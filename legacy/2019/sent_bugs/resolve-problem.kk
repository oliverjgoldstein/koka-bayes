public module resolve-problem

import model-using-effect

// import std/num/ddouble // Commenting this line out hides
// (<) : ddouble -> ddouble -> bool and produces an error

fun not-handling(a: number, b: number){
     a < b
}

// Exposing local effect
/*********
The infered return value is local int
fun local_effect(some_var: int): (() -> int){
  (fun(){
    var x := 1
    1
  })
}

Changing this to first assign function to named value
doesn't expose the local effect

*/


fun local_effect(some_var: int): (() -> int){
  fun g(){
    var x := 1
    1
  }
  g
}