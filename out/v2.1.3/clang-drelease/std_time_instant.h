#pragma once
#ifndef kk_std_time_instant_H
#define kk_std_time_instant_H
// Koka generated module: "std/time/instant", koka version: 2.1.3
#include <kklib.h>
#include "std_core_types.h"
#include "std_core.h"
#include "std_num_ddouble.h"
#include "std_time_date.h"
#include "std_time_timestamp.h"
#include "std_time_duration.h"

// type declarations

// type std/time/instant/timescale
struct kk_std_time_instant__timescale_s {
  kk_block_t _block;
};
typedef struct kk_std_time_instant__timescale_s* kk_std_time_instant__timescale;
struct kk_std_time_instant_Timescale {
  struct kk_std_time_instant__timescale_s _base;
  kk_string_t name;
  kk_string_t unit;
  kk_function_t from_tai;
  kk_function_t to_tai;
  kk_std_core_types__maybe mb_seconds_in_day;
  kk_std_core_types__maybe mb_to_mjd2000;
  kk_std_core_types__maybe mb_from_mjd2000;
};
static inline kk_std_time_instant__timescale kk_std_time_instant__base_Timescale(struct kk_std_time_instant_Timescale* _x){
  return &_x->_base;
}
static inline kk_std_time_instant__timescale kk_std_time_instant__new_Timescale(kk_reuse_t _at, kk_string_t name, kk_string_t unit, kk_function_t from_tai, kk_function_t to_tai, kk_std_core_types__maybe mb_seconds_in_day, kk_std_core_types__maybe mb_to_mjd2000, kk_std_core_types__maybe mb_from_mjd2000, kk_context_t* _ctx){
  struct kk_std_time_instant_Timescale* _con = kk_block_alloc_at_as(struct kk_std_time_instant_Timescale, _at, 10 /* scan count */, (kk_tag_t)(1), _ctx);
  _con->name = name;
  _con->unit = unit;
  _con->from_tai = from_tai;
  _con->to_tai = to_tai;
  _con->mb_seconds_in_day = mb_seconds_in_day;
  _con->mb_to_mjd2000 = mb_to_mjd2000;
  _con->mb_from_mjd2000 = mb_from_mjd2000;
  return kk_std_time_instant__base_Timescale(_con);
}
static inline struct kk_std_time_instant_Timescale* kk_std_time_instant__as_Timescale(kk_std_time_instant__timescale x) {
  return kk_basetype_as_assert(struct kk_std_time_instant_Timescale*, x, (kk_tag_t)(1) /* _tag */);
}
static inline bool kk_std_time_instant__is_Timescale(kk_std_time_instant__timescale x) {
  return (true);
}
static inline kk_std_time_instant__timescale kk_std_time_instant__timescale_dup(kk_std_time_instant__timescale _x) {
  return kk_basetype_dup_as(kk_std_time_instant__timescale, _x);
}
static inline void kk_std_time_instant__timescale_drop(kk_std_time_instant__timescale _x, kk_context_t* _ctx) {
  kk_basetype_drop(_x, _ctx);
}
static inline bool kk_std_time_instant__timescale_is_unique(kk_std_time_instant__timescale _x) {
  return kk_basetype_is_unique(_x);
}
static inline void kk_std_time_instant__timescale_free(kk_std_time_instant__timescale _x) {
  kk_basetype_free(_x);
}
static inline void kk_std_time_instant__timescale_decref(kk_std_time_instant__timescale _x, kk_context_t* _ctx) {
  kk_basetype_decref(_x, _ctx);
}
static inline kk_reuse_t kk_std_time_instant__timescale_dropn_reuse(kk_std_time_instant__timescale _x, size_t _scan_fsize, kk_context_t* _ctx) {
  return kk_basetype_dropn_reuse(_x, _scan_fsize, _ctx);
}
static inline void kk_std_time_instant__timescale_dropn(kk_std_time_instant__timescale _x, size_t _scan_fsize, kk_context_t* _ctx) {
  kk_basetype_dropn(_x, _scan_fsize, _ctx);
}
static inline kk_reuse_t kk_std_time_instant__timescale_reuse(kk_std_time_instant__timescale _x) {
  return kk_basetype_reuse(_x);
}
static inline kk_std_time_instant__timescale kk_std_time_instant__timescale_hole() {
  return (kk_std_time_instant__timescale)(1);
}
static inline kk_box_t kk_std_time_instant__timescale_box(kk_std_time_instant__timescale _x, kk_context_t* _ctx) {
  return kk_basetype_box(_x);
}
static inline kk_std_time_instant__timescale kk_std_time_instant__timescale_unbox(kk_box_t _x, kk_context_t* _ctx) {
  return kk_basetype_unbox_as(kk_std_time_instant__timescale, _x);
}

// type std/time/instant/instant
struct kk_std_time_instant__instant_s {
  kk_block_t _block;
};
typedef struct kk_std_time_instant__instant_s* kk_std_time_instant__instant;
struct kk_std_time_instant_Instant {
  struct kk_std_time_instant__instant_s _base;
  kk_std_time_instant__timescale ts;
  kk_std_time_timestamp__timestamp since;
};
static inline kk_std_time_instant__instant kk_std_time_instant__base_Instant(struct kk_std_time_instant_Instant* _x){
  return &_x->_base;
}
static inline kk_std_time_instant__instant kk_std_time_instant__new_Instant(kk_reuse_t _at, kk_std_time_timestamp__timestamp since, kk_std_time_instant__timescale ts, kk_context_t* _ctx){
  struct kk_std_time_instant_Instant* _con = kk_block_alloc_at_as(struct kk_std_time_instant_Instant, _at, 1 /* scan count */, (kk_tag_t)(1), _ctx);
  _con->ts = ts;
  _con->since = since;
  return kk_std_time_instant__base_Instant(_con);
}
static inline struct kk_std_time_instant_Instant* kk_std_time_instant__as_Instant(kk_std_time_instant__instant x) {
  return kk_basetype_as_assert(struct kk_std_time_instant_Instant*, x, (kk_tag_t)(1) /* _tag */);
}
static inline bool kk_std_time_instant__is_Instant(kk_std_time_instant__instant x) {
  return (true);
}
static inline kk_std_time_instant__instant kk_std_time_instant__instant_dup(kk_std_time_instant__instant _x) {
  return kk_basetype_dup_as(kk_std_time_instant__instant, _x);
}
static inline void kk_std_time_instant__instant_drop(kk_std_time_instant__instant _x, kk_context_t* _ctx) {
  kk_basetype_drop(_x, _ctx);
}
static inline bool kk_std_time_instant__instant_is_unique(kk_std_time_instant__instant _x) {
  return kk_basetype_is_unique(_x);
}
static inline void kk_std_time_instant__instant_free(kk_std_time_instant__instant _x) {
  kk_basetype_free(_x);
}
static inline void kk_std_time_instant__instant_decref(kk_std_time_instant__instant _x, kk_context_t* _ctx) {
  kk_basetype_decref(_x, _ctx);
}
static inline kk_reuse_t kk_std_time_instant__instant_dropn_reuse(kk_std_time_instant__instant _x, size_t _scan_fsize, kk_context_t* _ctx) {
  return kk_basetype_dropn_reuse(_x, _scan_fsize, _ctx);
}
static inline void kk_std_time_instant__instant_dropn(kk_std_time_instant__instant _x, size_t _scan_fsize, kk_context_t* _ctx) {
  kk_basetype_dropn(_x, _scan_fsize, _ctx);
}
static inline kk_reuse_t kk_std_time_instant__instant_reuse(kk_std_time_instant__instant _x) {
  return kk_basetype_reuse(_x);
}
static inline kk_std_time_instant__instant kk_std_time_instant__instant_hole() {
  return (kk_std_time_instant__instant)(1);
}
static inline kk_box_t kk_std_time_instant__instant_box(kk_std_time_instant__instant _x, kk_context_t* _ctx) {
  return kk_basetype_box(_x);
}
static inline kk_std_time_instant__instant kk_std_time_instant__instant_unbox(kk_box_t _x, kk_context_t* _ctx) {
  return kk_basetype_unbox_as(kk_std_time_instant__instant, _x);
}

// value declarations
 
// Automatically generated. Retrieves the `name` constructor field of the `:timescale` type.

static inline kk_string_t kk_std_time_instant_name(kk_std_time_instant__timescale timescale0, kk_context_t* _ctx) { /* (timescale : timescale) -> string */ 
  struct kk_std_time_instant_Timescale* _con5335 = kk_std_time_instant__as_Timescale(timescale0);
  kk_string_t _x = _con5335->name;
  kk_string_t _pat0 = _con5335->unit;
  kk_function_t _pat1 = _con5335->from_tai;
  kk_function_t _pat2 = _con5335->to_tai;
  kk_std_core_types__maybe _pat3 = _con5335->mb_seconds_in_day;
  kk_std_core_types__maybe _pat4 = _con5335->mb_to_mjd2000;
  kk_std_core_types__maybe _pat5 = _con5335->mb_from_mjd2000;
  if (kk_std_time_instant__timescale_is_unique(timescale0)) {
    kk_std_core_types__maybe_drop(_pat5, _ctx);
    kk_std_core_types__maybe_drop(_pat4, _ctx);
    kk_std_core_types__maybe_drop(_pat3, _ctx);
    kk_function_drop(_pat2, _ctx);
    kk_function_drop(_pat1, _ctx);
    kk_string_drop(_pat0, _ctx);
    kk_std_time_instant__timescale_free(timescale0);
  }
  else {
    kk_string_dup(_x);
    kk_std_time_instant__timescale_decref(timescale0, _ctx);
  }
  return _x;
}
 
// Automatically generated. Retrieves the `unit` constructor field of the `:timescale` type.

static inline kk_string_t kk_std_time_instant_unit(kk_std_time_instant__timescale timescale0, kk_context_t* _ctx) { /* (timescale : timescale) -> string */ 
  struct kk_std_time_instant_Timescale* _con5336 = kk_std_time_instant__as_Timescale(timescale0);
  kk_string_t _pat0 = _con5336->name;
  kk_string_t _x = _con5336->unit;
  kk_function_t _pat1 = _con5336->from_tai;
  kk_function_t _pat2 = _con5336->to_tai;
  kk_std_core_types__maybe _pat3 = _con5336->mb_seconds_in_day;
  kk_std_core_types__maybe _pat4 = _con5336->mb_to_mjd2000;
  kk_std_core_types__maybe _pat5 = _con5336->mb_from_mjd2000;
  if (kk_std_time_instant__timescale_is_unique(timescale0)) {
    kk_std_core_types__maybe_drop(_pat5, _ctx);
    kk_std_core_types__maybe_drop(_pat4, _ctx);
    kk_std_core_types__maybe_drop(_pat3, _ctx);
    kk_function_drop(_pat2, _ctx);
    kk_function_drop(_pat1, _ctx);
    kk_string_drop(_pat0, _ctx);
    kk_std_time_instant__timescale_free(timescale0);
  }
  else {
    kk_string_dup(_x);
    kk_std_time_instant__timescale_decref(timescale0, _ctx);
  }
  return _x;
}
 
// Automatically generated. Retrieves the `from-tai` constructor field of the `:timescale` type.

static inline kk_function_t kk_std_time_instant_from_tai(kk_std_time_instant__timescale timescale0, kk_context_t* _ctx) { /* (timescale : timescale) -> ((std/time/duration/duration) -> std/time/timestamp/timestamp) */ 
  struct kk_std_time_instant_Timescale* _con5337 = kk_std_time_instant__as_Timescale(timescale0);
  kk_string_t _pat0 = _con5337->name;
  kk_string_t _pat1 = _con5337->unit;
  kk_function_t _x = _con5337->from_tai;
  kk_function_t _pat2 = _con5337->to_tai;
  kk_std_core_types__maybe _pat3 = _con5337->mb_seconds_in_day;
  kk_std_core_types__maybe _pat4 = _con5337->mb_to_mjd2000;
  kk_std_core_types__maybe _pat5 = _con5337->mb_from_mjd2000;
  if (kk_std_time_instant__timescale_is_unique(timescale0)) {
    kk_std_core_types__maybe_drop(_pat5, _ctx);
    kk_std_core_types__maybe_drop(_pat4, _ctx);
    kk_std_core_types__maybe_drop(_pat3, _ctx);
    kk_function_drop(_pat2, _ctx);
    kk_string_drop(_pat1, _ctx);
    kk_string_drop(_pat0, _ctx);
    kk_std_time_instant__timescale_free(timescale0);
  }
  else {
    kk_function_dup(_x);
    kk_std_time_instant__timescale_decref(timescale0, _ctx);
  }
  return _x;
}
 
// Automatically generated. Retrieves the `to-tai` constructor field of the `:timescale` type.

static inline kk_function_t kk_std_time_instant_to_tai(kk_std_time_instant__timescale timescale0, kk_context_t* _ctx) { /* (timescale : timescale) -> ((std/time/timestamp/timestamp) -> std/time/duration/duration) */ 
  struct kk_std_time_instant_Timescale* _con5338 = kk_std_time_instant__as_Timescale(timescale0);
  kk_string_t _pat0 = _con5338->name;
  kk_string_t _pat1 = _con5338->unit;
  kk_function_t _pat2 = _con5338->from_tai;
  kk_function_t _x = _con5338->to_tai;
  kk_std_core_types__maybe _pat3 = _con5338->mb_seconds_in_day;
  kk_std_core_types__maybe _pat4 = _con5338->mb_to_mjd2000;
  kk_std_core_types__maybe _pat5 = _con5338->mb_from_mjd2000;
  if (kk_std_time_instant__timescale_is_unique(timescale0)) {
    kk_std_core_types__maybe_drop(_pat5, _ctx);
    kk_std_core_types__maybe_drop(_pat4, _ctx);
    kk_std_core_types__maybe_drop(_pat3, _ctx);
    kk_function_drop(_pat2, _ctx);
    kk_string_drop(_pat1, _ctx);
    kk_string_drop(_pat0, _ctx);
    kk_std_time_instant__timescale_free(timescale0);
  }
  else {
    kk_function_dup(_x);
    kk_std_time_instant__timescale_decref(timescale0, _ctx);
  }
  return _x;
}
 
// Automatically generated. Retrieves the `mb-seconds-in-day` constructor field of the `:timescale` type.

static inline kk_std_core_types__maybe kk_std_time_instant_mb_seconds_in_day(kk_std_time_instant__timescale timescale0, kk_context_t* _ctx) { /* (timescale : timescale) -> maybe<(t : std/time/timestamp/timestamp) -> std/time/timestamp/timespan> */ 
  struct kk_std_time_instant_Timescale* _con5339 = kk_std_time_instant__as_Timescale(timescale0);
  kk_string_t _pat0 = _con5339->name;
  kk_string_t _pat1 = _con5339->unit;
  kk_function_t _pat2 = _con5339->from_tai;
  kk_function_t _pat3 = _con5339->to_tai;
  kk_std_core_types__maybe _x = _con5339->mb_seconds_in_day;
  kk_std_core_types__maybe _pat4 = _con5339->mb_to_mjd2000;
  kk_std_core_types__maybe _pat5 = _con5339->mb_from_mjd2000;
  if (kk_std_time_instant__timescale_is_unique(timescale0)) {
    kk_std_core_types__maybe_drop(_pat5, _ctx);
    kk_std_core_types__maybe_drop(_pat4, _ctx);
    kk_function_drop(_pat3, _ctx);
    kk_function_drop(_pat2, _ctx);
    kk_string_drop(_pat1, _ctx);
    kk_string_drop(_pat0, _ctx);
    kk_std_time_instant__timescale_free(timescale0);
  }
  else {
    kk_std_core_types__maybe_dup(_x);
    kk_std_time_instant__timescale_decref(timescale0, _ctx);
  }
  return _x;
}
 
// Automatically generated. Retrieves the `mb-to-mjd2000` constructor field of the `:timescale` type.

static inline kk_std_core_types__maybe kk_std_time_instant_mb_to_mjd2000(kk_std_time_instant__timescale timescale0, kk_context_t* _ctx) { /* (timescale : timescale) -> maybe<(t : std/time/timestamp/timestamp, tzdelta : std/time/timestamp/timespan) -> std/num/ddouble/ddouble> */ 
  struct kk_std_time_instant_Timescale* _con5340 = kk_std_time_instant__as_Timescale(timescale0);
  kk_string_t _pat0 = _con5340->name;
  kk_string_t _pat1 = _con5340->unit;
  kk_function_t _pat2 = _con5340->from_tai;
  kk_function_t _pat3 = _con5340->to_tai;
  kk_std_core_types__maybe _pat4 = _con5340->mb_seconds_in_day;
  kk_std_core_types__maybe _x = _con5340->mb_to_mjd2000;
  kk_std_core_types__maybe _pat5 = _con5340->mb_from_mjd2000;
  if (kk_std_time_instant__timescale_is_unique(timescale0)) {
    kk_std_core_types__maybe_drop(_pat5, _ctx);
    kk_std_core_types__maybe_drop(_pat4, _ctx);
    kk_function_drop(_pat3, _ctx);
    kk_function_drop(_pat2, _ctx);
    kk_string_drop(_pat1, _ctx);
    kk_string_drop(_pat0, _ctx);
    kk_std_time_instant__timescale_free(timescale0);
  }
  else {
    kk_std_core_types__maybe_dup(_x);
    kk_std_time_instant__timescale_decref(timescale0, _ctx);
  }
  return _x;
}
 
// Automatically generated. Retrieves the `mb-from-mjd2000` constructor field of the `:timescale` type.

static inline kk_std_core_types__maybe kk_std_time_instant_mb_from_mjd2000(kk_std_time_instant__timescale timescale0, kk_context_t* _ctx) { /* (timescale : timescale) -> maybe<(days : int, frac : std/num/ddouble/ddouble) -> std/time/timestamp/timestamp> */ 
  struct kk_std_time_instant_Timescale* _con5341 = kk_std_time_instant__as_Timescale(timescale0);
  kk_string_t _pat0 = _con5341->name;
  kk_string_t _pat1 = _con5341->unit;
  kk_function_t _pat2 = _con5341->from_tai;
  kk_function_t _pat3 = _con5341->to_tai;
  kk_std_core_types__maybe _pat4 = _con5341->mb_seconds_in_day;
  kk_std_core_types__maybe _pat5 = _con5341->mb_to_mjd2000;
  kk_std_core_types__maybe _x = _con5341->mb_from_mjd2000;
  if (kk_std_time_instant__timescale_is_unique(timescale0)) {
    kk_std_core_types__maybe_drop(_pat5, _ctx);
    kk_std_core_types__maybe_drop(_pat4, _ctx);
    kk_function_drop(_pat3, _ctx);
    kk_function_drop(_pat2, _ctx);
    kk_string_drop(_pat1, _ctx);
    kk_string_drop(_pat0, _ctx);
    kk_std_time_instant__timescale_free(timescale0);
  }
  else {
    kk_std_core_types__maybe_dup(_x);
    kk_std_time_instant__timescale_decref(timescale0, _ctx);
  }
  return _x;
}

kk_std_time_instant__timescale kk_std_time_instant__copy(kk_std_time_instant__timescale _this, kk_std_core_types__optional name0, kk_std_core_types__optional unit0, kk_std_core_types__optional from_tai0, kk_std_core_types__optional to_tai0, kk_std_core_types__optional mb_seconds_in_day0, kk_std_core_types__optional mb_to_mjd20000, kk_std_core_types__optional mb_from_mjd20000, kk_context_t* _ctx); /* (timescale, name : optional<string>, unit : optional<string>, from-tai : optional<(std/time/duration/duration) -> std/time/timestamp/timestamp>, to-tai : optional<(std/time/timestamp/timestamp) -> std/time/duration/duration>, mb-seconds-in-day : optional<maybe<(t : std/time/timestamp/timestamp) -> std/time/timestamp/timespan>>, mb-to-mjd2000 : optional<maybe<(t : std/time/timestamp/timestamp, tzdelta : std/time/timestamp/timespan) -> std/num/ddouble/ddouble>>, mb-from-mjd2000 : optional<maybe<(days : int, frac : std/num/ddouble/ddouble) -> std/time/timestamp/timestamp>>) -> timescale */ 
 
// Automatically generated. Retrieves the `since` constructor field of the `:instant` type.

static inline kk_std_time_timestamp__timestamp kk_std_time_instant_since(kk_std_time_instant__instant instant0, kk_context_t* _ctx) { /* (instant : instant) -> std/time/timestamp/timestamp */ 
  struct kk_std_time_instant_Instant* _con5372 = kk_std_time_instant__as_Instant(instant0);
  kk_std_time_timestamp__timestamp _x = _con5372->since;
  kk_std_time_instant__timescale _pat2 = _con5372->ts;
  struct kk_std_time_instant_Timescale* _con5373 = kk_std_time_instant__as_Timescale(_pat2);
  kk_string_t _pat3 = _con5373->name;
  kk_string_t _pat4 = _con5373->unit;
  kk_function_t _pat5 = _con5373->from_tai;
  kk_function_t _pat6 = _con5373->to_tai;
  kk_std_core_types__maybe _pat7 = _con5373->mb_seconds_in_day;
  kk_std_core_types__maybe _pat8 = _con5373->mb_to_mjd2000;
  kk_std_core_types__maybe _pat9 = _con5373->mb_from_mjd2000;
  if (kk_std_time_instant__instant_is_unique(instant0)) {
    if (kk_std_time_instant__timescale_is_unique(_pat2)) {
      kk_string_drop(_pat3, _ctx);
      kk_string_drop(_pat4, _ctx);
      kk_function_drop(_pat5, _ctx);
      kk_function_drop(_pat6, _ctx);
      kk_std_core_types__maybe_drop(_pat7, _ctx);
      kk_std_core_types__maybe_drop(_pat8, _ctx);
      kk_std_core_types__maybe_drop(_pat9, _ctx);
      kk_std_time_instant__timescale_free(_pat2);
    }
    else {
      kk_std_time_instant__timescale_decref(_pat2, _ctx);
    }
    kk_std_time_instant__instant_free(instant0);
  }
  else {
    kk_std_time_instant__instant_decref(instant0, _ctx);
  }
  return _x;
}
 
// Automatically generated. Retrieves the `ts` constructor field of the `:instant` type.

static inline kk_std_time_instant__timescale kk_std_time_instant_ts(kk_std_time_instant__instant instant0, kk_context_t* _ctx) { /* (instant : instant) -> timescale */ 
  struct kk_std_time_instant_Instant* _con5374 = kk_std_time_instant__as_Instant(instant0);
  kk_std_time_timestamp__timestamp _pat0 = _con5374->since;
  kk_std_time_instant__timescale _x = _con5374->ts;
  struct kk_std_time_instant_Timescale* _con5375 = kk_std_time_instant__as_Timescale(_x);
  if (kk_std_time_instant__instant_is_unique(instant0)) {
    kk_std_time_instant__instant_free(instant0);
  }
  else {
    kk_std_time_instant__timescale_dup(_x);
    kk_std_time_instant__instant_decref(instant0, _ctx);
  }
  return _x;
}

kk_std_time_instant__instant kk_std_time_instant__copy_1(kk_std_time_instant__instant _this, kk_std_core_types__optional since0, kk_std_core_types__optional ts0, kk_context_t* _ctx); /* (instant, since : optional<std/time/timestamp/timestamp>, ts : optional<timescale>) -> instant */ 

kk_std_time_timestamp__timestamp kk_std_time_instant_timestamp(kk_std_time_instant__instant i, kk_context_t* _ctx); /* (i : instant) -> std/time/timestamp/timestamp */ 

bool kk_std_time_instant_has_leap_seconds(kk_std_time_instant__timescale ts0, kk_context_t* _ctx); /* (ts : timescale) -> bool */ 

extern kk_std_num_ddouble__ddouble kk_std_time_instant_mjd_epoch_delta;
 
/*----------------------------------------------------------------------------
  Julian Date
----------------------------------------------------------------------------*/

extern kk_std_num_ddouble__ddouble kk_std_time_instant_jd_epoch_delta;

kk_std_num_ddouble__ddouble kk_std_time_instant_seconds_in_day(kk_std_time_instant__instant i, kk_context_t* _ctx); /* (i : instant) -> std/time/timestamp/timespan */ 
 
// A time scale defines how time is measured: the rate and unit of time,
// and how it can be converted to- and from TAI.
// For time calculations, usually the [TAI](https://en.wikipedia.org/wiki/International_Atomic_Time)
// (international atomic time) time scale (`ts-tai`) is used which is time measured as SI seconds on the Earths geoid.
// Another common time scale is UTC (`std/time/utc/ts-utc`) which also uses SI second time units but can contain leap seconds.

static inline kk_std_time_instant__timescale kk_std_time_instant__create_Timescale(kk_string_t name0, kk_string_t unit0, kk_function_t from_tai0, kk_function_t to_tai0, kk_std_core_types__optional mb_seconds_in_day0, kk_std_core_types__optional mb_to_mjd20000, kk_std_core_types__optional mb_from_mjd20000, kk_context_t* _ctx) { /* (name : string, unit : string, from-tai : (std/time/duration/duration) -> std/time/timestamp/timestamp, to-tai : (std/time/timestamp/timestamp) -> std/time/duration/duration, mb-seconds-in-day : optional<maybe<(t : std/time/timestamp/timestamp) -> std/time/timestamp/timespan>>, mb-to-mjd2000 : optional<maybe<(t : std/time/timestamp/timestamp, tzdelta : std/time/timestamp/timespan) -> std/num/ddouble/ddouble>>, mb-from-mjd2000 : optional<maybe<(days : int, frac : std/num/ddouble/ddouble) -> std/time/timestamp/timestamp>>) -> timescale */ 
  kk_std_core_types__maybe _x5406;
  if (kk_std_core_types__is_Optional(mb_seconds_in_day0)) {
    kk_box_t _box_x4781 = mb_seconds_in_day0._cons.Optional.value;
    kk_std_core_types__maybe _mb_seconds_in_day_410 = kk_std_core_types__maybe_unbox(_box_x4781, NULL);
    kk_std_core_types__maybe_dup(_mb_seconds_in_day_410);
    kk_std_core_types__optional_drop(mb_seconds_in_day0, _ctx);
    _x5406 = _mb_seconds_in_day_410; /*maybe<(t : std/time/timestamp/timestamp) -> std/time/timestamp/timespan>*/
    goto _match5407;
  }
  _x5406 = kk_std_core_types__new_Nothing(_ctx); /*maybe<(t : std/time/timestamp/timestamp) -> std/time/timestamp/timespan>*/
  _match5407: ;
  kk_std_core_types__maybe _x5409;
  if (kk_std_core_types__is_Optional(mb_to_mjd20000)) {
    kk_box_t _box_x4782 = mb_to_mjd20000._cons.Optional.value;
    kk_std_core_types__maybe _mb_to_mjd2000_415 = kk_std_core_types__maybe_unbox(_box_x4782, NULL);
    kk_std_core_types__maybe_dup(_mb_to_mjd2000_415);
    kk_std_core_types__optional_drop(mb_to_mjd20000, _ctx);
    _x5409 = _mb_to_mjd2000_415; /*maybe<(t : std/time/timestamp/timestamp, tzdelta : std/time/timestamp/timespan) -> std/num/ddouble/ddouble>*/
    goto _match5410;
  }
  _x5409 = kk_std_core_types__new_Nothing(_ctx); /*maybe<(t : std/time/timestamp/timestamp, tzdelta : std/time/timestamp/timespan) -> std/num/ddouble/ddouble>*/
  _match5410: ;
  kk_std_core_types__maybe _x5412;
  if (kk_std_core_types__is_Optional(mb_from_mjd20000)) {
    kk_box_t _box_x4783 = mb_from_mjd20000._cons.Optional.value;
    kk_std_core_types__maybe _mb_from_mjd2000_420 = kk_std_core_types__maybe_unbox(_box_x4783, NULL);
    kk_std_core_types__maybe_dup(_mb_from_mjd2000_420);
    kk_std_core_types__optional_drop(mb_from_mjd20000, _ctx);
    _x5412 = _mb_from_mjd2000_420; /*maybe<(days : int, frac : std/num/ddouble/ddouble) -> std/time/timestamp/timestamp>*/
    goto _match5413;
  }
  _x5412 = kk_std_core_types__new_Nothing(_ctx); /*maybe<(days : int, frac : std/num/ddouble/ddouble) -> std/time/timestamp/timestamp>*/
  _match5413: ;
  return kk_std_time_instant__new_Timescale(kk_reuse_null, name0, unit0, from_tai0, to_tai0, _x5406, _x5409, _x5412, _ctx);
}
 
// Return the time scale that instant `i` uses.

static inline kk_std_time_instant__timescale kk_std_time_instant_timescale(kk_std_time_instant__instant i, kk_context_t* _ctx) { /* (i : instant) -> timescale */ 
  struct kk_std_time_instant_Instant* _con5415 = kk_std_time_instant__as_Instant(i);
  kk_std_time_timestamp__timestamp _pat0 = _con5415->since;
  kk_std_time_instant__timescale _x = _con5415->ts;
  struct kk_std_time_instant_Timescale* _con5416 = kk_std_time_instant__as_Timescale(_x);
  if (kk_std_time_instant__instant_is_unique(i)) {
    kk_std_time_instant__instant_free(i);
  }
  else {
    kk_std_time_instant__timescale_dup(_x);
    kk_std_time_instant__instant_decref(i, _ctx);
  }
  return _x;
}

kk_std_time_instant__timescale kk_std_time_instant_timescale_1(kk_string_t name0, kk_function_t from_tai0, kk_function_t to_tai0, kk_std_core_types__optional unit0, kk_std_core_types__optional seconds_in_day0, kk_std_core_types__optional to_mjd2000, kk_std_core_types__optional from_mjd2000, kk_context_t* _ctx); /* (name : string, from-tai : (std/time/duration/duration) -> std/time/timestamp/timestamp, to-tai : (std/time/timestamp/timestamp) -> std/time/duration/duration, unit : optional<string>, seconds-in-day : optional<maybe<(std/time/timestamp/timestamp) -> std/time/timestamp/timespan>>, to-mjd2000 : optional<maybe<(t : std/time/timestamp/timestamp, tzdelta : std/time/timestamp/timespan) -> std/num/ddouble/ddouble>>, from-mjd2000 : optional<maybe<(days : int, frac : std/num/ddouble/ddouble) -> std/time/timestamp/timestamp>>) -> timescale */ 

kk_std_time_instant__timescale kk_std_time_instant_tai_timescale(kk_string_t name0, kk_std_core_types__optional offset, kk_context_t* _ctx); /* (name : string, offset : optional<std/time/duration/duration>) -> timescale */ 

extern kk_std_time_instant__timescale kk_std_time_instant_ts_tai;

kk_std_time_instant__instant kk_std_time_instant_unsafe_add(kk_std_time_instant__instant i, kk_std_num_ddouble__ddouble tspan, kk_context_t* _ctx); /* (i : instant, tspan : std/time/timestamp/timespan) -> instant */ 

kk_std_time_timestamp__timestamp kk_std_time_instant_convert(kk_std_time_timestamp__timestamp t, kk_std_time_instant__timescale from, kk_std_time_instant__timescale to, kk_context_t* _ctx); /* (t : std/time/timestamp/timestamp, from : timescale, to : timescale) -> std/time/timestamp/timestamp */ 

kk_std_time_timestamp__timestamp kk_std_time_instant_timestamp_in(kk_std_time_instant__instant i, kk_std_time_instant__timescale tscale, kk_context_t* _ctx); /* (i : instant, tscale : timescale) -> std/time/timestamp/timestamp */ 

kk_std_time_instant__instant kk_std_time_instant_use_timescale(kk_std_time_instant__instant i, kk_std_time_instant__timescale tscale, kk_context_t* _ctx); /* (i : instant, tscale : timescale) -> instant */ 

kk_std_time_instant__instant kk_std_time_instant__lp__plus__rp_(kk_std_time_instant__instant i, kk_std_time_duration__duration d, kk_context_t* _ctx); /* (i : instant, d : std/time/duration/duration) -> instant */ 

kk_std_time_instant__instant kk_std_time_instant__lp__dash__rp_(kk_std_time_instant__instant i, kk_std_time_duration__duration d, kk_context_t* _ctx); /* (i : instant, d : std/time/duration/duration) -> instant */ 
 
// Return the (TAI) SI second duration since the `epoch` at this instant.

static inline kk_std_time_duration__duration kk_std_time_instant_duration(kk_std_time_instant__instant i, kk_context_t* _ctx) { /* (i : instant) -> std/time/duration/duration */ 
  kk_std_time_timestamp__timestamp t_4540;
  kk_std_time_instant__timescale _x5647 = kk_std_time_instant__timescale_dup(kk_std_time_instant_ts_tai); /*std/time/instant/timescale*/
  t_4540 = kk_std_time_instant_timestamp_in(i, _x5647, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_num_ddouble__ddouble _x5648 = kk_std_time_timestamp_unsafe_timespan_withleap(t_4540, _ctx); /*std/time/timestamp/timespan*/
  return kk_std_time_duration__new_Duration(_x5648, _ctx);
}
 
// Return the duration between to instants in time.

static inline kk_std_time_duration__duration kk_std_time_instant__lp__dash__1_rp_(kk_std_time_instant__instant i, kk_std_time_instant__instant j, kk_context_t* _ctx) { /* (i : instant, j : instant) -> std/time/duration/duration */ 
  kk_std_time_duration__duration d_4541 = kk_std_time_instant_duration(i, _ctx); /*std/time/duration/duration*/;
  kk_std_time_duration__duration e_4542 = kk_std_time_instant_duration(j, _ctx); /*std/time/duration/duration*/;
  kk_std_time_duration__duration e0_2276 = kk_std_time_duration__lp__tilde__rp_(e_4542, _ctx); /*std/time/duration/duration*/;
  kk_std_num_ddouble__ddouble _x5649;
  kk_std_num_ddouble__ddouble _x5650;
  kk_std_num_ddouble__ddouble _x = d_4541.secs;
  _x5650 = _x; /*std/time/timestamp/timespan*/
  kk_std_num_ddouble__ddouble _x5651;
  kk_std_num_ddouble__ddouble _x0 = e0_2276.secs;
  _x5651 = _x0; /*std/time/timestamp/timespan*/
  _x5649 = kk_std_num_ddouble__lp__plus__rp_(_x5650, _x5651, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_time_duration__new_Duration(_x5649, _ctx);
}

bool kk_std_time_instant__lp__eq__eq__rp_(kk_std_time_instant__timescale t1, kk_std_time_instant__timescale t2, kk_context_t* _ctx); /* (t1 : timescale, t2 : timescale) -> bool */ 

kk_std_core_types__order kk_std_time_instant_compare(kk_std_time_instant__instant i, kk_std_time_instant__instant j, kk_context_t* _ctx); /* (i : instant, j : instant) -> order */ 

bool kk_std_time_instant__lp__eq__eq__1_rp_(kk_std_time_instant__instant i, kk_std_time_instant__instant j, kk_context_t* _ctx); /* (i : instant, j : instant) -> bool */ 

kk_std_time_timestamp__timestamp kk_std_time_instant_from_tai_1(kk_std_time_instant__timescale ts0, kk_std_time_duration__duration d, kk_context_t* _ctx); /* (ts : timescale, d : std/time/duration/duration) -> std/time/timestamp/timestamp */ 
 
// Create an instant from a time stamp `t` interpreted in time scale `ts`.
// Be careful to ensure that `t` should indeed be interpreted in the given time scale.

static inline kk_std_time_instant__instant kk_std_time_instant_instant(kk_std_time_instant__timescale ts0, kk_std_time_timestamp__timestamp t, kk_context_t* _ctx) { /* (ts : timescale, t : std/time/timestamp/timestamp) -> instant */ 
  return kk_std_time_instant__new_Instant(kk_reuse_null, t, ts0, _ctx);
}
 
// Return the instant at (TAI) SI seconds duration since the `epoch`.

static inline kk_std_time_instant__instant kk_std_time_instant_instant_1(kk_std_time_duration__duration d, kk_context_t* _ctx) { /* (d : std/time/duration/duration) -> instant */ 
  kk_std_time_timestamp__timestamp t_4564 = kk_std_time_duration_timestamp(d, _ctx); /*std/time/timestamp/timestamp*/;
  kk_std_time_instant__timescale _x5700 = kk_std_time_instant__timescale_dup(kk_std_time_instant_ts_tai); /*std/time/instant/timescale*/
  return kk_std_time_instant__new_Instant(kk_reuse_null, t_4564, _x5700, _ctx);
}

kk_std_time_instant__instant kk_std_time_instant_instant_2(kk_std_time_instant__timescale ts0, kk_integer_t days0, kk_std_num_ddouble__ddouble secs, kk_std_core_types__optional leap, kk_context_t* _ctx); /* (ts : timescale, days : int, secs : std/time/timestamp/timespan, leap : optional<int>) -> instant */ 
 
// Return the `:duration` since the `epoch` for a timestamp `t` interpreted in time scale `ts`.

static inline kk_std_time_duration__duration kk_std_time_instant_to_tai_1(kk_std_time_instant__timescale ts0, kk_std_time_timestamp__timestamp t, kk_context_t* _ctx) { /* (ts : timescale, t : std/time/timestamp/timestamp) -> std/time/duration/duration */ 
  kk_std_time_timestamp__timestamp t0_4567;
  kk_std_time_instant__timescale _x5707 = kk_std_time_instant__timescale_dup(kk_std_time_instant_ts_tai); /*std/time/instant/timescale*/
  t0_4567 = kk_std_time_instant_convert(t, ts0, _x5707, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_num_ddouble__ddouble _x5708 = kk_std_time_timestamp_unsafe_timespan_withleap(t0_4567, _ctx); /*std/time/timestamp/timespan*/
  return kk_std_time_duration__new_Duration(_x5708, _ctx);
}

bool kk_std_time_instant__lp__excl__eq__rp_(kk_std_time_instant__instant i, kk_std_time_instant__instant j, kk_context_t* _ctx); /* (i : instant, j : instant) -> bool */ 

bool kk_std_time_instant__lp__lt__rp_(kk_std_time_instant__instant i, kk_std_time_instant__instant j, kk_context_t* _ctx); /* (i : instant, j : instant) -> bool */ 

bool kk_std_time_instant__lp__lt__eq__rp_(kk_std_time_instant__instant i, kk_std_time_instant__instant j, kk_context_t* _ctx); /* (i : instant, j : instant) -> bool */ 

bool kk_std_time_instant__lp__gt__rp_(kk_std_time_instant__instant i, kk_std_time_instant__instant j, kk_context_t* _ctx); /* (i : instant, j : instant) -> bool */ 

bool kk_std_time_instant__lp__gt__eq__rp_(kk_std_time_instant__instant i, kk_std_time_instant__instant j, kk_context_t* _ctx); /* (i : instant, j : instant) -> bool */ 

kk_std_time_instant__instant kk_std_time_instant_add_days(kk_std_time_instant__instant i, kk_integer_t days0, kk_context_t* _ctx); /* (i : instant, days : int) -> instant */ 

kk_std_time_instant__instant kk_std_time_instant_add_duration_in(kk_std_time_instant__instant i, kk_std_time_instant__timescale tscale, kk_std_num_ddouble__ddouble t, kk_context_t* _ctx); /* (i : instant, tscale : timescale, t : std/time/timestamp/timespan) -> instant */ 

kk_integer_t kk_std_time_instant_days(kk_std_time_instant__instant i, kk_context_t* _ctx); /* (i : instant) -> int */ 

kk_std_core_types__tuple2_ kk_std_time_instant_days_clock(kk_std_time_instant__instant i, kk_context_t* _ctx); /* (i : instant) -> (int, std/time/date/clock) */ 
 
// Our epoch is set at 2000-01-01 TAI (which is equal to 1999-12-31T23:59:28Z UTC).
//
// Another candidate epoch could have been the standard [J2000] epoch ([`epoch-j2000`](std_time_astro.html#epoch_j2000)),
// which equals 2000-01-01T12:00:00 TT (terrestrial time).
// However, that would mean that for the most common time scales, namely UTC and TAI, there would always be a
// fractional offset (of 32.184s) for common time stamps. Moreover, by having an epoch at noon there would be
// an extra correction needed for calendar date calculations too.
//
// Similarly, the standard Unix epoch of 1970-01-01Z UTC is not ideal either since the UTC offset with TAI
// was fractional at that time (namely 8.000082s).
//
// Finally, after 1996, TAI was corrected for black-body radiation [@blackbody] which makes
// the 2000-01-01 epoch a very precisely defined point in time.
//
//
// [J2000]: https://en.wikipedia.org/wiki/Equinox_(celestial_coordinates)#J2000.0

extern kk_std_time_instant__instant kk_std_time_instant_epoch;

extern kk_std_time_duration__duration kk_std_time_instant_gps2000;

kk_std_time_instant__instant kk_std_time_instant_gps_instant(kk_std_time_duration__duration gps, kk_context_t* _ctx); /* (gps : std/time/duration/duration) -> instant */ 

kk_std_time_instant__instant kk_std_time_instant_gps_instant_1(kk_integer_t weeks, kk_std_time_duration__duration secs, kk_context_t* _ctx); /* (weeks : int, secs : std/time/duration/duration) -> instant */ 

extern kk_std_time_instant__timescale kk_std_time_instant_ts_gps;

kk_std_time_duration__duration kk_std_time_instant_gps_timestamp(kk_std_time_instant__instant i, kk_context_t* _ctx); /* (i : instant) -> std/time/duration/duration */ 

kk_std_core_types__tuple2_ kk_std_time_instant_gps_week_timestamp(kk_std_time_instant__instant i, kk_context_t* _ctx); /* (i : instant) -> (int, std/time/duration/duration) */ 

kk_std_time_instant__instant kk_std_time_instant_instant_at_mjd_1(kk_std_num_ddouble__ddouble mjd0, kk_std_time_instant__timescale ts0, kk_context_t* _ctx); /* (mjd : std/num/ddouble/ddouble, ts : timescale) -> instant */ 

kk_std_time_instant__instant kk_std_time_instant_instant_at_mjd(double mjd0, kk_std_time_instant__timescale ts0, kk_context_t* _ctx); /* (mjd : double, ts : timescale) -> instant */ 

kk_std_time_instant__instant kk_std_time_instant_instant_at_jd_1(kk_std_num_ddouble__ddouble jd0, kk_std_time_instant__timescale ts0, kk_context_t* _ctx); /* (jd : std/num/ddouble/ddouble, ts : timescale) -> instant */ 

kk_std_time_instant__instant kk_std_time_instant_instant_at_jd(double jd0, kk_std_time_instant__timescale ts0, kk_context_t* _ctx); /* (jd : double, ts : timescale) -> instant */ 

kk_std_num_ddouble__ddouble kk_std_time_instant_mjd(kk_std_time_instant__instant i, kk_std_time_instant__timescale tscale, kk_std_core_types__optional tzdelta, kk_context_t* _ctx); /* (i : instant, tscale : timescale, tzdelta : optional<std/time/timestamp/timespan>) -> std/num/ddouble/ddouble */ 

kk_std_num_ddouble__ddouble kk_std_time_instant_jd(kk_std_time_instant__instant i, kk_std_time_instant__timescale ts0, kk_context_t* _ctx); /* (i : instant, ts : timescale) -> std/num/ddouble/ddouble */ 

kk_std_time_instant__instant kk_std_time_instant_max(kk_std_time_instant__instant i, kk_std_time_instant__instant j, kk_context_t* _ctx); /* (i : instant, j : instant) -> instant */ 

kk_std_time_instant__instant kk_std_time_instant_min(kk_std_time_instant__instant i, kk_std_time_instant__instant j, kk_context_t* _ctx); /* (i : instant, j : instant) -> instant */ 

kk_std_time_instant__instant kk_std_time_instant_round_to_prec(kk_std_time_instant__instant i, kk_integer_t prec, kk_context_t* _ctx); /* (i : instant, prec : int) -> instant */ 

kk_string_t kk_std_time_instant_show_raw(kk_std_time_instant__instant i, kk_std_core_types__optional max_prec, kk_std_core_types__optional secs_width, kk_std_core_types__optional unit0, kk_context_t* _ctx); /* (i : instant, max-prec : optional<int>, secs-width : optional<int>, unit : optional<string>) -> string */ 

kk_string_t kk_std_time_instant_show(kk_std_time_instant__instant i, kk_std_core_types__optional max_prec, kk_std_core_types__optional secs_width, kk_context_t* _ctx); /* (i : instant, max-prec : optional<int>, secs-width : optional<int>) -> string */ 

kk_string_t kk_std_time_instant_show_1(kk_std_time_timestamp__timestamp t, kk_std_core_types__optional max_prec, kk_std_core_types__optional secs_width, kk_std_core_types__optional unit0, kk_context_t* _ctx); /* (t : std/time/timestamp/timestamp, max-prec : optional<int>, secs-width : optional<int>, unit : optional<string>) -> string */ 

extern kk_std_time_instant__timescale kk_std_time_instant_ts_tt;

extern kk_std_time_duration__duration kk_std_time_instant_tt2000;

kk_std_time_duration__duration kk_std_time_instant_tt_instant(kk_std_time_instant__instant i, kk_context_t* _ctx); /* (i : instant) -> std/time/duration/duration */ 

kk_std_time_instant__instant kk_std_time_instant_tt_instant_1(kk_std_time_duration__duration tt, kk_context_t* _ctx); /* (tt : std/time/duration/duration) -> instant */ 

void kk_std_time_instant__init(kk_context_t* _ctx);

#endif // header
