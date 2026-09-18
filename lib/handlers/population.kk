module handlers/population

import std/num/float64
import std/num/random
import core/weights
import handlers/weight
import handlers/sequential

// A resampling boundary exposes its normalising constant separately from its
// equally weighted particles. Keeping these together prevents an outer inference
// layer from accidentally scoring a cumulative inner estimate more than once.
pub struct population<a>
  values       : list<a>
  log-evidence : float64

pub fun resample-population<a>(count : int,
                               values : list<a>,
                               log-weight : a -> float64) : <div,random> population<a>
  Population(resample-log-weighted(count, values, log-weight),
             log-mean-weight(values.map(log-weight)))

// Passing evidence outward is explicit: ordinary nesting leaves the outer score
// untouched, while this operation contributes one population normalizer.
pub fun push-population<a>(result : population<a>) : accumulate-weight list<a>
  push-evidence(result.log-evidence)
  result.values

pub fun add-evidence(current : float64, increment : float64) : float64
  if not(is-finite(current)) || not(is-finite(increment))
    then neginf
    else current + increment

// A dead inner filter remains dead; subtracting -infinity from -infinity must
// never manufacture a NaN weight or revive a zero-evidence outer particle.
pub fun evidence-increment(previous : float64, current : float64) : float64
  if not(is-finite(previous)) || not(is-finite(current))
    then neginf
    else current - previous

struct weighted-continuation<e,a>
  computation : suspension<e,a>
  log-weight  : float64

// Bootstrap filtering directly over suspended handler computations. Resampling
// copies continuations; scoped handlers inside them must therefore keep their
// state local to each resumption. Each checkpoint is an incremental scoring
// boundary. Finished computations are absorbing with unit incremental weight.
pub fun sample-population<a,e>(count : int,
                                action : () -> <checkpoint,accumulate-weight,div,random|e> a) : <div,random|e> population<a>
  val initial = start-continuations(count, action)
  val result = resample-population(count, initial, fn(item){ item.log-weight })
  run-population(result.values.map(fn(item){ item.computation }), result.log-evidence)

fun start-continuations<a,e>(count : int,
                              action : () -> <checkpoint,accumulate-weight,div,random|e> a) : <div,random|e> list<weighted-continuation<<accumulate-weight,div,random|e>,a>>
  if count <= 0
    then []
    else
      val (computation, weight) = handle-weight(fn(){ suspend(action) })
      Cons(Weighted-continuation(computation, weight), start-continuations(count - 1, action))

fun completed<a,e>(state : suspension<e,a>) : bool
  match state
    Completed(_) -> True
    Suspended(_) -> False

fun run-population<a,e>(states : list<suspension<<accumulate-weight,div,random|e>,a>>,
                         total-evidence : float64) : <div,random|e> population<a>
  if states.is-empty
    then Population([], neginf)
    elif states.all(completed) then
      Population(states.flatmap(fn(state){
        match state
          Completed(value) -> [value]
          Suspended(_) -> []
      }), total-evidence)
    else
      val weighted = states.map(fn(state){
        val (computation, weight) = handle-weight(fn(){ advance(state) })
        Weighted-continuation(computation, weight)
      })
      val result = resample-population(states.length, weighted, fn(item){ item.log-weight })
      run-population(result.values.map(fn(item){ item.computation }),
                       add-evidence(total-evidence, result.log-evidence))
