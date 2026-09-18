module probes/handler_multishot

// Historical failure reproduction, now repaired by branch-local handler state.
// Each branch has one trace entry and likelihood 0.8 or 0.2.
// The assertion-based regression lives in tests/handler_multishot.kk.

import bayes
import alg/lw
import std/num/random
import alg/rmsmc
import alg/smc
import alg/pmmh
import alg/smc2
import alg/mcmc
import core/sequential

effect branch
  ctl choose-branch() : bool

fun both(action : () -> <branch|e> a) : e list<a>
  handle(action)
    return(value) [value]
    ctl choose-branch()
      val left = resume(True)
      val right = resume(False)
      left ++ right

fun spec() : sequential-model<<branch|e>,(),bool,(),bool>
  Sequential-model(
    fn(){ () },
    fn(_parameter){
      val selected = choose-branch()
      val observed = bernoulli(obs-bool("y"), if selected then 0.8 else 0.2)
      selected
    },
    fn(_parameter, _index, previous){ Step-output(previous, ()) },
    fn(result){ result.current-state })

pub fun main() : <console,div> ()
  val y = obs-bool("y")
  val results = pseudo-random(719, fn(){
    both(fn(){
      run-lw(singleton(y, [True]), fn(){
        val selected = choose-branch()
        val observed = bernoulli(y, if selected then 0.8 else 0.2)
        selected
      })
    })
  })
  results.foreach fn(result){
    println("branch=" ++ result.value.show ++ "; trace=" ++ result.trace.length.show
      ++ "; weight=" ++ exp(result.log-weight).show)
  }
  val environment = singleton(y, [True])
  val rm = pseudo-random(719, fn(){ both(fn(){ rmsmc(1, 0, 0, environment, spec()) }) })
  rm.foreach fn(result){ println("RMSMC evidence=" ++ exp(result.log-evidence).show) }
  val s2 = pseudo-random(719, fn(){ both(fn(){ smc2(1, 1, 0, 0, environment, spec()) }) })
  s2.foreach fn(result){ println("SMC2 evidence=" ++ exp(result.log-evidence).show) }
  val pm = pseudo-random(719, fn(){ both(fn(){ pmmh(1, 0, default-config(1), environment, spec()) }) })
  pm.foreach fn(result){
    result.samples.foreach fn(draw){
      println("PMMH estimate=" ++ exp(draw.log-evidence).show ++ "; trace lengths="
        ++ draw.estimate.particles.map(fn(particle){ particle.trace.length }).show)
    }
  }
