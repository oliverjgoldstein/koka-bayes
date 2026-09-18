module alg/simulate

import std/num/random
import core/dist
import core/env
import core/model
import core/trace
import handlers/trace

pub struct simulate-result<a>
  value      : a
  trace      : run-trace
  output-env : env

// Simulation reifies the same trace while leaving the caller to use its score.
pub fun simulate(environment : env, action : model<e,a>) : <div,random|e> simulate-result<a>
  fst(simulate-state(environment, action))

pub fun simulate-state(environment : env, action : model<e,a>) : <div,random|e> (simulate-result<a>,env)
  val result = run-traced(environment, action)
  (Simulate-result(result.value, result.trace, to-output-env(result.trace)), result.remaining-env)
