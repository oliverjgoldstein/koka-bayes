public module output-and-plot

import std/num/double
import std/os/file
import std/os/path
import std/num/ddouble

import effects-and-types
import exponents

fun write( trace : list<(list<double>,double)>, filename : string ) {
    write-text(path("./output/" + filename), show(trace))
}

fun write( trace : list<(list<double>,list<double>)>, filename : string ) {
    write-text(path("./output/" + filename), show(trace))
}

fun write( hist : histogram<double>, filename : string ) {
   write-text(path("./output/" + filename), show(hist))
}

fun write( hist : histogram<(double, double)> , filename : string ) {
   write-text(path("./output/" + filename), show(hist))
}

fun write( hist : histogram<(list<double>)> , filename : string ) {
   write-text(path("./output/" + filename), show(hist))
}

fun write-awk( trace_vals : list<list<(list<double>, list<double>)>>, filename : string ) {
  val filenames = gen-filenames(filename)
  for(0, trace_vals.length - 1) fun(i) {
    match(trace_vals[i]) {
      Nothing -> error("No list!")
      Just(lst_lst) -> {
        match(filenames[i]) {
          Nothing -> error("No filename!")
          Just(fname) -> {
            write-text(path("./output/" + fname), showspecial(lst_lst))
          }
        }
      }
    }
  }
}

fun gen-filenames(filename : string) : list<string> {
  /* [filename + "_1.csv", filename + "_2.csv", filename + "_7.csv", filename + "_8.csv", */
   /* filename + "_9.csv",  */
   [filename + "_10.csv", filename + "_11.csv", filename + "_12.csv", filename + "_13.csv", filename + "_14.csv"]
   /* [filename + "_15.csv", filename + "_16.csv"] */
}

fun showspecial(tmcmc_result : list<(list<double>, list<double>)> ) : string {
  var total_string := ""
  for(0, tmcmc_result.length - 1) fun(i) {
    val str = match(tmcmc_result[i]) {
      Nothing -> "EMPTY"
      Just((_,a)) -> list_to_csv(a)
    }
    total_string := total_string + str
  }
  total_string
}


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
// These both ignore the trace of the results.
fun show(tmcmc_result : list<(list<double>,double)>) : string {
  var total_string := ""
  for(0, tmcmc_result.length - 1) fun(i) {
    val str = match(tmcmc_result[i]) {
      Nothing -> ""
      Just((_,a)) -> show-fixed(a)
    }
    total_string := total_string + str + "\n"
  }
  total_string
}

fun show(tmcmc_result : list<(list<double>,list<double>)>) : string {
  var total_string := ""
  for(0, tmcmc_result.length - 1) fun(i) {
    val str = match(tmcmc_result[i]) {
      Nothing -> ""
      Just((_,a)) -> list_to_csv(a)
    }
    total_string := total_string + str
  }
  total_string
}

fun show_head(tmcmc_result : list<(list<double>,double)>) : string {
  match(last(tmcmc_result)) {
    Nothing -> ""
    Just((_,a)) -> show-fixed(a)
  }
}

fun list_to_csv(xs : list<double>) : string {
  var total_string := ""
  for(0, xs.length - 2) fun(i) {
    val str = match(xs[i]) {
      Nothing -> ""
      Just(x) -> show-fixed(x) + ","
    }
    total_string := total_string + str
  }

  val str = match(xs[xs.length - 1]) {
    Nothing -> ""
    Just(x) -> show-fixed(x)
  }
  total_string := total_string + str + "\n"

  total_string
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
        (Exp(dbl), (db1, db2)) -> {show-fixed(exp(ddouble(dbl))) + ", " + show-fixed(db1) + ", " + show-fixed(db2)}
      }
    }
    total_string := total_string + str + "\n"
  }
  total_string
}

fun show(hist : histogram<(list<double>)>) : string {
  var total_string := ""
  for(0, hist.length - 1) fun(i) {
    match(hist[i]) {
      Nothing -> {total_string := total_string + ""}
      Just(x) -> match(x) {
        (_, lst : list<double>) -> {
          for(0, lst.length - 2) fun(j) {
            val str = match(lst[j]) {
              Nothing -> ""
              Just(u) -> (show-fixed(u) + ",")
            }
            total_string := total_string + str
          }

          val str = match(lst[lst.length - 1]) {
            Nothing -> ""
            Just(u) -> (show-fixed(u))
          }
          total_string := total_string + str
        }
      }
    }

    total_string := total_string + "\n"
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

fun show( x : list<list<double>> ) : string {
  join(map(x, show))
}

fun show( x : list<list<list<double>>> ) : string {
  join(map(x, show))
}

fun show(hist : histogram<(double -> double)>) : console int {
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
