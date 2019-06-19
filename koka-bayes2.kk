import test/ojg/exp
import std/num/double

alias rplus = exp
alias model<a>   = () -> <sample,score> a
alias regression = model<double -> double>

ambient fun sample() : double
ambient control score( s : rplus ) : ()

fun random-sampler(action : () -> <sample|e> a) : <ndet|e> a {
  with fun sample() { random() }
  mask<ndet>(action)  // mask out `ndet` from the `action` effect
}

val homogeneous-linear : regression = fun() {
  val a = normal(0.0,2.0)
  (fun(x){ a * x })
}

val linear : regression = fun() {
  val a = normal(0.0,2.0)
  val b = normal(0.0,2.0)
  (fun(x){ a * x + b })
}


fun box-muller(u1 :double, u2 :double) {
  sqrt(-2.0 * log(u1)) * cos(dbl-twopi * u2)
}

fun standard-normal() : <sample> double {
  box-muller(sample(),sample())
}

fun normal(mean, sdv ) {
  mean + standard-normal() * sdv
}
