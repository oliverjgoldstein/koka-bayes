#pragma once
#ifndef kk_sequential_H
#define kk_sequential_H
// Koka generated module: "sequential", koka version: 2.1.3
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

kk_std_core__list kk_sequential__mlift739_smc__loop(kk_integer_t i, bool normalize, kk_integer_t step__num, kk_integer_t step__size, kk_std_core__list _y_5, kk_context_t* _ctx); /* forall<a,e> (i : int, normalize : bool, step_num : int, step_size : int, list<(effects-and-types/exp, (a : int) -> <effects-and-types/yield,effects-and-types/score,exn,effects-and-types/sample,div|e> a)>) -> <exn,effects-and-types/sample,div|e> effects-and-types/histogram<a> */ 

kk_std_core__list kk_sequential__mlift740_smc__loop(kk_integer_t i0, bool normalize0, kk_integer_t step__num0, kk_integer_t step__size0, kk_std_core__list _y_7, kk_context_t* _ctx); /* forall<a,e> (i : int, normalize : bool, step_num : int, step_size : int, list<(effects-and-types/exp, (a : int) -> <effects-and-types/yield,effects-and-types/score,exn,effects-and-types/sample,div|e> a)>) -> <exn,effects-and-types/sample,div|e> effects-and-types/histogram<a> */ 

kk_std_core__list kk_sequential__mlift741_smc__loop(kk_integer_t i1, bool normalize1, kk_integer_t step__num1, kk_integer_t step__size1, kk_std_core__list resampled__histogram, kk_context_t* _ctx); /* forall<a,e> (i : int, normalize : bool, step_num : int, step_size : int, resampled_histogram : effects-and-types/histogram<(int) -> <exn,effects-and-types/yield,effects-and-types/score,effects-and-types/sample,div|e> a>) -> <exn,effects-and-types/sample,div|e> effects-and-types/histogram<a> */ 

kk_std_core__list kk_sequential__mlift742_smc__loop(kk_std_core__list _y_14, kk_context_t* _ctx); /* forall<a,e> (list<(effects-and-types/exp, a)>) -> <exn,effects-and-types/sample,div|e> effects-and-types/histogram<a> */ 

kk_std_core__list kk_sequential_smc__loop(kk_integer_t i2, kk_std_core__list populated__hist, kk_integer_t step__num2, kk_integer_t step__size2, bool normalize2, kk_context_t* _ctx); /* forall<a,e> (i : int, populated_hist : effects-and-types/histogram<(int) -> <exn,effects-and-types/yield,effects-and-types/score,effects-and-types/sample,div|e> a>, step_num : int, step_size : int, normalize : bool) -> <pure,effects-and-types/sample|e> effects-and-types/histogram<a> */ 

kk_std_core__list kk_sequential__mlift743_smc(bool normalize, kk_integer_t step__num, kk_integer_t step__size, kk_std_core__list _y_20, kk_context_t* _ctx); /* forall<a,e> (normalize : bool, step_num : int, step_size : int, effects-and-types/histogram<(a : int) -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random|e> a>) -> <effects-and-types/sample,div,exn,std/num/random/random|e> effects-and-types/histogram<a> */ 

kk_std_core__list kk_sequential_smc(kk_integer_t particle__num, kk_integer_t step__num, kk_integer_t step__size, kk_function_t model, bool normalize, kk_context_t* _ctx); /* forall<a,e> (particle_num : int, step_num : int, step_size : int, model : () -> <pure,std/num/random/random,effects-and-types/sample,effects-and-types/score,effects-and-types/yield|e> a, normalize : bool) -> <pure,std/num/random/random|e> effects-and-types/histogram<a> */ 

void kk_sequential__init(kk_context_t* _ctx);

#endif // header
