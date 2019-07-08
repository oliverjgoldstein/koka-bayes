import std/num/ddouble

alias model<a>        = () -> <sample, score> a
alias regression      = model<ddouble -> ddouble>
alias sequential_data = list<list<ddouble>>
alias data_1d         = list<ddouble>
alias two_d_data      = list<(ddouble, ddouble)>
alias trace_values    = list<ddouble>
alias histogram<a>    = list<(exp, a)>
alias histofunc<a,b>  = histogram<a> -> histogram<b>
alias row_vector      = list<ddouble>

type exp {
  Exp(i : ddouble)
}

effect yield {
  control yield() : ()
}

ambient fun sample() : ddouble
ambient control score( s : exp ) : ()

effect exc {
  fun raise(s : string ) : a
}

type trace<a> {
  Trace(m : model<a>, p : exp, l : trace_values, a : a)
}


fun trace_v(tr : trace<_a>) : list<ddouble> {
  match(tr) {
    Trace(_, _, d, _) -> d
  }
}

fun trace_m(tr : trace<_a>) : model<_a> {
  match(tr) {
    Trace(m, _, _, _) -> m
  }
}

fun trace_p(tr : trace<_a>) : exp {
  match(tr) {
    Trace(_, p, _, _) -> p
  }
}

fun trace_a(tr : trace<_a>) : _a {
  match(tr) {
    Trace(_, _, _, a) -> a
  }
}
