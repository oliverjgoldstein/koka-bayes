#pragma once
#ifndef kk_std_text_parse_H
#define kk_std_text_parse_H
// Koka generated module: "std/text/parse", koka version: 2.1.3
#include <kklib.h>
#include "std_core_types.h"
#include "std_core_hnd.h"
#include "std_core.h"

// type declarations

// type std/text/parse/.hnd-parse
struct kk_std_text_parse__hnd_parse_s {
  kk_block_t _block;
};
typedef struct kk_std_text_parse__hnd_parse_s* kk_std_text_parse__hnd_parse;
struct kk_std_text_parse__Hnd_parse {
  struct kk_std_text_parse__hnd_parse_s _base;
  kk_std_core_hnd__clause0 fun_current_input;
  kk_std_core_hnd__clause1 control_fail;
  kk_std_core_hnd__clause0 control_pick;
  kk_std_core_hnd__clause1 fun_satisfy;
};
static inline kk_std_text_parse__hnd_parse kk_std_text_parse__base_Hnd_parse(struct kk_std_text_parse__Hnd_parse* _x){
  return &_x->_base;
}
static inline kk_std_text_parse__hnd_parse kk_std_text_parse__new_Hnd_parse(kk_reuse_t _at, kk_std_core_hnd__clause0 fun_current_input, kk_std_core_hnd__clause1 control_fail, kk_std_core_hnd__clause0 control_pick, kk_std_core_hnd__clause1 fun_satisfy, kk_context_t* _ctx){
  struct kk_std_text_parse__Hnd_parse* _con = kk_block_alloc_at_as(struct kk_std_text_parse__Hnd_parse, _at, 4 /* scan count */, (kk_tag_t)(1), _ctx);
  _con->fun_current_input = fun_current_input;
  _con->control_fail = control_fail;
  _con->control_pick = control_pick;
  _con->fun_satisfy = fun_satisfy;
  return kk_std_text_parse__base_Hnd_parse(_con);
}
static inline struct kk_std_text_parse__Hnd_parse* kk_std_text_parse__as_Hnd_parse(kk_std_text_parse__hnd_parse x) {
  return kk_basetype_as_assert(struct kk_std_text_parse__Hnd_parse*, x, (kk_tag_t)(1) /* _tag */);
}
static inline bool kk_std_text_parse__is_Hnd_parse(kk_std_text_parse__hnd_parse x) {
  return (true);
}
static inline kk_std_text_parse__hnd_parse kk_std_text_parse__hnd_parse_dup(kk_std_text_parse__hnd_parse _x) {
  return kk_basetype_dup_as(kk_std_text_parse__hnd_parse, _x);
}
static inline void kk_std_text_parse__hnd_parse_drop(kk_std_text_parse__hnd_parse _x, kk_context_t* _ctx) {
  kk_basetype_drop(_x, _ctx);
}
static inline bool kk_std_text_parse__hnd_parse_is_unique(kk_std_text_parse__hnd_parse _x) {
  return kk_basetype_is_unique(_x);
}
static inline void kk_std_text_parse__hnd_parse_free(kk_std_text_parse__hnd_parse _x) {
  kk_basetype_free(_x);
}
static inline void kk_std_text_parse__hnd_parse_decref(kk_std_text_parse__hnd_parse _x, kk_context_t* _ctx) {
  kk_basetype_decref(_x, _ctx);
}
static inline kk_reuse_t kk_std_text_parse__hnd_parse_dropn_reuse(kk_std_text_parse__hnd_parse _x, size_t _scan_fsize, kk_context_t* _ctx) {
  return kk_basetype_dropn_reuse(_x, _scan_fsize, _ctx);
}
static inline void kk_std_text_parse__hnd_parse_dropn(kk_std_text_parse__hnd_parse _x, size_t _scan_fsize, kk_context_t* _ctx) {
  kk_basetype_dropn(_x, _scan_fsize, _ctx);
}
static inline kk_reuse_t kk_std_text_parse__hnd_parse_reuse(kk_std_text_parse__hnd_parse _x) {
  return kk_basetype_reuse(_x);
}
static inline kk_std_text_parse__hnd_parse kk_std_text_parse__hnd_parse_hole() {
  return (kk_std_text_parse__hnd_parse)(1);
}
static inline kk_box_t kk_std_text_parse__hnd_parse_box(kk_std_text_parse__hnd_parse _x, kk_context_t* _ctx) {
  return kk_basetype_box(_x);
}
static inline kk_std_text_parse__hnd_parse kk_std_text_parse__hnd_parse_unbox(kk_box_t _x, kk_context_t* _ctx) {
  return kk_basetype_unbox_as(kk_std_text_parse__hnd_parse, _x);
}

// type std/text/parse/parse
struct kk_std_text_parse__parse_s {
  kk_block_t _block;
};
typedef struct kk_std_text_parse__parse_s* kk_std_text_parse__parse;
struct kk_std_text_parse_Parse {
  struct kk_std_text_parse__parse_s _base;
  kk_std_text_parse__hnd_parse _field1;
};
static inline kk_std_text_parse__parse kk_std_text_parse__base_Parse(struct kk_std_text_parse_Parse* _x){
  return &_x->_base;
}
static inline kk_std_text_parse__parse kk_std_text_parse__new_Parse(kk_reuse_t _at, kk_std_text_parse__hnd_parse _field1, kk_context_t* _ctx){
  struct kk_std_text_parse_Parse* _con = kk_block_alloc_at_as(struct kk_std_text_parse_Parse, _at, 1 /* scan count */, (kk_tag_t)(1), _ctx);
  _con->_field1 = _field1;
  return kk_std_text_parse__base_Parse(_con);
}
static inline struct kk_std_text_parse_Parse* kk_std_text_parse__as_Parse(kk_std_text_parse__parse x) {
  return kk_basetype_as_assert(struct kk_std_text_parse_Parse*, x, (kk_tag_t)(1) /* _tag */);
}
static inline bool kk_std_text_parse__is_Parse(kk_std_text_parse__parse x) {
  return (true);
}
static inline kk_std_text_parse__parse kk_std_text_parse__parse_dup(kk_std_text_parse__parse _x) {
  return kk_basetype_dup_as(kk_std_text_parse__parse, _x);
}
static inline void kk_std_text_parse__parse_drop(kk_std_text_parse__parse _x, kk_context_t* _ctx) {
  kk_basetype_drop(_x, _ctx);
}
static inline bool kk_std_text_parse__parse_is_unique(kk_std_text_parse__parse _x) {
  return kk_basetype_is_unique(_x);
}
static inline void kk_std_text_parse__parse_free(kk_std_text_parse__parse _x) {
  kk_basetype_free(_x);
}
static inline void kk_std_text_parse__parse_decref(kk_std_text_parse__parse _x, kk_context_t* _ctx) {
  kk_basetype_decref(_x, _ctx);
}
static inline kk_reuse_t kk_std_text_parse__parse_dropn_reuse(kk_std_text_parse__parse _x, size_t _scan_fsize, kk_context_t* _ctx) {
  return kk_basetype_dropn_reuse(_x, _scan_fsize, _ctx);
}
static inline void kk_std_text_parse__parse_dropn(kk_std_text_parse__parse _x, size_t _scan_fsize, kk_context_t* _ctx) {
  kk_basetype_dropn(_x, _scan_fsize, _ctx);
}
static inline kk_reuse_t kk_std_text_parse__parse_reuse(kk_std_text_parse__parse _x) {
  return kk_basetype_reuse(_x);
}
static inline kk_std_text_parse__parse kk_std_text_parse__parse_hole() {
  return (kk_std_text_parse__parse)(1);
}
static inline kk_box_t kk_std_text_parse__parse_box(kk_std_text_parse__parse _x, kk_context_t* _ctx) {
  return kk_basetype_box(_x);
}
static inline kk_std_text_parse__parse kk_std_text_parse__parse_unbox(kk_box_t _x, kk_context_t* _ctx) {
  return kk_basetype_unbox_as(kk_std_text_parse__parse, _x);
}

// type std/text/parse/parse-error
struct kk_std_text_parse__parse_error_s {
  kk_block_t _block;
};
typedef struct kk_std_text_parse__parse_error_s* kk_std_text_parse__parse_error;
struct kk_std_text_parse_ParseOk {
  struct kk_std_text_parse__parse_error_s _base;
  kk_box_t result;
  kk_std_core__sslice rest;
};
struct kk_std_text_parse_ParseError {
  struct kk_std_text_parse__parse_error_s _base;
  kk_string_t msg;
  kk_std_core__sslice rest;
};
static inline kk_std_text_parse__parse_error kk_std_text_parse__base_ParseOk(struct kk_std_text_parse_ParseOk* _x){
  return &_x->_base;
}
static inline kk_std_text_parse__parse_error kk_std_text_parse__new_ParseOk(kk_reuse_t _at, kk_box_t result, kk_std_core__sslice rest, kk_context_t* _ctx){
  struct kk_std_text_parse_ParseOk* _con = kk_block_alloc_at_as(struct kk_std_text_parse_ParseOk, _at, 2 /* scan count */, (kk_tag_t)(1), _ctx);
  _con->result = result;
  _con->rest = rest;
  return kk_std_text_parse__base_ParseOk(_con);
}
static inline struct kk_std_text_parse_ParseOk* kk_std_text_parse__as_ParseOk(kk_std_text_parse__parse_error x) {
  return kk_basetype_as_assert(struct kk_std_text_parse_ParseOk*, x, (kk_tag_t)(1) /* _tag */);
}
static inline kk_std_text_parse__parse_error kk_std_text_parse__base_ParseError(struct kk_std_text_parse_ParseError* _x){
  return &_x->_base;
}
static inline kk_std_text_parse__parse_error kk_std_text_parse__new_ParseError(kk_reuse_t _at, kk_string_t msg, kk_std_core__sslice rest, kk_context_t* _ctx){
  struct kk_std_text_parse_ParseError* _con = kk_block_alloc_at_as(struct kk_std_text_parse_ParseError, _at, 2 /* scan count */, (kk_tag_t)(2), _ctx);
  _con->msg = msg;
  _con->rest = rest;
  return kk_std_text_parse__base_ParseError(_con);
}
static inline struct kk_std_text_parse_ParseError* kk_std_text_parse__as_ParseError(kk_std_text_parse__parse_error x) {
  return kk_basetype_as_assert(struct kk_std_text_parse_ParseError*, x, (kk_tag_t)(2) /* _tag */);
}
static inline bool kk_std_text_parse__is_ParseOk(kk_std_text_parse__parse_error x) {
  return (kk_basetype_has_tag(x, (kk_tag_t)(1)));
}
static inline bool kk_std_text_parse__is_ParseError(kk_std_text_parse__parse_error x) {
  return (kk_basetype_has_tag(x, (kk_tag_t)(2)));
}
static inline kk_std_text_parse__parse_error kk_std_text_parse__parse_error_dup(kk_std_text_parse__parse_error _x) {
  return kk_basetype_dup_as(kk_std_text_parse__parse_error, _x);
}
static inline void kk_std_text_parse__parse_error_drop(kk_std_text_parse__parse_error _x, kk_context_t* _ctx) {
  kk_basetype_drop(_x, _ctx);
}
static inline bool kk_std_text_parse__parse_error_is_unique(kk_std_text_parse__parse_error _x) {
  return kk_basetype_is_unique(_x);
}
static inline void kk_std_text_parse__parse_error_free(kk_std_text_parse__parse_error _x) {
  kk_basetype_free(_x);
}
static inline void kk_std_text_parse__parse_error_decref(kk_std_text_parse__parse_error _x, kk_context_t* _ctx) {
  kk_basetype_decref(_x, _ctx);
}
static inline kk_reuse_t kk_std_text_parse__parse_error_dropn_reuse(kk_std_text_parse__parse_error _x, size_t _scan_fsize, kk_context_t* _ctx) {
  return kk_basetype_dropn_reuse(_x, _scan_fsize, _ctx);
}
static inline void kk_std_text_parse__parse_error_dropn(kk_std_text_parse__parse_error _x, size_t _scan_fsize, kk_context_t* _ctx) {
  kk_basetype_dropn(_x, _scan_fsize, _ctx);
}
static inline kk_reuse_t kk_std_text_parse__parse_error_reuse(kk_std_text_parse__parse_error _x) {
  return kk_basetype_reuse(_x);
}
static inline kk_std_text_parse__parse_error kk_std_text_parse__parse_error_hole() {
  return (kk_std_text_parse__parse_error)(1);
}
static inline kk_box_t kk_std_text_parse__parse_error_box(kk_std_text_parse__parse_error _x, kk_context_t* _ctx) {
  return kk_basetype_box(_x);
}
static inline kk_std_text_parse__parse_error kk_std_text_parse__parse_error_unbox(kk_box_t _x, kk_context_t* _ctx) {
  return kk_basetype_unbox_as(kk_std_text_parse__parse_error, _x);
}

// value declarations
 
// Automatically generated. Retrieves the `rest` constructor field of the `:parse-error` type.

static inline kk_std_core__sslice kk_std_text_parse_rest(kk_std_text_parse__parse_error _this, kk_context_t* _ctx) { /* forall<a> (parse-error<a>) -> sslice */ 
  if (kk_std_text_parse__is_ParseOk(_this)) {
    struct kk_std_text_parse_ParseOk* _con4459 = kk_std_text_parse__as_ParseOk(_this);
    kk_box_t _pat0 = _con4459->result;
    kk_std_core__sslice _x = _con4459->rest;
    if (kk_std_text_parse__parse_error_is_unique(_this)) {
      kk_box_drop(_pat0, _ctx);
      kk_std_text_parse__parse_error_free(_this);
    }
    else {
      kk_std_core__sslice_dup(_x);
      kk_std_text_parse__parse_error_decref(_this, _ctx);
    }
    return _x;
  }
  struct kk_std_text_parse_ParseError* _con4460 = kk_std_text_parse__as_ParseError(_this);
  kk_string_t _pat5 = _con4460->msg;
  kk_std_core__sslice _x0 = _con4460->rest;
  if (kk_std_text_parse__parse_error_is_unique(_this)) {
    kk_string_drop(_pat5, _ctx);
    kk_std_text_parse__parse_error_free(_this);
  }
  else {
    kk_std_core__sslice_dup(_x0);
    kk_std_text_parse__parse_error_decref(_this, _ctx);
  }
  return _x0;
}
 
// Automatically generated. Tests for the `ParseOk` constructor of the `:parse-error` type.

static inline bool kk_std_text_parse_is_parseOk(kk_std_text_parse__parse_error parse_error, kk_context_t* _ctx) { /* forall<a> (parse-error : parse-error<a>) -> bool */ 
  if (kk_std_text_parse__is_ParseOk(parse_error)) {
    struct kk_std_text_parse_ParseOk* _con4461 = kk_std_text_parse__as_ParseOk(parse_error);
    kk_std_core__sslice _pat1 = _con4461->rest;
    kk_std_text_parse__parse_error_dropn(parse_error, ((int32_t)2), _ctx);
    return true;
  }
  kk_std_text_parse__parse_error_drop(parse_error, _ctx);
  return false;
}
 
// Automatically generated. Tests for the `ParseError` constructor of the `:parse-error` type.

static inline bool kk_std_text_parse_is_parseError(kk_std_text_parse__parse_error parse_error, kk_context_t* _ctx) { /* forall<a> (parse-error : parse-error<a>) -> bool */ 
  if (kk_std_text_parse__is_ParseError(parse_error)) {
    struct kk_std_text_parse_ParseError* _con4462 = kk_std_text_parse__as_ParseError(parse_error);
    kk_std_core__sslice _pat1 = _con4462->rest;
    kk_std_text_parse__parse_error_dropn(parse_error, ((int32_t)2), _ctx);
    return true;
  }
  kk_std_text_parse__parse_error_drop(parse_error, _ctx);
  return false;
}

extern kk_std_core_hnd__htag kk_std_text_parse__tag_parse;

kk_box_t kk_std_text_parse__handle_parse(int32_t cfc, kk_std_text_parse__hnd_parse hnd, kk_function_t ret, kk_function_t action, kk_context_t* _ctx); /* forall<a,e,b> (cfc : int32, hnd : .hnd-parse<e,b>, ret : (res : a) -> e b, action : () -> <parse|e> a) -> e b */ 
 
// select `current-input` operation out of the `:parse` effect handler

static inline kk_std_core_hnd__clause0 kk_std_text_parse__select_current_input(kk_std_text_parse__hnd_parse hnd, kk_context_t* _ctx) { /* forall<e,a> (hnd : .hnd-parse<e,a>) -> std/core/hnd/clause0<sslice,.hnd-parse,e,a> */ 
  struct kk_std_text_parse__Hnd_parse* _con4466 = kk_std_text_parse__as_Hnd_parse(hnd);
  kk_std_core_hnd__clause0 fun_current_input = _con4466->fun_current_input;
  kk_std_core_hnd__clause1 _pat0 = _con4466->control_fail;
  kk_std_core_hnd__clause0 _pat1 = _con4466->control_pick;
  kk_std_core_hnd__clause1 _pat2 = _con4466->fun_satisfy;
  if (kk_std_text_parse__hnd_parse_is_unique(hnd)) {
    kk_std_core_hnd__clause1_drop(_pat2, _ctx);
    kk_std_core_hnd__clause0_drop(_pat1, _ctx);
    kk_std_core_hnd__clause1_drop(_pat0, _ctx);
    kk_std_text_parse__hnd_parse_free(hnd);
  }
  else {
    kk_std_core_hnd__clause0_dup(fun_current_input);
    kk_std_text_parse__hnd_parse_decref(hnd, _ctx);
  }
  return fun_current_input;
}
 
// select `fail` operation out of the `:parse` effect handler

static inline kk_std_core_hnd__clause1 kk_std_text_parse__select_fail(kk_std_text_parse__hnd_parse hnd, kk_context_t* _ctx) { /* forall<a,e,b> (hnd : .hnd-parse<e,b>) -> std/core/hnd/clause1<string,a,.hnd-parse,e,b> */ 
  struct kk_std_text_parse__Hnd_parse* _con4467 = kk_std_text_parse__as_Hnd_parse(hnd);
  kk_std_core_hnd__clause0 _pat0 = _con4467->fun_current_input;
  kk_std_core_hnd__clause1 control_fail = _con4467->control_fail;
  kk_std_core_hnd__clause0 _pat1 = _con4467->control_pick;
  kk_std_core_hnd__clause1 _pat2 = _con4467->fun_satisfy;
  if (kk_std_text_parse__hnd_parse_is_unique(hnd)) {
    kk_std_core_hnd__clause1_drop(_pat2, _ctx);
    kk_std_core_hnd__clause0_drop(_pat1, _ctx);
    kk_std_core_hnd__clause0_drop(_pat0, _ctx);
    kk_std_text_parse__hnd_parse_free(hnd);
  }
  else {
    kk_std_core_hnd__clause1_dup(control_fail);
    kk_std_text_parse__hnd_parse_decref(hnd, _ctx);
  }
  return control_fail;
}
 
// select `pick` operation out of the `:parse` effect handler

static inline kk_std_core_hnd__clause0 kk_std_text_parse__select_pick(kk_std_text_parse__hnd_parse hnd, kk_context_t* _ctx) { /* forall<e,a> (hnd : .hnd-parse<e,a>) -> std/core/hnd/clause0<bool,.hnd-parse,e,a> */ 
  struct kk_std_text_parse__Hnd_parse* _con4468 = kk_std_text_parse__as_Hnd_parse(hnd);
  kk_std_core_hnd__clause0 _pat0 = _con4468->fun_current_input;
  kk_std_core_hnd__clause1 _pat1 = _con4468->control_fail;
  kk_std_core_hnd__clause0 control_pick = _con4468->control_pick;
  kk_std_core_hnd__clause1 _pat2 = _con4468->fun_satisfy;
  if (kk_std_text_parse__hnd_parse_is_unique(hnd)) {
    kk_std_core_hnd__clause1_drop(_pat2, _ctx);
    kk_std_core_hnd__clause1_drop(_pat1, _ctx);
    kk_std_core_hnd__clause0_drop(_pat0, _ctx);
    kk_std_text_parse__hnd_parse_free(hnd);
  }
  else {
    kk_std_core_hnd__clause0_dup(control_pick);
    kk_std_text_parse__hnd_parse_decref(hnd, _ctx);
  }
  return control_pick;
}
 
// select `satisfy` operation out of the `:parse` effect handler

static inline kk_std_core_hnd__clause1 kk_std_text_parse__select_satisfy(kk_std_text_parse__hnd_parse hnd, kk_context_t* _ctx) { /* forall<a,e,b> (hnd : .hnd-parse<e,b>) -> std/core/hnd/clause1<(sslice) -> total maybe<(a, sslice)>,maybe<a>,.hnd-parse,e,b> */ 
  struct kk_std_text_parse__Hnd_parse* _con4469 = kk_std_text_parse__as_Hnd_parse(hnd);
  kk_std_core_hnd__clause0 _pat0 = _con4469->fun_current_input;
  kk_std_core_hnd__clause1 _pat1 = _con4469->control_fail;
  kk_std_core_hnd__clause0 _pat2 = _con4469->control_pick;
  kk_std_core_hnd__clause1 fun_satisfy = _con4469->fun_satisfy;
  if (kk_std_text_parse__hnd_parse_is_unique(hnd)) {
    kk_std_core_hnd__clause0_drop(_pat2, _ctx);
    kk_std_core_hnd__clause1_drop(_pat1, _ctx);
    kk_std_core_hnd__clause0_drop(_pat0, _ctx);
    kk_std_text_parse__hnd_parse_free(hnd);
  }
  else {
    kk_std_core_hnd__clause1_dup(fun_satisfy);
    kk_std_text_parse__hnd_parse_decref(hnd, _ctx);
  }
  return fun_satisfy;
}

kk_std_core_types__either kk_std_text_parse_either(kk_std_text_parse__parse_error perr, kk_context_t* _ctx); /* forall<a> (perr : parse-error<a>) -> either<string,a> */ 
 
// call `fail` operation of the `:parse` effect

static inline kk_box_t kk_std_text_parse_fail(kk_string_t msg, kk_context_t* _ctx) { /* forall<a> (msg : string) -> parse a */ 
  kk_std_core_hnd__ev ev_2571;
  size_t _x4472 = ((size_t)0); /*size_t*/
  ev_2571 = kk_evv_at(_x4472,kk_context()); /*std/core/hnd/ev<std/text/parse/.hnd-parse>*/
  struct kk_std_core_hnd_Ev* _con4473 = kk_std_core_hnd__as_Ev(ev_2571);
  kk_std_core_hnd__marker m = _con4473->marker;
  kk_box_t _box_x2952 = _con4473->hnd;
  kk_std_text_parse__hnd_parse h = kk_std_text_parse__hnd_parse_unbox(_box_x2952, NULL);
  kk_std_text_parse__hnd_parse_dup(h);
  kk_std_core_hnd__clause1 _match_4458;
  struct kk_std_text_parse__Hnd_parse* _con4475 = kk_std_text_parse__as_Hnd_parse(h);
  kk_std_core_hnd__clause0 _pat00 = _con4475->fun_current_input;
  kk_std_core_hnd__clause1 control_fail = _con4475->control_fail;
  kk_std_core_hnd__clause0 _pat10 = _con4475->control_pick;
  kk_std_core_hnd__clause1 _pat20 = _con4475->fun_satisfy;
  if (kk_std_text_parse__hnd_parse_is_unique(h)) {
    kk_std_core_hnd__clause1_drop(_pat20, _ctx);
    kk_std_core_hnd__clause0_drop(_pat10, _ctx);
    kk_std_core_hnd__clause0_drop(_pat00, _ctx);
    kk_std_text_parse__hnd_parse_free(h);
  }
  else {
    kk_std_core_hnd__clause1_dup(control_fail);
    kk_std_text_parse__hnd_parse_decref(h, _ctx);
  }
  _match_4458 = control_fail; /*forall<a> std/core/hnd/clause1<string,a,std/text/parse/.hnd-parse,3528,3529>*/
  kk_function_t _fun_unbox_x2956 = _match_4458.clause;
  return kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x2956, (_fun_unbox_x2956, m, ev_2571, kk_string_box(msg), _ctx));
}
 
// call `satisfy` operation of the `:parse` effect


// lift anonymous function
struct kk_std_text_parse_satisfy_fun4481__t {
  struct kk_function_s _base;
  kk_function_t pred;
};
extern kk_box_t kk_std_text_parse_satisfy_fun4481(kk_function_t _fself, kk_box_t _b_2976, kk_context_t* _ctx);
static inline kk_function_t kk_std_text_parse_new_satisfy_fun4481(kk_function_t pred, kk_context_t* _ctx) {
  struct kk_std_text_parse_satisfy_fun4481__t* _self = kk_function_alloc_as(struct kk_std_text_parse_satisfy_fun4481__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_text_parse_satisfy_fun4481, kk_context());
  _self->pred = pred;
  return &_self->_base;
}


static inline kk_std_core_types__maybe kk_std_text_parse_satisfy(kk_function_t pred, kk_context_t* _ctx) { /* forall<a> (pred : (sslice) -> total maybe<(a, sslice)>) -> parse maybe<a> */ 
  kk_std_core_hnd__ev ev_2574;
  size_t _x4476 = ((size_t)0); /*size_t*/
  ev_2574 = kk_evv_at(_x4476,kk_context()); /*std/core/hnd/ev<std/text/parse/.hnd-parse>*/
  kk_box_t _x4477;
  struct kk_std_core_hnd_Ev* _con4478 = kk_std_core_hnd__as_Ev(ev_2574);
  kk_std_core_hnd__marker m = _con4478->marker;
  kk_box_t _box_x2963 = _con4478->hnd;
  kk_std_text_parse__hnd_parse h = kk_std_text_parse__hnd_parse_unbox(_box_x2963, NULL);
  kk_std_text_parse__hnd_parse_dup(h);
  kk_std_core_hnd__clause1 _match_4457;
  struct kk_std_text_parse__Hnd_parse* _con4480 = kk_std_text_parse__as_Hnd_parse(h);
  kk_std_core_hnd__clause0 _pat00 = _con4480->fun_current_input;
  kk_std_core_hnd__clause1 _pat10 = _con4480->control_fail;
  kk_std_core_hnd__clause0 _pat20 = _con4480->control_pick;
  kk_std_core_hnd__clause1 fun_satisfy = _con4480->fun_satisfy;
  if (kk_std_text_parse__hnd_parse_is_unique(h)) {
    kk_std_core_hnd__clause0_drop(_pat20, _ctx);
    kk_std_core_hnd__clause1_drop(_pat10, _ctx);
    kk_std_core_hnd__clause0_drop(_pat00, _ctx);
    kk_std_text_parse__hnd_parse_free(h);
  }
  else {
    kk_std_core_hnd__clause1_dup(fun_satisfy);
    kk_std_text_parse__hnd_parse_decref(h, _ctx);
  }
  _match_4457 = fun_satisfy; /*forall<a> std/core/hnd/clause1<(sslice) -> total maybe<(a, sslice)>,maybe<a>,std/text/parse/.hnd-parse,3528,3529>*/
  kk_function_t _fun_unbox_x2970 = _match_4457.clause;
  _x4477 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x2970, (_fun_unbox_x2970, m, ev_2574, kk_function_box(kk_std_text_parse_new_satisfy_fun4481(pred, _ctx)), _ctx)); /*53*/
  return kk_std_core_types__maybe_unbox(_x4477, _ctx);
}

kk_box_t kk_std_text_parse__mlift2547_satisfy_fail(kk_string_t msg, kk_std_core_types__maybe _y_3, kk_context_t* _ctx); /* forall<a> (msg : string, maybe<a>) -> parse a */ 

kk_box_t kk_std_text_parse_satisfy_fail(kk_string_t msg, kk_function_t pred, kk_context_t* _ctx); /* forall<a> (msg : string, pred : (sslice) -> maybe<(a, sslice)>) -> parse a */ 

kk_char_t kk_std_text_parse_char_is(kk_string_t msg, kk_function_t pred, kk_context_t* _ctx); /* (msg : string, pred : (char) -> bool) -> parse char */ 

kk_char_t kk_std_text_parse_alpha(kk_context_t* _ctx); /* () -> parse char */ 

kk_char_t kk_std_text_parse_alpha_num(kk_context_t* _ctx); /* () -> parse char */ 

kk_char_t kk_std_text_parse_char(kk_char_t c, kk_context_t* _ctx); /* (c : char) -> parse char */ 

kk_std_core_types__tuple2_ kk_std_text_parse_next_while0(kk_std_core__sslice slice, kk_function_t pred, kk_std_core__list acc, kk_context_t* _ctx); /* (slice : sslice, pred : (char) -> bool, acc : list<char>) -> (list<char>, sslice) */ 

kk_std_core__list kk_std_text_parse_chars_are(kk_string_t msg, kk_function_t pred, kk_context_t* _ctx); /* (msg : string, pred : (char) -> bool) -> parse list<char> */ 
 
// call `pick` operation of the `:parse` effect

static inline bool kk_std_text_parse_pick(kk_context_t* _ctx) { /* () -> parse bool */ 
  kk_std_core_hnd__ev ev_2618;
  size_t _x4587 = ((size_t)0); /*size_t*/
  ev_2618 = kk_evv_at(_x4587,kk_context()); /*std/core/hnd/ev<std/text/parse/.hnd-parse>*/
  kk_box_t _x4588;
  struct kk_std_core_hnd_Ev* _con4589 = kk_std_core_hnd__as_Ev(ev_2618);
  kk_std_core_hnd__marker m = _con4589->marker;
  kk_box_t _box_x3186 = _con4589->hnd;
  kk_std_text_parse__hnd_parse h = kk_std_text_parse__hnd_parse_unbox(_box_x3186, NULL);
  kk_std_text_parse__hnd_parse_dup(h);
  kk_std_core_hnd__clause0 _match_4439;
  struct kk_std_text_parse__Hnd_parse* _con4591 = kk_std_text_parse__as_Hnd_parse(h);
  kk_std_core_hnd__clause0 _pat00 = _con4591->fun_current_input;
  kk_std_core_hnd__clause1 _pat10 = _con4591->control_fail;
  kk_std_core_hnd__clause0 control_pick = _con4591->control_pick;
  kk_std_core_hnd__clause1 _pat20 = _con4591->fun_satisfy;
  if (kk_std_text_parse__hnd_parse_is_unique(h)) {
    kk_std_core_hnd__clause1_drop(_pat20, _ctx);
    kk_std_core_hnd__clause1_drop(_pat10, _ctx);
    kk_std_core_hnd__clause0_drop(_pat00, _ctx);
    kk_std_text_parse__hnd_parse_free(h);
  }
  else {
    kk_std_core_hnd__clause0_dup(control_pick);
    kk_std_text_parse__hnd_parse_decref(h, _ctx);
  }
  _match_4439 = control_pick; /*std/core/hnd/clause0<bool,std/text/parse/.hnd-parse,3435,3436>*/
  kk_function_t _fun_unbox_x3189 = _match_4439.clause;
  _x4588 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x3189, (_fun_unbox_x3189, m, ev_2618, _ctx)); /*37*/
  return kk_bool_unbox(_x4588);
}

kk_box_t kk_std_text_parse__mlift2548_choose(kk_function_t p0, kk_std_core__list pp, bool _y_14, kk_context_t* _ctx); /* forall<a,e> (p0 : parser<e,a>, pp : list<parser<e,a>>, bool) -> <parse|e> a */ 

kk_box_t kk_std_text_parse_choose(kk_std_core__list ps, kk_context_t* _ctx); /* forall<a,e> (ps : list<parser<e,a>>) -> <parse|e> a */ 

kk_std_core__list kk_std_text_parse__mlift2549_count_acc(kk_std_core__list acc, kk_integer_t n, kk_function_t p, kk_box_t x, kk_context_t* _ctx); /* forall<a,e> (acc : list<a>, n : int, p : parser<e,a>, x : a) -> <parse|e> list<a> */ 

kk_std_core__list kk_std_text_parse_count_acc(kk_integer_t n0, kk_std_core__list acc0, kk_function_t p0, kk_context_t* _ctx); /* forall<a,e> (n : int, acc : list<a>, p : parser<e,a>) -> <parse|e> list<a> */ 

static inline kk_std_core__list kk_std_text_parse_count(kk_integer_t n, kk_function_t p, kk_context_t* _ctx) { /* forall<a,e> (n : int, p : parser<e,a>) -> <parse|e> list<a> */ 
  return kk_std_text_parse_count_acc(n, kk_std_core__new_Nil(_ctx), p, _ctx);
}
 
// call `current-input` operation of the `:parse` effect

static inline kk_std_core__sslice kk_std_text_parse_current_input(kk_context_t* _ctx) { /* () -> parse sslice */ 
  kk_std_core_hnd__ev ev_2635;
  size_t _x4625 = ((size_t)0); /*size_t*/
  ev_2635 = kk_evv_at(_x4625,kk_context()); /*std/core/hnd/ev<std/text/parse/.hnd-parse>*/
  kk_box_t _x4626;
  struct kk_std_core_hnd_Ev* _con4627 = kk_std_core_hnd__as_Ev(ev_2635);
  kk_std_core_hnd__marker m = _con4627->marker;
  kk_box_t _box_x3242 = _con4627->hnd;
  kk_std_text_parse__hnd_parse h = kk_std_text_parse__hnd_parse_unbox(_box_x3242, NULL);
  kk_std_text_parse__hnd_parse_dup(h);
  kk_std_core_hnd__clause0 _match_4431;
  struct kk_std_text_parse__Hnd_parse* _con4629 = kk_std_text_parse__as_Hnd_parse(h);
  kk_std_core_hnd__clause0 fun_current_input = _con4629->fun_current_input;
  kk_std_core_hnd__clause1 _pat00 = _con4629->control_fail;
  kk_std_core_hnd__clause0 _pat10 = _con4629->control_pick;
  kk_std_core_hnd__clause1 _pat20 = _con4629->fun_satisfy;
  if (kk_std_text_parse__hnd_parse_is_unique(h)) {
    kk_std_core_hnd__clause1_drop(_pat20, _ctx);
    kk_std_core_hnd__clause0_drop(_pat10, _ctx);
    kk_std_core_hnd__clause1_drop(_pat00, _ctx);
    kk_std_text_parse__hnd_parse_free(h);
  }
  else {
    kk_std_core_hnd__clause0_dup(fun_current_input);
    kk_std_text_parse__hnd_parse_decref(h, _ctx);
  }
  _match_4431 = fun_current_input; /*std/core/hnd/clause0<sslice,std/text/parse/.hnd-parse,3435,3436>*/
  kk_function_t _fun_unbox_x3245 = _match_4431.clause;
  _x4626 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x3245, (_fun_unbox_x3245, m, ev_2635, _ctx)); /*37*/
  return kk_std_core__sslice_unbox(_x4626, _ctx);
}

kk_integer_t kk_std_text_parse__mlift2550_digit(kk_char_t c, kk_context_t* _ctx); /* (c : char) -> parse int */ 

kk_integer_t kk_std_text_parse_digit(kk_context_t* _ctx); /* () -> parse int */ 

kk_string_t kk_std_text_parse_digits(kk_context_t* _ctx); /* () -> parse string */ 

kk_box_t kk_std_text_parse__mlift2551_op(kk_function_t p1, kk_function_t p2, bool _y_26, kk_context_t* _ctx); /* forall<a,e> (p1 : parser<e,a>, p2 : parser<e,a>, bool) -> <parse|e> a */ 

kk_box_t kk_std_text_parse__lp__bar__bar__rp_(kk_function_t p1, kk_function_t p2, kk_context_t* _ctx); /* forall<a,e> (p1 : parser<e,a>, p2 : parser<e,a>) -> <parse|e> a */ 

kk_box_t kk_std_text_parse_optional(kk_box_t kkloc_default, kk_function_t p, kk_context_t* _ctx); /* forall<a,e> (default : a, p : parser<e,a>) -> <parse|e> a */ 

kk_string_t kk_std_text_parse_digits0(kk_context_t* _ctx); /* () -> parse string */ 

kk_unit_t kk_std_text_parse__mlift2552_eof(kk_std_core_types__maybe _y_32, kk_context_t* _ctx); /* (maybe<()>) -> parse () */ 

kk_unit_t kk_std_text_parse_eof(kk_context_t* _ctx); /* () -> parse () */ 

kk_string_t kk_std_text_parse_hex_digits(kk_context_t* _ctx); /* () -> parse string */ 

kk_std_core__list kk_std_text_parse__mlift2553_many_acc(kk_std_core__list acc, kk_function_t p, kk_box_t x, kk_context_t* _ctx); /* forall<a,e> (acc : list<a>, p : parser<e,a>, x : a) -> <parse|e> list<a> */ 

kk_std_core__list kk_std_text_parse_many_acc(kk_function_t p0, kk_std_core__list acc0, kk_context_t* _ctx); /* forall<a,e> (p : parser<e,a>, acc : list<a>) -> <parse|e> list<a> */ 

static inline kk_std_core__list kk_std_text_parse_many(kk_function_t p, kk_context_t* _ctx) { /* forall<a,e> (p : parser<e,a>) -> <parse|e> list<a> */ 
  return kk_std_text_parse_many_acc(p, kk_std_core__new_Nil(_ctx), _ctx);
}

kk_std_core__list kk_std_text_parse__mlift2554_many1(kk_box_t _y_40, kk_std_core__list _y_41, kk_context_t* _ctx); /* forall<a,e> (a, list<a>) -> <parse|e> list<a> */ 

kk_std_core__list kk_std_text_parse__mlift2555_many1(kk_function_t p, kk_box_t _y_40, kk_context_t* _ctx); /* forall<a,e> (p : parser<e,a>, a) -> <parse|e> list<a> */ 

kk_std_core__list kk_std_text_parse_many1(kk_function_t p, kk_context_t* _ctx); /* forall<a,e> (p : parser<e,a>) -> <parse|e> list<a> */ 

static inline kk_std_core_types__maybe kk_std_text_parse_maybe(kk_std_text_parse__parse_error perr, kk_context_t* _ctx) { /* forall<a> (perr : parse-error<a>) -> maybe<a> */ 
  kk_std_core_types__either e_2721 = kk_std_text_parse_either(perr, _ctx); /*either<string,1434>*/;
  if (kk_std_core_types__is_Left(e_2721)) {
    kk_box_t _box_x3604 = e_2721._cons.Left.left;
    kk_std_core_types__either_drop(e_2721, _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
  kk_box_t x = e_2721._cons.Right.right;
  return kk_std_core_types__new_Just(x, _ctx);
}

kk_std_core_types__maybe kk_std_text_parse_next_match(kk_std_core__sslice slice, kk_std_core__list cs, kk_context_t* _ctx); /* (slice : sslice, cs : list<char>) -> maybe<sslice> */ 

kk_char_t kk_std_text_parse_no_digit(kk_context_t* _ctx); /* () -> parse char */ 

kk_char_t kk_std_text_parse_none_of(kk_string_t chars, kk_context_t* _ctx); /* (chars : string) -> parse char */ 

kk_string_t kk_std_text_parse_none_of_many1(kk_string_t chars, kk_context_t* _ctx); /* (chars : string) -> parse string */ 

kk_char_t kk_std_text_parse_one_of(kk_string_t chars, kk_context_t* _ctx); /* (chars : string) -> parse char */ 

kk_char_t kk_std_text_parse_one_of_or(kk_string_t chars, kk_char_t kkloc_default, kk_context_t* _ctx); /* (chars : string, default : char) -> parse char */ 

kk_std_text_parse__parse_error kk_std_text_parse__mlift2556_parse(kk_string_t msg, kk_std_core__sslice _y_49, kk_context_t* _ctx); /* forall<_h,h1,a,e> (msg : string, sslice) -> <local<h1>,local<_h>|e> parse-error<a> */ 

kk_std_text_parse__parse_error kk_std_text_parse__mlift2557_parse(kk_std_text_parse__parse_error err1, kk_std_text_parse__parse_error _y_53, kk_context_t* _ctx); /* forall<_h,h1,a,e> (err1 : parse-error<a>, parse-error<a>) -> <local<h1>,local<_h>|e> parse-error<a> */ 

kk_std_text_parse__parse_error kk_std_text_parse__mlift2558_parse(kk_std_text_parse__parse_error err1, kk_function_t resume0, kk_unit_t wild__, kk_context_t* _ctx); /* forall<_h,h1,a,e> (err1 : parse-error<a>, resume0 : (bool) -> <local<h1>,local<_h>|e> parse-error<a>, wild_ : ()) -> <local<h1>,local<_h>|e> parse-error<a> */ 

kk_std_text_parse__parse_error kk_std_text_parse__mlift2559_parse(kk_ref_t input, kk_function_t resume0, kk_std_core__sslice save, kk_std_text_parse__parse_error _y_51, kk_context_t* _ctx); /* forall<_h,h1,a,e> (input : local-var<h1,sslice>, resume0 : (bool) -> <local<h1>,local<_h>|e> parse-error<a>, save : sslice, parse-error<a>) -> <local<h1>,local<_h>|e> parse-error<a> */ 

kk_std_text_parse__parse_error kk_std_text_parse__mlift2560_parse(kk_ref_t input, kk_function_t resume0, kk_std_core__sslice save, kk_context_t* _ctx); /* forall<_h,h1,a,e> (input : local-var<h1,sslice>, resume0 : (bool) -> <local<h1>,local<_h>|e> parse-error<a>, save : sslice) -> <local<h1>,local<_h>|e> parse-error<a> */ 

kk_std_core_types__maybe kk_std_text_parse__mlift2561_parse(kk_box_t x, kk_unit_t wild__0, kk_context_t* _ctx); /* forall<_h,a,h1,e> (x : a, wild_0 : ()) -> <local<h1>,local<_h>|e> maybe<a> */ 

kk_std_core_types__maybe kk_std_text_parse__mlift2562_parse(kk_ref_t input, kk_function_t pred, kk_std_core__sslice inp, kk_context_t* _ctx); /* forall<_h,a,h1,e> (input : local-var<h1,sslice>, pred : (sslice) -> total maybe<(a, sslice)>, inp : sslice) -> <local<h1>,local<_h>|e> maybe<a> */ 

kk_std_text_parse__parse_error kk_std_text_parse__mlift2563_parse(kk_box_t x0, kk_std_core__sslice _y_58, kk_context_t* _ctx); /* forall<_h,h1,a,e> (x0 : a, sslice) -> <local<h1>,local<_h>|e> parse-error<a> */ 

kk_std_text_parse__parse_error kk_std_text_parse_parse(kk_std_core__sslice input0, kk_function_t p, kk_context_t* _ctx); /* forall<a,e> (input0 : sslice, p : () -> <parse|e> a) -> e parse-error<a> */ 

kk_box_t kk_std_text_parse__mlift2564_parse_eof(kk_box_t x, kk_unit_t wild__, kk_context_t* _ctx); /* forall<a,e> (x : a, wild_ : ()) -> <parse|e> a */ 

kk_box_t kk_std_text_parse__mlift2565_parse_eof(kk_box_t x, kk_context_t* _ctx); /* forall<a,e> (x : a) -> <parse|e> a */ 

kk_std_text_parse__parse_error kk_std_text_parse_parse_eof(kk_std_core__sslice input, kk_function_t p, kk_context_t* _ctx); /* forall<a,e> (input : sslice, p : () -> <parse|e> a) -> e parse-error<a> */ 

kk_integer_t kk_std_text_parse__mlift2566_pnat(kk_string_t _y_67, kk_context_t* _ctx); /* (string) -> parse int */ 

kk_integer_t kk_std_text_parse_pnat(kk_context_t* _ctx); /* () -> parse int */ 

bool kk_std_text_parse__mlift2567_sign(kk_char_t c, kk_context_t* _ctx); /* (c : char) -> parse bool */ 

bool kk_std_text_parse_sign(kk_context_t* _ctx); /* () -> parse bool */ 

kk_integer_t kk_std_text_parse__mlift2568_pint(bool neg, kk_integer_t i, kk_context_t* _ctx); /* (neg : bool, i : int) -> parse int */ 

kk_integer_t kk_std_text_parse__mlift2569_pint(bool neg, kk_context_t* _ctx); /* (neg : bool) -> parse int */ 

kk_integer_t kk_std_text_parse_pint(kk_context_t* _ctx); /* () -> parse int */ 

kk_string_t kk_std_text_parse_pstring(kk_string_t s, kk_context_t* _ctx); /* (s : string) -> parse string */ 

kk_std_core_types__maybe kk_std_text_parse_starts_with(kk_string_t s, kk_function_t p, kk_context_t* _ctx); /* forall<a> (s : string, p : () -> parse a) -> maybe<(a, sslice)> */ 

kk_char_t kk_std_text_parse_white(kk_context_t* _ctx); /* () -> parse char */ 

kk_string_t kk_std_text_parse_whitespace(kk_context_t* _ctx); /* () -> parse string */ 

kk_string_t kk_std_text_parse_whitespace0(kk_context_t* _ctx); /* () -> parse string */ 

void kk_std_text_parse__init(kk_context_t* _ctx);

#endif // header
