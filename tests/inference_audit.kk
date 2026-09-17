module inference_audit

import std/num/float64
import std/num/random
import alg/lw
import alg/lwis
import alg/mh
import alg/mcmc
import alg/simulate
import alg/smc
import alg/rmsmc
import alg/pmmh
import alg/smc2
import core/env
import core/model
import core/obsvar
import core/sequential
import core/weights

val prior-y = obs-bool("audit/prior")
val initial-y = obs-bool("audit/initial")
val step-y = obs-bool("audit/step")

struct outcome
  parameter : bool
  state : bool

struct mass
  value : outcome
  weight : float64

fun ensure(label : string, condition : bool) : exn ()
  if not(condition) then throw(label)

fun model-spec() : sequential-model<e,bool,bool,bool,outcome>
  Sequential-model(
    fn(){
      val p = bernoulli'(0.3)
      val _ = bernoulli(prior-y, if p then 0.8 else 0.4)
      p
    },
    fn(p){
      val z = bernoulli'(if p then 0.75 else 0.25)
      val _ = bernoulli(initial-y, if z then 0.6 else 0.9)
      z
    },
    fn(p, _index, previous){
      val z = bernoulli'(if previous then 0.85 else if p then 0.6 else 0.2)
      Step-output(z, bernoulli(step-y, if z then 0.8 else 0.15))
    },
    fn(prefix-state){ Outcome(prefix-state.parameter, prefix-state.current-state) })

fun observations() : env
  set(prior-y, [True], set(initial-y, [True], set(step-y, [True, False, True], empty())))

// Enumerate all 32 parameter/initial-state/three-step-state paths using
// ordinary arithmetic. This oracle calls no inference or distribution code.
fun exact() : list<mass>
  val initial = [False, True].flatmap(fn(p){
    [False, True].map(fn(z){
      val parameter = if p then 0.3 * 0.8 else 0.7 * 0.4
      val state = if p then (if z then 0.75 else 0.25) else (if z then 0.25 else 0.75)
      Mass(Outcome(p, z), parameter * state * (if z then 0.6 else 0.9))
    })
  })
  [True, False, True].foldl(initial, fn(paths, y){
    paths.flatmap(fn(item){
      [False, True].map(fn(z){
        val transition = if item.value.state then 0.85 else if item.value.parameter then 0.6 else 0.2
        val emission = if z then 0.8 else 0.15
        Mass(Outcome(item.value.parameter, z), item.weight * (if z then transition else 1.0 - transition)
          * (if y then emission else 1.0 - emission))
      })
    })
  })

fun total(values : list<mass>) : float64
  values.foldl(0.0, fn(acc, item){ acc + item.weight })

fun marginal(values : list<mass>, predicate : outcome -> bool) : float64
  values.foldl(0.0, fn(acc, item){ acc + (if predicate(item.value) then item.weight else 0.0) }) / total(values)

fun equally-weighted(values : list<outcome>) : list<mass>
  values.map(fn(value){ Mass(value, 1.0) })

fun check(label : string, values : list<mass>, evidence : maybe<float64> = Nothing) : <console,exn> ()
  val reference = exact()
  val tests : list<outcome -> bool> = [fn(x){ x.parameter }, fn(x){ x.state }, fn(x){ x.parameter && x.state }]
  val errors = tests.map(fn(predicate){ abs(marginal(values, predicate) - marginal(reference, predicate)) })
  ensure(label ++ ": parameter/state/joint marginal disagrees with enumeration", errors.all(fn(error){ error < 0.065 }))
  match evidence
    Nothing -> ()
    Just(z) -> ensure(label ++ ": evidence disagrees with enumeration", abs(z / total(reference) - 1.0) < 0.15)
  println(label ++ " passed; marginal errors=" ++ errors.show)

fun nested-values(parameter : bool, estimate : smc-result<outcome>) : list<outcome>
  estimate.particles.map(fn(particle){ Outcome(parameter, particle.value.state) })

// Deliberately asymmetric independent proposals; omitting the correction
// would multiply the target's odds by 0.85/0.15.
fun parameter-kernel(current : bool) : <div,random> (bool,env,float64)
  val proposed = random-float64() < 0.85
  val correction = ln(if current then 0.85 else 0.15) - ln(if proposed then 0.85 else 0.15)
  (proposed, empty(), correction)

fun parameter-score(p : bool) : float64
  ln(if p then 0.3 * 0.8 else 0.7 * 0.4)

fun check-seed(seed : int) : <console,div,exn> ()
  val environment = observations()
  val spec = model-spec()
  val ordinary = as-model(3, spec)
  val suffix = " seed=" ++ seed.show
  val weighted = pseudo-random(seed, fn(){ lw(6000, environment, ordinary) })
  check("LW" ++ suffix, weighted.map(fn(item){ Mass(item.value, exp(item.log-weight)) }),
    Just(exp(log-mean-weight(weighted.map(fn(item){ item.log-weight })))))
  check("LWIS" ++ suffix, equally-weighted(pseudo-random(seed, fn(){ lwis(4000, environment, ordinary) })))
  val trace-chain = pseudo-random(seed, fn(){ mh(12000, 2000, environment, ordinary) })
  check("MH" ++ suffix, equally-weighted(trace-chain.samples.map(fn(item){ item.value })))
  val filtered = pseudo-random(seed, fn(){ smc(3000, 3, environment, spec) })
  check("SMC" ++ suffix, equally-weighted(filtered.particles.map(fn(item){ item.value })), Just(exp(filtered.log-evidence)))
  val moved = pseudo-random(seed, fn(){ rmsmc(1600, 3, 2, environment, spec) })
  check("RMSMC" ++ suffix, equally-weighted(moved.particles.map(fn(item){ item.value })), Just(exp(moved.log-evidence)))
  val chain = pseudo-random(seed, fn(){ pmmh(3, 3, default-config(6000, 1000), environment, spec) })
  check("PMMH" ++ suffix, equally-weighted(chain.samples.flatmap(fn(item){ nested-values(item.parameter, item.estimate) })))
  val nested = pseudo-random(seed, fn(){ smc2(1200, 3, 3, 2, environment, spec) })
  check("SMC2" ++ suffix, equally-weighted(nested.particles.flatmap(fn(item){ nested-values(item.parameter, item.estimate) })),
    Just(exp(nested.log-evidence)))
  val custom-chain = pseudo-random(seed, fn(){
    pmmh-with(3, 3, default-config(8000, 1000), environment, spec, parameter-score, parameter-kernel)
  })
  check("PMMH asymmetric" ++ suffix,
    equally-weighted(custom-chain.samples.flatmap(fn(item){ nested-values(item.parameter, item.estimate) })))
  val custom-nested = pseudo-random(seed, fn(){
    smc2-with(1600, 3, 3, 2, environment, spec, parameter-score, parameter-kernel)
  })
  check("SMC2 asymmetric" ++ suffix,
    equally-weighted(custom-nested.particles.flatmap(fn(item){ nested-values(item.parameter, item.estimate) })),
    Just(exp(custom-nested.log-evidence)))

fun check-mh-kernel() : <div,exn> ()
  val rejected = pseudo-random(701, fn(){
    mh-chain(default-config(20), Scored(17, 0.0), fn(_){ Mh-candidate(Scored(99, neginf), 0.0) })
  })
  ensure("rejected MH proposals must retain state and multiplicity", rejected.samples == replicate(17, 20) && rejected.accepted == 0)
  val recovered = pseudo-random(703, fn(){
    mh-chain(default-config(4), Scored(0, neginf), fn(_){ Mh-candidate(Scored(1, 0.0), 0.0) })
  })
  ensure("MH must escape an initial state with zero likelihood", recovered.samples == [1, 1, 1, 1])

fun check-particle-evidence() : <console,div,exn> ()
  // Test the estimator on the probability scale, across independent filters.
  // N=1 makes this particularly sensitive to erroneous weight cancellation.
  [1, 2, 4].foreach fn(count){
    val estimates = pseudo-random(709 + count, fn(){
      list(1, 4000).map(fn(_){
        val result = smc(count, 3, observations(), model-spec())
        val z = exp(result.log-evidence)
        val probability = float64(result.particles.filter(fn(item){ item.value.parameter }).length) / float64(count)
        (z, z * probability)
      })
    })
    val mean = estimates.foldl(0.0, fn(acc, item){ acc + fst(item) }) / float64(estimates.length)
    val weighted-mean = estimates.foldl(0.0, fn(acc, item){ acc + snd(item) }) / float64(estimates.length)
    val reference = exact()
    ensure("particle likelihood estimates agree with exact evidence", abs(mean / total(reference) - 1.0) < 0.08)
    ensure("evidence-weighted particle marginal agrees with the joint mass",
      abs(weighted-mean / total(reference) - marginal(reference, fn(x){ x.parameter })) < 0.045)
    println("SMC evidence N=" ++ count.show ++ " passed; relative error=" ++ abs(mean / total(reference) - 1.0).show)
  }

fun check-simulation-and-branching() : <console,div,exn> ()
  val prior = pseudo-random(739, fn(){
    list(1, 4000).map(fn(_){ simulate(observations(), prior(model-spec())).value })
  })
  val frequency = float64(prior.filter(fn(p){ p }).length) / float64(prior.length)
  ensure("simulation clamps observations but does not itself condition the prior", abs(frequency - 0.3) < 0.035)
  val branching = fn(){
    val flag = bernoulli'(0.7)
    val extra = if flag then bernoulli'(0.2) else False
    val _ = bernoulli(prior-y, if flag then (if extra then 0.9 else 0.3) else 0.1)
    (flag, extra)
  }
  val chain = pseudo-random(743, fn(){ mh(12000, 2000, singleton(prior-y, [True]), branching) })
  val probability = float64(chain.samples.filter(fn(item){ fst(item.value) }).length) / float64(chain.samples.length)
  val joint = float64(chain.samples.filter(fn(item){ snd(item.value) }).length) / float64(chain.samples.length)
  // P(y)=0.7*(0.2*0.9+0.8*0.3)+0.3*0.1=0.324.
  ensure("branching MH needs both likelihood and trace-length corrections", abs(probability - 0.294 / 0.324) < 0.04)
  ensure("branching MH regenerates the conditional suffix", abs(joint - 0.126 / 0.324) < 0.045)
  println("simulation and observed variable-length MH passed")

fun impossible-spec() : sequential-model<e,(),(),bool,()>
  Sequential-model(fn(){ () }, fn(_){ () },
    fn(_, _, _){ Step-output((), bernoulli(step-y, 0.0)) }, fn(_){ () })

fun check-impossible-data() : <console,div,exn> ()
  val environment = singleton(step-y, [True, True])
  val spec = impossible-spec()
  pseudo-random(751, fn(){
    val weighted = lw(8, environment, as-model(2, spec))
    ensure("impossible LW data have zero mass", weighted.all(fn(item){ item.log-weight == neginf }))
    ensure("impossible LWIS data have no posterior", lwis(8, environment, as-model(2, spec)).is-empty)
    ensure("impossible MH data have no posterior", mh(8, 0, environment, as-model(2, spec)).samples.is-empty)
    val filtered = smc(8, 2, environment, spec)
    ensure("impossible SMC data collapse", filtered.particles.is-empty && filtered.log-evidence == neginf)
    val moved = rmsmc(8, 2, 2, environment, spec)
    ensure("impossible RMSMC data collapse", moved.particles.is-empty && moved.log-evidence == neginf)
    ensure("impossible PMMH data have no posterior", pmmh(2, 2, default-config(8), environment, spec).samples.is-empty)
    val nested = smc2(8, 2, 2, 2, environment, spec)
    ensure("impossible SMC2 data collapse", nested.particles.is-empty && nested.log-evidence == neginf)
  })
  println("impossible observations passed for all seven algorithms")

pub fun main() : <console,div,exn> ()
  // Independently cross-checked with rational enumeration.
  val reference = exact()
  ensure("enumerated evidence", abs(total(reference) - 69018819.0 / 2000000000.0) < 1.0e-12)
  ensure("enumerated parameter marginal", abs(marginal(reference, fn(x){ x.parameter }) - 13483998.0 / 23006273.0) < 1.0e-12)
  ensure("enumerated state marginal", abs(marginal(reference, fn(x){ x.state }) - 20109776.0 / 23006273.0) < 1.0e-12)
  ensure("enumerated joint marginal", abs(marginal(reference, fn(x){ x.parameter && x.state }) - 12636576.0 / 23006273.0) < 1.0e-12)
  check-mh-kernel()
  check-simulation-and-branching()
  check-impossible-data()
  [719, 727, 733].foreach(check-seed)
  check-particle-evidence()
  println("inference audit passed: exact joint marginals, asymmetric kernels, rejection, particle evidence")
