module main

import std/num/random
import run/linear_regression
import run/hmm
import run/sir_simulate
import run/sir_infer

pub fun main() : <console,div,random> ()
  println("== Linear Regression ==")
  run-linear-regression()
  println("")
  println("== Hidden Markov Model ==")
  run-hmm()
  println("")
  println("== SIR Simulation ==")
  run-sir-simulate()
  println("")
  println("== SIR Inference ==")
  run-sir-infer()
