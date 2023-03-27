// Koka generated module: "exponents", koka version: 2.1.2
#include "exponents.h"


// lift anonymous function
struct kk_exponents_plus__exp_fun557__t {
  struct kk_function_s _base;
};
static double kk_exponents_plus__exp_fun557(kk_function_t _fself, double a, double b, kk_context_t* _ctx);
static kk_function_t kk_exponents_new_plus__exp_fun557(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_exponents_plus__exp_fun557, _ctx)
  return kk_function_dup(_fself);
}

static double kk_exponents_plus__exp_fun557(kk_function_t _fself, double a, double b, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x558;
  double _x559;
  double _x560 = (b - a); /*double*/
  _x559 = pow((0x1.5bf0a8b145769p1),_x560); /*double*/
  _x558 = log1p(_x559); /*double*/
  return (a + _x558);
}

kk_effects_dash_and_dash_types__exp kk_exponents_plus__exp(kk_effects_dash_and_dash_types__exp x, kk_effects_dash_and_dash_types__exp y, kk_context_t* _ctx) { /* (x : effects-and-types/exp, y : effects-and-types/exp) -> effects-and-types/exp */ 
  kk_function_t ln__plus = kk_exponents_new_plus__exp_fun557(_ctx); /*(a : double, b : double) -> double*/;
  kk_function_drop(ln__plus, _ctx);
  double xe = x.i;
  double ye = y.i;
  bool _match_554 = (xe < ye); /*bool*/;
  if (_match_554) {
    double _x561 = kk_function_call(double, (kk_function_t, double, double, kk_context_t*), ln__plus, (ln__plus, ye, xe, _ctx)); /*double*/
    return kk_effects_dash_and_dash_types__new_Exp(_x561, _ctx);
  }
  double _x562 = kk_function_call(double, (kk_function_t, double, double, kk_context_t*), ln__plus, (ln__plus, xe, ye, _ctx)); /*double*/
  return kk_effects_dash_and_dash_types__new_Exp(_x562, _ctx);
}

kk_string_t kk_exponents_show(kk_effects_dash_and_dash_types__exp x, kk_context_t* _ctx) { /* (x : effects-and-types/exp) -> string */ 
  double h = x.i;
  kk_string_t _x563;
  kk_define_string_literal(, _s564, 4, "Exp ")
  _x563 = kk_string_dup(_s564); /*string*/
  kk_string_t _x565;
  kk_string_t _x566 = kk_std_core_show_1(h, kk_std_core_types__new_None(_ctx), _ctx); /*string*/
  kk_string_t _x567;
  kk_string_t _x568;
  kk_define_string_literal(, _s569, 19, " with probability: ")
  _x568 = kk_string_dup(_s569); /*string*/
  kk_string_t _x570;
  kk_std_num_ddouble__ddouble _x571;
  kk_std_num_ddouble__ddouble _x572 = kk_std_num_ddouble__new_Ddouble(0x1.5bf0a8b145769p1, 0x1.4d57ee2b1013ap-53, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x573 = kk_std_num_ddouble_ddouble(h, _ctx); /*std/num/ddouble/ddouble*/
  _x571 = kk_std_num_ddouble_pow(_x572, _x573, _ctx); /*std/num/ddouble/ddouble*/
  _x570 = kk_std_num_ddouble_show_fixed(_x571, kk_std_core_types__new_None(_ctx), _ctx); /*string*/
  _x567 = kk_std_core__lp__plus__plus__1_rp_(_x568, _x570, _ctx); /*string*/
  _x565 = kk_std_core__lp__plus__plus__1_rp_(_x566, _x567, _ctx); /*string*/
  return kk_std_core__lp__plus__plus__1_rp_(_x563, _x565, _ctx);
}

// initialization
void kk_exponents__init(kk_context_t* _ctx){
  static bool _initialized = false;
  if (_initialized) return;
  _initialized = true;
  kk_std_core_types__init(_ctx);
  kk_std_core__init(_ctx);
  kk_std_num_double__init(_ctx);
  kk_std_num_ddouble__init(_ctx);
  kk_effects_dash_and_dash_types__init(_ctx);
}
