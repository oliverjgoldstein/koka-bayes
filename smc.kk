public module smc

import effects-and-types
import handlers
import sampling
import exponents
import output-and-plot

fun smc(particle_num : int, steps : int, step-size : int, model : () -> <sample,score|_e> _a, normalize : bool) {
  random_sampler {
    fun composition() {
      advance{ yield_on_score{ model() } }
    }
    val pop = normalise(populate(particle_num, composition))
    smc-steps(steps, step-size, pop, if normalize then normalise else id)
  }
}

fun smc-steps(steps : int, step-size : int, pop-hist : histogram<(int) -> <exn,yield,score,sample|e> a>, norm : forall<b> histogram<b> -> histogram<b> ) : <exn, sample|e> histogram<a> {
  if (steps <= 0) {
    fun finalize-step((w,m)) {
      weighted(w){ finalize{ m(0) } }
    }
    pop-hist.map(finalize-step).norm
  }
  else {
    val pop-resampled = resample(pop-hist)
    fun advance-step((w,m)) {
      weighted(w){ advance { m(step-size) } }
    }
    smc-steps(steps - 1, step-size, pop-resampled.map(advance-step).norm, norm)
  }
}
