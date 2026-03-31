effect reader {
  fun ask() : int
}

effect evil {
  control evil(x:int) : ()
}

val reader-one = handler { fun ask() { 1 } }

// forall<a,e>. (() -> <evil/evil|e> (() -> e a)) -> e (() -> e a)
//forall<a,e>. (() -> <evil/evil|e> (() -> e a)) -> e (() -> e a)
val hevil = handler { 
  fun evil(x) { () } 
}

fun test() {
  val x = ask()
  evil(x) // Commenting out this line produces an error
  // Changing evil: int -> () to evil : () -> () produces _x6 error 
  // (zero argument specialization)
  x
}

fun non-scoped() : evil int {
  val f : () -> <evil, reader> int
        = reader-one{ 
            hevil{ test } 
        }
  reader-one{ f() }
}


fun main(){
    println(
        hevil(non-scoped)
    )
}