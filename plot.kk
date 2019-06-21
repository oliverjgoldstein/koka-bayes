import test/ojg/bayes-handlers
import test/ojg/exp
import std/num/double

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

fun example-plot() {
  plot( fun(x){ 2.0 * x } )
}

fun list-join(len : int, elem) {
  val xs = list(1,len,elem)
  "[" + xs.join(",") + "]"
}

/* fun plot_reg() {
  for(1, 100) fun(i) {
    with random_sampler
    val f = homogeneous_linear()
    println(plot(f))
  }
} */
