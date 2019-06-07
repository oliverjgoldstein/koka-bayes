import std/os/readline

fun main() {
  println("DD")
  readline()
  /* readchar(tester) */
}

effect readchar {
  fun read() : char
  fun put(x : char) : ()
}

fun string-to-char (xs : list<char>) : char {
  match(xs) {
    Nil -> '\n'
    Cons(a,_) -> a
  }
}s

fun readchar(action) {
  var s := []
  handle(action) {
    return x -> x
    read() -> {
      match (s) {
        Nil -> {s := list(readline()); resume(string-to-char(s))}
        Cons(_, zs) -> {s := tail(s); resume(string-to-char(zs));}
      }}

    put(y : char) -> {print(y); resume(())}
  }
}

fun tester() {
  var c := read()
  while {c!='a'} {
    put(c)
    c := read()
  }
  put(c)
}

/* readchar(tester) */
