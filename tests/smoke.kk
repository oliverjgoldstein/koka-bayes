module smoke

import std/num/float64
import std/num/random

import alg/mcmc
import alg/lw
import alg/lwis
import alg/mh
import alg/pmmh
import alg/rmsmc
import alg/simulate
import alg/smc
import alg/smc2
import core/env
import core/model
import core/obsvar
import core/trace
import examples/hmm
import examples/linear_regression
import examples/sir

pub val repeated-var = obs-int("smoke/repeated")

struct dependent-output
  flag  : bool
  count : int

fun ensure(message : string, condition : bool) : exn ()
  if condition
    then ()
    else throw(message)

fun repeated-model(count : int = 3) : model<e,list<int>>
  fn(){
    var xs : list<int> := []
    for(count) fn(_i){
      xs := xs ++ [binomial(repeated-var, 5, 0.5)]
    }
    xs
  }

fun dependent-model() : model<e,dependent-output>
  fn(){
    val flag = bernoulli'(0.5)
    val count = binomial'(1, if flag then 1.0 else 0.0)
    Dependent-output(flag, count)
  }

fun has-finite-weight(samples : list<weighted-sample<a>>) : bool
  match samples
    Nil -> False
    Cons(sample, rest) ->
      sample.log-weight > neginf || has-finite-weight(rest)

fun all-dependent-consistent(samples : list<simulate-result<dependent-output>>) : bool
  match samples
    Nil -> True
    Cons(sample, rest) ->
      val expected = if sample.value.flag then 1 else 0
      sample.value.count == expected && all-dependent-consistent(rest)

fun test-missing-observations() : <exn,div,random> ()
  val result = pseudo-random(101, fn(){ simulate(empty(), repeated-model()) })
  ensure("missing observable values should sample", sample-count(result.trace) == 3)
  ensure("sampled values should appear in the output env", get(repeated-var, result.output-env).length == 3)

fun test-extra-observations() : <exn,div,random> ()
  val environment = set(repeated-var, [1, 2, 3, 4], empty())
  val result = pseudo-random(103, fn(){ simulate(environment, repeated-model()) })
  ensure("extra observations should be ignored", get(repeated-var, result.output-env) == [1, 2, 3])
  ensure("fully observed run should not sample repeated sites", sample-count(result.trace) == 0)

fun test-exact-consumption() : <exn,div,random> ()
  val environment = set(repeated-var, [4, 0, 2], empty())
  val result = pseudo-random(107, fn(){ simulate(environment, repeated-model()) })
  ensure("observations should be consumed in runtime order", result.value == [4, 0, 2])
  ensure("exactly supplied observations should be reified in the output env", get(repeated-var, result.output-env) == [4, 0, 2])

fun test-deterministic-addressing() : <exn,div,random> ()
  val first = pseudo-random(109, fn(){ simulate(empty(), repeated-model()) })
  val second = pseudo-random(113, fn(){ simulate(empty(), repeated-model()) })
  ensure("sample addresses should match execution order", sampled-addresses(first.trace) == [0, 1, 2])
  ensure("sample addresses should be independent of sampled values", sampled-addresses(first.trace) == sampled-addresses(second.trace))

fun test-linear-regression-lw() : <exn,div,random> ()
  val xs = [-2.0, -1.0, 0.0, 1.0, 2.0]
  val regression = linear-regression-model(xs)
  val synthetic = pseudo-random(127, fn(){ simulate(empty(), regression) })
  val observed = set(y-var, synthetic.value.ys, empty())
  val samples = pseudo-random(131, fn(){ lw(12, observed, regression) })
  ensure("likelihood weighting should return the requested number of samples", samples.length == 12)
  ensure("likelihood weighting should produce at least one finite weight", has-finite-weight(samples))

fun test-linear-regression-lwis() : <exn,div,random> ()
  val xs = [-2.0, -1.0, 0.0, 1.0, 2.0]
  val regression = linear-regression-model(xs)
  val synthetic = pseudo-random(133, fn(){ simulate(empty(), regression) })
  val observed = set(y-var, synthetic.value.ys, empty())
  val samples = pseudo-random(135, fn(){ lwis(12, observed, regression) })
  ensure("LWIS should return the requested number of resampled outputs", samples.length == 12)
  ensure("LWIS should preserve output shape", samples.all(fn(sample){ sample.ys.length == xs.length }))

fun test-hmm-observations() : <exn,div,random> ()
  val observed-values = [True, False, True, True, False, True]
  val result = pseudo-random(137, fn(){ simulate(set(emission-var, observed-values, empty()), hmm-model()) })
  ensure("HMM observations should be consumed in order", get(emission-var, result.output-env) == observed-values)

fun test-hmm-smc() : <exn,div,random> ()
  val observed-values = [True, False, True, True, False, True]
  val environment = set(emission-var, observed-values, empty())
  val result = pseudo-random(141, fn(){ smc(16, observed-values.length, environment, hmm-sequential()) })
  ensure("SMC should produce the requested number of HMM particles", result.particles.length == 16)
  ensure("SMC should produce at least one HMM trajectory", result.particles.length > 0)

fun test-hmm-rmsmc() : <exn,div,random> ()
  val observed-values = [True, True, False, True, False, False]
  val environment = set(emission-var, observed-values, empty())
  val result = pseudo-random(143, fn(){ rmsmc(12, observed-values.length, 1, environment, hmm-sequential()) })
  ensure("RMSMC should preserve the requested number of HMM particles", result.particles.length == 12)
  ensure("RMSMC should produce finite evidence on the HMM smoke example", result.log-evidence > neginf)

fun test-sir-mh() : <exn,div,random> ()
  val synthetic-env : env =
    set(report-rate-var, [0.25],
    set(gamma-var, [0.01],
    set(beta-var, [0.0008], empty())))
  val synthetic = pseudo-random(139, fn(){ simulate(synthetic-env, sir-model(6)) })
  val inference-env : env =
    set(reported-var, synthetic.value.reports,
    set(gamma-var, [0.01], empty()))
  val posterior = pseudo-random(149, fn(){ mh(20, 5, inference-env, sir-model(6)) })
  ensure("MH should retain post-burnin samples", posterior.samples.length == 15)
  ensure("posterior env should collect beta samples", get(beta-var, posterior.posterior-env).length == 15)

fun test-sir-pmmh() : <exn,div,random> ()
  val synthetic-env : env =
    set(report-rate-var, [0.25],
    set(gamma-var, [0.01],
    set(beta-var, [0.0008], empty())))
  val synthetic = pseudo-random(151, fn(){ simulate(synthetic-env, sir-model(5)) })
  val inference-env : env =
    set(reported-var, synthetic.value.reports,
    set(gamma-var, [0.01], empty()))
  val result = pseudo-random(153, fn(){ pmmh(10, 5, default-config(8, 2), inference-env, sir-sequential()) })
  ensure("PMMH should retain post-burnin samples", result.samples.length == 6)
  ensure("PMMH should collect beta samples", get(beta-var, result.posterior-env).length > 0)

fun test-sir-smc2() : <exn,div,random> ()
  val synthetic-env : env =
    set(report-rate-var, [0.25],
    set(gamma-var, [0.01],
    set(beta-var, [0.0008], empty())))
  val synthetic = pseudo-random(157, fn(){ simulate(synthetic-env, sir-model(5)) })
  val inference-env : env =
    set(reported-var, synthetic.value.reports,
    set(gamma-var, [0.01], empty()))
  val result = pseudo-random(159, fn(){ smc2(8, 8, 5, 1, inference-env, sir-sequential()) })
  ensure("SMC2 should maintain the requested number of parameter particles", result.particles.length == 8)
  ensure("SMC2 should collect beta samples", get(beta-var, result.posterior-env).length > 0)

fun test-mh-regenerates-suffix() : <exn,div,random> ()
  val posterior = pseudo-random(163, fn(){ mh(60, 10, empty(), dependent-model()) })
  ensure("MH should regenerate dependent suffix samples after a proposal", all-dependent-consistent(posterior.samples))

pub fun main() : <console,exn,div,random> ()
  test-missing-observations()
  test-extra-observations()
  test-exact-consumption()
  test-deterministic-addressing()
  test-linear-regression-lw()
  test-linear-regression-lwis()
  test-hmm-observations()
  test-hmm-smc()
  test-hmm-rmsmc()
  test-sir-mh()
  test-sir-pmmh()
  test-sir-smc2()
  test-mh-regenerates-suffix()
  println("smoke checks passed")
