// Koka generated module: "std/time/timer", koka version: 2.1.3
#include "std_time_timer.h"
/*---------------------------------------------------------------------------
  Copyright 2020, Daan Leijen, Microsoft Corporation.

  This is free software; you can redistribute it and/or modify it under the
  terms of the Apache License, Version 2.0. A copy of the License can be
  found in the file "license.txt" at the root of this distribution.
---------------------------------------------------------------------------*/

static kk_std_core_types__tuple2_ kk_timer_ticks_tuple(kk_context_t* ctx) {
  double frac;
  double secs = kk_timer_ticks(&frac,ctx);
  return kk_std_core_types__new_dash__lp__comma__rp_( kk_double_box(secs,ctx), kk_double_box(frac,ctx), ctx );
}


kk_std_core_types__tuple2_ kk_std_time_timer_xticks(kk_context_t* _ctx) { /* () -> ndet (double, double) */ 
  return kk_timer_ticks_tuple(kk_context());
}
 
// Return the smallest time difference in seconds that `ticks` can measure.

double kk_std_time_timer_xticks_resolution(kk_context_t* _ctx) { /* () -> ndet double */ 
  return kk_timer_resolution(kk_context());
}
 
// Return a high-resolution time stamp in fractional SI seconds.
// The duration is guaranteed to be monotonically increasing
// and have at least millisecond resolution.

kk_std_time_duration__duration kk_std_time_timer_ticks(kk_context_t* _ctx) { /* () -> ndet std/time/duration/duration */ 
  kk_std_core_types__tuple2_ _match_533 = kk_std_time_timer_xticks(_ctx); /*(double, double)*/;
  kk_box_t _box_x497 = _match_533.fst;
  kk_box_t _box_x498 = _match_533.snd;
  double secs = kk_double_unbox(_box_x497, NULL);
  double frac = kk_double_unbox(_box_x498, NULL);
  kk_std_core_types__tuple2__drop(_match_533, _ctx);
  kk_integer_t _x536;
  double _x537 = kk_std_num_double_truncate(secs, _ctx); /*double*/
  _x536 = kk_integer_from_double(_x537,kk_context()); /*int*/
  kk_std_core_types__optional _x538;
  double _b_500_499;
  double _x539 = kk_std_num_double_fraction(secs, _ctx); /*double*/
  _b_500_499 = (_x539 + frac); /*double*/
  _x538 = kk_std_core_types__new_Optional(kk_double_box(_b_500_499, _ctx), _ctx); /*optional<108>*/
  return kk_std_time_duration_duration_1(_x536, _x538, _ctx);
}
 
// monadic lift

kk_std_core_types__tuple2_ kk_std_time_timer__mlift480_elapsed(kk_std_time_duration__duration t0, kk_box_t x, kk_context_t* _ctx) { /* forall<a,e> (t0 : std/time/duration/duration, x : a) -> <ndet|e> (std/time/duration/duration, a) */ 
  kk_std_time_duration__duration t1 = kk_std_time_timer_ticks(_ctx); /*std/time/duration/duration*/;
  kk_std_time_duration__duration _b_503_501 = kk_std_time_duration__lp__dash__rp_(t1, t0, _ctx); /*std/time/duration/duration*/;
  return kk_std_core_types__new_dash__lp__comma__rp_(kk_std_time_duration__duration_box(_b_503_501, _ctx), x, _ctx);
}
 
// Return the number of fractional seconds that it takes to evaluate `action`.


// lift anonymous function
struct kk_std_time_timer_elapsed_fun541__t {
  struct kk_function_s _base;
  kk_std_time_duration__duration t0;
};
static kk_box_t kk_std_time_timer_elapsed_fun541(kk_function_t _fself, kk_box_t _b_506, kk_context_t* _ctx);
static kk_function_t kk_std_time_timer_new_elapsed_fun541(kk_std_time_duration__duration t0, kk_context_t* _ctx) {
  struct kk_std_time_timer_elapsed_fun541__t* _self = kk_function_alloc_as(struct kk_std_time_timer_elapsed_fun541__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_time_timer_elapsed_fun541, kk_context());
  _self->t0 = t0;
  return &_self->_base;
}

static kk_box_t kk_std_time_timer_elapsed_fun541(kk_function_t _fself, kk_box_t _b_506, kk_context_t* _ctx) {
  struct kk_std_time_timer_elapsed_fun541__t* _self = kk_function_as(struct kk_std_time_timer_elapsed_fun541__t*, _fself);
  kk_std_time_duration__duration t0 = _self->t0; /* std/time/duration/duration */
  kk_drop_match(_self, {kk_std_time_duration__duration_dup(t0);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x542 = kk_std_time_timer__mlift480_elapsed(t0, _b_506, _ctx); /*(std/time/duration/duration, 231)*/
  return kk_std_core_types__tuple2__box(_x542, _ctx);
}

kk_std_core_types__tuple2_ kk_std_time_timer_elapsed(kk_function_t action, kk_context_t* _ctx) { /* forall<a,e> (action : () -> <ndet|e> a) -> <ndet|e> (std/time/duration/duration, a) */ 
  kk_std_time_duration__duration t0 = kk_std_time_timer_ticks(_ctx); /*std/time/duration/duration*/;
  kk_box_t x_482 = kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), action, (action, _ctx)); /*231*/;
  if (kk_yielding(kk_context())) {
    kk_box_drop(x_482, _ctx);
    kk_box_t _x540 = kk_std_core_hnd_yield_extend(kk_std_time_timer_new_elapsed_fun541(t0, _ctx), _ctx); /*3991*/
    return kk_std_core_types__tuple2__unbox(_x540, _ctx);
  }
  kk_std_time_duration__duration t1 = kk_std_time_timer_ticks(_ctx); /*std/time/duration/duration*/;
  kk_std_time_duration__duration _b_511_507 = kk_std_time_duration__lp__dash__rp_(t1, t0, _ctx); /*std/time/duration/duration*/;
  return kk_std_core_types__new_dash__lp__comma__rp_(kk_std_time_duration__duration_box(_b_511_507, _ctx), x_482, _ctx);
}
 
// monadic lift

kk_box_t kk_std_time_timer__mlift481_print_elapsed(kk_std_core_types__optional msg, kk_std_core_types__tuple2_ _y_1, kk_context_t* _ctx) { /* forall<a,e> (msg : optional<string>, (std/time/duration/duration, a)) -> <ndet,console|e> a */ 
  kk_box_t _box_x513 = _y_1.fst;
  kk_box_t x = _y_1.snd;
  kk_std_time_duration__duration t = kk_std_time_duration__duration_unbox(_box_x513, NULL);
  kk_box_dup(x);
  kk_std_core_types__tuple2__drop(_y_1, _ctx);
  kk_unit_t __ = kk_Unit;
  kk_string_t s_486;
  kk_string_t _x544;
  if (kk_std_core_types__is_Optional(msg)) {
    kk_box_t _box_x514 = msg._cons.Optional.value;
    kk_string_t _msg_238 = kk_string_unbox(_box_x514);
    kk_string_dup(_msg_238);
    kk_std_core_types__optional_drop(msg, _ctx);
    _x544 = _msg_238; /*string*/
    goto _match545;
  }
  kk_define_string_literal(, _s547, 7, "elapsed")
  _x544 = kk_string_dup(_s547); /*string*/
  _match545: ;
  kk_string_t _x548;
  kk_string_t _x549;
  kk_define_string_literal(, _s550, 1, " ")
  _x549 = kk_string_dup(_s550); /*string*/
  kk_string_t _x551;
  kk_std_core_types__optional max_prec_488 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(3)), _ctx); /*optional<int>*/;
  kk_string_t _x552;
  kk_std_num_ddouble__ddouble _x553;
  kk_std_num_ddouble__ddouble _x = t.secs;
  _x553 = _x; /*std/time/timestamp/timespan*/
  kk_std_core_types__optional _x554;
  kk_integer_t _b_519_518;
  kk_integer_t _x555;
  kk_integer_t _x556;
  if (kk_std_core_types__is_Optional(max_prec_488)) {
    kk_box_t _box_x517 = max_prec_488._cons.Optional.value;
    kk_integer_t _max_prec_1769 = kk_integer_unbox(_box_x517);
    kk_integer_dup(_max_prec_1769);
    kk_std_core_types__optional_drop(max_prec_488, _ctx);
    _x556 = _max_prec_1769; /*int*/
    goto _match557;
  }
  _x556 = kk_integer_from_small(9); /*int*/
  _match557: ;
  _x555 = kk_integer_abs(_x556,kk_context()); /*int*/
  _b_519_518 = kk_integer_neg(_x555,kk_context()); /*int*/
  _x554 = kk_std_core_types__new_Optional(kk_integer_box(_b_519_518), _ctx); /*optional<108>*/
  _x552 = kk_std_num_ddouble_show_fixed(_x553, _x554, _ctx); /*string*/
  kk_string_t _x559;
  kk_define_string_literal(, _s560, 1, "s")
  _x559 = kk_string_dup(_s560); /*string*/
  _x551 = kk_std_core__lp__plus__plus__1_rp_(_x552, _x559, _ctx); /*string*/
  _x548 = kk_std_core__lp__plus__plus__1_rp_(_x549, _x551, _ctx); /*string*/
  s_486 = kk_std_core__lp__plus__plus__1_rp_(_x544, _x548, _ctx); /*string*/
  kk_std_core_printsln(s_486, _ctx);
  return x;
}
 
// Measure the number of fractional seconds that it takes to evaluate `action`, and print `msg` postfixed with the
// measured time in millisecond resolution.


// lift anonymous function
struct kk_std_time_timer_print_elapsed_fun561__t {
  struct kk_function_s _base;
  kk_std_core_types__optional msg;
};
static kk_box_t kk_std_time_timer_print_elapsed_fun561(kk_function_t _fself, kk_box_t _b_521, kk_context_t* _ctx);
static kk_function_t kk_std_time_timer_new_print_elapsed_fun561(kk_std_core_types__optional msg, kk_context_t* _ctx) {
  struct kk_std_time_timer_print_elapsed_fun561__t* _self = kk_function_alloc_as(struct kk_std_time_timer_print_elapsed_fun561__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_time_timer_print_elapsed_fun561, kk_context());
  _self->msg = msg;
  return &_self->_base;
}

static kk_box_t kk_std_time_timer_print_elapsed_fun561(kk_function_t _fself, kk_box_t _b_521, kk_context_t* _ctx) {
  struct kk_std_time_timer_print_elapsed_fun561__t* _self = kk_function_as(struct kk_std_time_timer_print_elapsed_fun561__t*, _fself);
  kk_std_core_types__optional msg = _self->msg; /* optional<string> */
  kk_drop_match(_self, {kk_std_core_types__optional_dup(msg);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x562 = kk_std_core_types__tuple2__unbox(_b_521, _ctx); /*(std/time/duration/duration, 453)*/
  return kk_std_time_timer__mlift481_print_elapsed(msg, _x562, _ctx);
}

kk_box_t kk_std_time_timer_print_elapsed(kk_function_t action, kk_std_core_types__optional msg, kk_context_t* _ctx) { /* forall<a,e> (action : () -> <ndet,console|e> a, msg : optional<string>) -> <ndet,console|e> a */ 
  kk_std_core_types__tuple2_ x_489 = kk_std_time_timer_elapsed(action, _ctx); /*(std/time/duration/duration, 453)*/;
  if (kk_yielding(kk_context())) {
    kk_std_core_types__tuple2__drop(x_489, _ctx);
    return kk_std_core_hnd_yield_extend(kk_std_time_timer_new_print_elapsed_fun561(msg, _ctx), _ctx);
  }
  kk_box_t _box_x522 = x_489.fst;
  kk_box_t x0 = x_489.snd;
  kk_std_time_duration__duration t = kk_std_time_duration__duration_unbox(_box_x522, NULL);
  kk_box_dup(x0);
  kk_std_core_types__tuple2__drop(x_489, _ctx);
  kk_unit_t __ = kk_Unit;
  kk_string_t s_493;
  kk_string_t _x564;
  if (kk_std_core_types__is_Optional(msg)) {
    kk_box_t _box_x523 = msg._cons.Optional.value;
    kk_string_t _msg_238 = kk_string_unbox(_box_x523);
    kk_string_dup(_msg_238);
    kk_std_core_types__optional_drop(msg, _ctx);
    _x564 = _msg_238; /*string*/
    goto _match565;
  }
  kk_define_string_literal(, _s567, 7, "elapsed")
  _x564 = kk_string_dup(_s567); /*string*/
  _match565: ;
  kk_string_t _x568;
  kk_string_t _x569;
  kk_define_string_literal(, _s570, 1, " ")
  _x569 = kk_string_dup(_s570); /*string*/
  kk_string_t _x571;
  kk_std_core_types__optional max_prec_495 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(3)), _ctx); /*optional<int>*/;
  kk_string_t _x572;
  kk_std_num_ddouble__ddouble _x573;
  kk_std_num_ddouble__ddouble _x = t.secs;
  _x573 = _x; /*std/time/timestamp/timespan*/
  kk_std_core_types__optional _x574;
  kk_integer_t _b_528_527;
  kk_integer_t _x575;
  kk_integer_t _x576;
  if (kk_std_core_types__is_Optional(max_prec_495)) {
    kk_box_t _box_x526 = max_prec_495._cons.Optional.value;
    kk_integer_t _max_prec_1769 = kk_integer_unbox(_box_x526);
    kk_integer_dup(_max_prec_1769);
    kk_std_core_types__optional_drop(max_prec_495, _ctx);
    _x576 = _max_prec_1769; /*int*/
    goto _match577;
  }
  _x576 = kk_integer_from_small(9); /*int*/
  _match577: ;
  _x575 = kk_integer_abs(_x576,kk_context()); /*int*/
  _b_528_527 = kk_integer_neg(_x575,kk_context()); /*int*/
  _x574 = kk_std_core_types__new_Optional(kk_integer_box(_b_528_527), _ctx); /*optional<108>*/
  _x572 = kk_std_num_ddouble_show_fixed(_x573, _x574, _ctx); /*string*/
  kk_string_t _x579;
  kk_define_string_literal(, _s580, 1, "s")
  _x579 = kk_string_dup(_s580); /*string*/
  _x571 = kk_std_core__lp__plus__plus__1_rp_(_x572, _x579, _ctx); /*string*/
  _x568 = kk_std_core__lp__plus__plus__1_rp_(_x569, _x571, _ctx); /*string*/
  s_493 = kk_std_core__lp__plus__plus__1_rp_(_x564, _x568, _ctx); /*string*/
  kk_std_core_printsln(s_493, _ctx);
  return x0;
}

// initialization
void kk_std_time_timer__init(kk_context_t* _ctx){
  static bool _initialized = false;
  if (_initialized) return;
  _initialized = true;
  kk_std_core_types__init(_ctx);
  kk_std_core_hnd__init(_ctx);
  kk_std_core__init(_ctx);
  kk_std_num_double__init(_ctx);
  kk_std_num_ddouble__init(_ctx);
  kk_std_time_timestamp__init(_ctx);
  kk_std_time_duration__init(_ctx);
}
