public module sampling-rmsmc

import std/num/double

import effects-and-types
import handlers
import exponents
import output-and-plot
import std/num/random

fun populate(k : int, model : () -> <score,sample,sample|e> b) : <sample|e> histogram_rmsmc<b> {
  list(1, k) fn(i) {
    recorder(Nil) {
      weighted(Exp(0.0)) {
        score(div_exp(Exp(0.0), Exp(log(k.double)))) // This acts like a uniform distribution over all particles.
        model()
      }
    }
  }
}
//
// fun normalise(histogram : histogram<a>) : histogram<a> {
//   val total = sum_weights(histogram)
//   map(histogram, fn(wt) {(div_exp(fst(wt), total), snd(wt))})
// }
//
// fun sum_histogram(hist : histogram<a>) : double {
//   fun foldfunc(init, ws) {
//     match(ws) {
//       (Exp(w), _) -> {dbl-e^w + init}
//     }
//   }
//
//   foldl(hist, 0.0, foldfunc)
// }
//
// fun importance_sampling(model : model<a,<random|e>>) : <random|e> histogram<a> {
//   val particle_count = 2000
//   random_sampler{normalise(populate(particle_count, model))}
// }
//
// fun sum_weights(histogram : histogram_rmsmc<a>) : exp {
//   fun foldlfunc(acc, wx) {
//     match(wx) {
//       (_,w,_) -> plus_exp(acc, w)
//     }
//   }
//   foldl(histogram, Exp(log(0.0)), foldlfunc)
// }
//
// // This chooses a histogram with the probabilirt of
// fun weighted_choice(histogram : histogram_rmsmc<a>) : <exn, sample> (trace_values, a) {
//   val total_w = sum_weights(histogram)
//   val total_fuel = (exp_to_double(total_w)) * sample()
//   fun choose(fuel : double, ws : list<_a>) {
//     match(ws) {
//       Nil -> throw("Histogram is empty! Cannot select any element when resampling!")
//       Cons((tr,w,x), wxs) -> {
//         val fuel_new = fuel - exp_to_double(w)
//         if (fuel_new <= 0.0) then {
//           (tr,x)
//         } else {
//           choose(fuel_new, wxs)
//         }
//       }
//     }
//   }
//   choose(total_fuel, histogram)
// }
//
// fun resample(histogram : histogram_rmsmc<a>) : <exn, sample> histogram_rmsmc<a> {
//   val n = histogram.length
//   val total_w = sum_weights(histogram)
//   fun resample_model() {
//     score(total_w)
//     weighted_choice(histogram)
//   }
//
//   populate(n, resample_model)
// }
