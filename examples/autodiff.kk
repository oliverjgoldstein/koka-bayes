module examples/autodiff

import std/num/float64
import autodiff/smooth
import autodiff/reverse

// theta ~ N(0,1), y=2 ~ N(theta,1); the posterior is N(1,1/2).
fun gaussian-log-joint(xs : list<a>) : smooth<a> a
  match xs
    Cons(theta, _) ->
      ad-add(ad-normal-log-density(theta, ad-constant(0.0), ad-constant(1.0)),
        ad-normal-log-density(ad-constant(2.0), theta, ad-constant(1.0)))
    _ -> ad-constant(0.0)

fun maximize(theta : float64, steps : int) : <div,exn> float64
  if steps <= 0 then theta
  else
    val result = value-and-grad(gaussian-log-joint, [theta])
    match result.partials
      Cons(slope, Nil) -> maximize(theta + 0.25 * slope, steps - 1)
      _ -> throw("expected one Gaussian parameter gradient")

pub fun main() : <console,div,exn> ()
  val theta = maximize(~3.0, 32)
  if not(abs(theta - 1.0) <= 1.0e-8) then throw("Gaussian MAP disagrees with exact optimum") else ()
  val result = value-and-grad(gaussian-log-joint, [theta])
  println("Handler-based reverse AD: Gaussian posterior MAP")
  println("Prior N(0,1); observation 2 with variance 1")
  println("Exact posterior: mean 1, variance 0.5, mode 1")
  println("Gradient ascent: 32 steps, learning rate 0.25, starting at -3")
  println("Estimated mode: " ++ theta.show)
  println("Absolute error: " ++ abs(theta - 1.0).show)
  println("Log joint at estimated mode: " ++ result.value.show)
  println("This example optimizes a log density; it does not draw posterior samples.")
