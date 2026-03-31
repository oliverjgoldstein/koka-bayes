module alg/simulate

import std/num/random
import std/core/unsafe
import core/dist
import core/env
import core/model
import core/trace
import handlers/core

pub struct simulate-result<a>
  value      : a
  trace      : run-trace
  output-env : env

noinline val sim-address : ref<global,int> = unsafe-total{ ref(0) }
noinline val sim-trace   : ref<global,run-trace> = unsafe-total{ ref([]) }

// Simulation is a handler composition over the core specialisation pass.
pub fun simulate(environment : env, action : model<e,a>) : <div,random|e> simulate-result<a>
  unsafe-total(fn(){ sim-address := 0; sim-trace := [] })
  with val sample-hook = fn(observable, distribution)
    val address = unsafe-total(fn(){ !sim-address })
    val value = sample(distribution)
    val entry = make-entry(address, observable, distribution, value, TraceSampled)
    unsafe-total(fn(){ sim-address := address + 1; sim-trace := !sim-trace ++ [entry] })
    value
  with val observe-hook = fn(name, distribution, value)
    val address = unsafe-total(fn(){ !sim-address })
    val entry = make-entry(address, Just(name), distribution, value, TraceObserved)
    unsafe-total(fn(){ sim-address := address + 1; sim-trace := !sim-trace ++ [entry] })
    value
  val value = handle-core(environment, action)
  val trace = unsafe-total(fn(){ !sim-trace })
  val output = to-output-env(trace)
  Simulate-result(value, trace, output)
