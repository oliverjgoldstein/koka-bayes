public module trace

import std/num/double

import effects-and-types
import exponents
import handlers
import sampling
import output-and-plot
import model-resources

type trace<a,e> {
  Trace(m : () -> e a, p : exp, l : trace_values, a : a)
}


fun trace_v(tr : trace<a,e>) : list<double> {
  match(tr) {
    Trace(_, _, d, _) -> d
  }
}

fun trace_m(tr : trace<a,e>) : (() -> e a) {
  match(tr) {
    Trace(m, _, _, _) -> m
  }
}

fun trace_p(tr : trace<a,e>) : exp {
  match(tr) {
    Trace(_, p, _, _) -> p
  }
}

fun trace_a(tr : trace<a,e>) : a {
  match(tr) {
    Trace(_, _, _, a) -> a
  }
}

fun perturb_trace(trace : trace<a,e>) : sample trace_values {
  val trace_values  = trace_v(trace)
  val perturb_index = random_range(trace_values.length)
  val div_trace     = split(trace_values, perturb_index)
  val new_trace     = match(div_trace) {
    (l1, Cons(_, l2)) -> l1 + [sample()] + l2
    (l1, l2) -> l1 + l2 // This should never be reached.
  }
  new_trace
}

fun with_randomness(model : () -> <sample,score|e> a, trace_values : trace_values) : <sample|e> (trace_values, (exp,a)) {
  val likelihood_a_trace =
    replay(trace_values) {
      weighted(Exp(0.0)) {
        model()
      }
    }
  likelihood_a_trace
}

fun mh_step(trace : trace<a,<sample,score|e>>) : <sample|e> trace<a,<sample,score|e>> {
  val modified_trace = perturb_trace(trace)
  match(trace) {
    Trace(model, p1, old_trace, _) -> {
      val p2b = with_randomness(model, modified_trace)
      match(p2b) {
        (new_trace, (p2, b)) -> {
          // This update procedure copies that of Monad Bayes:
          val ratio = min(1.0, ((exp_to_double(p2) * old_trace.length.double) / (exp_to_double(p1) * new_trace.length.double)))
          val accept = bernoulli(ratio)
          if(accept) {
            Trace(model, p2, new_trace, b)
          } else {
            trace
          }
        }
      }
    }
  }
}

fun random_range(upper_bound : int) : sample int {
  return int(sample() / (1.0 / double(upper_bound))) % upper_bound
}

fun split_tmcmc(lst : (list<(list<double>,a)>)) : div list<list<(list<double>,a)>> {
  /* val lst_as = map(lst, snd) */
  return splitter(lst, [])
}

fun splitter(lst_as : list<a>, build : list<list<a>>) : div list<list<a>> {
  val split_v = split(lst_as, 4000)
  match(split_v.fst) {
    Nil -> build
    Cons(_,_) -> {
      splitter(split_v.snd, build + [split_v.fst])
    }
  }
}

fun tmcmc(model : () -> <sample,score,div|e> a, steps : int, init_weight : exp, burnin : int) : <sample,div|e> (list<(list<double>,a)>, trace<a,<sample,score,div|e>>) {
  val model_results = weighted(init_weight) {
                        replay([]) {
                          model()
                        }
                      }

  val p = match(model_results) {
    (Exp(a), _) -> Exp(a)
  }

  val d = match(model_results) {
    (_, (d, _)) -> d
  }

  val a = match(model_results) {
    (_, (_, a)) -> a
  }

  model_stepper_recursive(steps, Trace(model, p, d, a), Nil, burnin)
}

fun model_stepper_recursive(steps : int, trace : trace<a,<sample,score,div|e>>, posterior : list<(list<double>,a)>, burnin) : <sample,div|e> (list<(list<double>,a)>, trace<a,<sample,score,div|e>>) {
  if(steps < 1) {
    (posterior, trace)
  } else {
    val new_trace = mh_step(trace)
    if (burnin > 0) {
      model_stepper_recursive(steps - 1, new_trace, posterior, burnin - 1)
    } else {
      model_stepper_recursive(steps - 1, new_trace, posterior + [(trace_v(new_trace), trace_a(new_trace))], burnin)
    }
  }
}
