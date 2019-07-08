public module test/koka-bayes/main

import std/num/double
import std/num/ddouble
import test/koka-bayes/output-and-plot
import test/koka-bayes/exponents
import test/koka-bayes/effects-and-types
import test/koka-bayes/sequential
import test/koka-bayes/trace
import test/koka-bayes/handlers
import test/koka-bayes/model-resources
import test/koka-bayes/climate-change
import test/koka-bayes/data/preprocessing

fun main() {
  val data_point                = 6.0
  val particles                 = 1000
  val resample_steps            = 20
  val scores_before_resampling  = 1
  val hist                      = smc(particles, resample_steps, scores_before_resampling, sequential_gaussian(data_point))
  write(hist, "gaussian_posterior.csv") // Note that if you change the filename - change plot_examples.py too if you want to show the histograms.
  println("Results of SMC written!")
  val trace_mcmc_steps          = 10000
  println("Estimated Gaussian mean after " + show(trace_mcmc_steps) + " steps with true mean " + show-fixed(data_point) + ": ")
  println(show(trace_a(tmcmc(sequential_gaussian(data_point), trace_mcmc_steps, Exp(0.0)))))
  println("Comment in line 33 and comment out line 34 in trace.kk -- to break this code!")
  val temperatures  = [[12.0,12.0,12.0,12.1,12.1,12.2,12.1,12.0,12.0,12.0,12.1,12.1,12.2,12.1]]
  val uncertainties = [replicate(1.0, 14)]
  val clim_hist = smc(particles, resample_steps, scores_before_resampling, linear_gaussian_climate_data(temperatures, uncertainties))
  write(clim_hist, "temperature_posterior.csv")
}

fun tester() {
  val x = pre_process_data()
  match(x) {
    (a,b) -> {
      println(show(a))
      println(show(b))
    }
  }
}