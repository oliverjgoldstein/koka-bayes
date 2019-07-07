public module test/koka-bayes/data/preprocessing

import std/num/double
import std/os/path
import std/os/file

fun pre_process_data() { //: (list<double>, list<double>) {
  val uncertainties1 = map(split(read-text(path("./test/koka-bayes/data/measurement-uncertainties1.txt")), "\n"), parse-double)
  val uncertainties2 = map(split(read-text(path("./test/koka-bayes/data/measurement-uncertainties2.txt")), "\n"), parse-double)
  val temperatures1  = map(split(read-text(path("./test/koka-bayes/data/temperature-readings1.txt")), "\n"), parse-double)
  val temperatures2  = map(split(read-text(path("./test/koka-bayes/data/temperature-readings2.txt")), "\n"), parse-double)

  val uncertainties = concat([uncertainties1, uncertainties2])
  val temperatures  = concat([temperatures1, temperatures2])
  println(temperatures.length)
}
