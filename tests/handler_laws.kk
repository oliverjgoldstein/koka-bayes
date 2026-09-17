module handler_laws

import bayes
import alg/lw
import alg/lwis
import alg/simulate
import alg/mh
import alg/smc
import alg/rmsmc
import alg/pmmh
import alg/smc2
import alg/mcmc
import core/sequential
import core/trace
import handlers/weight
import std/num/int32
import std/num/random

fun ensure(label : string, condition : bool) : exn ()
  if not(condition) then throw(label)

fun near(actual : float64, expected : float64) : bool
  abs(actual - expected) < 1.0e-12

fun fails(action : () -> <exn|e> a) : e bool
  try(fn(){ val result = action(); False }, fn(_exception){ True })

effect branch
  ctl choose-branch() : bool

fun both(action : () -> <branch|e> a) : e list<a>
  handle(action)
    return(value) [value]
    ctl choose-branch()
      val left = resume(True)
      val right = resume(False)
      left ++ right

fun test-weight-laws() : exn ()
  val (_, identity) = handle-weight(fn(){ () })
  val (_, product) = handle-weight(fn(){ push-evidence(ln(0.4)); push-evidence(ln(0.25)) })
  val (inner, outer) = handle-weight(fn(){
    push-evidence(ln(0.4))
    val (_, weight) = handle-weight(fn(){ push-evidence(ln(0.25)) })
    weight
  })
  ensure("weight identity is one", identity == 0.0)
  ensure("sequential weights multiply", near(exp(product), 0.1))
  ensure("nested weight handlers keep scores separate", near(exp(inner), 0.25) && near(exp(outer), 0.4))
  val (_, pushed) = handle-weight(fn(){
    push-evidence(ln(0.4))
    val (_, weight) = handle-weight(fn(){ push-evidence(ln(0.25)) })
    push-evidence(weight)
  })
  ensure("explicit evidence passing scores the inner estimate once", near(exp(pushed), 0.1))
  val branches = both(fn(){
    handle-weight(fn(){
      push-evidence(ln(0.6))
      val selected = choose-branch()
      push-evidence(ln(if selected then 0.8 else 0.2))
      selected
    })
  })
  ensure("weight handler resumes both branches", branches.length == 2)
  branches.foreach fn(result){
    val (selected, weight) = result
    ensure("weight handler snapshots the prefix separately per branch", near(exp(weight), if selected then 0.48 else 0.12))
  }

fun test-factor-laws() : <div,exn> ()
  val observed-y = obs-bool("laws/y")
  with fun random-int32() ~1.int32
  val plain = run-lw(singleton(observed-y, [True]), fn(){ bernoulli(observed-y, 0.7) })
  val identity = run-lw(singleton(observed-y, [True]), fn(){
    score(1.0)
    log-score(0.0)
    bernoulli(observed-y, 0.7)
  })
  val split = run-lw(singleton(observed-y, [True]), fn(){
    score(0.5)
    log-score(ln(0.4))
    bernoulli(observed-y, 0.7)
  })
  val fused = run-lw(singleton(observed-y, [True]), fn(){
    score(0.2)
    bernoulli(observed-y, 0.7)
  })
  ensure("factor identity preserves values and weights", identity.value == plain.value && identity.log-weight == plain.log-weight)
  ensure("factor multiplication agrees with a fused factor", split.value == fused.value && near(split.log-weight, fused.log-weight) && near(exp(split.log-weight), 0.14))
  ensure("factors occupy unique trace addresses", split.trace.map(fn(entry){ entry.address }) == [0, 1, 2])
  ensure("factor weights agree with observed trace scores", near(split.log-weight, observed-log-prob(split.trace)))
  ensure("factors are not sampled sites", sample-count(split.trace) == 0 && sampled-addresses(split.trace).is-empty)
  ensure("factors do not manufacture observed data", split.output-env.show == plain.output-env.show)
  val scaled = run-lw(empty(), fn(){ score(2.0); score(3.0); 7 })
  ensure("unnormalized scores may exceed one", scaled.value == 7 && near(exp(scaled.log-weight), 6.0))
  val zero = run-lw(empty(), fn(){ score(0.0); 7 })
  ensure("zero score has zero mass", zero.log-weight == neginf && observed-log-prob(zero.trace) == neginf)
  [~1.0, nan, posinf].foreach fn(weight){
    ensure("invalid ordinary scores are rejected", fails(fn(){ run-lw(empty(), fn(){ score(weight) }) }))
  }
  val simulated = simulate(empty(), fn(){ score(0.5); log-score(ln(0.4)); 7 })
  ensure("simulation retains factors for replay acceptance", simulated.value == 7 && near(exp(observed-log-prob(simulated.trace)), 0.2))
  val latent = run-lw(empty(), fn(){
    score(0.5)
    val value = bernoulli'(0.5)
    score(0.4)
    value
  })
  ensure("factor positions do not change sampled-site identification", sample-count(latent.trace) == 1 && sampled-addresses(latent.trace) == [1])

fun factor-spec() : sequential-model<e,(),(),(),int>
  Sequential-model(
    fn(){ log-score(ln(0.4)); () },
    fn(_){ log-score(ln(0.5)); () },
    fn(_, _, _){ log-score(ln(0.25)); Step-output((), ()) },
    fn(_){ 7 })

fun test-inference-factor-integration() : <div,exn> ()
  val spec = factor-spec()
  val model = as-model(1, spec)
  with fun random-int32() ~1.int32
  val weighted = lw(2, empty(), model)
  val independent = lwis(2, empty(), model)
  val trace-chain = mh(2, 0, empty(), model)
  val filtered = smc(2, 1, empty(), spec)
  val moved = rmsmc(2, 1, 2, empty(), spec)
  val marginal = pmmh(2, 1, default-config(2), empty(), spec)
  val squared = smc2(2, 2, 1, 2, empty(), spec)
  ensure("LW scores all model factors exactly once", weighted.length == 2 && weighted.all(fn(draw){ draw.value == 7 && near(exp(draw.log-weight), 0.05) }))
  ensure("LWIS resamples factored models", independent == [7, 7])
  ensure("MH retains factors through trace replay", trace-chain.accepted == 2 && trace-chain.samples.length == 2 && trace-chain.samples.all(fn(draw){ draw.value == 7 && near(exp(observed-log-prob(draw.trace)), 0.05) }))
  ensure("SMC scores factors across sequential boundaries", filtered.particles.length == 2 && near(exp(filtered.log-evidence), 0.05))
  ensure("RMSMC preserves factor evidence during rejuvenation", moved.particles.length == 2 && near(exp(moved.log-evidence), 0.05))
  ensure("RMSMC replay keeps all prefix factors", moved.particles.all(fn(particle){ particle.value == 7 && sample-count(particle.trace) == 0 && particle.trace.length == 3 && near(exp(particle.log-likelihood), 0.05) }))
  ensure("PMMH keeps constant factored proposals accepted", marginal.accepted == 2 && marginal.samples.length == 2)
  ensure("PMMH filter evidence excludes separately scored prior factors", marginal.samples.all(fn(draw){ near(exp(draw.log-evidence), 0.125) && draw.estimate.particles.all(fn(particle){ particle.value == 7 && particle.trace.length == 2 }) }))
  ensure("SMC2 passes incremental factor evidence once", squared.particles.length == 2 && near(exp(squared.log-evidence), 0.05))
  ensure("SMC2 retains inner factor evidence", squared.particles.all(fn(particle){ near(exp(particle.log-evidence), 0.125) }))

fun test-factor-rejection() : <div,exn> ()
  var draws := 0
  with fun random-int32()
    draws := draws + 1
    // Each uniform uses two words: initial False, select its only latent
    // address with a near-one draw, propose True, then reject its zero factor.
    // Rounding u * site-count would incorrectly select a nonexistent address
    // here, replay the old value, and skip both proposal and acceptance draws.
    if draws == 5 || draws == 6 then 0.int32 else ~1.int32
  val result = mh(1, 0, empty(), fn(){
    val selected = bernoulli'(0.5)
    score(if selected then 0.0 else 1.0)
    selected
  })
  ensure("factor test exercised the expected MH proposal", draws == 8)
  ensure("MH factor excludes an otherwise valid latent proposal", result.accepted == 0 && result.samples.map(fn(draw){ draw.value }) == [False])
  ensure("MH factor rejection retains the old trace", result.samples.all(fn(draw){ sample-count(draw.trace) == 1 && draw.trace.length == 2 && observed-log-prob(draw.trace) == 0.0 }))

fun test-invalid-factor-mass() : <div,exn> ()
  with fun random-int32() ~1.int32
  [neginf, nan, posinf].foreach fn(weight){
    val spec = Sequential-model(fn(){ () }, fn(_){ log-score(weight); () },
      fn(_, _, _){ Step-output((), ()) }, fn(_){ 7 })
    val model = as-model(0, spec)
    ensure("LWIS does not turn invalid or zero weight into positive mass", lwis(2, empty(), model).is-empty)
    ensure("MH does not retain invalid or zero target states", mh(2, 0, empty(), model).samples.is-empty)
    val filtered = smc(2, 0, empty(), spec)
    val moved = rmsmc(2, 0, 1, empty(), spec)
    val marginal = pmmh(2, 0, default-config(2), empty(), spec)
    val squared = smc2(2, 2, 0, 1, empty(), spec)
    ensure("SMC collapses invalid or zero factor mass", filtered.particles.is-empty && filtered.log-evidence == neginf)
    ensure("RMSMC collapses invalid or zero factor mass", moved.particles.is-empty && moved.log-evidence == neginf)
    ensure("PMMH does not retain invalid or zero estimated likelihood", marginal.samples.is-empty)
    ensure("SMC2 collapses invalid or zero factor mass", squared.particles.is-empty && squared.log-evidence == neginf)
  }

pub fun main() : <console,div,exn> ()
  test-weight-laws()
  test-factor-laws()
  test-inference-factor-integration()
  test-factor-rejection()
  test-invalid-factor-mass()
  println("Handler scoring laws passed.")
