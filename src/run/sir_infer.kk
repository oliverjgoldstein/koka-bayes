module run/sir_infer

import std/num/random
import examples/sir

pub fun run-sir-infer() : <console,div,random> ()
  inference-demo()
  println("")
  pmmh-demo()
  println("")
  smc2-demo()

pub fun main() : <console,div,random> ()
  run-sir-infer()
