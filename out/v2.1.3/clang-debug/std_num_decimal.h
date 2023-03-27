#pragma once
#ifndef kk_std_num_decimal_H
#define kk_std_num_decimal_H
// Koka generated module: "std/num/decimal", koka version: 2.1.3
#include <kklib.h>
#include "std_core_types.h"
#include "std_core_hnd.h"
#include "std_core.h"
#include "std_text_parse.h"
#include "std_num_double.h"

// type declarations

// value type std/num/decimal/decimal
struct kk_std_num_decimal_Decimal {
  kk_integer_t num;
  kk_integer_t exp;
};
typedef struct kk_std_num_decimal_Decimal kk_std_num_decimal__decimal;
static inline kk_std_num_decimal__decimal kk_std_num_decimal__new_Decimal(kk_integer_t num, kk_integer_t exp, kk_context_t* _ctx){
  kk_std_num_decimal__decimal _con;
  _con.num = num;
  _con.exp = exp;
  return _con;
}
static inline bool kk_std_num_decimal__is_Decimal(kk_std_num_decimal__decimal x) {
  return (true);
}
static inline kk_std_num_decimal__decimal kk_std_num_decimal__decimal_dup(kk_std_num_decimal__decimal _x) {
  kk_integer_dup(_x.num);
  kk_integer_dup(_x.exp);
  return _x;
}
static inline void kk_std_num_decimal__decimal_drop(kk_std_num_decimal__decimal _x, kk_context_t* _ctx) {
  kk_integer_drop(_x.num, _ctx);
  kk_integer_drop(_x.exp, _ctx);
}
static inline kk_box_t kk_std_num_decimal__decimal_box(kk_std_num_decimal__decimal _x, kk_context_t* _ctx) {
  kk_box_t _box;
  kk_valuetype_box(kk_std_num_decimal__decimal, _box, _x, 2 /* scan count */, _ctx);
  return _box;
}
static inline kk_std_num_decimal__decimal kk_std_num_decimal__decimal_unbox(kk_box_t _x, kk_context_t* _ctx) {
  kk_boxed_value_t _p;
  kk_std_num_decimal__decimal _unbox;
  kk_valuetype_unbox_(kk_std_num_decimal__decimal, _p, _unbox, _x, _ctx);
  if (_ctx!=NULL && _p!=NULL) {
    if (kk_basetype_is_unique(_p)) { kk_basetype_free(_p); } else {
      kk_std_num_decimal__decimal_dup(_unbox);
      kk_basetype_decref(_p, _ctx);
    }
  }
  return _unbox;
}

// value type std/num/decimal/round
enum kk_std_num_decimal__round_e {
  kk_std_num_decimal_Half_even,
  kk_std_num_decimal_Half_ceiling,
  kk_std_num_decimal_Half_floor,
  kk_std_num_decimal_Half_truncate,
  kk_std_num_decimal_Half_away_from_zero,
  kk_std_num_decimal_Ceiling,
  kk_std_num_decimal_Floor,
  kk_std_num_decimal_Truncate,
  kk_std_num_decimal_Away_from_zero
};
typedef uint8_t kk_std_num_decimal__round;

static inline kk_std_num_decimal__round kk_std_num_decimal__new_Half_even(kk_context_t* _ctx){
  return kk_std_num_decimal_Half_even;
}
static inline kk_std_num_decimal__round kk_std_num_decimal__new_Half_ceiling(kk_context_t* _ctx){
  return kk_std_num_decimal_Half_ceiling;
}
static inline kk_std_num_decimal__round kk_std_num_decimal__new_Half_floor(kk_context_t* _ctx){
  return kk_std_num_decimal_Half_floor;
}
static inline kk_std_num_decimal__round kk_std_num_decimal__new_Half_truncate(kk_context_t* _ctx){
  return kk_std_num_decimal_Half_truncate;
}
static inline kk_std_num_decimal__round kk_std_num_decimal__new_Half_away_from_zero(kk_context_t* _ctx){
  return kk_std_num_decimal_Half_away_from_zero;
}
static inline kk_std_num_decimal__round kk_std_num_decimal__new_Ceiling(kk_context_t* _ctx){
  return kk_std_num_decimal_Ceiling;
}
static inline kk_std_num_decimal__round kk_std_num_decimal__new_Floor(kk_context_t* _ctx){
  return kk_std_num_decimal_Floor;
}
static inline kk_std_num_decimal__round kk_std_num_decimal__new_Truncate(kk_context_t* _ctx){
  return kk_std_num_decimal_Truncate;
}
static inline kk_std_num_decimal__round kk_std_num_decimal__new_Away_from_zero(kk_context_t* _ctx){
  return kk_std_num_decimal_Away_from_zero;
}
static inline bool kk_std_num_decimal__is_Half_even(kk_std_num_decimal__round x) {
  return (x == kk_std_num_decimal_Half_even);
}
static inline bool kk_std_num_decimal__is_Half_ceiling(kk_std_num_decimal__round x) {
  return (x == kk_std_num_decimal_Half_ceiling);
}
static inline bool kk_std_num_decimal__is_Half_floor(kk_std_num_decimal__round x) {
  return (x == kk_std_num_decimal_Half_floor);
}
static inline bool kk_std_num_decimal__is_Half_truncate(kk_std_num_decimal__round x) {
  return (x == kk_std_num_decimal_Half_truncate);
}
static inline bool kk_std_num_decimal__is_Half_away_from_zero(kk_std_num_decimal__round x) {
  return (x == kk_std_num_decimal_Half_away_from_zero);
}
static inline bool kk_std_num_decimal__is_Ceiling(kk_std_num_decimal__round x) {
  return (x == kk_std_num_decimal_Ceiling);
}
static inline bool kk_std_num_decimal__is_Floor(kk_std_num_decimal__round x) {
  return (x == kk_std_num_decimal_Floor);
}
static inline bool kk_std_num_decimal__is_Truncate(kk_std_num_decimal__round x) {
  return (x == kk_std_num_decimal_Truncate);
}
static inline bool kk_std_num_decimal__is_Away_from_zero(kk_std_num_decimal__round x) {
  return (x == kk_std_num_decimal_Away_from_zero);
}
static inline kk_std_num_decimal__round kk_std_num_decimal__round_dup(kk_std_num_decimal__round _x) {
  return _x;
}
static inline void kk_std_num_decimal__round_drop(kk_std_num_decimal__round _x, kk_context_t* _ctx) {
  
}
static inline kk_box_t kk_std_num_decimal__round_box(kk_std_num_decimal__round _x, kk_context_t* _ctx) {
  return kk_enum_box(_x);
}
static inline kk_std_num_decimal__round kk_std_num_decimal__round_unbox(kk_box_t _x, kk_context_t* _ctx) {
  return (kk_std_num_decimal__round)kk_enum_unbox(_x);
}

// value declarations
 
// Automatically generated. Retrieves the `num` constructor field of the `:decimal` type.

static inline kk_integer_t kk_std_num_decimal_num(kk_std_num_decimal__decimal decimal0, kk_context_t* _ctx) { /* (decimal : decimal) -> int */ 
  kk_integer_t _x = decimal0.num;
  kk_integer_dup(_x);
  kk_std_num_decimal__decimal_drop(decimal0, _ctx);
  return _x;
}
 
// Automatically generated. Retrieves the `exp` constructor field of the `:decimal` type.

static inline kk_integer_t kk_std_num_decimal_exp(kk_std_num_decimal__decimal decimal0, kk_context_t* _ctx) { /* (decimal : decimal) -> int */ 
  kk_integer_t _x = decimal0.exp;
  kk_integer_dup(_x);
  kk_std_num_decimal__decimal_drop(decimal0, _ctx);
  return _x;
}

kk_std_num_decimal__decimal kk_std_num_decimal__copy(kk_std_num_decimal__decimal _this, kk_std_core_types__optional num0, kk_std_core_types__optional exp0, kk_context_t* _ctx); /* (decimal, num : optional<int>, exp : optional<int>) -> decimal */ 
 
// Automatically generated. Tests for the `Half-even` constructor of the `:round` type.

static inline bool kk_std_num_decimal_is_half_even(kk_std_num_decimal__round round0, kk_context_t* _ctx) { /* (round : round) -> bool */ 
  if (kk_std_num_decimal__is_Half_even(round0)) {
    return true;
  }
  return false;
}
 
// Automatically generated. Tests for the `Half-ceiling` constructor of the `:round` type.

static inline bool kk_std_num_decimal_is_half_ceiling(kk_std_num_decimal__round round0, kk_context_t* _ctx) { /* (round : round) -> bool */ 
  if (kk_std_num_decimal__is_Half_ceiling(round0)) {
    return true;
  }
  return false;
}
 
// Automatically generated. Tests for the `Half-floor` constructor of the `:round` type.

static inline bool kk_std_num_decimal_is_half_floor(kk_std_num_decimal__round round0, kk_context_t* _ctx) { /* (round : round) -> bool */ 
  if (kk_std_num_decimal__is_Half_floor(round0)) {
    return true;
  }
  return false;
}
 
// Automatically generated. Tests for the `Half-truncate` constructor of the `:round` type.

static inline bool kk_std_num_decimal_is_half_truncate(kk_std_num_decimal__round round0, kk_context_t* _ctx) { /* (round : round) -> bool */ 
  if (kk_std_num_decimal__is_Half_truncate(round0)) {
    return true;
  }
  return false;
}
 
// Automatically generated. Tests for the `Half-away-from-zero` constructor of the `:round` type.

static inline bool kk_std_num_decimal_is_half_away_from_zero(kk_std_num_decimal__round round0, kk_context_t* _ctx) { /* (round : round) -> bool */ 
  if (kk_std_num_decimal__is_Half_away_from_zero(round0)) {
    return true;
  }
  return false;
}
 
// Automatically generated. Tests for the `Ceiling` constructor of the `:round` type.

static inline bool kk_std_num_decimal_is_ceiling(kk_std_num_decimal__round round0, kk_context_t* _ctx) { /* (round : round) -> bool */ 
  if (kk_std_num_decimal__is_Ceiling(round0)) {
    return true;
  }
  return false;
}
 
// Automatically generated. Tests for the `Floor` constructor of the `:round` type.

static inline bool kk_std_num_decimal_is_floor(kk_std_num_decimal__round round0, kk_context_t* _ctx) { /* (round : round) -> bool */ 
  if (kk_std_num_decimal__is_Floor(round0)) {
    return true;
  }
  return false;
}
 
// Automatically generated. Tests for the `Truncate` constructor of the `:round` type.

static inline bool kk_std_num_decimal_is_truncate(kk_std_num_decimal__round round0, kk_context_t* _ctx) { /* (round : round) -> bool */ 
  if (kk_std_num_decimal__is_Truncate(round0)) {
    return true;
  }
  return false;
}
 
// Automatically generated. Tests for the `Away-from-zero` constructor of the `:round` type.

static inline bool kk_std_num_decimal_is_away_from_zero(kk_std_num_decimal__round round0, kk_context_t* _ctx) { /* (round : round) -> bool */ 
  if (kk_std_num_decimal__is_Away_from_zero(round0)) {
    return true;
  }
  return false;
}
#define kk_std_num_decimal_maxpd ((double)(0x1.c6bf52634p49))
 
// Optimize: Use double division when within precision bounds.

extern kk_integer_t kk_std_num_decimal_maxexp;

bool kk_std_num_decimal_is_neg(kk_std_num_decimal__decimal x, kk_context_t* _ctx); /* (x : decimal) -> bool */ 
 
// Is this decimal zero?

static inline bool kk_std_num_decimal_is_zero(kk_std_num_decimal__decimal x, kk_context_t* _ctx) { /* (x : decimal) -> bool */ 
  kk_integer_t _x6753;
  kk_integer_t _x = x.num;
  kk_integer_dup(_x);
  kk_std_num_decimal__decimal_drop(x, _ctx);
  _x6753 = _x; /*int*/
  return kk_integer_is_zero(_x6753,kk_context());
}

bool kk_std_num_decimal_is_pos(kk_std_num_decimal__decimal x, kk_context_t* _ctx); /* (x : decimal) -> bool */ 

kk_integer_t kk_std_num_decimal_round_exp(kk_integer_t exp0, kk_context_t* _ctx); /* (exp : int) -> int */ 

kk_std_num_decimal__decimal kk_std_num_decimal_decimal_exp(kk_integer_t i, kk_std_core_types__optional exp0, kk_context_t* _ctx); /* (i : int, exp : optional<int>) -> decimal */ 

kk_std_num_decimal__decimal kk_std_num_decimal_expand(kk_std_num_decimal__decimal x, kk_integer_t e, kk_context_t* _ctx); /* (x : decimal, e : int) -> decimal */ 

kk_std_core_types__order kk_std_num_decimal_compare(kk_std_num_decimal__decimal x, kk_std_num_decimal__decimal y, kk_context_t* _ctx); /* (x : decimal, y : decimal) -> order */ 

bool kk_std_num_decimal__lp__excl__eq__rp_(kk_std_num_decimal__decimal x, kk_std_num_decimal__decimal y, kk_context_t* _ctx); /* (x : decimal, y : decimal) -> bool */ 

kk_std_num_decimal__decimal kk_std_num_decimal_reduce(kk_std_num_decimal__decimal x, kk_context_t* _ctx); /* (x : decimal) -> decimal */ 

kk_std_num_decimal__decimal kk_std_num_decimal__lp__star__rp_(kk_std_num_decimal__decimal x, kk_std_num_decimal__decimal y, kk_context_t* _ctx); /* (x : decimal, y : decimal) -> decimal */ 

kk_std_num_decimal__decimal kk_std_num_decimal__lp__plus__rp_(kk_std_num_decimal__decimal x, kk_std_num_decimal__decimal y, kk_context_t* _ctx); /* (x : decimal, y : decimal) -> decimal */ 
 
// Negate a decimal.

static inline kk_std_num_decimal__decimal kk_std_num_decimal__lp__tilde__rp_(kk_std_num_decimal__decimal x, kk_context_t* _ctx) { /* (x : decimal) -> decimal */ 
  kk_integer_t _x6869;
  kk_integer_t _x6870;
  kk_integer_t _x = x.num;
  kk_integer_dup(_x);
  _x6870 = _x; /*int*/
  _x6869 = kk_integer_neg(_x6870,kk_context()); /*int*/
  kk_integer_t _x6871;
  kk_integer_t _x0 = x.exp;
  kk_integer_dup(_x0);
  kk_std_num_decimal__decimal_drop(x, _ctx);
  _x6871 = _x0; /*int*/
  return kk_std_num_decimal__new_Decimal(_x6869, _x6871, _ctx);
}

kk_std_num_decimal__decimal kk_std_num_decimal__lp__dash__rp_(kk_std_num_decimal__decimal x, kk_std_num_decimal__decimal y, kk_context_t* _ctx); /* (x : decimal, y : decimal) -> decimal */ 
 
// The decimal zero.

extern kk_std_num_decimal__decimal kk_std_num_decimal_zero;

kk_std_num_decimal__decimal kk_std_num_decimal_div(kk_std_num_decimal__decimal x, kk_std_num_decimal__decimal y, kk_std_core_types__optional min_prec, kk_context_t* _ctx); /* (x : decimal, y : decimal, min-prec : optional<int>) -> decimal */ 
 
// Divide two decimals using 15 digits of extra precision.

static inline kk_std_num_decimal__decimal kk_std_num_decimal__lp__fs__rp_(kk_std_num_decimal__decimal x, kk_std_num_decimal__decimal y, kk_context_t* _ctx) { /* (x : decimal, y : decimal) -> decimal */ 
  return kk_std_num_decimal_div(x, y, kk_std_core_types__new_None(_ctx), _ctx);
}

bool kk_std_num_decimal__lp__lt__rp_(kk_std_num_decimal__decimal x, kk_std_num_decimal__decimal y, kk_context_t* _ctx); /* (x : decimal, y : decimal) -> bool */ 

bool kk_std_num_decimal__lp__lt__eq__rp_(kk_std_num_decimal__decimal x, kk_std_num_decimal__decimal y, kk_context_t* _ctx); /* (x : decimal, y : decimal) -> bool */ 

bool kk_std_num_decimal__lp__eq__eq__rp_(kk_std_num_decimal__decimal x, kk_std_num_decimal__decimal y, kk_context_t* _ctx); /* (x : decimal, y : decimal) -> bool */ 

bool kk_std_num_decimal__lp__gt__rp_(kk_std_num_decimal__decimal x, kk_std_num_decimal__decimal y, kk_context_t* _ctx); /* (x : decimal, y : decimal) -> bool */ 

bool kk_std_num_decimal__lp__gt__eq__rp_(kk_std_num_decimal__decimal x, kk_std_num_decimal__decimal y, kk_context_t* _ctx); /* (x : decimal, y : decimal) -> bool */ 
 
// The absolute value of a decimal

static inline kk_std_num_decimal__decimal kk_std_num_decimal_abs(kk_std_num_decimal__decimal x, kk_context_t* _ctx) { /* (x : decimal) -> decimal */ 
  bool _match_6708;
  kk_std_num_decimal__decimal _x6952 = kk_std_num_decimal__decimal_dup(x); /*std/num/decimal/decimal*/
  _match_6708 = kk_std_num_decimal_is_neg(_x6952, _ctx); /*bool*/
  if (_match_6708) {
    return kk_std_num_decimal__lp__tilde__rp_(x, _ctx);
  }
  return x;
}

kk_std_num_decimal__decimal kk_std_num_decimal_decimal(kk_integer_t i, kk_std_core_types__optional exp0, kk_context_t* _ctx); /* (i : int, exp : optional<int>) -> decimal */ 

kk_std_num_decimal__decimal kk_std_num_decimal_pow(kk_std_num_decimal__decimal x, kk_integer_t n, kk_context_t* _ctx); /* (x : decimal, n : int) -> decimal */ 

kk_std_num_decimal__decimal kk_std_num_decimal_decimal_1(double d, kk_std_core_types__optional max_prec, kk_context_t* _ctx); /* (d : double, max-prec : optional<int>) -> decimal */ 

kk_std_num_decimal__decimal kk_std_num_decimal_max(kk_std_num_decimal__decimal x, kk_std_num_decimal__decimal y, kk_context_t* _ctx); /* (x : decimal, y : decimal) -> decimal */ 

kk_std_num_decimal__decimal kk_std_num_decimal_min(kk_std_num_decimal__decimal x, kk_std_num_decimal__decimal y, kk_context_t* _ctx); /* (x : decimal, y : decimal) -> decimal */ 
 
// Increment a decimal

static inline kk_std_num_decimal__decimal kk_std_num_decimal_inc(kk_std_num_decimal__decimal x, kk_context_t* _ctx) { /* (x : decimal) -> decimal */ 
  kk_integer_t _x7106;
  kk_integer_t _x7107;
  kk_integer_t _x = x.num;
  kk_integer_dup(_x);
  _x7107 = _x; /*int*/
  _x7106 = kk_integer_add(_x7107,(kk_integer_from_small(1)),kk_context()); /*int*/
  kk_integer_t _x7108;
  kk_integer_t _x0 = x.exp;
  kk_integer_dup(_x0);
  kk_std_num_decimal__decimal_drop(x, _ctx);
  _x7108 = _x0; /*int*/
  return kk_std_num_decimal__new_Decimal(_x7106, _x7108, _ctx);
}
 
// Is this an even decimal?

static inline bool kk_std_num_decimal_is_even(kk_std_num_decimal__decimal x, kk_context_t* _ctx) { /* (x : decimal) -> bool */ 
  bool _x7109;
  kk_integer_t _x7110;
  kk_integer_t _x = x.num;
  kk_integer_dup(_x);
  kk_std_num_decimal__decimal_drop(x, _ctx);
  _x7110 = _x; /*int*/
  _x7109 = kk_integer_is_odd(_x7110,kk_context()); /*bool*/
  return !(_x7109);
}

kk_std_num_decimal__decimal kk_std_num_decimal_round_to_prec(kk_std_num_decimal__decimal x, kk_std_core_types__optional prec, kk_std_core_types__optional rnd, kk_context_t* _ctx); /* (x : decimal, prec : optional<int>, rnd : optional<round>) -> total decimal */ 

kk_std_num_decimal__decimal kk_std_num_decimal_round(kk_std_num_decimal__decimal x, kk_std_core_types__optional rnd, kk_context_t* _ctx); /* (x : decimal, rnd : optional<round>) -> decimal */ 

kk_std_num_decimal__decimal kk_std_num_decimal_ceiling(kk_std_num_decimal__decimal x, kk_context_t* _ctx); /* (x : decimal) -> decimal */ 
 
// Decrement a decimal

static inline kk_std_num_decimal__decimal kk_std_num_decimal_dec(kk_std_num_decimal__decimal x, kk_context_t* _ctx) { /* (x : decimal) -> decimal */ 
  kk_integer_t _x7184;
  kk_integer_t _x7185;
  kk_integer_t _x = x.num;
  kk_integer_dup(_x);
  _x7185 = _x; /*int*/
  _x7184 = kk_integer_sub(_x7185,(kk_integer_from_small(1)),kk_context()); /*int*/
  kk_integer_t _x7186;
  kk_integer_t _x0 = x.exp;
  kk_integer_dup(_x0);
  kk_std_num_decimal__decimal_drop(x, _ctx);
  _x7186 = _x0; /*int*/
  return kk_std_num_decimal__new_Decimal(_x7184, _x7186, _ctx);
}

double kk_std_num_decimal_double(kk_std_num_decimal__decimal x, kk_context_t* _ctx); /* (x : decimal) -> double */ 

kk_integer_t kk_std_num_decimal_exponent(kk_std_num_decimal__decimal d, kk_context_t* _ctx); /* (d : decimal) -> int */ 

kk_std_num_decimal__decimal kk_std_num_decimal_floor(kk_std_num_decimal__decimal x, kk_context_t* _ctx); /* (x : decimal) -> decimal */ 

kk_std_num_decimal__decimal kk_std_num_decimal_ffraction(kk_std_num_decimal__decimal x, kk_context_t* _ctx); /* (x : decimal) -> decimal */ 

kk_std_num_decimal__decimal kk_std_num_decimal_truncate(kk_std_num_decimal__decimal x, kk_context_t* _ctx); /* (x : decimal) -> decimal */ 

kk_std_num_decimal__decimal kk_std_num_decimal_fraction(kk_std_num_decimal__decimal x, kk_context_t* _ctx); /* (x : decimal) -> decimal */ 

kk_integer_t kk_std_num_decimal_int(kk_std_num_decimal__decimal x, kk_std_core_types__optional rnd, kk_context_t* _ctx); /* (x : decimal, rnd : optional<round>) -> int */ 
 
// Is this an odd decimal?

static inline bool kk_std_num_decimal_is_odd(kk_std_num_decimal__decimal x, kk_context_t* _ctx) { /* (x : decimal) -> bool */ 
  kk_integer_t _x7281;
  kk_integer_t _x = x.num;
  kk_integer_dup(_x);
  kk_std_num_decimal__decimal_drop(x, _ctx);
  _x7281 = _x; /*int*/
  return kk_integer_is_odd(_x7281,kk_context());
}

extern kk_integer_t kk_std_num_decimal_maxprecise;

extern kk_integer_t kk_std_num_decimal_minprecise;

bool kk_std_num_decimal_is_precise(kk_integer_t i, kk_context_t* _ctx); /* (i : int) -> bool */ 
 
// The sign of a decimal number.

static inline kk_std_core_types__order kk_std_num_decimal_sign(kk_std_num_decimal__decimal x, kk_context_t* _ctx) { /* (x : decimal) -> order */ 
  kk_integer_t _x7286;
  kk_integer_t _x = x.num;
  kk_integer_dup(_x);
  kk_std_num_decimal__decimal_drop(x, _ctx);
  _x7286 = _x; /*int*/
  return kk_int_as_order(kk_integer_signum(_x7286,kk_context()),kk_context());
}

kk_integer_t kk_std_num_decimal__mlift6016_pdecimal(kk_char_t wild__0, kk_context_t* _ctx); /* (wild_0 : char) -> std/text/parse/parse int */ 

kk_std_num_decimal__decimal kk_std_num_decimal__mlift6017_pdecimal(kk_string_t frac, bool neg, kk_string_t whole, kk_integer_t exp0, kk_context_t* _ctx); /* (frac : string, neg : bool, whole : string, exp : int) -> std/text/parse/parse decimal */ 

kk_string_t kk_std_num_decimal__mlift6018_pdecimal(kk_char_t wild__, kk_context_t* _ctx); /* (wild_ : char) -> std/text/parse/parse string */ 

kk_std_num_decimal__decimal kk_std_num_decimal__mlift6019_pdecimal(bool neg, kk_string_t whole, kk_string_t frac, kk_context_t* _ctx); /* (neg : bool, whole : string, frac : string) -> std/text/parse/parse decimal */ 

kk_std_num_decimal__decimal kk_std_num_decimal__mlift6020_pdecimal(bool neg, kk_string_t whole, kk_context_t* _ctx); /* (neg : bool, whole : string) -> std/text/parse/parse decimal */ 

kk_std_num_decimal__decimal kk_std_num_decimal__mlift6021_pdecimal(bool neg, kk_context_t* _ctx); /* (neg : bool) -> std/text/parse/parse decimal */ 

kk_std_num_decimal__decimal kk_std_num_decimal_pdecimal(kk_context_t* _ctx); /* () -> std/text/parse/parse decimal */ 

kk_std_core_types__maybe kk_std_num_decimal_parse_decimal(kk_string_t s, kk_context_t* _ctx); /* (s : string) -> maybe<decimal> */ 

kk_string_t kk_std_num_decimal_show_frac(kk_string_t frac, kk_integer_t prec, kk_context_t* _ctx); /* (frac : string, prec : int) -> string */ 

kk_string_t kk_std_num_decimal_show_exp(kk_std_num_decimal__decimal d, kk_std_core_types__optional prec, kk_context_t* _ctx); /* (d : decimal, prec : optional<int>) -> string */ 

kk_string_t kk_std_num_decimal_show_fixed(kk_std_num_decimal__decimal d, kk_std_core_types__optional prec, kk_context_t* _ctx); /* (d : decimal, prec : optional<int>) -> string */ 

kk_string_t kk_std_num_decimal_show(kk_std_num_decimal__decimal d, kk_std_core_types__optional prec, kk_context_t* _ctx); /* (d : decimal, prec : optional<int>) -> string */ 

kk_string_t kk_std_num_decimal_show_raw(kk_std_num_decimal__decimal d, kk_context_t* _ctx); /* (d : decimal) -> string */ 

kk_std_num_decimal__decimal kk_std_num_decimal_sum(kk_std_core__list ds, kk_context_t* _ctx); /* (ds : list<decimal>) -> decimal */ 

void kk_std_num_decimal__init(kk_context_t* _ctx);

#endif // header
