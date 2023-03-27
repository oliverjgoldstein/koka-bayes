#pragma once
#ifndef kk_exponents_H
#define kk_exponents_H
// Koka generated module: "exponents", koka version: 2.1.3
#include <kklib.h>
#include "std_core_types.h"
#include "std_core.h"
#include "std_num_double.h"
#include "std_num_ddouble.h"
#include "effects_dash_and_dash_types.h"

// type declarations

// value declarations

static inline kk_effects_dash_and_dash_types__exp kk_exponents_div__exp(kk_effects_dash_and_dash_types__exp _pat__30__13, kk_effects_dash_and_dash_types__exp _pat__30__28, kk_context_t* _ctx) { /* (effects-and-types/exp, effects-and-types/exp) -> effects-and-types/exp */ 
  double xe = _pat__30__13.i;
  double ye = _pat__30__28.i;
  double _x673 = (xe - ye); /*double*/
  return kk_effects_dash_and_dash_types__new_Exp(_x673, _ctx);
}

static inline kk_effects_dash_and_dash_types__exp kk_exponents_double_to_exp(double d, kk_context_t* _ctx) { /* (d : double) -> effects-and-types/exp */ 
  double _x674 = log(d); /*double*/
  return kk_effects_dash_and_dash_types__new_Exp(_x674, _ctx);
}

static inline kk_effects_dash_and_dash_types__exp kk_exponents_e(double x, kk_context_t* _ctx) { /* (x : double) -> effects-and-types/exp */ 
  return kk_effects_dash_and_dash_types__new_Exp(x, _ctx);
}

static inline double kk_exponents_exp__to__double(kk_effects_dash_and_dash_types__exp _pat__22__19, kk_context_t* _ctx) { /* (effects-and-types/exp) -> double */ 
  double _x675;
  double x = _pat__22__19.i;
  _x675 = x; /*double*/
  return exp(_x675);
}

static inline double kk_exponents_ln(kk_effects_dash_and_dash_types__exp _pat__6__8, kk_context_t* _ctx) { /* (effects-and-types/exp) -> double */ 
  double xe = _pat__6__8.i;
  return xe;
}

static inline kk_effects_dash_and_dash_types__exp kk_exponents_mult__exp(kk_effects_dash_and_dash_types__exp _pat__26__14, kk_effects_dash_and_dash_types__exp _pat__26__29, kk_context_t* _ctx) { /* (effects-and-types/exp, effects-and-types/exp) -> effects-and-types/exp */ 
  double xe = _pat__26__14.i;
  double ye = _pat__26__29.i;
  double _x676 = (xe + ye); /*double*/
  return kk_effects_dash_and_dash_types__new_Exp(_x676, _ctx);
}

kk_effects_dash_and_dash_types__exp kk_exponents_plus__exp(kk_effects_dash_and_dash_types__exp _pat__34__14, kk_effects_dash_and_dash_types__exp _pat__34__29, kk_context_t* _ctx); /* (effects-and-types/exp, effects-and-types/exp) -> effects-and-types/exp */ 

static inline bool kk_exponents__lp__gt__eq__rp_(kk_effects_dash_and_dash_types__exp _pat__14__11, kk_effects_dash_and_dash_types__exp _pat__14__26, kk_context_t* _ctx) { /* (effects-and-types/exp, effects-and-types/exp) -> bool */ 
  double xe = _pat__14__11.i;
  double ye = _pat__14__26.i;
  return (xe >= ye);
}

kk_string_t kk_exponents_show(kk_effects_dash_and_dash_types__exp x, kk_context_t* _ctx); /* (x : effects-and-types/exp) -> string */ 

extern kk_effects_dash_and_dash_types__exp kk_exponents_zero_exp;

void kk_exponents__init(kk_context_t* _ctx);

#endif // header
