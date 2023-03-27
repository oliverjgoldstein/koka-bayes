#pragma once
#ifndef kk_sampling_dash_rmsmc_H
#define kk_sampling_dash_rmsmc_H
// Koka generated module: "sampling-rmsmc", koka version: 2.1.3
#include <kklib.h>
#include "std_core_types.h"
#include "std_core_hnd.h"
#include "std_core.h"
#include "std_num_double.h"
#include "effects_dash_and_dash_types.h"
#include "exponents.h"
#include "handlers.h"

// type declarations

// value declarations

kk_box_t kk_sampling_dash_rmsmc__mlift125_populate(kk_function_t model, kk_unit_t wild__, kk_context_t* _ctx); /* forall<a,e> (model : () -> <effects-and-types/score,effects-and-types/sample,effects-and-types/sample|e> a, wild_ : ()) -> <effects-and-types/score,effects-and-types/sample,effects-and-types/sample|e> a */ 

kk_std_core__list kk_sampling_dash_rmsmc_populate(kk_integer_t k, kk_function_t model, kk_context_t* _ctx); /* forall<a,e> (k : int, model : () -> <effects-and-types/score,effects-and-types/sample,effects-and-types/sample|e> a) -> <effects-and-types/sample|e> effects-and-types/histogram_rmsmc<a> */ 

void kk_sampling_dash_rmsmc__init(kk_context_t* _ctx);

#endif // header
