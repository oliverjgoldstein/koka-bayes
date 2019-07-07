public module test/koka-bayes/output-and-plot

import std/num/double
import std/os/file
import std/os/path
import std/num/ddouble

import test/koka-bayes/effects-and-types
import test/koka-bayes/exponents

fun plot( f : (double -> double) ) : string {
  val lft = 0.0
  val rgt = 4.0
  val steps = 100
  val stp = (rgt - lft) / steps.double
  list-join(steps) fun(i:int) {
    val x = lft + (stp * i.double)
    val y = f( x )
    "[" + x.show(6) + "," + y.show(6) + "]"
  }
}

fun write( hist : histogram<double>, filename : string ) {
   write-text(path("./test/koka-bayes/output/" + filename), show(hist))
}

fun write( hist : histogram<(double, double)> , filename : string ) {
   write-text(path("./test/koka-bayes/output/" + filename), show(hist))
}


fun show(hist : histogram<double>) : string {
  var total_string := ""
  for(0, hist.length - 1) fun(i) {
    val str = match(hist[i]) {
      Nothing -> ""
      Just(x) -> match(x) {
        (Exp(dbl), a) -> {show-fixed(exp(ddouble(dbl))) + ", " + show-fixed(a)}
      }
    }
    total_string := total_string + str + "\n"
  }
  total_string
}

fun show(hist : histogram<(double, double)>) : string {
  var total_string := ""
  for(0, hist.length - 1) fun(i) {
    val str = match(hist[i]) {
      Nothing -> ""
      Just(x) -> match(x) {
        (Exp(dbl), (db1, db2)) -> {show-fixed(exp(ddouble(dbl))) + ", " + show-fixed(db1) + "\n" +
                                    show-fixed(exp(ddouble(dbl))) + ", " + show-fixed(db2)}
      }
    }
    total_string := total_string + str + "\n"
  }
  total_string
}

fun show( ls : (list<int>, list<int>) ) : string {
  match(ls) {
    (l1, l2) -> {show(l1) + show(l2)}
  }
}

fun show(xs : list<double>) : string {
  var total_string := "["
  for(0, xs.length - 1) fun(i) {

    if(i < xs.length - 1) {
      val str = match(xs[i]) {
        Nothing -> ""
        Just(x) -> show-fixed(x) + ","
      }
      total_string := total_string + str
    } else {
      val str = match(xs[i]) {
        Nothing -> ""
        Just(x) -> show-fixed(x)
      }
      total_string := total_string + str
    }
  }
  total_string := total_string + "]"
  total_string
}

fun show(hist : histogram<(double -> double)>) : console int{
  for(0, hist.length - 1) fun(i) {
    val str = match(hist[i]) {
      Nothing -> ""
      Just(x) -> match(x) {
        (Exp(dbl), func) -> {"(" + show-fixed(exp(ddouble(dbl))) + ", " + show-fixed(func(100.0)) + ")"}
      }
    }
    println(str)
  }
  0
}

fun example-plot() {
  plot( fun(x){ 2.0 * x } )
}

fun list-join(len : int, elem) {
  val xs = list(1,len,elem)
  "[" + xs.join(",") + "]"
}
