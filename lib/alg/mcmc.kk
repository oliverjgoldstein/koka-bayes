module alg/mcmc

import std/num/float64
import std/num/random

pub struct mcmc-config
  iterations : int
  burnin     : int

pub struct scored<a>
  value      : a
  log-target : float64

pub struct mh-candidate<a>
  state          : scored<a>
  log-correction : float64

pub struct mcmc-result<a>
  samples   : list<a>
  accepted  : int

pub fun default-config(iterations : int, burnin : int = 0) : mcmc-config
  Mcmc-config(iterations, burnin)

pub fun mh-chain<a,e>(config : mcmc-config,
                      initial : scored<a>,
                      propose : scored<a> -> <div,random|e> mh-candidate<a>) : <div,random|e> mcmc-result<a>
  val (samples, accepted) = run-loop(config.iterations, config.burnin, initial, propose, 0, [])
  Mcmc-result(samples.reverse, accepted)

// Zero correction is valid when the score has already cancelled an independent
// proposal density (as in prior-proposal PMMH), or the proposal is symmetric.
// Other independent proposals still require an explicit MH density correction.
pub fun independent-proposal<a>(state : scored<a>) : mh-candidate<a>
  Mh-candidate(state, 0.0)

fun run-loop<a,e>(remaining : int,
                  burnin : int,
                  current : scored<a>,
                  propose : scored<a> -> <div,random|e> mh-candidate<a>,
                  accepted : int,
                  acc : list<a>) : <div,random|e> (list<a>, int)
  if remaining <= 0
    then (acc, accepted)
    else
      val candidate = propose(current)
      val log-alpha =
        candidate.state.log-target - current.log-target + candidate.log-correction
      val accept =
        if log-alpha >= 0.0
          then True
          else ln(random-float64()) < log-alpha
      val next =
        if accept
          then candidate.state
          else current
      val next-accepted =
        if accept then accepted + 1 else accepted
      val next-acc =
        if burnin > 0 || not(is-finite(next.log-target))
          then acc
          else Cons(next.value, acc)
      run-loop(remaining - 1,
               max(0, burnin - 1),
               next,
               propose,
               next-accepted,
               next-acc)
