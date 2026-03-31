module run/hmm

import std/num/random
import examples/hmm

pub fun run-hmm() : <console,div,random> ()
  simulate-demo()
  println("")
  observed-demo()
  println("")
  higher-order-demo()
  println("")
  smc-demo()
  println("")
  rmsmc-demo()

pub fun main() : <console,div,random> ()
  run-hmm()
