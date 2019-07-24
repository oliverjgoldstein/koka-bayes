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
  val t_steps                  = 50000

  // Note that if you change any filename - change output/plot_examples.py too if you want to show the histograms.
  /* println("Running Sequential Monte Carlo...")
  print-elapsed {
    write(smc(particles, resample_steps, scores_before_resampling, sequential_gaussian(data_point)), "./gaussian/smc_posterior.csv")
  }
  println("Completed Sequential Monte Carlo!")

  println("Running Trace MCMC...")
  print-elapsed {
    random_sampler {
      val trace_and_values = tmcmc(sequential_gaussian(data_point), 2000, Exp(0.0), gaussian_proposal_dist, 0).fst
      write(trace_and_values, "./gaussian/trace_posterior.csv")
    }
  }
  println("Completed Trace MCMC!") */

  run_climate_model(2, 2, 2, 2, 0)
  println("Finished running...")
}

fun run_experiments() {
  val data_1000 = 1.0
  val data_900 = 1.0
  val data_800 = 1.0
  val data_700 = 1.0
  val data_600 = 1.0
  val data_500 = 1.0
  val data_400 = 1.0
  val data_300 = 1.0
  val data_200 = 1.0
  val data_100 = 1.0
  val data_50  = 1.0
  val data_0   = 1.0

  println("Running Sequential Monte Carlo...")
  print-elapsed {
    // increasing data set size:
    print-elapsed {smc(100, 1000, 1, sequential_gaussian(data_1000))}
    print-elapsed {smc(100, 900, 1,  sequential_gaussian(data_900))}
    print-elapsed {smc(100, 800, 1,  sequential_gaussian(data_800))}
    print-elapsed {smc(100, 700, 1,  sequential_gaussian(data_700))}
    print-elapsed {smc(100, 600, 1,  sequential_gaussian(data_600))}
    print-elapsed {smc(100, 500, 1,  sequential_gaussian(data_500))}
    print-elapsed {smc(100, 400, 1,  sequential_gaussian(data_400))}
    print-elapsed {smc(100, 300, 1,  sequential_gaussian(data_300))}
    print-elapsed {smc(100, 200, 1,  sequential_gaussian(data_200))}
    print-elapsed {smc(100, 100, 1,  sequential_gaussian(data_100))}
    print-elapsed {smc(100, 1, 1,    sequential_gaussian(data_0  ))}

    println("Mid-way")

    print-elapsed {smc(1000, 50, 1, sequential_gaussian(data_50))}
    print-elapsed {smc(900, 50, 1,  sequential_gaussian(data_50))}
    print-elapsed {smc(800, 50, 1,  sequential_gaussian(data_50))}
    print-elapsed {smc(700, 50, 1,  sequential_gaussian(data_50))}
    print-elapsed {smc(600, 50, 1,  sequential_gaussian(data_50))}
    print-elapsed {smc(500, 50, 1,  sequential_gaussian(data_50))}
    print-elapsed {smc(400, 50, 1,  sequential_gaussian(data_50))}
    print-elapsed {smc(300, 50, 1,  sequential_gaussian(data_50))}
    print-elapsed {smc(200, 50, 1,  sequential_gaussian(data_50))}
    print-elapsed {smc(100, 50, 1,  sequential_gaussian(data_50))}
  }
  println("Completed Sequential Monte Carlo!")


  println("Running Trace MCMC...")
  print-elapsed {
    // increasing data set size:
    print-elapsed {tmcmc(sequential_gaussian(data_1000),100, Exp(0.0), gaussian_proposal_dist, 0)}
    print-elapsed {tmcmc(sequential_gaussian(data_900), 100, Exp(0.0), gaussian_proposal_dist, 0)}
    print-elapsed {tmcmc(sequential_gaussian(data_800), 100, Exp(0.0), gaussian_proposal_dist, 0)}
    print-elapsed {tmcmc(sequential_gaussian(data_700), 100, Exp(0.0), gaussian_proposal_dist, 0)}
    print-elapsed {tmcmc(sequential_gaussian(data_600), 100, Exp(0.0), gaussian_proposal_dist, 0)}
    print-elapsed {tmcmc(sequential_gaussian(data_500), 100, Exp(0.0), gaussian_proposal_dist, 0)}
    print-elapsed {tmcmc(sequential_gaussian(data_400), 100, Exp(0.0), gaussian_proposal_dist, 0)}
    print-elapsed {tmcmc(sequential_gaussian(data_300), 100, Exp(0.0), gaussian_proposal_dist, 0)}
    print-elapsed {tmcmc(sequential_gaussian(data_200), 100, Exp(0.0), gaussian_proposal_dist, 0)}
    print-elapsed {tmcmc(sequential_gaussian(data_100), 100, Exp(0.0), gaussian_proposal_dist, 0)}
    print-elapsed {tmcmc(sequential_gaussian(data_0),   100, Exp(0.0), gaussian_proposal_dist, 0)}
  }

  println("Mid-way")

  print-elapsed {
    // increasing data set size:
    print-elapsed {tmcmc(sequential_gaussian(data_50), 1000, Exp(0.0), gaussian_proposal_dist, 0)}
    print-elapsed {tmcmc(sequential_gaussian(data_50), 900,  Exp(0.0), gaussian_proposal_dist, 0)}
    print-elapsed {tmcmc(sequential_gaussian(data_50), 800,  Exp(0.0), gaussian_proposal_dist, 0)}
    print-elapsed {tmcmc(sequential_gaussian(data_50), 700,  Exp(0.0), gaussian_proposal_dist, 0)}
    print-elapsed {tmcmc(sequential_gaussian(data_50), 600,  Exp(0.0), gaussian_proposal_dist, 0)}
    print-elapsed {tmcmc(sequential_gaussian(data_50), 500,  Exp(0.0), gaussian_proposal_dist, 0)}
    print-elapsed {tmcmc(sequential_gaussian(data_50), 400,  Exp(0.0), gaussian_proposal_dist, 0)}
    print-elapsed {tmcmc(sequential_gaussian(data_50), 300,  Exp(0.0), gaussian_proposal_dist, 0)}
    print-elapsed {tmcmc(sequential_gaussian(data_50), 200,  Exp(0.0), gaussian_proposal_dist, 0)}
    print-elapsed {tmcmc(sequential_gaussian(data_50), 100,  Exp(0.0), gaussian_proposal_dist, 0)}
  }
  println("Completed Trace MCMC!")
}

fun run_climate_model(pt : int, rs : int, sbrs : int, t_steps : int, burnin : int) {

  val data = pre_process_data()

  /* ./months/jan/jan_1.
  ./months/jan/jan_2.
  ./months/feb/feb_1.
  ./months/feb/feb_2.
  ./months/mar/mar_1.
  ./months/mar/mar_2.
  ./months/apr/apr_1.
  ./months/apr/apr_2.
  ./months/may/may_1.
  ./months/may/may_2.
  ./months/jun/jun_1.
  ./months/jun/jun_2.
  ./months/jul/jul_1.
  ./months/jul/jul_2.
  ./months/aug/aug_1.
  ./months/aug/aug_2.
  ./months/sep/sep_1.
  ./months/sep/sep_2.
  ./months/oct/oct_1.
  ./months/oct/oct_2.
  ./months/nov/nov_1.
  ./months/nov/nov_2.
  ./months/dec/dec_1.
  ./months/dec/dec_2. */

  print-elapsed {
    random_sampler {
      println("Begin TMCMC:")
      print-elapsed{write(tmcmc(linear_gaussian_climate_data(exn-get(data.snd, 0), exn-get(data.fst, 0), False, 10.0, -3.0, 4.7), t_steps, Exp(0.0), gaussian_proposal_dist, burnin).fst, "./whatever.csv")}
      print-elapsed{write(tmcmc(linear_gaussian_climate_data(exn-get(data.snd, 0), exn-get(data.fst, 0), False, 10.0, -3.0, 4.7), t_steps, Exp(0.0), gaussian_proposal_dist, burnin).fst, "./whatever.csv")}
      print-elapsed{write(tmcmc(linear_gaussian_climate_data(exn-get(data.snd, 1), exn-get(data.fst, 1), False, 8.0 , -1.0, 4.7), t_steps, Exp(0.0), gaussian_proposal_dist, burnin).fst, "./whatever.csv")}
      print-elapsed{write(tmcmc(linear_gaussian_climate_data(exn-get(data.snd, 1), exn-get(data.fst, 1), False, 8.0 , -1.0, 4.7), t_steps, Exp(0.0), gaussian_proposal_dist, burnin).fst, "./whatever.csv")}
      print-elapsed{write(tmcmc(linear_gaussian_climate_data(exn-get(data.snd, 2), exn-get(data.fst, 2), False, 7.0 ,  1.0, 4.7), t_steps, Exp(0.0), gaussian_proposal_dist, burnin).fst, "./whatever.csv")}
      print-elapsed{write(tmcmc(linear_gaussian_climate_data(exn-get(data.snd, 2), exn-get(data.fst, 2), False, 7.0 ,  1.0, 4.7), t_steps, Exp(0.0), gaussian_proposal_dist, burnin).fst, "./whatever.csv")}
      print-elapsed{write(tmcmc(linear_gaussian_climate_data(exn-get(data.snd, 3), exn-get(data.fst, 3), False, 6.0 ,  5.0, 4.7), t_steps, Exp(0.0), gaussian_proposal_dist, burnin).fst, "./whatever.csv")}
      print-elapsed{write(tmcmc(linear_gaussian_climate_data(exn-get(data.snd, 3), exn-get(data.fst, 3), False, 6.0 ,  5.0, 4.7), t_steps, Exp(0.0), gaussian_proposal_dist, burnin).fst, "./whatever.csv")}
      print-elapsed{write(tmcmc(linear_gaussian_climate_data(exn-get(data.snd, 4), exn-get(data.fst, 4), False, 8.0 ,  9.0, 4.7), t_steps, Exp(0.0), gaussian_proposal_dist, burnin).fst, "./whatever.csv")}
      print-elapsed{write(tmcmc(linear_gaussian_climate_data(exn-get(data.snd, 4), exn-get(data.fst, 4), False, 8.0 ,  9.0, 4.7), t_steps, Exp(0.0), gaussian_proposal_dist, burnin).fst, "./whatever.csv")}
      print-elapsed{write(tmcmc(linear_gaussian_climate_data(exn-get(data.snd, 5), exn-get(data.fst, 5), False, 8.0 , 10.0, 4.7), t_steps, Exp(0.0), gaussian_proposal_dist, burnin).fst, "./whatever.csv")}
      print-elapsed{write(tmcmc(linear_gaussian_climate_data(exn-get(data.snd, 5), exn-get(data.fst, 5), False, 8.0 , 10.0, 4.7), t_steps, Exp(0.0), gaussian_proposal_dist, burnin).fst, "./whatever.csv")}
      print-elapsed{write(tmcmc(linear_gaussian_climate_data(exn-get(data.snd, 6), exn-get(data.fst, 6), False, 9.0 , 11.0, 4.7), t_steps, Exp(0.0), gaussian_proposal_dist, burnin).fst, "./whatever.csv")}
      print-elapsed{write(tmcmc(linear_gaussian_climate_data(exn-get(data.snd, 6), exn-get(data.fst, 6), False, 9.0 , 11.0, 4.7), t_steps, Exp(0.0), gaussian_proposal_dist, burnin).fst, "./whatever.csv")}
      print-elapsed{write(tmcmc(linear_gaussian_climate_data(exn-get(data.snd, 7), exn-get(data.fst, 7), False, 6.0 , 11.0, 4.7), t_steps, Exp(0.0), gaussian_proposal_dist, burnin).fst, "./whatever.csv")}
      print-elapsed{write(tmcmc(linear_gaussian_climate_data(exn-get(data.snd, 7), exn-get(data.fst, 7), False, 6.0 , 11.0, 4.7), t_steps, Exp(0.0), gaussian_proposal_dist, burnin).fst, "./whatever.csv")}
      print-elapsed{write(tmcmc(linear_gaussian_climate_data(exn-get(data.snd, 8), exn-get(data.fst, 8), False, 5.0 , 10.0, 4.7), t_steps, Exp(0.0), gaussian_proposal_dist, burnin).fst, "./whatever.csv")}
      print-elapsed{write(tmcmc(linear_gaussian_climate_data(exn-get(data.snd, 8), exn-get(data.fst, 8), False, 5.0 , 10.0, 4.7), t_steps, Exp(0.0), gaussian_proposal_dist, burnin).fst, "./whatever.csv")}
      print-elapsed{write(tmcmc(linear_gaussian_climate_data(exn-get(data.snd, 9), exn-get(data.fst, 9), False, 9.0 ,  1.0, 4.7), t_steps, Exp(0.0), gaussian_proposal_dist, burnin).fst, "./whatever.csv")}
      print-elapsed{write(tmcmc(linear_gaussian_climate_data(exn-get(data.snd, 9), exn-get(data.fst, 9), False, 9.0 ,  1.0, 4.7), t_steps, Exp(0.0), gaussian_proposal_dist, burnin).fst, "./whatever.csv")}
      print-elapsed{write(tmcmc(linear_gaussian_climate_data(exn-get(data.snd, 10), exn-get(data.fst, 10), False, 7.0, 2.0, 4.7), t_steps, Exp(0.0), gaussian_proposal_dist, burnin).fst, "./whatever.csv")}
      print-elapsed{write(tmcmc(linear_gaussian_climate_data(exn-get(data.snd, 10), exn-get(data.fst, 10), False, 7.0, 2.0, 4.7), t_steps, Exp(0.0), gaussian_proposal_dist, burnin).fst, "./whatever.csv")}
      print-elapsed{write(tmcmc(linear_gaussian_climate_data(exn-get(data.snd, 11), exn-get(data.fst, 11), False, 6.0, -1.0,4.7), t_steps, Exp(0.0), gaussian_proposal_dist, burnin).fst, "./whatever.csv")}
      print-elapsed{write(tmcmc(linear_gaussian_climate_data(exn-get(data.snd, 11), exn-get(data.fst, 11), False, 6.0, -1.0,4.7), t_steps, Exp(0.0), gaussian_proposal_dist, burnin).fst, "./whatever.csv")}
      println("End TMCMC:")
    }
  }



  print-elapsed {
    println("Begin SMC:")
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 0), exn-get(data.fst, 0), False, 10.0, -3.0, 4.7)), "./whatever.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 0), exn-get(data.fst, 0), False, 10.0, -3.0, 4.7)), "./whatever.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 1), exn-get(data.fst, 1), False, 8.0 , -1.0, 4.7)), "./whatever.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 1), exn-get(data.fst, 1), False, 8.0 , -1.0, 4.7)), "./whatever.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 2), exn-get(data.fst, 2), False, 7.0 ,  1.0, 4.7)), "./whatever.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 2), exn-get(data.fst, 2), False, 7.0 ,  1.0, 4.7)), "./whatever.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 3), exn-get(data.fst, 3), False, 6.0 ,  5.0, 4.7)), "./whatever.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 3), exn-get(data.fst, 3), False, 6.0 ,  5.0, 4.7)), "./whatever.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 4), exn-get(data.fst, 4), False, 8.0 ,  9.0, 4.7)), "./whatever.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 4), exn-get(data.fst, 4), False, 8.0 ,  9.0, 4.7)), "./whatever.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 5), exn-get(data.fst, 5), False, 8.0 , 10.0, 4.7)), "./whatever.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 5), exn-get(data.fst, 5), False, 8.0 , 10.0, 4.7)), "./whatever.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 6), exn-get(data.fst, 6), False, 9.0 , 11.0, 4.7)), "./whatever.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 6), exn-get(data.fst, 6), False, 9.0 , 11.0, 4.7)), "./whatever.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 7), exn-get(data.fst, 7), False, 6.0 , 11.0, 4.7)), "./whatever.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 7), exn-get(data.fst, 7), False, 6.0 , 11.0, 4.7)), "./whatever.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 8), exn-get(data.fst, 8), False, 5.0 , 10.0, 4.7)), "./whatever.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 8), exn-get(data.fst, 8), False, 5.0 , 10.0, 4.7)), "./whatever.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 9), exn-get(data.fst, 9), False, 9.0 ,  1.0, 4.7)), "./whatever.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 9), exn-get(data.fst, 9), False, 9.0 ,  1.0, 4.7)), "./whatever.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 10), exn-get(data.fst, 10), False, 7.0, 2.0, 4.7)), "./whatever.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 10), exn-get(data.fst, 10), False, 7.0, 2.0, 4.7)), "./whatever.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 11), exn-get(data.fst, 11), False, 6.0, -1.0,4.7)), "./whatever.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 11), exn-get(data.fst, 11), False, 6.0, -1.0,4.7)), "./whatever.csv")}
    println("Mid way!")
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 0), exn-get(data.fst, 0), False , 10.0, -3.0, 4.7)), "./whatever.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 0), exn-get(data.fst, 0), False , 10.0, -3.0, 4.7)), "./whatever.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 1), exn-get(data.fst, 1), False , 8.0 , -1.0, 4.7)), "./whatever.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 1), exn-get(data.fst, 1), False , 8.0 , -1.0, 4.7)), "./whatever.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 2), exn-get(data.fst, 2), False , 7.0 ,  1.0, 4.7)), "./whatever.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 2), exn-get(data.fst, 2), False , 7.0 ,  1.0, 4.7)), "./whatever.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 3), exn-get(data.fst, 3), False , 6.0 ,  5.0, 4.7)), "./whatever.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 3), exn-get(data.fst, 3), False , 6.0 ,  5.0, 4.7)), "./whatever.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 4), exn-get(data.fst, 4), False , 8.0 ,  9.0, 4.7)), "./whatever.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 4), exn-get(data.fst, 4), False , 8.0 ,  9.0, 4.7)), "./whatever.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 5), exn-get(data.fst, 5), False , 8.0 , 10.0, 4.7)), "./whatever.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 5), exn-get(data.fst, 5), False , 8.0 , 10.0, 4.7)), "./whatever.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 6), exn-get(data.fst, 6), False , 9.0 , 11.0, 4.7)), "./whatever.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 6), exn-get(data.fst, 6), False , 9.0 , 11.0, 4.7)), "./whatever.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 7), exn-get(data.fst, 7), False , 6.0 , 11.0, 4.7)), "./whatever.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 7), exn-get(data.fst, 7), False , 6.0 , 11.0, 4.7)), "./whatever.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 8), exn-get(data.fst, 8), False , 5.0 , 10.0, 4.7)), "./whatever.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 8), exn-get(data.fst, 8), False , 5.0 , 10.0, 4.7)), "./whatever.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 9), exn-get(data.fst, 9), False , 9.0 ,  1.0, 4.7)), "./whatever.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 9), exn-get(data.fst, 9), False , 9.0 ,  1.0, 4.7)), "./whatever.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 10), exn-get(data.fst, 10), False , 7.0, 2.0, 4.7)), "./whatever.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 10), exn-get(data.fst, 10), False , 7.0, 2.0, 4.7)), "./whatever.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 11), exn-get(data.fst, 11), False , 6.0, -1.0,4.7)), "./whatever.csv")}
    print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 11), exn-get(data.fst, 11), False , 6.0, -1.0,4.7)), "./whatever.csv")}
    println("End of SMC.")

  }
}
