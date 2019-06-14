
import test/ojg/exp

effect yield {
  control yield() : ()
}

effect sample {
  fun sample() : double
}

effect score {
  fun score(x : exp) : ()
}

effect exc {
  fun raise(s : string ) : a
}

fun catch(action,h) {
  handle(action) {
    raise(s) -> h(s)
  }
}

fun weighted( w : exp, action : () -> <score|e> a ) : e (exp, a) {
  var g := w
  val x = with fun score(s) { g := mult_exp(g, s) } in action()
  (g,x)
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

fun random_sampler(action : () -> sample a) : ndet a {
  handle(action) {
    return x -> x
    sample() -> {resume(random())}
  }
}

fun advance(action : () -> yield a) : yield ((a : int) -> yield a) {
  handle(action) {
    return x -> fun(a) {x}
    yield() -> fun(a) {
      if (a > 0) then {
        resume(())(a - 1)
      } else {
        yield();
        resume(())(0)
      }
    }
  }
}
