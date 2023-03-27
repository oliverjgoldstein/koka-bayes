// Koka generated module: "interactive", koka version: 2.1.3
#include "interactive.h"


// lift anonymous function
struct kk_interactive__expr_fun17__t {
  struct kk_function_s _base;
};
static kk_integer_t kk_interactive__expr_fun17(kk_function_t _fself, kk_box_t _x116, kk_context_t* _ctx);
static kk_function_t kk_interactive__new_expr_fun17(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_interactive__expr_fun17, _ctx)
  return kk_function_dup(_fself);
}

static kk_integer_t kk_interactive__expr_fun17(kk_function_t _fself, kk_box_t _x116, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return kk_rmsmc_x(_x116, _ctx);
}

kk_function_t kk_interactive__expr(kk_context_t* _ctx) { /* forall<a> () -> ((comp : a) -> int) */ 
  return kk_interactive__new_expr_fun17(_ctx);
}

// initialization
void kk_interactive__init(kk_context_t* _ctx){
  static bool _initialized = false;
  if (_initialized) return;
  _initialized = true;
  kk_std_core_types__init(_ctx);
  kk_std_core__init(_ctx);
  kk_rmsmc__init(_ctx);
}
