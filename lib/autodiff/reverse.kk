module autodiff/reverse

import std/num/float64
import autodiff/smooth

pub struct reverse-value<h>
  primal  : float64
  adjoint : ref<h,float64>

pub struct gradient
  value    : float64
  partials : list<float64>

// The continuation is the reverse tape: contributions accumulate after resume.
// Each call owns its references through run; there is no global AD state.
fun reverse-handler(action : () -> <smooth<reverse-value<h>>,st<h>> reverse-value<h>) : st<h> float64
  handle(action)
    return(output)
      set(output.adjoint, 1.0)
      output.primal
    fun constant(value)
      Reverse-value(value, ref(0.0))
    ctl apply-unary(op, x)
      val output = Reverse-value(unary-value(op, x.primal), ref(0.0))
      val result = resume(output)
      set(x.adjoint, !(x.adjoint) + unary-derivative(op, x.primal) * !(output.adjoint))
      result
    ctl apply-binary(op, x, y)
      val output = Reverse-value(binary-value(op, x.primal, y.primal), ref(0.0))
      val result = resume(output)
      val (dx, dy) = binary-partials(op, x.primal, y.primal)
      // Read each parent again: x and y can refer to the same value.
      set(x.adjoint, !(x.adjoint) + dx * !(output.adjoint))
      set(y.adjoint, !(y.adjoint) + dy * !(output.adjoint))
      result

pub fun value-and-grad(f : forall<a> list<a> -> smooth<a> a, xs : list<float64>) : gradient
  run(fn(){
    val inputs = xs.map(fn(x){ Reverse-value(x, ref(0.0)) })
    val value = reverse-handler(fn(){ f(inputs) })
    Gradient(value, inputs.map(fn(x){ !(x.adjoint) }))
  })
