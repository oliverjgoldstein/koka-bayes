#pragma once
#ifndef kk_smc_H
#define kk_smc_H
// Koka generated module: "smc", koka version: 2.1.3
#include <kklib.h>
#include "std_core_types.h"
#include "std_core_hnd.h"
#include "std_core.h"
#include "std_num_random.h"
#include "effects_dash_and_dash_types.h"
#include "handlers.h"
#include "sampling.h"

// type declarations

// value declarations

kk_std_core__list kk_smc__mlift509_smc_steps(kk_function_t norm, kk_std_core__list _y_4, kk_context_t* _ctx); /* forall<a,e> (norm : forall<b> (effects-and-types/histogram<b>) -> effects-and-types/histogram<b>, list<(effects-and-types/exp, a)>) -> <exn,effects-and-types/sample,div|e> effects-and-types/histogram<a> */ 

kk_std_core__list kk_smc__mlift510_smc_steps(kk_function_t norm0, kk_integer_t step_size, kk_integer_t steps, kk_std_core__list _y_10, kk_context_t* _ctx); /* forall<a,e> (norm : forall<b> (effects-and-types/histogram<b>) -> effects-and-types/histogram<b>, step-size : int, steps : int, list<(effects-and-types/exp, (steps : int) -> <effects-and-types/yield,effects-and-types/score,exn,effects-and-types/sample,div|e> a)>) -> <exn,effects-and-types/sample,div|e> effects-and-types/histogram<a> */ 

kk_std_core__list kk_smc__mlift511_smc_steps(kk_function_t norm1, kk_integer_t step_size0, kk_integer_t steps0, kk_std_core__list pop_resampled, kk_context_t* _ctx); /* forall<a,e> (norm : forall<b> (effects-and-types/histogram<b>) -> effects-and-types/histogram<b>, step-size : int, steps : int, pop-resampled : effects-and-types/histogram<(int) -> <exn,effects-and-types/yield,effects-and-types/score,effects-and-types/sample,div|e> a>) -> <exn,effects-and-types/sample,div|e> effects-and-types/histogram<a> */ 

kk_std_core__list kk_smc_smc_steps(kk_integer_t steps1, kk_integer_t step_size1, kk_std_core__list pop_hist, kk_function_t norm2, kk_context_t* _ctx); /* forall<a,e> (steps : int, step-size : int, pop-hist : effects-and-types/histogram<(int) -> <exn,effects-and-types/yield,effects-and-types/score,effects-and-types/sample,div|e> a>, norm : forall<b> (effects-and-types/histogram<b>) -> effects-and-types/histogram<b>) -> <pure,effects-and-types/sample|e> effects-and-types/histogram<a> */ 

kk_std_core__list kk_smc__mlift512_smc(bool normalize, kk_integer_t step_size, kk_integer_t steps, kk_std_core__list _y_15, kk_context_t* _ctx); /* forall<a,e> (normalize : bool, step-size : int, steps : int, effects-and-types/histogram<(steps : int) -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random|e> a>) -> <effects-and-types/sample,div,exn,std/num/random/random|e> effects-and-types/histogram<a> */ 

kk_std_core__list kk_smc_smc(kk_integer_t particle__num, kk_integer_t steps, kk_integer_t step_size, kk_function_t model, bool normalize, kk_context_t* _ctx); /* forall<a,e> (particle_num : int, steps : int, step-size : int, model : () -> <pure,std/num/random/random,effects-and-types/sample,effects-and-types/score,effects-and-types/yield|e> a, normalize : bool) -> <pure,std/num/random/random|e> effects-and-types/histogram<a> */ 

void kk_smc__init(kk_context_t* _ctx);

#endif // header
