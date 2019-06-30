import test/ojg/exp
alias model<a>        = () -> <sample, score> a
alias regression      = model<double -> double>
alias sequential_data = list<list<double>>
alias data_1d         = list<double>
alias two_d_data      = list<(double, double)>
alias trace_values    = list<double>
alias histogram<a>    = list<(exp, a)>
alias histofunc<a,b>  = histogram<a> -> histogram<b>

effect yield {
  control yield() : ()
}

ambient fun sample() : double
ambient control score( s : exp ) : ()

effect exc {
  fun raise(s : string ) : a
}

type trace<a> {
  Trace(m : model<a>, l : trace_values)
}

fun random_sampler(action : () -> <sample|e> a) : <ndet|e> a {
  with fun sample() { random() }
  mask<ndet>(action)  // mask out `ndet` from the `action` effect
}


fun catch(action,h) {
  handle(action) {
    raise(s) -> h(s)
  }
}

fun trace(action) {
  var random_list := Nil
  handle(action) {
    return x -> (random_list, x)
    sample() -> {
      val rand_choice = sample()
      random_list := random_list + [rand_choice]
      resume(rand_choice)
    }
  }
}

fun replay(trace : Trace, action) {
  var new_trace := traceDist(trace)
  var index     := 0
  handle(action) {
    return x -> (x, new_trace)
    sample() -> {
      match(trace[index]) {
        Just(random_value) -> resume(random_value)
        Nothing -> {
          val rand_choice = sample()
          new_trace := new_trace + [rand_choice]
          resume(rand_choice)
        }
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
