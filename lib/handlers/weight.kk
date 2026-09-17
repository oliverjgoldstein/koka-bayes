module handlers/weight

import std/num/float64

// Internal scoring can also pass an estimated likelihood to an enclosing layer.
pub effect fun accumulate-weight(log-weight : float64) : ()

// Local state is restored separately by each continuation resumption.
pub fun handle-weight(action : () -> <accumulate-weight|e> a) : e (a,float64)
  var weight := 0.0
  with fun accumulate-weight(increment)
    weight := weight + increment
  val result = action()
  (result, weight)

pub fun push-evidence(log-evidence : float64) : accumulate-weight ()
  accumulate-weight(log-evidence)
