module core/weights

import std/num/float64
import std/num/random

// A population without finite positive mass has no empirical posterior.
// In particular, impossible observations must never become uniform weights.
pub fun normalized-log-weights(weights : list<float64>) : maybe<list<float64>>
  if weights.is-empty || weights.any(fn(weight){ is-nan(weight) || weight == posinf })
    then Nothing
    else
      val largest = weights.foldl(neginf, fn(acc, weight){ max(acc, weight) })
      if largest == neginf
        then Nothing
        else
          val scaled = weights.map(fn(weight){ exp(weight - largest) })
          val total = scaled.foldl(0.0, fn(acc, weight){ acc + weight })
          Just(scaled.map(fn(weight){ weight / total }))

pub fun log-mean-weight(weights : list<float64>) : float64
  match normalized-log-weights(weights)
    Nothing -> neginf
    Just(_) ->
      val largest = weights.foldl(neginf, fn(acc, weight){ max(acc, weight) })
      val total = weights.foldl(0.0, fn(acc, weight){ acc + exp(weight - largest) })
      largest + ln(total) - ln(float64(weights.length))

pub fun resample-log-weighted<a>(count : int,
                                 values : list<a>,
                                 log-weight : a -> float64) : <div,random> list<a>
  if count <= 0
    then []
    else
      match normalized-log-weights(values.map(log-weight))
        Nothing -> []
        Just(weights) -> draw-many(count, zip(weights, values).filter(fn(item){ fst(item) > 0.0 }))

fun draw-many<a>(count : int, weighted : list<(float64,a)>) : <div,random> list<a>
  if count <= 0
    then []
    else Cons(choose(random-float64(), weighted), draw-many(count - 1, weighted))

fun choose<a>(threshold : float64, weighted : list<(float64,a)>) : a
  match weighted
    Cons((weight, value), rest) ->
      if threshold < weight || (weight > 0.0 && rest.is-empty)
        then value
        else choose(threshold - weight, rest)
    Nil -> impossible("cannot draw from a population without positive weight")
