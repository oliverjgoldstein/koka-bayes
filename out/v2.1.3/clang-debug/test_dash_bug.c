// Koka generated module: "test-bug", koka version: 2.1.3
#include "test_dash_bug.h"

kk_std_core__list kk_test_dash_bug_rmsmc__loop(kk_std_core__list _x140, kk_context_t* _ctx) { /* forall<a,e> (populated_hist : effects-and-types/histogram_rmsmc<(int) -> <exn,effects-and-types/yield,effects-and-types/score,effects-and-types/sample,effects-and-types/sample,div|e> a>) -> <div|e> effects-and-types/histogram_rmsmc<a> */ 
  kk__tailcall: ;
  { // tailcall
    goto kk__tailcall;
  }
}

// initialization
void kk_test_dash_bug__init(kk_context_t* _ctx){
  static bool _initialized = false;
  if (_initialized) return;
  _initialized = true;
  kk_std_core_types__init(_ctx);
  kk_std_core__init(_ctx);
  kk_effects_dash_and_dash_types__init(_ctx);
}
