module sequential_observations

import std/num/float64
import std/num/int32
import std/num/random
import alg/lw
import alg/mcmc
import alg/pmmh
import alg/rmsmc
import alg/simulate
import alg/smc
import alg/smc2
import core/env
import core/model
import core/obsvar
import core/sequential
import core/trace
import handlers/sequential

val shared = obs-bool("stream/shared")

fun ensure(label : string, condition : bool) : exn ()
  if not(condition) then throw(label)

fun near(actual : float64, expected : float64) : bool
  abs(actual - expected) < 1.0e-12

// The same stream is consumed in the prior, initial state and twice per step.
// Its shape describes occurrences, never whether a name is global or sequential.
fun shared-spec() : sequential-model<e,bool,list<bool>,bool,list<bool>>
  Sequential-model(
    fn(){ bernoulli(shared, 0.8) },
    fn(parameter){ [parameter, bernoulli(shared, 0.7)] },
    fn(_parameter, _index, previous){
      val first = bernoulli(shared, 0.6)
      val second = bernoulli(shared, 0.3)
      Step-output(previous ++ [first, second], second)
    },
    fn(prefix-state){ prefix-state.current-state })

fun test-shared-stream() : <div,random,exn> ()
  val data = [True, False, True, False, False, True]
  val environment = set(shared, data ++ [False], empty())
  val (whole, remaining) = run-lw-state(environment, as-model(2, shared-spec()))
  val (simulation, simulation-remaining) = simulate-state(environment, as-model(2, shared-spec()))
  ensure("a complete execution consumes every occurrence once", whole.value == data)
  ensure("LW returns only the unconsumed suffix", get(shared, remaining) == [False])
  ensure("simulation returns the same unconsumed suffix", get(shared, simulation-remaining) == [False])
  ensure("simulation and weighting observe the same full trace", simulation.trace.show == whole.trace.show)
  val expected = ln(0.8) + ln(0.3) + ln(0.6) + ln(0.7) + ln(0.4) + ln(0.3)
  ensure("whole-program likelihood agrees with the independent product", near(whole.log-weight, expected))
  val filtered = smc(4, 2, environment, shared-spec())
  ensure("SMC consumes shared streams across all three phases", filtered.particles.all(fn(p){ p.value == data }))
  ensure("SMC preserves whole-program trace addresses and observation modes", filtered.particles.all(fn(p){ p.trace.show == whole.trace.show }))
  ensure("SMC scores every supplied occurrence exactly once", near(filtered.log-evidence, expected))
  [0, 1, 5].foreach fn(moves){
    val moved = rmsmc(4, 2, moves, environment, shared-spec())
    ensure("RMSMC replay preserves observations shared between phases", moved.particles.all(fn(p){ p.value == data }))
    ensure("RMSMC prefix replay preserves the exact full trace", moved.particles.all(fn(p){ p.trace.show == whole.trace.show }))
    ensure("RMSMC replay preserves full likelihood", moved.particles.all(fn(p){ near(p.log-likelihood, expected) }))
    ensure("RMSMC evidence includes shared prior, initial and step factors", near(moved.log-evidence, expected))
  }

fun repeated-spec() : sequential-model<e,(),(),bool,list<bool>>
  Sequential-model(
    fn(){ () }, fn(_parameter){ () },
    fn(_parameter, _index, _previous){ Step-output((), bernoulli(shared, 0.5)) },
    fn(prefix-state){ prefix-state.observations })

fun test-singleton-exhaustion() : <div,exn> ()
  // A missing observation samples False, so reusing True cannot go unnoticed.
  with fun random-int32() ~1.int32
  val environment = set(shared, [True], empty())
  val whole = run-lw(environment, as-model(2, repeated-spec()))
  ensure("the singleton is consumed once in whole-program inference", whole.value == [True, False])
  val filtered = smc(1, 2, environment, repeated-spec())
  ensure("filtering consumes the singleton only once", filtered.particles.map(fn(p){ p.value }) == [[True, False]])
  ensure("a missing second datum contributes no observed likelihood", near(filtered.log-evidence, ln(0.5)))
  [0, 1, 5].foreach fn(moves){
    val moved = rmsmc(1, 2, moves, environment, repeated-spec())
    ensure("rejuvenation and propagation agree when a stream is exhausted", moved.particles.map(fn(p){ p.value }) == [[True, False]])
    ensure("all singleton paths retain one observed and one sampled site", moved.particles.all(fn(p){ p.trace.length == 2 && sample-count(p.trace) == 1 }))
    ensure("RMSMC singleton evidence is invariant under rejuvenation", near(moved.log-evidence, ln(0.5)))
    ensure("RMSMC singleton trace matches ordinary model execution", moved.particles.all(fn(p){ p.trace.show == whole.trace.show }))
  }

fun check-parameter-filter(estimate : smc-result<list<bool>>, expected-data : list<bool>, expected-score : float64) : exn ()
  ensure("the inner filter retains its population", not(estimate.particles.is-empty))
  ensure("the inner filter starts after the prior's consumed occurrence", estimate.particles.all(fn(p){ p.value == expected-data }))
  ensure("the inner filter observes the five remaining initial and step sites", estimate.particles.all(fn(p){ p.trace.length == 5 && sample-count(p.trace) == 0 }))
  ensure("the inner likelihood excludes the already-scored prior factor", near(estimate.log-evidence, expected-score))

fun test-parameter-prior-cursors() : <div,random,exn> ()
  val data = [True, False, True, False, False, True]
  val environment = set(shared, data, empty())
  val parameter-score = fn(parameter){ if parameter then ln(0.8) else neginf }
  val parameter-kernel = fn(_parameter){ (True, set(shared, [True], empty()), 0.0) }
  val expected-inner = ln(0.3) + ln(0.6) + ln(0.7) + ln(0.4) + ln(0.3)
  val default-chain = pmmh(4, 2, default-config(8, 2), environment, shared-spec())
  val custom-chain = pmmh-with(4, 2, default-config(8, 2), environment, shared-spec(), parameter-score, parameter-kernel)
  [default-chain, custom-chain].foreach fn(chain){
    ensure("PMMH retains six posterior draws", chain.samples.length == 6)
    chain.samples.foreach fn(sample){
      ensure("PMMH records the prior observation separately", sample.parameter && get(shared, sample.parameter-env) == [True])
      check-parameter-filter(sample.estimate, data, expected-inner)
    }
  }
  val default-nested = smc2(4, 4, 2, 2, environment, shared-spec())
  val custom-nested = smc2-with(4, 4, 2, 2, environment, shared-spec(), parameter-score, parameter-kernel)
  [default-nested, custom-nested].foreach fn(result){
    ensure("SMC2 retains four outer particles", result.particles.length == 4)
    ensure("SMC2 scores the shared prior occurrence once", near(result.log-evidence, ln(0.8) + expected-inner))
    result.particles.foreach fn(particle){
      ensure("SMC2 records the prior observation separately", particle.parameter && get(shared, particle.parameter-env) == [True])
      check-parameter-filter(particle.estimate, data, expected-inner)
    }
  }

fun conditional-spec() : sequential-model<e,bool,list<bool>,bool,(bool,list<bool>)>
  Sequential-model(
    fn(){ bernoulli'(0.5) },
    fn(parameter){ if parameter then [bernoulli(shared, 0.5)] else [] },
    fn(_parameter, _index, previous){
      val observed = bernoulli(shared, 0.5)
      Step-output(previous ++ [observed], observed)
    },
    fn(prefix-state){ (prefix-state.parameter, prefix-state.current-state) })

fun check-conditional(result : smc-result<(bool,list<bool>)>) : exn ()
  ensure("conditional test retains a nonempty population", not(result.particles.is-empty))
  result.particles.foreach fn(particle){
    val (parameter, values) = particle.value
    val expected = if parameter then [True, False, True] else [True, False]
    ensure("resampling and replay retain each particle's own stream position", values == expected)
    ensure("conditional observation score follows its own occurrence count", near(particle.log-likelihood, float64(expected.length) * ln(0.5)))
    ensure("conditional trace contains one prior sample and the actual observations", particle.trace.length == expected.length + 1 && sample-count(particle.trace) == 1)
  }

fun test-particle-local-cursors() : <div,random,exn> ()
  val environment = set(shared, [True, False, True], empty())
  [619, 631, 641].foreach fn(seed){
    val filtered = pseudo-random(seed, fn(){ smc(24, 2, environment, conditional-spec()) })
    val moved = pseudo-random(seed, fn(){ rmsmc(24, 2, 3, environment, conditional-spec()) })
    check-conditional(filtered)
    check-conditional(moved)
  }

fun test-retained-cursor() : <div,random,exn> ()
  val environment = set(shared, [True, False, True], empty())
  val whole = pseudo-random(653, fn(){ smc-given(4, 3, environment, (), repeated-spec()) })
  val split = pseudo-random(653, fn(){
    val initial = start-smc-given(4, environment, (), repeated-spec())
    val first = advance-smc-state(repeated-spec(), initial)
    val rest = extend-smc-state(2, repeated-spec(), first)
    ensure("advancing retains the original immutable filter", first.step-index == 1)
    finish-smc(repeated-spec(), rest)
  })
  ensure("retained cursor produces the same particle values", split.particles.map(fn(p){ p.value }) == whole.particles.map(fn(p){ p.value }))
  ensure("retained cursor produces the same complete output", split.posterior-env.show == whole.posterior-env.show)
  ensure("retained cursor produces the same evidence", split.log-evidence == whole.log-evidence)

fun test-checkpoint-cursor() : <div,random,exn> ()
  val environment = set(shared, [True, False, True], empty())
  val paused-initial = suspend(fn(){
    run-lw-state(environment, fn(){ checkpointed-prefix(2, (), repeated-spec()) })
  })
  // Advance past the first observation, then run the very same saved
  // continuation twice. Its reader, trace and score must be branch-local.
  val paused-first = advance(paused-initial)
  val (left, left-remaining) = complete(paused-first)
  val (right, right-remaining) = complete(paused-first)
  val (whole, whole-remaining) = run-lw-state(environment, prefix-model-given(2, (), repeated-spec()))
  ensure("a resumed checkpoint preserves the observation cursor", left.value.observations == [True, False])
  ensure("a second resumption starts from the same observation cursor", right.value.observations == [True, False])
  ensure("both checkpoint branches retain the same unconsumed suffix", get(shared, left-remaining) == [True] && get(shared, right-remaining) == [True])
  ensure("checkpoint branching agrees with whole-model consumption", left-remaining.show == whole-remaining.show)
  ensure("checkpoint branches do not share trace mutations", left.trace.show == whole.trace.show && right.trace.show == whole.trace.show)
  ensure("checkpoint branches do not share score accumulation", near(left.log-weight, 2.0 * ln(0.5)) && near(right.log-weight, 2.0 * ln(0.5)))

fun test-appended-observations() : <div,random,exn> ()
  val environment = set(shared, [True, False, True], empty())
  val whole = pseudo-random(659, fn(){ smc-given(4, 3, environment, (), repeated-spec()) })
  val online = pseudo-random(659, fn(){
    val initial = start-smc-given(4, set(shared, [True], empty()), (), repeated-spec())
    val first = advance-smc-state(repeated-spec(), initial)
    val extended = append-smc-observations(set(shared, [False, True], empty()), first)
    ensure("appending observations preserves the filter index", extended.step-index == first.step-index)
    ensure("appending observations does not score them prematurely", extended.log-evidence == first.log-evidence)
    val completed = extend-smc-state(2, repeated-spec(), extended)
    ensure("appending data retains the earlier immutable filter", first.step-index == 1)
    ensure("earlier filter output remains unchanged", finish-smc(repeated-spec(), first).particles.all(fn(p){ p.value == [True] }))
    val still-original = pseudo-random(663, fn(){ advance-smc-state(repeated-spec(), first) })
    ensure("appending does not mutate the original observation cursor", finish-smc(repeated-spec(), still-original).particles.all(fn(p){ sample-count(p.trace) == 1 }))
    ensure("the original exhausted cursor has no new observed likelihood", still-original.log-evidence == first.log-evidence)
    finish-smc(repeated-spec(), completed)
  })
  ensure("online observations produce the same draws as a batch", online.particles.map(fn(p){ p.value }) == whole.particles.map(fn(p){ p.value }))
  ensure("online observations produce the same traces as a batch", online.particles.map(fn(p){ p.trace.show }) == whole.particles.map(fn(p){ p.trace.show }))
  ensure("online observations produce the same output environment", online.posterior-env.show == whole.posterior-env.show)
  ensure("online observations produce the same evidence", online.log-evidence == whole.log-evidence)
  // Newly appended values follow any data already pending in the cursor.
  val pending = pseudo-random(661, fn(){
    val initial = start-smc-given(4, set(shared, [True, False], empty()), (), repeated-spec())
    val first = advance-smc-state(repeated-spec(), initial)
    val extended = append-smc-observations(set(shared, [True], empty()), first)
    finish-smc(repeated-spec(), extend-smc-state(2, repeated-spec(), extended))
  })
  ensure("appended data follow the existing unconsumed suffix", pending.particles.all(fn(p){ p.value == [True, False, True] }))

fun test-stream-slices() : exn ()
  val singleton = set(shared, [True], empty())
  ensure("the zeroth occurrence selects a singleton", get(shared, focus-step(0, singleton)) == [True])
  ensure("a singleton has no second occurrence", get(shared, focus-step(1, singleton)).is-empty)
  ensure("a negative occurrence is absent", get(shared, focus-step(-1, singleton)).is-empty)
  ensure("an empty prefix contains no singleton", get(shared, take-prefix(0, singleton)).is-empty)
  ensure("a one-occurrence prefix contains the singleton", get(shared, take-prefix(1, singleton)) == [True])

pub fun main() : <console,div,random,exn> ()
  test-shared-stream()
  test-singleton-exhaustion()
  test-parameter-prior-cursors()
  test-particle-local-cursors()
  test-retained-cursor()
  test-checkpoint-cursor()
  test-appended-observations()
  test-stream-slices()
  println("Sequential observation stream checks passed.")
