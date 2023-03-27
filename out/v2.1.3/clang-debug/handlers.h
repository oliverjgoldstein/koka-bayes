#pragma once
#ifndef kk_handlers_H
#define kk_handlers_H
// Koka generated module: "handlers", koka version: 2.1.3
#include <kklib.h>
#include "std_core_types.h"
#include "std_core_hnd.h"
#include "std_core.h"
#include "std_num_random.h"
#include "effects_dash_and_dash_types.h"
#include "exponents.h"

// type declarations

// value declarations

kk_box_t kk_handlers__mlift2014_advance(kk_integer_t a, kk_function_t _y_2, kk_context_t* _ctx); /* forall<a,e> (a : int, (int) -> <effects-and-types/yield|e> a) -> <effects-and-types/yield|e> a */ 

kk_box_t kk_handlers__mlift2015_advance(kk_integer_t a, kk_function_t resume, size_t _y_0, kk_context_t* _ctx); /* forall<a,e> (a : int, resume : (()) -> e ((int) -> <effects-and-types/yield|e> a), std/core/hnd/ev-index) -> <effects-and-types/yield|e> a */ 

kk_box_t kk_handlers__mlift2016_advance(kk_function_t _y_7, kk_context_t* _ctx); /* forall<a,e> ((int) -> <effects-and-types/yield|e> a) -> <effects-and-types/yield|e> a */ 

kk_box_t kk_handlers__mlift2017_advance(kk_function_t resume, size_t _y_5, kk_context_t* _ctx); /* forall<a,e> (resume : (()) -> e ((int) -> <effects-and-types/yield|e> a), std/core/hnd/ev-index) -> <effects-and-types/yield|e> a */ 

kk_box_t kk_handlers__mlift2018_advance(kk_function_t resume, kk_unit_t wild__, kk_context_t* _ctx); /* forall<a,e> (resume : (()) -> e ((int) -> <effects-and-types/yield|e> a), wild_ : ()) -> <effects-and-types/yield|e> a */ 

kk_function_t kk_handlers_advance(kk_function_t action, kk_context_t* _ctx); /* forall<a,e> (action : () -> <effects-and-types/yield|e> a) -> e ((a : int) -> <effects-and-types/yield|e> a) */ 

kk_box_t kk_handlers_finalize(kk_function_t action, kk_context_t* _ctx); /* forall<a,e> (action : () -> <effects-and-types/yield|e> a) -> e a */ 

kk_box_t kk_handlers_random__sampler(kk_function_t action, kk_context_t* _ctx); /* forall<a,e> (action : () -> <effects-and-types/sample,std/num/random/random|e> a) -> <std/num/random/random|e> a */ 

double kk_handlers__mlift2019_recorder(double rand__choice, kk_unit_t wild__, kk_context_t* _ctx); /* forall<h,e> (rand_choice : double, wild_ : ()) -> <local<h>,effects-and-types/sample|e> double */ 

double kk_handlers__mlift2020_recorder(double rand__choice, kk_ref_t trace, kk_std_core__list _y_15, kk_context_t* _ctx); /* forall<h,e> (rand_choice : double, trace : local-var<h,effects-and-types/trace_values>, effects-and-types/trace_values) -> <local<h>,effects-and-types/sample|e> double */ 

double kk_handlers__mlift2021_recorder(kk_ref_t trace, double rand__choice, kk_context_t* _ctx); /* forall<h,e> (trace : local-var<h,effects-and-types/trace_values>, rand_choice : double) -> <effects-and-types/sample,local<h>|e> double */ 

kk_std_core_types__tuple3_ kk_handlers__mlift2022_recorder(kk_box_t a, kk_box_t b, kk_std_core__list _y_17, kk_context_t* _ctx); /* forall<h,a,b,e> (a : a, b : b, effects-and-types/trace_values) -> <local<h>,effects-and-types/sample|e> (effects-and-types/trace_values, a, b) */ 

kk_std_core_types__tuple3_ kk_handlers_recorder(kk_std_core__list model__trace, kk_function_t action, kk_context_t* _ctx); /* forall<a,b,e> (model_trace : effects-and-types/trace_values, action : () -> <effects-and-types/sample,effects-and-types/sample|e> (a, b)) -> <effects-and-types/sample|e> (effects-and-types/trace_values, a, b) */ 

double kk_handlers__mlift2023_replayx(double rand__choice, kk_unit_t wild__0, kk_context_t* _ctx); /* forall<h,e> (rand_choice : double, wild_0 : ()) -> <local<h>,effects-and-types/sample|e> double */ 

double kk_handlers__mlift2024_replayx(kk_ref_t extended__trace, double rand__choice, kk_std_core__list _y_28, kk_context_t* _ctx); /* forall<h,e> (extended_trace : local-var<h,list<double>>, rand_choice : double, list<double>) -> <local<h>,effects-and-types/sample|e> double */ 

double kk_handlers__mlift2025_replayx(kk_ref_t extended__trace, double rand__choice, kk_context_t* _ctx); /* forall<h,e> (extended_trace : local-var<h,list<double>>, rand_choice : double) -> <effects-and-types/sample,local<h>|e> double */ 

double kk_handlers__mlift2026_replayx(kk_std_core__list _y_25, kk_ref_t extended__trace, kk_integer_t _y_26, kk_context_t* _ctx); /* forall<h,e> (list<double>, extended_trace : local-var<h,list<double>>, int) -> <local<h>,effects-and-types/sample|e> double */ 

double kk_handlers__mlift2027_replayx(kk_ref_t extended__trace, kk_ref_t index, kk_std_core__list _y_25, kk_context_t* _ctx); /* forall<h,e> (extended_trace : local-var<h,list<double>>, index : local-var<h,int>, list<double>) -> <local<h>,effects-and-types/sample|e> double */ 

double kk_handlers__mlift2028_replayx(kk_ref_t extended__trace, kk_ref_t index, kk_unit_t wild__, kk_context_t* _ctx); /* forall<h,e> (extended_trace : local-var<h,list<double>>, index : local-var<h,int>, wild_ : ()) -> <local<h>,effects-and-types/sample|e> double */ 

double kk_handlers__mlift2029_replayx(kk_ref_t extended__trace, kk_ref_t index, kk_integer_t _y_23, kk_context_t* _ctx); /* forall<h,e> (extended_trace : local-var<h,list<double>>, index : local-var<h,int>, int) -> <local<h>,effects-and-types/sample|e> double */ 

kk_std_core_types__tuple2_ kk_handlers__mlift2030_replayx(kk_std_core__list _y_31, kk_box_t x, kk_integer_t _y_32, kk_context_t* _ctx); /* forall<h,a,e> (list<double>, x : a, int) -> <local<h>,effects-and-types/sample|e> (list<double>, a) */ 

kk_std_core_types__tuple2_ kk_handlers__mlift2031_replayx(kk_ref_t index, kk_box_t x, kk_std_core__list _y_31, kk_context_t* _ctx); /* forall<h,a,e> (index : local-var<h,int>, x : a, list<double>) -> <local<h>,effects-and-types/sample|e> (list<double>, a) */ 

kk_std_core_types__tuple2_ kk_handlers_replayx(kk_std_core__list trace, kk_function_t action, kk_context_t* _ctx); /* forall<a,e> (trace : effects-and-types/trace_values, action : () -> <effects-and-types/sample,effects-and-types/sample|e> a) -> <effects-and-types/sample|e> (list<double>, a) */ 

kk_unit_t kk_handlers__mlift2032_weighted(kk_effects_dash_and_dash_types__exp s, kk_ref_t wps, kk_effects_dash_and_dash_types__exp _y_38, kk_context_t* _ctx); /* forall<h,e> (s : effects-and-types/exp, wps : local-var<h,effects-and-types/exp>, effects-and-types/exp) -> <local<h>|e> () */ 

kk_std_core_types__tuple2_ kk_handlers__mlift2033_weighted(kk_box_t x, kk_effects_dash_and_dash_types__exp _y_40, kk_context_t* _ctx); /* forall<h,a,e> (x : a, effects-and-types/exp) -> <local<h>|e> (effects-and-types/exp, a) */ 

kk_std_core_types__tuple2_ kk_handlers_weighted(kk_effects_dash_and_dash_types__exp wp, kk_function_t action, kk_context_t* _ctx); /* forall<a,e> (wp : effects-and-types/exp, action : () -> <effects-and-types/score|e> a) -> e (effects-and-types/exp, a) */ 

kk_unit_t kk_handlers__mlift2034_yield__on__scorex(kk_unit_t wild__, kk_context_t* _ctx); /* forall<e> (wild_ : ()) -> <effects-and-types/score,effects-and-types/yield|e> () */ 

kk_box_t kk_handlers_yield__on__scorex(kk_function_t action, kk_context_t* _ctx); /* forall<a,e> (action : () -> <effects-and-types/score,effects-and-types/score,effects-and-types/yield|e> a) -> <effects-and-types/score,effects-and-types/yield|e> a */ 

kk_box_t kk_handlers__mlift2035_replay(kk_function_t action, size_t _y_48, kk_context_t* _ctx); /* forall<a,e> (action : () -> <effects-and-types/sample|e> a, std/core/hnd/ev-index) -> <effects-and-types/sample,effects-and-types/sample|e> a */ 

kk_std_core_types__tuple2_ kk_handlers_replay(kk_std_core__list trace, kk_function_t action, kk_context_t* _ctx); /* forall<a,e> (trace : effects-and-types/trace_values, action : () -> <effects-and-types/sample|e> a) -> <effects-and-types/sample|e> (list<double>, a) */ 

kk_box_t kk_handlers__mlift2036_yield__on__score(kk_function_t action, size_t _y_51, kk_context_t* _ctx); /* forall<a,e> (action : () -> <effects-and-types/score,effects-and-types/yield|e> a, std/core/hnd/ev-index) -> <effects-and-types/score,effects-and-types/score,effects-and-types/yield|e> a */ 

kk_box_t kk_handlers_yield__on__score(kk_function_t action, kk_context_t* _ctx); /* forall<a,e> (action : () -> <effects-and-types/score,effects-and-types/yield|e> a) -> <effects-and-types/score,effects-and-types/yield|e> a */ 

void kk_handlers__init(kk_context_t* _ctx);

#endif // header
