module examples/sir

import std/num/float64
import std/num/random
import alg/mcmc
import alg/mh
import alg/pmmh
import alg/simulate
import alg/smc
import alg/smc2
import core/dist
import core/env
import core/model
import core/obsvalue
import core/obsvar
import core/sequential
import examples/hmm

pub struct population
  susceptible : int
  infected    : int
  recovered   : int

pub struct sir-output
  final-pop    : population
  reports      : list<int>
  beta         : float64
  gamma-rate   : float64
  report-rate  : float64

pub val beta-var        = obs-float64("sir/beta")
pub val gamma-var       = obs-float64("sir/gamma")
pub val report-rate-var = obs-float64("sir/report-rate")
pub val reported-var    = obs-int("sir/reported")

pub struct trans-params
  beta       : float64
  gamma-rate : float64

pub struct obs-params
  report-rate : float64

pub fun trans-si(beta : float64, pop : population) : <model-dist,div|e> population
  val total = max(1, pop.susceptible + pop.infected + pop.recovered)
  val infection-p = 1.0 - exp(~((beta * float64(pop.infected)) / float64(total)))
  val new-infected = binomial'(pop.susceptible, infection-p)
  Population(pop.susceptible - new-infected,
             pop.infected + new-infected,
             pop.recovered)

pub fun trans-ir(gamma-rate : float64, pop : population) : <model-dist,div|e> population
  val recovery-p = 1.0 - exp(~gamma-rate)
  val recovered-count = binomial'(pop.infected, recovery-p)
  Population(pop.susceptible,
             pop.infected - recovered-count,
             pop.recovered + recovered-count)

pub fun trans-sir(beta : float64, gamma-rate : float64, pop : population) : <model-dist,div|e> population
  val after-si = trans-si(beta, pop)
  trans-ir(gamma-rate, after-si)

pub fun obs-sir(report-rate : float64, pop : population) : <model-dist,div|e> int
  poisson(reported-var, report-rate * float64(pop.infected))

pub fun trans-prior() : model<e,trans-params>
  fn()
    val beta0 = gamma(beta-var, 2.0, 1.0)
    val gamma0 = gamma(gamma-var, 1.0, 0.125)
    Trans-params(beta0, gamma0)

pub fun obs-prior() : model<e,obs-params>
  fn()
    val report-rate0 = beta(report-rate-var, 2.0, 7.0)
    Obs-params(report-rate0)

pub fun sir-transition(params : trans-params, pop : population) : <obs-reader,model-dist,div|e> population
  trans-sir(params.beta, params.gamma-rate, pop)

pub fun sir-observation(params : obs-params, pop : population) : <obs-reader,model-dist,div|e> int
  obs-sir(params.report-rate, pop)

pub fun sir-sequential(start : population = Population(762, 1, 0)) : sequential-model<e,hmm-params<trans-params,obs-params>,population,int,sir-output>
  Sequential-model(
    fn(){
      val trans-params = trans-prior()()
      val obs-params = obs-prior()()
      Hmm-params(trans-params, obs-params)
    },
    fn(_params){ start },
    fn(params, _index, pop){
      val next = sir-transition(params.trans-params, pop)
      val reported = sir-observation(params.obs-params, next)
      Step-output(next, reported)
    },
    fn(prefix-state){
      Sir-output(prefix-state.current-state,
                 prefix-state.observations,
                 prefix-state.parameter.trans-params.beta,
                 prefix-state.parameter.trans-params.gamma-rate,
                 prefix-state.parameter.obs-params.report-rate)
    })

pub fun sir-model(days : int = 20, start : population = Population(762, 1, 0)) : model<e,sir-output>
  as-model(days, sir-sequential(start))

pub fun sir-parameter-env(params : hmm-params<trans-params,obs-params>) : env
  set(report-rate-var, [params.obs-params.report-rate],
  set(gamma-var, [params.trans-params.gamma-rate],
  set(beta-var, [params.trans-params.beta], empty())))

pub fun sir-parameter-kernel(params : hmm-params<trans-params,obs-params>) : <div,random> (hmm-params<trans-params,obs-params>, env, float64)
  val (beta1, beta-correction) = propose-positive(params.trans-params.beta, 0.18)
  val (report1, report-correction) = propose-rate(params.obs-params.report-rate, 0.45)
  val next =
    Hmm-params(Trans-params(beta1, params.trans-params.gamma-rate),
               Obs-params(report1))
  (next,
   sir-parameter-env(next),
   beta-correction + report-correction)

pub fun sir-parameter-log-prior(params : hmm-params<trans-params,obs-params>) : <div> float64
  log-prob(gamma-dist(2.0, 1.0), ObsFloat64(params.trans-params.beta)) +
  log-prob(gamma-dist(1.0, 0.125), ObsFloat64(params.trans-params.gamma-rate)) +
  log-prob(beta-dist(2.0, 7.0), ObsFloat64(params.obs-params.report-rate))

pub fun simulate-demo() : <console,div,random> ()
  val known : env =
    set(report-rate-var, [0.3],
    set(gamma-var, [0.009],
    set(beta-var, [0.7], empty())))
  val result = pseudo-random(31, fn(){ simulate(known, sir-model()) })
  println("SIR simulation")
  println("  reports = [" ++ result.value.reports.map(fn(x){ x.show }).join(", ") ++ "]")
  println("  final   = S=" ++ result.value.final-pop.susceptible.show ++
          ", I=" ++ result.value.final-pop.infected.show ++
          ", R=" ++ result.value.final-pop.recovered.show)

pub fun inference-demo(iterations : int = 400, burnin : int = 100) : <console,div,random> ()
  val synthetic-env : env =
    set(report-rate-var, [0.3],
    set(gamma-var, [0.009],
    set(beta-var, [0.7], empty())))
  val synthetic = pseudo-random(37, fn(){ simulate(synthetic-env, sir-model()) })
  val inference-env : env =
    set(reported-var, synthetic.value.reports,
    set(gamma-var, [0.009], empty()))
  val posterior = pseudo-random(41, fn(){ mh(iterations, burnin, inference-env, sir-model()) })
  println("SIR Metropolis-Hastings")
  println("  observed reports = [" ++ synthetic.value.reports.map(fn(x){ x.show }).join(", ") ++ "]")
  println("  accepted states  = " ++ posterior.accepted.show)
  println("  posterior beta samples        = " ++ preview-float64s(get(beta-var, posterior.posterior-env)))
  println("  posterior report-rate samples = " ++ preview-float64s(get(report-rate-var, posterior.posterior-env)))

pub fun smc-demo(particle-count : int = 48, days : int = 10) : <console,div,random> ()
  val synthetic = synthetic-dataset(days)
  val result = pseudo-random(53, fn(){ smc(particle-count, days, synthetic.inference-env, sir-sequential()) })
  println("SIR SMC")
  println("  log evidence = " ++ result.log-evidence.show)
  println("  beta preview = " ++ preview-float64s(get(beta-var, result.posterior-env)))

pub fun pmmh-demo(particle-count : int = 32,
                  iterations : int = 25,
                  burnin : int = 5,
                  days : int = 10) : <console,div,random> ()
  val synthetic = synthetic-dataset(days)
  val config = default-config(iterations, burnin)
  val result =
    pseudo-random(59, fn(){
      pmmh-with(particle-count, days, config, synthetic.inference-env, sir-sequential(), sir-parameter-log-prior, sir-parameter-kernel)
    })
  println("SIR PMMH")
  println("  accepted chains = " ++ result.accepted.show)
  println("  beta preview    = " ++ preview-float64s(get(beta-var, result.posterior-env)))
  println("  report preview  = " ++ preview-float64s(get(report-rate-var, result.posterior-env)))

pub fun smc2-demo(outer-particles : int = 20,
                  inner-particles : int = 20,
                  rejuvenation-steps : int = 1,
                  days : int = 8) : <console,div,random> ()
  val synthetic = synthetic-dataset(days)
  val result =
    pseudo-random(61, fn(){
      smc2-with(outer-particles,
                inner-particles,
                days,
                rejuvenation-steps,
                synthetic.inference-env,
                sir-sequential(),
                sir-parameter-log-prior,
                sir-parameter-kernel)
    })
  println("SIR SMC2")
  println("  outer particles = " ++ result.particles.length.show)
  println("  log evidence    = " ++ result.log-evidence.show)
  println("  beta preview    = " ++ preview-float64s(get(beta-var, result.posterior-env)))

pub fun bootstrap-demo() : <console,div,random> ()
  println("Bayesian bootstrap on the SIR model")
  pmmh-demo()

struct synthetic-dataset
  reports       : list<int>
  inference-env : env

fun synthetic-dataset(days : int) : <div,random> synthetic-dataset
  val synthetic-env : env =
    set(report-rate-var, [0.3],
    set(gamma-var, [0.009],
    set(beta-var, [0.7], empty())))
  val synthetic = pseudo-random(47, fn(){ simulate(synthetic-env, sir-model(days)) })
  val inference-env : env =
    set(reported-var, synthetic.value.reports,
    set(gamma-var, [0.009], empty()))
  Synthetic-dataset(synthetic.value.reports, inference-env)

fun preview-float64s(values : list<float64>, limit : int = 10) : string
  val shown = take-float64s(limit, values).map(fn(x){ x.show }).join(", ")
  val suffix = if values.length > limit then ", ..." else ""
  "[" ++ shown ++ suffix ++ "]"

fun take-float64s(limit : int, values : list<float64>) : list<float64>
  if limit <= 0
    then []
    else
      match values
        Nil -> []
        Cons(value, rest) -> Cons(value, take-float64s(limit - 1, rest))

fun propose-positive(value : float64, scale : float64) : <div,random> (float64, float64)
  val current = max(1.0e-6, value)
  val current-log = ln(current)
  val proposal-log = current-log + (scale * standard-normal())
  val proposal = exp(proposal-log)
  (proposal, ln(proposal) - ln(current))

fun propose-rate(value : float64, scale : float64) : <div,random> (float64, float64)
  val current = clamp-rate(value)
  val current-logit = ln(current / (1.0 - current))
  val proposal-logit = current-logit + (scale * standard-normal())
  val proposal = logistic(proposal-logit)
  val current-jacobian = ln(current) + ln(1.0 - current)
  val proposal-jacobian = ln(proposal) + ln(1.0 - proposal)
  (proposal, proposal-jacobian - current-jacobian)

fun standard-normal() : random float64
  val u1 = max(1.0e-12, random-float64())
  val u2 = random-float64()
  sqrt(~2.0 * ln(u1)) * cos(2.0 * pi * u2)

fun logistic(x : float64) : float64
  1.0 / (1.0 + exp(~x))

fun clamp-rate(x : float64) : float64
  if x <= 1.0e-6 then 1.0e-6
  elif x >= 1.0 - 1.0e-6 then 1.0 - 1.0e-6
  else x
