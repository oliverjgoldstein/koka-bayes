module examples/hmm

import std/num/float64
import std/num/random
import alg/rmsmc
import alg/simulate
import alg/smc
import core/env
import core/model
import core/obsvar
import core/sequential

pub struct hmm-output<a,b,c,d>(trans-params : a,
                               obs-params : b,
                               states : list<c>,
                               observations : list<d>)

pub struct hmm-params<a,b>
  trans-params : a
  obs-params   : b

pub val emission-var = obs-bool("hmm/emission")
pub val stay-prob-var = obs-float64("hmm/stay-prob")
pub val high-prob-var = obs-float64("hmm/high-prob")

pub struct transition-params
  stay-prob : float64

pub struct observation-params
  high-prob : float64

pub fun node<a,b,c,d,e>(trans-params : a,
                        obs-params : b,
                        trans : (a, c) -> <obs-reader,model-dist,div|e> c,
                        obs : (b, c) -> <obs-reader,model-dist,div|e> d,
                        current : c) : <obs-reader,model-dist,div|e> (c, d)
  val next = trans(trans-params, current)
  val emitted = obs(obs-params, next)
  (next, emitted)

pub fun higher-order-sequential<a,b,c,d,e>(initial-state : c,
                                           trans-prior : model<e,a>,
                                           obs-prior : model<e,b>,
                                           trans : (a, c) -> <obs-reader,model-dist,div|e> c,
                                           obs : (b, c) -> <obs-reader,model-dist,div|e> d) : sequential-model<e,hmm-params<a,b>,c,d,hmm-output<a,b,c,d>>
  Sequential-model(
    fn(){
      val trans-params = trans-prior()
      val obs-params = obs-prior()
      Hmm-params(trans-params, obs-params)
    },
    fn(_params){ initial-state },
    fn(params, _index, current){
      val (next, observed) = node(params.trans-params, params.obs-params, trans, obs, current)
      Step-output(next, observed)
    },
    fn(prefix-state){
      Hmm-output(prefix-state.parameter.trans-params,
                 prefix-state.parameter.obs-params,
                 prefix-state.states,
                 prefix-state.observations)
    })

pub fun higher-order-hmm<a,b,c,d,e>(length : int,
                                    initial-state : c,
                                    trans-prior : model<e,a>,
                                    obs-prior : model<e,b>,
                                    trans : (a, c) -> <obs-reader,model-dist,div|e> c,
                                    obs : (b, c) -> <obs-reader,model-dist,div|e> d) : model<e,hmm-output<a,b,c,d>>
  as-model(length, higher-order-sequential(initial-state, trans-prior, obs-prior, trans, obs))

pub fun transition-prior() : model<e,transition-params>
  fn()
    val stay-prob = beta(stay-prob-var, 8.0, 2.0)
    Transition-params(stay-prob)

pub fun observation-prior() : model<e,observation-params>
  fn()
    val high-prob = beta(high-prob-var, 8.0, 2.0)
    Observation-params(high-prob)

pub fun simple-transition(params : transition-params, current : int) : <obs-reader,model-dist,div|e> int
  if current == 0
    then if bernoulli'(params.stay-prob) then 0 else 1
    else if bernoulli'(params.stay-prob) then 1 else 0

pub fun simple-observation(params : observation-params, state : int) : <obs-reader,model-dist,div|e> bool
  val p = if state == 0 then 1.0 - params.high-prob else params.high-prob
  bernoulli(emission-var, p)

pub fun hmm-sequential() : sequential-model<e,hmm-params<transition-params,observation-params>,int,bool,hmm-output<transition-params,observation-params,int,bool>>
  higher-order-sequential(0, transition-prior(), observation-prior(), simple-transition, simple-observation)

pub fun model(length : int = 6) : model<e,hmm-output<transition-params,observation-params,int,bool>>
  as-model(length, hmm-sequential())

pub fun hmm-model(length : int = 6) : model<e,hmm-output<transition-params,observation-params,int,bool>>
  model(length)

pub fun simulate-demo() : <console,div,random> ()
  val result = pseudo-random(23, fn(){ simulate(empty(), model()) })
  println("HMM simulation")
  println("  stay-prob = " ++ result.value.trans-params.stay-prob.show)
  println("  high-prob = " ++ result.value.obs-params.high-prob.show)
  println("  states    = [" ++ result.value.states.map(fn(x){ x.show }).join(", ") ++ "]")
  println("  emissions = [" ++ result.value.observations.map(show-bool).join(", ") ++ "]")

pub fun observed-demo() : <console,div,random> ()
  val observed-values = [True, False, True, True, False, True]
  val environment = set(emission-var, observed-values, empty())
  val result = pseudo-random(29, fn(){ simulate(environment, model()) })
  println("HMM observed-mode simulation")
  println("  supplied observations = [" ++ observed-values.map(show-bool).join(", ") ++ "]")
  println("  consumed observations = [" ++ get(emission-var, result.output-env).map(show-bool).join(", ") ++ "]")
  println("  states                = [" ++ result.value.states.map(fn(x){ x.show }).join(", ") ++ "]")

pub fun higher-order-demo() : <console,div,random> ()
  val observed-values = [True, True, False, True, False, False]
  val environment =
    set(emission-var, observed-values,
    set(high-prob-var, [0.82],
    set(stay-prob-var, [0.9], empty())))
  val result = pseudo-random(31, fn(){ simulate(environment, model()) })
  println("Higher-order modular HMM")
  println("  fixed stay-prob = " ++ result.value.trans-params.stay-prob.show)
  println("  fixed high-prob = " ++ result.value.obs-params.high-prob.show)
  println("  consumed obs    = [" ++ get(emission-var, result.output-env).map(show-bool).join(", ") ++ "]")
  println("  states          = [" ++ result.value.states.map(fn(x){ x.show }).join(", ") ++ "]")

pub fun smc-demo(particle-count : int = 48) : <console,div,random> ()
  val observed-values = [True, False, True, True, False, True]
  val environment = set(emission-var, observed-values, empty())
  val result = pseudo-random(41, fn(){ smc(particle-count, observed-values.length, environment, hmm-sequential()) })
  val first = first-sample(result.particles)
  println("HMM SMC")
  println("  particles       = " ++ result.particles.length.show)
  println("  log evidence    = " ++ result.log-evidence.show)
  println("  first states    = [" ++ first.value.states.map(fn(x){ x.show }).join(", ") ++ "]")

pub fun rmsmc-demo(particle-count : int = 32, mh-steps : int = 2) : <console,div,random> ()
  val observed-values = [True, True, False, True, False, False]
  val environment = set(emission-var, observed-values, empty())
  val result = pseudo-random(43, fn(){ rmsmc(particle-count, observed-values.length, mh-steps, environment, hmm-sequential()) })
  val first = first-sample(result.particles)
  println("HMM resample-move SMC")
  println("  particles       = " ++ result.particles.length.show)
  println("  log evidence    = " ++ result.log-evidence.show)
  println("  first emissions = [" ++ first.value.observations.map(show-bool).join(", ") ++ "]")

fun first-sample<a>(samples : list<smc-sample<a>>) : smc-sample<a>
  match samples
    Cons(sample, _rest) -> sample
    Nil -> impossible("expected a non-empty SMC sample set")

fun show-bool(x : bool) : string
  if x then "true" else "false"
