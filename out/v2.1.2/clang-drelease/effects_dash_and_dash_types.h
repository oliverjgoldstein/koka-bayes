#pragma once
#ifndef kk_effects_dash_and_dash_types_H
#define kk_effects_dash_and_dash_types_H
// Koka generated module: "effects-and-types", koka version: 2.1.2
#include <kklib.h>
#include "std_core_types.h"
#include "std_core_hnd.h"
#include "std_core.h"
#include "std_num_random.h"

// type declarations

// type effects-and-types/.hnd-sample
struct kk_effects_dash_and_dash_types__hnd_sample_s {
  kk_block_t _block;
};
typedef struct kk_effects_dash_and_dash_types__hnd_sample_s* kk_effects_dash_and_dash_types__hnd_sample;
struct kk_effects_dash_and_dash_types__Hnd_sample {
  struct kk_effects_dash_and_dash_types__hnd_sample_s _base;
  kk_std_core_hnd__clause0 fun_sample;
};
static inline kk_effects_dash_and_dash_types__hnd_sample kk_effects_dash_and_dash_types__base_Hnd_sample(struct kk_effects_dash_and_dash_types__Hnd_sample* _x){
  return &_x->_base;
}
static inline kk_effects_dash_and_dash_types__hnd_sample kk_effects_dash_and_dash_types__new_Hnd_sample(kk_reuse_t _at, kk_std_core_hnd__clause0 fun_sample, kk_context_t* _ctx){
  struct kk_effects_dash_and_dash_types__Hnd_sample* _con = kk_block_alloc_at_as(struct kk_effects_dash_and_dash_types__Hnd_sample, _at, 1 /* scan count */, (kk_tag_t)(1), _ctx);
  _con->fun_sample = fun_sample;
  return kk_effects_dash_and_dash_types__base_Hnd_sample(_con);
}
static inline struct kk_effects_dash_and_dash_types__Hnd_sample* kk_effects_dash_and_dash_types__as_Hnd_sample(kk_effects_dash_and_dash_types__hnd_sample x) {
  return kk_basetype_as_assert(struct kk_effects_dash_and_dash_types__Hnd_sample*, x, (kk_tag_t)(1) /* _tag */);
}
static inline bool kk_effects_dash_and_dash_types__is_Hnd_sample(kk_effects_dash_and_dash_types__hnd_sample x) {
  return (true);
}
static inline kk_effects_dash_and_dash_types__hnd_sample kk_effects_dash_and_dash_types__hnd_sample_dup(kk_effects_dash_and_dash_types__hnd_sample _x) {
  return kk_basetype_dup_as(kk_effects_dash_and_dash_types__hnd_sample, _x);
}
static inline void kk_effects_dash_and_dash_types__hnd_sample_drop(kk_effects_dash_and_dash_types__hnd_sample _x, kk_context_t* _ctx) {
  kk_basetype_drop(_x, _ctx);
}
static inline bool kk_effects_dash_and_dash_types__hnd_sample_is_unique(kk_effects_dash_and_dash_types__hnd_sample _x) {
  return kk_basetype_is_unique(_x);
}
static inline void kk_effects_dash_and_dash_types__hnd_sample_free(kk_effects_dash_and_dash_types__hnd_sample _x) {
  kk_basetype_free(_x);
}
static inline void kk_effects_dash_and_dash_types__hnd_sample_decref(kk_effects_dash_and_dash_types__hnd_sample _x, kk_context_t* _ctx) {
  kk_basetype_decref(_x, _ctx);
}
static inline kk_reuse_t kk_effects_dash_and_dash_types__hnd_sample_dropn_reuse(kk_effects_dash_and_dash_types__hnd_sample _x, size_t _scan_fsize, kk_context_t* _ctx) {
  return kk_basetype_dropn_reuse(_x, _scan_fsize, _ctx);
}
static inline void kk_effects_dash_and_dash_types__hnd_sample_dropn(kk_effects_dash_and_dash_types__hnd_sample _x, size_t _scan_fsize, kk_context_t* _ctx) {
  kk_basetype_dropn(_x, _scan_fsize, _ctx);
}
static inline kk_reuse_t kk_effects_dash_and_dash_types__hnd_sample_reuse(kk_effects_dash_and_dash_types__hnd_sample _x) {
  return kk_basetype_reuse(_x);
}
static inline kk_effects_dash_and_dash_types__hnd_sample kk_effects_dash_and_dash_types__hnd_sample_hole() {
  return (kk_effects_dash_and_dash_types__hnd_sample)(1);
}
static inline kk_box_t kk_effects_dash_and_dash_types__hnd_sample_box(kk_effects_dash_and_dash_types__hnd_sample _x, kk_context_t* _ctx) {
  return kk_basetype_box(_x);
}
static inline kk_effects_dash_and_dash_types__hnd_sample kk_effects_dash_and_dash_types__hnd_sample_unbox(kk_box_t _x, kk_context_t* _ctx) {
  return kk_basetype_unbox_as(kk_effects_dash_and_dash_types__hnd_sample, _x);
}

// value type effects-and-types/exp
struct kk_effects_dash_and_dash_types_Exp {
  double i;
};
typedef struct kk_effects_dash_and_dash_types_Exp kk_effects_dash_and_dash_types__exp;
static inline kk_effects_dash_and_dash_types__exp kk_effects_dash_and_dash_types__new_Exp(double i, kk_context_t* _ctx){
  kk_effects_dash_and_dash_types__exp _con = { i };
  return _con;
}
static inline bool kk_effects_dash_and_dash_types__is_Exp(kk_effects_dash_and_dash_types__exp x) {
  return (true);
}
static inline kk_effects_dash_and_dash_types__exp kk_effects_dash_and_dash_types__exp_dup(kk_effects_dash_and_dash_types__exp _x) {
  return _x;
}
static inline void kk_effects_dash_and_dash_types__exp_drop(kk_effects_dash_and_dash_types__exp _x, kk_context_t* _ctx) {
  
}
static inline kk_box_t kk_effects_dash_and_dash_types__exp_box(kk_effects_dash_and_dash_types__exp _x, kk_context_t* _ctx) {
  return kk_double_box(_x.i, _ctx);
}
static inline kk_effects_dash_and_dash_types__exp kk_effects_dash_and_dash_types__exp_unbox(kk_box_t _x, kk_context_t* _ctx) {
  return kk_effects_dash_and_dash_types__new_Exp(kk_double_unbox(_x, _ctx), _ctx);
}

// type effects-and-types/.hnd-score
struct kk_effects_dash_and_dash_types__hnd_score_s {
  kk_block_t _block;
};
typedef struct kk_effects_dash_and_dash_types__hnd_score_s* kk_effects_dash_and_dash_types__hnd_score;
struct kk_effects_dash_and_dash_types__Hnd_score {
  struct kk_effects_dash_and_dash_types__hnd_score_s _base;
  kk_std_core_hnd__clause1 fun_score;
};
static inline kk_effects_dash_and_dash_types__hnd_score kk_effects_dash_and_dash_types__base_Hnd_score(struct kk_effects_dash_and_dash_types__Hnd_score* _x){
  return &_x->_base;
}
static inline kk_effects_dash_and_dash_types__hnd_score kk_effects_dash_and_dash_types__new_Hnd_score(kk_reuse_t _at, kk_std_core_hnd__clause1 fun_score, kk_context_t* _ctx){
  struct kk_effects_dash_and_dash_types__Hnd_score* _con = kk_block_alloc_at_as(struct kk_effects_dash_and_dash_types__Hnd_score, _at, 1 /* scan count */, (kk_tag_t)(1), _ctx);
  _con->fun_score = fun_score;
  return kk_effects_dash_and_dash_types__base_Hnd_score(_con);
}
static inline struct kk_effects_dash_and_dash_types__Hnd_score* kk_effects_dash_and_dash_types__as_Hnd_score(kk_effects_dash_and_dash_types__hnd_score x) {
  return kk_basetype_as_assert(struct kk_effects_dash_and_dash_types__Hnd_score*, x, (kk_tag_t)(1) /* _tag */);
}
static inline bool kk_effects_dash_and_dash_types__is_Hnd_score(kk_effects_dash_and_dash_types__hnd_score x) {
  return (true);
}
static inline kk_effects_dash_and_dash_types__hnd_score kk_effects_dash_and_dash_types__hnd_score_dup(kk_effects_dash_and_dash_types__hnd_score _x) {
  return kk_basetype_dup_as(kk_effects_dash_and_dash_types__hnd_score, _x);
}
static inline void kk_effects_dash_and_dash_types__hnd_score_drop(kk_effects_dash_and_dash_types__hnd_score _x, kk_context_t* _ctx) {
  kk_basetype_drop(_x, _ctx);
}
static inline bool kk_effects_dash_and_dash_types__hnd_score_is_unique(kk_effects_dash_and_dash_types__hnd_score _x) {
  return kk_basetype_is_unique(_x);
}
static inline void kk_effects_dash_and_dash_types__hnd_score_free(kk_effects_dash_and_dash_types__hnd_score _x) {
  kk_basetype_free(_x);
}
static inline void kk_effects_dash_and_dash_types__hnd_score_decref(kk_effects_dash_and_dash_types__hnd_score _x, kk_context_t* _ctx) {
  kk_basetype_decref(_x, _ctx);
}
static inline kk_reuse_t kk_effects_dash_and_dash_types__hnd_score_dropn_reuse(kk_effects_dash_and_dash_types__hnd_score _x, size_t _scan_fsize, kk_context_t* _ctx) {
  return kk_basetype_dropn_reuse(_x, _scan_fsize, _ctx);
}
static inline void kk_effects_dash_and_dash_types__hnd_score_dropn(kk_effects_dash_and_dash_types__hnd_score _x, size_t _scan_fsize, kk_context_t* _ctx) {
  kk_basetype_dropn(_x, _scan_fsize, _ctx);
}
static inline kk_reuse_t kk_effects_dash_and_dash_types__hnd_score_reuse(kk_effects_dash_and_dash_types__hnd_score _x) {
  return kk_basetype_reuse(_x);
}
static inline kk_effects_dash_and_dash_types__hnd_score kk_effects_dash_and_dash_types__hnd_score_hole() {
  return (kk_effects_dash_and_dash_types__hnd_score)(1);
}
static inline kk_box_t kk_effects_dash_and_dash_types__hnd_score_box(kk_effects_dash_and_dash_types__hnd_score _x, kk_context_t* _ctx) {
  return kk_basetype_box(_x);
}
static inline kk_effects_dash_and_dash_types__hnd_score kk_effects_dash_and_dash_types__hnd_score_unbox(kk_box_t _x, kk_context_t* _ctx) {
  return kk_basetype_unbox_as(kk_effects_dash_and_dash_types__hnd_score, _x);
}

// type effects-and-types/.hnd-yield
struct kk_effects_dash_and_dash_types__hnd_yield_s {
  kk_block_t _block;
};
typedef struct kk_effects_dash_and_dash_types__hnd_yield_s* kk_effects_dash_and_dash_types__hnd_yield;
struct kk_effects_dash_and_dash_types__Hnd_yield {
  struct kk_effects_dash_and_dash_types__hnd_yield_s _base;
  kk_std_core_hnd__clause0 control_yield;
};
static inline kk_effects_dash_and_dash_types__hnd_yield kk_effects_dash_and_dash_types__base_Hnd_yield(struct kk_effects_dash_and_dash_types__Hnd_yield* _x){
  return &_x->_base;
}
static inline kk_effects_dash_and_dash_types__hnd_yield kk_effects_dash_and_dash_types__new_Hnd_yield(kk_reuse_t _at, kk_std_core_hnd__clause0 control_yield, kk_context_t* _ctx){
  struct kk_effects_dash_and_dash_types__Hnd_yield* _con = kk_block_alloc_at_as(struct kk_effects_dash_and_dash_types__Hnd_yield, _at, 1 /* scan count */, (kk_tag_t)(1), _ctx);
  _con->control_yield = control_yield;
  return kk_effects_dash_and_dash_types__base_Hnd_yield(_con);
}
static inline struct kk_effects_dash_and_dash_types__Hnd_yield* kk_effects_dash_and_dash_types__as_Hnd_yield(kk_effects_dash_and_dash_types__hnd_yield x) {
  return kk_basetype_as_assert(struct kk_effects_dash_and_dash_types__Hnd_yield*, x, (kk_tag_t)(1) /* _tag */);
}
static inline bool kk_effects_dash_and_dash_types__is_Hnd_yield(kk_effects_dash_and_dash_types__hnd_yield x) {
  return (true);
}
static inline kk_effects_dash_and_dash_types__hnd_yield kk_effects_dash_and_dash_types__hnd_yield_dup(kk_effects_dash_and_dash_types__hnd_yield _x) {
  return kk_basetype_dup_as(kk_effects_dash_and_dash_types__hnd_yield, _x);
}
static inline void kk_effects_dash_and_dash_types__hnd_yield_drop(kk_effects_dash_and_dash_types__hnd_yield _x, kk_context_t* _ctx) {
  kk_basetype_drop(_x, _ctx);
}
static inline bool kk_effects_dash_and_dash_types__hnd_yield_is_unique(kk_effects_dash_and_dash_types__hnd_yield _x) {
  return kk_basetype_is_unique(_x);
}
static inline void kk_effects_dash_and_dash_types__hnd_yield_free(kk_effects_dash_and_dash_types__hnd_yield _x) {
  kk_basetype_free(_x);
}
static inline void kk_effects_dash_and_dash_types__hnd_yield_decref(kk_effects_dash_and_dash_types__hnd_yield _x, kk_context_t* _ctx) {
  kk_basetype_decref(_x, _ctx);
}
static inline kk_reuse_t kk_effects_dash_and_dash_types__hnd_yield_dropn_reuse(kk_effects_dash_and_dash_types__hnd_yield _x, size_t _scan_fsize, kk_context_t* _ctx) {
  return kk_basetype_dropn_reuse(_x, _scan_fsize, _ctx);
}
static inline void kk_effects_dash_and_dash_types__hnd_yield_dropn(kk_effects_dash_and_dash_types__hnd_yield _x, size_t _scan_fsize, kk_context_t* _ctx) {
  kk_basetype_dropn(_x, _scan_fsize, _ctx);
}
static inline kk_reuse_t kk_effects_dash_and_dash_types__hnd_yield_reuse(kk_effects_dash_and_dash_types__hnd_yield _x) {
  return kk_basetype_reuse(_x);
}
static inline kk_effects_dash_and_dash_types__hnd_yield kk_effects_dash_and_dash_types__hnd_yield_hole() {
  return (kk_effects_dash_and_dash_types__hnd_yield)(1);
}
static inline kk_box_t kk_effects_dash_and_dash_types__hnd_yield_box(kk_effects_dash_and_dash_types__hnd_yield _x, kk_context_t* _ctx) {
  return kk_basetype_box(_x);
}
static inline kk_effects_dash_and_dash_types__hnd_yield kk_effects_dash_and_dash_types__hnd_yield_unbox(kk_box_t _x, kk_context_t* _ctx) {
  return kk_basetype_unbox_as(kk_effects_dash_and_dash_types__hnd_yield, _x);
}

// type effects-and-types/sample
struct kk_effects_dash_and_dash_types__sample_s {
  kk_block_t _block;
};
typedef struct kk_effects_dash_and_dash_types__sample_s* kk_effects_dash_and_dash_types__sample;
struct kk_effects_dash_and_dash_types_Sample {
  struct kk_effects_dash_and_dash_types__sample_s _base;
  kk_effects_dash_and_dash_types__hnd_sample _field1;
};
static inline kk_effects_dash_and_dash_types__sample kk_effects_dash_and_dash_types__base_Sample(struct kk_effects_dash_and_dash_types_Sample* _x){
  return &_x->_base;
}
static inline kk_effects_dash_and_dash_types__sample kk_effects_dash_and_dash_types__new_Sample(kk_reuse_t _at, kk_effects_dash_and_dash_types__hnd_sample _field1, kk_context_t* _ctx){
  struct kk_effects_dash_and_dash_types_Sample* _con = kk_block_alloc_at_as(struct kk_effects_dash_and_dash_types_Sample, _at, 1 /* scan count */, (kk_tag_t)(1), _ctx);
  _con->_field1 = _field1;
  return kk_effects_dash_and_dash_types__base_Sample(_con);
}
static inline struct kk_effects_dash_and_dash_types_Sample* kk_effects_dash_and_dash_types__as_Sample(kk_effects_dash_and_dash_types__sample x) {
  return kk_basetype_as_assert(struct kk_effects_dash_and_dash_types_Sample*, x, (kk_tag_t)(1) /* _tag */);
}
static inline bool kk_effects_dash_and_dash_types__is_Sample(kk_effects_dash_and_dash_types__sample x) {
  return (true);
}
static inline kk_effects_dash_and_dash_types__sample kk_effects_dash_and_dash_types__sample_dup(kk_effects_dash_and_dash_types__sample _x) {
  return kk_basetype_dup_as(kk_effects_dash_and_dash_types__sample, _x);
}
static inline void kk_effects_dash_and_dash_types__sample_drop(kk_effects_dash_and_dash_types__sample _x, kk_context_t* _ctx) {
  kk_basetype_drop(_x, _ctx);
}
static inline bool kk_effects_dash_and_dash_types__sample_is_unique(kk_effects_dash_and_dash_types__sample _x) {
  return kk_basetype_is_unique(_x);
}
static inline void kk_effects_dash_and_dash_types__sample_free(kk_effects_dash_and_dash_types__sample _x) {
  kk_basetype_free(_x);
}
static inline void kk_effects_dash_and_dash_types__sample_decref(kk_effects_dash_and_dash_types__sample _x, kk_context_t* _ctx) {
  kk_basetype_decref(_x, _ctx);
}
static inline kk_reuse_t kk_effects_dash_and_dash_types__sample_dropn_reuse(kk_effects_dash_and_dash_types__sample _x, size_t _scan_fsize, kk_context_t* _ctx) {
  return kk_basetype_dropn_reuse(_x, _scan_fsize, _ctx);
}
static inline void kk_effects_dash_and_dash_types__sample_dropn(kk_effects_dash_and_dash_types__sample _x, size_t _scan_fsize, kk_context_t* _ctx) {
  kk_basetype_dropn(_x, _scan_fsize, _ctx);
}
static inline kk_reuse_t kk_effects_dash_and_dash_types__sample_reuse(kk_effects_dash_and_dash_types__sample _x) {
  return kk_basetype_reuse(_x);
}
static inline kk_effects_dash_and_dash_types__sample kk_effects_dash_and_dash_types__sample_hole() {
  return (kk_effects_dash_and_dash_types__sample)(1);
}
static inline kk_box_t kk_effects_dash_and_dash_types__sample_box(kk_effects_dash_and_dash_types__sample _x, kk_context_t* _ctx) {
  return kk_basetype_box(_x);
}
static inline kk_effects_dash_and_dash_types__sample kk_effects_dash_and_dash_types__sample_unbox(kk_box_t _x, kk_context_t* _ctx) {
  return kk_basetype_unbox_as(kk_effects_dash_and_dash_types__sample, _x);
}

// type effects-and-types/score
struct kk_effects_dash_and_dash_types__score_s {
  kk_block_t _block;
};
typedef struct kk_effects_dash_and_dash_types__score_s* kk_effects_dash_and_dash_types__score;
struct kk_effects_dash_and_dash_types_Score {
  struct kk_effects_dash_and_dash_types__score_s _base;
  kk_effects_dash_and_dash_types__hnd_score _field1;
};
static inline kk_effects_dash_and_dash_types__score kk_effects_dash_and_dash_types__base_Score(struct kk_effects_dash_and_dash_types_Score* _x){
  return &_x->_base;
}
static inline kk_effects_dash_and_dash_types__score kk_effects_dash_and_dash_types__new_Score(kk_reuse_t _at, kk_effects_dash_and_dash_types__hnd_score _field1, kk_context_t* _ctx){
  struct kk_effects_dash_and_dash_types_Score* _con = kk_block_alloc_at_as(struct kk_effects_dash_and_dash_types_Score, _at, 1 /* scan count */, (kk_tag_t)(1), _ctx);
  _con->_field1 = _field1;
  return kk_effects_dash_and_dash_types__base_Score(_con);
}
static inline struct kk_effects_dash_and_dash_types_Score* kk_effects_dash_and_dash_types__as_Score(kk_effects_dash_and_dash_types__score x) {
  return kk_basetype_as_assert(struct kk_effects_dash_and_dash_types_Score*, x, (kk_tag_t)(1) /* _tag */);
}
static inline bool kk_effects_dash_and_dash_types__is_Score(kk_effects_dash_and_dash_types__score x) {
  return (true);
}
static inline kk_effects_dash_and_dash_types__score kk_effects_dash_and_dash_types__score_dup(kk_effects_dash_and_dash_types__score _x) {
  return kk_basetype_dup_as(kk_effects_dash_and_dash_types__score, _x);
}
static inline void kk_effects_dash_and_dash_types__score_drop(kk_effects_dash_and_dash_types__score _x, kk_context_t* _ctx) {
  kk_basetype_drop(_x, _ctx);
}
static inline bool kk_effects_dash_and_dash_types__score_is_unique(kk_effects_dash_and_dash_types__score _x) {
  return kk_basetype_is_unique(_x);
}
static inline void kk_effects_dash_and_dash_types__score_free(kk_effects_dash_and_dash_types__score _x) {
  kk_basetype_free(_x);
}
static inline void kk_effects_dash_and_dash_types__score_decref(kk_effects_dash_and_dash_types__score _x, kk_context_t* _ctx) {
  kk_basetype_decref(_x, _ctx);
}
static inline kk_reuse_t kk_effects_dash_and_dash_types__score_dropn_reuse(kk_effects_dash_and_dash_types__score _x, size_t _scan_fsize, kk_context_t* _ctx) {
  return kk_basetype_dropn_reuse(_x, _scan_fsize, _ctx);
}
static inline void kk_effects_dash_and_dash_types__score_dropn(kk_effects_dash_and_dash_types__score _x, size_t _scan_fsize, kk_context_t* _ctx) {
  kk_basetype_dropn(_x, _scan_fsize, _ctx);
}
static inline kk_reuse_t kk_effects_dash_and_dash_types__score_reuse(kk_effects_dash_and_dash_types__score _x) {
  return kk_basetype_reuse(_x);
}
static inline kk_effects_dash_and_dash_types__score kk_effects_dash_and_dash_types__score_hole() {
  return (kk_effects_dash_and_dash_types__score)(1);
}
static inline kk_box_t kk_effects_dash_and_dash_types__score_box(kk_effects_dash_and_dash_types__score _x, kk_context_t* _ctx) {
  return kk_basetype_box(_x);
}
static inline kk_effects_dash_and_dash_types__score kk_effects_dash_and_dash_types__score_unbox(kk_box_t _x, kk_context_t* _ctx) {
  return kk_basetype_unbox_as(kk_effects_dash_and_dash_types__score, _x);
}

// type effects-and-types/yield
struct kk_effects_dash_and_dash_types__yield_s {
  kk_block_t _block;
};
typedef struct kk_effects_dash_and_dash_types__yield_s* kk_effects_dash_and_dash_types__yield;
struct kk_effects_dash_and_dash_types_Yield {
  struct kk_effects_dash_and_dash_types__yield_s _base;
  kk_effects_dash_and_dash_types__hnd_yield _field1;
};
static inline kk_effects_dash_and_dash_types__yield kk_effects_dash_and_dash_types__base_Yield(struct kk_effects_dash_and_dash_types_Yield* _x){
  return &_x->_base;
}
static inline kk_effects_dash_and_dash_types__yield kk_effects_dash_and_dash_types__new_Yield(kk_reuse_t _at, kk_effects_dash_and_dash_types__hnd_yield _field1, kk_context_t* _ctx){
  struct kk_effects_dash_and_dash_types_Yield* _con = kk_block_alloc_at_as(struct kk_effects_dash_and_dash_types_Yield, _at, 1 /* scan count */, (kk_tag_t)(1), _ctx);
  _con->_field1 = _field1;
  return kk_effects_dash_and_dash_types__base_Yield(_con);
}
static inline struct kk_effects_dash_and_dash_types_Yield* kk_effects_dash_and_dash_types__as_Yield(kk_effects_dash_and_dash_types__yield x) {
  return kk_basetype_as_assert(struct kk_effects_dash_and_dash_types_Yield*, x, (kk_tag_t)(1) /* _tag */);
}
static inline bool kk_effects_dash_and_dash_types__is_Yield(kk_effects_dash_and_dash_types__yield x) {
  return (true);
}
static inline kk_effects_dash_and_dash_types__yield kk_effects_dash_and_dash_types__yield_dup(kk_effects_dash_and_dash_types__yield _x) {
  return kk_basetype_dup_as(kk_effects_dash_and_dash_types__yield, _x);
}
static inline void kk_effects_dash_and_dash_types__yield_drop(kk_effects_dash_and_dash_types__yield _x, kk_context_t* _ctx) {
  kk_basetype_drop(_x, _ctx);
}
static inline bool kk_effects_dash_and_dash_types__yield_is_unique(kk_effects_dash_and_dash_types__yield _x) {
  return kk_basetype_is_unique(_x);
}
static inline void kk_effects_dash_and_dash_types__yield_free(kk_effects_dash_and_dash_types__yield _x) {
  kk_basetype_free(_x);
}
static inline void kk_effects_dash_and_dash_types__yield_decref(kk_effects_dash_and_dash_types__yield _x, kk_context_t* _ctx) {
  kk_basetype_decref(_x, _ctx);
}
static inline kk_reuse_t kk_effects_dash_and_dash_types__yield_dropn_reuse(kk_effects_dash_and_dash_types__yield _x, size_t _scan_fsize, kk_context_t* _ctx) {
  return kk_basetype_dropn_reuse(_x, _scan_fsize, _ctx);
}
static inline void kk_effects_dash_and_dash_types__yield_dropn(kk_effects_dash_and_dash_types__yield _x, size_t _scan_fsize, kk_context_t* _ctx) {
  kk_basetype_dropn(_x, _scan_fsize, _ctx);
}
static inline kk_reuse_t kk_effects_dash_and_dash_types__yield_reuse(kk_effects_dash_and_dash_types__yield _x) {
  return kk_basetype_reuse(_x);
}
static inline kk_effects_dash_and_dash_types__yield kk_effects_dash_and_dash_types__yield_hole() {
  return (kk_effects_dash_and_dash_types__yield)(1);
}
static inline kk_box_t kk_effects_dash_and_dash_types__yield_box(kk_effects_dash_and_dash_types__yield _x, kk_context_t* _ctx) {
  return kk_basetype_box(_x);
}
static inline kk_effects_dash_and_dash_types__yield kk_effects_dash_and_dash_types__yield_unbox(kk_box_t _x, kk_context_t* _ctx) {
  return kk_basetype_unbox_as(kk_effects_dash_and_dash_types__yield, _x);
}

// value declarations
 
// Automatically generated. Retrieves the `i` constructor field of the `:exp` type.

static inline double kk_effects_dash_and_dash_types_i(kk_effects_dash_and_dash_types__exp exp, kk_context_t* _ctx) { /* (exp : exp) -> double */ 
  double _x = exp.i;
  return _x;
}

static inline kk_effects_dash_and_dash_types__exp kk_effects_dash_and_dash_types__copy(kk_effects_dash_and_dash_types__exp _this, kk_std_core_types__optional i0, kk_context_t* _ctx) { /* (exp, i : optional<double>) -> exp */ 
  double _x469;
  if (kk_std_core_types__is_Optional(i0)) {
    kk_box_t _box_x399 = i0._cons.Optional.value;
    double _i_176 = kk_double_unbox(_box_x399, NULL);
    _x469 = _i_176; /*double*/
    goto _match470;
  }
  double _x = _this.i;
  _x469 = _x; /*double*/
  _match470: ;
  return kk_effects_dash_and_dash_types__new_Exp(_x469, _ctx);
}

extern kk_std_core_hnd__htag kk_effects_dash_and_dash_types__tag_sample;

kk_box_t kk_effects_dash_and_dash_types__handle_sample(int32_t cfc, kk_effects_dash_and_dash_types__hnd_sample hnd, kk_function_t ret, kk_function_t action, kk_context_t* _ctx); /* forall<a,e,b> (cfc : int32, hnd : .hnd-sample<e,b>, ret : (res : a) -> e b, action : () -> <sample|e> a) -> e b */ 

extern kk_std_core_hnd__htag kk_effects_dash_and_dash_types__tag_score;

kk_box_t kk_effects_dash_and_dash_types__handle_score(int32_t cfc, kk_effects_dash_and_dash_types__hnd_score hnd, kk_function_t ret, kk_function_t action, kk_context_t* _ctx); /* forall<a,e,b> (cfc : int32, hnd : .hnd-score<e,b>, ret : (res : a) -> e b, action : () -> <score|e> a) -> e b */ 

extern kk_std_core_hnd__htag kk_effects_dash_and_dash_types__tag_yield;

kk_box_t kk_effects_dash_and_dash_types__handle_yield(int32_t cfc, kk_effects_dash_and_dash_types__hnd_yield hnd, kk_function_t ret, kk_function_t action, kk_context_t* _ctx); /* forall<a,e,b> (cfc : int32, hnd : .hnd-yield<e,b>, ret : (res : a) -> e b, action : () -> <yield|e> a) -> e b */ 
 
// select `sample` operation out of the `:sample` effect handler

static inline kk_std_core_hnd__clause0 kk_effects_dash_and_dash_types__select_sample(kk_effects_dash_and_dash_types__hnd_sample hnd, kk_context_t* _ctx) { /* forall<e,a> (hnd : .hnd-sample<e,a>) -> std/core/hnd/clause0<double,.hnd-sample,e,a> */ 
  struct kk_effects_dash_and_dash_types__Hnd_sample* _con481 = kk_effects_dash_and_dash_types__as_Hnd_sample(hnd);
  kk_std_core_hnd__clause0 fun_sample = _con481->fun_sample;
  if (kk_effects_dash_and_dash_types__hnd_sample_is_unique(hnd)) {
    kk_effects_dash_and_dash_types__hnd_sample_free(hnd);
  }
  else {
    kk_std_core_hnd__clause0_dup(fun_sample);
    kk_effects_dash_and_dash_types__hnd_sample_decref(hnd, _ctx);
  }
  return fun_sample;
}
 
// select `score` operation out of the `:score` effect handler

static inline kk_std_core_hnd__clause1 kk_effects_dash_and_dash_types__select_score(kk_effects_dash_and_dash_types__hnd_score hnd, kk_context_t* _ctx) { /* forall<e,a> (hnd : .hnd-score<e,a>) -> std/core/hnd/clause1<exp,(),.hnd-score,e,a> */ 
  struct kk_effects_dash_and_dash_types__Hnd_score* _con482 = kk_effects_dash_and_dash_types__as_Hnd_score(hnd);
  kk_std_core_hnd__clause1 fun_score = _con482->fun_score;
  if (kk_effects_dash_and_dash_types__hnd_score_is_unique(hnd)) {
    kk_effects_dash_and_dash_types__hnd_score_free(hnd);
  }
  else {
    kk_std_core_hnd__clause1_dup(fun_score);
    kk_effects_dash_and_dash_types__hnd_score_decref(hnd, _ctx);
  }
  return fun_score;
}
 
// select `yield` operation out of the `:yield` effect handler

static inline kk_std_core_hnd__clause0 kk_effects_dash_and_dash_types__select_yield(kk_effects_dash_and_dash_types__hnd_yield hnd, kk_context_t* _ctx) { /* forall<e,a> (hnd : .hnd-yield<e,a>) -> std/core/hnd/clause0<(),.hnd-yield,e,a> */ 
  struct kk_effects_dash_and_dash_types__Hnd_yield* _con483 = kk_effects_dash_and_dash_types__as_Hnd_yield(hnd);
  kk_std_core_hnd__clause0 control_yield = _con483->control_yield;
  if (kk_effects_dash_and_dash_types__hnd_yield_is_unique(hnd)) {
    kk_effects_dash_and_dash_types__hnd_yield_free(hnd);
  }
  else {
    kk_std_core_hnd__clause0_dup(control_yield);
    kk_effects_dash_and_dash_types__hnd_yield_decref(hnd, _ctx);
  }
  return control_yield;
}
 
// call `sample` operation of the `:sample` effect

static inline double kk_effects_dash_and_dash_types_sample(kk_context_t* _ctx) { /* () -> sample double */ 
  kk_std_core_hnd__ev ev_389;
  size_t _x484 = ((size_t)0); /*size_t*/
  ev_389 = kk_evv_at(_x484,kk_context()); /*std/core/hnd/ev<effects-and-types/.hnd-sample>*/
  kk_box_t _x485;
  struct kk_std_core_hnd_Ev* _con486 = kk_std_core_hnd__as_Ev(ev_389);
  kk_std_core_hnd__marker m = _con486->marker;
  kk_box_t _box_x430 = _con486->hnd;
  kk_effects_dash_and_dash_types__hnd_sample h = kk_effects_dash_and_dash_types__hnd_sample_unbox(_box_x430, NULL);
  kk_effects_dash_and_dash_types__hnd_sample_dup(h);
  kk_std_core_hnd__clause0 _match_468;
  struct kk_effects_dash_and_dash_types__Hnd_sample* _con488 = kk_effects_dash_and_dash_types__as_Hnd_sample(h);
  kk_std_core_hnd__clause0 fun_sample = _con488->fun_sample;
  if (kk_effects_dash_and_dash_types__hnd_sample_is_unique(h)) {
    kk_effects_dash_and_dash_types__hnd_sample_free(h);
  }
  else {
    kk_std_core_hnd__clause0_dup(fun_sample);
    kk_effects_dash_and_dash_types__hnd_sample_decref(h, _ctx);
  }
  _match_468 = fun_sample; /*std/core/hnd/clause0<double,effects-and-types/.hnd-sample,6,7>*/
  kk_function_t _fun_unbox_x433 = _match_468.clause;
  _x485 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x433, (_fun_unbox_x433, m, ev_389, _ctx)); /*6*/
  return kk_double_unbox(_x485, _ctx);
}
 
// call `score` operation of the `:score` effect

static inline kk_unit_t kk_effects_dash_and_dash_types_score(kk_effects_dash_and_dash_types__exp s, kk_context_t* _ctx) { /* (s : exp) -> score () */ 
  kk_std_core_hnd__ev ev_391;
  size_t _x489 = ((size_t)0); /*size_t*/
  ev_391 = kk_evv_at(_x489,kk_context()); /*std/core/hnd/ev<effects-and-types/.hnd-score>*/
  kk_box_t _x490;
  struct kk_std_core_hnd_Ev* _con491 = kk_std_core_hnd__as_Ev(ev_391);
  kk_std_core_hnd__marker m = _con491->marker;
  kk_box_t _box_x438 = _con491->hnd;
  kk_effects_dash_and_dash_types__hnd_score h = kk_effects_dash_and_dash_types__hnd_score_unbox(_box_x438, NULL);
  kk_effects_dash_and_dash_types__hnd_score_dup(h);
  kk_std_core_hnd__clause1 _match_467;
  struct kk_effects_dash_and_dash_types__Hnd_score* _con493 = kk_effects_dash_and_dash_types__as_Hnd_score(h);
  kk_std_core_hnd__clause1 fun_score = _con493->fun_score;
  if (kk_effects_dash_and_dash_types__hnd_score_is_unique(h)) {
    kk_effects_dash_and_dash_types__hnd_score_free(h);
  }
  else {
    kk_std_core_hnd__clause1_dup(fun_score);
    kk_effects_dash_and_dash_types__hnd_score_decref(h, _ctx);
  }
  _match_467 = fun_score; /*std/core/hnd/clause1<effects-and-types/exp,(),effects-and-types/.hnd-score,8,9>*/
  kk_function_t _fun_unbox_x442 = _match_467.clause;
  _x490 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x442, (_fun_unbox_x442, m, ev_391, kk_effects_dash_and_dash_types__exp_box(s, _ctx), _ctx)); /*11*/
  kk_unit_unbox(_x490); return kk_Unit;
}
 
// call `yield` operation of the `:yield` effect

static inline kk_unit_t kk_effects_dash_and_dash_types_yield(kk_context_t* _ctx) { /* () -> yield () */ 
  kk_std_core_hnd__ev ev_394;
  size_t _x494 = ((size_t)0); /*size_t*/
  ev_394 = kk_evv_at(_x494,kk_context()); /*std/core/hnd/ev<effects-and-types/.hnd-yield>*/
  kk_box_t _x495;
  struct kk_std_core_hnd_Ev* _con496 = kk_std_core_hnd__as_Ev(ev_394);
  kk_std_core_hnd__marker m = _con496->marker;
  kk_box_t _box_x449 = _con496->hnd;
  kk_effects_dash_and_dash_types__hnd_yield h = kk_effects_dash_and_dash_types__hnd_yield_unbox(_box_x449, NULL);
  kk_effects_dash_and_dash_types__hnd_yield_dup(h);
  kk_std_core_hnd__clause0 _match_466;
  struct kk_effects_dash_and_dash_types__Hnd_yield* _con498 = kk_effects_dash_and_dash_types__as_Hnd_yield(h);
  kk_std_core_hnd__clause0 control_yield = _con498->control_yield;
  if (kk_effects_dash_and_dash_types__hnd_yield_is_unique(h)) {
    kk_effects_dash_and_dash_types__hnd_yield_free(h);
  }
  else {
    kk_std_core_hnd__clause0_dup(control_yield);
    kk_effects_dash_and_dash_types__hnd_yield_decref(h, _ctx);
  }
  _match_466 = control_yield; /*std/core/hnd/clause0<(),effects-and-types/.hnd-yield,6,7>*/
  kk_function_t _fun_unbox_x452 = _match_466.clause;
  _x495 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x452, (_fun_unbox_x452, m, ev_394, _ctx)); /*6*/
  kk_unit_unbox(_x495); return kk_Unit;
}

void kk_effects_dash_and_dash_types__init(kk_context_t* _ctx);

#endif // header
