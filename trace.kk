public module trace

import std/num/double

import effects-and-types
import exponents
import handlers
import sampling


type trace<a,e> {
  Trace(m : model<a,e>, p : exp, l : trace_values, a : a)
}


fun trace_v(tr : trace<a,_>) : list<double> {
  match(tr) {
    Trace(_, _, d, _) -> d
  }
}

fun trace_m(tr : trace<a,e>) : model<a,e> {
  match(tr) {
    Trace(m, _, _, _) -> m
  }
}

fun trace_p(tr : trace<a,_>) : exp {
  match(tr) {
    Trace(_, p, _, _) -> p
  }
}

fun trace_a(tr : trace<a,_>) : a {
  match(tr) {
    Trace(_, _, _, a) -> a
  }
}


fun perturb_trace(trace : trace<a,_e>) : <sample|e> trace_values {
  val trace_values  = trace_v(trace)
  val perturb_index = random_range(trace_values.length)
  val div_trace     = split(trace_values, perturb_index)
  val new_trace     = match(div_trace) {
    (l1, Cons(_, l2)) -> l1 + [sample()] + l2
    (l1, _) -> l1
  }
  new_trace
}

fun with_randomness(model : model<_a,<sample|e>>, trace_values : trace_values) : <sample|e> (trace_values, (exp, _a)) {
  val likelihood_a_trace = 
  /* random_sampler { */
    replay(trace_values) {
      weighted(Exp(0.0)) {
        model()
      }
    }
  /* } */
  likelihood_a_trace
}

fun mh_step(trace : trace<a,<sample|e>>) : <sample|e> trace<a,<sample|e>> {
  val modified_trace = perturb_trace(trace)
  match(trace) {
    Trace(model, p1, old_trace, _) -> {
      val p2b = with_randomness(model, modified_trace)
      match(p2b) {
        (new_trace, (p2, b)) -> {
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

fun bernoulli(p : double) : sample bool {
  val g = sample()
  if (g < p) {
    True
  } else{
    False
  }
}

fun random_range(upper_bound : int) {
  return int(sample() / (1.0 / double(upper_bound))) % upper_bound
}

fun tmcmc(model : model<a,<sample,div|e>>, steps : int, init_weight : exp) : <sample, div|e> trace<a,<sample,div|e>> {
  val model_results =
  weighted(init_weight) {
    /* random_sampler { */
      trace {
        model()
      }
    /* } */
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

  model_stepper_recursive(steps, Trace(model, p, d, a))
}
  
fun model_stepper_recursive(steps : int, trace : trace<a,<sample,div|e>>) : <sample,div|e> trace<a,<sample,div|e>> {
  if(steps < 0) {
    trace
  } else {
    val new_trace = mh_step(trace)
    model_stepper_recursive(steps - 1, new_trace)
  }
}


fun rmsmc(particle_num : int, step_num : int, step_size : int, model : model<_a,<score,yield,div,exn|_e>>) {

    val rmsmc_func = fun() {
      advance {
        yield_on_score {
          model()
        }
      }
    }
    random_sampler {
    val pop = normalise(populate(particle_num, rmsmc_func))
    rmsmc_loop(0, pop, step_num, step_size)
  }
}

fun rmsmc_loop(i : int, pop_hist : histogram<(int) -> <exn,yield,score,sample|e> a>, step_num : int, step_size : int) : <exn, sample|e> histogram<a> {
    if (i < step_num) then {
      val resampled_histogram = resample(pop_hist)
      fun rmsmc_func_2(wm) {
        match(wm) {
          (w, m) -> {
            weighted(w) {
              advance {
                trace_m(tmcmc( (fun() {m(step_size)}), 1, w ))()
                /* m(step_size) */
              }
            }
          }
        }
      }

      val second_term = map(resampled_histogram, rmsmc_func_2)
      rmsmc_loop(i + 1, second_term, step_num, step_size)
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


