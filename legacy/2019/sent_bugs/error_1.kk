effect reader {
  fun ask() : int
}

effect evil {
  control evil(x:int, y:int, z:int) : ()
}

val reader-one = handler { fun ask() { 1 } }

// forall<a,e>. (() -> <evil/evil|e> (() -> e a)) -> e (() -> e a)
//forall<a,e>. (() -> <evil/evil|e> (() -> e a)) -> e (() -> e a)
val hevil = handler { 
  control evil(x, y, z) { (fun(){resume(())()}) } 
}

fun test() {
  val x = ask()
  evil(x, 2*x, 10*x) // Commenting out this line produces an error
  // Changing evil: int -> () to evil : () -> () produces _x6 error 
  // (zero argument specialization)
  (fun(){x})
}

fun non-scoped() : int {
  val f : () -> reader int
        = reader-one { hevil{ test() } } 
        
  reader-one{ f() }
}


fun main(){
    println(non-scoped())
}