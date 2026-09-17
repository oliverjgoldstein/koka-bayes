module examples/temperature

import bayes

// One room, one unknown temperature, and three independent noisy readings.
pub val readings = [19.0, 21.0, 22.0]
pub val prior-mean = 20.0
pub val prior-stddev = 2.0
pub val reading-stddev = 1.0
val thermometer = obs-float64("thermometer")

fun room-temperature(count : int) : model<e,float64>
  fn(){
    val temperature = normal'(prior-mean, prior-stddev)
    for(count) fn(_){ val _ = normal(thermometer, temperature, reading-stddev); () }
    temperature
  }

// Normal prior + normal measurement noise has an exact normal posterior.
pub fun exact-posterior() : (float64,float64)
  val prior-precision = 1.0 / (prior-stddev * prior-stddev)
  val reading-precision = 1.0 / (reading-stddev * reading-stddev)
  val variance = 1.0 / (prior-precision + float64(readings.length) * reading-precision)
  val mean = variance * (prior-mean * prior-precision
    + readings.foldl(0.0, fn(total, reading){ total + reading }) * reading-precision)
  (mean, variance)

pub fun main() : <console,div,exn> ()
  val observations = singleton(thermometer, readings)
  val posterior = likelihood-weighting(6000, observations, room-temperature(readings.length), seed=2027)
  val (exact-mean, exact-variance) = exact-posterior()
  println("Room temperature from noisy thermometer readings")
  println("Readings (degrees C): " ++ readings.show)
  println("Prior mean: " ++ prior-mean.show ++ "; prior standard deviation: " ++ prior-stddev.show)
  println("Reading noise standard deviation: " ++ reading-stddev.show)
  println("Estimated temperature: " ++ posterior-mean(posterior).show)
  println("Exact posterior mean and mode: " ++ exact-mean.show)
  println("Exact posterior standard deviation: " ++ sqrt(exact-variance).show)
