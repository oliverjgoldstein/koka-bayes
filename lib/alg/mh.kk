module alg/mh

import std/num/float64
import std/num/random
import core/dist
import core/env
import core/model
import core/obsvalue
import core/trace
import handlers/trace

import alg/simulate

struct mh-state<a>
  current : simulate-result<a>
  logp    : float64

pub struct mh-result<a>
  samples       : list<simulate-result<a>>
  accepted      : int
  posterior-env : env

// Select a latent site, retain its prefix, and regenerate the suffix from the prior.
// The regenerated prior densities cancel against the forward/reverse proposals;
// only the observed likelihood ratio and site-selection ratio remain.
pub fun mh(iterations : int, burnin : int, environment : env, action : model<e,a>) : <div,random|e> mh-result<a>
  val initial = run-mh-proposal(environment, [], Nothing, action)
  val state0 = Mh-state(initial, observed-log-prob(initial.trace))
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
      val candidate-logp = observed-log-prob(candidate.trace)
      val current-count = max(1, sample-count(state.current.trace))
      val candidate-count = max(1, sample-count(candidate.trace))
      val log-alpha =
        candidate-logp - state.logp + ln(float64(current-count)) - ln(float64(candidate-count))
      val accept =
        if log-alpha >= 0.0
          then True
          else ln(random-float64()) < log-alpha
      val next-state =
        if accept
          then Mh-state(candidate, candidate-logp)
          else state
      val next-accepted =
        if accept then accepted + 1 else accepted
      val next-acc =
        if burnin > 0 || not(is-finite(next-state.logp))
          then acc
          else Cons(next-state.current, acc)
      val next-posterior =
        if burnin > 0 || not(is-finite(next-state.logp))
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
  val result = run-traced(environment, action, previous, proposal)
  Simulate-result(result.value, result.trace, to-output-env(result.trace))

fun choose-proposal(addresses : list<int>) : random maybe<int>
  match addresses
    Nil -> Nothing
    _   ->
      // float64.int rounds to nearest in Koka; floor preserves the uniform
      // half-open index intervals and never selects past the final address.
      val ix = int(floor(random-float64() * float64(addresses.length)))
      nth-int(ix, addresses)

fun nth-int(index : int, values : list<int>) : maybe<int>
  match values
    Nil -> Nothing
    Cons(value, rest) ->
      if index <= 0
        then Just(value)
            else nth-int(index - 1, rest)
