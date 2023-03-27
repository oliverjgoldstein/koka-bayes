public module sampling

import std/num/double

import effects-and-types
import handlers
import exponents
import output-and-plot
import std/num/random

fun populate(k : int, model : () -> <score|e> b) : e histogram<b> {
  list(1, k) fn(i) {
    weighted(Exp(0.0)) {
      score(div_exp(Exp(0.0), Exp(log(k.double)))) // This acts like a uniform distribution over all particles.
      model()
    }
  }
}

fun normalise(histogram : histogram<a>) : histogram<a> {
  val total = sum_weights(histogram)
  map(histogram, fn(wt) {(div_exp(fst(wt), total), snd(wt))})
}

fun sum_histogram(hist : histogram<a>) : double {
  foldl(hist, 0.0) fn(acc,(w,_)){ acc + w.exp_to_double }
}

fun importance_sampling(model : model<a,<random|e>>) : <random|e> histogram<a> {
  val particle_count = 2000
  random_sampler{normalise(populate(particle_count, model))}
}

fun sum_weights(histogram : histogram<a>) : exp {
  foldl(histogram, zero-exp ) fn(acc,(w,_)){ plus_exp(acc,w) }
}

// This chooses a histogram with the probabilirt of
fun weighted_choice(total_w : double, histogram : list<(double,a)>) : <exn, sample> a {
  //val total_w = sum_weights(histogram)
  val total_fuel = total_w * sample()
  fun choose(fuel : double, ws : list<_a>) {
    match(ws) {
      Nil -> throw("Histogram is empty! Cannot select any element when resampling!")
      Cons((w,x), wxs) -> {
        val fuel_new = fuel - w
        if (fuel_new <= 0.0) then x else choose(fuel_new, wxs)
      }
    }
  }
  choose(total_fuel, histogram)
}

fun resample(histogram : histogram<a>) : <exn, sample> histogram<a> {
  val n = histogram.length
  val total_w = sum_weights(histogram)
  val total_w_dbl   = total_w.exp_to_double
  val histogram_dbl = histogram.map( fn((w,x)){ (w.exp_to_double,x) }) 
  fun resample_model() {
    score(total_w)
    weighted_choice(total_w_dbl,histogram_dbl)
  }
  populate(n, resample_model)
}
