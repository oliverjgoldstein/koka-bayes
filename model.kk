import test/ojg/types
import test/ojg/bayes-handlers
import std/num/double
import test/ojg/exp

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
