module alg/parameter

import core/env

// A parameter proposal separates generated output from the unconsumed input
// stream. State-aware kernels must return the cursor after their proposed
// parameter-level model has consumed its observations.
pub struct parameter-proposal<p>
  parameter      : p
  parameter-env  : env
  remaining-env  : env
  log-correction : float64
