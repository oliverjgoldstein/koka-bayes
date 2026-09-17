module alg/rmsmc

import std/num/float64
import std/num/random

import alg/lw
import alg/mcmc
import alg/simulate
import alg/smc
import core/env
import core/sequential
import core/trace
import handlers/population

struct particle-state<p,s,o>
  parameter      : p
  current-state  : s
  states         : list<s>
  observations   : list<o>
  trace          : run-trace
  output-env     : env
  log-likelihood : float64
  remaining-env  : env

struct weighted-particle<p,s,o>
  particle        : particle-state<p,s,o>
  step-log-weight : float64

struct rejuvenated<p,s,o>
  prefix-state  : prefix-output<p,s,o>
  trace         : run-trace
  output-env    : env
  remaining-env : env

pub fun rmsmc<p,s,o,a,e>(particle-count : int,
                         steps : int,
                         mh-steps : int,
                         environment : env,
                         spec : sequential-model<e,p,s,o,a>) : <div,random|e> smc-result<a>
  if particle-count <= 0
    then Smc-result([], neginf, empty())
    else
      val initial = initialise-particles(particle-count, environment, spec)
      val population = resample-population(particle-count, initial, fn(item){ item.step-log-weight })
      val started = population.values.map(fn(item){ item.particle })
      val (particles, log-evidence) = run-rmsmc(steps, mh-steps, environment, spec, 0, started, population.log-evidence)
      finalize-result(spec, particles, log-evidence)

fun initialise-particles<p,s,o,a,e>(count : int,
                                     environment : env,
                                     spec : sequential-model<e,p,s,o,a>) : <div,random|e> list<weighted-particle<p,s,o>>
  if count <= 0
    then []
    else
      val (prior-sample, after-prior) = run-lw-state(environment, prior(spec))
      val (start, after-start) = run-lw-state(after-prior, fn(){ initial(spec)(prior-sample.value) })
      val trace = append-trace(prior-sample.trace, start.trace)
      val output = merge(prior-sample.output-env, start.output-env)
      val weight = prior-sample.log-weight + start.log-weight
      val particle = Particle-state(prior-sample.value, start.value, [], [], trace, output, weight, after-start)
      Cons(Weighted-particle(particle, weight), initialise-particles(count - 1, environment, spec))

fun run-rmsmc<p,s,o,a,e>(remaining : int,
                         mh-steps : int,
                         environment : env,
                         spec : sequential-model<e,p,s,o,a>,
                         index : int,
                         particles : list<particle-state<p,s,o>>,
                         accumulated-logz : float64) : <div,random|e> (list<particle-state<p,s,o>>, float64)
  if remaining <= 0 || particles.is-empty
    then (particles, accumulated-logz)
    else
      val stepped = advance-particles(index, spec, particles)
      val population = resample-population(particles.length, stepped, fn(item){ item.step-log-weight })
      val resampled = population.values.map(fn(item){ item.particle })
      // Replay the same complete observation stream; a prefix consumes its own
      // occurrences and returns the cursor to retain with the accepted state.
      val moved =
        rejuvenate-particles(index + 1, mh-steps, environment, spec, resampled)
      run-rmsmc(remaining - 1,
                mh-steps,
                environment,
                spec,
                index + 1,
                moved,
                add-evidence(accumulated-logz, population.log-evidence))

fun advance-particles<p,s,o,a,e>(index : int,
                                 spec : sequential-model<e,p,s,o,a>,
                                 particles : list<particle-state<p,s,o>>) : <div,random|e> list<weighted-particle<p,s,o>>
  match particles
    Nil -> []
    Cons(particle, rest) ->
      val (stepped, after-step) = run-lw-state(particle.remaining-env, fn(){ step(spec)(particle.parameter, index, particle.current-state) })
      val trace1 = append-trace(particle.trace, stepped.trace)
      val output1 = merge(particle.output-env, stepped.output-env)
      val particle1 =
        Particle-state(particle.parameter,
                       stepped.value.state,
                       particle.states ++ [stepped.value.state],
                       particle.observations ++ [stepped.value.observation],
                       trace1,
                       output1,
                       particle.log-likelihood + stepped.log-weight,
                       after-step)
      Cons(Weighted-particle(particle1, stepped.log-weight), advance-particles(index, spec, rest))

fun rejuvenate-particles<p,s,o,a,e>(prefix-steps : int,
                                    mh-steps : int,
                                    environment : env,
                                    spec : sequential-model<e,p,s,o,a>,
                                    particles : list<particle-state<p,s,o>>) : <div,random|e> list<particle-state<p,s,o>>
  match particles
    Nil -> []
    Cons(particle, rest) ->
      val moved = rejuvenate-particle(prefix-steps, mh-steps, environment, spec, particle)
      Cons(moved, rejuvenate-particles(prefix-steps, mh-steps, environment, spec, rest))

fun rejuvenate-particle<p,s,o,a,e>(prefix-steps : int,
                                   mh-steps : int,
                                   environment : env,
                                   spec : sequential-model<e,p,s,o,a>,
                                   particle : particle-state<p,s,o>) : <div,random|e> particle-state<p,s,o>
  if mh-steps <= 0
    then particle
    else
      val current = Rejuvenated(Prefix-output(particle.parameter, particle.current-state, particle.states, particle.observations),
                                particle.trace,
                                particle.output-env,
                                particle.remaining-env)
      val initial = Scored(current, observed-log-prob(particle.trace))
      val kernel = fn(_state){ propose-prefix(prefix-steps, environment, spec) }
      val chain = mh-chain(default-config(mh-steps, 0), initial, kernel)
      val moved = last-sample(current, chain.samples)
      Particle-state(moved.prefix-state.parameter,
                     moved.prefix-state.current-state,
                     moved.prefix-state.states,
                     moved.prefix-state.observations,
                     moved.trace,
                     moved.output-env,
                     observed-log-prob(moved.trace),
                     moved.remaining-env)

fun propose-prefix<p,s,o,a,e>(prefix-steps : int,
                              environment : env,
                              spec : sequential-model<e,p,s,o,a>) : <div,random|e> mh-candidate<rejuvenated<p,s,o>>
  val (candidate, after-prefix) = simulate-state(environment, prefix-model(prefix-steps, spec))
  val value = Rejuvenated(candidate.value, candidate.trace, candidate.output-env, after-prefix)
  Mh-candidate(Scored(value, observed-log-prob(candidate.trace)), 0.0)

fun last-sample<a>(default : a, samples : list<a>) : a
  match samples
    Nil -> default
    Cons(sample, rest) ->
      match rest
        Nil -> sample
        _   -> last-sample(sample, rest)

fun finalize-result<p,s,o,a,e>(spec : sequential-model<e,p,s,o,a>,
                               particles : list<particle-state<p,s,o>>,
                               log-evidence : float64) : smc-result<a>
  val finished = particles.map(fn(particle){
    val prefix-state = Prefix-output(particle.parameter, particle.current-state, particle.states, particle.observations)
    Smc-sample(finish(spec)(prefix-state), particle.trace, particle.output-env, particle.log-likelihood)
  })
  val posterior : env = finished.foldl(empty(), fn(acc, sample){ merge(acc, sample.output-env) })
  Smc-result(finished, log-evidence, posterior)
