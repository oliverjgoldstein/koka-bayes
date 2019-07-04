
import std/num/double


/* ambient fun arb() : double

fun handler_test(action) {

  var array := [1.0,2.0]

  handle(action) {
    return x -> x
    arb() -> {
      val x : maybe<double> = array[0]
      resume(4.0)
    }
  }
}


fun arb(arbitrary : list<(int) -> e a>) {

  var i := 0
  fun func(parameter) {
    parameter(0)
  }

  var temp := map(arbitrary, func)
  5
}

fun arb(arbitrary : list<(int) -> <e> a>) {

  var i := 0
  fun func(parameter) {
    parameter(0)
  }

  var temp := map(arbitrary, func)
  5
}

ambient fun foo() : ()

fun bar(i : int) {
  foo()
  bar((i + 1))
} */


















///













/* import std/num/ddouble

fun show(arb : int) {
  "G"
}

fun show( ls : list<int> ) : string {
  show(ls)
} */






type whatever<a> {
  Whatever(a : a)
}


fun arb(vale : whatever<_a>) : whatever<_a> {
  match(vale) {
    Whatever(a) -> {
      Whatever(a)
    }
  }
}

fun arb2(cool : whatever<a>) : div whatever<a>  {
  var main_val := cool
  for(1, 10) fun(i) {
    main_val := arb(main_val)
  }

  main_val
}
