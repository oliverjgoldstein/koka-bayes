#pragma once
#ifndef kk_std_num_ddouble_H
#define kk_std_num_ddouble_H
// Koka generated module: "std/num/ddouble", koka version: 2.1.2
#include <kklib.h>
#include "std_core_types.h"
#include "std_core_hnd.h"
#include "std_core.h"
#include "std_text_parse.h"
#include "std_num_double.h"
#include "std_num_decimal.h"

// type declarations

// value type std/num/ddouble/ddouble
struct kk_std_num_ddouble_Ddouble {
  double hi;
  double lo;
};
typedef struct kk_std_num_ddouble_Ddouble kk_std_num_ddouble__ddouble;
static inline kk_std_num_ddouble__ddouble kk_std_num_ddouble__new_Ddouble(double hi, double lo, kk_context_t* _ctx){
  kk_std_num_ddouble__ddouble _con;
  _con.hi = hi;
  _con.lo = lo;
  return _con;
}
static inline bool kk_std_num_ddouble__is_Ddouble(kk_std_num_ddouble__ddouble x) {
  return (true);
}
static inline kk_std_num_ddouble__ddouble kk_std_num_ddouble__ddouble_dup(kk_std_num_ddouble__ddouble _x) {
  return _x;
}
static inline void kk_std_num_ddouble__ddouble_drop(kk_std_num_ddouble__ddouble _x, kk_context_t* _ctx) {
  
}
static inline kk_box_t kk_std_num_ddouble__ddouble_box(kk_std_num_ddouble__ddouble _x, kk_context_t* _ctx) {
  kk_box_t _box;
  kk_valuetype_box(kk_std_num_ddouble__ddouble, _box, _x, 0 /* scan count */, _ctx);
  return _box;
}
static inline kk_std_num_ddouble__ddouble kk_std_num_ddouble__ddouble_unbox(kk_box_t _x, kk_context_t* _ctx) {
  kk_boxed_value_t _p;
  kk_std_num_ddouble__ddouble _unbox;
  kk_valuetype_unbox_(kk_std_num_ddouble__ddouble, _p, _unbox, _x, _ctx);
  if (_ctx!=NULL && _p!=NULL) {
    if (kk_basetype_is_unique(_p)) { kk_basetype_free(_p); } else {
      kk_std_num_ddouble__ddouble_dup(_unbox);
      kk_basetype_decref(_p, _ctx);
    }
  }
  else { kk_std_num_ddouble__ddouble_dup(_unbox); }
  return _unbox;
}

// value type std/num/ddouble/edouble
struct kk_std_num_ddouble_Edouble {
  double num;
  double err;
};
typedef struct kk_std_num_ddouble_Edouble kk_std_num_ddouble__edouble;
static inline kk_std_num_ddouble__edouble kk_std_num_ddouble__new_Edouble(double num, double err, kk_context_t* _ctx){
  kk_std_num_ddouble__edouble _con;
  _con.num = num;
  _con.err = err;
  return _con;
}
static inline bool kk_std_num_ddouble__is_Edouble(kk_std_num_ddouble__edouble x) {
  return (true);
}
static inline kk_std_num_ddouble__edouble kk_std_num_ddouble__edouble_dup(kk_std_num_ddouble__edouble _x) {
  return _x;
}
static inline void kk_std_num_ddouble__edouble_drop(kk_std_num_ddouble__edouble _x, kk_context_t* _ctx) {
  
}
static inline kk_box_t kk_std_num_ddouble__edouble_box(kk_std_num_ddouble__edouble _x, kk_context_t* _ctx) {
  kk_box_t _box;
  kk_valuetype_box(kk_std_num_ddouble__edouble, _box, _x, 0 /* scan count */, _ctx);
  return _box;
}
static inline kk_std_num_ddouble__edouble kk_std_num_ddouble__edouble_unbox(kk_box_t _x, kk_context_t* _ctx) {
  kk_boxed_value_t _p;
  kk_std_num_ddouble__edouble _unbox;
  kk_valuetype_unbox_(kk_std_num_ddouble__edouble, _p, _unbox, _x, _ctx);
  if (_ctx!=NULL && _p!=NULL) {
    if (kk_basetype_is_unique(_p)) { kk_basetype_free(_p); } else {
      kk_std_num_ddouble__edouble_dup(_unbox);
      kk_basetype_decref(_p, _ctx);
    }
  }
  else { kk_std_num_ddouble__edouble_dup(_unbox); }
  return _unbox;
}

// value declarations
 
// Automatically generated. Retrieves the `hi` constructor field of the `:ddouble` type.

static inline double kk_std_num_ddouble_hi(kk_std_num_ddouble__ddouble ddouble0, kk_context_t* _ctx) { /* (ddouble : ddouble) -> double */ 
  double _x = ddouble0.hi;
  return _x;
}
 
// Automatically generated. Retrieves the `lo` constructor field of the `:ddouble` type.

static inline double kk_std_num_ddouble_lo(kk_std_num_ddouble__ddouble ddouble0, kk_context_t* _ctx) { /* (ddouble : ddouble) -> double */ 
  double _x = ddouble0.lo;
  return _x;
}

static inline kk_std_num_ddouble__ddouble kk_std_num_ddouble__copy(kk_std_num_ddouble__ddouble _this, kk_std_core_types__optional hi0, kk_std_core_types__optional lo0, kk_context_t* _ctx) { /* (ddouble, hi : optional<double>, lo : optional<double>) -> ddouble */ 
  double _x22014;
  if (kk_std_core_types__is_Optional(hi0)) {
    kk_box_t _box_x21207 = hi0._cons.Optional.value;
    double _hi_179 = kk_double_unbox(_box_x21207, NULL);
    _x22014 = _hi_179; /*double*/
    goto _match22015;
  }
  double _x = _this.hi;
  _x22014 = _x; /*double*/
  _match22015: ;
  double _x22017;
  if (kk_std_core_types__is_Optional(lo0)) {
    kk_box_t _box_x21208 = lo0._cons.Optional.value;
    double _lo_185 = kk_double_unbox(_box_x21208, NULL);
    _x22017 = _lo_185; /*double*/
    goto _match22018;
  }
  double _x0 = _this.lo;
  _x22017 = _x0; /*double*/
  _match22018: ;
  return kk_std_num_ddouble__new_Ddouble(_x22014, _x22017, _ctx);
}
 
// Automatically generated. Retrieves the `num` constructor field of the `:edouble` type.

static inline double kk_std_num_ddouble_num(kk_std_num_ddouble__edouble edouble, kk_context_t* _ctx) { /* (edouble : edouble) -> double */ 
  double _x = edouble.num;
  return _x;
}
 
// Automatically generated. Retrieves the `err` constructor field of the `:edouble` type.

static inline double kk_std_num_ddouble_err(kk_std_num_ddouble__edouble edouble, kk_context_t* _ctx) { /* (edouble : edouble) -> double */ 
  double _x = edouble.err;
  return _x;
}

static inline kk_std_num_ddouble__edouble kk_std_num_ddouble__copy_1(kk_std_num_ddouble__edouble _this, kk_std_core_types__optional num0, kk_std_core_types__optional err0, kk_context_t* _ctx) { /* (edouble, num : optional<double>, err : optional<double>) -> edouble */ 
  double _x22020;
  if (kk_std_core_types__is_Optional(num0)) {
    kk_box_t _box_x21209 = num0._cons.Optional.value;
    double _num_211 = kk_double_unbox(_box_x21209, NULL);
    _x22020 = _num_211; /*double*/
    goto _match22021;
  }
  double _x = _this.num;
  _x22020 = _x; /*double*/
  _match22021: ;
  double _x22023;
  if (kk_std_core_types__is_Optional(err0)) {
    kk_box_t _box_x21210 = err0._cons.Optional.value;
    double _err_217 = kk_double_unbox(_box_x21210, NULL);
    _x22023 = _err_217; /*double*/
    goto _match22024;
  }
  double _x0 = _this.err;
  _x22023 = _x0; /*double*/
  _match22024: ;
  return kk_std_num_ddouble__new_Edouble(_x22020, _x22023, _ctx);
}

extern kk_integer_t kk_std_num_ddouble_maxprecise;
 
// Convert a `:ddouble` to a `:double` (losing precision)

static inline double kk_std_num_ddouble_double(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> double */ 
  double _x = x.hi;
  return _x;
}

extern kk_integer_t kk_std_num_ddouble_dd_default_prec;
 
// maximal precision in decimal digits of a `:ddouble`.

extern kk_integer_t kk_std_num_ddouble_dd_max_prec;
 
// Decode a `:ddouble` `d` into two doubles `(hi,lo)` such that `d` equals  `hi`+`lo`,
// where `lo` &le; 0.5&middot;ulp(`hi`).

static inline kk_std_core_types__tuple2_ kk_std_num_ddouble_decode(kk_std_num_ddouble__ddouble d, kk_context_t* _ctx) { /* (d : ddouble) -> (double, double) */ 
  kk_box_t _x22026;
  double _x22027;
  double _x = d.hi;
  _x22027 = _x; /*double*/
  _x22026 = kk_double_box(_x22027, _ctx); /*6*/
  kk_box_t _x22028;
  double _x22029;
  double _x0 = d.lo;
  _x22029 = _x0; /*double*/
  _x22028 = kk_double_box(_x22029, _ctx); /*7*/
  return kk_std_core_types__new_dash__lp__comma__rp_(_x22026, _x22028, _ctx);
}

kk_std_core_types__order kk_std_num_ddouble_compare(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_context_t* _ctx); /* (x : ddouble, y : ddouble) -> order */ 

bool kk_std_num_ddouble__lp__excl__eq__rp_(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_context_t* _ctx); /* (x : ddouble, y : ddouble) -> bool */ 

bool kk_std_num_ddouble__lp__lt__eq__rp_(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_context_t* _ctx); /* (x : ddouble, y : ddouble) -> bool */ 

bool kk_std_num_ddouble__lp__gt__eq__rp_(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_context_t* _ctx); /* (x : ddouble, y : ddouble) -> bool */ 
 
// Is this `:ddouble` equal to is-zero

static inline bool kk_std_num_ddouble_is_zero(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> bool */ 
  double _x22050;
  double _x = x.hi;
  _x22050 = _x; /*double*/
  return (_x22050 == (0x0p+0));
}
 
// Is this a finite `:ddouble`? (i.e. not `is-nan` or `is-inf`)

static inline bool kk_std_num_ddouble_is_finite(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> bool */ 
  bool _match_22005;
  double _x22051;
  double _x = x.hi;
  _x22051 = _x; /*double*/
  _match_22005 = isfinite(_x22051); /*bool*/
  if (_match_22005) {
    double _x22052;
    double _x0 = x.lo;
    _x22052 = _x0; /*double*/
    return isfinite(_x22052);
  }
  return false;
}
 
// Is this `:ddouble` negative?

static inline bool kk_std_num_ddouble_is_neg(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> bool */ 
  double _x22053;
  double _x = x.hi;
  _x22053 = _x; /*double*/
  return (_x22053 < (0x0p+0));
}

bool kk_std_num_ddouble__lp__eq__eq__rp_(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_context_t* _ctx); /* (x : ddouble, y : ddouble) -> bool */ 
 
// Create a `:ddouble` from a `:double`.

static inline kk_std_num_ddouble__ddouble kk_std_num_ddouble_ddouble(double d, kk_context_t* _ctx) { /* (d : double) -> ddouble */ 
  return kk_std_num_ddouble__new_Ddouble(d, 0x0p+0, _ctx);
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble_dquicksum(double x, double y, kk_context_t* _ctx); /* (x : double, y : double) -> ddouble */ 
 
// often called `twoproduct` in literature (see [@shewchuk])

static inline kk_std_num_ddouble__edouble kk_std_num_ddouble_prod(double x, double y, kk_context_t* _ctx) { /* (x : double, y : double) -> edouble */ 
  double z = (x * y); /*double*/;
  double err0;
  double _x22061 = (-z); /*double*/
  err0 = kk_std_num_double_fmadd(x, y, _x22061, _ctx); /*double*/
  return kk_std_num_ddouble__new_Edouble(z, err0, _ctx);
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble__lp__star__rp_(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_context_t* _ctx); /* (x : ddouble, y : ddouble) -> ddouble */ 

kk_std_num_ddouble__edouble kk_std_num_ddouble_quicksum(double x, double y, kk_context_t* _ctx); /* (x : double, y : double) -> edouble */ 

kk_std_num_ddouble__edouble kk_std_num_ddouble_sum(double x, double y, kk_context_t* _ctx); /* (x : double, y : double) -> edouble */ 

kk_std_num_ddouble__ddouble kk_std_num_ddouble__lp__plus__rp_(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_context_t* _ctx); /* (x : ddouble, y : ddouble) -> ddouble */ 
 
// Negate a `:ddouble`.

static inline kk_std_num_ddouble__ddouble kk_std_num_ddouble__lp__tilde__rp_(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> ddouble */ 
  double _x22121;
  double _x22122;
  double _x = x.hi;
  _x22122 = _x; /*double*/
  _x22121 = (-_x22122); /*double*/
  double _x22123;
  double _x22124;
  double _x0 = x.lo;
  _x22124 = _x0; /*double*/
  _x22123 = (-_x22124); /*double*/
  return kk_std_num_ddouble__new_Ddouble(_x22121, _x22123, _ctx);
}
 
// Subtract two values.

static inline kk_std_num_ddouble__ddouble kk_std_num_ddouble__lp__dash__rp_(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_context_t* _ctx) { /* (x : ddouble, y : ddouble) -> ddouble */ 
  kk_std_num_ddouble__ddouble _x22125 = kk_std_num_ddouble__lp__tilde__rp_(y, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__lp__plus__rp_(x, _x22125, _ctx);
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble__lp__fs__rp_(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_context_t* _ctx); /* (x : ddouble, y : ddouble) -> ddouble */ 
 
// Return the absolute value.

static inline kk_std_num_ddouble__ddouble kk_std_num_ddouble_abs(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> ddouble */ 
  bool _match_21988 = kk_std_num_ddouble_is_neg(x, _ctx); /*bool*/;
  if (_match_21988) {
    return kk_std_num_ddouble__lp__tilde__rp_(x, _ctx);
  }
  return x;
}

extern kk_std_num_ddouble__ddouble kk_std_num_ddouble_dd_nan;

extern kk_integer_t kk_std_num_ddouble_minprecise;

bool kk_std_num_ddouble_is_precise(kk_integer_t i, kk_context_t* _ctx); /* (i : int) -> bool */ 

static inline kk_std_num_ddouble__edouble kk_std_num_ddouble_prodsqr(double x, kk_context_t* _ctx) { /* (x : double) -> edouble */ 
  double z = (x * x); /*double*/;
  double err0;
  double _x22149 = (-z); /*double*/
  err0 = kk_std_num_double_fmadd(x, x, _x22149, _ctx); /*double*/
  return kk_std_num_ddouble__new_Edouble(z, err0, _ctx);
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble_sqr(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx); /* (x : ddouble) -> ddouble */ 

kk_std_num_ddouble__ddouble kk_std_num_ddouble_npwr_acc(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble acc, kk_integer_t n, kk_context_t* _ctx); /* (x : ddouble, acc : ddouble, n : int) -> ddouble */ 
 
// One

extern kk_std_num_ddouble__ddouble kk_std_num_ddouble_one;

kk_std_num_ddouble__ddouble kk_std_num_ddouble_npwr(kk_std_num_ddouble__ddouble x, kk_integer_t n, kk_context_t* _ctx); /* (x : ddouble, n : int) -> ddouble */ 

kk_std_num_ddouble__ddouble kk_std_num_ddouble_powi(kk_std_num_ddouble__ddouble x, kk_integer_t n, kk_context_t* _ctx); /* (x : ddouble, n : int) -> ddouble */ 
 
// Ten (`10.ddouble`)

extern kk_std_num_ddouble__ddouble kk_std_num_ddouble_ten;
 
// Return 10 to the power of `exp`.

static inline kk_std_num_ddouble__ddouble kk_std_num_ddouble_powi10(kk_integer_t exp0, kk_context_t* _ctx) { /* (exp : int) -> ddouble */ 
  kk_std_num_ddouble__ddouble _x22185 = kk_std_num_ddouble__new_Ddouble(0x1.4p3, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble_powi(_x22185, exp0, _ctx);
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble_mul_exp10(kk_std_num_ddouble__ddouble x, kk_integer_t exp0, kk_context_t* _ctx); /* (x : ddouble, exp : int) -> ddouble */ 

kk_std_num_ddouble__ddouble kk_std_num_ddouble_small_exp(kk_integer_t i, kk_integer_t e, kk_context_t* _ctx); /* (i : int, e : int) -> ddouble */ 

kk_std_num_ddouble__ddouble kk_std_num_ddouble_ddouble_int_exp(kk_integer_t i, kk_integer_t e, kk_context_t* _ctx); /* (i : int, e : int) -> ddouble */ 
 
// Create a `:ddouble` from an `:int`.
// A `:ddouble` can represent integers precisely up to 30 digits.
// If an integer is passed that is out of range an infinity is returned.

static inline kk_std_num_ddouble__ddouble kk_std_num_ddouble_ddouble_1(kk_integer_t i, kk_context_t* _ctx) { /* (i : int) -> ddouble */ 
  return kk_std_num_ddouble_ddouble_int_exp(i, kk_integer_from_small(0), _ctx);
}

kk_integer_t kk_std_num_ddouble__mlift20569_pddouble_normal(kk_char_t wild__0, kk_context_t* _ctx); /* (wild_0 : char) -> std/text/parse/parse int */ 

kk_std_num_ddouble__ddouble kk_std_num_ddouble__mlift20570_pddouble_normal(kk_string_t frac, bool neg, kk_string_t whole, kk_integer_t exp0, kk_context_t* _ctx); /* (frac : string, neg : bool, whole : string, exp : int) -> std/text/parse/parse ddouble */ 

kk_string_t kk_std_num_ddouble__mlift20571_pddouble_normal(kk_char_t wild__, kk_context_t* _ctx); /* (wild_ : char) -> std/text/parse/parse string */ 

kk_std_num_ddouble__ddouble kk_std_num_ddouble__mlift20572_pddouble_normal(bool neg, kk_string_t whole, kk_string_t _y_4, kk_context_t* _ctx); /* (neg : bool, whole : string, string) -> std/text/parse/parse ddouble */ 

kk_std_num_ddouble__ddouble kk_std_num_ddouble__mlift20573_pddouble_normal(bool neg, kk_string_t whole, kk_context_t* _ctx); /* (neg : bool, whole : string) -> std/text/parse/parse ddouble */ 

kk_std_num_ddouble__ddouble kk_std_num_ddouble__mlift20574_pddouble_normal(bool neg, kk_context_t* _ctx); /* (neg : bool) -> std/text/parse/parse ddouble */ 

kk_std_num_ddouble__ddouble kk_std_num_ddouble_pddouble_normal(kk_context_t* _ctx); /* () -> std/text/parse/parse ddouble */ 

kk_std_num_ddouble__ddouble kk_std_num_ddouble__mlift20575_pddouble_sum(double hi0, double lo0, kk_context_t* _ctx); /* (hi : double, lo : double) -> std/text/parse/parse ddouble */ 

kk_std_num_ddouble__ddouble kk_std_num_ddouble__mlift20576_pddouble_sum(double hi0, kk_string_t wild__0, kk_context_t* _ctx); /* (hi : double, wild_0 : string) -> std/text/parse/parse ddouble */ 

kk_std_num_ddouble__ddouble kk_std_num_ddouble__mlift20577_pddouble_sum(double hi0, kk_context_t* _ctx); /* (hi : double) -> std/text/parse/parse ddouble */ 

kk_std_num_ddouble__ddouble kk_std_num_ddouble_pddouble_sum(kk_context_t* _ctx); /* () -> std/text/parse/parse ddouble */ 

kk_std_num_ddouble__ddouble kk_std_num_ddouble_pddouble(kk_context_t* _ctx); /* () -> std/text/parse/parse ddouble */ 

kk_std_core_types__maybe kk_std_num_ddouble_parse_ddouble(kk_string_t s, kk_context_t* _ctx); /* (s : string) -> maybe<ddouble> */ 
 
// Parse a floating point number with up to 31 digits precision.
// Return `dd-nan` if the string is an invalid number.

static inline kk_std_num_ddouble__ddouble kk_std_num_ddouble_ddouble_2(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> ddouble */ 
  kk_std_core_types__maybe m_20742 = kk_std_num_ddouble_parse_ddouble(s, _ctx); /*maybe<std/num/ddouble/ddouble>*/;
  if (kk_std_core_types__is_Nothing(m_20742)) {
    return kk_std_num_ddouble_dd_nan;
  }
  kk_box_t _box_x21393 = m_20742._cons.Just.value;
  kk_std_num_ddouble__ddouble x = kk_std_num_ddouble__ddouble_unbox(_box_x21393, NULL);
  return x;
}
 
// Decrement by one.

static inline kk_std_num_ddouble__ddouble kk_std_num_ddouble_dec(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> ddouble */ 
  kk_std_num_ddouble__ddouble _x22418 = kk_std_num_ddouble__new_Ddouble(0x1p0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__lp__dash__rp_(x, _x22418, _ctx);
}
 
// Zero constant

extern kk_std_num_ddouble__ddouble kk_std_num_ddouble_zero;

kk_std_num_ddouble__ddouble kk_std_num_ddouble_sum_1(kk_std_core__list xs, kk_context_t* _ctx); /* (xs : list<ddouble>) -> ddouble */ 
 
// Is this `:ddouble` positive?

static inline bool kk_std_num_ddouble_is_pos(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> bool */ 
  double _x22455;
  double _x = x.hi;
  _x22455 = _x; /*double*/
  return (_x22455 > (0x0p+0));
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble_round(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx); /* (x : ddouble) -> ddouble */ 
 
// Remainder of two `:ddouble`s

static inline kk_std_num_ddouble__ddouble kk_std_num_ddouble__lp__perc__rp_(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_context_t* _ctx) { /* (x : ddouble, y : ddouble) -> ddouble */ 
  kk_std_num_ddouble__ddouble n;
  kk_std_num_ddouble__ddouble _x22464 = kk_std_num_ddouble__lp__fs__rp_(x, y, _ctx); /*std/num/ddouble/ddouble*/
  n = kk_std_num_ddouble_round(_x22464, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble y0_20772 = kk_std_num_ddouble__lp__star__rp_(n, y, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__ddouble _x22465 = kk_std_num_ddouble__lp__tilde__rp_(y0_20772, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__lp__plus__rp_(x, _x22465, _ctx);
}

bool kk_std_num_ddouble__lp__lt__rp_(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_context_t* _ctx); /* (x : ddouble, y : ddouble) -> bool */ 

bool kk_std_num_ddouble__lp__gt__rp_(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_context_t* _ctx); /* (x : ddouble, y : ddouble) -> bool */ 
 
// The maximum of `x` and `y`

static inline kk_std_num_ddouble__ddouble kk_std_num_ddouble_max(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_context_t* _ctx) { /* (x : ddouble, y : ddouble) -> ddouble */ 
  bool _match_21928 = kk_std_num_ddouble__lp__gt__eq__rp_(x, y, _ctx); /*bool*/;
  if (_match_21928) {
    return x;
  }
  return y;
}
 
// The maximum of the absolute values.

static inline kk_std_num_ddouble__ddouble kk_std_num_ddouble_abs_max(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_context_t* _ctx) { /* (x : ddouble, y : ddouble) -> ddouble */ 
  kk_std_num_ddouble__ddouble x0_20777 = kk_std_num_ddouble_abs(x, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__ddouble y0_20778 = kk_std_num_ddouble_abs(y, _ctx); /*std/num/ddouble/ddouble*/;
  bool _match_21927 = kk_std_num_ddouble__lp__gt__eq__rp_(x0_20777, y0_20778, _ctx); /*bool*/;
  if (_match_21927) {
    return x0_20777;
  }
  return y0_20778;
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble_abs_max_1(kk_std_core__list xs, kk_context_t* _ctx); /* (xs : list<ddouble>) -> ddouble */ 
 
// &pi;

extern kk_std_num_ddouble__ddouble kk_std_num_ddouble_dd_pi;
 
// &pi;/2

extern kk_std_num_ddouble__ddouble kk_std_num_ddouble_dd_pi2;
 
// 3&pi;/4

extern kk_std_num_ddouble__ddouble kk_std_num_ddouble_dd_pi34;
 
// &pi;/4

extern kk_std_num_ddouble__ddouble kk_std_num_ddouble_dd_pi4;

extern kk_std_core__list kk_std_num_ddouble_ch_factors;
 
// 2&pi;

extern kk_std_num_ddouble__ddouble kk_std_num_ddouble_dd_twopi;

kk_std_num_decimal__decimal kk_std_num_ddouble_decimal(kk_std_num_ddouble__ddouble x, kk_std_core_types__optional prec, kk_context_t* _ctx); /* (x : ddouble, prec : optional<int>) -> std/num/decimal/decimal */ 

kk_integer_t kk_std_num_ddouble_int(kk_std_num_ddouble__ddouble x, kk_std_core_types__optional nonfin, kk_context_t* _ctx); /* (x : ddouble, nonfin : optional<int>) -> int */ 

extern kk_vector_t kk_std_num_ddouble_sin16_table;
 
// Return sin(i*pi/16) for 0 <= i <= 8

static inline kk_std_num_ddouble__ddouble kk_std_num_ddouble_sin16(kk_integer_t i, kk_context_t* _ctx) { /* (i : int) -> ddouble */ 
  kk_std_core_types__maybe m_20797;
  kk_vector_t _x22525 = kk_vector_dup(kk_std_num_ddouble_sin16_table); /*vector<std/num/ddouble/ddouble>*/
  m_20797 = kk_std_core_at(_x22525, i, _ctx); /*maybe<std/num/ddouble/ddouble>*/
  if (kk_std_core_types__is_Nothing(m_20797)) {
    return kk_std_num_ddouble_dd_nan;
  }
  kk_box_t _box_x21521 = m_20797._cons.Just.value;
  kk_std_num_ddouble__ddouble x = kk_std_num_ddouble__ddouble_unbox(_box_x21521, NULL);
  return x;
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble_dsum(double x, double y, kk_context_t* _ctx); /* (x : double, y : double) -> ddouble */ 

kk_std_num_ddouble__ddouble kk_std_num_ddouble_sqrt(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx); /* (x : ddouble) -> ddouble */ 

kk_std_core_types__tuple2_ kk_std_num_ddouble_sincos(kk_std_num_ddouble__ddouble rad, kk_context_t* _ctx); /* (rad : ddouble) -> (ddouble, ddouble) */ 

kk_std_num_ddouble__ddouble kk_std_num_ddouble_with_sign_of(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_context_t* _ctx); /* (x : ddouble, y : ddouble) -> ddouble */ 

kk_std_num_ddouble__ddouble kk_std_num_ddouble_atan2(kk_std_num_ddouble__ddouble y, kk_std_num_ddouble__ddouble x, kk_context_t* _ctx); /* (y : ddouble, x : ddouble) -> ddouble */ 

kk_std_num_ddouble__ddouble kk_std_num_ddouble_acos(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx); /* (x : ddouble) -> ddouble */ 
 
// The _e_ constant.

extern kk_std_num_ddouble__ddouble kk_std_num_ddouble_dd_e;

extern kk_std_num_ddouble__ddouble kk_std_num_ddouble_dd_neginf;
 
// The 'machine epsilon': this is not well-defined for a `:ddouble` in general since
// the difference between 1.0 and the next representable `:ddouble` value is `dd-true-min`.
// Instead, we take the square of `dbl-epsilon`, i.e. 2^-104^.

extern kk_std_num_ddouble__ddouble kk_std_num_ddouble_dd_epsilon;
 
// The natural logarithm of 2

extern kk_std_num_ddouble__ddouble kk_std_num_ddouble_dd_log2;

extern kk_std_num_ddouble__ddouble kk_std_num_ddouble_dd_posinf;

kk_std_num_ddouble__ddouble kk_std_num_ddouble_exp_approx(kk_std_num_ddouble__ddouble p, kk_std_num_ddouble__ddouble t, kk_std_num_ddouble__ddouble r, double eps, kk_std_core__list fs, kk_std_core_types__optional s, kk_context_t* _ctx); /* (p : ddouble, t : ddouble, r : ddouble, eps : double, fs : list<ddouble>, s : optional<ddouble>) -> ddouble */ 

extern kk_std_core__list kk_std_num_ddouble_exp_factors;

kk_std_num_ddouble__ddouble kk_std_num_ddouble_floor(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx); /* (x : ddouble) -> ddouble */ 
 
// Multiply `x` by a `:double` `p` where `p` must be a power of 2.

static inline kk_std_num_ddouble__ddouble kk_std_num_ddouble_mul_pwr2(kk_std_num_ddouble__ddouble x, double p, kk_context_t* _ctx) { /* (x : ddouble, p : double) -> ddouble */ 
  double _x22898;
  double _x22899;
  double _x = x.hi;
  _x22899 = _x; /*double*/
  _x22898 = (_x22899 * p); /*double*/
  double _x22900;
  double _x22901;
  double _x0 = x.lo;
  _x22901 = _x0; /*double*/
  _x22900 = (_x22901 * p); /*double*/
  return kk_std_num_ddouble__new_Ddouble(_x22898, _x22900, _ctx);
}

static inline kk_std_num_ddouble__ddouble kk_std_num_ddouble_half(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> ddouble */ 
  double _x22902;
  double _x22903;
  double _x = x.hi;
  _x22903 = _x; /*double*/
  _x22902 = (_x22903 * (0x1p-1)); /*double*/
  double _x22904;
  double _x22905;
  double _x0 = x.lo;
  _x22905 = _x0; /*double*/
  _x22904 = (_x22905 * (0x1p-1)); /*double*/
  return kk_std_num_ddouble__new_Ddouble(_x22902, _x22904, _ctx);
}
 
// 'Load exponent': returns `x`&middot;2^`exp`^.

static inline kk_std_num_ddouble__ddouble kk_std_num_ddouble_ldexp(kk_std_num_ddouble__ddouble x, kk_integer_t exp0, kk_context_t* _ctx) { /* (x : ddouble, exp : int) -> ddouble */ 
  double _x22906;
  double _x22907;
  double _x = x.hi;
  _x22907 = _x; /*double*/
  kk_integer_t _x22908 = kk_integer_dup(exp0); /*int*/
  _x22906 = kk_std_num_double_ldexp(_x22907, _x22908, _ctx); /*double*/
  double _x22909;
  double _x22910;
  double _x0 = x.lo;
  _x22910 = _x0; /*double*/
  _x22909 = kk_std_num_double_ldexp(_x22910, exp0, _ctx); /*double*/
  return kk_std_num_ddouble__new_Ddouble(_x22906, _x22909, _ctx);
}

static inline kk_std_num_ddouble__ddouble kk_std_num_ddouble_twice(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> ddouble */ 
  double _x22911;
  double _x22912;
  double _x = x.hi;
  _x22912 = _x; /*double*/
  _x22911 = (_x22912 * 0x1p1); /*double*/
  double _x22913;
  double _x22914;
  double _x0 = x.lo;
  _x22914 = _x0; /*double*/
  _x22913 = (_x22914 * 0x1p1); /*double*/
  return kk_std_num_ddouble__new_Ddouble(_x22911, _x22913, _ctx);
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble_exp(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx); /* (x : ddouble) -> ddouble */ 
 
// Does `x` equal positive infinity?

static inline bool kk_std_num_ddouble_is_posinf(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> bool */ 
  double _x22999;
  double _x = x.hi;
  _x22999 = _x; /*double*/
  return (isinf(_x22999) && !signbit(_x22999));
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble_log(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx); /* (x : ddouble) -> ddouble */ 

kk_std_num_ddouble__ddouble kk_std_num_ddouble_acosh(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx); /* (x : ddouble) -> ddouble */ 

kk_std_num_ddouble__ddouble kk_std_num_ddouble_asin(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx); /* (x : ddouble) -> ddouble */ 

kk_std_num_ddouble__ddouble kk_std_num_ddouble_asinh(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx); /* (x : ddouble) -> ddouble */ 
 
// The arc-tangent of `x`. Returns the angle in radians.

static inline kk_std_num_ddouble__ddouble kk_std_num_ddouble_atan(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> ddouble */ 
  kk_std_num_ddouble__ddouble _x23131 = kk_std_num_ddouble__new_Ddouble(0x1p0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble_atan2(x, _x23131, _ctx);
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble_atanh(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx); /* (x : ddouble) -> ddouble */ 

kk_std_num_ddouble__ddouble kk_std_num_ddouble_ceiling(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx); /* (x : ddouble) -> ddouble */ 
 
// The cosine function of a given angle in radians.

static inline kk_std_num_ddouble__ddouble kk_std_num_ddouble_cos(kk_std_num_ddouble__ddouble rad, kk_context_t* _ctx) { /* (rad : ddouble) -> ddouble */ 
  kk_std_core_types__tuple2_ _this_20964 = kk_std_num_ddouble_sincos(rad, _ctx); /*(std/num/ddouble/ddouble, std/num/ddouble/ddouble)*/;
  kk_box_t _box_x21608 = _this_20964.fst;
  kk_box_t _box_x21609 = _this_20964.snd;
  kk_std_num_ddouble__ddouble _x = kk_std_num_ddouble__ddouble_unbox(_box_x21609, NULL);
  kk_std_core_types__tuple2__drop(_this_20964, _ctx);
  return _x;
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble_sinh(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx); /* (x : ddouble) -> ddouble */ 

kk_std_num_ddouble__ddouble kk_std_num_ddouble_cosh(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx); /* (x : ddouble) -> ddouble */ 
 
// 8*dd-epsilon

extern kk_std_num_ddouble__ddouble kk_std_num_ddouble_dd_epsilon8;
 
// [Euler's constant](https://en.wikipedia.org/wiki/Euler%E2%80%93Mascheroni_constant)

extern kk_std_num_ddouble__ddouble kk_std_num_ddouble_dd_euler;
 
// The natural logarithm of 10

extern kk_std_num_ddouble__ddouble kk_std_num_ddouble_dd_log10;
 
// The base-10 logarithm of _e_.

extern kk_std_num_ddouble__ddouble kk_std_num_ddouble_dd_log10e;
 
// The base-2 logarithm of _e_.

extern kk_std_num_ddouble__ddouble kk_std_num_ddouble_dd_log2e;
 
// The maximum representable `:ddouble`

extern kk_std_num_ddouble__ddouble kk_std_num_ddouble_dd_max;
 
// The smallest positive `:ddouble` that is still normalized

extern kk_std_num_ddouble__ddouble kk_std_num_ddouble_dd_min;
 
// &pi;/16

extern kk_std_num_ddouble__ddouble kk_std_num_ddouble_dd_pi16;
 
// `1.0 / sqrt(2.0)`

extern kk_std_num_ddouble__ddouble kk_std_num_ddouble_dd_sqrt12;
 
// The square-root of 2

extern kk_std_num_ddouble__ddouble kk_std_num_ddouble_dd_sqrt2;
 
// The smallest positive `:ddouble`  (which is subnormal).

extern kk_std_num_ddouble__ddouble kk_std_num_ddouble_dd_true_min;

kk_std_num_ddouble__ddouble kk_std_num_ddouble_ddouble_exp(double d, kk_integer_t e, kk_context_t* _ctx); /* (d : double, e : int) -> ddouble */ 

kk_std_num_ddouble__ddouble kk_std_num_ddouble_ddouble_exp_1(kk_integer_t i, kk_integer_t exp0, kk_context_t* _ctx); /* (i : int, exp : int) -> ddouble */ 

kk_std_core_types__tuple2_ kk_std_num_ddouble_divrem(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_context_t* _ctx); /* (x : ddouble, y : ddouble) -> (ddouble, ddouble) */ 
 
// Encode a `:ddouble` `d` from two doubles `(hi,lo)` such that `d` equals  `hi`+`lo`.

static inline kk_std_num_ddouble__ddouble kk_std_num_ddouble_encode(double hi0, double lo0, kk_context_t* _ctx) { /* (hi : double, lo : double) -> ddouble */ 
  kk_std_num_ddouble__ddouble _x23312 = kk_std_num_ddouble_ddouble(hi0, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x23313 = kk_std_num_ddouble_ddouble(lo0, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__lp__plus__rp_(_x23312, _x23313, _ctx);
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble_pow(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_context_t* _ctx); /* (x : ddouble, y : ddouble) -> ddouble */ 
 
// Return 10 to the power of `exp`.

static inline kk_std_num_ddouble__ddouble kk_std_num_ddouble_exp10(kk_std_num_ddouble__ddouble exp0, kk_context_t* _ctx) { /* (exp : ddouble) -> ddouble */ 
  kk_std_num_ddouble__ddouble _x23335 = kk_std_num_ddouble__new_Ddouble(0x1.4p3, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble_pow(_x23335, exp0, _ctx);
}

extern kk_std_num_ddouble__ddouble kk_std_num_ddouble_two;
 
// Return 2 to the power of `exp`.

static inline kk_std_num_ddouble__ddouble kk_std_num_ddouble_exp2(kk_std_num_ddouble__ddouble exp0, kk_context_t* _ctx) { /* (exp : ddouble) -> ddouble */ 
  kk_std_num_ddouble__ddouble _x23336 = kk_std_num_ddouble__new_Ddouble(0x1p1, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble_pow(_x23336, exp0, _ctx);
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble_expm1(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx); /* (x : ddouble) -> ddouble */ 

kk_std_num_ddouble__ddouble kk_std_num_ddouble_exp2m1(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx); /* (x : ddouble) -> ddouble */ 
 
// The _floored_ fraction of `x`. This is always positive, such that `x.floor + x.ffraction == x`.

static inline kk_std_num_ddouble__ddouble kk_std_num_ddouble_ffraction(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> ddouble */ 
  kk_std_num_ddouble__ddouble y_21007 = kk_std_num_ddouble_floor(x, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__ddouble _x23415 = kk_std_num_ddouble__lp__tilde__rp_(y_21007, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__lp__plus__rp_(x, _x23415, _ctx);
}
 
// Round towards zero.

static inline kk_std_num_ddouble__ddouble kk_std_num_ddouble_truncate(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> ddouble */ 
  bool _match_21785 = kk_std_num_ddouble_is_neg(x, _ctx); /*bool*/;
  if (_match_21785) {
    return kk_std_num_ddouble_ceiling(x, _ctx);
  }
  return kk_std_num_ddouble_floor(x, _ctx);
}
 
// The fraction of `x` such that `x.truncate + x.fraction == x`.

static inline kk_std_num_ddouble__ddouble kk_std_num_ddouble_fraction(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> ddouble */ 
  kk_std_num_ddouble__ddouble y_21009 = kk_std_num_ddouble_truncate(x, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__ddouble _x23416 = kk_std_num_ddouble__lp__tilde__rp_(y_21009, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__lp__plus__rp_(x, _x23416, _ctx);
}
 
// The minimum of `x` and `y`.

static inline kk_std_num_ddouble__ddouble kk_std_num_ddouble_min(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_context_t* _ctx) { /* (x : ddouble, y : ddouble) -> ddouble */ 
  bool _match_21784 = kk_std_num_ddouble__lp__lt__eq__rp_(x, y, _ctx); /*bool*/;
  if (_match_21784) {
    return x;
  }
  return y;
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble_hypot(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_context_t* _ctx); /* (x : ddouble, y : ddouble) -> ddouble */ 

kk_std_num_ddouble__ddouble kk_std_num_ddouble_hypot_1(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_std_num_ddouble__ddouble z, kk_context_t* _ctx); /* (x : ddouble, y : ddouble, z : ddouble) -> ddouble */ 

kk_std_num_ddouble__ddouble kk_std_num_ddouble_hypot_2(kk_std_core__list xs, kk_context_t* _ctx); /* (xs : list<ddouble>) -> ddouble */ 
 
// Increment by one.

static inline kk_std_num_ddouble__ddouble kk_std_num_ddouble_inc(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> ddouble */ 
  kk_std_num_ddouble__ddouble _x23653 = kk_std_num_ddouble__new_Ddouble(0x1p0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__lp__plus__rp_(x, _x23653, _ctx);
}
 
// Is this an infinite value.

static inline bool kk_std_num_ddouble_is_inf(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> bool */ 
  double _x23654;
  double _x = x.hi;
  _x23654 = _x; /*double*/
  return kk_std_num_double_is_inf(_x23654, _ctx);
}
 
// Is this `:ddouble` not-a-number?

static inline bool kk_std_num_ddouble_is_nan(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> bool */ 
  bool _match_21753;
  double _x23655;
  double _x = x.hi;
  _x23655 = _x; /*double*/
  _match_21753 = isnan(_x23655); /*bool*/
  if (_match_21753) {
    return true;
  }
  double _x23656;
  double _x0 = x.lo;
  _x23656 = _x0; /*double*/
  return isnan(_x23656);
}
 
// Does `x` equal negative infinity?

static inline bool kk_std_num_ddouble_is_neginf(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> bool */ 
  double _x23657;
  double _x = x.hi;
  _x23657 = _x; /*double*/
  return (isinf(_x23657) && signbit(_x23657));
}
 
// Return the sign of the `:ddouble`.

static inline kk_std_core_types__order kk_std_num_ddouble_is_sign(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> order */ 
  bool _match_21751;
  double _x23658;
  double _x = x.hi;
  _x23658 = _x; /*double*/
  _match_21751 = (_x23658 == (0x0p+0)); /*bool*/
  if (_match_21751) {
    return kk_std_core_types__new_Eq(_ctx);
  }
  bool _match_21752;
  double _x23659;
  double _x0 = x.hi;
  _x23659 = _x0; /*double*/
  _match_21752 = (_x23659 < (0x0p+0)); /*bool*/
  if (_match_21752) {
    return kk_std_core_types__new_Lt(_ctx);
  }
  return kk_std_core_types__new_Gt(_ctx);
}
 
// The logarithm in base 10 of `x`.

static inline kk_std_num_ddouble__ddouble kk_std_num_ddouble_log10(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> ddouble */ 
  kk_std_num_ddouble__ddouble _x23660 = kk_std_num_ddouble_log(x, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x23661 = kk_std_num_ddouble__new_Ddouble(0x1.26bb1bbb55516p1, -0x1.f48ad494ea3e9p-53, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__lp__fs__rp_(_x23660, _x23661, _ctx);
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble_log1p(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx); /* (x : ddouble) -> ddouble */ 
 
// The logarithm in base 2 of `x`.

static inline kk_std_num_ddouble__ddouble kk_std_num_ddouble_log2(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> ddouble */ 
  kk_std_num_ddouble__ddouble _x23684 = kk_std_num_ddouble_log(x, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x23685 = kk_std_num_ddouble__new_Ddouble(0x1.62e42fefa39efp-1, 0x1.abc9e3b39803fp-56, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__lp__fs__rp_(_x23684, _x23685, _ctx);
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble_log2p1(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx); /* (x : ddouble) -> ddouble */ 

kk_std_num_ddouble__ddouble kk_std_num_ddouble_logaddexp(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_context_t* _ctx); /* (x : ddouble, y : ddouble) -> ddouble */ 

kk_std_num_ddouble__ddouble kk_std_num_ddouble_logaddexp2(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_context_t* _ctx); /* (x : ddouble, y : ddouble) -> ddouble */ 

bool kk_std_num_ddouble_nearly_eq(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_std_core_types__optional epsilon, kk_context_t* _ctx); /* (x : ddouble, y : ddouble, epsilon : optional<ddouble>) -> bool */ 

kk_std_num_ddouble__ddouble kk_std_num_ddouble_nroot(kk_std_num_ddouble__ddouble x, kk_integer_t n, kk_context_t* _ctx); /* (x : ddouble, n : int) -> ddouble */ 

extern kk_std_num_ddouble__ddouble kk_std_num_ddouble_one_half;

kk_std_num_ddouble__ddouble kk_std_num_ddouble_round_to_prec(kk_std_num_ddouble__ddouble x, kk_integer_t prec, kk_context_t* _ctx); /* (x : ddouble, prec : int) -> ddouble */ 

kk_string_t kk_std_num_ddouble_show(kk_std_num_ddouble__ddouble x, kk_std_core_types__optional prec, kk_context_t* _ctx); /* (x : ddouble, prec : optional<int>) -> string */ 

kk_string_t kk_std_num_ddouble_show_exp(kk_std_num_ddouble__ddouble x, kk_std_core_types__optional prec, kk_context_t* _ctx); /* (x : ddouble, prec : optional<int>) -> string */ 

kk_string_t kk_std_num_ddouble_show_fixed(kk_std_num_ddouble__ddouble x, kk_std_core_types__optional prec, kk_context_t* _ctx); /* (x : ddouble, prec : optional<int>) -> string */ 

kk_string_t kk_std_num_ddouble_show_hex(kk_std_num_ddouble__ddouble x, kk_std_core_types__optional width, kk_std_core_types__optional use_capitals, kk_std_core_types__optional pre, kk_context_t* _ctx); /* (x : ddouble, width : optional<int>, use-capitals : optional<bool>, pre : optional<string>) -> string */ 

kk_string_t kk_std_num_ddouble_show_sum(kk_std_num_ddouble__ddouble x, kk_std_core_types__optional prec, kk_context_t* _ctx); /* (x : ddouble, prec : optional<int>) -> string */ 
 
// The sine function of a given angle in radians.

static inline kk_std_num_ddouble__ddouble kk_std_num_ddouble_sin(kk_std_num_ddouble__ddouble rad, kk_context_t* _ctx) { /* (rad : ddouble) -> ddouble */ 
  kk_std_core_types__tuple2_ _this_21084 = kk_std_num_ddouble_sincos(rad, _ctx); /*(std/num/ddouble/ddouble, std/num/ddouble/ddouble)*/;
  kk_box_t _box_x21673 = _this_21084.fst;
  kk_box_t _box_x21674 = _this_21084.snd;
  kk_std_num_ddouble__ddouble _x = kk_std_num_ddouble__ddouble_unbox(_box_x21673, NULL);
  kk_std_core_types__tuple2__drop(_this_21084, _ctx);
  return _x;
}
 
// The tangent of a given angle in radians.

static inline kk_std_num_ddouble__ddouble kk_std_num_ddouble_tan(kk_std_num_ddouble__ddouble rad, kk_context_t* _ctx) { /* (rad : ddouble) -> ddouble */ 
  kk_std_core_types__tuple2_ _match_21686 = kk_std_num_ddouble_sincos(rad, _ctx); /*(std/num/ddouble/ddouble, std/num/ddouble/ddouble)*/;
  kk_box_t _box_x21675 = _match_21686.fst;
  kk_box_t _box_x21676 = _match_21686.snd;
  kk_std_num_ddouble__ddouble s = kk_std_num_ddouble__ddouble_unbox(_box_x21675, NULL);
  kk_std_num_ddouble__ddouble c = kk_std_num_ddouble__ddouble_unbox(_box_x21676, NULL);
  return kk_std_num_ddouble__lp__fs__rp_(s, c, _ctx);
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble_tanh(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx); /* (x : ddouble) -> ddouble */ 
 
// Return if two `:ddouble`s are nearly equal with respect to an `epsilon` of `10*dd-epsilon`.
// See also `nearly-eq` which takes an explicit `epsilon`.

static inline bool kk_std_num_ddouble__lp__tilde__eq__rp_(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_context_t* _ctx) { /* (x : ddouble, y : ddouble) -> bool */ 
  return kk_std_num_ddouble_nearly_eq(x, y, kk_std_core_types__new_None(_ctx), _ctx);
}

void kk_std_num_ddouble__init(kk_context_t* _ctx);

#endif // header
