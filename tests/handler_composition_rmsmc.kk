module handler_composition_rmsmc

import std/num/float64
import std/num/int32
import std/num/random
import alg/lw
import alg/rmsmc
import alg/smc
import core/env
import core/model
import core/obsvar
import core/sequential
import core/trace

val step-y = obs-bool("composition/rmsmc/step")
val outer-y = obs-bool("composition/rmsmc/outer")
val inner-y = obs-bool("composition/rmsmc/inner")

fun ensure(label : string, condition : bool) : exn ()
  if not(condition) then throw(label)

fun near(actual : float64, expected : float64) : bool
  abs(actual - expected) < 1.0e-12

fun observed-sites(result : smc-result<a>) : int
  result.particles.foldl(0, fn(acc, p){ acc + p.trace.length - sample-count(p.trace) })

fun observations-spec() : sequential-model<e,(),(),bool,list<bool>>
  Sequential-model(
    fn(){ () },
    fn(_parameter){ () },
    fn(_parameter, _index, _previous){ Step-output((), bernoulli(step-y, 0.5)) },
    fn(prefix-state){ prefix-state.observations })

fun explicit-observations(moves : int) : div smc-result<list<bool>>
  // Any accidentally unobserved Bernoulli(0.5) site would return False.
  with fun random-int32() ~1.int32
  rmsmc(1, 2, moves, set(step-y, [True, True], empty()), observations-spec())

fun test-prefix-observation-consistency() : <div,exn> ()
  val unmoved = explicit-observations(0)
  [1, 5].foreach fn(moves){
    val moved = explicit-observations(moves)
    ensure("RMSMC moves preserve every explicit step observation",
      moved.particles.map(fn(p){ p.value }) == [[True, True]])
    ensure("RMSMC prefix replay preserves observation modes", observed-sites(moved) == 2)
    ensure("RMSMC prefix replay preserves the complete trace",
      moved.particles.map(fn(p){ p.trace.show }) == unmoved.particles.map(fn(p){ p.trace.show }))
    ensure("RMSMC moves preserve the accumulated likelihood",
      moved.particles.all(fn(p){ near(p.log-likelihood, 2.0 * ln(0.5)) }))
    ensure("RMSMC moves leave evidence unchanged", moved.log-evidence == unmoved.log-evidence)
  }

fun nested-spec() : sequential-model<e,(),(),bool,list<bool>>
  Sequential-model(
    fn(){ () },
    fn(_parameter){ () },
    fn(_parameter, _index, _previous){
      // The inner computation is deterministic under its supplied datum.
      // Its observation must not leak into either LW or simulation replay.
      val inner = {
        with fun random-int32() ~1.int32
        run-lw(set(inner-y, [True], empty()), fn(){ bernoulli(inner-y, 0.2) })
      }
      Step-output((), bernoulli(step-y, if inner.value then 0.5 else 0.0))
    },
    fn(prefix-state){ prefix-state.observations })

fun test-nested-handler-isolation() : <div,exn> ()
  val outer = {
    with fun random-int32() ~1.int32
    run-lw(set(outer-y, [True, False], empty()), fn(){
      val first = bernoulli(outer-y, 0.6)
      val nested = {
        with fun random-int32() ~1.int32
        rmsmc(1, 2, 2, set(step-y, [True, True], empty()), nested-spec())
      }
      val last = bernoulli(outer-y, 0.3)
      (first, nested, last)
    })
  }
  val (first, nested, last) = outer.value
  ensure("RMSMC preserves the surrounding observation reader", first && not(last))
  ensure("RMSMC does not leak inner likelihoods into surrounding LW", near(outer.log-weight, ln(0.6) + ln(0.7)))
  ensure("RMSMC does not leak or reset outer trace addresses", outer.trace.map(fn(entry){ entry.address }) == [0, 1])
  ensure("nested LW does not leak into RMSMC propagation or replay", observed-sites(nested) == 2)
  ensure("nested LW preserves RMSMC's own observations", nested.particles.map(fn(p){ p.value }) == [[True, True]])
  ensure("nested LW preserves RMSMC's own likelihood", nested.particles.all(fn(p){ near(p.log-likelihood, 2.0 * ln(0.5)) }))
  ensure("nested inference environments remain separate", get(inner-y, nested.posterior-env).is-empty && get(step-y, outer.output-env).is-empty)

fun rejection-spec() : sequential-model<e,bool,(),bool,bool>
  Sequential-model(
    fn(){ bernoulli'(0.5) },
    fn(_parameter){ () },
    fn(parameter, _index, _previous){ Step-output((), bernoulli(step-y, if parameter then 0.0 else 1.0)) },
    fn(prefix-state){ prefix-state.parameter })

fun rejection-run(moves : int) : div (smc-result<bool>,int)
  var draws := 0
  with fun random-int32()
    draws := draws + 1
    // A random-float64 uses two int32 draws. The initial parameter is False;
    // initial and step resampling use draws 3..6. Each move then proposes
    // True (zero likelihood), followed by a rejecting acceptance draw.
    if draws == 7 || draws == 8 || draws == 11 || draws == 12 then 0.int32 else ~1.int32
  val result = rmsmc(1, 1, moves, set(step-y, [True], empty()), rejection-spec())
  (result, draws)

fun test-rejected-prefix-preserved() : <div,exn> ()
  val (unmoved, initial-draws) = rejection-run(0)
  val (moved, total-draws) = rejection-run(2)
  ensure("the deterministic stream exercised two rejected proposals", initial-draws == 6 && total-draws == 14)
  ensure("RMSMC rejection retains the parameter", moved.particles.map(fn(p){ p.value }) == [False])
  ensure("RMSMC rejection retains the complete trace",
    moved.particles.map(fn(p){ p.trace.show }) == unmoved.particles.map(fn(p){ p.trace.show }))
  ensure("RMSMC rejection retains its output environment", moved.posterior-env.show == unmoved.posterior-env.show)
  ensure("RMSMC rejection retains its likelihood", moved.particles.all(fn(p){ p.log-likelihood == 0.0 }))
  ensure("RMSMC rejection retains its evidence", moved.log-evidence == unmoved.log-evidence)

pub fun main() : <console,div,exn> ()
  test-prefix-observation-consistency()
  test-nested-handler-isolation()
  test-rejected-prefix-preserved()
  println("RMSMC handler composition checks passed.")
