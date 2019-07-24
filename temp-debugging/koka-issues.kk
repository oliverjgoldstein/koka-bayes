
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


///////////////////////////










import std/num/double
import std/os/path
import std/os/file

fun main() {
  pre_process_data()
  pre_process_data2()
}

fun pre_process_data() {
  val values  = read-text(path("./double_values.txt"))
  val nums = map(split(values, "\n"), parse-double)
  println(nums.length)
  string_to_list_doubles(values)
}

fun string_to_list_doubles( s : string )  {
  val nums = map(split(s, "\n"), parse-double)
  println(nums.length)
  match(nums[50]) {
    Nothing -> " "
    Just(x) -> match(x) {
      Nothing -> " "
      Just(v) -> show-fixed(v)
    }
  }
}
///

ambient fun sample() : double

fun gamrand(alpha : double) {
  if(alpha>1.0) {

    var flag := True
    while {flag} {
      flag := True
    }

    0.0
  }
  else {
    val x = gamrand(alpha);
    return sample()
  }
}









//








fun gamrand(alpha : double, lambda : double) {
  if(alpha>1.0) {
    val d = alpha - 1.0/3.0
    val c = 1.0/sqrt(9.0*d)

    fun compute(flag, v) {
      val zz = normal(0.0,1.0)
      val new_v = (1.0 + c * zz)^3.0
      if(flag) {
        if (log(sample()) > (0.5 * zz^(2.0) + d - d * new_v + d * log(new_v))) {
          compute(True, new_v)
        } else {
          compute(False, new_v)
        }
      } else {
        return new_v
      }
    }

    return d * compute(True, 0.0) / lambda
  }
  else {
    val x = gamrand(alpha+1.0,lambda);
    return x * sample()^(1.0/alpha);
  }
}


//



Issue of model polymorphism
Nondeterministic compiler error.





//







fun compute(flag, v, c, d) {
  val zz = ref(normal(0.0,1.0))
  val new_v = (1.0 + c * !zz)^3.0
  if(flag) {
    if (log(sample()) > (0.5 * !zz^(2.0) + d - d * new_v + d * log(new_v))) {
      compute(True, new_v, c, d)
    } else {
      compute(False, new_v, c, d)
    }
  } else {
    return new_v
  }
}


fun gamrand(alpha : double, lambda : double) {
  if(alpha>1.0) {
    val d = alpha - 1.0/3.0
    val c = 1.0/sqrt(9.0*d)

    return d * compute(True, 0.0, c, d) / lambda
  }
  else {
    val x = gamrand(alpha+1.0,lambda);
    return x * sample()^(1.0/alpha);
  }
}
