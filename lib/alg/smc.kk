module alg/smc

import std/num/float64
import std/num/random

import alg/lw
import core/env
import core/model
import core/sequential
import core/trace
import handlers/population

pub struct smc-sample<a>
  value          : a
  trace          : run-trace
  output-env     : env
  log-likelihood : float64

pub struct smc-result<a>
  particles     : list<smc-sample<a>>
  log-evidence  : float64
  posterior-env : env

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

// A retained bootstrap filter, including its random particle population.
// Extending this value preserves the likelihood estimator's auxiliary state
// and each particle's remaining observation stream.
pub struct smc-state<p,s,o>
  particles    : list<particle-state<p,s,o>>
  step-index   : int
  log-evidence : float64

pub fun smc<p,s,o,a,e>(particle-count : int,
                       steps : int,
                       environment : env,
                       spec : sequential-model<e,p,s,o,a>) : <div,random|e> smc-result<a>
  val weighted = initialise-particles(particle-count, environment, spec)
  val initial = initial-filter(particle-count, weighted)
  finish-smc(spec, extend-smc-state(steps, spec, initial))

// The parameter prior has already run: `environment` is its unconsumed suffix.
// With no prior observations, pass the original environment unchanged.
pub fun smc-given<p,s,o,a,e>(particle-count : int,
                             steps : int,
                             environment : env,
                             parameter : p,
                             spec : sequential-model<e,p,s,o,a>) : <div,random|e> smc-result<a>
  finish-smc(spec, extend-smc-state(steps, spec,
                                  start-smc-given(particle-count, environment, parameter, spec)))

pub fun start-smc-given<p,s,o,a,e>(particle-count : int,
                                   environment : env,
                                   parameter : p,
                                   spec : sequential-model<e,p,s,o,a>) : <div,random|e> smc-state<p,s,o>
  initial-filter(particle-count, initialise-fixed-particles(particle-count, environment, parameter, spec))

// Append newly arrived data after each particle's unconsumed suffix. This does
// not run the model, change its evidence or mutate the original retained filter.
// Pass only new occurrences, rather than the entire observation history.
pub fun append-smc-observations<p,s,o>(additional : env,
                                       state : smc-state<p,s,o>) : smc-state<p,s,o>
  val particles = state.particles.map(fn(particle){
    Particle-state(particle.parameter,
                   particle.current-state,
                   particle.states,
                   particle.observations,
                   particle.trace,
                   particle.output-env,
                   particle.log-likelihood,
                   merge(particle.remaining-env, additional))
  })
  Smc-state(particles, state.step-index, state.log-evidence)

// Resume using each particle's remaining observation stream. The cursor is
// retained with the particle, including when a particle is resampled.
pub fun advance-smc-state<p,s,o,a,e>(spec : sequential-model<e,p,s,o,a>,
                                     state : smc-state<p,s,o>) : <div,random|e> smc-state<p,s,o>
  val stepped = advance-particles(state.step-index, spec, state.particles)
  val population = resample-population(state.particles.length, stepped, fn(item){ item.step-log-weight })
  Smc-state(population.values.map(fn(item){ item.particle }), state.step-index + 1,
            add-evidence(state.log-evidence, population.log-evidence))

pub fun extend-smc-state<p,s,o,a,e>(steps : int,
                                    spec : sequential-model<e,p,s,o,a>,
                                    state : smc-state<p,s,o>) : <div,random|e> smc-state<p,s,o>
  if steps <= 0 || state.particles.is-empty
    then state
    else extend-smc-state(steps - 1, spec, advance-smc-state(spec, state))

// Compatibility wrappers. Supply observations when starting the filter;
// subsequent calls use the retained cursor and do not reset it from this env.
pub fun advance-smc<p,s,o,a,e>(_environment : env,
                               spec : sequential-model<e,p,s,o,a>,
                               state : smc-state<p,s,o>) : <div,random|e> smc-state<p,s,o>
  advance-smc-state(spec, state)

pub fun extend-smc<p,s,o,a,e>(steps : int,
                              _environment : env,
                              spec : sequential-model<e,p,s,o,a>,
                              state : smc-state<p,s,o>) : <div,random|e> smc-state<p,s,o>
  extend-smc-state(steps, spec, state)

pub fun finish-smc<p,s,o,a,e>(spec : sequential-model<e,p,s,o,a>,
                              state : smc-state<p,s,o>) : smc-result<a>
  finalize-result(spec, state.particles, state.log-evidence)

fun initial-filter<p,s,o>(count : int, weighted : list<weighted-particle<p,s,o>>) : <div,random> smc-state<p,s,o>
  val population = resample-population(count, weighted, fn(item){ item.step-log-weight })
  Smc-state(population.values.map(fn(item){ item.particle }), 0, population.log-evidence)

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

fun initialise-fixed-particles<p,s,o,a,e>(count : int,
                                          environment : env,
                                          parameter : p,
                                          spec : sequential-model<e,p,s,o,a>) : <div,random|e> list<weighted-particle<p,s,o>>
  if count <= 0
    then []
    else
      val (start, after-start) = run-lw-state(environment, fn(){ initial(spec)(parameter) })
      val particle = Particle-state(parameter, start.value, [], [], start.trace, start.output-env, start.log-weight, after-start)
      Cons(Weighted-particle(particle, start.log-weight), initialise-fixed-particles(count - 1, environment, parameter, spec))

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

fun finalize-result<p,s,o,a,e>(spec : sequential-model<e,p,s,o,a>,
                               particles : list<particle-state<p,s,o>>,
                               log-evidence : float64) : smc-result<a>
  val finished = particles.map(fn(particle){
    val prefix-state = Prefix-output(particle.parameter, particle.current-state, particle.states, particle.observations)
    Smc-sample(finish(spec)(prefix-state), particle.trace, particle.output-env, particle.log-likelihood)
  })
  val posterior : env = finished.foldl(empty(), fn(acc, sample){ merge(acc, sample.output-env) })
  Smc-result(finished, log-evidence, posterior)
