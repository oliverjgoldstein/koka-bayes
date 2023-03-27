// Koka generated module: "pmmh", koka version: 2.1.3
#include "pmmh.h"
 
// monadic lift

kk_box_t kk_pmmh__mlift117_new__model(kk_box_t params, kk_unit_t wild__, kk_context_t* _ctx) { /* forall<e,a> (params : a, wild_ : ()) -> <effects-and-types/score,div,exn,std/num/random/random,ndet,effects-and-types/sample|e> a */ 
  return params;
}
 
// monadic lift


// lift anonymous function
struct kk_pmmh__mlift118_new__model_fun262__t {
  struct kk_function_s _base;
  size_t i_124;
};
static kk_box_t kk_pmmh__mlift118_new__model_fun262(kk_function_t _fself, kk_function_t _b_168, kk_box_t _b_169, kk_context_t* _ctx);
static kk_function_t kk_pmmh__new_mlift118_new__model_fun262(size_t i_124, kk_context_t* _ctx) {
  struct kk_pmmh__mlift118_new__model_fun262__t* _self = kk_function_alloc_as(struct kk_pmmh__mlift118_new__model_fun262__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_pmmh__mlift118_new__model_fun262, kk_context());
  _self->i_124 = i_124;
  return &_self->_base;
}

static kk_box_t kk_pmmh__mlift118_new__model_fun262(kk_function_t _fself, kk_function_t _b_168, kk_box_t _b_169, kk_context_t* _ctx) {
  struct kk_pmmh__mlift118_new__model_fun262__t* _self = kk_function_as(struct kk_pmmh__mlift118_new__model_fun262__t*, _fself);
  size_t i_124 = _self->i_124; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_124, _b_168, _b_169, _ctx);
}


// lift anonymous function
struct kk_pmmh__mlift118_new__model_fun263__t {
  struct kk_function_s _base;
  kk_box_t params;
};
static kk_box_t kk_pmmh__mlift118_new__model_fun263(kk_function_t _fself, kk_box_t _b_179, kk_context_t* _ctx);
static kk_function_t kk_pmmh__new_mlift118_new__model_fun263(kk_box_t params, kk_context_t* _ctx) {
  struct kk_pmmh__mlift118_new__model_fun263__t* _self = kk_function_alloc_as(struct kk_pmmh__mlift118_new__model_fun263__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_pmmh__mlift118_new__model_fun263, kk_context());
  _self->params = params;
  return &_self->_base;
}

static kk_box_t kk_pmmh__mlift118_new__model_fun263(kk_function_t _fself, kk_box_t _b_179, kk_context_t* _ctx) {
  struct kk_pmmh__mlift118_new__model_fun263__t* _self = kk_function_as(struct kk_pmmh__mlift118_new__model_fun263__t*, _fself);
  kk_box_t params = _self->params; /* 79 */
  kk_drop_match(_self, {kk_box_dup(params);}, {}, _ctx)
  kk_unit_t _x264 = kk_Unit;
  kk_unit_unbox(_b_179);
  return kk_pmmh__mlift117_new__model(params, _x264, _ctx);
}

kk_box_t kk_pmmh__mlift118_new__model(kk_box_t params, kk_std_core__list smc__hist, kk_context_t* _ctx) { /* forall<e,a,b> (params : b, smc_hist : effects-and-types/histogram<a>) -> <pure,std/num/random/random,effects-and-types/score,ndet,effects-and-types/sample|e> b */ 
  kk_unit_t x_120 = kk_Unit;
  kk_effects_dash_and_dash_types__exp _x10;
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*std/core/hnd/evv<(<>)>*/;
  kk_effects_dash_and_dash_types__exp x0 = kk_sampling_sum__weights(smc__hist, _ctx); /*effects-and-types/exp*/;
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  _x10 = x0; /*effects-and-types/exp*/
  size_t i_124;
  kk_std_core_hnd__htag _x260 = kk_std_core_hnd__htag_dup(kk_effects_dash_and_dash_types__tag_score); /*std/core/hnd/htag<effects-and-types/.hnd-score>*/
  i_124 = kk_std_core_hnd__evv_index(_x260, _ctx); /*std/core/hnd/ev-index*/
  kk_evv_t w0 = kk_evv_swap_create1(i_124,kk_context()); /*std/core/hnd/evv<<effects-and-types/score,div,exn,std/num/random/random,ndet,effects-and-types/sample|62>>*/;
  kk_unit_t y = kk_Unit;
  kk_effects_dash_and_dash_types_score(_x10, _ctx);
  kk_unit_t __w_l700_c9 = kk_Unit;
  kk_evv_set(w0,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x261 = kk_std_core_hnd_yield_cont(kk_pmmh__new_mlift118_new__model_fun262(i_124, _ctx), _ctx); /*3*/
    kk_unit_unbox(_x261);
  }
  else {
    y;
  }
  if (kk_yielding(kk_context())) {
    return kk_std_core_hnd_yield_extend(kk_pmmh__new_mlift118_new__model_fun263(params, _ctx), _ctx);
  }
  return kk_pmmh__mlift117_new__model(params, x_120, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_pmmh__mlift119_new__model_fun266__t {
  struct kk_function_s _base;
  kk_function_t main__model;
};
static kk_box_t kk_pmmh__mlift119_new__model_fun266(kk_function_t _fself, kk_box_t _b_184, kk_context_t* _ctx);
static kk_function_t kk_pmmh__new_mlift119_new__model_fun266(kk_function_t main__model, kk_context_t* _ctx) {
  struct kk_pmmh__mlift119_new__model_fun266__t* _self = kk_function_alloc_as(struct kk_pmmh__mlift119_new__model_fun266__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_pmmh__mlift119_new__model_fun266, kk_context());
  _self->main__model = main__model;
  return &_self->_base;
}

static kk_box_t kk_pmmh__mlift119_new__model_fun266(kk_function_t _fself, kk_box_t _b_184, kk_context_t* _ctx) {
  struct kk_pmmh__mlift119_new__model_fun266__t* _self = kk_function_as(struct kk_pmmh__mlift119_new__model_fun266__t*, _fself);
  kk_function_t main__model = _self->main__model; /* (79) -> effects-and-types/model<78,<div,exn,std/num/random/random,effects-and-types/yield,effects-and-types/score,ndet,effects-and-types/sample|62>> */
  kk_drop_match(_self, {kk_function_dup(main__model);}, {}, _ctx)
  kk_function_t _x267 = kk_function_call(kk_function_t, (kk_function_t, kk_box_t, kk_context_t*), main__model, (main__model, _b_184, _ctx)); /*effects-and-types/model<78,<div,exn,std/num/random/random,effects-and-types/yield,effects-and-types/score,ndet,effects-and-types/sample|62>>*/
  return kk_function_box(_x267);
}


// lift anonymous function
struct kk_pmmh__mlift119_new__model_fun270__t {
  struct kk_function_s _base;
  kk_function_t model_132;
  kk_integer_t particle__num;
  kk_integer_t step__num;
};
static kk_box_t kk_pmmh__mlift119_new__model_fun270(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_pmmh__new_mlift119_new__model_fun270(kk_function_t model_132, kk_integer_t particle__num, kk_integer_t step__num, kk_context_t* _ctx) {
  struct kk_pmmh__mlift119_new__model_fun270__t* _self = kk_function_alloc_as(struct kk_pmmh__mlift119_new__model_fun270__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_pmmh__mlift119_new__model_fun270, kk_context());
  _self->model_132 = model_132;
  _self->particle__num = particle__num;
  _self->step__num = step__num;
  return &_self->_base;
}



// lift anonymous function
struct kk_pmmh__mlift119_new__model_fun272__t {
  struct kk_function_s _base;
  kk_function_t model_132;
};
static kk_box_t kk_pmmh__mlift119_new__model_fun272(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_pmmh__new_mlift119_new__model_fun272(kk_function_t model_132, kk_context_t* _ctx) {
  struct kk_pmmh__mlift119_new__model_fun272__t* _self = kk_function_alloc_as(struct kk_pmmh__mlift119_new__model_fun272__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_pmmh__mlift119_new__model_fun272, kk_context());
  _self->model_132 = model_132;
  return &_self->_base;
}



// lift anonymous function
struct kk_pmmh__mlift119_new__model_fun274__t {
  struct kk_function_s _base;
  kk_function_t model_132;
};
static kk_box_t kk_pmmh__mlift119_new__model_fun274(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_pmmh__new_mlift119_new__model_fun274(kk_function_t model_132, kk_context_t* _ctx) {
  struct kk_pmmh__mlift119_new__model_fun274__t* _self = kk_function_alloc_as(struct kk_pmmh__mlift119_new__model_fun274__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_pmmh__mlift119_new__model_fun274, kk_context());
  _self->model_132 = model_132;
  return &_self->_base;
}

static kk_box_t kk_pmmh__mlift119_new__model_fun274(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_pmmh__mlift119_new__model_fun274__t* _self = kk_function_as(struct kk_pmmh__mlift119_new__model_fun274__t*, _fself);
  kk_function_t model_132 = _self->model_132; /* () -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random,effects-and-types/score,ndet,effects-and-types/sample|62> 78 */
  kk_drop_match(_self, {kk_function_dup(model_132);}, {}, _ctx)
  return kk_handlers_yield__on__score(model_132, _ctx);
}


// lift anonymous function
struct kk_pmmh__mlift119_new__model_fun275__t {
  struct kk_function_s _base;
  kk_function_t _bv_193;
};
static kk_box_t kk_pmmh__mlift119_new__model_fun275(kk_function_t _fself, kk_box_t _b_194, kk_context_t* _ctx);
static kk_function_t kk_pmmh__new_mlift119_new__model_fun275(kk_function_t _bv_193, kk_context_t* _ctx) {
  struct kk_pmmh__mlift119_new__model_fun275__t* _self = kk_function_alloc_as(struct kk_pmmh__mlift119_new__model_fun275__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_pmmh__mlift119_new__model_fun275, kk_context());
  _self->_bv_193 = _bv_193;
  return &_self->_base;
}

static kk_box_t kk_pmmh__mlift119_new__model_fun275(kk_function_t _fself, kk_box_t _b_194, kk_context_t* _ctx) {
  struct kk_pmmh__mlift119_new__model_fun275__t* _self = kk_function_as(struct kk_pmmh__mlift119_new__model_fun275__t*, _fself);
  kk_function_t _bv_193 = _self->_bv_193; /* (a : int) -> <effects-and-types/yield,effects-and-types/sample,effects-and-types/score,div,exn,std/num/random/random,effects-and-types/score,ndet,effects-and-types/sample|62> 78 */
  kk_drop_match(_self, {kk_function_dup(_bv_193);}, {}, _ctx)
  kk_integer_t _x276 = kk_integer_unbox(_b_194); /*int*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_context_t*), _bv_193, (_bv_193, _x276, _ctx));
}
static kk_box_t kk_pmmh__mlift119_new__model_fun272(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_pmmh__mlift119_new__model_fun272__t* _self = kk_function_as(struct kk_pmmh__mlift119_new__model_fun272__t*, _fself);
  kk_function_t model_132 = _self->model_132; /* () -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random,effects-and-types/score,ndet,effects-and-types/sample|62> 78 */
  kk_drop_match(_self, {kk_function_dup(model_132);}, {}, _ctx)
  kk_function_t _x273;
  kk_function_t _bv_193 = kk_handlers_advance(kk_pmmh__new_mlift119_new__model_fun274(model_132, _ctx), _ctx); /*(a : int) -> <effects-and-types/yield,effects-and-types/sample,effects-and-types/score,div,exn,std/num/random/random,effects-and-types/score,ndet,effects-and-types/sample|62> 78*/;
  _x273 = kk_pmmh__new_mlift119_new__model_fun275(_bv_193, _ctx); /*(191) -> <effects-and-types/yield,effects-and-types/sample,effects-and-types/score,div,exn,std/num/random/random,effects-and-types/score,ndet,effects-and-types/sample|62> 78*/
  return kk_function_box(_x273);
}


// lift anonymous function
struct kk_pmmh__mlift119_new__model_fun278__t {
  struct kk_function_s _base;
  kk_integer_t step__num;
};
static kk_box_t kk_pmmh__mlift119_new__model_fun278(kk_function_t _fself, kk_box_t _b_198, kk_context_t* _ctx);
static kk_function_t kk_pmmh__new_mlift119_new__model_fun278(kk_integer_t step__num, kk_context_t* _ctx) {
  struct kk_pmmh__mlift119_new__model_fun278__t* _self = kk_function_alloc_as(struct kk_pmmh__mlift119_new__model_fun278__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_pmmh__mlift119_new__model_fun278, kk_context());
  _self->step__num = step__num;
  return &_self->_base;
}

static kk_box_t kk_pmmh__mlift119_new__model_fun278(kk_function_t _fself, kk_box_t _b_198, kk_context_t* _ctx) {
  struct kk_pmmh__mlift119_new__model_fun278__t* _self = kk_function_as(struct kk_pmmh__mlift119_new__model_fun278__t*, _fself);
  kk_integer_t step__num = _self->step__num; /* int */
  kk_drop_match(_self, {kk_integer_dup(step__num);}, {}, _ctx)
  kk_std_core__list _x279;
  kk_std_core__list _x280 = kk_std_core__list_unbox(_b_198, _ctx); /*effects-and-types/histogram<(a : int) -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random,effects-and-types/score,ndet,effects-and-types/sample|62> 78>*/
  _x279 = kk_smc__mlift743_smc(false, step__num, kk_integer_from_small(1), _x280, _ctx); /*effects-and-types/histogram<24>*/
  return kk_std_core__list_box(_x279, _ctx);
}
static kk_box_t kk_pmmh__mlift119_new__model_fun270(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_pmmh__mlift119_new__model_fun270__t* _self = kk_function_as(struct kk_pmmh__mlift119_new__model_fun270__t*, _fself);
  kk_function_t model_132 = _self->model_132; /* () -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random,effects-and-types/score,ndet,effects-and-types/sample|62> 78 */
  kk_integer_t particle__num = _self->particle__num; /* int */
  kk_integer_t step__num = _self->step__num; /* int */
  kk_drop_match(_self, {kk_function_dup(model_132);kk_integer_dup(particle__num);kk_integer_dup(step__num);}, {}, _ctx)
  kk_std_core__list _x271;
  kk_std_core__list x_775 = kk_sampling_populate(particle__num, kk_pmmh__new_mlift119_new__model_fun272(model_132, _ctx), _ctx); /*effects-and-types/histogram<(a : int) -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random,effects-and-types/score,ndet,effects-and-types/sample|62> 78>*/;
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_775, _ctx);
    kk_box_t _x277 = kk_std_core_hnd_yield_extend(kk_pmmh__new_mlift119_new__model_fun278(step__num, _ctx), _ctx); /*2*/
    _x271 = kk_std_core__list_unbox(_x277, _ctx); /*effects-and-types/histogram<78>*/
  }
  else {
    _x271 = kk_smc__mlift743_smc(false, step__num, kk_integer_from_small(1), x_775, _ctx); /*effects-and-types/histogram<78>*/
  }
  return kk_std_core__list_box(_x271, _ctx);
}


// lift anonymous function
struct kk_pmmh__mlift119_new__model_fun281__t {
  struct kk_function_s _base;
  kk_box_t params;
};
static kk_box_t kk_pmmh__mlift119_new__model_fun281(kk_function_t _fself, kk_box_t _b_204, kk_context_t* _ctx);
static kk_function_t kk_pmmh__new_mlift119_new__model_fun281(kk_box_t params, kk_context_t* _ctx) {
  struct kk_pmmh__mlift119_new__model_fun281__t* _self = kk_function_alloc_as(struct kk_pmmh__mlift119_new__model_fun281__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_pmmh__mlift119_new__model_fun281, kk_context());
  _self->params = params;
  return &_self->_base;
}

static kk_box_t kk_pmmh__mlift119_new__model_fun281(kk_function_t _fself, kk_box_t _b_204, kk_context_t* _ctx) {
  struct kk_pmmh__mlift119_new__model_fun281__t* _self = kk_function_as(struct kk_pmmh__mlift119_new__model_fun281__t*, _fself);
  kk_box_t params = _self->params; /* 79 */
  kk_drop_match(_self, {kk_box_dup(params);}, {}, _ctx)
  kk_std_core__list _x282 = kk_std_core__list_unbox(_b_204, _ctx); /*effects-and-types/histogram<78>*/
  return kk_pmmh__mlift118_new__model(params, _x282, _ctx);
}

kk_box_t kk_pmmh__mlift119_new__model(kk_function_t main__model, kk_integer_t particle__num, kk_integer_t step__num, kk_box_t params, kk_context_t* _ctx) { /* forall<e,a,b> (main_model : (b) -> effects-and-types/model<a,<div,exn,std/num/random/random,effects-and-types/yield,effects-and-types/score,ndet,effects-and-types/sample|e>>, particle_num : int, step_num : int, params : b) -> <effects-and-types/sample,effects-and-types/score,pure,ndet,std/num/random/random|e> b */ 
  kk_std_core__list x_127;
  kk_function_t model_132;
  kk_box_t _x265;
  kk_box_t _x268 = kk_box_dup(params); /*79*/
  _x265 = kk_std_core_hnd__open_none1(kk_pmmh__new_mlift119_new__model_fun266(main__model, _ctx), _x268, _ctx); /*2*/
  model_132 = kk_function_unbox(_x265); /*() -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random,effects-and-types/score,ndet,effects-and-types/sample|62> 78*/
  kk_box_t _x269 = kk_handlers_random__sampler(kk_pmmh__new_mlift119_new__model_fun270(model_132, particle__num, step__num, _ctx), _ctx); /*0*/
  x_127 = kk_std_core__list_unbox(_x269, _ctx); /*effects-and-types/histogram<78>*/
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_127, _ctx);
    return kk_std_core_hnd_yield_extend(kk_pmmh__new_mlift119_new__model_fun281(params, _ctx), _ctx);
  }
  return kk_pmmh__mlift118_new__model(params, x_127, _ctx);
}


// lift anonymous function
struct kk_pmmh_new__model_fun283__t {
  struct kk_function_s _base;
  kk_function_t main__model;
  kk_function_t param__model;
  kk_integer_t particle__num;
  kk_integer_t step__num;
};
static kk_box_t kk_pmmh_new__model_fun283(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_pmmh_new_new__model_fun283(kk_function_t main__model, kk_function_t param__model, kk_integer_t particle__num, kk_integer_t step__num, kk_context_t* _ctx) {
  struct kk_pmmh_new__model_fun283__t* _self = kk_function_alloc_as(struct kk_pmmh_new__model_fun283__t, 5, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_pmmh_new__model_fun283, kk_context());
  _self->main__model = main__model;
  _self->param__model = param__model;
  _self->particle__num = particle__num;
  _self->step__num = step__num;
  return &_self->_base;
}



// lift anonymous function
struct kk_pmmh_new__model_fun284__t {
  struct kk_function_s _base;
  kk_function_t main__model;
  kk_integer_t particle__num;
  kk_integer_t step__num;
};
static kk_box_t kk_pmmh_new__model_fun284(kk_function_t _fself, kk_box_t params, kk_context_t* _ctx);
static kk_function_t kk_pmmh_new_new__model_fun284(kk_function_t main__model, kk_integer_t particle__num, kk_integer_t step__num, kk_context_t* _ctx) {
  struct kk_pmmh_new__model_fun284__t* _self = kk_function_alloc_as(struct kk_pmmh_new__model_fun284__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_pmmh_new__model_fun284, kk_context());
  _self->main__model = main__model;
  _self->particle__num = particle__num;
  _self->step__num = step__num;
  return &_self->_base;
}

static kk_box_t kk_pmmh_new__model_fun284(kk_function_t _fself, kk_box_t params, kk_context_t* _ctx) {
  struct kk_pmmh_new__model_fun284__t* _self = kk_function_as(struct kk_pmmh_new__model_fun284__t*, _fself);
  kk_function_t main__model = _self->main__model; /* (79) -> effects-and-types/model<78,<div,exn,std/num/random/random,effects-and-types/yield,effects-and-types/score,ndet,effects-and-types/sample|62>> */
  kk_integer_t particle__num = _self->particle__num; /* int */
  kk_integer_t step__num = _self->step__num; /* int */
  kk_drop_match(_self, {kk_function_dup(main__model);kk_integer_dup(particle__num);kk_integer_dup(step__num);}, {}, _ctx)
  return kk_pmmh__mlift119_new__model(main__model, particle__num, step__num, params, _ctx);
}


// lift anonymous function
struct kk_pmmh_new__model_fun286__t {
  struct kk_function_s _base;
  kk_function_t main__model;
};
static kk_box_t kk_pmmh_new__model_fun286(kk_function_t _fself, kk_box_t _b_209, kk_context_t* _ctx);
static kk_function_t kk_pmmh_new_new__model_fun286(kk_function_t main__model, kk_context_t* _ctx) {
  struct kk_pmmh_new__model_fun286__t* _self = kk_function_alloc_as(struct kk_pmmh_new__model_fun286__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_pmmh_new__model_fun286, kk_context());
  _self->main__model = main__model;
  return &_self->_base;
}

static kk_box_t kk_pmmh_new__model_fun286(kk_function_t _fself, kk_box_t _b_209, kk_context_t* _ctx) {
  struct kk_pmmh_new__model_fun286__t* _self = kk_function_as(struct kk_pmmh_new__model_fun286__t*, _fself);
  kk_function_t main__model = _self->main__model; /* (79) -> effects-and-types/model<78,<div,exn,std/num/random/random,effects-and-types/yield,effects-and-types/score,ndet,effects-and-types/sample|62>> */
  kk_drop_match(_self, {kk_function_dup(main__model);}, {}, _ctx)
  kk_function_t _x287 = kk_function_call(kk_function_t, (kk_function_t, kk_box_t, kk_context_t*), main__model, (main__model, _b_209, _ctx)); /*effects-and-types/model<78,<div,exn,std/num/random/random,effects-and-types/yield,effects-and-types/score,ndet,effects-and-types/sample|62>>*/
  return kk_function_box(_x287);
}


// lift anonymous function
struct kk_pmmh_new__model_fun290__t {
  struct kk_function_s _base;
  kk_function_t model_144;
  kk_integer_t particle__num;
  kk_integer_t step__num;
};
static kk_box_t kk_pmmh_new__model_fun290(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_pmmh_new_new__model_fun290(kk_function_t model_144, kk_integer_t particle__num, kk_integer_t step__num, kk_context_t* _ctx) {
  struct kk_pmmh_new__model_fun290__t* _self = kk_function_alloc_as(struct kk_pmmh_new__model_fun290__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_pmmh_new__model_fun290, kk_context());
  _self->model_144 = model_144;
  _self->particle__num = particle__num;
  _self->step__num = step__num;
  return &_self->_base;
}



// lift anonymous function
struct kk_pmmh_new__model_fun292__t {
  struct kk_function_s _base;
  kk_function_t model_144;
};
static kk_box_t kk_pmmh_new__model_fun292(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_pmmh_new_new__model_fun292(kk_function_t model_144, kk_context_t* _ctx) {
  struct kk_pmmh_new__model_fun292__t* _self = kk_function_alloc_as(struct kk_pmmh_new__model_fun292__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_pmmh_new__model_fun292, kk_context());
  _self->model_144 = model_144;
  return &_self->_base;
}



// lift anonymous function
struct kk_pmmh_new__model_fun294__t {
  struct kk_function_s _base;
  kk_function_t model_144;
};
static kk_box_t kk_pmmh_new__model_fun294(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_pmmh_new_new__model_fun294(kk_function_t model_144, kk_context_t* _ctx) {
  struct kk_pmmh_new__model_fun294__t* _self = kk_function_alloc_as(struct kk_pmmh_new__model_fun294__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_pmmh_new__model_fun294, kk_context());
  _self->model_144 = model_144;
  return &_self->_base;
}

static kk_box_t kk_pmmh_new__model_fun294(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_pmmh_new__model_fun294__t* _self = kk_function_as(struct kk_pmmh_new__model_fun294__t*, _fself);
  kk_function_t model_144 = _self->model_144; /* () -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random,effects-and-types/score,ndet,effects-and-types/sample|62> 78 */
  kk_drop_match(_self, {kk_function_dup(model_144);}, {}, _ctx)
  return kk_handlers_yield__on__score(model_144, _ctx);
}


// lift anonymous function
struct kk_pmmh_new__model_fun295__t {
  struct kk_function_s _base;
  kk_function_t _bv_218;
};
static kk_box_t kk_pmmh_new__model_fun295(kk_function_t _fself, kk_box_t _b_219, kk_context_t* _ctx);
static kk_function_t kk_pmmh_new_new__model_fun295(kk_function_t _bv_218, kk_context_t* _ctx) {
  struct kk_pmmh_new__model_fun295__t* _self = kk_function_alloc_as(struct kk_pmmh_new__model_fun295__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_pmmh_new__model_fun295, kk_context());
  _self->_bv_218 = _bv_218;
  return &_self->_base;
}

static kk_box_t kk_pmmh_new__model_fun295(kk_function_t _fself, kk_box_t _b_219, kk_context_t* _ctx) {
  struct kk_pmmh_new__model_fun295__t* _self = kk_function_as(struct kk_pmmh_new__model_fun295__t*, _fself);
  kk_function_t _bv_218 = _self->_bv_218; /* (a : int) -> <effects-and-types/yield,effects-and-types/sample,effects-and-types/score,div,exn,std/num/random/random,effects-and-types/score,ndet,effects-and-types/sample|62> 78 */
  kk_drop_match(_self, {kk_function_dup(_bv_218);}, {}, _ctx)
  kk_integer_t _x296 = kk_integer_unbox(_b_219); /*int*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_context_t*), _bv_218, (_bv_218, _x296, _ctx));
}
static kk_box_t kk_pmmh_new__model_fun292(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_pmmh_new__model_fun292__t* _self = kk_function_as(struct kk_pmmh_new__model_fun292__t*, _fself);
  kk_function_t model_144 = _self->model_144; /* () -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random,effects-and-types/score,ndet,effects-and-types/sample|62> 78 */
  kk_drop_match(_self, {kk_function_dup(model_144);}, {}, _ctx)
  kk_function_t _x293;
  kk_function_t _bv_218 = kk_handlers_advance(kk_pmmh_new_new__model_fun294(model_144, _ctx), _ctx); /*(a : int) -> <effects-and-types/yield,effects-and-types/sample,effects-and-types/score,div,exn,std/num/random/random,effects-and-types/score,ndet,effects-and-types/sample|62> 78*/;
  _x293 = kk_pmmh_new_new__model_fun295(_bv_218, _ctx); /*(216) -> <effects-and-types/yield,effects-and-types/sample,effects-and-types/score,div,exn,std/num/random/random,effects-and-types/score,ndet,effects-and-types/sample|62> 78*/
  return kk_function_box(_x293);
}


// lift anonymous function
struct kk_pmmh_new__model_fun298__t {
  struct kk_function_s _base;
  kk_integer_t step__num;
};
static kk_box_t kk_pmmh_new__model_fun298(kk_function_t _fself, kk_box_t _b_223, kk_context_t* _ctx);
static kk_function_t kk_pmmh_new_new__model_fun298(kk_integer_t step__num, kk_context_t* _ctx) {
  struct kk_pmmh_new__model_fun298__t* _self = kk_function_alloc_as(struct kk_pmmh_new__model_fun298__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_pmmh_new__model_fun298, kk_context());
  _self->step__num = step__num;
  return &_self->_base;
}

static kk_box_t kk_pmmh_new__model_fun298(kk_function_t _fself, kk_box_t _b_223, kk_context_t* _ctx) {
  struct kk_pmmh_new__model_fun298__t* _self = kk_function_as(struct kk_pmmh_new__model_fun298__t*, _fself);
  kk_integer_t step__num = _self->step__num; /* int */
  kk_drop_match(_self, {kk_integer_dup(step__num);}, {}, _ctx)
  kk_std_core__list _x299;
  kk_std_core__list _x300 = kk_std_core__list_unbox(_b_223, _ctx); /*effects-and-types/histogram<(a : int) -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random,effects-and-types/score,ndet,effects-and-types/sample|62> 78>*/
  _x299 = kk_smc__mlift743_smc(false, step__num, kk_integer_from_small(1), _x300, _ctx); /*effects-and-types/histogram<24>*/
  return kk_std_core__list_box(_x299, _ctx);
}
static kk_box_t kk_pmmh_new__model_fun290(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_pmmh_new__model_fun290__t* _self = kk_function_as(struct kk_pmmh_new__model_fun290__t*, _fself);
  kk_function_t model_144 = _self->model_144; /* () -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random,effects-and-types/score,ndet,effects-and-types/sample|62> 78 */
  kk_integer_t particle__num = _self->particle__num; /* int */
  kk_integer_t step__num = _self->step__num; /* int */
  kk_drop_match(_self, {kk_function_dup(model_144);kk_integer_dup(particle__num);kk_integer_dup(step__num);}, {}, _ctx)
  kk_std_core__list _x291;
  kk_std_core__list x_775 = kk_sampling_populate(particle__num, kk_pmmh_new_new__model_fun292(model_144, _ctx), _ctx); /*effects-and-types/histogram<(a : int) -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random,effects-and-types/score,ndet,effects-and-types/sample|62> 78>*/;
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_775, _ctx);
    kk_box_t _x297 = kk_std_core_hnd_yield_extend(kk_pmmh_new_new__model_fun298(step__num, _ctx), _ctx); /*2*/
    _x291 = kk_std_core__list_unbox(_x297, _ctx); /*effects-and-types/histogram<78>*/
  }
  else {
    _x291 = kk_smc__mlift743_smc(false, step__num, kk_integer_from_small(1), x_775, _ctx); /*effects-and-types/histogram<78>*/
  }
  return kk_std_core__list_box(_x291, _ctx);
}


// lift anonymous function
struct kk_pmmh_new__model_fun301__t {
  struct kk_function_s _base;
  kk_box_t x_134;
};
static kk_box_t kk_pmmh_new__model_fun301(kk_function_t _fself, kk_box_t _b_229, kk_context_t* _ctx);
static kk_function_t kk_pmmh_new_new__model_fun301(kk_box_t x_134, kk_context_t* _ctx) {
  struct kk_pmmh_new__model_fun301__t* _self = kk_function_alloc_as(struct kk_pmmh_new__model_fun301__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_pmmh_new__model_fun301, kk_context());
  _self->x_134 = x_134;
  return &_self->_base;
}

static kk_box_t kk_pmmh_new__model_fun301(kk_function_t _fself, kk_box_t _b_229, kk_context_t* _ctx) {
  struct kk_pmmh_new__model_fun301__t* _self = kk_function_as(struct kk_pmmh_new__model_fun301__t*, _fself);
  kk_box_t x_134 = _self->x_134; /* 79 */
  kk_drop_match(_self, {kk_box_dup(x_134);}, {}, _ctx)
  kk_std_core__list _x302 = kk_std_core__list_unbox(_b_229, _ctx); /*effects-and-types/histogram<78>*/
  return kk_pmmh__mlift118_new__model(x_134, _x302, _ctx);
}


// lift anonymous function
struct kk_pmmh_new__model_fun305__t {
  struct kk_function_s _base;
  size_t i_152;
};
static kk_box_t kk_pmmh_new__model_fun305(kk_function_t _fself, kk_function_t _b_235, kk_box_t _b_236, kk_context_t* _ctx);
static kk_function_t kk_pmmh_new_new__model_fun305(size_t i_152, kk_context_t* _ctx) {
  struct kk_pmmh_new__model_fun305__t* _self = kk_function_alloc_as(struct kk_pmmh_new__model_fun305__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_pmmh_new__model_fun305, kk_context());
  _self->i_152 = i_152;
  return &_self->_base;
}

static kk_box_t kk_pmmh_new__model_fun305(kk_function_t _fself, kk_function_t _b_235, kk_box_t _b_236, kk_context_t* _ctx) {
  struct kk_pmmh_new__model_fun305__t* _self = kk_function_as(struct kk_pmmh_new__model_fun305__t*, _fself);
  size_t i_152 = _self->i_152; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_152, _b_235, _b_236, _ctx);
}


// lift anonymous function
struct kk_pmmh_new__model_fun306__t {
  struct kk_function_s _base;
  kk_box_t x_134;
};
static kk_box_t kk_pmmh_new__model_fun306(kk_function_t _fself, kk_box_t _b_246, kk_context_t* _ctx);
static kk_function_t kk_pmmh_new_new__model_fun306(kk_box_t x_134, kk_context_t* _ctx) {
  struct kk_pmmh_new__model_fun306__t* _self = kk_function_alloc_as(struct kk_pmmh_new__model_fun306__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_pmmh_new__model_fun306, kk_context());
  _self->x_134 = x_134;
  return &_self->_base;
}

static kk_box_t kk_pmmh_new__model_fun306(kk_function_t _fself, kk_box_t _b_246, kk_context_t* _ctx) {
  struct kk_pmmh_new__model_fun306__t* _self = kk_function_as(struct kk_pmmh_new__model_fun306__t*, _fself);
  kk_box_t x_134 = _self->x_134; /* 79 */
  kk_drop_match(_self, {kk_box_dup(x_134);}, {}, _ctx)
  kk_unit_t _x307 = kk_Unit;
  kk_unit_unbox(_b_246);
  return kk_pmmh__mlift117_new__model(x_134, _x307, _ctx);
}
static kk_box_t kk_pmmh_new__model_fun283(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_pmmh_new__model_fun283__t* _self = kk_function_as(struct kk_pmmh_new__model_fun283__t*, _fself);
  kk_function_t main__model = _self->main__model; /* (79) -> effects-and-types/model<78,<div,exn,std/num/random/random,effects-and-types/yield,effects-and-types/score,ndet,effects-and-types/sample|62>> */
  kk_function_t param__model = _self->param__model; /* effects-and-types/model<79,<pure,ndet,std/num/random/random|62>> */
  kk_integer_t particle__num = _self->particle__num; /* int */
  kk_integer_t step__num = _self->step__num; /* int */
  kk_drop_match(_self, {kk_function_dup(main__model);kk_function_dup(param__model);kk_integer_dup(particle__num);kk_integer_dup(step__num);}, {}, _ctx)
  kk_box_t x_134 = kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), param__model, (param__model, _ctx)); /*79*/;
  if (kk_yielding(kk_context())) {
    kk_box_drop(x_134, _ctx);
    return kk_std_core_hnd_yield_extend(kk_pmmh_new_new__model_fun284(main__model, particle__num, step__num, _ctx), _ctx);
  }
  kk_std_core__list x0_138;
  kk_function_t model_144;
  kk_box_t _x285;
  kk_box_t _x288 = kk_box_dup(x_134); /*79*/
  _x285 = kk_std_core_hnd__open_none1(kk_pmmh_new_new__model_fun286(main__model, _ctx), _x288, _ctx); /*2*/
  model_144 = kk_function_unbox(_x285); /*() -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random,effects-and-types/score,ndet,effects-and-types/sample|62> 78*/
  kk_box_t _x289 = kk_handlers_random__sampler(kk_pmmh_new_new__model_fun290(model_144, particle__num, step__num, _ctx), _ctx); /*0*/
  x0_138 = kk_std_core__list_unbox(_x289, _ctx); /*effects-and-types/histogram<78>*/
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x0_138, _ctx);
    return kk_std_core_hnd_yield_extend(kk_pmmh_new_new__model_fun301(x_134, _ctx), _ctx);
  }
  kk_unit_t x1_147 = kk_Unit;
  kk_effects_dash_and_dash_types__exp _x10;
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*std/core/hnd/evv<(<>)>*/;
  kk_effects_dash_and_dash_types__exp x2 = kk_sampling_sum__weights(x0_138, _ctx); /*effects-and-types/exp*/;
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  _x10 = x2; /*effects-and-types/exp*/
  size_t i_152;
  kk_std_core_hnd__htag _x303 = kk_std_core_hnd__htag_dup(kk_effects_dash_and_dash_types__tag_score); /*std/core/hnd/htag<effects-and-types/.hnd-score>*/
  i_152 = kk_std_core_hnd__evv_index(_x303, _ctx); /*std/core/hnd/ev-index*/
  kk_evv_t w0 = kk_evv_swap_create1(i_152,kk_context()); /*std/core/hnd/evv<<effects-and-types/score,div,exn,std/num/random/random,ndet,effects-and-types/sample|62>>*/;
  kk_unit_t y = kk_Unit;
  kk_effects_dash_and_dash_types_score(_x10, _ctx);
  kk_unit_t __w_l700_c9 = kk_Unit;
  kk_evv_set(w0,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x304 = kk_std_core_hnd_yield_cont(kk_pmmh_new_new__model_fun305(i_152, _ctx), _ctx); /*3*/
    kk_unit_unbox(_x304);
  }
  else {
    y;
  }
  if (kk_yielding(kk_context())) {
    return kk_std_core_hnd_yield_extend(kk_pmmh_new_new__model_fun306(x_134, _ctx), _ctx);
  }
  return x_134;
}

kk_function_t kk_pmmh_new__model(kk_function_t param__model, kk_function_t main__model, kk_integer_t particle__num, kk_integer_t step__num, kk_context_t* _ctx) { /* forall<a,b,e> (param_model : effects-and-types/model<a,<pure,ndet,std/num/random/random|e>>, main_model : (a) -> effects-and-types/model<b,<div,exn,std/num/random/random,effects-and-types/yield,effects-and-types/score,ndet,effects-and-types/sample|e>>, particle_num : int, step_num : int) -> effects-and-types/model<a,<pure,ndet,std/num/random/random|e>> */ 
  return kk_pmmh_new_new__model_fun283(main__model, param__model, particle__num, step__num, _ctx);
}

// initialization
void kk_pmmh__init(kk_context_t* _ctx){
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
  kk_smc__init(_ctx);
  kk_tmcmc__init(_ctx);
}
