// Koka generated module: "std/core/types", koka version: 2.1.3
#include "std_core_types.h"

kk_std_core_types__tuple2_ kk_std_core_types__copy_1(kk_std_core_types__tuple2_ _this, kk_std_core_types__optional fst0, kk_std_core_types__optional snd0, kk_context_t* _ctx) { /* forall<a,b> ((a, b), fst : optional<a>, snd : optional<b>) -> (a, b) */ 
  kk_box_t _x2591;
  if (kk_std_core_types__is_Optional(fst0)) {
    kk_box_t _fst_392 = fst0._cons.Optional.value;
    _x2591 = _fst_392; /*413*/
  }
  else {
    kk_box_t _x = _this.fst;
    kk_box_dup(_x);
    _x2591 = _x; /*413*/
  }
  kk_box_t _x2592;
  if (kk_std_core_types__is_Optional(snd0)) {
    kk_box_t _snd_400 = snd0._cons.Optional.value;
    kk_std_core_types__tuple2__drop(_this, _ctx);
    _x2592 = _snd_400; /*414*/
  }
  else {
    kk_box_t _x0 = _this.snd;
    kk_box_dup(_x0);
    kk_std_core_types__tuple2__drop(_this, _ctx);
    _x2592 = _x0; /*414*/
  }
  return kk_std_core_types__new_dash__lp__comma__rp_(_x2591, _x2592, _ctx);
}

kk_std_core_types__tuple3_ kk_std_core_types__copy_2(kk_std_core_types__tuple3_ _this, kk_std_core_types__optional fst0, kk_std_core_types__optional snd0, kk_std_core_types__optional thd0, kk_context_t* _ctx) { /* forall<a,b,c> ((a, b, c), fst : optional<a>, snd : optional<b>, thd : optional<c>) -> (a, b, c) */ 
  kk_box_t _x2593;
  if (kk_std_core_types__is_Optional(fst0)) {
    kk_box_t _fst_584 = fst0._cons.Optional.value;
    _x2593 = _fst_584; /*651*/
  }
  else {
    kk_box_t _x = _this.fst;
    kk_box_dup(_x);
    _x2593 = _x; /*651*/
  }
  kk_box_t _x2594;
  if (kk_std_core_types__is_Optional(snd0)) {
    kk_box_t _snd_625 = snd0._cons.Optional.value;
    _x2594 = _snd_625; /*652*/
  }
  else {
    kk_box_t _x0 = _this.snd;
    kk_box_dup(_x0);
    _x2594 = _x0; /*652*/
  }
  kk_box_t _x2595;
  if (kk_std_core_types__is_Optional(thd0)) {
    kk_box_t _thd_634 = thd0._cons.Optional.value;
    kk_std_core_types__tuple3__drop(_this, _ctx);
    _x2595 = _thd_634; /*653*/
  }
  else {
    kk_box_t _x1 = _this.thd;
    kk_box_dup(_x1);
    kk_std_core_types__tuple3__drop(_this, _ctx);
    _x2595 = _x1; /*653*/
  }
  return kk_std_core_types__new_dash__lp__comma__comma__rp_(_x2593, _x2594, _x2595, _ctx);
}

kk_std_core_types__tuple4_ kk_std_core_types__copy_3(kk_std_core_types__tuple4_ _this, kk_std_core_types__optional fst0, kk_std_core_types__optional snd0, kk_std_core_types__optional thd0, kk_std_core_types__optional field40, kk_context_t* _ctx) { /* forall<a,b,c,d> ((a, b, c, d), fst : optional<a>, snd : optional<b>, thd : optional<c>, field4 : optional<d>) -> (a, b, c, d) */ 
  kk_box_t _x2600;
  if (kk_std_core_types__is_Optional(fst0)) {
    kk_box_t _fst_981 = fst0._cons.Optional.value;
    _x2600 = _fst_981; /*1127*/
  }
  else {
    struct kk_std_core_types__Tuple4_* _con2601 = kk_std_core_types__as_dash__lp__comma__comma__comma__rp_(_this);
    kk_box_t _x = _con2601->fst;
    kk_box_dup(_x);
    _x2600 = _x; /*1127*/
  }
  kk_box_t _x2602;
  if (kk_std_core_types__is_Optional(snd0)) {
    kk_box_t _snd_1045 = snd0._cons.Optional.value;
    _x2602 = _snd_1045; /*1128*/
  }
  else {
    struct kk_std_core_types__Tuple4_* _con2603 = kk_std_core_types__as_dash__lp__comma__comma__comma__rp_(_this);
    kk_box_t _x0 = _con2603->snd;
    kk_box_dup(_x0);
    _x2602 = _x0; /*1128*/
  }
  kk_box_t _x2604;
  if (kk_std_core_types__is_Optional(thd0)) {
    kk_box_t _thd_1096 = thd0._cons.Optional.value;
    _x2604 = _thd_1096; /*1129*/
  }
  else {
    struct kk_std_core_types__Tuple4_* _con2605 = kk_std_core_types__as_dash__lp__comma__comma__comma__rp_(_this);
    kk_box_t _x1 = _con2605->thd;
    kk_box_dup(_x1);
    _x2604 = _x1; /*1129*/
  }
  kk_box_t _x2606;
  if (kk_std_core_types__is_Optional(field40)) {
    kk_box_t _field4_1106 = field40._cons.Optional.value;
    kk_std_core_types__tuple4__dropn(_this, ((int32_t)4), _ctx);
    _x2606 = _field4_1106; /*1130*/
  }
  else {
    struct kk_std_core_types__Tuple4_* _con2607 = kk_std_core_types__as_dash__lp__comma__comma__comma__rp_(_this);
    kk_box_t _pat03 = _con2607->fst;
    kk_box_t _pat14 = _con2607->snd;
    kk_box_t _pat23 = _con2607->thd;
    kk_box_t _x2 = _con2607->field4;
    if (kk_std_core_types__tuple4__is_unique(_this)) {
      kk_box_drop(_pat23, _ctx);
      kk_box_drop(_pat14, _ctx);
      kk_box_drop(_pat03, _ctx);
      kk_std_core_types__tuple4__free(_this);
    }
    else {
      kk_box_dup(_x2);
      kk_std_core_types__tuple4__decref(_this, _ctx);
    }
    _x2606 = _x2; /*1130*/
  }
  return kk_std_core_types__new_dash__lp__comma__comma__comma__rp_(kk_reuse_null, _x2600, _x2602, _x2604, _x2606, _ctx);
}

kk_std_core_types___lp__comma__comma__comma__comma__rp_ kk_std_core_types__copy_4(kk_std_core_types___lp__comma__comma__comma__comma__rp_ _this, kk_std_core_types__optional fst0, kk_std_core_types__optional snd0, kk_std_core_types__optional thd0, kk_std_core_types__optional field40, kk_std_core_types__optional field50, kk_context_t* _ctx) { /* forall<a,b,c,d,a1> ((a, b, c, d, a1), fst : optional<a>, snd : optional<b>, thd : optional<c>, field4 : optional<d>, field5 : optional<a1>) -> (a, b, c, d, a1) */ 
  kk_box_t _x2613;
  if (kk_std_core_types__is_Optional(fst0)) {
    kk_box_t _fst_1682 = fst0._cons.Optional.value;
    _x2613 = _fst_1682; /*1949*/
  }
  else {
    struct kk_std_core_types__lp__comma__comma__comma__comma__rp_* _con2614 = kk_std_core_types__as_dash__lp__comma__comma__comma__comma__rp_(_this);
    kk_box_t _x = _con2614->fst;
    kk_box_dup(_x);
    _x2613 = _x; /*1949*/
  }
  kk_box_t _x2615;
  if (kk_std_core_types__is_Optional(snd0)) {
    kk_box_t _snd_1774 = snd0._cons.Optional.value;
    _x2615 = _snd_1774; /*1950*/
  }
  else {
    struct kk_std_core_types__lp__comma__comma__comma__comma__rp_* _con2616 = kk_std_core_types__as_dash__lp__comma__comma__comma__comma__rp_(_this);
    kk_box_t _x0 = _con2616->snd;
    kk_box_dup(_x0);
    _x2615 = _x0; /*1950*/
  }
  kk_box_t _x2617;
  if (kk_std_core_types__is_Optional(thd0)) {
    kk_box_t _thd_1852 = thd0._cons.Optional.value;
    _x2617 = _thd_1852; /*1951*/
  }
  else {
    struct kk_std_core_types__lp__comma__comma__comma__comma__rp_* _con2618 = kk_std_core_types__as_dash__lp__comma__comma__comma__comma__rp_(_this);
    kk_box_t _x1 = _con2618->thd;
    kk_box_dup(_x1);
    _x2617 = _x1; /*1951*/
  }
  kk_box_t _x2619;
  if (kk_std_core_types__is_Optional(field40)) {
    kk_box_t _field4_1913 = field40._cons.Optional.value;
    _x2619 = _field4_1913; /*1952*/
  }
  else {
    struct kk_std_core_types__lp__comma__comma__comma__comma__rp_* _con2620 = kk_std_core_types__as_dash__lp__comma__comma__comma__comma__rp_(_this);
    kk_box_t _x2 = _con2620->field4;
    kk_box_dup(_x2);
    _x2619 = _x2; /*1952*/
  }
  kk_box_t _x2621;
  if (kk_std_core_types__is_Optional(field50)) {
    kk_box_t _field5_1924 = field50._cons.Optional.value;
    kk_std_core_types___lp__comma__comma__comma__comma__rp__dropn(_this, ((int32_t)5), _ctx);
    _x2621 = _field5_1924; /*1953*/
  }
  else {
    struct kk_std_core_types__lp__comma__comma__comma__comma__rp_* _con2622 = kk_std_core_types__as_dash__lp__comma__comma__comma__comma__rp_(_this);
    kk_box_t _pat04 = _con2622->fst;
    kk_box_t _pat15 = _con2622->snd;
    kk_box_t _pat24 = _con2622->thd;
    kk_box_t _pat34 = _con2622->field4;
    kk_box_t _x3 = _con2622->field5;
    if (kk_std_core_types___lp__comma__comma__comma__comma__rp__is_unique(_this)) {
      kk_box_drop(_pat34, _ctx);
      kk_box_drop(_pat24, _ctx);
      kk_box_drop(_pat15, _ctx);
      kk_box_drop(_pat04, _ctx);
      kk_std_core_types___lp__comma__comma__comma__comma__rp__free(_this);
    }
    else {
      kk_box_dup(_x3);
      kk_std_core_types___lp__comma__comma__comma__comma__rp__decref(_this, _ctx);
    }
    _x2621 = _x3; /*1953*/
  }
  return kk_std_core_types__new_dash__lp__comma__comma__comma__comma__rp_(kk_reuse_null, _x2613, _x2615, _x2617, _x2619, _x2621, _ctx);
}

kk_std_core_types__hbox kk_std_core_types__copy_6(kk_std_core_types__hbox _this, kk_std_core_types__optional unhbox0, kk_context_t* _ctx) { /* forall<a> (hbox<a>, unhbox : optional<a>) -> hbox<a> */ 
  kk_box_t _x2625;
  if (kk_std_core_types__is_Optional(unhbox0)) {
    kk_box_t _unhbox_2214 = unhbox0._cons.Optional.value;
    kk_std_core_types__hbox_dropn(_this, ((int32_t)1), _ctx);
    _x2625 = _unhbox_2214; /*2223*/
  }
  else {
    struct kk_std_core_types_Hbox* _con2626 = kk_std_core_types__as_Hbox(_this);
    kk_box_t _x = _con2626->unhbox;
    if (kk_std_core_types__hbox_is_unique(_this)) {
      kk_std_core_types__hbox_free(_this);
    }
    else {
      kk_box_dup(_x);
      kk_std_core_types__hbox_decref(_this, _ctx);
    }
    _x2625 = _x; /*2223*/
  }
  return kk_std_core_types__new_Hbox(kk_reuse_null, _x2625, _ctx);
}

kk_reuse_t kk_std_core_types_no_reuse(kk_context_t* _ctx) { /* () -> reuse */ 
  return NULL;
}
 
// If a heap effect is unobservable, the heap effect can be erased by using the `run` fun.
// See also: _State in Haskell, by Simon Peyton Jones and John Launchbury_.

kk_box_t kk_std_core_types_run(kk_function_t action, kk_context_t* _ctx) { /* forall<e,a> (action : forall<h> () -> <alloc<h>,read<h>,write<h>|e> a) -> e a */ 
  return (kk_function_call(kk_box_t,(kk_function_t,kk_context_t*),action,(action,kk_context())));
}

// initialization
void kk_std_core_types__init(kk_context_t* _ctx){
  static bool _initialized = false;
  if (_initialized) return;
  _initialized = true;
}
