public module test/ojg/koka-bayes

import std/num/double
import test/ojg/exp
import test/ojg/bayes-handlers
import test/ojg/model
import test/ojg/plot

/*

This is going to introduce score effects into the regression model.

It kind of reassigns the thunk.

It introduces score effects that give some measure of similarity.

 */

fun fit(model : regression, dataset : data) : regression {
    val g = fun() {
      val f : double -> double = model()
      val map_fun = fun(xy) {
        match(xy) {
          (x,y) -> score(normal_pdf(f(x), 0.25, y))
        }
      }

      map(dataset, map_fun)
      f
    }
    g
}

fun fit_1d_gaussian(model : model<double>, dataset : data_1d) : model<double> {
  val g = fun() {
      val f : double = model()
      val map_fun = fun(x) {
        score(normal_pdf(f, 0.25, x))
      }

      map(dataset, map_fun)
      f
  }
  g
}

val fitted = fit(homogeneous_linear, dataset)
val gaussian = fit_1d_gaussian(gaussian_model(), gaussian_dataset)


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

fun normalise(histogram : histogram<double>) : histogram<double> {
  val total = sum_weights(histogram)

  val norm_fun = fun(wt_x) {
      match(wt_x) {
        (u, i) -> (div_exp(u, total), i)
      }
  }

  map(histogram, norm_fun)
}

fun sum_histogram(hist : histogram<double>) : double {
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

fun importance_sampling(model : model<double>) : ndet histogram<double> {
  val particle_count = 100
  random_sampler{normalise(populate(particle_count, model))}
}

fun gaussian_model() : model<double> {
  return fun() {
    normal(2.0, 0.9)
  }
}

fun show(hist : histogram<double>) {
  for(1, hist.length) fun(i) {
    val string = match(hist[i]) {
      Nothing -> " "
      Just(x) -> match(x) {
        (Exp(dbl), a) -> {show-fixed(dbl-e^dbl) + ", " + show-fixed(a)}
      }
    }
    println(string)
  }
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
    weighted_choice(histogram, default)
  }

  populate(n, resample_model)
}

/* fun smc_func_2(wm, step_size) {
  match(wm) {
    (w,m) -> {
      weighted(w) {
        with advance
        m(step_size)
      }
    }
  }
} */

/* fun smc(particle_num : int, step_num : int, step_size : int, model, default) {
  with random_sampler
  val smc_func = fun() {
    with advance
    with yield_on_score
    model()
  }

  val pop = populate(particle_num, smc_func)

  fun loop(i, pop_hist) {
      if (i < step_num) then {
        val first_term = resample(pop_hist, default)
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
        val second_term = map(first_term, smc_func_2)
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
} */

fun plot_population_regression(histogram : histogram<(double -> double)>, default : (exp, (double -> double))) : <ndet, console, sample> string {
  val negligible = length(filter(histogram,
    fun(element){
      match(element) {
          (Exp(j),_) -> (dbl-e^(j) < 0.00001)
      }
    }))
    println("Number of negligible samples: " + negligible.show)
    list-join(15) fun(i) {
      val f = weighted_choice(histogram, default)
      plot(f)
    }
}
