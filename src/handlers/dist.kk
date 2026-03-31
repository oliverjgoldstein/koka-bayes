module handlers/dist

import std/num/random
import core/model

pub fun handle-dist(action : () -> <obs-reader,model-dist,sample-hook,observe-hook,div,random|e> a) : <obs-reader,sample-hook,observe-hook,div,random|e> a
  handle(action)
    return(x) x
    fun draw(distribution)
      sample-hook(Nothing, distribution)
    fun draw-observable(name, distribution)
      match read-observation(name)
        Just(value) -> observe-hook(name, distribution, value)
        Nothing     -> sample-hook(Just(name), distribution)
