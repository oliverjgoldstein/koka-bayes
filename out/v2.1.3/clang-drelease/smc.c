// Koka generated module: "smc", koka version: 2.1.3
#include "smc.h"
 
// monadic lift

kk_std_core__list kk_smc__mlift509_smc_steps(kk_function_t norm, kk_std_core__list _y_4, kk_context_t* _ctx) { /* forall<a,e> (norm : forall<b> (effects-and-types/histogram<b>) -> effects-and-types/histogram<b>, list<(effects-and-types/exp, a)>) -> <exn,effects-and-types/sample,div|e> effects-and-types/histogram<a> */ 
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*std/core/hnd/evv<(<>)>*/;
  kk_std_core__list x = kk_function_call(kk_std_core__list, (kk_function_t, kk_std_core__list, kk_context_t*), norm, (norm, _y_4, _ctx)); /*effects-and-types/histogram<417>*/;
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  return x;
}
 
// monadic lift

kk_std_core__list kk_smc__mlift510_smc_steps(kk_function_t norm0, kk_integer_t step_size, kk_integer_t steps, kk_std_core__list _y_10, kk_context_t* _ctx) { /* forall<a,e> (norm : forall<b> (effects-and-types/histogram<b>) -> effects-and-types/histogram<b>, step-size : int, steps : int, list<(effects-and-types/exp, (steps : int) -> <effects-and-types/yield,effects-and-types/score,exn,effects-and-types/sample,div|e> a)>) -> <exn,effects-and-types/sample,div|e> effects-and-types/histogram<a> */ 
  kk_integer_t _x664 = kk_integer_sub(steps,(kk_integer_from_small(1)),kk_context()); /*int*/
  kk_std_core__list _x665;
  kk_evv_t w0 = kk_evv_swap_create0(kk_context()); /*std/core/hnd/evv<(<>)>*/;
  kk_std_core__list x0;
  kk_function_t _x666 = kk_function_dup(norm0); /*forall<a> (effects-and-types/histogram<a>) -> effects-and-types/histogram<a>*/
  x0 = kk_function_call(kk_std_core__list, (kk_function_t, kk_std_core__list, kk_context_t*), _x666, (_x666, _y_10, _ctx)); /*effects-and-types/histogram<(steps : int) -> <effects-and-types/yield,effects-and-types/score,exn,effects-and-types/sample,div|420> 417>*/
  kk_unit_t keep0 = kk_Unit;
  kk_evv_set(w0,kk_context());
  _x665 = x0; /*effects-and-types/histogram<(steps : int) -> <effects-and-types/yield,effects-and-types/score,exn,effects-and-types/sample,div|420> 417>*/
  return kk_smc_smc_steps(_x664, step_size, _x665, norm0, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_smc__mlift511_smc_steps_fun668__t {
  struct kk_function_s _base;
  kk_integer_t step_size0;
};
static kk_box_t kk_smc__mlift511_smc_steps_fun668(kk_function_t _fself, kk_box_t _b_558, kk_context_t* _ctx);
static kk_function_t kk_smc__new_mlift511_smc_steps_fun668(kk_integer_t step_size0, kk_context_t* _ctx) {
  struct kk_smc__mlift511_smc_steps_fun668__t* _self = kk_function_alloc_as(struct kk_smc__mlift511_smc_steps_fun668__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_smc__mlift511_smc_steps_fun668, kk_context());
  _self->step_size0 = step_size0;
  return &_self->_base;
}



// lift anonymous function
struct kk_smc__mlift511_smc_steps_fun671__t {
  struct kk_function_s _base;
  kk_box_t _fun_unbox_x546;
  kk_integer_t step_size0;
};
static kk_box_t kk_smc__mlift511_smc_steps_fun671(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_smc__new_mlift511_smc_steps_fun671(kk_box_t _fun_unbox_x546, kk_integer_t step_size0, kk_context_t* _ctx) {
  struct kk_smc__mlift511_smc_steps_fun671__t* _self = kk_function_alloc_as(struct kk_smc__mlift511_smc_steps_fun671__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_smc__mlift511_smc_steps_fun671, kk_context());
  _self->_fun_unbox_x546 = _fun_unbox_x546;
  _self->step_size0 = step_size0;
  return &_self->_base;
}



// lift anonymous function
struct kk_smc__mlift511_smc_steps_fun673__t {
  struct kk_function_s _base;
  kk_box_t _fun_unbox_x546;
  kk_integer_t step_size0;
};
static kk_box_t kk_smc__mlift511_smc_steps_fun673(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_smc__new_mlift511_smc_steps_fun673(kk_box_t _fun_unbox_x546, kk_integer_t step_size0, kk_context_t* _ctx) {
  struct kk_smc__mlift511_smc_steps_fun673__t* _self = kk_function_alloc_as(struct kk_smc__mlift511_smc_steps_fun673__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_smc__mlift511_smc_steps_fun673, kk_context());
  _self->_fun_unbox_x546 = _fun_unbox_x546;
  _self->step_size0 = step_size0;
  return &_self->_base;
}

static kk_box_t kk_smc__mlift511_smc_steps_fun673(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_smc__mlift511_smc_steps_fun673__t* _self = kk_function_as(struct kk_smc__mlift511_smc_steps_fun673__t*, _fself);
  kk_box_t _fun_unbox_x546 = _self->_fun_unbox_x546; /* 7 */
  kk_integer_t step_size0 = _self->step_size0; /* int */
  kk_drop_match(_self, {kk_box_dup(_fun_unbox_x546);kk_integer_dup(step_size0);}, {}, _ctx)
  kk_function_t _x674 = kk_function_unbox(_fun_unbox_x546); /*(547) -> <effects-and-types/yield,effects-and-types/score,exn,effects-and-types/sample,div|420> 548*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x674, (_x674, kk_integer_box(step_size0), _ctx));
}


// lift anonymous function
struct kk_smc__mlift511_smc_steps_fun675__t {
  struct kk_function_s _base;
  kk_function_t _bv_554;
};
static kk_box_t kk_smc__mlift511_smc_steps_fun675(kk_function_t _fself, kk_box_t _b_555, kk_context_t* _ctx);
static kk_function_t kk_smc__new_mlift511_smc_steps_fun675(kk_function_t _bv_554, kk_context_t* _ctx) {
  struct kk_smc__mlift511_smc_steps_fun675__t* _self = kk_function_alloc_as(struct kk_smc__mlift511_smc_steps_fun675__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_smc__mlift511_smc_steps_fun675, kk_context());
  _self->_bv_554 = _bv_554;
  return &_self->_base;
}

static kk_box_t kk_smc__mlift511_smc_steps_fun675(kk_function_t _fself, kk_box_t _b_555, kk_context_t* _ctx) {
  struct kk_smc__mlift511_smc_steps_fun675__t* _self = kk_function_as(struct kk_smc__mlift511_smc_steps_fun675__t*, _fself);
  kk_function_t _bv_554 = _self->_bv_554; /* (steps : int) -> <effects-and-types/yield,effects-and-types/score,exn,effects-and-types/sample,div|420> 417 */
  kk_drop_match(_self, {kk_function_dup(_bv_554);}, {}, _ctx)
  kk_integer_t _x676 = kk_integer_unbox(_b_555); /*int*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_context_t*), _bv_554, (_bv_554, _x676, _ctx));
}
static kk_box_t kk_smc__mlift511_smc_steps_fun671(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_smc__mlift511_smc_steps_fun671__t* _self = kk_function_as(struct kk_smc__mlift511_smc_steps_fun671__t*, _fself);
  kk_box_t _fun_unbox_x546 = _self->_fun_unbox_x546; /* 7 */
  kk_integer_t step_size0 = _self->step_size0; /* int */
  kk_drop_match(_self, {kk_box_dup(_fun_unbox_x546);kk_integer_dup(step_size0);}, {}, _ctx)
  kk_function_t _x672;
  kk_function_t _bv_554 = kk_handlers_advance(kk_smc__new_mlift511_smc_steps_fun673(_fun_unbox_x546, step_size0, _ctx), _ctx); /*(steps : int) -> <effects-and-types/yield,effects-and-types/score,exn,effects-and-types/sample,div|420> 417*/;
  _x672 = kk_smc__new_mlift511_smc_steps_fun675(_bv_554, _ctx); /*(552) -> <effects-and-types/yield,effects-and-types/score,exn,effects-and-types/sample,div|420> 417*/
  return kk_function_box(_x672);
}
static kk_box_t kk_smc__mlift511_smc_steps_fun668(kk_function_t _fself, kk_box_t _b_558, kk_context_t* _ctx) {
  struct kk_smc__mlift511_smc_steps_fun668__t* _self = kk_function_as(struct kk_smc__mlift511_smc_steps_fun668__t*, _fself);
  kk_integer_t step_size0 = _self->step_size0; /* int */
  kk_drop_match(_self, {kk_integer_dup(step_size0);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x669;
  kk_std_core_types__tuple2_ _match_663 = kk_std_core_types__tuple2__unbox(_b_558, _ctx); /*(effects-and-types/exp, (int) -> <effects-and-types/yield,effects-and-types/score,exn,effects-and-types/sample,div|420> 417)*/;
  kk_box_t _box_x542 = _match_663.fst;
  kk_box_t _fun_unbox_x546 = _match_663.snd;
  kk_effects_dash_and_dash_types__exp w00 = kk_effects_dash_and_dash_types__exp_unbox(_box_x542, NULL);
  kk_box_dup(_fun_unbox_x546);
  kk_std_core_types__tuple2__drop(_match_663, _ctx);
  _x669 = kk_handlers_weighted(w00, kk_smc__new_mlift511_smc_steps_fun671(_fun_unbox_x546, step_size0, _ctx), _ctx); /*(effects-and-types/exp, 2370)*/
  return kk_std_core_types__tuple2__box(_x669, _ctx);
}


// lift anonymous function
struct kk_smc__mlift511_smc_steps_fun678__t {
  struct kk_function_s _base;
  kk_function_t norm1;
  kk_integer_t step_size0;
  kk_integer_t steps0;
};
static kk_box_t kk_smc__mlift511_smc_steps_fun678(kk_function_t _fself, kk_box_t _b_566, kk_context_t* _ctx);
static kk_function_t kk_smc__new_mlift511_smc_steps_fun678(kk_function_t norm1, kk_integer_t step_size0, kk_integer_t steps0, kk_context_t* _ctx) {
  struct kk_smc__mlift511_smc_steps_fun678__t* _self = kk_function_alloc_as(struct kk_smc__mlift511_smc_steps_fun678__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_smc__mlift511_smc_steps_fun678, kk_context());
  _self->norm1 = norm1;
  _self->step_size0 = step_size0;
  _self->steps0 = steps0;
  return &_self->_base;
}

static kk_box_t kk_smc__mlift511_smc_steps_fun678(kk_function_t _fself, kk_box_t _b_566, kk_context_t* _ctx) {
  struct kk_smc__mlift511_smc_steps_fun678__t* _self = kk_function_as(struct kk_smc__mlift511_smc_steps_fun678__t*, _fself);
  kk_function_t norm1 = _self->norm1; /* forall<a> (effects-and-types/histogram<a>) -> effects-and-types/histogram<a> */
  kk_integer_t step_size0 = _self->step_size0; /* int */
  kk_integer_t steps0 = _self->steps0; /* int */
  kk_drop_match(_self, {kk_function_dup(norm1);kk_integer_dup(step_size0);kk_integer_dup(steps0);}, {}, _ctx)
  kk_std_core__list _x679;
  kk_std_core__list _x680 = kk_std_core__list_unbox(_b_566, _ctx); /*list<(effects-and-types/exp, (steps : int) -> <effects-and-types/yield,effects-and-types/score,exn,effects-and-types/sample,div|420> 417)>*/
  _x679 = kk_smc__mlift510_smc_steps(norm1, step_size0, steps0, _x680, _ctx); /*effects-and-types/histogram<417>*/
  return kk_std_core__list_box(_x679, _ctx);
}

kk_std_core__list kk_smc__mlift511_smc_steps(kk_function_t norm1, kk_integer_t step_size0, kk_integer_t steps0, kk_std_core__list pop_resampled, kk_context_t* _ctx) { /* forall<a,e> (norm : forall<b> (effects-and-types/histogram<b>) -> effects-and-types/histogram<b>, step-size : int, steps : int, pop-resampled : effects-and-types/histogram<(int) -> <exn,effects-and-types/yield,effects-and-types/score,effects-and-types/sample,div|e> a>) -> <exn,effects-and-types/sample,div|e> effects-and-types/histogram<a> */ 
  kk_std_core__list x_517;
  kk_function_t _x667;
  kk_integer_dup(step_size0);
  _x667 = kk_smc__new_mlift511_smc_steps_fun668(step_size0, _ctx); /*(7319) -> 7321 7320*/
  x_517 = kk_std_core_map_5(pop_resampled, _x667, _ctx); /*list<(effects-and-types/exp, (steps : int) -> <effects-and-types/yield,effects-and-types/score,exn,effects-and-types/sample,div|420> 417)>*/
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_517, _ctx);
    kk_box_t _x677 = kk_std_core_hnd_yield_extend(kk_smc__new_mlift511_smc_steps_fun678(norm1, step_size0, steps0, _ctx), _ctx); /*3991*/
    return kk_std_core__list_unbox(_x677, _ctx);
  }
  return kk_smc__mlift510_smc_steps(norm1, step_size0, steps0, x_517, _ctx);
}


// lift anonymous function
struct kk_smc_smc_steps_fun682__t {
  struct kk_function_s _base;
};
static kk_box_t kk_smc_smc_steps_fun682(kk_function_t _fself, kk_box_t _b_582, kk_context_t* _ctx);
static kk_function_t kk_smc_new_smc_steps_fun682(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_smc_smc_steps_fun682, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_smc_smc_steps_fun685__t {
  struct kk_function_s _base;
  kk_box_t _fun_unbox_x573;
};
static kk_box_t kk_smc_smc_steps_fun685(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_smc_new_smc_steps_fun685(kk_box_t _fun_unbox_x573, kk_context_t* _ctx) {
  struct kk_smc_smc_steps_fun685__t* _self = kk_function_alloc_as(struct kk_smc_smc_steps_fun685__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_smc_smc_steps_fun685, kk_context());
  _self->_fun_unbox_x573 = _fun_unbox_x573;
  return &_self->_base;
}



// lift anonymous function
struct kk_smc_smc_steps_fun688__t {
  struct kk_function_s _base;
};
static kk_box_t kk_smc_smc_steps_fun688(kk_function_t _fself, kk_std_core_hnd__marker _b_578, kk_std_core_hnd__ev _b_579, kk_context_t* _ctx);
static kk_function_t kk_smc_new_smc_steps_fun688(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_smc_smc_steps_fun688, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_smc_smc_steps_fun688(kk_function_t _fself, kk_std_core_hnd__marker _b_578, kk_std_core_hnd__ev _b_579, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core_hnd__ev_dropn(_b_579, ((int32_t)3), _ctx);
  return kk_unit_box(kk_Unit);
}


// lift anonymous function
struct kk_smc_smc_steps_fun689__t {
  struct kk_function_s _base;
};
static kk_box_t kk_smc_smc_steps_fun689(kk_function_t _fself, kk_box_t _x, kk_context_t* _ctx);
static kk_function_t kk_smc_new_smc_steps_fun689(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_smc_smc_steps_fun689, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_smc_smc_steps_fun689(kk_function_t _fself, kk_box_t _x, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return _x;
}


// lift anonymous function
struct kk_smc_smc_steps_fun690__t {
  struct kk_function_s _base;
  kk_box_t _fun_unbox_x573;
};
static kk_box_t kk_smc_smc_steps_fun690(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_smc_new_smc_steps_fun690(kk_box_t _fun_unbox_x573, kk_context_t* _ctx) {
  struct kk_smc_smc_steps_fun690__t* _self = kk_function_alloc_as(struct kk_smc_smc_steps_fun690__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_smc_smc_steps_fun690, kk_context());
  _self->_fun_unbox_x573 = _fun_unbox_x573;
  return &_self->_base;
}

static kk_box_t kk_smc_smc_steps_fun690(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_smc_smc_steps_fun690__t* _self = kk_function_as(struct kk_smc_smc_steps_fun690__t*, _fself);
  kk_box_t _fun_unbox_x573 = _self->_fun_unbox_x573; /* 7 */
  kk_drop_match(_self, {kk_box_dup(_fun_unbox_x573);}, {}, _ctx)
  kk_function_t _x691 = kk_function_unbox(_fun_unbox_x573); /*(574) -> <effects-and-types/yield,effects-and-types/score,exn,effects-and-types/sample,div|420> 575*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x691, (_x691, kk_integer_box(kk_integer_from_small(0)), _ctx));
}
static kk_box_t kk_smc_smc_steps_fun685(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_smc_smc_steps_fun685__t* _self = kk_function_as(struct kk_smc_smc_steps_fun685__t*, _fself);
  kk_box_t _fun_unbox_x573 = _self->_fun_unbox_x573; /* 7 */
  kk_drop_match(_self, {kk_box_dup(_fun_unbox_x573);}, {}, _ctx)
  kk_effects_dash_and_dash_types__hnd_yield _x686;
  kk_std_core_hnd__clause0 _x687 = kk_std_core_hnd__new_Clause0(kk_smc_new_smc_steps_fun688(_ctx), _ctx); /*std/core/hnd/clause0<37,38,39,40>*/
  _x686 = kk_effects_dash_and_dash_types__new_Hnd_yield(kk_reuse_null, _x687, _ctx); /*effects-and-types/.hnd-yield<25,26>*/
  return kk_effects_dash_and_dash_types__handle_yield(((int32_t)1), _x686, kk_smc_new_smc_steps_fun689(_ctx), kk_smc_new_smc_steps_fun690(_fun_unbox_x573, _ctx), _ctx);
}
static kk_box_t kk_smc_smc_steps_fun682(kk_function_t _fself, kk_box_t _b_582, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core_types__tuple2_ _x683;
  kk_std_core_types__tuple2_ _match_661 = kk_std_core_types__tuple2__unbox(_b_582, _ctx); /*(effects-and-types/exp, (int) -> <effects-and-types/yield,effects-and-types/score,exn,effects-and-types/sample,div|420> 417)*/;
  kk_box_t _box_x569 = _match_661.fst;
  kk_box_t _fun_unbox_x573 = _match_661.snd;
  kk_effects_dash_and_dash_types__exp w1 = kk_effects_dash_and_dash_types__exp_unbox(_box_x569, NULL);
  kk_box_dup(_fun_unbox_x573);
  kk_std_core_types__tuple2__drop(_match_661, _ctx);
  _x683 = kk_handlers_weighted(w1, kk_smc_new_smc_steps_fun685(_fun_unbox_x573, _ctx), _ctx); /*(effects-and-types/exp, 2370)*/
  return kk_std_core_types__tuple2__box(_x683, _ctx);
}


// lift anonymous function
struct kk_smc_smc_steps_fun693__t {
  struct kk_function_s _base;
  kk_function_t norm2;
};
static kk_box_t kk_smc_smc_steps_fun693(kk_function_t _fself, kk_box_t _b_591, kk_context_t* _ctx);
static kk_function_t kk_smc_new_smc_steps_fun693(kk_function_t norm2, kk_context_t* _ctx) {
  struct kk_smc_smc_steps_fun693__t* _self = kk_function_alloc_as(struct kk_smc_smc_steps_fun693__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_smc_smc_steps_fun693, kk_context());
  _self->norm2 = norm2;
  return &_self->_base;
}

static kk_box_t kk_smc_smc_steps_fun693(kk_function_t _fself, kk_box_t _b_591, kk_context_t* _ctx) {
  struct kk_smc_smc_steps_fun693__t* _self = kk_function_as(struct kk_smc_smc_steps_fun693__t*, _fself);
  kk_function_t norm2 = _self->norm2; /* forall<a> (effects-and-types/histogram<a>) -> effects-and-types/histogram<a> */
  kk_drop_match(_self, {kk_function_dup(norm2);}, {}, _ctx)
  kk_std_core__list _x694;
  kk_std_core__list _x695 = kk_std_core__list_unbox(_b_591, _ctx); /*list<(effects-and-types/exp, 417)>*/
  _x694 = kk_smc__mlift509_smc_steps(norm2, _x695, _ctx); /*effects-and-types/histogram<417>*/
  return kk_std_core__list_box(_x694, _ctx);
}


// lift anonymous function
struct kk_smc_smc_steps_fun700__t {
  struct kk_function_s _base;
};
static kk_box_t kk_smc_smc_steps_fun700(kk_function_t _fself, kk_box_t _b_599, kk_context_t* _ctx);
static kk_function_t kk_smc_new_smc_steps_fun700(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_smc_smc_steps_fun700, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_smc_smc_steps_fun700(kk_function_t _fself, kk_box_t _b_599, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core__list _x701;
  kk_std_core__list _x702 = kk_std_core__list_unbox(_b_599, _ctx); /*effects-and-types/histogram<(int) -> <exn,effects-and-types/yield,effects-and-types/score,effects-and-types/sample,div|420> 417>*/
  _x701 = kk_sampling_resample(_x702, _ctx); /*effects-and-types/histogram<811>*/
  return kk_std_core__list_box(_x701, _ctx);
}


// lift anonymous function
struct kk_smc_smc_steps_fun704__t {
  struct kk_function_s _base;
  kk_function_t norm2;
  kk_integer_t step_size1;
  kk_integer_t steps1;
};
static kk_box_t kk_smc_smc_steps_fun704(kk_function_t _fself, kk_box_t _b_608, kk_context_t* _ctx);
static kk_function_t kk_smc_new_smc_steps_fun704(kk_function_t norm2, kk_integer_t step_size1, kk_integer_t steps1, kk_context_t* _ctx) {
  struct kk_smc_smc_steps_fun704__t* _self = kk_function_alloc_as(struct kk_smc_smc_steps_fun704__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_smc_smc_steps_fun704, kk_context());
  _self->norm2 = norm2;
  _self->step_size1 = step_size1;
  _self->steps1 = steps1;
  return &_self->_base;
}

static kk_box_t kk_smc_smc_steps_fun704(kk_function_t _fself, kk_box_t _b_608, kk_context_t* _ctx) {
  struct kk_smc_smc_steps_fun704__t* _self = kk_function_as(struct kk_smc_smc_steps_fun704__t*, _fself);
  kk_function_t norm2 = _self->norm2; /* forall<a> (effects-and-types/histogram<a>) -> effects-and-types/histogram<a> */
  kk_integer_t step_size1 = _self->step_size1; /* int */
  kk_integer_t steps1 = _self->steps1; /* int */
  kk_drop_match(_self, {kk_function_dup(norm2);kk_integer_dup(step_size1);kk_integer_dup(steps1);}, {}, _ctx)
  kk_std_core__list _x705;
  kk_std_core__list _x706 = kk_std_core__list_unbox(_b_608, _ctx); /*effects-and-types/histogram<(int) -> <exn,effects-and-types/yield,effects-and-types/score,effects-and-types/sample,div|420> 417>*/
  _x705 = kk_smc__mlift511_smc_steps(norm2, step_size1, steps1, _x706, _ctx); /*effects-and-types/histogram<417>*/
  return kk_std_core__list_box(_x705, _ctx);
}


// lift anonymous function
struct kk_smc_smc_steps_fun708__t {
  struct kk_function_s _base;
  kk_integer_t step_size1;
};
static kk_box_t kk_smc_smc_steps_fun708(kk_function_t _fself, kk_box_t _b_625, kk_context_t* _ctx);
static kk_function_t kk_smc_new_smc_steps_fun708(kk_integer_t step_size1, kk_context_t* _ctx) {
  struct kk_smc_smc_steps_fun708__t* _self = kk_function_alloc_as(struct kk_smc_smc_steps_fun708__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_smc_smc_steps_fun708, kk_context());
  _self->step_size1 = step_size1;
  return &_self->_base;
}



// lift anonymous function
struct kk_smc_smc_steps_fun711__t {
  struct kk_function_s _base;
  kk_box_t _fun_unbox_x613;
  kk_integer_t step_size1;
};
static kk_box_t kk_smc_smc_steps_fun711(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_smc_new_smc_steps_fun711(kk_box_t _fun_unbox_x613, kk_integer_t step_size1, kk_context_t* _ctx) {
  struct kk_smc_smc_steps_fun711__t* _self = kk_function_alloc_as(struct kk_smc_smc_steps_fun711__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_smc_smc_steps_fun711, kk_context());
  _self->_fun_unbox_x613 = _fun_unbox_x613;
  _self->step_size1 = step_size1;
  return &_self->_base;
}



// lift anonymous function
struct kk_smc_smc_steps_fun713__t {
  struct kk_function_s _base;
  kk_box_t _fun_unbox_x613;
  kk_integer_t step_size1;
};
static kk_box_t kk_smc_smc_steps_fun713(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_smc_new_smc_steps_fun713(kk_box_t _fun_unbox_x613, kk_integer_t step_size1, kk_context_t* _ctx) {
  struct kk_smc_smc_steps_fun713__t* _self = kk_function_alloc_as(struct kk_smc_smc_steps_fun713__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_smc_smc_steps_fun713, kk_context());
  _self->_fun_unbox_x613 = _fun_unbox_x613;
  _self->step_size1 = step_size1;
  return &_self->_base;
}

static kk_box_t kk_smc_smc_steps_fun713(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_smc_smc_steps_fun713__t* _self = kk_function_as(struct kk_smc_smc_steps_fun713__t*, _fself);
  kk_box_t _fun_unbox_x613 = _self->_fun_unbox_x613; /* 7 */
  kk_integer_t step_size1 = _self->step_size1; /* int */
  kk_drop_match(_self, {kk_box_dup(_fun_unbox_x613);kk_integer_dup(step_size1);}, {}, _ctx)
  kk_function_t _x714 = kk_function_unbox(_fun_unbox_x613); /*(614) -> <effects-and-types/yield,effects-and-types/score,exn,effects-and-types/sample,div|420> 615*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x714, (_x714, kk_integer_box(step_size1), _ctx));
}


// lift anonymous function
struct kk_smc_smc_steps_fun715__t {
  struct kk_function_s _base;
  kk_function_t _bv_621;
};
static kk_box_t kk_smc_smc_steps_fun715(kk_function_t _fself, kk_box_t _b_622, kk_context_t* _ctx);
static kk_function_t kk_smc_new_smc_steps_fun715(kk_function_t _bv_621, kk_context_t* _ctx) {
  struct kk_smc_smc_steps_fun715__t* _self = kk_function_alloc_as(struct kk_smc_smc_steps_fun715__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_smc_smc_steps_fun715, kk_context());
  _self->_bv_621 = _bv_621;
  return &_self->_base;
}

static kk_box_t kk_smc_smc_steps_fun715(kk_function_t _fself, kk_box_t _b_622, kk_context_t* _ctx) {
  struct kk_smc_smc_steps_fun715__t* _self = kk_function_as(struct kk_smc_smc_steps_fun715__t*, _fself);
  kk_function_t _bv_621 = _self->_bv_621; /* (steps : int) -> <effects-and-types/yield,effects-and-types/score,exn,effects-and-types/sample,div|420> 417 */
  kk_drop_match(_self, {kk_function_dup(_bv_621);}, {}, _ctx)
  kk_integer_t _x716 = kk_integer_unbox(_b_622); /*int*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_context_t*), _bv_621, (_bv_621, _x716, _ctx));
}
static kk_box_t kk_smc_smc_steps_fun711(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_smc_smc_steps_fun711__t* _self = kk_function_as(struct kk_smc_smc_steps_fun711__t*, _fself);
  kk_box_t _fun_unbox_x613 = _self->_fun_unbox_x613; /* 7 */
  kk_integer_t step_size1 = _self->step_size1; /* int */
  kk_drop_match(_self, {kk_box_dup(_fun_unbox_x613);kk_integer_dup(step_size1);}, {}, _ctx)
  kk_function_t _x712;
  kk_function_t _bv_621 = kk_handlers_advance(kk_smc_new_smc_steps_fun713(_fun_unbox_x613, step_size1, _ctx), _ctx); /*(steps : int) -> <effects-and-types/yield,effects-and-types/score,exn,effects-and-types/sample,div|420> 417*/;
  _x712 = kk_smc_new_smc_steps_fun715(_bv_621, _ctx); /*(619) -> <effects-and-types/yield,effects-and-types/score,exn,effects-and-types/sample,div|420> 417*/
  return kk_function_box(_x712);
}
static kk_box_t kk_smc_smc_steps_fun708(kk_function_t _fself, kk_box_t _b_625, kk_context_t* _ctx) {
  struct kk_smc_smc_steps_fun708__t* _self = kk_function_as(struct kk_smc_smc_steps_fun708__t*, _fself);
  kk_integer_t step_size1 = _self->step_size1; /* int */
  kk_drop_match(_self, {kk_integer_dup(step_size1);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x709;
  kk_std_core_types__tuple2_ _match_659 = kk_std_core_types__tuple2__unbox(_b_625, _ctx); /*(effects-and-types/exp, (int) -> <effects-and-types/yield,effects-and-types/score,exn,effects-and-types/sample,div|420> 417)*/;
  kk_box_t _box_x609 = _match_659.fst;
  kk_box_t _fun_unbox_x613 = _match_659.snd;
  kk_effects_dash_and_dash_types__exp w000 = kk_effects_dash_and_dash_types__exp_unbox(_box_x609, NULL);
  kk_box_dup(_fun_unbox_x613);
  kk_std_core_types__tuple2__drop(_match_659, _ctx);
  _x709 = kk_handlers_weighted(w000, kk_smc_new_smc_steps_fun711(_fun_unbox_x613, step_size1, _ctx), _ctx); /*(effects-and-types/exp, 2370)*/
  return kk_std_core_types__tuple2__box(_x709, _ctx);
}


// lift anonymous function
struct kk_smc_smc_steps_fun718__t {
  struct kk_function_s _base;
  kk_function_t norm2;
  kk_integer_t step_size1;
  kk_integer_t steps1;
};
static kk_box_t kk_smc_smc_steps_fun718(kk_function_t _fself, kk_box_t _b_633, kk_context_t* _ctx);
static kk_function_t kk_smc_new_smc_steps_fun718(kk_function_t norm2, kk_integer_t step_size1, kk_integer_t steps1, kk_context_t* _ctx) {
  struct kk_smc_smc_steps_fun718__t* _self = kk_function_alloc_as(struct kk_smc_smc_steps_fun718__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_smc_smc_steps_fun718, kk_context());
  _self->norm2 = norm2;
  _self->step_size1 = step_size1;
  _self->steps1 = steps1;
  return &_self->_base;
}

static kk_box_t kk_smc_smc_steps_fun718(kk_function_t _fself, kk_box_t _b_633, kk_context_t* _ctx) {
  struct kk_smc_smc_steps_fun718__t* _self = kk_function_as(struct kk_smc_smc_steps_fun718__t*, _fself);
  kk_function_t norm2 = _self->norm2; /* forall<a> (effects-and-types/histogram<a>) -> effects-and-types/histogram<a> */
  kk_integer_t step_size1 = _self->step_size1; /* int */
  kk_integer_t steps1 = _self->steps1; /* int */
  kk_drop_match(_self, {kk_function_dup(norm2);kk_integer_dup(step_size1);kk_integer_dup(steps1);}, {}, _ctx)
  kk_std_core__list _x719;
  kk_std_core__list _x720 = kk_std_core__list_unbox(_b_633, _ctx); /*list<(effects-and-types/exp, (steps : int) -> <effects-and-types/yield,effects-and-types/score,exn,effects-and-types/sample,div|420> 417)>*/
  _x719 = kk_smc__mlift510_smc_steps(norm2, step_size1, steps1, _x720, _ctx); /*effects-and-types/histogram<417>*/
  return kk_std_core__list_box(_x719, _ctx);
}

kk_std_core__list kk_smc_smc_steps(kk_integer_t steps1, kk_integer_t step_size1, kk_std_core__list pop_hist, kk_function_t norm2, kk_context_t* _ctx) { /* forall<a,e> (steps : int, step-size : int, pop-hist : effects-and-types/histogram<(int) -> <exn,effects-and-types/yield,effects-and-types/score,effects-and-types/sample,div|e> a>, norm : forall<b> (effects-and-types/histogram<b>) -> effects-and-types/histogram<b>) -> <pure,effects-and-types/sample|e> effects-and-types/histogram<a> */ 
  kk__tailcall: ;
  bool _match_656;
  kk_integer_t _x681 = kk_integer_dup(steps1); /*int*/
  _match_656 = kk_integer_lte(_x681,(kk_integer_from_small(0)),kk_context()); /*bool*/
  if (_match_656) {
    kk_integer_drop(step_size1, _ctx);
    kk_integer_drop(steps1, _ctx);
    kk_std_core__list x_519 = kk_std_core_map_5(pop_hist, kk_smc_new_smc_steps_fun682(_ctx), _ctx); /*list<(effects-and-types/exp, 417)>*/;
    if (kk_yielding(kk_context())) {
      kk_std_core__list_drop(x_519, _ctx);
      kk_box_t _x692 = kk_std_core_hnd_yield_extend(kk_smc_new_smc_steps_fun693(norm2, _ctx), _ctx); /*3991*/
      return kk_std_core__list_unbox(_x692, _ctx);
    }
    kk_evv_t w01 = kk_evv_swap_create0(kk_context()); /*std/core/hnd/evv<(<>)>*/;
    kk_std_core__list x00 = kk_function_call(kk_std_core__list, (kk_function_t, kk_std_core__list, kk_context_t*), norm2, (norm2, x_519, _ctx)); /*effects-and-types/histogram<417>*/;
    kk_unit_t keep1 = kk_Unit;
    kk_evv_set(w01,kk_context());
    return x00;
  }
  kk_std_core__list x2_526;
  kk_vector_t _b_600_596;
  kk_std_core__list _x696;
  size_t _b_603_594;
  kk_std_core_hnd__htag _x697 = kk_std_core_hnd__htag_dup(kk_std_core__tag_exn); /*std/core/hnd/htag<.hnd-exn>*/
  _b_603_594 = kk_std_core_hnd__evv_index(_x697, _ctx); /*std/core/hnd/ev-index*/
  kk_std_core__list _b_604_595;
  size_t _b_605_592;
  kk_std_core_hnd__htag _x698 = kk_std_core_hnd__htag_dup(kk_effects_dash_and_dash_types__tag_sample); /*std/core/hnd/htag<effects-and-types/.hnd-sample>*/
  _b_605_592 = kk_std_core_hnd__evv_index(_x698, _ctx); /*std/core/hnd/ev-index*/
  _b_604_595 = kk_std_core__new_Cons(kk_reuse_null, kk_size_box(_b_605_592, _ctx), kk_std_core__new_Nil(_ctx), _ctx); /*list<std/core/hnd/ev-index>*/
  _x696 = kk_std_core__new_Cons(kk_reuse_null, kk_size_box(_b_603_594, _ctx), _b_604_595, _ctx); /*list<0>*/
  _b_600_596 = kk_std_core_unvlist(_x696, _ctx); /*vector<std/core/hnd/ev-index>*/
  kk_box_t _x699 = kk_std_core_hnd__open1(_b_600_596, kk_smc_new_smc_steps_fun700(_ctx), kk_std_core__list_box(pop_hist, _ctx), _ctx); /*5748*/
  x2_526 = kk_std_core__list_unbox(_x699, _ctx); /*effects-and-types/histogram<(int) -> <exn,effects-and-types/yield,effects-and-types/score,effects-and-types/sample,div|420> 417>*/
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x2_526, _ctx);
    kk_box_t _x703 = kk_std_core_hnd_yield_extend(kk_smc_new_smc_steps_fun704(norm2, step_size1, steps1, _ctx), _ctx); /*3991*/
    return kk_std_core__list_unbox(_x703, _ctx);
  }
  kk_std_core__list x3_530;
  kk_function_t _x707;
  kk_integer_dup(step_size1);
  _x707 = kk_smc_new_smc_steps_fun708(step_size1, _ctx); /*(7319) -> 7321 7320*/
  x3_530 = kk_std_core_map_5(x2_526, _x707, _ctx); /*list<(effects-and-types/exp, (steps : int) -> <effects-and-types/yield,effects-and-types/score,exn,effects-and-types/sample,div|420> 417)>*/
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x3_530, _ctx);
    kk_box_t _x717 = kk_std_core_hnd_yield_extend(kk_smc_new_smc_steps_fun718(norm2, step_size1, steps1, _ctx), _ctx); /*3991*/
    return kk_std_core__list_unbox(_x717, _ctx);
  }
  { // tailcall
    kk_integer_t _x721 = kk_integer_sub(steps1,(kk_integer_from_small(1)),kk_context()); /*int*/
    kk_std_core__list _x722;
    kk_evv_t w10 = kk_evv_swap_create0(kk_context()); /*std/core/hnd/evv<(<>)>*/;
    kk_std_core__list x4;
    kk_function_t _x723 = kk_function_dup(norm2); /*forall<a> (effects-and-types/histogram<a>) -> effects-and-types/histogram<a>*/
    x4 = kk_function_call(kk_std_core__list, (kk_function_t, kk_std_core__list, kk_context_t*), _x723, (_x723, x3_530, _ctx)); /*effects-and-types/histogram<(steps : int) -> <effects-and-types/yield,effects-and-types/score,exn,effects-and-types/sample,div|420> 417>*/
    kk_unit_t keep00 = kk_Unit;
    kk_evv_set(w10,kk_context());
    _x722 = x4; /*effects-and-types/histogram<(steps : int) -> <effects-and-types/yield,effects-and-types/score,exn,effects-and-types/sample,div|420> 417>*/
    steps1 = _x721;
    pop_hist = _x722;
    goto kk__tailcall;
  }
}
 
// monadic lift


// lift anonymous function
struct kk_smc__mlift512_smc_fun726__t {
  struct kk_function_s _base;
};
static kk_std_core__list kk_smc__mlift512_smc_fun726(kk_function_t _fself, kk_std_core__list _x1725, kk_context_t* _ctx);
static kk_function_t kk_smc__new_mlift512_smc_fun726(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_smc__mlift512_smc_fun726, _ctx)
  return kk_function_dup(_fself);
}

static kk_std_core__list kk_smc__mlift512_smc_fun726(kk_function_t _fself, kk_std_core__list _x1725, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return kk_sampling_normalise(_x1725, _ctx);
}


// lift anonymous function
struct kk_smc__mlift512_smc_fun727__t {
  struct kk_function_s _base;
};
static kk_std_core__list kk_smc__mlift512_smc_fun727(kk_function_t _fself, kk_std_core__list _b_640, kk_context_t* _ctx);
static kk_function_t kk_smc__new_mlift512_smc_fun727(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_smc__mlift512_smc_fun727, _ctx)
  return kk_function_dup(_fself);
}

static kk_std_core__list kk_smc__mlift512_smc_fun727(kk_function_t _fself, kk_std_core__list _b_640, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_box_t _x728 = kk_std_core_types_id(kk_std_core__list_box(_b_640, _ctx), _ctx); /*2445*/
  return kk_std_core__list_unbox(_x728, _ctx);
}

kk_std_core__list kk_smc__mlift512_smc(bool normalize, kk_integer_t step_size, kk_integer_t steps, kk_std_core__list _y_15, kk_context_t* _ctx) { /* forall<a,e> (normalize : bool, step-size : int, steps : int, effects-and-types/histogram<(steps : int) -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random|e> a>) -> <effects-and-types/sample,div,exn,std/num/random/random|e> effects-and-types/histogram<a> */ 
  kk_std_core__list pop;
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*std/core/hnd/evv<(<>)>*/;
  kk_std_core__list x = kk_sampling_normalise(_y_15, _ctx); /*effects-and-types/histogram<(steps : int) -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random|497> 29>*/;
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  pop = x; /*effects-and-types/histogram<(steps : int) -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random|497> 29>*/
  kk_function_t _x724;
  if (normalize) {
    _x724 = kk_smc__new_mlift512_smc_fun726(_ctx); /*forall<a> (histogram : effects-and-types/histogram<a>) -> effects-and-types/histogram<a>*/
  }
  else {
    _x724 = kk_smc__new_mlift512_smc_fun727(_ctx); /*forall<a> (histogram : effects-and-types/histogram<a>) -> effects-and-types/histogram<a>*/
  }
  return kk_smc_smc_steps(steps, step_size, pop, _x724, _ctx);
}


// lift anonymous function
struct kk_smc_smc_fun730__t {
  struct kk_function_s _base;
  kk_function_t model;
  kk_integer_t particle__num;
  kk_integer_t step_size;
  kk_integer_t steps;
  bool normalize;
};
static kk_box_t kk_smc_smc_fun730(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_smc_new_smc_fun730(kk_function_t model, kk_integer_t particle__num, kk_integer_t step_size, kk_integer_t steps, bool normalize, kk_context_t* _ctx) {
  struct kk_smc_smc_fun730__t* _self = kk_function_alloc_as(struct kk_smc_smc_fun730__t, 5, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_smc_smc_fun730, kk_context());
  _self->model = model;
  _self->particle__num = particle__num;
  _self->step_size = step_size;
  _self->steps = steps;
  _self->normalize = normalize;
  return &_self->_base;
}



// lift anonymous function
struct kk_smc_smc_fun732__t {
  struct kk_function_s _base;
  kk_function_t model;
};
static kk_box_t kk_smc_smc_fun732(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_smc_new_smc_fun732(kk_function_t model, kk_context_t* _ctx) {
  struct kk_smc_smc_fun732__t* _self = kk_function_alloc_as(struct kk_smc_smc_fun732__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_smc_smc_fun732, kk_context());
  _self->model = model;
  return &_self->_base;
}



// lift anonymous function
struct kk_smc_smc_fun734__t {
  struct kk_function_s _base;
  kk_function_t model;
};
static kk_box_t kk_smc_smc_fun734(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_smc_new_smc_fun734(kk_function_t model, kk_context_t* _ctx) {
  struct kk_smc_smc_fun734__t* _self = kk_function_alloc_as(struct kk_smc_smc_fun734__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_smc_smc_fun734, kk_context());
  _self->model = model;
  return &_self->_base;
}

static kk_box_t kk_smc_smc_fun734(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_smc_smc_fun734__t* _self = kk_function_as(struct kk_smc_smc_fun734__t*, _fself);
  kk_function_t model = _self->model; /* () -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random|497> 29 */
  kk_drop_match(_self, {kk_function_dup(model);}, {}, _ctx)
  return kk_handlers_yield__on__score(model, _ctx);
}


// lift anonymous function
struct kk_smc_smc_fun735__t {
  struct kk_function_s _base;
  kk_function_t _bv_645;
};
static kk_box_t kk_smc_smc_fun735(kk_function_t _fself, kk_box_t _b_646, kk_context_t* _ctx);
static kk_function_t kk_smc_new_smc_fun735(kk_function_t _bv_645, kk_context_t* _ctx) {
  struct kk_smc_smc_fun735__t* _self = kk_function_alloc_as(struct kk_smc_smc_fun735__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_smc_smc_fun735, kk_context());
  _self->_bv_645 = _bv_645;
  return &_self->_base;
}

static kk_box_t kk_smc_smc_fun735(kk_function_t _fself, kk_box_t _b_646, kk_context_t* _ctx) {
  struct kk_smc_smc_fun735__t* _self = kk_function_as(struct kk_smc_smc_fun735__t*, _fself);
  kk_function_t _bv_645 = _self->_bv_645; /* (steps : int) -> <effects-and-types/yield,effects-and-types/sample,effects-and-types/score,div,exn,std/num/random/random|497> 29 */
  kk_drop_match(_self, {kk_function_dup(_bv_645);}, {}, _ctx)
  kk_integer_t _x736 = kk_integer_unbox(_b_646); /*int*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_context_t*), _bv_645, (_bv_645, _x736, _ctx));
}
static kk_box_t kk_smc_smc_fun732(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_smc_smc_fun732__t* _self = kk_function_as(struct kk_smc_smc_fun732__t*, _fself);
  kk_function_t model = _self->model; /* () -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random|497> 29 */
  kk_drop_match(_self, {kk_function_dup(model);}, {}, _ctx)
  kk_function_t _x733;
  kk_function_t _bv_645 = kk_handlers_advance(kk_smc_new_smc_fun734(model, _ctx), _ctx); /*(steps : int) -> <effects-and-types/yield,effects-and-types/sample,effects-and-types/score,div,exn,std/num/random/random|497> 29*/;
  _x733 = kk_smc_new_smc_fun735(_bv_645, _ctx); /*(643) -> <effects-and-types/yield,effects-and-types/sample,effects-and-types/score,div,exn,std/num/random/random|497> 29*/
  return kk_function_box(_x733);
}


// lift anonymous function
struct kk_smc_smc_fun738__t {
  struct kk_function_s _base;
  kk_integer_t step_size;
  kk_integer_t steps;
  bool normalize;
};
static kk_box_t kk_smc_smc_fun738(kk_function_t _fself, kk_box_t _b_650, kk_context_t* _ctx);
static kk_function_t kk_smc_new_smc_fun738(kk_integer_t step_size, kk_integer_t steps, bool normalize, kk_context_t* _ctx) {
  struct kk_smc_smc_fun738__t* _self = kk_function_alloc_as(struct kk_smc_smc_fun738__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_smc_smc_fun738, kk_context());
  _self->step_size = step_size;
  _self->steps = steps;
  _self->normalize = normalize;
  return &_self->_base;
}

static kk_box_t kk_smc_smc_fun738(kk_function_t _fself, kk_box_t _b_650, kk_context_t* _ctx) {
  struct kk_smc_smc_fun738__t* _self = kk_function_as(struct kk_smc_smc_fun738__t*, _fself);
  kk_integer_t step_size = _self->step_size; /* int */
  kk_integer_t steps = _self->steps; /* int */
  bool normalize = _self->normalize; /* bool */
  kk_drop_match(_self, {kk_integer_dup(step_size);kk_integer_dup(steps);;}, {}, _ctx)
  kk_std_core__list _x739;
  kk_std_core__list _x740 = kk_std_core__list_unbox(_b_650, _ctx); /*effects-and-types/histogram<(steps : int) -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random|497> 29>*/
  _x739 = kk_smc__mlift512_smc(normalize, step_size, steps, _x740, _ctx); /*effects-and-types/histogram<29>*/
  return kk_std_core__list_box(_x739, _ctx);
}
static kk_box_t kk_smc_smc_fun730(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_smc_smc_fun730__t* _self = kk_function_as(struct kk_smc_smc_fun730__t*, _fself);
  kk_function_t model = _self->model; /* () -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random|497> 29 */
  kk_integer_t particle__num = _self->particle__num; /* int */
  kk_integer_t step_size = _self->step_size; /* int */
  kk_integer_t steps = _self->steps; /* int */
  bool normalize = _self->normalize; /* bool */
  kk_drop_match(_self, {kk_function_dup(model);kk_integer_dup(particle__num);kk_integer_dup(step_size);kk_integer_dup(steps);;}, {}, _ctx)
  kk_std_core__list _x731;
  kk_std_core__list x_538 = kk_sampling_populate(particle__num, kk_smc_new_smc_fun732(model, _ctx), _ctx); /*effects-and-types/histogram<(steps : int) -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random|497> 29>*/;
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_538, _ctx);
    kk_box_t _x737 = kk_std_core_hnd_yield_extend(kk_smc_new_smc_fun738(step_size, steps, normalize, _ctx), _ctx); /*3991*/
    _x731 = kk_std_core__list_unbox(_x737, _ctx); /*effects-and-types/histogram<29>*/
  }
  else {
    _x731 = kk_smc__mlift512_smc(normalize, step_size, steps, x_538, _ctx); /*effects-and-types/histogram<29>*/
  }
  return kk_std_core__list_box(_x731, _ctx);
}

kk_std_core__list kk_smc_smc(kk_integer_t particle__num, kk_integer_t steps, kk_integer_t step_size, kk_function_t model, bool normalize, kk_context_t* _ctx) { /* forall<a,e> (particle_num : int, steps : int, step-size : int, model : () -> <pure,std/num/random/random,effects-and-types/sample,effects-and-types/score,effects-and-types/yield|e> a, normalize : bool) -> <pure,std/num/random/random|e> effects-and-types/histogram<a> */ 
  kk_box_t _x729 = kk_handlers_random__sampler(kk_smc_new_smc_fun730(model, particle__num, step_size, steps, normalize, _ctx), _ctx); /*801*/
  return kk_std_core__list_unbox(_x729, _ctx);
}

// initialization
void kk_smc__init(kk_context_t* _ctx){
  static bool _initialized = false;
  if (_initialized) return;
  _initialized = true;
  kk_std_core_types__init(_ctx);
  kk_std_core_hnd__init(_ctx);
  kk_std_core__init(_ctx);
  kk_std_num_random__init(_ctx);
  kk_effects_dash_and_dash_types__init(_ctx);
  kk_handlers__init(_ctx);
  kk_sampling__init(_ctx);
}
