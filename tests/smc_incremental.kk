module smc_incremental

import std/num/float64
import std/num/random
import alg/smc
import alg/smc2
import core/env
import core/model
import core/obsvar
import core/sequential

val observation = obs-bool("incremental/y")
val initial-observation = obs-bool("incremental/initial")
val prior-observation = obs-bool("incremental/prior")

fun ensure(message : string, condition : bool) : exn ()
  if !condition then throw(message)

fun spec() : sequential-model<e,(),int,bool,list<int>>
  Sequential-model(
    fn(){ () },
    fn(_p){ if bernoulli'(0.3) then 1 else 0 },
    fn(_p, _index, previous){
      val next = if bernoulli'(if previous == 1 then 0.8 else 0.2) then 1 else 0
      val y = bernoulli(observation, if next == 1 then 0.9 else 0.1)
      Step-output(next, y)
    },
    fn(prefix-state){ prefix-state.states })

fun test-retained-filter() : <exn,div,random> ()
  val environment = set(observation, [True, False, True], empty())
  val whole = pseudo-random(101, fn(){ smc-given(48, 3, environment, (), spec()) })
  val split = pseudo-random(101, fn(){
    val initial = start-smc-given(48, environment, (), spec())
    val first = advance-smc(environment, spec(), initial)
    val rest = extend-smc(2, environment, spec(), first)
    ensure("advancing must preserve the earlier immutable filter", first.step-index == 1)
    ensure("retained filter must advance exactly three steps", rest.step-index == 3)
    finish-smc(spec(), rest)
  })
  ensure("split filtering must preserve particle trajectories and RNG consumption",
         whole.particles.map(fn(p){ p.value }) == split.particles.map(fn(p){ p.value }))
  ensure("split filtering must preserve evidence", whole.log-evidence == split.log-evidence)
  ensure("split filtering must preserve output observations", whole.posterior-env.show == split.posterior-env.show)

fun initial-spec(p : float64) : sequential-model<e,(),(),(),()>
  Sequential-model(
    fn(){ val _ = bernoulli(prior-observation, 0.4); () },
    fn(_parameter){ val _ = bernoulli(initial-observation, p); () },
    fn(_parameter, _index, _previous){ Step-output((), ()) },
    fn(_prefix){ () })

fun test-initial-weight() : <exn,div,random> ()
  val environment = set(prior-observation, [True], set(initial-observation, [True], empty()))
  val result = pseudo-random(103, fn(){ smc(8, 0, environment, initial-spec(0.25)) })
  ensure("SMC must include observations in prior and initial stages", abs(exp(result.log-evidence) - 0.1) < 1.0e-12)
  val given = pseudo-random(107, fn(){ smc-given(8, 0, environment, (), initial-spec(0.25)) })
  ensure("SMC-given must include initial-stage observation likelihood", abs(exp(given.log-evidence) - 0.25) < 1.0e-12)
  val collapsed = pseudo-random(109, fn(){ smc(8, 2, environment, initial-spec(0.0)) })
  ensure("impossible initial observations must collapse the population", collapsed.particles.is-empty && collapsed.log-evidence == neginf)

// A single persistent latent state is observed twice without observation noise.
// Both true observations imply z=true; their likelihood is p, never p*p.
fun persistent-state() : sequential-model<e,float64,bool,bool,float64>
  Sequential-model(
    fn(){ if bernoulli'(0.5) then 0.8 else 0.2 },
    fn(p){ bernoulli'(p) },
    fn(_p, _index, z){ Step-output(z, bernoulli(observation, if z then 1.0 else 0.0)) },
    fn(prefix-state){ prefix-state.parameter })

fun test-smc2-zero-support() : <console,exn,div,random> ()
  val environment = set(observation, [True, True], empty())
  for-seed([211, 419, 839], environment)

fun for-seed(seeds : list<int>, environment : env) : <console,exn,div,random> ()
  match seeds
    Nil -> ()
    Cons(seed, rest) ->
      val result = pseudo-random(seed, fn(){ smc2(2000, 1, 2, 0, environment, persistent-state()) })
      val mean = result.particles.foldl(0.0, fn(acc, p){ acc + p.parameter }) / float64(result.particles.length)
      println("SMC2 persistent latent seed=" ++ seed.show ++ " mean=" ++ mean.show ++ " expected=0.68")
      ensure("SMC2 must retain the latent state across observations", abs(mean - 0.68) < 0.04)
      ensure("SMC2 persistent-state evidence must equal P(z=true)=0.5", abs(exp(result.log-evidence) - 0.5) < 0.05)
      for-seed(rest, environment)

pub fun main() : <console,exn,div,random> ()
  test-retained-filter()
  test-initial-weight()
  test-smc2-zero-support()
  println("incremental SMC regression checks passed")
