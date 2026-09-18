module inference_transformations

import std/num/float64
import std/num/random
import alg/lw
import alg/mcmc
import alg/parameter
import alg/pmmh
import alg/smc
import alg/smc2
import core/env
import core/model
import core/obsvar
import core/sequential
import handlers/population
import handlers/sequential
import handlers/weight

fun ensure(message : string, condition : bool) : exn ()
  if not(condition) then throw(message)

fun near(actual : float64, expected : float64) : bool
  abs(actual - expected) < 1.0e-12

fun test-checkpoints() : <div,exn> ()
  val paused = suspend(fn(){ checkpoint(); checkpoint(); 7 })
  match paused
    Completed(_) -> throw("checkpoint must suspend before returning")
    Suspended(_) -> ()
  val once = advance(paused)
  match once
    Completed(_) -> throw("advancing one checkpoint must stop at the next")
    Suspended(_) -> ()
  ensure("completing a checkpointed computation returns its result", complete(once) == 7)
  ensure("a saved pure continuation can be resumed again", complete(paused) == 7)
  match advance(Completed(9))
    Completed(value) -> ensure("advancing a completed computation is stable", value == 9)
    Suspended(_) -> throw("completed computation unexpectedly suspended")

fun test-scoring-across-checkpoints() : <div,exn> ()
  pseudo-random(1901, fn(){
    val paused = suspend(fn(){
      run-lw(empty(), fn(){
        log-score(ln(0.5))
        checkpoint()
        log-score(ln(0.25))
        7
      })
    })
    val first = complete(paused)
    val second = complete(paused)
    ensure("checkpoint resumes the complete score", first.value == 7 && near(first.log-weight, ln(0.125)))
    ensure("checkpoint replay keeps scoring branch-local", near(second.log-weight, first.log-weight))
    ensure("checkpoint replay keeps traces branch-local", first.trace.length == 2 && second.trace.length == 2)
  })

fun test-populations() : <div,exn> ()
  pseudo-random(1907, fn(){
    val result = resample-population(12, [ln(0.2), ln(0.6)], fn(weight){ weight })
    ensure("population keeps its requested size", result.values.length == 12)
    ensure("population evidence is mean weight, not weight sum", near(result.log-evidence, ln(0.4)))
    val (resampled, total) = handle-weight(fn(){
      push-evidence(ln(0.5))
      push-population(result)
    })
    ensure("population evidence is passed outward exactly once", resampled == result.values && near(total, ln(0.2)))
    val dead = resample-population(12, [neginf, neginf], fn(weight){ weight })
    ensure("a zero-mass population stays empty", dead.values.is-empty && dead.log-evidence == neginf)
    ensure("zero-evidence increments cannot revive a dead filter", evidence-increment(neginf, neginf) == neginf)
    ensure("increment subtracts previous cumulative evidence", near(evidence-increment(ln(0.5), ln(0.125)), ln(0.25)))
  })

fun test-suspended-populations() : <div,exn> ()
  val result = pseudo-random(1931, fn(){
    sample-population(8, fn(){
      accumulate-weight(ln(0.5))
      checkpoint()
      accumulate-weight(ln(0.25))
      checkpoint()
      7
    })
  })
  ensure("checkpoint population retains its size", result.values == [7, 7, 7, 7, 7, 7, 7, 7])
  ensure("checkpoint population scores incremental factors once", near(result.log-evidence, ln(0.125)))
  val dead = pseudo-random(1933, fn(){
    sample-population(8, fn(){ accumulate-weight(neginf); checkpoint(); 7 })
  })
  ensure("zero-mass checkpoint population remains empty", dead.values.is-empty && dead.log-evidence == neginf)
  [1937, 1949, 1951].foreach fn(seed){
    // Exact prior masses: true 1/2 * 4/5 * 1/2 = 1/5; false 1/2 * 1/5 = 1/10.
    // The false branch finishes early and must retain unit weight at later rounds.
    val varied = pseudo-random(seed, fn(){
      sample-population(2000, fn(){
        val selected = random-float64() < 0.5
        accumulate-weight(ln(if selected then 0.8 else 0.2))
        if selected then
          checkpoint()
          accumulate-weight(ln(0.5))
        selected
      })
    })
    val probability = float64(varied.values.filter(fn(value){ value }).length) / float64(varied.values.length)
    ensure("variable checkpoint counts preserve posterior mass", abs(probability - 2.0/3.0) < 0.05)
    ensure("variable checkpoint counts preserve evidence", abs(exp(varied.log-evidence) - 0.3) < 0.025)
  }

val observation = obs-bool("transformations/stream")

fun test-suspended-readers() : <div,exn> ()
  pseudo-random(1957, fn(){
    val paused = suspend(fn(){
      run-lw(singleton(observation, [True, False]), fn(){
        val first = bernoulli(observation, 0.6)
        checkpoint()
        val second = bernoulli(observation, 0.25)
        (first, second)
      })
    })
    val first = complete(paused)
    val second = complete(paused)
    ensure("cloned continuation restores its observation cursor", first.value == (True, False) && second.value == (True, False))
    ensure("cloned reader keeps the same likelihood", near(first.log-weight, ln(0.45)) && near(second.log-weight, ln(0.45)))
    ensure("cloned reader keeps an independent trace", first.trace.length == 2 && second.trace.length == 2)
  })

fun variable-prior-spec() : sequential-model<e,bool,bool,(),bool>
  Sequential-model(
    fn(){
      val parameter = bernoulli'(0.5)
      if parameter then
        val observed = bernoulli(observation, 0.5)
        ()
      parameter
    },
    fn(_parameter){ bernoulli(observation, 0.5) },
    fn(_parameter, _index, state){ Step-output(state, ()) },
    fn(result){ result.current-state })

fun variable-kernel(parameter : bool) : parameter-proposal<bool>
  val proposed = not(parameter)
  // The prior consumes the first datum exactly when the proposed parameter is true.
  Parameter-proposal(proposed,
    if proposed then singleton(observation, [True]) else empty(),
    singleton(observation, if proposed then [False] else [True, False]),
    0.0)

fun test-parameter-cursors() : <div,exn> ()
  val environment = singleton(observation, [True, False])
  val parameter-score = fn(parameter){ if parameter then ln(0.25) else ln(0.5) }
  val pm = pseudo-random(1913, fn(){
    pmmh-with-state(2, 1, default-config(30), environment, variable-prior-spec(),
      parameter-score, variable-kernel)
  })
  ensure("state-aware PMMH exercises accepted proposals", pm.accepted > 0 && pm.samples.length == 30)
  ensure("state-aware PMMH handles both prior consumption patterns", pm.samples.any(fn(sample){ sample.parameter }) && pm.samples.any(fn(sample){ not(sample.parameter) }))
  pm.samples.foreach fn(sample){
    ensure("PMMH proposed filter receives the proposed cursor", sample.estimate.particles.all(fn(particle){ particle.value == not(sample.parameter) }))
    ensure("PMMH scores the inner observation once", near(sample.log-evidence, ln(0.5)))
  }
  val sq = pseudo-random(1919, fn(){
    smc2-with-state(24, 2, 1, 1, environment, variable-prior-spec(),
      parameter-score, variable-kernel)
  })
  ensure("state-aware SMC2 retains its population", sq.particles.length == 24)
  ensure("state-aware SMC2 handles both prior consumption patterns", sq.particles.any(fn(particle){ particle.parameter }) && sq.particles.any(fn(particle){ not(particle.parameter) }))
  sq.particles.foreach fn(particle){
    ensure("SMC2 rejuvenation uses the proposed cursor", particle.estimate.particles.all(fn(inner){ inner.value == not(particle.parameter) }))
    ensure("SMC2 scores the inner observation once", near(particle.log-evidence, ln(0.5)))
  }

fun scored-spec() : sequential-model<e,(),(),(),int>
  Sequential-model(fn(){ () }, fn(_parameter){ log-score(ln(0.5)); () },
    fn(_parameter, _index, state){ log-score(ln(0.25)); Step-output(state, ()) },
    fn(_result){ 7 })

fun test-nested-evidence() : <div,exn,random> ()
  val outer = pseudo-random(1921, fn(){
    run-lw(empty(), fn(){
      log-score(ln(0.8))
      val inner = smc2(3, 2, 1, 1, empty(), scored-spec())
      log-score(inner.log-evidence)
      inner
    })
  })
  ensure("nested filter scores do not leak; its estimate is scored once", near(outer.log-weight, ln(0.1)))
  ensure("nested filter evidence includes initial and step scores once", near(outer.value.log-evidence, ln(0.125)))
  ensure("only explicit outer scores enter its trace", outer.trace.length == 2)

pub fun main() : <console,div,exn,random> ()
  test-checkpoints()
  test-scoring-across-checkpoints()
  test-populations()
  test-suspended-populations()
  test-suspended-readers()
  test-parameter-cursors()
  test-nested-evidence()
  println("Inference transformation checks passed.")
