module alg/smc2

import std/num/float64
import std/num/random

import alg/mcmc
import alg/simulate
import alg/smc
import core/env
import core/sequential

pub struct smc2-particle<p,a>
  parameter     : p
  parameter-env : env
  estimate      : smc-result<a>
  log-evidence  : float64

pub struct smc2-result<p,a>
  particles     : list<smc2-particle<p,a>>
  log-evidence  : float64
  posterior-env : env

struct weighted-particle<p,a>
  particle        : smc2-particle<p,a>
  step-log-weight : float64

pub fun smc2<p,s,o,a,e>(outer-particles : int,
                        inner-particles : int,
                        steps : int,
                        rejuvenation-steps : int,
                        environment : env,
                        spec : sequential-model<e,p,s,o,a>) : <div,random|e> smc2-result<p,a>
  smc2-with(outer-particles,
            inner-particles,
            steps,
            rejuvenation-steps,
            environment,
            spec,
            fn(_parameter){ 0.0 },
            fn(_parameter){
              val proposal = simulate(environment, prior(spec))
              (proposal.value, proposal.output-env, 0.0)
            })

pub fun smc2-with<p,s,o,a,e>(outer-particles : int,
                             inner-particles : int,
                             steps : int,
                             rejuvenation-steps : int,
                             environment : env,
                             spec : sequential-model<e,p,s,o,a>,
                             parameter-score : p -> <div,random|e> float64,
                             parameter-kernel : p -> <div,random|e> (p, env, float64)) : <div,random|e> smc2-result<p,a>
  if outer-particles <= 0 || inner-particles <= 0
    then Smc2-result([], neginf, empty())
    else
      val initial = initialise-particles(outer-particles, inner-particles, environment, spec)
      val (particles, log-evidence) =
        run-smc2(steps,
                 outer-particles,
                 inner-particles,
                 rejuvenation-steps,
                 environment,
                 spec,
                 parameter-score,
                 parameter-kernel,
                 0,
                 initial,
                 0.0)
      finalize-result(particles, log-evidence)

fun initialise-particles<p,s,o,a,e>(count : int,
                                     inner-particles : int,
                                     environment : env,
                                     spec : sequential-model<e,p,s,o,a>) : <div,random|e> list<smc2-particle<p,a>>
  if count <= 0
    then []
    else
      val proposal = simulate(environment, prior(spec))
      val estimate = smc-given(inner-particles, 0, take-prefix(0, environment), proposal.value, spec)
      val particle = Smc2-particle(proposal.value, proposal.output-env, estimate, estimate.log-evidence)
      Cons(particle, initialise-particles(count - 1, inner-particles, environment, spec))

fun run-smc2<p,s,o,a,e>(remaining : int,
                        outer-particles : int,
                        inner-particles : int,
                        rejuvenation-steps : int,
                        environment : env,
                        spec : sequential-model<e,p,s,o,a>,
                        parameter-score : p -> <div,random|e> float64,
                        parameter-kernel : p -> <div,random|e> (p, env, float64),
                        index : int,
                        particles : list<smc2-particle<p,a>>,
                        log-evidence : float64) : <div,random|e> (list<smc2-particle<p,a>>, float64)
  if remaining <= 0
    then (particles, log-evidence)
    else
      val prefix-env = take-prefix(index + 1, environment)
      val weighted = update-particles(index + 1, inner-particles, prefix-env, spec, particles)
      val step-logz = log-mean-weight(weighted.map(fn(item){ item.step-log-weight }))
      val resampled = resample-particles(outer-particles, weighted)
      val moved =
        rejuvenate-particles(index + 1,
                             inner-particles,
                             rejuvenation-steps,
                             prefix-env,
                             spec,
                             parameter-score,
                             parameter-kernel,
                             resampled)
      run-smc2(remaining - 1,
               outer-particles,
               inner-particles,
               rejuvenation-steps,
               environment,
               spec,
               parameter-score,
               parameter-kernel,
               index + 1,
               moved,
               add-log-evidence(log-evidence, step-logz))

fun update-particles<p,s,o,a,e>(prefix-steps : int,
                                inner-particles : int,
                                environment : env,
                                spec : sequential-model<e,p,s,o,a>,
                                particles : list<smc2-particle<p,a>>) : <div,random|e> list<weighted-particle<p,a>>
  match particles
    Nil -> []
    Cons(particle, rest) ->
      val estimate = smc-given(inner-particles, prefix-steps, environment, particle.parameter, spec)
      val increment = incremental-weight(particle.log-evidence, estimate.log-evidence)
      val particle1 = Smc2-particle(particle.parameter, particle.parameter-env, estimate, estimate.log-evidence)
      Cons(Weighted-particle(particle1, increment), update-particles(prefix-steps, inner-particles, environment, spec, rest))

fun rejuvenate-particles<p,s,o,a,e>(prefix-steps : int,
                                    inner-particles : int,
                                    rejuvenation-steps : int,
                                    environment : env,
                                    spec : sequential-model<e,p,s,o,a>,
                                    parameter-score : p -> <div,random|e> float64,
                                    parameter-kernel : p -> <div,random|e> (p, env, float64),
                                    particles : list<smc2-particle<p,a>>) : <div,random|e> list<smc2-particle<p,a>>
  match particles
    Nil -> []
    Cons(particle, rest) ->
      val moved =
        rejuvenate-particle(prefix-steps,
                            inner-particles,
                            rejuvenation-steps,
                            environment,
                            spec,
                            parameter-score,
                            parameter-kernel,
                            particle)
      Cons(moved,
           rejuvenate-particles(prefix-steps,
                                inner-particles,
                                rejuvenation-steps,
                                environment,
                                spec,
                                parameter-score,
                                parameter-kernel,
                                rest))

fun rejuvenate-particle<p,s,o,a,e>(prefix-steps : int,
                                   inner-particles : int,
                                   rejuvenation-steps : int,
                                   environment : env,
                                   spec : sequential-model<e,p,s,o,a>,
                                   parameter-score : p -> <div,random|e> float64,
                                   parameter-kernel : p -> <div,random|e> (p, env, float64),
                                   particle : smc2-particle<p,a>) : <div,random|e> smc2-particle<p,a>
  if rejuvenation-steps <= 0
    then particle
    else
      val initial = Scored(particle, parameter-score(particle.parameter) + particle.log-evidence)
      val kernel =
        fn(state){
          val Scored(current-particle, _current-logevidence) = state
          val Smc2-particle(current-parameter, _current-env, _current-estimate, _current-logevidence2) = current-particle
          val (parameter, parameter-env, log-correction) = parameter-kernel(current-parameter)
          val estimate = smc-given(inner-particles, prefix-steps, environment, parameter, spec)
          val candidate = Smc2-particle(parameter, parameter-env, estimate, estimate.log-evidence)
          Mh-candidate(Scored(candidate, parameter-score(parameter) + estimate.log-evidence), log-correction)
        }
      val chain = mh-chain(default-config(rejuvenation-steps, 0), initial, kernel)
      last-sample(particle, chain.samples)

fun finalize-result<p,a>(particles : list<smc2-particle<p,a>>, log-evidence : float64) : smc2-result<p,a>
  val posterior : env = particles.foldl(empty(), fn(acc, particle){
    merge(acc, merge(particle.parameter-env, particle.estimate.posterior-env))
  })
  Smc2-result(particles, log-evidence, posterior)

fun last-sample<a>(default : a, samples : list<a>) : a
  match samples
    Nil -> default
    Cons(sample, rest) ->
      match rest
        Nil -> sample
        _   -> last-sample(sample, rest)

fun resample-particles<p,a>(count : int, particles : list<weighted-particle<p,a>>) : <div,random> list<smc2-particle<p,a>>
  if count <= 0
    then []
    else
      match prepare-particles(particles)
        Nothing ->
          []
        Just(weighted) ->
          val total = weighted.foldl(0.0, fn(acc, item){ acc + fst(item) })
          Cons(draw-particle(total, weighted), resample-particles(count - 1, particles))

fun prepare-particles<p,a>(particles : list<weighted-particle<p,a>>) : maybe<list<(float64, smc2-particle<p,a>)>>
  val max-log = max-weight(particles, neginf)
  if max-log <= neginf
    then uniform-particles(particles)
    else Just(particles.map(fn(item){ (exp(item.step-log-weight - max-log), item.particle) }))

fun uniform-particles<p,a>(particles : list<weighted-particle<p,a>>) : maybe<list<(float64, smc2-particle<p,a>)>>
  match particles
    Nil -> Nothing
    _   -> Just(particles.map(fn(item){ (1.0, item.particle) }))

fun max-weight<p,a>(particles : list<weighted-particle<p,a>>, current : float64) : float64
  match particles
    Nil -> current
    Cons(item, rest) -> max-weight(rest, max(current, item.step-log-weight))

fun draw-particle<p,a>(total : float64, particles : list<(float64, smc2-particle<p,a>)>) : <div,random> smc2-particle<p,a>
  val threshold = random-float64() * max(1.0e-12, total)
  choose-particle(threshold, particles)

fun choose-particle<p,a>(threshold : float64, particles : list<(float64, smc2-particle<p,a>)>) : smc2-particle<p,a>
  match particles
    Cons((_, particle), Nil) ->
      particle
    Cons((weight, particle), rest) ->
      if threshold <= weight
        then particle
        else choose-particle(threshold - weight, rest)
    Nil ->
      impossible("cannot resample an empty parameter particle set")

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

fun incremental-weight(previous : float64, current : float64) : float64
  if current <= neginf
    then neginf
    elif previous <= neginf
      then current
      else current - previous

fun add-log-evidence(current : float64, step : float64) : float64
  if current <= neginf || step <= neginf
    then neginf
    else current + step
