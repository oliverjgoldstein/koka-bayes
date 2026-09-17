module alg/hmc

import std/num/float64
import std/num/random
import autodiff/smooth
import alg/gradient
import alg/mcmc

// Fixed-step Hamiltonian Monte Carlo with unit mass and fresh normal momentum.
// iterations counts transitions, including burnin; rejected states remain draws.
pub fun hmc(config : mcmc-config,
            target : forall<a> list<a> -> smooth<a> a,
            initial : list<float64>,
            step-size : float64,
            leapfrog-steps : int,
            seed : int = 2027) : <div,exn> mcmc-result<list<float64>>
  validate-gradient-config(config, step-size)
  if leapfrog-steps <= 0 then throw("HMC needs a positive number of leapfrog steps.") else ()
  val start = initial-target(target, initial)
  val chain = pseudo-random(seed, fn(){
    mh-chain(config, scored-gradient(start), fn(current){
      val momentum = normal-vector(current.value.position.length)
      val initial-kinetic = kinetic-energy(momentum)
      match leapfrog(target, current.value, momentum, step-size, leapfrog-steps)
        Nothing -> rejected-gradient(current)
        Just((proposed, final-momentum)) ->
          // Momentum reversal makes the deterministic proposal an involution.
          // Its kinetic energy equals that of final-momentum.
          val reversed = final-momentum.map(fn(p){ 0.0 - p })
          val proposed-kinetic = kinetic-energy(reversed)
          if not(is-finite(initial-kinetic)) || not(is-finite(proposed-kinetic))
            then rejected-gradient(current)
            else Mh-candidate(scored-gradient(proposed), initial-kinetic - proposed-kinetic)
    })
  })
  gradient-chain-result(chain)

// Deterministic, reversible leapfrog trajectory, without the final momentum flip.
// A signed nonzero step permits reverse-time checks. Invalid trajectories reject.
pub fun leapfrog(target : forall<a> list<a> -> smooth<a> a,
                 initial : gradient-state,
                 momentum : list<float64>,
                 step-size : float64,
                 steps : int) : div maybe<(gradient-state,list<float64>)>
  if steps <= 0 || step-size == 0.0 || not(is-finite(step-size)) ||
     not(valid-gradient-state(initial)) || momentum.length != initial.position.length ||
     not(finite-vector(momentum))
    then Nothing
    else leapfrog-loop(target, initial, momentum, step-size, steps)

fun leapfrog-loop(target : forall<a> list<a> -> smooth<a> a,
                   current : gradient-state,
                   momentum : list<float64>,
                   step-size : float64,
                   remaining : int) : div maybe<(gradient-state,list<float64>)>
  val half-momentum = vector-add-scaled(momentum, 0.5 * step-size, current.gradient)
  val position = vector-add-scaled(current.position, step-size, half-momentum)
  if not(finite-vector(half-momentum))
    then Nothing
    else
      match evaluate-target(target, position)
        Nothing -> Nothing
        Just(next) ->
          val next-momentum = vector-add-scaled(half-momentum, 0.5 * step-size, next.gradient)
          if not(finite-vector(next-momentum))
            then Nothing
            else if remaining <= 1
              then Just((next, next-momentum))
              else leapfrog-loop(target, next, next-momentum, step-size, remaining - 1)
