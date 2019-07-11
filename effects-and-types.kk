public module effects-and-types

import std/num/double

alias model<a,e>      = () -> <sample, score|e> a
alias nmodel<a>       = () -> <sample, score> a
alias regression      = nmodel<double -> double>
alias data_1d         = list<double>
alias two_d_data      = list<(double, double)>
alias trace_values    = list<double>
alias histogram<a>    = list<(exp, a)>
alias row_vector      = list<double>

type exp {
  Exp(i : double)
}

effect yield {
  control yield() : ()
}

ambient fun sample() : double
ambient control score( s : exp ) : ()

