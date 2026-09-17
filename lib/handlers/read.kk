module handlers/read

import core/env
import core/model

pub fun handle-read(environment : env, action : () -> <obs-reader|e> a) : e a
  fst(handle-read-state(environment, action))

// The cursor is scoped state: separate resumptions restore their own version.
pub fun handle-read-state(environment : env, action : () -> <obs-reader|e> a) : e (a,env)
  var current := environment
  with fun read-observation(name)
    val (found, next) = maybe-consume-name(name, current)
    current := next
    found
  val result = action()
  (result, current)
