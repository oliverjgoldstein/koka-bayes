ambient control abort() : a

// Function that recurses `n` times and then calls `abort`
fun deep( n : int ) {
  if (n <= 0) then abort() else deep(n - 1)
}

// Handle abort.
fun example1() {
  with control abort() { 42 }   // on abort, return 42
  /* var s := deep(10)                  // large `n` works too */
  /* abort() */
  13                            // we never get here
}

// abort, catch it, and re-throw it
/* fun example2() {
  with control abort() { 42 }
  with control abort() { abort(); 13 }  // this abort goes to the outer handler
  val x = 2
  abort()
  val y = 3
  x+y
} */

fun main() {
  example1().println
  /* example2().println */
}
