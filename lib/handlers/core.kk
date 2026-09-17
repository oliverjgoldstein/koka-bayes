module handlers/core

import std/num/random
import core/env
import core/model
import handlers/dist
import handlers/read

// Specialise a multimodal model under a model environment.
pub fun handle-core(environment : env, action : model<e,a>) : <sample-hook,observe-hook,factor-hook,div,random|e> a
  fst(handle-core-state(environment, action))

pub fun handle-core-state(environment : env, action : model<e,a>) : <sample-hook,observe-hook,factor-hook,div,random|e> (a,env)
  handle-read-state(environment, fn(){
    handle-dist(fn(){
      mask<sample-hook>{
        mask<observe-hook>{
          mask<factor-hook>{
            mask<random>{ action() }
          }
        }
      }
    })
  })
