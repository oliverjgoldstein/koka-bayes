module handler_composition_pmmh

import std/num/float64
import std/num/random
import alg/lw
import alg/mcmc
import alg/pmmh
import alg/smc
import core/env
import core/model
import core/obsvar
import core/sequential
import core/trace

val outer-y = obs-bool("composition/pmmh/outer")
val second-y = obs-bool("composition/pmmh/second")
val noise-y = obs-float64("composition/pmmh/noise")

fun ensure(message : string, condition : bool) : exn ()
  if not(condition) then throw(message)

fun near(actual : float64, expected : float64) : bool
  abs(actual - expected) < 1.0e-12

fun rejection-spec() : sequential-model<e,bool,float64,(),float64>
  Sequential-model(
    fn(){ True },
    fn(_parameter){
      val x = normal'(0.0, 1.0)
      val observed = normal(noise-y, x, 1.0)
      x
    },
    fn(_parameter, _index, state){ Step-output(state, ()) },
    fn(prefix-state){ prefix-state.current-state })

fun test-rejected-filter() : <div,exn> ()
  val result = pseudo-random(1301, fn(){
    pmmh-with(3, 0, default-config(16, 4), singleton(noise-y, [0.0]), rejection-spec(),
      fn(parameter){ if parameter then 0.0 else neginf },
      fn(_parameter){ (False, singleton(outer-y, [False]), 0.0) })
  })
  ensure("PMMH rejected proposals retain draw multiplicity", result.accepted == 0 && result.samples.length == 12)
  match result.samples
    Nil -> throw("PMMH expected a retained state")
    Cons(first, _) ->
      val values = first.estimate.particles.map(fn(particle){ particle.value })
      val traces = first.estimate.particles.map(fn(particle){ particle.trace.map(fn(entry){ entry.log-prob }) })
      ensure("PMMH test starts from a finite noisy filter", is-finite(first.log-evidence) && first.estimate.particles.length == 3)
      result.samples.foreach fn(sample){
        ensure("PMMH rejection retains the parameter and its environment", sample.parameter && get(outer-y, sample.parameter-env).is-empty)
        ensure("PMMH rejection retains the cached likelihood estimate", sample.log-evidence == first.log-evidence)
        ensure("PMMH rejection retains the complete particle population", sample.estimate.particles.map(fn(particle){ particle.value }) == values)
        ensure("PMMH rejection retains particle traces", sample.estimate.particles.map(fn(particle){ particle.trace.map(fn(entry){ entry.log-prob }) }) == traces)
      }

fun inner-spec() : sequential-model<e,(),bool,(),bool>
  Sequential-model(fn(){ () }, fn(_parameter){ bernoulli(outer-y, 0.2) },
    fn(_parameter, _index, state){ Step-output(state, ()) }, fn(prefix-state){ prefix-state.current-state })

fun test-pmmh-inside-lw() : <div,exn,random> ()
  val result = pseudo-random(1303, fn(){
    run-lw(singleton(outer-y, [True, False]), fn(){
      val first = bernoulli(outer-y, 0.6)
      val nested = pmmh(2, 0, default-config(4), singleton(outer-y, [False]), inner-spec())
      val second = bernoulli(outer-y, 0.3)
      (first, second, nested)
    })
  })
  val (first, second, nested) = result.value
  ensure("nested PMMH preserves the outer observation reader", first && not(second))
  ensure("nested PMMH preserves outer trace and addresses", result.trace.map(fn(entry){ entry.address }) == [0, 1])
  ensure("nested PMMH does not add to the outer likelihood", near(result.log-weight, ln(0.6) + ln(0.7)))
  ensure("nested PMMH retains its own observations", nested.samples.length == 4 && nested.samples.all(fn(sample){
    near(sample.log-evidence, ln(0.8)) && sample.estimate.particles.all(fn(particle){ not(particle.value) && particle.trace.length == 1 })
  }))

fun test-lw-inside-pmmh() : <div,exn,random> ()
  val spec = Sequential-model(
    fn(){
      val first = bernoulli(outer-y, 0.6)
      val nested = run-lw(singleton(outer-y, [False]), fn(){ bernoulli(outer-y, 0.2) })
      val second = bernoulli(second-y, 0.3)
      (first, second, nested.log-weight)
    },
    fn(_parameter){ () },
    fn(_parameter, _index, _state){ Step-output((), ()) },
    fn(prefix-state){ prefix-state.parameter })
  val environment = set(outer-y, [True], singleton(second-y, [False]))
  val result = pseudo-random(1307, fn(){ pmmh(2, 0, default-config(5), environment, spec) })
  ensure("nested LW leaves identical PMMH prior proposals accepted", result.accepted == 5 && result.samples.length == 5)
  result.samples.foreach fn(sample){
    val (first, second, inner-weight) = sample.parameter
    ensure("nested LW preserves PMMH parameter observations", first && not(second) && near(inner-weight, ln(0.8)))
    ensure("nested LW cannot append to the PMMH parameter environment", get(outer-y, sample.parameter-env) == [True] && get(second-y, sample.parameter-env) == [False])
    ensure("nested LW cannot enter the PMMH inner filter", sample.log-evidence == 0.0 && sample.estimate.particles.all(fn(particle){ particle.trace.is-empty }))
  }

pub fun main() : <console,div,exn,random> ()
  test-rejected-filter()
  test-pmmh-inside-lw()
  test-lw-inside-pmmh()
  println("PMMH handler composition checks passed.")
