module alg/enumerate

import std/num/float64
import std/num/random
import core/env
import core/model
import core/trace
import handlers/enumerate

pub struct enumeration-outcome<a>
  value : a
  probability : float64
  log-probability : float64
  log-weight : float64
  trace : run-trace
  output-env : env

pub struct enumeration-result<a>
  outcomes : list<enumeration-outcome<a>>
  log-evidence : float64
  executions : int
  nodes : int

pub struct enumerated-value<a>
  value : a
  probability : float64
  log-probability : float64

fun log-add(left : float64, right : float64) : float64
  if left == neginf then right
  elif right == neginf then left
  else
    val largest = max(left, right)
    largest + ln1p(exp(min(left, right) - largest))

// Enumerate every positive-mass path or fail. Outcomes retain individual traces;
// marginal/probability combine paths with the same user-visible returned value.
pub fun enumerate(environment : env, action : model<<random,exn|e>,a>,
                    max-nodes : int = 100000) : <div,exn|e> enumeration-result<a>
  val (paths, nodes) = enumerate-paths(environment, action, max-nodes)
  val largest = paths.foldl(neginf, fn(acc, path){ max(acc, path.log-weight) })
  val centered-total = paths.foldl(neginf, fn(acc, path){ log-add(acc, path.log-weight - largest) })
  val evidence = if paths.is-empty then neginf else largest + centered-total
  if evidence != neginf && not(is-finite(evidence)) then throw("Finite enumeration evidence overflowed.")
  val outcomes = paths.map fn(path){
    // Center before normalizing: subtracting the rounded evidence can lose the
    // normalization term when all paths have a large common log score.
    val logp = (path.log-weight - largest) - centered-total
    Enumeration-outcome(path.value, exp(logp), logp, path.log-weight, path.trace, to-output-env(path.trace))
  }
  Enumeration-result(outcomes, evidence, paths.length, nodes)

fun require-posterior(result : enumeration-result<a>) : exn ()
  if result.outcomes.is-empty then throw("There is no finite positive posterior mass.")

pub fun probability(result : enumeration-result<a>, predicate : a -> bool) : exn float64
  require-posterior(result)
  val mass = result.outcomes.foldl(neginf, fn(acc, outcome){
    if predicate(outcome.value) then log-add(acc, outcome.log-probability) else acc
  })
  exp(mass)

pub fun expectation(result : enumeration-result<a>, project : a -> float64) : exn float64
  require-posterior(result)
  val (positive, negative) = result.outcomes.foldl((neginf,neginf), fn(acc, outcome){
    val value = project(outcome.value)
    if not(is-finite(value)) then throw("Enumeration expectation requires finite projected values.")
    val contribution = outcome.log-probability + ln(abs(value))
    if value > 0.0 then (log-add(fst(acc), contribution), snd(acc))
    elif value < 0.0 then (fst(acc), log-add(snd(acc), contribution))
    else acc
  })
  val expected = if positive == negative then 0.0
                 elif positive > negative then exp(positive) * ~expm1(negative - positive)
                 else ~exp(negative) * ~expm1(positive - negative)
  if not(is-finite(expected)) then throw("Enumeration expectation overflowed.")
  expected

fun insert-value(item-value : a, logp : float64, values : list<enumerated-value<a>>,
                   equal : (a,a) -> bool) : list<enumerated-value<a>>
  match values
    Nil -> [Enumerated-value(item-value, exp(logp), logp)]
    Cons(first, rest) ->
      if equal(item-value, first.value)
        then
          val combined = log-add(logp, first.log-probability)
          Cons(Enumerated-value(first.value, exp(combined), combined), rest)
        else Cons(first, insert-value(item-value, logp, rest, equal))

// The equality function makes aggregation available for arbitrary model values.
pub fun marginal(result : enumeration-result<a>, equal : (a,a) -> bool) : exn list<enumerated-value<a>>
  require-posterior(result)
  result.outcomes.foldl([], fn(acc, outcome){ insert-value(outcome.value, outcome.log-probability, acc, equal) })
