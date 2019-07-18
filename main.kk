public module main

import std/num/double
import std/num/ddouble
import std/time/timer
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
  val data_point               = 6.0
  val particles                = 2000
  val resample_steps           = 131
  val scores_before_resampling = 2
  val trace_mcmc_steps         = 2000

  // Note that if you change any filename - change output/plot_examples.py too if you want to show the histograms.
  /* println("Running Sequential Monte Carlo...")
  print-elapsed {
    write(smc(particles, resample_steps, scores_before_resampling, sequential_gaussian(data_point)), "./gaussian/smc_posterior.csv")
  }
  println("Completed Sequential Monte Carlo!") */

  println("Running Trace MCMC...")
  print-elapsed {
    random_sampler {
      val trace_and_values = tmcmc(sequential_gaussian(data_point), trace_mcmc_steps, Exp(0.0), uniform_proposal_dist).fst
      write(trace_and_values, "./gaussian/trace_posterior.csv")
    }
  }
  println("Completed Trace MCMC!")

  /* run_climate_model(particles, resample_steps, scores_before_resampling) */
  println("Finished running...")
}

fun run_climate_model(pt : int, rs : int, sbrs : int) {

  val data = pre_process_data()

  print-elapsed {
    println("Begin:")
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 0), exn-get(data.fst, 0), False)), "./months/jan/jan_1.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 0), exn-get(data.fst, 0), False)), "./months/jan/jan_2.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 1), exn-get(data.fst, 1), False)), "./months/feb/feb_1.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 1), exn-get(data.fst, 1), False)), "./months/feb/feb_2.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 2), exn-get(data.fst, 2), False)), "./months/mar/mar_1.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 2), exn-get(data.fst, 2), False)), "./months/mar/mar_2.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 3), exn-get(data.fst, 3), False)), "./months/apr/apr_1.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 3), exn-get(data.fst, 3), False)), "./months/apr/apr_2.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 4), exn-get(data.fst, 4), False)), "./months/may/may_1.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 4), exn-get(data.fst, 4), False)), "./months/may/may_2.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 5), exn-get(data.fst, 5), False)), "./months/jun/jun_1.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 5), exn-get(data.fst, 5), False)), "./months/jun/jun_2.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 6), exn-get(data.fst, 6), False)), "./months/jul/jul_1.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 6), exn-get(data.fst, 6), False)), "./months/jul/jul_2.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 7), exn-get(data.fst, 7), False)), "./months/aug/aug_1.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 7), exn-get(data.fst, 7), False)), "./months/aug/aug_2.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 8), exn-get(data.fst, 8), False)), "./months/sep/sep_1.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 8), exn-get(data.fst, 8), False)), "./months/sep/sep_2.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 9), exn-get(data.fst, 9), False)), "./months/oct/oct_1.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 9), exn-get(data.fst, 9), False)), "./months/oct/oct_2.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 10), exn-get(data.fst, 10), False)), "./months/nov/nov_1.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 10), exn-get(data.fst, 10), False)), "./months/nov/nov_2.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 11), exn-get(data.fst, 11), False)), "./months/dec/dec_1.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 11), exn-get(data.fst, 11), False)), "./months/dec/dec_2.csv")}
    println("Mid way!")
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 0), exn-get(data.fst, 0), False)), "./months/jan/jan_3.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 0), exn-get(data.fst, 0), False)), "./months/jan/jan_4.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 1), exn-get(data.fst, 1), False)), "./months/feb/feb_3.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 1), exn-get(data.fst, 1), False)), "./months/feb/feb_4.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 2), exn-get(data.fst, 2), False)), "./months/mar/mar_3.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 2), exn-get(data.fst, 2), False)), "./months/mar/mar_4.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 3), exn-get(data.fst, 3), False)), "./months/apr/apr_3.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 3), exn-get(data.fst, 3), False)), "./months/apr/apr_4.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 4), exn-get(data.fst, 4), False)), "./months/may/may_3.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 4), exn-get(data.fst, 4), False)), "./months/may/may_4.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 5), exn-get(data.fst, 5), False)), "./months/jun/jun_3.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 5), exn-get(data.fst, 5), False)), "./months/jun/jun_4.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 6), exn-get(data.fst, 6), False)), "./months/jul/jul_3.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 6), exn-get(data.fst, 6), False)), "./months/jul/jul_4.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 7), exn-get(data.fst, 7), False)), "./months/aug/aug_3.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 7), exn-get(data.fst, 7), False)), "./months/aug/aug_4.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 8), exn-get(data.fst, 8), False)), "./months/sep/sep_3.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 8), exn-get(data.fst, 8), False)), "./months/sep/sep_4.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 9), exn-get(data.fst, 9), False)), "./months/oct/oct_3.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 9), exn-get(data.fst, 9), False)), "./months/oct/oct_4.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 10), exn-get(data.fst, 10), False)), "./months/nov/nov_3.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 10), exn-get(data.fst, 10), False)), "./months/nov/nov_4.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 11), exn-get(data.fst, 11), False)), "./months/dec/dec_3.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 11), exn-get(data.fst, 11), False)), "./months/dec/dec_4.csv")}
    println("End.")
  }
}
