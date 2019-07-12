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
    val a_std_dev                         = 0.4
    val score_var                         = 4.65
    
    val x1                          = normal(prior_temperature, prior_temp_std_dev)
    val month_ys1                   = exn-get(ys,0)
    val month_vs1                   = exn-get(vs,0)
    val c_row1                      = multivariate_gaussian(month_ys1.length, 1.0 + mult_bias_of_thermometer, mult_bias_of_thermometer_std_dev)
    val v_row1                      = convert_uncertainty_to_rand(month_vs1)
    val predictions                 = plus(mult(x1, c_row1), v_row1)
    score_predictions(month_ys1, predictions, score_var)
    println("1st 20 year period.")
    
    val a_val1                      = normal(a_mean,a_std_dev)
    val w_val1                      = normal(w_mean,w_std_dev)
    val x2                          = x1 * a_val1 + w_val1
    val month_ys2                   = exn-get(ys,1)
    val month_vs2                   = exn-get(vs,1)
    val c_row2                      = multivariate_gaussian(month_ys2.length, 1.0 + mult_bias_of_thermometer, mult_bias_of_thermometer_std_dev)
    val v_row2                      = convert_uncertainty_to_rand(month_vs2)
    val predictions                 = plus(mult(x2, c_row2), v_row2)
    score_predictions(month_ys2, predictions, score_var)
    println("2nd 20 year period.")
    val a_val2                      = normal(a_mean,a_std_dev)
    val w_val2                      = normal(w_mean,w_std_dev)
    val x3                          = x2 * a_val2 + w_val2
    val month_ys3                   = exn-get(ys,2)
    val month_vs3                   = exn-get(vs,2)
    val c_row3                      = multivariate_gaussian(month_ys3.length, 1.0 + mult_bias_of_thermometer, mult_bias_of_thermometer_std_dev)
    val v_row3                      = convert_uncertainty_to_rand(month_vs3)
    val predictions                 = plus(mult(x3, c_row3), v_row3)
    score_predictions(month_ys3, predictions, score_var)
    println("3rd 20 year period.")
    val a_val3                      = normal(a_mean,a_std_dev)
    val w_val3                      = normal(w_mean,w_std_dev)
    val x4                          = x3 * a_val3 + w_val3
    val month_ys4                   = exn-get(ys,3)
    val month_vs4                   = exn-get(vs,3)
    val c_row4                      = multivariate_gaussian(month_ys4.length, 1.0 + mult_bias_of_thermometer, mult_bias_of_thermometer_std_dev)
    val v_row4                      = convert_uncertainty_to_rand(month_vs4)
    val predictions                 = plus(mult(x4, c_row4), v_row4)
    score_predictions(month_ys4, predictions, score_var)
    println("4th 20 year period.")
    val a_val4                      = normal(a_mean,a_std_dev)
    val w_val4                      = normal(w_mean,w_std_dev)
    val x5                          = x4 * a_val4 + w_val4
    val month_ys5                   = exn-get(ys,4)
    val month_vs5                   = exn-get(vs,4)
    val c_row5                      = multivariate_gaussian(month_ys5.length, 1.0 + mult_bias_of_thermometer, mult_bias_of_thermometer_std_dev)
    val v_row5                      = convert_uncertainty_to_rand(month_vs5)
    val predictions                 = plus(mult(x5, c_row5), v_row5)
    score_predictions(month_ys5, predictions, score_var)
    println("5th 20 year period.")
    val a_val5                      = normal(a_mean,a_std_dev)
    val w_val5                      = normal(w_mean,w_std_dev)
    val x6                          = x5 * a_val5 + w_val5
    val month_ys6                   = exn-get(ys,5)
    val month_vs6                   = exn-get(vs,5)
    val c_row6                      = multivariate_gaussian(month_ys6.length, 1.0 + mult_bias_of_thermometer, mult_bias_of_thermometer_std_dev)
    val v_row6                      = convert_uncertainty_to_rand(month_vs6)
    val predictions                 = plus(mult(x6, c_row6), v_row6)
    score_predictions(month_ys6, predictions, score_var)
    println("6th 20 year period.")
    val a_val6                      = normal(a_mean,a_std_dev)
    val w_val6                      = normal(w_mean,w_std_dev)
    val x7                          = x6 * a_val6 + w_val6
    val month_ys7                   = exn-get(ys,6)
    val month_vs7                   = exn-get(vs,6)
    val c_row7                      = multivariate_gaussian(month_ys7.length, 1.0 + mult_bias_of_thermometer, mult_bias_of_thermometer_std_dev)
    val v_row7                      = convert_uncertainty_to_rand(month_vs7)
    val predictions                 = plus(mult(x7, c_row7), v_row7)
    score_predictions(month_ys7, predictions, score_var)
    println("7th 20 year period.")
    val a_val7                      = normal(a_mean,a_std_dev)
    val w_val7                      = normal(w_mean,w_std_dev)
    val x8                          = x7 * a_val7 + w_val7
    val month_ys8                   = exn-get(ys,7)
    val month_vs8                   = exn-get(vs,7)
    val c_row8                      = multivariate_gaussian(month_ys8.length, 1.0 + mult_bias_of_thermometer, mult_bias_of_thermometer_std_dev)
    val v_row8                      = convert_uncertainty_to_rand(month_vs8)
    val predictions                 = plus(mult(x8, c_row8), v_row8)
    score_predictions(month_ys8, predictions, score_var)
    println("8th 20 year period.")
    val a_val8                      = normal(a_mean,a_std_dev)
    val w_val8                      = normal(w_mean,w_std_dev)
    val x9                          = x8 * a_val8 + w_val8
    val month_ys9                   = exn-get(ys,8)
    val month_vs9                   = exn-get(vs,8)
    val c_row9                      = multivariate_gaussian(month_ys9.length, 1.0 + mult_bias_of_thermometer, mult_bias_of_thermometer_std_dev)
    val v_row9                      = convert_uncertainty_to_rand(month_vs9)
    val predictions                 = plus(mult(x9, c_row9), v_row9)
    score_predictions(month_ys9, predictions, score_var)
    println("9th 20 year period.")
    val a_val9                      = normal(a_mean,a_std_dev)
    val w_val9                      = normal(w_mean,w_std_dev)
    val x10                         = x9 * a_val9 + w_val9
    val month_ys10                  = exn-get(ys,9)
    val month_vs10                  = exn-get(vs,9)
    val c_row10                     = multivariate_gaussian(month_ys10.length, 1.0 + mult_bias_of_thermometer, mult_bias_of_thermometer_std_dev)
    val v_row10                     = convert_uncertainty_to_rand(month_vs10)
    val predictions                 = plus(mult(x10, c_row10), v_row10)
    score_predictions(month_ys10, predictions, score_var)
    println("10th 20 year period.")
    val a_val10                     = normal(a_mean,a_std_dev)
    val w_val10                     = normal(w_mean,w_std_dev)
    val x11                         = x10 * a_val10 + w_val10
    val month_ys11                  = exn-get(ys,10)
    val month_vs11                  = exn-get(vs,10)
    val c_row11                     = multivariate_gaussian(month_ys11.length, 1.0 + mult_bias_of_thermometer, mult_bias_of_thermometer_std_dev)
    val v_row11                     = convert_uncertainty_to_rand(month_vs11)
    val predictions                 = plus(mult(x11, c_row11), v_row11)
    score_predictions(month_ys11, predictions, score_var)
    println("11th 20 year period.")
    val a_val11                     = normal(a_mean,a_std_dev)
    val w_val11                     = normal(w_mean,w_std_dev)
    val x12                         = x11 * a_val11 + w_val11
    val month_ys12                  = exn-get(ys,11)
    val month_vs12                  = exn-get(vs,11)
    val c_row12                     = multivariate_gaussian(month_ys12.length, 1.0 + mult_bias_of_thermometer, mult_bias_of_thermometer_std_dev)
    val v_row12                     = convert_uncertainty_to_rand(month_vs12)
    val predictions                 = plus(mult(x12, c_row12), v_row12)
    score_predictions(month_ys12, predictions, score_var)
    println("12th 20 year period.")
    val a_val12                     = normal(a_mean,a_std_dev)
    val w_val12                     = normal(w_mean,w_std_dev)
    val x13                         = x12 * a_val12 + w_val12
    val month_ys13                  = exn-get(ys,12)
    val month_vs13                  = exn-get(vs,12)
    val c_row13                     = multivariate_gaussian(month_ys13.length, 1.0 + mult_bias_of_thermometer, mult_bias_of_thermometer_std_dev)
    val v_row13                     = convert_uncertainty_to_rand(month_vs13)
    val predictions                 = plus(mult(x13, c_row13), v_row13)
    score_predictions(month_ys13, predictions, score_var)
    println("13th 20 year period.")
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
    error("AdditionError: Lengths are not equal! " + show(xs.length) + " vs " + show(ys.length))
  } else {
    zipwith(xs, ys, (+))
  }
}
