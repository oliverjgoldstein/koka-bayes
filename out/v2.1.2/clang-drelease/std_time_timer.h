#pragma once
#ifndef kk_std_time_timer_H
#define kk_std_time_timer_H
// Koka generated module: "std/time/timer", koka version: 2.1.2
#include <kklib.h>
#include "std_core_types.h"
#include "std_core_hnd.h"
#include "std_core.h"
#include "std_num_double.h"
#include "std_num_ddouble.h"
#include "std_time_timestamp.h"
#include "std_time_duration.h"

// type declarations

// value declarations

kk_std_core_types__tuple2_ kk_std_time_timer_xticks(kk_context_t* _ctx); /* () -> ndet (double, double) */ 

double kk_std_time_timer_xticks_resolution(kk_context_t* _ctx); /* () -> ndet double */ 

kk_std_time_duration__duration kk_std_time_timer_ticks(kk_context_t* _ctx); /* () -> ndet std/time/duration/duration */ 

kk_std_core_types__tuple2_ kk_std_time_timer__mlift480_elapsed(kk_std_time_duration__duration t0, kk_box_t x, kk_context_t* _ctx); /* forall<a,e> (t0 : std/time/duration/duration, x : a) -> <ndet|e> (std/time/duration/duration, a) */ 

kk_std_core_types__tuple2_ kk_std_time_timer_elapsed(kk_function_t action, kk_context_t* _ctx); /* forall<a,e> (action : () -> <ndet|e> a) -> <ndet|e> (std/time/duration/duration, a) */ 

kk_box_t kk_std_time_timer__mlift481_print_elapsed(kk_std_core_types__optional msg, kk_std_core_types__tuple2_ _y_1, kk_context_t* _ctx); /* forall<a,e> (msg : optional<string>, (std/time/duration/duration, a)) -> <ndet,console|e> a */ 

kk_box_t kk_std_time_timer_print_elapsed(kk_function_t action, kk_std_core_types__optional msg, kk_context_t* _ctx); /* forall<a,e> (action : () -> <ndet,console|e> a, msg : optional<string>) -> <ndet,console|e> a */ 
 
// Return the smallest time difference in seconds that `ticks` can measure.

static inline kk_std_time_duration__duration kk_std_time_timer_ticks_resolution(kk_context_t* _ctx) { /* () -> ndet std/time/duration/duration */ 
  double secs_496 = kk_std_time_timer_xticks_resolution(_ctx); /*double*/;
  kk_std_num_ddouble__ddouble _x581 = kk_std_time_timestamp_timespan_1(secs_496, _ctx); /*std/time/timestamp/timespan*/
  return kk_std_time_duration__new_Duration(_x581, _ctx);
}

void kk_std_time_timer__init(kk_context_t* _ctx);

#endif // header
