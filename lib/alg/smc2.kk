module alg/smc2

import std/num/float64
import std/num/random

import alg/mcmc
import alg/simulate
import alg/smc
import core/env
import core/sequential
import core/trace
import core/weights

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

struct parameter-candidate<p>
  parameter      : p
  parameter-env  : env
  log-target     : float64
  log-correction : float64

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
               environment, spec,
               fn(){
                 val candidate = prior-candidate(environment, spec)
                 (candidate, candidate.log-target)
               },
               fn(_parameter){ prior-candidate(environment, spec) })

fun prior-candidate<p,s,o,a,e>(environment : env,
                               spec : sequential-model<e,p,s,o,a>) : <div,random|e> parameter-candidate<p>
  val proposal = simulate(environment, prior(spec))
  // The independent sampled prior cancels in MH. Its observed factors do not.
  Parameter-candidate(proposal.value, proposal.output-env, observed-log-prob(proposal.trace), 0.0)

// Custom parameter-score is the complete parameter-level log target (including
// prior density and observed prior sites). The prior must return those latent
// coordinates directly: its sampled trace density is the initial proposal density.
// The kernel correction is log q(current | proposed) - log q(proposed | current).
pub fun smc2-with<p,s,o,a,e>(outer-particles : int,
                             inner-particles : int,
                             steps : int,
                             rejuvenation-steps : int,
                             environment : env,
                             spec : sequential-model<e,p,s,o,a>,
                             parameter-score : p -> <div,random|e> float64,
                             parameter-kernel : p -> <div,random|e> (p, env, float64)) : <div,random|e> smc2-result<p,a>
  smc2-engine(outer-particles, inner-particles, steps, rejuvenation-steps,
               environment, spec,
               fn(){
                 val proposal = simulate(environment, prior(spec))
                 val score = parameter-score(proposal.value)
                 val sampled-score = proposal.trace.foldl(0.0, fn(acc, entry){
                   match entry.mode
                     TraceSampled -> acc + entry.log-prob
                     TraceObserved -> acc
                 })
                 (Parameter-candidate(proposal.value, proposal.output-env, score, 0.0), score - sampled-score)
               },
               fn(current){
                 val (parameter, parameter-env, correction) = parameter-kernel(current)
                 Parameter-candidate(parameter, parameter-env, parameter-score(parameter), correction)
               })

fun smc2-engine<p,s,o,a,e>(outer-particles : int,
                            inner-particles : int,
                            steps : int,
                            rejuvenation-steps : int,
                            environment : env,
                            spec : sequential-model<e,p,s,o,a>,
                            initial-parameter : () -> <div,random|e> (parameter-candidate<p>,float64),
                            parameter-kernel : p -> <div,random|e> parameter-candidate<p>) : <div,random|e> smc2-result<p,a>
  if outer-particles <= 0 || inner-particles <= 0
    then Smc2-result([], neginf, empty())
    else
      val initial = initialise-particles(outer-particles, inner-particles, environment, spec, initial-parameter)
      val initial-logz = log-mean-weight(initial.map(fn(item){ item.step-log-weight }))
      val resampled = resample-particles(outer-particles, initial)
      val (particles, log-evidence) =
        run-smc2(steps, outer-particles, inner-particles, rejuvenation-steps,
                 environment, spec, parameter-kernel, 0,
                 resampled, initial-logz)
      finalize-result(spec, particles, log-evidence)

fun initialise-particles<p,s,o,a,e>(count : int,
                                     inner-particles : int,
                                     environment : env,
                                     spec : sequential-model<e,p,s,o,a>,
                                     initial-parameter : () -> <div,random|e> (parameter-candidate<p>,float64)) : <div,random|e> list<weighted-particle<p,s,o>>
  if count <= 0
    then []
    else
      val (proposal, weight) = initial-parameter()
      val filter = start-smc-given(inner-particles, environment, proposal.parameter, spec)
      val particle = Filter-particle(proposal.parameter, proposal.parameter-env, filter, proposal.log-target)
      Cons(Weighted-particle(particle, weight + filter.log-evidence),
           initialise-particles(count - 1, inner-particles, environment, spec, initial-parameter))

fun run-smc2<p,s,o,a,e>(remaining : int,
                        outer-particles : int,
                        inner-particles : int,
                        rejuvenation-steps : int,
                        environment : env,
                        spec : sequential-model<e,p,s,o,a>,
                        parameter-kernel : p -> <div,random|e> parameter-candidate<p>,
                        index : int,
                        particles : list<filter-particle<p,s,o>>,
                        log-evidence : float64) : <div,random|e> (list<filter-particle<p,s,o>>, float64)
  if remaining <= 0 || particles.is-empty
    then (particles, log-evidence)
    else
      val weighted = update-particles(environment, spec, particles)
      val step-logz = log-mean-weight(weighted.map(fn(item){ item.step-log-weight }))
      val resampled = resample-particles(outer-particles, weighted)
      val moved = resampled.map(fn(particle){
        rejuvenate-particle(index + 1, inner-particles, rejuvenation-steps,
                            environment, spec, parameter-kernel, particle)
      })
      run-smc2(remaining - 1, outer-particles, inner-particles, rejuvenation-steps,
               environment, spec, parameter-kernel,
               index + 1, moved, log-evidence + step-logz)

fun update-particles<p,s,o,a,e>(environment : env,
                                spec : sequential-model<e,p,s,o,a>,
                                particles : list<filter-particle<p,s,o>>) : <div,random|e> list<weighted-particle<p,s,o>>
  particles.map(fn(particle){
    val filter = advance-smc(environment, spec, particle.inner-state)
    val increment = if filter.log-evidence <= neginf then neginf
                    else filter.log-evidence - particle.inner-state.log-evidence
    Weighted-particle(Filter-particle(particle.parameter, particle.parameter-env, filter, particle.parameter-score), increment)
  })

fun rejuvenate-particle<p,s,o,a,e>(prefix-steps : int,
                                   inner-particles : int,
                                   rejuvenation-steps : int,
                                   environment : env,
                                   spec : sequential-model<e,p,s,o,a>,
                                   parameter-kernel : p -> <div,random|e> parameter-candidate<p>,
                                   particle : filter-particle<p,s,o>) : <div,random|e> filter-particle<p,s,o>
  if rejuvenation-steps <= 0
    then particle
    else
      val initial = Scored(particle, particle.parameter-score + particle.inner-state.log-evidence)
      val kernel = fn(state){
        val Scored(current-particle, _) = state
        val Filter-particle(current-parameter, _, _, _) = current-particle
        val proposed = parameter-kernel(current-parameter)
        val filter = extend-smc(prefix-steps, environment, spec,
                                start-smc-given(inner-particles, environment, proposed.parameter, spec))
        val candidate = Filter-particle(proposed.parameter, proposed.parameter-env, filter, proposed.log-target)
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

fun resample-particles<p,s,o>(count : int, particles : list<weighted-particle<p,s,o>>) : <div,random> list<filter-particle<p,s,o>>
  resample-log-weighted(count, particles, fn(item){ item.step-log-weight }).map(fn(item){ item.particle })
