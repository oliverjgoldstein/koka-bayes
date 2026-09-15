module alg/lwis

import std/num/random
import alg/lw
import core/env
import core/model
import core/weights

pub fun lwis<a,e>(count : int, environment : env, action : model<e,a>) : <div,random|e> list<a>
  val weighted = lw(count, environment, action)
  resample-values(count, weighted)

pub fun resample-values<a>(count : int, samples : list<weighted-sample<a>>) : <div,random> list<a>
  resample-weighted(count, samples).map(fn(sample){ sample.value })

// An empty result indicates no finite positive posterior mass.
pub fun resample-weighted<a>(count : int, samples : list<weighted-sample<a>>) : <div,random> list<weighted-sample<a>>
  resample-log-weighted(count, samples, fn(sample){ sample.log-weight })
