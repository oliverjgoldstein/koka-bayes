module alg/gradient

import std/num/float64
import std/num/random
import autodiff/smooth
import autodiff/reverse
import alg/mcmc

// A cached evaluation belongs to its position. Rejection retains the entire state.
pub struct gradient-state
  position    : list<float64>
  log-density : float64
  gradient    : list<float64>

pub fun finite-vector(xs : list<float64>) : bool
  xs.all(is-finite)

pub fun valid-gradient-state(state : gradient-state) : bool
  not(state.position.is-empty) && state.position.length == state.gradient.length &&
    finite-vector(state.position) && is-finite(state.log-density) && finite-vector(state.gradient)

// The target is a differentiable log density on fixed-dimensional coordinates.
// Invalid proposal positions, scores and derivatives represent rejected proposals.
pub fun evaluate-target(target : forall<a> list<a> -> smooth<a> a,
                        position : list<float64>) : maybe<gradient-state>
  if position.is-empty || not(finite-vector(position))
    then Nothing
    else
      val result = value-and-grad(target, position)
      val state = Gradient-state(position, result.value, result.partials)
      if valid-gradient-state(state) then Just(state) else Nothing

pub fun initial-target(target : forall<a> list<a> -> smooth<a> a,
                       position : list<float64>) : exn gradient-state
  match evaluate-target(target, position)
    Just(state) -> state
    Nothing -> throw("Gradient inference needs a nonempty finite initial position with finite log density and gradient.")

pub fun validate-gradient-config(config : mcmc-config, step-size : float64) : exn ()
  if config.iterations <= config.burnin || config.burnin < 0
    then throw("Gradient inference needs iterations > burnin >= 0.")
    else if not(is-finite(step-size)) || step-size <= 0.0
      then throw("Gradient inference needs a finite positive step size.")
      else ()

// Internal vector arithmetic expects equal dimensions (checked at entry points).
pub fun vector-add-scaled(xs : list<float64>, scale : float64, ys : list<float64>) : list<float64>
  xs.zipwith(ys, fn(x, y){ x + scale * y })

pub fun squared-norm(xs : list<float64>) : float64
  xs.foldl(0.0, fn(total, x){ total + x*x })

// Scale each term before squaring: x*x may overflow while x*x/2 is finite.
pub fun half-squared-norm(xs : list<float64>) : float64
  xs.foldl(0.0, fn(total, x){ total + (0.5*x)*x })

pub fun kinetic-energy(momentum : list<float64>) : float64
  half-squared-norm(momentum)

// Box-Muller with U in (0,1] avoids log(0) without truncating small draws.
pub fun standard-normal() : random float64
  val u = 1.0 - random-float64()
  val angle = 6.283185307179586 * random-float64()
  sqrt(-2.0 * ln(u)) * cos(angle)

pub fun normal-vector(dimension : int) : random list<float64>
  replicate(0.0, dimension).map(fn(_){ standard-normal() })

pub fun scored-gradient(state : gradient-state) : scored<gradient-state>
  Scored(state, state.log-density)

pub fun rejected-gradient(current : scored<gradient-state>) : mh-candidate<gradient-state>
  Mh-candidate(current, neginf)

pub fun gradient-chain-result(result : mcmc-result<gradient-state>) : mcmc-result<list<float64>>
  Mcmc-result(result.samples.map(fn(state){ state.position }), result.accepted)
