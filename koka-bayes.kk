
import std/num/double
import std/num/ddouble  // 128-bit double-double

alias model<a> = () -> a
alias thunk<a> = () -> a
alias rplus = ddouble
alias floatfunc = double -> double
alias regression = model<floatfunc>

effect yield {
  fun yield() : ()
}

effect sample {
  fun sample() : double
}

effect score {
  fun score(x : rplus) : ()
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
    score(w : rplus) -> {score(w); yield(); resume(())}
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

/* fun homogeneous_linear() : regression {
  val r = fun(x) {normal(0.0, 2.0) * x}
  val y = fun() {r}
  y
} */

/* let homogeneous_linear : regression
  = fun _ ->
      let a = normal 0.0 2.0 in
      fun x -> a *. x */


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
