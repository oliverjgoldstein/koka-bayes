import std/os/readline

fun main() {
  println("DD")
  readline()
  /* toplevel(tester) */
}

effect toplevel {
  fun read() : char
  fun put(x : char) : ()
}

fun string-to-char (xs : list<char>) : char {
  match(xs) {
    Nil -> '\n'
    Cons(a,_) -> a
  }
}

fun string-to-char-last (xs : list<char>) : char {
  match(xs) {
    Nil -> '\n'
    Cons(y,Nil) -> y
    Cons(_,ys) -> {string-to-char-last(ys)}
  }
}

fun toplevel(action) {
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

fun doubler(action) {
  var s := []
  handle(action) {
    return x -> x
    read() -> {
      match (s) {
        Nil -> {s := list(readline()); resume(string-to-char(s))}
        Cons(_, zs) -> {s := tail(s); resume(string-to-char(zs));}
      }}

    put(y : char) -> {print(y); print(y); resume(())}
  }
}

fun reverser(action) {
  var s := []
  handle(action) {
    return x -> x
    read() -> {
      match (s) {
        Nil -> {s := list(readline()); resume(string-to-char-last(s))}
        Cons(_, _) -> {s := take(s, (s.length - 1)); resume(string-to-char-last(s));}
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
