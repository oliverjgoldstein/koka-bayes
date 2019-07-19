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
  val t_steps                  = 100000

  // Note that if you change any filename - change output/plot_examples.py too if you want to show the histograms.
  /* println("Running Sequential Monte Carlo...")
  print-elapsed {
    write(smc(particles, resample_steps, scores_before_resampling, sequential_gaussian(data_point)), "./gaussian/smc_posterior.csv")
  }
  println("Completed Sequential Monte Carlo!") */

  println("Running Trace MCMC...")
  print-elapsed {
    random_sampler {
      val trace_and_values = tmcmc(sequential_gaussian(data_point), 2000, Exp(0.0), uniform_proposal_dist, 0).fst
      write(trace_and_values, "./gaussian/trace_posterior.csv")
    }
  }
  println("Completed Trace MCMC!")

  run_climate_model(particles, resample_steps, scores_before_resampling, t_steps)
  println("Finished running...")
}

fun run_climate_model(pt : int, rs : int, sbrs : int, t_steps : int) {

  val data = pre_process_data()

  print-elapsed {
    random_sampler {
      println("Begin TMCMC:")
      print-elapsed{write(tmcmc(linear_gaussian_climate_data(exn-get(data.snd, 0), exn-get(data.fst, 0), False, 10.0, -3.0), t_steps, Exp(0.0), uniform_proposal_dist, 98000).fst, "./months/jan/jan_1.csv")}
      /* print-elapsed{write(tmcmc(linear_gaussian_climate_data(exn-get(data.snd, 0), exn-get(data.fst, 0), False, 10.0, -3.0), t_steps, Exp(0.0), uniform_proposal_dist).fst, "./months/jan/jan_2.csv")}
      print-elapsed{write(tmcmc(linear_gaussian_climate_data(exn-get(data.snd, 1), exn-get(data.fst, 1), False, 8.0 , -1.0), t_steps, Exp(0.0), uniform_proposal_dist).fst, "./months/feb/feb_1.csv")}
      print-elapsed{write(tmcmc(linear_gaussian_climate_data(exn-get(data.snd, 1), exn-get(data.fst, 1), False, 8.0 , -1.0), t_steps, Exp(0.0), uniform_proposal_dist).fst, "./months/feb/feb_2.csv")}
      print-elapsed{write(tmcmc(linear_gaussian_climate_data(exn-get(data.snd, 2), exn-get(data.fst, 2), False, 7.0 ,  1.0), t_steps, Exp(0.0), uniform_proposal_dist).fst, "./months/mar/mar_1.csv")}
      print-elapsed{write(tmcmc(linear_gaussian_climate_data(exn-get(data.snd, 2), exn-get(data.fst, 2), False, 7.0 ,  1.0), t_steps, Exp(0.0), uniform_proposal_dist).fst, "./months/mar/mar_2.csv")}
      print-elapsed{write(tmcmc(linear_gaussian_climate_data(exn-get(data.snd, 3), exn-get(data.fst, 3), False, 6.0 ,  5.0), t_steps, Exp(0.0), uniform_proposal_dist).fst, "./months/apr/apr_1.csv")}
      print-elapsed{write(tmcmc(linear_gaussian_climate_data(exn-get(data.snd, 3), exn-get(data.fst, 3), False, 6.0 ,  5.0), t_steps, Exp(0.0), uniform_proposal_dist).fst, "./months/apr/apr_2.csv")}
      print-elapsed{write(tmcmc(linear_gaussian_climate_data(exn-get(data.snd, 4), exn-get(data.fst, 4), False, 8.0 ,  9.0), t_steps, Exp(0.0), uniform_proposal_dist).fst, "./months/may/may_1.csv")}
      print-elapsed{write(tmcmc(linear_gaussian_climate_data(exn-get(data.snd, 4), exn-get(data.fst, 4), False, 8.0 ,  9.0), t_steps, Exp(0.0), uniform_proposal_dist).fst, "./months/may/may_2.csv")}
      print-elapsed{write(tmcmc(linear_gaussian_climate_data(exn-get(data.snd, 5), exn-get(data.fst, 5), False, 8.0 , 10.0), t_steps, Exp(0.0), uniform_proposal_dist).fst, "./months/jun/jun_1.csv")}
      print-elapsed{write(tmcmc(linear_gaussian_climate_data(exn-get(data.snd, 5), exn-get(data.fst, 5), False, 8.0 , 10.0), t_steps, Exp(0.0), uniform_proposal_dist).fst, "./months/jun/jun_2.csv")}
      print-elapsed{write(tmcmc(linear_gaussian_climate_data(exn-get(data.snd, 6), exn-get(data.fst, 6), False, 9.0 , 11.0), t_steps, Exp(0.0), uniform_proposal_dist).fst, "./months/jul/jul_1.csv")}
      print-elapsed{write(tmcmc(linear_gaussian_climate_data(exn-get(data.snd, 6), exn-get(data.fst, 6), False, 9.0 , 11.0), t_steps, Exp(0.0), uniform_proposal_dist).fst, "./months/jul/jul_2.csv")}
      print-elapsed{write(tmcmc(linear_gaussian_climate_data(exn-get(data.snd, 7), exn-get(data.fst, 7), False, 6.0 , 11.0), t_steps, Exp(0.0), uniform_proposal_dist).fst, "./months/aug/aug_1.csv")}
      print-elapsed{write(tmcmc(linear_gaussian_climate_data(exn-get(data.snd, 7), exn-get(data.fst, 7), False, 6.0 , 11.0), t_steps, Exp(0.0), uniform_proposal_dist).fst, "./months/aug/aug_2.csv")}
      print-elapsed{write(tmcmc(linear_gaussian_climate_data(exn-get(data.snd, 8), exn-get(data.fst, 8), False, 5.0 , 10.0), t_steps, Exp(0.0), uniform_proposal_dist).fst, "./months/sep/sep_1.csv")}
      print-elapsed{write(tmcmc(linear_gaussian_climate_data(exn-get(data.snd, 8), exn-get(data.fst, 8), False, 5.0 , 10.0), t_steps, Exp(0.0), uniform_proposal_dist).fst, "./months/sep/sep_2.csv")}
      print-elapsed{write(tmcmc(linear_gaussian_climate_data(exn-get(data.snd, 9), exn-get(data.fst, 9), False, 9.0 ,  1.0), t_steps, Exp(0.0), uniform_proposal_dist).fst, "./months/oct/oct_1.csv")}
      print-elapsed{write(tmcmc(linear_gaussian_climate_data(exn-get(data.snd, 9), exn-get(data.fst, 9), False, 9.0 ,  1.0), t_steps, Exp(0.0), uniform_proposal_dist).fst, "./months/oct/oct_2.csv")}
      print-elapsed{write(tmcmc(linear_gaussian_climate_data(exn-get(data.snd, 10), exn-get(data.fst, 10), False, 7.0, 2.0), t_steps, Exp(0.0), uniform_proposal_dist).fst, "./months/nov/nov_1.csv")}
      print-elapsed{write(tmcmc(linear_gaussian_climate_data(exn-get(data.snd, 10), exn-get(data.fst, 10), False, 7.0, 2.0), t_steps, Exp(0.0), uniform_proposal_dist).fst, "./months/nov/nov_2.csv")}
      print-elapsed{write(tmcmc(linear_gaussian_climate_data(exn-get(data.snd, 11), exn-get(data.fst, 11), False, 6.0, -1.0), t_steps, Exp(0.0), uniform_proposal_dist).fst, "./months/dec/dec_1.csv")}
      print-elapsed{write(tmcmc(linear_gaussian_climate_data(exn-get(data.snd, 11), exn-get(data.fst, 11), False, 6.0, -1.0), t_steps, Exp(0.0), uniform_proposal_dist).fst, "./months/dec/dec_2.csv")}
      println("Mid way!")
      print-elapsed{write(tmcmc(linear_gaussian_climate_data(exn-get(data.snd, 0), exn-get(data.fst, 0), False , 10.0, -3.0), t_steps, Exp(0.0), uniform_proposal_dist).fst, "./months/jan/jan_3.csv")}
      print-elapsed{write(tmcmc(linear_gaussian_climate_data(exn-get(data.snd, 0), exn-get(data.fst, 0), False , 10.0, -3.0), t_steps, Exp(0.0), uniform_proposal_dist).fst, "./months/jan/jan_4.csv")}
      print-elapsed{write(tmcmc(linear_gaussian_climate_data(exn-get(data.snd, 1), exn-get(data.fst, 1), False , 8.0 , -1.0), t_steps, Exp(0.0), uniform_proposal_dist).fst, "./months/feb/feb_3.csv")}
      print-elapsed{write(tmcmc(linear_gaussian_climate_data(exn-get(data.snd, 1), exn-get(data.fst, 1), False , 8.0 , -1.0), t_steps, Exp(0.0), uniform_proposal_dist).fst, "./months/feb/feb_4.csv")}
      print-elapsed{write(tmcmc(linear_gaussian_climate_data(exn-get(data.snd, 2), exn-get(data.fst, 2), False , 7.0 ,  1.0), t_steps, Exp(0.0), uniform_proposal_dist).fst, "./months/mar/mar_3.csv")}
      print-elapsed{write(tmcmc(linear_gaussian_climate_data(exn-get(data.snd, 2), exn-get(data.fst, 2), False , 7.0 ,  1.0), t_steps, Exp(0.0), uniform_proposal_dist).fst, "./months/mar/mar_4.csv")}
      print-elapsed{write(tmcmc(linear_gaussian_climate_data(exn-get(data.snd, 3), exn-get(data.fst, 3), False , 6.0 ,  5.0), t_steps, Exp(0.0), uniform_proposal_dist).fst, "./months/apr/apr_3.csv")}
      print-elapsed{write(tmcmc(linear_gaussian_climate_data(exn-get(data.snd, 3), exn-get(data.fst, 3), False , 6.0 ,  5.0), t_steps, Exp(0.0), uniform_proposal_dist).fst, "./months/apr/apr_4.csv")}
      print-elapsed{write(tmcmc(linear_gaussian_climate_data(exn-get(data.snd, 4), exn-get(data.fst, 4), False , 8.0 ,  9.0), t_steps, Exp(0.0), uniform_proposal_dist).fst, "./months/may/may_3.csv")}
      print-elapsed{write(tmcmc(linear_gaussian_climate_data(exn-get(data.snd, 4), exn-get(data.fst, 4), False , 8.0 ,  9.0), t_steps, Exp(0.0), uniform_proposal_dist).fst, "./months/may/may_4.csv")}
      print-elapsed{write(tmcmc(linear_gaussian_climate_data(exn-get(data.snd, 5), exn-get(data.fst, 5), False , 8.0 , 10.0), t_steps, Exp(0.0), uniform_proposal_dist).fst, "./months/jun/jun_3.csv")}
      print-elapsed{write(tmcmc(linear_gaussian_climate_data(exn-get(data.snd, 5), exn-get(data.fst, 5), False , 8.0 , 10.0), t_steps, Exp(0.0), uniform_proposal_dist).fst, "./months/jun/jun_4.csv")}
      print-elapsed{write(tmcmc(linear_gaussian_climate_data(exn-get(data.snd, 6), exn-get(data.fst, 6), False , 9.0 , 11.0), t_steps, Exp(0.0), uniform_proposal_dist).fst, "./months/jul/jul_3.csv")}
      print-elapsed{write(tmcmc(linear_gaussian_climate_data(exn-get(data.snd, 6), exn-get(data.fst, 6), False , 9.0 , 11.0), t_steps, Exp(0.0), uniform_proposal_dist).fst, "./months/jul/jul_4.csv")}
      print-elapsed{write(tmcmc(linear_gaussian_climate_data(exn-get(data.snd, 7), exn-get(data.fst, 7), False , 6.0 , 11.0), t_steps, Exp(0.0), uniform_proposal_dist).fst, "./months/aug/aug_3.csv")}
      print-elapsed{write(tmcmc(linear_gaussian_climate_data(exn-get(data.snd, 7), exn-get(data.fst, 7), False , 6.0 , 11.0), t_steps, Exp(0.0), uniform_proposal_dist).fst, "./months/aug/aug_4.csv")}
      print-elapsed{write(tmcmc(linear_gaussian_climate_data(exn-get(data.snd, 8), exn-get(data.fst, 8), False , 5.0 , 10.0), t_steps, Exp(0.0), uniform_proposal_dist).fst, "./months/sep/sep_3.csv")}
      print-elapsed{write(tmcmc(linear_gaussian_climate_data(exn-get(data.snd, 8), exn-get(data.fst, 8), False , 5.0 , 10.0), t_steps, Exp(0.0), uniform_proposal_dist).fst, "./months/sep/sep_4.csv")}
      print-elapsed{write(tmcmc(linear_gaussian_climate_data(exn-get(data.snd, 9), exn-get(data.fst, 9), False , 9.0 ,  1.0), t_steps, Exp(0.0), uniform_proposal_dist).fst, "./months/oct/oct_3.csv")}
      print-elapsed{write(tmcmc(linear_gaussian_climate_data(exn-get(data.snd, 9), exn-get(data.fst, 9), False , 9.0 ,  1.0), t_steps, Exp(0.0), uniform_proposal_dist).fst, "./months/oct/oct_4.csv")}
      print-elapsed{write(tmcmc(linear_gaussian_climate_data(exn-get(data.snd, 10), exn-get(data.fst, 10), False , 7.0, 2.0), t_steps, Exp(0.0), uniform_proposal_dist).fst, "./months/nov/nov_3.csv")}
      print-elapsed{write(tmcmc(linear_gaussian_climate_data(exn-get(data.snd, 10), exn-get(data.fst, 10), False , 7.0, 2.0), t_steps, Exp(0.0), uniform_proposal_dist).fst, "./months/nov/nov_4.csv")}
      print-elapsed{write(tmcmc(linear_gaussian_climate_data(exn-get(data.snd, 11), exn-get(data.fst, 11), False , 6.0, -1.0), t_steps, Exp(0.0), uniform_proposal_dist).fst, "./months/dec/dec_3.csv")}
      print-elapsed{write(tmcmc(linear_gaussian_climate_data(exn-get(data.snd, 11), exn-get(data.fst, 11), False , 6.0, -1.0), t_steps, Exp(0.0), uniform_proposal_dist).fst, "./months/dec/dec_4.csv")}
      println("End of TMCMC.")
    }
  }



  print-elapsed {
    println("Begin SMC:")
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 0), exn-get(data.fst, 0), False, 10.0, -3.0)), "./months/jan/jan_5.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 0), exn-get(data.fst, 0), False, 10.0, -3.0)), "./months/jan/jan_6.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 1), exn-get(data.fst, 1), False, 8.0 , -1.0)), "./months/feb/feb_5.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 1), exn-get(data.fst, 1), False, 8.0 , -1.0)), "./months/feb/feb_6.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 2), exn-get(data.fst, 2), False, 7.0 ,  1.0)), "./months/mar/mar_5.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 2), exn-get(data.fst, 2), False, 7.0 ,  1.0)), "./months/mar/mar_6.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 3), exn-get(data.fst, 3), False, 6.0 ,  5.0)), "./months/apr/apr_5.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 3), exn-get(data.fst, 3), False, 6.0 ,  5.0)), "./months/apr/apr_6.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 4), exn-get(data.fst, 4), False, 8.0 ,  9.0)), "./months/may/may_5.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 4), exn-get(data.fst, 4), False, 8.0 ,  9.0)), "./months/may/may_6.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 5), exn-get(data.fst, 5), False, 8.0 , 10.0)), "./months/jun/jun_5.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 5), exn-get(data.fst, 5), False, 8.0 , 10.0)), "./months/jun/jun_6.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 6), exn-get(data.fst, 6), False, 9.0 , 11.0)), "./months/jul/jul_5.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 6), exn-get(data.fst, 6), False, 9.0 , 11.0)), "./months/jul/jul_6.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 7), exn-get(data.fst, 7), False, 6.0 , 11.0)), "./months/aug/aug_5.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 7), exn-get(data.fst, 7), False, 6.0 , 11.0)), "./months/aug/aug_6.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 8), exn-get(data.fst, 8), False, 5.0 , 10.0)), "./months/sep/sep_5.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 8), exn-get(data.fst, 8), False, 5.0 , 10.0)), "./months/sep/sep_6.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 9), exn-get(data.fst, 9), False, 9.0 ,  1.0)), "./months/oct/oct_5.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 9), exn-get(data.fst, 9), False, 9.0 ,  1.0)), "./months/oct/oct_6.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 10), exn-get(data.fst, 10), False, 7.0, 2.0)), "./months/nov/nov_5.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 10), exn-get(data.fst, 10), False, 7.0, 2.0)), "./months/nov/nov_6.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 11), exn-get(data.fst, 11), False, 6.0, -1.0)), "./months/dec/dec_5.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 11), exn-get(data.fst, 11), False, 6.0, -1.0)), "./months/dec/dec_6.csv")}
    println("Mid way!")
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 0), exn-get(data.fst, 0), False , 10.0, -3.0)), "./months/jan/jan_7.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 0), exn-get(data.fst, 0), False , 10.0, -3.0)), "./months/jan/jan_8.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 1), exn-get(data.fst, 1), False , 8.0 , -1.0)), "./months/feb/feb_7.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 1), exn-get(data.fst, 1), False , 8.0 , -1.0)), "./months/feb/feb_8.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 2), exn-get(data.fst, 2), False , 7.0 ,  1.0)), "./months/mar/mar_7.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 2), exn-get(data.fst, 2), False , 7.0 ,  1.0)), "./months/mar/mar_8.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 3), exn-get(data.fst, 3), False , 6.0 ,  5.0)), "./months/apr/apr_7.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 3), exn-get(data.fst, 3), False , 6.0 ,  5.0)), "./months/apr/apr_8.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 4), exn-get(data.fst, 4), False , 8.0 ,  9.0)), "./months/may/may_7.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 4), exn-get(data.fst, 4), False , 8.0 ,  9.0)), "./months/may/may_8.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 5), exn-get(data.fst, 5), False , 8.0 , 10.0)), "./months/jun/jun_7.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 5), exn-get(data.fst, 5), False , 8.0 , 10.0)), "./months/jun/jun_8.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 6), exn-get(data.fst, 6), False , 9.0 , 11.0)), "./months/jul/jul_7.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 6), exn-get(data.fst, 6), False , 9.0 , 11.0)), "./months/jul/jul_8.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 7), exn-get(data.fst, 7), False , 6.0 , 11.0)), "./months/aug/aug_7.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 7), exn-get(data.fst, 7), False , 6.0 , 11.0)), "./months/aug/aug_8.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 8), exn-get(data.fst, 8), False , 5.0 , 10.0)), "./months/sep/sep_7.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 8), exn-get(data.fst, 8), False , 5.0 , 10.0)), "./months/sep/sep_8.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 9), exn-get(data.fst, 9), False , 9.0 ,  1.0)), "./months/oct/oct_7.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 9), exn-get(data.fst, 9), False , 9.0 ,  1.0)), "./months/oct/oct_8.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 10), exn-get(data.fst, 10), False , 7.0, 2.0)), "./months/nov/nov_7.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 10), exn-get(data.fst, 10), False , 7.0, 2.0)), "./months/nov/nov_8.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 11), exn-get(data.fst, 11), False , 6.0, -1.0)), "./months/dec/dec_7.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 11), exn-get(data.fst, 11), False , 6.0, -1.0)), "./months/dec/dec_8.csv")}
    println("End of SMC.") */
  }
  }
}
