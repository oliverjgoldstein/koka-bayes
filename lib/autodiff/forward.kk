module autodiff/forward

import std/num/float64
import autodiff/smooth

pub struct dual
  primal  : float64
  tangent : float64

// A forward handler evaluates a primal and one directional derivative.
pub fun forward(action : () -> <smooth<dual>|e> a) : e a
  handle(action)
    return(result) result
    fun constant(value) Dual(value, 0.0)
    fun apply-unary(op, x)
      Dual(unary-value(op, x.primal), unary-derivative(op, x.primal) * x.tangent)
    fun apply-binary(op, x, y)
      val (dx, dy) = binary-partials(op, x.primal, y.primal)
      Dual(binary-value(op, x.primal, y.primal), dx * x.tangent + dy * y.tangent)

pub fun value-and-derivative(f : dual -> smooth<dual> dual, x : float64) : dual
  forward(fn(){ f(Dual(x, 1.0)) })
