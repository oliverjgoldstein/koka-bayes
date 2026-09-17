module alg/mala

import std/num/float64
import std/num/random
import autodiff/smooth
import alg/gradient
import alg/mcmc

// Metropolis-adjusted Langevin: proposal mean x + eps^2/2 grad log pi(x),
// covariance eps^2 I. The reverse/forward proposal correction is essential.
pub fun mala(config : mcmc-config,
             target : forall<a> list<a> -> smooth<a> a,
             initial : list<float64>,
             step-size : float64,
             seed : int = 2027) : <div,exn> mcmc-result<list<float64>>
  validate-gradient-config(config, step-size)
  val start = initial-target(target, initial)
  val chain = pseudo-random(seed, fn(){
    mh-chain(config, scored-gradient(start), fn(current){
      val noise = normal-vector(current.value.position.length)
      val position = vector-add-scaled(mala-mean(current.value, step-size), step-size, noise)
      match evaluate-target(target, position)
        Nothing -> rejected-gradient(current)
        Just(proposed) ->
          val forward = mala-log-transition(current.value, proposed, step-size)
          val backward = mala-log-transition(proposed, current.value, step-size)
          if not(is-finite(forward)) || not(is-finite(backward))
            then rejected-gradient(current)
            else Mh-candidate(scored-gradient(proposed), backward - forward)
    })
  })
  gradient-chain-result(chain)

// Deterministic helpers expect valid equal-dimensional states and positive eps.
pub fun mala-mean(state : gradient-state, step-size : float64) : list<float64>
  state.position.zipwith(state.gradient, fn(x, g){ x + (0.5 * step-size) * (step-size * g) })

// Log Gaussian transition density up to its shared normalizing constant.
// Standardize before squaring to avoid explicitly forming eps^2.
pub fun mala-log-transition(from : gradient-state,
                            to : gradient-state,
                            step-size : float64) : float64
  val mean = mala-mean(from, step-size)
  val residual = to.position.zipwith(mean, fn(y, m){ (y - m) / step-size })
  0.0 - half-squared-norm(residual)
