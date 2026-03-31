public module main

import std/num/random
import std/num/double
import std/num/ddouble
import std/time/timer
import effects-and-types
import output-and-plot
import smc
import model-resources
import handlers
import tmcmc


public fun print-elapsed2( action : () -> <ndet,console|e> a, msg : string = "elapsed" ) : <ndet,console|e> a {
  val x = action()
  //println( msg + " " + t.show(3) )
  x
}

fun main(){
  /*
  println("Running Trace MCMC...")
  pseudo-random(2020) {
    print-elapsed {
      random_sampler {
        val trace_and_values = tmcmc(sequential_gaussian(3.0), 1500, Exp(0.0), 0).fst
        write(trace_and_values, "./output-gaussian/trace_posterior.csv")
      }
    }
  }
  println("Completed Trace MCMC!")
  */
  println("Running Sequential Monte Carlo...")

  pseudo-random(2020) {
    print-elapsed {
      write(smc(3000, 10, 1, sequential_gaussian(3.0), True), "./output-gaussian/smc_posterior_filip.csv")
    }
  }

  println("Completed Sequential Monte Carlo!")
}
