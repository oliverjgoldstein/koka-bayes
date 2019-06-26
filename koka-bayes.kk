/* public module test/ojg/koka-bayes

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

/* val fitted_hmm = fit_linear_gaussian() */


/*
 Creates histogram with uniformly distributed exp weights.
 The model can induce another score to modify the weights.
 Randomly chosen elements from the model.
*/

fun populate(k : int, model : () -> <score|e> b) : e histogram<b> {
  list(1, k) fun(i) {
    weighted(Exp(0.0)) {
      score(div_exp(Exp(0.0), Exp(log(k.double))))
      model()
    }
  }
}

/*

normalise sums the weights.
it then maps over the histogram and dividies the exps by the total weights.

*/

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

/*
This initialises a set of particles,
random_sampler wraps around it
normalise is going to make the set of weights one.
the populate will return a histogram from the model.
*/

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

/*
Randomly choses a value from 0 through total_w.
It then reduces this value by e^histogram_element_weight successively.
When below 0 it chooses that value.
*/
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


/*
Returns a histogram which is populated with elements from resample_model.
Resample_model uses the original histogram.
The resampled model actually does induce another score in the populate.
The score is for total_w.
*/
fun resample(histogram : histogram<a>, default : (exp, a)) : <div, sample> histogram<a> {
  val n = histogram.length
  val total_w = sum_weights(histogram)
  fun resample_model() {
    score(total_w)
    weighted_choice(histogram, default) // Returns a's with the highest weight.
  }

  populate(n, resample_model)
}

fun smc(particle_num : int, step_num : int, step_size : int, model, default) :  <div,ndet|_e> histogram<_b> {
  with random_sampler
  val smc_func = fun() {
    with advance
    with yield_on_score
    model()
  }

  val pop = normalise(populate(particle_num, smc_func))

  fun loop(i, pop_hist) {
      if (i < step_num) then {
        val resampled_histogram = resample(pop_hist, default)
        fun smc_func_2(wm) {
          match(wm) {
            (w,m) -> {
              weighted(w) {
                with advance
                m(step_size)
              }
            }
          }
        }
        val second_term = map(resampled_histogram, smc_func_2)
        val third_term = loop((i + 1), second_term)
        third_term

      } else {
        val pop_func = fun(wm) {
          match(wm) {
            (w,m) -> {
              weighted(w) {
                finalize{m(0)}
              }
            }
          }
        }

        val x = map(pop_hist, pop_func)
        x
      }
  }
  loop(0, pop)
}

fun main() {
  val test_histogram : histogram<double> = [(Exp(0.0), 1.0), (Exp(2.0), 4.0)]
  write(test_histogram)
  val default = (Exp(0.0), fun(i : int){(1.0, 1.0)})
  val hist = smc(100, 50, 50, fit_linear_gaussian(gaussian_one, gaussian_two), default)
  show(hist)
} */
