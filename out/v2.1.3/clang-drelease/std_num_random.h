#pragma once
#ifndef kk_std_num_random_H
#define kk_std_num_random_H
// Koka generated module: "std/num/random", koka version: 2.1.3
#include <kklib.h>
#include "std_core_types.h"
#include "std_core_hnd.h"
#include "std_core.h"
#include "std_num_int32.h"
#include "std_num_double.h"

// type declarations

// type std/num/random/.hnd-random
struct kk_std_num_random__hnd_random_s {
  kk_block_t _block;
};
typedef struct kk_std_num_random__hnd_random_s* kk_std_num_random__hnd_random;
struct kk_std_num_random__Hnd_random {
  struct kk_std_num_random__hnd_random_s _base;
  kk_std_core_hnd__clause0 fun_random_int32;
};
static inline kk_std_num_random__hnd_random kk_std_num_random__base_Hnd_random(struct kk_std_num_random__Hnd_random* _x){
  return &_x->_base;
}
static inline kk_std_num_random__hnd_random kk_std_num_random__new_Hnd_random(kk_reuse_t _at, kk_std_core_hnd__clause0 fun_random_int32, kk_context_t* _ctx){
  struct kk_std_num_random__Hnd_random* _con = kk_block_alloc_at_as(struct kk_std_num_random__Hnd_random, _at, 1 /* scan count */, (kk_tag_t)(1), _ctx);
  _con->fun_random_int32 = fun_random_int32;
  return kk_std_num_random__base_Hnd_random(_con);
}
static inline struct kk_std_num_random__Hnd_random* kk_std_num_random__as_Hnd_random(kk_std_num_random__hnd_random x) {
  return kk_basetype_as_assert(struct kk_std_num_random__Hnd_random*, x, (kk_tag_t)(1) /* _tag */);
}
static inline bool kk_std_num_random__is_Hnd_random(kk_std_num_random__hnd_random x) {
  return (true);
}
static inline kk_std_num_random__hnd_random kk_std_num_random__hnd_random_dup(kk_std_num_random__hnd_random _x) {
  return kk_basetype_dup_as(kk_std_num_random__hnd_random, _x);
}
static inline void kk_std_num_random__hnd_random_drop(kk_std_num_random__hnd_random _x, kk_context_t* _ctx) {
  kk_basetype_drop(_x, _ctx);
}
static inline bool kk_std_num_random__hnd_random_is_unique(kk_std_num_random__hnd_random _x) {
  return kk_basetype_is_unique(_x);
}
static inline void kk_std_num_random__hnd_random_free(kk_std_num_random__hnd_random _x) {
  kk_basetype_free(_x);
}
static inline void kk_std_num_random__hnd_random_decref(kk_std_num_random__hnd_random _x, kk_context_t* _ctx) {
  kk_basetype_decref(_x, _ctx);
}
static inline kk_reuse_t kk_std_num_random__hnd_random_dropn_reuse(kk_std_num_random__hnd_random _x, size_t _scan_fsize, kk_context_t* _ctx) {
  return kk_basetype_dropn_reuse(_x, _scan_fsize, _ctx);
}
static inline void kk_std_num_random__hnd_random_dropn(kk_std_num_random__hnd_random _x, size_t _scan_fsize, kk_context_t* _ctx) {
  kk_basetype_dropn(_x, _scan_fsize, _ctx);
}
static inline kk_reuse_t kk_std_num_random__hnd_random_reuse(kk_std_num_random__hnd_random _x) {
  return kk_basetype_reuse(_x);
}
static inline kk_std_num_random__hnd_random kk_std_num_random__hnd_random_hole() {
  return (kk_std_num_random__hnd_random)(1);
}
static inline kk_box_t kk_std_num_random__hnd_random_box(kk_std_num_random__hnd_random _x, kk_context_t* _ctx) {
  return kk_basetype_box(_x);
}
static inline kk_std_num_random__hnd_random kk_std_num_random__hnd_random_unbox(kk_box_t _x, kk_context_t* _ctx) {
  return kk_basetype_unbox_as(kk_std_num_random__hnd_random, _x);
}

// type std/num/random/random
struct kk_std_num_random__random_s {
  kk_block_t _block;
};
typedef struct kk_std_num_random__random_s* kk_std_num_random__random;
struct kk_std_num_random_Random {
  struct kk_std_num_random__random_s _base;
  kk_std_num_random__hnd_random _field1;
};
static inline kk_std_num_random__random kk_std_num_random__base_Random(struct kk_std_num_random_Random* _x){
  return &_x->_base;
}
static inline kk_std_num_random__random kk_std_num_random__new_Random(kk_reuse_t _at, kk_std_num_random__hnd_random _field1, kk_context_t* _ctx){
  struct kk_std_num_random_Random* _con = kk_block_alloc_at_as(struct kk_std_num_random_Random, _at, 1 /* scan count */, (kk_tag_t)(1), _ctx);
  _con->_field1 = _field1;
  return kk_std_num_random__base_Random(_con);
}
static inline struct kk_std_num_random_Random* kk_std_num_random__as_Random(kk_std_num_random__random x) {
  return kk_basetype_as_assert(struct kk_std_num_random_Random*, x, (kk_tag_t)(1) /* _tag */);
}
static inline bool kk_std_num_random__is_Random(kk_std_num_random__random x) {
  return (true);
}
static inline kk_std_num_random__random kk_std_num_random__random_dup(kk_std_num_random__random _x) {
  return kk_basetype_dup_as(kk_std_num_random__random, _x);
}
static inline void kk_std_num_random__random_drop(kk_std_num_random__random _x, kk_context_t* _ctx) {
  kk_basetype_drop(_x, _ctx);
}
static inline bool kk_std_num_random__random_is_unique(kk_std_num_random__random _x) {
  return kk_basetype_is_unique(_x);
}
static inline void kk_std_num_random__random_free(kk_std_num_random__random _x) {
  kk_basetype_free(_x);
}
static inline void kk_std_num_random__random_decref(kk_std_num_random__random _x, kk_context_t* _ctx) {
  kk_basetype_decref(_x, _ctx);
}
static inline kk_reuse_t kk_std_num_random__random_dropn_reuse(kk_std_num_random__random _x, size_t _scan_fsize, kk_context_t* _ctx) {
  return kk_basetype_dropn_reuse(_x, _scan_fsize, _ctx);
}
static inline void kk_std_num_random__random_dropn(kk_std_num_random__random _x, size_t _scan_fsize, kk_context_t* _ctx) {
  kk_basetype_dropn(_x, _scan_fsize, _ctx);
}
static inline kk_reuse_t kk_std_num_random__random_reuse(kk_std_num_random__random _x) {
  return kk_basetype_reuse(_x);
}
static inline kk_std_num_random__random kk_std_num_random__random_hole() {
  return (kk_std_num_random__random)(1);
}
static inline kk_box_t kk_std_num_random__random_box(kk_std_num_random__random _x, kk_context_t* _ctx) {
  return kk_basetype_box(_x);
}
static inline kk_std_num_random__random kk_std_num_random__random_unbox(kk_box_t _x, kk_context_t* _ctx) {
  return kk_basetype_unbox_as(kk_std_num_random__random, _x);
}

// value type std/num/random/sfc
struct kk_std_num_random_Sfc {
  int32_t x;
  int32_t y;
  int32_t z;
  int32_t cnt;
};
typedef struct kk_std_num_random_Sfc kk_std_num_random__sfc;
static inline kk_std_num_random__sfc kk_std_num_random__new_Sfc(int32_t x, int32_t y, int32_t z, int32_t cnt, kk_context_t* _ctx){
  kk_std_num_random__sfc _con;
  _con.x = x;
  _con.y = y;
  _con.z = z;
  _con.cnt = cnt;
  return _con;
}
static inline bool kk_std_num_random__is_Sfc(kk_std_num_random__sfc x) {
  return (true);
}
static inline kk_std_num_random__sfc kk_std_num_random__sfc_dup(kk_std_num_random__sfc _x) {
  return _x;
}
static inline void kk_std_num_random__sfc_drop(kk_std_num_random__sfc _x, kk_context_t* _ctx) {
  
}
static inline kk_box_t kk_std_num_random__sfc_box(kk_std_num_random__sfc _x, kk_context_t* _ctx) {
  kk_box_t _box;
  kk_valuetype_box(kk_std_num_random__sfc, _box, _x, 0 /* scan count */, _ctx);
  return _box;
}
static inline kk_std_num_random__sfc kk_std_num_random__sfc_unbox(kk_box_t _x, kk_context_t* _ctx) {
  kk_boxed_value_t _p;
  kk_std_num_random__sfc _unbox;
  kk_valuetype_unbox_(kk_std_num_random__sfc, _p, _unbox, _x, _ctx);
  if (_ctx!=NULL && _p!=NULL) {
    if (kk_basetype_is_unique(_p)) { kk_basetype_free(_p); } else {
      kk_std_num_random__sfc_dup(_unbox);
      kk_basetype_decref(_p, _ctx);
    }
  }
  return _unbox;
}

// value declarations
 
// Automatically generated. Retrieves the `x` constructor field of the `:sfc` type.

static inline int32_t kk_std_num_random_x(kk_std_num_random__sfc sfc, kk_context_t* _ctx) { /* (sfc : sfc) -> int32 */ 
  int32_t _x = sfc.x;
  return _x;
}
 
// Automatically generated. Retrieves the `y` constructor field of the `:sfc` type.

static inline int32_t kk_std_num_random_y(kk_std_num_random__sfc sfc, kk_context_t* _ctx) { /* (sfc : sfc) -> int32 */ 
  int32_t _x = sfc.y;
  return _x;
}
 
// Automatically generated. Retrieves the `z` constructor field of the `:sfc` type.

static inline int32_t kk_std_num_random_z(kk_std_num_random__sfc sfc, kk_context_t* _ctx) { /* (sfc : sfc) -> int32 */ 
  int32_t _x = sfc.z;
  return _x;
}
 
// Automatically generated. Retrieves the `cnt` constructor field of the `:sfc` type.

static inline int32_t kk_std_num_random_cnt(kk_std_num_random__sfc sfc, kk_context_t* _ctx) { /* (sfc : sfc) -> int32 */ 
  int32_t _x = sfc.cnt;
  return _x;
}

kk_std_num_random__sfc kk_std_num_random__copy(kk_std_num_random__sfc _this, kk_std_core_types__optional x0, kk_std_core_types__optional y0, kk_std_core_types__optional z0, kk_std_core_types__optional cnt0, kk_context_t* _ctx); /* (sfc, x : optional<int32>, y : optional<int32>, z : optional<int32>, cnt : optional<int32>) -> sfc */ 
 
// select `random-int32` operation out of the `:random` effect handler

static inline kk_std_core_hnd__clause0 kk_std_num_random__select_random_int32(kk_std_num_random__hnd_random hnd, kk_context_t* _ctx) { /* forall<e,a> (hnd : .hnd-random<e,a>) -> std/core/hnd/clause0<int32,.hnd-random,e,a> */ 
  struct kk_std_num_random__Hnd_random* _con1563 = kk_std_num_random__as_Hnd_random(hnd);
  kk_std_core_hnd__clause0 fun_random_int32 = _con1563->fun_random_int32;
  if (kk_std_num_random__hnd_random_is_unique(hnd)) {
    kk_std_num_random__hnd_random_free(hnd);
  }
  else {
    kk_std_core_hnd__clause0_dup(fun_random_int32);
    kk_std_num_random__hnd_random_decref(hnd, _ctx);
  }
  return fun_random_int32;
}

extern kk_std_core_hnd__htag kk_std_num_random__tag_random;

kk_box_t kk_std_num_random__handle_random(int32_t cfc, kk_std_num_random__hnd_random hnd, kk_function_t ret, kk_function_t action, kk_context_t* _ctx); /* forall<a,e,b> (cfc : int32, hnd : .hnd-random<e,b>, ret : (res : a) -> e b, action : () -> <random|e> a) -> e b */ 

int32_t kk_std_num_random_srandom_int32(kk_context_t* _ctx); /* () -> ndet int32 */ 

kk_std_core_types__tuple2_ kk_std_num_random_sfc_step(kk_std_num_random__sfc sfc, kk_context_t* _ctx); /* (sfc : sfc) -> (int32, sfc) */ 

double kk_std_num_random_srandom_double(kk_context_t* _ctx); /* () -> ndet double */ 

int32_t kk_std_num_random_srandom_int32_range(int32_t lo, int32_t hi, kk_context_t* _ctx); /* (lo : int32, hi : int32) -> ndet int32 */ 

bool kk_std_num_random_srandom_is_strong(kk_context_t* _ctx); /* () -> ndet bool */ 
 
// call `random-int32` operation of the `:random` effect

static inline int32_t kk_std_num_random_random_int32(kk_context_t* _ctx) { /* () -> random int32 */ 
  kk_std_core_hnd__ev ev_1401;
  size_t _x1575 = ((size_t)0); /*size_t*/
  ev_1401 = kk_evv_at(_x1575,kk_context()); /*std/core/hnd/ev<std/num/random/.hnd-random>*/
  kk_box_t _x1576;
  struct kk_std_core_hnd_Ev* _con1577 = kk_std_core_hnd__as_Ev(ev_1401);
  kk_std_core_hnd__marker m = _con1577->marker;
  kk_box_t _box_x1454 = _con1577->hnd;
  kk_std_num_random__hnd_random h = kk_std_num_random__hnd_random_unbox(_box_x1454, NULL);
  kk_std_num_random__hnd_random_dup(h);
  kk_std_core_hnd__clause0 _match_1550;
  struct kk_std_num_random__Hnd_random* _con1579 = kk_std_num_random__as_Hnd_random(h);
  kk_std_core_hnd__clause0 fun_random_int32 = _con1579->fun_random_int32;
  if (kk_std_num_random__hnd_random_is_unique(h)) {
    kk_std_num_random__hnd_random_free(h);
  }
  else {
    kk_std_core_hnd__clause0_dup(fun_random_int32);
    kk_std_num_random__hnd_random_decref(h, _ctx);
  }
  _match_1550 = fun_random_int32; /*std/core/hnd/clause0<int32,std/num/random/.hnd-random,3435,3436>*/
  kk_function_t _fun_unbox_x1457 = _match_1550.clause;
  _x1576 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x1457, (_fun_unbox_x1457, m, ev_1401, _ctx)); /*37*/
  return kk_int32_unbox(_x1576, _ctx);
}

kk_box_t kk_std_num_random_strong_random(kk_function_t action, kk_context_t* _ctx); /* forall<a,e> (action : () -> <random,ndet|e> a) -> <ndet|e> a */ 

static inline kk_box_t kk_std_num_random__default_random(kk_function_t _x11585, kk_context_t* _ctx) { /* forall<a,e> (action : () -> <random,ndet|e> a) -> <ndet|e> a */ 
  return kk_std_num_random_strong_random(_x11585, _ctx);
}
 
// Return a strong random boolean

static inline bool kk_std_num_random_srandom_bool(kk_context_t* _ctx) { /* () -> ndet bool */ 
  int32_t _x1586 = kk_std_num_random_srandom_int32(_ctx); /*int32*/
  return (_x1586 >= (((int32_t)0)));
}
 
// Returns one of its arguments `x`  or `y`  based on a non-deterministic choice.

static inline kk_box_t kk_std_num_random_choose(kk_box_t x0, kk_box_t y0, kk_context_t* _ctx) { /* forall<a> (x : a, y : a) -> ndet a */ 
  bool _match_1549 = kk_std_num_random_srandom_bool(_ctx); /*bool*/;
  if (_match_1549) {
    kk_box_drop(y0, _ctx);
    return x0;
  }
  kk_box_drop(x0, _ctx);
  return y0;
}

kk_std_num_random__sfc kk_std_num_random_sfc_init(kk_integer_t seed, kk_context_t* _ctx); /* (seed : int) -> sfc */ 

int32_t kk_std_num_random__mlift1390_pseudo_random(int32_t x0, kk_unit_t wild__, kk_context_t* _ctx); /* forall<_h,h1,e> (x : int32, wild_ : ()) -> <local<h1>,local<_h>|e> int32 */ 

int32_t kk_std_num_random__mlift1391_pseudo_random(kk_ref_t s, kk_std_num_random__sfc _y_4, kk_context_t* _ctx); /* forall<_h,h1,e> (s : local-var<h1,sfc>, sfc) -> <local<h1>,local<_h>|e> int32 */ 

kk_box_t kk_std_num_random_pseudo_random(kk_integer_t seed, kk_function_t action, kk_context_t* _ctx); /* forall<a,e> (seed : int, action : () -> <random|e> a) -> e a */ 

bool kk_std_num_random__mlift1392_random_bool(int32_t _y_12, kk_context_t* _ctx); /* (int32) -> random bool */ 

bool kk_std_num_random_random_bool(kk_context_t* _ctx); /* () -> random bool */ 

double kk_std_num_random__mlift1393_random_double(int32_t lo, int32_t _y_14, kk_context_t* _ctx); /* (lo : int32, int32) -> random double */ 

double kk_std_num_random__mlift1394_random_double(int32_t lo, kk_context_t* _ctx); /* (lo : int32) -> random double */ 

double kk_std_num_random_random_double(kk_context_t* _ctx); /* () -> random double */ 

kk_integer_t kk_std_num_random__mlift1395_random_int(int32_t _y_15, kk_context_t* _ctx); /* (int32) -> random int */ 

kk_integer_t kk_std_num_random_random_int(kk_context_t* _ctx); /* () -> random int */ 

double kk_std_num_random_srandom_double_range(double lo, double hi, kk_context_t* _ctx); /* (lo : double, hi : double) -> ndet double */ 
 
// Return a strong random integer in the range [-2^^31^^, 2^^31^^).

static inline kk_integer_t kk_std_num_random_srandom_int(kk_context_t* _ctx) { /* () -> ndet int */ 
  int32_t _x1653 = kk_std_num_random_srandom_int32(_ctx); /*int32*/
  return kk_integer_from_int(_x1653,kk_context());
}

void kk_std_num_random__init(kk_context_t* _ctx);

#endif // header
