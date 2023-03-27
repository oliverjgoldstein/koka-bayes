#pragma once
#ifndef kk_sampling_H
#define kk_sampling_H
// Koka generated module: "sampling", koka version: 2.1.3
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

kk_box_t kk_sampling__mlift823_populate(kk_function_t model, kk_unit_t wild__, kk_context_t* _ctx); /* forall<a,e> (model : () -> <effects-and-types/score|e> a, wild_ : ()) -> <effects-and-types/score|e> a */ 

kk_std_core__list kk_sampling_populate(kk_integer_t k, kk_function_t model, kk_context_t* _ctx); /* forall<a,e> (k : int, model : () -> <effects-and-types/score|e> a) -> e effects-and-types/histogram<a> */ 

kk_box_t kk_sampling__lift812_weighted__choice(double fuel, kk_std_core__list ws, kk_context_t* _ctx); /* forall<a> (fuel : double, ws : list<(double, a)>) -> exn a */ 

kk_box_t kk_sampling__mlift824_weighted__choice(kk_std_core__list histogram, double total__w, double _y_8, kk_context_t* _ctx); /* forall<a> (histogram : list<(double, a)>, total_w : double, double) -> <effects-and-types/sample,exn> a */ 

kk_box_t kk_sampling_weighted__choice(double total__w, kk_std_core__list histogram, kk_context_t* _ctx); /* forall<a> (total_w : double, histogram : list<(double, a)>) -> <exn,effects-and-types/sample> a */ 

double kk_sampling_sum__histogram(kk_std_core__list hist, kk_context_t* _ctx); /* forall<a> (hist : effects-and-types/histogram<a>) -> double */ 

kk_std_core__list kk_sampling_normalise(kk_std_core__list histogram, kk_context_t* _ctx); /* forall<a> (histogram : effects-and-types/histogram<a>) -> effects-and-types/histogram<a> */ 

kk_std_core__list kk_sampling__mlift825_importance__sampling(kk_std_core__list _y_10, kk_context_t* _ctx); /* forall<a,e> (effects-and-types/histogram<a>) -> <std/num/random/random,effects-and-types/sample|e> effects-and-types/histogram<a> */ 

kk_std_core__list kk_sampling_importance__sampling(kk_function_t model, kk_context_t* _ctx); /* forall<a,e> (model : effects-and-types/model<a,<std/num/random/random|e>>) -> <std/num/random/random|e> effects-and-types/histogram<a> */ 

kk_box_t kk_sampling__mlift826_resample(kk_std_core__list histogram__dbl, double total__w__dbl, kk_unit_t wild__, kk_context_t* _ctx); /* forall<a> (histogram_dbl : list<(double, a)>, total_w_dbl : double, wild_ : ()) -> <effects-and-types/score,exn,effects-and-types/sample> a */ 

kk_std_core__list kk_sampling__mlift827_resample(kk_integer_t n, kk_effects_dash_and_dash_types__exp total__w, double total__w__dbl, kk_std_core__list histogram__dbl, kk_context_t* _ctx); /* forall<a> (n : int, total_w : effects-and-types/exp, total_w_dbl : double, histogram_dbl : list<(double, a)>) -> <exn,effects-and-types/sample> effects-and-types/histogram<a> */ 

kk_std_core__list kk_sampling_resample(kk_std_core__list histogram, kk_context_t* _ctx); /* forall<a> (histogram : effects-and-types/histogram<a>) -> <exn,effects-and-types/sample> effects-and-types/histogram<a> */ 

void kk_sampling__init(kk_context_t* _ctx);

#endif // header
