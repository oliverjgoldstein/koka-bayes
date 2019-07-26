public module model-resources

import std/num/double

import effects-and-types
import handlers
import exponents

fun gaussian_model() : nmodel<double> {
  return fun() {
    normal(0.0, 10.0)
  }
}

fun sequential_gaussian(data_point : double) : nmodel<double> {
  val g = fun() {
    val seed = normal(0.0, 1.0)
    score(normal_pdf(seed, 0.3, data_point))
    val seed2 = normal(seed, 1.0)
    score(normal_pdf(seed2, 0.3, data_point))
    val seed3 = normal(seed2, 0.5)
    score(normal_pdf(seed3, 0.3, data_point))
    val seed4 = normal(seed3, 0.4)
    score(normal_pdf(seed4, 0.3, data_point))
    val seed5 = normal(seed4, 0.2)
    score(normal_pdf(seed5, 0.2, data_point))
    val seed6 = normal(seed5, 0.1)
    score(normal_pdf(seed6, 0.1, data_point))
    seed6
  }
  g
}

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

fun generate_synthetic_lr_data(num : int) : ndet list<(double, bool)> {
  list(1, num) fun(i) {
    random_sampler{
      (sample() * 10.0, bernoulli(0.5))
    }
  }
}

fun logistic_regression(dat : list<(double,bool)>) : nmodel<(double,double)> {
  val g = fun() {
    val m = normal(0.0, 1.0)
    val b = normal(0.0, 1.0)
    val sigma = normal(0.0,1.0)

    fun y(x) {
      normal(m*x + b, sigma)
    }

    fun sigmoid(x) {
      1.0 / (1.0 + dbl-e^(y(x)))
    }

    fun obs(x_label) {
      match(x_label) {
        (x, label) -> {
          val p = sigmoid(x)
          if(label) {
            score(Exp(log(p)))
          } else {
            score(Exp(log(1.0 - p)))
          }
        }
      }
    }

    map(dat, obs)

    /* for(0, dat.length) fun(i) {
      score(Exp(1.0))
    } */
    (m,b)
  }
  g
}

fun gamma(x) {
    val p = [0.99999999999980993, 676.5203681218851, -1259.1392167224028,
        771.32342877765313, -176.61502916214059, 12.507343278686905,
        -0.13857109526572012, 9.9843695780195716e-6, 1.5056327351493116e-7]

    val g = 7.0
    if (x < 0.5) {
        return dbl-pi / (sin(dbl-pi * x) * gamma(1.0 - x))
    }

    val hh = x - 1.0

    val a = ref(0.99999999999980993)
    val t = hh + g + 0.5
    for(1, p.length) fun(i) {
      val new_p = match(p[i]) {
        Nothing -> 0.0
        Just(aa) -> aa
      }
      a := !a + new_p / (hh + double(i))
    }

    return sqrt(2.0 * dbl-pi) * t^(hh + 0.5) * exp(0.0 - t) * !a
}

fun gamrand(alpha : double, lambda : double) {
  if(alpha>1.0) {
    val d = alpha - 1.0/3.0
    val c = 1.0/sqrt(9.0*d)

    var flag := True
    val v = ref(0.0)
    while {flag} {
      val z = normal(0.0,1.0)
      if (z > (0.0 - (1.0/c))) {
        v := (1.0 + c * z)^3.0
        if (log(sample()) > (0.5 * z^(2.0) + d - d * !v + d * log(!v))) {
          flag := True
        } else {
          flag := False
        }
      }
    }

    return d * !v / lambda
  }
  else {
    val x = gamrand(alpha+1.0,lambda);
    return x * sample()^(1.0/alpha);
  }
}

fun fit_1d_gaussian(model : nmodel<double>, dataset : data_1d) : nmodel<double> {
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

fun bernoulli(p : double) : sample bool {
  val g = sample()
  if (g < p) {
    True
  } else{
    False
  }
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
