module alg/mh

import std/num/float64
import std/num/random
import std/core/unsafe
import core/dist
import core/env
import core/model
import core/obsvalue
import core/trace
import handlers/core

import alg/simulate

struct mh-state<a>
  current : simulate-result<a>
  logp    : float64

pub struct mh-result<a>
  samples       : list<simulate-result<a>>
  accepted      : int
  posterior-env : env

noinline val mh-address : ref<global,int> = unsafe-total{ ref(0) }
noinline val mh-trace   : ref<global,run-trace> = unsafe-total{ ref([]) }
noinline val mh-diverged : ref<global,bool> = unsafe-total{ ref(False) }

// A lightweight single-site MH runner over reusable sample traces.
pub fun mh(iterations : int, burnin : int, environment : env, action : model<e,a>) : <div,random|e> mh-result<a>
  val initial = run-mh-proposal(environment, [], Nothing, action)
  val state0 = Mh-state(initial, total-log-prob(initial.trace))
  val (samples, accepted, posterior) = mh-loop(iterations, burnin, environment, action, state0, 0, [], empty())
  Mh-result(samples.reverse, accepted, posterior)

fun mh-loop(iterations : int,
            burnin : int,
            environment : env,
            action : model<e,a>,
            state : mh-state<a>,
            accepted : int,
            acc : list<simulate-result<a>>,
            posterior : env) : <div,random|e> (list<simulate-result<a>>, int, env)
  if iterations <= 0
    then (acc, accepted, posterior)
    else
      val addresses = sampled-addresses(state.current.trace)
      val proposal = choose-proposal(addresses)
      val candidate = run-mh-proposal(environment, state.current.trace, proposal, action)
      val candidate-logp = total-log-prob(candidate.trace)
      val current-count = max(1, sample-count(state.current.trace))
      val candidate-count = max(1, sample-count(candidate.trace))
      val log-alpha =
        candidate-logp - state.logp + ln(float64(current-count)) - ln(float64(candidate-count))
      val accept =
        if log-alpha >= 0.0
          then True
          else ln(max(1.0e-12, random-float64())) < log-alpha
      val next-state =
        if accept
          then Mh-state(candidate, candidate-logp)
          else state
      val next-accepted =
        if accept then accepted + 1 else accepted
      val next-acc =
        if burnin > 0
          then acc
          else Cons(next-state.current, acc)
      val next-posterior =
        if burnin > 0
          then posterior
          else merge(posterior, next-state.current.output-env)
      mh-loop(iterations - 1,
              max(0, burnin - 1),
              environment,
              action,
              next-state,
              next-accepted,
              next-acc,
              next-posterior)

fun run-mh-proposal(environment : env,
                    previous : run-trace,
                    proposal : maybe<int>,
                    action : model<e,a>) : <div,random|e> simulate-result<a>
  unsafe-total(fn(){ mh-address := 0; mh-trace := []; mh-diverged := False })
  with val sample-hook = fn(observable, distribution)
    val address = unsafe-total(fn(){ !mh-address })
    val value = choose-sample(address, proposal, previous, distribution)
    val entry = make-entry(address, observable, distribution, value, TraceSampled)
    unsafe-total(fn(){ mh-address := address + 1; mh-trace := !mh-trace ++ [entry] })
    value
  with val observe-hook = fn(name, distribution, value)
    val address = unsafe-total(fn(){ !mh-address })
    val entry = make-entry(address, Just(name), distribution, value, TraceObserved)
    unsafe-total(fn(){ mh-address := address + 1; mh-trace := !mh-trace ++ [entry] })
    value
  val value = handle-core(environment, action)
  val trace = unsafe-total(fn(){ !mh-trace })
  val output = to-output-env(trace)
  Simulate-result(value, trace, output)

fun choose-proposal(addresses : list<int>) : random maybe<int>
  match addresses
    Nil -> Nothing
    _   ->
      val ix = int(random-float64() * float64(addresses.length))
      nth-int(ix, addresses)

fun nth-int(index : int, values : list<int>) : maybe<int>
  match values
    Nil -> Nothing
    Cons(value, rest) ->
      if index <= 0
        then Just(value)
        else nth-int(index - 1, rest)

fun choose-sample(address : int,
                  proposal : maybe<int>,
                  previous : run-trace,
                  distribution : dist) : <div,random> observable
  val diverged = unsafe-total(fn(){ !mh-diverged })
  if diverged
    then sample(distribution)
    else
      match proposal
        Just(ix) ->
          if address < ix
            then
              match lookup-sampled(address, previous)
                Just(value) -> value
                Nothing ->
                  unsafe-total(fn(){ mh-diverged := True })
                  sample(distribution)
            elif address == ix
              then
                unsafe-total(fn(){ mh-diverged := True })
                sample(distribution)
              else
                unsafe-total(fn(){ mh-diverged := True })
                sample(distribution)
        Nothing ->
          match lookup-sampled(address, previous)
            Just(value) -> value
            Nothing     -> sample(distribution)
