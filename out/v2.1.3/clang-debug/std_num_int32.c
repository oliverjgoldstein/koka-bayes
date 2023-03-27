// Koka generated module: "std/num/int32", koka version: 2.1.3
#include "std_num_int32.h"

kk_integer_t kk_std_num_int32_max_int32;
 
// Show an `:int32` in hexadecimal notation
// The `width`  parameter specifies how wide the hex value is where `'0'`  is used to align.
// The `use-capitals` parameter (= `True`) determines if captical letters should be used to display the hexadecimal digits.
// The `pre` (=`"0x"`) is an optional prefix for the number (goes between the sign and the number).

kk_string_t kk_std_num_int32_show_hex(int32_t i, kk_std_core_types__optional width, kk_std_core_types__optional use_capitals, kk_std_core_types__optional pre, kk_context_t* _ctx) { /* (i : int32, width : optional<int>, use-capitals : optional<bool>, pre : optional<string>) -> string */ 
  kk_integer_t _x2122 = kk_integer_from_int(i,kk_context()); /*int*/
  kk_std_core_types__optional _x2123;
  kk_box_t _x2124;
  kk_integer_t _x2125;
  if (kk_std_core_types__is_Optional(width)) {
    kk_box_t _box_x2043 = width._cons.Optional.value;
    kk_integer_t _width_212 = kk_integer_unbox(_box_x2043);
    kk_integer_dup(_width_212);
    kk_std_core_types__optional_drop(width, _ctx);
    _x2125 = _width_212; /*int*/
    goto _match2126;
  }
  _x2125 = kk_integer_from_small(1); /*int*/
  _match2126: ;
  _x2124 = kk_integer_box(_x2125); /*35*/
  _x2123 = kk_std_core_types__new_Optional(_x2124, _ctx); /*optional<35>*/
  kk_std_core_types__optional _x2128;
  kk_box_t _x2129;
  bool _x2130;
  if (kk_std_core_types__is_Optional(use_capitals)) {
    kk_box_t _box_x2045 = use_capitals._cons.Optional.value;
    bool _use_capitals_216 = kk_bool_unbox(_box_x2045);
    kk_std_core_types__optional_drop(use_capitals, _ctx);
    _x2130 = _use_capitals_216; /*bool*/
    goto _match2131;
  }
  _x2130 = true; /*bool*/
  _match2131: ;
  _x2129 = kk_bool_box(_x2130); /*35*/
  _x2128 = kk_std_core_types__new_Optional(_x2129, _ctx); /*optional<35>*/
  kk_std_core_types__optional _x2133;
  kk_box_t _x2134;
  kk_string_t _x2135;
  if (kk_std_core_types__is_Optional(pre)) {
    kk_box_t _box_x2047 = pre._cons.Optional.value;
    kk_string_t _pre_220 = kk_string_unbox(_box_x2047);
    kk_string_dup(_pre_220);
    kk_std_core_types__optional_drop(pre, _ctx);
    _x2135 = _pre_220; /*string*/
    goto _match2136;
  }
  kk_define_string_literal(, _s2138, 2, "0x")
  _x2135 = kk_string_dup(_s2138); /*string*/
  _match2136: ;
  _x2134 = kk_string_box(_x2135); /*35*/
  _x2133 = kk_std_core_types__new_Optional(_x2134, _ctx); /*optional<35>*/
  return kk_std_core_show_hex(_x2122, _x2123, _x2128, _x2133, _ctx);
}

int32_t kk_std_num_int32_one;

int32_t kk_std_num_int32_zero;
 
// Euclidean-0 modulus. See `(/):(x : int32, y : int32) -> int32` division for more information.

int32_t kk_std_num_int32__lp__perc__rp_(int32_t x, int32_t y, kk_context_t* _ctx) { /* (x : int32, y : int32) -> int32 */ 
  bool _match_2112 = (y == (((int32_t)0))); /*bool*/;
  if (_match_2112) {
    return x;
  }
  int32_t r = (x % y); /*int32*/;
  bool _match_2113 = (r >= (((int32_t)0))); /*bool*/;
  if (_match_2113) {
    return r;
  }
  bool _match_2114 = (y > (((int32_t)0))); /*bool*/;
  if (_match_2114) {
    return (r + y);
  }
  return (r - y);
}
 
/*
Euclidean-0 division.
Euclidean division is defined as: For any `D`  and `d`  where `d!=0` , we have:
1. `D == d*(D/d) + (D%d)`
2. `D%d`  is always positive where `0 <= D%d < abs(d)`
Moreover, Euclidean-0 is a total function, for the case where `d==0`  we have
that `D%0 == D`  and `D/0 == 0` . So property (1) still holds, but not property (2).
Useful laws that hold for Euclidean-0 division:
* `D/(-d) == -(D/d)`
* `D%(-d) == D%d`
* `D/(2^n) == sar(D,n)         `  (with `0 <= n <= 31`)
* `D%(2^n) == D & ((2^n) - 1)  `  (with `0 <= n <= 31`)
Note that an interesting edge case is `min-int32 / -1` which equals `min-int32` since in modulo 32-bit
arithmetic `min-int32 == -1 * min-int32 == -1 * (min-int32 / -1) + (min-int32 % -1)` satisfying property (1).
Of course `(min-int32 + 1) / -1` is again positive (namely `max-int32`).
See also _Division and modulus for computer scientists, Daan Leijen, 2001_
[pdf](http://research.microsoft.com/pubs/151917/divmodnote.pdf) .
*/

int32_t kk_std_num_int32__lp__fs__rp_(int32_t x, int32_t y, kk_context_t* _ctx) { /* (x : int32, y : int32) -> int32 */ 
  bool _match_2109 = (y == (((int32_t)0))); /*bool*/;
  if (_match_2109) {
    return ((int32_t)0);
  }
  int32_t q = (x / y); /*int32*/;
  int32_t r = (x % y); /*int32*/;
  bool _match_2110 = (r >= (((int32_t)0))); /*bool*/;
  if (_match_2110) {
    return q;
  }
  bool _match_2111 = (y > (((int32_t)0))); /*bool*/;
  if (_match_2111) {
    return (q - (((int32_t)1)));
  }
  return (q + (((int32_t)1)));
}

kk_integer_t kk_std_num_int32_min_int32;
 
// Return the absolute value of an integer.
// Raises an exception if the `:int32` is `min-int32`
// (since the negation of `min-int32` equals itself and is still negative)


// lift anonymous function
struct kk_std_num_int32_abs_fun2145__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_int32_abs_fun2145(kk_function_t _fself, kk_box_t _b_2054, kk_context_t* _ctx);
static kk_function_t kk_std_num_int32_new_abs_fun2145(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_int32_abs_fun2145, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_int32_abs_fun2145(kk_function_t _fself, kk_box_t _b_2054, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  int32_t _x2146;
  int32_t _x2147 = kk_int32_unbox(_b_2054, _ctx); /*int32*/
  _x2146 = kk_std_num_int32_negate(_x2147, _ctx); /*int32*/
  return kk_int32_box(_x2146, _ctx);
}

int32_t kk_std_num_int32_abs(int32_t i, kk_context_t* _ctx) { /* (i : int32) -> exn int32 */ 
  bool _match_2105;
  bool _x2141 = (i)<0; /*bool*/
  _match_2105 = !(_x2141); /*bool*/
  if (_match_2105) {
    return i;
  }
  bool _match_2106;
  int32_t _x2142;
  kk_integer_t _x2143 = kk_integer_neg((kk_integer_from_str("2147483648", _ctx)),kk_context()); /*int*/
  _x2142 = kk_std_core_int32(_x2143, _ctx); /*int32*/
  _match_2106 = (i > _x2142); /*bool*/
  if (_match_2106) {
    kk_box_t _x2144 = kk_std_core_hnd__open_none1(kk_std_num_int32_new_abs_fun2145(_ctx), kk_int32_box(i, _ctx), _ctx); /*2*/
    return kk_int32_unbox(_x2144, _ctx);
  }
  kk_std_core__exception exn_21561;
  kk_string_t _x2148;
  kk_define_string_literal(, _s2149, 79, "std/num/int32/abs: cannot make min-int32 into a positive int32 without overflow")
  _x2148 = kk_string_dup(_s2149); /*string*/
  kk_std_core__exception_info _x2150;
  kk_std_core_types__optional _match_2108 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
  if (kk_std_core_types__is_Optional(_match_2108)) {
    kk_box_t _box_x2055 = _match_2108._cons.Optional.value;
    kk_std_core__exception_info _info_14279 = kk_std_core__exception_info_unbox(_box_x2055, NULL);
    kk_std_core__exception_info_dup(_info_14279);
    kk_std_core_types__optional_drop(_match_2108, _ctx);
    _x2150 = _info_14279; /*exception-info*/
    goto _match2151;
  }
  _x2150 = kk_std_core__new_ExnError(_ctx); /*exception-info*/
  _match2151: ;
  exn_21561 = kk_std_core__new_Exception(_x2148, _x2150, _ctx); /*exception*/
  kk_std_core_hnd__ev ev_21562;
  size_t _x2153 = ((size_t)0); /*size_t*/
  ev_21562 = kk_evv_at(_x2153,kk_context()); /*std/core/hnd/ev<.hnd-exn>*/
  kk_box_t _x2154;
  struct kk_std_core_hnd_Ev* _con2155 = kk_std_core_hnd__as_Ev(ev_21562);
  kk_std_core_hnd__marker m = _con2155->marker;
  kk_box_t _box_x2056 = _con2155->hnd;
  kk_std_core__hnd_exn h = kk_std_core__hnd_exn_unbox(_box_x2056, NULL);
  kk_std_core__hnd_exn_dup(h);
  kk_std_core_hnd__clause1 _match_2107;
  struct kk_std_core__Hnd_exn* _con2157 = kk_std_core__as_Hnd_exn(h);
  kk_std_core_hnd__clause1 except_throw_exn = _con2157->except_throw_exn;
  if (kk_std_core__hnd_exn_is_unique(h)) {
    kk_std_core__hnd_exn_free(h);
  }
  else {
    kk_std_core_hnd__clause1_dup(except_throw_exn);
    kk_std_core__hnd_exn_decref(h, _ctx);
  }
  _match_2107 = except_throw_exn; /*forall<a> std/core/hnd/clause1<exception,a,.hnd-exn,6,7>*/
  kk_function_t _fun_unbox_x2060 = _match_2107.clause;
  _x2154 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x2060, (_fun_unbox_x2060, m, ev_21562, kk_std_core__exception_box(exn_21561, _ctx), _ctx)); /*11*/
  return kk_int32_unbox(_x2154, _ctx);
}
 
// Return the absolute value of an integer.
// Returns 0 if the `:int32` is `min-int32`
// (since the negation of `min-int32` equals itself and is still negative)

int32_t kk_std_num_int32_abs0(int32_t i, kk_context_t* _ctx) { /* (i : int32) -> int32 */ 
  bool _match_2103;
  bool _x2158 = (i)<0; /*bool*/
  _match_2103 = !(_x2158); /*bool*/
  if (_match_2103) {
    return i;
  }
  bool _match_2104;
  int32_t _x2159;
  kk_integer_t _x2160 = kk_integer_neg((kk_integer_from_str("2147483648", _ctx)),kk_context()); /*int*/
  _x2159 = kk_std_core_int32(_x2160, _ctx); /*int32*/
  _match_2104 = (i > _x2159); /*bool*/
  if (_match_2104) {
    return kk_std_num_int32_negate(i, _ctx);
  }
  return ((int32_t)0);
}

int32_t kk_std_num_int32_bits_int32;

kk_std_core_types__tuple2_ kk_std_num_int32_divmod(int32_t x, int32_t y, kk_context_t* _ctx) { /* (x : int32, y : int32) -> (int32, int32) */ 
  bool _match_2100 = 0==(y); /*bool*/;
  if (_match_2100) {
    int32_t _b_2077_2069 = ((int32_t)0); /*int32*/;
    int32_t _b_2078_2070 = ((int32_t)0); /*int32*/;
    return kk_std_core_types__new_dash__lp__comma__rp_(kk_int32_box(_b_2077_2069, _ctx), kk_int32_box(_b_2078_2070, _ctx), _ctx);
  }
  int32_t q = (x / y); /*int32*/;
  int32_t r = (x % y); /*int32*/;
  bool _match_2101;
  bool _x2161 = (r)<0; /*bool*/
  _match_2101 = !(_x2161); /*bool*/
  if (_match_2101) {
    return kk_std_core_types__new_dash__lp__comma__rp_(kk_int32_box(q, _ctx), kk_int32_box(r, _ctx), _ctx);
  }
  bool _match_2102 = 0<=(y); /*bool*/;
  if (_match_2102) {
    int32_t _b_2081_2073 = kk_std_num_int32_dec(q, _ctx); /*int32*/;
    int32_t _b_2082_2074 = (r + y); /*int32*/;
    return kk_std_core_types__new_dash__lp__comma__rp_(kk_int32_box(_b_2081_2073, _ctx), kk_int32_box(_b_2082_2074, _ctx), _ctx);
  }
  int32_t _b_2083_2075 = kk_std_num_int32_inc(q, _ctx); /*int32*/;
  int32_t _b_2084_2076 = (r - y); /*int32*/;
  return kk_std_core_types__new_dash__lp__comma__rp_(kk_int32_box(_b_2083_2075, _ctx), kk_int32_box(_b_2084_2076, _ctx), _ctx);
}

kk_box_t kk_std_num_int32_fold_int32(int32_t start, int32_t end, kk_box_t init, kk_function_t f, kk_context_t* _ctx) { /* forall<a> (start : int32, end : int32, init : a, f : (int32, a) -> a) -> a */ 
  kk__tailcall: ;
  bool _match_2099 = (start >= end); /*bool*/;
  if (_match_2099) {
    kk_function_drop(f, _ctx);
    return init;
  }
  kk_box_t x;
  kk_function_t _x2162 = kk_function_dup(f); /*(int32, 1536) -> 1536*/
  x = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_box_t, kk_context_t*), _x2162, (_x2162, start, init, _ctx)); /*1536*/
  { // tailcall
    int32_t _x2163 = kk_std_num_int32_inc(start, _ctx); /*int32*/
    start = _x2163;
    init = x;
    goto kk__tailcall;
  }
}
 
// Bitwise rotate an `:int32` `n` bits to the left.
// Does not rotate when `n` is negative.

int32_t kk_std_num_int32_rotl(int32_t i, int32_t n, kk_context_t* _ctx) { /* (i : int32, n : int32) -> int32 */ 
  bool _match_2098 = (n)<0; /*bool*/;
  if (_match_2098) {
    return i;
  }
  int32_t r;
  int32_t _x2166;
  int32_t i0_2041 = ((int32_t)32); /*int32*/;
  _x2166 = (i0_2041 - (((int32_t)1))); /*int32*/
  r = (n & _x2166); /*int32*/
  int32_t _x2167 = (i << r); /*int32*/
  int32_t _x2168;
  int32_t _x2169 = ((((int32_t)32)) - r); /*int32*/
  _x2168 = ((int32_t)((uint32_t)i >> _x2169)); /*int32*/
  return (_x2167 | _x2168);
}
 
// Bitwise rotate an `:int32` `n` bits to the right.
// Does not rotate when `n` is negative.

int32_t kk_std_num_int32_rotr(int32_t i, int32_t n, kk_context_t* _ctx) { /* (i : int32, n : int32) -> int32 */ 
  bool _match_2097 = (n)<0; /*bool*/;
  if (_match_2097) {
    return i;
  }
  int32_t r;
  int32_t _x2170;
  int32_t i0_2042 = ((int32_t)32); /*int32*/;
  _x2170 = (i0_2042 - (((int32_t)1))); /*int32*/
  r = (n & _x2170); /*int32*/
  int32_t _x2171 = ((int32_t)((uint32_t)i >> r)); /*int32*/
  int32_t _x2172;
  int32_t _x2173 = ((((int32_t)32)) - r); /*int32*/
  _x2172 = (i << _x2173); /*int32*/
  return (_x2171 | _x2172);
}
 
// Show an `:int32` in hexadecimal notation interpreted as an unsigned 32-bit value.
// The `width`  parameter specifies how wide the hex value is where `'0'`  is used to align.
// The `use-capitals` parameter (= `True`) determines if captical letters should be used to display the hexadecimal digits.
// The `pre` (=`"0x"`) is an optional prefix for the number.

kk_string_t kk_std_num_int32_show_hex32(int32_t i, kk_std_core_types__optional width, kk_std_core_types__optional use_capitals, kk_std_core_types__optional pre, kk_context_t* _ctx) { /* (i : int32, width : optional<int>, use-capitals : optional<bool>, pre : optional<string>) -> string */ 
  kk_integer_t _x2175 = kk_std_num_int32_uint(i, _ctx); /*int*/
  kk_std_core_types__optional _x2176;
  kk_box_t _x2177;
  kk_integer_t _x2178;
  if (kk_std_core_types__is_Optional(width)) {
    kk_box_t _box_x2085 = width._cons.Optional.value;
    kk_integer_t _width_1913 = kk_integer_unbox(_box_x2085);
    kk_integer_dup(_width_1913);
    kk_std_core_types__optional_drop(width, _ctx);
    _x2178 = _width_1913; /*int*/
    goto _match2179;
  }
  _x2178 = kk_integer_from_small(8); /*int*/
  _match2179: ;
  _x2177 = kk_integer_box(_x2178); /*35*/
  _x2176 = kk_std_core_types__new_Optional(_x2177, _ctx); /*optional<35>*/
  kk_std_core_types__optional _x2181;
  kk_box_t _x2182;
  bool _x2183;
  if (kk_std_core_types__is_Optional(use_capitals)) {
    kk_box_t _box_x2087 = use_capitals._cons.Optional.value;
    bool _use_capitals_1917 = kk_bool_unbox(_box_x2087);
    kk_std_core_types__optional_drop(use_capitals, _ctx);
    _x2183 = _use_capitals_1917; /*bool*/
    goto _match2184;
  }
  _x2183 = true; /*bool*/
  _match2184: ;
  _x2182 = kk_bool_box(_x2183); /*35*/
  _x2181 = kk_std_core_types__new_Optional(_x2182, _ctx); /*optional<35>*/
  kk_std_core_types__optional _x2186;
  kk_box_t _x2187;
  kk_string_t _x2188;
  if (kk_std_core_types__is_Optional(pre)) {
    kk_box_t _box_x2089 = pre._cons.Optional.value;
    kk_string_t _pre_1921 = kk_string_unbox(_box_x2089);
    kk_string_dup(_pre_1921);
    kk_std_core_types__optional_drop(pre, _ctx);
    _x2188 = _pre_1921; /*string*/
    goto _match2189;
  }
  kk_define_string_literal(, _s2191, 2, "0x")
  _x2188 = kk_string_dup(_s2191); /*string*/
  _match2189: ;
  _x2187 = kk_string_box(_x2188); /*35*/
  _x2186 = kk_std_core_types__new_Optional(_x2187, _ctx); /*optional<35>*/
  return kk_std_core_show_hex(_x2175, _x2176, _x2181, _x2186, _ctx);
}

// initialization
void kk_std_num_int32__init(kk_context_t* _ctx){
  static bool _initialized = false;
  if (_initialized) return;
  _initialized = true;
  kk_std_core_types__init(_ctx);
  kk_std_core_hnd__init(_ctx);
  kk_std_core__init(_ctx);
  {
    kk_std_num_int32_max_int32 = kk_integer_from_int(2147483647, _ctx); /*int*/
  }
  {
    kk_std_num_int32_one = ((int32_t)1); /*int32*/
  }
  {
    kk_std_num_int32_zero = ((int32_t)0); /*int32*/
  }
  {
    kk_std_num_int32_min_int32 = kk_integer_neg((kk_integer_from_str("2147483648", _ctx)),kk_context()); /*int*/
  }
  {
    kk_std_num_int32_bits_int32 = ((int32_t)32); /*int32*/
  }
}
