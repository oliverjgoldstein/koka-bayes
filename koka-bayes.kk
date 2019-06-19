public module test/ojg/koka-bayes

import std/num/double
import test/ojg/exp
import test/ojg/bayes-handlers
import test/ojg/model
import test/ojg/plot

alias model<a> = () -> <sample, score> a
alias regression = model<double -> double>
alias data = list<(double, double)>

alias histogram<a> = list<(exp, a)>
alias histofunc<a,b> = histogram<a> -> histogram<b>

fun fit(model : regression, dataset : data) : <score, sample> regression {
    val f = model
    val map_fun = fun(xy) {
      match(xy) {
        (x,y) -> score(normal_pdf(f()(x), 0.25, y))
      }
    }

    map(dataset, map_fun)
    f
}

/* val fitted = fit(homogeneous_linear, dataset) */

fun populate(k, model) {
  list(1, k) fun(i){
    weighted(Exp(0.0)) {
      score(div_exp(Exp(0.0), Exp(k.double)))
      model()
    }
  }
}

fun normalise(histogram : histogram<a>) : histogram<a> {
  val total = sum_weights(histogram)
  map(histogram, fun(wt_x) { (div_exp(fst(wt_x), total), snd(wt_x))})
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
  foldl(histogram, Exp(0.0), foldlfunc)
}

fun weighted_choice(histogram : histogram<a>, default : (exp, a)) : <sample> a {
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
  val default_added = Cons(default, histogram)
  choose(total_fuel, default_added)
}

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

fun smc(particle_num : int, step_num : int, step_size : int, model, default) {
  with random_sampler
  val smc_func = fun() {
    with advance
    with yield_on_score
    model()
  }

  val pop = populate(particle_num, smc_func)

  fun loop(i) {
      if (i < step_num) then {
        val first_term = resample(pop, default)
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
        /* val second_term = map(first_term, smc_func_2) */
        /* val third_term = loop((i + 1), second_term) */
        /* third_term */
        5
      } else {
        /* val first_term = resample(pop, default) */
        /* 4 */
        val pop_func = fun(m){finalize{m(0)}}
        val x = (pop_map(pop_func))(pop)
        6
      }
  }
  /* loop(0) */
  6
}

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

fun plot_reg() {
  for(1, 100) fun(i) {
    with random_sampler
    val f = homogeneous_linear()
    println(plot(f))
  }
}
