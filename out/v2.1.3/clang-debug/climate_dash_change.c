// Koka generated module: "climate-change", koka version: 2.1.3
#include "climate_dash_change.h"
 
// monadic lift


// lift anonymous function
struct kk_climate_dash_change__mlift2678_convert__uncertainty__to__rand_fun3394__t {
  struct kk_function_s _base;
  double _x20;
};
static kk_box_t kk_climate_dash_change__mlift2678_convert__uncertainty__to__rand_fun3394(kk_function_t _fself, kk_box_t _b_2843, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change__new_mlift2678_convert__uncertainty__to__rand_fun3394(double _x20, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2678_convert__uncertainty__to__rand_fun3394__t* _self = kk_function_alloc_as(struct kk_climate_dash_change__mlift2678_convert__uncertainty__to__rand_fun3394__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_change__mlift2678_convert__uncertainty__to__rand_fun3394, kk_context());
  _self->_x20 = _x20;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_change__mlift2678_convert__uncertainty__to__rand_fun3394(kk_function_t _fself, kk_box_t _b_2843, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2678_convert__uncertainty__to__rand_fun3394__t* _self = kk_function_as(struct kk_climate_dash_change__mlift2678_convert__uncertainty__to__rand_fun3394__t*, _fself);
  double _x20 = _self->_x20; /* double */
  kk_drop_match(_self, {;}, {}, _ctx)
  double _x3395;
  double _x3396 = kk_double_unbox(_b_2843, _ctx); /*double*/
  _x3395 = kk_model_dash_resources__mlift3175_normal(0x0p+0, _x20, _x3396, _ctx); /*double*/
  return kk_double_box(_x3395, _ctx);
}


// lift anonymous function
struct kk_climate_dash_change__mlift2678_convert__uncertainty__to__rand_fun3399__t {
  struct kk_function_s _base;
  size_t i_2697;
};
static kk_box_t kk_climate_dash_change__mlift2678_convert__uncertainty__to__rand_fun3399(kk_function_t _fself, kk_function_t _b_2851, kk_box_t _b_2852, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change__new_mlift2678_convert__uncertainty__to__rand_fun3399(size_t i_2697, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2678_convert__uncertainty__to__rand_fun3399__t* _self = kk_function_alloc_as(struct kk_climate_dash_change__mlift2678_convert__uncertainty__to__rand_fun3399__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_change__mlift2678_convert__uncertainty__to__rand_fun3399, kk_context());
  _self->i_2697 = i_2697;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_change__mlift2678_convert__uncertainty__to__rand_fun3399(kk_function_t _fself, kk_function_t _b_2851, kk_box_t _b_2852, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2678_convert__uncertainty__to__rand_fun3399__t* _self = kk_function_as(struct kk_climate_dash_change__mlift2678_convert__uncertainty__to__rand_fun3399__t*, _fself);
  size_t i_2697 = _self->i_2697; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_2697, _b_2851, _b_2852, _ctx);
}

double kk_climate_dash_change__mlift2678_convert__uncertainty__to__rand(double uncertainty, kk_context_t* _ctx) { /* (uncertainty : double) -> <exn,effects-and-types/sample> double */ 
  double _x20 = (uncertainty / (0x1.f5c28f5c28f5cp1)); /*double*/;
  size_t i_2697 = ((size_t)1); /*std/core/hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_2697,kk_context()); /*std/core/hnd/evv<<effects-and-types/sample,exn>>*/;
  double y;
  double x_3267 = kk_model_dash_resources_standard_normal(_ctx); /*double*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x3393 = kk_std_core_hnd_yield_extend(kk_climate_dash_change__new_mlift2678_convert__uncertainty__to__rand_fun3394(_x20, _ctx), _ctx); /*2*/
    y = kk_double_unbox(_x3393, _ctx); /*double*/
  }
  else {
    double _x3397 = (x_3267 * _x20); /*double*/
    y = ((0x0p+0) + _x3397); /*double*/
  }
  kk_unit_t __w_l717_c9 = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x3398 = kk_std_core_hnd_yield_cont(kk_climate_dash_change__new_mlift2678_convert__uncertainty__to__rand_fun3399(i_2697, _ctx), _ctx); /*3*/
    return kk_double_unbox(_x3398, _ctx);
  }
  return y;
}


// lift anonymous function
struct kk_climate_dash_change_convert__uncertainty__to__rand_fun3402__t {
  struct kk_function_s _base;
  kk_std_core__list vs;
};
static kk_box_t kk_climate_dash_change_convert__uncertainty__to__rand_fun3402(kk_function_t _fself, kk_integer_t _b_2886, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change_new_convert__uncertainty__to__rand_fun3402(kk_std_core__list vs, kk_context_t* _ctx) {
  struct kk_climate_dash_change_convert__uncertainty__to__rand_fun3402__t* _self = kk_function_alloc_as(struct kk_climate_dash_change_convert__uncertainty__to__rand_fun3402__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_change_convert__uncertainty__to__rand_fun3402, kk_context());
  _self->vs = vs;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_change_convert__uncertainty__to__rand_fun3406__t {
  struct kk_function_s _base;
  size_t i0_2706;
};
static kk_box_t kk_climate_dash_change_convert__uncertainty__to__rand_fun3406(kk_function_t _fself, kk_function_t _b_2870, kk_box_t _b_2871, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change_new_convert__uncertainty__to__rand_fun3406(size_t i0_2706, kk_context_t* _ctx) {
  struct kk_climate_dash_change_convert__uncertainty__to__rand_fun3406__t* _self = kk_function_alloc_as(struct kk_climate_dash_change_convert__uncertainty__to__rand_fun3406__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_change_convert__uncertainty__to__rand_fun3406, kk_context());
  _self->i0_2706 = i0_2706;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_change_convert__uncertainty__to__rand_fun3406(kk_function_t _fself, kk_function_t _b_2870, kk_box_t _b_2871, kk_context_t* _ctx) {
  struct kk_climate_dash_change_convert__uncertainty__to__rand_fun3406__t* _self = kk_function_as(struct kk_climate_dash_change_convert__uncertainty__to__rand_fun3406__t*, _fself);
  size_t i0_2706 = _self->i0_2706; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i0_2706, _b_2870, _b_2871, _ctx);
}


// lift anonymous function
struct kk_climate_dash_change_convert__uncertainty__to__rand_fun3408__t {
  struct kk_function_s _base;
};
static kk_box_t kk_climate_dash_change_convert__uncertainty__to__rand_fun3408(kk_function_t _fself, kk_box_t _b_2881, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change_new_convert__uncertainty__to__rand_fun3408(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_climate_dash_change_convert__uncertainty__to__rand_fun3408, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_climate_dash_change_convert__uncertainty__to__rand_fun3408(kk_function_t _fself, kk_box_t _b_2881, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x3409;
  double _x3410 = kk_double_unbox(_b_2881, _ctx); /*double*/
  _x3409 = kk_climate_dash_change__mlift2678_convert__uncertainty__to__rand(_x3410, _ctx); /*double*/
  return kk_double_box(_x3409, _ctx);
}
static kk_box_t kk_climate_dash_change_convert__uncertainty__to__rand_fun3402(kk_function_t _fself, kk_integer_t _b_2886, kk_context_t* _ctx) {
  struct kk_climate_dash_change_convert__uncertainty__to__rand_fun3402__t* _self = kk_function_as(struct kk_climate_dash_change_convert__uncertainty__to__rand_fun3402__t*, _fself);
  kk_std_core__list vs = _self->vs; /* effects-and-types/row_vector */
  kk_drop_match(_self, {kk_std_core__list_dup(vs);}, {}, _ctx)
  double _x3403;
  double x_2704;
  size_t i0_2706 = ((size_t)0); /*std/core/hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i0_2706,kk_context()); /*std/core/hnd/evv<<exn,effects-and-types/sample>>*/;
  double y;
  kk_box_t _x3404 = kk_exn_dash_get_exn_get(vs, _b_2886, _ctx); /*0*/
  y = kk_double_unbox(_x3404, _ctx); /*double*/
  kk_unit_t __w_l717_c9 = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x3405 = kk_std_core_hnd_yield_cont(kk_climate_dash_change_new_convert__uncertainty__to__rand_fun3406(i0_2706, _ctx), _ctx); /*3*/
    x_2704 = kk_double_unbox(_x3405, _ctx); /*double*/
  }
  else {
    x_2704 = y; /*double*/
  }
  if (kk_yielding(kk_context())) {
    kk_box_t _x3407 = kk_std_core_hnd_yield_extend(kk_climate_dash_change_new_convert__uncertainty__to__rand_fun3408(_ctx), _ctx); /*2*/
    _x3403 = kk_double_unbox(_x3407, _ctx); /*double*/
  }
  else {
    _x3403 = kk_climate_dash_change__mlift2678_convert__uncertainty__to__rand(x_2704, _ctx); /*double*/
  }
  return kk_double_box(_x3403, _ctx);
}

kk_std_core__list kk_climate_dash_change_convert__uncertainty__to__rand(kk_std_core__list vs, kk_context_t* _ctx) { /* (vs : effects-and-types/row_vector) -> <exn,effects-and-types/sample> effects-and-types/row_vector */ 
  kk_integer_t hi_2702;
  kk_integer_t _x3400;
  kk_std_core__list _x3401 = kk_std_core__list_dup(vs); /*effects-and-types/row_vector*/
  _x3400 = kk_std_core_length_1(_x3401, _ctx); /*int*/
  hi_2702 = kk_integer_sub(_x3400,(kk_integer_from_small(1)),kk_context()); /*int*/
  return kk_std_core__lift21054_list_1(kk_climate_dash_change_new_convert__uncertainty__to__rand_fun3402(vs, _ctx), kk_integer_from_small(0), hi_2702, kk_std_core__new_Nil(_ctx), _ctx);
}
extern double kk_climate_dash_change_mult__thunk_fun3411(kk_function_t _fself, double v, kk_context_t* _ctx) {
  struct kk_climate_dash_change_mult__thunk_fun3411__t* _self = kk_function_as(struct kk_climate_dash_change_mult__thunk_fun3411__t*, _fself);
  double x = _self->x; /* double */
  kk_drop_match(_self, {;}, {}, _ctx)
  return (x * v);
}
extern kk_box_t kk_climate_dash_change_multivariate__gaussian_fun3412(kk_function_t _fself, kk_integer_t _b_2897, kk_context_t* _ctx) {
  struct kk_climate_dash_change_multivariate__gaussian_fun3412__t* _self = kk_function_as(struct kk_climate_dash_change_multivariate__gaussian_fun3412__t*, _fself);
  double mean = _self->mean; /* double */
  double std__dev = _self->std__dev; /* double */
  kk_drop_match(_self, {;;}, {}, _ctx)
  kk_integer_drop(_b_2897, _ctx);
  double _x3413 = kk_model_dash_resources_normal(mean, std__dev, _ctx); /*double*/
  return kk_double_box(_x3413, _ctx);
}


// lift anonymous function
struct kk_climate_dash_change_plus_fun3436__t {
  struct kk_function_s _base;
};
static kk_box_t kk_climate_dash_change_plus_fun3436(kk_function_t _fself, kk_box_t _b_2915, kk_box_t _b_2916, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change_new_plus_fun3436(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_climate_dash_change_plus_fun3436, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_climate_dash_change_plus_fun3436(kk_function_t _fself, kk_box_t _b_2915, kk_box_t _b_2916, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x3437;
  double _x3438 = kk_double_unbox(_b_2915, _ctx); /*double*/
  double _x3439 = kk_double_unbox(_b_2916, _ctx); /*double*/
  _x3437 = (_x3438 + _x3439); /*double*/
  return kk_double_box(_x3437, _ctx);
}

kk_std_core__list kk_climate_dash_change_plus(kk_std_core__list xs, kk_std_core__list ys, kk_context_t* _ctx) { /* (xs : effects-and-types/row_vector, ys : effects-and-types/row_vector) -> exn effects-and-types/row_vector */ 
  bool _match_3386;
  kk_integer_t _x3414;
  kk_std_core__list _x3415 = kk_std_core__list_dup(xs); /*effects-and-types/row_vector*/
  _x3414 = kk_std_core_length_1(_x3415, _ctx); /*int*/
  kk_integer_t _x3416;
  kk_std_core__list _x3417 = kk_std_core__list_dup(ys); /*effects-and-types/row_vector*/
  _x3416 = kk_std_core_length_1(_x3417, _ctx); /*int*/
  _match_3386 = kk_integer_neq(_x3414,_x3416,kk_context()); /*bool*/
  if (_match_3386) {
    kk_string_t message_2713;
    kk_string_t _x3418;
    kk_define_string_literal(, _s3419, 38, "AdditionError: Lengths are not equal! ")
    _x3418 = kk_string_dup(_s3419); /*string*/
    kk_string_t _x3420;
    kk_string_t _x3421;
    kk_integer_t _x3422 = kk_std_core_length_1(xs, _ctx); /*int*/
    _x3421 = kk_std_core_show(_x3422, _ctx); /*string*/
    kk_string_t _x3423;
    kk_string_t _x3424;
    kk_define_string_literal(, _s3425, 4, " vs ")
    _x3424 = kk_string_dup(_s3425); /*string*/
    kk_string_t _x3426;
    kk_integer_t _x3427 = kk_std_core_length_1(ys, _ctx); /*int*/
    _x3426 = kk_std_core_show(_x3427, _ctx); /*string*/
    _x3423 = kk_std_core__lp__plus__plus__1_rp_(_x3424, _x3426, _ctx); /*string*/
    _x3420 = kk_std_core__lp__plus__plus__1_rp_(_x3421, _x3423, _ctx); /*string*/
    message_2713 = kk_std_core__lp__plus__plus__1_rp_(_x3418, _x3420, _ctx); /*string*/
    kk_std_core__exception exn_21561;
    kk_std_core__exception_info _x3428;
    kk_std_core_types__optional _match_3388 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
    if (kk_std_core_types__is_Optional(_match_3388)) {
      kk_box_t _box_x2903 = _match_3388._cons.Optional.value;
      kk_std_core__exception_info _info_14279 = kk_std_core__exception_info_unbox(_box_x2903, NULL);
      kk_std_core__exception_info_dup(_info_14279);
      kk_std_core_types__optional_drop(_match_3388, _ctx);
      _x3428 = _info_14279; /*exception-info*/
      goto _match3429;
    }
    _x3428 = kk_std_core__new_ExnError(_ctx); /*exception-info*/
    _match3429: ;
    exn_21561 = kk_std_core__new_Exception(message_2713, _x3428, _ctx); /*exception*/
    kk_std_core_hnd__ev ev_21562;
    size_t _x3431 = ((size_t)0); /*size_t*/
    ev_21562 = kk_evv_at(_x3431,kk_context()); /*std/core/hnd/ev<.hnd-exn>*/
    kk_box_t _x3432;
    struct kk_std_core_hnd_Ev* _con3433 = kk_std_core_hnd__as_Ev(ev_21562);
    kk_std_core_hnd__marker m = _con3433->marker;
    kk_box_t _box_x2904 = _con3433->hnd;
    kk_std_core__hnd_exn h = kk_std_core__hnd_exn_unbox(_box_x2904, NULL);
    kk_std_core__hnd_exn_dup(h);
    kk_std_core_hnd__clause1 _match_3387;
    struct kk_std_core__Hnd_exn* _con3435 = kk_std_core__as_Hnd_exn(h);
    kk_std_core_hnd__clause1 except_throw_exn = _con3435->except_throw_exn;
    if (kk_std_core__hnd_exn_is_unique(h)) {
      kk_std_core__hnd_exn_free(h);
    }
    else {
      kk_std_core_hnd__clause1_dup(except_throw_exn);
      kk_std_core__hnd_exn_decref(h, _ctx);
    }
    _match_3387 = except_throw_exn; /*forall<a> std/core/hnd/clause1<exception,a,.hnd-exn,6,7>*/
    kk_function_t _fun_unbox_x2908 = _match_3387.clause;
    _x3432 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x2908, (_fun_unbox_x2908, m, ev_21562, kk_std_core__exception_box(exn_21561, _ctx), _ctx)); /*11*/
    return kk_std_core__list_unbox(_x3432, _ctx);
  }
  return kk_std_core_zipwith(xs, ys, kk_climate_dash_change_new_plus_fun3436(_ctx), _ctx);
}


// lift anonymous function
struct kk_climate_dash_change_score__thunk_fun3440__t {
  struct kk_function_s _base;
  double score__std__dev;
};
static kk_unit_t kk_climate_dash_change_score__thunk_fun3440(kk_function_t _fself, double true__val, double pred__val, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change_new_score__thunk_fun3440(double score__std__dev, kk_context_t* _ctx) {
  struct kk_climate_dash_change_score__thunk_fun3440__t* _self = kk_function_alloc_as(struct kk_climate_dash_change_score__thunk_fun3440__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_change_score__thunk_fun3440, kk_context());
  _self->score__std__dev = score__std__dev;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_change_score__thunk_fun3442__t {
  struct kk_function_s _base;
};
static kk_box_t kk_climate_dash_change_score__thunk_fun3442(kk_function_t _fself, kk_box_t _b_2927, kk_box_t _b_2928, kk_box_t _b_2929, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change_new_score__thunk_fun3442(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_climate_dash_change_score__thunk_fun3442, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_climate_dash_change_score__thunk_fun3442(kk_function_t _fself, kk_box_t _b_2927, kk_box_t _b_2928, kk_box_t _b_2929, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_effects_dash_and_dash_types__exp _x3443;
  double _x3444 = kk_double_unbox(_b_2927, _ctx); /*double*/
  double _x3445 = kk_double_unbox(_b_2928, _ctx); /*double*/
  double _x3446 = kk_double_unbox(_b_2929, _ctx); /*double*/
  _x3443 = kk_model_dash_resources_normal__pdf(_x3444, _x3445, _x3446, _ctx); /*effects-and-types/exp*/
  return kk_effects_dash_and_dash_types__exp_box(_x3443, _ctx);
}


// lift anonymous function
struct kk_climate_dash_change_score__thunk_fun3449__t {
  struct kk_function_s _base;
  size_t i_2715;
};
static kk_box_t kk_climate_dash_change_score__thunk_fun3449(kk_function_t _fself, kk_function_t _b_2939, kk_box_t _b_2940, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change_new_score__thunk_fun3449(size_t i_2715, kk_context_t* _ctx) {
  struct kk_climate_dash_change_score__thunk_fun3449__t* _self = kk_function_alloc_as(struct kk_climate_dash_change_score__thunk_fun3449__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_change_score__thunk_fun3449, kk_context());
  _self->i_2715 = i_2715;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_change_score__thunk_fun3449(kk_function_t _fself, kk_function_t _b_2939, kk_box_t _b_2940, kk_context_t* _ctx) {
  struct kk_climate_dash_change_score__thunk_fun3449__t* _self = kk_function_as(struct kk_climate_dash_change_score__thunk_fun3449__t*, _fself);
  size_t i_2715 = _self->i_2715; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_2715, _b_2939, _b_2940, _ctx);
}
static kk_unit_t kk_climate_dash_change_score__thunk_fun3440(kk_function_t _fself, double true__val, double pred__val, kk_context_t* _ctx) {
  struct kk_climate_dash_change_score__thunk_fun3440__t* _self = kk_function_as(struct kk_climate_dash_change_score__thunk_fun3440__t*, _fself);
  double score__std__dev = _self->score__std__dev; /* double */
  kk_drop_match(_self, {;}, {}, _ctx)
  kk_effects_dash_and_dash_types__exp _x1;
  kk_box_t _x3441 = kk_std_core_hnd__open_none3(kk_climate_dash_change_new_score__thunk_fun3442(_ctx), kk_double_box(pred__val, _ctx), kk_double_box(score__std__dev, _ctx), kk_double_box(true__val, _ctx), _ctx); /*4*/
  _x1 = kk_effects_dash_and_dash_types__exp_unbox(_x3441, _ctx); /*effects-and-types/exp*/
  size_t i_2715;
  kk_std_core_hnd__htag _x3447 = kk_std_core_hnd__htag_dup(kk_effects_dash_and_dash_types__tag_score); /*std/core/hnd/htag<effects-and-types/.hnd-score>*/
  i_2715 = kk_std_core_hnd__evv_index(_x3447, _ctx); /*std/core/hnd/ev-index*/
  kk_evv_t w = kk_evv_swap_create1(i_2715,kk_context()); /*std/core/hnd/evv<<effects-and-types/score|1091>>*/;
  kk_unit_t y = kk_Unit;
  kk_effects_dash_and_dash_types_score(_x1, _ctx);
  kk_unit_t __w_l700_c9 = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x3448 = kk_std_core_hnd_yield_cont(kk_climate_dash_change_new_score__thunk_fun3449(i_2715, _ctx), _ctx); /*3*/
    return kk_unit_unbox(_x3448);
  }
  return y;
}

kk_function_t kk_climate_dash_change_score__thunk(double score__std__dev, kk_context_t* _ctx) { /* forall<e> (score_std_dev : double) -> ((true_val : double, pred_val : double) -> <effects-and-types/score|e> ()) */ 
  return kk_climate_dash_change_new_score__thunk_fun3440(score__std__dev, _ctx);
}
extern kk_box_t kk_climate_dash_change_mult_fun3450(kk_function_t _fself, kk_box_t _b_2951, kk_context_t* _ctx) {
  struct kk_climate_dash_change_mult_fun3450__t* _self = kk_function_as(struct kk_climate_dash_change_mult_fun3450__t*, _fself);
  kk_function_t _b_2953_2950 = _self->_b_2953_2950; /* (v : double) -> double */
  kk_drop_match(_self, {kk_function_dup(_b_2953_2950);}, {}, _ctx)
  double _x3451;
  double _x3452 = kk_double_unbox(_b_2951, _ctx); /*double*/
  _x3451 = kk_function_call(double, (kk_function_t, double, kk_context_t*), _b_2953_2950, (_b_2953_2950, _x3452, _ctx)); /*double*/
  return kk_double_box(_x3451, _ctx);
}


// lift anonymous function
struct kk_climate_dash_change_score__predictions_fun3476__t {
  struct kk_function_s _base;
  size_t i_2718;
};
static kk_box_t kk_climate_dash_change_score__predictions_fun3476(kk_function_t _fself, kk_function_t _b_2971, kk_box_t _b_2972, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change_new_score__predictions_fun3476(size_t i_2718, kk_context_t* _ctx) {
  struct kk_climate_dash_change_score__predictions_fun3476__t* _self = kk_function_alloc_as(struct kk_climate_dash_change_score__predictions_fun3476__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_change_score__predictions_fun3476, kk_context());
  _self->i_2718 = i_2718;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_change_score__predictions_fun3476(kk_function_t _fself, kk_function_t _b_2971, kk_box_t _b_2972, kk_context_t* _ctx) {
  struct kk_climate_dash_change_score__predictions_fun3476__t* _self = kk_function_as(struct kk_climate_dash_change_score__predictions_fun3476__t*, _fself);
  size_t i_2718 = _self->i_2718; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_2718, _b_2971, _b_2972, _ctx);
}


// lift anonymous function
struct kk_climate_dash_change_score__predictions_fun3477__t {
  struct kk_function_s _base;
  kk_function_t _b_2988_2976;
};
static kk_box_t kk_climate_dash_change_score__predictions_fun3477(kk_function_t _fself, kk_box_t _b_2977, kk_box_t _b_2978, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change_new_score__predictions_fun3477(kk_function_t _b_2988_2976, kk_context_t* _ctx) {
  struct kk_climate_dash_change_score__predictions_fun3477__t* _self = kk_function_alloc_as(struct kk_climate_dash_change_score__predictions_fun3477__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_change_score__predictions_fun3477, kk_context());
  _self->_b_2988_2976 = _b_2988_2976;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_change_score__predictions_fun3477(kk_function_t _fself, kk_box_t _b_2977, kk_box_t _b_2978, kk_context_t* _ctx) {
  struct kk_climate_dash_change_score__predictions_fun3477__t* _self = kk_function_as(struct kk_climate_dash_change_score__predictions_fun3477__t*, _fself);
  kk_function_t _b_2988_2976 = _self->_b_2988_2976; /* (true_val : double, pred_val : double) -> <effects-and-types/score,exn> () */
  kk_drop_match(_self, {kk_function_dup(_b_2988_2976);}, {}, _ctx)
  kk_unit_t _x3478 = kk_Unit;
  double _x3479 = kk_double_unbox(_b_2977, _ctx); /*double*/
  double _x3480 = kk_double_unbox(_b_2978, _ctx); /*double*/
  kk_function_call(kk_unit_t, (kk_function_t, double, double, kk_context_t*), _b_2988_2976, (_b_2988_2976, _x3479, _x3480, _ctx));
  return kk_unit_box(_x3478);
}

kk_std_core__list kk_climate_dash_change_score__predictions(kk_std_core__list true__values, kk_std_core__list predicted__values, double score__std__dev, kk_context_t* _ctx) { /* (true_values : effects-and-types/row_vector, predicted_values : effects-and-types/row_vector, score_std_dev : double) -> <exn,effects-and-types/score> list<()> */ 
  bool _match_3381;
  kk_integer_t _x3453;
  kk_std_core__list _x3454 = kk_std_core__list_dup(true__values); /*effects-and-types/row_vector*/
  _x3453 = kk_std_core_length_1(_x3454, _ctx); /*int*/
  kk_integer_t _x3455;
  kk_std_core__list _x3456 = kk_std_core__list_dup(predicted__values); /*effects-and-types/row_vector*/
  _x3455 = kk_std_core_length_1(_x3456, _ctx); /*int*/
  _match_3381 = kk_integer_neq(_x3453,_x3455,kk_context()); /*bool*/
  if (_match_3381) {
    kk_string_t _x1;
    kk_string_t _x3457;
    kk_define_string_literal(, _s3458, 71, "LengthError: predicted values and true values must be the same length! ")
    _x3457 = kk_string_dup(_s3458); /*string*/
    kk_string_t _x3459;
    kk_string_t _x3460;
    kk_integer_t _x3461 = kk_std_core_length_1(true__values, _ctx); /*int*/
    _x3460 = kk_std_core_show(_x3461, _ctx); /*string*/
    kk_string_t _x3462;
    kk_string_t _x3463;
    kk_define_string_literal(, _s3464, 4, " vs ")
    _x3463 = kk_string_dup(_s3464); /*string*/
    kk_string_t _x3465;
    kk_integer_t _x3466 = kk_std_core_length_1(predicted__values, _ctx); /*int*/
    _x3465 = kk_std_core_show(_x3466, _ctx); /*string*/
    _x3462 = kk_std_core__lp__plus__plus__1_rp_(_x3463, _x3465, _ctx); /*string*/
    _x3459 = kk_std_core__lp__plus__plus__1_rp_(_x3460, _x3462, _ctx); /*string*/
    _x1 = kk_std_core__lp__plus__plus__1_rp_(_x3457, _x3459, _ctx); /*string*/
    size_t i_2718 = ((size_t)0); /*std/core/hnd/ev-index*/;
    kk_evv_t w = kk_evv_swap_create1(i_2718,kk_context()); /*std/core/hnd/evv<<exn,effects-and-types/score>>*/;
    kk_std_core__list y;
    kk_std_core__exception exn_21561;
    kk_std_core__exception_info _x3467;
    kk_std_core_types__optional _match_3384 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
    if (kk_std_core_types__is_Optional(_match_3384)) {
      kk_box_t _box_x2954 = _match_3384._cons.Optional.value;
      kk_std_core__exception_info _info_14279 = kk_std_core__exception_info_unbox(_box_x2954, NULL);
      kk_std_core__exception_info_dup(_info_14279);
      kk_std_core_types__optional_drop(_match_3384, _ctx);
      _x3467 = _info_14279; /*exception-info*/
      goto _match3468;
    }
    _x3467 = kk_std_core__new_ExnError(_ctx); /*exception-info*/
    _match3468: ;
    exn_21561 = kk_std_core__new_Exception(_x1, _x3467, _ctx); /*exception*/
    kk_std_core_hnd__ev ev_21562;
    size_t _x3470 = ((size_t)0); /*size_t*/
    ev_21562 = kk_evv_at(_x3470,kk_context()); /*std/core/hnd/ev<.hnd-exn>*/
    kk_box_t _x3471;
    struct kk_std_core_hnd_Ev* _con3472 = kk_std_core_hnd__as_Ev(ev_21562);
    kk_std_core_hnd__marker m = _con3472->marker;
    kk_box_t _box_x2955 = _con3472->hnd;
    kk_std_core__hnd_exn h = kk_std_core__hnd_exn_unbox(_box_x2955, NULL);
    kk_std_core__hnd_exn_dup(h);
    kk_std_core_hnd__clause1 _match_3383;
    struct kk_std_core__Hnd_exn* _con3474 = kk_std_core__as_Hnd_exn(h);
    kk_std_core_hnd__clause1 except_throw_exn = _con3474->except_throw_exn;
    if (kk_std_core__hnd_exn_is_unique(h)) {
      kk_std_core__hnd_exn_free(h);
    }
    else {
      kk_std_core_hnd__clause1_dup(except_throw_exn);
      kk_std_core__hnd_exn_decref(h, _ctx);
    }
    _match_3383 = except_throw_exn; /*forall<a> std/core/hnd/clause1<exception,a,.hnd-exn,6,7>*/
    kk_function_t _fun_unbox_x2959 = _match_3383.clause;
    _x3471 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x2959, (_fun_unbox_x2959, m, ev_21562, kk_std_core__exception_box(exn_21561, _ctx), _ctx)); /*11*/
    y = kk_std_core__list_unbox(_x3471, _ctx); /*list<()>*/
    kk_unit_t __w_l717_c9 = kk_Unit;
    kk_evv_set(w,kk_context());
    if (kk_yielding(kk_context())) {
      kk_std_core__list_drop(y, _ctx);
      kk_box_t _x3475 = kk_std_core_hnd_yield_cont(kk_climate_dash_change_new_score__predictions_fun3476(i_2718, _ctx), _ctx); /*3*/
      return kk_std_core__list_unbox(_x3475, _ctx);
    }
    return y;
  }
  kk_function_t _b_2988_2976;
  kk_evv_t w0 = kk_evv_swap_create0(kk_context()); /*std/core/hnd/evv<(<>)>*/;
  kk_function_t x = kk_climate_dash_change_score__thunk(score__std__dev, _ctx); /*(true_val : double, pred_val : double) -> <effects-and-types/score,exn> ()*/;
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w0,kk_context());
  _b_2988_2976 = x; /*(true_val : double, pred_val : double) -> <effects-and-types/score,exn> ()*/
  return kk_std_core_zipwith(true__values, predicted__values, kk_climate_dash_change_new_score__predictions_fun3477(_b_2988_2976, _ctx), _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_climate_dash_change__mlift2679_linear__gaussian__climate__data_fun3483__t {
  struct kk_function_s _base;
  size_t i_2724;
};
static kk_box_t kk_climate_dash_change__mlift2679_linear__gaussian__climate__data_fun3483(kk_function_t _fself, kk_function_t _b_2998, kk_box_t _b_2999, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change__new_mlift2679_linear__gaussian__climate__data_fun3483(size_t i_2724, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2679_linear__gaussian__climate__data_fun3483__t* _self = kk_function_alloc_as(struct kk_climate_dash_change__mlift2679_linear__gaussian__climate__data_fun3483__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_change__mlift2679_linear__gaussian__climate__data_fun3483, kk_context());
  _self->i_2724 = i_2724;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_change__mlift2679_linear__gaussian__climate__data_fun3483(kk_function_t _fself, kk_function_t _b_2998, kk_box_t _b_2999, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2679_linear__gaussian__climate__data_fun3483__t* _self = kk_function_as(struct kk_climate_dash_change__mlift2679_linear__gaussian__climate__data_fun3483__t*, _fself);
  size_t i_2724 = _self->i_2724; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_2724, _b_2998, _b_2999, _ctx);
}

double kk_climate_dash_change__mlift2679_linear__gaussian__climate__data(kk_integer_t i0, kk_std_core__list _y_31, kk_context_t* _ctx) { /* forall<h> (i0 : int, list<double>) -> <local<h>,exn,effects-and-types/sample,effects-and-types/score> double */ 
  size_t i_2724 = ((size_t)0); /*std/core/hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_2724,kk_context()); /*std/core/hnd/evv<<exn,local<2652>,effects-and-types/sample,effects-and-types/score>>*/;
  double y;
  kk_box_t _x3481 = kk_exn_dash_get_exn_get(_y_31, i0, _ctx); /*0*/
  y = kk_double_unbox(_x3481, _ctx); /*double*/
  kk_unit_t __w_l717_c9 = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x3482 = kk_std_core_hnd_yield_cont(kk_climate_dash_change__new_mlift2679_linear__gaussian__climate__data_fun3483(i_2724, _ctx), _ctx); /*3*/
    return kk_double_unbox(_x3482, _ctx);
  }
  return y;
}
 
// monadic lift

kk_unit_t kk_climate_dash_change__mlift2680_linear__gaussian__climate__data(kk_std_core__list wild__0, kk_context_t* _ctx) { /* forall<h> (wild_0 : list<()>) -> <exn,effects-and-types/score,local<h>,effects-and-types/sample> () */ 
  kk_std_core__list_drop(wild__0, _ctx);
  kk_Unit; return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_climate_dash_change__mlift2681_linear__gaussian__climate__data_fun3486__t {
  struct kk_function_s _base;
};
static kk_box_t kk_climate_dash_change__mlift2681_linear__gaussian__climate__data_fun3486(kk_function_t _fself, kk_box_t _b_3017, kk_box_t _b_3018, kk_box_t _b_3019, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change__new_mlift2681_linear__gaussian__climate__data_fun3486(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_climate_dash_change__mlift2681_linear__gaussian__climate__data_fun3486, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_climate_dash_change__mlift2681_linear__gaussian__climate__data_fun3486(kk_function_t _fself, kk_box_t _b_3017, kk_box_t _b_3018, kk_box_t _b_3019, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core__list _x3487;
  kk_std_core__list _x3488 = kk_std_core__list_unbox(_b_3017, _ctx); /*effects-and-types/row_vector*/
  kk_std_core__list _x3489 = kk_std_core__list_unbox(_b_3018, _ctx); /*effects-and-types/row_vector*/
  double _x3490 = kk_double_unbox(_b_3019, _ctx); /*double*/
  _x3487 = kk_climate_dash_change_score__predictions(_x3488, _x3489, _x3490, _ctx); /*list<()>*/
  return kk_std_core__list_box(_x3487, _ctx);
}


// lift anonymous function
struct kk_climate_dash_change__mlift2681_linear__gaussian__climate__data_fun3492__t {
  struct kk_function_s _base;
};
static kk_box_t kk_climate_dash_change__mlift2681_linear__gaussian__climate__data_fun3492(kk_function_t _fself, kk_box_t _b_3030, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change__new_mlift2681_linear__gaussian__climate__data_fun3492(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_climate_dash_change__mlift2681_linear__gaussian__climate__data_fun3492, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_climate_dash_change__mlift2681_linear__gaussian__climate__data_fun3492(kk_function_t _fself, kk_box_t _b_3030, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_unit_t _x3493 = kk_Unit;
  kk_std_core__list _x3494 = kk_std_core__list_unbox(_b_3030, _ctx); /*list<()>*/
  kk_climate_dash_change__mlift2680_linear__gaussian__climate__data(_x3494, _ctx);
  return kk_unit_box(_x3493);
}

kk_unit_t kk_climate_dash_change__mlift2681_linear__gaussian__climate__data(kk_std_core__list month__ys, double score__var, kk_std_core__list predictions, kk_context_t* _ctx) { /* forall<h> (month_ys : effects-and-types/row_vector, score_var : double, predictions : effects-and-types/row_vector) -> <exn,local<h>,effects-and-types/score,effects-and-types/sample> () */ 
  kk_std_core__list x_2728;
  kk_vector_t _b_3020_3012;
  kk_std_core__list _x3484;
  size_t _b_3025_3010 = ((size_t)0); /*std/core/hnd/ev-index*/;
  kk_std_core__list _b_3026_3011;
  size_t _b_3027_3008 = ((size_t)2); /*std/core/hnd/ev-index*/;
  _b_3026_3011 = kk_std_core__new_Cons(kk_reuse_null, kk_size_box(_b_3027_3008, _ctx), kk_std_core__new_Nil(_ctx), _ctx); /*list<std/core/hnd/ev-index>*/
  _x3484 = kk_std_core__new_Cons(kk_reuse_null, kk_size_box(_b_3025_3010, _ctx), _b_3026_3011, _ctx); /*list<0>*/
  _b_3020_3012 = kk_std_core_unvlist(_x3484, _ctx); /*vector<std/core/hnd/ev-index>*/
  kk_box_t _x3485 = kk_std_core_hnd__open3(_b_3020_3012, kk_climate_dash_change__new_mlift2681_linear__gaussian__climate__data_fun3486(_ctx), kk_std_core__list_box(month__ys, _ctx), kk_std_core__list_box(predictions, _ctx), kk_double_box(score__var, _ctx), _ctx); /*4*/
  x_2728 = kk_std_core__list_unbox(_x3485, _ctx); /*list<()>*/
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_2728, _ctx);
    kk_box_t _x3491 = kk_std_core_hnd_yield_extend(kk_climate_dash_change__new_mlift2681_linear__gaussian__climate__data_fun3492(_ctx), _ctx); /*2*/
    kk_unit_unbox(_x3491); return kk_Unit;
  }
  kk_climate_dash_change__mlift2680_linear__gaussian__climate__data(x_2728, _ctx); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_climate_dash_change__mlift2682_linear__gaussian__climate__data_fun3496__t {
  struct kk_function_s _base;
};
static kk_box_t kk_climate_dash_change__mlift2682_linear__gaussian__climate__data_fun3496(kk_function_t _fself, kk_box_t _b_3036, kk_box_t _b_3037, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change__new_mlift2682_linear__gaussian__climate__data_fun3496(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_climate_dash_change__mlift2682_linear__gaussian__climate__data_fun3496, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_climate_dash_change__mlift2682_linear__gaussian__climate__data_fun3496(kk_function_t _fself, kk_box_t _b_3036, kk_box_t _b_3037, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core__list _x3497;
  double _x3498 = kk_double_unbox(_b_3036, _ctx); /*double*/
  kk_std_core__list _x3499 = kk_std_core__list_unbox(_b_3037, _ctx); /*effects-and-types/row_vector*/
  _x3497 = kk_climate_dash_change_mult(_x3498, _x3499, _ctx); /*effects-and-types/row_vector*/
  return kk_std_core__list_box(_x3497, _ctx);
}


// lift anonymous function
struct kk_climate_dash_change__mlift2682_linear__gaussian__climate__data_fun3501__t {
  struct kk_function_s _base;
  size_t i_2732;
};
static kk_box_t kk_climate_dash_change__mlift2682_linear__gaussian__climate__data_fun3501(kk_function_t _fself, kk_function_t _b_3046, kk_box_t _b_3047, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change__new_mlift2682_linear__gaussian__climate__data_fun3501(size_t i_2732, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2682_linear__gaussian__climate__data_fun3501__t* _self = kk_function_alloc_as(struct kk_climate_dash_change__mlift2682_linear__gaussian__climate__data_fun3501__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_change__mlift2682_linear__gaussian__climate__data_fun3501, kk_context());
  _self->i_2732 = i_2732;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_change__mlift2682_linear__gaussian__climate__data_fun3501(kk_function_t _fself, kk_function_t _b_3046, kk_box_t _b_3047, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2682_linear__gaussian__climate__data_fun3501__t* _self = kk_function_as(struct kk_climate_dash_change__mlift2682_linear__gaussian__climate__data_fun3501__t*, _fself);
  size_t i_2732 = _self->i_2732; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_2732, _b_3046, _b_3047, _ctx);
}


// lift anonymous function
struct kk_climate_dash_change__mlift2682_linear__gaussian__climate__data_fun3503__t {
  struct kk_function_s _base;
  kk_std_core__list month__ys;
  double score__var;
};
static kk_box_t kk_climate_dash_change__mlift2682_linear__gaussian__climate__data_fun3503(kk_function_t _fself, kk_box_t _b_3057, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change__new_mlift2682_linear__gaussian__climate__data_fun3503(kk_std_core__list month__ys, double score__var, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2682_linear__gaussian__climate__data_fun3503__t* _self = kk_function_alloc_as(struct kk_climate_dash_change__mlift2682_linear__gaussian__climate__data_fun3503__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_change__mlift2682_linear__gaussian__climate__data_fun3503, kk_context());
  _self->month__ys = month__ys;
  _self->score__var = score__var;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_change__mlift2682_linear__gaussian__climate__data_fun3503(kk_function_t _fself, kk_box_t _b_3057, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2682_linear__gaussian__climate__data_fun3503__t* _self = kk_function_as(struct kk_climate_dash_change__mlift2682_linear__gaussian__climate__data_fun3503__t*, _fself);
  kk_std_core__list month__ys = _self->month__ys; /* effects-and-types/row_vector */
  double score__var = _self->score__var; /* double */
  kk_drop_match(_self, {kk_std_core__list_dup(month__ys);;}, {}, _ctx)
  kk_unit_t _x3504 = kk_Unit;
  kk_std_core__list _x3505 = kk_std_core__list_unbox(_b_3057, _ctx); /*effects-and-types/row_vector*/
  kk_climate_dash_change__mlift2681_linear__gaussian__climate__data(month__ys, score__var, _x3505, _ctx);
  return kk_unit_box(_x3504);
}

kk_unit_t kk_climate_dash_change__mlift2682_linear__gaussian__climate__data(kk_std_core__list c__row, kk_std_core__list month__ys, double score__var, kk_std_core__list v__row, double _y_27, kk_context_t* _ctx) { /* forall<h> (c_row : list<double>, month_ys : effects-and-types/row_vector, score_var : double, v_row : effects-and-types/row_vector, double) -> <exn,local<h>,effects-and-types/score,effects-and-types/sample> () */ 
  kk_std_core__list x_2730;
  kk_std_core__list _x17;
  kk_box_t _x3495 = kk_std_core_hnd__open_none2(kk_climate_dash_change__new_mlift2682_linear__gaussian__climate__data_fun3496(_ctx), kk_double_box(_y_27, _ctx), kk_std_core__list_box(c__row, _ctx), _ctx); /*3*/
  _x17 = kk_std_core__list_unbox(_x3495, _ctx); /*effects-and-types/row_vector*/
  size_t i_2732 = ((size_t)0); /*std/core/hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_2732,kk_context()); /*std/core/hnd/evv<<exn,local<2652>,effects-and-types/score,effects-and-types/sample>>*/;
  kk_std_core__list y = kk_climate_dash_change_plus(_x17, v__row, _ctx); /*effects-and-types/row_vector*/;
  kk_unit_t __w_l717_c9 = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(y, _ctx);
    kk_box_t _x3500 = kk_std_core_hnd_yield_cont(kk_climate_dash_change__new_mlift2682_linear__gaussian__climate__data_fun3501(i_2732, _ctx), _ctx); /*3*/
    x_2730 = kk_std_core__list_unbox(_x3500, _ctx); /*effects-and-types/row_vector*/
  }
  else {
    x_2730 = y; /*effects-and-types/row_vector*/
  }
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_2730, _ctx);
    kk_box_t _x3502 = kk_std_core_hnd_yield_extend(kk_climate_dash_change__new_mlift2682_linear__gaussian__climate__data_fun3503(month__ys, score__var, _ctx), _ctx); /*2*/
    kk_unit_unbox(_x3502); return kk_Unit;
  }
  kk_climate_dash_change__mlift2681_linear__gaussian__climate__data(month__ys, score__var, x_2730, _ctx); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_climate_dash_change__mlift2683_linear__gaussian__climate__data_fun3508__t {
  struct kk_function_s _base;
  size_t i0_2738;
};
static kk_box_t kk_climate_dash_change__mlift2683_linear__gaussian__climate__data_fun3508(kk_function_t _fself, kk_function_t _b_3069, kk_box_t _b_3070, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change__new_mlift2683_linear__gaussian__climate__data_fun3508(size_t i0_2738, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2683_linear__gaussian__climate__data_fun3508__t* _self = kk_function_alloc_as(struct kk_climate_dash_change__mlift2683_linear__gaussian__climate__data_fun3508__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_change__mlift2683_linear__gaussian__climate__data_fun3508, kk_context());
  _self->i0_2738 = i0_2738;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_change__mlift2683_linear__gaussian__climate__data_fun3508(kk_function_t _fself, kk_function_t _b_3069, kk_box_t _b_3070, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2683_linear__gaussian__climate__data_fun3508__t* _self = kk_function_as(struct kk_climate_dash_change__mlift2683_linear__gaussian__climate__data_fun3508__t*, _fself);
  size_t i0_2738 = _self->i0_2738; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i0_2738, _b_3069, _b_3070, _ctx);
}


// lift anonymous function
struct kk_climate_dash_change__mlift2683_linear__gaussian__climate__data_fun3510__t {
  struct kk_function_s _base;
  kk_std_core__list c__row;
  kk_std_core__list month__ys;
  kk_std_core__list v__row;
  double score__var;
};
static kk_box_t kk_climate_dash_change__mlift2683_linear__gaussian__climate__data_fun3510(kk_function_t _fself, kk_box_t _b_3080, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change__new_mlift2683_linear__gaussian__climate__data_fun3510(kk_std_core__list c__row, kk_std_core__list month__ys, kk_std_core__list v__row, double score__var, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2683_linear__gaussian__climate__data_fun3510__t* _self = kk_function_alloc_as(struct kk_climate_dash_change__mlift2683_linear__gaussian__climate__data_fun3510__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_change__mlift2683_linear__gaussian__climate__data_fun3510, kk_context());
  _self->c__row = c__row;
  _self->month__ys = month__ys;
  _self->v__row = v__row;
  _self->score__var = score__var;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_change__mlift2683_linear__gaussian__climate__data_fun3510(kk_function_t _fself, kk_box_t _b_3080, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2683_linear__gaussian__climate__data_fun3510__t* _self = kk_function_as(struct kk_climate_dash_change__mlift2683_linear__gaussian__climate__data_fun3510__t*, _fself);
  kk_std_core__list c__row = _self->c__row; /* list<double> */
  kk_std_core__list month__ys = _self->month__ys; /* effects-and-types/row_vector */
  kk_std_core__list v__row = _self->v__row; /* effects-and-types/row_vector */
  double score__var = _self->score__var; /* double */
  kk_drop_match(_self, {kk_std_core__list_dup(c__row);kk_std_core__list_dup(month__ys);kk_std_core__list_dup(v__row);;}, {}, _ctx)
  kk_unit_t _x3511 = kk_Unit;
  double _x3512 = kk_double_unbox(_b_3080, _ctx); /*double*/
  kk_climate_dash_change__mlift2682_linear__gaussian__climate__data(c__row, month__ys, score__var, v__row, _x3512, _ctx);
  return kk_unit_box(_x3511);
}

kk_unit_t kk_climate_dash_change__mlift2683_linear__gaussian__climate__data(kk_std_core__list c__row, kk_integer_t i, kk_std_core__list month__ys, double score__var, kk_std_core__list v__row, kk_std_core__list _y_26, kk_context_t* _ctx) { /* forall<h> (c_row : list<double>, i : int, month_ys : effects-and-types/row_vector, score_var : double, v_row : effects-and-types/row_vector, list<double>) -> <local<h>,exn,effects-and-types/score,effects-and-types/sample> () */ 
  double x_2736;
  size_t i0_2738 = ((size_t)0); /*std/core/hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i0_2738,kk_context()); /*std/core/hnd/evv<<exn,local<2652>,effects-and-types/score,effects-and-types/sample>>*/;
  double y;
  kk_box_t _x3506 = kk_exn_dash_get_exn_get(_y_26, i, _ctx); /*0*/
  y = kk_double_unbox(_x3506, _ctx); /*double*/
  kk_unit_t __w_l717_c9 = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x3507 = kk_std_core_hnd_yield_cont(kk_climate_dash_change__new_mlift2683_linear__gaussian__climate__data_fun3508(i0_2738, _ctx), _ctx); /*3*/
    x_2736 = kk_double_unbox(_x3507, _ctx); /*double*/
  }
  else {
    x_2736 = y; /*double*/
  }
  if (kk_yielding(kk_context())) {
    kk_box_t _x3509 = kk_std_core_hnd_yield_extend(kk_climate_dash_change__new_mlift2683_linear__gaussian__climate__data_fun3510(c__row, month__ys, v__row, score__var, _ctx), _ctx); /*2*/
    kk_unit_unbox(_x3509); return kk_Unit;
  }
  kk_climate_dash_change__mlift2682_linear__gaussian__climate__data(c__row, month__ys, score__var, v__row, x_2736, _ctx); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_climate_dash_change__mlift2684_linear__gaussian__climate__data_fun3515__t {
  struct kk_function_s _base;
  kk_std_core__list c__row;
  kk_integer_t i;
  kk_std_core__list month__ys;
  kk_std_core__list v__row;
  double score__var;
};
static kk_box_t kk_climate_dash_change__mlift2684_linear__gaussian__climate__data_fun3515(kk_function_t _fself, kk_box_t _b_3086, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change__new_mlift2684_linear__gaussian__climate__data_fun3515(kk_std_core__list c__row, kk_integer_t i, kk_std_core__list month__ys, kk_std_core__list v__row, double score__var, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2684_linear__gaussian__climate__data_fun3515__t* _self = kk_function_alloc_as(struct kk_climate_dash_change__mlift2684_linear__gaussian__climate__data_fun3515__t, 5, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_change__mlift2684_linear__gaussian__climate__data_fun3515, kk_context());
  _self->c__row = c__row;
  _self->i = i;
  _self->month__ys = month__ys;
  _self->v__row = v__row;
  _self->score__var = score__var;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_change__mlift2684_linear__gaussian__climate__data_fun3515(kk_function_t _fself, kk_box_t _b_3086, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2684_linear__gaussian__climate__data_fun3515__t* _self = kk_function_as(struct kk_climate_dash_change__mlift2684_linear__gaussian__climate__data_fun3515__t*, _fself);
  kk_std_core__list c__row = _self->c__row; /* list<double> */
  kk_integer_t i = _self->i; /* int */
  kk_std_core__list month__ys = _self->month__ys; /* effects-and-types/row_vector */
  kk_std_core__list v__row = _self->v__row; /* effects-and-types/row_vector */
  double score__var = _self->score__var; /* double */
  kk_drop_match(_self, {kk_std_core__list_dup(c__row);kk_integer_dup(i);kk_std_core__list_dup(month__ys);kk_std_core__list_dup(v__row);;}, {}, _ctx)
  kk_unit_t _x3516 = kk_Unit;
  kk_std_core__list _x3517 = kk_std_core__list_unbox(_b_3086, _ctx); /*list<double>*/
  kk_climate_dash_change__mlift2683_linear__gaussian__climate__data(c__row, i, month__ys, score__var, v__row, _x3517, _ctx);
  return kk_unit_box(_x3516);
}

kk_unit_t kk_climate_dash_change__mlift2684_linear__gaussian__climate__data(kk_std_core__list c__row, kk_integer_t i, kk_std_core__list month__ys, double score__var, kk_ref_t x, kk_std_core__list v__row, kk_context_t* _ctx) { /* forall<h> (c_row : list<double>, i : int, month_ys : effects-and-types/row_vector, score_var : double, x : local-var<h,list<double>>, v_row : effects-and-types/row_vector) -> <exn,effects-and-types/sample,local<h>,effects-and-types/score> () */ 
  kk_std_core__list x0_2742;
  kk_box_t _x3513 = (kk_ref_get(x,kk_context())); /*0*/
  x0_2742 = kk_std_core__list_unbox(_x3513, _ctx); /*list<double>*/
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x0_2742, _ctx);
    kk_box_t _x3514 = kk_std_core_hnd_yield_extend(kk_climate_dash_change__new_mlift2684_linear__gaussian__climate__data_fun3515(c__row, i, month__ys, v__row, score__var, _ctx), _ctx); /*2*/
    kk_unit_unbox(_x3514); return kk_Unit;
  }
  kk_climate_dash_change__mlift2683_linear__gaussian__climate__data(c__row, i, month__ys, score__var, v__row, x0_2742, _ctx); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_climate_dash_change__mlift2685_linear__gaussian__climate__data_fun3520__t {
  struct kk_function_s _base;
};
static kk_box_t kk_climate_dash_change__mlift2685_linear__gaussian__climate__data_fun3520(kk_function_t _fself, kk_box_t _b_3096, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change__new_mlift2685_linear__gaussian__climate__data_fun3520(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_climate_dash_change__mlift2685_linear__gaussian__climate__data_fun3520, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_climate_dash_change__mlift2685_linear__gaussian__climate__data_fun3520(kk_function_t _fself, kk_box_t _b_3096, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core__list _x3521;
  kk_std_core__list _x3522 = kk_std_core__list_unbox(_b_3096, _ctx); /*effects-and-types/row_vector*/
  _x3521 = kk_climate_dash_change_convert__uncertainty__to__rand(_x3522, _ctx); /*effects-and-types/row_vector*/
  return kk_std_core__list_box(_x3521, _ctx);
}


// lift anonymous function
struct kk_climate_dash_change__mlift2685_linear__gaussian__climate__data_fun3524__t {
  struct kk_function_s _base;
  kk_std_core__list c__row;
  kk_integer_t i;
  kk_std_core__list month__ys;
  kk_ref_t x;
  double score__var;
};
static kk_box_t kk_climate_dash_change__mlift2685_linear__gaussian__climate__data_fun3524(kk_function_t _fself, kk_box_t _b_3105, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change__new_mlift2685_linear__gaussian__climate__data_fun3524(kk_std_core__list c__row, kk_integer_t i, kk_std_core__list month__ys, kk_ref_t x, double score__var, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2685_linear__gaussian__climate__data_fun3524__t* _self = kk_function_alloc_as(struct kk_climate_dash_change__mlift2685_linear__gaussian__climate__data_fun3524__t, 5, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_change__mlift2685_linear__gaussian__climate__data_fun3524, kk_context());
  _self->c__row = c__row;
  _self->i = i;
  _self->month__ys = month__ys;
  _self->x = x;
  _self->score__var = score__var;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_change__mlift2685_linear__gaussian__climate__data_fun3524(kk_function_t _fself, kk_box_t _b_3105, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2685_linear__gaussian__climate__data_fun3524__t* _self = kk_function_as(struct kk_climate_dash_change__mlift2685_linear__gaussian__climate__data_fun3524__t*, _fself);
  kk_std_core__list c__row = _self->c__row; /* list<double> */
  kk_integer_t i = _self->i; /* int */
  kk_std_core__list month__ys = _self->month__ys; /* effects-and-types/row_vector */
  kk_ref_t x = _self->x; /* local-var<2652,list<double>> */
  double score__var = _self->score__var; /* double */
  kk_drop_match(_self, {kk_std_core__list_dup(c__row);kk_integer_dup(i);kk_std_core__list_dup(month__ys);kk_ref_dup(x);;}, {}, _ctx)
  kk_unit_t _x3525 = kk_Unit;
  kk_std_core__list _x3526 = kk_std_core__list_unbox(_b_3105, _ctx); /*effects-and-types/row_vector*/
  kk_climate_dash_change__mlift2684_linear__gaussian__climate__data(c__row, i, month__ys, score__var, x, _x3526, _ctx);
  return kk_unit_box(_x3525);
}

kk_unit_t kk_climate_dash_change__mlift2685_linear__gaussian__climate__data(kk_integer_t i, kk_std_core__list month__vs, kk_std_core__list month__ys, double score__var, kk_ref_t x, kk_std_core__list c__row, kk_context_t* _ctx) { /* forall<h> (i : int, month_vs : effects-and-types/row_vector, month_ys : effects-and-types/row_vector, score_var : double, x : local-var<h,list<double>>, c_row : list<double>) -> <effects-and-types/sample,exn,local<h>,effects-and-types/score> () */ 
  kk_std_core__list x0_2744;
  kk_vector_t _b_3097_3093;
  kk_std_core__list _x3518;
  size_t _b_3100_3091 = ((size_t)0); /*std/core/hnd/ev-index*/;
  kk_std_core__list _b_3101_3092;
  size_t _b_3102_3089 = ((size_t)1); /*std/core/hnd/ev-index*/;
  _b_3101_3092 = kk_std_core__new_Cons(kk_reuse_null, kk_size_box(_b_3102_3089, _ctx), kk_std_core__new_Nil(_ctx), _ctx); /*list<std/core/hnd/ev-index>*/
  _x3518 = kk_std_core__new_Cons(kk_reuse_null, kk_size_box(_b_3100_3091, _ctx), _b_3101_3092, _ctx); /*list<0>*/
  _b_3097_3093 = kk_std_core_unvlist(_x3518, _ctx); /*vector<std/core/hnd/ev-index>*/
  kk_box_t _x3519 = kk_std_core_hnd__open1(_b_3097_3093, kk_climate_dash_change__new_mlift2685_linear__gaussian__climate__data_fun3520(_ctx), kk_std_core__list_box(month__vs, _ctx), _ctx); /*2*/
  x0_2744 = kk_std_core__list_unbox(_x3519, _ctx); /*effects-and-types/row_vector*/
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x0_2744, _ctx);
    kk_box_t _x3523 = kk_std_core_hnd_yield_extend(kk_climate_dash_change__new_mlift2685_linear__gaussian__climate__data_fun3524(c__row, i, month__ys, x, score__var, _ctx), _ctx); /*2*/
    kk_unit_unbox(_x3523); return kk_Unit;
  }
  kk_climate_dash_change__mlift2684_linear__gaussian__climate__data(c__row, i, month__ys, score__var, x, x0_2744, _ctx); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_climate_dash_change__mlift2686_linear__gaussian__climate__data_fun3528__t {
  struct kk_function_s _base;
  double _x24;
};
static kk_box_t kk_climate_dash_change__mlift2686_linear__gaussian__climate__data_fun3528(kk_function_t _fself, kk_integer_t _b_3112, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change__new_mlift2686_linear__gaussian__climate__data_fun3528(double _x24, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2686_linear__gaussian__climate__data_fun3528__t* _self = kk_function_alloc_as(struct kk_climate_dash_change__mlift2686_linear__gaussian__climate__data_fun3528__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_change__mlift2686_linear__gaussian__climate__data_fun3528, kk_context());
  _self->_x24 = _x24;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_change__mlift2686_linear__gaussian__climate__data_fun3528(kk_function_t _fself, kk_integer_t _b_3112, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2686_linear__gaussian__climate__data_fun3528__t* _self = kk_function_as(struct kk_climate_dash_change__mlift2686_linear__gaussian__climate__data_fun3528__t*, _fself);
  double _x24 = _self->_x24; /* double */
  kk_drop_match(_self, {;}, {}, _ctx)
  kk_integer_drop(_b_3112, _ctx);
  double _x3529 = kk_model_dash_resources_normal(_x24, 0x1.999999999999ap-5, _ctx); /*double*/
  return kk_double_box(_x3529, _ctx);
}


// lift anonymous function
struct kk_climate_dash_change__mlift2686_linear__gaussian__climate__data_fun3531__t {
  struct kk_function_s _base;
  size_t i0_2748;
};
static kk_box_t kk_climate_dash_change__mlift2686_linear__gaussian__climate__data_fun3531(kk_function_t _fself, kk_function_t _b_3123, kk_box_t _b_3124, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change__new_mlift2686_linear__gaussian__climate__data_fun3531(size_t i0_2748, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2686_linear__gaussian__climate__data_fun3531__t* _self = kk_function_alloc_as(struct kk_climate_dash_change__mlift2686_linear__gaussian__climate__data_fun3531__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_change__mlift2686_linear__gaussian__climate__data_fun3531, kk_context());
  _self->i0_2748 = i0_2748;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_change__mlift2686_linear__gaussian__climate__data_fun3531(kk_function_t _fself, kk_function_t _b_3123, kk_box_t _b_3124, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2686_linear__gaussian__climate__data_fun3531__t* _self = kk_function_as(struct kk_climate_dash_change__mlift2686_linear__gaussian__climate__data_fun3531__t*, _fself);
  size_t i0_2748 = _self->i0_2748; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i0_2748, _b_3123, _b_3124, _ctx);
}


// lift anonymous function
struct kk_climate_dash_change__mlift2686_linear__gaussian__climate__data_fun3533__t {
  struct kk_function_s _base;
  kk_integer_t i;
  kk_std_core__list month__vs;
  kk_std_core__list month__ys;
  kk_ref_t x;
  double score__var;
};
static kk_box_t kk_climate_dash_change__mlift2686_linear__gaussian__climate__data_fun3533(kk_function_t _fself, kk_box_t _b_3134, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change__new_mlift2686_linear__gaussian__climate__data_fun3533(kk_integer_t i, kk_std_core__list month__vs, kk_std_core__list month__ys, kk_ref_t x, double score__var, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2686_linear__gaussian__climate__data_fun3533__t* _self = kk_function_alloc_as(struct kk_climate_dash_change__mlift2686_linear__gaussian__climate__data_fun3533__t, 5, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_change__mlift2686_linear__gaussian__climate__data_fun3533, kk_context());
  _self->i = i;
  _self->month__vs = month__vs;
  _self->month__ys = month__ys;
  _self->x = x;
  _self->score__var = score__var;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_change__mlift2686_linear__gaussian__climate__data_fun3533(kk_function_t _fself, kk_box_t _b_3134, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2686_linear__gaussian__climate__data_fun3533__t* _self = kk_function_as(struct kk_climate_dash_change__mlift2686_linear__gaussian__climate__data_fun3533__t*, _fself);
  kk_integer_t i = _self->i; /* int */
  kk_std_core__list month__vs = _self->month__vs; /* effects-and-types/row_vector */
  kk_std_core__list month__ys = _self->month__ys; /* effects-and-types/row_vector */
  kk_ref_t x = _self->x; /* local-var<2652,list<double>> */
  double score__var = _self->score__var; /* double */
  kk_drop_match(_self, {kk_integer_dup(i);kk_std_core__list_dup(month__vs);kk_std_core__list_dup(month__ys);kk_ref_dup(x);;}, {}, _ctx)
  kk_unit_t _x3534 = kk_Unit;
  kk_std_core__list _x3535 = kk_std_core__list_unbox(_b_3134, _ctx); /*list<double>*/
  kk_climate_dash_change__mlift2685_linear__gaussian__climate__data(i, month__vs, month__ys, score__var, x, _x3535, _ctx);
  return kk_unit_box(_x3534);
}

kk_unit_t kk_climate_dash_change__mlift2686_linear__gaussian__climate__data(kk_integer_t i, kk_std_core__list month__ys, double score__var, kk_ref_t x, kk_std_core__list month__vs, kk_context_t* _ctx) { /* forall<h> (i : int, month_ys : effects-and-types/row_vector, score_var : double, x : local-var<h,list<double>>, month_vs : effects-and-types/row_vector) -> <exn,local<h>,effects-and-types/sample,effects-and-types/score> () */ 
  kk_std_core__list x0_2746;
  kk_integer_t _x14;
  kk_std_core__list _x3527 = kk_std_core__list_dup(month__ys); /*effects-and-types/row_vector*/
  _x14 = kk_std_core_length_1(_x3527, _ctx); /*int*/
  double _x24 = (0x1p0 + (0x0p+0)); /*double*/;
  size_t i0_2748 = ((size_t)1); /*std/core/hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i0_2748,kk_context()); /*std/core/hnd/evv<<effects-and-types/sample,exn,local<2652>,effects-and-types/score>>*/;
  kk_std_core__list y = kk_std_core__lift21054_list_1(kk_climate_dash_change__new_mlift2686_linear__gaussian__climate__data_fun3528(_x24, _ctx), kk_integer_from_small(1), _x14, kk_std_core__new_Nil(_ctx), _ctx); /*list<double>*/;
  kk_unit_t __w_l734_c9 = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(y, _ctx);
    kk_box_t _x3530 = kk_std_core_hnd_yield_cont(kk_climate_dash_change__new_mlift2686_linear__gaussian__climate__data_fun3531(i0_2748, _ctx), _ctx); /*3*/
    x0_2746 = kk_std_core__list_unbox(_x3530, _ctx); /*list<double>*/
  }
  else {
    x0_2746 = y; /*list<double>*/
  }
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x0_2746, _ctx);
    kk_box_t _x3532 = kk_std_core_hnd_yield_extend(kk_climate_dash_change__new_mlift2686_linear__gaussian__climate__data_fun3533(i, month__vs, month__ys, x, score__var, _ctx), _ctx); /*2*/
    kk_unit_unbox(_x3532); return kk_Unit;
  }
  kk_climate_dash_change__mlift2685_linear__gaussian__climate__data(i, month__vs, month__ys, score__var, x, x0_2746, _ctx); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_climate_dash_change__mlift2687_linear__gaussian__climate__data_fun3539__t {
  struct kk_function_s _base;
  size_t i0_2755;
};
static kk_box_t kk_climate_dash_change__mlift2687_linear__gaussian__climate__data_fun3539(kk_function_t _fself, kk_function_t _b_3146, kk_box_t _b_3147, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change__new_mlift2687_linear__gaussian__climate__data_fun3539(size_t i0_2755, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2687_linear__gaussian__climate__data_fun3539__t* _self = kk_function_alloc_as(struct kk_climate_dash_change__mlift2687_linear__gaussian__climate__data_fun3539__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_change__mlift2687_linear__gaussian__climate__data_fun3539, kk_context());
  _self->i0_2755 = i0_2755;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_change__mlift2687_linear__gaussian__climate__data_fun3539(kk_function_t _fself, kk_function_t _b_3146, kk_box_t _b_3147, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2687_linear__gaussian__climate__data_fun3539__t* _self = kk_function_as(struct kk_climate_dash_change__mlift2687_linear__gaussian__climate__data_fun3539__t*, _fself);
  size_t i0_2755 = _self->i0_2755; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i0_2755, _b_3146, _b_3147, _ctx);
}


// lift anonymous function
struct kk_climate_dash_change__mlift2687_linear__gaussian__climate__data_fun3541__t {
  struct kk_function_s _base;
  kk_integer_t i;
  kk_std_core__list month__ys;
  kk_ref_t x;
  double score__var;
};
static kk_box_t kk_climate_dash_change__mlift2687_linear__gaussian__climate__data_fun3541(kk_function_t _fself, kk_box_t _b_3157, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change__new_mlift2687_linear__gaussian__climate__data_fun3541(kk_integer_t i, kk_std_core__list month__ys, kk_ref_t x, double score__var, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2687_linear__gaussian__climate__data_fun3541__t* _self = kk_function_alloc_as(struct kk_climate_dash_change__mlift2687_linear__gaussian__climate__data_fun3541__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_change__mlift2687_linear__gaussian__climate__data_fun3541, kk_context());
  _self->i = i;
  _self->month__ys = month__ys;
  _self->x = x;
  _self->score__var = score__var;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_change__mlift2687_linear__gaussian__climate__data_fun3541(kk_function_t _fself, kk_box_t _b_3157, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2687_linear__gaussian__climate__data_fun3541__t* _self = kk_function_as(struct kk_climate_dash_change__mlift2687_linear__gaussian__climate__data_fun3541__t*, _fself);
  kk_integer_t i = _self->i; /* int */
  kk_std_core__list month__ys = _self->month__ys; /* effects-and-types/row_vector */
  kk_ref_t x = _self->x; /* local-var<2652,list<double>> */
  double score__var = _self->score__var; /* double */
  kk_drop_match(_self, {kk_integer_dup(i);kk_std_core__list_dup(month__ys);kk_ref_dup(x);;}, {}, _ctx)
  kk_unit_t _x3542 = kk_Unit;
  kk_std_core__list _x3543 = kk_std_core__list_unbox(_b_3157, _ctx); /*effects-and-types/row_vector*/
  kk_climate_dash_change__mlift2686_linear__gaussian__climate__data(i, month__ys, score__var, x, _x3543, _ctx);
  return kk_unit_box(_x3542);
}

kk_unit_t kk_climate_dash_change__mlift2687_linear__gaussian__climate__data(kk_integer_t i, double score__var, kk_std_core__list vs, kk_ref_t x, kk_std_core__list month__ys, kk_context_t* _ctx) { /* forall<h> (i : int, score_var : double, vs : list<effects-and-types/row_vector>, x : local-var<h,list<double>>, month_ys : effects-and-types/row_vector) -> <exn,local<h>,effects-and-types/sample,effects-and-types/score> () */ 
  kk_std_core__list x0_2753;
  size_t i0_2755 = ((size_t)0); /*std/core/hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i0_2755,kk_context()); /*std/core/hnd/evv<<exn,local<2652>,effects-and-types/sample,effects-and-types/score>>*/;
  kk_std_core__list y;
  kk_box_t _x3536;
  kk_integer_t _x3537 = kk_integer_dup(i); /*int*/
  _x3536 = kk_exn_dash_get_exn_get(vs, _x3537, _ctx); /*0*/
  y = kk_std_core__list_unbox(_x3536, _ctx); /*effects-and-types/row_vector*/
  kk_unit_t __w_l717_c9 = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(y, _ctx);
    kk_box_t _x3538 = kk_std_core_hnd_yield_cont(kk_climate_dash_change__new_mlift2687_linear__gaussian__climate__data_fun3539(i0_2755, _ctx), _ctx); /*3*/
    x0_2753 = kk_std_core__list_unbox(_x3538, _ctx); /*effects-and-types/row_vector*/
  }
  else {
    x0_2753 = y; /*effects-and-types/row_vector*/
  }
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x0_2753, _ctx);
    kk_box_t _x3540 = kk_std_core_hnd_yield_extend(kk_climate_dash_change__new_mlift2687_linear__gaussian__climate__data_fun3541(i, month__ys, x, score__var, _ctx), _ctx); /*2*/
    kk_unit_unbox(_x3540); return kk_Unit;
  }
  kk_climate_dash_change__mlift2686_linear__gaussian__climate__data(i, month__ys, score__var, x, x0_2753, _ctx); return kk_Unit;
}
 
// monadic lift

kk_unit_t kk_climate_dash_change__mlift2688_linear__gaussian__climate__data(kk_std_core__list _y_12, double diff, double subtract, kk_ref_t x, double _y_13, kk_context_t* _ctx) { /* forall<h> (list<double>, diff : double, subtract : double, x : local-var<h,list<double>>, double) -> <effects-and-types/sample,local<h>,exn,effects-and-types/score> () */ 
  kk_std_core__list _b_3167_3165;
  kk_std_core__list ys_2760;
  double _b_3162_3160;
  double _x3544 = (_y_13 * diff); /*double*/
  _b_3162_3160 = (_x3544 + subtract); /*double*/
  ys_2760 = kk_std_core__new_Cons(kk_reuse_null, kk_double_box(_b_3162_3160, _ctx), kk_std_core__new_Nil(_ctx), _ctx); /*list<double>*/
  _b_3167_3165 = kk_std_core_append(_y_12, ys_2760, _ctx); /*list<double>*/
  (kk_ref_set(x,(kk_std_core__list_box(_b_3167_3165, _ctx)),kk_context())); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_climate_dash_change__mlift2689_linear__gaussian__climate__data_fun3551__t {
  struct kk_function_s _base;
  size_t i_2763;
};
static kk_box_t kk_climate_dash_change__mlift2689_linear__gaussian__climate__data_fun3551(kk_function_t _fself, kk_function_t _b_3181, kk_box_t _b_3182, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change__new_mlift2689_linear__gaussian__climate__data_fun3551(size_t i_2763, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2689_linear__gaussian__climate__data_fun3551__t* _self = kk_function_alloc_as(struct kk_climate_dash_change__mlift2689_linear__gaussian__climate__data_fun3551__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_change__mlift2689_linear__gaussian__climate__data_fun3551, kk_context());
  _self->i_2763 = i_2763;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_change__mlift2689_linear__gaussian__climate__data_fun3551(kk_function_t _fself, kk_function_t _b_3181, kk_box_t _b_3182, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2689_linear__gaussian__climate__data_fun3551__t* _self = kk_function_as(struct kk_climate_dash_change__mlift2689_linear__gaussian__climate__data_fun3551__t*, _fself);
  size_t i_2763 = _self->i_2763; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_2763, _b_3181, _b_3182, _ctx);
}


// lift anonymous function
struct kk_climate_dash_change__mlift2689_linear__gaussian__climate__data_fun3553__t {
  struct kk_function_s _base;
  kk_std_core__list _y_12;
  kk_ref_t x;
  double diff;
  double subtract;
};
static kk_box_t kk_climate_dash_change__mlift2689_linear__gaussian__climate__data_fun3553(kk_function_t _fself, kk_box_t _b_3192, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change__new_mlift2689_linear__gaussian__climate__data_fun3553(kk_std_core__list _y_12, kk_ref_t x, double diff, double subtract, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2689_linear__gaussian__climate__data_fun3553__t* _self = kk_function_alloc_as(struct kk_climate_dash_change__mlift2689_linear__gaussian__climate__data_fun3553__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_change__mlift2689_linear__gaussian__climate__data_fun3553, kk_context());
  _self->_y_12 = _y_12;
  _self->x = x;
  _self->diff = diff;
  _self->subtract = subtract;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_change__mlift2689_linear__gaussian__climate__data_fun3553(kk_function_t _fself, kk_box_t _b_3192, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2689_linear__gaussian__climate__data_fun3553__t* _self = kk_function_as(struct kk_climate_dash_change__mlift2689_linear__gaussian__climate__data_fun3553__t*, _fself);
  kk_std_core__list _y_12 = _self->_y_12; /* list<double> */
  kk_ref_t x = _self->x; /* local-var<2652,list<double>> */
  double diff = _self->diff; /* double */
  double subtract = _self->subtract; /* double */
  kk_drop_match(_self, {kk_std_core__list_dup(_y_12);kk_ref_dup(x);;;}, {}, _ctx)
  kk_unit_t _x3554 = kk_Unit;
  double _x3555 = kk_double_unbox(_b_3192, _ctx); /*double*/
  kk_climate_dash_change__mlift2688_linear__gaussian__climate__data(_y_12, diff, subtract, x, _x3555, _ctx);
  return kk_unit_box(_x3554);
}

kk_unit_t kk_climate_dash_change__mlift2689_linear__gaussian__climate__data(double diff, double subtract, kk_ref_t x, kk_std_core__list _y_12, kk_context_t* _ctx) { /* forall<h> (diff : double, subtract : double, x : local-var<h,list<double>>, list<double>) -> <local<h>,effects-and-types/sample,exn,effects-and-types/score> () */ 
  double x0_2761;
  size_t i_2763 = ((size_t)1); /*std/core/hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_2763,kk_context()); /*std/core/hnd/evv<<effects-and-types/sample,local<2652>,exn,effects-and-types/score>>*/;
  double y;
  kk_std_core_hnd__ev ev_404;
  size_t _x3545 = ((size_t)0); /*size_t*/
  ev_404 = kk_evv_at(_x3545,kk_context()); /*std/core/hnd/ev<effects-and-types/.hnd-sample>*/
  kk_box_t _x3546;
  struct kk_std_core_hnd_Ev* _con3547 = kk_std_core_hnd__as_Ev(ev_404);
  kk_std_core_hnd__marker m = _con3547->marker;
  kk_box_t _box_x3168 = _con3547->hnd;
  kk_effects_dash_and_dash_types__hnd_sample h = kk_effects_dash_and_dash_types__hnd_sample_unbox(_box_x3168, NULL);
  kk_effects_dash_and_dash_types__hnd_sample_dup(h);
  kk_std_core_hnd__clause0 _match_3368;
  struct kk_effects_dash_and_dash_types__Hnd_sample* _con3549 = kk_effects_dash_and_dash_types__as_Hnd_sample(h);
  kk_std_core_hnd__clause0 fun_sample = _con3549->fun_sample;
  if (kk_effects_dash_and_dash_types__hnd_sample_is_unique(h)) {
    kk_effects_dash_and_dash_types__hnd_sample_free(h);
  }
  else {
    kk_std_core_hnd__clause0_dup(fun_sample);
    kk_effects_dash_and_dash_types__hnd_sample_decref(h, _ctx);
  }
  _match_3368 = fun_sample; /*std/core/hnd/clause0<double,effects-and-types/.hnd-sample,1,2>*/
  kk_function_t _fun_unbox_x3171 = _match_3368.clause;
  _x3546 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x3171, (_fun_unbox_x3171, m, ev_404, _ctx)); /*6*/
  y = kk_double_unbox(_x3546, _ctx); /*double*/
  kk_unit_t __w_l683_c9 = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x3550 = kk_std_core_hnd_yield_cont(kk_climate_dash_change__new_mlift2689_linear__gaussian__climate__data_fun3551(i_2763, _ctx), _ctx); /*3*/
    x0_2761 = kk_double_unbox(_x3550, _ctx); /*double*/
  }
  else {
    x0_2761 = y; /*double*/
  }
  if (kk_yielding(kk_context())) {
    kk_box_t _x3552 = kk_std_core_hnd_yield_extend(kk_climate_dash_change__new_mlift2689_linear__gaussian__climate__data_fun3553(_y_12, x, diff, subtract, _ctx), _ctx); /*2*/
    kk_unit_unbox(_x3552); return kk_Unit;
  }
  kk_climate_dash_change__mlift2688_linear__gaussian__climate__data(_y_12, diff, subtract, x, x0_2761, _ctx); return kk_Unit;
}
 
// monadic lift

kk_unit_t kk_climate_dash_change__mlift2690_linear__gaussian__climate__data(kk_std_core__list _y_17, double a__val, double w__val, kk_ref_t x, double _y_19, kk_context_t* _ctx) { /* forall<h> (list<double>, a_val : double, w_val : double, x : local-var<h,list<double>>, double) -> <exn,local<h>,effects-and-types/sample,effects-and-types/score> () */ 
  kk_std_core__list _b_3202_3200;
  kk_std_core__list ys_2766;
  double _b_3197_3195;
  double _x3556 = (_y_19 * a__val); /*double*/
  _b_3197_3195 = (_x3556 + w__val); /*double*/
  ys_2766 = kk_std_core__new_Cons(kk_reuse_null, kk_double_box(_b_3197_3195, _ctx), kk_std_core__new_Nil(_ctx), _ctx); /*list<double>*/
  _b_3202_3200 = kk_std_core_append(_y_17, ys_2766, _ctx); /*list<double>*/
  (kk_ref_set(x,(kk_std_core__list_box(_b_3202_3200, _ctx)),kk_context())); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_climate_dash_change__mlift2691_linear__gaussian__climate__data_fun3559__t {
  struct kk_function_s _base;
  size_t i0_2769;
};
static kk_box_t kk_climate_dash_change__mlift2691_linear__gaussian__climate__data_fun3559(kk_function_t _fself, kk_function_t _b_3212, kk_box_t _b_3213, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change__new_mlift2691_linear__gaussian__climate__data_fun3559(size_t i0_2769, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2691_linear__gaussian__climate__data_fun3559__t* _self = kk_function_alloc_as(struct kk_climate_dash_change__mlift2691_linear__gaussian__climate__data_fun3559__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_change__mlift2691_linear__gaussian__climate__data_fun3559, kk_context());
  _self->i0_2769 = i0_2769;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_change__mlift2691_linear__gaussian__climate__data_fun3559(kk_function_t _fself, kk_function_t _b_3212, kk_box_t _b_3213, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2691_linear__gaussian__climate__data_fun3559__t* _self = kk_function_as(struct kk_climate_dash_change__mlift2691_linear__gaussian__climate__data_fun3559__t*, _fself);
  size_t i0_2769 = _self->i0_2769; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i0_2769, _b_3212, _b_3213, _ctx);
}


// lift anonymous function
struct kk_climate_dash_change__mlift2691_linear__gaussian__climate__data_fun3561__t {
  struct kk_function_s _base;
  kk_std_core__list _y_17;
  kk_ref_t x;
  double a__val;
  double w__val;
};
static kk_box_t kk_climate_dash_change__mlift2691_linear__gaussian__climate__data_fun3561(kk_function_t _fself, kk_box_t _b_3223, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change__new_mlift2691_linear__gaussian__climate__data_fun3561(kk_std_core__list _y_17, kk_ref_t x, double a__val, double w__val, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2691_linear__gaussian__climate__data_fun3561__t* _self = kk_function_alloc_as(struct kk_climate_dash_change__mlift2691_linear__gaussian__climate__data_fun3561__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_change__mlift2691_linear__gaussian__climate__data_fun3561, kk_context());
  _self->_y_17 = _y_17;
  _self->x = x;
  _self->a__val = a__val;
  _self->w__val = w__val;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_change__mlift2691_linear__gaussian__climate__data_fun3561(kk_function_t _fself, kk_box_t _b_3223, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2691_linear__gaussian__climate__data_fun3561__t* _self = kk_function_as(struct kk_climate_dash_change__mlift2691_linear__gaussian__climate__data_fun3561__t*, _fself);
  kk_std_core__list _y_17 = _self->_y_17; /* list<double> */
  kk_ref_t x = _self->x; /* local-var<2652,list<double>> */
  double a__val = _self->a__val; /* double */
  double w__val = _self->w__val; /* double */
  kk_drop_match(_self, {kk_std_core__list_dup(_y_17);kk_ref_dup(x);;;}, {}, _ctx)
  kk_unit_t _x3562 = kk_Unit;
  double _x3563 = kk_double_unbox(_b_3223, _ctx); /*double*/
  kk_climate_dash_change__mlift2690_linear__gaussian__climate__data(_y_17, a__val, w__val, x, _x3563, _ctx);
  return kk_unit_box(_x3562);
}

kk_unit_t kk_climate_dash_change__mlift2691_linear__gaussian__climate__data(kk_std_core__list _y_17, double a__val, kk_integer_t i, double w__val, kk_ref_t x, kk_std_core__list _y_18, kk_context_t* _ctx) { /* forall<h> (list<double>, a_val : double, i : int, w_val : double, x : local-var<h,list<double>>, list<double>) -> <local<h>,exn,effects-and-types/sample,effects-and-types/score> () */ 
  double x0_2767;
  kk_integer_t _x21 = kk_integer_sub(i,(kk_integer_from_small(1)),kk_context()); /*int*/;
  size_t i0_2769 = ((size_t)0); /*std/core/hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i0_2769,kk_context()); /*std/core/hnd/evv<<exn,local<2652>,effects-and-types/sample,effects-and-types/score>>*/;
  double y;
  kk_box_t _x3557 = kk_exn_dash_get_exn_get(_y_18, _x21, _ctx); /*0*/
  y = kk_double_unbox(_x3557, _ctx); /*double*/
  kk_unit_t __w_l717_c9 = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x3558 = kk_std_core_hnd_yield_cont(kk_climate_dash_change__new_mlift2691_linear__gaussian__climate__data_fun3559(i0_2769, _ctx), _ctx); /*3*/
    x0_2767 = kk_double_unbox(_x3558, _ctx); /*double*/
  }
  else {
    x0_2767 = y; /*double*/
  }
  if (kk_yielding(kk_context())) {
    kk_box_t _x3560 = kk_std_core_hnd_yield_extend(kk_climate_dash_change__new_mlift2691_linear__gaussian__climate__data_fun3561(_y_17, x, a__val, w__val, _ctx), _ctx); /*2*/
    kk_unit_unbox(_x3560); return kk_Unit;
  }
  kk_climate_dash_change__mlift2690_linear__gaussian__climate__data(_y_17, a__val, w__val, x, x0_2767, _ctx); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_climate_dash_change__mlift2692_linear__gaussian__climate__data_fun3567__t {
  struct kk_function_s _base;
  kk_std_core__list _y_17;
  kk_integer_t i;
  kk_ref_t x;
  double a__val;
  double w__val;
};
static kk_box_t kk_climate_dash_change__mlift2692_linear__gaussian__climate__data_fun3567(kk_function_t _fself, kk_box_t _b_3229, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change__new_mlift2692_linear__gaussian__climate__data_fun3567(kk_std_core__list _y_17, kk_integer_t i, kk_ref_t x, double a__val, double w__val, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2692_linear__gaussian__climate__data_fun3567__t* _self = kk_function_alloc_as(struct kk_climate_dash_change__mlift2692_linear__gaussian__climate__data_fun3567__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_change__mlift2692_linear__gaussian__climate__data_fun3567, kk_context());
  _self->_y_17 = _y_17;
  _self->i = i;
  _self->x = x;
  _self->a__val = a__val;
  _self->w__val = w__val;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_change__mlift2692_linear__gaussian__climate__data_fun3567(kk_function_t _fself, kk_box_t _b_3229, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2692_linear__gaussian__climate__data_fun3567__t* _self = kk_function_as(struct kk_climate_dash_change__mlift2692_linear__gaussian__climate__data_fun3567__t*, _fself);
  kk_std_core__list _y_17 = _self->_y_17; /* list<double> */
  kk_integer_t i = _self->i; /* int */
  kk_ref_t x = _self->x; /* local-var<2652,list<double>> */
  double a__val = _self->a__val; /* double */
  double w__val = _self->w__val; /* double */
  kk_drop_match(_self, {kk_std_core__list_dup(_y_17);kk_integer_dup(i);kk_ref_dup(x);;;}, {}, _ctx)
  kk_unit_t _x3568 = kk_Unit;
  kk_std_core__list _x3569 = kk_std_core__list_unbox(_b_3229, _ctx); /*list<double>*/
  kk_climate_dash_change__mlift2691_linear__gaussian__climate__data(_y_17, a__val, i, w__val, x, _x3569, _ctx);
  return kk_unit_box(_x3568);
}

kk_unit_t kk_climate_dash_change__mlift2692_linear__gaussian__climate__data(double a__val, kk_integer_t i, double w__val, kk_ref_t x, kk_std_core__list _y_17, kk_context_t* _ctx) { /* forall<h> (a_val : double, i : int, w_val : double, x : local-var<h,list<double>>, list<double>) -> <local<h>,exn,effects-and-types/sample,effects-and-types/score> () */ 
  kk_std_core__list x0_2773;
  kk_box_t _x3564;
  kk_ref_t _x3565 = kk_ref_dup(x); /*local-var<2652,list<double>>*/
  _x3564 = (kk_ref_get(_x3565,kk_context())); /*0*/
  x0_2773 = kk_std_core__list_unbox(_x3564, _ctx); /*list<double>*/
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x0_2773, _ctx);
    kk_box_t _x3566 = kk_std_core_hnd_yield_extend(kk_climate_dash_change__new_mlift2692_linear__gaussian__climate__data_fun3567(_y_17, i, x, a__val, w__val, _ctx), _ctx); /*2*/
    kk_unit_unbox(_x3566); return kk_Unit;
  }
  kk_climate_dash_change__mlift2691_linear__gaussian__climate__data(_y_17, a__val, i, w__val, x, x0_2773, _ctx); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_climate_dash_change__mlift2693_linear__gaussian__climate__data_fun3573__t {
  struct kk_function_s _base;
  kk_integer_t i;
  kk_ref_t x;
  double a__val;
  double w__val;
};
static kk_box_t kk_climate_dash_change__mlift2693_linear__gaussian__climate__data_fun3573(kk_function_t _fself, kk_box_t _b_3235, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change__new_mlift2693_linear__gaussian__climate__data_fun3573(kk_integer_t i, kk_ref_t x, double a__val, double w__val, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2693_linear__gaussian__climate__data_fun3573__t* _self = kk_function_alloc_as(struct kk_climate_dash_change__mlift2693_linear__gaussian__climate__data_fun3573__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_change__mlift2693_linear__gaussian__climate__data_fun3573, kk_context());
  _self->i = i;
  _self->x = x;
  _self->a__val = a__val;
  _self->w__val = w__val;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_change__mlift2693_linear__gaussian__climate__data_fun3573(kk_function_t _fself, kk_box_t _b_3235, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2693_linear__gaussian__climate__data_fun3573__t* _self = kk_function_as(struct kk_climate_dash_change__mlift2693_linear__gaussian__climate__data_fun3573__t*, _fself);
  kk_integer_t i = _self->i; /* int */
  kk_ref_t x = _self->x; /* local-var<2652,list<double>> */
  double a__val = _self->a__val; /* double */
  double w__val = _self->w__val; /* double */
  kk_drop_match(_self, {kk_integer_dup(i);kk_ref_dup(x);;;}, {}, _ctx)
  kk_unit_t _x3574 = kk_Unit;
  kk_std_core__list _x3575 = kk_std_core__list_unbox(_b_3235, _ctx); /*list<double>*/
  kk_climate_dash_change__mlift2692_linear__gaussian__climate__data(a__val, i, w__val, x, _x3575, _ctx);
  return kk_unit_box(_x3574);
}

kk_unit_t kk_climate_dash_change__mlift2693_linear__gaussian__climate__data(double a__val, kk_integer_t i, kk_ref_t x, double w__val, kk_context_t* _ctx) { /* forall<h> (a_val : double, i : int, x : local-var<h,list<double>>, w_val : double) -> <effects-and-types/sample,exn,local<h>,effects-and-types/score> () */ 
  kk_std_core__list x0_2775;
  kk_box_t _x3570;
  kk_ref_t _x3571 = kk_ref_dup(x); /*local-var<2652,list<double>>*/
  _x3570 = (kk_ref_get(_x3571,kk_context())); /*0*/
  x0_2775 = kk_std_core__list_unbox(_x3570, _ctx); /*list<double>*/
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x0_2775, _ctx);
    kk_box_t _x3572 = kk_std_core_hnd_yield_extend(kk_climate_dash_change__new_mlift2693_linear__gaussian__climate__data_fun3573(i, x, a__val, w__val, _ctx), _ctx); /*2*/
    kk_unit_unbox(_x3572); return kk_Unit;
  }
  kk_climate_dash_change__mlift2692_linear__gaussian__climate__data(a__val, i, w__val, x, x0_2775, _ctx); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_climate_dash_change__mlift2694_linear__gaussian__climate__data_fun3577__t {
  struct kk_function_s _base;
};
static kk_box_t kk_climate_dash_change__mlift2694_linear__gaussian__climate__data_fun3577(kk_function_t _fself, kk_box_t _b_3239, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change__new_mlift2694_linear__gaussian__climate__data_fun3577(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_climate_dash_change__mlift2694_linear__gaussian__climate__data_fun3577, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_climate_dash_change__mlift2694_linear__gaussian__climate__data_fun3577(kk_function_t _fself, kk_box_t _b_3239, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x3578;
  double _x3579 = kk_double_unbox(_b_3239, _ctx); /*double*/
  _x3578 = kk_model_dash_resources__mlift3175_normal(0x0p+0, 0x1p0, _x3579, _ctx); /*double*/
  return kk_double_box(_x3578, _ctx);
}


// lift anonymous function
struct kk_climate_dash_change__mlift2694_linear__gaussian__climate__data_fun3582__t {
  struct kk_function_s _base;
  size_t i0_2779;
};
static kk_box_t kk_climate_dash_change__mlift2694_linear__gaussian__climate__data_fun3582(kk_function_t _fself, kk_function_t _b_3247, kk_box_t _b_3248, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change__new_mlift2694_linear__gaussian__climate__data_fun3582(size_t i0_2779, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2694_linear__gaussian__climate__data_fun3582__t* _self = kk_function_alloc_as(struct kk_climate_dash_change__mlift2694_linear__gaussian__climate__data_fun3582__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_change__mlift2694_linear__gaussian__climate__data_fun3582, kk_context());
  _self->i0_2779 = i0_2779;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_change__mlift2694_linear__gaussian__climate__data_fun3582(kk_function_t _fself, kk_function_t _b_3247, kk_box_t _b_3248, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2694_linear__gaussian__climate__data_fun3582__t* _self = kk_function_as(struct kk_climate_dash_change__mlift2694_linear__gaussian__climate__data_fun3582__t*, _fself);
  size_t i0_2779 = _self->i0_2779; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i0_2779, _b_3247, _b_3248, _ctx);
}


// lift anonymous function
struct kk_climate_dash_change__mlift2694_linear__gaussian__climate__data_fun3584__t {
  struct kk_function_s _base;
  kk_integer_t i;
  kk_ref_t x;
  double a__val;
};
static kk_box_t kk_climate_dash_change__mlift2694_linear__gaussian__climate__data_fun3584(kk_function_t _fself, kk_box_t _b_3258, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change__new_mlift2694_linear__gaussian__climate__data_fun3584(kk_integer_t i, kk_ref_t x, double a__val, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2694_linear__gaussian__climate__data_fun3584__t* _self = kk_function_alloc_as(struct kk_climate_dash_change__mlift2694_linear__gaussian__climate__data_fun3584__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_change__mlift2694_linear__gaussian__climate__data_fun3584, kk_context());
  _self->i = i;
  _self->x = x;
  _self->a__val = a__val;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_change__mlift2694_linear__gaussian__climate__data_fun3584(kk_function_t _fself, kk_box_t _b_3258, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2694_linear__gaussian__climate__data_fun3584__t* _self = kk_function_as(struct kk_climate_dash_change__mlift2694_linear__gaussian__climate__data_fun3584__t*, _fself);
  kk_integer_t i = _self->i; /* int */
  kk_ref_t x = _self->x; /* local-var<2652,list<double>> */
  double a__val = _self->a__val; /* double */
  kk_drop_match(_self, {kk_integer_dup(i);kk_ref_dup(x);;}, {}, _ctx)
  kk_unit_t _x3585 = kk_Unit;
  double _x3586 = kk_double_unbox(_b_3258, _ctx); /*double*/
  kk_climate_dash_change__mlift2693_linear__gaussian__climate__data(a__val, i, x, _x3586, _ctx);
  return kk_unit_box(_x3585);
}

kk_unit_t kk_climate_dash_change__mlift2694_linear__gaussian__climate__data(kk_integer_t i, kk_ref_t x, double a__val, kk_context_t* _ctx) { /* forall<h> (i : int, x : local-var<h,list<double>>, a_val : double) -> <effects-and-types/sample,exn,local<h>,effects-and-types/score> () */ 
  double x0_2777;
  size_t i0_2779 = ((size_t)1); /*std/core/hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i0_2779,kk_context()); /*std/core/hnd/evv<<effects-and-types/sample,exn,local<2652>,effects-and-types/score>>*/;
  double y;
  double x_3267 = kk_model_dash_resources_standard_normal(_ctx); /*double*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x3576 = kk_std_core_hnd_yield_extend(kk_climate_dash_change__new_mlift2694_linear__gaussian__climate__data_fun3577(_ctx), _ctx); /*2*/
    y = kk_double_unbox(_x3576, _ctx); /*double*/
  }
  else {
    double _x3580 = (x_3267 * 0x1p0); /*double*/
    y = ((0x0p+0) + _x3580); /*double*/
  }
  kk_unit_t __w_l717_c9 = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x3581 = kk_std_core_hnd_yield_cont(kk_climate_dash_change__new_mlift2694_linear__gaussian__climate__data_fun3582(i0_2779, _ctx), _ctx); /*3*/
    x0_2777 = kk_double_unbox(_x3581, _ctx); /*double*/
  }
  else {
    x0_2777 = y; /*double*/
  }
  if (kk_yielding(kk_context())) {
    kk_box_t _x3583 = kk_std_core_hnd_yield_extend(kk_climate_dash_change__new_mlift2694_linear__gaussian__climate__data_fun3584(i, x, a__val, _ctx), _ctx); /*2*/
    kk_unit_unbox(_x3583); return kk_Unit;
  }
  kk_climate_dash_change__mlift2693_linear__gaussian__climate__data(a__val, i, x, x0_2777, _ctx); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_climate_dash_change__mlift2695_linear__gaussian__climate__data_fun3590__t {
  struct kk_function_s _base;
  size_t i0_2785;
};
static kk_box_t kk_climate_dash_change__mlift2695_linear__gaussian__climate__data_fun3590(kk_function_t _fself, kk_function_t _b_3270, kk_box_t _b_3271, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change__new_mlift2695_linear__gaussian__climate__data_fun3590(size_t i0_2785, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2695_linear__gaussian__climate__data_fun3590__t* _self = kk_function_alloc_as(struct kk_climate_dash_change__mlift2695_linear__gaussian__climate__data_fun3590__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_change__mlift2695_linear__gaussian__climate__data_fun3590, kk_context());
  _self->i0_2785 = i0_2785;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_change__mlift2695_linear__gaussian__climate__data_fun3590(kk_function_t _fself, kk_function_t _b_3270, kk_box_t _b_3271, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2695_linear__gaussian__climate__data_fun3590__t* _self = kk_function_as(struct kk_climate_dash_change__mlift2695_linear__gaussian__climate__data_fun3590__t*, _fself);
  size_t i0_2785 = _self->i0_2785; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i0_2785, _b_3270, _b_3271, _ctx);
}


// lift anonymous function
struct kk_climate_dash_change__mlift2695_linear__gaussian__climate__data_fun3592__t {
  struct kk_function_s _base;
  kk_integer_t i;
  kk_std_core__list vs;
  kk_ref_t x;
  double score__var;
};
static kk_box_t kk_climate_dash_change__mlift2695_linear__gaussian__climate__data_fun3592(kk_function_t _fself, kk_box_t _b_3281, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change__new_mlift2695_linear__gaussian__climate__data_fun3592(kk_integer_t i, kk_std_core__list vs, kk_ref_t x, double score__var, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2695_linear__gaussian__climate__data_fun3592__t* _self = kk_function_alloc_as(struct kk_climate_dash_change__mlift2695_linear__gaussian__climate__data_fun3592__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_change__mlift2695_linear__gaussian__climate__data_fun3592, kk_context());
  _self->i = i;
  _self->vs = vs;
  _self->x = x;
  _self->score__var = score__var;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_change__mlift2695_linear__gaussian__climate__data_fun3592(kk_function_t _fself, kk_box_t _b_3281, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2695_linear__gaussian__climate__data_fun3592__t* _self = kk_function_as(struct kk_climate_dash_change__mlift2695_linear__gaussian__climate__data_fun3592__t*, _fself);
  kk_integer_t i = _self->i; /* int */
  kk_std_core__list vs = _self->vs; /* list<effects-and-types/row_vector> */
  kk_ref_t x = _self->x; /* local-var<2652,list<double>> */
  double score__var = _self->score__var; /* double */
  kk_drop_match(_self, {kk_integer_dup(i);kk_std_core__list_dup(vs);kk_ref_dup(x);;}, {}, _ctx)
  kk_unit_t _x3593 = kk_Unit;
  kk_std_core__list _x3594 = kk_std_core__list_unbox(_b_3281, _ctx); /*effects-and-types/row_vector*/
  kk_climate_dash_change__mlift2687_linear__gaussian__climate__data(i, score__var, vs, x, _x3594, _ctx);
  return kk_unit_box(_x3593);
}

kk_unit_t kk_climate_dash_change__mlift2695_linear__gaussian__climate__data(kk_integer_t i, double score__var, kk_std_core__list vs, kk_ref_t x, kk_std_core__list ys, kk_unit_t _c_21, kk_context_t* _ctx) { /* forall<h> (i : int, score_var : double, vs : list<effects-and-types/row_vector>, x : local-var<h,list<double>>, ys : list<effects-and-types/row_vector>, ()) -> () */ 
  kk_std_core__list x0_2783;
  size_t i0_2785 = ((size_t)0); /*std/core/hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i0_2785,kk_context()); /*std/core/hnd/evv<<exn,local<2652>,effects-and-types/sample,effects-and-types/score>>*/;
  kk_std_core__list y;
  kk_box_t _x3587;
  kk_integer_t _x3588 = kk_integer_dup(i); /*int*/
  _x3587 = kk_exn_dash_get_exn_get(ys, _x3588, _ctx); /*0*/
  y = kk_std_core__list_unbox(_x3587, _ctx); /*effects-and-types/row_vector*/
  kk_unit_t __w_l717_c9 = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(y, _ctx);
    kk_box_t _x3589 = kk_std_core_hnd_yield_cont(kk_climate_dash_change__new_mlift2695_linear__gaussian__climate__data_fun3590(i0_2785, _ctx), _ctx); /*3*/
    x0_2783 = kk_std_core__list_unbox(_x3589, _ctx); /*effects-and-types/row_vector*/
  }
  else {
    x0_2783 = y; /*effects-and-types/row_vector*/
  }
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x0_2783, _ctx);
    kk_box_t _x3591 = kk_std_core_hnd_yield_extend(kk_climate_dash_change__new_mlift2695_linear__gaussian__climate__data_fun3592(i, vs, x, score__var, _ctx), _ctx); /*2*/
    kk_unit_unbox(_x3591); return kk_Unit;
  }
  kk_climate_dash_change__mlift2687_linear__gaussian__climate__data(i, score__var, vs, x, x0_2783, _ctx); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_climate_dash_change__mlift2696_linear__gaussian__climate__data_fun3595__t {
  struct kk_function_s _base;
  kk_ref_t x;
};
static kk_box_t kk_climate_dash_change__mlift2696_linear__gaussian__climate__data_fun3595(kk_function_t _fself, kk_integer_t _b_3292, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change__new_mlift2696_linear__gaussian__climate__data_fun3595(kk_ref_t x, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2696_linear__gaussian__climate__data_fun3595__t* _self = kk_function_alloc_as(struct kk_climate_dash_change__mlift2696_linear__gaussian__climate__data_fun3595__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_change__mlift2696_linear__gaussian__climate__data_fun3595, kk_context());
  _self->x = x;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_change__mlift2696_linear__gaussian__climate__data_fun3599__t {
  struct kk_function_s _base;
  kk_integer_t _b_3292;
};
static kk_box_t kk_climate_dash_change__mlift2696_linear__gaussian__climate__data_fun3599(kk_function_t _fself, kk_box_t _b_3287, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change__new_mlift2696_linear__gaussian__climate__data_fun3599(kk_integer_t _b_3292, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2696_linear__gaussian__climate__data_fun3599__t* _self = kk_function_alloc_as(struct kk_climate_dash_change__mlift2696_linear__gaussian__climate__data_fun3599__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_change__mlift2696_linear__gaussian__climate__data_fun3599, kk_context());
  _self->_b_3292 = _b_3292;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_change__mlift2696_linear__gaussian__climate__data_fun3599(kk_function_t _fself, kk_box_t _b_3287, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2696_linear__gaussian__climate__data_fun3599__t* _self = kk_function_as(struct kk_climate_dash_change__mlift2696_linear__gaussian__climate__data_fun3599__t*, _fself);
  kk_integer_t _b_3292 = _self->_b_3292; /* int */
  kk_drop_match(_self, {kk_integer_dup(_b_3292);}, {}, _ctx)
  double _x3600;
  kk_std_core__list _x3601 = kk_std_core__list_unbox(_b_3287, _ctx); /*list<double>*/
  _x3600 = kk_climate_dash_change__mlift2679_linear__gaussian__climate__data(_b_3292, _x3601, _ctx); /*double*/
  return kk_double_box(_x3600, _ctx);
}
static kk_box_t kk_climate_dash_change__mlift2696_linear__gaussian__climate__data_fun3595(kk_function_t _fself, kk_integer_t _b_3292, kk_context_t* _ctx) {
  struct kk_climate_dash_change__mlift2696_linear__gaussian__climate__data_fun3595__t* _self = kk_function_as(struct kk_climate_dash_change__mlift2696_linear__gaussian__climate__data_fun3595__t*, _fself);
  kk_ref_t x = _self->x; /* local-var<2652,list<double>> */
  kk_drop_match(_self, {kk_ref_dup(x);}, {}, _ctx)
  double _x3596;
  kk_std_core__list x0_2792;
  kk_box_t _x3597 = (kk_ref_get(x,kk_context())); /*0*/
  x0_2792 = kk_std_core__list_unbox(_x3597, _ctx); /*list<double>*/
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x0_2792, _ctx);
    kk_box_t _x3598 = kk_std_core_hnd_yield_extend(kk_climate_dash_change__new_mlift2696_linear__gaussian__climate__data_fun3599(_b_3292, _ctx), _ctx); /*2*/
    _x3596 = kk_double_unbox(_x3598, _ctx); /*double*/
  }
  else {
    _x3596 = kk_climate_dash_change__mlift2679_linear__gaussian__climate__data(_b_3292, x0_2792, _ctx); /*double*/
  }
  return kk_double_box(_x3596, _ctx);
}

kk_std_core__list kk_climate_dash_change__mlift2696_linear__gaussian__climate__data(kk_ref_t x, kk_unit_t wild__1, kk_context_t* _ctx) { /* forall<h> (x : local-var<h,list<double>>, wild_1 : ()) -> <exn,local<h>,effects-and-types/sample,effects-and-types/score> list<double> */ 
  return kk_std_core__lift21054_list_1(kk_climate_dash_change__new_mlift2696_linear__gaussian__climate__data_fun3595(x, _ctx), kk_integer_from_small(0), kk_integer_from_small(12), kk_std_core__new_Nil(_ctx), _ctx);
}


// lift anonymous function
struct kk_climate_dash_change_linear__gaussian__climate__data_fun3602__t {
  struct kk_function_s _base;
  kk_std_core__list vs;
  kk_std_core__list ys;
  double diff;
  double score__var;
  double subtract;
};
static kk_std_core__list kk_climate_dash_change_linear__gaussian__climate__data_fun3602(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change_new_linear__gaussian__climate__data_fun3602(kk_std_core__list vs, kk_std_core__list ys, double diff, double score__var, double subtract, kk_context_t* _ctx) {
  struct kk_climate_dash_change_linear__gaussian__climate__data_fun3602__t* _self = kk_function_alloc_as(struct kk_climate_dash_change_linear__gaussian__climate__data_fun3602__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_change_linear__gaussian__climate__data_fun3602, kk_context());
  _self->vs = vs;
  _self->ys = ys;
  _self->diff = diff;
  _self->score__var = score__var;
  _self->subtract = subtract;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_change_linear__gaussian__climate__data_fun3604__t {
  struct kk_function_s _base;
  kk_ref_t loc;
  kk_std_core__list vs;
  kk_std_core__list ys;
  double diff;
  double score__var;
  double subtract;
};
static kk_unit_t kk_climate_dash_change_linear__gaussian__climate__data_fun3604(kk_function_t _fself, kk_integer_t i, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change_new_linear__gaussian__climate__data_fun3604(kk_ref_t loc, kk_std_core__list vs, kk_std_core__list ys, double diff, double score__var, double subtract, kk_context_t* _ctx) {
  struct kk_climate_dash_change_linear__gaussian__climate__data_fun3604__t* _self = kk_function_alloc_as(struct kk_climate_dash_change_linear__gaussian__climate__data_fun3604__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_change_linear__gaussian__climate__data_fun3604, kk_context());
  _self->loc = loc;
  _self->vs = vs;
  _self->ys = ys;
  _self->diff = diff;
  _self->score__var = score__var;
  _self->subtract = subtract;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_change_linear__gaussian__climate__data_fun3610__t {
  struct kk_function_s _base;
  kk_ref_t loc;
  double diff;
  double subtract;
};
static kk_box_t kk_climate_dash_change_linear__gaussian__climate__data_fun3610(kk_function_t _fself, kk_box_t _b_3305, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change_new_linear__gaussian__climate__data_fun3610(kk_ref_t loc, double diff, double subtract, kk_context_t* _ctx) {
  struct kk_climate_dash_change_linear__gaussian__climate__data_fun3610__t* _self = kk_function_alloc_as(struct kk_climate_dash_change_linear__gaussian__climate__data_fun3610__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_change_linear__gaussian__climate__data_fun3610, kk_context());
  _self->loc = loc;
  _self->diff = diff;
  _self->subtract = subtract;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_change_linear__gaussian__climate__data_fun3610(kk_function_t _fself, kk_box_t _b_3305, kk_context_t* _ctx) {
  struct kk_climate_dash_change_linear__gaussian__climate__data_fun3610__t* _self = kk_function_as(struct kk_climate_dash_change_linear__gaussian__climate__data_fun3610__t*, _fself);
  kk_ref_t loc = _self->loc; /* local-var<global,list<double>> */
  double diff = _self->diff; /* double */
  double subtract = _self->subtract; /* double */
  kk_drop_match(_self, {kk_ref_dup(loc);;;}, {}, _ctx)
  kk_unit_t _x3611 = kk_Unit;
  kk_std_core__list _x3612 = kk_std_core__list_unbox(_b_3305, _ctx); /*list<double>*/
  kk_climate_dash_change__mlift2689_linear__gaussian__climate__data(diff, subtract, loc, _x3612, _ctx);
  return kk_unit_box(_x3611);
}


// lift anonymous function
struct kk_climate_dash_change_linear__gaussian__climate__data_fun3615__t {
  struct kk_function_s _base;
};
static kk_box_t kk_climate_dash_change_linear__gaussian__climate__data_fun3615(kk_function_t _fself, kk_box_t _b_3307, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change_new_linear__gaussian__climate__data_fun3615(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_climate_dash_change_linear__gaussian__climate__data_fun3615, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_climate_dash_change_linear__gaussian__climate__data_fun3615(kk_function_t _fself, kk_box_t _b_3307, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x3616;
  double _x3617 = kk_double_unbox(_b_3307, _ctx); /*double*/
  _x3616 = kk_model_dash_resources__mlift3175_normal(0x1p0, 0x1.999999999999ap-2, _x3617, _ctx); /*double*/
  return kk_double_box(_x3616, _ctx);
}


// lift anonymous function
struct kk_climate_dash_change_linear__gaussian__climate__data_fun3620__t {
  struct kk_function_s _base;
  size_t i0_2809;
};
static kk_box_t kk_climate_dash_change_linear__gaussian__climate__data_fun3620(kk_function_t _fself, kk_function_t _b_3315, kk_box_t _b_3316, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change_new_linear__gaussian__climate__data_fun3620(size_t i0_2809, kk_context_t* _ctx) {
  struct kk_climate_dash_change_linear__gaussian__climate__data_fun3620__t* _self = kk_function_alloc_as(struct kk_climate_dash_change_linear__gaussian__climate__data_fun3620__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_change_linear__gaussian__climate__data_fun3620, kk_context());
  _self->i0_2809 = i0_2809;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_change_linear__gaussian__climate__data_fun3620(kk_function_t _fself, kk_function_t _b_3315, kk_box_t _b_3316, kk_context_t* _ctx) {
  struct kk_climate_dash_change_linear__gaussian__climate__data_fun3620__t* _self = kk_function_as(struct kk_climate_dash_change_linear__gaussian__climate__data_fun3620__t*, _fself);
  size_t i0_2809 = _self->i0_2809; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i0_2809, _b_3315, _b_3316, _ctx);
}


// lift anonymous function
struct kk_climate_dash_change_linear__gaussian__climate__data_fun3623__t {
  struct kk_function_s _base;
  kk_integer_t i;
  kk_ref_t loc;
};
static kk_box_t kk_climate_dash_change_linear__gaussian__climate__data_fun3623(kk_function_t _fself, kk_box_t _b_3326, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change_new_linear__gaussian__climate__data_fun3623(kk_integer_t i, kk_ref_t loc, kk_context_t* _ctx) {
  struct kk_climate_dash_change_linear__gaussian__climate__data_fun3623__t* _self = kk_function_alloc_as(struct kk_climate_dash_change_linear__gaussian__climate__data_fun3623__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_change_linear__gaussian__climate__data_fun3623, kk_context());
  _self->i = i;
  _self->loc = loc;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_change_linear__gaussian__climate__data_fun3623(kk_function_t _fself, kk_box_t _b_3326, kk_context_t* _ctx) {
  struct kk_climate_dash_change_linear__gaussian__climate__data_fun3623__t* _self = kk_function_as(struct kk_climate_dash_change_linear__gaussian__climate__data_fun3623__t*, _fself);
  kk_integer_t i = _self->i; /* int */
  kk_ref_t loc = _self->loc; /* local-var<global,list<double>> */
  kk_drop_match(_self, {kk_integer_dup(i);kk_ref_dup(loc);}, {}, _ctx)
  kk_unit_t _x3624 = kk_Unit;
  double _x3625 = kk_double_unbox(_b_3326, _ctx); /*double*/
  kk_climate_dash_change__mlift2694_linear__gaussian__climate__data(i, loc, _x3625, _ctx);
  return kk_unit_box(_x3624);
}


// lift anonymous function
struct kk_climate_dash_change_linear__gaussian__climate__data_fun3629__t {
  struct kk_function_s _base;
  kk_integer_t i;
  kk_ref_t loc;
  kk_std_core__list vs;
  kk_std_core__list ys;
  double score__var;
};
static kk_box_t kk_climate_dash_change_linear__gaussian__climate__data_fun3629(kk_function_t _fself, kk_box_t _b_3332, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change_new_linear__gaussian__climate__data_fun3629(kk_integer_t i, kk_ref_t loc, kk_std_core__list vs, kk_std_core__list ys, double score__var, kk_context_t* _ctx) {
  struct kk_climate_dash_change_linear__gaussian__climate__data_fun3629__t* _self = kk_function_alloc_as(struct kk_climate_dash_change_linear__gaussian__climate__data_fun3629__t, 5, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_change_linear__gaussian__climate__data_fun3629, kk_context());
  _self->i = i;
  _self->loc = loc;
  _self->vs = vs;
  _self->ys = ys;
  _self->score__var = score__var;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_change_linear__gaussian__climate__data_fun3629(kk_function_t _fself, kk_box_t _b_3332, kk_context_t* _ctx) {
  struct kk_climate_dash_change_linear__gaussian__climate__data_fun3629__t* _self = kk_function_as(struct kk_climate_dash_change_linear__gaussian__climate__data_fun3629__t*, _fself);
  kk_integer_t i = _self->i; /* int */
  kk_ref_t loc = _self->loc; /* local-var<global,list<double>> */
  kk_std_core__list vs = _self->vs; /* list<effects-and-types/row_vector> */
  kk_std_core__list ys = _self->ys; /* list<effects-and-types/row_vector> */
  double score__var = _self->score__var; /* double */
  kk_drop_match(_self, {kk_integer_dup(i);kk_ref_dup(loc);kk_std_core__list_dup(vs);kk_std_core__list_dup(ys);;}, {}, _ctx)
  kk_unit_t _x3630 = kk_Unit;
  kk_unit_t _x3631 = kk_Unit;
  kk_unit_unbox(_b_3332);
  kk_climate_dash_change__mlift2695_linear__gaussian__climate__data(i, score__var, vs, loc, ys, _x3631, _ctx);
  return kk_unit_box(_x3630);
}
static kk_unit_t kk_climate_dash_change_linear__gaussian__climate__data_fun3604(kk_function_t _fself, kk_integer_t i, kk_context_t* _ctx) {
  struct kk_climate_dash_change_linear__gaussian__climate__data_fun3604__t* _self = kk_function_as(struct kk_climate_dash_change_linear__gaussian__climate__data_fun3604__t*, _fself);
  kk_ref_t loc = _self->loc; /* local-var<global,list<double>> */
  kk_std_core__list vs = _self->vs; /* list<effects-and-types/row_vector> */
  kk_std_core__list ys = _self->ys; /* list<effects-and-types/row_vector> */
  double diff = _self->diff; /* double */
  double score__var = _self->score__var; /* double */
  double subtract = _self->subtract; /* double */
  kk_drop_match(_self, {kk_ref_dup(loc);kk_std_core__list_dup(vs);kk_std_core__list_dup(ys);;;;}, {}, _ctx)
  kk_unit_t x1_2803 = kk_Unit;
  bool _match_3351;
  kk_integer_t _x3605 = kk_integer_dup(i); /*int*/
  _match_3351 = kk_integer_eq(_x3605,(kk_integer_from_small(0)),kk_context()); /*bool*/
  if (_match_3351) {
    kk_std_core__list x2_2805;
    kk_box_t _x3606;
    kk_ref_t _x3607 = kk_ref_dup(loc); /*local-var<global,list<double>>*/
    _x3606 = (kk_ref_get(_x3607,kk_context())); /*0*/
    x2_2805 = kk_std_core__list_unbox(_x3606, _ctx); /*list<double>*/
    if (kk_yielding(kk_context())) {
      kk_std_core__list_drop(x2_2805, _ctx);
      kk_box_t _x3608;
      kk_function_t _x3609;
      kk_ref_dup(loc);
      _x3609 = kk_climate_dash_change_new_linear__gaussian__climate__data_fun3610(loc, diff, subtract, _ctx); /*(1) -> 3 2*/
      _x3608 = kk_std_core_hnd_yield_extend(_x3609, _ctx); /*2*/
      kk_unit_unbox(_x3608);
    }
    else {
      kk_ref_t _x3613 = kk_ref_dup(loc); /*local-var<global,list<double>>*/
      kk_climate_dash_change__mlift2689_linear__gaussian__climate__data(diff, subtract, _x3613, x2_2805, _ctx);
    }
  }
  else {
    double x3_2807;
    size_t i0_2809 = ((size_t)1); /*std/core/hnd/ev-index*/;
    kk_evv_t w = kk_evv_swap_create1(i0_2809,kk_context()); /*std/core/hnd/evv<<effects-and-types/sample,exn,local<global>,effects-and-types/score>>*/;
    double y;
    double x_3267 = kk_model_dash_resources_standard_normal(_ctx); /*double*/;
    if (kk_yielding(kk_context())) {
      kk_box_t _x3614 = kk_std_core_hnd_yield_extend(kk_climate_dash_change_new_linear__gaussian__climate__data_fun3615(_ctx), _ctx); /*2*/
      y = kk_double_unbox(_x3614, _ctx); /*double*/
    }
    else {
      double _x3618 = (x_3267 * (0x1.999999999999ap-2)); /*double*/
      y = (0x1p0 + _x3618); /*double*/
    }
    kk_unit_t __w_l717_c9 = kk_Unit;
    kk_evv_set(w,kk_context());
    if (kk_yielding(kk_context())) {
      kk_box_t _x3619 = kk_std_core_hnd_yield_cont(kk_climate_dash_change_new_linear__gaussian__climate__data_fun3620(i0_2809, _ctx), _ctx); /*3*/
      x3_2807 = kk_double_unbox(_x3619, _ctx); /*double*/
    }
    else {
      x3_2807 = y; /*double*/
    }
    if (kk_yielding(kk_context())) {
      kk_box_t _x3621;
      kk_function_t _x3622;
      kk_integer_dup(i);
      kk_ref_dup(loc);
      _x3622 = kk_climate_dash_change_new_linear__gaussian__climate__data_fun3623(i, loc, _ctx); /*(1) -> 3 2*/
      _x3621 = kk_std_core_hnd_yield_extend(_x3622, _ctx); /*2*/
      kk_unit_unbox(_x3621);
    }
    else {
      kk_integer_t _x3626 = kk_integer_dup(i); /*int*/
      kk_ref_t _x3627 = kk_ref_dup(loc); /*local-var<global,list<double>>*/
      kk_climate_dash_change__mlift2694_linear__gaussian__climate__data(_x3626, _x3627, x3_2807, _ctx);
    }
  }
  if (kk_yielding(kk_context())) {
    kk_box_t _x3628 = kk_std_core_hnd_yield_extend(kk_climate_dash_change_new_linear__gaussian__climate__data_fun3629(i, loc, vs, ys, score__var, _ctx), _ctx); /*2*/
    return kk_unit_unbox(_x3628);
  }
  return kk_climate_dash_change__mlift2695_linear__gaussian__climate__data(i, score__var, vs, loc, ys, x1_2803, _ctx);
}


// lift anonymous function
struct kk_climate_dash_change_linear__gaussian__climate__data_fun3634__t {
  struct kk_function_s _base;
  kk_ref_t loc;
};
static kk_box_t kk_climate_dash_change_linear__gaussian__climate__data_fun3634(kk_function_t _fself, kk_box_t _b_3336, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_change_new_linear__gaussian__climate__data_fun3634(kk_ref_t loc, kk_context_t* _ctx) {
  struct kk_climate_dash_change_linear__gaussian__climate__data_fun3634__t* _self = kk_function_alloc_as(struct kk_climate_dash_change_linear__gaussian__climate__data_fun3634__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_change_linear__gaussian__climate__data_fun3634, kk_context());
  _self->loc = loc;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_change_linear__gaussian__climate__data_fun3634(kk_function_t _fself, kk_box_t _b_3336, kk_context_t* _ctx) {
  struct kk_climate_dash_change_linear__gaussian__climate__data_fun3634__t* _self = kk_function_as(struct kk_climate_dash_change_linear__gaussian__climate__data_fun3634__t*, _fself);
  kk_ref_t loc = _self->loc; /* local-var<global,list<double>> */
  kk_drop_match(_self, {kk_ref_dup(loc);}, {}, _ctx)
  kk_std_core__list _x3635;
  kk_unit_t _x3636 = kk_Unit;
  kk_unit_unbox(_b_3336);
  _x3635 = kk_climate_dash_change__mlift2696_linear__gaussian__climate__data(loc, _x3636, _ctx); /*list<double>*/
  return kk_std_core__list_box(_x3635, _ctx);
}
static kk_std_core__list kk_climate_dash_change_linear__gaussian__climate__data_fun3602(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_change_linear__gaussian__climate__data_fun3602__t* _self = kk_function_as(struct kk_climate_dash_change_linear__gaussian__climate__data_fun3602__t*, _fself);
  kk_std_core__list vs = _self->vs; /* list<effects-and-types/row_vector> */
  kk_std_core__list ys = _self->ys; /* list<effects-and-types/row_vector> */
  double diff = _self->diff; /* double */
  double score__var = _self->score__var; /* double */
  double subtract = _self->subtract; /* double */
  kk_drop_match(_self, {kk_std_core__list_dup(vs);kk_std_core__list_dup(ys);;;;}, {}, _ctx)
  kk_ref_t loc = kk_ref_alloc((kk_std_core__list_box(kk_std_core__new_Nil(_ctx), _ctx)),kk_context()); /*local-var<global,list<double>>*/;
  kk_std_core__list res;
  kk_unit_t x0_2798 = kk_Unit;
  kk_function_t _x3603;
  kk_ref_dup(loc);
  _x3603 = kk_climate_dash_change_new_linear__gaussian__climate__data_fun3604(loc, vs, ys, diff, score__var, subtract, _ctx); /*(i : int) -> <exn,local<global>,effects-and-types/sample,effects-and-types/score> ()*/
  kk_std_core__lift21056_for(_x3603, kk_integer_from_small(12), kk_integer_from_small(0), _ctx);
  if (kk_yielding(kk_context())) {
    kk_box_t _x3632;
    kk_function_t _x3633;
    kk_ref_dup(loc);
    _x3633 = kk_climate_dash_change_new_linear__gaussian__climate__data_fun3634(loc, _ctx); /*(1) -> 3 2*/
    _x3632 = kk_std_core_hnd_yield_extend(_x3633, _ctx); /*2*/
    res = kk_std_core__list_unbox(_x3632, _ctx); /*list<double>*/
  }
  else {
    kk_ref_t _x3637 = kk_ref_dup(loc); /*local-var<global,list<double>>*/
    res = kk_climate_dash_change__mlift2696_linear__gaussian__climate__data(_x3637, x0_2798, _ctx); /*list<double>*/
  }
  kk_box_t _x3638 = kk_std_core_hnd_prompt_local_var(loc, kk_std_core__list_box(res, _ctx), _ctx); /*2*/
  return kk_std_core__list_unbox(_x3638, _ctx);
}

kk_function_t kk_climate_dash_change_linear__gaussian__climate__data(kk_std_core__list ys, kk_std_core__list vs, bool print, double diff, double subtract, double score__var, kk_context_t* _ctx) { /* (ys : list<effects-and-types/row_vector>, vs : list<effects-and-types/row_vector>, print : bool, diff : double, subtract : double, score_var : double) -> effects-and-types/model<list<double>,exn> */ 
  return kk_climate_dash_change_new_linear__gaussian__climate__data_fun3602(vs, ys, diff, score__var, subtract, _ctx);
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
  kk_model_dash_resources__init(_ctx);
  kk_exn_dash_get__init(_ctx);
}
