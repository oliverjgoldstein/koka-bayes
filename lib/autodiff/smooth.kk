module autodiff/smooth

import std/num/float64

// Arithmetic is an effect: the same program can evaluate or differentiate.
pub type unary-op
  Negate
  Exponential
  Logarithm
  Sine
  Cosine

pub type binary-op
  Add
  Subtract
  Multiply
  Divide

pub effect smooth<a>
  fun constant(value : float64) : a
  ctl apply-unary(op : unary-op, x : a) : a
  ctl apply-binary(op : binary-op, x : a, y : a) : a

pub fun ad-constant(value : float64) : smooth<a> a
  constant(value)

pub fun ad-negate(x : a) : smooth<a> a
  apply-unary(Negate, x)

pub fun ad-exp(x : a) : smooth<a> a
  apply-unary(Exponential, x)

pub fun ad-log(x : a) : smooth<a> a
  apply-unary(Logarithm, x)

pub fun ad-sin(x : a) : smooth<a> a
  apply-unary(Sine, x)

pub fun ad-cos(x : a) : smooth<a> a
  apply-unary(Cosine, x)

pub fun ad-add(x : a, y : a) : smooth<a> a
  apply-binary(Add, x, y)

pub fun ad-sub(x : a, y : a) : smooth<a> a
  apply-binary(Subtract, x, y)

pub fun ad-mul(x : a, y : a) : smooth<a> a
  apply-binary(Multiply, x, y)

pub fun ad-div(x : a, y : a) : smooth<a> a
  apply-binary(Divide, x, y)

pub fun ad-square(x : a) : smooth<a> a
  ad-mul(x, x)

pub fun unary-value(op : unary-op, x : float64) : float64
  match op
    Negate      -> ~x
    Exponential -> exp(x)
    Logarithm   -> ln(x)
    Sine        -> sin(x)
    Cosine      -> cos(x)

pub fun unary-derivative(op : unary-op, x : float64) : float64
  match op
    Negate      -> ~1.0
    Exponential -> exp(x)
    Logarithm   -> 1.0 / x
    Sine        -> cos(x)
    Cosine      -> ~sin(x)

pub fun binary-value(op : binary-op, x : float64, y : float64) : float64
  match op
    Add      -> x + y
    Subtract -> x - y
    Multiply -> x * y
    Divide   -> x / y

pub fun binary-partials(op : binary-op, x : float64, y : float64) : (float64,float64)
  match op
    Add      -> (1.0, 1.0)
    Subtract -> (1.0, ~1.0)
    Multiply -> (y, x)
    // Avoid squaring y: it can overflow or underflow while both partials are finite.
    Divide   -> (1.0 / y, ~(x / y) / y)

pub fun evaluate(action : () -> <smooth<float64>|e> a) : e a
  handle(action)
    return(result) result
    fun constant(value) value
    fun apply-unary(op, x) unary-value(op, x)
    fun apply-binary(op, x, y) binary-value(op, x, y)

// A normalized scalar normal log density. stddev must be strictly positive.
// Parameters and observations can all participate in differentiation.
pub fun ad-normal-log-density(x : a, mean : a, stddev : a) : smooth<a> a
  val centered = ad-div(ad-sub(x, mean), stddev)
  ad-sub(ad-sub(ad-constant(~0.5 * ln(2.0 * pi)), ad-log(stddev)),
         ad-mul(ad-constant(0.5), ad-square(centered)))
