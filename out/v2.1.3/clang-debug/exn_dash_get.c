// Koka generated module: "exn-get", koka version: 2.1.3
#include "exn_dash_get.h"

kk_box_t kk_exn_dash_get_exn_get(kk_std_core__list xs, kk_integer_t index, kk_context_t* _ctx) { /* forall<a> (xs : list<a>, index : int) -> exn a */ 
  kk_std_core_types__maybe _match_222;
  kk_integer_t _x225 = kk_integer_dup(index); /*int*/
  _match_222 = kk_std_core__lp__lb__rb__2_rp_(xs, _x225, _ctx); /*maybe<1>*/
  if (kk_std_core_types__is_Nothing(_match_222)) {
    kk_string_t message_205;
    kk_string_t _x226;
    kk_define_string_literal(, _s227, 48, "ListIndexError: Invalid list indexing at index: ")
    _x226 = kk_string_dup(_s227); /*string*/
    kk_string_t _x228 = kk_std_core_show(index, _ctx); /*string*/
    message_205 = kk_std_core__lp__plus__plus__1_rp_(_x226, _x228, _ctx); /*string*/
    kk_std_core__exception exn_21561;
    kk_std_core__exception_info _x229;
    kk_std_core_types__optional _match_224 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
    if (kk_std_core_types__is_Optional(_match_224)) {
      kk_box_t _box_x207 = _match_224._cons.Optional.value;
      kk_std_core__exception_info _info_14279 = kk_std_core__exception_info_unbox(_box_x207, NULL);
      kk_std_core__exception_info_dup(_info_14279);
      kk_std_core_types__optional_drop(_match_224, _ctx);
      _x229 = _info_14279; /*exception-info*/
      goto _match230;
    }
    _x229 = kk_std_core__new_ExnError(_ctx); /*exception-info*/
    _match230: ;
    exn_21561 = kk_std_core__new_Exception(message_205, _x229, _ctx); /*exception*/
    kk_std_core_hnd__ev ev_21562;
    size_t _x232 = ((size_t)0); /*size_t*/
    ev_21562 = kk_evv_at(_x232,kk_context()); /*std/core/hnd/ev<.hnd-exn>*/
    struct kk_std_core_hnd_Ev* _con233 = kk_std_core_hnd__as_Ev(ev_21562);
    kk_std_core_hnd__marker m = _con233->marker;
    kk_box_t _box_x208 = _con233->hnd;
    kk_std_core__hnd_exn h = kk_std_core__hnd_exn_unbox(_box_x208, NULL);
    kk_std_core__hnd_exn_dup(h);
    kk_std_core_hnd__clause1 _match_223;
    struct kk_std_core__Hnd_exn* _con235 = kk_std_core__as_Hnd_exn(h);
    kk_std_core_hnd__clause1 except_throw_exn = _con235->except_throw_exn;
    if (kk_std_core__hnd_exn_is_unique(h)) {
      kk_std_core__hnd_exn_free(h);
    }
    else {
      kk_std_core_hnd__clause1_dup(except_throw_exn);
      kk_std_core__hnd_exn_decref(h, _ctx);
    }
    _match_223 = except_throw_exn; /*forall<a> std/core/hnd/clause1<exception,a,.hnd-exn,6,7>*/
    kk_function_t _fun_unbox_x212 = _match_223.clause;
    return kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x212, (_fun_unbox_x212, m, ev_21562, kk_std_core__exception_box(exn_21561, _ctx), _ctx));
  }
  kk_box_t x = _match_222._cons.Just.value;
  kk_integer_drop(index, _ctx);
  return x;
}

// initialization
void kk_exn_dash_get__init(kk_context_t* _ctx){
  static bool _initialized = false;
  if (_initialized) return;
  _initialized = true;
  kk_std_core_types__init(_ctx);
  kk_std_core_hnd__init(_ctx);
  kk_std_core__init(_ctx);
}
