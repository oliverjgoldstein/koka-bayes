module rmsmc_singleton

// Historical singleton-replay counterexample, now a passing regression.
// Sequential observation streams are consumed once across filtering and replay.

import std/num/float64
import std/num/int32
import std/num/random
import alg/rmsmc
import alg/smc
import core/env
import core/model
import core/obsvar
import core/sequential
import core/trace

val observation = obs-bool("composition/step")

fun ensure(label : string, condition : bool) : exn ()
  if not(condition) then throw(label)

fun spec() : sequential-model<e,(),(),bool,list<bool>>
  Sequential-model(
    fn(){ () },
    fn(_parameter){ () },
    fn(_parameter, _index, _previous){ Step-output((), bernoulli(observation, 0.5)) },
    fn(prefix-state){ prefix-state.observations })

fun run(values : list<bool>, moves : int) : div smc-result<list<bool>>
  with fun random-int32() ~1.int32
  rmsmc(1, 2, moves, set(observation, values, empty()), spec())

fun observed-sites(result : smc-result<a>) : int
  result.particles.foldl(0, fn(acc, p){ acc + p.trace.length - sample-count(p.trace) })

pub fun main() : <console,div,exn> ()
  val singleton-unmoved = run([True], 0)
  val singleton-moved = run([True], 1)
  val singleton-moved-again = run([True], 5)
  val explicit-unmoved = run([True, True], 0)
  val explicit-moved = run([True, True], 1)
  val explicit-moved-again = run([True, True], 5)
  ensure("singleton filtering consumes the observed value once", singleton-unmoved.particles.map(fn(p){ p.value }) == [[True, False]])
  ensure("singleton replay observes once and samples the second value", singleton-moved.particles.map(fn(p){ p.value }) == [[True, False]])
  ensure("singleton replay remains consistent over multiple moves", singleton-moved-again.particles.map(fn(p){ p.value }) == [[True, False]])
  ensure("singleton keeps exactly one observed site", observed-sites(singleton-unmoved) == 1 && observed-sites(singleton-moved) == 1)
  ensure("explicit step data agree before and after one move", explicit-unmoved.particles.map(fn(p){ p.value }) == explicit-moved.particles.map(fn(p){ p.value }))
  ensure("explicit step data agree after many moves", explicit-moved-again.particles.map(fn(p){ p.value }) == [[True, True]])
  ensure("explicit replay retains both observation sites", observed-sites(explicit-moved) == 2 && observed-sites(explicit-moved-again) == 2)
  println("singleton no moves: " ++ singleton-unmoved.particles.map(fn(p){ p.value }).show ++ "; observed sites=" ++ observed-sites(singleton-unmoved).show)
  println("singleton one move: " ++ singleton-moved.particles.map(fn(p){ p.value }).show ++ "; observed sites=" ++ observed-sites(singleton-moved).show)
  println("explicit two-value data: " ++ explicit-moved.particles.map(fn(p){ p.value }).show ++ "; observed sites=" ++ observed-sites(explicit-moved).show)
  println("RMSMC singleton and explicit-stream replay regression checks passed.")
