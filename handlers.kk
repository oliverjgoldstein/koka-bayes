public module handlers

import std/num/double
import std/num/random
import exponents
import effects-and-types


/////////////// In Development:


fun recorder(model_trace : trace_values, action : () -> <sample,sample|e> (a,b)) : <sample|e> (trace_values, a, b) {
  var trace := model_trace
  handle(action) {
    return(x)   {
      match(x) {
        (a,b) -> (trace,a,b)
      }
    }
    fun sample() {
      val rand_choice = sample()
      trace := trace ++ [rand_choice]
      rand_choice
    }
  }
}

/////////////////////

fun random_sampler(action : () -> <sample, random|e> a) : <random|e> a {
  with fun sample() { random-double() }
  action()
}

fun replay(trace: trace_values, action : () -> <sample|e> a) : <sample|e> (list<double>, a) {
  replayx(trace, {mask behind<sample>(action)} )
}

private fun replayx(trace: trace_values, action : () -> <sample,sample|e> a) : <sample|e> (list<double>, a) {
  var extended_trace : list<double> := trace
  var index     := -1
  handle(action) {
    return(x) -> (split(extended_trace, index + 1).fst, x)
    fun sample() {
      index := index + 1
      match(extended_trace[index]) {
        Nothing -> {
          val rand_choice = sample()
          extended_trace := extended_trace ++ [rand_choice]
          rand_choice
        }
        Just(random_value) -> random_value
      }
    }
  }
}

fun weighted(wp : exp, action : () -> <score|e> a) : e (exp, a) {
  var wps := wp
  handle(action){
    return(x)   { (wps, x) }
    fun score(s){ wps := mult_exp(wps, s) }
  }
}

fun finalize(action) {
  with fun yield(){ () }
  action()
}


fun yield_on_score(action : () -> <score,yield|e> a ) : <score,yield|e> a {
  yield_on_scorex({mask behind<score>(action)})
}

private fun yield_on_scorex(action : () -> <score,score,yield|e> a ) : <score,yield|e> a {
  with fun score(w){
    score(w)
    yield()
  }
  action()
}


fun advance-deep(action : () -> <yield|e> b) : e ((steps : int) -> <yield|e> b) {
  handle(action) {
    return(x) -> fn(_steps){ x }
    control yield() -> fn(steps) {
      if (steps > 0) then {
        (mask<yield>{resume(())})(steps - 1)
      } else {
        yield() // Propagate yields up
        (mask<yield>{resume(())})(0)
      }
    }
  }
}

fun advance(action : () -> <yield|e> b) : e ((steps : int) -> <yield|e> b) {
  handle(action) {
    return(x) -> fn(_steps){ x }
    rcontrol yield() -> fn(steps) {
      if (steps > 0) then {
        (mask<yield>{rcontext.resume(())})(steps - 1)
      } else {
        yield() // Propagate yields up
        // rcontext.resume-shallow(())(0)
        (mask<yield>{rcontext.resume(())})(0)  // use deep for now
      }
    }
  }
}

/*
fun advance-steps(action : () -> <yield|e> b, init : int ) : e (() -> <yield|e> b) {
  advance-upto(action,init)
}

private fun advance-upto(action, init : int )  {
  handle( action ) {
    return(x){ fn(_count){ x } }
    rcontrol yield() -> fn(count){ 
      if (count > 0) then {
        rcontext.resume(())(count - 1)
      } else {
        yield()
        fn(){ rcontext.shallow-resume(())(count) }
      }
    }
  }  
}
*/

fun advance-alt1(action : () -> <yield|e> b) : e ((a : int) -> <yield|e> b) {
  fn(init){ advance-fun({mask behind<yield>(action)},init) }
}

private fun advance-fun(action, init : int )  {
  var count := init
  handle( action ) {
    rcontrol yield() {
      count := count - 1        
      if (count > 0) then {
        rcontext.resume(())
      } else {
        yield() // Propagate yields up
        // rcontext.shallow_resume(())
        rcontext.resume(())
      }
    }
  }
}
/*
fun advance_handler(num : int, action: () -> <yield|e> a): e (() -> e a) {
    var steps := num
    handle({mask<local>(action)}){
        return x -> fn(){ x }
        yield() -> {
            if(steps > 0) then {
                yield()
                (fn(){ resume(()) })
            }else{
              steps := steps - 1
              resume(())
            }
        }
    }
}

*/
