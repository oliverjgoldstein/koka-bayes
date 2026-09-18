module examples/exact_inference

import bayes

val alarm = obs-bool("machine/alarm")
val thermometer = obs-float64("room/reading")

// The alarm is more likely when the machine is faulty, but is not definitive.
fun machine() : model<e,bool>
  fn(){
    val faulty = bernoulli'(0.3)
    val sounded = bernoulli(alarm, if faulty then 0.8 else 0.2)
    faulty
  }

fun two-coins() : model<e,int>
  fn(){
    val first = bernoulli'(0.5)
    val second = bernoulli'(0.5)
    (if first then 1 else 0) + (if second then 1 else 0)
  }

// Only the latent heater setting is enumerated. An observed real-valued
// temperature contributes its Normal density without requiring a continuous
// set of latent alternatives.
fun heated-room() : model<e,bool>
  fn(){
    val heater-on = bernoulli'(0.3)
    val reading = normal(thermometer, if heater-on then 22.0 else 18.0, 2.0)
    heater-on
  }

fun ensure(label : string, condition : bool) : exn ()
  if not(condition) then throw(label)

fun close(label : string, actual : float64, expected : float64) : exn ()
  ensure(label ++ ": expected " ++ expected.show ++ ", got " ++ actual.show,
    is-finite(actual) && abs(actual - expected) < 1.0e-12)

pub fun main() : <console,div,exn> ()
  println("Exact inference by enumerating finite choices")
  val machine-result = enumerate(singleton(alarm, [True]), machine())
  val fault-probability = probability(machine-result, fn(faulty){ faulty })
  close("fault posterior", fault-probability, 12.0 / 19.0)
  close("alarm evidence", exp(machine-result.log-evidence), 0.38)
  println("Machine fault after hearing the alarm: " ++ fault-probability.show)
  println("  Prior: 0.3; exact posterior: 12/19; probability of hearing the alarm: 0.38")

  val coins = enumerate(empty(), two-coins())
  val counts = marginal(coins, fn(left, right){ left == right })
  ensure("two coins have four positive execution paths", coins.executions == 4 && coins.outcomes.length == 4)
  ensure("two coins use nine budgeted nodes", coins.nodes == 9)
  ensure("equal returned counts combine into three marginal outcomes", counts.length == 3)
  close("zero heads", probability(coins, fn(heads){ heads == 0 }), 0.25)
  close("one head", probability(coins, fn(heads){ heads == 1 }), 0.5)
  close("two heads", probability(coins, fn(heads){ heads == 2 }), 0.25)
  close("expected heads", expectation(coins, fn(heads){ float64(heads) }), 1.0)
  println("Two fair coins: four paths, three possible head counts")
  counts.foreach fn(outcome){
    ensure("marginal count is in the coin support", outcome.value >= 0 && outcome.value <= 2)
    close("aggregated coin marginal", outcome.probability, if outcome.value == 1 then 0.5 else 0.25)
    println("  " ++ outcome.value.show ++ " heads: " ++ outcome.probability.show)
  }

  val room = enumerate(singleton(thermometer, [21.0]), heated-room())
  val heater-probability = probability(room, fn(on){ on })
  val on-density = exp(~1.0 / 8.0) / sqrt(8.0 * pi)
  val off-density = exp(~9.0 / 8.0) / sqrt(8.0 * pi)
  val observation-density = 0.3 * on-density + 0.7 * off-density
  close("heater posterior", heater-probability, 0.3 / (0.3 + 0.7 * exp(~1.0)))
  close("continuous observation evidence density", exp(room.log-evidence), observation-density)
  println("Heater on after a 21-degree reading: " ++ heater-probability.show)
  println("  Two latent choices; the observed Normal reading contributes a density.")
  println("Finite enumeration examples passed.")
