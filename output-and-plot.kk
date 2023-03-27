public module output-and-plot

import std/num/double
import std/os/file
import std/os/path
import std/num/ddouble

import effects-and-types
import exponents



fun write( trace : list<(list<double>,double)>, filename : string ) {
    write-text-file(path(filename), show_trace_single(trace))
}

fun write( trace : list<(list<double>,list<double>)>, filename : string ) {
    write-text-file(path(filename), show_trace(trace))
}

fun write( hist : histogram<double>, filename : string ) {
   write-text-file(path(filename), show(hist))
}

fun write( hist : histogram<(double, double)> , filename : string ) {
   write-text-file(path(filename), show(hist))
}

fun write( hist : histogram<(list<double>)> , filename : string ) {
   write-text-file(path(filename), show(hist))
}

fun show_trace(tmcmc_result : list<(list<double>,list<double>)>) : string {
  var total_string := ""
  for(0, tmcmc_result.length - 1) fn(i) {
    val str = match(tmcmc_result[i]) {
      Nothing -> ""
      Just((_,a)) -> list_to_csv(a)
    }
    total_string := total_string ++ str
  }
  total_string
}


fun plot( f : (double -> double) ) : string {
  val lft = 0.0
  val rgt = 4.0
  val steps = 100
  val stp = (rgt - lft) / steps.double
  list-join(steps) fn(i:int) {
    val x = lft + (stp * i.double)
    val y = f( x )
    "[" ++ x.show(6) ++ "," ++ y.show(6) ++ "]"
  }
}
// These both ignore the trace of the results.
fun show_trace_single(tmcmc_result : list<(list<double>,double)>) : string {
  var total_string := ""
  for(0, tmcmc_result.length - 1) fn(i) {
    val str = match(tmcmc_result[i]) {
      Nothing -> ""
      Just((_,a)) -> show-fixed(a, 1)
    }
    total_string := total_string ++ str ++ "\n"
  }
  total_string
}



fun show_head(tmcmc_result : list<(list<double>,double)>) : string {
  match(last(tmcmc_result)) {
    Nothing -> ""
    Just((_,a)) -> show-fixed(a, 1)
  }
}

fun list_to_csv(xs : list<double>) : string {
  var total_string := ""
  for(0, xs.length - 2) fn(i) {
    val str = match(xs[i]) {
      Nothing -> ""
      Just(x) -> show-fixed(x, 1) ++ ","
    }
    total_string := total_string ++ str
  }

  val str = match(xs[xs.length - 1]) {
    Nothing -> ""
    Just(x) -> show-fixed(x, 1)
  }
  total_string := total_string ++ str ++ "\n"

  total_string
}


fun show(hist : histogram<double>) : string {
  var total_string := ""
  for(0, hist.length - 1) fn(i) {
    val str = match(hist[i]) {
      Nothing -> ""
      Just(x) -> match(x) {
        (Exp(dbl), a) -> {show-fixed(exp(ddouble(dbl)), 1) ++ ", " ++ show-fixed(a, 1)}
      }
    }
    total_string := total_string ++ str ++ "\n"
  }
  total_string
}

fun show(hist : histogram<(double, double)>) : string {
  var total_string := ""
  for(0, hist.length - 1) fn(i) {
    val str = match(hist[i]) {
      Nothing -> ""
      Just(x) -> match(x) {
        (Exp(dbl), (db1, db2)) -> {show-fixed(exp(ddouble(dbl)), 1) ++ ", " ++ show-fixed(db1, 1) ++ ", " ++ show-fixed(db2, 1)}
      }
    }
    total_string := total_string ++ str ++ "\n"
  }
  total_string
}

fun show(hist : histogram<(list<double>)>) : string {
  var total_string := ""
  for(0, hist.length - 1) fn(i) {
    match(hist[i]) {
      Nothing -> {total_string := total_string ++ ""}
      Just(x) -> match(x) {
        (_, lst : list<double>) -> {
          for(0, lst.length - 2) fn(j) {
            val str = match(lst[j]) {
              Nothing -> ""
              Just(u) -> (show-fixed(u, 1) ++ ",")
            }
            total_string := total_string ++ str
          }

          val str = match(lst[lst.length - 1]) {
            Nothing -> ""
            Just(u) -> (show-fixed(u, 1))
          }
          total_string := total_string ++ str
        }
      }
    }

    total_string := total_string ++ "\n"
  }
  total_string
}

fun show( ls : (list<int>, list<int>) ) : string {
  match(ls) {
    (l1, l2) -> {show(l1) ++ show(l2)}
  }
}

fun show(xs : list<double>) : string {
  var total_string := "["
  for(0, xs.length - 1) fn(i) {

    if(i < xs.length - 1) {
      val str = match(xs[i]) {
        Nothing -> ""
        Just(x) -> show-fixed(x, 1) ++ ","
      }
      total_string := total_string ++ str
    } else {
      val str = match(xs[i]) {
        Nothing -> ""
        Just(x) -> show-fixed(x, 1)
      }
      total_string := total_string ++ str
    }
  }
  total_string := total_string ++ "]"
  total_string
}

fun show( x : list<list<double>> ) : string {
  join(map(x, show))
}

fun show( x : list<list<list<double>>> ) : string {
  join(map(x, show))
}

fun show(hist : histogram<(double -> double)>) : console int {
  for(0, hist.length - 1) fn(i) {
    val str = match(hist[i]) {
      Nothing -> ""
      Just(x) -> match(x) {
        (Exp(dbl), func) -> {"(" ++ show-fixed(exp(ddouble(dbl)), 1) ++ ", " ++ show-fixed(func(100.0), 1) ++ ")"}
      }
    }
    println(str)
  }
  0
}

fun example-plot() {
  plot( fn(x){ 2.0 * x } )
}

fun list-join(len : int, elem) {
  val xs = list(1,len,elem)
  "[" ++ xs.join(",") ++ "]"
}
