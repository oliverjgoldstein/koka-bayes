module alg/pmmh

import std/num/float64
import std/num/random

import alg/mcmc
import alg/simulate
import alg/smc
import core/env
import core/sequential
import core/trace

pub struct pmmh-sample<p,a>
  parameter     : p
  parameter-env : env
  estimate      : smc-result<a>
  log-evidence  : float64

pub struct pmmh-result<p,a>
  samples       : list<pmmh-sample<p,a>>
  accepted      : int
  posterior-env : env

pub fun pmmh<p,s,o,a,e>(particle-count : int,
                        steps : int,
                        config : mcmc-config,
                        environment : env,
                        spec : sequential-model<e,p,s,o,a>) : <div,random|e> pmmh-result<p,a>
  if particle-count <= 0 || config.iterations <= 0
    then Pmmh-result([], 0, empty())
    else
      // The sampled parameter prior cancels against its independent proposal.
      // Observed sites inside that prior remain part of the target likelihood.
      val initial = prior-proposal(particle-count, steps, environment, spec)
      val chain = mh-chain(config, initial, fn(_current){
        independent-proposal(prior-proposal(particle-count, steps, environment, spec))
      })
      finish-chain(chain)

fun prior-proposal<p,s,o,a,e>(particle-count : int,
                              steps : int,
                              environment : env,
                              spec : sequential-model<e,p,s,o,a>) : <div,random|e> scored<pmmh-sample<p,a>>
  val parameter = simulate(environment, prior(spec))
  val estimate = smc-given(particle-count, steps, environment, parameter.value, spec)
  val sample = Pmmh-sample(parameter.value, parameter.output-env, estimate, estimate.log-evidence)
  Scored(sample, observed-log-prob(parameter.trace) + estimate.log-evidence)

// Custom kernels must supply log q(current | proposed) - log q(proposed | current).
// parameter-score supplies every parameter-level target factor, including prior
// density and any observations made by prior(spec); the filter scores later sites.

pub fun pmmh-with<p,s,o,a,e>(particle-count : int,
                             steps : int,
                             config : mcmc-config,
                             environment : env,
                             spec : sequential-model<e,p,s,o,a>,
                             parameter-score : p -> <div,random|e> float64,
                             parameter-kernel : p -> <div,random|e> (p, env, float64)) : <div,random|e> pmmh-result<p,a>
  if particle-count <= 0 || config.iterations <= 0
    then Pmmh-result([], 0, empty())
    else
      val initial = initialise-state(particle-count, steps, environment, spec, parameter-score)
      val chain = mh-chain(config, initial, fn(current){
        propose-state(particle-count, steps, environment, spec, parameter-score, parameter-kernel, current)
      })
      finish-chain(chain)

fun finish-chain<p,a>(chain : mcmc-result<pmmh-sample<p,a>>) : pmmh-result<p,a>
  val posterior : env = chain.samples.foldl(empty(), fn(acc, sample){
    merge(acc, merge(sample.parameter-env, sample.estimate.posterior-env))
  })
  Pmmh-result(chain.samples, chain.accepted, posterior)

fun initialise-state<p,s,o,a,e>(particle-count : int,
                                steps : int,
                                environment : env,
                                spec : sequential-model<e,p,s,o,a>,
                                parameter-score : p -> <div,random|e> float64) : <div,random|e> scored<pmmh-sample<p,a>>
  best-initial-state(max(4, min(12, particle-count / 8)),
                     particle-count,
                     steps,
                     environment,
                     spec,
                     parameter-score,
                     Nothing)

fun propose-state<p,s,o,a,e>(particle-count : int,
                             steps : int,
                             environment : env,
                             spec : sequential-model<e,p,s,o,a>,
                             parameter-score : p -> <div,random|e> float64,
                             parameter-kernel : p -> <div,random|e> (p, env, float64),
                             current : scored<pmmh-sample<p,a>>) : <div,random|e> mh-candidate<pmmh-sample<p,a>>
  val (parameter, parameter-env, log-correction) = parameter-kernel(current.value.parameter)
  val estimate = smc-given(particle-count, steps, environment, parameter, spec)
  val sample = Pmmh-sample(parameter, parameter-env, estimate, estimate.log-evidence)
  Mh-candidate(Scored(sample, parameter-score(parameter) + estimate.log-evidence), log-correction)

fun best-initial-state<p,s,o,a,e>(remaining : int,
                                  particle-count : int,
                                  steps : int,
                                  environment : env,
                                  spec : sequential-model<e,p,s,o,a>,
                                  parameter-score : p -> <div,random|e> float64,
                                  current : maybe<scored<pmmh-sample<p,a>>>) : <div,random|e> scored<pmmh-sample<p,a>>
  if remaining <= 0
    then
      match current
        Just(best) -> best
        Nothing    -> impossible("PMMH initialization requires at least one attempt")
    else
      val proposal = simulate(environment, prior(spec))
      val estimate = smc-given(particle-count, steps, environment, proposal.value, spec)
      val sample = Pmmh-sample(proposal.value, proposal.output-env, estimate, estimate.log-evidence)
      val scored-sample = Scored(sample, parameter-score(proposal.value) + estimate.log-evidence)
      val next =
        match current
          Nothing -> Just(scored-sample)
          Just(best) ->
            if scored-sample.log-target >= best.log-target
              then Just(scored-sample)
              else current
      best-initial-state(remaining - 1, particle-count, steps, environment, spec, parameter-score, next)
