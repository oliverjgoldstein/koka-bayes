public module test/koka-bayes/model-resources

import std/num/ddouble

import test/koka-bayes/effects-and-types
import test/koka-bayes/handlers
import test/koka-bayes/exponents

val linear : regression = fun() {
  val a = normal(ddouble(0.0),ddouble(2.0))
  val b = normal(ddouble(0.0),ddouble(2.0))
  (fun(x){ a * x + b })
}

fun gaussian_model() : model<ddouble> {
  return fun() {
    normal(ddouble(0.0), ddouble(10.0))
  }
}

fun fit_linear_gaussian(x1s : data_1d, x2s : data_1d) : model<(ddouble, ddouble)> {
  val g = fun() {
    val h1 = normal(ddouble(0.0), ddouble(1.0))
    val v1 = h1 + ddouble(2.0) * normal(ddouble(0.0), ddouble(1.0))
    map(x1s, fun(x) {score(normal_pdf(v1, ddouble(1.0), x))})

    val h2 = ddouble(4.0) * h1 + normal(ddouble(0.0), ddouble(1.0))
    val v2 = h2 + ddouble(3.0) * normal(ddouble(0.0), ddouble(1.0))
    map(x2s, fun(x) {score(normal_pdf(v2, ddouble(1.0), x))})

    (h1, h2)
  }
  g
}

fun sequential_gaussian(data_point : ddouble) : model<ddouble> {
  val g = fun() {
    val seed = normal(ddouble(2.0), ddouble(1.0))
    score(normal_pdf(seed, ddouble(0.3), data_point))
    val seed2 = normal(seed, ddouble(1.0))
    score(normal_pdf(seed2, ddouble(0.3), data_point))
    val seed3 = normal(seed2, ddouble(0.5))
    score(normal_pdf(seed3, ddouble(0.3), data_point))
    val seed4 = normal(seed3, ddouble(0.4))
    score(normal_pdf(seed4, ddouble(0.3), data_point))
    val seed5 = normal(seed4, ddouble(0.2))
    score(normal_pdf(seed5, ddouble(0.2), data_point))
    val seed6 = normal(seed5, ddouble(0.1))
    score(normal_pdf(seed6, ddouble(0.1), data_point))
    seed6
  }
  g
}

val fitted = fit(homogeneous_linear, dataset)
val gaussian = fit_1d_gaussian(gaussian_model(), gaussian_dataset)

fun fit(model : regression, dataset : two_d_data) : regression {
    val g = fun() {
      val f : ddouble -> ddouble = model()
      val map_fun = fun(xy) {
        match(xy) {
          (x,y) -> score(normal_pdf(f(x), ddouble(0.25), y))
        }
      }

      map(dataset, map_fun)
      f
    }
    g
}

fun fit_1d_gaussian(model : model<ddouble>, dataset : data_1d) : model<ddouble> {
  val g = fun() {
      val f : ddouble = model()
      val map_fun = fun(x) {
        score(normal_pdf(f, ddouble(1.0), x))
      }

      map(dataset, map_fun)
      f
  }
  g
}


/* This function is going to return a linear function i.e. ddouble(0.1) * x for any x you give it. */
val homogeneous_linear : regression = fun() {
  val a = normal(ddouble(0.0), ddouble(2.0))
  val r = fun(x : ddouble) {a * x}
  r
}


val gaussian_dataset : data_1d = [ddouble(5.0),ddouble(5.0),ddouble(5.0),ddouble(5.0),ddouble(5.1),ddouble(5.0),ddouble(5.0),ddouble(5.0),ddouble(5.0),ddouble(5.1),ddouble(5.0),ddouble(5.0),ddouble(5.0),ddouble(5.0),ddouble(5.1)]
val dataset : two_d_data = [(ddouble(1.0),ddouble(2.0)),(ddouble(2.0),ddouble(3.0)),(ddouble(1.0),ddouble(2.0)),(ddouble(2.0),ddouble(3.0)),(ddouble(1.0),ddouble(2.0)),(ddouble(2.0),ddouble(3.0))]

fun box-muller(u1 :ddouble, u2 :ddouble) {
  sqrt(ddouble(-2.0) * log(u1)) * cos(dd-twopi * u2)
}

fun standard-normal() : <sample> ddouble {
  box-muller(sample(),sample())
}

fun normal(mean, sdv) {
  mean + standard-normal() * sdv
}

fun square(x : ddouble) : ddouble {
  return x * x
}

fun normal_pdf(mean, sdv, x) {
  return div_exp(Exp(ddouble(0.0) - ((square(x - mean)) / (ddouble(2.0) * (square(sdv))))), e(log(sdv * sqrt(ddouble(2.0)*dd-pi))))
}
