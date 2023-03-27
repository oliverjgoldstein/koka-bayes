#pragma once
#ifndef kk_std_time_date_H
#define kk_std_time_date_H
// Koka generated module: "std/time/date", koka version: 2.1.3
#include <kklib.h>
#include "std_core_types.h"
#include "std_core.h"
#include "std_num_double.h"
#include "std_num_ddouble.h"

// type declarations

// type std/time/date/clock
struct kk_std_time_date__clock_s {
  kk_block_t _block;
};
typedef struct kk_std_time_date__clock_s* kk_std_time_date__clock;
struct kk_std_time_date_Clock {
  struct kk_std_time_date__clock_s _base;
  kk_integer_t hours;
  kk_integer_t minutes;
  kk_std_num_ddouble__ddouble seconds;
};
static inline kk_std_time_date__clock kk_std_time_date__base_Clock(struct kk_std_time_date_Clock* _x){
  return &_x->_base;
}
static inline kk_std_time_date__clock kk_std_time_date__new_Clock(kk_reuse_t _at, kk_integer_t hours, kk_integer_t minutes, kk_std_num_ddouble__ddouble seconds, kk_context_t* _ctx){
  struct kk_std_time_date_Clock* _con = kk_block_alloc_at_as(struct kk_std_time_date_Clock, _at, 2 /* scan count */, (kk_tag_t)(1), _ctx);
  _con->hours = hours;
  _con->minutes = minutes;
  _con->seconds = seconds;
  return kk_std_time_date__base_Clock(_con);
}
static inline struct kk_std_time_date_Clock* kk_std_time_date__as_Clock(kk_std_time_date__clock x) {
  return kk_basetype_as_assert(struct kk_std_time_date_Clock*, x, (kk_tag_t)(1) /* _tag */);
}
static inline bool kk_std_time_date__is_Clock(kk_std_time_date__clock x) {
  return (true);
}
static inline kk_std_time_date__clock kk_std_time_date__clock_dup(kk_std_time_date__clock _x) {
  return kk_basetype_dup_as(kk_std_time_date__clock, _x);
}
static inline void kk_std_time_date__clock_drop(kk_std_time_date__clock _x, kk_context_t* _ctx) {
  kk_basetype_drop(_x, _ctx);
}
static inline bool kk_std_time_date__clock_is_unique(kk_std_time_date__clock _x) {
  return kk_basetype_is_unique(_x);
}
static inline void kk_std_time_date__clock_free(kk_std_time_date__clock _x) {
  kk_basetype_free(_x);
}
static inline void kk_std_time_date__clock_decref(kk_std_time_date__clock _x, kk_context_t* _ctx) {
  kk_basetype_decref(_x, _ctx);
}
static inline kk_reuse_t kk_std_time_date__clock_dropn_reuse(kk_std_time_date__clock _x, size_t _scan_fsize, kk_context_t* _ctx) {
  return kk_basetype_dropn_reuse(_x, _scan_fsize, _ctx);
}
static inline void kk_std_time_date__clock_dropn(kk_std_time_date__clock _x, size_t _scan_fsize, kk_context_t* _ctx) {
  kk_basetype_dropn(_x, _scan_fsize, _ctx);
}
static inline kk_reuse_t kk_std_time_date__clock_reuse(kk_std_time_date__clock _x) {
  return kk_basetype_reuse(_x);
}
static inline kk_std_time_date__clock kk_std_time_date__clock_hole() {
  return (kk_std_time_date__clock)(1);
}
static inline kk_box_t kk_std_time_date__clock_box(kk_std_time_date__clock _x, kk_context_t* _ctx) {
  return kk_basetype_box(_x);
}
static inline kk_std_time_date__clock kk_std_time_date__clock_unbox(kk_box_t _x, kk_context_t* _ctx) {
  return kk_basetype_unbox_as(kk_std_time_date__clock, _x);
}

// value type std/time/date/date
struct kk_std_time_date_Date {
  kk_integer_t year;
  kk_integer_t month;
  kk_integer_t day;
};
typedef struct kk_std_time_date_Date kk_std_time_date__date;
static inline kk_std_time_date__date kk_std_time_date__new_Date(kk_integer_t year, kk_integer_t month, kk_integer_t day, kk_context_t* _ctx){
  kk_std_time_date__date _con;
  _con.year = year;
  _con.month = month;
  _con.day = day;
  return _con;
}
static inline bool kk_std_time_date__is_Date(kk_std_time_date__date x) {
  return (true);
}
static inline kk_std_time_date__date kk_std_time_date__date_dup(kk_std_time_date__date _x) {
  kk_integer_dup(_x.year);
  kk_integer_dup(_x.month);
  kk_integer_dup(_x.day);
  return _x;
}
static inline void kk_std_time_date__date_drop(kk_std_time_date__date _x, kk_context_t* _ctx) {
  kk_integer_drop(_x.year, _ctx);
  kk_integer_drop(_x.month, _ctx);
  kk_integer_drop(_x.day, _ctx);
}
static inline kk_box_t kk_std_time_date__date_box(kk_std_time_date__date _x, kk_context_t* _ctx) {
  kk_box_t _box;
  kk_valuetype_box(kk_std_time_date__date, _box, _x, 3 /* scan count */, _ctx);
  return _box;
}
static inline kk_std_time_date__date kk_std_time_date__date_unbox(kk_box_t _x, kk_context_t* _ctx) {
  kk_boxed_value_t _p;
  kk_std_time_date__date _unbox;
  kk_valuetype_unbox_(kk_std_time_date__date, _p, _unbox, _x, _ctx);
  if (_ctx!=NULL && _p!=NULL) {
    if (kk_basetype_is_unique(_p)) { kk_basetype_free(_p); } else {
      kk_std_time_date__date_dup(_unbox);
      kk_basetype_decref(_p, _ctx);
    }
  }
  return _unbox;
}

// value type std/time/date/weekday
enum kk_std_time_date__weekday_e {
  kk_std_time_date_Mon,
  kk_std_time_date_Tue,
  kk_std_time_date_Wed,
  kk_std_time_date_Thu,
  kk_std_time_date_Fri,
  kk_std_time_date_Sat,
  kk_std_time_date_Sun
};
typedef uint8_t kk_std_time_date__weekday;

static inline kk_std_time_date__weekday kk_std_time_date__new_Mon(kk_context_t* _ctx){
  return kk_std_time_date_Mon;
}
static inline kk_std_time_date__weekday kk_std_time_date__new_Tue(kk_context_t* _ctx){
  return kk_std_time_date_Tue;
}
static inline kk_std_time_date__weekday kk_std_time_date__new_Wed(kk_context_t* _ctx){
  return kk_std_time_date_Wed;
}
static inline kk_std_time_date__weekday kk_std_time_date__new_Thu(kk_context_t* _ctx){
  return kk_std_time_date_Thu;
}
static inline kk_std_time_date__weekday kk_std_time_date__new_Fri(kk_context_t* _ctx){
  return kk_std_time_date_Fri;
}
static inline kk_std_time_date__weekday kk_std_time_date__new_Sat(kk_context_t* _ctx){
  return kk_std_time_date_Sat;
}
static inline kk_std_time_date__weekday kk_std_time_date__new_Sun(kk_context_t* _ctx){
  return kk_std_time_date_Sun;
}
static inline bool kk_std_time_date__is_Mon(kk_std_time_date__weekday x) {
  return (x == kk_std_time_date_Mon);
}
static inline bool kk_std_time_date__is_Tue(kk_std_time_date__weekday x) {
  return (x == kk_std_time_date_Tue);
}
static inline bool kk_std_time_date__is_Wed(kk_std_time_date__weekday x) {
  return (x == kk_std_time_date_Wed);
}
static inline bool kk_std_time_date__is_Thu(kk_std_time_date__weekday x) {
  return (x == kk_std_time_date_Thu);
}
static inline bool kk_std_time_date__is_Fri(kk_std_time_date__weekday x) {
  return (x == kk_std_time_date_Fri);
}
static inline bool kk_std_time_date__is_Sat(kk_std_time_date__weekday x) {
  return (x == kk_std_time_date_Sat);
}
static inline bool kk_std_time_date__is_Sun(kk_std_time_date__weekday x) {
  return (x == kk_std_time_date_Sun);
}
static inline kk_std_time_date__weekday kk_std_time_date__weekday_dup(kk_std_time_date__weekday _x) {
  return _x;
}
static inline void kk_std_time_date__weekday_drop(kk_std_time_date__weekday _x, kk_context_t* _ctx) {
  
}
static inline kk_box_t kk_std_time_date__weekday_box(kk_std_time_date__weekday _x, kk_context_t* _ctx) {
  return kk_enum_box(_x);
}
static inline kk_std_time_date__weekday kk_std_time_date__weekday_unbox(kk_box_t _x, kk_context_t* _ctx) {
  return (kk_std_time_date__weekday)kk_enum_unbox(_x);
}

// value declarations
 
// Automatically generated. Retrieves the `hours` constructor field of the `:clock` type.

static inline kk_integer_t kk_std_time_date_hours(kk_std_time_date__clock clock1, kk_context_t* _ctx) { /* (clock : clock) -> int */ 
  struct kk_std_time_date_Clock* _con10069 = kk_std_time_date__as_Clock(clock1);
  kk_integer_t _x = _con10069->hours;
  kk_integer_t _pat0 = _con10069->minutes;
  kk_std_num_ddouble__ddouble _pat1 = _con10069->seconds;
  if (kk_std_time_date__clock_is_unique(clock1)) {
    kk_integer_drop(_pat0, _ctx);
    kk_std_time_date__clock_free(clock1);
  }
  else {
    kk_integer_dup(_x);
    kk_std_time_date__clock_decref(clock1, _ctx);
  }
  return _x;
}
 
// Automatically generated. Retrieves the `minutes` constructor field of the `:clock` type.

static inline kk_integer_t kk_std_time_date_minutes(kk_std_time_date__clock clock1, kk_context_t* _ctx) { /* (clock : clock) -> int */ 
  struct kk_std_time_date_Clock* _con10070 = kk_std_time_date__as_Clock(clock1);
  kk_integer_t _pat0 = _con10070->hours;
  kk_integer_t _x = _con10070->minutes;
  kk_std_num_ddouble__ddouble _pat1 = _con10070->seconds;
  if (kk_std_time_date__clock_is_unique(clock1)) {
    kk_integer_drop(_pat0, _ctx);
    kk_std_time_date__clock_free(clock1);
  }
  else {
    kk_integer_dup(_x);
    kk_std_time_date__clock_decref(clock1, _ctx);
  }
  return _x;
}
 
// Automatically generated. Retrieves the `seconds` constructor field of the `:clock` type.

static inline kk_std_num_ddouble__ddouble kk_std_time_date_seconds(kk_std_time_date__clock clock1, kk_context_t* _ctx) { /* (clock : clock) -> std/num/ddouble/ddouble */ 
  struct kk_std_time_date_Clock* _con10071 = kk_std_time_date__as_Clock(clock1);
  kk_integer_t _pat0 = _con10071->hours;
  kk_integer_t _pat1 = _con10071->minutes;
  kk_std_num_ddouble__ddouble _x = _con10071->seconds;
  if (kk_std_time_date__clock_is_unique(clock1)) {
    kk_integer_drop(_pat1, _ctx);
    kk_integer_drop(_pat0, _ctx);
    kk_std_time_date__clock_free(clock1);
  }
  else {
    kk_std_time_date__clock_decref(clock1, _ctx);
  }
  return _x;
}

kk_std_time_date__clock kk_std_time_date__copy(kk_std_time_date__clock _this, kk_std_core_types__optional hours0, kk_std_core_types__optional minutes0, kk_std_core_types__optional seconds0, kk_context_t* _ctx); /* (clock, hours : optional<int>, minutes : optional<int>, seconds : optional<std/num/ddouble/ddouble>) -> clock */ 
 
// Automatically generated. Retrieves the `year` constructor field of the `:date` type.

static inline kk_integer_t kk_std_time_date_year(kk_std_time_date__date date, kk_context_t* _ctx) { /* (date : date) -> int */ 
  kk_integer_t _x = date.year;
  kk_integer_dup(_x);
  kk_std_time_date__date_drop(date, _ctx);
  return _x;
}
 
// Automatically generated. Retrieves the `month` constructor field of the `:date` type.

static inline kk_integer_t kk_std_time_date_month(kk_std_time_date__date date, kk_context_t* _ctx) { /* (date : date) -> int */ 
  kk_integer_t _x = date.month;
  kk_integer_dup(_x);
  kk_std_time_date__date_drop(date, _ctx);
  return _x;
}
 
// Automatically generated. Retrieves the `day` constructor field of the `:date` type.

static inline kk_integer_t kk_std_time_date_day(kk_std_time_date__date date, kk_context_t* _ctx) { /* (date : date) -> int */ 
  kk_integer_t _x = date.day;
  kk_integer_dup(_x);
  kk_std_time_date__date_drop(date, _ctx);
  return _x;
}

kk_std_time_date__date kk_std_time_date__copy_1(kk_std_time_date__date _this, kk_std_core_types__optional year0, kk_std_core_types__optional month0, kk_std_core_types__optional day0, kk_context_t* _ctx); /* (date, year : optional<int>, month : optional<int>, day : optional<int>) -> date */ 
 
// Automatically generated. Tests for the `Mon` constructor of the `:weekday` type.

static inline bool kk_std_time_date_is_mon(kk_std_time_date__weekday weekday0, kk_context_t* _ctx) { /* (weekday : weekday) -> bool */ 
  if (kk_std_time_date__is_Mon(weekday0)) {
    return true;
  }
  return false;
}
 
// Automatically generated. Tests for the `Tue` constructor of the `:weekday` type.

static inline bool kk_std_time_date_is_tue(kk_std_time_date__weekday weekday0, kk_context_t* _ctx) { /* (weekday : weekday) -> bool */ 
  if (kk_std_time_date__is_Tue(weekday0)) {
    return true;
  }
  return false;
}
 
// Automatically generated. Tests for the `Wed` constructor of the `:weekday` type.

static inline bool kk_std_time_date_is_wed(kk_std_time_date__weekday weekday0, kk_context_t* _ctx) { /* (weekday : weekday) -> bool */ 
  if (kk_std_time_date__is_Wed(weekday0)) {
    return true;
  }
  return false;
}
 
// Automatically generated. Tests for the `Thu` constructor of the `:weekday` type.

static inline bool kk_std_time_date_is_thu(kk_std_time_date__weekday weekday0, kk_context_t* _ctx) { /* (weekday : weekday) -> bool */ 
  if (kk_std_time_date__is_Thu(weekday0)) {
    return true;
  }
  return false;
}
 
// Automatically generated. Tests for the `Fri` constructor of the `:weekday` type.

static inline bool kk_std_time_date_is_fri(kk_std_time_date__weekday weekday0, kk_context_t* _ctx) { /* (weekday : weekday) -> bool */ 
  if (kk_std_time_date__is_Fri(weekday0)) {
    return true;
  }
  return false;
}
 
// Automatically generated. Tests for the `Sat` constructor of the `:weekday` type.

static inline bool kk_std_time_date_is_sat(kk_std_time_date__weekday weekday0, kk_context_t* _ctx) { /* (weekday : weekday) -> bool */ 
  if (kk_std_time_date__is_Sat(weekday0)) {
    return true;
  }
  return false;
}
 
// Automatically generated. Tests for the `Sun` constructor of the `:weekday` type.

static inline bool kk_std_time_date_is_sun(kk_std_time_date__weekday weekday0, kk_context_t* _ctx) { /* (weekday : weekday) -> bool */ 
  if (kk_std_time_date__is_Sun(weekday0)) {
    return true;
  }
  return false;
}

kk_integer_t kk_std_time_date_int(kk_std_time_date__weekday wd, kk_context_t* _ctx); /* (wd : weekday) -> int */ 

kk_std_time_date__date kk_std_time_date__lp__plus__rp_(kk_std_time_date__date d1, kk_std_time_date__date d2, kk_context_t* _ctx); /* (d1 : date, d2 : date) -> date */ 

kk_std_time_date__clock kk_std_time_date__lp__plus__1_rp_(kk_std_time_date__clock c, kk_std_time_date__clock d, kk_context_t* _ctx); /* (c : clock, d : clock) -> clock */ 

kk_std_time_date__weekday kk_std_time_date_weekday(kk_integer_t i, kk_context_t* _ctx); /* (i : int) -> weekday */ 

kk_std_time_date__weekday kk_std_time_date__lp__plus__2_rp_(kk_std_time_date__weekday wd, kk_integer_t n, kk_context_t* _ctx); /* (wd : weekday, n : int) -> weekday */ 

kk_std_time_date__weekday kk_std_time_date__lp__dash__rp_(kk_std_time_date__weekday wd, kk_integer_t n, kk_context_t* _ctx); /* (wd : weekday, n : int) -> weekday */ 
 
// Return the difference between two week days:
// `wd2 == wd1 + (wd2 - wd1)`

static inline kk_integer_t kk_std_time_date__lp__dash__1_rp_(kk_std_time_date__weekday wd1, kk_std_time_date__weekday wd2, kk_context_t* _ctx) { /* (wd1 : weekday, wd2 : weekday) -> int */ 
  kk_integer_t _x10137;
  kk_integer_t _x10138 = kk_std_time_date_int(wd1, _ctx); /*int*/
  kk_integer_t _x10139 = kk_std_time_date_int(wd2, _ctx); /*int*/
  _x10137 = kk_integer_sub(_x10138,_x10139,kk_context()); /*int*/
  return kk_integer_mod(_x10137,(kk_integer_from_small(7)),kk_context());
}

kk_std_core_types__order kk_std_time_date_compare(kk_std_time_date__date d, kk_std_time_date__date e, kk_context_t* _ctx); /* (d : date, e : date) -> order */ 

bool kk_std_time_date__lp__eq__eq__rp_(kk_std_time_date__date i, kk_std_time_date__date j, kk_context_t* _ctx); /* (i : date, j : date) -> bool */ 

kk_std_num_ddouble__ddouble kk_std_time_date_total_seconds(kk_std_time_date__clock c, kk_context_t* _ctx); /* (c : clock) -> std/num/ddouble/ddouble */ 

kk_std_core_types__order kk_std_time_date_compare_1(kk_std_time_date__clock c, kk_std_time_date__clock d, kk_context_t* _ctx); /* (c : clock, d : clock) -> order */ 

bool kk_std_time_date__lp__eq__eq__1_rp_(kk_std_time_date__clock i, kk_std_time_date__clock j, kk_context_t* _ctx); /* (i : clock, j : clock) -> bool */ 
 
// Compare weekdays.

static inline kk_std_core_types__order kk_std_time_date_compare_2(kk_std_time_date__weekday wd1, kk_std_time_date__weekday wd2, kk_context_t* _ctx) { /* (wd1 : weekday, wd2 : weekday) -> order */ 
  kk_integer_t _x10171 = kk_std_time_date_int(wd1, _ctx); /*int*/
  kk_integer_t _x10172 = kk_std_time_date_int(wd2, _ctx); /*int*/
  return kk_int_as_order(kk_integer_cmp(_x10171,_x10172,kk_context()),kk_context());
}

bool kk_std_time_date__lp__eq__eq__2_rp_(kk_std_time_date__weekday i, kk_std_time_date__weekday j, kk_context_t* _ctx); /* (i : weekday, j : weekday) -> bool */ 

kk_std_time_date__clock kk_std_time_date_clock_2(kk_integer_t seconds0, kk_std_core_types__optional frac, kk_context_t* _ctx); /* (seconds : int, frac : optional<std/num/ddouble/ddouble>) -> clock */ 

kk_std_time_date__clock kk_std_time_date_clock(kk_std_num_ddouble__ddouble seconds0, kk_context_t* _ctx); /* (seconds : std/num/ddouble/ddouble) -> clock */ 

kk_std_time_date__clock kk_std_time_date_clock_1(kk_integer_t seconds0, double frac, kk_context_t* _ctx); /* (seconds : int, frac : double) -> clock */ 

kk_std_time_date__clock kk_std_time_date_clock_3(kk_std_num_ddouble__ddouble seconds0, kk_integer_t leap, kk_context_t* _ctx); /* (seconds : std/num/ddouble/ddouble, leap : int) -> clock */ 

bool kk_std_time_date__lp__excl__eq__rp_(kk_std_time_date__date i, kk_std_time_date__date j, kk_context_t* _ctx); /* (i : date, j : date) -> bool */ 

bool kk_std_time_date__lp__excl__eq__1_rp_(kk_std_time_date__clock i, kk_std_time_date__clock j, kk_context_t* _ctx); /* (i : clock, j : clock) -> bool */ 

bool kk_std_time_date__lp__excl__eq__2_rp_(kk_std_time_date__weekday i, kk_std_time_date__weekday j, kk_context_t* _ctx); /* (i : weekday, j : weekday) -> bool */ 

bool kk_std_time_date__lp__lt__rp_(kk_std_time_date__date i, kk_std_time_date__date j, kk_context_t* _ctx); /* (i : date, j : date) -> bool */ 

bool kk_std_time_date__lp__lt__1_rp_(kk_std_time_date__clock i, kk_std_time_date__clock j, kk_context_t* _ctx); /* (i : clock, j : clock) -> bool */ 

bool kk_std_time_date__lp__lt__2_rp_(kk_std_time_date__weekday i, kk_std_time_date__weekday j, kk_context_t* _ctx); /* (i : weekday, j : weekday) -> bool */ 

bool kk_std_time_date__lp__lt__eq__rp_(kk_std_time_date__date i, kk_std_time_date__date j, kk_context_t* _ctx); /* (i : date, j : date) -> bool */ 

bool kk_std_time_date__lp__lt__eq__1_rp_(kk_std_time_date__clock i, kk_std_time_date__clock j, kk_context_t* _ctx); /* (i : clock, j : clock) -> bool */ 

bool kk_std_time_date__lp__lt__eq__2_rp_(kk_std_time_date__weekday i, kk_std_time_date__weekday j, kk_context_t* _ctx); /* (i : weekday, j : weekday) -> bool */ 

bool kk_std_time_date__lp__gt__rp_(kk_std_time_date__date i, kk_std_time_date__date j, kk_context_t* _ctx); /* (i : date, j : date) -> bool */ 

bool kk_std_time_date__lp__gt__1_rp_(kk_std_time_date__clock i, kk_std_time_date__clock j, kk_context_t* _ctx); /* (i : clock, j : clock) -> bool */ 

bool kk_std_time_date__lp__gt__2_rp_(kk_std_time_date__weekday i, kk_std_time_date__weekday j, kk_context_t* _ctx); /* (i : weekday, j : weekday) -> bool */ 

bool kk_std_time_date__lp__gt__eq__rp_(kk_std_time_date__date i, kk_std_time_date__date j, kk_context_t* _ctx); /* (i : date, j : date) -> bool */ 

bool kk_std_time_date__lp__gt__eq__1_rp_(kk_std_time_date__clock i, kk_std_time_date__clock j, kk_context_t* _ctx); /* (i : clock, j : clock) -> bool */ 

bool kk_std_time_date__lp__gt__eq__2_rp_(kk_std_time_date__weekday i, kk_std_time_date__weekday j, kk_context_t* _ctx); /* (i : weekday, j : weekday) -> bool */ 

extern kk_std_time_date__clock kk_std_time_date_clock0;

kk_std_time_date__date kk_std_time_date_easter(kk_integer_t year0, kk_context_t* _ctx); /* (year : int) -> date */ 

bool kk_std_time_date_is_zero(kk_std_time_date__clock c, kk_context_t* _ctx); /* (c : clock) -> bool */ 

kk_integer_t kk_std_time_date_milli_seconds(kk_std_time_date__clock c, kk_context_t* _ctx); /* (c : clock) -> int */ 

kk_integer_t kk_std_time_date_nano_seconds(kk_std_time_date__clock c, kk_context_t* _ctx); /* (c : clock) -> int */ 

kk_std_time_date__clock kk_std_time_date_round_to_prec(kk_std_time_date__clock c, kk_std_core_types__optional prec, kk_context_t* _ctx); /* (c : clock, prec : optional<int>) -> clock */ 

kk_string_t kk_std_time_date_show_seconds(kk_std_num_ddouble__ddouble secs, kk_std_core_types__optional max_prec, kk_std_core_types__optional secs_width, kk_std_core_types__optional unit, kk_context_t* _ctx); /* (secs : std/num/ddouble/ddouble, max-prec : optional<int>, secs-width : optional<int>, unit : optional<string>) -> string */ 

kk_string_t kk_std_time_date_show0(kk_integer_t i, kk_std_core_types__optional width, kk_context_t* _ctx); /* (i : int, width : optional<int>) -> string */ 

kk_string_t kk_std_time_date_show_year(kk_integer_t year0, kk_context_t* _ctx); /* (year : int) -> string */ 

kk_string_t kk_std_time_date_show(kk_std_time_date__date d, kk_std_core_types__optional month_prefix, kk_context_t* _ctx); /* (d : date, month-prefix : optional<string>) -> string */ 

kk_string_t kk_std_time_date_show_1(kk_std_time_date__clock c, kk_std_core_types__optional prec, kk_context_t* _ctx); /* (c : clock, prec : optional<int>) -> string */ 

kk_string_t kk_std_time_date_show_2(kk_std_time_date__weekday wd, kk_context_t* _ctx); /* (wd : weekday) -> string */ 

kk_string_t kk_std_time_date_show_short(kk_std_time_date__weekday wd, kk_context_t* _ctx); /* (wd : weekday) -> string */ 
 
// Create an ISO weekdate where the "month" is the ISO week number.

static inline kk_std_time_date__date kk_std_time_date_weekdate(kk_integer_t year0, kk_integer_t month0, kk_std_time_date__weekday weekday0, kk_context_t* _ctx) { /* (year : int, month : int, weekday : weekday) -> date */ 
  kk_integer_t _x10566 = kk_std_time_date_int(weekday0, _ctx); /*int*/
  return kk_std_time_date__new_Date(year0, month0, _x10566, _ctx);
}

kk_integer_t kk_std_time_date_whole_seconds(kk_std_time_date__clock c, kk_context_t* _ctx); /* (c : clock) -> int */ 

void kk_std_time_date__init(kk_context_t* _ctx);

#endif // header
