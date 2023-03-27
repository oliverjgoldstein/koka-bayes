// Koka generated module: "exponents", koka version: 2.1.3
#include "exponents.h"


// lift anonymous function
struct kk_exponents_plus__exp_fun677__t {
  struct kk_function_s _base;
};
static double kk_exponents_plus__exp_fun677(kk_function_t _fself, double a, double b, kk_context_t* _ctx);
static kk_function_t kk_exponents_new_plus__exp_fun677(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_exponents_plus__exp_fun677, _ctx)
  return kk_function_dup(_fself);
}

static double kk_exponents_plus__exp_fun677(kk_function_t _fself, double a, double b, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x678;
  double _x679;
  double _x680 = (b - a); /*double*/
  _x679 = exp(_x680); /*double*/
  _x678 = log1p(_x679); /*double*/
  return (a + _x678);
}

kk_effects_dash_and_dash_types__exp kk_exponents_plus__exp(kk_effects_dash_and_dash_types__exp _pat__34__14, kk_effects_dash_and_dash_types__exp _pat__34__29, kk_context_t* _ctx) { /* (effects-and-types/exp, effects-and-types/exp) -> effects-and-types/exp */ 
  double xe = _pat__34__14.i;
  double ye = _pat__34__29.i;
  kk_function_t ln__plus = kk_exponents_new_plus__exp_fun677(_ctx); /*(a : double, b : double) -> double*/;
  kk_function_drop(ln__plus, _ctx);
  bool _match_672 = (xe < ye); /*bool*/;
  if (_match_672) {
    double _x681 = kk_function_call(double, (kk_function_t, double, double, kk_context_t*), ln__plus, (ln__plus, ye, xe, _ctx)); /*double*/
    return kk_effects_dash_and_dash_types__new_Exp(_x681, _ctx);
  }
  double _x682 = kk_function_call(double, (kk_function_t, double, double, kk_context_t*), ln__plus, (ln__plus, xe, ye, _ctx)); /*double*/
  return kk_effects_dash_and_dash_types__new_Exp(_x682, _ctx);
}

kk_string_t kk_exponents_show(kk_effects_dash_and_dash_types__exp x, kk_context_t* _ctx) { /* (x : effects-and-types/exp) -> string */ 
  double h = x.i;
  kk_string_t _x683;
  kk_define_string_literal(, _s684, 4, "Exp ")
  _x683 = kk_string_dup(_s684); /*string*/
  kk_string_t _x685;
  kk_string_t _x686 = kk_std_core_show_1(h, kk_std_core_types__new_None(_ctx), _ctx); /*string*/
  kk_string_t _x687;
  kk_string_t _x688;
  kk_define_string_literal(, _s689, 19, " with probability: ")
  _x688 = kk_string_dup(_s689); /*string*/
  kk_string_t _x690;
  kk_std_num_ddouble__ddouble _x691;
  kk_std_num_ddouble__ddouble _x692 = kk_std_num_ddouble__new_Ddouble(0x1.5bf0a8b145769p1, 0x1.4d57ee2b1013ap-53, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x693 = kk_std_num_ddouble_ddouble(h, _ctx); /*std/num/ddouble/ddouble*/
  _x691 = kk_std_num_ddouble_pow(_x692, _x693, _ctx); /*std/num/ddouble/ddouble*/
  _x690 = kk_std_num_ddouble_show_fixed(_x691, kk_std_core_types__new_None(_ctx), _ctx); /*string*/
  _x687 = kk_std_core__lp__plus__plus__1_rp_(_x688, _x690, _ctx); /*string*/
  _x685 = kk_std_core__lp__plus__plus__1_rp_(_x686, _x687, _ctx); /*string*/
  return kk_std_core__lp__plus__plus__1_rp_(_x683, _x685, _ctx);
}

kk_effects_dash_and_dash_types__exp kk_exponents_zero_exp;

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
  {
    double _x694 = log((0x0p+0)); /*double*/
    kk_exponents_zero_exp = kk_effects_dash_and_dash_types__new_Exp(_x694, _ctx); /*effects-and-types/exp*/
  }
}
