import std/os/readline
import std/async


alias readchar = <asyncx,console>
/* alias putchar = <div,exn> */

fun main() : readchar string { // <async,exn,ndet>
   var x := readline()
   /* putchar(x) */
   x
}

fun putchar(s : string) {
  var f := s.map(fun(c : char) {
    c
    });
  println(f : string)
}

/*
effect readchar {
  fun flip() : bool
} */

// readchar takes a file and a number of characters to read and prints that out.
// Readchar = getchar which gets a character from standard input;
// Putchar writes a series of characters to standard output.
