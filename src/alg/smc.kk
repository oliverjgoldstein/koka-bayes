module alg/smc

import std/num/float64
import std/num/random

import alg/lw
import alg/simulate
import core/env
import core/model
import core/sequential
import core/trace

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

struct weighted-particle<p,s,o>
  particle        : particle-state<p,s,o>
  step-log-weight : float64

pub fun smc<p,s,o,a,e>(particle-count : int,
                       steps : int,
                       environment : env,
                       spec : sequential-model<e,p,s,o,a>) : <div,random|e> smc-result<a>
  if particle-count <= 0
    then Smc-result([], neginf, empty())
    else
      val initial = initialise-particles(particle-count, environment, spec)
      val (particles, log-evidence) = run-smc(steps, environment, spec, 0, initial, 0.0)
      finalize-result(spec, particles, log-evidence)

pub fun smc-given<p,s,o,a,e>(particle-count : int,
                             steps : int,
                             environment : env,
                             parameter : p,
                             spec : sequential-model<e,p,s,o,a>) : <div,random|e> smc-result<a>
  if particle-count <= 0
    then Smc-result([], neginf, empty())
    else
      val initial = initialise-fixed-particles(particle-count, environment, parameter, spec)
      val (particles, log-evidence) = run-smc(steps, environment, spec, 0, initial, 0.0)
      finalize-result(spec, particles, log-evidence)

fun initialise-particles<p,s,o,a,e>(count : int,
                                     environment : env,
                                     spec : sequential-model<e,p,s,o,a>) : <div,random|e> list<particle-state<p,s,o>>
  if count <= 0
    then []
    else
      val prior-sample = simulate(environment, prior(spec))
      val start = simulate(take-prefix(0, environment), fn(){ initial(spec)(prior-sample.value) })
      val trace = append-trace(prior-sample.trace, start.trace)
      val output = merge(prior-sample.output-env, start.output-env)
      val particle = Particle-state(prior-sample.value, start.value, [], [], trace, output, 0.0)
      Cons(particle, initialise-particles(count - 1, environment, spec))

fun initialise-fixed-particles<p,s,o,a,e>(count : int,
                                          environment : env,
                                          parameter : p,
                                          spec : sequential-model<e,p,s,o,a>) : <div,random|e> list<particle-state<p,s,o>>
  if count <= 0
    then []
    else
      val start = simulate(take-prefix(0, environment), fn(){ initial(spec)(parameter) })
      val particle = Particle-state(parameter, start.value, [], [], start.trace, start.output-env, 0.0)
      Cons(particle, initialise-fixed-particles(count - 1, environment, parameter, spec))

fun run-smc<p,s,o,a,e>(remaining : int,
                       environment : env,
                       spec : sequential-model<e,p,s,o,a>,
                       index : int,
                       particles : list<particle-state<p,s,o>>,
                       log-evidence : float64) : <div,random|e> (list<particle-state<p,s,o>>, float64)
  if remaining <= 0
    then (particles, log-evidence)
    else
      val stepped = advance-particles(index, focus-step(index, environment), spec, particles)
      val step-logz = log-mean-weight(stepped.map(fn(item){ item.step-log-weight }))
      val resampled = resample-particles(particles.length, stepped)
      run-smc(remaining - 1,
              environment,
              spec,
              index + 1,
              resampled,
              add-log-evidence(log-evidence, step-logz))

fun advance-particles<p,s,o,a,e>(index : int,
                                 environment : env,
                                 spec : sequential-model<e,p,s,o,a>,
                                 particles : list<particle-state<p,s,o>>) : <div,random|e> list<weighted-particle<p,s,o>>
  match particles
    Nil -> []
    Cons(particle, rest) ->
      val stepped = run-lw(environment, fn(){ step(spec)(particle.parameter, index, particle.current-state) })
      val trace1 = append-trace(particle.trace, stepped.trace)
      val output1 = merge(particle.output-env, stepped.output-env)
      val particle1 =
        Particle-state(particle.parameter,
                       stepped.value.state,
                       particle.states ++ [stepped.value.state],
                       particle.observations ++ [stepped.value.observation],
                       trace1,
                       output1,
                       particle.log-likelihood + stepped.log-weight)
      Cons(Weighted-particle(particle1, stepped.log-weight), advance-particles(index, environment, spec, rest))

fun finalize-result<p,s,o,a,e>(spec : sequential-model<e,p,s,o,a>,
                               particles : list<particle-state<p,s,o>>,
                               log-evidence : float64) : smc-result<a>
  val finished = particles.map(fn(particle){
    val prefix-state = Prefix-output(particle.parameter, particle.current-state, particle.states, particle.observations)
    Smc-sample(finish(spec)(prefix-state), particle.trace, particle.output-env, particle.log-likelihood)
  })
  val posterior : env = finished.foldl(empty(), fn(acc, sample){ merge(acc, sample.output-env) })
  Smc-result(finished, log-evidence, posterior)

fun resample-particles<p,s,o>(count : int, particles : list<weighted-particle<p,s,o>>) : <div,random> list<particle-state<p,s,o>>
  if count <= 0
    then []
    else
      match prepare-particles(particles)
        Nothing ->
          []
        Just(weighted) ->
          val total = weighted.foldl(0.0, fn(acc, item){ acc + fst(item) })
          Cons(draw-particle(total, weighted), resample-particles(count - 1, particles))

fun prepare-particles<p,s,o>(particles : list<weighted-particle<p,s,o>>) : maybe<list<(float64, particle-state<p,s,o>)>>
  val max-log = max-weight(particles, neginf)
  if max-log <= neginf
    then uniform-particles(particles)
    else Just(particles.map(fn(item){ (exp(item.step-log-weight - max-log), item.particle) }))

fun uniform-particles<p,s,o>(particles : list<weighted-particle<p,s,o>>) : maybe<list<(float64, particle-state<p,s,o>)>>
  match particles
    Nil -> Nothing
    _   -> Just(particles.map(fn(item){ (1.0, item.particle) }))

fun max-weight<p,s,o>(particles : list<weighted-particle<p,s,o>>, current : float64) : float64
  match particles
    Nil -> current
    Cons(item, rest) ->
      max-weight(rest, max(current, item.step-log-weight))

fun draw-particle<p,s,o>(total : float64, particles : list<(float64, particle-state<p,s,o>)>) : <div,random> particle-state<p,s,o>
  val threshold = random-float64() * max(1.0e-12, total)
  choose-particle(threshold, particles)

fun choose-particle<p,s,o>(threshold : float64, particles : list<(float64, particle-state<p,s,o>)>) : particle-state<p,s,o>
  match particles
    Cons((_, particle), Nil) ->
      particle
    Cons((weight, particle), rest) ->
      if threshold <= weight
        then particle
        else choose-particle(threshold - weight, rest)
    Nil ->
      impossible("cannot resample an empty particle set")

fun log-mean-weight(weights : list<float64>) : float64
  val max-log = max-log-weight(weights, neginf)
  if max-log <= neginf
    then neginf
    else
      val total = weights.foldl(0.0, fn(acc, weight){ acc + exp(weight - max-log) })
      max-log + ln(total) - ln(float64(max(1, weights.length)))

fun max-log-weight(weights : list<float64>, current : float64) : float64
  match weights
    Nil -> current
    Cons(weight, rest) -> max-log-weight(rest, max(current, weight))

fun add-log-evidence(current : float64, step : float64) : float64
  if current <= neginf || step <= neginf
    then neginf
    else current + step
