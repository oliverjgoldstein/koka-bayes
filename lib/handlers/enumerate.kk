module handlers/enumerate

import std/num/float64
import std/num/random
import core/dist
import core/env
import core/finite
import core/model
import core/obsvalue
import core/trace
import handlers/read
import handlers/trace
import handlers/weight

// The public model operations remain tail-resumptive. This private effect
// introduces branching behind their interpretation without changing model code.
effect enumeration-control
  ctl choose-finite(distribution : dist) : observable
  ctl discard-branch() : ()
  fun count-operation() : ()

pub struct enumeration-path<a>
  value : a
  trace : run-trace
  remaining-env : env
  log-weight : float64

// State is outside the branching handler, so every resumed branch consumes
// the SAME work budget. Reader, trace and weight state sit inside it instead.
fun explore(action : () -> <enumeration-control,div,exn|e> a,
              max-nodes : int) : <div,exn|e> (list<(a,float64)>,int)
  var nodes := 0
  val tick = fn(){
    if nodes >= max-nodes then throw("Finite enumeration exceeded max-nodes; no exact result was returned.")
    nodes := nodes + 1
  }
  val paths = handle(action)
    return(value) [(value, 0.0)]
    fun count-operation() tick()
    ctl discard-branch() []
    ctl choose-finite(distribution)
      tick()
      // Each support alternative will consume at least one more work unit.
      val choices = finite-support(distribution, max-nodes - nodes)
      choices.flatmap fn(choice){
        tick()
        val suffixes = resume(choice.value)
        suffixes.map(fn(item){ (fst(item), choice.log-probability + snd(item)) })
      }
  (paths, nodes)

// A specialized interpretation of the shared weight effect validates factors,
// counts observed/factor sites, and stops a zero-mass branch immediately.
fun exact-weight(action : () -> <accumulate-weight,enumeration-control,exn|e> a) : <enumeration-control,exn|e> (a,float64)
  var weight := 0.0
  with fun accumulate-weight(increment)
    count-operation()
    if increment == neginf
      then discard-branch()
      elif not(is-finite(increment)) then throw("Finite enumeration requires finite log scores or negative infinity.")
      else
        weight := weight + increment
        if not(is-finite(weight)) then throw("Finite enumeration log weight overflowed.")
  val value = action()
  (value, weight)

fun finite-sampling(action : () -> <sample-value,enumeration-control,div,exn|e> a) : <enumeration-control,div,exn|e> a
  with fun sample-value(_address, distribution)
    choose-finite(distribution)
  action()

fun validate(distribution : dist) : exn ()
  if not(is-valid(distribution)) then throw("Finite enumeration received invalid distribution parameters: " ++ distribution.summary)

// Same consume-once observation semantics as handle-core, with strict parameter
// validation for observed as well as latent distributions. Observed continuous
// distributions are scored normally and never sent to the finite-support handler.
fun exact-core(environment : env, action : model<<exn|e>,a>) : <sample-hook,observe-hook,factor-hook,div,exn|e> (a,env)
  handle-read-state(environment, fn(){
    handle(fn(){
      mask<sample-hook>{ mask<observe-hook>{ mask<factor-hook>{ action() } } }
    })
      return(value) value
      fun draw(distribution)
        validate(distribution)
        sample-hook(Nothing, distribution)
      fun draw-observable(name, distribution)
        validate(distribution)
        match read-observation(name)
          Nothing -> sample-hook(Just(name), distribution)
          Just(value) -> observe-hook(name, distribution, value)
      fun factor(log-weight)
        factor-hook(log-weight)
  })

pub fun enumerate-paths(environment : env, action : model<<random,exn|e>,a>,
                         max-nodes : int) : <div,exn|e> (list<enumeration-path<a>>,int)
  if max-nodes <= 0 then throw("Finite enumeration needs a positive max-nodes budget.")
  // A model must express all randomness through model distribution operations.
  // Reject raw random calls instead of silently producing an approximate result.
  with fun random-int32()
    throw("Finite enumeration cannot use untraced randomness.")
  val (weighted-paths, nodes) = explore(fn(){
    exact-weight(fn(){
      finite-sampling(fn(){
        handle-trace(fn(){
          mask<sample-value>{ mask<accumulate-weight>{ mask<enumeration-control>{ exact-core(environment, action) } } }
        })
      })
    })
  }, max-nodes)
  val paths = weighted-paths.map fn(item){
    val ((((value, remaining), entries), observation-weight), prior-weight) = item
    val joint = prior-weight + observation-weight
    if not(is-finite(joint)) then throw("Finite enumeration joint log weight overflowed.")
    Enumeration-path(value, entries, remaining, joint)
  }
  (paths, nodes)
