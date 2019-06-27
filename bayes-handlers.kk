import test/ojg/exp
alias model<a> = () -> <sample, score> a
alias regression = model<double -> double>
alias data = list<(double, double)>
alias data_1d = list<double>
alias sequential_data = list<list<double>>

alias histogram<a> = list<(exp, a)>
alias histofunc<a,b> = histogram<a> -> histogram<b>


effect yield {
  control yield() : ()
}

ambient fun sample() : double
ambient control score( s : exp ) : ()


effect exc {
  fun raise(s : string ) : a
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

val weighted = handler(wp : exp) {
    return x -> (wp, x)
    score(s) -> resume((), mult_exp(wp, s))
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
