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

fun tester() {
  var c := read()
  while {c!="newline"} {
    put(c)
    c := read()
  }
  put(c)
}

/* readchar(tester) */
