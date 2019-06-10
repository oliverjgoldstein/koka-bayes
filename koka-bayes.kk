
import std/num/double
import std/num/ddouble  // 128-bit double-double

alias model<a> = () -> a
alias thunk<a> = () -> a
alias rplus = ddouble
alias floatfunc = double -> <ndet> double
alias regression = model<floatfunc>
alias histogram<a> = list<(exp, a)>

type exp {
  Exp(i : double)
}

fun mult-exp(x : exp, y : exp) : exp {
  match (x) {
    Exp(j) -> {
      match(y) {
        Exp(t) -> Exp(t + j)
      }
    }
  }
}

fun div-exp(x : exp, y : exp) : exp {
  match (x) {
    Exp(j) -> {
      match(y) {
        Exp(t) -> Exp(t - j)
      }
    }
  }
}

fun show(x : exp) : string {
  match(x) {
    Exp(h) -> (dbl-e^h).show-fixed
  }
}

effect yield {
  fun yield() : ()
}

effect sample {
  fun sample() : double
}

effect score {
  fun score(x : exp) : ()
}

fun finalize(action) {
  handle(action) {
    return x -> x
    yield() -> {resume(())}
  }
}

fun yield-on-score(action) {
  handle(action) {
    return x -> x
    score(w : exp) -> {score(w); yield(); resume(())}
  }
}

fun random-sampler(action) {
  handle(action) {
    return x -> x
    sample() -> {resume(random())}
  }
}

fun advance(action)  {
  handle(action) {
    return x -> fun(a) {x}
    yield() -> fun(a) {
      if (a > 0) then {
        resume(()); a - 1
      } else {
        yield(); resume(()); 0
      }
    }
  }
}

fun populate(k : int, model : model<a>) : div histogram<a> {
    fun loop(i, acc) {
      if (i < k) then {
        fun result() {
          with weighted
          score(div-exp(Exp(0.0), Exp(k.double)))
          model()
        }

        loop(i + 1, (single(result()) + acc))
      } else {
        acc
      }
    }
    loop(0, Nil)
}

/* fun weighted (initial_weight, action) {
  handle(action) {
    fun score(w : rplus) -> fun(g) {resume(()) (g * w)}
    return x -> fun(w) {(w, x)}
  }
} */

fun weighted( action : () -> <score|e> a) : e (exp, a) {
  var w : exp  := Exp(1.0)
  val x = with fun score(s) { w := mult-exp(w, s) } in action()
  (w,x)
}

fun homogeneous_linear() : regression {
  val r = fun(x) {normal(0.0, 2.0) * x}
  val y = fun() {r}
  y
}

fun box-muller(u1 :double, u2 :double) {
  sqrt(-2.0 * log(u1)) * cos(dbl-twopi * u2)
}

fun standard-normal() : <sample> double {
  box-muller(sample(),sample())
}

fun normal(mean, sdv) {
  with random-sampler
  mean + standard-normal() * sdv
}

fun tester() {
  with random-sampler
  random()
}
