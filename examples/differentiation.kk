import std/num/float64
import autodiff/smooth
import autodiff/forward
import autodiff/reverse

// A polynomial with an exact gradient: f(x,y) = 1 + x*x*x - y*y.
fun objective(xs : list<a>) : smooth<a> a
  match xs
    Cons(x, Cons(y, _)) ->
      ad-add(ad-constant(1.0), ad-add(ad-mul(ad-mul(x, x), x), ad-negate(ad-mul(y, y))))
    _ -> ad-constant(0.0)

pub fun main()
  val value = evaluate(fn(){ objective([2.0, 4.0]) })
  val directional = forward(fn(){ objective([Dual(2.0, 1.0), Dual(4.0, 0.0)]) })
  val gradient = value-and-grad(objective, [2.0, 4.0])
  println("Model: f(x,y) = 1 + x*x*x - y*y")
  println("Inputs: x=2, y=4")
  println("Evaluation: " ++ value.show ++ " (exact: -7)")
  println("Forward derivative in x: " ++ directional.tangent.show ++ " (exact: 12)")
  println("Reverse gradient: " ++ gradient.partials.show ++ " (exact: [12,-8])")
