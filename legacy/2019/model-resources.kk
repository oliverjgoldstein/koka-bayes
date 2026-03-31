public module model-resources

import std/num/double

import effects-and-types
import handlers
import exponents
import exn-get
import std/num/random

fun gaussian_model() : nmodel<double> {
  return fn() {
    normal(0.0, 10.0)
  }
}

fun sequential_gaussian(data_point : double) : nmodel<double> {
  val g = fn() {
    var x          := 0.0
    val vars       = 1.0
    val score-var  = 0.2
    for(0, 5) fn(i) {
      x := normal(x, vars)
      score(normal_pdf(x, score-var, data_point))
    }
    mask<random>{x}
  }
  g
}


fun fit(model : regression, dataset : two_d_data) : regression {
    val g = fn() {
      val f : double -> double = model()
      val map_fun = fn(xy) {
        match(xy) {
          (x,y) -> score(normal_pdf(f(x), 0.25, y))
        }
      }

      map(dataset, map_fun)
      f
    }
    g
}

fun generate_synthetic_lr_data(num : int) : random list<(double, bool)> {
  list(1, num) fn(i) {
    random_sampler{
      (sample() * 10.0, bernoulli(0.5))
    }
  }
}

fun logistic_regression(dat : list<(double,bool)>) : model<(double,double), _e> {
  val g = fn() {
    val m = normal(0.0, 1.0)
    val b = normal(0.0, 1.0)
    val sigma = grand(0.0,1.0)

    fun y(x) {
      normal(m*x + b, sigma)
    }

    fun sigmoid(x) {
      1.0 / (1.0 + dbl-e^(y(x)))
    }
    //
    // var i := 0
    // while { i < 2000 } {
    //   score(Exp(log(10.0)))
    //   i := i + 1
    // }

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
    for(1, p.length) fn(i) {
      val new_p = match(p[i]) {
        Nothing -> 0.0
        Just(aa) -> aa
      }
      a := !a + new_p / (hh + double(i))
    }

    return sqrt(2.0 * dbl-pi) * t^(hh + 0.5) * exp(0.0 - t) * !a
}

fun grand(alpha : double, beta : double) : <sample,div> double {
  if(alpha <= 1.0) {
    val x = grand(alpha + 1.0, beta)
    x * sample()^(1.0/alpha)
  }
  else {
    val d = alpha - 1.0/3.0
    val c = 1.0/sqrt(9.0*d)
    val v = grandx(d,c,0.0)
    (d * v / beta)
  }
}

private fun grandx(d : double, c : double, v : double ) : <sample,div> double {
  val z = normal(0.0,1.0)
  val w = (1.0 + c * z)^3.0
  if(z > (0.0 - (1.0/c))) {
    if (log(sample()) > (0.5*(z^2.0)) + d - d * w + d * log(w)) {
      grandx(d,c,w)
    } else {
      w
    }
  }
  else grandx(d,c,w)
}


fun fit_1d_gaussian(model : nmodel<double>, dataset : data_1d) : nmodel<double> {
  fun g() {
      val f : double = model()
      val map_fun = fn(x) {
        score(normal_pdf(f, 1.0, x))
      }

      map(dataset, map_fun)
      f
  }
  g
}


fun params()  {
  fun g() {
    val s = grand(1.0,1.0)
    s
  }
  g
}

fun random_walk( zs : list<double> ) : ((s : double) -> (nmodel<list<double>>)) {
  fun g(s : double) {
    fun f() {
      fun obs(x,y) {
        mask<random>{score(normal_pdf(x, 1.0, y))}
      }

      fun expand(xss : list<double>, yss : list<double>) {
        match(yss) {
          Nil -> return xss
          Cons(y, ys) -> {
            match(xss) {
              Nil -> return Nil
              Cons(x, xs) -> {
                val x' = normal(x,s)
                obs(x', y)
                expand([x', x] ++ xs, ys)
              }
            }
          }
        }
      }

      expand([0.0], zs).reverse
    }
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
