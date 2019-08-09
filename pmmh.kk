public module pmmh

import std/num/double

import effects-and-types
import exponents
import handlers
import sampling
import output-and-plot
import model-resources
import trace
import sequential

fun new_model(param_prior : () -> <pure,sample,score,ndet|e> b, smc_model : b -> model<a,<yield,div,exn,sample,score|e>>, particle_num : int, step_num : int) : (() -> <pure,sample,score,ndet|e> b) {
  val g = fun() {
    val params = param_prior()
    val smc_hist = smc(particle_num, step_num, 1, smc_model(params))
    score(sum_weights(smc_hist))
    params
  }
  g
}

fun pmmh(smc_model, param_prior) {
  val pmmh_model = new_model(param_prior, smc_model, 10, 10)
  tmcmc(pmmh_model, 10, Exp(0.0), 0)
}
