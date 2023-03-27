#pragma once
#ifndef kk_bug_dash_test4_H
#define kk_bug_dash_test4_H
// Koka generated module: "bug-test4", koka version: 2.1.3
#include <kklib.h>
#include "std_core_types.h"
#include "std_core_hnd.h"
#include "std_core.h"
#include "std_num_random.h"
#include "effects_dash_and_dash_types.h"
#include "handlers.h"

// type declarations

// value declarations

static inline kk_box_t kk_bug_dash_test4_x(kk_function_t comp, kk_context_t* _ctx) { /* forall<a,e> (comp : () -> e a) -> e a */ 
  return kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), comp, (comp, _ctx));
}

kk_std_core__list kk_bug_dash_test4_rmsmc__loop(kk_integer_t a, kk_integer_t composition__1, kk_integer_t i, kk_integer_t smc__step__num, kk_integer_t mh__step__num, kk_integer_t step__size, bool normalize, kk_context_t* _ctx); /* forall<a> (a : int, composition_1 : int, i : int, smc_step_num : int, mh_step_num : int, step_size : int, normalize : bool) -> <pure,effects-and-types/sample> effects-and-types/histogram_rmsmc<a> */ 

kk_function_t kk_bug_dash_test4__mlift178_rmsmc(kk_function_t model, kk_std_core__list wild__, kk_context_t* _ctx); /* forall<a,_b,e> (model : () -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random|e> a, wild_ : effects-and-types/histogram_rmsmc<_b>) -> <div,exn,effects-and-types/sample,effects-and-types/score,std/num/random/random|e> ((a : int) -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random|e> a) */ 

kk_function_t kk_bug_dash_test4_rmsmc(kk_integer_t particle__num, kk_integer_t smc__step__num, kk_integer_t mh__step__num, kk_integer_t step__size, kk_function_t model, bool normalize, kk_context_t* _ctx); /* forall<a,e> (particle_num : int, smc_step_num : int, mh_step_num : int, step_size : int, model : () -> <pure,std/num/random/random,effects-and-types/sample,effects-and-types/score,effects-and-types/yield|e> a, normalize : bool) -> <pure,std/num/random/random,effects-and-types/score|e> ((a : int) -> <pure,std/num/random/random,effects-and-types/sample,effects-and-types/score,effects-and-types/yield|e> a) */ 

void kk_bug_dash_test4__init(kk_context_t* _ctx);

#endif // header
