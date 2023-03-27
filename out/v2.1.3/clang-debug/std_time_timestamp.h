#pragma once
#ifndef kk_std_time_timestamp_H
#define kk_std_time_timestamp_H
// Koka generated module: "std/time/timestamp", koka version: 2.1.3
#include <kklib.h>
#include "std_core_types.h"
#include "std_core.h"
#include "std_num_int32.h"
#include "std_num_ddouble.h"
#include "std_time_date.h"

// type declarations

// value type std/time/timestamp/timestamp
struct kk_std_time_timestamp_Timestamp {
  kk_std_num_ddouble__ddouble since;
  int32_t leap32;
};
typedef struct kk_std_time_timestamp_Timestamp kk_std_time_timestamp__timestamp;
static inline kk_std_time_timestamp__timestamp kk_std_time_timestamp__new_Timestamp(kk_std_num_ddouble__ddouble since, int32_t leap32, kk_context_t* _ctx){
  kk_std_time_timestamp__timestamp _con;
  _con.since = since;
  _con.leap32 = leap32;
  return _con;
}
static inline bool kk_std_time_timestamp__is_Timestamp(kk_std_time_timestamp__timestamp x) {
  return (true);
}
static inline kk_std_time_timestamp__timestamp kk_std_time_timestamp__timestamp_dup(kk_std_time_timestamp__timestamp _x) {
  kk_std_num_ddouble__ddouble_dup(_x.since);
  return _x;
}
static inline void kk_std_time_timestamp__timestamp_drop(kk_std_time_timestamp__timestamp _x, kk_context_t* _ctx) {
  kk_std_num_ddouble__ddouble_drop(_x.since, _ctx);
}
static inline kk_box_t kk_std_time_timestamp__timestamp_box(kk_std_time_timestamp__timestamp _x, kk_context_t* _ctx) {
  kk_box_t _box;
  kk_valuetype_box(kk_std_time_timestamp__timestamp, _box, _x, 0 /* scan count */, _ctx);
  return _box;
}
static inline kk_std_time_timestamp__timestamp kk_std_time_timestamp__timestamp_unbox(kk_box_t _x, kk_context_t* _ctx) {
  kk_boxed_value_t _p;
  kk_std_time_timestamp__timestamp _unbox;
  kk_valuetype_unbox_(kk_std_time_timestamp__timestamp, _p, _unbox, _x, _ctx);
  if (_ctx!=NULL && _p!=NULL) {
    if (kk_basetype_is_unique(_p)) { kk_basetype_free(_p); } else {
      kk_std_time_timestamp__timestamp_dup(_unbox);
      kk_basetype_decref(_p, _ctx);
    }
  }
  return _unbox;
}

// value declarations
 
// Automatically generated. Retrieves the `since` constructor field of the `:timestamp` type.

static inline kk_std_num_ddouble__ddouble kk_std_time_timestamp_since(kk_std_time_timestamp__timestamp timestamp1, kk_context_t* _ctx) { /* (timestamp : timestamp) -> timespan */ 
  kk_std_num_ddouble__ddouble _x = timestamp1.since;
  return _x;
}
 
// Automatically generated. Retrieves the `leap32` constructor field of the `:timestamp` type.

static inline int32_t kk_std_time_timestamp_leap32(kk_std_time_timestamp__timestamp timestamp1, kk_context_t* _ctx) { /* (timestamp : timestamp) -> int32 */ 
  kk_std_num_ddouble__ddouble _pat0 = timestamp1.since;
  int32_t _x = timestamp1.leap32;
  return _x;
}

static inline kk_std_time_timestamp__timestamp kk_std_time_timestamp__copy(kk_std_time_timestamp__timestamp _this, kk_std_core_types__optional since0, kk_std_core_types__optional leap320, kk_context_t* _ctx) { /* (timestamp, since : optional<timespan>, leap32 : optional<int32>) -> timestamp */ 
  kk_std_num_ddouble__ddouble _x3966;
  if (kk_std_core_types__is_Optional(since0)) {
    kk_box_t _box_x3842 = since0._cons.Optional.value;
    kk_std_num_ddouble__ddouble _since_78 = kk_std_num_ddouble__ddouble_unbox(_box_x3842, NULL);
    kk_std_core_types__optional_drop(since0, _ctx);
    _x3966 = _since_78; /*std/time/timestamp/timespan*/
    goto _match3967;
  }
  kk_std_num_ddouble__ddouble _x = _this.since;
  _x3966 = _x; /*std/time/timestamp/timespan*/
  _match3967: ;
  int32_t _x3969;
  if (kk_std_core_types__is_Optional(leap320)) {
    kk_box_t _box_x3843 = leap320._cons.Optional.value;
    int32_t _leap32_84 = kk_int32_unbox(_box_x3843, NULL);
    kk_std_core_types__optional_drop(leap320, _ctx);
    _x3969 = _leap32_84; /*int32*/
    goto _match3970;
  }
  kk_std_num_ddouble__ddouble _pat01 = _this.since;
  int32_t _x0 = _this.leap32;
  _x3969 = _x0; /*int32*/
  _match3970: ;
  return kk_std_time_timestamp__new_Timestamp(_x3966, _x3969, _ctx);
}

static inline kk_integer_t kk_std_time_timestamp_leap(kk_std_time_timestamp__timestamp t, kk_context_t* _ctx) { /* (t : timestamp) -> int */ 
  int32_t _x3972;
  kk_std_num_ddouble__ddouble _pat0 = t.since;
  int32_t _x = t.leap32;
  _x3972 = _x; /*int32*/
  return kk_integer_from_int(_x3972,kk_context());
}
 
// Seconds in a solar day, 86400.

extern kk_integer_t kk_std_time_timestamp_isolar_secs_per_day;
 
// Divide using `div` to allow for different timespan representations

static inline kk_std_num_ddouble__ddouble kk_std_time_timestamp_div(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_std_core_types__optional prec, kk_context_t* _ctx) { /* (x : timespan, y : timespan, prec : optional<int>) -> timespan */ 
  kk_std_core_types__optional_drop(prec, _ctx);
  return kk_std_num_ddouble__lp__fs__rp_(x, y, _ctx);
}
 
// The time span since 2000-01-01 for time scales that do not have
// leap seconds and where every day is 86400s. For time scales
// with leap seconds, this effectively ignores any leap seconds.

static inline kk_std_num_ddouble__ddouble kk_std_time_timestamp_timespan_noleap(kk_std_time_timestamp__timestamp ts, kk_context_t* _ctx) { /* (ts : timestamp) -> timespan */ 
  kk_std_num_ddouble__ddouble _x = ts.since;
  return _x;
}
 
// A zero-valued timespan.

extern kk_std_num_ddouble__ddouble kk_std_time_timestamp_timespan0;

kk_std_core_types__order kk_std_time_timestamp_compare(kk_std_time_timestamp__timestamp i, kk_std_time_timestamp__timestamp j, kk_context_t* _ctx); /* (i : timestamp, j : timestamp) -> order */ 

bool kk_std_time_timestamp__lp__excl__eq__rp_(kk_std_time_timestamp__timestamp i, kk_std_time_timestamp__timestamp j, kk_context_t* _ctx); /* (i : timestamp, j : timestamp) -> bool */ 
 
// Add a time span to a time stamp.

static inline kk_std_time_timestamp__timestamp kk_std_time_timestamp__lp__plus__rp_(kk_std_time_timestamp__timestamp ts, kk_std_num_ddouble__ddouble t, kk_context_t* _ctx) { /* (ts : timestamp, t : timespan) -> timestamp */ 
  kk_std_num_ddouble__ddouble _x3987;
  kk_std_num_ddouble__ddouble _x3988;
  kk_std_num_ddouble__ddouble _x = ts.since;
  _x3988 = _x; /*std/time/timestamp/timespan*/
  _x3987 = kk_std_num_ddouble__lp__plus__rp_(_x3988, t, _ctx); /*std/num/ddouble/ddouble*/
  int32_t _x3989;
  kk_std_num_ddouble__ddouble _pat00 = ts.since;
  int32_t _x0 = ts.leap32;
  _x3989 = _x0; /*int32*/
  return kk_std_time_timestamp__new_Timestamp(_x3987, _x3989, _ctx);
}
 
// Create a time stamp from a `:timespan` since 2000-01-01 and possible leap seconds.

static inline kk_std_time_timestamp__timestamp kk_std_time_timestamp_timestamp(kk_std_num_ddouble__ddouble t, kk_std_core_types__optional leap0, kk_context_t* _ctx) { /* (t : timespan, leap : optional<int>) -> timestamp */ 
  int32_t _x3990;
  kk_integer_t _x3991;
  if (kk_std_core_types__is_Optional(leap0)) {
    kk_box_t _box_x3844 = leap0._cons.Optional.value;
    kk_integer_t _leap_492 = kk_integer_unbox(_box_x3844);
    kk_integer_dup(_leap_492);
    kk_std_core_types__optional_drop(leap0, _ctx);
    _x3991 = _leap_492; /*int*/
    goto _match3992;
  }
  _x3991 = kk_integer_from_small(0); /*int*/
  _match3992: ;
  _x3990 = kk_std_core_int32(_x3991, _ctx); /*int32*/
  return kk_std_time_timestamp__new_Timestamp(t, _x3990, _ctx);
}

kk_std_time_timestamp__timestamp kk_std_time_timestamp_timestamp_1(kk_integer_t t, kk_std_core_types__optional frac, kk_std_core_types__optional leap0, kk_context_t* _ctx); /* (t : int, frac : optional<double>, leap : optional<int>) -> timestamp */ 
 
// Subtract a time span from a time stamp.

static inline kk_std_time_timestamp__timestamp kk_std_time_timestamp__lp__dash__rp_(kk_std_time_timestamp__timestamp ts, kk_std_num_ddouble__ddouble t, kk_context_t* _ctx) { /* (ts : timestamp, t : timespan) -> timestamp */ 
  kk_std_num_ddouble__ddouble _x4007;
  kk_std_num_ddouble__ddouble _x4008;
  kk_std_num_ddouble__ddouble _x = ts.since;
  _x4008 = _x; /*std/time/timestamp/timespan*/
  kk_std_num_ddouble__ddouble _x4009 = kk_std_num_ddouble__lp__tilde__rp_(t, _ctx); /*std/num/ddouble/ddouble*/
  _x4007 = kk_std_num_ddouble__lp__plus__rp_(_x4008, _x4009, _ctx); /*std/num/ddouble/ddouble*/
  int32_t _x4010;
  kk_std_num_ddouble__ddouble _pat00 = ts.since;
  int32_t _x0 = ts.leap32;
  _x4010 = _x0; /*int32*/
  return kk_std_time_timestamp__new_Timestamp(_x4007, _x4010, _ctx);
}

bool kk_std_time_timestamp__lp__eq__eq__rp_(kk_std_time_timestamp__timestamp i, kk_std_time_timestamp__timestamp j, kk_context_t* _ctx); /* (i : timestamp, j : timestamp) -> bool */ 

bool kk_std_time_timestamp__lp__lt__rp_(kk_std_time_timestamp__timestamp i, kk_std_time_timestamp__timestamp j, kk_context_t* _ctx); /* (i : timestamp, j : timestamp) -> bool */ 

bool kk_std_time_timestamp__lp__lt__eq__rp_(kk_std_time_timestamp__timestamp i, kk_std_time_timestamp__timestamp j, kk_context_t* _ctx); /* (i : timestamp, j : timestamp) -> bool */ 

bool kk_std_time_timestamp__lp__gt__rp_(kk_std_time_timestamp__timestamp i, kk_std_time_timestamp__timestamp j, kk_context_t* _ctx); /* (i : timestamp, j : timestamp) -> bool */ 

bool kk_std_time_timestamp__lp__gt__eq__rp_(kk_std_time_timestamp__timestamp i, kk_std_time_timestamp__timestamp j, kk_context_t* _ctx); /* (i : timestamp, j : timestamp) -> bool */ 

kk_std_num_ddouble__ddouble kk_std_time_timestamp_timespan(kk_integer_t seconds, kk_std_core_types__optional frac, kk_context_t* _ctx); /* (seconds : int, frac : optional<double>) -> timespan */ 

static inline kk_std_num_ddouble__ddouble kk_std_time_timestamp_timespan_1(double _x14039, kk_context_t* _ctx) { /* (secs : double) -> timespan */ 
  return kk_std_num_ddouble_ddouble(_x14039, _ctx);
}
 
// Timespan from a `:ddouble`. Just for convenience as `:timespan` is an alias

static inline kk_std_num_ddouble__ddouble kk_std_time_timestamp_timespan_2(kk_std_num_ddouble__ddouble secs, kk_context_t* _ctx) { /* (secs : std/num/ddouble/ddouble) -> timespan */ 
  return secs;
}

kk_std_time_timestamp__timestamp kk_std_time_timestamp_add_days(kk_std_time_timestamp__timestamp ts, kk_integer_t days0, kk_context_t* _ctx); /* (ts : timestamp, days : int) -> timestamp */ 

kk_std_time_timestamp__timestamp kk_std_time_timestamp_add_leap_seconds(kk_std_time_timestamp__timestamp ts, kk_std_num_ddouble__ddouble leaps, kk_context_t* _ctx); /* (ts : timestamp, leaps : timespan) -> timestamp */ 

kk_std_core_types__tuple2_ kk_std_time_timestamp_days_seconds(kk_std_time_timestamp__timestamp ts, kk_context_t* _ctx); /* (ts : timestamp) -> (int, std/num/ddouble/ddouble) */ 

static inline kk_integer_t kk_std_time_timestamp_days(kk_std_time_timestamp__timestamp ts, kk_context_t* _ctx) { /* (ts : timestamp) -> int */ 
  kk_std_core_types__tuple2_ _this_3806 = kk_std_time_timestamp_days_seconds(ts, _ctx); /*(int, std/num/ddouble/ddouble)*/;
  kk_box_t _box_x3864 = _this_3806.fst;
  kk_box_t _box_x3865 = _this_3806.snd;
  kk_integer_t _x = kk_integer_unbox(_box_x3864);
  kk_integer_dup(_x);
  kk_std_core_types__tuple2__drop(_this_3806, _ctx);
  return _x;
}

kk_std_core_types__tuple2_ kk_std_time_timestamp_days_clock(kk_std_time_timestamp__timestamp ts, kk_context_t* _ctx); /* (ts : timestamp) -> (int, std/time/date/clock) */ 
 
// The maximum of two timestamps.

static inline kk_std_time_timestamp__timestamp kk_std_time_timestamp_max(kk_std_time_timestamp__timestamp i, kk_std_time_timestamp__timestamp j, kk_context_t* _ctx) { /* (i : timestamp, j : timestamp) -> timestamp */ 
  bool _match_3929 = kk_std_time_timestamp__lp__gt__eq__rp_(i, j, _ctx); /*bool*/;
  if (_match_3929) {
    return i;
  }
  return j;
}
 
// The minimum of two timestamps.

static inline kk_std_time_timestamp__timestamp kk_std_time_timestamp_min(kk_std_time_timestamp__timestamp i, kk_std_time_timestamp__timestamp j, kk_context_t* _ctx) { /* (i : timestamp, j : timestamp) -> timestamp */ 
  bool _match_3928 = kk_std_time_timestamp__lp__lt__eq__rp_(i, j, _ctx); /*bool*/;
  if (_match_3928) {
    return i;
  }
  return j;
}

kk_std_time_timestamp__timestamp kk_std_time_timestamp_round_to_prec(kk_std_time_timestamp__timestamp t, kk_integer_t prec, kk_context_t* _ctx); /* (t : timestamp, prec : int) -> timestamp */ 

static inline kk_std_num_ddouble__ddouble kk_std_time_timestamp_seconds_into_day(kk_std_time_timestamp__timestamp ts, kk_context_t* _ctx) { /* (ts : timestamp) -> std/num/ddouble/ddouble */ 
  kk_std_num_ddouble__ddouble _x4105;
  kk_std_core_types__tuple2_ _this_3811 = kk_std_time_timestamp_days_seconds(ts, _ctx); /*(int, std/num/ddouble/ddouble)*/;
  kk_box_t _box_x3872 = _this_3811.fst;
  kk_box_t _box_x3873 = _this_3811.snd;
  kk_std_num_ddouble__ddouble _x = kk_std_num_ddouble__ddouble_unbox(_box_x3873, NULL);
  kk_std_core_types__tuple2__drop(_this_3811, _ctx);
  _x4105 = _x; /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x4108;
  kk_integer_t i_3812 = kk_std_time_timestamp_leap(ts, _ctx); /*int*/;
  _x4108 = kk_std_num_ddouble_ddouble_int_exp(i_3812, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__lp__plus__rp_(_x4105, _x4108, _ctx);
}

extern kk_std_num_ddouble__ddouble kk_std_time_timestamp_solar_secs_per_day;

kk_std_time_timestamp__timestamp kk_std_time_timestamp_timestamp_days(kk_integer_t days0, kk_std_core_types__optional secs, kk_std_core_types__optional leap0, kk_context_t* _ctx); /* (days : int, secs : optional<timespan>, leap : optional<int>) -> timestamp */ 

extern kk_std_time_timestamp__timestamp kk_std_time_timestamp_timestamp0;

kk_string_t kk_std_time_timestamp_ts_show(kk_std_time_timestamp__timestamp ts, kk_std_core_types__optional max_prec, kk_std_core_types__optional secs_width, kk_std_core_types__optional unit, kk_context_t* _ctx); /* (ts : timestamp, max-prec : optional<int>, secs-width : optional<int>, unit : optional<string>) -> string */ 

kk_string_t kk_std_time_timestamp_ts_show_days(kk_std_time_timestamp__timestamp ts, kk_std_core_types__optional prec, kk_context_t* _ctx); /* (ts : timestamp, prec : optional<int>) -> string */ 

kk_std_num_ddouble__ddouble kk_std_time_timestamp_unsafe_timespan_withleap(kk_std_time_timestamp__timestamp ts, kk_context_t* _ctx); /* (ts : timestamp) -> timespan */ 

void kk_std_time_timestamp__init(kk_context_t* _ctx);

#endif // header
