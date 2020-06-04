public module main

import std/num/double
import std/num/ddouble
import std/time/timer
import output-and-plot
import exponents
import effects-and-types
import sequential
import trace
import pmmh
import handlers
import model-resources
import climate-change
import data/preprocessing
import exn-get
import sampling

// The following is a short demonstration of how to use Importance Sampling,
// Sequential Monte Carlo, as well as Trace Markov Chain Monte Carlo.

fun main() {
  println("Running Importance Sampling...")
  print-elapsed{write(importance_sampling(sequential_gaussian(3.0)), "./gaussian/importance_sampling.csv")}
  println("Completed Importance Sampling!")

  // Note that if you change any filename - change output/plot_examples.py too if you want to show the histograms.
  println("Running Sequential Monte Carlo...")
  print-elapsed {
    write(smc(2000, 10, 1, sequential_gaussian(3.0), True), "./gaussian/smc_posterior.csv")
  }
  println("Completed Sequential Monte Carlo!")

  println("Running Trace MCMC...")
  print-elapsed {
    random_sampler {
      val trace_and_values = tmcmc(sequential_gaussian(3.0), 2000, Exp(0.0), 0).fst
      write(trace_and_values, "./gaussian/trace_posterior.csv")
    }
  }
  println("Completed Trace MCMC!")
}
