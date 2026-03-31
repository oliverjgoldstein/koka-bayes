module alg/lwis

import std/core/debug
import std/num/float64
import std/num/random
import alg/lw
import core/env
import core/model

pub fun lwis<a,e>(count : int, environment : env, action : model<e,a>) : <div,random|e> list<a>
  val weighted = lw(count, environment, action)
  resample-values(count, weighted)

pub fun resample-values<a>(count : int, samples : list<weighted-sample<a>>) : <div,random> list<a>
  resample-weighted(count, samples).map(fn(sample){ sample.value })

pub fun resample-weighted<a>(count : int, samples : list<weighted-sample<a>>) : <div,random> list<weighted-sample<a>>
  if count <= 0
    then []
    else
      match prepare-weights(samples)
        Nothing ->
          []
        Just(weighted) ->
          val total = weighted.foldl(0.0, fn(acc, item){ acc + fst(item) })
          Cons(draw-one(total, weighted), resample-weighted(count - 1, samples))

fun prepare-weights<a>(samples : list<weighted-sample<a>>) : maybe<list<(float64, weighted-sample<a>)>>
  val max-log = max-log-weight(samples, neginf)
  if max-log <= neginf
    then uniform-weights(samples)
    else Just(samples.map(fn(sample){ (exp(sample.log-weight - max-log), sample) }))

fun uniform-weights<a>(samples : list<weighted-sample<a>>) : maybe<list<(float64, weighted-sample<a>)>>
  match samples
    Nil -> Nothing
    _   -> Just(samples.map(fn(sample){ (1.0, sample) }))

fun max-log-weight<a>(samples : list<weighted-sample<a>>, current : float64) : float64
  match samples
    Nil -> current
    Cons(sample, rest) ->
      max-log-weight(rest, max(current, sample.log-weight))

fun draw-one<a>(total : float64, samples : list<(float64, weighted-sample<a>)>) : <div,random> weighted-sample<a>
  val threshold = random-float64() * max(1.0e-12, total)
  choose(threshold, samples)

fun choose<a>(threshold : float64, samples : list<(float64, weighted-sample<a>)>) : weighted-sample<a>
  match samples
    Cons((_, sample), Nil) ->
      sample
    Cons((weight, sample), rest) ->
      if threshold <= weight
        then sample
        else choose(threshold - weight, rest)
    Nil ->
      Weighted-sample(impossible("cannot resample from an empty weighted sample set"), [], empty(), neginf)
