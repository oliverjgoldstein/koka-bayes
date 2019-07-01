import std/num/double

alias model<a>        = () -> <sample, score> a
alias regression      = model<double -> double>
alias sequential_data = list<list<double>>
alias data_1d         = list<double>
alias two_d_data      = list<(double, double)>
alias trace_values    = list<double>
alias model_trace<a>  = (trace_values, a)
alias histogram<a>    = list<(exp, a)>
alias histofunc<a,b>  = histogram<a> -> histogram<b>

type exp {
  Exp(i : double)
}

effect yield {
  control yield() : ()
}

ambient fun sample() : double
ambient control score( s : exp ) : ()

effect exc {
  fun raise(s : string ) : a
}

type trace<a> {
  Trace(m : model<a>, l : model_trace<a>)
}


fun trace_dist(tr : trace<_a>) : list<double> {
  match(tr) {
    Trace(_, (d, _)) -> d
  }
}

fun trace_model(tr : trace<_a>) {
  match(tr) {
    Trace(m, _) -> m
  }
}

fun trace_a(tr : trace<_a>) {
  match(tr) {
    Trace(_, (_, a)) -> a
  }
}
