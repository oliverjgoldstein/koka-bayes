// Koka generated module: "std/num/random", koka version: 2.1.2
#include "std_num_random.h"
 
// runtime tag for the `:random` effect

kk_std_core_hnd__htag kk_std_num_random__tag_random;
 
// handler for the `:random` effect

kk_box_t kk_std_num_random__handle_random(int32_t cfc, kk_std_num_random__hnd_random hnd, kk_function_t ret, kk_function_t action, kk_context_t* _ctx) { /* forall<a,e,b> (cfc : int32, hnd : .hnd-random<e,b>, ret : (res : a) -> e b, action : () -> <random|e> a) -> e b */ 
  kk_std_core_hnd__htag _x1566 = kk_std_core_hnd__htag_dup(kk_std_num_random__tag_random); /*std/core/hnd/htag<std/num/random/.hnd-random>*/
  return kk_std_core_hnd__hhandle(_x1566, cfc, kk_std_num_random__hnd_random_box(hnd, _ctx), ret, action, _ctx);
}
 
// Return a strong random `:int32`

int32_t kk_std_num_random_srandom_int32(kk_context_t* _ctx) { /* () -> ndet int32 */ 
  return (int32_t)kk_srandom_uint32(kk_context());
}

kk_std_core_types__tuple2_ kk_std_num_random_sfc_step(kk_std_num_random__sfc sfc, kk_context_t* _ctx) { /* (sfc : sfc) -> (int32, sfc) */ 
  int32_t x0 = sfc.x;
  int32_t y0 = sfc.y;
  int32_t z0 = sfc.z;
  int32_t cnt0 = sfc.cnt;
  int32_t res;
  int32_t _x1567 = (x0 + y0); /*int32*/
  res = (_x1567 + cnt0); /*int32*/
  kk_std_num_random__sfc _b_1453_1451;
  int32_t _x1568;
  int32_t _x1569 = ((int32_t)((uint32_t)y0 >> (((int32_t)9)))); /*int32*/
  _x1568 = (y0 ^ _x1569); /*int32*/
  int32_t _x1570;
  int32_t _x1571 = (z0 << (((int32_t)3))); /*int32*/
  _x1570 = (z0 + _x1571); /*int32*/
  int32_t _x1572;
  int32_t _x1573 = kk_std_num_int32_rotl(z0, ((int32_t)21), _ctx); /*int32*/
  _x1572 = (_x1573 + res); /*int32*/
  int32_t _x1574 = (cnt0 + (((int32_t)1))); /*int32*/
  _b_1453_1451 = kk_std_num_random__new_Sfc(_x1568, _x1570, _x1572, _x1574, _ctx); /*std/num/random/sfc*/
  return kk_std_core_types__new_dash__lp__comma__rp_(kk_int32_box(res, _ctx), kk_std_num_random__sfc_box(_b_1453_1451, _ctx), _ctx);
}
 
// Return a strong random `:double` in the range [0,1) using 52-bits of randomness

double kk_std_num_random_srandom_double(kk_context_t* _ctx) { /* () -> ndet double */ 
  return kk_srandom_double(kk_context());
}
 
// Return a strong random `:int32` uniformly distributed in the range [lo,hi)

int32_t kk_std_num_random_srandom_int32_range(int32_t lo, int32_t hi, kk_context_t* _ctx) { /* (lo : int32, hi : int32) -> ndet int32 */ 
  return kk_srandom_range_int32(lo,hi,kk_context());
}
 
// Are the strong random numbers generated from a strong random source? (like /dev/urandom)

bool kk_std_num_random_srandom_is_strong(kk_context_t* _ctx) { /* () -> ndet bool */ 
  return kk_srandom_is_strong(kk_context());
}
 
// Pick random numbers from a the best strong random source in the OS.
// (e.g. like `/dev/urandom`, `arc4random` etc.). Use `srandom-is-strong` to test if the
// numbers are indeed based on a strong random source.


// lift anonymous function
struct kk_std_num_random_strong_random_fun1582__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_random_strong_random_fun1582(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_random_new_strong_random_fun1582(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_random_strong_random_fun1582, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_random_strong_random_fun1582(kk_function_t _fself, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  int32_t _x1583 = kk_std_num_random_srandom_int32(_ctx); /*int32*/
  return kk_int32_box(_x1583, _ctx);
}


// lift anonymous function
struct kk_std_num_random_strong_random_fun1584__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_random_strong_random_fun1584(kk_function_t _fself, kk_box_t _x, kk_context_t* _ctx);
static kk_function_t kk_std_num_random_new_strong_random_fun1584(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_random_strong_random_fun1584, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_random_strong_random_fun1584(kk_function_t _fself, kk_box_t _x, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return _x;
}

kk_box_t kk_std_num_random_strong_random(kk_function_t action, kk_context_t* _ctx) { /* forall<a,e> (action : () -> <random,ndet|e> a) -> <ndet|e> a */ 
  kk_std_num_random__hnd_random _x1580;
  kk_std_core_hnd__clause0 _x1581 = kk_std_core_hnd_clause_tail_noyield0(kk_std_num_random_new_strong_random_fun1582(_ctx), _ctx); /*std/core/hnd/clause0<8685,8686,8683,8684>*/
  _x1580 = kk_std_num_random__new_Hnd_random(kk_reuse_null, _x1581, _ctx); /*std/num/random/.hnd-random<6,7>*/
  return kk_std_num_random__handle_random(((int32_t)1), _x1580, kk_std_num_random_new_strong_random_fun1584(_ctx), action, _ctx);
}


// lift anonymous function
struct kk_std_num_random_sfc_init_fun1592__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_random_sfc_init_fun1592(kk_function_t _fself, int32_t _b_1470, kk_box_t _b_1471, kk_context_t* _ctx);
static kk_function_t kk_std_num_random_new_sfc_init_fun1592(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_random_sfc_init_fun1592, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_random_sfc_init_fun1592(kk_function_t _fself, int32_t _b_1470, kk_box_t _b_1471, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_num_random__sfc _x1593;
  kk_std_core_types__tuple2_ _this_1403;
  kk_std_num_random__sfc _x1594 = kk_std_num_random__sfc_unbox(_b_1471, _ctx); /*std/num/random/sfc*/
  _this_1403 = kk_std_num_random_sfc_step(_x1594, _ctx); /*(int32, std/num/random/sfc)*/
  kk_box_t _box_x1464 = _this_1403.fst;
  kk_box_t _box_x1465 = _this_1403.snd;
  kk_std_num_random__sfc _x = kk_std_num_random__sfc_unbox(_box_x1465, NULL);
  kk_std_core_types__tuple2__drop(_this_1403, _ctx);
  _x1593 = _x; /*std/num/random/sfc*/
  return kk_std_num_random__sfc_box(_x1593, _ctx);
}

kk_std_num_random__sfc kk_std_num_random_sfc_init(kk_integer_t seed, kk_context_t* _ctx) { /* (seed : int) -> sfc */ 
  kk_std_num_random__sfc sfc0;
  int32_t _x1587;
  kk_integer_t _x1588 = kk_integer_dup(seed); /*int*/
  _x1587 = kk_std_core_int32(_x1588, _ctx); /*int32*/
  int32_t _x1589;
  kk_integer_t _x1590 = kk_integer_div(seed,(kk_integer_from_str("4294967296", _ctx)),kk_context()); /*int*/
  _x1589 = kk_std_core_int32(_x1590, _ctx); /*int32*/
  sfc0 = kk_std_num_random__new_Sfc(((int32_t)0), _x1587, _x1589, ((int32_t)1), _ctx); /*std/num/random/sfc*/
  int32_t _b_1472_1466 = ((int32_t)0); /*int32*/;
  int32_t _b_1473_1467 = ((int32_t)12); /*int32*/;
  kk_box_t _x1591 = kk_std_num_int32_fold_int32(_b_1472_1466, _b_1473_1467, kk_std_num_random__sfc_box(sfc0, _ctx), kk_std_num_random_new_sfc_init_fun1592(_ctx), _ctx); /*1536*/
  return kk_std_num_random__sfc_unbox(_x1591, _ctx);
}
 
// monadic lift

int32_t kk_std_num_random__mlift1390_pseudo_random(int32_t x0, kk_unit_t wild__, kk_context_t* _ctx) { /* forall<_h,h1,e> (x : int32, wild_ : ()) -> <local<h1>,local<_h>|e> int32 */ 
  return x0;
}
 
// monadic lift


// lift anonymous function
struct kk_std_num_random__mlift1391_pseudo_random_fun1600__t {
  struct kk_function_s _base;
  int32_t x0;
};
static kk_box_t kk_std_num_random__mlift1391_pseudo_random_fun1600(kk_function_t _fself, kk_box_t _b_1485, kk_context_t* _ctx);
static kk_function_t kk_std_num_random__new_mlift1391_pseudo_random_fun1600(int32_t x0, kk_context_t* _ctx) {
  struct kk_std_num_random__mlift1391_pseudo_random_fun1600__t* _self = kk_function_alloc_as(struct kk_std_num_random__mlift1391_pseudo_random_fun1600__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_num_random__mlift1391_pseudo_random_fun1600, kk_context());
  _self->x0 = x0;
  return &_self->_base;
}

static kk_box_t kk_std_num_random__mlift1391_pseudo_random_fun1600(kk_function_t _fself, kk_box_t _b_1485, kk_context_t* _ctx) {
  struct kk_std_num_random__mlift1391_pseudo_random_fun1600__t* _self = kk_function_as(struct kk_std_num_random__mlift1391_pseudo_random_fun1600__t*, _fself);
  int32_t x0 = _self->x0; /* int32 */
  kk_drop_match(_self, {;}, {}, _ctx)
  int32_t _x1601;
  kk_unit_t _x1602 = kk_Unit;
  kk_unit_unbox(_b_1485);
  _x1601 = kk_std_num_random__mlift1390_pseudo_random(x0, _x1602, _ctx); /*int32*/
  return kk_int32_box(_x1601, _ctx);
}

int32_t kk_std_num_random__mlift1391_pseudo_random(kk_ref_t s, kk_std_num_random__sfc _y_4, kk_context_t* _ctx) { /* forall<_h,h1,e> (s : local-var<h1,sfc>, sfc) -> <local<h1>,local<_h>|e> int32 */ 
  kk_std_core_types__tuple2_ _match_1547 = kk_std_num_random_sfc_step(_y_4, _ctx); /*(int32, std/num/random/sfc)*/;
  kk_box_t _box_x1478 = _match_1547.fst;
  kk_box_t _box_x1479 = _match_1547.snd;
  int32_t x0 = kk_int32_unbox(_box_x1478, NULL);
  kk_std_num_random__sfc sfc = kk_std_num_random__sfc_unbox(_box_x1479, NULL);
  kk_unit_t x0_1404 = kk_Unit;
  (kk_ref_set(s,(kk_std_num_random__sfc_box(sfc, _ctx)),kk_context()));
  if (kk_yielding(kk_context())) {
    kk_box_t _x1599 = kk_std_core_hnd_yield_extend(kk_std_num_random__new_mlift1391_pseudo_random_fun1600(x0, _ctx), _ctx); /*3991*/
    return kk_int32_unbox(_x1599, _ctx);
  }
  return kk_std_num_random__mlift1390_pseudo_random(x0, x0_1404, _ctx);
}
 
// Use pseudo random numbers given some initial `seed`. At most
// 64-bits of the initial seed are used. Do not use this for
// cryptographic applications (use `strong-random` instead).
// Uses _sfc32_ by Chris Doty-Humphrey which is a fast random
// number generator with a 128-bit internal state which
// passes PractRand and BigCrush. The worst case minimum cycle
// is 2^^32^^, where a potential cycle of 2^^48^^ has a chance
// of 2^^-80^^.


// lift anonymous function
struct kk_std_num_random_pseudo_random_fun1606__t {
  struct kk_function_s _base;
  kk_ref_t loc;
};
static kk_box_t kk_std_num_random_pseudo_random_fun1606(kk_function_t _fself, kk_std_core_hnd__marker _b_1495, kk_std_core_hnd__ev _b_1496, kk_context_t* _ctx);
static kk_function_t kk_std_num_random_new_pseudo_random_fun1606(kk_ref_t loc, kk_context_t* _ctx) {
  struct kk_std_num_random_pseudo_random_fun1606__t* _self = kk_function_alloc_as(struct kk_std_num_random_pseudo_random_fun1606__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_num_random_pseudo_random_fun1606, kk_context());
  _self->loc = loc;
  return &_self->_base;
}



// lift anonymous function
struct kk_std_num_random_pseudo_random_fun1611__t {
  struct kk_function_s _base;
  kk_ref_t loc;
};
static kk_box_t kk_std_num_random_pseudo_random_fun1611(kk_function_t _fself, kk_box_t _b_1493, kk_context_t* _ctx);
static kk_function_t kk_std_num_random_new_pseudo_random_fun1611(kk_ref_t loc, kk_context_t* _ctx) {
  struct kk_std_num_random_pseudo_random_fun1611__t* _self = kk_function_alloc_as(struct kk_std_num_random_pseudo_random_fun1611__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_num_random_pseudo_random_fun1611, kk_context());
  _self->loc = loc;
  return &_self->_base;
}

static kk_box_t kk_std_num_random_pseudo_random_fun1611(kk_function_t _fself, kk_box_t _b_1493, kk_context_t* _ctx) {
  struct kk_std_num_random_pseudo_random_fun1611__t* _self = kk_function_as(struct kk_std_num_random_pseudo_random_fun1611__t*, _fself);
  kk_ref_t loc = _self->loc; /* local-var<global,std/num/random/sfc> */
  kk_drop_match(_self, {kk_ref_dup(loc);}, {}, _ctx)
  int32_t _x1612;
  kk_std_num_random__sfc _x1613 = kk_std_num_random__sfc_unbox(_b_1493, _ctx); /*std/num/random/sfc*/
  _x1612 = kk_std_num_random__mlift1391_pseudo_random(loc, _x1613, _ctx); /*int32*/
  return kk_int32_box(_x1612, _ctx);
}
static kk_box_t kk_std_num_random_pseudo_random_fun1606(kk_function_t _fself, kk_std_core_hnd__marker _b_1495, kk_std_core_hnd__ev _b_1496, kk_context_t* _ctx) {
  struct kk_std_num_random_pseudo_random_fun1606__t* _self = kk_function_as(struct kk_std_num_random_pseudo_random_fun1606__t*, _fself);
  kk_ref_t loc = _self->loc; /* local-var<global,std/num/random/sfc> */
  kk_drop_match(_self, {kk_ref_dup(loc);}, {}, _ctx)
  kk_std_core_hnd__ev_dropn(_b_1496, ((int32_t)3), _ctx);
  int32_t _x1607;
  kk_std_num_random__sfc x_1411;
  kk_box_t _x1608;
  kk_ref_t _x1609 = kk_ref_dup(loc); /*local-var<global,std/num/random/sfc>*/
  _x1608 = (kk_ref_get(_x1609,kk_context())); /*228*/
  x_1411 = kk_std_num_random__sfc_unbox(_x1608, _ctx); /*std/num/random/sfc*/
  if (kk_yielding(kk_context())) {
    kk_box_t _x1610 = kk_std_core_hnd_yield_extend(kk_std_num_random_new_pseudo_random_fun1611(loc, _ctx), _ctx); /*3991*/
    _x1607 = kk_int32_unbox(_x1610, _ctx); /*int32*/
  }
  else {
    _x1607 = kk_std_num_random__mlift1391_pseudo_random(loc, x_1411, _ctx); /*int32*/
  }
  return kk_int32_box(_x1607, _ctx);
}


// lift anonymous function
struct kk_std_num_random_pseudo_random_fun1614__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_random_pseudo_random_fun1614(kk_function_t _fself, kk_box_t _x, kk_context_t* _ctx);
static kk_function_t kk_std_num_random_new_pseudo_random_fun1614(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_random_pseudo_random_fun1614, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_random_pseudo_random_fun1614(kk_function_t _fself, kk_box_t _x, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return _x;
}


// lift anonymous function
struct kk_std_num_random_pseudo_random_fun1615__t {
  struct kk_function_s _base;
  kk_function_t action;
};
static kk_box_t kk_std_num_random_pseudo_random_fun1615(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_random_new_pseudo_random_fun1615(kk_function_t action, kk_context_t* _ctx) {
  struct kk_std_num_random_pseudo_random_fun1615__t* _self = kk_function_alloc_as(struct kk_std_num_random_pseudo_random_fun1615__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_num_random_pseudo_random_fun1615, kk_context());
  _self->action = action;
  return &_self->_base;
}

static kk_box_t kk_std_num_random_pseudo_random_fun1615(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_num_random_pseudo_random_fun1615__t* _self = kk_function_as(struct kk_std_num_random_pseudo_random_fun1615__t*, _fself);
  kk_function_t action = _self->action; /* () -> <std/num/random/random|972> 971 */
  kk_drop_match(_self, {kk_function_dup(action);}, {}, _ctx)
  return kk_std_core_hnd__mask_builtin(action, _ctx);
}

kk_box_t kk_std_num_random_pseudo_random(kk_integer_t seed, kk_function_t action, kk_context_t* _ctx) { /* forall<a,e> (seed : int, action : () -> <random|e> a) -> e a */ 
  kk_std_num_random__sfc init_1407 = kk_std_num_random_sfc_init(seed, _ctx); /*std/num/random/sfc*/;
  kk_ref_t loc = kk_ref_alloc((kk_std_num_random__sfc_box(init_1407, _ctx)),kk_context()); /*local-var<global,std/num/random/sfc>*/;
  kk_box_t res;
  kk_std_num_random__hnd_random _x1603;
  kk_std_core_hnd__clause0 _x1604;
  kk_function_t _x1605;
  kk_ref_dup(loc);
  _x1605 = kk_std_num_random_new_pseudo_random_fun1606(loc, _ctx); /*(std/core/hnd/marker<39,40>, std/core/hnd/ev<38>) -> 39 37*/
  _x1604 = kk_std_core_hnd__new_Clause0(_x1605, _ctx); /*std/core/hnd/clause0<37,38,39,40>*/
  _x1603 = kk_std_num_random__new_Hnd_random(kk_reuse_null, _x1604, _ctx); /*std/num/random/.hnd-random<6,7>*/
  res = kk_std_num_random__handle_random(((int32_t)1), _x1603, kk_std_num_random_new_pseudo_random_fun1614(_ctx), kk_std_num_random_new_pseudo_random_fun1615(action, _ctx), _ctx); /*971*/
  return kk_std_core_hnd_prompt_local_var(loc, res, _ctx);
}
 
// monadic lift

bool kk_std_num_random__mlift1392_random_bool(int32_t _y_12, kk_context_t* _ctx) { /* (int32) -> random bool */ 
  return (_y_12 >= (((int32_t)0)));
}
 
// Return a random boolean


// lift anonymous function
struct kk_std_num_random_random_bool_fun1617__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_random_random_bool_fun1617(kk_function_t _fself, kk_box_t _b_1503, kk_context_t* _ctx);
static kk_function_t kk_std_num_random_new_random_bool_fun1617(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_random_random_bool_fun1617, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_random_random_bool_fun1617(kk_function_t _fself, kk_box_t _b_1503, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  bool _x1618;
  int32_t _x1619 = kk_int32_unbox(_b_1503, _ctx); /*int32*/
  _x1618 = kk_std_num_random__mlift1392_random_bool(_x1619, _ctx); /*bool*/
  return kk_bool_box(_x1618);
}

bool kk_std_num_random_random_bool(kk_context_t* _ctx) { /* () -> random bool */ 
  int32_t x_1414 = kk_std_num_random_random_int32(_ctx); /*int32*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x1616 = kk_std_core_hnd_yield_extend(kk_std_num_random_new_random_bool_fun1617(_ctx), _ctx); /*3991*/
    return kk_bool_unbox(_x1616);
  }
  return (x_1414 >= (((int32_t)0)));
}
 
// monadic lift


// lift anonymous function
struct kk_std_num_random__mlift1393_random_double_fun1623__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_random__mlift1393_random_double_fun1623(kk_function_t _fself, kk_box_t _b_1508, kk_box_t _b_1509, kk_context_t* _ctx);
static kk_function_t kk_std_num_random__new_mlift1393_random_double_fun1623(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_random__mlift1393_random_double_fun1623, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_random__mlift1393_random_double_fun1623(kk_function_t _fself, kk_box_t _b_1508, kk_box_t _b_1509, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x1624;
  int32_t _x1625 = kk_int32_unbox(_b_1508, _ctx); /*int32*/
  int32_t _x1626 = kk_int32_unbox(_b_1509, _ctx); /*int32*/
  _x1624 = kk_std_num_double_double_from_bits(_x1625, _x1626, _ctx); /*double*/
  return kk_double_box(_x1624, _ctx);
}

double kk_std_num_random__mlift1393_random_double(int32_t lo, int32_t _y_14, kk_context_t* _ctx) { /* (lo : int32, int32) -> random double */ 
  int32_t hi;
  int32_t _x1620 = ((int32_t)((uint32_t)_y_14 >> (((int32_t)12)))); /*int32*/
  hi = (_x1620 | (((int32_t)1072693248))); /*int32*/
  double _x1621;
  kk_box_t _x1622 = kk_std_core_hnd__open_none2(kk_std_num_random__new_mlift1393_random_double_fun1623(_ctx), kk_int32_box(lo, _ctx), kk_int32_box(hi, _ctx), _ctx); /*3333*/
  _x1621 = kk_double_unbox(_x1622, _ctx); /*double*/
  return (_x1621 - 0x1p0);
}
 
// monadic lift


// lift anonymous function
struct kk_std_num_random__mlift1394_random_double_fun1628__t {
  struct kk_function_s _base;
  int32_t lo;
};
static kk_box_t kk_std_num_random__mlift1394_random_double_fun1628(kk_function_t _fself, kk_box_t _b_1514, kk_context_t* _ctx);
static kk_function_t kk_std_num_random__new_mlift1394_random_double_fun1628(int32_t lo, kk_context_t* _ctx) {
  struct kk_std_num_random__mlift1394_random_double_fun1628__t* _self = kk_function_alloc_as(struct kk_std_num_random__mlift1394_random_double_fun1628__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_num_random__mlift1394_random_double_fun1628, kk_context());
  _self->lo = lo;
  return &_self->_base;
}

static kk_box_t kk_std_num_random__mlift1394_random_double_fun1628(kk_function_t _fself, kk_box_t _b_1514, kk_context_t* _ctx) {
  struct kk_std_num_random__mlift1394_random_double_fun1628__t* _self = kk_function_as(struct kk_std_num_random__mlift1394_random_double_fun1628__t*, _fself);
  int32_t lo = _self->lo; /* int32 */
  kk_drop_match(_self, {;}, {}, _ctx)
  double _x1629;
  int32_t _x1630 = kk_int32_unbox(_b_1514, _ctx); /*int32*/
  _x1629 = kk_std_num_random__mlift1393_random_double(lo, _x1630, _ctx); /*double*/
  return kk_double_box(_x1629, _ctx);
}

double kk_std_num_random__mlift1394_random_double(int32_t lo, kk_context_t* _ctx) { /* (lo : int32) -> random double */ 
  int32_t x_1418 = kk_std_num_random_random_int32(_ctx); /*int32*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x1627 = kk_std_core_hnd_yield_extend(kk_std_num_random__new_mlift1394_random_double_fun1628(lo, _ctx), _ctx); /*3991*/
    return kk_double_unbox(_x1627, _ctx);
  }
  return kk_std_num_random__mlift1393_random_double(lo, x_1418, _ctx);
}
 
// Return a random double in the range [0,1) using 52-bits of randomness


// lift anonymous function
struct kk_std_num_random_random_double_fun1632__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_random_random_double_fun1632(kk_function_t _fself, kk_box_t _b_1518, kk_context_t* _ctx);
static kk_function_t kk_std_num_random_new_random_double_fun1632(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_random_random_double_fun1632, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_random_random_double_fun1632(kk_function_t _fself, kk_box_t _b_1518, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x1633;
  int32_t _x1634 = kk_int32_unbox(_b_1518, _ctx); /*int32*/
  _x1633 = kk_std_num_random__mlift1394_random_double(_x1634, _ctx); /*double*/
  return kk_double_box(_x1633, _ctx);
}


// lift anonymous function
struct kk_std_num_random_random_double_fun1636__t {
  struct kk_function_s _base;
  int32_t x_1420;
};
static kk_box_t kk_std_num_random_random_double_fun1636(kk_function_t _fself, kk_box_t _b_1520, kk_context_t* _ctx);
static kk_function_t kk_std_num_random_new_random_double_fun1636(int32_t x_1420, kk_context_t* _ctx) {
  struct kk_std_num_random_random_double_fun1636__t* _self = kk_function_alloc_as(struct kk_std_num_random_random_double_fun1636__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_num_random_random_double_fun1636, kk_context());
  _self->x_1420 = x_1420;
  return &_self->_base;
}

static kk_box_t kk_std_num_random_random_double_fun1636(kk_function_t _fself, kk_box_t _b_1520, kk_context_t* _ctx) {
  struct kk_std_num_random_random_double_fun1636__t* _self = kk_function_as(struct kk_std_num_random_random_double_fun1636__t*, _fself);
  int32_t x_1420 = _self->x_1420; /* int32 */
  kk_drop_match(_self, {;}, {}, _ctx)
  double _x1637;
  int32_t _x1638 = kk_int32_unbox(_b_1520, _ctx); /*int32*/
  _x1637 = kk_std_num_random__mlift1393_random_double(x_1420, _x1638, _ctx); /*double*/
  return kk_double_box(_x1637, _ctx);
}


// lift anonymous function
struct kk_std_num_random_random_double_fun1642__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_random_random_double_fun1642(kk_function_t _fself, kk_box_t _b_1524, kk_box_t _b_1525, kk_context_t* _ctx);
static kk_function_t kk_std_num_random_new_random_double_fun1642(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_random_random_double_fun1642, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_random_random_double_fun1642(kk_function_t _fself, kk_box_t _b_1524, kk_box_t _b_1525, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x1643;
  int32_t _x1644 = kk_int32_unbox(_b_1524, _ctx); /*int32*/
  int32_t _x1645 = kk_int32_unbox(_b_1525, _ctx); /*int32*/
  _x1643 = kk_std_num_double_double_from_bits(_x1644, _x1645, _ctx); /*double*/
  return kk_double_box(_x1643, _ctx);
}

double kk_std_num_random_random_double(kk_context_t* _ctx) { /* () -> random double */ 
  int32_t x_1420 = kk_std_num_random_random_int32(_ctx); /*int32*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x1631 = kk_std_core_hnd_yield_extend(kk_std_num_random_new_random_double_fun1632(_ctx), _ctx); /*3991*/
    return kk_double_unbox(_x1631, _ctx);
  }
  int32_t x0_1424 = kk_std_num_random_random_int32(_ctx); /*int32*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x1635 = kk_std_core_hnd_yield_extend(kk_std_num_random_new_random_double_fun1636(x_1420, _ctx), _ctx); /*3991*/
    return kk_double_unbox(_x1635, _ctx);
  }
  int32_t hi;
  int32_t _x1639 = ((int32_t)((uint32_t)x0_1424 >> (((int32_t)12)))); /*int32*/
  hi = (_x1639 | (((int32_t)1072693248))); /*int32*/
  double _x1640;
  kk_box_t _x1641 = kk_std_core_hnd__open_none2(kk_std_num_random_new_random_double_fun1642(_ctx), kk_int32_box(x_1420, _ctx), kk_int32_box(hi, _ctx), _ctx); /*3333*/
  _x1640 = kk_double_unbox(_x1641, _ctx); /*double*/
  return (_x1640 - 0x1p0);
}
 
// monadic lift

kk_integer_t kk_std_num_random__mlift1395_random_int(int32_t _y_15, kk_context_t* _ctx) { /* (int32) -> random int */ 
  return kk_integer_from_int(_y_15,kk_context());
}
 
// Return a random integer in the range [-2^^31^^, 2^^31^^).


// lift anonymous function
struct kk_std_num_random_random_int_fun1647__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_random_random_int_fun1647(kk_function_t _fself, kk_box_t _b_1533, kk_context_t* _ctx);
static kk_function_t kk_std_num_random_new_random_int_fun1647(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_random_random_int_fun1647, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_random_random_int_fun1647(kk_function_t _fself, kk_box_t _b_1533, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_integer_t _x1648;
  int32_t _x1649 = kk_int32_unbox(_b_1533, _ctx); /*int32*/
  _x1648 = kk_std_num_random__mlift1395_random_int(_x1649, _ctx); /*int*/
  return kk_integer_box(_x1648);
}

kk_integer_t kk_std_num_random_random_int(kk_context_t* _ctx) { /* () -> random int */ 
  int32_t x_1428 = kk_std_num_random_random_int32(_ctx); /*int32*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x1646 = kk_std_core_hnd_yield_extend(kk_std_num_random_new_random_int_fun1647(_ctx), _ctx); /*3991*/
    return kk_integer_unbox(_x1646);
  }
  return kk_integer_from_int(x_1428,kk_context());
}
 
// Generate a strong random double uniformly distributed in the range [lo, hi)

double kk_std_num_random_srandom_double_range(double lo, double hi, kk_context_t* _ctx) { /* (lo : double, hi : double) -> ndet double */ 
  double low;
  bool _match_1540 = (lo <= hi); /*bool*/;
  if (_match_1540) {
    low = lo; /*double*/
  }
  else {
    low = hi; /*double*/
  }
  double high;
  bool _match_1539 = (lo <= hi); /*bool*/;
  if (_match_1539) {
    high = hi; /*double*/
  }
  else {
    high = lo; /*double*/
  }
  double x0;
  double _x1650;
  double _x1651 = (high - low); /*double*/
  double _x1652 = kk_std_num_random_srandom_double(_ctx); /*double*/
  _x1650 = (_x1651 * _x1652); /*double*/
  x0 = (_x1650 + low); /*double*/
  bool _match_1538 = (x0 >= high); /*bool*/;
  if (_match_1538) {
    return low;
  }
  return x0;
}

// initialization
void kk_std_num_random__init(kk_context_t* _ctx){
  static bool _initialized = false;
  if (_initialized) return;
  _initialized = true;
  kk_std_core_types__init(_ctx);
  kk_std_core_hnd__init(_ctx);
  kk_std_core__init(_ctx);
  kk_std_num_int32__init(_ctx);
  kk_std_num_double__init(_ctx);
  {
    kk_string_t _x1564;
    kk_define_string_literal(, _s1565, 13, "random.random")
    _x1564 = kk_string_dup(_s1565); /*string*/
    kk_std_num_random__tag_random = kk_std_core_hnd__new_Htag(_x1564, _ctx); /*std/core/hnd/htag<std/num/random/.hnd-random>*/
  }
}
