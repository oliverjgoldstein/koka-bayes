module examples/gradient_inference

import bayes
import autodiff/smooth
import autodiff/model
import alg/mcmc
import alg/hmc
import alg/mala
import examples/inference

// The same model body supports ordinary probabilistic execution and AD.
// Its four latent coordinates are [average, actual1, actual2, actual3].
pub fun temperature-program() : <continuous<a>,smooth<a>> a
  val average = normal-latent(ad-constant(inference/prior-mean),
    ad-constant(inference/prior-stddev))
  inference/readings.foreach fn(_){
    val actual = normal-latent(average, ad-constant(inference/fluctuation-stddev))
    val observed = normal-observed(inference/thermometer.name, actual,
      ad-constant(inference/reading-stddev))
    ()
  }
  average

// The density handler binds latent sites to the supplied coordinates and
// accumulates their prior and observation scores using smooth arithmetic.
pub fun temperature-log-joint(xs : list<a>) : smooth<a> a
  log-joint(temperature-program, xs, inference/observations())

fun average-coordinate(position : list<float64>) : exn float64
  match position
    Cons(average, _) -> average
    Nil -> throw("Expected the average temperature as the first latent coordinate.")

fun report(name : string, result : mcmc-result<list<float64>>, iterations : int) : <console,exn> ()
  val averages = result.samples.map(average-coordinate)
  val mean = posterior-mean(averages)
  val variance = averages.foldl(0.0, fn(total, average){
    val difference = average - mean
    total + difference * difference
  }) / float64(averages.length)
  val (exact-mean, exact-variance) = inference/exact-posterior()
  println(name)
  println("  posterior mean: " ++ mean.show ++ "; exact: " ++ exact-mean.show)
  println("  posterior standard deviation: " ++ sqrt(variance).show
    ++ "; exact: " ++ sqrt(exact-variance).show)
  println("  retained samples: " ++ averages.length.show)
  println("  acceptance fraction (including burnin): "
    ++ (float64(result.accepted) / float64(iterations)).show)

pub fun run-hmc() : <console,div,exn> ()
  val result = hmc(default-config(4500, 500), temperature-log-joint,
    [20.0, 20.0, 20.0, 20.0], 0.15, 10, seed=8108)
  report("HMC: use AD gradients along a leapfrog trajectory", result, 4500)

pub fun run-mala() : <console,div,exn> ()
  val result = mala(default-config(10000, 2000), temperature-log-joint,
    [20.0, 20.0, 20.0, 20.0], 0.35, seed=8109)
  report("MALA: use AD gradients in a corrected Gaussian proposal", result, 10000)

pub fun run-probabilistic() : <console,div,exn> ()
  val draws = likelihood-weighting(4000, inference/observations(),
    probabilistic(temperature-program), seed=8110)
  val (exact-mean, _) = inference/exact-posterior()
  println("The same model body under the ordinary probabilistic handler (LW)")
  println("  posterior mean: " ++ posterior-mean(draws).show ++ "; exact: " ++ exact-mean.show)

pub fun main() : <console,div,exn> ()
  println("One thermometer program, interpreted as a sampler or a differentiable density")
  println("Readings: " ++ inference/readings.show ++ " degrees C")
  run-probabilistic()
  run-hmc()
  run-mala()
  println("Gradient inference examples completed.")
