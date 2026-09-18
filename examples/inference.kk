module examples/inference

import bayes
import std/num/random
import alg/mcmc
import alg/simulate
import alg/smc
import alg/rmsmc
import alg/pmmh
import alg/smc2
import core/sequential
import core/weights

// We want the room's average temperature. Each reading includes both a small
// real fluctuation in temperature and independent thermometer noise.
pub val readings = [19.0, 21.0, 22.0]
pub val thermometer = obs-float64("temperature/readings")
pub val prior-mean = 20.0
pub val prior-stddev = 2.0
pub val fluctuation-stddev = 0.5
pub val reading-stddev = 1.0

// The parameter is the average; the state is the actual temperature at a
// particular reading. All seven algorithms below use this one model.
pub fun temperature-model() : sequential-model<e,float64,float64,float64,float64>
  Sequential-model(
    fn(){ normal'(prior-mean, prior-stddev) },
    fn(average){ average },
    fn(average, _index, _previous){
      val actual = normal'(average, fluctuation-stddev)
      Step-output(actual, normal(thermometer, actual, reading-stddev))
    },
    fn(result){ result.parameter })

pub fun observations() : env
  singleton(thermometer, readings)

// Integrating out each fluctuation adds its variance to the sensor variance.
// The normal-normal posterior then gives an independent analytic reference.
pub fun exact-posterior() : (float64,float64)
  val observation-variance = fluctuation-stddev * fluctuation-stddev
    + reading-stddev * reading-stddev
  val prior-precision = 1.0 / (prior-stddev * prior-stddev)
  val reading-precision = 1.0 / observation-variance
  val variance = 1.0 / (prior-precision + float64(readings.length) * reading-precision)
  val mean = variance * (prior-mean * prior-precision
    + readings.foldl(0.0, fn(total, reading){ total + reading }) * reading-precision)
  (mean, variance)

fun report(name : string, mean : float64, variance : float64) : console ()
  val (exact-mean, exact-variance) = exact-posterior()
  println(name)
  println("  posterior mean: " ++ mean.show ++ "; exact: " ++ exact-mean.show)
  println("  posterior standard deviation: " ++ sqrt(variance).show
    ++ "; exact: " ++ sqrt(exact-variance).show)

fun report-draws(name : string, values : list<float64>) : <console,exn> ()
  val mean = posterior-mean(values)
  val variance = values.foldl(0.0, fn(total, value){
    val difference = value - mean
    total + difference * difference
  }) / float64(values.length)
  report(name, mean, variance)

pub fun run-lw() : <console,div,exn> ()
  val draws = likelihood-weighting(4000, observations(),
    as-model(readings.length, temperature-model()), seed=8101)
  val mean = posterior-mean(draws)
  val weights = normalized-log-weights(draws.map(fn(draw){ draw.log-weight }))
  val variance = match weights
    Nothing -> throw("The temperature example has no posterior mass.")
    Just(values) -> zip(draws, values).foldl(0.0, fn(total, item){
      val (draw, weight) = item
      val difference = draw.value - mean
      total + weight * difference * difference
    })
  report("LW: weight independent prior simulations by their likelihood", mean, variance)

pub fun run-lwis() : <console,div,exn> ()
  val draws = likelihood-weighting-resampled(4000, observations(),
    as-model(readings.length, temperature-model()), seed=8102)
  report-draws("LWIS: resample the weighted simulations", draws)

pub fun run-mh() : <console,div,exn> ()
  val result = metropolis-hastings(6000, 1000, observations(),
    as-model(readings.length, temperature-model()), seed=8103)
  report-draws("MH: update a latent choice and regenerate the remaining trace",
    result.samples.map(fn(draw){ draw.value }))

pub fun run-smc() : <console,div,exn> ()
  val result = pseudo-random(8104, fn(){
    smc(1600, readings.length, observations(), temperature-model())
  })
  report-draws("SMC: update and resample particles after each reading",
    result.particles.map(fn(draw){ draw.value }))

pub fun run-rmsmc() : <console,div,exn> ()
  val result = pseudo-random(8105, fn(){
    rmsmc(800, readings.length, 1, observations(), temperature-model())
  })
  report-draws("RMSMC: add an MH move after each particle resampling",
    result.particles.map(fn(draw){ draw.value }))

pub fun run-pmmh() : <console,div,exn> ()
  val result = pseudo-random(8106, fn(){
    pmmh(6, readings.length, default-config(2500, 500), observations(), temperature-model())
  })
  report-draws("PMMH: sample the average using an inner particle likelihood estimate",
    result.samples.map(fn(draw){ draw.parameter }))

pub fun run-smc2() : <console,div,exn> ()
  val result = pseudo-random(8107, fn(){
    smc2(300, 6, readings.length, 1, observations(), temperature-model())
  })
  report-draws("SMC2: update particles of averages, each carrying its own inner filter",
    result.particles.map(fn(draw){ draw.parameter }))

pub fun main() : <console,div,exn> ()
  println("Average room temperature from readings " ++ readings.show ++ " degrees C")
  println("Real fluctuations: SD 0.5 C; thermometer noise: SD 1 C")
  run-lw()
  run-lwis()
  run-mh()
  run-smc()
  run-rmsmc()
  run-pmmh()
  run-smc2()
  println("Finite inference budgets produce approximate posterior estimates.")
