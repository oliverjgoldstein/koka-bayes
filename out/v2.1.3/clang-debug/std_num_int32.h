#pragma once
#ifndef kk_std_num_int32_H
#define kk_std_num_int32_H
// Koka generated module: "std/num/int32", koka version: 2.1.3
#include <kklib.h>
#include "std_core_types.h"
#include "std_core_hnd.h"
#include "std_core.h"

// type declarations

// value declarations

static inline kk_std_core_types__order kk_std_num_int32_compare(int32_t x, int32_t y, kk_context_t* _ctx) { /* (x : int32, y : int32) -> order */ 
  bool _match_2120 = (x < y); /*bool*/;
  if (_match_2120) {
    return kk_std_core_types__new_Lt(_ctx);
  }
  bool _match_2121 = (x > y); /*bool*/;
  if (_match_2121) {
    return kk_std_core_types__new_Gt(_ctx);
  }
  return kk_std_core_types__new_Eq(_ctx);
}
 
// Return the maximum of two integers

static inline int32_t kk_std_num_int32_max(int32_t i, int32_t j, kk_context_t* _ctx) { /* (i : int32, j : int32) -> int32 */ 
  bool _match_2119 = (i >= j); /*bool*/;
  if (_match_2119) {
    return i;
  }
  return j;
}
 
// The maximal integer value before overflow happens

extern kk_integer_t kk_std_num_int32_max_int32;
 
// Return the minimum of two integers

static inline int32_t kk_std_num_int32_min(int32_t i, int32_t j, kk_context_t* _ctx) { /* (i : int32, j : int32) -> int32 */ 
  bool _match_2118 = (i <= j); /*bool*/;
  if (_match_2118) {
    return i;
  }
  return j;
}

kk_string_t kk_std_num_int32_show_hex(int32_t i, kk_std_core_types__optional width, kk_std_core_types__optional use_capitals, kk_std_core_types__optional pre, kk_context_t* _ctx); /* (i : int32, width : optional<int>, use-capitals : optional<bool>, pre : optional<string>) -> string */ 
 
// Convert an `:int32` to an `:int` but interpret the `:int32` as a 32-bit unsigned value.

static inline kk_integer_t kk_std_num_int32_uint(int32_t i, kk_context_t* _ctx) { /* (i : int32) -> int */ 
  bool _match_2117 = (i)<0; /*bool*/;
  if (_match_2117) {
    kk_integer_t _x2139 = kk_integer_from_int(i,kk_context()); /*int*/
    return kk_integer_add((kk_integer_from_str("4294967296", _ctx)),_x2139,kk_context());
  }
  return kk_integer_from_int(i,kk_context());
}

static inline kk_std_core_types__order kk_std_num_int32_sign(int32_t i, kk_context_t* _ctx) { /* (i : int32) -> order */ 
  bool _match_2115 = 0<=(i); /*bool*/;
  if (_match_2115) {
    return kk_std_core_types__new_Gt(_ctx);
  }
  bool _match_2116 = (i)<0; /*bool*/;
  if (_match_2116) {
    return kk_std_core_types__new_Lt(_ctx);
  }
  return kk_std_core_types__new_Eq(_ctx);
}

extern int32_t kk_std_num_int32_one;

extern int32_t kk_std_num_int32_zero;
 
// Convert a boolean to an `:int32`.

static inline int32_t kk_std_num_int32_int32_1(bool b, kk_context_t* _ctx) { /* (b : bool) -> int32 */ 
  kk_integer_t _x2140;
  if (b) {
    _x2140 = kk_integer_from_small(1); /*int*/
  }
  else {
    _x2140 = kk_integer_from_small(0); /*int*/
  }
  return kk_std_core_int32(_x2140, _ctx);
}

int32_t kk_std_num_int32__lp__perc__rp_(int32_t x, int32_t y, kk_context_t* _ctx); /* (x : int32, y : int32) -> int32 */ 

int32_t kk_std_num_int32__lp__fs__rp_(int32_t x, int32_t y, kk_context_t* _ctx); /* (x : int32, y : int32) -> int32 */ 
 
// Negate an 32-bit integer

static inline int32_t kk_std_num_int32__lp__tilde__rp_(int32_t i, kk_context_t* _ctx) { /* (i : int32) -> total int32 */ 
  return ((((int32_t)0)) - i);
}
 
// The minimal integer value before underflow happens

extern kk_integer_t kk_std_num_int32_min_int32;
 
// Negate a 32-bit integer

static inline int32_t kk_std_num_int32_negate(int32_t i, kk_context_t* _ctx) { /* (i : int32) -> int32 */ 
  return ((((int32_t)0)) - i);
}

int32_t kk_std_num_int32_abs(int32_t i, kk_context_t* _ctx); /* (i : int32) -> exn int32 */ 

int32_t kk_std_num_int32_abs0(int32_t i, kk_context_t* _ctx); /* (i : int32) -> int32 */ 
 
// The number of bits in an `:int32` (always 32)

extern int32_t kk_std_num_int32_bits_int32;
 
// Convert an `:int32` to a boolean.

static inline bool kk_std_num_int32_bool(int32_t i, kk_context_t* _ctx) { /* (i : int32) -> bool */ 
  return (i != (((int32_t)0)));
}
 
// Decrement a 32-bit integer.

static inline int32_t kk_std_num_int32_dec(int32_t i, kk_context_t* _ctx) { /* (i : int32) -> int32 */ 
  return (i - (((int32_t)1)));
}
 
// Increment a 32-bit integer.

static inline int32_t kk_std_num_int32_inc(int32_t i, kk_context_t* _ctx) { /* (i : int32) -> int32 */ 
  return (i + (((int32_t)1)));
}

kk_std_core_types__tuple2_ kk_std_num_int32_divmod(int32_t x, int32_t y, kk_context_t* _ctx); /* (x : int32, y : int32) -> (int32, int32) */ 

kk_box_t kk_std_num_int32_fold_int32(int32_t start, int32_t end, kk_box_t init, kk_function_t f, kk_context_t* _ctx); /* forall<a> (start : int32, end : int32, init : a, f : (int32, a) -> a) -> a */ 
 
// Returns `true` if the integer `i`  is an even number.

static inline bool kk_std_num_int32_is_even(int32_t i, kk_context_t* _ctx) { /* (i : int32) -> bool */ 
  int32_t _x2164 = (i & (((int32_t)1))); /*int32*/
  return (_x2164 == (((int32_t)0)));
}
 
// Returns `true` if the integer `i`  is an odd number.

static inline bool kk_std_num_int32_is_odd(int32_t i, kk_context_t* _ctx) { /* (i : int32) -> bool */ 
  int32_t _x2165 = (i & (((int32_t)1))); /*int32*/
  return (_x2165 == (((int32_t)1)));
}

int32_t kk_std_num_int32_rotl(int32_t i, int32_t n, kk_context_t* _ctx); /* (i : int32, n : int32) -> int32 */ 

int32_t kk_std_num_int32_rotr(int32_t i, int32_t n, kk_context_t* _ctx); /* (i : int32, n : int32) -> int32 */ 
 
// Convert an `:int32` to a string

static inline kk_string_t kk_std_num_int32_show(int32_t i, kk_context_t* _ctx) { /* (i : int32) -> string */ 
  kk_integer_t _x2174 = kk_integer_from_int(i,kk_context()); /*int*/
  return kk_std_core_show(_x2174, _ctx);
}

kk_string_t kk_std_num_int32_show_hex32(int32_t i, kk_std_core_types__optional width, kk_std_core_types__optional use_capitals, kk_std_core_types__optional pre, kk_context_t* _ctx); /* (i : int32, width : optional<int>, use-capitals : optional<bool>, pre : optional<string>) -> string */ 
 
// Convert an `:int` to `:int32` but interpret the `int` as an unsigned 32-bit value.
// `i` is clamped between `0` and `0xFFFFFFFF`.
// `0x7FFFFFFF.uint32 == 0x7FFFFFFF.int32 == max-int32`
// `0x80000000.uint32 == -1.int32`
// `0xFFFFFFFF.uint32 == -0x80000000.int32 == min-int32`

static inline int32_t kk_std_num_int32_uint32(kk_integer_t i, kk_context_t* _ctx) { /* (i : int) -> int32 */ 
  kk_integer_t _x2192;
  bool _match_2096;
  kk_integer_t _x2193 = kk_integer_dup(i); /*int*/
  _match_2096 = kk_integer_gt(_x2193,(kk_integer_from_int(2147483647, _ctx)),kk_context()); /*bool*/
  if (_match_2096) {
    _x2192 = kk_integer_sub(i,(kk_integer_from_str("4294967296", _ctx)),kk_context()); /*int*/
  }
  else {
    _x2192 = i; /*int*/
  }
  return kk_std_core_int32(_x2192, _ctx);
}

void kk_std_num_int32__init(kk_context_t* _ctx);

#endif // header
