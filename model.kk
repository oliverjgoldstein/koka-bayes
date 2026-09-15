import bayes

// Model: one unknown probability, shared by all coin flips.
val flip = obs-bool("flip")

fun coin-model(count : int) : model<e,float64>
  fn(){
    val probability = beta'(2.0, 3.0)
    for(count) fn(_){ val _ = bernoulli(flip, probability); () }
    probability
  }

pub fun main() : <console,div,exn> ()
  // Data assumptions: flips are independent given the same probability.
  val flips = [True, True, True, False]
  val observations = singleton(flip, flips)

  // Inference: change this line to choose the algorithm and its budget.
  val posterior = likelihood-weighting(2000, observations, coin-model(flips.length), seed=2027)
  // Alternative: metropolis-hastings(3000, 500, observations, coin-model(flips.length), seed=2027)

  // Results: the posterior mean of the unknown probability.
  println("Observed flips: " ++ flips.show)
  println("Estimated probability of heads: " ++ posterior-mean(posterior).show)
