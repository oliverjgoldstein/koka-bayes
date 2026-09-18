module alg/pmmh

import std/num/float64
import std/num/random

import alg/mcmc
import alg/parameter
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

struct retained-parameter<p,a>
  sample        : pmmh-sample<p,a>
  remaining-env : env

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
  val (parameter, after-prior) = simulate-state(environment, prior(spec))
  val estimate = smc-given(particle-count, steps, after-prior, parameter.value, spec)
  val sample = Pmmh-sample(parameter.value, parameter.output-env, estimate, estimate.log-evidence)
  Scored(sample, observed-log-prob(parameter.trace) + estimate.log-evidence)

// Custom kernels must supply log q(current | proposed) - log q(proposed | current).
// parameter-score supplies every parameter-level target factor, including prior
// density and any observations made by prior(spec); the filter scores later sites.
// The supplied score must be deterministic for a fixed parameter. Its effect row
// does not make arbitrary random log scores or changing external state valid.
// This compatibility API requires the prior to consume a fixed observation
// prefix for every parameter. Use pmmh-with-state for parameter-dependent cursors.

pub fun pmmh-with<p,s,o,a,e>(particle-count : int,
                             steps : int,
                             config : mcmc-config,
                             environment : env,
                             spec : sequential-model<e,p,s,o,a>,
                             parameter-score : p -> <div,random|e> float64,
                             parameter-kernel : p -> <div,random|e> (p, env, float64)) : <div,random|e> pmmh-result<p,a>
  pmmh-engine(particle-count, steps, config, environment, spec, parameter-score,
    fn(parameter, remaining){
      val (proposed, output, correction) = parameter-kernel(parameter)
      Parameter-proposal(proposed, output, remaining, correction)
    })

pub fun pmmh-with-state<p,s,o,a,e>(particle-count : int,
                                   steps : int,
                                   config : mcmc-config,
                                   environment : env,
                                   spec : sequential-model<e,p,s,o,a>,
                                   parameter-score : p -> <div,random|e> float64,
                                   parameter-kernel : p -> <div,random|e> parameter-proposal<p>) : <div,random|e> pmmh-result<p,a>
  pmmh-engine(particle-count, steps, config, environment, spec, parameter-score,
    fn(parameter, _remaining){ parameter-kernel(parameter) })

fun pmmh-engine<p,s,o,a,e>(particle-count : int,
                            steps : int,
                            config : mcmc-config,
                            environment : env,
                            spec : sequential-model<e,p,s,o,a>,
                            parameter-score : p -> <div,random|e> float64,
                            parameter-kernel : (p,env) -> <div,random|e> parameter-proposal<p>) : <div,random|e> pmmh-result<p,a>
  if particle-count <= 0 || config.iterations <= 0
    then Pmmh-result([], 0, empty())
    else
      val initial = initialise-state(particle-count, steps, environment, spec, parameter-score)
      val chain = mh-chain(config, initial, fn(current){
        propose-state(particle-count, steps, spec, parameter-score, parameter-kernel, current)
      })
      finish-chain(Mcmc-result(chain.samples.map(fn(state){ state.sample }), chain.accepted))

fun finish-chain<p,a>(chain : mcmc-result<pmmh-sample<p,a>>) : pmmh-result<p,a>
  val posterior : env = chain.samples.foldl(empty(), fn(acc, sample){
    merge(acc, merge(sample.parameter-env, sample.estimate.posterior-env))
  })
  Pmmh-result(chain.samples, chain.accepted, posterior)

fun initialise-state<p,s,o,a,e>(particle-count : int,
                                steps : int,
                                environment : env,
                                spec : sequential-model<e,p,s,o,a>,
                                parameter-score : p -> <div,random|e> float64) : <div,random|e> scored<retained-parameter<p,a>>
  best-initial-state(max(4, min(12, particle-count / 8)),
                     particle-count,
                     steps,
                     environment,
                     spec,
                     parameter-score,
                     Nothing)

fun propose-state<p,s,o,a,e>(particle-count : int,
                             steps : int,
                             spec : sequential-model<e,p,s,o,a>,
                             parameter-score : p -> <div,random|e> float64,
                             parameter-kernel : (p,env) -> <div,random|e> parameter-proposal<p>,
                             current : scored<retained-parameter<p,a>>) : <div,random|e> mh-candidate<retained-parameter<p,a>>
  val proposal = parameter-kernel(current.value.sample.parameter, current.value.remaining-env)
  val estimate = smc-given(particle-count, steps, proposal.remaining-env, proposal.parameter, spec)
  val sample = Pmmh-sample(proposal.parameter, proposal.parameter-env, estimate, estimate.log-evidence)
  val state = Retained-parameter(sample, proposal.remaining-env)
  Mh-candidate(Scored(state, parameter-score(proposal.parameter) + estimate.log-evidence), proposal.log-correction)

fun best-initial-state<p,s,o,a,e>(remaining : int,
                                  particle-count : int,
                                  steps : int,
                                  environment : env,
                                  spec : sequential-model<e,p,s,o,a>,
                                  parameter-score : p -> <div,random|e> float64,
                                  current : maybe<scored<retained-parameter<p,a>>>) : <div,random|e> scored<retained-parameter<p,a>>
  if remaining <= 0
    then
      match current
        Just(best) -> best
        Nothing    -> impossible("PMMH initialization requires at least one attempt")
    else
      val (proposal, after-prior) = simulate-state(environment, prior(spec))
      val estimate = smc-given(particle-count, steps, after-prior, proposal.value, spec)
      val sample = Pmmh-sample(proposal.value, proposal.output-env, estimate, estimate.log-evidence)
      val scored-sample = Scored(Retained-parameter(sample, after-prior), parameter-score(proposal.value) + estimate.log-evidence)
      val next =
        match current
          Nothing -> Just(scored-sample)
          Just(best) ->
            if scored-sample.log-target >= best.log-target
              then Just(scored-sample)
              else current
      best-initial-state(remaining - 1, particle-count, steps, environment, spec, parameter-score, next)
