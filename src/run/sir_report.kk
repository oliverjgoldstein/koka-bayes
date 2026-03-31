module run/sir_report

import std/num/random
import diagnostics/sir_report

pub fun run-sir-report() : <console,fsys,exn,div,random> ()
  write-sir-report()

pub fun main() : <console,fsys,exn,div,random> ()
  run-sir-report()
