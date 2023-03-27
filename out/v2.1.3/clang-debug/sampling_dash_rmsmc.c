// Koka generated module: "sampling-rmsmc", koka version: 2.1.3
#include "sampling_dash_rmsmc.h"
 
// monadic lift

kk_box_t kk_sampling_dash_rmsmc__mlift125_populate(kk_function_t model, kk_unit_t wild__, kk_context_t* _ctx) { /* forall<a,e> (model : () -> <effects-and-types/score,effects-and-types/sample,effects-and-types/sample|e> a, wild_ : ()) -> <effects-and-types/score,effects-and-types/sample,effects-and-types/sample|e> a */ 
  return kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), model, (model, _ctx));
}


// lift anonymous function
struct kk_sampling_dash_rmsmc_populate_fun175__t {
  struct kk_function_s _base;
  kk_integer_t k;
  kk_function_t model;
};
static kk_box_t kk_sampling_dash_rmsmc_populate_fun175(kk_function_t _fself, kk_integer_t _b_164, kk_context_t* _ctx);
static kk_function_t kk_sampling_dash_rmsmc_new_populate_fun175(kk_integer_t k, kk_function_t model, kk_context_t* _ctx) {
  struct kk_sampling_dash_rmsmc_populate_fun175__t* _self = kk_function_alloc_as(struct kk_sampling_dash_rmsmc_populate_fun175__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_sampling_dash_rmsmc_populate_fun175, kk_context());
  _self->k = k;
  _self->model = model;
  return &_self->_base;
}



// lift anonymous function
struct kk_sampling_dash_rmsmc_populate_fun177__t {
  struct kk_function_s _base;
  kk_integer_t k;
  kk_function_t model;
};
static kk_std_core_types__tuple2_ kk_sampling_dash_rmsmc_populate_fun177(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_sampling_dash_rmsmc_new_populate_fun177(kk_integer_t k, kk_function_t model, kk_context_t* _ctx) {
  struct kk_sampling_dash_rmsmc_populate_fun177__t* _self = kk_function_alloc_as(struct kk_sampling_dash_rmsmc_populate_fun177__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_sampling_dash_rmsmc_populate_fun177, kk_context());
  _self->k = k;
  _self->model = model;
  return &_self->_base;
}



// lift anonymous function
struct kk_sampling_dash_rmsmc_populate_fun179__t {
  struct kk_function_s _base;
  kk_integer_t k;
  kk_function_t model;
};
static kk_box_t kk_sampling_dash_rmsmc_populate_fun179(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_sampling_dash_rmsmc_new_populate_fun179(kk_integer_t k, kk_function_t model, kk_context_t* _ctx) {
  struct kk_sampling_dash_rmsmc_populate_fun179__t* _self = kk_function_alloc_as(struct kk_sampling_dash_rmsmc_populate_fun179__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_sampling_dash_rmsmc_populate_fun179, kk_context());
  _self->k = k;
  _self->model = model;
  return &_self->_base;
}



// lift anonymous function
struct kk_sampling_dash_rmsmc_populate_fun183__t {
  struct kk_function_s _base;
};
static kk_box_t kk_sampling_dash_rmsmc_populate_fun183(kk_function_t _fself, kk_box_t _b_138, kk_box_t _b_139, kk_context_t* _ctx);
static kk_function_t kk_sampling_dash_rmsmc_new_populate_fun183(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_sampling_dash_rmsmc_populate_fun183, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_sampling_dash_rmsmc_populate_fun183(kk_function_t _fself, kk_box_t _b_138, kk_box_t _b_139, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_effects_dash_and_dash_types__exp _x184;
  kk_effects_dash_and_dash_types__exp _x185 = kk_effects_dash_and_dash_types__exp_unbox(_b_138, _ctx); /*effects-and-types/exp*/
  kk_effects_dash_and_dash_types__exp _x186 = kk_effects_dash_and_dash_types__exp_unbox(_b_139, _ctx); /*effects-and-types/exp*/
  _x184 = kk_exponents_div__exp(_x185, _x186, _ctx); /*effects-and-types/exp*/
  return kk_effects_dash_and_dash_types__exp_box(_x184, _ctx);
}


// lift anonymous function
struct kk_sampling_dash_rmsmc_populate_fun189__t {
  struct kk_function_s _base;
  size_t i0_131;
};
static kk_box_t kk_sampling_dash_rmsmc_populate_fun189(kk_function_t _fself, kk_function_t _b_148, kk_box_t _b_149, kk_context_t* _ctx);
static kk_function_t kk_sampling_dash_rmsmc_new_populate_fun189(size_t i0_131, kk_context_t* _ctx) {
  struct kk_sampling_dash_rmsmc_populate_fun189__t* _self = kk_function_alloc_as(struct kk_sampling_dash_rmsmc_populate_fun189__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_sampling_dash_rmsmc_populate_fun189, kk_context());
  _self->i0_131 = i0_131;
  return &_self->_base;
}

static kk_box_t kk_sampling_dash_rmsmc_populate_fun189(kk_function_t _fself, kk_function_t _b_148, kk_box_t _b_149, kk_context_t* _ctx) {
  struct kk_sampling_dash_rmsmc_populate_fun189__t* _self = kk_function_as(struct kk_sampling_dash_rmsmc_populate_fun189__t*, _fself);
  size_t i0_131 = _self->i0_131; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i0_131, _b_148, _b_149, _ctx);
}


// lift anonymous function
struct kk_sampling_dash_rmsmc_populate_fun190__t {
  struct kk_function_s _base;
  kk_function_t model;
};
static kk_box_t kk_sampling_dash_rmsmc_populate_fun190(kk_function_t _fself, kk_box_t _b_159, kk_context_t* _ctx);
static kk_function_t kk_sampling_dash_rmsmc_new_populate_fun190(kk_function_t model, kk_context_t* _ctx) {
  struct kk_sampling_dash_rmsmc_populate_fun190__t* _self = kk_function_alloc_as(struct kk_sampling_dash_rmsmc_populate_fun190__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_sampling_dash_rmsmc_populate_fun190, kk_context());
  _self->model = model;
  return &_self->_base;
}

static kk_box_t kk_sampling_dash_rmsmc_populate_fun190(kk_function_t _fself, kk_box_t _b_159, kk_context_t* _ctx) {
  struct kk_sampling_dash_rmsmc_populate_fun190__t* _self = kk_function_as(struct kk_sampling_dash_rmsmc_populate_fun190__t*, _fself);
  kk_function_t model = _self->model; /* () -> <effects-and-types/score,effects-and-types/sample,effects-and-types/sample|122> 121 */
  kk_drop_match(_self, {kk_function_dup(model);}, {}, _ctx)
  kk_unit_t _x191 = kk_Unit;
  kk_unit_unbox(_b_159);
  return kk_sampling_dash_rmsmc__mlift125_populate(model, _x191, _ctx);
}
static kk_box_t kk_sampling_dash_rmsmc_populate_fun179(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_sampling_dash_rmsmc_populate_fun179__t* _self = kk_function_as(struct kk_sampling_dash_rmsmc_populate_fun179__t*, _fself);
  kk_integer_t k = _self->k; /* int */
  kk_function_t model = _self->model; /* () -> <effects-and-types/score,effects-and-types/sample,effects-and-types/sample|122> 121 */
  kk_drop_match(_self, {kk_integer_dup(k);kk_function_dup(model);}, {}, _ctx)
  kk_unit_t x_129 = kk_Unit;
  kk_effects_dash_and_dash_types__exp _x1;
  kk_effects_dash_and_dash_types__exp _x10 = kk_effects_dash_and_dash_types__new_Exp(0x0p+0, _ctx); /*effects-and-types/exp*/;
  kk_effects_dash_and_dash_types__exp _x2;
  double _x180;
  double _x181 = kk_integer_as_double(k,kk_context()); /*double*/
  _x180 = log(_x181); /*double*/
  _x2 = kk_effects_dash_and_dash_types__new_Exp(_x180, _ctx); /*effects-and-types/exp*/
  kk_box_t _x182 = kk_std_core_hnd__open_none2(kk_sampling_dash_rmsmc_new_populate_fun183(_ctx), kk_effects_dash_and_dash_types__exp_box(_x10, _ctx), kk_effects_dash_and_dash_types__exp_box(_x2, _ctx), _ctx); /*3*/
  _x1 = kk_effects_dash_and_dash_types__exp_unbox(_x182, _ctx); /*effects-and-types/exp*/
  size_t i0_131;
  kk_std_core_hnd__htag _x187 = kk_std_core_hnd__htag_dup(kk_effects_dash_and_dash_types__tag_score); /*std/core/hnd/htag<effects-and-types/.hnd-score>*/
  i0_131 = kk_std_core_hnd__evv_index(_x187, _ctx); /*std/core/hnd/ev-index*/
  kk_evv_t w = kk_evv_swap_create1(i0_131,kk_context()); /*std/core/hnd/evv<<effects-and-types/score,effects-and-types/sample,effects-and-types/sample|122>>*/;
  kk_unit_t y = kk_Unit;
  kk_effects_dash_and_dash_types_score(_x1, _ctx);
  kk_unit_t __w_l700_c9 = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x188 = kk_std_core_hnd_yield_cont(kk_sampling_dash_rmsmc_new_populate_fun189(i0_131, _ctx), _ctx); /*3*/
    kk_unit_unbox(_x188);
  }
  else {
    y;
  }
  if (kk_yielding(kk_context())) {
    return kk_std_core_hnd_yield_extend(kk_sampling_dash_rmsmc_new_populate_fun190(model, _ctx), _ctx);
  }
  return kk_sampling_dash_rmsmc__mlift125_populate(model, x_129, _ctx);
}
static kk_std_core_types__tuple2_ kk_sampling_dash_rmsmc_populate_fun177(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_sampling_dash_rmsmc_populate_fun177__t* _self = kk_function_as(struct kk_sampling_dash_rmsmc_populate_fun177__t*, _fself);
  kk_integer_t k = _self->k; /* int */
  kk_function_t model = _self->model; /* () -> <effects-and-types/score,effects-and-types/sample,effects-and-types/sample|122> 121 */
  kk_drop_match(_self, {kk_integer_dup(k);kk_function_dup(model);}, {}, _ctx)
  kk_effects_dash_and_dash_types__exp _x178 = kk_effects_dash_and_dash_types__new_Exp(0x0p+0, _ctx); /*effects-and-types/exp*/
  return kk_handlers_weighted(_x178, kk_sampling_dash_rmsmc_new_populate_fun179(k, model, _ctx), _ctx);
}
static kk_box_t kk_sampling_dash_rmsmc_populate_fun175(kk_function_t _fself, kk_integer_t _b_164, kk_context_t* _ctx) {
  struct kk_sampling_dash_rmsmc_populate_fun175__t* _self = kk_function_as(struct kk_sampling_dash_rmsmc_populate_fun175__t*, _fself);
  kk_integer_t k = _self->k; /* int */
  kk_function_t model = _self->model; /* () -> <effects-and-types/score,effects-and-types/sample,effects-and-types/sample|122> 121 */
  kk_drop_match(_self, {kk_integer_dup(k);kk_function_dup(model);}, {}, _ctx)
  kk_integer_drop(_b_164, _ctx);
  kk_std_core_types__tuple3_ _x176 = kk_handlers_recorder(kk_std_core__new_Nil(_ctx), kk_sampling_dash_rmsmc_new_populate_fun177(k, model, _ctx), _ctx); /*(effects-and-types/trace_values, 0, 1)*/
  return kk_std_core_types__tuple3__box(_x176, _ctx);
}

kk_std_core__list kk_sampling_dash_rmsmc_populate(kk_integer_t k, kk_function_t model, kk_context_t* _ctx) { /* forall<a,e> (k : int, model : () -> <effects-and-types/score,effects-and-types/sample,effects-and-types/sample|e> a) -> <effects-and-types/sample|e> effects-and-types/histogram_rmsmc<a> */ 
  kk_function_t _x174;
  kk_integer_dup(k);
  _x174 = kk_sampling_dash_rmsmc_new_populate_fun175(k, model, _ctx); /*(int) -> 2 1*/
  return kk_std_core__lift21054_list_1(_x174, kk_integer_from_small(1), k, kk_std_core__new_Nil(_ctx), _ctx);
}

// initialization
void kk_sampling_dash_rmsmc__init(kk_context_t* _ctx){
  static bool _initialized = false;
  if (_initialized) return;
  _initialized = true;
  kk_std_core_types__init(_ctx);
  kk_std_core_hnd__init(_ctx);
  kk_std_core__init(_ctx);
  kk_std_num_double__init(_ctx);
  kk_effects_dash_and_dash_types__init(_ctx);
  kk_exponents__init(_ctx);
  kk_handlers__init(_ctx);
}
