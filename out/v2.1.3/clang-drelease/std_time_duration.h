#pragma once
#ifndef kk_std_time_duration_H
#define kk_std_time_duration_H
// Koka generated module: "std/time/duration", koka version: 2.1.3
#include <kklib.h>
#include "std_core_types.h"
#include "std_core.h"
#include "std_num_ddouble.h"
#include "std_time_timestamp.h"

// type declarations

// value type std/time/duration/duration
struct kk_std_time_duration_Duration {
  kk_std_num_ddouble__ddouble secs;
};
typedef struct kk_std_time_duration_Duration kk_std_time_duration__duration;
static inline kk_std_time_duration__duration kk_std_time_duration__new_Duration(kk_std_num_ddouble__ddouble secs, kk_context_t* _ctx){
  kk_std_time_duration__duration _con = { secs };
  return _con;
}
static inline bool kk_std_time_duration__is_Duration(kk_std_time_duration__duration x) {
  return (true);
}
static inline kk_std_time_duration__duration kk_std_time_duration__duration_dup(kk_std_time_duration__duration _x) {
  kk_std_num_ddouble__ddouble_dup(_x.secs);
  return _x;
}
static inline void kk_std_time_duration__duration_drop(kk_std_time_duration__duration _x, kk_context_t* _ctx) {
  kk_std_num_ddouble__ddouble_drop(_x.secs, _ctx);
}
static inline kk_box_t kk_std_time_duration__duration_box(kk_std_time_duration__duration _x, kk_context_t* _ctx) {
  return kk_std_num_ddouble__ddouble_box(_x.secs, _ctx);
}
static inline kk_std_time_duration__duration kk_std_time_duration__duration_unbox(kk_box_t _x, kk_context_t* _ctx) {
  return kk_std_time_duration__new_Duration(kk_std_num_ddouble__ddouble_unbox(_x, _ctx), _ctx);
}

// value declarations
 
// Automatically generated. Retrieves the `secs` constructor field of the `:duration` type.

static inline kk_std_num_ddouble__ddouble kk_std_time_duration_secs(kk_std_time_duration__duration duration1, kk_context_t* _ctx) { /* (duration : duration) -> std/time/timestamp/timespan */ 
  kk_std_num_ddouble__ddouble _x = duration1.secs;
  return _x;
}

static inline kk_std_time_duration__duration kk_std_time_duration__copy(kk_std_time_duration__duration _this, kk_std_core_types__optional secs0, kk_context_t* _ctx) { /* (duration, secs : optional<std/time/timestamp/timespan>) -> duration */ 
  kk_std_num_ddouble__ddouble _x2442;
  if (kk_std_core_types__is_Optional(secs0)) {
    kk_box_t _box_x2341 = secs0._cons.Optional.value;
    kk_std_num_ddouble__ddouble _secs_60 = kk_std_num_ddouble__ddouble_unbox(_box_x2341, NULL);
    kk_std_core_types__optional_drop(secs0, _ctx);
    _x2442 = _secs_60; /*std/time/timestamp/timespan*/
    goto _match2443;
  }
  kk_std_num_ddouble__ddouble _x = _this.secs;
  _x2442 = _x; /*std/time/timestamp/timespan*/
  _match2443: ;
  return kk_std_time_duration__new_Duration(_x2442, _ctx);
}

kk_std_core_types__order kk_std_time_duration_compare(kk_std_time_duration__duration i, kk_std_time_duration__duration j, kk_context_t* _ctx); /* (i : duration, j : duration) -> order */ 

bool kk_std_time_duration__lp__excl__eq__rp_(kk_std_time_duration__duration i, kk_std_time_duration__duration j, kk_context_t* _ctx); /* (i : duration, j : duration) -> bool */ 
 
// Convert a `:timespan` to a `:duration`. Be careful to only use
// use this on timespan's that are in TAI SI seconds!

static inline kk_std_time_duration__duration kk_std_time_duration_duration(kk_std_num_ddouble__ddouble t, kk_context_t* _ctx) { /* (t : std/time/timestamp/timespan) -> duration */ 
  return kk_std_time_duration__new_Duration(t, _ctx);
}

kk_std_time_duration__duration kk_std_time_duration_duration_1(kk_integer_t secs0, kk_std_core_types__optional frac, kk_context_t* _ctx); /* (secs : int, frac : optional<double>) -> duration */ 
 
// Create a duration from seconds as a `:double`.

static inline kk_std_time_duration__duration kk_std_time_duration_duration_2(double secs0, kk_context_t* _ctx) { /* (secs : double) -> duration */ 
  kk_std_num_ddouble__ddouble _x2470 = kk_std_time_timestamp_timespan_1(secs0, _ctx); /*std/time/timestamp/timespan*/
  return kk_std_time_duration__new_Duration(_x2470, _ctx);
}
 
// Return the duration in SI seconds.

static inline kk_std_num_ddouble__ddouble kk_std_time_duration_seconds(kk_std_time_duration__duration d, kk_context_t* _ctx) { /* (d : duration) -> std/time/timestamp/timespan */ 
  kk_std_num_ddouble__ddouble _x = d.secs;
  return _x;
}

kk_std_time_duration__duration kk_std_time_duration_seconds_1(kk_integer_t n, kk_context_t* _ctx); /* (n : int) -> duration */ 
 
// Convert a duration to a `:timespan`.

static inline kk_std_num_ddouble__ddouble kk_std_time_duration_timespan(kk_std_time_duration__duration d, kk_context_t* _ctx) { /* (d : duration) -> std/time/timestamp/timespan */ 
  kk_std_num_ddouble__ddouble _x = d.secs;
  return _x;
}
 
// Add two durations.

static inline kk_std_time_duration__duration kk_std_time_duration__lp__plus__rp_(kk_std_time_duration__duration d, kk_std_time_duration__duration e, kk_context_t* _ctx) { /* (d : duration, e : duration) -> duration */ 
  kk_std_num_ddouble__ddouble _x2484;
  kk_std_num_ddouble__ddouble _x2485;
  kk_std_num_ddouble__ddouble _x = d.secs;
  _x2485 = _x; /*std/time/timestamp/timespan*/
  kk_std_num_ddouble__ddouble _x2486;
  kk_std_num_ddouble__ddouble _x0 = e.secs;
  _x2486 = _x0; /*std/time/timestamp/timespan*/
  _x2484 = kk_std_num_ddouble__lp__plus__rp_(_x2485, _x2486, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_time_duration__new_Duration(_x2484, _ctx);
}
 
// Negate a duration.

static inline kk_std_time_duration__duration kk_std_time_duration__lp__tilde__rp_(kk_std_time_duration__duration d, kk_context_t* _ctx) { /* (d : duration) -> duration */ 
  kk_std_num_ddouble__ddouble _x2487;
  double _x2488;
  double _x2489;
  kk_std_num_ddouble__ddouble _match_2424;
  kk_std_num_ddouble__ddouble _x1 = d.secs;
  _match_2424 = _x1; /*std/time/timestamp/timespan*/
  double _x = _match_2424.hi;
  _x2489 = _x; /*double*/
  _x2488 = (-_x2489); /*double*/
  double _x2490;
  double _x2491;
  kk_std_num_ddouble__ddouble _match_2423;
  kk_std_num_ddouble__ddouble _x10 = d.secs;
  _match_2423 = _x10; /*std/time/timestamp/timespan*/
  double _x0 = _match_2423.lo;
  _x2491 = _x0; /*double*/
  _x2490 = (-_x2491); /*double*/
  _x2487 = kk_std_num_ddouble__new_Ddouble(_x2488, _x2490, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_time_duration__new_Duration(_x2487, _ctx);
}
 
// Subtract a duration from a duration.

static inline kk_std_time_duration__duration kk_std_time_duration__lp__dash__rp_(kk_std_time_duration__duration d, kk_std_time_duration__duration e, kk_context_t* _ctx) { /* (d : duration, e : duration) -> duration */ 
  kk_std_time_duration__duration e0_2276 = kk_std_time_duration__lp__tilde__rp_(e, _ctx); /*std/time/duration/duration*/;
  kk_std_num_ddouble__ddouble _x2492;
  kk_std_num_ddouble__ddouble _x2493;
  kk_std_num_ddouble__ddouble _x = d.secs;
  _x2493 = _x; /*std/time/timestamp/timespan*/
  kk_std_num_ddouble__ddouble _x2494;
  kk_std_num_ddouble__ddouble _x0 = e0_2276.secs;
  _x2494 = _x0; /*std/time/timestamp/timespan*/
  _x2492 = kk_std_num_ddouble__lp__plus__rp_(_x2493, _x2494, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_time_duration__new_Duration(_x2492, _ctx);
}

bool kk_std_time_duration__lp__eq__eq__rp_(kk_std_time_duration__duration i, kk_std_time_duration__duration j, kk_context_t* _ctx); /* (i : duration, j : duration) -> bool */ 

bool kk_std_time_duration__lp__lt__rp_(kk_std_time_duration__duration i, kk_std_time_duration__duration j, kk_context_t* _ctx); /* (i : duration, j : duration) -> bool */ 

bool kk_std_time_duration__lp__lt__eq__rp_(kk_std_time_duration__duration i, kk_std_time_duration__duration j, kk_context_t* _ctx); /* (i : duration, j : duration) -> bool */ 

bool kk_std_time_duration__lp__gt__rp_(kk_std_time_duration__duration i, kk_std_time_duration__duration j, kk_context_t* _ctx); /* (i : duration, j : duration) -> bool */ 

bool kk_std_time_duration__lp__gt__eq__rp_(kk_std_time_duration__duration i, kk_std_time_duration__duration j, kk_context_t* _ctx); /* (i : duration, j : duration) -> bool */ 

kk_std_time_duration__duration kk_std_time_duration_days(kk_integer_t n, kk_context_t* _ctx); /* (n : int) -> duration */ 

extern kk_std_time_duration__duration kk_std_time_duration_duration0;
 
// The fractional seconds of a duration as a `:double`.
// `d.seconds == d.truncate.fixed + d.fraction.fixed

static inline double kk_std_time_duration_fraction(kk_std_time_duration__duration d, kk_context_t* _ctx) { /* (d : duration) -> double */ 
  kk_std_num_ddouble__ddouble x_2293;
  kk_std_num_ddouble__ddouble y_21009;
  kk_std_num_ddouble__ddouble _x2529;
  kk_std_num_ddouble__ddouble _x0 = d.secs;
  _x2529 = _x0; /*std/time/timestamp/timespan*/
  y_21009 = kk_std_num_ddouble_truncate(_x2529, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x2530;
  kk_std_num_ddouble__ddouble _x00 = d.secs;
  _x2530 = _x00; /*std/time/timestamp/timespan*/
  kk_std_num_ddouble__ddouble _x2531 = kk_std_num_ddouble__lp__tilde__rp_(y_21009, _ctx); /*std/num/ddouble/ddouble*/
  x_2293 = kk_std_num_ddouble__lp__plus__rp_(_x2530, _x2531, _ctx); /*std/num/ddouble/ddouble*/
  double _x = x_2293.hi;
  return _x;
}

kk_std_time_duration__duration kk_std_time_duration_hours(kk_integer_t n, kk_context_t* _ctx); /* (n : int) -> duration */ 
 
// Is this a negative duration?

static inline bool kk_std_time_duration_is_neg(kk_std_time_duration__duration d, kk_context_t* _ctx) { /* (d : duration) -> bool */ 
  double _x2545;
  kk_std_num_ddouble__ddouble _match_2413;
  kk_std_num_ddouble__ddouble _x0 = d.secs;
  _match_2413 = _x0; /*std/time/timestamp/timespan*/
  double _x = _match_2413.hi;
  _x2545 = _x; /*double*/
  return (_x2545 < (0x0p+0));
}
 
// Is this a positive duration?

static inline bool kk_std_time_duration_is_pos(kk_std_time_duration__duration d, kk_context_t* _ctx) { /* (d : duration) -> bool */ 
  double _x2546;
  kk_std_num_ddouble__ddouble _match_2412;
  kk_std_num_ddouble__ddouble _x0 = d.secs;
  _match_2412 = _x0; /*std/time/timestamp/timespan*/
  double _x = _match_2412.hi;
  _x2546 = _x; /*double*/
  return (_x2546 > (0x0p+0));
}
 
// Is this a zero duration?

static inline bool kk_std_time_duration_is_zero(kk_std_time_duration__duration d, kk_context_t* _ctx) { /* (d : duration) -> bool */ 
  double _x2547;
  kk_std_num_ddouble__ddouble _match_2411;
  kk_std_num_ddouble__ddouble _x0 = d.secs;
  _match_2411 = _x0; /*std/time/timestamp/timespan*/
  double _x = _match_2411.hi;
  _x2547 = _x; /*double*/
  return (_x2547 == (0x0p+0));
}
 
// The maximum of two durations.

static inline kk_std_time_duration__duration kk_std_time_duration_max(kk_std_time_duration__duration i, kk_std_time_duration__duration j, kk_context_t* _ctx) { /* (i : duration, j : duration) -> duration */ 
  bool _match_2410 = kk_std_time_duration__lp__gt__eq__rp_(i, j, _ctx); /*bool*/;
  if (_match_2410) {
    return i;
  }
  return j;
}

kk_integer_t kk_std_time_duration_milli_seconds(kk_std_time_duration__duration d, kk_context_t* _ctx); /* (d : duration) -> int */ 

kk_std_time_duration__duration kk_std_time_duration_milli_seconds_1(kk_integer_t n, kk_context_t* _ctx); /* (n : int) -> duration */ 
 
// The minimum of two durations.

static inline kk_std_time_duration__duration kk_std_time_duration_min(kk_std_time_duration__duration i, kk_std_time_duration__duration j, kk_context_t* _ctx) { /* (i : duration, j : duration) -> duration */ 
  bool _match_2400 = kk_std_time_duration__lp__lt__eq__rp_(i, j, _ctx); /*bool*/;
  if (_match_2400) {
    return i;
  }
  return j;
}

kk_std_time_duration__duration kk_std_time_duration_minutes(kk_integer_t n, kk_context_t* _ctx); /* (n : int) -> duration */ 

kk_integer_t kk_std_time_duration_nano_seconds(kk_std_time_duration__duration d, kk_context_t* _ctx); /* (d : duration) -> int */ 

kk_string_t kk_std_time_duration_show(kk_std_time_duration__duration d, kk_std_core_types__optional max_prec, kk_context_t* _ctx); /* (d : duration, max-prec : optional<int>) -> string */ 
 
// Convert a duration to a `:timespan`.

static inline kk_std_time_timestamp__timestamp kk_std_time_duration_timestamp(kk_std_time_duration__duration d, kk_context_t* _ctx) { /* (d : duration) -> std/time/timestamp/timestamp */ 
  kk_std_num_ddouble__ddouble _x2611;
  kk_std_num_ddouble__ddouble _x = d.secs;
  _x2611 = _x; /*std/time/timestamp/timespan*/
  int32_t _x2612;
  kk_integer_t _x2613;
  kk_std_core_types__optional _match_2394 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
  if (kk_std_core_types__is_Optional(_match_2394)) {
    kk_box_t _box_x2378 = _match_2394._cons.Optional.value;
    kk_integer_t _leap_492 = kk_integer_unbox(_box_x2378);
    kk_integer_dup(_leap_492);
    kk_std_core_types__optional_drop(_match_2394, _ctx);
    _x2613 = _leap_492; /*int*/
    goto _match2614;
  }
  _x2613 = kk_integer_from_small(0); /*int*/
  _match2614: ;
  _x2612 = kk_std_core_int32(_x2613, _ctx); /*int32*/
  return kk_std_time_timestamp__new_Timestamp(_x2611, _x2612, _ctx);
}
 
// The whole seconds (in some time unit) of the duration as `:int``. Rounds towards zero.

static inline kk_integer_t kk_std_time_duration_truncate(kk_std_time_duration__duration d, kk_context_t* _ctx) { /* (d : duration) -> int */ 
  kk_std_num_ddouble__ddouble _x2616;
  bool _match_2393;
  kk_std_num_ddouble__ddouble _x2617;
  kk_std_num_ddouble__ddouble _x = d.secs;
  _x2617 = _x; /*std/time/timestamp/timespan*/
  _match_2393 = kk_std_num_ddouble_is_neg(_x2617, _ctx); /*bool*/
  if (_match_2393) {
    kk_std_num_ddouble__ddouble _x2618;
    kk_std_num_ddouble__ddouble _x0 = d.secs;
    _x2618 = _x0; /*std/time/timestamp/timespan*/
    _x2616 = kk_std_num_ddouble_ceiling(_x2618, _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    kk_std_num_ddouble__ddouble _x2619;
    kk_std_num_ddouble__ddouble _x1 = d.secs;
    _x2619 = _x1; /*std/time/timestamp/timespan*/
    _x2616 = kk_std_num_ddouble_floor(_x2619, _ctx); /*std/num/ddouble/ddouble*/
  }
  return kk_std_num_ddouble_int(_x2616, kk_std_core_types__new_None(_ctx), _ctx);
}
 
// Convert a `:timestamp` to a `:duration`. Be careful to only use
// use this on timestamp's that are in TAI SI seconds and do not
// contain leap seconds!

static inline kk_std_time_duration__duration kk_std_time_duration_unsafe_duration(kk_std_time_timestamp__timestamp t, kk_context_t* _ctx) { /* (t : std/time/timestamp/timestamp) -> duration */ 
  kk_std_num_ddouble__ddouble _x2620 = kk_std_time_timestamp_unsafe_timespan_withleap(t, _ctx); /*std/time/timestamp/timespan*/
  return kk_std_time_duration__new_Duration(_x2620, _ctx);
}

kk_std_time_duration__duration kk_std_time_duration_weeks(kk_integer_t n, kk_context_t* _ctx); /* (n : int) -> duration */ 

kk_std_time_duration__duration kk_std_time_duration_years(kk_integer_t n, kk_context_t* _ctx); /* (n : int) -> duration */ 

extern kk_std_time_duration__duration kk_std_time_duration_zero;

void kk_std_time_duration__init(kk_context_t* _ctx);

#endif // header
