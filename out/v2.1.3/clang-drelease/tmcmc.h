#pragma once
#ifndef kk_tmcmc_H
#define kk_tmcmc_H
// Koka generated module: "tmcmc", koka version: 2.1.3
#include <kklib.h>
#include "std_core_types.h"
#include "std_core_hnd.h"
#include "std_core.h"
#include "effects_dash_and_dash_types.h"
#include "exponents.h"
#include "handlers.h"
#include "model_dash_resources.h"

// type declarations

// type tmcmc/trace
struct kk_tmcmc__trace_s {
  kk_block_t _block;
};
typedef struct kk_tmcmc__trace_s* kk_tmcmc__trace;
struct kk_tmcmc_Trace {
  struct kk_tmcmc__trace_s _base;
  kk_function_t m;
  kk_std_core__list l;
  kk_box_t a;
  kk_effects_dash_and_dash_types__exp p;
};
static inline kk_tmcmc__trace kk_tmcmc__base_Trace(struct kk_tmcmc_Trace* _x){
  return &_x->_base;
}
static inline kk_tmcmc__trace kk_tmcmc__new_Trace(kk_reuse_t _at, kk_function_t m, kk_effects_dash_and_dash_types__exp p, kk_std_core__list l, kk_box_t a, kk_context_t* _ctx){
  struct kk_tmcmc_Trace* _con = kk_block_alloc_at_as(struct kk_tmcmc_Trace, _at, 3 /* scan count */, (kk_tag_t)(1), _ctx);
  _con->m = m;
  _con->l = l;
  _con->a = a;
  _con->p = p;
  return kk_tmcmc__base_Trace(_con);
}
static inline struct kk_tmcmc_Trace* kk_tmcmc__as_Trace(kk_tmcmc__trace x) {
  return kk_basetype_as_assert(struct kk_tmcmc_Trace*, x, (kk_tag_t)(1) /* _tag */);
}
static inline bool kk_tmcmc__is_Trace(kk_tmcmc__trace x) {
  return (true);
}
static inline kk_tmcmc__trace kk_tmcmc__trace_dup(kk_tmcmc__trace _x) {
  return kk_basetype_dup_as(kk_tmcmc__trace, _x);
}
static inline void kk_tmcmc__trace_drop(kk_tmcmc__trace _x, kk_context_t* _ctx) {
  kk_basetype_drop(_x, _ctx);
}
static inline bool kk_tmcmc__trace_is_unique(kk_tmcmc__trace _x) {
  return kk_basetype_is_unique(_x);
}
static inline void kk_tmcmc__trace_free(kk_tmcmc__trace _x) {
  kk_basetype_free(_x);
}
static inline void kk_tmcmc__trace_decref(kk_tmcmc__trace _x, kk_context_t* _ctx) {
  kk_basetype_decref(_x, _ctx);
}
static inline kk_reuse_t kk_tmcmc__trace_dropn_reuse(kk_tmcmc__trace _x, size_t _scan_fsize, kk_context_t* _ctx) {
  return kk_basetype_dropn_reuse(_x, _scan_fsize, _ctx);
}
static inline void kk_tmcmc__trace_dropn(kk_tmcmc__trace _x, size_t _scan_fsize, kk_context_t* _ctx) {
  kk_basetype_dropn(_x, _scan_fsize, _ctx);
}
static inline kk_reuse_t kk_tmcmc__trace_reuse(kk_tmcmc__trace _x) {
  return kk_basetype_reuse(_x);
}
static inline kk_tmcmc__trace kk_tmcmc__trace_hole() {
  return (kk_tmcmc__trace)(1);
}
static inline kk_box_t kk_tmcmc__trace_box(kk_tmcmc__trace _x, kk_context_t* _ctx) {
  return kk_basetype_box(_x);
}
static inline kk_tmcmc__trace kk_tmcmc__trace_unbox(kk_box_t _x, kk_context_t* _ctx) {
  return kk_basetype_unbox_as(kk_tmcmc__trace, _x);
}

// value type tmcmc/trace_rmsmc
struct kk_tmcmc_RTrace {
  kk_function_t m;
  kk_std_core__list l;
  kk_effects_dash_and_dash_types__exp p;
};
typedef struct kk_tmcmc_RTrace kk_tmcmc__trace__rmsmc;
static inline kk_tmcmc__trace__rmsmc kk_tmcmc__new_RTrace(kk_function_t m, kk_effects_dash_and_dash_types__exp p, kk_std_core__list l, kk_context_t* _ctx){
  kk_tmcmc__trace__rmsmc _con;
  _con.m = m;
  _con.l = l;
  _con.p = p;
  return _con;
}
static inline bool kk_tmcmc__is_RTrace(kk_tmcmc__trace__rmsmc x) {
  return (true);
}
static inline kk_tmcmc__trace__rmsmc kk_tmcmc__trace__rmsmc_dup(kk_tmcmc__trace__rmsmc _x) {
  kk_function_dup(_x.m);
  kk_std_core__list_dup(_x.l);
  kk_effects_dash_and_dash_types__exp_dup(_x.p);
  return _x;
}
static inline void kk_tmcmc__trace__rmsmc_drop(kk_tmcmc__trace__rmsmc _x, kk_context_t* _ctx) {
  kk_function_drop(_x.m, _ctx);
  kk_std_core__list_drop(_x.l, _ctx);
  kk_effects_dash_and_dash_types__exp_drop(_x.p, _ctx);
}
static inline kk_box_t kk_tmcmc__trace__rmsmc_box(kk_tmcmc__trace__rmsmc _x, kk_context_t* _ctx) {
  kk_box_t _box;
  kk_valuetype_box(kk_tmcmc__trace__rmsmc, _box, _x, 2 /* scan count */, _ctx);
  return _box;
}
static inline kk_tmcmc__trace__rmsmc kk_tmcmc__trace__rmsmc_unbox(kk_box_t _x, kk_context_t* _ctx) {
  kk_boxed_value_t _p;
  kk_tmcmc__trace__rmsmc _unbox;
  kk_valuetype_unbox_(kk_tmcmc__trace__rmsmc, _p, _unbox, _x, _ctx);
  if (_ctx!=NULL && _p!=NULL) {
    if (kk_basetype_is_unique(_p)) { kk_basetype_free(_p); } else {
      kk_tmcmc__trace__rmsmc_dup(_unbox);
      kk_basetype_decref(_p, _ctx);
    }
  }
  return _unbox;
}

// value declarations
 
// Automatically generated. Retrieves the `m` constructor field of the `:trace` type.

static inline kk_function_t kk_tmcmc_m(kk_tmcmc__trace trace, kk_context_t* _ctx) { /* forall<a,e> (trace : trace<a,e>) -> (() -> e a) */ 
  struct kk_tmcmc_Trace* _con2352 = kk_tmcmc__as_Trace(trace);
  kk_function_t _x = _con2352->m;
  kk_effects_dash_and_dash_types__exp _pat0 = _con2352->p;
  kk_std_core__list _pat2 = _con2352->l;
  kk_box_t _pat3 = _con2352->a;
  if (kk_tmcmc__trace_is_unique(trace)) {
    kk_box_drop(_pat3, _ctx);
    kk_std_core__list_drop(_pat2, _ctx);
    kk_tmcmc__trace_free(trace);
  }
  else {
    kk_function_dup(_x);
    kk_tmcmc__trace_decref(trace, _ctx);
  }
  return _x;
}
 
// Automatically generated. Retrieves the `p` constructor field of the `:trace` type.

static inline kk_effects_dash_and_dash_types__exp kk_tmcmc_p(kk_tmcmc__trace trace, kk_context_t* _ctx) { /* forall<a,e> (trace : trace<a,e>) -> effects-and-types/exp */ 
  struct kk_tmcmc_Trace* _con2353 = kk_tmcmc__as_Trace(trace);
  kk_function_t _pat0 = _con2353->m;
  kk_effects_dash_and_dash_types__exp _x = _con2353->p;
  kk_std_core__list _pat2 = _con2353->l;
  kk_box_t _pat3 = _con2353->a;
  if (kk_tmcmc__trace_is_unique(trace)) {
    kk_box_drop(_pat3, _ctx);
    kk_std_core__list_drop(_pat2, _ctx);
    kk_function_drop(_pat0, _ctx);
    kk_tmcmc__trace_free(trace);
  }
  else {
    kk_tmcmc__trace_decref(trace, _ctx);
  }
  return _x;
}
 
// Automatically generated. Retrieves the `l` constructor field of the `:trace` type.

static inline kk_std_core__list kk_tmcmc_l(kk_tmcmc__trace trace, kk_context_t* _ctx) { /* forall<a,e> (trace : trace<a,e>) -> effects-and-types/trace_values */ 
  struct kk_tmcmc_Trace* _con2354 = kk_tmcmc__as_Trace(trace);
  kk_function_t _pat0 = _con2354->m;
  kk_effects_dash_and_dash_types__exp _pat1 = _con2354->p;
  kk_std_core__list _x = _con2354->l;
  kk_box_t _pat3 = _con2354->a;
  if (kk_tmcmc__trace_is_unique(trace)) {
    kk_box_drop(_pat3, _ctx);
    kk_function_drop(_pat0, _ctx);
    kk_tmcmc__trace_free(trace);
  }
  else {
    kk_std_core__list_dup(_x);
    kk_tmcmc__trace_decref(trace, _ctx);
  }
  return _x;
}
 
// Automatically generated. Retrieves the `a` constructor field of the `:trace` type.

static inline kk_box_t kk_tmcmc_a(kk_tmcmc__trace trace, kk_context_t* _ctx) { /* forall<a,e> (trace : trace<a,e>) -> a */ 
  struct kk_tmcmc_Trace* _con2355 = kk_tmcmc__as_Trace(trace);
  kk_function_t _pat0 = _con2355->m;
  kk_effects_dash_and_dash_types__exp _pat1 = _con2355->p;
  kk_std_core__list _pat3 = _con2355->l;
  kk_box_t _x = _con2355->a;
  if (kk_tmcmc__trace_is_unique(trace)) {
    kk_std_core__list_drop(_pat3, _ctx);
    kk_function_drop(_pat0, _ctx);
    kk_tmcmc__trace_free(trace);
  }
  else {
    kk_box_dup(_x);
    kk_tmcmc__trace_decref(trace, _ctx);
  }
  return _x;
}

kk_tmcmc__trace kk_tmcmc__mlift1671_op(kk_function_t _c_1, kk_effects_dash_and_dash_types__exp _c_2, kk_std_core__list _c_3, kk_box_t _c_4, kk_context_t* _ctx); /* forall<a,e> (() -> e a, effects-and-types/exp, effects-and-types/trace_values, a) -> trace<a,e> */ 

kk_tmcmc__trace kk_tmcmc__mlift1672_op(kk_function_t _c_1, kk_effects_dash_and_dash_types__exp _c_2, kk_tmcmc__trace _this, kk_std_core_types__optional a0, kk_std_core__list _c_3, kk_context_t* _ctx); /* forall<a,e> (() -> e a, effects-and-types/exp, trace<a,e>, a : optional<a>, effects-and-types/trace_values) -> trace<a,e> */ 

kk_tmcmc__trace kk_tmcmc__mlift1673_op(kk_function_t _c_1, kk_tmcmc__trace _this, kk_std_core_types__optional a0, kk_std_core_types__optional l0, kk_effects_dash_and_dash_types__exp _c_2, kk_context_t* _ctx); /* forall<a,e> (() -> e a, trace<a,e>, a : optional<a>, l : optional<effects-and-types/trace_values>, effects-and-types/exp) -> trace<a,e> */ 

kk_tmcmc__trace kk_tmcmc__mlift1674_op(kk_tmcmc__trace _this, kk_std_core_types__optional a0, kk_std_core_types__optional l0, kk_std_core_types__optional p0, kk_function_t _c_1, kk_context_t* _ctx); /* forall<a,e> (trace<a,e>, a : optional<a>, l : optional<effects-and-types/trace_values>, p : optional<effects-and-types/exp>, () -> e a) -> trace<a,e> */ 

kk_tmcmc__trace kk_tmcmc__copy(kk_tmcmc__trace _this, kk_std_core_types__optional m0, kk_std_core_types__optional p0, kk_std_core_types__optional l0, kk_std_core_types__optional a0, kk_context_t* _ctx); /* forall<a,e> (trace<a,e>, m : optional<() -> e a>, p : optional<effects-and-types/exp>, l : optional<effects-and-types/trace_values>, a : optional<a>) -> trace<a,e> */ 
 
// Automatically generated. Retrieves the `m` constructor field of the `:trace_rmsmc` type.

static inline kk_function_t kk_tmcmc_m_1(kk_tmcmc__trace__rmsmc _this, kk_context_t* _ctx) { /* forall<a,e> (trace_rmsmc<a,e>) -> (() -> ((int) -> e a)) */ 
  kk_function_t _x = _this.m;
  kk_effects_dash_and_dash_types__exp _pat0 = _this.p;
  kk_function_dup(_x);
  kk_tmcmc__trace__rmsmc_drop(_this, _ctx);
  return _x;
}
 
// Automatically generated. Retrieves the `p` constructor field of the `:trace_rmsmc` type.

static inline kk_effects_dash_and_dash_types__exp kk_tmcmc_p_1(kk_tmcmc__trace__rmsmc _this, kk_context_t* _ctx) { /* forall<a,e> (trace_rmsmc<a,e>) -> effects-and-types/exp */ 
  kk_effects_dash_and_dash_types__exp _x = _this.p;
  kk_tmcmc__trace__rmsmc_drop(_this, _ctx);
  return _x;
}
 
// Automatically generated. Retrieves the `l` constructor field of the `:trace_rmsmc` type.

static inline kk_std_core__list kk_tmcmc_l_1(kk_tmcmc__trace__rmsmc _this, kk_context_t* _ctx) { /* forall<a,e> (trace_rmsmc<a,e>) -> effects-and-types/trace_values */ 
  kk_effects_dash_and_dash_types__exp _pat1 = _this.p;
  kk_std_core__list _x = _this.l;
  kk_std_core__list_dup(_x);
  kk_tmcmc__trace__rmsmc_drop(_this, _ctx);
  return _x;
}

kk_tmcmc__trace__rmsmc kk_tmcmc__mlift1675_op(kk_function_t _c_5, kk_effects_dash_and_dash_types__exp _c_6, kk_std_core__list _c_7, kk_context_t* _ctx); /* forall<a,e> (() -> ((int) -> e a), effects-and-types/exp, effects-and-types/trace_values) -> trace_rmsmc<a,e> */ 

kk_tmcmc__trace__rmsmc kk_tmcmc__mlift1676_op(kk_function_t _c_5, kk_tmcmc__trace__rmsmc _this, kk_std_core_types__optional l0, kk_effects_dash_and_dash_types__exp _c_6, kk_context_t* _ctx); /* forall<a,e> (() -> ((int) -> e a), trace_rmsmc<a,e>, l : optional<effects-and-types/trace_values>, effects-and-types/exp) -> trace_rmsmc<a,e> */ 

kk_tmcmc__trace__rmsmc kk_tmcmc__mlift1677_op(kk_tmcmc__trace__rmsmc _this, kk_std_core_types__optional l0, kk_std_core_types__optional p0, kk_function_t _c_5, kk_context_t* _ctx); /* forall<a,e> (trace_rmsmc<a,e>, l : optional<effects-and-types/trace_values>, p : optional<effects-and-types/exp>, () -> ((int) -> e a)) -> trace_rmsmc<a,e> */ 

kk_tmcmc__trace__rmsmc kk_tmcmc__copy_1(kk_tmcmc__trace__rmsmc _this, kk_std_core_types__optional m0, kk_std_core_types__optional p0, kk_std_core_types__optional l0, kk_context_t* _ctx); /* forall<a,e> (trace_rmsmc<a,e>, m : optional<() -> ((int) -> e a)>, p : optional<effects-and-types/exp>, l : optional<effects-and-types/trace_values>) -> trace_rmsmc<a,e> */ 

kk_integer_t kk_tmcmc__mlift1678_random__range(kk_integer_t upper__bound, double _y_8, kk_context_t* _ctx); /* (upper_bound : int, double) -> effects-and-types/sample int */ 

kk_integer_t kk_tmcmc_random__range(kk_integer_t upper__bound, kk_context_t* _ctx); /* (upper_bound : int) -> effects-and-types/sample int */ 

kk_std_core_types__tuple2_ kk_tmcmc_with__randomness(kk_function_t model, kk_std_core__list trace__values, kk_context_t* _ctx); /* forall<a,e> (model : () -> <effects-and-types/sample,effects-and-types/score|e> a, trace_values : effects-and-types/trace_values) -> <effects-and-types/sample|e> (effects-and-types/trace_values, (effects-and-types/exp, a)) */ 

kk_std_core_types__tuple2_ kk_tmcmc_with__randomness__rmsmc(kk_function_t model, kk_std_core__list trace__values, kk_context_t* _ctx); /* forall<a,e> (model : () -> ((int) -> <exn,effects-and-types/yield,effects-and-types/score,effects-and-types/sample,effects-and-types/sample|e> a), trace_values : effects-and-types/trace_values) -> <effects-and-types/sample,effects-and-types/sample,exn,effects-and-types/yield|e> (effects-and-types/trace_values, (effects-and-types/exp, a)) */ 

kk_std_core__list kk_tmcmc__mlift1679_perturb__trace(kk_std_core__list l1, double _y_15, kk_context_t* _ctx); /* (l1 : list<double>, double) -> effects-and-types/sample list<double> */ 

kk_std_core__list kk_tmcmc__mlift1680_perturb__trace(kk_std_core__list trace__values, kk_integer_t perturb__index, kk_context_t* _ctx); /* (trace_values : effects-and-types/trace_values, perturb_index : int) -> effects-and-types/sample list<double> */ 

kk_std_core__list kk_tmcmc_perturb__trace(kk_std_core__list trace__values, kk_context_t* _ctx); /* (trace_values : effects-and-types/trace_values) -> effects-and-types/sample effects-and-types/trace_values */ 

kk_tmcmc__trace kk_tmcmc__mlift1681_mh__step(kk_box_t b, kk_function_t model, kk_std_core__list new__trace, kk_effects_dash_and_dash_types__exp p2, kk_tmcmc__trace trace, bool accept, kk_context_t* _ctx); /* forall<a,e> (b : a, model : () -> <effects-and-types/sample,effects-and-types/score|e> a, new_trace : effects-and-types/trace_values, p2 : effects-and-types/exp, trace : trace<a,<effects-and-types/sample,effects-and-types/score|e>>, accept : bool) -> <effects-and-types/sample|e> trace<a,<effects-and-types/sample,effects-and-types/score|e>> */ 

kk_tmcmc__trace kk_tmcmc__mlift1682_mh__step(kk_function_t model, kk_std_core__list old__trace, kk_effects_dash_and_dash_types__exp p1, kk_tmcmc__trace trace, kk_std_core_types__tuple2_ p2b, kk_context_t* _ctx); /* forall<a,e> (model : () -> <effects-and-types/sample,effects-and-types/score|e> a, old_trace : effects-and-types/trace_values, p1 : effects-and-types/exp, trace : trace<a,<effects-and-types/sample,effects-and-types/score|e>>, p2b : (effects-and-types/trace_values, (effects-and-types/exp, a))) -> <effects-and-types/sample|e> trace<a,<effects-and-types/sample,effects-and-types/score|e>> */ 

kk_tmcmc__trace kk_tmcmc__mlift1683_mh__step(kk_tmcmc__trace trace, kk_std_core__list modified__trace, kk_context_t* _ctx); /* forall<a,e> (trace : trace<a,<effects-and-types/sample,effects-and-types/score|e>>, modified_trace : effects-and-types/trace_values) -> <effects-and-types/sample|e> trace<a,<effects-and-types/sample,effects-and-types/score|e>> */ 

kk_tmcmc__trace kk_tmcmc_mh__step(kk_tmcmc__trace trace, kk_context_t* _ctx); /* forall<a,e> (trace : trace<a,<effects-and-types/sample,effects-and-types/score|e>>) -> <effects-and-types/sample|e> trace<a,<effects-and-types/sample,effects-and-types/score|e>> */ 

kk_tmcmc__trace__rmsmc kk_tmcmc__mlift1684_mh__step__rmsmc(kk_function_t model, kk_std_core__list new__trace, kk_effects_dash_and_dash_types__exp p2, kk_tmcmc__trace__rmsmc trace, bool accept, kk_context_t* _ctx); /* forall<a,e> (model : () -> ((int) -> <exn,effects-and-types/sample,effects-and-types/sample,effects-and-types/score,effects-and-types/yield|e> a), new_trace : effects-and-types/trace_values, p2 : effects-and-types/exp, trace : trace_rmsmc<a,<effects-and-types/sample,effects-and-types/sample,effects-and-types/score,effects-and-types/yield,exn|e>>, accept : bool) -> <effects-and-types/sample,exn,effects-and-types/sample,effects-and-types/yield|e> trace_rmsmc<a,<exn,effects-and-types/sample,effects-and-types/sample,effects-and-types/score,effects-and-types/yield|e>> */ 

kk_tmcmc__trace__rmsmc kk_tmcmc__mlift1685_mh__step__rmsmc(kk_function_t model, kk_std_core__list old__trace, kk_effects_dash_and_dash_types__exp p1, kk_tmcmc__trace__rmsmc trace, kk_std_core_types__tuple2_ p2b, kk_context_t* _ctx); /* forall<a,e> (model : () -> ((int) -> <exn,effects-and-types/sample,effects-and-types/sample,effects-and-types/score,effects-and-types/yield|e> a), old_trace : effects-and-types/trace_values, p1 : effects-and-types/exp, trace : trace_rmsmc<a,<effects-and-types/sample,effects-and-types/sample,effects-and-types/score,effects-and-types/yield,exn|e>>, p2b : (effects-and-types/trace_values, (effects-and-types/exp, a))) -> <effects-and-types/sample,effects-and-types/sample,exn,effects-and-types/yield|e> trace_rmsmc<a,<exn,effects-and-types/sample,effects-and-types/sample,effects-and-types/score,effects-and-types/yield|e>> */ 

kk_tmcmc__trace__rmsmc kk_tmcmc__mlift1686_mh__step__rmsmc(kk_tmcmc__trace__rmsmc trace, kk_std_core__list modified__trace, kk_context_t* _ctx); /* forall<a,e> (trace : trace_rmsmc<a,<effects-and-types/sample,effects-and-types/sample,effects-and-types/score,effects-and-types/yield,exn|e>>, modified_trace : effects-and-types/trace_values) -> <effects-and-types/sample,exn,effects-and-types/sample,effects-and-types/yield|e> trace_rmsmc<a,<exn,effects-and-types/sample,effects-and-types/sample,effects-and-types/score,effects-and-types/yield|e>> */ 

kk_tmcmc__trace__rmsmc kk_tmcmc_mh__step__rmsmc(kk_tmcmc__trace__rmsmc trace, kk_context_t* _ctx); /* forall<a,e> (trace : trace_rmsmc<a,<effects-and-types/sample,effects-and-types/sample,effects-and-types/score,effects-and-types/yield,exn|e>>) -> <effects-and-types/sample,effects-and-types/sample,effects-and-types/yield,exn|e> trace_rmsmc<a,<effects-and-types/sample,effects-and-types/sample,effects-and-types/score,effects-and-types/yield,exn|e>> */ 

kk_std_core_types__tuple2_ kk_tmcmc__mlift1687_model__stepper__recursive(kk_integer_t burnin, kk_std_core__list posterior, kk_integer_t steps, kk_tmcmc__trace new__trace, kk_context_t* _ctx); /* forall<a,e> (burnin : int, posterior : list<(list<double>, a)>, steps : int, new_trace : trace<a,<effects-and-types/sample,effects-and-types/score,div|e>>) -> <effects-and-types/sample,div|e> (list<(list<double>, a)>, trace<a,<effects-and-types/sample,effects-and-types/score,div|e>>) */ 

kk_std_core_types__tuple2_ kk_tmcmc_model__stepper__recursive(kk_integer_t steps0, kk_tmcmc__trace trace, kk_std_core__list posterior0, kk_integer_t burnin0, kk_context_t* _ctx); /* forall<a,e> (steps : int, trace : trace<a,<effects-and-types/sample,effects-and-types/score,div|e>>, posterior : list<(list<double>, a)>, burnin : int) -> <effects-and-types/sample,div|e> (list<(list<double>, a)>, trace<a,<effects-and-types/sample,effects-and-types/score,div|e>>) */ 

kk_std_core_types__tuple2_ kk_tmcmc__mlift1688_tmcmc(kk_integer_t burnin, kk_function_t model, kk_integer_t steps, kk_std_core_types__tuple2_ model__results, kk_context_t* _ctx); /* forall<a,e> (burnin : int, model : () -> <effects-and-types/sample,effects-and-types/score,div|e> a, steps : int, model_results : (effects-and-types/exp, (list<double>, a))) -> <div,effects-and-types/sample|e> (list<(list<double>, a)>, trace<a,<effects-and-types/sample,effects-and-types/score,div|e>>) */ 

kk_std_core_types__tuple2_ kk_tmcmc_tmcmc(kk_function_t model, kk_integer_t steps, kk_effects_dash_and_dash_types__exp init__weight, kk_integer_t burnin, kk_context_t* _ctx); /* forall<a,e> (model : () -> <effects-and-types/sample,effects-and-types/score,div|e> a, steps : int, init_weight : effects-and-types/exp, burnin : int) -> <effects-and-types/sample,div|e> (list<(list<double>, a)>, trace<a,<effects-and-types/sample,effects-and-types/score,div|e>>) */ 

void kk_tmcmc__init(kk_context_t* _ctx);

#endif // header
