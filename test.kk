import std/os/readline

effect readchar<s> {
  fun read() : s
  fun put(x : s) : ()
}

val readchar = handler {
  return x = x
  read() -> resume(readline())
  put(x) -> resume(println(x))
}

val doubler = handler {
  return x = x
  read() -> resume(join(map(list(readline()), doubler-func)))
  put(x) -> resume(println(x : string))
}

val reverser = handler {
  return x = x
  read() -> resume(string(reverse(list(readline()))))
  put(x) -> resume(println(x : string))
}

val repeater = handler {
  return x = x
  read() -> resume(string-doubler(readline()))
  put(x) -> resume(println(x : string))
}


fun doubler-func(x : char) : string {
  return string([x,x])
}

fun string-doubler(x : string) : string {
  return (x + "\n" + x)
}

fun tester() {
  var c := read()
  while {c!="nnnn"} {
    put(c)
    c := read()
  }
  put(c)
}

/* readchar(tester) */
