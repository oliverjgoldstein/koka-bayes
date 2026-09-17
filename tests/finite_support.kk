module finite_support

import std/num/float64
import core/dist
import core/finite
import core/obsvalue

fun ensure(message : string, condition : bool) : exn ()
  if not(condition) then throw(message)

fun near(actual : float64, expected : float64, tolerance : float64 = 1.0e-12) : bool
  abs(actual - expected) <= tolerance

fun rejects(action : () -> <div,exn> list<finite-choice>) : div bool
  try(fn(){ val result = action(); False }, fn(_exception){ True })

fun integers(choices : list<finite-choice>) : exn list<int>
  choices.map(fn(choice){
    match choice.value
      ObsInt(value) -> value
      _ -> throw("Expected integer support.")
  })

fun booleans(choices : list<finite-choice>) : exn list<bool>
  choices.map(fn(choice){
    match choice.value
      ObsBool(value) -> value
      _ -> throw("Expected boolean support.")
  })

fun masses(choices : list<finite-choice>) : list<float64>
  choices.map(fn(choice){ exp(choice.log-probability) })

fun test-bernoulli() : <div,exn> ()
  val ordinary = finite-support(bernoulli-dist(0.25), 2)
  ensure("Bernoulli support keeps both outcomes", booleans(ordinary) == [False, True])
  ensure("Bernoulli masses are .75 and .25", zip(masses(ordinary), [0.75, 0.25]).all(fn(pair){ near(fst(pair), snd(pair)) }))
  val zero = finite-support(bernoulli-dist(0.0), 1)
  val one = finite-support(bernoulli-dist(1.0), 1)
  ensure("Bernoulli zero probability is omitted", booleans(zero) == [False] && masses(zero) == [1.0])
  ensure("Bernoulli certainty needs one support slot", booleans(one) == [True] && masses(one) == [1.0])
  val tiny = finite-support(bernoulli-dist(1.0e-308), 2)
  ensure("Bernoulli tiny positive probability is retained", tiny.length == 2 && tiny.all(fn(choice){ is-finite(choice.log-probability) }))
  ensure("Bernoulli near-one mass uses log1p", match tiny {
    Cons(first, _) -> first.log-probability < 0.0 && near(first.log-probability / (~1.0e-308), 1.0)
    _ -> False
  })

fun test-categorical() : <div,exn> ()
  val sparse = finite-support(discrete-dist([0.0, 2.0, 0.0, 3.0, 0.0]), 2)
  ensure("Categorical support preserves original indexes", integers(sparse) == [1, 3])
  ensure("Categorical weights normalize", zip(masses(sparse), [0.4, 0.6]).all(fn(pair){ near(fst(pair), snd(pair)) }))
  val large = finite-support(discrete-dist([1.0e308, 1.0e308]), 2)
  ensure("Large categorical weights avoid overflow", masses(large).all(fn(mass){ near(mass, 0.5) }))
  val tiny = finite-support(discrete-dist([1.0e308, 0.0, 1.0e-308]), 2)
  ensure("Underflowing categorical mass retains its support", integers(tiny) == [0, 2])
  ensure("Underflowing categorical mass retains a finite log probability", tiny.all(fn(choice){ is-finite(choice.log-probability) }))
  match tiny
    Cons(first, Cons(last, Nil)) ->
      ensure("Dominant categorical log probability is zero to precision", near(first.log-probability, 0.0))
      ensure("Tiny log probability uses original weights", near(last.log-probability, ln(1.0e-308) - ln(1.0e308)))
      ensure("The tiny branch really would underflow outside log space", exp(last.log-probability) == 0.0)
    _ -> throw("Unexpected categorical support size.")
  val subnormal = finite-support(discrete-dist([1.0e-320, 2.0e-320]), 2)
  ensure("Subnormal categorical weights normalize", zip(masses(subnormal), [1.0/3.0, 2.0/3.0]).all(fn(pair){ near(fst(pair), snd(pair)) }))

fun test-binomial() : <div,exn> ()
  val ordinary = finite-support(binomial-dist(4, 0.25), 5)
  ensure("Binomial support is zero through n", integers(ordinary) == [0, 1, 2, 3, 4])
  val oracle = [81.0/256.0, 108.0/256.0, 54.0/256.0, 12.0/256.0, 1.0/256.0]
  ensure("Binomial masses match exact polynomial coefficients", zip(masses(ordinary), oracle).all(fn(pair){ near(fst(pair), snd(pair)) }))
  val zero-trials = finite-support(binomial-dist(0, 0.37), 1)
  val no-success = finite-support(binomial-dist(1000000000, 0.0), 1)
  val all-success = finite-support(binomial-dist(1000000000, 1.0), 1)
  ensure("Zero-trial Binomial needs one support slot", integers(zero-trials) == [0] && masses(zero-trials) == [1.0])
  ensure("Huge degenerate Binomial avoids allocating n+1", integers(no-success) == [0] && integers(all-success) == [1000000000])
  ensure("Degenerate Binomial mass is one", masses(no-success) == [1.0] && masses(all-success) == [1.0])
  val symmetric = finite-support(binomial-dist(1200, 0.5), 1201)
  ensure("Large Binomial retains tiny endpoint log masses", symmetric.length == 1201 && symmetric.all(fn(choice){ is-finite(choice.log-probability) }))
  val mass = masses(symmetric).foldl(0.0, fn(acc, probability){ acc + probability })
  val mean = zip(integers(symmetric), masses(symmetric)).foldl(0.0, fn(acc, pair){ acc + float64(fst(pair)) * snd(pair) })
  val variance = zip(integers(symmetric), masses(symmetric)).foldl(0.0, fn(acc, pair){
    val centered = float64(fst(pair)) - 600.0
    acc + centered * centered * snd(pair)
  })
  ensure("Large Binomial normalizes", near(mass, 1.0))
  ensure("Large Binomial has analytic mean", near(mean, 600.0, 1.0e-8))
  ensure("Large Binomial has analytic variance", near(variance, 300.0, 1.0e-8))
  val skewed = finite-support(binomial-dist(4, 1.0e-308), 5)
  ensure("Extremely skewed Binomial retains every positive branch", skewed.length == 5 && skewed.all(fn(choice){ is-finite(choice.log-probability) }))

fun test-rejections() : <div,exn> ()
  [0, ~1].foreach fn(budget){
    ensure("Nonpositive support budget is rejected", rejects(fn(){ finite-support(bernoulli-dist(0.0), budget) }))
  }
  ensure("Bernoulli support cannot silently truncate", rejects(fn(){ finite-support(bernoulli-dist(0.5), 1) }))
  ensure("Categorical support cannot silently truncate", rejects(fn(){ finite-support(discrete-dist([1.0, 0.0, 2.0]), 1) }))
  ensure("Huge Binomial is rejected before allocation", rejects(fn(){ finite-support(binomial-dist(1000000000, 0.5), 10) }))
  [bernoulli-dist(~0.1), bernoulli-dist(nan), bernoulli-dist(posinf),
   discrete-dist([]), discrete-dist([0.0]), discrete-dist([~1.0, 2.0]),
   discrete-dist([nan, 1.0]), discrete-dist([posinf]),
   binomial-dist(~1, 0.5), binomial-dist(3, 1.1), poisson-dist(~1.0)].foreach fn(distribution){
    ensure("Invalid distribution parameters are rejected", rejects(fn(){ finite-support(distribution, 10) }))
  }
  [normal-dist(0.0, 1.0), uniform-dist(0.0, 1.0), gamma-dist(2.0, 1.0),
   beta-dist(2.0, 3.0), poisson-dist(1.0)].foreach fn(distribution){
    ensure("Unsupported continuous or infinite support is explicit", rejects(fn(){ finite-support(distribution, 10) }))
  }
  val poisson-zero = finite-support(poisson-dist(0.0), 1)
  ensure("Poisson zero has finite singleton support", integers(poisson-zero) == [0] && masses(poisson-zero) == [1.0])

pub fun main() : <console,div,exn> ()
  test-bernoulli()
  test-categorical()
  test-binomial()
  test-rejections()
  println("Finite support checks passed.")
