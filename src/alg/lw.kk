module alg/lw

import std/num/random
import std/core/unsafe
import std/num/float64
import core/dist
import core/env
import core/model
import core/trace
import handlers/core

pub struct weighted-sample<a>
  value      : a
  trace      : run-trace
  output-env : env
  log-weight : float64

noinline val lw-address : ref<global,int> = unsafe-total{ ref(0) }
noinline val lw-trace   : ref<global,run-trace> = unsafe-total{ ref([]) }
noinline val lw-weight  : ref<global,float64> = unsafe-total{ ref(0.0) }

// Likelihood weighting accumulates observed log-probability contributions.
pub fun run-lw(environment : env, action : model<e,a>) : <div,random|e> weighted-sample<a>
  unsafe-total(fn(){ lw-address := 0; lw-trace := []; lw-weight := 0.0 })
  with val sample-hook = fn(observable, distribution)
    val address = unsafe-total(fn(){ !lw-address })
    val value = sample(distribution)
    val entry = make-entry(address, observable, distribution, value, TraceSampled)
    unsafe-total(fn(){ lw-address := address + 1; lw-trace := !lw-trace ++ [entry] })
    value
  with val observe-hook = fn(name, distribution, value)
    val address = unsafe-total(fn(){ !lw-address })
    val entry = make-entry(address, Just(name), distribution, value, TraceObserved)
    unsafe-total(fn(){
      lw-address := address + 1
      lw-trace := !lw-trace ++ [entry]
      lw-weight := !lw-weight + entry.log-prob
    })
    value
  val value = handle-core(environment, action)
  val trace = unsafe-total(fn(){ !lw-trace })
  val weight = unsafe-total(fn(){ !lw-weight })
  val output = to-output-env(trace)
  Weighted-sample(value, trace, output, weight)

pub fun lw(iterations : int, environment : env, action : model<e,a>) : <div,random|e> list<weighted-sample<a>>
  if iterations <= 0
    then []
    else Cons(run-lw(environment, action), lw(iterations - 1, environment, action))
