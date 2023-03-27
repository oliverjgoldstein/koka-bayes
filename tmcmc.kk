public module tmcmc

import std/num/double

import effects-and-types
import exponents
import handlers
import sampling
import output-and-plot
import model-resources

// define(['./std_core_types', './std_core_hnd', './std_core', './exn_dash_get', './model_dash_resources', './handlers', './effects_dash_and_dash_types', './exponents'], function($std_core_types, $std_core_hnd, $std_core, $exn_dash_get, $model_dash_resources, $handlers, $effects_dash_and_dash_types, $exponents) {


type trace<a,e> {
  Trace(m : () -> e a, p : exp, l : trace_values, a : a)
}

fun perturb_trace(trace_values : trace_values) : sample trace_values {
  val perturb_index = random_range(trace_values.length)
  val div_trace     = split(trace_values, perturb_index)
  val new_trace     = match(div_trace) {
    (l1, Cons(_, _)) -> l1 ++ [sample()] // This is the source of a bug ++ l2
    (l1, l2) -> l1 ++ l2 // This should never be reached.
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
  val modified_trace = perturb_trace(trace.l)
  match(trace) {
    Trace(model, p1, old_trace, _) -> {
      val p2b = with_randomness(model, modified_trace)
      match(p2b) {
        (new_trace, (p2, b)) -> {
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

/////////////////////////////////////////// In Development:
type trace_rmsmc<a,e> {
  RTrace(m : () -> ((int) -> e a), p : exp, l : trace_values)
}

fun with_randomness_rmsmc(model  : () -> ((int) -> <exn,yield,score,sample,sample|e> a), trace_values : trace_values) : <sample,sample,exn,yield|e> (trace_values, (exp,a)) {
  val likelihood_a_trace =
    replay(trace_values) {
      weighted(Exp(0.0)) {
         model()(trace_values.length)
      }
    }
  likelihood_a_trace
}


fun mh_step_rmsmc(       trace : trace_rmsmc<a,<sample,sample,score,yield,exn|e>>) :
  <sample, sample, yield, exn|e> trace_rmsmc<a,<sample,sample,score,yield,exn|e>> {
  val modified_trace = perturb_trace(trace.l)
  match(trace) {
    RTrace(model, p1, old_trace) -> {
      val p2b = with_randomness_rmsmc(model, modified_trace)
      match(p2b) {
        (new_trace, (p2, _)) -> {
          val ratio = min(1.0, ((exp_to_double(p2) * old_trace.length.double) / (exp_to_double(p1) * new_trace.length.double)))
          val accept = bernoulli(ratio)
          if(accept) {
            RTrace(model, p2, new_trace)
          } else {
            trace
          }
        }
      }
    }
  }
}
//////////////////////////////////////////


fun random_range(upper_bound : int) : sample int {
  return int(sample() / (1.0 / double(upper_bound))) % upper_bound
}

fun tmcmc(model : () -> <sample,score,div|e> a, steps : int, init_weight : exp, burnin : int) : <sample,div|e> (list<(list<double>,a)>, trace<a,<sample,score,div|e>>) {
  val model_results = weighted(init_weight) {
                        replay([]) {
                          model()
                        }
                      }

  val (p,(d,a)) = model_results

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
      model_stepper_recursive(steps - 1, new_trace, posterior ++ [(new_trace.l, new_trace.a)], burnin)
    }
  }
}
