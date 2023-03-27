public module recursive-error

/*
Name resulution seems wrong when using recursive overloaded functions
overloading print and using print in it always tries to resolve to the defining print (not the globally available)
*/

fun println(x: (int, int)){
    println(x.fst) // Changing this to print works
}

fun main(){
    println((1,2))
}