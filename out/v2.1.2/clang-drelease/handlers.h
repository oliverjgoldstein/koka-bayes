#pragma once
#ifndef kk_handlers_H
#define kk_handlers_H
// Koka generated module: "handlers", koka version: 2.1.2
#include <kklib.h>
#include "std_core_types.h"
#include "std_core_hnd.h"
#include "std_core.h"
#include "std_num_random.h"
#include "effects_dash_and_dash_types.h"
#include "exponents.h"

// type declarations

// value declarations

kk_box_t kk_handlers__mlift1696_advance(kk_integer_t a, kk_function_t _y_2, kk_context_t* _ctx); /* forall<a,e> (a : int, (int) -> <effects-and-types/yield|e> a) -> <effects-and-types/yield|e> a */ 

kk_box_t kk_handlers__mlift1697_advance(kk_integer_t a, kk_function_t resume, size_t _y_0, kk_context_t* _ctx); /* forall<a,e> (a : int, resume : (()) -> e ((int) -> <effects-and-types/yield|e> a), std/core/hnd/ev-index) -> <effects-and-types/yield|e> a */ 

kk_box_t kk_handlers__mlift1698_advance(kk_function_t _y_7, kk_context_t* _ctx); /* forall<a,e> ((int) -> <effects-and-types/yield|e> a) -> <effects-and-types/yield|e> a */ 

kk_box_t kk_handlers__mlift1699_advance(kk_function_t resume, size_t _y_5, kk_context_t* _ctx); /* forall<a,e> (resume : (()) -> e ((int) -> <effects-and-types/yield|e> a), std/core/hnd/ev-index) -> <effects-and-types/yield|e> a */ 

kk_box_t kk_handlers__mlift1700_advance(kk_function_t resume, kk_unit_t wild__, kk_context_t* _ctx); /* forall<a,e> (resume : (()) -> e ((int) -> <effects-and-types/yield|e> a), wild_ : ()) -> <effects-and-types/yield|e> a */ 

kk_function_t kk_handlers_advance(kk_function_t action, kk_context_t* _ctx); /* forall<a,e> (action : () -> <effects-and-types/yield|e> a) -> e ((a : int) -> <effects-and-types/yield|e> a) */ 

kk_box_t kk_handlers_finalize(kk_function_t action, kk_context_t* _ctx); /* forall<a,e> (action : () -> <effects-and-types/yield|e> a) -> e a */ 

kk_box_t kk_handlers_random__sampler(kk_function_t action, kk_context_t* _ctx); /* forall<a,e> (action : () -> <effects-and-types/sample,std/num/random/random|e> a) -> <std/num/random/random|e> a */ 

double kk_handlers__mlift1701_replayx(double rand__choice, kk_unit_t wild__0, kk_context_t* _ctx); /* forall<h,e> (rand_choice : double, wild_0 : ()) -> <local<h>,effects-and-types/sample|e> double */ 

double kk_handlers__mlift1702_replayx(kk_ref_t extended__trace, double rand__choice, kk_std_core__list _y_19, kk_context_t* _ctx); /* forall<h,e> (extended_trace : local-var<h,list<double>>, rand_choice : double, list<double>) -> <local<h>,effects-and-types/sample|e> double */ 

double kk_handlers__mlift1703_replayx(kk_ref_t extended__trace, double rand__choice, kk_context_t* _ctx); /* forall<h,e> (extended_trace : local-var<h,list<double>>, rand_choice : double) -> <effects-and-types/sample,local<h>|e> double */ 

double kk_handlers__mlift1704_replayx(kk_std_core__list _y_16, kk_ref_t extended__trace, kk_integer_t _y_17, kk_context_t* _ctx); /* forall<h,e> (list<double>, extended_trace : local-var<h,list<double>>, int) -> <local<h>,effects-and-types/sample|e> double */ 

double kk_handlers__mlift1705_replayx(kk_ref_t extended__trace, kk_ref_t index, kk_std_core__list _y_16, kk_context_t* _ctx); /* forall<h,e> (extended_trace : local-var<h,list<double>>, index : local-var<h,int>, list<double>) -> <local<h>,effects-and-types/sample|e> double */ 

double kk_handlers__mlift1706_replayx(kk_ref_t extended__trace, kk_ref_t index, kk_unit_t wild__, kk_context_t* _ctx); /* forall<h,e> (extended_trace : local-var<h,list<double>>, index : local-var<h,int>, wild_ : ()) -> <local<h>,effects-and-types/sample|e> double */ 

double kk_handlers__mlift1707_replayx(kk_ref_t extended__trace, kk_ref_t index, kk_integer_t _y_14, kk_context_t* _ctx); /* forall<h,e> (extended_trace : local-var<h,list<double>>, index : local-var<h,int>, int) -> <local<h>,effects-and-types/sample|e> double */ 

kk_std_core_types__tuple2_ kk_handlers__mlift1708_replayx(kk_std_core__list _y_22, kk_box_t x, kk_integer_t _y_23, kk_context_t* _ctx); /* forall<h,a,e> (list<double>, x : a, int) -> <local<h>,effects-and-types/sample|e> (list<double>, a) */ 

kk_std_core_types__tuple2_ kk_handlers__mlift1709_replayx(kk_ref_t index, kk_box_t x, kk_std_core__list _y_22, kk_context_t* _ctx); /* forall<h,a,e> (index : local-var<h,int>, x : a, list<double>) -> <local<h>,effects-and-types/sample|e> (list<double>, a) */ 

kk_std_core_types__tuple2_ kk_handlers_replayx(kk_std_core__list trace, kk_function_t action, kk_context_t* _ctx); /* forall<a,e> (trace : effects-and-types/trace_values, action : () -> <effects-and-types/sample,effects-and-types/sample|e> a) -> <effects-and-types/sample|e> (list<double>, a) */ 

kk_unit_t kk_handlers__mlift1710_weighted(kk_effects_dash_and_dash_types__exp s, kk_ref_t wps, kk_effects_dash_and_dash_types__exp _y_29, kk_context_t* _ctx); /* forall<h,e> (s : effects-and-types/exp, wps : local-var<h,effects-and-types/exp>, effects-and-types/exp) -> <local<h>|e> () */ 

kk_std_core_types__tuple2_ kk_handlers__mlift1711_weighted(kk_box_t x, kk_effects_dash_and_dash_types__exp _y_31, kk_context_t* _ctx); /* forall<h,a,e> (x : a, effects-and-types/exp) -> <local<h>|e> (effects-and-types/exp, a) */ 

kk_std_core_types__tuple2_ kk_handlers_weighted(kk_effects_dash_and_dash_types__exp wp, kk_function_t action, kk_context_t* _ctx); /* forall<a,e> (wp : effects-and-types/exp, action : () -> <effects-and-types/score|e> a) -> e (effects-and-types/exp, a) */ 

kk_unit_t kk_handlers__mlift1712_yield__on__scorex(kk_unit_t wild__, kk_context_t* _ctx); /* forall<e> (wild_ : ()) -> <effects-and-types/score,effects-and-types/yield|e> () */ 

kk_box_t kk_handlers_yield__on__scorex(kk_function_t action, kk_context_t* _ctx); /* forall<a,e> (action : () -> <effects-and-types/score,effects-and-types/score,effects-and-types/yield|e> a) -> <effects-and-types/score,effects-and-types/yield|e> a */ 

kk_box_t kk_handlers__mlift1713_replay(kk_function_t action, size_t _y_39, kk_context_t* _ctx); /* forall<a,e> (action : () -> <effects-and-types/sample|e> a, std/core/hnd/ev-index) -> <effects-and-types/sample,effects-and-types/sample|e> a */ 

kk_std_core_types__tuple2_ kk_handlers_replay(kk_std_core__list trace, kk_function_t action, kk_context_t* _ctx); /* forall<a,e> (trace : effects-and-types/trace_values, action : () -> <effects-and-types/sample|e> a) -> <effects-and-types/sample|e> (list<double>, a) */ 

kk_box_t kk_handlers__mlift1714_yield__on__score(kk_function_t action, size_t _y_42, kk_context_t* _ctx); /* forall<a,e> (action : () -> <effects-and-types/score,effects-and-types/yield|e> a, std/core/hnd/ev-index) -> <effects-and-types/score,effects-and-types/score,effects-and-types/yield|e> a */ 

kk_box_t kk_handlers_yield__on__score(kk_function_t action, kk_context_t* _ctx); /* forall<a,e> (action : () -> <effects-and-types/score,effects-and-types/yield|e> a) -> <effects-and-types/score,effects-and-types/yield|e> a */ 

void kk_handlers__init(kk_context_t* _ctx);

#endif // header
