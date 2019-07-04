public module test/ojg/trace

import std/num/double

import test/ojg/effects-and-types
import test/ojg/exponents
import test/ojg/handlers
import test/ojg/sampling

fun rmsmc(particle_num : int, step_num : int, step_size : int, model) {
    val smc_func = fun() {
      advance {
        yield_on_score {
          model()
        }
      }
    }

    val pop = random_samplier{normalise(populate(particle_num, smc_func))}

    rsmmc_loop(0, pop, step_num, step_size)
}

fun rsmmc_loop(i : int, pop_hist, step_num : int, step_size : int) : <exn, div,sample|e> histogram<a> {
  random_sampler {
    if (i < step_num) then {
      val resampled_histogram = resample(pop_hist)
      fun smc_func_2(wm) {
        match(wm) {
          (w, m) -> {
            weighted(w) {
              advance {
                trace_m(tmcmc( (fun() {m(step_size)}), 1 ))() // Remember to implement initial weight!
              }
            }
          }
        }
      }

      val second_term = map(resampled_histogram, smc_func_2)
      rsmmc_loop(i + 1, second_term, step_num, step_size)
    } else {

      val pop_func = fun(wm) {
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

      val x = map(pop_hist, pop_func)
      x
    }
  }
}

fun perturb_trace(trace : trace<_a>) : <ndet, sample|e> trace_values {
  val trace_values  = trace_v(trace)
  val perturb_index = random_range(trace_values.length)
  val div_trace     = split(trace_values, perturb_index)
  val new_trace     = match(div_trace) {
    (l1, Cons(_, l2)) -> l1 + [sample()] + l2
    (l1, _) -> l1
  }
  new_trace
}

fun with_randomness(model : model<_a>, trace_values : trace_values) : ndet (trace_values, (exp, _a)) {
  val likelihood_a_trace = random_sampler {
    replay(trace_values) {
      weighted(Exp(0.0)) {
        model()
      }
    }
  }
  likelihood_a_trace
}

fun mh_step(trace : trace<a>) : <ndet, ndet|e> trace<a> {
  val modified_trace = random_sampler{perturb_trace(trace)}
  match(trace) {
    Trace(model, p1, old_trace, _) -> {
      val p2b = with_randomness(model, modified_trace)
      match(p2b) {
        (new_trace ,(p2, b)) -> {
          val ratio = min(1.0, (exp_to_double(p2) * new_trace.length.double) / (exp_to_double(p1) * old_trace.length.double))
          val accept = bernoulli(ratio)
          if(accept) {
            Trace(model, p2, new_trace, b)
          } else {
            trace
          }
        }
      }
    }
  }
}

fun bernoulli(p : double) : ndet bool {
  val g = random()
  if (g < p) {
    True
  } else{
    False
  }
}

fun random_range(upper_bound : int) {
  return int(random() / (1.0 / double(upper_bound))) % upper_bound
}

fun tmcmc(model : model<a>, steps : int) : <div, ndet, ndet> trace<a> {
  val model_results =
  weighted(Exp(0.0)) {
    random_sampler {
      trace {
        model()
      }
    }
  }

  val p = match(model_results) {
    (Exp(a), _) -> Exp(a)
  }

  val d = match(model_results) {
    (_, (d, _)) -> d
  }

  val a = match(model_results) {
    (_, (_, a)) -> a
  }

  var main_trace := Trace(model, p, d, a)

  for(1, steps) fun(i) {
    main_trace := mh_step(main_trace)
  }

  main_trace
}
