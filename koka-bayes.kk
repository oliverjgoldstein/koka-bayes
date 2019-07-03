public module test/ojg/koka-bayes

import std/num/double
import std/num/ddouble
import test/ojg/types
import test/ojg/exp
import test/ojg/bayes-handlers
import test/ojg/model
import test/ojg/plot

/*

This is going to introduce score effects into the regression model.

It kind of reassigns the thunk.

It introduces score effects that give some measure of similarity.

 */

fun fit_linear_gaussian(x1s : data_1d, x2s : data_1d) : model<(double, double)> {
  val g = fun() {
    val h1 = normal(0.0, 1.0)
    val v1 = h1 + 2.0 * normal(0.0, 1.0)
    map(x1s, fun(x) {score(normal_pdf(v1, 1.0, x))})

    val h2 = 4.0 * h1 + normal(0.0, 1.0)
    val v2 = h2 + 3.0 * normal(0.0, 1.0)
    map(x2s, fun(x) {score(normal_pdf(v2, 1.0, x))})

    (h1, h2)
  }
  g
}

fun sequential_gaussian() : model<double> {
  val x1 = 4.0
  val g = fun() {
    val seed = normal(2.0, 1.0)
    score(normal_pdf(seed, 0.3, x1))
    val seed2 = normal(seed, 1.0)
    score(normal_pdf(seed2, 0.3, x1))
    val seed3 = normal(seed2, 0.5)
    score(normal_pdf(seed3, 0.3, x1))
    val seed4 = normal(seed3, 0.4)
    score(normal_pdf(seed4, 0.3, x1))
    val seed5 = normal(seed4, 0.2)
    score(normal_pdf(seed5, 0.2, x1))
    val seed6 = normal(seed5, 0.1)
    score(normal_pdf(seed6, 0.1, x1))
    seed6
  }
  g
}

fun populate(k : int, model : () -> <score|e> b) : e histogram<b> {
  list(1, k) fun(i) {
    weighted(Exp(0.0)) {
      score(div_exp(Exp(0.0), Exp(log(k.double))))
      model()
    }
  }
}

fun normalise(histogram : histogram<a>) : histogram<a> {
  val total = sum_weights(histogram)
  map(histogram, fun(wt) {(div_exp(fst(wt), total), snd(wt))})
}

fun sum_histogram(hist : histogram<a>) : double {
  fun foldfunc(init, ws) {
    match(ws) {
      (Exp(w), _) -> {dbl-e^w + init}
    }
  }

  foldl(hist, 0.0, foldfunc)
}

fun importance_sampling(model : model<a>) : ndet histogram<a> {
  val particle_count = 1000
  random_sampler{normalise(populate(particle_count, model))}
}

fun sum_weights(histogram : histogram<a>) : exp {
  fun foldlfunc(acc, wx) {
    match(wx) {
      (w,_) -> plus_exp(acc, w)
    }
  }
  foldl(histogram, Exp(log(0.0)), foldlfunc)
}

fun weighted_choice(histogram : histogram<a>, default : (exp, a)) : sample a {
  val total_w = sum_weights(histogram)
  val total_fuel = (exp_to_double(total_w)) * sample()
  fun choose(fuel : double, ws) {
    match(ws) {
      Nil -> match(default) {
        (Exp(_), k) -> k
      }
      Cons((w,x), wxs) -> {
        val fuel_new = fuel - exp_to_double(w)
        if (fuel_new <= 0.0) then {
          x
        } else {
          choose(fuel_new, wxs)
        }
      }
    }
  }
  choose(total_fuel, histogram)
}

fun resample(histogram : histogram<a>, default : (exp, a)) : <div, sample> histogram<a> {
  val n = histogram.length
  val total_w = sum_weights(histogram)
  fun resample_model() {
    score(total_w)
    weighted_choice(histogram, default) // Returns a's with the highest weight.
  }

  populate(n, resample_model)
}

fun smc(particle_num : int, step_num : int, step_size : int, model, default) {
  random_sampler {
    val smc_func = fun() {
      advance {
        yield_on_score {
          model()
        }
      }
    }

    val pop = normalise(populate(particle_num, smc_func))
    smc_loop(0, pop, step_num, step_size, default)
  }
}

fun smc_loop(i : int, pop_hist : histogram<(int) -> <yield,score,div,sample|e> a>, step_num : int, step_size : int, default : (exp, int -> <yield,score,div,sample|e> a)) : <div,sample|e> histogram<a> {
    if (i < step_num) then {
      val resampled_histogram = resample(pop_hist, default)
      fun smc_func_2(wm) {
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

      val second_term = map(resampled_histogram, smc_func_2)
      smc_loop(i + 1, second_term, step_num, step_size, default)
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

fun rmsmc(particle_num : int, step_num : int, step_size : int, model, default) {
  random_sampler {
    val smc_func = fun() {
      advance {
        yield_on_score {
          trace {
            model()
          }
        }
      }
    }

    val pop = normalise(populate(particle_num, smc_func))
    /* rsmmc_loop(0, pop, step_num, step_size, default) */
    pop
  }
}

/* fun rsmmc_loop(i : int, pop_hist : histogram<(int) -> <yield,score,div,sample|e> a>, step_num : int, step_size : int, default : (exp, int -> <yield,score,div,sample|e> a)) : <div,sample|e> histogram<a> {
    if (i < step_num) then {
      val resampled_histogram = resample(pop_hist, default)
      fun smc_func_2(wm) {
        match(wm) {
          (w, m) -> {
            weighted(w) {
              advance {
                  trace_a(mh_step(Trace(trace{m(step_size)}))
              }
            }
          }
        }
      }

      val second_term = map(resampled_histogram, smc_func_2)
      rsmmc_loop(i + 1, second_term, step_num, step_size, default)
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
} */

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

fun mh_step(trace : trace<double>) : <console, ndet, ndet> trace<double> {
  val modified_trace = random_sampler{perturb_trace(trace)}
  match(trace) {
    Trace(model, p1, old_trace, a) -> {
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

fun tmcmc(model : model<double>, steps : int) : <div, ndet, ndet, console> trace<double> {
  val model_results =
  weighted(Exp(0.0)) {
    random_sampler{
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

fun main() {
  /* val test_histogram : histogram<double> = [(Exp(0.0), 1.0), (Exp(2.0), 4.0)] */
  /* val default = (Exp(0.0), fun(i : int){(fun(k:double){1.0})}) */
  val default = (Exp(0.0), fun(i : int){(100.0)})
  val hist = smc(50, 6, 1, sequential_gaussian(), default)
  write(hist)
  /* println(show(hist)) */
  show(trace_a(tmcmc(sequential_gaussian(), 1000)))
}
