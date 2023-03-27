#pragma once
#ifndef kk_pmmh_H
#define kk_pmmh_H
// Koka generated module: "pmmh", koka version: 2.1.2
#include <kklib.h>
#include "std_core_types.h"
#include "std_core_hnd.h"
#include "std_core.h"
#include "std_num_random.h"
#include "effects_dash_and_dash_types.h"
#include "handlers.h"
#include "sampling.h"
#include "sequential.h"
#include "trace.h"

// type declarations

// value declarations

kk_box_t kk_pmmh__mlift117_new__model(kk_box_t params, kk_unit_t wild__, kk_context_t* _ctx); /* forall<e,a> (params : a, wild_ : ()) -> <effects-and-types/score,div,exn,std/num/random/random,ndet,effects-and-types/sample|e> a */ 

kk_box_t kk_pmmh__mlift118_new__model(kk_box_t params, kk_std_core__list smc__hist, kk_context_t* _ctx); /* forall<e,a,b> (params : b, smc_hist : effects-and-types/histogram<a>) -> <pure,std/num/random/random,effects-and-types/score,ndet,effects-and-types/sample|e> b */ 

kk_box_t kk_pmmh__mlift119_new__model(kk_function_t main__model, kk_integer_t particle__num, kk_integer_t step__num, kk_box_t params, kk_context_t* _ctx); /* forall<e,a,b> (main_model : (b) -> effects-and-types/model<a,<div,exn,std/num/random/random,effects-and-types/yield,effects-and-types/score,ndet,effects-and-types/sample|e>>, particle_num : int, step_num : int, params : b) -> <effects-and-types/sample,effects-and-types/score,pure,ndet,std/num/random/random|e> b */ 

kk_function_t kk_pmmh_new__model(kk_function_t param__model, kk_function_t main__model, kk_integer_t particle__num, kk_integer_t step__num, kk_context_t* _ctx); /* forall<a,b,e> (param_model : effects-and-types/model<a,<pure,ndet,std/num/random/random|e>>, main_model : (a) -> effects-and-types/model<b,<div,exn,std/num/random/random,effects-and-types/yield,effects-and-types/score,ndet,effects-and-types/sample|e>>, particle_num : int, step_num : int) -> effects-and-types/model<a,<pure,ndet,std/num/random/random|e>> */ 

static inline kk_std_core_types__tuple2_ kk_pmmh_pmmh(kk_function_t param__model, kk_function_t main__model, kk_context_t* _ctx) { /* forall<a,b,e> (param_model : effects-and-types/model<a,<pure,ndet,std/num/random/random|e>>, main_model : (a) -> effects-and-types/model<b,<div,exn,std/num/random/random,effects-and-types/yield,effects-and-types/score,ndet,effects-and-types/sample|e>>) -> <pure,ndet,std/num/random/random,effects-and-types/sample|e> (list<(list<double>, a)>, trace/trace<a,<effects-and-types/sample,effects-and-types/score,div,exn,ndet,std/num/random/random|e>>) */ 
  kk_function_t pmmh__model;
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*std/core/hnd/evv<(<>)>*/;
  kk_function_t x = kk_pmmh_new__model(param__model, main__model, kk_integer_from_small(10), kk_integer_from_small(10), _ctx); /*effects-and-types/model<85,<pure,ndet,std/num/random/random|87>>*/;
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  pmmh__model = x; /*effects-and-types/model<85,<pure,ndet,std/num/random/random|87>>*/
  kk_effects_dash_and_dash_types__exp _x308 = kk_effects_dash_and_dash_types__new_Exp(0x0p+0, _ctx); /*effects-and-types/exp*/
  return kk_trace_tmcmc(pmmh__model, kk_integer_from_small(10), _x308, kk_integer_from_small(0), _ctx);
}

void kk_pmmh__init(kk_context_t* _ctx);

#endif // header
