module sir_inference

import std/num/float64
import std/num/random
import alg/mcmc
import alg/pmmh
import alg/smc
import alg/smc2
import core/env
import core/model
import core/sequential
import examples/hmm
import examples/sir

// A small SIR posterior with an independent exhaustive arithmetic oracle.
// These are posterior-accuracy checks, not recovery of one generating parameter.
// Budgets and tolerances are fixed before runs: three seeds; SMC 4000 particles;
// custom PMMH 3000 transitions, 600 burnin, 8 inner particles; custom SMC2
// 800 outer / 8 inner particles, one move per observation. All four parameter
// cells and both marginals have absolute tolerance .075; evidence has 15%
// relative tolerance. The asymmetric proposals exercise the custom APIs used
// by the larger SIR diagnostic, including the Hastings correction.
val seeds = [3011, 3023, 3037]
val observed-reports = [0, 1, 1]
val marginal-tolerance = 0.075
val evidence-tolerance = 0.15

alias parameters = hmm-params<trans-params,obs-params>

struct reference
  statistics : list<float64>
  evidence   : float64

struct draws
  values         : list<parameters>
  expected-count : int
  log-evidence   : maybe<float64>
  valid-outputs  : bool

fun ensure(message : string, condition : bool) : exn ()
  if not(condition) then throw(message)

fun indicator(condition : bool) : float64
  if condition then 1.0 else 0.0

fun parameter-value(high-beta : bool, high-report : bool) : parameters
  Hmm-params(Trans-params(if high-beta then 1.0 else 0.4, 0.3),
             Obs-params(if high-report then 0.7 else 0.2))

fun statistics(parameter : parameters) : list<float64>
  val high-beta = parameter.trans-params.beta == 1.0
  val high-report = parameter.obs-params.report-rate == 0.7
  [indicator(high-beta), indicator(high-report),
   indicator(not(high-beta) && not(high-report)),
   indicator(not(high-beta) && high-report),
   indicator(high-beta && not(high-report)),
   indicator(high-beta && high-report)]

fun tiny-sir() : sequential-model<e,parameters,population,int,sir-output>
  Sequential-model(
    fn(){
      val high-beta = bernoulli'(0.5)
      val high-report = bernoulli'(0.5)
      parameter-value(high-beta, high-report)
    },
    fn(_){ Population(4, 1, 0) },
    fn(parameter, _index, current){
      // Use the real example's infection, recovery and reporting code.
      val next = sir-transition(parameter.trans-params, current)
      val reported = sir-observation(parameter.obs-params, next)
      Step-output(next, reported)
    },
    fn(result){
      Sir-output(result.current-state, result.observations,
        result.parameter.trans-params.beta,
        result.parameter.trans-params.gamma-rate,
        result.parameter.obs-params.report-rate)
    })

fun parameter-score(_parameter : parameters) : float64
  ln(0.25)

fun proposal-log-prob(parameter : parameters) : float64
  ln(if parameter.trans-params.beta == 1.0 then 0.8 else 0.2)
    + ln(if parameter.obs-params.report-rate == 0.7 then 0.7 else 0.3)

fun parameter-kernel(current : parameters) : random (parameters,env,float64)
  val high-beta = random-float64() < 0.8
  val high-report = random-float64() < 0.7
  val proposed = parameter-value(high-beta, high-report)
  (proposed, sir-parameter-env(proposed),
    proposal-log-prob(current) - proposal-log-prob(proposed))

// Independent oracle: no distribution, inference, or SIR transition functions.
// There are five people, so each count is in [0,5] and R is determined by S,I.
// Each path first infects k susceptible people, then recovers r of the I+k
// infected people, including newly infected people, before observing reports.
struct state-mass
  susceptible : int
  infected    : int
  mass        : float64

fun factorial(n : int) : float64
  [1, 2, 3, 4, 5].foldl(1.0, fn(acc, k){
    if k <= n then acc * float64(k) else acc
  })

fun integer-power(base : float64, exponent : int) : float64
  [0, 1, 2, 3, 4].foldl(1.0, fn(acc, k){
    if k < exponent then acc * base else acc
  })

fun binomial-mass(n : int, k : int, probability : float64) : float64
  factorial(n) / (factorial(k) * factorial(n - k))
    * integer-power(probability, k) * integer-power(1.0 - probability, n - k)

fun poisson-mass(observed : int, rate : float64) : float64
  exp(~rate) * integer-power(rate, observed) / factorial(observed)

fun advance-exact(states : list<state-mass>, beta : float64,
                    report-rate : float64, observed : int) : list<state-mass>
  states.flatmap(fn(state){
    val infection-probability = 1.0 - exp(~(beta * float64(state.infected) / 5.0))
    val recovery-probability = 1.0 - exp(~0.3)
    [0, 1, 2, 3, 4, 5].filter(fn(k){ k <= state.susceptible }).flatmap(fn(k){
      val infections = binomial-mass(state.susceptible, k, infection-probability)
      val before-recovery = state.infected + k
      [0, 1, 2, 3, 4, 5].filter(fn(r){ r <= before-recovery }).map(fn(r){
        val next-infected = before-recovery - r
        val recoveries = binomial-mass(before-recovery, r, recovery-probability)
        val observation = poisson-mass(observed, report-rate * float64(next-infected))
        State-mass(state.susceptible - k, next-infected,
          state.mass * infections * recoveries * observation)
      })
    })
  }).filter(fn(state){ state.mass > 0.0 })

fun exact-likelihood(parameter : parameters) : float64
  val paths = observed-reports.foldl([State-mass(4, 1, 1.0)], fn(states, observed){
    advance-exact(states, parameter.trans-params.beta,
      parameter.obs-params.report-rate, observed)
  })
  paths.foldl(0.0, fn(acc, state){ acc + state.mass })

fun exact-reference() : exn reference
  val cells = [False, True].flatmap(fn(high-beta){
    [False, True].map(fn(high-report){
      val parameter = parameter-value(high-beta, high-report)
      (parameter, 0.25 * exact-likelihood(parameter))
    })
  })
  // These independently calculated joint masses guard the oracle itself.
  val known-masses = [0.004750349535694069, 0.006937864009386905,
                     0.008000506768234944, 0.006859542634672268]
  ensure("SIR exhaustive oracle matches independently calculated joint masses",
    zip(cells, known-masses).all(fn(item){ abs(snd(fst(item)) - snd(item)) < 1.0e-12 }))
  val evidence = cells.foldl(0.0, fn(acc, cell){ acc + snd(cell) })
  val totals = cells.foldl(replicate(0.0, 6), fn(acc, cell){
    zip(acc, statistics(fst(cell))).map(fn(item){ fst(item) + snd(item) * snd(cell) })
  })
  val expected = totals.map(fn(total){ total / evidence })
  ensure("SIR exact evidence", abs(evidence - 0.026548262947988184) < 1.0e-12)
  Reference(expected, evidence)

fun valid-parameter(parameter : parameters) : bool
  (parameter.trans-params.beta == 0.4 || parameter.trans-params.beta == 1.0)
    && (parameter.obs-params.report-rate == 0.2 || parameter.obs-params.report-rate == 0.7)
    && parameter.trans-params.gamma-rate == 0.3

fun matches-parameter(value : sir-output, parameter : parameters) : bool
  value.beta == parameter.trans-params.beta
    && value.gamma-rate == parameter.trans-params.gamma-rate
    && value.report-rate == parameter.obs-params.report-rate

fun valid-output(value : sir-output) : bool
  val pop = value.final-pop
  pop.susceptible >= 0 && pop.infected >= 0 && pop.recovered >= 0
    && pop.susceptible + pop.infected + pop.recovered == 5
    && value.reports == observed-reports && value.gamma-rate == 0.3

fun run-algorithm(algorithm : string, seed : int) : div draws
  pseudo-random(seed, fn(){
    val environment = singleton(reported-var, observed-reports)
    val spec = tiny-sir()
    match algorithm
      "SMC" ->
        val result = smc(4000, 3, environment, spec)
        val values = result.particles.map(fn(particle){
          val value = particle.value
          Hmm-params(Trans-params(value.beta, value.gamma-rate), Obs-params(value.report-rate))
        })
        Draws(values, 4000, Just(result.log-evidence),
          result.particles.all(fn(particle){ valid-output(particle.value) }))
      "PMMH" ->
        val result = pmmh-with(8, 3, default-config(3000, 600), environment,
          spec, parameter-score, parameter-kernel)
        Draws(result.samples.map(fn(sample){ sample.parameter }), 2400, Nothing,
          result.samples.all(fn(sample){
            sample.estimate.particles.length == 8
              && sample.estimate.particles.all(fn(particle){
                valid-output(particle.value) && matches-parameter(particle.value, sample.parameter)
              })
          }))
      "SMC2" ->
        val result = smc2-with(800, 8, 3, 1, environment,
          spec, parameter-score, parameter-kernel)
        Draws(result.particles.map(fn(particle){ particle.parameter }), 800, Just(result.log-evidence),
          result.particles.all(fn(particle){
            particle.estimate.particles.length == 8
              && particle.estimate.particles.all(fn(inner){
                valid-output(inner.value) && matches-parameter(inner.value, particle.parameter)
              })
          }))
      _ -> impossible("unknown SIR test algorithm")
  })

fun check(algorithm : string, seed : int, expected : reference) : <console,div,exn> ()
  val result = run-algorithm(algorithm, seed)
  ensure(algorithm ++ " SIR sample count and observation/state invariants",
    result.values.length == result.expected-count && result.valid-outputs
      && result.values.all(valid-parameter))
  val totals = result.values.foldl(replicate(0.0, 6), fn(acc, parameter){
    zip(acc, statistics(parameter)).map(fn(item){ fst(item) + snd(item) })
  })
  val actual = totals.map(fn(value){ value / float64(result.values.length) })
  val errors = zip(actual, expected.statistics).map(fn(item){ abs(fst(item) - snd(item)) })
  val evidence-error = match result.log-evidence
    Nothing -> 0.0 // A retained PMMH conditional estimate is not marginal evidence.
    Just(logz) -> abs(exp(logz) / expected.evidence - 1.0)
  println(algorithm ++ " SIR seed=" ++ seed.show ++ "; posterior errors=" ++ errors.show
    ++ "; evidence relative error=" ++ evidence-error.show)
  ensure(algorithm ++ " SIR posterior marginals and all four joint cells",
    errors.all(fn(error){ is-finite(error) && error < marginal-tolerance }))
  ensure(algorithm ++ " SIR marginal evidence",
    is-finite(evidence-error) && evidence-error < evidence-tolerance)

pub fun main() : <console,div,exn> ()
  val expected = exact-reference()
  ["SMC", "PMMH", "SMC2"].foreach fn(algorithm){
    seeds.foreach fn(seed){ check(algorithm, seed, expected) }
  }
  println("SIR inference checks passed.")
