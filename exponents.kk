import std/num/ddouble
import test/koka-bayes/effects-and-types


fun ln(x : exp) : ddouble {
  match(x) {
    (Exp(g)) -> g
  }
}

fun e(x : ddouble) {
  Exp(x)
}

fun exp_to_ddouble(x : exp) : ddouble {
  match(x) {
    (Exp(j)) -> pow(dd-e,j)
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
  fun ln_plus (a : ddouble, b : ddouble) {
      (a + log1p(pow(dd-e,(b - a))))
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
    Exp(h) -> "Exp " + show(h) + " with probability: " + show-fixed(pow(dd-e,h))
  }
}
