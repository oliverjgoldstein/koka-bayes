import bayes

// Model: observations share an unknown mean; their standard deviation is 1.
val measurement = obs-float64("measurement")

fun gaussian-model(count : int) : model<e,float64>
  fn(){
    val mean = normal'(0.0, 1.0)
    for(count) fn(_){ val _ = normal(measurement, mean, 1.0); () }
    mean
  }

pub fun main() : <console,div,exn> ()
  // Data assumptions: independent measurements given a common mean.
  val measurements = [1.0, 2.0]
  val observations = singleton(measurement, measurements)

  // Inference: 3000 transitions, including 500 discarded warm-up transitions.
  val posterior = metropolis-hastings(3000, 500, observations, gaussian-model(measurements.length), seed=2027)

  // Results: average the retained draws of the unknown mean.
  println("Observed measurements: " ++ measurements.show)
  println("Estimated mean: " ++ posterior-mean(posterior).show)
