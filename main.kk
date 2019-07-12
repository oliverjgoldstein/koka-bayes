public module main

import std/num/double
import std/num/ddouble
import output-and-plot
import exponents
import effects-and-types
import sequential
import trace
import handlers
import model-resources
import climate-change
import data/preprocessing
import exn-get

fun main() {
  println("Running code...")
  val data_point                = 6.0
  val particles                 = 200
  val resample_steps            = 250
  val scores_before_resampling  = 2
  val trace_mcmc_steps          = 10000
  
  // Note that if you change any filename - change output/plot_examples.py too if you want to show the histograms.
  write(smc(particles, resample_steps, scores_before_resampling, sequential_gaussian(data_point)), "gaussian_posterior.csv")  
  println("Results of SMC written!")
  
  
  println("Estimated Gaussian mean with trace mcmc after " + show(trace_mcmc_steps) + " steps with true mean " + show-fixed(data_point) + ": ")
  random_sampler {
    println(show(trace_a(tmcmc(sequential_gaussian(data_point), trace_mcmc_steps, Exp(0.0)))))
  }
  
  println("Comment in line 33 and comment out line 34 in trace.kk -- to break this code!")
  
  initialise_climate_model(particles, resample_steps, scores_before_resampling)
  println("Finished running...")
}

fun initialise_climate_model(pt : int, rs : int, sbrs : int) {
  
  val data = pre_process_data()
  // Only do January for the sake of time.
  write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd,  0), exn-get(data.fst, 0))), "temperature_posterior_january.csv")
  /* write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd,  1), exn-get(data.fst, 1))), "temperature_posterior_february.csv")
  write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd,  2), exn-get(data.fst, 2))), "temperature_posterior_march.csv")
  write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd,  3), exn-get(data.fst, 3))), "temperature_posterior_april.csv")
  write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd,  4), exn-get(data.fst, 4))), "temperature_posterior_may.csv")
  write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd,  5), exn-get(data.fst, 5))), "temperature_posterior_june.csv")
  write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd,  6), exn-get(data.fst, 6))), "temperature_posterior_july.csv")
  write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd,  7), exn-get(data.fst, 7))), "temperature_posterior_august.csv")
  write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd,  8), exn-get(data.fst, 8))), "temperature_posterior_september.csv")
  write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd,  9), exn-get(data.fst, 9))), "temperature_posterior_october.csv")
  write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd,  10), exn-get(data.fst, 10))), "temperature_posterior_november.csv")
  write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd,  11), exn-get(data.fst, 11))), "temperature_posterior_december.csv") */
}
