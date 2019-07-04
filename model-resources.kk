public module test/ojg/model-resources

import std/num/double

import test/ojg/effects-and-types
import test/ojg/handlers
import test/ojg/exponents

val linear : regression = fun() {
  val a = normal(0.0,2.0)
  val b = normal(0.0,2.0)
  (fun(x){ a * x + b })
}

fun gaussian_model() : model<double> {
  return fun() {
    normal(0.0, 10.0)
  }
}

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

fun sequential_gaussian(x1 : double) : model<double> {
  val g = fun() {
    val seed = normal(2.0, 1.0)
    score(normal_pdf(seed, 0.3, x1))
    val seed2 = normal(seed, 1.0)
    score(normal_pdf(seed2, 0.3, x1))
    val seed3 = normal(seed2, 0.5)
    score(normal_pdf(seed3, 0.3, x1))
    val seed4 = normal(seed3, 0.4)
    score(normal_pdf(seed4, 0.3, x1))
    val seed5 = normal(seed4, 0.2)
    score(normal_pdf(seed5, 0.2, x1))
    val seed6 = normal(seed5, 0.1)
    score(normal_pdf(seed6, 0.1, x1))
    seed6
  }
  g
}


val fitted = fit(homogeneous_linear, dataset)
val gaussian = fit_1d_gaussian(gaussian_model(), gaussian_dataset)

fun fit(model : regression, dataset : two_d_data) : regression {
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
        score(normal_pdf(f, 1.0, x))
      }

      map(dataset, map_fun)
      f
  }
  g
}


/* This function is going to return a linear function i.e. 0.1 * x for any x you give it. */
val homogeneous_linear : regression = fun() {
  val a = normal(0.0, 2.0)
  val r = fun(x : double) {a * x}
  r
}

val gaussian_dataset : data_1d = [0.0, 0.1, 0.1, 0.0, 0.2, 0.1, 0.0, 0.2]
val gaussian_five : data_1d = [5.0,5.0,5.0,5.0,5.1,5.0,5.0,5.0,5.0,5.1,5.0,5.0,5.0,5.0,5.1]
val dataset : two_d_data = [(1.0,2.0),(2.0,3.0),(1.0,2.0),(2.0,3.0),(1.0,2.0),(2.0,3.0)]

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
