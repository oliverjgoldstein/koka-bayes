module alg/smc2

import std/num/float64
import std/num/random

import alg/mcmc
import alg/parameter
import alg/simulate
import alg/smc
import core/env
import core/sequential
import core/trace
import handlers/population
import handlers/weight

pub struct smc2-particle<p,a>
  parameter     : p
  parameter-env : env
  estimate      : smc-result<a>
  log-evidence  : float64

pub struct smc2-result<p,a>
  particles     : list<smc2-particle<p,a>>
  log-evidence  : float64
  posterior-env : env

// Keep the inner filter's auxiliary randomness in the outer particle.
// Incremental extension preserves support even when likelihood estimates can be zero.
struct filter-particle<p,s,o>
  parameter     : p
  parameter-env : env
  inner-state   : smc-state<p,s,o>
  parameter-score : float64
  remaining-env : env

struct parameter-candidate<p>
  parameter      : p
  parameter-env  : env
  log-target     : float64
  log-correction : float64
  remaining-env  : env

struct weighted-particle<p,s,o>
  particle        : filter-particle<p,s,o>
  step-log-weight : float64

pub fun smc2<p,s,o,a,e>(outer-particles : int,
                        inner-particles : int,
                        steps : int,
                        rejuvenation-steps : int,
                        environment : env,
                        spec : sequential-model<e,p,s,o,a>) : <div,random|e> smc2-result<p,a>
  smc2-engine(outer-particles, inner-particles, steps, rejuvenation-steps,
               spec,
               fn(){
                 val candidate = prior-candidate(environment, spec)
                 (candidate, candidate.log-target)
               },
               fn(_parameter, _remaining){ prior-candidate(environment, spec) })

fun prior-candidate<p,s,o,a,e>(environment : env,
                               spec : sequential-model<e,p,s,o,a>) : <div,random|e> parameter-candidate<p>
  val (proposal, after-prior) = simulate-state(environment, prior(spec))
  // The independent sampled prior cancels in MH. Its observed factors do not.
  Parameter-candidate(proposal.value, proposal.output-env, observed-log-prob(proposal.trace), 0.0, after-prior)

// Custom parameter-score is the complete parameter-level log target (including
// prior density and observed prior sites). The prior must return those latent
// coordinates directly: its sampled trace density is the initial proposal density.
// The kernel correction is log q(current | proposed) - log q(proposed | current).
// parameter-score must be deterministic for a fixed parameter; random log scores
// or changing external state do not satisfy this contract despite the effect row.
// This compatibility API requires a fixed prior observation-consumption pattern.
// Use smc2-with-state when proposed parameters need different input cursors.
pub fun smc2-with<p,s,o,a,e>(outer-particles : int,
                             inner-particles : int,
                             steps : int,
                             rejuvenation-steps : int,
                             environment : env,
                             spec : sequential-model<e,p,s,o,a>,
                             parameter-score : p -> <div,random|e> float64,
                             parameter-kernel : p -> <div,random|e> (p, env, float64)) : <div,random|e> smc2-result<p,a>
  custom-smc2(outer-particles, inner-particles, steps, rejuvenation-steps,
    environment, spec, parameter-score,
    fn(parameter, remaining){
      val (proposed, output, correction) = parameter-kernel(parameter)
      Parameter-proposal(proposed, output, remaining, correction)
    })

pub fun smc2-with-state<p,s,o,a,e>(outer-particles : int,
                                   inner-particles : int,
                                   steps : int,
                                   rejuvenation-steps : int,
                                   environment : env,
                                   spec : sequential-model<e,p,s,o,a>,
                                   parameter-score : p -> <div,random|e> float64,
                                   parameter-kernel : p -> <div,random|e> parameter-proposal<p>) : <div,random|e> smc2-result<p,a>
  custom-smc2(outer-particles, inner-particles, steps, rejuvenation-steps,
    environment, spec, parameter-score,
    fn(parameter, _remaining){ parameter-kernel(parameter) })

fun custom-smc2<p,s,o,a,e>(outer-particles : int,
                            inner-particles : int,
                            steps : int,
                            rejuvenation-steps : int,
                            environment : env,
                            spec : sequential-model<e,p,s,o,a>,
                            parameter-score : p -> <div,random|e> float64,
                            parameter-kernel : (p,env) -> <div,random|e> parameter-proposal<p>) : <div,random|e> smc2-result<p,a>
  smc2-engine(outer-particles, inner-particles, steps, rejuvenation-steps,
               spec,
               fn(){
                 val (proposal, after-prior) = simulate-state(environment, prior(spec))
                 val score = parameter-score(proposal.value)
                 val sampled-score = proposal.trace.foldl(0.0, fn(acc, entry){
                   match entry.mode
                     TraceSampled -> acc + entry.log-prob
                     TraceObserved -> acc
                     TraceFactor -> acc
                 })
                 (Parameter-candidate(proposal.value, proposal.output-env, score, 0.0, after-prior), score - sampled-score)
               },
               fn(current, remaining){
                 val proposal = parameter-kernel(current, remaining)
                 Parameter-candidate(proposal.parameter, proposal.parameter-env,
                   parameter-score(proposal.parameter), proposal.log-correction, proposal.remaining-env)
               })

fun smc2-engine<p,s,o,a,e>(outer-particles : int,
                            inner-particles : int,
                            steps : int,
                            rejuvenation-steps : int,
                            spec : sequential-model<e,p,s,o,a>,
                            initial-parameter : () -> <div,random|e> (parameter-candidate<p>,float64),
                            parameter-kernel : (p,env) -> <div,random|e> parameter-candidate<p>) : <div,random|e> smc2-result<p,a>
  if outer-particles <= 0 || inner-particles <= 0
    then Smc2-result([], neginf, empty())
    else
      val initial = initialise-particles(outer-particles, inner-particles, spec, initial-parameter)
      val initial-population = resample-population(outer-particles, initial, fn(item){ item.step-log-weight })
      val (particles, total-evidence) = handle-weight(fn(){
        val resampled = push-population(initial-population).map(fn(item){ item.particle })
        run-smc2(steps, outer-particles, inner-particles, rejuvenation-steps,
                 spec, parameter-kernel, 0, resampled)
      })
      finalize-result(spec, particles, total-evidence)

fun initialise-particles<p,s,o,a,e>(count : int,
                                     inner-particles : int,
                                     spec : sequential-model<e,p,s,o,a>,
                                     initial-parameter : () -> <div,random|e> (parameter-candidate<p>,float64)) : <div,random|e> list<weighted-particle<p,s,o>>
  if count <= 0
    then []
    else
      val (proposal, weight) = initial-parameter()
      val filter = start-smc-given(inner-particles, proposal.remaining-env, proposal.parameter, spec)
      val particle = Filter-particle(proposal.parameter, proposal.parameter-env, filter, proposal.log-target, proposal.remaining-env)
      Cons(Weighted-particle(particle, weight + filter.log-evidence),
           initialise-particles(count - 1, inner-particles, spec, initial-parameter))

fun run-smc2<p,s,o,a,e>(remaining : int,
                        outer-particles : int,
                        inner-particles : int,
                        rejuvenation-steps : int,
                        spec : sequential-model<e,p,s,o,a>,
                        parameter-kernel : (p,env) -> <div,random|e> parameter-candidate<p>,
                        index : int,
                        particles : list<filter-particle<p,s,o>>) : <accumulate-weight,div,random|e> list<filter-particle<p,s,o>>
  if remaining <= 0 || particles.is-empty
    then particles
    else
      val weighted = mask<accumulate-weight>{ update-particles(spec, particles) }
      val step-population = resample-population(outer-particles, weighted, fn(item){ item.step-log-weight })
      val resampled = push-population(step-population).map(fn(item){ item.particle })
      val moved = mask<accumulate-weight>{
        resampled.map(fn(particle){
          rejuvenate-particle(index + 1, inner-particles, rejuvenation-steps,
                              spec, parameter-kernel, particle)
        })
      }
      run-smc2(remaining - 1, outer-particles, inner-particles, rejuvenation-steps,
               spec, parameter-kernel,
               index + 1, moved)

fun update-particles<p,s,o,a,e>(spec : sequential-model<e,p,s,o,a>,
                                particles : list<filter-particle<p,s,o>>) : <div,random|e> list<weighted-particle<p,s,o>>
  particles.map(fn(particle){
    val filter = advance-smc-state(spec, particle.inner-state)
    val increment = evidence-increment(particle.inner-state.log-evidence, filter.log-evidence)
    Weighted-particle(Filter-particle(particle.parameter, particle.parameter-env, filter, particle.parameter-score, particle.remaining-env), increment)
  })

fun rejuvenate-particle<p,s,o,a,e>(prefix-steps : int,
                                   inner-particles : int,
                                   rejuvenation-steps : int,
                                   spec : sequential-model<e,p,s,o,a>,
                                   parameter-kernel : (p,env) -> <div,random|e> parameter-candidate<p>,
                                   particle : filter-particle<p,s,o>) : <div,random|e> filter-particle<p,s,o>
  if rejuvenation-steps <= 0
    then particle
    else
      val initial = Scored(particle, particle.parameter-score + particle.inner-state.log-evidence)
      val kernel = fn(state){
        val Scored(current-particle, _) = state
        val Filter-particle(current-parameter, _, _, _, current-remaining) = current-particle
        val proposed = parameter-kernel(current-parameter, current-remaining)
        val filter = extend-smc-state(prefix-steps, spec,
                                start-smc-given(inner-particles, proposed.remaining-env, proposed.parameter, spec))
        val candidate = Filter-particle(proposed.parameter, proposed.parameter-env, filter, proposed.log-target, proposed.remaining-env)
        Mh-candidate(Scored(candidate, proposed.log-target + filter.log-evidence), proposed.log-correction)
      }
      // On rejection retain the entire old filter, not just its likelihood.
      val chain = mh-chain(default-config(rejuvenation-steps, 0), initial, kernel)
      last-sample(particle, chain.samples)

fun finalize-result<p,s,o,a,e>(spec : sequential-model<e,p,s,o,a>,
                               particles : list<filter-particle<p,s,o>>,
                               total-logz : float64) : smc2-result<p,a>
  val finished = particles.map(fn(particle){
    val estimate = finish-smc(spec, particle.inner-state)
    Smc2-particle(particle.parameter, particle.parameter-env, estimate, estimate.log-evidence)
  })
  val posterior : env = finished.foldl(empty(), fn(acc, particle){
    merge(acc, merge(particle.parameter-env, particle.estimate.posterior-env))
  })
  Smc2-result(finished, total-logz, posterior)

fun last-sample<a>(default : a, samples : list<a>) : a
  match samples
    Nil -> default
    Cons(sample, rest) ->
      match rest
        Nil -> sample
        _   -> last-sample(sample, rest)
