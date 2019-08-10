public module sequential

import effects-and-types
import handlers
import sampling
import exponents
import output-and-plot

fun smc(particle_num : int, step_num : int, step_size : int, model : () -> <sample,score|_e> _a, normalize : bool) {
  random_sampler {
    val composition_1 = fun() {
      advance {
        yield_on_score {
          model()
        }
      }
    }

    val pop = normalise(populate(particle_num, composition_1))
    smc_loop(0, pop, step_num, step_size, normalize)
  }
}

fun smc_loop(i : int, populated_hist : histogram<(int) -> <exn,yield,score,sample|e> a>, step_num : int, step_size : int, normalize : bool) : <exn, sample|e> histogram<a> {
    if (i < step_num) then {
      val resampled_histogram = resample(populated_hist)
      fun advance_func(wm) {
        match(wm) {
          (w, m) -> {
            weighted(w) {
              advance {
                m(step_size)
              }
            }
          }
        }
      }
      if(normalize) {
        smc_loop(i + 1, normalise(map(resampled_histogram, advance_func)), step_num, step_size, normalize)
      } else {
        smc_loop(i + 1, (map(resampled_histogram, advance_func)), step_num, step_size, normalize)
      }
    } else {

      val finalize_func = fun(wm) {
        match(wm) {
          (w,m) -> {
            weighted(w) {
              finalize{
                m(0)
              }
            }
          }
        }
      }
      if(normalize) {
        normalise(map(populated_hist, finalize_func))
      } else {
        map(populated_hist, finalize_func)
      }
    }
}
