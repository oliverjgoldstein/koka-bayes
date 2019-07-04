public module test/ojg/sampling

import std/num/double

import test/ojg/effects-and-types
import test/ojg/handlers
import test/ojg/exponents

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

fun weighted_choice(histogram : histogram<a>) : <exn, sample> a {
  val total_w = sum_weights(histogram)
  val total_fuel = (exp_to_double(total_w)) * sample()
  fun choose(fuel : double, ws) {
    match(ws) {
      Nil -> error("Histogram is empty! Cannot select any element when resampling!")
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

fun resample(histogram : histogram<a>) : <exn, sample> histogram<a> {
  val n = histogram.length
  val total_w = sum_weights(histogram)
  fun resample_model() {
    score(total_w)
    weighted_choice(histogram)
  }

  populate(n, resample_model)
}
