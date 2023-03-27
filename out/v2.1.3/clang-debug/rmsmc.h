#pragma once
#ifndef kk_rmsmc_H
#define kk_rmsmc_H
// Koka generated module: "rmsmc", koka version: 2.1.3
#include <kklib.h>
#include "std_core_types.h"
#include "std_core_hnd.h"
#include "std_core.h"
#include "std_num_random.h"
#include "effects_dash_and_dash_types.h"
#include "handlers.h"
#include "sampling_dash_rmsmc.h"

// type declarations

// value declarations

kk_std_core_types__tuple3_ kk_rmsmc__mlift665_rmsmc__loop(kk_std_core_types__tuple3_ _y_3, kk_context_t* _ctx); /* forall<a,e> ((effects-and-types/trace_values, effects-and-types/exp, (a : int) -> <effects-and-types/yield,effects-and-types/score,effects-and-types/sample,effects-and-types/sample,exn,div|e> a)) -> <effects-and-types/sample,exn,div|e> (effects-and-types/trace_values, effects-and-types/exp, (a : int) -> <effects-and-types/yield,effects-and-types/score,effects-and-types/sample,effects-and-types/sample,exn,div|e> a) */ 

kk_std_core__list kk_rmsmc__mlift666_rmsmc__loop(kk_integer_t composition__1, kk_integer_t i, kk_integer_t mh__step__num, bool normalize, kk_integer_t smc__step__num, kk_integer_t step__size, kk_std_core__list irrelevant, kk_context_t* _ctx); /* forall<a,e> (composition_1 : int, i : int, mh_step_num : int, normalize : bool, smc_step_num : int, step_size : int, irrelevant : list<(effects-and-types/trace_values, effects-and-types/exp, (a : int) -> <effects-and-types/yield,effects-and-types/score,effects-and-types/sample,effects-and-types/sample,exn,div|e> a)>) -> <effects-and-types/sample,exn,div|e> effects-and-types/histogram_rmsmc<a> */ 

kk_std_core__list kk_rmsmc_rmsmc__loop(kk_std_core__list populated__hist, kk_integer_t composition__10, kk_integer_t i0, kk_integer_t smc__step__num0, kk_integer_t mh__step__num0, kk_integer_t step__size0, bool normalize0, kk_context_t* _ctx); /* forall<a,e> (populated_hist : effects-and-types/histogram_rmsmc<(int) -> <exn,effects-and-types/yield,effects-and-types/score,effects-and-types/sample,effects-and-types/sample,div|e> a>, composition_1 : int, i : int, smc_step_num : int, mh_step_num : int, step_size : int, normalize : bool) -> <pure,effects-and-types/sample|e> effects-and-types/histogram_rmsmc<a> */ 

kk_std_core__list kk_rmsmc__mlift667_rmsmc(kk_integer_t mh__step__num, bool normalize, kk_integer_t smc__step__num, kk_integer_t step__size, kk_std_core__list pop, kk_context_t* _ctx); /* forall<a,e> (mh_step_num : int, normalize : bool, smc_step_num : int, step_size : int, pop : effects-and-types/histogram_rmsmc<(a : int) -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,effects-and-types/sample,div,exn,std/num/random/random|e> a>) -> <effects-and-types/sample,div,exn,std/num/random/random|e> effects-and-types/histogram_rmsmc<a> */ 

kk_std_core__list kk_rmsmc_rmsmc(kk_integer_t particle__num, kk_integer_t smc__step__num, kk_integer_t mh__step__num, kk_integer_t step__size, kk_function_t model, bool normalize, kk_context_t* _ctx); /* forall<a,e> (particle_num : int, smc_step_num : int, mh_step_num : int, step_size : int, model : () -> <pure,std/num/random/random,effects-and-types/sample,effects-and-types/sample,effects-and-types/score,effects-and-types/yield|e> a, normalize : bool) -> <pure,std/num/random/random|e> effects-and-types/histogram_rmsmc<a> */ 

void kk_rmsmc__init(kk_context_t* _ctx);

#endif // header
