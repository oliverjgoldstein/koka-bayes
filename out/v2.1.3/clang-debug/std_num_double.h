#pragma once
#ifndef kk_std_num_double_H
#define kk_std_num_double_H
// Koka generated module: "std/num/double", koka version: 2.1.3
#include <kklib.h>
#include "std_core_types.h"
#include "std_core_hnd.h"
#include "std_core.h"
#include "std_text_parse.h"
#include "std_num_int32.h"

// type declarations

// value declarations
 
// The maximum of the absolute values.

static inline double kk_std_num_double_abs_max(double x, double y, kk_context_t* _ctx) { /* (x : double, y : double) -> double */ 
  double x0_5674 = kk_double_abs(x); /*double*/;
  double y0_5675 = kk_double_abs(y); /*double*/;
  bool _match_6353 = (x0_5674 >= y0_5675); /*bool*/;
  if (_match_6353) {
    return x0_5674;
  }
  return y0_5675;
}

double kk_std_num_double_abs_max_1(kk_std_core__list xs, kk_context_t* _ctx); /* (xs : list<double>) -> double */ 

double kk_std_num_double_acosh(double d, kk_context_t* _ctx); /* (d : double) -> double */ 

double kk_std_num_double_asinh(double d, kk_context_t* _ctx); /* (d : double) -> double */ 

double kk_std_num_double_atanh(double d, kk_context_t* _ctx); /* (d : double) -> double */ 
 
// The [_e_](https://en.wikipedia.org/wiki/E_(mathematical_constant)) constant.
#define kk_std_num_double_dbl_e ((double)(0x1.5bf0a8b145769p1))
 
// Machine epsilon: the difference between 1.0 and the next representable `:double` value.
#define kk_std_num_double_dbl_epsilon ((double)(0x1p-52))
 
// [Euler's constant](https://en.wikipedia.org/wiki/Euler%E2%80%93Mascheroni_constant)
#define kk_std_num_double_dbl_euler ((double)(0x1.2788cfc6fb619p-1))
 
// The natural logarithm of 10
#define kk_std_num_double_dbl_log10 ((double)(0x1.26bb1bbb55516p1))
 
// The base-10 logarithm of _e_.
#define kk_std_num_double_dbl_log10e ((double)(0x1.bcb7b1526e50ep-2))
 
// The natural logarithm of 2
#define kk_std_num_double_dbl_log2 ((double)(0x1.62e42fefa39efp-1))
 
// The base-2 logarithm of _e_.
#define kk_std_num_double_dbl_log2e ((double)(0x1.71547652b82fep0))
 
// Maximum double value
#define kk_std_num_double_dbl_max ((double)(0x1.fffffffffffffp1023))
 
// maximal precision in decimal digits of a `:double`.

extern kk_integer_t kk_std_num_double_dbl_max_prec;
 
// Smallest positive normalized double value
#define kk_std_num_double_dbl_min ((double)(0x1p-1022))
 
// &pi;
#define kk_std_num_double_pi ((double)(0x1.921fb54442d18p1))
 
// &pi;/2
#define kk_std_num_double_dbl_pi2 ((double)(0x1.921fb54442d18p0))
 
// 3&pi;/4
#define kk_std_num_double_dbl_pi34 ((double)(0x1.2d97c7f3321d2p1))
 
// &pi;/4
#define kk_std_num_double_dbl_pi4 ((double)(0x1.921fb54442d18p-1))
 
// `1.0 / sqrt(2.0)`  (= `sqrt(0.5)`)
#define kk_std_num_double_dbl_sqrt12 ((double)(0x1.6a09e667f3bcdp-1))
 
// The square-root of 2
#define kk_std_num_double_dbl_sqrt2 ((double)(0x1.6a09e667f3bcdp0))
 
// Smallest positive subnormal value (i.e. [``DBL_TRUE_MIN``](http://en.cppreference.com/w/cpp/types/climits))
#define kk_std_num_double_dbl_true_min ((double)(0x1p-1074))
 
// 2&pi;
#define kk_std_num_double_dbl_twopi ((double)(0x1.921fb54442d18p2))

kk_std_core_types__tuple2_ kk_std_num_double_double_to_bits(double d, kk_context_t* _ctx); /* (d : double) -> (int32, int32) */ 

double kk_std_num_double_double_from_bits(int32_t lo, int32_t hi, kk_context_t* _ctx); /* (lo : int32, hi : int32) -> double */ 

double kk_std_num_double_make_neginf(kk_context_t* _ctx); /* () -> double */ 
#define kk_std_num_double_one_m1022 ((double)(0x1p-1022))
#define kk_std_num_double_one_p1023 ((double)(0x1p1023))

double kk_std_num_double_make_posinf(kk_context_t* _ctx); /* () -> double */ 
 
// Return the 10 to the power of `p`.

static inline double kk_std_num_double_exp10(double p, kk_context_t* _ctx) { /* (p : double) -> double */ 
  return pow((0x1.4p3),p);
}
 
// Return the 'floored' fraction of `d`, always greater or equal to zero.
// `d.floor + d.ffraction === d`
// `(-2.4).ffraction === 0.6`

static inline double kk_std_num_double_ffraction(double d, kk_context_t* _ctx) { /* (d : double) -> double */ 
  double _x6360 = floor(d); /*double*/
  return (d - _x6360);
}

double kk_std_num_double_fmadd(double x, double y, double z, kk_context_t* _ctx); /* (x : double, y : double, z : double) -> double */ 
 
// Return the integral part of a `:double` `d` .
// If `d >= 0.0` , return the largest integer equal or less to `d` ,
// If `d < 0.0` , return the smallest integer equal or larger to `d` .

static inline double kk_std_num_double_truncate(double d, kk_context_t* _ctx) { /* (d : double) -> double */ 
  bool _match_6351 = (d >= (0x0p+0)); /*bool*/;
  if (_match_6351) {
    return floor(d);
  }
  return ceil(d);
}
 
// Is this a negative zero value?

static inline bool kk_std_num_double_is_negzero(double d, kk_context_t* _ctx) { /* (d : double) -> bool */ 
  bool _match_6350 = (d == (0x0p+0)); /*bool*/;
  if (_match_6350) {
    double _x6361 = (0x1p0 / d); /*double*/
    return (isinf(_x6361) && signbit(_x6361));
  }
  return false;
}
 
// The square of a double

static inline double kk_std_num_double_sqr(double x, kk_context_t* _ctx) { /* (x : double) -> double */ 
  return (x * x);
}

double kk_std_num_double_sum(kk_std_core__list xs, kk_context_t* _ctx); /* (xs : list<double>) -> double */ 

bool kk_std_num_double_is_inf(double _arg1, kk_context_t* _ctx); /* (double) -> bool */ 

double kk_std_num_double_make_nan(kk_context_t* _ctx); /* () -> double */ 

double kk_std_num_double_prim_parse_double(kk_string_t s, kk_context_t* _ctx); /* (s : string) -> double */ 
 
// Return `x` with the sign of `y`.

static inline double kk_std_num_double_with_sign_of(double x, double y, kk_context_t* _ctx) { /* (x : double, y : double) -> double */ 
  bool _match_6348 = (y < (0x0p+0)); /*bool*/;
  if (_match_6348) {
    double _x6397 = kk_double_abs(x); /*double*/
    return (-_x6397);
  }
  return kk_double_abs(x);
}
 
// &pi;
#define kk_std_num_double_dbl_pi ((double)(0x1.921fb54442d18p1))

kk_std_core_types__tuple2_ kk_std_num_double_decode_normalized(double d, kk_std_core_types__optional e_adjust, kk_context_t* _ctx); /* (d : double, e-adjust : optional<int>) -> (int, int) */ 
 
// Is this a [subnormal](https://en.wikipedia.org/wiki/Denormal_number) value?
// (i.e. `0 < d.abs < dbl-min`)

static inline bool kk_std_num_double_is_subnormal(double d, kk_context_t* _ctx) { /* (d : double) -> bool */ 
  bool _match_6345 = (d != (0x0p+0)); /*bool*/;
  if (_match_6345) {
    double _x6412 = kk_double_abs(d); /*double*/
    return (_x6412 < (0x1p-1022));
  }
  return false;
}

kk_std_core_types__tuple2_ kk_std_num_double_decode(double d, kk_context_t* _ctx); /* (d : double) -> (int, int) */ 

extern double kk_std_num_double_rad2deg;
 
// Convert radians to degrees.

static inline double kk_std_num_double_deg(double rad0, kk_context_t* _ctx) { /* (rad : double) -> double */ 
  double _x6416 = ((0x1.68p7) / (0x1.921fb54442d18p1)); /*double*/
  return (rad0 * _x6416);
}

extern double kk_std_num_double_deg2rad;
 
// Return the 2 to the power of `p`.

static inline double kk_std_num_double_exp2(double p, kk_context_t* _ctx) { /* (p : double) -> double */ 
  return pow(0x1p1,p);
}

double kk_std_num_double_exp2_1(kk_integer_t e, kk_context_t* _ctx); /* (e : int) -> double */ 
 
// = dbl-min

static inline double kk_std_num_double_mul_exp2(double x, kk_integer_t e, kk_context_t* _ctx) { /* (x : double, e : int) -> double */ 
  double _x6422 = kk_std_num_double_exp2_1(e, _ctx); /*double*/
  return (x * _x6422);
}
 
// Negative infinity

extern double kk_std_num_double_neginf;
 
// Positive infinity

extern double kk_std_num_double_posinf;

double kk_std_num_double_ldexp(double x, kk_integer_t e, kk_context_t* _ctx); /* (x : double, e : int) -> double */ 
 
// Create a double `d` given a mantissa `man` and exponent `exp`
// such that `man`&middot;2^`exp`^ =  `d` exactly (if it is representable
// by a `:double`). See also `ldexp`.

static inline double kk_std_num_double_encode(kk_integer_t man, kk_integer_t exp, kk_context_t* _ctx) { /* (man : int, exp : int) -> double */ 
  double _x6436 = kk_integer_as_double(man,kk_context()); /*double*/
  return kk_std_num_double_ldexp(_x6436, exp, _ctx);
}

static inline double kk_std_num_double_exp2m1(double x, kk_context_t* _ctx) { /* (x : double) -> double */ 
  double _x6437 = ((0x1.62e42fefa39efp-1) * x); /*double*/
  return log1p(_x6437);
}
 
// Return the fractional part of a `:double` `d`.
// `d.truncate + d.fraction === d`
// `(-2.4).fraction === -0.4`

static inline double kk_std_num_double_fraction(double d, kk_context_t* _ctx) { /* (d : double) -> double */ 
  double _x6438 = kk_std_num_double_truncate(d, _ctx); /*double*/
  return (d - _x6438);
}

kk_std_core_types__tuple2_ kk_std_num_double_frexp(double x, kk_context_t* _ctx); /* (x : double) -> (double, int) */ 

double kk_std_num_double_hypot(double x, double y, kk_context_t* _ctx); /* (x : double, y : double) -> double */ 

double kk_std_num_double_hypot_1(double x, double y, double z, kk_context_t* _ctx); /* (x : double, y : double, z : double) -> double */ 

double kk_std_num_double_hypot_2(kk_std_core__list xs, kk_context_t* _ctx); /* (xs : list<double>) -> double */ 
 
// Return the logarithm in base 10 of a `:double` `d`.

static inline double kk_std_num_double_log10(double d, kk_context_t* _ctx) { /* (d : double) -> double */ 
  double _x6459 = log(d); /*double*/
  return (_x6459 / (0x1.26bb1bbb55516p1));
}
 
// Return the logarithm in base 2 of a `:double` `d`.

static inline double kk_std_num_double_log2(double d, kk_context_t* _ctx) { /* (d : double) -> double */ 
  double _x6460 = log(d); /*double*/
  return (_x6460 / (0x1.62e42fefa39efp-1));
}

static inline double kk_std_num_double_log2p1(double x, kk_context_t* _ctx) { /* (x : double) -> double */ 
  double _x6461 = log1p(x); /*double*/
  return ((0x1.71547652b82fep0) * _x6461);
}

double kk_std_num_double_logaddexp(double x, double y, kk_context_t* _ctx); /* (x : double, y : double) -> double */ 

double kk_std_num_double_logaddexp2(double x, double y, kk_context_t* _ctx); /* (x : double, y : double) -> double */ 
 
// Represents a value that is _not a number_ (NaN)

extern double kk_std_num_double_nan;

bool kk_std_num_double_nearly_eq(double x, double y, kk_std_core_types__optional epsilon, kk_context_t* _ctx); /* (x : double, y : double, epsilon : optional<double>) -> bool */ 

kk_integer_t kk_std_num_double__mlift5656_pdecdouble(kk_char_t wild__0, kk_context_t* _ctx); /* (wild_0 : char) -> std/text/parse/parse int */ 

double kk_std_num_double__mlift5657_pdecdouble(kk_std_core__sslice cur, kk_integer_t exp, kk_context_t* _ctx); /* (cur : sslice, exp : int) -> std/text/parse/parse double */ 

kk_string_t kk_std_num_double__mlift5658_pdecdouble(kk_char_t wild__, kk_context_t* _ctx); /* (wild_ : char) -> std/text/parse/parse string */ 

double kk_std_num_double__mlift5659_pdecdouble(kk_std_core__sslice cur, kk_string_t _y_4, kk_context_t* _ctx); /* (cur : sslice, string) -> std/text/parse/parse double */ 

double kk_std_num_double__mlift5660_pdecdouble(kk_std_core__sslice cur, kk_string_t man, kk_context_t* _ctx); /* (cur : sslice, man : string) -> std/text/parse/parse double */ 

double kk_std_num_double__mlift5661_pdecdouble(kk_std_core__sslice cur, kk_context_t* _ctx); /* (cur : sslice) -> std/text/parse/parse double */ 

double kk_std_num_double_pdecdouble(kk_context_t* _ctx); /* () -> std/text/parse/parse double */ 

kk_integer_t kk_std_num_double__mlift5662_phexdouble(kk_char_t wild__2, kk_context_t* _ctx); /* (wild_2 : char) -> std/text/parse/parse int */ 

double kk_std_num_double__mlift5663_phexdouble(kk_string_t frac, kk_string_t man, kk_integer_t exp, kk_context_t* _ctx); /* (frac : string, man : string, exp : int) -> std/text/parse/parse double */ 

kk_string_t kk_std_num_double__mlift5664_phexdouble(kk_char_t wild__1, kk_context_t* _ctx); /* (wild_1 : char) -> std/text/parse/parse string */ 

double kk_std_num_double__mlift5665_phexdouble(kk_string_t man, kk_string_t _y_13, kk_context_t* _ctx); /* (man : string, string) -> std/text/parse/parse double */ 

double kk_std_num_double__mlift5666_phexdouble(kk_string_t man, kk_context_t* _ctx); /* (man : string) -> std/text/parse/parse double */ 

double kk_std_num_double__mlift5667_phexdouble(kk_char_t wild__0, kk_context_t* _ctx); /* (wild_0 : char) -> std/text/parse/parse double */ 

double kk_std_num_double__mlift5668_phexdouble(kk_char_t wild__, kk_context_t* _ctx); /* (wild_ : char) -> std/text/parse/parse double */ 

double kk_std_num_double_phexdouble(kk_context_t* _ctx); /* () -> std/text/parse/parse double */ 

double kk_std_num_double__mlift5669_pspecial(kk_string_t wild__, kk_context_t* _ctx); /* (wild_ : string) -> std/text/parse/parse double */ 

double kk_std_num_double__mlift5670_pspecial(kk_string_t wild__0, kk_context_t* _ctx); /* (wild_0 : string) -> std/text/parse/parse double */ 

double kk_std_num_double__mlift5671_pspecial(kk_string_t wild__1, kk_context_t* _ctx); /* (wild_1 : string) -> std/text/parse/parse double */ 

double kk_std_num_double_pspecial(kk_context_t* _ctx); /* () -> std/text/parse/parse double */ 

double kk_std_num_double__mlift5672_pdouble(bool neg, double d, kk_context_t* _ctx); /* (neg : bool, d : double) -> std/text/parse/parse double */ 

double kk_std_num_double__mlift5673_pdouble(bool neg, kk_context_t* _ctx); /* (neg : bool) -> std/text/parse/parse double */ 

double kk_std_num_double_pdouble(kk_context_t* _ctx); /* () -> std/text/parse/parse double */ 

kk_std_core_types__maybe kk_std_num_double_parse_double(kk_string_t s, kk_context_t* _ctx); /* (s : string) -> maybe<double> */ 
 
// Convert degrees to radians.

static inline double kk_std_num_double_rad(double deg0, kk_context_t* _ctx) { /* (deg : double) -> double */ 
  double _x6822 = ((0x1.921fb54442d18p1) / (0x1.68p7)); /*double*/
  return (deg0 * _x6822);
}

double kk_std_num_double_round_to_prec(double d, kk_integer_t prec, kk_context_t* _ctx); /* (d : double, prec : int) -> double */ 

kk_string_t kk_std_num_double_show_hex(double d, kk_std_core_types__optional width, kk_std_core_types__optional use_capitals, kk_std_core_types__optional pre, kk_context_t* _ctx); /* (d : double, width : optional<int>, use-capitals : optional<bool>, pre : optional<string>) -> string */ 
 
// Return if two doubles are nearly equal with respect to an `epsilon` of `8*dbl-epsilon`.
// See also `nearly-eq` which takes an explicit `epsilon`.

static inline bool kk_std_num_double__lp__tilde__eq__rp_(double x, double y, kk_context_t* _ctx) { /* (x : double, y : double) -> bool */ 
  return kk_std_num_double_nearly_eq(x, y, kk_std_core_types__new_None(_ctx), _ctx);
}

void kk_std_num_double__init(kk_context_t* _ctx);

#endif // header
