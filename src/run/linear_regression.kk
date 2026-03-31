module run/linear_regression

import std/num/random
import examples/linear_regression

pub fun run-linear-regression() : <console,div,random> ()
  simulate-demo()
  println("")
  lw-demo()
  println("")
  lwis-demo()

pub fun main() : <console,div,random> ()
  run-linear-regression()
