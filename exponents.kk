import std/num/double
import std/num/ddouble
import effects-and-types


fun ln(Exp(xe) : exp) : double {
  xe
}

fun e(x : double) {
  Exp(x)
}

fun (>=)( Exp(xe) : exp, Exp(ye) : exp ) : bool { xe >= ye }

fun double-to-exp( d : double ) : exp {
  Exp(log(d))
}

val zero-exp = 0.0.double-to-exp

fun exp_to_double(Exp(x) : exp) : double {
  exp(x)  
} 

fun mult_exp(Exp(xe) : exp, Exp(ye) : exp) : exp {
  Exp(xe + ye)  
}

fun div_exp(Exp(xe) : exp, Exp(ye) : exp) : exp {
  Exp(xe - ye)
}

fun plus_exp(Exp(xe) : exp, Exp(ye) : exp) {
  fun ln_plus (a : double, b : double) {
      (a + log1p(exp(b - a)))
  }
  if (xe < ye) then {
    Exp(ln_plus(ye, xe))
  } else {
    Exp(ln_plus(xe, ye))
  }
}


fun show(x : exp) : string {
  match(x) {
    Exp(h) -> "Exp " ++ show(h) ++ " with probability: " ++ show-fixed(pow(dd-e,ddouble(h)))
  }
}
