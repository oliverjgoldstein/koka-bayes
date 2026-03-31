effect reader {
  fun ask() : int
}

effect evil {
  control evil(a: int) : int
}

val reader-one = handler { fun ask() { 100 } }

// forall<a,e>. (() -> <evil/evil|e> (() -> e a)) -> e (() -> e a)
//forall<a,e>. (() -> <evil/evil|e> (() -> e a)) -> e (() -> e a)
val hevil = handler { 
  control evil(a) { (fun(){ resume(a*20)() } ) } 
}

fun test() {
  val x = ask()
  val c = evil(2) // Commenting out this line produces an error
  (fun(){ x + c })
}

fun non-scoped() : int {
  val f : () -> reader int
        = reader-one{ 
            hevil{ test() } 
        }
  reader-one{ f() }
}


fun main(){
    println(non-scoped())
}