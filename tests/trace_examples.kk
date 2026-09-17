module trace_examples

import std/num/float64
import std/num/random
import alg/lw
import alg/lwis
import alg/mh
import alg/simulate
import core/env
import core/model
import core/obsvar

val count-data = obs-int("examples/count")
val mixture-data = obs-float64("examples/mixture")
val seeds = [1301, 1303, 1307]

struct reference
  mean : float64
  variance : float64
  cdf-points : list<(float64,float64)>
  evidence : float64

struct tolerance
  mean : float64
  variance : float64
  cdf : float64
  evidence-relative : float64

struct mass
  value : float64
  weight : float64

fun ensure(label : string, condition : bool) : exn ()
  if not(condition) then throw(label)

fun beta-binomial() : <model-dist> float64
  val probability = beta'(2.0, 3.0)
  val first = binomial(count-data, 5, probability)
  val second = binomial(count-data, 5, probability)
  probability

fun gamma-poisson() : <model-dist> float64
  val rate = gamma'(2.0, 1.5)
  val first = poisson(count-data, rate)
  val second = poisson(count-data, rate)
  val third = poisson(count-data, rate)
  rate

fun finite-mixture() : <model-dist> float64
  val component = discrete'([0.2, 0.5, 0.3])
  val center = if component == 0 then ~1.0 else if component == 1 then 0.5 else 2.0
  val first = normal(mixture-data, center, 1.2)
  val second = normal(mixture-data, center, 1.2)
  float64(component)

// For integer shape, the Gamma CDF is a finite Poisson sum. This oracle uses
// ordinary arithmetic, not the distribution scorer or any inference routine.
fun gamma-cdf(shape : int, rate : float64, cutoff : float64) : float64
  val x = rate * cutoff
  var term := 1.0
  var sum := 1.0
  list(1, shape - 1).foreach fn(k){
    term := term * x / float64(k)
    sum := sum + term
  }
  1.0 - exp(~x) * sum

fun mixture-reference() : reference
  val masses = [(0.0, 0.2, ~1.0), (1.0, 0.5, 0.5), (2.0, 0.3, 2.0)].map fn(item){
    val (component, prior, center) = item
    val squared = (0.4 - center)*(0.4 - center) + (1.2 - center)*(1.2 - center)
    Mass(component, prior * exp(~squared / (2.0 * 1.44)) / (2.0 * pi * 1.44))
  }
  val z = masses.foldl(0.0, fn(acc, item){ acc + item.weight })
  val mean = masses.foldl(0.0, fn(acc, item){ acc + item.value * item.weight }) / z
  val variance = masses.foldl(0.0, fn(acc, item){ acc + (item.value - mean)*(item.value - mean)*item.weight }) / z
  val cdf = masses.foldl(0.0, fn(acc, item){ acc + (if item.value == 0.0 then item.weight else 0.0) }) / z
  val second-cdf = masses.foldl(0.0, fn(acc, item){ acc + (if item.value <= 1.0 then item.weight else 0.0) }) / z
  Reference(mean, variance, [(0.5, cdf), (1.5, second-cdf)], z)

fun equal-mass(values : list<float64>) : list<mass>
  values.map(fn(value){ Mass(value, 1.0) })

fun check(label : string, algorithm : string, seed : int, values : list<mass>,
            truth : reference, bounds : tolerance, estimate-evidence : maybe<float64> = Nothing) : <console,exn> ()
  ensure(label ++ " " ++ algorithm ++ ": no samples", not(values.is-empty))
  ensure(label ++ " " ++ algorithm ++ ": invalid sample or weight",
    values.all(fn(item){ is-finite(item.value) && is-finite(item.weight) && item.weight >= 0.0 }))
  val total = values.foldl(0.0, fn(acc, item){ acc + item.weight })
  ensure(label ++ ": no finite positive mass", is-finite(total) && total > 0.0)
  val actual-mean = values.foldl(0.0, fn(acc, item){ acc + item.value * item.weight }) / total
  val actual-variance = values.foldl(0.0, fn(acc, item){ acc + (item.value - actual-mean)*(item.value - actual-mean)*item.weight }) / total
  val cdf-errors = truth.cdf-points.map fn(point){
    val actual = values.foldl(0.0, fn(acc, item){ acc + (if item.value <= fst(point) then item.weight else 0.0) }) / total
    abs(actual - snd(point))
  }
  val evidence-error = match estimate-evidence
    Nothing -> 0.0
    Just(z) -> abs(z / truth.evidence - 1.0)
  val ratios = [abs(actual-mean - truth.mean) / bounds.mean, abs(actual-variance - truth.variance) / bounds.variance,
                 cdf-errors.foldl(0.0, max) / bounds.cdf, evidence-error / bounds.evidence-relative]
  val maximum = ratios.foldl(0.0, max)
  val ok = ratios.all(fn(ratio){ is-finite(ratio) && ratio <= 1.0 })
  println("example,trace," ++ label ++ "," ++ algorithm ++ "," ++ seed.show ++ "," ++ maximum.show ++ "," ++ (if ok then "PASS" else "FAIL"))
  println("  mean=" ++ actual-mean.show ++ "; variance=" ++ actual-variance.show ++ "; cdf errors=" ++ cdf-errors.show ++ "; relative evidence error=" ++ evidence-error.show)
  ensure(label ++ " " ++ algorithm ++ " seed " ++ seed.show ++ ": posterior or prior disagrees with independent oracle", ok)

fun run-example(label : string, environment : env, action : model<total,float64>,
                  posterior : reference, prior : reference,
                  posterior-bounds : tolerance, prior-bounds : tolerance) : <console,div,exn> ()
  seeds.foreach fn(seed){
    // Simulation deliberately clamps observations without conditioning the prior.
    val generated = pseudo-random(seed, fn(){ list(1, 6000).map(fn(_){ simulate(environment, action).value }) })
    check(label, "simulate", seed, equal-mass(generated), prior, prior-bounds)
    val weighted = pseudo-random(seed, fn(){ lw(6000, environment, action) })
    val masses = weighted.map(fn(item){ Mass(item.value, exp(item.log-weight)) })
    val evidence = masses.foldl(0.0, fn(acc, item){ acc + item.weight }) / float64(masses.length)
    check(label, "LW", seed, masses, posterior, posterior-bounds, Just(evidence))
    val resampled = pseudo-random(seed, fn(){ lwis(6000, environment, action) })
    ensure(label ++ ": LWIS sample count", resampled.length == 6000)
    check(label, "LWIS", seed, equal-mass(resampled), posterior, posterior-bounds)
    val chain = pseudo-random(seed, fn(){ mh(14000, 2000, environment, action) })
    ensure(label ++ ": MH retains all post-burnin states", chain.samples.length == 12000)
    ensure(label ++ ": MH exercises acceptance and rejection", chain.accepted > 0 && chain.accepted < 14000)
    check(label, "MH", seed, equal-mass(chain.samples.map(fn(item){ item.value })), posterior, posterior-bounds)
  }

pub fun main() : <console,div,exn> ()
  // Fixed budgets, seeds and tolerances declared before executing the matrix.
  // Beta(2,3), Binomial(5) data [4,2] gives Beta(8,7).
  // The evidence includes both binomial coefficients: 50*B(8,7)/B(2,3)=25/1001.
  // The CDF at 1/2 is sum_{k=8}^{14} choose(14,k)/2^14 = 6476/16384.
  run-example("beta-binomial", singleton(count-data, [4, 2]), beta-binomial,
    Reference(8.0/15.0, 56.0/3600.0, [(0.25, 0.010309532284736633), (0.5, 6476.0/16384.0), (0.75, 0.9617292433977127)], 25.0/1001.0),
    Reference(0.4, 0.04, [(0.25, 0.26171875), (0.5, 0.6875), (0.75, 0.94921875)], 1.0),
    Tolerance(0.02, 0.0025, 0.045, 0.10), Tolerance(0.025, 0.008, 0.035, 1.0))
  // Gamma(shape=2, rate=2/3), Poisson data [1,4,2] gives Gamma(9,11/3).
  // Evidence is (2/3)^2 * 8! / ((11/3)^9 * 1!4!2!), independently rationalized.
  run-example("gamma-poisson", singleton(count-data, [1, 4, 2]), gamma-poisson,
    Reference(27.0/11.0, 81.0/121.0, [1.0,2.0,3.0,4.0].map(fn(x){ (x, gamma-cdf(9, 11.0/3.0, x)) }), 7348320.0/2357947691.0),
    Reference(3.0, 4.5, [1.0,2.0,3.0,4.0].map(fn(x){ (x, gamma-cdf(2, 2.0/3.0, x)) }), 1.0),
    Tolerance(0.09, 0.12, 0.045, 0.10), Tolerance(0.10, 0.50, 0.035, 1.0))
  run-example("finite-mixture", singleton(mixture-data, [0.4, 1.2]), finite-mixture,
    mixture-reference(), Reference(1.1, 0.49, [(0.5, 0.2), (1.5, 0.7)], 1.0),
    Tolerance(0.065, 0.055, 0.035, 0.10), Tolerance(0.06, 0.05, 0.035, 1.0))
  println("Trace example matrix passed (36 runs).")
