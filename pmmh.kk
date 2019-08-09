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

fun new_model(param_prior : () -> e b, smc_model : b -> model<a,e>, particle_num : int, step_num : int) {
  val params = param_prior()
  random_sampler {
    val smc_hist = smc(particle_num, step_num, 1, smc_model(params))
    score(sum_weights(smc_hist))
  }
  params
}

fun pmmh(smc_model : b -> model<a,e>, param_prior : trace<b,e>) {
  val pmmh_model = new_model(trace_m(param_prior), smc_model, 10, 10)
  tmcmc(pmmh_model, 10, trace_p(param_prior), 0)
}
