module inference_regressions

import std/num/float64
import std/num/random
import alg/lw
import alg/lwis
import alg/mh
import alg/mcmc
import alg/pmmh
import alg/rmsmc
import alg/smc
import alg/smc2
import alg/simulate
import core/dist
import core/env
import core/model
import core/obsvalue
import core/obsvar
import core/sequential
import core/trace
import core/weights

fun ensure(message : string, condition : bool) : exn ()
  if condition then () else throw(message)

fun near(actual : float64, expected : float64, tolerance : float64 = 1.0e-10) : bool
  abs(actual - expected) <= tolerance

fun test-distribution-support() : <div,exn,random> ()
  ensure("Bernoulli(0) cannot be true", log-prob(bernoulli-dist(0.0), ObsBool(True)) == neginf)
  ensure("Bernoulli(1) cannot be false", log-prob(bernoulli-dist(1.0), ObsBool(False)) == neginf)
  ensure("Binomial boundary mass is exact", log-prob(binomial-dist(4, 0.0), ObsInt(0)) == 0.0)
  ensure("Binomial certain success mass is exact", log-prob(binomial-dist(4, 1.0), ObsInt(4)) == 0.0)
  ensure("Zero-trial binomial is not NaN", log-prob(binomial-dist(0, 0.0), ObsInt(0)) == 0.0)
  ensure("Impossible binomial outcome has zero mass", log-prob(binomial-dist(4, 1.0), ObsInt(3)) == neginf)
  ensure("Poisson(0) has all mass at zero", log-prob(poisson-dist(0.0), ObsInt(0)) == 0.0)
  ensure("Poisson(0) cannot be positive", log-prob(poisson-dist(0.0), ObsInt(1)) == neginf)
  val zero = pseudo-random(601, fn(){ sample(poisson-dist(0.0)) })
  ensure("Poisson(0) samples zero", match zero { ObsInt(k) -> k == 0; _ -> False })
  ensure("negative categorical index is outside support", log-prob(discrete-dist([0.2, 0.8]), ObsInt(~1)) == neginf)
  ensure("large categorical weights normalize without overflow", near(log-prob(discrete-dist([1.0e308, 1.0e308]), ObsInt(0)), ln(0.5)))
  ensure("uniform beta includes boundary density", near(log-prob(beta-dist(1.0, 1.0), ObsFloat64(0.0)), 0.0))
  ensure("exponential density at zero", near(log-prob(gamma-dist(1.0, 2.0), ObsFloat64(0.0)), ~ln(2.0)))
  ensure("invalid probabilities rejected", not(is-valid(bernoulli-dist(~0.1))))
  ensure("empty categorical rejected", not(is-valid(discrete-dist([]))))
  ensure("zero-mass categorical rejected", not(is-valid(discrete-dist([0.0, 0.0]))))
  ensure("negative categorical weights rejected", not(is-valid(discrete-dist([~1.0, 2.0]))))
  ensure("invalid normal scale rejected", not(is-valid(normal-dist(0.0, 0.0))))
  ensure("invalid gamma shape rejected", not(is-valid(gamma-dist(~1.0, 1.0))))
  ensure("reversed uniform bounds rejected", not(is-valid(uniform-dist(2.0, 1.0))))
  ensure("NaN uniform observation cannot have finite density", log-prob(uniform-dist(0.0, 1.0), ObsFloat64(nan)) == neginf)
  ensure("infinite gamma observation has no finite density", log-prob(gamma-dist(2.0, 1.0), ObsFloat64(posinf)) == neginf)

fun test-weight-collapse() : <div,exn,random> ()
  val impossible = [Weighted-sample(1, [], empty(), neginf), Weighted-sample(2, [], empty(), neginf)]
  val result = pseudo-random(603, fn(){ resample-values(20, impossible) })
  ensure("all impossible LW samples must not become a uniform posterior", result.is-empty)
  val invalid = [Weighted-sample(1, [], empty(), nan), Weighted-sample(2, [], empty(), 0.0)]
  ensure("NaN weights must not create posterior samples", pseudo-random(605, fn(){ resample-values(20, invalid) }).is-empty)
  val available = [Weighted-sample(1, [], empty(), neginf), Weighted-sample(2, [], empty(), ~10000.0)]
  ensure("zero mass is never selected", pseudo-random(607, fn(){ resample-values(100, available) }).all(fn(value){ value == 2 }))
  ensure("log evidence retains very small likelihoods", near(log-mean-weight([~10000.0, ~10000.0]), ~10000.0))

val outer-observation = obs-bool("regression/outer")
val inner-observation = obs-bool("regression/inner")

fun test-nested-inference() : <div,exn,random> ()
  val environment = set(outer-observation, [True, False], empty())
  val outer-model = fn(){
    val first = bernoulli(outer-observation, 0.6)
    val nested = run-lw(set(inner-observation, [True], empty()), fn(){ bernoulli(inner-observation, 0.2) })
    val second = bernoulli(outer-observation, 0.3)
    (first, nested.log-weight, second)
  }
  val outer = pseudo-random(609, fn(){ run-lw(environment, outer-model) })
  ensure("nested LW preserves the outer trace", outer.trace.length == 2)
  ensure("nested LW preserves outer address order", outer.trace.map(fn(entry){ entry.address }) == [0, 1])
  ensure("nested LW cannot reset or add to outer weight", near(outer.log-weight, ln(0.6) + ln(0.7)))
  val simulation-model = fn(){
    val first = bernoulli'(0.6)
    val nested = simulate(empty(), fn(){ bernoulli'(0.2) })
    val second = bernoulli'(0.3)
    (first, nested.value, second)
  }
  val simulation = pseudo-random(611, fn(){ simulate(empty(), simulation-model) })
  ensure("nested simulation preserves the outer trace", sampled-addresses(simulation.trace) == [0, 1])

fun test-mh-prior-cancellation() : <div,exn,random> ()
  val result = pseudo-random(613, fn(){ mh(12000, 1000, empty(), fn(){ bernoulli'(0.8) }) })
  val frequency = float64(result.samples.filter(fn(sample){ sample.value }).length) / float64(result.samples.length)
  ensure("unobserved MH must preserve Bernoulli(0.8), not square its prior", near(frequency, 0.8, 0.025))
  val branching-model = fn(){
    val flag = bernoulli'(0.8)
    if flag
      then
        val extra = bernoulli'(0.4)
        (flag, extra)
      else (flag, False)
  }
  val branching = pseudo-random(617, fn(){ mh(16000, 1000, empty(), branching-model) })
  val branch-frequency = float64(branching.samples.filter(fn(sample){ fst(sample.value) }).length) / float64(branching.samples.length)
  ensure("variable-length MH retains the site-selection correction", near(branch-frequency, 0.8, 0.025))
  val impossible = pseudo-random(619, fn(){ mh(30, 0, set(outer-observation, [True], empty()), fn(){ bernoulli(outer-observation, 0.0) }) })
  ensure("MH must not retain states with impossible observations", impossible.samples.is-empty)

fun test-large-poisson() : <div,exn,random> ()
  val values = pseudo-random(621, fn(){ lw(1200, empty(), fn(){ poisson'(1000.0) }) })
  val mean = values.foldl(0.0, fn(acc, item){ acc + float64(item.value) }) / float64(values.length)
  ensure("large Poisson sampler must not stop near floating-point underflow", near(mean, 1000.0, 5.0))

fun test-small-distribution-parameters() : <div,exn,random> ()
  val tiny = pseudo-random(631, fn(){ lw(100, empty(), fn(){ poisson'(1.0e-20) }) })
  ensure("a tiny positive Poisson rate must not produce negative counts", tiny.all(fn(item){ item.value >= 0 }))
  [633, 635, 637].foreach fn(seed){
    val values = pseudo-random(seed, fn(){ lw(2000, empty(), fn(){ beta'(0.001, 0.002) }) })
    ensure("small-shape Beta draws must remain finite and within support",
      values.all(fn(item){ is-finite(item.value) && item.value >= 0.0 && item.value <= 1.0 }))
    val mean = values.foldl(0.0, fn(acc, item){ acc + item.value }) / float64(values.length)
    val second = values.foldl(0.0, fn(acc, item){ acc + item.value * item.value }) / float64(values.length)
    ensure("small-shape Beta mean agrees with alpha/(alpha+beta)", near(mean, 1.0 / 3.0, 0.04))
    ensure("small-shape Beta second moment agrees with the analytic answer", near(second, (1.001 / 1.003) / 3.0, 0.04))
  }

fun prior-observation-model() : sequential-model<e,bool,int,bool,bool>
  Sequential-model(
    fn(){
      val parameter = bernoulli'(0.5)
      val observed = bernoulli(outer-observation, if parameter then 0.9 else 0.1)
      parameter
    },
    fn(_parameter){ 0 },
    fn(parameter, _index, state){ Step-output(state, parameter) },
    fn(prefix-state){ prefix-state.parameter })

fun test-prior-observations() : <div,exn,random> ()
  val environment = set(outer-observation, [True], empty())
  val population = pseudo-random(623, fn(){ rmsmc(3000, 0, 0, environment, prior-observation-model()) })
  val probability = float64(population.particles.filter(fn(item){ item.value }).length) / float64(population.particles.length)
  ensure("RMSMC scores observations in the parameter prior", near(probability, 0.9, 0.04))
  ensure("RMSMC initial evidence includes prior observations", near(exp(population.log-evidence), 0.5, 0.025))
  val chain = pseudo-random(625, fn(){ pmmh(2, 0, default-config(10000, 1000), environment, prior-observation-model()) })
  val frequency = float64(chain.samples.filter(fn(item){ item.parameter }).length) / float64(chain.samples.length)
  ensure("PMMH scores observations in the parameter prior", near(frequency, 0.9, 0.035))
  val nested = pseudo-random(627, fn(){ smc2(2000, 2, 2, 2, environment, prior-observation-model()) })
  val nested-frequency = float64(nested.particles.filter(fn(item){ item.parameter }).length) / float64(nested.particles.length)
  ensure("SMC2 retains prior observations through rejuvenation", near(nested-frequency, 0.9, 0.04))
  ensure("SMC2 evidence includes prior observations", near(exp(nested.log-evidence), 0.5, 0.035))
  val custom-score = fn(parameter){ ln(0.5) + ln(if parameter then 0.9 else 0.1) }
  val custom-kernel : bool -> (bool,env,float64) = fn(parameter){ (not(parameter), empty(), 0.0) }
  val custom = pseudo-random(629, fn(){ smc2-with(2000, 2, 2, 2, environment, prior-observation-model(), custom-score, custom-kernel) })
  val custom-frequency = float64(custom.particles.filter(fn(item){ item.parameter }).length) / float64(custom.particles.length)
  ensure("custom SMC2 scores and kernel preserve the posterior", near(custom-frequency, 0.9, 0.04))
  ensure("custom SMC2 initial proposal density is corrected", near(exp(custom.log-evidence), 0.5, 0.035))

pub fun main() : <console,div,exn,random> ()
  test-distribution-support()
  test-weight-collapse()
  test-nested-inference()
  test-mh-prior-cancellation()
  test-large-poisson()
  test-small-distribution-parameters()
  test-prior-observations()
  println("inference regression checks passed")
