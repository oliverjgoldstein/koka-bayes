module handlers/read

import core/env
import core/model

pub fun handle-read(environment : env, action : () -> <obs-reader|e> a) : e a
  var current := environment
  with fun read-observation(name)
    val (found, next) = maybe-consume-name(name, current)
    current := next
    found
  action()
