module examples/compositional_inference

import bayes
import std/num/random
import alg/handler_smc
import alg/smc
import handlers/sequential

val thermometer = obs-float64("room/reading")
val readings = [19.0, 21.0, 22.0]

// Plain model code, with explicit points where the population may resample.
// The same checkpoints can be interpreted by run-sequential to run as usual.
fun room() : <checkpoint,obs-reader,model-dist,div> float64
  val temperature = normal'(20.0, 2.0)
  readings.foreach fn(_){
    val observed = normal(thermometer, temperature, 1.0)
    checkpoint()
  }
  temperature

pub fun main() : <console,div,exn> ()
  val data = singleton(thermometer, readings)
  val posterior = pseudo-random(2027, fn(){ smc-model(2500, data, room) })
  val ordinary = likelihood-weighting(2500, data, fn(){ run-sequential(room) }, seed=2027)
  println("One thermometer model, two compositions of inference handlers")
  println("Checkpoint SMC mean: " ++ posterior-mean(posterior.particles.map(fn(p){ p.value })).show)
  println("LW with checkpoints completed: " ++ posterior-mean(ordinary).show)
  println("Exact posterior mean: " ++ ((20.0 / 4.0 + 19.0 + 21.0 + 22.0) / (1.0 / 4.0 + 3.0)).show)
  println("Compositional inference example passed.")
