public module climate-change

import std/num/double

import model-resources
import effects-and-types
import handlers
import output-and-plot
import exponents
import exn-get

fun multivariate_gaussian(dimension : int, mean : double, std_dev : double) : sample list<double> {
  list(1, dimension) fun(i) {
    normal(mean, std_dev)
  }
}

fun linear_gaussian_climate_data(ys : list<row_vector>, vs : list<row_vector>, print : bool, diff : double, subtract : double, score_var) : model<list<double>,<exn>> {
  val g = fun() {
    val mult_bias_of_thermometer_std_dev  = 0.05
    val mult_bias_of_thermometer          = 0.0
    val w_mean                            = 0.0
    val w_std_dev                         = 1.0
    val a_mean                            = 1.0
    val a_std_dev                         = 0.4

    var x := []
    for(0, 12) fun(i) {
      if(i == 0) {
        x := x + [(sample() * diff) + subtract]
      } else {
        val a_val = normal(a_mean,a_std_dev)
        val w_val = normal(w_mean,w_std_dev)
        x := x + [exn-get(x, i - 1) * a_val + w_val]
      }
      val month_ys = exn-get(ys,i)
      val month_vs = exn-get(vs,i)
      val c_row = multivariate_gaussian(month_ys.length, 1.0 + mult_bias_of_thermometer, mult_bias_of_thermometer_std_dev)
      val v_row = convert_uncertainty_to_rand(month_vs)
      val predictions = plus(mult(exn-get(x, i), c_row), v_row)

      score_predictions(month_ys, predictions, score_var)
      ()
    }

    list(0,12) fun(i) {
      exn-get(x, i)
    }
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

fun score_thunk(score_std_dev : double) {
  return fun(true_val : double, pred_val : double) {
    score(normal_pdf(pred_val, score_std_dev, true_val))
  }
}

fun convert_uncertainty_to_rand(vs : row_vector) : <exn, sample> row_vector {
  list(0, vs.length - 1) fun(i) {
    val uncertainty = exn-get(vs, i)
    normal(0.0, uncertainty / 3.92) // This factor converts confidence interval to std_dev.
  }
}

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
    error("AdditionError: Lengths are not equal! " + show(xs.length) + " vs " + show(ys.length))
  } else {
    zipwith(xs, ys, (+))
  }
}
