import test/ojg/bayes-handlers
import test/ojg/exp
import std/num/double
import std/os/file
import std/os/path
import std/num/ddouble

fun pop_map( f ){
  (fun(lista) {
    pop_map_helper(f, lista)
  })
}

fun pop_map_helper(f, t) {
    match(t) {
      Nil -> Nil
      Cons(x, xs) -> match(x) {
        (Exp(n), a) -> Cons((Exp(n), f(a)), pop_map_helper(f, xs))
      }
    }
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

fun write( hist : histogram<double> ) {
   write-text(path("./test/ojg/output.csv"), show(hist))
}

fun show(hist : histogram<double>) {
  var total_string := ""
  for(1, hist.length) fun(i) {
    val str = match(hist[i]) {
      Nothing -> ""
      Just(x) -> match(x) {
        (Exp(dbl), a) -> {show-fixed(exp(ddouble(dbl))) + ", " + show-fixed(a)}
      }
    }
    total_string := total_string + str
  }
  total_string := total_string + "\n"
  total_string
}

fun show(hist : histogram<(double, double)>) : string {
  var total_string := ""
  for(1, hist.length) fun(i) {
    val str = match(hist[i]) {
      Nothing -> ""
      Just(x) -> match(x) {
        (Exp(dbl), (db1, db2)) -> {show-fixed(exp(ddouble(dbl))) + ", (" + show-fixed(db1) + ", " + show-fixed(db2) + ")"}
      }
    }
    total_string := total_string + str
  }
  total_string := total_string + "\n"
  total_string
}

fun example-plot() {
  plot( fun(x){ 2.0 * x } )
}

fun list-join(len : int, elem) {
  val xs = list(1,len,elem)
  "[" + xs.join(",") + "]"
}
