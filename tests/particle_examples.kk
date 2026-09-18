module particle_examples

import std/num/float64
import std/num/random
import alg/handler_smc
import alg/mcmc
import alg/pmmh
import alg/rmsmc
import alg/smc
import alg/smc2
import core/env
import core/model
import core/obsvar
import core/sequential
import handlers/sequential

// Fixed before running: 3 models x 5 algorithms x 3 seeds = 45 checks.
// All models have three observations. Budgets are identical across models:
// SMC/checkpoint SMC 4000 particles; RMSMC 700 particles, 2 moves per step;
// PMMH 2000 iterations, 400 burnin, 2 inner particles;
// SMC2 600 outer particles, 4 inner particles, 1 move per step.
// Finite posterior cells/marginals have absolute tolerance .075. Classification
// additionally caps each tolerance at 65% of its exact cell probability: its
// rare class has probability .0387 (about 23-155 outer/filter particles), so an
// absolute .075 bound alone would incorrectly permit dropping that class.
// Gaussian mean/variance/covariance tolerances are specified in its oracle below.
// Evidence tolerance is 15% relative, where an evidence estimator is available.
// PMMH's retained conditional likelihood estimate is NOT marginal evidence.
val seeds = [3011, 3023, 3037]
val algorithms = ["SMC", "RMSMC", "PMMH", "SMC2", "checkpoint-SMC"]
val evidence-tolerance = 0.15

struct reference
  statistics : list<float64>
  tolerances : list<float64>
  evidence   : float64

struct draws
  values         : list<list<float64>>
  expected-count : int
  log-evidence   : maybe<float64>

fun indicator(value : bool) : float64
  if value then 1.0 else 0.0

fun from-filter(result : smc-result<list<float64>>, count : int) : draws
  Draws(result.particles.map(fn(particle){ particle.value }), count, Just(result.log-evidence))

fun run-algorithm<p,s,o>(algorithm : string, seed : int, environment : env,
                         spec : sequential-model<total,p,s,o,list<float64>>) : div draws
  pseudo-random(seed, fn(){
    match algorithm
      "SMC" -> from-filter(smc(4000, 3, environment, spec), 4000)
      "RMSMC" -> from-filter(rmsmc(700, 3, 2, environment, spec), 700)
      "PMMH" ->
        val chain = pmmh(2, 3, default-config(2000, 400), environment, spec)
        // Every retained outer state contributes the same number of equally
        // weighted inner particles, including repeated rejected states.
        val values = chain.samples.flatmap(fn(sample){
          sample.estimate.particles.map(fn(particle){ particle.value })
        })
        Draws(values, 1600 * 2, Nothing)
      "SMC2" ->
        val result = smc2(600, 4, 3, 1, environment, spec)
        val values = result.particles.flatmap(fn(particle){
          particle.estimate.particles.map(fn(inner){ inner.value })
        })
        Draws(values, 600 * 4, Just(result.log-evidence))
      "checkpoint-SMC" ->
        val result = smc-model(4000, environment, fn(){
          val parameter = mask<checkpoint>{ prior(spec)() }
          val prefix-state = checkpointed-prefix(3, parameter, spec)
          finish(spec)(prefix-state)
        })
        from-filter(result, 4000)
      _ -> impossible("unknown particle example algorithm")
  })

fun averages(values : list<list<float64>>, dimensions : int) : list<float64>
  val zeroes = replicate(0.0, dimensions)
  val totals = values.foldl(zeroes, fn(acc, value){
    zip(acc, value).map(fn(item){ fst(item) + snd(item) })
  })
  totals.map(fn(value){ value / float64(values.length) })

fun run-example<p,s,o>(name : string, environment : env,
                        spec : sequential-model<total,p,s,o,list<float64>>,
                        truth : reference) : <console,div,exn> ()
  algorithms.foreach fn(algorithm){
    seeds.foreach fn(seed){
      val result = run-algorithm(algorithm, seed, environment, spec)
      val shape-ok = result.values.length == result.expected-count &&
        result.values.all(fn(value){ value.length == truth.statistics.length && value.all(is-finite) })
      val actual = averages(result.values, truth.statistics.length)
      val errors = zip(zip(actual, truth.statistics), truth.tolerances).map(fn(item){
        val ((estimate, expected), tolerance) = item
        abs(estimate - expected) / tolerance
      })
      val statistic-ratio = errors.foldl(0.0, fn(acc, value){ max(acc, if is-finite(value) then value else posinf) })
      val evidence-ratio = match result.log-evidence
        Nothing -> 0.0
        Just(logz) -> abs(exp(logz) / truth.evidence - 1.0) / evidence-tolerance
      val maximum-error = if shape-ok && is-finite(evidence-ratio)
        then max(statistic-ratio, evidence-ratio) else posinf
      val passed = maximum-error <= 1.0
      // CSV schema: record,family,model,algorithm,seed,max_error_ratio,status
      println("example,particle," ++ name ++ "," ++ algorithm ++ "," ++ seed.show ++ ","
        ++ maximum-error.show ++ "," ++ (if passed then "PASS" else "FAIL"))
      if not(passed) then
        println("  actual statistics=" ++ actual.show ++ "; expected=" ++ truth.statistics.show
          ++ "; tolerance ratios=" ++ errors.show ++ "; evidence ratio=" ++ evidence-ratio.show
          ++ "; count=" ++ result.values.length.show ++ "/" ++ result.expected-count.show)
        throw("Particle example failed: " ++ name ++ "/" ++ algorithm ++ "/" ++ seed.show)
    }
  }

// A classifier has three possible sensitivity classes with unequal prior mass.
val classification-reading = obs-bool("particle-examples/classification")

fun class-statistics(category : int) : list<float64>
  [indicator(category == 0), indicator(category == 1), indicator(category == 2)]

fun classification() : sequential-model<e,int,(),bool,list<float64>>
  Sequential-model(
    fn(){ discrete'([0.2, 0.5, 0.3]) },
    fn(_parameter){ () },
    fn(category, _index, _state){
      val probability = if category == 0 then 0.15 elif category == 1 then 0.5 else 0.85
      Step-output((), bernoulli(classification-reading, probability))
    },
    fn(result){ class-statistics(result.parameter) })

fun classification-reference() : reference
  // Three observations [true,false,true]. Each line is prior * p*(1-p)*p.
  val masses = [0.2 * 0.15 * 0.85 * 0.15,
                0.5 * 0.5 * 0.5 * 0.5,
                0.3 * 0.85 * 0.15 * 0.85]
  val evidence = masses.foldl(0.0, fn(acc, mass){ acc + mass })
  val probabilities = masses.map(fn(mass){ mass / evidence })
  Reference(probabilities, probabilities.map(fn(p){ min(0.075, 0.65*p) }), evidence)

// A binary hidden process has an unknown transition persistence class. There
// are 2 parameter choices x 2^4 hidden paths, exhaustively enumerated below.
val process-reading = obs-bool("particle-examples/process")

struct hidden-state
  initial : bool
  current : bool

fun process-statistics(parameter : bool, initial : bool, last : bool) : list<float64>
  [indicator(parameter && last), indicator(parameter && not(last)),
   indicator(not(parameter) && last), indicator(not(parameter) && not(last)),
   indicator(initial)]

fun hidden-process() : sequential-model<e,bool,hidden-state,bool,list<float64>>
  Sequential-model(
    fn(){ bernoulli'(0.35) },
    fn(_parameter){
      val initial = bernoulli'(0.4)
      Hidden-state(initial, initial)
    },
    fn(parameter, _index, state){
      val persistence = if parameter then 0.8 else 0.55
      val next = bernoulli'(if state.current then persistence else 1.0 - persistence)
      val observed = bernoulli(process-reading, if next then 0.85 else 0.2)
      Step-output(Hidden-state(state.initial, next), observed)
    },
    fn(result){ process-statistics(result.parameter, result.current-state.initial, result.current-state.current) })

fun process-reference() : reference
  val paths = [False, True].flatmap(fn(parameter){
    [False, True].flatmap(fn(x0){
      [False, True].flatmap(fn(x1){
        [False, True].flatmap(fn(x2){
          [False, True].map(fn(x3){
            val prior = if parameter then 0.35 else 0.65
            val initial = if x0 then 0.4 else 0.6
            val stay = if parameter then 0.8 else 0.55
            val transitions = (if x0 == x1 then stay else 1.0 - stay)
              * (if x1 == x2 then stay else 1.0 - stay)
              * (if x2 == x3 then stay else 1.0 - stay)
            val observations = (if x1 then 0.85 else 0.2)
              * (if x2 then 0.15 else 0.8) * (if x3 then 0.85 else 0.2)
            (process-statistics(parameter, x0, x3), prior * initial * transitions * observations)
          })
        })
      })
    })
  })
  val evidence = paths.foldl(0.0, fn(acc, path){ acc + snd(path) })
  val totals = paths.foldl([0.0, 0.0, 0.0, 0.0, 0.0], fn(acc, path){
    zip(acc, fst(path)).map(fn(item){ fst(item) + snd(item) * snd(path) })
  })
  Reference(totals.map(fn(value){ value / evidence }),
            [0.075, 0.075, 0.075, 0.075, 0.075], evidence)

// Sensor calibration: theta~N(0,1), z_i~N(theta,.5), y_i~N(z_i,1).
// The nuisance z_i makes each particle likelihood estimate genuinely random.
val sensor-reading = obs-float64("particle-examples/sensor")
val sensor-data = [-0.5, 0.75, 1.25]
val parameter-mean = 6.0 / 17.0
val final-state-mean = 0.8 * parameter-mean + 0.25

fun sensor-statistics(parameter : float64, last : float64) : list<float64>
  val x = parameter - parameter-mean
  val z = last - final-state-mean
  [parameter, x*x, last, z*z, x*z]

fun sensor() : sequential-model<e,float64,float64,float64,list<float64>>
  Sequential-model(
    fn(){ normal'(0.0, 1.0) },
    fn(parameter){ parameter },
    fn(parameter, _index, _state){
      val actual = normal'(parameter, 0.5)
      val observed = normal(sensor-reading, actual, 1.0)
      Step-output(actual, observed)
    },
    fn(result){ sensor-statistics(result.parameter, result.current-state) })

fun sensor-reference() : reference
  // Marginal y|theta is N(theta,5/4); posterior precision is 1+3/(5/4).
  // z_last|theta,y_last has mean .8*theta+.2*y_last and variance .2.
  val variance = 5.0 / 17.0
  val latent-variance = 0.2 + 0.64 * variance
  val covariance = 0.8 * variance
  // Marginal covariance of y is (5/4)I + 11^T. Matrix determinant lemma
  // gives det=(5/4)^2*(17/4); Sherman-Morrison gives the quadratic below.
  val determinant = (5.0/4.0) * (5.0/4.0) * (17.0/4.0)
  val quadratic = (19.0/8.0) / (5.0/4.0) - (9.0/4.0) / ((5.0/4.0)*(17.0/4.0))
  val log-evidence = -1.5 * ln(2.0*pi) - 0.5 * ln(determinant) - 0.5 * quadratic
  Reference([parameter-mean, variance, final-state-mean, latent-variance, covariance],
            [0.12, 0.12, 0.12, 0.15, 0.12], exp(log-evidence))

pub fun main() : <console,div,exn> ()
  run-example("classification", singleton(classification-reading, [True, False, True]),
                classification(), classification-reference())
  run-example("hidden-process", singleton(process-reading, [True, False, True]),
                hidden-process(), process-reference())
  run-example("sensor-calibration", singleton(sensor-reading, sensor-data), sensor(), sensor-reference())
  println("Particle example matrix passed (45 runs).")
