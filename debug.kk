
ambient fun arb() : double

fun handler_test(action) {

  var array := [1.0,2.0]

  handle(action) {
    return r -> r
    arb() -> {
      val x : maybe<double> = array[0]
      resume(4.0)
    }
  }
}
