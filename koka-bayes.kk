public module test/ojg/koka-bayes

import std/num/double
import std/num/ddouble
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
  val x1 = 2.0
  val x2 = 2.0
  val x3 = 2.1
  val x4 = 2.2
  val x5 = 2.0
  val x6 = 2.0
  val g = fun() {
    val seed = normal(2.0, 1.0)
    score(normal_pdf(seed, 0.3, x1))
    val seed2 = normal(seed, 1.0)
    score(normal_pdf(seed2, 0.3, x2))
    val seed3 = normal(seed2, 0.5)
    score(normal_pdf(seed3, 0.3, x3))
    val seed4 = normal(seed3, 0.4)
    score(normal_pdf(seed4, 0.3, x4))
    val seed5 = normal(seed4, 0.2)
    score(normal_pdf(seed5, 0.3, x5))
    val seed6 = normal(seed5, 0.1)
    score(normal_pdf(seed6, 0.3, x6))
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

    /* loop(0, pop, step_num, step_size, default) */
    5
  }
}

fun loop(i : int, pop_hist : histogram<(int) -> <yield,score,div,sample|e> a>, step_num : int, step_size : int, default : (exp, int -> <yield,score,div,sample|e> a)) : <div,sample|e> histogram<a> {
  var histogram := pop_hist
  for(i, step_num) fun(i) {
      if (i < step_num) then {
        histogram := resample(histogram, default)
        fun smc_func_2(wm) {
          match(wm) {
            (w,m) -> {
              weighted(w) {
                advance {
                  m(step_size)
                }
              }
            }
          }
        }

        histogram := map(histogram, smc_func_2)
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

        return map(histogram, pop_func)
      }
   }
}

fun main() {
  /* val test_histogram : histogram<double> = [(Exp(0.0), 1.0), (Exp(2.0), 4.0)] */
  /* val default = (Exp(0.0), fun(i : int){(fun(k:double){1.0})}) */
  val default = (Exp(0.0), fun(i : int){(0.0)})
  val hist = smc(90, 6, 1, sequential_gaussian(), default)
  /* write(hist) */
  show(hist)
}
