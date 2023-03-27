#pragma once
#ifndef kk_std_core_H
#define kk_std_core_H
// Koka generated module: "std/core", koka version: 2.1.2
#include <kklib.h>
#include "std_core_types.h"
#include "std_core_hnd.h"
/*---------------------------------------------------------------------------
  Copyright 2020 Microsoft Corporation.

  This is free software; you can redistribute it and/or modify it under the
  terms of the Apache License, Version 2.0. A copy of the License can be
  found in the file "license.txt" at the root of this distribution.
---------------------------------------------------------------------------*/

kk_box_t kk_std_core_error_pattern(kk_string_t location, kk_string_t definition, kk_context_t* _ctx);

static inline kk_std_core_types__order kk_int_as_order(int i,kk_context_t* ctx) {
  return (i==0 ? kk_std_core_types__new_Eq(ctx) : (i > 0 ? kk_std_core_types__new_Gt(ctx) : kk_std_core_types__new_Lt(ctx)));
}

static inline kk_std_core_types__maybe kk_integer_xparse( kk_string_t s, bool hex, kk_context_t* ctx ) {
  kk_integer_t i;
  bool ok = (hex ? kk_integer_hex_parse(kk_string_cbuf_borrow(s,NULL),&i,ctx) : kk_integer_parse(kk_string_cbuf_borrow(s,NULL),&i,ctx) );
  kk_string_drop(s,ctx);
  return (ok ? kk_std_core_types__new_Just(kk_integer_box(i),ctx) : kk_std_core_types__new_Nothing(ctx));
}

struct kk_std_core_Sslice;

kk_datatype_t kk_string_to_list(kk_string_t s, kk_context_t* ctx);
kk_string_t   kk_string_from_list(kk_datatype_t cs, kk_context_t* ctx);

kk_datatype_t  kk_vector_to_list(kk_vector_t v, kk_datatype_t tail, kk_context_t* ctx);
kk_vector_t    kk_list_to_vector(kk_datatype_t xs, kk_context_t* ctx);

static inline kk_integer_t  kk_string_count_int(kk_string_t s, kk_context_t* ctx) {
  return kk_integer_from_size_t( kk_string_count(s,ctx), ctx );
}

static inline kk_integer_t kk_string_cmp_int(kk_string_t s1, kk_string_t s2, kk_context_t* ctx) {
  return kk_integer_from_small( kk_string_cmp(s1,s2,ctx) );
}

kk_string_t  kk_string_join(kk_vector_t v, kk_context_t* ctx);
kk_string_t  kk_string_join_with(kk_vector_t v, kk_string_t sep, kk_context_t* ctx);
kk_string_t  kk_string_replace_all(kk_string_t str, kk_string_t pattern, kk_string_t repl, kk_context_t* ctx);
static inline kk_integer_t kk_string_count_pattern(kk_string_t str, kk_string_t pattern, kk_context_t* ctx) {
  kk_integer_t count = kk_integer_from_size_t( kk_string_count_pattern_borrow(str,pattern), ctx );
  kk_string_drop(str,ctx);
  kk_string_drop(pattern,ctx);
  return count;
}

kk_integer_t kk_slice_count( struct kk_std_core_Sslice sslice, kk_context_t* ctx );
kk_string_t  kk_slice_to_string( struct kk_std_core_Sslice sslice, kk_context_t* ctx );
struct kk_std_core_Sslice kk_slice_first( kk_string_t str, kk_context_t* ctx );
struct kk_std_core_Sslice kk_slice_last( kk_string_t str, kk_context_t* ctx );

struct kk_std_core_Sslice kk_slice_common_prefix( kk_string_t str1, kk_string_t str2, kk_integer_t upto, kk_context_t* ctx );
struct kk_std_core_Sslice kk_slice_advance( struct kk_std_core_Sslice slice, kk_integer_t count, kk_context_t* ctx );
struct kk_std_core_Sslice kk_slice_extend( struct kk_std_core_Sslice slice, kk_integer_t count, kk_context_t* ctx );
kk_std_core_types__maybe kk_slice_next( struct kk_std_core_Sslice slice, kk_context_t* ctx );


static inline kk_unit_t kk_vector_unsafe_assign( kk_vector_t v, size_t i, kk_box_t x, kk_context_t* ctx  ) {
  size_t len;
  kk_box_t* p = kk_vector_buf(v,&len);
  kk_assert(i < len);
  p[i] = x;
  kk_vector_drop(v,ctx); // TODO: use borrowing
  return kk_Unit;
}

kk_vector_t kk_vector_init( size_t n, kk_function_t init, kk_context_t* ctx);

static inline kk_vector_t kk_vector_allocz( size_t n, kk_context_t* ctx ) {
  return kk_vector_alloc( n, kk_box_null, ctx);
}

static inline kk_box_t kk_vector_at_int( kk_vector_t v, kk_integer_t n, kk_context_t* ctx ) {
  // TODO: check bounds
  return kk_vector_at(v,kk_integer_clamp_size_t(n,ctx));
}

static inline double kk_double_abs(double d) {
  return (isfinite(d) && d < 0.0 ? -d : d);
}

static inline kk_std_core_types__tuple2_ kk_integer_div_mod_tuple(kk_integer_t x, kk_integer_t y, kk_context_t* ctx) {
  kk_integer_t mod;
  kk_integer_t div = kk_integer_div_mod(x,y,&mod,ctx);
  return kk_std_core_types__new_dash__lp__comma__rp_(kk_integer_box(div),kk_integer_box(mod),ctx);
}

kk_box_t kk_main_console( kk_function_t action, kk_context_t* ctx );
kk_unit_t kk_assert_fail( kk_string_t msg, kk_context_t* ctx );

struct kk_std_core_error_s;
struct kk_std_core_error_s kk_error_ok( kk_box_t result, kk_context_t* ctx );
struct kk_std_core_error_s kk_error_from_errno( int err, kk_context_t* ctx );




// type declarations

// type std/core/exception-info
struct kk_std_core__exception_info_s {
  kk_block_t _block;
  kk_string_t _tag;
};
typedef struct kk_std_core__exception_info_s* kk_std_core__exception_info;
struct kk_std_core_ExnError {
  struct kk_std_core__exception_info_s _base;
};
struct kk_std_core_ExnAssert {
  struct kk_std_core__exception_info_s _base;
};
struct kk_std_core_ExnTodo {
  struct kk_std_core__exception_info_s _base;
};
struct kk_std_core_ExnRange {
  struct kk_std_core__exception_info_s _base;
};
struct kk_std_core_ExnPattern {
  struct kk_std_core__exception_info_s _base;
  kk_string_t location;
  kk_string_t definition;
};
struct kk_std_core_ExnSystem {
  struct kk_std_core__exception_info_s _base;
  kk_integer_t kkloc_errno;
};
struct kk_std_core_ExnInternal {
  struct kk_std_core__exception_info_s _base;
  kk_string_t name;
};
static inline kk_std_core__exception_info kk_std_core__base_ExnError(struct kk_std_core_ExnError* _x){
  return &_x->_base;
}
extern kk_string_t kk_std_core__tag_ExnError;
static inline kk_std_core__exception_info kk_std_core__new_ExnError(kk_context_t* _ctx){
  struct kk_std_core_ExnError* _con = kk_block_alloc_at_as(struct kk_std_core_ExnError, kk_reuse_null, 1 /* scan count */, KK_TAG_OPEN, _ctx);
  _con->_base._tag = kk_string_dup(kk_std_core__tag_ExnError);
  return kk_std_core__base_ExnError(_con);
}
static inline struct kk_std_core_ExnError* kk_std_core__as_ExnError(kk_std_core__exception_info x) {
  return kk_basetype_as_assert(struct kk_std_core_ExnError*, x, KK_TAG_OPEN);
}
static inline kk_std_core__exception_info kk_std_core__base_ExnAssert(struct kk_std_core_ExnAssert* _x){
  return &_x->_base;
}
extern kk_string_t kk_std_core__tag_ExnAssert;
static inline kk_std_core__exception_info kk_std_core__new_ExnAssert(kk_context_t* _ctx){
  struct kk_std_core_ExnAssert* _con = kk_block_alloc_at_as(struct kk_std_core_ExnAssert, kk_reuse_null, 1 /* scan count */, KK_TAG_OPEN, _ctx);
  _con->_base._tag = kk_string_dup(kk_std_core__tag_ExnAssert);
  return kk_std_core__base_ExnAssert(_con);
}
static inline struct kk_std_core_ExnAssert* kk_std_core__as_ExnAssert(kk_std_core__exception_info x) {
  return kk_basetype_as_assert(struct kk_std_core_ExnAssert*, x, KK_TAG_OPEN);
}
static inline kk_std_core__exception_info kk_std_core__base_ExnTodo(struct kk_std_core_ExnTodo* _x){
  return &_x->_base;
}
extern kk_string_t kk_std_core__tag_ExnTodo;
static inline kk_std_core__exception_info kk_std_core__new_ExnTodo(kk_context_t* _ctx){
  struct kk_std_core_ExnTodo* _con = kk_block_alloc_at_as(struct kk_std_core_ExnTodo, kk_reuse_null, 1 /* scan count */, KK_TAG_OPEN, _ctx);
  _con->_base._tag = kk_string_dup(kk_std_core__tag_ExnTodo);
  return kk_std_core__base_ExnTodo(_con);
}
static inline struct kk_std_core_ExnTodo* kk_std_core__as_ExnTodo(kk_std_core__exception_info x) {
  return kk_basetype_as_assert(struct kk_std_core_ExnTodo*, x, KK_TAG_OPEN);
}
static inline kk_std_core__exception_info kk_std_core__base_ExnRange(struct kk_std_core_ExnRange* _x){
  return &_x->_base;
}
extern kk_string_t kk_std_core__tag_ExnRange;
static inline kk_std_core__exception_info kk_std_core__new_ExnRange(kk_context_t* _ctx){
  struct kk_std_core_ExnRange* _con = kk_block_alloc_at_as(struct kk_std_core_ExnRange, kk_reuse_null, 1 /* scan count */, KK_TAG_OPEN, _ctx);
  _con->_base._tag = kk_string_dup(kk_std_core__tag_ExnRange);
  return kk_std_core__base_ExnRange(_con);
}
static inline struct kk_std_core_ExnRange* kk_std_core__as_ExnRange(kk_std_core__exception_info x) {
  return kk_basetype_as_assert(struct kk_std_core_ExnRange*, x, KK_TAG_OPEN);
}
static inline kk_std_core__exception_info kk_std_core__base_ExnPattern(struct kk_std_core_ExnPattern* _x){
  return &_x->_base;
}
extern kk_string_t kk_std_core__tag_ExnPattern;
static inline kk_std_core__exception_info kk_std_core__new_ExnPattern(kk_reuse_t _at, kk_string_t location, kk_string_t definition, kk_context_t* _ctx){
  struct kk_std_core_ExnPattern* _con = kk_block_alloc_at_as(struct kk_std_core_ExnPattern, _at, 3 /* scan count */, KK_TAG_OPEN, _ctx);
  _con->_base._tag = kk_string_dup(kk_std_core__tag_ExnPattern);
  _con->location = location;
  _con->definition = definition;
  return kk_std_core__base_ExnPattern(_con);
}
static inline struct kk_std_core_ExnPattern* kk_std_core__as_ExnPattern(kk_std_core__exception_info x) {
  return kk_basetype_as_assert(struct kk_std_core_ExnPattern*, x, KK_TAG_OPEN);
}
static inline kk_std_core__exception_info kk_std_core__base_ExnSystem(struct kk_std_core_ExnSystem* _x){
  return &_x->_base;
}
extern kk_string_t kk_std_core__tag_ExnSystem;
static inline kk_std_core__exception_info kk_std_core__new_ExnSystem(kk_reuse_t _at, kk_integer_t kkloc_errno, kk_context_t* _ctx){
  struct kk_std_core_ExnSystem* _con = kk_block_alloc_at_as(struct kk_std_core_ExnSystem, _at, 2 /* scan count */, KK_TAG_OPEN, _ctx);
  _con->_base._tag = kk_string_dup(kk_std_core__tag_ExnSystem);
  _con->kkloc_errno = kkloc_errno;
  return kk_std_core__base_ExnSystem(_con);
}
static inline struct kk_std_core_ExnSystem* kk_std_core__as_ExnSystem(kk_std_core__exception_info x) {
  return kk_basetype_as_assert(struct kk_std_core_ExnSystem*, x, KK_TAG_OPEN);
}
static inline kk_std_core__exception_info kk_std_core__base_ExnInternal(struct kk_std_core_ExnInternal* _x){
  return &_x->_base;
}
extern kk_string_t kk_std_core__tag_ExnInternal;
static inline kk_std_core__exception_info kk_std_core__new_ExnInternal(kk_reuse_t _at, kk_string_t name, kk_context_t* _ctx){
  struct kk_std_core_ExnInternal* _con = kk_block_alloc_at_as(struct kk_std_core_ExnInternal, _at, 2 /* scan count */, KK_TAG_OPEN, _ctx);
  _con->_base._tag = kk_string_dup(kk_std_core__tag_ExnInternal);
  _con->name = name;
  return kk_std_core__base_ExnInternal(_con);
}
static inline struct kk_std_core_ExnInternal* kk_std_core__as_ExnInternal(kk_std_core__exception_info x) {
  return kk_basetype_as_assert(struct kk_std_core_ExnInternal*, x, KK_TAG_OPEN);
}
static inline bool kk_std_core__is_ExnError(kk_std_core__exception_info x) {
  return (kk_string_ptr_eq_borrow(x->_tag, kk_std_core__tag_ExnError));
}
static inline bool kk_std_core__is_ExnAssert(kk_std_core__exception_info x) {
  return (kk_string_ptr_eq_borrow(x->_tag, kk_std_core__tag_ExnAssert));
}
static inline bool kk_std_core__is_ExnTodo(kk_std_core__exception_info x) {
  return (kk_string_ptr_eq_borrow(x->_tag, kk_std_core__tag_ExnTodo));
}
static inline bool kk_std_core__is_ExnRange(kk_std_core__exception_info x) {
  return (kk_string_ptr_eq_borrow(x->_tag, kk_std_core__tag_ExnRange));
}
static inline bool kk_std_core__is_ExnPattern(kk_std_core__exception_info x) {
  return (kk_string_ptr_eq_borrow(x->_tag, kk_std_core__tag_ExnPattern));
}
static inline bool kk_std_core__is_ExnSystem(kk_std_core__exception_info x) {
  return (kk_string_ptr_eq_borrow(x->_tag, kk_std_core__tag_ExnSystem));
}
static inline bool kk_std_core__is_ExnInternal(kk_std_core__exception_info x) {
  return (kk_string_ptr_eq_borrow(x->_tag, kk_std_core__tag_ExnInternal));
}
static inline kk_std_core__exception_info kk_std_core__exception_info_dup(kk_std_core__exception_info _x) {
  return kk_basetype_dup_as(kk_std_core__exception_info, _x);
}
static inline void kk_std_core__exception_info_drop(kk_std_core__exception_info _x, kk_context_t* _ctx) {
  kk_basetype_drop(_x, _ctx);
}
static inline bool kk_std_core__exception_info_is_unique(kk_std_core__exception_info _x) {
  return kk_basetype_is_unique(_x);
}
static inline void kk_std_core__exception_info_free(kk_std_core__exception_info _x) {
  kk_basetype_free(_x);
}
static inline void kk_std_core__exception_info_decref(kk_std_core__exception_info _x, kk_context_t* _ctx) {
  kk_basetype_decref(_x, _ctx);
}
static inline kk_reuse_t kk_std_core__exception_info_dropn_reuse(kk_std_core__exception_info _x, size_t _scan_fsize, kk_context_t* _ctx) {
  return kk_basetype_dropn_reuse(_x, _scan_fsize, _ctx);
}
static inline void kk_std_core__exception_info_dropn(kk_std_core__exception_info _x, size_t _scan_fsize, kk_context_t* _ctx) {
  kk_basetype_dropn(_x, _scan_fsize, _ctx);
}
static inline kk_reuse_t kk_std_core__exception_info_reuse(kk_std_core__exception_info _x) {
  return kk_basetype_reuse(_x);
}
static inline kk_std_core__exception_info kk_std_core__exception_info_hole() {
  return (kk_std_core__exception_info)(1);
}
static inline kk_box_t kk_std_core__exception_info_box(kk_std_core__exception_info _x, kk_context_t* _ctx) {
  return kk_basetype_box(_x);
}
static inline kk_std_core__exception_info kk_std_core__exception_info_unbox(kk_box_t _x, kk_context_t* _ctx) {
  return kk_basetype_unbox_as(kk_std_core__exception_info, _x);
}

// value type std/core/exception
struct kk_std_core_Exception {
  kk_string_t message;
  kk_std_core__exception_info info;
};
typedef struct kk_std_core_Exception kk_std_core__exception;
static inline kk_std_core__exception kk_std_core__new_Exception(kk_string_t message, kk_std_core__exception_info info, kk_context_t* _ctx){
  kk_std_core__exception _con;
  _con.message = message;
  _con.info = info;
  return _con;
}
static inline bool kk_std_core__is_Exception(kk_std_core__exception x) {
  return (true);
}
static inline kk_std_core__exception kk_std_core__exception_dup(kk_std_core__exception _x) {
  kk_string_dup(_x.message);
  kk_std_core__exception_info_dup(_x.info);
  return _x;
}
static inline void kk_std_core__exception_drop(kk_std_core__exception _x, kk_context_t* _ctx) {
  kk_string_drop(_x.message, _ctx);
  kk_std_core__exception_info_drop(_x.info, _ctx);
}
static inline kk_box_t kk_std_core__exception_box(kk_std_core__exception _x, kk_context_t* _ctx) {
  kk_box_t _box;
  kk_valuetype_box(kk_std_core__exception, _box, _x, 2 /* scan count */, _ctx);
  return _box;
}
static inline kk_std_core__exception kk_std_core__exception_unbox(kk_box_t _x, kk_context_t* _ctx) {
  kk_boxed_value_t _p;
  kk_std_core__exception _unbox;
  kk_valuetype_unbox_(kk_std_core__exception, _p, _unbox, _x, _ctx);
  if (_ctx!=NULL && _p!=NULL) {
    if (kk_basetype_is_unique(_p)) { kk_basetype_free(_p); } else {
      kk_std_core__exception_dup(_unbox);
      kk_basetype_decref(_p, _ctx);
    }
  }
  else { kk_std_core__exception_dup(_unbox); }
  return _unbox;
}

// type std/core/.hnd-exn
struct kk_std_core__hnd_exn_s {
  kk_block_t _block;
};
typedef struct kk_std_core__hnd_exn_s* kk_std_core__hnd_exn;
struct kk_std_core__Hnd_exn {
  struct kk_std_core__hnd_exn_s _base;
  kk_std_core_hnd__clause1 except_throw_exn;
};
static inline kk_std_core__hnd_exn kk_std_core__base_Hnd_exn(struct kk_std_core__Hnd_exn* _x){
  return &_x->_base;
}
static inline kk_std_core__hnd_exn kk_std_core__new_Hnd_exn(kk_reuse_t _at, kk_std_core_hnd__clause1 except_throw_exn, kk_context_t* _ctx){
  struct kk_std_core__Hnd_exn* _con = kk_block_alloc_at_as(struct kk_std_core__Hnd_exn, _at, 1 /* scan count */, (kk_tag_t)(1), _ctx);
  _con->except_throw_exn = except_throw_exn;
  return kk_std_core__base_Hnd_exn(_con);
}
static inline struct kk_std_core__Hnd_exn* kk_std_core__as_Hnd_exn(kk_std_core__hnd_exn x) {
  return kk_basetype_as_assert(struct kk_std_core__Hnd_exn*, x, (kk_tag_t)(1) /* _tag */);
}
static inline bool kk_std_core__is_Hnd_exn(kk_std_core__hnd_exn x) {
  return (true);
}
static inline kk_std_core__hnd_exn kk_std_core__hnd_exn_dup(kk_std_core__hnd_exn _x) {
  return kk_basetype_dup_as(kk_std_core__hnd_exn, _x);
}
static inline void kk_std_core__hnd_exn_drop(kk_std_core__hnd_exn _x, kk_context_t* _ctx) {
  kk_basetype_drop(_x, _ctx);
}
static inline bool kk_std_core__hnd_exn_is_unique(kk_std_core__hnd_exn _x) {
  return kk_basetype_is_unique(_x);
}
static inline void kk_std_core__hnd_exn_free(kk_std_core__hnd_exn _x) {
  kk_basetype_free(_x);
}
static inline void kk_std_core__hnd_exn_decref(kk_std_core__hnd_exn _x, kk_context_t* _ctx) {
  kk_basetype_decref(_x, _ctx);
}
static inline kk_reuse_t kk_std_core__hnd_exn_dropn_reuse(kk_std_core__hnd_exn _x, size_t _scan_fsize, kk_context_t* _ctx) {
  return kk_basetype_dropn_reuse(_x, _scan_fsize, _ctx);
}
static inline void kk_std_core__hnd_exn_dropn(kk_std_core__hnd_exn _x, size_t _scan_fsize, kk_context_t* _ctx) {
  kk_basetype_dropn(_x, _scan_fsize, _ctx);
}
static inline kk_reuse_t kk_std_core__hnd_exn_reuse(kk_std_core__hnd_exn _x) {
  return kk_basetype_reuse(_x);
}
static inline kk_std_core__hnd_exn kk_std_core__hnd_exn_hole() {
  return (kk_std_core__hnd_exn)(1);
}
static inline kk_box_t kk_std_core__hnd_exn_box(kk_std_core__hnd_exn _x, kk_context_t* _ctx) {
  return kk_basetype_box(_x);
}
static inline kk_std_core__hnd_exn kk_std_core__hnd_exn_unbox(kk_box_t _x, kk_context_t* _ctx) {
  return kk_basetype_unbox_as(kk_std_core__hnd_exn, _x);
}

// type std/core/blocking
struct kk_std_core__blocking_s {
  kk_block_t _block;
};
typedef kk_datatype_t kk_std_core__blocking;
static inline kk_std_core__blocking kk_std_core__blocking_dup(kk_std_core__blocking _x) {
  return kk_datatype_dup(_x);
}
static inline void kk_std_core__blocking_drop(kk_std_core__blocking _x, kk_context_t* _ctx) {
  kk_datatype_drop(_x, _ctx);
}
static inline bool kk_std_core__blocking_is_unique(kk_std_core__blocking _x) {
  return kk_datatype_is_unique(_x);
}
static inline void kk_std_core__blocking_free(kk_std_core__blocking _x) {
  kk_datatype_free(_x);
}
static inline void kk_std_core__blocking_decref(kk_std_core__blocking _x, kk_context_t* _ctx) {
  kk_datatype_decref(_x, _ctx);
}
static inline kk_reuse_t kk_std_core__blocking_dropn_reuse(kk_std_core__blocking _x, size_t _scan_fsize, kk_context_t* _ctx) {
  return kk_datatype_dropn_reuse(_x, _scan_fsize, _ctx);
}
static inline void kk_std_core__blocking_dropn(kk_std_core__blocking _x, size_t _scan_fsize, kk_context_t* _ctx) {
  kk_datatype_dropn(_x, _scan_fsize, _ctx);
}
static inline kk_reuse_t kk_std_core__blocking_reuse(kk_std_core__blocking _x) {
  return kk_datatype_reuse(_x);
}
static inline kk_std_core__blocking kk_std_core__blocking_hole() {
  return kk_datatype_from_tag((kk_tag_t)0);
}
static inline kk_box_t kk_std_core__blocking_box(kk_std_core__blocking _x, kk_context_t* _ctx) {
  return kk_datatype_box(_x);
}
static inline kk_std_core__blocking kk_std_core__blocking_unbox(kk_box_t _x, kk_context_t* _ctx) {
  return kk_datatype_unbox(_x);
}

// type std/core/console
struct kk_std_core__console_s {
  kk_block_t _block;
};
typedef kk_datatype_t kk_std_core__console;
static inline kk_std_core__console kk_std_core__console_dup(kk_std_core__console _x) {
  return kk_datatype_dup(_x);
}
static inline void kk_std_core__console_drop(kk_std_core__console _x, kk_context_t* _ctx) {
  kk_datatype_drop(_x, _ctx);
}
static inline bool kk_std_core__console_is_unique(kk_std_core__console _x) {
  return kk_datatype_is_unique(_x);
}
static inline void kk_std_core__console_free(kk_std_core__console _x) {
  kk_datatype_free(_x);
}
static inline void kk_std_core__console_decref(kk_std_core__console _x, kk_context_t* _ctx) {
  kk_datatype_decref(_x, _ctx);
}
static inline kk_reuse_t kk_std_core__console_dropn_reuse(kk_std_core__console _x, size_t _scan_fsize, kk_context_t* _ctx) {
  return kk_datatype_dropn_reuse(_x, _scan_fsize, _ctx);
}
static inline void kk_std_core__console_dropn(kk_std_core__console _x, size_t _scan_fsize, kk_context_t* _ctx) {
  kk_datatype_dropn(_x, _scan_fsize, _ctx);
}
static inline kk_reuse_t kk_std_core__console_reuse(kk_std_core__console _x) {
  return kk_datatype_reuse(_x);
}
static inline kk_std_core__console kk_std_core__console_hole() {
  return kk_datatype_from_tag((kk_tag_t)0);
}
static inline kk_box_t kk_std_core__console_box(kk_std_core__console _x, kk_context_t* _ctx) {
  return kk_datatype_box(_x);
}
static inline kk_std_core__console kk_std_core__console_unbox(kk_box_t _x, kk_context_t* _ctx) {
  return kk_datatype_unbox(_x);
}

// value type std/core/delayed
struct kk_std_core_Delay {
  kk_ref_t dref;
};
typedef struct kk_std_core_Delay kk_std_core__delayed;
static inline kk_std_core__delayed kk_std_core__new_Delay(kk_ref_t dref, kk_context_t* _ctx){
  kk_std_core__delayed _con = { dref };
  return _con;
}
static inline bool kk_std_core__is_Delay(kk_std_core__delayed x) {
  return (true);
}
static inline kk_std_core__delayed kk_std_core__delayed_dup(kk_std_core__delayed _x) {
  kk_ref_dup(_x.dref);
  return _x;
}
static inline void kk_std_core__delayed_drop(kk_std_core__delayed _x, kk_context_t* _ctx) {
  kk_ref_drop(_x.dref, _ctx);
}
static inline kk_box_t kk_std_core__delayed_box(kk_std_core__delayed _x, kk_context_t* _ctx) {
  return kk_ref_box(_x.dref, _ctx);
}
static inline kk_std_core__delayed kk_std_core__delayed_unbox(kk_box_t _x, kk_context_t* _ctx) {
  return kk_std_core__new_Delay(kk_ref_unbox(_x, _ctx), _ctx);
}

// value type std/core/error
struct kk_std_core_Error {
  kk_std_core__exception exception;
};
struct kk_std_core_Ok {
  kk_box_t result;
};
struct kk_std_core_error_s {
  kk_value_tag_t _tag;
  union {
    struct kk_std_core_Error Error;
    struct kk_std_core_Ok Ok;
    kk_box_t _fields[2];
  } _cons;
};
typedef struct kk_std_core_error_s kk_std_core__error;
static inline kk_std_core__error kk_std_core__new_Error(kk_std_core__exception exception, kk_context_t* _ctx){
  kk_std_core__error _con;
  _con._tag = kk_value_tag(1);
  _con._cons.Error.exception = exception;
  return _con;
}
static inline kk_std_core__error kk_std_core__new_Ok(kk_box_t result, kk_context_t* _ctx){
  kk_std_core__error _con;
  _con._tag = kk_value_tag(2);
  _con._cons.Ok.result = result;
  _con._cons._fields[1] = kk_box_null;
  return _con;
}
static inline bool kk_std_core__is_Error(kk_std_core__error x) {
  return (kk_integer_small_eq(x._tag, kk_value_tag(1)));
}
static inline bool kk_std_core__is_Ok(kk_std_core__error x) {
  return (kk_integer_small_eq(x._tag, kk_value_tag(2)));
}
static inline size_t kk_std_core__error_scan_count(kk_std_core__error _x) {
  if (kk_std_core__is_Error(_x)) return 3;
  else return 2;
}
static inline kk_std_core__error kk_std_core__error_dup(kk_std_core__error _x) {
  if (kk_std_core__is_Error(_x)) {
    kk_std_core__exception_dup(_x._cons.Error.exception);
  }
  else {
    kk_box_dup(_x._cons.Ok.result);
  }
  return _x;
}
static inline void kk_std_core__error_drop(kk_std_core__error _x, kk_context_t* _ctx) {
  if (kk_std_core__is_Error(_x)) {
    kk_std_core__exception_drop(_x._cons.Error.exception, _ctx);
  }
  else {
    kk_box_drop(_x._cons.Ok.result, _ctx);
  }
}
static inline kk_box_t kk_std_core__error_box(kk_std_core__error _x, kk_context_t* _ctx) {
  kk_box_t _box;
  kk_valuetype_box(kk_std_core__error, _box, _x, kk_std_core__error_scan_count(_x), _ctx);
  return _box;
}
static inline kk_std_core__error kk_std_core__error_unbox(kk_box_t _x, kk_context_t* _ctx) {
  kk_boxed_value_t _p;
  kk_std_core__error _unbox;
  kk_valuetype_unbox_(kk_std_core__error, _p, _unbox, _x, _ctx);
  if (_ctx!=NULL && _p!=NULL) {
    if (kk_basetype_is_unique(_p)) { kk_basetype_free(_p); } else {
      kk_std_core__error_dup(_unbox);
      kk_basetype_decref(_p, _ctx);
    }
  }
  else { kk_std_core__error_dup(_unbox); }
  return _unbox;
}

// type std/core/exn
struct kk_std_core__exn_s {
  kk_block_t _block;
};
typedef struct kk_std_core__exn_s* kk_std_core__exn;
struct kk_std_core_Exn {
  struct kk_std_core__exn_s _base;
  kk_std_core__hnd_exn _field1;
};
static inline kk_std_core__exn kk_std_core__base_Exn(struct kk_std_core_Exn* _x){
  return &_x->_base;
}
static inline kk_std_core__exn kk_std_core__new_Exn(kk_reuse_t _at, kk_std_core__hnd_exn _field1, kk_context_t* _ctx){
  struct kk_std_core_Exn* _con = kk_block_alloc_at_as(struct kk_std_core_Exn, _at, 1 /* scan count */, (kk_tag_t)(1), _ctx);
  _con->_field1 = _field1;
  return kk_std_core__base_Exn(_con);
}
static inline struct kk_std_core_Exn* kk_std_core__as_Exn(kk_std_core__exn x) {
  return kk_basetype_as_assert(struct kk_std_core_Exn*, x, (kk_tag_t)(1) /* _tag */);
}
static inline bool kk_std_core__is_Exn(kk_std_core__exn x) {
  return (true);
}
static inline kk_std_core__exn kk_std_core__exn_dup(kk_std_core__exn _x) {
  return kk_basetype_dup_as(kk_std_core__exn, _x);
}
static inline void kk_std_core__exn_drop(kk_std_core__exn _x, kk_context_t* _ctx) {
  kk_basetype_drop(_x, _ctx);
}
static inline bool kk_std_core__exn_is_unique(kk_std_core__exn _x) {
  return kk_basetype_is_unique(_x);
}
static inline void kk_std_core__exn_free(kk_std_core__exn _x) {
  kk_basetype_free(_x);
}
static inline void kk_std_core__exn_decref(kk_std_core__exn _x, kk_context_t* _ctx) {
  kk_basetype_decref(_x, _ctx);
}
static inline kk_reuse_t kk_std_core__exn_dropn_reuse(kk_std_core__exn _x, size_t _scan_fsize, kk_context_t* _ctx) {
  return kk_basetype_dropn_reuse(_x, _scan_fsize, _ctx);
}
static inline void kk_std_core__exn_dropn(kk_std_core__exn _x, size_t _scan_fsize, kk_context_t* _ctx) {
  kk_basetype_dropn(_x, _scan_fsize, _ctx);
}
static inline kk_reuse_t kk_std_core__exn_reuse(kk_std_core__exn _x) {
  return kk_basetype_reuse(_x);
}
static inline kk_std_core__exn kk_std_core__exn_hole() {
  return (kk_std_core__exn)(1);
}
static inline kk_box_t kk_std_core__exn_box(kk_std_core__exn _x, kk_context_t* _ctx) {
  return kk_basetype_box(_x);
}
static inline kk_std_core__exn kk_std_core__exn_unbox(kk_box_t _x, kk_context_t* _ctx) {
  return kk_basetype_unbox_as(kk_std_core__exn, _x);
}

// type std/core/fsys
struct kk_std_core__fsys_s {
  kk_block_t _block;
};
typedef kk_datatype_t kk_std_core__fsys;
static inline kk_std_core__fsys kk_std_core__fsys_dup(kk_std_core__fsys _x) {
  return kk_datatype_dup(_x);
}
static inline void kk_std_core__fsys_drop(kk_std_core__fsys _x, kk_context_t* _ctx) {
  kk_datatype_drop(_x, _ctx);
}
static inline bool kk_std_core__fsys_is_unique(kk_std_core__fsys _x) {
  return kk_datatype_is_unique(_x);
}
static inline void kk_std_core__fsys_free(kk_std_core__fsys _x) {
  kk_datatype_free(_x);
}
static inline void kk_std_core__fsys_decref(kk_std_core__fsys _x, kk_context_t* _ctx) {
  kk_datatype_decref(_x, _ctx);
}
static inline kk_reuse_t kk_std_core__fsys_dropn_reuse(kk_std_core__fsys _x, size_t _scan_fsize, kk_context_t* _ctx) {
  return kk_datatype_dropn_reuse(_x, _scan_fsize, _ctx);
}
static inline void kk_std_core__fsys_dropn(kk_std_core__fsys _x, size_t _scan_fsize, kk_context_t* _ctx) {
  kk_datatype_dropn(_x, _scan_fsize, _ctx);
}
static inline kk_reuse_t kk_std_core__fsys_reuse(kk_std_core__fsys _x) {
  return kk_datatype_reuse(_x);
}
static inline kk_std_core__fsys kk_std_core__fsys_hole() {
  return kk_datatype_from_tag((kk_tag_t)0);
}
static inline kk_box_t kk_std_core__fsys_box(kk_std_core__fsys _x, kk_context_t* _ctx) {
  return kk_datatype_box(_x);
}
static inline kk_std_core__fsys kk_std_core__fsys_unbox(kk_box_t _x, kk_context_t* _ctx) {
  return kk_datatype_unbox(_x);
}

// type std/core/global-scope
struct kk_std_core__global_scope_s {
  kk_block_t _block;
};
typedef kk_datatype_t kk_std_core__global_scope;
static inline kk_std_core__global_scope kk_std_core__global_scope_dup(kk_std_core__global_scope _x) {
  return kk_datatype_dup(_x);
}
static inline void kk_std_core__global_scope_drop(kk_std_core__global_scope _x, kk_context_t* _ctx) {
  kk_datatype_drop(_x, _ctx);
}
static inline bool kk_std_core__global_scope_is_unique(kk_std_core__global_scope _x) {
  return kk_datatype_is_unique(_x);
}
static inline void kk_std_core__global_scope_free(kk_std_core__global_scope _x) {
  kk_datatype_free(_x);
}
static inline void kk_std_core__global_scope_decref(kk_std_core__global_scope _x, kk_context_t* _ctx) {
  kk_datatype_decref(_x, _ctx);
}
static inline kk_reuse_t kk_std_core__global_scope_dropn_reuse(kk_std_core__global_scope _x, size_t _scan_fsize, kk_context_t* _ctx) {
  return kk_datatype_dropn_reuse(_x, _scan_fsize, _ctx);
}
static inline void kk_std_core__global_scope_dropn(kk_std_core__global_scope _x, size_t _scan_fsize, kk_context_t* _ctx) {
  kk_datatype_dropn(_x, _scan_fsize, _ctx);
}
static inline kk_reuse_t kk_std_core__global_scope_reuse(kk_std_core__global_scope _x) {
  return kk_datatype_reuse(_x);
}
static inline kk_std_core__global_scope kk_std_core__global_scope_hole() {
  return kk_datatype_from_tag((kk_tag_t)0);
}
static inline kk_box_t kk_std_core__global_scope_box(kk_std_core__global_scope _x, kk_context_t* _ctx) {
  return kk_datatype_box(_x);
}
static inline kk_std_core__global_scope kk_std_core__global_scope_unbox(kk_box_t _x, kk_context_t* _ctx) {
  return kk_datatype_unbox(_x);
}

// type std/core/net
struct kk_std_core__net_s {
  kk_block_t _block;
};
typedef kk_datatype_t kk_std_core__net;
static inline kk_std_core__net kk_std_core__net_dup(kk_std_core__net _x) {
  return kk_datatype_dup(_x);
}
static inline void kk_std_core__net_drop(kk_std_core__net _x, kk_context_t* _ctx) {
  kk_datatype_drop(_x, _ctx);
}
static inline bool kk_std_core__net_is_unique(kk_std_core__net _x) {
  return kk_datatype_is_unique(_x);
}
static inline void kk_std_core__net_free(kk_std_core__net _x) {
  kk_datatype_free(_x);
}
static inline void kk_std_core__net_decref(kk_std_core__net _x, kk_context_t* _ctx) {
  kk_datatype_decref(_x, _ctx);
}
static inline kk_reuse_t kk_std_core__net_dropn_reuse(kk_std_core__net _x, size_t _scan_fsize, kk_context_t* _ctx) {
  return kk_datatype_dropn_reuse(_x, _scan_fsize, _ctx);
}
static inline void kk_std_core__net_dropn(kk_std_core__net _x, size_t _scan_fsize, kk_context_t* _ctx) {
  kk_datatype_dropn(_x, _scan_fsize, _ctx);
}
static inline kk_reuse_t kk_std_core__net_reuse(kk_std_core__net _x) {
  return kk_datatype_reuse(_x);
}
static inline kk_std_core__net kk_std_core__net_hole() {
  return kk_datatype_from_tag((kk_tag_t)0);
}
static inline kk_box_t kk_std_core__net_box(kk_std_core__net _x, kk_context_t* _ctx) {
  return kk_datatype_box(_x);
}
static inline kk_std_core__net kk_std_core__net_unbox(kk_box_t _x, kk_context_t* _ctx) {
  return kk_datatype_unbox(_x);
}

// type std/core/ui
struct kk_std_core__ui_s {
  kk_block_t _block;
};
typedef kk_datatype_t kk_std_core__ui;
static inline kk_std_core__ui kk_std_core__ui_dup(kk_std_core__ui _x) {
  return kk_datatype_dup(_x);
}
static inline void kk_std_core__ui_drop(kk_std_core__ui _x, kk_context_t* _ctx) {
  kk_datatype_drop(_x, _ctx);
}
static inline bool kk_std_core__ui_is_unique(kk_std_core__ui _x) {
  return kk_datatype_is_unique(_x);
}
static inline void kk_std_core__ui_free(kk_std_core__ui _x) {
  kk_datatype_free(_x);
}
static inline void kk_std_core__ui_decref(kk_std_core__ui _x, kk_context_t* _ctx) {
  kk_datatype_decref(_x, _ctx);
}
static inline kk_reuse_t kk_std_core__ui_dropn_reuse(kk_std_core__ui _x, size_t _scan_fsize, kk_context_t* _ctx) {
  return kk_datatype_dropn_reuse(_x, _scan_fsize, _ctx);
}
static inline void kk_std_core__ui_dropn(kk_std_core__ui _x, size_t _scan_fsize, kk_context_t* _ctx) {
  kk_datatype_dropn(_x, _scan_fsize, _ctx);
}
static inline kk_reuse_t kk_std_core__ui_reuse(kk_std_core__ui _x) {
  return kk_datatype_reuse(_x);
}
static inline kk_std_core__ui kk_std_core__ui_hole() {
  return kk_datatype_from_tag((kk_tag_t)0);
}
static inline kk_box_t kk_std_core__ui_box(kk_std_core__ui _x, kk_context_t* _ctx) {
  return kk_datatype_box(_x);
}
static inline kk_std_core__ui kk_std_core__ui_unbox(kk_box_t _x, kk_context_t* _ctx) {
  return kk_datatype_unbox(_x);
}

// type std/core/list
struct kk_std_core__list_s {
  kk_block_t _block;
};
typedef kk_datatype_t kk_std_core__list;
struct kk_std_core_Cons {
  struct kk_std_core__list_s _base;
  kk_box_t head;
  kk_std_core__list tail;
};
static inline kk_std_core__list kk_std_core__new_Nil(kk_context_t* _ctx){
  return kk_datatype_from_tag((kk_tag_t)(1));
}
static inline kk_std_core__list kk_std_core__base_Cons(struct kk_std_core_Cons* _x){
  return kk_datatype_from_base(&_x->_base);
}
static inline kk_std_core__list kk_std_core__new_Cons(kk_reuse_t _at, kk_box_t head, kk_std_core__list tail, kk_context_t* _ctx){
  struct kk_std_core_Cons* _con = kk_block_alloc_at_as(struct kk_std_core_Cons, _at, 2 /* scan count */, (kk_tag_t)(2), _ctx);
  _con->head = head;
  _con->tail = tail;
  return kk_std_core__base_Cons(_con);
}
static inline struct kk_std_core_Cons* kk_std_core__as_Cons(kk_std_core__list x) {
  return kk_datatype_as_assert(struct kk_std_core_Cons*, x, (kk_tag_t)(2) /* _tag */);
}
static inline bool kk_std_core__is_Nil(kk_std_core__list x) {
  return (kk_datatype_is_singleton(x));
}
static inline bool kk_std_core__is_Cons(kk_std_core__list x) {
  return (kk_datatype_is_ptr(x));
}
static inline kk_std_core__list kk_std_core__list_dup(kk_std_core__list _x) {
  return kk_datatype_dup(_x);
}
static inline void kk_std_core__list_drop(kk_std_core__list _x, kk_context_t* _ctx) {
  kk_datatype_drop(_x, _ctx);
}
static inline bool kk_std_core__list_is_unique(kk_std_core__list _x) {
  return kk_datatype_is_unique(_x);
}
static inline void kk_std_core__list_free(kk_std_core__list _x) {
  kk_datatype_free(_x);
}
static inline void kk_std_core__list_decref(kk_std_core__list _x, kk_context_t* _ctx) {
  kk_datatype_decref(_x, _ctx);
}
static inline kk_reuse_t kk_std_core__list_dropn_reuse(kk_std_core__list _x, size_t _scan_fsize, kk_context_t* _ctx) {
  return kk_datatype_dropn_reuse(_x, _scan_fsize, _ctx);
}
static inline void kk_std_core__list_dropn(kk_std_core__list _x, size_t _scan_fsize, kk_context_t* _ctx) {
  kk_datatype_dropn(_x, _scan_fsize, _ctx);
}
static inline kk_reuse_t kk_std_core__list_reuse(kk_std_core__list _x) {
  return kk_datatype_reuse(_x);
}
static inline kk_std_core__list kk_std_core__list_hole() {
  return kk_datatype_from_tag((kk_tag_t)0);
}
static inline kk_box_t kk_std_core__list_box(kk_std_core__list _x, kk_context_t* _ctx) {
  return kk_datatype_box(_x);
}
static inline kk_std_core__list kk_std_core__list_unbox(kk_box_t _x, kk_context_t* _ctx) {
  return kk_datatype_unbox(_x);
}

// type std/core/nmd
struct kk_std_core__nmd_s {
  kk_block_t _block;
};
typedef kk_datatype_t kk_std_core__nmd;
static inline kk_std_core__nmd kk_std_core__nmd_dup(kk_std_core__nmd _x) {
  return kk_datatype_dup(_x);
}
static inline void kk_std_core__nmd_drop(kk_std_core__nmd _x, kk_context_t* _ctx) {
  kk_datatype_drop(_x, _ctx);
}
static inline bool kk_std_core__nmd_is_unique(kk_std_core__nmd _x) {
  return kk_datatype_is_unique(_x);
}
static inline void kk_std_core__nmd_free(kk_std_core__nmd _x) {
  kk_datatype_free(_x);
}
static inline void kk_std_core__nmd_decref(kk_std_core__nmd _x, kk_context_t* _ctx) {
  kk_datatype_decref(_x, _ctx);
}
static inline kk_reuse_t kk_std_core__nmd_dropn_reuse(kk_std_core__nmd _x, size_t _scan_fsize, kk_context_t* _ctx) {
  return kk_datatype_dropn_reuse(_x, _scan_fsize, _ctx);
}
static inline void kk_std_core__nmd_dropn(kk_std_core__nmd _x, size_t _scan_fsize, kk_context_t* _ctx) {
  kk_datatype_dropn(_x, _scan_fsize, _ctx);
}
static inline kk_reuse_t kk_std_core__nmd_reuse(kk_std_core__nmd _x) {
  return kk_datatype_reuse(_x);
}
static inline kk_std_core__nmd kk_std_core__nmd_hole() {
  return kk_datatype_from_tag((kk_tag_t)0);
}
static inline kk_box_t kk_std_core__nmd_box(kk_std_core__nmd _x, kk_context_t* _ctx) {
  return kk_datatype_box(_x);
}
static inline kk_std_core__nmd kk_std_core__nmd_unbox(kk_box_t _x, kk_context_t* _ctx) {
  return kk_datatype_unbox(_x);
}

// type std/core/null
struct kk_std_core__null_s {
  kk_block_t _block;
};
typedef kk_datatype_t kk_std_core__null;
static inline kk_std_core__null kk_std_core__null_dup(kk_std_core__null _x) {
  return kk_datatype_dup(_x);
}
static inline void kk_std_core__null_drop(kk_std_core__null _x, kk_context_t* _ctx) {
  kk_datatype_drop(_x, _ctx);
}
static inline bool kk_std_core__null_is_unique(kk_std_core__null _x) {
  return kk_datatype_is_unique(_x);
}
static inline void kk_std_core__null_free(kk_std_core__null _x) {
  kk_datatype_free(_x);
}
static inline void kk_std_core__null_decref(kk_std_core__null _x, kk_context_t* _ctx) {
  kk_datatype_decref(_x, _ctx);
}
static inline kk_reuse_t kk_std_core__null_dropn_reuse(kk_std_core__null _x, size_t _scan_fsize, kk_context_t* _ctx) {
  return kk_datatype_dropn_reuse(_x, _scan_fsize, _ctx);
}
static inline void kk_std_core__null_dropn(kk_std_core__null _x, size_t _scan_fsize, kk_context_t* _ctx) {
  kk_datatype_dropn(_x, _scan_fsize, _ctx);
}
static inline kk_reuse_t kk_std_core__null_reuse(kk_std_core__null _x) {
  return kk_datatype_reuse(_x);
}
static inline kk_std_core__null kk_std_core__null_hole() {
  return kk_datatype_from_tag((kk_tag_t)0);
}
static inline kk_box_t kk_std_core__null_box(kk_std_core__null _x, kk_context_t* _ctx) {
  return kk_datatype_box(_x);
}
static inline kk_std_core__null kk_std_core__null_unbox(kk_box_t _x, kk_context_t* _ctx) {
  return kk_datatype_unbox(_x);
}

// type std/core/scope
struct kk_std_core__scope_s {
  kk_block_t _block;
};
typedef kk_datatype_t kk_std_core__scope;
static inline kk_std_core__scope kk_std_core__scope_dup(kk_std_core__scope _x) {
  return kk_datatype_dup(_x);
}
static inline void kk_std_core__scope_drop(kk_std_core__scope _x, kk_context_t* _ctx) {
  kk_datatype_drop(_x, _ctx);
}
static inline bool kk_std_core__scope_is_unique(kk_std_core__scope _x) {
  return kk_datatype_is_unique(_x);
}
static inline void kk_std_core__scope_free(kk_std_core__scope _x) {
  kk_datatype_free(_x);
}
static inline void kk_std_core__scope_decref(kk_std_core__scope _x, kk_context_t* _ctx) {
  kk_datatype_decref(_x, _ctx);
}
static inline kk_reuse_t kk_std_core__scope_dropn_reuse(kk_std_core__scope _x, size_t _scan_fsize, kk_context_t* _ctx) {
  return kk_datatype_dropn_reuse(_x, _scan_fsize, _ctx);
}
static inline void kk_std_core__scope_dropn(kk_std_core__scope _x, size_t _scan_fsize, kk_context_t* _ctx) {
  kk_datatype_dropn(_x, _scan_fsize, _ctx);
}
static inline kk_reuse_t kk_std_core__scope_reuse(kk_std_core__scope _x) {
  return kk_datatype_reuse(_x);
}
static inline kk_std_core__scope kk_std_core__scope_hole() {
  return kk_datatype_from_tag((kk_tag_t)0);
}
static inline kk_box_t kk_std_core__scope_box(kk_std_core__scope _x, kk_context_t* _ctx) {
  return kk_datatype_box(_x);
}
static inline kk_std_core__scope kk_std_core__scope_unbox(kk_box_t _x, kk_context_t* _ctx) {
  return kk_datatype_unbox(_x);
}

// value type std/core/sslice
struct kk_std_core_Sslice {
  kk_string_t str;
  size_t start;
  size_t len;
};
typedef struct kk_std_core_Sslice kk_std_core__sslice;
static inline kk_std_core__sslice kk_std_core__new_Sslice(kk_string_t str, size_t start, size_t len, kk_context_t* _ctx){
  kk_std_core__sslice _con;
  _con.str = str;
  _con.start = start;
  _con.len = len;
  return _con;
}
static inline bool kk_std_core__is_Sslice(kk_std_core__sslice x) {
  return (true);
}
static inline kk_std_core__sslice kk_std_core__sslice_dup(kk_std_core__sslice _x) {
  kk_string_dup(_x.str);
  return _x;
}
static inline void kk_std_core__sslice_drop(kk_std_core__sslice _x, kk_context_t* _ctx) {
  kk_string_drop(_x.str, _ctx);
}
static inline kk_box_t kk_std_core__sslice_box(kk_std_core__sslice _x, kk_context_t* _ctx) {
  kk_box_t _box;
  kk_valuetype_box(kk_std_core__sslice, _box, _x, 1 /* scan count */, _ctx);
  return _box;
}
static inline kk_std_core__sslice kk_std_core__sslice_unbox(kk_box_t _x, kk_context_t* _ctx) {
  kk_boxed_value_t _p;
  kk_std_core__sslice _unbox;
  kk_valuetype_unbox_(kk_std_core__sslice, _p, _unbox, _x, _ctx);
  if (_ctx!=NULL && _p!=NULL) {
    if (kk_basetype_is_unique(_p)) { kk_basetype_free(_p); } else {
      kk_std_core__sslice_dup(_unbox);
      kk_basetype_decref(_p, _ctx);
    }
  }
  else { kk_std_core__sslice_dup(_unbox); }
  return _unbox;
}

// type std/core/stream
struct kk_std_core__stream_s {
  kk_block_t _block;
};
typedef struct kk_std_core__stream_s* kk_std_core__stream;
struct kk_std_core_Next {
  struct kk_std_core__stream_s _base;
  kk_box_t head;
  kk_std_core__stream tail;
};
static inline kk_std_core__stream kk_std_core__base_Next(struct kk_std_core_Next* _x){
  return &_x->_base;
}
static inline kk_std_core__stream kk_std_core__new_Next(kk_reuse_t _at, kk_box_t head, kk_std_core__stream tail, kk_context_t* _ctx){
  struct kk_std_core_Next* _con = kk_block_alloc_at_as(struct kk_std_core_Next, _at, 2 /* scan count */, (kk_tag_t)(1), _ctx);
  _con->head = head;
  _con->tail = tail;
  return kk_std_core__base_Next(_con);
}
static inline struct kk_std_core_Next* kk_std_core__as_Next(kk_std_core__stream x) {
  return kk_basetype_as_assert(struct kk_std_core_Next*, x, (kk_tag_t)(1) /* _tag */);
}
static inline bool kk_std_core__is_Next(kk_std_core__stream x) {
  return (true);
}
static inline kk_std_core__stream kk_std_core__stream_dup(kk_std_core__stream _x) {
  return kk_basetype_dup_as(kk_std_core__stream, _x);
}
static inline void kk_std_core__stream_drop(kk_std_core__stream _x, kk_context_t* _ctx) {
  kk_basetype_drop(_x, _ctx);
}
static inline bool kk_std_core__stream_is_unique(kk_std_core__stream _x) {
  return kk_basetype_is_unique(_x);
}
static inline void kk_std_core__stream_free(kk_std_core__stream _x) {
  kk_basetype_free(_x);
}
static inline void kk_std_core__stream_decref(kk_std_core__stream _x, kk_context_t* _ctx) {
  kk_basetype_decref(_x, _ctx);
}
static inline kk_reuse_t kk_std_core__stream_dropn_reuse(kk_std_core__stream _x, size_t _scan_fsize, kk_context_t* _ctx) {
  return kk_basetype_dropn_reuse(_x, _scan_fsize, _ctx);
}
static inline void kk_std_core__stream_dropn(kk_std_core__stream _x, size_t _scan_fsize, kk_context_t* _ctx) {
  kk_basetype_dropn(_x, _scan_fsize, _ctx);
}
static inline kk_reuse_t kk_std_core__stream_reuse(kk_std_core__stream _x) {
  return kk_basetype_reuse(_x);
}
static inline kk_std_core__stream kk_std_core__stream_hole() {
  return (kk_std_core__stream)(1);
}
static inline kk_box_t kk_std_core__stream_box(kk_std_core__stream _x, kk_context_t* _ctx) {
  return kk_basetype_box(_x);
}
static inline kk_std_core__stream kk_std_core__stream_unbox(kk_box_t _x, kk_context_t* _ctx) {
  return kk_basetype_unbox_as(kk_std_core__stream, _x);
}

// value declarations
 
// Automatically generated. Tests for the `ExnError` constructor of the `:exception-info` type.

static inline bool kk_std_core_is_exnError(kk_std_core__exception_info kkloc_exception_info, kk_context_t* _ctx) { /* (exception-info : exception-info) -> bool */ 
  if (kk_std_core__is_ExnError(kkloc_exception_info)) {
    struct kk_std_core_ExnError* _con23654 = kk_std_core__as_ExnError(kkloc_exception_info);
    kk_std_core__exception_info_dropn(kkloc_exception_info, ((int32_t)0), _ctx);
    return true;
  }
  kk_std_core__exception_info_drop(kkloc_exception_info, _ctx);
  return false;
}
 
// Automatically generated. Tests for the `ExnAssert` constructor of the `:exception-info` type.

static inline bool kk_std_core_is_exnAssert(kk_std_core__exception_info kkloc_exception_info, kk_context_t* _ctx) { /* (exception-info : exception-info) -> bool */ 
  if (kk_std_core__is_ExnAssert(kkloc_exception_info)) {
    struct kk_std_core_ExnAssert* _con23655 = kk_std_core__as_ExnAssert(kkloc_exception_info);
    kk_std_core__exception_info_dropn(kkloc_exception_info, ((int32_t)0), _ctx);
    return true;
  }
  kk_std_core__exception_info_drop(kkloc_exception_info, _ctx);
  return false;
}
 
// Automatically generated. Tests for the `ExnTodo` constructor of the `:exception-info` type.

static inline bool kk_std_core_is_exnTodo(kk_std_core__exception_info kkloc_exception_info, kk_context_t* _ctx) { /* (exception-info : exception-info) -> bool */ 
  if (kk_std_core__is_ExnTodo(kkloc_exception_info)) {
    struct kk_std_core_ExnTodo* _con23656 = kk_std_core__as_ExnTodo(kkloc_exception_info);
    kk_std_core__exception_info_dropn(kkloc_exception_info, ((int32_t)0), _ctx);
    return true;
  }
  kk_std_core__exception_info_drop(kkloc_exception_info, _ctx);
  return false;
}
 
// Automatically generated. Tests for the `ExnRange` constructor of the `:exception-info` type.

static inline bool kk_std_core_is_exnRange(kk_std_core__exception_info kkloc_exception_info, kk_context_t* _ctx) { /* (exception-info : exception-info) -> bool */ 
  if (kk_std_core__is_ExnRange(kkloc_exception_info)) {
    struct kk_std_core_ExnRange* _con23657 = kk_std_core__as_ExnRange(kkloc_exception_info);
    kk_std_core__exception_info_dropn(kkloc_exception_info, ((int32_t)0), _ctx);
    return true;
  }
  kk_std_core__exception_info_drop(kkloc_exception_info, _ctx);
  return false;
}
 
// Automatically generated. Tests for the `ExnPattern` constructor of the `:exception-info` type.

static inline bool kk_std_core_is_exnPattern(kk_std_core__exception_info kkloc_exception_info, kk_context_t* _ctx) { /* (exception-info : exception-info) -> bool */ 
  if (kk_std_core__is_ExnPattern(kkloc_exception_info)) {
    struct kk_std_core_ExnPattern* _con23658 = kk_std_core__as_ExnPattern(kkloc_exception_info);
    kk_std_core__exception_info_dropn(kkloc_exception_info, ((int32_t)3), _ctx);
    return true;
  }
  kk_std_core__exception_info_drop(kkloc_exception_info, _ctx);
  return false;
}
 
// Automatically generated. Tests for the `ExnSystem` constructor of the `:exception-info` type.

static inline bool kk_std_core_is_exnSystem(kk_std_core__exception_info kkloc_exception_info, kk_context_t* _ctx) { /* (exception-info : exception-info) -> bool */ 
  if (kk_std_core__is_ExnSystem(kkloc_exception_info)) {
    struct kk_std_core_ExnSystem* _con23659 = kk_std_core__as_ExnSystem(kkloc_exception_info);
    kk_std_core__exception_info_dropn(kkloc_exception_info, ((int32_t)2), _ctx);
    return true;
  }
  kk_std_core__exception_info_drop(kkloc_exception_info, _ctx);
  return false;
}
 
// Automatically generated. Tests for the `ExnInternal` constructor of the `:exception-info` type.

static inline bool kk_std_core_is_exnInternal(kk_std_core__exception_info kkloc_exception_info, kk_context_t* _ctx) { /* (exception-info : exception-info) -> bool */ 
  if (kk_std_core__is_ExnInternal(kkloc_exception_info)) {
    struct kk_std_core_ExnInternal* _con23660 = kk_std_core__as_ExnInternal(kkloc_exception_info);
    kk_std_core__exception_info_dropn(kkloc_exception_info, ((int32_t)2), _ctx);
    return true;
  }
  kk_std_core__exception_info_drop(kkloc_exception_info, _ctx);
  return false;
}

extern kk_string_t kk_std_core__tag_ExnError;

extern kk_string_t kk_std_core__tag_ExnAssert;

extern kk_string_t kk_std_core__tag_ExnTodo;

extern kk_string_t kk_std_core__tag_ExnRange;

extern kk_string_t kk_std_core__tag_ExnPattern;

extern kk_string_t kk_std_core__tag_ExnSystem;

extern kk_string_t kk_std_core__tag_ExnInternal;
 
// Automatically generated. Retrieves the `message` constructor field of the `:exception` type.

static inline kk_string_t kk_std_core_message(kk_std_core__exception exception, kk_context_t* _ctx) { /* (exception : exception) -> string */ 
  kk_string_t _x = exception.message;
  kk_string_dup(_x);
  kk_std_core__exception_drop(exception, _ctx);
  return _x;
}
 
// Automatically generated. Retrieves the `info` constructor field of the `:exception` type.

static inline kk_std_core__exception_info kk_std_core_info(kk_std_core__exception exception, kk_context_t* _ctx) { /* (exception : exception) -> exception-info */ 
  kk_std_core__exception_info _x = exception.info;
  kk_std_core__exception_info_dup(_x);
  kk_std_core__exception_drop(exception, _ctx);
  return _x;
}

kk_std_core__exception kk_std_core__copy(kk_std_core__exception _this, kk_std_core_types__optional message0, kk_std_core_types__optional info0, kk_context_t* _ctx); /* (exception, message : optional<string>, info : optional<exception-info>) -> exception */ 
 
// Automatically generated. Retrieves the `dref` constructor field of the `:delayed` type.

static inline kk_ref_t kk_std_core_dref(kk_std_core__delayed delayed, kk_context_t* _ctx) { /* forall<e,a> (delayed : delayed<e,a>) -> ref<global,either<() -> e a,a>> */ 
  kk_ref_t _x = delayed.dref;
  return _x;
}

kk_std_core__delayed kk_std_core__mlift21167_op(kk_ref_t _c_0, kk_context_t* _ctx); /* forall<e,a> (ref<global,either<() -> e a,a>>) -> delayed<e,a> */ 

kk_std_core__delayed kk_std_core__copy_1(kk_std_core__delayed _this, kk_std_core_types__optional dref0, kk_context_t* _ctx); /* forall<e,a> (delayed<e,a>, dref : optional<ref<global,either<() -> e a,a>>>) -> delayed<e,a> */ 
 
// Automatically generated. Tests for the `Error` constructor of the `:error` type.

static inline bool kk_std_core_is_error(kk_std_core__error error, kk_context_t* _ctx) { /* forall<a> (error : error<a>) -> bool */ 
  if (kk_std_core__is_Error(error)) {
    kk_std_core__exception _pat0 = error._cons.Error.exception;
    kk_std_core__error_drop(error, _ctx);
    return true;
  }
  kk_std_core__error_drop(error, _ctx);
  return false;
}
 
// Automatically generated. Tests for the `Ok` constructor of the `:error` type.

static inline bool kk_std_core_is_ok(kk_std_core__error error, kk_context_t* _ctx) { /* forall<a> (error : error<a>) -> bool */ 
  if (kk_std_core__is_Ok(error)) {
    kk_std_core__error_drop(error, _ctx);
    return true;
  }
  kk_std_core__error_drop(error, _ctx);
  return false;
}
 
// Automatically generated. Tests for the `Nil` constructor of the `:list` type.

static inline bool kk_std_core_is_nil(kk_std_core__list list0, kk_context_t* _ctx) { /* forall<a> (list : list<a>) -> bool */ 
  if (kk_std_core__is_Nil(list0)) {
    return true;
  }
  kk_std_core__list_drop(list0, _ctx);
  return false;
}
 
// Automatically generated. Tests for the `Cons` constructor of the `:list` type.

static inline bool kk_std_core_is_cons(kk_std_core__list list0, kk_context_t* _ctx) { /* forall<a> (list : list<a>) -> bool */ 
  if (kk_std_core__is_Cons(list0)) {
    struct kk_std_core_Cons* _con23674 = kk_std_core__as_Cons(list0);
    kk_std_core__list_dropn(list0, ((int32_t)2), _ctx);
    return true;
  }
  return false;
}
 
// Automatically generated. Retrieves the `str` constructor field of the `:sslice` type.

static inline kk_string_t kk_std_core_str(kk_std_core__sslice sslice, kk_context_t* _ctx) { /* (sslice : sslice) -> string */ 
  kk_string_t _x = sslice.str;
  kk_string_dup(_x);
  kk_std_core__sslice_drop(sslice, _ctx);
  return _x;
}
 
// Automatically generated. Retrieves the `start` constructor field of the `:sslice` type.

static inline size_t kk_std_core_start(kk_std_core__sslice sslice, kk_context_t* _ctx) { /* (sslice : sslice) -> size_t */ 
  size_t _x = sslice.start;
  kk_std_core__sslice_drop(sslice, _ctx);
  return _x;
}
 
// Automatically generated. Retrieves the `len` constructor field of the `:sslice` type.

static inline size_t kk_std_core_len(kk_std_core__sslice sslice, kk_context_t* _ctx) { /* (sslice : sslice) -> size_t */ 
  size_t _x = sslice.len;
  kk_std_core__sslice_drop(sslice, _ctx);
  return _x;
}

kk_std_core__sslice kk_std_core__copy_2(kk_std_core__sslice _this, kk_std_core_types__optional str0, kk_std_core_types__optional start0, kk_std_core_types__optional len0, kk_context_t* _ctx); /* (sslice, str : optional<string>, start : optional<size_t>, len : optional<size_t>) -> sslice */ 
 
// Automatically generated. Retrieves the `head` constructor field of the `:stream` type.

static inline kk_box_t kk_std_core_head(kk_std_core__stream stream, kk_context_t* _ctx) { /* forall<a> (stream : stream<a>) -> a */ 
  struct kk_std_core_Next* _con23684 = kk_std_core__as_Next(stream);
  kk_box_t _x = _con23684->head;
  kk_std_core__stream _pat0 = _con23684->tail;
  if (kk_std_core__stream_is_unique(stream)) {
    kk_std_core__stream_drop(_pat0, _ctx);
    kk_std_core__stream_free(stream);
  }
  else {
    kk_box_dup(_x);
    kk_std_core__stream_decref(stream, _ctx);
  }
  return _x;
}
 
// Automatically generated. Retrieves the `tail` constructor field of the `:stream` type.

static inline kk_std_core__stream kk_std_core_tail(kk_std_core__stream stream, kk_context_t* _ctx) { /* forall<a> (stream : stream<a>) -> stream<a> */ 
  struct kk_std_core_Next* _con23685 = kk_std_core__as_Next(stream);
  kk_box_t _pat0 = _con23685->head;
  kk_std_core__stream _x = _con23685->tail;
  if (kk_std_core__stream_is_unique(stream)) {
    kk_box_drop(_pat0, _ctx);
    kk_std_core__stream_free(stream);
  }
  else {
    kk_std_core__stream_dup(_x);
    kk_std_core__stream_decref(stream, _ctx);
  }
  return _x;
}

kk_std_core__stream kk_std_core__copy_3(kk_std_core__stream _this, kk_std_core_types__optional head0, kk_std_core_types__optional tail0, kk_context_t* _ctx); /* forall<a> (stream<a>, head : optional<a>, tail : optional<stream<a>>) -> stream<a> */ 
 
// select `throw-exn` operation out of the `:exn` effect handler

static inline kk_std_core_hnd__clause1 kk_std_core__select_throw_exn(kk_std_core__hnd_exn hnd, kk_context_t* _ctx) { /* forall<a,e,b> (hnd : .hnd-exn<e,b>) -> std/core/hnd/clause1<exception,a,.hnd-exn,e,b> */ 
  struct kk_std_core__Hnd_exn* _con23692 = kk_std_core__as_Hnd_exn(hnd);
  kk_std_core_hnd__clause1 except_throw_exn = _con23692->except_throw_exn;
  if (kk_std_core__hnd_exn_is_unique(hnd)) {
    kk_std_core__hnd_exn_free(hnd);
  }
  else {
    kk_std_core_hnd__clause1_dup(except_throw_exn);
    kk_std_core__hnd_exn_decref(hnd, _ctx);
  }
  return except_throw_exn;
}

extern kk_std_core_hnd__htag kk_std_core__tag_exn;

kk_box_t kk_std_core__handle_exn(int32_t cfc, kk_std_core__hnd_exn hnd, kk_function_t ret, kk_function_t action, kk_context_t* _ctx); /* forall<a,e,b> (cfc : int32, hnd : .hnd-exn<e,b>, ret : (res : a) -> e b, action : () -> <exn|e> a) -> e b */ 
 
// Internal export for the regex module

static inline kk_std_core__sslice kk_std_core__new_sslice(kk_string_t str0, size_t start0, size_t len0, kk_context_t* _ctx) { /* (str : string, start : size_t, len : size_t) -> sslice */ 
  return kk_std_core__new_Sslice(str0, start0, len0, _ctx);
}

kk_std_core__null kk_std_core__null_any(kk_box_t x, kk_context_t* _ctx); /* forall<a> (x : a) -> null<a> */ 

extern kk_ref_t kk_std_core_redirect;

kk_unit_t kk_std_core_xprintsln(kk_string_t s, kk_context_t* _ctx); /* (s : string) -> console () */ 

kk_integer_t kk_std_core_string_compare(kk_string_t x, kk_string_t y, kk_context_t* _ctx); /* (x : string, y : string) -> int */ 

int32_t kk_std_core_int32(kk_integer_t _arg1, kk_context_t* _ctx); /* (int) -> int32 */ 

size_t kk_std_core_size__t(kk_integer_t i, kk_context_t* _ctx); /* (i : int) -> size_t */ 

kk_string_t kk_std_core_string(kk_char_t c, kk_context_t* _ctx); /* (c : char) -> string */ 

kk_string_t kk_std_core_string_1(kk_vector_t _arg1, kk_context_t* _ctx); /* (vector<char>) -> string */ 

kk_string_t kk_std_core_string_2(kk_std_core__list cs, kk_context_t* _ctx); /* (cs : list<char>) -> total string */ 

kk_string_t kk_std_core_string_3(kk_std_core__sslice slice0, kk_context_t* _ctx); /* (slice : sslice) -> string */ 
 
// Convert a `:maybe` string to a string using the empty sting for `Nothing`

static inline kk_string_t kk_std_core_string_4(kk_std_core_types__maybe ms, kk_context_t* _ctx) { /* (ms : maybe<string>) -> string */ 
  if (kk_std_core_types__is_Nothing(ms)) {
    return kk_string_empty();
  }
  kk_box_t _box_x21920 = ms._cons.Just.value;
  kk_string_t s = kk_string_unbox(_box_x21920);
  return s;
}

kk_std_core__list kk_std_core_vlist(kk_vector_t v, kk_std_core_types__optional tail0, kk_context_t* _ctx); /* forall<a> (v : vector<a>, tail : optional<list<a>>) -> list<a> */ 

kk_string_t kk_std_core_int_show_hex(kk_integer_t i, bool use_capitals, kk_context_t* _ctx); /* (i : int, use-capitals : bool) -> string */ 

kk_string_t kk_std_core_repeatz(kk_string_t s, size_t n, kk_context_t* _ctx); /* (s : string, n : size_t) -> string */ 

kk_string_t kk_std_core_show_expx(double d, int32_t prec, kk_context_t* _ctx); /* (d : double, prec : int32) -> string */ 

kk_string_t kk_std_core_show_fixedx(double d, int32_t prec, kk_context_t* _ctx); /* (d : double, prec : int32) -> string */ 

kk_unit_t kk_std_core_xprints(kk_string_t s, kk_context_t* _ctx); /* (s : string) -> console () */ 

kk_integer_t kk_std_core_pow(kk_integer_t i, kk_integer_t exp, kk_context_t* _ctx); /* (i : int, exp : int) -> int */ 

kk_std_core__sslice kk_std_core_advance(kk_std_core__sslice slice0, kk_integer_t count, kk_context_t* _ctx); /* (slice : sslice, count : int) -> sslice */ 
 
// Apply a function `f` to a specified argument `x`.

static inline kk_box_t kk_std_core_apply(kk_function_t f, kk_box_t x, kk_context_t* _ctx) { /* forall<a,b,e> (f : (a) -> e b, x : a) -> e b */ 
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), f, (f, x, _ctx));
}

kk_unit_t kk_std_core_unsafe_assert_fail(kk_string_t msg, kk_context_t* _ctx); /* (msg : string) -> () */ 

kk_std_core__sslice kk_std_core_extend(kk_std_core__sslice slice0, kk_integer_t count, kk_context_t* _ctx); /* (slice : sslice, count : int) -> sslice */ 

kk_std_core__sslice kk_std_core_first1(kk_string_t s, kk_context_t* _ctx); /* (s : string) -> sslice */ 

kk_string_t kk_std_core_to_upper(kk_string_t s, kk_context_t* _ctx); /* (s : string) -> string */ 

kk_integer_t kk_std_core_cdiv_exp10(kk_integer_t i, kk_integer_t n, kk_context_t* _ctx); /* (i : int, n : int) -> int */ 

kk_integer_t kk_std_core_mul_exp10(kk_integer_t i, kk_integer_t n, kk_context_t* _ctx); /* (i : int, n : int) -> int */ 

kk_std_core__sslice kk_std_core_common_prefix(kk_string_t s, kk_string_t t, kk_std_core_types__optional upto, kk_context_t* _ctx); /* (s : string, t : string, upto : optional<int>) -> sslice */ 

kk_std_core__list kk_std_core__ctail_lift21045_concat(kk_std_core__list ys, kk_std_core__list zss, kk_std_core_types__ctail _acc, kk_context_t* _ctx); /* forall<a> (ys : list<a>, zss : list<list<a>>, ctail<list<a>>) -> list<a> */ 

kk_std_core__list kk_std_core__lift21045_concat(kk_std_core__list ys0, kk_std_core__list zss0, kk_context_t* _ctx); /* forall<a> (ys : list<a>, zss : list<list<a>>) -> list<a> */ 
 
// Concatenate all lists in a list (e.g. flatten the list). (tail-recursive)

static inline kk_std_core__list kk_std_core_concat(kk_std_core__list xss, kk_context_t* _ctx) { /* forall<a> (xss : list<list<a>>) -> list<a> */ 
  return kk_std_core__lift21045_concat(kk_std_core__new_Nil(_ctx), xss, _ctx);
}
 
// The `const` funs returns its first argument and ignores the second.

static inline kk_box_t kk_std_core_const(kk_box_t x, kk_box_t y, kk_context_t* _ctx) { /* forall<a,b> (x : a, y : b) -> a */ 
  kk_box_drop(y, _ctx);
  return x;
}
 
// Return a 'constant' function that ignores its argument and always returns the same result


// lift anonymous function
struct kk_std_core_const_fun23713__t_1 {
  struct kk_function_s _base;
  kk_box_t default0;
};
extern kk_box_t kk_std_core_const_fun23713_1(kk_function_t _fself, kk_box_t ___wildcard__124__7, kk_context_t* _ctx);
static inline kk_function_t kk_std_core_new_const_fun23713_1(kk_box_t default0, kk_context_t* _ctx) {
  struct kk_std_core_const_fun23713__t_1* _self = kk_function_alloc_as(struct kk_std_core_const_fun23713__t_1, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_const_fun23713_1, kk_context());
  _self->default0 = default0;
  return &_self->_base;
}


static inline kk_function_t kk_std_core_const_1(kk_box_t default0, kk_context_t* _ctx) { /* forall<a,b> (default : a) -> total ((x : b) -> a) */ 
  return kk_std_core_new_const_fun23713_1(default0, _ctx);
}

kk_std_core_types__maybe kk_std_core_next(kk_std_core__sslice slice0, kk_context_t* _ctx); /* (slice : sslice) -> maybe<(char, sslice)> */ 

kk_integer_t kk_std_core_count_digits(kk_integer_t i, kk_context_t* _ctx); /* (i : int) -> int */ 
 
// Convert a `:maybe<a>` value to `:a`, using the `nothing` parameter for `Nothing`.

static inline kk_box_t kk_std_core_default(kk_std_core_types__maybe m, kk_box_t nothing, kk_context_t* _ctx) { /* forall<a> (m : maybe<a>, nothing : a) -> a */ 
  if (kk_std_core_types__is_Nothing(m)) {
    return nothing;
  }
  kk_box_t x = m._cons.Just.value;
  kk_box_drop(nothing, _ctx);
  return x;
}
 
// Use default value `def` in case of an error.

static inline kk_box_t kk_std_core_default_1(kk_std_core__error t, kk_box_t def, kk_context_t* _ctx) { /* forall<a> (t : error<a>, def : a) -> a */ 
  if (kk_std_core__is_Error(t)) {
    kk_std_core__exception _pat0 = t._cons.Error.exception;
    kk_std_core__error_drop(t, _ctx);
    return def;
  }
  kk_box_t x = t._cons.Ok.result;
  kk_box_drop(def, _ctx);
  return x;
}

kk_std_core_types__either kk_std_core_either(kk_std_core__error t, kk_context_t* _ctx); /* forall<a> (t : error<a>) -> either<exception,a> */ 

bool kk_std_core_xends_with(kk_string_t s, kk_string_t post, kk_context_t* _ctx); /* (s : string, post : string) -> bool */ 

kk_std_core__list kk_std_core__mlift21168_op(kk_std_core_types__ctail _acc, kk_function_t f, kk_std_core__list zz, kk_std_core__list ys1_21065, kk_context_t* _ctx); /* forall<a,b,e> (ctail<list<b>>, f : (a) -> e list<b>, zz : list<a>, ys1.21065 : list<b>) -> e list<b> */ 

kk_std_core__list kk_std_core__mlift21169_op(kk_function_t _accm, kk_function_t f0, kk_std_core__list zz0, kk_std_core__list ys1_210650, kk_context_t* _ctx); /* forall<a,b,e> ((list<b>) -> list<b>, f : (a) -> e list<b>, zz : list<a>, ys1.21065 : list<b>) -> e list<b> */ 

kk_std_core__list kk_std_core__ctail_lift21046_flatmap(kk_function_t f1, kk_std_core__list ys, kk_std_core__list zs, kk_std_core_types__ctail _acc0, kk_context_t* _ctx); /* forall<a,b,e> (f : (a) -> e list<b>, ys : list<b>, zs : list<a>, ctail<list<b>>) -> e list<b> */ 

kk_std_core__list kk_std_core__ctailm_lift21046_flatmap(kk_function_t f2, kk_std_core__list ys0, kk_std_core__list zs0, kk_function_t _accm0, kk_context_t* _ctx); /* forall<a,b,e> (f : (a) -> e list<b>, ys : list<b>, zs : list<a>, (list<b>) -> list<b>) -> e list<b> */ 

kk_std_core__list kk_std_core__lift21046_flatmap(kk_function_t f3, kk_std_core__list ys1, kk_std_core__list zs1, kk_context_t* _ctx); /* forall<a,b,e> (f : (a) -> e list<b>, ys : list<b>, zs : list<a>) -> e list<b> */ 
 
// Concatenate the result lists from applying a function to all elements.

static inline kk_std_core__list kk_std_core_flatmap(kk_std_core__list xs, kk_function_t f, kk_context_t* _ctx) { /* forall<a,b,e> (xs : list<a>, f : (a) -> e list<b>) -> e list<b> */ 
  return kk_std_core__lift21046_flatmap(f, kk_std_core__new_Nil(_ctx), xs, _ctx);
}

kk_std_core__list kk_std_core__lift21047_reverse_append(kk_std_core__list acc, kk_std_core__list ys, kk_context_t* _ctx); /* forall<a> (acc : list<a>, ys : list<a>) -> list<a> */ 
 
// Efficiently reverse a list `xs` and append it to `tl`:
// `reverse-append(xs,tl) == reserve(xs) ++ tl

static inline kk_std_core__list kk_std_core_reverse_append(kk_std_core__list xs, kk_std_core__list tl, kk_context_t* _ctx) { /* forall<a> (xs : list<a>, tl : list<a>) -> list<a> */ 
  return kk_std_core__lift21047_reverse_append(tl, xs, _ctx);
}

kk_box_t kk_std_core__mlift21170_force(kk_ref_t r, kk_box_t x0, kk_context_t* _ctx); /* forall<a,e> (r : ref<global,either<() -> e a,a>>, x0 : a) -> <st<global>,div|e> a */ 

kk_box_t kk_std_core_force(kk_std_core__delayed delayed, kk_context_t* _ctx); /* forall<a,e> (delayed : delayed<e,a>) -> e a */ 

kk_string_t kk_std_core_gshow(kk_box_t _arg1, kk_context_t* _ctx); /* forall<a> (a) -> string */ 

kk_string_t kk_std_core_host(kk_context_t* _ctx); /* () -> ndet string */ 
 
// The `ignore` function ignores its argument.

static inline kk_unit_t kk_std_core_ignore(kk_box_t x, kk_context_t* _ctx) { /* forall<a> (x : a) -> () */ 
  kk_box_drop(x, _ctx);
  kk_Unit; return kk_Unit;
}

kk_std_core__list kk_std_core__ctail_lift21048_intersperse(kk_std_core__list ys, kk_box_t s, kk_std_core_types__ctail _acc, kk_context_t* _ctx); /* forall<a> (ys : list<a>, s : a, ctail<list<a>>) -> list<a> */ 

kk_std_core__list kk_std_core__lift21048_intersperse(kk_std_core__list ys0, kk_box_t s0, kk_context_t* _ctx); /* forall<a> (ys : list<a>, s : a) -> list<a> */ 

kk_std_core__list kk_std_core_intersperse(kk_std_core__list xs, kk_box_t sep, kk_context_t* _ctx); /* forall<a> (xs : list<a>, sep : a) -> list<a> */ 
 
// Is this an even integer?

static inline bool kk_std_core_is_even(kk_integer_t i, kk_context_t* _ctx) { /* (i : int) -> bool */ 
  bool _x23760 = kk_integer_is_odd(i,kk_context()); /*bool*/
  return !(_x23760);
}

kk_integer_t kk_std_core_is_exp10(kk_integer_t i, kk_context_t* _ctx); /* (i : int) -> int */ 

kk_std_core__sslice kk_std_core_last1(kk_string_t s, kk_context_t* _ctx); /* (s : string) -> sslice */ 

kk_box_t kk_std_core_main_console(kk_function_t main, kk_context_t* _ctx); /* forall<a,e> (main : () -> e a) -> e a */ 

kk_std_core__list kk_std_core__mlift21171_op(kk_std_core_types__ctail _acc, kk_function_t f, kk_std_core__list yy, kk_box_t _ctail_21115, kk_context_t* _ctx); /* forall<a,b,e> (ctail<list<b>>, f : (value : a, rest : list<a>) -> e b, yy : list<a>, b) -> e list<b> */ 

kk_std_core__list kk_std_core__mlift21172_op(kk_function_t _accm, kk_function_t f0, kk_std_core__list yy0, kk_box_t _ctail_21120, kk_context_t* _ctx); /* forall<a,b,e> ((list<b>) -> list<b>, f : (value : a, rest : list<a>) -> e b, yy : list<a>, b) -> e list<b> */ 

kk_std_core__list kk_std_core__ctail_lift21049_map_peek(kk_function_t f1, kk_std_core__list ys, kk_std_core_types__ctail _acc0, kk_context_t* _ctx); /* forall<a,b,e> (f : (value : a, rest : list<a>) -> e b, ys : list<a>, ctail<list<b>>) -> e list<b> */ 

kk_std_core__list kk_std_core__ctailm_lift21049_map_peek(kk_function_t f2, kk_std_core__list ys0, kk_function_t _accm0, kk_context_t* _ctx); /* forall<a,b,e> (f : (value : a, rest : list<a>) -> e b, ys : list<a>, (list<b>) -> list<b>) -> e list<b> */ 

kk_std_core__list kk_std_core__lift21049_map_peek(kk_function_t f3, kk_std_core__list ys1, kk_context_t* _ctx); /* forall<a,b,e> (f : (value : a, rest : list<a>) -> e b, ys : list<a>) -> e list<b> */ 
 
// Apply a function `f`  to each element of the input list in sequence where `f` takes
// both the current element and the tail list as arguments.

static inline kk_std_core__list kk_std_core_map_peek(kk_std_core__list xs, kk_function_t f, kk_context_t* _ctx) { /* forall<a,b,e> (xs : list<a>, f : (value : a, rest : list<a>) -> e b) -> e list<b> */ 
  return kk_std_core__lift21049_map_peek(f, xs, _ctx);
}

extern kk_integer_t kk_std_core_maxListStack;

static inline kk_integer_t kk_std_core_mbint(kk_std_core_types__maybe m, kk_context_t* _ctx) { /* (m : maybe<int>) -> int */ 
  if (kk_std_core_types__is_Nothing(m)) {
    return kk_integer_from_small(0);
  }
  kk_box_t _box_x22066 = m._cons.Just.value;
  kk_integer_t i = kk_integer_unbox(_box_x22066);
  return i;
}

static inline kk_integer_t kk_std_core_negate(kk_integer_t i, kk_context_t* _ctx) { /* (i : int) -> int */ 
  return kk_integer_neg(i,kk_context());
}

extern kk_ref_t kk_std_core_trace_enabled;

kk_function_t kk_std_core_o(kk_function_t f, kk_function_t g, kk_context_t* _ctx); /* forall<a,b,c,e> (f : (a) -> e b, g : (c) -> e a) -> ((x : c) -> e b) */ 
 
// Set a `hndler` that is always called when the `action` finishes (either normally or with an exception).

static inline kk_box_t kk_std_core_on_exit(kk_function_t _x123788, kk_function_t _x223789, kk_context_t* _ctx) { /* forall<a,e> (hndler : () -> e (), action : () -> e a) -> e a */ 
  return kk_std_core_hnd_finally(_x123788, _x223789, _ctx);
}

kk_function_t kk_std_core_once(kk_function_t calc, kk_context_t* _ctx); /* forall<a> (calc : () -> a) -> (() -> a) */ 

kk_std_core_types__maybe kk_std_core_xparse_int(kk_string_t s, bool hex, kk_context_t* _ctx); /* (s : string, hex : bool) -> maybe<int> */ 

kk_box_t kk_std_core_phantom(kk_context_t* _ctx); /* forall<a> () -> a */ 
 
// Returns a singleton list.

static inline kk_std_core__list kk_std_core_single(kk_box_t x, kk_context_t* _ctx) { /* forall<a> (x : a) -> list<a> */ 
  return kk_std_core__new_Cons(kk_reuse_null, x, kk_std_core__new_Nil(_ctx), _ctx);
}

kk_string_t kk_std_core_to_lower(kk_string_t s, kk_context_t* _ctx); /* (s : string) -> string */ 

kk_unit_t kk_std_core_xtrace(kk_string_t message0, kk_context_t* _ctx); /* (message : string) -> () */ 

kk_unit_t kk_std_core_xtrace_any(kk_string_t message0, kk_box_t x, kk_context_t* _ctx); /* forall<a> (message : string, x : a) -> () */ 

extern kk_ref_t kk_std_core_unique_count;
 
// _Unsafe_. This function removes the non-termination effect (`:div`) from the effect of an action

static inline kk_box_t kk_std_core_unsafe_nodiv(kk_function_t _x123794, kk_context_t* _ctx) { /* forall<a,e> (action : () -> <div|e> a) -> e a */ 
  return kk_std_core_types_unsafe_total(_x123794, _ctx);
}
 
// _Unsafe_. This function removes the exception effect (`:exn`) from the effect of an action

static inline kk_box_t kk_std_core_unsafe_noexn(kk_function_t _x123795, kk_context_t* _ctx) { /* forall<a,e> (action : () -> <exn|e> a) -> e a */ 
  return kk_std_core_types_unsafe_total(_x123795, _ctx);
}

kk_vector_t kk_std_core_unvlist(kk_std_core__list xs, kk_context_t* _ctx); /* forall<a> (xs : list<a>) -> vector<a> */ 

kk_vector_t kk_std_core_vector_initz(size_t n, kk_function_t f, kk_context_t* _ctx); /* forall<a> (n : size_t, f : (size_t) -> a) -> vector<a> */ 
 
// Substract two character codePoints

static inline kk_char_t kk_std_core__lp__dash__4_rp_(kk_char_t c, kk_char_t d, kk_context_t* _ctx) { /* (c : char, d : char) -> total char */ 
  kk_integer_t _x23796;
  kk_integer_t _x23797 = kk_integer_from_int(c,kk_context()); /*int*/
  kk_integer_t _x23798 = kk_integer_from_int(d,kk_context()); /*int*/
  _x23796 = kk_integer_sub(_x23797,_x23798,kk_context()); /*int*/
  return kk_integer_clamp32(_x23796,kk_context());
}

static inline kk_integer_t kk_std_core_int_4(bool b, kk_context_t* _ctx) { /* (b : bool) -> int */ 
  if (b) {
    return kk_integer_from_small(1);
  }
  return kk_integer_from_small(0);
}

static inline kk_integer_t kk_std_core_int_5(kk_std_core_types__order x, kk_context_t* _ctx) { /* (x : order) -> int */ 
  if (kk_std_core_types__is_Lt(x)) {
    return kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context());
  }
  if (kk_std_core_types__is_Eq(x)) {
    return kk_integer_from_small(0);
  }
  return kk_integer_from_small(1);
}

static inline bool kk_std_core__lp__excl__eq__4_rp_(kk_std_core_types__order x, kk_std_core_types__order y, kk_context_t* _ctx) { /* (x : order, y : order) -> bool */ 
  kk_integer_t _x23799 = kk_std_core_int_5(x, _ctx); /*int*/
  kk_integer_t _x23800 = kk_std_core_int_5(y, _ctx); /*int*/
  return kk_integer_neq(_x23799,_x23800,kk_context());
}

static inline bool kk_std_core__lp__excl__eq__5_rp_(bool x, bool y, kk_context_t* _ctx) { /* (x : bool, y : bool) -> bool */ 
  if (x) {
    return !(y);
  }
  return y;
}
 
// Add two character code points

static inline kk_char_t kk_std_core__lp__plus__4_rp_(kk_char_t c, kk_char_t d, kk_context_t* _ctx) { /* (c : char, d : char) -> total char */ 
  kk_integer_t _x23801;
  kk_integer_t _x23802 = kk_integer_from_int(c,kk_context()); /*int*/
  kk_integer_t _x23803 = kk_integer_from_int(d,kk_context()); /*int*/
  _x23801 = kk_integer_add(_x23802,_x23803,kk_context()); /*int*/
  return kk_integer_clamp32(_x23801,kk_context());
}

kk_std_core__list kk_std_core__ctail_append(kk_std_core__list xs, kk_std_core__list ys, kk_std_core_types__ctail _acc, kk_context_t* _ctx); /* forall<a> (xs : list<a>, ys : list<a>, ctail<list<a>>) -> list<a> */ 

kk_std_core__list kk_std_core_append(kk_std_core__list xs0, kk_std_core__list ys0, kk_context_t* _ctx); /* forall<a> (xs : list<a>, ys : list<a>) -> list<a> */ 
 
// Append two lists.

static inline kk_std_core__list kk_std_core__lp__plus__plus__rp_(kk_std_core__list _x123811, kk_std_core__list _x223812, kk_context_t* _ctx) { /* forall<a> (xs : list<a>, ys : list<a>) -> list<a> */ 
  return kk_std_core_append(_x123811, _x223812, _ctx);
}

kk_string_t kk_std_core__lp__plus__plus__1_rp_(kk_string_t x, kk_string_t y, kk_context_t* _ctx); /* (x : string, y : string) -> string */ 

kk_unit_t kk_std_core_printsln(kk_string_t s, kk_context_t* _ctx); /* (s : string) -> console () */ 

static inline bool kk_std_core__lp__eq__eq__4_rp_(kk_std_core_types__order x, kk_std_core_types__order y, kk_context_t* _ctx) { /* (x : order, y : order) -> bool */ 
  kk_integer_t _x23819 = kk_std_core_int_5(x, _ctx); /*int*/
  kk_integer_t _x23820 = kk_std_core_int_5(y, _ctx); /*int*/
  return kk_integer_eq(_x23819,_x23820,kk_context());
}

static inline bool kk_std_core__lp__eq__eq__5_rp_(bool x, bool y, kk_context_t* _ctx) { /* (x : bool, y : bool) -> bool */ 
  if (x) {
    return y;
  }
  return !(y);
}

static inline bool kk_std_core__lp__lt__5_rp_(kk_std_core_types__order x, kk_std_core_types__order y, kk_context_t* _ctx) { /* (x : order, y : order) -> bool */ 
  kk_integer_t _x23821 = kk_std_core_int_5(x, _ctx); /*int*/
  kk_integer_t _x23822 = kk_std_core_int_5(y, _ctx); /*int*/
  return kk_integer_lt(_x23821,_x23822,kk_context());
}

static inline bool kk_std_core__lp__lt__6_rp_(bool x, bool y, kk_context_t* _ctx) { /* (x : bool, y : bool) -> bool */ 
  bool _match_23639 = !(x); /*bool*/;
  if (_match_23639) {
    return y;
  }
  return false;
}

kk_std_core_types__order kk_std_core_order(kk_integer_t i, kk_context_t* _ctx); /* (i : int) -> order */ 

kk_std_core_types__order kk_std_core_compare_4(kk_string_t x, kk_string_t y, kk_context_t* _ctx); /* (x : string, y : string) -> order */ 

bool kk_std_core__lp__lt__7_rp_(kk_string_t x, kk_string_t y, kk_context_t* _ctx); /* (x : string, y : string) -> bool */ 

static inline bool kk_std_core__lp__gt__3_rp_(kk_std_core_types__order x, kk_std_core_types__order y, kk_context_t* _ctx) { /* (x : order, y : order) -> bool */ 
  kk_integer_t _x23829 = kk_std_core_int_5(x, _ctx); /*int*/
  kk_integer_t _x23830 = kk_std_core_int_5(y, _ctx); /*int*/
  return kk_integer_gt(_x23829,_x23830,kk_context());
}

static inline bool kk_std_core__lp__gt__4_rp_(bool x, bool y, kk_context_t* _ctx) { /* (x : bool, y : bool) -> bool */ 
  if (x) {
    return !(y);
  }
  return false;
}

bool kk_std_core__lp__gt__5_rp_(kk_string_t x, kk_string_t y, kk_context_t* _ctx); /* (x : string, y : string) -> bool */ 

static inline kk_std_core_types__order kk_std_core_compare_1(kk_char_t x, kk_char_t y, kk_context_t* _ctx) { /* (x : char, y : char) -> order */ 
  bool _match_23631 = (x < y); /*bool*/;
  if (_match_23631) {
    return kk_std_core_types__new_Lt(_ctx);
  }
  bool _match_23632 = (x > y); /*bool*/;
  if (_match_23632) {
    return kk_std_core_types__new_Gt(_ctx);
  }
  return kk_std_core_types__new_Eq(_ctx);
}

static inline kk_std_core_types__order kk_std_core_compare_2(bool x, bool y, kk_context_t* _ctx) { /* (x : bool, y : bool) -> order */ 
  bool _match_23629 = kk_std_core__lp__lt__6_rp_(x, y, _ctx); /*bool*/;
  if (_match_23629) {
    return kk_std_core_types__new_Lt(_ctx);
  }
  bool _match_23630 = kk_std_core__lp__gt__4_rp_(x, y, _ctx); /*bool*/;
  if (_match_23630) {
    return kk_std_core_types__new_Gt(_ctx);
  }
  return kk_std_core_types__new_Eq(_ctx);
}

static inline kk_std_core_types__order kk_std_core_compare_3(double x, double y, kk_context_t* _ctx) { /* (x : double, y : double) -> order */ 
  bool _match_23627 = (x < y); /*bool*/;
  if (_match_23627) {
    return kk_std_core_types__new_Lt(_ctx);
  }
  bool _match_23628 = (x > y); /*bool*/;
  if (_match_23628) {
    return kk_std_core_types__new_Gt(_ctx);
  }
  return kk_std_core_types__new_Eq(_ctx);
}

static inline bool kk_std_core__lp__gt__eq__3_rp_(kk_std_core_types__order x, kk_std_core_types__order y, kk_context_t* _ctx) { /* (x : order, y : order) -> bool */ 
  kk_integer_t _x23835 = kk_std_core_int_5(x, _ctx); /*int*/
  kk_integer_t _x23836 = kk_std_core_int_5(y, _ctx); /*int*/
  return kk_integer_gte(_x23835,_x23836,kk_context());
}

static inline bool kk_std_core__lp__gt__eq__4_rp_(bool x, bool y, kk_context_t* _ctx) { /* (x : bool, y : bool) -> bool */ 
  bool _x23837 = kk_std_core__lp__lt__6_rp_(x, y, _ctx); /*bool*/
  return !(_x23837);
}

bool kk_std_core__lp__gt__eq__5_rp_(kk_string_t x, kk_string_t y, kk_context_t* _ctx); /* (x : string, y : string) -> bool */ 

kk_string_t kk_std_core__lift21050_joinsep(kk_string_t sep, kk_std_core__list ys, kk_string_t acc, kk_context_t* _ctx); /* (sep : string, ys : list<string>, acc : string) -> string */ 

kk_string_t kk_std_core_joinsep(kk_std_core__list xs, kk_string_t sep, kk_context_t* _ctx); /* (xs : list<string>, sep : string) -> string */ 

kk_string_t kk_std_core_join_2(kk_std_core__list xs, kk_context_t* _ctx); /* (xs : list<string>) -> string */ 
 
// Concatenate all strings in a list using a specific separator

static inline kk_string_t kk_std_core_join_3(kk_std_core__list _x123854, kk_string_t _x223855, kk_context_t* _ctx) { /* (xs : list<string>, sep : string) -> string */ 
  return kk_std_core_joinsep(_x123854, _x223855, _ctx);
}

static inline int32_t kk_std_core_decr(int32_t i, kk_context_t* _ctx) { /* (i : int32) -> int32 */ 
  return (i - (((int32_t)1)));
}

size_t kk_std_core_decr_1(size_t i, kk_context_t* _ctx); /* (i : size_t) -> size_t */ 

static inline bool kk_std_core__lp__lt__eq__5_rp_(kk_std_core_types__order x, kk_std_core_types__order y, kk_context_t* _ctx) { /* (x : order, y : order) -> bool */ 
  kk_integer_t _x23856 = kk_std_core_int_5(x, _ctx); /*int*/
  kk_integer_t _x23857 = kk_std_core_int_5(y, _ctx); /*int*/
  return kk_integer_lte(_x23856,_x23857,kk_context());
}

static inline bool kk_std_core__lp__lt__eq__6_rp_(bool x, bool y, kk_context_t* _ctx) { /* (x : bool, y : bool) -> bool */ 
  bool _x23858 = kk_std_core__lp__gt__4_rp_(x, y, _ctx); /*bool*/
  return !(_x23858);
}

bool kk_std_core__lp__lt__eq__7_rp_(kk_string_t x, kk_string_t y, kk_context_t* _ctx); /* (x : string, y : string) -> bool */ 

static inline int32_t kk_std_core_incr(int32_t i, kk_context_t* _ctx) { /* (i : int32) -> int32 */ 
  return (i + (((int32_t)1)));
}

size_t kk_std_core_incr_1(size_t i, kk_context_t* _ctx); /* (i : size_t) -> size_t */ 

kk_unit_t kk_std_core__mlift21173_op(kk_function_t action, size_t end, size_t i, kk_unit_t wild__, kk_context_t* _ctx); /* forall<e> (action : (size_t) -> e (), end : size_t, i : size_t, wild_ : ()) -> e () */ 

kk_unit_t kk_std_core__lift21051_forz(kk_function_t action0, size_t end0, size_t i0, kk_context_t* _ctx); /* forall<e> (action : (size_t) -> e (), end : size_t, i : size_t) -> e () */ 
 
// Executes `action`  for each integer between `start`  upto `end`  (including both `start`  and `end` ).
// If `start > end`  the function returns without any call to `action` .

static inline kk_unit_t kk_std_core_forz(size_t start0, size_t end, kk_function_t action, kk_context_t* _ctx) { /* forall<e> (start : size_t, end : size_t, action : (size_t) -> e ()) -> e () */ 
  kk_std_core__lift21051_forz(action, end, start0, _ctx); return kk_Unit;
}

kk_unit_t kk_std_core_foreach_indexedz(kk_vector_t v, kk_function_t f, kk_context_t* _ctx); /* forall<a,e> (v : vector<a>, f : (a, size_t) -> e ()) -> e () */ 

kk_integer_t kk_std_core__lift21052_length_1(kk_std_core__list ys, kk_integer_t acc, kk_context_t* _ctx); /* forall<a> (ys : list<a>, acc : int) -> int */ 
 
// Returns the length of a list.

static inline kk_integer_t kk_std_core_length_1(kk_std_core__list xs, kk_context_t* _ctx) { /* forall<a> (xs : list<a>) -> int */ 
  return kk_std_core__lift21052_length_1(xs, kk_integer_from_small(0), _ctx);
}
 
// Return the length of a vector.

static inline kk_integer_t kk_std_core_length_2(kk_vector_t v, kk_context_t* _ctx) { /* forall<a> (v : vector<a>) -> int */ 
  size_t _x23874 = kk_vector_len(v); /*size_t*/
  return kk_integer_from_size_t(_x23874,kk_context());
}

kk_std_core__list kk_std_core__lift21053_list(kk_integer_t low, kk_integer_t high, kk_std_core__list acc, kk_context_t* _ctx); /* (low : int, high : int, acc : list<int>) -> list<int> */ 
 
// Returns an integer list of increasing elements from `lo`  to `hi`
// (including both `lo`  and `hi` ).
// If `lo > hi`  the function returns the empty list.

static inline kk_std_core__list kk_std_core_list(kk_integer_t lo, kk_integer_t hi, kk_context_t* _ctx) { /* (lo : int, hi : int) -> total list<int> */ 
  return kk_std_core__lift21053_list(lo, hi, kk_std_core__new_Nil(_ctx), _ctx);
}

kk_std_core__list kk_std_core__mlift21174_op(kk_std_core__list acc, kk_function_t f, kk_integer_t high0_21076, kk_integer_t low, kk_box_t _y_46, kk_context_t* _ctx); /* forall<a,e> (acc : list<a>, f : (int) -> e a, high0.21076 : int, low : int, a) -> e list<a> */ 

kk_std_core__list kk_std_core__lift21054_list_1(kk_function_t f0, kk_integer_t low0, kk_integer_t high, kk_std_core__list acc0, kk_context_t* _ctx); /* forall<a,e> (f : (int) -> e a, low : int, high : int, acc : list<a>) -> e list<a> */ 
 
// Applies a function `f` to list of increasing elements from `lo`  to `hi`
// (including both `lo`  and `hi` ).
// If `lo > hi`  the function returns the empty list.

static inline kk_std_core__list kk_std_core_list_1(kk_integer_t lo, kk_integer_t hi, kk_function_t f, kk_context_t* _ctx) { /* forall<a,e> (lo : int, hi : int, f : (int) -> e a) -> e list<a> */ 
  return kk_std_core__lift21054_list_1(f, lo, hi, kk_std_core__new_Nil(_ctx), _ctx);
}

kk_std_core__list kk_std_core__mlift21175_op(kk_std_core_types__ctail _acc, kk_function_t f, kk_std_core__list xx, kk_box_t _ctail_21123, kk_context_t* _ctx); /* forall<a,b,e> (ctail<list<b>>, f : (a) -> e b, xx : list<a>, b) -> e list<b> */ 

kk_std_core__list kk_std_core__mlift21176_op(kk_function_t _accm, kk_function_t f0, kk_std_core__list xx0, kk_box_t _ctail_21128, kk_context_t* _ctx); /* forall<a,b,e> ((list<b>) -> list<b>, f : (a) -> e b, xx : list<a>, b) -> e list<b> */ 

kk_std_core__list kk_std_core__ctail_map_5(kk_std_core__list xs, kk_function_t f1, kk_std_core_types__ctail _acc0, kk_context_t* _ctx); /* forall<a,b,e> (xs : list<a>, f : (a) -> e b, ctail<list<b>>) -> e list<b> */ 

kk_std_core__list kk_std_core__ctailm_map_5(kk_std_core__list xs0, kk_function_t f2, kk_function_t _accm0, kk_context_t* _ctx); /* forall<a,b,e> (xs : list<a>, f : (a) -> e b, (list<b>) -> list<b>) -> e list<b> */ 

kk_std_core__list kk_std_core_map_5(kk_std_core__list xs1, kk_function_t f3, kk_context_t* _ctx); /* forall<a,b,e> (xs : list<a>, f : (a) -> e b) -> e list<b> */ 

kk_std_core__list kk_std_core_list_2(kk_char_t lo, kk_char_t hi, kk_context_t* _ctx); /* (lo : char, hi : char) -> total list<char> */ 
 
// Convert a `:maybe` type to a list type.

static inline kk_std_core__list kk_std_core_list_3(kk_std_core_types__maybe m, kk_context_t* _ctx) { /* forall<a> (m : maybe<a>) -> list<a> */ 
  if (kk_std_core_types__is_Nothing(m)) {
    return kk_std_core__new_Nil(_ctx);
  }
  kk_box_t x = m._cons.Just.value;
  return kk_std_core__new_Cons(kk_reuse_null, x, kk_std_core__new_Nil(_ctx), _ctx);
}

kk_std_core__list kk_std_core_list_4(kk_string_t s, kk_context_t* _ctx); /* (s : string) -> total list<char> */ 
 
// Convert a vector to a list.

static inline kk_std_core__list kk_std_core_list_5(kk_vector_t v, kk_context_t* _ctx) { /* forall<a> (v : vector<a>) -> list<a> */ 
  return kk_std_core_vlist(v, kk_std_core_types__new_None(_ctx), _ctx);
}

kk_std_core_types__maybe kk_std_core__mlift21177_map(kk_box_t _y_59, kk_context_t* _ctx); /* forall<a,e> (a) -> e maybe<a> */ 

kk_std_core_types__maybe kk_std_core_map(kk_std_core_types__maybe m, kk_function_t f, kk_context_t* _ctx); /* forall<a,b,e> (m : maybe<a>, f : (a) -> e b) -> e maybe<b> */ 

kk_std_core_types__either kk_std_core__mlift21178_map_1(kk_box_t _y_61, kk_context_t* _ctx); /* forall<a,b,e> (b) -> e either<a,b> */ 

kk_std_core_types__either kk_std_core_map_1(kk_std_core_types__either e, kk_function_t f, kk_context_t* _ctx); /* forall<a,b,c,e> (e : either<a,b>, f : (b) -> e c) -> e either<a,c> */ 

kk_std_core_types__tuple2_ kk_std_core__mlift21179_map_2(kk_box_t _y_63, kk_box_t _y_64, kk_context_t* _ctx); /* forall<a,e> (a, a) -> e (a, a) */ 

kk_std_core_types__tuple2_ kk_std_core__mlift21180_map_2(kk_function_t f, kk_std_core_types__tuple2_ t, kk_box_t _y_63, kk_context_t* _ctx); /* forall<a,b,e> (f : (a) -> e b, t : (a, a), b) -> e (b, b) */ 

kk_std_core_types__tuple2_ kk_std_core_map_2(kk_std_core_types__tuple2_ t, kk_function_t f, kk_context_t* _ctx); /* forall<a,b,e> (t : (a, a), f : (a) -> e b) -> e (b, b) */ 

kk_std_core_types__tuple3_ kk_std_core__mlift21181_map_3(kk_box_t _y_65, kk_box_t _y_66, kk_box_t _y_67, kk_context_t* _ctx); /* forall<a,e> (a, a, a) -> e (a, a, a) */ 

kk_std_core_types__tuple3_ kk_std_core__mlift21182_map_3(kk_box_t _y_65, kk_function_t f, kk_std_core_types__tuple3_ t, kk_box_t _y_66, kk_context_t* _ctx); /* forall<a,b,e> (b, f : (a) -> e b, t : (a, a, a), b) -> e (b, b, b) */ 

kk_std_core_types__tuple3_ kk_std_core__mlift21183_map_3(kk_function_t f, kk_std_core_types__tuple3_ t, kk_box_t _y_65, kk_context_t* _ctx); /* forall<a,b,e> (f : (a) -> e b, t : (a, a, a), b) -> e (b, b, b) */ 

kk_std_core_types__tuple3_ kk_std_core_map_3(kk_std_core_types__tuple3_ t, kk_function_t f, kk_context_t* _ctx); /* forall<a,b,e> (t : (a, a, a), f : (a) -> e b) -> e (b, b, b) */ 

kk_std_core_types__tuple4_ kk_std_core__mlift21184_map_4(kk_box_t _y_68, kk_box_t _y_69, kk_box_t _y_70, kk_box_t _y_71, kk_context_t* _ctx); /* forall<a,e> (a, a, a, a) -> e (a, a, a, a) */ 

kk_std_core_types__tuple4_ kk_std_core__mlift21185_map_4(kk_box_t _y_68, kk_box_t _y_69, kk_function_t f, kk_std_core_types__tuple4_ t, kk_box_t _y_70, kk_context_t* _ctx); /* forall<a,b,e> (b, b, f : (a) -> e b, t : (a, a, a, a), b) -> e (b, b, b, b) */ 

kk_std_core_types__tuple4_ kk_std_core__mlift21186_map_4(kk_box_t _y_68, kk_function_t f, kk_std_core_types__tuple4_ t, kk_box_t _y_69, kk_context_t* _ctx); /* forall<a,b,e> (b, f : (a) -> e b, t : (a, a, a, a), b) -> e (b, b, b, b) */ 

kk_std_core_types__tuple4_ kk_std_core__mlift21187_map_4(kk_function_t f, kk_std_core_types__tuple4_ t, kk_box_t _y_68, kk_context_t* _ctx); /* forall<a,b,e> (f : (a) -> e b, t : (a, a, a, a), b) -> e (b, b, b, b) */ 

kk_std_core_types__tuple4_ kk_std_core_map_4(kk_std_core_types__tuple4_ t, kk_function_t f, kk_context_t* _ctx); /* forall<a,b,e> (t : (a, a, a, a), f : (a) -> e b) -> e (b, b, b, b) */ 

kk_string_t kk_std_core_map_6(kk_string_t s, kk_function_t f, kk_context_t* _ctx); /* forall<e> (s : string, f : (char) -> e char) -> e string */ 

kk_unit_t kk_std_core__mlift21188_map_7(size_t i, kk_vector_t w, kk_box_t _y_73, kk_context_t* _ctx); /* forall<a,e> (i : size_t, w : vector<a>, a) -> e () */ 

kk_vector_t kk_std_core__mlift21189_map_7(kk_vector_t w, kk_unit_t wild__, kk_context_t* _ctx); /* forall<a,e> (w : vector<a>, wild_ : ()) -> e vector<a> */ 

kk_vector_t kk_std_core_map_7(kk_vector_t v, kk_function_t f, kk_context_t* _ctx); /* forall<a,b,e> (v : vector<a>, f : (a) -> e b) -> e vector<b> */ 

kk_string_t kk_std_core_pad_left(kk_string_t s, kk_integer_t width, kk_std_core_types__optional fill, kk_context_t* _ctx); /* (s : string, width : int, fill : optional<char>) -> string */ 

kk_string_t kk_std_core_show_hex(kk_integer_t i, kk_std_core_types__optional width, kk_std_core_types__optional use_capitals, kk_std_core_types__optional pre, kk_context_t* _ctx); /* (i : int, width : optional<int>, use-capitals : optional<bool>, pre : optional<string>) -> string */ 

static inline kk_std_core_types__order kk_std_core_sign_1(double d, kk_context_t* _ctx) { /* (d : double) -> order */ 
  bool _match_23592 = (d < (0x0p+0)); /*bool*/;
  if (_match_23592) {
    return kk_std_core_types__new_Lt(_ctx);
  }
  bool _match_23593 = (d > (0x0p+0)); /*bool*/;
  if (_match_23593) {
    return kk_std_core_types__new_Gt(_ctx);
  }
  return kk_std_core_types__new_Eq(_ctx);
}

bool kk_std_core_is_pos_2(kk_integer_t i, kk_context_t* _ctx); /* (i : int) -> bool */ 
 
// Is the value positive?

static inline bool kk_std_core_is_pos_3(double d, kk_context_t* _ctx) { /* (d : double) -> bool */ 
  return (d > (0x0p+0));
}
 
// Is the list empty?

static inline bool kk_std_core_is_empty(kk_std_core__list xs, kk_context_t* _ctx) { /* forall<a> (xs : list<a>) -> bool */ 
  if (kk_std_core__is_Nil(xs)) {
    return true;
  }
  kk_std_core__list_drop(xs, _ctx);
  return false;
}
 
// Is a slice empty?

static inline bool kk_std_core_is_empty_1(kk_std_core__sslice slice0, kk_context_t* _ctx) { /* (slice : sslice) -> bool */ 
  bool _x24051;
  size_t _x24052;
  size_t _x = slice0.len;
  kk_std_core__sslice_drop(slice0, _ctx);
  _x24052 = _x; /*size_t*/
  _x24051 = (_x24052 > 0); /*bool*/
  return !(_x24051);
}
 
// Is a string empty?

static inline bool kk_std_core_is_empty_2(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> bool */ 
  kk_string_t _x24053 = kk_string_empty(); /*string*/
  return kk_string_is_eq(s,_x24053,kk_context());
}

static inline kk_std_core_types__maybe kk_std_core__lp__bar__bar__rp_(kk_std_core_types__maybe m1, kk_std_core_types__maybe m2, kk_context_t* _ctx) { /* forall<a> (m1 : maybe<a>, m2 : maybe<a>) -> maybe<a> */ 
  if (kk_std_core_types__is_Nothing(m1)) {
    return m2;
  }
  kk_std_core_types__maybe_drop(m2, _ctx);
  return m1;
}
 
// Choose a non-empty string

static inline kk_string_t kk_std_core__lp__bar__bar__1_rp_(kk_string_t x, kk_string_t y, kk_context_t* _ctx) { /* (x : string, y : string) -> string */ 
  bool _match_23590;
  kk_string_t _x24055 = kk_string_dup(x); /*string*/
  _match_23590 = kk_std_core_is_empty_2(_x24055, _ctx); /*bool*/
  if (_match_23590) {
    kk_string_drop(x, _ctx);
    return y;
  }
  kk_string_drop(y, _ctx);
  return x;
}

kk_string_t kk_std_core_show_char(kk_char_t c, kk_context_t* _ctx); /* (c : char) -> string */ 
 
// Show a `:double` in exponential (scientific) notation.
// The optional `precision` (= `-17`) specifies the precision.
// If `>=0` it specifies the number of digits behind the dot (up to `17` max).
// If negative, then at most the absolute value of `precision` digits behind the dot are used.

static inline kk_string_t kk_std_core_show_exp(double d, kk_std_core_types__optional precision, kk_context_t* _ctx) { /* (d : double, precision : optional<int>) -> string */ 
  int32_t _x24157;
  kk_integer_t _x24158;
  if (kk_std_core_types__is_Optional(precision)) {
    kk_box_t _box_x22304 = precision._cons.Optional.value;
    kk_integer_t _precision_9662 = kk_integer_unbox(_box_x22304);
    _x24158 = _precision_9662; /*int*/
    goto _match24159;
  }
  _x24158 = kk_integer_from_small(-17); /*int*/
  _match24159: ;
  _x24157 = kk_std_core_int32(_x24158, _ctx); /*int32*/
  return kk_std_core_show_expx(d, _x24157, _ctx);
}

kk_string_t kk_std_core_show_fixed(double d, kk_std_core_types__optional precision, kk_context_t* _ctx); /* (d : double, precision : optional<int>) -> string */ 

kk_string_t kk_std_core__mlift21190_show_list(kk_std_core__list _y_75, kk_context_t* _ctx); /* forall<e> (list<string>) -> e string */ 

kk_string_t kk_std_core_show_list(kk_std_core__list xs, kk_function_t show_elem, kk_context_t* _ctx); /* forall<a,e> (xs : list<a>, show-elem : (a) -> e string) -> e string */ 

kk_string_t kk_std_core_show(kk_integer_t i, kk_context_t* _ctx); /* (i : int) -> string */ 

kk_string_t kk_std_core_show_1(double d, kk_std_core_types__optional precision, kk_context_t* _ctx); /* (d : double, precision : optional<int>) -> string */ 
 
// Show the exception message

static inline kk_string_t kk_std_core_show_10(kk_std_core__exception exn0, kk_context_t* _ctx) { /* (exn : exception) -> string */ 
  kk_string_t _x = exn0.message;
  kk_string_dup(_x);
  kk_std_core__exception_drop(exn0, _ctx);
  return _x;
}
 
// Show a `:char` as a character literal

static inline kk_string_t kk_std_core_show_2(kk_char_t c, kk_context_t* _ctx) { /* (c : char) -> string */ 
  kk_string_t _x24225;
  kk_define_string_literal(, _s24226, 1, "\'")
  _x24225 = kk_string_dup(_s24226); /*string*/
  kk_string_t _x24227;
  kk_string_t _x24228 = kk_std_core_show_char(c, _ctx); /*string*/
  kk_string_t _x24229;
  kk_define_string_literal(, _s24230, 1, "\'")
  _x24229 = kk_string_dup(_s24230); /*string*/
  _x24227 = kk_std_core__lp__plus__plus__1_rp_(_x24228, _x24229, _ctx); /*string*/
  return kk_std_core__lp__plus__plus__1_rp_(_x24225, _x24227, _ctx);
}

kk_string_t kk_std_core_show_3(kk_string_t s, kk_context_t* _ctx); /* (s : string) -> string */ 
 
// Convert a `:bool` to a string

static inline kk_string_t kk_std_core_show_4(bool b, kk_context_t* _ctx) { /* (b : bool) -> string */ 
  if (b) {
    kk_define_string_literal(, _s24245, 4, "True")
    return kk_string_dup(_s24245);
  }
  kk_define_string_literal(, _s24246, 5, "False")
  return kk_string_dup(_s24246);
}
 
// Convert a unit value `()` to a string

static inline kk_string_t kk_std_core_show_5(kk_unit_t u, kk_context_t* _ctx) { /* (u : ()) -> string */ 
  kk_define_string_literal(, _s24247, 2, "()")
  return kk_string_dup(_s24247);
}

kk_string_t kk_std_core_show_6(kk_std_core__sslice s, kk_context_t* _ctx); /* (s : sslice) -> string */ 


// lift anonymous function
struct kk_std_core_show_fun24262__t_7 {
  struct kk_function_s _base;
};
extern kk_string_t kk_std_core_show_fun24262_7(kk_function_t _fself, kk_box_t _b_22347, kk_context_t* _ctx);
static inline kk_function_t kk_std_core_new_show_fun24262_7(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_show_fun24262_7, _ctx)
  return kk_function_dup(_fself);
}


static inline kk_string_t kk_std_core_show_7(kk_std_core__list xs, kk_context_t* _ctx) { /* (xs : list<string>) -> string */ 
  return kk_std_core_show_list(xs, kk_std_core_new_show_fun24262_7(_ctx), _ctx);
}


// lift anonymous function
struct kk_std_core_show_fun24264__t_8 {
  struct kk_function_s _base;
};
extern kk_string_t kk_std_core_show_fun24264_8(kk_function_t _fself, kk_box_t _b_22352, kk_context_t* _ctx);
static inline kk_function_t kk_std_core_new_show_fun24264_8(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_show_fun24264_8, _ctx)
  return kk_function_dup(_fself);
}


static inline kk_string_t kk_std_core_show_8(kk_std_core__list xs, kk_context_t* _ctx) { /* (xs : list<int>) -> string */ 
  return kk_std_core_show_list(xs, kk_std_core_new_show_fun24264_8(_ctx), _ctx);
}


// lift anonymous function
struct kk_std_core_show_fun24266__t_9 {
  struct kk_function_s _base;
};
extern kk_string_t kk_std_core_show_fun24266_9(kk_function_t _fself, kk_box_t _b_22357, kk_context_t* _ctx);
static inline kk_function_t kk_std_core_new_show_fun24266_9(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_show_fun24266_9, _ctx)
  return kk_function_dup(_fself);
}


static inline kk_string_t kk_std_core_show_9(kk_std_core__list xs, kk_context_t* _ctx) { /* (xs : list<bool>) -> string */ 
  return kk_std_core_show_list(xs, kk_std_core_new_show_fun24266_9(_ctx), _ctx);
}
 
// Print a string to the console, including a final newline character.

static inline kk_unit_t kk_std_core_println(kk_string_t _x124268, kk_context_t* _ctx) { /* (s : string) -> console () */ 
  kk_std_core_printsln(_x124268, _ctx); return kk_Unit;
}
 
// Print an integer to the console, including a final newline character.

static inline kk_unit_t kk_std_core_println_1(kk_integer_t i, kk_context_t* _ctx) { /* (i : int) -> console () */ 
  kk_string_t _x24269 = kk_std_core_show(i, _ctx); /*string*/
  kk_std_core_printsln(_x24269, _ctx); return kk_Unit;
}
 
// Print a double to the console, including a final newline character.

static inline kk_unit_t kk_std_core_println_2(double d, kk_context_t* _ctx) { /* (d : double) -> console () */ 
  kk_string_t _x24270 = kk_std_core_show_1(d, kk_std_core_types__new_None(_ctx), _ctx); /*string*/
  kk_std_core_printsln(_x24270, _ctx); return kk_Unit;
}
 
// Print a boolean to the console, including a final newline character

static inline kk_unit_t kk_std_core_println_3(bool b, kk_context_t* _ctx) { /* (b : bool) -> console () */ 
  kk_string_t _x24271 = kk_std_core_show_4(b, _ctx); /*string*/
  kk_std_core_printsln(_x24271, _ctx); return kk_Unit;
}
 
// Print a character to the console, including a final newline character.

static inline kk_unit_t kk_std_core_println_4(kk_char_t c, kk_context_t* _ctx) { /* (c : char) -> console () */ 
  kk_string_t _x24272 = kk_std_core_string(c, _ctx); /*string*/
  kk_std_core_printsln(_x24272, _ctx); return kk_Unit;
}
 
// Print a unit value to the console, including a final newline character

static inline kk_unit_t kk_std_core_println_5(kk_unit_t u, kk_context_t* _ctx) { /* (u : ()) -> console () */ 
  kk_string_t _x24273;
  kk_define_string_literal(, _s24274, 2, "()")
  _x24273 = kk_string_dup(_s24274); /*string*/
  kk_std_core_printsln(_x24273, _ctx); return kk_Unit;
}

kk_unit_t kk_std_core_prints(kk_string_t s, kk_context_t* _ctx); /* (s : string) -> console () */ 
 
// call `throw-exn` operation of the `:exn` effect

static inline kk_box_t kk_std_core_throw_exn(kk_std_core__exception exn0, kk_context_t* _ctx) { /* forall<a> (exn : exception) -> exn a */ 
  kk_std_core_hnd__ev ev_21475;
  size_t _x24279 = ((size_t)0); /*size_t*/
  ev_21475 = kk_evv_at(_x24279,kk_context()); /*std/core/hnd/ev<.hnd-exn>*/
  struct kk_std_core_hnd_Ev* _con24280 = kk_std_core_hnd__as_Ev(ev_21475);
  kk_std_core_hnd__marker m = _con24280->marker;
  kk_box_t _box_x22370 = _con24280->hnd;
  kk_std_core__hnd_exn h = kk_std_core__hnd_exn_unbox(_box_x22370, NULL);
  kk_std_core__hnd_exn_dup(h);
  kk_std_core_hnd__clause1 _match_23562;
  struct kk_std_core__Hnd_exn* _con24282 = kk_std_core__as_Hnd_exn(h);
  kk_std_core_hnd__clause1 except_throw_exn = _con24282->except_throw_exn;
  if (kk_std_core__hnd_exn_is_unique(h)) {
    kk_std_core__hnd_exn_free(h);
  }
  else {
    kk_std_core_hnd__clause1_dup(except_throw_exn);
    kk_std_core__hnd_exn_decref(h, _ctx);
  }
  _match_23562 = except_throw_exn; /*forall<a> std/core/hnd/clause1<exception,a,.hnd-exn,3528,3529>*/
  kk_function_t _fun_unbox_x22374 = _match_23562.clause;
  return kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x22374, (_fun_unbox_x22374, m, ev_21475, kk_std_core__exception_box(exn0, _ctx), _ctx));
}

kk_unit_t kk_std_core__default_exn(kk_function_t action, kk_context_t* _ctx); /* forall<e> (action : () -> <console,exn|e> ()) -> <console|e> () */ 

kk_std_core_types__maybe kk_std_core__lp__lb__rb__2_rp_(kk_std_core__list xs, kk_integer_t n, kk_context_t* _ctx); /* forall<a> (xs : list<a>, n : int) -> maybe<a> */ 
 
// Raise an integer `i` to the power of `exp`.

static inline kk_integer_t kk_std_core__lp__hat__1_rp_(kk_integer_t _x124297, kk_integer_t _x224298, kk_context_t* _ctx) { /* (i : int, exp : int) -> int */ 
  return kk_std_core_pow(_x124297, _x224298, _ctx);
}

kk_std_core__sslice kk_std_core_after(kk_std_core__sslice slice0, kk_context_t* _ctx); /* (slice : sslice) -> sslice */ 

bool kk_std_core__mlift21191_all(kk_function_t predicate, kk_std_core__list xx, bool _y_78, kk_context_t* _ctx); /* forall<a,e> (predicate : (a) -> e bool, xx : list<a>, bool) -> e bool */ 

bool kk_std_core_all(kk_std_core__list xs, kk_function_t predicate0, kk_context_t* _ctx); /* forall<a,e> (xs : list<a>, predicate : (a) -> e bool) -> e bool */ 

bool kk_std_core__mlift21192_any(kk_function_t predicate, kk_std_core__list xx, bool _y_82, kk_context_t* _ctx); /* forall<a,e> (predicate : (a) -> e bool, xx : list<a>, bool) -> e bool */ 

bool kk_std_core_any(kk_std_core__list xs, kk_function_t predicate0, kk_context_t* _ctx); /* forall<a,e> (xs : list<a>, predicate : (a) -> e bool) -> e bool */ 

static inline kk_unit_t kk_std_core_assert(kk_string_t message0, bool condition, kk_context_t* _ctx) { /* (message : string, condition : bool) -> () */ 
  bool _match_23556 = !(condition); /*bool*/;
  if (_match_23556) {
    kk_std_core_unsafe_assert_fail(message0, _ctx); return kk_Unit;
  }
  kk_string_drop(message0, _ctx);
  kk_Unit; return kk_Unit;
}

kk_std_core_types__maybe kk_std_core_at(kk_vector_t v, kk_integer_t index, kk_context_t* _ctx); /* forall<a> (v : vector<a>, index : int) -> maybe<a> */ 
 
// O(1). Return the string slice from the start of a string up to the
// start of `slice` argument.

static inline kk_std_core__sslice kk_std_core_before(kk_std_core__sslice slice0, kk_context_t* _ctx) { /* (slice : sslice) -> sslice */ 
  kk_string_t s = slice0.str;
  size_t start0 = slice0.start;
  kk_string_dup(s);
  kk_std_core__sslice_drop(slice0, _ctx);
  size_t _x24319 = ((size_t)0); /*size_t*/
  return kk_std_core__new_Sslice(s, _x24319, start0, _ctx);
}
 
// Convert an int to a boolean, using `False` for 0 and `True` otherwise.

static inline bool kk_std_core_bool(kk_integer_t i, kk_context_t* _ctx) { /* (i : int) -> bool */ 
  return kk_integer_neq(i,(kk_integer_from_small(0)),kk_context());
}
 
// Convert a `:maybe` type to a boolean using `False` for `Nothing` and `True` for `Just`.

static inline bool kk_std_core_bool_1(kk_std_core_types__maybe m, kk_context_t* _ctx) { /* forall<a> (m : maybe<a>) -> bool */ 
  if (kk_std_core_types__is_Nothing(m)) {
    return false;
  }
  kk_std_core_types__maybe_drop(m, _ctx);
  return true;
}
 
// Convert a string to a boolean, using `False` for the empty string and `True` otherwise.

static inline bool kk_std_core_bool_2(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> bool */ 
  kk_string_t _x24320 = kk_string_empty(); /*string*/
  return kk_string_is_neq(s,_x24320,kk_context());
}

kk_std_core__sslice kk_std_core_first(kk_string_t s, kk_std_core_types__optional n, kk_context_t* _ctx); /* (s : string, n : optional<int>) -> sslice */ 

kk_string_t kk_std_core_capitalize(kk_string_t s, kk_context_t* _ctx); /* (s : string) -> string */ 

kk_box_t kk_std_core_try(kk_function_t action, kk_function_t hndl, kk_context_t* _ctx); /* forall<a,e> (action : () -> <exn|e> a, hndl : (exception) -> e a) -> e a */ 

kk_std_core__error kk_std_core__mlift21193_try_1(kk_box_t _y_87, kk_context_t* _ctx); /* forall<a,e> (a) -> <exn|e> error<a> */ 

kk_std_core__error kk_std_core_try_1(kk_function_t action, kk_context_t* _ctx); /* forall<a,e> (action : () -> <exn|e> a) -> e error<a> */ 
 
// _Deprecated_; use `try` instead. Catch an exception raised by `throw` and handle it.
// Use `on-exn` or `on-exit` when appropiate.

static inline kk_box_t kk_std_core_catch(kk_function_t _x124375, kk_function_t _x224376, kk_context_t* _ctx) { /* forall<a,e> (action : () -> <exn|e> a, hndl : (exception) -> e a) -> e a */ 
  return kk_std_core_try(_x124375, _x224376, _ctx);
}

kk_std_core_types__tuple2_ kk_std_core_cdivmod_exp10(kk_integer_t i, kk_integer_t n, kk_context_t* _ctx); /* (i : int, n : int) -> (int, int) */ 

kk_std_core__list kk_std_core__ctail_concat_maybe(kk_std_core__list xs, kk_std_core_types__ctail _acc, kk_context_t* _ctx); /* forall<a> (xs : list<maybe<a>>, ctail<list<a>>) -> list<a> */ 

kk_std_core__list kk_std_core_concat_maybe(kk_std_core__list xs0, kk_context_t* _ctx); /* forall<a> (xs : list<maybe<a>>) -> list<a> */ 

kk_std_core_types__maybe kk_std_core__mlift21194_op(kk_function_t action, size_t end, size_t i, kk_std_core_types__maybe _y_90, kk_context_t* _ctx); /* forall<a,e> (action : (size_t) -> e maybe<a>, end : size_t, i : size_t, maybe<a>) -> e maybe<a> */ 

kk_std_core_types__maybe kk_std_core__lift21055_for_whilez(kk_function_t action0, size_t end0, size_t i0, kk_context_t* _ctx); /* forall<a,e> (action : (size_t) -> e maybe<a>, end : size_t, i : size_t) -> e maybe<a> */ 
 
// Executes `action`  for each integer between `start`  upto `end`  (including both `start`  and `end` ).
// If `start > end`  the function returns without any call to `action` .
// If `action` returns `Just`, the iteration is stopped and the result returned

static inline kk_std_core_types__maybe kk_std_core_for_whilez(size_t start0, size_t end, kk_function_t action, kk_context_t* _ctx) { /* forall<a,e> (start : size_t, end : size_t, action : (size_t) -> e maybe<a>) -> e maybe<a> */ 
  return kk_std_core__lift21055_for_whilez(action, end, start0, _ctx);
}
 
// O(1). The entire string as a slice

static inline kk_std_core__sslice kk_std_core_slice(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> sslice */ 
  kk_string_t _x24393 = kk_string_dup(s); /*string*/
  size_t _x24394 = ((size_t)0); /*size_t*/
  size_t _x24395 = kk_string_len(s,kk_context()); /*size_t*/
  return kk_std_core__new_Sslice(_x24393, _x24394, _x24395, _ctx);
}

kk_std_core_types__maybe kk_std_core__mlift21195_foreach_while(kk_function_t action, kk_std_core__list xx, kk_std_core_types__maybe _y_95, kk_context_t* _ctx); /* forall<a,b,e> (action : (a) -> e maybe<b>, xx : list<a>, maybe<b>) -> e maybe<b> */ 

kk_std_core_types__maybe kk_std_core_foreach_while(kk_std_core__list xs, kk_function_t action0, kk_context_t* _ctx); /* forall<a,b,e> (xs : list<a>, action : (a) -> e maybe<b>) -> e maybe<b> */ 

kk_std_core_types__maybe kk_std_core__mlift21196_foreach_while_1(kk_function_t action, kk_std_core__sslice rest, kk_std_core_types__maybe _y_99, kk_context_t* _ctx); /* forall<a,e> (action : (c : char) -> e maybe<a>, rest : sslice, maybe<a>) -> e maybe<a> */ 

kk_std_core_types__maybe kk_std_core_foreach_while_1(kk_std_core__sslice slice0, kk_function_t action0, kk_context_t* _ctx); /* forall<a,e> (slice : sslice, action : (c : char) -> e maybe<a>) -> e maybe<a> */ 
 
// Invoke a function for each character in a string.
// If `action` returns `Just`, the function returns immediately with that result.

static inline kk_std_core_types__maybe kk_std_core_foreach_while_2(kk_string_t s, kk_function_t action, kk_context_t* _ctx) { /* forall<a,e> (s : string, action : (c : char) -> e maybe<a>) -> e maybe<a> */ 
  kk_std_core__sslice _x24410 = kk_std_core_slice(s, _ctx); /*sslice*/
  return kk_std_core_foreach_while_1(_x24410, action, _ctx);
}

kk_std_core_types__maybe kk_std_core_foreach_while_3(kk_vector_t v, kk_function_t f, kk_context_t* _ctx); /* forall<a,b,e> (v : vector<a>, f : (a) -> e maybe<b>) -> e maybe<b> */ 

kk_unit_t kk_std_core__mlift21197_foreach(kk_function_t action, kk_std_core__list xx, kk_unit_t wild__, kk_context_t* _ctx); /* forall<a,e> (action : (a) -> e (), xx : list<a>, wild_ : ()) -> e () */ 

kk_unit_t kk_std_core_foreach(kk_std_core__list xs, kk_function_t action0, kk_context_t* _ctx); /* forall<a,e> (xs : list<a>, action : (a) -> e ()) -> e () */ 

kk_std_core_types__maybe kk_std_core__mlift21198_foreach_1(kk_unit_t wild__, kk_context_t* _ctx); /* forall<_a,e> (wild_ : ()) -> e maybe<_a> */ 

kk_unit_t kk_std_core__mlift21199_foreach_1(kk_std_core_types__maybe wild__0, kk_context_t* _ctx); /* forall<_a,e> (wild_0 : maybe<_a>) -> e () */ 

kk_unit_t kk_std_core_foreach_1(kk_std_core__sslice slice0, kk_function_t action, kk_context_t* _ctx); /* forall<e> (slice : sslice, action : (c : char) -> e ()) -> e () */ 

kk_unit_t kk_std_core_foreach_2(kk_string_t s, kk_function_t action, kk_context_t* _ctx); /* forall<e> (s : string, action : (c : char) -> e ()) -> e () */ 

kk_unit_t kk_std_core_foreach_3(kk_vector_t v, kk_function_t f, kk_context_t* _ctx); /* forall<a,e> (v : vector<a>, f : (a) -> e ()) -> e () */ 

kk_integer_t kk_std_core_count_1(kk_string_t s, kk_context_t* _ctx); /* (s : string) -> int */ 

kk_integer_t kk_std_core_count_2(kk_std_core__sslice slice0, kk_context_t* _ctx); /* (slice : sslice) -> int */ 

kk_integer_t kk_std_core_count_3(kk_string_t s, kk_function_t pred, kk_context_t* _ctx); /* (s : string, pred : (char) -> bool) -> int */ 

static inline kk_integer_t kk_std_core_dec(kk_integer_t i, kk_context_t* _ctx) { /* (i : int) -> int */ 
  return kk_integer_sub(i,(kk_integer_from_small(1)),kk_context());
}
 
// Create a new `:delayed` value.

static inline kk_std_core__delayed kk_std_core_delay(kk_function_t action, kk_context_t* _ctx) { /* forall<a,e> (action : () -> e a) -> delayed<e,a> */ 
  kk_ref_t _x24458;
  kk_std_core_types__either _b_22545_22544 = kk_std_core_types__new_Left(kk_function_box(action), _ctx); /*either<() -> 13868 13867,13867>*/;
  _x24458 = kk_ref_alloc((kk_std_core_types__either_box(_b_22545_22544, _ctx)),kk_context()); /*ref<156,157>*/
  return kk_std_core__new_Delay(_x24458, _ctx);
}
 
// Calculate `10^exp`

static inline kk_integer_t kk_std_core_exp10(kk_integer_t exp, kk_context_t* _ctx) { /* (exp : int) -> int */ 
  return kk_std_core_mul_exp10(kk_integer_from_small(1), exp, _ctx);
}

bool kk_std_core_is_neg_2(kk_integer_t i, kk_context_t* _ctx); /* (i : int) -> bool */ 
 
// Is the value negative?

static inline bool kk_std_core_is_neg_3(double d, kk_context_t* _ctx) { /* (d : double) -> bool */ 
  return (d < (0x0p+0));
}

kk_std_core_types__tuple2_ kk_std_core_divmod_exp10(kk_integer_t i, kk_integer_t n, kk_context_t* _ctx); /* (i : int, n : int) -> (int, int) */ 

kk_std_core__list kk_std_core_drop(kk_std_core__list xs, kk_integer_t n, kk_context_t* _ctx); /* forall<a> (xs : list<a>, n : int) -> list<a> */ 

kk_std_core__list kk_std_core__mlift21200_drop_while(kk_function_t predicate, kk_std_core__list xs, kk_std_core__list xx, bool _y_115, kk_context_t* _ctx); /* forall<a,e> (predicate : (a) -> e bool, xs : list<a>, xx : list<a>, bool) -> e list<a> */ 

kk_std_core__list kk_std_core_drop_while(kk_std_core__list xs0, kk_function_t predicate0, kk_context_t* _ctx); /* forall<a,e> (xs : list<a>, predicate : (a) -> e bool) -> e list<a> */ 

extern kk_std_core__sslice kk_std_core_empty;

kk_std_core_types__maybe kk_std_core_ends_with(kk_string_t s, kk_string_t post, kk_context_t* _ctx); /* (s : string, post : string) -> maybe<sslice> */ 

kk_box_t kk_std_core_throw(kk_string_t message0, kk_std_core_types__optional info0, kk_context_t* _ctx); /* forall<a> (message : string, info : optional<exception-info>) -> exn a */ 
 
// Transform an `:error` type back to an `exn` effect.

static inline kk_box_t kk_std_core_throw_1(kk_std_core__error err, kk_context_t* _ctx) { /* forall<a> (err : error<a>) -> exn a */ 
  if (kk_std_core__is_Error(err)) {
    kk_std_core__exception exn0 = err._cons.Error.exception;
    kk_std_core__exception_dup(exn0);
    kk_std_core__error_drop(err, _ctx);
    return kk_std_core_throw_exn(exn0, _ctx);
  }
  kk_box_t x = err._cons.Ok.result;
  return x;
}

kk_box_t kk_std_core__mlift21201_error_pattern(kk_string_t definition, kk_string_t location, kk_string_t _c_122, kk_context_t* _ctx); /* forall<a> (definition : string, location : string, string) -> a */ 

kk_box_t kk_std_core_error_pattern(kk_string_t location, kk_string_t definition, kk_context_t* _ctx); /* forall<a> (location : string, definition : string) -> exn a */ 
 
// Transform an `:error` type back to an `exn` effect.

static inline kk_box_t kk_std_core_exn(kk_std_core__error _x124525, kk_context_t* _ctx) { /* forall<a> (err : error<a>) -> exn a */ 
  return kk_std_core_throw_1(_x124525, _ctx);
}
 
// Calculate `2^exp`.

static inline kk_integer_t kk_std_core_exp2(kk_integer_t exp, kk_context_t* _ctx) { /* (exp : int) -> int */ 
  return kk_std_core_pow(kk_integer_from_small(2), exp, _ctx);
}

kk_std_core__list kk_std_core__mlift21202_op(kk_std_core_types__ctail _acc, kk_function_t pred, kk_box_t x, kk_std_core__list xx, bool _y_125, kk_context_t* _ctx); /* forall<a,e> (ctail<list<a>>, pred : (a) -> e bool, x : a, xx : list<a>, bool) -> e list<a> */ 

kk_std_core__list kk_std_core__mlift21203_op(kk_function_t _accm, kk_function_t pred0, kk_box_t x0, kk_std_core__list xx0, bool _y_130, kk_context_t* _ctx); /* forall<a,e> ((list<a>) -> list<a>, pred : (a) -> e bool, x : a, xx : list<a>, bool) -> e list<a> */ 

kk_std_core__list kk_std_core__ctail_filter(kk_std_core__list xs, kk_function_t pred1, kk_std_core_types__ctail _acc0, kk_context_t* _ctx); /* forall<a,e> (xs : list<a>, pred : (a) -> e bool, ctail<list<a>>) -> e list<a> */ 

kk_std_core__list kk_std_core__ctailm_filter(kk_std_core__list xs0, kk_function_t pred2, kk_function_t _accm0, kk_context_t* _ctx); /* forall<a,e> (xs : list<a>, pred : (a) -> e bool, (list<a>) -> list<a>) -> e list<a> */ 

kk_std_core__list kk_std_core_filter(kk_std_core__list xs1, kk_function_t pred3, kk_context_t* _ctx); /* forall<a,e> (xs : list<a>, pred : (a) -> e bool) -> e list<a> */ 

kk_std_core__list kk_std_core__mlift21204_op(kk_std_core_types__ctail _acc, kk_function_t pred, kk_std_core__list xx, kk_std_core_types__maybe _y_138, kk_context_t* _ctx); /* forall<a,b,e> (ctail<list<b>>, pred : (a) -> e maybe<b>, xx : list<a>, maybe<b>) -> e list<b> */ 

kk_std_core__list kk_std_core__mlift21205_op(kk_function_t _accm, kk_function_t pred0, kk_std_core__list xx0, kk_std_core_types__maybe _y_143, kk_context_t* _ctx); /* forall<a,b,e> ((list<b>) -> list<b>, pred : (a) -> e maybe<b>, xx : list<a>, maybe<b>) -> e list<b> */ 

kk_std_core__list kk_std_core__ctail_filter_map(kk_std_core__list xs, kk_function_t pred1, kk_std_core_types__ctail _acc0, kk_context_t* _ctx); /* forall<a,b,e> (xs : list<a>, pred : (a) -> e maybe<b>, ctail<list<b>>) -> e list<b> */ 

kk_std_core__list kk_std_core__ctailm_filter_map(kk_std_core__list xs0, kk_function_t pred2, kk_function_t _accm0, kk_context_t* _ctx); /* forall<a,b,e> (xs : list<a>, pred : (a) -> e maybe<b>, (list<b>) -> list<b>) -> e list<b> */ 

kk_std_core__list kk_std_core_filter_map(kk_std_core__list xs1, kk_function_t pred3, kk_context_t* _ctx); /* forall<a,b,e> (xs : list<a>, pred : (a) -> e maybe<b>) -> e list<b> */ 

bool kk_std_core_is_zero_1(size_t i, kk_context_t* _ctx); /* (i : size_t) -> bool */ 
 
// Is the value zero?

static inline bool kk_std_core_is_zero_2(double d, kk_context_t* _ctx) { /* (d : double) -> bool */ 
  return (d == (0x0p+0));
}

kk_std_core_types__maybe kk_std_core_find(kk_std_core__list xs, kk_function_t pred, kk_context_t* _ctx); /* forall<a> (xs : list<a>, pred : (a) -> bool) -> maybe<a> */ 

kk_std_core_types__maybe kk_std_core_find_1(kk_string_t s, kk_string_t sub, kk_context_t* _ctx); /* (s : string, sub : string) -> maybe<sslice> */ 

kk_std_core_types__maybe kk_std_core_find_last(kk_string_t s, kk_string_t sub, kk_context_t* _ctx); /* (s : string, sub : string) -> maybe<sslice> */ 
 
// Find the first element satisfying some predicate and return it.

static inline kk_std_core_types__maybe kk_std_core_find_maybe(kk_std_core__list _x124590, kk_function_t _x224591, kk_context_t* _ctx) { /* forall<a,b> (xs : list<a>, pred : (a) -> maybe<b>) -> maybe<b> */ 
  return kk_std_core_foreach_while(_x124590, _x224591, _ctx);
}

kk_std_core__list kk_std_core__mlift21206_op(kk_std_core_types__ctail _acc, kk_function_t f, kk_std_core__list xx, kk_std_core_types__maybe _y_151, kk_context_t* _ctx); /* forall<a,b,e> (ctail<list<b>>, f : (a) -> e maybe<b>, xx : list<a>, maybe<b>) -> e list<b> */ 

kk_std_core__list kk_std_core__mlift21207_op(kk_function_t _accm, kk_function_t f0, kk_std_core__list xx0, kk_std_core_types__maybe _y_156, kk_context_t* _ctx); /* forall<a,b,e> ((list<b>) -> list<b>, f : (a) -> e maybe<b>, xx : list<a>, maybe<b>) -> e list<b> */ 

kk_std_core__list kk_std_core__ctail_flatmap_maybe(kk_std_core__list xs, kk_function_t f1, kk_std_core_types__ctail _acc0, kk_context_t* _ctx); /* forall<a,b,e> (xs : list<a>, f : (a) -> e maybe<b>, ctail<list<b>>) -> e list<b> */ 

kk_std_core__list kk_std_core__ctailm_flatmap_maybe(kk_std_core__list xs0, kk_function_t f2, kk_function_t _accm0, kk_context_t* _ctx); /* forall<a,b,e> (xs : list<a>, f : (a) -> e maybe<b>, (list<b>) -> list<b>) -> e list<b> */ 

kk_std_core__list kk_std_core_flatmap_maybe(kk_std_core__list xs1, kk_function_t f3, kk_context_t* _ctx); /* forall<a,b,e> (xs : list<a>, f : (a) -> e maybe<b>) -> e list<b> */ 

static inline kk_integer_t kk_std_core_inc(kk_integer_t i, kk_context_t* _ctx) { /* (i : int) -> int */ 
  return kk_integer_add(i,(kk_integer_from_small(1)),kk_context());
}

kk_box_t kk_std_core_fold_int(kk_integer_t start0, kk_integer_t end, kk_box_t init0, kk_function_t f, kk_context_t* _ctx); /* forall<a> (start : int, end : int, init : a, f : (int, a) -> a) -> a */ 

kk_box_t kk_std_core__mlift21208_foldl(kk_function_t f, kk_std_core__list xx, kk_box_t _y_164, kk_context_t* _ctx); /* forall<a,e,b> (f : (a, b) -> e a, xx : list<b>, a) -> e a */ 

kk_box_t kk_std_core_foldl(kk_std_core__list xs, kk_box_t z, kk_function_t f0, kk_context_t* _ctx); /* forall<a,b,e> (list<a>, b, (b, a) -> e b) -> e b */ 

kk_box_t kk_std_core_foldl1(kk_std_core__list xs, kk_function_t f, kk_context_t* _ctx); /* forall<a,e> (xs : list<a>, f : (a, a) -> <exn|e> a) -> <exn|e> a */ 
 
// Reverse a list.

static inline kk_std_core__list kk_std_core_reverse(kk_std_core__list xs, kk_context_t* _ctx) { /* forall<a> (xs : list<a>) -> list<a> */ 
  return kk_std_core__lift21047_reverse_append(kk_std_core__new_Nil(_ctx), xs, _ctx);
}
 
// Fold a list from the right, i.e. `foldr([1,2],0,(+)) == 1+(2+0)`
// Note, `foldr` is less efficient than `foldl` as it reverses the list first.


// lift anonymous function
struct kk_std_core_foldr_fun24639__t {
  struct kk_function_s _base;
  kk_function_t f;
};
extern kk_box_t kk_std_core_foldr_fun24639(kk_function_t _fself, kk_box_t x, kk_box_t y, kk_context_t* _ctx);
static inline kk_function_t kk_std_core_new_foldr_fun24639(kk_function_t f, kk_context_t* _ctx) {
  struct kk_std_core_foldr_fun24639__t* _self = kk_function_alloc_as(struct kk_std_core_foldr_fun24639__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_foldr_fun24639, kk_context());
  _self->f = f;
  return &_self->_base;
}


static inline kk_box_t kk_std_core_foldr(kk_std_core__list xs, kk_box_t z, kk_function_t f, kk_context_t* _ctx) { /* forall<a,b,e> (xs : list<a>, z : b, f : (a, b) -> e b) -> e b */ 
  kk_std_core__list _x24638 = kk_std_core_reverse(xs, _ctx); /*list<15099>*/
  return kk_std_core_foldl(_x24638, z, kk_std_core_new_foldr_fun24639(f, _ctx), _ctx);
}

kk_box_t kk_std_core_foldr1(kk_std_core__list xs, kk_function_t f, kk_context_t* _ctx); /* forall<a,e> (xs : list<a>, f : (a, a) -> <exn|e> a) -> <exn|e> a */ 

kk_unit_t kk_std_core__mlift21209_op(kk_function_t action, kk_integer_t end, kk_integer_t i, kk_unit_t wild__, kk_context_t* _ctx); /* forall<e> (action : (int) -> e (), end : int, i : int, wild_ : ()) -> e () */ 

kk_unit_t kk_std_core__lift21056_for(kk_function_t action0, kk_integer_t end0, kk_integer_t i0, kk_context_t* _ctx); /* forall<e> (action : (int) -> e (), end : int, i : int) -> e () */ 
 
// Executes `action`  for each integer between `start`  upto `end`  (including both `start`  and `end` ).
// If `start > end`  the function returns without any call to `action` .

static inline kk_unit_t kk_std_core_for(kk_integer_t start0, kk_integer_t end, kk_function_t action, kk_context_t* _ctx) { /* forall<e> (start : int, end : int, action : (int) -> e ()) -> e () */ 
  kk_std_core__lift21056_for(action, end, start0, _ctx); return kk_Unit;
}

kk_std_core_types__maybe kk_std_core__mlift21210_op(kk_function_t action, kk_integer_t end, kk_integer_t i, kk_std_core_types__maybe _y_177, kk_context_t* _ctx); /* forall<a,e> (action : (int) -> e maybe<a>, end : int, i : int, maybe<a>) -> e maybe<a> */ 

kk_std_core_types__maybe kk_std_core__lift21057_for_while(kk_function_t action0, kk_integer_t end0, kk_integer_t i0, kk_context_t* _ctx); /* forall<a,e> (action : (int) -> e maybe<a>, end : int, i : int) -> e maybe<a> */ 
 
// Executes `action`  for each integer between `start`  upto `end`  (including both `start`  and `end` ).
// If `start > end`  the function returns without any call to `action` .
// If `action` returns `Just`, the iteration is stopped and the result returned

static inline kk_std_core_types__maybe kk_std_core_for_while(kk_integer_t start0, kk_integer_t end, kk_function_t action, kk_context_t* _ctx) { /* forall<a,e> (start : int, end : int, action : (int) -> e maybe<a>) -> e maybe<a> */ 
  return kk_std_core__lift21057_for_while(action, end, start0, _ctx);
}

kk_unit_t kk_std_core__mlift21211_foreach_indexed(kk_ref_t i, kk_integer_t _y_185, kk_context_t* _ctx); /* forall<h,e> (i : local-var<h,int>, int) -> <local<h>|e> () */ 

kk_unit_t kk_std_core__mlift21212_foreach_indexed(kk_ref_t i, kk_unit_t wild__, kk_context_t* _ctx); /* forall<h,e> (i : local-var<h,int>, wild_ : ()) -> <local<h>|e> () */ 

kk_unit_t kk_std_core__mlift21213_foreach_indexed(kk_function_t action, kk_ref_t i, kk_box_t x, kk_integer_t j, kk_context_t* _ctx); /* forall<h,a,e> (action : (int, a) -> e (), i : local-var<h,int>, x : a, j : int) -> <local<h>|e> () */ 

kk_unit_t kk_std_core_foreach_indexed(kk_std_core__list xs, kk_function_t action, kk_context_t* _ctx); /* forall<a,e> (xs : list<a>, action : (int, a) -> e ()) -> e () */ 

kk_unit_t kk_std_core_foreach_indexed_1(kk_vector_t v, kk_function_t f, kk_context_t* _ctx); /* forall<a,e> (v : vector<a>, f : (a, int) -> e ()) -> e () */ 
 
// Print a string to the console.

static inline kk_unit_t kk_std_core_print(kk_string_t _x124692, kk_context_t* _ctx) { /* (s : string) -> console () */ 
  kk_std_core_prints(_x124692, _ctx); return kk_Unit;
}
 
// Print an integer to the console.

static inline kk_unit_t kk_std_core_print_1(kk_integer_t i, kk_context_t* _ctx) { /* (i : int) -> console () */ 
  kk_string_t _x24693 = kk_std_core_show(i, _ctx); /*string*/
  kk_std_core_prints(_x24693, _ctx); return kk_Unit;
}
 
// Print a double to the console.

static inline kk_unit_t kk_std_core_print_2(double d, kk_context_t* _ctx) { /* (d : double) -> console () */ 
  kk_string_t _x24694 = kk_std_core_show_1(d, kk_std_core_types__new_None(_ctx), _ctx); /*string*/
  kk_std_core_prints(_x24694, _ctx); return kk_Unit;
}
 
// Print a boolean to the console

static inline kk_unit_t kk_std_core_print_3(bool b, kk_context_t* _ctx) { /* (b : bool) -> console () */ 
  kk_string_t _x24695 = kk_std_core_show_4(b, _ctx); /*string*/
  kk_std_core_prints(_x24695, _ctx); return kk_Unit;
}
 
// Print a character to the console.

static inline kk_unit_t kk_std_core_print_4(kk_char_t c, kk_context_t* _ctx) { /* (c : char) -> console () */ 
  kk_string_t _x24696 = kk_std_core_string(c, _ctx); /*string*/
  kk_std_core_prints(_x24696, _ctx); return kk_Unit;
}
 
// Print a unit value to the console

static inline kk_unit_t kk_std_core_print_5(kk_unit_t u, kk_context_t* _ctx) { /* (u : ()) -> console () */ 
  kk_string_t _x24697;
  kk_define_string_literal(, _s24698, 2, "()")
  _x24697 = kk_string_dup(_s24698); /*string*/
  kk_std_core_prints(_x24697, _ctx); return kk_Unit;
}
 
// Generic print routine: prints the internal representation as a string to the console,
// including a final newline character.
// Note: this breaks parametricity so it should not be public

static inline kk_unit_t kk_std_core_gprint(kk_box_t x, kk_context_t* _ctx) { /* forall<a> (x : a) -> console () */ 
  kk_string_t s_21676 = kk_std_core_gshow(x, _ctx); /*string*/;
  kk_std_core_prints(s_21676, _ctx); return kk_Unit;
}
 
// Generic print routine: prints the internal representation as a string to the console, including a final newline character.
// Note: this breaks parametricity so it should not be public

static inline kk_unit_t kk_std_core_gprintln(kk_box_t x, kk_context_t* _ctx) { /* forall<a> (x : a) -> console () */ 
  kk_string_t s_21677 = kk_std_core_gshow(x, _ctx); /*string*/;
  kk_std_core_printsln(s_21677, _ctx); return kk_Unit;
}

kk_std_core_types__maybe kk_std_core_head_1(kk_std_core__list xs, kk_context_t* _ctx); /* forall<a> (xs : list<a>) -> maybe<a> */ 

kk_box_t kk_std_core_head_2(kk_std_core__list xs, kk_box_t default0, kk_context_t* _ctx); /* forall<a> (xs : list<a>, default : a) -> a */ 

kk_string_t kk_std_core_head_3(kk_string_t s, kk_context_t* _ctx); /* (s : string) -> string */ 
 
// Return the first character of a string (or `Nothing` for the empty string).


// lift anonymous function
struct kk_std_core_head_char_fun24712__t {
  struct kk_function_s _base;
};
extern kk_std_core_types__maybe kk_std_core_head_char_fun24712(kk_function_t _fself, kk_char_t _b_22824, kk_context_t* _ctx);
static inline kk_function_t kk_std_core_new_head_char_fun24712(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_head_char_fun24712, _ctx)
  return kk_function_dup(_fself);
}


static inline kk_std_core_types__maybe kk_std_core_head_char(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> maybe<char> */ 
  kk_std_core__sslice _x24711 = kk_std_core_slice(s, _ctx); /*sslice*/
  return kk_std_core_foreach_while_1(_x24711, kk_std_core_new_head_char_fun24712(_ctx), _ctx);
}

kk_integer_t kk_std_core_index_of_acc(kk_std_core__list xs, kk_function_t pred, kk_integer_t idx, kk_context_t* _ctx); /* forall<a> (xs : list<a>, pred : (a) -> bool, idx : int) -> int */ 
 
// Returns the index of the first element where `pred` holds, or `-1` if no such element exists.

static inline kk_integer_t kk_std_core_index_of(kk_std_core__list xs, kk_function_t pred, kk_context_t* _ctx) { /* forall<a> (xs : list<a>, pred : (a) -> bool) -> int */ 
  return kk_std_core_index_of_acc(xs, pred, kk_integer_from_small(0), _ctx);
}

kk_std_core__list kk_std_core__ctail_init(kk_std_core__list xs, kk_std_core_types__ctail _acc, kk_context_t* _ctx); /* forall<a> (xs : list<a>, ctail<list<a>>) -> list<a> */ 

kk_std_core__list kk_std_core_init(kk_std_core__list xs0, kk_context_t* _ctx); /* forall<a> (xs : list<a>) -> list<a> */ 
 
// Is the character a lower-case ASCII character ?

static inline bool kk_std_core_is_lower(kk_char_t c, kk_context_t* _ctx) { /* (c : char) -> bool */ 
  bool _match_23491 = (c >= ('a')); /*bool*/;
  if (_match_23491) {
    return (c <= ('z'));
  }
  return false;
}
 
// Is the character an upper-case ASCII character ?

static inline bool kk_std_core_is_upper(kk_char_t c, kk_context_t* _ctx) { /* (c : char) -> bool */ 
  bool _match_23490 = (c >= ('A')); /*bool*/;
  if (_match_23490) {
    return (c <= ('Z'));
  }
  return false;
}
 
// Is the character an ASCII letter is-

static inline bool kk_std_core_is_alpha(kk_char_t c, kk_context_t* _ctx) { /* (c : char) -> bool */ 
  bool _match_23489 = kk_std_core_is_lower(c, _ctx); /*bool*/;
  if (_match_23489) {
    return true;
  }
  return kk_std_core_is_upper(c, _ctx);
}
 
// Is the character an ASCII digit ?

static inline bool kk_std_core_is_digit(kk_char_t c, kk_context_t* _ctx) { /* (c : char) -> bool */ 
  bool _match_23488 = (c >= ('0')); /*bool*/;
  if (_match_23488) {
    return (c <= ('9'));
  }
  return false;
}
 
// Is the character ASCII letter or digit?

static inline bool kk_std_core_is_alpha_num(kk_char_t c, kk_context_t* _ctx) { /* (c : char) -> bool */ 
  bool _match_23487 = kk_std_core_is_alpha(c, _ctx); /*bool*/;
  if (_match_23487) {
    return true;
  }
  return kk_std_core_is_digit(c, _ctx);
}
 
// Is the character an ASCII character, e.g. `c <= '\x7F'`  ?

static inline bool kk_std_core_is_ascii(kk_char_t c, kk_context_t* _ctx) { /* (c : char) -> bool */ 
  return (c <= 0x007F);
}
 
// Is the character an ASCII control character, e.g. `c < ' '`  ?

static inline bool kk_std_core_is_control(kk_char_t c, kk_context_t* _ctx) { /* (c : char) -> bool */ 
  return (c < (' '));
}

bool kk_std_core_is_hex_digit(kk_char_t c, kk_context_t* _ctx); /* (c : char) -> bool */ 
 
// Is a slice not empty?

static inline bool kk_std_core_is_notempty(kk_std_core__sslice slice0, kk_context_t* _ctx) { /* (slice : sslice) -> bool */ 
  size_t _x24723;
  size_t _x = slice0.len;
  kk_std_core__sslice_drop(slice0, _ctx);
  _x24723 = _x; /*size_t*/
  return (_x24723 > 0);
}
 
// Is a string not empty?

static inline bool kk_std_core_is_notempty_1(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> bool */ 
  kk_string_t _x24724 = kk_string_empty(); /*string*/
  return kk_string_is_neq(s,_x24724,kk_context());
}

bool kk_std_core_is_white(kk_char_t c, kk_context_t* _ctx); /* (c : char) -> bool */ 
 
// Append `end` to each string in the list `xs` and join them all together.
// `join-end([],end) === ""`
// `join-end(["a","b"],"/") === "a/b/"`

static inline kk_string_t kk_std_core_join_end(kk_std_core__list xs, kk_string_t end, kk_context_t* _ctx) { /* (xs : list<string>, end : string) -> string */ 
  if (kk_std_core__is_Nil(xs)) {
    kk_string_drop(end, _ctx);
    return kk_string_empty();
  }
  kk_string_t _x24727;
  kk_string_t _x24728 = kk_string_dup(end); /*string*/
  _x24727 = kk_std_core_joinsep(xs, _x24728, _ctx); /*string*/
  return kk_std_core__lp__plus__plus__1_rp_(_x24727, end, _ctx);
}

kk_std_core_types__maybe kk_std_core_last(kk_std_core__list xs, kk_context_t* _ctx); /* forall<a> (xs : list<a>) -> maybe<a> */ 

kk_box_t kk_std_core_last_1(kk_std_core__list xs, kk_box_t default0, kk_context_t* _ctx); /* forall<a> (xs : list<a>, default : a) -> a */ 

kk_std_core__sslice kk_std_core_last_2(kk_string_t s, kk_std_core_types__optional n, kk_context_t* _ctx); /* (s : string, n : optional<int>) -> sslice */ 

kk_std_core__list kk_std_core__ctail_take(kk_std_core__list xs, kk_integer_t n, kk_std_core_types__ctail _acc, kk_context_t* _ctx); /* forall<a> (xs : list<a>, n : int, ctail<list<a>>) -> list<a> */ 

kk_std_core__list kk_std_core_take(kk_std_core__list xs0, kk_integer_t n0, kk_context_t* _ctx); /* forall<a> (xs : list<a>, n : int) -> list<a> */ 

kk_std_core_types__tuple2_ kk_std_core_split(kk_std_core__list xs, kk_integer_t n, kk_context_t* _ctx); /* forall<a> (xs : list<a>, n : int) -> (list<a>, list<a>) */ 
 
// Split a string into parts that were delimited by `sep`. The delimeters are not included in the results.
// For example: `split("1,,2",",") == ["1","","2]`

static inline kk_std_core__list kk_std_core_split_1(kk_string_t s, kk_string_t sep, kk_context_t* _ctx) { /* (s : string, sep : string) -> list<string> */ 
  kk_vector_t v_21693 = kk_string_splitv(s,sep,kk_context()); /*vector<string>*/;
  return kk_std_core_vlist(v_21693, kk_std_core_types__new_None(_ctx), _ctx);
}
 
// Split a string into at most `n` parts that were delimited by a string `sep`. The delimeters are not included in the results (except for possibly the final part).
// For example: `split("1,2,3",",",2) == ["1","2,3"]`

static inline kk_std_core__list kk_std_core_split_2(kk_string_t s, kk_string_t sep, kk_integer_t n, kk_context_t* _ctx) { /* (s : string, sep : string, n : int) -> list<string> */ 
  kk_vector_t v_21694;
  size_t _x24756 = kk_std_core_size__t(n, _ctx); /*size_t*/
  v_21694 = kk_string_splitv_atmost(s,sep,_x24756,kk_context()); /*vector<string>*/
  return kk_std_core_vlist(v_21694, kk_std_core_types__new_None(_ctx), _ctx);
}
 
// Split a string into a list of lines

static inline kk_std_core__list kk_std_core_lines(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> list<string> */ 
  kk_vector_t v_21697;
  kk_string_t _x24757;
  kk_define_string_literal(, _s24758, 1, "\n")
  _x24757 = kk_string_dup(_s24758); /*string*/
  v_21697 = kk_string_splitv(s,_x24757,kk_context()); /*vector<string>*/
  return kk_std_core_vlist(v_21697, kk_std_core_types__new_None(_ctx), _ctx);
}

kk_std_core_types__maybe kk_std_core_lookup(kk_std_core__list xs, kk_function_t pred, kk_context_t* _ctx); /* forall<a,b> (xs : list<(a, b)>, pred : (a) -> bool) -> maybe<b> */ 

kk_std_core__list kk_std_core__mlift21214_op(kk_box_t _y_192, kk_std_core__list _y_193, kk_context_t* _ctx); /* forall<a,e> (a, list<a>) -> e list<a> */ 

kk_std_core__list kk_std_core__mlift21215_op(kk_function_t f, kk_integer_t i, kk_std_core__list yy, kk_box_t _y_1920, kk_context_t* _ctx); /* forall<a,b,e> (f : (idx : int, value : a) -> e b, i : int, yy : list<a>, b) -> e list<b> */ 

kk_std_core__list kk_std_core__lift21058_map_indexed(kk_function_t f0, kk_std_core__list ys, kk_integer_t i0, kk_context_t* _ctx); /* forall<a,b,e> (f : (idx : int, value : a) -> e b, ys : list<a>, i : int) -> e list<b> */ 
 
// Apply a function `f`  to each element of the input list in sequence where takes
// both the index of the current element and the element itself as arguments.

static inline kk_std_core__list kk_std_core_map_indexed(kk_std_core__list xs, kk_function_t f, kk_context_t* _ctx) { /* forall<a,b,e> (xs : list<a>, f : (idx : int, value : a) -> e b) -> e list<b> */ 
  return kk_std_core__lift21058_map_indexed(f, xs, kk_integer_from_small(0), _ctx);
}

kk_std_core__list kk_std_core__mlift21216_op(kk_box_t _y_196, kk_std_core__list _y_197, kk_context_t* _ctx); /* forall<a,e> (a, list<a>) -> e list<a> */ 

kk_std_core__list kk_std_core__mlift21217_op(kk_function_t f, kk_integer_t i, kk_std_core__list yy, kk_box_t _y_1960, kk_context_t* _ctx); /* forall<a,b,e> (f : (idx : int, value : a, rest : list<a>) -> e b, i : int, yy : list<a>, b) -> e list<b> */ 

kk_std_core__list kk_std_core__lift21059_map_indexed_peek(kk_function_t f0, kk_std_core__list ys, kk_integer_t i0, kk_context_t* _ctx); /* forall<a,b,e> (f : (idx : int, value : a, rest : list<a>) -> e b, ys : list<a>, i : int) -> e list<b> */ 
 
// Apply a function `f`  to each element of the input list in sequence where takes
// both the index of the current element, the element itself, and the tail list as arguments.

static inline kk_std_core__list kk_std_core_map_indexed_peek(kk_std_core__list xs, kk_function_t f, kk_context_t* _ctx) { /* forall<a,b,e> (xs : list<a>, f : (idx : int, value : a, rest : list<a>) -> e b) -> e list<b> */ 
  return kk_std_core__lift21059_map_indexed_peek(f, xs, kk_integer_from_small(0), _ctx);
}

kk_std_core__list kk_std_core__mlift21218_op(kk_std_core_types__ctail _acc, kk_function_t action, kk_std_core__list xx, kk_std_core_types__maybe _y_200, kk_context_t* _ctx); /* forall<a,b,e> (ctail<list<b>>, action : (a) -> e maybe<b>, xx : list<a>, maybe<b>) -> e list<b> */ 

kk_std_core__list kk_std_core__mlift21219_op(kk_function_t _accm, kk_function_t action0, kk_std_core__list xx0, kk_std_core_types__maybe _y_204, kk_context_t* _ctx); /* forall<a,b,e> ((list<b>) -> list<b>, action : (a) -> e maybe<b>, xx : list<a>, maybe<b>) -> e list<b> */ 

kk_std_core__list kk_std_core__ctail_map_while(kk_std_core__list xs, kk_function_t action1, kk_std_core_types__ctail _acc0, kk_context_t* _ctx); /* forall<a,b,e> (xs : list<a>, action : (a) -> e maybe<b>, ctail<list<b>>) -> e list<b> */ 

kk_std_core__list kk_std_core__ctailm_map_while(kk_std_core__list xs0, kk_function_t action2, kk_function_t _accm0, kk_context_t* _ctx); /* forall<a,b,e> (xs : list<a>, action : (a) -> e maybe<b>, (list<b>) -> list<b>) -> e list<b> */ 

kk_std_core__list kk_std_core_map_while(kk_std_core__list xs1, kk_function_t action3, kk_context_t* _ctx); /* forall<a,b,e> (xs : list<a>, action : (a) -> e maybe<b>) -> e list<b> */ 

kk_integer_t kk_std_core_max(kk_integer_t i, kk_integer_t j, kk_context_t* _ctx); /* (i : int, j : int) -> int */ 
 
// Returns the largest of two doubles

static inline double kk_std_core_max_1(double x, double y, kk_context_t* _ctx) { /* (x : double, y : double) -> double */ 
  bool _match_23465 = (x >= y); /*bool*/;
  if (_match_23465) {
    return x;
  }
  return y;
}

kk_integer_t kk_std_core_maximum(kk_std_core__list xs, kk_std_core_types__optional default0, kk_context_t* _ctx); /* (xs : list<int>, default : optional<int>) -> int */ 

double kk_std_core_maximum_1(kk_std_core__list xs, kk_context_t* _ctx); /* (xs : list<double>) -> double */ 
 
// Match a `:maybe` value and either return a default value on `Nothing` or apply a function to the value on `Just`

static inline kk_box_t kk_std_core_maybe(kk_std_core_types__maybe m, kk_box_t onNothing, kk_function_t onJust, kk_context_t* _ctx) { /* forall<a,b,e> (m : maybe<a>, onNothing : b, onJust : (a) -> e b) -> e b */ 
  if (kk_std_core_types__is_Nothing(m)) {
    kk_function_drop(onJust, _ctx);
    return onNothing;
  }
  kk_box_t x = m._cons.Just.value;
  kk_box_drop(onNothing, _ctx);
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), onJust, (onJust, x, _ctx));
}
 
// Convert a `:maybe<a>` value to `:a`, using the `nothing` parameter for `Nothing`.
// This is an alias for `default`.

static inline kk_box_t kk_std_core_maybe_1(kk_std_core_types__maybe _x124836, kk_box_t _x224837, kk_context_t* _ctx) { /* forall<a> (m : maybe<a>, nothing : a) -> a */ 
  return kk_std_core_default(_x124836, _x224837, _ctx);
}
 
// Convert a `:either` to a `:maybe` type discarding the value of the `Left` constructor
// and using `Just` for the `Right` constructor.

static inline kk_std_core_types__maybe kk_std_core_maybe_2(kk_std_core_types__either e, kk_context_t* _ctx) { /* forall<a,b> (e : either<a,b>) -> maybe<b> */ 
  if (kk_std_core_types__is_Left(e)) {
    kk_std_core_types__either_drop(e, _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
  kk_box_t x = e._cons.Right.right;
  return kk_std_core_types__new_Just(x, _ctx);
}

kk_std_core_types__maybe kk_std_core_maybe_3(kk_std_core__list xs, kk_context_t* _ctx); /* forall<a> (xs : list<a>) -> maybe<a> */ 
 
// Transform a boolean to a maybe type, using `Nothing` for `False`

static inline kk_std_core_types__maybe kk_std_core_maybe_4(bool b, kk_context_t* _ctx) { /* (b : bool) -> maybe<()> */ 
  if (b) {
    return kk_std_core_types__new_Just(kk_unit_box(kk_Unit), _ctx);
  }
  return kk_std_core_types__new_Nothing(_ctx);
}

kk_std_core_types__maybe kk_std_core_maybe_5(kk_integer_t i, kk_context_t* _ctx); /* (i : int) -> maybe<int> */ 

kk_std_core_types__maybe kk_std_core_maybe_6(kk_string_t s, kk_context_t* _ctx); /* (s : string) -> maybe<string> */ 
 
// Transform an `:error` type to a `:maybe` value.

static inline kk_std_core_types__maybe kk_std_core_maybe_7(kk_std_core__error t, kk_context_t* _ctx) { /* forall<a> (t : error<a>) -> maybe<a> */ 
  if (kk_std_core__is_Error(t)) {
    kk_std_core__exception _pat0 = t._cons.Error.exception;
    kk_std_core__error_drop(t, _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
  kk_box_t x = t._cons.Ok.result;
  return kk_std_core_types__new_Just(x, _ctx);
}

kk_std_core_types__maybe kk_std_core_maybe_8(kk_std_core__null n, kk_context_t* _ctx); /* forall<a> (n : null<a>) -> maybe<a> */ 

kk_integer_t kk_std_core_min(kk_integer_t i, kk_integer_t j, kk_context_t* _ctx); /* (i : int, j : int) -> int */ 
 
// Returns the smallest of two doubles

static inline double kk_std_core_min_1(double x, double y, kk_context_t* _ctx) { /* (x : double, y : double) -> double */ 
  bool _match_23461 = (x <= y); /*bool*/;
  if (_match_23461) {
    return x;
  }
  return y;
}

kk_integer_t kk_std_core_minimum(kk_std_core__list xs, kk_std_core_types__optional default0, kk_context_t* _ctx); /* (xs : list<int>, default : optional<int>) -> int */ 

double kk_std_core_minimum_1(kk_std_core__list xs, kk_context_t* _ctx); /* (xs : list<double>) -> double */ 

kk_unit_t kk_std_core_notrace(kk_context_t* _ctx); /* () -> (st<global>) () */ 

kk_std_core__null kk_std_core_null(kk_std_core_types__maybe x, kk_context_t* _ctx); /* forall<a> (x : maybe<a>) -> null<a> */ 
 
// Cast a integer that is zero to a null

static inline kk_std_core__null kk_std_core_null_1(kk_integer_t i, kk_context_t* _ctx) { /* (i : int) -> null<int> */ 
  kk_std_core_types__maybe _x24858 = kk_std_core_maybe_5(i, _ctx); /*maybe<int>*/
  return kk_std_core_null(_x24858, _ctx);
}
 
// Cast an empty string a null

static inline kk_std_core__null kk_std_core_null_2(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> null<string> */ 
  kk_std_core_types__maybe _x24859 = kk_std_core_maybe_6(s, _ctx); /*maybe<string>*/
  return kk_std_core_null(_x24859, _ctx);
}
 
// Cast a boolean `False` to null

static inline kk_std_core__null kk_std_core_null_3(bool b, kk_context_t* _ctx) { /* (b : bool) -> null<()> */ 
  kk_std_core_types__maybe _x24860 = kk_std_core_maybe_4(b, _ctx); /*maybe<()>*/
  return kk_std_core_null(_x24860, _ctx);
}

extern kk_std_core__null kk_std_core_null_const;

kk_string_t kk_std_core_pad_right(kk_string_t s, kk_integer_t width, kk_std_core_types__optional fill, kk_context_t* _ctx); /* (s : string, width : int, fill : optional<char>) -> string */ 

kk_std_core_types__maybe kk_std_core_starts_with(kk_string_t s, kk_string_t pre, kk_context_t* _ctx); /* (s : string, pre : string) -> maybe<sslice> */ 

kk_string_t kk_std_core_trim_left_1(kk_string_t s, kk_string_t sub, kk_context_t* _ctx); /* (s : string, sub : string) -> string */ 

kk_string_t kk_std_core_trim_right_1(kk_string_t s, kk_string_t sub, kk_context_t* _ctx); /* (s : string, sub : string) -> string */ 
 
// Trim whitespace on the left and right side of a string

static inline kk_string_t kk_std_core_trim(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> string */ 
  kk_string_t _x24886 = kk_string_trim_left(s,kk_context()); /*string*/
  return kk_string_trim_right(_x24886,kk_context());
}
 
// Parse an integer after trimming whitespace.
// If an illegal digit character is encountered `Nothing` is returned.
// An empty string will result in `Just(0)`.
// A string can start with a `-` sign for negative numbers,
// and with `0x` or `0X` for hexadecimal numbers (in which case the `hex` parameter is ignored).

static inline kk_std_core_types__maybe kk_std_core_parse_int(kk_string_t s, kk_std_core_types__optional hex, kk_context_t* _ctx) { /* (s : string, hex : optional<bool>) -> maybe<int> */ 
  kk_string_t _x24887 = kk_std_core_trim(s, _ctx); /*string*/
  bool _x24888;
  if (kk_std_core_types__is_Optional(hex)) {
    kk_box_t _box_x23026 = hex._cons.Optional.value;
    bool _hex_19366 = kk_bool_unbox(_box_x23026);
    _x24888 = _hex_19366; /*bool*/
    goto _match24889;
  }
  _x24888 = false; /*bool*/
  _match24889: ;
  return kk_std_core_xparse_int(_x24887, _x24888, _ctx);
}

kk_integer_t kk_std_core_parse_int_default(kk_string_t s, kk_std_core_types__optional default0, kk_std_core_types__optional hex, kk_context_t* _ctx); /* (s : string, default : optional<int>, hex : optional<bool>) -> int */ 

kk_std_core_types__tuple2_ kk_std_core__mlift21220_partition_acc(kk_std_core__list acc1, kk_std_core__list acc2, kk_function_t pred, kk_box_t x, kk_std_core__list xx, bool _y_213, kk_context_t* _ctx); /* forall<a,e> (acc1 : list<a>, acc2 : list<a>, pred : (a) -> e bool, x : a, xx : list<a>, bool) -> e (list<a>, list<a>) */ 

kk_std_core_types__tuple2_ kk_std_core_partition_acc(kk_std_core__list xs, kk_function_t pred0, kk_std_core__list acc10, kk_std_core__list acc20, kk_context_t* _ctx); /* forall<a,e> (xs : list<a>, pred : (a) -> e bool, acc1 : list<a>, acc2 : list<a>) -> e (list<a>, list<a>) */ 
 
// Partition a list in two lists where the first list contains
// those elements that satisfy the given predicate `pred`.
// For example: `partition([1,2,3],odd?) == ([1,3],[2])`

static inline kk_std_core_types__tuple2_ kk_std_core_partition(kk_std_core__list xs, kk_function_t pred, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, pred : (a) -> e bool) -> e (list<a>, list<a>) */ 
  return kk_std_core_partition_acc(xs, pred, kk_std_core__new_Nil(_ctx), kk_std_core__new_Nil(_ctx), _ctx);
}

kk_unit_t kk_std_core_print_redirect(kk_function_t print0, kk_context_t* _ctx); /* (print : (msg : string) -> console ()) -> io () */ 
 
// Remove those elements of a list that satisfy the given predicate `pred`.
// For example: `remove([1,2,3],odd?) == [2]`


// lift anonymous function
struct kk_std_core_remove_fun24922__t {
  struct kk_function_s _base;
  kk_function_t pred;
};
extern bool kk_std_core_remove_fun24922(kk_function_t _fself, kk_box_t x, kk_context_t* _ctx);
static inline kk_function_t kk_std_core_new_remove_fun24922(kk_function_t pred, kk_context_t* _ctx) {
  struct kk_std_core_remove_fun24922__t* _self = kk_function_alloc_as(struct kk_std_core_remove_fun24922__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_remove_fun24922, kk_context());
  _self->pred = pred;
  return &_self->_base;
}


static inline kk_std_core__list kk_std_core_remove(kk_std_core__list xs, kk_function_t pred, kk_context_t* _ctx) { /* forall<a> (xs : list<a>, pred : (a) -> bool) -> list<a> */ 
  return kk_std_core_filter(xs, kk_std_core_new_remove_fun24922(pred, _ctx), _ctx);
}
 
// Repeat a string `n` times

static inline kk_string_t kk_std_core_repeat(kk_string_t s, kk_integer_t n, kk_context_t* _ctx) { /* (s : string, n : int) -> string */ 
  size_t _x24924 = kk_std_core_size__t(n, _ctx); /*size_t*/
  return kk_std_core_repeatz(s, _x24924, _ctx);
}
 
// The `repeat` fun executes `action`  `n`  times.


// lift anonymous function
struct kk_std_core_repeat_fun24925__t_1 {
  struct kk_function_s _base;
  kk_function_t action;
};
extern kk_unit_t kk_std_core_repeat_fun24925_1(kk_function_t _fself, kk_integer_t i, kk_context_t* _ctx);
static inline kk_function_t kk_std_core_new_repeat_fun24925_1(kk_function_t action, kk_context_t* _ctx) {
  struct kk_std_core_repeat_fun24925__t_1* _self = kk_function_alloc_as(struct kk_std_core_repeat_fun24925__t_1, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_repeat_fun24925_1, kk_context());
  _self->action = action;
  return &_self->_base;
}


static inline kk_unit_t kk_std_core_repeat_1(kk_integer_t n, kk_function_t action, kk_context_t* _ctx) { /* forall<e> (n : int, action : () -> e ()) -> e () */ 
  kk_std_core__lift21056_for(kk_std_core_new_repeat_fun24925_1(action, _ctx), n, kk_integer_from_small(1), _ctx); return kk_Unit;
}

kk_std_core__list kk_std_core__ctail_replicate(kk_box_t x, kk_integer_t n, kk_std_core_types__ctail _acc, kk_context_t* _ctx); /* forall<a> (x : a, n : int, ctail<list<a>>) -> list<a> */ 

kk_std_core__list kk_std_core_replicate(kk_box_t x0, kk_integer_t n0, kk_context_t* _ctx); /* forall<a> (x : a, n : int) -> list<a> */ 

kk_string_t kk_std_core_show_tuple(kk_std_core_types__tuple2_ x, kk_function_t showfst, kk_function_t showsnd, kk_context_t* _ctx); /* forall<a,b> (x : (a, b), showfst : (a) -> string, showsnd : (b) -> string) -> string */ 

kk_std_core_types__tuple2_ kk_std_core__mlift21221_op(kk_std_core__list acc, kk_function_t predicate, kk_box_t y, kk_std_core__list ys, kk_std_core__list yy, bool _y_221, kk_context_t* _ctx); /* forall<a,e> (acc : list<a>, predicate : (a) -> e bool, y : a, ys : list<a>, yy : list<a>, bool) -> e (list<a>, list<a>) */ 

kk_std_core_types__tuple2_ kk_std_core__lift21060_span(kk_function_t predicate0, kk_std_core__list ys0, kk_std_core__list acc0, kk_context_t* _ctx); /* forall<a,e> (predicate : (a) -> e bool, ys : list<a>, acc : list<a>) -> e (list<a>, list<a>) */ 

static inline kk_std_core_types__tuple2_ kk_std_core_span(kk_std_core__list xs, kk_function_t predicate, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, predicate : (a) -> e bool) -> e (list<a>, list<a>) */ 
  return kk_std_core__lift21060_span(predicate, xs, kk_std_core__new_Nil(_ctx), _ctx);
}

kk_integer_t kk_std_core_sum(kk_std_core__list xs, kk_context_t* _ctx); /* (xs : list<int>) -> int */ 

kk_std_core__list kk_std_core_tail_1(kk_std_core__list xs, kk_context_t* _ctx); /* forall<a> (xs : list<a>) -> list<a> */ 

kk_string_t kk_std_core_tail_2(kk_string_t s, kk_context_t* _ctx); /* (s : string) -> string */ 

kk_std_core__list kk_std_core__mlift21222_op(kk_std_core_types__ctail _acc, kk_function_t predicate, kk_box_t x, kk_std_core__list xx, bool _y_226, kk_context_t* _ctx); /* forall<a,e> (ctail<list<a>>, predicate : (a) -> e bool, x : a, xx : list<a>, bool) -> e list<a> */ 

kk_std_core__list kk_std_core__mlift21223_op(kk_function_t _accm, kk_function_t predicate0, kk_box_t x0, kk_std_core__list xx0, bool _y_230, kk_context_t* _ctx); /* forall<a,e> ((list<a>) -> list<a>, predicate : (a) -> e bool, x : a, xx : list<a>, bool) -> e list<a> */ 

kk_std_core__list kk_std_core__ctail_take_while(kk_std_core__list xs, kk_function_t predicate1, kk_std_core_types__ctail _acc0, kk_context_t* _ctx); /* forall<a,e> (xs : list<a>, predicate : (a) -> e bool, ctail<list<a>>) -> e list<a> */ 

kk_std_core__list kk_std_core__ctailm_take_while(kk_std_core__list xs0, kk_function_t predicate2, kk_function_t _accm0, kk_context_t* _ctx); /* forall<a,e> (xs : list<a>, predicate : (a) -> e bool, (list<a>) -> list<a>) -> e list<a> */ 

kk_std_core__list kk_std_core_take_while(kk_std_core__list xs1, kk_function_t predicate3, kk_context_t* _ctx); /* forall<a,e> (xs : list<a>, predicate : (a) -> e bool) -> e list<a> */ 

kk_unit_t kk_std_core_trace(kk_string_t message0, kk_context_t* _ctx); /* (message : string) -> () */ 

kk_unit_t kk_std_core_trace_any(kk_string_t message0, kk_box_t x, kk_context_t* _ctx); /* forall<a> (message : string, x : a) -> () */ 

kk_string_t kk_std_core_truncate(kk_string_t s, kk_integer_t count, kk_context_t* _ctx); /* (s : string, count : int) -> string */ 

kk_box_t kk_std_core_try_default(kk_box_t value, kk_function_t action, kk_context_t* _ctx); /* forall<a,e> (value : a, action : () -> <exn|e> a) -> e a */ 

kk_integer_t kk_std_core_unique(kk_context_t* _ctx); /* () -> ndet int */ 

kk_box_t kk_std_core_unjust(kk_std_core_types__maybe m, kk_context_t* _ctx); /* forall<a> (m : maybe<a>) -> exn a */ 

kk_string_t kk_std_core_unlines(kk_std_core__list xs, kk_context_t* _ctx); /* (xs : list<string>) -> string */ 

kk_std_core_types__tuple2_ kk_std_core__lift21061_unzip(kk_std_core__list ys, kk_std_core__list acc1, kk_std_core__list acc2, kk_context_t* _ctx); /* forall<a,b> (ys : list<(a, b)>, acc1 : list<a>, acc2 : list<b>) -> (list<a>, list<b>) */ 
 
// Unzip a list of pairs into two lists

static inline kk_std_core_types__tuple2_ kk_std_core_unzip(kk_std_core__list xs, kk_context_t* _ctx) { /* forall<a,b> (xs : list<(a, b)>) -> (list<a>, list<b>) */ 
  return kk_std_core__lift21061_unzip(xs, kk_std_core__new_Nil(_ctx), kk_std_core__new_Nil(_ctx), _ctx);
}

kk_vector_t kk_std_core_vector_1(kk_string_t s, kk_context_t* _ctx); /* (s : string) -> vector<char> */ 
 
// Create a new vector of length `n`  with initial elements `default` .


// lift anonymous function
struct kk_std_core_vector_fun25051__t_2 {
  struct kk_function_s _base;
  kk_box_t default0;
};
extern kk_box_t kk_std_core_vector_fun25051_2(kk_function_t _fself, size_t ___wildcard__2034__29, kk_context_t* _ctx);
static inline kk_function_t kk_std_core_new_vector_fun25051_2(kk_box_t default0, kk_context_t* _ctx) {
  struct kk_std_core_vector_fun25051__t_2* _self = kk_function_alloc_as(struct kk_std_core_vector_fun25051__t_2, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_vector_fun25051_2, kk_context());
  _self->default0 = default0;
  return &_self->_base;
}


static inline kk_vector_t kk_std_core_vector_2(kk_integer_t n, kk_box_t default0, kk_context_t* _ctx) { /* forall<a> (n : int, default : a) -> vector<a> */ 
  size_t _x25050 = kk_std_core_size__t(n, _ctx); /*size_t*/
  return kk_std_core_vector_initz(_x25050, kk_std_core_new_vector_fun25051_2(default0, _ctx), _ctx);
}
 
// Convert a list to a vector.

static inline kk_vector_t kk_std_core_vector_3(kk_std_core__list _x125052, kk_context_t* _ctx) { /* forall<a> (xs : list<a>) -> vector<a> */ 
  return kk_std_core_unvlist(_x125052, _ctx);
}
 
// Create a new vector of length `n`  with initial elements given by function `f` .


// lift anonymous function
struct kk_std_core_vector_init_fun25054__t {
  struct kk_function_s _base;
  kk_function_t f;
};
extern kk_box_t kk_std_core_vector_init_fun25054(kk_function_t _fself, size_t i, kk_context_t* _ctx);
static inline kk_function_t kk_std_core_new_vector_init_fun25054(kk_function_t f, kk_context_t* _ctx) {
  struct kk_std_core_vector_init_fun25054__t* _self = kk_function_alloc_as(struct kk_std_core_vector_init_fun25054__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_vector_init_fun25054, kk_context());
  _self->f = f;
  return &_self->_base;
}


static inline kk_vector_t kk_std_core_vector_init(kk_integer_t n, kk_function_t f, kk_context_t* _ctx) { /* forall<a> (n : int, f : (int) -> a) -> vector<a> */ 
  size_t _x25053 = kk_std_core_size__t(n, _ctx); /*size_t*/
  return kk_std_core_vector_initz(_x25053, kk_std_core_new_vector_init_fun25054(f, _ctx), _ctx);
}

kk_unit_t kk_std_core__mlift21224_while(kk_function_t action, kk_function_t predicate, kk_unit_t wild__, kk_context_t* _ctx); /* forall<e> (action : () -> <div|e> (), predicate : () -> <div|e> bool, wild_ : ()) -> <div|e> () */ 

kk_unit_t kk_std_core__mlift21225_while(kk_function_t action0, kk_function_t predicate0, bool _y_245, kk_context_t* _ctx); /* forall<e> (action : () -> <div|e> (), predicate : () -> <div|e> bool, bool) -> <div|e> () */ 

kk_unit_t kk_std_core_while(kk_function_t predicate1, kk_function_t action1, kk_context_t* _ctx); /* forall<e> (predicate : () -> <div|e> bool, action : () -> <div|e> ()) -> <div|e> () */ 

kk_std_core__list kk_std_core__ctail_zip(kk_std_core__list xs, kk_std_core__list ys, kk_std_core_types__ctail _acc, kk_context_t* _ctx); /* forall<a,b> (xs : list<a>, ys : list<b>, ctail<list<(a, b)>>) -> list<(a, b)> */ 

kk_std_core__list kk_std_core_zip(kk_std_core__list xs0, kk_std_core__list ys0, kk_context_t* _ctx); /* forall<a,b> (xs : list<a>, ys : list<b>) -> list<(a, b)> */ 

kk_std_core__list kk_std_core__mlift21226_op(kk_std_core_types__ctail _acc, kk_function_t f, kk_std_core__list xx, kk_std_core__list yy, kk_box_t _ctail_21160, kk_context_t* _ctx); /* forall<a,b,c,e> (ctail<list<c>>, f : (a, b) -> e c, xx : list<a>, yy : list<b>, c) -> e list<c> */ 

kk_std_core__list kk_std_core__mlift21227_op(kk_function_t _accm, kk_function_t f0, kk_std_core__list xx0, kk_std_core__list yy0, kk_box_t _ctail_21165, kk_context_t* _ctx); /* forall<a,b,c,e> ((list<c>) -> list<c>, f : (a, b) -> e c, xx : list<a>, yy : list<b>, c) -> e list<c> */ 

kk_std_core__list kk_std_core__ctail_zipwith(kk_std_core__list xs, kk_std_core__list ys, kk_function_t f1, kk_std_core_types__ctail _acc0, kk_context_t* _ctx); /* forall<a,b,c,e> (xs : list<a>, ys : list<b>, f : (a, b) -> e c, ctail<list<c>>) -> e list<c> */ 

kk_std_core__list kk_std_core__ctailm_zipwith(kk_std_core__list xs0, kk_std_core__list ys0, kk_function_t f2, kk_function_t _accm0, kk_context_t* _ctx); /* forall<a,b,c,e> (xs : list<a>, ys : list<b>, f : (a, b) -> e c, (list<c>) -> list<c>) -> e list<c> */ 

kk_std_core__list kk_std_core_zipwith(kk_std_core__list xs1, kk_std_core__list ys1, kk_function_t f3, kk_context_t* _ctx); /* forall<a,b,c,e> (xs : list<a>, ys : list<b>, f : (a, b) -> e c) -> e list<c> */ 

kk_std_core__list kk_std_core__mlift21228_zipwith_acc(kk_std_core__list acc, kk_function_t f, kk_integer_t i, kk_std_core__list xx, kk_std_core__list yy, kk_box_t _y_260, kk_context_t* _ctx); /* forall<e,a,b,c> (acc : list<b>, f : (int, a, c) -> e b, i : int, xx : list<a>, yy : list<c>, b) -> e list<b> */ 

kk_std_core__list kk_std_core_zipwith_acc(kk_function_t f0, kk_integer_t i0, kk_std_core__list acc0, kk_std_core__list xs, kk_std_core__list ys, kk_context_t* _ctx); /* forall<a,b,c,e> ((int, a, b) -> e c, int, list<c>, list<a>, list<b>) -> e list<c> */ 

kk_std_core__list kk_std_core__mlift21229_op(kk_box_t _y_264, kk_std_core__list _y_265, kk_context_t* _ctx); /* forall<a,e> (a, list<a>) -> e list<a> */ 

kk_std_core__list kk_std_core__mlift21230_op(kk_function_t f, kk_integer_t i, kk_std_core__list xx, kk_std_core__list yy, kk_box_t _y_2640, kk_context_t* _ctx); /* forall<a,b,c,e> (f : (int, a, b) -> e c, i : int, xx : list<a>, yy : list<b>, c) -> e list<c> */ 

kk_std_core__list kk_std_core__lift21062_zipwith_indexed(kk_function_t f0, kk_integer_t i0, kk_std_core__list xs, kk_std_core__list ys, kk_context_t* _ctx); /* forall<a,b,c,e> (f : (int, a, b) -> e c, i : int, xs : list<a>, ys : list<b>) -> e list<c> */ 
 
// Zip two lists together by apply a function `f` to all corresponding elements
// and their index in the list.
// The returned list is only as long as the smallest input list.

static inline kk_std_core__list kk_std_core_zipwith_indexed(kk_std_core__list xs0, kk_std_core__list ys0, kk_function_t f, kk_context_t* _ctx) { /* forall<a,b,c,e> (xs0 : list<a>, ys0 : list<b>, f : (int, a, b) -> e c) -> e list<c> */ 
  return kk_std_core__lift21062_zipwith_indexed(f, kk_integer_from_small(0), xs0, ys0, _ctx);
}

void kk_std_core__init(kk_context_t* _ctx);

#endif // header
