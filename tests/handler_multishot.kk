module handler_multishot

import bayes
import alg/lw
import alg/simulate
import alg/mh
import alg/rmsmc
import alg/smc
import alg/pmmh
import alg/smc2
import alg/mcmc
import core/sequential
import core/trace
import std/num/int32
import std/num/random

effect branch
  ctl choose-branch() : bool

fun both(reverse : bool, action : () -> <branch|e> a) : e list<a>
  handle(action)
    return(value) [value]
    ctl choose-branch()
      val first = resume(not(reverse))
      val second = resume(reverse)
      first ++ second

fun ensure(label : string, condition : bool) : exn ()
  if not(condition) then throw(label)

fun near(actual : float64, expected : float64) : bool
  abs(actual - expected) < 1.0e-12

val y = obs-bool("multishot/y")

fun branch-model() : <branch,model-dist> bool
  val selected = choose-branch()
  val observed = bernoulli(y, if selected then 0.8 else 0.2)
  selected

fun branch-spec() : sequential-model<<branch|e>,(),bool,(),bool>
  Sequential-model(fn(){ () }, fn(_){ branch-model() },
    fn(_, _, previous){ Step-output(previous, ()) },
    fn(prefix-state){ prefix-state.current-state })

fun check-trace(label : string, selected : bool, trace : run-trace) : exn ()
  ensure(label ++ " has one branch-local observation", trace.length == 1 && sample-count(trace) == 0)
  ensure(label ++ " starts its own trace addresses", trace.map(fn(entry){ entry.address }) == [0])
  ensure(label ++ " scores only its own branch", near(exp(observed-log-prob(trace)), if selected then 0.8 else 0.2))
  ensure(label ++ " retains its input observation", get(y, to-output-env(trace)) == [True])

fun test-direct(reverse : bool) : <div,exn> ()
  val environment = singleton(y, [True])
  with fun random-int32() ~1.int32
  val weighted = both(reverse, fn(){ run-lw(environment, branch-model) })
  val simulated = both(reverse, fn(){ simulate(environment, branch-model) })
  val order = [not(reverse), reverse]
  ensure("LW visits both continuation resumptions", weighted.map(fn(result){ result.value }) == order)
  ensure("simulation visits both continuation resumptions", simulated.map(fn(result){ result.value }) == order)
  weighted.foreach fn(result){
    check-trace("LW", result.value, result.trace)
    ensure("LW weight agrees with its branch trace", near(result.log-weight, observed-log-prob(result.trace)))
  }
  simulated.foreach fn(result){ check-trace("simulation", result.value, result.trace) }

fun test-nested(reverse : bool) : <div,exn> ()
  with fun random-int32() ~1.int32
  val results = both(reverse, fn(){
    run-lw(singleton(y, [True, False, True]), fn(){
      val first = bernoulli(y, 0.6)
      val left = choose-branch()
      val middle = bernoulli(y, if left then 0.8 else 0.2)
      val right = choose-branch()
      val last = bernoulli(y, if right then 0.7 else 0.3)
      (left, right, first, middle, last)
    })
  })
  ensure("nested branching explores all four paths", results.length == 4)
  results.foreach fn(result){
    val (left, right, first, middle, last) = result.value
    ensure("nested continuation branches each restore their observation cursor", first && not(middle) && last)
    ensure("nested continuation branches each restore their trace address", result.trace.map(fn(entry){ entry.address }) == [0, 1, 2])
    ensure("nested continuation branches preserve only their own outputs", get(y, result.output-env) == [True, False, True])
    val expected = 0.6 * (if left then 0.2 else 0.8) * (if right then 0.7 else 0.3)
    ensure("nested continuation branches restore accumulated likelihood", near(exp(result.log-weight), expected))
  }

fun test-populations(reverse : bool) : <div,exn> ()
  val environment = singleton(y, [True])
  with fun random-int32() ~1.int32
  val rm = both(reverse, fn(){ rmsmc(1, 0, 0, environment, branch-spec()) })
  val s2 = both(reverse, fn(){ smc2(1, 1, 0, 0, environment, branch-spec()) })
  ensure("RMSMC visits both continuation resumptions", rm.length == 2)
  ensure("SMC2 visits both continuation resumptions", s2.length == 2)
  rm.foreach fn(result){
    ensure("RMSMC retains one particle per branch", result.particles.length == 1)
    result.particles.foreach fn(particle){
      check-trace("RMSMC", particle.value, particle.trace)
      ensure("RMSMC evidence belongs to its branch", near(result.log-evidence, observed-log-prob(particle.trace)))
    }
  }
  s2.foreach fn(result){
    ensure("SMC2 retains one outer particle per branch", result.particles.length == 1)
    result.particles.foreach fn(outer){
      ensure("SMC2 retains one inner particle per branch", outer.estimate.particles.length == 1)
      outer.estimate.particles.foreach fn(particle){
        check-trace("SMC2", particle.value, particle.trace)
        ensure("SMC2 outer evidence belongs to its branch", near(result.log-evidence, observed-log-prob(particle.trace)))
        ensure("SMC2 inner evidence belongs to its branch", near(outer.log-evidence, observed-log-prob(particle.trace)))
      }
    }
  }

fun test-chains(reverse : bool) : <div,exn> ()
  val environment = singleton(y, [True])
  // A near-one uniform rejects the .8 -> .2 transition. The other three
  // initial/proposed pairs accept, giving an exact retained-state oracle.
  with fun random-int32() ~1.int32
  val pm = both(reverse, fn(){ pmmh(1, 0, default-config(1), environment, branch-spec()) })
  val single = both(reverse, fn(){ mh(1, 0, environment, branch-model) })
  val retained = if reverse then [False, True, True, True] else [True, True, True, False]
  ensure("PMMH explores four initial/proposal paths", pm.length == 4)
  ensure("MH explores four initial/proposal paths", single.length == 4)
  val pm-values = pm.flatmap(fn(result){ result.samples.flatmap(fn(draw){ draw.estimate.particles.map(fn(p){ p.value }) }) })
  val mh-values = single.flatmap(fn(result){ result.samples.map(fn(draw){ draw.value }) })
  ensure("PMMH rejection retains the correct branch state", pm-values == retained)
  ensure("MH rejection retains the correct branch state", mh-values == retained)
  pm.foreach fn(result){
    ensure("PMMH retains one draw per branch", result.samples.length == 1)
    result.samples.foreach fn(draw){
      draw.estimate.particles.foreach fn(particle){
        check-trace("PMMH", particle.value, particle.trace)
        ensure("PMMH retains its branch likelihood after rejection", near(draw.log-evidence, observed-log-prob(particle.trace)))
      }
    }
  }
  single.foreach fn(result){
    ensure("MH retains one draw per branch", result.samples.length == 1)
    result.samples.foreach fn(draw){ check-trace("MH", draw.value, draw.trace) }
  }

pub fun main() : <console,div,exn> ()
  [False, True].foreach fn(reverse){
    test-direct(reverse)
    test-nested(reverse)
    test-populations(reverse)
    test-chains(reverse)
  }
  println("Multi-shot handler checks passed.")
