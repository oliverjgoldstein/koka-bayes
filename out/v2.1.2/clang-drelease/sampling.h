#pragma once
#ifndef kk_sampling_H
#define kk_sampling_H
// Koka generated module: "sampling", koka version: 2.1.2
#include <kklib.h>
#include "std_core_types.h"
#include "std_core_hnd.h"
#include "std_core.h"
#include "std_num_double.h"
#include "std_num_random.h"
#include "effects_dash_and_dash_types.h"
#include "exponents.h"
#include "handlers.h"

// type declarations

// value declarations

kk_effects_dash_and_dash_types__exp kk_sampling_sum__weights(kk_std_core__list histogram, kk_context_t* _ctx); /* forall<a> (histogram : effects-and-types/histogram<a>) -> effects-and-types/exp */ 

kk_box_t kk_sampling__mlift749_populate(kk_function_t model, kk_unit_t wild__, kk_context_t* _ctx); /* forall<a,e> (model : () -> <effects-and-types/score|e> a, wild_ : ()) -> <effects-and-types/score|e> a */ 

kk_std_core__list kk_sampling_populate(kk_integer_t k, kk_function_t model, kk_context_t* _ctx); /* forall<a,e> (k : int, model : () -> <effects-and-types/score|e> a) -> e effects-and-types/histogram<a> */ 

double kk_sampling_sum__histogram(kk_std_core__list hist, kk_context_t* _ctx); /* forall<a> (hist : effects-and-types/histogram<a>) -> double */ 

kk_std_core__list kk_sampling_normalise(kk_std_core__list histogram, kk_context_t* _ctx); /* forall<a> (histogram : effects-and-types/histogram<a>) -> effects-and-types/histogram<a> */ 

kk_std_core__list kk_sampling__mlift750_importance__sampling(kk_std_core__list _y_4, kk_context_t* _ctx); /* forall<a,e> (effects-and-types/histogram<a>) -> <std/num/random/random,effects-and-types/sample|e> effects-and-types/histogram<a> */ 

kk_std_core__list kk_sampling_importance__sampling(kk_function_t model, kk_context_t* _ctx); /* forall<a,e> (model : effects-and-types/model<a,<std/num/random/random|e>>) -> <std/num/random/random|e> effects-and-types/histogram<a> */ 

kk_box_t kk_sampling__lift737_weighted__choice(double fuel, kk_std_core__list ws, kk_context_t* _ctx); /* forall<a> (fuel : double, ws : list<(effects-and-types/exp, a)>) -> exn a */ 

kk_box_t kk_sampling__mlift751_weighted__choice(kk_std_core__list histogram, kk_effects_dash_and_dash_types__exp total__w, double _y_10, kk_context_t* _ctx); /* forall<a> (histogram : effects-and-types/histogram<a>, total_w : effects-and-types/exp, double) -> <effects-and-types/sample,exn> a */ 

kk_box_t kk_sampling_weighted__choice(kk_std_core__list histogram, kk_context_t* _ctx); /* forall<a> (histogram : effects-and-types/histogram<a>) -> <exn,effects-and-types/sample> a */ 

kk_box_t kk_sampling__mlift752_resample(kk_std_core__list histogram, kk_unit_t wild__, kk_context_t* _ctx); /* forall<a> (histogram : effects-and-types/histogram<a>, wild_ : ()) -> <effects-and-types/score,exn,effects-and-types/sample> a */ 

kk_std_core__list kk_sampling_resample(kk_std_core__list histogram, kk_context_t* _ctx); /* forall<a> (histogram : effects-and-types/histogram<a>) -> <exn,effects-and-types/sample> effects-and-types/histogram<a> */ 

void kk_sampling__init(kk_context_t* _ctx);

#endif // header
