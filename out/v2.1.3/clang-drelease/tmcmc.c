// Koka generated module: "tmcmc", koka version: 2.1.3
#include "tmcmc.h"
 
// monadic lift

kk_tmcmc__trace kk_tmcmc__mlift1671_op(kk_function_t _c_1, kk_effects_dash_and_dash_types__exp _c_2, kk_std_core__list _c_3, kk_box_t _c_4, kk_context_t* _ctx) { /* forall<a,e> (() -> e a, effects-and-types/exp, effects-and-types/trace_values, a) -> trace<a,e> */ 
  return kk_tmcmc__new_Trace(kk_reuse_null, _c_1, _c_2, _c_3, _c_4, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_tmcmc__mlift1672_op_fun2357__t {
  struct kk_function_s _base;
  kk_function_t _c_1;
  kk_std_core__list _c_3;
  kk_effects_dash_and_dash_types__exp _c_2;
};
static kk_box_t kk_tmcmc__mlift1672_op_fun2357(kk_function_t _fself, kk_box_t _b_1867, kk_context_t* _ctx);
static kk_function_t kk_tmcmc__new_mlift1672_op_fun2357(kk_function_t _c_1, kk_std_core__list _c_3, kk_effects_dash_and_dash_types__exp _c_2, kk_context_t* _ctx) {
  struct kk_tmcmc__mlift1672_op_fun2357__t* _self = kk_function_alloc_as(struct kk_tmcmc__mlift1672_op_fun2357__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc__mlift1672_op_fun2357, kk_context());
  _self->_c_1 = _c_1;
  _self->_c_3 = _c_3;
  _self->_c_2 = _c_2;
  return &_self->_base;
}

static kk_box_t kk_tmcmc__mlift1672_op_fun2357(kk_function_t _fself, kk_box_t _b_1867, kk_context_t* _ctx) {
  struct kk_tmcmc__mlift1672_op_fun2357__t* _self = kk_function_as(struct kk_tmcmc__mlift1672_op_fun2357__t*, _fself);
  kk_function_t _c_1 = _self->_c_1; /* () -> 265 264 */
  kk_std_core__list _c_3 = _self->_c_3; /* effects-and-types/trace_values */
  kk_effects_dash_and_dash_types__exp _c_2 = _self->_c_2; /* effects-and-types/exp */
  kk_drop_match(_self, {kk_function_dup(_c_1);kk_std_core__list_dup(_c_3);kk_effects_dash_and_dash_types__exp_dup(_c_2);}, {}, _ctx)
  kk_tmcmc__trace _x2358 = kk_tmcmc__mlift1671_op(_c_1, _c_2, _c_3, _b_1867, _ctx); /*tmcmc/trace<264,265>*/
  return kk_tmcmc__trace_box(_x2358, _ctx);
}

kk_tmcmc__trace kk_tmcmc__mlift1672_op(kk_function_t _c_1, kk_effects_dash_and_dash_types__exp _c_2, kk_tmcmc__trace _this, kk_std_core_types__optional a0, kk_std_core__list _c_3, kk_context_t* _ctx) { /* forall<a,e> (() -> e a, effects-and-types/exp, trace<a,e>, a : optional<a>, effects-and-types/trace_values) -> trace<a,e> */ 
  if (kk_yielding(kk_context())) {
    kk_tmcmc__trace_dropn(_this, ((int32_t)3), _ctx);
    kk_std_core_types__optional_drop(a0, _ctx);
    kk_box_t _x2356 = kk_std_core_hnd_yield_extend(kk_tmcmc__new_mlift1672_op_fun2357(_c_1, _c_3, _c_2, _ctx), _ctx); /*2*/
    return kk_tmcmc__trace_unbox(_x2356, _ctx);
  }
  kk_box_t _x2359;
  if (kk_std_core_types__is_Optional(a0)) {
    kk_box_t _a_249 = a0._cons.Optional.value;
    kk_tmcmc__trace_dropn(_this, ((int32_t)3), _ctx);
    _x2359 = _a_249; /*264*/
  }
  else {
    struct kk_tmcmc_Trace* _con2360 = kk_tmcmc__as_Trace(_this);
    kk_function_t _pat00 = _con2360->m;
    kk_effects_dash_and_dash_types__exp _pat10 = _con2360->p;
    kk_std_core__list _pat3 = _con2360->l;
    kk_box_t _x = _con2360->a;
    if (kk_tmcmc__trace_is_unique(_this)) {
      kk_std_core__list_drop(_pat3, _ctx);
      kk_function_drop(_pat00, _ctx);
      kk_tmcmc__trace_free(_this);
    }
    else {
      kk_box_dup(_x);
      kk_tmcmc__trace_decref(_this, _ctx);
    }
    _x2359 = _x; /*264*/
  }
  return kk_tmcmc__mlift1671_op(_c_1, _c_2, _c_3, _x2359, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_tmcmc__mlift1673_op_fun2362__t {
  struct kk_function_s _base;
  kk_function_t _c_1;
  kk_tmcmc__trace _this;
  kk_std_core_types__optional a0;
  kk_effects_dash_and_dash_types__exp _c_2;
};
static kk_box_t kk_tmcmc__mlift1673_op_fun2362(kk_function_t _fself, kk_box_t _b_1871, kk_context_t* _ctx);
static kk_function_t kk_tmcmc__new_mlift1673_op_fun2362(kk_function_t _c_1, kk_tmcmc__trace _this, kk_std_core_types__optional a0, kk_effects_dash_and_dash_types__exp _c_2, kk_context_t* _ctx) {
  struct kk_tmcmc__mlift1673_op_fun2362__t* _self = kk_function_alloc_as(struct kk_tmcmc__mlift1673_op_fun2362__t, 5, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc__mlift1673_op_fun2362, kk_context());
  _self->_c_1 = _c_1;
  _self->_this = _this;
  _self->a0 = a0;
  _self->_c_2 = _c_2;
  return &_self->_base;
}

static kk_box_t kk_tmcmc__mlift1673_op_fun2362(kk_function_t _fself, kk_box_t _b_1871, kk_context_t* _ctx) {
  struct kk_tmcmc__mlift1673_op_fun2362__t* _self = kk_function_as(struct kk_tmcmc__mlift1673_op_fun2362__t*, _fself);
  kk_function_t _c_1 = _self->_c_1; /* () -> 265 264 */
  kk_tmcmc__trace _this = _self->_this; /* tmcmc/trace<264,265> */
  kk_std_core_types__optional a0 = _self->a0; /* optional<264> */
  kk_effects_dash_and_dash_types__exp _c_2 = _self->_c_2; /* effects-and-types/exp */
  kk_drop_match(_self, {kk_function_dup(_c_1);kk_tmcmc__trace_dup(_this);kk_std_core_types__optional_dup(a0);kk_effects_dash_and_dash_types__exp_dup(_c_2);}, {}, _ctx)
  kk_tmcmc__trace _x2363;
  kk_std_core__list _x2364 = kk_std_core__list_unbox(_b_1871, _ctx); /*effects-and-types/trace_values*/
  _x2363 = kk_tmcmc__mlift1672_op(_c_1, _c_2, _this, a0, _x2364, _ctx); /*tmcmc/trace<264,265>*/
  return kk_tmcmc__trace_box(_x2363, _ctx);
}

kk_tmcmc__trace kk_tmcmc__mlift1673_op(kk_function_t _c_1, kk_tmcmc__trace _this, kk_std_core_types__optional a0, kk_std_core_types__optional l0, kk_effects_dash_and_dash_types__exp _c_2, kk_context_t* _ctx) { /* forall<a,e> (() -> e a, trace<a,e>, a : optional<a>, l : optional<effects-and-types/trace_values>, effects-and-types/exp) -> trace<a,e> */ 
  if (kk_yielding(kk_context())) {
    kk_std_core_types__optional_drop(l0, _ctx);
    kk_box_t _x2361 = kk_std_core_hnd_yield_extend(kk_tmcmc__new_mlift1673_op_fun2362(_c_1, _this, a0, _c_2, _ctx), _ctx); /*2*/
    return kk_tmcmc__trace_unbox(_x2361, _ctx);
  }
  kk_tmcmc__trace _x2365 = kk_tmcmc__trace_dup(_this); /*tmcmc/trace<264,265>*/
  kk_std_core__list _x2366;
  if (kk_std_core_types__is_Optional(l0)) {
    kk_box_t _box_x1872 = l0._cons.Optional.value;
    kk_std_core__list _l_241 = kk_std_core__list_unbox(_box_x1872, NULL);
    kk_std_core__list_dup(_l_241);
    kk_std_core_types__optional_drop(l0, _ctx);
    kk_tmcmc__trace_dropn(_this, ((int32_t)3), _ctx);
    _x2366 = _l_241; /*effects-and-types/trace_values*/
    goto _match2367;
  }
  struct kk_tmcmc_Trace* _con2369 = kk_tmcmc__as_Trace(_this);
  kk_function_t _pat00 = _con2369->m;
  kk_effects_dash_and_dash_types__exp _pat10 = _con2369->p;
  kk_std_core__list _x = _con2369->l;
  kk_box_t _pat30 = _con2369->a;
  if (kk_tmcmc__trace_is_unique(_this)) {
    kk_box_drop(_pat30, _ctx);
    kk_function_drop(_pat00, _ctx);
    kk_tmcmc__trace_free(_this);
  }
  else {
    kk_std_core__list_dup(_x);
    kk_tmcmc__trace_decref(_this, _ctx);
  }
  _x2366 = _x; /*effects-and-types/trace_values*/
  _match2367: ;
  return kk_tmcmc__mlift1672_op(_c_1, _c_2, _x2365, a0, _x2366, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_tmcmc__mlift1674_op_fun2371__t {
  struct kk_function_s _base;
  kk_function_t _c_1;
  kk_tmcmc__trace _this;
  kk_std_core_types__optional a0;
  kk_std_core_types__optional l0;
};
static kk_box_t kk_tmcmc__mlift1674_op_fun2371(kk_function_t _fself, kk_box_t _b_1876, kk_context_t* _ctx);
static kk_function_t kk_tmcmc__new_mlift1674_op_fun2371(kk_function_t _c_1, kk_tmcmc__trace _this, kk_std_core_types__optional a0, kk_std_core_types__optional l0, kk_context_t* _ctx) {
  struct kk_tmcmc__mlift1674_op_fun2371__t* _self = kk_function_alloc_as(struct kk_tmcmc__mlift1674_op_fun2371__t, 7, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc__mlift1674_op_fun2371, kk_context());
  _self->_c_1 = _c_1;
  _self->_this = _this;
  _self->a0 = a0;
  _self->l0 = l0;
  return &_self->_base;
}

static kk_box_t kk_tmcmc__mlift1674_op_fun2371(kk_function_t _fself, kk_box_t _b_1876, kk_context_t* _ctx) {
  struct kk_tmcmc__mlift1674_op_fun2371__t* _self = kk_function_as(struct kk_tmcmc__mlift1674_op_fun2371__t*, _fself);
  kk_function_t _c_1 = _self->_c_1; /* () -> 265 264 */
  kk_tmcmc__trace _this = _self->_this; /* tmcmc/trace<264,265> */
  kk_std_core_types__optional a0 = _self->a0; /* optional<264> */
  kk_std_core_types__optional l0 = _self->l0; /* optional<effects-and-types/trace_values> */
  kk_drop_match(_self, {kk_function_dup(_c_1);kk_tmcmc__trace_dup(_this);kk_std_core_types__optional_dup(a0);kk_std_core_types__optional_dup(l0);}, {}, _ctx)
  kk_tmcmc__trace _x2372;
  kk_effects_dash_and_dash_types__exp _x2373 = kk_effects_dash_and_dash_types__exp_unbox(_b_1876, _ctx); /*effects-and-types/exp*/
  _x2372 = kk_tmcmc__mlift1673_op(_c_1, _this, a0, l0, _x2373, _ctx); /*tmcmc/trace<264,265>*/
  return kk_tmcmc__trace_box(_x2372, _ctx);
}

kk_tmcmc__trace kk_tmcmc__mlift1674_op(kk_tmcmc__trace _this, kk_std_core_types__optional a0, kk_std_core_types__optional l0, kk_std_core_types__optional p0, kk_function_t _c_1, kk_context_t* _ctx) { /* forall<a,e> (trace<a,e>, a : optional<a>, l : optional<effects-and-types/trace_values>, p : optional<effects-and-types/exp>, () -> e a) -> trace<a,e> */ 
  if (kk_yielding(kk_context())) {
    kk_std_core_types__optional_drop(p0, _ctx);
    kk_box_t _x2370 = kk_std_core_hnd_yield_extend(kk_tmcmc__new_mlift1674_op_fun2371(_c_1, _this, a0, l0, _ctx), _ctx); /*2*/
    return kk_tmcmc__trace_unbox(_x2370, _ctx);
  }
  kk_tmcmc__trace _x2374 = kk_tmcmc__trace_dup(_this); /*tmcmc/trace<264,265>*/
  kk_effects_dash_and_dash_types__exp _x2375;
  if (kk_std_core_types__is_Optional(p0)) {
    kk_box_t _box_x1877 = p0._cons.Optional.value;
    kk_effects_dash_and_dash_types__exp _p_233 = kk_effects_dash_and_dash_types__exp_unbox(_box_x1877, NULL);
    kk_std_core_types__optional_drop(p0, _ctx);
    kk_tmcmc__trace_dropn(_this, ((int32_t)3), _ctx);
    _x2375 = _p_233; /*effects-and-types/exp*/
    goto _match2376;
  }
  struct kk_tmcmc_Trace* _con2378 = kk_tmcmc__as_Trace(_this);
  kk_function_t _pat00 = _con2378->m;
  kk_effects_dash_and_dash_types__exp _x = _con2378->p;
  kk_std_core__list _pat20 = _con2378->l;
  kk_box_t _pat30 = _con2378->a;
  if (kk_tmcmc__trace_is_unique(_this)) {
    kk_box_drop(_pat30, _ctx);
    kk_std_core__list_drop(_pat20, _ctx);
    kk_function_drop(_pat00, _ctx);
    kk_tmcmc__trace_free(_this);
  }
  else {
    kk_tmcmc__trace_decref(_this, _ctx);
  }
  _x2375 = _x; /*effects-and-types/exp*/
  _match2376: ;
  return kk_tmcmc__mlift1673_op(_c_1, _x2374, a0, l0, _x2375, _ctx);
}


// lift anonymous function
struct kk_tmcmc__copy_fun2380__t {
  struct kk_function_s _base;
  kk_tmcmc__trace _this;
  kk_std_core_types__optional a0;
  kk_std_core_types__optional l0;
  kk_std_core_types__optional p0;
};
static kk_box_t kk_tmcmc__copy_fun2380(kk_function_t _fself, kk_box_t _b_1881, kk_context_t* _ctx);
static kk_function_t kk_tmcmc__new_copy_fun2380(kk_tmcmc__trace _this, kk_std_core_types__optional a0, kk_std_core_types__optional l0, kk_std_core_types__optional p0, kk_context_t* _ctx) {
  struct kk_tmcmc__copy_fun2380__t* _self = kk_function_alloc_as(struct kk_tmcmc__copy_fun2380__t, 8, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc__copy_fun2380, kk_context());
  _self->_this = _this;
  _self->a0 = a0;
  _self->l0 = l0;
  _self->p0 = p0;
  return &_self->_base;
}

static kk_box_t kk_tmcmc__copy_fun2380(kk_function_t _fself, kk_box_t _b_1881, kk_context_t* _ctx) {
  struct kk_tmcmc__copy_fun2380__t* _self = kk_function_as(struct kk_tmcmc__copy_fun2380__t*, _fself);
  kk_tmcmc__trace _this = _self->_this; /* tmcmc/trace<264,265> */
  kk_std_core_types__optional a0 = _self->a0; /* optional<264> */
  kk_std_core_types__optional l0 = _self->l0; /* optional<effects-and-types/trace_values> */
  kk_std_core_types__optional p0 = _self->p0; /* optional<effects-and-types/exp> */
  kk_drop_match(_self, {kk_tmcmc__trace_dup(_this);kk_std_core_types__optional_dup(a0);kk_std_core_types__optional_dup(l0);kk_std_core_types__optional_dup(p0);}, {}, _ctx)
  kk_tmcmc__trace _x2381;
  kk_function_t _x2382 = kk_function_unbox(_b_1881); /*() -> 265 1882*/
  _x2381 = kk_tmcmc__mlift1674_op(_this, a0, l0, p0, _x2382, _ctx); /*tmcmc/trace<264,265>*/
  return kk_tmcmc__trace_box(_x2381, _ctx);
}


// lift anonymous function
struct kk_tmcmc__copy_fun2384__t {
  struct kk_function_s _base;
  kk_tmcmc__trace _this;
  kk_std_core_types__optional a0;
  kk_std_core_types__optional l0;
  kk_std_core_types__optional m0;
};
static kk_box_t kk_tmcmc__copy_fun2384(kk_function_t _fself, kk_box_t _b_1887, kk_context_t* _ctx);
static kk_function_t kk_tmcmc__new_copy_fun2384(kk_tmcmc__trace _this, kk_std_core_types__optional a0, kk_std_core_types__optional l0, kk_std_core_types__optional m0, kk_context_t* _ctx) {
  struct kk_tmcmc__copy_fun2384__t* _self = kk_function_alloc_as(struct kk_tmcmc__copy_fun2384__t, 8, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc__copy_fun2384, kk_context());
  _self->_this = _this;
  _self->a0 = a0;
  _self->l0 = l0;
  _self->m0 = m0;
  return &_self->_base;
}

static kk_box_t kk_tmcmc__copy_fun2384(kk_function_t _fself, kk_box_t _b_1887, kk_context_t* _ctx) {
  struct kk_tmcmc__copy_fun2384__t* _self = kk_function_as(struct kk_tmcmc__copy_fun2384__t*, _fself);
  kk_tmcmc__trace _this = _self->_this; /* tmcmc/trace<264,265> */
  kk_std_core_types__optional a0 = _self->a0; /* optional<264> */
  kk_std_core_types__optional l0 = _self->l0; /* optional<effects-and-types/trace_values> */
  kk_std_core_types__optional m0 = _self->m0; /* optional<() -> 265 264> */
  kk_drop_match(_self, {kk_tmcmc__trace_dup(_this);kk_std_core_types__optional_dup(a0);kk_std_core_types__optional_dup(l0);kk_std_core_types__optional_dup(m0);}, {}, _ctx)
  kk_tmcmc__trace _x2385;
  kk_function_t _x2386;
  if (kk_std_core_types__is_Optional(m0)) {
    kk_box_t _fun_unbox_x1884 = m0._cons.Optional.value;
    _x2386 = kk_function_unbox(_fun_unbox_x1884); /*() -> 265 1885*/
  }
  else {
    struct kk_tmcmc_Trace* _con2387 = kk_tmcmc__as_Trace(_this);
    kk_function_t _x = _con2387->m;
    kk_effects_dash_and_dash_types__exp _pat01 = _con2387->p;
    kk_function_dup(_x);
    _x2386 = _x; /*() -> 265 1885*/
  }
  kk_effects_dash_and_dash_types__exp _x2388 = kk_effects_dash_and_dash_types__exp_unbox(_b_1887, _ctx); /*effects-and-types/exp*/
  _x2385 = kk_tmcmc__mlift1673_op(_x2386, _this, a0, l0, _x2388, _ctx); /*tmcmc/trace<264,265>*/
  return kk_tmcmc__trace_box(_x2385, _ctx);
}


// lift anonymous function
struct kk_tmcmc__copy_fun2390__t {
  struct kk_function_s _base;
  kk_tmcmc__trace _this;
  kk_std_core_types__optional a0;
  kk_std_core_types__optional m0;
  kk_std_core_types__optional p0;
};
static kk_box_t kk_tmcmc__copy_fun2390(kk_function_t _fself, kk_box_t _b_1893, kk_context_t* _ctx);
static kk_function_t kk_tmcmc__new_copy_fun2390(kk_tmcmc__trace _this, kk_std_core_types__optional a0, kk_std_core_types__optional m0, kk_std_core_types__optional p0, kk_context_t* _ctx) {
  struct kk_tmcmc__copy_fun2390__t* _self = kk_function_alloc_as(struct kk_tmcmc__copy_fun2390__t, 8, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc__copy_fun2390, kk_context());
  _self->_this = _this;
  _self->a0 = a0;
  _self->m0 = m0;
  _self->p0 = p0;
  return &_self->_base;
}

static kk_box_t kk_tmcmc__copy_fun2390(kk_function_t _fself, kk_box_t _b_1893, kk_context_t* _ctx) {
  struct kk_tmcmc__copy_fun2390__t* _self = kk_function_as(struct kk_tmcmc__copy_fun2390__t*, _fself);
  kk_tmcmc__trace _this = _self->_this; /* tmcmc/trace<264,265> */
  kk_std_core_types__optional a0 = _self->a0; /* optional<264> */
  kk_std_core_types__optional m0 = _self->m0; /* optional<() -> 265 264> */
  kk_std_core_types__optional p0 = _self->p0; /* optional<effects-and-types/exp> */
  kk_drop_match(_self, {kk_tmcmc__trace_dup(_this);kk_std_core_types__optional_dup(a0);kk_std_core_types__optional_dup(m0);kk_std_core_types__optional_dup(p0);}, {}, _ctx)
  kk_tmcmc__trace _x2391;
  kk_function_t _x2392;
  if (kk_std_core_types__is_Optional(m0)) {
    kk_box_t _fun_unbox_x1889 = m0._cons.Optional.value;
    _x2392 = kk_function_unbox(_fun_unbox_x1889); /*() -> 265 1890*/
  }
  else {
    struct kk_tmcmc_Trace* _con2393 = kk_tmcmc__as_Trace(_this);
    kk_function_t _x0 = _con2393->m;
    kk_effects_dash_and_dash_types__exp _pat010 = _con2393->p;
    kk_function_dup(_x0);
    _x2392 = _x0; /*() -> 265 1890*/
  }
  kk_effects_dash_and_dash_types__exp _x2394;
  if (kk_std_core_types__is_Optional(p0)) {
    kk_box_t _box_x1891 = p0._cons.Optional.value;
    kk_effects_dash_and_dash_types__exp _p_233 = kk_effects_dash_and_dash_types__exp_unbox(_box_x1891, NULL);
    kk_std_core_types__optional_drop(p0, _ctx);
    _x2394 = _p_233; /*effects-and-types/exp*/
    goto _match2395;
  }
  struct kk_tmcmc_Trace* _con2397 = kk_tmcmc__as_Trace(_this);
  kk_effects_dash_and_dash_types__exp _x00 = _con2397->p;
  _x2394 = _x00; /*effects-and-types/exp*/
  _match2395: ;
  kk_std_core__list _x2398 = kk_std_core__list_unbox(_b_1893, _ctx); /*effects-and-types/trace_values*/
  _x2391 = kk_tmcmc__mlift1672_op(_x2392, _x2394, _this, a0, _x2398, _ctx); /*tmcmc/trace<264,265>*/
  return kk_tmcmc__trace_box(_x2391, _ctx);
}


// lift anonymous function
struct kk_tmcmc__copy_fun2400__t {
  struct kk_function_s _base;
  kk_tmcmc__trace _this;
  kk_std_core_types__optional l0;
  kk_std_core_types__optional m0;
  kk_std_core_types__optional p0;
};
static kk_box_t kk_tmcmc__copy_fun2400(kk_function_t _fself, kk_box_t _b_1900, kk_context_t* _ctx);
static kk_function_t kk_tmcmc__new_copy_fun2400(kk_tmcmc__trace _this, kk_std_core_types__optional l0, kk_std_core_types__optional m0, kk_std_core_types__optional p0, kk_context_t* _ctx) {
  struct kk_tmcmc__copy_fun2400__t* _self = kk_function_alloc_as(struct kk_tmcmc__copy_fun2400__t, 8, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc__copy_fun2400, kk_context());
  _self->_this = _this;
  _self->l0 = l0;
  _self->m0 = m0;
  _self->p0 = p0;
  return &_self->_base;
}

static kk_box_t kk_tmcmc__copy_fun2400(kk_function_t _fself, kk_box_t _b_1900, kk_context_t* _ctx) {
  struct kk_tmcmc__copy_fun2400__t* _self = kk_function_as(struct kk_tmcmc__copy_fun2400__t*, _fself);
  kk_tmcmc__trace _this = _self->_this; /* tmcmc/trace<264,265> */
  kk_std_core_types__optional l0 = _self->l0; /* optional<effects-and-types/trace_values> */
  kk_std_core_types__optional m0 = _self->m0; /* optional<() -> 265 264> */
  kk_std_core_types__optional p0 = _self->p0; /* optional<effects-and-types/exp> */
  kk_drop_match(_self, {kk_tmcmc__trace_dup(_this);kk_std_core_types__optional_dup(l0);kk_std_core_types__optional_dup(m0);kk_std_core_types__optional_dup(p0);}, {}, _ctx)
  kk_tmcmc__trace _x2401;
  kk_function_t _x2402;
  if (kk_std_core_types__is_Optional(m0)) {
    kk_box_t _fun_unbox_x1895 = m0._cons.Optional.value;
    _x2402 = kk_function_unbox(_fun_unbox_x1895); /*() -> 265 1896*/
  }
  else {
    struct kk_tmcmc_Trace* _con2403 = kk_tmcmc__as_Trace(_this);
    kk_function_t _x1 = _con2403->m;
    kk_effects_dash_and_dash_types__exp _pat011 = _con2403->p;
    kk_function_dup(_x1);
    _x2402 = _x1; /*() -> 265 1896*/
  }
  kk_effects_dash_and_dash_types__exp _x2404;
  if (kk_std_core_types__is_Optional(p0)) {
    kk_box_t _box_x1897 = p0._cons.Optional.value;
    kk_effects_dash_and_dash_types__exp _p_2330 = kk_effects_dash_and_dash_types__exp_unbox(_box_x1897, NULL);
    kk_std_core_types__optional_drop(p0, _ctx);
    _x2404 = _p_2330; /*effects-and-types/exp*/
    goto _match2405;
  }
  struct kk_tmcmc_Trace* _con2407 = kk_tmcmc__as_Trace(_this);
  kk_effects_dash_and_dash_types__exp _x01 = _con2407->p;
  _x2404 = _x01; /*effects-and-types/exp*/
  _match2405: ;
  kk_std_core__list _x2408;
  if (kk_std_core_types__is_Optional(l0)) {
    kk_box_t _box_x1898 = l0._cons.Optional.value;
    kk_std_core__list _l_241 = kk_std_core__list_unbox(_box_x1898, NULL);
    kk_std_core__list_dup(_l_241);
    kk_std_core_types__optional_drop(l0, _ctx);
    kk_tmcmc__trace_dropn(_this, ((int32_t)3), _ctx);
    _x2408 = _l_241; /*effects-and-types/trace_values*/
    goto _match2409;
  }
  struct kk_tmcmc_Trace* _con2411 = kk_tmcmc__as_Trace(_this);
  kk_function_t _pat05 = _con2411->m;
  kk_effects_dash_and_dash_types__exp _pat130 = _con2411->p;
  kk_std_core__list _x10 = _con2411->l;
  kk_box_t _pat32 = _con2411->a;
  if (kk_tmcmc__trace_is_unique(_this)) {
    kk_box_drop(_pat32, _ctx);
    kk_function_drop(_pat05, _ctx);
    kk_tmcmc__trace_free(_this);
  }
  else {
    kk_std_core__list_dup(_x10);
    kk_tmcmc__trace_decref(_this, _ctx);
  }
  _x2408 = _x10; /*effects-and-types/trace_values*/
  _match2409: ;
  _x2401 = kk_tmcmc__mlift1671_op(_x2402, _x2404, _x2408, _b_1900, _ctx); /*tmcmc/trace<264,265>*/
  return kk_tmcmc__trace_box(_x2401, _ctx);
}

kk_tmcmc__trace kk_tmcmc__copy(kk_tmcmc__trace _this, kk_std_core_types__optional m0, kk_std_core_types__optional p0, kk_std_core_types__optional l0, kk_std_core_types__optional a0, kk_context_t* _ctx) { /* forall<a,e> (trace<a,e>, m : optional<() -> e a>, p : optional<effects-and-types/exp>, l : optional<effects-and-types/trace_values>, a : optional<a>) -> trace<a,e> */ 
  if (kk_yielding(kk_context())) {
    kk_std_core_types__optional_drop(m0, _ctx);
    kk_box_t _x2379 = kk_std_core_hnd_yield_extend(kk_tmcmc__new_copy_fun2380(_this, a0, l0, p0, _ctx), _ctx); /*2*/
    return kk_tmcmc__trace_unbox(_x2379, _ctx);
  }
  if (kk_yielding(kk_context())) {
    kk_std_core_types__optional_drop(p0, _ctx);
    kk_box_t _x2383 = kk_std_core_hnd_yield_extend(kk_tmcmc__new_copy_fun2384(_this, a0, l0, m0, _ctx), _ctx); /*2*/
    return kk_tmcmc__trace_unbox(_x2383, _ctx);
  }
  if (kk_yielding(kk_context())) {
    kk_std_core_types__optional_drop(l0, _ctx);
    kk_box_t _x2389 = kk_std_core_hnd_yield_extend(kk_tmcmc__new_copy_fun2390(_this, a0, m0, p0, _ctx), _ctx); /*2*/
    return kk_tmcmc__trace_unbox(_x2389, _ctx);
  }
  if (kk_yielding(kk_context())) {
    kk_std_core_types__optional_drop(a0, _ctx);
    kk_box_t _x2399 = kk_std_core_hnd_yield_extend(kk_tmcmc__new_copy_fun2400(_this, l0, m0, p0, _ctx), _ctx); /*2*/
    return kk_tmcmc__trace_unbox(_x2399, _ctx);
  }
  kk_function_t _x2412;
  if (kk_std_core_types__is_Optional(m0)) {
    kk_box_t _fun_unbox_x1902 = m0._cons.Optional.value;
    _x2412 = kk_function_unbox(_fun_unbox_x1902); /*() -> 265 1903*/
  }
  else {
    struct kk_tmcmc_Trace* _con2413 = kk_tmcmc__as_Trace(_this);
    kk_function_t _x2 = _con2413->m;
    kk_effects_dash_and_dash_types__exp _pat012 = _con2413->p;
    kk_function_dup(_x2);
    _x2412 = _x2; /*() -> 265 1903*/
  }
  kk_effects_dash_and_dash_types__exp _x2414;
  if (kk_std_core_types__is_Optional(p0)) {
    kk_box_t _box_x1904 = p0._cons.Optional.value;
    kk_effects_dash_and_dash_types__exp _p_2331 = kk_effects_dash_and_dash_types__exp_unbox(_box_x1904, NULL);
    kk_std_core_types__optional_drop(p0, _ctx);
    _x2414 = _p_2331; /*effects-and-types/exp*/
    goto _match2415;
  }
  struct kk_tmcmc_Trace* _con2417 = kk_tmcmc__as_Trace(_this);
  kk_effects_dash_and_dash_types__exp _x02 = _con2417->p;
  _x2414 = _x02; /*effects-and-types/exp*/
  _match2415: ;
  kk_std_core__list _x2418;
  if (kk_std_core_types__is_Optional(l0)) {
    kk_box_t _box_x1905 = l0._cons.Optional.value;
    kk_std_core__list _l_2410 = kk_std_core__list_unbox(_box_x1905, NULL);
    kk_std_core__list_dup(_l_2410);
    kk_std_core_types__optional_drop(l0, _ctx);
    _x2418 = _l_2410; /*effects-and-types/trace_values*/
    goto _match2419;
  }
  struct kk_tmcmc_Trace* _con2421 = kk_tmcmc__as_Trace(_this);
  kk_effects_dash_and_dash_types__exp _pat131 = _con2421->p;
  kk_std_core__list _x11 = _con2421->l;
  kk_std_core__list_dup(_x11);
  _x2418 = _x11; /*effects-and-types/trace_values*/
  _match2419: ;
  kk_box_t _x2422;
  if (kk_std_core_types__is_Optional(a0)) {
    kk_box_t _a_249 = a0._cons.Optional.value;
    kk_tmcmc__trace_dropn(_this, ((int32_t)3), _ctx);
    _x2422 = _a_249; /*264*/
  }
  else {
    struct kk_tmcmc_Trace* _con2423 = kk_tmcmc__as_Trace(_this);
    kk_function_t _pat07 = _con2423->m;
    kk_effects_dash_and_dash_types__exp _pat140 = _con2423->p;
    kk_std_core__list _pat330 = _con2423->l;
    kk_box_t _x20 = _con2423->a;
    if (kk_tmcmc__trace_is_unique(_this)) {
      kk_std_core__list_drop(_pat330, _ctx);
      kk_function_drop(_pat07, _ctx);
      kk_tmcmc__trace_free(_this);
    }
    else {
      kk_box_dup(_x20);
      kk_tmcmc__trace_decref(_this, _ctx);
    }
    _x2422 = _x20; /*264*/
  }
  return kk_tmcmc__new_Trace(kk_reuse_null, _x2412, _x2414, _x2418, _x2422, _ctx);
}
 
// monadic lift

kk_tmcmc__trace__rmsmc kk_tmcmc__mlift1675_op(kk_function_t _c_5, kk_effects_dash_and_dash_types__exp _c_6, kk_std_core__list _c_7, kk_context_t* _ctx) { /* forall<a,e> (() -> ((int) -> e a), effects-and-types/exp, effects-and-types/trace_values) -> trace_rmsmc<a,e> */ 
  return kk_tmcmc__new_RTrace(_c_5, _c_6, _c_7, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_tmcmc__mlift1676_op_fun2425__t {
  struct kk_function_s _base;
  kk_function_t _c_5;
  kk_effects_dash_and_dash_types__exp _c_6;
};
static kk_box_t kk_tmcmc__mlift1676_op_fun2425(kk_function_t _fself, kk_box_t _b_1915, kk_context_t* _ctx);
static kk_function_t kk_tmcmc__new_mlift1676_op_fun2425(kk_function_t _c_5, kk_effects_dash_and_dash_types__exp _c_6, kk_context_t* _ctx) {
  struct kk_tmcmc__mlift1676_op_fun2425__t* _self = kk_function_alloc_as(struct kk_tmcmc__mlift1676_op_fun2425__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc__mlift1676_op_fun2425, kk_context());
  _self->_c_5 = _c_5;
  _self->_c_6 = _c_6;
  return &_self->_base;
}

static kk_box_t kk_tmcmc__mlift1676_op_fun2425(kk_function_t _fself, kk_box_t _b_1915, kk_context_t* _ctx) {
  struct kk_tmcmc__mlift1676_op_fun2425__t* _self = kk_function_as(struct kk_tmcmc__mlift1676_op_fun2425__t*, _fself);
  kk_function_t _c_5 = _self->_c_5; /* () -> ((int) -> 492 491) */
  kk_effects_dash_and_dash_types__exp _c_6 = _self->_c_6; /* effects-and-types/exp */
  kk_drop_match(_self, {kk_function_dup(_c_5);kk_effects_dash_and_dash_types__exp_dup(_c_6);}, {}, _ctx)
  kk_tmcmc__trace__rmsmc _x2426;
  kk_std_core__list _x2427 = kk_std_core__list_unbox(_b_1915, _ctx); /*effects-and-types/trace_values*/
  _x2426 = kk_tmcmc__mlift1675_op(_c_5, _c_6, _x2427, _ctx); /*tmcmc/trace_rmsmc<491,492>*/
  return kk_tmcmc__trace__rmsmc_box(_x2426, _ctx);
}

kk_tmcmc__trace__rmsmc kk_tmcmc__mlift1676_op(kk_function_t _c_5, kk_tmcmc__trace__rmsmc _this, kk_std_core_types__optional l0, kk_effects_dash_and_dash_types__exp _c_6, kk_context_t* _ctx) { /* forall<a,e> (() -> ((int) -> e a), trace_rmsmc<a,e>, l : optional<effects-and-types/trace_values>, effects-and-types/exp) -> trace_rmsmc<a,e> */ 
  if (kk_yielding(kk_context())) {
    kk_tmcmc__trace__rmsmc_drop(_this, _ctx);
    kk_std_core_types__optional_drop(l0, _ctx);
    kk_box_t _x2424 = kk_std_core_hnd_yield_extend(kk_tmcmc__new_mlift1676_op_fun2425(_c_5, _c_6, _ctx), _ctx); /*2*/
    return kk_tmcmc__trace__rmsmc_unbox(_x2424, _ctx);
  }
  kk_std_core__list _x2428;
  if (kk_std_core_types__is_Optional(l0)) {
    kk_box_t _box_x1916 = l0._cons.Optional.value;
    kk_std_core__list _l_476 = kk_std_core__list_unbox(_box_x1916, NULL);
    kk_std_core__list_dup(_l_476);
    kk_std_core_types__optional_drop(l0, _ctx);
    kk_tmcmc__trace__rmsmc_drop(_this, _ctx);
    _x2428 = _l_476; /*effects-and-types/trace_values*/
    goto _match2429;
  }
  kk_effects_dash_and_dash_types__exp _pat10 = _this.p;
  kk_std_core__list _x = _this.l;
  kk_std_core__list_dup(_x);
  kk_tmcmc__trace__rmsmc_drop(_this, _ctx);
  _x2428 = _x; /*effects-and-types/trace_values*/
  _match2429: ;
  return kk_tmcmc__mlift1675_op(_c_5, _c_6, _x2428, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_tmcmc__mlift1677_op_fun2432__t {
  struct kk_function_s _base;
  kk_function_t _c_5;
  kk_std_core_types__optional l0;
  kk_tmcmc__trace__rmsmc _this;
};
static kk_box_t kk_tmcmc__mlift1677_op_fun2432(kk_function_t _fself, kk_box_t _b_1920, kk_context_t* _ctx);
static kk_function_t kk_tmcmc__new_mlift1677_op_fun2432(kk_function_t _c_5, kk_std_core_types__optional l0, kk_tmcmc__trace__rmsmc _this, kk_context_t* _ctx) {
  struct kk_tmcmc__mlift1677_op_fun2432__t* _self = kk_function_alloc_as(struct kk_tmcmc__mlift1677_op_fun2432__t, 6, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc__mlift1677_op_fun2432, kk_context());
  _self->_c_5 = _c_5;
  _self->l0 = l0;
  _self->_this = _this;
  return &_self->_base;
}

static kk_box_t kk_tmcmc__mlift1677_op_fun2432(kk_function_t _fself, kk_box_t _b_1920, kk_context_t* _ctx) {
  struct kk_tmcmc__mlift1677_op_fun2432__t* _self = kk_function_as(struct kk_tmcmc__mlift1677_op_fun2432__t*, _fself);
  kk_function_t _c_5 = _self->_c_5; /* () -> ((int) -> 492 491) */
  kk_std_core_types__optional l0 = _self->l0; /* optional<effects-and-types/trace_values> */
  kk_tmcmc__trace__rmsmc _this = _self->_this; /* tmcmc/trace_rmsmc<491,492> */
  kk_drop_match(_self, {kk_function_dup(_c_5);kk_std_core_types__optional_dup(l0);kk_tmcmc__trace__rmsmc_dup(_this);}, {}, _ctx)
  kk_tmcmc__trace__rmsmc _x2433;
  kk_effects_dash_and_dash_types__exp _x2434 = kk_effects_dash_and_dash_types__exp_unbox(_b_1920, _ctx); /*effects-and-types/exp*/
  _x2433 = kk_tmcmc__mlift1676_op(_c_5, _this, l0, _x2434, _ctx); /*tmcmc/trace_rmsmc<491,492>*/
  return kk_tmcmc__trace__rmsmc_box(_x2433, _ctx);
}

kk_tmcmc__trace__rmsmc kk_tmcmc__mlift1677_op(kk_tmcmc__trace__rmsmc _this, kk_std_core_types__optional l0, kk_std_core_types__optional p0, kk_function_t _c_5, kk_context_t* _ctx) { /* forall<a,e> (trace_rmsmc<a,e>, l : optional<effects-and-types/trace_values>, p : optional<effects-and-types/exp>, () -> ((int) -> e a)) -> trace_rmsmc<a,e> */ 
  if (kk_yielding(kk_context())) {
    kk_std_core_types__optional_drop(p0, _ctx);
    kk_box_t _x2431 = kk_std_core_hnd_yield_extend(kk_tmcmc__new_mlift1677_op_fun2432(_c_5, l0, _this, _ctx), _ctx); /*2*/
    return kk_tmcmc__trace__rmsmc_unbox(_x2431, _ctx);
  }
  kk_tmcmc__trace__rmsmc _x2435 = kk_tmcmc__trace__rmsmc_dup(_this); /*tmcmc/trace_rmsmc<491,492>*/
  kk_effects_dash_and_dash_types__exp _x2436;
  if (kk_std_core_types__is_Optional(p0)) {
    kk_box_t _box_x1921 = p0._cons.Optional.value;
    kk_effects_dash_and_dash_types__exp _p_442 = kk_effects_dash_and_dash_types__exp_unbox(_box_x1921, NULL);
    kk_std_core_types__optional_drop(p0, _ctx);
    kk_tmcmc__trace__rmsmc_drop(_this, _ctx);
    _x2436 = _p_442; /*effects-and-types/exp*/
    goto _match2437;
  }
  kk_effects_dash_and_dash_types__exp _x = _this.p;
  kk_tmcmc__trace__rmsmc_drop(_this, _ctx);
  _x2436 = _x; /*effects-and-types/exp*/
  _match2437: ;
  return kk_tmcmc__mlift1676_op(_c_5, _x2435, l0, _x2436, _ctx);
}


// lift anonymous function
struct kk_tmcmc__copy_fun2440__t_1 {
  struct kk_function_s _base;
  kk_std_core_types__optional l0;
  kk_std_core_types__optional p0;
  kk_tmcmc__trace__rmsmc _this;
};
static kk_box_t kk_tmcmc__copy_fun2440_1(kk_function_t _fself, kk_box_t _b_1925, kk_context_t* _ctx);
static kk_function_t kk_tmcmc__new_copy_fun2440_1(kk_std_core_types__optional l0, kk_std_core_types__optional p0, kk_tmcmc__trace__rmsmc _this, kk_context_t* _ctx) {
  struct kk_tmcmc__copy_fun2440__t_1* _self = kk_function_alloc_as(struct kk_tmcmc__copy_fun2440__t_1, 7, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc__copy_fun2440_1, kk_context());
  _self->l0 = l0;
  _self->p0 = p0;
  _self->_this = _this;
  return &_self->_base;
}



// lift anonymous function
struct kk_tmcmc__copy_fun2442__t_1 {
  struct kk_function_s _base;
  kk_box_t _b_1925;
};
static kk_function_t kk_tmcmc__copy_fun2442_1(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_tmcmc__new_copy_fun2442_1(kk_box_t _b_1925, kk_context_t* _ctx) {
  struct kk_tmcmc__copy_fun2442__t_1* _self = kk_function_alloc_as(struct kk_tmcmc__copy_fun2442__t_1, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc__copy_fun2442_1, kk_context());
  _self->_b_1925 = _b_1925;
  return &_self->_base;
}



// lift anonymous function
struct kk_tmcmc__copy_fun2445__t_1 {
  struct kk_function_s _base;
  kk_function_t _bv_1929;
};
static kk_box_t kk_tmcmc__copy_fun2445_1(kk_function_t _fself, kk_integer_t _b_1930, kk_context_t* _ctx);
static kk_function_t kk_tmcmc__new_copy_fun2445_1(kk_function_t _bv_1929, kk_context_t* _ctx) {
  struct kk_tmcmc__copy_fun2445__t_1* _self = kk_function_alloc_as(struct kk_tmcmc__copy_fun2445__t_1, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc__copy_fun2445_1, kk_context());
  _self->_bv_1929 = _bv_1929;
  return &_self->_base;
}

static kk_box_t kk_tmcmc__copy_fun2445_1(kk_function_t _fself, kk_integer_t _b_1930, kk_context_t* _ctx) {
  struct kk_tmcmc__copy_fun2445__t_1* _self = kk_function_as(struct kk_tmcmc__copy_fun2445__t_1*, _fself);
  kk_function_t _bv_1929 = _self->_bv_1929; /* (1927) -> 492 1928 */
  kk_drop_match(_self, {kk_function_dup(_bv_1929);}, {}, _ctx)
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _bv_1929, (_bv_1929, kk_integer_box(_b_1930), _ctx));
}
static kk_function_t kk_tmcmc__copy_fun2442_1(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_tmcmc__copy_fun2442__t_1* _self = kk_function_as(struct kk_tmcmc__copy_fun2442__t_1*, _fself);
  kk_box_t _b_1925 = _self->_b_1925; /* 1 */
  kk_drop_match(_self, {kk_box_dup(_b_1925);}, {}, _ctx)
  kk_function_t _bv_1929;
  kk_box_t _x2443;
  kk_function_t _x2444 = kk_function_unbox(_b_1925); /*() -> 1926*/
  _x2443 = kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), _x2444, (_x2444, _ctx)); /*1926*/
  _bv_1929 = kk_function_unbox(_x2443); /*(1927) -> 492 1928*/
  return kk_tmcmc__new_copy_fun2445_1(_bv_1929, _ctx);
}
static kk_box_t kk_tmcmc__copy_fun2440_1(kk_function_t _fself, kk_box_t _b_1925, kk_context_t* _ctx) {
  struct kk_tmcmc__copy_fun2440__t_1* _self = kk_function_as(struct kk_tmcmc__copy_fun2440__t_1*, _fself);
  kk_std_core_types__optional l0 = _self->l0; /* optional<effects-and-types/trace_values> */
  kk_std_core_types__optional p0 = _self->p0; /* optional<effects-and-types/exp> */
  kk_tmcmc__trace__rmsmc _this = _self->_this; /* tmcmc/trace_rmsmc<491,492> */
  kk_drop_match(_self, {kk_std_core_types__optional_dup(l0);kk_std_core_types__optional_dup(p0);kk_tmcmc__trace__rmsmc_dup(_this);}, {}, _ctx)
  kk_tmcmc__trace__rmsmc _x2441 = kk_tmcmc__mlift1677_op(_this, l0, p0, kk_tmcmc__new_copy_fun2442_1(_b_1925, _ctx), _ctx); /*tmcmc/trace_rmsmc<491,492>*/
  return kk_tmcmc__trace__rmsmc_box(_x2441, _ctx);
}


// lift anonymous function
struct kk_tmcmc__copy_fun2447__t_1 {
  struct kk_function_s _base;
  kk_std_core_types__optional l0;
  kk_std_core_types__optional m0;
  kk_tmcmc__trace__rmsmc _this;
};
static kk_box_t kk_tmcmc__copy_fun2447_1(kk_function_t _fself, kk_box_t _b_1943, kk_context_t* _ctx);
static kk_function_t kk_tmcmc__new_copy_fun2447_1(kk_std_core_types__optional l0, kk_std_core_types__optional m0, kk_tmcmc__trace__rmsmc _this, kk_context_t* _ctx) {
  struct kk_tmcmc__copy_fun2447__t_1* _self = kk_function_alloc_as(struct kk_tmcmc__copy_fun2447__t_1, 7, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc__copy_fun2447_1, kk_context());
  _self->l0 = l0;
  _self->m0 = m0;
  _self->_this = _this;
  return &_self->_base;
}



// lift anonymous function
struct kk_tmcmc__copy_fun2450__t_1 {
  struct kk_function_s _base;
  kk_box_t _fun_unbox_x1936;
};
static kk_function_t kk_tmcmc__copy_fun2450_1(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_tmcmc__new_copy_fun2450_1(kk_box_t _fun_unbox_x1936, kk_context_t* _ctx) {
  struct kk_tmcmc__copy_fun2450__t_1* _self = kk_function_alloc_as(struct kk_tmcmc__copy_fun2450__t_1, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc__copy_fun2450_1, kk_context());
  _self->_fun_unbox_x1936 = _fun_unbox_x1936;
  return &_self->_base;
}



// lift anonymous function
struct kk_tmcmc__copy_fun2453__t_1 {
  struct kk_function_s _base;
  kk_function_t _bv_1940;
};
static kk_box_t kk_tmcmc__copy_fun2453_1(kk_function_t _fself, kk_integer_t _b_1941, kk_context_t* _ctx);
static kk_function_t kk_tmcmc__new_copy_fun2453_1(kk_function_t _bv_1940, kk_context_t* _ctx) {
  struct kk_tmcmc__copy_fun2453__t_1* _self = kk_function_alloc_as(struct kk_tmcmc__copy_fun2453__t_1, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc__copy_fun2453_1, kk_context());
  _self->_bv_1940 = _bv_1940;
  return &_self->_base;
}

static kk_box_t kk_tmcmc__copy_fun2453_1(kk_function_t _fself, kk_integer_t _b_1941, kk_context_t* _ctx) {
  struct kk_tmcmc__copy_fun2453__t_1* _self = kk_function_as(struct kk_tmcmc__copy_fun2453__t_1*, _fself);
  kk_function_t _bv_1940 = _self->_bv_1940; /* (1938) -> 492 1939 */
  kk_drop_match(_self, {kk_function_dup(_bv_1940);}, {}, _ctx)
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _bv_1940, (_bv_1940, kk_integer_box(_b_1941), _ctx));
}
static kk_function_t kk_tmcmc__copy_fun2450_1(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_tmcmc__copy_fun2450__t_1* _self = kk_function_as(struct kk_tmcmc__copy_fun2450__t_1*, _fself);
  kk_box_t _fun_unbox_x1936 = _self->_fun_unbox_x1936; /* 33 */
  kk_drop_match(_self, {kk_box_dup(_fun_unbox_x1936);}, {}, _ctx)
  kk_function_t _bv_1940;
  kk_box_t _x2451;
  kk_function_t _x2452 = kk_function_unbox(_fun_unbox_x1936); /*() -> 1937*/
  _x2451 = kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), _x2452, (_x2452, _ctx)); /*1937*/
  _bv_1940 = kk_function_unbox(_x2451); /*(1938) -> 492 1939*/
  return kk_tmcmc__new_copy_fun2453_1(_bv_1940, _ctx);
}
static kk_box_t kk_tmcmc__copy_fun2447_1(kk_function_t _fself, kk_box_t _b_1943, kk_context_t* _ctx) {
  struct kk_tmcmc__copy_fun2447__t_1* _self = kk_function_as(struct kk_tmcmc__copy_fun2447__t_1*, _fself);
  kk_std_core_types__optional l0 = _self->l0; /* optional<effects-and-types/trace_values> */
  kk_std_core_types__optional m0 = _self->m0; /* optional<() -> ((int) -> 492 491)> */
  kk_tmcmc__trace__rmsmc _this = _self->_this; /* tmcmc/trace_rmsmc<491,492> */
  kk_drop_match(_self, {kk_std_core_types__optional_dup(l0);kk_std_core_types__optional_dup(m0);kk_tmcmc__trace__rmsmc_dup(_this);}, {}, _ctx)
  kk_tmcmc__trace__rmsmc _x2448;
  kk_function_t _x2449;
  if (kk_std_core_types__is_Optional(m0)) {
    kk_box_t _fun_unbox_x1936 = m0._cons.Optional.value;
    _x2449 = kk_tmcmc__new_copy_fun2450_1(_fun_unbox_x1936, _ctx); /*() -> ((int) -> 492 1939)*/
  }
  else {
    kk_function_t _x = _this.m;
    kk_effects_dash_and_dash_types__exp _pat01 = _this.p;
    kk_function_dup(_x);
    _x2449 = _x; /*() -> ((int) -> 492 1939)*/
  }
  kk_effects_dash_and_dash_types__exp _x2454 = kk_effects_dash_and_dash_types__exp_unbox(_b_1943, _ctx); /*effects-and-types/exp*/
  _x2448 = kk_tmcmc__mlift1676_op(_x2449, _this, l0, _x2454, _ctx); /*tmcmc/trace_rmsmc<491,492>*/
  return kk_tmcmc__trace__rmsmc_box(_x2448, _ctx);
}


// lift anonymous function
struct kk_tmcmc__copy_fun2456__t_1 {
  struct kk_function_s _base;
  kk_std_core_types__optional m0;
  kk_std_core_types__optional p0;
  kk_tmcmc__trace__rmsmc _this;
};
static kk_box_t kk_tmcmc__copy_fun2456_1(kk_function_t _fself, kk_box_t _b_1957, kk_context_t* _ctx);
static kk_function_t kk_tmcmc__new_copy_fun2456_1(kk_std_core_types__optional m0, kk_std_core_types__optional p0, kk_tmcmc__trace__rmsmc _this, kk_context_t* _ctx) {
  struct kk_tmcmc__copy_fun2456__t_1* _self = kk_function_alloc_as(struct kk_tmcmc__copy_fun2456__t_1, 7, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc__copy_fun2456_1, kk_context());
  _self->m0 = m0;
  _self->p0 = p0;
  _self->_this = _this;
  return &_self->_base;
}



// lift anonymous function
struct kk_tmcmc__copy_fun2459__t_1 {
  struct kk_function_s _base;
  kk_box_t _fun_unbox_x1949;
};
static kk_function_t kk_tmcmc__copy_fun2459_1(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_tmcmc__new_copy_fun2459_1(kk_box_t _fun_unbox_x1949, kk_context_t* _ctx) {
  struct kk_tmcmc__copy_fun2459__t_1* _self = kk_function_alloc_as(struct kk_tmcmc__copy_fun2459__t_1, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc__copy_fun2459_1, kk_context());
  _self->_fun_unbox_x1949 = _fun_unbox_x1949;
  return &_self->_base;
}



// lift anonymous function
struct kk_tmcmc__copy_fun2462__t_1 {
  struct kk_function_s _base;
  kk_function_t _bv_1953;
};
static kk_box_t kk_tmcmc__copy_fun2462_1(kk_function_t _fself, kk_integer_t _b_1954, kk_context_t* _ctx);
static kk_function_t kk_tmcmc__new_copy_fun2462_1(kk_function_t _bv_1953, kk_context_t* _ctx) {
  struct kk_tmcmc__copy_fun2462__t_1* _self = kk_function_alloc_as(struct kk_tmcmc__copy_fun2462__t_1, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc__copy_fun2462_1, kk_context());
  _self->_bv_1953 = _bv_1953;
  return &_self->_base;
}

static kk_box_t kk_tmcmc__copy_fun2462_1(kk_function_t _fself, kk_integer_t _b_1954, kk_context_t* _ctx) {
  struct kk_tmcmc__copy_fun2462__t_1* _self = kk_function_as(struct kk_tmcmc__copy_fun2462__t_1*, _fself);
  kk_function_t _bv_1953 = _self->_bv_1953; /* (1951) -> 492 1952 */
  kk_drop_match(_self, {kk_function_dup(_bv_1953);}, {}, _ctx)
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _bv_1953, (_bv_1953, kk_integer_box(_b_1954), _ctx));
}
static kk_function_t kk_tmcmc__copy_fun2459_1(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_tmcmc__copy_fun2459__t_1* _self = kk_function_as(struct kk_tmcmc__copy_fun2459__t_1*, _fself);
  kk_box_t _fun_unbox_x1949 = _self->_fun_unbox_x1949; /* 33 */
  kk_drop_match(_self, {kk_box_dup(_fun_unbox_x1949);}, {}, _ctx)
  kk_function_t _bv_1953;
  kk_box_t _x2460;
  kk_function_t _x2461 = kk_function_unbox(_fun_unbox_x1949); /*() -> 1950*/
  _x2460 = kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), _x2461, (_x2461, _ctx)); /*1950*/
  _bv_1953 = kk_function_unbox(_x2460); /*(1951) -> 492 1952*/
  return kk_tmcmc__new_copy_fun2462_1(_bv_1953, _ctx);
}
static kk_box_t kk_tmcmc__copy_fun2456_1(kk_function_t _fself, kk_box_t _b_1957, kk_context_t* _ctx) {
  struct kk_tmcmc__copy_fun2456__t_1* _self = kk_function_as(struct kk_tmcmc__copy_fun2456__t_1*, _fself);
  kk_std_core_types__optional m0 = _self->m0; /* optional<() -> ((int) -> 492 491)> */
  kk_std_core_types__optional p0 = _self->p0; /* optional<effects-and-types/exp> */
  kk_tmcmc__trace__rmsmc _this = _self->_this; /* tmcmc/trace_rmsmc<491,492> */
  kk_drop_match(_self, {kk_std_core_types__optional_dup(m0);kk_std_core_types__optional_dup(p0);kk_tmcmc__trace__rmsmc_dup(_this);}, {}, _ctx)
  kk_tmcmc__trace__rmsmc _x2457;
  kk_function_t _x2458;
  if (kk_std_core_types__is_Optional(m0)) {
    kk_box_t _fun_unbox_x1949 = m0._cons.Optional.value;
    _x2458 = kk_tmcmc__new_copy_fun2459_1(_fun_unbox_x1949, _ctx); /*() -> ((int) -> 492 1952)*/
  }
  else {
    kk_function_t _x0 = _this.m;
    kk_effects_dash_and_dash_types__exp _pat010 = _this.p;
    kk_function_dup(_x0);
    _x2458 = _x0; /*() -> ((int) -> 492 1952)*/
  }
  kk_effects_dash_and_dash_types__exp _x2463;
  if (kk_std_core_types__is_Optional(p0)) {
    kk_box_t _box_x1955 = p0._cons.Optional.value;
    kk_effects_dash_and_dash_types__exp _p_442 = kk_effects_dash_and_dash_types__exp_unbox(_box_x1955, NULL);
    kk_std_core_types__optional_drop(p0, _ctx);
    kk_tmcmc__trace__rmsmc_drop(_this, _ctx);
    _x2463 = _p_442; /*effects-and-types/exp*/
    goto _match2464;
  }
  kk_effects_dash_and_dash_types__exp _x00 = _this.p;
  kk_tmcmc__trace__rmsmc_drop(_this, _ctx);
  _x2463 = _x00; /*effects-and-types/exp*/
  _match2464: ;
  kk_std_core__list _x2466 = kk_std_core__list_unbox(_b_1957, _ctx); /*effects-and-types/trace_values*/
  _x2457 = kk_tmcmc__mlift1675_op(_x2458, _x2463, _x2466, _ctx); /*tmcmc/trace_rmsmc<491,492>*/
  return kk_tmcmc__trace__rmsmc_box(_x2457, _ctx);
}


// lift anonymous function
struct kk_tmcmc__copy_fun2468__t_1 {
  struct kk_function_s _base;
  kk_box_t _fun_unbox_x1963;
};
static kk_function_t kk_tmcmc__copy_fun2468_1(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_tmcmc__new_copy_fun2468_1(kk_box_t _fun_unbox_x1963, kk_context_t* _ctx) {
  struct kk_tmcmc__copy_fun2468__t_1* _self = kk_function_alloc_as(struct kk_tmcmc__copy_fun2468__t_1, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc__copy_fun2468_1, kk_context());
  _self->_fun_unbox_x1963 = _fun_unbox_x1963;
  return &_self->_base;
}



// lift anonymous function
struct kk_tmcmc__copy_fun2471__t_1 {
  struct kk_function_s _base;
  kk_function_t _bv_1967;
};
static kk_box_t kk_tmcmc__copy_fun2471_1(kk_function_t _fself, kk_integer_t _b_1968, kk_context_t* _ctx);
static kk_function_t kk_tmcmc__new_copy_fun2471_1(kk_function_t _bv_1967, kk_context_t* _ctx) {
  struct kk_tmcmc__copy_fun2471__t_1* _self = kk_function_alloc_as(struct kk_tmcmc__copy_fun2471__t_1, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc__copy_fun2471_1, kk_context());
  _self->_bv_1967 = _bv_1967;
  return &_self->_base;
}

static kk_box_t kk_tmcmc__copy_fun2471_1(kk_function_t _fself, kk_integer_t _b_1968, kk_context_t* _ctx) {
  struct kk_tmcmc__copy_fun2471__t_1* _self = kk_function_as(struct kk_tmcmc__copy_fun2471__t_1*, _fself);
  kk_function_t _bv_1967 = _self->_bv_1967; /* (1965) -> 492 1966 */
  kk_drop_match(_self, {kk_function_dup(_bv_1967);}, {}, _ctx)
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _bv_1967, (_bv_1967, kk_integer_box(_b_1968), _ctx));
}
static kk_function_t kk_tmcmc__copy_fun2468_1(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_tmcmc__copy_fun2468__t_1* _self = kk_function_as(struct kk_tmcmc__copy_fun2468__t_1*, _fself);
  kk_box_t _fun_unbox_x1963 = _self->_fun_unbox_x1963; /* 33 */
  kk_drop_match(_self, {kk_box_dup(_fun_unbox_x1963);}, {}, _ctx)
  kk_function_t _bv_1967;
  kk_box_t _x2469;
  kk_function_t _x2470 = kk_function_unbox(_fun_unbox_x1963); /*() -> 1964*/
  _x2469 = kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), _x2470, (_x2470, _ctx)); /*1964*/
  _bv_1967 = kk_function_unbox(_x2469); /*(1965) -> 492 1966*/
  return kk_tmcmc__new_copy_fun2471_1(_bv_1967, _ctx);
}

kk_tmcmc__trace__rmsmc kk_tmcmc__copy_1(kk_tmcmc__trace__rmsmc _this, kk_std_core_types__optional m0, kk_std_core_types__optional p0, kk_std_core_types__optional l0, kk_context_t* _ctx) { /* forall<a,e> (trace_rmsmc<a,e>, m : optional<() -> ((int) -> e a)>, p : optional<effects-and-types/exp>, l : optional<effects-and-types/trace_values>) -> trace_rmsmc<a,e> */ 
  if (kk_yielding(kk_context())) {
    kk_std_core_types__optional_drop(m0, _ctx);
    kk_box_t _x2439 = kk_std_core_hnd_yield_extend(kk_tmcmc__new_copy_fun2440_1(l0, p0, _this, _ctx), _ctx); /*2*/
    return kk_tmcmc__trace__rmsmc_unbox(_x2439, _ctx);
  }
  if (kk_yielding(kk_context())) {
    kk_std_core_types__optional_drop(p0, _ctx);
    kk_box_t _x2446 = kk_std_core_hnd_yield_extend(kk_tmcmc__new_copy_fun2447_1(l0, m0, _this, _ctx), _ctx); /*2*/
    return kk_tmcmc__trace__rmsmc_unbox(_x2446, _ctx);
  }
  if (kk_yielding(kk_context())) {
    kk_std_core_types__optional_drop(l0, _ctx);
    kk_box_t _x2455 = kk_std_core_hnd_yield_extend(kk_tmcmc__new_copy_fun2456_1(m0, p0, _this, _ctx), _ctx); /*2*/
    return kk_tmcmc__trace__rmsmc_unbox(_x2455, _ctx);
  }
  kk_function_t _x2467;
  if (kk_std_core_types__is_Optional(m0)) {
    kk_box_t _fun_unbox_x1963 = m0._cons.Optional.value;
    _x2467 = kk_tmcmc__new_copy_fun2468_1(_fun_unbox_x1963, _ctx); /*() -> ((int) -> 492 1966)*/
  }
  else {
    kk_function_t _x1 = _this.m;
    kk_effects_dash_and_dash_types__exp _pat011 = _this.p;
    kk_function_dup(_x1);
    _x2467 = _x1; /*() -> ((int) -> 492 1966)*/
  }
  kk_effects_dash_and_dash_types__exp _x2472;
  if (kk_std_core_types__is_Optional(p0)) {
    kk_box_t _box_x1969 = p0._cons.Optional.value;
    kk_effects_dash_and_dash_types__exp _p_4420 = kk_effects_dash_and_dash_types__exp_unbox(_box_x1969, NULL);
    kk_std_core_types__optional_drop(p0, _ctx);
    _x2472 = _p_4420; /*effects-and-types/exp*/
    goto _match2473;
  }
  kk_effects_dash_and_dash_types__exp _x01 = _this.p;
  _x2472 = _x01; /*effects-and-types/exp*/
  _match2473: ;
  kk_std_core__list _x2475;
  if (kk_std_core_types__is_Optional(l0)) {
    kk_box_t _box_x1970 = l0._cons.Optional.value;
    kk_std_core__list _l_476 = kk_std_core__list_unbox(_box_x1970, NULL);
    kk_std_core__list_dup(_l_476);
    kk_std_core_types__optional_drop(l0, _ctx);
    kk_tmcmc__trace__rmsmc_drop(_this, _ctx);
    _x2475 = _l_476; /*effects-and-types/trace_values*/
    goto _match2476;
  }
  kk_effects_dash_and_dash_types__exp _pat130 = _this.p;
  kk_std_core__list _x10 = _this.l;
  kk_std_core__list_dup(_x10);
  kk_tmcmc__trace__rmsmc_drop(_this, _ctx);
  _x2475 = _x10; /*effects-and-types/trace_values*/
  _match2476: ;
  return kk_tmcmc__new_RTrace(_x2467, _x2472, _x2475, _ctx);
}
 
// monadic lift

kk_integer_t kk_tmcmc__mlift1678_random__range(kk_integer_t upper__bound, double _y_8, kk_context_t* _ctx) { /* (upper_bound : int, double) -> effects-and-types/sample int */ 
  kk_integer_t _x2478;
  double _x2479;
  double _x2480;
  double _x2481;
  kk_integer_t _x2482 = kk_integer_dup(upper__bound); /*int*/
  _x2481 = kk_integer_as_double(_x2482,kk_context()); /*double*/
  _x2480 = (0x1p0 / _x2481); /*double*/
  _x2479 = (_y_8 / _x2480); /*double*/
  _x2478 = kk_integer_from_double(_x2479,kk_context()); /*int*/
  return kk_integer_mod(_x2478,upper__bound,kk_context());
}


// lift anonymous function
struct kk_tmcmc_random__range_fun2484__t {
  struct kk_function_s _base;
  kk_integer_t upper__bound;
};
static kk_box_t kk_tmcmc_random__range_fun2484(kk_function_t _fself, kk_box_t _b_1978, kk_context_t* _ctx);
static kk_function_t kk_tmcmc_new_random__range_fun2484(kk_integer_t upper__bound, kk_context_t* _ctx) {
  struct kk_tmcmc_random__range_fun2484__t* _self = kk_function_alloc_as(struct kk_tmcmc_random__range_fun2484__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc_random__range_fun2484, kk_context());
  _self->upper__bound = upper__bound;
  return &_self->_base;
}

static kk_box_t kk_tmcmc_random__range_fun2484(kk_function_t _fself, kk_box_t _b_1978, kk_context_t* _ctx) {
  struct kk_tmcmc_random__range_fun2484__t* _self = kk_function_as(struct kk_tmcmc_random__range_fun2484__t*, _fself);
  kk_integer_t upper__bound = _self->upper__bound; /* int */
  kk_drop_match(_self, {kk_integer_dup(upper__bound);}, {}, _ctx)
  kk_integer_t _x2485;
  double _x2486 = kk_double_unbox(_b_1978, _ctx); /*double*/
  _x2485 = kk_tmcmc__mlift1678_random__range(upper__bound, _x2486, _ctx); /*int*/
  return kk_integer_box(_x2485);
}

kk_integer_t kk_tmcmc_random__range(kk_integer_t upper__bound, kk_context_t* _ctx) { /* (upper_bound : int) -> effects-and-types/sample int */ 
  double x_1739 = kk_effects_dash_and_dash_types_sample(_ctx); /*double*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x2483 = kk_std_core_hnd_yield_extend(kk_tmcmc_new_random__range_fun2484(upper__bound, _ctx), _ctx); /*2*/
    return kk_integer_unbox(_x2483);
  }
  kk_integer_t _x2487;
  double _x2488;
  double _x2489;
  double _x2490;
  kk_integer_t _x2491 = kk_integer_dup(upper__bound); /*int*/
  _x2490 = kk_integer_as_double(_x2491,kk_context()); /*double*/
  _x2489 = (0x1p0 / _x2490); /*double*/
  _x2488 = (x_1739 / _x2489); /*double*/
  _x2487 = kk_integer_from_double(_x2488,kk_context()); /*int*/
  return kk_integer_mod(_x2487,upper__bound,kk_context());
}


// lift anonymous function
struct kk_tmcmc_with__randomness_fun2492__t {
  struct kk_function_s _base;
  kk_function_t model;
};
static kk_box_t kk_tmcmc_with__randomness_fun2492(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_tmcmc_new_with__randomness_fun2492(kk_function_t model, kk_context_t* _ctx) {
  struct kk_tmcmc_with__randomness_fun2492__t* _self = kk_function_alloc_as(struct kk_tmcmc_with__randomness_fun2492__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc_with__randomness_fun2492, kk_context());
  _self->model = model;
  return &_self->_base;
}



// lift anonymous function
struct kk_tmcmc_with__randomness_fun2496__t {
  struct kk_function_s _base;
  kk_function_t model;
};
static kk_box_t kk_tmcmc_with__randomness_fun2496(kk_function_t _fself, kk_box_t _b_1984, kk_context_t* _ctx);
static kk_function_t kk_tmcmc_new_with__randomness_fun2496(kk_function_t model, kk_context_t* _ctx) {
  struct kk_tmcmc_with__randomness_fun2496__t* _self = kk_function_alloc_as(struct kk_tmcmc_with__randomness_fun2496__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc_with__randomness_fun2496, kk_context());
  _self->model = model;
  return &_self->_base;
}



// lift anonymous function
struct kk_tmcmc_with__randomness_fun2497__t {
  struct kk_function_s _base;
  kk_function_t model;
};
static kk_box_t kk_tmcmc_with__randomness_fun2497(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_tmcmc_new_with__randomness_fun2497(kk_function_t model, kk_context_t* _ctx) {
  struct kk_tmcmc_with__randomness_fun2497__t* _self = kk_function_alloc_as(struct kk_tmcmc_with__randomness_fun2497__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc_with__randomness_fun2497, kk_context());
  _self->model = model;
  return &_self->_base;
}

static kk_box_t kk_tmcmc_with__randomness_fun2497(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_tmcmc_with__randomness_fun2497__t* _self = kk_function_as(struct kk_tmcmc_with__randomness_fun2497__t*, _fself);
  kk_function_t model = _self->model; /* () -> <effects-and-types/sample,effects-and-types/score|736> 735 */
  kk_drop_match(_self, {kk_function_dup(model);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x2498;
  kk_effects_dash_and_dash_types__exp _x2499 = kk_effects_dash_and_dash_types__new_Exp(0x0p+0, _ctx); /*effects-and-types/exp*/
  _x2498 = kk_handlers_weighted(_x2499, model, _ctx); /*(effects-and-types/exp, 0)*/
  return kk_std_core_types__tuple2__box(_x2498, _ctx);
}
static kk_box_t kk_tmcmc_with__randomness_fun2496(kk_function_t _fself, kk_box_t _b_1984, kk_context_t* _ctx) {
  struct kk_tmcmc_with__randomness_fun2496__t* _self = kk_function_as(struct kk_tmcmc_with__randomness_fun2496__t*, _fself);
  kk_function_t model = _self->model; /* () -> <effects-and-types/sample,effects-and-types/score|736> 735 */
  kk_drop_match(_self, {kk_function_dup(model);}, {}, _ctx)
  size_t _x2500 = kk_size_unbox(_b_1984, _ctx); /*std/core/hnd/ev-index*/
  return kk_handlers__mlift2541_replay(kk_tmcmc_new_with__randomness_fun2497(model, _ctx), _x2500, _ctx);
}


// lift anonymous function
struct kk_tmcmc_with__randomness_fun2501__t {
  struct kk_function_s _base;
  kk_function_t model;
};
static kk_box_t kk_tmcmc_with__randomness_fun2501(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_tmcmc_new_with__randomness_fun2501(kk_function_t model, kk_context_t* _ctx) {
  struct kk_tmcmc_with__randomness_fun2501__t* _self = kk_function_alloc_as(struct kk_tmcmc_with__randomness_fun2501__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc_with__randomness_fun2501, kk_context());
  _self->model = model;
  return &_self->_base;
}

static kk_box_t kk_tmcmc_with__randomness_fun2501(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_tmcmc_with__randomness_fun2501__t* _self = kk_function_as(struct kk_tmcmc_with__randomness_fun2501__t*, _fself);
  kk_function_t model = _self->model; /* () -> <effects-and-types/sample,effects-and-types/score|736> 735 */
  kk_drop_match(_self, {kk_function_dup(model);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x2502;
  kk_effects_dash_and_dash_types__exp _x2503 = kk_effects_dash_and_dash_types__new_Exp(0x0p+0, _ctx); /*effects-and-types/exp*/
  _x2502 = kk_handlers_weighted(_x2503, model, _ctx); /*(effects-and-types/exp, 0)*/
  return kk_std_core_types__tuple2__box(_x2502, _ctx);
}
static kk_box_t kk_tmcmc_with__randomness_fun2492(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_tmcmc_with__randomness_fun2492__t* _self = kk_function_as(struct kk_tmcmc_with__randomness_fun2492__t*, _fself);
  kk_function_t model = _self->model; /* () -> <effects-and-types/sample,effects-and-types/score|736> 735 */
  kk_drop_match(_self, {kk_function_dup(model);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x2493;
  size_t x_2685;
  kk_std_core_hnd__htag _x2494 = kk_std_core_hnd__htag_dup(kk_effects_dash_and_dash_types__tag_sample); /*std/core/hnd/htag<effects-and-types/.hnd-sample>*/
  x_2685 = kk_std_core_hnd__evv_index(_x2494, _ctx); /*std/core/hnd/ev-index*/
  kk_box_t _x2495;
  if (kk_yielding(kk_context())) {
    _x2495 = kk_std_core_hnd_yield_extend(kk_tmcmc_new_with__randomness_fun2496(model, _ctx), _ctx); /*2*/
  }
  else {
    _x2495 = kk_handlers__mlift2541_replay(kk_tmcmc_new_with__randomness_fun2501(model, _ctx), x_2685, _ctx); /*2*/
  }
  _x2493 = kk_std_core_types__tuple2__unbox(_x2495, _ctx); /*(effects-and-types/exp, 735)*/
  return kk_std_core_types__tuple2__box(_x2493, _ctx);
}

kk_std_core_types__tuple2_ kk_tmcmc_with__randomness(kk_function_t model, kk_std_core__list trace__values, kk_context_t* _ctx) { /* forall<a,e> (model : () -> <effects-and-types/sample,effects-and-types/score|e> a, trace_values : effects-and-types/trace_values) -> <effects-and-types/sample|e> (effects-and-types/trace_values, (effects-and-types/exp, a)) */ 
  return kk_handlers_replayx(trace__values, kk_tmcmc_new_with__randomness_fun2492(model, _ctx), _ctx);
}


// lift anonymous function
struct kk_tmcmc_with__randomness__rmsmc_fun2504__t {
  struct kk_function_s _base;
  kk_function_t model;
  kk_std_core__list trace__values;
};
static kk_std_core_types__tuple2_ kk_tmcmc_with__randomness__rmsmc_fun2504(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_tmcmc_new_with__randomness__rmsmc_fun2504(kk_function_t model, kk_std_core__list trace__values, kk_context_t* _ctx) {
  struct kk_tmcmc_with__randomness__rmsmc_fun2504__t* _self = kk_function_alloc_as(struct kk_tmcmc_with__randomness__rmsmc_fun2504__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc_with__randomness__rmsmc_fun2504, kk_context());
  _self->model = model;
  _self->trace__values = trace__values;
  return &_self->_base;
}



// lift anonymous function
struct kk_tmcmc_with__randomness__rmsmc_fun2506__t {
  struct kk_function_s _base;
  kk_function_t model;
  kk_std_core__list trace__values;
};
static kk_box_t kk_tmcmc_with__randomness__rmsmc_fun2506(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_tmcmc_new_with__randomness__rmsmc_fun2506(kk_function_t model, kk_std_core__list trace__values, kk_context_t* _ctx) {
  struct kk_tmcmc_with__randomness__rmsmc_fun2506__t* _self = kk_function_alloc_as(struct kk_tmcmc_with__randomness__rmsmc_fun2506__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc_with__randomness__rmsmc_fun2506, kk_context());
  _self->model = model;
  _self->trace__values = trace__values;
  return &_self->_base;
}



// lift anonymous function
struct kk_tmcmc_with__randomness__rmsmc_fun2510__t {
  struct kk_function_s _base;
  kk_function_t model;
};
static kk_box_t kk_tmcmc_with__randomness__rmsmc_fun2510(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_tmcmc_new_with__randomness__rmsmc_fun2510(kk_function_t model, kk_context_t* _ctx) {
  struct kk_tmcmc_with__randomness__rmsmc_fun2510__t* _self = kk_function_alloc_as(struct kk_tmcmc_with__randomness__rmsmc_fun2510__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc_with__randomness__rmsmc_fun2510, kk_context());
  _self->model = model;
  return &_self->_base;
}



// lift anonymous function
struct kk_tmcmc_with__randomness__rmsmc_fun2512__t {
  struct kk_function_s _base;
  kk_function_t _bv_2000;
};
static kk_box_t kk_tmcmc_with__randomness__rmsmc_fun2512(kk_function_t _fself, kk_box_t _b_2001, kk_context_t* _ctx);
static kk_function_t kk_tmcmc_new_with__randomness__rmsmc_fun2512(kk_function_t _bv_2000, kk_context_t* _ctx) {
  struct kk_tmcmc_with__randomness__rmsmc_fun2512__t* _self = kk_function_alloc_as(struct kk_tmcmc_with__randomness__rmsmc_fun2512__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc_with__randomness__rmsmc_fun2512, kk_context());
  _self->_bv_2000 = _bv_2000;
  return &_self->_base;
}

static kk_box_t kk_tmcmc_with__randomness__rmsmc_fun2512(kk_function_t _fself, kk_box_t _b_2001, kk_context_t* _ctx) {
  struct kk_tmcmc_with__randomness__rmsmc_fun2512__t* _self = kk_function_as(struct kk_tmcmc_with__randomness__rmsmc_fun2512__t*, _fself);
  kk_function_t _bv_2000 = _self->_bv_2000; /* (int) -> <exn,effects-and-types/yield,effects-and-types/score,effects-and-types/sample,effects-and-types/sample|793> 792 */
  kk_drop_match(_self, {kk_function_dup(_bv_2000);}, {}, _ctx)
  kk_integer_t _x2513 = kk_integer_unbox(_b_2001); /*int*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_context_t*), _bv_2000, (_bv_2000, _x2513, _ctx));
}
static kk_box_t kk_tmcmc_with__randomness__rmsmc_fun2510(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_tmcmc_with__randomness__rmsmc_fun2510__t* _self = kk_function_as(struct kk_tmcmc_with__randomness__rmsmc_fun2510__t*, _fself);
  kk_function_t model = _self->model; /* () -> ((int) -> <exn,effects-and-types/yield,effects-and-types/score,effects-and-types/sample,effects-and-types/sample|793> 792) */
  kk_drop_match(_self, {kk_function_dup(model);}, {}, _ctx)
  kk_function_t _x2511;
  kk_function_t _bv_2000 = kk_function_call(kk_function_t, (kk_function_t, kk_context_t*), model, (model, _ctx)); /*(int) -> <exn,effects-and-types/yield,effects-and-types/score,effects-and-types/sample,effects-and-types/sample|793> 792*/;
  _x2511 = kk_tmcmc_new_with__randomness__rmsmc_fun2512(_bv_2000, _ctx); /*(1998) -> <exn,effects-and-types/yield,effects-and-types/score,effects-and-types/sample,effects-and-types/sample|793> 792*/
  return kk_function_box(_x2511);
}


// lift anonymous function
struct kk_tmcmc_with__randomness__rmsmc_fun2514__t {
  struct kk_function_s _base;
  kk_function_t _bv_2004;
};
static kk_box_t kk_tmcmc_with__randomness__rmsmc_fun2514(kk_function_t _fself, kk_integer_t _b_2005, kk_context_t* _ctx);
static kk_function_t kk_tmcmc_new_with__randomness__rmsmc_fun2514(kk_function_t _bv_2004, kk_context_t* _ctx) {
  struct kk_tmcmc_with__randomness__rmsmc_fun2514__t* _self = kk_function_alloc_as(struct kk_tmcmc_with__randomness__rmsmc_fun2514__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc_with__randomness__rmsmc_fun2514, kk_context());
  _self->_bv_2004 = _bv_2004;
  return &_self->_base;
}

static kk_box_t kk_tmcmc_with__randomness__rmsmc_fun2514(kk_function_t _fself, kk_integer_t _b_2005, kk_context_t* _ctx) {
  struct kk_tmcmc_with__randomness__rmsmc_fun2514__t* _self = kk_function_as(struct kk_tmcmc_with__randomness__rmsmc_fun2514__t*, _fself);
  kk_function_t _bv_2004 = _self->_bv_2004; /* (2002) -> 2003 */
  kk_drop_match(_self, {kk_function_dup(_bv_2004);}, {}, _ctx)
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _bv_2004, (_bv_2004, kk_integer_box(_b_2005), _ctx));
}
static kk_box_t kk_tmcmc_with__randomness__rmsmc_fun2506(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_tmcmc_with__randomness__rmsmc_fun2506__t* _self = kk_function_as(struct kk_tmcmc_with__randomness__rmsmc_fun2506__t*, _fself);
  kk_function_t model = _self->model; /* () -> ((int) -> <exn,effects-and-types/yield,effects-and-types/score,effects-and-types/sample,effects-and-types/sample|793> 792) */
  kk_std_core__list trace__values = _self->trace__values; /* effects-and-types/trace_values */
  kk_drop_match(_self, {kk_function_dup(model);kk_std_core__list_dup(trace__values);}, {}, _ctx)
  kk_function_t _x2508;
  kk_function_t _bv_2004;
  kk_box_t _x2509 = kk_std_core_hnd__open_none0(kk_tmcmc_new_with__randomness__rmsmc_fun2510(model, _ctx), _ctx); /*1*/
  _bv_2004 = kk_function_unbox(_x2509); /*(2002) -> 2003*/
  _x2508 = kk_tmcmc_new_with__randomness__rmsmc_fun2514(_bv_2004, _ctx); /*(int) -> 2003*/
  kk_integer_t _x2507 = kk_std_core_length_1(trace__values, _ctx); /*int*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_context_t*), _x2508, (_x2508, _x2507, _ctx));
}
static kk_std_core_types__tuple2_ kk_tmcmc_with__randomness__rmsmc_fun2504(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_tmcmc_with__randomness__rmsmc_fun2504__t* _self = kk_function_as(struct kk_tmcmc_with__randomness__rmsmc_fun2504__t*, _fself);
  kk_function_t model = _self->model; /* () -> ((int) -> <exn,effects-and-types/yield,effects-and-types/score,effects-and-types/sample,effects-and-types/sample|793> 792) */
  kk_std_core__list trace__values = _self->trace__values; /* effects-and-types/trace_values */
  kk_drop_match(_self, {kk_function_dup(model);kk_std_core__list_dup(trace__values);}, {}, _ctx)
  kk_effects_dash_and_dash_types__exp _x2505 = kk_effects_dash_and_dash_types__new_Exp(0x0p+0, _ctx); /*effects-and-types/exp*/
  return kk_handlers_weighted(_x2505, kk_tmcmc_new_with__randomness__rmsmc_fun2506(model, trace__values, _ctx), _ctx);
}


// lift anonymous function
struct kk_tmcmc_with__randomness__rmsmc_fun2515__t {
  struct kk_function_s _base;
  kk_function_t action_1746;
};
static kk_box_t kk_tmcmc_with__randomness__rmsmc_fun2515(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_tmcmc_new_with__randomness__rmsmc_fun2515(kk_function_t action_1746, kk_context_t* _ctx) {
  struct kk_tmcmc_with__randomness__rmsmc_fun2515__t* _self = kk_function_alloc_as(struct kk_tmcmc_with__randomness__rmsmc_fun2515__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc_with__randomness__rmsmc_fun2515, kk_context());
  _self->action_1746 = action_1746;
  return &_self->_base;
}



// lift anonymous function
struct kk_tmcmc_with__randomness__rmsmc_fun2519__t {
  struct kk_function_s _base;
  kk_function_t action_1746;
};
static kk_box_t kk_tmcmc_with__randomness__rmsmc_fun2519(kk_function_t _fself, kk_box_t _b_2010, kk_context_t* _ctx);
static kk_function_t kk_tmcmc_new_with__randomness__rmsmc_fun2519(kk_function_t action_1746, kk_context_t* _ctx) {
  struct kk_tmcmc_with__randomness__rmsmc_fun2519__t* _self = kk_function_alloc_as(struct kk_tmcmc_with__randomness__rmsmc_fun2519__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc_with__randomness__rmsmc_fun2519, kk_context());
  _self->action_1746 = action_1746;
  return &_self->_base;
}



// lift anonymous function
struct kk_tmcmc_with__randomness__rmsmc_fun2520__t {
  struct kk_function_s _base;
  kk_function_t action_1746;
};
static kk_box_t kk_tmcmc_with__randomness__rmsmc_fun2520(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_tmcmc_new_with__randomness__rmsmc_fun2520(kk_function_t action_1746, kk_context_t* _ctx) {
  struct kk_tmcmc_with__randomness__rmsmc_fun2520__t* _self = kk_function_alloc_as(struct kk_tmcmc_with__randomness__rmsmc_fun2520__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc_with__randomness__rmsmc_fun2520, kk_context());
  _self->action_1746 = action_1746;
  return &_self->_base;
}

static kk_box_t kk_tmcmc_with__randomness__rmsmc_fun2520(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_tmcmc_with__randomness__rmsmc_fun2520__t* _self = kk_function_as(struct kk_tmcmc_with__randomness__rmsmc_fun2520__t*, _fself);
  kk_function_t action_1746 = _self->action_1746; /* () -> <effects-and-types/sample,exn,effects-and-types/sample,effects-and-types/yield|793> (effects-and-types/exp, 792) */
  kk_drop_match(_self, {kk_function_dup(action_1746);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x2521 = kk_function_call(kk_std_core_types__tuple2_, (kk_function_t, kk_context_t*), action_1746, (action_1746, _ctx)); /*(effects-and-types/exp, 792)*/
  return kk_std_core_types__tuple2__box(_x2521, _ctx);
}
static kk_box_t kk_tmcmc_with__randomness__rmsmc_fun2519(kk_function_t _fself, kk_box_t _b_2010, kk_context_t* _ctx) {
  struct kk_tmcmc_with__randomness__rmsmc_fun2519__t* _self = kk_function_as(struct kk_tmcmc_with__randomness__rmsmc_fun2519__t*, _fself);
  kk_function_t action_1746 = _self->action_1746; /* () -> <effects-and-types/sample,exn,effects-and-types/sample,effects-and-types/yield|793> (effects-and-types/exp, 792) */
  kk_drop_match(_self, {kk_function_dup(action_1746);}, {}, _ctx)
  size_t _x2522 = kk_size_unbox(_b_2010, _ctx); /*std/core/hnd/ev-index*/
  return kk_handlers__mlift2541_replay(kk_tmcmc_new_with__randomness__rmsmc_fun2520(action_1746, _ctx), _x2522, _ctx);
}


// lift anonymous function
struct kk_tmcmc_with__randomness__rmsmc_fun2523__t {
  struct kk_function_s _base;
  kk_function_t action_1746;
};
static kk_box_t kk_tmcmc_with__randomness__rmsmc_fun2523(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_tmcmc_new_with__randomness__rmsmc_fun2523(kk_function_t action_1746, kk_context_t* _ctx) {
  struct kk_tmcmc_with__randomness__rmsmc_fun2523__t* _self = kk_function_alloc_as(struct kk_tmcmc_with__randomness__rmsmc_fun2523__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc_with__randomness__rmsmc_fun2523, kk_context());
  _self->action_1746 = action_1746;
  return &_self->_base;
}

static kk_box_t kk_tmcmc_with__randomness__rmsmc_fun2523(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_tmcmc_with__randomness__rmsmc_fun2523__t* _self = kk_function_as(struct kk_tmcmc_with__randomness__rmsmc_fun2523__t*, _fself);
  kk_function_t action_1746 = _self->action_1746; /* () -> <effects-and-types/sample,exn,effects-and-types/sample,effects-and-types/yield|793> (effects-and-types/exp, 792) */
  kk_drop_match(_self, {kk_function_dup(action_1746);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x2524 = kk_function_call(kk_std_core_types__tuple2_, (kk_function_t, kk_context_t*), action_1746, (action_1746, _ctx)); /*(effects-and-types/exp, 792)*/
  return kk_std_core_types__tuple2__box(_x2524, _ctx);
}
static kk_box_t kk_tmcmc_with__randomness__rmsmc_fun2515(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_tmcmc_with__randomness__rmsmc_fun2515__t* _self = kk_function_as(struct kk_tmcmc_with__randomness__rmsmc_fun2515__t*, _fself);
  kk_function_t action_1746 = _self->action_1746; /* () -> <effects-and-types/sample,exn,effects-and-types/sample,effects-and-types/yield|793> (effects-and-types/exp, 792) */
  kk_drop_match(_self, {kk_function_dup(action_1746);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x2516;
  size_t x_2685;
  kk_std_core_hnd__htag _x2517 = kk_std_core_hnd__htag_dup(kk_effects_dash_and_dash_types__tag_sample); /*std/core/hnd/htag<effects-and-types/.hnd-sample>*/
  x_2685 = kk_std_core_hnd__evv_index(_x2517, _ctx); /*std/core/hnd/ev-index*/
  kk_box_t _x2518;
  if (kk_yielding(kk_context())) {
    _x2518 = kk_std_core_hnd_yield_extend(kk_tmcmc_new_with__randomness__rmsmc_fun2519(action_1746, _ctx), _ctx); /*2*/
  }
  else {
    _x2518 = kk_handlers__mlift2541_replay(kk_tmcmc_new_with__randomness__rmsmc_fun2523(action_1746, _ctx), x_2685, _ctx); /*2*/
  }
  _x2516 = kk_std_core_types__tuple2__unbox(_x2518, _ctx); /*(effects-and-types/exp, 792)*/
  return kk_std_core_types__tuple2__box(_x2516, _ctx);
}

kk_std_core_types__tuple2_ kk_tmcmc_with__randomness__rmsmc(kk_function_t model, kk_std_core__list trace__values, kk_context_t* _ctx) { /* forall<a,e> (model : () -> ((int) -> <exn,effects-and-types/yield,effects-and-types/score,effects-and-types/sample,effects-and-types/sample|e> a), trace_values : effects-and-types/trace_values) -> <effects-and-types/sample,effects-and-types/sample,exn,effects-and-types/yield|e> (effects-and-types/trace_values, (effects-and-types/exp, a)) */ 
  kk_function_t action_1746;
  kk_std_core__list_dup(trace__values);
  action_1746 = kk_tmcmc_new_with__randomness__rmsmc_fun2504(model, trace__values, _ctx); /*() -> <effects-and-types/sample,exn,effects-and-types/sample,effects-and-types/yield|793> (effects-and-types/exp, 792)*/
  return kk_handlers_replayx(trace__values, kk_tmcmc_new_with__randomness__rmsmc_fun2515(action_1746, _ctx), _ctx);
}
 
// monadic lift

kk_std_core__list kk_tmcmc__mlift1679_perturb__trace(kk_std_core__list l1, double _y_15, kk_context_t* _ctx) { /* (l1 : list<double>, double) -> effects-and-types/sample list<double> */ 
  kk_std_core__list ys_1748 = kk_std_core__new_Cons(kk_reuse_null, kk_double_box(_y_15, _ctx), kk_std_core__new_Nil(_ctx), _ctx); /*list<double>*/;
  return kk_std_core_append(l1, ys_1748, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_tmcmc__mlift1680_perturb__trace_fun2530__t {
  struct kk_function_s _base;
  kk_std_core__list l1;
};
static kk_box_t kk_tmcmc__mlift1680_perturb__trace_fun2530(kk_function_t _fself, kk_box_t _b_2031, kk_context_t* _ctx);
static kk_function_t kk_tmcmc__new_mlift1680_perturb__trace_fun2530(kk_std_core__list l1, kk_context_t* _ctx) {
  struct kk_tmcmc__mlift1680_perturb__trace_fun2530__t* _self = kk_function_alloc_as(struct kk_tmcmc__mlift1680_perturb__trace_fun2530__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc__mlift1680_perturb__trace_fun2530, kk_context());
  _self->l1 = l1;
  return &_self->_base;
}

static kk_box_t kk_tmcmc__mlift1680_perturb__trace_fun2530(kk_function_t _fself, kk_box_t _b_2031, kk_context_t* _ctx) {
  struct kk_tmcmc__mlift1680_perturb__trace_fun2530__t* _self = kk_function_as(struct kk_tmcmc__mlift1680_perturb__trace_fun2530__t*, _fself);
  kk_std_core__list l1 = _self->l1; /* list<double> */
  kk_drop_match(_self, {kk_std_core__list_dup(l1);}, {}, _ctx)
  kk_std_core__list _x2531;
  double _x2532 = kk_double_unbox(_b_2031, _ctx); /*double*/
  _x2531 = kk_tmcmc__mlift1679_perturb__trace(l1, _x2532, _ctx); /*list<double>*/
  return kk_std_core__list_box(_x2531, _ctx);
}

kk_std_core__list kk_tmcmc__mlift1680_perturb__trace(kk_std_core__list trace__values, kk_integer_t perturb__index, kk_context_t* _ctx) { /* (trace_values : effects-and-types/trace_values, perturb_index : int) -> effects-and-types/sample list<double> */ 
  kk_std_core_types__tuple2_ div__trace = kk_std_core_split(trace__values, perturb__index, _ctx); /*(list<double>, list<double>)*/;
  kk_box_t _box_x2027 = div__trace.fst;
  kk_box_t _box_x2028 = div__trace.snd;
  kk_std_core__list l1 = kk_std_core__list_unbox(_box_x2027, NULL);
  kk_std_core__list _pat0 = kk_std_core__list_unbox(_box_x2028, NULL);
  if (kk_std_core__is_Cons(_pat0)) {
    struct kk_std_core_Cons* _con2527 = kk_std_core__as_Cons(_pat0);
    kk_box_t _box_x2029 = _con2527->head;
    kk_std_core__list_dup(l1);
    kk_std_core_types__tuple2__drop(div__trace, _ctx);
    double x_1749 = kk_effects_dash_and_dash_types_sample(_ctx); /*double*/;
    if (kk_yielding(kk_context())) {
      kk_box_t _x2529 = kk_std_core_hnd_yield_extend(kk_tmcmc__new_mlift1680_perturb__trace_fun2530(l1, _ctx), _ctx); /*2*/
      return kk_std_core__list_unbox(_x2529, _ctx);
    }
    return kk_tmcmc__mlift1679_perturb__trace(l1, x_1749, _ctx);
  }
  kk_box_t _box_x2032 = div__trace.fst;
  kk_box_t _box_x2033 = div__trace.snd;
  kk_std_core__list l10 = kk_std_core__list_unbox(_box_x2032, NULL);
  kk_std_core__list l2 = kk_std_core__list_unbox(_box_x2033, NULL);
  kk_std_core__list_dup(l10);
  kk_std_core__list_dup(l2);
  kk_std_core_types__tuple2__drop(div__trace, _ctx);
  return kk_std_core__lp__plus__plus__rp_(l10, l2, _ctx);
}


// lift anonymous function
struct kk_tmcmc_perturb__trace_fun2537__t {
  struct kk_function_s _base;
  kk_integer_t upper__bound_1754;
};
static kk_box_t kk_tmcmc_perturb__trace_fun2537(kk_function_t _fself, kk_box_t _b_2037, kk_context_t* _ctx);
static kk_function_t kk_tmcmc_new_perturb__trace_fun2537(kk_integer_t upper__bound_1754, kk_context_t* _ctx) {
  struct kk_tmcmc_perturb__trace_fun2537__t* _self = kk_function_alloc_as(struct kk_tmcmc_perturb__trace_fun2537__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc_perturb__trace_fun2537, kk_context());
  _self->upper__bound_1754 = upper__bound_1754;
  return &_self->_base;
}

static kk_box_t kk_tmcmc_perturb__trace_fun2537(kk_function_t _fself, kk_box_t _b_2037, kk_context_t* _ctx) {
  struct kk_tmcmc_perturb__trace_fun2537__t* _self = kk_function_as(struct kk_tmcmc_perturb__trace_fun2537__t*, _fself);
  kk_integer_t upper__bound_1754 = _self->upper__bound_1754; /* int */
  kk_drop_match(_self, {kk_integer_dup(upper__bound_1754);}, {}, _ctx)
  kk_integer_t _x2538;
  double _x2539 = kk_double_unbox(_b_2037, _ctx); /*double*/
  _x2538 = kk_tmcmc__mlift1678_random__range(upper__bound_1754, _x2539, _ctx); /*int*/
  return kk_integer_box(_x2538);
}


// lift anonymous function
struct kk_tmcmc_perturb__trace_fun2546__t {
  struct kk_function_s _base;
  kk_std_core__list trace__values;
};
static kk_box_t kk_tmcmc_perturb__trace_fun2546(kk_function_t _fself, kk_box_t _b_2041, kk_context_t* _ctx);
static kk_function_t kk_tmcmc_new_perturb__trace_fun2546(kk_std_core__list trace__values, kk_context_t* _ctx) {
  struct kk_tmcmc_perturb__trace_fun2546__t* _self = kk_function_alloc_as(struct kk_tmcmc_perturb__trace_fun2546__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc_perturb__trace_fun2546, kk_context());
  _self->trace__values = trace__values;
  return &_self->_base;
}

static kk_box_t kk_tmcmc_perturb__trace_fun2546(kk_function_t _fself, kk_box_t _b_2041, kk_context_t* _ctx) {
  struct kk_tmcmc_perturb__trace_fun2546__t* _self = kk_function_as(struct kk_tmcmc_perturb__trace_fun2546__t*, _fself);
  kk_std_core__list trace__values = _self->trace__values; /* effects-and-types/trace_values */
  kk_drop_match(_self, {kk_std_core__list_dup(trace__values);}, {}, _ctx)
  kk_std_core__list _x2547;
  kk_integer_t _x2548 = kk_integer_unbox(_b_2041); /*int*/
  _x2547 = kk_tmcmc__mlift1680_perturb__trace(trace__values, _x2548, _ctx); /*list<double>*/
  return kk_std_core__list_box(_x2547, _ctx);
}


// lift anonymous function
struct kk_tmcmc_perturb__trace_fun2554__t {
  struct kk_function_s _base;
  kk_std_core__list l1;
};
static kk_box_t kk_tmcmc_perturb__trace_fun2554(kk_function_t _fself, kk_box_t _b_2046, kk_context_t* _ctx);
static kk_function_t kk_tmcmc_new_perturb__trace_fun2554(kk_std_core__list l1, kk_context_t* _ctx) {
  struct kk_tmcmc_perturb__trace_fun2554__t* _self = kk_function_alloc_as(struct kk_tmcmc_perturb__trace_fun2554__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc_perturb__trace_fun2554, kk_context());
  _self->l1 = l1;
  return &_self->_base;
}

static kk_box_t kk_tmcmc_perturb__trace_fun2554(kk_function_t _fself, kk_box_t _b_2046, kk_context_t* _ctx) {
  struct kk_tmcmc_perturb__trace_fun2554__t* _self = kk_function_as(struct kk_tmcmc_perturb__trace_fun2554__t*, _fself);
  kk_std_core__list l1 = _self->l1; /* list<double> */
  kk_drop_match(_self, {kk_std_core__list_dup(l1);}, {}, _ctx)
  kk_std_core__list _x2555;
  double _x2556 = kk_double_unbox(_b_2046, _ctx); /*double*/
  _x2555 = kk_tmcmc__mlift1679_perturb__trace(l1, _x2556, _ctx); /*list<double>*/
  return kk_std_core__list_box(_x2555, _ctx);
}

kk_std_core__list kk_tmcmc_perturb__trace(kk_std_core__list trace__values, kk_context_t* _ctx) { /* (trace_values : effects-and-types/trace_values) -> effects-and-types/sample effects-and-types/trace_values */ 
  kk_integer_t x_1751;
  kk_integer_t upper__bound_1754;
  kk_std_core__list _x2535 = kk_std_core__list_dup(trace__values); /*effects-and-types/trace_values*/
  upper__bound_1754 = kk_std_core_length_1(_x2535, _ctx); /*int*/
  double x0_1755 = kk_effects_dash_and_dash_types_sample(_ctx); /*double*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x2536 = kk_std_core_hnd_yield_extend(kk_tmcmc_new_perturb__trace_fun2537(upper__bound_1754, _ctx), _ctx); /*2*/
    x_1751 = kk_integer_unbox(_x2536); /*int*/
  }
  else {
    kk_integer_t _x2540;
    double _x2541;
    double _x2542;
    double _x2543;
    kk_integer_t _x2544 = kk_integer_dup(upper__bound_1754); /*int*/
    _x2543 = kk_integer_as_double(_x2544,kk_context()); /*double*/
    _x2542 = (0x1p0 / _x2543); /*double*/
    _x2541 = (x0_1755 / _x2542); /*double*/
    _x2540 = kk_integer_from_double(_x2541,kk_context()); /*int*/
    x_1751 = kk_integer_mod(_x2540,upper__bound_1754,kk_context()); /*int*/
  }
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_1751, _ctx);
    kk_box_t _x2545 = kk_std_core_hnd_yield_extend(kk_tmcmc_new_perturb__trace_fun2546(trace__values, _ctx), _ctx); /*2*/
    return kk_std_core__list_unbox(_x2545, _ctx);
  }
  kk_std_core_types__tuple2_ div__trace = kk_std_core_split(trace__values, x_1751, _ctx); /*(list<double>, list<double>)*/;
  kk_box_t _box_x2042 = div__trace.fst;
  kk_box_t _box_x2043 = div__trace.snd;
  kk_std_core__list l1 = kk_std_core__list_unbox(_box_x2042, NULL);
  kk_std_core__list _pat01 = kk_std_core__list_unbox(_box_x2043, NULL);
  if (kk_std_core__is_Cons(_pat01)) {
    struct kk_std_core_Cons* _con2551 = kk_std_core__as_Cons(_pat01);
    kk_box_t _box_x2044 = _con2551->head;
    kk_reuse_t _ru_2299 = kk_reuse_null; /*reuse*/;
    kk_std_core__list_dup(l1);
    _ru_2299 = kk_reuse_null;
    kk_std_core_types__tuple2__drop(div__trace, _ctx);
    double x1_1760 = kk_effects_dash_and_dash_types_sample(_ctx); /*double*/;
    if (kk_yielding(kk_context())) {
      kk_reuse_drop(_ru_2299, _ctx);
      kk_box_t _x2553 = kk_std_core_hnd_yield_extend(kk_tmcmc_new_perturb__trace_fun2554(l1, _ctx), _ctx); /*2*/
      return kk_std_core__list_unbox(_x2553, _ctx);
    }
    kk_std_core__list ys_1765 = kk_std_core__new_Cons(_ru_2299, kk_double_box(x1_1760, _ctx), kk_std_core__new_Nil(_ctx), _ctx); /*list<double>*/;
    return kk_std_core_append(l1, ys_1765, _ctx);
  }
  kk_box_t _box_x2051 = div__trace.fst;
  kk_box_t _box_x2052 = div__trace.snd;
  kk_std_core__list l10 = kk_std_core__list_unbox(_box_x2051, NULL);
  kk_std_core__list l2 = kk_std_core__list_unbox(_box_x2052, NULL);
  kk_std_core__list_dup(l10);
  kk_std_core__list_dup(l2);
  kk_std_core_types__tuple2__drop(div__trace, _ctx);
  return kk_std_core__lp__plus__plus__rp_(l10, l2, _ctx);
}
 
// monadic lift

kk_tmcmc__trace kk_tmcmc__mlift1681_mh__step(kk_box_t b, kk_function_t model, kk_std_core__list new__trace, kk_effects_dash_and_dash_types__exp p2, kk_tmcmc__trace trace, bool accept, kk_context_t* _ctx) { /* forall<a,e> (b : a, model : () -> <effects-and-types/sample,effects-and-types/score|e> a, new_trace : effects-and-types/trace_values, p2 : effects-and-types/exp, trace : trace<a,<effects-and-types/sample,effects-and-types/score|e>>, accept : bool) -> <effects-and-types/sample|e> trace<a,<effects-and-types/sample,effects-and-types/score|e>> */ 
  if (accept) {
    kk_tmcmc__trace_dropn(trace, ((int32_t)3), _ctx);
    return kk_tmcmc__new_Trace(kk_reuse_null, model, p2, new__trace, b, _ctx);
  }
  kk_box_drop(b, _ctx);
  kk_function_drop(model, _ctx);
  kk_std_core__list_drop(new__trace, _ctx);
  return trace;
}
 
// monadic lift


// lift anonymous function
struct kk_tmcmc__mlift1682_mh__step_fun2565__t {
  struct kk_function_s _base;
};
static kk_box_t kk_tmcmc__mlift1682_mh__step_fun2565(kk_function_t _fself, kk_box_t _b_2062, kk_context_t* _ctx);
static kk_function_t kk_tmcmc__new_mlift1682_mh__step_fun2565(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_tmcmc__mlift1682_mh__step_fun2565, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_tmcmc__mlift1682_mh__step_fun2565(kk_function_t _fself, kk_box_t _b_2062, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x2566;
  kk_effects_dash_and_dash_types__exp _x2567 = kk_effects_dash_and_dash_types__exp_unbox(_b_2062, _ctx); /*effects-and-types/exp*/
  _x2566 = kk_exponents_exp__to__double(_x2567, _ctx); /*double*/
  return kk_double_box(_x2566, _ctx);
}


// lift anonymous function
struct kk_tmcmc__mlift1682_mh__step_fun2573__t {
  struct kk_function_s _base;
};
static kk_box_t kk_tmcmc__mlift1682_mh__step_fun2573(kk_function_t _fself, kk_box_t _b_2065, kk_context_t* _ctx);
static kk_function_t kk_tmcmc__new_mlift1682_mh__step_fun2573(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_tmcmc__mlift1682_mh__step_fun2573, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_tmcmc__mlift1682_mh__step_fun2573(kk_function_t _fself, kk_box_t _b_2065, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x2574;
  kk_effects_dash_and_dash_types__exp _x2575 = kk_effects_dash_and_dash_types__exp_unbox(_b_2065, _ctx); /*effects-and-types/exp*/
  _x2574 = kk_exponents_exp__to__double(_x2575, _ctx); /*double*/
  return kk_double_box(_x2574, _ctx);
}


// lift anonymous function
struct kk_tmcmc__mlift1682_mh__step_fun2581__t {
  struct kk_function_s _base;
  size_t i_1770;
};
static kk_box_t kk_tmcmc__mlift1682_mh__step_fun2581(kk_function_t _fself, kk_function_t _b_2075, kk_box_t _b_2076, kk_context_t* _ctx);
static kk_function_t kk_tmcmc__new_mlift1682_mh__step_fun2581(size_t i_1770, kk_context_t* _ctx) {
  struct kk_tmcmc__mlift1682_mh__step_fun2581__t* _self = kk_function_alloc_as(struct kk_tmcmc__mlift1682_mh__step_fun2581__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc__mlift1682_mh__step_fun2581, kk_context());
  _self->i_1770 = i_1770;
  return &_self->_base;
}

static kk_box_t kk_tmcmc__mlift1682_mh__step_fun2581(kk_function_t _fself, kk_function_t _b_2075, kk_box_t _b_2076, kk_context_t* _ctx) {
  struct kk_tmcmc__mlift1682_mh__step_fun2581__t* _self = kk_function_as(struct kk_tmcmc__mlift1682_mh__step_fun2581__t*, _fself);
  size_t i_1770 = _self->i_1770; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_1770, _b_2075, _b_2076, _ctx);
}


// lift anonymous function
struct kk_tmcmc__mlift1682_mh__step_fun2583__t {
  struct kk_function_s _base;
  kk_box_t b;
  kk_function_t model;
  kk_std_core__list new__trace;
  kk_tmcmc__trace trace;
  kk_effects_dash_and_dash_types__exp p2;
};
static kk_box_t kk_tmcmc__mlift1682_mh__step_fun2583(kk_function_t _fself, kk_box_t _b_2086, kk_context_t* _ctx);
static kk_function_t kk_tmcmc__new_mlift1682_mh__step_fun2583(kk_box_t b, kk_function_t model, kk_std_core__list new__trace, kk_tmcmc__trace trace, kk_effects_dash_and_dash_types__exp p2, kk_context_t* _ctx) {
  struct kk_tmcmc__mlift1682_mh__step_fun2583__t* _self = kk_function_alloc_as(struct kk_tmcmc__mlift1682_mh__step_fun2583__t, 5, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc__mlift1682_mh__step_fun2583, kk_context());
  _self->b = b;
  _self->model = model;
  _self->new__trace = new__trace;
  _self->trace = trace;
  _self->p2 = p2;
  return &_self->_base;
}

static kk_box_t kk_tmcmc__mlift1682_mh__step_fun2583(kk_function_t _fself, kk_box_t _b_2086, kk_context_t* _ctx) {
  struct kk_tmcmc__mlift1682_mh__step_fun2583__t* _self = kk_function_as(struct kk_tmcmc__mlift1682_mh__step_fun2583__t*, _fself);
  kk_box_t b = _self->b; /* 1139 */
  kk_function_t model = _self->model; /* () -> <effects-and-types/sample,effects-and-types/score|1140> 1139 */
  kk_std_core__list new__trace = _self->new__trace; /* effects-and-types/trace_values */
  kk_tmcmc__trace trace = _self->trace; /* tmcmc/trace<1139,<effects-and-types/sample,effects-and-types/score|1140>> */
  kk_effects_dash_and_dash_types__exp p2 = _self->p2; /* effects-and-types/exp */
  kk_drop_match(_self, {kk_box_dup(b);kk_function_dup(model);kk_std_core__list_dup(new__trace);kk_tmcmc__trace_dup(trace);kk_effects_dash_and_dash_types__exp_dup(p2);}, {}, _ctx)
  kk_tmcmc__trace _x2584;
  bool _x2585 = kk_bool_unbox(_b_2086); /*bool*/
  _x2584 = kk_tmcmc__mlift1681_mh__step(b, model, new__trace, p2, trace, _x2585, _ctx); /*tmcmc/trace<1139,<effects-and-types/sample,effects-and-types/score|1140>>*/
  return kk_tmcmc__trace_box(_x2584, _ctx);
}

kk_tmcmc__trace kk_tmcmc__mlift1682_mh__step(kk_function_t model, kk_std_core__list old__trace, kk_effects_dash_and_dash_types__exp p1, kk_tmcmc__trace trace, kk_std_core_types__tuple2_ p2b, kk_context_t* _ctx) { /* forall<a,e> (model : () -> <effects-and-types/sample,effects-and-types/score|e> a, old_trace : effects-and-types/trace_values, p1 : effects-and-types/exp, trace : trace<a,<effects-and-types/sample,effects-and-types/score|e>>, p2b : (effects-and-types/trace_values, (effects-and-types/exp, a))) -> <effects-and-types/sample|e> trace<a,<effects-and-types/sample,effects-and-types/score|e>> */ 
  kk_box_t _box_x2057 = p2b.fst;
  kk_box_t _box_x2058 = p2b.snd;
  kk_std_core__list new__trace = kk_std_core__list_unbox(_box_x2057, NULL);
  kk_std_core_types__tuple2_ _pat3 = kk_std_core_types__tuple2__unbox(_box_x2058, NULL);
  kk_box_t _box_x2059 = _pat3.fst;
  kk_box_t b = _pat3.snd;
  kk_effects_dash_and_dash_types__exp p2 = kk_effects_dash_and_dash_types__exp_unbox(_box_x2059, NULL);
  kk_box_dup(b);
  kk_std_core__list_dup(new__trace);
  kk_std_core_types__tuple2__drop(p2b, _ctx);
  double ratio;
  double y_1767;
  double _x2562;
  double _x2563;
  kk_box_t _x2564 = kk_std_core_hnd__open_none1(kk_tmcmc__new_mlift1682_mh__step_fun2565(_ctx), kk_effects_dash_and_dash_types__exp_box(p2, _ctx), _ctx); /*2*/
  _x2563 = kk_double_unbox(_x2564, _ctx); /*double*/
  double _x2568;
  kk_integer_t _x2569 = kk_std_core_length_1(old__trace, _ctx); /*int*/
  _x2568 = kk_integer_as_double(_x2569,kk_context()); /*double*/
  _x2562 = (_x2563 * _x2568); /*double*/
  double _x2570;
  double _x2571;
  kk_box_t _x2572 = kk_std_core_hnd__open_none1(kk_tmcmc__new_mlift1682_mh__step_fun2573(_ctx), kk_effects_dash_and_dash_types__exp_box(p1, _ctx), _ctx); /*2*/
  _x2571 = kk_double_unbox(_x2572, _ctx); /*double*/
  double _x2576;
  kk_integer_t _x2577;
  kk_std_core__list _x2578 = kk_std_core__list_dup(new__trace); /*effects-and-types/trace_values*/
  _x2577 = kk_std_core_length_1(_x2578, _ctx); /*int*/
  _x2576 = kk_integer_as_double(_x2577,kk_context()); /*double*/
  _x2570 = (_x2571 * _x2576); /*double*/
  y_1767 = (_x2562 / _x2570); /*double*/
  bool _match_2332 = (0x1p0 <= y_1767); /*bool*/;
  if (_match_2332) {
    ratio = 0x1p0; /*double*/
  }
  else {
    ratio = y_1767; /*double*/
  }
  bool x0_1768;
  size_t i_1770;
  kk_std_core_hnd__htag _x2579 = kk_std_core_hnd__htag_dup(kk_effects_dash_and_dash_types__tag_sample); /*std/core/hnd/htag<effects-and-types/.hnd-sample>*/
  i_1770 = kk_std_core_hnd__evv_index(_x2579, _ctx); /*std/core/hnd/ev-index*/
  kk_evv_t w = kk_evv_swap_create1(i_1770,kk_context()); /*std/core/hnd/evv<<effects-and-types/sample|1140>>*/;
  bool y0 = kk_model_dash_resources_bernoulli(ratio, _ctx); /*bool*/;
  kk_unit_t __w_l700_c9 = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x2580 = kk_std_core_hnd_yield_cont(kk_tmcmc__new_mlift1682_mh__step_fun2581(i_1770, _ctx), _ctx); /*3*/
    x0_1768 = kk_bool_unbox(_x2580); /*bool*/
  }
  else {
    x0_1768 = y0; /*bool*/
  }
  if (kk_yielding(kk_context())) {
    kk_box_t _x2582 = kk_std_core_hnd_yield_extend(kk_tmcmc__new_mlift1682_mh__step_fun2583(b, model, new__trace, trace, p2, _ctx), _ctx); /*2*/
    return kk_tmcmc__trace_unbox(_x2582, _ctx);
  }
  return kk_tmcmc__mlift1681_mh__step(b, model, new__trace, p2, trace, x0_1768, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_tmcmc__mlift1683_mh__step_fun2589__t {
  struct kk_function_s _base;
  kk_function_t model;
  kk_std_core__list old__trace;
  kk_tmcmc__trace trace;
  kk_effects_dash_and_dash_types__exp p1;
};
static kk_box_t kk_tmcmc__mlift1683_mh__step_fun2589(kk_function_t _fself, kk_box_t _b_2090, kk_context_t* _ctx);
static kk_function_t kk_tmcmc__new_mlift1683_mh__step_fun2589(kk_function_t model, kk_std_core__list old__trace, kk_tmcmc__trace trace, kk_effects_dash_and_dash_types__exp p1, kk_context_t* _ctx) {
  struct kk_tmcmc__mlift1683_mh__step_fun2589__t* _self = kk_function_alloc_as(struct kk_tmcmc__mlift1683_mh__step_fun2589__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc__mlift1683_mh__step_fun2589, kk_context());
  _self->model = model;
  _self->old__trace = old__trace;
  _self->trace = trace;
  _self->p1 = p1;
  return &_self->_base;
}

static kk_box_t kk_tmcmc__mlift1683_mh__step_fun2589(kk_function_t _fself, kk_box_t _b_2090, kk_context_t* _ctx) {
  struct kk_tmcmc__mlift1683_mh__step_fun2589__t* _self = kk_function_as(struct kk_tmcmc__mlift1683_mh__step_fun2589__t*, _fself);
  kk_function_t model = _self->model; /* () -> <effects-and-types/sample,effects-and-types/score|1140> 1139 */
  kk_std_core__list old__trace = _self->old__trace; /* effects-and-types/trace_values */
  kk_tmcmc__trace trace = _self->trace; /* tmcmc/trace<1139,<effects-and-types/sample,effects-and-types/score|1140>> */
  kk_effects_dash_and_dash_types__exp p1 = _self->p1; /* effects-and-types/exp */
  kk_drop_match(_self, {kk_function_dup(model);kk_std_core__list_dup(old__trace);kk_tmcmc__trace_dup(trace);kk_effects_dash_and_dash_types__exp_dup(p1);}, {}, _ctx)
  kk_tmcmc__trace _x2590;
  kk_std_core_types__tuple2_ _x2591 = kk_std_core_types__tuple2__unbox(_b_2090, _ctx); /*(effects-and-types/trace_values, (effects-and-types/exp, 1139))*/
  _x2590 = kk_tmcmc__mlift1682_mh__step(model, old__trace, p1, trace, _x2591, _ctx); /*tmcmc/trace<1139,<effects-and-types/sample,effects-and-types/score|1140>>*/
  return kk_tmcmc__trace_box(_x2590, _ctx);
}

kk_tmcmc__trace kk_tmcmc__mlift1683_mh__step(kk_tmcmc__trace trace, kk_std_core__list modified__trace, kk_context_t* _ctx) { /* forall<a,e> (trace : trace<a,<effects-and-types/sample,effects-and-types/score|e>>, modified_trace : effects-and-types/trace_values) -> <effects-and-types/sample|e> trace<a,<effects-and-types/sample,effects-and-types/score|e>> */ 
  struct kk_tmcmc_Trace* _con2586 = kk_tmcmc__as_Trace(trace);
  kk_function_t model = _con2586->m;
  kk_effects_dash_and_dash_types__exp p1 = _con2586->p;
  kk_std_core__list old__trace = _con2586->l;
  kk_function_dup(model);
  kk_std_core__list_dup(old__trace);
  kk_std_core_types__tuple2_ x_1773;
  kk_function_t _x2587 = kk_function_dup(model); /*() -> <effects-and-types/sample,effects-and-types/score|1140> 1139*/
  x_1773 = kk_tmcmc_with__randomness(_x2587, modified__trace, _ctx); /*(effects-and-types/trace_values, (effects-and-types/exp, 1139))*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__tuple2__drop(x_1773, _ctx);
    kk_box_t _x2588 = kk_std_core_hnd_yield_extend(kk_tmcmc__new_mlift1683_mh__step_fun2589(model, old__trace, trace, p1, _ctx), _ctx); /*2*/
    return kk_tmcmc__trace_unbox(_x2588, _ctx);
  }
  return kk_tmcmc__mlift1682_mh__step(model, old__trace, p1, trace, x_1773, _ctx);
}


// lift anonymous function
struct kk_tmcmc_mh__step_fun2595__t {
  struct kk_function_s _base;
  size_t i_1780;
};
static kk_box_t kk_tmcmc_mh__step_fun2595(kk_function_t _fself, kk_function_t _b_2098, kk_box_t _b_2099, kk_context_t* _ctx);
static kk_function_t kk_tmcmc_new_mh__step_fun2595(size_t i_1780, kk_context_t* _ctx) {
  struct kk_tmcmc_mh__step_fun2595__t* _self = kk_function_alloc_as(struct kk_tmcmc_mh__step_fun2595__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc_mh__step_fun2595, kk_context());
  _self->i_1780 = i_1780;
  return &_self->_base;
}

static kk_box_t kk_tmcmc_mh__step_fun2595(kk_function_t _fself, kk_function_t _b_2098, kk_box_t _b_2099, kk_context_t* _ctx) {
  struct kk_tmcmc_mh__step_fun2595__t* _self = kk_function_as(struct kk_tmcmc_mh__step_fun2595__t*, _fself);
  size_t i_1780 = _self->i_1780; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_1780, _b_2098, _b_2099, _ctx);
}


// lift anonymous function
struct kk_tmcmc_mh__step_fun2597__t {
  struct kk_function_s _base;
  kk_tmcmc__trace trace;
};
static kk_box_t kk_tmcmc_mh__step_fun2597(kk_function_t _fself, kk_box_t _b_2109, kk_context_t* _ctx);
static kk_function_t kk_tmcmc_new_mh__step_fun2597(kk_tmcmc__trace trace, kk_context_t* _ctx) {
  struct kk_tmcmc_mh__step_fun2597__t* _self = kk_function_alloc_as(struct kk_tmcmc_mh__step_fun2597__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc_mh__step_fun2597, kk_context());
  _self->trace = trace;
  return &_self->_base;
}

static kk_box_t kk_tmcmc_mh__step_fun2597(kk_function_t _fself, kk_box_t _b_2109, kk_context_t* _ctx) {
  struct kk_tmcmc_mh__step_fun2597__t* _self = kk_function_as(struct kk_tmcmc_mh__step_fun2597__t*, _fself);
  kk_tmcmc__trace trace = _self->trace; /* tmcmc/trace<1139,<effects-and-types/sample,effects-and-types/score|1140>> */
  kk_drop_match(_self, {kk_tmcmc__trace_dup(trace);}, {}, _ctx)
  kk_tmcmc__trace _x2598;
  kk_std_core__list _x2599 = kk_std_core__list_unbox(_b_2109, _ctx); /*effects-and-types/trace_values*/
  _x2598 = kk_tmcmc__mlift1683_mh__step(trace, _x2599, _ctx); /*tmcmc/trace<1139,<effects-and-types/sample,effects-and-types/score|1140>>*/
  return kk_tmcmc__trace_box(_x2598, _ctx);
}


// lift anonymous function
struct kk_tmcmc_mh__step_fun2604__t {
  struct kk_function_s _base;
  kk_function_t model;
  kk_std_core__list old__trace;
  kk_tmcmc__trace trace;
  kk_effects_dash_and_dash_types__exp p1;
};
static kk_box_t kk_tmcmc_mh__step_fun2604(kk_function_t _fself, kk_box_t _b_2111, kk_context_t* _ctx);
static kk_function_t kk_tmcmc_new_mh__step_fun2604(kk_function_t model, kk_std_core__list old__trace, kk_tmcmc__trace trace, kk_effects_dash_and_dash_types__exp p1, kk_context_t* _ctx) {
  struct kk_tmcmc_mh__step_fun2604__t* _self = kk_function_alloc_as(struct kk_tmcmc_mh__step_fun2604__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc_mh__step_fun2604, kk_context());
  _self->model = model;
  _self->old__trace = old__trace;
  _self->trace = trace;
  _self->p1 = p1;
  return &_self->_base;
}

static kk_box_t kk_tmcmc_mh__step_fun2604(kk_function_t _fself, kk_box_t _b_2111, kk_context_t* _ctx) {
  struct kk_tmcmc_mh__step_fun2604__t* _self = kk_function_as(struct kk_tmcmc_mh__step_fun2604__t*, _fself);
  kk_function_t model = _self->model; /* () -> <effects-and-types/sample,effects-and-types/score|1140> 1139 */
  kk_std_core__list old__trace = _self->old__trace; /* effects-and-types/trace_values */
  kk_tmcmc__trace trace = _self->trace; /* tmcmc/trace<1139,<effects-and-types/sample,effects-and-types/score|1140>> */
  kk_effects_dash_and_dash_types__exp p1 = _self->p1; /* effects-and-types/exp */
  kk_drop_match(_self, {kk_function_dup(model);kk_std_core__list_dup(old__trace);kk_tmcmc__trace_dup(trace);kk_effects_dash_and_dash_types__exp_dup(p1);}, {}, _ctx)
  kk_tmcmc__trace _x2605;
  kk_std_core_types__tuple2_ _x2606 = kk_std_core_types__tuple2__unbox(_b_2111, _ctx); /*(effects-and-types/trace_values, (effects-and-types/exp, 1139))*/
  _x2605 = kk_tmcmc__mlift1682_mh__step(model, old__trace, p1, trace, _x2606, _ctx); /*tmcmc/trace<1139,<effects-and-types/sample,effects-and-types/score|1140>>*/
  return kk_tmcmc__trace_box(_x2605, _ctx);
}


// lift anonymous function
struct kk_tmcmc_mh__step_fun2613__t {
  struct kk_function_s _base;
};
static kk_box_t kk_tmcmc_mh__step_fun2613(kk_function_t _fself, kk_box_t _b_2117, kk_context_t* _ctx);
static kk_function_t kk_tmcmc_new_mh__step_fun2613(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_tmcmc_mh__step_fun2613, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_tmcmc_mh__step_fun2613(kk_function_t _fself, kk_box_t _b_2117, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x2614;
  kk_effects_dash_and_dash_types__exp _x2615 = kk_effects_dash_and_dash_types__exp_unbox(_b_2117, _ctx); /*effects-and-types/exp*/
  _x2614 = kk_exponents_exp__to__double(_x2615, _ctx); /*double*/
  return kk_double_box(_x2614, _ctx);
}


// lift anonymous function
struct kk_tmcmc_mh__step_fun2621__t {
  struct kk_function_s _base;
};
static kk_box_t kk_tmcmc_mh__step_fun2621(kk_function_t _fself, kk_box_t _b_2120, kk_context_t* _ctx);
static kk_function_t kk_tmcmc_new_mh__step_fun2621(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_tmcmc_mh__step_fun2621, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_tmcmc_mh__step_fun2621(kk_function_t _fself, kk_box_t _b_2120, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x2622;
  kk_effects_dash_and_dash_types__exp _x2623 = kk_effects_dash_and_dash_types__exp_unbox(_b_2120, _ctx); /*effects-and-types/exp*/
  _x2622 = kk_exponents_exp__to__double(_x2623, _ctx); /*double*/
  return kk_double_box(_x2622, _ctx);
}


// lift anonymous function
struct kk_tmcmc_mh__step_fun2629__t {
  struct kk_function_s _base;
  size_t i0_1793;
};
static kk_box_t kk_tmcmc_mh__step_fun2629(kk_function_t _fself, kk_function_t _b_2130, kk_box_t _b_2131, kk_context_t* _ctx);
static kk_function_t kk_tmcmc_new_mh__step_fun2629(size_t i0_1793, kk_context_t* _ctx) {
  struct kk_tmcmc_mh__step_fun2629__t* _self = kk_function_alloc_as(struct kk_tmcmc_mh__step_fun2629__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc_mh__step_fun2629, kk_context());
  _self->i0_1793 = i0_1793;
  return &_self->_base;
}

static kk_box_t kk_tmcmc_mh__step_fun2629(kk_function_t _fself, kk_function_t _b_2130, kk_box_t _b_2131, kk_context_t* _ctx) {
  struct kk_tmcmc_mh__step_fun2629__t* _self = kk_function_as(struct kk_tmcmc_mh__step_fun2629__t*, _fself);
  size_t i0_1793 = _self->i0_1793; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i0_1793, _b_2130, _b_2131, _ctx);
}


// lift anonymous function
struct kk_tmcmc_mh__step_fun2631__t {
  struct kk_function_s _base;
  kk_box_t b;
  kk_function_t model;
  kk_std_core__list new__trace;
  kk_tmcmc__trace trace;
  kk_effects_dash_and_dash_types__exp p2;
};
static kk_box_t kk_tmcmc_mh__step_fun2631(kk_function_t _fself, kk_box_t _b_2141, kk_context_t* _ctx);
static kk_function_t kk_tmcmc_new_mh__step_fun2631(kk_box_t b, kk_function_t model, kk_std_core__list new__trace, kk_tmcmc__trace trace, kk_effects_dash_and_dash_types__exp p2, kk_context_t* _ctx) {
  struct kk_tmcmc_mh__step_fun2631__t* _self = kk_function_alloc_as(struct kk_tmcmc_mh__step_fun2631__t, 5, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc_mh__step_fun2631, kk_context());
  _self->b = b;
  _self->model = model;
  _self->new__trace = new__trace;
  _self->trace = trace;
  _self->p2 = p2;
  return &_self->_base;
}

static kk_box_t kk_tmcmc_mh__step_fun2631(kk_function_t _fself, kk_box_t _b_2141, kk_context_t* _ctx) {
  struct kk_tmcmc_mh__step_fun2631__t* _self = kk_function_as(struct kk_tmcmc_mh__step_fun2631__t*, _fself);
  kk_box_t b = _self->b; /* 1139 */
  kk_function_t model = _self->model; /* () -> <effects-and-types/sample,effects-and-types/score|1140> 1139 */
  kk_std_core__list new__trace = _self->new__trace; /* effects-and-types/trace_values */
  kk_tmcmc__trace trace = _self->trace; /* tmcmc/trace<1139,<effects-and-types/sample,effects-and-types/score|1140>> */
  kk_effects_dash_and_dash_types__exp p2 = _self->p2; /* effects-and-types/exp */
  kk_drop_match(_self, {kk_box_dup(b);kk_function_dup(model);kk_std_core__list_dup(new__trace);kk_tmcmc__trace_dup(trace);kk_effects_dash_and_dash_types__exp_dup(p2);}, {}, _ctx)
  kk_tmcmc__trace _x2632;
  bool _x2633 = kk_bool_unbox(_b_2141); /*bool*/
  _x2632 = kk_tmcmc__mlift1681_mh__step(b, model, new__trace, p2, trace, _x2633, _ctx); /*tmcmc/trace<1139,<effects-and-types/sample,effects-and-types/score|1140>>*/
  return kk_tmcmc__trace_box(_x2632, _ctx);
}

kk_tmcmc__trace kk_tmcmc_mh__step(kk_tmcmc__trace trace, kk_context_t* _ctx) { /* forall<a,e> (trace : trace<a,<effects-and-types/sample,effects-and-types/score|e>>) -> <effects-and-types/sample|e> trace<a,<effects-and-types/sample,effects-and-types/score|e>> */ 
  kk_std_core__list x_1775;
  kk_std_core__list _x1;
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*std/core/hnd/evv<(<>)>*/;
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  struct kk_tmcmc_Trace* _con2592 = kk_tmcmc__as_Trace(trace);
  kk_effects_dash_and_dash_types__exp _pat1 = _con2592->p;
  kk_std_core__list _x = _con2592->l;
  kk_std_core__list_dup(_x);
  _x1 = _x; /*effects-and-types/trace_values*/
  size_t i_1780;
  kk_std_core_hnd__htag _x2593 = kk_std_core_hnd__htag_dup(kk_effects_dash_and_dash_types__tag_sample); /*std/core/hnd/htag<effects-and-types/.hnd-sample>*/
  i_1780 = kk_std_core_hnd__evv_index(_x2593, _ctx); /*std/core/hnd/ev-index*/
  kk_evv_t w0 = kk_evv_swap_create1(i_1780,kk_context()); /*std/core/hnd/evv<<effects-and-types/sample|1140>>*/;
  kk_std_core__list y = kk_tmcmc_perturb__trace(_x1, _ctx); /*effects-and-types/trace_values*/;
  kk_unit_t __w_l700_c9 = kk_Unit;
  kk_evv_set(w0,kk_context());
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(y, _ctx);
    kk_box_t _x2594 = kk_std_core_hnd_yield_cont(kk_tmcmc_new_mh__step_fun2595(i_1780, _ctx), _ctx); /*3*/
    x_1775 = kk_std_core__list_unbox(_x2594, _ctx); /*effects-and-types/trace_values*/
  }
  else {
    x_1775 = y; /*effects-and-types/trace_values*/
  }
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_1775, _ctx);
    kk_box_t _x2596 = kk_std_core_hnd_yield_extend(kk_tmcmc_new_mh__step_fun2597(trace, _ctx), _ctx); /*2*/
    return kk_tmcmc__trace_unbox(_x2596, _ctx);
  }
  struct kk_tmcmc_Trace* _con2600 = kk_tmcmc__as_Trace(trace);
  kk_function_t model = _con2600->m;
  kk_effects_dash_and_dash_types__exp p1 = _con2600->p;
  kk_std_core__list old__trace = _con2600->l;
  kk_function_dup(model);
  kk_std_core__list_dup(old__trace);
  kk_reuse_t _ru_2302;
  kk_tmcmc__trace _x2601 = kk_tmcmc__trace_dup(trace); /*tmcmc/trace<1139,<effects-and-types/sample,effects-and-types/score|1140>>*/
  _ru_2302 = kk_tmcmc__trace_dropn_reuse(_x2601, ((int32_t)3), _ctx); /*reuse*/
  kk_std_core_types__tuple2_ x3_1784;
  kk_function_t _x2602 = kk_function_dup(model); /*() -> <effects-and-types/sample,effects-and-types/score|1140> 1139*/
  x3_1784 = kk_tmcmc_with__randomness(_x2602, x_1775, _ctx); /*(effects-and-types/trace_values, (effects-and-types/exp, 1139))*/
  if (kk_yielding(kk_context())) {
    kk_reuse_drop(_ru_2302, _ctx);
    kk_std_core_types__tuple2__drop(x3_1784, _ctx);
    kk_box_t _x2603 = kk_std_core_hnd_yield_extend(kk_tmcmc_new_mh__step_fun2604(model, old__trace, trace, p1, _ctx), _ctx); /*2*/
    return kk_tmcmc__trace_unbox(_x2603, _ctx);
  }
  kk_box_t _box_x2112 = x3_1784.fst;
  kk_box_t _box_x2113 = x3_1784.snd;
  kk_std_core__list new__trace = kk_std_core__list_unbox(_box_x2112, NULL);
  kk_std_core_types__tuple2_ _pat300 = kk_std_core_types__tuple2__unbox(_box_x2113, NULL);
  kk_box_t _box_x2114 = _pat300.fst;
  kk_box_t b = _pat300.snd;
  kk_effects_dash_and_dash_types__exp p2 = kk_effects_dash_and_dash_types__exp_unbox(_box_x2114, NULL);
  kk_box_dup(b);
  kk_std_core__list_dup(new__trace);
  kk_std_core_types__tuple2__drop(x3_1784, _ctx);
  double ratio;
  double y0_1789;
  double _x2610;
  double _x2611;
  kk_box_t _x2612 = kk_std_core_hnd__open_none1(kk_tmcmc_new_mh__step_fun2613(_ctx), kk_effects_dash_and_dash_types__exp_box(p2, _ctx), _ctx); /*2*/
  _x2611 = kk_double_unbox(_x2612, _ctx); /*double*/
  double _x2616;
  kk_integer_t _x2617 = kk_std_core_length_1(old__trace, _ctx); /*int*/
  _x2616 = kk_integer_as_double(_x2617,kk_context()); /*double*/
  _x2610 = (_x2611 * _x2616); /*double*/
  double _x2618;
  double _x2619;
  kk_box_t _x2620 = kk_std_core_hnd__open_none1(kk_tmcmc_new_mh__step_fun2621(_ctx), kk_effects_dash_and_dash_types__exp_box(p1, _ctx), _ctx); /*2*/
  _x2619 = kk_double_unbox(_x2620, _ctx); /*double*/
  double _x2624;
  kk_integer_t _x2625;
  kk_std_core__list _x2626 = kk_std_core__list_dup(new__trace); /*effects-and-types/trace_values*/
  _x2625 = kk_std_core_length_1(_x2626, _ctx); /*int*/
  _x2624 = kk_integer_as_double(_x2625,kk_context()); /*double*/
  _x2618 = (_x2619 * _x2624); /*double*/
  y0_1789 = (_x2610 / _x2618); /*double*/
  bool _match_2327 = (0x1p0 <= y0_1789); /*bool*/;
  if (_match_2327) {
    ratio = 0x1p0; /*double*/
  }
  else {
    ratio = y0_1789; /*double*/
  }
  bool x5_1790;
  size_t i0_1793;
  kk_std_core_hnd__htag _x2627 = kk_std_core_hnd__htag_dup(kk_effects_dash_and_dash_types__tag_sample); /*std/core/hnd/htag<effects-and-types/.hnd-sample>*/
  i0_1793 = kk_std_core_hnd__evv_index(_x2627, _ctx); /*std/core/hnd/ev-index*/
  kk_evv_t w1 = kk_evv_swap_create1(i0_1793,kk_context()); /*std/core/hnd/evv<<effects-and-types/sample|1140>>*/;
  bool y1 = kk_model_dash_resources_bernoulli(ratio, _ctx); /*bool*/;
  kk_unit_t __w_l700_c90 = kk_Unit;
  kk_evv_set(w1,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x2628 = kk_std_core_hnd_yield_cont(kk_tmcmc_new_mh__step_fun2629(i0_1793, _ctx), _ctx); /*3*/
    x5_1790 = kk_bool_unbox(_x2628); /*bool*/
  }
  else {
    x5_1790 = y1; /*bool*/
  }
  if (kk_yielding(kk_context())) {
    kk_reuse_drop(_ru_2302, _ctx);
    kk_box_t _x2630 = kk_std_core_hnd_yield_extend(kk_tmcmc_new_mh__step_fun2631(b, model, new__trace, trace, p2, _ctx), _ctx); /*2*/
    return kk_tmcmc__trace_unbox(_x2630, _ctx);
  }
  if (x5_1790) {
    kk_tmcmc__trace_dropn(trace, ((int32_t)3), _ctx);
    return kk_tmcmc__new_Trace(_ru_2302, model, p2, new__trace, b, _ctx);
  }
  kk_reuse_drop(_ru_2302, _ctx);
  kk_box_drop(b, _ctx);
  kk_function_drop(model, _ctx);
  kk_std_core__list_drop(new__trace, _ctx);
  return trace;
}
 
// monadic lift

kk_tmcmc__trace__rmsmc kk_tmcmc__mlift1684_mh__step__rmsmc(kk_function_t model, kk_std_core__list new__trace, kk_effects_dash_and_dash_types__exp p2, kk_tmcmc__trace__rmsmc trace, bool accept, kk_context_t* _ctx) { /* forall<a,e> (model : () -> ((int) -> <exn,effects-and-types/sample,effects-and-types/sample,effects-and-types/score,effects-and-types/yield|e> a), new_trace : effects-and-types/trace_values, p2 : effects-and-types/exp, trace : trace_rmsmc<a,<effects-and-types/sample,effects-and-types/sample,effects-and-types/score,effects-and-types/yield,exn|e>>, accept : bool) -> <effects-and-types/sample,exn,effects-and-types/sample,effects-and-types/yield|e> trace_rmsmc<a,<exn,effects-and-types/sample,effects-and-types/sample,effects-and-types/score,effects-and-types/yield|e>> */ 
  if (accept) {
    kk_tmcmc__trace__rmsmc_drop(trace, _ctx);
    return kk_tmcmc__new_RTrace(model, p2, new__trace, _ctx);
  }
  kk_function_drop(model, _ctx);
  kk_std_core__list_drop(new__trace, _ctx);
  return trace;
}
 
// monadic lift


// lift anonymous function
struct kk_tmcmc__mlift1685_mh__step__rmsmc_fun2640__t {
  struct kk_function_s _base;
};
static kk_box_t kk_tmcmc__mlift1685_mh__step__rmsmc_fun2640(kk_function_t _fself, kk_box_t _b_2153, kk_context_t* _ctx);
static kk_function_t kk_tmcmc__new_mlift1685_mh__step__rmsmc_fun2640(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_tmcmc__mlift1685_mh__step__rmsmc_fun2640, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_tmcmc__mlift1685_mh__step__rmsmc_fun2640(kk_function_t _fself, kk_box_t _b_2153, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x2641;
  kk_effects_dash_and_dash_types__exp _x2642 = kk_effects_dash_and_dash_types__exp_unbox(_b_2153, _ctx); /*effects-and-types/exp*/
  _x2641 = kk_exponents_exp__to__double(_x2642, _ctx); /*double*/
  return kk_double_box(_x2641, _ctx);
}


// lift anonymous function
struct kk_tmcmc__mlift1685_mh__step__rmsmc_fun2648__t {
  struct kk_function_s _base;
};
static kk_box_t kk_tmcmc__mlift1685_mh__step__rmsmc_fun2648(kk_function_t _fself, kk_box_t _b_2156, kk_context_t* _ctx);
static kk_function_t kk_tmcmc__new_mlift1685_mh__step__rmsmc_fun2648(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_tmcmc__mlift1685_mh__step__rmsmc_fun2648, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_tmcmc__mlift1685_mh__step__rmsmc_fun2648(kk_function_t _fself, kk_box_t _b_2156, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x2649;
  kk_effects_dash_and_dash_types__exp _x2650 = kk_effects_dash_and_dash_types__exp_unbox(_b_2156, _ctx); /*effects-and-types/exp*/
  _x2649 = kk_exponents_exp__to__double(_x2650, _ctx); /*double*/
  return kk_double_box(_x2649, _ctx);
}


// lift anonymous function
struct kk_tmcmc__mlift1685_mh__step__rmsmc_fun2656__t {
  struct kk_function_s _base;
  size_t i_1801;
};
static kk_box_t kk_tmcmc__mlift1685_mh__step__rmsmc_fun2656(kk_function_t _fself, kk_function_t _b_2166, kk_box_t _b_2167, kk_context_t* _ctx);
static kk_function_t kk_tmcmc__new_mlift1685_mh__step__rmsmc_fun2656(size_t i_1801, kk_context_t* _ctx) {
  struct kk_tmcmc__mlift1685_mh__step__rmsmc_fun2656__t* _self = kk_function_alloc_as(struct kk_tmcmc__mlift1685_mh__step__rmsmc_fun2656__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc__mlift1685_mh__step__rmsmc_fun2656, kk_context());
  _self->i_1801 = i_1801;
  return &_self->_base;
}

static kk_box_t kk_tmcmc__mlift1685_mh__step__rmsmc_fun2656(kk_function_t _fself, kk_function_t _b_2166, kk_box_t _b_2167, kk_context_t* _ctx) {
  struct kk_tmcmc__mlift1685_mh__step__rmsmc_fun2656__t* _self = kk_function_as(struct kk_tmcmc__mlift1685_mh__step__rmsmc_fun2656__t*, _fself);
  size_t i_1801 = _self->i_1801; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_1801, _b_2166, _b_2167, _ctx);
}


// lift anonymous function
struct kk_tmcmc__mlift1685_mh__step__rmsmc_fun2658__t {
  struct kk_function_s _base;
  kk_function_t model;
  kk_std_core__list new__trace;
  kk_tmcmc__trace__rmsmc trace;
  kk_effects_dash_and_dash_types__exp p2;
};
static kk_box_t kk_tmcmc__mlift1685_mh__step__rmsmc_fun2658(kk_function_t _fself, kk_box_t _b_2177, kk_context_t* _ctx);
static kk_function_t kk_tmcmc__new_mlift1685_mh__step__rmsmc_fun2658(kk_function_t model, kk_std_core__list new__trace, kk_tmcmc__trace__rmsmc trace, kk_effects_dash_and_dash_types__exp p2, kk_context_t* _ctx) {
  struct kk_tmcmc__mlift1685_mh__step__rmsmc_fun2658__t* _self = kk_function_alloc_as(struct kk_tmcmc__mlift1685_mh__step__rmsmc_fun2658__t, 5, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc__mlift1685_mh__step__rmsmc_fun2658, kk_context());
  _self->model = model;
  _self->new__trace = new__trace;
  _self->trace = trace;
  _self->p2 = p2;
  return &_self->_base;
}

static kk_box_t kk_tmcmc__mlift1685_mh__step__rmsmc_fun2658(kk_function_t _fself, kk_box_t _b_2177, kk_context_t* _ctx) {
  struct kk_tmcmc__mlift1685_mh__step__rmsmc_fun2658__t* _self = kk_function_as(struct kk_tmcmc__mlift1685_mh__step__rmsmc_fun2658__t*, _fself);
  kk_function_t model = _self->model; /* () -> ((int) -> <exn,effects-and-types/sample,effects-and-types/sample,effects-and-types/score,effects-and-types/yield|1373> 1372) */
  kk_std_core__list new__trace = _self->new__trace; /* effects-and-types/trace_values */
  kk_tmcmc__trace__rmsmc trace = _self->trace; /* tmcmc/trace_rmsmc<1372,<effects-and-types/sample,effects-and-types/sample,effects-and-types/score,effects-and-types/yield,exn|1373>> */
  kk_effects_dash_and_dash_types__exp p2 = _self->p2; /* effects-and-types/exp */
  kk_drop_match(_self, {kk_function_dup(model);kk_std_core__list_dup(new__trace);kk_tmcmc__trace__rmsmc_dup(trace);kk_effects_dash_and_dash_types__exp_dup(p2);}, {}, _ctx)
  kk_tmcmc__trace__rmsmc _x2659;
  bool _x2660 = kk_bool_unbox(_b_2177); /*bool*/
  _x2659 = kk_tmcmc__mlift1684_mh__step__rmsmc(model, new__trace, p2, trace, _x2660, _ctx); /*tmcmc/trace_rmsmc<1372,<exn,effects-and-types/sample,effects-and-types/sample,effects-and-types/score,effects-and-types/yield|1373>>*/
  return kk_tmcmc__trace__rmsmc_box(_x2659, _ctx);
}

kk_tmcmc__trace__rmsmc kk_tmcmc__mlift1685_mh__step__rmsmc(kk_function_t model, kk_std_core__list old__trace, kk_effects_dash_and_dash_types__exp p1, kk_tmcmc__trace__rmsmc trace, kk_std_core_types__tuple2_ p2b, kk_context_t* _ctx) { /* forall<a,e> (model : () -> ((int) -> <exn,effects-and-types/sample,effects-and-types/sample,effects-and-types/score,effects-and-types/yield|e> a), old_trace : effects-and-types/trace_values, p1 : effects-and-types/exp, trace : trace_rmsmc<a,<effects-and-types/sample,effects-and-types/sample,effects-and-types/score,effects-and-types/yield,exn|e>>, p2b : (effects-and-types/trace_values, (effects-and-types/exp, a))) -> <effects-and-types/sample,effects-and-types/sample,exn,effects-and-types/yield|e> trace_rmsmc<a,<exn,effects-and-types/sample,effects-and-types/sample,effects-and-types/score,effects-and-types/yield|e>> */ 
  kk_box_t _box_x2148 = p2b.fst;
  kk_box_t _box_x2149 = p2b.snd;
  kk_std_core__list new__trace = kk_std_core__list_unbox(_box_x2148, NULL);
  kk_std_core_types__tuple2_ _pat2 = kk_std_core_types__tuple2__unbox(_box_x2149, NULL);
  kk_box_t _box_x2150 = _pat2.fst;
  kk_effects_dash_and_dash_types__exp p2 = kk_effects_dash_and_dash_types__exp_unbox(_box_x2150, NULL);
  kk_std_core__list_dup(new__trace);
  kk_std_core_types__tuple2__drop(p2b, _ctx);
  double ratio;
  double y_1798;
  double _x2637;
  double _x2638;
  kk_box_t _x2639 = kk_std_core_hnd__open_none1(kk_tmcmc__new_mlift1685_mh__step__rmsmc_fun2640(_ctx), kk_effects_dash_and_dash_types__exp_box(p2, _ctx), _ctx); /*2*/
  _x2638 = kk_double_unbox(_x2639, _ctx); /*double*/
  double _x2643;
  kk_integer_t _x2644 = kk_std_core_length_1(old__trace, _ctx); /*int*/
  _x2643 = kk_integer_as_double(_x2644,kk_context()); /*double*/
  _x2637 = (_x2638 * _x2643); /*double*/
  double _x2645;
  double _x2646;
  kk_box_t _x2647 = kk_std_core_hnd__open_none1(kk_tmcmc__new_mlift1685_mh__step__rmsmc_fun2648(_ctx), kk_effects_dash_and_dash_types__exp_box(p1, _ctx), _ctx); /*2*/
  _x2646 = kk_double_unbox(_x2647, _ctx); /*double*/
  double _x2651;
  kk_integer_t _x2652;
  kk_std_core__list _x2653 = kk_std_core__list_dup(new__trace); /*effects-and-types/trace_values*/
  _x2652 = kk_std_core_length_1(_x2653, _ctx); /*int*/
  _x2651 = kk_integer_as_double(_x2652,kk_context()); /*double*/
  _x2645 = (_x2646 * _x2651); /*double*/
  y_1798 = (_x2637 / _x2645); /*double*/
  bool _match_2322 = (0x1p0 <= y_1798); /*bool*/;
  if (_match_2322) {
    ratio = 0x1p0; /*double*/
  }
  else {
    ratio = y_1798; /*double*/
  }
  bool x0_1799;
  size_t i_1801;
  kk_std_core_hnd__htag _x2654 = kk_std_core_hnd__htag_dup(kk_effects_dash_and_dash_types__tag_sample); /*std/core/hnd/htag<effects-and-types/.hnd-sample>*/
  i_1801 = kk_std_core_hnd__evv_index(_x2654, _ctx); /*std/core/hnd/ev-index*/
  kk_evv_t w = kk_evv_swap_create1(i_1801,kk_context()); /*std/core/hnd/evv<<effects-and-types/sample,exn,effects-and-types/sample,effects-and-types/yield|1373>>*/;
  bool y0 = kk_model_dash_resources_bernoulli(ratio, _ctx); /*bool*/;
  kk_unit_t __w_l700_c9 = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x2655 = kk_std_core_hnd_yield_cont(kk_tmcmc__new_mlift1685_mh__step__rmsmc_fun2656(i_1801, _ctx), _ctx); /*3*/
    x0_1799 = kk_bool_unbox(_x2655); /*bool*/
  }
  else {
    x0_1799 = y0; /*bool*/
  }
  if (kk_yielding(kk_context())) {
    kk_box_t _x2657 = kk_std_core_hnd_yield_extend(kk_tmcmc__new_mlift1685_mh__step__rmsmc_fun2658(model, new__trace, trace, p2, _ctx), _ctx); /*2*/
    return kk_tmcmc__trace__rmsmc_unbox(_x2657, _ctx);
  }
  return kk_tmcmc__mlift1684_mh__step__rmsmc(model, new__trace, p2, trace, x0_1799, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_tmcmc__mlift1686_mh__step__rmsmc_fun2663__t {
  struct kk_function_s _base;
  kk_function_t model;
  kk_std_core__list old__trace;
  kk_tmcmc__trace__rmsmc trace;
  kk_effects_dash_and_dash_types__exp p1;
};
static kk_box_t kk_tmcmc__mlift1686_mh__step__rmsmc_fun2663(kk_function_t _fself, kk_box_t _b_2181, kk_context_t* _ctx);
static kk_function_t kk_tmcmc__new_mlift1686_mh__step__rmsmc_fun2663(kk_function_t model, kk_std_core__list old__trace, kk_tmcmc__trace__rmsmc trace, kk_effects_dash_and_dash_types__exp p1, kk_context_t* _ctx) {
  struct kk_tmcmc__mlift1686_mh__step__rmsmc_fun2663__t* _self = kk_function_alloc_as(struct kk_tmcmc__mlift1686_mh__step__rmsmc_fun2663__t, 5, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc__mlift1686_mh__step__rmsmc_fun2663, kk_context());
  _self->model = model;
  _self->old__trace = old__trace;
  _self->trace = trace;
  _self->p1 = p1;
  return &_self->_base;
}

static kk_box_t kk_tmcmc__mlift1686_mh__step__rmsmc_fun2663(kk_function_t _fself, kk_box_t _b_2181, kk_context_t* _ctx) {
  struct kk_tmcmc__mlift1686_mh__step__rmsmc_fun2663__t* _self = kk_function_as(struct kk_tmcmc__mlift1686_mh__step__rmsmc_fun2663__t*, _fself);
  kk_function_t model = _self->model; /* () -> ((int) -> <exn,effects-and-types/sample,effects-and-types/sample,effects-and-types/score,effects-and-types/yield|1373> 1372) */
  kk_std_core__list old__trace = _self->old__trace; /* effects-and-types/trace_values */
  kk_tmcmc__trace__rmsmc trace = _self->trace; /* tmcmc/trace_rmsmc<1372,<effects-and-types/sample,effects-and-types/sample,effects-and-types/score,effects-and-types/yield,exn|1373>> */
  kk_effects_dash_and_dash_types__exp p1 = _self->p1; /* effects-and-types/exp */
  kk_drop_match(_self, {kk_function_dup(model);kk_std_core__list_dup(old__trace);kk_tmcmc__trace__rmsmc_dup(trace);kk_effects_dash_and_dash_types__exp_dup(p1);}, {}, _ctx)
  kk_tmcmc__trace__rmsmc _x2664;
  kk_std_core_types__tuple2_ _x2665 = kk_std_core_types__tuple2__unbox(_b_2181, _ctx); /*(effects-and-types/trace_values, (effects-and-types/exp, 1372))*/
  _x2664 = kk_tmcmc__mlift1685_mh__step__rmsmc(model, old__trace, p1, trace, _x2665, _ctx); /*tmcmc/trace_rmsmc<1372,<exn,effects-and-types/sample,effects-and-types/sample,effects-and-types/score,effects-and-types/yield|1373>>*/
  return kk_tmcmc__trace__rmsmc_box(_x2664, _ctx);
}

kk_tmcmc__trace__rmsmc kk_tmcmc__mlift1686_mh__step__rmsmc(kk_tmcmc__trace__rmsmc trace, kk_std_core__list modified__trace, kk_context_t* _ctx) { /* forall<a,e> (trace : trace_rmsmc<a,<effects-and-types/sample,effects-and-types/sample,effects-and-types/score,effects-and-types/yield,exn|e>>, modified_trace : effects-and-types/trace_values) -> <effects-and-types/sample,exn,effects-and-types/sample,effects-and-types/yield|e> trace_rmsmc<a,<exn,effects-and-types/sample,effects-and-types/sample,effects-and-types/score,effects-and-types/yield|e>> */ 
  kk_function_t model = trace.m;
  kk_effects_dash_and_dash_types__exp p1 = trace.p;
  kk_std_core__list old__trace = trace.l;
  kk_function_dup(model);
  kk_std_core__list_dup(old__trace);
  kk_std_core_types__tuple2_ x_1804;
  kk_function_t _x2661 = kk_function_dup(model); /*() -> ((int) -> <exn,effects-and-types/sample,effects-and-types/sample,effects-and-types/score,effects-and-types/yield|1373> 1372)*/
  x_1804 = kk_tmcmc_with__randomness__rmsmc(_x2661, modified__trace, _ctx); /*(effects-and-types/trace_values, (effects-and-types/exp, 1372))*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__tuple2__drop(x_1804, _ctx);
    kk_box_t _x2662 = kk_std_core_hnd_yield_extend(kk_tmcmc__new_mlift1686_mh__step__rmsmc_fun2663(model, old__trace, trace, p1, _ctx), _ctx); /*2*/
    return kk_tmcmc__trace__rmsmc_unbox(_x2662, _ctx);
  }
  return kk_tmcmc__mlift1685_mh__step__rmsmc(model, old__trace, p1, trace, x_1804, _ctx);
}


// lift anonymous function
struct kk_tmcmc_mh__step__rmsmc_fun2668__t {
  struct kk_function_s _base;
  size_t i_1811;
};
static kk_box_t kk_tmcmc_mh__step__rmsmc_fun2668(kk_function_t _fself, kk_function_t _b_2189, kk_box_t _b_2190, kk_context_t* _ctx);
static kk_function_t kk_tmcmc_new_mh__step__rmsmc_fun2668(size_t i_1811, kk_context_t* _ctx) {
  struct kk_tmcmc_mh__step__rmsmc_fun2668__t* _self = kk_function_alloc_as(struct kk_tmcmc_mh__step__rmsmc_fun2668__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc_mh__step__rmsmc_fun2668, kk_context());
  _self->i_1811 = i_1811;
  return &_self->_base;
}

static kk_box_t kk_tmcmc_mh__step__rmsmc_fun2668(kk_function_t _fself, kk_function_t _b_2189, kk_box_t _b_2190, kk_context_t* _ctx) {
  struct kk_tmcmc_mh__step__rmsmc_fun2668__t* _self = kk_function_as(struct kk_tmcmc_mh__step__rmsmc_fun2668__t*, _fself);
  size_t i_1811 = _self->i_1811; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_1811, _b_2189, _b_2190, _ctx);
}


// lift anonymous function
struct kk_tmcmc_mh__step__rmsmc_fun2670__t {
  struct kk_function_s _base;
  kk_tmcmc__trace__rmsmc trace;
};
static kk_box_t kk_tmcmc_mh__step__rmsmc_fun2670(kk_function_t _fself, kk_box_t _b_2200, kk_context_t* _ctx);
static kk_function_t kk_tmcmc_new_mh__step__rmsmc_fun2670(kk_tmcmc__trace__rmsmc trace, kk_context_t* _ctx) {
  struct kk_tmcmc_mh__step__rmsmc_fun2670__t* _self = kk_function_alloc_as(struct kk_tmcmc_mh__step__rmsmc_fun2670__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc_mh__step__rmsmc_fun2670, kk_context());
  _self->trace = trace;
  return &_self->_base;
}

static kk_box_t kk_tmcmc_mh__step__rmsmc_fun2670(kk_function_t _fself, kk_box_t _b_2200, kk_context_t* _ctx) {
  struct kk_tmcmc_mh__step__rmsmc_fun2670__t* _self = kk_function_as(struct kk_tmcmc_mh__step__rmsmc_fun2670__t*, _fself);
  kk_tmcmc__trace__rmsmc trace = _self->trace; /* tmcmc/trace_rmsmc<1372,<effects-and-types/sample,effects-and-types/sample,effects-and-types/score,effects-and-types/yield,exn|1373>> */
  kk_drop_match(_self, {kk_tmcmc__trace__rmsmc_dup(trace);}, {}, _ctx)
  kk_tmcmc__trace__rmsmc _x2671;
  kk_std_core__list _x2672 = kk_std_core__list_unbox(_b_2200, _ctx); /*effects-and-types/trace_values*/
  _x2671 = kk_tmcmc__mlift1686_mh__step__rmsmc(trace, _x2672, _ctx); /*tmcmc/trace_rmsmc<1372,<exn,effects-and-types/sample,effects-and-types/sample,effects-and-types/score,effects-and-types/yield|1373>>*/
  return kk_tmcmc__trace__rmsmc_box(_x2671, _ctx);
}


// lift anonymous function
struct kk_tmcmc_mh__step__rmsmc_fun2675__t {
  struct kk_function_s _base;
  kk_function_t model;
  kk_std_core__list old__trace;
  kk_tmcmc__trace__rmsmc trace;
  kk_effects_dash_and_dash_types__exp p1;
};
static kk_box_t kk_tmcmc_mh__step__rmsmc_fun2675(kk_function_t _fself, kk_box_t _b_2202, kk_context_t* _ctx);
static kk_function_t kk_tmcmc_new_mh__step__rmsmc_fun2675(kk_function_t model, kk_std_core__list old__trace, kk_tmcmc__trace__rmsmc trace, kk_effects_dash_and_dash_types__exp p1, kk_context_t* _ctx) {
  struct kk_tmcmc_mh__step__rmsmc_fun2675__t* _self = kk_function_alloc_as(struct kk_tmcmc_mh__step__rmsmc_fun2675__t, 5, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc_mh__step__rmsmc_fun2675, kk_context());
  _self->model = model;
  _self->old__trace = old__trace;
  _self->trace = trace;
  _self->p1 = p1;
  return &_self->_base;
}

static kk_box_t kk_tmcmc_mh__step__rmsmc_fun2675(kk_function_t _fself, kk_box_t _b_2202, kk_context_t* _ctx) {
  struct kk_tmcmc_mh__step__rmsmc_fun2675__t* _self = kk_function_as(struct kk_tmcmc_mh__step__rmsmc_fun2675__t*, _fself);
  kk_function_t model = _self->model; /* () -> ((int) -> <exn,effects-and-types/sample,effects-and-types/sample,effects-and-types/score,effects-and-types/yield|1373> 1372) */
  kk_std_core__list old__trace = _self->old__trace; /* effects-and-types/trace_values */
  kk_tmcmc__trace__rmsmc trace = _self->trace; /* tmcmc/trace_rmsmc<1372,<effects-and-types/sample,effects-and-types/sample,effects-and-types/score,effects-and-types/yield,exn|1373>> */
  kk_effects_dash_and_dash_types__exp p1 = _self->p1; /* effects-and-types/exp */
  kk_drop_match(_self, {kk_function_dup(model);kk_std_core__list_dup(old__trace);kk_tmcmc__trace__rmsmc_dup(trace);kk_effects_dash_and_dash_types__exp_dup(p1);}, {}, _ctx)
  kk_tmcmc__trace__rmsmc _x2676;
  kk_std_core_types__tuple2_ _x2677 = kk_std_core_types__tuple2__unbox(_b_2202, _ctx); /*(effects-and-types/trace_values, (effects-and-types/exp, 1372))*/
  _x2676 = kk_tmcmc__mlift1685_mh__step__rmsmc(model, old__trace, p1, trace, _x2677, _ctx); /*tmcmc/trace_rmsmc<1372,<exn,effects-and-types/sample,effects-and-types/sample,effects-and-types/score,effects-and-types/yield|1373>>*/
  return kk_tmcmc__trace__rmsmc_box(_x2676, _ctx);
}


// lift anonymous function
struct kk_tmcmc_mh__step__rmsmc_fun2684__t {
  struct kk_function_s _base;
};
static kk_box_t kk_tmcmc_mh__step__rmsmc_fun2684(kk_function_t _fself, kk_box_t _b_2208, kk_context_t* _ctx);
static kk_function_t kk_tmcmc_new_mh__step__rmsmc_fun2684(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_tmcmc_mh__step__rmsmc_fun2684, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_tmcmc_mh__step__rmsmc_fun2684(kk_function_t _fself, kk_box_t _b_2208, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x2685;
  kk_effects_dash_and_dash_types__exp _x2686 = kk_effects_dash_and_dash_types__exp_unbox(_b_2208, _ctx); /*effects-and-types/exp*/
  _x2685 = kk_exponents_exp__to__double(_x2686, _ctx); /*double*/
  return kk_double_box(_x2685, _ctx);
}


// lift anonymous function
struct kk_tmcmc_mh__step__rmsmc_fun2692__t {
  struct kk_function_s _base;
};
static kk_box_t kk_tmcmc_mh__step__rmsmc_fun2692(kk_function_t _fself, kk_box_t _b_2211, kk_context_t* _ctx);
static kk_function_t kk_tmcmc_new_mh__step__rmsmc_fun2692(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_tmcmc_mh__step__rmsmc_fun2692, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_tmcmc_mh__step__rmsmc_fun2692(kk_function_t _fself, kk_box_t _b_2211, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x2693;
  kk_effects_dash_and_dash_types__exp _x2694 = kk_effects_dash_and_dash_types__exp_unbox(_b_2211, _ctx); /*effects-and-types/exp*/
  _x2693 = kk_exponents_exp__to__double(_x2694, _ctx); /*double*/
  return kk_double_box(_x2693, _ctx);
}


// lift anonymous function
struct kk_tmcmc_mh__step__rmsmc_fun2700__t {
  struct kk_function_s _base;
  size_t i0_1824;
};
static kk_box_t kk_tmcmc_mh__step__rmsmc_fun2700(kk_function_t _fself, kk_function_t _b_2221, kk_box_t _b_2222, kk_context_t* _ctx);
static kk_function_t kk_tmcmc_new_mh__step__rmsmc_fun2700(size_t i0_1824, kk_context_t* _ctx) {
  struct kk_tmcmc_mh__step__rmsmc_fun2700__t* _self = kk_function_alloc_as(struct kk_tmcmc_mh__step__rmsmc_fun2700__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc_mh__step__rmsmc_fun2700, kk_context());
  _self->i0_1824 = i0_1824;
  return &_self->_base;
}

static kk_box_t kk_tmcmc_mh__step__rmsmc_fun2700(kk_function_t _fself, kk_function_t _b_2221, kk_box_t _b_2222, kk_context_t* _ctx) {
  struct kk_tmcmc_mh__step__rmsmc_fun2700__t* _self = kk_function_as(struct kk_tmcmc_mh__step__rmsmc_fun2700__t*, _fself);
  size_t i0_1824 = _self->i0_1824; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i0_1824, _b_2221, _b_2222, _ctx);
}


// lift anonymous function
struct kk_tmcmc_mh__step__rmsmc_fun2702__t {
  struct kk_function_s _base;
  kk_function_t model;
  kk_std_core__list new__trace;
  kk_tmcmc__trace__rmsmc trace;
  kk_effects_dash_and_dash_types__exp p2;
};
static kk_box_t kk_tmcmc_mh__step__rmsmc_fun2702(kk_function_t _fself, kk_box_t _b_2232, kk_context_t* _ctx);
static kk_function_t kk_tmcmc_new_mh__step__rmsmc_fun2702(kk_function_t model, kk_std_core__list new__trace, kk_tmcmc__trace__rmsmc trace, kk_effects_dash_and_dash_types__exp p2, kk_context_t* _ctx) {
  struct kk_tmcmc_mh__step__rmsmc_fun2702__t* _self = kk_function_alloc_as(struct kk_tmcmc_mh__step__rmsmc_fun2702__t, 5, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc_mh__step__rmsmc_fun2702, kk_context());
  _self->model = model;
  _self->new__trace = new__trace;
  _self->trace = trace;
  _self->p2 = p2;
  return &_self->_base;
}

static kk_box_t kk_tmcmc_mh__step__rmsmc_fun2702(kk_function_t _fself, kk_box_t _b_2232, kk_context_t* _ctx) {
  struct kk_tmcmc_mh__step__rmsmc_fun2702__t* _self = kk_function_as(struct kk_tmcmc_mh__step__rmsmc_fun2702__t*, _fself);
  kk_function_t model = _self->model; /* () -> ((int) -> <exn,effects-and-types/sample,effects-and-types/sample,effects-and-types/score,effects-and-types/yield|1373> 1372) */
  kk_std_core__list new__trace = _self->new__trace; /* effects-and-types/trace_values */
  kk_tmcmc__trace__rmsmc trace = _self->trace; /* tmcmc/trace_rmsmc<1372,<effects-and-types/sample,effects-and-types/sample,effects-and-types/score,effects-and-types/yield,exn|1373>> */
  kk_effects_dash_and_dash_types__exp p2 = _self->p2; /* effects-and-types/exp */
  kk_drop_match(_self, {kk_function_dup(model);kk_std_core__list_dup(new__trace);kk_tmcmc__trace__rmsmc_dup(trace);kk_effects_dash_and_dash_types__exp_dup(p2);}, {}, _ctx)
  kk_tmcmc__trace__rmsmc _x2703;
  bool _x2704 = kk_bool_unbox(_b_2232); /*bool*/
  _x2703 = kk_tmcmc__mlift1684_mh__step__rmsmc(model, new__trace, p2, trace, _x2704, _ctx); /*tmcmc/trace_rmsmc<1372,<exn,effects-and-types/sample,effects-and-types/sample,effects-and-types/score,effects-and-types/yield|1373>>*/
  return kk_tmcmc__trace__rmsmc_box(_x2703, _ctx);
}

kk_tmcmc__trace__rmsmc kk_tmcmc_mh__step__rmsmc(kk_tmcmc__trace__rmsmc trace, kk_context_t* _ctx) { /* forall<a,e> (trace : trace_rmsmc<a,<effects-and-types/sample,effects-and-types/sample,effects-and-types/score,effects-and-types/yield,exn|e>>) -> <effects-and-types/sample,effects-and-types/sample,effects-and-types/yield,exn|e> trace_rmsmc<a,<effects-and-types/sample,effects-and-types/sample,effects-and-types/score,effects-and-types/yield,exn|e>> */ 
  kk_std_core__list x_1806;
  kk_std_core__list _x1;
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*std/core/hnd/evv<(<>)>*/;
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  kk_effects_dash_and_dash_types__exp _pat1 = trace.p;
  kk_std_core__list _x = trace.l;
  kk_std_core__list_dup(_x);
  _x1 = _x; /*effects-and-types/trace_values*/
  size_t i_1811;
  kk_std_core_hnd__htag _x2666 = kk_std_core_hnd__htag_dup(kk_effects_dash_and_dash_types__tag_sample); /*std/core/hnd/htag<effects-and-types/.hnd-sample>*/
  i_1811 = kk_std_core_hnd__evv_index(_x2666, _ctx); /*std/core/hnd/ev-index*/
  kk_evv_t w0 = kk_evv_swap_create1(i_1811,kk_context()); /*std/core/hnd/evv<<effects-and-types/sample,exn,effects-and-types/sample,effects-and-types/yield|1373>>*/;
  kk_std_core__list y = kk_tmcmc_perturb__trace(_x1, _ctx); /*effects-and-types/trace_values*/;
  kk_unit_t __w_l700_c9 = kk_Unit;
  kk_evv_set(w0,kk_context());
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(y, _ctx);
    kk_box_t _x2667 = kk_std_core_hnd_yield_cont(kk_tmcmc_new_mh__step__rmsmc_fun2668(i_1811, _ctx), _ctx); /*3*/
    x_1806 = kk_std_core__list_unbox(_x2667, _ctx); /*effects-and-types/trace_values*/
  }
  else {
    x_1806 = y; /*effects-and-types/trace_values*/
  }
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_1806, _ctx);
    kk_box_t _x2669 = kk_std_core_hnd_yield_extend(kk_tmcmc_new_mh__step__rmsmc_fun2670(trace, _ctx), _ctx); /*2*/
    return kk_tmcmc__trace__rmsmc_unbox(_x2669, _ctx);
  }
  kk_function_t model = trace.m;
  kk_effects_dash_and_dash_types__exp p1 = trace.p;
  kk_std_core__list old__trace = trace.l;
  kk_function_dup(model);
  kk_std_core__list_dup(old__trace);
  kk_std_core_types__tuple2_ x3_1815;
  kk_function_t _x2673 = kk_function_dup(model); /*() -> ((int) -> <exn,effects-and-types/sample,effects-and-types/sample,effects-and-types/score,effects-and-types/yield|1373> 1372)*/
  x3_1815 = kk_tmcmc_with__randomness__rmsmc(_x2673, x_1806, _ctx); /*(effects-and-types/trace_values, (effects-and-types/exp, 1372))*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__tuple2__drop(x3_1815, _ctx);
    kk_box_t _x2674 = kk_std_core_hnd_yield_extend(kk_tmcmc_new_mh__step__rmsmc_fun2675(model, old__trace, trace, p1, _ctx), _ctx); /*2*/
    return kk_tmcmc__trace__rmsmc_unbox(_x2674, _ctx);
  }
  kk_box_t _box_x2203 = x3_1815.fst;
  kk_box_t _box_x2204 = x3_1815.snd;
  kk_std_core__list new__trace = kk_std_core__list_unbox(_box_x2203, NULL);
  kk_std_core_types__tuple2_ _pat200 = kk_std_core_types__tuple2__unbox(_box_x2204, NULL);
  kk_box_t _box_x2205 = _pat200.fst;
  kk_effects_dash_and_dash_types__exp p2 = kk_effects_dash_and_dash_types__exp_unbox(_box_x2205, NULL);
  kk_std_core__list_dup(new__trace);
  kk_std_core_types__tuple2__drop(x3_1815, _ctx);
  double ratio;
  double y0_1820;
  double _x2681;
  double _x2682;
  kk_box_t _x2683 = kk_std_core_hnd__open_none1(kk_tmcmc_new_mh__step__rmsmc_fun2684(_ctx), kk_effects_dash_and_dash_types__exp_box(p2, _ctx), _ctx); /*2*/
  _x2682 = kk_double_unbox(_x2683, _ctx); /*double*/
  double _x2687;
  kk_integer_t _x2688 = kk_std_core_length_1(old__trace, _ctx); /*int*/
  _x2687 = kk_integer_as_double(_x2688,kk_context()); /*double*/
  _x2681 = (_x2682 * _x2687); /*double*/
  double _x2689;
  double _x2690;
  kk_box_t _x2691 = kk_std_core_hnd__open_none1(kk_tmcmc_new_mh__step__rmsmc_fun2692(_ctx), kk_effects_dash_and_dash_types__exp_box(p1, _ctx), _ctx); /*2*/
  _x2690 = kk_double_unbox(_x2691, _ctx); /*double*/
  double _x2695;
  kk_integer_t _x2696;
  kk_std_core__list _x2697 = kk_std_core__list_dup(new__trace); /*effects-and-types/trace_values*/
  _x2696 = kk_std_core_length_1(_x2697, _ctx); /*int*/
  _x2695 = kk_integer_as_double(_x2696,kk_context()); /*double*/
  _x2689 = (_x2690 * _x2695); /*double*/
  y0_1820 = (_x2681 / _x2689); /*double*/
  bool _match_2317 = (0x1p0 <= y0_1820); /*bool*/;
  if (_match_2317) {
    ratio = 0x1p0; /*double*/
  }
  else {
    ratio = y0_1820; /*double*/
  }
  bool x5_1821;
  size_t i0_1824;
  kk_std_core_hnd__htag _x2698 = kk_std_core_hnd__htag_dup(kk_effects_dash_and_dash_types__tag_sample); /*std/core/hnd/htag<effects-and-types/.hnd-sample>*/
  i0_1824 = kk_std_core_hnd__evv_index(_x2698, _ctx); /*std/core/hnd/ev-index*/
  kk_evv_t w1 = kk_evv_swap_create1(i0_1824,kk_context()); /*std/core/hnd/evv<<effects-and-types/sample,exn,effects-and-types/sample,effects-and-types/yield|1373>>*/;
  bool y1 = kk_model_dash_resources_bernoulli(ratio, _ctx); /*bool*/;
  kk_unit_t __w_l700_c90 = kk_Unit;
  kk_evv_set(w1,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x2699 = kk_std_core_hnd_yield_cont(kk_tmcmc_new_mh__step__rmsmc_fun2700(i0_1824, _ctx), _ctx); /*3*/
    x5_1821 = kk_bool_unbox(_x2699); /*bool*/
  }
  else {
    x5_1821 = y1; /*bool*/
  }
  if (kk_yielding(kk_context())) {
    kk_box_t _x2701 = kk_std_core_hnd_yield_extend(kk_tmcmc_new_mh__step__rmsmc_fun2702(model, new__trace, trace, p2, _ctx), _ctx); /*2*/
    return kk_tmcmc__trace__rmsmc_unbox(_x2701, _ctx);
  }
  if (x5_1821) {
    kk_tmcmc__trace__rmsmc_drop(trace, _ctx);
    return kk_tmcmc__new_RTrace(model, p2, new__trace, _ctx);
  }
  kk_function_drop(model, _ctx);
  kk_std_core__list_drop(new__trace, _ctx);
  return trace;
}
 
// monadic lift

kk_std_core_types__tuple2_ kk_tmcmc__mlift1687_model__stepper__recursive(kk_integer_t burnin, kk_std_core__list posterior, kk_integer_t steps, kk_tmcmc__trace new__trace, kk_context_t* _ctx) { /* forall<a,e> (burnin : int, posterior : list<(list<double>, a)>, steps : int, new_trace : trace<a,<effects-and-types/sample,effects-and-types/score,div|e>>) -> <effects-and-types/sample,div|e> (list<(list<double>, a)>, trace<a,<effects-and-types/sample,effects-and-types/score,div|e>>) */ 
  bool _match_2312;
  kk_integer_t _x2705 = kk_integer_dup(burnin); /*int*/
  _match_2312 = kk_integer_gt(_x2705,(kk_integer_from_small(0)),kk_context()); /*bool*/
  if (_match_2312) {
    kk_integer_t _x2706 = kk_integer_sub(steps,(kk_integer_from_small(1)),kk_context()); /*int*/
    kk_integer_t _x2707 = kk_integer_sub(burnin,(kk_integer_from_small(1)),kk_context()); /*int*/
    return kk_tmcmc_model__stepper__recursive(_x2706, new__trace, posterior, _x2707, _ctx);
  }
  kk_integer_t _x2708 = kk_integer_sub(steps,(kk_integer_from_small(1)),kk_context()); /*int*/
  kk_tmcmc__trace _x2709 = kk_tmcmc__trace_dup(new__trace); /*tmcmc/trace<1597,<effects-and-types/sample,effects-and-types/score,div|1598>>*/
  kk_std_core__list _x2710;
  kk_std_core__list ys_1829;
  kk_std_core_types__tuple2_ _b_2243_2241;
  kk_std_core__list _b_2245_2239;
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*std/core/hnd/evv<(<>)>*/;
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  struct kk_tmcmc_Trace* _con2711 = kk_tmcmc__as_Trace(new__trace);
  kk_effects_dash_and_dash_types__exp _pat10 = _con2711->p;
  kk_std_core__list _x = _con2711->l;
  kk_std_core__list_dup(_x);
  _b_2245_2239 = _x; /*effects-and-types/trace_values*/
  kk_box_t _b_2246_2240;
  kk_evv_t w0 = kk_evv_swap_create0(kk_context()); /*std/core/hnd/evv<(<>)>*/;
  kk_unit_t keep0 = kk_Unit;
  kk_evv_set(w0,kk_context());
  struct kk_tmcmc_Trace* _con2712 = kk_tmcmc__as_Trace(new__trace);
  kk_function_t _pat00 = _con2712->m;
  kk_effects_dash_and_dash_types__exp _pat11 = _con2712->p;
  kk_std_core__list _pat30 = _con2712->l;
  kk_box_t _x0 = _con2712->a;
  if (kk_tmcmc__trace_is_unique(new__trace)) {
    kk_std_core__list_drop(_pat30, _ctx);
    kk_function_drop(_pat00, _ctx);
    kk_tmcmc__trace_free(new__trace);
  }
  else {
    kk_box_dup(_x0);
    kk_tmcmc__trace_decref(new__trace, _ctx);
  }
  _b_2246_2240 = _x0; /*1597*/
  _b_2243_2241 = kk_std_core_types__new_dash__lp__comma__rp_(kk_std_core__list_box(_b_2245_2239, _ctx), _b_2246_2240, _ctx); /*(effects-and-types/trace_values, 1597)*/
  ys_1829 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core_types__tuple2__box(_b_2243_2241, _ctx), kk_std_core__new_Nil(_ctx), _ctx); /*list<(list<double>, 1597)>*/
  _x2710 = kk_std_core_append(posterior, ys_1829, _ctx); /*list<1>*/
  return kk_tmcmc_model__stepper__recursive(_x2708, _x2709, _x2710, burnin, _ctx);
}


// lift anonymous function
struct kk_tmcmc_model__stepper__recursive_fun2715__t {
  struct kk_function_s _base;
  kk_integer_t burnin0;
  kk_std_core__list posterior0;
  kk_integer_t steps0;
};
static kk_box_t kk_tmcmc_model__stepper__recursive_fun2715(kk_function_t _fself, kk_box_t _b_2250, kk_context_t* _ctx);
static kk_function_t kk_tmcmc_new_model__stepper__recursive_fun2715(kk_integer_t burnin0, kk_std_core__list posterior0, kk_integer_t steps0, kk_context_t* _ctx) {
  struct kk_tmcmc_model__stepper__recursive_fun2715__t* _self = kk_function_alloc_as(struct kk_tmcmc_model__stepper__recursive_fun2715__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc_model__stepper__recursive_fun2715, kk_context());
  _self->burnin0 = burnin0;
  _self->posterior0 = posterior0;
  _self->steps0 = steps0;
  return &_self->_base;
}

static kk_box_t kk_tmcmc_model__stepper__recursive_fun2715(kk_function_t _fself, kk_box_t _b_2250, kk_context_t* _ctx) {
  struct kk_tmcmc_model__stepper__recursive_fun2715__t* _self = kk_function_as(struct kk_tmcmc_model__stepper__recursive_fun2715__t*, _fself);
  kk_integer_t burnin0 = _self->burnin0; /* int */
  kk_std_core__list posterior0 = _self->posterior0; /* list<(list<double>, 1597)> */
  kk_integer_t steps0 = _self->steps0; /* int */
  kk_drop_match(_self, {kk_integer_dup(burnin0);kk_std_core__list_dup(posterior0);kk_integer_dup(steps0);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x2716;
  kk_tmcmc__trace _x2717 = kk_tmcmc__trace_unbox(_b_2250, _ctx); /*tmcmc/trace<1597,<effects-and-types/sample,effects-and-types/score,div|1598>>*/
  _x2716 = kk_tmcmc__mlift1687_model__stepper__recursive(burnin0, posterior0, steps0, _x2717, _ctx); /*(list<(list<double>, 1597)>, tmcmc/trace<1597,<effects-and-types/sample,effects-and-types/score,div|1598>>)*/
  return kk_std_core_types__tuple2__box(_x2716, _ctx);
}

kk_std_core_types__tuple2_ kk_tmcmc_model__stepper__recursive(kk_integer_t steps0, kk_tmcmc__trace trace, kk_std_core__list posterior0, kk_integer_t burnin0, kk_context_t* _ctx) { /* forall<a,e> (steps : int, trace : trace<a,<effects-and-types/sample,effects-and-types/score,div|e>>, posterior : list<(list<double>, a)>, burnin : int) -> <effects-and-types/sample,div|e> (list<(list<double>, a)>, trace<a,<effects-and-types/sample,effects-and-types/score,div|e>>) */ 
  kk__tailcall: ;
  bool _match_2309;
  kk_integer_t _x2713 = kk_integer_dup(steps0); /*int*/
  _match_2309 = kk_integer_lt(_x2713,(kk_integer_from_small(1)),kk_context()); /*bool*/
  if (_match_2309) {
    kk_integer_drop(burnin0, _ctx);
    kk_integer_drop(steps0, _ctx);
    return kk_std_core_types__new_dash__lp__comma__rp_(kk_std_core__list_box(posterior0, _ctx), kk_tmcmc__trace_box(trace, _ctx), _ctx);
  }
  kk_tmcmc__trace x_1834 = kk_tmcmc_mh__step(trace, _ctx); /*tmcmc/trace<1597,<effects-and-types/sample,effects-and-types/score,div|1598>>*/;
  if (kk_yielding(kk_context())) {
    kk_tmcmc__trace_dropn(x_1834, ((int32_t)3), _ctx);
    kk_box_t _x2714 = kk_std_core_hnd_yield_extend(kk_tmcmc_new_model__stepper__recursive_fun2715(burnin0, posterior0, steps0, _ctx), _ctx); /*2*/
    return kk_std_core_types__tuple2__unbox(_x2714, _ctx);
  }
  bool _match_2311;
  kk_integer_t _x2718 = kk_integer_dup(burnin0); /*int*/
  _match_2311 = kk_integer_gt(_x2718,(kk_integer_from_small(0)),kk_context()); /*bool*/
  if (_match_2311) {
    { // tailcall
      kk_integer_t _x2719 = kk_integer_sub(steps0,(kk_integer_from_small(1)),kk_context()); /*int*/
      kk_integer_t _x2720 = kk_integer_sub(burnin0,(kk_integer_from_small(1)),kk_context()); /*int*/
      steps0 = _x2719;
      trace = x_1834;
      burnin0 = _x2720;
      goto kk__tailcall;
    }
  }
  { // tailcall
    kk_integer_t _x2721 = kk_integer_sub(steps0,(kk_integer_from_small(1)),kk_context()); /*int*/
    kk_tmcmc__trace _x2722 = kk_tmcmc__trace_dup(x_1834); /*tmcmc/trace<1597,<effects-and-types/sample,effects-and-types/score,div|1598>>*/
    kk_std_core__list _x2723;
    kk_std_core__list ys_1839;
    kk_std_core_types__tuple2_ _b_2255_2253;
    kk_std_core__list _b_2257_2251;
    kk_evv_t w1 = kk_evv_swap_create0(kk_context()); /*std/core/hnd/evv<(<>)>*/;
    kk_unit_t keep1 = kk_Unit;
    kk_evv_set(w1,kk_context());
    struct kk_tmcmc_Trace* _con2724 = kk_tmcmc__as_Trace(x_1834);
    kk_effects_dash_and_dash_types__exp _pat110 = _con2724->p;
    kk_std_core__list _x1 = _con2724->l;
    kk_std_core__list_dup(_x1);
    _b_2257_2251 = _x1; /*effects-and-types/trace_values*/
    kk_box_t _b_2258_2252;
    kk_evv_t w00 = kk_evv_swap_create0(kk_context()); /*std/core/hnd/evv<(<>)>*/;
    kk_unit_t keep00 = kk_Unit;
    kk_evv_set(w00,kk_context());
    struct kk_tmcmc_Trace* _con2725 = kk_tmcmc__as_Trace(x_1834);
    kk_function_t _pat02 = _con2725->m;
    kk_effects_dash_and_dash_types__exp _pat120 = _con2725->p;
    kk_std_core__list _pat310 = _con2725->l;
    kk_box_t _x00 = _con2725->a;
    if (kk_tmcmc__trace_is_unique(x_1834)) {
      kk_std_core__list_drop(_pat310, _ctx);
      kk_function_drop(_pat02, _ctx);
      kk_tmcmc__trace_free(x_1834);
    }
    else {
      kk_box_dup(_x00);
      kk_tmcmc__trace_decref(x_1834, _ctx);
    }
    _b_2258_2252 = _x00; /*1597*/
    _b_2255_2253 = kk_std_core_types__new_dash__lp__comma__rp_(kk_std_core__list_box(_b_2257_2251, _ctx), _b_2258_2252, _ctx); /*(effects-and-types/trace_values, 1597)*/
    ys_1839 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core_types__tuple2__box(_b_2255_2253, _ctx), kk_std_core__new_Nil(_ctx), _ctx); /*list<(list<double>, 1597)>*/
    _x2723 = kk_std_core_append(posterior0, ys_1839, _ctx); /*list<1>*/
    steps0 = _x2721;
    trace = _x2722;
    posterior0 = _x2723;
    goto kk__tailcall;
  }
}
 
// monadic lift

kk_std_core_types__tuple2_ kk_tmcmc__mlift1688_tmcmc(kk_integer_t burnin, kk_function_t model, kk_integer_t steps, kk_std_core_types__tuple2_ model__results, kk_context_t* _ctx) { /* forall<a,e> (burnin : int, model : () -> <effects-and-types/sample,effects-and-types/score,div|e> a, steps : int, model_results : (effects-and-types/exp, (list<double>, a))) -> <div,effects-and-types/sample|e> (list<(list<double>, a)>, trace<a,<effects-and-types/sample,effects-and-types/score,div|e>>) */ 
  kk_box_t _box_x2263 = model__results.fst;
  kk_box_t _box_x2264 = model__results.snd;
  kk_effects_dash_and_dash_types__exp p0 = kk_effects_dash_and_dash_types__exp_unbox(_box_x2263, NULL);
  kk_std_core_types__tuple2_ _pat1 = kk_std_core_types__tuple2__unbox(_box_x2264, NULL);
  kk_box_t _box_x2265 = _pat1.fst;
  kk_box_t a0 = _pat1.snd;
  kk_std_core__list d = kk_std_core__list_unbox(_box_x2265, NULL);
  kk_box_dup(a0);
  kk_std_core__list_dup(d);
  kk_std_core_types__tuple2__drop(model__results, _ctx);
  kk_tmcmc__trace _x2729 = kk_tmcmc__new_Trace(kk_reuse_null, model, p0, d, a0, _ctx); /*tmcmc/trace<5,6>*/
  return kk_tmcmc_model__stepper__recursive(steps, _x2729, kk_std_core__new_Nil(_ctx), burnin, _ctx);
}


// lift anonymous function
struct kk_tmcmc_tmcmc_fun2731__t {
  struct kk_function_s _base;
  kk_function_t model;
};
static kk_box_t kk_tmcmc_tmcmc_fun2731(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_tmcmc_new_tmcmc_fun2731(kk_function_t model, kk_context_t* _ctx) {
  struct kk_tmcmc_tmcmc_fun2731__t* _self = kk_function_alloc_as(struct kk_tmcmc_tmcmc_fun2731__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc_tmcmc_fun2731, kk_context());
  _self->model = model;
  return &_self->_base;
}



// lift anonymous function
struct kk_tmcmc_tmcmc_fun2733__t {
  struct kk_function_s _base;
  kk_function_t model;
};
static kk_box_t kk_tmcmc_tmcmc_fun2733(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_tmcmc_new_tmcmc_fun2733(kk_function_t model, kk_context_t* _ctx) {
  struct kk_tmcmc_tmcmc_fun2733__t* _self = kk_function_alloc_as(struct kk_tmcmc_tmcmc_fun2733__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc_tmcmc_fun2733, kk_context());
  _self->model = model;
  return &_self->_base;
}



// lift anonymous function
struct kk_tmcmc_tmcmc_fun2735__t {
  struct kk_function_s _base;
  kk_function_t model;
};
static kk_box_t kk_tmcmc_tmcmc_fun2735(kk_function_t _fself, kk_box_t _b_2267, kk_context_t* _ctx);
static kk_function_t kk_tmcmc_new_tmcmc_fun2735(kk_function_t model, kk_context_t* _ctx) {
  struct kk_tmcmc_tmcmc_fun2735__t* _self = kk_function_alloc_as(struct kk_tmcmc_tmcmc_fun2735__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc_tmcmc_fun2735, kk_context());
  _self->model = model;
  return &_self->_base;
}

static kk_box_t kk_tmcmc_tmcmc_fun2735(kk_function_t _fself, kk_box_t _b_2267, kk_context_t* _ctx) {
  struct kk_tmcmc_tmcmc_fun2735__t* _self = kk_function_as(struct kk_tmcmc_tmcmc_fun2735__t*, _fself);
  kk_function_t model = _self->model; /* () -> <effects-and-types/sample,effects-and-types/score,div|1657> 1656 */
  kk_drop_match(_self, {kk_function_dup(model);}, {}, _ctx)
  size_t _x2736 = kk_size_unbox(_b_2267, _ctx); /*std/core/hnd/ev-index*/
  return kk_handlers__mlift2541_replay(model, _x2736, _ctx);
}
static kk_box_t kk_tmcmc_tmcmc_fun2733(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_tmcmc_tmcmc_fun2733__t* _self = kk_function_as(struct kk_tmcmc_tmcmc_fun2733__t*, _fself);
  kk_function_t model = _self->model; /* () -> <effects-and-types/sample,effects-and-types/score,div|1657> 1656 */
  kk_drop_match(_self, {kk_function_dup(model);}, {}, _ctx)
  size_t x_2685;
  kk_std_core_hnd__htag _x2734 = kk_std_core_hnd__htag_dup(kk_effects_dash_and_dash_types__tag_sample); /*std/core/hnd/htag<effects-and-types/.hnd-sample>*/
  x_2685 = kk_std_core_hnd__evv_index(_x2734, _ctx); /*std/core/hnd/ev-index*/
  if (kk_yielding(kk_context())) {
    return kk_std_core_hnd_yield_extend(kk_tmcmc_new_tmcmc_fun2735(model, _ctx), _ctx);
  }
  return kk_handlers__mlift2541_replay(model, x_2685, _ctx);
}
static kk_box_t kk_tmcmc_tmcmc_fun2731(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_tmcmc_tmcmc_fun2731__t* _self = kk_function_as(struct kk_tmcmc_tmcmc_fun2731__t*, _fself);
  kk_function_t model = _self->model; /* () -> <effects-and-types/sample,effects-and-types/score,div|1657> 1656 */
  kk_drop_match(_self, {kk_function_dup(model);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x2732 = kk_handlers_replayx(kk_std_core__new_Nil(_ctx), kk_tmcmc_new_tmcmc_fun2733(model, _ctx), _ctx); /*(list<double>, 0)*/
  return kk_std_core_types__tuple2__box(_x2732, _ctx);
}


// lift anonymous function
struct kk_tmcmc_tmcmc_fun2738__t {
  struct kk_function_s _base;
  kk_integer_t burnin;
  kk_function_t model;
  kk_integer_t steps;
};
static kk_box_t kk_tmcmc_tmcmc_fun2738(kk_function_t _fself, kk_box_t _b_2275, kk_context_t* _ctx);
static kk_function_t kk_tmcmc_new_tmcmc_fun2738(kk_integer_t burnin, kk_function_t model, kk_integer_t steps, kk_context_t* _ctx) {
  struct kk_tmcmc_tmcmc_fun2738__t* _self = kk_function_alloc_as(struct kk_tmcmc_tmcmc_fun2738__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc_tmcmc_fun2738, kk_context());
  _self->burnin = burnin;
  _self->model = model;
  _self->steps = steps;
  return &_self->_base;
}

static kk_box_t kk_tmcmc_tmcmc_fun2738(kk_function_t _fself, kk_box_t _b_2275, kk_context_t* _ctx) {
  struct kk_tmcmc_tmcmc_fun2738__t* _self = kk_function_as(struct kk_tmcmc_tmcmc_fun2738__t*, _fself);
  kk_integer_t burnin = _self->burnin; /* int */
  kk_function_t model = _self->model; /* () -> <effects-and-types/sample,effects-and-types/score,div|1657> 1656 */
  kk_integer_t steps = _self->steps; /* int */
  kk_drop_match(_self, {kk_integer_dup(burnin);kk_function_dup(model);kk_integer_dup(steps);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x2739;
  kk_std_core_types__tuple2_ _x2740 = kk_std_core_types__tuple2__unbox(_b_2275, _ctx); /*(effects-and-types/exp, (list<double>, 1656))*/
  _x2739 = kk_tmcmc__mlift1688_tmcmc(burnin, model, steps, _x2740, _ctx); /*(list<(list<double>, 1656)>, tmcmc/trace<1656,<effects-and-types/sample,effects-and-types/score,div|1657>>)*/
  return kk_std_core_types__tuple2__box(_x2739, _ctx);
}

kk_std_core_types__tuple2_ kk_tmcmc_tmcmc(kk_function_t model, kk_integer_t steps, kk_effects_dash_and_dash_types__exp init__weight, kk_integer_t burnin, kk_context_t* _ctx) { /* forall<a,e> (model : () -> <effects-and-types/sample,effects-and-types/score,div|e> a, steps : int, init_weight : effects-and-types/exp, burnin : int) -> <effects-and-types/sample,div|e> (list<(list<double>, a)>, trace<a,<effects-and-types/sample,effects-and-types/score,div|e>>) */ 
  kk_std_core_types__tuple2_ x_1844;
  kk_function_t _x2730;
  kk_function_dup(model);
  _x2730 = kk_tmcmc_new_tmcmc_fun2731(model, _ctx); /*() -> <effects-and-types/score|1> 0*/
  x_1844 = kk_handlers_weighted(init__weight, _x2730, _ctx); /*(effects-and-types/exp, (list<double>, 1656))*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__tuple2__drop(x_1844, _ctx);
    kk_box_t _x2737 = kk_std_core_hnd_yield_extend(kk_tmcmc_new_tmcmc_fun2738(burnin, model, steps, _ctx), _ctx); /*2*/
    return kk_std_core_types__tuple2__unbox(_x2737, _ctx);
  }
  kk_box_t _box_x2276 = x_1844.fst;
  kk_box_t _box_x2277 = x_1844.snd;
  kk_effects_dash_and_dash_types__exp p0 = kk_effects_dash_and_dash_types__exp_unbox(_box_x2276, NULL);
  kk_std_core_types__tuple2_ _pat10 = kk_std_core_types__tuple2__unbox(_box_x2277, NULL);
  kk_box_t _box_x2278 = _pat10.fst;
  kk_box_t a0 = _pat10.snd;
  kk_std_core__list d = kk_std_core__list_unbox(_box_x2278, NULL);
  kk_box_dup(a0);
  kk_std_core__list_dup(d);
  kk_std_core_types__tuple2__drop(x_1844, _ctx);
  kk_tmcmc__trace _x2744 = kk_tmcmc__new_Trace(kk_reuse_null, model, p0, d, a0, _ctx); /*tmcmc/trace<5,6>*/
  return kk_tmcmc_model__stepper__recursive(steps, _x2744, kk_std_core__new_Nil(_ctx), burnin, _ctx);
}

// initialization
void kk_tmcmc__init(kk_context_t* _ctx){
  static bool _initialized = false;
  if (_initialized) return;
  _initialized = true;
  kk_std_core_types__init(_ctx);
  kk_std_core_hnd__init(_ctx);
  kk_std_core__init(_ctx);
  kk_effects_dash_and_dash_types__init(_ctx);
  kk_exponents__init(_ctx);
  kk_handlers__init(_ctx);
  kk_model_dash_resources__init(_ctx);
}
