#pragma once
#ifndef kk_exponents_H
#define kk_exponents_H
// Koka generated module: "exponents", koka version: 2.1.2
#include <kklib.h>
#include "std_core_types.h"
#include "std_core.h"
#include "std_num_double.h"
#include "std_num_ddouble.h"
#include "effects_dash_and_dash_types.h"

// type declarations

// value declarations

static inline kk_effects_dash_and_dash_types__exp kk_exponents_div__exp(kk_effects_dash_and_dash_types__exp x, kk_effects_dash_and_dash_types__exp y, kk_context_t* _ctx) { /* (x : effects-and-types/exp, y : effects-and-types/exp) -> effects-and-types/exp */ 
  double j = x.i;
  double t = y.i;
  double _x555 = (j - t); /*double*/
  return kk_effects_dash_and_dash_types__new_Exp(_x555, _ctx);
}

static inline kk_effects_dash_and_dash_types__exp kk_exponents_e(double x, kk_context_t* _ctx) { /* (x : double) -> effects-and-types/exp */ 
  return kk_effects_dash_and_dash_types__new_Exp(x, _ctx);
}

static inline double kk_exponents_exp__to__double(kk_effects_dash_and_dash_types__exp x, kk_context_t* _ctx) { /* (x : effects-and-types/exp) -> double */ 
  double j = x.i;
  return pow((0x1.5bf0a8b145769p1),j);
}

static inline double kk_exponents_ln(kk_effects_dash_and_dash_types__exp x, kk_context_t* _ctx) { /* (x : effects-and-types/exp) -> double */ 
  double g = x.i;
  return g;
}

static inline kk_effects_dash_and_dash_types__exp kk_exponents_mult__exp(kk_effects_dash_and_dash_types__exp x, kk_effects_dash_and_dash_types__exp y, kk_context_t* _ctx) { /* (x : effects-and-types/exp, y : effects-and-types/exp) -> effects-and-types/exp */ 
  double j = x.i;
  double t = y.i;
  double _x556 = (j + t); /*double*/
  return kk_effects_dash_and_dash_types__new_Exp(_x556, _ctx);
}

kk_effects_dash_and_dash_types__exp kk_exponents_plus__exp(kk_effects_dash_and_dash_types__exp x, kk_effects_dash_and_dash_types__exp y, kk_context_t* _ctx); /* (x : effects-and-types/exp, y : effects-and-types/exp) -> effects-and-types/exp */ 

kk_string_t kk_exponents_show(kk_effects_dash_and_dash_types__exp x, kk_context_t* _ctx); /* (x : effects-and-types/exp) -> string */ 

void kk_exponents__init(kk_context_t* _ctx);

#endif // header
