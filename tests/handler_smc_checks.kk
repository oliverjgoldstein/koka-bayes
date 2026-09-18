module handler_smc_checks

import std/num/float64
import std/num/random
import alg/handler_smc
import alg/lw
import alg/lwis
import alg/smc
import core/env
import core/model
import core/obsvar
import core/trace
import handlers/sequential

val datum = obs-bool("handler-smc/data")

fun ensure(message : string, condition : bool) : exn ()
  if not(condition) then throw(message)

fun near(actual : float64, expected : float64) : bool
  abs(actual - expected) < 1.0e-12

fun plain-model() : <obs-reader,model-dist,div|e> bool
  val latent = bernoulli'(0.4)
  val observed = bernoulli(datum, if latent then 0.8 else 0.2)
  log-score(ln(0.5))
  latent

fun test-no-checkpoints() : <div,exn> ()
  val environment = singleton(datum, [True])
  val actual = pseudo-random(2003, fn(){
    smc-model(300, environment, fn(){ mask<checkpoint>{ plain-model() } })
  })
  val expected = pseudo-random(2003, fn(){
    val weighted = lw(300, environment, plain-model)
    resample-weighted(300, weighted)
  })
  ensure("without checkpoints handler SMC is seeded weighted resampling", actual.particles.map(fn(p){ p.value }) == expected.map(fn(p){ p.value }))
  ensure("without checkpoints scores agree particle by particle", actual.particles.map(fn(p){ p.log-likelihood }) == expected.map(fn(p){ p.log-weight }))
  actual.particles.foreach fn(particle){
    ensure("without checkpoints scoring preserves one observation", get(datum, particle.output-env) == [True])
    ensure("without checkpoints trace keeps latent, observation and factor", particle.trace.length == 3)
  }

fun binary-joint() : <checkpoint,obs-reader,model-dist,div|e> (bool,bool,int)
  var count := 0
  val first = bernoulli'(0.4)
  val observed-first = bernoulli(datum, if first then 0.8 else 0.2)
  count := count + 1
  checkpoint()
  val second = bernoulli'(if first then 0.7 else 0.3)
  val observed-second = bernoulli(datum, if second then 0.6 else 0.1)
  log-score(ln(0.5))
  count := count + 1
  checkpoint()
  (first, second, count)

fun test-joint-posterior() : <div,exn> ()
  // Independent enumeration of the four joint prior/likelihood products:
  // TT=.4*.8*.7*.4*.5; TF=.4*.8*.3*.9*.5;
  // FT=.6*.2*.3*.4*.5; FF=.6*.2*.7*.9*.5. Their sum is .133.
  val exact = [(True, True, 0.0448), (True, False, 0.0432),
               (False, True, 0.0072), (False, False, 0.0378)]
  [2011, 2017, 2027].foreach fn(seed){
    val result = pseudo-random(seed, fn(){
      smc-model(2000, singleton(datum, [True, False]), binary-joint)
    })
    ensure("checkpoint SMC preserves the particle count", result.particles.length == 2000)
    ensure("checkpoint SMC evidence matches the exact joint sum", abs(exp(result.log-evidence) - 0.133) < 0.018)
    exact.foreach fn(reference){
      val (first, second, mass) = reference
      val matches = result.particles.filter(fn(particle){
        val (x, z, _) = particle.value
        x == first && z == second
      }).length
      val probability = float64(matches) / 2000.0
      ensure("checkpoint SMC matches each exact joint posterior cell", abs(probability - mass / 0.133) < 0.065)
    }
    result.particles.foreach fn(particle){
      val (first, second, count) = particle.value
      ensure("resampled continuations clone model-local state", count == 2)
      ensure("resampled continuations clone the observation cursor", get(datum, particle.output-env) == [True, False])
      ensure("resampled continuations clone the trace and address counter", particle.trace.map(fn(entry){ entry.address }) == [0, 1, 2, 3, 4])
      val expected = ln(if first then 0.8 else 0.2) + ln(if second then 0.4 else 0.9) + ln(0.5)
      ensure("the output likelihood contains each observation and factor once", near(particle.log-likelihood, expected))
    }
  }

fun test-zero-mass() : <div,exn> ()
  val result = pseudo-random(2029, fn(){
    smc-model(5, empty(), fn(){
      log-score(neginf)
      checkpoint()
      throw("a zero-mass continuation must not be resumed")
      7
    })
  })
  ensure("zero-mass handler SMC returns no posterior", result.particles.is-empty && result.log-evidence == neginf)
  val zero-count = pseudo-random(2039, fn(){
    smc-model(0, empty(), fn(){ throw("zero particles must not execute a model"); 7 })
  })
  ensure("zero particles produce no evidence estimate", zero-count.particles.is-empty && zero-count.log-evidence == neginf)

pub fun main() : <console,div,exn> ()
  test-no-checkpoints()
  test-joint-posterior()
  test-zero-mass()
  println("Checkpoint SMC checks passed.")
