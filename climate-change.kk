public module test/koka-bayes/climate-change

import std/num/ddouble

import test/koka-bayes/model-resources
import test/koka-bayes/effects-and-types
import test/koka-bayes/handlers
import test/koka-bayes/output-and-plot
import test/koka-bayes/exponents
import test/koka-bayes/exn-get

fun multivariate_gaussian(dimension : int, mean : ddouble, std_dev : ddouble) : sample list<ddouble> {
  list(1, dimension) fun(i) {
    normal(mean, std_dev)
  }
}

fun linear_gaussian_climate_data(ys : list<row_vector>, vs : list<row_vector>) : (() -> <exn,sample,score> ddouble) {
  val g = fun() {
    val prior_temperature           = ddouble(0.0)
    val prior_temp_std_dev          = ddouble(5.0)
    val x1                          = normal(prior_temperature, prior_temp_std_dev)
    val mult_bias_of_thermometer_std_dev = ddouble(0.2)
    val mult_bias_of_thermometer    = ddouble(0.0)
    val first_ys                    = exn-get(ys,0)
    val first_vs                    = exn-get(vs,0)
    val c_row                       = multivariate_gaussian(first_ys.length, ddouble(1.0) + mult_bias_of_thermometer, mult_bias_of_thermometer_std_dev)
    val v_row                       = convert_uncertainty_to_rand(first_vs)
    val predictions                 = plus(mult(x1, c_row), v_row)
    score_predictions(first_ys, predictions, ddouble(0.5))
    x1
  }
  g
}

fun score_predictions(true_values : row_vector, predicted_values : row_vector, score_std_dev) {
  if (true_values.length != predicted_values.length) {
    error("LengthError: predicted values and true values must be the same length! " + show(true_values.length) + " vs " + show(predicted_values.length))
  } else {
    zipwith(true_values, predicted_values, score_thunk(score_std_dev))
  }
}

fun score_thunk(score_std_dev : ddouble) {
  return fun(true_val : ddouble, pred_val : ddouble) {
    score(normal_pdf(true_val, score_std_dev, pred_val))
  }
}

fun convert_uncertainty_to_rand(vs : row_vector) : <exn, sample> row_vector {
  list(0, vs.length - 1) fun(i) {
    val uncertainty = exn-get(vs, i)
    normal(ddouble(0.0), uncertainty)
  }
}

/* fun tester() {
  show(random_sampler {
    plus([ddouble(5.0),7.4], [ddouble(2.0),ddouble(5.0)])
  })
} */

fun mult_thunk(x : ddouble) {
  return fun(v : ddouble) {
    x * v
  }
}

fun mult( x : ddouble, ys : row_vector ) : row_vector {
  map(ys, mult_thunk(x))
}

fun plus( xs : row_vector, ys : row_vector ) : exn row_vector {
  if (xs.length != ys.length) {
    error("AdditionError: Lengths are not equal! " + show(xs.length) + " vs " + show(ys.length))
  } else {
    zipwith(xs, ys, (+))
  }
}
