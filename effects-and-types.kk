public module effects-and-types

import std/num/double
import std/num/random

alias model<a,e>         = () -> <sample, score|e> a
alias nmodel<a>          = () -> <sample, score, random> a
alias regression         = nmodel<double -> double>
alias data_1d            = list<double>
alias two_d_data         = list<(double, double)>
alias trace_values       = list<double>
alias histogram<a>       = list<(exp, a)>
alias row_vector         = list<double>
//////////////////// In Development:
alias histogram_rmsmc<a> = list<(trace_values, exp, a)>
alias advance_model<a,e> = (int) -> e a
////////////////////
type exp {
  Exp(i : double)
}

effect control yield() : ()

effect fun sample() : double
effect fun score( s : exp ) : ()
