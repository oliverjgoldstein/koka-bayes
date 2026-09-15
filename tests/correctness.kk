module correctness

import std/num/float64
import std/num/random
import alg/lw
import alg/lwis
import alg/mcmc
import alg/mh
import alg/pmmh
import alg/rmsmc
import alg/simulate
import alg/smc
import alg/smc2
import core/env
import core/model
import core/obsvar
import core/sequential

// These oracles use conjugacy or explicit enumeration, never inference output.
struct reference
  mean       : float64
  variance   : float64
  below-half : float64
  evidence   : float64
  final-state : float64

struct output
  parameter   : float64
  final-state : float64

struct estimate
  mean        : float64
  variance    : float64
  below-half  : float64
  evidence    : maybe<float64>
  final-state : float64

val seeds = [2027, 4093, 8191]
val coin-observation = obs-bool("correctness/coin")
val gaussian-observation = obs-float64("correctness/gaussian")
val hmm-observation = obs-bool("correctness/hmm")
val latent-observation = obs-bool("correctness/latent")

type inference-algorithm
  LikelihoodWeighting
  ResampledLikelihoodWeighting
  MetropolisHastings
  SequentialMonteCarlo
  ResampleMoveSMC
  ParticleMarginalMH
  NestedSMC

fun coin() : sequential-model<e,float64,(),bool,output>
  Sequential-model(
    fn(){ beta'(2.0, 3.0) },
    fn(_p){ () },
    fn(p, _index, _state){ Step-output((), bernoulli(coin-observation, p)) },
    fn(prefix-state){ Output(prefix-state.parameter, 0.0) })

fun gaussian() : sequential-model<e,float64,(),float64,output>
  Sequential-model(
    fn(){ normal'(0.0, 1.0) },
    fn(_p){ () },
    fn(p, _index, _state){ Step-output((), normal(gaussian-observation, p, 1.0)) },
    fn(prefix-state){ Output(prefix-state.parameter, 0.0) })

// Filtering has only a known transition matrix and a known observation model.
fun tiny-hmm() : sequential-model<e,float64,int,bool,output>
  Sequential-model(
    fn(){ 0.8 },
    fn(_p){ if bernoulli'(0.5) then 1 else 0 },
    fn(p, index, previous){
      val state =
        if index == 0 then previous
        else if bernoulli'(if previous == 1 then 0.8 else 0.2) then 1 else 0
      val observed = bernoulli(hmm-observation, if state == 1 then p else 1.0 - p)
      Step-output(state, observed)
    },
    fn(prefix-state){
      val state = float64(prefix-state.current-state)
      Output(state, state)
    })

// The smallest useful noisy-likelihood example: one binary parameter, one
// persistent binary latent variable, two observations, and no state transition.
fun latent-coin() : sequential-model<e,float64,int,bool,output>
  Sequential-model(
    fn(){ if bernoulli'(0.5) then 0.75 else 0.25 },
    fn(q){ if bernoulli'(q) then 1 else 0 },
    fn(_q, _index, state){
      Step-output(state, bernoulli(latent-observation, if state == 1 then 0.8 else 0.2))
    },
    fn(prefix-state){ Output(prefix-state.parameter, float64(prefix-state.current-state)) })

fun from-enumeration(values : list<(output,float64)>) : reference
  val summary = summarize(values, Nothing)
  Reference(summary.mean, summary.variance, summary.below-half,
            values.foldl(0.0, fn(acc, item){ acc + snd(item) }), summary.final-state)

// Enumerate the four state paths directly, without distribution-library scores.
fun hmm-reference() : reference
  val paths = [0, 1].flatmap(fn(first){
    [0, 1].map(fn(last){
      val transition = if first == last then 0.8 else 0.2
      val first-observation = if first == 1 then 0.8 else 0.2
      val last-observation = if last == 1 then 0.8 else 0.2
      (Output(float64(last), float64(last)), 0.5 * transition * first-observation * last-observation)
    })
  })
  from-enumeration(paths)

// Enumerate just four combinations: two parameter values times two latent values.
fun latent-reference() : reference
  val combinations = [0.25, 0.75].flatmap(fn(q){
    [0, 1].map(fn(state){
      val latent-probability = if state == 1 then q else 1.0 - q
      val observation = if state == 1 then 0.8 else 0.2
      (Output(q, float64(state)), 0.5 * latent-probability * observation * observation)
    })
  })
  from-enumeration(combinations)

fun summarize(values : list<(output,float64)>, evidence : maybe<float64>) : estimate
  val total = values.foldl(0.0, fn(acc, item){ acc + snd(item) })
  val mean = values.foldl(0.0, fn(acc, item){ acc + fst(item).parameter * snd(item) }) / total
  val variance = values.foldl(0.0, fn(acc, item){
    val centered = fst(item).parameter - mean
    acc + centered * centered * snd(item)
  }) / total
  val state = values.foldl(0.0, fn(acc, item){ acc + fst(item).final-state * snd(item) }) / total
  val below-half = values.foldl(0.0, fn(acc, item){
    acc + (if fst(item).parameter <= 0.5 then snd(item) else 0.0)
  }) / total
  Estimate(mean, variance, below-half, evidence, state)

fun unweighted(values : list<output>, evidence : maybe<float64> = Nothing) : estimate
  summarize(values.map(fn(value){ (value, 1.0) }), evidence)

fun weighted(values : list<weighted-sample<output>>) : estimate
  val maximum = values.foldl(neginf, fn(acc, sample){ max(acc, sample.log-weight) })
  val weights = values.map(fn(sample){ (sample.value, exp(sample.log-weight - maximum)) })
  val evidence = exp(maximum) * weights.foldl(0.0, fn(acc, item){ acc + snd(item) }) / float64(values.length)
  summarize(weights, Just(evidence))

fun filter-output(parameter : float64, estimate : smc-result<output>) : output
  val state = estimate.particles.foldl(0.0, fn(acc, particle){ acc + particle.value.final-state })
    / float64(estimate.particles.length)
  Output(parameter, state)

fun close(actual : float64, expected : float64, tolerance : float64) : bool
  // NaN and infinities fail this comparison too.
  abs(actual - expected) <= tolerance

fun report(label : string, algorithm : string, seed : int, result : estimate, truth : reference) : <console> bool
  val mean-tolerance = if label == "gaussian" then 0.10 else 0.05
  // For the binary HMM, variance is p(1-p), determined by the mean.
  // A marginal error |e| <= delta implies |variance error| <= |1-2p|*delta + delta².
  val variance-tolerance =
    if label == "gaussian" then 0.075
    elif label == "hmm" then abs(1.0 - 2.0 * truth.mean) * mean-tolerance + mean-tolerance * mean-tolerance
    else 0.015
  val cdf-tolerance = if label == "hmm" then mean-tolerance else 0.075
  val mean-ok = close(result.mean, truth.mean, mean-tolerance)
  val variance-ok = close(result.variance, truth.variance, variance-tolerance)
  val cdf-ok = close(result.below-half, truth.below-half, cdf-tolerance)
  val state-ok = close(result.final-state, truth.final-state, 0.085)
  val evidence-ok =
    match result.evidence
      Nothing -> True
      Just(z) -> close(z, truth.evidence, 0.15 * truth.evidence)
  val evidence-text = match result.evidence
    Nothing -> "NA"
    Just(z) -> z.show
  val ok = mean-ok && variance-ok && cdf-ok && state-ok && evidence-ok
  println(label ++ "," ++ algorithm ++ "," ++ seed.show ++ "," ++ result.mean.show ++ ","
    ++ result.variance.show ++ "," ++ result.below-half.show ++ "," ++ evidence-text ++ "," ++ result.final-state.show ++ ","
    ++ (if ok then "PASS" else "FAIL"))
  if !mean-ok then println("  posterior mean outside tolerance " ++ mean-tolerance.show) else ()
  if !variance-ok then println("  posterior variance outside tolerance " ++ variance-tolerance.show) else ()
  if !cdf-ok then println("  posterior CDF at 0.5 outside tolerance " ++ cdf-tolerance.show) else ()
  if !state-ok then println("  final-state marginal outside tolerance 0.085") else ()
  if !evidence-ok then println("  evidence outside relative tolerance 0.15") else ()
  ok

fun estimate-seed<s,o>(algorithm : inference-algorithm, seed : int, steps : int, environment : env,
                         spec : sequential-model<total,float64,s,o,output>) : div (string,estimate)
  // Dispatch before inference, so a selected check never runs another method.
  match algorithm
    LikelihoodWeighting ->
      val importance = pseudo-random(seed, fn(){ lw(2000, environment, as-model(steps, spec)) })
      ("LW", weighted(importance))
    ResampledLikelihoodWeighting ->
      val resampled = pseudo-random(seed, fn(){ lwis(1000, environment, as-model(steps, spec)) })
      ("LWIS", unweighted(resampled))
    MetropolisHastings ->
      val chain = pseudo-random(seed, fn(){ mh(3000, 500, environment, as-model(steps, spec)) })
      ("MH", unweighted(chain.samples.map(fn(sample){ sample.value })))
    SequentialMonteCarlo ->
      val filtered = pseudo-random(seed, fn(){ smc(800, steps, environment, spec) })
      ("SMC", unweighted(filtered.particles.map(fn(particle){ particle.value }), Just(exp(filtered.log-evidence))))
    ResampleMoveSMC ->
      val moved = pseudo-random(seed, fn(){ rmsmc(600, steps, 1, environment, spec) })
      ("RMSMC", unweighted(moved.particles.map(fn(particle){ particle.value }), Just(exp(moved.log-evidence))))
    ParticleMarginalMH ->
      val particle-chain = pseudo-random(seed, fn(){ pmmh(4, steps, default-config(1500, 300), environment, spec) })
      ("PMMH", unweighted(particle-chain.samples.map(fn(sample){ filter-output(sample.parameter, sample.estimate) })))
    NestedSMC ->
      val nested = pseudo-random(seed, fn(){ smc2(600, 4, steps, 1, environment, spec) })
      ("SMC2", unweighted(nested.particles.map(fn(particle){ filter-output(particle.parameter, particle.estimate) }),
                          Just(exp(nested.log-evidence))))

fun assess<s,o>(algorithms : list<inference-algorithm>, label : string, steps : int, environment : env,
                  spec : sequential-model<total,float64,s,o,output>, truth : reference) : <console,div> bool
  println("reference," ++ label ++ ",mean=" ++ truth.mean.show ++ ",variance=" ++ truth.variance.show
    ++ ",cdf_half=" ++ truth.below-half.show ++ ",evidence=" ++ truth.evidence.show ++ ",final-state=" ++ truth.final-state.show)
  val checks = seeds.map fn(seed){
    val results = algorithms.map(fn(algorithm){ estimate-seed(algorithm, seed, steps, environment, spec) })
    results.map(fn(item){ report(label, fst(item), seed, snd(item), truth) }).all(fn(ok){ ok })
  }
  checks.all(fn(ok){ ok })

fun assert-reference(label : string, actual : reference, expected : reference) : exn ()
  if close(actual.mean, expected.mean, 1.0e-12)
      && close(actual.variance, expected.variance, 1.0e-12)
      && close(actual.below-half, expected.below-half, 1.0e-12)
      && close(actual.evidence, expected.evidence, 1.0e-12)
      && close(actual.final-state, expected.final-state, 1.0e-12)
    then ()
    else throw("enumeration/reference mismatch for " ++ label)

fun assess-ordinary(algorithms : list<inference-algorithm>) : <console,div> bool
  // Ordered Bernoulli observations: B(5,4)/B(2,3) = 3/70 (no binomial coefficient).
  val coin-ok = assess(algorithms, "coin", 4, set(coin-observation, [True, True, True, False], empty()),
                       coin(), Reference(5.0/9.0, 20.0/810.0, 93.0/256.0, 3.0/70.0, 0.0))
  // The joint Gaussian observation covariance is [[2,1],[1,2]], determinant 3.
  val gaussian-z = exp(~1.0) / (2.0 * pi * sqrt(3.0))
  val gaussian-ok = assess(algorithms, "gaussian", 2, set(gaussian-observation, [1.0, 2.0], empty()),
                           gaussian(), Reference(1.0, 1.0/3.0, 0.19323811538561636, gaussian-z, 0.0))
  coin-ok && gaussian-ok

fun assess-filtering(algorithms : list<inference-algorithm>) : <console,exn,div> bool
  val hmm-truth = hmm-reference()
  assert-reference("hmm", hmm-truth, Reference(17.0/19.0, 34.0/361.0, 2.0/19.0, 38.0/125.0, 17.0/19.0))
  assess(algorithms, "hmm", 2, set(hmm-observation, [True, True], empty()), tiny-hmm(), hmm-truth)

fun assess-parameters(algorithms : list<inference-algorithm>) : <console,exn,div> bool
  val latent-truth = latent-reference()
  assert-reference("latent", latent-truth, Reference(83.0/136.0, 931.0/18496.0, 19.0/68.0, 17.0/50.0, 16.0/17.0))
  assess(algorithms, "latent", 2, set(latent-observation, [True, True], empty()), latent-coin(), latent-truth)

fun run-checks(ordinary : list<inference-algorithm>, filtering : list<inference-algorithm>,
               parameters : list<inference-algorithm>, completion : string) : <console,exn,div> ()
  println("model,algorithm,seed,posterior_mean,posterior_variance,cdf_half,evidence,final_state_probability,status")
  val ordinary-ok = if ordinary.is-empty then True else assess-ordinary(ordinary)
  val filtering-ok = if filtering.is-empty then True else assess-filtering(filtering)
  val parameters-ok = if parameters.is-empty then True else assess-parameters(parameters)
  if ordinary-ok && filtering-ok && parameters-ok
    then println(completion)
    else throw("inference correctness checks failed; see FAIL rows above")

pub fun test-lw() : <console,exn,div> ()
  run-checks([LikelihoodWeighting], [], [], "LW inference checks passed (6 runs).")

pub fun test-lwis() : <console,exn,div> ()
  run-checks([ResampledLikelihoodWeighting], [], [], "LWIS inference checks passed (6 runs).")

pub fun test-mh() : <console,exn,div> ()
  run-checks([MetropolisHastings], [], [], "MH inference checks passed (6 runs).")

pub fun test-smc() : <console,exn,div> ()
  run-checks([], [SequentialMonteCarlo], [], "SMC inference checks passed (3 runs).")

pub fun test-rmsmc() : <console,exn,div> ()
  run-checks([], [ResampleMoveSMC], [], "RMSMC inference checks passed (3 runs).")

pub fun test-pmmh() : <console,exn,div> ()
  run-checks([], [], [ParticleMarginalMH], "PMMH inference checks passed (3 runs).")

pub fun test-smc2() : <console,exn,div> ()
  run-checks([], [], [NestedSMC], "SMC2 inference checks passed (3 runs).")

pub fun main() : <console,exn,div> ()
  run-checks([LikelihoodWeighting, ResampledLikelihoodWeighting, MetropolisHastings],
    [SequentialMonteCarlo, ResampleMoveSMC], [ParticleMarginalMH, NestedSMC],
    "inference correctness checks passed (30 runs; 3 fixed seeds per model/algorithm)")
