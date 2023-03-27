// Koka generated module: "std/num/double", koka version: 2.1.3
#include "std_num_double.h"
/*---------------------------------------------------------------------------
  Copyright 2020 Daan Leijen, Microsoft Corporation.

  This is free software; you can redistribute it and/or modify it under the
  terms of the Apache License, Version 2.0. A copy of the License can be
  found in the file "license.txt" at the root of this distribution.
---------------------------------------------------------------------------*/

static inline kk_std_core_types__tuple2_ kk_double_to_bits( double d, kk_context_t* ctx ) {
  uint64_t u;
  memcpy(&u,&d,sizeof(u));  // safe for C aliasing: see <https://gist.github.com/shafik/848ae25ee209f698763cffee272a58f8#how-do-we-type-pun-correctly>
  return kk_std_core_types__new_dash__lp__comma__rp_( kk_int32_box((int32_t)u, ctx), kk_int32_box((int32_t)(u >> 32), ctx), ctx );
}

static inline double kk_double_from_bits( int32_t lo, int32_t hi, kk_context_t* ctx ) {
  KK_UNUSED(ctx);
  double d;
  uint64_t u = (((uint64_t)((uint32_t)hi)) << 32) | (uint32_t)lo;  // note: careful about sign extension
  memcpy(&d,&u,sizeof(d));
  return d;
}

static inline double kk_prim_parse_double( kk_string_t str, kk_context_t* ctx) {
  const char* s = kk_string_cbuf_borrow(str,NULL);
  char* end;
  double d = strtod(s,&end);
  kk_string_drop(str,ctx);  
  return d;
}

 
// The maximum of a list of absolute values.


// lift anonymous function
struct kk_std_num_double_abs_max_fun6355__t_1 {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_double_abs_max_fun6355_1(kk_function_t _fself, kk_box_t _b_5820, kk_box_t _b_5821, kk_context_t* _ctx);
static kk_function_t kk_std_num_double_new_abs_max_fun6355_1(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_double_abs_max_fun6355_1, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_double_abs_max_fun6355_1(kk_function_t _fself, kk_box_t _b_5820, kk_box_t _b_5821, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x6356;
  double x0_5676;
  double _x6357 = kk_double_unbox(_b_5821, _ctx); /*double*/
  x0_5676 = kk_double_abs(_x6357); /*double*/
  bool _match_6352;
  double _x6358;
  kk_box_t _x6359 = kk_box_dup(_b_5820); /*2*/
  _x6358 = kk_double_unbox(_x6359, _ctx); /*double*/
  _match_6352 = (x0_5676 >= _x6358); /*bool*/
  if (_match_6352) {
    kk_box_drop(_b_5820, _ctx);
    _x6356 = x0_5676; /*double*/
  }
  else {
    _x6356 = kk_double_unbox(_b_5820, _ctx); /*double*/
  }
  return kk_double_box(_x6356, _ctx);
}

double kk_std_num_double_abs_max_1(kk_std_core__list xs, kk_context_t* _ctx) { /* (xs : list<double>) -> double */ 
  kk_box_t _x6354 = kk_std_core_foldl(xs, kk_double_box(0x0p+0, _ctx), kk_std_num_double_new_abs_max_fun6355_1(_ctx), _ctx); /*2*/
  return kk_double_unbox(_x6354, _ctx);
}
 
// The area hyperbolic cosine of `d`

double kk_std_num_double_acosh(double d, kk_context_t* _ctx) { /* (d : double) -> double */ 
  return acosh(d);
}
 
// The area hyperbolic sine of `d`

double kk_std_num_double_asinh(double d, kk_context_t* _ctx) { /* (d : double) -> double */ 
  return asinh(d);
}
 
// The area hyperbolic tangent of `d`

double kk_std_num_double_atanh(double d, kk_context_t* _ctx) { /* (d : double) -> double */ 
  return atanh(d);
}

kk_integer_t kk_std_num_double_dbl_max_prec;
 
// Low-level: return the `(lo,hi)` bits of a 64-bit double.

kk_std_core_types__tuple2_ kk_std_num_double_double_to_bits(double d, kk_context_t* _ctx) { /* (d : double) -> (int32, int32) */ 
  return kk_double_to_bits(d,kk_context());
}
 
// Low-level: create a `:double` from the given `lo` and `hi` 32-bits.

double kk_std_num_double_double_from_bits(int32_t lo, int32_t hi, kk_context_t* _ctx) { /* (lo : int32, hi : int32) -> double */ 
  return kk_double_from_bits(lo,hi,kk_context());
}

double kk_std_num_double_make_neginf(kk_context_t* _ctx) { /* () -> double */ 
  return -HUGE_VAL;
}

double kk_std_num_double_make_posinf(kk_context_t* _ctx) { /* () -> double */ 
  return HUGE_VAL;
}
 
// fused multiply-add. Computes `(x*y)+z` as if to infinite precision
// with only the final result rounded back to a `:double`.

double kk_std_num_double_fmadd(double x, double y, double z, kk_context_t* _ctx) { /* (x : double, y : double, z : double) -> double */ 
  return fma(x,y,z);
}
 
// Return the sum of a list of doubles.
// Uses [Kahan-Babu&scaron;kan-Neumaier summation](https://en.wikipedia.org/wiki/Kahan_summation_algorithm#Further_enhancements)
// to minimize rounding errors. This
// is more precise as Kahan summation and about as fast.
// `[1.0e3,1.0e97,1.0e3,-1.0e97].sum == 2000.0`
// A. Neumaier, _Rundungsfehleranalyse einiger Verfahren zur Summation endlicher Summen_.
// Math. Mechanik, 54:39--51, 1974.


// lift anonymous function
struct kk_std_num_double_sum_fun6363__t {
  struct kk_function_s _base;
  kk_ref_t loc;
  kk_ref_t loc0;
};
static kk_unit_t kk_std_num_double_sum_fun6363(kk_function_t _fself, kk_box_t _b_5849, kk_context_t* _ctx);
static kk_function_t kk_std_num_double_new_sum_fun6363(kk_ref_t loc, kk_ref_t loc0, kk_context_t* _ctx) {
  struct kk_std_num_double_sum_fun6363__t* _self = kk_function_alloc_as(struct kk_std_num_double_sum_fun6363__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_num_double_sum_fun6363, kk_context());
  _self->loc = loc;
  _self->loc0 = loc0;
  return &_self->_base;
}

static kk_unit_t kk_std_num_double_sum_fun6363(kk_function_t _fself, kk_box_t _b_5849, kk_context_t* _ctx) {
  struct kk_std_num_double_sum_fun6363__t* _self = kk_function_as(struct kk_std_num_double_sum_fun6363__t*, _fself);
  kk_ref_t loc = _self->loc; /* local-var<global,double> */
  kk_ref_t loc0 = _self->loc0; /* local-var<global,double> */
  kk_drop_match(_self, {kk_ref_dup(loc);kk_ref_dup(loc0);}, {}, _ctx)
  double t;
  double _x6364;
  kk_box_t _x6365;
  kk_ref_t _x6366 = kk_ref_dup(loc); /*local-var<global,double>*/
  _x6365 = (kk_ref_get(_x6366,kk_context())); /*0*/
  _x6364 = kk_double_unbox(_x6365, _ctx); /*double*/
  double _x6367;
  kk_box_t _x6368 = kk_box_dup(_b_5849); /*1*/
  _x6367 = kk_double_unbox(_x6368, _ctx); /*double*/
  t = (_x6364 + _x6367); /*double*/
  double c;
  bool _match_6349;
  double _x6369;
  double _x6370;
  kk_box_t _x6371;
  kk_ref_t _x6372 = kk_ref_dup(loc); /*local-var<global,double>*/
  _x6371 = (kk_ref_get(_x6372,kk_context())); /*0*/
  _x6370 = kk_double_unbox(_x6371, _ctx); /*double*/
  _x6369 = kk_double_abs(_x6370); /*double*/
  double _x6373;
  double _x6374;
  kk_box_t _x6375 = kk_box_dup(_b_5849); /*1*/
  _x6374 = kk_double_unbox(_x6375, _ctx); /*double*/
  _x6373 = kk_double_abs(_x6374); /*double*/
  _match_6349 = (_x6369 >= _x6373); /*bool*/
  if (_match_6349) {
    double _x6376;
    double _x6377;
    kk_box_t _x6378;
    kk_ref_t _x6379 = kk_ref_dup(loc); /*local-var<global,double>*/
    _x6378 = (kk_ref_get(_x6379,kk_context())); /*0*/
    _x6377 = kk_double_unbox(_x6378, _ctx); /*double*/
    _x6376 = (_x6377 - t); /*double*/
    double _x6380 = kk_double_unbox(_b_5849, _ctx); /*double*/
    c = (_x6376 + _x6380); /*double*/
  }
  else {
    double _x6381;
    double _x6382 = kk_double_unbox(_b_5849, _ctx); /*double*/
    _x6381 = (_x6382 - t); /*double*/
    double _x6383;
    kk_box_t _x6384;
    kk_ref_t _x6385 = kk_ref_dup(loc); /*local-var<global,double>*/
    _x6384 = (kk_ref_get(_x6385,kk_context())); /*0*/
    _x6383 = kk_double_unbox(_x6384, _ctx); /*double*/
    c = (_x6381 + _x6383); /*double*/
  }
  kk_unit_t __ = kk_Unit;
  double _b_5843_5841;
  double _x6386;
  kk_box_t _x6387;
  kk_ref_t _x6388 = kk_ref_dup(loc0); /*local-var<global,double>*/
  _x6387 = (kk_ref_get(_x6388,kk_context())); /*0*/
  _x6386 = kk_double_unbox(_x6387, _ctx); /*double*/
  _b_5843_5841 = (_x6386 + c); /*double*/
  (kk_ref_set(loc0,(kk_double_box(_b_5843_5841, _ctx)),kk_context()));
  return (kk_ref_set(loc,(kk_double_box(t, _ctx)),kk_context()));
}

double kk_std_num_double_sum(kk_std_core__list xs, kk_context_t* _ctx) { /* (xs : list<double>) -> double */ 
  kk_ref_t loc = kk_ref_alloc((kk_double_box(0x0p+0, _ctx)),kk_context()); /*local-var<global,double>*/;
  double res;
  kk_ref_t loc0 = kk_ref_alloc((kk_double_box(0x0p+0, _ctx)),kk_context()); /*local-var<global,double>*/;
  double res0;
  kk_unit_t __0 = kk_Unit;
  kk_function_t _x6362;
  kk_ref_dup(loc);
  kk_ref_dup(loc0);
  _x6362 = kk_std_num_double_new_sum_fun6363(loc, loc0, _ctx); /*(1) -> 2 ()*/
  kk_std_core_foreach(xs, _x6362, _ctx);
  double _x6389;
  kk_box_t _x6390;
  kk_ref_t _x6391 = kk_ref_dup(loc); /*local-var<global,double>*/
  _x6390 = (kk_ref_get(_x6391,kk_context())); /*0*/
  _x6389 = kk_double_unbox(_x6390, _ctx); /*double*/
  double _x6392;
  kk_box_t _x6393;
  kk_ref_t _x6394 = kk_ref_dup(loc0); /*local-var<global,double>*/
  _x6393 = (kk_ref_get(_x6394,kk_context())); /*0*/
  _x6392 = kk_double_unbox(_x6393, _ctx); /*double*/
  res0 = (_x6389 + _x6392); /*double*/
  kk_box_t _x6395 = kk_std_core_hnd_prompt_local_var(loc0, kk_double_box(res0, _ctx), _ctx); /*2*/
  res = kk_double_unbox(_x6395, _ctx); /*double*/
  kk_box_t _x6396 = kk_std_core_hnd_prompt_local_var(loc, kk_double_box(res, _ctx), _ctx); /*2*/
  return kk_double_unbox(_x6396, _ctx);
}
 
// Is this value equal to negative or positive infinity ?

bool kk_std_num_double_is_inf(double _arg1, kk_context_t* _ctx) { /* (double) -> bool */ 
  return isinf(_arg1);
}

double kk_std_num_double_make_nan(kk_context_t* _ctx) { /* () -> double */ 
  return (double)NAN;
}
 
// Return `nan` on failure

double kk_std_num_double_prim_parse_double(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> double */ 
  return kk_prim_parse_double(s,kk_context());
}
 
// decode a normalized double (i.e. not subnormal)

kk_std_core_types__tuple2_ kk_std_num_double_decode_normalized(double d, kk_std_core_types__optional e_adjust, kk_context_t* _ctx) { /* (d : double, e-adjust : optional<int>) -> (int, int) */ 
  kk_std_core_types__tuple2_ _match_6346 = kk_std_num_double_double_to_bits(d, _ctx); /*(int32, int32)*/;
  kk_box_t _box_x5867 = _match_6346.fst;
  kk_box_t _box_x5868 = _match_6346.snd;
  int32_t lo = kk_int32_unbox(_box_x5867, NULL);
  int32_t hi = kk_int32_unbox(_box_x5868, NULL);
  kk_std_core_types__tuple2__drop(_match_6346, _ctx);
  kk_integer_t sign;
  bool _match_6347 = (hi)<0; /*bool*/;
  if (_match_6347) {
    sign = kk_integer_from_small(-1); /*int*/
  }
  else {
    sign = kk_integer_from_small(1); /*int*/
  }
  kk_integer_t exp;
  kk_integer_t _x6400;
  int32_t _x6401;
  int32_t _x6402 = ((int32_t)((uint32_t)hi >> (((int32_t)20)))); /*int32*/
  _x6401 = (_x6402 & (((int32_t)2047))); /*int32*/
  _x6400 = kk_integer_from_int(_x6401,kk_context()); /*int*/
  exp = kk_integer_sub(_x6400,(kk_integer_from_small(1043)),kk_context()); /*int*/
  kk_integer_t man;
  kk_integer_t _x6403;
  int32_t _x6404 = (hi & (((int32_t)1048575))); /*int32*/
  _x6403 = kk_integer_from_int(_x6404,kk_context()); /*int*/
  man = kk_integer_add(_x6403,(kk_integer_from_int(1048576, _ctx)),kk_context()); /*int*/
  kk_integer_t _b_5872_5870;
  kk_integer_t _x6405;
  kk_integer_t _x6406 = kk_integer_mul(man,(kk_integer_from_str("4294967296", _ctx)),kk_context()); /*int*/
  kk_integer_t _x6407 = kk_std_num_int32_uint(lo, _ctx); /*int*/
  _x6405 = kk_integer_add(_x6406,_x6407,kk_context()); /*int*/
  _b_5872_5870 = kk_integer_mul(sign,_x6405,kk_context()); /*int*/
  kk_integer_t _b_5873_5871;
  kk_integer_t _x6408 = kk_integer_sub(exp,(kk_integer_from_small(32)),kk_context()); /*int*/
  kk_integer_t _x6409;
  if (kk_std_core_types__is_Optional(e_adjust)) {
    kk_box_t _box_x5869 = e_adjust._cons.Optional.value;
    kk_integer_t _e_adjust_974 = kk_integer_unbox(_box_x5869);
    kk_integer_dup(_e_adjust_974);
    kk_std_core_types__optional_drop(e_adjust, _ctx);
    _x6409 = _e_adjust_974; /*int*/
    goto _match6410;
  }
  _x6409 = kk_integer_from_small(0); /*int*/
  _match6410: ;
  _b_5873_5871 = kk_integer_add(_x6408,_x6409,kk_context()); /*int*/
  return kk_std_core_types__new_dash__lp__comma__rp_(kk_integer_box(_b_5872_5870), kk_integer_box(_b_5873_5871), _ctx);
}
 
// Decode a double `d` into a tuple `(m,e)` of a mantissa `m` and exponent `e`
// such that `m`&middot;2^`e`^ =  `d` exactly. The mantissa `m` is
// always either 0 or in the range [2^52^, 2^53^). See also `frexp`.

kk_std_core_types__tuple2_ kk_std_num_double_decode(double d, kk_context_t* _ctx) { /* (d : double) -> (int, int) */ 
  bool _match_6343 = (d == (0x0p+0)); /*bool*/;
  if (_match_6343) {
    return kk_std_core_types__new_dash__lp__comma__rp_(kk_integer_box(kk_integer_from_small(0)), kk_integer_box(kk_integer_from_small(0)), _ctx);
  }
  bool _match_6344 = kk_std_num_double_is_subnormal(d, _ctx); /*bool*/;
  if (_match_6344) {
    double _x6413 = (d * 0x1p54); /*double*/
    kk_std_core_types__optional _x6414 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(-54)), _ctx); /*optional<35>*/
    return kk_std_num_double_decode_normalized(_x6413, _x6414, _ctx);
  }
  kk_std_core_types__optional _x6415 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(0)), _ctx); /*optional<35>*/
  return kk_std_num_double_decode_normalized(d, _x6415, _ctx);
}

double kk_std_num_double_rad2deg;

double kk_std_num_double_deg2rad;
 
// Calculate 2&middot;^`e`^ for an integer `e`.
// Uses efficient bit conversion for exponents between  -1022 and 1023 and
// otherwise falls back to the regular `exp2` function converting `e` to a double.

double kk_std_num_double_exp2_1(kk_integer_t e, kk_context_t* _ctx) { /* (e : int) -> double */ 
  bool _match_6341;
  bool _match_6342;
  kk_integer_t _x6417 = kk_integer_dup(e); /*int*/
  _match_6342 = kk_integer_gte(_x6417,(kk_integer_from_small(-1022)),kk_context()); /*bool*/
  if (_match_6342) {
    kk_integer_t _x6418 = kk_integer_dup(e); /*int*/
    _match_6341 = kk_integer_lte(_x6418,(kk_integer_from_small(1023)),kk_context()); /*bool*/
  }
  else {
    _match_6341 = false; /*bool*/
  }
  if (_match_6341) {
    int32_t _x6419;
    int32_t _x6420;
    kk_integer_t _x6421 = kk_integer_add((kk_integer_from_small(1023)),e,kk_context()); /*int*/
    _x6420 = kk_std_core_int32(_x6421, _ctx); /*int32*/
    _x6419 = (_x6420 << (((int32_t)20))); /*int32*/
    return kk_std_num_double_double_from_bits(((int32_t)0), _x6419, _ctx);
  }
  double p_5685 = kk_integer_as_double(e,kk_context()); /*double*/;
  return pow(0x1p1,p_5685);
}

double kk_std_num_double_neginf;

double kk_std_num_double_posinf;
 
// 'Load exponent': returns `x`&middot;2^`e`^ for a `is-finite` `x` and
// otherwise `x` itself. See also `encode` which loads an integer mantissa.

double kk_std_num_double_ldexp(double x, kk_integer_t e, kk_context_t* _ctx) { /* (x : double, e : int) -> double */ 
  bool _match_6332;
  bool _x6423 = isfinite(x); /*bool*/
  _match_6332 = !(_x6423); /*bool*/
  if (_match_6332) {
    kk_integer_drop(e, _ctx);
    return x;
  }
  bool _match_6333;
  kk_integer_t _x6424 = kk_integer_dup(e); /*int*/
  _match_6333 = kk_integer_gte(_x6424,(kk_integer_from_small(-1022)),kk_context()); /*bool*/
  if (_match_6333) {
    bool _match_6337;
    kk_integer_t _x6425 = kk_integer_dup(e); /*int*/
    _match_6337 = kk_integer_lte(_x6425,(kk_integer_from_small(1023)),kk_context()); /*bool*/
    if (_match_6337) {
      return kk_std_num_double_mul_exp2(x, e, _ctx);
    }
    bool _match_6338;
    kk_integer_t _x6426 = kk_integer_dup(e); /*int*/
    _match_6338 = kk_integer_lte(_x6426,(kk_integer_from_small(2046)),kk_context()); /*bool*/
    if (_match_6338) {
      double x0_5686 = (x * 0x1p1023); /*double*/;
      kk_integer_t e0_5687 = kk_integer_sub(e,(kk_integer_from_small(1023)),kk_context()); /*int*/;
      double _x6427 = kk_std_num_double_exp2_1(e0_5687, _ctx); /*double*/
      return (x0_5686 * _x6427);
    }
    bool _match_6339;
    kk_integer_t _x6428 = kk_integer_dup(e); /*int*/
    _match_6339 = kk_integer_lte(_x6428,(kk_integer_from_int(3069, _ctx)),kk_context()); /*bool*/
    if (_match_6339) {
      double x1_5688;
      double _x6429 = (x * 0x1p1023); /*double*/
      x1_5688 = (_x6429 * 0x1p1023); /*double*/
      kk_integer_t e1_5689 = kk_integer_sub(e,(kk_integer_from_small(2046)),kk_context()); /*int*/;
      double _x6430 = kk_std_num_double_exp2_1(e1_5689, _ctx); /*double*/
      return (x1_5688 * _x6430);
    }
    kk_integer_drop(e, _ctx);
    bool _match_6340 = (x < (0x0p+0)); /*bool*/;
    if (_match_6340) {
      return kk_std_num_double_make_neginf(_ctx);
    }
    return kk_std_num_double_make_posinf(_ctx);
  }
  bool _match_6334;
  kk_integer_t _x6431 = kk_integer_dup(e); /*int*/
  _match_6334 = kk_integer_gte(_x6431,(kk_integer_from_small(-2044)),kk_context()); /*bool*/
  if (_match_6334) {
    double x2_5690 = (x * (0x1p-1022)); /*double*/;
    kk_integer_t e2_5691 = kk_integer_add(e,(kk_integer_from_small(1022)),kk_context()); /*int*/;
    double _x6432 = kk_std_num_double_exp2_1(e2_5691, _ctx); /*double*/
    return (x2_5690 * _x6432);
  }
  bool _match_6335;
  kk_integer_t _x6433 = kk_integer_dup(e); /*int*/
  _match_6335 = kk_integer_gte(_x6433,(kk_integer_from_int(-3066, _ctx)),kk_context()); /*bool*/
  if (_match_6335) {
    double x3_5692;
    double _x6434 = (x * (0x1p-1022)); /*double*/
    x3_5692 = (_x6434 * (0x1p-1022)); /*double*/
    kk_integer_t e3_5693 = kk_integer_add(e,(kk_integer_from_small(2044)),kk_context()); /*int*/;
    double _x6435 = kk_std_num_double_exp2_1(e3_5693, _ctx); /*double*/
    return (x3_5692 * _x6435);
  }
  kk_integer_drop(e, _ctx);
  bool _match_6336 = (x < (0x0p+0)); /*bool*/;
  if (_match_6336) {
    return -0x0p+0;
  }
  return 0x0p+0;
}
 
// 'Fraction/exponent': return the normalized fraction `f` and exponent `exp`
// for a number `x` such that `x == f`&middot;2^`exp`^.
// The absolute value of the fraction `f` is always in the range [0.5, 1.0), or
// one of `0.0`, `-0.0`, `neginf`, `posinf`, or `nan`.
// See also `decode` which  decodes to an integer mantissa.

kk_std_core_types__tuple2_ kk_std_num_double_frexp(double x, kk_context_t* _ctx) { /* (x : double) -> (double, int) */ 
  bool _match_6329;
  bool _match_6331;
  bool _x6439 = isfinite(x); /*bool*/
  _match_6331 = !(_x6439); /*bool*/
  if (_match_6331) {
    _match_6329 = true; /*bool*/
  }
  else {
    _match_6329 = kk_std_num_double_is_negzero(x, _ctx); /*bool*/
  }
  if (_match_6329) {
    return kk_std_core_types__new_dash__lp__comma__rp_(kk_double_box(x, _ctx), kk_integer_box(kk_integer_from_small(0)), _ctx);
  }
  kk_std_core_types__tuple2_ _match_6330 = kk_std_num_double_decode(x, _ctx); /*(int, int)*/;
  kk_box_t _box_x5884 = _match_6330.fst;
  kk_box_t _box_x5885 = _match_6330.snd;
  kk_integer_t m = kk_integer_unbox(_box_x5884);
  kk_integer_t e = kk_integer_unbox(_box_x5885);
  kk_integer_dup(e);
  kk_integer_dup(m);
  kk_std_core_types__tuple2__drop(_match_6330, _ctx);
  double _b_5890_5886;
  double _x6442 = kk_integer_as_double(m,kk_context()); /*double*/
  _b_5890_5886 = (_x6442 * (0x1p-53)); /*double*/
  kk_integer_t _b_5891_5887 = kk_integer_add(e,(kk_integer_from_small(53)),kk_context()); /*int*/;
  return kk_std_core_types__new_dash__lp__comma__rp_(kk_double_box(_b_5890_5886, _ctx), kk_integer_box(_b_5891_5887), _ctx);
}
 
// The hypotenuse of `x` and `y`: `sqrt(x*x + y*y)`.
// Prevents overflow for large numbers.

double kk_std_num_double_hypot(double x, double y, kk_context_t* _ctx) { /* (x : double, y : double) -> double */ 
  double xx = kk_double_abs(x); /*double*/;
  double yy = kk_double_abs(y); /*double*/;
  double lo = kk_std_core_min_1(xx, yy, _ctx); /*double*/;
  double hi = kk_std_core_max_1(xx, yy, _ctx); /*double*/;
  bool _match_6328 = (hi == (0x0p+0)); /*bool*/;
  if (_match_6328) {
    return 0x0p+0;
  }
  double z = (lo / hi); /*double*/;
  double _x6443;
  double _x6444;
  double _x6445 = (z * z); /*double*/
  _x6444 = (0x1p0 + _x6445); /*double*/
  _x6443 = sqrt(_x6444); /*double*/
  return (hi * _x6443);
}
 
// The square root of the sum of the squares of three doubles.
// Prevents overflow for large numbers.

double kk_std_num_double_hypot_1(double x, double y, double z, kk_context_t* _ctx) { /* (x : double, y : double, z : double) -> double */ 
  double xx = kk_double_abs(x); /*double*/;
  double yy = kk_double_abs(y); /*double*/;
  double zz = kk_double_abs(z); /*double*/;
  double hi;
  double x0_5694 = kk_std_core_max_1(xx, yy, _ctx); /*double*/;
  bool _match_6327 = (x0_5694 >= zz); /*bool*/;
  if (_match_6327) {
    hi = x0_5694; /*double*/
  }
  else {
    hi = zz; /*double*/
  }
  bool _match_6326 = (hi == (0x0p+0)); /*bool*/;
  if (_match_6326) {
    return 0x0p+0;
  }
  double _x6446;
  double _x6447;
  double _x6448;
  double _x6449;
  double x1_5696 = (xx / hi); /*double*/;
  _x6449 = (x1_5696 * x1_5696); /*double*/
  double _x6450;
  double x2_5697 = (yy / hi); /*double*/;
  _x6450 = (x2_5697 * x2_5697); /*double*/
  _x6448 = (_x6449 + _x6450); /*double*/
  double _x6451;
  double x3_5698 = (zz / hi); /*double*/;
  _x6451 = (x3_5698 * x3_5698); /*double*/
  _x6447 = (_x6448 + _x6451); /*double*/
  _x6446 = sqrt(_x6447); /*double*/
  return (hi * _x6446);
}
 
// The square root of the sum of squares of a list of doubles.
// Prevents overflow for large numbers and uses Kahan-Babu&scaron;kan-Neumaier summation
// for precision.


// lift anonymous function
struct kk_std_num_double_hypot_fun6456__t_2 {
  struct kk_function_s _base;
  double hi;
};
static kk_box_t kk_std_num_double_hypot_fun6456_2(kk_function_t _fself, kk_box_t _b_5894, kk_context_t* _ctx);
static kk_function_t kk_std_num_double_new_hypot_fun6456_2(double hi, kk_context_t* _ctx) {
  struct kk_std_num_double_hypot_fun6456__t_2* _self = kk_function_alloc_as(struct kk_std_num_double_hypot_fun6456__t_2, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_num_double_hypot_fun6456_2, kk_context());
  _self->hi = hi;
  return &_self->_base;
}

static kk_box_t kk_std_num_double_hypot_fun6456_2(kk_function_t _fself, kk_box_t _b_5894, kk_context_t* _ctx) {
  struct kk_std_num_double_hypot_fun6456__t_2* _self = kk_function_as(struct kk_std_num_double_hypot_fun6456__t_2*, _fself);
  double hi = _self->hi; /* double */
  kk_drop_match(_self, {;}, {}, _ctx)
  double _x6457;
  double x0_5699;
  double _x6458 = kk_double_unbox(_b_5894, _ctx); /*double*/
  x0_5699 = (_x6458 / hi); /*double*/
  _x6457 = (x0_5699 * x0_5699); /*double*/
  return kk_double_box(_x6457, _ctx);
}

double kk_std_num_double_hypot_2(kk_std_core__list xs, kk_context_t* _ctx) { /* (xs : list<double>) -> double */ 
  double hi;
  kk_std_core__list _x6452 = kk_std_core__list_dup(xs); /*list<double>*/
  hi = kk_std_num_double_abs_max_1(_x6452, _ctx); /*double*/
  bool _match_6325 = (hi == (0x0p+0)); /*bool*/;
  if (_match_6325) {
    kk_std_core__list_drop(xs, _ctx);
    return 0x0p+0;
  }
  double _x6453;
  double _x6454;
  kk_std_core__list _x6455 = kk_std_core_map_5(xs, kk_std_num_double_new_hypot_fun6456_2(hi, _ctx), _ctx); /*list<2>*/
  _x6454 = kk_std_num_double_sum(_x6455, _ctx); /*double*/
  _x6453 = sqrt(_x6454); /*double*/
  return (hi * _x6453);
}
 
// Returns `log(exp(x) + exp(y))`.
// Avoids overlow/underflow errors.

double kk_std_num_double_logaddexp(double x, double y, kk_context_t* _ctx) { /* (x : double, y : double) -> double */ 
  bool _match_6323 = (x == y); /*bool*/;
  if (_match_6323) {
    return (x + (0x1.62e42fefa39efp-1));
  }
  double z = (x - y); /*double*/;
  bool _match_6324 = (z > (0x0p+0)); /*bool*/;
  if (_match_6324) {
    double _x6462;
    double _x6463;
    double _x6464 = (-z); /*double*/
    _x6463 = exp(_x6464); /*double*/
    _x6462 = log1p(_x6463); /*double*/
    return (x + _x6462);
  }
  double _x6465;
  double _x6466 = exp(z); /*double*/
  _x6465 = log1p(_x6466); /*double*/
  return (y + _x6465);
}
 
// Returns `log2( exp2(x) + exp2(y) )`.
// Avoids overlow/underflow errors.

double kk_std_num_double_logaddexp2(double x, double y, kk_context_t* _ctx) { /* (x : double, y : double) -> double */ 
  bool _match_6321 = (x == y); /*bool*/;
  if (_match_6321) {
    return (x + 0x1p0);
  }
  double z = (x - y); /*double*/;
  bool _match_6322 = (z > (0x0p+0)); /*bool*/;
  if (_match_6322) {
    double _x6467;
    double x0_5700;
    double p_5701 = (-z); /*double*/;
    x0_5700 = pow(0x1p1,p_5701); /*double*/
    double _x6468 = log1p(x0_5700); /*double*/
    _x6467 = ((0x1.71547652b82fep0) * _x6468); /*double*/
    return (x + _x6467);
  }
  double _x6469;
  double x1_5702 = kk_std_num_double_exp2(z, _ctx); /*double*/;
  double _x6470 = log1p(x1_5702); /*double*/
  _x6469 = ((0x1.71547652b82fep0) * _x6470); /*double*/
  return (y + _x6469);
}

double kk_std_num_double_nan;
 
// Return if two doubles are nearly equal with respect to some `epsilon` (=`8*dbl-epsilon`).
// The epsilon is the nearest difference for numbers around 1.0. The routine automatically
// scales the epsilon for larger and smaller numbers, and for subnormal numbers.

bool kk_std_num_double_nearly_eq(double x, double y, kk_std_core_types__optional epsilon, kk_context_t* _ctx) { /* (x : double, y : double, epsilon : optional<double>) -> bool */ 
  double _epsilon_3819;
  if (kk_std_core_types__is_Optional(epsilon)) {
    kk_box_t _box_x5898 = epsilon._cons.Optional.value;
    double _epsilon_3820 = kk_double_unbox(_box_x5898, NULL);
    kk_std_core_types__optional_drop(epsilon, _ctx);
    _epsilon_3819 = _epsilon_3820; /*double*/
    goto _match6471;
  }
  _epsilon_3819 = (0x1p3 * (0x1p-52)); /*double*/
  _match6471: ;
  bool _match_6316 = (x == y); /*bool*/;
  if (_match_6316) {
    return true;
  }
  double diff;
  double _x6473 = (x - y); /*double*/
  diff = kk_double_abs(_x6473); /*double*/
  bool _match_6317;
  bool _match_6319 = (x == (0x0p+0)); /*bool*/;
  if (_match_6319) {
    _match_6317 = true; /*bool*/
  }
  else {
    bool _match_6320 = (y == (0x0p+0)); /*bool*/;
    if (_match_6320) {
      _match_6317 = true; /*bool*/
    }
    else {
      _match_6317 = (diff < (0x1p-1022)); /*bool*/
    }
  }
  if (_match_6317) {
    double _x6474 = (0x1p1 * diff); /*double*/
    double _x6475 = (_epsilon_3819 * (0x1p-1022)); /*double*/
    return (_x6474 < _x6475);
  }
  double sum0;
  double _x6476 = kk_double_abs(x); /*double*/
  double _x6477 = kk_double_abs(y); /*double*/
  sum0 = (_x6476 + _x6477); /*double*/
  double _x6478;
  double _x6479 = (0x1p1 * diff); /*double*/
  double _x6480;
  bool _match_6318 = (sum0 > (0x1.fffffffffffffp1023)); /*bool*/;
  if (_match_6318) {
    _x6480 = 0x1.fffffffffffffp1023; /*double*/
  }
  else {
    _x6480 = sum0; /*double*/
  }
  _x6478 = (_x6479 / _x6480); /*double*/
  return (_x6478 < _epsilon_3819);
}
 
// monadic lift

kk_integer_t kk_std_num_double__mlift5656_pdecdouble(kk_char_t wild__0, kk_context_t* _ctx) { /* (wild_0 : char) -> std/text/parse/parse int */ 
  return kk_std_text_parse_pint(_ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_num_double__mlift5657_pdecdouble_fun6482__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_double__mlift5657_pdecdouble_fun6482(kk_function_t _fself, kk_box_t _b_5901, kk_context_t* _ctx);
static kk_function_t kk_std_num_double__new_mlift5657_pdecdouble_fun6482(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_double__mlift5657_pdecdouble_fun6482, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_double__mlift5657_pdecdouble_fun6482(kk_function_t _fself, kk_box_t _b_5901, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x6483;
  kk_string_t _x6484 = kk_string_unbox(_b_5901); /*string*/
  _x6483 = kk_std_num_double_prim_parse_double(_x6484, _ctx); /*double*/
  return kk_double_box(_x6483, _ctx);
}

double kk_std_num_double__mlift5657_pdecdouble(kk_std_core__sslice cur, kk_integer_t exp, kk_context_t* _ctx) { /* (cur : sslice, exp : int) -> std/text/parse/parse double */ 
  kk_integer_drop(exp, _ctx);
  kk_string_t _x1 = kk_std_core_string_3(cur, _ctx); /*string*/;
  kk_box_t _x6481 = kk_std_core_hnd__open_none1(kk_std_num_double__new_mlift5657_pdecdouble_fun6482(_ctx), kk_string_box(_x1), _ctx); /*2*/
  return kk_double_unbox(_x6481, _ctx);
}
 
// monadic lift

kk_string_t kk_std_num_double__mlift5658_pdecdouble(kk_char_t wild__, kk_context_t* _ctx) { /* (wild_ : char) -> std/text/parse/parse string */ 
  return kk_std_text_parse_digits0(_ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_num_double__mlift5659_pdecdouble_fun6488__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_double__mlift5659_pdecdouble_fun6488(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_double__new_mlift5659_pdecdouble_fun6488(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_double__mlift5659_pdecdouble_fun6488, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_std_num_double__mlift5659_pdecdouble_fun6493__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_double__mlift5659_pdecdouble_fun6493(kk_function_t _fself, kk_box_t _b_5905, kk_context_t* _ctx);
static kk_function_t kk_std_num_double__new_mlift5659_pdecdouble_fun6493(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_double__mlift5659_pdecdouble_fun6493, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_double__mlift5659_pdecdouble_fun6493(kk_function_t _fself, kk_box_t _b_5905, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_integer_t _x6494;
  kk_char_t _x6495 = kk_char_unbox(_b_5905, _ctx); /*char*/
  _x6494 = kk_std_num_double__mlift5656_pdecdouble(_x6495, _ctx); /*int*/
  return kk_integer_box(_x6494);
}
static kk_box_t kk_std_num_double__mlift5659_pdecdouble_fun6488(kk_function_t _fself, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_integer_t _x6489;
  kk_char_t x0_5705;
  kk_string_t _x6490;
  kk_define_string_literal(, _s6491, 2, "eE")
  _x6490 = kk_string_dup(_s6491); /*string*/
  x0_5705 = kk_std_text_parse_one_of(_x6490, _ctx); /*char*/
  if (kk_yielding(kk_context())) {
    kk_box_t _x6492 = kk_std_core_hnd_yield_extend(kk_std_num_double__new_mlift5659_pdecdouble_fun6493(_ctx), _ctx); /*2*/
    _x6489 = kk_integer_unbox(_x6492); /*int*/
  }
  else {
    _x6489 = kk_std_num_double__mlift5656_pdecdouble(x0_5705, _ctx); /*int*/
  }
  return kk_integer_box(_x6489);
}


// lift anonymous function
struct kk_std_num_double__mlift5659_pdecdouble_fun6497__t {
  struct kk_function_s _base;
  kk_std_core__sslice cur;
};
static kk_box_t kk_std_num_double__mlift5659_pdecdouble_fun6497(kk_function_t _fself, kk_box_t _b_5912, kk_context_t* _ctx);
static kk_function_t kk_std_num_double__new_mlift5659_pdecdouble_fun6497(kk_std_core__sslice cur, kk_context_t* _ctx) {
  struct kk_std_num_double__mlift5659_pdecdouble_fun6497__t* _self = kk_function_alloc_as(struct kk_std_num_double__mlift5659_pdecdouble_fun6497__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_num_double__mlift5659_pdecdouble_fun6497, kk_context());
  _self->cur = cur;
  return &_self->_base;
}

static kk_box_t kk_std_num_double__mlift5659_pdecdouble_fun6497(kk_function_t _fself, kk_box_t _b_5912, kk_context_t* _ctx) {
  struct kk_std_num_double__mlift5659_pdecdouble_fun6497__t* _self = kk_function_as(struct kk_std_num_double__mlift5659_pdecdouble_fun6497__t*, _fself);
  kk_std_core__sslice cur = _self->cur; /* sslice */
  kk_drop_match(_self, {kk_std_core__sslice_dup(cur);}, {}, _ctx)
  double _x6498;
  kk_integer_t _x6499 = kk_integer_unbox(_b_5912); /*int*/
  _x6498 = kk_std_num_double__mlift5657_pdecdouble(cur, _x6499, _ctx); /*double*/
  return kk_double_box(_x6498, _ctx);
}

double kk_std_num_double__mlift5659_pdecdouble(kk_std_core__sslice cur, kk_string_t _y_4, kk_context_t* _ctx) { /* (cur : sslice, string) -> std/text/parse/parse double */ 
  kk_string_t frac;
  kk_string_t _x6485;
  kk_define_string_literal(, _s6486, 1, "0")
  _x6485 = kk_string_dup(_s6486); /*string*/
  frac = kk_std_core_trim_right_1(_y_4, _x6485, _ctx); /*string*/
  kk_string_drop(frac, _ctx);
  kk_integer_t x_5703;
  kk_box_t _x6487 = kk_std_text_parse_optional(kk_integer_box(kk_integer_from_small(0)), kk_std_num_double__new_mlift5659_pdecdouble_fun6488(_ctx), _ctx); /*0*/
  x_5703 = kk_integer_unbox(_x6487); /*int*/
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_5703, _ctx);
    kk_box_t _x6496 = kk_std_core_hnd_yield_extend(kk_std_num_double__new_mlift5659_pdecdouble_fun6497(cur, _ctx), _ctx); /*2*/
    return kk_double_unbox(_x6496, _ctx);
  }
  return kk_std_num_double__mlift5657_pdecdouble(cur, x_5703, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_num_double__mlift5660_pdecdouble_fun6504__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_double__mlift5660_pdecdouble_fun6504(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_double__new_mlift5660_pdecdouble_fun6504(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_double__mlift5660_pdecdouble_fun6504, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_std_num_double__mlift5660_pdecdouble_fun6507__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_double__mlift5660_pdecdouble_fun6507(kk_function_t _fself, kk_box_t _b_5916, kk_context_t* _ctx);
static kk_function_t kk_std_num_double__new_mlift5660_pdecdouble_fun6507(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_double__mlift5660_pdecdouble_fun6507, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_double__mlift5660_pdecdouble_fun6507(kk_function_t _fself, kk_box_t _b_5916, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x6508;
  kk_char_t _x6509 = kk_char_unbox(_b_5916, _ctx); /*char*/
  _x6508 = kk_std_num_double__mlift5658_pdecdouble(_x6509, _ctx); /*string*/
  return kk_string_box(_x6508);
}
static kk_box_t kk_std_num_double__mlift5660_pdecdouble_fun6504(kk_function_t _fself, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x6505;
  kk_char_t x0_5709 = kk_std_text_parse_char('.', _ctx); /*char*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x6506 = kk_std_core_hnd_yield_extend(kk_std_num_double__new_mlift5660_pdecdouble_fun6507(_ctx), _ctx); /*2*/
    _x6505 = kk_string_unbox(_x6506); /*string*/
  }
  else {
    _x6505 = kk_std_num_double__mlift5658_pdecdouble(x0_5709, _ctx); /*string*/
  }
  return kk_string_box(_x6505);
}


// lift anonymous function
struct kk_std_num_double__mlift5660_pdecdouble_fun6511__t {
  struct kk_function_s _base;
  kk_std_core__sslice cur;
};
static kk_box_t kk_std_num_double__mlift5660_pdecdouble_fun6511(kk_function_t _fself, kk_box_t _b_5923, kk_context_t* _ctx);
static kk_function_t kk_std_num_double__new_mlift5660_pdecdouble_fun6511(kk_std_core__sslice cur, kk_context_t* _ctx) {
  struct kk_std_num_double__mlift5660_pdecdouble_fun6511__t* _self = kk_function_alloc_as(struct kk_std_num_double__mlift5660_pdecdouble_fun6511__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_num_double__mlift5660_pdecdouble_fun6511, kk_context());
  _self->cur = cur;
  return &_self->_base;
}

static kk_box_t kk_std_num_double__mlift5660_pdecdouble_fun6511(kk_function_t _fself, kk_box_t _b_5923, kk_context_t* _ctx) {
  struct kk_std_num_double__mlift5660_pdecdouble_fun6511__t* _self = kk_function_as(struct kk_std_num_double__mlift5660_pdecdouble_fun6511__t*, _fself);
  kk_std_core__sslice cur = _self->cur; /* sslice */
  kk_drop_match(_self, {kk_std_core__sslice_dup(cur);}, {}, _ctx)
  double _x6512;
  kk_string_t _x6513 = kk_string_unbox(_b_5923); /*string*/
  _x6512 = kk_std_num_double__mlift5659_pdecdouble(cur, _x6513, _ctx); /*double*/
  return kk_double_box(_x6512, _ctx);
}

double kk_std_num_double__mlift5660_pdecdouble(kk_std_core__sslice cur, kk_string_t man, kk_context_t* _ctx) { /* (cur : sslice, man : string) -> std/text/parse/parse double */ 
  kk_string_drop(man, _ctx);
  kk_string_t x_5707;
  kk_box_t _x6500;
  kk_box_t _x6501;
  kk_string_t _x6502 = kk_string_empty(); /*string*/
  _x6501 = kk_string_box(_x6502); /*0*/
  _x6500 = kk_std_text_parse_optional(_x6501, kk_std_num_double__new_mlift5660_pdecdouble_fun6504(_ctx), _ctx); /*0*/
  x_5707 = kk_string_unbox(_x6500); /*string*/
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_5707, _ctx);
    kk_box_t _x6510 = kk_std_core_hnd_yield_extend(kk_std_num_double__new_mlift5660_pdecdouble_fun6511(cur, _ctx), _ctx); /*2*/
    return kk_double_unbox(_x6510, _ctx);
  }
  return kk_std_num_double__mlift5659_pdecdouble(cur, x_5707, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_num_double__mlift5661_pdecdouble_fun6515__t {
  struct kk_function_s _base;
  kk_std_core__sslice cur;
};
static kk_box_t kk_std_num_double__mlift5661_pdecdouble_fun6515(kk_function_t _fself, kk_box_t _b_5927, kk_context_t* _ctx);
static kk_function_t kk_std_num_double__new_mlift5661_pdecdouble_fun6515(kk_std_core__sslice cur, kk_context_t* _ctx) {
  struct kk_std_num_double__mlift5661_pdecdouble_fun6515__t* _self = kk_function_alloc_as(struct kk_std_num_double__mlift5661_pdecdouble_fun6515__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_num_double__mlift5661_pdecdouble_fun6515, kk_context());
  _self->cur = cur;
  return &_self->_base;
}

static kk_box_t kk_std_num_double__mlift5661_pdecdouble_fun6515(kk_function_t _fself, kk_box_t _b_5927, kk_context_t* _ctx) {
  struct kk_std_num_double__mlift5661_pdecdouble_fun6515__t* _self = kk_function_as(struct kk_std_num_double__mlift5661_pdecdouble_fun6515__t*, _fself);
  kk_std_core__sslice cur = _self->cur; /* sslice */
  kk_drop_match(_self, {kk_std_core__sslice_dup(cur);}, {}, _ctx)
  double _x6516;
  kk_string_t _x6517 = kk_string_unbox(_b_5927); /*string*/
  _x6516 = kk_std_num_double__mlift5660_pdecdouble(cur, _x6517, _ctx); /*double*/
  return kk_double_box(_x6516, _ctx);
}

double kk_std_num_double__mlift5661_pdecdouble(kk_std_core__sslice cur, kk_context_t* _ctx) { /* (cur : sslice) -> std/text/parse/parse double */ 
  kk_string_t x_5711 = kk_std_text_parse_digits(_ctx); /*string*/;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_5711, _ctx);
    kk_box_t _x6514 = kk_std_core_hnd_yield_extend(kk_std_num_double__new_mlift5661_pdecdouble_fun6515(cur, _ctx), _ctx); /*2*/
    return kk_double_unbox(_x6514, _ctx);
  }
  return kk_std_num_double__mlift5660_pdecdouble(cur, x_5711, _ctx);
}


// lift anonymous function
struct kk_std_num_double_pdecdouble_fun6519__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_double_pdecdouble_fun6519(kk_function_t _fself, kk_box_t _b_5931, kk_context_t* _ctx);
static kk_function_t kk_std_num_double_new_pdecdouble_fun6519(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_double_pdecdouble_fun6519, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_double_pdecdouble_fun6519(kk_function_t _fself, kk_box_t _b_5931, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x6520;
  kk_std_core__sslice _x6521 = kk_std_core__sslice_unbox(_b_5931, _ctx); /*sslice*/
  _x6520 = kk_std_num_double__mlift5661_pdecdouble(_x6521, _ctx); /*double*/
  return kk_double_box(_x6520, _ctx);
}


// lift anonymous function
struct kk_std_num_double_pdecdouble_fun6523__t {
  struct kk_function_s _base;
  kk_std_core__sslice x_5713;
};
static kk_box_t kk_std_num_double_pdecdouble_fun6523(kk_function_t _fself, kk_box_t _b_5933, kk_context_t* _ctx);
static kk_function_t kk_std_num_double_new_pdecdouble_fun6523(kk_std_core__sslice x_5713, kk_context_t* _ctx) {
  struct kk_std_num_double_pdecdouble_fun6523__t* _self = kk_function_alloc_as(struct kk_std_num_double_pdecdouble_fun6523__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_num_double_pdecdouble_fun6523, kk_context());
  _self->x_5713 = x_5713;
  return &_self->_base;
}

static kk_box_t kk_std_num_double_pdecdouble_fun6523(kk_function_t _fself, kk_box_t _b_5933, kk_context_t* _ctx) {
  struct kk_std_num_double_pdecdouble_fun6523__t* _self = kk_function_as(struct kk_std_num_double_pdecdouble_fun6523__t*, _fself);
  kk_std_core__sslice x_5713 = _self->x_5713; /* sslice */
  kk_drop_match(_self, {kk_std_core__sslice_dup(x_5713);}, {}, _ctx)
  double _x6524;
  kk_string_t _x6525 = kk_string_unbox(_b_5933); /*string*/
  _x6524 = kk_std_num_double__mlift5660_pdecdouble(x_5713, _x6525, _ctx); /*double*/
  return kk_double_box(_x6524, _ctx);
}


// lift anonymous function
struct kk_std_num_double_pdecdouble_fun6530__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_double_pdecdouble_fun6530(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_double_new_pdecdouble_fun6530(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_double_pdecdouble_fun6530, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_std_num_double_pdecdouble_fun6533__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_double_pdecdouble_fun6533(kk_function_t _fself, kk_box_t _b_5935, kk_context_t* _ctx);
static kk_function_t kk_std_num_double_new_pdecdouble_fun6533(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_double_pdecdouble_fun6533, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_double_pdecdouble_fun6533(kk_function_t _fself, kk_box_t _b_5935, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x6534;
  kk_char_t _x6535 = kk_char_unbox(_b_5935, _ctx); /*char*/
  _x6534 = kk_std_num_double__mlift5658_pdecdouble(_x6535, _ctx); /*string*/
  return kk_string_box(_x6534);
}
static kk_box_t kk_std_num_double_pdecdouble_fun6530(kk_function_t _fself, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x6531;
  kk_char_t x2_5724 = kk_std_text_parse_char('.', _ctx); /*char*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x6532 = kk_std_core_hnd_yield_extend(kk_std_num_double_new_pdecdouble_fun6533(_ctx), _ctx); /*2*/
    _x6531 = kk_string_unbox(_x6532); /*string*/
  }
  else {
    _x6531 = kk_std_num_double__mlift5658_pdecdouble(x2_5724, _ctx); /*string*/
  }
  return kk_string_box(_x6531);
}


// lift anonymous function
struct kk_std_num_double_pdecdouble_fun6537__t {
  struct kk_function_s _base;
  kk_std_core__sslice x_5713;
};
static kk_box_t kk_std_num_double_pdecdouble_fun6537(kk_function_t _fself, kk_box_t _b_5942, kk_context_t* _ctx);
static kk_function_t kk_std_num_double_new_pdecdouble_fun6537(kk_std_core__sslice x_5713, kk_context_t* _ctx) {
  struct kk_std_num_double_pdecdouble_fun6537__t* _self = kk_function_alloc_as(struct kk_std_num_double_pdecdouble_fun6537__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_num_double_pdecdouble_fun6537, kk_context());
  _self->x_5713 = x_5713;
  return &_self->_base;
}

static kk_box_t kk_std_num_double_pdecdouble_fun6537(kk_function_t _fself, kk_box_t _b_5942, kk_context_t* _ctx) {
  struct kk_std_num_double_pdecdouble_fun6537__t* _self = kk_function_as(struct kk_std_num_double_pdecdouble_fun6537__t*, _fself);
  kk_std_core__sslice x_5713 = _self->x_5713; /* sslice */
  kk_drop_match(_self, {kk_std_core__sslice_dup(x_5713);}, {}, _ctx)
  double _x6538;
  kk_string_t _x6539 = kk_string_unbox(_b_5942); /*string*/
  _x6538 = kk_std_num_double__mlift5659_pdecdouble(x_5713, _x6539, _ctx); /*double*/
  return kk_double_box(_x6538, _ctx);
}


// lift anonymous function
struct kk_std_num_double_pdecdouble_fun6543__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_double_pdecdouble_fun6543(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_double_new_pdecdouble_fun6543(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_double_pdecdouble_fun6543, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_std_num_double_pdecdouble_fun6548__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_double_pdecdouble_fun6548(kk_function_t _fself, kk_box_t _b_5944, kk_context_t* _ctx);
static kk_function_t kk_std_num_double_new_pdecdouble_fun6548(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_double_pdecdouble_fun6548, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_double_pdecdouble_fun6548(kk_function_t _fself, kk_box_t _b_5944, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_integer_t _x6549;
  kk_char_t _x6550 = kk_char_unbox(_b_5944, _ctx); /*char*/
  _x6549 = kk_std_num_double__mlift5656_pdecdouble(_x6550, _ctx); /*int*/
  return kk_integer_box(_x6549);
}
static kk_box_t kk_std_num_double_pdecdouble_fun6543(kk_function_t _fself, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_integer_t _x6544;
  kk_char_t x4_5730;
  kk_string_t _x6545;
  kk_define_string_literal(, _s6546, 2, "eE")
  _x6545 = kk_string_dup(_s6546); /*string*/
  x4_5730 = kk_std_text_parse_one_of(_x6545, _ctx); /*char*/
  if (kk_yielding(kk_context())) {
    kk_box_t _x6547 = kk_std_core_hnd_yield_extend(kk_std_num_double_new_pdecdouble_fun6548(_ctx), _ctx); /*2*/
    _x6544 = kk_integer_unbox(_x6547); /*int*/
  }
  else {
    _x6544 = kk_std_num_double__mlift5656_pdecdouble(x4_5730, _ctx); /*int*/
  }
  return kk_integer_box(_x6544);
}


// lift anonymous function
struct kk_std_num_double_pdecdouble_fun6552__t {
  struct kk_function_s _base;
  kk_std_core__sslice x_5713;
};
static kk_box_t kk_std_num_double_pdecdouble_fun6552(kk_function_t _fself, kk_box_t _b_5951, kk_context_t* _ctx);
static kk_function_t kk_std_num_double_new_pdecdouble_fun6552(kk_std_core__sslice x_5713, kk_context_t* _ctx) {
  struct kk_std_num_double_pdecdouble_fun6552__t* _self = kk_function_alloc_as(struct kk_std_num_double_pdecdouble_fun6552__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_num_double_pdecdouble_fun6552, kk_context());
  _self->x_5713 = x_5713;
  return &_self->_base;
}

static kk_box_t kk_std_num_double_pdecdouble_fun6552(kk_function_t _fself, kk_box_t _b_5951, kk_context_t* _ctx) {
  struct kk_std_num_double_pdecdouble_fun6552__t* _self = kk_function_as(struct kk_std_num_double_pdecdouble_fun6552__t*, _fself);
  kk_std_core__sslice x_5713 = _self->x_5713; /* sslice */
  kk_drop_match(_self, {kk_std_core__sslice_dup(x_5713);}, {}, _ctx)
  double _x6553;
  kk_integer_t _x6554 = kk_integer_unbox(_b_5951); /*int*/
  _x6553 = kk_std_num_double__mlift5657_pdecdouble(x_5713, _x6554, _ctx); /*double*/
  return kk_double_box(_x6553, _ctx);
}


// lift anonymous function
struct kk_std_num_double_pdecdouble_fun6556__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_double_pdecdouble_fun6556(kk_function_t _fself, kk_box_t _b_5954, kk_context_t* _ctx);
static kk_function_t kk_std_num_double_new_pdecdouble_fun6556(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_double_pdecdouble_fun6556, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_double_pdecdouble_fun6556(kk_function_t _fself, kk_box_t _b_5954, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x6557;
  kk_string_t _x6558 = kk_string_unbox(_b_5954); /*string*/
  _x6557 = kk_std_num_double_prim_parse_double(_x6558, _ctx); /*double*/
  return kk_double_box(_x6557, _ctx);
}

double kk_std_num_double_pdecdouble(kk_context_t* _ctx) { /* () -> std/text/parse/parse double */ 
  kk_std_core__sslice x_5713 = kk_std_text_parse_current_input(_ctx); /*sslice*/;
  if (kk_yielding(kk_context())) {
    kk_std_core__sslice_drop(x_5713, _ctx);
    kk_box_t _x6518 = kk_std_core_hnd_yield_extend(kk_std_num_double_new_pdecdouble_fun6519(_ctx), _ctx); /*2*/
    return kk_double_unbox(_x6518, _ctx);
  }
  kk_string_t x0_5717 = kk_std_text_parse_digits(_ctx); /*string*/;
  kk_string_drop(x0_5717, _ctx);
  if (kk_yielding(kk_context())) {
    kk_box_t _x6522 = kk_std_core_hnd_yield_extend(kk_std_num_double_new_pdecdouble_fun6523(x_5713, _ctx), _ctx); /*2*/
    return kk_double_unbox(_x6522, _ctx);
  }
  kk_string_t x1_5721;
  kk_box_t _x6526;
  kk_box_t _x6527;
  kk_string_t _x6528 = kk_string_empty(); /*string*/
  _x6527 = kk_string_box(_x6528); /*0*/
  _x6526 = kk_std_text_parse_optional(_x6527, kk_std_num_double_new_pdecdouble_fun6530(_ctx), _ctx); /*0*/
  x1_5721 = kk_string_unbox(_x6526); /*string*/
  if (kk_yielding(kk_context())) {
    kk_string_drop(x1_5721, _ctx);
    kk_box_t _x6536 = kk_std_core_hnd_yield_extend(kk_std_num_double_new_pdecdouble_fun6537(x_5713, _ctx), _ctx); /*2*/
    return kk_double_unbox(_x6536, _ctx);
  }
  kk_string_t frac;
  kk_string_t _x6540;
  kk_define_string_literal(, _s6541, 1, "0")
  _x6540 = kk_string_dup(_s6541); /*string*/
  frac = kk_std_core_trim_right_1(x1_5721, _x6540, _ctx); /*string*/
  kk_string_drop(frac, _ctx);
  kk_integer_t x3_5727;
  kk_box_t _x6542 = kk_std_text_parse_optional(kk_integer_box(kk_integer_from_small(0)), kk_std_num_double_new_pdecdouble_fun6543(_ctx), _ctx); /*0*/
  x3_5727 = kk_integer_unbox(_x6542); /*int*/
  kk_integer_drop(x3_5727, _ctx);
  if (kk_yielding(kk_context())) {
    kk_box_t _x6551 = kk_std_core_hnd_yield_extend(kk_std_num_double_new_pdecdouble_fun6552(x_5713, _ctx), _ctx); /*2*/
    return kk_double_unbox(_x6551, _ctx);
  }
  kk_string_t _x1 = kk_std_core_string_3(x_5713, _ctx); /*string*/;
  kk_box_t _x6555 = kk_std_core_hnd__open_none1(kk_std_num_double_new_pdecdouble_fun6556(_ctx), kk_string_box(_x1), _ctx); /*2*/
  return kk_double_unbox(_x6555, _ctx);
}
 
// monadic lift

kk_integer_t kk_std_num_double__mlift5662_phexdouble(kk_char_t wild__2, kk_context_t* _ctx) { /* (wild_2 : char) -> std/text/parse/parse int */ 
  return kk_std_text_parse_pint(_ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_num_double__mlift5663_phexdouble_fun6568__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_double__mlift5663_phexdouble_fun6568(kk_function_t _fself, kk_box_t _b_5971, kk_box_t _b_5972, kk_context_t* _ctx);
static kk_function_t kk_std_num_double__new_mlift5663_phexdouble_fun6568(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_double__mlift5663_phexdouble_fun6568, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_double__mlift5663_phexdouble_fun6568(kk_function_t _fself, kk_box_t _b_5971, kk_box_t _b_5972, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x6569;
  kk_integer_t _x6570 = kk_integer_unbox(_b_5971); /*int*/
  kk_integer_t _x6571 = kk_integer_unbox(_b_5972); /*int*/
  _x6569 = kk_std_num_double_encode(_x6570, _x6571, _ctx); /*double*/
  return kk_double_box(_x6569, _ctx);
}

double kk_std_num_double__mlift5663_phexdouble(kk_string_t frac, kk_string_t man, kk_integer_t exp, kk_context_t* _ctx) { /* (frac : string, man : string, exp : int) -> std/text/parse/parse double */ 
  kk_integer_t m0;
  kk_std_core_types__maybe m_5733;
  kk_string_t s_5735;
  kk_string_t _x6559 = kk_string_dup(frac); /*string*/
  s_5735 = kk_std_core__lp__plus__plus__1_rp_(man, _x6559, _ctx); /*string*/
  kk_std_core_types__optional hex_5736 = kk_std_core_types__new_Optional(kk_bool_box(true), _ctx); /*optional<bool>*/;
  kk_string_t _x6560 = kk_std_core_trim(s_5735, _ctx); /*string*/
  bool _x6561;
  if (kk_std_core_types__is_Optional(hex_5736)) {
    kk_box_t _box_x5966 = hex_5736._cons.Optional.value;
    bool _hex_19366 = kk_bool_unbox(_box_x5966);
    kk_std_core_types__optional_drop(hex_5736, _ctx);
    _x6561 = _hex_19366; /*bool*/
    goto _match6562;
  }
  _x6561 = false; /*bool*/
  _match6562: ;
  m_5733 = kk_std_core_xparse_int(_x6560, _x6561, _ctx); /*maybe<int>*/
  if (kk_std_core_types__is_Nothing(m_5733)) {
    m0 = kk_integer_from_small(0); /*int*/
  }
  else {
    kk_box_t _box_x5967 = m_5733._cons.Just.value;
    kk_integer_t x = kk_integer_unbox(_box_x5967);
    kk_integer_dup(x);
    kk_std_core_types__maybe_drop(m_5733, _ctx);
    m0 = x; /*int*/
  }
  kk_integer_t e;
  kk_integer_t _x6565;
  kk_integer_t _x6566 = kk_std_core_count_1(frac, _ctx); /*int*/
  _x6565 = kk_integer_mul((kk_integer_from_small(4)),_x6566,kk_context()); /*int*/
  e = kk_integer_sub(exp,_x6565,kk_context()); /*int*/
  kk_box_t _x6567 = kk_std_core_hnd__open_none2(kk_std_num_double__new_mlift5663_phexdouble_fun6568(_ctx), kk_integer_box(m0), kk_integer_box(e), _ctx); /*3*/
  return kk_double_unbox(_x6567, _ctx);
}
 
// monadic lift

kk_string_t kk_std_num_double__mlift5664_phexdouble(kk_char_t wild__1, kk_context_t* _ctx) { /* (wild_1 : char) -> std/text/parse/parse string */ 
  return kk_std_text_parse_hex_digits(_ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_num_double__mlift5665_phexdouble_fun6575__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_double__mlift5665_phexdouble_fun6575(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_double__new_mlift5665_phexdouble_fun6575(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_double__mlift5665_phexdouble_fun6575, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_std_num_double__mlift5665_phexdouble_fun6580__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_double__mlift5665_phexdouble_fun6580(kk_function_t _fself, kk_box_t _b_5977, kk_context_t* _ctx);
static kk_function_t kk_std_num_double__new_mlift5665_phexdouble_fun6580(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_double__mlift5665_phexdouble_fun6580, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_double__mlift5665_phexdouble_fun6580(kk_function_t _fself, kk_box_t _b_5977, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_integer_t _x6581;
  kk_char_t _x6582 = kk_char_unbox(_b_5977, _ctx); /*char*/
  _x6581 = kk_std_num_double__mlift5662_phexdouble(_x6582, _ctx); /*int*/
  return kk_integer_box(_x6581);
}
static kk_box_t kk_std_num_double__mlift5665_phexdouble_fun6575(kk_function_t _fself, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_integer_t _x6576;
  kk_char_t x0_5739;
  kk_string_t _x6577;
  kk_define_string_literal(, _s6578, 2, "pP")
  _x6577 = kk_string_dup(_s6578); /*string*/
  x0_5739 = kk_std_text_parse_one_of(_x6577, _ctx); /*char*/
  if (kk_yielding(kk_context())) {
    kk_box_t _x6579 = kk_std_core_hnd_yield_extend(kk_std_num_double__new_mlift5665_phexdouble_fun6580(_ctx), _ctx); /*2*/
    _x6576 = kk_integer_unbox(_x6579); /*int*/
  }
  else {
    _x6576 = kk_std_num_double__mlift5662_phexdouble(x0_5739, _ctx); /*int*/
  }
  return kk_integer_box(_x6576);
}


// lift anonymous function
struct kk_std_num_double__mlift5665_phexdouble_fun6584__t {
  struct kk_function_s _base;
  kk_string_t frac;
  kk_string_t man;
};
static kk_box_t kk_std_num_double__mlift5665_phexdouble_fun6584(kk_function_t _fself, kk_box_t _b_5984, kk_context_t* _ctx);
static kk_function_t kk_std_num_double__new_mlift5665_phexdouble_fun6584(kk_string_t frac, kk_string_t man, kk_context_t* _ctx) {
  struct kk_std_num_double__mlift5665_phexdouble_fun6584__t* _self = kk_function_alloc_as(struct kk_std_num_double__mlift5665_phexdouble_fun6584__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_num_double__mlift5665_phexdouble_fun6584, kk_context());
  _self->frac = frac;
  _self->man = man;
  return &_self->_base;
}

static kk_box_t kk_std_num_double__mlift5665_phexdouble_fun6584(kk_function_t _fself, kk_box_t _b_5984, kk_context_t* _ctx) {
  struct kk_std_num_double__mlift5665_phexdouble_fun6584__t* _self = kk_function_as(struct kk_std_num_double__mlift5665_phexdouble_fun6584__t*, _fself);
  kk_string_t frac = _self->frac; /* string */
  kk_string_t man = _self->man; /* string */
  kk_drop_match(_self, {kk_string_dup(frac);kk_string_dup(man);}, {}, _ctx)
  double _x6585;
  kk_integer_t _x6586 = kk_integer_unbox(_b_5984); /*int*/
  _x6585 = kk_std_num_double__mlift5663_phexdouble(frac, man, _x6586, _ctx); /*double*/
  return kk_double_box(_x6585, _ctx);
}

double kk_std_num_double__mlift5665_phexdouble(kk_string_t man, kk_string_t _y_13, kk_context_t* _ctx) { /* (man : string, string) -> std/text/parse/parse double */ 
  kk_string_t frac;
  kk_string_t _x6572;
  kk_define_string_literal(, _s6573, 1, "0")
  _x6572 = kk_string_dup(_s6573); /*string*/
  frac = kk_std_core_trim_right_1(_y_13, _x6572, _ctx); /*string*/
  kk_integer_t x_5737;
  kk_box_t _x6574 = kk_std_text_parse_optional(kk_integer_box(kk_integer_from_small(0)), kk_std_num_double__new_mlift5665_phexdouble_fun6575(_ctx), _ctx); /*0*/
  x_5737 = kk_integer_unbox(_x6574); /*int*/
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_5737, _ctx);
    kk_box_t _x6583 = kk_std_core_hnd_yield_extend(kk_std_num_double__new_mlift5665_phexdouble_fun6584(frac, man, _ctx), _ctx); /*2*/
    return kk_double_unbox(_x6583, _ctx);
  }
  return kk_std_num_double__mlift5663_phexdouble(frac, man, x_5737, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_num_double__mlift5666_phexdouble_fun6591__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_double__mlift5666_phexdouble_fun6591(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_double__new_mlift5666_phexdouble_fun6591(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_double__mlift5666_phexdouble_fun6591, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_std_num_double__mlift5666_phexdouble_fun6594__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_double__mlift5666_phexdouble_fun6594(kk_function_t _fself, kk_box_t _b_5988, kk_context_t* _ctx);
static kk_function_t kk_std_num_double__new_mlift5666_phexdouble_fun6594(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_double__mlift5666_phexdouble_fun6594, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_double__mlift5666_phexdouble_fun6594(kk_function_t _fself, kk_box_t _b_5988, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x6595;
  kk_char_t _x6596 = kk_char_unbox(_b_5988, _ctx); /*char*/
  _x6595 = kk_std_num_double__mlift5664_phexdouble(_x6596, _ctx); /*string*/
  return kk_string_box(_x6595);
}
static kk_box_t kk_std_num_double__mlift5666_phexdouble_fun6591(kk_function_t _fself, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x6592;
  kk_char_t x0_5743 = kk_std_text_parse_char('.', _ctx); /*char*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x6593 = kk_std_core_hnd_yield_extend(kk_std_num_double__new_mlift5666_phexdouble_fun6594(_ctx), _ctx); /*2*/
    _x6592 = kk_string_unbox(_x6593); /*string*/
  }
  else {
    _x6592 = kk_std_num_double__mlift5664_phexdouble(x0_5743, _ctx); /*string*/
  }
  return kk_string_box(_x6592);
}


// lift anonymous function
struct kk_std_num_double__mlift5666_phexdouble_fun6598__t {
  struct kk_function_s _base;
  kk_string_t man;
};
static kk_box_t kk_std_num_double__mlift5666_phexdouble_fun6598(kk_function_t _fself, kk_box_t _b_5995, kk_context_t* _ctx);
static kk_function_t kk_std_num_double__new_mlift5666_phexdouble_fun6598(kk_string_t man, kk_context_t* _ctx) {
  struct kk_std_num_double__mlift5666_phexdouble_fun6598__t* _self = kk_function_alloc_as(struct kk_std_num_double__mlift5666_phexdouble_fun6598__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_num_double__mlift5666_phexdouble_fun6598, kk_context());
  _self->man = man;
  return &_self->_base;
}

static kk_box_t kk_std_num_double__mlift5666_phexdouble_fun6598(kk_function_t _fself, kk_box_t _b_5995, kk_context_t* _ctx) {
  struct kk_std_num_double__mlift5666_phexdouble_fun6598__t* _self = kk_function_as(struct kk_std_num_double__mlift5666_phexdouble_fun6598__t*, _fself);
  kk_string_t man = _self->man; /* string */
  kk_drop_match(_self, {kk_string_dup(man);}, {}, _ctx)
  double _x6599;
  kk_string_t _x6600 = kk_string_unbox(_b_5995); /*string*/
  _x6599 = kk_std_num_double__mlift5665_phexdouble(man, _x6600, _ctx); /*double*/
  return kk_double_box(_x6599, _ctx);
}

double kk_std_num_double__mlift5666_phexdouble(kk_string_t man, kk_context_t* _ctx) { /* (man : string) -> std/text/parse/parse double */ 
  kk_string_t x_5741;
  kk_box_t _x6587;
  kk_box_t _x6588;
  kk_string_t _x6589 = kk_string_empty(); /*string*/
  _x6588 = kk_string_box(_x6589); /*0*/
  _x6587 = kk_std_text_parse_optional(_x6588, kk_std_num_double__new_mlift5666_phexdouble_fun6591(_ctx), _ctx); /*0*/
  x_5741 = kk_string_unbox(_x6587); /*string*/
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_5741, _ctx);
    kk_box_t _x6597 = kk_std_core_hnd_yield_extend(kk_std_num_double__new_mlift5666_phexdouble_fun6598(man, _ctx), _ctx); /*2*/
    return kk_double_unbox(_x6597, _ctx);
  }
  return kk_std_num_double__mlift5665_phexdouble(man, x_5741, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_num_double__mlift5667_phexdouble_fun6602__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_double__mlift5667_phexdouble_fun6602(kk_function_t _fself, kk_box_t _b_5999, kk_context_t* _ctx);
static kk_function_t kk_std_num_double__new_mlift5667_phexdouble_fun6602(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_double__mlift5667_phexdouble_fun6602, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_double__mlift5667_phexdouble_fun6602(kk_function_t _fself, kk_box_t _b_5999, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x6603;
  kk_string_t _x6604 = kk_string_unbox(_b_5999); /*string*/
  _x6603 = kk_std_num_double__mlift5666_phexdouble(_x6604, _ctx); /*double*/
  return kk_double_box(_x6603, _ctx);
}

double kk_std_num_double__mlift5667_phexdouble(kk_char_t wild__0, kk_context_t* _ctx) { /* (wild_0 : char) -> std/text/parse/parse double */ 
  kk_string_t x_5745 = kk_std_text_parse_hex_digits(_ctx); /*string*/;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_5745, _ctx);
    kk_box_t _x6601 = kk_std_core_hnd_yield_extend(kk_std_num_double__new_mlift5667_phexdouble_fun6602(_ctx), _ctx); /*2*/
    return kk_double_unbox(_x6601, _ctx);
  }
  return kk_std_num_double__mlift5666_phexdouble(x_5745, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_num_double__mlift5668_phexdouble_fun6608__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_double__mlift5668_phexdouble_fun6608(kk_function_t _fself, kk_box_t _b_6002, kk_context_t* _ctx);
static kk_function_t kk_std_num_double__new_mlift5668_phexdouble_fun6608(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_double__mlift5668_phexdouble_fun6608, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_double__mlift5668_phexdouble_fun6608(kk_function_t _fself, kk_box_t _b_6002, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x6609;
  kk_char_t _x6610 = kk_char_unbox(_b_6002, _ctx); /*char*/
  _x6609 = kk_std_num_double__mlift5667_phexdouble(_x6610, _ctx); /*double*/
  return kk_double_box(_x6609, _ctx);
}

double kk_std_num_double__mlift5668_phexdouble(kk_char_t wild__, kk_context_t* _ctx) { /* (wild_ : char) -> std/text/parse/parse double */ 
  kk_char_t x_5747;
  kk_string_t _x6605;
  kk_define_string_literal(, _s6606, 2, "xX")
  _x6605 = kk_string_dup(_s6606); /*string*/
  x_5747 = kk_std_text_parse_one_of(_x6605, _ctx); /*char*/
  if (kk_yielding(kk_context())) {
    kk_box_t _x6607 = kk_std_core_hnd_yield_extend(kk_std_num_double__new_mlift5668_phexdouble_fun6608(_ctx), _ctx); /*2*/
    return kk_double_unbox(_x6607, _ctx);
  }
  return kk_std_num_double__mlift5667_phexdouble(x_5747, _ctx);
}


// lift anonymous function
struct kk_std_num_double_phexdouble_fun6612__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_double_phexdouble_fun6612(kk_function_t _fself, kk_box_t _b_6005, kk_context_t* _ctx);
static kk_function_t kk_std_num_double_new_phexdouble_fun6612(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_double_phexdouble_fun6612, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_double_phexdouble_fun6612(kk_function_t _fself, kk_box_t _b_6005, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x6613;
  kk_char_t _x6614 = kk_char_unbox(_b_6005, _ctx); /*char*/
  _x6613 = kk_std_num_double__mlift5668_phexdouble(_x6614, _ctx); /*double*/
  return kk_double_box(_x6613, _ctx);
}


// lift anonymous function
struct kk_std_num_double_phexdouble_fun6618__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_double_phexdouble_fun6618(kk_function_t _fself, kk_box_t _b_6007, kk_context_t* _ctx);
static kk_function_t kk_std_num_double_new_phexdouble_fun6618(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_double_phexdouble_fun6618, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_double_phexdouble_fun6618(kk_function_t _fself, kk_box_t _b_6007, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x6619;
  kk_char_t _x6620 = kk_char_unbox(_b_6007, _ctx); /*char*/
  _x6619 = kk_std_num_double__mlift5667_phexdouble(_x6620, _ctx); /*double*/
  return kk_double_box(_x6619, _ctx);
}


// lift anonymous function
struct kk_std_num_double_phexdouble_fun6622__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_double_phexdouble_fun6622(kk_function_t _fself, kk_box_t _b_6009, kk_context_t* _ctx);
static kk_function_t kk_std_num_double_new_phexdouble_fun6622(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_double_phexdouble_fun6622, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_double_phexdouble_fun6622(kk_function_t _fself, kk_box_t _b_6009, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x6623;
  kk_string_t _x6624 = kk_string_unbox(_b_6009); /*string*/
  _x6623 = kk_std_num_double__mlift5666_phexdouble(_x6624, _ctx); /*double*/
  return kk_double_box(_x6623, _ctx);
}


// lift anonymous function
struct kk_std_num_double_phexdouble_fun6629__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_double_phexdouble_fun6629(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_double_new_phexdouble_fun6629(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_double_phexdouble_fun6629, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_std_num_double_phexdouble_fun6632__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_double_phexdouble_fun6632(kk_function_t _fself, kk_box_t _b_6011, kk_context_t* _ctx);
static kk_function_t kk_std_num_double_new_phexdouble_fun6632(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_double_phexdouble_fun6632, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_double_phexdouble_fun6632(kk_function_t _fself, kk_box_t _b_6011, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x6633;
  kk_char_t _x6634 = kk_char_unbox(_b_6011, _ctx); /*char*/
  _x6633 = kk_std_num_double__mlift5664_phexdouble(_x6634, _ctx); /*string*/
  return kk_string_box(_x6633);
}
static kk_box_t kk_std_num_double_phexdouble_fun6629(kk_function_t _fself, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x6630;
  kk_char_t x3_5764 = kk_std_text_parse_char('.', _ctx); /*char*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x6631 = kk_std_core_hnd_yield_extend(kk_std_num_double_new_phexdouble_fun6632(_ctx), _ctx); /*2*/
    _x6630 = kk_string_unbox(_x6631); /*string*/
  }
  else {
    _x6630 = kk_std_num_double__mlift5664_phexdouble(x3_5764, _ctx); /*string*/
  }
  return kk_string_box(_x6630);
}


// lift anonymous function
struct kk_std_num_double_phexdouble_fun6636__t {
  struct kk_function_s _base;
  kk_string_t x1_5757;
};
static kk_box_t kk_std_num_double_phexdouble_fun6636(kk_function_t _fself, kk_box_t _b_6018, kk_context_t* _ctx);
static kk_function_t kk_std_num_double_new_phexdouble_fun6636(kk_string_t x1_5757, kk_context_t* _ctx) {
  struct kk_std_num_double_phexdouble_fun6636__t* _self = kk_function_alloc_as(struct kk_std_num_double_phexdouble_fun6636__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_num_double_phexdouble_fun6636, kk_context());
  _self->x1_5757 = x1_5757;
  return &_self->_base;
}

static kk_box_t kk_std_num_double_phexdouble_fun6636(kk_function_t _fself, kk_box_t _b_6018, kk_context_t* _ctx) {
  struct kk_std_num_double_phexdouble_fun6636__t* _self = kk_function_as(struct kk_std_num_double_phexdouble_fun6636__t*, _fself);
  kk_string_t x1_5757 = _self->x1_5757; /* string */
  kk_drop_match(_self, {kk_string_dup(x1_5757);}, {}, _ctx)
  double _x6637;
  kk_string_t _x6638 = kk_string_unbox(_b_6018); /*string*/
  _x6637 = kk_std_num_double__mlift5665_phexdouble(x1_5757, _x6638, _ctx); /*double*/
  return kk_double_box(_x6637, _ctx);
}


// lift anonymous function
struct kk_std_num_double_phexdouble_fun6642__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_double_phexdouble_fun6642(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_double_new_phexdouble_fun6642(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_double_phexdouble_fun6642, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_std_num_double_phexdouble_fun6647__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_double_phexdouble_fun6647(kk_function_t _fself, kk_box_t _b_6020, kk_context_t* _ctx);
static kk_function_t kk_std_num_double_new_phexdouble_fun6647(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_double_phexdouble_fun6647, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_double_phexdouble_fun6647(kk_function_t _fself, kk_box_t _b_6020, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_integer_t _x6648;
  kk_char_t _x6649 = kk_char_unbox(_b_6020, _ctx); /*char*/
  _x6648 = kk_std_num_double__mlift5662_phexdouble(_x6649, _ctx); /*int*/
  return kk_integer_box(_x6648);
}
static kk_box_t kk_std_num_double_phexdouble_fun6642(kk_function_t _fself, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_integer_t _x6643;
  kk_char_t x5_5770;
  kk_string_t _x6644;
  kk_define_string_literal(, _s6645, 2, "pP")
  _x6644 = kk_string_dup(_s6645); /*string*/
  x5_5770 = kk_std_text_parse_one_of(_x6644, _ctx); /*char*/
  if (kk_yielding(kk_context())) {
    kk_box_t _x6646 = kk_std_core_hnd_yield_extend(kk_std_num_double_new_phexdouble_fun6647(_ctx), _ctx); /*2*/
    _x6643 = kk_integer_unbox(_x6646); /*int*/
  }
  else {
    _x6643 = kk_std_num_double__mlift5662_phexdouble(x5_5770, _ctx); /*int*/
  }
  return kk_integer_box(_x6643);
}


// lift anonymous function
struct kk_std_num_double_phexdouble_fun6651__t {
  struct kk_function_s _base;
  kk_string_t frac;
  kk_string_t x1_5757;
};
static kk_box_t kk_std_num_double_phexdouble_fun6651(kk_function_t _fself, kk_box_t _b_6027, kk_context_t* _ctx);
static kk_function_t kk_std_num_double_new_phexdouble_fun6651(kk_string_t frac, kk_string_t x1_5757, kk_context_t* _ctx) {
  struct kk_std_num_double_phexdouble_fun6651__t* _self = kk_function_alloc_as(struct kk_std_num_double_phexdouble_fun6651__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_num_double_phexdouble_fun6651, kk_context());
  _self->frac = frac;
  _self->x1_5757 = x1_5757;
  return &_self->_base;
}

static kk_box_t kk_std_num_double_phexdouble_fun6651(kk_function_t _fself, kk_box_t _b_6027, kk_context_t* _ctx) {
  struct kk_std_num_double_phexdouble_fun6651__t* _self = kk_function_as(struct kk_std_num_double_phexdouble_fun6651__t*, _fself);
  kk_string_t frac = _self->frac; /* string */
  kk_string_t x1_5757 = _self->x1_5757; /* string */
  kk_drop_match(_self, {kk_string_dup(frac);kk_string_dup(x1_5757);}, {}, _ctx)
  double _x6652;
  kk_integer_t _x6653 = kk_integer_unbox(_b_6027); /*int*/
  _x6652 = kk_std_num_double__mlift5663_phexdouble(frac, x1_5757, _x6653, _ctx); /*double*/
  return kk_double_box(_x6652, _ctx);
}


// lift anonymous function
struct kk_std_num_double_phexdouble_fun6663__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_double_phexdouble_fun6663(kk_function_t _fself, kk_box_t _b_6035, kk_box_t _b_6036, kk_context_t* _ctx);
static kk_function_t kk_std_num_double_new_phexdouble_fun6663(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_double_phexdouble_fun6663, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_double_phexdouble_fun6663(kk_function_t _fself, kk_box_t _b_6035, kk_box_t _b_6036, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x6664;
  kk_integer_t _x6665 = kk_integer_unbox(_b_6035); /*int*/
  kk_integer_t _x6666 = kk_integer_unbox(_b_6036); /*int*/
  _x6664 = kk_std_num_double_encode(_x6665, _x6666, _ctx); /*double*/
  return kk_double_box(_x6664, _ctx);
}

double kk_std_num_double_phexdouble(kk_context_t* _ctx) { /* () -> std/text/parse/parse double */ 
  kk_char_t x_5749 = kk_std_text_parse_char('0', _ctx); /*char*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x6611 = kk_std_core_hnd_yield_extend(kk_std_num_double_new_phexdouble_fun6612(_ctx), _ctx); /*2*/
    return kk_double_unbox(_x6611, _ctx);
  }
  kk_char_t x0_5753;
  kk_string_t _x6615;
  kk_define_string_literal(, _s6616, 2, "xX")
  _x6615 = kk_string_dup(_s6616); /*string*/
  x0_5753 = kk_std_text_parse_one_of(_x6615, _ctx); /*char*/
  if (kk_yielding(kk_context())) {
    kk_box_t _x6617 = kk_std_core_hnd_yield_extend(kk_std_num_double_new_phexdouble_fun6618(_ctx), _ctx); /*2*/
    return kk_double_unbox(_x6617, _ctx);
  }
  kk_string_t x1_5757 = kk_std_text_parse_hex_digits(_ctx); /*string*/;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x1_5757, _ctx);
    kk_box_t _x6621 = kk_std_core_hnd_yield_extend(kk_std_num_double_new_phexdouble_fun6622(_ctx), _ctx); /*2*/
    return kk_double_unbox(_x6621, _ctx);
  }
  kk_string_t x2_5761;
  kk_box_t _x6625;
  kk_box_t _x6626;
  kk_string_t _x6627 = kk_string_empty(); /*string*/
  _x6626 = kk_string_box(_x6627); /*0*/
  _x6625 = kk_std_text_parse_optional(_x6626, kk_std_num_double_new_phexdouble_fun6629(_ctx), _ctx); /*0*/
  x2_5761 = kk_string_unbox(_x6625); /*string*/
  if (kk_yielding(kk_context())) {
    kk_string_drop(x2_5761, _ctx);
    kk_box_t _x6635 = kk_std_core_hnd_yield_extend(kk_std_num_double_new_phexdouble_fun6636(x1_5757, _ctx), _ctx); /*2*/
    return kk_double_unbox(_x6635, _ctx);
  }
  kk_string_t frac;
  kk_string_t _x6639;
  kk_define_string_literal(, _s6640, 1, "0")
  _x6639 = kk_string_dup(_s6640); /*string*/
  frac = kk_std_core_trim_right_1(x2_5761, _x6639, _ctx); /*string*/
  kk_integer_t x4_5767;
  kk_box_t _x6641 = kk_std_text_parse_optional(kk_integer_box(kk_integer_from_small(0)), kk_std_num_double_new_phexdouble_fun6642(_ctx), _ctx); /*0*/
  x4_5767 = kk_integer_unbox(_x6641); /*int*/
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x4_5767, _ctx);
    kk_box_t _x6650 = kk_std_core_hnd_yield_extend(kk_std_num_double_new_phexdouble_fun6651(frac, x1_5757, _ctx), _ctx); /*2*/
    return kk_double_unbox(_x6650, _ctx);
  }
  kk_integer_t m0;
  kk_std_core_types__maybe m_5773;
  kk_string_t s_5775;
  kk_string_t _x6654 = kk_string_dup(frac); /*string*/
  s_5775 = kk_std_core__lp__plus__plus__1_rp_(x1_5757, _x6654, _ctx); /*string*/
  kk_std_core_types__optional hex_5776 = kk_std_core_types__new_Optional(kk_bool_box(true), _ctx); /*optional<bool>*/;
  kk_string_t _x6655 = kk_std_core_trim(s_5775, _ctx); /*string*/
  bool _x6656;
  if (kk_std_core_types__is_Optional(hex_5776)) {
    kk_box_t _box_x6030 = hex_5776._cons.Optional.value;
    bool _hex_19366 = kk_bool_unbox(_box_x6030);
    kk_std_core_types__optional_drop(hex_5776, _ctx);
    _x6656 = _hex_19366; /*bool*/
    goto _match6657;
  }
  _x6656 = false; /*bool*/
  _match6657: ;
  m_5773 = kk_std_core_xparse_int(_x6655, _x6656, _ctx); /*maybe<int>*/
  if (kk_std_core_types__is_Nothing(m_5773)) {
    m0 = kk_integer_from_small(0); /*int*/
  }
  else {
    kk_box_t _box_x6031 = m_5773._cons.Just.value;
    kk_integer_t x6 = kk_integer_unbox(_box_x6031);
    kk_integer_dup(x6);
    kk_std_core_types__maybe_drop(m_5773, _ctx);
    m0 = x6; /*int*/
  }
  kk_integer_t e;
  kk_integer_t _x6660;
  kk_integer_t _x6661 = kk_std_core_count_1(frac, _ctx); /*int*/
  _x6660 = kk_integer_mul((kk_integer_from_small(4)),_x6661,kk_context()); /*int*/
  e = kk_integer_sub(x4_5767,_x6660,kk_context()); /*int*/
  kk_box_t _x6662 = kk_std_core_hnd__open_none2(kk_std_num_double_new_phexdouble_fun6663(_ctx), kk_integer_box(m0), kk_integer_box(e), _ctx); /*3*/
  return kk_double_unbox(_x6662, _ctx);
}
 
// monadic lift

double kk_std_num_double__mlift5669_pspecial(kk_string_t wild__, kk_context_t* _ctx) { /* (wild_ : string) -> std/text/parse/parse double */ 
  kk_string_drop(wild__, _ctx);
  return kk_std_num_double_make_nan(_ctx);
}
 
// monadic lift

double kk_std_num_double__mlift5670_pspecial(kk_string_t wild__0, kk_context_t* _ctx) { /* (wild_0 : string) -> std/text/parse/parse double */ 
  kk_string_drop(wild__0, _ctx);
  return kk_std_num_double_make_posinf(_ctx);
}
 
// monadic lift

double kk_std_num_double__mlift5671_pspecial(kk_string_t wild__1, kk_context_t* _ctx) { /* (wild_1 : string) -> std/text/parse/parse double */ 
  kk_string_drop(wild__1, _ctx);
  return kk_std_num_double_make_posinf(_ctx);
}


// lift anonymous function
struct kk_std_num_double_pspecial_fun6667__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_double_pspecial_fun6667(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_double_new_pspecial_fun6667(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_double_pspecial_fun6667, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_std_num_double_pspecial_fun6672__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_double_pspecial_fun6672(kk_function_t _fself, kk_box_t _b_6052, kk_context_t* _ctx);
static kk_function_t kk_std_num_double_new_pspecial_fun6672(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_double_pspecial_fun6672, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_double_pspecial_fun6672(kk_function_t _fself, kk_box_t _b_6052, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x6673;
  kk_string_t _x6674 = kk_string_unbox(_b_6052); /*string*/
  _x6673 = kk_std_num_double__mlift5671_pspecial(_x6674, _ctx); /*double*/
  return kk_double_box(_x6673, _ctx);
}
static kk_box_t kk_std_num_double_pspecial_fun6667(kk_function_t _fself, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x6668;
  kk_string_t x1_5781;
  kk_string_t _x6669;
  kk_define_string_literal(, _s6670, 3, "inf")
  _x6669 = kk_string_dup(_s6670); /*string*/
  x1_5781 = kk_std_text_parse_pstring(_x6669, _ctx); /*string*/
  if (kk_yielding(kk_context())) {
    kk_string_drop(x1_5781, _ctx);
    kk_box_t _x6671 = kk_std_core_hnd_yield_extend(kk_std_num_double_new_pspecial_fun6672(_ctx), _ctx); /*2*/
    _x6668 = kk_double_unbox(_x6671, _ctx); /*double*/
  }
  else {
    _x6668 = kk_std_num_double__mlift5671_pspecial(x1_5781, _ctx); /*double*/
  }
  return kk_double_box(_x6668, _ctx);
}


// lift anonymous function
struct kk_std_num_double_pspecial_fun6675__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_double_pspecial_fun6675(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_double_new_pspecial_fun6675(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_double_pspecial_fun6675, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_std_num_double_pspecial_fun6680__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_double_pspecial_fun6680(kk_function_t _fself, kk_box_t _b_6050, kk_context_t* _ctx);
static kk_function_t kk_std_num_double_new_pspecial_fun6680(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_double_pspecial_fun6680, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_double_pspecial_fun6680(kk_function_t _fself, kk_box_t _b_6050, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x6681;
  kk_string_t _x6682 = kk_string_unbox(_b_6050); /*string*/
  _x6681 = kk_std_num_double__mlift5670_pspecial(_x6682, _ctx); /*double*/
  return kk_double_box(_x6681, _ctx);
}
static kk_box_t kk_std_num_double_pspecial_fun6675(kk_function_t _fself, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x6676;
  kk_string_t x0_5779;
  kk_string_t _x6677;
  kk_define_string_literal(, _s6678, 8, "infinity")
  _x6677 = kk_string_dup(_s6678); /*string*/
  x0_5779 = kk_std_text_parse_pstring(_x6677, _ctx); /*string*/
  if (kk_yielding(kk_context())) {
    kk_string_drop(x0_5779, _ctx);
    kk_box_t _x6679 = kk_std_core_hnd_yield_extend(kk_std_num_double_new_pspecial_fun6680(_ctx), _ctx); /*2*/
    _x6676 = kk_double_unbox(_x6679, _ctx); /*double*/
  }
  else {
    _x6676 = kk_std_num_double__mlift5670_pspecial(x0_5779, _ctx); /*double*/
  }
  return kk_double_box(_x6676, _ctx);
}


// lift anonymous function
struct kk_std_num_double_pspecial_fun6683__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_double_pspecial_fun6683(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_double_new_pspecial_fun6683(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_double_pspecial_fun6683, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_std_num_double_pspecial_fun6688__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_double_pspecial_fun6688(kk_function_t _fself, kk_box_t _b_6048, kk_context_t* _ctx);
static kk_function_t kk_std_num_double_new_pspecial_fun6688(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_double_pspecial_fun6688, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_double_pspecial_fun6688(kk_function_t _fself, kk_box_t _b_6048, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x6689;
  kk_string_t _x6690 = kk_string_unbox(_b_6048); /*string*/
  _x6689 = kk_std_num_double__mlift5669_pspecial(_x6690, _ctx); /*double*/
  return kk_double_box(_x6689, _ctx);
}
static kk_box_t kk_std_num_double_pspecial_fun6683(kk_function_t _fself, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x6684;
  kk_string_t x_5777;
  kk_string_t _x6685;
  kk_define_string_literal(, _s6686, 3, "nan")
  _x6685 = kk_string_dup(_s6686); /*string*/
  x_5777 = kk_std_text_parse_pstring(_x6685, _ctx); /*string*/
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_5777, _ctx);
    kk_box_t _x6687 = kk_std_core_hnd_yield_extend(kk_std_num_double_new_pspecial_fun6688(_ctx), _ctx); /*2*/
    _x6684 = kk_double_unbox(_x6687, _ctx); /*double*/
  }
  else {
    _x6684 = kk_std_num_double__mlift5669_pspecial(x_5777, _ctx); /*double*/
  }
  return kk_double_box(_x6684, _ctx);
}

double kk_std_num_double_pspecial(kk_context_t* _ctx) { /* () -> std/text/parse/parse double */ 
  kk_std_core__list _b_6063_6062;
  kk_std_core__list _b_6065_6060;
  kk_std_core__list _b_6067_6057 = kk_std_core__new_Cons(kk_reuse_null, kk_function_box(kk_std_num_double_new_pspecial_fun6667(_ctx)), kk_std_core__new_Nil(_ctx), _ctx); /*list<() -> std/text/parse/parse double>*/;
  _b_6065_6060 = kk_std_core__new_Cons(kk_reuse_null, kk_function_box(kk_std_num_double_new_pspecial_fun6675(_ctx)), _b_6067_6057, _ctx); /*list<() -> std/text/parse/parse double>*/
  _b_6063_6062 = kk_std_core__new_Cons(kk_reuse_null, kk_function_box(kk_std_num_double_new_pspecial_fun6683(_ctx)), _b_6065_6060, _ctx); /*list<() -> std/text/parse/parse double>*/
  kk_box_t _x6691 = kk_std_text_parse_choose(_b_6063_6062, _ctx); /*0*/
  return kk_double_unbox(_x6691, _ctx);
}
 
// monadic lift

double kk_std_num_double__mlift5672_pdouble(bool neg, double d, kk_context_t* _ctx) { /* (neg : bool, d : double) -> std/text/parse/parse double */ 
  if (neg) {
    return (-d);
  }
  return d;
}
 
// monadic lift


// lift anonymous function
struct kk_std_num_double__mlift5673_pdouble_fun6692__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_double__mlift5673_pdouble_fun6692(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_double__new_mlift5673_pdouble_fun6692(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_double__mlift5673_pdouble_fun6692, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_double__mlift5673_pdouble_fun6692(kk_function_t _fself, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return kk_double_box(0x0p+0, _ctx);
}


// lift anonymous function
struct kk_std_num_double__mlift5673_pdouble_fun6693__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_double__mlift5673_pdouble_fun6693(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_double__new_mlift5673_pdouble_fun6693(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_double__mlift5673_pdouble_fun6693, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_std_num_double__mlift5673_pdouble_fun6695__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_double__mlift5673_pdouble_fun6695(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_double__new_mlift5673_pdouble_fun6695(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_double__mlift5673_pdouble_fun6695, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_std_num_double__mlift5673_pdouble_fun6700__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_double__mlift5673_pdouble_fun6700(kk_function_t _fself, kk_box_t _b_6078, kk_context_t* _ctx);
static kk_function_t kk_std_num_double__new_mlift5673_pdouble_fun6700(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_double__mlift5673_pdouble_fun6700, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_double__mlift5673_pdouble_fun6700(kk_function_t _fself, kk_box_t _b_6078, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x6701;
  kk_string_t _x6702 = kk_string_unbox(_b_6078); /*string*/
  _x6701 = kk_std_num_double__mlift5671_pspecial(_x6702, _ctx); /*double*/
  return kk_double_box(_x6701, _ctx);
}
static kk_box_t kk_std_num_double__mlift5673_pdouble_fun6695(kk_function_t _fself, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x6696;
  kk_string_t x1_5781;
  kk_string_t _x6697;
  kk_define_string_literal(, _s6698, 3, "inf")
  _x6697 = kk_string_dup(_s6698); /*string*/
  x1_5781 = kk_std_text_parse_pstring(_x6697, _ctx); /*string*/
  if (kk_yielding(kk_context())) {
    kk_string_drop(x1_5781, _ctx);
    kk_box_t _x6699 = kk_std_core_hnd_yield_extend(kk_std_num_double__new_mlift5673_pdouble_fun6700(_ctx), _ctx); /*2*/
    _x6696 = kk_double_unbox(_x6699, _ctx); /*double*/
  }
  else {
    _x6696 = kk_std_num_double__mlift5671_pspecial(x1_5781, _ctx); /*double*/
  }
  return kk_double_box(_x6696, _ctx);
}


// lift anonymous function
struct kk_std_num_double__mlift5673_pdouble_fun6703__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_double__mlift5673_pdouble_fun6703(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_double__new_mlift5673_pdouble_fun6703(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_double__mlift5673_pdouble_fun6703, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_std_num_double__mlift5673_pdouble_fun6708__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_double__mlift5673_pdouble_fun6708(kk_function_t _fself, kk_box_t _b_6076, kk_context_t* _ctx);
static kk_function_t kk_std_num_double__new_mlift5673_pdouble_fun6708(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_double__mlift5673_pdouble_fun6708, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_double__mlift5673_pdouble_fun6708(kk_function_t _fself, kk_box_t _b_6076, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x6709;
  kk_string_t _x6710 = kk_string_unbox(_b_6076); /*string*/
  _x6709 = kk_std_num_double__mlift5670_pspecial(_x6710, _ctx); /*double*/
  return kk_double_box(_x6709, _ctx);
}
static kk_box_t kk_std_num_double__mlift5673_pdouble_fun6703(kk_function_t _fself, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x6704;
  kk_string_t x0_5779;
  kk_string_t _x6705;
  kk_define_string_literal(, _s6706, 8, "infinity")
  _x6705 = kk_string_dup(_s6706); /*string*/
  x0_5779 = kk_std_text_parse_pstring(_x6705, _ctx); /*string*/
  if (kk_yielding(kk_context())) {
    kk_string_drop(x0_5779, _ctx);
    kk_box_t _x6707 = kk_std_core_hnd_yield_extend(kk_std_num_double__new_mlift5673_pdouble_fun6708(_ctx), _ctx); /*2*/
    _x6704 = kk_double_unbox(_x6707, _ctx); /*double*/
  }
  else {
    _x6704 = kk_std_num_double__mlift5670_pspecial(x0_5779, _ctx); /*double*/
  }
  return kk_double_box(_x6704, _ctx);
}


// lift anonymous function
struct kk_std_num_double__mlift5673_pdouble_fun6711__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_double__mlift5673_pdouble_fun6711(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_double__new_mlift5673_pdouble_fun6711(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_double__mlift5673_pdouble_fun6711, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_std_num_double__mlift5673_pdouble_fun6716__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_double__mlift5673_pdouble_fun6716(kk_function_t _fself, kk_box_t _b_6074, kk_context_t* _ctx);
static kk_function_t kk_std_num_double__new_mlift5673_pdouble_fun6716(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_double__mlift5673_pdouble_fun6716, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_double__mlift5673_pdouble_fun6716(kk_function_t _fself, kk_box_t _b_6074, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x6717;
  kk_string_t _x6718 = kk_string_unbox(_b_6074); /*string*/
  _x6717 = kk_std_num_double__mlift5669_pspecial(_x6718, _ctx); /*double*/
  return kk_double_box(_x6717, _ctx);
}
static kk_box_t kk_std_num_double__mlift5673_pdouble_fun6711(kk_function_t _fself, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x6712;
  kk_string_t x_5777;
  kk_string_t _x6713;
  kk_define_string_literal(, _s6714, 3, "nan")
  _x6713 = kk_string_dup(_s6714); /*string*/
  x_5777 = kk_std_text_parse_pstring(_x6713, _ctx); /*string*/
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_5777, _ctx);
    kk_box_t _x6715 = kk_std_core_hnd_yield_extend(kk_std_num_double__new_mlift5673_pdouble_fun6716(_ctx), _ctx); /*2*/
    _x6712 = kk_double_unbox(_x6715, _ctx); /*double*/
  }
  else {
    _x6712 = kk_std_num_double__mlift5669_pspecial(x_5777, _ctx); /*double*/
  }
  return kk_double_box(_x6712, _ctx);
}
static kk_box_t kk_std_num_double__mlift5673_pdouble_fun6693(kk_function_t _fself, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x6694;
  kk_std_core__list _b_6111_6088;
  kk_std_core__list _b_6113_6086;
  kk_std_core__list _b_6115_6083 = kk_std_core__new_Cons(kk_reuse_null, kk_function_box(kk_std_num_double__new_mlift5673_pdouble_fun6695(_ctx)), kk_std_core__new_Nil(_ctx), _ctx); /*list<() -> std/text/parse/parse double>*/;
  _b_6113_6086 = kk_std_core__new_Cons(kk_reuse_null, kk_function_box(kk_std_num_double__new_mlift5673_pdouble_fun6703(_ctx)), _b_6115_6083, _ctx); /*list<() -> std/text/parse/parse double>*/
  _b_6111_6088 = kk_std_core__new_Cons(kk_reuse_null, kk_function_box(kk_std_num_double__new_mlift5673_pdouble_fun6711(_ctx)), _b_6113_6086, _ctx); /*list<() -> std/text/parse/parse double>*/
  kk_box_t _x6719 = kk_std_text_parse_choose(_b_6111_6088, _ctx); /*0*/
  _x6694 = kk_double_unbox(_x6719, _ctx); /*double*/
  return kk_double_box(_x6694, _ctx);
}


// lift anonymous function
struct kk_std_num_double__mlift5673_pdouble_fun6720__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_double__mlift5673_pdouble_fun6720(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_double__new_mlift5673_pdouble_fun6720(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_double__mlift5673_pdouble_fun6720, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_double__mlift5673_pdouble_fun6720(kk_function_t _fself, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x6721 = kk_std_num_double_pdecdouble(_ctx); /*double*/
  return kk_double_box(_x6721, _ctx);
}


// lift anonymous function
struct kk_std_num_double__mlift5673_pdouble_fun6722__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_double__mlift5673_pdouble_fun6722(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_double__new_mlift5673_pdouble_fun6722(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_double__mlift5673_pdouble_fun6722, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_double__mlift5673_pdouble_fun6722(kk_function_t _fself, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x6723 = kk_std_num_double_phexdouble(_ctx); /*double*/
  return kk_double_box(_x6723, _ctx);
}


// lift anonymous function
struct kk_std_num_double__mlift5673_pdouble_fun6726__t {
  struct kk_function_s _base;
  bool neg;
};
static kk_box_t kk_std_num_double__mlift5673_pdouble_fun6726(kk_function_t _fself, kk_box_t _b_6122, kk_context_t* _ctx);
static kk_function_t kk_std_num_double__new_mlift5673_pdouble_fun6726(bool neg, kk_context_t* _ctx) {
  struct kk_std_num_double__mlift5673_pdouble_fun6726__t* _self = kk_function_alloc_as(struct kk_std_num_double__mlift5673_pdouble_fun6726__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_num_double__mlift5673_pdouble_fun6726, kk_context());
  _self->neg = neg;
  return &_self->_base;
}

static kk_box_t kk_std_num_double__mlift5673_pdouble_fun6726(kk_function_t _fself, kk_box_t _b_6122, kk_context_t* _ctx) {
  struct kk_std_num_double__mlift5673_pdouble_fun6726__t* _self = kk_function_as(struct kk_std_num_double__mlift5673_pdouble_fun6726__t*, _fself);
  bool neg = _self->neg; /* bool */
  kk_drop_match(_self, {;}, {}, _ctx)
  double _x6727;
  double _x6728 = kk_double_unbox(_b_6122, _ctx); /*double*/
  _x6727 = kk_std_num_double__mlift5672_pdouble(neg, _x6728, _ctx); /*double*/
  return kk_double_box(_x6727, _ctx);
}

double kk_std_num_double__mlift5673_pdouble(bool neg, kk_context_t* _ctx) { /* (neg : bool) -> std/text/parse/parse double */ 
  double x_5783;
  kk_std_core__list _b_6102_6101;
  kk_std_core__list _b_6104_6099;
  kk_std_core__list _b_6106_6096;
  kk_std_core__list _b_6108_6093 = kk_std_core__new_Cons(kk_reuse_null, kk_function_box(kk_std_num_double__new_mlift5673_pdouble_fun6692(_ctx)), kk_std_core__new_Nil(_ctx), _ctx); /*list<() -> std/text/parse/parse double>*/;
  _b_6106_6096 = kk_std_core__new_Cons(kk_reuse_null, kk_function_box(kk_std_num_double__new_mlift5673_pdouble_fun6693(_ctx)), _b_6108_6093, _ctx); /*list<() -> std/text/parse/parse double>*/
  _b_6104_6099 = kk_std_core__new_Cons(kk_reuse_null, kk_function_box(kk_std_num_double__new_mlift5673_pdouble_fun6720(_ctx)), _b_6106_6096, _ctx); /*list<() -> std/text/parse/parse double>*/
  _b_6102_6101 = kk_std_core__new_Cons(kk_reuse_null, kk_function_box(kk_std_num_double__new_mlift5673_pdouble_fun6722(_ctx)), _b_6104_6099, _ctx); /*list<() -> std/text/parse/parse double>*/
  kk_box_t _x6724 = kk_std_text_parse_choose(_b_6102_6101, _ctx); /*0*/
  x_5783 = kk_double_unbox(_x6724, _ctx); /*double*/
  if (kk_yielding(kk_context())) {
    kk_box_t _x6725 = kk_std_core_hnd_yield_extend(kk_std_num_double__new_mlift5673_pdouble_fun6726(neg, _ctx), _ctx); /*2*/
    return kk_double_unbox(_x6725, _ctx);
  }
  return kk_std_num_double__mlift5672_pdouble(neg, x_5783, _ctx);
}


// lift anonymous function
struct kk_std_num_double_pdouble_fun6730__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_double_pdouble_fun6730(kk_function_t _fself, kk_box_t _b_6126, kk_context_t* _ctx);
static kk_function_t kk_std_num_double_new_pdouble_fun6730(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_double_pdouble_fun6730, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_double_pdouble_fun6730(kk_function_t _fself, kk_box_t _b_6126, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x6731;
  bool _x6732 = kk_bool_unbox(_b_6126); /*bool*/
  _x6731 = kk_std_num_double__mlift5673_pdouble(_x6732, _ctx); /*double*/
  return kk_double_box(_x6731, _ctx);
}


// lift anonymous function
struct kk_std_num_double_pdouble_fun6733__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_double_pdouble_fun6733(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_double_new_pdouble_fun6733(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_double_pdouble_fun6733, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_double_pdouble_fun6733(kk_function_t _fself, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return kk_double_box(0x0p+0, _ctx);
}


// lift anonymous function
struct kk_std_num_double_pdouble_fun6734__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_double_pdouble_fun6734(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_double_new_pdouble_fun6734(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_double_pdouble_fun6734, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_std_num_double_pdouble_fun6736__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_double_pdouble_fun6736(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_double_new_pdouble_fun6736(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_double_pdouble_fun6736, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_std_num_double_pdouble_fun6741__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_double_pdouble_fun6741(kk_function_t _fself, kk_box_t _b_6132, kk_context_t* _ctx);
static kk_function_t kk_std_num_double_new_pdouble_fun6741(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_double_pdouble_fun6741, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_double_pdouble_fun6741(kk_function_t _fself, kk_box_t _b_6132, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x6742;
  kk_string_t _x6743 = kk_string_unbox(_b_6132); /*string*/
  _x6742 = kk_std_num_double__mlift5671_pspecial(_x6743, _ctx); /*double*/
  return kk_double_box(_x6742, _ctx);
}
static kk_box_t kk_std_num_double_pdouble_fun6736(kk_function_t _fself, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x6737;
  kk_string_t x1_5781;
  kk_string_t _x6738;
  kk_define_string_literal(, _s6739, 3, "inf")
  _x6738 = kk_string_dup(_s6739); /*string*/
  x1_5781 = kk_std_text_parse_pstring(_x6738, _ctx); /*string*/
  if (kk_yielding(kk_context())) {
    kk_string_drop(x1_5781, _ctx);
    kk_box_t _x6740 = kk_std_core_hnd_yield_extend(kk_std_num_double_new_pdouble_fun6741(_ctx), _ctx); /*2*/
    _x6737 = kk_double_unbox(_x6740, _ctx); /*double*/
  }
  else {
    _x6737 = kk_std_num_double__mlift5671_pspecial(x1_5781, _ctx); /*double*/
  }
  return kk_double_box(_x6737, _ctx);
}


// lift anonymous function
struct kk_std_num_double_pdouble_fun6744__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_double_pdouble_fun6744(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_double_new_pdouble_fun6744(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_double_pdouble_fun6744, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_std_num_double_pdouble_fun6749__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_double_pdouble_fun6749(kk_function_t _fself, kk_box_t _b_6130, kk_context_t* _ctx);
static kk_function_t kk_std_num_double_new_pdouble_fun6749(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_double_pdouble_fun6749, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_double_pdouble_fun6749(kk_function_t _fself, kk_box_t _b_6130, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x6750;
  kk_string_t _x6751 = kk_string_unbox(_b_6130); /*string*/
  _x6750 = kk_std_num_double__mlift5670_pspecial(_x6751, _ctx); /*double*/
  return kk_double_box(_x6750, _ctx);
}
static kk_box_t kk_std_num_double_pdouble_fun6744(kk_function_t _fself, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x6745;
  kk_string_t x0_5779;
  kk_string_t _x6746;
  kk_define_string_literal(, _s6747, 8, "infinity")
  _x6746 = kk_string_dup(_s6747); /*string*/
  x0_5779 = kk_std_text_parse_pstring(_x6746, _ctx); /*string*/
  if (kk_yielding(kk_context())) {
    kk_string_drop(x0_5779, _ctx);
    kk_box_t _x6748 = kk_std_core_hnd_yield_extend(kk_std_num_double_new_pdouble_fun6749(_ctx), _ctx); /*2*/
    _x6745 = kk_double_unbox(_x6748, _ctx); /*double*/
  }
  else {
    _x6745 = kk_std_num_double__mlift5670_pspecial(x0_5779, _ctx); /*double*/
  }
  return kk_double_box(_x6745, _ctx);
}


// lift anonymous function
struct kk_std_num_double_pdouble_fun6752__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_double_pdouble_fun6752(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_double_new_pdouble_fun6752(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_double_pdouble_fun6752, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_std_num_double_pdouble_fun6757__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_double_pdouble_fun6757(kk_function_t _fself, kk_box_t _b_6128, kk_context_t* _ctx);
static kk_function_t kk_std_num_double_new_pdouble_fun6757(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_double_pdouble_fun6757, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_double_pdouble_fun6757(kk_function_t _fself, kk_box_t _b_6128, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x6758;
  kk_string_t _x6759 = kk_string_unbox(_b_6128); /*string*/
  _x6758 = kk_std_num_double__mlift5669_pspecial(_x6759, _ctx); /*double*/
  return kk_double_box(_x6758, _ctx);
}
static kk_box_t kk_std_num_double_pdouble_fun6752(kk_function_t _fself, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x6753;
  kk_string_t x_5777;
  kk_string_t _x6754;
  kk_define_string_literal(, _s6755, 3, "nan")
  _x6754 = kk_string_dup(_s6755); /*string*/
  x_5777 = kk_std_text_parse_pstring(_x6754, _ctx); /*string*/
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_5777, _ctx);
    kk_box_t _x6756 = kk_std_core_hnd_yield_extend(kk_std_num_double_new_pdouble_fun6757(_ctx), _ctx); /*2*/
    _x6753 = kk_double_unbox(_x6756, _ctx); /*double*/
  }
  else {
    _x6753 = kk_std_num_double__mlift5669_pspecial(x_5777, _ctx); /*double*/
  }
  return kk_double_box(_x6753, _ctx);
}
static kk_box_t kk_std_num_double_pdouble_fun6734(kk_function_t _fself, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x6735;
  kk_std_core__list _b_6165_6142;
  kk_std_core__list _b_6167_6140;
  kk_std_core__list _b_6169_6137 = kk_std_core__new_Cons(kk_reuse_null, kk_function_box(kk_std_num_double_new_pdouble_fun6736(_ctx)), kk_std_core__new_Nil(_ctx), _ctx); /*list<() -> std/text/parse/parse double>*/;
  _b_6167_6140 = kk_std_core__new_Cons(kk_reuse_null, kk_function_box(kk_std_num_double_new_pdouble_fun6744(_ctx)), _b_6169_6137, _ctx); /*list<() -> std/text/parse/parse double>*/
  _b_6165_6142 = kk_std_core__new_Cons(kk_reuse_null, kk_function_box(kk_std_num_double_new_pdouble_fun6752(_ctx)), _b_6167_6140, _ctx); /*list<() -> std/text/parse/parse double>*/
  kk_box_t _x6760 = kk_std_text_parse_choose(_b_6165_6142, _ctx); /*0*/
  _x6735 = kk_double_unbox(_x6760, _ctx); /*double*/
  return kk_double_box(_x6735, _ctx);
}


// lift anonymous function
struct kk_std_num_double_pdouble_fun6761__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_double_pdouble_fun6761(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_double_new_pdouble_fun6761(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_double_pdouble_fun6761, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_double_pdouble_fun6761(kk_function_t _fself, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x6762 = kk_std_num_double_pdecdouble(_ctx); /*double*/
  return kk_double_box(_x6762, _ctx);
}


// lift anonymous function
struct kk_std_num_double_pdouble_fun6763__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_double_pdouble_fun6763(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_double_new_pdouble_fun6763(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_double_pdouble_fun6763, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_double_pdouble_fun6763(kk_function_t _fself, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x6764 = kk_std_num_double_phexdouble(_ctx); /*double*/
  return kk_double_box(_x6764, _ctx);
}


// lift anonymous function
struct kk_std_num_double_pdouble_fun6767__t {
  struct kk_function_s _base;
  bool x_5785;
};
static kk_box_t kk_std_num_double_pdouble_fun6767(kk_function_t _fself, kk_box_t _b_6176, kk_context_t* _ctx);
static kk_function_t kk_std_num_double_new_pdouble_fun6767(bool x_5785, kk_context_t* _ctx) {
  struct kk_std_num_double_pdouble_fun6767__t* _self = kk_function_alloc_as(struct kk_std_num_double_pdouble_fun6767__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_num_double_pdouble_fun6767, kk_context());
  _self->x_5785 = x_5785;
  return &_self->_base;
}

static kk_box_t kk_std_num_double_pdouble_fun6767(kk_function_t _fself, kk_box_t _b_6176, kk_context_t* _ctx) {
  struct kk_std_num_double_pdouble_fun6767__t* _self = kk_function_as(struct kk_std_num_double_pdouble_fun6767__t*, _fself);
  bool x_5785 = _self->x_5785; /* bool */
  kk_drop_match(_self, {;}, {}, _ctx)
  double _x6768;
  double _x6769 = kk_double_unbox(_b_6176, _ctx); /*double*/
  _x6768 = kk_std_num_double__mlift5672_pdouble(x_5785, _x6769, _ctx); /*double*/
  return kk_double_box(_x6768, _ctx);
}

double kk_std_num_double_pdouble(kk_context_t* _ctx) { /* () -> std/text/parse/parse double */ 
  bool x_5785 = kk_std_text_parse_sign(_ctx); /*bool*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x6729 = kk_std_core_hnd_yield_extend(kk_std_num_double_new_pdouble_fun6730(_ctx), _ctx); /*2*/
    return kk_double_unbox(_x6729, _ctx);
  }
  double x0_5789;
  kk_std_core__list _b_6156_6155;
  kk_std_core__list _b_6158_6153;
  kk_std_core__list _b_6160_6150;
  kk_std_core__list _b_6162_6147 = kk_std_core__new_Cons(kk_reuse_null, kk_function_box(kk_std_num_double_new_pdouble_fun6733(_ctx)), kk_std_core__new_Nil(_ctx), _ctx); /*list<() -> std/text/parse/parse double>*/;
  _b_6160_6150 = kk_std_core__new_Cons(kk_reuse_null, kk_function_box(kk_std_num_double_new_pdouble_fun6734(_ctx)), _b_6162_6147, _ctx); /*list<() -> std/text/parse/parse double>*/
  _b_6158_6153 = kk_std_core__new_Cons(kk_reuse_null, kk_function_box(kk_std_num_double_new_pdouble_fun6761(_ctx)), _b_6160_6150, _ctx); /*list<() -> std/text/parse/parse double>*/
  _b_6156_6155 = kk_std_core__new_Cons(kk_reuse_null, kk_function_box(kk_std_num_double_new_pdouble_fun6763(_ctx)), _b_6158_6153, _ctx); /*list<() -> std/text/parse/parse double>*/
  kk_box_t _x6765 = kk_std_text_parse_choose(_b_6156_6155, _ctx); /*0*/
  x0_5789 = kk_double_unbox(_x6765, _ctx); /*double*/
  if (kk_yielding(kk_context())) {
    kk_box_t _x6766 = kk_std_core_hnd_yield_extend(kk_std_num_double_new_pdouble_fun6767(x_5785, _ctx), _ctx); /*2*/
    return kk_double_unbox(_x6766, _ctx);
  }
  if (x_5785) {
    return (-x0_5789);
  }
  return x0_5789;
}
 
// Parse a double number. Can be "NaN", "Inf(inity)" (case-insensitive),
// a fix-point number (`1.2`) or in scientific notation (`-2.3e-5`).
// Also allows floats in [hexadecimal notation](https://books.google.com/books?id=FgMsCwAAQBAJ&pg=PA41) (`0xA.Fp-10`) that can
// be represented precisely (and are the preferred _round trip_ format).


// lift anonymous function
struct kk_std_num_double_parse_double_fun6774__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_double_parse_double_fun6774(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_double_new_parse_double_fun6774(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_double_parse_double_fun6774, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_std_num_double_parse_double_fun6777__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_double_parse_double_fun6777(kk_function_t _fself, kk_box_t _b_6181, kk_context_t* _ctx);
static kk_function_t kk_std_num_double_new_parse_double_fun6777(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_double_parse_double_fun6777, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_double_parse_double_fun6777(kk_function_t _fself, kk_box_t _b_6181, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x6778;
  bool _x6779 = kk_bool_unbox(_b_6181); /*bool*/
  _x6778 = kk_std_num_double__mlift5673_pdouble(_x6779, _ctx); /*double*/
  return kk_double_box(_x6778, _ctx);
}


// lift anonymous function
struct kk_std_num_double_parse_double_fun6780__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_double_parse_double_fun6780(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_double_new_parse_double_fun6780(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_double_parse_double_fun6780, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_double_parse_double_fun6780(kk_function_t _fself, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return kk_double_box(0x0p+0, _ctx);
}


// lift anonymous function
struct kk_std_num_double_parse_double_fun6781__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_double_parse_double_fun6781(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_double_new_parse_double_fun6781(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_double_parse_double_fun6781, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_std_num_double_parse_double_fun6783__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_double_parse_double_fun6783(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_double_new_parse_double_fun6783(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_double_parse_double_fun6783, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_std_num_double_parse_double_fun6788__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_double_parse_double_fun6788(kk_function_t _fself, kk_box_t _b_6187, kk_context_t* _ctx);
static kk_function_t kk_std_num_double_new_parse_double_fun6788(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_double_parse_double_fun6788, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_double_parse_double_fun6788(kk_function_t _fself, kk_box_t _b_6187, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x6789;
  kk_string_t _x6790 = kk_string_unbox(_b_6187); /*string*/
  _x6789 = kk_std_num_double__mlift5671_pspecial(_x6790, _ctx); /*double*/
  return kk_double_box(_x6789, _ctx);
}
static kk_box_t kk_std_num_double_parse_double_fun6783(kk_function_t _fself, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x6784;
  kk_string_t x1_5781;
  kk_string_t _x6785;
  kk_define_string_literal(, _s6786, 3, "inf")
  _x6785 = kk_string_dup(_s6786); /*string*/
  x1_5781 = kk_std_text_parse_pstring(_x6785, _ctx); /*string*/
  if (kk_yielding(kk_context())) {
    kk_string_drop(x1_5781, _ctx);
    kk_box_t _x6787 = kk_std_core_hnd_yield_extend(kk_std_num_double_new_parse_double_fun6788(_ctx), _ctx); /*2*/
    _x6784 = kk_double_unbox(_x6787, _ctx); /*double*/
  }
  else {
    _x6784 = kk_std_num_double__mlift5671_pspecial(x1_5781, _ctx); /*double*/
  }
  return kk_double_box(_x6784, _ctx);
}


// lift anonymous function
struct kk_std_num_double_parse_double_fun6791__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_double_parse_double_fun6791(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_double_new_parse_double_fun6791(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_double_parse_double_fun6791, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_std_num_double_parse_double_fun6796__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_double_parse_double_fun6796(kk_function_t _fself, kk_box_t _b_6185, kk_context_t* _ctx);
static kk_function_t kk_std_num_double_new_parse_double_fun6796(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_double_parse_double_fun6796, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_double_parse_double_fun6796(kk_function_t _fself, kk_box_t _b_6185, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x6797;
  kk_string_t _x6798 = kk_string_unbox(_b_6185); /*string*/
  _x6797 = kk_std_num_double__mlift5670_pspecial(_x6798, _ctx); /*double*/
  return kk_double_box(_x6797, _ctx);
}
static kk_box_t kk_std_num_double_parse_double_fun6791(kk_function_t _fself, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x6792;
  kk_string_t x0_5779;
  kk_string_t _x6793;
  kk_define_string_literal(, _s6794, 8, "infinity")
  _x6793 = kk_string_dup(_s6794); /*string*/
  x0_5779 = kk_std_text_parse_pstring(_x6793, _ctx); /*string*/
  if (kk_yielding(kk_context())) {
    kk_string_drop(x0_5779, _ctx);
    kk_box_t _x6795 = kk_std_core_hnd_yield_extend(kk_std_num_double_new_parse_double_fun6796(_ctx), _ctx); /*2*/
    _x6792 = kk_double_unbox(_x6795, _ctx); /*double*/
  }
  else {
    _x6792 = kk_std_num_double__mlift5670_pspecial(x0_5779, _ctx); /*double*/
  }
  return kk_double_box(_x6792, _ctx);
}


// lift anonymous function
struct kk_std_num_double_parse_double_fun6799__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_double_parse_double_fun6799(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_double_new_parse_double_fun6799(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_double_parse_double_fun6799, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_std_num_double_parse_double_fun6804__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_double_parse_double_fun6804(kk_function_t _fself, kk_box_t _b_6183, kk_context_t* _ctx);
static kk_function_t kk_std_num_double_new_parse_double_fun6804(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_double_parse_double_fun6804, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_double_parse_double_fun6804(kk_function_t _fself, kk_box_t _b_6183, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x6805;
  kk_string_t _x6806 = kk_string_unbox(_b_6183); /*string*/
  _x6805 = kk_std_num_double__mlift5669_pspecial(_x6806, _ctx); /*double*/
  return kk_double_box(_x6805, _ctx);
}
static kk_box_t kk_std_num_double_parse_double_fun6799(kk_function_t _fself, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x6800;
  kk_string_t x_5777;
  kk_string_t _x6801;
  kk_define_string_literal(, _s6802, 3, "nan")
  _x6801 = kk_string_dup(_s6802); /*string*/
  x_5777 = kk_std_text_parse_pstring(_x6801, _ctx); /*string*/
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_5777, _ctx);
    kk_box_t _x6803 = kk_std_core_hnd_yield_extend(kk_std_num_double_new_parse_double_fun6804(_ctx), _ctx); /*2*/
    _x6800 = kk_double_unbox(_x6803, _ctx); /*double*/
  }
  else {
    _x6800 = kk_std_num_double__mlift5669_pspecial(x_5777, _ctx); /*double*/
  }
  return kk_double_box(_x6800, _ctx);
}
static kk_box_t kk_std_num_double_parse_double_fun6781(kk_function_t _fself, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x6782;
  kk_std_core__list _b_6220_6197;
  kk_std_core__list _b_6222_6195;
  kk_std_core__list _b_6224_6192 = kk_std_core__new_Cons(kk_reuse_null, kk_function_box(kk_std_num_double_new_parse_double_fun6783(_ctx)), kk_std_core__new_Nil(_ctx), _ctx); /*list<() -> std/text/parse/parse double>*/;
  _b_6222_6195 = kk_std_core__new_Cons(kk_reuse_null, kk_function_box(kk_std_num_double_new_parse_double_fun6791(_ctx)), _b_6224_6192, _ctx); /*list<() -> std/text/parse/parse double>*/
  _b_6220_6197 = kk_std_core__new_Cons(kk_reuse_null, kk_function_box(kk_std_num_double_new_parse_double_fun6799(_ctx)), _b_6222_6195, _ctx); /*list<() -> std/text/parse/parse double>*/
  kk_box_t _x6807 = kk_std_text_parse_choose(_b_6220_6197, _ctx); /*0*/
  _x6782 = kk_double_unbox(_x6807, _ctx); /*double*/
  return kk_double_box(_x6782, _ctx);
}


// lift anonymous function
struct kk_std_num_double_parse_double_fun6808__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_double_parse_double_fun6808(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_double_new_parse_double_fun6808(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_double_parse_double_fun6808, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_double_parse_double_fun6808(kk_function_t _fself, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x6809 = kk_std_num_double_pdecdouble(_ctx); /*double*/
  return kk_double_box(_x6809, _ctx);
}


// lift anonymous function
struct kk_std_num_double_parse_double_fun6810__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_double_parse_double_fun6810(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_double_new_parse_double_fun6810(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_double_parse_double_fun6810, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_double_parse_double_fun6810(kk_function_t _fself, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x6811 = kk_std_num_double_phexdouble(_ctx); /*double*/
  return kk_double_box(_x6811, _ctx);
}


// lift anonymous function
struct kk_std_num_double_parse_double_fun6814__t {
  struct kk_function_s _base;
  bool x1_5797;
};
static kk_box_t kk_std_num_double_parse_double_fun6814(kk_function_t _fself, kk_box_t _b_6231, kk_context_t* _ctx);
static kk_function_t kk_std_num_double_new_parse_double_fun6814(bool x1_5797, kk_context_t* _ctx) {
  struct kk_std_num_double_parse_double_fun6814__t* _self = kk_function_alloc_as(struct kk_std_num_double_parse_double_fun6814__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_num_double_parse_double_fun6814, kk_context());
  _self->x1_5797 = x1_5797;
  return &_self->_base;
}

static kk_box_t kk_std_num_double_parse_double_fun6814(kk_function_t _fself, kk_box_t _b_6231, kk_context_t* _ctx) {
  struct kk_std_num_double_parse_double_fun6814__t* _self = kk_function_as(struct kk_std_num_double_parse_double_fun6814__t*, _fself);
  bool x1_5797 = _self->x1_5797; /* bool */
  kk_drop_match(_self, {;}, {}, _ctx)
  double _x6815;
  double _x6816 = kk_double_unbox(_b_6231, _ctx); /*double*/
  _x6815 = kk_std_num_double__mlift5672_pdouble(x1_5797, _x6816, _ctx); /*double*/
  return kk_double_box(_x6815, _ctx);
}


// lift anonymous function
struct kk_std_num_double_parse_double_fun6819__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_double_parse_double_fun6819(kk_function_t _fself, kk_box_t _x16818, kk_context_t* _ctx);
static kk_function_t kk_std_num_double_new_parse_double_fun6819(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_double_parse_double_fun6819, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_double_parse_double_fun6819(kk_function_t _fself, kk_box_t _x16818, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return kk_std_text_parse__mlift2565_parse_eof(_x16818, _ctx);
}
static kk_box_t kk_std_num_double_parse_double_fun6774(kk_function_t _fself, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x6775;
  double x_2790;
  bool x1_5797 = kk_std_text_parse_sign(_ctx); /*bool*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x6776 = kk_std_core_hnd_yield_extend(kk_std_num_double_new_parse_double_fun6777(_ctx), _ctx); /*2*/
    x_2790 = kk_double_unbox(_x6776, _ctx); /*double*/
  }
  else {
    double x2_5801;
    kk_std_core__list _b_6211_6210;
    kk_std_core__list _b_6213_6208;
    kk_std_core__list _b_6215_6205;
    kk_std_core__list _b_6217_6202 = kk_std_core__new_Cons(kk_reuse_null, kk_function_box(kk_std_num_double_new_parse_double_fun6780(_ctx)), kk_std_core__new_Nil(_ctx), _ctx); /*list<() -> std/text/parse/parse double>*/;
    _b_6215_6205 = kk_std_core__new_Cons(kk_reuse_null, kk_function_box(kk_std_num_double_new_parse_double_fun6781(_ctx)), _b_6217_6202, _ctx); /*list<() -> std/text/parse/parse double>*/
    _b_6213_6208 = kk_std_core__new_Cons(kk_reuse_null, kk_function_box(kk_std_num_double_new_parse_double_fun6808(_ctx)), _b_6215_6205, _ctx); /*list<() -> std/text/parse/parse double>*/
    _b_6211_6210 = kk_std_core__new_Cons(kk_reuse_null, kk_function_box(kk_std_num_double_new_parse_double_fun6810(_ctx)), _b_6213_6208, _ctx); /*list<() -> std/text/parse/parse double>*/
    kk_box_t _x6812 = kk_std_text_parse_choose(_b_6211_6210, _ctx); /*0*/
    x2_5801 = kk_double_unbox(_x6812, _ctx); /*double*/
    if (kk_yielding(kk_context())) {
      kk_box_t _x6813 = kk_std_core_hnd_yield_extend(kk_std_num_double_new_parse_double_fun6814(x1_5797, _ctx), _ctx); /*2*/
      x_2790 = kk_double_unbox(_x6813, _ctx); /*double*/
    }
    else {
      if (x1_5797) {
        x_2790 = (-x2_5801); /*double*/
      }
      else {
        x_2790 = x2_5801; /*double*/
      }
    }
  }
  kk_box_t _x6817;
  if (kk_yielding(kk_context())) {
    _x6817 = kk_std_core_hnd_yield_extend(kk_std_num_double_new_parse_double_fun6819(_ctx), _ctx); /*2*/
  }
  else {
    _x6817 = kk_std_text_parse__mlift2565_parse_eof(kk_double_box(x_2790, _ctx), _ctx); /*2*/
  }
  _x6775 = kk_double_unbox(_x6817, _ctx); /*double*/
  return kk_double_box(_x6775, _ctx);
}

kk_std_core_types__maybe kk_std_num_double_parse_double(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> maybe<double> */ 
  kk_std_text_parse__parse_error perr_5793;
  kk_std_core__sslice input_5794;
  kk_string_t s0_5796;
  kk_string_t _x6770 = kk_std_core_trim(s, _ctx); /*string*/
  s0_5796 = kk_std_core_to_lower(_x6770, _ctx); /*string*/
  kk_string_t _x6771 = kk_string_dup(s0_5796); /*string*/
  size_t _x6772 = ((size_t)0); /*size_t*/
  size_t _x6773 = kk_string_len(s0_5796,kk_context()); /*size_t*/
  input_5794 = kk_std_core__new_Sslice(_x6771, _x6772, _x6773, _ctx); /*sslice*/
  perr_5793 = kk_std_text_parse_parse(input_5794, kk_std_num_double_new_parse_double_fun6774(_ctx), _ctx); /*std/text/parse/parse-error<double>*/
  kk_std_core_types__either e_2721 = kk_std_text_parse_either(perr_5793, _ctx); /*either<string,double>*/;
  if (kk_std_core_types__is_Left(e_2721)) {
    kk_box_t _box_x6247 = e_2721._cons.Left.left;
    kk_std_core_types__either_drop(e_2721, _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
  kk_box_t _box_x6248 = e_2721._cons.Right.right;
  double x = kk_double_unbox(_box_x6248, NULL);
  kk_std_core_types__either_drop(e_2721, _ctx);
  return kk_std_core_types__new_Just(kk_double_box(x, _ctx), _ctx);
}
 
// Round a double to a specified precision. Rounds to the  even number in case of a tie.
// `123.456.round-to-prec(2) == 123.46`
// `123.456.round-to-prec(-1) == 120.0`

double kk_std_num_double_round_to_prec(double d, kk_integer_t prec, kk_context_t* _ctx) { /* (d : double, prec : int) -> double */ 
  bool _match_6273;
  kk_integer_t _x6823 = kk_integer_dup(prec); /*int*/
  _match_6273 = kk_integer_lte(_x6823,(kk_integer_from_small(0)),kk_context()); /*bool*/
  if (_match_6273) {
    kk_integer_drop(prec, _ctx);
    return round(d);
  }
  double p0;
  double p_5805 = kk_integer_as_double(prec,kk_context()); /*double*/;
  p0 = pow((0x1.4p3),p_5805); /*double*/
  double _x6824;
  double _x6825 = (d * p0); /*double*/
  _x6824 = round(_x6825); /*double*/
  return (_x6824 / p0);
}
 
/* Show a double in [hexadecimal notation](https://books.google.com/books?id=FgMsCwAAQBAJ&pg=PA41).
An advantage of this format is that it precisely represents the `:double` and can
reliably (and efficiently) be parsed back, i.e. `d.show-hex.parse-double == Just(d)`.
The significant is the _hexadecimal_ fraction while the
exponent after the `p` is the _decimal_ power of 2.
 For example, ``0xA.Fp-10`` = (10 + 15/16)&middot;2^-10^  (not 2^-16^!) = 0.01068115234375.
 Equivalently, ``0xA.Fp-10 == 0x5.78p-9 == 0x2.BCp-8 == 0x1.5Ep-7``.
```
> dbl-min.show-hex
"0x1.0p-1022"
> 0.1.show-hex
"0x1.999999999999Ap-4"
> dbl-max.show-hex
"0x1.FFFFFFFFFFFFFp+1023"
> -0.0.show-hex
"-0x0.0p+0"
> nan.show-hex
"NaN"
> 0.01068115234375.show-hex
"0x1.5Ep-7"
```
.
*/

kk_string_t kk_std_num_double_show_hex(double d, kk_std_core_types__optional width, kk_std_core_types__optional use_capitals, kk_std_core_types__optional pre, kk_context_t* _ctx) { /* (d : double, width : optional<int>, use-capitals : optional<bool>, pre : optional<string>) -> string */ 
  bool _match_6266;
  bool _x6826 = isfinite(d); /*bool*/
  _match_6266 = !(_x6826); /*bool*/
  if (_match_6266) {
    kk_std_core_types__optional_drop(pre, _ctx);
    kk_std_core_types__optional_drop(use_capitals, _ctx);
    kk_std_core_types__optional_drop(width, _ctx);
    return kk_std_core_show_1(d, kk_std_core_types__new_None(_ctx), _ctx);
  }
  kk_std_core_types__tuple2_ _match_6267 = kk_std_num_double_decode(d, _ctx); /*(int, int)*/;
  kk_box_t _box_x6251 = _match_6267.fst;
  kk_box_t _box_x6252 = _match_6267.snd;
  kk_integer_t m = kk_integer_unbox(_box_x6251);
  kk_integer_t e = kk_integer_unbox(_box_x6252);
  kk_integer_dup(e);
  kk_integer_dup(m);
  kk_std_core_types__tuple2__drop(_match_6267, _ctx);
  kk_string_t man;
  kk_integer_t _x6829 = kk_integer_abs(m,kk_context()); /*int*/
  kk_std_core_types__optional _x6830 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(1)), _ctx); /*optional<35>*/
  kk_std_core_types__optional _x6831;
  kk_box_t _x6832;
  bool _x6833;
  if (kk_std_core_types__is_Optional(use_capitals)) {
    kk_box_t _box_x6254 = use_capitals._cons.Optional.value;
    bool _use_capitals_5038 = kk_bool_unbox(_box_x6254);
    kk_std_core_types__optional_drop(use_capitals, _ctx);
    _x6833 = _use_capitals_5038; /*bool*/
    goto _match6834;
  }
  _x6833 = true; /*bool*/
  _match6834: ;
  _x6832 = kk_bool_box(_x6833); /*35*/
  _x6831 = kk_std_core_types__new_Optional(_x6832, _ctx); /*optional<35>*/
  kk_std_core_types__optional _x6836;
  kk_box_t _x6837;
  kk_string_t _x6838 = kk_string_empty(); /*string*/
  _x6837 = kk_string_box(_x6838); /*35*/
  _x6836 = kk_std_core_types__new_Optional(_x6837, _ctx); /*optional<35>*/
  man = kk_std_core_show_hex(_x6829, _x6830, _x6831, _x6836, _ctx); /*string*/
  kk_integer_t exp0;
  kk_integer_t _x6840;
  kk_integer_t _x6841;
  kk_integer_t _x6842;
  kk_string_t _x6843 = kk_string_dup(man); /*string*/
  _x6842 = kk_std_core_count_1(_x6843, _ctx); /*int*/
  _x6841 = kk_integer_sub(_x6842,(kk_integer_from_small(1)),kk_context()); /*int*/
  _x6840 = kk_integer_mul((kk_integer_from_small(4)),_x6841,kk_context()); /*int*/
  exp0 = kk_integer_add(e,_x6840,kk_context()); /*int*/
  kk_string_t exp;
  kk_string_t _x6844;
  bool _match_6272;
  kk_integer_t _x6845 = kk_integer_dup(exp0); /*int*/
  _match_6272 = kk_integer_gte(_x6845,(kk_integer_from_small(0)),kk_context()); /*bool*/
  if (_match_6272) {
    kk_define_string_literal(, _s6846, 1, "+")
    _x6844 = kk_string_dup(_s6846); /*string*/
  }
  else {
    _x6844 = kk_string_empty(); /*string*/
  }
  kk_string_t _x6848 = kk_std_core_show(exp0, _ctx); /*string*/
  exp = kk_std_core__lp__plus__plus__1_rp_(_x6844, _x6848, _ctx); /*string*/
  kk_string_t frac;
  kk_string_t s_5806;
  kk_string_t _x6849;
  kk_string_t _x6850 = kk_string_dup(man); /*string*/
  _x6849 = kk_std_core_tail_2(_x6850, _ctx); /*string*/
  kk_string_t _x6851;
  kk_define_string_literal(, _s6852, 1, "0")
  _x6851 = kk_string_dup(_s6852); /*string*/
  s_5806 = kk_std_core_trim_right_1(_x6849, _x6851, _ctx); /*string*/
  kk_integer_t width0_5807;
  bool _match_6271;
  kk_integer_t _x6853;
  if (kk_std_core_types__is_Optional(width)) {
    kk_box_t _box_x6260 = width._cons.Optional.value;
    kk_integer_t _width_5034 = kk_integer_unbox(_box_x6260);
    kk_integer_dup(_width_5034);
    _x6853 = _width_5034; /*int*/
    goto _match6854;
  }
  _x6853 = kk_integer_from_small(1); /*int*/
  _match6854: ;
  _match_6271 = kk_integer_gte((kk_integer_from_small(1)),_x6853,kk_context()); /*bool*/
  if (_match_6271) {
    kk_std_core_types__optional_drop(width, _ctx);
    width0_5807 = kk_integer_from_small(1); /*int*/
  }
  else {
    if (kk_std_core_types__is_Optional(width)) {
      kk_box_t _box_x6261 = width._cons.Optional.value;
      kk_integer_t _width_50340 = kk_integer_unbox(_box_x6261);
      kk_integer_dup(_width_50340);
      kk_std_core_types__optional_drop(width, _ctx);
      width0_5807 = _width_50340; /*int*/
      goto _match6856;
    }
    width0_5807 = kk_integer_from_small(1); /*int*/
    _match6856: ;
  }
  kk_std_core_types__optional fill_5808 = kk_std_core_types__new_Optional(kk_char_box('0', _ctx), _ctx); /*optional<char>*/;
  size_t w = kk_std_core_size__t(width0_5807, _ctx); /*size_t*/;
  size_t n;
  kk_string_t _x6858 = kk_string_dup(s_5806); /*string*/
  n = kk_string_len(_x6858,kk_context()); /*size_t*/
  bool _match_6270 = (w <= n); /*bool*/;
  if (_match_6270) {
    kk_std_core_types__optional_drop(fill_5808, _ctx);
    frac = s_5806; /*string*/
  }
  else {
    kk_string_t _x6859;
    kk_string_t _x6860;
    kk_char_t _x6861;
    if (kk_std_core_types__is_Optional(fill_5808)) {
      kk_box_t _box_x6264 = fill_5808._cons.Optional.value;
      kk_char_t _fill_18968 = kk_char_unbox(_box_x6264, NULL);
      kk_std_core_types__optional_drop(fill_5808, _ctx);
      _x6861 = _fill_18968; /*char*/
      goto _match6862;
    }
    _x6861 = ' '; /*char*/
    _match6862: ;
    _x6860 = kk_std_core_string(_x6861, _ctx); /*string*/
    size_t _x6864 = (w - n); /*size_t*/
    _x6859 = kk_std_core_repeatz(_x6860, _x6864, _ctx); /*string*/
    frac = kk_std_core__lp__plus__plus__1_rp_(s_5806, _x6859, _ctx); /*string*/
  }
  kk_string_t sign;
  bool _match_6268;
  bool _match_6269 = kk_std_core_is_neg_3(d, _ctx); /*bool*/;
  if (_match_6269) {
    _match_6268 = true; /*bool*/
  }
  else {
    _match_6268 = kk_std_num_double_is_negzero(d, _ctx); /*bool*/
  }
  if (_match_6268) {
    kk_define_string_literal(, _s6865, 1, "-")
    sign = kk_string_dup(_s6865); /*string*/
  }
  else {
    sign = kk_string_empty(); /*string*/
  }
  kk_string_t _x6867;
  kk_string_t _x6868;
  if (kk_std_core_types__is_Optional(pre)) {
    kk_box_t _box_x6265 = pre._cons.Optional.value;
    kk_string_t _pre_5042 = kk_string_unbox(_box_x6265);
    kk_string_dup(_pre_5042);
    kk_std_core_types__optional_drop(pre, _ctx);
    _x6868 = _pre_5042; /*string*/
    goto _match6869;
  }
  kk_define_string_literal(, _s6871, 2, "0x")
  _x6868 = kk_string_dup(_s6871); /*string*/
  _match6869: ;
  kk_string_t _x6872;
  kk_string_t _x6873 = kk_std_core_head_3(man, _ctx); /*string*/
  kk_string_t _x6874;
  kk_string_t _x6875;
  kk_define_string_literal(, _s6876, 1, ".")
  _x6875 = kk_string_dup(_s6876); /*string*/
  kk_string_t _x6877;
  kk_string_t _x6878;
  kk_string_t _x6879;
  kk_define_string_literal(, _s6880, 1, "p")
  _x6879 = kk_string_dup(_s6880); /*string*/
  _x6878 = kk_std_core__lp__plus__plus__1_rp_(_x6879, exp, _ctx); /*string*/
  _x6877 = kk_std_core__lp__plus__plus__1_rp_(frac, _x6878, _ctx); /*string*/
  _x6874 = kk_std_core__lp__plus__plus__1_rp_(_x6875, _x6877, _ctx); /*string*/
  _x6872 = kk_std_core__lp__plus__plus__1_rp_(_x6873, _x6874, _ctx); /*string*/
  _x6867 = kk_std_core__lp__plus__plus__1_rp_(_x6868, _x6872, _ctx); /*string*/
  return kk_std_core__lp__plus__plus__1_rp_(sign, _x6867, _ctx);
}

// initialization
void kk_std_num_double__init(kk_context_t* _ctx){
  static bool _initialized = false;
  if (_initialized) return;
  _initialized = true;
  kk_std_core_types__init(_ctx);
  kk_std_core_hnd__init(_ctx);
  kk_std_core__init(_ctx);
  kk_std_text_parse__init(_ctx);
  kk_std_num_int32__init(_ctx);
  {
    kk_std_num_double_dbl_max_prec = kk_integer_from_small(15); /*int*/
  }
  {
    kk_std_num_double_rad2deg = ((0x1.68p7) / (0x1.921fb54442d18p1)); /*double*/
  }
  {
    kk_std_num_double_deg2rad = ((0x1.921fb54442d18p1) / (0x1.68p7)); /*double*/
  }
  {
    kk_std_num_double_neginf = kk_std_num_double_make_neginf(_ctx); /*double*/
  }
  {
    kk_std_num_double_posinf = kk_std_num_double_make_posinf(_ctx); /*double*/
  }
  {
    kk_std_num_double_nan = kk_std_num_double_make_nan(_ctx); /*double*/
  }
}
