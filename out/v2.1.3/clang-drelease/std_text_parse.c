// Koka generated module: "std/text/parse", koka version: 2.1.3
#include "std_text_parse.h"
 
// runtime tag for the `:parse` effect

kk_std_core_hnd__htag kk_std_text_parse__tag_parse;
 
// handler for the `:parse` effect

kk_box_t kk_std_text_parse__handle_parse(int32_t cfc, kk_std_text_parse__hnd_parse hnd, kk_function_t ret, kk_function_t action, kk_context_t* _ctx) { /* forall<a,e,b> (cfc : int32, hnd : .hnd-parse<e,b>, ret : (res : a) -> e b, action : () -> <parse|e> a) -> e b */ 
  kk_std_core_hnd__htag _x4465 = kk_std_core_hnd__htag_dup(kk_std_text_parse__tag_parse); /*std/core/hnd/htag<std/text/parse/.hnd-parse>*/
  return kk_std_core_hnd__hhandle(_x4465, cfc, kk_std_text_parse__hnd_parse_box(hnd, _ctx), ret, action, _ctx);
}

kk_std_core_types__either kk_std_text_parse_either(kk_std_text_parse__parse_error perr, kk_context_t* _ctx) { /* forall<a> (perr : parse-error<a>) -> either<string,a> */ 
  if (kk_std_text_parse__is_ParseOk(perr)) {
    struct kk_std_text_parse_ParseOk* _con4470 = kk_std_text_parse__as_ParseOk(perr);
    kk_box_t x = _con4470->result;
    kk_std_core__sslice _pat0 = _con4470->rest;
    if (kk_std_text_parse__parse_error_is_unique(perr)) {
      kk_std_core__sslice_drop(_pat0, _ctx);
      kk_std_text_parse__parse_error_free(perr);
    }
    else {
      kk_box_dup(x);
      kk_std_text_parse__parse_error_decref(perr, _ctx);
    }
    return kk_std_core_types__new_Right(x, _ctx);
  }
  struct kk_std_text_parse_ParseError* _con4471 = kk_std_text_parse__as_ParseError(perr);
  kk_string_t msg = _con4471->msg;
  kk_std_core__sslice _pat5 = _con4471->rest;
  if (kk_std_text_parse__parse_error_is_unique(perr)) {
    kk_std_core__sslice_drop(_pat5, _ctx);
    kk_std_text_parse__parse_error_free(perr);
  }
  else {
    kk_string_dup(msg);
    kk_std_text_parse__parse_error_decref(perr, _ctx);
  }
  return kk_std_core_types__new_Left(kk_string_box(msg), _ctx);
}
extern kk_box_t kk_std_text_parse_satisfy_fun4481(kk_function_t _fself, kk_box_t _b_2976, kk_context_t* _ctx) {
  struct kk_std_text_parse_satisfy_fun4481__t* _self = kk_function_as(struct kk_std_text_parse_satisfy_fun4481__t*, _fself);
  kk_function_t pred = _self->pred; /* (sslice) -> total maybe<(521, sslice)> */
  kk_drop_match(_self, {kk_function_dup(pred);}, {}, _ctx)
  kk_std_core_types__maybe _x4482;
  kk_std_core__sslice _x4483 = kk_std_core__sslice_unbox(_b_2976, _ctx); /*sslice*/
  _x4482 = kk_function_call(kk_std_core_types__maybe, (kk_function_t, kk_std_core__sslice, kk_context_t*), pred, (pred, _x4483, _ctx)); /*maybe<(521, sslice)>*/
  return kk_std_core_types__maybe_box(_x4482, _ctx);
}
 
// monadic lift

kk_box_t kk_std_text_parse__mlift2547_satisfy_fail(kk_string_t msg, kk_std_core_types__maybe _y_3, kk_context_t* _ctx) { /* forall<a> (msg : string, maybe<a>) -> parse a */ 
  if (kk_std_core_types__is_Nothing(_y_3)) {
    return kk_std_text_parse_fail(msg, _ctx);
  }
  kk_box_t x = _y_3._cons.Just.value;
  kk_string_drop(msg, _ctx);
  return x;
}


// lift anonymous function
struct kk_std_text_parse_satisfy_fail_fun4484__t {
  struct kk_function_s _base;
  kk_string_t msg;
};
static kk_box_t kk_std_text_parse_satisfy_fail_fun4484(kk_function_t _fself, kk_box_t _b_2981, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_satisfy_fail_fun4484(kk_string_t msg, kk_context_t* _ctx) {
  struct kk_std_text_parse_satisfy_fail_fun4484__t* _self = kk_function_alloc_as(struct kk_std_text_parse_satisfy_fail_fun4484__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_text_parse_satisfy_fail_fun4484, kk_context());
  _self->msg = msg;
  return &_self->_base;
}

static kk_box_t kk_std_text_parse_satisfy_fail_fun4484(kk_function_t _fself, kk_box_t _b_2981, kk_context_t* _ctx) {
  struct kk_std_text_parse_satisfy_fail_fun4484__t* _self = kk_function_as(struct kk_std_text_parse_satisfy_fail_fun4484__t*, _fself);
  kk_string_t msg = _self->msg; /* string */
  kk_drop_match(_self, {kk_string_dup(msg);}, {}, _ctx)
  kk_std_core_types__maybe _x4485 = kk_std_core_types__maybe_unbox(_b_2981, _ctx); /*maybe<547>*/
  return kk_std_text_parse__mlift2547_satisfy_fail(msg, _x4485, _ctx);
}

kk_box_t kk_std_text_parse_satisfy_fail(kk_string_t msg, kk_function_t pred, kk_context_t* _ctx) { /* forall<a> (msg : string, pred : (sslice) -> maybe<(a, sslice)>) -> parse a */ 
  kk_std_core_types__maybe x_2577 = kk_std_text_parse_satisfy(pred, _ctx); /*maybe<547>*/;
  if (kk_yielding(kk_context())) {
    kk_std_core_types__maybe_drop(x_2577, _ctx);
    return kk_std_core_hnd_yield_extend(kk_std_text_parse_new_satisfy_fail_fun4484(msg, _ctx), _ctx);
  }
  if (kk_std_core_types__is_Nothing(x_2577)) {
    return kk_std_text_parse_fail(msg, _ctx);
  }
  kk_box_t x0 = x_2577._cons.Just.value;
  kk_string_drop(msg, _ctx);
  return x0;
}


// lift anonymous function
struct kk_std_text_parse_char_is_fun4491__t {
  struct kk_function_s _base;
  kk_function_t pred;
};
static kk_box_t kk_std_text_parse_char_is_fun4491(kk_function_t _fself, kk_box_t _b_2997, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_char_is_fun4491(kk_function_t pred, kk_context_t* _ctx) {
  struct kk_std_text_parse_char_is_fun4491__t* _self = kk_function_alloc_as(struct kk_std_text_parse_char_is_fun4491__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_text_parse_char_is_fun4491, kk_context());
  _self->pred = pred;
  return &_self->_base;
}

static kk_box_t kk_std_text_parse_char_is_fun4491(kk_function_t _fself, kk_box_t _b_2997, kk_context_t* _ctx) {
  struct kk_std_text_parse_char_is_fun4491__t* _self = kk_function_as(struct kk_std_text_parse_char_is_fun4491__t*, _fself);
  kk_function_t pred = _self->pred; /* (char) -> bool */
  kk_drop_match(_self, {kk_function_dup(pred);}, {}, _ctx)
  kk_std_core_types__maybe _x4492;
  kk_std_core_types__maybe _match_4455;
  kk_std_core__sslice _x4493 = kk_std_core__sslice_unbox(_b_2997, _ctx); /*sslice*/
  _match_4455 = kk_std_core_next(_x4493, _ctx); /*maybe<(char, sslice)>*/
  if (kk_std_core_types__is_Just(_match_4455)) {
    kk_box_t _box_x2998 = _match_4455._cons.Just.value;
    kk_std_core_types__tuple2_ _pat01 = kk_std_core_types__tuple2__unbox(_box_x2998, NULL);
    if (kk_std_core_types__is_dash__lp__comma__rp_(_pat01)) {
      kk_box_t _box_x2999 = _pat01.fst;
      kk_box_t _box_x3000 = _pat01.snd;
      kk_char_t c = kk_char_unbox(_box_x2999, NULL);
      kk_std_core__sslice rest0 = kk_std_core__sslice_unbox(_box_x3000, NULL);
      kk_function_t _x4498 = kk_function_dup(pred); /*(char) -> bool*/
      if (kk_function_call(bool, (kk_function_t, kk_char_t, kk_context_t*), _x4498, (_x4498, c, _ctx))) {
        kk_function_drop(pred, _ctx);
        kk_std_core__sslice_dup(rest0);
        kk_std_core_types__maybe_drop(_match_4455, _ctx);
        kk_std_core_types__tuple2_ _b_3008_3003 = kk_std_core_types__new_dash__lp__comma__rp_(kk_char_box(c, _ctx), kk_std_core__sslice_box(rest0, _ctx), _ctx); /*(char, sslice)*/;
        _x4492 = kk_std_core_types__new_Just(kk_std_core_types__tuple2__box(_b_3008_3003, _ctx), _ctx); /*maybe<103>*/
        goto _match4494;
      }
    }
  }
  kk_std_core_types__maybe_drop(_match_4455, _ctx);
  kk_function_drop(pred, _ctx);
  _x4492 = kk_std_core_types__new_Nothing(_ctx); /*maybe<103>*/
  _match4494: ;
  return kk_std_core_types__maybe_box(_x4492, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_char_is_fun4500__t {
  struct kk_function_s _base;
  kk_string_t msg;
};
static kk_box_t kk_std_text_parse_char_is_fun4500(kk_function_t _fself, kk_box_t _b_3014, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_char_is_fun4500(kk_string_t msg, kk_context_t* _ctx) {
  struct kk_std_text_parse_char_is_fun4500__t* _self = kk_function_alloc_as(struct kk_std_text_parse_char_is_fun4500__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_text_parse_char_is_fun4500, kk_context());
  _self->msg = msg;
  return &_self->_base;
}

static kk_box_t kk_std_text_parse_char_is_fun4500(kk_function_t _fself, kk_box_t _b_3014, kk_context_t* _ctx) {
  struct kk_std_text_parse_char_is_fun4500__t* _self = kk_function_as(struct kk_std_text_parse_char_is_fun4500__t*, _fself);
  kk_string_t msg = _self->msg; /* string */
  kk_drop_match(_self, {kk_string_dup(msg);}, {}, _ctx)
  kk_std_core_types__maybe _x4501 = kk_std_core_types__maybe_unbox(_b_3014, _ctx); /*maybe<char>*/
  return kk_std_text_parse__mlift2547_satisfy_fail(msg, _x4501, _ctx);
}

kk_char_t kk_std_text_parse_char_is(kk_string_t msg, kk_function_t pred, kk_context_t* _ctx) { /* (msg : string, pred : (char) -> bool) -> parse char */ 
  kk_std_core_types__maybe x_2583;
  kk_std_core_hnd__ev ev_2574;
  size_t _x4486 = ((size_t)0); /*size_t*/
  ev_2574 = kk_evv_at(_x4486,kk_context()); /*std/core/hnd/ev<std/text/parse/.hnd-parse>*/
  kk_box_t _x4487;
  struct kk_std_core_hnd_Ev* _con4488 = kk_std_core_hnd__as_Ev(ev_2574);
  kk_std_core_hnd__marker m = _con4488->marker;
  kk_box_t _box_x2984 = _con4488->hnd;
  kk_std_text_parse__hnd_parse h = kk_std_text_parse__hnd_parse_unbox(_box_x2984, NULL);
  kk_std_text_parse__hnd_parse_dup(h);
  kk_std_core_hnd__clause1 _match_4454;
  struct kk_std_text_parse__Hnd_parse* _con4490 = kk_std_text_parse__as_Hnd_parse(h);
  kk_std_core_hnd__clause0 _pat00 = _con4490->fun_current_input;
  kk_std_core_hnd__clause1 _pat10 = _con4490->control_fail;
  kk_std_core_hnd__clause0 _pat20 = _con4490->control_pick;
  kk_std_core_hnd__clause1 fun_satisfy = _con4490->fun_satisfy;
  if (kk_std_text_parse__hnd_parse_is_unique(h)) {
    kk_std_core_hnd__clause0_drop(_pat20, _ctx);
    kk_std_core_hnd__clause1_drop(_pat10, _ctx);
    kk_std_core_hnd__clause0_drop(_pat00, _ctx);
    kk_std_text_parse__hnd_parse_free(h);
  }
  else {
    kk_std_core_hnd__clause1_dup(fun_satisfy);
    kk_std_text_parse__hnd_parse_decref(h, _ctx);
  }
  _match_4454 = fun_satisfy; /*forall<a> std/core/hnd/clause1<(sslice) -> total maybe<(a, sslice)>,maybe<a>,std/text/parse/.hnd-parse,3528,3529>*/
  kk_function_t _fun_unbox_x2991 = _match_4454.clause;
  _x4487 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x2991, (_fun_unbox_x2991, m, ev_2574, kk_function_box(kk_std_text_parse_new_char_is_fun4491(pred, _ctx)), _ctx)); /*53*/
  x_2583 = kk_std_core_types__maybe_unbox(_x4487, _ctx); /*maybe<char>*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__maybe_drop(x_2583, _ctx);
    kk_box_t _x4499 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_char_is_fun4500(msg, _ctx), _ctx); /*3991*/
    return kk_char_unbox(_x4499, _ctx);
  }
  if (kk_std_core_types__is_Nothing(x_2583)) {
    kk_box_t _x4502 = kk_std_text_parse_fail(msg, _ctx); /*492*/
    return kk_char_unbox(_x4502, _ctx);
  }
  kk_box_t _box_x3016 = x_2583._cons.Just.value;
  kk_char_t x0 = kk_char_unbox(_box_x3016, NULL);
  kk_std_core_types__maybe_drop(x_2583, _ctx);
  kk_string_drop(msg, _ctx);
  return x0;
}


// lift anonymous function
struct kk_std_text_parse_alpha_fun4509__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse_alpha_fun4509(kk_function_t _fself, kk_box_t _b_3035, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_alpha_fun4509(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_alpha_fun4509, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_text_parse_alpha_fun4509(kk_function_t _fself, kk_box_t _b_3035, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core_types__maybe _x4510;
  kk_std_core_types__maybe _match_4452;
  kk_std_core__sslice _x4511 = kk_std_core__sslice_unbox(_b_3035, _ctx); /*sslice*/
  _match_4452 = kk_std_core_next(_x4511, _ctx); /*maybe<(char, sslice)>*/
  if (kk_std_core_types__is_Just(_match_4452)) {
    kk_box_t _box_x3036 = _match_4452._cons.Just.value;
    kk_std_core_types__tuple2_ _pat01 = kk_std_core_types__tuple2__unbox(_box_x3036, NULL);
    if (kk_std_core_types__is_dash__lp__comma__rp_(_pat01)) {
      kk_box_t _box_x3037 = _pat01.fst;
      kk_box_t _box_x3038 = _pat01.snd;
      kk_char_t c = kk_char_unbox(_box_x3037, NULL);
      kk_std_core__sslice rest0 = kk_std_core__sslice_unbox(_box_x3038, NULL);
      if (kk_std_core_is_alpha(c, _ctx)) {
        kk_std_core__sslice_dup(rest0);
        kk_std_core_types__maybe_drop(_match_4452, _ctx);
        kk_std_core_types__tuple2_ _b_3046_3041 = kk_std_core_types__new_dash__lp__comma__rp_(kk_char_box(c, _ctx), kk_std_core__sslice_box(rest0, _ctx), _ctx); /*(char, sslice)*/;
        _x4510 = kk_std_core_types__new_Just(kk_std_core_types__tuple2__box(_b_3046_3041, _ctx), _ctx); /*maybe<103>*/
        goto _match4512;
      }
    }
  }
  kk_std_core_types__maybe_drop(_match_4452, _ctx);
  _x4510 = kk_std_core_types__new_Nothing(_ctx); /*maybe<103>*/
  _match4512: ;
  return kk_std_core_types__maybe_box(_x4510, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_alpha_fun4517__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse_alpha_fun4517(kk_function_t _fself, kk_box_t _b_3052, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_alpha_fun4517(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_alpha_fun4517, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_text_parse_alpha_fun4517(kk_function_t _fself, kk_box_t _b_3052, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x4518;
  kk_define_string_literal(, _s4519, 5, "alpha")
  _x4518 = kk_string_dup(_s4519); /*string*/
  kk_std_core_types__maybe _x4520 = kk_std_core_types__maybe_unbox(_b_3052, _ctx); /*maybe<char>*/
  return kk_std_text_parse__mlift2547_satisfy_fail(_x4518, _x4520, _ctx);
}

kk_char_t kk_std_text_parse_alpha(kk_context_t* _ctx) { /* () -> parse char */ 
  kk_std_core_types__maybe x_2591;
  kk_std_core_hnd__ev ev_2574;
  size_t _x4504 = ((size_t)0); /*size_t*/
  ev_2574 = kk_evv_at(_x4504,kk_context()); /*std/core/hnd/ev<std/text/parse/.hnd-parse>*/
  kk_box_t _x4505;
  struct kk_std_core_hnd_Ev* _con4506 = kk_std_core_hnd__as_Ev(ev_2574);
  kk_std_core_hnd__marker m = _con4506->marker;
  kk_box_t _box_x3022 = _con4506->hnd;
  kk_std_text_parse__hnd_parse h = kk_std_text_parse__hnd_parse_unbox(_box_x3022, NULL);
  kk_std_text_parse__hnd_parse_dup(h);
  kk_std_core_hnd__clause1 _match_4451;
  struct kk_std_text_parse__Hnd_parse* _con4508 = kk_std_text_parse__as_Hnd_parse(h);
  kk_std_core_hnd__clause0 _pat00 = _con4508->fun_current_input;
  kk_std_core_hnd__clause1 _pat10 = _con4508->control_fail;
  kk_std_core_hnd__clause0 _pat20 = _con4508->control_pick;
  kk_std_core_hnd__clause1 fun_satisfy = _con4508->fun_satisfy;
  if (kk_std_text_parse__hnd_parse_is_unique(h)) {
    kk_std_core_hnd__clause0_drop(_pat20, _ctx);
    kk_std_core_hnd__clause1_drop(_pat10, _ctx);
    kk_std_core_hnd__clause0_drop(_pat00, _ctx);
    kk_std_text_parse__hnd_parse_free(h);
  }
  else {
    kk_std_core_hnd__clause1_dup(fun_satisfy);
    kk_std_text_parse__hnd_parse_decref(h, _ctx);
  }
  _match_4451 = fun_satisfy; /*forall<a> std/core/hnd/clause1<(sslice) -> total maybe<(a, sslice)>,maybe<a>,std/text/parse/.hnd-parse,3528,3529>*/
  kk_function_t _fun_unbox_x3029 = _match_4451.clause;
  _x4505 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x3029, (_fun_unbox_x3029, m, ev_2574, kk_function_box(kk_std_text_parse_new_alpha_fun4509(_ctx)), _ctx)); /*53*/
  x_2591 = kk_std_core_types__maybe_unbox(_x4505, _ctx); /*maybe<char>*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__maybe_drop(x_2591, _ctx);
    kk_box_t _x4516 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_alpha_fun4517(_ctx), _ctx); /*3991*/
    return kk_char_unbox(_x4516, _ctx);
  }
  if (kk_std_core_types__is_Nothing(x_2591)) {
    kk_box_t _x4521;
    kk_string_t _x4522;
    kk_define_string_literal(, _s4523, 5, "alpha")
    _x4522 = kk_string_dup(_s4523); /*string*/
    _x4521 = kk_std_text_parse_fail(_x4522, _ctx); /*492*/
    return kk_char_unbox(_x4521, _ctx);
  }
  kk_box_t _box_x3054 = x_2591._cons.Just.value;
  kk_char_t x0 = kk_char_unbox(_box_x3054, NULL);
  kk_std_core_types__maybe_drop(x_2591, _ctx);
  return x0;
}


// lift anonymous function
struct kk_std_text_parse_alpha_num_fun4530__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse_alpha_num_fun4530(kk_function_t _fself, kk_box_t _b_3073, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_alpha_num_fun4530(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_alpha_num_fun4530, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_text_parse_alpha_num_fun4530(kk_function_t _fself, kk_box_t _b_3073, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core_types__maybe _x4531;
  kk_std_core_types__maybe _match_4449;
  kk_std_core__sslice _x4532 = kk_std_core__sslice_unbox(_b_3073, _ctx); /*sslice*/
  _match_4449 = kk_std_core_next(_x4532, _ctx); /*maybe<(char, sslice)>*/
  if (kk_std_core_types__is_Just(_match_4449)) {
    kk_box_t _box_x3074 = _match_4449._cons.Just.value;
    kk_std_core_types__tuple2_ _pat01 = kk_std_core_types__tuple2__unbox(_box_x3074, NULL);
    if (kk_std_core_types__is_dash__lp__comma__rp_(_pat01)) {
      kk_box_t _box_x3075 = _pat01.fst;
      kk_box_t _box_x3076 = _pat01.snd;
      kk_char_t c = kk_char_unbox(_box_x3075, NULL);
      kk_std_core__sslice rest0 = kk_std_core__sslice_unbox(_box_x3076, NULL);
      if (kk_std_core_is_alpha_num(c, _ctx)) {
        kk_std_core__sslice_dup(rest0);
        kk_std_core_types__maybe_drop(_match_4449, _ctx);
        kk_std_core_types__tuple2_ _b_3084_3079 = kk_std_core_types__new_dash__lp__comma__rp_(kk_char_box(c, _ctx), kk_std_core__sslice_box(rest0, _ctx), _ctx); /*(char, sslice)*/;
        _x4531 = kk_std_core_types__new_Just(kk_std_core_types__tuple2__box(_b_3084_3079, _ctx), _ctx); /*maybe<103>*/
        goto _match4533;
      }
    }
  }
  kk_std_core_types__maybe_drop(_match_4449, _ctx);
  _x4531 = kk_std_core_types__new_Nothing(_ctx); /*maybe<103>*/
  _match4533: ;
  return kk_std_core_types__maybe_box(_x4531, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_alpha_num_fun4538__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse_alpha_num_fun4538(kk_function_t _fself, kk_box_t _b_3090, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_alpha_num_fun4538(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_alpha_num_fun4538, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_text_parse_alpha_num_fun4538(kk_function_t _fself, kk_box_t _b_3090, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x4539;
  kk_define_string_literal(, _s4540, 9, "alpha-num")
  _x4539 = kk_string_dup(_s4540); /*string*/
  kk_std_core_types__maybe _x4541 = kk_std_core_types__maybe_unbox(_b_3090, _ctx); /*maybe<char>*/
  return kk_std_text_parse__mlift2547_satisfy_fail(_x4539, _x4541, _ctx);
}

kk_char_t kk_std_text_parse_alpha_num(kk_context_t* _ctx) { /* () -> parse char */ 
  kk_std_core_types__maybe x_2599;
  kk_std_core_hnd__ev ev_2574;
  size_t _x4525 = ((size_t)0); /*size_t*/
  ev_2574 = kk_evv_at(_x4525,kk_context()); /*std/core/hnd/ev<std/text/parse/.hnd-parse>*/
  kk_box_t _x4526;
  struct kk_std_core_hnd_Ev* _con4527 = kk_std_core_hnd__as_Ev(ev_2574);
  kk_std_core_hnd__marker m = _con4527->marker;
  kk_box_t _box_x3060 = _con4527->hnd;
  kk_std_text_parse__hnd_parse h = kk_std_text_parse__hnd_parse_unbox(_box_x3060, NULL);
  kk_std_text_parse__hnd_parse_dup(h);
  kk_std_core_hnd__clause1 _match_4448;
  struct kk_std_text_parse__Hnd_parse* _con4529 = kk_std_text_parse__as_Hnd_parse(h);
  kk_std_core_hnd__clause0 _pat00 = _con4529->fun_current_input;
  kk_std_core_hnd__clause1 _pat10 = _con4529->control_fail;
  kk_std_core_hnd__clause0 _pat20 = _con4529->control_pick;
  kk_std_core_hnd__clause1 fun_satisfy = _con4529->fun_satisfy;
  if (kk_std_text_parse__hnd_parse_is_unique(h)) {
    kk_std_core_hnd__clause0_drop(_pat20, _ctx);
    kk_std_core_hnd__clause1_drop(_pat10, _ctx);
    kk_std_core_hnd__clause0_drop(_pat00, _ctx);
    kk_std_text_parse__hnd_parse_free(h);
  }
  else {
    kk_std_core_hnd__clause1_dup(fun_satisfy);
    kk_std_text_parse__hnd_parse_decref(h, _ctx);
  }
  _match_4448 = fun_satisfy; /*forall<a> std/core/hnd/clause1<(sslice) -> total maybe<(a, sslice)>,maybe<a>,std/text/parse/.hnd-parse,3528,3529>*/
  kk_function_t _fun_unbox_x3067 = _match_4448.clause;
  _x4526 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x3067, (_fun_unbox_x3067, m, ev_2574, kk_function_box(kk_std_text_parse_new_alpha_num_fun4530(_ctx)), _ctx)); /*53*/
  x_2599 = kk_std_core_types__maybe_unbox(_x4526, _ctx); /*maybe<char>*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__maybe_drop(x_2599, _ctx);
    kk_box_t _x4537 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_alpha_num_fun4538(_ctx), _ctx); /*3991*/
    return kk_char_unbox(_x4537, _ctx);
  }
  if (kk_std_core_types__is_Nothing(x_2599)) {
    kk_box_t _x4542;
    kk_string_t _x4543;
    kk_define_string_literal(, _s4544, 9, "alpha-num")
    _x4543 = kk_string_dup(_s4544); /*string*/
    _x4542 = kk_std_text_parse_fail(_x4543, _ctx); /*492*/
    return kk_char_unbox(_x4542, _ctx);
  }
  kk_box_t _box_x3092 = x_2599._cons.Just.value;
  kk_char_t x0 = kk_char_unbox(_box_x3092, NULL);
  kk_std_core_types__maybe_drop(x_2599, _ctx);
  return x0;
}


// lift anonymous function
struct kk_std_text_parse_char_fun4551__t {
  struct kk_function_s _base;
  kk_char_t c;
};
static kk_box_t kk_std_text_parse_char_fun4551(kk_function_t _fself, kk_box_t _b_3111, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_char_fun4551(kk_char_t c, kk_context_t* _ctx) {
  struct kk_std_text_parse_char_fun4551__t* _self = kk_function_alloc_as(struct kk_std_text_parse_char_fun4551__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_text_parse_char_fun4551, kk_context());
  _self->c = c;
  return &_self->_base;
}

static kk_box_t kk_std_text_parse_char_fun4551(kk_function_t _fself, kk_box_t _b_3111, kk_context_t* _ctx) {
  struct kk_std_text_parse_char_fun4551__t* _self = kk_function_as(struct kk_std_text_parse_char_fun4551__t*, _fself);
  kk_char_t c = _self->c; /* char */
  kk_drop_match(_self, {;}, {}, _ctx)
  kk_std_core_types__maybe _x4552;
  kk_std_core_types__maybe _match_4446;
  kk_std_core__sslice _x4553 = kk_std_core__sslice_unbox(_b_3111, _ctx); /*sslice*/
  _match_4446 = kk_std_core_next(_x4553, _ctx); /*maybe<(char, sslice)>*/
  if (kk_std_core_types__is_Just(_match_4446)) {
    kk_box_t _box_x3112 = _match_4446._cons.Just.value;
    kk_std_core_types__tuple2_ _pat01 = kk_std_core_types__tuple2__unbox(_box_x3112, NULL);
    if (kk_std_core_types__is_dash__lp__comma__rp_(_pat01)) {
      kk_box_t _box_x3113 = _pat01.fst;
      kk_box_t _box_x3114 = _pat01.snd;
      kk_char_t c0 = kk_char_unbox(_box_x3113, NULL);
      kk_std_core__sslice rest0 = kk_std_core__sslice_unbox(_box_x3114, NULL);
      if (c == c0) {
        kk_std_core__sslice_dup(rest0);
        kk_std_core_types__maybe_drop(_match_4446, _ctx);
        kk_std_core_types__tuple2_ _b_3122_3117 = kk_std_core_types__new_dash__lp__comma__rp_(kk_char_box(c0, _ctx), kk_std_core__sslice_box(rest0, _ctx), _ctx); /*(char, sslice)*/;
        _x4552 = kk_std_core_types__new_Just(kk_std_core_types__tuple2__box(_b_3122_3117, _ctx), _ctx); /*maybe<103>*/
        goto _match4554;
      }
    }
  }
  kk_std_core_types__maybe_drop(_match_4446, _ctx);
  _x4552 = kk_std_core_types__new_Nothing(_ctx); /*maybe<103>*/
  _match4554: ;
  return kk_std_core_types__maybe_box(_x4552, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_char_fun4559__t {
  struct kk_function_s _base;
  kk_string_t msg_2603;
};
static kk_box_t kk_std_text_parse_char_fun4559(kk_function_t _fself, kk_box_t _b_3128, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_char_fun4559(kk_string_t msg_2603, kk_context_t* _ctx) {
  struct kk_std_text_parse_char_fun4559__t* _self = kk_function_alloc_as(struct kk_std_text_parse_char_fun4559__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_text_parse_char_fun4559, kk_context());
  _self->msg_2603 = msg_2603;
  return &_self->_base;
}

static kk_box_t kk_std_text_parse_char_fun4559(kk_function_t _fself, kk_box_t _b_3128, kk_context_t* _ctx) {
  struct kk_std_text_parse_char_fun4559__t* _self = kk_function_as(struct kk_std_text_parse_char_fun4559__t*, _fself);
  kk_string_t msg_2603 = _self->msg_2603; /* string */
  kk_drop_match(_self, {kk_string_dup(msg_2603);}, {}, _ctx)
  kk_std_core_types__maybe _x4560 = kk_std_core_types__maybe_unbox(_b_3128, _ctx); /*maybe<char>*/
  return kk_std_text_parse__mlift2547_satisfy_fail(msg_2603, _x4560, _ctx);
}

kk_char_t kk_std_text_parse_char(kk_char_t c, kk_context_t* _ctx) { /* (c : char) -> parse char */ 
  kk_string_t msg_2603 = kk_std_core_show_2(c, _ctx); /*string*/;
  kk_std_core_types__maybe x_2607;
  kk_std_core_hnd__ev ev_2574;
  size_t _x4546 = ((size_t)0); /*size_t*/
  ev_2574 = kk_evv_at(_x4546,kk_context()); /*std/core/hnd/ev<std/text/parse/.hnd-parse>*/
  kk_box_t _x4547;
  struct kk_std_core_hnd_Ev* _con4548 = kk_std_core_hnd__as_Ev(ev_2574);
  kk_std_core_hnd__marker m = _con4548->marker;
  kk_box_t _box_x3098 = _con4548->hnd;
  kk_std_text_parse__hnd_parse h = kk_std_text_parse__hnd_parse_unbox(_box_x3098, NULL);
  kk_std_text_parse__hnd_parse_dup(h);
  kk_std_core_hnd__clause1 _match_4445;
  struct kk_std_text_parse__Hnd_parse* _con4550 = kk_std_text_parse__as_Hnd_parse(h);
  kk_std_core_hnd__clause0 _pat00 = _con4550->fun_current_input;
  kk_std_core_hnd__clause1 _pat10 = _con4550->control_fail;
  kk_std_core_hnd__clause0 _pat20 = _con4550->control_pick;
  kk_std_core_hnd__clause1 fun_satisfy = _con4550->fun_satisfy;
  if (kk_std_text_parse__hnd_parse_is_unique(h)) {
    kk_std_core_hnd__clause0_drop(_pat20, _ctx);
    kk_std_core_hnd__clause1_drop(_pat10, _ctx);
    kk_std_core_hnd__clause0_drop(_pat00, _ctx);
    kk_std_text_parse__hnd_parse_free(h);
  }
  else {
    kk_std_core_hnd__clause1_dup(fun_satisfy);
    kk_std_text_parse__hnd_parse_decref(h, _ctx);
  }
  _match_4445 = fun_satisfy; /*forall<a> std/core/hnd/clause1<(sslice) -> total maybe<(a, sslice)>,maybe<a>,std/text/parse/.hnd-parse,3528,3529>*/
  kk_function_t _fun_unbox_x3105 = _match_4445.clause;
  _x4547 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x3105, (_fun_unbox_x3105, m, ev_2574, kk_function_box(kk_std_text_parse_new_char_fun4551(c, _ctx)), _ctx)); /*53*/
  x_2607 = kk_std_core_types__maybe_unbox(_x4547, _ctx); /*maybe<char>*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__maybe_drop(x_2607, _ctx);
    kk_box_t _x4558 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_char_fun4559(msg_2603, _ctx), _ctx); /*3991*/
    return kk_char_unbox(_x4558, _ctx);
  }
  if (kk_std_core_types__is_Nothing(x_2607)) {
    kk_box_t _x4561 = kk_std_text_parse_fail(msg_2603, _ctx); /*492*/
    return kk_char_unbox(_x4561, _ctx);
  }
  kk_box_t _box_x3130 = x_2607._cons.Just.value;
  kk_char_t x0 = kk_char_unbox(_box_x3130, NULL);
  kk_std_core_types__maybe_drop(x_2607, _ctx);
  kk_string_drop(msg_2603, _ctx);
  return x0;
}

kk_std_core_types__tuple2_ kk_std_text_parse_next_while0(kk_std_core__sslice slice, kk_function_t pred, kk_std_core__list acc, kk_context_t* _ctx) { /* (slice : sslice, pred : (char) -> bool, acc : list<char>) -> (list<char>, sslice) */ 
  kk__tailcall: ;
  kk_std_core_types__maybe _match_4443;
  kk_std_core__sslice _x4563 = kk_std_core__sslice_dup(slice); /*sslice*/
  _match_4443 = kk_std_core_next(_x4563, _ctx); /*maybe<(char, sslice)>*/
  if (kk_std_core_types__is_Just(_match_4443)) {
    kk_box_t _box_x3136 = _match_4443._cons.Just.value;
    kk_std_core_types__tuple2_ _pat0 = kk_std_core_types__tuple2__unbox(_box_x3136, NULL);
    if (kk_std_core_types__is_dash__lp__comma__rp_(_pat0)) {
      kk_box_t _box_x3137 = _pat0.fst;
      kk_box_t _box_x3138 = _pat0.snd;
      kk_char_t c = kk_char_unbox(_box_x3137, NULL);
      kk_std_core__sslice rest0 = kk_std_core__sslice_unbox(_box_x3138, NULL);
      kk_function_t _x4567 = kk_function_dup(pred); /*(char) -> bool*/
      if (kk_function_call(bool, (kk_function_t, kk_char_t, kk_context_t*), _x4567, (_x4567, c, _ctx))) {
        kk_std_core__sslice_drop(slice, _ctx);
        kk_std_core__sslice_dup(rest0);
        kk_std_core_types__maybe_drop(_match_4443, _ctx);
        { // tailcall
          kk_std_core__list _x4568 = kk_std_core__new_Cons(kk_reuse_null, kk_char_box(c, _ctx), acc, _ctx); /*list<61>*/
          slice = rest0;
          acc = _x4568;
          goto kk__tailcall;
        }
      }
    }
  }
  kk_std_core_types__maybe_drop(_match_4443, _ctx);
  kk_function_drop(pred, _ctx);
  kk_std_core__list _b_3145_3141 = kk_std_core_reverse(acc, _ctx); /*list<char>*/;
  return kk_std_core_types__new_dash__lp__comma__rp_(kk_std_core__list_box(_b_3145_3141, _ctx), kk_std_core__sslice_box(slice, _ctx), _ctx);
}


// lift anonymous function
struct kk_std_text_parse_chars_are_fun4574__t {
  struct kk_function_s _base;
  kk_function_t pred;
};
static kk_box_t kk_std_text_parse_chars_are_fun4574(kk_function_t _fself, kk_box_t _b_3160, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_chars_are_fun4574(kk_function_t pred, kk_context_t* _ctx) {
  struct kk_std_text_parse_chars_are_fun4574__t* _self = kk_function_alloc_as(struct kk_std_text_parse_chars_are_fun4574__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_text_parse_chars_are_fun4574, kk_context());
  _self->pred = pred;
  return &_self->_base;
}

static kk_box_t kk_std_text_parse_chars_are_fun4574(kk_function_t _fself, kk_box_t _b_3160, kk_context_t* _ctx) {
  struct kk_std_text_parse_chars_are_fun4574__t* _self = kk_function_as(struct kk_std_text_parse_chars_are_fun4574__t*, _fself);
  kk_function_t pred = _self->pred; /* (char) -> bool */
  kk_drop_match(_self, {kk_function_dup(pred);}, {}, _ctx)
  kk_std_core_types__maybe _x4575;
  kk_std_core_types__tuple2_ _match_4442;
  kk_std_core__sslice _x4576 = kk_std_core__sslice_unbox(_b_3160, _ctx); /*sslice*/
  _match_4442 = kk_std_text_parse_next_while0(_x4576, pred, kk_std_core__new_Nil(_ctx), _ctx); /*(list<char>, sslice)*/
  kk_box_t _box_x3161 = _match_4442.fst;
  kk_box_t _box_x3162 = _match_4442.snd;
  kk_std_core__list _pat01 = kk_std_core__list_unbox(_box_x3161, NULL);
  kk_std_core__sslice _pat100 = kk_std_core__sslice_unbox(_box_x3162, NULL);
  if (kk_std_core__is_Nil(_pat01)) {
    kk_std_core_types__tuple2__drop(_match_4442, _ctx);
    _x4575 = kk_std_core_types__new_Nothing(_ctx); /*forall<a> maybe<a>*/
    goto _match4577;
  }
  kk_box_t _box_x3163 = _match_4442.fst;
  kk_box_t _box_x3164 = _match_4442.snd;
  kk_std_core__list xs = kk_std_core__list_unbox(_box_x3163, NULL);
  kk_std_core__sslice rest0 = kk_std_core__sslice_unbox(_box_x3164, NULL);
  kk_std_core__sslice_dup(rest0);
  kk_std_core__list_dup(xs);
  kk_std_core_types__tuple2__drop(_match_4442, _ctx);
  kk_std_core_types__tuple2_ _b_3172_3167 = kk_std_core_types__new_dash__lp__comma__rp_(kk_std_core__list_box(xs, _ctx), kk_std_core__sslice_box(rest0, _ctx), _ctx); /*(list<char>, sslice)*/;
  _x4575 = kk_std_core_types__new_Just(kk_std_core_types__tuple2__box(_b_3172_3167, _ctx), _ctx); /*forall<a> maybe<a>*/
  _match4577: ;
  return kk_std_core_types__maybe_box(_x4575, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_chars_are_fun4583__t {
  struct kk_function_s _base;
  kk_string_t msg;
};
static kk_box_t kk_std_text_parse_chars_are_fun4583(kk_function_t _fself, kk_box_t _b_3178, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_chars_are_fun4583(kk_string_t msg, kk_context_t* _ctx) {
  struct kk_std_text_parse_chars_are_fun4583__t* _self = kk_function_alloc_as(struct kk_std_text_parse_chars_are_fun4583__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_text_parse_chars_are_fun4583, kk_context());
  _self->msg = msg;
  return &_self->_base;
}

static kk_box_t kk_std_text_parse_chars_are_fun4583(kk_function_t _fself, kk_box_t _b_3178, kk_context_t* _ctx) {
  struct kk_std_text_parse_chars_are_fun4583__t* _self = kk_function_as(struct kk_std_text_parse_chars_are_fun4583__t*, _fself);
  kk_string_t msg = _self->msg; /* string */
  kk_drop_match(_self, {kk_string_dup(msg);}, {}, _ctx)
  kk_std_core_types__maybe _x4584 = kk_std_core_types__maybe_unbox(_b_3178, _ctx); /*maybe<list<char>>*/
  return kk_std_text_parse__mlift2547_satisfy_fail(msg, _x4584, _ctx);
}

kk_std_core__list kk_std_text_parse_chars_are(kk_string_t msg, kk_function_t pred, kk_context_t* _ctx) { /* (msg : string, pred : (char) -> bool) -> parse list<char> */ 
  kk_std_core_types__maybe x_2614;
  kk_std_core_hnd__ev ev_2574;
  size_t _x4569 = ((size_t)0); /*size_t*/
  ev_2574 = kk_evv_at(_x4569,kk_context()); /*std/core/hnd/ev<std/text/parse/.hnd-parse>*/
  kk_box_t _x4570;
  struct kk_std_core_hnd_Ev* _con4571 = kk_std_core_hnd__as_Ev(ev_2574);
  kk_std_core_hnd__marker m = _con4571->marker;
  kk_box_t _box_x3147 = _con4571->hnd;
  kk_std_text_parse__hnd_parse h = kk_std_text_parse__hnd_parse_unbox(_box_x3147, NULL);
  kk_std_text_parse__hnd_parse_dup(h);
  kk_std_core_hnd__clause1 _match_4441;
  struct kk_std_text_parse__Hnd_parse* _con4573 = kk_std_text_parse__as_Hnd_parse(h);
  kk_std_core_hnd__clause0 _pat00 = _con4573->fun_current_input;
  kk_std_core_hnd__clause1 _pat10 = _con4573->control_fail;
  kk_std_core_hnd__clause0 _pat20 = _con4573->control_pick;
  kk_std_core_hnd__clause1 fun_satisfy = _con4573->fun_satisfy;
  if (kk_std_text_parse__hnd_parse_is_unique(h)) {
    kk_std_core_hnd__clause0_drop(_pat20, _ctx);
    kk_std_core_hnd__clause1_drop(_pat10, _ctx);
    kk_std_core_hnd__clause0_drop(_pat00, _ctx);
    kk_std_text_parse__hnd_parse_free(h);
  }
  else {
    kk_std_core_hnd__clause1_dup(fun_satisfy);
    kk_std_text_parse__hnd_parse_decref(h, _ctx);
  }
  _match_4441 = fun_satisfy; /*forall<a> std/core/hnd/clause1<(sslice) -> total maybe<(a, sslice)>,maybe<a>,std/text/parse/.hnd-parse,3528,3529>*/
  kk_function_t _fun_unbox_x3154 = _match_4441.clause;
  _x4570 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x3154, (_fun_unbox_x3154, m, ev_2574, kk_function_box(kk_std_text_parse_new_chars_are_fun4574(pred, _ctx)), _ctx)); /*53*/
  x_2614 = kk_std_core_types__maybe_unbox(_x4570, _ctx); /*maybe<list<char>>*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__maybe_drop(x_2614, _ctx);
    kk_box_t _x4582 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_chars_are_fun4583(msg, _ctx), _ctx); /*3991*/
    return kk_std_core__list_unbox(_x4582, _ctx);
  }
  if (kk_std_core_types__is_Nothing(x_2614)) {
    kk_box_t _x4585 = kk_std_text_parse_fail(msg, _ctx); /*492*/
    return kk_std_core__list_unbox(_x4585, _ctx);
  }
  kk_box_t _box_x3180 = x_2614._cons.Just.value;
  kk_std_core__list x0 = kk_std_core__list_unbox(_box_x3180, NULL);
  kk_std_core__list_dup(x0);
  kk_std_core_types__maybe_drop(x_2614, _ctx);
  kk_string_drop(msg, _ctx);
  return x0;
}
 
// monadic lift

kk_box_t kk_std_text_parse__mlift2548_choose(kk_function_t p0, kk_std_core__list pp, bool _y_14, kk_context_t* _ctx) { /* forall<a,e> (p0 : parser<e,a>, pp : list<parser<e,a>>, bool) -> <parse|e> a */ 
  if (_y_14) {
    kk_std_core__list_drop(pp, _ctx);
    return kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), p0, (p0, _ctx));
  }
  kk_function_drop(p0, _ctx);
  return kk_std_text_parse_choose(pp, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_choose_fun4600__t {
  struct kk_function_s _base;
  size_t i_2620;
};
static kk_box_t kk_std_text_parse_choose_fun4600(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_choose_fun4600(size_t i_2620, kk_context_t* _ctx) {
  struct kk_std_text_parse_choose_fun4600__t* _self = kk_function_alloc_as(struct kk_std_text_parse_choose_fun4600__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_text_parse_choose_fun4600, kk_context());
  _self->i_2620 = i_2620;
  return &_self->_base;
}

static kk_box_t kk_std_text_parse_choose_fun4600(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_std_text_parse_choose_fun4600__t* _self = kk_function_as(struct kk_std_text_parse_choose_fun4600__t*, _fself);
  size_t i_2620 = _self->i_2620; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_2620, cont, res, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_choose_fun4611__t {
  struct kk_function_s _base;
  size_t i0_2626;
};
static kk_box_t kk_std_text_parse_choose_fun4611(kk_function_t _fself, kk_function_t _b_3224, kk_box_t _b_3225, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_choose_fun4611(size_t i0_2626, kk_context_t* _ctx) {
  struct kk_std_text_parse_choose_fun4611__t* _self = kk_function_alloc_as(struct kk_std_text_parse_choose_fun4611__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_text_parse_choose_fun4611, kk_context());
  _self->i0_2626 = i0_2626;
  return &_self->_base;
}

static kk_box_t kk_std_text_parse_choose_fun4611(kk_function_t _fself, kk_function_t _b_3224, kk_box_t _b_3225, kk_context_t* _ctx) {
  struct kk_std_text_parse_choose_fun4611__t* _self = kk_function_as(struct kk_std_text_parse_choose_fun4611__t*, _fself);
  size_t i0_2626 = _self->i0_2626; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i0_2626, _b_3224, _b_3225, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_choose_fun4612__t {
  struct kk_function_s _base;
  kk_box_t _fun_unbox_x3209;
  kk_std_core__list pp0;
};
static kk_box_t kk_std_text_parse_choose_fun4612(kk_function_t _fself, kk_box_t _b_3235, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_choose_fun4612(kk_box_t _fun_unbox_x3209, kk_std_core__list pp0, kk_context_t* _ctx) {
  struct kk_std_text_parse_choose_fun4612__t* _self = kk_function_alloc_as(struct kk_std_text_parse_choose_fun4612__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_text_parse_choose_fun4612, kk_context());
  _self->_fun_unbox_x3209 = _fun_unbox_x3209;
  _self->pp0 = pp0;
  return &_self->_base;
}

static kk_box_t kk_std_text_parse_choose_fun4612(kk_function_t _fself, kk_box_t _b_3235, kk_context_t* _ctx) {
  struct kk_std_text_parse_choose_fun4612__t* _self = kk_function_as(struct kk_std_text_parse_choose_fun4612__t*, _fself);
  kk_box_t _fun_unbox_x3209 = _self->_fun_unbox_x3209; /* 61 */
  kk_std_core__list pp0 = _self->pp0; /* list<std/text/parse/parser<809,808>> */
  kk_drop_match(_self, {kk_box_dup(_fun_unbox_x3209);kk_std_core__list_dup(pp0);}, {}, _ctx)
  kk_function_t _x4613 = kk_function_unbox(_fun_unbox_x3209); /*() -> <std/text/parse/parse|809> 3210*/
  bool _x4614 = kk_bool_unbox(_b_3235); /*bool*/
  return kk_std_text_parse__mlift2548_choose(_x4613, pp0, _x4614, _ctx);
}

kk_box_t kk_std_text_parse_choose(kk_std_core__list ps, kk_context_t* _ctx) { /* forall<a,e> (ps : list<parser<e,a>>) -> <parse|e> a */ 
  kk__tailcall: ;
  if (kk_std_core__is_Nil(ps)) {
    size_t i_2620;
    kk_std_core_hnd__htag _x4592 = kk_std_core_hnd__htag_dup(kk_std_text_parse__tag_parse); /*std/core/hnd/htag<std/text/parse/.hnd-parse>*/
    i_2620 = kk_std_core_hnd__evv_index(_x4592, _ctx); /*std/core/hnd/ev-index*/
    kk_evv_t w = kk_evv_swap_create1(i_2620,kk_context()); /*std/core/hnd/evv<<std/text/parse/parse|809>>*/;
    kk_box_t y;
    kk_std_core_hnd__ev ev_2571;
    size_t _x4593 = ((size_t)0); /*size_t*/
    ev_2571 = kk_evv_at(_x4593,kk_context()); /*std/core/hnd/ev<std/text/parse/.hnd-parse>*/
    struct kk_std_core_hnd_Ev* _con4594 = kk_std_core_hnd__as_Ev(ev_2571);
    kk_std_core_hnd__marker m = _con4594->marker;
    kk_box_t _box_x3194 = _con4594->hnd;
    kk_std_text_parse__hnd_parse h = kk_std_text_parse__hnd_parse_unbox(_box_x3194, NULL);
    kk_std_text_parse__hnd_parse_dup(h);
    kk_std_core_hnd__clause1 _match_4438;
    struct kk_std_text_parse__Hnd_parse* _con4596 = kk_std_text_parse__as_Hnd_parse(h);
    kk_std_core_hnd__clause0 _pat01 = _con4596->fun_current_input;
    kk_std_core_hnd__clause1 control_fail = _con4596->control_fail;
    kk_std_core_hnd__clause0 _pat10 = _con4596->control_pick;
    kk_std_core_hnd__clause1 _pat20 = _con4596->fun_satisfy;
    if (kk_std_text_parse__hnd_parse_is_unique(h)) {
      kk_std_core_hnd__clause1_drop(_pat20, _ctx);
      kk_std_core_hnd__clause0_drop(_pat10, _ctx);
      kk_std_core_hnd__clause0_drop(_pat01, _ctx);
      kk_std_text_parse__hnd_parse_free(h);
    }
    else {
      kk_std_core_hnd__clause1_dup(control_fail);
      kk_std_text_parse__hnd_parse_decref(h, _ctx);
    }
    _match_4438 = control_fail; /*forall<a> std/core/hnd/clause1<string,a,std/text/parse/.hnd-parse,3528,3529>*/
    kk_function_t _fun_unbox_x3198 = _match_4438.clause;
    kk_box_t _x4597;
    kk_string_t _x4598;
    kk_define_string_literal(, _s4599, 23, "no further alternatives")
    _x4598 = kk_string_dup(_s4599); /*string*/
    _x4597 = kk_string_box(_x4598); /*52*/
    y = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x3198, (_fun_unbox_x3198, m, ev_2571, _x4597, _ctx)); /*808*/
    kk_unit_t __ = kk_Unit;
    kk_evv_set(w,kk_context());
    if (kk_yielding(kk_context())) {
      kk_box_drop(y, _ctx);
      return kk_std_core_hnd_yield_cont(kk_std_text_parse_new_choose_fun4600(i_2620, _ctx), _ctx);
    }
    return y;
  }
  struct kk_std_core_Cons* _con4601 = kk_std_core__as_Cons(ps);
  kk_box_t _fun_unbox_x3206 = _con4601->head;
  kk_std_core__list _pat11 = _con4601->tail;
  if (kk_std_core__is_Nil(_pat11)) {
    if (kk_std_core__list_is_unique(ps)) {
      kk_std_core__list_free(ps);
    }
    else {
      kk_box_dup(_fun_unbox_x3206);
      kk_std_core__list_decref(ps, _ctx);
    }
    kk_function_t _x4602 = kk_function_unbox(_fun_unbox_x3206); /*() -> <std/text/parse/parse|809> 3207*/
    return kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), _x4602, (_x4602, _ctx));
  }
  struct kk_std_core_Cons* _con4603 = kk_std_core__as_Cons(ps);
  kk_box_t _fun_unbox_x3209 = _con4603->head;
  kk_std_core__list pp0 = _con4603->tail;
  if (kk_std_core__list_is_unique(ps)) {
    kk_std_core__list_free(ps);
  }
  else {
    kk_box_dup(_fun_unbox_x3209);
    kk_std_core__list_dup(pp0);
    kk_std_core__list_decref(ps, _ctx);
  }
  bool x0_2623;
  size_t i0_2626;
  kk_std_core_hnd__htag _x4604 = kk_std_core_hnd__htag_dup(kk_std_text_parse__tag_parse); /*std/core/hnd/htag<std/text/parse/.hnd-parse>*/
  i0_2626 = kk_std_core_hnd__evv_index(_x4604, _ctx); /*std/core/hnd/ev-index*/
  kk_evv_t w0 = kk_evv_swap_create1(i0_2626,kk_context()); /*std/core/hnd/evv<<std/text/parse/parse|809>>*/;
  bool y0;
  kk_std_core_hnd__ev ev_2628;
  size_t _x4605 = ((size_t)0); /*size_t*/
  ev_2628 = kk_evv_at(_x4605,kk_context()); /*std/core/hnd/ev<std/text/parse/.hnd-parse>*/
  kk_box_t _x4606;
  struct kk_std_core_hnd_Ev* _con4607 = kk_std_core_hnd__as_Ev(ev_2628);
  kk_std_core_hnd__marker m0 = _con4607->marker;
  kk_box_t _box_x3211 = _con4607->hnd;
  kk_std_text_parse__hnd_parse h0 = kk_std_text_parse__hnd_parse_unbox(_box_x3211, NULL);
  kk_std_text_parse__hnd_parse_dup(h0);
  kk_std_core_hnd__clause0 _match_4436;
  struct kk_std_text_parse__Hnd_parse* _con4609 = kk_std_text_parse__as_Hnd_parse(h0);
  kk_std_core_hnd__clause0 _pat03 = _con4609->fun_current_input;
  kk_std_core_hnd__clause1 _pat12 = _con4609->control_fail;
  kk_std_core_hnd__clause0 control_pick = _con4609->control_pick;
  kk_std_core_hnd__clause1 _pat22 = _con4609->fun_satisfy;
  if (kk_std_text_parse__hnd_parse_is_unique(h0)) {
    kk_std_core_hnd__clause1_drop(_pat22, _ctx);
    kk_std_core_hnd__clause1_drop(_pat12, _ctx);
    kk_std_core_hnd__clause0_drop(_pat03, _ctx);
    kk_std_text_parse__hnd_parse_free(h0);
  }
  else {
    kk_std_core_hnd__clause0_dup(control_pick);
    kk_std_text_parse__hnd_parse_decref(h0, _ctx);
  }
  _match_4436 = control_pick; /*std/core/hnd/clause0<bool,std/text/parse/.hnd-parse,3435,3436>*/
  kk_function_t _fun_unbox_x3214 = _match_4436.clause;
  _x4606 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x3214, (_fun_unbox_x3214, m0, ev_2628, _ctx)); /*37*/
  y0 = kk_bool_unbox(_x4606); /*bool*/
  kk_unit_t __0 = kk_Unit;
  kk_evv_set(w0,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x4610 = kk_std_core_hnd_yield_cont(kk_std_text_parse_new_choose_fun4611(i0_2626, _ctx), _ctx); /*3820*/
    x0_2623 = kk_bool_unbox(_x4610); /*bool*/
  }
  else {
    x0_2623 = y0; /*bool*/
  }
  if (kk_yielding(kk_context())) {
    return kk_std_core_hnd_yield_extend(kk_std_text_parse_new_choose_fun4612(_fun_unbox_x3209, pp0, _ctx), _ctx);
  }
  if (x0_2623) {
    kk_std_core__list_drop(pp0, _ctx);
    kk_function_t _x4615 = kk_function_unbox(_fun_unbox_x3209); /*() -> <std/text/parse/parse|809> 3210*/
    return kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), _x4615, (_x4615, _ctx));
  }
  kk_box_drop(_fun_unbox_x3209, _ctx);
  { // tailcall
    ps = pp0;
    goto kk__tailcall;
  }
}
 
// monadic lift

kk_std_core__list kk_std_text_parse__mlift2549_count_acc(kk_std_core__list acc, kk_integer_t n, kk_function_t p, kk_box_t x, kk_context_t* _ctx) { /* forall<a,e> (acc : list<a>, n : int, p : parser<e,a>, x : a) -> <parse|e> list<a> */ 
  kk_integer_t _x4616 = kk_integer_sub(n,(kk_integer_from_small(1)),kk_context()); /*int*/
  kk_std_core__list _x4617 = kk_std_core__new_Cons(kk_reuse_null, x, acc, _ctx); /*list<61>*/
  return kk_std_text_parse_count_acc(_x4616, _x4617, p, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_count_acc_fun4621__t {
  struct kk_function_s _base;
  kk_std_core__list acc0;
  kk_integer_t n0;
  kk_function_t p0;
};
static kk_box_t kk_std_text_parse_count_acc_fun4621(kk_function_t _fself, kk_box_t _b_3239, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_count_acc_fun4621(kk_std_core__list acc0, kk_integer_t n0, kk_function_t p0, kk_context_t* _ctx) {
  struct kk_std_text_parse_count_acc_fun4621__t* _self = kk_function_alloc_as(struct kk_std_text_parse_count_acc_fun4621__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_text_parse_count_acc_fun4621, kk_context());
  _self->acc0 = acc0;
  _self->n0 = n0;
  _self->p0 = p0;
  return &_self->_base;
}

static kk_box_t kk_std_text_parse_count_acc_fun4621(kk_function_t _fself, kk_box_t _b_3239, kk_context_t* _ctx) {
  struct kk_std_text_parse_count_acc_fun4621__t* _self = kk_function_as(struct kk_std_text_parse_count_acc_fun4621__t*, _fself);
  kk_std_core__list acc0 = _self->acc0; /* list<881> */
  kk_integer_t n0 = _self->n0; /* int */
  kk_function_t p0 = _self->p0; /* std/text/parse/parser<882,881> */
  kk_drop_match(_self, {kk_std_core__list_dup(acc0);kk_integer_dup(n0);kk_function_dup(p0);}, {}, _ctx)
  kk_std_core__list _x4622 = kk_std_text_parse__mlift2549_count_acc(acc0, n0, p0, _b_3239, _ctx); /*list<881>*/
  return kk_std_core__list_box(_x4622, _ctx);
}

kk_std_core__list kk_std_text_parse_count_acc(kk_integer_t n0, kk_std_core__list acc0, kk_function_t p0, kk_context_t* _ctx) { /* forall<a,e> (n : int, acc : list<a>, p : parser<e,a>) -> <parse|e> list<a> */ 
  kk__tailcall: ;
  bool _match_4432;
  kk_integer_t _x4618 = kk_integer_dup(n0); /*int*/
  _match_4432 = kk_integer_lte(_x4618,(kk_integer_from_small(0)),kk_context()); /*bool*/
  if (_match_4432) {
    kk_integer_drop(n0, _ctx);
    kk_function_drop(p0, _ctx);
    return kk_std_core_reverse(acc0, _ctx);
  }
  kk_box_t x_2631;
  kk_function_t _x4619 = kk_function_dup(p0); /*std/text/parse/parser<882,881>*/
  x_2631 = kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), _x4619, (_x4619, _ctx)); /*881*/
  if (kk_yielding(kk_context())) {
    kk_box_drop(x_2631, _ctx);
    kk_box_t _x4620 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_count_acc_fun4621(acc0, n0, p0, _ctx), _ctx); /*3991*/
    return kk_std_core__list_unbox(_x4620, _ctx);
  }
  { // tailcall
    kk_integer_t _x4623 = kk_integer_sub(n0,(kk_integer_from_small(1)),kk_context()); /*int*/
    kk_std_core__list _x4624 = kk_std_core__new_Cons(kk_reuse_null, x_2631, acc0, _ctx); /*list<61>*/
    n0 = _x4623;
    acc0 = _x4624;
    goto kk__tailcall;
  }
}
 
// monadic lift

kk_integer_t kk_std_text_parse__mlift2550_digit(kk_char_t c, kk_context_t* _ctx) { /* (c : char) -> parse int */ 
  kk_char_t _x4630;
  kk_integer_t _x4631;
  kk_integer_t _x4632 = kk_integer_from_int(c,kk_context()); /*int*/
  kk_integer_t _x4633 = kk_integer_from_int(('0'),kk_context()); /*int*/
  _x4631 = kk_integer_sub(_x4632,_x4633,kk_context()); /*int*/
  _x4630 = kk_integer_clamp32(_x4631,kk_context()); /*char*/
  return kk_integer_from_int(_x4630,kk_context());
}


// lift anonymous function
struct kk_std_text_parse_digit_fun4639__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse_digit_fun4639(kk_function_t _fself, kk_box_t _b_3263, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_digit_fun4639(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_digit_fun4639, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_text_parse_digit_fun4639(kk_function_t _fself, kk_box_t _b_3263, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core_types__maybe _x4640;
  kk_std_core_types__maybe _match_4430;
  kk_std_core__sslice _x4641 = kk_std_core__sslice_unbox(_b_3263, _ctx); /*sslice*/
  _match_4430 = kk_std_core_next(_x4641, _ctx); /*maybe<(char, sslice)>*/
  if (kk_std_core_types__is_Just(_match_4430)) {
    kk_box_t _box_x3264 = _match_4430._cons.Just.value;
    kk_std_core_types__tuple2_ _pat02 = kk_std_core_types__tuple2__unbox(_box_x3264, NULL);
    if (kk_std_core_types__is_dash__lp__comma__rp_(_pat02)) {
      kk_box_t _box_x3265 = _pat02.fst;
      kk_box_t _box_x3266 = _pat02.snd;
      kk_char_t c = kk_char_unbox(_box_x3265, NULL);
      kk_std_core__sslice rest0 = kk_std_core__sslice_unbox(_box_x3266, NULL);
      if (kk_std_core_is_digit(c, _ctx)) {
        kk_std_core__sslice_dup(rest0);
        kk_std_core_types__maybe_drop(_match_4430, _ctx);
        kk_std_core_types__tuple2_ _b_3274_3269 = kk_std_core_types__new_dash__lp__comma__rp_(kk_char_box(c, _ctx), kk_std_core__sslice_box(rest0, _ctx), _ctx); /*(char, sslice)*/;
        _x4640 = kk_std_core_types__new_Just(kk_std_core_types__tuple2__box(_b_3274_3269, _ctx), _ctx); /*maybe<103>*/
        goto _match4642;
      }
    }
  }
  kk_std_core_types__maybe_drop(_match_4430, _ctx);
  _x4640 = kk_std_core_types__new_Nothing(_ctx); /*maybe<103>*/
  _match4642: ;
  return kk_std_core_types__maybe_box(_x4640, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_digit_fun4647__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse_digit_fun4647(kk_function_t _fself, kk_box_t _b_3280, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_digit_fun4647(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_digit_fun4647, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_text_parse_digit_fun4647(kk_function_t _fself, kk_box_t _b_3280, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x4648;
  kk_define_string_literal(, _s4649, 5, "digit")
  _x4648 = kk_string_dup(_s4649); /*string*/
  kk_std_core_types__maybe _x4650 = kk_std_core_types__maybe_unbox(_b_3280, _ctx); /*maybe<char>*/
  return kk_std_text_parse__mlift2547_satisfy_fail(_x4648, _x4650, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_digit_fun4656__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse_digit_fun4656(kk_function_t _fself, kk_box_t _b_3289, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_digit_fun4656(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_digit_fun4656, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_text_parse_digit_fun4656(kk_function_t _fself, kk_box_t _b_3289, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_integer_t _x4657;
  kk_char_t _x4658 = kk_char_unbox(_b_3289, _ctx); /*char*/
  _x4657 = kk_std_text_parse__mlift2550_digit(_x4658, _ctx); /*int*/
  return kk_integer_box(_x4657);
}

kk_integer_t kk_std_text_parse_digit(kk_context_t* _ctx) { /* () -> parse int */ 
  kk_char_t x_2639;
  kk_std_core_types__maybe x0_2646;
  kk_std_core_hnd__ev ev_2574;
  size_t _x4634 = ((size_t)0); /*size_t*/
  ev_2574 = kk_evv_at(_x4634,kk_context()); /*std/core/hnd/ev<std/text/parse/.hnd-parse>*/
  kk_box_t _x4635;
  struct kk_std_core_hnd_Ev* _con4636 = kk_std_core_hnd__as_Ev(ev_2574);
  kk_std_core_hnd__marker m = _con4636->marker;
  kk_box_t _box_x3250 = _con4636->hnd;
  kk_std_text_parse__hnd_parse h = kk_std_text_parse__hnd_parse_unbox(_box_x3250, NULL);
  kk_std_text_parse__hnd_parse_dup(h);
  kk_std_core_hnd__clause1 _match_4429;
  struct kk_std_text_parse__Hnd_parse* _con4638 = kk_std_text_parse__as_Hnd_parse(h);
  kk_std_core_hnd__clause0 _pat00 = _con4638->fun_current_input;
  kk_std_core_hnd__clause1 _pat10 = _con4638->control_fail;
  kk_std_core_hnd__clause0 _pat20 = _con4638->control_pick;
  kk_std_core_hnd__clause1 fun_satisfy = _con4638->fun_satisfy;
  if (kk_std_text_parse__hnd_parse_is_unique(h)) {
    kk_std_core_hnd__clause0_drop(_pat20, _ctx);
    kk_std_core_hnd__clause1_drop(_pat10, _ctx);
    kk_std_core_hnd__clause0_drop(_pat00, _ctx);
    kk_std_text_parse__hnd_parse_free(h);
  }
  else {
    kk_std_core_hnd__clause1_dup(fun_satisfy);
    kk_std_text_parse__hnd_parse_decref(h, _ctx);
  }
  _match_4429 = fun_satisfy; /*forall<a> std/core/hnd/clause1<(sslice) -> total maybe<(a, sslice)>,maybe<a>,std/text/parse/.hnd-parse,3528,3529>*/
  kk_function_t _fun_unbox_x3257 = _match_4429.clause;
  _x4635 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x3257, (_fun_unbox_x3257, m, ev_2574, kk_function_box(kk_std_text_parse_new_digit_fun4639(_ctx)), _ctx)); /*53*/
  x0_2646 = kk_std_core_types__maybe_unbox(_x4635, _ctx); /*maybe<char>*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__maybe_drop(x0_2646, _ctx);
    kk_box_t _x4646 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_digit_fun4647(_ctx), _ctx); /*3991*/
    x_2639 = kk_char_unbox(_x4646, _ctx); /*char*/
  }
  else {
    if (kk_std_core_types__is_Nothing(x0_2646)) {
      kk_box_t _x4651;
      kk_string_t _x4652;
      kk_define_string_literal(, _s4653, 5, "digit")
      _x4652 = kk_string_dup(_s4653); /*string*/
      _x4651 = kk_std_text_parse_fail(_x4652, _ctx); /*492*/
      x_2639 = kk_char_unbox(_x4651, _ctx); /*char*/
    }
    else {
      kk_box_t _box_x3282 = x0_2646._cons.Just.value;
      kk_char_t x1 = kk_char_unbox(_box_x3282, NULL);
      kk_std_core_types__maybe_drop(x0_2646, _ctx);
      x_2639 = x1; /*char*/
    }
  }
  if (kk_yielding(kk_context())) {
    kk_box_t _x4655 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_digit_fun4656(_ctx), _ctx); /*3991*/
    return kk_integer_unbox(_x4655);
  }
  kk_char_t _x4659;
  kk_integer_t _x4660;
  kk_integer_t _x4661 = kk_integer_from_int(x_2639,kk_context()); /*int*/
  kk_integer_t _x4662 = kk_integer_from_int(('0'),kk_context()); /*int*/
  _x4660 = kk_integer_sub(_x4661,_x4662,kk_context()); /*int*/
  _x4659 = kk_integer_clamp32(_x4660,kk_context()); /*char*/
  return kk_integer_from_int(_x4659,kk_context());
}


// lift anonymous function
struct kk_std_text_parse_digits_fun4668__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse_digits_fun4668(kk_function_t _fself, kk_box_t _b_3304, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_digits_fun4668(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_digits_fun4668, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_std_text_parse_digits_fun4672__t {
  struct kk_function_s _base;
};
static bool kk_std_text_parse_digits_fun4672(kk_function_t _fself, kk_char_t _x14671, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_digits_fun4672(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_digits_fun4672, _ctx)
  return kk_function_dup(_fself);
}

static bool kk_std_text_parse_digits_fun4672(kk_function_t _fself, kk_char_t _x14671, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return kk_std_core_is_digit(_x14671, _ctx);
}
static kk_box_t kk_std_text_parse_digits_fun4668(kk_function_t _fself, kk_box_t _b_3304, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core_types__maybe _x4669;
  kk_std_core_types__tuple2_ _match_4426;
  kk_std_core__sslice _x4670 = kk_std_core__sslice_unbox(_b_3304, _ctx); /*sslice*/
  _match_4426 = kk_std_text_parse_next_while0(_x4670, kk_std_text_parse_new_digits_fun4672(_ctx), kk_std_core__new_Nil(_ctx), _ctx); /*(list<char>, sslice)*/
  kk_box_t _box_x3305 = _match_4426.fst;
  kk_box_t _box_x3306 = _match_4426.snd;
  kk_std_core__list _pat02 = kk_std_core__list_unbox(_box_x3305, NULL);
  kk_std_core__sslice _pat100 = kk_std_core__sslice_unbox(_box_x3306, NULL);
  if (kk_std_core__is_Nil(_pat02)) {
    kk_std_core_types__tuple2__drop(_match_4426, _ctx);
    _x4669 = kk_std_core_types__new_Nothing(_ctx); /*forall<a> maybe<a>*/
    goto _match4673;
  }
  kk_box_t _box_x3307 = _match_4426.fst;
  kk_box_t _box_x3308 = _match_4426.snd;
  kk_std_core__list xs = kk_std_core__list_unbox(_box_x3307, NULL);
  kk_std_core__sslice rest0 = kk_std_core__sslice_unbox(_box_x3308, NULL);
  kk_std_core__sslice_dup(rest0);
  kk_std_core__list_dup(xs);
  kk_std_core_types__tuple2__drop(_match_4426, _ctx);
  kk_std_core_types__tuple2_ _b_3316_3311 = kk_std_core_types__new_dash__lp__comma__rp_(kk_std_core__list_box(xs, _ctx), kk_std_core__sslice_box(rest0, _ctx), _ctx); /*(list<char>, sslice)*/;
  _x4669 = kk_std_core_types__new_Just(kk_std_core_types__tuple2__box(_b_3316_3311, _ctx), _ctx); /*forall<a> maybe<a>*/
  _match4673: ;
  return kk_std_core_types__maybe_box(_x4669, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_digits_fun4679__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse_digits_fun4679(kk_function_t _fself, kk_box_t _b_3322, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_digits_fun4679(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_digits_fun4679, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_text_parse_digits_fun4679(kk_function_t _fself, kk_box_t _b_3322, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x4680;
  kk_define_string_literal(, _s4681, 5, "digit")
  _x4680 = kk_string_dup(_s4681); /*string*/
  kk_std_core_types__maybe _x4682 = kk_std_core_types__maybe_unbox(_b_3322, _ctx); /*maybe<list<char>>*/
  return kk_std_text_parse__mlift2547_satisfy_fail(_x4680, _x4682, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_digits_fun4688__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse_digits_fun4688(kk_function_t _fself, kk_box_t _b_3331, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_digits_fun4688(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_digits_fun4688, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_text_parse_digits_fun4688(kk_function_t _fself, kk_box_t _b_3331, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x4689;
  kk_std_core__list _x4690 = kk_std_core__list_unbox(_b_3331, _ctx); /*list<char>*/
  _x4689 = kk_std_core_string_2(_x4690, _ctx); /*string*/
  return kk_string_box(_x4689);
}

kk_string_t kk_std_text_parse_digits(kk_context_t* _ctx) { /* () -> parse string */ 
  kk_std_core__list x_2653;
  kk_std_core_types__maybe x0_2659;
  kk_std_core_hnd__ev ev_2574;
  size_t _x4663 = ((size_t)0); /*size_t*/
  ev_2574 = kk_evv_at(_x4663,kk_context()); /*std/core/hnd/ev<std/text/parse/.hnd-parse>*/
  kk_box_t _x4664;
  struct kk_std_core_hnd_Ev* _con4665 = kk_std_core_hnd__as_Ev(ev_2574);
  kk_std_core_hnd__marker m = _con4665->marker;
  kk_box_t _box_x3291 = _con4665->hnd;
  kk_std_text_parse__hnd_parse h = kk_std_text_parse__hnd_parse_unbox(_box_x3291, NULL);
  kk_std_text_parse__hnd_parse_dup(h);
  kk_std_core_hnd__clause1 _match_4425;
  struct kk_std_text_parse__Hnd_parse* _con4667 = kk_std_text_parse__as_Hnd_parse(h);
  kk_std_core_hnd__clause0 _pat00 = _con4667->fun_current_input;
  kk_std_core_hnd__clause1 _pat10 = _con4667->control_fail;
  kk_std_core_hnd__clause0 _pat20 = _con4667->control_pick;
  kk_std_core_hnd__clause1 fun_satisfy = _con4667->fun_satisfy;
  if (kk_std_text_parse__hnd_parse_is_unique(h)) {
    kk_std_core_hnd__clause0_drop(_pat20, _ctx);
    kk_std_core_hnd__clause1_drop(_pat10, _ctx);
    kk_std_core_hnd__clause0_drop(_pat00, _ctx);
    kk_std_text_parse__hnd_parse_free(h);
  }
  else {
    kk_std_core_hnd__clause1_dup(fun_satisfy);
    kk_std_text_parse__hnd_parse_decref(h, _ctx);
  }
  _match_4425 = fun_satisfy; /*forall<a> std/core/hnd/clause1<(sslice) -> total maybe<(a, sslice)>,maybe<a>,std/text/parse/.hnd-parse,3528,3529>*/
  kk_function_t _fun_unbox_x3298 = _match_4425.clause;
  _x4664 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x3298, (_fun_unbox_x3298, m, ev_2574, kk_function_box(kk_std_text_parse_new_digits_fun4668(_ctx)), _ctx)); /*53*/
  x0_2659 = kk_std_core_types__maybe_unbox(_x4664, _ctx); /*maybe<list<char>>*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__maybe_drop(x0_2659, _ctx);
    kk_box_t _x4678 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_digits_fun4679(_ctx), _ctx); /*3991*/
    x_2653 = kk_std_core__list_unbox(_x4678, _ctx); /*list<char>*/
  }
  else {
    if (kk_std_core_types__is_Nothing(x0_2659)) {
      kk_box_t _x4683;
      kk_string_t _x4684;
      kk_define_string_literal(, _s4685, 5, "digit")
      _x4684 = kk_string_dup(_s4685); /*string*/
      _x4683 = kk_std_text_parse_fail(_x4684, _ctx); /*492*/
      x_2653 = kk_std_core__list_unbox(_x4683, _ctx); /*list<char>*/
    }
    else {
      kk_box_t _box_x3324 = x0_2659._cons.Just.value;
      kk_std_core__list x1 = kk_std_core__list_unbox(_box_x3324, NULL);
      kk_std_core__list_dup(x1);
      kk_std_core_types__maybe_drop(x0_2659, _ctx);
      x_2653 = x1; /*list<char>*/
    }
  }
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_2653, _ctx);
    kk_box_t _x4687 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_digits_fun4688(_ctx), _ctx); /*3991*/
    return kk_string_unbox(_x4687);
  }
  return kk_std_core_string_2(x_2653, _ctx);
}
 
// monadic lift

kk_box_t kk_std_text_parse__mlift2551_op(kk_function_t p1, kk_function_t p2, bool _y_26, kk_context_t* _ctx) { /* forall<a,e> (p1 : parser<e,a>, p2 : parser<e,a>, bool) -> <parse|e> a */ 
  if (_y_26) {
    kk_function_drop(p2, _ctx);
    return kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), p1, (p1, _ctx));
  }
  kk_function_drop(p1, _ctx);
  return kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), p2, (p2, _ctx));
}


// lift anonymous function
struct kk_std_text_parse__lp__bar__bar__fun4698__t_rp_ {
  struct kk_function_s _base;
  size_t i_2666;
};
static kk_box_t kk_std_text_parse__lp__bar__bar__fun4698_rp_(kk_function_t _fself, kk_function_t _b_3346, kk_box_t _b_3347, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_dash__bar__bar__fun4698(size_t i_2666, kk_context_t* _ctx) {
  struct kk_std_text_parse__lp__bar__bar__fun4698__t_rp_* _self = kk_function_alloc_as(struct kk_std_text_parse__lp__bar__bar__fun4698__t_rp_, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_text_parse__lp__bar__bar__fun4698_rp_, kk_context());
  _self->i_2666 = i_2666;
  return &_self->_base;
}

static kk_box_t kk_std_text_parse__lp__bar__bar__fun4698_rp_(kk_function_t _fself, kk_function_t _b_3346, kk_box_t _b_3347, kk_context_t* _ctx) {
  struct kk_std_text_parse__lp__bar__bar__fun4698__t_rp_* _self = kk_function_as(struct kk_std_text_parse__lp__bar__bar__fun4698__t_rp_*, _fself);
  size_t i_2666 = _self->i_2666; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_2666, _b_3346, _b_3347, _ctx);
}


// lift anonymous function
struct kk_std_text_parse__lp__bar__bar__fun4699__t_rp_ {
  struct kk_function_s _base;
  kk_function_t p1;
  kk_function_t p2;
};
static kk_box_t kk_std_text_parse__lp__bar__bar__fun4699_rp_(kk_function_t _fself, kk_box_t _b_3357, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_dash__bar__bar__fun4699(kk_function_t p1, kk_function_t p2, kk_context_t* _ctx) {
  struct kk_std_text_parse__lp__bar__bar__fun4699__t_rp_* _self = kk_function_alloc_as(struct kk_std_text_parse__lp__bar__bar__fun4699__t_rp_, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_text_parse__lp__bar__bar__fun4699_rp_, kk_context());
  _self->p1 = p1;
  _self->p2 = p2;
  return &_self->_base;
}

static kk_box_t kk_std_text_parse__lp__bar__bar__fun4699_rp_(kk_function_t _fself, kk_box_t _b_3357, kk_context_t* _ctx) {
  struct kk_std_text_parse__lp__bar__bar__fun4699__t_rp_* _self = kk_function_as(struct kk_std_text_parse__lp__bar__bar__fun4699__t_rp_*, _fself);
  kk_function_t p1 = _self->p1; /* std/text/parse/parser<1033,1032> */
  kk_function_t p2 = _self->p2; /* std/text/parse/parser<1033,1032> */
  kk_drop_match(_self, {kk_function_dup(p1);kk_function_dup(p2);}, {}, _ctx)
  bool _x4700 = kk_bool_unbox(_b_3357); /*bool*/
  return kk_std_text_parse__mlift2551_op(p1, p2, _x4700, _ctx);
}

kk_box_t kk_std_text_parse__lp__bar__bar__rp_(kk_function_t p1, kk_function_t p2, kk_context_t* _ctx) { /* forall<a,e> (p1 : parser<e,a>, p2 : parser<e,a>) -> <parse|e> a */ 
  bool x_2663;
  size_t i_2666;
  kk_std_core_hnd__htag _x4691 = kk_std_core_hnd__htag_dup(kk_std_text_parse__tag_parse); /*std/core/hnd/htag<std/text/parse/.hnd-parse>*/
  i_2666 = kk_std_core_hnd__evv_index(_x4691, _ctx); /*std/core/hnd/ev-index*/
  kk_evv_t w = kk_evv_swap_create1(i_2666,kk_context()); /*std/core/hnd/evv<<std/text/parse/parse|1033>>*/;
  bool y;
  kk_std_core_hnd__ev ev_2668;
  size_t _x4692 = ((size_t)0); /*size_t*/
  ev_2668 = kk_evv_at(_x4692,kk_context()); /*std/core/hnd/ev<std/text/parse/.hnd-parse>*/
  kk_box_t _x4693;
  struct kk_std_core_hnd_Ev* _con4694 = kk_std_core_hnd__as_Ev(ev_2668);
  kk_std_core_hnd__marker m = _con4694->marker;
  kk_box_t _box_x3333 = _con4694->hnd;
  kk_std_text_parse__hnd_parse h = kk_std_text_parse__hnd_parse_unbox(_box_x3333, NULL);
  kk_std_text_parse__hnd_parse_dup(h);
  kk_std_core_hnd__clause0 _match_4422;
  struct kk_std_text_parse__Hnd_parse* _con4696 = kk_std_text_parse__as_Hnd_parse(h);
  kk_std_core_hnd__clause0 _pat0 = _con4696->fun_current_input;
  kk_std_core_hnd__clause1 _pat1 = _con4696->control_fail;
  kk_std_core_hnd__clause0 control_pick = _con4696->control_pick;
  kk_std_core_hnd__clause1 _pat21 = _con4696->fun_satisfy;
  if (kk_std_text_parse__hnd_parse_is_unique(h)) {
    kk_std_core_hnd__clause1_drop(_pat21, _ctx);
    kk_std_core_hnd__clause1_drop(_pat1, _ctx);
    kk_std_core_hnd__clause0_drop(_pat0, _ctx);
    kk_std_text_parse__hnd_parse_free(h);
  }
  else {
    kk_std_core_hnd__clause0_dup(control_pick);
    kk_std_text_parse__hnd_parse_decref(h, _ctx);
  }
  _match_4422 = control_pick; /*std/core/hnd/clause0<bool,std/text/parse/.hnd-parse,3435,3436>*/
  kk_function_t _fun_unbox_x3336 = _match_4422.clause;
  _x4693 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x3336, (_fun_unbox_x3336, m, ev_2668, _ctx)); /*37*/
  y = kk_bool_unbox(_x4693); /*bool*/
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x4697 = kk_std_core_hnd_yield_cont(kk_std_text_parse_new_dash__bar__bar__fun4698(i_2666, _ctx), _ctx); /*3820*/
    x_2663 = kk_bool_unbox(_x4697); /*bool*/
  }
  else {
    x_2663 = y; /*bool*/
  }
  if (kk_yielding(kk_context())) {
    return kk_std_core_hnd_yield_extend(kk_std_text_parse_new_dash__bar__bar__fun4699(p1, p2, _ctx), _ctx);
  }
  if (x_2663) {
    kk_function_drop(p2, _ctx);
    return kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), p1, (p1, _ctx));
  }
  kk_function_drop(p1, _ctx);
  return kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), p2, (p2, _ctx));
}


// lift anonymous function
struct kk_std_text_parse_optional_fun4708__t {
  struct kk_function_s _base;
  size_t i_2666;
};
static kk_box_t kk_std_text_parse_optional_fun4708(kk_function_t _fself, kk_function_t _b_3373, kk_box_t _b_3374, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_optional_fun4708(size_t i_2666, kk_context_t* _ctx) {
  struct kk_std_text_parse_optional_fun4708__t* _self = kk_function_alloc_as(struct kk_std_text_parse_optional_fun4708__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_text_parse_optional_fun4708, kk_context());
  _self->i_2666 = i_2666;
  return &_self->_base;
}

static kk_box_t kk_std_text_parse_optional_fun4708(kk_function_t _fself, kk_function_t _b_3373, kk_box_t _b_3374, kk_context_t* _ctx) {
  struct kk_std_text_parse_optional_fun4708__t* _self = kk_function_as(struct kk_std_text_parse_optional_fun4708__t*, _fself);
  size_t i_2666 = _self->i_2666; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_2666, _b_3373, _b_3374, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_optional_fun4709__t {
  struct kk_function_s _base;
  kk_box_t kkloc_default;
  kk_function_t p;
};
static kk_box_t kk_std_text_parse_optional_fun4709(kk_function_t _fself, kk_box_t _b_3384, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_optional_fun4709(kk_box_t kkloc_default, kk_function_t p, kk_context_t* _ctx) {
  struct kk_std_text_parse_optional_fun4709__t* _self = kk_function_alloc_as(struct kk_std_text_parse_optional_fun4709__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_text_parse_optional_fun4709, kk_context());
  _self->kkloc_default = kkloc_default;
  _self->p = p;
  return &_self->_base;
}



// lift anonymous function
struct kk_std_text_parse_optional_fun4710__t {
  struct kk_function_s _base;
  kk_box_t kkloc_default;
};
static kk_box_t kk_std_text_parse_optional_fun4710(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_optional_fun4710(kk_box_t kkloc_default, kk_context_t* _ctx) {
  struct kk_std_text_parse_optional_fun4710__t* _self = kk_function_alloc_as(struct kk_std_text_parse_optional_fun4710__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_text_parse_optional_fun4710, kk_context());
  _self->kkloc_default = kkloc_default;
  return &_self->_base;
}

static kk_box_t kk_std_text_parse_optional_fun4710(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_text_parse_optional_fun4710__t* _self = kk_function_as(struct kk_std_text_parse_optional_fun4710__t*, _fself);
  kk_box_t kkloc_default = _self->kkloc_default; /* 1080 */
  kk_drop_match(_self, {kk_box_dup(kkloc_default);}, {}, _ctx)
  return kkloc_default;
}
static kk_box_t kk_std_text_parse_optional_fun4709(kk_function_t _fself, kk_box_t _b_3384, kk_context_t* _ctx) {
  struct kk_std_text_parse_optional_fun4709__t* _self = kk_function_as(struct kk_std_text_parse_optional_fun4709__t*, _fself);
  kk_box_t kkloc_default = _self->kkloc_default; /* 1080 */
  kk_function_t p = _self->p; /* std/text/parse/parser<1081,1080> */
  kk_drop_match(_self, {kk_box_dup(kkloc_default);kk_function_dup(p);}, {}, _ctx)
  bool _x4711 = kk_bool_unbox(_b_3384); /*bool*/
  return kk_std_text_parse__mlift2551_op(p, kk_std_text_parse_new_optional_fun4710(kkloc_default, _ctx), _x4711, _ctx);
}

kk_box_t kk_std_text_parse_optional(kk_box_t kkloc_default, kk_function_t p, kk_context_t* _ctx) { /* forall<a,e> (default : a, p : parser<e,a>) -> <parse|e> a */ 
  bool x_2663;
  size_t i_2666;
  kk_std_core_hnd__htag _x4701 = kk_std_core_hnd__htag_dup(kk_std_text_parse__tag_parse); /*std/core/hnd/htag<std/text/parse/.hnd-parse>*/
  i_2666 = kk_std_core_hnd__evv_index(_x4701, _ctx); /*std/core/hnd/ev-index*/
  kk_evv_t w = kk_evv_swap_create1(i_2666,kk_context()); /*std/core/hnd/evv<<std/text/parse/parse|1081>>*/;
  bool y;
  kk_std_core_hnd__ev ev_2668;
  size_t _x4702 = ((size_t)0); /*size_t*/
  ev_2668 = kk_evv_at(_x4702,kk_context()); /*std/core/hnd/ev<std/text/parse/.hnd-parse>*/
  kk_box_t _x4703;
  struct kk_std_core_hnd_Ev* _con4704 = kk_std_core_hnd__as_Ev(ev_2668);
  kk_std_core_hnd__marker m = _con4704->marker;
  kk_box_t _box_x3360 = _con4704->hnd;
  kk_std_text_parse__hnd_parse h = kk_std_text_parse__hnd_parse_unbox(_box_x3360, NULL);
  kk_std_text_parse__hnd_parse_dup(h);
  kk_std_core_hnd__clause0 _match_4419;
  struct kk_std_text_parse__Hnd_parse* _con4706 = kk_std_text_parse__as_Hnd_parse(h);
  kk_std_core_hnd__clause0 _pat0 = _con4706->fun_current_input;
  kk_std_core_hnd__clause1 _pat1 = _con4706->control_fail;
  kk_std_core_hnd__clause0 control_pick = _con4706->control_pick;
  kk_std_core_hnd__clause1 _pat21 = _con4706->fun_satisfy;
  if (kk_std_text_parse__hnd_parse_is_unique(h)) {
    kk_std_core_hnd__clause1_drop(_pat21, _ctx);
    kk_std_core_hnd__clause1_drop(_pat1, _ctx);
    kk_std_core_hnd__clause0_drop(_pat0, _ctx);
    kk_std_text_parse__hnd_parse_free(h);
  }
  else {
    kk_std_core_hnd__clause0_dup(control_pick);
    kk_std_text_parse__hnd_parse_decref(h, _ctx);
  }
  _match_4419 = control_pick; /*std/core/hnd/clause0<bool,std/text/parse/.hnd-parse,3435,3436>*/
  kk_function_t _fun_unbox_x3363 = _match_4419.clause;
  _x4703 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x3363, (_fun_unbox_x3363, m, ev_2668, _ctx)); /*37*/
  y = kk_bool_unbox(_x4703); /*bool*/
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x4707 = kk_std_core_hnd_yield_cont(kk_std_text_parse_new_optional_fun4708(i_2666, _ctx), _ctx); /*3820*/
    x_2663 = kk_bool_unbox(_x4707); /*bool*/
  }
  else {
    x_2663 = y; /*bool*/
  }
  if (kk_yielding(kk_context())) {
    return kk_std_core_hnd_yield_extend(kk_std_text_parse_new_optional_fun4709(kkloc_default, p, _ctx), _ctx);
  }
  if (x_2663) {
    kk_box_drop(kkloc_default, _ctx);
    return kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), p, (p, _ctx));
  }
  kk_function_drop(p, _ctx);
  return kkloc_default;
}


// lift anonymous function
struct kk_std_text_parse_digits0_fun4712__t {
  struct kk_function_s _base;
};
static kk_string_t kk_std_text_parse_digits0_fun4712(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_digits0_fun4712(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_digits0_fun4712, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_std_text_parse_digits0_fun4718__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse_digits0_fun4718(kk_function_t _fself, kk_box_t _b_3400, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_digits0_fun4718(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_digits0_fun4718, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_std_text_parse_digits0_fun4722__t {
  struct kk_function_s _base;
};
static bool kk_std_text_parse_digits0_fun4722(kk_function_t _fself, kk_char_t _x14721, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_digits0_fun4722(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_digits0_fun4722, _ctx)
  return kk_function_dup(_fself);
}

static bool kk_std_text_parse_digits0_fun4722(kk_function_t _fself, kk_char_t _x14721, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return kk_std_core_is_digit(_x14721, _ctx);
}
static kk_box_t kk_std_text_parse_digits0_fun4718(kk_function_t _fself, kk_box_t _b_3400, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core_types__maybe _x4719;
  kk_std_core_types__tuple2_ _match_4416;
  kk_std_core__sslice _x4720 = kk_std_core__sslice_unbox(_b_3400, _ctx); /*sslice*/
  _match_4416 = kk_std_text_parse_next_while0(_x4720, kk_std_text_parse_new_digits0_fun4722(_ctx), kk_std_core__new_Nil(_ctx), _ctx); /*(list<char>, sslice)*/
  kk_box_t _box_x3401 = _match_4416.fst;
  kk_box_t _box_x3402 = _match_4416.snd;
  kk_std_core__list _pat021 = kk_std_core__list_unbox(_box_x3401, NULL);
  kk_std_core__sslice _pat100 = kk_std_core__sslice_unbox(_box_x3402, NULL);
  if (kk_std_core__is_Nil(_pat021)) {
    kk_std_core_types__tuple2__drop(_match_4416, _ctx);
    _x4719 = kk_std_core_types__new_Nothing(_ctx); /*forall<a> maybe<a>*/
    goto _match4723;
  }
  kk_box_t _box_x3403 = _match_4416.fst;
  kk_box_t _box_x3404 = _match_4416.snd;
  kk_std_core__list xs = kk_std_core__list_unbox(_box_x3403, NULL);
  kk_std_core__sslice rest0 = kk_std_core__sslice_unbox(_box_x3404, NULL);
  kk_std_core__sslice_dup(rest0);
  kk_std_core__list_dup(xs);
  kk_std_core_types__tuple2__drop(_match_4416, _ctx);
  kk_std_core_types__tuple2_ _b_3412_3407 = kk_std_core_types__new_dash__lp__comma__rp_(kk_std_core__list_box(xs, _ctx), kk_std_core__sslice_box(rest0, _ctx), _ctx); /*(list<char>, sslice)*/;
  _x4719 = kk_std_core_types__new_Just(kk_std_core_types__tuple2__box(_b_3412_3407, _ctx), _ctx); /*forall<a> maybe<a>*/
  _match4723: ;
  return kk_std_core_types__maybe_box(_x4719, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_digits0_fun4729__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse_digits0_fun4729(kk_function_t _fself, kk_box_t _b_3418, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_digits0_fun4729(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_digits0_fun4729, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_text_parse_digits0_fun4729(kk_function_t _fself, kk_box_t _b_3418, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x4730;
  kk_define_string_literal(, _s4731, 5, "digit")
  _x4730 = kk_string_dup(_s4731); /*string*/
  kk_std_core_types__maybe _x4732 = kk_std_core_types__maybe_unbox(_b_3418, _ctx); /*maybe<list<char>>*/
  return kk_std_text_parse__mlift2547_satisfy_fail(_x4730, _x4732, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_digits0_fun4738__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse_digits0_fun4738(kk_function_t _fself, kk_box_t _b_3427, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_digits0_fun4738(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_digits0_fun4738, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_text_parse_digits0_fun4738(kk_function_t _fself, kk_box_t _b_3427, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x4739;
  kk_std_core__list _x4740 = kk_std_core__list_unbox(_b_3427, _ctx); /*list<char>*/
  _x4739 = kk_std_core_string_2(_x4740, _ctx); /*string*/
  return kk_string_box(_x4739);
}
static kk_string_t kk_std_text_parse_digits0_fun4712(kk_function_t _fself, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core__list x_2673;
  kk_std_core_types__maybe x0_2679;
  kk_std_core_hnd__ev ev_2574;
  size_t _x4713 = ((size_t)0); /*size_t*/
  ev_2574 = kk_evv_at(_x4713,kk_context()); /*std/core/hnd/ev<std/text/parse/.hnd-parse>*/
  kk_box_t _x4714;
  struct kk_std_core_hnd_Ev* _con4715 = kk_std_core_hnd__as_Ev(ev_2574);
  kk_std_core_hnd__marker m0 = _con4715->marker;
  kk_box_t _box_x3387 = _con4715->hnd;
  kk_std_text_parse__hnd_parse h0 = kk_std_text_parse__hnd_parse_unbox(_box_x3387, NULL);
  kk_std_text_parse__hnd_parse_dup(h0);
  kk_std_core_hnd__clause1 _match_4415;
  struct kk_std_text_parse__Hnd_parse* _con4717 = kk_std_text_parse__as_Hnd_parse(h0);
  kk_std_core_hnd__clause0 _pat04 = _con4717->fun_current_input;
  kk_std_core_hnd__clause1 _pat13 = _con4717->control_fail;
  kk_std_core_hnd__clause0 _pat23 = _con4717->control_pick;
  kk_std_core_hnd__clause1 fun_satisfy = _con4717->fun_satisfy;
  if (kk_std_text_parse__hnd_parse_is_unique(h0)) {
    kk_std_core_hnd__clause0_drop(_pat23, _ctx);
    kk_std_core_hnd__clause1_drop(_pat13, _ctx);
    kk_std_core_hnd__clause0_drop(_pat04, _ctx);
    kk_std_text_parse__hnd_parse_free(h0);
  }
  else {
    kk_std_core_hnd__clause1_dup(fun_satisfy);
    kk_std_text_parse__hnd_parse_decref(h0, _ctx);
  }
  _match_4415 = fun_satisfy; /*forall<a> std/core/hnd/clause1<(sslice) -> total maybe<(a, sslice)>,maybe<a>,std/text/parse/.hnd-parse,3528,3529>*/
  kk_function_t _fun_unbox_x3394 = _match_4415.clause;
  _x4714 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x3394, (_fun_unbox_x3394, m0, ev_2574, kk_function_box(kk_std_text_parse_new_digits0_fun4718(_ctx)), _ctx)); /*53*/
  x0_2679 = kk_std_core_types__maybe_unbox(_x4714, _ctx); /*maybe<list<char>>*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__maybe_drop(x0_2679, _ctx);
    kk_box_t _x4728 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_digits0_fun4729(_ctx), _ctx); /*3991*/
    x_2673 = kk_std_core__list_unbox(_x4728, _ctx); /*list<char>*/
  }
  else {
    if (kk_std_core_types__is_Nothing(x0_2679)) {
      kk_box_t _x4733;
      kk_string_t _x4734;
      kk_define_string_literal(, _s4735, 5, "digit")
      _x4734 = kk_string_dup(_s4735); /*string*/
      _x4733 = kk_std_text_parse_fail(_x4734, _ctx); /*492*/
      x_2673 = kk_std_core__list_unbox(_x4733, _ctx); /*list<char>*/
    }
    else {
      kk_box_t _box_x3420 = x0_2679._cons.Just.value;
      kk_std_core__list x1 = kk_std_core__list_unbox(_box_x3420, NULL);
      kk_std_core__list_dup(x1);
      kk_std_core_types__maybe_drop(x0_2679, _ctx);
      x_2673 = x1; /*list<char>*/
    }
  }
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_2673, _ctx);
    kk_box_t _x4737 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_digits0_fun4738(_ctx), _ctx); /*3991*/
    return kk_string_unbox(_x4737);
  }
  return kk_std_core_string_2(x_2673, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_digits0_fun4747__t {
  struct kk_function_s _base;
  size_t i_2666;
};
static kk_box_t kk_std_text_parse_digits0_fun4747(kk_function_t _fself, kk_function_t _b_3442, kk_box_t _b_3443, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_digits0_fun4747(size_t i_2666, kk_context_t* _ctx) {
  struct kk_std_text_parse_digits0_fun4747__t* _self = kk_function_alloc_as(struct kk_std_text_parse_digits0_fun4747__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_text_parse_digits0_fun4747, kk_context());
  _self->i_2666 = i_2666;
  return &_self->_base;
}

static kk_box_t kk_std_text_parse_digits0_fun4747(kk_function_t _fself, kk_function_t _b_3442, kk_box_t _b_3443, kk_context_t* _ctx) {
  struct kk_std_text_parse_digits0_fun4747__t* _self = kk_function_as(struct kk_std_text_parse_digits0_fun4747__t*, _fself);
  size_t i_2666 = _self->i_2666; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_2666, _b_3442, _b_3443, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_digits0_fun4749__t {
  struct kk_function_s _base;
  kk_function_t p1_2881;
};
static kk_box_t kk_std_text_parse_digits0_fun4749(kk_function_t _fself, kk_box_t _b_3456, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_digits0_fun4749(kk_function_t p1_2881, kk_context_t* _ctx) {
  struct kk_std_text_parse_digits0_fun4749__t* _self = kk_function_alloc_as(struct kk_std_text_parse_digits0_fun4749__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_text_parse_digits0_fun4749, kk_context());
  _self->p1_2881 = p1_2881;
  return &_self->_base;
}



// lift anonymous function
struct kk_std_text_parse_digits0_fun4750__t {
  struct kk_function_s _base;
  kk_function_t p1_2881;
};
static kk_box_t kk_std_text_parse_digits0_fun4750(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_digits0_fun4750(kk_function_t p1_2881, kk_context_t* _ctx) {
  struct kk_std_text_parse_digits0_fun4750__t* _self = kk_function_alloc_as(struct kk_std_text_parse_digits0_fun4750__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_text_parse_digits0_fun4750, kk_context());
  _self->p1_2881 = p1_2881;
  return &_self->_base;
}

static kk_box_t kk_std_text_parse_digits0_fun4750(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_text_parse_digits0_fun4750__t* _self = kk_function_as(struct kk_std_text_parse_digits0_fun4750__t*, _fself);
  kk_function_t p1_2881 = _self->p1_2881; /* std/text/parse/parser<(<>),string> */
  kk_drop_match(_self, {kk_function_dup(p1_2881);}, {}, _ctx)
  kk_string_t _x4751 = kk_function_call(kk_string_t, (kk_function_t, kk_context_t*), p1_2881, (p1_2881, _ctx)); /*string*/
  return kk_string_box(_x4751);
}


// lift anonymous function
struct kk_std_text_parse_digits0_fun4752__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse_digits0_fun4752(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_digits0_fun4752(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_digits0_fun4752, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_text_parse_digits0_fun4752(kk_function_t _fself, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x4753;
  kk_define_string_literal(, _s4754, 1, "0")
  _x4753 = kk_string_dup(_s4754); /*string*/
  return kk_string_box(_x4753);
}
static kk_box_t kk_std_text_parse_digits0_fun4749(kk_function_t _fself, kk_box_t _b_3456, kk_context_t* _ctx) {
  struct kk_std_text_parse_digits0_fun4749__t* _self = kk_function_as(struct kk_std_text_parse_digits0_fun4749__t*, _fself);
  kk_function_t p1_2881 = _self->p1_2881; /* std/text/parse/parser<(<>),string> */
  kk_drop_match(_self, {kk_function_dup(p1_2881);}, {}, _ctx)
  bool _x4755 = kk_bool_unbox(_b_3456); /*bool*/
  return kk_std_text_parse__mlift2551_op(kk_std_text_parse_new_digits0_fun4750(p1_2881, _ctx), kk_std_text_parse_new_digits0_fun4752(_ctx), _x4755, _ctx);
}

kk_string_t kk_std_text_parse_digits0(kk_context_t* _ctx) { /* () -> parse string */ 
  kk_function_t p1_2881 = kk_std_text_parse_new_digits0_fun4712(_ctx); /*std/text/parse/parser<(<>),string>*/;
  bool x_2663;
  size_t i_2666 = ((size_t)0); /*std/core/hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_2666,kk_context()); /*std/core/hnd/evv<std/text/parse/parse>*/;
  bool y;
  kk_std_core_hnd__ev ev_2668;
  size_t _x4741 = ((size_t)0); /*size_t*/
  ev_2668 = kk_evv_at(_x4741,kk_context()); /*std/core/hnd/ev<std/text/parse/.hnd-parse>*/
  kk_box_t _x4742;
  struct kk_std_core_hnd_Ev* _con4743 = kk_std_core_hnd__as_Ev(ev_2668);
  kk_std_core_hnd__marker m = _con4743->marker;
  kk_box_t _box_x3429 = _con4743->hnd;
  kk_std_text_parse__hnd_parse h = kk_std_text_parse__hnd_parse_unbox(_box_x3429, NULL);
  kk_std_text_parse__hnd_parse_dup(h);
  kk_std_core_hnd__clause0 _match_4412;
  struct kk_std_text_parse__Hnd_parse* _con4745 = kk_std_text_parse__as_Hnd_parse(h);
  kk_std_core_hnd__clause0 _pat0 = _con4745->fun_current_input;
  kk_std_core_hnd__clause1 _pat1 = _con4745->control_fail;
  kk_std_core_hnd__clause0 control_pick = _con4745->control_pick;
  kk_std_core_hnd__clause1 _pat21 = _con4745->fun_satisfy;
  if (kk_std_text_parse__hnd_parse_is_unique(h)) {
    kk_std_core_hnd__clause1_drop(_pat21, _ctx);
    kk_std_core_hnd__clause1_drop(_pat1, _ctx);
    kk_std_core_hnd__clause0_drop(_pat0, _ctx);
    kk_std_text_parse__hnd_parse_free(h);
  }
  else {
    kk_std_core_hnd__clause0_dup(control_pick);
    kk_std_text_parse__hnd_parse_decref(h, _ctx);
  }
  _match_4412 = control_pick; /*std/core/hnd/clause0<bool,std/text/parse/.hnd-parse,3435,3436>*/
  kk_function_t _fun_unbox_x3432 = _match_4412.clause;
  _x4742 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x3432, (_fun_unbox_x3432, m, ev_2668, _ctx)); /*37*/
  y = kk_bool_unbox(_x4742); /*bool*/
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x4746 = kk_std_core_hnd_yield_cont(kk_std_text_parse_new_digits0_fun4747(i_2666, _ctx), _ctx); /*3820*/
    x_2663 = kk_bool_unbox(_x4746); /*bool*/
  }
  else {
    x_2663 = y; /*bool*/
  }
  if (kk_yielding(kk_context())) {
    kk_box_t _x4748 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_digits0_fun4749(p1_2881, _ctx), _ctx); /*3991*/
    return kk_string_unbox(_x4748);
  }
  if (x_2663) {
    return kk_function_call(kk_string_t, (kk_function_t, kk_context_t*), p1_2881, (p1_2881, _ctx));
  }
  kk_function_drop(p1_2881, _ctx);
  kk_define_string_literal(, _s4756, 1, "0")
  return kk_string_dup(_s4756);
}
 
// monadic lift

kk_unit_t kk_std_text_parse__mlift2552_eof(kk_std_core_types__maybe _y_32, kk_context_t* _ctx) { /* (maybe<()>) -> parse () */ 
  if (kk_std_core_types__is_Nothing(_y_32)) {
    kk_std_core_hnd__ev ev_2684;
    size_t _x4757 = ((size_t)0); /*size_t*/
    ev_2684 = kk_evv_at(_x4757,kk_context()); /*std/core/hnd/ev<std/text/parse/.hnd-parse>*/
    kk_box_t _x4758;
    struct kk_std_core_hnd_Ev* _con4759 = kk_std_core_hnd__as_Ev(ev_2684);
    kk_std_core_hnd__marker m = _con4759->marker;
    kk_box_t _box_x3462 = _con4759->hnd;
    kk_std_text_parse__hnd_parse h = kk_std_text_parse__hnd_parse_unbox(_box_x3462, NULL);
    kk_std_text_parse__hnd_parse_dup(h);
    kk_std_core_hnd__clause1 _match_4409;
    struct kk_std_text_parse__Hnd_parse* _con4761 = kk_std_text_parse__as_Hnd_parse(h);
    kk_std_core_hnd__clause0 _pat00 = _con4761->fun_current_input;
    kk_std_core_hnd__clause1 control_fail = _con4761->control_fail;
    kk_std_core_hnd__clause0 _pat11 = _con4761->control_pick;
    kk_std_core_hnd__clause1 _pat20 = _con4761->fun_satisfy;
    if (kk_std_text_parse__hnd_parse_is_unique(h)) {
      kk_std_core_hnd__clause1_drop(_pat20, _ctx);
      kk_std_core_hnd__clause0_drop(_pat11, _ctx);
      kk_std_core_hnd__clause0_drop(_pat00, _ctx);
      kk_std_text_parse__hnd_parse_free(h);
    }
    else {
      kk_std_core_hnd__clause1_dup(control_fail);
      kk_std_text_parse__hnd_parse_decref(h, _ctx);
    }
    _match_4409 = control_fail; /*forall<a> std/core/hnd/clause1<string,a,std/text/parse/.hnd-parse,3528,3529>*/
    kk_function_t _fun_unbox_x3466 = _match_4409.clause;
    kk_box_t _x4762;
    kk_string_t _x4763;
    kk_define_string_literal(, _s4764, 22, "expecting end-of-input")
    _x4763 = kk_string_dup(_s4764); /*string*/
    _x4762 = kk_string_box(_x4763); /*52*/
    _x4758 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x3466, (_fun_unbox_x3466, m, ev_2684, _x4762, _ctx)); /*53*/
    kk_unit_unbox(_x4758); return kk_Unit;
  }
  kk_box_t _box_x3470 = _y_32._cons.Just.value;
  kk_unit_t _pat300 = kk_unit_unbox(_box_x3470);
  kk_std_core_types__maybe_drop(_y_32, _ctx);
  kk_Unit; return kk_Unit;
}


// lift anonymous function
struct kk_std_text_parse_eof_fun4771__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse_eof_fun4771(kk_function_t _fself, kk_box_t _b_3487, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_eof_fun4771(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_eof_fun4771, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_text_parse_eof_fun4771(kk_function_t _fself, kk_box_t _b_3487, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core_types__maybe _x4772;
  bool _match_4408;
  kk_std_core__sslice _x4773;
  kk_box_t _x4774 = kk_box_dup(_b_3487); /*3485*/
  _x4773 = kk_std_core__sslice_unbox(_x4774, _ctx); /*sslice*/
  _match_4408 = kk_std_core_is_empty_1(_x4773, _ctx); /*bool*/
  if (_match_4408) {
    kk_std_core_types__tuple2_ _b_3495_3490 = kk_std_core_types__new_dash__lp__comma__rp_(kk_unit_box(kk_Unit), _b_3487, _ctx); /*((), sslice)*/;
    _x4772 = kk_std_core_types__new_Just(kk_std_core_types__tuple2__box(_b_3495_3490, _ctx), _ctx); /*maybe<103>*/
  }
  else {
    kk_box_drop(_b_3487, _ctx);
    _x4772 = kk_std_core_types__new_Nothing(_ctx); /*maybe<103>*/
  }
  return kk_std_core_types__maybe_box(_x4772, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_eof_fun4776__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse_eof_fun4776(kk_function_t _fself, kk_box_t _b_3499, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_eof_fun4776(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_eof_fun4776, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_text_parse_eof_fun4776(kk_function_t _fself, kk_box_t _b_3499, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_unit_t _x4777 = kk_Unit;
  kk_std_core_types__maybe _x4778 = kk_std_core_types__maybe_unbox(_b_3499, _ctx); /*maybe<()>*/
  kk_std_text_parse__mlift2552_eof(_x4778, _ctx);
  return kk_unit_box(_x4777);
}

kk_unit_t kk_std_text_parse_eof(kk_context_t* _ctx) { /* () -> parse () */ 
  kk_std_core_types__maybe x_2687;
  kk_std_core_hnd__ev ev_2691;
  size_t _x4766 = ((size_t)0); /*size_t*/
  ev_2691 = kk_evv_at(_x4766,kk_context()); /*std/core/hnd/ev<std/text/parse/.hnd-parse>*/
  kk_box_t _x4767;
  struct kk_std_core_hnd_Ev* _con4768 = kk_std_core_hnd__as_Ev(ev_2691);
  kk_std_core_hnd__marker m = _con4768->marker;
  kk_box_t _box_x3474 = _con4768->hnd;
  kk_std_text_parse__hnd_parse h = kk_std_text_parse__hnd_parse_unbox(_box_x3474, NULL);
  kk_std_text_parse__hnd_parse_dup(h);
  kk_std_core_hnd__clause1 _match_4407;
  struct kk_std_text_parse__Hnd_parse* _con4770 = kk_std_text_parse__as_Hnd_parse(h);
  kk_std_core_hnd__clause0 _pat0 = _con4770->fun_current_input;
  kk_std_core_hnd__clause1 _pat11 = _con4770->control_fail;
  kk_std_core_hnd__clause0 _pat20 = _con4770->control_pick;
  kk_std_core_hnd__clause1 fun_satisfy = _con4770->fun_satisfy;
  if (kk_std_text_parse__hnd_parse_is_unique(h)) {
    kk_std_core_hnd__clause0_drop(_pat20, _ctx);
    kk_std_core_hnd__clause1_drop(_pat11, _ctx);
    kk_std_core_hnd__clause0_drop(_pat0, _ctx);
    kk_std_text_parse__hnd_parse_free(h);
  }
  else {
    kk_std_core_hnd__clause1_dup(fun_satisfy);
    kk_std_text_parse__hnd_parse_decref(h, _ctx);
  }
  _match_4407 = fun_satisfy; /*forall<a> std/core/hnd/clause1<(sslice) -> total maybe<(a, sslice)>,maybe<a>,std/text/parse/.hnd-parse,3528,3529>*/
  kk_function_t _fun_unbox_x3481 = _match_4407.clause;
  _x4767 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x3481, (_fun_unbox_x3481, m, ev_2691, kk_function_box(kk_std_text_parse_new_eof_fun4771(_ctx)), _ctx)); /*53*/
  x_2687 = kk_std_core_types__maybe_unbox(_x4767, _ctx); /*maybe<()>*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__maybe_drop(x_2687, _ctx);
    kk_box_t _x4775 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_eof_fun4776(_ctx), _ctx); /*3991*/
    kk_unit_unbox(_x4775); return kk_Unit;
  }
  if (kk_std_core_types__is_Nothing(x_2687)) {
    kk_std_core_hnd__ev ev0_2696;
    size_t _x4779 = ((size_t)0); /*size_t*/
    ev0_2696 = kk_evv_at(_x4779,kk_context()); /*std/core/hnd/ev<std/text/parse/.hnd-parse>*/
    kk_box_t _x4780;
    struct kk_std_core_hnd_Ev* _con4781 = kk_std_core_hnd__as_Ev(ev0_2696);
    kk_std_core_hnd__marker m0 = _con4781->marker;
    kk_box_t _box_x3500 = _con4781->hnd;
    kk_std_text_parse__hnd_parse h0 = kk_std_text_parse__hnd_parse_unbox(_box_x3500, NULL);
    kk_std_text_parse__hnd_parse_dup(h0);
    kk_std_core_hnd__clause1 _match_4406;
    struct kk_std_text_parse__Hnd_parse* _con4783 = kk_std_text_parse__as_Hnd_parse(h0);
    kk_std_core_hnd__clause0 _pat03 = _con4783->fun_current_input;
    kk_std_core_hnd__clause1 control_fail = _con4783->control_fail;
    kk_std_core_hnd__clause0 _pat13 = _con4783->control_pick;
    kk_std_core_hnd__clause1 _pat21 = _con4783->fun_satisfy;
    if (kk_std_text_parse__hnd_parse_is_unique(h0)) {
      kk_std_core_hnd__clause1_drop(_pat21, _ctx);
      kk_std_core_hnd__clause0_drop(_pat13, _ctx);
      kk_std_core_hnd__clause0_drop(_pat03, _ctx);
      kk_std_text_parse__hnd_parse_free(h0);
    }
    else {
      kk_std_core_hnd__clause1_dup(control_fail);
      kk_std_text_parse__hnd_parse_decref(h0, _ctx);
    }
    _match_4406 = control_fail; /*forall<a> std/core/hnd/clause1<string,a,std/text/parse/.hnd-parse,3528,3529>*/
    kk_function_t _fun_unbox_x3504 = _match_4406.clause;
    kk_box_t _x4784;
    kk_string_t _x4785;
    kk_define_string_literal(, _s4786, 22, "expecting end-of-input")
    _x4785 = kk_string_dup(_s4786); /*string*/
    _x4784 = kk_string_box(_x4785); /*52*/
    _x4780 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x3504, (_fun_unbox_x3504, m0, ev0_2696, _x4784, _ctx)); /*53*/
    kk_unit_unbox(_x4780); return kk_Unit;
  }
  kk_box_t _box_x3508 = x_2687._cons.Just.value;
  kk_unit_t _pat31 = kk_unit_unbox(_box_x3508);
  kk_std_core_types__maybe_drop(x_2687, _ctx);
  kk_Unit; return kk_Unit;
}


// lift anonymous function
struct kk_std_text_parse_hex_digits_fun4793__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse_hex_digits_fun4793(kk_function_t _fself, kk_box_t _b_3526, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_hex_digits_fun4793(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_hex_digits_fun4793, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_std_text_parse_hex_digits_fun4797__t {
  struct kk_function_s _base;
};
static bool kk_std_text_parse_hex_digits_fun4797(kk_function_t _fself, kk_char_t _x14796, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_hex_digits_fun4797(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_hex_digits_fun4797, _ctx)
  return kk_function_dup(_fself);
}

static bool kk_std_text_parse_hex_digits_fun4797(kk_function_t _fself, kk_char_t _x14796, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return kk_std_core_is_hex_digit(_x14796, _ctx);
}
static kk_box_t kk_std_text_parse_hex_digits_fun4793(kk_function_t _fself, kk_box_t _b_3526, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core_types__maybe _x4794;
  kk_std_core_types__tuple2_ _match_4404;
  kk_std_core__sslice _x4795 = kk_std_core__sslice_unbox(_b_3526, _ctx); /*sslice*/
  _match_4404 = kk_std_text_parse_next_while0(_x4795, kk_std_text_parse_new_hex_digits_fun4797(_ctx), kk_std_core__new_Nil(_ctx), _ctx); /*(list<char>, sslice)*/
  kk_box_t _box_x3527 = _match_4404.fst;
  kk_box_t _box_x3528 = _match_4404.snd;
  kk_std_core__list _pat02 = kk_std_core__list_unbox(_box_x3527, NULL);
  kk_std_core__sslice _pat100 = kk_std_core__sslice_unbox(_box_x3528, NULL);
  if (kk_std_core__is_Nil(_pat02)) {
    kk_std_core_types__tuple2__drop(_match_4404, _ctx);
    _x4794 = kk_std_core_types__new_Nothing(_ctx); /*forall<a> maybe<a>*/
    goto _match4798;
  }
  kk_box_t _box_x3529 = _match_4404.fst;
  kk_box_t _box_x3530 = _match_4404.snd;
  kk_std_core__list xs = kk_std_core__list_unbox(_box_x3529, NULL);
  kk_std_core__sslice rest0 = kk_std_core__sslice_unbox(_box_x3530, NULL);
  kk_std_core__sslice_dup(rest0);
  kk_std_core__list_dup(xs);
  kk_std_core_types__tuple2__drop(_match_4404, _ctx);
  kk_std_core_types__tuple2_ _b_3538_3533 = kk_std_core_types__new_dash__lp__comma__rp_(kk_std_core__list_box(xs, _ctx), kk_std_core__sslice_box(rest0, _ctx), _ctx); /*(list<char>, sslice)*/;
  _x4794 = kk_std_core_types__new_Just(kk_std_core_types__tuple2__box(_b_3538_3533, _ctx), _ctx); /*forall<a> maybe<a>*/
  _match4798: ;
  return kk_std_core_types__maybe_box(_x4794, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_hex_digits_fun4804__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse_hex_digits_fun4804(kk_function_t _fself, kk_box_t _b_3544, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_hex_digits_fun4804(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_hex_digits_fun4804, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_text_parse_hex_digits_fun4804(kk_function_t _fself, kk_box_t _b_3544, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x4805;
  kk_define_string_literal(, _s4806, 5, "digit")
  _x4805 = kk_string_dup(_s4806); /*string*/
  kk_std_core_types__maybe _x4807 = kk_std_core_types__maybe_unbox(_b_3544, _ctx); /*maybe<list<char>>*/
  return kk_std_text_parse__mlift2547_satisfy_fail(_x4805, _x4807, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_hex_digits_fun4813__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse_hex_digits_fun4813(kk_function_t _fself, kk_box_t _b_3553, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_hex_digits_fun4813(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_hex_digits_fun4813, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_text_parse_hex_digits_fun4813(kk_function_t _fself, kk_box_t _b_3553, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x4814;
  kk_std_core__list _x4815 = kk_std_core__list_unbox(_b_3553, _ctx); /*list<char>*/
  _x4814 = kk_std_core_string_2(_x4815, _ctx); /*string*/
  return kk_string_box(_x4814);
}

kk_string_t kk_std_text_parse_hex_digits(kk_context_t* _ctx) { /* () -> parse string */ 
  kk_std_core__list x_2699;
  kk_std_core_types__maybe x0_2705;
  kk_std_core_hnd__ev ev_2574;
  size_t _x4788 = ((size_t)0); /*size_t*/
  ev_2574 = kk_evv_at(_x4788,kk_context()); /*std/core/hnd/ev<std/text/parse/.hnd-parse>*/
  kk_box_t _x4789;
  struct kk_std_core_hnd_Ev* _con4790 = kk_std_core_hnd__as_Ev(ev_2574);
  kk_std_core_hnd__marker m = _con4790->marker;
  kk_box_t _box_x3513 = _con4790->hnd;
  kk_std_text_parse__hnd_parse h = kk_std_text_parse__hnd_parse_unbox(_box_x3513, NULL);
  kk_std_text_parse__hnd_parse_dup(h);
  kk_std_core_hnd__clause1 _match_4403;
  struct kk_std_text_parse__Hnd_parse* _con4792 = kk_std_text_parse__as_Hnd_parse(h);
  kk_std_core_hnd__clause0 _pat00 = _con4792->fun_current_input;
  kk_std_core_hnd__clause1 _pat10 = _con4792->control_fail;
  kk_std_core_hnd__clause0 _pat20 = _con4792->control_pick;
  kk_std_core_hnd__clause1 fun_satisfy = _con4792->fun_satisfy;
  if (kk_std_text_parse__hnd_parse_is_unique(h)) {
    kk_std_core_hnd__clause0_drop(_pat20, _ctx);
    kk_std_core_hnd__clause1_drop(_pat10, _ctx);
    kk_std_core_hnd__clause0_drop(_pat00, _ctx);
    kk_std_text_parse__hnd_parse_free(h);
  }
  else {
    kk_std_core_hnd__clause1_dup(fun_satisfy);
    kk_std_text_parse__hnd_parse_decref(h, _ctx);
  }
  _match_4403 = fun_satisfy; /*forall<a> std/core/hnd/clause1<(sslice) -> total maybe<(a, sslice)>,maybe<a>,std/text/parse/.hnd-parse,3528,3529>*/
  kk_function_t _fun_unbox_x3520 = _match_4403.clause;
  _x4789 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x3520, (_fun_unbox_x3520, m, ev_2574, kk_function_box(kk_std_text_parse_new_hex_digits_fun4793(_ctx)), _ctx)); /*53*/
  x0_2705 = kk_std_core_types__maybe_unbox(_x4789, _ctx); /*maybe<list<char>>*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__maybe_drop(x0_2705, _ctx);
    kk_box_t _x4803 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_hex_digits_fun4804(_ctx), _ctx); /*3991*/
    x_2699 = kk_std_core__list_unbox(_x4803, _ctx); /*list<char>*/
  }
  else {
    if (kk_std_core_types__is_Nothing(x0_2705)) {
      kk_box_t _x4808;
      kk_string_t _x4809;
      kk_define_string_literal(, _s4810, 5, "digit")
      _x4809 = kk_string_dup(_s4810); /*string*/
      _x4808 = kk_std_text_parse_fail(_x4809, _ctx); /*492*/
      x_2699 = kk_std_core__list_unbox(_x4808, _ctx); /*list<char>*/
    }
    else {
      kk_box_t _box_x3546 = x0_2705._cons.Just.value;
      kk_std_core__list x1 = kk_std_core__list_unbox(_box_x3546, NULL);
      kk_std_core__list_dup(x1);
      kk_std_core_types__maybe_drop(x0_2705, _ctx);
      x_2699 = x1; /*list<char>*/
    }
  }
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_2699, _ctx);
    kk_box_t _x4812 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_hex_digits_fun4813(_ctx), _ctx); /*3991*/
    return kk_string_unbox(_x4812);
  }
  return kk_std_core_string_2(x_2699, _ctx);
}
 
// monadic lift

kk_std_core__list kk_std_text_parse__mlift2553_many_acc(kk_std_core__list acc, kk_function_t p, kk_box_t x, kk_context_t* _ctx) { /* forall<a,e> (acc : list<a>, p : parser<e,a>, x : a) -> <parse|e> list<a> */ 
  kk_std_core__list _x4816 = kk_std_core__new_Cons(kk_reuse_null, x, acc, _ctx); /*list<61>*/
  return kk_std_text_parse_many_acc(p, _x4816, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_many_acc_fun4817__t {
  struct kk_function_s _base;
  kk_std_core__list acc0;
  kk_function_t p0;
};
static kk_std_core__list kk_std_text_parse_many_acc_fun4817(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_many_acc_fun4817(kk_std_core__list acc0, kk_function_t p0, kk_context_t* _ctx) {
  struct kk_std_text_parse_many_acc_fun4817__t* _self = kk_function_alloc_as(struct kk_std_text_parse_many_acc_fun4817__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_text_parse_many_acc_fun4817, kk_context());
  _self->acc0 = acc0;
  _self->p0 = p0;
  return &_self->_base;
}



// lift anonymous function
struct kk_std_text_parse_many_acc_fun4820__t {
  struct kk_function_s _base;
  kk_std_core__list acc0;
  kk_function_t p0;
};
static kk_box_t kk_std_text_parse_many_acc_fun4820(kk_function_t _fself, kk_box_t _b_3556, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_many_acc_fun4820(kk_std_core__list acc0, kk_function_t p0, kk_context_t* _ctx) {
  struct kk_std_text_parse_many_acc_fun4820__t* _self = kk_function_alloc_as(struct kk_std_text_parse_many_acc_fun4820__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_text_parse_many_acc_fun4820, kk_context());
  _self->acc0 = acc0;
  _self->p0 = p0;
  return &_self->_base;
}

static kk_box_t kk_std_text_parse_many_acc_fun4820(kk_function_t _fself, kk_box_t _b_3556, kk_context_t* _ctx) {
  struct kk_std_text_parse_many_acc_fun4820__t* _self = kk_function_as(struct kk_std_text_parse_many_acc_fun4820__t*, _fself);
  kk_std_core__list acc0 = _self->acc0; /* list<1264> */
  kk_function_t p0 = _self->p0; /* std/text/parse/parser<1265,1264> */
  kk_drop_match(_self, {kk_std_core__list_dup(acc0);kk_function_dup(p0);}, {}, _ctx)
  kk_std_core__list _x4821 = kk_std_text_parse__mlift2553_many_acc(acc0, p0, _b_3556, _ctx); /*list<1264>*/
  return kk_std_core__list_box(_x4821, _ctx);
}
static kk_std_core__list kk_std_text_parse_many_acc_fun4817(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_text_parse_many_acc_fun4817__t* _self = kk_function_as(struct kk_std_text_parse_many_acc_fun4817__t*, _fself);
  kk_std_core__list acc0 = _self->acc0; /* list<1264> */
  kk_function_t p0 = _self->p0; /* std/text/parse/parser<1265,1264> */
  kk_drop_match(_self, {kk_std_core__list_dup(acc0);kk_function_dup(p0);}, {}, _ctx)
  kk_box_t x_2709;
  kk_function_t _x4818 = kk_function_dup(p0); /*std/text/parse/parser<1265,1264>*/
  x_2709 = kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), _x4818, (_x4818, _ctx)); /*1264*/
  if (kk_yielding(kk_context())) {
    kk_box_drop(x_2709, _ctx);
    kk_box_t _x4819 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_many_acc_fun4820(acc0, p0, _ctx), _ctx); /*3991*/
    return kk_std_core__list_unbox(_x4819, _ctx);
  }
  return kk_std_text_parse__mlift2553_many_acc(acc0, p0, x_2709, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_many_acc_fun4829__t {
  struct kk_function_s _base;
  size_t i_2666;
};
static kk_box_t kk_std_text_parse_many_acc_fun4829(kk_function_t _fself, kk_function_t _b_3572, kk_box_t _b_3573, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_many_acc_fun4829(size_t i_2666, kk_context_t* _ctx) {
  struct kk_std_text_parse_many_acc_fun4829__t* _self = kk_function_alloc_as(struct kk_std_text_parse_many_acc_fun4829__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_text_parse_many_acc_fun4829, kk_context());
  _self->i_2666 = i_2666;
  return &_self->_base;
}

static kk_box_t kk_std_text_parse_many_acc_fun4829(kk_function_t _fself, kk_function_t _b_3572, kk_box_t _b_3573, kk_context_t* _ctx) {
  struct kk_std_text_parse_many_acc_fun4829__t* _self = kk_function_as(struct kk_std_text_parse_many_acc_fun4829__t*, _fself);
  size_t i_2666 = _self->i_2666; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_2666, _b_3572, _b_3573, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_many_acc_fun4831__t {
  struct kk_function_s _base;
  kk_std_core__list acc0;
  kk_function_t p1_2891;
};
static kk_box_t kk_std_text_parse_many_acc_fun4831(kk_function_t _fself, kk_box_t _b_3586, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_many_acc_fun4831(kk_std_core__list acc0, kk_function_t p1_2891, kk_context_t* _ctx) {
  struct kk_std_text_parse_many_acc_fun4831__t* _self = kk_function_alloc_as(struct kk_std_text_parse_many_acc_fun4831__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_text_parse_many_acc_fun4831, kk_context());
  _self->acc0 = acc0;
  _self->p1_2891 = p1_2891;
  return &_self->_base;
}



// lift anonymous function
struct kk_std_text_parse_many_acc_fun4832__t {
  struct kk_function_s _base;
  kk_function_t p1_2891;
};
static kk_box_t kk_std_text_parse_many_acc_fun4832(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_many_acc_fun4832(kk_function_t p1_2891, kk_context_t* _ctx) {
  struct kk_std_text_parse_many_acc_fun4832__t* _self = kk_function_alloc_as(struct kk_std_text_parse_many_acc_fun4832__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_text_parse_many_acc_fun4832, kk_context());
  _self->p1_2891 = p1_2891;
  return &_self->_base;
}

static kk_box_t kk_std_text_parse_many_acc_fun4832(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_text_parse_many_acc_fun4832__t* _self = kk_function_as(struct kk_std_text_parse_many_acc_fun4832__t*, _fself);
  kk_function_t p1_2891 = _self->p1_2891; /* std/text/parse/parser<1265,list<1264>> */
  kk_drop_match(_self, {kk_function_dup(p1_2891);}, {}, _ctx)
  kk_std_core__list _x4833 = kk_function_call(kk_std_core__list, (kk_function_t, kk_context_t*), p1_2891, (p1_2891, _ctx)); /*list<1264>*/
  return kk_std_core__list_box(_x4833, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_many_acc_fun4834__t {
  struct kk_function_s _base;
  kk_std_core__list acc0;
};
static kk_box_t kk_std_text_parse_many_acc_fun4834(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_many_acc_fun4834(kk_std_core__list acc0, kk_context_t* _ctx) {
  struct kk_std_text_parse_many_acc_fun4834__t* _self = kk_function_alloc_as(struct kk_std_text_parse_many_acc_fun4834__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_text_parse_many_acc_fun4834, kk_context());
  _self->acc0 = acc0;
  return &_self->_base;
}

static kk_box_t kk_std_text_parse_many_acc_fun4834(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_text_parse_many_acc_fun4834__t* _self = kk_function_as(struct kk_std_text_parse_many_acc_fun4834__t*, _fself);
  kk_std_core__list acc0 = _self->acc0; /* list<1264> */
  kk_drop_match(_self, {kk_std_core__list_dup(acc0);}, {}, _ctx)
  kk_std_core__list _x4835 = kk_std_core_reverse(acc0, _ctx); /*list<15099>*/
  return kk_std_core__list_box(_x4835, _ctx);
}
static kk_box_t kk_std_text_parse_many_acc_fun4831(kk_function_t _fself, kk_box_t _b_3586, kk_context_t* _ctx) {
  struct kk_std_text_parse_many_acc_fun4831__t* _self = kk_function_as(struct kk_std_text_parse_many_acc_fun4831__t*, _fself);
  kk_std_core__list acc0 = _self->acc0; /* list<1264> */
  kk_function_t p1_2891 = _self->p1_2891; /* std/text/parse/parser<1265,list<1264>> */
  kk_drop_match(_self, {kk_std_core__list_dup(acc0);kk_function_dup(p1_2891);}, {}, _ctx)
  bool _x4836 = kk_bool_unbox(_b_3586); /*bool*/
  return kk_std_text_parse__mlift2551_op(kk_std_text_parse_new_many_acc_fun4832(p1_2891, _ctx), kk_std_text_parse_new_many_acc_fun4834(acc0, _ctx), _x4836, _ctx);
}

kk_std_core__list kk_std_text_parse_many_acc(kk_function_t p0, kk_std_core__list acc0, kk_context_t* _ctx) { /* forall<a,e> (p : parser<e,a>, acc : list<a>) -> <parse|e> list<a> */ 
  kk_function_t p1_2891;
  kk_std_core__list_dup(acc0);
  p1_2891 = kk_std_text_parse_new_many_acc_fun4817(acc0, p0, _ctx); /*std/text/parse/parser<1265,list<1264>>*/
  bool x_2663;
  size_t i_2666;
  kk_std_core_hnd__htag _x4822 = kk_std_core_hnd__htag_dup(kk_std_text_parse__tag_parse); /*std/core/hnd/htag<std/text/parse/.hnd-parse>*/
  i_2666 = kk_std_core_hnd__evv_index(_x4822, _ctx); /*std/core/hnd/ev-index*/
  kk_evv_t w = kk_evv_swap_create1(i_2666,kk_context()); /*std/core/hnd/evv<<std/text/parse/parse|1265>>*/;
  bool y;
  kk_std_core_hnd__ev ev_2668;
  size_t _x4823 = ((size_t)0); /*size_t*/
  ev_2668 = kk_evv_at(_x4823,kk_context()); /*std/core/hnd/ev<std/text/parse/.hnd-parse>*/
  kk_box_t _x4824;
  struct kk_std_core_hnd_Ev* _con4825 = kk_std_core_hnd__as_Ev(ev_2668);
  kk_std_core_hnd__marker m = _con4825->marker;
  kk_box_t _box_x3559 = _con4825->hnd;
  kk_std_text_parse__hnd_parse h = kk_std_text_parse__hnd_parse_unbox(_box_x3559, NULL);
  kk_std_text_parse__hnd_parse_dup(h);
  kk_std_core_hnd__clause0 _match_4399;
  struct kk_std_text_parse__Hnd_parse* _con4827 = kk_std_text_parse__as_Hnd_parse(h);
  kk_std_core_hnd__clause0 _pat0 = _con4827->fun_current_input;
  kk_std_core_hnd__clause1 _pat1 = _con4827->control_fail;
  kk_std_core_hnd__clause0 control_pick = _con4827->control_pick;
  kk_std_core_hnd__clause1 _pat21 = _con4827->fun_satisfy;
  if (kk_std_text_parse__hnd_parse_is_unique(h)) {
    kk_std_core_hnd__clause1_drop(_pat21, _ctx);
    kk_std_core_hnd__clause1_drop(_pat1, _ctx);
    kk_std_core_hnd__clause0_drop(_pat0, _ctx);
    kk_std_text_parse__hnd_parse_free(h);
  }
  else {
    kk_std_core_hnd__clause0_dup(control_pick);
    kk_std_text_parse__hnd_parse_decref(h, _ctx);
  }
  _match_4399 = control_pick; /*std/core/hnd/clause0<bool,std/text/parse/.hnd-parse,3435,3436>*/
  kk_function_t _fun_unbox_x3562 = _match_4399.clause;
  _x4824 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x3562, (_fun_unbox_x3562, m, ev_2668, _ctx)); /*37*/
  y = kk_bool_unbox(_x4824); /*bool*/
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x4828 = kk_std_core_hnd_yield_cont(kk_std_text_parse_new_many_acc_fun4829(i_2666, _ctx), _ctx); /*3820*/
    x_2663 = kk_bool_unbox(_x4828); /*bool*/
  }
  else {
    x_2663 = y; /*bool*/
  }
  if (kk_yielding(kk_context())) {
    kk_box_t _x4830 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_many_acc_fun4831(acc0, p1_2891, _ctx), _ctx); /*3991*/
    return kk_std_core__list_unbox(_x4830, _ctx);
  }
  if (x_2663) {
    kk_std_core__list_drop(acc0, _ctx);
    return kk_function_call(kk_std_core__list, (kk_function_t, kk_context_t*), p1_2891, (p1_2891, _ctx));
  }
  kk_function_drop(p1_2891, _ctx);
  return kk_std_core_reverse(acc0, _ctx);
}
 
// monadic lift

kk_std_core__list kk_std_text_parse__mlift2554_many1(kk_box_t _y_40, kk_std_core__list _y_41, kk_context_t* _ctx) { /* forall<a,e> (a, list<a>) -> <parse|e> list<a> */ 
  return kk_std_core__new_Cons(kk_reuse_null, _y_40, _y_41, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_text_parse__mlift2555_many1_fun4838__t {
  struct kk_function_s _base;
  kk_box_t _y_40;
};
static kk_box_t kk_std_text_parse__mlift2555_many1_fun4838(kk_function_t _fself, kk_box_t _b_3593, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse__new_mlift2555_many1_fun4838(kk_box_t _y_40, kk_context_t* _ctx) {
  struct kk_std_text_parse__mlift2555_many1_fun4838__t* _self = kk_function_alloc_as(struct kk_std_text_parse__mlift2555_many1_fun4838__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_text_parse__mlift2555_many1_fun4838, kk_context());
  _self->_y_40 = _y_40;
  return &_self->_base;
}

static kk_box_t kk_std_text_parse__mlift2555_many1_fun4838(kk_function_t _fself, kk_box_t _b_3593, kk_context_t* _ctx) {
  struct kk_std_text_parse__mlift2555_many1_fun4838__t* _self = kk_function_as(struct kk_std_text_parse__mlift2555_many1_fun4838__t*, _fself);
  kk_box_t _y_40 = _self->_y_40; /* 1301 */
  kk_drop_match(_self, {kk_box_dup(_y_40);}, {}, _ctx)
  kk_std_core__list _x4839;
  kk_std_core__list _x4840 = kk_std_core__list_unbox(_b_3593, _ctx); /*list<1301>*/
  _x4839 = kk_std_text_parse__mlift2554_many1(_y_40, _x4840, _ctx); /*list<1301>*/
  return kk_std_core__list_box(_x4839, _ctx);
}

kk_std_core__list kk_std_text_parse__mlift2555_many1(kk_function_t p, kk_box_t _y_40, kk_context_t* _ctx) { /* forall<a,e> (p : parser<e,a>, a) -> <parse|e> list<a> */ 
  kk_std_core__list x_2711 = kk_std_text_parse_many(p, _ctx); /*list<1301>*/;
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_2711, _ctx);
    kk_box_t _x4837 = kk_std_core_hnd_yield_extend(kk_std_text_parse__new_mlift2555_many1_fun4838(_y_40, _ctx), _ctx); /*3991*/
    return kk_std_core__list_unbox(_x4837, _ctx);
  }
  return kk_std_text_parse__mlift2554_many1(_y_40, x_2711, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_many1_fun4843__t {
  struct kk_function_s _base;
  kk_function_t p;
};
static kk_box_t kk_std_text_parse_many1_fun4843(kk_function_t _fself, kk_box_t _b_3597, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_many1_fun4843(kk_function_t p, kk_context_t* _ctx) {
  struct kk_std_text_parse_many1_fun4843__t* _self = kk_function_alloc_as(struct kk_std_text_parse_many1_fun4843__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_text_parse_many1_fun4843, kk_context());
  _self->p = p;
  return &_self->_base;
}

static kk_box_t kk_std_text_parse_many1_fun4843(kk_function_t _fself, kk_box_t _b_3597, kk_context_t* _ctx) {
  struct kk_std_text_parse_many1_fun4843__t* _self = kk_function_as(struct kk_std_text_parse_many1_fun4843__t*, _fself);
  kk_function_t p = _self->p; /* std/text/parse/parser<1302,1301> */
  kk_drop_match(_self, {kk_function_dup(p);}, {}, _ctx)
  kk_std_core__list _x4844 = kk_std_text_parse__mlift2555_many1(p, _b_3597, _ctx); /*list<1301>*/
  return kk_std_core__list_box(_x4844, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_many1_fun4846__t {
  struct kk_function_s _base;
  kk_box_t x_2713;
};
static kk_box_t kk_std_text_parse_many1_fun4846(kk_function_t _fself, kk_box_t _b_3599, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_many1_fun4846(kk_box_t x_2713, kk_context_t* _ctx) {
  struct kk_std_text_parse_many1_fun4846__t* _self = kk_function_alloc_as(struct kk_std_text_parse_many1_fun4846__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_text_parse_many1_fun4846, kk_context());
  _self->x_2713 = x_2713;
  return &_self->_base;
}

static kk_box_t kk_std_text_parse_many1_fun4846(kk_function_t _fself, kk_box_t _b_3599, kk_context_t* _ctx) {
  struct kk_std_text_parse_many1_fun4846__t* _self = kk_function_as(struct kk_std_text_parse_many1_fun4846__t*, _fself);
  kk_box_t x_2713 = _self->x_2713; /* 1301 */
  kk_drop_match(_self, {kk_box_dup(x_2713);}, {}, _ctx)
  kk_std_core__list _x4847;
  kk_std_core__list _x4848 = kk_std_core__list_unbox(_b_3599, _ctx); /*list<1301>*/
  _x4847 = kk_std_text_parse__mlift2554_many1(x_2713, _x4848, _ctx); /*list<1301>*/
  return kk_std_core__list_box(_x4847, _ctx);
}

kk_std_core__list kk_std_text_parse_many1(kk_function_t p, kk_context_t* _ctx) { /* forall<a,e> (p : parser<e,a>) -> <parse|e> list<a> */ 
  kk_box_t x_2713;
  kk_function_t _x4841 = kk_function_dup(p); /*std/text/parse/parser<1302,1301>*/
  x_2713 = kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), _x4841, (_x4841, _ctx)); /*1301*/
  if (kk_yielding(kk_context())) {
    kk_box_drop(x_2713, _ctx);
    kk_box_t _x4842 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_many1_fun4843(p, _ctx), _ctx); /*3991*/
    return kk_std_core__list_unbox(_x4842, _ctx);
  }
  kk_std_core__list x0_2717 = kk_std_text_parse_many(p, _ctx); /*list<1301>*/;
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x0_2717, _ctx);
    kk_box_t _x4845 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_many1_fun4846(x_2713, _ctx), _ctx); /*3991*/
    return kk_std_core__list_unbox(_x4845, _ctx);
  }
  return kk_std_core__new_Cons(kk_reuse_null, x_2713, x0_2717, _ctx);
}

kk_std_core_types__maybe kk_std_text_parse_next_match(kk_std_core__sslice slice, kk_std_core__list cs, kk_context_t* _ctx) { /* (slice : sslice, cs : list<char>) -> maybe<sslice> */ 
  kk__tailcall: ;
  if (kk_std_core__is_Nil(cs)) {
    return kk_std_core_types__new_Just(kk_std_core__sslice_box(slice, _ctx), _ctx);
  }
  struct kk_std_core_Cons* _con4850 = kk_std_core__as_Cons(cs);
  kk_box_t _box_x3606 = _con4850->head;
  kk_std_core__list cc = _con4850->tail;
  kk_char_t c = kk_char_unbox(_box_x3606, NULL);
  if (kk_std_core__list_is_unique(cs)) {
    kk_std_core__list_free(cs);
  }
  else {
    kk_std_core__list_dup(cc);
    kk_std_core__list_decref(cs, _ctx);
  }
  kk_std_core_types__maybe _match_4393 = kk_std_core_next(slice, _ctx); /*maybe<(char, sslice)>*/;
  if (kk_std_core_types__is_Just(_match_4393)) {
    kk_box_t _box_x3607 = _match_4393._cons.Just.value;
    kk_std_core_types__tuple2_ _pat2 = kk_std_core_types__tuple2__unbox(_box_x3607, NULL);
    if (kk_std_core_types__is_dash__lp__comma__rp_(_pat2)) {
      kk_box_t _box_x3608 = _pat2.fst;
      kk_box_t _box_x3609 = _pat2.snd;
      kk_char_t d = kk_char_unbox(_box_x3608, NULL);
      kk_std_core__sslice rest0 = kk_std_core__sslice_unbox(_box_x3609, NULL);
      if (c == d) {
        kk_std_core__sslice_dup(rest0);
        kk_std_core_types__maybe_drop(_match_4393, _ctx);
        { // tailcall
          slice = rest0;
          cs = cc;
          goto kk__tailcall;
        }
      }
    }
  }
  kk_std_core_types__maybe_drop(_match_4393, _ctx);
  kk_std_core__list_drop(cc, _ctx);
  return kk_std_core_types__new_Nothing(_ctx);
}


// lift anonymous function
struct kk_std_text_parse_no_digit_fun4860__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse_no_digit_fun4860(kk_function_t _fself, kk_box_t _b_3624, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_no_digit_fun4860(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_no_digit_fun4860, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_text_parse_no_digit_fun4860(kk_function_t _fself, kk_box_t _b_3624, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core_types__maybe _x4861;
  kk_std_core_types__maybe _match_4392;
  kk_std_core__sslice _x4862 = kk_std_core__sslice_unbox(_b_3624, _ctx); /*sslice*/
  _match_4392 = kk_std_core_next(_x4862, _ctx); /*maybe<(char, sslice)>*/
  if (kk_std_core_types__is_Just(_match_4392)) {
    kk_box_t _box_x3625 = _match_4392._cons.Just.value;
    kk_std_core_types__tuple2_ _pat01 = kk_std_core_types__tuple2__unbox(_box_x3625, NULL);
    if (kk_std_core_types__is_dash__lp__comma__rp_(_pat01)) {
      kk_box_t _box_x3626 = _pat01.fst;
      kk_box_t _box_x3627 = _pat01.snd;
      kk_char_t c = kk_char_unbox(_box_x3626, NULL);
      kk_std_core__sslice rest0 = kk_std_core__sslice_unbox(_box_x3627, NULL);
      bool _x4867 = kk_std_core_is_digit(c, _ctx); /*bool*/
      if (!(_x4867)) {
        kk_std_core__sslice_dup(rest0);
        kk_std_core_types__maybe_drop(_match_4392, _ctx);
        kk_std_core_types__tuple2_ _b_3635_3630 = kk_std_core_types__new_dash__lp__comma__rp_(kk_char_box(c, _ctx), kk_std_core__sslice_box(rest0, _ctx), _ctx); /*(char, sslice)*/;
        _x4861 = kk_std_core_types__new_Just(kk_std_core_types__tuple2__box(_b_3635_3630, _ctx), _ctx); /*maybe<103>*/
        goto _match4863;
      }
    }
  }
  kk_std_core_types__maybe_drop(_match_4392, _ctx);
  _x4861 = kk_std_core_types__new_Nothing(_ctx); /*maybe<103>*/
  _match4863: ;
  return kk_std_core_types__maybe_box(_x4861, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_no_digit_fun4869__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse_no_digit_fun4869(kk_function_t _fself, kk_box_t _b_3641, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_no_digit_fun4869(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_no_digit_fun4869, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_text_parse_no_digit_fun4869(kk_function_t _fself, kk_box_t _b_3641, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x4870;
  kk_define_string_literal(, _s4871, 11, "not a digit")
  _x4870 = kk_string_dup(_s4871); /*string*/
  kk_std_core_types__maybe _x4872 = kk_std_core_types__maybe_unbox(_b_3641, _ctx); /*maybe<char>*/
  return kk_std_text_parse__mlift2547_satisfy_fail(_x4870, _x4872, _ctx);
}

kk_char_t kk_std_text_parse_no_digit(kk_context_t* _ctx) { /* () -> parse char */ 
  kk_std_core_types__maybe x_2726;
  kk_std_core_hnd__ev ev_2574;
  size_t _x4855 = ((size_t)0); /*size_t*/
  ev_2574 = kk_evv_at(_x4855,kk_context()); /*std/core/hnd/ev<std/text/parse/.hnd-parse>*/
  kk_box_t _x4856;
  struct kk_std_core_hnd_Ev* _con4857 = kk_std_core_hnd__as_Ev(ev_2574);
  kk_std_core_hnd__marker m = _con4857->marker;
  kk_box_t _box_x3611 = _con4857->hnd;
  kk_std_text_parse__hnd_parse h = kk_std_text_parse__hnd_parse_unbox(_box_x3611, NULL);
  kk_std_text_parse__hnd_parse_dup(h);
  kk_std_core_hnd__clause1 _match_4391;
  struct kk_std_text_parse__Hnd_parse* _con4859 = kk_std_text_parse__as_Hnd_parse(h);
  kk_std_core_hnd__clause0 _pat00 = _con4859->fun_current_input;
  kk_std_core_hnd__clause1 _pat10 = _con4859->control_fail;
  kk_std_core_hnd__clause0 _pat20 = _con4859->control_pick;
  kk_std_core_hnd__clause1 fun_satisfy = _con4859->fun_satisfy;
  if (kk_std_text_parse__hnd_parse_is_unique(h)) {
    kk_std_core_hnd__clause0_drop(_pat20, _ctx);
    kk_std_core_hnd__clause1_drop(_pat10, _ctx);
    kk_std_core_hnd__clause0_drop(_pat00, _ctx);
    kk_std_text_parse__hnd_parse_free(h);
  }
  else {
    kk_std_core_hnd__clause1_dup(fun_satisfy);
    kk_std_text_parse__hnd_parse_decref(h, _ctx);
  }
  _match_4391 = fun_satisfy; /*forall<a> std/core/hnd/clause1<(sslice) -> total maybe<(a, sslice)>,maybe<a>,std/text/parse/.hnd-parse,3528,3529>*/
  kk_function_t _fun_unbox_x3618 = _match_4391.clause;
  _x4856 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x3618, (_fun_unbox_x3618, m, ev_2574, kk_function_box(kk_std_text_parse_new_no_digit_fun4860(_ctx)), _ctx)); /*53*/
  x_2726 = kk_std_core_types__maybe_unbox(_x4856, _ctx); /*maybe<char>*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__maybe_drop(x_2726, _ctx);
    kk_box_t _x4868 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_no_digit_fun4869(_ctx), _ctx); /*3991*/
    return kk_char_unbox(_x4868, _ctx);
  }
  if (kk_std_core_types__is_Nothing(x_2726)) {
    kk_box_t _x4873;
    kk_string_t _x4874;
    kk_define_string_literal(, _s4875, 11, "not a digit")
    _x4874 = kk_string_dup(_s4875); /*string*/
    _x4873 = kk_std_text_parse_fail(_x4874, _ctx); /*492*/
    return kk_char_unbox(_x4873, _ctx);
  }
  kk_box_t _box_x3643 = x_2726._cons.Just.value;
  kk_char_t x0 = kk_char_unbox(_box_x3643, NULL);
  kk_std_core_types__maybe_drop(x_2726, _ctx);
  return x0;
}


// lift anonymous function
struct kk_std_text_parse_none_of_fun4882__t {
  struct kk_function_s _base;
  kk_string_t chars;
};
static kk_box_t kk_std_text_parse_none_of_fun4882(kk_function_t _fself, kk_box_t _b_3662, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_none_of_fun4882(kk_string_t chars, kk_context_t* _ctx) {
  struct kk_std_text_parse_none_of_fun4882__t* _self = kk_function_alloc_as(struct kk_std_text_parse_none_of_fun4882__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_text_parse_none_of_fun4882, kk_context());
  _self->chars = chars;
  return &_self->_base;
}

static kk_box_t kk_std_text_parse_none_of_fun4882(kk_function_t _fself, kk_box_t _b_3662, kk_context_t* _ctx) {
  struct kk_std_text_parse_none_of_fun4882__t* _self = kk_function_as(struct kk_std_text_parse_none_of_fun4882__t*, _fself);
  kk_string_t chars = _self->chars; /* string */
  kk_drop_match(_self, {kk_string_dup(chars);}, {}, _ctx)
  kk_std_core_types__maybe _x4883;
  kk_std_core_types__maybe _match_4389;
  kk_std_core__sslice _x4884 = kk_std_core__sslice_unbox(_b_3662, _ctx); /*sslice*/
  _match_4389 = kk_std_core_next(_x4884, _ctx); /*maybe<(char, sslice)>*/
  if (kk_std_core_types__is_Just(_match_4389)) {
    kk_box_t _box_x3663 = _match_4389._cons.Just.value;
    kk_std_core_types__tuple2_ _pat01 = kk_std_core_types__tuple2__unbox(_box_x3663, NULL);
    if (kk_std_core_types__is_dash__lp__comma__rp_(_pat01)) {
      kk_box_t _box_x3664 = _pat01.fst;
      kk_box_t _box_x3665 = _pat01.snd;
      kk_char_t c = kk_char_unbox(_box_x3664, NULL);
      kk_std_core__sslice rest0 = kk_std_core__sslice_unbox(_box_x3665, NULL);
      bool _x4889;
      kk_string_t _x4890 = kk_string_dup(chars); /*string*/
      kk_string_t _x4891 = kk_std_core_string(c, _ctx); /*string*/
      _x4889 = kk_string_contains(_x4890,_x4891,kk_context()); /*bool*/
      if (!(_x4889)) {
        kk_string_drop(chars, _ctx);
        kk_std_core__sslice_dup(rest0);
        kk_std_core_types__maybe_drop(_match_4389, _ctx);
        kk_std_core_types__tuple2_ _b_3673_3668 = kk_std_core_types__new_dash__lp__comma__rp_(kk_char_box(c, _ctx), kk_std_core__sslice_box(rest0, _ctx), _ctx); /*(char, sslice)*/;
        _x4883 = kk_std_core_types__new_Just(kk_std_core_types__tuple2__box(_b_3673_3668, _ctx), _ctx); /*maybe<103>*/
        goto _match4885;
      }
    }
  }
  kk_std_core_types__maybe_drop(_match_4389, _ctx);
  kk_string_drop(chars, _ctx);
  _x4883 = kk_std_core_types__new_Nothing(_ctx); /*maybe<103>*/
  _match4885: ;
  return kk_std_core_types__maybe_box(_x4883, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_none_of_fun4893__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse_none_of_fun4893(kk_function_t _fself, kk_box_t _b_3679, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_none_of_fun4893(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_none_of_fun4893, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_text_parse_none_of_fun4893(kk_function_t _fself, kk_box_t _b_3679, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x4894 = kk_string_empty(); /*string*/
  kk_std_core_types__maybe _x4896 = kk_std_core_types__maybe_unbox(_b_3679, _ctx); /*maybe<char>*/
  return kk_std_text_parse__mlift2547_satisfy_fail(_x4894, _x4896, _ctx);
}

kk_char_t kk_std_text_parse_none_of(kk_string_t chars, kk_context_t* _ctx) { /* (chars : string) -> parse char */ 
  kk_std_core_types__maybe x_2735;
  kk_std_core_hnd__ev ev_2574;
  size_t _x4877 = ((size_t)0); /*size_t*/
  ev_2574 = kk_evv_at(_x4877,kk_context()); /*std/core/hnd/ev<std/text/parse/.hnd-parse>*/
  kk_box_t _x4878;
  struct kk_std_core_hnd_Ev* _con4879 = kk_std_core_hnd__as_Ev(ev_2574);
  kk_std_core_hnd__marker m = _con4879->marker;
  kk_box_t _box_x3649 = _con4879->hnd;
  kk_std_text_parse__hnd_parse h = kk_std_text_parse__hnd_parse_unbox(_box_x3649, NULL);
  kk_std_text_parse__hnd_parse_dup(h);
  kk_std_core_hnd__clause1 _match_4388;
  struct kk_std_text_parse__Hnd_parse* _con4881 = kk_std_text_parse__as_Hnd_parse(h);
  kk_std_core_hnd__clause0 _pat00 = _con4881->fun_current_input;
  kk_std_core_hnd__clause1 _pat10 = _con4881->control_fail;
  kk_std_core_hnd__clause0 _pat20 = _con4881->control_pick;
  kk_std_core_hnd__clause1 fun_satisfy = _con4881->fun_satisfy;
  if (kk_std_text_parse__hnd_parse_is_unique(h)) {
    kk_std_core_hnd__clause0_drop(_pat20, _ctx);
    kk_std_core_hnd__clause1_drop(_pat10, _ctx);
    kk_std_core_hnd__clause0_drop(_pat00, _ctx);
    kk_std_text_parse__hnd_parse_free(h);
  }
  else {
    kk_std_core_hnd__clause1_dup(fun_satisfy);
    kk_std_text_parse__hnd_parse_decref(h, _ctx);
  }
  _match_4388 = fun_satisfy; /*forall<a> std/core/hnd/clause1<(sslice) -> total maybe<(a, sslice)>,maybe<a>,std/text/parse/.hnd-parse,3528,3529>*/
  kk_function_t _fun_unbox_x3656 = _match_4388.clause;
  _x4878 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x3656, (_fun_unbox_x3656, m, ev_2574, kk_function_box(kk_std_text_parse_new_none_of_fun4882(chars, _ctx)), _ctx)); /*53*/
  x_2735 = kk_std_core_types__maybe_unbox(_x4878, _ctx); /*maybe<char>*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__maybe_drop(x_2735, _ctx);
    kk_box_t _x4892 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_none_of_fun4893(_ctx), _ctx); /*3991*/
    return kk_char_unbox(_x4892, _ctx);
  }
  if (kk_std_core_types__is_Nothing(x_2735)) {
    kk_box_t _x4897;
    kk_string_t _x4898 = kk_string_empty(); /*string*/
    _x4897 = kk_std_text_parse_fail(_x4898, _ctx); /*492*/
    return kk_char_unbox(_x4897, _ctx);
  }
  kk_box_t _box_x3681 = x_2735._cons.Just.value;
  kk_char_t x0 = kk_char_unbox(_box_x3681, NULL);
  kk_std_core_types__maybe_drop(x_2735, _ctx);
  return x0;
}


// lift anonymous function
struct kk_std_text_parse_none_of_many1_fun4906__t {
  struct kk_function_s _base;
  kk_string_t chars;
};
static kk_box_t kk_std_text_parse_none_of_many1_fun4906(kk_function_t _fself, kk_box_t _b_3700, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_none_of_many1_fun4906(kk_string_t chars, kk_context_t* _ctx) {
  struct kk_std_text_parse_none_of_many1_fun4906__t* _self = kk_function_alloc_as(struct kk_std_text_parse_none_of_many1_fun4906__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_text_parse_none_of_many1_fun4906, kk_context());
  _self->chars = chars;
  return &_self->_base;
}



// lift anonymous function
struct kk_std_text_parse_none_of_many1_fun4909__t {
  struct kk_function_s _base;
  kk_string_t chars;
};
static bool kk_std_text_parse_none_of_many1_fun4909(kk_function_t _fself, kk_char_t c, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_none_of_many1_fun4909(kk_string_t chars, kk_context_t* _ctx) {
  struct kk_std_text_parse_none_of_many1_fun4909__t* _self = kk_function_alloc_as(struct kk_std_text_parse_none_of_many1_fun4909__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_text_parse_none_of_many1_fun4909, kk_context());
  _self->chars = chars;
  return &_self->_base;
}

static bool kk_std_text_parse_none_of_many1_fun4909(kk_function_t _fself, kk_char_t c, kk_context_t* _ctx) {
  struct kk_std_text_parse_none_of_many1_fun4909__t* _self = kk_function_as(struct kk_std_text_parse_none_of_many1_fun4909__t*, _fself);
  kk_string_t chars = _self->chars; /* string */
  kk_drop_match(_self, {kk_string_dup(chars);}, {}, _ctx)
  bool _x4910;
  kk_string_t _x4911 = kk_std_core_string(c, _ctx); /*string*/
  _x4910 = kk_string_contains(chars,_x4911,kk_context()); /*bool*/
  return !(_x4910);
}
static kk_box_t kk_std_text_parse_none_of_many1_fun4906(kk_function_t _fself, kk_box_t _b_3700, kk_context_t* _ctx) {
  struct kk_std_text_parse_none_of_many1_fun4906__t* _self = kk_function_as(struct kk_std_text_parse_none_of_many1_fun4906__t*, _fself);
  kk_string_t chars = _self->chars; /* string */
  kk_drop_match(_self, {kk_string_dup(chars);}, {}, _ctx)
  kk_std_core_types__maybe _x4907;
  kk_std_core_types__tuple2_ _match_4386;
  kk_std_core__sslice _x4908 = kk_std_core__sslice_unbox(_b_3700, _ctx); /*sslice*/
  _match_4386 = kk_std_text_parse_next_while0(_x4908, kk_std_text_parse_new_none_of_many1_fun4909(chars, _ctx), kk_std_core__new_Nil(_ctx), _ctx); /*(list<char>, sslice)*/
  kk_box_t _box_x3701 = _match_4386.fst;
  kk_box_t _box_x3702 = _match_4386.snd;
  kk_std_core__list _pat02 = kk_std_core__list_unbox(_box_x3701, NULL);
  kk_std_core__sslice _pat100 = kk_std_core__sslice_unbox(_box_x3702, NULL);
  if (kk_std_core__is_Nil(_pat02)) {
    kk_std_core_types__tuple2__drop(_match_4386, _ctx);
    _x4907 = kk_std_core_types__new_Nothing(_ctx); /*forall<a> maybe<a>*/
    goto _match4912;
  }
  kk_box_t _box_x3703 = _match_4386.fst;
  kk_box_t _box_x3704 = _match_4386.snd;
  kk_std_core__list xs = kk_std_core__list_unbox(_box_x3703, NULL);
  kk_std_core__sslice rest0 = kk_std_core__sslice_unbox(_box_x3704, NULL);
  kk_std_core__sslice_dup(rest0);
  kk_std_core__list_dup(xs);
  kk_std_core_types__tuple2__drop(_match_4386, _ctx);
  kk_std_core_types__tuple2_ _b_3712_3707 = kk_std_core_types__new_dash__lp__comma__rp_(kk_std_core__list_box(xs, _ctx), kk_std_core__sslice_box(rest0, _ctx), _ctx); /*(list<char>, sslice)*/;
  _x4907 = kk_std_core_types__new_Just(kk_std_core_types__tuple2__box(_b_3712_3707, _ctx), _ctx); /*forall<a> maybe<a>*/
  _match4912: ;
  return kk_std_core_types__maybe_box(_x4907, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_none_of_many1_fun4918__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse_none_of_many1_fun4918(kk_function_t _fself, kk_box_t _b_3718, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_none_of_many1_fun4918(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_none_of_many1_fun4918, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_text_parse_none_of_many1_fun4918(kk_function_t _fself, kk_box_t _b_3718, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x4919 = kk_string_empty(); /*string*/
  kk_std_core_types__maybe _x4921 = kk_std_core_types__maybe_unbox(_b_3718, _ctx); /*maybe<list<char>>*/
  return kk_std_text_parse__mlift2547_satisfy_fail(_x4919, _x4921, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_none_of_many1_fun4927__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse_none_of_many1_fun4927(kk_function_t _fself, kk_box_t _b_3727, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_none_of_many1_fun4927(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_none_of_many1_fun4927, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_text_parse_none_of_many1_fun4927(kk_function_t _fself, kk_box_t _b_3727, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x4928;
  kk_std_core__list _x4929 = kk_std_core__list_unbox(_b_3727, _ctx); /*list<char>*/
  _x4928 = kk_std_core_string_2(_x4929, _ctx); /*string*/
  return kk_string_box(_x4928);
}

kk_string_t kk_std_text_parse_none_of_many1(kk_string_t chars, kk_context_t* _ctx) { /* (chars : string) -> parse string */ 
  kk_std_core__list x_2740;
  kk_std_core_types__maybe x0_2746;
  kk_std_core_hnd__ev ev_2574;
  size_t _x4901 = ((size_t)0); /*size_t*/
  ev_2574 = kk_evv_at(_x4901,kk_context()); /*std/core/hnd/ev<std/text/parse/.hnd-parse>*/
  kk_box_t _x4902;
  struct kk_std_core_hnd_Ev* _con4903 = kk_std_core_hnd__as_Ev(ev_2574);
  kk_std_core_hnd__marker m = _con4903->marker;
  kk_box_t _box_x3687 = _con4903->hnd;
  kk_std_text_parse__hnd_parse h = kk_std_text_parse__hnd_parse_unbox(_box_x3687, NULL);
  kk_std_text_parse__hnd_parse_dup(h);
  kk_std_core_hnd__clause1 _match_4385;
  struct kk_std_text_parse__Hnd_parse* _con4905 = kk_std_text_parse__as_Hnd_parse(h);
  kk_std_core_hnd__clause0 _pat00 = _con4905->fun_current_input;
  kk_std_core_hnd__clause1 _pat10 = _con4905->control_fail;
  kk_std_core_hnd__clause0 _pat20 = _con4905->control_pick;
  kk_std_core_hnd__clause1 fun_satisfy = _con4905->fun_satisfy;
  if (kk_std_text_parse__hnd_parse_is_unique(h)) {
    kk_std_core_hnd__clause0_drop(_pat20, _ctx);
    kk_std_core_hnd__clause1_drop(_pat10, _ctx);
    kk_std_core_hnd__clause0_drop(_pat00, _ctx);
    kk_std_text_parse__hnd_parse_free(h);
  }
  else {
    kk_std_core_hnd__clause1_dup(fun_satisfy);
    kk_std_text_parse__hnd_parse_decref(h, _ctx);
  }
  _match_4385 = fun_satisfy; /*forall<a> std/core/hnd/clause1<(sslice) -> total maybe<(a, sslice)>,maybe<a>,std/text/parse/.hnd-parse,3528,3529>*/
  kk_function_t _fun_unbox_x3694 = _match_4385.clause;
  _x4902 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x3694, (_fun_unbox_x3694, m, ev_2574, kk_function_box(kk_std_text_parse_new_none_of_many1_fun4906(chars, _ctx)), _ctx)); /*53*/
  x0_2746 = kk_std_core_types__maybe_unbox(_x4902, _ctx); /*maybe<list<char>>*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__maybe_drop(x0_2746, _ctx);
    kk_box_t _x4917 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_none_of_many1_fun4918(_ctx), _ctx); /*3991*/
    x_2740 = kk_std_core__list_unbox(_x4917, _ctx); /*list<char>*/
  }
  else {
    if (kk_std_core_types__is_Nothing(x0_2746)) {
      kk_box_t _x4922;
      kk_string_t _x4923 = kk_string_empty(); /*string*/
      _x4922 = kk_std_text_parse_fail(_x4923, _ctx); /*492*/
      x_2740 = kk_std_core__list_unbox(_x4922, _ctx); /*list<char>*/
    }
    else {
      kk_box_t _box_x3720 = x0_2746._cons.Just.value;
      kk_std_core__list x1 = kk_std_core__list_unbox(_box_x3720, NULL);
      kk_std_core__list_dup(x1);
      kk_std_core_types__maybe_drop(x0_2746, _ctx);
      x_2740 = x1; /*list<char>*/
    }
  }
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_2740, _ctx);
    kk_box_t _x4926 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_none_of_many1_fun4927(_ctx), _ctx); /*3991*/
    return kk_string_unbox(_x4926);
  }
  return kk_std_core_string_2(x_2740, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_one_of_fun4937__t {
  struct kk_function_s _base;
  kk_string_t chars;
};
static kk_box_t kk_std_text_parse_one_of_fun4937(kk_function_t _fself, kk_box_t _b_3742, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_one_of_fun4937(kk_string_t chars, kk_context_t* _ctx) {
  struct kk_std_text_parse_one_of_fun4937__t* _self = kk_function_alloc_as(struct kk_std_text_parse_one_of_fun4937__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_text_parse_one_of_fun4937, kk_context());
  _self->chars = chars;
  return &_self->_base;
}

static kk_box_t kk_std_text_parse_one_of_fun4937(kk_function_t _fself, kk_box_t _b_3742, kk_context_t* _ctx) {
  struct kk_std_text_parse_one_of_fun4937__t* _self = kk_function_as(struct kk_std_text_parse_one_of_fun4937__t*, _fself);
  kk_string_t chars = _self->chars; /* string */
  kk_drop_match(_self, {kk_string_dup(chars);}, {}, _ctx)
  kk_std_core_types__maybe _x4938;
  kk_std_core_types__maybe _match_4382;
  kk_std_core__sslice _x4939 = kk_std_core__sslice_unbox(_b_3742, _ctx); /*sslice*/
  _match_4382 = kk_std_core_next(_x4939, _ctx); /*maybe<(char, sslice)>*/
  if (kk_std_core_types__is_Just(_match_4382)) {
    kk_box_t _box_x3743 = _match_4382._cons.Just.value;
    kk_std_core_types__tuple2_ _pat01 = kk_std_core_types__tuple2__unbox(_box_x3743, NULL);
    if (kk_std_core_types__is_dash__lp__comma__rp_(_pat01)) {
      kk_box_t _box_x3744 = _pat01.fst;
      kk_box_t _box_x3745 = _pat01.snd;
      kk_char_t c = kk_char_unbox(_box_x3744, NULL);
      kk_std_core__sslice rest0 = kk_std_core__sslice_unbox(_box_x3745, NULL);
      kk_string_t _x4944 = kk_string_dup(chars); /*string*/
      kk_string_t _x4945 = kk_std_core_string(c, _ctx); /*string*/
      if (kk_string_contains(_x4944,_x4945,kk_context())) {
        kk_string_drop(chars, _ctx);
        kk_std_core__sslice_dup(rest0);
        kk_std_core_types__maybe_drop(_match_4382, _ctx);
        kk_std_core_types__tuple2_ _b_3753_3748 = kk_std_core_types__new_dash__lp__comma__rp_(kk_char_box(c, _ctx), kk_std_core__sslice_box(rest0, _ctx), _ctx); /*(char, sslice)*/;
        _x4938 = kk_std_core_types__new_Just(kk_std_core_types__tuple2__box(_b_3753_3748, _ctx), _ctx); /*maybe<103>*/
        goto _match4940;
      }
    }
  }
  kk_std_core_types__maybe_drop(_match_4382, _ctx);
  kk_string_drop(chars, _ctx);
  _x4938 = kk_std_core_types__new_Nothing(_ctx); /*maybe<103>*/
  _match4940: ;
  return kk_std_core_types__maybe_box(_x4938, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_one_of_fun4947__t {
  struct kk_function_s _base;
  kk_string_t chars;
};
static kk_box_t kk_std_text_parse_one_of_fun4947(kk_function_t _fself, kk_box_t _b_3759, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_one_of_fun4947(kk_string_t chars, kk_context_t* _ctx) {
  struct kk_std_text_parse_one_of_fun4947__t* _self = kk_function_alloc_as(struct kk_std_text_parse_one_of_fun4947__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_text_parse_one_of_fun4947, kk_context());
  _self->chars = chars;
  return &_self->_base;
}

static kk_box_t kk_std_text_parse_one_of_fun4947(kk_function_t _fself, kk_box_t _b_3759, kk_context_t* _ctx) {
  struct kk_std_text_parse_one_of_fun4947__t* _self = kk_function_as(struct kk_std_text_parse_one_of_fun4947__t*, _fself);
  kk_string_t chars = _self->chars; /* string */
  kk_drop_match(_self, {kk_string_dup(chars);}, {}, _ctx)
  kk_std_core_types__maybe _x4948 = kk_std_core_types__maybe_unbox(_b_3759, _ctx); /*maybe<char>*/
  return kk_std_text_parse__mlift2547_satisfy_fail(chars, _x4948, _ctx);
}

kk_char_t kk_std_text_parse_one_of(kk_string_t chars, kk_context_t* _ctx) { /* (chars : string) -> parse char */ 
  kk_std_core_types__maybe x_2754;
  kk_std_core_hnd__ev ev_2574;
  size_t _x4930 = ((size_t)0); /*size_t*/
  ev_2574 = kk_evv_at(_x4930,kk_context()); /*std/core/hnd/ev<std/text/parse/.hnd-parse>*/
  kk_box_t _x4931;
  struct kk_std_core_hnd_Ev* _con4932 = kk_std_core_hnd__as_Ev(ev_2574);
  kk_std_core_hnd__marker m = _con4932->marker;
  kk_box_t _box_x3729 = _con4932->hnd;
  kk_std_text_parse__hnd_parse h = kk_std_text_parse__hnd_parse_unbox(_box_x3729, NULL);
  kk_std_text_parse__hnd_parse_dup(h);
  kk_std_core_hnd__clause1 _match_4381;
  struct kk_std_text_parse__Hnd_parse* _con4934 = kk_std_text_parse__as_Hnd_parse(h);
  kk_std_core_hnd__clause0 _pat00 = _con4934->fun_current_input;
  kk_std_core_hnd__clause1 _pat10 = _con4934->control_fail;
  kk_std_core_hnd__clause0 _pat20 = _con4934->control_pick;
  kk_std_core_hnd__clause1 fun_satisfy = _con4934->fun_satisfy;
  if (kk_std_text_parse__hnd_parse_is_unique(h)) {
    kk_std_core_hnd__clause0_drop(_pat20, _ctx);
    kk_std_core_hnd__clause1_drop(_pat10, _ctx);
    kk_std_core_hnd__clause0_drop(_pat00, _ctx);
    kk_std_text_parse__hnd_parse_free(h);
  }
  else {
    kk_std_core_hnd__clause1_dup(fun_satisfy);
    kk_std_text_parse__hnd_parse_decref(h, _ctx);
  }
  _match_4381 = fun_satisfy; /*forall<a> std/core/hnd/clause1<(sslice) -> total maybe<(a, sslice)>,maybe<a>,std/text/parse/.hnd-parse,3528,3529>*/
  kk_function_t _fun_unbox_x3736 = _match_4381.clause;
  kk_box_t _x4935;
  kk_function_t _x4936;
  kk_string_dup(chars);
  _x4936 = kk_std_text_parse_new_one_of_fun4937(chars, _ctx); /*(3740) -> total 3741*/
  _x4935 = kk_function_box(_x4936); /*52*/
  _x4931 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x3736, (_fun_unbox_x3736, m, ev_2574, _x4935, _ctx)); /*53*/
  x_2754 = kk_std_core_types__maybe_unbox(_x4931, _ctx); /*maybe<char>*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__maybe_drop(x_2754, _ctx);
    kk_box_t _x4946 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_one_of_fun4947(chars, _ctx), _ctx); /*3991*/
    return kk_char_unbox(_x4946, _ctx);
  }
  if (kk_std_core_types__is_Nothing(x_2754)) {
    kk_box_t _x4949 = kk_std_text_parse_fail(chars, _ctx); /*492*/
    return kk_char_unbox(_x4949, _ctx);
  }
  kk_box_t _box_x3761 = x_2754._cons.Just.value;
  kk_char_t x0 = kk_char_unbox(_box_x3761, NULL);
  kk_std_core_types__maybe_drop(x_2754, _ctx);
  kk_string_drop(chars, _ctx);
  return x0;
}


// lift anonymous function
struct kk_std_text_parse_one_of_or_fun4957__t {
  struct kk_function_s _base;
  size_t i_2666;
};
static kk_box_t kk_std_text_parse_one_of_or_fun4957(kk_function_t _fself, kk_function_t _b_3780, kk_box_t _b_3781, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_one_of_or_fun4957(size_t i_2666, kk_context_t* _ctx) {
  struct kk_std_text_parse_one_of_or_fun4957__t* _self = kk_function_alloc_as(struct kk_std_text_parse_one_of_or_fun4957__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_text_parse_one_of_or_fun4957, kk_context());
  _self->i_2666 = i_2666;
  return &_self->_base;
}

static kk_box_t kk_std_text_parse_one_of_or_fun4957(kk_function_t _fself, kk_function_t _b_3780, kk_box_t _b_3781, kk_context_t* _ctx) {
  struct kk_std_text_parse_one_of_or_fun4957__t* _self = kk_function_as(struct kk_std_text_parse_one_of_or_fun4957__t*, _fself);
  size_t i_2666 = _self->i_2666; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_2666, _b_3780, _b_3781, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_one_of_or_fun4959__t {
  struct kk_function_s _base;
  kk_string_t chars;
  kk_char_t kkloc_default;
};
static kk_box_t kk_std_text_parse_one_of_or_fun4959(kk_function_t _fself, kk_box_t _b_3794, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_one_of_or_fun4959(kk_string_t chars, kk_char_t kkloc_default, kk_context_t* _ctx) {
  struct kk_std_text_parse_one_of_or_fun4959__t* _self = kk_function_alloc_as(struct kk_std_text_parse_one_of_or_fun4959__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_text_parse_one_of_or_fun4959, kk_context());
  _self->chars = chars;
  _self->kkloc_default = kkloc_default;
  return &_self->_base;
}



// lift anonymous function
struct kk_std_text_parse_one_of_or_fun4960__t {
  struct kk_function_s _base;
  kk_string_t chars;
};
static kk_box_t kk_std_text_parse_one_of_or_fun4960(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_one_of_or_fun4960(kk_string_t chars, kk_context_t* _ctx) {
  struct kk_std_text_parse_one_of_or_fun4960__t* _self = kk_function_alloc_as(struct kk_std_text_parse_one_of_or_fun4960__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_text_parse_one_of_or_fun4960, kk_context());
  _self->chars = chars;
  return &_self->_base;
}

static kk_box_t kk_std_text_parse_one_of_or_fun4960(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_text_parse_one_of_or_fun4960__t* _self = kk_function_as(struct kk_std_text_parse_one_of_or_fun4960__t*, _fself);
  kk_string_t chars = _self->chars; /* string */
  kk_drop_match(_self, {kk_string_dup(chars);}, {}, _ctx)
  kk_char_t _x4961 = kk_std_text_parse_one_of(chars, _ctx); /*char*/
  return kk_char_box(_x4961, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_one_of_or_fun4962__t {
  struct kk_function_s _base;
  kk_char_t kkloc_default;
};
static kk_box_t kk_std_text_parse_one_of_or_fun4962(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_one_of_or_fun4962(kk_char_t kkloc_default, kk_context_t* _ctx) {
  struct kk_std_text_parse_one_of_or_fun4962__t* _self = kk_function_alloc_as(struct kk_std_text_parse_one_of_or_fun4962__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_text_parse_one_of_or_fun4962, kk_context());
  _self->kkloc_default = kkloc_default;
  return &_self->_base;
}

static kk_box_t kk_std_text_parse_one_of_or_fun4962(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_text_parse_one_of_or_fun4962__t* _self = kk_function_as(struct kk_std_text_parse_one_of_or_fun4962__t*, _fself);
  kk_char_t kkloc_default = _self->kkloc_default; /* char */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_char_box(kkloc_default, _ctx);
}
static kk_box_t kk_std_text_parse_one_of_or_fun4959(kk_function_t _fself, kk_box_t _b_3794, kk_context_t* _ctx) {
  struct kk_std_text_parse_one_of_or_fun4959__t* _self = kk_function_as(struct kk_std_text_parse_one_of_or_fun4959__t*, _fself);
  kk_string_t chars = _self->chars; /* string */
  kk_char_t kkloc_default = _self->kkloc_default; /* char */
  kk_drop_match(_self, {kk_string_dup(chars);;}, {}, _ctx)
  bool _x4963 = kk_bool_unbox(_b_3794); /*bool*/
  return kk_std_text_parse__mlift2551_op(kk_std_text_parse_new_one_of_or_fun4960(chars, _ctx), kk_std_text_parse_new_one_of_or_fun4962(kkloc_default, _ctx), _x4963, _ctx);
}

kk_char_t kk_std_text_parse_one_of_or(kk_string_t chars, kk_char_t kkloc_default, kk_context_t* _ctx) { /* (chars : string, default : char) -> parse char */ 
  bool x_2663;
  size_t i_2666 = ((size_t)0); /*std/core/hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_2666,kk_context()); /*std/core/hnd/evv<std/text/parse/parse>*/;
  bool y;
  kk_std_core_hnd__ev ev_2668;
  size_t _x4951 = ((size_t)0); /*size_t*/
  ev_2668 = kk_evv_at(_x4951,kk_context()); /*std/core/hnd/ev<std/text/parse/.hnd-parse>*/
  kk_box_t _x4952;
  struct kk_std_core_hnd_Ev* _con4953 = kk_std_core_hnd__as_Ev(ev_2668);
  kk_std_core_hnd__marker m = _con4953->marker;
  kk_box_t _box_x3767 = _con4953->hnd;
  kk_std_text_parse__hnd_parse h = kk_std_text_parse__hnd_parse_unbox(_box_x3767, NULL);
  kk_std_text_parse__hnd_parse_dup(h);
  kk_std_core_hnd__clause0 _match_4379;
  struct kk_std_text_parse__Hnd_parse* _con4955 = kk_std_text_parse__as_Hnd_parse(h);
  kk_std_core_hnd__clause0 _pat0 = _con4955->fun_current_input;
  kk_std_core_hnd__clause1 _pat1 = _con4955->control_fail;
  kk_std_core_hnd__clause0 control_pick = _con4955->control_pick;
  kk_std_core_hnd__clause1 _pat21 = _con4955->fun_satisfy;
  if (kk_std_text_parse__hnd_parse_is_unique(h)) {
    kk_std_core_hnd__clause1_drop(_pat21, _ctx);
    kk_std_core_hnd__clause1_drop(_pat1, _ctx);
    kk_std_core_hnd__clause0_drop(_pat0, _ctx);
    kk_std_text_parse__hnd_parse_free(h);
  }
  else {
    kk_std_core_hnd__clause0_dup(control_pick);
    kk_std_text_parse__hnd_parse_decref(h, _ctx);
  }
  _match_4379 = control_pick; /*std/core/hnd/clause0<bool,std/text/parse/.hnd-parse,3435,3436>*/
  kk_function_t _fun_unbox_x3770 = _match_4379.clause;
  _x4952 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x3770, (_fun_unbox_x3770, m, ev_2668, _ctx)); /*37*/
  y = kk_bool_unbox(_x4952); /*bool*/
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x4956 = kk_std_core_hnd_yield_cont(kk_std_text_parse_new_one_of_or_fun4957(i_2666, _ctx), _ctx); /*3820*/
    x_2663 = kk_bool_unbox(_x4956); /*bool*/
  }
  else {
    x_2663 = y; /*bool*/
  }
  if (kk_yielding(kk_context())) {
    kk_box_t _x4958 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_one_of_or_fun4959(chars, kkloc_default, _ctx), _ctx); /*3991*/
    return kk_char_unbox(_x4958, _ctx);
  }
  if (x_2663) {
    return kk_std_text_parse_one_of(chars, _ctx);
  }
  kk_string_drop(chars, _ctx);
  return kkloc_default;
}
 
// monadic lift

kk_std_text_parse__parse_error kk_std_text_parse__mlift2556_parse(kk_string_t msg, kk_std_core__sslice _y_49, kk_context_t* _ctx) { /* forall<_h,h1,a,e> (msg : string, sslice) -> <local<h1>,local<_h>|e> parse-error<a> */ 
  return kk_std_text_parse__new_ParseError(kk_reuse_null, msg, _y_49, _ctx);
}
 
// monadic lift

kk_std_text_parse__parse_error kk_std_text_parse__mlift2557_parse(kk_std_text_parse__parse_error err1, kk_std_text_parse__parse_error _y_53, kk_context_t* _ctx) { /* forall<_h,h1,a,e> (err1 : parse-error<a>, parse-error<a>) -> <local<h1>,local<_h>|e> parse-error<a> */ 
  if (kk_std_text_parse__is_ParseOk(_y_53)) {
    struct kk_std_text_parse_ParseOk* _con4964 = kk_std_text_parse__as_ParseOk(_y_53);
    kk_box_t x2 = _con4964->result;
    kk_std_core__sslice rest2 = _con4964->rest;
    kk_reuse_t _ru_4314 = kk_reuse_null; /*reuse*/;
    if (kk_std_text_parse__parse_error_is_unique(_y_53)) {
      _ru_4314 = (kk_std_text_parse__parse_error_reuse(_y_53));
    }
    else {
      kk_std_core__sslice_dup(rest2);
      kk_box_dup(x2);
      kk_std_text_parse__parse_error_decref(_y_53, _ctx);
      _ru_4314 = kk_reuse_null;
    }
    kk_std_text_parse__parse_error_drop(err1, _ctx);
    bool _x4965 = _ru_4314!=NULL; /*bool*/
    if (_x4965) {
      struct kk_std_text_parse_ParseOk* _con4966 = (struct kk_std_text_parse_ParseOk*)_ru_4314;
      return kk_std_text_parse__base_ParseOk(_con4966);
    }
    return kk_std_text_parse__new_ParseOk(kk_reuse_null, x2, rest2, _ctx);
  }
  kk_std_text_parse__parse_error_drop(_y_53, _ctx);
  return err1;
}
 
// monadic lift


// lift anonymous function
struct kk_std_text_parse__mlift2558_parse_fun4968__t {
  struct kk_function_s _base;
  kk_std_text_parse__parse_error err1;
};
static kk_box_t kk_std_text_parse__mlift2558_parse_fun4968(kk_function_t _fself, kk_box_t _b_3801, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse__new_mlift2558_parse_fun4968(kk_std_text_parse__parse_error err1, kk_context_t* _ctx) {
  struct kk_std_text_parse__mlift2558_parse_fun4968__t* _self = kk_function_alloc_as(struct kk_std_text_parse__mlift2558_parse_fun4968__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_text_parse__mlift2558_parse_fun4968, kk_context());
  _self->err1 = err1;
  return &_self->_base;
}

static kk_box_t kk_std_text_parse__mlift2558_parse_fun4968(kk_function_t _fself, kk_box_t _b_3801, kk_context_t* _ctx) {
  struct kk_std_text_parse__mlift2558_parse_fun4968__t* _self = kk_function_as(struct kk_std_text_parse__mlift2558_parse_fun4968__t*, _fself);
  kk_std_text_parse__parse_error err1 = _self->err1; /* std/text/parse/parse-error<2282> */
  kk_drop_match(_self, {kk_std_text_parse__parse_error_dup(err1);}, {}, _ctx)
  kk_std_text_parse__parse_error _x4969;
  kk_std_text_parse__parse_error _x4970 = kk_std_text_parse__parse_error_unbox(_b_3801, _ctx); /*std/text/parse/parse-error<2282>*/
  _x4969 = kk_std_text_parse__mlift2557_parse(err1, _x4970, _ctx); /*std/text/parse/parse-error<2282>*/
  return kk_std_text_parse__parse_error_box(_x4969, _ctx);
}

kk_std_text_parse__parse_error kk_std_text_parse__mlift2558_parse(kk_std_text_parse__parse_error err1, kk_function_t resume0, kk_unit_t wild__, kk_context_t* _ctx) { /* forall<_h,h1,a,e> (err1 : parse-error<a>, resume0 : (bool) -> <local<h1>,local<_h>|e> parse-error<a>, wild_ : ()) -> <local<h1>,local<_h>|e> parse-error<a> */ 
  kk_std_text_parse__parse_error x_2761 = kk_function_call(kk_std_text_parse__parse_error, (kk_function_t, bool, kk_context_t*), resume0, (resume0, false, _ctx)); /*std/text/parse/parse-error<2282>*/;
  if (kk_yielding(kk_context())) {
    kk_std_text_parse__parse_error_drop(x_2761, _ctx);
    kk_box_t _x4967 = kk_std_core_hnd_yield_extend(kk_std_text_parse__new_mlift2558_parse_fun4968(err1, _ctx), _ctx); /*3991*/
    return kk_std_text_parse__parse_error_unbox(_x4967, _ctx);
  }
  return kk_std_text_parse__mlift2557_parse(err1, x_2761, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_text_parse__mlift2559_parse_fun4975__t {
  struct kk_function_s _base;
  kk_std_text_parse__parse_error _y_51;
  kk_function_t resume0;
};
static kk_box_t kk_std_text_parse__mlift2559_parse_fun4975(kk_function_t _fself, kk_box_t _b_3809, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse__new_mlift2559_parse_fun4975(kk_std_text_parse__parse_error _y_51, kk_function_t resume0, kk_context_t* _ctx) {
  struct kk_std_text_parse__mlift2559_parse_fun4975__t* _self = kk_function_alloc_as(struct kk_std_text_parse__mlift2559_parse_fun4975__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_text_parse__mlift2559_parse_fun4975, kk_context());
  _self->_y_51 = _y_51;
  _self->resume0 = resume0;
  return &_self->_base;
}

static kk_box_t kk_std_text_parse__mlift2559_parse_fun4975(kk_function_t _fself, kk_box_t _b_3809, kk_context_t* _ctx) {
  struct kk_std_text_parse__mlift2559_parse_fun4975__t* _self = kk_function_as(struct kk_std_text_parse__mlift2559_parse_fun4975__t*, _fself);
  kk_std_text_parse__parse_error _y_51 = _self->_y_51; /* std/text/parse/parse-error<2282> */
  kk_function_t resume0 = _self->resume0; /* (bool) -> <local<2274>,local<_253>|2283> std/text/parse/parse-error<2282> */
  kk_drop_match(_self, {kk_std_text_parse__parse_error_dup(_y_51);kk_function_dup(resume0);}, {}, _ctx)
  kk_std_text_parse__parse_error _x4976;
  kk_unit_t _x4977 = kk_Unit;
  kk_unit_unbox(_b_3809);
  _x4976 = kk_std_text_parse__mlift2558_parse(_y_51, resume0, _x4977, _ctx); /*std/text/parse/parse-error<2282>*/
  return kk_std_text_parse__parse_error_box(_x4976, _ctx);
}

kk_std_text_parse__parse_error kk_std_text_parse__mlift2559_parse(kk_ref_t input, kk_function_t resume0, kk_std_core__sslice save, kk_std_text_parse__parse_error _y_51, kk_context_t* _ctx) { /* forall<_h,h1,a,e> (input : local-var<h1,sslice>, resume0 : (bool) -> <local<h1>,local<_h>|e> parse-error<a>, save : sslice, parse-error<a>) -> <local<h1>,local<_h>|e> parse-error<a> */ 
  if (kk_std_text_parse__is_ParseOk(_y_51)) {
    struct kk_std_text_parse_ParseOk* _con4971 = kk_std_text_parse__as_ParseOk(_y_51);
    kk_box_t x1 = _con4971->result;
    kk_std_core__sslice rest1 = _con4971->rest;
    kk_reuse_t _ru_4315 = kk_reuse_null; /*reuse*/;
    if (kk_std_text_parse__parse_error_is_unique(_y_51)) {
      _ru_4315 = (kk_std_text_parse__parse_error_reuse(_y_51));
    }
    else {
      kk_std_core__sslice_dup(rest1);
      kk_box_dup(x1);
      kk_std_text_parse__parse_error_decref(_y_51, _ctx);
      _ru_4315 = kk_reuse_null;
    }
    kk_std_core__sslice_drop(save, _ctx);
    kk_function_drop(resume0, _ctx);
    kk_ref_drop(input, _ctx);
    bool _x4972 = _ru_4315!=NULL; /*bool*/
    if (_x4972) {
      struct kk_std_text_parse_ParseOk* _con4973 = (struct kk_std_text_parse_ParseOk*)_ru_4315;
      return kk_std_text_parse__base_ParseOk(_con4973);
    }
    return kk_std_text_parse__new_ParseOk(kk_reuse_null, x1, rest1, _ctx);
  }
  kk_unit_t x_2763 = kk_Unit;
  (kk_ref_set(input,(kk_std_core__sslice_box(save, _ctx)),kk_context()));
  if (kk_yielding(kk_context())) {
    kk_box_t _x4974 = kk_std_core_hnd_yield_extend(kk_std_text_parse__new_mlift2559_parse_fun4975(_y_51, resume0, _ctx), _ctx); /*3991*/
    return kk_std_text_parse__parse_error_unbox(_x4974, _ctx);
  }
  return kk_std_text_parse__mlift2558_parse(_y_51, resume0, x_2763, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_text_parse__mlift2560_parse_fun4980__t {
  struct kk_function_s _base;
  kk_ref_t input;
  kk_function_t resume0;
  kk_std_core__sslice save;
};
static kk_box_t kk_std_text_parse__mlift2560_parse_fun4980(kk_function_t _fself, kk_box_t _b_3813, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse__new_mlift2560_parse_fun4980(kk_ref_t input, kk_function_t resume0, kk_std_core__sslice save, kk_context_t* _ctx) {
  struct kk_std_text_parse__mlift2560_parse_fun4980__t* _self = kk_function_alloc_as(struct kk_std_text_parse__mlift2560_parse_fun4980__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_text_parse__mlift2560_parse_fun4980, kk_context());
  _self->input = input;
  _self->resume0 = resume0;
  _self->save = save;
  return &_self->_base;
}

static kk_box_t kk_std_text_parse__mlift2560_parse_fun4980(kk_function_t _fself, kk_box_t _b_3813, kk_context_t* _ctx) {
  struct kk_std_text_parse__mlift2560_parse_fun4980__t* _self = kk_function_as(struct kk_std_text_parse__mlift2560_parse_fun4980__t*, _fself);
  kk_ref_t input = _self->input; /* local-var<2274,sslice> */
  kk_function_t resume0 = _self->resume0; /* (bool) -> <local<2274>,local<_253>|2283> std/text/parse/parse-error<2282> */
  kk_std_core__sslice save = _self->save; /* sslice */
  kk_drop_match(_self, {kk_ref_dup(input);kk_function_dup(resume0);kk_std_core__sslice_dup(save);}, {}, _ctx)
  kk_std_text_parse__parse_error _x4981;
  kk_std_text_parse__parse_error _x4982 = kk_std_text_parse__parse_error_unbox(_b_3813, _ctx); /*std/text/parse/parse-error<2282>*/
  _x4981 = kk_std_text_parse__mlift2559_parse(input, resume0, save, _x4982, _ctx); /*std/text/parse/parse-error<2282>*/
  return kk_std_text_parse__parse_error_box(_x4981, _ctx);
}

kk_std_text_parse__parse_error kk_std_text_parse__mlift2560_parse(kk_ref_t input, kk_function_t resume0, kk_std_core__sslice save, kk_context_t* _ctx) { /* forall<_h,h1,a,e> (input : local-var<h1,sslice>, resume0 : (bool) -> <local<h1>,local<_h>|e> parse-error<a>, save : sslice) -> <local<h1>,local<_h>|e> parse-error<a> */ 
  kk_std_text_parse__parse_error x_2765;
  kk_function_t _x4978 = kk_function_dup(resume0); /*(bool) -> <local<2274>,local<_253>|2283> std/text/parse/parse-error<2282>*/
  x_2765 = kk_function_call(kk_std_text_parse__parse_error, (kk_function_t, bool, kk_context_t*), _x4978, (_x4978, true, _ctx)); /*std/text/parse/parse-error<2282>*/
  if (kk_yielding(kk_context())) {
    kk_std_text_parse__parse_error_drop(x_2765, _ctx);
    kk_box_t _x4979 = kk_std_core_hnd_yield_extend(kk_std_text_parse__new_mlift2560_parse_fun4980(input, resume0, save, _ctx), _ctx); /*3991*/
    return kk_std_text_parse__parse_error_unbox(_x4979, _ctx);
  }
  return kk_std_text_parse__mlift2559_parse(input, resume0, save, x_2765, _ctx);
}
 
// monadic lift

kk_std_core_types__maybe kk_std_text_parse__mlift2561_parse(kk_box_t x, kk_unit_t wild__0, kk_context_t* _ctx) { /* forall<_h,a,h1,e> (x : a, wild_0 : ()) -> <local<h1>,local<_h>|e> maybe<a> */ 
  return kk_std_core_types__new_Just(x, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_text_parse__mlift2562_parse_fun4986__t {
  struct kk_function_s _base;
  kk_box_t x;
};
static kk_box_t kk_std_text_parse__mlift2562_parse_fun4986(kk_function_t _fself, kk_box_t _b_3823, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse__new_mlift2562_parse_fun4986(kk_box_t x, kk_context_t* _ctx) {
  struct kk_std_text_parse__mlift2562_parse_fun4986__t* _self = kk_function_alloc_as(struct kk_std_text_parse__mlift2562_parse_fun4986__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_text_parse__mlift2562_parse_fun4986, kk_context());
  _self->x = x;
  return &_self->_base;
}

static kk_box_t kk_std_text_parse__mlift2562_parse_fun4986(kk_function_t _fself, kk_box_t _b_3823, kk_context_t* _ctx) {
  struct kk_std_text_parse__mlift2562_parse_fun4986__t* _self = kk_function_as(struct kk_std_text_parse__mlift2562_parse_fun4986__t*, _fself);
  kk_box_t x = _self->x; /* 2232 */
  kk_drop_match(_self, {kk_box_dup(x);}, {}, _ctx)
  kk_std_core_types__maybe _x4987;
  kk_unit_t _x4988 = kk_Unit;
  kk_unit_unbox(_b_3823);
  _x4987 = kk_std_text_parse__mlift2561_parse(x, _x4988, _ctx); /*maybe<2232>*/
  return kk_std_core_types__maybe_box(_x4987, _ctx);
}

kk_std_core_types__maybe kk_std_text_parse__mlift2562_parse(kk_ref_t input, kk_function_t pred, kk_std_core__sslice inp, kk_context_t* _ctx) { /* forall<_h,a,h1,e> (input : local-var<h1,sslice>, pred : (sslice) -> total maybe<(a, sslice)>, inp : sslice) -> <local<h1>,local<_h>|e> maybe<a> */ 
  kk_std_core_types__maybe _match_4372 = kk_function_call(kk_std_core_types__maybe, (kk_function_t, kk_std_core__sslice, kk_context_t*), pred, (pred, inp, _ctx)); /*maybe<(2232, sslice)>*/;
  if (kk_std_core_types__is_Just(_match_4372)) {
    kk_box_t _box_x3816 = _match_4372._cons.Just.value;
    kk_std_core_types__tuple2_ _pat9 = kk_std_core_types__tuple2__unbox(_box_x3816, NULL);
    kk_box_t x = _pat9.fst;
    kk_box_t _box_x3817 = _pat9.snd;
    kk_std_core__sslice cap = kk_std_core__sslice_unbox(_box_x3817, NULL);
    kk_std_core__sslice_dup(cap);
    kk_box_dup(x);
    kk_std_core_types__maybe_drop(_match_4372, _ctx);
    kk_unit_t x0_2767 = kk_Unit;
    (kk_ref_set(input,(kk_std_core__sslice_box(cap, _ctx)),kk_context()));
    if (kk_yielding(kk_context())) {
      kk_box_t _x4985 = kk_std_core_hnd_yield_extend(kk_std_text_parse__new_mlift2562_parse_fun4986(x, _ctx), _ctx); /*3991*/
      return kk_std_core_types__maybe_unbox(_x4985, _ctx);
    }
    return kk_std_text_parse__mlift2561_parse(x, x0_2767, _ctx);
  }
  kk_ref_drop(input, _ctx);
  return kk_std_core_types__new_Nothing(_ctx);
}
 
// monadic lift

kk_std_text_parse__parse_error kk_std_text_parse__mlift2563_parse(kk_box_t x0, kk_std_core__sslice _y_58, kk_context_t* _ctx) { /* forall<_h,h1,a,e> (x0 : a, sslice) -> <local<h1>,local<_h>|e> parse-error<a> */ 
  return kk_std_text_parse__new_ParseOk(kk_reuse_null, x0, _y_58, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_parse_fun4991__t {
  struct kk_function_s _base;
  kk_ref_t loc;
};
static kk_box_t kk_std_text_parse_parse_fun4991(kk_function_t _fself, kk_std_core_hnd__marker _b_3830, kk_std_core_hnd__ev _b_3831, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_parse_fun4991(kk_ref_t loc, kk_context_t* _ctx) {
  struct kk_std_text_parse_parse_fun4991__t* _self = kk_function_alloc_as(struct kk_std_text_parse_parse_fun4991__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_text_parse_parse_fun4991, kk_context());
  _self->loc = loc;
  return &_self->_base;
}

static kk_box_t kk_std_text_parse_parse_fun4991(kk_function_t _fself, kk_std_core_hnd__marker _b_3830, kk_std_core_hnd__ev _b_3831, kk_context_t* _ctx) {
  struct kk_std_text_parse_parse_fun4991__t* _self = kk_function_as(struct kk_std_text_parse_parse_fun4991__t*, _fself);
  kk_ref_t loc = _self->loc; /* local-var<global,sslice> */
  kk_drop_match(_self, {kk_ref_dup(loc);}, {}, _ctx)
  kk_std_core_hnd__ev_dropn(_b_3831, ((int32_t)3), _ctx);
  return (kk_ref_get(loc,kk_context()));
}


// lift anonymous function
struct kk_std_text_parse_parse_fun4994__t {
  struct kk_function_s _base;
  kk_ref_t loc;
};
static kk_box_t kk_std_text_parse_parse_fun4994(kk_function_t _fself, kk_std_core_hnd__marker _b_3855, kk_std_core_hnd__ev _b_3856, kk_box_t _b_3857, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_parse_fun4994(kk_ref_t loc, kk_context_t* _ctx) {
  struct kk_std_text_parse_parse_fun4994__t* _self = kk_function_alloc_as(struct kk_std_text_parse_parse_fun4994__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_text_parse_parse_fun4994, kk_context());
  _self->loc = loc;
  return &_self->_base;
}



// lift anonymous function
struct kk_std_text_parse_parse_fun4995__t {
  struct kk_function_s _base;
  kk_box_t _b_3857;
  kk_ref_t loc;
};
static kk_box_t kk_std_text_parse_parse_fun4995(kk_function_t _fself, kk_function_t _b_3852, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_parse_fun4995(kk_box_t _b_3857, kk_ref_t loc, kk_context_t* _ctx) {
  struct kk_std_text_parse_parse_fun4995__t* _self = kk_function_alloc_as(struct kk_std_text_parse_parse_fun4995__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_text_parse_parse_fun4995, kk_context());
  _self->_b_3857 = _b_3857;
  _self->loc = loc;
  return &_self->_base;
}



// lift anonymous function
struct kk_std_text_parse_parse_fun4997__t {
  struct kk_function_s _base;
  kk_function_t _b_3852;
};
static kk_std_text_parse__parse_error kk_std_text_parse_parse_fun4997(kk_function_t _fself, kk_function_t _b_3853, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_parse_fun4997(kk_function_t _b_3852, kk_context_t* _ctx) {
  struct kk_std_text_parse_parse_fun4997__t* _self = kk_function_alloc_as(struct kk_std_text_parse_parse_fun4997__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_text_parse_parse_fun4997, kk_context());
  _self->_b_3852 = _b_3852;
  return &_self->_base;
}

static kk_std_text_parse__parse_error kk_std_text_parse_parse_fun4997(kk_function_t _fself, kk_function_t _b_3853, kk_context_t* _ctx) {
  struct kk_std_text_parse_parse_fun4997__t* _self = kk_function_as(struct kk_std_text_parse_parse_fun4997__t*, _fself);
  kk_function_t _b_3852 = _self->_b_3852; /* (() -> 6146) -> 6147 6148 */
  kk_drop_match(_self, {kk_function_dup(_b_3852);}, {}, _ctx)
  kk_box_t _x4998 = kk_function_call(kk_box_t, (kk_function_t, kk_function_t, kk_context_t*), _b_3852, (_b_3852, _b_3853, _ctx)); /*6148*/
  return kk_std_text_parse__parse_error_unbox(_x4998, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_parse_fun5001__t {
  struct kk_function_s _base;
  kk_box_t _b_3857;
};
static kk_box_t kk_std_text_parse_parse_fun5001(kk_function_t _fself, kk_box_t _b_3837, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_parse_fun5001(kk_box_t _b_3857, kk_context_t* _ctx) {
  struct kk_std_text_parse_parse_fun5001__t* _self = kk_function_alloc_as(struct kk_std_text_parse_parse_fun5001__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_text_parse_parse_fun5001, kk_context());
  _self->_b_3857 = _b_3857;
  return &_self->_base;
}

static kk_box_t kk_std_text_parse_parse_fun5001(kk_function_t _fself, kk_box_t _b_3837, kk_context_t* _ctx) {
  struct kk_std_text_parse_parse_fun5001__t* _self = kk_function_as(struct kk_std_text_parse_parse_fun5001__t*, _fself);
  kk_box_t _b_3857 = _self->_b_3857; /* 52 */
  kk_drop_match(_self, {kk_box_dup(_b_3857);}, {}, _ctx)
  kk_std_text_parse__parse_error _x5002;
  kk_string_t _x5003 = kk_string_unbox(_b_3857); /*string*/
  kk_std_core__sslice _x5004 = kk_std_core__sslice_unbox(_b_3837, _ctx); /*sslice*/
  _x5002 = kk_std_text_parse__mlift2556_parse(_x5003, _x5004, _ctx); /*std/text/parse/parse-error<2282>*/
  return kk_std_text_parse__parse_error_box(_x5002, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_parse_fun5007__t {
  struct kk_function_s _base;
  kk_function_t k_3899;
  kk_ref_t resumed;
};
static kk_box_t kk_std_text_parse_parse_fun5007(kk_function_t _fself, kk_box_t _b_3845, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_parse_fun5007(kk_function_t k_3899, kk_ref_t resumed, kk_context_t* _ctx) {
  struct kk_std_text_parse_parse_fun5007__t* _self = kk_function_alloc_as(struct kk_std_text_parse_parse_fun5007__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_text_parse_parse_fun5007, kk_context());
  _self->k_3899 = k_3899;
  _self->resumed = resumed;
  return &_self->_base;
}



// lift anonymous function
struct kk_std_text_parse_parse_fun5008__t {
  struct kk_function_s _base;
  kk_function_t k_3899;
};
static kk_box_t kk_std_text_parse_parse_fun5008(kk_function_t _fself, kk_function_t _b_3843, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_parse_fun5008(kk_function_t k_3899, kk_context_t* _ctx) {
  struct kk_std_text_parse_parse_fun5008__t* _self = kk_function_alloc_as(struct kk_std_text_parse_parse_fun5008__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_text_parse_parse_fun5008, kk_context());
  _self->k_3899 = k_3899;
  return &_self->_base;
}

static kk_box_t kk_std_text_parse_parse_fun5008(kk_function_t _fself, kk_function_t _b_3843, kk_context_t* _ctx) {
  struct kk_std_text_parse_parse_fun5008__t* _self = kk_function_as(struct kk_std_text_parse_parse_fun5008__t*, _fself);
  kk_function_t k_3899 = _self->k_3899; /* (() -> 2123) -> <local<global>,local<_253>|2283> std/text/parse/parse-error<2282> */
  kk_drop_match(_self, {kk_function_dup(k_3899);}, {}, _ctx)
  kk_std_text_parse__parse_error _x5009 = kk_function_call(kk_std_text_parse__parse_error, (kk_function_t, kk_function_t, kk_context_t*), k_3899, (k_3899, _b_3843, _ctx)); /*std/text/parse/parse-error<2282>*/
  return kk_std_text_parse__parse_error_box(_x5009, _ctx);
}
static kk_box_t kk_std_text_parse_parse_fun5007(kk_function_t _fself, kk_box_t _b_3845, kk_context_t* _ctx) {
  struct kk_std_text_parse_parse_fun5007__t* _self = kk_function_as(struct kk_std_text_parse_parse_fun5007__t*, _fself);
  kk_function_t k_3899 = _self->k_3899; /* (() -> 2123) -> <local<global>,local<_253>|2283> std/text/parse/parse-error<2282> */
  kk_ref_t resumed = _self->resumed; /* ref<global,bool> */
  kk_drop_match(_self, {kk_function_dup(k_3899);kk_ref_dup(resumed);}, {}, _ctx)
  return kk_std_core_hnd_protect_check(resumed, kk_std_text_parse_new_parse_fun5008(k_3899, _ctx), _b_3845, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_parse_fun5010__t {
  struct kk_function_s _base;
  kk_function_t k_3899;
};
static kk_box_t kk_std_text_parse_parse_fun5010(kk_function_t _fself, kk_function_t _b_3849, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_parse_fun5010(kk_function_t k_3899, kk_context_t* _ctx) {
  struct kk_std_text_parse_parse_fun5010__t* _self = kk_function_alloc_as(struct kk_std_text_parse_parse_fun5010__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_text_parse_parse_fun5010, kk_context());
  _self->k_3899 = k_3899;
  return &_self->_base;
}

static kk_box_t kk_std_text_parse_parse_fun5010(kk_function_t _fself, kk_function_t _b_3849, kk_context_t* _ctx) {
  struct kk_std_text_parse_parse_fun5010__t* _self = kk_function_as(struct kk_std_text_parse_parse_fun5010__t*, _fself);
  kk_function_t k_3899 = _self->k_3899; /* (() -> 2123) -> <local<global>,local<_253>|2283> std/text/parse/parse-error<2282> */
  kk_drop_match(_self, {kk_function_dup(k_3899);}, {}, _ctx)
  kk_std_text_parse__parse_error _x5011 = kk_function_call(kk_std_text_parse__parse_error, (kk_function_t, kk_function_t, kk_context_t*), k_3899, (k_3899, _b_3849, _ctx)); /*std/text/parse/parse-error<2282>*/
  return kk_std_text_parse__parse_error_box(_x5011, _ctx);
}
static kk_box_t kk_std_text_parse_parse_fun4995(kk_function_t _fself, kk_function_t _b_3852, kk_context_t* _ctx) {
  struct kk_std_text_parse_parse_fun4995__t* _self = kk_function_as(struct kk_std_text_parse_parse_fun4995__t*, _fself);
  kk_box_t _b_3857 = _self->_b_3857; /* 52 */
  kk_ref_t loc = _self->loc; /* local-var<global,sslice> */
  kk_drop_match(_self, {kk_box_dup(_b_3857);kk_ref_dup(loc);}, {}, _ctx)
  kk_std_text_parse__parse_error _x4996;
  kk_function_t k_3899 = kk_std_text_parse_new_parse_fun4997(_b_3852, _ctx); /*(() -> 2123) -> <local<global>,local<_253>|2283> std/text/parse/parse-error<2282>*/;
  kk_ref_t resumed = kk_ref_alloc((kk_bool_box(false)),kk_context()); /*ref<global,bool>*/;
  kk_std_text_parse__parse_error res;
  kk_std_core__sslice x0_2775;
  kk_box_t _x4999 = (kk_ref_get(loc,kk_context())); /*228*/
  x0_2775 = kk_std_core__sslice_unbox(_x4999, _ctx); /*sslice*/
  if (kk_yielding(kk_context())) {
    kk_std_core__sslice_drop(x0_2775, _ctx);
    kk_box_t _x5000 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_parse_fun5001(_b_3857, _ctx), _ctx); /*3991*/
    res = kk_std_text_parse__parse_error_unbox(_x5000, _ctx); /*std/text/parse/parse-error<2282>*/
  }
  else {
    kk_string_t _x5005 = kk_string_unbox(_b_3857); /*string*/
    res = kk_std_text_parse__mlift2556_parse(_x5005, x0_2775, _ctx); /*std/text/parse/parse-error<2282>*/
  }
  kk_box_t _x5006;
  if (kk_yielding(kk_context())) {
    kk_std_text_parse__parse_error_drop(res, _ctx);
    _x5006 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_parse_fun5007(k_3899, resumed, _ctx), _ctx); /*3991*/
  }
  else {
    _x5006 = kk_std_core_hnd_protect_check(resumed, kk_std_text_parse_new_parse_fun5010(k_3899, _ctx), kk_std_text_parse__parse_error_box(res, _ctx), _ctx); /*3991*/
  }
  _x4996 = kk_std_text_parse__parse_error_unbox(_x5006, _ctx); /*std/text/parse/parse-error<2282>*/
  return kk_std_text_parse__parse_error_box(_x4996, _ctx);
}
static kk_box_t kk_std_text_parse_parse_fun4994(kk_function_t _fself, kk_std_core_hnd__marker _b_3855, kk_std_core_hnd__ev _b_3856, kk_box_t _b_3857, kk_context_t* _ctx) {
  struct kk_std_text_parse_parse_fun4994__t* _self = kk_function_as(struct kk_std_text_parse_parse_fun4994__t*, _fself);
  kk_ref_t loc = _self->loc; /* local-var<global,sslice> */
  kk_drop_match(_self, {kk_ref_dup(loc);}, {}, _ctx)
  kk_std_core_hnd__ev_dropn(_b_3856, ((int32_t)3), _ctx);
  return kk_std_core_hnd_yield_to(_b_3855, kk_std_text_parse_new_parse_fun4995(_b_3857, loc, _ctx), _ctx);
}


// lift anonymous function
struct kk_std_text_parse_parse_fun5014__t {
  struct kk_function_s _base;
  kk_ref_t loc;
};
static kk_box_t kk_std_text_parse_parse_fun5014(kk_function_t _fself, kk_function_t _b_3863, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_parse_fun5014(kk_ref_t loc, kk_context_t* _ctx) {
  struct kk_std_text_parse_parse_fun5014__t* _self = kk_function_alloc_as(struct kk_std_text_parse_parse_fun5014__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_text_parse_parse_fun5014, kk_context());
  _self->loc = loc;
  return &_self->_base;
}



// lift anonymous function
struct kk_std_text_parse_parse_fun5016__t {
  struct kk_function_s _base;
  kk_function_t _b_3863;
};
static kk_std_text_parse__parse_error kk_std_text_parse_parse_fun5016(kk_function_t _fself, bool _b_3864, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_parse_fun5016(kk_function_t _b_3863, kk_context_t* _ctx) {
  struct kk_std_text_parse_parse_fun5016__t* _self = kk_function_alloc_as(struct kk_std_text_parse_parse_fun5016__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_text_parse_parse_fun5016, kk_context());
  _self->_b_3863 = _b_3863;
  return &_self->_base;
}

static kk_std_text_parse__parse_error kk_std_text_parse_parse_fun5016(kk_function_t _fself, bool _b_3864, kk_context_t* _ctx) {
  struct kk_std_text_parse_parse_fun5016__t* _self = kk_function_as(struct kk_std_text_parse_parse_fun5016__t*, _fself);
  kk_function_t _b_3863 = _self->_b_3863; /* (7164) -> 7165 7167 */
  kk_drop_match(_self, {kk_function_dup(_b_3863);}, {}, _ctx)
  kk_box_t _x5017 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _b_3863, (_b_3863, kk_bool_box(_b_3864), _ctx)); /*7167*/
  return kk_std_text_parse__parse_error_unbox(_x5017, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_parse_fun5021__t {
  struct kk_function_s _base;
  kk_ref_t loc;
  kk_function_t resume0_3909;
};
static kk_box_t kk_std_text_parse_parse_fun5021(kk_function_t _fself, kk_box_t _b_3861, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_parse_fun5021(kk_ref_t loc, kk_function_t resume0_3909, kk_context_t* _ctx) {
  struct kk_std_text_parse_parse_fun5021__t* _self = kk_function_alloc_as(struct kk_std_text_parse_parse_fun5021__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_text_parse_parse_fun5021, kk_context());
  _self->loc = loc;
  _self->resume0_3909 = resume0_3909;
  return &_self->_base;
}

static kk_box_t kk_std_text_parse_parse_fun5021(kk_function_t _fself, kk_box_t _b_3861, kk_context_t* _ctx) {
  struct kk_std_text_parse_parse_fun5021__t* _self = kk_function_as(struct kk_std_text_parse_parse_fun5021__t*, _fself);
  kk_ref_t loc = _self->loc; /* local-var<global,sslice> */
  kk_function_t resume0_3909 = _self->resume0_3909; /* (bool) -> <local<global>,local<_253>|2283> std/text/parse/parse-error<2282> */
  kk_drop_match(_self, {kk_ref_dup(loc);kk_function_dup(resume0_3909);}, {}, _ctx)
  kk_std_text_parse__parse_error _x5022;
  kk_std_core__sslice _x5023 = kk_std_core__sslice_unbox(_b_3861, _ctx); /*sslice*/
  _x5022 = kk_std_text_parse__mlift2560_parse(loc, resume0_3909, _x5023, _ctx); /*std/text/parse/parse-error<2282>*/
  return kk_std_text_parse__parse_error_box(_x5022, _ctx);
}
static kk_box_t kk_std_text_parse_parse_fun5014(kk_function_t _fself, kk_function_t _b_3863, kk_context_t* _ctx) {
  struct kk_std_text_parse_parse_fun5014__t* _self = kk_function_as(struct kk_std_text_parse_parse_fun5014__t*, _fself);
  kk_ref_t loc = _self->loc; /* local-var<global,sslice> */
  kk_drop_match(_self, {kk_ref_dup(loc);}, {}, _ctx)
  kk_std_text_parse__parse_error _x5015;
  kk_function_t resume0_3909 = kk_std_text_parse_new_parse_fun5016(_b_3863, _ctx); /*(bool) -> <local<global>,local<_253>|2283> std/text/parse/parse-error<2282>*/;
  kk_std_core__sslice x1_2777;
  kk_box_t _x5018;
  kk_ref_t _x5019 = kk_ref_dup(loc); /*local-var<global,sslice>*/
  _x5018 = (kk_ref_get(_x5019,kk_context())); /*228*/
  x1_2777 = kk_std_core__sslice_unbox(_x5018, _ctx); /*sslice*/
  if (kk_yielding(kk_context())) {
    kk_std_core__sslice_drop(x1_2777, _ctx);
    kk_box_t _x5020 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_parse_fun5021(loc, resume0_3909, _ctx), _ctx); /*3991*/
    _x5015 = kk_std_text_parse__parse_error_unbox(_x5020, _ctx); /*std/text/parse/parse-error<2282>*/
  }
  else {
    _x5015 = kk_std_text_parse__mlift2560_parse(loc, resume0_3909, x1_2777, _ctx); /*std/text/parse/parse-error<2282>*/
  }
  return kk_std_text_parse__parse_error_box(_x5015, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_parse_fun5026__t {
  struct kk_function_s _base;
  kk_ref_t loc;
};
static kk_box_t kk_std_text_parse_parse_fun5026(kk_function_t _fself, kk_std_core_hnd__marker _b_3870, kk_std_core_hnd__ev _b_3871, kk_box_t _b_3872, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_parse_fun5026(kk_ref_t loc, kk_context_t* _ctx) {
  struct kk_std_text_parse_parse_fun5026__t* _self = kk_function_alloc_as(struct kk_std_text_parse_parse_fun5026__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_text_parse_parse_fun5026, kk_context());
  _self->loc = loc;
  return &_self->_base;
}



// lift anonymous function
struct kk_std_text_parse_parse_fun5028__t {
  struct kk_function_s _base;
  kk_box_t _b_3872;
};
static kk_std_core_types__maybe kk_std_text_parse_parse_fun5028(kk_function_t _fself, kk_std_core__sslice _b_3875, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_parse_fun5028(kk_box_t _b_3872, kk_context_t* _ctx) {
  struct kk_std_text_parse_parse_fun5028__t* _self = kk_function_alloc_as(struct kk_std_text_parse_parse_fun5028__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_text_parse_parse_fun5028, kk_context());
  _self->_b_3872 = _b_3872;
  return &_self->_base;
}

static kk_std_core_types__maybe kk_std_text_parse_parse_fun5028(kk_function_t _fself, kk_std_core__sslice _b_3875, kk_context_t* _ctx) {
  struct kk_std_text_parse_parse_fun5028__t* _self = kk_function_as(struct kk_std_text_parse_parse_fun5028__t*, _fself);
  kk_box_t _b_3872 = _self->_b_3872; /* 52 */
  kk_drop_match(_self, {kk_box_dup(_b_3872);}, {}, _ctx)
  kk_box_t _x5029;
  kk_function_t _x5030 = kk_function_unbox(_b_3872); /*(3873) -> total 3874*/
  _x5029 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x5030, (_x5030, kk_std_core__sslice_box(_b_3875, _ctx), _ctx)); /*3874*/
  return kk_std_core_types__maybe_unbox(_x5029, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_parse_fun5034__t {
  struct kk_function_s _base;
  kk_ref_t loc;
  kk_function_t x2_3915;
};
static kk_box_t kk_std_text_parse_parse_fun5034(kk_function_t _fself, kk_box_t _b_3868, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_parse_fun5034(kk_ref_t loc, kk_function_t x2_3915, kk_context_t* _ctx) {
  struct kk_std_text_parse_parse_fun5034__t* _self = kk_function_alloc_as(struct kk_std_text_parse_parse_fun5034__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_text_parse_parse_fun5034, kk_context());
  _self->loc = loc;
  _self->x2_3915 = x2_3915;
  return &_self->_base;
}

static kk_box_t kk_std_text_parse_parse_fun5034(kk_function_t _fself, kk_box_t _b_3868, kk_context_t* _ctx) {
  struct kk_std_text_parse_parse_fun5034__t* _self = kk_function_as(struct kk_std_text_parse_parse_fun5034__t*, _fself);
  kk_ref_t loc = _self->loc; /* local-var<global,sslice> */
  kk_function_t x2_3915 = _self->x2_3915; /* (sslice) -> total maybe<(2232, sslice)> */
  kk_drop_match(_self, {kk_ref_dup(loc);kk_function_dup(x2_3915);}, {}, _ctx)
  kk_std_core_types__maybe _x5035;
  kk_std_core__sslice _x5036 = kk_std_core__sslice_unbox(_b_3868, _ctx); /*sslice*/
  _x5035 = kk_std_text_parse__mlift2562_parse(loc, x2_3915, _x5036, _ctx); /*maybe<2232>*/
  return kk_std_core_types__maybe_box(_x5035, _ctx);
}
static kk_box_t kk_std_text_parse_parse_fun5026(kk_function_t _fself, kk_std_core_hnd__marker _b_3870, kk_std_core_hnd__ev _b_3871, kk_box_t _b_3872, kk_context_t* _ctx) {
  struct kk_std_text_parse_parse_fun5026__t* _self = kk_function_as(struct kk_std_text_parse_parse_fun5026__t*, _fself);
  kk_ref_t loc = _self->loc; /* local-var<global,sslice> */
  kk_drop_match(_self, {kk_ref_dup(loc);}, {}, _ctx)
  kk_std_core_hnd__ev_dropn(_b_3871, ((int32_t)3), _ctx);
  kk_std_core_types__maybe _x5027;
  kk_function_t x2_3915 = kk_std_text_parse_new_parse_fun5028(_b_3872, _ctx); /*(sslice) -> total maybe<(2232, sslice)>*/;
  kk_std_core__sslice x3_2781;
  kk_box_t _x5031;
  kk_ref_t _x5032 = kk_ref_dup(loc); /*local-var<global,sslice>*/
  _x5031 = (kk_ref_get(_x5032,kk_context())); /*228*/
  x3_2781 = kk_std_core__sslice_unbox(_x5031, _ctx); /*sslice*/
  if (kk_yielding(kk_context())) {
    kk_std_core__sslice_drop(x3_2781, _ctx);
    kk_box_t _x5033 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_parse_fun5034(loc, x2_3915, _ctx), _ctx); /*3991*/
    _x5027 = kk_std_core_types__maybe_unbox(_x5033, _ctx); /*maybe<2232>*/
  }
  else {
    _x5027 = kk_std_text_parse__mlift2562_parse(loc, x2_3915, x3_2781, _ctx); /*maybe<2232>*/
  }
  return kk_std_core_types__maybe_box(_x5027, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_parse_fun5039__t {
  struct kk_function_s _base;
  kk_ref_t loc;
};
static kk_box_t kk_std_text_parse_parse_fun5039(kk_function_t _fself, kk_box_t _b_3884, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_parse_fun5039(kk_ref_t loc, kk_context_t* _ctx) {
  struct kk_std_text_parse_parse_fun5039__t* _self = kk_function_alloc_as(struct kk_std_text_parse_parse_fun5039__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_text_parse_parse_fun5039, kk_context());
  _self->loc = loc;
  return &_self->_base;
}



// lift anonymous function
struct kk_std_text_parse_parse_fun5043__t {
  struct kk_function_s _base;
  kk_box_t _b_3884;
};
static kk_box_t kk_std_text_parse_parse_fun5043(kk_function_t _fself, kk_box_t _b_3879, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_parse_fun5043(kk_box_t _b_3884, kk_context_t* _ctx) {
  struct kk_std_text_parse_parse_fun5043__t* _self = kk_function_alloc_as(struct kk_std_text_parse_parse_fun5043__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_text_parse_parse_fun5043, kk_context());
  _self->_b_3884 = _b_3884;
  return &_self->_base;
}

static kk_box_t kk_std_text_parse_parse_fun5043(kk_function_t _fself, kk_box_t _b_3879, kk_context_t* _ctx) {
  struct kk_std_text_parse_parse_fun5043__t* _self = kk_function_as(struct kk_std_text_parse_parse_fun5043__t*, _fself);
  kk_box_t _b_3884 = _self->_b_3884; /* 360 */
  kk_drop_match(_self, {kk_box_dup(_b_3884);}, {}, _ctx)
  kk_std_text_parse__parse_error _x5044;
  kk_std_core__sslice _x5045 = kk_std_core__sslice_unbox(_b_3879, _ctx); /*sslice*/
  _x5044 = kk_std_text_parse__mlift2563_parse(_b_3884, _x5045, _ctx); /*std/text/parse/parse-error<2282>*/
  return kk_std_text_parse__parse_error_box(_x5044, _ctx);
}
static kk_box_t kk_std_text_parse_parse_fun5039(kk_function_t _fself, kk_box_t _b_3884, kk_context_t* _ctx) {
  struct kk_std_text_parse_parse_fun5039__t* _self = kk_function_as(struct kk_std_text_parse_parse_fun5039__t*, _fself);
  kk_ref_t loc = _self->loc; /* local-var<global,sslice> */
  kk_drop_match(_self, {kk_ref_dup(loc);}, {}, _ctx)
  kk_std_text_parse__parse_error _x5040;
  kk_std_core__sslice x4_2783;
  kk_box_t _x5041 = (kk_ref_get(loc,kk_context())); /*228*/
  x4_2783 = kk_std_core__sslice_unbox(_x5041, _ctx); /*sslice*/
  if (kk_yielding(kk_context())) {
    kk_std_core__sslice_drop(x4_2783, _ctx);
    kk_box_t _x5042 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_parse_fun5043(_b_3884, _ctx), _ctx); /*3991*/
    _x5040 = kk_std_text_parse__parse_error_unbox(_x5042, _ctx); /*std/text/parse/parse-error<2282>*/
  }
  else {
    _x5040 = kk_std_text_parse__mlift2563_parse(_b_3884, x4_2783, _ctx); /*std/text/parse/parse-error<2282>*/
  }
  return kk_std_text_parse__parse_error_box(_x5040, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_parse_fun5046__t {
  struct kk_function_s _base;
  kk_function_t p;
};
static kk_box_t kk_std_text_parse_parse_fun5046(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_parse_fun5046(kk_function_t p, kk_context_t* _ctx) {
  struct kk_std_text_parse_parse_fun5046__t* _self = kk_function_alloc_as(struct kk_std_text_parse_parse_fun5046__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_text_parse_parse_fun5046, kk_context());
  _self->p = p;
  return &_self->_base;
}

static kk_box_t kk_std_text_parse_parse_fun5046(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_text_parse_parse_fun5046__t* _self = kk_function_as(struct kk_std_text_parse_parse_fun5046__t*, _fself);
  kk_function_t p = _self->p; /* () -> <std/text/parse/parse|2283> 2282 */
  kk_drop_match(_self, {kk_function_dup(p);}, {}, _ctx)
  return kk_std_core_hnd__mask_builtin(p, _ctx);
}

kk_std_text_parse__parse_error kk_std_text_parse_parse(kk_std_core__sslice input0, kk_function_t p, kk_context_t* _ctx) { /* forall<a,e> (input0 : sslice, p : () -> <parse|e> a) -> e parse-error<a> */ 
  kk_ref_t loc = kk_ref_alloc((kk_std_core__sslice_box(input0, _ctx)),kk_context()); /*local-var<global,sslice>*/;
  kk_std_text_parse__parse_error res0;
  int32_t _b_3885_3880 = ((int32_t)3); /*int32*/;
  kk_std_text_parse__hnd_parse _b_3886_3881;
  kk_std_core_hnd__clause0 _x4989;
  kk_function_t _x4990;
  kk_ref_dup(loc);
  _x4990 = kk_std_text_parse_new_parse_fun4991(loc, _ctx); /*(std/core/hnd/marker<39,40>, std/core/hnd/ev<38>) -> 39 228*/
  _x4989 = kk_std_core_hnd__new_Clause0(_x4990, _ctx); /*std/core/hnd/clause0<37,38,39,40>*/
  kk_std_core_hnd__clause1 _x4992;
  kk_function_t _x4993;
  kk_ref_dup(loc);
  _x4993 = kk_std_text_parse_new_parse_fun4994(loc, _ctx); /*(std/core/hnd/marker<55,56>, std/core/hnd/ev<54>, 52) -> 55 6146*/
  _x4992 = kk_std_core_hnd__new_Clause1(_x4993, _ctx); /*std/core/hnd/clause1<52,53,54,55,56>*/
  kk_std_core_hnd__clause0 _x5012;
  kk_function_t _x5013;
  kk_ref_dup(loc);
  _x5013 = kk_std_text_parse_new_parse_fun5014(loc, _ctx); /*((7164) -> 7165 7167) -> 7165 7167*/
  _x5012 = kk_std_core_hnd_clause_control0(_x5013, _ctx); /*std/core/hnd/clause0<7164,7166,7165,7167>*/
  kk_std_core_hnd__clause1 _x5024;
  kk_function_t _x5025;
  kk_ref_dup(loc);
  _x5025 = kk_std_text_parse_new_parse_fun5026(loc, _ctx); /*(std/core/hnd/marker<55,56>, std/core/hnd/ev<54>, 52) -> 55 53*/
  _x5024 = kk_std_core_hnd__new_Clause1(_x5025, _ctx); /*std/core/hnd/clause1<52,53,54,55,56>*/
  _b_3886_3881 = kk_std_text_parse__new_Hnd_parse(kk_reuse_null, _x4989, _x4992, _x5012, _x5024, _ctx); /*std/text/parse/.hnd-parse<<local<global>,local<_253>|2283>,std/text/parse/parse-error<2282>>*/
  kk_box_t _x5037;
  kk_function_t _x5038;
  kk_ref_dup(loc);
  _x5038 = kk_std_text_parse_new_parse_fun5039(loc, _ctx); /*(360) -> 361 362*/
  _x5037 = kk_std_text_parse__handle_parse(_b_3885_3880, _b_3886_3881, _x5038, kk_std_text_parse_new_parse_fun5046(p, _ctx), _ctx); /*362*/
  res0 = kk_std_text_parse__parse_error_unbox(_x5037, _ctx); /*std/text/parse/parse-error<2282>*/
  kk_box_t _x5047 = kk_std_core_hnd_prompt_local_var(loc, kk_std_text_parse__parse_error_box(res0, _ctx), _ctx); /*9788*/
  return kk_std_text_parse__parse_error_unbox(_x5047, _ctx);
}
 
// monadic lift

kk_box_t kk_std_text_parse__mlift2564_parse_eof(kk_box_t x, kk_unit_t wild__, kk_context_t* _ctx) { /* forall<a,e> (x : a, wild_ : ()) -> <parse|e> a */ 
  return x;
}
 
// monadic lift


// lift anonymous function
struct kk_std_text_parse__mlift2565_parse_eof_fun5050__t {
  struct kk_function_s _base;
  size_t i_2788;
};
static kk_box_t kk_std_text_parse__mlift2565_parse_eof_fun5050(kk_function_t _fself, kk_function_t _b_3930, kk_box_t _b_3931, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse__new_mlift2565_parse_eof_fun5050(size_t i_2788, kk_context_t* _ctx) {
  struct kk_std_text_parse__mlift2565_parse_eof_fun5050__t* _self = kk_function_alloc_as(struct kk_std_text_parse__mlift2565_parse_eof_fun5050__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_text_parse__mlift2565_parse_eof_fun5050, kk_context());
  _self->i_2788 = i_2788;
  return &_self->_base;
}

static kk_box_t kk_std_text_parse__mlift2565_parse_eof_fun5050(kk_function_t _fself, kk_function_t _b_3930, kk_box_t _b_3931, kk_context_t* _ctx) {
  struct kk_std_text_parse__mlift2565_parse_eof_fun5050__t* _self = kk_function_as(struct kk_std_text_parse__mlift2565_parse_eof_fun5050__t*, _fself);
  size_t i_2788 = _self->i_2788; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_2788, _b_3930, _b_3931, _ctx);
}


// lift anonymous function
struct kk_std_text_parse__mlift2565_parse_eof_fun5051__t {
  struct kk_function_s _base;
  kk_box_t x;
};
static kk_box_t kk_std_text_parse__mlift2565_parse_eof_fun5051(kk_function_t _fself, kk_box_t _b_3941, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse__new_mlift2565_parse_eof_fun5051(kk_box_t x, kk_context_t* _ctx) {
  struct kk_std_text_parse__mlift2565_parse_eof_fun5051__t* _self = kk_function_alloc_as(struct kk_std_text_parse__mlift2565_parse_eof_fun5051__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_text_parse__mlift2565_parse_eof_fun5051, kk_context());
  _self->x = x;
  return &_self->_base;
}

static kk_box_t kk_std_text_parse__mlift2565_parse_eof_fun5051(kk_function_t _fself, kk_box_t _b_3941, kk_context_t* _ctx) {
  struct kk_std_text_parse__mlift2565_parse_eof_fun5051__t* _self = kk_function_as(struct kk_std_text_parse__mlift2565_parse_eof_fun5051__t*, _fself);
  kk_box_t x = _self->x; /* 2308 */
  kk_drop_match(_self, {kk_box_dup(x);}, {}, _ctx)
  kk_unit_t _x5052 = kk_Unit;
  kk_unit_unbox(_b_3941);
  return kk_std_text_parse__mlift2564_parse_eof(x, _x5052, _ctx);
}

kk_box_t kk_std_text_parse__mlift2565_parse_eof(kk_box_t x, kk_context_t* _ctx) { /* forall<a,e> (x : a) -> <parse|e> a */ 
  kk_unit_t x0_2786 = kk_Unit;
  size_t i_2788;
  kk_std_core_hnd__htag _x5048 = kk_std_core_hnd__htag_dup(kk_std_text_parse__tag_parse); /*std/core/hnd/htag<std/text/parse/.hnd-parse>*/
  i_2788 = kk_std_core_hnd__evv_index(_x5048, _ctx); /*std/core/hnd/ev-index*/
  kk_evv_t w = kk_evv_swap_create1(i_2788,kk_context()); /*std/core/hnd/evv<<std/text/parse/parse|2309>>*/;
  kk_unit_t y = kk_Unit;
  kk_std_text_parse_eof(_ctx);
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x5049 = kk_std_core_hnd_yield_cont(kk_std_text_parse__new_mlift2565_parse_eof_fun5050(i_2788, _ctx), _ctx); /*3820*/
    kk_unit_unbox(_x5049);
  }
  else {
    y;
  }
  if (kk_yielding(kk_context())) {
    return kk_std_core_hnd_yield_extend(kk_std_text_parse__new_mlift2565_parse_eof_fun5051(x, _ctx), _ctx);
  }
  return kk_std_text_parse__mlift2564_parse_eof(x, x0_2786, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_parse_eof_fun5053__t {
  struct kk_function_s _base;
  kk_function_t p;
};
static kk_box_t kk_std_text_parse_parse_eof_fun5053(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_parse_eof_fun5053(kk_function_t p, kk_context_t* _ctx) {
  struct kk_std_text_parse_parse_eof_fun5053__t* _self = kk_function_alloc_as(struct kk_std_text_parse_parse_eof_fun5053__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_text_parse_parse_eof_fun5053, kk_context());
  _self->p = p;
  return &_self->_base;
}



// lift anonymous function
struct kk_std_text_parse_parse_eof_fun5055__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse_parse_eof_fun5055(kk_function_t _fself, kk_box_t _x15054, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_parse_eof_fun5055(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_parse_eof_fun5055, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_text_parse_parse_eof_fun5055(kk_function_t _fself, kk_box_t _x15054, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return kk_std_text_parse__mlift2565_parse_eof(_x15054, _ctx);
}
static kk_box_t kk_std_text_parse_parse_eof_fun5053(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_text_parse_parse_eof_fun5053__t* _self = kk_function_as(struct kk_std_text_parse_parse_eof_fun5053__t*, _fself);
  kk_function_t p = _self->p; /* () -> <std/text/parse/parse|2309> 2308 */
  kk_drop_match(_self, {kk_function_dup(p);}, {}, _ctx)
  kk_box_t x_2790 = kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), p, (p, _ctx)); /*2308*/;
  if (kk_yielding(kk_context())) {
    kk_box_drop(x_2790, _ctx);
    return kk_std_core_hnd_yield_extend(kk_std_text_parse_new_parse_eof_fun5055(_ctx), _ctx);
  }
  return kk_std_text_parse__mlift2565_parse_eof(x_2790, _ctx);
}

kk_std_text_parse__parse_error kk_std_text_parse_parse_eof(kk_std_core__sslice input, kk_function_t p, kk_context_t* _ctx) { /* forall<a,e> (input : sslice, p : () -> <parse|e> a) -> e parse-error<a> */ 
  return kk_std_text_parse_parse(input, kk_std_text_parse_new_parse_eof_fun5053(p, _ctx), _ctx);
}
 
// monadic lift

kk_integer_t kk_std_text_parse__mlift2566_pnat(kk_string_t _y_67, kk_context_t* _ctx) { /* (string) -> parse int */ 
  kk_std_core_types__optional default_2793 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(0)), _ctx); /*optional<int>*/;
  bool _match_4362;
  kk_string_t _x5056 = kk_string_dup(_y_67); /*string*/
  _match_4362 = kk_std_core_is_empty_2(_x5056, _ctx); /*bool*/
  if (_match_4362) {
    kk_string_drop(_y_67, _ctx);
    if (kk_std_core_types__is_Optional(default_2793)) {
      kk_box_t _box_x3946 = default_2793._cons.Optional.value;
      kk_integer_t _default_19378 = kk_integer_unbox(_box_x3946);
      kk_integer_dup(_default_19378);
      kk_std_core_types__optional_drop(default_2793, _ctx);
      return _default_19378;
    }
    return kk_integer_from_small(0);
  }
  kk_std_core_types__maybe m_21736;
  kk_std_core_types__optional hex0_21739;
  kk_box_t _x5058;
  bool _x5059;
  kk_std_core_types__optional _match_4363 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
  if (kk_std_core_types__is_Optional(_match_4363)) {
    kk_box_t _box_x3947 = _match_4363._cons.Optional.value;
    bool _hex_19382 = kk_bool_unbox(_box_x3947);
    kk_std_core_types__optional_drop(_match_4363, _ctx);
    _x5059 = _hex_19382; /*bool*/
    goto _match5060;
  }
  _x5059 = false; /*bool*/
  _match5060: ;
  _x5058 = kk_bool_box(_x5059); /*108*/
  hex0_21739 = kk_std_core_types__new_Optional(_x5058, _ctx); /*optional<bool>*/
  kk_string_t _x5062 = kk_std_core_trim(_y_67, _ctx); /*string*/
  bool _x5063;
  if (kk_std_core_types__is_Optional(hex0_21739)) {
    kk_box_t _box_x3950 = hex0_21739._cons.Optional.value;
    bool _hex_19366 = kk_bool_unbox(_box_x3950);
    kk_std_core_types__optional_drop(hex0_21739, _ctx);
    _x5063 = _hex_19366; /*bool*/
    goto _match5064;
  }
  _x5063 = false; /*bool*/
  _match5064: ;
  m_21736 = kk_std_core_xparse_int(_x5062, _x5063, _ctx); /*maybe<int>*/
  if (kk_std_core_types__is_Nothing(m_21736)) {
    if (kk_std_core_types__is_Optional(default_2793)) {
      kk_box_t _box_x3951 = default_2793._cons.Optional.value;
      kk_integer_t _default_193780 = kk_integer_unbox(_box_x3951);
      kk_integer_dup(_default_193780);
      kk_std_core_types__optional_drop(default_2793, _ctx);
      return _default_193780;
    }
    return kk_integer_from_small(0);
  }
  kk_box_t _box_x3952 = m_21736._cons.Just.value;
  kk_integer_t x = kk_integer_unbox(_box_x3952);
  kk_integer_dup(x);
  kk_std_core_types__maybe_drop(m_21736, _ctx);
  kk_std_core_types__optional_drop(default_2793, _ctx);
  return x;
}


// lift anonymous function
struct kk_std_text_parse_pnat_fun5069__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse_pnat_fun5069(kk_function_t _fself, kk_box_t _b_3954, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_pnat_fun5069(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_pnat_fun5069, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_text_parse_pnat_fun5069(kk_function_t _fself, kk_box_t _b_3954, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_integer_t _x5070;
  kk_string_t _x5071 = kk_string_unbox(_b_3954); /*string*/
  _x5070 = kk_std_text_parse__mlift2566_pnat(_x5071, _ctx); /*int*/
  return kk_integer_box(_x5070);
}

kk_integer_t kk_std_text_parse_pnat(kk_context_t* _ctx) { /* () -> parse int */ 
  kk_string_t x_2795 = kk_std_text_parse_digits(_ctx); /*string*/;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_2795, _ctx);
    kk_box_t _x5068 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_pnat_fun5069(_ctx), _ctx); /*3991*/
    return kk_integer_unbox(_x5068);
  }
  kk_std_core_types__optional default_2800 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(0)), _ctx); /*optional<int>*/;
  bool _match_4360;
  kk_string_t _x5072 = kk_string_dup(x_2795); /*string*/
  _match_4360 = kk_std_core_is_empty_2(_x5072, _ctx); /*bool*/
  if (_match_4360) {
    kk_string_drop(x_2795, _ctx);
    if (kk_std_core_types__is_Optional(default_2800)) {
      kk_box_t _box_x3957 = default_2800._cons.Optional.value;
      kk_integer_t _default_19378 = kk_integer_unbox(_box_x3957);
      kk_integer_dup(_default_19378);
      kk_std_core_types__optional_drop(default_2800, _ctx);
      return _default_19378;
    }
    return kk_integer_from_small(0);
  }
  kk_std_core_types__maybe m_21736;
  kk_std_core_types__optional hex0_21739;
  kk_box_t _x5074;
  bool _x5075;
  kk_std_core_types__optional _match_4361 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
  if (kk_std_core_types__is_Optional(_match_4361)) {
    kk_box_t _box_x3958 = _match_4361._cons.Optional.value;
    bool _hex_19382 = kk_bool_unbox(_box_x3958);
    kk_std_core_types__optional_drop(_match_4361, _ctx);
    _x5075 = _hex_19382; /*bool*/
    goto _match5076;
  }
  _x5075 = false; /*bool*/
  _match5076: ;
  _x5074 = kk_bool_box(_x5075); /*108*/
  hex0_21739 = kk_std_core_types__new_Optional(_x5074, _ctx); /*optional<bool>*/
  kk_string_t _x5078 = kk_std_core_trim(x_2795, _ctx); /*string*/
  bool _x5079;
  if (kk_std_core_types__is_Optional(hex0_21739)) {
    kk_box_t _box_x3961 = hex0_21739._cons.Optional.value;
    bool _hex_19366 = kk_bool_unbox(_box_x3961);
    kk_std_core_types__optional_drop(hex0_21739, _ctx);
    _x5079 = _hex_19366; /*bool*/
    goto _match5080;
  }
  _x5079 = false; /*bool*/
  _match5080: ;
  m_21736 = kk_std_core_xparse_int(_x5078, _x5079, _ctx); /*maybe<int>*/
  if (kk_std_core_types__is_Nothing(m_21736)) {
    if (kk_std_core_types__is_Optional(default_2800)) {
      kk_box_t _box_x3962 = default_2800._cons.Optional.value;
      kk_integer_t _default_193780 = kk_integer_unbox(_box_x3962);
      kk_integer_dup(_default_193780);
      kk_std_core_types__optional_drop(default_2800, _ctx);
      return _default_193780;
    }
    return kk_integer_from_small(0);
  }
  kk_box_t _box_x3963 = m_21736._cons.Just.value;
  kk_integer_t x0 = kk_integer_unbox(_box_x3963);
  kk_integer_dup(x0);
  kk_std_core_types__maybe_drop(m_21736, _ctx);
  kk_std_core_types__optional_drop(default_2800, _ctx);
  return x0;
}
 
// monadic lift

bool kk_std_text_parse__mlift2567_sign(kk_char_t c, kk_context_t* _ctx) { /* (c : char) -> parse bool */ 
  return (c == ('-'));
}


// lift anonymous function
struct kk_std_text_parse_sign_fun5084__t {
  struct kk_function_s _base;
};
static kk_char_t kk_std_text_parse_sign_fun5084(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_sign_fun5084(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_sign_fun5084, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_std_text_parse_sign_fun5090__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse_sign_fun5090(kk_function_t _fself, kk_box_t _b_3978, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_sign_fun5090(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_sign_fun5090, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_text_parse_sign_fun5090(kk_function_t _fself, kk_box_t _b_3978, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core_types__maybe _x5091;
  kk_std_core_types__maybe _match_4358;
  kk_std_core__sslice _x5092 = kk_std_core__sslice_unbox(_b_3978, _ctx); /*sslice*/
  _match_4358 = kk_std_core_next(_x5092, _ctx); /*maybe<(char, sslice)>*/
  if (kk_std_core_types__is_Just(_match_4358)) {
    kk_box_t _box_x3979 = _match_4358._cons.Just.value;
    kk_std_core_types__tuple2_ _pat010 = kk_std_core_types__tuple2__unbox(_box_x3979, NULL);
    if (kk_std_core_types__is_dash__lp__comma__rp_(_pat010)) {
      kk_box_t _box_x3980 = _pat010.fst;
      kk_box_t _box_x3981 = _pat010.snd;
      kk_char_t c = kk_char_unbox(_box_x3980, NULL);
      kk_std_core__sslice rest0 = kk_std_core__sslice_unbox(_box_x3981, NULL);
      kk_string_t _x5097;
      kk_define_string_literal(, _s5098, 2, "+-")
      _x5097 = kk_string_dup(_s5098); /*string*/
      kk_string_t _x5099 = kk_std_core_string(c, _ctx); /*string*/
      if (kk_string_contains(_x5097,_x5099,kk_context())) {
        kk_std_core__sslice_dup(rest0);
        kk_std_core_types__maybe_drop(_match_4358, _ctx);
        kk_std_core_types__tuple2_ _b_3989_3984 = kk_std_core_types__new_dash__lp__comma__rp_(kk_char_box(c, _ctx), kk_std_core__sslice_box(rest0, _ctx), _ctx); /*(char, sslice)*/;
        _x5091 = kk_std_core_types__new_Just(kk_std_core_types__tuple2__box(_b_3989_3984, _ctx), _ctx); /*maybe<103>*/
        goto _match5093;
      }
    }
  }
  kk_std_core_types__maybe_drop(_match_4358, _ctx);
  _x5091 = kk_std_core_types__new_Nothing(_ctx); /*maybe<103>*/
  _match5093: ;
  return kk_std_core_types__maybe_box(_x5091, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_sign_fun5101__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse_sign_fun5101(kk_function_t _fself, kk_box_t _b_3995, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_sign_fun5101(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_sign_fun5101, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_text_parse_sign_fun5101(kk_function_t _fself, kk_box_t _b_3995, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x5102;
  kk_define_string_literal(, _s5103, 2, "+-")
  _x5102 = kk_string_dup(_s5103); /*string*/
  kk_std_core_types__maybe _x5104 = kk_std_core_types__maybe_unbox(_b_3995, _ctx); /*maybe<char>*/
  return kk_std_text_parse__mlift2547_satisfy_fail(_x5102, _x5104, _ctx);
}
static kk_char_t kk_std_text_parse_sign_fun5084(kk_function_t _fself, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core_types__maybe x_2754;
  kk_std_core_hnd__ev ev_2574;
  size_t _x5085 = ((size_t)0); /*size_t*/
  ev_2574 = kk_evv_at(_x5085,kk_context()); /*std/core/hnd/ev<std/text/parse/.hnd-parse>*/
  kk_box_t _x5086;
  struct kk_std_core_hnd_Ev* _con5087 = kk_std_core_hnd__as_Ev(ev_2574);
  kk_std_core_hnd__marker m0 = _con5087->marker;
  kk_box_t _box_x3965 = _con5087->hnd;
  kk_std_text_parse__hnd_parse h0 = kk_std_text_parse__hnd_parse_unbox(_box_x3965, NULL);
  kk_std_text_parse__hnd_parse_dup(h0);
  kk_std_core_hnd__clause1 _match_4357;
  struct kk_std_text_parse__Hnd_parse* _con5089 = kk_std_text_parse__as_Hnd_parse(h0);
  kk_std_core_hnd__clause0 _pat04 = _con5089->fun_current_input;
  kk_std_core_hnd__clause1 _pat13 = _con5089->control_fail;
  kk_std_core_hnd__clause0 _pat23 = _con5089->control_pick;
  kk_std_core_hnd__clause1 fun_satisfy = _con5089->fun_satisfy;
  if (kk_std_text_parse__hnd_parse_is_unique(h0)) {
    kk_std_core_hnd__clause0_drop(_pat23, _ctx);
    kk_std_core_hnd__clause1_drop(_pat13, _ctx);
    kk_std_core_hnd__clause0_drop(_pat04, _ctx);
    kk_std_text_parse__hnd_parse_free(h0);
  }
  else {
    kk_std_core_hnd__clause1_dup(fun_satisfy);
    kk_std_text_parse__hnd_parse_decref(h0, _ctx);
  }
  _match_4357 = fun_satisfy; /*forall<a> std/core/hnd/clause1<(sslice) -> total maybe<(a, sslice)>,maybe<a>,std/text/parse/.hnd-parse,3528,3529>*/
  kk_function_t _fun_unbox_x3972 = _match_4357.clause;
  _x5086 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x3972, (_fun_unbox_x3972, m0, ev_2574, kk_function_box(kk_std_text_parse_new_sign_fun5090(_ctx)), _ctx)); /*53*/
  x_2754 = kk_std_core_types__maybe_unbox(_x5086, _ctx); /*maybe<char>*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__maybe_drop(x_2754, _ctx);
    kk_box_t _x5100 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_sign_fun5101(_ctx), _ctx); /*3991*/
    return kk_char_unbox(_x5100, _ctx);
  }
  if (kk_std_core_types__is_Nothing(x_2754)) {
    kk_box_t _x5105;
    kk_string_t _x5106;
    kk_define_string_literal(, _s5107, 2, "+-")
    _x5106 = kk_string_dup(_s5107); /*string*/
    _x5105 = kk_std_text_parse_fail(_x5106, _ctx); /*492*/
    return kk_char_unbox(_x5105, _ctx);
  }
  kk_box_t _box_x3997 = x_2754._cons.Just.value;
  kk_char_t x0 = kk_char_unbox(_box_x3997, NULL);
  kk_std_core_types__maybe_drop(x_2754, _ctx);
  return x0;
}


// lift anonymous function
struct kk_std_text_parse_sign_fun5115__t {
  struct kk_function_s _base;
  size_t i_2666;
};
static kk_box_t kk_std_text_parse_sign_fun5115(kk_function_t _fself, kk_function_t _b_4016, kk_box_t _b_4017, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_sign_fun5115(size_t i_2666, kk_context_t* _ctx) {
  struct kk_std_text_parse_sign_fun5115__t* _self = kk_function_alloc_as(struct kk_std_text_parse_sign_fun5115__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_text_parse_sign_fun5115, kk_context());
  _self->i_2666 = i_2666;
  return &_self->_base;
}

static kk_box_t kk_std_text_parse_sign_fun5115(kk_function_t _fself, kk_function_t _b_4016, kk_box_t _b_4017, kk_context_t* _ctx) {
  struct kk_std_text_parse_sign_fun5115__t* _self = kk_function_as(struct kk_std_text_parse_sign_fun5115__t*, _fself);
  size_t i_2666 = _self->i_2666; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_2666, _b_4016, _b_4017, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_sign_fun5117__t {
  struct kk_function_s _base;
  kk_function_t p1_2922;
};
static kk_box_t kk_std_text_parse_sign_fun5117(kk_function_t _fself, kk_box_t _b_4030, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_sign_fun5117(kk_function_t p1_2922, kk_context_t* _ctx) {
  struct kk_std_text_parse_sign_fun5117__t* _self = kk_function_alloc_as(struct kk_std_text_parse_sign_fun5117__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_text_parse_sign_fun5117, kk_context());
  _self->p1_2922 = p1_2922;
  return &_self->_base;
}



// lift anonymous function
struct kk_std_text_parse_sign_fun5118__t {
  struct kk_function_s _base;
  kk_function_t p1_2922;
};
static kk_box_t kk_std_text_parse_sign_fun5118(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_sign_fun5118(kk_function_t p1_2922, kk_context_t* _ctx) {
  struct kk_std_text_parse_sign_fun5118__t* _self = kk_function_alloc_as(struct kk_std_text_parse_sign_fun5118__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_text_parse_sign_fun5118, kk_context());
  _self->p1_2922 = p1_2922;
  return &_self->_base;
}

static kk_box_t kk_std_text_parse_sign_fun5118(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_text_parse_sign_fun5118__t* _self = kk_function_as(struct kk_std_text_parse_sign_fun5118__t*, _fself);
  kk_function_t p1_2922 = _self->p1_2922; /* std/text/parse/parser<(<>),char> */
  kk_drop_match(_self, {kk_function_dup(p1_2922);}, {}, _ctx)
  kk_char_t _x5119 = kk_function_call(kk_char_t, (kk_function_t, kk_context_t*), p1_2922, (p1_2922, _ctx)); /*char*/
  return kk_char_box(_x5119, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_sign_fun5120__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse_sign_fun5120(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_sign_fun5120(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_sign_fun5120, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_text_parse_sign_fun5120(kk_function_t _fself, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return kk_char_box('+', _ctx);
}
static kk_box_t kk_std_text_parse_sign_fun5117(kk_function_t _fself, kk_box_t _b_4030, kk_context_t* _ctx) {
  struct kk_std_text_parse_sign_fun5117__t* _self = kk_function_as(struct kk_std_text_parse_sign_fun5117__t*, _fself);
  kk_function_t p1_2922 = _self->p1_2922; /* std/text/parse/parser<(<>),char> */
  kk_drop_match(_self, {kk_function_dup(p1_2922);}, {}, _ctx)
  bool _x5121 = kk_bool_unbox(_b_4030); /*bool*/
  return kk_std_text_parse__mlift2551_op(kk_std_text_parse_new_sign_fun5118(p1_2922, _ctx), kk_std_text_parse_new_sign_fun5120(_ctx), _x5121, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_sign_fun5123__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse_sign_fun5123(kk_function_t _fself, kk_box_t _b_4037, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_sign_fun5123(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_sign_fun5123, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_text_parse_sign_fun5123(kk_function_t _fself, kk_box_t _b_4037, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  bool _x5124;
  kk_char_t _x5125 = kk_char_unbox(_b_4037, _ctx); /*char*/
  _x5124 = kk_std_text_parse__mlift2567_sign(_x5125, _ctx); /*bool*/
  return kk_bool_box(_x5124);
}

bool kk_std_text_parse_sign(kk_context_t* _ctx) { /* () -> parse bool */ 
  kk_char_t x_2802;
  kk_function_t p1_2922 = kk_std_text_parse_new_sign_fun5084(_ctx); /*std/text/parse/parser<(<>),char>*/;
  bool x_2663;
  size_t i_2666 = ((size_t)0); /*std/core/hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_2666,kk_context()); /*std/core/hnd/evv<std/text/parse/parse>*/;
  bool y;
  kk_std_core_hnd__ev ev_2668;
  size_t _x5109 = ((size_t)0); /*size_t*/
  ev_2668 = kk_evv_at(_x5109,kk_context()); /*std/core/hnd/ev<std/text/parse/.hnd-parse>*/
  kk_box_t _x5110;
  struct kk_std_core_hnd_Ev* _con5111 = kk_std_core_hnd__as_Ev(ev_2668);
  kk_std_core_hnd__marker m = _con5111->marker;
  kk_box_t _box_x4003 = _con5111->hnd;
  kk_std_text_parse__hnd_parse h = kk_std_text_parse__hnd_parse_unbox(_box_x4003, NULL);
  kk_std_text_parse__hnd_parse_dup(h);
  kk_std_core_hnd__clause0 _match_4355;
  struct kk_std_text_parse__Hnd_parse* _con5113 = kk_std_text_parse__as_Hnd_parse(h);
  kk_std_core_hnd__clause0 _pat0 = _con5113->fun_current_input;
  kk_std_core_hnd__clause1 _pat1 = _con5113->control_fail;
  kk_std_core_hnd__clause0 control_pick = _con5113->control_pick;
  kk_std_core_hnd__clause1 _pat21 = _con5113->fun_satisfy;
  if (kk_std_text_parse__hnd_parse_is_unique(h)) {
    kk_std_core_hnd__clause1_drop(_pat21, _ctx);
    kk_std_core_hnd__clause1_drop(_pat1, _ctx);
    kk_std_core_hnd__clause0_drop(_pat0, _ctx);
    kk_std_text_parse__hnd_parse_free(h);
  }
  else {
    kk_std_core_hnd__clause0_dup(control_pick);
    kk_std_text_parse__hnd_parse_decref(h, _ctx);
  }
  _match_4355 = control_pick; /*std/core/hnd/clause0<bool,std/text/parse/.hnd-parse,3435,3436>*/
  kk_function_t _fun_unbox_x4006 = _match_4355.clause;
  _x5110 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x4006, (_fun_unbox_x4006, m, ev_2668, _ctx)); /*37*/
  y = kk_bool_unbox(_x5110); /*bool*/
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x5114 = kk_std_core_hnd_yield_cont(kk_std_text_parse_new_sign_fun5115(i_2666, _ctx), _ctx); /*3820*/
    x_2663 = kk_bool_unbox(_x5114); /*bool*/
  }
  else {
    x_2663 = y; /*bool*/
  }
  if (kk_yielding(kk_context())) {
    kk_box_t _x5116 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_sign_fun5117(p1_2922, _ctx), _ctx); /*3991*/
    x_2802 = kk_char_unbox(_x5116, _ctx); /*char*/
  }
  else {
    if (x_2663) {
      x_2802 = kk_function_call(kk_char_t, (kk_function_t, kk_context_t*), p1_2922, (p1_2922, _ctx)); /*char*/
    }
    else {
      kk_function_drop(p1_2922, _ctx);
      x_2802 = '+'; /*char*/
    }
  }
  if (kk_yielding(kk_context())) {
    kk_box_t _x5122 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_sign_fun5123(_ctx), _ctx); /*3991*/
    return kk_bool_unbox(_x5122);
  }
  return (x_2802 == ('-'));
}
 
// monadic lift

kk_integer_t kk_std_text_parse__mlift2568_pint(bool neg, kk_integer_t i, kk_context_t* _ctx) { /* (neg : bool, i : int) -> parse int */ 
  if (neg) {
    return kk_integer_neg(i,kk_context());
  }
  return i;
}
 
// monadic lift


// lift anonymous function
struct kk_std_text_parse__mlift2569_pint_fun5127__t {
  struct kk_function_s _base;
  bool neg;
};
static kk_box_t kk_std_text_parse__mlift2569_pint_fun5127(kk_function_t _fself, kk_box_t _b_4040, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse__new_mlift2569_pint_fun5127(bool neg, kk_context_t* _ctx) {
  struct kk_std_text_parse__mlift2569_pint_fun5127__t* _self = kk_function_alloc_as(struct kk_std_text_parse__mlift2569_pint_fun5127__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_text_parse__mlift2569_pint_fun5127, kk_context());
  _self->neg = neg;
  return &_self->_base;
}

static kk_box_t kk_std_text_parse__mlift2569_pint_fun5127(kk_function_t _fself, kk_box_t _b_4040, kk_context_t* _ctx) {
  struct kk_std_text_parse__mlift2569_pint_fun5127__t* _self = kk_function_as(struct kk_std_text_parse__mlift2569_pint_fun5127__t*, _fself);
  bool neg = _self->neg; /* bool */
  kk_drop_match(_self, {;}, {}, _ctx)
  kk_integer_t _x5128;
  kk_integer_t _x5129 = kk_integer_unbox(_b_4040); /*int*/
  _x5128 = kk_std_text_parse__mlift2568_pint(neg, _x5129, _ctx); /*int*/
  return kk_integer_box(_x5128);
}

kk_integer_t kk_std_text_parse__mlift2569_pint(bool neg, kk_context_t* _ctx) { /* (neg : bool) -> parse int */ 
  kk_integer_t x_2810 = kk_std_text_parse_pnat(_ctx); /*int*/;
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_2810, _ctx);
    kk_box_t _x5126 = kk_std_core_hnd_yield_extend(kk_std_text_parse__new_mlift2569_pint_fun5127(neg, _ctx), _ctx); /*3991*/
    return kk_integer_unbox(_x5126);
  }
  return kk_std_text_parse__mlift2568_pint(neg, x_2810, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_pint_fun5131__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse_pint_fun5131(kk_function_t _fself, kk_box_t _b_4044, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_pint_fun5131(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_pint_fun5131, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_text_parse_pint_fun5131(kk_function_t _fself, kk_box_t _b_4044, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_integer_t _x5132;
  bool _x5133 = kk_bool_unbox(_b_4044); /*bool*/
  _x5132 = kk_std_text_parse__mlift2569_pint(_x5133, _ctx); /*int*/
  return kk_integer_box(_x5132);
}


// lift anonymous function
struct kk_std_text_parse_pint_fun5135__t {
  struct kk_function_s _base;
  bool x_2812;
};
static kk_box_t kk_std_text_parse_pint_fun5135(kk_function_t _fself, kk_box_t _b_4046, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_pint_fun5135(bool x_2812, kk_context_t* _ctx) {
  struct kk_std_text_parse_pint_fun5135__t* _self = kk_function_alloc_as(struct kk_std_text_parse_pint_fun5135__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_text_parse_pint_fun5135, kk_context());
  _self->x_2812 = x_2812;
  return &_self->_base;
}

static kk_box_t kk_std_text_parse_pint_fun5135(kk_function_t _fself, kk_box_t _b_4046, kk_context_t* _ctx) {
  struct kk_std_text_parse_pint_fun5135__t* _self = kk_function_as(struct kk_std_text_parse_pint_fun5135__t*, _fself);
  bool x_2812 = _self->x_2812; /* bool */
  kk_drop_match(_self, {;}, {}, _ctx)
  kk_integer_t _x5136;
  kk_integer_t _x5137 = kk_integer_unbox(_b_4046); /*int*/
  _x5136 = kk_std_text_parse__mlift2568_pint(x_2812, _x5137, _ctx); /*int*/
  return kk_integer_box(_x5136);
}

kk_integer_t kk_std_text_parse_pint(kk_context_t* _ctx) { /* () -> parse int */ 
  bool x_2812 = kk_std_text_parse_sign(_ctx); /*bool*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x5130 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_pint_fun5131(_ctx), _ctx); /*3991*/
    return kk_integer_unbox(_x5130);
  }
  kk_integer_t x0_2816 = kk_std_text_parse_pnat(_ctx); /*int*/;
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x0_2816, _ctx);
    kk_box_t _x5134 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_pint_fun5135(x_2812, _ctx), _ctx); /*3991*/
    return kk_integer_unbox(_x5134);
  }
  if (x_2812) {
    return kk_integer_neg(x0_2816,kk_context());
  }
  return x0_2816;
}


// lift anonymous function
struct kk_std_text_parse_pstring_fun5145__t {
  struct kk_function_s _base;
  kk_string_t s;
};
static kk_box_t kk_std_text_parse_pstring_fun5145(kk_function_t _fself, kk_box_t _b_4063, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_pstring_fun5145(kk_string_t s, kk_context_t* _ctx) {
  struct kk_std_text_parse_pstring_fun5145__t* _self = kk_function_alloc_as(struct kk_std_text_parse_pstring_fun5145__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_text_parse_pstring_fun5145, kk_context());
  _self->s = s;
  return &_self->_base;
}

static kk_box_t kk_std_text_parse_pstring_fun5145(kk_function_t _fself, kk_box_t _b_4063, kk_context_t* _ctx) {
  struct kk_std_text_parse_pstring_fun5145__t* _self = kk_function_as(struct kk_std_text_parse_pstring_fun5145__t*, _fself);
  kk_string_t s = _self->s; /* string */
  kk_drop_match(_self, {kk_string_dup(s);}, {}, _ctx)
  kk_std_core_types__maybe _x5146;
  kk_std_core_types__maybe _match_4348;
  kk_std_core__sslice _x5147 = kk_std_core__sslice_unbox(_b_4063, _ctx); /*sslice*/
  kk_std_core__list _x5148;
  kk_string_t _x5149 = kk_string_dup(s); /*string*/
  _x5148 = kk_std_core_list_4(_x5149, _ctx); /*list<char>*/
  _match_4348 = kk_std_text_parse_next_match(_x5147, _x5148, _ctx); /*maybe<sslice>*/
  if (kk_std_core_types__is_Just(_match_4348)) {
    kk_box_t _box_x4064 = _match_4348._cons.Just.value;
    kk_std_core__sslice rest0 = kk_std_core__sslice_unbox(_box_x4064, NULL);
    kk_std_core__sslice_dup(rest0);
    kk_std_core_types__maybe_drop(_match_4348, _ctx);
    kk_std_core_types__tuple2_ _b_4072_4067 = kk_std_core_types__new_dash__lp__comma__rp_(kk_string_box(s), kk_std_core__sslice_box(rest0, _ctx), _ctx); /*(string, sslice)*/;
    _x5146 = kk_std_core_types__new_Just(kk_std_core_types__tuple2__box(_b_4072_4067, _ctx), _ctx); /*maybe<103>*/
    goto _match5150;
  }
  kk_string_drop(s, _ctx);
  _x5146 = kk_std_core_types__new_Nothing(_ctx); /*maybe<103>*/
  _match5150: ;
  return kk_std_core_types__maybe_box(_x5146, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_pstring_fun5153__t {
  struct kk_function_s _base;
  kk_string_t s;
};
static kk_box_t kk_std_text_parse_pstring_fun5153(kk_function_t _fself, kk_box_t _b_4078, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_pstring_fun5153(kk_string_t s, kk_context_t* _ctx) {
  struct kk_std_text_parse_pstring_fun5153__t* _self = kk_function_alloc_as(struct kk_std_text_parse_pstring_fun5153__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_text_parse_pstring_fun5153, kk_context());
  _self->s = s;
  return &_self->_base;
}

static kk_box_t kk_std_text_parse_pstring_fun5153(kk_function_t _fself, kk_box_t _b_4078, kk_context_t* _ctx) {
  struct kk_std_text_parse_pstring_fun5153__t* _self = kk_function_as(struct kk_std_text_parse_pstring_fun5153__t*, _fself);
  kk_string_t s = _self->s; /* string */
  kk_drop_match(_self, {kk_string_dup(s);}, {}, _ctx)
  kk_std_core_types__maybe _x5154 = kk_std_core_types__maybe_unbox(_b_4078, _ctx); /*maybe<string>*/
  return kk_std_text_parse__mlift2547_satisfy_fail(s, _x5154, _ctx);
}

kk_string_t kk_std_text_parse_pstring(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> parse string */ 
  kk_std_core_types__maybe x_2822;
  kk_std_core_hnd__ev ev_2574;
  size_t _x5138 = ((size_t)0); /*size_t*/
  ev_2574 = kk_evv_at(_x5138,kk_context()); /*std/core/hnd/ev<std/text/parse/.hnd-parse>*/
  kk_box_t _x5139;
  struct kk_std_core_hnd_Ev* _con5140 = kk_std_core_hnd__as_Ev(ev_2574);
  kk_std_core_hnd__marker m = _con5140->marker;
  kk_box_t _box_x4050 = _con5140->hnd;
  kk_std_text_parse__hnd_parse h = kk_std_text_parse__hnd_parse_unbox(_box_x4050, NULL);
  kk_std_text_parse__hnd_parse_dup(h);
  kk_std_core_hnd__clause1 _match_4347;
  struct kk_std_text_parse__Hnd_parse* _con5142 = kk_std_text_parse__as_Hnd_parse(h);
  kk_std_core_hnd__clause0 _pat00 = _con5142->fun_current_input;
  kk_std_core_hnd__clause1 _pat10 = _con5142->control_fail;
  kk_std_core_hnd__clause0 _pat20 = _con5142->control_pick;
  kk_std_core_hnd__clause1 fun_satisfy = _con5142->fun_satisfy;
  if (kk_std_text_parse__hnd_parse_is_unique(h)) {
    kk_std_core_hnd__clause0_drop(_pat20, _ctx);
    kk_std_core_hnd__clause1_drop(_pat10, _ctx);
    kk_std_core_hnd__clause0_drop(_pat00, _ctx);
    kk_std_text_parse__hnd_parse_free(h);
  }
  else {
    kk_std_core_hnd__clause1_dup(fun_satisfy);
    kk_std_text_parse__hnd_parse_decref(h, _ctx);
  }
  _match_4347 = fun_satisfy; /*forall<a> std/core/hnd/clause1<(sslice) -> total maybe<(a, sslice)>,maybe<a>,std/text/parse/.hnd-parse,3528,3529>*/
  kk_function_t _fun_unbox_x4057 = _match_4347.clause;
  kk_box_t _x5143;
  kk_function_t _x5144;
  kk_string_dup(s);
  _x5144 = kk_std_text_parse_new_pstring_fun5145(s, _ctx); /*(4061) -> total 4062*/
  _x5143 = kk_function_box(_x5144); /*52*/
  _x5139 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x4057, (_fun_unbox_x4057, m, ev_2574, _x5143, _ctx)); /*53*/
  x_2822 = kk_std_core_types__maybe_unbox(_x5139, _ctx); /*maybe<string>*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__maybe_drop(x_2822, _ctx);
    kk_box_t _x5152 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_pstring_fun5153(s, _ctx), _ctx); /*3991*/
    return kk_string_unbox(_x5152);
  }
  if (kk_std_core_types__is_Nothing(x_2822)) {
    kk_box_t _x5155 = kk_std_text_parse_fail(s, _ctx); /*492*/
    return kk_string_unbox(_x5155);
  }
  kk_box_t _box_x4080 = x_2822._cons.Just.value;
  kk_string_t x0 = kk_string_unbox(_box_x4080);
  kk_string_dup(x0);
  kk_std_core_types__maybe_drop(x_2822, _ctx);
  kk_string_drop(s, _ctx);
  return x0;
}

kk_std_core_types__maybe kk_std_text_parse_starts_with(kk_string_t s, kk_function_t p, kk_context_t* _ctx) { /* forall<a> (s : string, p : () -> parse a) -> maybe<(a, sslice)> */ 
  kk_std_text_parse__parse_error _match_4345;
  kk_std_core__sslice _x5157 = kk_std_core_slice(s, _ctx); /*sslice*/
  _match_4345 = kk_std_text_parse_parse(_x5157, p, _ctx); /*std/text/parse/parse-error<2282>*/
  if (kk_std_text_parse__is_ParseOk(_match_4345)) {
    struct kk_std_text_parse_ParseOk* _con5158 = kk_std_text_parse__as_ParseOk(_match_4345);
    kk_box_t x = _con5158->result;
    kk_std_core__sslice rest0 = _con5158->rest;
    if (kk_std_text_parse__parse_error_is_unique(_match_4345)) {
      kk_std_text_parse__parse_error_free(_match_4345);
    }
    else {
      kk_std_core__sslice_dup(rest0);
      kk_box_dup(x);
      kk_std_text_parse__parse_error_decref(_match_4345, _ctx);
    }
    kk_std_core_types__tuple2_ _b_4089_4088 = kk_std_core_types__new_dash__lp__comma__rp_(x, kk_std_core__sslice_box(rest0, _ctx), _ctx); /*(2486, sslice)*/;
    return kk_std_core_types__new_Just(kk_std_core_types__tuple2__box(_b_4089_4088, _ctx), _ctx);
  }
  kk_std_text_parse__parse_error_drop(_match_4345, _ctx);
  return kk_std_core_types__new_Nothing(_ctx);
}


// lift anonymous function
struct kk_std_text_parse_white_fun5164__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse_white_fun5164(kk_function_t _fself, kk_box_t _b_4105, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_white_fun5164(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_white_fun5164, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_text_parse_white_fun5164(kk_function_t _fself, kk_box_t _b_4105, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core_types__maybe _x5165;
  kk_std_core_types__maybe _match_4344;
  kk_std_core__sslice _x5166 = kk_std_core__sslice_unbox(_b_4105, _ctx); /*sslice*/
  _match_4344 = kk_std_core_next(_x5166, _ctx); /*maybe<(char, sslice)>*/
  if (kk_std_core_types__is_Just(_match_4344)) {
    kk_box_t _box_x4106 = _match_4344._cons.Just.value;
    kk_std_core_types__tuple2_ _pat01 = kk_std_core_types__tuple2__unbox(_box_x4106, NULL);
    if (kk_std_core_types__is_dash__lp__comma__rp_(_pat01)) {
      kk_box_t _box_x4107 = _pat01.fst;
      kk_box_t _box_x4108 = _pat01.snd;
      kk_char_t c = kk_char_unbox(_box_x4107, NULL);
      kk_std_core__sslice rest0 = kk_std_core__sslice_unbox(_box_x4108, NULL);
      if (kk_std_core_is_white(c, _ctx)) {
        kk_std_core__sslice_dup(rest0);
        kk_std_core_types__maybe_drop(_match_4344, _ctx);
        kk_std_core_types__tuple2_ _b_4116_4111 = kk_std_core_types__new_dash__lp__comma__rp_(kk_char_box(c, _ctx), kk_std_core__sslice_box(rest0, _ctx), _ctx); /*(char, sslice)*/;
        _x5165 = kk_std_core_types__new_Just(kk_std_core_types__tuple2__box(_b_4116_4111, _ctx), _ctx); /*maybe<103>*/
        goto _match5167;
      }
    }
  }
  kk_std_core_types__maybe_drop(_match_4344, _ctx);
  _x5165 = kk_std_core_types__new_Nothing(_ctx); /*maybe<103>*/
  _match5167: ;
  return kk_std_core_types__maybe_box(_x5165, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_white_fun5172__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse_white_fun5172(kk_function_t _fself, kk_box_t _b_4122, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_white_fun5172(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_white_fun5172, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_text_parse_white_fun5172(kk_function_t _fself, kk_box_t _b_4122, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x5173 = kk_string_empty(); /*string*/
  kk_std_core_types__maybe _x5175 = kk_std_core_types__maybe_unbox(_b_4122, _ctx); /*maybe<char>*/
  return kk_std_text_parse__mlift2547_satisfy_fail(_x5173, _x5175, _ctx);
}

kk_char_t kk_std_text_parse_white(kk_context_t* _ctx) { /* () -> parse char */ 
  kk_std_core_types__maybe x_2830;
  kk_std_core_hnd__ev ev_2574;
  size_t _x5159 = ((size_t)0); /*size_t*/
  ev_2574 = kk_evv_at(_x5159,kk_context()); /*std/core/hnd/ev<std/text/parse/.hnd-parse>*/
  kk_box_t _x5160;
  struct kk_std_core_hnd_Ev* _con5161 = kk_std_core_hnd__as_Ev(ev_2574);
  kk_std_core_hnd__marker m = _con5161->marker;
  kk_box_t _box_x4092 = _con5161->hnd;
  kk_std_text_parse__hnd_parse h = kk_std_text_parse__hnd_parse_unbox(_box_x4092, NULL);
  kk_std_text_parse__hnd_parse_dup(h);
  kk_std_core_hnd__clause1 _match_4343;
  struct kk_std_text_parse__Hnd_parse* _con5163 = kk_std_text_parse__as_Hnd_parse(h);
  kk_std_core_hnd__clause0 _pat00 = _con5163->fun_current_input;
  kk_std_core_hnd__clause1 _pat10 = _con5163->control_fail;
  kk_std_core_hnd__clause0 _pat20 = _con5163->control_pick;
  kk_std_core_hnd__clause1 fun_satisfy = _con5163->fun_satisfy;
  if (kk_std_text_parse__hnd_parse_is_unique(h)) {
    kk_std_core_hnd__clause0_drop(_pat20, _ctx);
    kk_std_core_hnd__clause1_drop(_pat10, _ctx);
    kk_std_core_hnd__clause0_drop(_pat00, _ctx);
    kk_std_text_parse__hnd_parse_free(h);
  }
  else {
    kk_std_core_hnd__clause1_dup(fun_satisfy);
    kk_std_text_parse__hnd_parse_decref(h, _ctx);
  }
  _match_4343 = fun_satisfy; /*forall<a> std/core/hnd/clause1<(sslice) -> total maybe<(a, sslice)>,maybe<a>,std/text/parse/.hnd-parse,3528,3529>*/
  kk_function_t _fun_unbox_x4099 = _match_4343.clause;
  _x5160 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x4099, (_fun_unbox_x4099, m, ev_2574, kk_function_box(kk_std_text_parse_new_white_fun5164(_ctx)), _ctx)); /*53*/
  x_2830 = kk_std_core_types__maybe_unbox(_x5160, _ctx); /*maybe<char>*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__maybe_drop(x_2830, _ctx);
    kk_box_t _x5171 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_white_fun5172(_ctx), _ctx); /*3991*/
    return kk_char_unbox(_x5171, _ctx);
  }
  if (kk_std_core_types__is_Nothing(x_2830)) {
    kk_box_t _x5176;
    kk_string_t _x5177 = kk_string_empty(); /*string*/
    _x5176 = kk_std_text_parse_fail(_x5177, _ctx); /*492*/
    return kk_char_unbox(_x5176, _ctx);
  }
  kk_box_t _box_x4124 = x_2830._cons.Just.value;
  kk_char_t x0 = kk_char_unbox(_box_x4124, NULL);
  kk_std_core_types__maybe_drop(x_2830, _ctx);
  return x0;
}


// lift anonymous function
struct kk_std_text_parse_whitespace_fun5185__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse_whitespace_fun5185(kk_function_t _fself, kk_box_t _b_4143, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_whitespace_fun5185(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_whitespace_fun5185, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_std_text_parse_whitespace_fun5189__t {
  struct kk_function_s _base;
};
static bool kk_std_text_parse_whitespace_fun5189(kk_function_t _fself, kk_char_t _x15188, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_whitespace_fun5189(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_whitespace_fun5189, _ctx)
  return kk_function_dup(_fself);
}

static bool kk_std_text_parse_whitespace_fun5189(kk_function_t _fself, kk_char_t _x15188, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return kk_std_core_is_white(_x15188, _ctx);
}
static kk_box_t kk_std_text_parse_whitespace_fun5185(kk_function_t _fself, kk_box_t _b_4143, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core_types__maybe _x5186;
  kk_std_core_types__tuple2_ _match_4341;
  kk_std_core__sslice _x5187 = kk_std_core__sslice_unbox(_b_4143, _ctx); /*sslice*/
  _match_4341 = kk_std_text_parse_next_while0(_x5187, kk_std_text_parse_new_whitespace_fun5189(_ctx), kk_std_core__new_Nil(_ctx), _ctx); /*(list<char>, sslice)*/
  kk_box_t _box_x4144 = _match_4341.fst;
  kk_box_t _box_x4145 = _match_4341.snd;
  kk_std_core__list _pat02 = kk_std_core__list_unbox(_box_x4144, NULL);
  kk_std_core__sslice _pat100 = kk_std_core__sslice_unbox(_box_x4145, NULL);
  if (kk_std_core__is_Nil(_pat02)) {
    kk_std_core_types__tuple2__drop(_match_4341, _ctx);
    _x5186 = kk_std_core_types__new_Nothing(_ctx); /*forall<a> maybe<a>*/
    goto _match5190;
  }
  kk_box_t _box_x4146 = _match_4341.fst;
  kk_box_t _box_x4147 = _match_4341.snd;
  kk_std_core__list xs = kk_std_core__list_unbox(_box_x4146, NULL);
  kk_std_core__sslice rest0 = kk_std_core__sslice_unbox(_box_x4147, NULL);
  kk_std_core__sslice_dup(rest0);
  kk_std_core__list_dup(xs);
  kk_std_core_types__tuple2__drop(_match_4341, _ctx);
  kk_std_core_types__tuple2_ _b_4155_4150 = kk_std_core_types__new_dash__lp__comma__rp_(kk_std_core__list_box(xs, _ctx), kk_std_core__sslice_box(rest0, _ctx), _ctx); /*(list<char>, sslice)*/;
  _x5186 = kk_std_core_types__new_Just(kk_std_core_types__tuple2__box(_b_4155_4150, _ctx), _ctx); /*forall<a> maybe<a>*/
  _match5190: ;
  return kk_std_core_types__maybe_box(_x5186, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_whitespace_fun5196__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse_whitespace_fun5196(kk_function_t _fself, kk_box_t _b_4161, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_whitespace_fun5196(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_whitespace_fun5196, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_text_parse_whitespace_fun5196(kk_function_t _fself, kk_box_t _b_4161, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x5197 = kk_string_empty(); /*string*/
  kk_std_core_types__maybe _x5199 = kk_std_core_types__maybe_unbox(_b_4161, _ctx); /*maybe<list<char>>*/
  return kk_std_text_parse__mlift2547_satisfy_fail(_x5197, _x5199, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_whitespace_fun5205__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse_whitespace_fun5205(kk_function_t _fself, kk_box_t _b_4170, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_whitespace_fun5205(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_whitespace_fun5205, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_text_parse_whitespace_fun5205(kk_function_t _fself, kk_box_t _b_4170, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x5206;
  kk_std_core__list _x5207 = kk_std_core__list_unbox(_b_4170, _ctx); /*list<char>*/
  _x5206 = kk_std_core_string_2(_x5207, _ctx); /*string*/
  return kk_string_box(_x5206);
}

kk_string_t kk_std_text_parse_whitespace(kk_context_t* _ctx) { /* () -> parse string */ 
  kk_std_core__list x_2834;
  kk_std_core_types__maybe x0_2840;
  kk_std_core_hnd__ev ev_2574;
  size_t _x5180 = ((size_t)0); /*size_t*/
  ev_2574 = kk_evv_at(_x5180,kk_context()); /*std/core/hnd/ev<std/text/parse/.hnd-parse>*/
  kk_box_t _x5181;
  struct kk_std_core_hnd_Ev* _con5182 = kk_std_core_hnd__as_Ev(ev_2574);
  kk_std_core_hnd__marker m = _con5182->marker;
  kk_box_t _box_x4130 = _con5182->hnd;
  kk_std_text_parse__hnd_parse h = kk_std_text_parse__hnd_parse_unbox(_box_x4130, NULL);
  kk_std_text_parse__hnd_parse_dup(h);
  kk_std_core_hnd__clause1 _match_4340;
  struct kk_std_text_parse__Hnd_parse* _con5184 = kk_std_text_parse__as_Hnd_parse(h);
  kk_std_core_hnd__clause0 _pat00 = _con5184->fun_current_input;
  kk_std_core_hnd__clause1 _pat10 = _con5184->control_fail;
  kk_std_core_hnd__clause0 _pat20 = _con5184->control_pick;
  kk_std_core_hnd__clause1 fun_satisfy = _con5184->fun_satisfy;
  if (kk_std_text_parse__hnd_parse_is_unique(h)) {
    kk_std_core_hnd__clause0_drop(_pat20, _ctx);
    kk_std_core_hnd__clause1_drop(_pat10, _ctx);
    kk_std_core_hnd__clause0_drop(_pat00, _ctx);
    kk_std_text_parse__hnd_parse_free(h);
  }
  else {
    kk_std_core_hnd__clause1_dup(fun_satisfy);
    kk_std_text_parse__hnd_parse_decref(h, _ctx);
  }
  _match_4340 = fun_satisfy; /*forall<a> std/core/hnd/clause1<(sslice) -> total maybe<(a, sslice)>,maybe<a>,std/text/parse/.hnd-parse,3528,3529>*/
  kk_function_t _fun_unbox_x4137 = _match_4340.clause;
  _x5181 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x4137, (_fun_unbox_x4137, m, ev_2574, kk_function_box(kk_std_text_parse_new_whitespace_fun5185(_ctx)), _ctx)); /*53*/
  x0_2840 = kk_std_core_types__maybe_unbox(_x5181, _ctx); /*maybe<list<char>>*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__maybe_drop(x0_2840, _ctx);
    kk_box_t _x5195 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_whitespace_fun5196(_ctx), _ctx); /*3991*/
    x_2834 = kk_std_core__list_unbox(_x5195, _ctx); /*list<char>*/
  }
  else {
    if (kk_std_core_types__is_Nothing(x0_2840)) {
      kk_box_t _x5200;
      kk_string_t _x5201 = kk_string_empty(); /*string*/
      _x5200 = kk_std_text_parse_fail(_x5201, _ctx); /*492*/
      x_2834 = kk_std_core__list_unbox(_x5200, _ctx); /*list<char>*/
    }
    else {
      kk_box_t _box_x4163 = x0_2840._cons.Just.value;
      kk_std_core__list x1 = kk_std_core__list_unbox(_box_x4163, NULL);
      kk_std_core__list_dup(x1);
      kk_std_core_types__maybe_drop(x0_2840, _ctx);
      x_2834 = x1; /*list<char>*/
    }
  }
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_2834, _ctx);
    kk_box_t _x5204 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_whitespace_fun5205(_ctx), _ctx); /*3991*/
    return kk_string_unbox(_x5204);
  }
  return kk_std_core_string_2(x_2834, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_whitespace0_fun5208__t {
  struct kk_function_s _base;
};
static kk_string_t kk_std_text_parse_whitespace0_fun5208(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_whitespace0_fun5208(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_whitespace0_fun5208, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_std_text_parse_whitespace0_fun5214__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse_whitespace0_fun5214(kk_function_t _fself, kk_box_t _b_4185, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_whitespace0_fun5214(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_whitespace0_fun5214, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_std_text_parse_whitespace0_fun5218__t {
  struct kk_function_s _base;
};
static bool kk_std_text_parse_whitespace0_fun5218(kk_function_t _fself, kk_char_t _x15217, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_whitespace0_fun5218(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_whitespace0_fun5218, _ctx)
  return kk_function_dup(_fself);
}

static bool kk_std_text_parse_whitespace0_fun5218(kk_function_t _fself, kk_char_t _x15217, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return kk_std_core_is_white(_x15217, _ctx);
}
static kk_box_t kk_std_text_parse_whitespace0_fun5214(kk_function_t _fself, kk_box_t _b_4185, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core_types__maybe _x5215;
  kk_std_core_types__tuple2_ _match_4337;
  kk_std_core__sslice _x5216 = kk_std_core__sslice_unbox(_b_4185, _ctx); /*sslice*/
  _match_4337 = kk_std_text_parse_next_while0(_x5216, kk_std_text_parse_new_whitespace0_fun5218(_ctx), kk_std_core__new_Nil(_ctx), _ctx); /*(list<char>, sslice)*/
  kk_box_t _box_x4186 = _match_4337.fst;
  kk_box_t _box_x4187 = _match_4337.snd;
  kk_std_core__list _pat021 = kk_std_core__list_unbox(_box_x4186, NULL);
  kk_std_core__sslice _pat100 = kk_std_core__sslice_unbox(_box_x4187, NULL);
  if (kk_std_core__is_Nil(_pat021)) {
    kk_std_core_types__tuple2__drop(_match_4337, _ctx);
    _x5215 = kk_std_core_types__new_Nothing(_ctx); /*forall<a> maybe<a>*/
    goto _match5219;
  }
  kk_box_t _box_x4188 = _match_4337.fst;
  kk_box_t _box_x4189 = _match_4337.snd;
  kk_std_core__list xs = kk_std_core__list_unbox(_box_x4188, NULL);
  kk_std_core__sslice rest0 = kk_std_core__sslice_unbox(_box_x4189, NULL);
  kk_std_core__sslice_dup(rest0);
  kk_std_core__list_dup(xs);
  kk_std_core_types__tuple2__drop(_match_4337, _ctx);
  kk_std_core_types__tuple2_ _b_4197_4192 = kk_std_core_types__new_dash__lp__comma__rp_(kk_std_core__list_box(xs, _ctx), kk_std_core__sslice_box(rest0, _ctx), _ctx); /*(list<char>, sslice)*/;
  _x5215 = kk_std_core_types__new_Just(kk_std_core_types__tuple2__box(_b_4197_4192, _ctx), _ctx); /*forall<a> maybe<a>*/
  _match5219: ;
  return kk_std_core_types__maybe_box(_x5215, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_whitespace0_fun5225__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse_whitespace0_fun5225(kk_function_t _fself, kk_box_t _b_4203, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_whitespace0_fun5225(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_whitespace0_fun5225, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_text_parse_whitespace0_fun5225(kk_function_t _fself, kk_box_t _b_4203, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x5226 = kk_string_empty(); /*string*/
  kk_std_core_types__maybe _x5228 = kk_std_core_types__maybe_unbox(_b_4203, _ctx); /*maybe<list<char>>*/
  return kk_std_text_parse__mlift2547_satisfy_fail(_x5226, _x5228, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_whitespace0_fun5234__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse_whitespace0_fun5234(kk_function_t _fself, kk_box_t _b_4212, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_whitespace0_fun5234(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_whitespace0_fun5234, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_text_parse_whitespace0_fun5234(kk_function_t _fself, kk_box_t _b_4212, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x5235;
  kk_std_core__list _x5236 = kk_std_core__list_unbox(_b_4212, _ctx); /*list<char>*/
  _x5235 = kk_std_core_string_2(_x5236, _ctx); /*string*/
  return kk_string_box(_x5235);
}
static kk_string_t kk_std_text_parse_whitespace0_fun5208(kk_function_t _fself, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core__list x_2846;
  kk_std_core_types__maybe x0_2852;
  kk_std_core_hnd__ev ev_2574;
  size_t _x5209 = ((size_t)0); /*size_t*/
  ev_2574 = kk_evv_at(_x5209,kk_context()); /*std/core/hnd/ev<std/text/parse/.hnd-parse>*/
  kk_box_t _x5210;
  struct kk_std_core_hnd_Ev* _con5211 = kk_std_core_hnd__as_Ev(ev_2574);
  kk_std_core_hnd__marker m0 = _con5211->marker;
  kk_box_t _box_x4172 = _con5211->hnd;
  kk_std_text_parse__hnd_parse h0 = kk_std_text_parse__hnd_parse_unbox(_box_x4172, NULL);
  kk_std_text_parse__hnd_parse_dup(h0);
  kk_std_core_hnd__clause1 _match_4336;
  struct kk_std_text_parse__Hnd_parse* _con5213 = kk_std_text_parse__as_Hnd_parse(h0);
  kk_std_core_hnd__clause0 _pat04 = _con5213->fun_current_input;
  kk_std_core_hnd__clause1 _pat13 = _con5213->control_fail;
  kk_std_core_hnd__clause0 _pat23 = _con5213->control_pick;
  kk_std_core_hnd__clause1 fun_satisfy = _con5213->fun_satisfy;
  if (kk_std_text_parse__hnd_parse_is_unique(h0)) {
    kk_std_core_hnd__clause0_drop(_pat23, _ctx);
    kk_std_core_hnd__clause1_drop(_pat13, _ctx);
    kk_std_core_hnd__clause0_drop(_pat04, _ctx);
    kk_std_text_parse__hnd_parse_free(h0);
  }
  else {
    kk_std_core_hnd__clause1_dup(fun_satisfy);
    kk_std_text_parse__hnd_parse_decref(h0, _ctx);
  }
  _match_4336 = fun_satisfy; /*forall<a> std/core/hnd/clause1<(sslice) -> total maybe<(a, sslice)>,maybe<a>,std/text/parse/.hnd-parse,3528,3529>*/
  kk_function_t _fun_unbox_x4179 = _match_4336.clause;
  _x5210 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x4179, (_fun_unbox_x4179, m0, ev_2574, kk_function_box(kk_std_text_parse_new_whitespace0_fun5214(_ctx)), _ctx)); /*53*/
  x0_2852 = kk_std_core_types__maybe_unbox(_x5210, _ctx); /*maybe<list<char>>*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__maybe_drop(x0_2852, _ctx);
    kk_box_t _x5224 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_whitespace0_fun5225(_ctx), _ctx); /*3991*/
    x_2846 = kk_std_core__list_unbox(_x5224, _ctx); /*list<char>*/
  }
  else {
    if (kk_std_core_types__is_Nothing(x0_2852)) {
      kk_box_t _x5229;
      kk_string_t _x5230 = kk_string_empty(); /*string*/
      _x5229 = kk_std_text_parse_fail(_x5230, _ctx); /*492*/
      x_2846 = kk_std_core__list_unbox(_x5229, _ctx); /*list<char>*/
    }
    else {
      kk_box_t _box_x4205 = x0_2852._cons.Just.value;
      kk_std_core__list x1 = kk_std_core__list_unbox(_box_x4205, NULL);
      kk_std_core__list_dup(x1);
      kk_std_core_types__maybe_drop(x0_2852, _ctx);
      x_2846 = x1; /*list<char>*/
    }
  }
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_2846, _ctx);
    kk_box_t _x5233 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_whitespace0_fun5234(_ctx), _ctx); /*3991*/
    return kk_string_unbox(_x5233);
  }
  return kk_std_core_string_2(x_2846, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_whitespace0_fun5243__t {
  struct kk_function_s _base;
  size_t i_2666;
};
static kk_box_t kk_std_text_parse_whitespace0_fun5243(kk_function_t _fself, kk_function_t _b_4227, kk_box_t _b_4228, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_whitespace0_fun5243(size_t i_2666, kk_context_t* _ctx) {
  struct kk_std_text_parse_whitespace0_fun5243__t* _self = kk_function_alloc_as(struct kk_std_text_parse_whitespace0_fun5243__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_text_parse_whitespace0_fun5243, kk_context());
  _self->i_2666 = i_2666;
  return &_self->_base;
}

static kk_box_t kk_std_text_parse_whitespace0_fun5243(kk_function_t _fself, kk_function_t _b_4227, kk_box_t _b_4228, kk_context_t* _ctx) {
  struct kk_std_text_parse_whitespace0_fun5243__t* _self = kk_function_as(struct kk_std_text_parse_whitespace0_fun5243__t*, _fself);
  size_t i_2666 = _self->i_2666; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_2666, _b_4227, _b_4228, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_whitespace0_fun5245__t {
  struct kk_function_s _base;
  kk_function_t p1_2935;
};
static kk_box_t kk_std_text_parse_whitespace0_fun5245(kk_function_t _fself, kk_box_t _b_4241, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_whitespace0_fun5245(kk_function_t p1_2935, kk_context_t* _ctx) {
  struct kk_std_text_parse_whitespace0_fun5245__t* _self = kk_function_alloc_as(struct kk_std_text_parse_whitespace0_fun5245__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_text_parse_whitespace0_fun5245, kk_context());
  _self->p1_2935 = p1_2935;
  return &_self->_base;
}



// lift anonymous function
struct kk_std_text_parse_whitespace0_fun5246__t {
  struct kk_function_s _base;
  kk_function_t p1_2935;
};
static kk_box_t kk_std_text_parse_whitespace0_fun5246(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_whitespace0_fun5246(kk_function_t p1_2935, kk_context_t* _ctx) {
  struct kk_std_text_parse_whitespace0_fun5246__t* _self = kk_function_alloc_as(struct kk_std_text_parse_whitespace0_fun5246__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_text_parse_whitespace0_fun5246, kk_context());
  _self->p1_2935 = p1_2935;
  return &_self->_base;
}

static kk_box_t kk_std_text_parse_whitespace0_fun5246(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_text_parse_whitespace0_fun5246__t* _self = kk_function_as(struct kk_std_text_parse_whitespace0_fun5246__t*, _fself);
  kk_function_t p1_2935 = _self->p1_2935; /* std/text/parse/parser<(<>),string> */
  kk_drop_match(_self, {kk_function_dup(p1_2935);}, {}, _ctx)
  kk_string_t _x5247 = kk_function_call(kk_string_t, (kk_function_t, kk_context_t*), p1_2935, (p1_2935, _ctx)); /*string*/
  return kk_string_box(_x5247);
}


// lift anonymous function
struct kk_std_text_parse_whitespace0_fun5248__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse_whitespace0_fun5248(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_whitespace0_fun5248(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_whitespace0_fun5248, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_text_parse_whitespace0_fun5248(kk_function_t _fself, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x5249 = kk_string_empty(); /*string*/
  return kk_string_box(_x5249);
}
static kk_box_t kk_std_text_parse_whitespace0_fun5245(kk_function_t _fself, kk_box_t _b_4241, kk_context_t* _ctx) {
  struct kk_std_text_parse_whitespace0_fun5245__t* _self = kk_function_as(struct kk_std_text_parse_whitespace0_fun5245__t*, _fself);
  kk_function_t p1_2935 = _self->p1_2935; /* std/text/parse/parser<(<>),string> */
  kk_drop_match(_self, {kk_function_dup(p1_2935);}, {}, _ctx)
  bool _x5251 = kk_bool_unbox(_b_4241); /*bool*/
  return kk_std_text_parse__mlift2551_op(kk_std_text_parse_new_whitespace0_fun5246(p1_2935, _ctx), kk_std_text_parse_new_whitespace0_fun5248(_ctx), _x5251, _ctx);
}

kk_string_t kk_std_text_parse_whitespace0(kk_context_t* _ctx) { /* () -> parse string */ 
  kk_function_t p1_2935 = kk_std_text_parse_new_whitespace0_fun5208(_ctx); /*std/text/parse/parser<(<>),string>*/;
  bool x_2663;
  size_t i_2666 = ((size_t)0); /*std/core/hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_2666,kk_context()); /*std/core/hnd/evv<std/text/parse/parse>*/;
  bool y;
  kk_std_core_hnd__ev ev_2668;
  size_t _x5237 = ((size_t)0); /*size_t*/
  ev_2668 = kk_evv_at(_x5237,kk_context()); /*std/core/hnd/ev<std/text/parse/.hnd-parse>*/
  kk_box_t _x5238;
  struct kk_std_core_hnd_Ev* _con5239 = kk_std_core_hnd__as_Ev(ev_2668);
  kk_std_core_hnd__marker m = _con5239->marker;
  kk_box_t _box_x4214 = _con5239->hnd;
  kk_std_text_parse__hnd_parse h = kk_std_text_parse__hnd_parse_unbox(_box_x4214, NULL);
  kk_std_text_parse__hnd_parse_dup(h);
  kk_std_core_hnd__clause0 _match_4333;
  struct kk_std_text_parse__Hnd_parse* _con5241 = kk_std_text_parse__as_Hnd_parse(h);
  kk_std_core_hnd__clause0 _pat0 = _con5241->fun_current_input;
  kk_std_core_hnd__clause1 _pat1 = _con5241->control_fail;
  kk_std_core_hnd__clause0 control_pick = _con5241->control_pick;
  kk_std_core_hnd__clause1 _pat21 = _con5241->fun_satisfy;
  if (kk_std_text_parse__hnd_parse_is_unique(h)) {
    kk_std_core_hnd__clause1_drop(_pat21, _ctx);
    kk_std_core_hnd__clause1_drop(_pat1, _ctx);
    kk_std_core_hnd__clause0_drop(_pat0, _ctx);
    kk_std_text_parse__hnd_parse_free(h);
  }
  else {
    kk_std_core_hnd__clause0_dup(control_pick);
    kk_std_text_parse__hnd_parse_decref(h, _ctx);
  }
  _match_4333 = control_pick; /*std/core/hnd/clause0<bool,std/text/parse/.hnd-parse,3435,3436>*/
  kk_function_t _fun_unbox_x4217 = _match_4333.clause;
  _x5238 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x4217, (_fun_unbox_x4217, m, ev_2668, _ctx)); /*37*/
  y = kk_bool_unbox(_x5238); /*bool*/
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x5242 = kk_std_core_hnd_yield_cont(kk_std_text_parse_new_whitespace0_fun5243(i_2666, _ctx), _ctx); /*3820*/
    x_2663 = kk_bool_unbox(_x5242); /*bool*/
  }
  else {
    x_2663 = y; /*bool*/
  }
  if (kk_yielding(kk_context())) {
    kk_box_t _x5244 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_whitespace0_fun5245(p1_2935, _ctx), _ctx); /*3991*/
    return kk_string_unbox(_x5244);
  }
  if (x_2663) {
    return kk_function_call(kk_string_t, (kk_function_t, kk_context_t*), p1_2935, (p1_2935, _ctx));
  }
  kk_function_drop(p1_2935, _ctx);
  return kk_string_empty();
}

// initialization
void kk_std_text_parse__init(kk_context_t* _ctx){
  static bool _initialized = false;
  if (_initialized) return;
  _initialized = true;
  kk_std_core_types__init(_ctx);
  kk_std_core_hnd__init(_ctx);
  kk_std_core__init(_ctx);
  {
    kk_string_t _x4463;
    kk_define_string_literal(, _s4464, 11, "parse.parse")
    _x4463 = kk_string_dup(_s4464); /*string*/
    kk_std_text_parse__tag_parse = kk_std_core_hnd__new_Htag(_x4463, _ctx); /*std/core/hnd/htag<std/text/parse/.hnd-parse>*/
  }
}
