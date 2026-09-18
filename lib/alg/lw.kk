module alg/lw

import std/num/random
import std/num/float64
import core/dist
import core/env
import core/model
import core/trace
import handlers/trace

pub struct weighted-sample<a>
  value      : a
  trace      : run-trace
  output-env : env
  log-weight : float64

// Compose branch-local reading, tracing, sampling and weight accumulation.
pub fun run-lw(environment : env, action : model<e,a>) : <div,random|e> weighted-sample<a>
  fst(run-lw-state(environment, action))

pub fun run-lw-state(environment : env, action : model<e,a>) : <div,random|e> (weighted-sample<a>,env)
  val result = run-traced(environment, action)
  (Weighted-sample(result.value, result.trace, to-output-env(result.trace), result.log-weight), result.remaining-env)

pub fun lw(iterations : int, environment : env, action : model<e,a>) : <div,random|e> list<weighted-sample<a>>
  if iterations <= 0
    then []
    else Cons(run-lw(environment, action), lw(iterations - 1, environment, action))
