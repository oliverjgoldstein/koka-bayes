#pragma once
#ifndef kk_trace_H
#define kk_trace_H
// Koka generated module: "trace", koka version: 2.1.3
#include <kklib.h>
#include "std_core_types.h"
#include "std_core_hnd.h"
#include "std_core.h"
#include "effects_dash_and_dash_types.h"
#include "exponents.h"
#include "handlers.h"
#include "model_dash_resources.h"

// type declarations

// type trace/trace
struct kk_trace__trace_s {
  kk_block_t _block;
};
typedef struct kk_trace__trace_s* kk_trace__trace;
struct kk_trace_Trace {
  struct kk_trace__trace_s _base;
  kk_function_t m;
  kk_std_core__list l;
  kk_box_t a;
  kk_effects_dash_and_dash_types__exp p;
};
static inline kk_trace__trace kk_trace__base_Trace(struct kk_trace_Trace* _x){
  return &_x->_base;
}
static inline kk_trace__trace kk_trace__new_Trace(kk_reuse_t _at, kk_function_t m, kk_effects_dash_and_dash_types__exp p, kk_std_core__list l, kk_box_t a, kk_context_t* _ctx){
  struct kk_trace_Trace* _con = kk_block_alloc_at_as(struct kk_trace_Trace, _at, 3 /* scan count */, (kk_tag_t)(1), _ctx);
  _con->m = m;
  _con->l = l;
  _con->a = a;
  _con->p = p;
  return kk_trace__base_Trace(_con);
}
static inline struct kk_trace_Trace* kk_trace__as_Trace(kk_trace__trace x) {
  return kk_basetype_as_assert(struct kk_trace_Trace*, x, (kk_tag_t)(1) /* _tag */);
}
static inline bool kk_trace__is_Trace(kk_trace__trace x) {
  return (true);
}
static inline kk_trace__trace kk_trace__trace_dup(kk_trace__trace _x) {
  return kk_basetype_dup_as(kk_trace__trace, _x);
}
static inline void kk_trace__trace_drop(kk_trace__trace _x, kk_context_t* _ctx) {
  kk_basetype_drop(_x, _ctx);
}
static inline bool kk_trace__trace_is_unique(kk_trace__trace _x) {
  return kk_basetype_is_unique(_x);
}
static inline void kk_trace__trace_free(kk_trace__trace _x) {
  kk_basetype_free(_x);
}
static inline void kk_trace__trace_decref(kk_trace__trace _x, kk_context_t* _ctx) {
  kk_basetype_decref(_x, _ctx);
}
static inline kk_reuse_t kk_trace__trace_dropn_reuse(kk_trace__trace _x, size_t _scan_fsize, kk_context_t* _ctx) {
  return kk_basetype_dropn_reuse(_x, _scan_fsize, _ctx);
}
static inline void kk_trace__trace_dropn(kk_trace__trace _x, size_t _scan_fsize, kk_context_t* _ctx) {
  kk_basetype_dropn(_x, _scan_fsize, _ctx);
}
static inline kk_reuse_t kk_trace__trace_reuse(kk_trace__trace _x) {
  return kk_basetype_reuse(_x);
}
static inline kk_trace__trace kk_trace__trace_hole() {
  return (kk_trace__trace)(1);
}
static inline kk_box_t kk_trace__trace_box(kk_trace__trace _x, kk_context_t* _ctx) {
  return kk_basetype_box(_x);
}
static inline kk_trace__trace kk_trace__trace_unbox(kk_box_t _x, kk_context_t* _ctx) {
  return kk_basetype_unbox_as(kk_trace__trace, _x);
}

// value declarations
 
// Automatically generated. Retrieves the `m` constructor field of the `:trace` type.

static inline kk_function_t kk_trace_m(kk_trace__trace trace, kk_context_t* _ctx) { /* forall<a,e> (trace : trace<a,e>) -> (() -> e a) */ 
  struct kk_trace_Trace* _con1838 = kk_trace__as_Trace(trace);
  kk_function_t _x = _con1838->m;
  kk_effects_dash_and_dash_types__exp _pat0 = _con1838->p;
  kk_std_core__list _pat2 = _con1838->l;
  kk_box_t _pat3 = _con1838->a;
  if (kk_trace__trace_is_unique(trace)) {
    kk_box_drop(_pat3, _ctx);
    kk_std_core__list_drop(_pat2, _ctx);
    kk_trace__trace_free(trace);
  }
  else {
    kk_function_dup(_x);
    kk_trace__trace_decref(trace, _ctx);
  }
  return _x;
}
 
// Automatically generated. Retrieves the `p` constructor field of the `:trace` type.

static inline kk_effects_dash_and_dash_types__exp kk_trace_p(kk_trace__trace trace, kk_context_t* _ctx) { /* forall<a,e> (trace : trace<a,e>) -> effects-and-types/exp */ 
  struct kk_trace_Trace* _con1839 = kk_trace__as_Trace(trace);
  kk_function_t _pat0 = _con1839->m;
  kk_effects_dash_and_dash_types__exp _x = _con1839->p;
  kk_std_core__list _pat2 = _con1839->l;
  kk_box_t _pat3 = _con1839->a;
  if (kk_trace__trace_is_unique(trace)) {
    kk_box_drop(_pat3, _ctx);
    kk_std_core__list_drop(_pat2, _ctx);
    kk_function_drop(_pat0, _ctx);
    kk_trace__trace_free(trace);
  }
  else {
    kk_trace__trace_decref(trace, _ctx);
  }
  return _x;
}
 
// Automatically generated. Retrieves the `l` constructor field of the `:trace` type.

static inline kk_std_core__list kk_trace_l(kk_trace__trace trace, kk_context_t* _ctx) { /* forall<a,e> (trace : trace<a,e>) -> effects-and-types/trace_values */ 
  struct kk_trace_Trace* _con1840 = kk_trace__as_Trace(trace);
  kk_function_t _pat0 = _con1840->m;
  kk_effects_dash_and_dash_types__exp _pat1 = _con1840->p;
  kk_std_core__list _x = _con1840->l;
  kk_box_t _pat3 = _con1840->a;
  if (kk_trace__trace_is_unique(trace)) {
    kk_box_drop(_pat3, _ctx);
    kk_function_drop(_pat0, _ctx);
    kk_trace__trace_free(trace);
  }
  else {
    kk_std_core__list_dup(_x);
    kk_trace__trace_decref(trace, _ctx);
  }
  return _x;
}
 
// Automatically generated. Retrieves the `a` constructor field of the `:trace` type.

static inline kk_box_t kk_trace_a(kk_trace__trace trace, kk_context_t* _ctx) { /* forall<a,e> (trace : trace<a,e>) -> a */ 
  struct kk_trace_Trace* _con1841 = kk_trace__as_Trace(trace);
  kk_function_t _pat0 = _con1841->m;
  kk_effects_dash_and_dash_types__exp _pat1 = _con1841->p;
  kk_std_core__list _pat3 = _con1841->l;
  kk_box_t _x = _con1841->a;
  if (kk_trace__trace_is_unique(trace)) {
    kk_std_core__list_drop(_pat3, _ctx);
    kk_function_drop(_pat0, _ctx);
    kk_trace__trace_free(trace);
  }
  else {
    kk_box_dup(_x);
    kk_trace__trace_decref(trace, _ctx);
  }
  return _x;
}

kk_trace__trace kk_trace__mlift1391_op(kk_function_t _c_1, kk_effects_dash_and_dash_types__exp _c_2, kk_std_core__list _c_3, kk_box_t _c_4, kk_context_t* _ctx); /* forall<a,e> (() -> e a, effects-and-types/exp, effects-and-types/trace_values, a) -> trace<a,e> */ 

kk_trace__trace kk_trace__mlift1392_op(kk_function_t _c_1, kk_effects_dash_and_dash_types__exp _c_2, kk_trace__trace _this, kk_std_core_types__optional a0, kk_std_core__list _c_3, kk_context_t* _ctx); /* forall<a,e> (() -> e a, effects-and-types/exp, trace<a,e>, a : optional<a>, effects-and-types/trace_values) -> trace<a,e> */ 

kk_trace__trace kk_trace__mlift1393_op(kk_function_t _c_1, kk_trace__trace _this, kk_std_core_types__optional a0, kk_std_core_types__optional l0, kk_effects_dash_and_dash_types__exp _c_2, kk_context_t* _ctx); /* forall<a,e> (() -> e a, trace<a,e>, a : optional<a>, l : optional<effects-and-types/trace_values>, effects-and-types/exp) -> trace<a,e> */ 

kk_trace__trace kk_trace__mlift1394_op(kk_trace__trace _this, kk_std_core_types__optional a0, kk_std_core_types__optional l0, kk_std_core_types__optional p0, kk_function_t _c_1, kk_context_t* _ctx); /* forall<a,e> (trace<a,e>, a : optional<a>, l : optional<effects-and-types/trace_values>, p : optional<effects-and-types/exp>, () -> e a) -> trace<a,e> */ 

kk_trace__trace kk_trace__copy(kk_trace__trace _this, kk_std_core_types__optional m0, kk_std_core_types__optional p0, kk_std_core_types__optional l0, kk_std_core_types__optional a0, kk_context_t* _ctx); /* forall<a,e> (trace<a,e>, m : optional<() -> e a>, p : optional<effects-and-types/exp>, l : optional<effects-and-types/trace_values>, a : optional<a>) -> trace<a,e> */ 

kk_integer_t kk_trace__mlift1395_random__range(kk_integer_t upper__bound, double _y_5, kk_context_t* _ctx); /* (upper_bound : int, double) -> effects-and-types/sample int */ 

kk_integer_t kk_trace_random__range(kk_integer_t upper__bound, kk_context_t* _ctx); /* (upper_bound : int) -> effects-and-types/sample int */ 

kk_std_core_types__tuple2_ kk_trace_with__randomness(kk_function_t model, kk_std_core__list trace__values, kk_context_t* _ctx); /* forall<a,e> (model : () -> <effects-and-types/sample,effects-and-types/score|e> a, trace_values : effects-and-types/trace_values) -> <effects-and-types/sample|e> (effects-and-types/trace_values, (effects-and-types/exp, a)) */ 

kk_std_core__list kk_trace__mlift1396_perturb__trace(kk_std_core__list l1, kk_std_core__list l2, double _y_9, kk_context_t* _ctx); /* (l1 : list<double>, l2 : list<double>, double) -> effects-and-types/sample list<double> */ 

kk_std_core__list kk_trace__mlift1397_perturb__trace(kk_std_core__list trace__values, kk_integer_t perturb__index, kk_context_t* _ctx); /* (trace_values : effects-and-types/trace_values, perturb_index : int) -> effects-and-types/sample list<double> */ 

kk_std_core__list kk_trace_perturb__trace(kk_trace__trace trace, kk_context_t* _ctx); /* forall<a,e> (trace : trace<a,e>) -> effects-and-types/sample effects-and-types/trace_values */ 

kk_trace__trace kk_trace__mlift1398_mh__step(kk_box_t b, kk_function_t model, kk_std_core__list new__trace, kk_effects_dash_and_dash_types__exp p2, kk_trace__trace trace, bool accept, kk_context_t* _ctx); /* forall<a,e> (b : a, model : () -> <effects-and-types/sample,effects-and-types/score|e> a, new_trace : effects-and-types/trace_values, p2 : effects-and-types/exp, trace : trace<a,<effects-and-types/sample,effects-and-types/score|e>>, accept : bool) -> <effects-and-types/sample|e> trace<a,<effects-and-types/sample,effects-and-types/score|e>> */ 

kk_trace__trace kk_trace__mlift1399_mh__step(kk_function_t model, kk_std_core__list old__trace, kk_effects_dash_and_dash_types__exp p1, kk_trace__trace trace, kk_std_core_types__tuple2_ p2b, kk_context_t* _ctx); /* forall<a,e> (model : () -> <effects-and-types/sample,effects-and-types/score|e> a, old_trace : effects-and-types/trace_values, p1 : effects-and-types/exp, trace : trace<a,<effects-and-types/sample,effects-and-types/score|e>>, p2b : (effects-and-types/trace_values, (effects-and-types/exp, a))) -> <effects-and-types/sample|e> trace<a,<effects-and-types/sample,effects-and-types/score|e>> */ 

kk_trace__trace kk_trace__mlift1400_mh__step(kk_trace__trace trace, kk_std_core__list modified__trace, kk_context_t* _ctx); /* forall<a,e> (trace : trace<a,<effects-and-types/sample,effects-and-types/score|e>>, modified_trace : effects-and-types/trace_values) -> <effects-and-types/sample|e> trace<a,<effects-and-types/sample,effects-and-types/score|e>> */ 

kk_trace__trace kk_trace_mh__step(kk_trace__trace trace, kk_context_t* _ctx); /* forall<a,e> (trace : trace<a,<effects-and-types/sample,effects-and-types/score|e>>) -> <effects-and-types/sample|e> trace<a,<effects-and-types/sample,effects-and-types/score|e>> */ 

kk_std_core_types__tuple2_ kk_trace__mlift1401_model__stepper__recursive(kk_integer_t burnin, kk_std_core__list posterior, kk_integer_t steps, kk_trace__trace new__trace, kk_context_t* _ctx); /* forall<a,e> (burnin : int, posterior : list<(list<double>, a)>, steps : int, new_trace : trace<a,<effects-and-types/sample,effects-and-types/score,div|e>>) -> <effects-and-types/sample,div|e> (list<(list<double>, a)>, trace<a,<effects-and-types/sample,effects-and-types/score,div|e>>) */ 

kk_std_core_types__tuple2_ kk_trace_model__stepper__recursive(kk_integer_t steps0, kk_trace__trace trace, kk_std_core__list posterior0, kk_integer_t burnin0, kk_context_t* _ctx); /* forall<a,e> (steps : int, trace : trace<a,<effects-and-types/sample,effects-and-types/score,div|e>>, posterior : list<(list<double>, a)>, burnin : int) -> <effects-and-types/sample,div|e> (list<(list<double>, a)>, trace<a,<effects-and-types/sample,effects-and-types/score,div|e>>) */ 

kk_std_core__list kk_trace_splitter(kk_std_core__list lst__as, kk_std_core__list build, kk_context_t* _ctx); /* forall<a> (lst_as : list<a>, build : list<list<a>>) -> div list<list<a>> */ 

static inline kk_std_core__list kk_trace_split__tmcmc(kk_std_core__list lst, kk_context_t* _ctx) { /* forall<a> (lst : list<(list<double>, a)>) -> div list<list<(list<double>, a)>> */ 
  return kk_trace_splitter(lst, kk_std_core__new_Nil(_ctx), _ctx);
}

kk_std_core_types__tuple2_ kk_trace__mlift1402_tmcmc(kk_integer_t burnin, kk_function_t model, kk_integer_t steps, kk_std_core_types__tuple2_ model__results, kk_context_t* _ctx); /* forall<a,e> (burnin : int, model : () -> <effects-and-types/sample,effects-and-types/score,div|e> a, steps : int, model_results : (effects-and-types/exp, (list<double>, a))) -> <div,effects-and-types/sample|e> (list<(list<double>, a)>, trace<a,<effects-and-types/sample,effects-and-types/score,div|e>>) */ 

kk_std_core_types__tuple2_ kk_trace_tmcmc(kk_function_t model, kk_integer_t steps, kk_effects_dash_and_dash_types__exp init__weight, kk_integer_t burnin, kk_context_t* _ctx); /* forall<a,e> (model : () -> <effects-and-types/sample,effects-and-types/score,div|e> a, steps : int, init_weight : effects-and-types/exp, burnin : int) -> <effects-and-types/sample,div|e> (list<(list<double>, a)>, trace<a,<effects-and-types/sample,effects-and-types/score,div|e>>) */ 

void kk_trace__init(kk_context_t* _ctx);

#endif // header
