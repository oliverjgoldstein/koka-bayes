public module test/ojg/koka-bayes

import std/num/double
import test/ojg/exp
import test/ojg/bayes-handlers

alias model<a> = () -> <sample, score> a
alias doublefunc = double -> ndet double
alias regression = () -> ((x : double) -> ndet double)
alias histogram<a> = list<(exp, a)>
alias histofunc<a,b> = histogram<a> -> histogram<b>


fun populate(k : int, model : model<a>) : <sample> histogram<a>  {
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
  with random_sampler
  normalise(populate(particle_count, model))
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

/* fun smc(particle_num : int, step_num : int, step_size : int, model : model<a>) {
  with random_sampler
  fun smc_func() {
    advance{yield_on_score(model())}
  }

  //val pop = populate(particle_num, smc_func)

  /*/* val resample_pop = resample pop */
  fun loop(i, pop) {
      if (i < step_num) then {
        /* resample(pop) */
      } else {

      }
    } */
5
} */

fun pop_map( f : a -> b ) : histofunc<a,b> {
  (fun(lista) {
    pop_map_helper(f, lista)
  })
}

fun pop_map_helper(f : a -> b, t : histogram<a>) : (histogram<b>) {
    match(t) {
      Nil -> Nil
      Cons(x, xs) -> match(x) {
        (Exp(n), a) -> Cons((Exp(n), f(a)), pop_map_helper(f, xs))
      }
    }
}

fun plot( f : (double -> double) ) : string {
  val lft = 0.0
  val rgt = 4.0
  val steps = 100
  val stp = (rgt - lft) / steps.double
  list-join(steps) fun(i:int) {
    val x = lft + (stp * i.double)
    val y = f( x )
    "[" + x.show(6) + "," + y.show(6) + "]"
  }
}

fun example-plot() {
  plot( fun(x){ 2.0 * x } )
}

fun list-join(len : int, elem) {
  val xs = list(1,len,elem)
  "[" + xs.join(",") + "]"
}


/* fun gaussian-model() : model<double> {
  val x = fun() {
    with random_sampler
    return normal(5.0, 1.0)
  }
  x
} */

fun homogeneous_linear() : regression {
  val r = fun(x : double) {normal(0.0, 2.0) * x}
  val y = fun() {r}
  y
}

fun box-muller(u1 :double, u2 :double) {
  sqrt(-2.0 * log(u1)) * cos(dbl-twopi * u2)
}

fun standard-normal() : <sample> double {
  box-muller(sample(),sample())
}

fun normal(mean, sdv) {
  with random_sampler
  mean + standard-normal() * sdv
}
