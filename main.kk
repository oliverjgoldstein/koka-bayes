public module test/koka-bayes/main

import std/num/double
import std/num/ddouble
import test/koka-bayes/output-and-plot
import test/koka-bayes/exponents
import test/koka-bayes/effects-and-types
import test/koka-bayes/sequential
/* import test/koka-bayes/trace */
import test/koka-bayes/model-resources


fun main() {
  val data_point                = 4.0
  val particles                 = 50
  val resample_steps            = 6
  val scores_before_resampling  = 1
  val hist = smc(particles, resample_steps, scores_before_resampling, sequential_gaussian(data_point))
  write(hist)
  /* val trace_mcmc_steps = 10000 */
  /* show(trace_a(tmcmc(sequential_gaussian(), trace_mcmc_steps, Exp(0.0)))) */
}

/* fun test(){
  error("Exception test.")
} */
