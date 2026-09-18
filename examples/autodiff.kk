module examples/autodiff

import std/num/float64
import autodiff/smooth
import autodiff/reverse
import examples/temperature

// Each reading is its own differentiable component. foldl composes them.
fun reading-log-density(reading : float64, temperature : a) : smooth<a> a
  ad-normal-log-density(ad-constant(reading), temperature, ad-constant(reading-stddev))

pub fun temperature-log-joint(xs : list<a>) : smooth<a> a
  match xs
    Cons(temperature, _) ->
      val prior = ad-normal-log-density(temperature, ad-constant(prior-mean), ad-constant(prior-stddev))
      readings.foldl(prior, fn(total, reading){ ad-add(total, reading-log-density(reading, temperature)) })
    _ -> ad-constant(0.0)

fun maximize(theta : float64, steps : int) : <div,exn> float64
  if steps <= 0 then theta
  else
    val result = value-and-grad(temperature-log-joint, [theta])
    match result.partials
      Cons(slope, Nil) -> maximize(theta + 0.25 * slope, steps - 1)
      _ -> throw("expected one temperature gradient")

pub fun main() : <console,div,exn> ()
  val theta = maximize(16.0, 16)
  val (exact-mode, _) = exact-posterior()
  if not(abs(theta - exact-mode) <= 1.0e-8) then throw("Temperature MAP disagrees with exact optimum") else ()
  val result = value-and-grad(temperature-log-joint, [theta])
  println("Handler-based reverse AD: room temperature")
  println("Readings (degrees C): " ++ readings.show)
  println("Exact posterior mode: " ++ exact-mode.show)
  println("Gradient ascent: 16 steps, learning rate 0.25, starting at 16 degrees C")
  println("Estimated mode (degrees C): " ++ theta.show)
  println("Absolute error: " ++ abs(theta - exact-mode).show)
  println("Log joint at estimated mode: " ++ result.value.show)
  println("This example optimizes a log density; it does not draw posterior samples.")
