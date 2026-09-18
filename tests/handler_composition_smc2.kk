module handler_composition_smc2

import std/num/float64
import std/num/random
import alg/lw
import alg/smc
import alg/smc2
import core/env
import core/model
import core/obsvar
import core/sequential
import core/trace

val prior-y = obs-bool("composition/smc2/prior")
val initial-y = obs-bool("composition/smc2/initial")
val shared-y = obs-bool("composition/smc2/shared")
val latent-x = obs-float64("composition/smc2/latent")

fun ensure(message : string, condition : bool) : exn ()
  if not(condition) then throw(message)

fun near(actual : float64, expected : float64) : bool
  abs(actual - expected) < 1.0e-12

fun weighted-initial(prior-probability : float64, initial-probability : float64) : sequential-model<e,bool,(),(),bool>
  Sequential-model(
    fn(){
      val parameter = bernoulli'(0.8)
      val observed = bernoulli(prior-y, prior-probability)
      parameter
    },
    fn(_){ val observed = bernoulli(initial-y, initial-probability); () },
    fn(_, _, _){ Step-output((), ()) },
    fn(prefix-state){ prefix-state.parameter })

fun initial-environment() : env
  set(prior-y, [True], set(initial-y, [True], empty()))

fun check-initial-factors() : <exn,div> ()
  val environment = initial-environment()
  val model = weighted-initial(0.4, 0.25)
  val zero = pseudo-random(9401, fn(){ smc2(12, 3, 0, 2, environment, model) })
  ensure("SMC2 zero-step initialization retains particles", zero.particles.length == 12)
  ensure("SMC2 scores prior and initial observations exactly once", near(exp(zero.log-evidence), 0.1))
  ensure("SMC2 inner evidence excludes the separately scored prior", zero.particles.all(fn(item){ near(exp(item.log-evidence), 0.25) }))

  // The unequal prior makes omitted initial proposal cancellation observable.
  // With a constant likelihood, all initial importance weights must be 0.1.
  val score = fn(parameter){ ln(if parameter then 0.8 else 0.2) + ln(0.4) }
  val identity : bool -> (bool,env,float64) = fn(parameter){ (parameter, empty(), 0.0) }
  [0, 2].foreach fn(steps){
    val custom = pseudo-random(9403, fn(){ smc2-with(12, 3, steps, 2, environment, model, score, identity) })
    ensure("custom SMC2 divides by the actual sampled prior density", near(exp(custom.log-evidence), 0.1))
    ensure("custom SMC2 retains its full population", custom.particles.length == 12)
  }

  [weighted-initial(0.0, 0.25), weighted-initial(0.4, 0.0)].foreach fn(impossible-model){
    val result = pseudo-random(9405, fn(){ smc2(12, 3, 2, 2, environment, impossible-model) })
    ensure("impossible prior or initial factors collapse SMC2", result.particles.is-empty && result.log-evidence == neginf)
  }

fun persistent-model() : sequential-model<e,int,float64,bool,float64>
  Sequential-model(
    fn(){ 1 },
    fn(_){ normal(latent-x, 0.0, 1.0) },
    fn(_, _, state){ Step-output(state, bernoulli(shared-y, 0.5)) },
    fn(prefix-state){ prefix-state.current-state })

fun check-rejected-filter() : <exn,div> ()
  val environment = set(shared-y, [True, False], empty())
  val model = persistent-model()
  val score = fn(parameter){ if parameter == 1 then 0.0 else neginf }
  val rejected : int -> (int,env,float64) = fn(_){ (2, empty(), 0.0) }
  val baseline = pseudo-random(9407, fn(){ smc2-with(1, 1, 2, 0, environment, model, score, rejected) })
  val moved = pseudo-random(9407, fn(){ smc2-with(1, 1, 2, 3, environment, model, score, rejected) })
  ensure("rejected SMC2 moves preserve the parameter", moved.particles.map(fn(item){ item.parameter }) == [1])
  // A single retained particle and deterministic state transition remove
  // resampling variation, even though rejected proposals consume fresh RNG.
  val baseline-values = baseline.particles.flatmap(fn(item){ item.estimate.particles.map(fn(p){ p.value }) })
  val moved-values = moved.particles.flatmap(fn(item){ item.estimate.particles.map(fn(p){ p.value }) })
  ensure("rejected SMC2 moves retain the old latent trajectory", moved-values == baseline-values)
  ensure("rejected SMC2 moves retain the old filter output", moved.posterior-env.show == baseline.posterior-env.show)
  ensure("rejected SMC2 moves retain the old evidence estimate", moved.log-evidence == baseline.log-evidence && near(exp(moved.log-evidence), 0.25))
  val baseline-traces = baseline.particles.flatmap(fn(item){ item.estimate.particles.map(fn(p){ p.trace.show }) })
  val moved-traces = moved.particles.flatmap(fn(item){ item.estimate.particles.map(fn(p){ p.trace.show }) })
  ensure("rejected SMC2 moves retain the old filter trace", moved-traces == baseline-traces)

fun nested-model() : sequential-model<e,(),(),bool,()>
  Sequential-model(fn(){ () }, fn(_){ () },
    fn(_, _, _){ Step-output((), bernoulli(shared-y, 0.8)) }, fn(_){ () })

fun check-nested-handlers() : <exn,div> ()
  val outer-environment = set(shared-y, [True, False], empty())
  val inner-environment = set(shared-y, [False, True], empty())
  val result = pseudo-random(9409, fn(){
    run-lw(outer-environment, fn(){
      val before = bernoulli(shared-y, 0.6)
      val nested = pseudo-random(9411, fn(){ smc2(3, 2, 2, 1, inner-environment, nested-model()) })
      val after = bernoulli(shared-y, 0.3)
      (before, after, nested.log-evidence)
    })
  })
  val (before, after, nested-evidence) = result.value
  ensure("nested SMC2 preserves the outer observation cursor", before && not(after))
  ensure("nested SMC2 uses its own observations and weights", near(exp(nested-evidence), 0.16))
  ensure("nested SMC2 does not leak likelihood into outer LW", near(exp(result.log-weight), 0.42))
  ensure("nested SMC2 does not leak trace entries into outer LW", result.trace.length == 2 && result.trace.map(fn(entry){ entry.address }) == [0, 1])
  ensure("nested SMC2 does not leak observations into outer output", get(shared-y, result.output-env) == [True, False])

pub fun main() : <console,exn,div> ()
  check-initial-factors()
  check-rejected-filter()
  check-nested-handlers()
  println("SMC2 handler composition checks passed.")
