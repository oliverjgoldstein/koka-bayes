import test/ojg/bayes-handlers
import std/num/double
import test/ojg/exp

val linear : regression = fun() {
  val a = normal(0.0,2.0)
  val b = normal(0.0,2.0)
  (fun(x){ a * x + b })
}

fun gaussian-model() : model<double> {
  return fun() {
    normal(5.0, 1.0)
  }
}

val homogeneous_linear : regression = fun() {
  val a = normal(0.0, 2.0)
  val r = fun(x : double) {a * x}
  r
}

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
  return div_exp(Exp(0.0 - (square(x - mean)) / (2.0 * (square(sdv)))), e(sdv * sqrt(2.0)*pi))
}
