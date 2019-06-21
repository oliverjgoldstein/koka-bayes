import std/num/double

type exp {
  Exp(i : double)
}

fun ln(x : exp) : double {
  match(x) {
    (Exp(g)) -> g
  }
}

fun e(x : double) {
  Exp(x)
}

fun exp_to_double(x : exp) : double {
  match(x) {
    (Exp(j)) -> dbl-e^j
  }
}

fun mult_exp(x : exp, y : exp) : exp {
  match (x) {
    Exp(j) -> {
      match(y) {
        Exp(t) -> Exp(j + t)
      }
    }
  }
}

fun div_exp(x : exp, y : exp) : exp {
  match (x) {
    Exp(j) -> {
      match(y) {
        Exp(t) -> Exp(j - t)
      }
    }
  }
}

fun plus_exp(x : exp, y : exp) {
  fun ln_plus (a : double, b : double) {
      (a + log1p(dbl-e^(b - a)))
  }
  match(x) {
    (Exp(xe)) -> match(y) {
      (Exp(ye)) -> {
        if (xe < ye) then {
          Exp(ln_plus(ye, xe))
        } else {
          Exp(ln_plus(xe, ye))
        }
      }
    }
  }
}

fun show(x : exp) : string {
  match(x) {
    Exp(h) -> "Exp " + show(h) + " with value: " + show-fixed(dbl-e^h)
  }
}
