module alg/handler_smc

import std/num/random
import core/env
import core/model
import core/trace
import handlers/core
import handlers/trace
import handlers/weight
import handlers/sequential
import handlers/population
import alg/smc

// An ordinary model may checkpoint anywhere. A population of suspended model
// executions carries its reader, trace and continuation through resampling.
pub fun smc-model(particle-count : int, environment : env,
                   action : () -> <checkpoint,obs-reader,model-dist,div|e> a) : <div,random|e> smc-result<a>
  val population = sample-population(particle-count, fn(){
    handle-sampling(fn(){
      handle-trace(fn(){
        mask<sample-value>{ mask<accumulate-weight>{ handle-core-state(environment, action) } }
      })
    })
  })
  val particles = population.values.map fn(item){
    val ((value, _remaining), entries) = item
    Smc-sample(value, entries, to-output-env(entries), observed-log-prob(entries))
  }
  val output : env = particles.foldl(empty(), fn(acc, particle){ merge(acc, particle.output-env) })
  Smc-result(particles, population.log-evidence, output)
