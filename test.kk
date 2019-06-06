import std/os/readline
/* import std/async */
/* import readline */


/* alias readchar = <asyncx,console> */
/* alias putchar = <div,exn> */

/* fun main() : readchar string { // <async,exn,ndet>
   var x := readline()
   /* putchar(x) */
   x
} */

fun identity(s : string) {
  var f := s.map(fun(c : char) {
    c
    });
  println(f : string)
}

effect input {
  fun putchar(x : string) : string
  /* fun readchar() : readchar */
}

val putchar_handler = handler {
  return x -> x
  putchar(x : string) -> resume(x)
  /* readchar() -> readchar */
}

/* TAKES EVERYTHING THAT IS NOT getstr and just does the same thing. */
/* but for getstr it simply resumes afterwards with a "there". */

fun hello() {
  val char_read = putchar("Stri")
  println(char_read)
}



// readchar takes a file and a number of characters to read and prints that out.
// Readchar = getchar which gets a character from standard input;
// Putchar writes a series of characters to standard output.












effect amb {
  fun flip() : int
}

fun and() : amb int {
  val a = flip()
  val b = flip()
  val c = flip()
  val d = flip()
  val e = flip()
  val f = flip()
  val g = flip()
  val h = flip()
  (a + b + c + d + e + f + g + h)
}

/* val coinflip = handler {
  flip() -> resume(random-bool())
} */

val amb = handler {
  return x -> [x]
  flip() -> resume(1) + resume(2)
}


effect state<s> {
  fun get() : s
  fun put( x : s ) : ()
}

fun test() : state<int> int {
  val i = get()
  val j = 5
  /* println(j) */
  put(j);
  val k = get()
  5
  /* println(k : string) */
}

fun counter() {
val i = get()
if (i <= 0) then () else {
println("hi")
put(i - 1);
counter()
}
}

/* Question 1:  Why is the state handler not working? */
/* Question 2:  How to pattern match on the maybe monad? */

val state = handler(s) {
  return x -> (x,s)
  get() -> resume(s,s)
  put(s') -> resume(s',())
}

/* state(2,counter) */


/* effect yield<a> {
  yield( item : a ) : ()
} */





effect exc {
  fun raise (s : string) : a
}

fun test2() {
  raise("ERROR")
  6
}

val to-maybe = handler {
  return x -> Just(x)
  raise(_s) -> Nothing
}

fun show (mi : maybe<int>) : string {
  match(mi) {
    Just(x : int) -> x.char.string
    Nothing -> "Nothing"
  }
}






/* effect async {
  fun readline() : string
}
val outer-async = handler {
  readline() -> prim-readline( resume )
}

fun ask-age() {
  println("what is your name?")
  val name = readline() // asynchronous!
  println("hello " + name)
} */



/* putChar c writes the character c to
the screen, and returns no result value:
putChar :: Char → IO ()

c:
getchar:
reads character from standard input and casts it to an unsigned int and returns it.

putchar: takes an unsigned integer and pushes it to standard output. returns the character too.

getChar reads a character from the
keyboard, echoes it to the screen, and returns
the character as its result value:
getChar :: IO Char

main()
{
  int c;
  while((c=getchar()) != EOF) {
    putchar(c);
  }
} */
















//
