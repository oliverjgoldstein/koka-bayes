module autodiff_checks

import std/num/float64
import autodiff/smooth
import autodiff/forward
import autodiff/reverse
import examples/autodiff

fun ensure-close(label : string, actual : float64, expected : float64) : <div,exn> ()
  if abs(actual - expected) <= 1.0e-10 * max(1.0, abs(expected))
    then ()
    else throw(label ++ ": expected " ++ expected.show ++ ", got " ++ actual.show)

// Polynomial: 1 + x^3 - y^2, with gradient (3*x^2, -2*y).
fun polynomial(xs : list<a>) : smooth<a> a
  match xs
    Cons(x, Cons(y, _)) ->
      ad-add(ad-constant(1.0), ad-sub(ad-mul(ad-square(x), x), ad-square(y)))
    Nil -> ad-constant(0.0)
    _ -> ad-constant(0.0)

fun shared(xs : list<a>) : smooth<a> a
  match xs
    Cons(x, Cons(y, _)) ->
      val product = ad-mul(x, y)
      ad-add(ad-square(product), product)
    _ -> ad-constant(0.0)

fun primitives(xs : list<a>) : smooth<a> a
  match xs
    Cons(x, Cons(y, _)) ->
      ad-add(ad-add(ad-exp(x), ad-log(y)),
        ad-add(ad-mul(ad-sin(x), ad-cos(y)), ad-negate(ad-div(x, y))))
    _ -> ad-constant(0.0)

fun normal-density(xs : list<a>) : smooth<a> a
  match xs
    Cons(x, Cons(mean, Cons(stddev, _))) -> ad-normal-log-density(x, mean, stddev)
    _ -> ad-constant(0.0)

fun quotient(xs : list<a>) : smooth<a> a
  match xs
    Cons(x, Cons(y, _)) -> ad-div(x, y)
    _ -> ad-constant(0.0)

// theta ~ N(0,1); observe 2 ~ N(theta,1). Posterior is N(1,1/2).
fun normal-joint(xs : list<a>) : smooth<a> a
  match xs
    Cons(theta, _) ->
      ad-add(ad-normal-log-density(theta, ad-constant(0.0), ad-constant(1.0)),
        ad-normal-log-density(ad-constant(2.0), theta, ad-constant(1.0)))
    _ -> ad-constant(0.0)

fun ignore-inputs(_xs : list<a>) : smooth<a> a
  ad-constant(7.0)

fun identity(xs : list<a>) : smooth<a> a
  match xs
    Cons(x, _) -> x
    _ -> ad-constant(0.0)

fun ensure-gradient(label : string, actual : list<float64>, expected : list<float64>) : <div,exn> ()
  match (actual, expected)
    (Nil, Nil) -> ()
    (Cons(x, xs), Cons(y, ys)) ->
      ensure-close(label, x, y)
      ensure-gradient(label, xs, ys)
    _ -> throw(label ++ ": gradient has the wrong shape")

fun test-polynomial() : <div,exn> ()
  ensure-close("polynomial evaluation", evaluate(fn(){ polynomial([2.0, 4.0]) }), ~7.0)
  val forward-result = forward(fn(){ polynomial([Dual(2.0, 1.0), Dual(4.0, 0.0)]) })
  ensure-close("polynomial forward value", forward-result.primal, ~7.0)
  ensure-close("polynomial forward derivative", forward-result.tangent, 12.0)
  val reverse-result = value-and-grad(polynomial, [2.0, 4.0])
  ensure-close("polynomial reverse value", reverse-result.value, ~7.0)
  ensure-gradient("polynomial reverse gradient", reverse-result.partials, [12.0, ~8.0])

fun test-shared-subexpressions() : <div,exn> ()
  val result = value-and-grad(shared, [2.0, 3.0])
  ensure-close("shared product value", result.value, 42.0)
  ensure-gradient("shared product gradient", result.partials, [39.0, 26.0])
  val result2 = forward(fn(){ shared([Dual(2.0, 2.0), Dual(3.0, ~1.0)]) })
  ensure-close("shared product directional derivative", result2.tangent, 52.0)

fun test-primitives() : <div,exn> ()
  val x = 0.7
  val y = 1.4
  val expected = exp(x) + ln(y) + sin(x) * cos(y) - x / y
  val dx = exp(x) + cos(x) * cos(y) - 1.0 / y
  val dy = 1.0 / y - sin(x) * sin(y) + x / (y * y)
  val result = value-and-grad(primitives, [x, y])
  ensure-close("all primitives value", result.value, expected)
  ensure-gradient("all primitives gradient", result.partials, [dx, dy])
  val result2 = forward(fn(){ primitives([Dual(x, 2.0), Dual(y, ~3.0)]) })
  ensure-close("all primitives directional derivative", result2.tangent, 2.0 * dx - 3.0 * dy)

fun test-normal-density() : <div,exn> ()
  val expected = ~0.5 * ln(2.0 * pi) - ln(1.5) - 8.0 / 9.0
  val result = value-and-grad(normal-density, [1.7, ~0.3, 1.5])
  ensure-close("normal log density", result.value, expected)
  ensure-gradient("normal density gradient", result.partials, [~8.0 / 9.0, 8.0 / 9.0, 14.0 / 27.0])
  val result2 = forward(fn(){ normal-density([Dual(1.7, 0.0), Dual(~0.3, 0.0), Dual(1.5, 1.0)]) })
  ensure-close("normal scale forward derivative", result2.tangent, 14.0 / 27.0)

fun test-division-scales() : <div,exn> ()
  // For x/y at x=y=s, the partials are 1/s and -1/s. Scaling back by s
  // detects even a tiny gradient incorrectly rounded to zero by squaring y.
  [1.0e200, 1.0e-200].foreach fn(scale){
    val result = value-and-grad(quotient, [scale, scale])
    ensure-close("scaled quotient value", result.value, 1.0)
    ensure-gradient("scaled quotient reverse gradient",
      result.partials.map(fn(partial){ partial * scale }), [1.0, ~1.0])
    val directional = forward(fn(){ quotient([Dual(scale, 0.0), Dual(scale, scale)]) })
    ensure-close("scaled quotient forward derivative", directional.tangent, ~1.0)
  }

fun test-normal-joint() : <div,exn> ()
  val result = value-and-grad(normal-joint, [0.25])
  ensure-close("normal joint log density", result.value, ~ln(2.0 * pi) - 1.5625)
  ensure-gradient("normal joint gradient", result.partials, [1.5])
  ensure-gradient("normal posterior mode gradient", value-and-grad(normal-joint, [1.0]).partials, [0.0])
  // Repeated differentiation also supports optimization of this log density.
  var theta := ~3.0
  for(32) fn(_i){
    match value-and-grad(normal-joint, [theta]).partials
      Cons(slope, Nil) -> theta := theta + 0.25 * slope
      _ -> throw("expected one Gaussian gradient")
  }
  if abs(theta - 1.0) < 1.0e-8 then ()
    else throw("gradient ascent missed the exact Gaussian posterior mode")

fun test-composed-temperature() : <div,exn> ()
  // Independent derivative of the prior plus all three readings: 67 - 13*T/4.
  ensure-gradient("composed temperature gradient at 20",
    value-and-grad(temperature-log-joint, [20.0]).partials, [2.0])
  ensure-gradient("composed temperature gradient at 22",
    value-and-grad(temperature-log-joint, [22.0]).partials, [~4.5])
  ensure-gradient("exact temperature mode gradient",
    value-and-grad(temperature-log-joint, [268.0 / 13.0]).partials, [0.0])
  val directional = forward(fn(){ temperature-log-joint([Dual(20.0, 3.0)]) })
  ensure-close("composed temperature forward derivative", directional.tangent, 6.0)
  // Prior normalization contributes log(2); squared residual terms sum to 3.
  ensure-close("composed temperature log joint", directional.primal,
    ~2.0 * ln(2.0 * pi) - ln(2.0) - 3.0)

fun test-constants-identity-and-isolation() : <div,exn> ()
  val constant-result = value-and-grad(ignore-inputs, [2.0, 3.0])
  ensure-close("constant value", constant-result.value, 7.0)
  ensure-gradient("unused input gradients", constant-result.partials, [0.0, 0.0])
  ensure-gradient("empty input gradient", value-and-grad(ignore-inputs, []).partials, [])
  ensure-gradient("identity and unused input", value-and-grad(identity, [2.0, 3.0]).partials, [1.0, 0.0])
  // Repeated runs must neither retain adjoints nor interfere with forward mode.
  ensure-gradient("first independent run", value-and-grad(shared, [2.0, 3.0]).partials, [39.0, 26.0])
  ensure-gradient("second independent run", value-and-grad(shared, [1.0, 2.0]).partials, [10.0, 5.0])
  ensure-gradient("repeat independent run", value-and-grad(shared, [2.0, 3.0]).partials, [39.0, 26.0])
  val identity-forward = value-and-derivative(fn(x){ x }, 3.0)
  ensure-close("identity forward derivative", identity-forward.tangent, 1.0)

fun test-central-differences() : <div,exn> ()
  // Independent numerical cross-check, in addition to analytic assertions.
  val h = 1.0e-5
  val plus = evaluate(fn(){ primitives([0.7 + h, 1.4]) })
  val minus = evaluate(fn(){ primitives([0.7 - h, 1.4]) })
  val derivative = (plus - minus) / (2.0 * h)
  val actual = forward(fn(){ primitives([Dual(0.7, 1.0), Dual(1.4, 0.0)]) })
  if abs(actual.tangent - derivative) < 1.0e-8 then ()
    else throw("central finite difference disagrees with AD")

pub fun main() : <console,div,exn> ()
  test-polynomial()
  test-shared-subexpressions()
  test-primitives()
  test-division-scales()
  test-normal-density()
  test-normal-joint()
  test-composed-temperature()
  test-constants-identity-and-isolation()
  test-central-differences()
  println("autodiff checks passed: analytic values/gradients, sharing, Gaussian density, finite differences, isolation")
