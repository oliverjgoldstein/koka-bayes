module model_api

import bayes

fun ensure(message : string, condition : bool) : exn ()
  if condition then () else throw(message)

fun fails(action : () -> <exn|e> a) : e bool
  try(fn(){ val result = action(); False }, fn(_exception){ True })

val flip = obs-bool("model-api/flip")

fun coin(count : int) : model<e,float64>
  fn(){
    val p = beta'(2.0, 3.0)
    for(count) fn(_){ val _ = bernoulli(flip, p); () }
    p
  }

fun test-method-switching() : <div,exn> ()
  val flips = [True, True, True, False]
  val observations = singleton(flip, flips)
  val exact-mean = 5.0 / 9.0
  val weighted = likelihood-weighting(2000, observations, coin(flips.length))
  val resampled = likelihood-weighting-resampled(1000, observations, coin(flips.length))
  val chain = metropolis-hastings(3000, 500, observations, coin(flips.length))
  ensure("LW mean matches the conjugate posterior", abs(posterior-mean(weighted) - exact-mean) <= 0.05)
  ensure("LWIS mean matches the conjugate posterior", abs(posterior-mean(resampled) - exact-mean) <= 0.05)
  ensure("MH mean matches the conjugate posterior", abs(posterior-mean(chain) - exact-mean) <= 0.05)
  ensure("MH budget includes burn-in", chain.samples.length == 2500)
  val repeat = likelihood-weighting(2000, observations, coin(flips.length))
  ensure("Default seeds reproduce the same population", weighted.map(fn(x){ x.value }) == repeat.map(fn(x){ x.value }))

fun test-observation-count() : <div,exn> ()
  val flips = [False, False, False, False, False, False]
  val weighted = likelihood-weighting(2000, singleton(flip, flips), coin(flips.length))
  ensure("Every provided observation changes the posterior", abs(posterior-mean(weighted) - (2.0 / 11.0)) <= 0.04)
  val prior = likelihood-weighting(2000, empty(), coin(0))
  ensure("An empty data set leaves the prior", abs(posterior-mean(prior) - 0.4) <= 0.04)

fun test-summary-weighting() : exn ()
  val weighted = [Weighted-sample(0.0, [], empty(), ln(0.25)), Weighted-sample(1.0, [], empty(), ln(0.75))]
  ensure("LW summary uses normalized weights", abs(posterior-mean(weighted) - 0.75) < 1.0e-12)
  ensure("Ordinary draws are equally weighted", posterior-mean([0.0, 1.0]) == 0.5)
  ensure("A finite mean does not overflow when summing large draws", posterior-mean([1.0e308, 1.0e308]) == 1.0e308)
  val zero-mass = [Weighted-sample(nan, [], empty(), neginf), Weighted-sample(2.0, [], empty(), ~10000.0)]
  ensure("Zero mass contributes nothing, including a nonfinite value", posterior-mean(zero-mass) == 2.0)
  val no-weighted : list<weighted-sample<float64>> = []
  val no-draws : list<float64> = []
  ensure("An empty weighted population has no mean", fails(fn(){ posterior-mean(no-weighted) }))
  ensure("An empty resampled population has no mean", fails(fn(){ posterior-mean(no-draws) }))
  ensure("An impossible population has no mean", fails(fn(){ posterior-mean([Weighted-sample(1.0, [], empty(), neginf)]) }))
  ensure("Nonfinite sample means fail clearly", fails(fn(){ posterior-mean([nan]) }))

fun test-invalid-budgets() : <div,exn> ()
  ensure("LW rejects an empty budget", fails(fn(){ likelihood-weighting(0, empty(), coin(0)) }))
  ensure("LWIS rejects an empty budget", fails(fn(){ likelihood-weighting-resampled(0, empty(), coin(0)) }))
  ensure("MH rejects a chain with no retained draws", fails(fn(){ metropolis-hastings(10, 10, empty(), coin(0)) }))
  ensure("MH rejects negative burn-in", fails(fn(){ metropolis-hastings(10, ~1, empty(), coin(0)) }))

pub fun main() : <console,div,exn> ()
  test-method-switching()
  test-observation-count()
  test-summary-weighting()
  test-invalid-budgets()
  println("Model API tests passed.")
