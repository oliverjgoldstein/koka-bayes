fun loop(i : int, pop_hist : histogram<(int) -> <yield,score,div,sample|e> a>, step_num : int, step_size : int, default : (exp, int -> <yield,score,div,sample|e> a), tc_default : <div,sample|e> histogram<a>) : <div,sample|e> histogram<a> {
  var second_term := pop_hist
  var x := tc_default
  for(i, step_num) fun(i) {
      if (i < step_num) then {
        val resampled_histogram = resample(pop_hist, default)
        fun smc_func_2(wm) {
          match(wm) {
            (w,m) -> {
              weighted(w) {
                advance {
                  m(step_size)
                }
              }
            }
          }
        }

        second_term := map(resampled_histogram, smc_func_2)
      } else {

        val pop_func = fun(wm) {
          match(wm) {
            (w,m) -> {
              weighted(w) {
                finalize{
                  m(0)
                }
              }
            }
          }
        }

        tc_default := map(second_term, pop_func)
      }
   }
   tc_default
}
