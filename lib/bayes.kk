module bayes

// The single import needed by a model file. Algorithms retain their native
// results, so weighted draws and Markov-chain draws stay distinguishable.
pub import std/num/float64
pub import core/model
pub import core/obsvar
pub import core/env
pub import alg/lw
pub import alg/lwis
pub import alg/mh

import std/num/random
import core/weights
import alg/simulate

// Independent prior draws, weighted by the observed likelihood.
pub fun likelihood-weighting(draws : int, observations : env,
                             action : model<<exn|e>,a>, seed : int = 2027) : <div,exn|e> list<weighted-sample<a>>
  if draws <= 0
    then throw("Likelihood weighting needs a positive number of draws.")
    else pseudo-random(seed, fn(){ lw(draws, observations, action) })

// Resample likelihood-weighted draws into an equally weighted population.
pub fun likelihood-weighting-resampled(draws : int, observations : env,
                                       action : model<<exn|e>,a>, seed : int = 2027) : <div,exn|e> list<a>
  if draws <= 0
    then throw("Likelihood weighting needs a positive number of draws.")
    else pseudo-random(seed, fn(){ lwis(draws, observations, action) })

// iterations includes burnin; the retained chain has iterations - burnin draws
// when its states have finite likelihood. Consecutive draws can be correlated.
pub fun metropolis-hastings(iterations : int, burnin : int, observations : env,
                            action : model<<exn|e>,a>, seed : int = 2027) : <div,exn|e> mh-result<a>
  if burnin < 0 || iterations <= burnin
    then throw("Metropolis-Hastings needs iterations > burnin >= 0.")
    else pseudo-random(seed, fn(){ mh(iterations, burnin, observations, action) })

// Normalize log weights before computing the expectation. An impossible or
// empty population has no posterior mean and must not become a uniform one.
pub fun weighted/posterior-mean(samples : list<weighted-sample<float64>>) : exn float64
  match normalized-log-weights(samples.map(fn(sample){ sample.log-weight }))
    Nothing -> throw("No finite positive posterior mass; check the model, data, and inference budget.")
    Just(weights) ->
      val mean = zip(samples, weights).foldl(0.0, fn(acc, item){
        val (sample, weight) = item
        if weight <= 0.0 then acc else acc + sample.value * weight
      })
      checked-mean(mean)

// Resampled particles and retained MH states are equally weighted here.
pub fun draws/posterior-mean(samples : list<float64>) : exn float64
  if samples.is-empty
    then throw("No posterior draws; check the model, data, and inference budget.")
    else
      val count = float64(samples.length)
      checked-mean(samples.foldl(0.0, fn(acc, value){ acc + value / count }))

pub fun chain/posterior-mean(result : mh-result<float64>) : exn float64
  posterior-mean(result.samples.map(fn(sample){ sample.value }))

fun checked-mean(value : float64) : exn float64
  if is-finite(value) then value else throw("Posterior mean is not finite.")
