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

fun linear_gaussian_climate_data(ys : list<row_vector>, vs : list<row_vector>) : (() -> <console,exn,sample,score> list<double>) {
  val g = fun() {
    val prior_temperature                 = 0.0
    val prior_temp_std_dev                = 5.0
    val mult_bias_of_thermometer_std_dev  = 0.05
    val mult_bias_of_thermometer          = 0.0
    val w_mean                            = 0.0
    val w_std_dev                         = 1.0
    val a_mean                            = 1.0
    val a_std_dev                         = 0.3
    val score_var                         = 5.0
    
    val x1                          = normal(prior_temperature, prior_temp_std_dev)
    val month_ys                    = exn-get(ys,0)
    val month_vs                    = exn-get(vs,0)
    val c_row                       = multivariate_gaussian(month_ys.length, 1.0 + mult_bias_of_thermometer, mult_bias_of_thermometer_std_dev)
    val v_row                       = convert_uncertainty_to_rand(month_vs)
    val predictions                 = plus(mult(x1, c_row), v_row)
    score_predictions(month_ys, predictions, score_var)
    println("x1")
    
    val a_val                       = normal(a_mean,a_std_dev)
    val w_val                       = normal(w_mean,w_std_dev)
    val x2                          = x1 * a_val + w_val
    val month_ys                    = exn-get(ys,1)
    val month_vs                    = exn-get(vs,1)
    val c_row                       = multivariate_gaussian(month_ys.length, 1.0 + mult_bias_of_thermometer, mult_bias_of_thermometer_std_dev)
    val v_row                       = convert_uncertainty_to_rand(month_vs)
    val predictions                 = plus(mult(x2, c_row), v_row)
    score_predictions(month_ys, predictions, score_var)
    println("x2")
    val a_val                       = normal(a_mean,a_std_dev)
    val w_val                       = normal(w_mean,w_std_dev)
    val x3                          = x2 * a_val + w_val
    val month_ys                    = exn-get(ys,2)
    val month_vs                    = exn-get(vs,2)
    val c_row                       = multivariate_gaussian(month_ys.length, 1.0 + mult_bias_of_thermometer, mult_bias_of_thermometer_std_dev)
    val v_row                       = convert_uncertainty_to_rand(month_vs)
    val predictions                 = plus(mult(x3, c_row), v_row)
    score_predictions(month_ys, predictions, score_var)
    println("x3")
    val a_val                       = normal(a_mean,a_std_dev)
    val w_val                       = normal(w_mean,w_std_dev)
    val x4                          = x3 * a_val + w_val
    val month_ys                    = exn-get(ys,3)
    val month_vs                    = exn-get(vs,3)
    val c_row                       = multivariate_gaussian(month_ys.length, 1.0 + mult_bias_of_thermometer, mult_bias_of_thermometer_std_dev)
    val v_row                       = convert_uncertainty_to_rand(month_vs)
    val predictions                 = plus(mult(x4, c_row), v_row)
    score_predictions(month_ys, predictions, score_var)
    println("x4")
    val a_val                       = normal(a_mean,a_std_dev)
    val w_val                       = normal(w_mean,w_std_dev)
    val x5                          = x4 * a_val + w_val
    val month_ys                    = exn-get(ys,4)
    val month_vs                    = exn-get(vs,4)
    val c_row                       = multivariate_gaussian(month_ys.length, 1.0 + mult_bias_of_thermometer, mult_bias_of_thermometer_std_dev)
    val v_row                       = convert_uncertainty_to_rand(month_vs)
    val predictions                 = plus(mult(x5, c_row), v_row)
    score_predictions(month_ys, predictions, score_var)
    println("x5")
    val a_val                       = normal(a_mean,a_std_dev)
    val w_val                       = normal(w_mean,w_std_dev)
    val x6                          = x5 * a_val + w_val
    val month_ys                    = exn-get(ys,5)
    val month_vs                    = exn-get(vs,5)
    val c_row                       = multivariate_gaussian(month_ys.length, 1.0 + mult_bias_of_thermometer, mult_bias_of_thermometer_std_dev)
    val v_row                       = convert_uncertainty_to_rand(month_vs)
    val predictions                 = plus(mult(x6, c_row), v_row)
    score_predictions(month_ys, predictions, score_var)
    println("x6")
    val a_val                       = normal(a_mean,a_std_dev)
    val w_val                       = normal(w_mean,w_std_dev)
    val x7                          = x6 * a_val + w_val
    val month_ys                    = exn-get(ys,6)
    val month_vs                    = exn-get(vs,6)
    val c_row                       = multivariate_gaussian(month_ys.length, 1.0 + mult_bias_of_thermometer, mult_bias_of_thermometer_std_dev)
    val v_row                       = convert_uncertainty_to_rand(month_vs)
    val predictions                 = plus(mult(x7, c_row), v_row)
    score_predictions(month_ys, predictions, score_var)
    println("x7")
    val a_val                       = normal(a_mean,a_std_dev)
    val w_val                       = normal(w_mean,w_std_dev)
    val x8                          = x7 * a_val + w_val
    val month_ys                    = exn-get(ys,7)
    val month_vs                    = exn-get(vs,7)
    val c_row                       = multivariate_gaussian(month_ys.length, 1.0 + mult_bias_of_thermometer, mult_bias_of_thermometer_std_dev)
    val v_row                       = convert_uncertainty_to_rand(month_vs)
    val predictions                 = plus(mult(x8, c_row), v_row)
    score_predictions(month_ys, predictions, score_var)
    println("x8")
    val a_val                       = normal(a_mean,a_std_dev)
    val w_val                       = normal(w_mean,w_std_dev)
    val x9                          = x8 * a_val + w_val
    val month_ys                    = exn-get(ys,8)
    val month_vs                    = exn-get(vs,8)
    val c_row                       = multivariate_gaussian(month_ys.length, 1.0 + mult_bias_of_thermometer, mult_bias_of_thermometer_std_dev)
    val v_row                       = convert_uncertainty_to_rand(month_vs)
    val predictions                 = plus(mult(x9, c_row), v_row)
    score_predictions(month_ys, predictions, score_var)
    println("x9")
    val a_val                       = normal(a_mean,a_std_dev)
    val w_val                       = normal(w_mean,w_std_dev)
    val x10                         = x9 * a_val + w_val
    val month_ys                    = exn-get(ys,9)
    val month_vs                    = exn-get(vs,9)
    val c_row                       = multivariate_gaussian(month_ys.length, 1.0 + mult_bias_of_thermometer, mult_bias_of_thermometer_std_dev)
    val v_row                       = convert_uncertainty_to_rand(month_vs)
    val predictions                 = plus(mult(x10, c_row), v_row)
    score_predictions(month_ys, predictions, score_var)
    println("x10")
    val a_val                       = normal(a_mean,a_std_dev)
    val w_val                       = normal(w_mean,w_std_dev)
    val x11                         = x10 * a_val + w_val
    val month_ys                    = exn-get(ys,10)
    val month_vs                    = exn-get(vs,10)
    val c_row                       = multivariate_gaussian(month_ys.length, 1.0 + mult_bias_of_thermometer, mult_bias_of_thermometer_std_dev)
    val v_row                       = convert_uncertainty_to_rand(month_vs)
    val predictions                 = plus(mult(x11, c_row), v_row)
    score_predictions(month_ys, predictions, score_var)
    println("x11")
    val a_val                       = normal(a_mean,a_std_dev)
    val w_val                       = normal(w_mean,w_std_dev)
    val x12                         = x11 * a_val + w_val
    val month_ys                    = exn-get(ys,11)
    val month_vs                    = exn-get(vs,11)
    val c_row                       = multivariate_gaussian(month_ys.length, 1.0 + mult_bias_of_thermometer, mult_bias_of_thermometer_std_dev)
    val v_row                       = convert_uncertainty_to_rand(month_vs)
    val predictions                 = plus(mult(x12, c_row), v_row)
    score_predictions(month_ys, predictions, score_var)
    println("x12")
    val a_val                       = normal(a_mean,a_std_dev)
    val w_val                       = normal(w_mean,w_std_dev)
    val x13                         = x12 * a_val + w_val
    val month_ys                    = exn-get(ys,12)
    val month_vs                    = exn-get(vs,12)
    val c_row                       = multivariate_gaussian(month_ys.length, 1.0 + mult_bias_of_thermometer, mult_bias_of_thermometer_std_dev)
    val v_row                       = convert_uncertainty_to_rand(month_vs)
    val predictions                 = plus(mult(x13, c_row), v_row)
    score_predictions(month_ys, predictions, score_var)
    
    [x1,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12,x13]
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
    score(normal_pdf(true_val, score_std_dev, pred_val))
  }
}

fun convert_uncertainty_to_rand(vs : row_vector) : <exn, sample> row_vector {
  list(0, vs.length - 1) fun(i) {
    val uncertainty = exn-get(vs, i)
    normal(0.0, uncertainty/10.0)
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
    error("AdditionError: Lengths are not equal! " + show(xs.length) + " vs " + show(ys.length))
  } else {
    zipwith(xs, ys, (+))
  }
}
