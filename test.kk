import std/os/readline

fun main() {
  println("DD")
  /* readchar(tester) */
}

effect readchar {
  fun read() : char
  fun put(x : char) : ()
}

fun string-to-char (xs : list<char>) : char {
  match(xs) {
    Nil -> 'n'
    Cons(a,_) -> a
  }
}

/* val readchar = handler {
  return x -> x
  read() -> resume(readline())
  put(x) -> resume(println(x))
} */

fun readchar(buffer, action) {
  var s := buffer
  handle(action) {
    return x -> x
    read() -> {s := readline(); resume(string-to-char(list(s.head))); s := s.tail;} // If the buffer is full don't readline
    put(y : char) -> {println(y); resume(())}
  }
}

/* var read = handler {

} */

/* val doubler = handler {
  return x -> x
  read() -> resume(join(map(list(readline()), doubler-func)))
  put(x) -> resume(println(x : string))
}

/* readchar type char instead of s */

val reverser = handler {
  return x -> x
  read() -> resume(string(reverse(list(readline()))))
  put(x) -> resume(println(x : string))
}

val repeater = handler {
  return x -> x
  read() -> resume(string-doubler(readline()))
  put(x) -> resume(println(x : string))
}


fun doubler-func(x : char) : string {
  return string([x,x])
}

fun string-doubler(x : string) : string {
  return (x + "\n" + x)
} */

fun tester() {
  var c := read()
  while {c!='a'} {
    put(c)
    c := read()
  }
  put(c)
}

/* readchar(tester) */
