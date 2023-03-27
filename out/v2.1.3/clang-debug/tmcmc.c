// Koka generated module: "tmcmc", koka version: 2.1.3
#include "tmcmc.h"
 
// monadic lift

kk_tmcmc__trace kk_tmcmc__mlift1703_op(kk_function_t _c_1, kk_effects_dash_and_dash_types__exp _c_2, kk_std_core__list _c_3, kk_box_t _c_4, kk_context_t* _ctx) { /* forall<a,e> (() -> e a, effects-and-types/exp, effects-and-types/trace_values, a) -> trace<a,e> */ 
  return kk_tmcmc__new_Trace(kk_reuse_null, _c_1, _c_2, _c_3, _c_4, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_tmcmc__mlift1704_op_fun2393__t {
  struct kk_function_s _base;
  kk_function_t _c_1;
  kk_std_core__list _c_3;
  kk_effects_dash_and_dash_types__exp _c_2;
};
static kk_box_t kk_tmcmc__mlift1704_op_fun2393(kk_function_t _fself, kk_box_t _b_1903, kk_context_t* _ctx);
static kk_function_t kk_tmcmc__new_mlift1704_op_fun2393(kk_function_t _c_1, kk_std_core__list _c_3, kk_effects_dash_and_dash_types__exp _c_2, kk_context_t* _ctx) {
  struct kk_tmcmc__mlift1704_op_fun2393__t* _self = kk_function_alloc_as(struct kk_tmcmc__mlift1704_op_fun2393__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc__mlift1704_op_fun2393, kk_context());
  _self->_c_1 = _c_1;
  _self->_c_3 = _c_3;
  _self->_c_2 = _c_2;
  return &_self->_base;
}

static kk_box_t kk_tmcmc__mlift1704_op_fun2393(kk_function_t _fself, kk_box_t _b_1903, kk_context_t* _ctx) {
  struct kk_tmcmc__mlift1704_op_fun2393__t* _self = kk_function_as(struct kk_tmcmc__mlift1704_op_fun2393__t*, _fself);
  kk_function_t _c_1 = _self->_c_1; /* () -> 265 264 */
  kk_std_core__list _c_3 = _self->_c_3; /* effects-and-types/trace_values */
  kk_effects_dash_and_dash_types__exp _c_2 = _self->_c_2; /* effects-and-types/exp */
  kk_drop_match(_self, {kk_function_dup(_c_1);kk_std_core__list_dup(_c_3);kk_effects_dash_and_dash_types__exp_dup(_c_2);}, {}, _ctx)
  kk_tmcmc__trace _x2394 = kk_tmcmc__mlift1703_op(_c_1, _c_2, _c_3, _b_1903, _ctx); /*tmcmc/trace<264,265>*/
  return kk_tmcmc__trace_box(_x2394, _ctx);
}

kk_tmcmc__trace kk_tmcmc__mlift1704_op(kk_function_t _c_1, kk_effects_dash_and_dash_types__exp _c_2, kk_tmcmc__trace _this, kk_std_core_types__optional a0, kk_std_core__list _c_3, kk_context_t* _ctx) { /* forall<a,e> (() -> e a, effects-and-types/exp, trace<a,e>, a : optional<a>, effects-and-types/trace_values) -> trace<a,e> */ 
  if (kk_yielding(kk_context())) {
    kk_tmcmc__trace_dropn(_this, ((int32_t)3), _ctx);
    kk_std_core_types__optional_drop(a0, _ctx);
    kk_box_t _x2392 = kk_std_core_hnd_yield_extend(kk_tmcmc__new_mlift1704_op_fun2393(_c_1, _c_3, _c_2, _ctx), _ctx); /*2*/
    return kk_tmcmc__trace_unbox(_x2392, _ctx);
  }
  kk_box_t _x2395;
  if (kk_std_core_types__is_Optional(a0)) {
    kk_box_t _a_249 = a0._cons.Optional.value;
    kk_tmcmc__trace_dropn(_this, ((int32_t)3), _ctx);
    _x2395 = _a_249; /*264*/
  }
  else {
    struct kk_tmcmc_Trace* _con2396 = kk_tmcmc__as_Trace(_this);
    kk_function_t _pat00 = _con2396->m;
    kk_effects_dash_and_dash_types__exp _pat10 = _con2396->p;
    kk_std_core__list _pat3 = _con2396->l;
    kk_box_t _x = _con2396->a;
    if (kk_tmcmc__trace_is_unique(_this)) {
      kk_std_core__list_drop(_pat3, _ctx);
      kk_function_drop(_pat00, _ctx);
      kk_tmcmc__trace_free(_this);
    }
    else {
      kk_box_dup(_x);
      kk_tmcmc__trace_decref(_this, _ctx);
    }
    _x2395 = _x; /*264*/
  }
  return kk_tmcmc__mlift1703_op(_c_1, _c_2, _c_3, _x2395, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_tmcmc__mlift1705_op_fun2398__t {
  struct kk_function_s _base;
  kk_function_t _c_1;
  kk_tmcmc__trace _this;
  kk_std_core_types__optional a0;
  kk_effects_dash_and_dash_types__exp _c_2;
};
static kk_box_t kk_tmcmc__mlift1705_op_fun2398(kk_function_t _fself, kk_box_t _b_1907, kk_context_t* _ctx);
static kk_function_t kk_tmcmc__new_mlift1705_op_fun2398(kk_function_t _c_1, kk_tmcmc__trace _this, kk_std_core_types__optional a0, kk_effects_dash_and_dash_types__exp _c_2, kk_context_t* _ctx) {
  struct kk_tmcmc__mlift1705_op_fun2398__t* _self = kk_function_alloc_as(struct kk_tmcmc__mlift1705_op_fun2398__t, 5, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc__mlift1705_op_fun2398, kk_context());
  _self->_c_1 = _c_1;
  _self->_this = _this;
  _self->a0 = a0;
  _self->_c_2 = _c_2;
  return &_self->_base;
}

static kk_box_t kk_tmcmc__mlift1705_op_fun2398(kk_function_t _fself, kk_box_t _b_1907, kk_context_t* _ctx) {
  struct kk_tmcmc__mlift1705_op_fun2398__t* _self = kk_function_as(struct kk_tmcmc__mlift1705_op_fun2398__t*, _fself);
  kk_function_t _c_1 = _self->_c_1; /* () -> 265 264 */
  kk_tmcmc__trace _this = _self->_this; /* tmcmc/trace<264,265> */
  kk_std_core_types__optional a0 = _self->a0; /* optional<264> */
  kk_effects_dash_and_dash_types__exp _c_2 = _self->_c_2; /* effects-and-types/exp */
  kk_drop_match(_self, {kk_function_dup(_c_1);kk_tmcmc__trace_dup(_this);kk_std_core_types__optional_dup(a0);kk_effects_dash_and_dash_types__exp_dup(_c_2);}, {}, _ctx)
  kk_tmcmc__trace _x2399;
  kk_std_core__list _x2400 = kk_std_core__list_unbox(_b_1907, _ctx); /*effects-and-types/trace_values*/
  _x2399 = kk_tmcmc__mlift1704_op(_c_1, _c_2, _this, a0, _x2400, _ctx); /*tmcmc/trace<264,265>*/
  return kk_tmcmc__trace_box(_x2399, _ctx);
}

kk_tmcmc__trace kk_tmcmc__mlift1705_op(kk_function_t _c_1, kk_tmcmc__trace _this, kk_std_core_types__optional a0, kk_std_core_types__optional l0, kk_effects_dash_and_dash_types__exp _c_2, kk_context_t* _ctx) { /* forall<a,e> (() -> e a, trace<a,e>, a : optional<a>, l : optional<effects-and-types/trace_values>, effects-and-types/exp) -> trace<a,e> */ 
  if (kk_yielding(kk_context())) {
    kk_std_core_types__optional_drop(l0, _ctx);
    kk_box_t _x2397 = kk_std_core_hnd_yield_extend(kk_tmcmc__new_mlift1705_op_fun2398(_c_1, _this, a0, _c_2, _ctx), _ctx); /*2*/
    return kk_tmcmc__trace_unbox(_x2397, _ctx);
  }
  kk_tmcmc__trace _x2401 = kk_tmcmc__trace_dup(_this); /*tmcmc/trace<264,265>*/
  kk_std_core__list _x2402;
  if (kk_std_core_types__is_Optional(l0)) {
    kk_box_t _box_x1908 = l0._cons.Optional.value;
    kk_std_core__list _l_241 = kk_std_core__list_unbox(_box_x1908, NULL);
    kk_std_core__list_dup(_l_241);
    kk_std_core_types__optional_drop(l0, _ctx);
    kk_tmcmc__trace_dropn(_this, ((int32_t)3), _ctx);
    _x2402 = _l_241; /*effects-and-types/trace_values*/
    goto _match2403;
  }
  struct kk_tmcmc_Trace* _con2405 = kk_tmcmc__as_Trace(_this);
  kk_function_t _pat00 = _con2405->m;
  kk_effects_dash_and_dash_types__exp _pat10 = _con2405->p;
  kk_std_core__list _x = _con2405->l;
  kk_box_t _pat30 = _con2405->a;
  if (kk_tmcmc__trace_is_unique(_this)) {
    kk_box_drop(_pat30, _ctx);
    kk_function_drop(_pat00, _ctx);
    kk_tmcmc__trace_free(_this);
  }
  else {
    kk_std_core__list_dup(_x);
    kk_tmcmc__trace_decref(_this, _ctx);
  }
  _x2402 = _x; /*effects-and-types/trace_values*/
  _match2403: ;
  return kk_tmcmc__mlift1704_op(_c_1, _c_2, _x2401, a0, _x2402, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_tmcmc__mlift1706_op_fun2407__t {
  struct kk_function_s _base;
  kk_function_t _c_1;
  kk_tmcmc__trace _this;
  kk_std_core_types__optional a0;
  kk_std_core_types__optional l0;
};
static kk_box_t kk_tmcmc__mlift1706_op_fun2407(kk_function_t _fself, kk_box_t _b_1912, kk_context_t* _ctx);
static kk_function_t kk_tmcmc__new_mlift1706_op_fun2407(kk_function_t _c_1, kk_tmcmc__trace _this, kk_std_core_types__optional a0, kk_std_core_types__optional l0, kk_context_t* _ctx) {
  struct kk_tmcmc__mlift1706_op_fun2407__t* _self = kk_function_alloc_as(struct kk_tmcmc__mlift1706_op_fun2407__t, 7, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc__mlift1706_op_fun2407, kk_context());
  _self->_c_1 = _c_1;
  _self->_this = _this;
  _self->a0 = a0;
  _self->l0 = l0;
  return &_self->_base;
}

static kk_box_t kk_tmcmc__mlift1706_op_fun2407(kk_function_t _fself, kk_box_t _b_1912, kk_context_t* _ctx) {
  struct kk_tmcmc__mlift1706_op_fun2407__t* _self = kk_function_as(struct kk_tmcmc__mlift1706_op_fun2407__t*, _fself);
  kk_function_t _c_1 = _self->_c_1; /* () -> 265 264 */
  kk_tmcmc__trace _this = _self->_this; /* tmcmc/trace<264,265> */
  kk_std_core_types__optional a0 = _self->a0; /* optional<264> */
  kk_std_core_types__optional l0 = _self->l0; /* optional<effects-and-types/trace_values> */
  kk_drop_match(_self, {kk_function_dup(_c_1);kk_tmcmc__trace_dup(_this);kk_std_core_types__optional_dup(a0);kk_std_core_types__optional_dup(l0);}, {}, _ctx)
  kk_tmcmc__trace _x2408;
  kk_effects_dash_and_dash_types__exp _x2409 = kk_effects_dash_and_dash_types__exp_unbox(_b_1912, _ctx); /*effects-and-types/exp*/
  _x2408 = kk_tmcmc__mlift1705_op(_c_1, _this, a0, l0, _x2409, _ctx); /*tmcmc/trace<264,265>*/
  return kk_tmcmc__trace_box(_x2408, _ctx);
}

kk_tmcmc__trace kk_tmcmc__mlift1706_op(kk_tmcmc__trace _this, kk_std_core_types__optional a0, kk_std_core_types__optional l0, kk_std_core_types__optional p0, kk_function_t _c_1, kk_context_t* _ctx) { /* forall<a,e> (trace<a,e>, a : optional<a>, l : optional<effects-and-types/trace_values>, p : optional<effects-and-types/exp>, () -> e a) -> trace<a,e> */ 
  if (kk_yielding(kk_context())) {
    kk_std_core_types__optional_drop(p0, _ctx);
    kk_box_t _x2406 = kk_std_core_hnd_yield_extend(kk_tmcmc__new_mlift1706_op_fun2407(_c_1, _this, a0, l0, _ctx), _ctx); /*2*/
    return kk_tmcmc__trace_unbox(_x2406, _ctx);
  }
  kk_tmcmc__trace _x2410 = kk_tmcmc__trace_dup(_this); /*tmcmc/trace<264,265>*/
  kk_effects_dash_and_dash_types__exp _x2411;
  if (kk_std_core_types__is_Optional(p0)) {
    kk_box_t _box_x1913 = p0._cons.Optional.value;
    kk_effects_dash_and_dash_types__exp _p_233 = kk_effects_dash_and_dash_types__exp_unbox(_box_x1913, NULL);
    kk_std_core_types__optional_drop(p0, _ctx);
    kk_tmcmc__trace_dropn(_this, ((int32_t)3), _ctx);
    _x2411 = _p_233; /*effects-and-types/exp*/
    goto _match2412;
  }
  struct kk_tmcmc_Trace* _con2414 = kk_tmcmc__as_Trace(_this);
  kk_function_t _pat00 = _con2414->m;
  kk_effects_dash_and_dash_types__exp _x = _con2414->p;
  kk_std_core__list _pat20 = _con2414->l;
  kk_box_t _pat30 = _con2414->a;
  if (kk_tmcmc__trace_is_unique(_this)) {
    kk_box_drop(_pat30, _ctx);
    kk_std_core__list_drop(_pat20, _ctx);
    kk_function_drop(_pat00, _ctx);
    kk_tmcmc__trace_free(_this);
  }
  else {
    kk_tmcmc__trace_decref(_this, _ctx);
  }
  _x2411 = _x; /*effects-and-types/exp*/
  _match2412: ;
  return kk_tmcmc__mlift1705_op(_c_1, _x2410, a0, l0, _x2411, _ctx);
}


// lift anonymous function
struct kk_tmcmc__copy_fun2416__t {
  struct kk_function_s _base;
  kk_tmcmc__trace _this;
  kk_std_core_types__optional a0;
  kk_std_core_types__optional l0;
  kk_std_core_types__optional p0;
};
static kk_box_t kk_tmcmc__copy_fun2416(kk_function_t _fself, kk_box_t _b_1917, kk_context_t* _ctx);
static kk_function_t kk_tmcmc__new_copy_fun2416(kk_tmcmc__trace _this, kk_std_core_types__optional a0, kk_std_core_types__optional l0, kk_std_core_types__optional p0, kk_context_t* _ctx) {
  struct kk_tmcmc__copy_fun2416__t* _self = kk_function_alloc_as(struct kk_tmcmc__copy_fun2416__t, 8, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc__copy_fun2416, kk_context());
  _self->_this = _this;
  _self->a0 = a0;
  _self->l0 = l0;
  _self->p0 = p0;
  return &_self->_base;
}

static kk_box_t kk_tmcmc__copy_fun2416(kk_function_t _fself, kk_box_t _b_1917, kk_context_t* _ctx) {
  struct kk_tmcmc__copy_fun2416__t* _self = kk_function_as(struct kk_tmcmc__copy_fun2416__t*, _fself);
  kk_tmcmc__trace _this = _self->_this; /* tmcmc/trace<264,265> */
  kk_std_core_types__optional a0 = _self->a0; /* optional<264> */
  kk_std_core_types__optional l0 = _self->l0; /* optional<effects-and-types/trace_values> */
  kk_std_core_types__optional p0 = _self->p0; /* optional<effects-and-types/exp> */
  kk_drop_match(_self, {kk_tmcmc__trace_dup(_this);kk_std_core_types__optional_dup(a0);kk_std_core_types__optional_dup(l0);kk_std_core_types__optional_dup(p0);}, {}, _ctx)
  kk_tmcmc__trace _x2417;
  kk_function_t _x2418 = kk_function_unbox(_b_1917); /*() -> 265 1918*/
  _x2417 = kk_tmcmc__mlift1706_op(_this, a0, l0, p0, _x2418, _ctx); /*tmcmc/trace<264,265>*/
  return kk_tmcmc__trace_box(_x2417, _ctx);
}


// lift anonymous function
struct kk_tmcmc__copy_fun2420__t {
  struct kk_function_s _base;
  kk_tmcmc__trace _this;
  kk_std_core_types__optional a0;
  kk_std_core_types__optional l0;
  kk_std_core_types__optional m0;
};
static kk_box_t kk_tmcmc__copy_fun2420(kk_function_t _fself, kk_box_t _b_1923, kk_context_t* _ctx);
static kk_function_t kk_tmcmc__new_copy_fun2420(kk_tmcmc__trace _this, kk_std_core_types__optional a0, kk_std_core_types__optional l0, kk_std_core_types__optional m0, kk_context_t* _ctx) {
  struct kk_tmcmc__copy_fun2420__t* _self = kk_function_alloc_as(struct kk_tmcmc__copy_fun2420__t, 8, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc__copy_fun2420, kk_context());
  _self->_this = _this;
  _self->a0 = a0;
  _self->l0 = l0;
  _self->m0 = m0;
  return &_self->_base;
}

static kk_box_t kk_tmcmc__copy_fun2420(kk_function_t _fself, kk_box_t _b_1923, kk_context_t* _ctx) {
  struct kk_tmcmc__copy_fun2420__t* _self = kk_function_as(struct kk_tmcmc__copy_fun2420__t*, _fself);
  kk_tmcmc__trace _this = _self->_this; /* tmcmc/trace<264,265> */
  kk_std_core_types__optional a0 = _self->a0; /* optional<264> */
  kk_std_core_types__optional l0 = _self->l0; /* optional<effects-and-types/trace_values> */
  kk_std_core_types__optional m0 = _self->m0; /* optional<() -> 265 264> */
  kk_drop_match(_self, {kk_tmcmc__trace_dup(_this);kk_std_core_types__optional_dup(a0);kk_std_core_types__optional_dup(l0);kk_std_core_types__optional_dup(m0);}, {}, _ctx)
  kk_tmcmc__trace _x2421;
  kk_function_t _x2422;
  if (kk_std_core_types__is_Optional(m0)) {
    kk_box_t _fun_unbox_x1920 = m0._cons.Optional.value;
    _x2422 = kk_function_unbox(_fun_unbox_x1920); /*() -> 265 1921*/
  }
  else {
    struct kk_tmcmc_Trace* _con2423 = kk_tmcmc__as_Trace(_this);
    kk_function_t _x = _con2423->m;
    kk_effects_dash_and_dash_types__exp _pat01 = _con2423->p;
    kk_function_dup(_x);
    _x2422 = _x; /*() -> 265 1921*/
  }
  kk_effects_dash_and_dash_types__exp _x2424 = kk_effects_dash_and_dash_types__exp_unbox(_b_1923, _ctx); /*effects-and-types/exp*/
  _x2421 = kk_tmcmc__mlift1705_op(_x2422, _this, a0, l0, _x2424, _ctx); /*tmcmc/trace<264,265>*/
  return kk_tmcmc__trace_box(_x2421, _ctx);
}


// lift anonymous function
struct kk_tmcmc__copy_fun2426__t {
  struct kk_function_s _base;
  kk_tmcmc__trace _this;
  kk_std_core_types__optional a0;
  kk_std_core_types__optional m0;
  kk_std_core_types__optional p0;
};
static kk_box_t kk_tmcmc__copy_fun2426(kk_function_t _fself, kk_box_t _b_1929, kk_context_t* _ctx);
static kk_function_t kk_tmcmc__new_copy_fun2426(kk_tmcmc__trace _this, kk_std_core_types__optional a0, kk_std_core_types__optional m0, kk_std_core_types__optional p0, kk_context_t* _ctx) {
  struct kk_tmcmc__copy_fun2426__t* _self = kk_function_alloc_as(struct kk_tmcmc__copy_fun2426__t, 8, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc__copy_fun2426, kk_context());
  _self->_this = _this;
  _self->a0 = a0;
  _self->m0 = m0;
  _self->p0 = p0;
  return &_self->_base;
}

static kk_box_t kk_tmcmc__copy_fun2426(kk_function_t _fself, kk_box_t _b_1929, kk_context_t* _ctx) {
  struct kk_tmcmc__copy_fun2426__t* _self = kk_function_as(struct kk_tmcmc__copy_fun2426__t*, _fself);
  kk_tmcmc__trace _this = _self->_this; /* tmcmc/trace<264,265> */
  kk_std_core_types__optional a0 = _self->a0; /* optional<264> */
  kk_std_core_types__optional m0 = _self->m0; /* optional<() -> 265 264> */
  kk_std_core_types__optional p0 = _self->p0; /* optional<effects-and-types/exp> */
  kk_drop_match(_self, {kk_tmcmc__trace_dup(_this);kk_std_core_types__optional_dup(a0);kk_std_core_types__optional_dup(m0);kk_std_core_types__optional_dup(p0);}, {}, _ctx)
  kk_tmcmc__trace _x2427;
  kk_function_t _x2428;
  if (kk_std_core_types__is_Optional(m0)) {
    kk_box_t _fun_unbox_x1925 = m0._cons.Optional.value;
    _x2428 = kk_function_unbox(_fun_unbox_x1925); /*() -> 265 1926*/
  }
  else {
    struct kk_tmcmc_Trace* _con2429 = kk_tmcmc__as_Trace(_this);
    kk_function_t _x0 = _con2429->m;
    kk_effects_dash_and_dash_types__exp _pat010 = _con2429->p;
    kk_function_dup(_x0);
    _x2428 = _x0; /*() -> 265 1926*/
  }
  kk_effects_dash_and_dash_types__exp _x2430;
  if (kk_std_core_types__is_Optional(p0)) {
    kk_box_t _box_x1927 = p0._cons.Optional.value;
    kk_effects_dash_and_dash_types__exp _p_233 = kk_effects_dash_and_dash_types__exp_unbox(_box_x1927, NULL);
    kk_std_core_types__optional_drop(p0, _ctx);
    _x2430 = _p_233; /*effects-and-types/exp*/
    goto _match2431;
  }
  struct kk_tmcmc_Trace* _con2433 = kk_tmcmc__as_Trace(_this);
  kk_effects_dash_and_dash_types__exp _x00 = _con2433->p;
  _x2430 = _x00; /*effects-and-types/exp*/
  _match2431: ;
  kk_std_core__list _x2434 = kk_std_core__list_unbox(_b_1929, _ctx); /*effects-and-types/trace_values*/
  _x2427 = kk_tmcmc__mlift1704_op(_x2428, _x2430, _this, a0, _x2434, _ctx); /*tmcmc/trace<264,265>*/
  return kk_tmcmc__trace_box(_x2427, _ctx);
}


// lift anonymous function
struct kk_tmcmc__copy_fun2436__t {
  struct kk_function_s _base;
  kk_tmcmc__trace _this;
  kk_std_core_types__optional l0;
  kk_std_core_types__optional m0;
  kk_std_core_types__optional p0;
};
static kk_box_t kk_tmcmc__copy_fun2436(kk_function_t _fself, kk_box_t _b_1936, kk_context_t* _ctx);
static kk_function_t kk_tmcmc__new_copy_fun2436(kk_tmcmc__trace _this, kk_std_core_types__optional l0, kk_std_core_types__optional m0, kk_std_core_types__optional p0, kk_context_t* _ctx) {
  struct kk_tmcmc__copy_fun2436__t* _self = kk_function_alloc_as(struct kk_tmcmc__copy_fun2436__t, 8, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc__copy_fun2436, kk_context());
  _self->_this = _this;
  _self->l0 = l0;
  _self->m0 = m0;
  _self->p0 = p0;
  return &_self->_base;
}

static kk_box_t kk_tmcmc__copy_fun2436(kk_function_t _fself, kk_box_t _b_1936, kk_context_t* _ctx) {
  struct kk_tmcmc__copy_fun2436__t* _self = kk_function_as(struct kk_tmcmc__copy_fun2436__t*, _fself);
  kk_tmcmc__trace _this = _self->_this; /* tmcmc/trace<264,265> */
  kk_std_core_types__optional l0 = _self->l0; /* optional<effects-and-types/trace_values> */
  kk_std_core_types__optional m0 = _self->m0; /* optional<() -> 265 264> */
  kk_std_core_types__optional p0 = _self->p0; /* optional<effects-and-types/exp> */
  kk_drop_match(_self, {kk_tmcmc__trace_dup(_this);kk_std_core_types__optional_dup(l0);kk_std_core_types__optional_dup(m0);kk_std_core_types__optional_dup(p0);}, {}, _ctx)
  kk_tmcmc__trace _x2437;
  kk_function_t _x2438;
  if (kk_std_core_types__is_Optional(m0)) {
    kk_box_t _fun_unbox_x1931 = m0._cons.Optional.value;
    _x2438 = kk_function_unbox(_fun_unbox_x1931); /*() -> 265 1932*/
  }
  else {
    struct kk_tmcmc_Trace* _con2439 = kk_tmcmc__as_Trace(_this);
    kk_function_t _x1 = _con2439->m;
    kk_effects_dash_and_dash_types__exp _pat011 = _con2439->p;
    kk_function_dup(_x1);
    _x2438 = _x1; /*() -> 265 1932*/
  }
  kk_effects_dash_and_dash_types__exp _x2440;
  if (kk_std_core_types__is_Optional(p0)) {
    kk_box_t _box_x1933 = p0._cons.Optional.value;
    kk_effects_dash_and_dash_types__exp _p_2330 = kk_effects_dash_and_dash_types__exp_unbox(_box_x1933, NULL);
    kk_std_core_types__optional_drop(p0, _ctx);
    _x2440 = _p_2330; /*effects-and-types/exp*/
    goto _match2441;
  }
  struct kk_tmcmc_Trace* _con2443 = kk_tmcmc__as_Trace(_this);
  kk_effects_dash_and_dash_types__exp _x01 = _con2443->p;
  _x2440 = _x01; /*effects-and-types/exp*/
  _match2441: ;
  kk_std_core__list _x2444;
  if (kk_std_core_types__is_Optional(l0)) {
    kk_box_t _box_x1934 = l0._cons.Optional.value;
    kk_std_core__list _l_241 = kk_std_core__list_unbox(_box_x1934, NULL);
    kk_std_core__list_dup(_l_241);
    kk_std_core_types__optional_drop(l0, _ctx);
    kk_tmcmc__trace_dropn(_this, ((int32_t)3), _ctx);
    _x2444 = _l_241; /*effects-and-types/trace_values*/
    goto _match2445;
  }
  struct kk_tmcmc_Trace* _con2447 = kk_tmcmc__as_Trace(_this);
  kk_function_t _pat05 = _con2447->m;
  kk_effects_dash_and_dash_types__exp _pat130 = _con2447->p;
  kk_std_core__list _x10 = _con2447->l;
  kk_box_t _pat32 = _con2447->a;
  if (kk_tmcmc__trace_is_unique(_this)) {
    kk_box_drop(_pat32, _ctx);
    kk_function_drop(_pat05, _ctx);
    kk_tmcmc__trace_free(_this);
  }
  else {
    kk_std_core__list_dup(_x10);
    kk_tmcmc__trace_decref(_this, _ctx);
  }
  _x2444 = _x10; /*effects-and-types/trace_values*/
  _match2445: ;
  _x2437 = kk_tmcmc__mlift1703_op(_x2438, _x2440, _x2444, _b_1936, _ctx); /*tmcmc/trace<264,265>*/
  return kk_tmcmc__trace_box(_x2437, _ctx);
}

kk_tmcmc__trace kk_tmcmc__copy(kk_tmcmc__trace _this, kk_std_core_types__optional m0, kk_std_core_types__optional p0, kk_std_core_types__optional l0, kk_std_core_types__optional a0, kk_context_t* _ctx) { /* forall<a,e> (trace<a,e>, m : optional<() -> e a>, p : optional<effects-and-types/exp>, l : optional<effects-and-types/trace_values>, a : optional<a>) -> trace<a,e> */ 
  if (kk_yielding(kk_context())) {
    kk_std_core_types__optional_drop(m0, _ctx);
    kk_box_t _x2415 = kk_std_core_hnd_yield_extend(kk_tmcmc__new_copy_fun2416(_this, a0, l0, p0, _ctx), _ctx); /*2*/
    return kk_tmcmc__trace_unbox(_x2415, _ctx);
  }
  if (kk_yielding(kk_context())) {
    kk_std_core_types__optional_drop(p0, _ctx);
    kk_box_t _x2419 = kk_std_core_hnd_yield_extend(kk_tmcmc__new_copy_fun2420(_this, a0, l0, m0, _ctx), _ctx); /*2*/
    return kk_tmcmc__trace_unbox(_x2419, _ctx);
  }
  if (kk_yielding(kk_context())) {
    kk_std_core_types__optional_drop(l0, _ctx);
    kk_box_t _x2425 = kk_std_core_hnd_yield_extend(kk_tmcmc__new_copy_fun2426(_this, a0, m0, p0, _ctx), _ctx); /*2*/
    return kk_tmcmc__trace_unbox(_x2425, _ctx);
  }
  if (kk_yielding(kk_context())) {
    kk_std_core_types__optional_drop(a0, _ctx);
    kk_box_t _x2435 = kk_std_core_hnd_yield_extend(kk_tmcmc__new_copy_fun2436(_this, l0, m0, p0, _ctx), _ctx); /*2*/
    return kk_tmcmc__trace_unbox(_x2435, _ctx);
  }
  kk_function_t _x2448;
  if (kk_std_core_types__is_Optional(m0)) {
    kk_box_t _fun_unbox_x1938 = m0._cons.Optional.value;
    _x2448 = kk_function_unbox(_fun_unbox_x1938); /*() -> 265 1939*/
  }
  else {
    struct kk_tmcmc_Trace* _con2449 = kk_tmcmc__as_Trace(_this);
    kk_function_t _x2 = _con2449->m;
    kk_effects_dash_and_dash_types__exp _pat012 = _con2449->p;
    kk_function_dup(_x2);
    _x2448 = _x2; /*() -> 265 1939*/
  }
  kk_effects_dash_and_dash_types__exp _x2450;
  if (kk_std_core_types__is_Optional(p0)) {
    kk_box_t _box_x1940 = p0._cons.Optional.value;
    kk_effects_dash_and_dash_types__exp _p_2331 = kk_effects_dash_and_dash_types__exp_unbox(_box_x1940, NULL);
    kk_std_core_types__optional_drop(p0, _ctx);
    _x2450 = _p_2331; /*effects-and-types/exp*/
    goto _match2451;
  }
  struct kk_tmcmc_Trace* _con2453 = kk_tmcmc__as_Trace(_this);
  kk_effects_dash_and_dash_types__exp _x02 = _con2453->p;
  _x2450 = _x02; /*effects-and-types/exp*/
  _match2451: ;
  kk_std_core__list _x2454;
  if (kk_std_core_types__is_Optional(l0)) {
    kk_box_t _box_x1941 = l0._cons.Optional.value;
    kk_std_core__list _l_2410 = kk_std_core__list_unbox(_box_x1941, NULL);
    kk_std_core__list_dup(_l_2410);
    kk_std_core_types__optional_drop(l0, _ctx);
    _x2454 = _l_2410; /*effects-and-types/trace_values*/
    goto _match2455;
  }
  struct kk_tmcmc_Trace* _con2457 = kk_tmcmc__as_Trace(_this);
  kk_effects_dash_and_dash_types__exp _pat131 = _con2457->p;
  kk_std_core__list _x11 = _con2457->l;
  kk_std_core__list_dup(_x11);
  _x2454 = _x11; /*effects-and-types/trace_values*/
  _match2455: ;
  kk_box_t _x2458;
  if (kk_std_core_types__is_Optional(a0)) {
    kk_box_t _a_249 = a0._cons.Optional.value;
    kk_tmcmc__trace_dropn(_this, ((int32_t)3), _ctx);
    _x2458 = _a_249; /*264*/
  }
  else {
    struct kk_tmcmc_Trace* _con2459 = kk_tmcmc__as_Trace(_this);
    kk_function_t _pat07 = _con2459->m;
    kk_effects_dash_and_dash_types__exp _pat140 = _con2459->p;
    kk_std_core__list _pat330 = _con2459->l;
    kk_box_t _x20 = _con2459->a;
    if (kk_tmcmc__trace_is_unique(_this)) {
      kk_std_core__list_drop(_pat330, _ctx);
      kk_function_drop(_pat07, _ctx);
      kk_tmcmc__trace_free(_this);
    }
    else {
      kk_box_dup(_x20);
      kk_tmcmc__trace_decref(_this, _ctx);
    }
    _x2458 = _x20; /*264*/
  }
  return kk_tmcmc__new_Trace(kk_reuse_null, _x2448, _x2450, _x2454, _x2458, _ctx);
}
 
// monadic lift

kk_tmcmc__trace__rmsmc kk_tmcmc__mlift1707_op(kk_function_t _c_5, kk_effects_dash_and_dash_types__exp _c_6, kk_std_core__list _c_7, kk_context_t* _ctx) { /* forall<a,e> (() -> ((int) -> e a), effects-and-types/exp, effects-and-types/trace_values) -> trace_rmsmc<a,e> */ 
  return kk_tmcmc__new_RTrace(_c_5, _c_6, _c_7, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_tmcmc__mlift1708_op_fun2461__t {
  struct kk_function_s _base;
  kk_function_t _c_5;
  kk_effects_dash_and_dash_types__exp _c_6;
};
static kk_box_t kk_tmcmc__mlift1708_op_fun2461(kk_function_t _fself, kk_box_t _b_1951, kk_context_t* _ctx);
static kk_function_t kk_tmcmc__new_mlift1708_op_fun2461(kk_function_t _c_5, kk_effects_dash_and_dash_types__exp _c_6, kk_context_t* _ctx) {
  struct kk_tmcmc__mlift1708_op_fun2461__t* _self = kk_function_alloc_as(struct kk_tmcmc__mlift1708_op_fun2461__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc__mlift1708_op_fun2461, kk_context());
  _self->_c_5 = _c_5;
  _self->_c_6 = _c_6;
  return &_self->_base;
}

static kk_box_t kk_tmcmc__mlift1708_op_fun2461(kk_function_t _fself, kk_box_t _b_1951, kk_context_t* _ctx) {
  struct kk_tmcmc__mlift1708_op_fun2461__t* _self = kk_function_as(struct kk_tmcmc__mlift1708_op_fun2461__t*, _fself);
  kk_function_t _c_5 = _self->_c_5; /* () -> ((int) -> 492 491) */
  kk_effects_dash_and_dash_types__exp _c_6 = _self->_c_6; /* effects-and-types/exp */
  kk_drop_match(_self, {kk_function_dup(_c_5);kk_effects_dash_and_dash_types__exp_dup(_c_6);}, {}, _ctx)
  kk_tmcmc__trace__rmsmc _x2462;
  kk_std_core__list _x2463 = kk_std_core__list_unbox(_b_1951, _ctx); /*effects-and-types/trace_values*/
  _x2462 = kk_tmcmc__mlift1707_op(_c_5, _c_6, _x2463, _ctx); /*tmcmc/trace_rmsmc<491,492>*/
  return kk_tmcmc__trace__rmsmc_box(_x2462, _ctx);
}

kk_tmcmc__trace__rmsmc kk_tmcmc__mlift1708_op(kk_function_t _c_5, kk_tmcmc__trace__rmsmc _this, kk_std_core_types__optional l0, kk_effects_dash_and_dash_types__exp _c_6, kk_context_t* _ctx) { /* forall<a,e> (() -> ((int) -> e a), trace_rmsmc<a,e>, l : optional<effects-and-types/trace_values>, effects-and-types/exp) -> trace_rmsmc<a,e> */ 
  if (kk_yielding(kk_context())) {
    kk_tmcmc__trace__rmsmc_drop(_this, _ctx);
    kk_std_core_types__optional_drop(l0, _ctx);
    kk_box_t _x2460 = kk_std_core_hnd_yield_extend(kk_tmcmc__new_mlift1708_op_fun2461(_c_5, _c_6, _ctx), _ctx); /*2*/
    return kk_tmcmc__trace__rmsmc_unbox(_x2460, _ctx);
  }
  kk_std_core__list _x2464;
  if (kk_std_core_types__is_Optional(l0)) {
    kk_box_t _box_x1952 = l0._cons.Optional.value;
    kk_std_core__list _l_476 = kk_std_core__list_unbox(_box_x1952, NULL);
    kk_std_core__list_dup(_l_476);
    kk_std_core_types__optional_drop(l0, _ctx);
    kk_tmcmc__trace__rmsmc_drop(_this, _ctx);
    _x2464 = _l_476; /*effects-and-types/trace_values*/
    goto _match2465;
  }
  kk_effects_dash_and_dash_types__exp _pat10 = _this.p;
  kk_std_core__list _x = _this.l;
  kk_std_core__list_dup(_x);
  kk_tmcmc__trace__rmsmc_drop(_this, _ctx);
  _x2464 = _x; /*effects-and-types/trace_values*/
  _match2465: ;
  return kk_tmcmc__mlift1707_op(_c_5, _c_6, _x2464, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_tmcmc__mlift1709_op_fun2468__t {
  struct kk_function_s _base;
  kk_function_t _c_5;
  kk_std_core_types__optional l0;
  kk_tmcmc__trace__rmsmc _this;
};
static kk_box_t kk_tmcmc__mlift1709_op_fun2468(kk_function_t _fself, kk_box_t _b_1956, kk_context_t* _ctx);
static kk_function_t kk_tmcmc__new_mlift1709_op_fun2468(kk_function_t _c_5, kk_std_core_types__optional l0, kk_tmcmc__trace__rmsmc _this, kk_context_t* _ctx) {
  struct kk_tmcmc__mlift1709_op_fun2468__t* _self = kk_function_alloc_as(struct kk_tmcmc__mlift1709_op_fun2468__t, 6, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc__mlift1709_op_fun2468, kk_context());
  _self->_c_5 = _c_5;
  _self->l0 = l0;
  _self->_this = _this;
  return &_self->_base;
}

static kk_box_t kk_tmcmc__mlift1709_op_fun2468(kk_function_t _fself, kk_box_t _b_1956, kk_context_t* _ctx) {
  struct kk_tmcmc__mlift1709_op_fun2468__t* _self = kk_function_as(struct kk_tmcmc__mlift1709_op_fun2468__t*, _fself);
  kk_function_t _c_5 = _self->_c_5; /* () -> ((int) -> 492 491) */
  kk_std_core_types__optional l0 = _self->l0; /* optional<effects-and-types/trace_values> */
  kk_tmcmc__trace__rmsmc _this = _self->_this; /* tmcmc/trace_rmsmc<491,492> */
  kk_drop_match(_self, {kk_function_dup(_c_5);kk_std_core_types__optional_dup(l0);kk_tmcmc__trace__rmsmc_dup(_this);}, {}, _ctx)
  kk_tmcmc__trace__rmsmc _x2469;
  kk_effects_dash_and_dash_types__exp _x2470 = kk_effects_dash_and_dash_types__exp_unbox(_b_1956, _ctx); /*effects-and-types/exp*/
  _x2469 = kk_tmcmc__mlift1708_op(_c_5, _this, l0, _x2470, _ctx); /*tmcmc/trace_rmsmc<491,492>*/
  return kk_tmcmc__trace__rmsmc_box(_x2469, _ctx);
}

kk_tmcmc__trace__rmsmc kk_tmcmc__mlift1709_op(kk_tmcmc__trace__rmsmc _this, kk_std_core_types__optional l0, kk_std_core_types__optional p0, kk_function_t _c_5, kk_context_t* _ctx) { /* forall<a,e> (trace_rmsmc<a,e>, l : optional<effects-and-types/trace_values>, p : optional<effects-and-types/exp>, () -> ((int) -> e a)) -> trace_rmsmc<a,e> */ 
  if (kk_yielding(kk_context())) {
    kk_std_core_types__optional_drop(p0, _ctx);
    kk_box_t _x2467 = kk_std_core_hnd_yield_extend(kk_tmcmc__new_mlift1709_op_fun2468(_c_5, l0, _this, _ctx), _ctx); /*2*/
    return kk_tmcmc__trace__rmsmc_unbox(_x2467, _ctx);
  }
  kk_tmcmc__trace__rmsmc _x2471 = kk_tmcmc__trace__rmsmc_dup(_this); /*tmcmc/trace_rmsmc<491,492>*/
  kk_effects_dash_and_dash_types__exp _x2472;
  if (kk_std_core_types__is_Optional(p0)) {
    kk_box_t _box_x1957 = p0._cons.Optional.value;
    kk_effects_dash_and_dash_types__exp _p_442 = kk_effects_dash_and_dash_types__exp_unbox(_box_x1957, NULL);
    kk_std_core_types__optional_drop(p0, _ctx);
    kk_tmcmc__trace__rmsmc_drop(_this, _ctx);
    _x2472 = _p_442; /*effects-and-types/exp*/
    goto _match2473;
  }
  kk_effects_dash_and_dash_types__exp _x = _this.p;
  kk_tmcmc__trace__rmsmc_drop(_this, _ctx);
  _x2472 = _x; /*effects-and-types/exp*/
  _match2473: ;
  return kk_tmcmc__mlift1708_op(_c_5, _x2471, l0, _x2472, _ctx);
}


// lift anonymous function
struct kk_tmcmc__copy_fun2476__t_1 {
  struct kk_function_s _base;
  kk_std_core_types__optional l0;
  kk_std_core_types__optional p0;
  kk_tmcmc__trace__rmsmc _this;
};
static kk_box_t kk_tmcmc__copy_fun2476_1(kk_function_t _fself, kk_box_t _b_1961, kk_context_t* _ctx);
static kk_function_t kk_tmcmc__new_copy_fun2476_1(kk_std_core_types__optional l0, kk_std_core_types__optional p0, kk_tmcmc__trace__rmsmc _this, kk_context_t* _ctx) {
  struct kk_tmcmc__copy_fun2476__t_1* _self = kk_function_alloc_as(struct kk_tmcmc__copy_fun2476__t_1, 7, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc__copy_fun2476_1, kk_context());
  _self->l0 = l0;
  _self->p0 = p0;
  _self->_this = _this;
  return &_self->_base;
}



// lift anonymous function
struct kk_tmcmc__copy_fun2478__t_1 {
  struct kk_function_s _base;
  kk_box_t _b_1961;
};
static kk_function_t kk_tmcmc__copy_fun2478_1(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_tmcmc__new_copy_fun2478_1(kk_box_t _b_1961, kk_context_t* _ctx) {
  struct kk_tmcmc__copy_fun2478__t_1* _self = kk_function_alloc_as(struct kk_tmcmc__copy_fun2478__t_1, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc__copy_fun2478_1, kk_context());
  _self->_b_1961 = _b_1961;
  return &_self->_base;
}



// lift anonymous function
struct kk_tmcmc__copy_fun2481__t_1 {
  struct kk_function_s _base;
  kk_function_t _bv_1965;
};
static kk_box_t kk_tmcmc__copy_fun2481_1(kk_function_t _fself, kk_integer_t _b_1966, kk_context_t* _ctx);
static kk_function_t kk_tmcmc__new_copy_fun2481_1(kk_function_t _bv_1965, kk_context_t* _ctx) {
  struct kk_tmcmc__copy_fun2481__t_1* _self = kk_function_alloc_as(struct kk_tmcmc__copy_fun2481__t_1, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc__copy_fun2481_1, kk_context());
  _self->_bv_1965 = _bv_1965;
  return &_self->_base;
}

static kk_box_t kk_tmcmc__copy_fun2481_1(kk_function_t _fself, kk_integer_t _b_1966, kk_context_t* _ctx) {
  struct kk_tmcmc__copy_fun2481__t_1* _self = kk_function_as(struct kk_tmcmc__copy_fun2481__t_1*, _fself);
  kk_function_t _bv_1965 = _self->_bv_1965; /* (1963) -> 492 1964 */
  kk_drop_match(_self, {kk_function_dup(_bv_1965);}, {}, _ctx)
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _bv_1965, (_bv_1965, kk_integer_box(_b_1966), _ctx));
}
static kk_function_t kk_tmcmc__copy_fun2478_1(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_tmcmc__copy_fun2478__t_1* _self = kk_function_as(struct kk_tmcmc__copy_fun2478__t_1*, _fself);
  kk_box_t _b_1961 = _self->_b_1961; /* 1 */
  kk_drop_match(_self, {kk_box_dup(_b_1961);}, {}, _ctx)
  kk_function_t _bv_1965;
  kk_box_t _x2479;
  kk_function_t _x2480 = kk_function_unbox(_b_1961); /*() -> 1962*/
  _x2479 = kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), _x2480, (_x2480, _ctx)); /*1962*/
  _bv_1965 = kk_function_unbox(_x2479); /*(1963) -> 492 1964*/
  return kk_tmcmc__new_copy_fun2481_1(_bv_1965, _ctx);
}
static kk_box_t kk_tmcmc__copy_fun2476_1(kk_function_t _fself, kk_box_t _b_1961, kk_context_t* _ctx) {
  struct kk_tmcmc__copy_fun2476__t_1* _self = kk_function_as(struct kk_tmcmc__copy_fun2476__t_1*, _fself);
  kk_std_core_types__optional l0 = _self->l0; /* optional<effects-and-types/trace_values> */
  kk_std_core_types__optional p0 = _self->p0; /* optional<effects-and-types/exp> */
  kk_tmcmc__trace__rmsmc _this = _self->_this; /* tmcmc/trace_rmsmc<491,492> */
  kk_drop_match(_self, {kk_std_core_types__optional_dup(l0);kk_std_core_types__optional_dup(p0);kk_tmcmc__trace__rmsmc_dup(_this);}, {}, _ctx)
  kk_tmcmc__trace__rmsmc _x2477 = kk_tmcmc__mlift1709_op(_this, l0, p0, kk_tmcmc__new_copy_fun2478_1(_b_1961, _ctx), _ctx); /*tmcmc/trace_rmsmc<491,492>*/
  return kk_tmcmc__trace__rmsmc_box(_x2477, _ctx);
}


// lift anonymous function
struct kk_tmcmc__copy_fun2483__t_1 {
  struct kk_function_s _base;
  kk_std_core_types__optional l0;
  kk_std_core_types__optional m0;
  kk_tmcmc__trace__rmsmc _this;
};
static kk_box_t kk_tmcmc__copy_fun2483_1(kk_function_t _fself, kk_box_t _b_1979, kk_context_t* _ctx);
static kk_function_t kk_tmcmc__new_copy_fun2483_1(kk_std_core_types__optional l0, kk_std_core_types__optional m0, kk_tmcmc__trace__rmsmc _this, kk_context_t* _ctx) {
  struct kk_tmcmc__copy_fun2483__t_1* _self = kk_function_alloc_as(struct kk_tmcmc__copy_fun2483__t_1, 7, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc__copy_fun2483_1, kk_context());
  _self->l0 = l0;
  _self->m0 = m0;
  _self->_this = _this;
  return &_self->_base;
}



// lift anonymous function
struct kk_tmcmc__copy_fun2486__t_1 {
  struct kk_function_s _base;
  kk_box_t _fun_unbox_x1972;
};
static kk_function_t kk_tmcmc__copy_fun2486_1(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_tmcmc__new_copy_fun2486_1(kk_box_t _fun_unbox_x1972, kk_context_t* _ctx) {
  struct kk_tmcmc__copy_fun2486__t_1* _self = kk_function_alloc_as(struct kk_tmcmc__copy_fun2486__t_1, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc__copy_fun2486_1, kk_context());
  _self->_fun_unbox_x1972 = _fun_unbox_x1972;
  return &_self->_base;
}



// lift anonymous function
struct kk_tmcmc__copy_fun2489__t_1 {
  struct kk_function_s _base;
  kk_function_t _bv_1976;
};
static kk_box_t kk_tmcmc__copy_fun2489_1(kk_function_t _fself, kk_integer_t _b_1977, kk_context_t* _ctx);
static kk_function_t kk_tmcmc__new_copy_fun2489_1(kk_function_t _bv_1976, kk_context_t* _ctx) {
  struct kk_tmcmc__copy_fun2489__t_1* _self = kk_function_alloc_as(struct kk_tmcmc__copy_fun2489__t_1, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc__copy_fun2489_1, kk_context());
  _self->_bv_1976 = _bv_1976;
  return &_self->_base;
}

static kk_box_t kk_tmcmc__copy_fun2489_1(kk_function_t _fself, kk_integer_t _b_1977, kk_context_t* _ctx) {
  struct kk_tmcmc__copy_fun2489__t_1* _self = kk_function_as(struct kk_tmcmc__copy_fun2489__t_1*, _fself);
  kk_function_t _bv_1976 = _self->_bv_1976; /* (1974) -> 492 1975 */
  kk_drop_match(_self, {kk_function_dup(_bv_1976);}, {}, _ctx)
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _bv_1976, (_bv_1976, kk_integer_box(_b_1977), _ctx));
}
static kk_function_t kk_tmcmc__copy_fun2486_1(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_tmcmc__copy_fun2486__t_1* _self = kk_function_as(struct kk_tmcmc__copy_fun2486__t_1*, _fself);
  kk_box_t _fun_unbox_x1972 = _self->_fun_unbox_x1972; /* 33 */
  kk_drop_match(_self, {kk_box_dup(_fun_unbox_x1972);}, {}, _ctx)
  kk_function_t _bv_1976;
  kk_box_t _x2487;
  kk_function_t _x2488 = kk_function_unbox(_fun_unbox_x1972); /*() -> 1973*/
  _x2487 = kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), _x2488, (_x2488, _ctx)); /*1973*/
  _bv_1976 = kk_function_unbox(_x2487); /*(1974) -> 492 1975*/
  return kk_tmcmc__new_copy_fun2489_1(_bv_1976, _ctx);
}
static kk_box_t kk_tmcmc__copy_fun2483_1(kk_function_t _fself, kk_box_t _b_1979, kk_context_t* _ctx) {
  struct kk_tmcmc__copy_fun2483__t_1* _self = kk_function_as(struct kk_tmcmc__copy_fun2483__t_1*, _fself);
  kk_std_core_types__optional l0 = _self->l0; /* optional<effects-and-types/trace_values> */
  kk_std_core_types__optional m0 = _self->m0; /* optional<() -> ((int) -> 492 491)> */
  kk_tmcmc__trace__rmsmc _this = _self->_this; /* tmcmc/trace_rmsmc<491,492> */
  kk_drop_match(_self, {kk_std_core_types__optional_dup(l0);kk_std_core_types__optional_dup(m0);kk_tmcmc__trace__rmsmc_dup(_this);}, {}, _ctx)
  kk_tmcmc__trace__rmsmc _x2484;
  kk_function_t _x2485;
  if (kk_std_core_types__is_Optional(m0)) {
    kk_box_t _fun_unbox_x1972 = m0._cons.Optional.value;
    _x2485 = kk_tmcmc__new_copy_fun2486_1(_fun_unbox_x1972, _ctx); /*() -> ((int) -> 492 1975)*/
  }
  else {
    kk_function_t _x = _this.m;
    kk_effects_dash_and_dash_types__exp _pat01 = _this.p;
    kk_function_dup(_x);
    _x2485 = _x; /*() -> ((int) -> 492 1975)*/
  }
  kk_effects_dash_and_dash_types__exp _x2490 = kk_effects_dash_and_dash_types__exp_unbox(_b_1979, _ctx); /*effects-and-types/exp*/
  _x2484 = kk_tmcmc__mlift1708_op(_x2485, _this, l0, _x2490, _ctx); /*tmcmc/trace_rmsmc<491,492>*/
  return kk_tmcmc__trace__rmsmc_box(_x2484, _ctx);
}


// lift anonymous function
struct kk_tmcmc__copy_fun2492__t_1 {
  struct kk_function_s _base;
  kk_std_core_types__optional m0;
  kk_std_core_types__optional p0;
  kk_tmcmc__trace__rmsmc _this;
};
static kk_box_t kk_tmcmc__copy_fun2492_1(kk_function_t _fself, kk_box_t _b_1993, kk_context_t* _ctx);
static kk_function_t kk_tmcmc__new_copy_fun2492_1(kk_std_core_types__optional m0, kk_std_core_types__optional p0, kk_tmcmc__trace__rmsmc _this, kk_context_t* _ctx) {
  struct kk_tmcmc__copy_fun2492__t_1* _self = kk_function_alloc_as(struct kk_tmcmc__copy_fun2492__t_1, 7, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc__copy_fun2492_1, kk_context());
  _self->m0 = m0;
  _self->p0 = p0;
  _self->_this = _this;
  return &_self->_base;
}



// lift anonymous function
struct kk_tmcmc__copy_fun2495__t_1 {
  struct kk_function_s _base;
  kk_box_t _fun_unbox_x1985;
};
static kk_function_t kk_tmcmc__copy_fun2495_1(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_tmcmc__new_copy_fun2495_1(kk_box_t _fun_unbox_x1985, kk_context_t* _ctx) {
  struct kk_tmcmc__copy_fun2495__t_1* _self = kk_function_alloc_as(struct kk_tmcmc__copy_fun2495__t_1, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc__copy_fun2495_1, kk_context());
  _self->_fun_unbox_x1985 = _fun_unbox_x1985;
  return &_self->_base;
}



// lift anonymous function
struct kk_tmcmc__copy_fun2498__t_1 {
  struct kk_function_s _base;
  kk_function_t _bv_1989;
};
static kk_box_t kk_tmcmc__copy_fun2498_1(kk_function_t _fself, kk_integer_t _b_1990, kk_context_t* _ctx);
static kk_function_t kk_tmcmc__new_copy_fun2498_1(kk_function_t _bv_1989, kk_context_t* _ctx) {
  struct kk_tmcmc__copy_fun2498__t_1* _self = kk_function_alloc_as(struct kk_tmcmc__copy_fun2498__t_1, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc__copy_fun2498_1, kk_context());
  _self->_bv_1989 = _bv_1989;
  return &_self->_base;
}

static kk_box_t kk_tmcmc__copy_fun2498_1(kk_function_t _fself, kk_integer_t _b_1990, kk_context_t* _ctx) {
  struct kk_tmcmc__copy_fun2498__t_1* _self = kk_function_as(struct kk_tmcmc__copy_fun2498__t_1*, _fself);
  kk_function_t _bv_1989 = _self->_bv_1989; /* (1987) -> 492 1988 */
  kk_drop_match(_self, {kk_function_dup(_bv_1989);}, {}, _ctx)
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _bv_1989, (_bv_1989, kk_integer_box(_b_1990), _ctx));
}
static kk_function_t kk_tmcmc__copy_fun2495_1(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_tmcmc__copy_fun2495__t_1* _self = kk_function_as(struct kk_tmcmc__copy_fun2495__t_1*, _fself);
  kk_box_t _fun_unbox_x1985 = _self->_fun_unbox_x1985; /* 33 */
  kk_drop_match(_self, {kk_box_dup(_fun_unbox_x1985);}, {}, _ctx)
  kk_function_t _bv_1989;
  kk_box_t _x2496;
  kk_function_t _x2497 = kk_function_unbox(_fun_unbox_x1985); /*() -> 1986*/
  _x2496 = kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), _x2497, (_x2497, _ctx)); /*1986*/
  _bv_1989 = kk_function_unbox(_x2496); /*(1987) -> 492 1988*/
  return kk_tmcmc__new_copy_fun2498_1(_bv_1989, _ctx);
}
static kk_box_t kk_tmcmc__copy_fun2492_1(kk_function_t _fself, kk_box_t _b_1993, kk_context_t* _ctx) {
  struct kk_tmcmc__copy_fun2492__t_1* _self = kk_function_as(struct kk_tmcmc__copy_fun2492__t_1*, _fself);
  kk_std_core_types__optional m0 = _self->m0; /* optional<() -> ((int) -> 492 491)> */
  kk_std_core_types__optional p0 = _self->p0; /* optional<effects-and-types/exp> */
  kk_tmcmc__trace__rmsmc _this = _self->_this; /* tmcmc/trace_rmsmc<491,492> */
  kk_drop_match(_self, {kk_std_core_types__optional_dup(m0);kk_std_core_types__optional_dup(p0);kk_tmcmc__trace__rmsmc_dup(_this);}, {}, _ctx)
  kk_tmcmc__trace__rmsmc _x2493;
  kk_function_t _x2494;
  if (kk_std_core_types__is_Optional(m0)) {
    kk_box_t _fun_unbox_x1985 = m0._cons.Optional.value;
    _x2494 = kk_tmcmc__new_copy_fun2495_1(_fun_unbox_x1985, _ctx); /*() -> ((int) -> 492 1988)*/
  }
  else {
    kk_function_t _x0 = _this.m;
    kk_effects_dash_and_dash_types__exp _pat010 = _this.p;
    kk_function_dup(_x0);
    _x2494 = _x0; /*() -> ((int) -> 492 1988)*/
  }
  kk_effects_dash_and_dash_types__exp _x2499;
  if (kk_std_core_types__is_Optional(p0)) {
    kk_box_t _box_x1991 = p0._cons.Optional.value;
    kk_effects_dash_and_dash_types__exp _p_442 = kk_effects_dash_and_dash_types__exp_unbox(_box_x1991, NULL);
    kk_std_core_types__optional_drop(p0, _ctx);
    kk_tmcmc__trace__rmsmc_drop(_this, _ctx);
    _x2499 = _p_442; /*effects-and-types/exp*/
    goto _match2500;
  }
  kk_effects_dash_and_dash_types__exp _x00 = _this.p;
  kk_tmcmc__trace__rmsmc_drop(_this, _ctx);
  _x2499 = _x00; /*effects-and-types/exp*/
  _match2500: ;
  kk_std_core__list _x2502 = kk_std_core__list_unbox(_b_1993, _ctx); /*effects-and-types/trace_values*/
  _x2493 = kk_tmcmc__mlift1707_op(_x2494, _x2499, _x2502, _ctx); /*tmcmc/trace_rmsmc<491,492>*/
  return kk_tmcmc__trace__rmsmc_box(_x2493, _ctx);
}


// lift anonymous function
struct kk_tmcmc__copy_fun2504__t_1 {
  struct kk_function_s _base;
  kk_box_t _fun_unbox_x1999;
};
static kk_function_t kk_tmcmc__copy_fun2504_1(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_tmcmc__new_copy_fun2504_1(kk_box_t _fun_unbox_x1999, kk_context_t* _ctx) {
  struct kk_tmcmc__copy_fun2504__t_1* _self = kk_function_alloc_as(struct kk_tmcmc__copy_fun2504__t_1, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc__copy_fun2504_1, kk_context());
  _self->_fun_unbox_x1999 = _fun_unbox_x1999;
  return &_self->_base;
}



// lift anonymous function
struct kk_tmcmc__copy_fun2507__t_1 {
  struct kk_function_s _base;
  kk_function_t _bv_2003;
};
static kk_box_t kk_tmcmc__copy_fun2507_1(kk_function_t _fself, kk_integer_t _b_2004, kk_context_t* _ctx);
static kk_function_t kk_tmcmc__new_copy_fun2507_1(kk_function_t _bv_2003, kk_context_t* _ctx) {
  struct kk_tmcmc__copy_fun2507__t_1* _self = kk_function_alloc_as(struct kk_tmcmc__copy_fun2507__t_1, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc__copy_fun2507_1, kk_context());
  _self->_bv_2003 = _bv_2003;
  return &_self->_base;
}

static kk_box_t kk_tmcmc__copy_fun2507_1(kk_function_t _fself, kk_integer_t _b_2004, kk_context_t* _ctx) {
  struct kk_tmcmc__copy_fun2507__t_1* _self = kk_function_as(struct kk_tmcmc__copy_fun2507__t_1*, _fself);
  kk_function_t _bv_2003 = _self->_bv_2003; /* (2001) -> 492 2002 */
  kk_drop_match(_self, {kk_function_dup(_bv_2003);}, {}, _ctx)
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _bv_2003, (_bv_2003, kk_integer_box(_b_2004), _ctx));
}
static kk_function_t kk_tmcmc__copy_fun2504_1(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_tmcmc__copy_fun2504__t_1* _self = kk_function_as(struct kk_tmcmc__copy_fun2504__t_1*, _fself);
  kk_box_t _fun_unbox_x1999 = _self->_fun_unbox_x1999; /* 33 */
  kk_drop_match(_self, {kk_box_dup(_fun_unbox_x1999);}, {}, _ctx)
  kk_function_t _bv_2003;
  kk_box_t _x2505;
  kk_function_t _x2506 = kk_function_unbox(_fun_unbox_x1999); /*() -> 2000*/
  _x2505 = kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), _x2506, (_x2506, _ctx)); /*2000*/
  _bv_2003 = kk_function_unbox(_x2505); /*(2001) -> 492 2002*/
  return kk_tmcmc__new_copy_fun2507_1(_bv_2003, _ctx);
}

kk_tmcmc__trace__rmsmc kk_tmcmc__copy_1(kk_tmcmc__trace__rmsmc _this, kk_std_core_types__optional m0, kk_std_core_types__optional p0, kk_std_core_types__optional l0, kk_context_t* _ctx) { /* forall<a,e> (trace_rmsmc<a,e>, m : optional<() -> ((int) -> e a)>, p : optional<effects-and-types/exp>, l : optional<effects-and-types/trace_values>) -> trace_rmsmc<a,e> */ 
  if (kk_yielding(kk_context())) {
    kk_std_core_types__optional_drop(m0, _ctx);
    kk_box_t _x2475 = kk_std_core_hnd_yield_extend(kk_tmcmc__new_copy_fun2476_1(l0, p0, _this, _ctx), _ctx); /*2*/
    return kk_tmcmc__trace__rmsmc_unbox(_x2475, _ctx);
  }
  if (kk_yielding(kk_context())) {
    kk_std_core_types__optional_drop(p0, _ctx);
    kk_box_t _x2482 = kk_std_core_hnd_yield_extend(kk_tmcmc__new_copy_fun2483_1(l0, m0, _this, _ctx), _ctx); /*2*/
    return kk_tmcmc__trace__rmsmc_unbox(_x2482, _ctx);
  }
  if (kk_yielding(kk_context())) {
    kk_std_core_types__optional_drop(l0, _ctx);
    kk_box_t _x2491 = kk_std_core_hnd_yield_extend(kk_tmcmc__new_copy_fun2492_1(m0, p0, _this, _ctx), _ctx); /*2*/
    return kk_tmcmc__trace__rmsmc_unbox(_x2491, _ctx);
  }
  kk_function_t _x2503;
  if (kk_std_core_types__is_Optional(m0)) {
    kk_box_t _fun_unbox_x1999 = m0._cons.Optional.value;
    _x2503 = kk_tmcmc__new_copy_fun2504_1(_fun_unbox_x1999, _ctx); /*() -> ((int) -> 492 2002)*/
  }
  else {
    kk_function_t _x1 = _this.m;
    kk_effects_dash_and_dash_types__exp _pat011 = _this.p;
    kk_function_dup(_x1);
    _x2503 = _x1; /*() -> ((int) -> 492 2002)*/
  }
  kk_effects_dash_and_dash_types__exp _x2508;
  if (kk_std_core_types__is_Optional(p0)) {
    kk_box_t _box_x2005 = p0._cons.Optional.value;
    kk_effects_dash_and_dash_types__exp _p_4420 = kk_effects_dash_and_dash_types__exp_unbox(_box_x2005, NULL);
    kk_std_core_types__optional_drop(p0, _ctx);
    _x2508 = _p_4420; /*effects-and-types/exp*/
    goto _match2509;
  }
  kk_effects_dash_and_dash_types__exp _x01 = _this.p;
  _x2508 = _x01; /*effects-and-types/exp*/
  _match2509: ;
  kk_std_core__list _x2511;
  if (kk_std_core_types__is_Optional(l0)) {
    kk_box_t _box_x2006 = l0._cons.Optional.value;
    kk_std_core__list _l_476 = kk_std_core__list_unbox(_box_x2006, NULL);
    kk_std_core__list_dup(_l_476);
    kk_std_core_types__optional_drop(l0, _ctx);
    kk_tmcmc__trace__rmsmc_drop(_this, _ctx);
    _x2511 = _l_476; /*effects-and-types/trace_values*/
    goto _match2512;
  }
  kk_effects_dash_and_dash_types__exp _pat130 = _this.p;
  kk_std_core__list _x10 = _this.l;
  kk_std_core__list_dup(_x10);
  kk_tmcmc__trace__rmsmc_drop(_this, _ctx);
  _x2511 = _x10; /*effects-and-types/trace_values*/
  _match2512: ;
  return kk_tmcmc__new_RTrace(_x2503, _x2508, _x2511, _ctx);
}
 
// monadic lift

kk_integer_t kk_tmcmc__mlift1710_random__range(kk_integer_t upper__bound, double _y_8, kk_context_t* _ctx) { /* (upper_bound : int, double) -> effects-and-types/sample int */ 
  kk_integer_t _x2514;
  double _x2515;
  double _x2516;
  double _x2517;
  kk_integer_t _x2518 = kk_integer_dup(upper__bound); /*int*/
  _x2517 = kk_integer_as_double(_x2518,kk_context()); /*double*/
  _x2516 = (0x1p0 / _x2517); /*double*/
  _x2515 = (_y_8 / _x2516); /*double*/
  _x2514 = kk_integer_from_double(_x2515,kk_context()); /*int*/
  return kk_integer_mod(_x2514,upper__bound,kk_context());
}


// lift anonymous function
struct kk_tmcmc_random__range_fun2520__t {
  struct kk_function_s _base;
  kk_integer_t upper__bound;
};
static kk_box_t kk_tmcmc_random__range_fun2520(kk_function_t _fself, kk_box_t _b_2014, kk_context_t* _ctx);
static kk_function_t kk_tmcmc_new_random__range_fun2520(kk_integer_t upper__bound, kk_context_t* _ctx) {
  struct kk_tmcmc_random__range_fun2520__t* _self = kk_function_alloc_as(struct kk_tmcmc_random__range_fun2520__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc_random__range_fun2520, kk_context());
  _self->upper__bound = upper__bound;
  return &_self->_base;
}

static kk_box_t kk_tmcmc_random__range_fun2520(kk_function_t _fself, kk_box_t _b_2014, kk_context_t* _ctx) {
  struct kk_tmcmc_random__range_fun2520__t* _self = kk_function_as(struct kk_tmcmc_random__range_fun2520__t*, _fself);
  kk_integer_t upper__bound = _self->upper__bound; /* int */
  kk_drop_match(_self, {kk_integer_dup(upper__bound);}, {}, _ctx)
  kk_integer_t _x2521;
  double _x2522 = kk_double_unbox(_b_2014, _ctx); /*double*/
  _x2521 = kk_tmcmc__mlift1710_random__range(upper__bound, _x2522, _ctx); /*int*/
  return kk_integer_box(_x2521);
}

kk_integer_t kk_tmcmc_random__range(kk_integer_t upper__bound, kk_context_t* _ctx) { /* (upper_bound : int) -> effects-and-types/sample int */ 
  double x_1771 = kk_effects_dash_and_dash_types_sample(_ctx); /*double*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x2519 = kk_std_core_hnd_yield_extend(kk_tmcmc_new_random__range_fun2520(upper__bound, _ctx), _ctx); /*2*/
    return kk_integer_unbox(_x2519);
  }
  kk_integer_t _x2523;
  double _x2524;
  double _x2525;
  double _x2526;
  kk_integer_t _x2527 = kk_integer_dup(upper__bound); /*int*/
  _x2526 = kk_integer_as_double(_x2527,kk_context()); /*double*/
  _x2525 = (0x1p0 / _x2526); /*double*/
  _x2524 = (x_1771 / _x2525); /*double*/
  _x2523 = kk_integer_from_double(_x2524,kk_context()); /*int*/
  return kk_integer_mod(_x2523,upper__bound,kk_context());
}


// lift anonymous function
struct kk_tmcmc_with__randomness_fun2528__t {
  struct kk_function_s _base;
  kk_function_t model;
};
static kk_box_t kk_tmcmc_with__randomness_fun2528(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_tmcmc_new_with__randomness_fun2528(kk_function_t model, kk_context_t* _ctx) {
  struct kk_tmcmc_with__randomness_fun2528__t* _self = kk_function_alloc_as(struct kk_tmcmc_with__randomness_fun2528__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc_with__randomness_fun2528, kk_context());
  _self->model = model;
  return &_self->_base;
}



// lift anonymous function
struct kk_tmcmc_with__randomness_fun2532__t {
  struct kk_function_s _base;
  kk_function_t model;
};
static kk_box_t kk_tmcmc_with__randomness_fun2532(kk_function_t _fself, kk_box_t _b_2020, kk_context_t* _ctx);
static kk_function_t kk_tmcmc_new_with__randomness_fun2532(kk_function_t model, kk_context_t* _ctx) {
  struct kk_tmcmc_with__randomness_fun2532__t* _self = kk_function_alloc_as(struct kk_tmcmc_with__randomness_fun2532__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc_with__randomness_fun2532, kk_context());
  _self->model = model;
  return &_self->_base;
}



// lift anonymous function
struct kk_tmcmc_with__randomness_fun2533__t {
  struct kk_function_s _base;
  kk_function_t model;
};
static kk_box_t kk_tmcmc_with__randomness_fun2533(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_tmcmc_new_with__randomness_fun2533(kk_function_t model, kk_context_t* _ctx) {
  struct kk_tmcmc_with__randomness_fun2533__t* _self = kk_function_alloc_as(struct kk_tmcmc_with__randomness_fun2533__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc_with__randomness_fun2533, kk_context());
  _self->model = model;
  return &_self->_base;
}

static kk_box_t kk_tmcmc_with__randomness_fun2533(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_tmcmc_with__randomness_fun2533__t* _self = kk_function_as(struct kk_tmcmc_with__randomness_fun2533__t*, _fself);
  kk_function_t model = _self->model; /* () -> <effects-and-types/sample,effects-and-types/score|736> 735 */
  kk_drop_match(_self, {kk_function_dup(model);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x2534;
  kk_effects_dash_and_dash_types__exp _x2535 = kk_effects_dash_and_dash_types__new_Exp(0x0p+0, _ctx); /*effects-and-types/exp*/
  _x2534 = kk_handlers_weighted(_x2535, model, _ctx); /*(effects-and-types/exp, 0)*/
  return kk_std_core_types__tuple2__box(_x2534, _ctx);
}
static kk_box_t kk_tmcmc_with__randomness_fun2532(kk_function_t _fself, kk_box_t _b_2020, kk_context_t* _ctx) {
  struct kk_tmcmc_with__randomness_fun2532__t* _self = kk_function_as(struct kk_tmcmc_with__randomness_fun2532__t*, _fself);
  kk_function_t model = _self->model; /* () -> <effects-and-types/sample,effects-and-types/score|736> 735 */
  kk_drop_match(_self, {kk_function_dup(model);}, {}, _ctx)
  size_t _x2536 = kk_size_unbox(_b_2020, _ctx); /*std/core/hnd/ev-index*/
  return kk_handlers__mlift2035_replay(kk_tmcmc_new_with__randomness_fun2533(model, _ctx), _x2536, _ctx);
}


// lift anonymous function
struct kk_tmcmc_with__randomness_fun2537__t {
  struct kk_function_s _base;
  kk_function_t model;
};
static kk_box_t kk_tmcmc_with__randomness_fun2537(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_tmcmc_new_with__randomness_fun2537(kk_function_t model, kk_context_t* _ctx) {
  struct kk_tmcmc_with__randomness_fun2537__t* _self = kk_function_alloc_as(struct kk_tmcmc_with__randomness_fun2537__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc_with__randomness_fun2537, kk_context());
  _self->model = model;
  return &_self->_base;
}

static kk_box_t kk_tmcmc_with__randomness_fun2537(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_tmcmc_with__randomness_fun2537__t* _self = kk_function_as(struct kk_tmcmc_with__randomness_fun2537__t*, _fself);
  kk_function_t model = _self->model; /* () -> <effects-and-types/sample,effects-and-types/score|736> 735 */
  kk_drop_match(_self, {kk_function_dup(model);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x2538;
  kk_effects_dash_and_dash_types__exp _x2539 = kk_effects_dash_and_dash_types__new_Exp(0x0p+0, _ctx); /*effects-and-types/exp*/
  _x2538 = kk_handlers_weighted(_x2539, model, _ctx); /*(effects-and-types/exp, 0)*/
  return kk_std_core_types__tuple2__box(_x2538, _ctx);
}
static kk_box_t kk_tmcmc_with__randomness_fun2528(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_tmcmc_with__randomness_fun2528__t* _self = kk_function_as(struct kk_tmcmc_with__randomness_fun2528__t*, _fself);
  kk_function_t model = _self->model; /* () -> <effects-and-types/sample,effects-and-types/score|736> 735 */
  kk_drop_match(_self, {kk_function_dup(model);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x2529;
  size_t x_2130;
  kk_std_core_hnd__htag _x2530 = kk_std_core_hnd__htag_dup(kk_effects_dash_and_dash_types__tag_sample); /*std/core/hnd/htag<effects-and-types/.hnd-sample>*/
  x_2130 = kk_std_core_hnd__evv_index(_x2530, _ctx); /*std/core/hnd/ev-index*/
  kk_box_t _x2531;
  if (kk_yielding(kk_context())) {
    _x2531 = kk_std_core_hnd_yield_extend(kk_tmcmc_new_with__randomness_fun2532(model, _ctx), _ctx); /*2*/
  }
  else {
    _x2531 = kk_handlers__mlift2035_replay(kk_tmcmc_new_with__randomness_fun2537(model, _ctx), x_2130, _ctx); /*2*/
  }
  _x2529 = kk_std_core_types__tuple2__unbox(_x2531, _ctx); /*(effects-and-types/exp, 735)*/
  return kk_std_core_types__tuple2__box(_x2529, _ctx);
}

kk_std_core_types__tuple2_ kk_tmcmc_with__randomness(kk_function_t model, kk_std_core__list trace__values, kk_context_t* _ctx) { /* forall<a,e> (model : () -> <effects-and-types/sample,effects-and-types/score|e> a, trace_values : effects-and-types/trace_values) -> <effects-and-types/sample|e> (effects-and-types/trace_values, (effects-and-types/exp, a)) */ 
  return kk_handlers_replayx(trace__values, kk_tmcmc_new_with__randomness_fun2528(model, _ctx), _ctx);
}


// lift anonymous function
struct kk_tmcmc_with__randomness__rmsmc_fun2540__t {
  struct kk_function_s _base;
  kk_function_t model;
  kk_std_core__list trace__values;
};
static kk_std_core_types__tuple2_ kk_tmcmc_with__randomness__rmsmc_fun2540(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_tmcmc_new_with__randomness__rmsmc_fun2540(kk_function_t model, kk_std_core__list trace__values, kk_context_t* _ctx) {
  struct kk_tmcmc_with__randomness__rmsmc_fun2540__t* _self = kk_function_alloc_as(struct kk_tmcmc_with__randomness__rmsmc_fun2540__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc_with__randomness__rmsmc_fun2540, kk_context());
  _self->model = model;
  _self->trace__values = trace__values;
  return &_self->_base;
}



// lift anonymous function
struct kk_tmcmc_with__randomness__rmsmc_fun2542__t {
  struct kk_function_s _base;
  kk_function_t model;
  kk_std_core__list trace__values;
};
static kk_box_t kk_tmcmc_with__randomness__rmsmc_fun2542(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_tmcmc_new_with__randomness__rmsmc_fun2542(kk_function_t model, kk_std_core__list trace__values, kk_context_t* _ctx) {
  struct kk_tmcmc_with__randomness__rmsmc_fun2542__t* _self = kk_function_alloc_as(struct kk_tmcmc_with__randomness__rmsmc_fun2542__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc_with__randomness__rmsmc_fun2542, kk_context());
  _self->model = model;
  _self->trace__values = trace__values;
  return &_self->_base;
}



// lift anonymous function
struct kk_tmcmc_with__randomness__rmsmc_fun2546__t {
  struct kk_function_s _base;
  kk_function_t model;
};
static kk_box_t kk_tmcmc_with__randomness__rmsmc_fun2546(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_tmcmc_new_with__randomness__rmsmc_fun2546(kk_function_t model, kk_context_t* _ctx) {
  struct kk_tmcmc_with__randomness__rmsmc_fun2546__t* _self = kk_function_alloc_as(struct kk_tmcmc_with__randomness__rmsmc_fun2546__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc_with__randomness__rmsmc_fun2546, kk_context());
  _self->model = model;
  return &_self->_base;
}



// lift anonymous function
struct kk_tmcmc_with__randomness__rmsmc_fun2548__t {
  struct kk_function_s _base;
  kk_function_t _bv_2036;
};
static kk_box_t kk_tmcmc_with__randomness__rmsmc_fun2548(kk_function_t _fself, kk_box_t _b_2037, kk_context_t* _ctx);
static kk_function_t kk_tmcmc_new_with__randomness__rmsmc_fun2548(kk_function_t _bv_2036, kk_context_t* _ctx) {
  struct kk_tmcmc_with__randomness__rmsmc_fun2548__t* _self = kk_function_alloc_as(struct kk_tmcmc_with__randomness__rmsmc_fun2548__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc_with__randomness__rmsmc_fun2548, kk_context());
  _self->_bv_2036 = _bv_2036;
  return &_self->_base;
}

static kk_box_t kk_tmcmc_with__randomness__rmsmc_fun2548(kk_function_t _fself, kk_box_t _b_2037, kk_context_t* _ctx) {
  struct kk_tmcmc_with__randomness__rmsmc_fun2548__t* _self = kk_function_as(struct kk_tmcmc_with__randomness__rmsmc_fun2548__t*, _fself);
  kk_function_t _bv_2036 = _self->_bv_2036; /* (int) -> <exn,effects-and-types/yield,effects-and-types/score,effects-and-types/sample,effects-and-types/sample|793> 792 */
  kk_drop_match(_self, {kk_function_dup(_bv_2036);}, {}, _ctx)
  kk_integer_t _x2549 = kk_integer_unbox(_b_2037); /*int*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_context_t*), _bv_2036, (_bv_2036, _x2549, _ctx));
}
static kk_box_t kk_tmcmc_with__randomness__rmsmc_fun2546(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_tmcmc_with__randomness__rmsmc_fun2546__t* _self = kk_function_as(struct kk_tmcmc_with__randomness__rmsmc_fun2546__t*, _fself);
  kk_function_t model = _self->model; /* () -> ((int) -> <exn,effects-and-types/yield,effects-and-types/score,effects-and-types/sample,effects-and-types/sample|793> 792) */
  kk_drop_match(_self, {kk_function_dup(model);}, {}, _ctx)
  kk_function_t _x2547;
  kk_function_t _bv_2036 = kk_function_call(kk_function_t, (kk_function_t, kk_context_t*), model, (model, _ctx)); /*(int) -> <exn,effects-and-types/yield,effects-and-types/score,effects-and-types/sample,effects-and-types/sample|793> 792*/;
  _x2547 = kk_tmcmc_new_with__randomness__rmsmc_fun2548(_bv_2036, _ctx); /*(2034) -> <exn,effects-and-types/yield,effects-and-types/score,effects-and-types/sample,effects-and-types/sample|793> 792*/
  return kk_function_box(_x2547);
}


// lift anonymous function
struct kk_tmcmc_with__randomness__rmsmc_fun2550__t {
  struct kk_function_s _base;
  kk_function_t _bv_2040;
};
static kk_box_t kk_tmcmc_with__randomness__rmsmc_fun2550(kk_function_t _fself, kk_integer_t _b_2041, kk_context_t* _ctx);
static kk_function_t kk_tmcmc_new_with__randomness__rmsmc_fun2550(kk_function_t _bv_2040, kk_context_t* _ctx) {
  struct kk_tmcmc_with__randomness__rmsmc_fun2550__t* _self = kk_function_alloc_as(struct kk_tmcmc_with__randomness__rmsmc_fun2550__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc_with__randomness__rmsmc_fun2550, kk_context());
  _self->_bv_2040 = _bv_2040;
  return &_self->_base;
}

static kk_box_t kk_tmcmc_with__randomness__rmsmc_fun2550(kk_function_t _fself, kk_integer_t _b_2041, kk_context_t* _ctx) {
  struct kk_tmcmc_with__randomness__rmsmc_fun2550__t* _self = kk_function_as(struct kk_tmcmc_with__randomness__rmsmc_fun2550__t*, _fself);
  kk_function_t _bv_2040 = _self->_bv_2040; /* (2038) -> 2039 */
  kk_drop_match(_self, {kk_function_dup(_bv_2040);}, {}, _ctx)
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _bv_2040, (_bv_2040, kk_integer_box(_b_2041), _ctx));
}
static kk_box_t kk_tmcmc_with__randomness__rmsmc_fun2542(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_tmcmc_with__randomness__rmsmc_fun2542__t* _self = kk_function_as(struct kk_tmcmc_with__randomness__rmsmc_fun2542__t*, _fself);
  kk_function_t model = _self->model; /* () -> ((int) -> <exn,effects-and-types/yield,effects-and-types/score,effects-and-types/sample,effects-and-types/sample|793> 792) */
  kk_std_core__list trace__values = _self->trace__values; /* effects-and-types/trace_values */
  kk_drop_match(_self, {kk_function_dup(model);kk_std_core__list_dup(trace__values);}, {}, _ctx)
  kk_function_t _x2544;
  kk_function_t _bv_2040;
  kk_box_t _x2545 = kk_std_core_hnd__open_none0(kk_tmcmc_new_with__randomness__rmsmc_fun2546(model, _ctx), _ctx); /*1*/
  _bv_2040 = kk_function_unbox(_x2545); /*(2038) -> 2039*/
  _x2544 = kk_tmcmc_new_with__randomness__rmsmc_fun2550(_bv_2040, _ctx); /*(int) -> 2039*/
  kk_integer_t _x2543 = kk_std_core_length_1(trace__values, _ctx); /*int*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_context_t*), _x2544, (_x2544, _x2543, _ctx));
}
static kk_std_core_types__tuple2_ kk_tmcmc_with__randomness__rmsmc_fun2540(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_tmcmc_with__randomness__rmsmc_fun2540__t* _self = kk_function_as(struct kk_tmcmc_with__randomness__rmsmc_fun2540__t*, _fself);
  kk_function_t model = _self->model; /* () -> ((int) -> <exn,effects-and-types/yield,effects-and-types/score,effects-and-types/sample,effects-and-types/sample|793> 792) */
  kk_std_core__list trace__values = _self->trace__values; /* effects-and-types/trace_values */
  kk_drop_match(_self, {kk_function_dup(model);kk_std_core__list_dup(trace__values);}, {}, _ctx)
  kk_effects_dash_and_dash_types__exp _x2541 = kk_effects_dash_and_dash_types__new_Exp(0x0p+0, _ctx); /*effects-and-types/exp*/
  return kk_handlers_weighted(_x2541, kk_tmcmc_new_with__randomness__rmsmc_fun2542(model, trace__values, _ctx), _ctx);
}


// lift anonymous function
struct kk_tmcmc_with__randomness__rmsmc_fun2551__t {
  struct kk_function_s _base;
  kk_function_t action_1778;
};
static kk_box_t kk_tmcmc_with__randomness__rmsmc_fun2551(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_tmcmc_new_with__randomness__rmsmc_fun2551(kk_function_t action_1778, kk_context_t* _ctx) {
  struct kk_tmcmc_with__randomness__rmsmc_fun2551__t* _self = kk_function_alloc_as(struct kk_tmcmc_with__randomness__rmsmc_fun2551__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc_with__randomness__rmsmc_fun2551, kk_context());
  _self->action_1778 = action_1778;
  return &_self->_base;
}



// lift anonymous function
struct kk_tmcmc_with__randomness__rmsmc_fun2555__t {
  struct kk_function_s _base;
  kk_function_t action_1778;
};
static kk_box_t kk_tmcmc_with__randomness__rmsmc_fun2555(kk_function_t _fself, kk_box_t _b_2046, kk_context_t* _ctx);
static kk_function_t kk_tmcmc_new_with__randomness__rmsmc_fun2555(kk_function_t action_1778, kk_context_t* _ctx) {
  struct kk_tmcmc_with__randomness__rmsmc_fun2555__t* _self = kk_function_alloc_as(struct kk_tmcmc_with__randomness__rmsmc_fun2555__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc_with__randomness__rmsmc_fun2555, kk_context());
  _self->action_1778 = action_1778;
  return &_self->_base;
}



// lift anonymous function
struct kk_tmcmc_with__randomness__rmsmc_fun2556__t {
  struct kk_function_s _base;
  kk_function_t action_1778;
};
static kk_box_t kk_tmcmc_with__randomness__rmsmc_fun2556(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_tmcmc_new_with__randomness__rmsmc_fun2556(kk_function_t action_1778, kk_context_t* _ctx) {
  struct kk_tmcmc_with__randomness__rmsmc_fun2556__t* _self = kk_function_alloc_as(struct kk_tmcmc_with__randomness__rmsmc_fun2556__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc_with__randomness__rmsmc_fun2556, kk_context());
  _self->action_1778 = action_1778;
  return &_self->_base;
}

static kk_box_t kk_tmcmc_with__randomness__rmsmc_fun2556(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_tmcmc_with__randomness__rmsmc_fun2556__t* _self = kk_function_as(struct kk_tmcmc_with__randomness__rmsmc_fun2556__t*, _fself);
  kk_function_t action_1778 = _self->action_1778; /* () -> <effects-and-types/sample,exn,effects-and-types/sample,effects-and-types/yield|793> (effects-and-types/exp, 792) */
  kk_drop_match(_self, {kk_function_dup(action_1778);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x2557 = kk_function_call(kk_std_core_types__tuple2_, (kk_function_t, kk_context_t*), action_1778, (action_1778, _ctx)); /*(effects-and-types/exp, 792)*/
  return kk_std_core_types__tuple2__box(_x2557, _ctx);
}
static kk_box_t kk_tmcmc_with__randomness__rmsmc_fun2555(kk_function_t _fself, kk_box_t _b_2046, kk_context_t* _ctx) {
  struct kk_tmcmc_with__randomness__rmsmc_fun2555__t* _self = kk_function_as(struct kk_tmcmc_with__randomness__rmsmc_fun2555__t*, _fself);
  kk_function_t action_1778 = _self->action_1778; /* () -> <effects-and-types/sample,exn,effects-and-types/sample,effects-and-types/yield|793> (effects-and-types/exp, 792) */
  kk_drop_match(_self, {kk_function_dup(action_1778);}, {}, _ctx)
  size_t _x2558 = kk_size_unbox(_b_2046, _ctx); /*std/core/hnd/ev-index*/
  return kk_handlers__mlift2035_replay(kk_tmcmc_new_with__randomness__rmsmc_fun2556(action_1778, _ctx), _x2558, _ctx);
}


// lift anonymous function
struct kk_tmcmc_with__randomness__rmsmc_fun2559__t {
  struct kk_function_s _base;
  kk_function_t action_1778;
};
static kk_box_t kk_tmcmc_with__randomness__rmsmc_fun2559(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_tmcmc_new_with__randomness__rmsmc_fun2559(kk_function_t action_1778, kk_context_t* _ctx) {
  struct kk_tmcmc_with__randomness__rmsmc_fun2559__t* _self = kk_function_alloc_as(struct kk_tmcmc_with__randomness__rmsmc_fun2559__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc_with__randomness__rmsmc_fun2559, kk_context());
  _self->action_1778 = action_1778;
  return &_self->_base;
}

static kk_box_t kk_tmcmc_with__randomness__rmsmc_fun2559(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_tmcmc_with__randomness__rmsmc_fun2559__t* _self = kk_function_as(struct kk_tmcmc_with__randomness__rmsmc_fun2559__t*, _fself);
  kk_function_t action_1778 = _self->action_1778; /* () -> <effects-and-types/sample,exn,effects-and-types/sample,effects-and-types/yield|793> (effects-and-types/exp, 792) */
  kk_drop_match(_self, {kk_function_dup(action_1778);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x2560 = kk_function_call(kk_std_core_types__tuple2_, (kk_function_t, kk_context_t*), action_1778, (action_1778, _ctx)); /*(effects-and-types/exp, 792)*/
  return kk_std_core_types__tuple2__box(_x2560, _ctx);
}
static kk_box_t kk_tmcmc_with__randomness__rmsmc_fun2551(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_tmcmc_with__randomness__rmsmc_fun2551__t* _self = kk_function_as(struct kk_tmcmc_with__randomness__rmsmc_fun2551__t*, _fself);
  kk_function_t action_1778 = _self->action_1778; /* () -> <effects-and-types/sample,exn,effects-and-types/sample,effects-and-types/yield|793> (effects-and-types/exp, 792) */
  kk_drop_match(_self, {kk_function_dup(action_1778);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x2552;
  size_t x_2130;
  kk_std_core_hnd__htag _x2553 = kk_std_core_hnd__htag_dup(kk_effects_dash_and_dash_types__tag_sample); /*std/core/hnd/htag<effects-and-types/.hnd-sample>*/
  x_2130 = kk_std_core_hnd__evv_index(_x2553, _ctx); /*std/core/hnd/ev-index*/
  kk_box_t _x2554;
  if (kk_yielding(kk_context())) {
    _x2554 = kk_std_core_hnd_yield_extend(kk_tmcmc_new_with__randomness__rmsmc_fun2555(action_1778, _ctx), _ctx); /*2*/
  }
  else {
    _x2554 = kk_handlers__mlift2035_replay(kk_tmcmc_new_with__randomness__rmsmc_fun2559(action_1778, _ctx), x_2130, _ctx); /*2*/
  }
  _x2552 = kk_std_core_types__tuple2__unbox(_x2554, _ctx); /*(effects-and-types/exp, 792)*/
  return kk_std_core_types__tuple2__box(_x2552, _ctx);
}

kk_std_core_types__tuple2_ kk_tmcmc_with__randomness__rmsmc(kk_function_t model, kk_std_core__list trace__values, kk_context_t* _ctx) { /* forall<a,e> (model : () -> ((int) -> <exn,effects-and-types/yield,effects-and-types/score,effects-and-types/sample,effects-and-types/sample|e> a), trace_values : effects-and-types/trace_values) -> <effects-and-types/sample,effects-and-types/sample,exn,effects-and-types/yield|e> (effects-and-types/trace_values, (effects-and-types/exp, a)) */ 
  kk_function_t action_1778;
  kk_std_core__list_dup(trace__values);
  action_1778 = kk_tmcmc_new_with__randomness__rmsmc_fun2540(model, trace__values, _ctx); /*() -> <effects-and-types/sample,exn,effects-and-types/sample,effects-and-types/yield|793> (effects-and-types/exp, 792)*/
  return kk_handlers_replayx(trace__values, kk_tmcmc_new_with__randomness__rmsmc_fun2551(action_1778, _ctx), _ctx);
}
 
// monadic lift

kk_std_core__list kk_tmcmc__mlift1711_perturb__trace(kk_std_core__list l1, kk_std_core__list l2, double _y_15, kk_context_t* _ctx) { /* (l1 : list<double>, l2 : list<double>, double) -> effects-and-types/sample list<double> */ 
  kk_std_core__list ys_1780;
  kk_std_core__list xs0_1781 = kk_std_core__new_Cons(kk_reuse_null, kk_double_box(_y_15, _ctx), kk_std_core__new_Nil(_ctx), _ctx); /*list<double>*/;
  ys_1780 = kk_std_core_append(xs0_1781, l2, _ctx); /*list<double>*/
  return kk_std_core_append(l1, ys_1780, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_tmcmc__mlift1712_perturb__trace_fun2566__t {
  struct kk_function_s _base;
  kk_std_core__list l1;
  kk_std_core__list l2;
};
static kk_box_t kk_tmcmc__mlift1712_perturb__trace_fun2566(kk_function_t _fself, kk_box_t _b_2067, kk_context_t* _ctx);
static kk_function_t kk_tmcmc__new_mlift1712_perturb__trace_fun2566(kk_std_core__list l1, kk_std_core__list l2, kk_context_t* _ctx) {
  struct kk_tmcmc__mlift1712_perturb__trace_fun2566__t* _self = kk_function_alloc_as(struct kk_tmcmc__mlift1712_perturb__trace_fun2566__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc__mlift1712_perturb__trace_fun2566, kk_context());
  _self->l1 = l1;
  _self->l2 = l2;
  return &_self->_base;
}

static kk_box_t kk_tmcmc__mlift1712_perturb__trace_fun2566(kk_function_t _fself, kk_box_t _b_2067, kk_context_t* _ctx) {
  struct kk_tmcmc__mlift1712_perturb__trace_fun2566__t* _self = kk_function_as(struct kk_tmcmc__mlift1712_perturb__trace_fun2566__t*, _fself);
  kk_std_core__list l1 = _self->l1; /* list<double> */
  kk_std_core__list l2 = _self->l2; /* list<double> */
  kk_drop_match(_self, {kk_std_core__list_dup(l1);kk_std_core__list_dup(l2);}, {}, _ctx)
  kk_std_core__list _x2567;
  double _x2568 = kk_double_unbox(_b_2067, _ctx); /*double*/
  _x2567 = kk_tmcmc__mlift1711_perturb__trace(l1, l2, _x2568, _ctx); /*list<double>*/
  return kk_std_core__list_box(_x2567, _ctx);
}

kk_std_core__list kk_tmcmc__mlift1712_perturb__trace(kk_std_core__list trace__values, kk_integer_t perturb__index, kk_context_t* _ctx) { /* (trace_values : effects-and-types/trace_values, perturb_index : int) -> effects-and-types/sample list<double> */ 
  kk_std_core_types__tuple2_ div__trace = kk_std_core_split(trace__values, perturb__index, _ctx); /*(list<double>, list<double>)*/;
  kk_box_t _box_x2063 = div__trace.fst;
  kk_box_t _box_x2064 = div__trace.snd;
  kk_std_core__list l1 = kk_std_core__list_unbox(_box_x2063, NULL);
  kk_std_core__list _pat0 = kk_std_core__list_unbox(_box_x2064, NULL);
  if (kk_std_core__is_Cons(_pat0)) {
    struct kk_std_core_Cons* _con2563 = kk_std_core__as_Cons(_pat0);
    kk_box_t _box_x2065 = _con2563->head;
    kk_std_core__list l2 = _con2563->tail;
    kk_std_core__list_dup(l1);
    kk_std_core__list_dup(l2);
    kk_std_core_types__tuple2__drop(div__trace, _ctx);
    double x_1783 = kk_effects_dash_and_dash_types_sample(_ctx); /*double*/;
    if (kk_yielding(kk_context())) {
      kk_box_t _x2565 = kk_std_core_hnd_yield_extend(kk_tmcmc__new_mlift1712_perturb__trace_fun2566(l1, l2, _ctx), _ctx); /*2*/
      return kk_std_core__list_unbox(_x2565, _ctx);
    }
    return kk_tmcmc__mlift1711_perturb__trace(l1, l2, x_1783, _ctx);
  }
  kk_box_t _box_x2068 = div__trace.fst;
  kk_box_t _box_x2069 = div__trace.snd;
  kk_std_core__list l10 = kk_std_core__list_unbox(_box_x2068, NULL);
  kk_std_core__list l20 = kk_std_core__list_unbox(_box_x2069, NULL);
  kk_std_core__list_dup(l10);
  kk_std_core__list_dup(l20);
  kk_std_core_types__tuple2__drop(div__trace, _ctx);
  return kk_std_core__lp__plus__plus__rp_(l10, l20, _ctx);
}


// lift anonymous function
struct kk_tmcmc_perturb__trace_fun2573__t {
  struct kk_function_s _base;
  kk_integer_t upper__bound_1788;
};
static kk_box_t kk_tmcmc_perturb__trace_fun2573(kk_function_t _fself, kk_box_t _b_2073, kk_context_t* _ctx);
static kk_function_t kk_tmcmc_new_perturb__trace_fun2573(kk_integer_t upper__bound_1788, kk_context_t* _ctx) {
  struct kk_tmcmc_perturb__trace_fun2573__t* _self = kk_function_alloc_as(struct kk_tmcmc_perturb__trace_fun2573__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc_perturb__trace_fun2573, kk_context());
  _self->upper__bound_1788 = upper__bound_1788;
  return &_self->_base;
}

static kk_box_t kk_tmcmc_perturb__trace_fun2573(kk_function_t _fself, kk_box_t _b_2073, kk_context_t* _ctx) {
  struct kk_tmcmc_perturb__trace_fun2573__t* _self = kk_function_as(struct kk_tmcmc_perturb__trace_fun2573__t*, _fself);
  kk_integer_t upper__bound_1788 = _self->upper__bound_1788; /* int */
  kk_drop_match(_self, {kk_integer_dup(upper__bound_1788);}, {}, _ctx)
  kk_integer_t _x2574;
  double _x2575 = kk_double_unbox(_b_2073, _ctx); /*double*/
  _x2574 = kk_tmcmc__mlift1710_random__range(upper__bound_1788, _x2575, _ctx); /*int*/
  return kk_integer_box(_x2574);
}


// lift anonymous function
struct kk_tmcmc_perturb__trace_fun2582__t {
  struct kk_function_s _base;
  kk_std_core__list trace__values;
};
static kk_box_t kk_tmcmc_perturb__trace_fun2582(kk_function_t _fself, kk_box_t _b_2077, kk_context_t* _ctx);
static kk_function_t kk_tmcmc_new_perturb__trace_fun2582(kk_std_core__list trace__values, kk_context_t* _ctx) {
  struct kk_tmcmc_perturb__trace_fun2582__t* _self = kk_function_alloc_as(struct kk_tmcmc_perturb__trace_fun2582__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc_perturb__trace_fun2582, kk_context());
  _self->trace__values = trace__values;
  return &_self->_base;
}

static kk_box_t kk_tmcmc_perturb__trace_fun2582(kk_function_t _fself, kk_box_t _b_2077, kk_context_t* _ctx) {
  struct kk_tmcmc_perturb__trace_fun2582__t* _self = kk_function_as(struct kk_tmcmc_perturb__trace_fun2582__t*, _fself);
  kk_std_core__list trace__values = _self->trace__values; /* effects-and-types/trace_values */
  kk_drop_match(_self, {kk_std_core__list_dup(trace__values);}, {}, _ctx)
  kk_std_core__list _x2583;
  kk_integer_t _x2584 = kk_integer_unbox(_b_2077); /*int*/
  _x2583 = kk_tmcmc__mlift1712_perturb__trace(trace__values, _x2584, _ctx); /*list<double>*/
  return kk_std_core__list_box(_x2583, _ctx);
}


// lift anonymous function
struct kk_tmcmc_perturb__trace_fun2590__t {
  struct kk_function_s _base;
  kk_std_core__list l1;
  kk_std_core__list l2;
};
static kk_box_t kk_tmcmc_perturb__trace_fun2590(kk_function_t _fself, kk_box_t _b_2082, kk_context_t* _ctx);
static kk_function_t kk_tmcmc_new_perturb__trace_fun2590(kk_std_core__list l1, kk_std_core__list l2, kk_context_t* _ctx) {
  struct kk_tmcmc_perturb__trace_fun2590__t* _self = kk_function_alloc_as(struct kk_tmcmc_perturb__trace_fun2590__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc_perturb__trace_fun2590, kk_context());
  _self->l1 = l1;
  _self->l2 = l2;
  return &_self->_base;
}

static kk_box_t kk_tmcmc_perturb__trace_fun2590(kk_function_t _fself, kk_box_t _b_2082, kk_context_t* _ctx) {
  struct kk_tmcmc_perturb__trace_fun2590__t* _self = kk_function_as(struct kk_tmcmc_perturb__trace_fun2590__t*, _fself);
  kk_std_core__list l1 = _self->l1; /* list<double> */
  kk_std_core__list l2 = _self->l2; /* list<double> */
  kk_drop_match(_self, {kk_std_core__list_dup(l1);kk_std_core__list_dup(l2);}, {}, _ctx)
  kk_std_core__list _x2591;
  double _x2592 = kk_double_unbox(_b_2082, _ctx); /*double*/
  _x2591 = kk_tmcmc__mlift1711_perturb__trace(l1, l2, _x2592, _ctx); /*list<double>*/
  return kk_std_core__list_box(_x2591, _ctx);
}

kk_std_core__list kk_tmcmc_perturb__trace(kk_std_core__list trace__values, kk_context_t* _ctx) { /* (trace_values : effects-and-types/trace_values) -> effects-and-types/sample effects-and-types/trace_values */ 
  kk_integer_t x_1785;
  kk_integer_t upper__bound_1788;
  kk_std_core__list _x2571 = kk_std_core__list_dup(trace__values); /*effects-and-types/trace_values*/
  upper__bound_1788 = kk_std_core_length_1(_x2571, _ctx); /*int*/
  double x0_1789 = kk_effects_dash_and_dash_types_sample(_ctx); /*double*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x2572 = kk_std_core_hnd_yield_extend(kk_tmcmc_new_perturb__trace_fun2573(upper__bound_1788, _ctx), _ctx); /*2*/
    x_1785 = kk_integer_unbox(_x2572); /*int*/
  }
  else {
    kk_integer_t _x2576;
    double _x2577;
    double _x2578;
    double _x2579;
    kk_integer_t _x2580 = kk_integer_dup(upper__bound_1788); /*int*/
    _x2579 = kk_integer_as_double(_x2580,kk_context()); /*double*/
    _x2578 = (0x1p0 / _x2579); /*double*/
    _x2577 = (x0_1789 / _x2578); /*double*/
    _x2576 = kk_integer_from_double(_x2577,kk_context()); /*int*/
    x_1785 = kk_integer_mod(_x2576,upper__bound_1788,kk_context()); /*int*/
  }
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_1785, _ctx);
    kk_box_t _x2581 = kk_std_core_hnd_yield_extend(kk_tmcmc_new_perturb__trace_fun2582(trace__values, _ctx), _ctx); /*2*/
    return kk_std_core__list_unbox(_x2581, _ctx);
  }
  kk_std_core_types__tuple2_ div__trace = kk_std_core_split(trace__values, x_1785, _ctx); /*(list<double>, list<double>)*/;
  kk_box_t _box_x2078 = div__trace.fst;
  kk_box_t _box_x2079 = div__trace.snd;
  kk_std_core__list l1 = kk_std_core__list_unbox(_box_x2078, NULL);
  kk_std_core__list _pat01 = kk_std_core__list_unbox(_box_x2079, NULL);
  if (kk_std_core__is_Cons(_pat01)) {
    struct kk_std_core_Cons* _con2587 = kk_std_core__as_Cons(_pat01);
    kk_box_t _box_x2080 = _con2587->head;
    kk_std_core__list l2 = _con2587->tail;
    kk_reuse_t _ru_2335 = kk_reuse_null; /*reuse*/;
    kk_std_core__list_dup(l1);
    kk_std_core__list_dup(l2);
    _ru_2335 = kk_reuse_null;
    kk_std_core_types__tuple2__drop(div__trace, _ctx);
    double x1_1794 = kk_effects_dash_and_dash_types_sample(_ctx); /*double*/;
    if (kk_yielding(kk_context())) {
      kk_reuse_drop(_ru_2335, _ctx);
      kk_box_t _x2589 = kk_std_core_hnd_yield_extend(kk_tmcmc_new_perturb__trace_fun2590(l1, l2, _ctx), _ctx); /*2*/
      return kk_std_core__list_unbox(_x2589, _ctx);
    }
    kk_std_core__list ys_1799;
    kk_std_core__list xs0_1800 = kk_std_core__new_Cons(_ru_2335, kk_double_box(x1_1794, _ctx), kk_std_core__new_Nil(_ctx), _ctx); /*list<double>*/;
    ys_1799 = kk_std_core_append(xs0_1800, l2, _ctx); /*list<double>*/
    return kk_std_core_append(l1, ys_1799, _ctx);
  }
  kk_box_t _box_x2087 = div__trace.fst;
  kk_box_t _box_x2088 = div__trace.snd;
  kk_std_core__list l10 = kk_std_core__list_unbox(_box_x2087, NULL);
  kk_std_core__list l20 = kk_std_core__list_unbox(_box_x2088, NULL);
  kk_std_core__list_dup(l10);
  kk_std_core__list_dup(l20);
  kk_std_core_types__tuple2__drop(div__trace, _ctx);
  return kk_std_core__lp__plus__plus__rp_(l10, l20, _ctx);
}
 
// monadic lift

kk_tmcmc__trace kk_tmcmc__mlift1713_mh__step(kk_box_t b, kk_function_t model, kk_std_core__list new__trace, kk_effects_dash_and_dash_types__exp p2, kk_tmcmc__trace trace, bool accept, kk_context_t* _ctx) { /* forall<a,e> (b : a, model : () -> <effects-and-types/sample,effects-and-types/score|e> a, new_trace : effects-and-types/trace_values, p2 : effects-and-types/exp, trace : trace<a,<effects-and-types/sample,effects-and-types/score|e>>, accept : bool) -> <effects-and-types/sample|e> trace<a,<effects-and-types/sample,effects-and-types/score|e>> */ 
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
struct kk_tmcmc__mlift1714_mh__step_fun2601__t {
  struct kk_function_s _base;
};
static kk_box_t kk_tmcmc__mlift1714_mh__step_fun2601(kk_function_t _fself, kk_box_t _b_2098, kk_context_t* _ctx);
static kk_function_t kk_tmcmc__new_mlift1714_mh__step_fun2601(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_tmcmc__mlift1714_mh__step_fun2601, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_tmcmc__mlift1714_mh__step_fun2601(kk_function_t _fself, kk_box_t _b_2098, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x2602;
  kk_effects_dash_and_dash_types__exp _x2603 = kk_effects_dash_and_dash_types__exp_unbox(_b_2098, _ctx); /*effects-and-types/exp*/
  _x2602 = kk_exponents_exp__to__double(_x2603, _ctx); /*double*/
  return kk_double_box(_x2602, _ctx);
}


// lift anonymous function
struct kk_tmcmc__mlift1714_mh__step_fun2609__t {
  struct kk_function_s _base;
};
static kk_box_t kk_tmcmc__mlift1714_mh__step_fun2609(kk_function_t _fself, kk_box_t _b_2101, kk_context_t* _ctx);
static kk_function_t kk_tmcmc__new_mlift1714_mh__step_fun2609(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_tmcmc__mlift1714_mh__step_fun2609, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_tmcmc__mlift1714_mh__step_fun2609(kk_function_t _fself, kk_box_t _b_2101, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x2610;
  kk_effects_dash_and_dash_types__exp _x2611 = kk_effects_dash_and_dash_types__exp_unbox(_b_2101, _ctx); /*effects-and-types/exp*/
  _x2610 = kk_exponents_exp__to__double(_x2611, _ctx); /*double*/
  return kk_double_box(_x2610, _ctx);
}


// lift anonymous function
struct kk_tmcmc__mlift1714_mh__step_fun2617__t {
  struct kk_function_s _base;
  size_t i_1806;
};
static kk_box_t kk_tmcmc__mlift1714_mh__step_fun2617(kk_function_t _fself, kk_function_t _b_2111, kk_box_t _b_2112, kk_context_t* _ctx);
static kk_function_t kk_tmcmc__new_mlift1714_mh__step_fun2617(size_t i_1806, kk_context_t* _ctx) {
  struct kk_tmcmc__mlift1714_mh__step_fun2617__t* _self = kk_function_alloc_as(struct kk_tmcmc__mlift1714_mh__step_fun2617__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc__mlift1714_mh__step_fun2617, kk_context());
  _self->i_1806 = i_1806;
  return &_self->_base;
}

static kk_box_t kk_tmcmc__mlift1714_mh__step_fun2617(kk_function_t _fself, kk_function_t _b_2111, kk_box_t _b_2112, kk_context_t* _ctx) {
  struct kk_tmcmc__mlift1714_mh__step_fun2617__t* _self = kk_function_as(struct kk_tmcmc__mlift1714_mh__step_fun2617__t*, _fself);
  size_t i_1806 = _self->i_1806; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_1806, _b_2111, _b_2112, _ctx);
}


// lift anonymous function
struct kk_tmcmc__mlift1714_mh__step_fun2619__t {
  struct kk_function_s _base;
  kk_box_t b;
  kk_function_t model;
  kk_std_core__list new__trace;
  kk_tmcmc__trace trace;
  kk_effects_dash_and_dash_types__exp p2;
};
static kk_box_t kk_tmcmc__mlift1714_mh__step_fun2619(kk_function_t _fself, kk_box_t _b_2122, kk_context_t* _ctx);
static kk_function_t kk_tmcmc__new_mlift1714_mh__step_fun2619(kk_box_t b, kk_function_t model, kk_std_core__list new__trace, kk_tmcmc__trace trace, kk_effects_dash_and_dash_types__exp p2, kk_context_t* _ctx) {
  struct kk_tmcmc__mlift1714_mh__step_fun2619__t* _self = kk_function_alloc_as(struct kk_tmcmc__mlift1714_mh__step_fun2619__t, 5, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc__mlift1714_mh__step_fun2619, kk_context());
  _self->b = b;
  _self->model = model;
  _self->new__trace = new__trace;
  _self->trace = trace;
  _self->p2 = p2;
  return &_self->_base;
}

static kk_box_t kk_tmcmc__mlift1714_mh__step_fun2619(kk_function_t _fself, kk_box_t _b_2122, kk_context_t* _ctx) {
  struct kk_tmcmc__mlift1714_mh__step_fun2619__t* _self = kk_function_as(struct kk_tmcmc__mlift1714_mh__step_fun2619__t*, _fself);
  kk_box_t b = _self->b; /* 1171 */
  kk_function_t model = _self->model; /* () -> <effects-and-types/sample,effects-and-types/score|1172> 1171 */
  kk_std_core__list new__trace = _self->new__trace; /* effects-and-types/trace_values */
  kk_tmcmc__trace trace = _self->trace; /* tmcmc/trace<1171,<effects-and-types/sample,effects-and-types/score|1172>> */
  kk_effects_dash_and_dash_types__exp p2 = _self->p2; /* effects-and-types/exp */
  kk_drop_match(_self, {kk_box_dup(b);kk_function_dup(model);kk_std_core__list_dup(new__trace);kk_tmcmc__trace_dup(trace);kk_effects_dash_and_dash_types__exp_dup(p2);}, {}, _ctx)
  kk_tmcmc__trace _x2620;
  bool _x2621 = kk_bool_unbox(_b_2122); /*bool*/
  _x2620 = kk_tmcmc__mlift1713_mh__step(b, model, new__trace, p2, trace, _x2621, _ctx); /*tmcmc/trace<1171,<effects-and-types/sample,effects-and-types/score|1172>>*/
  return kk_tmcmc__trace_box(_x2620, _ctx);
}

kk_tmcmc__trace kk_tmcmc__mlift1714_mh__step(kk_function_t model, kk_std_core__list old__trace, kk_effects_dash_and_dash_types__exp p1, kk_tmcmc__trace trace, kk_std_core_types__tuple2_ p2b, kk_context_t* _ctx) { /* forall<a,e> (model : () -> <effects-and-types/sample,effects-and-types/score|e> a, old_trace : effects-and-types/trace_values, p1 : effects-and-types/exp, trace : trace<a,<effects-and-types/sample,effects-and-types/score|e>>, p2b : (effects-and-types/trace_values, (effects-and-types/exp, a))) -> <effects-and-types/sample|e> trace<a,<effects-and-types/sample,effects-and-types/score|e>> */ 
  kk_box_t _box_x2093 = p2b.fst;
  kk_box_t _box_x2094 = p2b.snd;
  kk_std_core__list new__trace = kk_std_core__list_unbox(_box_x2093, NULL);
  kk_std_core_types__tuple2_ _pat3 = kk_std_core_types__tuple2__unbox(_box_x2094, NULL);
  kk_box_t _box_x2095 = _pat3.fst;
  kk_box_t b = _pat3.snd;
  kk_effects_dash_and_dash_types__exp p2 = kk_effects_dash_and_dash_types__exp_unbox(_box_x2095, NULL);
  kk_box_dup(b);
  kk_std_core__list_dup(new__trace);
  kk_std_core_types__tuple2__drop(p2b, _ctx);
  double ratio;
  double y_1803;
  double _x2598;
  double _x2599;
  kk_box_t _x2600 = kk_std_core_hnd__open_none1(kk_tmcmc__new_mlift1714_mh__step_fun2601(_ctx), kk_effects_dash_and_dash_types__exp_box(p2, _ctx), _ctx); /*2*/
  _x2599 = kk_double_unbox(_x2600, _ctx); /*double*/
  double _x2604;
  kk_integer_t _x2605 = kk_std_core_length_1(old__trace, _ctx); /*int*/
  _x2604 = kk_integer_as_double(_x2605,kk_context()); /*double*/
  _x2598 = (_x2599 * _x2604); /*double*/
  double _x2606;
  double _x2607;
  kk_box_t _x2608 = kk_std_core_hnd__open_none1(kk_tmcmc__new_mlift1714_mh__step_fun2609(_ctx), kk_effects_dash_and_dash_types__exp_box(p1, _ctx), _ctx); /*2*/
  _x2607 = kk_double_unbox(_x2608, _ctx); /*double*/
  double _x2612;
  kk_integer_t _x2613;
  kk_std_core__list _x2614 = kk_std_core__list_dup(new__trace); /*effects-and-types/trace_values*/
  _x2613 = kk_std_core_length_1(_x2614, _ctx); /*int*/
  _x2612 = kk_integer_as_double(_x2613,kk_context()); /*double*/
  _x2606 = (_x2607 * _x2612); /*double*/
  y_1803 = (_x2598 / _x2606); /*double*/
  bool _match_2368 = (0x1p0 <= y_1803); /*bool*/;
  if (_match_2368) {
    ratio = 0x1p0; /*double*/
  }
  else {
    ratio = y_1803; /*double*/
  }
  bool x0_1804;
  size_t i_1806;
  kk_std_core_hnd__htag _x2615 = kk_std_core_hnd__htag_dup(kk_effects_dash_and_dash_types__tag_sample); /*std/core/hnd/htag<effects-and-types/.hnd-sample>*/
  i_1806 = kk_std_core_hnd__evv_index(_x2615, _ctx); /*std/core/hnd/ev-index*/
  kk_evv_t w = kk_evv_swap_create1(i_1806,kk_context()); /*std/core/hnd/evv<<effects-and-types/sample|1172>>*/;
  bool y0 = kk_model_dash_resources_bernoulli(ratio, _ctx); /*bool*/;
  kk_unit_t __w_l700_c9 = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x2616 = kk_std_core_hnd_yield_cont(kk_tmcmc__new_mlift1714_mh__step_fun2617(i_1806, _ctx), _ctx); /*3*/
    x0_1804 = kk_bool_unbox(_x2616); /*bool*/
  }
  else {
    x0_1804 = y0; /*bool*/
  }
  if (kk_yielding(kk_context())) {
    kk_box_t _x2618 = kk_std_core_hnd_yield_extend(kk_tmcmc__new_mlift1714_mh__step_fun2619(b, model, new__trace, trace, p2, _ctx), _ctx); /*2*/
    return kk_tmcmc__trace_unbox(_x2618, _ctx);
  }
  return kk_tmcmc__mlift1713_mh__step(b, model, new__trace, p2, trace, x0_1804, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_tmcmc__mlift1715_mh__step_fun2625__t {
  struct kk_function_s _base;
  kk_function_t model;
  kk_std_core__list old__trace;
  kk_tmcmc__trace trace;
  kk_effects_dash_and_dash_types__exp p1;
};
static kk_box_t kk_tmcmc__mlift1715_mh__step_fun2625(kk_function_t _fself, kk_box_t _b_2126, kk_context_t* _ctx);
static kk_function_t kk_tmcmc__new_mlift1715_mh__step_fun2625(kk_function_t model, kk_std_core__list old__trace, kk_tmcmc__trace trace, kk_effects_dash_and_dash_types__exp p1, kk_context_t* _ctx) {
  struct kk_tmcmc__mlift1715_mh__step_fun2625__t* _self = kk_function_alloc_as(struct kk_tmcmc__mlift1715_mh__step_fun2625__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc__mlift1715_mh__step_fun2625, kk_context());
  _self->model = model;
  _self->old__trace = old__trace;
  _self->trace = trace;
  _self->p1 = p1;
  return &_self->_base;
}

static kk_box_t kk_tmcmc__mlift1715_mh__step_fun2625(kk_function_t _fself, kk_box_t _b_2126, kk_context_t* _ctx) {
  struct kk_tmcmc__mlift1715_mh__step_fun2625__t* _self = kk_function_as(struct kk_tmcmc__mlift1715_mh__step_fun2625__t*, _fself);
  kk_function_t model = _self->model; /* () -> <effects-and-types/sample,effects-and-types/score|1172> 1171 */
  kk_std_core__list old__trace = _self->old__trace; /* effects-and-types/trace_values */
  kk_tmcmc__trace trace = _self->trace; /* tmcmc/trace<1171,<effects-and-types/sample,effects-and-types/score|1172>> */
  kk_effects_dash_and_dash_types__exp p1 = _self->p1; /* effects-and-types/exp */
  kk_drop_match(_self, {kk_function_dup(model);kk_std_core__list_dup(old__trace);kk_tmcmc__trace_dup(trace);kk_effects_dash_and_dash_types__exp_dup(p1);}, {}, _ctx)
  kk_tmcmc__trace _x2626;
  kk_std_core_types__tuple2_ _x2627 = kk_std_core_types__tuple2__unbox(_b_2126, _ctx); /*(effects-and-types/trace_values, (effects-and-types/exp, 1171))*/
  _x2626 = kk_tmcmc__mlift1714_mh__step(model, old__trace, p1, trace, _x2627, _ctx); /*tmcmc/trace<1171,<effects-and-types/sample,effects-and-types/score|1172>>*/
  return kk_tmcmc__trace_box(_x2626, _ctx);
}

kk_tmcmc__trace kk_tmcmc__mlift1715_mh__step(kk_tmcmc__trace trace, kk_std_core__list modified__trace, kk_context_t* _ctx) { /* forall<a,e> (trace : trace<a,<effects-and-types/sample,effects-and-types/score|e>>, modified_trace : effects-and-types/trace_values) -> <effects-and-types/sample|e> trace<a,<effects-and-types/sample,effects-and-types/score|e>> */ 
  struct kk_tmcmc_Trace* _con2622 = kk_tmcmc__as_Trace(trace);
  kk_function_t model = _con2622->m;
  kk_effects_dash_and_dash_types__exp p1 = _con2622->p;
  kk_std_core__list old__trace = _con2622->l;
  kk_function_dup(model);
  kk_std_core__list_dup(old__trace);
  kk_std_core_types__tuple2_ x_1809;
  kk_function_t _x2623 = kk_function_dup(model); /*() -> <effects-and-types/sample,effects-and-types/score|1172> 1171*/
  x_1809 = kk_tmcmc_with__randomness(_x2623, modified__trace, _ctx); /*(effects-and-types/trace_values, (effects-and-types/exp, 1171))*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__tuple2__drop(x_1809, _ctx);
    kk_box_t _x2624 = kk_std_core_hnd_yield_extend(kk_tmcmc__new_mlift1715_mh__step_fun2625(model, old__trace, trace, p1, _ctx), _ctx); /*2*/
    return kk_tmcmc__trace_unbox(_x2624, _ctx);
  }
  return kk_tmcmc__mlift1714_mh__step(model, old__trace, p1, trace, x_1809, _ctx);
}


// lift anonymous function
struct kk_tmcmc_mh__step_fun2631__t {
  struct kk_function_s _base;
  size_t i_1816;
};
static kk_box_t kk_tmcmc_mh__step_fun2631(kk_function_t _fself, kk_function_t _b_2134, kk_box_t _b_2135, kk_context_t* _ctx);
static kk_function_t kk_tmcmc_new_mh__step_fun2631(size_t i_1816, kk_context_t* _ctx) {
  struct kk_tmcmc_mh__step_fun2631__t* _self = kk_function_alloc_as(struct kk_tmcmc_mh__step_fun2631__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc_mh__step_fun2631, kk_context());
  _self->i_1816 = i_1816;
  return &_self->_base;
}

static kk_box_t kk_tmcmc_mh__step_fun2631(kk_function_t _fself, kk_function_t _b_2134, kk_box_t _b_2135, kk_context_t* _ctx) {
  struct kk_tmcmc_mh__step_fun2631__t* _self = kk_function_as(struct kk_tmcmc_mh__step_fun2631__t*, _fself);
  size_t i_1816 = _self->i_1816; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_1816, _b_2134, _b_2135, _ctx);
}


// lift anonymous function
struct kk_tmcmc_mh__step_fun2633__t {
  struct kk_function_s _base;
  kk_tmcmc__trace trace;
};
static kk_box_t kk_tmcmc_mh__step_fun2633(kk_function_t _fself, kk_box_t _b_2145, kk_context_t* _ctx);
static kk_function_t kk_tmcmc_new_mh__step_fun2633(kk_tmcmc__trace trace, kk_context_t* _ctx) {
  struct kk_tmcmc_mh__step_fun2633__t* _self = kk_function_alloc_as(struct kk_tmcmc_mh__step_fun2633__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc_mh__step_fun2633, kk_context());
  _self->trace = trace;
  return &_self->_base;
}

static kk_box_t kk_tmcmc_mh__step_fun2633(kk_function_t _fself, kk_box_t _b_2145, kk_context_t* _ctx) {
  struct kk_tmcmc_mh__step_fun2633__t* _self = kk_function_as(struct kk_tmcmc_mh__step_fun2633__t*, _fself);
  kk_tmcmc__trace trace = _self->trace; /* tmcmc/trace<1171,<effects-and-types/sample,effects-and-types/score|1172>> */
  kk_drop_match(_self, {kk_tmcmc__trace_dup(trace);}, {}, _ctx)
  kk_tmcmc__trace _x2634;
  kk_std_core__list _x2635 = kk_std_core__list_unbox(_b_2145, _ctx); /*effects-and-types/trace_values*/
  _x2634 = kk_tmcmc__mlift1715_mh__step(trace, _x2635, _ctx); /*tmcmc/trace<1171,<effects-and-types/sample,effects-and-types/score|1172>>*/
  return kk_tmcmc__trace_box(_x2634, _ctx);
}


// lift anonymous function
struct kk_tmcmc_mh__step_fun2640__t {
  struct kk_function_s _base;
  kk_function_t model;
  kk_std_core__list old__trace;
  kk_tmcmc__trace trace;
  kk_effects_dash_and_dash_types__exp p1;
};
static kk_box_t kk_tmcmc_mh__step_fun2640(kk_function_t _fself, kk_box_t _b_2147, kk_context_t* _ctx);
static kk_function_t kk_tmcmc_new_mh__step_fun2640(kk_function_t model, kk_std_core__list old__trace, kk_tmcmc__trace trace, kk_effects_dash_and_dash_types__exp p1, kk_context_t* _ctx) {
  struct kk_tmcmc_mh__step_fun2640__t* _self = kk_function_alloc_as(struct kk_tmcmc_mh__step_fun2640__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc_mh__step_fun2640, kk_context());
  _self->model = model;
  _self->old__trace = old__trace;
  _self->trace = trace;
  _self->p1 = p1;
  return &_self->_base;
}

static kk_box_t kk_tmcmc_mh__step_fun2640(kk_function_t _fself, kk_box_t _b_2147, kk_context_t* _ctx) {
  struct kk_tmcmc_mh__step_fun2640__t* _self = kk_function_as(struct kk_tmcmc_mh__step_fun2640__t*, _fself);
  kk_function_t model = _self->model; /* () -> <effects-and-types/sample,effects-and-types/score|1172> 1171 */
  kk_std_core__list old__trace = _self->old__trace; /* effects-and-types/trace_values */
  kk_tmcmc__trace trace = _self->trace; /* tmcmc/trace<1171,<effects-and-types/sample,effects-and-types/score|1172>> */
  kk_effects_dash_and_dash_types__exp p1 = _self->p1; /* effects-and-types/exp */
  kk_drop_match(_self, {kk_function_dup(model);kk_std_core__list_dup(old__trace);kk_tmcmc__trace_dup(trace);kk_effects_dash_and_dash_types__exp_dup(p1);}, {}, _ctx)
  kk_tmcmc__trace _x2641;
  kk_std_core_types__tuple2_ _x2642 = kk_std_core_types__tuple2__unbox(_b_2147, _ctx); /*(effects-and-types/trace_values, (effects-and-types/exp, 1171))*/
  _x2641 = kk_tmcmc__mlift1714_mh__step(model, old__trace, p1, trace, _x2642, _ctx); /*tmcmc/trace<1171,<effects-and-types/sample,effects-and-types/score|1172>>*/
  return kk_tmcmc__trace_box(_x2641, _ctx);
}


// lift anonymous function
struct kk_tmcmc_mh__step_fun2649__t {
  struct kk_function_s _base;
};
static kk_box_t kk_tmcmc_mh__step_fun2649(kk_function_t _fself, kk_box_t _b_2153, kk_context_t* _ctx);
static kk_function_t kk_tmcmc_new_mh__step_fun2649(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_tmcmc_mh__step_fun2649, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_tmcmc_mh__step_fun2649(kk_function_t _fself, kk_box_t _b_2153, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x2650;
  kk_effects_dash_and_dash_types__exp _x2651 = kk_effects_dash_and_dash_types__exp_unbox(_b_2153, _ctx); /*effects-and-types/exp*/
  _x2650 = kk_exponents_exp__to__double(_x2651, _ctx); /*double*/
  return kk_double_box(_x2650, _ctx);
}


// lift anonymous function
struct kk_tmcmc_mh__step_fun2657__t {
  struct kk_function_s _base;
};
static kk_box_t kk_tmcmc_mh__step_fun2657(kk_function_t _fself, kk_box_t _b_2156, kk_context_t* _ctx);
static kk_function_t kk_tmcmc_new_mh__step_fun2657(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_tmcmc_mh__step_fun2657, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_tmcmc_mh__step_fun2657(kk_function_t _fself, kk_box_t _b_2156, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x2658;
  kk_effects_dash_and_dash_types__exp _x2659 = kk_effects_dash_and_dash_types__exp_unbox(_b_2156, _ctx); /*effects-and-types/exp*/
  _x2658 = kk_exponents_exp__to__double(_x2659, _ctx); /*double*/
  return kk_double_box(_x2658, _ctx);
}


// lift anonymous function
struct kk_tmcmc_mh__step_fun2665__t {
  struct kk_function_s _base;
  size_t i0_1829;
};
static kk_box_t kk_tmcmc_mh__step_fun2665(kk_function_t _fself, kk_function_t _b_2166, kk_box_t _b_2167, kk_context_t* _ctx);
static kk_function_t kk_tmcmc_new_mh__step_fun2665(size_t i0_1829, kk_context_t* _ctx) {
  struct kk_tmcmc_mh__step_fun2665__t* _self = kk_function_alloc_as(struct kk_tmcmc_mh__step_fun2665__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc_mh__step_fun2665, kk_context());
  _self->i0_1829 = i0_1829;
  return &_self->_base;
}

static kk_box_t kk_tmcmc_mh__step_fun2665(kk_function_t _fself, kk_function_t _b_2166, kk_box_t _b_2167, kk_context_t* _ctx) {
  struct kk_tmcmc_mh__step_fun2665__t* _self = kk_function_as(struct kk_tmcmc_mh__step_fun2665__t*, _fself);
  size_t i0_1829 = _self->i0_1829; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i0_1829, _b_2166, _b_2167, _ctx);
}


// lift anonymous function
struct kk_tmcmc_mh__step_fun2667__t {
  struct kk_function_s _base;
  kk_box_t b;
  kk_function_t model;
  kk_std_core__list new__trace;
  kk_tmcmc__trace trace;
  kk_effects_dash_and_dash_types__exp p2;
};
static kk_box_t kk_tmcmc_mh__step_fun2667(kk_function_t _fself, kk_box_t _b_2177, kk_context_t* _ctx);
static kk_function_t kk_tmcmc_new_mh__step_fun2667(kk_box_t b, kk_function_t model, kk_std_core__list new__trace, kk_tmcmc__trace trace, kk_effects_dash_and_dash_types__exp p2, kk_context_t* _ctx) {
  struct kk_tmcmc_mh__step_fun2667__t* _self = kk_function_alloc_as(struct kk_tmcmc_mh__step_fun2667__t, 5, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc_mh__step_fun2667, kk_context());
  _self->b = b;
  _self->model = model;
  _self->new__trace = new__trace;
  _self->trace = trace;
  _self->p2 = p2;
  return &_self->_base;
}

static kk_box_t kk_tmcmc_mh__step_fun2667(kk_function_t _fself, kk_box_t _b_2177, kk_context_t* _ctx) {
  struct kk_tmcmc_mh__step_fun2667__t* _self = kk_function_as(struct kk_tmcmc_mh__step_fun2667__t*, _fself);
  kk_box_t b = _self->b; /* 1171 */
  kk_function_t model = _self->model; /* () -> <effects-and-types/sample,effects-and-types/score|1172> 1171 */
  kk_std_core__list new__trace = _self->new__trace; /* effects-and-types/trace_values */
  kk_tmcmc__trace trace = _self->trace; /* tmcmc/trace<1171,<effects-and-types/sample,effects-and-types/score|1172>> */
  kk_effects_dash_and_dash_types__exp p2 = _self->p2; /* effects-and-types/exp */
  kk_drop_match(_self, {kk_box_dup(b);kk_function_dup(model);kk_std_core__list_dup(new__trace);kk_tmcmc__trace_dup(trace);kk_effects_dash_and_dash_types__exp_dup(p2);}, {}, _ctx)
  kk_tmcmc__trace _x2668;
  bool _x2669 = kk_bool_unbox(_b_2177); /*bool*/
  _x2668 = kk_tmcmc__mlift1713_mh__step(b, model, new__trace, p2, trace, _x2669, _ctx); /*tmcmc/trace<1171,<effects-and-types/sample,effects-and-types/score|1172>>*/
  return kk_tmcmc__trace_box(_x2668, _ctx);
}

kk_tmcmc__trace kk_tmcmc_mh__step(kk_tmcmc__trace trace, kk_context_t* _ctx) { /* forall<a,e> (trace : trace<a,<effects-and-types/sample,effects-and-types/score|e>>) -> <effects-and-types/sample|e> trace<a,<effects-and-types/sample,effects-and-types/score|e>> */ 
  kk_std_core__list x_1811;
  kk_std_core__list _x1;
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*std/core/hnd/evv<(<>)>*/;
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  struct kk_tmcmc_Trace* _con2628 = kk_tmcmc__as_Trace(trace);
  kk_effects_dash_and_dash_types__exp _pat1 = _con2628->p;
  kk_std_core__list _x = _con2628->l;
  kk_std_core__list_dup(_x);
  _x1 = _x; /*effects-and-types/trace_values*/
  size_t i_1816;
  kk_std_core_hnd__htag _x2629 = kk_std_core_hnd__htag_dup(kk_effects_dash_and_dash_types__tag_sample); /*std/core/hnd/htag<effects-and-types/.hnd-sample>*/
  i_1816 = kk_std_core_hnd__evv_index(_x2629, _ctx); /*std/core/hnd/ev-index*/
  kk_evv_t w0 = kk_evv_swap_create1(i_1816,kk_context()); /*std/core/hnd/evv<<effects-and-types/sample|1172>>*/;
  kk_std_core__list y = kk_tmcmc_perturb__trace(_x1, _ctx); /*effects-and-types/trace_values*/;
  kk_unit_t __w_l700_c9 = kk_Unit;
  kk_evv_set(w0,kk_context());
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(y, _ctx);
    kk_box_t _x2630 = kk_std_core_hnd_yield_cont(kk_tmcmc_new_mh__step_fun2631(i_1816, _ctx), _ctx); /*3*/
    x_1811 = kk_std_core__list_unbox(_x2630, _ctx); /*effects-and-types/trace_values*/
  }
  else {
    x_1811 = y; /*effects-and-types/trace_values*/
  }
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_1811, _ctx);
    kk_box_t _x2632 = kk_std_core_hnd_yield_extend(kk_tmcmc_new_mh__step_fun2633(trace, _ctx), _ctx); /*2*/
    return kk_tmcmc__trace_unbox(_x2632, _ctx);
  }
  struct kk_tmcmc_Trace* _con2636 = kk_tmcmc__as_Trace(trace);
  kk_function_t model = _con2636->m;
  kk_effects_dash_and_dash_types__exp p1 = _con2636->p;
  kk_std_core__list old__trace = _con2636->l;
  kk_function_dup(model);
  kk_std_core__list_dup(old__trace);
  kk_reuse_t _ru_2338;
  kk_tmcmc__trace _x2637 = kk_tmcmc__trace_dup(trace); /*tmcmc/trace<1171,<effects-and-types/sample,effects-and-types/score|1172>>*/
  _ru_2338 = kk_tmcmc__trace_dropn_reuse(_x2637, ((int32_t)3), _ctx); /*reuse*/
  kk_std_core_types__tuple2_ x3_1820;
  kk_function_t _x2638 = kk_function_dup(model); /*() -> <effects-and-types/sample,effects-and-types/score|1172> 1171*/
  x3_1820 = kk_tmcmc_with__randomness(_x2638, x_1811, _ctx); /*(effects-and-types/trace_values, (effects-and-types/exp, 1171))*/
  if (kk_yielding(kk_context())) {
    kk_reuse_drop(_ru_2338, _ctx);
    kk_std_core_types__tuple2__drop(x3_1820, _ctx);
    kk_box_t _x2639 = kk_std_core_hnd_yield_extend(kk_tmcmc_new_mh__step_fun2640(model, old__trace, trace, p1, _ctx), _ctx); /*2*/
    return kk_tmcmc__trace_unbox(_x2639, _ctx);
  }
  kk_box_t _box_x2148 = x3_1820.fst;
  kk_box_t _box_x2149 = x3_1820.snd;
  kk_std_core__list new__trace = kk_std_core__list_unbox(_box_x2148, NULL);
  kk_std_core_types__tuple2_ _pat300 = kk_std_core_types__tuple2__unbox(_box_x2149, NULL);
  kk_box_t _box_x2150 = _pat300.fst;
  kk_box_t b = _pat300.snd;
  kk_effects_dash_and_dash_types__exp p2 = kk_effects_dash_and_dash_types__exp_unbox(_box_x2150, NULL);
  kk_box_dup(b);
  kk_std_core__list_dup(new__trace);
  kk_std_core_types__tuple2__drop(x3_1820, _ctx);
  double ratio;
  double y0_1825;
  double _x2646;
  double _x2647;
  kk_box_t _x2648 = kk_std_core_hnd__open_none1(kk_tmcmc_new_mh__step_fun2649(_ctx), kk_effects_dash_and_dash_types__exp_box(p2, _ctx), _ctx); /*2*/
  _x2647 = kk_double_unbox(_x2648, _ctx); /*double*/
  double _x2652;
  kk_integer_t _x2653 = kk_std_core_length_1(old__trace, _ctx); /*int*/
  _x2652 = kk_integer_as_double(_x2653,kk_context()); /*double*/
  _x2646 = (_x2647 * _x2652); /*double*/
  double _x2654;
  double _x2655;
  kk_box_t _x2656 = kk_std_core_hnd__open_none1(kk_tmcmc_new_mh__step_fun2657(_ctx), kk_effects_dash_and_dash_types__exp_box(p1, _ctx), _ctx); /*2*/
  _x2655 = kk_double_unbox(_x2656, _ctx); /*double*/
  double _x2660;
  kk_integer_t _x2661;
  kk_std_core__list _x2662 = kk_std_core__list_dup(new__trace); /*effects-and-types/trace_values*/
  _x2661 = kk_std_core_length_1(_x2662, _ctx); /*int*/
  _x2660 = kk_integer_as_double(_x2661,kk_context()); /*double*/
  _x2654 = (_x2655 * _x2660); /*double*/
  y0_1825 = (_x2646 / _x2654); /*double*/
  bool _match_2363 = (0x1p0 <= y0_1825); /*bool*/;
  if (_match_2363) {
    ratio = 0x1p0; /*double*/
  }
  else {
    ratio = y0_1825; /*double*/
  }
  bool x5_1826;
  size_t i0_1829;
  kk_std_core_hnd__htag _x2663 = kk_std_core_hnd__htag_dup(kk_effects_dash_and_dash_types__tag_sample); /*std/core/hnd/htag<effects-and-types/.hnd-sample>*/
  i0_1829 = kk_std_core_hnd__evv_index(_x2663, _ctx); /*std/core/hnd/ev-index*/
  kk_evv_t w1 = kk_evv_swap_create1(i0_1829,kk_context()); /*std/core/hnd/evv<<effects-and-types/sample|1172>>*/;
  bool y1 = kk_model_dash_resources_bernoulli(ratio, _ctx); /*bool*/;
  kk_unit_t __w_l700_c90 = kk_Unit;
  kk_evv_set(w1,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x2664 = kk_std_core_hnd_yield_cont(kk_tmcmc_new_mh__step_fun2665(i0_1829, _ctx), _ctx); /*3*/
    x5_1826 = kk_bool_unbox(_x2664); /*bool*/
  }
  else {
    x5_1826 = y1; /*bool*/
  }
  if (kk_yielding(kk_context())) {
    kk_reuse_drop(_ru_2338, _ctx);
    kk_box_t _x2666 = kk_std_core_hnd_yield_extend(kk_tmcmc_new_mh__step_fun2667(b, model, new__trace, trace, p2, _ctx), _ctx); /*2*/
    return kk_tmcmc__trace_unbox(_x2666, _ctx);
  }
  if (x5_1826) {
    kk_tmcmc__trace_dropn(trace, ((int32_t)3), _ctx);
    return kk_tmcmc__new_Trace(_ru_2338, model, p2, new__trace, b, _ctx);
  }
  kk_reuse_drop(_ru_2338, _ctx);
  kk_box_drop(b, _ctx);
  kk_function_drop(model, _ctx);
  kk_std_core__list_drop(new__trace, _ctx);
  return trace;
}
 
// monadic lift

kk_tmcmc__trace__rmsmc kk_tmcmc__mlift1716_mh__step__rmsmc(kk_function_t model, kk_std_core__list new__trace, kk_effects_dash_and_dash_types__exp p2, kk_tmcmc__trace__rmsmc trace, bool accept, kk_context_t* _ctx) { /* forall<a,e> (model : () -> ((int) -> <exn,effects-and-types/sample,effects-and-types/sample,effects-and-types/score,effects-and-types/yield|e> a), new_trace : effects-and-types/trace_values, p2 : effects-and-types/exp, trace : trace_rmsmc<a,<effects-and-types/sample,effects-and-types/sample,effects-and-types/score,effects-and-types/yield,exn|e>>, accept : bool) -> <effects-and-types/sample,exn,effects-and-types/sample,effects-and-types/yield|e> trace_rmsmc<a,<exn,effects-and-types/sample,effects-and-types/sample,effects-and-types/score,effects-and-types/yield|e>> */ 
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
struct kk_tmcmc__mlift1717_mh__step__rmsmc_fun2676__t {
  struct kk_function_s _base;
};
static kk_box_t kk_tmcmc__mlift1717_mh__step__rmsmc_fun2676(kk_function_t _fself, kk_box_t _b_2189, kk_context_t* _ctx);
static kk_function_t kk_tmcmc__new_mlift1717_mh__step__rmsmc_fun2676(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_tmcmc__mlift1717_mh__step__rmsmc_fun2676, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_tmcmc__mlift1717_mh__step__rmsmc_fun2676(kk_function_t _fself, kk_box_t _b_2189, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x2677;
  kk_effects_dash_and_dash_types__exp _x2678 = kk_effects_dash_and_dash_types__exp_unbox(_b_2189, _ctx); /*effects-and-types/exp*/
  _x2677 = kk_exponents_exp__to__double(_x2678, _ctx); /*double*/
  return kk_double_box(_x2677, _ctx);
}


// lift anonymous function
struct kk_tmcmc__mlift1717_mh__step__rmsmc_fun2684__t {
  struct kk_function_s _base;
};
static kk_box_t kk_tmcmc__mlift1717_mh__step__rmsmc_fun2684(kk_function_t _fself, kk_box_t _b_2192, kk_context_t* _ctx);
static kk_function_t kk_tmcmc__new_mlift1717_mh__step__rmsmc_fun2684(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_tmcmc__mlift1717_mh__step__rmsmc_fun2684, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_tmcmc__mlift1717_mh__step__rmsmc_fun2684(kk_function_t _fself, kk_box_t _b_2192, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x2685;
  kk_effects_dash_and_dash_types__exp _x2686 = kk_effects_dash_and_dash_types__exp_unbox(_b_2192, _ctx); /*effects-and-types/exp*/
  _x2685 = kk_exponents_exp__to__double(_x2686, _ctx); /*double*/
  return kk_double_box(_x2685, _ctx);
}


// lift anonymous function
struct kk_tmcmc__mlift1717_mh__step__rmsmc_fun2692__t {
  struct kk_function_s _base;
  size_t i_1837;
};
static kk_box_t kk_tmcmc__mlift1717_mh__step__rmsmc_fun2692(kk_function_t _fself, kk_function_t _b_2202, kk_box_t _b_2203, kk_context_t* _ctx);
static kk_function_t kk_tmcmc__new_mlift1717_mh__step__rmsmc_fun2692(size_t i_1837, kk_context_t* _ctx) {
  struct kk_tmcmc__mlift1717_mh__step__rmsmc_fun2692__t* _self = kk_function_alloc_as(struct kk_tmcmc__mlift1717_mh__step__rmsmc_fun2692__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc__mlift1717_mh__step__rmsmc_fun2692, kk_context());
  _self->i_1837 = i_1837;
  return &_self->_base;
}

static kk_box_t kk_tmcmc__mlift1717_mh__step__rmsmc_fun2692(kk_function_t _fself, kk_function_t _b_2202, kk_box_t _b_2203, kk_context_t* _ctx) {
  struct kk_tmcmc__mlift1717_mh__step__rmsmc_fun2692__t* _self = kk_function_as(struct kk_tmcmc__mlift1717_mh__step__rmsmc_fun2692__t*, _fself);
  size_t i_1837 = _self->i_1837; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_1837, _b_2202, _b_2203, _ctx);
}


// lift anonymous function
struct kk_tmcmc__mlift1717_mh__step__rmsmc_fun2694__t {
  struct kk_function_s _base;
  kk_function_t model;
  kk_std_core__list new__trace;
  kk_tmcmc__trace__rmsmc trace;
  kk_effects_dash_and_dash_types__exp p2;
};
static kk_box_t kk_tmcmc__mlift1717_mh__step__rmsmc_fun2694(kk_function_t _fself, kk_box_t _b_2213, kk_context_t* _ctx);
static kk_function_t kk_tmcmc__new_mlift1717_mh__step__rmsmc_fun2694(kk_function_t model, kk_std_core__list new__trace, kk_tmcmc__trace__rmsmc trace, kk_effects_dash_and_dash_types__exp p2, kk_context_t* _ctx) {
  struct kk_tmcmc__mlift1717_mh__step__rmsmc_fun2694__t* _self = kk_function_alloc_as(struct kk_tmcmc__mlift1717_mh__step__rmsmc_fun2694__t, 5, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc__mlift1717_mh__step__rmsmc_fun2694, kk_context());
  _self->model = model;
  _self->new__trace = new__trace;
  _self->trace = trace;
  _self->p2 = p2;
  return &_self->_base;
}

static kk_box_t kk_tmcmc__mlift1717_mh__step__rmsmc_fun2694(kk_function_t _fself, kk_box_t _b_2213, kk_context_t* _ctx) {
  struct kk_tmcmc__mlift1717_mh__step__rmsmc_fun2694__t* _self = kk_function_as(struct kk_tmcmc__mlift1717_mh__step__rmsmc_fun2694__t*, _fself);
  kk_function_t model = _self->model; /* () -> ((int) -> <exn,effects-and-types/sample,effects-and-types/sample,effects-and-types/score,effects-and-types/yield|1405> 1404) */
  kk_std_core__list new__trace = _self->new__trace; /* effects-and-types/trace_values */
  kk_tmcmc__trace__rmsmc trace = _self->trace; /* tmcmc/trace_rmsmc<1404,<effects-and-types/sample,effects-and-types/sample,effects-and-types/score,effects-and-types/yield,exn|1405>> */
  kk_effects_dash_and_dash_types__exp p2 = _self->p2; /* effects-and-types/exp */
  kk_drop_match(_self, {kk_function_dup(model);kk_std_core__list_dup(new__trace);kk_tmcmc__trace__rmsmc_dup(trace);kk_effects_dash_and_dash_types__exp_dup(p2);}, {}, _ctx)
  kk_tmcmc__trace__rmsmc _x2695;
  bool _x2696 = kk_bool_unbox(_b_2213); /*bool*/
  _x2695 = kk_tmcmc__mlift1716_mh__step__rmsmc(model, new__trace, p2, trace, _x2696, _ctx); /*tmcmc/trace_rmsmc<1404,<exn,effects-and-types/sample,effects-and-types/sample,effects-and-types/score,effects-and-types/yield|1405>>*/
  return kk_tmcmc__trace__rmsmc_box(_x2695, _ctx);
}

kk_tmcmc__trace__rmsmc kk_tmcmc__mlift1717_mh__step__rmsmc(kk_function_t model, kk_std_core__list old__trace, kk_effects_dash_and_dash_types__exp p1, kk_tmcmc__trace__rmsmc trace, kk_std_core_types__tuple2_ p2b, kk_context_t* _ctx) { /* forall<a,e> (model : () -> ((int) -> <exn,effects-and-types/sample,effects-and-types/sample,effects-and-types/score,effects-and-types/yield|e> a), old_trace : effects-and-types/trace_values, p1 : effects-and-types/exp, trace : trace_rmsmc<a,<effects-and-types/sample,effects-and-types/sample,effects-and-types/score,effects-and-types/yield,exn|e>>, p2b : (effects-and-types/trace_values, (effects-and-types/exp, a))) -> <effects-and-types/sample,effects-and-types/sample,exn,effects-and-types/yield|e> trace_rmsmc<a,<exn,effects-and-types/sample,effects-and-types/sample,effects-and-types/score,effects-and-types/yield|e>> */ 
  kk_box_t _box_x2184 = p2b.fst;
  kk_box_t _box_x2185 = p2b.snd;
  kk_std_core__list new__trace = kk_std_core__list_unbox(_box_x2184, NULL);
  kk_std_core_types__tuple2_ _pat2 = kk_std_core_types__tuple2__unbox(_box_x2185, NULL);
  kk_box_t _box_x2186 = _pat2.fst;
  kk_effects_dash_and_dash_types__exp p2 = kk_effects_dash_and_dash_types__exp_unbox(_box_x2186, NULL);
  kk_std_core__list_dup(new__trace);
  kk_std_core_types__tuple2__drop(p2b, _ctx);
  double ratio;
  double y_1834;
  double _x2673;
  double _x2674;
  kk_box_t _x2675 = kk_std_core_hnd__open_none1(kk_tmcmc__new_mlift1717_mh__step__rmsmc_fun2676(_ctx), kk_effects_dash_and_dash_types__exp_box(p2, _ctx), _ctx); /*2*/
  _x2674 = kk_double_unbox(_x2675, _ctx); /*double*/
  double _x2679;
  kk_integer_t _x2680 = kk_std_core_length_1(old__trace, _ctx); /*int*/
  _x2679 = kk_integer_as_double(_x2680,kk_context()); /*double*/
  _x2673 = (_x2674 * _x2679); /*double*/
  double _x2681;
  double _x2682;
  kk_box_t _x2683 = kk_std_core_hnd__open_none1(kk_tmcmc__new_mlift1717_mh__step__rmsmc_fun2684(_ctx), kk_effects_dash_and_dash_types__exp_box(p1, _ctx), _ctx); /*2*/
  _x2682 = kk_double_unbox(_x2683, _ctx); /*double*/
  double _x2687;
  kk_integer_t _x2688;
  kk_std_core__list _x2689 = kk_std_core__list_dup(new__trace); /*effects-and-types/trace_values*/
  _x2688 = kk_std_core_length_1(_x2689, _ctx); /*int*/
  _x2687 = kk_integer_as_double(_x2688,kk_context()); /*double*/
  _x2681 = (_x2682 * _x2687); /*double*/
  y_1834 = (_x2673 / _x2681); /*double*/
  bool _match_2358 = (0x1p0 <= y_1834); /*bool*/;
  if (_match_2358) {
    ratio = 0x1p0; /*double*/
  }
  else {
    ratio = y_1834; /*double*/
  }
  bool x0_1835;
  size_t i_1837;
  kk_std_core_hnd__htag _x2690 = kk_std_core_hnd__htag_dup(kk_effects_dash_and_dash_types__tag_sample); /*std/core/hnd/htag<effects-and-types/.hnd-sample>*/
  i_1837 = kk_std_core_hnd__evv_index(_x2690, _ctx); /*std/core/hnd/ev-index*/
  kk_evv_t w = kk_evv_swap_create1(i_1837,kk_context()); /*std/core/hnd/evv<<effects-and-types/sample,exn,effects-and-types/sample,effects-and-types/yield|1405>>*/;
  bool y0 = kk_model_dash_resources_bernoulli(ratio, _ctx); /*bool*/;
  kk_unit_t __w_l700_c9 = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x2691 = kk_std_core_hnd_yield_cont(kk_tmcmc__new_mlift1717_mh__step__rmsmc_fun2692(i_1837, _ctx), _ctx); /*3*/
    x0_1835 = kk_bool_unbox(_x2691); /*bool*/
  }
  else {
    x0_1835 = y0; /*bool*/
  }
  if (kk_yielding(kk_context())) {
    kk_box_t _x2693 = kk_std_core_hnd_yield_extend(kk_tmcmc__new_mlift1717_mh__step__rmsmc_fun2694(model, new__trace, trace, p2, _ctx), _ctx); /*2*/
    return kk_tmcmc__trace__rmsmc_unbox(_x2693, _ctx);
  }
  return kk_tmcmc__mlift1716_mh__step__rmsmc(model, new__trace, p2, trace, x0_1835, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_tmcmc__mlift1718_mh__step__rmsmc_fun2699__t {
  struct kk_function_s _base;
  kk_function_t model;
  kk_std_core__list old__trace;
  kk_tmcmc__trace__rmsmc trace;
  kk_effects_dash_and_dash_types__exp p1;
};
static kk_box_t kk_tmcmc__mlift1718_mh__step__rmsmc_fun2699(kk_function_t _fself, kk_box_t _b_2217, kk_context_t* _ctx);
static kk_function_t kk_tmcmc__new_mlift1718_mh__step__rmsmc_fun2699(kk_function_t model, kk_std_core__list old__trace, kk_tmcmc__trace__rmsmc trace, kk_effects_dash_and_dash_types__exp p1, kk_context_t* _ctx) {
  struct kk_tmcmc__mlift1718_mh__step__rmsmc_fun2699__t* _self = kk_function_alloc_as(struct kk_tmcmc__mlift1718_mh__step__rmsmc_fun2699__t, 5, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc__mlift1718_mh__step__rmsmc_fun2699, kk_context());
  _self->model = model;
  _self->old__trace = old__trace;
  _self->trace = trace;
  _self->p1 = p1;
  return &_self->_base;
}

static kk_box_t kk_tmcmc__mlift1718_mh__step__rmsmc_fun2699(kk_function_t _fself, kk_box_t _b_2217, kk_context_t* _ctx) {
  struct kk_tmcmc__mlift1718_mh__step__rmsmc_fun2699__t* _self = kk_function_as(struct kk_tmcmc__mlift1718_mh__step__rmsmc_fun2699__t*, _fself);
  kk_function_t model = _self->model; /* () -> ((int) -> <exn,effects-and-types/sample,effects-and-types/sample,effects-and-types/score,effects-and-types/yield|1405> 1404) */
  kk_std_core__list old__trace = _self->old__trace; /* effects-and-types/trace_values */
  kk_tmcmc__trace__rmsmc trace = _self->trace; /* tmcmc/trace_rmsmc<1404,<effects-and-types/sample,effects-and-types/sample,effects-and-types/score,effects-and-types/yield,exn|1405>> */
  kk_effects_dash_and_dash_types__exp p1 = _self->p1; /* effects-and-types/exp */
  kk_drop_match(_self, {kk_function_dup(model);kk_std_core__list_dup(old__trace);kk_tmcmc__trace__rmsmc_dup(trace);kk_effects_dash_and_dash_types__exp_dup(p1);}, {}, _ctx)
  kk_tmcmc__trace__rmsmc _x2700;
  kk_std_core_types__tuple2_ _x2701 = kk_std_core_types__tuple2__unbox(_b_2217, _ctx); /*(effects-and-types/trace_values, (effects-and-types/exp, 1404))*/
  _x2700 = kk_tmcmc__mlift1717_mh__step__rmsmc(model, old__trace, p1, trace, _x2701, _ctx); /*tmcmc/trace_rmsmc<1404,<exn,effects-and-types/sample,effects-and-types/sample,effects-and-types/score,effects-and-types/yield|1405>>*/
  return kk_tmcmc__trace__rmsmc_box(_x2700, _ctx);
}

kk_tmcmc__trace__rmsmc kk_tmcmc__mlift1718_mh__step__rmsmc(kk_tmcmc__trace__rmsmc trace, kk_std_core__list modified__trace, kk_context_t* _ctx) { /* forall<a,e> (trace : trace_rmsmc<a,<effects-and-types/sample,effects-and-types/sample,effects-and-types/score,effects-and-types/yield,exn|e>>, modified_trace : effects-and-types/trace_values) -> <effects-and-types/sample,exn,effects-and-types/sample,effects-and-types/yield|e> trace_rmsmc<a,<exn,effects-and-types/sample,effects-and-types/sample,effects-and-types/score,effects-and-types/yield|e>> */ 
  kk_function_t model = trace.m;
  kk_effects_dash_and_dash_types__exp p1 = trace.p;
  kk_std_core__list old__trace = trace.l;
  kk_function_dup(model);
  kk_std_core__list_dup(old__trace);
  kk_std_core_types__tuple2_ x_1840;
  kk_function_t _x2697 = kk_function_dup(model); /*() -> ((int) -> <exn,effects-and-types/sample,effects-and-types/sample,effects-and-types/score,effects-and-types/yield|1405> 1404)*/
  x_1840 = kk_tmcmc_with__randomness__rmsmc(_x2697, modified__trace, _ctx); /*(effects-and-types/trace_values, (effects-and-types/exp, 1404))*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__tuple2__drop(x_1840, _ctx);
    kk_box_t _x2698 = kk_std_core_hnd_yield_extend(kk_tmcmc__new_mlift1718_mh__step__rmsmc_fun2699(model, old__trace, trace, p1, _ctx), _ctx); /*2*/
    return kk_tmcmc__trace__rmsmc_unbox(_x2698, _ctx);
  }
  return kk_tmcmc__mlift1717_mh__step__rmsmc(model, old__trace, p1, trace, x_1840, _ctx);
}


// lift anonymous function
struct kk_tmcmc_mh__step__rmsmc_fun2704__t {
  struct kk_function_s _base;
  size_t i_1847;
};
static kk_box_t kk_tmcmc_mh__step__rmsmc_fun2704(kk_function_t _fself, kk_function_t _b_2225, kk_box_t _b_2226, kk_context_t* _ctx);
static kk_function_t kk_tmcmc_new_mh__step__rmsmc_fun2704(size_t i_1847, kk_context_t* _ctx) {
  struct kk_tmcmc_mh__step__rmsmc_fun2704__t* _self = kk_function_alloc_as(struct kk_tmcmc_mh__step__rmsmc_fun2704__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc_mh__step__rmsmc_fun2704, kk_context());
  _self->i_1847 = i_1847;
  return &_self->_base;
}

static kk_box_t kk_tmcmc_mh__step__rmsmc_fun2704(kk_function_t _fself, kk_function_t _b_2225, kk_box_t _b_2226, kk_context_t* _ctx) {
  struct kk_tmcmc_mh__step__rmsmc_fun2704__t* _self = kk_function_as(struct kk_tmcmc_mh__step__rmsmc_fun2704__t*, _fself);
  size_t i_1847 = _self->i_1847; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_1847, _b_2225, _b_2226, _ctx);
}


// lift anonymous function
struct kk_tmcmc_mh__step__rmsmc_fun2706__t {
  struct kk_function_s _base;
  kk_tmcmc__trace__rmsmc trace;
};
static kk_box_t kk_tmcmc_mh__step__rmsmc_fun2706(kk_function_t _fself, kk_box_t _b_2236, kk_context_t* _ctx);
static kk_function_t kk_tmcmc_new_mh__step__rmsmc_fun2706(kk_tmcmc__trace__rmsmc trace, kk_context_t* _ctx) {
  struct kk_tmcmc_mh__step__rmsmc_fun2706__t* _self = kk_function_alloc_as(struct kk_tmcmc_mh__step__rmsmc_fun2706__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc_mh__step__rmsmc_fun2706, kk_context());
  _self->trace = trace;
  return &_self->_base;
}

static kk_box_t kk_tmcmc_mh__step__rmsmc_fun2706(kk_function_t _fself, kk_box_t _b_2236, kk_context_t* _ctx) {
  struct kk_tmcmc_mh__step__rmsmc_fun2706__t* _self = kk_function_as(struct kk_tmcmc_mh__step__rmsmc_fun2706__t*, _fself);
  kk_tmcmc__trace__rmsmc trace = _self->trace; /* tmcmc/trace_rmsmc<1404,<effects-and-types/sample,effects-and-types/sample,effects-and-types/score,effects-and-types/yield,exn|1405>> */
  kk_drop_match(_self, {kk_tmcmc__trace__rmsmc_dup(trace);}, {}, _ctx)
  kk_tmcmc__trace__rmsmc _x2707;
  kk_std_core__list _x2708 = kk_std_core__list_unbox(_b_2236, _ctx); /*effects-and-types/trace_values*/
  _x2707 = kk_tmcmc__mlift1718_mh__step__rmsmc(trace, _x2708, _ctx); /*tmcmc/trace_rmsmc<1404,<exn,effects-and-types/sample,effects-and-types/sample,effects-and-types/score,effects-and-types/yield|1405>>*/
  return kk_tmcmc__trace__rmsmc_box(_x2707, _ctx);
}


// lift anonymous function
struct kk_tmcmc_mh__step__rmsmc_fun2711__t {
  struct kk_function_s _base;
  kk_function_t model;
  kk_std_core__list old__trace;
  kk_tmcmc__trace__rmsmc trace;
  kk_effects_dash_and_dash_types__exp p1;
};
static kk_box_t kk_tmcmc_mh__step__rmsmc_fun2711(kk_function_t _fself, kk_box_t _b_2238, kk_context_t* _ctx);
static kk_function_t kk_tmcmc_new_mh__step__rmsmc_fun2711(kk_function_t model, kk_std_core__list old__trace, kk_tmcmc__trace__rmsmc trace, kk_effects_dash_and_dash_types__exp p1, kk_context_t* _ctx) {
  struct kk_tmcmc_mh__step__rmsmc_fun2711__t* _self = kk_function_alloc_as(struct kk_tmcmc_mh__step__rmsmc_fun2711__t, 5, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc_mh__step__rmsmc_fun2711, kk_context());
  _self->model = model;
  _self->old__trace = old__trace;
  _self->trace = trace;
  _self->p1 = p1;
  return &_self->_base;
}

static kk_box_t kk_tmcmc_mh__step__rmsmc_fun2711(kk_function_t _fself, kk_box_t _b_2238, kk_context_t* _ctx) {
  struct kk_tmcmc_mh__step__rmsmc_fun2711__t* _self = kk_function_as(struct kk_tmcmc_mh__step__rmsmc_fun2711__t*, _fself);
  kk_function_t model = _self->model; /* () -> ((int) -> <exn,effects-and-types/sample,effects-and-types/sample,effects-and-types/score,effects-and-types/yield|1405> 1404) */
  kk_std_core__list old__trace = _self->old__trace; /* effects-and-types/trace_values */
  kk_tmcmc__trace__rmsmc trace = _self->trace; /* tmcmc/trace_rmsmc<1404,<effects-and-types/sample,effects-and-types/sample,effects-and-types/score,effects-and-types/yield,exn|1405>> */
  kk_effects_dash_and_dash_types__exp p1 = _self->p1; /* effects-and-types/exp */
  kk_drop_match(_self, {kk_function_dup(model);kk_std_core__list_dup(old__trace);kk_tmcmc__trace__rmsmc_dup(trace);kk_effects_dash_and_dash_types__exp_dup(p1);}, {}, _ctx)
  kk_tmcmc__trace__rmsmc _x2712;
  kk_std_core_types__tuple2_ _x2713 = kk_std_core_types__tuple2__unbox(_b_2238, _ctx); /*(effects-and-types/trace_values, (effects-and-types/exp, 1404))*/
  _x2712 = kk_tmcmc__mlift1717_mh__step__rmsmc(model, old__trace, p1, trace, _x2713, _ctx); /*tmcmc/trace_rmsmc<1404,<exn,effects-and-types/sample,effects-and-types/sample,effects-and-types/score,effects-and-types/yield|1405>>*/
  return kk_tmcmc__trace__rmsmc_box(_x2712, _ctx);
}


// lift anonymous function
struct kk_tmcmc_mh__step__rmsmc_fun2720__t {
  struct kk_function_s _base;
};
static kk_box_t kk_tmcmc_mh__step__rmsmc_fun2720(kk_function_t _fself, kk_box_t _b_2244, kk_context_t* _ctx);
static kk_function_t kk_tmcmc_new_mh__step__rmsmc_fun2720(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_tmcmc_mh__step__rmsmc_fun2720, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_tmcmc_mh__step__rmsmc_fun2720(kk_function_t _fself, kk_box_t _b_2244, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x2721;
  kk_effects_dash_and_dash_types__exp _x2722 = kk_effects_dash_and_dash_types__exp_unbox(_b_2244, _ctx); /*effects-and-types/exp*/
  _x2721 = kk_exponents_exp__to__double(_x2722, _ctx); /*double*/
  return kk_double_box(_x2721, _ctx);
}


// lift anonymous function
struct kk_tmcmc_mh__step__rmsmc_fun2728__t {
  struct kk_function_s _base;
};
static kk_box_t kk_tmcmc_mh__step__rmsmc_fun2728(kk_function_t _fself, kk_box_t _b_2247, kk_context_t* _ctx);
static kk_function_t kk_tmcmc_new_mh__step__rmsmc_fun2728(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_tmcmc_mh__step__rmsmc_fun2728, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_tmcmc_mh__step__rmsmc_fun2728(kk_function_t _fself, kk_box_t _b_2247, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x2729;
  kk_effects_dash_and_dash_types__exp _x2730 = kk_effects_dash_and_dash_types__exp_unbox(_b_2247, _ctx); /*effects-and-types/exp*/
  _x2729 = kk_exponents_exp__to__double(_x2730, _ctx); /*double*/
  return kk_double_box(_x2729, _ctx);
}


// lift anonymous function
struct kk_tmcmc_mh__step__rmsmc_fun2736__t {
  struct kk_function_s _base;
  size_t i0_1860;
};
static kk_box_t kk_tmcmc_mh__step__rmsmc_fun2736(kk_function_t _fself, kk_function_t _b_2257, kk_box_t _b_2258, kk_context_t* _ctx);
static kk_function_t kk_tmcmc_new_mh__step__rmsmc_fun2736(size_t i0_1860, kk_context_t* _ctx) {
  struct kk_tmcmc_mh__step__rmsmc_fun2736__t* _self = kk_function_alloc_as(struct kk_tmcmc_mh__step__rmsmc_fun2736__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc_mh__step__rmsmc_fun2736, kk_context());
  _self->i0_1860 = i0_1860;
  return &_self->_base;
}

static kk_box_t kk_tmcmc_mh__step__rmsmc_fun2736(kk_function_t _fself, kk_function_t _b_2257, kk_box_t _b_2258, kk_context_t* _ctx) {
  struct kk_tmcmc_mh__step__rmsmc_fun2736__t* _self = kk_function_as(struct kk_tmcmc_mh__step__rmsmc_fun2736__t*, _fself);
  size_t i0_1860 = _self->i0_1860; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i0_1860, _b_2257, _b_2258, _ctx);
}


// lift anonymous function
struct kk_tmcmc_mh__step__rmsmc_fun2738__t {
  struct kk_function_s _base;
  kk_function_t model;
  kk_std_core__list new__trace;
  kk_tmcmc__trace__rmsmc trace;
  kk_effects_dash_and_dash_types__exp p2;
};
static kk_box_t kk_tmcmc_mh__step__rmsmc_fun2738(kk_function_t _fself, kk_box_t _b_2268, kk_context_t* _ctx);
static kk_function_t kk_tmcmc_new_mh__step__rmsmc_fun2738(kk_function_t model, kk_std_core__list new__trace, kk_tmcmc__trace__rmsmc trace, kk_effects_dash_and_dash_types__exp p2, kk_context_t* _ctx) {
  struct kk_tmcmc_mh__step__rmsmc_fun2738__t* _self = kk_function_alloc_as(struct kk_tmcmc_mh__step__rmsmc_fun2738__t, 5, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc_mh__step__rmsmc_fun2738, kk_context());
  _self->model = model;
  _self->new__trace = new__trace;
  _self->trace = trace;
  _self->p2 = p2;
  return &_self->_base;
}

static kk_box_t kk_tmcmc_mh__step__rmsmc_fun2738(kk_function_t _fself, kk_box_t _b_2268, kk_context_t* _ctx) {
  struct kk_tmcmc_mh__step__rmsmc_fun2738__t* _self = kk_function_as(struct kk_tmcmc_mh__step__rmsmc_fun2738__t*, _fself);
  kk_function_t model = _self->model; /* () -> ((int) -> <exn,effects-and-types/sample,effects-and-types/sample,effects-and-types/score,effects-and-types/yield|1405> 1404) */
  kk_std_core__list new__trace = _self->new__trace; /* effects-and-types/trace_values */
  kk_tmcmc__trace__rmsmc trace = _self->trace; /* tmcmc/trace_rmsmc<1404,<effects-and-types/sample,effects-and-types/sample,effects-and-types/score,effects-and-types/yield,exn|1405>> */
  kk_effects_dash_and_dash_types__exp p2 = _self->p2; /* effects-and-types/exp */
  kk_drop_match(_self, {kk_function_dup(model);kk_std_core__list_dup(new__trace);kk_tmcmc__trace__rmsmc_dup(trace);kk_effects_dash_and_dash_types__exp_dup(p2);}, {}, _ctx)
  kk_tmcmc__trace__rmsmc _x2739;
  bool _x2740 = kk_bool_unbox(_b_2268); /*bool*/
  _x2739 = kk_tmcmc__mlift1716_mh__step__rmsmc(model, new__trace, p2, trace, _x2740, _ctx); /*tmcmc/trace_rmsmc<1404,<exn,effects-and-types/sample,effects-and-types/sample,effects-and-types/score,effects-and-types/yield|1405>>*/
  return kk_tmcmc__trace__rmsmc_box(_x2739, _ctx);
}

kk_tmcmc__trace__rmsmc kk_tmcmc_mh__step__rmsmc(kk_tmcmc__trace__rmsmc trace, kk_context_t* _ctx) { /* forall<a,e> (trace : trace_rmsmc<a,<effects-and-types/sample,effects-and-types/sample,effects-and-types/score,effects-and-types/yield,exn|e>>) -> <effects-and-types/sample,effects-and-types/sample,effects-and-types/yield,exn|e> trace_rmsmc<a,<effects-and-types/sample,effects-and-types/sample,effects-and-types/score,effects-and-types/yield,exn|e>> */ 
  kk_std_core__list x_1842;
  kk_std_core__list _x1;
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*std/core/hnd/evv<(<>)>*/;
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  kk_effects_dash_and_dash_types__exp _pat1 = trace.p;
  kk_std_core__list _x = trace.l;
  kk_std_core__list_dup(_x);
  _x1 = _x; /*effects-and-types/trace_values*/
  size_t i_1847;
  kk_std_core_hnd__htag _x2702 = kk_std_core_hnd__htag_dup(kk_effects_dash_and_dash_types__tag_sample); /*std/core/hnd/htag<effects-and-types/.hnd-sample>*/
  i_1847 = kk_std_core_hnd__evv_index(_x2702, _ctx); /*std/core/hnd/ev-index*/
  kk_evv_t w0 = kk_evv_swap_create1(i_1847,kk_context()); /*std/core/hnd/evv<<effects-and-types/sample,exn,effects-and-types/sample,effects-and-types/yield|1405>>*/;
  kk_std_core__list y = kk_tmcmc_perturb__trace(_x1, _ctx); /*effects-and-types/trace_values*/;
  kk_unit_t __w_l700_c9 = kk_Unit;
  kk_evv_set(w0,kk_context());
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(y, _ctx);
    kk_box_t _x2703 = kk_std_core_hnd_yield_cont(kk_tmcmc_new_mh__step__rmsmc_fun2704(i_1847, _ctx), _ctx); /*3*/
    x_1842 = kk_std_core__list_unbox(_x2703, _ctx); /*effects-and-types/trace_values*/
  }
  else {
    x_1842 = y; /*effects-and-types/trace_values*/
  }
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_1842, _ctx);
    kk_box_t _x2705 = kk_std_core_hnd_yield_extend(kk_tmcmc_new_mh__step__rmsmc_fun2706(trace, _ctx), _ctx); /*2*/
    return kk_tmcmc__trace__rmsmc_unbox(_x2705, _ctx);
  }
  kk_function_t model = trace.m;
  kk_effects_dash_and_dash_types__exp p1 = trace.p;
  kk_std_core__list old__trace = trace.l;
  kk_function_dup(model);
  kk_std_core__list_dup(old__trace);
  kk_std_core_types__tuple2_ x3_1851;
  kk_function_t _x2709 = kk_function_dup(model); /*() -> ((int) -> <exn,effects-and-types/sample,effects-and-types/sample,effects-and-types/score,effects-and-types/yield|1405> 1404)*/
  x3_1851 = kk_tmcmc_with__randomness__rmsmc(_x2709, x_1842, _ctx); /*(effects-and-types/trace_values, (effects-and-types/exp, 1404))*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__tuple2__drop(x3_1851, _ctx);
    kk_box_t _x2710 = kk_std_core_hnd_yield_extend(kk_tmcmc_new_mh__step__rmsmc_fun2711(model, old__trace, trace, p1, _ctx), _ctx); /*2*/
    return kk_tmcmc__trace__rmsmc_unbox(_x2710, _ctx);
  }
  kk_box_t _box_x2239 = x3_1851.fst;
  kk_box_t _box_x2240 = x3_1851.snd;
  kk_std_core__list new__trace = kk_std_core__list_unbox(_box_x2239, NULL);
  kk_std_core_types__tuple2_ _pat200 = kk_std_core_types__tuple2__unbox(_box_x2240, NULL);
  kk_box_t _box_x2241 = _pat200.fst;
  kk_effects_dash_and_dash_types__exp p2 = kk_effects_dash_and_dash_types__exp_unbox(_box_x2241, NULL);
  kk_std_core__list_dup(new__trace);
  kk_std_core_types__tuple2__drop(x3_1851, _ctx);
  double ratio;
  double y0_1856;
  double _x2717;
  double _x2718;
  kk_box_t _x2719 = kk_std_core_hnd__open_none1(kk_tmcmc_new_mh__step__rmsmc_fun2720(_ctx), kk_effects_dash_and_dash_types__exp_box(p2, _ctx), _ctx); /*2*/
  _x2718 = kk_double_unbox(_x2719, _ctx); /*double*/
  double _x2723;
  kk_integer_t _x2724 = kk_std_core_length_1(old__trace, _ctx); /*int*/
  _x2723 = kk_integer_as_double(_x2724,kk_context()); /*double*/
  _x2717 = (_x2718 * _x2723); /*double*/
  double _x2725;
  double _x2726;
  kk_box_t _x2727 = kk_std_core_hnd__open_none1(kk_tmcmc_new_mh__step__rmsmc_fun2728(_ctx), kk_effects_dash_and_dash_types__exp_box(p1, _ctx), _ctx); /*2*/
  _x2726 = kk_double_unbox(_x2727, _ctx); /*double*/
  double _x2731;
  kk_integer_t _x2732;
  kk_std_core__list _x2733 = kk_std_core__list_dup(new__trace); /*effects-and-types/trace_values*/
  _x2732 = kk_std_core_length_1(_x2733, _ctx); /*int*/
  _x2731 = kk_integer_as_double(_x2732,kk_context()); /*double*/
  _x2725 = (_x2726 * _x2731); /*double*/
  y0_1856 = (_x2717 / _x2725); /*double*/
  bool _match_2353 = (0x1p0 <= y0_1856); /*bool*/;
  if (_match_2353) {
    ratio = 0x1p0; /*double*/
  }
  else {
    ratio = y0_1856; /*double*/
  }
  bool x5_1857;
  size_t i0_1860;
  kk_std_core_hnd__htag _x2734 = kk_std_core_hnd__htag_dup(kk_effects_dash_and_dash_types__tag_sample); /*std/core/hnd/htag<effects-and-types/.hnd-sample>*/
  i0_1860 = kk_std_core_hnd__evv_index(_x2734, _ctx); /*std/core/hnd/ev-index*/
  kk_evv_t w1 = kk_evv_swap_create1(i0_1860,kk_context()); /*std/core/hnd/evv<<effects-and-types/sample,exn,effects-and-types/sample,effects-and-types/yield|1405>>*/;
  bool y1 = kk_model_dash_resources_bernoulli(ratio, _ctx); /*bool*/;
  kk_unit_t __w_l700_c90 = kk_Unit;
  kk_evv_set(w1,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x2735 = kk_std_core_hnd_yield_cont(kk_tmcmc_new_mh__step__rmsmc_fun2736(i0_1860, _ctx), _ctx); /*3*/
    x5_1857 = kk_bool_unbox(_x2735); /*bool*/
  }
  else {
    x5_1857 = y1; /*bool*/
  }
  if (kk_yielding(kk_context())) {
    kk_box_t _x2737 = kk_std_core_hnd_yield_extend(kk_tmcmc_new_mh__step__rmsmc_fun2738(model, new__trace, trace, p2, _ctx), _ctx); /*2*/
    return kk_tmcmc__trace__rmsmc_unbox(_x2737, _ctx);
  }
  if (x5_1857) {
    kk_tmcmc__trace__rmsmc_drop(trace, _ctx);
    return kk_tmcmc__new_RTrace(model, p2, new__trace, _ctx);
  }
  kk_function_drop(model, _ctx);
  kk_std_core__list_drop(new__trace, _ctx);
  return trace;
}
 
// monadic lift

kk_std_core_types__tuple2_ kk_tmcmc__mlift1719_model__stepper__recursive(kk_integer_t burnin, kk_std_core__list posterior, kk_integer_t steps, kk_tmcmc__trace new__trace, kk_context_t* _ctx) { /* forall<a,e> (burnin : int, posterior : list<(list<double>, a)>, steps : int, new_trace : trace<a,<effects-and-types/sample,effects-and-types/score,div|e>>) -> <effects-and-types/sample,div|e> (list<(list<double>, a)>, trace<a,<effects-and-types/sample,effects-and-types/score,div|e>>) */ 
  bool _match_2348;
  kk_integer_t _x2741 = kk_integer_dup(burnin); /*int*/
  _match_2348 = kk_integer_gt(_x2741,(kk_integer_from_small(0)),kk_context()); /*bool*/
  if (_match_2348) {
    kk_integer_t _x2742 = kk_integer_sub(steps,(kk_integer_from_small(1)),kk_context()); /*int*/
    kk_integer_t _x2743 = kk_integer_sub(burnin,(kk_integer_from_small(1)),kk_context()); /*int*/
    return kk_tmcmc_model__stepper__recursive(_x2742, new__trace, posterior, _x2743, _ctx);
  }
  kk_integer_t _x2744 = kk_integer_sub(steps,(kk_integer_from_small(1)),kk_context()); /*int*/
  kk_tmcmc__trace _x2745 = kk_tmcmc__trace_dup(new__trace); /*tmcmc/trace<1629,<effects-and-types/sample,effects-and-types/score,div|1630>>*/
  kk_std_core__list _x2746;
  kk_std_core__list ys_1865;
  kk_std_core_types__tuple2_ _b_2279_2277;
  kk_std_core__list _b_2281_2275;
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*std/core/hnd/evv<(<>)>*/;
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  struct kk_tmcmc_Trace* _con2747 = kk_tmcmc__as_Trace(new__trace);
  kk_effects_dash_and_dash_types__exp _pat10 = _con2747->p;
  kk_std_core__list _x = _con2747->l;
  kk_std_core__list_dup(_x);
  _b_2281_2275 = _x; /*effects-and-types/trace_values*/
  kk_box_t _b_2282_2276;
  kk_evv_t w0 = kk_evv_swap_create0(kk_context()); /*std/core/hnd/evv<(<>)>*/;
  kk_unit_t keep0 = kk_Unit;
  kk_evv_set(w0,kk_context());
  struct kk_tmcmc_Trace* _con2748 = kk_tmcmc__as_Trace(new__trace);
  kk_function_t _pat00 = _con2748->m;
  kk_effects_dash_and_dash_types__exp _pat11 = _con2748->p;
  kk_std_core__list _pat30 = _con2748->l;
  kk_box_t _x0 = _con2748->a;
  if (kk_tmcmc__trace_is_unique(new__trace)) {
    kk_std_core__list_drop(_pat30, _ctx);
    kk_function_drop(_pat00, _ctx);
    kk_tmcmc__trace_free(new__trace);
  }
  else {
    kk_box_dup(_x0);
    kk_tmcmc__trace_decref(new__trace, _ctx);
  }
  _b_2282_2276 = _x0; /*1629*/
  _b_2279_2277 = kk_std_core_types__new_dash__lp__comma__rp_(kk_std_core__list_box(_b_2281_2275, _ctx), _b_2282_2276, _ctx); /*(effects-and-types/trace_values, 1629)*/
  ys_1865 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core_types__tuple2__box(_b_2279_2277, _ctx), kk_std_core__new_Nil(_ctx), _ctx); /*list<(list<double>, 1629)>*/
  _x2746 = kk_std_core_append(posterior, ys_1865, _ctx); /*list<1>*/
  return kk_tmcmc_model__stepper__recursive(_x2744, _x2745, _x2746, burnin, _ctx);
}


// lift anonymous function
struct kk_tmcmc_model__stepper__recursive_fun2751__t {
  struct kk_function_s _base;
  kk_integer_t burnin0;
  kk_std_core__list posterior0;
  kk_integer_t steps0;
};
static kk_box_t kk_tmcmc_model__stepper__recursive_fun2751(kk_function_t _fself, kk_box_t _b_2286, kk_context_t* _ctx);
static kk_function_t kk_tmcmc_new_model__stepper__recursive_fun2751(kk_integer_t burnin0, kk_std_core__list posterior0, kk_integer_t steps0, kk_context_t* _ctx) {
  struct kk_tmcmc_model__stepper__recursive_fun2751__t* _self = kk_function_alloc_as(struct kk_tmcmc_model__stepper__recursive_fun2751__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc_model__stepper__recursive_fun2751, kk_context());
  _self->burnin0 = burnin0;
  _self->posterior0 = posterior0;
  _self->steps0 = steps0;
  return &_self->_base;
}

static kk_box_t kk_tmcmc_model__stepper__recursive_fun2751(kk_function_t _fself, kk_box_t _b_2286, kk_context_t* _ctx) {
  struct kk_tmcmc_model__stepper__recursive_fun2751__t* _self = kk_function_as(struct kk_tmcmc_model__stepper__recursive_fun2751__t*, _fself);
  kk_integer_t burnin0 = _self->burnin0; /* int */
  kk_std_core__list posterior0 = _self->posterior0; /* list<(list<double>, 1629)> */
  kk_integer_t steps0 = _self->steps0; /* int */
  kk_drop_match(_self, {kk_integer_dup(burnin0);kk_std_core__list_dup(posterior0);kk_integer_dup(steps0);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x2752;
  kk_tmcmc__trace _x2753 = kk_tmcmc__trace_unbox(_b_2286, _ctx); /*tmcmc/trace<1629,<effects-and-types/sample,effects-and-types/score,div|1630>>*/
  _x2752 = kk_tmcmc__mlift1719_model__stepper__recursive(burnin0, posterior0, steps0, _x2753, _ctx); /*(list<(list<double>, 1629)>, tmcmc/trace<1629,<effects-and-types/sample,effects-and-types/score,div|1630>>)*/
  return kk_std_core_types__tuple2__box(_x2752, _ctx);
}

kk_std_core_types__tuple2_ kk_tmcmc_model__stepper__recursive(kk_integer_t steps0, kk_tmcmc__trace trace, kk_std_core__list posterior0, kk_integer_t burnin0, kk_context_t* _ctx) { /* forall<a,e> (steps : int, trace : trace<a,<effects-and-types/sample,effects-and-types/score,div|e>>, posterior : list<(list<double>, a)>, burnin : int) -> <effects-and-types/sample,div|e> (list<(list<double>, a)>, trace<a,<effects-and-types/sample,effects-and-types/score,div|e>>) */ 
  kk__tailcall: ;
  bool _match_2345;
  kk_integer_t _x2749 = kk_integer_dup(steps0); /*int*/
  _match_2345 = kk_integer_lt(_x2749,(kk_integer_from_small(1)),kk_context()); /*bool*/
  if (_match_2345) {
    kk_integer_drop(burnin0, _ctx);
    kk_integer_drop(steps0, _ctx);
    return kk_std_core_types__new_dash__lp__comma__rp_(kk_std_core__list_box(posterior0, _ctx), kk_tmcmc__trace_box(trace, _ctx), _ctx);
  }
  kk_tmcmc__trace x_1870 = kk_tmcmc_mh__step(trace, _ctx); /*tmcmc/trace<1629,<effects-and-types/sample,effects-and-types/score,div|1630>>*/;
  if (kk_yielding(kk_context())) {
    kk_tmcmc__trace_dropn(x_1870, ((int32_t)3), _ctx);
    kk_box_t _x2750 = kk_std_core_hnd_yield_extend(kk_tmcmc_new_model__stepper__recursive_fun2751(burnin0, posterior0, steps0, _ctx), _ctx); /*2*/
    return kk_std_core_types__tuple2__unbox(_x2750, _ctx);
  }
  bool _match_2347;
  kk_integer_t _x2754 = kk_integer_dup(burnin0); /*int*/
  _match_2347 = kk_integer_gt(_x2754,(kk_integer_from_small(0)),kk_context()); /*bool*/
  if (_match_2347) {
    { // tailcall
      kk_integer_t _x2755 = kk_integer_sub(steps0,(kk_integer_from_small(1)),kk_context()); /*int*/
      kk_integer_t _x2756 = kk_integer_sub(burnin0,(kk_integer_from_small(1)),kk_context()); /*int*/
      steps0 = _x2755;
      trace = x_1870;
      burnin0 = _x2756;
      goto kk__tailcall;
    }
  }
  { // tailcall
    kk_integer_t _x2757 = kk_integer_sub(steps0,(kk_integer_from_small(1)),kk_context()); /*int*/
    kk_tmcmc__trace _x2758 = kk_tmcmc__trace_dup(x_1870); /*tmcmc/trace<1629,<effects-and-types/sample,effects-and-types/score,div|1630>>*/
    kk_std_core__list _x2759;
    kk_std_core__list ys_1875;
    kk_std_core_types__tuple2_ _b_2291_2289;
    kk_std_core__list _b_2293_2287;
    kk_evv_t w1 = kk_evv_swap_create0(kk_context()); /*std/core/hnd/evv<(<>)>*/;
    kk_unit_t keep1 = kk_Unit;
    kk_evv_set(w1,kk_context());
    struct kk_tmcmc_Trace* _con2760 = kk_tmcmc__as_Trace(x_1870);
    kk_effects_dash_and_dash_types__exp _pat110 = _con2760->p;
    kk_std_core__list _x1 = _con2760->l;
    kk_std_core__list_dup(_x1);
    _b_2293_2287 = _x1; /*effects-and-types/trace_values*/
    kk_box_t _b_2294_2288;
    kk_evv_t w00 = kk_evv_swap_create0(kk_context()); /*std/core/hnd/evv<(<>)>*/;
    kk_unit_t keep00 = kk_Unit;
    kk_evv_set(w00,kk_context());
    struct kk_tmcmc_Trace* _con2761 = kk_tmcmc__as_Trace(x_1870);
    kk_function_t _pat02 = _con2761->m;
    kk_effects_dash_and_dash_types__exp _pat120 = _con2761->p;
    kk_std_core__list _pat310 = _con2761->l;
    kk_box_t _x00 = _con2761->a;
    if (kk_tmcmc__trace_is_unique(x_1870)) {
      kk_std_core__list_drop(_pat310, _ctx);
      kk_function_drop(_pat02, _ctx);
      kk_tmcmc__trace_free(x_1870);
    }
    else {
      kk_box_dup(_x00);
      kk_tmcmc__trace_decref(x_1870, _ctx);
    }
    _b_2294_2288 = _x00; /*1629*/
    _b_2291_2289 = kk_std_core_types__new_dash__lp__comma__rp_(kk_std_core__list_box(_b_2293_2287, _ctx), _b_2294_2288, _ctx); /*(effects-and-types/trace_values, 1629)*/
    ys_1875 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core_types__tuple2__box(_b_2291_2289, _ctx), kk_std_core__new_Nil(_ctx), _ctx); /*list<(list<double>, 1629)>*/
    _x2759 = kk_std_core_append(posterior0, ys_1875, _ctx); /*list<1>*/
    steps0 = _x2757;
    trace = _x2758;
    posterior0 = _x2759;
    goto kk__tailcall;
  }
}
 
// monadic lift

kk_std_core_types__tuple2_ kk_tmcmc__mlift1720_tmcmc(kk_integer_t burnin, kk_function_t model, kk_integer_t steps, kk_std_core_types__tuple2_ model__results, kk_context_t* _ctx) { /* forall<a,e> (burnin : int, model : () -> <effects-and-types/sample,effects-and-types/score,div|e> a, steps : int, model_results : (effects-and-types/exp, (list<double>, a))) -> <div,effects-and-types/sample|e> (list<(list<double>, a)>, trace<a,<effects-and-types/sample,effects-and-types/score,div|e>>) */ 
  kk_box_t _box_x2299 = model__results.fst;
  kk_box_t _box_x2300 = model__results.snd;
  kk_effects_dash_and_dash_types__exp p0 = kk_effects_dash_and_dash_types__exp_unbox(_box_x2299, NULL);
  kk_std_core_types__tuple2_ _pat1 = kk_std_core_types__tuple2__unbox(_box_x2300, NULL);
  kk_box_t _box_x2301 = _pat1.fst;
  kk_box_t a0 = _pat1.snd;
  kk_std_core__list d = kk_std_core__list_unbox(_box_x2301, NULL);
  kk_box_dup(a0);
  kk_std_core__list_dup(d);
  kk_std_core_types__tuple2__drop(model__results, _ctx);
  kk_tmcmc__trace _x2765 = kk_tmcmc__new_Trace(kk_reuse_null, model, p0, d, a0, _ctx); /*tmcmc/trace<5,6>*/
  return kk_tmcmc_model__stepper__recursive(steps, _x2765, kk_std_core__new_Nil(_ctx), burnin, _ctx);
}


// lift anonymous function
struct kk_tmcmc_tmcmc_fun2767__t {
  struct kk_function_s _base;
  kk_function_t model;
};
static kk_box_t kk_tmcmc_tmcmc_fun2767(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_tmcmc_new_tmcmc_fun2767(kk_function_t model, kk_context_t* _ctx) {
  struct kk_tmcmc_tmcmc_fun2767__t* _self = kk_function_alloc_as(struct kk_tmcmc_tmcmc_fun2767__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc_tmcmc_fun2767, kk_context());
  _self->model = model;
  return &_self->_base;
}



// lift anonymous function
struct kk_tmcmc_tmcmc_fun2769__t {
  struct kk_function_s _base;
  kk_function_t model;
};
static kk_box_t kk_tmcmc_tmcmc_fun2769(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_tmcmc_new_tmcmc_fun2769(kk_function_t model, kk_context_t* _ctx) {
  struct kk_tmcmc_tmcmc_fun2769__t* _self = kk_function_alloc_as(struct kk_tmcmc_tmcmc_fun2769__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc_tmcmc_fun2769, kk_context());
  _self->model = model;
  return &_self->_base;
}



// lift anonymous function
struct kk_tmcmc_tmcmc_fun2771__t {
  struct kk_function_s _base;
  kk_function_t model;
};
static kk_box_t kk_tmcmc_tmcmc_fun2771(kk_function_t _fself, kk_box_t _b_2303, kk_context_t* _ctx);
static kk_function_t kk_tmcmc_new_tmcmc_fun2771(kk_function_t model, kk_context_t* _ctx) {
  struct kk_tmcmc_tmcmc_fun2771__t* _self = kk_function_alloc_as(struct kk_tmcmc_tmcmc_fun2771__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc_tmcmc_fun2771, kk_context());
  _self->model = model;
  return &_self->_base;
}

static kk_box_t kk_tmcmc_tmcmc_fun2771(kk_function_t _fself, kk_box_t _b_2303, kk_context_t* _ctx) {
  struct kk_tmcmc_tmcmc_fun2771__t* _self = kk_function_as(struct kk_tmcmc_tmcmc_fun2771__t*, _fself);
  kk_function_t model = _self->model; /* () -> <effects-and-types/sample,effects-and-types/score,div|1689> 1688 */
  kk_drop_match(_self, {kk_function_dup(model);}, {}, _ctx)
  size_t _x2772 = kk_size_unbox(_b_2303, _ctx); /*std/core/hnd/ev-index*/
  return kk_handlers__mlift2035_replay(model, _x2772, _ctx);
}
static kk_box_t kk_tmcmc_tmcmc_fun2769(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_tmcmc_tmcmc_fun2769__t* _self = kk_function_as(struct kk_tmcmc_tmcmc_fun2769__t*, _fself);
  kk_function_t model = _self->model; /* () -> <effects-and-types/sample,effects-and-types/score,div|1689> 1688 */
  kk_drop_match(_self, {kk_function_dup(model);}, {}, _ctx)
  size_t x_2130;
  kk_std_core_hnd__htag _x2770 = kk_std_core_hnd__htag_dup(kk_effects_dash_and_dash_types__tag_sample); /*std/core/hnd/htag<effects-and-types/.hnd-sample>*/
  x_2130 = kk_std_core_hnd__evv_index(_x2770, _ctx); /*std/core/hnd/ev-index*/
  if (kk_yielding(kk_context())) {
    return kk_std_core_hnd_yield_extend(kk_tmcmc_new_tmcmc_fun2771(model, _ctx), _ctx);
  }
  return kk_handlers__mlift2035_replay(model, x_2130, _ctx);
}
static kk_box_t kk_tmcmc_tmcmc_fun2767(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_tmcmc_tmcmc_fun2767__t* _self = kk_function_as(struct kk_tmcmc_tmcmc_fun2767__t*, _fself);
  kk_function_t model = _self->model; /* () -> <effects-and-types/sample,effects-and-types/score,div|1689> 1688 */
  kk_drop_match(_self, {kk_function_dup(model);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x2768 = kk_handlers_replayx(kk_std_core__new_Nil(_ctx), kk_tmcmc_new_tmcmc_fun2769(model, _ctx), _ctx); /*(list<double>, 0)*/
  return kk_std_core_types__tuple2__box(_x2768, _ctx);
}


// lift anonymous function
struct kk_tmcmc_tmcmc_fun2774__t {
  struct kk_function_s _base;
  kk_integer_t burnin;
  kk_function_t model;
  kk_integer_t steps;
};
static kk_box_t kk_tmcmc_tmcmc_fun2774(kk_function_t _fself, kk_box_t _b_2311, kk_context_t* _ctx);
static kk_function_t kk_tmcmc_new_tmcmc_fun2774(kk_integer_t burnin, kk_function_t model, kk_integer_t steps, kk_context_t* _ctx) {
  struct kk_tmcmc_tmcmc_fun2774__t* _self = kk_function_alloc_as(struct kk_tmcmc_tmcmc_fun2774__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_tmcmc_tmcmc_fun2774, kk_context());
  _self->burnin = burnin;
  _self->model = model;
  _self->steps = steps;
  return &_self->_base;
}

static kk_box_t kk_tmcmc_tmcmc_fun2774(kk_function_t _fself, kk_box_t _b_2311, kk_context_t* _ctx) {
  struct kk_tmcmc_tmcmc_fun2774__t* _self = kk_function_as(struct kk_tmcmc_tmcmc_fun2774__t*, _fself);
  kk_integer_t burnin = _self->burnin; /* int */
  kk_function_t model = _self->model; /* () -> <effects-and-types/sample,effects-and-types/score,div|1689> 1688 */
  kk_integer_t steps = _self->steps; /* int */
  kk_drop_match(_self, {kk_integer_dup(burnin);kk_function_dup(model);kk_integer_dup(steps);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x2775;
  kk_std_core_types__tuple2_ _x2776 = kk_std_core_types__tuple2__unbox(_b_2311, _ctx); /*(effects-and-types/exp, (list<double>, 1688))*/
  _x2775 = kk_tmcmc__mlift1720_tmcmc(burnin, model, steps, _x2776, _ctx); /*(list<(list<double>, 1688)>, tmcmc/trace<1688,<effects-and-types/sample,effects-and-types/score,div|1689>>)*/
  return kk_std_core_types__tuple2__box(_x2775, _ctx);
}

kk_std_core_types__tuple2_ kk_tmcmc_tmcmc(kk_function_t model, kk_integer_t steps, kk_effects_dash_and_dash_types__exp init__weight, kk_integer_t burnin, kk_context_t* _ctx) { /* forall<a,e> (model : () -> <effects-and-types/sample,effects-and-types/score,div|e> a, steps : int, init_weight : effects-and-types/exp, burnin : int) -> <effects-and-types/sample,div|e> (list<(list<double>, a)>, trace<a,<effects-and-types/sample,effects-and-types/score,div|e>>) */ 
  kk_std_core_types__tuple2_ x_1880;
  kk_function_t _x2766;
  kk_function_dup(model);
  _x2766 = kk_tmcmc_new_tmcmc_fun2767(model, _ctx); /*() -> <effects-and-types/score|1> 0*/
  x_1880 = kk_handlers_weighted(init__weight, _x2766, _ctx); /*(effects-and-types/exp, (list<double>, 1688))*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__tuple2__drop(x_1880, _ctx);
    kk_box_t _x2773 = kk_std_core_hnd_yield_extend(kk_tmcmc_new_tmcmc_fun2774(burnin, model, steps, _ctx), _ctx); /*2*/
    return kk_std_core_types__tuple2__unbox(_x2773, _ctx);
  }
  kk_box_t _box_x2312 = x_1880.fst;
  kk_box_t _box_x2313 = x_1880.snd;
  kk_effects_dash_and_dash_types__exp p0 = kk_effects_dash_and_dash_types__exp_unbox(_box_x2312, NULL);
  kk_std_core_types__tuple2_ _pat10 = kk_std_core_types__tuple2__unbox(_box_x2313, NULL);
  kk_box_t _box_x2314 = _pat10.fst;
  kk_box_t a0 = _pat10.snd;
  kk_std_core__list d = kk_std_core__list_unbox(_box_x2314, NULL);
  kk_box_dup(a0);
  kk_std_core__list_dup(d);
  kk_std_core_types__tuple2__drop(x_1880, _ctx);
  kk_tmcmc__trace _x2780 = kk_tmcmc__new_Trace(kk_reuse_null, model, p0, d, a0, _ctx); /*tmcmc/trace<5,6>*/
  return kk_tmcmc_model__stepper__recursive(steps, _x2780, kk_std_core__new_Nil(_ctx), burnin, _ctx);
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
