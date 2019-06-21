import test/ojg/bayes-handlers
import std/num/double
import test/ojg/exp

val linear : regression = fun() {
  val a = normal(0.0,2.0)
  val b = normal(0.0,2.0)
  (fun(x){ a * x + b })
}


/* This function is going to return a linear function i.e. 0.1 * x for any x you give it. */
val homogeneous_linear : regression = fun() {
  val a = normal(0.0, 2.0)
  val r = fun(x : double) {a * x}
  r
}

/* fun gaussian_model() : model<double> {
  return fun() {
    normal(2.0, 0.3)
  }
} */

val gaussian_dataset : data_1d = [0.0, 0.1, 0.1, 0.0, 0.2, 0.1, 0.0, 0.2]

val dataset : data = [(1.0,2.0),(2.0,3.0)]

fun box-muller(u1 :double, u2 :double) {
  sqrt(-2.0 * log(u1)) * cos(dbl-twopi * u2)
}

fun standard-normal() : <sample> double {
  box-muller(sample(),sample())
}

fun normal(mean, sdv) {
  mean + standard-normal() * sdv
}

fun square(x : double) : double {
  return x * x
}

fun normal_pdf(mean, sdv, x) {
  return div_exp(Exp(0.0 - ((square(x - mean)) / (2.0 * (square(sdv))))), e(log(sdv * sqrt(2.0*pi))))
}
