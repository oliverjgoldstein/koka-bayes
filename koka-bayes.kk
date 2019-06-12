public module test/ojg/koka-bayes

import std/num/double
/* import lib/std/core */

alias model<a> = () -> a
alias thunk<a> = () -> a
alias doublefunc = double -> <ndet> double
alias regression = model<doublefunc>
alias histogram<a> = list<(exp, a)>
alias histofunc<a,b> = histogram<a> -> histogram<b>

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
        Exp(t) -> Exp(t + j)
      }
    }
  }
}

fun div_exp(x : exp, y : exp) : exp {
  match (x) {
    Exp(j) -> {
      match(y) {
        Exp(t) -> Exp(t - j)
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

effect exc {
  fun raise(s : string ) : a
}

fun catch(action,h) {
  handle(action) {
    raise(s) -> h(s)
  }
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

fun random-sampler(action : () -> sample a) : ndet a {
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

fun populate(k : int, model : () -> <sample, score> a) : <div, sample> histogram<a>  {
    fun loop(i, acc) {
      if (i < k) then {
        fun result() {
          weighted(Exp(0.0)) {
          score(div_exp(Exp(0.0), Exp(k.double)))
          model()
        }
      }
        loop((i + 1), (single(result()) + acc))
      } else {
        acc
      }
    }
    loop(0, Nil)
}

fun sum_weights(histogram : histogram<a>) : exp {
  fun foldlfunc(acc, wx) {
    match(wx) {
      (w,_) -> plus_exp(acc, w)
    }
  }
  foldl(histogram, Exp(0.0), foldlfunc)
}

fun weighted_choice(histogram : histogram<a>) : <exc, sample> a {
  val total_w = sum_weights(histogram)
  val total_fuel = (exp_to_double(total_w)) * sample()
  fun choose(fuel : double, ws : histogram<a>) : <exc> a {
    match(ws) {
      Nil -> raise("Error")
      Cons((w,x), wxs) -> {
        val fuel_new = fuel - exp_to_double(w)
        if (fuel_new <= 0.0) then {
          x
        } else {
          choose(fuel_new, wxs)
        }
      }
    }
  }
  choose(total_fuel, histogram)
}

fun resample(histogram : histogram<a>) : <div, sample> histogram<a> {
  val n = histogram.length
  val total_w = sum_weights(histogram)
  fun resample_model() {
    score(total_w)
    catch({random-sampler(weighted_choice(histogram))}, fun(s:string) {s})
  }

  populate(n, resample_model)
}

/* fun smc(particle_num : int, step_num : int, step_size : int, model : model<a>) {
  with random_sampler handle
  fun smc-func() {
    with advance handle
    with yield_on_score handle
    model()
  }
  val pop = populate(particle_num, smc-func)

  fun loop(i, pop) {
      if (i < step_num) then {
        pop (resample)
      } else {

      }
  }

} */

fun pop_map( f : a -> b ) : histofunc<a,b> {
  (fun(lista) {
    pop_map_helper(f, lista)
  })
}

fun pop_map_helper(f : a -> b, t : histogram<a>) : (histogram<b>) {
    match(t) {
      Nil -> Nil
      Cons(x, xs) -> match(x) {
        (Exp(n), a) -> Cons((Exp(n), f(a)), pop_map_helper(f, xs))
      }
    }
}


fun weighted( w : exp, action : () -> <score|e> a ) : e (exp, a) {
  var g := w
  val x = with fun score(s) { g := mult_exp(g, s) } in action()
  (g,x)
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
