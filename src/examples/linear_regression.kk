module examples/linear_regression

import std/num/random
import std/num/float64
import core/env
import core/model
import core/obsvar
import alg/lw
import alg/lwis
import alg/simulate

pub struct linear-regression-output
  slope     : float64
  intercept : float64
  sigma     : float64
  ys        : list<float64>

pub val slope-var     = obs-float64("linear-regression/slope")
pub val intercept-var = obs-float64("linear-regression/intercept")
pub val sigma-var     = obs-float64("linear-regression/sigma")
pub val y-var         = obs-float64("linear-regression/y")

pub fun model(xs : list<float64>) : model<e,linear-regression-output>
  fn()
    val slope = normal(slope-var, 0.0, 3.0)
    val intercept = normal(intercept-var, 0.0, 2.0)
    val sigma = uniform(sigma-var, 1.0, 3.0)
    val ys = xs.map(fn(x){ normal(y-var, (slope * x) + intercept, sigma) })
    Linear-regression-output(slope, intercept, sigma, ys)

pub fun linear-regression-model(xs : list<float64>) : model<e,linear-regression-output>
  model(xs)

pub fun simulate-demo() : <console,div,random> ()
  val xs = [-2.0, -1.0, 0.0, 1.0, 2.0]
  val result = pseudo-random(7, fn(){ simulate(empty(), model(xs)) })
  println("Linear regression simulation")
  println("  slope     = " ++ result.value.slope.show)
  println("  intercept = " ++ result.value.intercept.show)
  println("  sigma     = " ++ result.value.sigma.show)
  println("  ys        = [" ++ result.value.ys.map(fn(y){ y.show }).join(", ") ++ "]")

pub fun lw-demo(iterations : int = 200) : <console,div,random> ()
  val xs = [-2.0, -1.0, 0.0, 1.0, 2.0]
  val synthetic = pseudo-random(11, fn(){ simulate(empty(), model(xs)) })
  val observed = set(y-var, synthetic.value.ys, empty())
  val samples = pseudo-random(19, fn(){ lw(iterations, observed, model(xs)) })
  val best = best-sample(samples)
  println("Linear regression likelihood weighting")
  println("  observed ys = [" ++ synthetic.value.ys.map(fn(y){ y.show }).join(", ") ++ "]")
  println("  best log-weight = " ++ best.log-weight.show)
  println("  best slope      = " ++ best.value.slope.show)
  println("  best intercept  = " ++ best.value.intercept.show)
  println("  best sigma      = " ++ best.value.sigma.show)

pub fun lwis-demo(iterations : int = 200) : <console,div,random> ()
  val xs = [-2.0, -1.0, 0.0, 1.0, 2.0]
  val synthetic = pseudo-random(23, fn(){ simulate(empty(), model(xs)) })
  val observed = set(y-var, synthetic.value.ys, empty())
  val posterior = pseudo-random(29, fn(){ lwis(iterations, observed, model(xs)) })
  println("Linear regression likelihood weighting with resampling")
  println("  observed ys = [" ++ synthetic.value.ys.map(fn(y){ y.show }).join(", ") ++ "]")
  println("  posterior slope preview = " ++ preview-float64s(posterior.map(fn(sample){ sample.slope })))
  println("  posterior sigma preview = " ++ preview-float64s(posterior.map(fn(sample){ sample.sigma })))

fun best-sample(samples : list<weighted-sample<linear-regression-output>>) : weighted-sample<linear-regression-output>
  match samples
    Cons(sample, rest) -> rest.foldl(sample, fn(best, current){
      if current.log-weight > best.log-weight then current else best
    })
    Nil -> Weighted-sample(Linear-regression-output(0.0, 0.0, 1.0, []), [], empty(), neginf)

fun preview-float64s(values : list<float64>, limit : int = 8) : string
  val shown = take-float64s(limit, values).map(fn(x){ x.show }).join(", ")
  val suffix = if values.length > limit then ", ..." else ""
  "[" ++ shown ++ suffix ++ "]"

fun take-float64s(limit : int, values : list<float64>) : list<float64>
  if limit <= 0
    then []
    else
      match values
        Nil -> []
        Cons(value, rest) -> Cons(value, take-float64s(limit - 1, rest))
