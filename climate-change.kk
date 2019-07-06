public module test/koka-bayes/climate-change

import std/num/double

import test/koka-bayes/model-resources
import test/koka-bayes/effects-and-types
import test/koka-bayes/handlers
import test/koka-bayes/output-and-plot

fun multivariate_gaussian(dimension : int, mean : double, std_dev : double) : sample list<double> {
  list(1, dimension) fun(i) {
    normal(mean, std_dev)
  }
}

fun linear_gaussian_climate_data(ys : list<row_vector>, vs : list<row_vector>) {
  val prior_temperature           = 5.0
  val prior_temp_std_dev          = 25.0
  val x1                          = normal(prior_temperature, prior_temp_std_dev)
  val bias_of_thermometer_std_dev = 0.5
  val bias_of_thermometer         = 0.0
  val c_row                       = multivariate_gaussian(ys.length, 1.0 + bias_of_thermometer, bias_of_thermometer_std_dev)
  val v_row                       = convert_uncertainty_to_rand(get(vs,0))
  val predictions                 = plus(mult(x1, c_row), v_row)
  5
}

fun score_predictions(true_values : row_vector, predicted_values : row_vector) {

}

fun get(xs : list<_a>, index : int) : exn _a {
  match(xs[index]) {
    Nothing -> error("ListIndexError: Invalid list indexing at index: " + show(index))
    Just(x) -> x
  }
}

fun convert_uncertainty_to_rand(vs : row_vector) : <exn, sample> row_vector {
  list(0, vs.length - 1) fun(i) {
    val uncertainty = get(vs, i)
    normal(0.0, uncertainty)
  }
}

/* fun tester() {
  show(random_sampler {
    plus([5.0,7.4], [2.0,5.0])
  })
} */

fun mult_thunk(x : double) {
  return fun(v : double) {
    x * v
  }
}

fun mult( x : double, ys : row_vector ) : row_vector {
  map(ys, mult_thunk(x))
}

fun plus( xs : row_vector, ys : row_vector ) : exn row_vector {
  if (xs.length != ys.length) {
    error("AdditionError: Lengths are not equal!")
  } else {
    zipwith(xs, ys, (+))
  }
}
