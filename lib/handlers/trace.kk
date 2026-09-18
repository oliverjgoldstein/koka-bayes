module handlers/trace

import std/num/random
import std/num/float64
import core/dist
import core/env
import core/model
import core/obsvalue
import core/trace
import handlers/core
import handlers/weight

pub effect fun sample-value(address : int, distribution : dist) : observable

pub struct traced-result<a>
  value : a
  trace : run-trace
  log-weight : float64
  remaining-env : env

// Trace construction is separate from sample selection and weight accumulation.
// Scoped state avoids heap cells shared by multi-shot continuation branches.
pub fun handle-trace(action : () -> <sample-hook,observe-hook,factor-hook,sample-value,accumulate-weight,div|e> a) : <sample-value,accumulate-weight,div|e> (a,run-trace)
  var address := 0
  var entries := []
  with fun sample-hook(name, distribution)
    val value = sample-value(address, distribution)
    entries := entries ++ [make-entry(address, name, distribution, value, TraceSampled)]
    address := address + 1
    value
  with fun observe-hook(name, distribution, value)
    val entry = make-entry(address, Just(name), distribution, value, TraceObserved)
    entries := entries ++ [entry]
    address := address + 1
    accumulate-weight(entry.log-prob)
    value
  with fun factor-hook(log-weight)
    entries := entries ++ [make-factor-entry(address, log-weight)]
    address := address + 1
    accumulate-weight(log-weight)
  val result = action()
  (result, entries)

pub fun handle-sampling(action : () -> <sample-value,div,random|e> a) : <div,random|e> a
  with fun sample-value(_address, distribution)
    sample(distribution)
  action()

// Reuse a trace prefix; after the selected site, regenerate every latent choice.
pub fun handle-replay(previous : run-trace, proposal : maybe<int>,
                      action : () -> <sample-value,div,random|e> a) : <div,random|e> a
  var diverged := False
  with fun sample-value(address, distribution)
    if diverged
      then sample(distribution)
      else
        match proposal
          Just(index) ->
            if address >= index
              then
                diverged := True
                sample(distribution)
              else
                match lookup-sampled(address, previous)
                  Just(value) -> value
                  Nothing ->
                    diverged := True
                    sample(distribution)
          Nothing ->
            match lookup-sampled(address, previous)
              Just(value) -> value
              Nothing -> sample(distribution)
  action()

pub fun run-traced(environment : env, action : model<e,a>,
                    previous : run-trace = [], proposal : maybe<int> = Nothing) : <div,random|e> traced-result<a>
  val (((result, remaining), entries), weight) = handle-weight(fn(){
    handle-replay(previous, proposal, fn(){
      handle-trace(fn(){
        mask<sample-value>{ mask<accumulate-weight>{ handle-core-state(environment, action) } }
      })
    })
  })
  Traced-result(result, entries, weight, remaining)
