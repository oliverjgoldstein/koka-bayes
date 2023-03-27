// Koka generated module: "bug-test4", koka version: 2.1.3
#include "bug_dash_test4.h"

kk_std_core__list kk_bug_dash_test4_rmsmc__loop(kk_integer_t a, kk_integer_t composition__1, kk_integer_t i, kk_integer_t smc__step__num, kk_integer_t mh__step__num, kk_integer_t step__size, bool normalize, kk_context_t* _ctx) { /* forall<a> (a : int, composition_1 : int, i : int, smc_step_num : int, mh_step_num : int, step_size : int, normalize : bool) -> <pure,effects-and-types/sample> effects-and-types/histogram_rmsmc<a> */ 
  kk__tailcall: ;
  if (normalize) {
    { // tailcall
      kk_integer_t _x218 = kk_integer_add(i,(kk_integer_from_small(1)),kk_context()); /*int*/
      i = _x218;
      goto kk__tailcall;
    }
  }
  { // tailcall
    kk_integer_t _x219 = kk_integer_add(i,(kk_integer_from_small(1)),kk_context()); /*int*/
    i = _x219;
    goto kk__tailcall;
  }
}
 
// monadic lift


// lift anonymous function
struct kk_bug_dash_test4__mlift178_rmsmc_fun220__t {
  struct kk_function_s _base;
  kk_function_t model;
};
static kk_box_t kk_bug_dash_test4__mlift178_rmsmc_fun220(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_bug_dash_test4__new_mlift178_rmsmc_fun220(kk_function_t model, kk_context_t* _ctx) {
  struct kk_bug_dash_test4__mlift178_rmsmc_fun220__t* _self = kk_function_alloc_as(struct kk_bug_dash_test4__mlift178_rmsmc_fun220__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_bug_dash_test4__mlift178_rmsmc_fun220, kk_context());
  _self->model = model;
  return &_self->_base;
}

static kk_box_t kk_bug_dash_test4__mlift178_rmsmc_fun220(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_bug_dash_test4__mlift178_rmsmc_fun220__t* _self = kk_function_as(struct kk_bug_dash_test4__mlift178_rmsmc_fun220__t*, _fself);
  kk_function_t model = _self->model; /* () -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random|169> 18 */
  kk_drop_match(_self, {kk_function_dup(model);}, {}, _ctx)
  return kk_handlers_yield__on__score(model, _ctx);
}

kk_function_t kk_bug_dash_test4__mlift178_rmsmc(kk_function_t model, kk_std_core__list wild__, kk_context_t* _ctx) { /* forall<a,_b,e> (model : () -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random|e> a, wild_ : effects-and-types/histogram_rmsmc<_b>) -> <div,exn,effects-and-types/sample,effects-and-types/score,std/num/random/random|e> ((a : int) -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random|e> a) */ 
  kk_std_core__list_drop(wild__, _ctx);
  return kk_handlers_advance(kk_bug_dash_test4__new_mlift178_rmsmc_fun220(model, _ctx), _ctx);
}


// lift anonymous function
struct kk_bug_dash_test4_rmsmc_fun222__t {
  struct kk_function_s _base;
  kk_integer_t mh__step__num;
  kk_function_t model;
  kk_integer_t smc__step__num;
  kk_integer_t step__size;
  bool normalize;
};
static kk_box_t kk_bug_dash_test4_rmsmc_fun222(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_bug_dash_test4_new_rmsmc_fun222(kk_integer_t mh__step__num, kk_function_t model, kk_integer_t smc__step__num, kk_integer_t step__size, bool normalize, kk_context_t* _ctx) {
  struct kk_bug_dash_test4_rmsmc_fun222__t* _self = kk_function_alloc_as(struct kk_bug_dash_test4_rmsmc_fun222__t, 5, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_bug_dash_test4_rmsmc_fun222, kk_context());
  _self->mh__step__num = mh__step__num;
  _self->model = model;
  _self->smc__step__num = smc__step__num;
  _self->step__size = step__size;
  _self->normalize = normalize;
  return &_self->_base;
}



// lift anonymous function
struct kk_bug_dash_test4_rmsmc_fun228__t {
  struct kk_function_s _base;
  kk_integer_t mh__step__num;
  kk_integer_t smc__step__num;
  kk_integer_t step__size;
  bool normalize;
};
static kk_box_t kk_bug_dash_test4_rmsmc_fun228(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_bug_dash_test4_new_rmsmc_fun228(kk_integer_t mh__step__num, kk_integer_t smc__step__num, kk_integer_t step__size, bool normalize, kk_context_t* _ctx) {
  struct kk_bug_dash_test4_rmsmc_fun228__t* _self = kk_function_alloc_as(struct kk_bug_dash_test4_rmsmc_fun228__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_bug_dash_test4_rmsmc_fun228, kk_context());
  _self->mh__step__num = mh__step__num;
  _self->smc__step__num = smc__step__num;
  _self->step__size = step__size;
  _self->normalize = normalize;
  return &_self->_base;
}

static kk_box_t kk_bug_dash_test4_rmsmc_fun228(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_bug_dash_test4_rmsmc_fun228__t* _self = kk_function_as(struct kk_bug_dash_test4_rmsmc_fun228__t*, _fself);
  kk_integer_t mh__step__num = _self->mh__step__num; /* int */
  kk_integer_t smc__step__num = _self->smc__step__num; /* int */
  kk_integer_t step__size = _self->step__size; /* int */
  bool normalize = _self->normalize; /* bool */
  kk_drop_match(_self, {kk_integer_dup(mh__step__num);kk_integer_dup(smc__step__num);kk_integer_dup(step__size);;}, {}, _ctx)
  kk_std_core__list _x229 = kk_bug_dash_test4_rmsmc__loop(kk_integer_from_small(5), kk_integer_from_small(5), kk_integer_from_small(0), smc__step__num, mh__step__num, step__size, normalize, _ctx); /*effects-and-types/histogram_rmsmc<103>*/
  return kk_std_core__list_box(_x229, _ctx);
}


// lift anonymous function
struct kk_bug_dash_test4_rmsmc_fun231__t {
  struct kk_function_s _base;
  kk_function_t model;
};
static kk_box_t kk_bug_dash_test4_rmsmc_fun231(kk_function_t _fself, kk_box_t _b_196, kk_context_t* _ctx);
static kk_function_t kk_bug_dash_test4_new_rmsmc_fun231(kk_function_t model, kk_context_t* _ctx) {
  struct kk_bug_dash_test4_rmsmc_fun231__t* _self = kk_function_alloc_as(struct kk_bug_dash_test4_rmsmc_fun231__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_bug_dash_test4_rmsmc_fun231, kk_context());
  _self->model = model;
  return &_self->_base;
}



// lift anonymous function
struct kk_bug_dash_test4_rmsmc_fun234__t {
  struct kk_function_s _base;
  kk_function_t _bv_199;
};
static kk_box_t kk_bug_dash_test4_rmsmc_fun234(kk_function_t _fself, kk_box_t _b_200, kk_context_t* _ctx);
static kk_function_t kk_bug_dash_test4_new_rmsmc_fun234(kk_function_t _bv_199, kk_context_t* _ctx) {
  struct kk_bug_dash_test4_rmsmc_fun234__t* _self = kk_function_alloc_as(struct kk_bug_dash_test4_rmsmc_fun234__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_bug_dash_test4_rmsmc_fun234, kk_context());
  _self->_bv_199 = _bv_199;
  return &_self->_base;
}

static kk_box_t kk_bug_dash_test4_rmsmc_fun234(kk_function_t _fself, kk_box_t _b_200, kk_context_t* _ctx) {
  struct kk_bug_dash_test4_rmsmc_fun234__t* _self = kk_function_as(struct kk_bug_dash_test4_rmsmc_fun234__t*, _fself);
  kk_function_t _bv_199 = _self->_bv_199; /* (a : int) -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random|169> 18 */
  kk_drop_match(_self, {kk_function_dup(_bv_199);}, {}, _ctx)
  kk_integer_t _x235 = kk_integer_unbox(_b_200); /*int*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_context_t*), _bv_199, (_bv_199, _x235, _ctx));
}
static kk_box_t kk_bug_dash_test4_rmsmc_fun231(kk_function_t _fself, kk_box_t _b_196, kk_context_t* _ctx) {
  struct kk_bug_dash_test4_rmsmc_fun231__t* _self = kk_function_as(struct kk_bug_dash_test4_rmsmc_fun231__t*, _fself);
  kk_function_t model = _self->model; /* () -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random|169> 18 */
  kk_drop_match(_self, {kk_function_dup(model);}, {}, _ctx)
  kk_function_t _x232;
  kk_function_t _bv_199;
  kk_std_core__list _x233 = kk_std_core__list_unbox(_b_196, _ctx); /*effects-and-types/histogram_rmsmc<_147>*/
  _bv_199 = kk_bug_dash_test4__mlift178_rmsmc(model, _x233, _ctx); /*(a : int) -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random|169> 18*/
  _x232 = kk_bug_dash_test4_new_rmsmc_fun234(_bv_199, _ctx); /*(197) -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random|169> 18*/
  return kk_function_box(_x232);
}


// lift anonymous function
struct kk_bug_dash_test4_rmsmc_fun236__t {
  struct kk_function_s _base;
  kk_function_t _bv_203;
};
static kk_box_t kk_bug_dash_test4_rmsmc_fun236(kk_function_t _fself, kk_integer_t _b_204, kk_context_t* _ctx);
static kk_function_t kk_bug_dash_test4_new_rmsmc_fun236(kk_function_t _bv_203, kk_context_t* _ctx) {
  struct kk_bug_dash_test4_rmsmc_fun236__t* _self = kk_function_alloc_as(struct kk_bug_dash_test4_rmsmc_fun236__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_bug_dash_test4_rmsmc_fun236, kk_context());
  _self->_bv_203 = _bv_203;
  return &_self->_base;
}

static kk_box_t kk_bug_dash_test4_rmsmc_fun236(kk_function_t _fself, kk_integer_t _b_204, kk_context_t* _ctx) {
  struct kk_bug_dash_test4_rmsmc_fun236__t* _self = kk_function_as(struct kk_bug_dash_test4_rmsmc_fun236__t*, _fself);
  kk_function_t _bv_203 = _self->_bv_203; /* (a : 201) -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random|169> 202 */
  kk_drop_match(_self, {kk_function_dup(_bv_203);}, {}, _ctx)
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _bv_203, (_bv_203, kk_integer_box(_b_204), _ctx));
}


// lift anonymous function
struct kk_bug_dash_test4_rmsmc_fun237__t {
  struct kk_function_s _base;
  kk_function_t _bv_208;
};
static kk_box_t kk_bug_dash_test4_rmsmc_fun237(kk_function_t _fself, kk_box_t _b_209, kk_context_t* _ctx);
static kk_function_t kk_bug_dash_test4_new_rmsmc_fun237(kk_function_t _bv_208, kk_context_t* _ctx) {
  struct kk_bug_dash_test4_rmsmc_fun237__t* _self = kk_function_alloc_as(struct kk_bug_dash_test4_rmsmc_fun237__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_bug_dash_test4_rmsmc_fun237, kk_context());
  _self->_bv_208 = _bv_208;
  return &_self->_base;
}

static kk_box_t kk_bug_dash_test4_rmsmc_fun237(kk_function_t _fself, kk_box_t _b_209, kk_context_t* _ctx) {
  struct kk_bug_dash_test4_rmsmc_fun237__t* _self = kk_function_as(struct kk_bug_dash_test4_rmsmc_fun237__t*, _fself);
  kk_function_t _bv_208 = _self->_bv_208; /* (a : int) -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random|169> 18 */
  kk_drop_match(_self, {kk_function_dup(_bv_208);}, {}, _ctx)
  kk_integer_t _x238 = kk_integer_unbox(_b_209); /*int*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_context_t*), _bv_208, (_bv_208, _x238, _ctx));
}
static kk_box_t kk_bug_dash_test4_rmsmc_fun222(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_bug_dash_test4_rmsmc_fun222__t* _self = kk_function_as(struct kk_bug_dash_test4_rmsmc_fun222__t*, _fself);
  kk_integer_t mh__step__num = _self->mh__step__num; /* int */
  kk_function_t model = _self->model; /* () -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random|169> 18 */
  kk_integer_t smc__step__num = _self->smc__step__num; /* int */
  kk_integer_t step__size = _self->step__size; /* int */
  bool normalize = _self->normalize; /* bool */
  kk_drop_match(_self, {kk_integer_dup(mh__step__num);kk_function_dup(model);kk_integer_dup(smc__step__num);kk_integer_dup(step__size);;}, {}, _ctx)
  kk_function_t _x223;
  kk_function_t _bv_208;
  kk_std_core__list x_180;
  kk_vector_t _b_189_187;
  kk_std_core__list _x224;
  size_t _b_191_185;
  kk_std_core_hnd__htag _x225 = kk_std_core_hnd__htag_dup(kk_std_core__tag_exn); /*std/core/hnd/htag<.hnd-exn>*/
  _b_191_185 = kk_std_core_hnd__evv_index(_x225, _ctx); /*std/core/hnd/ev-index*/
  kk_std_core__list _b_192_186;
  size_t _b_193_183;
  kk_std_core_hnd__htag _x226 = kk_std_core_hnd__htag_dup(kk_effects_dash_and_dash_types__tag_sample); /*std/core/hnd/htag<effects-and-types/.hnd-sample>*/
  _b_193_183 = kk_std_core_hnd__evv_index(_x226, _ctx); /*std/core/hnd/ev-index*/
  _b_192_186 = kk_std_core__new_Cons(kk_reuse_null, kk_size_box(_b_193_183, _ctx), kk_std_core__new_Nil(_ctx), _ctx); /*list<std/core/hnd/ev-index>*/
  _x224 = kk_std_core__new_Cons(kk_reuse_null, kk_size_box(_b_191_185, _ctx), _b_192_186, _ctx); /*list<0>*/
  _b_189_187 = kk_std_core_unvlist(_x224, _ctx); /*vector<std/core/hnd/ev-index>*/
  kk_box_t _x227 = kk_std_core_hnd__open0(_b_189_187, kk_bug_dash_test4_new_rmsmc_fun228(mh__step__num, smc__step__num, step__size, normalize, _ctx), _ctx); /*1*/
  x_180 = kk_std_core__list_unbox(_x227, _ctx); /*effects-and-types/histogram_rmsmc<_147>*/
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_180, _ctx);
    kk_function_t _bv_203;
    kk_box_t _x230 = kk_std_core_hnd_yield_extend(kk_bug_dash_test4_new_rmsmc_fun231(model, _ctx), _ctx); /*2*/
    _bv_203 = kk_function_unbox(_x230); /*(a : 201) -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random|169> 202*/
    _bv_208 = kk_bug_dash_test4_new_rmsmc_fun236(_bv_203, _ctx); /*(a : int) -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random|169> 18*/
  }
  else {
    _bv_208 = kk_bug_dash_test4__mlift178_rmsmc(model, x_180, _ctx); /*(a : int) -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random|169> 18*/
  }
  _x223 = kk_bug_dash_test4_new_rmsmc_fun237(_bv_208, _ctx); /*(206) -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random|169> 18*/
  return kk_function_box(_x223);
}


// lift anonymous function
struct kk_bug_dash_test4_rmsmc_fun239__t {
  struct kk_function_s _base;
  kk_function_t _bv_212;
};
static kk_box_t kk_bug_dash_test4_rmsmc_fun239(kk_function_t _fself, kk_integer_t _b_213, kk_context_t* _ctx);
static kk_function_t kk_bug_dash_test4_new_rmsmc_fun239(kk_function_t _bv_212, kk_context_t* _ctx) {
  struct kk_bug_dash_test4_rmsmc_fun239__t* _self = kk_function_alloc_as(struct kk_bug_dash_test4_rmsmc_fun239__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_bug_dash_test4_rmsmc_fun239, kk_context());
  _self->_bv_212 = _bv_212;
  return &_self->_base;
}

static kk_box_t kk_bug_dash_test4_rmsmc_fun239(kk_function_t _fself, kk_integer_t _b_213, kk_context_t* _ctx) {
  struct kk_bug_dash_test4_rmsmc_fun239__t* _self = kk_function_as(struct kk_bug_dash_test4_rmsmc_fun239__t*, _fself);
  kk_function_t _bv_212 = _self->_bv_212; /* (a : 210) -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random|169> 211 */
  kk_drop_match(_self, {kk_function_dup(_bv_212);}, {}, _ctx)
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _bv_212, (_bv_212, kk_integer_box(_b_213), _ctx));
}

kk_function_t kk_bug_dash_test4_rmsmc(kk_integer_t particle__num, kk_integer_t smc__step__num, kk_integer_t mh__step__num, kk_integer_t step__size, kk_function_t model, bool normalize, kk_context_t* _ctx) { /* forall<a,e> (particle_num : int, smc_step_num : int, mh_step_num : int, step_size : int, model : () -> <pure,std/num/random/random,effects-and-types/sample,effects-and-types/score,effects-and-types/yield|e> a, normalize : bool) -> <pure,std/num/random/random,effects-and-types/score|e> ((a : int) -> <pure,std/num/random/random,effects-and-types/sample,effects-and-types/score,effects-and-types/yield|e> a) */ 
  kk_integer_drop(particle__num, _ctx);
  kk_function_t _bv_212;
  kk_box_t _x221 = kk_handlers_random__sampler(kk_bug_dash_test4_new_rmsmc_fun222(mh__step__num, model, smc__step__num, step__size, normalize, _ctx), _ctx); /*0*/
  _bv_212 = kk_function_unbox(_x221); /*(a : 210) -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random|169> 211*/
  return kk_bug_dash_test4_new_rmsmc_fun239(_bv_212, _ctx);
}

// initialization
void kk_bug_dash_test4__init(kk_context_t* _ctx){
  static bool _initialized = false;
  if (_initialized) return;
  _initialized = true;
  kk_std_core_types__init(_ctx);
  kk_std_core_hnd__init(_ctx);
  kk_std_core__init(_ctx);
  kk_std_num_random__init(_ctx);
  kk_effects_dash_and_dash_types__init(_ctx);
  kk_handlers__init(_ctx);
}
