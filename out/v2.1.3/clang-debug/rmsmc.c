// Koka generated module: "rmsmc", koka version: 2.1.3
#include "rmsmc.h"
 
// monadic lift


// lift anonymous function
struct kk_rmsmc__mlift665_rmsmc__loop_fun777__t {
  struct kk_function_s _base;
  kk_box_t _fun_unbox_x684;
};
static kk_box_t kk_rmsmc__mlift665_rmsmc__loop_fun777(kk_function_t _fself, kk_box_t _b_693, kk_context_t* _ctx);
static kk_function_t kk_rmsmc__new_mlift665_rmsmc__loop_fun777(kk_box_t _fun_unbox_x684, kk_context_t* _ctx) {
  struct kk_rmsmc__mlift665_rmsmc__loop_fun777__t* _self = kk_function_alloc_as(struct kk_rmsmc__mlift665_rmsmc__loop_fun777__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_rmsmc__mlift665_rmsmc__loop_fun777, kk_context());
  _self->_fun_unbox_x684 = _fun_unbox_x684;
  return &_self->_base;
}

static kk_box_t kk_rmsmc__mlift665_rmsmc__loop_fun777(kk_function_t _fself, kk_box_t _b_693, kk_context_t* _ctx) {
  struct kk_rmsmc__mlift665_rmsmc__loop_fun777__t* _self = kk_function_as(struct kk_rmsmc__mlift665_rmsmc__loop_fun777__t*, _fself);
  kk_box_t _fun_unbox_x684 = _self->_fun_unbox_x684; /* 4 */
  kk_drop_match(_self, {kk_box_dup(_fun_unbox_x684);}, {}, _ctx)
  kk_function_t _x778 = kk_function_unbox(_fun_unbox_x684); /*(a : 685) -> <effects-and-types/yield,effects-and-types/score,effects-and-types/sample,effects-and-types/sample,exn,div|594> 686*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x778, (_x778, _b_693, _ctx));
}

kk_std_core_types__tuple3_ kk_rmsmc__mlift665_rmsmc__loop(kk_std_core_types__tuple3_ _y_3, kk_context_t* _ctx) { /* forall<a,e> ((effects-and-types/trace_values, effects-and-types/exp, (a : int) -> <effects-and-types/yield,effects-and-types/score,effects-and-types/sample,effects-and-types/sample,exn,div|e> a)) -> <effects-and-types/sample,exn,div|e> (effects-and-types/trace_values, effects-and-types/exp, (a : int) -> <effects-and-types/yield,effects-and-types/score,effects-and-types/sample,effects-and-types/sample,exn,div|e> a) */ 
  kk_box_t _box_x679 = _y_3.fst;
  kk_box_t _box_x680 = _y_3.snd;
  kk_box_t _fun_unbox_x684 = _y_3.thd;
  kk_std_core__list tr__new = kk_std_core__list_unbox(_box_x679, NULL);
  kk_effects_dash_and_dash_types__exp w__new = kk_effects_dash_and_dash_types__exp_unbox(_box_x680, NULL);
  kk_box_dup(_fun_unbox_x684);
  kk_std_core__list_dup(tr__new);
  kk_std_core_types__tuple3__drop(_y_3, _ctx);
  return kk_std_core_types__new_dash__lp__comma__comma__rp_(kk_std_core__list_box(tr__new, _ctx), kk_effects_dash_and_dash_types__exp_box(w__new, _ctx), kk_function_box(kk_rmsmc__new_mlift665_rmsmc__loop_fun777(_fun_unbox_x684, _ctx)), _ctx);
}
 
// monadic lift

kk_std_core__list kk_rmsmc__mlift666_rmsmc__loop(kk_integer_t composition__1, kk_integer_t i, kk_integer_t mh__step__num, bool normalize, kk_integer_t smc__step__num, kk_integer_t step__size, kk_std_core__list irrelevant, kk_context_t* _ctx) { /* forall<a,e> (composition_1 : int, i : int, mh_step_num : int, normalize : bool, smc_step_num : int, step_size : int, irrelevant : list<(effects-and-types/trace_values, effects-and-types/exp, (a : int) -> <effects-and-types/yield,effects-and-types/score,effects-and-types/sample,effects-and-types/sample,exn,div|e> a)>) -> <effects-and-types/sample,exn,div|e> effects-and-types/histogram_rmsmc<a> */ 
  if (normalize) {
    kk_integer_t _x779 = kk_integer_add(i,(kk_integer_from_small(1)),kk_context()); /*int*/
    return kk_rmsmc_rmsmc__loop(irrelevant, composition__1, _x779, smc__step__num, mh__step__num, step__size, normalize, _ctx);
  }
  kk_integer_t _x780 = kk_integer_add(i,(kk_integer_from_small(1)),kk_context()); /*int*/
  return kk_rmsmc_rmsmc__loop(irrelevant, composition__1, _x780, smc__step__num, mh__step__num, step__size, normalize, _ctx);
}


// lift anonymous function
struct kk_rmsmc_rmsmc__loop_fun784__t {
  struct kk_function_s _base;
  kk_integer_t step__size0;
};
static kk_box_t kk_rmsmc_rmsmc__loop_fun784(kk_function_t _fself, kk_box_t _b_719, kk_context_t* _ctx);
static kk_function_t kk_rmsmc_new_rmsmc__loop_fun784(kk_integer_t step__size0, kk_context_t* _ctx) {
  struct kk_rmsmc_rmsmc__loop_fun784__t* _self = kk_function_alloc_as(struct kk_rmsmc_rmsmc__loop_fun784__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_rmsmc_rmsmc__loop_fun784, kk_context());
  _self->step__size0 = step__size0;
  return &_self->_base;
}



// lift anonymous function
struct kk_rmsmc_rmsmc__loop_fun788__t {
  struct kk_function_s _base;
  kk_box_t _fun_unbox_x703;
  kk_integer_t step__size0;
  kk_effects_dash_and_dash_types__exp w;
};
static kk_std_core_types__tuple2_ kk_rmsmc_rmsmc__loop_fun788(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_rmsmc_new_rmsmc__loop_fun788(kk_box_t _fun_unbox_x703, kk_integer_t step__size0, kk_effects_dash_and_dash_types__exp w, kk_context_t* _ctx) {
  struct kk_rmsmc_rmsmc__loop_fun788__t* _self = kk_function_alloc_as(struct kk_rmsmc_rmsmc__loop_fun788__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_rmsmc_rmsmc__loop_fun788, kk_context());
  _self->_fun_unbox_x703 = _fun_unbox_x703;
  _self->step__size0 = step__size0;
  _self->w = w;
  return &_self->_base;
}



// lift anonymous function
struct kk_rmsmc_rmsmc__loop_fun789__t {
  struct kk_function_s _base;
  kk_box_t _fun_unbox_x703;
  kk_integer_t step__size0;
};
static kk_box_t kk_rmsmc_rmsmc__loop_fun789(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_rmsmc_new_rmsmc__loop_fun789(kk_box_t _fun_unbox_x703, kk_integer_t step__size0, kk_context_t* _ctx) {
  struct kk_rmsmc_rmsmc__loop_fun789__t* _self = kk_function_alloc_as(struct kk_rmsmc_rmsmc__loop_fun789__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_rmsmc_rmsmc__loop_fun789, kk_context());
  _self->_fun_unbox_x703 = _fun_unbox_x703;
  _self->step__size0 = step__size0;
  return &_self->_base;
}



// lift anonymous function
struct kk_rmsmc_rmsmc__loop_fun791__t {
  struct kk_function_s _base;
  kk_box_t _fun_unbox_x703;
  kk_integer_t step__size0;
};
static kk_box_t kk_rmsmc_rmsmc__loop_fun791(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_rmsmc_new_rmsmc__loop_fun791(kk_box_t _fun_unbox_x703, kk_integer_t step__size0, kk_context_t* _ctx) {
  struct kk_rmsmc_rmsmc__loop_fun791__t* _self = kk_function_alloc_as(struct kk_rmsmc_rmsmc__loop_fun791__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_rmsmc_rmsmc__loop_fun791, kk_context());
  _self->_fun_unbox_x703 = _fun_unbox_x703;
  _self->step__size0 = step__size0;
  return &_self->_base;
}

static kk_box_t kk_rmsmc_rmsmc__loop_fun791(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_rmsmc_rmsmc__loop_fun791__t* _self = kk_function_as(struct kk_rmsmc_rmsmc__loop_fun791__t*, _fself);
  kk_box_t _fun_unbox_x703 = _self->_fun_unbox_x703; /* 4 */
  kk_integer_t step__size0 = _self->step__size0; /* int */
  kk_drop_match(_self, {kk_box_dup(_fun_unbox_x703);kk_integer_dup(step__size0);}, {}, _ctx)
  kk_function_t _x792 = kk_function_unbox(_fun_unbox_x703); /*(704) -> <effects-and-types/yield,effects-and-types/score,effects-and-types/sample,effects-and-types/sample,exn,div|594> 705*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x792, (_x792, kk_integer_box(step__size0), _ctx));
}


// lift anonymous function
struct kk_rmsmc_rmsmc__loop_fun793__t {
  struct kk_function_s _base;
  kk_function_t _bv_711;
};
static kk_box_t kk_rmsmc_rmsmc__loop_fun793(kk_function_t _fself, kk_box_t _b_712, kk_context_t* _ctx);
static kk_function_t kk_rmsmc_new_rmsmc__loop_fun793(kk_function_t _bv_711, kk_context_t* _ctx) {
  struct kk_rmsmc_rmsmc__loop_fun793__t* _self = kk_function_alloc_as(struct kk_rmsmc_rmsmc__loop_fun793__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_rmsmc_rmsmc__loop_fun793, kk_context());
  _self->_bv_711 = _bv_711;
  return &_self->_base;
}

static kk_box_t kk_rmsmc_rmsmc__loop_fun793(kk_function_t _fself, kk_box_t _b_712, kk_context_t* _ctx) {
  struct kk_rmsmc_rmsmc__loop_fun793__t* _self = kk_function_as(struct kk_rmsmc_rmsmc__loop_fun793__t*, _fself);
  kk_function_t _bv_711 = _self->_bv_711; /* (a : int) -> <effects-and-types/yield,effects-and-types/score,effects-and-types/sample,effects-and-types/sample,exn,div|594> 591 */
  kk_drop_match(_self, {kk_function_dup(_bv_711);}, {}, _ctx)
  kk_integer_t _x794 = kk_integer_unbox(_b_712); /*int*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_context_t*), _bv_711, (_bv_711, _x794, _ctx));
}
static kk_box_t kk_rmsmc_rmsmc__loop_fun789(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_rmsmc_rmsmc__loop_fun789__t* _self = kk_function_as(struct kk_rmsmc_rmsmc__loop_fun789__t*, _fself);
  kk_box_t _fun_unbox_x703 = _self->_fun_unbox_x703; /* 4 */
  kk_integer_t step__size0 = _self->step__size0; /* int */
  kk_drop_match(_self, {kk_box_dup(_fun_unbox_x703);kk_integer_dup(step__size0);}, {}, _ctx)
  kk_function_t _x790;
  kk_function_t _bv_711 = kk_handlers_advance(kk_rmsmc_new_rmsmc__loop_fun791(_fun_unbox_x703, step__size0, _ctx), _ctx); /*(a : int) -> <effects-and-types/yield,effects-and-types/score,effects-and-types/sample,effects-and-types/sample,exn,div|594> 591*/;
  _x790 = kk_rmsmc_new_rmsmc__loop_fun793(_bv_711, _ctx); /*(709) -> <effects-and-types/yield,effects-and-types/score,effects-and-types/sample,effects-and-types/sample,exn,div|594> 591*/
  return kk_function_box(_x790);
}
static kk_std_core_types__tuple2_ kk_rmsmc_rmsmc__loop_fun788(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_rmsmc_rmsmc__loop_fun788__t* _self = kk_function_as(struct kk_rmsmc_rmsmc__loop_fun788__t*, _fself);
  kk_box_t _fun_unbox_x703 = _self->_fun_unbox_x703; /* 4 */
  kk_integer_t step__size0 = _self->step__size0; /* int */
  kk_effects_dash_and_dash_types__exp w = _self->w; /* effects-and-types/exp */
  kk_drop_match(_self, {kk_box_dup(_fun_unbox_x703);kk_integer_dup(step__size0);kk_effects_dash_and_dash_types__exp_dup(w);}, {}, _ctx)
  return kk_handlers_weighted(w, kk_rmsmc_new_rmsmc__loop_fun789(_fun_unbox_x703, step__size0, _ctx), _ctx);
}


// lift anonymous function
struct kk_rmsmc_rmsmc__loop_fun796__t {
  struct kk_function_s _base;
};
static kk_box_t kk_rmsmc_rmsmc__loop_fun796(kk_function_t _fself, kk_box_t _b_716, kk_context_t* _ctx);
static kk_function_t kk_rmsmc_new_rmsmc__loop_fun796(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_rmsmc_rmsmc__loop_fun796, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_rmsmc_rmsmc__loop_fun796(kk_function_t _fself, kk_box_t _b_716, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core_types__tuple3_ _x797;
  kk_std_core_types__tuple3_ _x798 = kk_std_core_types__tuple3__unbox(_b_716, _ctx); /*(effects-and-types/trace_values, effects-and-types/exp, (a : int) -> <effects-and-types/yield,effects-and-types/score,effects-and-types/sample,effects-and-types/sample,exn,div|594> 591)*/
  _x797 = kk_rmsmc__mlift665_rmsmc__loop(_x798, _ctx); /*(effects-and-types/trace_values, effects-and-types/exp, (a : int) -> <effects-and-types/yield,effects-and-types/score,effects-and-types/sample,effects-and-types/sample,exn,div|594> 591)*/
  return kk_std_core_types__tuple3__box(_x797, _ctx);
}
static kk_box_t kk_rmsmc_rmsmc__loop_fun784(kk_function_t _fself, kk_box_t _b_719, kk_context_t* _ctx) {
  struct kk_rmsmc_rmsmc__loop_fun784__t* _self = kk_function_as(struct kk_rmsmc_rmsmc__loop_fun784__t*, _fself);
  kk_integer_t step__size0 = _self->step__size0; /* int */
  kk_drop_match(_self, {kk_integer_dup(step__size0);}, {}, _ctx)
  kk_std_core_types__tuple3_ _x785;
  kk_std_core_types__tuple3_ _match_773 = kk_std_core_types__tuple3__unbox(_b_719, _ctx); /*(effects-and-types/trace_values, effects-and-types/exp, (int) -> <effects-and-types/yield,effects-and-types/score,effects-and-types/sample,effects-and-types/sample,exn,div|594> 591)*/;
  kk_box_t _box_x698 = _match_773.fst;
  kk_box_t _box_x699 = _match_773.snd;
  kk_box_t _fun_unbox_x703 = _match_773.thd;
  kk_std_core__list tr = kk_std_core__list_unbox(_box_x698, NULL);
  kk_effects_dash_and_dash_types__exp w = kk_effects_dash_and_dash_types__exp_unbox(_box_x699, NULL);
  kk_box_dup(_fun_unbox_x703);
  kk_std_core__list_dup(tr);
  kk_std_core_types__tuple3__drop(_match_773, _ctx);
  kk_std_core_types__tuple3_ x0_671 = kk_handlers_recorder(tr, kk_rmsmc_new_rmsmc__loop_fun788(_fun_unbox_x703, step__size0, w, _ctx), _ctx); /*(effects-and-types/trace_values, effects-and-types/exp, (a : int) -> <effects-and-types/yield,effects-and-types/score,effects-and-types/sample,effects-and-types/sample,exn,div|594> 591)*/;
  if (kk_yielding(kk_context())) {
    kk_std_core_types__tuple3__drop(x0_671, _ctx);
    kk_box_t _x795 = kk_std_core_hnd_yield_extend(kk_rmsmc_new_rmsmc__loop_fun796(_ctx), _ctx); /*2*/
    _x785 = kk_std_core_types__tuple3__unbox(_x795, _ctx); /*(effects-and-types/trace_values, effects-and-types/exp, (a : int) -> <effects-and-types/yield,effects-and-types/score,effects-and-types/sample,effects-and-types/sample,exn,div|594> 591)*/
  }
  else {
    _x785 = kk_rmsmc__mlift665_rmsmc__loop(x0_671, _ctx); /*(effects-and-types/trace_values, effects-and-types/exp, (a : int) -> <effects-and-types/yield,effects-and-types/score,effects-and-types/sample,effects-and-types/sample,exn,div|594> 591)*/
  }
  return kk_std_core_types__tuple3__box(_x785, _ctx);
}


// lift anonymous function
struct kk_rmsmc_rmsmc__loop_fun800__t {
  struct kk_function_s _base;
  kk_integer_t composition__10;
  kk_integer_t i0;
  kk_integer_t mh__step__num0;
  kk_integer_t smc__step__num0;
  kk_integer_t step__size0;
  bool normalize0;
};
static kk_box_t kk_rmsmc_rmsmc__loop_fun800(kk_function_t _fself, kk_box_t _b_727, kk_context_t* _ctx);
static kk_function_t kk_rmsmc_new_rmsmc__loop_fun800(kk_integer_t composition__10, kk_integer_t i0, kk_integer_t mh__step__num0, kk_integer_t smc__step__num0, kk_integer_t step__size0, bool normalize0, kk_context_t* _ctx) {
  struct kk_rmsmc_rmsmc__loop_fun800__t* _self = kk_function_alloc_as(struct kk_rmsmc_rmsmc__loop_fun800__t, 6, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_rmsmc_rmsmc__loop_fun800, kk_context());
  _self->composition__10 = composition__10;
  _self->i0 = i0;
  _self->mh__step__num0 = mh__step__num0;
  _self->smc__step__num0 = smc__step__num0;
  _self->step__size0 = step__size0;
  _self->normalize0 = normalize0;
  return &_self->_base;
}

static kk_box_t kk_rmsmc_rmsmc__loop_fun800(kk_function_t _fself, kk_box_t _b_727, kk_context_t* _ctx) {
  struct kk_rmsmc_rmsmc__loop_fun800__t* _self = kk_function_as(struct kk_rmsmc_rmsmc__loop_fun800__t*, _fself);
  kk_integer_t composition__10 = _self->composition__10; /* int */
  kk_integer_t i0 = _self->i0; /* int */
  kk_integer_t mh__step__num0 = _self->mh__step__num0; /* int */
  kk_integer_t smc__step__num0 = _self->smc__step__num0; /* int */
  kk_integer_t step__size0 = _self->step__size0; /* int */
  bool normalize0 = _self->normalize0; /* bool */
  kk_drop_match(_self, {kk_integer_dup(composition__10);kk_integer_dup(i0);kk_integer_dup(mh__step__num0);kk_integer_dup(smc__step__num0);kk_integer_dup(step__size0);;}, {}, _ctx)
  kk_std_core__list _x801;
  kk_std_core__list _x802 = kk_std_core__list_unbox(_b_727, _ctx); /*list<(effects-and-types/trace_values, effects-and-types/exp, (a : int) -> <effects-and-types/yield,effects-and-types/score,effects-and-types/sample,effects-and-types/sample,exn,div|594> 591)>*/
  _x801 = kk_rmsmc__mlift666_rmsmc__loop(composition__10, i0, mh__step__num0, normalize0, smc__step__num0, step__size0, _x802, _ctx); /*effects-and-types/histogram_rmsmc<591>*/
  return kk_std_core__list_box(_x801, _ctx);
}


// lift anonymous function
struct kk_rmsmc_rmsmc__loop_fun805__t {
  struct kk_function_s _base;
};
static kk_std_core_types__tuple3_ kk_rmsmc_rmsmc__loop_fun805(kk_function_t _fself, kk_std_core_types__tuple3_ wm0, kk_context_t* _ctx);
static kk_function_t kk_rmsmc_new_rmsmc__loop_fun805(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_rmsmc_rmsmc__loop_fun805, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_rmsmc_rmsmc__loop_fun808__t {
  struct kk_function_s _base;
  kk_box_t _fun_unbox_x733;
  kk_effects_dash_and_dash_types__exp w0;
};
static kk_std_core_types__tuple2_ kk_rmsmc_rmsmc__loop_fun808(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_rmsmc_new_rmsmc__loop_fun808(kk_box_t _fun_unbox_x733, kk_effects_dash_and_dash_types__exp w0, kk_context_t* _ctx) {
  struct kk_rmsmc_rmsmc__loop_fun808__t* _self = kk_function_alloc_as(struct kk_rmsmc_rmsmc__loop_fun808__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_rmsmc_rmsmc__loop_fun808, kk_context());
  _self->_fun_unbox_x733 = _fun_unbox_x733;
  _self->w0 = w0;
  return &_self->_base;
}



// lift anonymous function
struct kk_rmsmc_rmsmc__loop_fun809__t {
  struct kk_function_s _base;
  kk_box_t _fun_unbox_x733;
};
static kk_box_t kk_rmsmc_rmsmc__loop_fun809(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_rmsmc_new_rmsmc__loop_fun809(kk_box_t _fun_unbox_x733, kk_context_t* _ctx) {
  struct kk_rmsmc_rmsmc__loop_fun809__t* _self = kk_function_alloc_as(struct kk_rmsmc_rmsmc__loop_fun809__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_rmsmc_rmsmc__loop_fun809, kk_context());
  _self->_fun_unbox_x733 = _fun_unbox_x733;
  return &_self->_base;
}



// lift anonymous function
struct kk_rmsmc_rmsmc__loop_fun812__t {
  struct kk_function_s _base;
};
static kk_box_t kk_rmsmc_rmsmc__loop_fun812(kk_function_t _fself, kk_std_core_hnd__marker _b_738, kk_std_core_hnd__ev _b_739, kk_context_t* _ctx);
static kk_function_t kk_rmsmc_new_rmsmc__loop_fun812(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_rmsmc_rmsmc__loop_fun812, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_rmsmc_rmsmc__loop_fun812(kk_function_t _fself, kk_std_core_hnd__marker _b_738, kk_std_core_hnd__ev _b_739, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core_hnd__ev_dropn(_b_739, ((int32_t)3), _ctx);
  return kk_unit_box(kk_Unit);
}


// lift anonymous function
struct kk_rmsmc_rmsmc__loop_fun813__t {
  struct kk_function_s _base;
};
static kk_box_t kk_rmsmc_rmsmc__loop_fun813(kk_function_t _fself, kk_box_t _x, kk_context_t* _ctx);
static kk_function_t kk_rmsmc_new_rmsmc__loop_fun813(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_rmsmc_rmsmc__loop_fun813, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_rmsmc_rmsmc__loop_fun813(kk_function_t _fself, kk_box_t _x, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return _x;
}


// lift anonymous function
struct kk_rmsmc_rmsmc__loop_fun814__t {
  struct kk_function_s _base;
  kk_box_t _fun_unbox_x733;
};
static kk_box_t kk_rmsmc_rmsmc__loop_fun814(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_rmsmc_new_rmsmc__loop_fun814(kk_box_t _fun_unbox_x733, kk_context_t* _ctx) {
  struct kk_rmsmc_rmsmc__loop_fun814__t* _self = kk_function_alloc_as(struct kk_rmsmc_rmsmc__loop_fun814__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_rmsmc_rmsmc__loop_fun814, kk_context());
  _self->_fun_unbox_x733 = _fun_unbox_x733;
  return &_self->_base;
}

static kk_box_t kk_rmsmc_rmsmc__loop_fun814(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_rmsmc_rmsmc__loop_fun814__t* _self = kk_function_as(struct kk_rmsmc_rmsmc__loop_fun814__t*, _fself);
  kk_box_t _fun_unbox_x733 = _self->_fun_unbox_x733; /* 4 */
  kk_drop_match(_self, {kk_box_dup(_fun_unbox_x733);}, {}, _ctx)
  kk_function_t _x815 = kk_function_unbox(_fun_unbox_x733); /*(734) -> <effects-and-types/yield,effects-and-types/score,effects-and-types/sample,effects-and-types/sample,exn,div|594> 735*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x815, (_x815, kk_integer_box(kk_integer_from_small(0)), _ctx));
}
static kk_box_t kk_rmsmc_rmsmc__loop_fun809(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_rmsmc_rmsmc__loop_fun809__t* _self = kk_function_as(struct kk_rmsmc_rmsmc__loop_fun809__t*, _fself);
  kk_box_t _fun_unbox_x733 = _self->_fun_unbox_x733; /* 4 */
  kk_drop_match(_self, {kk_box_dup(_fun_unbox_x733);}, {}, _ctx)
  kk_effects_dash_and_dash_types__hnd_yield _x810;
  kk_std_core_hnd__clause0 _x811 = kk_std_core_hnd__new_Clause0(kk_rmsmc_new_rmsmc__loop_fun812(_ctx), _ctx); /*std/core/hnd/clause0<11,12,13,14>*/
  _x810 = kk_effects_dash_and_dash_types__new_Hnd_yield(kk_reuse_null, _x811, _ctx); /*effects-and-types/.hnd-yield<7,8>*/
  return kk_effects_dash_and_dash_types__handle_yield(((int32_t)1), _x810, kk_rmsmc_new_rmsmc__loop_fun813(_ctx), kk_rmsmc_new_rmsmc__loop_fun814(_fun_unbox_x733, _ctx), _ctx);
}
static kk_std_core_types__tuple2_ kk_rmsmc_rmsmc__loop_fun808(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_rmsmc_rmsmc__loop_fun808__t* _self = kk_function_as(struct kk_rmsmc_rmsmc__loop_fun808__t*, _fself);
  kk_box_t _fun_unbox_x733 = _self->_fun_unbox_x733; /* 4 */
  kk_effects_dash_and_dash_types__exp w0 = _self->w0; /* effects-and-types/exp */
  kk_drop_match(_self, {kk_box_dup(_fun_unbox_x733);kk_effects_dash_and_dash_types__exp_dup(w0);}, {}, _ctx)
  return kk_handlers_weighted(w0, kk_rmsmc_new_rmsmc__loop_fun809(_fun_unbox_x733, _ctx), _ctx);
}
static kk_std_core_types__tuple3_ kk_rmsmc_rmsmc__loop_fun805(kk_function_t _fself, kk_std_core_types__tuple3_ wm0, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_box_t _box_x728 = wm0.fst;
  kk_box_t _box_x729 = wm0.snd;
  kk_box_t _fun_unbox_x733 = wm0.thd;
  kk_std_core__list tr0 = kk_std_core__list_unbox(_box_x728, NULL);
  kk_effects_dash_and_dash_types__exp w0 = kk_effects_dash_and_dash_types__exp_unbox(_box_x729, NULL);
  kk_box_dup(_fun_unbox_x733);
  kk_std_core__list_dup(tr0);
  kk_std_core_types__tuple3__drop(wm0, _ctx);
  return kk_handlers_recorder(tr0, kk_rmsmc_new_rmsmc__loop_fun808(_fun_unbox_x733, w0, _ctx), _ctx);
}


// lift anonymous function
struct kk_rmsmc_rmsmc__loop_fun816__t {
  struct kk_function_s _base;
  kk_function_t finalize__func;
};
static kk_box_t kk_rmsmc_rmsmc__loop_fun816(kk_function_t _fself, kk_box_t _b_746, kk_context_t* _ctx);
static kk_function_t kk_rmsmc_new_rmsmc__loop_fun816(kk_function_t finalize__func, kk_context_t* _ctx) {
  struct kk_rmsmc_rmsmc__loop_fun816__t* _self = kk_function_alloc_as(struct kk_rmsmc_rmsmc__loop_fun816__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_rmsmc_rmsmc__loop_fun816, kk_context());
  _self->finalize__func = finalize__func;
  return &_self->_base;
}

static kk_box_t kk_rmsmc_rmsmc__loop_fun816(kk_function_t _fself, kk_box_t _b_746, kk_context_t* _ctx) {
  struct kk_rmsmc_rmsmc__loop_fun816__t* _self = kk_function_as(struct kk_rmsmc_rmsmc__loop_fun816__t*, _fself);
  kk_function_t finalize__func = _self->finalize__func; /* (wm : (effects-and-types/trace_values, effects-and-types/exp, (int) -> <effects-and-types/yield,effects-and-types/score,effects-and-types/sample,effects-and-types/sample,exn,div|594> 591)) -> <effects-and-types/sample,exn,div|594> (effects-and-types/trace_values, effects-and-types/exp, 591) */
  kk_drop_match(_self, {kk_function_dup(finalize__func);}, {}, _ctx)
  kk_std_core_types__tuple3_ _x817;
  kk_std_core_types__tuple3_ _x818 = kk_std_core_types__tuple3__unbox(_b_746, _ctx); /*(effects-and-types/trace_values, effects-and-types/exp, (int) -> <effects-and-types/yield,effects-and-types/score,effects-and-types/sample,effects-and-types/sample,exn,div|594> 591)*/
  _x817 = kk_function_call(kk_std_core_types__tuple3_, (kk_function_t, kk_std_core_types__tuple3_, kk_context_t*), finalize__func, (finalize__func, _x818, _ctx)); /*(effects-and-types/trace_values, effects-and-types/exp, 591)*/
  return kk_std_core_types__tuple3__box(_x817, _ctx);
}


// lift anonymous function
struct kk_rmsmc_rmsmc__loop_fun819__t {
  struct kk_function_s _base;
  kk_function_t finalize__func;
};
static kk_box_t kk_rmsmc_rmsmc__loop_fun819(kk_function_t _fself, kk_box_t _b_749, kk_context_t* _ctx);
static kk_function_t kk_rmsmc_new_rmsmc__loop_fun819(kk_function_t finalize__func, kk_context_t* _ctx) {
  struct kk_rmsmc_rmsmc__loop_fun819__t* _self = kk_function_alloc_as(struct kk_rmsmc_rmsmc__loop_fun819__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_rmsmc_rmsmc__loop_fun819, kk_context());
  _self->finalize__func = finalize__func;
  return &_self->_base;
}

static kk_box_t kk_rmsmc_rmsmc__loop_fun819(kk_function_t _fself, kk_box_t _b_749, kk_context_t* _ctx) {
  struct kk_rmsmc_rmsmc__loop_fun819__t* _self = kk_function_as(struct kk_rmsmc_rmsmc__loop_fun819__t*, _fself);
  kk_function_t finalize__func = _self->finalize__func; /* (wm : (effects-and-types/trace_values, effects-and-types/exp, (int) -> <effects-and-types/yield,effects-and-types/score,effects-and-types/sample,effects-and-types/sample,exn,div|594> 591)) -> <effects-and-types/sample,exn,div|594> (effects-and-types/trace_values, effects-and-types/exp, 591) */
  kk_drop_match(_self, {kk_function_dup(finalize__func);}, {}, _ctx)
  kk_std_core_types__tuple3_ _x820;
  kk_std_core_types__tuple3_ _x821 = kk_std_core_types__tuple3__unbox(_b_749, _ctx); /*(effects-and-types/trace_values, effects-and-types/exp, (int) -> <effects-and-types/yield,effects-and-types/score,effects-and-types/sample,effects-and-types/sample,exn,div|594> 591)*/
  _x820 = kk_function_call(kk_std_core_types__tuple3_, (kk_function_t, kk_std_core_types__tuple3_, kk_context_t*), finalize__func, (finalize__func, _x821, _ctx)); /*(effects-and-types/trace_values, effects-and-types/exp, 591)*/
  return kk_std_core_types__tuple3__box(_x820, _ctx);
}

kk_std_core__list kk_rmsmc_rmsmc__loop(kk_std_core__list populated__hist, kk_integer_t composition__10, kk_integer_t i0, kk_integer_t smc__step__num0, kk_integer_t mh__step__num0, kk_integer_t step__size0, bool normalize0, kk_context_t* _ctx) { /* forall<a,e> (populated_hist : effects-and-types/histogram_rmsmc<(int) -> <exn,effects-and-types/yield,effects-and-types/score,effects-and-types/sample,effects-and-types/sample,div|e> a>, composition_1 : int, i : int, smc_step_num : int, mh_step_num : int, step_size : int, normalize : bool) -> <pure,effects-and-types/sample|e> effects-and-types/histogram_rmsmc<a> */ 
  kk__tailcall: ;
  bool _match_771;
  kk_integer_t _x781 = kk_integer_dup(i0); /*int*/
  kk_integer_t _x782 = kk_integer_dup(smc__step__num0); /*int*/
  _match_771 = kk_integer_lt(_x781,_x782,kk_context()); /*bool*/
  if (_match_771) {
    kk_std_core__list x_668;
    kk_function_t _x783;
    kk_integer_dup(step__size0);
    _x783 = kk_rmsmc_new_rmsmc__loop_fun784(step__size0, _ctx); /*(1) -> 3 2*/
    x_668 = kk_std_core_map_5(populated__hist, _x783, _ctx); /*list<(effects-and-types/trace_values, effects-and-types/exp, (a : int) -> <effects-and-types/yield,effects-and-types/score,effects-and-types/sample,effects-and-types/sample,exn,div|594> 591)>*/
    if (kk_yielding(kk_context())) {
      kk_std_core__list_drop(x_668, _ctx);
      kk_box_t _x799 = kk_std_core_hnd_yield_extend(kk_rmsmc_new_rmsmc__loop_fun800(composition__10, i0, mh__step__num0, smc__step__num0, step__size0, normalize0, _ctx), _ctx); /*2*/
      return kk_std_core__list_unbox(_x799, _ctx);
    }
    if (normalize0) {
      { // tailcall
        kk_integer_t _x803 = kk_integer_add(i0,(kk_integer_from_small(1)),kk_context()); /*int*/
        populated__hist = x_668;
        i0 = _x803;
        goto kk__tailcall;
      }
    }
    { // tailcall
      kk_integer_t _x804 = kk_integer_add(i0,(kk_integer_from_small(1)),kk_context()); /*int*/
      populated__hist = x_668;
      i0 = _x804;
      goto kk__tailcall;
    }
  }
  kk_integer_drop(composition__10, _ctx);
  kk_integer_drop(i0, _ctx);
  kk_integer_drop(mh__step__num0, _ctx);
  kk_integer_drop(smc__step__num0, _ctx);
  kk_integer_drop(step__size0, _ctx);
  kk_function_t finalize__func = kk_rmsmc_new_rmsmc__loop_fun805(_ctx); /*(wm : (effects-and-types/trace_values, effects-and-types/exp, (int) -> <effects-and-types/yield,effects-and-types/score,effects-and-types/sample,effects-and-types/sample,exn,div|594> 591)) -> <effects-and-types/sample,exn,div|594> (effects-and-types/trace_values, effects-and-types/exp, 591)*/;
  if (normalize0) {
    return kk_std_core_map_5(populated__hist, kk_rmsmc_new_rmsmc__loop_fun816(finalize__func, _ctx), _ctx);
  }
  return kk_std_core_map_5(populated__hist, kk_rmsmc_new_rmsmc__loop_fun819(finalize__func, _ctx), _ctx);
}
 
// monadic lift

kk_std_core__list kk_rmsmc__mlift667_rmsmc(kk_integer_t mh__step__num, bool normalize, kk_integer_t smc__step__num, kk_integer_t step__size, kk_std_core__list pop, kk_context_t* _ctx) { /* forall<a,e> (mh_step_num : int, normalize : bool, smc_step_num : int, step_size : int, pop : effects-and-types/histogram_rmsmc<(a : int) -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,effects-and-types/sample,div,exn,std/num/random/random|e> a>) -> <effects-and-types/sample,div,exn,std/num/random/random|e> effects-and-types/histogram_rmsmc<a> */ 
  return kk_rmsmc_rmsmc__loop(pop, kk_integer_from_small(5), kk_integer_from_small(0), smc__step__num, mh__step__num, step__size, normalize, _ctx);
}


// lift anonymous function
struct kk_rmsmc_rmsmc_fun823__t {
  struct kk_function_s _base;
  kk_integer_t mh__step__num;
  kk_function_t model;
  kk_integer_t particle__num;
  kk_integer_t smc__step__num;
  kk_integer_t step__size;
  bool normalize;
};
static kk_box_t kk_rmsmc_rmsmc_fun823(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_rmsmc_new_rmsmc_fun823(kk_integer_t mh__step__num, kk_function_t model, kk_integer_t particle__num, kk_integer_t smc__step__num, kk_integer_t step__size, bool normalize, kk_context_t* _ctx) {
  struct kk_rmsmc_rmsmc_fun823__t* _self = kk_function_alloc_as(struct kk_rmsmc_rmsmc_fun823__t, 6, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_rmsmc_rmsmc_fun823, kk_context());
  _self->mh__step__num = mh__step__num;
  _self->model = model;
  _self->particle__num = particle__num;
  _self->smc__step__num = smc__step__num;
  _self->step__size = step__size;
  _self->normalize = normalize;
  return &_self->_base;
}



// lift anonymous function
struct kk_rmsmc_rmsmc_fun825__t {
  struct kk_function_s _base;
  kk_function_t model;
};
static kk_box_t kk_rmsmc_rmsmc_fun825(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_rmsmc_new_rmsmc_fun825(kk_function_t model, kk_context_t* _ctx) {
  struct kk_rmsmc_rmsmc_fun825__t* _self = kk_function_alloc_as(struct kk_rmsmc_rmsmc_fun825__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_rmsmc_rmsmc_fun825, kk_context());
  _self->model = model;
  return &_self->_base;
}



// lift anonymous function
struct kk_rmsmc_rmsmc_fun827__t {
  struct kk_function_s _base;
  kk_function_t model;
};
static kk_box_t kk_rmsmc_rmsmc_fun827(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_rmsmc_new_rmsmc_fun827(kk_function_t model, kk_context_t* _ctx) {
  struct kk_rmsmc_rmsmc_fun827__t* _self = kk_function_alloc_as(struct kk_rmsmc_rmsmc_fun827__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_rmsmc_rmsmc_fun827, kk_context());
  _self->model = model;
  return &_self->_base;
}

static kk_box_t kk_rmsmc_rmsmc_fun827(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_rmsmc_rmsmc_fun827__t* _self = kk_function_as(struct kk_rmsmc_rmsmc_fun827__t*, _fself);
  kk_function_t model = _self->model; /* () -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,effects-and-types/sample,div,exn,std/num/random/random|657> 25 */
  kk_drop_match(_self, {kk_function_dup(model);}, {}, _ctx)
  return kk_handlers_yield__on__score(model, _ctx);
}


// lift anonymous function
struct kk_rmsmc_rmsmc_fun828__t {
  struct kk_function_s _base;
  kk_function_t _bv_760;
};
static kk_box_t kk_rmsmc_rmsmc_fun828(kk_function_t _fself, kk_box_t _b_761, kk_context_t* _ctx);
static kk_function_t kk_rmsmc_new_rmsmc_fun828(kk_function_t _bv_760, kk_context_t* _ctx) {
  struct kk_rmsmc_rmsmc_fun828__t* _self = kk_function_alloc_as(struct kk_rmsmc_rmsmc_fun828__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_rmsmc_rmsmc_fun828, kk_context());
  _self->_bv_760 = _bv_760;
  return &_self->_base;
}

static kk_box_t kk_rmsmc_rmsmc_fun828(kk_function_t _fself, kk_box_t _b_761, kk_context_t* _ctx) {
  struct kk_rmsmc_rmsmc_fun828__t* _self = kk_function_as(struct kk_rmsmc_rmsmc_fun828__t*, _fself);
  kk_function_t _bv_760 = _self->_bv_760; /* (a : int) -> <effects-and-types/yield,effects-and-types/sample,effects-and-types/score,effects-and-types/sample,div,exn,std/num/random/random|657> 25 */
  kk_drop_match(_self, {kk_function_dup(_bv_760);}, {}, _ctx)
  kk_integer_t _x829 = kk_integer_unbox(_b_761); /*int*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_context_t*), _bv_760, (_bv_760, _x829, _ctx));
}
static kk_box_t kk_rmsmc_rmsmc_fun825(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_rmsmc_rmsmc_fun825__t* _self = kk_function_as(struct kk_rmsmc_rmsmc_fun825__t*, _fself);
  kk_function_t model = _self->model; /* () -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,effects-and-types/sample,div,exn,std/num/random/random|657> 25 */
  kk_drop_match(_self, {kk_function_dup(model);}, {}, _ctx)
  kk_function_t _x826;
  kk_function_t _bv_760 = kk_handlers_advance(kk_rmsmc_new_rmsmc_fun827(model, _ctx), _ctx); /*(a : int) -> <effects-and-types/yield,effects-and-types/sample,effects-and-types/score,effects-and-types/sample,div,exn,std/num/random/random|657> 25*/;
  _x826 = kk_rmsmc_new_rmsmc_fun828(_bv_760, _ctx); /*(758) -> <effects-and-types/yield,effects-and-types/sample,effects-and-types/score,effects-and-types/sample,div,exn,std/num/random/random|657> 25*/
  return kk_function_box(_x826);
}


// lift anonymous function
struct kk_rmsmc_rmsmc_fun831__t {
  struct kk_function_s _base;
  kk_integer_t mh__step__num;
  kk_integer_t smc__step__num;
  kk_integer_t step__size;
  bool normalize;
};
static kk_box_t kk_rmsmc_rmsmc_fun831(kk_function_t _fself, kk_box_t _b_765, kk_context_t* _ctx);
static kk_function_t kk_rmsmc_new_rmsmc_fun831(kk_integer_t mh__step__num, kk_integer_t smc__step__num, kk_integer_t step__size, bool normalize, kk_context_t* _ctx) {
  struct kk_rmsmc_rmsmc_fun831__t* _self = kk_function_alloc_as(struct kk_rmsmc_rmsmc_fun831__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_rmsmc_rmsmc_fun831, kk_context());
  _self->mh__step__num = mh__step__num;
  _self->smc__step__num = smc__step__num;
  _self->step__size = step__size;
  _self->normalize = normalize;
  return &_self->_base;
}

static kk_box_t kk_rmsmc_rmsmc_fun831(kk_function_t _fself, kk_box_t _b_765, kk_context_t* _ctx) {
  struct kk_rmsmc_rmsmc_fun831__t* _self = kk_function_as(struct kk_rmsmc_rmsmc_fun831__t*, _fself);
  kk_integer_t mh__step__num = _self->mh__step__num; /* int */
  kk_integer_t smc__step__num = _self->smc__step__num; /* int */
  kk_integer_t step__size = _self->step__size; /* int */
  bool normalize = _self->normalize; /* bool */
  kk_drop_match(_self, {kk_integer_dup(mh__step__num);kk_integer_dup(smc__step__num);kk_integer_dup(step__size);;}, {}, _ctx)
  kk_std_core__list _x832;
  kk_std_core__list _x833 = kk_std_core__list_unbox(_b_765, _ctx); /*effects-and-types/histogram_rmsmc<(a : int) -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,effects-and-types/sample,div,exn,std/num/random/random|657> 25>*/
  _x832 = kk_rmsmc__mlift667_rmsmc(mh__step__num, normalize, smc__step__num, step__size, _x833, _ctx); /*effects-and-types/histogram_rmsmc<25>*/
  return kk_std_core__list_box(_x832, _ctx);
}
static kk_box_t kk_rmsmc_rmsmc_fun823(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_rmsmc_rmsmc_fun823__t* _self = kk_function_as(struct kk_rmsmc_rmsmc_fun823__t*, _fself);
  kk_integer_t mh__step__num = _self->mh__step__num; /* int */
  kk_function_t model = _self->model; /* () -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,effects-and-types/sample,div,exn,std/num/random/random|657> 25 */
  kk_integer_t particle__num = _self->particle__num; /* int */
  kk_integer_t smc__step__num = _self->smc__step__num; /* int */
  kk_integer_t step__size = _self->step__size; /* int */
  bool normalize = _self->normalize; /* bool */
  kk_drop_match(_self, {kk_integer_dup(mh__step__num);kk_function_dup(model);kk_integer_dup(particle__num);kk_integer_dup(smc__step__num);kk_integer_dup(step__size);;}, {}, _ctx)
  kk_std_core__list _x824;
  kk_std_core__list x_675 = kk_sampling_dash_rmsmc_populate(particle__num, kk_rmsmc_new_rmsmc_fun825(model, _ctx), _ctx); /*effects-and-types/histogram_rmsmc<(a : int) -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,effects-and-types/sample,div,exn,std/num/random/random|657> 25>*/;
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_675, _ctx);
    kk_box_t _x830 = kk_std_core_hnd_yield_extend(kk_rmsmc_new_rmsmc_fun831(mh__step__num, smc__step__num, step__size, normalize, _ctx), _ctx); /*2*/
    _x824 = kk_std_core__list_unbox(_x830, _ctx); /*effects-and-types/histogram_rmsmc<25>*/
  }
  else {
    _x824 = kk_rmsmc__mlift667_rmsmc(mh__step__num, normalize, smc__step__num, step__size, x_675, _ctx); /*effects-and-types/histogram_rmsmc<25>*/
  }
  return kk_std_core__list_box(_x824, _ctx);
}

kk_std_core__list kk_rmsmc_rmsmc(kk_integer_t particle__num, kk_integer_t smc__step__num, kk_integer_t mh__step__num, kk_integer_t step__size, kk_function_t model, bool normalize, kk_context_t* _ctx) { /* forall<a,e> (particle_num : int, smc_step_num : int, mh_step_num : int, step_size : int, model : () -> <pure,std/num/random/random,effects-and-types/sample,effects-and-types/sample,effects-and-types/score,effects-and-types/yield|e> a, normalize : bool) -> <pure,std/num/random/random|e> effects-and-types/histogram_rmsmc<a> */ 
  kk_box_t _x822 = kk_handlers_random__sampler(kk_rmsmc_new_rmsmc_fun823(mh__step__num, model, particle__num, smc__step__num, step__size, normalize, _ctx), _ctx); /*0*/
  return kk_std_core__list_unbox(_x822, _ctx);
}

// initialization
void kk_rmsmc__init(kk_context_t* _ctx){
  static bool _initialized = false;
  if (_initialized) return;
  _initialized = true;
  kk_std_core_types__init(_ctx);
  kk_std_core_hnd__init(_ctx);
  kk_std_core__init(_ctx);
  kk_std_num_random__init(_ctx);
  kk_effects_dash_and_dash_types__init(_ctx);
  kk_handlers__init(_ctx);
  kk_sampling_dash_rmsmc__init(_ctx);
}
