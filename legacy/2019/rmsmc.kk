public module rmsmc

import effects-and-types
import handlers
import exponents
import output-and-plot
import sampling-rmsmc
import tmcmc

fun rmsmc(particle_num : int, smc_step_num : int, mh_step_num : int, step_size : int, model : () -> <sample,score|_e> _a, normalize : bool) {
  random_sampler {
    val composition_1 = fn() {
      advance {
        yield_on_score {
          model()
        }
      }
    }

    val pop = populate(particle_num, composition_1) //normalise
    rmsmc_loop(pop, 5, 0, smc_step_num, mh_step_num, step_size, normalize)
    x(composition_1)
  }
}

fun x(comp) {
  comp()
}


fun rmsmc_loop(populated_hist : histogram_rmsmc<(int) -> <exn,yield,score,sample,sample|e> a>,
              composition_1 : int,
              i : int, smc_step_num : int, mh_step_num : int, step_size : int, normalize : bool) : <exn, sample|e> histogram_rmsmc<a> {

    if (i < smc_step_num) then {
      // val resampled_histogram = resample(populated_hist)
      val resampled_histogram = populated_hist
      fun advance_func(wm) {
        match(wm) {
          (tr, w, m) -> {

            // I need to run the model from the start and run it with the length of the trace.

            val (tr_new, w_new, m_new) =
              recorder(tr) { // The trace completely determines a probabilistic program.
                weighted(w) {
                  advance {
                    m(step_size)
                  }
                }
              }

            // val trace = RTrace(composition_1, w_new, tr_new)
            // val new_trace = mh_step_rmsmc(trace)
            // (trace.l, trace.w, trace.m)
            (tr_new, w_new, m_new)
          }
        }
      }

      val irrelevant = map(resampled_histogram, advance_func)

      if(normalize) {
        rmsmc_loop(irrelevant, composition_1, i + 1, smc_step_num, mh_step_num, step_size, normalize)
      } else {
        rmsmc_loop(irrelevant, composition_1, i + 1, smc_step_num, mh_step_num, step_size, normalize)
      }
    } else {

      val finalize_func = fn(wm) {
        match(wm) {
          (tr,w,m) -> {
            recorder(tr) {
              weighted(w) {
                finalize {
                  m(0)
                }
              }
            }
          }
        }
      }
      if(normalize) {
        map(populated_hist, finalize_func)
      } else {
        map(populated_hist, finalize_func)
      }
    }
}
