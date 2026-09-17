module gradient_examples

import std/num/float64
import autodiff/smooth
import alg/gradient
import alg/hmc
import alg/mala
import alg/mcmc

// Three Bayesian models, two samplers and three fixed seeds = 18 posterior runs.
// The oracle construction, budgets and tolerances are fixed before sampling.
val seeds = [1201, 1213, 1217]
val hmc-iterations = 8000
val hmc-burnin = 1000
val mala-iterations = 14000
val mala-burnin = 2000
val mean-sd-tolerance = 0.10
val variance-relative-tolerance = 0.12
val correlation-scale-tolerance = 0.10
val predictive-tolerance = 0.012

val thermometer-data = [19.0, 21.0, 22.0]
val regression-data = [(~1.0, ~1.0), (0.0, 1.0), (1.0, 2.0), (2.0, 3.0)]

struct oracle
  means : list<float64>
  variances : list<float64>
  covariance : float64
  predictive : maybe<float64>

fun ensure(label : string, condition : bool) : exn ()
  if not(condition) then throw(label)

fun close(label : string, actual : float64, expected : float64, tolerance : float64 = 1.0e-10) : exn ()
  ensure(label ++ ": expected " ++ expected.show ++ ", got " ++ actual.show,
    is-finite(actual) && abs(actual - expected) <= tolerance)

fun coordinate(values : list<float64>, index : int) : float64
  match values
    Nil -> nan
    Cons(value, rest) -> if index == 0 then value else coordinate(rest, index - 1)

// A Normal(20,2) prior and three independent Normal(theta,1) readings.
fun thermometer-target(xs : list<a>) : smooth<a> a
  match xs
    Cons(theta, Nil) ->
      thermometer-data.foldl(ad-normal-log-density(theta, ad-constant(20.0), ad-constant(2.0)), fn(total, reading){
        ad-add(total, ad-normal-log-density(ad-constant(reading), theta, ad-constant(1.0)))
      })
    _ -> ad-constant(nan)

fun thermometer-oracle() : oracle
  val precision = 0.25 + float64(thermometer-data.length)
  val mean = (5.0 + thermometer-data.foldl(0.0, fn(total, reading){ total + reading })) / precision
  Oracle([mean], [1.0 / precision], 0.0, Nothing)

// y_i = intercept + slope*x_i + Normal(0,1), with independent priors
// intercept ~ Normal(0,2), slope ~ Normal(0,1.5). The noncentered design
// makes the posterior coefficients correlated.
fun regression-target(xs : list<a>) : smooth<a> a
  match xs
    Cons(intercept, Cons(slope, Nil)) ->
      val prior = ad-add(
        ad-normal-log-density(intercept, ad-constant(0.0), ad-constant(2.0)),
        ad-normal-log-density(slope, ad-constant(0.0), ad-constant(1.5)))
      regression-data.foldl(prior, fn(total, datum){
        val fitted = ad-add(intercept, ad-mul(slope, ad-constant(fst(datum))))
        ad-add(total, ad-normal-log-density(ad-constant(snd(datum)), fitted, ad-constant(1.0)))
      })
    _ -> ad-constant(nan)

// Independently invert Q = prior_precision + X'X, then compute Q^-1 X'y.
fun regression-oracle() : oracle
  val q00 = 0.25 + float64(regression-data.length)
  val q01 = regression-data.foldl(0.0, fn(total, xy){ total + fst(xy) })
  val q11 = 1.0 / 2.25 + regression-data.foldl(0.0, fn(total, xy){ total + fst(xy) * fst(xy) })
  val rhs0 = regression-data.foldl(0.0, fn(total, xy){ total + snd(xy) })
  val rhs1 = regression-data.foldl(0.0, fn(total, xy){ total + fst(xy) * snd(xy) })
  val determinant = q00 * q11 - q01 * q01
  Oracle([(q11 * rhs0 - q01 * rhs1) / determinant,
          (q00 * rhs1 - q01 * rhs0) / determinant],
         [q11 / determinant, q00 / determinant], ~q01 / determinant, Nothing)

// Nine successes and one failure with logistic probability sigmoid(intercept),
// and intercept ~ Normal(0,2). This posterior is not Gaussian.
fun logistic-target(xs : list<a>) : smooth<a> a
  match xs
    Cons(intercept, Nil) ->
      val prior = ad-normal-log-density(intercept, ad-constant(0.0), ad-constant(2.0))
      val successes = ad-mul(ad-constant(9.0), intercept)
      val trials = ad-mul(ad-constant(10.0), ad-log(ad-add(ad-constant(1.0), ad-exp(intercept))))
      ad-add(prior, ad-sub(successes, trials))
    _ -> ad-constant(nan)

fun sigmoid(x : float64) : float64
  if x >= 0.0 then 1.0 / (1.0 + exp(~x)) else exp(x) / (1.0 + exp(x))

// Ordinary floating arithmetic, separate from AD and both samplers. Stable
// log-sigmoid identities avoid cancellation in the quadrature's far tails.
fun logistic-log-density(x : float64) : float64
  val log-probability = if x >= 0.0 then ~ln(1.0 + exp(~x)) else x - ln(1.0 + exp(x))
  val log-failure = if x >= 0.0 then ~x - ln(1.0 + exp(~x)) else ~ln(1.0 + exp(x))
  ~x * x / 8.0 + 9.0 * log-probability + log-failure

// Composite Simpson integration. Its common dx/3 factor cancels from ratios.
fun logistic-quadrature(bound : float64, intervals : int) : oracle
  var mass := 0.0
  var first := 0.0
  var second := 0.0
  var predictive := 0.0
  val spacing = 2.0 * bound / float64(intervals)
  for(intervals + 1) fn(index){
    val x = ~bound + float64(index) * spacing
    val simpson = if index == 0 || index == intervals then 1.0 elif is-odd(index) then 4.0 else 2.0
    val weight = simpson * exp(logistic-log-density(x))
    mass := mass + weight
    first := first + weight * x
    second := second + weight * x * x
    predictive := predictive + weight * sigmoid(x)
  }
  val mean = first / mass
  Oracle([mean], [second / mass - mean * mean], 0.0, Just(predictive / mass))

fun predictive-value(value : oracle) : float64
  match value.predictive
    Just(probability) -> probability
    Nothing -> nan

fun checked-logistic-oracle() : <console,exn> oracle
  val coarse = logistic-quadrature(12.0, 2400)
  val refined = logistic-quadrature(12.0, 4800)
  val expanded = logistic-quadrature(16.0, 6400)
  [coarse, refined].foreach fn(reference){
    close("quadrature mean survives refinement/domain expansion", coordinate(reference.means, 0), coordinate(expanded.means, 0), 1.0e-8)
    close("quadrature variance survives refinement/domain expansion", coordinate(reference.variances, 0), coordinate(expanded.variances, 0), 1.0e-8)
    close("quadrature predictive mean survives refinement/domain expansion", predictive-value(reference), predictive-value(expanded), 1.0e-8)
  }
  ensure("logistic quadrature has a finite positive variance", coordinate(expanded.variances, 0) > 0.0 && is-finite(coordinate(expanded.variances, 0)))
  println("gradient oracle logistic: mean=" ++ coordinate(expanded.means, 0).show
    ++ ", variance=" ++ coordinate(expanded.variances, 0).show
    ++ ", predictive=" ++ predictive-value(expanded).show
    ++ "; grid and domain checks <=1e-8")
  expanded

fun test-density-gradients() : <div,exn> ()
  val temperature = initial-target(thermometer-target, [20.25])
  val thermal-gradient = ~(20.25 - 20.0) / 4.0 + thermometer-data.foldl(0.0, fn(total, y){ total + y - 20.25 })
  close("thermometer analytic gradient", coordinate(temperature.gradient, 0), thermal-gradient)
  val coefficients = initial-target(regression-target, [0.5, 1.0])
  val intercept-gradient = ~0.5 / 4.0 + regression-data.foldl(0.0, fn(total, xy){ total + snd(xy) - 0.5 - fst(xy) })
  val slope-gradient = ~1.0 / 2.25 + regression-data.foldl(0.0, fn(total, xy){ total + fst(xy) * (snd(xy) - 0.5 - fst(xy)) })
  close("regression intercept analytic gradient", coordinate(coefficients.gradient, 0), intercept-gradient)
  close("regression slope analytic gradient", coordinate(coefficients.gradient, 1), slope-gradient)
  [~2.0, 0.0, 2.0].foreach fn(x){
    val state = initial-target(logistic-target, [x])
    close("logistic density matches independent probability calculation", state.log-density,
      logistic-log-density(x) - ln(2.0) - 0.5 * ln(2.0 * pi))
    close("logistic analytic gradient", coordinate(state.gradient, 0), ~x / 4.0 + 9.0 - 10.0 * sigmoid(x))
  }

fun empirical-mean(samples : list<list<float64>>, index : int) : float64
  samples.foldl(0.0, fn(total, point){ total + coordinate(point, index) }) / float64(samples.length)

// Center about the oracle mean, not an estimated sample mean: each check has
// an independent target and a bias in the mean cannot hide inside centering.
fun empirical-moment(samples : list<list<float64>>, means : list<float64>, left : int, right : int) : float64
  samples.foldl(0.0, fn(total, point){
    total + (coordinate(point, left) - coordinate(means, left))
          * (coordinate(point, right) - coordinate(means, right))
  }) / float64(samples.length)

fun check-posterior(model-name : string, algorithm : string, seed : int,
                     result : mcmc-result<list<float64>>, reference : oracle,
                     iterations : int, retained : int) : console bool
  val valid = result.samples.length == retained && result.accepted > 0 && result.accepted < iterations
    && result.samples.all(fn(point){ point.length == reference.means.length && point.all(is-finite) })
  var mean-error := 0.0
  var variance-error := 0.0
  for(reference.means.length) fn(index){
    val variance = coordinate(reference.variances, index)
    mean-error := max(mean-error, abs(empirical-mean(result.samples, index) - coordinate(reference.means, index)) / sqrt(variance))
    variance-error := max(variance-error, abs(empirical-moment(result.samples, reference.means, index, index) - variance) / variance)
  }
  val covariance-error =
    if reference.means.length == 2
      then abs(empirical-moment(result.samples, reference.means, 0, 1) - reference.covariance)
        / sqrt(coordinate(reference.variances, 0) * coordinate(reference.variances, 1))
      else 0.0
  val predictive-error = match reference.predictive
    Nothing -> 0.0
    Just(expected) ->
      abs(result.samples.foldl(0.0, fn(total, point){ total + sigmoid(coordinate(point, 0)) }) / float64(result.samples.length) - expected)
  val ratio =
    if valid
      then max(max(mean-error / mean-sd-tolerance, variance-error / variance-relative-tolerance),
               max(covariance-error / correlation-scale-tolerance, predictive-error / predictive-tolerance))
      else posinf
  val passed = valid && is-finite(ratio) && ratio <= 1.0
  println("gradient metrics " ++ model-name ++ "/" ++ algorithm ++ "/" ++ seed.show
    ++ ": standardized-mean=" ++ mean-error.show ++ ", relative-second-moment=" ++ variance-error.show
    ++ ", standardized-cross-moment=" ++ covariance-error.show ++ ", predictive=" ++ predictive-error.show
    ++ ", acceptance=" ++ (float64(result.accepted) / float64(iterations)).show)
  println("example,gradient," ++ model-name ++ "," ++ algorithm ++ "," ++ seed.show
    ++ "," ++ ratio.show ++ "," ++ (if passed then "PASS" else "FAIL"))
  passed

fun run-example(name : string, target : forall<a> list<a> -> smooth<a> a,
                  initial : list<float64>, reference : oracle,
                  hmc-step : float64, hmc-steps : int, mala-step : float64) : <console,div,exn> bool
  var passed := True
  seeds.foreach fn(seed){
    val hmc-result = hmc(default-config(hmc-iterations, hmc-burnin), target, initial, hmc-step, hmc-steps, seed)
    val hmc-passed = check-posterior(name, "HMC", seed, hmc-result, reference, hmc-iterations, hmc-iterations - hmc-burnin)
    val mala-result = mala(default-config(mala-iterations, mala-burnin), target, initial, mala-step, seed)
    val mala-passed = check-posterior(name, "MALA", seed, mala-result, reference, mala-iterations, mala-iterations - mala-burnin)
    passed := (passed && hmc-passed && mala-passed)
  }
  passed

pub fun main() : <console,div,exn> ()
  test-density-gradients()
  val logistic = checked-logistic-oracle()
  println("Gradient example budgets: HMC 8000/1000 burnin; MALA 14000/2000 burnin; seeds 1201,1213,1217")
  println("Gradient tolerances: mean 0.10 posterior SD; centered second moment 0.12 variance; cross moment 0.10 SD product; predictive 0.012")
  val thermometer = run-example("thermometer", thermometer-target, [20.0], thermometer-oracle(), 0.20, 4, 0.70)
  val regression = run-example("linear-regression", regression-target, [0.0, 0.0], regression-oracle(), 0.16, 4, 0.55)
  val logistic-passed = run-example("logistic-intercept", logistic-target, [0.0], logistic, 0.30, 4, 1.0)
  ensure("Gradient example matrix failed; see emitted FAIL rows and fixed tolerances.", thermometer && regression && logistic-passed)
  println("Gradient example matrix passed (18 runs).")
