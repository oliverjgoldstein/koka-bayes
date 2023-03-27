// Koka generated module: "climate-change", koka version: 2.1.2
#include "climate_dash_change.h"
 
// monadic lift


// lift anonymous function
struct kk_climate_dash_change__mlift2750_convert__uncertainty__to__rand_fun3466__t {
  struct kk_function_s _base;
  double _x20;
};
static kk_box_t kk_climate_dash_change__mlift2750_convert__uncertainty__to__rand_fun3466(kk_function_t _fself, kk_box_t _b_2915, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change__new_mlift2750_convert__uncertainty__to__rand_fun3466(double _x20, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2750_convert__uncertainty__to__rand_fun3466__t* _self = kk_function_alloc_as(struct kk_climate_dash_change__mlift2750_convert__uncertainty__to__rand_fun3466__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_change__mlift2750_convert__uncertainty__to__rand_fun3466, kk_context());
  _self->_x20 = _x20;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_change__mlift2750_convert__uncertainty__to__rand_fun3466(kk_function_t _fself, kk_box_t _b_2915, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2750_convert__uncertainty__to__rand_fun3466__t* _self = kk_function_as(struct kk_climate_dash_change__mlift2750_convert__uncertainty__to__rand_fun3466__t*, _fself);
  double _x20 = _self->_x20; /* double */
  kk_drop_match(_self, {;}, {}, _ctx)
  double _x3467;
  double _x3468 = kk_double_unbox(_b_2915, _ctx); /*double*/
  _x3467 = kk_model_dash_resources__mlift3175_normal(0x0p+0, _x20, _x3468, _ctx); /*double*/
  return kk_double_box(_x3467, _ctx);
}


// lift anonymous function
struct kk_climate_dash_change__mlift2750_convert__uncertainty__to__rand_fun3471__t {
  struct kk_function_s _base;
  size_t i_2769;
};
static kk_box_t kk_climate_dash_change__mlift2750_convert__uncertainty__to__rand_fun3471(kk_function_t _fself, kk_function_t _b_2923, kk_box_t _b_2924, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change__new_mlift2750_convert__uncertainty__to__rand_fun3471(size_t i_2769, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2750_convert__uncertainty__to__rand_fun3471__t* _self = kk_function_alloc_as(struct kk_climate_dash_change__mlift2750_convert__uncertainty__to__rand_fun3471__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_change__mlift2750_convert__uncertainty__to__rand_fun3471, kk_context());
  _self->i_2769 = i_2769;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_change__mlift2750_convert__uncertainty__to__rand_fun3471(kk_function_t _fself, kk_function_t _b_2923, kk_box_t _b_2924, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2750_convert__uncertainty__to__rand_fun3471__t* _self = kk_function_as(struct kk_climate_dash_change__mlift2750_convert__uncertainty__to__rand_fun3471__t*, _fself);
  size_t i_2769 = _self->i_2769; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_2769, _b_2923, _b_2924, _ctx);
}

double kk_climate_dash_change__mlift2750_convert__uncertainty__to__rand(double uncertainty, kk_context_t* _ctx) { /* (uncertainty : double) -> <exn,effects-and-types/sample> double */ 
  double _x20 = (uncertainty / (0x1.f5c28f5c28f5cp1)); /*double*/;
  size_t i_2769 = ((size_t)1); /*std/core/hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_2769,kk_context()); /*std/core/hnd/evv<<effects-and-types/sample,exn>>*/;
  double y;
  double x_3267 = kk_model_dash_resources_standard_normal(_ctx); /*double*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x3465 = kk_std_core_hnd_yield_extend(kk_climate_dash_change__new_mlift2750_convert__uncertainty__to__rand_fun3466(_x20, _ctx), _ctx); /*2*/
    y = kk_double_unbox(_x3465, _ctx); /*double*/
  }
  else {
    double _x3469 = (x_3267 * _x20); /*double*/
    y = ((0x0p+0) + _x3469); /*double*/
  }
  kk_unit_t __w_l713_c9 = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x3470 = kk_std_core_hnd_yield_cont(kk_climate_dash_change__new_mlift2750_convert__uncertainty__to__rand_fun3471(i_2769, _ctx), _ctx); /*3*/
    return kk_double_unbox(_x3470, _ctx);
  }
  return y;
}


// lift anonymous function
struct kk_climate_dash_change_convert__uncertainty__to__rand_fun3474__t {
  struct kk_function_s _base;
  kk_std_core__list vs;
};
static kk_box_t kk_climate_dash_change_convert__uncertainty__to__rand_fun3474(kk_function_t _fself, kk_integer_t _b_2958, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change_new_convert__uncertainty__to__rand_fun3474(kk_std_core__list vs, kk_context_t* _ctx) {
  struct kk_climate_dash_change_convert__uncertainty__to__rand_fun3474__t* _self = kk_function_alloc_as(struct kk_climate_dash_change_convert__uncertainty__to__rand_fun3474__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_change_convert__uncertainty__to__rand_fun3474, kk_context());
  _self->vs = vs;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_change_convert__uncertainty__to__rand_fun3478__t {
  struct kk_function_s _base;
  size_t i0_2778;
};
static kk_box_t kk_climate_dash_change_convert__uncertainty__to__rand_fun3478(kk_function_t _fself, kk_function_t _b_2942, kk_box_t _b_2943, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change_new_convert__uncertainty__to__rand_fun3478(size_t i0_2778, kk_context_t* _ctx) {
  struct kk_climate_dash_change_convert__uncertainty__to__rand_fun3478__t* _self = kk_function_alloc_as(struct kk_climate_dash_change_convert__uncertainty__to__rand_fun3478__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_change_convert__uncertainty__to__rand_fun3478, kk_context());
  _self->i0_2778 = i0_2778;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_change_convert__uncertainty__to__rand_fun3478(kk_function_t _fself, kk_function_t _b_2942, kk_box_t _b_2943, kk_context_t* _ctx) {
  struct kk_climate_dash_change_convert__uncertainty__to__rand_fun3478__t* _self = kk_function_as(struct kk_climate_dash_change_convert__uncertainty__to__rand_fun3478__t*, _fself);
  size_t i0_2778 = _self->i0_2778; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i0_2778, _b_2942, _b_2943, _ctx);
}


// lift anonymous function
struct kk_climate_dash_change_convert__uncertainty__to__rand_fun3480__t {
  struct kk_function_s _base;
};
static kk_box_t kk_climate_dash_change_convert__uncertainty__to__rand_fun3480(kk_function_t _fself, kk_box_t _b_2953, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change_new_convert__uncertainty__to__rand_fun3480(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_climate_dash_change_convert__uncertainty__to__rand_fun3480, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_climate_dash_change_convert__uncertainty__to__rand_fun3480(kk_function_t _fself, kk_box_t _b_2953, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x3481;
  double _x3482 = kk_double_unbox(_b_2953, _ctx); /*double*/
  _x3481 = kk_climate_dash_change__mlift2750_convert__uncertainty__to__rand(_x3482, _ctx); /*double*/
  return kk_double_box(_x3481, _ctx);
}
static kk_box_t kk_climate_dash_change_convert__uncertainty__to__rand_fun3474(kk_function_t _fself, kk_integer_t _b_2958, kk_context_t* _ctx) {
  struct kk_climate_dash_change_convert__uncertainty__to__rand_fun3474__t* _self = kk_function_as(struct kk_climate_dash_change_convert__uncertainty__to__rand_fun3474__t*, _fself);
  kk_std_core__list vs = _self->vs; /* effects-and-types/row_vector */
  kk_drop_match(_self, {kk_std_core__list_dup(vs);}, {}, _ctx)
  double _x3475;
  double x_2776;
  size_t i0_2778 = ((size_t)0); /*std/core/hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i0_2778,kk_context()); /*std/core/hnd/evv<<exn,effects-and-types/sample>>*/;
  double y;
  kk_box_t _x3476 = kk_exn_dash_get_exn_get(vs, _b_2958, _ctx); /*3*/
  y = kk_double_unbox(_x3476, _ctx); /*double*/
  kk_unit_t __w_l713_c9 = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x3477 = kk_std_core_hnd_yield_cont(kk_climate_dash_change_new_convert__uncertainty__to__rand_fun3478(i0_2778, _ctx), _ctx); /*3*/
    x_2776 = kk_double_unbox(_x3477, _ctx); /*double*/
  }
  else {
    x_2776 = y; /*double*/
  }
  if (kk_yielding(kk_context())) {
    kk_box_t _x3479 = kk_std_core_hnd_yield_extend(kk_climate_dash_change_new_convert__uncertainty__to__rand_fun3480(_ctx), _ctx); /*2*/
    _x3475 = kk_double_unbox(_x3479, _ctx); /*double*/
  }
  else {
    _x3475 = kk_climate_dash_change__mlift2750_convert__uncertainty__to__rand(x_2776, _ctx); /*double*/
  }
  return kk_double_box(_x3475, _ctx);
}

kk_std_core__list kk_climate_dash_change_convert__uncertainty__to__rand(kk_std_core__list vs, kk_context_t* _ctx) { /* (vs : effects-and-types/row_vector) -> <exn,effects-and-types/sample> effects-and-types/row_vector */ 
  kk_integer_t hi_2774;
  kk_integer_t _x3472;
  kk_std_core__list _x3473 = kk_std_core__list_dup(vs); /*effects-and-types/row_vector*/
  _x3472 = kk_std_core_length_1(_x3473, _ctx); /*int*/
  hi_2774 = kk_integer_sub(_x3472,(kk_integer_from_small(1)),kk_context()); /*int*/
  return kk_std_core__lift21054_list_1(kk_climate_dash_change_new_convert__uncertainty__to__rand_fun3474(vs, _ctx), kk_integer_from_small(0), hi_2774, kk_std_core__new_Nil(_ctx), _ctx);
}
extern double kk_climate_dash_change_mult__thunk_fun3483(kk_function_t _fself, double v, kk_context_t* _ctx) {
  struct kk_climate_dash_change_mult__thunk_fun3483__t* _self = kk_function_as(struct kk_climate_dash_change_mult__thunk_fun3483__t*, _fself);
  double x = _self->x; /* double */
  kk_drop_match(_self, {;}, {}, _ctx)
  return (x * v);
}
extern kk_box_t kk_climate_dash_change_multivariate__gaussian_fun3484(kk_function_t _fself, kk_integer_t _b_2969, kk_context_t* _ctx) {
  struct kk_climate_dash_change_multivariate__gaussian_fun3484__t* _self = kk_function_as(struct kk_climate_dash_change_multivariate__gaussian_fun3484__t*, _fself);
  double mean = _self->mean; /* double */
  double std__dev = _self->std__dev; /* double */
  kk_drop_match(_self, {;;}, {}, _ctx)
  kk_integer_drop(_b_2969, _ctx);
  double _x3485 = kk_model_dash_resources_normal(mean, std__dev, _ctx); /*double*/
  return kk_double_box(_x3485, _ctx);
}


// lift anonymous function
struct kk_climate_dash_change_plus_fun3509__t {
  struct kk_function_s _base;
};
static kk_box_t kk_climate_dash_change_plus_fun3509(kk_function_t _fself, kk_box_t _b_2987, kk_box_t _b_2988, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change_new_plus_fun3509(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_climate_dash_change_plus_fun3509, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_climate_dash_change_plus_fun3509(kk_function_t _fself, kk_box_t _b_2987, kk_box_t _b_2988, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x3510;
  double _x3511 = kk_double_unbox(_b_2987, _ctx); /*double*/
  double _x3512 = kk_double_unbox(_b_2988, _ctx); /*double*/
  _x3510 = (_x3511 + _x3512); /*double*/
  return kk_double_box(_x3510, _ctx);
}

kk_std_core__list kk_climate_dash_change_plus(kk_std_core__list xs, kk_std_core__list ys, kk_context_t* _ctx) { /* (xs : effects-and-types/row_vector, ys : effects-and-types/row_vector) -> exn effects-and-types/row_vector */ 
  bool _match_3458;
  kk_integer_t _x3486;
  kk_std_core__list _x3487 = kk_std_core__list_dup(xs); /*effects-and-types/row_vector*/
  _x3486 = kk_std_core_length_1(_x3487, _ctx); /*int*/
  kk_integer_t _x3488;
  kk_std_core__list _x3489 = kk_std_core__list_dup(ys); /*effects-and-types/row_vector*/
  _x3488 = kk_std_core_length_1(_x3489, _ctx); /*int*/
  _match_3458 = kk_integer_neq(_x3486,_x3488,kk_context()); /*bool*/
  if (_match_3458) {
    kk_string_t message_2785;
    kk_string_t _x3490;
    kk_define_string_literal(, _s3491, 38, "AdditionError: Lengths are not equal! ")
    _x3490 = kk_string_dup(_s3491); /*string*/
    kk_string_t _x3492;
    kk_string_t _x3493;
    kk_integer_t _x3494 = kk_std_core_length_1(xs, _ctx); /*int*/
    _x3493 = kk_std_core_show(_x3494, _ctx); /*string*/
    kk_string_t _x3495;
    kk_string_t _x3496;
    kk_define_string_literal(, _s3497, 4, " vs ")
    _x3496 = kk_string_dup(_s3497); /*string*/
    kk_string_t _x3498;
    kk_integer_t _x3499 = kk_std_core_length_1(ys, _ctx); /*int*/
    _x3498 = kk_std_core_show(_x3499, _ctx); /*string*/
    _x3495 = kk_std_core__lp__plus__plus__1_rp_(_x3496, _x3498, _ctx); /*string*/
    _x3492 = kk_std_core__lp__plus__plus__1_rp_(_x3493, _x3495, _ctx); /*string*/
    message_2785 = kk_std_core__lp__plus__plus__1_rp_(_x3490, _x3492, _ctx); /*string*/
    kk_std_core__exception exn_21565;
    kk_std_core__exception_info _x3500;
    kk_std_core_types__optional _x3501 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/
    if (kk_std_core_types__is_Optional(_x3501)) {
      kk_box_t _box_x2975 = _x3501._cons.Optional.value;
      kk_std_core__exception_info _info_14279 = kk_std_core__exception_info_unbox(_box_x2975, NULL);
      _x3500 = _info_14279; /*exception-info*/
      goto _match3502;
    }
    _x3500 = kk_std_core__new_ExnError(_ctx); /*exception-info*/
    _match3502: ;
    exn_21565 = kk_std_core__new_Exception(message_2785, _x3500, _ctx); /*exception*/
    kk_std_core_hnd__ev ev_21566;
    size_t _x3504 = ((size_t)0); /*size_t*/
    ev_21566 = kk_evv_at(_x3504,kk_context()); /*std/core/hnd/ev<.hnd-exn>*/
    kk_box_t _x3505;
    struct kk_std_core_hnd_Ev* _con3506 = kk_std_core_hnd__as_Ev(ev_21566);
    kk_std_core_hnd__marker m = _con3506->marker;
    kk_box_t _box_x2976 = _con3506->hnd;
    kk_std_core__hnd_exn h = kk_std_core__hnd_exn_unbox(_box_x2976, NULL);
    kk_std_core__hnd_exn_dup(h);
    kk_std_core_hnd__clause1 _match_3459;
    struct kk_std_core__Hnd_exn* _con3508 = kk_std_core__as_Hnd_exn(h);
    kk_std_core_hnd__clause1 except_throw_exn = _con3508->except_throw_exn;
    if (kk_std_core__hnd_exn_is_unique(h)) {
      kk_std_core__hnd_exn_free(h);
    }
    else {
      kk_std_core_hnd__clause1_dup(except_throw_exn);
      kk_std_core__hnd_exn_decref(h, _ctx);
    }
    _match_3459 = except_throw_exn; /*forall<a> std/core/hnd/clause1<exception,a,.hnd-exn,6,7>*/
    kk_function_t _fun_unbox_x2980 = _match_3459.clause;
    _x3505 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x2980, (_fun_unbox_x2980, m, ev_21566, kk_std_core__exception_box(exn_21565, _ctx), _ctx)); /*11*/
    return kk_std_core__list_unbox(_x3505, _ctx);
  }
  return kk_std_core_zipwith(xs, ys, kk_climate_dash_change_new_plus_fun3509(_ctx), _ctx);
}


// lift anonymous function
struct kk_climate_dash_change_score__thunk_fun3513__t {
  struct kk_function_s _base;
  double score__std__dev;
};
static kk_unit_t kk_climate_dash_change_score__thunk_fun3513(kk_function_t _fself, double true__val, double pred__val, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change_new_score__thunk_fun3513(double score__std__dev, kk_context_t* _ctx) {
  struct kk_climate_dash_change_score__thunk_fun3513__t* _self = kk_function_alloc_as(struct kk_climate_dash_change_score__thunk_fun3513__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_change_score__thunk_fun3513, kk_context());
  _self->score__std__dev = score__std__dev;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_change_score__thunk_fun3515__t {
  struct kk_function_s _base;
};
static kk_box_t kk_climate_dash_change_score__thunk_fun3515(kk_function_t _fself, kk_box_t _b_2999, kk_box_t _b_3000, kk_box_t _b_3001, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change_new_score__thunk_fun3515(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_climate_dash_change_score__thunk_fun3515, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_climate_dash_change_score__thunk_fun3515(kk_function_t _fself, kk_box_t _b_2999, kk_box_t _b_3000, kk_box_t _b_3001, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_effects_dash_and_dash_types__exp _x3516;
  double _x3517 = kk_double_unbox(_b_2999, _ctx); /*double*/
  double _x3518 = kk_double_unbox(_b_3000, _ctx); /*double*/
  double _x3519 = kk_double_unbox(_b_3001, _ctx); /*double*/
  _x3516 = kk_model_dash_resources_normal__pdf(_x3517, _x3518, _x3519, _ctx); /*effects-and-types/exp*/
  return kk_effects_dash_and_dash_types__exp_box(_x3516, _ctx);
}


// lift anonymous function
struct kk_climate_dash_change_score__thunk_fun3522__t {
  struct kk_function_s _base;
  size_t i_2787;
};
static kk_box_t kk_climate_dash_change_score__thunk_fun3522(kk_function_t _fself, kk_function_t _b_3011, kk_box_t _b_3012, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change_new_score__thunk_fun3522(size_t i_2787, kk_context_t* _ctx) {
  struct kk_climate_dash_change_score__thunk_fun3522__t* _self = kk_function_alloc_as(struct kk_climate_dash_change_score__thunk_fun3522__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_change_score__thunk_fun3522, kk_context());
  _self->i_2787 = i_2787;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_change_score__thunk_fun3522(kk_function_t _fself, kk_function_t _b_3011, kk_box_t _b_3012, kk_context_t* _ctx) {
  struct kk_climate_dash_change_score__thunk_fun3522__t* _self = kk_function_as(struct kk_climate_dash_change_score__thunk_fun3522__t*, _fself);
  size_t i_2787 = _self->i_2787; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_2787, _b_3011, _b_3012, _ctx);
}
static kk_unit_t kk_climate_dash_change_score__thunk_fun3513(kk_function_t _fself, double true__val, double pred__val, kk_context_t* _ctx) {
  struct kk_climate_dash_change_score__thunk_fun3513__t* _self = kk_function_as(struct kk_climate_dash_change_score__thunk_fun3513__t*, _fself);
  double score__std__dev = _self->score__std__dev; /* double */
  kk_drop_match(_self, {;}, {}, _ctx)
  kk_effects_dash_and_dash_types__exp _x1;
  kk_box_t _x3514 = kk_std_core_hnd__open_none3(kk_climate_dash_change_new_score__thunk_fun3515(_ctx), kk_double_box(pred__val, _ctx), kk_double_box(score__std__dev, _ctx), kk_double_box(true__val, _ctx), _ctx); /*4*/
  _x1 = kk_effects_dash_and_dash_types__exp_unbox(_x3514, _ctx); /*effects-and-types/exp*/
  size_t i_2787;
  kk_std_core_hnd__htag _x3520 = kk_std_core_hnd__htag_dup(kk_effects_dash_and_dash_types__tag_score); /*std/core/hnd/htag<effects-and-types/.hnd-score>*/
  i_2787 = kk_std_core_hnd__evv_index(_x3520, _ctx); /*std/core/hnd/ev-index*/
  kk_evv_t w = kk_evv_swap_create1(i_2787,kk_context()); /*std/core/hnd/evv<<effects-and-types/score|1127>>*/;
  kk_unit_t y = kk_Unit;
  kk_effects_dash_and_dash_types_score(_x1, _ctx);
  kk_unit_t __w_l696_c9 = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x3521 = kk_std_core_hnd_yield_cont(kk_climate_dash_change_new_score__thunk_fun3522(i_2787, _ctx), _ctx); /*3*/
    return kk_unit_unbox(_x3521);
  }
  return y;
}

kk_function_t kk_climate_dash_change_score__thunk(double score__std__dev, kk_context_t* _ctx) { /* forall<e> (score_std_dev : double) -> ((true_val : double, pred_val : double) -> <effects-and-types/score|e> ()) */ 
  return kk_climate_dash_change_new_score__thunk_fun3513(score__std__dev, _ctx);
}
extern kk_box_t kk_climate_dash_change_mult_fun3523(kk_function_t _fself, kk_box_t _b_3023, kk_context_t* _ctx) {
  struct kk_climate_dash_change_mult_fun3523__t* _self = kk_function_as(struct kk_climate_dash_change_mult_fun3523__t*, _fself);
  kk_function_t _b_3025_3022 = _self->_b_3025_3022; /* (v : double) -> double */
  kk_drop_match(_self, {kk_function_dup(_b_3025_3022);}, {}, _ctx)
  double _x3524;
  double _x3525 = kk_double_unbox(_b_3023, _ctx); /*double*/
  _x3524 = kk_function_call(double, (kk_function_t, double, kk_context_t*), _b_3025_3022, (_b_3025_3022, _x3525, _ctx)); /*double*/
  return kk_double_box(_x3524, _ctx);
}


// lift anonymous function
struct kk_climate_dash_change_score__predictions_fun3550__t {
  struct kk_function_s _base;
  size_t i_2790;
};
static kk_box_t kk_climate_dash_change_score__predictions_fun3550(kk_function_t _fself, kk_function_t _b_3043, kk_box_t _b_3044, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change_new_score__predictions_fun3550(size_t i_2790, kk_context_t* _ctx) {
  struct kk_climate_dash_change_score__predictions_fun3550__t* _self = kk_function_alloc_as(struct kk_climate_dash_change_score__predictions_fun3550__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_change_score__predictions_fun3550, kk_context());
  _self->i_2790 = i_2790;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_change_score__predictions_fun3550(kk_function_t _fself, kk_function_t _b_3043, kk_box_t _b_3044, kk_context_t* _ctx) {
  struct kk_climate_dash_change_score__predictions_fun3550__t* _self = kk_function_as(struct kk_climate_dash_change_score__predictions_fun3550__t*, _fself);
  size_t i_2790 = _self->i_2790; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_2790, _b_3043, _b_3044, _ctx);
}


// lift anonymous function
struct kk_climate_dash_change_score__predictions_fun3551__t {
  struct kk_function_s _base;
  kk_function_t _b_3060_3048;
};
static kk_box_t kk_climate_dash_change_score__predictions_fun3551(kk_function_t _fself, kk_box_t _b_3049, kk_box_t _b_3050, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change_new_score__predictions_fun3551(kk_function_t _b_3060_3048, kk_context_t* _ctx) {
  struct kk_climate_dash_change_score__predictions_fun3551__t* _self = kk_function_alloc_as(struct kk_climate_dash_change_score__predictions_fun3551__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_change_score__predictions_fun3551, kk_context());
  _self->_b_3060_3048 = _b_3060_3048;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_change_score__predictions_fun3551(kk_function_t _fself, kk_box_t _b_3049, kk_box_t _b_3050, kk_context_t* _ctx) {
  struct kk_climate_dash_change_score__predictions_fun3551__t* _self = kk_function_as(struct kk_climate_dash_change_score__predictions_fun3551__t*, _fself);
  kk_function_t _b_3060_3048 = _self->_b_3060_3048; /* (true_val : double, pred_val : double) -> <effects-and-types/score,exn> () */
  kk_drop_match(_self, {kk_function_dup(_b_3060_3048);}, {}, _ctx)
  kk_unit_t _x3552 = kk_Unit;
  double _x3553 = kk_double_unbox(_b_3049, _ctx); /*double*/
  double _x3554 = kk_double_unbox(_b_3050, _ctx); /*double*/
  kk_function_call(kk_unit_t, (kk_function_t, double, double, kk_context_t*), _b_3060_3048, (_b_3060_3048, _x3553, _x3554, _ctx));
  return kk_unit_box(_x3552);
}

kk_std_core__list kk_climate_dash_change_score__predictions(kk_std_core__list true__values, kk_std_core__list predicted__values, double score__std__dev, kk_context_t* _ctx) { /* (true_values : effects-and-types/row_vector, predicted_values : effects-and-types/row_vector, score_std_dev : double) -> <exn,effects-and-types/score> list<()> */ 
  bool _match_3453;
  kk_integer_t _x3526;
  kk_std_core__list _x3527 = kk_std_core__list_dup(true__values); /*effects-and-types/row_vector*/
  _x3526 = kk_std_core_length_1(_x3527, _ctx); /*int*/
  kk_integer_t _x3528;
  kk_std_core__list _x3529 = kk_std_core__list_dup(predicted__values); /*effects-and-types/row_vector*/
  _x3528 = kk_std_core_length_1(_x3529, _ctx); /*int*/
  _match_3453 = kk_integer_neq(_x3526,_x3528,kk_context()); /*bool*/
  if (_match_3453) {
    kk_string_t _x1;
    kk_string_t _x3530;
    kk_define_string_literal(, _s3531, 71, "LengthError: predicted values and true values must be the same length! ")
    _x3530 = kk_string_dup(_s3531); /*string*/
    kk_string_t _x3532;
    kk_string_t _x3533;
    kk_integer_t _x3534 = kk_std_core_length_1(true__values, _ctx); /*int*/
    _x3533 = kk_std_core_show(_x3534, _ctx); /*string*/
    kk_string_t _x3535;
    kk_string_t _x3536;
    kk_define_string_literal(, _s3537, 4, " vs ")
    _x3536 = kk_string_dup(_s3537); /*string*/
    kk_string_t _x3538;
    kk_integer_t _x3539 = kk_std_core_length_1(predicted__values, _ctx); /*int*/
    _x3538 = kk_std_core_show(_x3539, _ctx); /*string*/
    _x3535 = kk_std_core__lp__plus__plus__1_rp_(_x3536, _x3538, _ctx); /*string*/
    _x3532 = kk_std_core__lp__plus__plus__1_rp_(_x3533, _x3535, _ctx); /*string*/
    _x1 = kk_std_core__lp__plus__plus__1_rp_(_x3530, _x3532, _ctx); /*string*/
    size_t i_2790 = ((size_t)0); /*std/core/hnd/ev-index*/;
    kk_evv_t w = kk_evv_swap_create1(i_2790,kk_context()); /*std/core/hnd/evv<<exn,effects-and-types/score>>*/;
    kk_std_core__list y;
    kk_std_core__exception exn_21565;
    kk_std_core__exception_info _x3540;
    kk_std_core_types__optional _x3541 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/
    if (kk_std_core_types__is_Optional(_x3541)) {
      kk_box_t _box_x3026 = _x3541._cons.Optional.value;
      kk_std_core__exception_info _info_14279 = kk_std_core__exception_info_unbox(_box_x3026, NULL);
      _x3540 = _info_14279; /*exception-info*/
      goto _match3542;
    }
    _x3540 = kk_std_core__new_ExnError(_ctx); /*exception-info*/
    _match3542: ;
    exn_21565 = kk_std_core__new_Exception(_x1, _x3540, _ctx); /*exception*/
    kk_std_core_hnd__ev ev_21566;
    size_t _x3544 = ((size_t)0); /*size_t*/
    ev_21566 = kk_evv_at(_x3544,kk_context()); /*std/core/hnd/ev<.hnd-exn>*/
    kk_box_t _x3545;
    struct kk_std_core_hnd_Ev* _con3546 = kk_std_core_hnd__as_Ev(ev_21566);
    kk_std_core_hnd__marker m = _con3546->marker;
    kk_box_t _box_x3027 = _con3546->hnd;
    kk_std_core__hnd_exn h = kk_std_core__hnd_exn_unbox(_box_x3027, NULL);
    kk_std_core__hnd_exn_dup(h);
    kk_std_core_hnd__clause1 _match_3455;
    struct kk_std_core__Hnd_exn* _con3548 = kk_std_core__as_Hnd_exn(h);
    kk_std_core_hnd__clause1 except_throw_exn = _con3548->except_throw_exn;
    if (kk_std_core__hnd_exn_is_unique(h)) {
      kk_std_core__hnd_exn_free(h);
    }
    else {
      kk_std_core_hnd__clause1_dup(except_throw_exn);
      kk_std_core__hnd_exn_decref(h, _ctx);
    }
    _match_3455 = except_throw_exn; /*forall<a> std/core/hnd/clause1<exception,a,.hnd-exn,6,7>*/
    kk_function_t _fun_unbox_x3031 = _match_3455.clause;
    _x3545 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x3031, (_fun_unbox_x3031, m, ev_21566, kk_std_core__exception_box(exn_21565, _ctx), _ctx)); /*11*/
    y = kk_std_core__list_unbox(_x3545, _ctx); /*list<()>*/
    kk_unit_t __w_l713_c9 = kk_Unit;
    kk_evv_set(w,kk_context());
    if (kk_yielding(kk_context())) {
      kk_std_core__list_drop(y, _ctx);
      kk_box_t _x3549 = kk_std_core_hnd_yield_cont(kk_climate_dash_change_new_score__predictions_fun3550(i_2790, _ctx), _ctx); /*3*/
      return kk_std_core__list_unbox(_x3549, _ctx);
    }
    return y;
  }
  kk_function_t _b_3060_3048;
  kk_evv_t w0 = kk_evv_swap_create0(kk_context()); /*std/core/hnd/evv<(<>)>*/;
  kk_function_t x = kk_climate_dash_change_score__thunk(score__std__dev, _ctx); /*(true_val : double, pred_val : double) -> <effects-and-types/score,exn> ()*/;
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w0,kk_context());
  _b_3060_3048 = x; /*(true_val : double, pred_val : double) -> <effects-and-types/score,exn> ()*/
  return kk_std_core_zipwith(true__values, predicted__values, kk_climate_dash_change_new_score__predictions_fun3551(_b_3060_3048, _ctx), _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_climate_dash_change__mlift2751_linear__gaussian__climate__data_fun3557__t {
  struct kk_function_s _base;
  size_t i_2796;
};
static kk_box_t kk_climate_dash_change__mlift2751_linear__gaussian__climate__data_fun3557(kk_function_t _fself, kk_function_t _b_3070, kk_box_t _b_3071, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change__new_mlift2751_linear__gaussian__climate__data_fun3557(size_t i_2796, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2751_linear__gaussian__climate__data_fun3557__t* _self = kk_function_alloc_as(struct kk_climate_dash_change__mlift2751_linear__gaussian__climate__data_fun3557__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_change__mlift2751_linear__gaussian__climate__data_fun3557, kk_context());
  _self->i_2796 = i_2796;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_change__mlift2751_linear__gaussian__climate__data_fun3557(kk_function_t _fself, kk_function_t _b_3070, kk_box_t _b_3071, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2751_linear__gaussian__climate__data_fun3557__t* _self = kk_function_as(struct kk_climate_dash_change__mlift2751_linear__gaussian__climate__data_fun3557__t*, _fself);
  size_t i_2796 = _self->i_2796; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_2796, _b_3070, _b_3071, _ctx);
}

double kk_climate_dash_change__mlift2751_linear__gaussian__climate__data(kk_integer_t i0, kk_std_core__list _y_31, kk_context_t* _ctx) { /* forall<h> (i0 : int, list<double>) -> <local<h>,exn,effects-and-types/sample,effects-and-types/score> double */ 
  size_t i_2796 = ((size_t)0); /*std/core/hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_2796,kk_context()); /*std/core/hnd/evv<<exn,local<2724>,effects-and-types/sample,effects-and-types/score>>*/;
  double y;
  kk_box_t _x3555 = kk_exn_dash_get_exn_get(_y_31, i0, _ctx); /*3*/
  y = kk_double_unbox(_x3555, _ctx); /*double*/
  kk_unit_t __w_l713_c9 = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x3556 = kk_std_core_hnd_yield_cont(kk_climate_dash_change__new_mlift2751_linear__gaussian__climate__data_fun3557(i_2796, _ctx), _ctx); /*3*/
    return kk_double_unbox(_x3556, _ctx);
  }
  return y;
}
 
// monadic lift

kk_unit_t kk_climate_dash_change__mlift2752_linear__gaussian__climate__data(kk_std_core__list wild__0, kk_context_t* _ctx) { /* forall<h> (wild_0 : list<()>) -> <exn,effects-and-types/score,local<h>,effects-and-types/sample> () */ 
  kk_std_core__list_drop(wild__0, _ctx);
  kk_Unit; return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_climate_dash_change__mlift2753_linear__gaussian__climate__data_fun3560__t {
  struct kk_function_s _base;
};
static kk_box_t kk_climate_dash_change__mlift2753_linear__gaussian__climate__data_fun3560(kk_function_t _fself, kk_box_t _b_3089, kk_box_t _b_3090, kk_box_t _b_3091, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change__new_mlift2753_linear__gaussian__climate__data_fun3560(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_climate_dash_change__mlift2753_linear__gaussian__climate__data_fun3560, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_climate_dash_change__mlift2753_linear__gaussian__climate__data_fun3560(kk_function_t _fself, kk_box_t _b_3089, kk_box_t _b_3090, kk_box_t _b_3091, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core__list _x3561;
  kk_std_core__list _x3562 = kk_std_core__list_unbox(_b_3089, _ctx); /*effects-and-types/row_vector*/
  kk_std_core__list _x3563 = kk_std_core__list_unbox(_b_3090, _ctx); /*effects-and-types/row_vector*/
  double _x3564 = kk_double_unbox(_b_3091, _ctx); /*double*/
  _x3561 = kk_climate_dash_change_score__predictions(_x3562, _x3563, _x3564, _ctx); /*list<()>*/
  return kk_std_core__list_box(_x3561, _ctx);
}


// lift anonymous function
struct kk_climate_dash_change__mlift2753_linear__gaussian__climate__data_fun3566__t {
  struct kk_function_s _base;
};
static kk_box_t kk_climate_dash_change__mlift2753_linear__gaussian__climate__data_fun3566(kk_function_t _fself, kk_box_t _b_3102, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change__new_mlift2753_linear__gaussian__climate__data_fun3566(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_climate_dash_change__mlift2753_linear__gaussian__climate__data_fun3566, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_climate_dash_change__mlift2753_linear__gaussian__climate__data_fun3566(kk_function_t _fself, kk_box_t _b_3102, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_unit_t _x3567 = kk_Unit;
  kk_std_core__list _x3568 = kk_std_core__list_unbox(_b_3102, _ctx); /*list<()>*/
  kk_climate_dash_change__mlift2752_linear__gaussian__climate__data(_x3568, _ctx);
  return kk_unit_box(_x3567);
}

kk_unit_t kk_climate_dash_change__mlift2753_linear__gaussian__climate__data(kk_std_core__list month__ys, double score__var, kk_std_core__list predictions, kk_context_t* _ctx) { /* forall<h> (month_ys : effects-and-types/row_vector, score_var : double, predictions : effects-and-types/row_vector) -> <exn,local<h>,effects-and-types/score,effects-and-types/sample> () */ 
  kk_std_core__list x_2800;
  kk_vector_t _b_3092_3084;
  kk_std_core__list _x3558;
  size_t _b_3097_3082 = ((size_t)0); /*std/core/hnd/ev-index*/;
  kk_std_core__list _b_3098_3083;
  size_t _b_3099_3080 = ((size_t)2); /*std/core/hnd/ev-index*/;
  _b_3098_3083 = kk_std_core__new_Cons(kk_reuse_null, kk_size_box(_b_3099_3080, _ctx), kk_std_core__new_Nil(_ctx), _ctx); /*list<std/core/hnd/ev-index>*/
  _x3558 = kk_std_core__new_Cons(kk_reuse_null, kk_size_box(_b_3097_3082, _ctx), _b_3098_3083, _ctx); /*list<0>*/
  _b_3092_3084 = kk_std_core_unvlist(_x3558, _ctx); /*vector<std/core/hnd/ev-index>*/
  kk_box_t _x3559 = kk_std_core_hnd__open3(_b_3092_3084, kk_climate_dash_change__new_mlift2753_linear__gaussian__climate__data_fun3560(_ctx), kk_std_core__list_box(month__ys, _ctx), kk_std_core__list_box(predictions, _ctx), kk_double_box(score__var, _ctx), _ctx); /*4*/
  x_2800 = kk_std_core__list_unbox(_x3559, _ctx); /*list<()>*/
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_2800, _ctx);
    kk_box_t _x3565 = kk_std_core_hnd_yield_extend(kk_climate_dash_change__new_mlift2753_linear__gaussian__climate__data_fun3566(_ctx), _ctx); /*2*/
    kk_unit_unbox(_x3565); return kk_Unit;
  }
  kk_climate_dash_change__mlift2752_linear__gaussian__climate__data(x_2800, _ctx); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_climate_dash_change__mlift2754_linear__gaussian__climate__data_fun3570__t {
  struct kk_function_s _base;
};
static kk_box_t kk_climate_dash_change__mlift2754_linear__gaussian__climate__data_fun3570(kk_function_t _fself, kk_box_t _b_3108, kk_box_t _b_3109, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change__new_mlift2754_linear__gaussian__climate__data_fun3570(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_climate_dash_change__mlift2754_linear__gaussian__climate__data_fun3570, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_climate_dash_change__mlift2754_linear__gaussian__climate__data_fun3570(kk_function_t _fself, kk_box_t _b_3108, kk_box_t _b_3109, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core__list _x3571;
  double _x3572 = kk_double_unbox(_b_3108, _ctx); /*double*/
  kk_std_core__list _x3573 = kk_std_core__list_unbox(_b_3109, _ctx); /*effects-and-types/row_vector*/
  _x3571 = kk_climate_dash_change_mult(_x3572, _x3573, _ctx); /*effects-and-types/row_vector*/
  return kk_std_core__list_box(_x3571, _ctx);
}


// lift anonymous function
struct kk_climate_dash_change__mlift2754_linear__gaussian__climate__data_fun3575__t {
  struct kk_function_s _base;
  size_t i_2804;
};
static kk_box_t kk_climate_dash_change__mlift2754_linear__gaussian__climate__data_fun3575(kk_function_t _fself, kk_function_t _b_3118, kk_box_t _b_3119, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change__new_mlift2754_linear__gaussian__climate__data_fun3575(size_t i_2804, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2754_linear__gaussian__climate__data_fun3575__t* _self = kk_function_alloc_as(struct kk_climate_dash_change__mlift2754_linear__gaussian__climate__data_fun3575__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_change__mlift2754_linear__gaussian__climate__data_fun3575, kk_context());
  _self->i_2804 = i_2804;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_change__mlift2754_linear__gaussian__climate__data_fun3575(kk_function_t _fself, kk_function_t _b_3118, kk_box_t _b_3119, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2754_linear__gaussian__climate__data_fun3575__t* _self = kk_function_as(struct kk_climate_dash_change__mlift2754_linear__gaussian__climate__data_fun3575__t*, _fself);
  size_t i_2804 = _self->i_2804; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_2804, _b_3118, _b_3119, _ctx);
}


// lift anonymous function
struct kk_climate_dash_change__mlift2754_linear__gaussian__climate__data_fun3577__t {
  struct kk_function_s _base;
  kk_std_core__list month__ys;
  double score__var;
};
static kk_box_t kk_climate_dash_change__mlift2754_linear__gaussian__climate__data_fun3577(kk_function_t _fself, kk_box_t _b_3129, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change__new_mlift2754_linear__gaussian__climate__data_fun3577(kk_std_core__list month__ys, double score__var, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2754_linear__gaussian__climate__data_fun3577__t* _self = kk_function_alloc_as(struct kk_climate_dash_change__mlift2754_linear__gaussian__climate__data_fun3577__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_change__mlift2754_linear__gaussian__climate__data_fun3577, kk_context());
  _self->month__ys = month__ys;
  _self->score__var = score__var;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_change__mlift2754_linear__gaussian__climate__data_fun3577(kk_function_t _fself, kk_box_t _b_3129, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2754_linear__gaussian__climate__data_fun3577__t* _self = kk_function_as(struct kk_climate_dash_change__mlift2754_linear__gaussian__climate__data_fun3577__t*, _fself);
  kk_std_core__list month__ys = _self->month__ys; /* effects-and-types/row_vector */
  double score__var = _self->score__var; /* double */
  kk_drop_match(_self, {kk_std_core__list_dup(month__ys);;}, {}, _ctx)
  kk_unit_t _x3578 = kk_Unit;
  kk_std_core__list _x3579 = kk_std_core__list_unbox(_b_3129, _ctx); /*effects-and-types/row_vector*/
  kk_climate_dash_change__mlift2753_linear__gaussian__climate__data(month__ys, score__var, _x3579, _ctx);
  return kk_unit_box(_x3578);
}

kk_unit_t kk_climate_dash_change__mlift2754_linear__gaussian__climate__data(kk_std_core__list c__row, kk_std_core__list month__ys, double score__var, kk_std_core__list v__row, double _y_27, kk_context_t* _ctx) { /* forall<h> (c_row : list<double>, month_ys : effects-and-types/row_vector, score_var : double, v_row : effects-and-types/row_vector, double) -> <exn,local<h>,effects-and-types/score,effects-and-types/sample> () */ 
  kk_std_core__list x_2802;
  kk_std_core__list _x17;
  kk_box_t _x3569 = kk_std_core_hnd__open_none2(kk_climate_dash_change__new_mlift2754_linear__gaussian__climate__data_fun3570(_ctx), kk_double_box(_y_27, _ctx), kk_std_core__list_box(c__row, _ctx), _ctx); /*3*/
  _x17 = kk_std_core__list_unbox(_x3569, _ctx); /*effects-and-types/row_vector*/
  size_t i_2804 = ((size_t)0); /*std/core/hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_2804,kk_context()); /*std/core/hnd/evv<<exn,local<2724>,effects-and-types/score,effects-and-types/sample>>*/;
  kk_std_core__list y = kk_climate_dash_change_plus(_x17, v__row, _ctx); /*effects-and-types/row_vector*/;
  kk_unit_t __w_l713_c9 = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(y, _ctx);
    kk_box_t _x3574 = kk_std_core_hnd_yield_cont(kk_climate_dash_change__new_mlift2754_linear__gaussian__climate__data_fun3575(i_2804, _ctx), _ctx); /*3*/
    x_2802 = kk_std_core__list_unbox(_x3574, _ctx); /*effects-and-types/row_vector*/
  }
  else {
    x_2802 = y; /*effects-and-types/row_vector*/
  }
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_2802, _ctx);
    kk_box_t _x3576 = kk_std_core_hnd_yield_extend(kk_climate_dash_change__new_mlift2754_linear__gaussian__climate__data_fun3577(month__ys, score__var, _ctx), _ctx); /*2*/
    kk_unit_unbox(_x3576); return kk_Unit;
  }
  kk_climate_dash_change__mlift2753_linear__gaussian__climate__data(month__ys, score__var, x_2802, _ctx); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_climate_dash_change__mlift2755_linear__gaussian__climate__data_fun3582__t {
  struct kk_function_s _base;
  size_t i0_2810;
};
static kk_box_t kk_climate_dash_change__mlift2755_linear__gaussian__climate__data_fun3582(kk_function_t _fself, kk_function_t _b_3141, kk_box_t _b_3142, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change__new_mlift2755_linear__gaussian__climate__data_fun3582(size_t i0_2810, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2755_linear__gaussian__climate__data_fun3582__t* _self = kk_function_alloc_as(struct kk_climate_dash_change__mlift2755_linear__gaussian__climate__data_fun3582__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_change__mlift2755_linear__gaussian__climate__data_fun3582, kk_context());
  _self->i0_2810 = i0_2810;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_change__mlift2755_linear__gaussian__climate__data_fun3582(kk_function_t _fself, kk_function_t _b_3141, kk_box_t _b_3142, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2755_linear__gaussian__climate__data_fun3582__t* _self = kk_function_as(struct kk_climate_dash_change__mlift2755_linear__gaussian__climate__data_fun3582__t*, _fself);
  size_t i0_2810 = _self->i0_2810; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i0_2810, _b_3141, _b_3142, _ctx);
}


// lift anonymous function
struct kk_climate_dash_change__mlift2755_linear__gaussian__climate__data_fun3584__t {
  struct kk_function_s _base;
  kk_std_core__list c__row;
  kk_std_core__list month__ys;
  kk_std_core__list v__row;
  double score__var;
};
static kk_box_t kk_climate_dash_change__mlift2755_linear__gaussian__climate__data_fun3584(kk_function_t _fself, kk_box_t _b_3152, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change__new_mlift2755_linear__gaussian__climate__data_fun3584(kk_std_core__list c__row, kk_std_core__list month__ys, kk_std_core__list v__row, double score__var, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2755_linear__gaussian__climate__data_fun3584__t* _self = kk_function_alloc_as(struct kk_climate_dash_change__mlift2755_linear__gaussian__climate__data_fun3584__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_change__mlift2755_linear__gaussian__climate__data_fun3584, kk_context());
  _self->c__row = c__row;
  _self->month__ys = month__ys;
  _self->v__row = v__row;
  _self->score__var = score__var;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_change__mlift2755_linear__gaussian__climate__data_fun3584(kk_function_t _fself, kk_box_t _b_3152, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2755_linear__gaussian__climate__data_fun3584__t* _self = kk_function_as(struct kk_climate_dash_change__mlift2755_linear__gaussian__climate__data_fun3584__t*, _fself);
  kk_std_core__list c__row = _self->c__row; /* list<double> */
  kk_std_core__list month__ys = _self->month__ys; /* effects-and-types/row_vector */
  kk_std_core__list v__row = _self->v__row; /* effects-and-types/row_vector */
  double score__var = _self->score__var; /* double */
  kk_drop_match(_self, {kk_std_core__list_dup(c__row);kk_std_core__list_dup(month__ys);kk_std_core__list_dup(v__row);;}, {}, _ctx)
  kk_unit_t _x3585 = kk_Unit;
  double _x3586 = kk_double_unbox(_b_3152, _ctx); /*double*/
  kk_climate_dash_change__mlift2754_linear__gaussian__climate__data(c__row, month__ys, score__var, v__row, _x3586, _ctx);
  return kk_unit_box(_x3585);
}

kk_unit_t kk_climate_dash_change__mlift2755_linear__gaussian__climate__data(kk_std_core__list c__row, kk_integer_t i, kk_std_core__list month__ys, double score__var, kk_std_core__list v__row, kk_std_core__list _y_26, kk_context_t* _ctx) { /* forall<h> (c_row : list<double>, i : int, month_ys : effects-and-types/row_vector, score_var : double, v_row : effects-and-types/row_vector, list<double>) -> <local<h>,exn,effects-and-types/score,effects-and-types/sample> () */ 
  double x_2808;
  size_t i0_2810 = ((size_t)0); /*std/core/hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i0_2810,kk_context()); /*std/core/hnd/evv<<exn,local<2724>,effects-and-types/score,effects-and-types/sample>>*/;
  double y;
  kk_box_t _x3580 = kk_exn_dash_get_exn_get(_y_26, i, _ctx); /*3*/
  y = kk_double_unbox(_x3580, _ctx); /*double*/
  kk_unit_t __w_l713_c9 = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x3581 = kk_std_core_hnd_yield_cont(kk_climate_dash_change__new_mlift2755_linear__gaussian__climate__data_fun3582(i0_2810, _ctx), _ctx); /*3*/
    x_2808 = kk_double_unbox(_x3581, _ctx); /*double*/
  }
  else {
    x_2808 = y; /*double*/
  }
  if (kk_yielding(kk_context())) {
    kk_box_t _x3583 = kk_std_core_hnd_yield_extend(kk_climate_dash_change__new_mlift2755_linear__gaussian__climate__data_fun3584(c__row, month__ys, v__row, score__var, _ctx), _ctx); /*2*/
    kk_unit_unbox(_x3583); return kk_Unit;
  }
  kk_climate_dash_change__mlift2754_linear__gaussian__climate__data(c__row, month__ys, score__var, v__row, x_2808, _ctx); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_climate_dash_change__mlift2756_linear__gaussian__climate__data_fun3589__t {
  struct kk_function_s _base;
  kk_std_core__list c__row;
  kk_integer_t i;
  kk_std_core__list month__ys;
  kk_std_core__list v__row;
  double score__var;
};
static kk_box_t kk_climate_dash_change__mlift2756_linear__gaussian__climate__data_fun3589(kk_function_t _fself, kk_box_t _b_3158, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change__new_mlift2756_linear__gaussian__climate__data_fun3589(kk_std_core__list c__row, kk_integer_t i, kk_std_core__list month__ys, kk_std_core__list v__row, double score__var, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2756_linear__gaussian__climate__data_fun3589__t* _self = kk_function_alloc_as(struct kk_climate_dash_change__mlift2756_linear__gaussian__climate__data_fun3589__t, 5, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_change__mlift2756_linear__gaussian__climate__data_fun3589, kk_context());
  _self->c__row = c__row;
  _self->i = i;
  _self->month__ys = month__ys;
  _self->v__row = v__row;
  _self->score__var = score__var;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_change__mlift2756_linear__gaussian__climate__data_fun3589(kk_function_t _fself, kk_box_t _b_3158, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2756_linear__gaussian__climate__data_fun3589__t* _self = kk_function_as(struct kk_climate_dash_change__mlift2756_linear__gaussian__climate__data_fun3589__t*, _fself);
  kk_std_core__list c__row = _self->c__row; /* list<double> */
  kk_integer_t i = _self->i; /* int */
  kk_std_core__list month__ys = _self->month__ys; /* effects-and-types/row_vector */
  kk_std_core__list v__row = _self->v__row; /* effects-and-types/row_vector */
  double score__var = _self->score__var; /* double */
  kk_drop_match(_self, {kk_std_core__list_dup(c__row);kk_integer_dup(i);kk_std_core__list_dup(month__ys);kk_std_core__list_dup(v__row);;}, {}, _ctx)
  kk_unit_t _x3590 = kk_Unit;
  kk_std_core__list _x3591 = kk_std_core__list_unbox(_b_3158, _ctx); /*list<double>*/
  kk_climate_dash_change__mlift2755_linear__gaussian__climate__data(c__row, i, month__ys, score__var, v__row, _x3591, _ctx);
  return kk_unit_box(_x3590);
}

kk_unit_t kk_climate_dash_change__mlift2756_linear__gaussian__climate__data(kk_std_core__list c__row, kk_integer_t i, kk_std_core__list month__ys, double score__var, kk_ref_t x, kk_std_core__list v__row, kk_context_t* _ctx) { /* forall<h> (c_row : list<double>, i : int, month_ys : effects-and-types/row_vector, score_var : double, x : local-var<h,list<double>>, v_row : effects-and-types/row_vector) -> <exn,effects-and-types/sample,local<h>,effects-and-types/score> () */ 
  kk_std_core__list x0_2814;
  kk_box_t _x3587 = (kk_ref_get(x,kk_context())); /*0*/
  x0_2814 = kk_std_core__list_unbox(_x3587, _ctx); /*list<double>*/
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x0_2814, _ctx);
    kk_box_t _x3588 = kk_std_core_hnd_yield_extend(kk_climate_dash_change__new_mlift2756_linear__gaussian__climate__data_fun3589(c__row, i, month__ys, v__row, score__var, _ctx), _ctx); /*2*/
    kk_unit_unbox(_x3588); return kk_Unit;
  }
  kk_climate_dash_change__mlift2755_linear__gaussian__climate__data(c__row, i, month__ys, score__var, v__row, x0_2814, _ctx); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_climate_dash_change__mlift2757_linear__gaussian__climate__data_fun3594__t {
  struct kk_function_s _base;
};
static kk_box_t kk_climate_dash_change__mlift2757_linear__gaussian__climate__data_fun3594(kk_function_t _fself, kk_box_t _b_3168, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change__new_mlift2757_linear__gaussian__climate__data_fun3594(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_climate_dash_change__mlift2757_linear__gaussian__climate__data_fun3594, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_climate_dash_change__mlift2757_linear__gaussian__climate__data_fun3594(kk_function_t _fself, kk_box_t _b_3168, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core__list _x3595;
  kk_std_core__list _x3596 = kk_std_core__list_unbox(_b_3168, _ctx); /*effects-and-types/row_vector*/
  _x3595 = kk_climate_dash_change_convert__uncertainty__to__rand(_x3596, _ctx); /*effects-and-types/row_vector*/
  return kk_std_core__list_box(_x3595, _ctx);
}


// lift anonymous function
struct kk_climate_dash_change__mlift2757_linear__gaussian__climate__data_fun3598__t {
  struct kk_function_s _base;
  kk_std_core__list c__row;
  kk_integer_t i;
  kk_std_core__list month__ys;
  kk_ref_t x;
  double score__var;
};
static kk_box_t kk_climate_dash_change__mlift2757_linear__gaussian__climate__data_fun3598(kk_function_t _fself, kk_box_t _b_3177, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change__new_mlift2757_linear__gaussian__climate__data_fun3598(kk_std_core__list c__row, kk_integer_t i, kk_std_core__list month__ys, kk_ref_t x, double score__var, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2757_linear__gaussian__climate__data_fun3598__t* _self = kk_function_alloc_as(struct kk_climate_dash_change__mlift2757_linear__gaussian__climate__data_fun3598__t, 5, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_change__mlift2757_linear__gaussian__climate__data_fun3598, kk_context());
  _self->c__row = c__row;
  _self->i = i;
  _self->month__ys = month__ys;
  _self->x = x;
  _self->score__var = score__var;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_change__mlift2757_linear__gaussian__climate__data_fun3598(kk_function_t _fself, kk_box_t _b_3177, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2757_linear__gaussian__climate__data_fun3598__t* _self = kk_function_as(struct kk_climate_dash_change__mlift2757_linear__gaussian__climate__data_fun3598__t*, _fself);
  kk_std_core__list c__row = _self->c__row; /* list<double> */
  kk_integer_t i = _self->i; /* int */
  kk_std_core__list month__ys = _self->month__ys; /* effects-and-types/row_vector */
  kk_ref_t x = _self->x; /* local-var<2724,list<double>> */
  double score__var = _self->score__var; /* double */
  kk_drop_match(_self, {kk_std_core__list_dup(c__row);kk_integer_dup(i);kk_std_core__list_dup(month__ys);kk_ref_dup(x);;}, {}, _ctx)
  kk_unit_t _x3599 = kk_Unit;
  kk_std_core__list _x3600 = kk_std_core__list_unbox(_b_3177, _ctx); /*effects-and-types/row_vector*/
  kk_climate_dash_change__mlift2756_linear__gaussian__climate__data(c__row, i, month__ys, score__var, x, _x3600, _ctx);
  return kk_unit_box(_x3599);
}

kk_unit_t kk_climate_dash_change__mlift2757_linear__gaussian__climate__data(kk_integer_t i, kk_std_core__list month__vs, kk_std_core__list month__ys, double score__var, kk_ref_t x, kk_std_core__list c__row, kk_context_t* _ctx) { /* forall<h> (i : int, month_vs : effects-and-types/row_vector, month_ys : effects-and-types/row_vector, score_var : double, x : local-var<h,list<double>>, c_row : list<double>) -> <effects-and-types/sample,exn,local<h>,effects-and-types/score> () */ 
  kk_std_core__list x0_2816;
  kk_vector_t _b_3169_3165;
  kk_std_core__list _x3592;
  size_t _b_3172_3163 = ((size_t)0); /*std/core/hnd/ev-index*/;
  kk_std_core__list _b_3173_3164;
  size_t _b_3174_3161 = ((size_t)1); /*std/core/hnd/ev-index*/;
  _b_3173_3164 = kk_std_core__new_Cons(kk_reuse_null, kk_size_box(_b_3174_3161, _ctx), kk_std_core__new_Nil(_ctx), _ctx); /*list<std/core/hnd/ev-index>*/
  _x3592 = kk_std_core__new_Cons(kk_reuse_null, kk_size_box(_b_3172_3163, _ctx), _b_3173_3164, _ctx); /*list<0>*/
  _b_3169_3165 = kk_std_core_unvlist(_x3592, _ctx); /*vector<std/core/hnd/ev-index>*/
  kk_box_t _x3593 = kk_std_core_hnd__open1(_b_3169_3165, kk_climate_dash_change__new_mlift2757_linear__gaussian__climate__data_fun3594(_ctx), kk_std_core__list_box(month__vs, _ctx), _ctx); /*2*/
  x0_2816 = kk_std_core__list_unbox(_x3593, _ctx); /*effects-and-types/row_vector*/
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x0_2816, _ctx);
    kk_box_t _x3597 = kk_std_core_hnd_yield_extend(kk_climate_dash_change__new_mlift2757_linear__gaussian__climate__data_fun3598(c__row, i, month__ys, x, score__var, _ctx), _ctx); /*2*/
    kk_unit_unbox(_x3597); return kk_Unit;
  }
  kk_climate_dash_change__mlift2756_linear__gaussian__climate__data(c__row, i, month__ys, score__var, x, x0_2816, _ctx); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_climate_dash_change__mlift2758_linear__gaussian__climate__data_fun3602__t {
  struct kk_function_s _base;
  double _x24;
};
static kk_box_t kk_climate_dash_change__mlift2758_linear__gaussian__climate__data_fun3602(kk_function_t _fself, kk_integer_t _b_3184, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change__new_mlift2758_linear__gaussian__climate__data_fun3602(double _x24, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2758_linear__gaussian__climate__data_fun3602__t* _self = kk_function_alloc_as(struct kk_climate_dash_change__mlift2758_linear__gaussian__climate__data_fun3602__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_change__mlift2758_linear__gaussian__climate__data_fun3602, kk_context());
  _self->_x24 = _x24;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_change__mlift2758_linear__gaussian__climate__data_fun3602(kk_function_t _fself, kk_integer_t _b_3184, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2758_linear__gaussian__climate__data_fun3602__t* _self = kk_function_as(struct kk_climate_dash_change__mlift2758_linear__gaussian__climate__data_fun3602__t*, _fself);
  double _x24 = _self->_x24; /* double */
  kk_drop_match(_self, {;}, {}, _ctx)
  kk_integer_drop(_b_3184, _ctx);
  double _x3603 = kk_model_dash_resources_normal(_x24, 0x1.999999999999ap-5, _ctx); /*double*/
  return kk_double_box(_x3603, _ctx);
}


// lift anonymous function
struct kk_climate_dash_change__mlift2758_linear__gaussian__climate__data_fun3605__t {
  struct kk_function_s _base;
  size_t i0_2820;
};
static kk_box_t kk_climate_dash_change__mlift2758_linear__gaussian__climate__data_fun3605(kk_function_t _fself, kk_function_t _b_3195, kk_box_t _b_3196, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change__new_mlift2758_linear__gaussian__climate__data_fun3605(size_t i0_2820, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2758_linear__gaussian__climate__data_fun3605__t* _self = kk_function_alloc_as(struct kk_climate_dash_change__mlift2758_linear__gaussian__climate__data_fun3605__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_change__mlift2758_linear__gaussian__climate__data_fun3605, kk_context());
  _self->i0_2820 = i0_2820;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_change__mlift2758_linear__gaussian__climate__data_fun3605(kk_function_t _fself, kk_function_t _b_3195, kk_box_t _b_3196, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2758_linear__gaussian__climate__data_fun3605__t* _self = kk_function_as(struct kk_climate_dash_change__mlift2758_linear__gaussian__climate__data_fun3605__t*, _fself);
  size_t i0_2820 = _self->i0_2820; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i0_2820, _b_3195, _b_3196, _ctx);
}


// lift anonymous function
struct kk_climate_dash_change__mlift2758_linear__gaussian__climate__data_fun3607__t {
  struct kk_function_s _base;
  kk_integer_t i;
  kk_std_core__list month__vs;
  kk_std_core__list month__ys;
  kk_ref_t x;
  double score__var;
};
static kk_box_t kk_climate_dash_change__mlift2758_linear__gaussian__climate__data_fun3607(kk_function_t _fself, kk_box_t _b_3206, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change__new_mlift2758_linear__gaussian__climate__data_fun3607(kk_integer_t i, kk_std_core__list month__vs, kk_std_core__list month__ys, kk_ref_t x, double score__var, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2758_linear__gaussian__climate__data_fun3607__t* _self = kk_function_alloc_as(struct kk_climate_dash_change__mlift2758_linear__gaussian__climate__data_fun3607__t, 5, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_change__mlift2758_linear__gaussian__climate__data_fun3607, kk_context());
  _self->i = i;
  _self->month__vs = month__vs;
  _self->month__ys = month__ys;
  _self->x = x;
  _self->score__var = score__var;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_change__mlift2758_linear__gaussian__climate__data_fun3607(kk_function_t _fself, kk_box_t _b_3206, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2758_linear__gaussian__climate__data_fun3607__t* _self = kk_function_as(struct kk_climate_dash_change__mlift2758_linear__gaussian__climate__data_fun3607__t*, _fself);
  kk_integer_t i = _self->i; /* int */
  kk_std_core__list month__vs = _self->month__vs; /* effects-and-types/row_vector */
  kk_std_core__list month__ys = _self->month__ys; /* effects-and-types/row_vector */
  kk_ref_t x = _self->x; /* local-var<2724,list<double>> */
  double score__var = _self->score__var; /* double */
  kk_drop_match(_self, {kk_integer_dup(i);kk_std_core__list_dup(month__vs);kk_std_core__list_dup(month__ys);kk_ref_dup(x);;}, {}, _ctx)
  kk_unit_t _x3608 = kk_Unit;
  kk_std_core__list _x3609 = kk_std_core__list_unbox(_b_3206, _ctx); /*list<double>*/
  kk_climate_dash_change__mlift2757_linear__gaussian__climate__data(i, month__vs, month__ys, score__var, x, _x3609, _ctx);
  return kk_unit_box(_x3608);
}

kk_unit_t kk_climate_dash_change__mlift2758_linear__gaussian__climate__data(kk_integer_t i, kk_std_core__list month__ys, double score__var, kk_ref_t x, kk_std_core__list month__vs, kk_context_t* _ctx) { /* forall<h> (i : int, month_ys : effects-and-types/row_vector, score_var : double, x : local-var<h,list<double>>, month_vs : effects-and-types/row_vector) -> <exn,local<h>,effects-and-types/sample,effects-and-types/score> () */ 
  kk_std_core__list x0_2818;
  kk_integer_t _x14;
  kk_std_core__list _x3601 = kk_std_core__list_dup(month__ys); /*effects-and-types/row_vector*/
  _x14 = kk_std_core_length_1(_x3601, _ctx); /*int*/
  double _x24 = (0x1p0 + (0x0p+0)); /*double*/;
  size_t i0_2820 = ((size_t)1); /*std/core/hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i0_2820,kk_context()); /*std/core/hnd/evv<<effects-and-types/sample,exn,local<2724>,effects-and-types/score>>*/;
  kk_std_core__list y = kk_std_core__lift21054_list_1(kk_climate_dash_change__new_mlift2758_linear__gaussian__climate__data_fun3602(_x24, _ctx), kk_integer_from_small(1), _x14, kk_std_core__new_Nil(_ctx), _ctx); /*list<double>*/;
  kk_unit_t __w_l730_c9 = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(y, _ctx);
    kk_box_t _x3604 = kk_std_core_hnd_yield_cont(kk_climate_dash_change__new_mlift2758_linear__gaussian__climate__data_fun3605(i0_2820, _ctx), _ctx); /*3*/
    x0_2818 = kk_std_core__list_unbox(_x3604, _ctx); /*list<double>*/
  }
  else {
    x0_2818 = y; /*list<double>*/
  }
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x0_2818, _ctx);
    kk_box_t _x3606 = kk_std_core_hnd_yield_extend(kk_climate_dash_change__new_mlift2758_linear__gaussian__climate__data_fun3607(i, month__vs, month__ys, x, score__var, _ctx), _ctx); /*2*/
    kk_unit_unbox(_x3606); return kk_Unit;
  }
  kk_climate_dash_change__mlift2757_linear__gaussian__climate__data(i, month__vs, month__ys, score__var, x, x0_2818, _ctx); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_climate_dash_change__mlift2759_linear__gaussian__climate__data_fun3613__t {
  struct kk_function_s _base;
  size_t i0_2827;
};
static kk_box_t kk_climate_dash_change__mlift2759_linear__gaussian__climate__data_fun3613(kk_function_t _fself, kk_function_t _b_3218, kk_box_t _b_3219, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change__new_mlift2759_linear__gaussian__climate__data_fun3613(size_t i0_2827, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2759_linear__gaussian__climate__data_fun3613__t* _self = kk_function_alloc_as(struct kk_climate_dash_change__mlift2759_linear__gaussian__climate__data_fun3613__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_change__mlift2759_linear__gaussian__climate__data_fun3613, kk_context());
  _self->i0_2827 = i0_2827;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_change__mlift2759_linear__gaussian__climate__data_fun3613(kk_function_t _fself, kk_function_t _b_3218, kk_box_t _b_3219, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2759_linear__gaussian__climate__data_fun3613__t* _self = kk_function_as(struct kk_climate_dash_change__mlift2759_linear__gaussian__climate__data_fun3613__t*, _fself);
  size_t i0_2827 = _self->i0_2827; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i0_2827, _b_3218, _b_3219, _ctx);
}


// lift anonymous function
struct kk_climate_dash_change__mlift2759_linear__gaussian__climate__data_fun3615__t {
  struct kk_function_s _base;
  kk_integer_t i;
  kk_std_core__list month__ys;
  kk_ref_t x;
  double score__var;
};
static kk_box_t kk_climate_dash_change__mlift2759_linear__gaussian__climate__data_fun3615(kk_function_t _fself, kk_box_t _b_3229, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change__new_mlift2759_linear__gaussian__climate__data_fun3615(kk_integer_t i, kk_std_core__list month__ys, kk_ref_t x, double score__var, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2759_linear__gaussian__climate__data_fun3615__t* _self = kk_function_alloc_as(struct kk_climate_dash_change__mlift2759_linear__gaussian__climate__data_fun3615__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_change__mlift2759_linear__gaussian__climate__data_fun3615, kk_context());
  _self->i = i;
  _self->month__ys = month__ys;
  _self->x = x;
  _self->score__var = score__var;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_change__mlift2759_linear__gaussian__climate__data_fun3615(kk_function_t _fself, kk_box_t _b_3229, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2759_linear__gaussian__climate__data_fun3615__t* _self = kk_function_as(struct kk_climate_dash_change__mlift2759_linear__gaussian__climate__data_fun3615__t*, _fself);
  kk_integer_t i = _self->i; /* int */
  kk_std_core__list month__ys = _self->month__ys; /* effects-and-types/row_vector */
  kk_ref_t x = _self->x; /* local-var<2724,list<double>> */
  double score__var = _self->score__var; /* double */
  kk_drop_match(_self, {kk_integer_dup(i);kk_std_core__list_dup(month__ys);kk_ref_dup(x);;}, {}, _ctx)
  kk_unit_t _x3616 = kk_Unit;
  kk_std_core__list _x3617 = kk_std_core__list_unbox(_b_3229, _ctx); /*effects-and-types/row_vector*/
  kk_climate_dash_change__mlift2758_linear__gaussian__climate__data(i, month__ys, score__var, x, _x3617, _ctx);
  return kk_unit_box(_x3616);
}

kk_unit_t kk_climate_dash_change__mlift2759_linear__gaussian__climate__data(kk_integer_t i, double score__var, kk_std_core__list vs, kk_ref_t x, kk_std_core__list month__ys, kk_context_t* _ctx) { /* forall<h> (i : int, score_var : double, vs : list<effects-and-types/row_vector>, x : local-var<h,list<double>>, month_ys : effects-and-types/row_vector) -> <exn,local<h>,effects-and-types/sample,effects-and-types/score> () */ 
  kk_std_core__list x0_2825;
  size_t i0_2827 = ((size_t)0); /*std/core/hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i0_2827,kk_context()); /*std/core/hnd/evv<<exn,local<2724>,effects-and-types/sample,effects-and-types/score>>*/;
  kk_std_core__list y;
  kk_box_t _x3610;
  kk_integer_t _x3611 = kk_integer_dup(i); /*int*/
  _x3610 = kk_exn_dash_get_exn_get(vs, _x3611, _ctx); /*3*/
  y = kk_std_core__list_unbox(_x3610, _ctx); /*effects-and-types/row_vector*/
  kk_unit_t __w_l713_c9 = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(y, _ctx);
    kk_box_t _x3612 = kk_std_core_hnd_yield_cont(kk_climate_dash_change__new_mlift2759_linear__gaussian__climate__data_fun3613(i0_2827, _ctx), _ctx); /*3*/
    x0_2825 = kk_std_core__list_unbox(_x3612, _ctx); /*effects-and-types/row_vector*/
  }
  else {
    x0_2825 = y; /*effects-and-types/row_vector*/
  }
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x0_2825, _ctx);
    kk_box_t _x3614 = kk_std_core_hnd_yield_extend(kk_climate_dash_change__new_mlift2759_linear__gaussian__climate__data_fun3615(i, month__ys, x, score__var, _ctx), _ctx); /*2*/
    kk_unit_unbox(_x3614); return kk_Unit;
  }
  kk_climate_dash_change__mlift2758_linear__gaussian__climate__data(i, month__ys, score__var, x, x0_2825, _ctx); return kk_Unit;
}
 
// monadic lift

kk_unit_t kk_climate_dash_change__mlift2760_linear__gaussian__climate__data(kk_std_core__list _y_12, double diff, double subtract, kk_ref_t x, double _y_13, kk_context_t* _ctx) { /* forall<h> (list<double>, diff : double, subtract : double, x : local-var<h,list<double>>, double) -> <effects-and-types/sample,local<h>,exn,effects-and-types/score> () */ 
  kk_std_core__list _b_3239_3237;
  kk_std_core__list ys_2832;
  double _b_3234_3232;
  double _x3618 = (_y_13 * diff); /*double*/
  _b_3234_3232 = (_x3618 + subtract); /*double*/
  ys_2832 = kk_std_core__new_Cons(kk_reuse_null, kk_double_box(_b_3234_3232, _ctx), kk_std_core__new_Nil(_ctx), _ctx); /*list<double>*/
  _b_3239_3237 = kk_std_core_append(_y_12, ys_2832, _ctx); /*list<double>*/
  (kk_ref_set(x,(kk_std_core__list_box(_b_3239_3237, _ctx)),kk_context())); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_climate_dash_change__mlift2761_linear__gaussian__climate__data_fun3625__t {
  struct kk_function_s _base;
  size_t i_2835;
};
static kk_box_t kk_climate_dash_change__mlift2761_linear__gaussian__climate__data_fun3625(kk_function_t _fself, kk_function_t _b_3253, kk_box_t _b_3254, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change__new_mlift2761_linear__gaussian__climate__data_fun3625(size_t i_2835, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2761_linear__gaussian__climate__data_fun3625__t* _self = kk_function_alloc_as(struct kk_climate_dash_change__mlift2761_linear__gaussian__climate__data_fun3625__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_change__mlift2761_linear__gaussian__climate__data_fun3625, kk_context());
  _self->i_2835 = i_2835;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_change__mlift2761_linear__gaussian__climate__data_fun3625(kk_function_t _fself, kk_function_t _b_3253, kk_box_t _b_3254, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2761_linear__gaussian__climate__data_fun3625__t* _self = kk_function_as(struct kk_climate_dash_change__mlift2761_linear__gaussian__climate__data_fun3625__t*, _fself);
  size_t i_2835 = _self->i_2835; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_2835, _b_3253, _b_3254, _ctx);
}


// lift anonymous function
struct kk_climate_dash_change__mlift2761_linear__gaussian__climate__data_fun3627__t {
  struct kk_function_s _base;
  kk_std_core__list _y_12;
  kk_ref_t x;
  double diff;
  double subtract;
};
static kk_box_t kk_climate_dash_change__mlift2761_linear__gaussian__climate__data_fun3627(kk_function_t _fself, kk_box_t _b_3264, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change__new_mlift2761_linear__gaussian__climate__data_fun3627(kk_std_core__list _y_12, kk_ref_t x, double diff, double subtract, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2761_linear__gaussian__climate__data_fun3627__t* _self = kk_function_alloc_as(struct kk_climate_dash_change__mlift2761_linear__gaussian__climate__data_fun3627__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_change__mlift2761_linear__gaussian__climate__data_fun3627, kk_context());
  _self->_y_12 = _y_12;
  _self->x = x;
  _self->diff = diff;
  _self->subtract = subtract;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_change__mlift2761_linear__gaussian__climate__data_fun3627(kk_function_t _fself, kk_box_t _b_3264, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2761_linear__gaussian__climate__data_fun3627__t* _self = kk_function_as(struct kk_climate_dash_change__mlift2761_linear__gaussian__climate__data_fun3627__t*, _fself);
  kk_std_core__list _y_12 = _self->_y_12; /* list<double> */
  kk_ref_t x = _self->x; /* local-var<2724,list<double>> */
  double diff = _self->diff; /* double */
  double subtract = _self->subtract; /* double */
  kk_drop_match(_self, {kk_std_core__list_dup(_y_12);kk_ref_dup(x);;;}, {}, _ctx)
  kk_unit_t _x3628 = kk_Unit;
  double _x3629 = kk_double_unbox(_b_3264, _ctx); /*double*/
  kk_climate_dash_change__mlift2760_linear__gaussian__climate__data(_y_12, diff, subtract, x, _x3629, _ctx);
  return kk_unit_box(_x3628);
}

kk_unit_t kk_climate_dash_change__mlift2761_linear__gaussian__climate__data(double diff, double subtract, kk_ref_t x, kk_std_core__list _y_12, kk_context_t* _ctx) { /* forall<h> (diff : double, subtract : double, x : local-var<h,list<double>>, list<double>) -> <local<h>,effects-and-types/sample,exn,effects-and-types/score> () */ 
  double x0_2833;
  size_t i_2835 = ((size_t)1); /*std/core/hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_2835,kk_context()); /*std/core/hnd/evv<<effects-and-types/sample,local<2724>,exn,effects-and-types/score>>*/;
  double y;
  kk_std_core_hnd__ev ev_389;
  size_t _x3619 = ((size_t)0); /*size_t*/
  ev_389 = kk_evv_at(_x3619,kk_context()); /*std/core/hnd/ev<effects-and-types/.hnd-sample>*/
  kk_box_t _x3620;
  struct kk_std_core_hnd_Ev* _con3621 = kk_std_core_hnd__as_Ev(ev_389);
  kk_std_core_hnd__marker m = _con3621->marker;
  kk_box_t _box_x3240 = _con3621->hnd;
  kk_effects_dash_and_dash_types__hnd_sample h = kk_effects_dash_and_dash_types__hnd_sample_unbox(_box_x3240, NULL);
  kk_effects_dash_and_dash_types__hnd_sample_dup(h);
  kk_std_core_hnd__clause0 _match_3440;
  struct kk_effects_dash_and_dash_types__Hnd_sample* _con3623 = kk_effects_dash_and_dash_types__as_Hnd_sample(h);
  kk_std_core_hnd__clause0 fun_sample = _con3623->fun_sample;
  if (kk_effects_dash_and_dash_types__hnd_sample_is_unique(h)) {
    kk_effects_dash_and_dash_types__hnd_sample_free(h);
  }
  else {
    kk_std_core_hnd__clause0_dup(fun_sample);
    kk_effects_dash_and_dash_types__hnd_sample_decref(h, _ctx);
  }
  _match_3440 = fun_sample; /*std/core/hnd/clause0<double,effects-and-types/.hnd-sample,6,7>*/
  kk_function_t _fun_unbox_x3243 = _match_3440.clause;
  _x3620 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x3243, (_fun_unbox_x3243, m, ev_389, _ctx)); /*6*/
  y = kk_double_unbox(_x3620, _ctx); /*double*/
  kk_unit_t __w_l679_c9 = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x3624 = kk_std_core_hnd_yield_cont(kk_climate_dash_change__new_mlift2761_linear__gaussian__climate__data_fun3625(i_2835, _ctx), _ctx); /*3*/
    x0_2833 = kk_double_unbox(_x3624, _ctx); /*double*/
  }
  else {
    x0_2833 = y; /*double*/
  }
  if (kk_yielding(kk_context())) {
    kk_box_t _x3626 = kk_std_core_hnd_yield_extend(kk_climate_dash_change__new_mlift2761_linear__gaussian__climate__data_fun3627(_y_12, x, diff, subtract, _ctx), _ctx); /*2*/
    kk_unit_unbox(_x3626); return kk_Unit;
  }
  kk_climate_dash_change__mlift2760_linear__gaussian__climate__data(_y_12, diff, subtract, x, x0_2833, _ctx); return kk_Unit;
}
 
// monadic lift

kk_unit_t kk_climate_dash_change__mlift2762_linear__gaussian__climate__data(kk_std_core__list _y_17, double a__val, double w__val, kk_ref_t x, double _y_19, kk_context_t* _ctx) { /* forall<h> (list<double>, a_val : double, w_val : double, x : local-var<h,list<double>>, double) -> <exn,local<h>,effects-and-types/sample,effects-and-types/score> () */ 
  kk_std_core__list _b_3274_3272;
  kk_std_core__list ys_2838;
  double _b_3269_3267;
  double _x3630 = (_y_19 * a__val); /*double*/
  _b_3269_3267 = (_x3630 + w__val); /*double*/
  ys_2838 = kk_std_core__new_Cons(kk_reuse_null, kk_double_box(_b_3269_3267, _ctx), kk_std_core__new_Nil(_ctx), _ctx); /*list<double>*/
  _b_3274_3272 = kk_std_core_append(_y_17, ys_2838, _ctx); /*list<double>*/
  (kk_ref_set(x,(kk_std_core__list_box(_b_3274_3272, _ctx)),kk_context())); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_climate_dash_change__mlift2763_linear__gaussian__climate__data_fun3633__t {
  struct kk_function_s _base;
  size_t i0_2841;
};
static kk_box_t kk_climate_dash_change__mlift2763_linear__gaussian__climate__data_fun3633(kk_function_t _fself, kk_function_t _b_3284, kk_box_t _b_3285, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change__new_mlift2763_linear__gaussian__climate__data_fun3633(size_t i0_2841, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2763_linear__gaussian__climate__data_fun3633__t* _self = kk_function_alloc_as(struct kk_climate_dash_change__mlift2763_linear__gaussian__climate__data_fun3633__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_change__mlift2763_linear__gaussian__climate__data_fun3633, kk_context());
  _self->i0_2841 = i0_2841;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_change__mlift2763_linear__gaussian__climate__data_fun3633(kk_function_t _fself, kk_function_t _b_3284, kk_box_t _b_3285, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2763_linear__gaussian__climate__data_fun3633__t* _self = kk_function_as(struct kk_climate_dash_change__mlift2763_linear__gaussian__climate__data_fun3633__t*, _fself);
  size_t i0_2841 = _self->i0_2841; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i0_2841, _b_3284, _b_3285, _ctx);
}


// lift anonymous function
struct kk_climate_dash_change__mlift2763_linear__gaussian__climate__data_fun3635__t {
  struct kk_function_s _base;
  kk_std_core__list _y_17;
  kk_ref_t x;
  double a__val;
  double w__val;
};
static kk_box_t kk_climate_dash_change__mlift2763_linear__gaussian__climate__data_fun3635(kk_function_t _fself, kk_box_t _b_3295, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change__new_mlift2763_linear__gaussian__climate__data_fun3635(kk_std_core__list _y_17, kk_ref_t x, double a__val, double w__val, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2763_linear__gaussian__climate__data_fun3635__t* _self = kk_function_alloc_as(struct kk_climate_dash_change__mlift2763_linear__gaussian__climate__data_fun3635__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_change__mlift2763_linear__gaussian__climate__data_fun3635, kk_context());
  _self->_y_17 = _y_17;
  _self->x = x;
  _self->a__val = a__val;
  _self->w__val = w__val;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_change__mlift2763_linear__gaussian__climate__data_fun3635(kk_function_t _fself, kk_box_t _b_3295, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2763_linear__gaussian__climate__data_fun3635__t* _self = kk_function_as(struct kk_climate_dash_change__mlift2763_linear__gaussian__climate__data_fun3635__t*, _fself);
  kk_std_core__list _y_17 = _self->_y_17; /* list<double> */
  kk_ref_t x = _self->x; /* local-var<2724,list<double>> */
  double a__val = _self->a__val; /* double */
  double w__val = _self->w__val; /* double */
  kk_drop_match(_self, {kk_std_core__list_dup(_y_17);kk_ref_dup(x);;;}, {}, _ctx)
  kk_unit_t _x3636 = kk_Unit;
  double _x3637 = kk_double_unbox(_b_3295, _ctx); /*double*/
  kk_climate_dash_change__mlift2762_linear__gaussian__climate__data(_y_17, a__val, w__val, x, _x3637, _ctx);
  return kk_unit_box(_x3636);
}

kk_unit_t kk_climate_dash_change__mlift2763_linear__gaussian__climate__data(kk_std_core__list _y_17, double a__val, kk_integer_t i, double w__val, kk_ref_t x, kk_std_core__list _y_18, kk_context_t* _ctx) { /* forall<h> (list<double>, a_val : double, i : int, w_val : double, x : local-var<h,list<double>>, list<double>) -> <local<h>,exn,effects-and-types/sample,effects-and-types/score> () */ 
  double x0_2839;
  kk_integer_t _x21 = kk_integer_sub(i,(kk_integer_from_small(1)),kk_context()); /*int*/;
  size_t i0_2841 = ((size_t)0); /*std/core/hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i0_2841,kk_context()); /*std/core/hnd/evv<<exn,local<2724>,effects-and-types/sample,effects-and-types/score>>*/;
  double y;
  kk_box_t _x3631 = kk_exn_dash_get_exn_get(_y_18, _x21, _ctx); /*3*/
  y = kk_double_unbox(_x3631, _ctx); /*double*/
  kk_unit_t __w_l713_c9 = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x3632 = kk_std_core_hnd_yield_cont(kk_climate_dash_change__new_mlift2763_linear__gaussian__climate__data_fun3633(i0_2841, _ctx), _ctx); /*3*/
    x0_2839 = kk_double_unbox(_x3632, _ctx); /*double*/
  }
  else {
    x0_2839 = y; /*double*/
  }
  if (kk_yielding(kk_context())) {
    kk_box_t _x3634 = kk_std_core_hnd_yield_extend(kk_climate_dash_change__new_mlift2763_linear__gaussian__climate__data_fun3635(_y_17, x, a__val, w__val, _ctx), _ctx); /*2*/
    kk_unit_unbox(_x3634); return kk_Unit;
  }
  kk_climate_dash_change__mlift2762_linear__gaussian__climate__data(_y_17, a__val, w__val, x, x0_2839, _ctx); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_climate_dash_change__mlift2764_linear__gaussian__climate__data_fun3641__t {
  struct kk_function_s _base;
  kk_std_core__list _y_17;
  kk_integer_t i;
  kk_ref_t x;
  double a__val;
  double w__val;
};
static kk_box_t kk_climate_dash_change__mlift2764_linear__gaussian__climate__data_fun3641(kk_function_t _fself, kk_box_t _b_3301, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change__new_mlift2764_linear__gaussian__climate__data_fun3641(kk_std_core__list _y_17, kk_integer_t i, kk_ref_t x, double a__val, double w__val, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2764_linear__gaussian__climate__data_fun3641__t* _self = kk_function_alloc_as(struct kk_climate_dash_change__mlift2764_linear__gaussian__climate__data_fun3641__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_change__mlift2764_linear__gaussian__climate__data_fun3641, kk_context());
  _self->_y_17 = _y_17;
  _self->i = i;
  _self->x = x;
  _self->a__val = a__val;
  _self->w__val = w__val;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_change__mlift2764_linear__gaussian__climate__data_fun3641(kk_function_t _fself, kk_box_t _b_3301, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2764_linear__gaussian__climate__data_fun3641__t* _self = kk_function_as(struct kk_climate_dash_change__mlift2764_linear__gaussian__climate__data_fun3641__t*, _fself);
  kk_std_core__list _y_17 = _self->_y_17; /* list<double> */
  kk_integer_t i = _self->i; /* int */
  kk_ref_t x = _self->x; /* local-var<2724,list<double>> */
  double a__val = _self->a__val; /* double */
  double w__val = _self->w__val; /* double */
  kk_drop_match(_self, {kk_std_core__list_dup(_y_17);kk_integer_dup(i);kk_ref_dup(x);;;}, {}, _ctx)
  kk_unit_t _x3642 = kk_Unit;
  kk_std_core__list _x3643 = kk_std_core__list_unbox(_b_3301, _ctx); /*list<double>*/
  kk_climate_dash_change__mlift2763_linear__gaussian__climate__data(_y_17, a__val, i, w__val, x, _x3643, _ctx);
  return kk_unit_box(_x3642);
}

kk_unit_t kk_climate_dash_change__mlift2764_linear__gaussian__climate__data(double a__val, kk_integer_t i, double w__val, kk_ref_t x, kk_std_core__list _y_17, kk_context_t* _ctx) { /* forall<h> (a_val : double, i : int, w_val : double, x : local-var<h,list<double>>, list<double>) -> <local<h>,exn,effects-and-types/sample,effects-and-types/score> () */ 
  kk_std_core__list x0_2845;
  kk_box_t _x3638;
  kk_ref_t _x3639 = kk_ref_dup(x); /*local-var<2724,list<double>>*/
  _x3638 = (kk_ref_get(_x3639,kk_context())); /*0*/
  x0_2845 = kk_std_core__list_unbox(_x3638, _ctx); /*list<double>*/
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x0_2845, _ctx);
    kk_box_t _x3640 = kk_std_core_hnd_yield_extend(kk_climate_dash_change__new_mlift2764_linear__gaussian__climate__data_fun3641(_y_17, i, x, a__val, w__val, _ctx), _ctx); /*2*/
    kk_unit_unbox(_x3640); return kk_Unit;
  }
  kk_climate_dash_change__mlift2763_linear__gaussian__climate__data(_y_17, a__val, i, w__val, x, x0_2845, _ctx); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_climate_dash_change__mlift2765_linear__gaussian__climate__data_fun3647__t {
  struct kk_function_s _base;
  kk_integer_t i;
  kk_ref_t x;
  double a__val;
  double w__val;
};
static kk_box_t kk_climate_dash_change__mlift2765_linear__gaussian__climate__data_fun3647(kk_function_t _fself, kk_box_t _b_3307, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change__new_mlift2765_linear__gaussian__climate__data_fun3647(kk_integer_t i, kk_ref_t x, double a__val, double w__val, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2765_linear__gaussian__climate__data_fun3647__t* _self = kk_function_alloc_as(struct kk_climate_dash_change__mlift2765_linear__gaussian__climate__data_fun3647__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_change__mlift2765_linear__gaussian__climate__data_fun3647, kk_context());
  _self->i = i;
  _self->x = x;
  _self->a__val = a__val;
  _self->w__val = w__val;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_change__mlift2765_linear__gaussian__climate__data_fun3647(kk_function_t _fself, kk_box_t _b_3307, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2765_linear__gaussian__climate__data_fun3647__t* _self = kk_function_as(struct kk_climate_dash_change__mlift2765_linear__gaussian__climate__data_fun3647__t*, _fself);
  kk_integer_t i = _self->i; /* int */
  kk_ref_t x = _self->x; /* local-var<2724,list<double>> */
  double a__val = _self->a__val; /* double */
  double w__val = _self->w__val; /* double */
  kk_drop_match(_self, {kk_integer_dup(i);kk_ref_dup(x);;;}, {}, _ctx)
  kk_unit_t _x3648 = kk_Unit;
  kk_std_core__list _x3649 = kk_std_core__list_unbox(_b_3307, _ctx); /*list<double>*/
  kk_climate_dash_change__mlift2764_linear__gaussian__climate__data(a__val, i, w__val, x, _x3649, _ctx);
  return kk_unit_box(_x3648);
}

kk_unit_t kk_climate_dash_change__mlift2765_linear__gaussian__climate__data(double a__val, kk_integer_t i, kk_ref_t x, double w__val, kk_context_t* _ctx) { /* forall<h> (a_val : double, i : int, x : local-var<h,list<double>>, w_val : double) -> <effects-and-types/sample,exn,local<h>,effects-and-types/score> () */ 
  kk_std_core__list x0_2847;
  kk_box_t _x3644;
  kk_ref_t _x3645 = kk_ref_dup(x); /*local-var<2724,list<double>>*/
  _x3644 = (kk_ref_get(_x3645,kk_context())); /*0*/
  x0_2847 = kk_std_core__list_unbox(_x3644, _ctx); /*list<double>*/
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x0_2847, _ctx);
    kk_box_t _x3646 = kk_std_core_hnd_yield_extend(kk_climate_dash_change__new_mlift2765_linear__gaussian__climate__data_fun3647(i, x, a__val, w__val, _ctx), _ctx); /*2*/
    kk_unit_unbox(_x3646); return kk_Unit;
  }
  kk_climate_dash_change__mlift2764_linear__gaussian__climate__data(a__val, i, w__val, x, x0_2847, _ctx); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_climate_dash_change__mlift2766_linear__gaussian__climate__data_fun3651__t {
  struct kk_function_s _base;
};
static kk_box_t kk_climate_dash_change__mlift2766_linear__gaussian__climate__data_fun3651(kk_function_t _fself, kk_box_t _b_3311, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change__new_mlift2766_linear__gaussian__climate__data_fun3651(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_climate_dash_change__mlift2766_linear__gaussian__climate__data_fun3651, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_climate_dash_change__mlift2766_linear__gaussian__climate__data_fun3651(kk_function_t _fself, kk_box_t _b_3311, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x3652;
  double _x3653 = kk_double_unbox(_b_3311, _ctx); /*double*/
  _x3652 = kk_model_dash_resources__mlift3175_normal(0x0p+0, 0x1p0, _x3653, _ctx); /*double*/
  return kk_double_box(_x3652, _ctx);
}


// lift anonymous function
struct kk_climate_dash_change__mlift2766_linear__gaussian__climate__data_fun3656__t {
  struct kk_function_s _base;
  size_t i0_2851;
};
static kk_box_t kk_climate_dash_change__mlift2766_linear__gaussian__climate__data_fun3656(kk_function_t _fself, kk_function_t _b_3319, kk_box_t _b_3320, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change__new_mlift2766_linear__gaussian__climate__data_fun3656(size_t i0_2851, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2766_linear__gaussian__climate__data_fun3656__t* _self = kk_function_alloc_as(struct kk_climate_dash_change__mlift2766_linear__gaussian__climate__data_fun3656__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_change__mlift2766_linear__gaussian__climate__data_fun3656, kk_context());
  _self->i0_2851 = i0_2851;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_change__mlift2766_linear__gaussian__climate__data_fun3656(kk_function_t _fself, kk_function_t _b_3319, kk_box_t _b_3320, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2766_linear__gaussian__climate__data_fun3656__t* _self = kk_function_as(struct kk_climate_dash_change__mlift2766_linear__gaussian__climate__data_fun3656__t*, _fself);
  size_t i0_2851 = _self->i0_2851; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i0_2851, _b_3319, _b_3320, _ctx);
}


// lift anonymous function
struct kk_climate_dash_change__mlift2766_linear__gaussian__climate__data_fun3658__t {
  struct kk_function_s _base;
  kk_integer_t i;
  kk_ref_t x;
  double a__val;
};
static kk_box_t kk_climate_dash_change__mlift2766_linear__gaussian__climate__data_fun3658(kk_function_t _fself, kk_box_t _b_3330, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change__new_mlift2766_linear__gaussian__climate__data_fun3658(kk_integer_t i, kk_ref_t x, double a__val, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2766_linear__gaussian__climate__data_fun3658__t* _self = kk_function_alloc_as(struct kk_climate_dash_change__mlift2766_linear__gaussian__climate__data_fun3658__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_change__mlift2766_linear__gaussian__climate__data_fun3658, kk_context());
  _self->i = i;
  _self->x = x;
  _self->a__val = a__val;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_change__mlift2766_linear__gaussian__climate__data_fun3658(kk_function_t _fself, kk_box_t _b_3330, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2766_linear__gaussian__climate__data_fun3658__t* _self = kk_function_as(struct kk_climate_dash_change__mlift2766_linear__gaussian__climate__data_fun3658__t*, _fself);
  kk_integer_t i = _self->i; /* int */
  kk_ref_t x = _self->x; /* local-var<2724,list<double>> */
  double a__val = _self->a__val; /* double */
  kk_drop_match(_self, {kk_integer_dup(i);kk_ref_dup(x);;}, {}, _ctx)
  kk_unit_t _x3659 = kk_Unit;
  double _x3660 = kk_double_unbox(_b_3330, _ctx); /*double*/
  kk_climate_dash_change__mlift2765_linear__gaussian__climate__data(a__val, i, x, _x3660, _ctx);
  return kk_unit_box(_x3659);
}

kk_unit_t kk_climate_dash_change__mlift2766_linear__gaussian__climate__data(kk_integer_t i, kk_ref_t x, double a__val, kk_context_t* _ctx) { /* forall<h> (i : int, x : local-var<h,list<double>>, a_val : double) -> <effects-and-types/sample,exn,local<h>,effects-and-types/score> () */ 
  double x0_2849;
  size_t i0_2851 = ((size_t)1); /*std/core/hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i0_2851,kk_context()); /*std/core/hnd/evv<<effects-and-types/sample,exn,local<2724>,effects-and-types/score>>*/;
  double y;
  double x_3267 = kk_model_dash_resources_standard_normal(_ctx); /*double*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x3650 = kk_std_core_hnd_yield_extend(kk_climate_dash_change__new_mlift2766_linear__gaussian__climate__data_fun3651(_ctx), _ctx); /*2*/
    y = kk_double_unbox(_x3650, _ctx); /*double*/
  }
  else {
    double _x3654 = (x_3267 * 0x1p0); /*double*/
    y = ((0x0p+0) + _x3654); /*double*/
  }
  kk_unit_t __w_l713_c9 = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x3655 = kk_std_core_hnd_yield_cont(kk_climate_dash_change__new_mlift2766_linear__gaussian__climate__data_fun3656(i0_2851, _ctx), _ctx); /*3*/
    x0_2849 = kk_double_unbox(_x3655, _ctx); /*double*/
  }
  else {
    x0_2849 = y; /*double*/
  }
  if (kk_yielding(kk_context())) {
    kk_box_t _x3657 = kk_std_core_hnd_yield_extend(kk_climate_dash_change__new_mlift2766_linear__gaussian__climate__data_fun3658(i, x, a__val, _ctx), _ctx); /*2*/
    kk_unit_unbox(_x3657); return kk_Unit;
  }
  kk_climate_dash_change__mlift2765_linear__gaussian__climate__data(a__val, i, x, x0_2849, _ctx); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_climate_dash_change__mlift2767_linear__gaussian__climate__data_fun3664__t {
  struct kk_function_s _base;
  size_t i0_2857;
};
static kk_box_t kk_climate_dash_change__mlift2767_linear__gaussian__climate__data_fun3664(kk_function_t _fself, kk_function_t _b_3342, kk_box_t _b_3343, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change__new_mlift2767_linear__gaussian__climate__data_fun3664(size_t i0_2857, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2767_linear__gaussian__climate__data_fun3664__t* _self = kk_function_alloc_as(struct kk_climate_dash_change__mlift2767_linear__gaussian__climate__data_fun3664__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_change__mlift2767_linear__gaussian__climate__data_fun3664, kk_context());
  _self->i0_2857 = i0_2857;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_change__mlift2767_linear__gaussian__climate__data_fun3664(kk_function_t _fself, kk_function_t _b_3342, kk_box_t _b_3343, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2767_linear__gaussian__climate__data_fun3664__t* _self = kk_function_as(struct kk_climate_dash_change__mlift2767_linear__gaussian__climate__data_fun3664__t*, _fself);
  size_t i0_2857 = _self->i0_2857; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i0_2857, _b_3342, _b_3343, _ctx);
}


// lift anonymous function
struct kk_climate_dash_change__mlift2767_linear__gaussian__climate__data_fun3666__t {
  struct kk_function_s _base;
  kk_integer_t i;
  kk_std_core__list vs;
  kk_ref_t x;
  double score__var;
};
static kk_box_t kk_climate_dash_change__mlift2767_linear__gaussian__climate__data_fun3666(kk_function_t _fself, kk_box_t _b_3353, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change__new_mlift2767_linear__gaussian__climate__data_fun3666(kk_integer_t i, kk_std_core__list vs, kk_ref_t x, double score__var, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2767_linear__gaussian__climate__data_fun3666__t* _self = kk_function_alloc_as(struct kk_climate_dash_change__mlift2767_linear__gaussian__climate__data_fun3666__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_change__mlift2767_linear__gaussian__climate__data_fun3666, kk_context());
  _self->i = i;
  _self->vs = vs;
  _self->x = x;
  _self->score__var = score__var;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_change__mlift2767_linear__gaussian__climate__data_fun3666(kk_function_t _fself, kk_box_t _b_3353, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2767_linear__gaussian__climate__data_fun3666__t* _self = kk_function_as(struct kk_climate_dash_change__mlift2767_linear__gaussian__climate__data_fun3666__t*, _fself);
  kk_integer_t i = _self->i; /* int */
  kk_std_core__list vs = _self->vs; /* list<effects-and-types/row_vector> */
  kk_ref_t x = _self->x; /* local-var<2724,list<double>> */
  double score__var = _self->score__var; /* double */
  kk_drop_match(_self, {kk_integer_dup(i);kk_std_core__list_dup(vs);kk_ref_dup(x);;}, {}, _ctx)
  kk_unit_t _x3667 = kk_Unit;
  kk_std_core__list _x3668 = kk_std_core__list_unbox(_b_3353, _ctx); /*effects-and-types/row_vector*/
  kk_climate_dash_change__mlift2759_linear__gaussian__climate__data(i, score__var, vs, x, _x3668, _ctx);
  return kk_unit_box(_x3667);
}

kk_unit_t kk_climate_dash_change__mlift2767_linear__gaussian__climate__data(kk_integer_t i, double score__var, kk_std_core__list vs, kk_ref_t x, kk_std_core__list ys, kk_unit_t _c_21, kk_context_t* _ctx) { /* forall<h> (i : int, score_var : double, vs : list<effects-and-types/row_vector>, x : local-var<h,list<double>>, ys : list<effects-and-types/row_vector>, ()) -> () */ 
  kk_std_core__list x0_2855;
  size_t i0_2857 = ((size_t)0); /*std/core/hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i0_2857,kk_context()); /*std/core/hnd/evv<<exn,local<2724>,effects-and-types/sample,effects-and-types/score>>*/;
  kk_std_core__list y;
  kk_box_t _x3661;
  kk_integer_t _x3662 = kk_integer_dup(i); /*int*/
  _x3661 = kk_exn_dash_get_exn_get(ys, _x3662, _ctx); /*3*/
  y = kk_std_core__list_unbox(_x3661, _ctx); /*effects-and-types/row_vector*/
  kk_unit_t __w_l713_c9 = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(y, _ctx);
    kk_box_t _x3663 = kk_std_core_hnd_yield_cont(kk_climate_dash_change__new_mlift2767_linear__gaussian__climate__data_fun3664(i0_2857, _ctx), _ctx); /*3*/
    x0_2855 = kk_std_core__list_unbox(_x3663, _ctx); /*effects-and-types/row_vector*/
  }
  else {
    x0_2855 = y; /*effects-and-types/row_vector*/
  }
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x0_2855, _ctx);
    kk_box_t _x3665 = kk_std_core_hnd_yield_extend(kk_climate_dash_change__new_mlift2767_linear__gaussian__climate__data_fun3666(i, vs, x, score__var, _ctx), _ctx); /*2*/
    kk_unit_unbox(_x3665); return kk_Unit;
  }
  kk_climate_dash_change__mlift2759_linear__gaussian__climate__data(i, score__var, vs, x, x0_2855, _ctx); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_climate_dash_change__mlift2768_linear__gaussian__climate__data_fun3669__t {
  struct kk_function_s _base;
  kk_ref_t x;
};
static kk_box_t kk_climate_dash_change__mlift2768_linear__gaussian__climate__data_fun3669(kk_function_t _fself, kk_integer_t _b_3364, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change__new_mlift2768_linear__gaussian__climate__data_fun3669(kk_ref_t x, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2768_linear__gaussian__climate__data_fun3669__t* _self = kk_function_alloc_as(struct kk_climate_dash_change__mlift2768_linear__gaussian__climate__data_fun3669__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_change__mlift2768_linear__gaussian__climate__data_fun3669, kk_context());
  _self->x = x;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_change__mlift2768_linear__gaussian__climate__data_fun3673__t {
  struct kk_function_s _base;
  kk_integer_t _b_3364;
};
static kk_box_t kk_climate_dash_change__mlift2768_linear__gaussian__climate__data_fun3673(kk_function_t _fself, kk_box_t _b_3359, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change__new_mlift2768_linear__gaussian__climate__data_fun3673(kk_integer_t _b_3364, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2768_linear__gaussian__climate__data_fun3673__t* _self = kk_function_alloc_as(struct kk_climate_dash_change__mlift2768_linear__gaussian__climate__data_fun3673__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_change__mlift2768_linear__gaussian__climate__data_fun3673, kk_context());
  _self->_b_3364 = _b_3364;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_change__mlift2768_linear__gaussian__climate__data_fun3673(kk_function_t _fself, kk_box_t _b_3359, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2768_linear__gaussian__climate__data_fun3673__t* _self = kk_function_as(struct kk_climate_dash_change__mlift2768_linear__gaussian__climate__data_fun3673__t*, _fself);
  kk_integer_t _b_3364 = _self->_b_3364; /* int */
  kk_drop_match(_self, {kk_integer_dup(_b_3364);}, {}, _ctx)
  double _x3674;
  kk_std_core__list _x3675 = kk_std_core__list_unbox(_b_3359, _ctx); /*list<double>*/
  _x3674 = kk_climate_dash_change__mlift2751_linear__gaussian__climate__data(_b_3364, _x3675, _ctx); /*double*/
  return kk_double_box(_x3674, _ctx);
}
static kk_box_t kk_climate_dash_change__mlift2768_linear__gaussian__climate__data_fun3669(kk_function_t _fself, kk_integer_t _b_3364, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2768_linear__gaussian__climate__data_fun3669__t* _self = kk_function_as(struct kk_climate_dash_change__mlift2768_linear__gaussian__climate__data_fun3669__t*, _fself);
  kk_ref_t x = _self->x; /* local-var<2724,list<double>> */
  kk_drop_match(_self, {kk_ref_dup(x);}, {}, _ctx)
  double _x3670;
  kk_std_core__list x0_2864;
  kk_box_t _x3671 = (kk_ref_get(x,kk_context())); /*0*/
  x0_2864 = kk_std_core__list_unbox(_x3671, _ctx); /*list<double>*/
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x0_2864, _ctx);
    kk_box_t _x3672 = kk_std_core_hnd_yield_extend(kk_climate_dash_change__new_mlift2768_linear__gaussian__climate__data_fun3673(_b_3364, _ctx), _ctx); /*2*/
    _x3670 = kk_double_unbox(_x3672, _ctx); /*double*/
  }
  else {
    _x3670 = kk_climate_dash_change__mlift2751_linear__gaussian__climate__data(_b_3364, x0_2864, _ctx); /*double*/
  }
  return kk_double_box(_x3670, _ctx);
}

kk_std_core__list kk_climate_dash_change__mlift2768_linear__gaussian__climate__data(kk_ref_t x, kk_unit_t wild__1, kk_context_t* _ctx) { /* forall<h> (x : local-var<h,list<double>>, wild_1 : ()) -> <exn,local<h>,effects-and-types/sample,effects-and-types/score> list<double> */ 
  return kk_std_core__lift21054_list_1(kk_climate_dash_change__new_mlift2768_linear__gaussian__climate__data_fun3669(x, _ctx), kk_integer_from_small(0), kk_integer_from_small(12), kk_std_core__new_Nil(_ctx), _ctx);
}


// lift anonymous function
struct kk_climate_dash_change_linear__gaussian__climate__data_fun3676__t {
  struct kk_function_s _base;
  kk_std_core__list vs;
  kk_std_core__list ys;
  double diff;
  double score__var;
  double subtract;
};
static kk_std_core__list kk_climate_dash_change_linear__gaussian__climate__data_fun3676(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change_new_linear__gaussian__climate__data_fun3676(kk_std_core__list vs, kk_std_core__list ys, double diff, double score__var, double subtract, kk_context_t* _ctx) {
  struct kk_climate_dash_change_linear__gaussian__climate__data_fun3676__t* _self = kk_function_alloc_as(struct kk_climate_dash_change_linear__gaussian__climate__data_fun3676__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_change_linear__gaussian__climate__data_fun3676, kk_context());
  _self->vs = vs;
  _self->ys = ys;
  _self->diff = diff;
  _self->score__var = score__var;
  _self->subtract = subtract;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_change_linear__gaussian__climate__data_fun3678__t {
  struct kk_function_s _base;
  kk_ref_t loc;
  kk_std_core__list vs;
  kk_std_core__list ys;
  double diff;
  double score__var;
  double subtract;
};
static kk_unit_t kk_climate_dash_change_linear__gaussian__climate__data_fun3678(kk_function_t _fself, kk_integer_t i, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change_new_linear__gaussian__climate__data_fun3678(kk_ref_t loc, kk_std_core__list vs, kk_std_core__list ys, double diff, double score__var, double subtract, kk_context_t* _ctx) {
  struct kk_climate_dash_change_linear__gaussian__climate__data_fun3678__t* _self = kk_function_alloc_as(struct kk_climate_dash_change_linear__gaussian__climate__data_fun3678__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_change_linear__gaussian__climate__data_fun3678, kk_context());
  _self->loc = loc;
  _self->vs = vs;
  _self->ys = ys;
  _self->diff = diff;
  _self->score__var = score__var;
  _self->subtract = subtract;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_change_linear__gaussian__climate__data_fun3684__t {
  struct kk_function_s _base;
  kk_ref_t loc;
  double diff;
  double subtract;
};
static kk_box_t kk_climate_dash_change_linear__gaussian__climate__data_fun3684(kk_function_t _fself, kk_box_t _b_3377, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change_new_linear__gaussian__climate__data_fun3684(kk_ref_t loc, double diff, double subtract, kk_context_t* _ctx) {
  struct kk_climate_dash_change_linear__gaussian__climate__data_fun3684__t* _self = kk_function_alloc_as(struct kk_climate_dash_change_linear__gaussian__climate__data_fun3684__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_change_linear__gaussian__climate__data_fun3684, kk_context());
  _self->loc = loc;
  _self->diff = diff;
  _self->subtract = subtract;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_change_linear__gaussian__climate__data_fun3684(kk_function_t _fself, kk_box_t _b_3377, kk_context_t* _ctx) {
  struct kk_climate_dash_change_linear__gaussian__climate__data_fun3684__t* _self = kk_function_as(struct kk_climate_dash_change_linear__gaussian__climate__data_fun3684__t*, _fself);
  kk_ref_t loc = _self->loc; /* local-var<global,list<double>> */
  double diff = _self->diff; /* double */
  double subtract = _self->subtract; /* double */
  kk_drop_match(_self, {kk_ref_dup(loc);;;}, {}, _ctx)
  kk_unit_t _x3685 = kk_Unit;
  kk_std_core__list _x3686 = kk_std_core__list_unbox(_b_3377, _ctx); /*list<double>*/
  kk_climate_dash_change__mlift2761_linear__gaussian__climate__data(diff, subtract, loc, _x3686, _ctx);
  return kk_unit_box(_x3685);
}


// lift anonymous function
struct kk_climate_dash_change_linear__gaussian__climate__data_fun3689__t {
  struct kk_function_s _base;
};
static kk_box_t kk_climate_dash_change_linear__gaussian__climate__data_fun3689(kk_function_t _fself, kk_box_t _b_3379, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change_new_linear__gaussian__climate__data_fun3689(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_climate_dash_change_linear__gaussian__climate__data_fun3689, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_climate_dash_change_linear__gaussian__climate__data_fun3689(kk_function_t _fself, kk_box_t _b_3379, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x3690;
  double _x3691 = kk_double_unbox(_b_3379, _ctx); /*double*/
  _x3690 = kk_model_dash_resources__mlift3175_normal(0x1p0, 0x1.999999999999ap-2, _x3691, _ctx); /*double*/
  return kk_double_box(_x3690, _ctx);
}


// lift anonymous function
struct kk_climate_dash_change_linear__gaussian__climate__data_fun3694__t {
  struct kk_function_s _base;
  size_t i0_2881;
};
static kk_box_t kk_climate_dash_change_linear__gaussian__climate__data_fun3694(kk_function_t _fself, kk_function_t _b_3387, kk_box_t _b_3388, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change_new_linear__gaussian__climate__data_fun3694(size_t i0_2881, kk_context_t* _ctx) {
  struct kk_climate_dash_change_linear__gaussian__climate__data_fun3694__t* _self = kk_function_alloc_as(struct kk_climate_dash_change_linear__gaussian__climate__data_fun3694__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_change_linear__gaussian__climate__data_fun3694, kk_context());
  _self->i0_2881 = i0_2881;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_change_linear__gaussian__climate__data_fun3694(kk_function_t _fself, kk_function_t _b_3387, kk_box_t _b_3388, kk_context_t* _ctx) {
  struct kk_climate_dash_change_linear__gaussian__climate__data_fun3694__t* _self = kk_function_as(struct kk_climate_dash_change_linear__gaussian__climate__data_fun3694__t*, _fself);
  size_t i0_2881 = _self->i0_2881; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i0_2881, _b_3387, _b_3388, _ctx);
}


// lift anonymous function
struct kk_climate_dash_change_linear__gaussian__climate__data_fun3697__t {
  struct kk_function_s _base;
  kk_integer_t i;
  kk_ref_t loc;
};
static kk_box_t kk_climate_dash_change_linear__gaussian__climate__data_fun3697(kk_function_t _fself, kk_box_t _b_3398, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change_new_linear__gaussian__climate__data_fun3697(kk_integer_t i, kk_ref_t loc, kk_context_t* _ctx) {
  struct kk_climate_dash_change_linear__gaussian__climate__data_fun3697__t* _self = kk_function_alloc_as(struct kk_climate_dash_change_linear__gaussian__climate__data_fun3697__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_change_linear__gaussian__climate__data_fun3697, kk_context());
  _self->i = i;
  _self->loc = loc;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_change_linear__gaussian__climate__data_fun3697(kk_function_t _fself, kk_box_t _b_3398, kk_context_t* _ctx) {
  struct kk_climate_dash_change_linear__gaussian__climate__data_fun3697__t* _self = kk_function_as(struct kk_climate_dash_change_linear__gaussian__climate__data_fun3697__t*, _fself);
  kk_integer_t i = _self->i; /* int */
  kk_ref_t loc = _self->loc; /* local-var<global,list<double>> */
  kk_drop_match(_self, {kk_integer_dup(i);kk_ref_dup(loc);}, {}, _ctx)
  kk_unit_t _x3698 = kk_Unit;
  double _x3699 = kk_double_unbox(_b_3398, _ctx); /*double*/
  kk_climate_dash_change__mlift2766_linear__gaussian__climate__data(i, loc, _x3699, _ctx);
  return kk_unit_box(_x3698);
}


// lift anonymous function
struct kk_climate_dash_change_linear__gaussian__climate__data_fun3703__t {
  struct kk_function_s _base;
  kk_integer_t i;
  kk_ref_t loc;
  kk_std_core__list vs;
  kk_std_core__list ys;
  double score__var;
};
static kk_box_t kk_climate_dash_change_linear__gaussian__climate__data_fun3703(kk_function_t _fself, kk_box_t _b_3404, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change_new_linear__gaussian__climate__data_fun3703(kk_integer_t i, kk_ref_t loc, kk_std_core__list vs, kk_std_core__list ys, double score__var, kk_context_t* _ctx) {
  struct kk_climate_dash_change_linear__gaussian__climate__data_fun3703__t* _self = kk_function_alloc_as(struct kk_climate_dash_change_linear__gaussian__climate__data_fun3703__t, 5, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_change_linear__gaussian__climate__data_fun3703, kk_context());
  _self->i = i;
  _self->loc = loc;
  _self->vs = vs;
  _self->ys = ys;
  _self->score__var = score__var;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_change_linear__gaussian__climate__data_fun3703(kk_function_t _fself, kk_box_t _b_3404, kk_context_t* _ctx) {
  struct kk_climate_dash_change_linear__gaussian__climate__data_fun3703__t* _self = kk_function_as(struct kk_climate_dash_change_linear__gaussian__climate__data_fun3703__t*, _fself);
  kk_integer_t i = _self->i; /* int */
  kk_ref_t loc = _self->loc; /* local-var<global,list<double>> */
  kk_std_core__list vs = _self->vs; /* list<effects-and-types/row_vector> */
  kk_std_core__list ys = _self->ys; /* list<effects-and-types/row_vector> */
  double score__var = _self->score__var; /* double */
  kk_drop_match(_self, {kk_integer_dup(i);kk_ref_dup(loc);kk_std_core__list_dup(vs);kk_std_core__list_dup(ys);;}, {}, _ctx)
  kk_unit_t _x3704 = kk_Unit;
  kk_unit_t _x3705 = kk_Unit;
  kk_unit_unbox(_b_3404);
  kk_climate_dash_change__mlift2767_linear__gaussian__climate__data(i, score__var, vs, loc, ys, _x3705, _ctx);
  return kk_unit_box(_x3704);
}
static kk_unit_t kk_climate_dash_change_linear__gaussian__climate__data_fun3678(kk_function_t _fself, kk_integer_t i, kk_context_t* _ctx) {
  struct kk_climate_dash_change_linear__gaussian__climate__data_fun3678__t* _self = kk_function_as(struct kk_climate_dash_change_linear__gaussian__climate__data_fun3678__t*, _fself);
  kk_ref_t loc = _self->loc; /* local-var<global,list<double>> */
  kk_std_core__list vs = _self->vs; /* list<effects-and-types/row_vector> */
  kk_std_core__list ys = _self->ys; /* list<effects-and-types/row_vector> */
  double diff = _self->diff; /* double */
  double score__var = _self->score__var; /* double */
  double subtract = _self->subtract; /* double */
  kk_drop_match(_self, {kk_ref_dup(loc);kk_std_core__list_dup(vs);kk_std_core__list_dup(ys);;;;}, {}, _ctx)
  kk_unit_t x1_2875 = kk_Unit;
  bool _match_3423;
  kk_integer_t _x3679 = kk_integer_dup(i); /*int*/
  _match_3423 = kk_integer_eq(_x3679,(kk_integer_from_small(0)),kk_context()); /*bool*/
  if (_match_3423) {
    kk_std_core__list x2_2877;
    kk_box_t _x3680;
    kk_ref_t _x3681 = kk_ref_dup(loc); /*local-var<global,list<double>>*/
    _x3680 = (kk_ref_get(_x3681,kk_context())); /*0*/
    x2_2877 = kk_std_core__list_unbox(_x3680, _ctx); /*list<double>*/
    if (kk_yielding(kk_context())) {
      kk_std_core__list_drop(x2_2877, _ctx);
      kk_box_t _x3682;
      kk_function_t _x3683;
      kk_ref_dup(loc);
      _x3683 = kk_climate_dash_change_new_linear__gaussian__climate__data_fun3684(loc, diff, subtract, _ctx); /*(1) -> 3 2*/
      _x3682 = kk_std_core_hnd_yield_extend(_x3683, _ctx); /*2*/
      kk_unit_unbox(_x3682);
    }
    else {
      kk_ref_t _x3687 = kk_ref_dup(loc); /*local-var<global,list<double>>*/
      kk_climate_dash_change__mlift2761_linear__gaussian__climate__data(diff, subtract, _x3687, x2_2877, _ctx);
    }
  }
  else {
    double x3_2879;
    size_t i0_2881 = ((size_t)1); /*std/core/hnd/ev-index*/;
    kk_evv_t w = kk_evv_swap_create1(i0_2881,kk_context()); /*std/core/hnd/evv<<effects-and-types/sample,exn,local<global>,effects-and-types/score>>*/;
    double y;
    double x_3267 = kk_model_dash_resources_standard_normal(_ctx); /*double*/;
    if (kk_yielding(kk_context())) {
      kk_box_t _x3688 = kk_std_core_hnd_yield_extend(kk_climate_dash_change_new_linear__gaussian__climate__data_fun3689(_ctx), _ctx); /*2*/
      y = kk_double_unbox(_x3688, _ctx); /*double*/
    }
    else {
      double _x3692 = (x_3267 * (0x1.999999999999ap-2)); /*double*/
      y = (0x1p0 + _x3692); /*double*/
    }
    kk_unit_t __w_l713_c9 = kk_Unit;
    kk_evv_set(w,kk_context());
    if (kk_yielding(kk_context())) {
      kk_box_t _x3693 = kk_std_core_hnd_yield_cont(kk_climate_dash_change_new_linear__gaussian__climate__data_fun3694(i0_2881, _ctx), _ctx); /*3*/
      x3_2879 = kk_double_unbox(_x3693, _ctx); /*double*/
    }
    else {
      x3_2879 = y; /*double*/
    }
    if (kk_yielding(kk_context())) {
      kk_box_t _x3695;
      kk_function_t _x3696;
      kk_integer_dup(i);
      kk_ref_dup(loc);
      _x3696 = kk_climate_dash_change_new_linear__gaussian__climate__data_fun3697(i, loc, _ctx); /*(1) -> 3 2*/
      _x3695 = kk_std_core_hnd_yield_extend(_x3696, _ctx); /*2*/
      kk_unit_unbox(_x3695);
    }
    else {
      kk_integer_t _x3700 = kk_integer_dup(i); /*int*/
      kk_ref_t _x3701 = kk_ref_dup(loc); /*local-var<global,list<double>>*/
      kk_climate_dash_change__mlift2766_linear__gaussian__climate__data(_x3700, _x3701, x3_2879, _ctx);
    }
  }
  if (kk_yielding(kk_context())) {
    kk_box_t _x3702 = kk_std_core_hnd_yield_extend(kk_climate_dash_change_new_linear__gaussian__climate__data_fun3703(i, loc, vs, ys, score__var, _ctx), _ctx); /*2*/
    return kk_unit_unbox(_x3702);
  }
  return kk_climate_dash_change__mlift2767_linear__gaussian__climate__data(i, score__var, vs, loc, ys, x1_2875, _ctx);
}


// lift anonymous function
struct kk_climate_dash_change_linear__gaussian__climate__data_fun3708__t {
  struct kk_function_s _base;
  kk_ref_t loc;
};
static kk_box_t kk_climate_dash_change_linear__gaussian__climate__data_fun3708(kk_function_t _fself, kk_box_t _b_3408, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change_new_linear__gaussian__climate__data_fun3708(kk_ref_t loc, kk_context_t* _ctx) {
  struct kk_climate_dash_change_linear__gaussian__climate__data_fun3708__t* _self = kk_function_alloc_as(struct kk_climate_dash_change_linear__gaussian__climate__data_fun3708__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_change_linear__gaussian__climate__data_fun3708, kk_context());
  _self->loc = loc;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_change_linear__gaussian__climate__data_fun3708(kk_function_t _fself, kk_box_t _b_3408, kk_context_t* _ctx) {
  struct kk_climate_dash_change_linear__gaussian__climate__data_fun3708__t* _self = kk_function_as(struct kk_climate_dash_change_linear__gaussian__climate__data_fun3708__t*, _fself);
  kk_ref_t loc = _self->loc; /* local-var<global,list<double>> */
  kk_drop_match(_self, {kk_ref_dup(loc);}, {}, _ctx)
  kk_std_core__list _x3709;
  kk_unit_t _x3710 = kk_Unit;
  kk_unit_unbox(_b_3408);
  _x3709 = kk_climate_dash_change__mlift2768_linear__gaussian__climate__data(loc, _x3710, _ctx); /*list<double>*/
  return kk_std_core__list_box(_x3709, _ctx);
}
static kk_std_core__list kk_climate_dash_change_linear__gaussian__climate__data_fun3676(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_change_linear__gaussian__climate__data_fun3676__t* _self = kk_function_as(struct kk_climate_dash_change_linear__gaussian__climate__data_fun3676__t*, _fself);
  kk_std_core__list vs = _self->vs; /* list<effects-and-types/row_vector> */
  kk_std_core__list ys = _self->ys; /* list<effects-and-types/row_vector> */
  double diff = _self->diff; /* double */
  double score__var = _self->score__var; /* double */
  double subtract = _self->subtract; /* double */
  kk_drop_match(_self, {kk_std_core__list_dup(vs);kk_std_core__list_dup(ys);;;;}, {}, _ctx)
  kk_ref_t loc = kk_ref_alloc((kk_std_core__list_box(kk_std_core__new_Nil(_ctx), _ctx)),kk_context()); /*local-var<global,list<double>>*/;
  kk_std_core__list res;
  kk_unit_t x0_2870 = kk_Unit;
  kk_function_t _x3677;
  kk_ref_dup(loc);
  _x3677 = kk_climate_dash_change_new_linear__gaussian__climate__data_fun3678(loc, vs, ys, diff, score__var, subtract, _ctx); /*(i : int) -> <exn,local<global>,effects-and-types/sample,effects-and-types/score> ()*/
  kk_std_core__lift21056_for(_x3677, kk_integer_from_small(12), kk_integer_from_small(0), _ctx);
  if (kk_yielding(kk_context())) {
    kk_box_t _x3706;
    kk_function_t _x3707;
    kk_ref_dup(loc);
    _x3707 = kk_climate_dash_change_new_linear__gaussian__climate__data_fun3708(loc, _ctx); /*(1) -> 3 2*/
    _x3706 = kk_std_core_hnd_yield_extend(_x3707, _ctx); /*2*/
    res = kk_std_core__list_unbox(_x3706, _ctx); /*list<double>*/
  }
  else {
    kk_ref_t _x3711 = kk_ref_dup(loc); /*local-var<global,list<double>>*/
    res = kk_climate_dash_change__mlift2768_linear__gaussian__climate__data(_x3711, x0_2870, _ctx); /*list<double>*/
  }
  kk_box_t _x3712 = kk_std_core_hnd_prompt_local_var(loc, kk_std_core__list_box(res, _ctx), _ctx); /*2*/
  return kk_std_core__list_unbox(_x3712, _ctx);
}

kk_function_t kk_climate_dash_change_linear__gaussian__climate__data(kk_std_core__list ys, kk_std_core__list vs, bool print, double diff, double subtract, double score__var, kk_context_t* _ctx) { /* (ys : list<effects-and-types/row_vector>, vs : list<effects-and-types/row_vector>, print : bool, diff : double, subtract : double, score_var : double) -> effects-and-types/model<list<double>,exn> */ 
  return kk_climate_dash_change_new_linear__gaussian__climate__data_fun3676(vs, ys, diff, score__var, subtract, _ctx);
}

// initialization
void kk_climate_dash_change__init(kk_context_t* _ctx){
  static bool _initialized = false;
  if (_initialized) return;
  _initialized = true;
  kk_std_core_types__init(_ctx);
  kk_std_core_hnd__init(_ctx);
  kk_std_core__init(_ctx);
  kk_effects_dash_and_dash_types__init(_ctx);
  kk_exn_dash_get__init(_ctx);
  kk_model_dash_resources__init(_ctx);
}
