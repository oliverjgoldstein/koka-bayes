public module pmmh

import std/num/double

import effects-and-types
import exponents
import handlers
import sampling
import output-and-plot
import model-resources
import tmcmc
import smc

// PMMH is under development and does not currently work as expected.

fun new_model(param_model : model<b,<pure,ndet|_e>>, main_model : b -> model<a,_e1>, particle_num : int, step_num : int) : model<b, <pure,ndet|_e>> {
  fun g(){
    val params = param_model()
    val smc_hist = smc(particle_num, step_num, 1, main_model(params), False)
    score(sum_weights(smc_hist))
    params
  }
  g
}

fun pmmh(param_model, main_model) {
  val pmmh_model = new_model(param_model, main_model, 10, 10)
  tmcmc(pmmh_model, 10, Exp(0.0), 0)
}
