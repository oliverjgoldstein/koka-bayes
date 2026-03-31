module core/trace

import std/num/float64
import core/dist
import core/env
import core/obsvalue

pub type trace-mode
  TraceSampled
  TraceObserved

pub struct trace-entry
  address    : int
  site       : string
  observable : maybe<string>
  value      : observable
  log-prob   : float64
  mode       : trace-mode

pub alias run-trace = list<trace-entry>

pub fun empty-trace() : run-trace
  []

pub fun make-entry(address : int, observable : maybe<string>, distribution : dist, value : observable, mode : trace-mode) : <div> trace-entry
  Trace-entry(address, distribution.summary, observable, value, log-prob(distribution, value), mode)

pub fun total-log-prob(trace : run-trace) : float64
  trace.foldl(0.0, fn(acc, entry){ acc + entry.log-prob })

pub fun observed-log-prob(trace : run-trace) : float64
  trace.foldl(0.0, fn(acc, entry){
    match entry.mode
      TraceObserved -> acc + entry.log-prob
      TraceSampled  -> acc
  })

pub fun sample-count(trace : run-trace) : int
  trace.foldl(0, fn(acc, entry){
    match entry.mode
      TraceSampled -> acc + 1
      TraceObserved -> acc
  })

pub fun sampled-addresses(trace : run-trace) : list<int>
  trace.flatmap(fn(entry){
    match entry.mode
      TraceSampled -> [entry.address]
      TraceObserved -> []
  })

pub fun lookup-sampled(target : int, trace : run-trace) : maybe<observable>
  match trace
    Nil -> Nothing
    Cons(entry, rest) ->
      match entry.mode
        TraceObserved -> lookup-sampled(target, rest)
        TraceSampled ->
          if entry.address == target
            then Just(entry.value)
            else lookup-sampled(target, rest)

pub fun to-output-env(trace : run-trace) : env
  trace.foldl(empty(), fn(acc, entry){
    match entry.observable
      Just(name) -> append-raw(name, entry.value, acc)
      Nothing    -> acc
  })

pub fun append-trace(left : run-trace, right : run-trace) : run-trace
  val offset = left.length
  left ++ right.map(fn(entry){ shift-entry(offset, entry) })

pub fun show-entry(entry : trace-entry) : string
  val mode =
    match entry.mode
      TraceSampled -> "sample"
      TraceObserved -> "observe"
  val name =
    match entry.observable
      Just(obs) -> obs
      Nothing   -> "-"
  "{addr=" ++ entry.address.show ++
  ", mode=" ++ mode ++
  ", obs=" ++ name ++
  ", site=" ++ entry.site ++
  ", value=" ++ show-obsvalue(entry.value) ++
  ", lp=" ++ entry.log-prob.show ++ "}"

pub fun show(trace : run-trace) : string
  "[" ++ trace.map(show-entry).join(", ") ++ "]"

fun shift-entry(offset : int, entry : trace-entry) : trace-entry
  Trace-entry(entry.address + offset,
              entry.site,
              entry.observable,
              entry.value,
              entry.log-prob,
              entry.mode)
