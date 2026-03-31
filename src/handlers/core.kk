module handlers/core

import std/num/random
import core/env
import core/model
import handlers/dist
import handlers/read

// Specialise a multimodal model under a model environment.
pub fun handle-core(environment : env, action : model<e,a>) : <sample-hook,observe-hook,div,random|e> a
  handle-read(environment, fn(){
    handle-dist(fn(){
      mask<sample-hook>{
        mask<observe-hook>{
          mask<random>{ action() }
        }
      }
    })
  })
