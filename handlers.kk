public module handlers

import std/num/double

import exponents
import effects-and-types

fun random_sampler(action : () -> <sample|e> a) : <ndet|e> a {
  with fun sample() { random() }
  mask<ndet>(action)  // mask out `ndet` from the `action` effect
}

fun replay(trace : trace_values, action : () -> <sample,sample|e> a) : <sample|e> (list<double>, a) {
  var extended_trace : list<double> := trace
  var index     := -1
  handle(action) {
    return x -> (split(extended_trace, index).fst, x)
    sample() -> {
      index := index + 1
      match(extended_trace[index]) {
        Nothing -> {
          val rand_choice = sample()
          extended_trace := extended_trace + [rand_choice]
          resume(rand_choice)
        }
        Just(random_value) -> resume(random_value)
      }
    }
  }
}

/* val weighted = handler(wp : exp) {
    return x -> (wp, x)
    score(s) -> resume((), mult_exp(wp, s))
} */


fun weighted(wp : exp, action) {
  var wps := wp
    handle(action) {
      return x -> (wps, x)
      score(s) -> {wps := mult_exp(wps, s); resume(())}
  }
}


fun finalize(action) {
  handle(action) {
    return x -> x
    yield() -> resume(())
  }
}

fun yield_on_score(action) {
  handle(action) {
    return x -> x
    score(w : exp) -> {score(w); yield(); resume(())}
  }
}

fun advance(action : () -> <yield|e> b) : e ((a : int) -> <yield|e> b) {
  handle(action) {
    return x -> fun(a){x}
    yield() -> fun(a) {
      if (a > 0) then {
        (mask<yield>{resume(())})(a - 1)
      } else {
        yield()
        (mask<yield>{resume(())})(0)
      }
    }
  }
}
