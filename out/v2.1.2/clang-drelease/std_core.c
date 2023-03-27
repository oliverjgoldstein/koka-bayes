// Koka generated module: "std/core", koka version: 2.1.2
#include "std_core.h"
/*---------------------------------------------------------------------------
  Copyright 2020 Microsoft Corporation.

  This is free software; you can redistribute it and/or modify it under the
  terms of the Apache License, Version 2.0. A copy of the License can be
  found in the file "license.txt" at the root of this distribution.
---------------------------------------------------------------------------*/

kk_std_core__list kk_vector_to_list(kk_vector_t v, kk_std_core__list tail, kk_context_t* ctx) {
  // todo: avoid boxed_dup if v is unique
  size_t n;
  kk_box_t* p = kk_vector_buf(v, &n);
  if (n == 0) {
    kk_vector_drop(v,ctx);
    return tail;
  }
  kk_std_core__list nil  = kk_std_core__new_Nil(ctx);
  struct kk_std_core_Cons* cons = NULL;
  kk_std_core__list list = kk_std_core__new_Nil(ctx);
  for( size_t i = 0; i < n; i++ ) {
    kk_std_core__list hd = kk_std_core__new_Cons(kk_reuse_null,kk_box_dup(p[i]), nil, ctx);
    if (cons==NULL) {
      list = hd;
    }
    else {
      cons->tail = hd;
    }
    cons = kk_std_core__as_Cons(hd);
  }
  cons->tail = tail;
  kk_vector_drop(v,ctx);
  return list;
}

kk_vector_t kk_list_to_vector(kk_std_core__list xs, kk_context_t* ctx) {
  // todo: avoid boxed_dup if xs is unique
  // find the length
  size_t len = 0;
  kk_std_core__list ys = xs;
  while (kk_std_core__is_Cons(ys)) {
    struct kk_std_core_Cons* cons = kk_std_core__as_Cons(ys);
    len++;
    ys = cons->tail;
  }
  // alloc the vector and copy
  kk_vector_t v = kk_vector_alloc(len,kk_box_null,ctx);
  kk_box_t* p = kk_vector_buf(v,NULL);
  ys = xs;
  for( size_t i = 0; i < len; i++) {
    struct kk_std_core_Cons* cons = kk_std_core__as_Cons(ys);
    ys = cons->tail;
    p[i] = kk_box_dup(cons->head);
  }
  return v;
}

kk_vector_t kk_vector_init( size_t n, kk_function_t init, kk_context_t* ctx) {
  kk_vector_t v = kk_vector_alloc(n,kk_box_null,ctx);
  kk_box_t* p = kk_vector_buf(v,NULL);
  for(size_t i = 0; i < n; i++) {
    kk_function_dup(init);
    p[i] = kk_function_call(kk_box_t,(kk_function_t,size_t,kk_context_t*),init,(init,i,ctx));
  }
  kk_function_drop(init,ctx);
  return v;
}

kk_box_t kk_main_console( kk_function_t action, kk_context_t* ctx ) {
  return kk_function_call(kk_box_t,(kk_function_t,kk_unit_t,kk_context_t*),action,(action,kk_Unit,ctx));
}


kk_std_core__list kk_string_to_list(kk_string_t s, kk_context_t* ctx) {
  size_t len;
  const uint8_t* p = kk_string_buf_borrow(s,&len);
  const uint8_t* const end = p + len;
  kk_std_core__list nil  = kk_std_core__new_Nil(ctx);
  kk_std_core__list list = nil;
  struct kk_std_core_Cons* tl = NULL;
  size_t count;
  while( p < end ) {
    kk_char_t c = kk_utf8_read(p,&count);
    p += count;
    kk_std_core__list cons = kk_std_core__new_Cons(kk_reuse_null,kk_char_box(c,ctx), nil, ctx);
    if (tl!=NULL) {
      tl->tail = cons;
    }
    else {
      list = cons;
    }
    tl = kk_std_core__as_Cons(cons);
  }
  return list;
}

kk_string_t kk_string_from_list(kk_std_core__list cs, kk_context_t* ctx) {
  // TODO: optimize for short strings to write directly into a local buffer?
  // find total UTF8 length
  size_t len = 0;
  kk_std_core__list xs = cs;
  while (kk_std_core__is_Cons(xs)) {
    struct kk_std_core_Cons* cons = kk_std_core__as_Cons(xs);
    len += kk_utf8_len(kk_char_unbox(cons->head,ctx));
    xs = cons->tail;
  }
  // allocate and copy the characters
  uint8_t* p;
  kk_string_t s = kk_unsafe_string_alloc_buf(len,&p,ctx);  // must be initialized
  xs = cs;
  while (kk_std_core__is_Cons(xs)) {
    struct kk_std_core_Cons* cons = kk_std_core__as_Cons(xs);
    size_t count;
    kk_utf8_write( kk_char_unbox(cons->head,ctx), p, &count );
    p += count;
    xs = cons->tail;
  }
  kk_assert_internal(*p == 0 && (p - kk_string_buf_borrow(s,NULL)) == len);
  kk_std_core__list_drop(cs,ctx);  // todo: drop while visiting?
  return s;
}

static inline void kk_sslice_start_end_borrowx( kk_std_core__sslice sslice, const uint8_t** start, const uint8_t** end, const uint8_t** sstart, const uint8_t** send) {
  size_t slen;
  const uint8_t* s = kk_string_buf_borrow(sslice.str,&slen);
  *start = s + sslice.start;
  *end = s + sslice.start + sslice.len;
  if (sstart != NULL) *sstart = s;
  if (send != NULL) *send = s + slen;
  kk_assert_internal(*start >= s && *start <= *end);
  kk_assert_internal(*end >= *start && *end <= s + slen);
}

static inline void kk_sslice_start_end_borrow( kk_std_core__sslice sslice, const uint8_t** start, const uint8_t** end) {
  kk_sslice_start_end_borrowx(sslice,start,end,NULL,NULL);
}

kk_integer_t kk_slice_count( kk_std_core__sslice sslice, kk_context_t* ctx ) {
  // TODO: optimize this by extending kk_string_count
  const uint8_t* start;
  const uint8_t* end;
  kk_sslice_start_end_borrow(sslice, &start, &end);
  size_t count = 0;
  while( start < end && *start != 0 ) {
    const uint8_t* next = kk_utf8_next(start);
    count++;
    start = next;
  }
  return kk_integer_from_size_t(count,ctx);
}

kk_string_t kk_slice_to_string( kk_std_core__sslice  sslice, kk_context_t* ctx ) {
  const uint8_t* start;
  const uint8_t* end;
  kk_sslice_start_end_borrow(sslice, &start, &end);
  // is it the full string?
  if (sslice.start == 0 && sslice.len == kk_string_len_borrow(sslice.str)) {
    // TODO: drop sslice and dup sslice.str?
    return sslice.str;
  }
  else {
    // if not, we copy len bytes
    kk_string_t s = kk_string_alloc_dupn_valid_utf8(sslice.len, start, ctx);
    kk_std_core__sslice_drop(sslice,ctx);
    return s;
  }
}

kk_std_core__sslice kk_slice_first( kk_string_t str, kk_context_t* ctx ) {
  size_t slen;
  const uint8_t* s = kk_string_buf_borrow(str,&slen);
  const uint8_t* next = (slen > 0 ? kk_utf8_next(s) : s);
  return kk_std_core__new_Sslice(str, 0, (size_t)(next - s), ctx);
}

kk_std_core__sslice kk_slice_last( kk_string_t str, kk_context_t* ctx ) {
  size_t slen;
  const uint8_t* s = kk_string_buf_borrow(str,&slen);
  const uint8_t* end = s + slen;
  const uint8_t* prev = (s==end ? s : kk_utf8_prev(end));
  return kk_std_core__new_Sslice(str, (size_t)(prev - s), (size_t)(end - prev), ctx);
}

kk_std_core_types__maybe kk_slice_next( struct kk_std_core_Sslice slice, kk_context_t* ctx ) {
  if (slice.len == 0) {
    kk_std_core__sslice_drop(slice,ctx);
    return kk_std_core_types__new_Nothing(ctx);
  }
  const uint8_t* start;
  const uint8_t* end;
  kk_sslice_start_end_borrow(slice, &start, &end);
  size_t clen;
  const kk_char_t c = kk_utf8_read(start,&clen);
  kk_assert_internal(clen > 0 && clen <= slice.len);
  if (clen > slice.len) clen = slice.len;
  // TODO: specialize type to avoid boxing
  kk_std_core__sslice snext = kk_std_core__new_Sslice(slice.str, slice.start + clen, slice.len - clen, ctx);
  kk_std_core_types__tuple2_ res = kk_std_core_types__new_dash__lp__comma__rp_( kk_char_box(c,ctx), kk_std_core__sslice_box(snext,ctx), ctx);
  return kk_std_core_types__new_Just( kk_std_core_types__tuple2__box(res,ctx), ctx );
}

struct kk_std_core_Sslice kk_slice_extend( struct kk_std_core_Sslice slice, kk_integer_t count, kk_context_t* ctx ) {
  ptrdiff_t cnt = kk_integer_clamp(count,ctx);
  if (cnt==0 || (slice.len == 0 && cnt<0)) return slice;
  const uint8_t* s0;
  const uint8_t* s1;
  kk_sslice_start_end_borrow(slice,&s0,&s1);
  const uint8_t* t  = s1;
  if (cnt >= 0) {
    do {
      t = kk_utf8_next(t);
      cnt--;
    } while (cnt > 0 && *t != 0);
  }
  else {  // cnt < 0
    const uint8_t* sstart = s0 - slice.start;
    do {
      t = kk_utf8_prev(t);
      cnt++;
    } while (cnt < 0 && t > sstart);
  }
  if (t == s1) return slice;  // length is unchanged
  return kk_std_core__new_Sslice(slice.str, slice.start, (t < s0 ? 0 : (size_t)(t - s0)), ctx);
}

struct kk_std_core_Sslice kk_slice_advance( struct kk_std_core_Sslice slice, kk_integer_t count, kk_context_t* ctx ) {
  const ptrdiff_t cnt0 = kk_integer_clamp(count,ctx);
  ptrdiff_t cnt = cnt0;
  if (cnt==0 || (slice.start == 0 && cnt<0)) return slice;
  const uint8_t* sstart;
  const uint8_t* s0;
  const uint8_t* s1;
  const uint8_t* send;
  kk_sslice_start_end_borrowx(slice,&s0,&s1,&sstart,&send);
  // advance the start
  const uint8_t* t0  = s0;
  if (cnt >= 0) {
    do {
      t0 = kk_utf8_next(t0);
      cnt--;
    } while (cnt > 0 && t0 < send);
  }
  else {  // cnt < 0
    do {
      t0 = kk_utf8_prev(t0);
      cnt++;
    } while (cnt < 0 && t0 > sstart);
  }
  if (t0 == s0) return slice;  // start is unchanged
  // "t0" points to the new start, now advance the end by the same amount of codepoints
  const uint8_t* t1 = s1;
  cnt = cnt0;
  if (cnt >= 0) {
    do {
      t1 = kk_utf8_next(t1);
      cnt--;
    } while (cnt > 0 && t1 < send);
  }
  else {  // cnt < 0
    do {
      t1 = kk_utf8_prev(t1);
      cnt++;
    } while (cnt < 0 && t1 > sstart);
  }
  // t1 points to the new end
  kk_assert_internal(t1 >= t0);
  return kk_std_core__new_Sslice(slice.str, (size_t)(t0 - sstart), (size_t)(t1 - t0), ctx);
}

struct kk_std_core_Sslice kk_slice_common_prefix( kk_string_t str1, kk_string_t str2, kk_integer_t iupto, kk_context_t* ctx ) {
  const uint8_t* s1 = kk_string_buf_borrow(str1,NULL);
  const uint8_t* s2 = kk_string_buf_borrow(str2,NULL);
  size_t upto = kk_integer_clamp_size_t(iupto,ctx);
  size_t count;
  for(count = 0; count < upto && *s1 != 0 && *s2 != 0; count++, s1++, s2++ ) {
    if (*s1 != *s2) break;
  }
  kk_string_drop(str2,ctx);
  return kk_std_core__new_Sslice(str1, 0, count, ctx);
}


kk_std_core__error kk_error_ok( kk_box_t result, kk_context_t* ctx ) {
  return kk_std_core__new_Ok( result, ctx );
}

kk_std_core__error kk_error_from_errno( int err, kk_context_t* ctx ) {  
  kk_string_t msg;
  #if defined(_GNU_SOURCE) && !defined(__APPLE__) && !defined(__FreeBSD__)
    // GNU version of strerror_r
    char buf[256];
    char* serr = strerror_r(err, buf, 255); buf[255] = 0;
    msg = kk_string_alloc_from_qutf8( serr, ctx );
  #elif (/* _POSIX_C_SOURCE >= 200112L ||*/ _XOPEN_SOURCE >= 600 || defined(__APPLE__) || defined(__FreeBSD__))
    // XSI version of strerror_r
    char buf[256];
    strerror_r(err, buf, 255); buf[255] = 0;
    msg = kk_string_alloc_from_qutf8( buf, ctx );
  #elif defined(_MSC_VER) || (__STDC_VERSION__ >= 201112L || __cplusplus >= 201103L)
    // MSVC, or C/C++ 11
    char buf[256];
    strerror_s(buf, 255, err); buf[255] = 0;
    msg = kk_string_alloc_from_qutf8( buf, ctx );
  #else
    // Old style
    msg = kk_string_alloc_from_qutf8( strerror(err), ctx );
  #endif
  return kk_std_core__new_Error( kk_std_core__new_Exception( msg, kk_std_core__new_ExnSystem(kk_reuse_null, kk_integer_from_int(err,ctx), ctx), ctx), ctx );  
}


kk_unit_t kk_assert_fail( kk_string_t msg, kk_context_t* ctx ) {
  kk_fatal_error(EINVAL, "assertion failed: %s\n", kk_string_cbuf_borrow(msg,NULL));
  kk_string_drop(msg,ctx);
  return kk_Unit;
}
kk_define_string_literal(, kk_std_core__tag_ExnError, 17, "std/core/ExnError")
kk_define_string_literal(, kk_std_core__tag_ExnAssert, 18, "std/core/ExnAssert")
kk_define_string_literal(, kk_std_core__tag_ExnTodo, 16, "std/core/ExnTodo")
kk_define_string_literal(, kk_std_core__tag_ExnRange, 17, "std/core/ExnRange")
kk_define_string_literal(, kk_std_core__tag_ExnPattern, 19, "std/core/ExnPattern")
kk_define_string_literal(, kk_std_core__tag_ExnSystem, 18, "std/core/ExnSystem")
kk_define_string_literal(, kk_std_core__tag_ExnInternal, 20, "std/core/ExnInternal")

kk_std_core__exception kk_std_core__copy(kk_std_core__exception _this, kk_std_core_types__optional message0, kk_std_core_types__optional info0, kk_context_t* _ctx) { /* (exception, message : optional<string>, info : optional<exception-info>) -> exception */ 
  kk_string_t _x23661;
  if (kk_std_core_types__is_Optional(message0)) {
    kk_box_t _box_x21897 = message0._cons.Optional.value;
    kk_string_t _message_1673 = kk_string_unbox(_box_x21897);
    _x23661 = _message_1673; /*string*/
    goto _match23662;
  }
  kk_string_t _x = _this.message;
  kk_string_dup(_x);
  _x23661 = _x; /*string*/
  _match23662: ;
  kk_std_core__exception_info _x23664;
  if (kk_std_core_types__is_Optional(info0)) {
    kk_box_t _box_x21898 = info0._cons.Optional.value;
    kk_std_core__exception_info _info_1679 = kk_std_core__exception_info_unbox(_box_x21898, NULL);
    kk_std_core__exception_drop(_this, _ctx);
    _x23664 = _info_1679; /*exception-info*/
    goto _match23665;
  }
  kk_std_core__exception_info _x0 = _this.info;
  kk_std_core__exception_info_dup(_x0);
  kk_std_core__exception_drop(_this, _ctx);
  _x23664 = _x0; /*exception-info*/
  _match23665: ;
  return kk_std_core__new_Exception(_x23661, _x23664, _ctx);
}
 
// monadic lift

kk_std_core__delayed kk_std_core__mlift21167_op(kk_ref_t _c_0, kk_context_t* _ctx) { /* forall<e,a> (ref<global,either<() -> e a,a>>) -> delayed<e,a> */ 
  return kk_std_core__new_Delay(_c_0, _ctx);
}


// lift anonymous function
struct kk_std_core__copy_fun23668__t_1 {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core__copy_fun23668_1(kk_function_t _fself, kk_box_t _b_21900, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_copy_fun23668_1(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core__copy_fun23668_1, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_core__copy_fun23668_1(kk_function_t _fself, kk_box_t _b_21900, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core__delayed _x23669;
  kk_ref_t _x23670 = kk_ref_unbox(_b_21900, _ctx); /*ref<global,either<() -> 1724 1725,1725>>*/
  _x23669 = kk_std_core__mlift21167_op(_x23670, _ctx); /*delayed<1724,1725>*/
  return kk_std_core__delayed_box(_x23669, _ctx);
}

kk_std_core__delayed kk_std_core__copy_1(kk_std_core__delayed _this, kk_std_core_types__optional dref0, kk_context_t* _ctx) { /* forall<e,a> (delayed<e,a>, dref : optional<ref<global,either<() -> e a,a>>>) -> delayed<e,a> */ 
  if (kk_yielding(kk_context())) {
    kk_std_core__delayed_drop(_this, _ctx);
    kk_std_core_types__optional_drop(dref0, _ctx);
    kk_box_t _x23667 = kk_std_core_hnd_yield_extend(kk_std_core__new_copy_fun23668_1(_ctx), _ctx); /*3991*/
    return kk_std_core__delayed_unbox(_x23667, _ctx);
  }
  kk_ref_t _x23671;
  if (kk_std_core_types__is_Optional(dref0)) {
    kk_box_t _box_x21901 = dref0._cons.Optional.value;
    kk_ref_t _dref_1712 = kk_ref_unbox(_box_x21901, NULL);
    kk_std_core__delayed_drop(_this, _ctx);
    _x23671 = _dref_1712; /*ref<global,either<() -> 1724 1725,1725>>*/
    goto _match23672;
  }
  kk_ref_t _x = _this.dref;
  _x23671 = _x; /*ref<global,either<() -> 1724 1725,1725>>*/
  _match23672: ;
  return kk_std_core__new_Delay(_x23671, _ctx);
}

kk_std_core__sslice kk_std_core__copy_2(kk_std_core__sslice _this, kk_std_core_types__optional str0, kk_std_core_types__optional start0, kk_std_core_types__optional len0, kk_context_t* _ctx) { /* (sslice, str : optional<string>, start : optional<size_t>, len : optional<size_t>) -> sslice */ 
  kk_string_t _x23675;
  if (kk_std_core_types__is_Optional(str0)) {
    kk_box_t _box_x21904 = str0._cons.Optional.value;
    kk_string_t _str_1813 = kk_string_unbox(_box_x21904);
    _x23675 = _str_1813; /*string*/
    goto _match23676;
  }
  kk_string_t _x = _this.str;
  kk_string_dup(_x);
  _x23675 = _x; /*string*/
  _match23676: ;
  size_t _x23678;
  if (kk_std_core_types__is_Optional(start0)) {
    kk_box_t _box_x21905 = start0._cons.Optional.value;
    size_t _start_1819 = kk_size_unbox(_box_x21905, NULL);
    _x23678 = _start_1819; /*size_t*/
    goto _match23679;
  }
  size_t _x0 = _this.start;
  _x23678 = _x0; /*size_t*/
  _match23679: ;
  size_t _x23681;
  if (kk_std_core_types__is_Optional(len0)) {
    kk_box_t _box_x21906 = len0._cons.Optional.value;
    size_t _len_1825 = kk_size_unbox(_box_x21906, NULL);
    kk_std_core__sslice_drop(_this, _ctx);
    _x23681 = _len_1825; /*size_t*/
    goto _match23682;
  }
  size_t _x1 = _this.len;
  kk_std_core__sslice_drop(_this, _ctx);
  _x23681 = _x1; /*size_t*/
  _match23682: ;
  return kk_std_core__new_Sslice(_x23675, _x23678, _x23681, _ctx);
}

kk_std_core__stream kk_std_core__copy_3(kk_std_core__stream _this, kk_std_core_types__optional head0, kk_std_core_types__optional tail0, kk_context_t* _ctx) { /* forall<a> (stream<a>, head : optional<a>, tail : optional<stream<a>>) -> stream<a> */ 
  kk_box_t _x23686;
  if (kk_std_core_types__is_Optional(head0)) {
    kk_box_t _head_1875 = head0._cons.Optional.value;
    _x23686 = _head_1875; /*1892*/
  }
  else {
    struct kk_std_core_Next* _con23687 = kk_std_core__as_Next(_this);
    kk_box_t _x = _con23687->head;
    kk_box_dup(_x);
    _x23686 = _x; /*1892*/
  }
  kk_std_core__stream _x23688;
  if (kk_std_core_types__is_Optional(tail0)) {
    kk_box_t _box_x21907 = tail0._cons.Optional.value;
    kk_std_core__stream _tail_1882 = kk_std_core__stream_unbox(_box_x21907, NULL);
    kk_std_core__stream_drop(_this, _ctx);
    _x23688 = _tail_1882; /*stream<1892>*/
    goto _match23689;
  }
  struct kk_std_core_Next* _con23691 = kk_std_core__as_Next(_this);
  kk_box_t _pat01 = _con23691->head;
  kk_std_core__stream _x0 = _con23691->tail;
  if (kk_std_core__stream_is_unique(_this)) {
    kk_box_drop(_pat01, _ctx);
    kk_std_core__stream_free(_this);
  }
  else {
    kk_std_core__stream_dup(_x0);
    kk_std_core__stream_decref(_this, _ctx);
  }
  _x23688 = _x0; /*stream<1892>*/
  _match23689: ;
  return kk_std_core__new_Next(kk_reuse_null, _x23686, _x23688, _ctx);
}
 
// runtime tag for the `:exn` effect

kk_std_core_hnd__htag kk_std_core__tag_exn;
 
// handler for the `:exn` effect

kk_box_t kk_std_core__handle_exn(int32_t cfc, kk_std_core__hnd_exn hnd, kk_function_t ret, kk_function_t action, kk_context_t* _ctx) { /* forall<a,e,b> (cfc : int32, hnd : .hnd-exn<e,b>, ret : (res : a) -> e b, action : () -> <exn|e> a) -> e b */ 
  kk_std_core_hnd__htag _x23695 = kk_std_core_hnd__htag_dup(kk_std_core__tag_exn); /*std/core/hnd/htag<.hnd-exn>*/
  return kk_std_core_hnd__hhandle(_x23695, cfc, kk_std_core__hnd_exn_box(hnd, _ctx), ret, action, _ctx);
}
 
// Unsafe: transform any type to a `null` type; used internally by the compiler.

kk_std_core__null kk_std_core__null_any(kk_box_t x, kk_context_t* _ctx) { /* forall<a> (x : a) -> null<a> */ 
  return ((x).box == kk_box_null.box ? kk_datatype_from_ptr(NULL) : kk_datatype_unbox(x));
}

kk_ref_t kk_std_core_redirect;
 
// Print a string to the console, including a final newline character.

kk_unit_t kk_std_core_xprintsln(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> console () */ 
  kk_println(s,kk_context()); return kk_Unit;
}

kk_integer_t kk_std_core_string_compare(kk_string_t x, kk_string_t y, kk_context_t* _ctx) { /* (x : string, y : string) -> int */ 
  return kk_string_cmp_int(x,y,kk_context());
}
 
// Convert an integer to an `:int32`. The number is _clamped_ to the maximal or minimum `:int32`
// value if it is outside the range of an `:int32`.

int32_t kk_std_core_int32(kk_integer_t _arg1, kk_context_t* _ctx) { /* (int) -> int32 */ 
  return kk_integer_clamp32(_arg1,kk_context());
}
 
// Convert an integer to an `:size_t`. The number is _clamped_ to the maximal or minimum `:size_t`
// value if it is outside the range of an `:size_t`.

size_t kk_std_core_size__t(kk_integer_t i, kk_context_t* _ctx) { /* (i : int) -> size_t */ 
  return kk_integer_clamp_size_t(i,kk_context());
}
 
// Convert a character to a string

kk_string_t kk_std_core_string(kk_char_t c, kk_context_t* _ctx) { /* (c : char) -> string */ 
  return kk_string_from_char(c,kk_context());
}
 
// Convert a vector of characters to a string.

kk_string_t kk_std_core_string_1(kk_vector_t _arg1, kk_context_t* _ctx) { /* (vector<char>) -> string */ 
  return kk_string_from_chars(_arg1,kk_context());
}
 
// Convert a list of characters to a string

kk_string_t kk_std_core_string_2(kk_std_core__list cs, kk_context_t* _ctx) { /* (cs : list<char>) -> total string */ 
  return kk_string_from_list(cs,kk_context());
}
 
// O(n). Copy the `slice` argument into a fresh string.
// Takes O(1) time if the slice covers the entire string.

kk_string_t kk_std_core_string_3(kk_std_core__sslice slice0, kk_context_t* _ctx) { /* (slice : sslice) -> string */ 
  return kk_slice_to_string(slice0,kk_context());
}
 
// Convert a vector to a list with an optional tail.

kk_std_core__list kk_std_core_vlist(kk_vector_t v, kk_std_core_types__optional tail0, kk_context_t* _ctx) { /* forall<a> (v : vector<a>, tail : optional<list<a>>) -> list<a> */ 
  kk_std_core__list _x23698;
  if (kk_std_core_types__is_Optional(tail0)) {
    kk_box_t _box_x21921 = tail0._cons.Optional.value;
    kk_std_core__list _tail_2144 = kk_std_core__list_unbox(_box_x21921, NULL);
    _x23698 = _tail_2144; /*list<2154>*/
    goto _match23699;
  }
  _x23698 = kk_std_core__new_Nil(_ctx); /*list<2154>*/
  _match23699: ;
  return kk_vector_to_list(v,_x23698,kk_context());
}

kk_string_t kk_std_core_int_show_hex(kk_integer_t i, bool use_capitals, kk_context_t* _ctx) { /* (i : int, use-capitals : bool) -> string */ 
  return kk_integer_to_hex_string(i,use_capitals,kk_context());
}

kk_string_t kk_std_core_repeatz(kk_string_t s, size_t n, kk_context_t* _ctx) { /* (s : string, n : size_t) -> string */ 
  return kk_string_repeat(s,n,kk_context());
}

kk_string_t kk_std_core_show_expx(double d, int32_t prec, kk_context_t* _ctx) { /* (d : double, prec : int32) -> string */ 
  return kk_double_show_exp(d,prec,kk_context());
}

kk_string_t kk_std_core_show_fixedx(double d, int32_t prec, kk_context_t* _ctx) { /* (d : double, prec : int32) -> string */ 
  return kk_double_show_fixed(d,prec,kk_context());
}
 
// Print a string to the console

kk_unit_t kk_std_core_xprints(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> console () */ 
  kk_print(s,kk_context()); return kk_Unit;
}
 
// Raise an integer `i` to the power of `exp`.

kk_integer_t kk_std_core_pow(kk_integer_t i, kk_integer_t exp, kk_context_t* _ctx) { /* (i : int, exp : int) -> int */ 
  return kk_integer_pow(i,exp,kk_context());
}
 
// O(`count`). Advance the start position of a string slice by `count` characters
// up to the end of the string.
// A negative `count` advances the start position backwards upto the first position
// in a string.
// Maintains the character count of the original slice upto the end of the string.
// For example:
//
// * `"abc".first.advance(1).string == "b"`,
// * `"abc".first.advance(3).string == ""`,
// * `"abc".last.advance(-1).string == "b"`.
//

kk_std_core__sslice kk_std_core_advance(kk_std_core__sslice slice0, kk_integer_t count, kk_context_t* _ctx) { /* (slice : sslice, count : int) -> sslice */ 
  return kk_slice_advance(slice0,count,kk_context());
}

kk_unit_t kk_std_core_unsafe_assert_fail(kk_string_t msg, kk_context_t* _ctx) { /* (msg : string) -> () */ 
  kk_assert_fail(msg,kk_context()); return kk_Unit;
}
 
// O(`count`). Extend a string slice by `count` characters up to the end of the string.
// A negative `count` shrinks the slice up to the empty slice.
// For example:
//
// * `"abc".first.extend(1).string == "ab"`
// * `"abc".last.extend(-1).string == ""`
//

kk_std_core__sslice kk_std_core_extend(kk_std_core__sslice slice0, kk_integer_t count, kk_context_t* _ctx) { /* (slice : sslice, count : int) -> sslice */ 
  return kk_slice_extend(slice0,count,kk_context());
}

kk_std_core__sslice kk_std_core_first1(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> sslice */ 
  return kk_slice_first(s,kk_context());
}
 
// Convert a string to upper-case

kk_string_t kk_std_core_to_upper(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> string */ 
  return kk_string_to_upper(s,kk_context());
}

kk_integer_t kk_std_core_cdiv_exp10(kk_integer_t i, kk_integer_t n, kk_context_t* _ctx) { /* (i : int, n : int) -> int */ 
  return kk_integer_cdiv_pow10(i,n,kk_context());
}

kk_integer_t kk_std_core_mul_exp10(kk_integer_t i, kk_integer_t n, kk_context_t* _ctx) { /* (i : int, n : int) -> int */ 
  return kk_integer_mul_pow10(i,n,kk_context());
}
 
// Return the common prefix of two strings (upto `upto` characters (default is minimum length of the two strings))

kk_std_core__sslice kk_std_core_common_prefix(kk_string_t s, kk_string_t t, kk_std_core_types__optional upto, kk_context_t* _ctx) { /* (s : string, t : string, upto : optional<int>) -> sslice */ 
  kk_integer_t _x23701;
  if (kk_std_core_types__is_Optional(upto)) {
    kk_box_t _box_x21922 = upto._cons.Optional.value;
    kk_integer_t _upto_2243 = kk_integer_unbox(_box_x21922);
    _x23701 = _upto_2243; /*int*/
    goto _match23702;
  }
  _x23701 = kk_integer_from_small(-1); /*int*/
  _match23702: ;
  return kk_slice_common_prefix(s,t,_x23701,kk_context());
}
 
// lift

kk_std_core__list kk_std_core__ctail_lift21045_concat(kk_std_core__list ys, kk_std_core__list zss, kk_std_core_types__ctail _acc, kk_context_t* _ctx) { /* forall<a> (ys : list<a>, zss : list<list<a>>, ctail<list<a>>) -> list<a> */ 
  kk__tailcall: ;
  if (kk_std_core__is_Cons(ys)) {
    struct kk_std_core_Cons* _con23704 = kk_std_core__as_Cons(ys);
    kk_box_t y = _con23704->head;
    kk_std_core__list yy = _con23704->tail;
    kk_reuse_t _ru_23332 = kk_reuse_null; /*reuse*/;
    if (kk_std_core__list_is_unique(ys)) {
      _ru_23332 = (kk_std_core__list_reuse(ys));
    }
    else {
      kk_box_dup(y);
      kk_std_core__list_dup(yy);
      kk_std_core__list_decref(ys, _ctx);
      _ru_23332 = kk_reuse_null;
    }
    kk_std_core__list _ctail_21107 = kk_std_core__list_hole(); /*list<2291>*/;
    kk_std_core__list _ctail_21108;
    bool _x23705 = _ru_23332!=NULL; /*bool*/
    if (_x23705) {
      struct kk_std_core_Cons* _con23706 = (struct kk_std_core_Cons*)_ru_23332;
      _con23706->tail = _ctail_21107;
      _ctail_21108 = kk_std_core__base_Cons(_con23706); /*list<2291>*/
    }
    else {
      _ctail_21108 = kk_std_core__new_Cons(kk_reuse_null, y, _ctail_21107, _ctx); /*list<2291>*/
    }
    { // tailcall
      kk_std_core_types__ctail _x23707;
      kk_box_t* field_21247 = (kk_box_t*)((&kk_std_core__as_Cons(_ctail_21108)->tail)); /*cfield<list<2291>>*/;
      if (kk_std_core_types__is_CTail(_acc)) {
        kk_box_t _box_x21929 = _acc._cons.CTail._field1;
        kk_box_t* last0 = _acc._cons.CTail._field2;
        kk_std_core__list head0 = kk_std_core__list_unbox(_box_x21929, NULL);
        kk_unit_t __ = kk_Unit;
        *(last0) = kk_std_core__list_box(_ctail_21108, _ctx);
        _x23707 = kk_std_core_types__new_CTail(kk_std_core__list_box(head0, _ctx), field_21247, _ctx); /*ctail<58>*/
        goto _match23708;
      }
      _x23707 = kk_std_core_types__new_CTail(kk_std_core__list_box(_ctail_21108, _ctx), field_21247, _ctx); /*ctail<58>*/
      _match23708: ;
      ys = yy;
      _acc = _x23707;
      goto kk__tailcall;
    }
  }
  if (kk_std_core__is_Cons(zss)) {
    struct kk_std_core_Cons* _con23710 = kk_std_core__as_Cons(zss);
    kk_box_t _box_x21938 = _con23710->head;
    kk_std_core__list zzs = _con23710->tail;
    kk_std_core__list zs = kk_std_core__list_unbox(_box_x21938, NULL);
    if (kk_std_core__list_is_unique(zss)) {
      kk_std_core__list_free(zss);
    }
    else {
      kk_std_core__list_dup(zs);
      kk_std_core__list_dup(zzs);
      kk_std_core__list_decref(zss, _ctx);
    }
    { // tailcall
      ys = zs;
      zss = zzs;
      goto kk__tailcall;
    }
  }
  if (kk_std_core_types__is_CTail(_acc)) {
    kk_box_t _box_x21939 = _acc._cons.CTail._field1;
    kk_box_t* last00 = _acc._cons.CTail._field2;
    kk_std_core__list head00 = kk_std_core__list_unbox(_box_x21939, NULL);
    kk_unit_t __0 = kk_Unit;
    *(last00) = kk_std_core__list_box(kk_std_core__new_Nil(_ctx), _ctx);
    return head00;
  }
  return kk_std_core__new_Nil(_ctx);
}
 
// lift

kk_std_core__list kk_std_core__lift21045_concat(kk_std_core__list ys0, kk_std_core__list zss0, kk_context_t* _ctx) { /* forall<a> (ys : list<a>, zss : list<list<a>>) -> list<a> */ 
  return kk_std_core__ctail_lift21045_concat(ys0, zss0, kk_std_core_types__new_CTailNil(_ctx), _ctx);
}
extern kk_box_t kk_std_core_const_fun23713_1(kk_function_t _fself, kk_box_t ___wildcard__124__7, kk_context_t* _ctx) {
  struct kk_std_core_const_fun23713__t_1* _self = kk_function_as(struct kk_std_core_const_fun23713__t_1*, _fself);
  kk_box_t default0 = _self->default0; /* 2319 */
  kk_drop_match(_self, {kk_box_dup(default0);}, {}, _ctx)
  kk_box_drop(___wildcard__124__7, _ctx);
  return default0;
}
 
// If the slice is not empty,
// return the first character, and a new slice that is advanced by 1.

kk_std_core_types__maybe kk_std_core_next(kk_std_core__sslice slice0, kk_context_t* _ctx) { /* (slice : sslice) -> maybe<(char, sslice)> */ 
  return kk_slice_next(slice0,kk_context());
}
 
// Return the number of decimal digits of `i`. Return `0` when `i==0`.

kk_integer_t kk_std_core_count_digits(kk_integer_t i, kk_context_t* _ctx) { /* (i : int) -> int */ 
  return kk_integer_count_digits(i,kk_context());
}
 
// Transform an `:error` type to an `:either` value.

kk_std_core_types__either kk_std_core_either(kk_std_core__error t, kk_context_t* _ctx) { /* forall<a> (t : error<a>) -> either<exception,a> */ 
  if (kk_std_core__is_Error(t)) {
    kk_std_core__exception exn0 = t._cons.Error.exception;
    kk_std_core__exception_dup(exn0);
    kk_std_core__error_drop(t, _ctx);
    return kk_std_core_types__new_Left(kk_std_core__exception_box(exn0, _ctx), _ctx);
  }
  kk_box_t x = t._cons.Ok.result;
  return kk_std_core_types__new_Right(x, _ctx);
}

bool kk_std_core_xends_with(kk_string_t s, kk_string_t post, kk_context_t* _ctx) { /* (s : string, post : string) -> bool */ 
  return kk_string_ends_with(s,post,kk_context());
}
 
// monadic lift

kk_std_core__list kk_std_core__mlift21168_op(kk_std_core_types__ctail _acc, kk_function_t f, kk_std_core__list zz, kk_std_core__list ys1_21065, kk_context_t* _ctx) { /* forall<a,b,e> (ctail<list<b>>, f : (a) -> e list<b>, zz : list<a>, ys1.21065 : list<b>) -> e list<b> */ 
  return kk_std_core__ctail_lift21046_flatmap(f, ys1_21065, zz, _acc, _ctx);
}
 
// monadic lift

kk_std_core__list kk_std_core__mlift21169_op(kk_function_t _accm, kk_function_t f0, kk_std_core__list zz0, kk_std_core__list ys1_210650, kk_context_t* _ctx) { /* forall<a,b,e> ((list<b>) -> list<b>, f : (a) -> e list<b>, zz : list<a>, ys1.21065 : list<b>) -> e list<b> */ 
  return kk_std_core__ctailm_lift21046_flatmap(f0, ys1_210650, zz0, _accm, _ctx);
}
 
// lift


// lift anonymous function
struct kk_std_core__ctail_lift21046_flatmap_fun23723__t {
  struct kk_function_s _base;
  kk_function_t f1;
  kk_std_core__list zz1;
  kk_std_core_types__ctail _acc0;
};
static kk_box_t kk_std_core__ctail_lift21046_flatmap_fun23723(kk_function_t _fself, kk_box_t _b_21966, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_ctail_lift21046_flatmap_fun23723(kk_function_t f1, kk_std_core__list zz1, kk_std_core_types__ctail _acc0, kk_context_t* _ctx) {
  struct kk_std_core__ctail_lift21046_flatmap_fun23723__t* _self = kk_function_alloc_as(struct kk_std_core__ctail_lift21046_flatmap_fun23723__t, 5, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__ctail_lift21046_flatmap_fun23723, kk_context());
  _self->f1 = f1;
  _self->zz1 = zz1;
  _self->_acc0 = _acc0;
  return &_self->_base;
}

static kk_box_t kk_std_core__ctail_lift21046_flatmap_fun23723(kk_function_t _fself, kk_box_t _b_21966, kk_context_t* _ctx) {
  struct kk_std_core__ctail_lift21046_flatmap_fun23723__t* _self = kk_function_as(struct kk_std_core__ctail_lift21046_flatmap_fun23723__t*, _fself);
  kk_function_t f1 = _self->f1; /* (2421) -> 2423 list<2422> */
  kk_std_core__list zz1 = _self->zz1; /* list<2421> */
  kk_std_core_types__ctail _acc0 = _self->_acc0; /* ctail<list<2422>> */
  kk_drop_match(_self, {kk_function_dup(f1);kk_std_core__list_dup(zz1);kk_std_core_types__ctail_dup(_acc0);}, {}, _ctx)
  kk_std_core__list _x23724;
  kk_std_core__list _x23725 = kk_std_core__list_unbox(_b_21966, _ctx); /*list<2422>*/
  _x23724 = kk_std_core__mlift21168_op(_acc0, f1, zz1, _x23725, _ctx); /*list<2422>*/
  return kk_std_core__list_box(_x23724, _ctx);
}

kk_std_core__list kk_std_core__ctail_lift21046_flatmap(kk_function_t f1, kk_std_core__list ys, kk_std_core__list zs, kk_std_core_types__ctail _acc0, kk_context_t* _ctx) { /* forall<a,b,e> (f : (a) -> e list<b>, ys : list<b>, zs : list<a>, ctail<list<b>>) -> e list<b> */ 
  kk__tailcall: ;
  if (kk_std_core__is_Cons(ys)) {
    struct kk_std_core_Cons* _con23714 = kk_std_core__as_Cons(ys);
    kk_box_t y = _con23714->head;
    kk_std_core__list yy = _con23714->tail;
    kk_reuse_t _ru_23334 = kk_reuse_null; /*reuse*/;
    if (kk_std_core__list_is_unique(ys)) {
      _ru_23334 = (kk_std_core__list_reuse(ys));
    }
    else {
      kk_box_dup(y);
      kk_std_core__list_dup(yy);
      kk_std_core__list_decref(ys, _ctx);
      _ru_23334 = kk_reuse_null;
    }
    kk_std_core__list _ctail_21109 = kk_std_core__list_hole(); /*list<2422>*/;
    kk_std_core__list _ctail_21110;
    bool _x23715 = _ru_23334!=NULL; /*bool*/
    if (_x23715) {
      struct kk_std_core_Cons* _con23716 = (struct kk_std_core_Cons*)_ru_23334;
      _con23716->tail = _ctail_21109;
      _ctail_21110 = kk_std_core__base_Cons(_con23716); /*list<2422>*/
    }
    else {
      _ctail_21110 = kk_std_core__new_Cons(kk_reuse_null, y, _ctail_21109, _ctx); /*list<2422>*/
    }
    { // tailcall
      kk_std_core_types__ctail _x23717;
      kk_box_t* field_21252 = (kk_box_t*)((&kk_std_core__as_Cons(_ctail_21110)->tail)); /*cfield<list<2422>>*/;
      if (kk_std_core_types__is_CTail(_acc0)) {
        kk_box_t _box_x21956 = _acc0._cons.CTail._field1;
        kk_box_t* last0 = _acc0._cons.CTail._field2;
        kk_std_core__list head0 = kk_std_core__list_unbox(_box_x21956, NULL);
        kk_unit_t __ = kk_Unit;
        *(last0) = kk_std_core__list_box(_ctail_21110, _ctx);
        _x23717 = kk_std_core_types__new_CTail(kk_std_core__list_box(head0, _ctx), field_21252, _ctx); /*ctail<58>*/
        goto _match23718;
      }
      _x23717 = kk_std_core_types__new_CTail(kk_std_core__list_box(_ctail_21110, _ctx), field_21252, _ctx); /*ctail<58>*/
      _match23718: ;
      ys = yy;
      _acc0 = _x23717;
      goto kk__tailcall;
    }
  }
  if (kk_std_core__is_Cons(zs)) {
    struct kk_std_core_Cons* _con23720 = kk_std_core__as_Cons(zs);
    kk_box_t z = _con23720->head;
    kk_std_core__list zz1 = _con23720->tail;
    if (kk_std_core__list_is_unique(zs)) {
      kk_std_core__list_free(zs);
    }
    else {
      kk_box_dup(z);
      kk_std_core__list_dup(zz1);
      kk_std_core__list_decref(zs, _ctx);
    }
    kk_std_core__list x_21253;
    kk_function_t _x23721 = kk_function_dup(f1); /*(2421) -> 2423 list<2422>*/
    x_21253 = kk_function_call(kk_std_core__list, (kk_function_t, kk_box_t, kk_context_t*), _x23721, (_x23721, z, _ctx)); /*list<2422>*/
    if (kk_yielding(kk_context())) {
      kk_std_core__list_drop(x_21253, _ctx);
      kk_box_t _x23722 = kk_std_core_hnd_yield_extend(kk_std_core__new_ctail_lift21046_flatmap_fun23723(f1, zz1, _acc0, _ctx), _ctx); /*3991*/
      return kk_std_core__list_unbox(_x23722, _ctx);
    }
    { // tailcall
      ys = x_21253;
      zs = zz1;
      goto kk__tailcall;
    }
  }
  kk_function_drop(f1, _ctx);
  if (kk_std_core_types__is_CTail(_acc0)) {
    kk_box_t _box_x21967 = _acc0._cons.CTail._field1;
    kk_box_t* last00 = _acc0._cons.CTail._field2;
    kk_std_core__list head00 = kk_std_core__list_unbox(_box_x21967, NULL);
    kk_unit_t __0 = kk_Unit;
    *(last00) = kk_std_core__list_box(kk_std_core__new_Nil(_ctx), _ctx);
    return head00;
  }
  return kk_std_core__new_Nil(_ctx);
}
 
// lift


// lift anonymous function
struct kk_std_core__ctailm_lift21046_flatmap_fun23729__t {
  struct kk_function_s _base;
  kk_function_t _accm0;
  kk_box_t y0;
};
static kk_std_core__list kk_std_core__ctailm_lift21046_flatmap_fun23729(kk_function_t _fself, kk_std_core__list _ctail_21112, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_ctailm_lift21046_flatmap_fun23729(kk_function_t _accm0, kk_box_t y0, kk_context_t* _ctx) {
  struct kk_std_core__ctailm_lift21046_flatmap_fun23729__t* _self = kk_function_alloc_as(struct kk_std_core__ctailm_lift21046_flatmap_fun23729__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__ctailm_lift21046_flatmap_fun23729, kk_context());
  _self->_accm0 = _accm0;
  _self->y0 = y0;
  return &_self->_base;
}

static kk_std_core__list kk_std_core__ctailm_lift21046_flatmap_fun23729(kk_function_t _fself, kk_std_core__list _ctail_21112, kk_context_t* _ctx) {
  struct kk_std_core__ctailm_lift21046_flatmap_fun23729__t* _self = kk_function_as(struct kk_std_core__ctailm_lift21046_flatmap_fun23729__t*, _fself);
  kk_function_t _accm0 = _self->_accm0; /* (list<2422>) -> list<2422> */
  kk_box_t y0 = _self->y0; /* 2422 */
  kk_drop_match(_self, {kk_function_dup(_accm0);kk_box_dup(y0);}, {}, _ctx)
  kk_std_core__list _x23730 = kk_std_core__new_Cons(kk_reuse_null, y0, _ctail_21112, _ctx); /*list<61>*/
  return kk_function_call(kk_std_core__list, (kk_function_t, kk_std_core__list, kk_context_t*), _accm0, (_accm0, _x23730, _ctx));
}


// lift anonymous function
struct kk_std_core__ctailm_lift21046_flatmap_fun23734__t {
  struct kk_function_s _base;
  kk_function_t _accm0;
  kk_function_t f2;
  kk_std_core__list zz2;
};
static kk_box_t kk_std_core__ctailm_lift21046_flatmap_fun23734(kk_function_t _fself, kk_box_t _b_21979, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_ctailm_lift21046_flatmap_fun23734(kk_function_t _accm0, kk_function_t f2, kk_std_core__list zz2, kk_context_t* _ctx) {
  struct kk_std_core__ctailm_lift21046_flatmap_fun23734__t* _self = kk_function_alloc_as(struct kk_std_core__ctailm_lift21046_flatmap_fun23734__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__ctailm_lift21046_flatmap_fun23734, kk_context());
  _self->_accm0 = _accm0;
  _self->f2 = f2;
  _self->zz2 = zz2;
  return &_self->_base;
}

static kk_box_t kk_std_core__ctailm_lift21046_flatmap_fun23734(kk_function_t _fself, kk_box_t _b_21979, kk_context_t* _ctx) {
  struct kk_std_core__ctailm_lift21046_flatmap_fun23734__t* _self = kk_function_as(struct kk_std_core__ctailm_lift21046_flatmap_fun23734__t*, _fself);
  kk_function_t _accm0 = _self->_accm0; /* (list<2422>) -> list<2422> */
  kk_function_t f2 = _self->f2; /* (2421) -> 2423 list<2422> */
  kk_std_core__list zz2 = _self->zz2; /* list<2421> */
  kk_drop_match(_self, {kk_function_dup(_accm0);kk_function_dup(f2);kk_std_core__list_dup(zz2);}, {}, _ctx)
  kk_std_core__list _x23735;
  kk_std_core__list _x23736 = kk_std_core__list_unbox(_b_21979, _ctx); /*list<2422>*/
  _x23735 = kk_std_core__mlift21169_op(_accm0, f2, zz2, _x23736, _ctx); /*list<2422>*/
  return kk_std_core__list_box(_x23735, _ctx);
}

kk_std_core__list kk_std_core__ctailm_lift21046_flatmap(kk_function_t f2, kk_std_core__list ys0, kk_std_core__list zs0, kk_function_t _accm0, kk_context_t* _ctx) { /* forall<a,b,e> (f : (a) -> e list<b>, ys : list<b>, zs : list<a>, (list<b>) -> list<b>) -> e list<b> */ 
  kk__tailcall: ;
  if (kk_std_core__is_Cons(ys0)) {
    struct kk_std_core_Cons* _con23727 = kk_std_core__as_Cons(ys0);
    kk_box_t y0 = _con23727->head;
    kk_std_core__list yy0 = _con23727->tail;
    if (kk_std_core__list_is_unique(ys0)) {
      kk_std_core__list_free(ys0);
    }
    else {
      kk_box_dup(y0);
      kk_std_core__list_dup(yy0);
      kk_std_core__list_decref(ys0, _ctx);
    }
    { // tailcall
      kk_function_t _x23728 = kk_std_core__new_ctailm_lift21046_flatmap_fun23729(_accm0, y0, _ctx); /*(list<2422>) -> list<2422>*/
      ys0 = yy0;
      _accm0 = _x23728;
      goto kk__tailcall;
    }
  }
  if (kk_std_core__is_Cons(zs0)) {
    struct kk_std_core_Cons* _con23731 = kk_std_core__as_Cons(zs0);
    kk_box_t z0 = _con23731->head;
    kk_std_core__list zz2 = _con23731->tail;
    if (kk_std_core__list_is_unique(zs0)) {
      kk_std_core__list_free(zs0);
    }
    else {
      kk_box_dup(z0);
      kk_std_core__list_dup(zz2);
      kk_std_core__list_decref(zs0, _ctx);
    }
    kk_std_core__list x_21259;
    kk_function_t _x23732 = kk_function_dup(f2); /*(2421) -> 2423 list<2422>*/
    x_21259 = kk_function_call(kk_std_core__list, (kk_function_t, kk_box_t, kk_context_t*), _x23732, (_x23732, z0, _ctx)); /*list<2422>*/
    if (kk_yielding(kk_context())) {
      kk_std_core__list_drop(x_21259, _ctx);
      kk_box_t _x23733 = kk_std_core_hnd_yield_extend(kk_std_core__new_ctailm_lift21046_flatmap_fun23734(_accm0, f2, zz2, _ctx), _ctx); /*3991*/
      return kk_std_core__list_unbox(_x23733, _ctx);
    }
    { // tailcall
      ys0 = x_21259;
      zs0 = zz2;
      goto kk__tailcall;
    }
  }
  kk_function_drop(f2, _ctx);
  return kk_function_call(kk_std_core__list, (kk_function_t, kk_std_core__list, kk_context_t*), _accm0, (_accm0, kk_std_core__new_Nil(_ctx), _ctx));
}
 
// lift


// lift anonymous function
struct kk_std_core__lift21046_flatmap_fun23737__t {
  struct kk_function_s _base;
};
static kk_std_core__list kk_std_core__lift21046_flatmap_fun23737(kk_function_t _fself, kk_std_core__list _ctail_21111, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_lift21046_flatmap_fun23737(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core__lift21046_flatmap_fun23737, _ctx)
  return kk_function_dup(_fself);
}

static kk_std_core__list kk_std_core__lift21046_flatmap_fun23737(kk_function_t _fself, kk_std_core__list _ctail_21111, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return _ctail_21111;
}

kk_std_core__list kk_std_core__lift21046_flatmap(kk_function_t f3, kk_std_core__list ys1, kk_std_core__list zs1, kk_context_t* _ctx) { /* forall<a,b,e> (f : (a) -> e list<b>, ys : list<b>, zs : list<a>) -> e list<b> */ 
  bool _match_23648 = kk_std_core_hnd__evv_is_affine(_ctx); /*bool*/;
  if (_match_23648) {
    return kk_std_core__ctail_lift21046_flatmap(f3, ys1, zs1, kk_std_core_types__new_CTailNil(_ctx), _ctx);
  }
  return kk_std_core__ctailm_lift21046_flatmap(f3, ys1, zs1, kk_std_core__new_lift21046_flatmap_fun23737(_ctx), _ctx);
}
 
// lift

kk_std_core__list kk_std_core__lift21047_reverse_append(kk_std_core__list acc, kk_std_core__list ys, kk_context_t* _ctx) { /* forall<a> (acc : list<a>, ys : list<a>) -> list<a> */ 
  kk__tailcall: ;
  if (kk_std_core__is_Cons(ys)) {
    struct kk_std_core_Cons* _con23738 = kk_std_core__as_Cons(ys);
    kk_box_t x = _con23738->head;
    kk_std_core__list xx = _con23738->tail;
    kk_reuse_t _ru_23338 = kk_reuse_null; /*reuse*/;
    if (kk_std_core__list_is_unique(ys)) {
      _ru_23338 = (kk_std_core__list_reuse(ys));
    }
    else {
      kk_box_dup(x);
      kk_std_core__list_dup(xx);
      kk_std_core__list_decref(ys, _ctx);
      _ru_23338 = kk_reuse_null;
    }
    { // tailcall
      kk_std_core__list _x23739;
      bool _x23740 = _ru_23338!=NULL; /*bool*/
      if (_x23740) {
        struct kk_std_core_Cons* _con23741 = (struct kk_std_core_Cons*)_ru_23338;
        _con23741->tail = acc;
        _x23739 = kk_std_core__base_Cons(_con23741); /*list<61>*/
      }
      else {
        _x23739 = kk_std_core__new_Cons(kk_reuse_null, x, acc, _ctx); /*list<61>*/
      }
      acc = _x23739;
      ys = xx;
      goto kk__tailcall;
    }
  }
  return acc;
}
 
// monadic lift

kk_box_t kk_std_core__mlift21170_force(kk_ref_t r, kk_box_t x0, kk_context_t* _ctx) { /* forall<a,e> (r : ref<global,either<() -> e a,a>>, x0 : a) -> <st<global>,div|e> a */ 
  kk_unit_t __ = kk_Unit;
  kk_std_core_types__either _b_21985_21983;
  kk_box_t _x23742 = kk_box_dup(x0); /*2610*/
  _b_21985_21983 = kk_std_core_types__new_Right(_x23742, _ctx); /*either<() -> 2611 2610,2610>*/
  kk_ref_set(r,(kk_std_core_types__either_box(_b_21985_21983, _ctx)),kk_context());
  return x0;
}
 
// Force a delayed value; the value is computed only on the first
// call to `force` and cached afterwards.


// lift anonymous function
struct kk_std_core_force_fun23746__t {
  struct kk_function_s _base;
  kk_std_core__delayed delayed;
};
static kk_box_t kk_std_core_force_fun23746(kk_function_t _fself, kk_box_t x00, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_force_fun23746(kk_std_core__delayed delayed, kk_context_t* _ctx) {
  struct kk_std_core_force_fun23746__t* _self = kk_function_alloc_as(struct kk_std_core_force_fun23746__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_force_fun23746, kk_context());
  _self->delayed = delayed;
  return &_self->_base;
}

static kk_box_t kk_std_core_force_fun23746(kk_function_t _fself, kk_box_t x00, kk_context_t* _ctx) {
  struct kk_std_core_force_fun23746__t* _self = kk_function_as(struct kk_std_core_force_fun23746__t*, _fself);
  kk_std_core__delayed delayed = _self->delayed; /* delayed<2611,2610> */
  kk_drop_match(_self, {kk_std_core__delayed_dup(delayed);}, {}, _ctx)
  kk_ref_t _x23747;
  kk_ref_t _x0 = delayed.dref;
  _x23747 = _x0; /*ref<global,either<() -> 2611 2610,2610>>*/
  return kk_std_core__mlift21170_force(_x23747, x00, _ctx);
}

kk_box_t kk_std_core_force(kk_std_core__delayed delayed, kk_context_t* _ctx) { /* forall<a,e> (delayed : delayed<e,a>) -> e a */ 
  kk_std_core_types__either _match_23646;
  kk_box_t _x23743;
  kk_ref_t _x23744;
  kk_ref_t _x = delayed.dref;
  kk_ref_dup(_x);
  _x23744 = _x; /*ref<global,either<() -> 2611 2610,2610>>*/
  _x23743 = kk_ref_get(_x23744,kk_context()); /*179*/
  _match_23646 = kk_std_core_types__either_unbox(_x23743, _ctx); /*either<() -> 2611 2610,2610>*/
  if (kk_std_core_types__is_Right(_match_23646)) {
    kk_box_t x = _match_23646._cons.Right.right;
    kk_std_core__delayed_drop(delayed, _ctx);
    return x;
  }
  kk_box_t _fun_unbox_x21988 = _match_23646._cons.Left.left;
  kk_box_t x0_21265;
  kk_function_t _x23745 = kk_function_unbox(_fun_unbox_x21988); /*() -> 2611 21989*/
  x0_21265 = kk_std_core_hnd__mask_builtin(_x23745, _ctx); /*2610*/
  kk_function_t next_21266 = kk_std_core_new_force_fun23746(delayed, _ctx); /*(2610) -> <st<global>,div|2611> 2610*/;
  if (kk_yielding(kk_context())) {
    kk_box_drop(x0_21265, _ctx);
    return kk_std_core_hnd_yield_extend(next_21266, _ctx);
  }
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), next_21266, (next_21266, x0_21265, _ctx));
}
 
// Generic show: shows the internal representation of an object as a string
// Note: this breaks parametricity so it should not be public

kk_string_t kk_std_core_gshow(kk_box_t _arg1, kk_context_t* _ctx) { /* forall<a> (a) -> string */ 
  return kk_show_any(_arg1,kk_context());
}
 
// Return the host environment: `dotnet`, `browser`, `webworker`, `node`, or `libc`.

kk_string_t kk_std_core_host(kk_context_t* _ctx) { /* () -> ndet string */ 
  return kk_get_host(kk_context());
}
 
// lift

kk_std_core__list kk_std_core__ctail_lift21048_intersperse(kk_std_core__list ys, kk_box_t s, kk_std_core_types__ctail _acc, kk_context_t* _ctx) { /* forall<a> (ys : list<a>, s : a, ctail<list<a>>) -> list<a> */ 
  kk__tailcall: ;
  if (kk_std_core__is_Cons(ys)) {
    struct kk_std_core_Cons* _con23748 = kk_std_core__as_Cons(ys);
    kk_box_t y = _con23748->head;
    kk_std_core__list yy = _con23748->tail;
    kk_reuse_t _ru_23339 = kk_reuse_null; /*reuse*/;
    if (kk_std_core__list_is_unique(ys)) {
      _ru_23339 = (kk_std_core__list_reuse(ys));
    }
    else {
      kk_box_dup(y);
      kk_std_core__list_dup(yy);
      kk_std_core__list_decref(ys, _ctx);
      _ru_23339 = kk_reuse_null;
    }
    kk_std_core__list _ctail_21113;
    kk_std_core__list _ru_23652 = kk_std_core__list_hole(); /*list<2637>*/;
    bool _x23749 = _ru_23339!=NULL; /*bool*/
    if (_x23749) {
      struct kk_std_core_Cons* _con23750 = (struct kk_std_core_Cons*)_ru_23339;
      _con23750->tail = _ru_23652;
      _ctail_21113 = kk_std_core__base_Cons(_con23750); /*list<2637>*/
    }
    else {
      _ctail_21113 = kk_std_core__new_Cons(kk_reuse_null, y, _ru_23652, _ctx); /*list<2637>*/
    }
    kk_std_core__list _ctail_21114;
    kk_box_t _x23751 = kk_box_dup(s); /*2637*/
    kk_std_core__list _x23752 = kk_std_core__list_dup(_ctail_21113); /*list<2637>*/
    _ctail_21114 = kk_std_core__new_Cons(kk_reuse_null, _x23751, _x23752, _ctx); /*list<2637>*/
    { // tailcall
      kk_std_core_types__ctail _x23753;
      kk_box_t* field_21269;
      kk_std_core__list_drop(_ctail_21113, _ctx);
      field_21269 = (kk_box_t*)((&kk_std_core__as_Cons(_ctail_21113)->tail)); /*cfield<list<2637>>*/
      if (kk_std_core_types__is_CTail(_acc)) {
        kk_box_t _box_x21997 = _acc._cons.CTail._field1;
        kk_box_t* last0 = _acc._cons.CTail._field2;
        kk_std_core__list head0 = kk_std_core__list_unbox(_box_x21997, NULL);
        kk_unit_t __ = kk_Unit;
        *(last0) = kk_std_core__list_box(_ctail_21114, _ctx);
        _x23753 = kk_std_core_types__new_CTail(kk_std_core__list_box(head0, _ctx), field_21269, _ctx); /*ctail<58>*/
        goto _match23754;
      }
      _x23753 = kk_std_core_types__new_CTail(kk_std_core__list_box(_ctail_21114, _ctx), field_21269, _ctx); /*ctail<58>*/
      _match23754: ;
      ys = yy;
      _acc = _x23753;
      goto kk__tailcall;
    }
  }
  kk_box_drop(s, _ctx);
  if (kk_std_core_types__is_CTail(_acc)) {
    kk_box_t _box_x22006 = _acc._cons.CTail._field1;
    kk_box_t* last00 = _acc._cons.CTail._field2;
    kk_std_core__list head00 = kk_std_core__list_unbox(_box_x22006, NULL);
    kk_unit_t __0 = kk_Unit;
    *(last00) = kk_std_core__list_box(kk_std_core__new_Nil(_ctx), _ctx);
    return head00;
  }
  return kk_std_core__new_Nil(_ctx);
}
 
// lift

kk_std_core__list kk_std_core__lift21048_intersperse(kk_std_core__list ys0, kk_box_t s0, kk_context_t* _ctx) { /* forall<a> (ys : list<a>, s : a) -> list<a> */ 
  return kk_std_core__ctail_lift21048_intersperse(ys0, s0, kk_std_core_types__new_CTailNil(_ctx), _ctx);
}
 
// Insert a separator `sep`  between all elements of a list `xs` .

kk_std_core__list kk_std_core_intersperse(kk_std_core__list xs, kk_box_t sep, kk_context_t* _ctx) { /* forall<a> (xs : list<a>, sep : a) -> list<a> */ 
  if (kk_std_core__is_Cons(xs)) {
    struct kk_std_core_Cons* _con23757 = kk_std_core__as_Cons(xs);
    kk_box_t x = _con23757->head;
    kk_std_core__list xx = _con23757->tail;
    kk_reuse_t _ru_23340 = kk_reuse_null; /*reuse*/;
    if (kk_std_core__list_is_unique(xs)) {
      _ru_23340 = (kk_std_core__list_reuse(xs));
    }
    else {
      kk_box_dup(x);
      kk_std_core__list_dup(xx);
      kk_std_core__list_decref(xs, _ctx);
      _ru_23340 = kk_reuse_null;
    }
    kk_std_core__list _ru_23653 = kk_std_core__lift21048_intersperse(xx, sep, _ctx); /*list<2637>*/;
    bool _x23758 = _ru_23340!=NULL; /*bool*/
    if (_x23758) {
      struct kk_std_core_Cons* _con23759 = (struct kk_std_core_Cons*)_ru_23340;
      _con23759->tail = _ru_23653;
      return kk_std_core__base_Cons(_con23759);
    }
    return kk_std_core__new_Cons(kk_reuse_null, x, _ru_23653, _ctx);
  }
  kk_box_drop(sep, _ctx);
  return kk_std_core__new_Nil(_ctx);
}
 
// Return the number of ending `0` digits of `i`. Return `0` when `i==0`.

kk_integer_t kk_std_core_is_exp10(kk_integer_t i, kk_context_t* _ctx) { /* (i : int) -> int */ 
  return kk_integer_ctz(i,kk_context());
}

kk_std_core__sslice kk_std_core_last1(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> sslice */ 
  return kk_slice_last(s,kk_context());
}
 
// Used by the compiler to wrap main console applications

kk_box_t kk_std_core_main_console(kk_function_t main, kk_context_t* _ctx) { /* forall<a,e> (main : () -> e a) -> e a */ 
  return kk_main_console(main,kk_context());
}
 
// monadic lift

kk_std_core__list kk_std_core__mlift21171_op(kk_std_core_types__ctail _acc, kk_function_t f, kk_std_core__list yy, kk_box_t _ctail_21115, kk_context_t* _ctx) { /* forall<a,b,e> (ctail<list<b>>, f : (value : a, rest : list<a>) -> e b, yy : list<a>, b) -> e list<b> */ 
  kk_std_core__list _ctail_21116 = kk_std_core__list_hole(); /*list<2738>*/;
  kk_std_core__list _ctail_21117 = kk_std_core__new_Cons(kk_reuse_null, _ctail_21115, _ctail_21116, _ctx); /*list<2738>*/;
  kk_std_core_types__ctail _x23761;
  kk_box_t* field_21274 = (kk_box_t*)((&kk_std_core__as_Cons(_ctail_21117)->tail)); /*cfield<list<2738>>*/;
  if (kk_std_core_types__is_CTail(_acc)) {
    kk_box_t _box_x22021 = _acc._cons.CTail._field1;
    kk_box_t* last0 = _acc._cons.CTail._field2;
    kk_std_core__list head0 = kk_std_core__list_unbox(_box_x22021, NULL);
    kk_unit_t __ = kk_Unit;
    *(last0) = kk_std_core__list_box(_ctail_21117, _ctx);
    _x23761 = kk_std_core_types__new_CTail(kk_std_core__list_box(head0, _ctx), field_21274, _ctx); /*ctail<58>*/
    goto _match23762;
  }
  _x23761 = kk_std_core_types__new_CTail(kk_std_core__list_box(_ctail_21117, _ctx), field_21274, _ctx); /*ctail<58>*/
  _match23762: ;
  return kk_std_core__ctail_lift21049_map_peek(f, yy, _x23761, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_core__mlift21172_op_fun23764__t {
  struct kk_function_s _base;
  kk_function_t _accm;
  kk_box_t _ctail_21120;
};
static kk_std_core__list kk_std_core__mlift21172_op_fun23764(kk_function_t _fself, kk_std_core__list _ctail_21119, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_mlift21172_op_fun23764(kk_function_t _accm, kk_box_t _ctail_21120, kk_context_t* _ctx) {
  struct kk_std_core__mlift21172_op_fun23764__t* _self = kk_function_alloc_as(struct kk_std_core__mlift21172_op_fun23764__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__mlift21172_op_fun23764, kk_context());
  _self->_accm = _accm;
  _self->_ctail_21120 = _ctail_21120;
  return &_self->_base;
}

static kk_std_core__list kk_std_core__mlift21172_op_fun23764(kk_function_t _fself, kk_std_core__list _ctail_21119, kk_context_t* _ctx) {
  struct kk_std_core__mlift21172_op_fun23764__t* _self = kk_function_as(struct kk_std_core__mlift21172_op_fun23764__t*, _fself);
  kk_function_t _accm = _self->_accm; /* (list<2738>) -> list<2738> */
  kk_box_t _ctail_21120 = _self->_ctail_21120; /* 2738 */
  kk_drop_match(_self, {kk_function_dup(_accm);kk_box_dup(_ctail_21120);}, {}, _ctx)
  kk_std_core__list _x23765 = kk_std_core__new_Cons(kk_reuse_null, _ctail_21120, _ctail_21119, _ctx); /*list<61>*/
  return kk_function_call(kk_std_core__list, (kk_function_t, kk_std_core__list, kk_context_t*), _accm, (_accm, _x23765, _ctx));
}

kk_std_core__list kk_std_core__mlift21172_op(kk_function_t _accm, kk_function_t f0, kk_std_core__list yy0, kk_box_t _ctail_21120, kk_context_t* _ctx) { /* forall<a,b,e> ((list<b>) -> list<b>, f : (value : a, rest : list<a>) -> e b, yy : list<a>, b) -> e list<b> */ 
  return kk_std_core__ctailm_lift21049_map_peek(f0, yy0, kk_std_core__new_mlift21172_op_fun23764(_accm, _ctail_21120, _ctx), _ctx);
}
 
// lift


// lift anonymous function
struct kk_std_core__ctail_lift21049_map_peek_fun23770__t {
  struct kk_function_s _base;
  kk_function_t f1;
  kk_std_core__list yy1;
  kk_std_core_types__ctail _acc0;
};
static kk_box_t kk_std_core__ctail_lift21049_map_peek_fun23770(kk_function_t _fself, kk_box_t _b_22035, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_ctail_lift21049_map_peek_fun23770(kk_function_t f1, kk_std_core__list yy1, kk_std_core_types__ctail _acc0, kk_context_t* _ctx) {
  struct kk_std_core__ctail_lift21049_map_peek_fun23770__t* _self = kk_function_alloc_as(struct kk_std_core__ctail_lift21049_map_peek_fun23770__t, 5, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__ctail_lift21049_map_peek_fun23770, kk_context());
  _self->f1 = f1;
  _self->yy1 = yy1;
  _self->_acc0 = _acc0;
  return &_self->_base;
}

static kk_box_t kk_std_core__ctail_lift21049_map_peek_fun23770(kk_function_t _fself, kk_box_t _b_22035, kk_context_t* _ctx) {
  struct kk_std_core__ctail_lift21049_map_peek_fun23770__t* _self = kk_function_as(struct kk_std_core__ctail_lift21049_map_peek_fun23770__t*, _fself);
  kk_function_t f1 = _self->f1; /* (value : 2737, rest : list<2737>) -> 2739 2738 */
  kk_std_core__list yy1 = _self->yy1; /* list<2737> */
  kk_std_core_types__ctail _acc0 = _self->_acc0; /* ctail<list<2738>> */
  kk_drop_match(_self, {kk_function_dup(f1);kk_std_core__list_dup(yy1);kk_std_core_types__ctail_dup(_acc0);}, {}, _ctx)
  kk_std_core__list _x23771 = kk_std_core__mlift21171_op(_acc0, f1, yy1, _b_22035, _ctx); /*list<2738>*/
  return kk_std_core__list_box(_x23771, _ctx);
}

kk_std_core__list kk_std_core__ctail_lift21049_map_peek(kk_function_t f1, kk_std_core__list ys, kk_std_core_types__ctail _acc0, kk_context_t* _ctx) { /* forall<a,b,e> (f : (value : a, rest : list<a>) -> e b, ys : list<a>, ctail<list<b>>) -> e list<b> */ 
  kk__tailcall: ;
  if (kk_std_core__is_Cons(ys)) {
    struct kk_std_core_Cons* _con23766 = kk_std_core__as_Cons(ys);
    kk_box_t y = _con23766->head;
    kk_std_core__list yy1 = _con23766->tail;
    kk_reuse_t _ru_23341 = kk_reuse_null; /*reuse*/;
    if (kk_std_core__list_is_unique(ys)) {
      _ru_23341 = (kk_std_core__list_reuse(ys));
    }
    else {
      kk_box_dup(y);
      kk_std_core__list_dup(yy1);
      kk_std_core__list_decref(ys, _ctx);
      _ru_23341 = kk_reuse_null;
    }
    kk_box_t x_21275;
    kk_function_t _x23768 = kk_function_dup(f1); /*(value : 2737, rest : list<2737>) -> 2739 2738*/
    kk_std_core__list _x23767 = kk_std_core__list_dup(yy1); /*list<2737>*/
    x_21275 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_std_core__list, kk_context_t*), _x23768, (_x23768, y, _x23767, _ctx)); /*2738*/
    if (kk_yielding(kk_context())) {
      kk_reuse_drop(_ru_23341, _ctx);
      kk_box_drop(x_21275, _ctx);
      kk_box_t _x23769 = kk_std_core_hnd_yield_extend(kk_std_core__new_ctail_lift21049_map_peek_fun23770(f1, yy1, _acc0, _ctx), _ctx); /*3991*/
      return kk_std_core__list_unbox(_x23769, _ctx);
    }
    kk_std_core__list _ctail_211160 = kk_std_core__list_hole(); /*list<2738>*/;
    kk_std_core__list _ctail_211170 = kk_std_core__new_Cons(_ru_23341, x_21275, _ctail_211160, _ctx); /*list<2738>*/;
    { // tailcall
      kk_std_core_types__ctail _x23772;
      kk_box_t* field_21281 = (kk_box_t*)((&kk_std_core__as_Cons(_ctail_211170)->tail)); /*cfield<list<2738>>*/;
      if (kk_std_core_types__is_CTail(_acc0)) {
        kk_box_t _box_x22042 = _acc0._cons.CTail._field1;
        kk_box_t* last2 = _acc0._cons.CTail._field2;
        kk_std_core__list head1 = kk_std_core__list_unbox(_box_x22042, NULL);
        kk_unit_t __0 = kk_Unit;
        *(last2) = kk_std_core__list_box(_ctail_211170, _ctx);
        _x23772 = kk_std_core_types__new_CTail(kk_std_core__list_box(head1, _ctx), field_21281, _ctx); /*ctail<58>*/
        goto _match23773;
      }
      _x23772 = kk_std_core_types__new_CTail(kk_std_core__list_box(_ctail_211170, _ctx), field_21281, _ctx); /*ctail<58>*/
      _match23773: ;
      ys = yy1;
      _acc0 = _x23772;
      goto kk__tailcall;
    }
  }
  kk_function_drop(f1, _ctx);
  if (kk_std_core_types__is_CTail(_acc0)) {
    kk_box_t _box_x22051 = _acc0._cons.CTail._field1;
    kk_box_t* last00 = _acc0._cons.CTail._field2;
    kk_std_core__list head00 = kk_std_core__list_unbox(_box_x22051, NULL);
    kk_unit_t __00 = kk_Unit;
    *(last00) = kk_std_core__list_box(kk_std_core__new_Nil(_ctx), _ctx);
    return head00;
  }
  return kk_std_core__new_Nil(_ctx);
}
 
// lift


// lift anonymous function
struct kk_std_core__ctailm_lift21049_map_peek_fun23780__t {
  struct kk_function_s _base;
  kk_function_t _accm0;
  kk_function_t f2;
  kk_std_core__list yy2;
};
static kk_box_t kk_std_core__ctailm_lift21049_map_peek_fun23780(kk_function_t _fself, kk_box_t _b_22063, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_ctailm_lift21049_map_peek_fun23780(kk_function_t _accm0, kk_function_t f2, kk_std_core__list yy2, kk_context_t* _ctx) {
  struct kk_std_core__ctailm_lift21049_map_peek_fun23780__t* _self = kk_function_alloc_as(struct kk_std_core__ctailm_lift21049_map_peek_fun23780__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__ctailm_lift21049_map_peek_fun23780, kk_context());
  _self->_accm0 = _accm0;
  _self->f2 = f2;
  _self->yy2 = yy2;
  return &_self->_base;
}

static kk_box_t kk_std_core__ctailm_lift21049_map_peek_fun23780(kk_function_t _fself, kk_box_t _b_22063, kk_context_t* _ctx) {
  struct kk_std_core__ctailm_lift21049_map_peek_fun23780__t* _self = kk_function_as(struct kk_std_core__ctailm_lift21049_map_peek_fun23780__t*, _fself);
  kk_function_t _accm0 = _self->_accm0; /* (list<2738>) -> list<2738> */
  kk_function_t f2 = _self->f2; /* (value : 2737, rest : list<2737>) -> 2739 2738 */
  kk_std_core__list yy2 = _self->yy2; /* list<2737> */
  kk_drop_match(_self, {kk_function_dup(_accm0);kk_function_dup(f2);kk_std_core__list_dup(yy2);}, {}, _ctx)
  kk_std_core__list _x23781 = kk_std_core__mlift21172_op(_accm0, f2, yy2, _b_22063, _ctx); /*list<2738>*/
  return kk_std_core__list_box(_x23781, _ctx);
}


// lift anonymous function
struct kk_std_core__ctailm_lift21049_map_peek_fun23783__t {
  struct kk_function_s _base;
  kk_function_t _accm0;
  kk_box_t x_21284;
};
static kk_std_core__list kk_std_core__ctailm_lift21049_map_peek_fun23783(kk_function_t _fself, kk_std_core__list _ctail_211190, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_ctailm_lift21049_map_peek_fun23783(kk_function_t _accm0, kk_box_t x_21284, kk_context_t* _ctx) {
  struct kk_std_core__ctailm_lift21049_map_peek_fun23783__t* _self = kk_function_alloc_as(struct kk_std_core__ctailm_lift21049_map_peek_fun23783__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__ctailm_lift21049_map_peek_fun23783, kk_context());
  _self->_accm0 = _accm0;
  _self->x_21284 = x_21284;
  return &_self->_base;
}

static kk_std_core__list kk_std_core__ctailm_lift21049_map_peek_fun23783(kk_function_t _fself, kk_std_core__list _ctail_211190, kk_context_t* _ctx) {
  struct kk_std_core__ctailm_lift21049_map_peek_fun23783__t* _self = kk_function_as(struct kk_std_core__ctailm_lift21049_map_peek_fun23783__t*, _fself);
  kk_function_t _accm0 = _self->_accm0; /* (list<2738>) -> list<2738> */
  kk_box_t x_21284 = _self->x_21284; /* 2738 */
  kk_drop_match(_self, {kk_function_dup(_accm0);kk_box_dup(x_21284);}, {}, _ctx)
  kk_std_core__list _x23784 = kk_std_core__new_Cons(kk_reuse_null, x_21284, _ctail_211190, _ctx); /*list<61>*/
  return kk_function_call(kk_std_core__list, (kk_function_t, kk_std_core__list, kk_context_t*), _accm0, (_accm0, _x23784, _ctx));
}

kk_std_core__list kk_std_core__ctailm_lift21049_map_peek(kk_function_t f2, kk_std_core__list ys0, kk_function_t _accm0, kk_context_t* _ctx) { /* forall<a,b,e> (f : (value : a, rest : list<a>) -> e b, ys : list<a>, (list<b>) -> list<b>) -> e list<b> */ 
  kk__tailcall: ;
  if (kk_std_core__is_Cons(ys0)) {
    struct kk_std_core_Cons* _con23776 = kk_std_core__as_Cons(ys0);
    kk_box_t y0 = _con23776->head;
    kk_std_core__list yy2 = _con23776->tail;
    if (kk_std_core__list_is_unique(ys0)) {
      kk_std_core__list_free(ys0);
    }
    else {
      kk_box_dup(y0);
      kk_std_core__list_dup(yy2);
      kk_std_core__list_decref(ys0, _ctx);
    }
    kk_box_t x_21284;
    kk_function_t _x23778 = kk_function_dup(f2); /*(value : 2737, rest : list<2737>) -> 2739 2738*/
    kk_std_core__list _x23777 = kk_std_core__list_dup(yy2); /*list<2737>*/
    x_21284 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_std_core__list, kk_context_t*), _x23778, (_x23778, y0, _x23777, _ctx)); /*2738*/
    if (kk_yielding(kk_context())) {
      kk_box_drop(x_21284, _ctx);
      kk_box_t _x23779 = kk_std_core_hnd_yield_extend(kk_std_core__new_ctailm_lift21049_map_peek_fun23780(_accm0, f2, yy2, _ctx), _ctx); /*3991*/
      return kk_std_core__list_unbox(_x23779, _ctx);
    }
    { // tailcall
      kk_function_t _x23782 = kk_std_core__new_ctailm_lift21049_map_peek_fun23783(_accm0, x_21284, _ctx); /*(list<2738>) -> list<2738>*/
      ys0 = yy2;
      _accm0 = _x23782;
      goto kk__tailcall;
    }
  }
  kk_function_drop(f2, _ctx);
  return kk_function_call(kk_std_core__list, (kk_function_t, kk_std_core__list, kk_context_t*), _accm0, (_accm0, kk_std_core__new_Nil(_ctx), _ctx));
}
 
// lift


// lift anonymous function
struct kk_std_core__lift21049_map_peek_fun23785__t {
  struct kk_function_s _base;
};
static kk_std_core__list kk_std_core__lift21049_map_peek_fun23785(kk_function_t _fself, kk_std_core__list _ctail_21118, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_lift21049_map_peek_fun23785(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core__lift21049_map_peek_fun23785, _ctx)
  return kk_function_dup(_fself);
}

static kk_std_core__list kk_std_core__lift21049_map_peek_fun23785(kk_function_t _fself, kk_std_core__list _ctail_21118, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return _ctail_21118;
}

kk_std_core__list kk_std_core__lift21049_map_peek(kk_function_t f3, kk_std_core__list ys1, kk_context_t* _ctx) { /* forall<a,b,e> (f : (value : a, rest : list<a>) -> e b, ys : list<a>) -> e list<b> */ 
  bool _match_23643 = kk_std_core_hnd__evv_is_affine(_ctx); /*bool*/;
  if (_match_23643) {
    return kk_std_core__ctail_lift21049_map_peek(f3, ys1, kk_std_core_types__new_CTailNil(_ctx), _ctx);
  }
  return kk_std_core__ctailm_lift21049_map_peek(f3, ys1, kk_std_core__new_lift21049_map_peek_fun23785(_ctx), _ctx);
}

kk_integer_t kk_std_core_maxListStack;

kk_ref_t kk_std_core_trace_enabled;
 
// Compose two funs `f` and `g`.


// lift anonymous function
struct kk_std_core_o_fun23787__t {
  struct kk_function_s _base;
  kk_function_t f;
  kk_function_t g;
};
static kk_box_t kk_std_core_o_fun23787(kk_function_t _fself, kk_box_t x, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_o_fun23787(kk_function_t f, kk_function_t g, kk_context_t* _ctx) {
  struct kk_std_core_o_fun23787__t* _self = kk_function_alloc_as(struct kk_std_core_o_fun23787__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_o_fun23787, kk_context());
  _self->f = f;
  _self->g = g;
  return &_self->_base;
}

static kk_box_t kk_std_core_o_fun23787(kk_function_t _fself, kk_box_t x, kk_context_t* _ctx) {
  struct kk_std_core_o_fun23787__t* _self = kk_function_as(struct kk_std_core_o_fun23787__t*, _fself);
  kk_function_t f = _self->f; /* (2822) -> 2819 2820 */
  kk_function_t g = _self->g; /* (2818) -> 2819 2822 */
  kk_drop_match(_self, {kk_function_dup(f);kk_function_dup(g);}, {}, _ctx)
  kk_box_t x0_21289 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), g, (g, x, _ctx)); /*2822*/;
  if (kk_yielding(kk_context())) {
    kk_box_drop(x0_21289, _ctx);
    return kk_std_core_hnd_yield_extend(f, _ctx);
  }
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), f, (f, x0_21289, _ctx));
}

kk_function_t kk_std_core_o(kk_function_t f, kk_function_t g, kk_context_t* _ctx) { /* forall<a,b,c,e> (f : (a) -> e b, g : (c) -> e a) -> ((x : c) -> e b) */ 
  return kk_std_core_new_o_fun23787(f, g, _ctx);
}
 
// Given a total function to calculate a value `:a`, return
// a total function that only calculates the value once and then
// returns the cached result.


// lift anonymous function
struct kk_std_core_once_fun23790__t {
  struct kk_function_s _base;
  kk_function_t calc;
  kk_ref_t r;
};
static kk_box_t kk_std_core_once_fun23790(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_once_fun23790(kk_function_t calc, kk_ref_t r, kk_context_t* _ctx) {
  struct kk_std_core_once_fun23790__t* _self = kk_function_alloc_as(struct kk_std_core_once_fun23790__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_once_fun23790, kk_context());
  _self->calc = calc;
  _self->r = r;
  return &_self->_base;
}

static kk_box_t kk_std_core_once_fun23790(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_core_once_fun23790__t* _self = kk_function_as(struct kk_std_core_once_fun23790__t*, _fself);
  kk_function_t calc = _self->calc; /* () -> 2945 */
  kk_ref_t r = _self->r; /* ref<_2851,maybe<2945>> */
  kk_drop_match(_self, {kk_function_dup(calc);kk_ref_dup(r);}, {}, _ctx)
  kk_std_core_types__maybe _match_23641;
  kk_box_t _x23791;
  kk_ref_t _x23792 = kk_ref_dup(r); /*ref<_2851,maybe<2945>>*/
  _x23791 = kk_ref_get(_x23792,kk_context()); /*179*/
  _match_23641 = kk_std_core_types__maybe_unbox(_x23791, _ctx); /*maybe<2945>*/
  if (kk_std_core_types__is_Just(_match_23641)) {
    kk_box_t x = _match_23641._cons.Just.value;
    kk_function_drop(calc, _ctx);
    kk_ref_drop(r, _ctx);
    return x;
  }
  kk_box_t x0 = kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), calc, (calc, _ctx)); /*2945*/;
  kk_unit_t __ = kk_Unit;
  kk_std_core_types__maybe _b_22075_22073;
  kk_box_t _x23793 = kk_box_dup(x0); /*2945*/
  _b_22075_22073 = kk_std_core_types__new_Just(_x23793, _ctx); /*maybe<2945>*/
  kk_ref_set(r,(kk_std_core_types__maybe_box(_b_22075_22073, _ctx)),kk_context());
  return x0;
}

kk_function_t kk_std_core_once(kk_function_t calc, kk_context_t* _ctx) { /* forall<a> (calc : () -> a) -> (() -> a) */ 
  kk_ref_t r = kk_ref_alloc((kk_std_core_types__maybe_box(kk_std_core_types__new_Nothing(_ctx), _ctx)),kk_context()); /*ref<_2851,maybe<2945>>*/;
  return kk_std_core_new_once_fun23790(calc, r, _ctx);
}

kk_std_core_types__maybe kk_std_core_xparse_int(kk_string_t s, bool hex, kk_context_t* _ctx) { /* (s : string, hex : bool) -> maybe<int> */ 
  return kk_integer_xparse(s,hex,kk_context());
}

kk_box_t kk_std_core_phantom(kk_context_t* _ctx) { /* forall<a> () -> a */ 
  return kk_box_null;
}
 
// Convert a string to lower-case

kk_string_t kk_std_core_to_lower(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> string */ 
  return kk_string_to_lower(s,kk_context());
}

kk_unit_t kk_std_core_xtrace(kk_string_t message0, kk_context_t* _ctx) { /* (message : string) -> () */ 
  kk_trace(message0,kk_context()); return kk_Unit;
}

kk_unit_t kk_std_core_xtrace_any(kk_string_t message0, kk_box_t x, kk_context_t* _ctx) { /* forall<a> (message : string, x : a) -> () */ 
  kk_trace_any(message0,x,kk_context()); return kk_Unit;
}

kk_ref_t kk_std_core_unique_count;

kk_vector_t kk_std_core_unvlist(kk_std_core__list xs, kk_context_t* _ctx) { /* forall<a> (xs : list<a>) -> vector<a> */ 
  return kk_list_to_vector(xs,kk_context());
}
 
// Create a new vector of length `n`  with initial elements given by function `f` .

kk_vector_t kk_std_core_vector_initz(size_t n, kk_function_t f, kk_context_t* _ctx) { /* forall<a> (n : size_t, f : (size_t) -> a) -> vector<a> */ 
  return kk_vector_init(n,f,kk_context());
}
 
// Append two lists.

kk_std_core__list kk_std_core__ctail_append(kk_std_core__list xs, kk_std_core__list ys, kk_std_core_types__ctail _acc, kk_context_t* _ctx) { /* forall<a> (xs : list<a>, ys : list<a>, ctail<list<a>>) -> list<a> */ 
  kk__tailcall: ;
  if (kk_std_core__is_Cons(xs)) {
    struct kk_std_core_Cons* _con23804 = kk_std_core__as_Cons(xs);
    kk_box_t x = _con23804->head;
    kk_std_core__list xx = _con23804->tail;
    kk_reuse_t _ru_23343 = kk_reuse_null; /*reuse*/;
    if (kk_std_core__list_is_unique(xs)) {
      _ru_23343 = (kk_std_core__list_reuse(xs));
    }
    else {
      kk_box_dup(x);
      kk_std_core__list_dup(xx);
      kk_std_core__list_decref(xs, _ctx);
      _ru_23343 = kk_reuse_null;
    }
    kk_std_core__list _ctail_21121 = kk_std_core__list_hole(); /*list<3560>*/;
    kk_std_core__list _ctail_21122;
    bool _x23805 = _ru_23343!=NULL; /*bool*/
    if (_x23805) {
      struct kk_std_core_Cons* _con23806 = (struct kk_std_core_Cons*)_ru_23343;
      _con23806->tail = _ctail_21121;
      _ctail_21122 = kk_std_core__base_Cons(_con23806); /*list<3560>*/
    }
    else {
      _ctail_21122 = kk_std_core__new_Cons(kk_reuse_null, x, _ctail_21121, _ctx); /*list<3560>*/
    }
    { // tailcall
      kk_std_core_types__ctail _x23807;
      kk_box_t* field_21296 = (kk_box_t*)((&kk_std_core__as_Cons(_ctail_21122)->tail)); /*cfield<list<3560>>*/;
      if (kk_std_core_types__is_CTail(_acc)) {
        kk_box_t _box_x22085 = _acc._cons.CTail._field1;
        kk_box_t* last0 = _acc._cons.CTail._field2;
        kk_std_core__list head0 = kk_std_core__list_unbox(_box_x22085, NULL);
        kk_unit_t __ = kk_Unit;
        *(last0) = kk_std_core__list_box(_ctail_21122, _ctx);
        _x23807 = kk_std_core_types__new_CTail(kk_std_core__list_box(head0, _ctx), field_21296, _ctx); /*ctail<58>*/
        goto _match23808;
      }
      _x23807 = kk_std_core_types__new_CTail(kk_std_core__list_box(_ctail_21122, _ctx), field_21296, _ctx); /*ctail<58>*/
      _match23808: ;
      xs = xx;
      _acc = _x23807;
      goto kk__tailcall;
    }
  }
  kk_box_t _x23810 = kk_std_core_types__ctail_resolve(_acc, kk_std_core__list_box(ys, _ctx), _ctx); /*-1*/
  return kk_std_core__list_unbox(_x23810, _ctx);
}
 
// Append two lists.

kk_std_core__list kk_std_core_append(kk_std_core__list xs0, kk_std_core__list ys0, kk_context_t* _ctx) { /* forall<a> (xs : list<a>, ys : list<a>) -> list<a> */ 
  return kk_std_core__ctail_append(xs0, ys0, kk_std_core_types__new_CTailNil(_ctx), _ctx);
}
 
// Append two strings.

kk_string_t kk_std_core__lp__plus__plus__1_rp_(kk_string_t x, kk_string_t y, kk_context_t* _ctx) { /* (x : string, y : string) -> string */ 
  return kk_string_cat(x,y,kk_context());
}

kk_unit_t kk_std_core_printsln(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> console () */ 
  kk_std_core_types__maybe _match_23640;
  kk_box_t _x23813;
  kk_ref_t _x23814 = kk_ref_dup(kk_std_core_redirect); /*ref<global,maybe<(string) -> console ()>>*/
  _x23813 = kk_ref_get(_x23814,kk_context()); /*179*/
  _match_23640 = kk_std_core_types__maybe_unbox(_x23813, _ctx); /*maybe<(string) -> console ()>*/
  if (kk_std_core_types__is_Nothing(_match_23640)) {
    kk_std_core_xprintsln(s, _ctx); return kk_Unit;
  }
  kk_box_t _fun_unbox_x22106 = _match_23640._cons.Just.value;
  kk_string_t _b_22111_22109;
  kk_string_t _x23815;
  kk_define_string_literal(, _s23816, 1, "\n")
  _x23815 = kk_string_dup(_s23816); /*string*/
  _b_22111_22109 = kk_std_core__lp__plus__plus__1_rp_(s, _x23815, _ctx); /*string*/
  kk_box_t _x23817;
  kk_function_t _x23818 = kk_function_unbox(_fun_unbox_x22106); /*(22107) -> console 22108*/
  _x23817 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x23818, (_x23818, kk_string_box(_b_22111_22109), _ctx)); /*22108*/
  kk_unit_unbox(_x23817); return kk_Unit;
}

kk_std_core_types__order kk_std_core_order(kk_integer_t i, kk_context_t* _ctx) { /* (i : int) -> order */ 
  bool _match_23637;
  kk_integer_t _x23823 = kk_integer_dup(i); /*int*/
  _match_23637 = kk_integer_lt(_x23823,(kk_integer_from_small(0)),kk_context()); /*bool*/
  if (_match_23637) {
    kk_integer_drop(i, _ctx);
    return kk_std_core_types__new_Lt(_ctx);
  }
  bool _match_23638 = kk_integer_gt(i,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  if (_match_23638) {
    return kk_std_core_types__new_Gt(_ctx);
  }
  return kk_std_core_types__new_Eq(_ctx);
}
 
// Compare two strings.
// Uses the character codes directly for comparison

kk_std_core_types__order kk_std_core_compare_4(kk_string_t x, kk_string_t y, kk_context_t* _ctx) { /* (x : string, y : string) -> order */ 
  kk_integer_t i_21297 = kk_std_core_string_compare(x, y, _ctx); /*int*/;
  bool _match_23635;
  kk_integer_t _x23824 = kk_integer_dup(i_21297); /*int*/
  _match_23635 = kk_integer_lt(_x23824,(kk_integer_from_small(0)),kk_context()); /*bool*/
  if (_match_23635) {
    kk_integer_drop(i_21297, _ctx);
    return kk_std_core_types__new_Lt(_ctx);
  }
  bool _match_23636 = kk_integer_gt(i_21297,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  if (_match_23636) {
    return kk_std_core_types__new_Gt(_ctx);
  }
  return kk_std_core_types__new_Eq(_ctx);
}

bool kk_std_core__lp__lt__7_rp_(kk_string_t x, kk_string_t y, kk_context_t* _ctx) { /* (x : string, y : string) -> bool */ 
  kk_std_core_types__order x0_21298 = kk_std_core_compare_4(x, y, _ctx); /*order*/;
  kk_integer_t _x23825 = kk_std_core_int_5(x0_21298, _ctx); /*int*/
  kk_integer_t _x23826;
  kk_std_core_types__order _x23827 = kk_std_core_types__new_Lt(_ctx); /*order*/
  if (kk_std_core_types__is_Lt(_x23827)) {
    _x23826 = kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context()); /*int*/
    goto _match23828;
  }
  if (kk_std_core_types__is_Eq(_x23827)) {
    _x23826 = kk_integer_from_small(0); /*int*/
    goto _match23828;
  }
  _x23826 = kk_integer_from_small(1); /*int*/
  _match23828: ;
  return kk_integer_eq(_x23825,_x23826,kk_context());
}

bool kk_std_core__lp__gt__5_rp_(kk_string_t x, kk_string_t y, kk_context_t* _ctx) { /* (x : string, y : string) -> bool */ 
  kk_std_core_types__order x0_21300 = kk_std_core_compare_4(x, y, _ctx); /*order*/;
  kk_integer_t _x23831 = kk_std_core_int_5(x0_21300, _ctx); /*int*/
  kk_integer_t _x23832;
  kk_std_core_types__order _x23833 = kk_std_core_types__new_Gt(_ctx); /*order*/
  if (kk_std_core_types__is_Lt(_x23833)) {
    _x23832 = kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context()); /*int*/
    goto _match23834;
  }
  if (kk_std_core_types__is_Eq(_x23833)) {
    _x23832 = kk_integer_from_small(0); /*int*/
    goto _match23834;
  }
  _x23832 = kk_integer_from_small(1); /*int*/
  _match23834: ;
  return kk_integer_eq(_x23831,_x23832,kk_context());
}

bool kk_std_core__lp__gt__eq__5_rp_(kk_string_t x, kk_string_t y, kk_context_t* _ctx) { /* (x : string, y : string) -> bool */ 
  kk_std_core_types__order x0_21302 = kk_std_core_compare_4(x, y, _ctx); /*order*/;
  kk_integer_t _x23838 = kk_std_core_int_5(x0_21302, _ctx); /*int*/
  kk_integer_t _x23839;
  kk_std_core_types__order _x23840 = kk_std_core_types__new_Lt(_ctx); /*order*/
  if (kk_std_core_types__is_Lt(_x23840)) {
    _x23839 = kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context()); /*int*/
    goto _match23841;
  }
  if (kk_std_core_types__is_Eq(_x23840)) {
    _x23839 = kk_integer_from_small(0); /*int*/
    goto _match23841;
  }
  _x23839 = kk_integer_from_small(1); /*int*/
  _match23841: ;
  return kk_integer_gt(_x23838,_x23839,kk_context());
}
 
// lift

kk_string_t kk_std_core__lift21050_joinsep(kk_string_t sep, kk_std_core__list ys, kk_string_t acc, kk_context_t* _ctx) { /* (sep : string, ys : list<string>, acc : string) -> string */ 
  kk__tailcall: ;
  if (kk_std_core__is_Cons(ys)) {
    struct kk_std_core_Cons* _con23842 = kk_std_core__as_Cons(ys);
    kk_box_t _box_x22112 = _con23842->head;
    kk_std_core__list yy = _con23842->tail;
    kk_string_t y = kk_string_unbox(_box_x22112);
    if (kk_std_core__list_is_unique(ys)) {
      kk_std_core__list_free(ys);
    }
    else {
      kk_string_dup(y);
      kk_std_core__list_dup(yy);
      kk_std_core__list_decref(ys, _ctx);
    }
    kk_string_t acc0_21072;
    kk_string_t _x23844;
    kk_string_t _x23845 = kk_string_dup(sep); /*string*/
    _x23844 = kk_std_core__lp__plus__plus__1_rp_(_x23845, y, _ctx); /*string*/
    acc0_21072 = kk_std_core__lp__plus__plus__1_rp_(acc, _x23844, _ctx); /*string*/
    { // tailcall
      ys = yy;
      acc = acc0_21072;
      goto kk__tailcall;
    }
  }
  kk_string_drop(sep, _ctx);
  return acc;
}
 
// Concatenate all strings in a list

kk_string_t kk_std_core_joinsep(kk_std_core__list xs, kk_string_t sep, kk_context_t* _ctx) { /* (xs : list<string>, sep : string) -> string */ 
  if (kk_std_core__is_Nil(xs)) {
    kk_string_drop(sep, _ctx);
    return kk_string_empty();
  }
  struct kk_std_core_Cons* _con23847 = kk_std_core__as_Cons(xs);
  kk_box_t _box_x22113 = _con23847->head;
  kk_std_core__list xx = _con23847->tail;
  kk_string_t x = kk_string_unbox(_box_x22113);
  if (kk_std_core__list_is_unique(xs)) {
    kk_std_core__list_free(xs);
  }
  else {
    kk_string_dup(x);
    kk_std_core__list_dup(xx);
    kk_std_core__list_decref(xs, _ctx);
  }
  return kk_std_core__lift21050_joinsep(sep, xx, x, _ctx);
}
 
// Concatenate all strings in a list

kk_string_t kk_std_core_join_2(kk_std_core__list xs, kk_context_t* _ctx) { /* (xs : list<string>) -> string */ 
  if (kk_std_core__is_Nil(xs)) {
    return kk_string_empty();
  }
  struct kk_std_core_Cons* _con23850 = kk_std_core__as_Cons(xs);
  kk_box_t _box_x22114 = _con23850->head;
  kk_std_core__list xx = _con23850->tail;
  kk_string_t x = kk_string_unbox(_box_x22114);
  if (kk_std_core__list_is_unique(xs)) {
    kk_std_core__list_free(xs);
  }
  else {
    kk_string_dup(x);
    kk_std_core__list_dup(xx);
    kk_std_core__list_decref(xs, _ctx);
  }
  kk_string_t _x23852 = kk_string_empty(); /*string*/
  return kk_std_core__lift21050_joinsep(_x23852, xx, x, _ctx);
}

size_t kk_std_core_decr_1(size_t i, kk_context_t* _ctx) { /* (i : size_t) -> size_t */ 
  return (i - 1);
}

bool kk_std_core__lp__lt__eq__7_rp_(kk_string_t x, kk_string_t y, kk_context_t* _ctx) { /* (x : string, y : string) -> bool */ 
  kk_std_core_types__order x0_21306 = kk_std_core_compare_4(x, y, _ctx); /*order*/;
  kk_integer_t _x23859 = kk_std_core_int_5(x0_21306, _ctx); /*int*/
  kk_integer_t _x23860;
  kk_std_core_types__order _x23861 = kk_std_core_types__new_Gt(_ctx); /*order*/
  if (kk_std_core_types__is_Lt(_x23861)) {
    _x23860 = kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context()); /*int*/
    goto _match23862;
  }
  if (kk_std_core_types__is_Eq(_x23861)) {
    _x23860 = kk_integer_from_small(0); /*int*/
    goto _match23862;
  }
  _x23860 = kk_integer_from_small(1); /*int*/
  _match23862: ;
  return kk_integer_lt(_x23859,_x23860,kk_context());
}

size_t kk_std_core_incr_1(size_t i, kk_context_t* _ctx) { /* (i : size_t) -> size_t */ 
  return (i + 1);
}
 
// monadic lift

kk_unit_t kk_std_core__mlift21173_op(kk_function_t action, size_t end, size_t i, kk_unit_t wild__, kk_context_t* _ctx) { /* forall<e> (action : (size_t) -> e (), end : size_t, i : size_t, wild_ : ()) -> e () */ 
  size_t i0_21073 = kk_std_core_incr_1(i, _ctx); /*size_t*/;
  kk_std_core__lift21051_forz(action, end, i0_21073, _ctx); return kk_Unit;
}
 
// lift


// lift anonymous function
struct kk_std_core__lift21051_forz_fun23865__t {
  struct kk_function_s _base;
  kk_function_t action0;
  size_t end0;
  size_t i0;
};
static kk_box_t kk_std_core__lift21051_forz_fun23865(kk_function_t _fself, kk_box_t _b_22116, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_lift21051_forz_fun23865(kk_function_t action0, size_t end0, size_t i0, kk_context_t* _ctx) {
  struct kk_std_core__lift21051_forz_fun23865__t* _self = kk_function_alloc_as(struct kk_std_core__lift21051_forz_fun23865__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__lift21051_forz_fun23865, kk_context());
  _self->action0 = action0;
  _self->end0 = end0;
  _self->i0 = i0;
  return &_self->_base;
}

static kk_box_t kk_std_core__lift21051_forz_fun23865(kk_function_t _fself, kk_box_t _b_22116, kk_context_t* _ctx) {
  struct kk_std_core__lift21051_forz_fun23865__t* _self = kk_function_as(struct kk_std_core__lift21051_forz_fun23865__t*, _fself);
  kk_function_t action0 = _self->action0; /* (size_t) -> 5520 () */
  size_t end0 = _self->end0; /* size_t */
  size_t i0 = _self->i0; /* size_t */
  kk_drop_match(_self, {kk_function_dup(action0);;;}, {}, _ctx)
  kk_unit_t _x23866 = kk_Unit;
  kk_unit_t _x23867 = kk_Unit;
  kk_unit_unbox(_b_22116);
  kk_std_core__mlift21173_op(action0, end0, i0, _x23867, _ctx);
  return kk_unit_box(_x23866);
}

kk_unit_t kk_std_core__lift21051_forz(kk_function_t action0, size_t end0, size_t i0, kk_context_t* _ctx) { /* forall<e> (action : (size_t) -> e (), end : size_t, i : size_t) -> e () */ 
  kk__tailcall: ;
  bool _match_23623 = (i0 <= end0); /*bool*/;
  if (_match_23623) {
    kk_unit_t x_21308 = kk_Unit;
    kk_function_t _x23863 = kk_function_dup(action0); /*(size_t) -> 5520 ()*/
    kk_function_call(kk_unit_t, (kk_function_t, size_t, kk_context_t*), _x23863, (_x23863, i0, _ctx));
    if (kk_yielding(kk_context())) {
      kk_box_t _x23864 = kk_std_core_hnd_yield_extend(kk_std_core__new_lift21051_forz_fun23865(action0, end0, i0, _ctx), _ctx); /*3991*/
      kk_unit_unbox(_x23864); return kk_Unit;
    }
    size_t i0_210730 = kk_std_core_incr_1(i0, _ctx); /*size_t*/;
    { // tailcall
      i0 = i0_210730;
      goto kk__tailcall;
    }
  }
  kk_function_drop(action0, _ctx);
  kk_Unit; return kk_Unit;
}


// lift anonymous function
struct kk_std_core_foreach_indexedz_fun23870__t {
  struct kk_function_s _base;
  kk_function_t f;
  kk_vector_t v;
};
static kk_unit_t kk_std_core_foreach_indexedz_fun23870(kk_function_t _fself, size_t i, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_foreach_indexedz_fun23870(kk_function_t f, kk_vector_t v, kk_context_t* _ctx) {
  struct kk_std_core_foreach_indexedz_fun23870__t* _self = kk_function_alloc_as(struct kk_std_core_foreach_indexedz_fun23870__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_foreach_indexedz_fun23870, kk_context());
  _self->f = f;
  _self->v = v;
  return &_self->_base;
}

static kk_unit_t kk_std_core_foreach_indexedz_fun23870(kk_function_t _fself, size_t i, kk_context_t* _ctx) {
  struct kk_std_core_foreach_indexedz_fun23870__t* _self = kk_function_as(struct kk_std_core_foreach_indexedz_fun23870__t*, _fself);
  kk_function_t f = _self->f; /* (5617, size_t) -> 5618 () */
  kk_vector_t v = _self->v; /* vector<5617> */
  kk_drop_match(_self, {kk_function_dup(f);kk_vector_dup(v);}, {}, _ctx)
  kk_box_t _x23871 = kk_vector_at(v,i); /*216*/
  return kk_function_call(kk_unit_t, (kk_function_t, kk_box_t, size_t, kk_context_t*), f, (f, _x23871, i, _ctx));
}

kk_unit_t kk_std_core_foreach_indexedz(kk_vector_t v, kk_function_t f, kk_context_t* _ctx) { /* forall<a,e> (v : vector<a>, f : (a, size_t) -> e ()) -> e () */ 
  size_t start_21312 = ((size_t)0); /*size_t*/;
  size_t end_21313;
  size_t _x23868;
  kk_vector_t _x23869 = kk_vector_dup(v); /*vector<5617>*/
  _x23868 = kk_vector_len(_x23869); /*size_t*/
  end_21313 = kk_std_core_decr_1(_x23868, _ctx); /*size_t*/
  kk_std_core__lift21051_forz(kk_std_core_new_foreach_indexedz_fun23870(f, v, _ctx), end_21313, start_21312, _ctx); return kk_Unit;
}
 
// lift

kk_integer_t kk_std_core__lift21052_length_1(kk_std_core__list ys, kk_integer_t acc, kk_context_t* _ctx) { /* forall<a> (ys : list<a>, acc : int) -> int */ 
  kk__tailcall: ;
  if (kk_std_core__is_Cons(ys)) {
    struct kk_std_core_Cons* _con23872 = kk_std_core__as_Cons(ys);
    kk_box_t _pat0 = _con23872->head;
    kk_std_core__list yy = _con23872->tail;
    if (kk_std_core__list_is_unique(ys)) {
      kk_box_drop(_pat0, _ctx);
      kk_std_core__list_free(ys);
    }
    else {
      kk_std_core__list_dup(yy);
      kk_std_core__list_decref(ys, _ctx);
    }
    { // tailcall
      kk_integer_t _x23873 = kk_integer_add(acc,(kk_integer_from_small(1)),kk_context()); /*int*/
      ys = yy;
      acc = _x23873;
      goto kk__tailcall;
    }
  }
  return acc;
}
 
// lift

kk_std_core__list kk_std_core__lift21053_list(kk_integer_t low, kk_integer_t high, kk_std_core__list acc, kk_context_t* _ctx) { /* (low : int, high : int, acc : list<int>) -> list<int> */ 
  kk__tailcall: ;
  bool _match_23622;
  kk_integer_t _x23875 = kk_integer_dup(low); /*int*/
  kk_integer_t _x23876 = kk_integer_dup(high); /*int*/
  _match_23622 = kk_integer_gt(_x23875,_x23876,kk_context()); /*bool*/
  if (_match_23622) {
    kk_integer_drop(high, _ctx);
    kk_integer_drop(low, _ctx);
    return acc;
  }
  { // tailcall
    kk_integer_t _x23877;
    kk_integer_t _x23878 = kk_integer_dup(high); /*int*/
    _x23877 = kk_integer_sub(_x23878,(kk_integer_from_small(1)),kk_context()); /*int*/
    kk_std_core__list _x23879 = kk_std_core__new_Cons(kk_reuse_null, kk_integer_box(high), acc, _ctx); /*list<61>*/
    high = _x23877;
    acc = _x23879;
    goto kk__tailcall;
  }
}
 
// monadic lift

kk_std_core__list kk_std_core__mlift21174_op(kk_std_core__list acc, kk_function_t f, kk_integer_t high0_21076, kk_integer_t low, kk_box_t _y_46, kk_context_t* _ctx) { /* forall<a,e> (acc : list<a>, f : (int) -> e a, high0.21076 : int, low : int, a) -> e list<a> */ 
  kk_std_core__list acc0_21077 = kk_std_core__new_Cons(kk_reuse_null, _y_46, acc, _ctx); /*list<6015>*/;
  return kk_std_core__lift21054_list_1(f, low, high0_21076, acc0_21077, _ctx);
}
 
// lift


// lift anonymous function
struct kk_std_core__lift21054_list_fun23885__t_1 {
  struct kk_function_s _base;
  kk_std_core__list acc0;
  kk_function_t f0;
  kk_integer_t high0_210760;
  kk_integer_t low0;
};
static kk_box_t kk_std_core__lift21054_list_fun23885_1(kk_function_t _fself, kk_box_t _b_22124, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_lift21054_list_fun23885_1(kk_std_core__list acc0, kk_function_t f0, kk_integer_t high0_210760, kk_integer_t low0, kk_context_t* _ctx) {
  struct kk_std_core__lift21054_list_fun23885__t_1* _self = kk_function_alloc_as(struct kk_std_core__lift21054_list_fun23885__t_1, 5, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__lift21054_list_fun23885_1, kk_context());
  _self->acc0 = acc0;
  _self->f0 = f0;
  _self->high0_210760 = high0_210760;
  _self->low0 = low0;
  return &_self->_base;
}

static kk_box_t kk_std_core__lift21054_list_fun23885_1(kk_function_t _fself, kk_box_t _b_22124, kk_context_t* _ctx) {
  struct kk_std_core__lift21054_list_fun23885__t_1* _self = kk_function_as(struct kk_std_core__lift21054_list_fun23885__t_1*, _fself);
  kk_std_core__list acc0 = _self->acc0; /* list<6015> */
  kk_function_t f0 = _self->f0; /* (int) -> 6016 6015 */
  kk_integer_t high0_210760 = _self->high0_210760; /* int */
  kk_integer_t low0 = _self->low0; /* int */
  kk_drop_match(_self, {kk_std_core__list_dup(acc0);kk_function_dup(f0);kk_integer_dup(high0_210760);kk_integer_dup(low0);}, {}, _ctx)
  kk_std_core__list _x23886 = kk_std_core__mlift21174_op(acc0, f0, high0_210760, low0, _b_22124, _ctx); /*list<6015>*/
  return kk_std_core__list_box(_x23886, _ctx);
}

kk_std_core__list kk_std_core__lift21054_list_1(kk_function_t f0, kk_integer_t low0, kk_integer_t high, kk_std_core__list acc0, kk_context_t* _ctx) { /* forall<a,e> (f : (int) -> e a, low : int, high : int, acc : list<a>) -> e list<a> */ 
  kk__tailcall: ;
  bool _match_23620;
  kk_integer_t _x23880 = kk_integer_dup(low0); /*int*/
  kk_integer_t _x23881 = kk_integer_dup(high); /*int*/
  _match_23620 = kk_integer_gt(_x23880,_x23881,kk_context()); /*bool*/
  if (_match_23620) {
    kk_function_drop(f0, _ctx);
    kk_integer_drop(high, _ctx);
    kk_integer_drop(low0, _ctx);
    return acc0;
  }
  kk_integer_t high0_210760;
  kk_integer_t _x23882 = kk_integer_dup(high); /*int*/
  high0_210760 = kk_integer_sub(_x23882,(kk_integer_from_small(1)),kk_context()); /*int*/
  kk_box_t x_21315;
  kk_function_t _x23883 = kk_function_dup(f0); /*(int) -> 6016 6015*/
  x_21315 = kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_context_t*), _x23883, (_x23883, high, _ctx)); /*6015*/
  if (kk_yielding(kk_context())) {
    kk_box_drop(x_21315, _ctx);
    kk_box_t _x23884 = kk_std_core_hnd_yield_extend(kk_std_core__new_lift21054_list_fun23885_1(acc0, f0, high0_210760, low0, _ctx), _ctx); /*3991*/
    return kk_std_core__list_unbox(_x23884, _ctx);
  }
  kk_std_core__list acc0_210770 = kk_std_core__new_Cons(kk_reuse_null, x_21315, acc0, _ctx); /*list<6015>*/;
  { // tailcall
    high = high0_210760;
    acc0 = acc0_210770;
    goto kk__tailcall;
  }
}
 
// monadic lift

kk_std_core__list kk_std_core__mlift21175_op(kk_std_core_types__ctail _acc, kk_function_t f, kk_std_core__list xx, kk_box_t _ctail_21123, kk_context_t* _ctx) { /* forall<a,b,e> (ctail<list<b>>, f : (a) -> e b, xx : list<a>, b) -> e list<b> */ 
  kk_std_core__list _ctail_21124 = kk_std_core__list_hole(); /*list<7320>*/;
  kk_std_core__list _ctail_21125 = kk_std_core__new_Cons(kk_reuse_null, _ctail_21123, _ctail_21124, _ctx); /*list<7320>*/;
  kk_std_core_types__ctail _x23887;
  kk_box_t* field_21321 = (kk_box_t*)((&kk_std_core__as_Cons(_ctail_21125)->tail)); /*cfield<list<7320>>*/;
  if (kk_std_core_types__is_CTail(_acc)) {
    kk_box_t _box_x22133 = _acc._cons.CTail._field1;
    kk_box_t* last0 = _acc._cons.CTail._field2;
    kk_std_core__list head0 = kk_std_core__list_unbox(_box_x22133, NULL);
    kk_unit_t __ = kk_Unit;
    *(last0) = kk_std_core__list_box(_ctail_21125, _ctx);
    _x23887 = kk_std_core_types__new_CTail(kk_std_core__list_box(head0, _ctx), field_21321, _ctx); /*ctail<58>*/
    goto _match23888;
  }
  _x23887 = kk_std_core_types__new_CTail(kk_std_core__list_box(_ctail_21125, _ctx), field_21321, _ctx); /*ctail<58>*/
  _match23888: ;
  return kk_std_core__ctail_map_5(xx, f, _x23887, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_core__mlift21176_op_fun23890__t {
  struct kk_function_s _base;
  kk_function_t _accm;
  kk_box_t _ctail_21128;
};
static kk_std_core__list kk_std_core__mlift21176_op_fun23890(kk_function_t _fself, kk_std_core__list _ctail_21127, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_mlift21176_op_fun23890(kk_function_t _accm, kk_box_t _ctail_21128, kk_context_t* _ctx) {
  struct kk_std_core__mlift21176_op_fun23890__t* _self = kk_function_alloc_as(struct kk_std_core__mlift21176_op_fun23890__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__mlift21176_op_fun23890, kk_context());
  _self->_accm = _accm;
  _self->_ctail_21128 = _ctail_21128;
  return &_self->_base;
}

static kk_std_core__list kk_std_core__mlift21176_op_fun23890(kk_function_t _fself, kk_std_core__list _ctail_21127, kk_context_t* _ctx) {
  struct kk_std_core__mlift21176_op_fun23890__t* _self = kk_function_as(struct kk_std_core__mlift21176_op_fun23890__t*, _fself);
  kk_function_t _accm = _self->_accm; /* (list<7320>) -> list<7320> */
  kk_box_t _ctail_21128 = _self->_ctail_21128; /* 7320 */
  kk_drop_match(_self, {kk_function_dup(_accm);kk_box_dup(_ctail_21128);}, {}, _ctx)
  kk_std_core__list _x23891 = kk_std_core__new_Cons(kk_reuse_null, _ctail_21128, _ctail_21127, _ctx); /*list<61>*/
  return kk_function_call(kk_std_core__list, (kk_function_t, kk_std_core__list, kk_context_t*), _accm, (_accm, _x23891, _ctx));
}

kk_std_core__list kk_std_core__mlift21176_op(kk_function_t _accm, kk_function_t f0, kk_std_core__list xx0, kk_box_t _ctail_21128, kk_context_t* _ctx) { /* forall<a,b,e> ((list<b>) -> list<b>, f : (a) -> e b, xx : list<a>, b) -> e list<b> */ 
  return kk_std_core__ctailm_map_5(xx0, f0, kk_std_core__new_mlift21176_op_fun23890(_accm, _ctail_21128, _ctx), _ctx);
}
 
// Apply a function `f`  to each element of the input list in sequence.


// lift anonymous function
struct kk_std_core__ctail_map_fun23895__t_5 {
  struct kk_function_s _base;
  kk_function_t f1;
  kk_std_core__list xx1;
  kk_std_core_types__ctail _acc0;
};
static kk_box_t kk_std_core__ctail_map_fun23895_5(kk_function_t _fself, kk_box_t _b_22147, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_ctail_map_fun23895_5(kk_function_t f1, kk_std_core__list xx1, kk_std_core_types__ctail _acc0, kk_context_t* _ctx) {
  struct kk_std_core__ctail_map_fun23895__t_5* _self = kk_function_alloc_as(struct kk_std_core__ctail_map_fun23895__t_5, 5, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__ctail_map_fun23895_5, kk_context());
  _self->f1 = f1;
  _self->xx1 = xx1;
  _self->_acc0 = _acc0;
  return &_self->_base;
}

static kk_box_t kk_std_core__ctail_map_fun23895_5(kk_function_t _fself, kk_box_t _b_22147, kk_context_t* _ctx) {
  struct kk_std_core__ctail_map_fun23895__t_5* _self = kk_function_as(struct kk_std_core__ctail_map_fun23895__t_5*, _fself);
  kk_function_t f1 = _self->f1; /* (7319) -> 7321 7320 */
  kk_std_core__list xx1 = _self->xx1; /* list<7319> */
  kk_std_core_types__ctail _acc0 = _self->_acc0; /* ctail<list<7320>> */
  kk_drop_match(_self, {kk_function_dup(f1);kk_std_core__list_dup(xx1);kk_std_core_types__ctail_dup(_acc0);}, {}, _ctx)
  kk_std_core__list _x23896 = kk_std_core__mlift21175_op(_acc0, f1, xx1, _b_22147, _ctx); /*list<7320>*/
  return kk_std_core__list_box(_x23896, _ctx);
}

kk_std_core__list kk_std_core__ctail_map_5(kk_std_core__list xs, kk_function_t f1, kk_std_core_types__ctail _acc0, kk_context_t* _ctx) { /* forall<a,b,e> (xs : list<a>, f : (a) -> e b, ctail<list<b>>) -> e list<b> */ 
  kk__tailcall: ;
  if (kk_std_core__is_Cons(xs)) {
    struct kk_std_core_Cons* _con23892 = kk_std_core__as_Cons(xs);
    kk_box_t x = _con23892->head;
    kk_std_core__list xx1 = _con23892->tail;
    kk_reuse_t _ru_23348 = kk_reuse_null; /*reuse*/;
    if (kk_std_core__list_is_unique(xs)) {
      _ru_23348 = (kk_std_core__list_reuse(xs));
    }
    else {
      kk_box_dup(x);
      kk_std_core__list_dup(xx1);
      kk_std_core__list_decref(xs, _ctx);
      _ru_23348 = kk_reuse_null;
    }
    kk_box_t x0_21322;
    kk_function_t _x23893 = kk_function_dup(f1); /*(7319) -> 7321 7320*/
    x0_21322 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x23893, (_x23893, x, _ctx)); /*7320*/
    if (kk_yielding(kk_context())) {
      kk_reuse_drop(_ru_23348, _ctx);
      kk_box_drop(x0_21322, _ctx);
      kk_box_t _x23894 = kk_std_core_hnd_yield_extend(kk_std_core__new_ctail_map_fun23895_5(f1, xx1, _acc0, _ctx), _ctx); /*3991*/
      return kk_std_core__list_unbox(_x23894, _ctx);
    }
    kk_std_core__list _ctail_211240 = kk_std_core__list_hole(); /*list<7320>*/;
    kk_std_core__list _ctail_211250 = kk_std_core__new_Cons(_ru_23348, x0_21322, _ctail_211240, _ctx); /*list<7320>*/;
    { // tailcall
      kk_std_core_types__ctail _x23897;
      kk_box_t* field_21328 = (kk_box_t*)((&kk_std_core__as_Cons(_ctail_211250)->tail)); /*cfield<list<7320>>*/;
      if (kk_std_core_types__is_CTail(_acc0)) {
        kk_box_t _box_x22154 = _acc0._cons.CTail._field1;
        kk_box_t* last2 = _acc0._cons.CTail._field2;
        kk_std_core__list head1 = kk_std_core__list_unbox(_box_x22154, NULL);
        kk_unit_t __0 = kk_Unit;
        *(last2) = kk_std_core__list_box(_ctail_211250, _ctx);
        _x23897 = kk_std_core_types__new_CTail(kk_std_core__list_box(head1, _ctx), field_21328, _ctx); /*ctail<58>*/
        goto _match23898;
      }
      _x23897 = kk_std_core_types__new_CTail(kk_std_core__list_box(_ctail_211250, _ctx), field_21328, _ctx); /*ctail<58>*/
      _match23898: ;
      xs = xx1;
      _acc0 = _x23897;
      goto kk__tailcall;
    }
  }
  kk_function_drop(f1, _ctx);
  if (kk_std_core_types__is_CTail(_acc0)) {
    kk_box_t _box_x22163 = _acc0._cons.CTail._field1;
    kk_box_t* last00 = _acc0._cons.CTail._field2;
    kk_std_core__list head00 = kk_std_core__list_unbox(_box_x22163, NULL);
    kk_unit_t __00 = kk_Unit;
    *(last00) = kk_std_core__list_box(kk_std_core__new_Nil(_ctx), _ctx);
    return head00;
  }
  return kk_std_core__new_Nil(_ctx);
}
 
// Apply a function `f`  to each element of the input list in sequence.


// lift anonymous function
struct kk_std_core__ctailm_map_fun23904__t_5 {
  struct kk_function_s _base;
  kk_function_t _accm0;
  kk_function_t f2;
  kk_std_core__list xx2;
};
static kk_box_t kk_std_core__ctailm_map_fun23904_5(kk_function_t _fself, kk_box_t _b_22175, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_ctailm_map_fun23904_5(kk_function_t _accm0, kk_function_t f2, kk_std_core__list xx2, kk_context_t* _ctx) {
  struct kk_std_core__ctailm_map_fun23904__t_5* _self = kk_function_alloc_as(struct kk_std_core__ctailm_map_fun23904__t_5, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__ctailm_map_fun23904_5, kk_context());
  _self->_accm0 = _accm0;
  _self->f2 = f2;
  _self->xx2 = xx2;
  return &_self->_base;
}

static kk_box_t kk_std_core__ctailm_map_fun23904_5(kk_function_t _fself, kk_box_t _b_22175, kk_context_t* _ctx) {
  struct kk_std_core__ctailm_map_fun23904__t_5* _self = kk_function_as(struct kk_std_core__ctailm_map_fun23904__t_5*, _fself);
  kk_function_t _accm0 = _self->_accm0; /* (list<7320>) -> list<7320> */
  kk_function_t f2 = _self->f2; /* (7319) -> 7321 7320 */
  kk_std_core__list xx2 = _self->xx2; /* list<7319> */
  kk_drop_match(_self, {kk_function_dup(_accm0);kk_function_dup(f2);kk_std_core__list_dup(xx2);}, {}, _ctx)
  kk_std_core__list _x23905 = kk_std_core__mlift21176_op(_accm0, f2, xx2, _b_22175, _ctx); /*list<7320>*/
  return kk_std_core__list_box(_x23905, _ctx);
}


// lift anonymous function
struct kk_std_core__ctailm_map_fun23907__t_5 {
  struct kk_function_s _base;
  kk_function_t _accm0;
  kk_box_t x0_21331;
};
static kk_std_core__list kk_std_core__ctailm_map_fun23907_5(kk_function_t _fself, kk_std_core__list _ctail_211270, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_ctailm_map_fun23907_5(kk_function_t _accm0, kk_box_t x0_21331, kk_context_t* _ctx) {
  struct kk_std_core__ctailm_map_fun23907__t_5* _self = kk_function_alloc_as(struct kk_std_core__ctailm_map_fun23907__t_5, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__ctailm_map_fun23907_5, kk_context());
  _self->_accm0 = _accm0;
  _self->x0_21331 = x0_21331;
  return &_self->_base;
}

static kk_std_core__list kk_std_core__ctailm_map_fun23907_5(kk_function_t _fself, kk_std_core__list _ctail_211270, kk_context_t* _ctx) {
  struct kk_std_core__ctailm_map_fun23907__t_5* _self = kk_function_as(struct kk_std_core__ctailm_map_fun23907__t_5*, _fself);
  kk_function_t _accm0 = _self->_accm0; /* (list<7320>) -> list<7320> */
  kk_box_t x0_21331 = _self->x0_21331; /* 7320 */
  kk_drop_match(_self, {kk_function_dup(_accm0);kk_box_dup(x0_21331);}, {}, _ctx)
  kk_std_core__list _x23908 = kk_std_core__new_Cons(kk_reuse_null, x0_21331, _ctail_211270, _ctx); /*list<61>*/
  return kk_function_call(kk_std_core__list, (kk_function_t, kk_std_core__list, kk_context_t*), _accm0, (_accm0, _x23908, _ctx));
}

kk_std_core__list kk_std_core__ctailm_map_5(kk_std_core__list xs0, kk_function_t f2, kk_function_t _accm0, kk_context_t* _ctx) { /* forall<a,b,e> (xs : list<a>, f : (a) -> e b, (list<b>) -> list<b>) -> e list<b> */ 
  kk__tailcall: ;
  if (kk_std_core__is_Cons(xs0)) {
    struct kk_std_core_Cons* _con23901 = kk_std_core__as_Cons(xs0);
    kk_box_t x0 = _con23901->head;
    kk_std_core__list xx2 = _con23901->tail;
    if (kk_std_core__list_is_unique(xs0)) {
      kk_std_core__list_free(xs0);
    }
    else {
      kk_box_dup(x0);
      kk_std_core__list_dup(xx2);
      kk_std_core__list_decref(xs0, _ctx);
    }
    kk_box_t x0_21331;
    kk_function_t _x23902 = kk_function_dup(f2); /*(7319) -> 7321 7320*/
    x0_21331 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x23902, (_x23902, x0, _ctx)); /*7320*/
    if (kk_yielding(kk_context())) {
      kk_box_drop(x0_21331, _ctx);
      kk_box_t _x23903 = kk_std_core_hnd_yield_extend(kk_std_core__new_ctailm_map_fun23904_5(_accm0, f2, xx2, _ctx), _ctx); /*3991*/
      return kk_std_core__list_unbox(_x23903, _ctx);
    }
    { // tailcall
      kk_function_t _x23906 = kk_std_core__new_ctailm_map_fun23907_5(_accm0, x0_21331, _ctx); /*(list<7320>) -> list<7320>*/
      xs0 = xx2;
      _accm0 = _x23906;
      goto kk__tailcall;
    }
  }
  kk_function_drop(f2, _ctx);
  return kk_function_call(kk_std_core__list, (kk_function_t, kk_std_core__list, kk_context_t*), _accm0, (_accm0, kk_std_core__new_Nil(_ctx), _ctx));
}
 
// Apply a function `f`  to each element of the input list in sequence.


// lift anonymous function
struct kk_std_core_map_fun23909__t_5 {
  struct kk_function_s _base;
};
static kk_std_core__list kk_std_core_map_fun23909_5(kk_function_t _fself, kk_std_core__list _ctail_21126, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_map_fun23909_5(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_map_fun23909_5, _ctx)
  return kk_function_dup(_fself);
}

static kk_std_core__list kk_std_core_map_fun23909_5(kk_function_t _fself, kk_std_core__list _ctail_21126, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return _ctail_21126;
}

kk_std_core__list kk_std_core_map_5(kk_std_core__list xs1, kk_function_t f3, kk_context_t* _ctx) { /* forall<a,b,e> (xs : list<a>, f : (a) -> e b) -> e list<b> */ 
  bool _match_23617 = kk_std_core_hnd__evv_is_affine(_ctx); /*bool*/;
  if (_match_23617) {
    return kk_std_core__ctail_map_5(xs1, f3, kk_std_core_types__new_CTailNil(_ctx), _ctx);
  }
  return kk_std_core__ctailm_map_5(xs1, f3, kk_std_core_new_map_fun23909_5(_ctx), _ctx);
}
 
// Create a list of characters from `lo`  to `hi`  (inclusive).


// lift anonymous function
struct kk_std_core_list_fun23910__t_2 {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_list_fun23910_2(kk_function_t _fself, kk_box_t _b_22180, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_list_fun23910_2(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_list_fun23910_2, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_core_list_fun23910_2(kk_function_t _fself, kk_box_t _b_22180, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_char_t _x23911;
  kk_integer_t _x23912 = kk_integer_unbox(_b_22180); /*int*/
  _x23911 = kk_integer_clamp32(_x23912,kk_context()); /*char*/
  return kk_char_box(_x23911, _ctx);
}

kk_std_core__list kk_std_core_list_2(kk_char_t lo, kk_char_t hi, kk_context_t* _ctx) { /* (lo : char, hi : char) -> total list<char> */ 
  kk_std_core__list _b_22181_22178;
  kk_integer_t lo0_21335 = kk_integer_from_int(lo,kk_context()); /*int*/;
  kk_integer_t hi0_21336 = kk_integer_from_int(hi,kk_context()); /*int*/;
  _b_22181_22178 = kk_std_core__lift21053_list(lo0_21335, hi0_21336, kk_std_core__new_Nil(_ctx), _ctx); /*list<int>*/
  return kk_std_core_map_5(_b_22181_22178, kk_std_core_new_list_fun23910_2(_ctx), _ctx);
}
 
// Convert a string to a list of characters

kk_std_core__list kk_std_core_list_4(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> total list<char> */ 
  return kk_string_to_list(s,kk_context());
}
 
// monadic lift

kk_std_core_types__maybe kk_std_core__mlift21177_map(kk_box_t _y_59, kk_context_t* _ctx) { /* forall<a,e> (a) -> e maybe<a> */ 
  return kk_std_core_types__new_Just(_y_59, _ctx);
}


// lift anonymous function
struct kk_std_core_map_fun23914__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_map_fun23914(kk_function_t _fself, kk_box_t _b_22184, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_map_fun23914(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_map_fun23914, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_core_map_fun23914(kk_function_t _fself, kk_box_t _b_22184, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core_types__maybe _x23915 = kk_std_core__mlift21177_map(_b_22184, _ctx); /*maybe<6436>*/
  return kk_std_core_types__maybe_box(_x23915, _ctx);
}

kk_std_core_types__maybe kk_std_core_map(kk_std_core_types__maybe m, kk_function_t f, kk_context_t* _ctx) { /* forall<a,b,e> (m : maybe<a>, f : (a) -> e b) -> e maybe<b> */ 
  if (kk_std_core_types__is_Nothing(m)) {
    kk_function_drop(f, _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
  kk_box_t x = m._cons.Just.value;
  kk_box_t x0_21337 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), f, (f, x, _ctx)); /*6436*/;
  if (kk_yielding(kk_context())) {
    kk_box_drop(x0_21337, _ctx);
    kk_box_t _x23913 = kk_std_core_hnd_yield_extend(kk_std_core_new_map_fun23914(_ctx), _ctx); /*3991*/
    return kk_std_core_types__maybe_unbox(_x23913, _ctx);
  }
  return kk_std_core_types__new_Just(x0_21337, _ctx);
}
 
// monadic lift

kk_std_core_types__either kk_std_core__mlift21178_map_1(kk_box_t _y_61, kk_context_t* _ctx) { /* forall<a,b,e> (b) -> e either<a,b> */ 
  return kk_std_core_types__new_Right(_y_61, _ctx);
}
 
// Map over the `Right` component of an `:either` type.


// lift anonymous function
struct kk_std_core_map_fun23917__t_1 {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_map_fun23917_1(kk_function_t _fself, kk_box_t _b_22188, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_map_fun23917_1(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_map_fun23917_1, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_core_map_fun23917_1(kk_function_t _fself, kk_box_t _b_22188, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core_types__either _x23918 = kk_std_core__mlift21178_map_1(_b_22188, _ctx); /*either<6472,6474>*/
  return kk_std_core_types__either_box(_x23918, _ctx);
}

kk_std_core_types__either kk_std_core_map_1(kk_std_core_types__either e, kk_function_t f, kk_context_t* _ctx) { /* forall<a,b,c,e> (e : either<a,b>, f : (b) -> e c) -> e either<a,c> */ 
  if (kk_std_core_types__is_Right(e)) {
    kk_box_t x = e._cons.Right.right;
    kk_box_t x0_21341 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), f, (f, x, _ctx)); /*6474*/;
    if (kk_yielding(kk_context())) {
      kk_box_drop(x0_21341, _ctx);
      kk_box_t _x23916 = kk_std_core_hnd_yield_extend(kk_std_core_new_map_fun23917_1(_ctx), _ctx); /*3991*/
      return kk_std_core_types__either_unbox(_x23916, _ctx);
    }
    return kk_std_core_types__new_Right(x0_21341, _ctx);
  }
  kk_box_t x00 = e._cons.Left.left;
  kk_function_drop(f, _ctx);
  return kk_std_core_types__new_Left(x00, _ctx);
}
 
// monadic lift

kk_std_core_types__tuple2_ kk_std_core__mlift21179_map_2(kk_box_t _y_63, kk_box_t _y_64, kk_context_t* _ctx) { /* forall<a,e> (a, a) -> e (a, a) */ 
  return kk_std_core_types__new_dash__lp__comma__rp_(_y_63, _y_64, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_core__mlift21180_map_fun23921__t_2 {
  struct kk_function_s _base;
  kk_box_t _y_63;
};
static kk_box_t kk_std_core__mlift21180_map_fun23921_2(kk_function_t _fself, kk_box_t _b_22192, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_mlift21180_map_fun23921_2(kk_box_t _y_63, kk_context_t* _ctx) {
  struct kk_std_core__mlift21180_map_fun23921__t_2* _self = kk_function_alloc_as(struct kk_std_core__mlift21180_map_fun23921__t_2, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__mlift21180_map_fun23921_2, kk_context());
  _self->_y_63 = _y_63;
  return &_self->_base;
}

static kk_box_t kk_std_core__mlift21180_map_fun23921_2(kk_function_t _fself, kk_box_t _b_22192, kk_context_t* _ctx) {
  struct kk_std_core__mlift21180_map_fun23921__t_2* _self = kk_function_as(struct kk_std_core__mlift21180_map_fun23921__t_2*, _fself);
  kk_box_t _y_63 = _self->_y_63; /* 6635 */
  kk_drop_match(_self, {kk_box_dup(_y_63);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x23922 = kk_std_core__mlift21179_map_2(_y_63, _b_22192, _ctx); /*(6635, 6635)*/
  return kk_std_core_types__tuple2__box(_x23922, _ctx);
}

kk_std_core_types__tuple2_ kk_std_core__mlift21180_map_2(kk_function_t f, kk_std_core_types__tuple2_ t, kk_box_t _y_63, kk_context_t* _ctx) { /* forall<a,b,e> (f : (a) -> e b, t : (a, a), b) -> e (b, b) */ 
  kk_box_t x_21345;
  kk_box_t _x23919;
  kk_box_t _x = t.snd;
  kk_box_dup(_x);
  kk_std_core_types__tuple2__drop(t, _ctx);
  _x23919 = _x; /*6634*/
  x_21345 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), f, (f, _x23919, _ctx)); /*6635*/
  if (kk_yielding(kk_context())) {
    kk_box_drop(x_21345, _ctx);
    kk_box_t _x23920 = kk_std_core_hnd_yield_extend(kk_std_core__new_mlift21180_map_fun23921_2(_y_63, _ctx), _ctx); /*3991*/
    return kk_std_core_types__tuple2__unbox(_x23920, _ctx);
  }
  return kk_std_core__mlift21179_map_2(_y_63, x_21345, _ctx);
}


// lift anonymous function
struct kk_std_core_map_fun23926__t_2 {
  struct kk_function_s _base;
  kk_function_t f;
  kk_std_core_types__tuple2_ t;
};
static kk_box_t kk_std_core_map_fun23926_2(kk_function_t _fself, kk_box_t _b_22196, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_map_fun23926_2(kk_function_t f, kk_std_core_types__tuple2_ t, kk_context_t* _ctx) {
  struct kk_std_core_map_fun23926__t_2* _self = kk_function_alloc_as(struct kk_std_core_map_fun23926__t_2, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_map_fun23926_2, kk_context());
  _self->f = f;
  _self->t = t;
  return &_self->_base;
}

static kk_box_t kk_std_core_map_fun23926_2(kk_function_t _fself, kk_box_t _b_22196, kk_context_t* _ctx) {
  struct kk_std_core_map_fun23926__t_2* _self = kk_function_as(struct kk_std_core_map_fun23926__t_2*, _fself);
  kk_function_t f = _self->f; /* (6634) -> 6636 6635 */
  kk_std_core_types__tuple2_ t = _self->t; /* (6634, 6634) */
  kk_drop_match(_self, {kk_function_dup(f);kk_std_core_types__tuple2__dup(t);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x23927 = kk_std_core__mlift21180_map_2(f, t, _b_22196, _ctx); /*(6635, 6635)*/
  return kk_std_core_types__tuple2__box(_x23927, _ctx);
}


// lift anonymous function
struct kk_std_core_map_fun23930__t_2 {
  struct kk_function_s _base;
  kk_box_t x_21348;
};
static kk_box_t kk_std_core_map_fun23930_2(kk_function_t _fself, kk_box_t _b_22198, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_map_fun23930_2(kk_box_t x_21348, kk_context_t* _ctx) {
  struct kk_std_core_map_fun23930__t_2* _self = kk_function_alloc_as(struct kk_std_core_map_fun23930__t_2, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_map_fun23930_2, kk_context());
  _self->x_21348 = x_21348;
  return &_self->_base;
}

static kk_box_t kk_std_core_map_fun23930_2(kk_function_t _fself, kk_box_t _b_22198, kk_context_t* _ctx) {
  struct kk_std_core_map_fun23930__t_2* _self = kk_function_as(struct kk_std_core_map_fun23930__t_2*, _fself);
  kk_box_t x_21348 = _self->x_21348; /* 6635 */
  kk_drop_match(_self, {kk_box_dup(x_21348);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x23931 = kk_std_core__mlift21179_map_2(x_21348, _b_22198, _ctx); /*(6635, 6635)*/
  return kk_std_core_types__tuple2__box(_x23931, _ctx);
}

kk_std_core_types__tuple2_ kk_std_core_map_2(kk_std_core_types__tuple2_ t, kk_function_t f, kk_context_t* _ctx) { /* forall<a,b,e> (t : (a, a), f : (a) -> e b) -> e (b, b) */ 
  kk_box_t x_21348;
  kk_function_t _x23924 = kk_function_dup(f); /*(6634) -> 6636 6635*/
  kk_box_t _x23923;
  kk_box_t _x = t.fst;
  kk_box_dup(_x);
  _x23923 = _x; /*6634*/
  x_21348 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x23924, (_x23924, _x23923, _ctx)); /*6635*/
  if (kk_yielding(kk_context())) {
    kk_box_drop(x_21348, _ctx);
    kk_box_t _x23925 = kk_std_core_hnd_yield_extend(kk_std_core_new_map_fun23926_2(f, t, _ctx), _ctx); /*3991*/
    return kk_std_core_types__tuple2__unbox(_x23925, _ctx);
  }
  kk_box_t x0_21353;
  kk_box_t _x23928;
  kk_box_t _x0 = t.snd;
  kk_box_dup(_x0);
  kk_std_core_types__tuple2__drop(t, _ctx);
  _x23928 = _x0; /*6634*/
  x0_21353 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), f, (f, _x23928, _ctx)); /*6635*/
  if (kk_yielding(kk_context())) {
    kk_box_drop(x0_21353, _ctx);
    kk_box_t _x23929 = kk_std_core_hnd_yield_extend(kk_std_core_new_map_fun23930_2(x_21348, _ctx), _ctx); /*3991*/
    return kk_std_core_types__tuple2__unbox(_x23929, _ctx);
  }
  return kk_std_core_types__new_dash__lp__comma__rp_(x_21348, x0_21353, _ctx);
}
 
// monadic lift

kk_std_core_types__tuple3_ kk_std_core__mlift21181_map_3(kk_box_t _y_65, kk_box_t _y_66, kk_box_t _y_67, kk_context_t* _ctx) { /* forall<a,e> (a, a, a) -> e (a, a, a) */ 
  return kk_std_core_types__new_dash__lp__comma__comma__rp_(_y_65, _y_66, _y_67, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_core__mlift21182_map_fun23934__t_3 {
  struct kk_function_s _base;
  kk_box_t _y_65;
  kk_box_t _y_66;
};
static kk_box_t kk_std_core__mlift21182_map_fun23934_3(kk_function_t _fself, kk_box_t _b_22204, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_mlift21182_map_fun23934_3(kk_box_t _y_65, kk_box_t _y_66, kk_context_t* _ctx) {
  struct kk_std_core__mlift21182_map_fun23934__t_3* _self = kk_function_alloc_as(struct kk_std_core__mlift21182_map_fun23934__t_3, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__mlift21182_map_fun23934_3, kk_context());
  _self->_y_65 = _y_65;
  _self->_y_66 = _y_66;
  return &_self->_base;
}

static kk_box_t kk_std_core__mlift21182_map_fun23934_3(kk_function_t _fself, kk_box_t _b_22204, kk_context_t* _ctx) {
  struct kk_std_core__mlift21182_map_fun23934__t_3* _self = kk_function_as(struct kk_std_core__mlift21182_map_fun23934__t_3*, _fself);
  kk_box_t _y_65 = _self->_y_65; /* 6875 */
  kk_box_t _y_66 = _self->_y_66; /* 6875 */
  kk_drop_match(_self, {kk_box_dup(_y_65);kk_box_dup(_y_66);}, {}, _ctx)
  kk_std_core_types__tuple3_ _x23935 = kk_std_core__mlift21181_map_3(_y_65, _y_66, _b_22204, _ctx); /*(6875, 6875, 6875)*/
  return kk_std_core_types__tuple3__box(_x23935, _ctx);
}

kk_std_core_types__tuple3_ kk_std_core__mlift21182_map_3(kk_box_t _y_65, kk_function_t f, kk_std_core_types__tuple3_ t, kk_box_t _y_66, kk_context_t* _ctx) { /* forall<a,b,e> (b, f : (a) -> e b, t : (a, a, a), b) -> e (b, b, b) */ 
  kk_box_t x_21358;
  kk_box_t _x23932;
  kk_box_t _x = t.thd;
  kk_box_dup(_x);
  kk_std_core_types__tuple3__drop(t, _ctx);
  _x23932 = _x; /*6874*/
  x_21358 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), f, (f, _x23932, _ctx)); /*6875*/
  if (kk_yielding(kk_context())) {
    kk_box_drop(x_21358, _ctx);
    kk_box_t _x23933 = kk_std_core_hnd_yield_extend(kk_std_core__new_mlift21182_map_fun23934_3(_y_65, _y_66, _ctx), _ctx); /*3991*/
    return kk_std_core_types__tuple3__unbox(_x23933, _ctx);
  }
  return kk_std_core__mlift21181_map_3(_y_65, _y_66, x_21358, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_core__mlift21183_map_fun23939__t_3 {
  struct kk_function_s _base;
  kk_box_t _y_65;
  kk_function_t f;
  kk_std_core_types__tuple3_ t;
};
static kk_box_t kk_std_core__mlift21183_map_fun23939_3(kk_function_t _fself, kk_box_t _b_22208, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_mlift21183_map_fun23939_3(kk_box_t _y_65, kk_function_t f, kk_std_core_types__tuple3_ t, kk_context_t* _ctx) {
  struct kk_std_core__mlift21183_map_fun23939__t_3* _self = kk_function_alloc_as(struct kk_std_core__mlift21183_map_fun23939__t_3, 6, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__mlift21183_map_fun23939_3, kk_context());
  _self->_y_65 = _y_65;
  _self->f = f;
  _self->t = t;
  return &_self->_base;
}

static kk_box_t kk_std_core__mlift21183_map_fun23939_3(kk_function_t _fself, kk_box_t _b_22208, kk_context_t* _ctx) {
  struct kk_std_core__mlift21183_map_fun23939__t_3* _self = kk_function_as(struct kk_std_core__mlift21183_map_fun23939__t_3*, _fself);
  kk_box_t _y_65 = _self->_y_65; /* 6875 */
  kk_function_t f = _self->f; /* (6874) -> 6876 6875 */
  kk_std_core_types__tuple3_ t = _self->t; /* (6874, 6874, 6874) */
  kk_drop_match(_self, {kk_box_dup(_y_65);kk_function_dup(f);kk_std_core_types__tuple3__dup(t);}, {}, _ctx)
  kk_std_core_types__tuple3_ _x23940 = kk_std_core__mlift21182_map_3(_y_65, f, t, _b_22208, _ctx); /*(6875, 6875, 6875)*/
  return kk_std_core_types__tuple3__box(_x23940, _ctx);
}

kk_std_core_types__tuple3_ kk_std_core__mlift21183_map_3(kk_function_t f, kk_std_core_types__tuple3_ t, kk_box_t _y_65, kk_context_t* _ctx) { /* forall<a,b,e> (f : (a) -> e b, t : (a, a, a), b) -> e (b, b, b) */ 
  kk_box_t x_21361;
  kk_function_t _x23937 = kk_function_dup(f); /*(6874) -> 6876 6875*/
  kk_box_t _x23936;
  kk_box_t _x = t.snd;
  kk_box_dup(_x);
  _x23936 = _x; /*6874*/
  x_21361 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x23937, (_x23937, _x23936, _ctx)); /*6875*/
  if (kk_yielding(kk_context())) {
    kk_box_drop(x_21361, _ctx);
    kk_box_t _x23938 = kk_std_core_hnd_yield_extend(kk_std_core__new_mlift21183_map_fun23939_3(_y_65, f, t, _ctx), _ctx); /*3991*/
    return kk_std_core_types__tuple3__unbox(_x23938, _ctx);
  }
  return kk_std_core__mlift21182_map_3(_y_65, f, t, x_21361, _ctx);
}


// lift anonymous function
struct kk_std_core_map_fun23944__t_3 {
  struct kk_function_s _base;
  kk_function_t f;
  kk_std_core_types__tuple3_ t;
};
static kk_box_t kk_std_core_map_fun23944_3(kk_function_t _fself, kk_box_t _b_22212, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_map_fun23944_3(kk_function_t f, kk_std_core_types__tuple3_ t, kk_context_t* _ctx) {
  struct kk_std_core_map_fun23944__t_3* _self = kk_function_alloc_as(struct kk_std_core_map_fun23944__t_3, 5, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_map_fun23944_3, kk_context());
  _self->f = f;
  _self->t = t;
  return &_self->_base;
}

static kk_box_t kk_std_core_map_fun23944_3(kk_function_t _fself, kk_box_t _b_22212, kk_context_t* _ctx) {
  struct kk_std_core_map_fun23944__t_3* _self = kk_function_as(struct kk_std_core_map_fun23944__t_3*, _fself);
  kk_function_t f = _self->f; /* (6874) -> 6876 6875 */
  kk_std_core_types__tuple3_ t = _self->t; /* (6874, 6874, 6874) */
  kk_drop_match(_self, {kk_function_dup(f);kk_std_core_types__tuple3__dup(t);}, {}, _ctx)
  kk_std_core_types__tuple3_ _x23945 = kk_std_core__mlift21183_map_3(f, t, _b_22212, _ctx); /*(6875, 6875, 6875)*/
  return kk_std_core_types__tuple3__box(_x23945, _ctx);
}


// lift anonymous function
struct kk_std_core_map_fun23949__t_3 {
  struct kk_function_s _base;
  kk_function_t f;
  kk_std_core_types__tuple3_ t;
  kk_box_t x_21364;
};
static kk_box_t kk_std_core_map_fun23949_3(kk_function_t _fself, kk_box_t _b_22214, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_map_fun23949_3(kk_function_t f, kk_std_core_types__tuple3_ t, kk_box_t x_21364, kk_context_t* _ctx) {
  struct kk_std_core_map_fun23949__t_3* _self = kk_function_alloc_as(struct kk_std_core_map_fun23949__t_3, 6, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_map_fun23949_3, kk_context());
  _self->f = f;
  _self->t = t;
  _self->x_21364 = x_21364;
  return &_self->_base;
}

static kk_box_t kk_std_core_map_fun23949_3(kk_function_t _fself, kk_box_t _b_22214, kk_context_t* _ctx) {
  struct kk_std_core_map_fun23949__t_3* _self = kk_function_as(struct kk_std_core_map_fun23949__t_3*, _fself);
  kk_function_t f = _self->f; /* (6874) -> 6876 6875 */
  kk_std_core_types__tuple3_ t = _self->t; /* (6874, 6874, 6874) */
  kk_box_t x_21364 = _self->x_21364; /* 6875 */
  kk_drop_match(_self, {kk_function_dup(f);kk_std_core_types__tuple3__dup(t);kk_box_dup(x_21364);}, {}, _ctx)
  kk_std_core_types__tuple3_ _x23950 = kk_std_core__mlift21182_map_3(x_21364, f, t, _b_22214, _ctx); /*(6875, 6875, 6875)*/
  return kk_std_core_types__tuple3__box(_x23950, _ctx);
}


// lift anonymous function
struct kk_std_core_map_fun23953__t_3 {
  struct kk_function_s _base;
  kk_box_t x_21364;
  kk_box_t x0_21369;
};
static kk_box_t kk_std_core_map_fun23953_3(kk_function_t _fself, kk_box_t _b_22216, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_map_fun23953_3(kk_box_t x_21364, kk_box_t x0_21369, kk_context_t* _ctx) {
  struct kk_std_core_map_fun23953__t_3* _self = kk_function_alloc_as(struct kk_std_core_map_fun23953__t_3, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_map_fun23953_3, kk_context());
  _self->x_21364 = x_21364;
  _self->x0_21369 = x0_21369;
  return &_self->_base;
}

static kk_box_t kk_std_core_map_fun23953_3(kk_function_t _fself, kk_box_t _b_22216, kk_context_t* _ctx) {
  struct kk_std_core_map_fun23953__t_3* _self = kk_function_as(struct kk_std_core_map_fun23953__t_3*, _fself);
  kk_box_t x_21364 = _self->x_21364; /* 6875 */
  kk_box_t x0_21369 = _self->x0_21369; /* 6875 */
  kk_drop_match(_self, {kk_box_dup(x_21364);kk_box_dup(x0_21369);}, {}, _ctx)
  kk_std_core_types__tuple3_ _x23954 = kk_std_core__mlift21181_map_3(x_21364, x0_21369, _b_22216, _ctx); /*(6875, 6875, 6875)*/
  return kk_std_core_types__tuple3__box(_x23954, _ctx);
}

kk_std_core_types__tuple3_ kk_std_core_map_3(kk_std_core_types__tuple3_ t, kk_function_t f, kk_context_t* _ctx) { /* forall<a,b,e> (t : (a, a, a), f : (a) -> e b) -> e (b, b, b) */ 
  kk_box_t x_21364;
  kk_function_t _x23942 = kk_function_dup(f); /*(6874) -> 6876 6875*/
  kk_box_t _x23941;
  kk_box_t _x = t.fst;
  kk_box_dup(_x);
  _x23941 = _x; /*6874*/
  x_21364 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x23942, (_x23942, _x23941, _ctx)); /*6875*/
  if (kk_yielding(kk_context())) {
    kk_box_drop(x_21364, _ctx);
    kk_box_t _x23943 = kk_std_core_hnd_yield_extend(kk_std_core_new_map_fun23944_3(f, t, _ctx), _ctx); /*3991*/
    return kk_std_core_types__tuple3__unbox(_x23943, _ctx);
  }
  kk_box_t x0_21369;
  kk_function_t _x23947 = kk_function_dup(f); /*(6874) -> 6876 6875*/
  kk_box_t _x23946;
  kk_box_t _x0 = t.snd;
  kk_box_dup(_x0);
  _x23946 = _x0; /*6874*/
  x0_21369 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x23947, (_x23947, _x23946, _ctx)); /*6875*/
  if (kk_yielding(kk_context())) {
    kk_box_drop(x0_21369, _ctx);
    kk_box_t _x23948 = kk_std_core_hnd_yield_extend(kk_std_core_new_map_fun23949_3(f, t, x_21364, _ctx), _ctx); /*3991*/
    return kk_std_core_types__tuple3__unbox(_x23948, _ctx);
  }
  kk_box_t x1_21374;
  kk_box_t _x23951;
  kk_box_t _x1 = t.thd;
  kk_box_dup(_x1);
  kk_std_core_types__tuple3__drop(t, _ctx);
  _x23951 = _x1; /*6874*/
  x1_21374 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), f, (f, _x23951, _ctx)); /*6875*/
  if (kk_yielding(kk_context())) {
    kk_box_drop(x1_21374, _ctx);
    kk_box_t _x23952 = kk_std_core_hnd_yield_extend(kk_std_core_new_map_fun23953_3(x_21364, x0_21369, _ctx), _ctx); /*3991*/
    return kk_std_core_types__tuple3__unbox(_x23952, _ctx);
  }
  return kk_std_core_types__new_dash__lp__comma__comma__rp_(x_21364, x0_21369, x1_21374, _ctx);
}
 
// monadic lift

kk_std_core_types__tuple4_ kk_std_core__mlift21184_map_4(kk_box_t _y_68, kk_box_t _y_69, kk_box_t _y_70, kk_box_t _y_71, kk_context_t* _ctx) { /* forall<a,e> (a, a, a, a) -> e (a, a, a, a) */ 
  return kk_std_core_types__new_dash__lp__comma__comma__comma__rp_(kk_reuse_null, _y_68, _y_69, _y_70, _y_71, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_core__mlift21185_map_fun23958__t_4 {
  struct kk_function_s _base;
  kk_box_t _y_68;
  kk_box_t _y_69;
  kk_box_t _y_70;
};
static kk_box_t kk_std_core__mlift21185_map_fun23958_4(kk_function_t _fself, kk_box_t _b_22224, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_mlift21185_map_fun23958_4(kk_box_t _y_68, kk_box_t _y_69, kk_box_t _y_70, kk_context_t* _ctx) {
  struct kk_std_core__mlift21185_map_fun23958__t_4* _self = kk_function_alloc_as(struct kk_std_core__mlift21185_map_fun23958__t_4, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__mlift21185_map_fun23958_4, kk_context());
  _self->_y_68 = _y_68;
  _self->_y_69 = _y_69;
  _self->_y_70 = _y_70;
  return &_self->_base;
}

static kk_box_t kk_std_core__mlift21185_map_fun23958_4(kk_function_t _fself, kk_box_t _b_22224, kk_context_t* _ctx) {
  struct kk_std_core__mlift21185_map_fun23958__t_4* _self = kk_function_as(struct kk_std_core__mlift21185_map_fun23958__t_4*, _fself);
  kk_box_t _y_68 = _self->_y_68; /* 7188 */
  kk_box_t _y_69 = _self->_y_69; /* 7188 */
  kk_box_t _y_70 = _self->_y_70; /* 7188 */
  kk_drop_match(_self, {kk_box_dup(_y_68);kk_box_dup(_y_69);kk_box_dup(_y_70);}, {}, _ctx)
  kk_std_core_types__tuple4_ _x23959 = kk_std_core__mlift21184_map_4(_y_68, _y_69, _y_70, _b_22224, _ctx); /*(7188, 7188, 7188, 7188)*/
  return kk_std_core_types__tuple4__box(_x23959, _ctx);
}

kk_std_core_types__tuple4_ kk_std_core__mlift21185_map_4(kk_box_t _y_68, kk_box_t _y_69, kk_function_t f, kk_std_core_types__tuple4_ t, kk_box_t _y_70, kk_context_t* _ctx) { /* forall<a,b,e> (b, b, f : (a) -> e b, t : (a, a, a, a), b) -> e (b, b, b, b) */ 
  kk_box_t x_21379;
  kk_box_t _x23955;
  struct kk_std_core_types__Tuple4_* _con23956 = kk_std_core_types__as_dash__lp__comma__comma__comma__rp_(t);
  kk_box_t _pat00 = _con23956->fst;
  kk_box_t _pat10 = _con23956->snd;
  kk_box_t _pat2 = _con23956->thd;
  kk_box_t _x = _con23956->field4;
  if (kk_std_core_types__tuple4__is_unique(t)) {
    kk_box_drop(_pat2, _ctx);
    kk_box_drop(_pat10, _ctx);
    kk_box_drop(_pat00, _ctx);
    kk_std_core_types__tuple4__free(t);
  }
  else {
    kk_box_dup(_x);
    kk_std_core_types__tuple4__decref(t, _ctx);
  }
  _x23955 = _x; /*7187*/
  x_21379 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), f, (f, _x23955, _ctx)); /*7188*/
  if (kk_yielding(kk_context())) {
    kk_box_drop(x_21379, _ctx);
    kk_box_t _x23957 = kk_std_core_hnd_yield_extend(kk_std_core__new_mlift21185_map_fun23958_4(_y_68, _y_69, _y_70, _ctx), _ctx); /*3991*/
    return kk_std_core_types__tuple4__unbox(_x23957, _ctx);
  }
  return kk_std_core__mlift21184_map_4(_y_68, _y_69, _y_70, x_21379, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_core__mlift21186_map_fun23964__t_4 {
  struct kk_function_s _base;
  kk_box_t _y_68;
  kk_box_t _y_69;
  kk_function_t f;
  kk_std_core_types__tuple4_ t;
};
static kk_box_t kk_std_core__mlift21186_map_fun23964_4(kk_function_t _fself, kk_box_t _b_22228, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_mlift21186_map_fun23964_4(kk_box_t _y_68, kk_box_t _y_69, kk_function_t f, kk_std_core_types__tuple4_ t, kk_context_t* _ctx) {
  struct kk_std_core__mlift21186_map_fun23964__t_4* _self = kk_function_alloc_as(struct kk_std_core__mlift21186_map_fun23964__t_4, 5, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__mlift21186_map_fun23964_4, kk_context());
  _self->_y_68 = _y_68;
  _self->_y_69 = _y_69;
  _self->f = f;
  _self->t = t;
  return &_self->_base;
}

static kk_box_t kk_std_core__mlift21186_map_fun23964_4(kk_function_t _fself, kk_box_t _b_22228, kk_context_t* _ctx) {
  struct kk_std_core__mlift21186_map_fun23964__t_4* _self = kk_function_as(struct kk_std_core__mlift21186_map_fun23964__t_4*, _fself);
  kk_box_t _y_68 = _self->_y_68; /* 7188 */
  kk_box_t _y_69 = _self->_y_69; /* 7188 */
  kk_function_t f = _self->f; /* (7187) -> 7189 7188 */
  kk_std_core_types__tuple4_ t = _self->t; /* (7187, 7187, 7187, 7187) */
  kk_drop_match(_self, {kk_box_dup(_y_68);kk_box_dup(_y_69);kk_function_dup(f);kk_std_core_types__tuple4__dup(t);}, {}, _ctx)
  kk_std_core_types__tuple4_ _x23965 = kk_std_core__mlift21185_map_4(_y_68, _y_69, f, t, _b_22228, _ctx); /*(7188, 7188, 7188, 7188)*/
  return kk_std_core_types__tuple4__box(_x23965, _ctx);
}

kk_std_core_types__tuple4_ kk_std_core__mlift21186_map_4(kk_box_t _y_68, kk_function_t f, kk_std_core_types__tuple4_ t, kk_box_t _y_69, kk_context_t* _ctx) { /* forall<a,b,e> (b, f : (a) -> e b, t : (a, a, a, a), b) -> e (b, b, b, b) */ 
  kk_box_t x_21382;
  kk_function_t _x23962 = kk_function_dup(f); /*(7187) -> 7189 7188*/
  kk_box_t _x23960;
  struct kk_std_core_types__Tuple4_* _con23961 = kk_std_core_types__as_dash__lp__comma__comma__comma__rp_(t);
  kk_box_t _x = _con23961->thd;
  kk_box_dup(_x);
  _x23960 = _x; /*7187*/
  x_21382 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x23962, (_x23962, _x23960, _ctx)); /*7188*/
  if (kk_yielding(kk_context())) {
    kk_box_drop(x_21382, _ctx);
    kk_box_t _x23963 = kk_std_core_hnd_yield_extend(kk_std_core__new_mlift21186_map_fun23964_4(_y_68, _y_69, f, t, _ctx), _ctx); /*3991*/
    return kk_std_core_types__tuple4__unbox(_x23963, _ctx);
  }
  return kk_std_core__mlift21185_map_4(_y_68, _y_69, f, t, x_21382, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_core__mlift21187_map_fun23970__t_4 {
  struct kk_function_s _base;
  kk_box_t _y_68;
  kk_function_t f;
  kk_std_core_types__tuple4_ t;
};
static kk_box_t kk_std_core__mlift21187_map_fun23970_4(kk_function_t _fself, kk_box_t _b_22232, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_mlift21187_map_fun23970_4(kk_box_t _y_68, kk_function_t f, kk_std_core_types__tuple4_ t, kk_context_t* _ctx) {
  struct kk_std_core__mlift21187_map_fun23970__t_4* _self = kk_function_alloc_as(struct kk_std_core__mlift21187_map_fun23970__t_4, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__mlift21187_map_fun23970_4, kk_context());
  _self->_y_68 = _y_68;
  _self->f = f;
  _self->t = t;
  return &_self->_base;
}

static kk_box_t kk_std_core__mlift21187_map_fun23970_4(kk_function_t _fself, kk_box_t _b_22232, kk_context_t* _ctx) {
  struct kk_std_core__mlift21187_map_fun23970__t_4* _self = kk_function_as(struct kk_std_core__mlift21187_map_fun23970__t_4*, _fself);
  kk_box_t _y_68 = _self->_y_68; /* 7188 */
  kk_function_t f = _self->f; /* (7187) -> 7189 7188 */
  kk_std_core_types__tuple4_ t = _self->t; /* (7187, 7187, 7187, 7187) */
  kk_drop_match(_self, {kk_box_dup(_y_68);kk_function_dup(f);kk_std_core_types__tuple4__dup(t);}, {}, _ctx)
  kk_std_core_types__tuple4_ _x23971 = kk_std_core__mlift21186_map_4(_y_68, f, t, _b_22232, _ctx); /*(7188, 7188, 7188, 7188)*/
  return kk_std_core_types__tuple4__box(_x23971, _ctx);
}

kk_std_core_types__tuple4_ kk_std_core__mlift21187_map_4(kk_function_t f, kk_std_core_types__tuple4_ t, kk_box_t _y_68, kk_context_t* _ctx) { /* forall<a,b,e> (f : (a) -> e b, t : (a, a, a, a), b) -> e (b, b, b, b) */ 
  kk_box_t x_21385;
  kk_function_t _x23968 = kk_function_dup(f); /*(7187) -> 7189 7188*/
  kk_box_t _x23966;
  struct kk_std_core_types__Tuple4_* _con23967 = kk_std_core_types__as_dash__lp__comma__comma__comma__rp_(t);
  kk_box_t _x = _con23967->snd;
  kk_box_dup(_x);
  _x23966 = _x; /*7187*/
  x_21385 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x23968, (_x23968, _x23966, _ctx)); /*7188*/
  if (kk_yielding(kk_context())) {
    kk_box_drop(x_21385, _ctx);
    kk_box_t _x23969 = kk_std_core_hnd_yield_extend(kk_std_core__new_mlift21187_map_fun23970_4(_y_68, f, t, _ctx), _ctx); /*3991*/
    return kk_std_core_types__tuple4__unbox(_x23969, _ctx);
  }
  return kk_std_core__mlift21186_map_4(_y_68, f, t, x_21385, _ctx);
}


// lift anonymous function
struct kk_std_core_map_fun23976__t_4 {
  struct kk_function_s _base;
  kk_function_t f;
  kk_std_core_types__tuple4_ t;
};
static kk_box_t kk_std_core_map_fun23976_4(kk_function_t _fself, kk_box_t _b_22236, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_map_fun23976_4(kk_function_t f, kk_std_core_types__tuple4_ t, kk_context_t* _ctx) {
  struct kk_std_core_map_fun23976__t_4* _self = kk_function_alloc_as(struct kk_std_core_map_fun23976__t_4, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_map_fun23976_4, kk_context());
  _self->f = f;
  _self->t = t;
  return &_self->_base;
}

static kk_box_t kk_std_core_map_fun23976_4(kk_function_t _fself, kk_box_t _b_22236, kk_context_t* _ctx) {
  struct kk_std_core_map_fun23976__t_4* _self = kk_function_as(struct kk_std_core_map_fun23976__t_4*, _fself);
  kk_function_t f = _self->f; /* (7187) -> 7189 7188 */
  kk_std_core_types__tuple4_ t = _self->t; /* (7187, 7187, 7187, 7187) */
  kk_drop_match(_self, {kk_function_dup(f);kk_std_core_types__tuple4__dup(t);}, {}, _ctx)
  kk_std_core_types__tuple4_ _x23977 = kk_std_core__mlift21187_map_4(f, t, _b_22236, _ctx); /*(7188, 7188, 7188, 7188)*/
  return kk_std_core_types__tuple4__box(_x23977, _ctx);
}


// lift anonymous function
struct kk_std_core_map_fun23982__t_4 {
  struct kk_function_s _base;
  kk_function_t f;
  kk_std_core_types__tuple4_ t;
  kk_box_t x_21388;
};
static kk_box_t kk_std_core_map_fun23982_4(kk_function_t _fself, kk_box_t _b_22238, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_map_fun23982_4(kk_function_t f, kk_std_core_types__tuple4_ t, kk_box_t x_21388, kk_context_t* _ctx) {
  struct kk_std_core_map_fun23982__t_4* _self = kk_function_alloc_as(struct kk_std_core_map_fun23982__t_4, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_map_fun23982_4, kk_context());
  _self->f = f;
  _self->t = t;
  _self->x_21388 = x_21388;
  return &_self->_base;
}

static kk_box_t kk_std_core_map_fun23982_4(kk_function_t _fself, kk_box_t _b_22238, kk_context_t* _ctx) {
  struct kk_std_core_map_fun23982__t_4* _self = kk_function_as(struct kk_std_core_map_fun23982__t_4*, _fself);
  kk_function_t f = _self->f; /* (7187) -> 7189 7188 */
  kk_std_core_types__tuple4_ t = _self->t; /* (7187, 7187, 7187, 7187) */
  kk_box_t x_21388 = _self->x_21388; /* 7188 */
  kk_drop_match(_self, {kk_function_dup(f);kk_std_core_types__tuple4__dup(t);kk_box_dup(x_21388);}, {}, _ctx)
  kk_std_core_types__tuple4_ _x23983 = kk_std_core__mlift21186_map_4(x_21388, f, t, _b_22238, _ctx); /*(7188, 7188, 7188, 7188)*/
  return kk_std_core_types__tuple4__box(_x23983, _ctx);
}


// lift anonymous function
struct kk_std_core_map_fun23988__t_4 {
  struct kk_function_s _base;
  kk_function_t f;
  kk_std_core_types__tuple4_ t;
  kk_box_t x_21388;
  kk_box_t x0_21393;
};
static kk_box_t kk_std_core_map_fun23988_4(kk_function_t _fself, kk_box_t _b_22240, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_map_fun23988_4(kk_function_t f, kk_std_core_types__tuple4_ t, kk_box_t x_21388, kk_box_t x0_21393, kk_context_t* _ctx) {
  struct kk_std_core_map_fun23988__t_4* _self = kk_function_alloc_as(struct kk_std_core_map_fun23988__t_4, 5, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_map_fun23988_4, kk_context());
  _self->f = f;
  _self->t = t;
  _self->x_21388 = x_21388;
  _self->x0_21393 = x0_21393;
  return &_self->_base;
}

static kk_box_t kk_std_core_map_fun23988_4(kk_function_t _fself, kk_box_t _b_22240, kk_context_t* _ctx) {
  struct kk_std_core_map_fun23988__t_4* _self = kk_function_as(struct kk_std_core_map_fun23988__t_4*, _fself);
  kk_function_t f = _self->f; /* (7187) -> 7189 7188 */
  kk_std_core_types__tuple4_ t = _self->t; /* (7187, 7187, 7187, 7187) */
  kk_box_t x_21388 = _self->x_21388; /* 7188 */
  kk_box_t x0_21393 = _self->x0_21393; /* 7188 */
  kk_drop_match(_self, {kk_function_dup(f);kk_std_core_types__tuple4__dup(t);kk_box_dup(x_21388);kk_box_dup(x0_21393);}, {}, _ctx)
  kk_std_core_types__tuple4_ _x23989 = kk_std_core__mlift21185_map_4(x_21388, x0_21393, f, t, _b_22240, _ctx); /*(7188, 7188, 7188, 7188)*/
  return kk_std_core_types__tuple4__box(_x23989, _ctx);
}


// lift anonymous function
struct kk_std_core_map_fun23993__t_4 {
  struct kk_function_s _base;
  kk_box_t x_21388;
  kk_box_t x0_21393;
  kk_box_t x1_21398;
};
static kk_box_t kk_std_core_map_fun23993_4(kk_function_t _fself, kk_box_t _b_22242, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_map_fun23993_4(kk_box_t x_21388, kk_box_t x0_21393, kk_box_t x1_21398, kk_context_t* _ctx) {
  struct kk_std_core_map_fun23993__t_4* _self = kk_function_alloc_as(struct kk_std_core_map_fun23993__t_4, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_map_fun23993_4, kk_context());
  _self->x_21388 = x_21388;
  _self->x0_21393 = x0_21393;
  _self->x1_21398 = x1_21398;
  return &_self->_base;
}

static kk_box_t kk_std_core_map_fun23993_4(kk_function_t _fself, kk_box_t _b_22242, kk_context_t* _ctx) {
  struct kk_std_core_map_fun23993__t_4* _self = kk_function_as(struct kk_std_core_map_fun23993__t_4*, _fself);
  kk_box_t x_21388 = _self->x_21388; /* 7188 */
  kk_box_t x0_21393 = _self->x0_21393; /* 7188 */
  kk_box_t x1_21398 = _self->x1_21398; /* 7188 */
  kk_drop_match(_self, {kk_box_dup(x_21388);kk_box_dup(x0_21393);kk_box_dup(x1_21398);}, {}, _ctx)
  kk_std_core_types__tuple4_ _x23994 = kk_std_core__mlift21184_map_4(x_21388, x0_21393, x1_21398, _b_22242, _ctx); /*(7188, 7188, 7188, 7188)*/
  return kk_std_core_types__tuple4__box(_x23994, _ctx);
}

kk_std_core_types__tuple4_ kk_std_core_map_4(kk_std_core_types__tuple4_ t, kk_function_t f, kk_context_t* _ctx) { /* forall<a,b,e> (t : (a, a, a, a), f : (a) -> e b) -> e (b, b, b, b) */ 
  kk_box_t x_21388;
  kk_function_t _x23974 = kk_function_dup(f); /*(7187) -> 7189 7188*/
  kk_box_t _x23972;
  struct kk_std_core_types__Tuple4_* _con23973 = kk_std_core_types__as_dash__lp__comma__comma__comma__rp_(t);
  kk_box_t _x = _con23973->fst;
  kk_box_dup(_x);
  _x23972 = _x; /*7187*/
  x_21388 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x23974, (_x23974, _x23972, _ctx)); /*7188*/
  if (kk_yielding(kk_context())) {
    kk_box_drop(x_21388, _ctx);
    kk_box_t _x23975 = kk_std_core_hnd_yield_extend(kk_std_core_new_map_fun23976_4(f, t, _ctx), _ctx); /*3991*/
    return kk_std_core_types__tuple4__unbox(_x23975, _ctx);
  }
  kk_box_t x0_21393;
  kk_function_t _x23980 = kk_function_dup(f); /*(7187) -> 7189 7188*/
  kk_box_t _x23978;
  struct kk_std_core_types__Tuple4_* _con23979 = kk_std_core_types__as_dash__lp__comma__comma__comma__rp_(t);
  kk_box_t _x0 = _con23979->snd;
  kk_box_dup(_x0);
  _x23978 = _x0; /*7187*/
  x0_21393 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x23980, (_x23980, _x23978, _ctx)); /*7188*/
  if (kk_yielding(kk_context())) {
    kk_box_drop(x0_21393, _ctx);
    kk_box_t _x23981 = kk_std_core_hnd_yield_extend(kk_std_core_new_map_fun23982_4(f, t, x_21388, _ctx), _ctx); /*3991*/
    return kk_std_core_types__tuple4__unbox(_x23981, _ctx);
  }
  kk_box_t x1_21398;
  kk_function_t _x23986 = kk_function_dup(f); /*(7187) -> 7189 7188*/
  kk_box_t _x23984;
  struct kk_std_core_types__Tuple4_* _con23985 = kk_std_core_types__as_dash__lp__comma__comma__comma__rp_(t);
  kk_box_t _x1 = _con23985->thd;
  kk_box_dup(_x1);
  _x23984 = _x1; /*7187*/
  x1_21398 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x23986, (_x23986, _x23984, _ctx)); /*7188*/
  if (kk_yielding(kk_context())) {
    kk_box_drop(x1_21398, _ctx);
    kk_box_t _x23987 = kk_std_core_hnd_yield_extend(kk_std_core_new_map_fun23988_4(f, t, x_21388, x0_21393, _ctx), _ctx); /*3991*/
    return kk_std_core_types__tuple4__unbox(_x23987, _ctx);
  }
  kk_box_t x2_21403;
  kk_box_t _x23990;
  struct kk_std_core_types__Tuple4_* _con23991 = kk_std_core_types__as_dash__lp__comma__comma__comma__rp_(t);
  kk_box_t _pat06 = _con23991->fst;
  kk_box_t _pat13 = _con23991->snd;
  kk_box_t _pat22 = _con23991->thd;
  kk_box_t _x2 = _con23991->field4;
  if (kk_std_core_types__tuple4__is_unique(t)) {
    kk_box_drop(_pat22, _ctx);
    kk_box_drop(_pat13, _ctx);
    kk_box_drop(_pat06, _ctx);
    kk_std_core_types__tuple4__free(t);
  }
  else {
    kk_box_dup(_x2);
    kk_std_core_types__tuple4__decref(t, _ctx);
  }
  _x23990 = _x2; /*7187*/
  x2_21403 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), f, (f, _x23990, _ctx)); /*7188*/
  if (kk_yielding(kk_context())) {
    kk_box_drop(x2_21403, _ctx);
    kk_box_t _x23992 = kk_std_core_hnd_yield_extend(kk_std_core_new_map_fun23993_4(x_21388, x0_21393, x1_21398, _ctx), _ctx); /*3991*/
    return kk_std_core_types__tuple4__unbox(_x23992, _ctx);
  }
  return kk_std_core_types__new_dash__lp__comma__comma__comma__rp_(kk_reuse_null, x_21388, x0_21393, x1_21398, x2_21403, _ctx);
}
 
// Apply a function `f` to each character in a string


// lift anonymous function
struct kk_std_core_map_fun23995__t_6 {
  struct kk_function_s _base;
  kk_function_t f;
};
static kk_box_t kk_std_core_map_fun23995_6(kk_function_t _fself, kk_box_t _b_22253, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_map_fun23995_6(kk_function_t f, kk_context_t* _ctx) {
  struct kk_std_core_map_fun23995__t_6* _self = kk_function_alloc_as(struct kk_std_core_map_fun23995__t_6, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_map_fun23995_6, kk_context());
  _self->f = f;
  return &_self->_base;
}

static kk_box_t kk_std_core_map_fun23995_6(kk_function_t _fself, kk_box_t _b_22253, kk_context_t* _ctx) {
  struct kk_std_core_map_fun23995__t_6* _self = kk_function_as(struct kk_std_core_map_fun23995__t_6*, _fself);
  kk_function_t f = _self->f; /* (char) -> 7678 char */
  kk_drop_match(_self, {kk_function_dup(f);}, {}, _ctx)
  kk_char_t _x23996;
  kk_char_t _x23997 = kk_char_unbox(_b_22253, _ctx); /*char*/
  _x23996 = kk_function_call(kk_char_t, (kk_function_t, kk_char_t, kk_context_t*), f, (f, _x23997, _ctx)); /*char*/
  return kk_char_box(_x23996, _ctx);
}


// lift anonymous function
struct kk_std_core_map_fun23999__t_6 {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_map_fun23999_6(kk_function_t _fself, kk_box_t _b_22257, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_map_fun23999_6(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_map_fun23999_6, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_core_map_fun23999_6(kk_function_t _fself, kk_box_t _b_22257, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x24000;
  kk_std_core__list _x24001 = kk_std_core__list_unbox(_b_22257, _ctx); /*list<char>*/
  _x24000 = kk_std_core_string_2(_x24001, _ctx); /*string*/
  return kk_string_box(_x24000);
}

kk_string_t kk_std_core_map_6(kk_string_t s, kk_function_t f, kk_context_t* _ctx) { /* forall<e> (s : string, f : (char) -> e char) -> e string */ 
  kk_std_core__list x_21408;
  kk_std_core__list _b_22254_22251 = kk_std_core_list_4(s, _ctx); /*list<char>*/;
  x_21408 = kk_std_core_map_5(_b_22254_22251, kk_std_core_new_map_fun23995_6(f, _ctx), _ctx); /*list<char>*/
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_21408, _ctx);
    kk_box_t _x23998 = kk_std_core_hnd_yield_extend(kk_std_core_new_map_fun23999_6(_ctx), _ctx); /*3991*/
    return kk_string_unbox(_x23998);
  }
  return kk_std_core_string_2(x_21408, _ctx);
}
 
// monadic lift

kk_unit_t kk_std_core__mlift21188_map_7(size_t i, kk_vector_t w, kk_box_t _y_73, kk_context_t* _ctx) { /* forall<a,e> (i : size_t, w : vector<a>, a) -> e () */ 
  kk_vector_unsafe_assign(w,i,_y_73,kk_context()); return kk_Unit;
}
 
// monadic lift

kk_vector_t kk_std_core__mlift21189_map_7(kk_vector_t w, kk_unit_t wild__, kk_context_t* _ctx) { /* forall<a,e> (w : vector<a>, wild_ : ()) -> e vector<a> */ 
  return w;
}
 
// Apply a total function `f` to each element in a vector `v`


// lift anonymous function
struct kk_std_core_map_fun24008__t_7 {
  struct kk_function_s _base;
  kk_function_t f;
  kk_vector_t v;
  kk_vector_t w;
};
static kk_unit_t kk_std_core_map_fun24008_7(kk_function_t _fself, size_t i, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_map_fun24008_7(kk_function_t f, kk_vector_t v, kk_vector_t w, kk_context_t* _ctx) {
  struct kk_std_core_map_fun24008__t_7* _self = kk_function_alloc_as(struct kk_std_core_map_fun24008__t_7, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_map_fun24008_7, kk_context());
  _self->f = f;
  _self->v = v;
  _self->w = w;
  return &_self->_base;
}



// lift anonymous function
struct kk_std_core_map_fun24010__t_7 {
  struct kk_function_s _base;
  kk_vector_t w;
  size_t i;
};
static kk_box_t kk_std_core_map_fun24010_7(kk_function_t _fself, kk_box_t _b_22260, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_map_fun24010_7(kk_vector_t w, size_t i, kk_context_t* _ctx) {
  struct kk_std_core_map_fun24010__t_7* _self = kk_function_alloc_as(struct kk_std_core_map_fun24010__t_7, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_map_fun24010_7, kk_context());
  _self->w = w;
  _self->i = i;
  return &_self->_base;
}

static kk_box_t kk_std_core_map_fun24010_7(kk_function_t _fself, kk_box_t _b_22260, kk_context_t* _ctx) {
  struct kk_std_core_map_fun24010__t_7* _self = kk_function_as(struct kk_std_core_map_fun24010__t_7*, _fself);
  kk_vector_t w = _self->w; /* vector<7733> */
  size_t i = _self->i; /* size_t */
  kk_drop_match(_self, {kk_vector_dup(w);;}, {}, _ctx)
  kk_unit_t _x24011 = kk_Unit;
  kk_std_core__mlift21188_map_7(i, w, _b_22260, _ctx);
  return kk_unit_box(_x24011);
}
static kk_unit_t kk_std_core_map_fun24008_7(kk_function_t _fself, size_t i, kk_context_t* _ctx) {
  struct kk_std_core_map_fun24008__t_7* _self = kk_function_as(struct kk_std_core_map_fun24008__t_7*, _fself);
  kk_function_t f = _self->f; /* (7732) -> 7734 7733 */
  kk_vector_t v = _self->v; /* vector<7732> */
  kk_vector_t w = _self->w; /* vector<7733> */
  kk_drop_match(_self, {kk_function_dup(f);kk_vector_dup(v);kk_vector_dup(w);}, {}, _ctx)
  kk_box_t x0_21418 = kk_vector_at(v,i); /*7732*/;
  kk_box_t x1_21420 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), f, (f, x0_21418, _ctx)); /*7733*/;
  if (kk_yielding(kk_context())) {
    kk_box_drop(x1_21420, _ctx);
    kk_box_t _x24009 = kk_std_core_hnd_yield_extend(kk_std_core_new_map_fun24010_7(w, i, _ctx), _ctx); /*3991*/
    return kk_unit_unbox(_x24009);
  }
  return kk_std_core__mlift21188_map_7(i, w, x1_21420, _ctx);
}


// lift anonymous function
struct kk_std_core_map_fun24013__t_7 {
  struct kk_function_s _base;
  kk_vector_t w;
};
static kk_box_t kk_std_core_map_fun24013_7(kk_function_t _fself, kk_box_t _b_22264, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_map_fun24013_7(kk_vector_t w, kk_context_t* _ctx) {
  struct kk_std_core_map_fun24013__t_7* _self = kk_function_alloc_as(struct kk_std_core_map_fun24013__t_7, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_map_fun24013_7, kk_context());
  _self->w = w;
  return &_self->_base;
}

static kk_box_t kk_std_core_map_fun24013_7(kk_function_t _fself, kk_box_t _b_22264, kk_context_t* _ctx) {
  struct kk_std_core_map_fun24013__t_7* _self = kk_function_as(struct kk_std_core_map_fun24013__t_7*, _fself);
  kk_vector_t w = _self->w; /* vector<7733> */
  kk_drop_match(_self, {kk_vector_dup(w);}, {}, _ctx)
  kk_vector_t _x24014;
  kk_unit_t _x24015 = kk_Unit;
  kk_unit_unbox(_b_22264);
  _x24014 = kk_std_core__mlift21189_map_7(w, _x24015, _ctx); /*vector<7733>*/
  return kk_vector_box(_x24014, _ctx);
}

kk_vector_t kk_std_core_map_7(kk_vector_t v, kk_function_t f, kk_context_t* _ctx) { /* forall<a,b,e> (v : vector<a>, f : (a) -> e b) -> e vector<b> */ 
  kk_vector_t w;
  size_t _x24002;
  kk_integer_t _x24003;
  kk_vector_t _x24004 = kk_vector_dup(v); /*vector<7732>*/
  _x24003 = kk_std_core_length_2(_x24004, _ctx); /*int*/
  _x24002 = kk_std_core_size__t(_x24003, _ctx); /*size_t*/
  w = kk_vector_allocz(_x24002,kk_context()); /*vector<7733>*/
  kk_unit_t x_21410 = kk_Unit;
  size_t start_21415 = ((size_t)0); /*size_t*/;
  size_t end_21416;
  size_t _x24005;
  kk_vector_t _x24006 = kk_vector_dup(v); /*vector<7732>*/
  _x24005 = kk_vector_len(_x24006); /*size_t*/
  end_21416 = kk_std_core_decr_1(_x24005, _ctx); /*size_t*/
  kk_function_t _x24007;
  kk_vector_dup(w);
  _x24007 = kk_std_core_new_map_fun24008_7(f, v, w, _ctx); /*(i : size_t) -> 7734 ()*/
  kk_std_core__lift21051_forz(_x24007, end_21416, start_21415, _ctx);
  if (kk_yielding(kk_context())) {
    kk_box_t _x24012 = kk_std_core_hnd_yield_extend(kk_std_core_new_map_fun24013_7(w, _ctx), _ctx); /*3991*/
    return kk_vector_unbox(_x24012, _ctx);
  }
  return w;
}
 
// Right-align a string to width `width`  using `fill`  (default is a space) to fill from the left.

kk_string_t kk_std_core_pad_left(kk_string_t s, kk_integer_t width, kk_std_core_types__optional fill, kk_context_t* _ctx) { /* (s : string, width : int, fill : optional<char>) -> string */ 
  size_t w = kk_std_core_size__t(width, _ctx); /*size_t*/;
  size_t n;
  kk_string_t _x24016 = kk_string_dup(s); /*string*/
  n = kk_string_len(_x24016,kk_context()); /*size_t*/
  bool _match_23596 = (w <= n); /*bool*/;
  if (_match_23596) {
    kk_std_core_types__optional_drop(fill, _ctx);
    return s;
  }
  kk_string_t _x24017;
  kk_string_t _x24018;
  kk_char_t _x24019;
  if (kk_std_core_types__is_Optional(fill)) {
    kk_box_t _box_x22267 = fill._cons.Optional.value;
    kk_char_t _fill_8417 = kk_char_unbox(_box_x22267, NULL);
    _x24019 = _fill_8417; /*char*/
    goto _match24020;
  }
  _x24019 = ' '; /*char*/
  _match24020: ;
  _x24018 = kk_std_core_string(_x24019, _ctx); /*string*/
  size_t _x24022 = (w - n); /*size_t*/
  _x24017 = kk_std_core_repeatz(_x24018, _x24022, _ctx); /*string*/
  return kk_std_core__lp__plus__plus__1_rp_(_x24017, s, _ctx);
}
 
// Show an `:int` as a hexadecimal value.
// The `width`  parameter specifies how wide the hex value is where `"0"`  is used to align.
// The `use-capitals` parameter (= `True`) determines if captical letters should be used to display the hexadecimal digits.
// The `pre` (=`"0x"`) is an optional prefix for the number (goes between the sign and the number).

kk_string_t kk_std_core_show_hex(kk_integer_t i, kk_std_core_types__optional width, kk_std_core_types__optional use_capitals, kk_std_core_types__optional pre, kk_context_t* _ctx) { /* (i : int, width : optional<int>, use-capitals : optional<bool>, pre : optional<string>) -> string */ 
  kk_string_t _x24023;
  bool _match_23595;
  kk_integer_t _x24024 = kk_integer_dup(i); /*int*/
  _match_23595 = kk_integer_lt(_x24024,(kk_integer_from_small(0)),kk_context()); /*bool*/
  if (_match_23595) {
    kk_define_string_literal(, _s24025, 1, "-")
    _x24023 = kk_string_dup(_s24025); /*string*/
  }
  else {
    _x24023 = kk_string_empty(); /*string*/
  }
  kk_string_t _x24027;
  kk_string_t _x24028;
  if (kk_std_core_types__is_Optional(pre)) {
    kk_box_t _box_x22268 = pre._cons.Optional.value;
    kk_string_t _pre_8591 = kk_string_unbox(_box_x22268);
    _x24028 = _pre_8591; /*string*/
    goto _match24029;
  }
  kk_define_string_literal(, _s24031, 2, "0x")
  _x24028 = kk_string_dup(_s24031); /*string*/
  _match24029: ;
  kk_string_t _x24032;
  kk_string_t s_21423;
  kk_integer_t _x24033 = kk_integer_abs(i,kk_context()); /*int*/
  bool _x24034;
  if (kk_std_core_types__is_Optional(use_capitals)) {
    kk_box_t _box_x22269 = use_capitals._cons.Optional.value;
    bool _use_capitals_8587 = kk_bool_unbox(_box_x22269);
    _x24034 = _use_capitals_8587; /*bool*/
    goto _match24035;
  }
  _x24034 = true; /*bool*/
  _match24035: ;
  s_21423 = kk_std_core_int_show_hex(_x24033, _x24034, _ctx); /*string*/
  kk_std_core_types__optional fill_21425 = kk_std_core_types__new_Optional(kk_char_box('0', _ctx), _ctx); /*optional<char>*/;
  size_t w;
  kk_integer_t _x24037;
  if (kk_std_core_types__is_Optional(width)) {
    kk_box_t _box_x22272 = width._cons.Optional.value;
    kk_integer_t _width_8583 = kk_integer_unbox(_box_x22272);
    _x24037 = _width_8583; /*int*/
    goto _match24038;
  }
  _x24037 = kk_integer_from_small(1); /*int*/
  _match24038: ;
  w = kk_std_core_size__t(_x24037, _ctx); /*size_t*/
  size_t n;
  kk_string_t _x24040 = kk_string_dup(s_21423); /*string*/
  n = kk_string_len(_x24040,kk_context()); /*size_t*/
  bool _match_23594 = (w <= n); /*bool*/;
  if (_match_23594) {
    kk_std_core_types__optional_drop(fill_21425, _ctx);
    _x24032 = s_21423; /*string*/
  }
  else {
    kk_string_t _x24041;
    kk_string_t _x24042;
    kk_char_t _x24043;
    if (kk_std_core_types__is_Optional(fill_21425)) {
      kk_box_t _box_x22273 = fill_21425._cons.Optional.value;
      kk_char_t _fill_8417 = kk_char_unbox(_box_x22273, NULL);
      _x24043 = _fill_8417; /*char*/
      goto _match24044;
    }
    _x24043 = ' '; /*char*/
    _match24044: ;
    _x24042 = kk_std_core_string(_x24043, _ctx); /*string*/
    size_t _x24046 = (w - n); /*size_t*/
    _x24041 = kk_std_core_repeatz(_x24042, _x24046, _ctx); /*string*/
    _x24032 = kk_std_core__lp__plus__plus__1_rp_(_x24041, s_21423, _ctx); /*string*/
  }
  _x24027 = kk_std_core__lp__plus__plus__1_rp_(_x24028, _x24032, _ctx); /*string*/
  return kk_std_core__lp__plus__plus__1_rp_(_x24023, _x24027, _ctx);
}
 
// Is the integer positive (stricly greater than zero)

bool kk_std_core_is_pos_2(kk_integer_t i, kk_context_t* _ctx) { /* (i : int) -> bool */ 
  kk_std_core_types__order x_21426 = kk_int_as_order(kk_integer_signum(i,kk_context()),kk_context()); /*order*/;
  kk_integer_t _x24047 = kk_std_core_int_5(x_21426, _ctx); /*int*/
  kk_integer_t _x24048;
  kk_std_core_types__order _x24049 = kk_std_core_types__new_Gt(_ctx); /*order*/
  if (kk_std_core_types__is_Lt(_x24049)) {
    _x24048 = kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context()); /*int*/
    goto _match24050;
  }
  if (kk_std_core_types__is_Eq(_x24049)) {
    _x24048 = kk_integer_from_small(0); /*int*/
    goto _match24050;
  }
  _x24048 = kk_integer_from_small(1); /*int*/
  _match24050: ;
  return kk_integer_eq(_x24047,_x24048,kk_context());
}
 
// Show a character as a string

kk_string_t kk_std_core_show_char(kk_char_t c, kk_context_t* _ctx) { /* (c : char) -> string */ 
  bool _match_23571;
  bool _match_23589 = (c < (' ')); /*bool*/;
  if (_match_23589) {
    _match_23571 = true; /*bool*/
  }
  else {
    _match_23571 = (c > ('~')); /*bool*/
  }
  if (_match_23571) {
    bool _match_23575 = (c == 0x000A); /*bool*/;
    if (_match_23575) {
      kk_define_string_literal(, _s24056, 2, "\\n")
      return kk_string_dup(_s24056);
    }
    bool _match_23576 = (c == 0x000D); /*bool*/;
    if (_match_23576) {
      kk_define_string_literal(, _s24057, 2, "\\r")
      return kk_string_dup(_s24057);
    }
    bool _match_23577 = (c == 0x0009); /*bool*/;
    if (_match_23577) {
      kk_define_string_literal(, _s24058, 2, "\\t")
      return kk_string_dup(_s24058);
    }
    bool _match_23578;
    kk_integer_t _x24059 = kk_integer_from_int(c,kk_context()); /*int*/
    _match_23578 = kk_integer_lte(_x24059,(kk_integer_from_small(255)),kk_context()); /*bool*/
    if (_match_23578) {
      kk_string_t _x24060;
      kk_define_string_literal(, _s24061, 2, "\\x")
      _x24060 = kk_string_dup(_s24061); /*string*/
      kk_string_t _x24062;
      kk_integer_t _arg_9350 = kk_integer_from_int(c,kk_context()); /*int*/;
      kk_std_core_types__optional _arg_9351 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(2)), _ctx); /*optional<int>*/;
      kk_std_core_types__optional _arg_9353;
      kk_box_t _x24063;
      kk_string_t _x24064 = kk_string_empty(); /*string*/
      _x24063 = kk_string_box(_x24064); /*108*/
      _arg_9353 = kk_std_core_types__new_Optional(_x24063, _ctx); /*optional<string>*/
      kk_string_t _x24066;
      bool _match_23588;
      kk_integer_t _x24067 = kk_integer_dup(_arg_9350); /*int*/
      _match_23588 = kk_integer_lt(_x24067,(kk_integer_from_small(0)),kk_context()); /*bool*/
      if (_match_23588) {
        kk_define_string_literal(, _s24068, 1, "-")
        _x24066 = kk_string_dup(_s24068); /*string*/
      }
      else {
        _x24066 = kk_string_empty(); /*string*/
      }
      kk_string_t _x24070;
      kk_string_t _x24071;
      if (kk_std_core_types__is_Optional(_arg_9353)) {
        kk_box_t _box_x22278 = _arg_9353._cons.Optional.value;
        kk_string_t _pre_8591 = kk_string_unbox(_box_x22278);
        _x24071 = _pre_8591; /*string*/
        goto _match24072;
      }
      kk_define_string_literal(, _s24074, 2, "0x")
      _x24071 = kk_string_dup(_s24074); /*string*/
      _match24072: ;
      kk_string_t _x24075;
      kk_string_t s_21433;
      kk_integer_t _x24076 = kk_integer_abs(_arg_9350,kk_context()); /*int*/
      bool _x24077;
      kk_std_core_types__optional _x24078 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/
      if (kk_std_core_types__is_Optional(_x24078)) {
        kk_box_t _box_x22279 = _x24078._cons.Optional.value;
        bool _use_capitals_8587 = kk_bool_unbox(_box_x22279);
        _x24077 = _use_capitals_8587; /*bool*/
        goto _match24079;
      }
      _x24077 = true; /*bool*/
      _match24079: ;
      s_21433 = kk_std_core_int_show_hex(_x24076, _x24077, _ctx); /*string*/
      kk_std_core_types__optional fill_21435 = kk_std_core_types__new_Optional(kk_char_box('0', _ctx), _ctx); /*optional<char>*/;
      size_t w;
      kk_integer_t _x24081;
      if (kk_std_core_types__is_Optional(_arg_9351)) {
        kk_box_t _box_x22282 = _arg_9351._cons.Optional.value;
        kk_integer_t _width_8583 = kk_integer_unbox(_box_x22282);
        _x24081 = _width_8583; /*int*/
        goto _match24082;
      }
      _x24081 = kk_integer_from_small(1); /*int*/
      _match24082: ;
      w = kk_std_core_size__t(_x24081, _ctx); /*size_t*/
      size_t n;
      kk_string_t _x24084 = kk_string_dup(s_21433); /*string*/
      n = kk_string_len(_x24084,kk_context()); /*size_t*/
      bool _match_23586 = (w <= n); /*bool*/;
      if (_match_23586) {
        kk_std_core_types__optional_drop(fill_21435, _ctx);
        _x24075 = s_21433; /*string*/
      }
      else {
        kk_string_t _x24085;
        kk_string_t _x24086;
        kk_char_t _x24087;
        if (kk_std_core_types__is_Optional(fill_21435)) {
          kk_box_t _box_x22283 = fill_21435._cons.Optional.value;
          kk_char_t _fill_8417 = kk_char_unbox(_box_x22283, NULL);
          _x24087 = _fill_8417; /*char*/
          goto _match24088;
        }
        _x24087 = ' '; /*char*/
        _match24088: ;
        _x24086 = kk_std_core_string(_x24087, _ctx); /*string*/
        size_t _x24090 = (w - n); /*size_t*/
        _x24085 = kk_std_core_repeatz(_x24086, _x24090, _ctx); /*string*/
        _x24075 = kk_std_core__lp__plus__plus__1_rp_(_x24085, s_21433, _ctx); /*string*/
      }
      _x24070 = kk_std_core__lp__plus__plus__1_rp_(_x24071, _x24075, _ctx); /*string*/
      _x24062 = kk_std_core__lp__plus__plus__1_rp_(_x24066, _x24070, _ctx); /*string*/
      return kk_std_core__lp__plus__plus__1_rp_(_x24060, _x24062, _ctx);
    }
    bool _match_23579;
    kk_integer_t _x24091 = kk_integer_from_int(c,kk_context()); /*int*/
    _match_23579 = kk_integer_lte(_x24091,(kk_integer_from_int(65535, _ctx)),kk_context()); /*bool*/
    if (_match_23579) {
      kk_string_t _x24092;
      kk_define_string_literal(, _s24093, 2, "\\u")
      _x24092 = kk_string_dup(_s24093); /*string*/
      kk_string_t _x24094;
      kk_integer_t _arg_9482 = kk_integer_from_int(c,kk_context()); /*int*/;
      kk_std_core_types__optional _arg_9483 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(4)), _ctx); /*optional<int>*/;
      kk_std_core_types__optional _arg_9485;
      kk_box_t _x24095;
      kk_string_t _x24096 = kk_string_empty(); /*string*/
      _x24095 = kk_string_box(_x24096); /*108*/
      _arg_9485 = kk_std_core_types__new_Optional(_x24095, _ctx); /*optional<string>*/
      kk_string_t _x24098;
      bool _match_23585;
      kk_integer_t _x24099 = kk_integer_dup(_arg_9482); /*int*/
      _match_23585 = kk_integer_lt(_x24099,(kk_integer_from_small(0)),kk_context()); /*bool*/
      if (_match_23585) {
        kk_define_string_literal(, _s24100, 1, "-")
        _x24098 = kk_string_dup(_s24100); /*string*/
      }
      else {
        _x24098 = kk_string_empty(); /*string*/
      }
      kk_string_t _x24102;
      kk_string_t _x24103;
      if (kk_std_core_types__is_Optional(_arg_9485)) {
        kk_box_t _box_x22288 = _arg_9485._cons.Optional.value;
        kk_string_t _pre_85910 = kk_string_unbox(_box_x22288);
        _x24103 = _pre_85910; /*string*/
        goto _match24104;
      }
      kk_define_string_literal(, _s24106, 2, "0x")
      _x24103 = kk_string_dup(_s24106); /*string*/
      _match24104: ;
      kk_string_t _x24107;
      kk_string_t s0_21440;
      kk_integer_t _x24108 = kk_integer_abs(_arg_9482,kk_context()); /*int*/
      bool _x24109;
      kk_std_core_types__optional _x24110 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/
      if (kk_std_core_types__is_Optional(_x24110)) {
        kk_box_t _box_x22289 = _x24110._cons.Optional.value;
        bool _use_capitals_85870 = kk_bool_unbox(_box_x22289);
        _x24109 = _use_capitals_85870; /*bool*/
        goto _match24111;
      }
      _x24109 = true; /*bool*/
      _match24111: ;
      s0_21440 = kk_std_core_int_show_hex(_x24108, _x24109, _ctx); /*string*/
      kk_std_core_types__optional fill0_21442 = kk_std_core_types__new_Optional(kk_char_box('0', _ctx), _ctx); /*optional<char>*/;
      size_t w0;
      kk_integer_t _x24113;
      if (kk_std_core_types__is_Optional(_arg_9483)) {
        kk_box_t _box_x22292 = _arg_9483._cons.Optional.value;
        kk_integer_t _width_85830 = kk_integer_unbox(_box_x22292);
        _x24113 = _width_85830; /*int*/
        goto _match24114;
      }
      _x24113 = kk_integer_from_small(1); /*int*/
      _match24114: ;
      w0 = kk_std_core_size__t(_x24113, _ctx); /*size_t*/
      size_t n0;
      kk_string_t _x24116 = kk_string_dup(s0_21440); /*string*/
      n0 = kk_string_len(_x24116,kk_context()); /*size_t*/
      bool _match_23583 = (w0 <= n0); /*bool*/;
      if (_match_23583) {
        kk_std_core_types__optional_drop(fill0_21442, _ctx);
        _x24107 = s0_21440; /*string*/
      }
      else {
        kk_string_t _x24117;
        kk_string_t _x24118;
        kk_char_t _x24119;
        if (kk_std_core_types__is_Optional(fill0_21442)) {
          kk_box_t _box_x22293 = fill0_21442._cons.Optional.value;
          kk_char_t _fill_84170 = kk_char_unbox(_box_x22293, NULL);
          _x24119 = _fill_84170; /*char*/
          goto _match24120;
        }
        _x24119 = ' '; /*char*/
        _match24120: ;
        _x24118 = kk_std_core_string(_x24119, _ctx); /*string*/
        size_t _x24122 = (w0 - n0); /*size_t*/
        _x24117 = kk_std_core_repeatz(_x24118, _x24122, _ctx); /*string*/
        _x24107 = kk_std_core__lp__plus__plus__1_rp_(_x24117, s0_21440, _ctx); /*string*/
      }
      _x24102 = kk_std_core__lp__plus__plus__1_rp_(_x24103, _x24107, _ctx); /*string*/
      _x24094 = kk_std_core__lp__plus__plus__1_rp_(_x24098, _x24102, _ctx); /*string*/
      return kk_std_core__lp__plus__plus__1_rp_(_x24092, _x24094, _ctx);
    }
    kk_string_t _x24123;
    kk_define_string_literal(, _s24124, 2, "\\U")
    _x24123 = kk_string_dup(_s24124); /*string*/
    kk_string_t _x24125;
    kk_integer_t _arg_9538 = kk_integer_from_int(c,kk_context()); /*int*/;
    kk_std_core_types__optional _arg_9539 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(6)), _ctx); /*optional<int>*/;
    kk_std_core_types__optional _arg_9541;
    kk_box_t _x24126;
    kk_string_t _x24127 = kk_string_empty(); /*string*/
    _x24126 = kk_string_box(_x24127); /*108*/
    _arg_9541 = kk_std_core_types__new_Optional(_x24126, _ctx); /*optional<string>*/
    kk_string_t _x24129;
    bool _match_23582;
    kk_integer_t _x24130 = kk_integer_dup(_arg_9538); /*int*/
    _match_23582 = kk_integer_lt(_x24130,(kk_integer_from_small(0)),kk_context()); /*bool*/
    if (_match_23582) {
      kk_define_string_literal(, _s24131, 1, "-")
      _x24129 = kk_string_dup(_s24131); /*string*/
    }
    else {
      _x24129 = kk_string_empty(); /*string*/
    }
    kk_string_t _x24133;
    kk_string_t _x24134;
    if (kk_std_core_types__is_Optional(_arg_9541)) {
      kk_box_t _box_x22298 = _arg_9541._cons.Optional.value;
      kk_string_t _pre_85911 = kk_string_unbox(_box_x22298);
      _x24134 = _pre_85911; /*string*/
      goto _match24135;
    }
    kk_define_string_literal(, _s24137, 2, "0x")
    _x24134 = kk_string_dup(_s24137); /*string*/
    _match24135: ;
    kk_string_t _x24138;
    kk_string_t s1_21447;
    kk_integer_t _x24139 = kk_integer_abs(_arg_9538,kk_context()); /*int*/
    bool _x24140;
    kk_std_core_types__optional _x24141 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/
    if (kk_std_core_types__is_Optional(_x24141)) {
      kk_box_t _box_x22299 = _x24141._cons.Optional.value;
      bool _use_capitals_85871 = kk_bool_unbox(_box_x22299);
      _x24140 = _use_capitals_85871; /*bool*/
      goto _match24142;
    }
    _x24140 = true; /*bool*/
    _match24142: ;
    s1_21447 = kk_std_core_int_show_hex(_x24139, _x24140, _ctx); /*string*/
    kk_std_core_types__optional fill1_21449 = kk_std_core_types__new_Optional(kk_char_box('0', _ctx), _ctx); /*optional<char>*/;
    size_t w1;
    kk_integer_t _x24144;
    if (kk_std_core_types__is_Optional(_arg_9539)) {
      kk_box_t _box_x22302 = _arg_9539._cons.Optional.value;
      kk_integer_t _width_85831 = kk_integer_unbox(_box_x22302);
      _x24144 = _width_85831; /*int*/
      goto _match24145;
    }
    _x24144 = kk_integer_from_small(1); /*int*/
    _match24145: ;
    w1 = kk_std_core_size__t(_x24144, _ctx); /*size_t*/
    size_t n1;
    kk_string_t _x24147 = kk_string_dup(s1_21447); /*string*/
    n1 = kk_string_len(_x24147,kk_context()); /*size_t*/
    bool _match_23580 = (w1 <= n1); /*bool*/;
    if (_match_23580) {
      kk_std_core_types__optional_drop(fill1_21449, _ctx);
      _x24138 = s1_21447; /*string*/
    }
    else {
      kk_string_t _x24148;
      kk_string_t _x24149;
      kk_char_t _x24150;
      if (kk_std_core_types__is_Optional(fill1_21449)) {
        kk_box_t _box_x22303 = fill1_21449._cons.Optional.value;
        kk_char_t _fill_84171 = kk_char_unbox(_box_x22303, NULL);
        _x24150 = _fill_84171; /*char*/
        goto _match24151;
      }
      _x24150 = ' '; /*char*/
      _match24151: ;
      _x24149 = kk_std_core_string(_x24150, _ctx); /*string*/
      size_t _x24153 = (w1 - n1); /*size_t*/
      _x24148 = kk_std_core_repeatz(_x24149, _x24153, _ctx); /*string*/
      _x24138 = kk_std_core__lp__plus__plus__1_rp_(_x24148, s1_21447, _ctx); /*string*/
    }
    _x24133 = kk_std_core__lp__plus__plus__1_rp_(_x24134, _x24138, _ctx); /*string*/
    _x24125 = kk_std_core__lp__plus__plus__1_rp_(_x24129, _x24133, _ctx); /*string*/
    return kk_std_core__lp__plus__plus__1_rp_(_x24123, _x24125, _ctx);
  }
  bool _match_23572 = (c == ('\'')); /*bool*/;
  if (_match_23572) {
    kk_define_string_literal(, _s24154, 2, "\\\'")
    return kk_string_dup(_s24154);
  }
  bool _match_23573 = (c == ('"')); /*bool*/;
  if (_match_23573) {
    kk_define_string_literal(, _s24155, 2, "\\\"")
    return kk_string_dup(_s24155);
  }
  bool _match_23574 = (c == ('\\')); /*bool*/;
  if (_match_23574) {
    kk_define_string_literal(, _s24156, 2, "\\\\")
    return kk_string_dup(_s24156);
  }
  return kk_std_core_string(c, _ctx);
}
 
// Show a `:double` fixed-point notation.
// The optional `precision` (= `-2`) specifies the maximum precision.
// If `>=0` it specifies the number of digits behind the dot (up to `20` max).
// If negative, then at most the absolute value of `precision` digits behind the dot are used.
// This may still show a number in exponential notation if the it is too small or large,
// in particular, for  a `d` where `d > 1.0e21` or `d < 1.0e-15`, or if
// `precision.abs > 17`, the `show-exp` routine is used.

kk_string_t kk_std_core_show_fixed(double d, kk_std_core_types__optional precision, kk_context_t* _ctx) { /* (d : double, precision : optional<int>) -> string */ 
  double dabs = kk_double_abs(d); /*double*/;
  bool _match_23569;
  bool _match_23570 = (dabs < (0x1.203af9ee75616p-50)); /*bool*/;
  if (_match_23570) {
    _match_23569 = true; /*bool*/
  }
  else {
    _match_23569 = (dabs > (0x1.b1ae4d6e2ef5p69)); /*bool*/
  }
  if (_match_23569) {
    kk_std_core_types__optional precision0_21451;
    kk_box_t _x24161;
    kk_integer_t _x24162;
    if (kk_std_core_types__is_Optional(precision)) {
      kk_box_t _box_x22305 = precision._cons.Optional.value;
      kk_integer_t _precision_9673 = kk_integer_unbox(_box_x22305);
      _x24162 = _precision_9673; /*int*/
      goto _match24163;
    }
    _x24162 = kk_integer_from_small(-2); /*int*/
    _match24163: ;
    _x24161 = kk_integer_box(_x24162); /*108*/
    precision0_21451 = kk_std_core_types__new_Optional(_x24161, _ctx); /*optional<int>*/
    int32_t _x24165;
    kk_integer_t _x24166;
    if (kk_std_core_types__is_Optional(precision0_21451)) {
      kk_box_t _box_x22308 = precision0_21451._cons.Optional.value;
      kk_integer_t _precision_9662 = kk_integer_unbox(_box_x22308);
      _x24166 = _precision_9662; /*int*/
      goto _match24167;
    }
    _x24166 = kk_integer_from_small(-17); /*int*/
    _match24167: ;
    _x24165 = kk_std_core_int32(_x24166, _ctx); /*int32*/
    return kk_std_core_show_expx(d, _x24165, _ctx);
  }
  int32_t _x24169;
  kk_integer_t _x24170;
  if (kk_std_core_types__is_Optional(precision)) {
    kk_box_t _box_x22309 = precision._cons.Optional.value;
    kk_integer_t _precision_96730 = kk_integer_unbox(_box_x22309);
    _x24170 = _precision_96730; /*int*/
    goto _match24171;
  }
  _x24170 = kk_integer_from_small(-2); /*int*/
  _match24171: ;
  _x24169 = kk_std_core_int32(_x24170, _ctx); /*int32*/
  return kk_std_core_show_fixedx(d, _x24169, _ctx);
}
 
// monadic lift

kk_string_t kk_std_core__mlift21190_show_list(kk_std_core__list _y_75, kk_context_t* _ctx) { /* forall<e> (list<string>) -> e string */ 
  kk_string_t _x24173;
  kk_define_string_literal(, _s24174, 1, "[")
  _x24173 = kk_string_dup(_s24174); /*string*/
  kk_string_t _x24175;
  kk_string_t _x24176;
  if (kk_std_core__is_Nil(_y_75)) {
    _x24176 = kk_string_empty(); /*string*/
  }
  else {
    struct kk_std_core_Cons* _con24178 = kk_std_core__as_Cons(_y_75);
    kk_box_t _box_x22310 = _con24178->head;
    kk_std_core__list xx = _con24178->tail;
    kk_string_t x = kk_string_unbox(_box_x22310);
    if (kk_std_core__list_is_unique(_y_75)) {
      kk_std_core__list_free(_y_75);
    }
    else {
      kk_string_dup(x);
      kk_std_core__list_dup(xx);
      kk_std_core__list_decref(_y_75, _ctx);
    }
    kk_string_t _x24180;
    kk_define_string_literal(, _s24181, 1, ",")
    _x24180 = kk_string_dup(_s24181); /*string*/
    _x24176 = kk_std_core__lift21050_joinsep(_x24180, xx, x, _ctx); /*string*/
  }
  kk_string_t _x24182;
  kk_define_string_literal(, _s24183, 1, "]")
  _x24182 = kk_string_dup(_s24183); /*string*/
  _x24175 = kk_std_core__lp__plus__plus__1_rp_(_x24176, _x24182, _ctx); /*string*/
  return kk_std_core__lp__plus__plus__1_rp_(_x24173, _x24175, _ctx);
}
 
// Convert a list to a string


// lift anonymous function
struct kk_std_core_show_list_fun24184__t {
  struct kk_function_s _base;
  kk_function_t show_elem;
};
static kk_box_t kk_std_core_show_list_fun24184(kk_function_t _fself, kk_box_t _b_22313, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_show_list_fun24184(kk_function_t show_elem, kk_context_t* _ctx) {
  struct kk_std_core_show_list_fun24184__t* _self = kk_function_alloc_as(struct kk_std_core_show_list_fun24184__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_show_list_fun24184, kk_context());
  _self->show_elem = show_elem;
  return &_self->_base;
}

static kk_box_t kk_std_core_show_list_fun24184(kk_function_t _fself, kk_box_t _b_22313, kk_context_t* _ctx) {
  struct kk_std_core_show_list_fun24184__t* _self = kk_function_as(struct kk_std_core_show_list_fun24184__t*, _fself);
  kk_function_t show_elem = _self->show_elem; /* (10296) -> 10297 string */
  kk_drop_match(_self, {kk_function_dup(show_elem);}, {}, _ctx)
  kk_string_t _x24185 = kk_function_call(kk_string_t, (kk_function_t, kk_box_t, kk_context_t*), show_elem, (show_elem, _b_22313, _ctx)); /*string*/
  return kk_string_box(_x24185);
}


// lift anonymous function
struct kk_std_core_show_list_fun24187__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_show_list_fun24187(kk_function_t _fself, kk_box_t _b_22317, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_show_list_fun24187(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_show_list_fun24187, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_core_show_list_fun24187(kk_function_t _fself, kk_box_t _b_22317, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x24188;
  kk_std_core__list _x24189 = kk_std_core__list_unbox(_b_22317, _ctx); /*list<string>*/
  _x24188 = kk_std_core__mlift21190_show_list(_x24189, _ctx); /*string*/
  return kk_string_box(_x24188);
}

kk_string_t kk_std_core_show_list(kk_std_core__list xs, kk_function_t show_elem, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, show-elem : (a) -> e string) -> e string */ 
  kk_std_core__list x_21454 = kk_std_core_map_5(xs, kk_std_core_new_show_list_fun24184(show_elem, _ctx), _ctx); /*list<string>*/;
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_21454, _ctx);
    kk_box_t _x24186 = kk_std_core_hnd_yield_extend(kk_std_core_new_show_list_fun24187(_ctx), _ctx); /*3991*/
    return kk_string_unbox(_x24186);
  }
  kk_string_t _x24190;
  kk_define_string_literal(, _s24191, 1, "[")
  _x24190 = kk_string_dup(_s24191); /*string*/
  kk_string_t _x24192;
  kk_string_t _x24193;
  if (kk_std_core__is_Nil(x_21454)) {
    _x24193 = kk_string_empty(); /*string*/
  }
  else {
    struct kk_std_core_Cons* _con24195 = kk_std_core__as_Cons(x_21454);
    kk_box_t _box_x22318 = _con24195->head;
    kk_std_core__list xx = _con24195->tail;
    kk_string_t x = kk_string_unbox(_box_x22318);
    if (kk_std_core__list_is_unique(x_21454)) {
      kk_std_core__list_free(x_21454);
    }
    else {
      kk_string_dup(x);
      kk_std_core__list_dup(xx);
      kk_std_core__list_decref(x_21454, _ctx);
    }
    kk_string_t _x24197;
    kk_define_string_literal(, _s24198, 1, ",")
    _x24197 = kk_string_dup(_s24198); /*string*/
    _x24193 = kk_std_core__lift21050_joinsep(_x24197, xx, x, _ctx); /*string*/
  }
  kk_string_t _x24199;
  kk_define_string_literal(, _s24200, 1, "]")
  _x24199 = kk_string_dup(_s24200); /*string*/
  _x24192 = kk_std_core__lp__plus__plus__1_rp_(_x24193, _x24199, _ctx); /*string*/
  return kk_std_core__lp__plus__plus__1_rp_(_x24190, _x24192, _ctx);
}
 
// Convert an `:int` to a string

kk_string_t kk_std_core_show(kk_integer_t i, kk_context_t* _ctx) { /* (i : int) -> string */ 
  return kk_integer_to_string(i,kk_context());
}
 
// Show a `:double` as a string.
// If `d >= 1.0e-5` and `d < 1.0e+21`, `show-fixed` is used and otherwise `show-exp`.
// Default `precision` is `-17`.

kk_string_t kk_std_core_show_1(double d, kk_std_core_types__optional precision, kk_context_t* _ctx) { /* (d : double, precision : optional<int>) -> string */ 
  double dabs = kk_double_abs(d); /*double*/;
  bool _match_23564;
  bool _match_23567 = (dabs >= (0x1.4f8b588e368f1p-17)); /*bool*/;
  if (_match_23567) {
    _match_23564 = (dabs < (0x1.b1ae4d6e2ef5p69)); /*bool*/
  }
  else {
    _match_23564 = false; /*bool*/
  }
  if (_match_23564) {
    kk_std_core_types__optional precision0_21461;
    kk_box_t _x24201;
    kk_integer_t _x24202;
    if (kk_std_core_types__is_Optional(precision)) {
      kk_box_t _box_x22321 = precision._cons.Optional.value;
      kk_integer_t _precision_10416 = kk_integer_unbox(_box_x22321);
      _x24202 = _precision_10416; /*int*/
      goto _match24203;
    }
    _x24202 = kk_integer_from_small(-17); /*int*/
    _match24203: ;
    _x24201 = kk_integer_box(_x24202); /*108*/
    precision0_21461 = kk_std_core_types__new_Optional(_x24201, _ctx); /*optional<int>*/
    double dabs0 = kk_double_abs(d); /*double*/;
    bool _match_23565;
    bool _match_23566 = (dabs0 < (0x1.203af9ee75616p-50)); /*bool*/;
    if (_match_23566) {
      _match_23565 = true; /*bool*/
    }
    else {
      _match_23565 = (dabs0 > (0x1.b1ae4d6e2ef5p69)); /*bool*/
    }
    if (_match_23565) {
      kk_std_core_types__optional precision1_21463;
      kk_box_t _x24205;
      kk_integer_t _x24206;
      if (kk_std_core_types__is_Optional(precision0_21461)) {
        kk_box_t _box_x22324 = precision0_21461._cons.Optional.value;
        kk_integer_t _precision_9673 = kk_integer_unbox(_box_x22324);
        _x24206 = _precision_9673; /*int*/
        goto _match24207;
      }
      _x24206 = kk_integer_from_small(-2); /*int*/
      _match24207: ;
      _x24205 = kk_integer_box(_x24206); /*108*/
      precision1_21463 = kk_std_core_types__new_Optional(_x24205, _ctx); /*optional<int>*/
      int32_t _x24209;
      kk_integer_t _x24210;
      if (kk_std_core_types__is_Optional(precision1_21463)) {
        kk_box_t _box_x22327 = precision1_21463._cons.Optional.value;
        kk_integer_t _precision_9662 = kk_integer_unbox(_box_x22327);
        _x24210 = _precision_9662; /*int*/
        goto _match24211;
      }
      _x24210 = kk_integer_from_small(-17); /*int*/
      _match24211: ;
      _x24209 = kk_std_core_int32(_x24210, _ctx); /*int32*/
      return kk_std_core_show_expx(d, _x24209, _ctx);
    }
    int32_t _x24213;
    kk_integer_t _x24214;
    if (kk_std_core_types__is_Optional(precision0_21461)) {
      kk_box_t _box_x22328 = precision0_21461._cons.Optional.value;
      kk_integer_t _precision_96730 = kk_integer_unbox(_box_x22328);
      _x24214 = _precision_96730; /*int*/
      goto _match24215;
    }
    _x24214 = kk_integer_from_small(-2); /*int*/
    _match24215: ;
    _x24213 = kk_std_core_int32(_x24214, _ctx); /*int32*/
    return kk_std_core_show_fixedx(d, _x24213, _ctx);
  }
  kk_std_core_types__optional precision2_21465;
  kk_box_t _x24217;
  kk_integer_t _x24218;
  if (kk_std_core_types__is_Optional(precision)) {
    kk_box_t _box_x22329 = precision._cons.Optional.value;
    kk_integer_t _precision_104160 = kk_integer_unbox(_box_x22329);
    _x24218 = _precision_104160; /*int*/
    goto _match24219;
  }
  _x24218 = kk_integer_from_small(-17); /*int*/
  _match24219: ;
  _x24217 = kk_integer_box(_x24218); /*108*/
  precision2_21465 = kk_std_core_types__new_Optional(_x24217, _ctx); /*optional<int>*/
  int32_t _x24221;
  kk_integer_t _x24222;
  if (kk_std_core_types__is_Optional(precision2_21465)) {
    kk_box_t _box_x22332 = precision2_21465._cons.Optional.value;
    kk_integer_t _precision_96620 = kk_integer_unbox(_box_x22332);
    _x24222 = _precision_96620; /*int*/
    goto _match24223;
  }
  _x24222 = kk_integer_from_small(-17); /*int*/
  _match24223: ;
  _x24221 = kk_std_core_int32(_x24222, _ctx); /*int32*/
  return kk_std_core_show_expx(d, _x24221, _ctx);
}
 
// Show a string as a string literal


// lift anonymous function
struct kk_std_core_show_fun24235__t_3 {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_show_fun24235_3(kk_function_t _fself, kk_box_t _b_22335, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_show_fun24235_3(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_show_fun24235_3, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_core_show_fun24235_3(kk_function_t _fself, kk_box_t _b_22335, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x24236;
  kk_char_t _x24237 = kk_char_unbox(_b_22335, _ctx); /*char*/
  _x24236 = kk_std_core_show_char(_x24237, _ctx); /*string*/
  return kk_string_box(_x24236);
}

kk_string_t kk_std_core_show_3(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> string */ 
  kk_string_t _x24231;
  kk_define_string_literal(, _s24232, 1, "\"")
  _x24231 = kk_string_dup(_s24232); /*string*/
  kk_string_t _x24233;
  kk_string_t _x24234;
  kk_std_core__list xs_21467;
  kk_std_core__list _b_22336_22333 = kk_std_core_list_4(s, _ctx); /*list<char>*/;
  xs_21467 = kk_std_core_map_5(_b_22336_22333, kk_std_core_new_show_fun24235_3(_ctx), _ctx); /*list<string>*/
  if (kk_std_core__is_Nil(xs_21467)) {
    _x24234 = kk_string_empty(); /*string*/
  }
  else {
    struct kk_std_core_Cons* _con24239 = kk_std_core__as_Cons(xs_21467);
    kk_box_t _box_x22338 = _con24239->head;
    kk_std_core__list xx = _con24239->tail;
    kk_string_t x = kk_string_unbox(_box_x22338);
    if (kk_std_core__list_is_unique(xs_21467)) {
      kk_std_core__list_free(xs_21467);
    }
    else {
      kk_string_dup(x);
      kk_std_core__list_dup(xx);
      kk_std_core__list_decref(xs_21467, _ctx);
    }
    kk_string_t _x24241 = kk_string_empty(); /*string*/
    _x24234 = kk_std_core__lift21050_joinsep(_x24241, xx, x, _ctx); /*string*/
  }
  kk_string_t _x24243;
  kk_define_string_literal(, _s24244, 1, "\"")
  _x24243 = kk_string_dup(_s24244); /*string*/
  _x24233 = kk_std_core__lp__plus__plus__1_rp_(_x24234, _x24243, _ctx); /*string*/
  return kk_std_core__lp__plus__plus__1_rp_(_x24231, _x24233, _ctx);
}
 
// Show an `:sslice` as a string literal


// lift anonymous function
struct kk_std_core_show_fun24252__t_6 {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_show_fun24252_6(kk_function_t _fself, kk_box_t _b_22341, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_show_fun24252_6(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_show_fun24252_6, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_core_show_fun24252_6(kk_function_t _fself, kk_box_t _b_22341, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x24253;
  kk_char_t _x24254 = kk_char_unbox(_b_22341, _ctx); /*char*/
  _x24253 = kk_std_core_show_char(_x24254, _ctx); /*string*/
  return kk_string_box(_x24253);
}

kk_string_t kk_std_core_show_6(kk_std_core__sslice s, kk_context_t* _ctx) { /* (s : sslice) -> string */ 
  kk_string_t s0_21470 = kk_std_core_string_3(s, _ctx); /*string*/;
  kk_string_t _x24248;
  kk_define_string_literal(, _s24249, 1, "\"")
  _x24248 = kk_string_dup(_s24249); /*string*/
  kk_string_t _x24250;
  kk_string_t _x24251;
  kk_std_core__list xs_21471;
  kk_std_core__list _b_22342_22339 = kk_std_core_list_4(s0_21470, _ctx); /*list<char>*/;
  xs_21471 = kk_std_core_map_5(_b_22342_22339, kk_std_core_new_show_fun24252_6(_ctx), _ctx); /*list<string>*/
  if (kk_std_core__is_Nil(xs_21471)) {
    _x24251 = kk_string_empty(); /*string*/
  }
  else {
    struct kk_std_core_Cons* _con24256 = kk_std_core__as_Cons(xs_21471);
    kk_box_t _box_x22344 = _con24256->head;
    kk_std_core__list xx = _con24256->tail;
    kk_string_t x = kk_string_unbox(_box_x22344);
    if (kk_std_core__list_is_unique(xs_21471)) {
      kk_std_core__list_free(xs_21471);
    }
    else {
      kk_string_dup(x);
      kk_std_core__list_dup(xx);
      kk_std_core__list_decref(xs_21471, _ctx);
    }
    kk_string_t _x24258 = kk_string_empty(); /*string*/
    _x24251 = kk_std_core__lift21050_joinsep(_x24258, xx, x, _ctx); /*string*/
  }
  kk_string_t _x24260;
  kk_define_string_literal(, _s24261, 1, "\"")
  _x24260 = kk_string_dup(_s24261); /*string*/
  _x24250 = kk_std_core__lp__plus__plus__1_rp_(_x24251, _x24260, _ctx); /*string*/
  return kk_std_core__lp__plus__plus__1_rp_(_x24248, _x24250, _ctx);
}
extern kk_string_t kk_std_core_show_fun24262_7(kk_function_t _fself, kk_box_t _b_22347, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x24263 = kk_string_unbox(_b_22347); /*string*/
  return kk_std_core_show_3(_x24263, _ctx);
}
extern kk_string_t kk_std_core_show_fun24264_8(kk_function_t _fself, kk_box_t _b_22352, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_integer_t _x24265 = kk_integer_unbox(_b_22352); /*int*/
  return kk_std_core_show(_x24265, _ctx);
}
extern kk_string_t kk_std_core_show_fun24266_9(kk_function_t _fself, kk_box_t _b_22357, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  bool _x24267 = kk_bool_unbox(_b_22357); /*bool*/
  return kk_std_core_show_4(_x24267, _ctx);
}

kk_unit_t kk_std_core_prints(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> console () */ 
  kk_std_core_types__maybe _match_23563;
  kk_box_t _x24275;
  kk_ref_t _x24276 = kk_ref_dup(kk_std_core_redirect); /*ref<global,maybe<(string) -> console ()>>*/
  _x24275 = kk_ref_get(_x24276,kk_context()); /*179*/
  _match_23563 = kk_std_core_types__maybe_unbox(_x24275, _ctx); /*maybe<(string) -> console ()>*/
  if (kk_std_core_types__is_Nothing(_match_23563)) {
    kk_std_core_xprints(s, _ctx); return kk_Unit;
  }
  kk_box_t _fun_unbox_x22364 = _match_23563._cons.Just.value;
  kk_box_t _x24277;
  kk_function_t _x24278 = kk_function_unbox(_fun_unbox_x22364); /*(22365) -> console 22366*/
  _x24277 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x24278, (_x24278, kk_string_box(s), _ctx)); /*22366*/
  kk_unit_unbox(_x24277); return kk_Unit;
}


// lift anonymous function
struct kk_std_core__default_exn_fun24284__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core__default_exn_fun24284(kk_function_t _fself, kk_std_core_hnd__marker _b_22386, kk_std_core_hnd__ev _b_22387, kk_box_t _b_22388, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_default_exn_fun24284(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core__default_exn_fun24284, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_std_core__default_exn_fun24285__t {
  struct kk_function_s _base;
  kk_box_t _b_22388;
};
static kk_box_t kk_std_core__default_exn_fun24285(kk_function_t _fself, kk_function_t _b_22383, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_default_exn_fun24285(kk_box_t _b_22388, kk_context_t* _ctx) {
  struct kk_std_core__default_exn_fun24285__t* _self = kk_function_alloc_as(struct kk_std_core__default_exn_fun24285__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__default_exn_fun24285, kk_context());
  _self->_b_22388 = _b_22388;
  return &_self->_base;
}

static kk_box_t kk_std_core__default_exn_fun24285(kk_function_t _fself, kk_function_t _b_22383, kk_context_t* _ctx) {
  struct kk_std_core__default_exn_fun24285__t* _self = kk_function_as(struct kk_std_core__default_exn_fun24285__t*, _fself);
  kk_box_t _b_22388 = _self->_b_22388; /* 52 */
  kk_drop_match(_self, {kk_box_dup(_b_22388);}, {}, _ctx)
  kk_function_drop(_b_22383, _ctx);
  kk_unit_t _x24286 = kk_Unit;
  kk_unit_t __ = kk_Unit;
  kk_string_t _x24287;
  kk_define_string_literal(, _s24288, 20, "uncaught exception: ")
  _x24287 = kk_string_dup(_s24288); /*string*/
  kk_std_core_prints(_x24287, _ctx);
  kk_string_t _x24289;
  kk_std_core__exception _match_23561 = kk_std_core__exception_unbox(_b_22388, _ctx); /*exception*/;
  kk_string_t _x = _match_23561.message;
  kk_string_dup(_x);
  kk_std_core__exception_drop(_match_23561, _ctx);
  _x24289 = _x; /*string*/
  kk_std_core_printsln(_x24289, _ctx);
  return kk_unit_box(_x24286);
}
static kk_box_t kk_std_core__default_exn_fun24284(kk_function_t _fself, kk_std_core_hnd__marker _b_22386, kk_std_core_hnd__ev _b_22387, kk_box_t _b_22388, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core_hnd__ev_dropn(_b_22387, ((int32_t)3), _ctx);
  return kk_std_core_hnd_yield_to_final(_b_22386, kk_std_core__new_default_exn_fun24285(_b_22388, _ctx), _ctx);
}


// lift anonymous function
struct kk_std_core__default_exn_fun24291__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core__default_exn_fun24291(kk_function_t _fself, kk_box_t _b_22393, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_default_exn_fun24291(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core__default_exn_fun24291, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_core__default_exn_fun24291(kk_function_t _fself, kk_box_t _b_22393, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return _b_22393;
}


// lift anonymous function
struct kk_std_core__default_exn_fun24292__t {
  struct kk_function_s _base;
  kk_function_t action;
};
static kk_box_t kk_std_core__default_exn_fun24292(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_default_exn_fun24292(kk_function_t action, kk_context_t* _ctx) {
  struct kk_std_core__default_exn_fun24292__t* _self = kk_function_alloc_as(struct kk_std_core__default_exn_fun24292__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__default_exn_fun24292, kk_context());
  _self->action = action;
  return &_self->_base;
}

static kk_box_t kk_std_core__default_exn_fun24292(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_core__default_exn_fun24292__t* _self = kk_function_as(struct kk_std_core__default_exn_fun24292__t*, _fself);
  kk_function_t action = _self->action; /* () -> <exn,console|11881> () */
  kk_drop_match(_self, {kk_function_dup(action);}, {}, _ctx)
  kk_unit_t _x24293 = kk_Unit;
  kk_function_call(kk_unit_t, (kk_function_t, kk_context_t*), action, (action, _ctx));
  return kk_unit_box(_x24293);
}

kk_unit_t kk_std_core__default_exn(kk_function_t action, kk_context_t* _ctx) { /* forall<e> (action : () -> <console,exn|e> ()) -> <console|e> () */ 
  int32_t _b_22394_22389 = ((int32_t)0); /*int32*/;
  kk_std_core__hnd_exn _b_22395_22390;
  kk_std_core_hnd__clause1 _x24283 = kk_std_core_hnd__new_Clause1(kk_std_core__new_default_exn_fun24284(_ctx), _ctx); /*std/core/hnd/clause1<52,53,54,55,56>*/
  _b_22395_22390 = kk_std_core__new_Hnd_exn(kk_reuse_null, _x24283, _ctx); /*.hnd-exn<<console|11881>,()>*/
  kk_box_t _x24290 = kk_std_core__handle_exn(_b_22394_22389, _b_22395_22390, kk_std_core__new_default_exn_fun24291(_ctx), kk_std_core__new_default_exn_fun24292(action, _ctx), _ctx); /*1966*/
  kk_unit_unbox(_x24290); return kk_Unit;
}
 
// Get (zero-based) element `n`  of a list. Return a `:maybe` type.

kk_std_core_types__maybe kk_std_core__lp__lb__rb__2_rp_(kk_std_core__list xs, kk_integer_t n, kk_context_t* _ctx) { /* forall<a> (xs : list<a>, n : int) -> maybe<a> */ 
  kk__tailcall: ;
  if (kk_std_core__is_Cons(xs)) {
    struct kk_std_core_Cons* _con24294 = kk_std_core__as_Cons(xs);
    kk_box_t x = _con24294->head;
    kk_std_core__list xx = _con24294->tail;
    if (kk_std_core__list_is_unique(xs)) {
      kk_std_core__list_free(xs);
    }
    else {
      kk_box_dup(x);
      kk_std_core__list_dup(xx);
      kk_std_core__list_decref(xs, _ctx);
    }
    bool _match_23559;
    kk_integer_t _x24295 = kk_integer_dup(n); /*int*/
    _match_23559 = kk_integer_gt(_x24295,(kk_integer_from_small(0)),kk_context()); /*bool*/
    if (_match_23559) {
      kk_box_drop(x, _ctx);
      { // tailcall
        kk_integer_t _x24296 = kk_integer_sub(n,(kk_integer_from_small(1)),kk_context()); /*int*/
        xs = xx;
        n = _x24296;
        goto kk__tailcall;
      }
    }
    kk_std_core__list_drop(xx, _ctx);
    bool _match_23560 = kk_integer_eq(n,(kk_integer_from_small(0)),kk_context()); /*bool*/;
    if (_match_23560) {
      return kk_std_core_types__new_Just(x, _ctx);
    }
    kk_box_drop(x, _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
  kk_integer_drop(n, _ctx);
  return kk_std_core_types__new_Nothing(_ctx);
}
 
// O(1). Return the string slice from the end of `slice` argument
// to the end of the string.

kk_std_core__sslice kk_std_core_after(kk_std_core__sslice slice0, kk_context_t* _ctx) { /* (slice : sslice) -> sslice */ 
  kk_string_t s = slice0.str;
  size_t start0 = slice0.start;
  size_t len0 = slice0.len;
  kk_string_dup(s);
  kk_std_core__sslice_drop(slice0, _ctx);
  kk_string_t _x24299 = kk_string_dup(s); /*string*/
  size_t _x24300 = (start0 + len0); /*size_t*/
  size_t _x24301;
  size_t _x24302 = kk_string_len(s,kk_context()); /*size_t*/
  size_t _x24303 = (start0 + len0); /*size_t*/
  _x24301 = (_x24302 - _x24303); /*size_t*/
  return kk_std_core__new_Sslice(_x24299, _x24300, _x24301, _ctx);
}
 
// monadic lift

bool kk_std_core__mlift21191_all(kk_function_t predicate, kk_std_core__list xx, bool _y_78, kk_context_t* _ctx) { /* forall<a,e> (predicate : (a) -> e bool, xx : list<a>, bool) -> e bool */ 
  if (_y_78) {
    return kk_std_core_all(xx, predicate, _ctx);
  }
  kk_function_drop(predicate, _ctx);
  kk_std_core__list_drop(xx, _ctx);
  return false;
}
 
// Do all elements satisfy a predicate ?


// lift anonymous function
struct kk_std_core_all_fun24307__t {
  struct kk_function_s _base;
  kk_function_t predicate0;
  kk_std_core__list xx0;
};
static kk_box_t kk_std_core_all_fun24307(kk_function_t _fself, kk_box_t _b_22407, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_all_fun24307(kk_function_t predicate0, kk_std_core__list xx0, kk_context_t* _ctx) {
  struct kk_std_core_all_fun24307__t* _self = kk_function_alloc_as(struct kk_std_core_all_fun24307__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_all_fun24307, kk_context());
  _self->predicate0 = predicate0;
  _self->xx0 = xx0;
  return &_self->_base;
}

static kk_box_t kk_std_core_all_fun24307(kk_function_t _fself, kk_box_t _b_22407, kk_context_t* _ctx) {
  struct kk_std_core_all_fun24307__t* _self = kk_function_as(struct kk_std_core_all_fun24307__t*, _fself);
  kk_function_t predicate0 = _self->predicate0; /* (12206) -> 12207 bool */
  kk_std_core__list xx0 = _self->xx0; /* list<12206> */
  kk_drop_match(_self, {kk_function_dup(predicate0);kk_std_core__list_dup(xx0);}, {}, _ctx)
  bool _x24308;
  bool _x24309 = kk_bool_unbox(_b_22407); /*bool*/
  _x24308 = kk_std_core__mlift21191_all(predicate0, xx0, _x24309, _ctx); /*bool*/
  return kk_bool_box(_x24308);
}

bool kk_std_core_all(kk_std_core__list xs, kk_function_t predicate0, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, predicate : (a) -> e bool) -> e bool */ 
  kk__tailcall: ;
  if (kk_std_core__is_Cons(xs)) {
    struct kk_std_core_Cons* _con24304 = kk_std_core__as_Cons(xs);
    kk_box_t x = _con24304->head;
    kk_std_core__list xx0 = _con24304->tail;
    if (kk_std_core__list_is_unique(xs)) {
      kk_std_core__list_free(xs);
    }
    else {
      kk_box_dup(x);
      kk_std_core__list_dup(xx0);
      kk_std_core__list_decref(xs, _ctx);
    }
    bool x0_21481;
    kk_function_t _x24305 = kk_function_dup(predicate0); /*(12206) -> 12207 bool*/
    x0_21481 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_context_t*), _x24305, (_x24305, x, _ctx)); /*bool*/
    if (kk_yielding(kk_context())) {
      kk_box_t _x24306 = kk_std_core_hnd_yield_extend(kk_std_core_new_all_fun24307(predicate0, xx0, _ctx), _ctx); /*3991*/
      return kk_bool_unbox(_x24306);
    }
    if (x0_21481) {
      { // tailcall
        xs = xx0;
        goto kk__tailcall;
      }
    }
    kk_function_drop(predicate0, _ctx);
    kk_std_core__list_drop(xx0, _ctx);
    return false;
  }
  kk_function_drop(predicate0, _ctx);
  return true;
}
 
// monadic lift

bool kk_std_core__mlift21192_any(kk_function_t predicate, kk_std_core__list xx, bool _y_82, kk_context_t* _ctx) { /* forall<a,e> (predicate : (a) -> e bool, xx : list<a>, bool) -> e bool */ 
  if (_y_82) {
    kk_function_drop(predicate, _ctx);
    kk_std_core__list_drop(xx, _ctx);
    return true;
  }
  return kk_std_core_any(xx, predicate, _ctx);
}
 
// Are there any elements in a list that satisfy a predicate ?


// lift anonymous function
struct kk_std_core_any_fun24313__t {
  struct kk_function_s _base;
  kk_function_t predicate0;
  kk_std_core__list xx0;
};
static kk_box_t kk_std_core_any_fun24313(kk_function_t _fself, kk_box_t _b_22411, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_any_fun24313(kk_function_t predicate0, kk_std_core__list xx0, kk_context_t* _ctx) {
  struct kk_std_core_any_fun24313__t* _self = kk_function_alloc_as(struct kk_std_core_any_fun24313__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_any_fun24313, kk_context());
  _self->predicate0 = predicate0;
  _self->xx0 = xx0;
  return &_self->_base;
}

static kk_box_t kk_std_core_any_fun24313(kk_function_t _fself, kk_box_t _b_22411, kk_context_t* _ctx) {
  struct kk_std_core_any_fun24313__t* _self = kk_function_as(struct kk_std_core_any_fun24313__t*, _fself);
  kk_function_t predicate0 = _self->predicate0; /* (12234) -> 12235 bool */
  kk_std_core__list xx0 = _self->xx0; /* list<12234> */
  kk_drop_match(_self, {kk_function_dup(predicate0);kk_std_core__list_dup(xx0);}, {}, _ctx)
  bool _x24314;
  bool _x24315 = kk_bool_unbox(_b_22411); /*bool*/
  _x24314 = kk_std_core__mlift21192_any(predicate0, xx0, _x24315, _ctx); /*bool*/
  return kk_bool_box(_x24314);
}

bool kk_std_core_any(kk_std_core__list xs, kk_function_t predicate0, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, predicate : (a) -> e bool) -> e bool */ 
  kk__tailcall: ;
  if (kk_std_core__is_Cons(xs)) {
    struct kk_std_core_Cons* _con24310 = kk_std_core__as_Cons(xs);
    kk_box_t x = _con24310->head;
    kk_std_core__list xx0 = _con24310->tail;
    if (kk_std_core__list_is_unique(xs)) {
      kk_std_core__list_free(xs);
    }
    else {
      kk_box_dup(x);
      kk_std_core__list_dup(xx0);
      kk_std_core__list_decref(xs, _ctx);
    }
    bool x0_21485;
    kk_function_t _x24311 = kk_function_dup(predicate0); /*(12234) -> 12235 bool*/
    x0_21485 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_context_t*), _x24311, (_x24311, x, _ctx)); /*bool*/
    if (kk_yielding(kk_context())) {
      kk_box_t _x24312 = kk_std_core_hnd_yield_extend(kk_std_core_new_any_fun24313(predicate0, xx0, _ctx), _ctx); /*3991*/
      return kk_bool_unbox(_x24312);
    }
    if (x0_21485) {
      kk_function_drop(predicate0, _ctx);
      kk_std_core__list_drop(xx0, _ctx);
      return true;
    }
    { // tailcall
      xs = xx0;
      goto kk__tailcall;
    }
  }
  kk_function_drop(predicate0, _ctx);
  return false;
}
 
// Return the element at position `index` in vector `v`, or `Nothing` if out of bounds

kk_std_core_types__maybe kk_std_core_at(kk_vector_t v, kk_integer_t index, kk_context_t* _ctx) { /* forall<a> (v : vector<a>, index : int) -> maybe<a> */ 
  size_t idx = kk_std_core_size__t(index, _ctx); /*size_t*/;
  bool _match_23555;
  size_t _x24316;
  kk_vector_t _x24317 = kk_vector_dup(v); /*vector<12323>*/
  _x24316 = kk_vector_len(_x24317); /*size_t*/
  _match_23555 = (_x24316 <= idx); /*bool*/
  if (_match_23555) {
    kk_vector_drop(v, _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
  kk_box_t _x24318 = kk_vector_at(v,idx); /*216*/
  return kk_std_core_types__new_Just(_x24318, _ctx);
}
 
// O(`n`). The first `n` (default = `1`) characters in a string.

kk_std_core__sslice kk_std_core_first(kk_string_t s, kk_std_core_types__optional n, kk_context_t* _ctx) { /* (s : string, n : optional<int>) -> sslice */ 
  kk_std_core__sslice slice0 = kk_std_core_first1(s, _ctx); /*sslice*/;
  bool _match_23554;
  kk_integer_t _x24322;
  if (kk_std_core_types__is_Optional(n)) {
    kk_box_t _box_x22414 = n._cons.Optional.value;
    kk_integer_t _n_12425 = kk_integer_unbox(_box_x22414);
    kk_integer_dup(_n_12425);
    _x24322 = _n_12425; /*int*/
    goto _match24323;
  }
  _x24322 = kk_integer_from_small(1); /*int*/
  _match24323: ;
  _match_23554 = kk_integer_eq(_x24322,(kk_integer_from_small(1)),kk_context()); /*bool*/
  if (_match_23554) {
    kk_std_core_types__optional_drop(n, _ctx);
    return slice0;
  }
  kk_integer_t _x24325;
  kk_integer_t _x24326;
  if (kk_std_core_types__is_Optional(n)) {
    kk_box_t _box_x22415 = n._cons.Optional.value;
    kk_integer_t _n_124250 = kk_integer_unbox(_box_x22415);
    _x24326 = _n_124250; /*int*/
    goto _match24327;
  }
  _x24326 = kk_integer_from_small(1); /*int*/
  _match24327: ;
  _x24325 = kk_integer_sub(_x24326,(kk_integer_from_small(1)),kk_context()); /*int*/
  return kk_std_core_extend(slice0, _x24325, _ctx);
}
 
// Convert the first character of a string to uppercase.

kk_string_t kk_std_core_capitalize(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> string */ 
  kk_string_t _x24329;
  kk_string_t _x24330;
  kk_std_core__sslice _x24331;
  kk_std_core__sslice slice0;
  kk_string_t _x24332 = kk_string_dup(s); /*string*/
  slice0 = kk_std_core_first1(_x24332, _ctx); /*sslice*/
  bool _match_23551;
  kk_integer_t _x24333;
  kk_std_core_types__optional _x24334 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/
  if (kk_std_core_types__is_Optional(_x24334)) {
    kk_box_t _box_x22416 = _x24334._cons.Optional.value;
    kk_integer_t _n_12425 = kk_integer_unbox(_box_x22416);
    _x24333 = _n_12425; /*int*/
    goto _match24335;
  }
  _x24333 = kk_integer_from_small(1); /*int*/
  _match24335: ;
  _match_23551 = kk_integer_eq(_x24333,(kk_integer_from_small(1)),kk_context()); /*bool*/
  if (_match_23551) {
    _x24331 = slice0; /*sslice*/
  }
  else {
    kk_integer_t _x24337;
    kk_integer_t _x24338;
    kk_std_core_types__optional _x24339 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/
    if (kk_std_core_types__is_Optional(_x24339)) {
      kk_box_t _box_x22417 = _x24339._cons.Optional.value;
      kk_integer_t _n_124250 = kk_integer_unbox(_box_x22417);
      _x24338 = _n_124250; /*int*/
      goto _match24340;
    }
    _x24338 = kk_integer_from_small(1); /*int*/
    _match24340: ;
    _x24337 = kk_integer_sub(_x24338,(kk_integer_from_small(1)),kk_context()); /*int*/
    _x24331 = kk_std_core_extend(slice0, _x24337, _ctx); /*sslice*/
  }
  _x24330 = kk_std_core_string_3(_x24331, _ctx); /*string*/
  _x24329 = kk_std_core_to_upper(_x24330, _ctx); /*string*/
  kk_string_t _x24342;
  kk_std_core__sslice _x24343;
  kk_std_core__sslice slice0_21491;
  kk_std_core__sslice slice1 = kk_std_core_first1(s, _ctx); /*sslice*/;
  bool _match_23548;
  kk_integer_t _x24344;
  kk_std_core_types__optional _x24345 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/
  if (kk_std_core_types__is_Optional(_x24345)) {
    kk_box_t _box_x22418 = _x24345._cons.Optional.value;
    kk_integer_t _n_124251 = kk_integer_unbox(_box_x22418);
    _x24344 = _n_124251; /*int*/
    goto _match24346;
  }
  _x24344 = kk_integer_from_small(1); /*int*/
  _match24346: ;
  _match_23548 = kk_integer_eq(_x24344,(kk_integer_from_small(1)),kk_context()); /*bool*/
  if (_match_23548) {
    slice0_21491 = slice1; /*sslice*/
  }
  else {
    kk_integer_t _x24348;
    kk_integer_t _x24349;
    kk_std_core_types__optional _x24350 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/
    if (kk_std_core_types__is_Optional(_x24350)) {
      kk_box_t _box_x22419 = _x24350._cons.Optional.value;
      kk_integer_t _n_124252 = kk_integer_unbox(_box_x22419);
      _x24349 = _n_124252; /*int*/
      goto _match24351;
    }
    _x24349 = kk_integer_from_small(1); /*int*/
    _match24351: ;
    _x24348 = kk_integer_sub(_x24349,(kk_integer_from_small(1)),kk_context()); /*int*/
    slice0_21491 = kk_std_core_extend(slice1, _x24348, _ctx); /*sslice*/
  }
  kk_string_t s1 = slice0_21491.str;
  size_t start0 = slice0_21491.start;
  size_t len0 = slice0_21491.len;
  kk_string_dup(s1);
  kk_std_core__sslice_drop(slice0_21491, _ctx);
  kk_string_t _x24353 = kk_string_dup(s1); /*string*/
  size_t _x24354 = (start0 + len0); /*size_t*/
  size_t _x24355;
  size_t _x24356 = kk_string_len(s1,kk_context()); /*size_t*/
  size_t _x24357 = (start0 + len0); /*size_t*/
  _x24355 = (_x24356 - _x24357); /*size_t*/
  _x24343 = kk_std_core__new_Sslice(_x24353, _x24354, _x24355, _ctx); /*sslice*/
  _x24342 = kk_std_core_string_3(_x24343, _ctx); /*string*/
  return kk_std_core__lp__plus__plus__1_rp_(_x24329, _x24342, _ctx);
}
 
// Catch any exception raised in `action` and handle it.
// Use `on-exn` or `on-exit` when appropiate.


// lift anonymous function
struct kk_std_core_try_fun24360__t {
  struct kk_function_s _base;
  kk_function_t hndl;
};
static kk_box_t kk_std_core_try_fun24360(kk_function_t _fself, kk_box_t _b_22421, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_try_fun24360(kk_function_t hndl, kk_context_t* _ctx) {
  struct kk_std_core_try_fun24360__t* _self = kk_function_alloc_as(struct kk_std_core_try_fun24360__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_try_fun24360, kk_context());
  _self->hndl = hndl;
  return &_self->_base;
}

static kk_box_t kk_std_core_try_fun24360(kk_function_t _fself, kk_box_t _b_22421, kk_context_t* _ctx) {
  struct kk_std_core_try_fun24360__t* _self = kk_function_as(struct kk_std_core_try_fun24360__t*, _fself);
  kk_function_t hndl = _self->hndl; /* (exception) -> 12648 12647 */
  kk_drop_match(_self, {kk_function_dup(hndl);}, {}, _ctx)
  kk_std_core__exception _x24361 = kk_std_core__exception_unbox(_b_22421, _ctx); /*exception*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_std_core__exception, kk_context_t*), hndl, (hndl, _x24361, _ctx));
}


// lift anonymous function
struct kk_std_core_try_fun24362__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_try_fun24362(kk_function_t _fself, kk_box_t _x, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_try_fun24362(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_try_fun24362, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_core_try_fun24362(kk_function_t _fself, kk_box_t _x, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return _x;
}

kk_box_t kk_std_core_try(kk_function_t action, kk_function_t hndl, kk_context_t* _ctx) { /* forall<a,e> (action : () -> <exn|e> a, hndl : (exception) -> e a) -> e a */ 
  kk_std_core__hnd_exn _x24358;
  kk_std_core_hnd__clause1 _x24359 = kk_std_core_hnd_clause_never1(kk_std_core_new_try_fun24360(hndl, _ctx), _ctx); /*std/core/hnd/clause1<7986,7987,7989,7988,7990>*/
  _x24358 = kk_std_core__new_Hnd_exn(kk_reuse_null, _x24359, _ctx); /*.hnd-exn<11,12>*/
  return kk_std_core__handle_exn(((int32_t)0), _x24358, kk_std_core_new_try_fun24362(_ctx), action, _ctx);
}
 
// monadic lift

kk_std_core__error kk_std_core__mlift21193_try_1(kk_box_t _y_87, kk_context_t* _ctx) { /* forall<a,e> (a) -> <exn|e> error<a> */ 
  return kk_std_core__new_Ok(_y_87, _ctx);
}
 
// Transform an exception effect to an  `:error` type.


// lift anonymous function
struct kk_std_core_try_fun24364__t_1 {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_try_fun24364_1(kk_function_t _fself, kk_std_core_hnd__marker _b_22428, kk_std_core_hnd__ev _b_22429, kk_box_t _b_22430, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_try_fun24364_1(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_try_fun24364_1, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_std_core_try_fun24365__t_1 {
  struct kk_function_s _base;
  kk_box_t _b_22430;
};
static kk_box_t kk_std_core_try_fun24365_1(kk_function_t _fself, kk_function_t _b_22425, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_try_fun24365_1(kk_box_t _b_22430, kk_context_t* _ctx) {
  struct kk_std_core_try_fun24365__t_1* _self = kk_function_alloc_as(struct kk_std_core_try_fun24365__t_1, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_try_fun24365_1, kk_context());
  _self->_b_22430 = _b_22430;
  return &_self->_base;
}

static kk_box_t kk_std_core_try_fun24365_1(kk_function_t _fself, kk_function_t _b_22425, kk_context_t* _ctx) {
  struct kk_std_core_try_fun24365__t_1* _self = kk_function_as(struct kk_std_core_try_fun24365__t_1*, _fself);
  kk_box_t _b_22430 = _self->_b_22430; /* 52 */
  kk_drop_match(_self, {kk_box_dup(_b_22430);}, {}, _ctx)
  kk_function_drop(_b_22425, _ctx);
  kk_std_core__error _x24366;
  kk_std_core__exception _x24367 = kk_std_core__exception_unbox(_b_22430, _ctx); /*exception*/
  _x24366 = kk_std_core__new_Error(_x24367, _ctx); /*error<30>*/
  return kk_std_core__error_box(_x24366, _ctx);
}
static kk_box_t kk_std_core_try_fun24364_1(kk_function_t _fself, kk_std_core_hnd__marker _b_22428, kk_std_core_hnd__ev _b_22429, kk_box_t _b_22430, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core_hnd__ev_dropn(_b_22429, ((int32_t)3), _ctx);
  return kk_std_core_hnd_yield_to_final(_b_22428, kk_std_core_new_try_fun24365_1(_b_22430, _ctx), _ctx);
}


// lift anonymous function
struct kk_std_core_try_fun24369__t_1 {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_try_fun24369_1(kk_function_t _fself, kk_box_t _b_22437, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_try_fun24369_1(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_try_fun24369_1, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_core_try_fun24369_1(kk_function_t _fself, kk_box_t _b_22437, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return _b_22437;
}


// lift anonymous function
struct kk_std_core_try_fun24370__t_1 {
  struct kk_function_s _base;
  kk_function_t action;
};
static kk_box_t kk_std_core_try_fun24370_1(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_try_fun24370_1(kk_function_t action, kk_context_t* _ctx) {
  struct kk_std_core_try_fun24370__t_1* _self = kk_function_alloc_as(struct kk_std_core_try_fun24370__t_1, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_try_fun24370_1, kk_context());
  _self->action = action;
  return &_self->_base;
}



// lift anonymous function
struct kk_std_core_try_fun24373__t_1 {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_try_fun24373_1(kk_function_t _fself, kk_box_t _b_22432, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_try_fun24373_1(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_try_fun24373_1, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_core_try_fun24373_1(kk_function_t _fself, kk_box_t _b_22432, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core__error _x24374 = kk_std_core__mlift21193_try_1(_b_22432, _ctx); /*error<12686>*/
  return kk_std_core__error_box(_x24374, _ctx);
}
static kk_box_t kk_std_core_try_fun24370_1(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_core_try_fun24370__t_1* _self = kk_function_as(struct kk_std_core_try_fun24370__t_1*, _fself);
  kk_function_t action = _self->action; /* () -> <exn|12687> 12686 */
  kk_drop_match(_self, {kk_function_dup(action);}, {}, _ctx)
  kk_std_core__error _x24371;
  kk_box_t x_21496 = kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), action, (action, _ctx)); /*12686*/;
  if (kk_yielding(kk_context())) {
    kk_box_drop(x_21496, _ctx);
    kk_box_t _x24372 = kk_std_core_hnd_yield_extend(kk_std_core_new_try_fun24373_1(_ctx), _ctx); /*3991*/
    _x24371 = kk_std_core__error_unbox(_x24372, _ctx); /*error<12686>*/
  }
  else {
    _x24371 = kk_std_core__mlift21193_try_1(x_21496, _ctx); /*error<12686>*/
  }
  return kk_std_core__error_box(_x24371, _ctx);
}

kk_std_core__error kk_std_core_try_1(kk_function_t action, kk_context_t* _ctx) { /* forall<a,e> (action : () -> <exn|e> a) -> e error<a> */ 
  int32_t _b_22438_22433 = ((int32_t)0); /*int32*/;
  kk_std_core__hnd_exn _b_22439_22434;
  kk_std_core_hnd__clause1 _x24363 = kk_std_core_hnd__new_Clause1(kk_std_core_new_try_fun24364_1(_ctx), _ctx); /*std/core/hnd/clause1<52,53,54,55,56>*/
  _b_22439_22434 = kk_std_core__new_Hnd_exn(kk_reuse_null, _x24363, _ctx); /*.hnd-exn<12687,error<12686>>*/
  kk_box_t _x24368 = kk_std_core__handle_exn(_b_22438_22433, _b_22439_22434, kk_std_core_new_try_fun24369_1(_ctx), kk_std_core_new_try_fun24370_1(action, _ctx), _ctx); /*1966*/
  return kk_std_core__error_unbox(_x24368, _ctx);
}

kk_std_core_types__tuple2_ kk_std_core_cdivmod_exp10(kk_integer_t i, kk_integer_t n, kk_context_t* _ctx) { /* (i : int, n : int) -> (int, int) */ 
  bool _match_23546;
  kk_integer_t _x24377 = kk_integer_dup(n); /*int*/
  _match_23546 = kk_integer_lte(_x24377,(kk_integer_from_small(0)),kk_context()); /*bool*/
  if (_match_23546) {
    kk_integer_drop(n, _ctx);
    return kk_std_core_types__new_dash__lp__comma__rp_(kk_integer_box(i), kk_integer_box(kk_integer_from_small(0)), _ctx);
  }
  kk_integer_t cq;
  kk_integer_t _x24378 = kk_integer_dup(i); /*int*/
  kk_integer_t _x24379 = kk_integer_dup(n); /*int*/
  cq = kk_std_core_cdiv_exp10(_x24378, _x24379, _ctx); /*int*/
  kk_integer_t cr;
  kk_integer_t _x24380;
  kk_integer_t _x24381 = kk_integer_dup(cq); /*int*/
  _x24380 = kk_std_core_mul_exp10(_x24381, n, _ctx); /*int*/
  cr = kk_integer_sub(i,_x24380,kk_context()); /*int*/
  return kk_std_core_types__new_dash__lp__comma__rp_(kk_integer_box(cq), kk_integer_box(cr), _ctx);
}
 
// Concatenate a list of `:maybe` values

kk_std_core__list kk_std_core__ctail_concat_maybe(kk_std_core__list xs, kk_std_core_types__ctail _acc, kk_context_t* _ctx) { /* forall<a> (xs : list<maybe<a>>, ctail<list<a>>) -> list<a> */ 
  kk__tailcall: ;
  if (kk_std_core__is_Cons(xs)) {
    struct kk_std_core_Cons* _con24382 = kk_std_core__as_Cons(xs);
    kk_box_t _box_x22460 = _con24382->head;
    kk_std_core__list xx = _con24382->tail;
    kk_std_core_types__maybe x = kk_std_core_types__maybe_unbox(_box_x22460, NULL);
    kk_reuse_t _ru_23366 = kk_reuse_null; /*reuse*/;
    if (kk_std_core__list_is_unique(xs)) {
      kk_std_core_types__maybe_dup(x);
      kk_box_drop(_box_x22460, _ctx);
      _ru_23366 = (kk_std_core__list_reuse(xs));
    }
    else {
      kk_std_core_types__maybe_dup(x);
      kk_std_core__list_dup(xx);
      kk_std_core__list_decref(xs, _ctx);
      _ru_23366 = kk_reuse_null;
    }
    if (kk_std_core_types__is_Just(x)) {
      kk_box_t y = x._cons.Just.value;
      kk_std_core__list _ctail_21129 = kk_std_core__list_hole(); /*list<12852>*/;
      kk_std_core__list _ctail_21130 = kk_std_core__new_Cons(_ru_23366, y, _ctail_21129, _ctx); /*list<12852>*/;
      { // tailcall
        kk_std_core_types__ctail _x24384;
        kk_box_t* field_21500 = (kk_box_t*)((&kk_std_core__as_Cons(_ctail_21130)->tail)); /*cfield<list<12852>>*/;
        if (kk_std_core_types__is_CTail(_acc)) {
          kk_box_t _box_x22467 = _acc._cons.CTail._field1;
          kk_box_t* last0 = _acc._cons.CTail._field2;
          kk_std_core__list head0 = kk_std_core__list_unbox(_box_x22467, NULL);
          kk_unit_t __ = kk_Unit;
          *(last0) = kk_std_core__list_box(_ctail_21130, _ctx);
          _x24384 = kk_std_core_types__new_CTail(kk_std_core__list_box(head0, _ctx), field_21500, _ctx); /*ctail<58>*/
          goto _match24385;
        }
        _x24384 = kk_std_core_types__new_CTail(kk_std_core__list_box(_ctail_21130, _ctx), field_21500, _ctx); /*ctail<58>*/
        _match24385: ;
        xs = xx;
        _acc = _x24384;
        goto kk__tailcall;
      }
    }
    kk_reuse_drop(_ru_23366, _ctx);
    { // tailcall
      xs = xx;
      goto kk__tailcall;
    }
  }
  if (kk_std_core_types__is_CTail(_acc)) {
    kk_box_t _box_x22476 = _acc._cons.CTail._field1;
    kk_box_t* last00 = _acc._cons.CTail._field2;
    kk_std_core__list head00 = kk_std_core__list_unbox(_box_x22476, NULL);
    kk_unit_t __0 = kk_Unit;
    *(last00) = kk_std_core__list_box(kk_std_core__new_Nil(_ctx), _ctx);
    return head00;
  }
  return kk_std_core__new_Nil(_ctx);
}
 
// Concatenate a list of `:maybe` values

kk_std_core__list kk_std_core_concat_maybe(kk_std_core__list xs0, kk_context_t* _ctx) { /* forall<a> (xs : list<maybe<a>>) -> list<a> */ 
  return kk_std_core__ctail_concat_maybe(xs0, kk_std_core_types__new_CTailNil(_ctx), _ctx);
}
 
// monadic lift

kk_std_core_types__maybe kk_std_core__mlift21194_op(kk_function_t action, size_t end, size_t i, kk_std_core_types__maybe _y_90, kk_context_t* _ctx) { /* forall<a,e> (action : (size_t) -> e maybe<a>, end : size_t, i : size_t, maybe<a>) -> e maybe<a> */ 
  if (kk_std_core_types__is_Nothing(_y_90)) {
    size_t i0_21083 = kk_std_core_incr_1(i, _ctx); /*size_t*/;
    return kk_std_core__lift21055_for_whilez(action, end, i0_21083, _ctx);
  }
  kk_box_t x = _y_90._cons.Just.value;
  kk_function_drop(action, _ctx);
  return kk_std_core_types__new_Just(x, _ctx);
}
 
// lift


// lift anonymous function
struct kk_std_core__lift21055_for_whilez_fun24390__t {
  struct kk_function_s _base;
  kk_function_t action0;
  size_t end0;
  size_t i0;
};
static kk_box_t kk_std_core__lift21055_for_whilez_fun24390(kk_function_t _fself, kk_box_t _b_22486, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_lift21055_for_whilez_fun24390(kk_function_t action0, size_t end0, size_t i0, kk_context_t* _ctx) {
  struct kk_std_core__lift21055_for_whilez_fun24390__t* _self = kk_function_alloc_as(struct kk_std_core__lift21055_for_whilez_fun24390__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__lift21055_for_whilez_fun24390, kk_context());
  _self->action0 = action0;
  _self->end0 = end0;
  _self->i0 = i0;
  return &_self->_base;
}

static kk_box_t kk_std_core__lift21055_for_whilez_fun24390(kk_function_t _fself, kk_box_t _b_22486, kk_context_t* _ctx) {
  struct kk_std_core__lift21055_for_whilez_fun24390__t* _self = kk_function_as(struct kk_std_core__lift21055_for_whilez_fun24390__t*, _fself);
  kk_function_t action0 = _self->action0; /* (size_t) -> 12854 maybe<12853> */
  size_t end0 = _self->end0; /* size_t */
  size_t i0 = _self->i0; /* size_t */
  kk_drop_match(_self, {kk_function_dup(action0);;;}, {}, _ctx)
  kk_std_core_types__maybe _x24391;
  kk_std_core_types__maybe _x24392 = kk_std_core_types__maybe_unbox(_b_22486, _ctx); /*maybe<12853>*/
  _x24391 = kk_std_core__mlift21194_op(action0, end0, i0, _x24392, _ctx); /*maybe<12853>*/
  return kk_std_core_types__maybe_box(_x24391, _ctx);
}

kk_std_core_types__maybe kk_std_core__lift21055_for_whilez(kk_function_t action0, size_t end0, size_t i0, kk_context_t* _ctx) { /* forall<a,e> (action : (size_t) -> e maybe<a>, end : size_t, i : size_t) -> e maybe<a> */ 
  kk__tailcall: ;
  bool _match_23544 = (i0 <= end0); /*bool*/;
  if (_match_23544) {
    kk_std_core_types__maybe x_21503;
    kk_function_t _x24388 = kk_function_dup(action0); /*(size_t) -> 12854 maybe<12853>*/
    x_21503 = kk_function_call(kk_std_core_types__maybe, (kk_function_t, size_t, kk_context_t*), _x24388, (_x24388, i0, _ctx)); /*maybe<12853>*/
    if (kk_yielding(kk_context())) {
      kk_std_core_types__maybe_drop(x_21503, _ctx);
      kk_box_t _x24389 = kk_std_core_hnd_yield_extend(kk_std_core__new_lift21055_for_whilez_fun24390(action0, end0, i0, _ctx), _ctx); /*3991*/
      return kk_std_core_types__maybe_unbox(_x24389, _ctx);
    }
    if (kk_std_core_types__is_Nothing(x_21503)) {
      size_t i0_210830 = kk_std_core_incr_1(i0, _ctx); /*size_t*/;
      { // tailcall
        i0 = i0_210830;
        goto kk__tailcall;
      }
    }
    kk_box_t x0 = x_21503._cons.Just.value;
    kk_function_drop(action0, _ctx);
    return kk_std_core_types__new_Just(x0, _ctx);
  }
  kk_function_drop(action0, _ctx);
  return kk_std_core_types__new_Nothing(_ctx);
}
 
// monadic lift

kk_std_core_types__maybe kk_std_core__mlift21195_foreach_while(kk_function_t action, kk_std_core__list xx, kk_std_core_types__maybe _y_95, kk_context_t* _ctx) { /* forall<a,b,e> (action : (a) -> e maybe<b>, xx : list<a>, maybe<b>) -> e maybe<b> */ 
  if (kk_std_core_types__is_Nothing(_y_95)) {
    return kk_std_core_foreach_while(xx, action, _ctx);
  }
  kk_function_drop(action, _ctx);
  kk_std_core__list_drop(xx, _ctx);
  return _y_95;
}
 
// Invoke `action` for each element of a list while `action` return `Nothing`


// lift anonymous function
struct kk_std_core_foreach_while_fun24399__t {
  struct kk_function_s _base;
  kk_function_t action0;
  kk_std_core__list xx0;
};
static kk_box_t kk_std_core_foreach_while_fun24399(kk_function_t _fself, kk_box_t _b_22490, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_foreach_while_fun24399(kk_function_t action0, kk_std_core__list xx0, kk_context_t* _ctx) {
  struct kk_std_core_foreach_while_fun24399__t* _self = kk_function_alloc_as(struct kk_std_core_foreach_while_fun24399__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_foreach_while_fun24399, kk_context());
  _self->action0 = action0;
  _self->xx0 = xx0;
  return &_self->_base;
}

static kk_box_t kk_std_core_foreach_while_fun24399(kk_function_t _fself, kk_box_t _b_22490, kk_context_t* _ctx) {
  struct kk_std_core_foreach_while_fun24399__t* _self = kk_function_as(struct kk_std_core_foreach_while_fun24399__t*, _fself);
  kk_function_t action0 = _self->action0; /* (13066) -> 13068 maybe<13067> */
  kk_std_core__list xx0 = _self->xx0; /* list<13066> */
  kk_drop_match(_self, {kk_function_dup(action0);kk_std_core__list_dup(xx0);}, {}, _ctx)
  kk_std_core_types__maybe _x24400;
  kk_std_core_types__maybe _x24401 = kk_std_core_types__maybe_unbox(_b_22490, _ctx); /*maybe<13067>*/
  _x24400 = kk_std_core__mlift21195_foreach_while(action0, xx0, _x24401, _ctx); /*maybe<13067>*/
  return kk_std_core_types__maybe_box(_x24400, _ctx);
}

kk_std_core_types__maybe kk_std_core_foreach_while(kk_std_core__list xs, kk_function_t action0, kk_context_t* _ctx) { /* forall<a,b,e> (xs : list<a>, action : (a) -> e maybe<b>) -> e maybe<b> */ 
  kk__tailcall: ;
  if (kk_std_core__is_Nil(xs)) {
    kk_function_drop(action0, _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
  struct kk_std_core_Cons* _con24396 = kk_std_core__as_Cons(xs);
  kk_box_t x = _con24396->head;
  kk_std_core__list xx0 = _con24396->tail;
  if (kk_std_core__list_is_unique(xs)) {
    kk_std_core__list_free(xs);
  }
  else {
    kk_box_dup(x);
    kk_std_core__list_dup(xx0);
    kk_std_core__list_decref(xs, _ctx);
  }
  kk_std_core_types__maybe x0_21507;
  kk_function_t _x24397 = kk_function_dup(action0); /*(13066) -> 13068 maybe<13067>*/
  x0_21507 = kk_function_call(kk_std_core_types__maybe, (kk_function_t, kk_box_t, kk_context_t*), _x24397, (_x24397, x, _ctx)); /*maybe<13067>*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__maybe_drop(x0_21507, _ctx);
    kk_box_t _x24398 = kk_std_core_hnd_yield_extend(kk_std_core_new_foreach_while_fun24399(action0, xx0, _ctx), _ctx); /*3991*/
    return kk_std_core_types__maybe_unbox(_x24398, _ctx);
  }
  if (kk_std_core_types__is_Nothing(x0_21507)) {
    { // tailcall
      xs = xx0;
      goto kk__tailcall;
    }
  }
  kk_function_drop(action0, _ctx);
  kk_std_core__list_drop(xx0, _ctx);
  return x0_21507;
}
 
// monadic lift

kk_std_core_types__maybe kk_std_core__mlift21196_foreach_while_1(kk_function_t action, kk_std_core__sslice rest, kk_std_core_types__maybe _y_99, kk_context_t* _ctx) { /* forall<a,e> (action : (c : char) -> e maybe<a>, rest : sslice, maybe<a>) -> e maybe<a> */ 
  if (kk_std_core_types__is_Nothing(_y_99)) {
    return kk_std_core_foreach_while_1(rest, action, _ctx);
  }
  kk_function_drop(action, _ctx);
  kk_std_core__sslice_drop(rest, _ctx);
  return _y_99;
}
 
// Apply a function for each character in a string slice.
// If `action` returns `Just`, the function returns immediately with that result.


// lift anonymous function
struct kk_std_core_foreach_while_fun24407__t_1 {
  struct kk_function_s _base;
  kk_function_t action0;
  kk_std_core__sslice rest0;
};
static kk_box_t kk_std_core_foreach_while_fun24407_1(kk_function_t _fself, kk_box_t _b_22497, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_foreach_while_fun24407_1(kk_function_t action0, kk_std_core__sslice rest0, kk_context_t* _ctx) {
  struct kk_std_core_foreach_while_fun24407__t_1* _self = kk_function_alloc_as(struct kk_std_core_foreach_while_fun24407__t_1, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_foreach_while_fun24407_1, kk_context());
  _self->action0 = action0;
  _self->rest0 = rest0;
  return &_self->_base;
}

static kk_box_t kk_std_core_foreach_while_fun24407_1(kk_function_t _fself, kk_box_t _b_22497, kk_context_t* _ctx) {
  struct kk_std_core_foreach_while_fun24407__t_1* _self = kk_function_as(struct kk_std_core_foreach_while_fun24407__t_1*, _fself);
  kk_function_t action0 = _self->action0; /* (c : char) -> 13155 maybe<13154> */
  kk_std_core__sslice rest0 = _self->rest0; /* sslice */
  kk_drop_match(_self, {kk_function_dup(action0);kk_std_core__sslice_dup(rest0);}, {}, _ctx)
  kk_std_core_types__maybe _x24408;
  kk_std_core_types__maybe _x24409 = kk_std_core_types__maybe_unbox(_b_22497, _ctx); /*maybe<13154>*/
  _x24408 = kk_std_core__mlift21196_foreach_while_1(action0, rest0, _x24409, _ctx); /*maybe<13154>*/
  return kk_std_core_types__maybe_box(_x24408, _ctx);
}

kk_std_core_types__maybe kk_std_core_foreach_while_1(kk_std_core__sslice slice0, kk_function_t action0, kk_context_t* _ctx) { /* forall<a,e> (slice : sslice, action : (c : char) -> e maybe<a>) -> e maybe<a> */ 
  kk__tailcall: ;
  kk_std_core_types__maybe _match_23541 = kk_std_core_next(slice0, _ctx); /*maybe<(char, sslice)>*/;
  if (kk_std_core_types__is_Nothing(_match_23541)) {
    kk_function_drop(action0, _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
  kk_box_t _box_x22493 = _match_23541._cons.Just.value;
  kk_std_core_types__tuple2_ _pat1 = kk_std_core_types__tuple2__unbox(_box_x22493, NULL);
  kk_box_t _box_x22494 = _pat1.fst;
  kk_box_t _box_x22495 = _pat1.snd;
  kk_char_t c = kk_char_unbox(_box_x22494, NULL);
  kk_std_core__sslice rest0 = kk_std_core__sslice_unbox(_box_x22495, NULL);
  kk_std_core__sslice_dup(rest0);
  kk_std_core_types__maybe_drop(_match_23541, _ctx);
  kk_std_core_types__maybe x_21511;
  kk_function_t _x24405 = kk_function_dup(action0); /*(c : char) -> 13155 maybe<13154>*/
  x_21511 = kk_function_call(kk_std_core_types__maybe, (kk_function_t, kk_char_t, kk_context_t*), _x24405, (_x24405, c, _ctx)); /*maybe<13154>*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__maybe_drop(x_21511, _ctx);
    kk_box_t _x24406 = kk_std_core_hnd_yield_extend(kk_std_core_new_foreach_while_fun24407_1(action0, rest0, _ctx), _ctx); /*3991*/
    return kk_std_core_types__maybe_unbox(_x24406, _ctx);
  }
  if (kk_std_core_types__is_Nothing(x_21511)) {
    { // tailcall
      slice0 = rest0;
      goto kk__tailcall;
    }
  }
  kk_function_drop(action0, _ctx);
  kk_std_core__sslice_drop(rest0, _ctx);
  return x_21511;
}
 
// Invoke a function `f` for each element in a vector `v`.
// If `f` returns `Just`, the iteration is stopped early and the result is returned.


// lift anonymous function
struct kk_std_core_foreach_while_fun24413__t_3 {
  struct kk_function_s _base;
  kk_function_t f;
  kk_vector_t v;
};
static kk_std_core_types__maybe kk_std_core_foreach_while_fun24413_3(kk_function_t _fself, size_t i, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_foreach_while_fun24413_3(kk_function_t f, kk_vector_t v, kk_context_t* _ctx) {
  struct kk_std_core_foreach_while_fun24413__t_3* _self = kk_function_alloc_as(struct kk_std_core_foreach_while_fun24413__t_3, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_foreach_while_fun24413_3, kk_context());
  _self->f = f;
  _self->v = v;
  return &_self->_base;
}

static kk_std_core_types__maybe kk_std_core_foreach_while_fun24413_3(kk_function_t _fself, size_t i, kk_context_t* _ctx) {
  struct kk_std_core_foreach_while_fun24413__t_3* _self = kk_function_as(struct kk_std_core_foreach_while_fun24413__t_3*, _fself);
  kk_function_t f = _self->f; /* (13257) -> 13259 maybe<13258> */
  kk_vector_t v = _self->v; /* vector<13257> */
  kk_drop_match(_self, {kk_function_dup(f);kk_vector_dup(v);}, {}, _ctx)
  kk_box_t _x24414 = kk_vector_at(v,i); /*216*/
  return kk_function_call(kk_std_core_types__maybe, (kk_function_t, kk_box_t, kk_context_t*), f, (f, _x24414, _ctx));
}

kk_std_core_types__maybe kk_std_core_foreach_while_3(kk_vector_t v, kk_function_t f, kk_context_t* _ctx) { /* forall<a,b,e> (v : vector<a>, f : (a) -> e maybe<b>) -> e maybe<b> */ 
  size_t start_21515 = ((size_t)0); /*size_t*/;
  size_t end_21516;
  size_t _x24411;
  kk_vector_t _x24412 = kk_vector_dup(v); /*vector<13257>*/
  _x24411 = kk_vector_len(_x24412); /*size_t*/
  end_21516 = kk_std_core_decr_1(_x24411, _ctx); /*size_t*/
  return kk_std_core__lift21055_for_whilez(kk_std_core_new_foreach_while_fun24413_3(f, v, _ctx), end_21516, start_21515, _ctx);
}
 
// monadic lift

kk_unit_t kk_std_core__mlift21197_foreach(kk_function_t action, kk_std_core__list xx, kk_unit_t wild__, kk_context_t* _ctx) { /* forall<a,e> (action : (a) -> e (), xx : list<a>, wild_ : ()) -> e () */ 
  kk_std_core_foreach(xx, action, _ctx); return kk_Unit;
}
 
// Invoke `action` for each element of a list


// lift anonymous function
struct kk_std_core_foreach_fun24418__t {
  struct kk_function_s _base;
  kk_function_t action0;
  kk_std_core__list xx0;
};
static kk_box_t kk_std_core_foreach_fun24418(kk_function_t _fself, kk_box_t _b_22501, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_foreach_fun24418(kk_function_t action0, kk_std_core__list xx0, kk_context_t* _ctx) {
  struct kk_std_core_foreach_fun24418__t* _self = kk_function_alloc_as(struct kk_std_core_foreach_fun24418__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_foreach_fun24418, kk_context());
  _self->action0 = action0;
  _self->xx0 = xx0;
  return &_self->_base;
}

static kk_box_t kk_std_core_foreach_fun24418(kk_function_t _fself, kk_box_t _b_22501, kk_context_t* _ctx) {
  struct kk_std_core_foreach_fun24418__t* _self = kk_function_as(struct kk_std_core_foreach_fun24418__t*, _fself);
  kk_function_t action0 = _self->action0; /* (13452) -> 13453 () */
  kk_std_core__list xx0 = _self->xx0; /* list<13452> */
  kk_drop_match(_self, {kk_function_dup(action0);kk_std_core__list_dup(xx0);}, {}, _ctx)
  kk_unit_t _x24419 = kk_Unit;
  kk_unit_t _x24420 = kk_Unit;
  kk_unit_unbox(_b_22501);
  kk_std_core__mlift21197_foreach(action0, xx0, _x24420, _ctx);
  return kk_unit_box(_x24419);
}

kk_unit_t kk_std_core_foreach(kk_std_core__list xs, kk_function_t action0, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, action : (a) -> e ()) -> e () */ 
  kk__tailcall: ;
  if (kk_std_core__is_Nil(xs)) {
    kk_function_drop(action0, _ctx);
    kk_Unit; return kk_Unit;
  }
  struct kk_std_core_Cons* _con24415 = kk_std_core__as_Cons(xs);
  kk_box_t x = _con24415->head;
  kk_std_core__list xx0 = _con24415->tail;
  if (kk_std_core__list_is_unique(xs)) {
    kk_std_core__list_free(xs);
  }
  else {
    kk_box_dup(x);
    kk_std_core__list_dup(xx0);
    kk_std_core__list_decref(xs, _ctx);
  }
  kk_unit_t x0_21518 = kk_Unit;
  kk_function_t _x24416 = kk_function_dup(action0); /*(13452) -> 13453 ()*/
  kk_function_call(kk_unit_t, (kk_function_t, kk_box_t, kk_context_t*), _x24416, (_x24416, x, _ctx));
  if (kk_yielding(kk_context())) {
    kk_box_t _x24417 = kk_std_core_hnd_yield_extend(kk_std_core_new_foreach_fun24418(action0, xx0, _ctx), _ctx); /*3991*/
    kk_unit_unbox(_x24417); return kk_Unit;
  }
  { // tailcall
    xs = xx0;
    goto kk__tailcall;
  }
}
 
// monadic lift

kk_std_core_types__maybe kk_std_core__mlift21198_foreach_1(kk_unit_t wild__, kk_context_t* _ctx) { /* forall<_a,e> (wild_ : ()) -> e maybe<_a> */ 
  return kk_std_core_types__new_Nothing(_ctx);
}
 
// monadic lift

kk_unit_t kk_std_core__mlift21199_foreach_1(kk_std_core_types__maybe wild__0, kk_context_t* _ctx) { /* forall<_a,e> (wild_0 : maybe<_a>) -> e () */ 
  kk_std_core_types__maybe_drop(wild__0, _ctx);
  kk_Unit; return kk_Unit;
}
 
// Apply a function for each character in a string slice.


// lift anonymous function
struct kk_std_core_foreach_fun24421__t_1 {
  struct kk_function_s _base;
  kk_function_t action;
};
static kk_std_core_types__maybe kk_std_core_foreach_fun24421_1(kk_function_t _fself, kk_char_t c, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_foreach_fun24421_1(kk_function_t action, kk_context_t* _ctx) {
  struct kk_std_core_foreach_fun24421__t_1* _self = kk_function_alloc_as(struct kk_std_core_foreach_fun24421__t_1, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_foreach_fun24421_1, kk_context());
  _self->action = action;
  return &_self->_base;
}



// lift anonymous function
struct kk_std_core_foreach_fun24423__t_1 {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_foreach_fun24423_1(kk_function_t _fself, kk_box_t _b_22505, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_foreach_fun24423_1(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_foreach_fun24423_1, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_core_foreach_fun24423_1(kk_function_t _fself, kk_box_t _b_22505, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core_types__maybe _x24424;
  kk_unit_t _x24425 = kk_Unit;
  kk_unit_unbox(_b_22505);
  _x24424 = kk_std_core__mlift21198_foreach_1(_x24425, _ctx); /*maybe<_13498>*/
  return kk_std_core_types__maybe_box(_x24424, _ctx);
}
static kk_std_core_types__maybe kk_std_core_foreach_fun24421_1(kk_function_t _fself, kk_char_t c, kk_context_t* _ctx) {
  struct kk_std_core_foreach_fun24421__t_1* _self = kk_function_as(struct kk_std_core_foreach_fun24421__t_1*, _fself);
  kk_function_t action = _self->action; /* (c : char) -> 13511 () */
  kk_drop_match(_self, {kk_function_dup(action);}, {}, _ctx)
  kk_unit_t x0_21525 = kk_Unit;
  kk_function_call(kk_unit_t, (kk_function_t, kk_char_t, kk_context_t*), action, (action, c, _ctx));
  if (kk_yielding(kk_context())) {
    kk_box_t _x24422 = kk_std_core_hnd_yield_extend(kk_std_core_new_foreach_fun24423_1(_ctx), _ctx); /*3991*/
    return kk_std_core_types__maybe_unbox(_x24422, _ctx);
  }
  return kk_std_core__mlift21198_foreach_1(x0_21525, _ctx);
}


// lift anonymous function
struct kk_std_core_foreach_fun24427__t_1 {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_foreach_fun24427_1(kk_function_t _fself, kk_box_t _b_22509, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_foreach_fun24427_1(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_foreach_fun24427_1, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_core_foreach_fun24427_1(kk_function_t _fself, kk_box_t _b_22509, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_unit_t _x24428 = kk_Unit;
  kk_std_core_types__maybe _x24429 = kk_std_core_types__maybe_unbox(_b_22509, _ctx); /*maybe<_13498>*/
  kk_std_core__mlift21199_foreach_1(_x24429, _ctx);
  return kk_unit_box(_x24428);
}

kk_unit_t kk_std_core_foreach_1(kk_std_core__sslice slice0, kk_function_t action, kk_context_t* _ctx) { /* forall<e> (slice : sslice, action : (c : char) -> e ()) -> e () */ 
  kk_std_core_types__maybe x_21522 = kk_std_core_foreach_while_1(slice0, kk_std_core_new_foreach_fun24421_1(action, _ctx), _ctx); /*maybe<_13498>*/;
  kk_std_core_types__maybe_drop(x_21522, _ctx);
  if (kk_yielding(kk_context())) {
    kk_box_t _x24426 = kk_std_core_hnd_yield_extend(kk_std_core_new_foreach_fun24427_1(_ctx), _ctx); /*3991*/
    kk_unit_unbox(_x24426); return kk_Unit;
  }
  kk_Unit; return kk_Unit;
}
 
// Invoke a function for each character in a string


// lift anonymous function
struct kk_std_core_foreach_fun24430__t_2 {
  struct kk_function_s _base;
  kk_function_t action;
};
static kk_std_core_types__maybe kk_std_core_foreach_fun24430_2(kk_function_t _fself, kk_char_t c, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_foreach_fun24430_2(kk_function_t action, kk_context_t* _ctx) {
  struct kk_std_core_foreach_fun24430__t_2* _self = kk_function_alloc_as(struct kk_std_core_foreach_fun24430__t_2, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_foreach_fun24430_2, kk_context());
  _self->action = action;
  return &_self->_base;
}



// lift anonymous function
struct kk_std_core_foreach_fun24432__t_2 {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_foreach_fun24432_2(kk_function_t _fself, kk_box_t _b_22513, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_foreach_fun24432_2(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_foreach_fun24432_2, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_core_foreach_fun24432_2(kk_function_t _fself, kk_box_t _b_22513, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core_types__maybe _x24433;
  kk_unit_t _x24434 = kk_Unit;
  kk_unit_unbox(_b_22513);
  _x24433 = kk_std_core__mlift21198_foreach_1(_x24434, _ctx); /*maybe<_13498>*/
  return kk_std_core_types__maybe_box(_x24433, _ctx);
}
static kk_std_core_types__maybe kk_std_core_foreach_fun24430_2(kk_function_t _fself, kk_char_t c, kk_context_t* _ctx) {
  struct kk_std_core_foreach_fun24430__t_2* _self = kk_function_as(struct kk_std_core_foreach_fun24430__t_2*, _fself);
  kk_function_t action = _self->action; /* (c : char) -> 13550 () */
  kk_drop_match(_self, {kk_function_dup(action);}, {}, _ctx)
  kk_unit_t x0_21533 = kk_Unit;
  kk_function_call(kk_unit_t, (kk_function_t, kk_char_t, kk_context_t*), action, (action, c, _ctx));
  if (kk_yielding(kk_context())) {
    kk_box_t _x24431 = kk_std_core_hnd_yield_extend(kk_std_core_new_foreach_fun24432_2(_ctx), _ctx); /*3991*/
    return kk_std_core_types__maybe_unbox(_x24431, _ctx);
  }
  return kk_std_core__mlift21198_foreach_1(x0_21533, _ctx);
}


// lift anonymous function
struct kk_std_core_foreach_fun24436__t_2 {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_foreach_fun24436_2(kk_function_t _fself, kk_box_t _b_22517, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_foreach_fun24436_2(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_foreach_fun24436_2, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_core_foreach_fun24436_2(kk_function_t _fself, kk_box_t _b_22517, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_unit_t _x24437 = kk_Unit;
  kk_std_core_types__maybe _x24438 = kk_std_core_types__maybe_unbox(_b_22517, _ctx); /*maybe<_13498>*/
  kk_std_core__mlift21199_foreach_1(_x24438, _ctx);
  return kk_unit_box(_x24437);
}

kk_unit_t kk_std_core_foreach_2(kk_string_t s, kk_function_t action, kk_context_t* _ctx) { /* forall<e> (s : string, action : (c : char) -> e ()) -> e () */ 
  kk_std_core__sslice slice_21528 = kk_std_core_slice(s, _ctx); /*sslice*/;
  kk_std_core_types__maybe x_21530 = kk_std_core_foreach_while_1(slice_21528, kk_std_core_new_foreach_fun24430_2(action, _ctx), _ctx); /*maybe<_13498>*/;
  kk_std_core_types__maybe_drop(x_21530, _ctx);
  if (kk_yielding(kk_context())) {
    kk_box_t _x24435 = kk_std_core_hnd_yield_extend(kk_std_core_new_foreach_fun24436_2(_ctx), _ctx); /*3991*/
    kk_unit_unbox(_x24435); return kk_Unit;
  }
  kk_Unit; return kk_Unit;
}
 
// Invoke a function `f` for each element in a vector `v`


// lift anonymous function
struct kk_std_core_foreach_fun24441__t_3 {
  struct kk_function_s _base;
  kk_function_t f;
  kk_vector_t v;
};
static kk_unit_t kk_std_core_foreach_fun24441_3(kk_function_t _fself, size_t i, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_foreach_fun24441_3(kk_function_t f, kk_vector_t v, kk_context_t* _ctx) {
  struct kk_std_core_foreach_fun24441__t_3* _self = kk_function_alloc_as(struct kk_std_core_foreach_fun24441__t_3, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_foreach_fun24441_3, kk_context());
  _self->f = f;
  _self->v = v;
  return &_self->_base;
}

static kk_unit_t kk_std_core_foreach_fun24441_3(kk_function_t _fself, size_t i, kk_context_t* _ctx) {
  struct kk_std_core_foreach_fun24441__t_3* _self = kk_function_as(struct kk_std_core_foreach_fun24441__t_3*, _fself);
  kk_function_t f = _self->f; /* (13565) -> 13566 () */
  kk_vector_t v = _self->v; /* vector<13565> */
  kk_drop_match(_self, {kk_function_dup(f);kk_vector_dup(v);}, {}, _ctx)
  kk_box_t x_21541 = kk_vector_at(v,i); /*13565*/;
  return kk_function_call(kk_unit_t, (kk_function_t, kk_box_t, kk_context_t*), f, (f, x_21541, _ctx));
}

kk_unit_t kk_std_core_foreach_3(kk_vector_t v, kk_function_t f, kk_context_t* _ctx) { /* forall<a,e> (v : vector<a>, f : (a) -> e ()) -> e () */ 
  size_t start_21538 = ((size_t)0); /*size_t*/;
  size_t end_21539;
  size_t _x24439;
  kk_vector_t _x24440 = kk_vector_dup(v); /*vector<13565>*/
  _x24439 = kk_vector_len(_x24440); /*size_t*/
  end_21539 = kk_std_core_decr_1(_x24439, _ctx); /*size_t*/
  kk_std_core__lift21051_forz(kk_std_core_new_foreach_fun24441_3(f, v, _ctx), end_21539, start_21538, _ctx); return kk_Unit;
}
 
// O(n). Return the number of characters in a string.

kk_integer_t kk_std_core_count_1(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> int */ 
  return kk_string_count_int(s,kk_context());
}
 
// O(n). Return the number of characters in a string slice

kk_integer_t kk_std_core_count_2(kk_std_core__sslice slice0, kk_context_t* _ctx) { /* (slice : sslice) -> int */ 
  return kk_slice_count(slice0,kk_context());
}
 
// Count the number of times a predicate is true for each character in a string


// lift anonymous function
struct kk_std_core_count_fun24443__t_3 {
  struct kk_function_s _base;
  kk_ref_t loc;
  kk_function_t pred;
};
static kk_std_core_types__maybe kk_std_core_count_fun24443_3(kk_function_t _fself, kk_char_t c, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_count_fun24443_3(kk_ref_t loc, kk_function_t pred, kk_context_t* _ctx) {
  struct kk_std_core_count_fun24443__t_3* _self = kk_function_alloc_as(struct kk_std_core_count_fun24443__t_3, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_count_fun24443_3, kk_context());
  _self->loc = loc;
  _self->pred = pred;
  return &_self->_base;
}



// lift anonymous function
struct kk_std_core_count_fun24448__t_3 {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_count_fun24448_3(kk_function_t _fself, kk_box_t _b_22529, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_count_fun24448_3(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_count_fun24448_3, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_core_count_fun24448_3(kk_function_t _fself, kk_box_t _b_22529, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core_types__maybe _x24449;
  kk_unit_t _x24450 = kk_Unit;
  kk_unit_unbox(_b_22529);
  _x24449 = kk_std_core__mlift21198_foreach_1(_x24450, _ctx); /*maybe<_13498>*/
  return kk_std_core_types__maybe_box(_x24449, _ctx);
}
static kk_std_core_types__maybe kk_std_core_count_fun24443_3(kk_function_t _fself, kk_char_t c, kk_context_t* _ctx) {
  struct kk_std_core_count_fun24443__t_3* _self = kk_function_as(struct kk_std_core_count_fun24443__t_3*, _fself);
  kk_ref_t loc = _self->loc; /* local-var<global,int> */
  kk_function_t pred = _self->pred; /* (char) -> bool */
  kk_drop_match(_self, {kk_ref_dup(loc);kk_function_dup(pred);}, {}, _ctx)
  kk_unit_t x0_21554 = kk_Unit;
  bool _match_23535 = kk_function_call(bool, (kk_function_t, kk_char_t, kk_context_t*), pred, (pred, c, _ctx)); /*bool*/;
  if (_match_23535) {
    kk_integer_t _b_22526_22524;
    kk_integer_t _x24444;
    kk_box_t _x24445;
    kk_ref_t _x24446 = kk_ref_dup(loc); /*local-var<global,int>*/
    _x24445 = (kk_ref_get(_x24446,kk_context())); /*228*/
    _x24444 = kk_integer_unbox(_x24445); /*int*/
    _b_22526_22524 = kk_integer_add(_x24444,(kk_integer_from_small(1)),kk_context()); /*int*/
    (kk_ref_set(loc,(kk_integer_box(_b_22526_22524)),kk_context()));
  }
  else {
    kk_ref_drop(loc, _ctx);
    kk_Unit;
  }
  if (kk_yielding(kk_context())) {
    kk_box_t _x24447 = kk_std_core_hnd_yield_extend(kk_std_core_new_count_fun24448_3(_ctx), _ctx); /*3991*/
    return kk_std_core_types__maybe_unbox(_x24447, _ctx);
  }
  return kk_std_core__mlift21198_foreach_1(x0_21554, _ctx);
}


// lift anonymous function
struct kk_std_core_count_fun24452__t_3 {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_count_fun24452_3(kk_function_t _fself, kk_box_t _b_22533, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_count_fun24452_3(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_count_fun24452_3, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_core_count_fun24452_3(kk_function_t _fself, kk_box_t _b_22533, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_unit_t _x24453 = kk_Unit;
  kk_std_core_types__maybe _x24454 = kk_std_core_types__maybe_unbox(_b_22533, _ctx); /*maybe<_13498>*/
  kk_std_core__mlift21199_foreach_1(_x24454, _ctx);
  return kk_unit_box(_x24453);
}

kk_integer_t kk_std_core_count_3(kk_string_t s, kk_function_t pred, kk_context_t* _ctx) { /* (s : string, pred : (char) -> bool) -> int */ 
  kk_ref_t loc = kk_ref_alloc((kk_integer_box(kk_integer_from_small(0))),kk_context()); /*local-var<global,int>*/;
  kk_integer_t res;
  kk_unit_t __ = kk_Unit;
  kk_std_core__sslice slice_21549 = kk_std_core_slice(s, _ctx); /*sslice*/;
  kk_std_core_types__maybe x_21551;
  kk_function_t _x24442;
  kk_ref_dup(loc);
  _x24442 = kk_std_core_new_count_fun24443_3(loc, pred, _ctx); /*(c : char) -> (local<global>) maybe<_13498>*/
  x_21551 = kk_std_core_foreach_while_1(slice_21549, _x24442, _ctx); /*maybe<_13498>*/
  kk_std_core_types__maybe_drop(x_21551, _ctx);
  if (kk_yielding(kk_context())) {
    kk_box_t _x24451 = kk_std_core_hnd_yield_extend(kk_std_core_new_count_fun24452_3(_ctx), _ctx); /*3991*/
    kk_unit_unbox(_x24451);
  }
  else {
    kk_Unit;
  }
  kk_box_t _x24455;
  kk_ref_t _x24456 = kk_ref_dup(loc); /*local-var<global,int>*/
  _x24455 = (kk_ref_get(_x24456,kk_context())); /*228*/
  res = kk_integer_unbox(_x24455); /*int*/
  kk_box_t _x24457 = kk_std_core_hnd_prompt_local_var(loc, kk_integer_box(res), _ctx); /*9788*/
  return kk_integer_unbox(_x24457);
}
 
// Is the integer negative (stricly smaller than zero)

bool kk_std_core_is_neg_2(kk_integer_t i, kk_context_t* _ctx) { /* (i : int) -> bool */ 
  kk_std_core_types__order x_21559 = kk_int_as_order(kk_integer_signum(i,kk_context()),kk_context()); /*order*/;
  kk_integer_t _x24459 = kk_std_core_int_5(x_21559, _ctx); /*int*/
  kk_integer_t _x24460;
  kk_std_core_types__order _x24461 = kk_std_core_types__new_Lt(_ctx); /*order*/
  if (kk_std_core_types__is_Lt(_x24461)) {
    _x24460 = kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context()); /*int*/
    goto _match24462;
  }
  if (kk_std_core_types__is_Eq(_x24461)) {
    _x24460 = kk_integer_from_small(0); /*int*/
    goto _match24462;
  }
  _x24460 = kk_integer_from_small(1); /*int*/
  _match24462: ;
  return kk_integer_eq(_x24459,_x24460,kk_context());
}

kk_std_core_types__tuple2_ kk_std_core_divmod_exp10(kk_integer_t i, kk_integer_t n, kk_context_t* _ctx) { /* (i : int, n : int) -> (int, int) */ 
  kk_std_core_types__tuple2_ _match_23530;
  kk_integer_t _x24463 = kk_integer_dup(n); /*int*/
  _match_23530 = kk_std_core_cdivmod_exp10(i, _x24463, _ctx); /*(int, int)*/
  kk_box_t _box_x22547 = _match_23530.fst;
  kk_box_t _box_x22548 = _match_23530.snd;
  kk_integer_t cq = kk_integer_unbox(_box_x22547);
  kk_integer_t cr = kk_integer_unbox(_box_x22548);
  bool _match_23531;
  bool _x24466;
  kk_integer_t _x24467 = kk_integer_dup(cr); /*int*/
  _x24466 = kk_std_core_is_neg_2(_x24467, _ctx); /*bool*/
  _match_23531 = !(_x24466); /*bool*/
  if (_match_23531) {
    kk_integer_drop(n, _ctx);
    return kk_std_core_types__new_dash__lp__comma__rp_(kk_integer_box(cq), kk_integer_box(cr), _ctx);
  }
  kk_integer_t _b_22555_22551 = kk_std_core_dec(cq, _ctx); /*int*/;
  kk_integer_t _b_22556_22552;
  kk_integer_t _x24468 = kk_std_core_exp10(n, _ctx); /*int*/
  _b_22556_22552 = kk_integer_add(cr,_x24468,kk_context()); /*int*/
  return kk_std_core_types__new_dash__lp__comma__rp_(kk_integer_box(_b_22555_22551), kk_integer_box(_b_22556_22552), _ctx);
}
 
// Drop the first `n` elements of a list (or fewer if the list is shorter than `n`)

kk_std_core__list kk_std_core_drop(kk_std_core__list xs, kk_integer_t n, kk_context_t* _ctx) { /* forall<a> (xs : list<a>, n : int) -> list<a> */ 
  kk__tailcall: ;
  if (kk_std_core__is_Cons(xs)) {
    struct kk_std_core_Cons* _con24469 = kk_std_core__as_Cons(xs);
    kk_box_t _pat0 = _con24469->head;
    kk_std_core__list xx = _con24469->tail;
    kk_integer_t _x24470 = kk_integer_dup(n); /*int*/
    if (kk_integer_gt(_x24470,(kk_integer_from_small(0)),kk_context())) {
      if (kk_std_core__list_is_unique(xs)) {
        kk_box_drop(_pat0, _ctx);
        kk_std_core__list_free(xs);
      }
      else {
        kk_std_core__list_dup(xx);
        kk_std_core__list_decref(xs, _ctx);
      }
      { // tailcall
        kk_integer_t _x24471 = kk_integer_sub(n,(kk_integer_from_small(1)),kk_context()); /*int*/
        xs = xx;
        n = _x24471;
        goto kk__tailcall;
      }
    }
  }
  kk_integer_drop(n, _ctx);
  return xs;
}
 
// monadic lift

kk_std_core__list kk_std_core__mlift21200_drop_while(kk_function_t predicate, kk_std_core__list xs, kk_std_core__list xx, bool _y_115, kk_context_t* _ctx) { /* forall<a,e> (predicate : (a) -> e bool, xs : list<a>, xx : list<a>, bool) -> e list<a> */ 
  if (_y_115) {
    kk_std_core__list_drop(xs, _ctx);
    return kk_std_core_drop_while(xx, predicate, _ctx);
  }
  kk_function_drop(predicate, _ctx);
  kk_std_core__list_drop(xx, _ctx);
  return xs;
}
 
// Drop all initial elements that satisfy `predicate`


// lift anonymous function
struct kk_std_core_drop_while_fun24475__t {
  struct kk_function_s _base;
  kk_function_t predicate0;
  kk_std_core__list xs0;
  kk_std_core__list xx0;
};
static kk_box_t kk_std_core_drop_while_fun24475(kk_function_t _fself, kk_box_t _b_22558, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_drop_while_fun24475(kk_function_t predicate0, kk_std_core__list xs0, kk_std_core__list xx0, kk_context_t* _ctx) {
  struct kk_std_core_drop_while_fun24475__t* _self = kk_function_alloc_as(struct kk_std_core_drop_while_fun24475__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_drop_while_fun24475, kk_context());
  _self->predicate0 = predicate0;
  _self->xs0 = xs0;
  _self->xx0 = xx0;
  return &_self->_base;
}

static kk_box_t kk_std_core_drop_while_fun24475(kk_function_t _fself, kk_box_t _b_22558, kk_context_t* _ctx) {
  struct kk_std_core_drop_while_fun24475__t* _self = kk_function_as(struct kk_std_core_drop_while_fun24475__t*, _fself);
  kk_function_t predicate0 = _self->predicate0; /* (14165) -> 14166 bool */
  kk_std_core__list xs0 = _self->xs0; /* list<14165> */
  kk_std_core__list xx0 = _self->xx0; /* list<14165> */
  kk_drop_match(_self, {kk_function_dup(predicate0);kk_std_core__list_dup(xs0);kk_std_core__list_dup(xx0);}, {}, _ctx)
  kk_std_core__list _x24476;
  bool _x24477 = kk_bool_unbox(_b_22558); /*bool*/
  _x24476 = kk_std_core__mlift21200_drop_while(predicate0, xs0, xx0, _x24477, _ctx); /*list<14165>*/
  return kk_std_core__list_box(_x24476, _ctx);
}

kk_std_core__list kk_std_core_drop_while(kk_std_core__list xs0, kk_function_t predicate0, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, predicate : (a) -> e bool) -> e list<a> */ 
  kk__tailcall: ;
  if (kk_std_core__is_Cons(xs0)) {
    struct kk_std_core_Cons* _con24472 = kk_std_core__as_Cons(xs0);
    kk_box_t x = _con24472->head;
    kk_std_core__list xx0 = _con24472->tail;
    kk_box_dup(x);
    kk_std_core__list_dup(xx0);
    bool x0_21561;
    kk_function_t _x24473 = kk_function_dup(predicate0); /*(14165) -> 14166 bool*/
    x0_21561 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_context_t*), _x24473, (_x24473, x, _ctx)); /*bool*/
    if (kk_yielding(kk_context())) {
      kk_box_t _x24474 = kk_std_core_hnd_yield_extend(kk_std_core_new_drop_while_fun24475(predicate0, xs0, xx0, _ctx), _ctx); /*3991*/
      return kk_std_core__list_unbox(_x24474, _ctx);
    }
    if (x0_21561) {
      kk_std_core__list_dropn(xs0, ((int32_t)2), _ctx);
      { // tailcall
        xs0 = xx0;
        goto kk__tailcall;
      }
    }
    kk_function_drop(predicate0, _ctx);
    kk_std_core__list_drop(xx0, _ctx);
    return xs0;
  }
  kk_function_drop(predicate0, _ctx);
  return kk_std_core__new_Nil(_ctx);
}
 
// An empty slice

kk_std_core__sslice kk_std_core_empty;
 
// Does string `s`  end with `post`?
// If so, returns a slice of `s` from the start up to the `post` string at the end.

kk_std_core_types__maybe kk_std_core_ends_with(kk_string_t s, kk_string_t post, kk_context_t* _ctx) { /* (s : string, post : string) -> maybe<sslice> */ 
  bool _match_23528;
  kk_string_t _x24482 = kk_string_dup(s); /*string*/
  kk_string_t _x24483 = kk_string_dup(post); /*string*/
  _match_23528 = kk_std_core_xends_with(_x24482, _x24483, _ctx); /*bool*/
  if (_match_23528) {
    kk_std_core__sslice _b_22562_22561;
    kk_string_t _x24484 = kk_string_dup(s); /*string*/
    size_t _x24485 = ((size_t)0); /*size_t*/
    size_t _x24486;
    size_t _x24487 = kk_string_len(s,kk_context()); /*size_t*/
    size_t _x24488 = kk_string_len(post,kk_context()); /*size_t*/
    _x24486 = (_x24487 - _x24488); /*size_t*/
    _b_22562_22561 = kk_std_core__new_Sslice(_x24484, _x24485, _x24486, _ctx); /*sslice*/
    return kk_std_core_types__new_Just(kk_std_core__sslice_box(_b_22562_22561, _ctx), _ctx);
  }
  kk_string_drop(post, _ctx);
  kk_string_drop(s, _ctx);
  return kk_std_core_types__new_Nothing(_ctx);
}
 
// Throw an exception with a specified message.

kk_box_t kk_std_core_throw(kk_string_t message0, kk_std_core_types__optional info0, kk_context_t* _ctx) { /* forall<a> (message : string, info : optional<exception-info>) -> exn a */ 
  kk_std_core__exception exn_21565;
  kk_std_core__exception_info _x24489;
  if (kk_std_core_types__is_Optional(info0)) {
    kk_box_t _box_x22563 = info0._cons.Optional.value;
    kk_std_core__exception_info _info_14279 = kk_std_core__exception_info_unbox(_box_x22563, NULL);
    _x24489 = _info_14279; /*exception-info*/
    goto _match24490;
  }
  _x24489 = kk_std_core__new_ExnError(_ctx); /*exception-info*/
  _match24490: ;
  exn_21565 = kk_std_core__new_Exception(message0, _x24489, _ctx); /*exception*/
  kk_std_core_hnd__ev ev_21566;
  size_t _x24492 = ((size_t)0); /*size_t*/
  ev_21566 = kk_evv_at(_x24492,kk_context()); /*std/core/hnd/ev<.hnd-exn>*/
  struct kk_std_core_hnd_Ev* _con24493 = kk_std_core_hnd__as_Ev(ev_21566);
  kk_std_core_hnd__marker m = _con24493->marker;
  kk_box_t _box_x22564 = _con24493->hnd;
  kk_std_core__hnd_exn h = kk_std_core__hnd_exn_unbox(_box_x22564, NULL);
  kk_std_core__hnd_exn_dup(h);
  kk_std_core_hnd__clause1 _match_23527;
  struct kk_std_core__Hnd_exn* _con24495 = kk_std_core__as_Hnd_exn(h);
  kk_std_core_hnd__clause1 except_throw_exn = _con24495->except_throw_exn;
  if (kk_std_core__hnd_exn_is_unique(h)) {
    kk_std_core__hnd_exn_free(h);
  }
  else {
    kk_std_core_hnd__clause1_dup(except_throw_exn);
    kk_std_core__hnd_exn_decref(h, _ctx);
  }
  _match_23527 = except_throw_exn; /*forall<a> std/core/hnd/clause1<exception,a,.hnd-exn,3528,3529>*/
  kk_function_t _fun_unbox_x22568 = _match_23527.clause;
  return kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x22568, (_fun_unbox_x22568, m, ev_21566, kk_std_core__exception_box(exn_21565, _ctx), _ctx));
}
 
// monadic lift

kk_box_t kk_std_core__mlift21201_error_pattern(kk_string_t definition, kk_string_t location, kk_string_t _c_122, kk_context_t* _ctx) { /* forall<a> (definition : string, location : string, string) -> a */ 
  kk_string_t message_21569;
  kk_string_t _x24496 = kk_string_dup(location); /*string*/
  kk_string_t _x24497;
  kk_string_t _x24498;
  kk_define_string_literal(, _s24499, 23, ": pattern match failure")
  _x24498 = kk_string_dup(_s24499); /*string*/
  _x24497 = kk_std_core__lp__plus__plus__1_rp_(_c_122, _x24498, _ctx); /*string*/
  message_21569 = kk_std_core__lp__plus__plus__1_rp_(_x24496, _x24497, _ctx); /*string*/
  kk_std_core_types__optional info_21570;
  kk_std_core__exception_info _b_22576_22575 = kk_std_core__new_ExnPattern(kk_reuse_null, location, definition, _ctx); /*exception-info*/;
  info_21570 = kk_std_core_types__new_Optional(kk_std_core__exception_info_box(_b_22576_22575, _ctx), _ctx); /*optional<exception-info>*/
  kk_std_core__exception exn_21571;
  kk_std_core__exception_info _x24500;
  if (kk_std_core_types__is_Optional(info_21570)) {
    kk_box_t _box_x22577 = info_21570._cons.Optional.value;
    kk_std_core__exception_info _info_14279 = kk_std_core__exception_info_unbox(_box_x22577, NULL);
    _x24500 = _info_14279; /*exception-info*/
    goto _match24501;
  }
  _x24500 = kk_std_core__new_ExnError(_ctx); /*exception-info*/
  _match24501: ;
  exn_21571 = kk_std_core__new_Exception(message_21569, _x24500, _ctx); /*exception*/
  kk_std_core_hnd__ev ev_21572;
  size_t _x24503 = ((size_t)0); /*size_t*/
  ev_21572 = kk_evv_at(_x24503,kk_context()); /*std/core/hnd/ev<.hnd-exn>*/
  struct kk_std_core_hnd_Ev* _con24504 = kk_std_core_hnd__as_Ev(ev_21572);
  kk_std_core_hnd__marker m = _con24504->marker;
  kk_box_t _box_x22578 = _con24504->hnd;
  kk_std_core__hnd_exn h = kk_std_core__hnd_exn_unbox(_box_x22578, NULL);
  kk_std_core__hnd_exn_dup(h);
  kk_std_core_hnd__clause1 _match_23526;
  struct kk_std_core__Hnd_exn* _con24506 = kk_std_core__as_Hnd_exn(h);
  kk_std_core_hnd__clause1 except_throw_exn = _con24506->except_throw_exn;
  if (kk_std_core__hnd_exn_is_unique(h)) {
    kk_std_core__hnd_exn_free(h);
  }
  else {
    kk_std_core_hnd__clause1_dup(except_throw_exn);
    kk_std_core__hnd_exn_decref(h, _ctx);
  }
  _match_23526 = except_throw_exn; /*forall<a> std/core/hnd/clause1<exception,a,.hnd-exn,3528,3529>*/
  kk_function_t _fun_unbox_x22582 = _match_23526.clause;
  return kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x22582, (_fun_unbox_x22582, m, ev_21572, kk_std_core__exception_box(exn_21571, _ctx), _ctx));
}
 
// Raise a pattern match exception. This is function is used internally by the
// compiler to generate error messages on pattern match failures.


// lift anonymous function
struct kk_std_core_error_pattern_fun24512__t {
  struct kk_function_s _base;
  kk_string_t definition;
  kk_string_t location;
};
static kk_box_t kk_std_core_error_pattern_fun24512(kk_function_t _fself, kk_box_t _b_22590, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_error_pattern_fun24512(kk_string_t definition, kk_string_t location, kk_context_t* _ctx) {
  struct kk_std_core_error_pattern_fun24512__t* _self = kk_function_alloc_as(struct kk_std_core_error_pattern_fun24512__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_error_pattern_fun24512, kk_context());
  _self->definition = definition;
  _self->location = location;
  return &_self->_base;
}

static kk_box_t kk_std_core_error_pattern_fun24512(kk_function_t _fself, kk_box_t _b_22590, kk_context_t* _ctx) {
  struct kk_std_core_error_pattern_fun24512__t* _self = kk_function_as(struct kk_std_core_error_pattern_fun24512__t*, _fself);
  kk_string_t definition = _self->definition; /* string */
  kk_string_t location = _self->location; /* string */
  kk_drop_match(_self, {kk_string_dup(definition);kk_string_dup(location);}, {}, _ctx)
  kk_string_t _x24513 = kk_string_unbox(_b_22590); /*string*/
  return kk_std_core__mlift21201_error_pattern(definition, location, _x24513, _ctx);
}

kk_box_t kk_std_core_error_pattern(kk_string_t location, kk_string_t definition, kk_context_t* _ctx) { /* forall<a> (location : string, definition : string) -> exn a */ 
  kk_string_t x_21575;
  bool _match_23525;
  kk_string_t _x24507 = kk_string_dup(definition); /*string*/
  _match_23525 = kk_std_core_is_empty_2(_x24507, _ctx); /*bool*/
  if (_match_23525) {
    x_21575 = kk_string_empty(); /*string*/
  }
  else {
    kk_string_t _x24509;
    kk_define_string_literal(, _s24510, 2, ": ")
    _x24509 = kk_string_dup(_s24510); /*string*/
    kk_string_t _x24511 = kk_string_dup(definition); /*string*/
    x_21575 = kk_std_core__lp__plus__plus__1_rp_(_x24509, _x24511, _ctx); /*string*/
  }
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_21575, _ctx);
    return kk_std_core_hnd_yield_extend(kk_std_core_new_error_pattern_fun24512(definition, location, _ctx), _ctx);
  }
  kk_string_t message_21579;
  kk_string_t _x24514 = kk_string_dup(location); /*string*/
  kk_string_t _x24515;
  kk_string_t _x24516;
  kk_define_string_literal(, _s24517, 23, ": pattern match failure")
  _x24516 = kk_string_dup(_s24517); /*string*/
  _x24515 = kk_std_core__lp__plus__plus__1_rp_(x_21575, _x24516, _ctx); /*string*/
  message_21579 = kk_std_core__lp__plus__plus__1_rp_(_x24514, _x24515, _ctx); /*string*/
  kk_std_core_types__optional info_21580;
  kk_std_core__exception_info _b_22592_22591 = kk_std_core__new_ExnPattern(kk_reuse_null, location, definition, _ctx); /*exception-info*/;
  info_21580 = kk_std_core_types__new_Optional(kk_std_core__exception_info_box(_b_22592_22591, _ctx), _ctx); /*optional<exception-info>*/
  kk_std_core__exception exn_21581;
  kk_std_core__exception_info _x24518;
  if (kk_std_core_types__is_Optional(info_21580)) {
    kk_box_t _box_x22593 = info_21580._cons.Optional.value;
    kk_std_core__exception_info _info_14279 = kk_std_core__exception_info_unbox(_box_x22593, NULL);
    _x24518 = _info_14279; /*exception-info*/
    goto _match24519;
  }
  _x24518 = kk_std_core__new_ExnError(_ctx); /*exception-info*/
  _match24519: ;
  exn_21581 = kk_std_core__new_Exception(message_21579, _x24518, _ctx); /*exception*/
  kk_std_core_hnd__ev ev_21582;
  size_t _x24521 = ((size_t)0); /*size_t*/
  ev_21582 = kk_evv_at(_x24521,kk_context()); /*std/core/hnd/ev<.hnd-exn>*/
  struct kk_std_core_hnd_Ev* _con24522 = kk_std_core_hnd__as_Ev(ev_21582);
  kk_std_core_hnd__marker m = _con24522->marker;
  kk_box_t _box_x22594 = _con24522->hnd;
  kk_std_core__hnd_exn h = kk_std_core__hnd_exn_unbox(_box_x22594, NULL);
  kk_std_core__hnd_exn_dup(h);
  kk_std_core_hnd__clause1 _match_23524;
  struct kk_std_core__Hnd_exn* _con24524 = kk_std_core__as_Hnd_exn(h);
  kk_std_core_hnd__clause1 except_throw_exn = _con24524->except_throw_exn;
  if (kk_std_core__hnd_exn_is_unique(h)) {
    kk_std_core__hnd_exn_free(h);
  }
  else {
    kk_std_core_hnd__clause1_dup(except_throw_exn);
    kk_std_core__hnd_exn_decref(h, _ctx);
  }
  _match_23524 = except_throw_exn; /*forall<a> std/core/hnd/clause1<exception,a,.hnd-exn,3528,3529>*/
  kk_function_t _fun_unbox_x22598 = _match_23524.clause;
  return kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x22598, (_fun_unbox_x22598, m, ev_21582, kk_std_core__exception_box(exn_21581, _ctx), _ctx));
}
 
// monadic lift

kk_std_core__list kk_std_core__mlift21202_op(kk_std_core_types__ctail _acc, kk_function_t pred, kk_box_t x, kk_std_core__list xx, bool _y_125, kk_context_t* _ctx) { /* forall<a,e> (ctail<list<a>>, pred : (a) -> e bool, x : a, xx : list<a>, bool) -> e list<a> */ 
  if (_y_125) {
    kk_std_core__list _ctail_21131 = kk_std_core__list_hole(); /*list<14526>*/;
    kk_std_core__list _ctail_21132 = kk_std_core__new_Cons(kk_reuse_null, x, _ctail_21131, _ctx); /*list<14526>*/;
    kk_std_core_types__ctail _x24526;
    kk_box_t* field_21587 = (kk_box_t*)((&kk_std_core__as_Cons(_ctail_21132)->tail)); /*cfield<list<14526>>*/;
    if (kk_std_core_types__is_CTail(_acc)) {
      kk_box_t _box_x22613 = _acc._cons.CTail._field1;
      kk_box_t* last0 = _acc._cons.CTail._field2;
      kk_std_core__list head0 = kk_std_core__list_unbox(_box_x22613, NULL);
      kk_unit_t __ = kk_Unit;
      *(last0) = kk_std_core__list_box(_ctail_21132, _ctx);
      _x24526 = kk_std_core_types__new_CTail(kk_std_core__list_box(head0, _ctx), field_21587, _ctx); /*ctail<58>*/
      goto _match24527;
    }
    _x24526 = kk_std_core_types__new_CTail(kk_std_core__list_box(_ctail_21132, _ctx), field_21587, _ctx); /*ctail<58>*/
    _match24527: ;
    return kk_std_core__ctail_filter(xx, pred, _x24526, _ctx);
  }
  kk_box_drop(x, _ctx);
  return kk_std_core__ctail_filter(xx, pred, _acc, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_core__mlift21203_op_fun24529__t {
  struct kk_function_s _base;
  kk_function_t _accm;
  kk_box_t x0;
};
static kk_std_core__list kk_std_core__mlift21203_op_fun24529(kk_function_t _fself, kk_std_core__list _ctail_21134, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_mlift21203_op_fun24529(kk_function_t _accm, kk_box_t x0, kk_context_t* _ctx) {
  struct kk_std_core__mlift21203_op_fun24529__t* _self = kk_function_alloc_as(struct kk_std_core__mlift21203_op_fun24529__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__mlift21203_op_fun24529, kk_context());
  _self->_accm = _accm;
  _self->x0 = x0;
  return &_self->_base;
}

static kk_std_core__list kk_std_core__mlift21203_op_fun24529(kk_function_t _fself, kk_std_core__list _ctail_21134, kk_context_t* _ctx) {
  struct kk_std_core__mlift21203_op_fun24529__t* _self = kk_function_as(struct kk_std_core__mlift21203_op_fun24529__t*, _fself);
  kk_function_t _accm = _self->_accm; /* (list<14526>) -> list<14526> */
  kk_box_t x0 = _self->x0; /* 14526 */
  kk_drop_match(_self, {kk_function_dup(_accm);kk_box_dup(x0);}, {}, _ctx)
  kk_std_core__list _x24530 = kk_std_core__new_Cons(kk_reuse_null, x0, _ctail_21134, _ctx); /*list<61>*/
  return kk_function_call(kk_std_core__list, (kk_function_t, kk_std_core__list, kk_context_t*), _accm, (_accm, _x24530, _ctx));
}

kk_std_core__list kk_std_core__mlift21203_op(kk_function_t _accm, kk_function_t pred0, kk_box_t x0, kk_std_core__list xx0, bool _y_130, kk_context_t* _ctx) { /* forall<a,e> ((list<a>) -> list<a>, pred : (a) -> e bool, x : a, xx : list<a>, bool) -> e list<a> */ 
  if (_y_130) {
    return kk_std_core__ctailm_filter(xx0, pred0, kk_std_core__new_mlift21203_op_fun24529(_accm, x0, _ctx), _ctx);
  }
  kk_box_drop(x0, _ctx);
  return kk_std_core__ctailm_filter(xx0, pred0, _accm, _ctx);
}
 
// Retain only those elements of a list that satisfy the given predicate `pred`.
// For example: `filter([1,2,3],odd?) == [1,3]`


// lift anonymous function
struct kk_std_core__ctail_filter_fun24535__t {
  struct kk_function_s _base;
  kk_function_t pred1;
  kk_box_t x1;
  kk_std_core__list xx1;
  kk_std_core_types__ctail _acc0;
};
static kk_box_t kk_std_core__ctail_filter_fun24535(kk_function_t _fself, kk_box_t _b_22627, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_ctail_filter_fun24535(kk_function_t pred1, kk_box_t x1, kk_std_core__list xx1, kk_std_core_types__ctail _acc0, kk_context_t* _ctx) {
  struct kk_std_core__ctail_filter_fun24535__t* _self = kk_function_alloc_as(struct kk_std_core__ctail_filter_fun24535__t, 6, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__ctail_filter_fun24535, kk_context());
  _self->pred1 = pred1;
  _self->x1 = x1;
  _self->xx1 = xx1;
  _self->_acc0 = _acc0;
  return &_self->_base;
}

static kk_box_t kk_std_core__ctail_filter_fun24535(kk_function_t _fself, kk_box_t _b_22627, kk_context_t* _ctx) {
  struct kk_std_core__ctail_filter_fun24535__t* _self = kk_function_as(struct kk_std_core__ctail_filter_fun24535__t*, _fself);
  kk_function_t pred1 = _self->pred1; /* (14526) -> 14527 bool */
  kk_box_t x1 = _self->x1; /* 14526 */
  kk_std_core__list xx1 = _self->xx1; /* list<14526> */
  kk_std_core_types__ctail _acc0 = _self->_acc0; /* ctail<list<14526>> */
  kk_drop_match(_self, {kk_function_dup(pred1);kk_box_dup(x1);kk_std_core__list_dup(xx1);kk_std_core_types__ctail_dup(_acc0);}, {}, _ctx)
  kk_std_core__list _x24536;
  bool _x24537 = kk_bool_unbox(_b_22627); /*bool*/
  _x24536 = kk_std_core__mlift21202_op(_acc0, pred1, x1, xx1, _x24537, _ctx); /*list<14526>*/
  return kk_std_core__list_box(_x24536, _ctx);
}

kk_std_core__list kk_std_core__ctail_filter(kk_std_core__list xs, kk_function_t pred1, kk_std_core_types__ctail _acc0, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, pred : (a) -> e bool, ctail<list<a>>) -> e list<a> */ 
  kk__tailcall: ;
  if (kk_std_core__is_Cons(xs)) {
    struct kk_std_core_Cons* _con24531 = kk_std_core__as_Cons(xs);
    kk_box_t x1 = _con24531->head;
    kk_std_core__list xx1 = _con24531->tail;
    kk_reuse_t _ru_23377 = kk_reuse_null; /*reuse*/;
    if (kk_std_core__list_is_unique(xs)) {
      _ru_23377 = (kk_std_core__list_reuse(xs));
    }
    else {
      kk_box_dup(x1);
      kk_std_core__list_dup(xx1);
      kk_std_core__list_decref(xs, _ctx);
      _ru_23377 = kk_reuse_null;
    }
    bool x0_21588;
    kk_function_t _x24533 = kk_function_dup(pred1); /*(14526) -> 14527 bool*/
    kk_box_t _x24532 = kk_box_dup(x1); /*14526*/
    x0_21588 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_context_t*), _x24533, (_x24533, _x24532, _ctx)); /*bool*/
    if (kk_yielding(kk_context())) {
      kk_reuse_drop(_ru_23377, _ctx);
      kk_box_t _x24534 = kk_std_core_hnd_yield_extend(kk_std_core__new_ctail_filter_fun24535(pred1, x1, xx1, _acc0, _ctx), _ctx); /*3991*/
      return kk_std_core__list_unbox(_x24534, _ctx);
    }
    if (x0_21588) {
      kk_std_core__list _ctail_211310 = kk_std_core__list_hole(); /*list<14526>*/;
      kk_std_core__list _ctail_211320;
      bool _x24538 = _ru_23377!=NULL; /*bool*/
      if (_x24538) {
        struct kk_std_core_Cons* _con24539 = (struct kk_std_core_Cons*)_ru_23377;
        _con24539->tail = _ctail_211310;
        _ctail_211320 = kk_std_core__base_Cons(_con24539); /*list<14526>*/
      }
      else {
        _ctail_211320 = kk_std_core__new_Cons(kk_reuse_null, x1, _ctail_211310, _ctx); /*list<14526>*/
      }
      { // tailcall
        kk_std_core_types__ctail _x24540;
        kk_box_t* field_21594 = (kk_box_t*)((&kk_std_core__as_Cons(_ctail_211320)->tail)); /*cfield<list<14526>>*/;
        if (kk_std_core_types__is_CTail(_acc0)) {
          kk_box_t _box_x22634 = _acc0._cons.CTail._field1;
          kk_box_t* last2 = _acc0._cons.CTail._field2;
          kk_std_core__list head1 = kk_std_core__list_unbox(_box_x22634, NULL);
          kk_unit_t __0 = kk_Unit;
          *(last2) = kk_std_core__list_box(_ctail_211320, _ctx);
          _x24540 = kk_std_core_types__new_CTail(kk_std_core__list_box(head1, _ctx), field_21594, _ctx); /*ctail<58>*/
          goto _match24541;
        }
        _x24540 = kk_std_core_types__new_CTail(kk_std_core__list_box(_ctail_211320, _ctx), field_21594, _ctx); /*ctail<58>*/
        _match24541: ;
        xs = xx1;
        _acc0 = _x24540;
        goto kk__tailcall;
      }
    }
    kk_reuse_drop(_ru_23377, _ctx);
    kk_box_drop(x1, _ctx);
    { // tailcall
      xs = xx1;
      goto kk__tailcall;
    }
  }
  kk_function_drop(pred1, _ctx);
  if (kk_std_core_types__is_CTail(_acc0)) {
    kk_box_t _box_x22643 = _acc0._cons.CTail._field1;
    kk_box_t* last00 = _acc0._cons.CTail._field2;
    kk_std_core__list head00 = kk_std_core__list_unbox(_box_x22643, NULL);
    kk_unit_t __00 = kk_Unit;
    *(last00) = kk_std_core__list_box(kk_std_core__new_Nil(_ctx), _ctx);
    return head00;
  }
  return kk_std_core__new_Nil(_ctx);
}
 
// Retain only those elements of a list that satisfy the given predicate `pred`.
// For example: `filter([1,2,3],odd?) == [1,3]`


// lift anonymous function
struct kk_std_core__ctailm_filter_fun24548__t {
  struct kk_function_s _base;
  kk_function_t _accm0;
  kk_function_t pred2;
  kk_box_t x2;
  kk_std_core__list xx2;
};
static kk_box_t kk_std_core__ctailm_filter_fun24548(kk_function_t _fself, kk_box_t _b_22655, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_ctailm_filter_fun24548(kk_function_t _accm0, kk_function_t pred2, kk_box_t x2, kk_std_core__list xx2, kk_context_t* _ctx) {
  struct kk_std_core__ctailm_filter_fun24548__t* _self = kk_function_alloc_as(struct kk_std_core__ctailm_filter_fun24548__t, 5, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__ctailm_filter_fun24548, kk_context());
  _self->_accm0 = _accm0;
  _self->pred2 = pred2;
  _self->x2 = x2;
  _self->xx2 = xx2;
  return &_self->_base;
}

static kk_box_t kk_std_core__ctailm_filter_fun24548(kk_function_t _fself, kk_box_t _b_22655, kk_context_t* _ctx) {
  struct kk_std_core__ctailm_filter_fun24548__t* _self = kk_function_as(struct kk_std_core__ctailm_filter_fun24548__t*, _fself);
  kk_function_t _accm0 = _self->_accm0; /* (list<14526>) -> list<14526> */
  kk_function_t pred2 = _self->pred2; /* (14526) -> 14527 bool */
  kk_box_t x2 = _self->x2; /* 14526 */
  kk_std_core__list xx2 = _self->xx2; /* list<14526> */
  kk_drop_match(_self, {kk_function_dup(_accm0);kk_function_dup(pred2);kk_box_dup(x2);kk_std_core__list_dup(xx2);}, {}, _ctx)
  kk_std_core__list _x24549;
  bool _x24550 = kk_bool_unbox(_b_22655); /*bool*/
  _x24549 = kk_std_core__mlift21203_op(_accm0, pred2, x2, xx2, _x24550, _ctx); /*list<14526>*/
  return kk_std_core__list_box(_x24549, _ctx);
}


// lift anonymous function
struct kk_std_core__ctailm_filter_fun24552__t {
  struct kk_function_s _base;
  kk_function_t _accm0;
  kk_box_t x2;
};
static kk_std_core__list kk_std_core__ctailm_filter_fun24552(kk_function_t _fself, kk_std_core__list _ctail_211340, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_ctailm_filter_fun24552(kk_function_t _accm0, kk_box_t x2, kk_context_t* _ctx) {
  struct kk_std_core__ctailm_filter_fun24552__t* _self = kk_function_alloc_as(struct kk_std_core__ctailm_filter_fun24552__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__ctailm_filter_fun24552, kk_context());
  _self->_accm0 = _accm0;
  _self->x2 = x2;
  return &_self->_base;
}

static kk_std_core__list kk_std_core__ctailm_filter_fun24552(kk_function_t _fself, kk_std_core__list _ctail_211340, kk_context_t* _ctx) {
  struct kk_std_core__ctailm_filter_fun24552__t* _self = kk_function_as(struct kk_std_core__ctailm_filter_fun24552__t*, _fself);
  kk_function_t _accm0 = _self->_accm0; /* (list<14526>) -> list<14526> */
  kk_box_t x2 = _self->x2; /* 14526 */
  kk_drop_match(_self, {kk_function_dup(_accm0);kk_box_dup(x2);}, {}, _ctx)
  kk_std_core__list _x24553 = kk_std_core__new_Cons(kk_reuse_null, x2, _ctail_211340, _ctx); /*list<61>*/
  return kk_function_call(kk_std_core__list, (kk_function_t, kk_std_core__list, kk_context_t*), _accm0, (_accm0, _x24553, _ctx));
}

kk_std_core__list kk_std_core__ctailm_filter(kk_std_core__list xs0, kk_function_t pred2, kk_function_t _accm0, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, pred : (a) -> e bool, (list<a>) -> list<a>) -> e list<a> */ 
  kk__tailcall: ;
  if (kk_std_core__is_Cons(xs0)) {
    struct kk_std_core_Cons* _con24544 = kk_std_core__as_Cons(xs0);
    kk_box_t x2 = _con24544->head;
    kk_std_core__list xx2 = _con24544->tail;
    if (kk_std_core__list_is_unique(xs0)) {
      kk_std_core__list_free(xs0);
    }
    else {
      kk_box_dup(x2);
      kk_std_core__list_dup(xx2);
      kk_std_core__list_decref(xs0, _ctx);
    }
    bool x0_21597;
    kk_function_t _x24546 = kk_function_dup(pred2); /*(14526) -> 14527 bool*/
    kk_box_t _x24545 = kk_box_dup(x2); /*14526*/
    x0_21597 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_context_t*), _x24546, (_x24546, _x24545, _ctx)); /*bool*/
    if (kk_yielding(kk_context())) {
      kk_box_t _x24547 = kk_std_core_hnd_yield_extend(kk_std_core__new_ctailm_filter_fun24548(_accm0, pred2, x2, xx2, _ctx), _ctx); /*3991*/
      return kk_std_core__list_unbox(_x24547, _ctx);
    }
    if (x0_21597) {
      { // tailcall
        kk_function_t _x24551 = kk_std_core__new_ctailm_filter_fun24552(_accm0, x2, _ctx); /*(list<14526>) -> list<14526>*/
        xs0 = xx2;
        _accm0 = _x24551;
        goto kk__tailcall;
      }
    }
    kk_box_drop(x2, _ctx);
    { // tailcall
      xs0 = xx2;
      goto kk__tailcall;
    }
  }
  kk_function_drop(pred2, _ctx);
  return kk_function_call(kk_std_core__list, (kk_function_t, kk_std_core__list, kk_context_t*), _accm0, (_accm0, kk_std_core__new_Nil(_ctx), _ctx));
}
 
// Retain only those elements of a list that satisfy the given predicate `pred`.
// For example: `filter([1,2,3],odd?) == [1,3]`


// lift anonymous function
struct kk_std_core_filter_fun24554__t {
  struct kk_function_s _base;
};
static kk_std_core__list kk_std_core_filter_fun24554(kk_function_t _fself, kk_std_core__list _ctail_21133, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_filter_fun24554(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_filter_fun24554, _ctx)
  return kk_function_dup(_fself);
}

static kk_std_core__list kk_std_core_filter_fun24554(kk_function_t _fself, kk_std_core__list _ctail_21133, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return _ctail_21133;
}

kk_std_core__list kk_std_core_filter(kk_std_core__list xs1, kk_function_t pred3, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, pred : (a) -> e bool) -> e list<a> */ 
  bool _match_23520 = kk_std_core_hnd__evv_is_affine(_ctx); /*bool*/;
  if (_match_23520) {
    return kk_std_core__ctail_filter(xs1, pred3, kk_std_core_types__new_CTailNil(_ctx), _ctx);
  }
  return kk_std_core__ctailm_filter(xs1, pred3, kk_std_core_new_filter_fun24554(_ctx), _ctx);
}
 
// monadic lift

kk_std_core__list kk_std_core__mlift21204_op(kk_std_core_types__ctail _acc, kk_function_t pred, kk_std_core__list xx, kk_std_core_types__maybe _y_138, kk_context_t* _ctx) { /* forall<a,b,e> (ctail<list<b>>, pred : (a) -> e maybe<b>, xx : list<a>, maybe<b>) -> e list<b> */ 
  if (kk_std_core_types__is_Nothing(_y_138)) {
    return kk_std_core__ctail_filter_map(xx, pred, _acc, _ctx);
  }
  kk_box_t y = _y_138._cons.Just.value;
  kk_std_core__list _ctail_21135 = kk_std_core__list_hole(); /*list<14572>*/;
  kk_std_core__list _ctail_21136 = kk_std_core__new_Cons(kk_reuse_null, y, _ctail_21135, _ctx); /*list<14572>*/;
  kk_std_core_types__ctail _x24555;
  kk_box_t* field_21603 = (kk_box_t*)((&kk_std_core__as_Cons(_ctail_21136)->tail)); /*cfield<list<14572>>*/;
  if (kk_std_core_types__is_CTail(_acc)) {
    kk_box_t _box_x22664 = _acc._cons.CTail._field1;
    kk_box_t* last0 = _acc._cons.CTail._field2;
    kk_std_core__list head0 = kk_std_core__list_unbox(_box_x22664, NULL);
    kk_unit_t __ = kk_Unit;
    *(last0) = kk_std_core__list_box(_ctail_21136, _ctx);
    _x24555 = kk_std_core_types__new_CTail(kk_std_core__list_box(head0, _ctx), field_21603, _ctx); /*ctail<58>*/
    goto _match24556;
  }
  _x24555 = kk_std_core_types__new_CTail(kk_std_core__list_box(_ctail_21136, _ctx), field_21603, _ctx); /*ctail<58>*/
  _match24556: ;
  return kk_std_core__ctail_filter_map(xx, pred, _x24555, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_core__mlift21205_op_fun24558__t {
  struct kk_function_s _base;
  kk_function_t _accm;
  kk_box_t y0;
};
static kk_std_core__list kk_std_core__mlift21205_op_fun24558(kk_function_t _fself, kk_std_core__list _ctail_21138, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_mlift21205_op_fun24558(kk_function_t _accm, kk_box_t y0, kk_context_t* _ctx) {
  struct kk_std_core__mlift21205_op_fun24558__t* _self = kk_function_alloc_as(struct kk_std_core__mlift21205_op_fun24558__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__mlift21205_op_fun24558, kk_context());
  _self->_accm = _accm;
  _self->y0 = y0;
  return &_self->_base;
}

static kk_std_core__list kk_std_core__mlift21205_op_fun24558(kk_function_t _fself, kk_std_core__list _ctail_21138, kk_context_t* _ctx) {
  struct kk_std_core__mlift21205_op_fun24558__t* _self = kk_function_as(struct kk_std_core__mlift21205_op_fun24558__t*, _fself);
  kk_function_t _accm = _self->_accm; /* (list<14572>) -> list<14572> */
  kk_box_t y0 = _self->y0; /* 14572 */
  kk_drop_match(_self, {kk_function_dup(_accm);kk_box_dup(y0);}, {}, _ctx)
  kk_std_core__list _x24559 = kk_std_core__new_Cons(kk_reuse_null, y0, _ctail_21138, _ctx); /*list<61>*/
  return kk_function_call(kk_std_core__list, (kk_function_t, kk_std_core__list, kk_context_t*), _accm, (_accm, _x24559, _ctx));
}

kk_std_core__list kk_std_core__mlift21205_op(kk_function_t _accm, kk_function_t pred0, kk_std_core__list xx0, kk_std_core_types__maybe _y_143, kk_context_t* _ctx) { /* forall<a,b,e> ((list<b>) -> list<b>, pred : (a) -> e maybe<b>, xx : list<a>, maybe<b>) -> e list<b> */ 
  if (kk_std_core_types__is_Nothing(_y_143)) {
    return kk_std_core__ctailm_filter_map(xx0, pred0, _accm, _ctx);
  }
  kk_box_t y0 = _y_143._cons.Just.value;
  return kk_std_core__ctailm_filter_map(xx0, pred0, kk_std_core__new_mlift21205_op_fun24558(_accm, y0, _ctx), _ctx);
}
 
// Retain only those elements of a list that satisfy the given predicate `pred`.
// For example: `filterMap([1,2,3],fn(i) { if (i.odd?) then Nothing else Just(i*i) }) == [4]`


// lift anonymous function
struct kk_std_core__ctail_filter_map_fun24564__t {
  struct kk_function_s _base;
  kk_function_t pred1;
  kk_std_core__list xx1;
  kk_std_core_types__ctail _acc0;
};
static kk_box_t kk_std_core__ctail_filter_map_fun24564(kk_function_t _fself, kk_box_t _b_22683, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_ctail_filter_map_fun24564(kk_function_t pred1, kk_std_core__list xx1, kk_std_core_types__ctail _acc0, kk_context_t* _ctx) {
  struct kk_std_core__ctail_filter_map_fun24564__t* _self = kk_function_alloc_as(struct kk_std_core__ctail_filter_map_fun24564__t, 5, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__ctail_filter_map_fun24564, kk_context());
  _self->pred1 = pred1;
  _self->xx1 = xx1;
  _self->_acc0 = _acc0;
  return &_self->_base;
}

static kk_box_t kk_std_core__ctail_filter_map_fun24564(kk_function_t _fself, kk_box_t _b_22683, kk_context_t* _ctx) {
  struct kk_std_core__ctail_filter_map_fun24564__t* _self = kk_function_as(struct kk_std_core__ctail_filter_map_fun24564__t*, _fself);
  kk_function_t pred1 = _self->pred1; /* (14571) -> 14573 maybe<14572> */
  kk_std_core__list xx1 = _self->xx1; /* list<14571> */
  kk_std_core_types__ctail _acc0 = _self->_acc0; /* ctail<list<14572>> */
  kk_drop_match(_self, {kk_function_dup(pred1);kk_std_core__list_dup(xx1);kk_std_core_types__ctail_dup(_acc0);}, {}, _ctx)
  kk_std_core__list _x24565;
  kk_std_core_types__maybe _x24566 = kk_std_core_types__maybe_unbox(_b_22683, _ctx); /*maybe<14572>*/
  _x24565 = kk_std_core__mlift21204_op(_acc0, pred1, xx1, _x24566, _ctx); /*list<14572>*/
  return kk_std_core__list_box(_x24565, _ctx);
}

kk_std_core__list kk_std_core__ctail_filter_map(kk_std_core__list xs, kk_function_t pred1, kk_std_core_types__ctail _acc0, kk_context_t* _ctx) { /* forall<a,b,e> (xs : list<a>, pred : (a) -> e maybe<b>, ctail<list<b>>) -> e list<b> */ 
  kk__tailcall: ;
  if (kk_std_core__is_Nil(xs)) {
    kk_function_drop(pred1, _ctx);
    if (kk_std_core_types__is_CTail(_acc0)) {
      kk_box_t _box_x22677 = _acc0._cons.CTail._field1;
      kk_box_t* last2 = _acc0._cons.CTail._field2;
      kk_std_core__list head1 = kk_std_core__list_unbox(_box_x22677, NULL);
      kk_unit_t __0 = kk_Unit;
      *(last2) = kk_std_core__list_box(kk_std_core__new_Nil(_ctx), _ctx);
      return head1;
    }
    return kk_std_core__new_Nil(_ctx);
  }
  struct kk_std_core_Cons* _con24561 = kk_std_core__as_Cons(xs);
  kk_box_t x = _con24561->head;
  kk_std_core__list xx1 = _con24561->tail;
  kk_reuse_t _ru_23379 = kk_reuse_null; /*reuse*/;
  if (kk_std_core__list_is_unique(xs)) {
    _ru_23379 = (kk_std_core__list_reuse(xs));
  }
  else {
    kk_box_dup(x);
    kk_std_core__list_dup(xx1);
    kk_std_core__list_decref(xs, _ctx);
    _ru_23379 = kk_reuse_null;
  }
  kk_std_core_types__maybe x0_21606;
  kk_function_t _x24562 = kk_function_dup(pred1); /*(14571) -> 14573 maybe<14572>*/
  x0_21606 = kk_function_call(kk_std_core_types__maybe, (kk_function_t, kk_box_t, kk_context_t*), _x24562, (_x24562, x, _ctx)); /*maybe<14572>*/
  if (kk_yielding(kk_context())) {
    kk_reuse_drop(_ru_23379, _ctx);
    kk_std_core_types__maybe_drop(x0_21606, _ctx);
    kk_box_t _x24563 = kk_std_core_hnd_yield_extend(kk_std_core__new_ctail_filter_map_fun24564(pred1, xx1, _acc0, _ctx), _ctx); /*3991*/
    return kk_std_core__list_unbox(_x24563, _ctx);
  }
  if (kk_std_core_types__is_Nothing(x0_21606)) {
    kk_reuse_drop(_ru_23379, _ctx);
    { // tailcall
      xs = xx1;
      goto kk__tailcall;
    }
  }
  kk_box_t y1 = x0_21606._cons.Just.value;
  kk_std_core__list _ctail_211350 = kk_std_core__list_hole(); /*list<14572>*/;
  kk_std_core__list _ctail_211360 = kk_std_core__new_Cons(_ru_23379, y1, _ctail_211350, _ctx); /*list<14572>*/;
  { // tailcall
    kk_std_core_types__ctail _x24567;
    kk_box_t* field_21612 = (kk_box_t*)((&kk_std_core__as_Cons(_ctail_211360)->tail)); /*cfield<list<14572>>*/;
    if (kk_std_core_types__is_CTail(_acc0)) {
      kk_box_t _box_x22690 = _acc0._cons.CTail._field1;
      kk_box_t* last00 = _acc0._cons.CTail._field2;
      kk_std_core__list head00 = kk_std_core__list_unbox(_box_x22690, NULL);
      kk_unit_t __00 = kk_Unit;
      *(last00) = kk_std_core__list_box(_ctail_211360, _ctx);
      _x24567 = kk_std_core_types__new_CTail(kk_std_core__list_box(head00, _ctx), field_21612, _ctx); /*ctail<58>*/
      goto _match24568;
    }
    _x24567 = kk_std_core_types__new_CTail(kk_std_core__list_box(_ctail_211360, _ctx), field_21612, _ctx); /*ctail<58>*/
    _match24568: ;
    xs = xx1;
    _acc0 = _x24567;
    goto kk__tailcall;
  }
}
 
// Retain only those elements of a list that satisfy the given predicate `pred`.
// For example: `filterMap([1,2,3],fn(i) { if (i.odd?) then Nothing else Just(i*i) }) == [4]`


// lift anonymous function
struct kk_std_core__ctailm_filter_map_fun24573__t {
  struct kk_function_s _base;
  kk_function_t _accm0;
  kk_function_t pred2;
  kk_std_core__list xx2;
};
static kk_box_t kk_std_core__ctailm_filter_map_fun24573(kk_function_t _fself, kk_box_t _b_22706, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_ctailm_filter_map_fun24573(kk_function_t _accm0, kk_function_t pred2, kk_std_core__list xx2, kk_context_t* _ctx) {
  struct kk_std_core__ctailm_filter_map_fun24573__t* _self = kk_function_alloc_as(struct kk_std_core__ctailm_filter_map_fun24573__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__ctailm_filter_map_fun24573, kk_context());
  _self->_accm0 = _accm0;
  _self->pred2 = pred2;
  _self->xx2 = xx2;
  return &_self->_base;
}

static kk_box_t kk_std_core__ctailm_filter_map_fun24573(kk_function_t _fself, kk_box_t _b_22706, kk_context_t* _ctx) {
  struct kk_std_core__ctailm_filter_map_fun24573__t* _self = kk_function_as(struct kk_std_core__ctailm_filter_map_fun24573__t*, _fself);
  kk_function_t _accm0 = _self->_accm0; /* (list<14572>) -> list<14572> */
  kk_function_t pred2 = _self->pred2; /* (14571) -> 14573 maybe<14572> */
  kk_std_core__list xx2 = _self->xx2; /* list<14571> */
  kk_drop_match(_self, {kk_function_dup(_accm0);kk_function_dup(pred2);kk_std_core__list_dup(xx2);}, {}, _ctx)
  kk_std_core__list _x24574;
  kk_std_core_types__maybe _x24575 = kk_std_core_types__maybe_unbox(_b_22706, _ctx); /*maybe<14572>*/
  _x24574 = kk_std_core__mlift21205_op(_accm0, pred2, xx2, _x24575, _ctx); /*list<14572>*/
  return kk_std_core__list_box(_x24574, _ctx);
}


// lift anonymous function
struct kk_std_core__ctailm_filter_map_fun24577__t {
  struct kk_function_s _base;
  kk_function_t _accm0;
  kk_box_t y2;
};
static kk_std_core__list kk_std_core__ctailm_filter_map_fun24577(kk_function_t _fself, kk_std_core__list _ctail_211380, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_ctailm_filter_map_fun24577(kk_function_t _accm0, kk_box_t y2, kk_context_t* _ctx) {
  struct kk_std_core__ctailm_filter_map_fun24577__t* _self = kk_function_alloc_as(struct kk_std_core__ctailm_filter_map_fun24577__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__ctailm_filter_map_fun24577, kk_context());
  _self->_accm0 = _accm0;
  _self->y2 = y2;
  return &_self->_base;
}

static kk_std_core__list kk_std_core__ctailm_filter_map_fun24577(kk_function_t _fself, kk_std_core__list _ctail_211380, kk_context_t* _ctx) {
  struct kk_std_core__ctailm_filter_map_fun24577__t* _self = kk_function_as(struct kk_std_core__ctailm_filter_map_fun24577__t*, _fself);
  kk_function_t _accm0 = _self->_accm0; /* (list<14572>) -> list<14572> */
  kk_box_t y2 = _self->y2; /* 14572 */
  kk_drop_match(_self, {kk_function_dup(_accm0);kk_box_dup(y2);}, {}, _ctx)
  kk_std_core__list _x24578 = kk_std_core__new_Cons(kk_reuse_null, y2, _ctail_211380, _ctx); /*list<61>*/
  return kk_function_call(kk_std_core__list, (kk_function_t, kk_std_core__list, kk_context_t*), _accm0, (_accm0, _x24578, _ctx));
}

kk_std_core__list kk_std_core__ctailm_filter_map(kk_std_core__list xs0, kk_function_t pred2, kk_function_t _accm0, kk_context_t* _ctx) { /* forall<a,b,e> (xs : list<a>, pred : (a) -> e maybe<b>, (list<b>) -> list<b>) -> e list<b> */ 
  kk__tailcall: ;
  if (kk_std_core__is_Nil(xs0)) {
    kk_function_drop(pred2, _ctx);
    return kk_function_call(kk_std_core__list, (kk_function_t, kk_std_core__list, kk_context_t*), _accm0, (_accm0, kk_std_core__new_Nil(_ctx), _ctx));
  }
  struct kk_std_core_Cons* _con24570 = kk_std_core__as_Cons(xs0);
  kk_box_t x0 = _con24570->head;
  kk_std_core__list xx2 = _con24570->tail;
  if (kk_std_core__list_is_unique(xs0)) {
    kk_std_core__list_free(xs0);
  }
  else {
    kk_box_dup(x0);
    kk_std_core__list_dup(xx2);
    kk_std_core__list_decref(xs0, _ctx);
  }
  kk_std_core_types__maybe x0_21613;
  kk_function_t _x24571 = kk_function_dup(pred2); /*(14571) -> 14573 maybe<14572>*/
  x0_21613 = kk_function_call(kk_std_core_types__maybe, (kk_function_t, kk_box_t, kk_context_t*), _x24571, (_x24571, x0, _ctx)); /*maybe<14572>*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__maybe_drop(x0_21613, _ctx);
    kk_box_t _x24572 = kk_std_core_hnd_yield_extend(kk_std_core__new_ctailm_filter_map_fun24573(_accm0, pred2, xx2, _ctx), _ctx); /*3991*/
    return kk_std_core__list_unbox(_x24572, _ctx);
  }
  if (kk_std_core_types__is_Nothing(x0_21613)) {
    { // tailcall
      xs0 = xx2;
      goto kk__tailcall;
    }
  }
  kk_box_t y2 = x0_21613._cons.Just.value;
  { // tailcall
    kk_function_t _x24576 = kk_std_core__new_ctailm_filter_map_fun24577(_accm0, y2, _ctx); /*(list<14572>) -> list<14572>*/
    xs0 = xx2;
    _accm0 = _x24576;
    goto kk__tailcall;
  }
}
 
// Retain only those elements of a list that satisfy the given predicate `pred`.
// For example: `filterMap([1,2,3],fn(i) { if (i.odd?) then Nothing else Just(i*i) }) == [4]`


// lift anonymous function
struct kk_std_core_filter_map_fun24579__t {
  struct kk_function_s _base;
};
static kk_std_core__list kk_std_core_filter_map_fun24579(kk_function_t _fself, kk_std_core__list _ctail_21137, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_filter_map_fun24579(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_filter_map_fun24579, _ctx)
  return kk_function_dup(_fself);
}

static kk_std_core__list kk_std_core_filter_map_fun24579(kk_function_t _fself, kk_std_core__list _ctail_21137, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return _ctail_21137;
}

kk_std_core__list kk_std_core_filter_map(kk_std_core__list xs1, kk_function_t pred3, kk_context_t* _ctx) { /* forall<a,b,e> (xs : list<a>, pred : (a) -> e maybe<b>) -> e list<b> */ 
  bool _match_23517 = kk_std_core_hnd__evv_is_affine(_ctx); /*bool*/;
  if (_match_23517) {
    return kk_std_core__ctail_filter_map(xs1, pred3, kk_std_core_types__new_CTailNil(_ctx), _ctx);
  }
  return kk_std_core__ctailm_filter_map(xs1, pred3, kk_std_core_new_filter_map_fun24579(_ctx), _ctx);
}

bool kk_std_core_is_zero_1(size_t i, kk_context_t* _ctx) { /* (i : size_t) -> bool */ 
  return (i == 0);
}
 
// Find the first element satisfying some predicate


// lift anonymous function
struct kk_std_core_find_fun24580__t {
  struct kk_function_s _base;
  kk_function_t pred;
};
static kk_std_core_types__maybe kk_std_core_find_fun24580(kk_function_t _fself, kk_box_t x, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_find_fun24580(kk_function_t pred, kk_context_t* _ctx) {
  struct kk_std_core_find_fun24580__t* _self = kk_function_alloc_as(struct kk_std_core_find_fun24580__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_find_fun24580, kk_context());
  _self->pred = pred;
  return &_self->_base;
}

static kk_std_core_types__maybe kk_std_core_find_fun24580(kk_function_t _fself, kk_box_t x, kk_context_t* _ctx) {
  struct kk_std_core_find_fun24580__t* _self = kk_function_as(struct kk_std_core_find_fun24580__t*, _fself);
  kk_function_t pred = _self->pred; /* (14688) -> bool */
  kk_drop_match(_self, {kk_function_dup(pred);}, {}, _ctx)
  bool _match_23516;
  kk_box_t _x24581 = kk_box_dup(x); /*14688*/
  _match_23516 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_context_t*), pred, (pred, _x24581, _ctx)); /*bool*/
  if (_match_23516) {
    return kk_std_core_types__new_Just(x, _ctx);
  }
  kk_box_drop(x, _ctx);
  return kk_std_core_types__new_Nothing(_ctx);
}

kk_std_core_types__maybe kk_std_core_find(kk_std_core__list xs, kk_function_t pred, kk_context_t* _ctx) { /* forall<a> (xs : list<a>, pred : (a) -> bool) -> maybe<a> */ 
  return kk_std_core_foreach_while(xs, kk_std_core_new_find_fun24580(pred, _ctx), _ctx);
}
 
// O(n). If it occurs, return the position of substring `sub` in `s`, tupled with
// the position just following the substring `sub`.

kk_std_core_types__maybe kk_std_core_find_1(kk_string_t s, kk_string_t sub, kk_context_t* _ctx) { /* (s : string, sub : string) -> maybe<sslice> */ 
  size_t i;
  kk_string_t _x24582 = kk_string_dup(s); /*string*/
  kk_string_t _x24583 = kk_string_dup(sub); /*string*/
  i = kk_string_index_of1(_x24582,_x24583,kk_context()); /*size_t*/
  bool _match_23515 = kk_std_core_is_zero_1(i, _ctx); /*bool*/;
  if (_match_23515) {
    kk_string_drop(s, _ctx);
    kk_string_drop(sub, _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
  kk_std_core__sslice _b_22710_22709;
  size_t _x24584 = kk_std_core_decr_1(i, _ctx); /*size_t*/
  size_t _x24585 = kk_string_len(sub,kk_context()); /*size_t*/
  _b_22710_22709 = kk_std_core__new_Sslice(s, _x24584, _x24585, _ctx); /*sslice*/
  return kk_std_core_types__new_Just(kk_std_core__sslice_box(_b_22710_22709, _ctx), _ctx);
}
 
// Return the last index of substring `sub` in `s` if it occurs.

kk_std_core_types__maybe kk_std_core_find_last(kk_string_t s, kk_string_t sub, kk_context_t* _ctx) { /* (s : string, sub : string) -> maybe<sslice> */ 
  size_t i;
  kk_string_t _x24586 = kk_string_dup(s); /*string*/
  kk_string_t _x24587 = kk_string_dup(sub); /*string*/
  i = kk_string_last_index_of1(_x24586,_x24587,kk_context()); /*size_t*/
  bool _match_23514 = kk_std_core_is_zero_1(i, _ctx); /*bool*/;
  if (_match_23514) {
    kk_string_drop(s, _ctx);
    kk_string_drop(sub, _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
  kk_std_core__sslice _b_22712_22711;
  size_t _x24588 = kk_std_core_decr_1(i, _ctx); /*size_t*/
  size_t _x24589 = kk_string_len(sub,kk_context()); /*size_t*/
  _b_22712_22711 = kk_std_core__new_Sslice(s, _x24588, _x24589, _ctx); /*sslice*/
  return kk_std_core_types__new_Just(kk_std_core__sslice_box(_b_22712_22711, _ctx), _ctx);
}
 
// monadic lift

kk_std_core__list kk_std_core__mlift21206_op(kk_std_core_types__ctail _acc, kk_function_t f, kk_std_core__list xx, kk_std_core_types__maybe _y_151, kk_context_t* _ctx) { /* forall<a,b,e> (ctail<list<b>>, f : (a) -> e maybe<b>, xx : list<a>, maybe<b>) -> e list<b> */ 
  if (kk_std_core_types__is_Just(_y_151)) {
    kk_box_t y = _y_151._cons.Just.value;
    kk_std_core__list _ctail_21139 = kk_std_core__list_hole(); /*list<14928>*/;
    kk_std_core__list _ctail_21140 = kk_std_core__new_Cons(kk_reuse_null, y, _ctail_21139, _ctx); /*list<14928>*/;
    kk_std_core_types__ctail _x24592;
    kk_box_t* field_21619 = (kk_box_t*)((&kk_std_core__as_Cons(_ctail_21140)->tail)); /*cfield<list<14928>>*/;
    if (kk_std_core_types__is_CTail(_acc)) {
      kk_box_t _box_x22719 = _acc._cons.CTail._field1;
      kk_box_t* last0 = _acc._cons.CTail._field2;
      kk_std_core__list head0 = kk_std_core__list_unbox(_box_x22719, NULL);
      kk_unit_t __ = kk_Unit;
      *(last0) = kk_std_core__list_box(_ctail_21140, _ctx);
      _x24592 = kk_std_core_types__new_CTail(kk_std_core__list_box(head0, _ctx), field_21619, _ctx); /*ctail<58>*/
      goto _match24593;
    }
    _x24592 = kk_std_core_types__new_CTail(kk_std_core__list_box(_ctail_21140, _ctx), field_21619, _ctx); /*ctail<58>*/
    _match24593: ;
    return kk_std_core__ctail_flatmap_maybe(xx, f, _x24592, _ctx);
  }
  return kk_std_core__ctail_flatmap_maybe(xx, f, _acc, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_core__mlift21207_op_fun24595__t {
  struct kk_function_s _base;
  kk_function_t _accm;
  kk_box_t y0;
};
static kk_std_core__list kk_std_core__mlift21207_op_fun24595(kk_function_t _fself, kk_std_core__list _ctail_21142, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_mlift21207_op_fun24595(kk_function_t _accm, kk_box_t y0, kk_context_t* _ctx) {
  struct kk_std_core__mlift21207_op_fun24595__t* _self = kk_function_alloc_as(struct kk_std_core__mlift21207_op_fun24595__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__mlift21207_op_fun24595, kk_context());
  _self->_accm = _accm;
  _self->y0 = y0;
  return &_self->_base;
}

static kk_std_core__list kk_std_core__mlift21207_op_fun24595(kk_function_t _fself, kk_std_core__list _ctail_21142, kk_context_t* _ctx) {
  struct kk_std_core__mlift21207_op_fun24595__t* _self = kk_function_as(struct kk_std_core__mlift21207_op_fun24595__t*, _fself);
  kk_function_t _accm = _self->_accm; /* (list<14928>) -> list<14928> */
  kk_box_t y0 = _self->y0; /* 14928 */
  kk_drop_match(_self, {kk_function_dup(_accm);kk_box_dup(y0);}, {}, _ctx)
  kk_std_core__list _x24596 = kk_std_core__new_Cons(kk_reuse_null, y0, _ctail_21142, _ctx); /*list<61>*/
  return kk_function_call(kk_std_core__list, (kk_function_t, kk_std_core__list, kk_context_t*), _accm, (_accm, _x24596, _ctx));
}

kk_std_core__list kk_std_core__mlift21207_op(kk_function_t _accm, kk_function_t f0, kk_std_core__list xx0, kk_std_core_types__maybe _y_156, kk_context_t* _ctx) { /* forall<a,b,e> ((list<b>) -> list<b>, f : (a) -> e maybe<b>, xx : list<a>, maybe<b>) -> e list<b> */ 
  if (kk_std_core_types__is_Just(_y_156)) {
    kk_box_t y0 = _y_156._cons.Just.value;
    return kk_std_core__ctailm_flatmap_maybe(xx0, f0, kk_std_core__new_mlift21207_op_fun24595(_accm, y0, _ctx), _ctx);
  }
  return kk_std_core__ctailm_flatmap_maybe(xx0, f0, _accm, _ctx);
}
 
// Concatenate the `Just` result elements from applying a function to all elements.


// lift anonymous function
struct kk_std_core__ctail_flatmap_maybe_fun24600__t {
  struct kk_function_s _base;
  kk_function_t f1;
  kk_std_core__list xx1;
  kk_std_core_types__ctail _acc0;
};
static kk_box_t kk_std_core__ctail_flatmap_maybe_fun24600(kk_function_t _fself, kk_box_t _b_22733, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_ctail_flatmap_maybe_fun24600(kk_function_t f1, kk_std_core__list xx1, kk_std_core_types__ctail _acc0, kk_context_t* _ctx) {
  struct kk_std_core__ctail_flatmap_maybe_fun24600__t* _self = kk_function_alloc_as(struct kk_std_core__ctail_flatmap_maybe_fun24600__t, 5, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__ctail_flatmap_maybe_fun24600, kk_context());
  _self->f1 = f1;
  _self->xx1 = xx1;
  _self->_acc0 = _acc0;
  return &_self->_base;
}

static kk_box_t kk_std_core__ctail_flatmap_maybe_fun24600(kk_function_t _fself, kk_box_t _b_22733, kk_context_t* _ctx) {
  struct kk_std_core__ctail_flatmap_maybe_fun24600__t* _self = kk_function_as(struct kk_std_core__ctail_flatmap_maybe_fun24600__t*, _fself);
  kk_function_t f1 = _self->f1; /* (14927) -> 14929 maybe<14928> */
  kk_std_core__list xx1 = _self->xx1; /* list<14927> */
  kk_std_core_types__ctail _acc0 = _self->_acc0; /* ctail<list<14928>> */
  kk_drop_match(_self, {kk_function_dup(f1);kk_std_core__list_dup(xx1);kk_std_core_types__ctail_dup(_acc0);}, {}, _ctx)
  kk_std_core__list _x24601;
  kk_std_core_types__maybe _x24602 = kk_std_core_types__maybe_unbox(_b_22733, _ctx); /*maybe<14928>*/
  _x24601 = kk_std_core__mlift21206_op(_acc0, f1, xx1, _x24602, _ctx); /*list<14928>*/
  return kk_std_core__list_box(_x24601, _ctx);
}

kk_std_core__list kk_std_core__ctail_flatmap_maybe(kk_std_core__list xs, kk_function_t f1, kk_std_core_types__ctail _acc0, kk_context_t* _ctx) { /* forall<a,b,e> (xs : list<a>, f : (a) -> e maybe<b>, ctail<list<b>>) -> e list<b> */ 
  kk__tailcall: ;
  if (kk_std_core__is_Cons(xs)) {
    struct kk_std_core_Cons* _con24597 = kk_std_core__as_Cons(xs);
    kk_box_t x = _con24597->head;
    kk_std_core__list xx1 = _con24597->tail;
    kk_reuse_t _ru_23381 = kk_reuse_null; /*reuse*/;
    if (kk_std_core__list_is_unique(xs)) {
      _ru_23381 = (kk_std_core__list_reuse(xs));
    }
    else {
      kk_box_dup(x);
      kk_std_core__list_dup(xx1);
      kk_std_core__list_decref(xs, _ctx);
      _ru_23381 = kk_reuse_null;
    }
    kk_std_core_types__maybe x0_21620;
    kk_function_t _x24598 = kk_function_dup(f1); /*(14927) -> 14929 maybe<14928>*/
    x0_21620 = kk_function_call(kk_std_core_types__maybe, (kk_function_t, kk_box_t, kk_context_t*), _x24598, (_x24598, x, _ctx)); /*maybe<14928>*/
    if (kk_yielding(kk_context())) {
      kk_reuse_drop(_ru_23381, _ctx);
      kk_std_core_types__maybe_drop(x0_21620, _ctx);
      kk_box_t _x24599 = kk_std_core_hnd_yield_extend(kk_std_core__new_ctail_flatmap_maybe_fun24600(f1, xx1, _acc0, _ctx), _ctx); /*3991*/
      return kk_std_core__list_unbox(_x24599, _ctx);
    }
    if (kk_std_core_types__is_Just(x0_21620)) {
      kk_box_t y1 = x0_21620._cons.Just.value;
      kk_std_core__list _ctail_211390 = kk_std_core__list_hole(); /*list<14928>*/;
      kk_std_core__list _ctail_211400 = kk_std_core__new_Cons(_ru_23381, y1, _ctail_211390, _ctx); /*list<14928>*/;
      { // tailcall
        kk_std_core_types__ctail _x24603;
        kk_box_t* field_21626 = (kk_box_t*)((&kk_std_core__as_Cons(_ctail_211400)->tail)); /*cfield<list<14928>>*/;
        if (kk_std_core_types__is_CTail(_acc0)) {
          kk_box_t _box_x22740 = _acc0._cons.CTail._field1;
          kk_box_t* last2 = _acc0._cons.CTail._field2;
          kk_std_core__list head1 = kk_std_core__list_unbox(_box_x22740, NULL);
          kk_unit_t __0 = kk_Unit;
          *(last2) = kk_std_core__list_box(_ctail_211400, _ctx);
          _x24603 = kk_std_core_types__new_CTail(kk_std_core__list_box(head1, _ctx), field_21626, _ctx); /*ctail<58>*/
          goto _match24604;
        }
        _x24603 = kk_std_core_types__new_CTail(kk_std_core__list_box(_ctail_211400, _ctx), field_21626, _ctx); /*ctail<58>*/
        _match24604: ;
        xs = xx1;
        _acc0 = _x24603;
        goto kk__tailcall;
      }
    }
    kk_reuse_drop(_ru_23381, _ctx);
    { // tailcall
      xs = xx1;
      goto kk__tailcall;
    }
  }
  kk_function_drop(f1, _ctx);
  if (kk_std_core_types__is_CTail(_acc0)) {
    kk_box_t _box_x22749 = _acc0._cons.CTail._field1;
    kk_box_t* last00 = _acc0._cons.CTail._field2;
    kk_std_core__list head00 = kk_std_core__list_unbox(_box_x22749, NULL);
    kk_unit_t __00 = kk_Unit;
    *(last00) = kk_std_core__list_box(kk_std_core__new_Nil(_ctx), _ctx);
    return head00;
  }
  return kk_std_core__new_Nil(_ctx);
}
 
// Concatenate the `Just` result elements from applying a function to all elements.


// lift anonymous function
struct kk_std_core__ctailm_flatmap_maybe_fun24610__t {
  struct kk_function_s _base;
  kk_function_t _accm0;
  kk_function_t f2;
  kk_std_core__list xx2;
};
static kk_box_t kk_std_core__ctailm_flatmap_maybe_fun24610(kk_function_t _fself, kk_box_t _b_22761, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_ctailm_flatmap_maybe_fun24610(kk_function_t _accm0, kk_function_t f2, kk_std_core__list xx2, kk_context_t* _ctx) {
  struct kk_std_core__ctailm_flatmap_maybe_fun24610__t* _self = kk_function_alloc_as(struct kk_std_core__ctailm_flatmap_maybe_fun24610__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__ctailm_flatmap_maybe_fun24610, kk_context());
  _self->_accm0 = _accm0;
  _self->f2 = f2;
  _self->xx2 = xx2;
  return &_self->_base;
}

static kk_box_t kk_std_core__ctailm_flatmap_maybe_fun24610(kk_function_t _fself, kk_box_t _b_22761, kk_context_t* _ctx) {
  struct kk_std_core__ctailm_flatmap_maybe_fun24610__t* _self = kk_function_as(struct kk_std_core__ctailm_flatmap_maybe_fun24610__t*, _fself);
  kk_function_t _accm0 = _self->_accm0; /* (list<14928>) -> list<14928> */
  kk_function_t f2 = _self->f2; /* (14927) -> 14929 maybe<14928> */
  kk_std_core__list xx2 = _self->xx2; /* list<14927> */
  kk_drop_match(_self, {kk_function_dup(_accm0);kk_function_dup(f2);kk_std_core__list_dup(xx2);}, {}, _ctx)
  kk_std_core__list _x24611;
  kk_std_core_types__maybe _x24612 = kk_std_core_types__maybe_unbox(_b_22761, _ctx); /*maybe<14928>*/
  _x24611 = kk_std_core__mlift21207_op(_accm0, f2, xx2, _x24612, _ctx); /*list<14928>*/
  return kk_std_core__list_box(_x24611, _ctx);
}


// lift anonymous function
struct kk_std_core__ctailm_flatmap_maybe_fun24614__t {
  struct kk_function_s _base;
  kk_function_t _accm0;
  kk_box_t y2;
};
static kk_std_core__list kk_std_core__ctailm_flatmap_maybe_fun24614(kk_function_t _fself, kk_std_core__list _ctail_211420, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_ctailm_flatmap_maybe_fun24614(kk_function_t _accm0, kk_box_t y2, kk_context_t* _ctx) {
  struct kk_std_core__ctailm_flatmap_maybe_fun24614__t* _self = kk_function_alloc_as(struct kk_std_core__ctailm_flatmap_maybe_fun24614__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__ctailm_flatmap_maybe_fun24614, kk_context());
  _self->_accm0 = _accm0;
  _self->y2 = y2;
  return &_self->_base;
}

static kk_std_core__list kk_std_core__ctailm_flatmap_maybe_fun24614(kk_function_t _fself, kk_std_core__list _ctail_211420, kk_context_t* _ctx) {
  struct kk_std_core__ctailm_flatmap_maybe_fun24614__t* _self = kk_function_as(struct kk_std_core__ctailm_flatmap_maybe_fun24614__t*, _fself);
  kk_function_t _accm0 = _self->_accm0; /* (list<14928>) -> list<14928> */
  kk_box_t y2 = _self->y2; /* 14928 */
  kk_drop_match(_self, {kk_function_dup(_accm0);kk_box_dup(y2);}, {}, _ctx)
  kk_std_core__list _x24615 = kk_std_core__new_Cons(kk_reuse_null, y2, _ctail_211420, _ctx); /*list<61>*/
  return kk_function_call(kk_std_core__list, (kk_function_t, kk_std_core__list, kk_context_t*), _accm0, (_accm0, _x24615, _ctx));
}

kk_std_core__list kk_std_core__ctailm_flatmap_maybe(kk_std_core__list xs0, kk_function_t f2, kk_function_t _accm0, kk_context_t* _ctx) { /* forall<a,b,e> (xs : list<a>, f : (a) -> e maybe<b>, (list<b>) -> list<b>) -> e list<b> */ 
  kk__tailcall: ;
  if (kk_std_core__is_Cons(xs0)) {
    struct kk_std_core_Cons* _con24607 = kk_std_core__as_Cons(xs0);
    kk_box_t x0 = _con24607->head;
    kk_std_core__list xx2 = _con24607->tail;
    if (kk_std_core__list_is_unique(xs0)) {
      kk_std_core__list_free(xs0);
    }
    else {
      kk_box_dup(x0);
      kk_std_core__list_dup(xx2);
      kk_std_core__list_decref(xs0, _ctx);
    }
    kk_std_core_types__maybe x0_21629;
    kk_function_t _x24608 = kk_function_dup(f2); /*(14927) -> 14929 maybe<14928>*/
    x0_21629 = kk_function_call(kk_std_core_types__maybe, (kk_function_t, kk_box_t, kk_context_t*), _x24608, (_x24608, x0, _ctx)); /*maybe<14928>*/
    if (kk_yielding(kk_context())) {
      kk_std_core_types__maybe_drop(x0_21629, _ctx);
      kk_box_t _x24609 = kk_std_core_hnd_yield_extend(kk_std_core__new_ctailm_flatmap_maybe_fun24610(_accm0, f2, xx2, _ctx), _ctx); /*3991*/
      return kk_std_core__list_unbox(_x24609, _ctx);
    }
    if (kk_std_core_types__is_Just(x0_21629)) {
      kk_box_t y2 = x0_21629._cons.Just.value;
      { // tailcall
        kk_function_t _x24613 = kk_std_core__new_ctailm_flatmap_maybe_fun24614(_accm0, y2, _ctx); /*(list<14928>) -> list<14928>*/
        xs0 = xx2;
        _accm0 = _x24613;
        goto kk__tailcall;
      }
    }
    { // tailcall
      xs0 = xx2;
      goto kk__tailcall;
    }
  }
  kk_function_drop(f2, _ctx);
  return kk_function_call(kk_std_core__list, (kk_function_t, kk_std_core__list, kk_context_t*), _accm0, (_accm0, kk_std_core__new_Nil(_ctx), _ctx));
}
 
// Concatenate the `Just` result elements from applying a function to all elements.


// lift anonymous function
struct kk_std_core_flatmap_maybe_fun24616__t {
  struct kk_function_s _base;
};
static kk_std_core__list kk_std_core_flatmap_maybe_fun24616(kk_function_t _fself, kk_std_core__list _ctail_21141, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_flatmap_maybe_fun24616(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_flatmap_maybe_fun24616, _ctx)
  return kk_function_dup(_fself);
}

static kk_std_core__list kk_std_core_flatmap_maybe_fun24616(kk_function_t _fself, kk_std_core__list _ctail_21141, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return _ctail_21141;
}

kk_std_core__list kk_std_core_flatmap_maybe(kk_std_core__list xs1, kk_function_t f3, kk_context_t* _ctx) { /* forall<a,b,e> (xs : list<a>, f : (a) -> e maybe<b>) -> e list<b> */ 
  bool _match_23511 = kk_std_core_hnd__evv_is_affine(_ctx); /*bool*/;
  if (_match_23511) {
    return kk_std_core__ctail_flatmap_maybe(xs1, f3, kk_std_core_types__new_CTailNil(_ctx), _ctx);
  }
  return kk_std_core__ctailm_flatmap_maybe(xs1, f3, kk_std_core_new_flatmap_maybe_fun24616(_ctx), _ctx);
}

kk_box_t kk_std_core_fold_int(kk_integer_t start0, kk_integer_t end, kk_box_t init0, kk_function_t f, kk_context_t* _ctx) { /* forall<a> (start : int, end : int, init : a, f : (int, a) -> a) -> a */ 
  kk__tailcall: ;
  bool _match_23510;
  kk_integer_t _x24617 = kk_integer_dup(start0); /*int*/
  kk_integer_t _x24618 = kk_integer_dup(end); /*int*/
  _match_23510 = kk_integer_gte(_x24617,_x24618,kk_context()); /*bool*/
  if (_match_23510) {
    kk_integer_drop(end, _ctx);
    kk_function_drop(f, _ctx);
    kk_integer_drop(start0, _ctx);
    return init0;
  }
  kk_box_t x;
  kk_function_t _x24620 = kk_function_dup(f); /*(int, 15007) -> 15007*/
  kk_integer_t _x24619 = kk_integer_dup(start0); /*int*/
  x = kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_box_t, kk_context_t*), _x24620, (_x24620, _x24619, init0, _ctx)); /*15007*/
  { // tailcall
    kk_integer_t _x24621 = kk_std_core_inc(start0, _ctx); /*int*/
    start0 = _x24621;
    init0 = x;
    goto kk__tailcall;
  }
}
 
// monadic lift

kk_box_t kk_std_core__mlift21208_foldl(kk_function_t f, kk_std_core__list xx, kk_box_t _y_164, kk_context_t* _ctx) { /* forall<a,e,b> (f : (a, b) -> e a, xx : list<b>, a) -> e a */ 
  return kk_std_core_foldl(xx, _y_164, f, _ctx);
}
 
// Fold a list from the left, i.e. `foldl([1,2],0,(+)) == (0+1)+2`
// Since `foldl` is tail recursive, it is preferred over `foldr` when using an associative function `f`


// lift anonymous function
struct kk_std_core_foldl_fun24624__t {
  struct kk_function_s _base;
  kk_function_t f0;
  kk_std_core__list xx0;
};
static kk_box_t kk_std_core_foldl_fun24624(kk_function_t _fself, kk_box_t _y_1640, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_foldl_fun24624(kk_function_t f0, kk_std_core__list xx0, kk_context_t* _ctx) {
  struct kk_std_core_foldl_fun24624__t* _self = kk_function_alloc_as(struct kk_std_core_foldl_fun24624__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_foldl_fun24624, kk_context());
  _self->f0 = f0;
  _self->xx0 = xx0;
  return &_self->_base;
}

static kk_box_t kk_std_core_foldl_fun24624(kk_function_t _fself, kk_box_t _y_1640, kk_context_t* _ctx) {
  struct kk_std_core_foldl_fun24624__t* _self = kk_function_as(struct kk_std_core_foldl_fun24624__t*, _fself);
  kk_function_t f0 = _self->f0; /* (15010, 15015) -> 15012 15010 */
  kk_std_core__list xx0 = _self->xx0; /* list<15015> */
  kk_drop_match(_self, {kk_function_dup(f0);kk_std_core__list_dup(xx0);}, {}, _ctx)
  return kk_std_core__mlift21208_foldl(f0, xx0, _y_1640, _ctx);
}

kk_box_t kk_std_core_foldl(kk_std_core__list xs, kk_box_t z, kk_function_t f0, kk_context_t* _ctx) { /* forall<a,b,e> (list<a>, b, (b, a) -> e b) -> e b */ 
  kk__tailcall: ;
  if (kk_std_core__is_Cons(xs)) {
    struct kk_std_core_Cons* _con24622 = kk_std_core__as_Cons(xs);
    kk_box_t x = _con24622->head;
    kk_std_core__list xx0 = _con24622->tail;
    if (kk_std_core__list_is_unique(xs)) {
      kk_std_core__list_free(xs);
    }
    else {
      kk_box_dup(x);
      kk_std_core__list_dup(xx0);
      kk_std_core__list_decref(xs, _ctx);
    }
    kk_box_t x0_21633;
    kk_function_t _x24623 = kk_function_dup(f0); /*(15010, 15015) -> 15012 15010*/
    x0_21633 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _x24623, (_x24623, z, x, _ctx)); /*15010*/
    if (kk_yielding(kk_context())) {
      kk_box_drop(x0_21633, _ctx);
      return kk_std_core_hnd_yield_extend(kk_std_core_new_foldl_fun24624(f0, xx0, _ctx), _ctx);
    }
    { // tailcall
      xs = xx0;
      z = x0_21633;
      goto kk__tailcall;
    }
  }
  kk_function_drop(f0, _ctx);
  return z;
}


// lift anonymous function
struct kk_std_core_foldl1_fun24637__t {
  struct kk_function_s _base;
  size_t i_21637;
};
static kk_box_t kk_std_core_foldl1_fun24637(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_foldl1_fun24637(size_t i_21637, kk_context_t* _ctx) {
  struct kk_std_core_foldl1_fun24637__t* _self = kk_function_alloc_as(struct kk_std_core_foldl1_fun24637__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_foldl1_fun24637, kk_context());
  _self->i_21637 = i_21637;
  return &_self->_base;
}

static kk_box_t kk_std_core_foldl1_fun24637(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_std_core_foldl1_fun24637__t* _self = kk_function_as(struct kk_std_core_foldl1_fun24637__t*, _fself);
  size_t i_21637 = _self->i_21637; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_21637, cont, res, _ctx);
}

kk_box_t kk_std_core_foldl1(kk_std_core__list xs, kk_function_t f, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, f : (a, a) -> <exn|e> a) -> <exn|e> a */ 
  if (kk_std_core__is_Cons(xs)) {
    struct kk_std_core_Cons* _con24625 = kk_std_core__as_Cons(xs);
    kk_box_t x = _con24625->head;
    kk_std_core__list xx = _con24625->tail;
    if (kk_std_core__list_is_unique(xs)) {
      kk_std_core__list_free(xs);
    }
    else {
      kk_box_dup(x);
      kk_std_core__list_dup(xx);
      kk_std_core__list_decref(xs, _ctx);
    }
    return kk_std_core_foldl(xx, x, f, _ctx);
  }
  kk_function_drop(f, _ctx);
  size_t i_21637;
  kk_std_core_hnd__htag _x24626 = kk_std_core_hnd__htag_dup(kk_std_core__tag_exn); /*std/core/hnd/htag<.hnd-exn>*/
  i_21637 = kk_std_core_hnd__evv_index(_x24626, _ctx); /*std/core/hnd/ev-index*/
  kk_evv_t w = kk_evv_swap_create1(i_21637,kk_context()); /*std/core/hnd/evv<<exn|15087>>*/;
  kk_box_t y;
  kk_std_core__exception exn_21565;
  kk_string_t _x24627;
  kk_define_string_literal(, _s24628, 33, "unexpected Nil in std/core/foldl1")
  _x24627 = kk_string_dup(_s24628); /*string*/
  kk_std_core__exception_info _x24629;
  kk_std_core_types__optional _x24630 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/
  if (kk_std_core_types__is_Optional(_x24630)) {
    kk_box_t _box_x22764 = _x24630._cons.Optional.value;
    kk_std_core__exception_info _info_14279 = kk_std_core__exception_info_unbox(_box_x22764, NULL);
    _x24629 = _info_14279; /*exception-info*/
    goto _match24631;
  }
  _x24629 = kk_std_core__new_ExnError(_ctx); /*exception-info*/
  _match24631: ;
  exn_21565 = kk_std_core__new_Exception(_x24627, _x24629, _ctx); /*exception*/
  kk_std_core_hnd__ev ev_21566;
  size_t _x24633 = ((size_t)0); /*size_t*/
  ev_21566 = kk_evv_at(_x24633,kk_context()); /*std/core/hnd/ev<.hnd-exn>*/
  struct kk_std_core_hnd_Ev* _con24634 = kk_std_core_hnd__as_Ev(ev_21566);
  kk_std_core_hnd__marker m = _con24634->marker;
  kk_box_t _box_x22765 = _con24634->hnd;
  kk_std_core__hnd_exn h = kk_std_core__hnd_exn_unbox(_box_x22765, NULL);
  kk_std_core__hnd_exn_dup(h);
  kk_std_core_hnd__clause1 _match_23507;
  struct kk_std_core__Hnd_exn* _con24636 = kk_std_core__as_Hnd_exn(h);
  kk_std_core_hnd__clause1 except_throw_exn = _con24636->except_throw_exn;
  if (kk_std_core__hnd_exn_is_unique(h)) {
    kk_std_core__hnd_exn_free(h);
  }
  else {
    kk_std_core_hnd__clause1_dup(except_throw_exn);
    kk_std_core__hnd_exn_decref(h, _ctx);
  }
  _match_23507 = except_throw_exn; /*forall<a> std/core/hnd/clause1<exception,a,.hnd-exn,3528,3529>*/
  kk_function_t _fun_unbox_x22769 = _match_23507.clause;
  y = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x22769, (_fun_unbox_x22769, m, ev_21566, kk_std_core__exception_box(exn_21565, _ctx), _ctx)); /*15086*/
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_drop(y, _ctx);
    return kk_std_core_hnd_yield_cont(kk_std_core_new_foldl1_fun24637(i_21637, _ctx), _ctx);
  }
  return y;
}
extern kk_box_t kk_std_core_foldr_fun24639(kk_function_t _fself, kk_box_t x, kk_box_t y, kk_context_t* _ctx) {
  struct kk_std_core_foldr_fun24639__t* _self = kk_function_as(struct kk_std_core_foldr_fun24639__t*, _fself);
  kk_function_t f = _self->f; /* (15105, 15101) -> 15103 15101 */
  kk_drop_match(_self, {kk_function_dup(f);}, {}, _ctx)
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), f, (f, y, x, _ctx));
}


// lift anonymous function
struct kk_std_core_foldr1_fun24652__t {
  struct kk_function_s _base;
  size_t i_21645;
};
static kk_box_t kk_std_core_foldr1_fun24652(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_foldr1_fun24652(size_t i_21645, kk_context_t* _ctx) {
  struct kk_std_core_foldr1_fun24652__t* _self = kk_function_alloc_as(struct kk_std_core_foldr1_fun24652__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_foldr1_fun24652, kk_context());
  _self->i_21645 = i_21645;
  return &_self->_base;
}

static kk_box_t kk_std_core_foldr1_fun24652(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_std_core_foldr1_fun24652__t* _self = kk_function_as(struct kk_std_core_foldr1_fun24652__t*, _fself);
  size_t i_21645 = _self->i_21645; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_21645, cont, res, _ctx);
}

kk_box_t kk_std_core_foldr1(kk_std_core__list xs, kk_function_t f, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, f : (a, a) -> <exn|e> a) -> <exn|e> a */ 
  kk_std_core__list xs0_21643 = kk_std_core_reverse(xs, _ctx); /*list<15139>*/;
  if (kk_std_core__is_Cons(xs0_21643)) {
    struct kk_std_core_Cons* _con24640 = kk_std_core__as_Cons(xs0_21643);
    kk_box_t x = _con24640->head;
    kk_std_core__list xx = _con24640->tail;
    if (kk_std_core__list_is_unique(xs0_21643)) {
      kk_std_core__list_free(xs0_21643);
    }
    else {
      kk_box_dup(x);
      kk_std_core__list_dup(xx);
      kk_std_core__list_decref(xs0_21643, _ctx);
    }
    return kk_std_core_foldl(xx, x, f, _ctx);
  }
  kk_function_drop(f, _ctx);
  size_t i_21645;
  kk_std_core_hnd__htag _x24641 = kk_std_core_hnd__htag_dup(kk_std_core__tag_exn); /*std/core/hnd/htag<.hnd-exn>*/
  i_21645 = kk_std_core_hnd__evv_index(_x24641, _ctx); /*std/core/hnd/ev-index*/
  kk_evv_t w = kk_evv_swap_create1(i_21645,kk_context()); /*std/core/hnd/evv<<exn|15140>>*/;
  kk_box_t y;
  kk_std_core__exception exn_21565;
  kk_string_t _x24642;
  kk_define_string_literal(, _s24643, 33, "unexpected Nil in std/core/foldl1")
  _x24642 = kk_string_dup(_s24643); /*string*/
  kk_std_core__exception_info _x24644;
  kk_std_core_types__optional _x24645 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/
  if (kk_std_core_types__is_Optional(_x24645)) {
    kk_box_t _box_x22776 = _x24645._cons.Optional.value;
    kk_std_core__exception_info _info_14279 = kk_std_core__exception_info_unbox(_box_x22776, NULL);
    _x24644 = _info_14279; /*exception-info*/
    goto _match24646;
  }
  _x24644 = kk_std_core__new_ExnError(_ctx); /*exception-info*/
  _match24646: ;
  exn_21565 = kk_std_core__new_Exception(_x24642, _x24644, _ctx); /*exception*/
  kk_std_core_hnd__ev ev_21566;
  size_t _x24648 = ((size_t)0); /*size_t*/
  ev_21566 = kk_evv_at(_x24648,kk_context()); /*std/core/hnd/ev<.hnd-exn>*/
  struct kk_std_core_hnd_Ev* _con24649 = kk_std_core_hnd__as_Ev(ev_21566);
  kk_std_core_hnd__marker m = _con24649->marker;
  kk_box_t _box_x22777 = _con24649->hnd;
  kk_std_core__hnd_exn h = kk_std_core__hnd_exn_unbox(_box_x22777, NULL);
  kk_std_core__hnd_exn_dup(h);
  kk_std_core_hnd__clause1 _match_23504;
  struct kk_std_core__Hnd_exn* _con24651 = kk_std_core__as_Hnd_exn(h);
  kk_std_core_hnd__clause1 except_throw_exn = _con24651->except_throw_exn;
  if (kk_std_core__hnd_exn_is_unique(h)) {
    kk_std_core__hnd_exn_free(h);
  }
  else {
    kk_std_core_hnd__clause1_dup(except_throw_exn);
    kk_std_core__hnd_exn_decref(h, _ctx);
  }
  _match_23504 = except_throw_exn; /*forall<a> std/core/hnd/clause1<exception,a,.hnd-exn,3528,3529>*/
  kk_function_t _fun_unbox_x22781 = _match_23504.clause;
  y = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x22781, (_fun_unbox_x22781, m, ev_21566, kk_std_core__exception_box(exn_21565, _ctx), _ctx)); /*15139*/
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_drop(y, _ctx);
    return kk_std_core_hnd_yield_cont(kk_std_core_new_foldr1_fun24652(i_21645, _ctx), _ctx);
  }
  return y;
}
 
// monadic lift

kk_unit_t kk_std_core__mlift21209_op(kk_function_t action, kk_integer_t end, kk_integer_t i, kk_unit_t wild__, kk_context_t* _ctx) { /* forall<e> (action : (int) -> e (), end : int, i : int, wild_ : ()) -> e () */ 
  kk_integer_t i0_21085 = kk_std_core_inc(i, _ctx); /*int*/;
  kk_std_core__lift21056_for(action, end, i0_21085, _ctx); return kk_Unit;
}
 
// lift


// lift anonymous function
struct kk_std_core__lift21056_for_fun24658__t {
  struct kk_function_s _base;
  kk_function_t action0;
  kk_integer_t end0;
  kk_integer_t i0;
};
static kk_box_t kk_std_core__lift21056_for_fun24658(kk_function_t _fself, kk_box_t _b_22789, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_lift21056_for_fun24658(kk_function_t action0, kk_integer_t end0, kk_integer_t i0, kk_context_t* _ctx) {
  struct kk_std_core__lift21056_for_fun24658__t* _self = kk_function_alloc_as(struct kk_std_core__lift21056_for_fun24658__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__lift21056_for_fun24658, kk_context());
  _self->action0 = action0;
  _self->end0 = end0;
  _self->i0 = i0;
  return &_self->_base;
}

static kk_box_t kk_std_core__lift21056_for_fun24658(kk_function_t _fself, kk_box_t _b_22789, kk_context_t* _ctx) {
  struct kk_std_core__lift21056_for_fun24658__t* _self = kk_function_as(struct kk_std_core__lift21056_for_fun24658__t*, _fself);
  kk_function_t action0 = _self->action0; /* (int) -> 15141 () */
  kk_integer_t end0 = _self->end0; /* int */
  kk_integer_t i0 = _self->i0; /* int */
  kk_drop_match(_self, {kk_function_dup(action0);kk_integer_dup(end0);kk_integer_dup(i0);}, {}, _ctx)
  kk_unit_t _x24659 = kk_Unit;
  kk_unit_t _x24660 = kk_Unit;
  kk_unit_unbox(_b_22789);
  kk_std_core__mlift21209_op(action0, end0, i0, _x24660, _ctx);
  return kk_unit_box(_x24659);
}

kk_unit_t kk_std_core__lift21056_for(kk_function_t action0, kk_integer_t end0, kk_integer_t i0, kk_context_t* _ctx) { /* forall<e> (action : (int) -> e (), end : int, i : int) -> e () */ 
  kk__tailcall: ;
  bool _match_23501;
  kk_integer_t _x24653 = kk_integer_dup(i0); /*int*/
  kk_integer_t _x24654 = kk_integer_dup(end0); /*int*/
  _match_23501 = kk_integer_lte(_x24653,_x24654,kk_context()); /*bool*/
  if (_match_23501) {
    kk_unit_t x_21649 = kk_Unit;
    kk_function_t _x24656 = kk_function_dup(action0); /*(int) -> 15141 ()*/
    kk_integer_t _x24655 = kk_integer_dup(i0); /*int*/
    kk_function_call(kk_unit_t, (kk_function_t, kk_integer_t, kk_context_t*), _x24656, (_x24656, _x24655, _ctx));
    if (kk_yielding(kk_context())) {
      kk_box_t _x24657 = kk_std_core_hnd_yield_extend(kk_std_core__new_lift21056_for_fun24658(action0, end0, i0, _ctx), _ctx); /*3991*/
      kk_unit_unbox(_x24657); return kk_Unit;
    }
    kk_integer_t i0_210850 = kk_std_core_inc(i0, _ctx); /*int*/;
    { // tailcall
      i0 = i0_210850;
      goto kk__tailcall;
    }
  }
  kk_function_drop(action0, _ctx);
  kk_integer_drop(end0, _ctx);
  kk_integer_drop(i0, _ctx);
  kk_Unit; return kk_Unit;
}
 
// monadic lift

kk_std_core_types__maybe kk_std_core__mlift21210_op(kk_function_t action, kk_integer_t end, kk_integer_t i, kk_std_core_types__maybe _y_177, kk_context_t* _ctx) { /* forall<a,e> (action : (int) -> e maybe<a>, end : int, i : int, maybe<a>) -> e maybe<a> */ 
  if (kk_std_core_types__is_Nothing(_y_177)) {
    kk_integer_t i0_21087 = kk_std_core_inc(i, _ctx); /*int*/;
    return kk_std_core__lift21057_for_while(action, end, i0_21087, _ctx);
  }
  kk_box_t x = _y_177._cons.Just.value;
  kk_function_drop(action, _ctx);
  kk_integer_drop(end, _ctx);
  kk_integer_drop(i, _ctx);
  return kk_std_core_types__new_Just(x, _ctx);
}
 
// lift


// lift anonymous function
struct kk_std_core__lift21057_for_while_fun24666__t {
  struct kk_function_s _base;
  kk_function_t action0;
  kk_integer_t end0;
  kk_integer_t i0;
};
static kk_box_t kk_std_core__lift21057_for_while_fun24666(kk_function_t _fself, kk_box_t _b_22793, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_lift21057_for_while_fun24666(kk_function_t action0, kk_integer_t end0, kk_integer_t i0, kk_context_t* _ctx) {
  struct kk_std_core__lift21057_for_while_fun24666__t* _self = kk_function_alloc_as(struct kk_std_core__lift21057_for_while_fun24666__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__lift21057_for_while_fun24666, kk_context());
  _self->action0 = action0;
  _self->end0 = end0;
  _self->i0 = i0;
  return &_self->_base;
}

static kk_box_t kk_std_core__lift21057_for_while_fun24666(kk_function_t _fself, kk_box_t _b_22793, kk_context_t* _ctx) {
  struct kk_std_core__lift21057_for_while_fun24666__t* _self = kk_function_as(struct kk_std_core__lift21057_for_while_fun24666__t*, _fself);
  kk_function_t action0 = _self->action0; /* (int) -> 15194 maybe<15193> */
  kk_integer_t end0 = _self->end0; /* int */
  kk_integer_t i0 = _self->i0; /* int */
  kk_drop_match(_self, {kk_function_dup(action0);kk_integer_dup(end0);kk_integer_dup(i0);}, {}, _ctx)
  kk_std_core_types__maybe _x24667;
  kk_std_core_types__maybe _x24668 = kk_std_core_types__maybe_unbox(_b_22793, _ctx); /*maybe<15193>*/
  _x24667 = kk_std_core__mlift21210_op(action0, end0, i0, _x24668, _ctx); /*maybe<15193>*/
  return kk_std_core_types__maybe_box(_x24667, _ctx);
}

kk_std_core_types__maybe kk_std_core__lift21057_for_while(kk_function_t action0, kk_integer_t end0, kk_integer_t i0, kk_context_t* _ctx) { /* forall<a,e> (action : (int) -> e maybe<a>, end : int, i : int) -> e maybe<a> */ 
  kk__tailcall: ;
  bool _match_23499;
  kk_integer_t _x24661 = kk_integer_dup(i0); /*int*/
  kk_integer_t _x24662 = kk_integer_dup(end0); /*int*/
  _match_23499 = kk_integer_lte(_x24661,_x24662,kk_context()); /*bool*/
  if (_match_23499) {
    kk_std_core_types__maybe x_21653;
    kk_function_t _x24664 = kk_function_dup(action0); /*(int) -> 15194 maybe<15193>*/
    kk_integer_t _x24663 = kk_integer_dup(i0); /*int*/
    x_21653 = kk_function_call(kk_std_core_types__maybe, (kk_function_t, kk_integer_t, kk_context_t*), _x24664, (_x24664, _x24663, _ctx)); /*maybe<15193>*/
    if (kk_yielding(kk_context())) {
      kk_std_core_types__maybe_drop(x_21653, _ctx);
      kk_box_t _x24665 = kk_std_core_hnd_yield_extend(kk_std_core__new_lift21057_for_while_fun24666(action0, end0, i0, _ctx), _ctx); /*3991*/
      return kk_std_core_types__maybe_unbox(_x24665, _ctx);
    }
    if (kk_std_core_types__is_Nothing(x_21653)) {
      kk_integer_t i0_210870 = kk_std_core_inc(i0, _ctx); /*int*/;
      { // tailcall
        i0 = i0_210870;
        goto kk__tailcall;
      }
    }
    kk_box_t x0 = x_21653._cons.Just.value;
    kk_integer_drop(i0, _ctx);
    kk_integer_drop(end0, _ctx);
    kk_function_drop(action0, _ctx);
    return kk_std_core_types__new_Just(x0, _ctx);
  }
  kk_function_drop(action0, _ctx);
  kk_integer_drop(end0, _ctx);
  kk_integer_drop(i0, _ctx);
  return kk_std_core_types__new_Nothing(_ctx);
}
 
// monadic lift

kk_unit_t kk_std_core__mlift21211_foreach_indexed(kk_ref_t i, kk_integer_t _y_185, kk_context_t* _ctx) { /* forall<h,e> (i : local-var<h,int>, int) -> <local<h>|e> () */ 
  kk_integer_t _b_22799_22797 = kk_integer_add(_y_185,(kk_integer_from_small(1)),kk_context()); /*int*/;
  (kk_ref_set(i,(kk_integer_box(_b_22799_22797)),kk_context())); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_std_core__mlift21212_foreach_indexed_fun24672__t {
  struct kk_function_s _base;
  kk_ref_t i;
};
static kk_box_t kk_std_core__mlift21212_foreach_indexed_fun24672(kk_function_t _fself, kk_box_t _b_22803, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_mlift21212_foreach_indexed_fun24672(kk_ref_t i, kk_context_t* _ctx) {
  struct kk_std_core__mlift21212_foreach_indexed_fun24672__t* _self = kk_function_alloc_as(struct kk_std_core__mlift21212_foreach_indexed_fun24672__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__mlift21212_foreach_indexed_fun24672, kk_context());
  _self->i = i;
  return &_self->_base;
}

static kk_box_t kk_std_core__mlift21212_foreach_indexed_fun24672(kk_function_t _fself, kk_box_t _b_22803, kk_context_t* _ctx) {
  struct kk_std_core__mlift21212_foreach_indexed_fun24672__t* _self = kk_function_as(struct kk_std_core__mlift21212_foreach_indexed_fun24672__t*, _fself);
  kk_ref_t i = _self->i; /* local-var<15373,int> */
  kk_drop_match(_self, {kk_ref_dup(i);}, {}, _ctx)
  kk_unit_t _x24673 = kk_Unit;
  kk_integer_t _x24674 = kk_integer_unbox(_b_22803); /*int*/
  kk_std_core__mlift21211_foreach_indexed(i, _x24674, _ctx);
  return kk_unit_box(_x24673);
}

kk_unit_t kk_std_core__mlift21212_foreach_indexed(kk_ref_t i, kk_unit_t wild__, kk_context_t* _ctx) { /* forall<h,e> (i : local-var<h,int>, wild_ : ()) -> <local<h>|e> () */ 
  kk_integer_t x_21657;
  kk_box_t _x24669;
  kk_ref_t _x24670 = kk_ref_dup(i); /*local-var<15373,int>*/
  _x24669 = (kk_ref_get(_x24670,kk_context())); /*228*/
  x_21657 = kk_integer_unbox(_x24669); /*int*/
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_21657, _ctx);
    kk_box_t _x24671 = kk_std_core_hnd_yield_extend(kk_std_core__new_mlift21212_foreach_indexed_fun24672(i, _ctx), _ctx); /*3991*/
    kk_unit_unbox(_x24671); return kk_Unit;
  }
  kk_std_core__mlift21211_foreach_indexed(i, x_21657, _ctx); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_std_core__mlift21213_foreach_indexed_fun24676__t {
  struct kk_function_s _base;
  kk_ref_t i;
};
static kk_box_t kk_std_core__mlift21213_foreach_indexed_fun24676(kk_function_t _fself, kk_box_t _b_22807, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_mlift21213_foreach_indexed_fun24676(kk_ref_t i, kk_context_t* _ctx) {
  struct kk_std_core__mlift21213_foreach_indexed_fun24676__t* _self = kk_function_alloc_as(struct kk_std_core__mlift21213_foreach_indexed_fun24676__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__mlift21213_foreach_indexed_fun24676, kk_context());
  _self->i = i;
  return &_self->_base;
}

static kk_box_t kk_std_core__mlift21213_foreach_indexed_fun24676(kk_function_t _fself, kk_box_t _b_22807, kk_context_t* _ctx) {
  struct kk_std_core__mlift21213_foreach_indexed_fun24676__t* _self = kk_function_as(struct kk_std_core__mlift21213_foreach_indexed_fun24676__t*, _fself);
  kk_ref_t i = _self->i; /* local-var<15373,int> */
  kk_drop_match(_self, {kk_ref_dup(i);}, {}, _ctx)
  kk_unit_t _x24677 = kk_Unit;
  kk_unit_t _x24678 = kk_Unit;
  kk_unit_unbox(_b_22807);
  kk_std_core__mlift21212_foreach_indexed(i, _x24678, _ctx);
  return kk_unit_box(_x24677);
}

kk_unit_t kk_std_core__mlift21213_foreach_indexed(kk_function_t action, kk_ref_t i, kk_box_t x, kk_integer_t j, kk_context_t* _ctx) { /* forall<h,a,e> (action : (int, a) -> e (), i : local-var<h,int>, x : a, j : int) -> <local<h>|e> () */ 
  kk_unit_t x0_21659 = kk_Unit;
  kk_function_call(kk_unit_t, (kk_function_t, kk_integer_t, kk_box_t, kk_context_t*), action, (action, j, x, _ctx));
  if (kk_yielding(kk_context())) {
    kk_box_t _x24675 = kk_std_core_hnd_yield_extend(kk_std_core__new_mlift21213_foreach_indexed_fun24676(i, _ctx), _ctx); /*3991*/
    kk_unit_unbox(_x24675); return kk_Unit;
  }
  kk_std_core__mlift21212_foreach_indexed(i, x0_21659, _ctx); return kk_Unit;
}
 
// Invoke `action` for each element of a list, passing also the position of the element.


// lift anonymous function
struct kk_std_core_foreach_indexed_fun24680__t {
  struct kk_function_s _base;
  kk_function_t action;
  kk_ref_t loc;
};
static kk_unit_t kk_std_core_foreach_indexed_fun24680(kk_function_t _fself, kk_box_t x, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_foreach_indexed_fun24680(kk_function_t action, kk_ref_t loc, kk_context_t* _ctx) {
  struct kk_std_core_foreach_indexed_fun24680__t* _self = kk_function_alloc_as(struct kk_std_core_foreach_indexed_fun24680__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_foreach_indexed_fun24680, kk_context());
  _self->action = action;
  _self->loc = loc;
  return &_self->_base;
}



// lift anonymous function
struct kk_std_core_foreach_indexed_fun24684__t {
  struct kk_function_s _base;
  kk_function_t action;
  kk_ref_t loc;
  kk_box_t x;
};
static kk_box_t kk_std_core_foreach_indexed_fun24684(kk_function_t _fself, kk_box_t _b_22815, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_foreach_indexed_fun24684(kk_function_t action, kk_ref_t loc, kk_box_t x, kk_context_t* _ctx) {
  struct kk_std_core_foreach_indexed_fun24684__t* _self = kk_function_alloc_as(struct kk_std_core_foreach_indexed_fun24684__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_foreach_indexed_fun24684, kk_context());
  _self->action = action;
  _self->loc = loc;
  _self->x = x;
  return &_self->_base;
}

static kk_box_t kk_std_core_foreach_indexed_fun24684(kk_function_t _fself, kk_box_t _b_22815, kk_context_t* _ctx) {
  struct kk_std_core_foreach_indexed_fun24684__t* _self = kk_function_as(struct kk_std_core_foreach_indexed_fun24684__t*, _fself);
  kk_function_t action = _self->action; /* (int, 15379) -> 15380 () */
  kk_ref_t loc = _self->loc; /* local-var<global,int> */
  kk_box_t x = _self->x; /* 15379 */
  kk_drop_match(_self, {kk_function_dup(action);kk_ref_dup(loc);kk_box_dup(x);}, {}, _ctx)
  kk_unit_t _x24685 = kk_Unit;
  kk_integer_t _x24686 = kk_integer_unbox(_b_22815); /*int*/
  kk_std_core__mlift21213_foreach_indexed(action, loc, x, _x24686, _ctx);
  return kk_unit_box(_x24685);
}
static kk_unit_t kk_std_core_foreach_indexed_fun24680(kk_function_t _fself, kk_box_t x, kk_context_t* _ctx) {
  struct kk_std_core_foreach_indexed_fun24680__t* _self = kk_function_as(struct kk_std_core_foreach_indexed_fun24680__t*, _fself);
  kk_function_t action = _self->action; /* (int, 15379) -> 15380 () */
  kk_ref_t loc = _self->loc; /* local-var<global,int> */
  kk_drop_match(_self, {kk_function_dup(action);kk_ref_dup(loc);}, {}, _ctx)
  kk_integer_t x0_21666;
  kk_box_t _x24681;
  kk_ref_t _x24682 = kk_ref_dup(loc); /*local-var<global,int>*/
  _x24681 = (kk_ref_get(_x24682,kk_context())); /*228*/
  x0_21666 = kk_integer_unbox(_x24681); /*int*/
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x0_21666, _ctx);
    kk_box_t _x24683 = kk_std_core_hnd_yield_extend(kk_std_core_new_foreach_indexed_fun24684(action, loc, x, _ctx), _ctx); /*3991*/
    return kk_unit_unbox(_x24683);
  }
  return kk_std_core__mlift21213_foreach_indexed(action, loc, x, x0_21666, _ctx);
}

kk_unit_t kk_std_core_foreach_indexed(kk_std_core__list xs, kk_function_t action, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, action : (int, a) -> e ()) -> e () */ 
  kk_ref_t loc = kk_ref_alloc((kk_integer_box(kk_integer_from_small(0))),kk_context()); /*local-var<global,int>*/;
  kk_unit_t res = kk_Unit;
  kk_function_t _x24679;
  kk_ref_dup(loc);
  _x24679 = kk_std_core_new_foreach_indexed_fun24680(action, loc, _ctx); /*(x : 15379) -> <local<global>|15380> ()*/
  kk_std_core_foreach(xs, _x24679, _ctx);
  kk_box_t _x24687 = kk_std_core_hnd_prompt_local_var(loc, kk_unit_box(res), _ctx); /*9788*/
  kk_unit_unbox(_x24687); return kk_Unit;
}
 
// Invoke a function `f` for each element in a vector `v`


// lift anonymous function
struct kk_std_core_foreach_indexed_fun24690__t_1 {
  struct kk_function_s _base;
  kk_function_t f;
  kk_vector_t v;
};
static kk_unit_t kk_std_core_foreach_indexed_fun24690_1(kk_function_t _fself, size_t i, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_foreach_indexed_fun24690_1(kk_function_t f, kk_vector_t v, kk_context_t* _ctx) {
  struct kk_std_core_foreach_indexed_fun24690__t_1* _self = kk_function_alloc_as(struct kk_std_core_foreach_indexed_fun24690__t_1, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_foreach_indexed_fun24690_1, kk_context());
  _self->f = f;
  _self->v = v;
  return &_self->_base;
}

static kk_unit_t kk_std_core_foreach_indexed_fun24690_1(kk_function_t _fself, size_t i, kk_context_t* _ctx) {
  struct kk_std_core_foreach_indexed_fun24690__t_1* _self = kk_function_as(struct kk_std_core_foreach_indexed_fun24690__t_1*, _fself);
  kk_function_t f = _self->f; /* (15418, int) -> 15419 () */
  kk_vector_t v = _self->v; /* vector<15418> */
  kk_drop_match(_self, {kk_function_dup(f);kk_vector_dup(v);}, {}, _ctx)
  kk_box_t x_21673 = kk_vector_at(v,i); /*15418*/;
  kk_integer_t _x24691 = kk_integer_from_size_t(i,kk_context()); /*int*/
  return kk_function_call(kk_unit_t, (kk_function_t, kk_box_t, kk_integer_t, kk_context_t*), f, (f, x_21673, _x24691, _ctx));
}

kk_unit_t kk_std_core_foreach_indexed_1(kk_vector_t v, kk_function_t f, kk_context_t* _ctx) { /* forall<a,e> (v : vector<a>, f : (a, int) -> e ()) -> e () */ 
  size_t start_21670 = ((size_t)0); /*size_t*/;
  size_t end_21671;
  size_t _x24688;
  kk_vector_t _x24689 = kk_vector_dup(v); /*vector<15418>*/
  _x24688 = kk_vector_len(_x24689); /*size_t*/
  end_21671 = kk_std_core_decr_1(_x24688, _ctx); /*size_t*/
  kk_std_core__lift21051_forz(kk_std_core_new_foreach_indexed_fun24690_1(f, v, _ctx), end_21671, start_21670, _ctx); return kk_Unit;
}
 
// Return the head of list if the list is not empty.

kk_std_core_types__maybe kk_std_core_head_1(kk_std_core__list xs, kk_context_t* _ctx) { /* forall<a> (xs : list<a>) -> maybe<a> */ 
  if (kk_std_core__is_Cons(xs)) {
    struct kk_std_core_Cons* _con24699 = kk_std_core__as_Cons(xs);
    kk_box_t x = _con24699->head;
    kk_std_core__list _pat0 = _con24699->tail;
    if (kk_std_core__list_is_unique(xs)) {
      kk_std_core__list_drop(_pat0, _ctx);
      kk_std_core__list_free(xs);
    }
    else {
      kk_box_dup(x);
      kk_std_core__list_decref(xs, _ctx);
    }
    return kk_std_core_types__new_Just(x, _ctx);
  }
  return kk_std_core_types__new_Nothing(_ctx);
}
 
// Return the head of list if the list is not empty, or use `default` otherwise

kk_box_t kk_std_core_head_2(kk_std_core__list xs, kk_box_t default0, kk_context_t* _ctx) { /* forall<a> (xs : list<a>, default : a) -> a */ 
  if (kk_std_core__is_Cons(xs)) {
    struct kk_std_core_Cons* _con24700 = kk_std_core__as_Cons(xs);
    kk_box_t x = _con24700->head;
    kk_std_core__list _pat0 = _con24700->tail;
    if (kk_std_core__list_is_unique(xs)) {
      kk_std_core__list_drop(_pat0, _ctx);
      kk_std_core__list_free(xs);
    }
    else {
      kk_box_dup(x);
      kk_std_core__list_decref(xs, _ctx);
    }
    kk_box_drop(default0, _ctx);
    return x;
  }
  return default0;
}
 
// Return the first character of a string as a string (or the empty string)

kk_string_t kk_std_core_head_3(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> string */ 
  kk_std_core__sslice _x24701;
  kk_std_core__sslice slice0 = kk_std_core_first1(s, _ctx); /*sslice*/;
  bool _match_23493;
  kk_integer_t _x24702;
  kk_std_core_types__optional _x24703 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/
  if (kk_std_core_types__is_Optional(_x24703)) {
    kk_box_t _box_x22822 = _x24703._cons.Optional.value;
    kk_integer_t _n_12425 = kk_integer_unbox(_box_x22822);
    _x24702 = _n_12425; /*int*/
    goto _match24704;
  }
  _x24702 = kk_integer_from_small(1); /*int*/
  _match24704: ;
  _match_23493 = kk_integer_eq(_x24702,(kk_integer_from_small(1)),kk_context()); /*bool*/
  if (_match_23493) {
    _x24701 = slice0; /*sslice*/
  }
  else {
    kk_integer_t _x24706;
    kk_integer_t _x24707;
    kk_std_core_types__optional _x24708 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/
    if (kk_std_core_types__is_Optional(_x24708)) {
      kk_box_t _box_x22823 = _x24708._cons.Optional.value;
      kk_integer_t _n_124250 = kk_integer_unbox(_box_x22823);
      _x24707 = _n_124250; /*int*/
      goto _match24709;
    }
    _x24707 = kk_integer_from_small(1); /*int*/
    _match24709: ;
    _x24706 = kk_integer_sub(_x24707,(kk_integer_from_small(1)),kk_context()); /*int*/
    _x24701 = kk_std_core_extend(slice0, _x24706, _ctx); /*sslice*/
  }
  return kk_std_core_string_3(_x24701, _ctx);
}
extern kk_std_core_types__maybe kk_std_core_head_char_fun24712(kk_function_t _fself, kk_char_t _b_22824, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return kk_std_core_types__new_Just(kk_char_box(_b_22824, _ctx), _ctx);
}

kk_integer_t kk_std_core_index_of_acc(kk_std_core__list xs, kk_function_t pred, kk_integer_t idx, kk_context_t* _ctx) { /* forall<a> (xs : list<a>, pred : (a) -> bool, idx : int) -> int */ 
  kk__tailcall: ;
  if (kk_std_core__is_Nil(xs)) {
    kk_integer_drop(idx, _ctx);
    kk_function_drop(pred, _ctx);
    return kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context());
  }
  struct kk_std_core_Cons* _con24713 = kk_std_core__as_Cons(xs);
  kk_box_t x = _con24713->head;
  kk_std_core__list xx = _con24713->tail;
  if (kk_std_core__list_is_unique(xs)) {
    kk_std_core__list_free(xs);
  }
  else {
    kk_box_dup(x);
    kk_std_core__list_dup(xx);
    kk_std_core__list_decref(xs, _ctx);
  }
  bool _match_23492;
  kk_function_t _x24714 = kk_function_dup(pred); /*(15989) -> bool*/
  _match_23492 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_context_t*), _x24714, (_x24714, x, _ctx)); /*bool*/
  if (_match_23492) {
    kk_function_drop(pred, _ctx);
    kk_std_core__list_drop(xx, _ctx);
    return idx;
  }
  { // tailcall
    kk_integer_t _x24715 = kk_integer_add(idx,(kk_integer_from_small(1)),kk_context()); /*int*/
    xs = xx;
    idx = _x24715;
    goto kk__tailcall;
  }
}
 
// Return the list without its last element.
// Return an empty list for an empty list.

kk_std_core__list kk_std_core__ctail_init(kk_std_core__list xs, kk_std_core_types__ctail _acc, kk_context_t* _ctx) { /* forall<a> (xs : list<a>, ctail<list<a>>) -> list<a> */ 
  kk__tailcall: ;
  if (kk_std_core__is_Cons(xs)) {
    struct kk_std_core_Cons* _con24716 = kk_std_core__as_Cons(xs);
    kk_box_t x = _con24716->head;
    kk_std_core__list xx = _con24716->tail;
    if (kk_std_core__is_Cons(xx)) {
      struct kk_std_core_Cons* _con24717 = kk_std_core__as_Cons(xx);
      if (kk_std_core__list_is_unique(xs)) {
        kk_std_core__list_free(xs);
      }
      else {
        kk_box_dup(x);
        kk_std_core__list_dup(xx);
        kk_std_core__list_decref(xs, _ctx);
      }
      kk_reuse_t _ru_23394;
      kk_std_core__list _x24718 = kk_std_core__list_dup(xx); /*list<16026>*/
      _ru_23394 = kk_std_core__list_dropn_reuse(_x24718, ((int32_t)2), _ctx); /*reuse*/
      kk_std_core__list _ctail_21143 = kk_std_core__list_hole(); /*list<16026>*/;
      kk_std_core__list _ctail_21144 = kk_std_core__new_Cons(_ru_23394, x, _ctail_21143, _ctx); /*list<16026>*/;
      { // tailcall
        kk_std_core_types__ctail _x24719;
        kk_box_t* field_21684 = (kk_box_t*)((&kk_std_core__as_Cons(_ctail_21144)->tail)); /*cfield<list<16026>>*/;
        if (kk_std_core_types__is_CTail(_acc)) {
          kk_box_t _box_x22831 = _acc._cons.CTail._field1;
          kk_box_t* last0 = _acc._cons.CTail._field2;
          kk_std_core__list head0 = kk_std_core__list_unbox(_box_x22831, NULL);
          kk_unit_t __ = kk_Unit;
          *(last0) = kk_std_core__list_box(_ctail_21144, _ctx);
          _x24719 = kk_std_core_types__new_CTail(kk_std_core__list_box(head0, _ctx), field_21684, _ctx); /*ctail<58>*/
          goto _match24720;
        }
        _x24719 = kk_std_core_types__new_CTail(kk_std_core__list_box(_ctail_21144, _ctx), field_21684, _ctx); /*ctail<58>*/
        _match24720: ;
        xs = xx;
        _acc = _x24719;
        goto kk__tailcall;
      }
    }
  }
  kk_std_core__list_drop(xs, _ctx);
  if (kk_std_core_types__is_CTail(_acc)) {
    kk_box_t _box_x22840 = _acc._cons.CTail._field1;
    kk_box_t* last00 = _acc._cons.CTail._field2;
    kk_std_core__list head00 = kk_std_core__list_unbox(_box_x22840, NULL);
    kk_unit_t __0 = kk_Unit;
    *(last00) = kk_std_core__list_box(kk_std_core__new_Nil(_ctx), _ctx);
    return head00;
  }
  return kk_std_core__new_Nil(_ctx);
}
 
// Return the list without its last element.
// Return an empty list for an empty list.

kk_std_core__list kk_std_core_init(kk_std_core__list xs0, kk_context_t* _ctx) { /* forall<a> (xs : list<a>) -> list<a> */ 
  return kk_std_core__ctail_init(xs0, kk_std_core_types__new_CTailNil(_ctx), _ctx);
}
 
// Is the character an ASCII hexa-decimal digit ?

bool kk_std_core_is_hex_digit(kk_char_t c, kk_context_t* _ctx) { /* (c : char) -> bool */ 
  bool _match_23483 = kk_std_core_is_digit(c, _ctx); /*bool*/;
  if (_match_23483) {
    return true;
  }
  bool _match_23484;
  bool _match_23486 = (c >= ('a')); /*bool*/;
  if (_match_23486) {
    _match_23484 = (c <= ('f')); /*bool*/
  }
  else {
    _match_23484 = false; /*bool*/
  }
  if (_match_23484) {
    return true;
  }
  bool _match_23485 = (c >= ('A')); /*bool*/;
  if (_match_23485) {
    return (c <= ('F'));
  }
  return false;
}
 
// Tests if a character is an element of `" \t\n\r"`

bool kk_std_core_is_white(kk_char_t c, kk_context_t* _ctx) { /* (c : char) -> bool */ 
  bool _match_23480 = (c == (' ')); /*bool*/;
  if (_match_23480) {
    return true;
  }
  bool _match_23481 = (c == 0x0009); /*bool*/;
  if (_match_23481) {
    return true;
  }
  bool _match_23482 = (c == 0x000A); /*bool*/;
  if (_match_23482) {
    return true;
  }
  return (c == 0x000D);
}
 
// Return the last element of a list (or `Nothing` for the empty list)

kk_std_core_types__maybe kk_std_core_last(kk_std_core__list xs, kk_context_t* _ctx) { /* forall<a> (xs : list<a>) -> maybe<a> */ 
  kk__tailcall: ;
  if (kk_std_core__is_Cons(xs)) {
    struct kk_std_core_Cons* _con24729 = kk_std_core__as_Cons(xs);
    kk_box_t x = _con24729->head;
    kk_std_core__list _pat0 = _con24729->tail;
    if (kk_std_core__is_Nil(_pat0)) {
      if (kk_std_core__list_is_unique(xs)) {
        if (kk_std_core__list_is_unique(_pat0)) {
          kk_std_core__list_free(_pat0);
        }
        else {
          kk_std_core__list_decref(_pat0, _ctx);
        }
        kk_std_core__list_free(xs);
      }
      else {
        kk_box_dup(x);
        kk_std_core__list_decref(xs, _ctx);
      }
      return kk_std_core_types__new_Just(x, _ctx);
    }
  }
  if (kk_std_core__is_Cons(xs)) {
    struct kk_std_core_Cons* _con24730 = kk_std_core__as_Cons(xs);
    kk_box_t _pat2 = _con24730->head;
    kk_std_core__list xx = _con24730->tail;
    if (kk_std_core__list_is_unique(xs)) {
      kk_box_drop(_pat2, _ctx);
      kk_std_core__list_free(xs);
    }
    else {
      kk_std_core__list_dup(xx);
      kk_std_core__list_decref(xs, _ctx);
    }
    { // tailcall
      xs = xx;
      goto kk__tailcall;
    }
  }
  return kk_std_core_types__new_Nothing(_ctx);
}
 
// Return the last element of a list (or `default` for the empty list)

kk_box_t kk_std_core_last_1(kk_std_core__list xs, kk_box_t default0, kk_context_t* _ctx) { /* forall<a> (xs : list<a>, default : a) -> a */ 
  kk__tailcall: ;
  if (kk_std_core__is_Cons(xs)) {
    struct kk_std_core_Cons* _con24731 = kk_std_core__as_Cons(xs);
    kk_box_t x = _con24731->head;
    kk_std_core__list _pat0 = _con24731->tail;
    if (kk_std_core__is_Nil(_pat0)) {
      if (kk_std_core__list_is_unique(xs)) {
        if (kk_std_core__list_is_unique(_pat0)) {
          kk_std_core__list_free(_pat0);
        }
        else {
          kk_std_core__list_decref(_pat0, _ctx);
        }
        kk_std_core__list_free(xs);
      }
      else {
        kk_box_dup(x);
        kk_std_core__list_decref(xs, _ctx);
      }
      kk_box_drop(default0, _ctx);
      return x;
    }
  }
  if (kk_std_core__is_Cons(xs)) {
    struct kk_std_core_Cons* _con24732 = kk_std_core__as_Cons(xs);
    kk_box_t _pat2 = _con24732->head;
    kk_std_core__list xx = _con24732->tail;
    if (kk_std_core__list_is_unique(xs)) {
      kk_box_drop(_pat2, _ctx);
      kk_std_core__list_free(xs);
    }
    else {
      kk_std_core__list_dup(xx);
      kk_std_core__list_decref(xs, _ctx);
    }
    { // tailcall
      xs = xx;
      goto kk__tailcall;
    }
  }
  return default0;
}
 
// O(`n`). The last `n` (default = `1`) characters in a string

kk_std_core__sslice kk_std_core_last_2(kk_string_t s, kk_std_core_types__optional n, kk_context_t* _ctx) { /* (s : string, n : optional<int>) -> sslice */ 
  kk_std_core__sslice slice0 = kk_std_core_last1(s, _ctx); /*sslice*/;
  bool _match_23479;
  kk_integer_t _x24733;
  if (kk_std_core_types__is_Optional(n)) {
    kk_box_t _box_x22849 = n._cons.Optional.value;
    kk_integer_t _n_16953 = kk_integer_unbox(_box_x22849);
    kk_integer_dup(_n_16953);
    _x24733 = _n_16953; /*int*/
    goto _match24734;
  }
  _x24733 = kk_integer_from_small(1); /*int*/
  _match24734: ;
  _match_23479 = kk_integer_eq(_x24733,(kk_integer_from_small(1)),kk_context()); /*bool*/
  if (_match_23479) {
    kk_std_core_types__optional_drop(n, _ctx);
    return slice0;
  }
  kk_std_core__sslice _x24736;
  kk_integer_t _x24737;
  kk_integer_t _x24738;
  if (kk_std_core_types__is_Optional(n)) {
    kk_box_t _box_x22850 = n._cons.Optional.value;
    kk_integer_t _n_169530 = kk_integer_unbox(_box_x22850);
    kk_integer_dup(_n_169530);
    _x24738 = _n_169530; /*int*/
    goto _match24739;
  }
  _x24738 = kk_integer_from_small(1); /*int*/
  _match24739: ;
  _x24737 = kk_integer_sub((kk_integer_from_small(1)),_x24738,kk_context()); /*int*/
  _x24736 = kk_std_core_advance(slice0, _x24737, _ctx); /*sslice*/
  kk_integer_t _x24741;
  kk_integer_t _x24742;
  if (kk_std_core_types__is_Optional(n)) {
    kk_box_t _box_x22851 = n._cons.Optional.value;
    kk_integer_t _n_169531 = kk_integer_unbox(_box_x22851);
    _x24742 = _n_169531; /*int*/
    goto _match24743;
  }
  _x24742 = kk_integer_from_small(1); /*int*/
  _match24743: ;
  _x24741 = kk_integer_sub(_x24742,(kk_integer_from_small(1)),kk_context()); /*int*/
  return kk_std_core_extend(_x24736, _x24741, _ctx);
}
 
// Take the first `n` elements of a list (or fewer if the list is shorter than `n`)

kk_std_core__list kk_std_core__ctail_take(kk_std_core__list xs, kk_integer_t n, kk_std_core_types__ctail _acc, kk_context_t* _ctx) { /* forall<a> (xs : list<a>, n : int, ctail<list<a>>) -> list<a> */ 
  kk__tailcall: ;
  if (kk_std_core__is_Cons(xs)) {
    struct kk_std_core_Cons* _con24745 = kk_std_core__as_Cons(xs);
    kk_box_t x = _con24745->head;
    kk_std_core__list xx = _con24745->tail;
    kk_integer_t _x24746 = kk_integer_dup(n); /*int*/
    if (kk_integer_gt(_x24746,(kk_integer_from_small(0)),kk_context())) {
      kk_reuse_t _ru_23399 = kk_reuse_null; /*reuse*/;
      if (kk_std_core__list_is_unique(xs)) {
        _ru_23399 = (kk_std_core__list_reuse(xs));
      }
      else {
        kk_box_dup(x);
        kk_std_core__list_dup(xx);
        kk_std_core__list_decref(xs, _ctx);
        _ru_23399 = kk_reuse_null;
      }
      kk_std_core__list _ctail_21145 = kk_std_core__list_hole(); /*list<17137>*/;
      kk_std_core__list _ctail_21146;
      bool _x24747 = _ru_23399!=NULL; /*bool*/
      if (_x24747) {
        struct kk_std_core_Cons* _con24748 = (struct kk_std_core_Cons*)_ru_23399;
        _con24748->tail = _ctail_21145;
        _ctail_21146 = kk_std_core__base_Cons(_con24748); /*list<17137>*/
      }
      else {
        _ctail_21146 = kk_std_core__new_Cons(kk_reuse_null, x, _ctail_21145, _ctx); /*list<17137>*/
      }
      { // tailcall
        kk_integer_t _x24749 = kk_integer_sub(n,(kk_integer_from_small(1)),kk_context()); /*int*/
        kk_std_core_types__ctail _x24750;
        kk_box_t* field_21690 = (kk_box_t*)((&kk_std_core__as_Cons(_ctail_21146)->tail)); /*cfield<list<17137>>*/;
        if (kk_std_core_types__is_CTail(_acc)) {
          kk_box_t _box_x22858 = _acc._cons.CTail._field1;
          kk_box_t* last0 = _acc._cons.CTail._field2;
          kk_std_core__list head0 = kk_std_core__list_unbox(_box_x22858, NULL);
          kk_unit_t __ = kk_Unit;
          *(last0) = kk_std_core__list_box(_ctail_21146, _ctx);
          _x24750 = kk_std_core_types__new_CTail(kk_std_core__list_box(head0, _ctx), field_21690, _ctx); /*ctail<58>*/
          goto _match24751;
        }
        _x24750 = kk_std_core_types__new_CTail(kk_std_core__list_box(_ctail_21146, _ctx), field_21690, _ctx); /*ctail<58>*/
        _match24751: ;
        xs = xx;
        n = _x24749;
        _acc = _x24750;
        goto kk__tailcall;
      }
    }
  }
  kk_integer_drop(n, _ctx);
  kk_std_core__list_drop(xs, _ctx);
  if (kk_std_core_types__is_CTail(_acc)) {
    kk_box_t _box_x22867 = _acc._cons.CTail._field1;
    kk_box_t* last00 = _acc._cons.CTail._field2;
    kk_std_core__list head00 = kk_std_core__list_unbox(_box_x22867, NULL);
    kk_unit_t __0 = kk_Unit;
    *(last00) = kk_std_core__list_box(kk_std_core__new_Nil(_ctx), _ctx);
    return head00;
  }
  return kk_std_core__new_Nil(_ctx);
}
 
// Take the first `n` elements of a list (or fewer if the list is shorter than `n`)

kk_std_core__list kk_std_core_take(kk_std_core__list xs0, kk_integer_t n0, kk_context_t* _ctx) { /* forall<a> (xs : list<a>, n : int) -> list<a> */ 
  return kk_std_core__ctail_take(xs0, n0, kk_std_core_types__new_CTailNil(_ctx), _ctx);
}
 
// split a list at position `n`

kk_std_core_types__tuple2_ kk_std_core_split(kk_std_core__list xs, kk_integer_t n, kk_context_t* _ctx) { /* forall<a> (xs : list<a>, n : int) -> (list<a>, list<a>) */ 
  kk_std_core__list _b_22878_22876;
  kk_std_core__list _x24754 = kk_std_core__list_dup(xs); /*list<17157>*/
  kk_integer_t _x24755 = kk_integer_dup(n); /*int*/
  _b_22878_22876 = kk_std_core_take(_x24754, _x24755, _ctx); /*list<17157>*/
  kk_std_core__list _b_22879_22877 = kk_std_core_drop(xs, n, _ctx); /*list<17157>*/;
  return kk_std_core_types__new_dash__lp__comma__rp_(kk_std_core__list_box(_b_22878_22876, _ctx), kk_std_core__list_box(_b_22879_22877, _ctx), _ctx);
}
 
// Lookup the first element satisfying some predicate


// lift anonymous function
struct kk_std_core_lookup_fun24759__t {
  struct kk_function_s _base;
  kk_function_t pred;
};
static kk_std_core_types__maybe kk_std_core_lookup_fun24759(kk_function_t _fself, kk_box_t _b_22882, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_lookup_fun24759(kk_function_t pred, kk_context_t* _ctx) {
  struct kk_std_core_lookup_fun24759__t* _self = kk_function_alloc_as(struct kk_std_core_lookup_fun24759__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_lookup_fun24759, kk_context());
  _self->pred = pred;
  return &_self->_base;
}

static kk_std_core_types__maybe kk_std_core_lookup_fun24759(kk_function_t _fself, kk_box_t _b_22882, kk_context_t* _ctx) {
  struct kk_std_core_lookup_fun24759__t* _self = kk_function_as(struct kk_std_core_lookup_fun24759__t*, _fself);
  kk_function_t pred = _self->pred; /* (17530) -> bool */
  kk_drop_match(_self, {kk_function_dup(pred);}, {}, _ctx)
  bool _match_23476;
  kk_box_t _x24760;
  kk_std_core_types__tuple2_ _match_23478;
  kk_box_t _x24761 = kk_box_dup(_b_22882); /*13066*/
  _match_23478 = kk_std_core_types__tuple2__unbox(_x24761, _ctx); /*(17530, 17531)*/
  kk_box_t _x = _match_23478.fst;
  kk_box_dup(_x);
  kk_std_core_types__tuple2__drop(_match_23478, _ctx);
  _x24760 = _x; /*17530*/
  _match_23476 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_context_t*), pred, (pred, _x24760, _ctx)); /*bool*/
  if (_match_23476) {
    kk_box_t _x24762;
    kk_std_core_types__tuple2_ _match_23477 = kk_std_core_types__tuple2__unbox(_b_22882, _ctx); /*(17530, 17531)*/;
    kk_box_t _x0 = _match_23477.snd;
    kk_box_dup(_x0);
    kk_std_core_types__tuple2__drop(_match_23477, _ctx);
    _x24762 = _x0; /*17531*/
    return kk_std_core_types__new_Just(_x24762, _ctx);
  }
  kk_box_drop(_b_22882, _ctx);
  return kk_std_core_types__new_Nothing(_ctx);
}

kk_std_core_types__maybe kk_std_core_lookup(kk_std_core__list xs, kk_function_t pred, kk_context_t* _ctx) { /* forall<a,b> (xs : list<(a, b)>, pred : (a) -> bool) -> maybe<b> */ 
  return kk_std_core_foreach_while(xs, kk_std_core_new_lookup_fun24759(pred, _ctx), _ctx);
}
 
// monadic lift

kk_std_core__list kk_std_core__mlift21214_op(kk_box_t _y_192, kk_std_core__list _y_193, kk_context_t* _ctx) { /* forall<a,e> (a, list<a>) -> e list<a> */ 
  return kk_std_core__new_Cons(kk_reuse_null, _y_192, _y_193, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_core__mlift21215_op_fun24764__t {
  struct kk_function_s _base;
  kk_box_t _y_1920;
};
static kk_box_t kk_std_core__mlift21215_op_fun24764(kk_function_t _fself, kk_box_t _b_22887, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_mlift21215_op_fun24764(kk_box_t _y_1920, kk_context_t* _ctx) {
  struct kk_std_core__mlift21215_op_fun24764__t* _self = kk_function_alloc_as(struct kk_std_core__mlift21215_op_fun24764__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__mlift21215_op_fun24764, kk_context());
  _self->_y_1920 = _y_1920;
  return &_self->_base;
}

static kk_box_t kk_std_core__mlift21215_op_fun24764(kk_function_t _fself, kk_box_t _b_22887, kk_context_t* _ctx) {
  struct kk_std_core__mlift21215_op_fun24764__t* _self = kk_function_as(struct kk_std_core__mlift21215_op_fun24764__t*, _fself);
  kk_box_t _y_1920 = _self->_y_1920; /* 17533 */
  kk_drop_match(_self, {kk_box_dup(_y_1920);}, {}, _ctx)
  kk_std_core__list _x24765;
  kk_std_core__list _x24766 = kk_std_core__list_unbox(_b_22887, _ctx); /*list<17533>*/
  _x24765 = kk_std_core__mlift21214_op(_y_1920, _x24766, _ctx); /*list<17533>*/
  return kk_std_core__list_box(_x24765, _ctx);
}

kk_std_core__list kk_std_core__mlift21215_op(kk_function_t f, kk_integer_t i, kk_std_core__list yy, kk_box_t _y_1920, kk_context_t* _ctx) { /* forall<a,b,e> (f : (idx : int, value : a) -> e b, i : int, yy : list<a>, b) -> e list<b> */ 
  kk_integer_t i0_21090 = kk_integer_add(i,(kk_integer_from_small(1)),kk_context()); /*int*/;
  kk_std_core__list x_21700 = kk_std_core__lift21058_map_indexed(f, yy, i0_21090, _ctx); /*list<17533>*/;
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_21700, _ctx);
    kk_box_t _x24763 = kk_std_core_hnd_yield_extend(kk_std_core__new_mlift21215_op_fun24764(_y_1920, _ctx), _ctx); /*3991*/
    return kk_std_core__list_unbox(_x24763, _ctx);
  }
  return kk_std_core__mlift21214_op(_y_1920, x_21700, _ctx);
}
 
// lift


// lift anonymous function
struct kk_std_core__lift21058_map_indexed_fun24771__t {
  struct kk_function_s _base;
  kk_function_t f0;
  kk_integer_t i0;
  kk_std_core__list yy0;
};
static kk_box_t kk_std_core__lift21058_map_indexed_fun24771(kk_function_t _fself, kk_box_t _b_22891, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_lift21058_map_indexed_fun24771(kk_function_t f0, kk_integer_t i0, kk_std_core__list yy0, kk_context_t* _ctx) {
  struct kk_std_core__lift21058_map_indexed_fun24771__t* _self = kk_function_alloc_as(struct kk_std_core__lift21058_map_indexed_fun24771__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__lift21058_map_indexed_fun24771, kk_context());
  _self->f0 = f0;
  _self->i0 = i0;
  _self->yy0 = yy0;
  return &_self->_base;
}

static kk_box_t kk_std_core__lift21058_map_indexed_fun24771(kk_function_t _fself, kk_box_t _b_22891, kk_context_t* _ctx) {
  struct kk_std_core__lift21058_map_indexed_fun24771__t* _self = kk_function_as(struct kk_std_core__lift21058_map_indexed_fun24771__t*, _fself);
  kk_function_t f0 = _self->f0; /* (idx : int, value : 17532) -> 17534 17533 */
  kk_integer_t i0 = _self->i0; /* int */
  kk_std_core__list yy0 = _self->yy0; /* list<17532> */
  kk_drop_match(_self, {kk_function_dup(f0);kk_integer_dup(i0);kk_std_core__list_dup(yy0);}, {}, _ctx)
  kk_std_core__list _x24772 = kk_std_core__mlift21215_op(f0, i0, yy0, _b_22891, _ctx); /*list<17533>*/
  return kk_std_core__list_box(_x24772, _ctx);
}


// lift anonymous function
struct kk_std_core__lift21058_map_indexed_fun24774__t {
  struct kk_function_s _base;
  kk_box_t x_21702;
};
static kk_box_t kk_std_core__lift21058_map_indexed_fun24774(kk_function_t _fself, kk_box_t _b_22893, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_lift21058_map_indexed_fun24774(kk_box_t x_21702, kk_context_t* _ctx) {
  struct kk_std_core__lift21058_map_indexed_fun24774__t* _self = kk_function_alloc_as(struct kk_std_core__lift21058_map_indexed_fun24774__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__lift21058_map_indexed_fun24774, kk_context());
  _self->x_21702 = x_21702;
  return &_self->_base;
}

static kk_box_t kk_std_core__lift21058_map_indexed_fun24774(kk_function_t _fself, kk_box_t _b_22893, kk_context_t* _ctx) {
  struct kk_std_core__lift21058_map_indexed_fun24774__t* _self = kk_function_as(struct kk_std_core__lift21058_map_indexed_fun24774__t*, _fself);
  kk_box_t x_21702 = _self->x_21702; /* 17533 */
  kk_drop_match(_self, {kk_box_dup(x_21702);}, {}, _ctx)
  kk_std_core__list _x24775;
  kk_std_core__list _x24776 = kk_std_core__list_unbox(_b_22893, _ctx); /*list<17533>*/
  _x24775 = kk_std_core__mlift21214_op(x_21702, _x24776, _ctx); /*list<17533>*/
  return kk_std_core__list_box(_x24775, _ctx);
}

kk_std_core__list kk_std_core__lift21058_map_indexed(kk_function_t f0, kk_std_core__list ys, kk_integer_t i0, kk_context_t* _ctx) { /* forall<a,b,e> (f : (idx : int, value : a) -> e b, ys : list<a>, i : int) -> e list<b> */ 
  if (kk_std_core__is_Cons(ys)) {
    struct kk_std_core_Cons* _con24767 = kk_std_core__as_Cons(ys);
    kk_box_t y = _con24767->head;
    kk_std_core__list yy0 = _con24767->tail;
    kk_reuse_t _ru_23400 = kk_reuse_null; /*reuse*/;
    if (kk_std_core__list_is_unique(ys)) {
      _ru_23400 = (kk_std_core__list_reuse(ys));
    }
    else {
      kk_box_dup(y);
      kk_std_core__list_dup(yy0);
      kk_std_core__list_decref(ys, _ctx);
      _ru_23400 = kk_reuse_null;
    }
    kk_box_t x_21702;
    kk_function_t _x24769 = kk_function_dup(f0); /*(idx : int, value : 17532) -> 17534 17533*/
    kk_integer_t _x24768 = kk_integer_dup(i0); /*int*/
    x_21702 = kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_box_t, kk_context_t*), _x24769, (_x24769, _x24768, y, _ctx)); /*17533*/
    if (kk_yielding(kk_context())) {
      kk_reuse_drop(_ru_23400, _ctx);
      kk_box_drop(x_21702, _ctx);
      kk_box_t _x24770 = kk_std_core_hnd_yield_extend(kk_std_core__new_lift21058_map_indexed_fun24771(f0, i0, yy0, _ctx), _ctx); /*3991*/
      return kk_std_core__list_unbox(_x24770, _ctx);
    }
    kk_integer_t i0_210900 = kk_integer_add(i0,(kk_integer_from_small(1)),kk_context()); /*int*/;
    kk_std_core__list x0_21706 = kk_std_core__lift21058_map_indexed(f0, yy0, i0_210900, _ctx); /*list<17533>*/;
    if (kk_yielding(kk_context())) {
      kk_reuse_drop(_ru_23400, _ctx);
      kk_std_core__list_drop(x0_21706, _ctx);
      kk_box_t _x24773 = kk_std_core_hnd_yield_extend(kk_std_core__new_lift21058_map_indexed_fun24774(x_21702, _ctx), _ctx); /*3991*/
      return kk_std_core__list_unbox(_x24773, _ctx);
    }
    return kk_std_core__new_Cons(_ru_23400, x_21702, x0_21706, _ctx);
  }
  kk_function_drop(f0, _ctx);
  kk_integer_drop(i0, _ctx);
  return kk_std_core__new_Nil(_ctx);
}
 
// monadic lift

kk_std_core__list kk_std_core__mlift21216_op(kk_box_t _y_196, kk_std_core__list _y_197, kk_context_t* _ctx) { /* forall<a,e> (a, list<a>) -> e list<a> */ 
  return kk_std_core__new_Cons(kk_reuse_null, _y_196, _y_197, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_core__mlift21217_op_fun24778__t {
  struct kk_function_s _base;
  kk_box_t _y_1960;
};
static kk_box_t kk_std_core__mlift21217_op_fun24778(kk_function_t _fself, kk_box_t _b_22899, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_mlift21217_op_fun24778(kk_box_t _y_1960, kk_context_t* _ctx) {
  struct kk_std_core__mlift21217_op_fun24778__t* _self = kk_function_alloc_as(struct kk_std_core__mlift21217_op_fun24778__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__mlift21217_op_fun24778, kk_context());
  _self->_y_1960 = _y_1960;
  return &_self->_base;
}

static kk_box_t kk_std_core__mlift21217_op_fun24778(kk_function_t _fself, kk_box_t _b_22899, kk_context_t* _ctx) {
  struct kk_std_core__mlift21217_op_fun24778__t* _self = kk_function_as(struct kk_std_core__mlift21217_op_fun24778__t*, _fself);
  kk_box_t _y_1960 = _self->_y_1960; /* 17604 */
  kk_drop_match(_self, {kk_box_dup(_y_1960);}, {}, _ctx)
  kk_std_core__list _x24779;
  kk_std_core__list _x24780 = kk_std_core__list_unbox(_b_22899, _ctx); /*list<17604>*/
  _x24779 = kk_std_core__mlift21216_op(_y_1960, _x24780, _ctx); /*list<17604>*/
  return kk_std_core__list_box(_x24779, _ctx);
}

kk_std_core__list kk_std_core__mlift21217_op(kk_function_t f, kk_integer_t i, kk_std_core__list yy, kk_box_t _y_1960, kk_context_t* _ctx) { /* forall<a,b,e> (f : (idx : int, value : a, rest : list<a>) -> e b, i : int, yy : list<a>, b) -> e list<b> */ 
  kk_integer_t i0_21094 = kk_integer_add(i,(kk_integer_from_small(1)),kk_context()); /*int*/;
  kk_std_core__list x_21710 = kk_std_core__lift21059_map_indexed_peek(f, yy, i0_21094, _ctx); /*list<17604>*/;
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_21710, _ctx);
    kk_box_t _x24777 = kk_std_core_hnd_yield_extend(kk_std_core__new_mlift21217_op_fun24778(_y_1960, _ctx), _ctx); /*3991*/
    return kk_std_core__list_unbox(_x24777, _ctx);
  }
  return kk_std_core__mlift21216_op(_y_1960, x_21710, _ctx);
}
 
// lift


// lift anonymous function
struct kk_std_core__lift21059_map_indexed_peek_fun24786__t {
  struct kk_function_s _base;
  kk_function_t f0;
  kk_integer_t i0;
  kk_std_core__list yy0;
};
static kk_box_t kk_std_core__lift21059_map_indexed_peek_fun24786(kk_function_t _fself, kk_box_t _b_22903, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_lift21059_map_indexed_peek_fun24786(kk_function_t f0, kk_integer_t i0, kk_std_core__list yy0, kk_context_t* _ctx) {
  struct kk_std_core__lift21059_map_indexed_peek_fun24786__t* _self = kk_function_alloc_as(struct kk_std_core__lift21059_map_indexed_peek_fun24786__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__lift21059_map_indexed_peek_fun24786, kk_context());
  _self->f0 = f0;
  _self->i0 = i0;
  _self->yy0 = yy0;
  return &_self->_base;
}

static kk_box_t kk_std_core__lift21059_map_indexed_peek_fun24786(kk_function_t _fself, kk_box_t _b_22903, kk_context_t* _ctx) {
  struct kk_std_core__lift21059_map_indexed_peek_fun24786__t* _self = kk_function_as(struct kk_std_core__lift21059_map_indexed_peek_fun24786__t*, _fself);
  kk_function_t f0 = _self->f0; /* (idx : int, value : 17603, rest : list<17603>) -> 17605 17604 */
  kk_integer_t i0 = _self->i0; /* int */
  kk_std_core__list yy0 = _self->yy0; /* list<17603> */
  kk_drop_match(_self, {kk_function_dup(f0);kk_integer_dup(i0);kk_std_core__list_dup(yy0);}, {}, _ctx)
  kk_std_core__list _x24787 = kk_std_core__mlift21217_op(f0, i0, yy0, _b_22903, _ctx); /*list<17604>*/
  return kk_std_core__list_box(_x24787, _ctx);
}


// lift anonymous function
struct kk_std_core__lift21059_map_indexed_peek_fun24789__t {
  struct kk_function_s _base;
  kk_box_t x_21712;
};
static kk_box_t kk_std_core__lift21059_map_indexed_peek_fun24789(kk_function_t _fself, kk_box_t _b_22905, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_lift21059_map_indexed_peek_fun24789(kk_box_t x_21712, kk_context_t* _ctx) {
  struct kk_std_core__lift21059_map_indexed_peek_fun24789__t* _self = kk_function_alloc_as(struct kk_std_core__lift21059_map_indexed_peek_fun24789__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__lift21059_map_indexed_peek_fun24789, kk_context());
  _self->x_21712 = x_21712;
  return &_self->_base;
}

static kk_box_t kk_std_core__lift21059_map_indexed_peek_fun24789(kk_function_t _fself, kk_box_t _b_22905, kk_context_t* _ctx) {
  struct kk_std_core__lift21059_map_indexed_peek_fun24789__t* _self = kk_function_as(struct kk_std_core__lift21059_map_indexed_peek_fun24789__t*, _fself);
  kk_box_t x_21712 = _self->x_21712; /* 17604 */
  kk_drop_match(_self, {kk_box_dup(x_21712);}, {}, _ctx)
  kk_std_core__list _x24790;
  kk_std_core__list _x24791 = kk_std_core__list_unbox(_b_22905, _ctx); /*list<17604>*/
  _x24790 = kk_std_core__mlift21216_op(x_21712, _x24791, _ctx); /*list<17604>*/
  return kk_std_core__list_box(_x24790, _ctx);
}

kk_std_core__list kk_std_core__lift21059_map_indexed_peek(kk_function_t f0, kk_std_core__list ys, kk_integer_t i0, kk_context_t* _ctx) { /* forall<a,b,e> (f : (idx : int, value : a, rest : list<a>) -> e b, ys : list<a>, i : int) -> e list<b> */ 
  if (kk_std_core__is_Cons(ys)) {
    struct kk_std_core_Cons* _con24781 = kk_std_core__as_Cons(ys);
    kk_box_t y = _con24781->head;
    kk_std_core__list yy0 = _con24781->tail;
    kk_reuse_t _ru_23401 = kk_reuse_null; /*reuse*/;
    if (kk_std_core__list_is_unique(ys)) {
      _ru_23401 = (kk_std_core__list_reuse(ys));
    }
    else {
      kk_box_dup(y);
      kk_std_core__list_dup(yy0);
      kk_std_core__list_decref(ys, _ctx);
      _ru_23401 = kk_reuse_null;
    }
    kk_box_t x_21712;
    kk_function_t _x24784 = kk_function_dup(f0); /*(idx : int, value : 17603, rest : list<17603>) -> 17605 17604*/
    kk_integer_t _x24782 = kk_integer_dup(i0); /*int*/
    kk_std_core__list _x24783 = kk_std_core__list_dup(yy0); /*list<17603>*/
    x_21712 = kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_box_t, kk_std_core__list, kk_context_t*), _x24784, (_x24784, _x24782, y, _x24783, _ctx)); /*17604*/
    if (kk_yielding(kk_context())) {
      kk_reuse_drop(_ru_23401, _ctx);
      kk_box_drop(x_21712, _ctx);
      kk_box_t _x24785 = kk_std_core_hnd_yield_extend(kk_std_core__new_lift21059_map_indexed_peek_fun24786(f0, i0, yy0, _ctx), _ctx); /*3991*/
      return kk_std_core__list_unbox(_x24785, _ctx);
    }
    kk_integer_t i0_210940 = kk_integer_add(i0,(kk_integer_from_small(1)),kk_context()); /*int*/;
    kk_std_core__list x0_21716 = kk_std_core__lift21059_map_indexed_peek(f0, yy0, i0_210940, _ctx); /*list<17604>*/;
    if (kk_yielding(kk_context())) {
      kk_reuse_drop(_ru_23401, _ctx);
      kk_std_core__list_drop(x0_21716, _ctx);
      kk_box_t _x24788 = kk_std_core_hnd_yield_extend(kk_std_core__new_lift21059_map_indexed_peek_fun24789(x_21712, _ctx), _ctx); /*3991*/
      return kk_std_core__list_unbox(_x24788, _ctx);
    }
    return kk_std_core__new_Cons(_ru_23401, x_21712, x0_21716, _ctx);
  }
  kk_function_drop(f0, _ctx);
  kk_integer_drop(i0, _ctx);
  return kk_std_core__new_Nil(_ctx);
}
 
// monadic lift

kk_std_core__list kk_std_core__mlift21218_op(kk_std_core_types__ctail _acc, kk_function_t action, kk_std_core__list xx, kk_std_core_types__maybe _y_200, kk_context_t* _ctx) { /* forall<a,b,e> (ctail<list<b>>, action : (a) -> e maybe<b>, xx : list<a>, maybe<b>) -> e list<b> */ 
  if (kk_std_core_types__is_Just(_y_200)) {
    kk_box_t y = _y_200._cons.Just.value;
    kk_std_core__list _ctail_21147 = kk_std_core__list_hole(); /*list<17715>*/;
    kk_std_core__list _ctail_21148 = kk_std_core__new_Cons(kk_reuse_null, y, _ctail_21147, _ctx); /*list<17715>*/;
    kk_std_core_types__ctail _x24792;
    kk_box_t* field_21722 = (kk_box_t*)((&kk_std_core__as_Cons(_ctail_21148)->tail)); /*cfield<list<17715>>*/;
    if (kk_std_core_types__is_CTail(_acc)) {
      kk_box_t _box_x22916 = _acc._cons.CTail._field1;
      kk_box_t* last0 = _acc._cons.CTail._field2;
      kk_std_core__list head0 = kk_std_core__list_unbox(_box_x22916, NULL);
      kk_unit_t __ = kk_Unit;
      *(last0) = kk_std_core__list_box(_ctail_21148, _ctx);
      _x24792 = kk_std_core_types__new_CTail(kk_std_core__list_box(head0, _ctx), field_21722, _ctx); /*ctail<58>*/
      goto _match24793;
    }
    _x24792 = kk_std_core_types__new_CTail(kk_std_core__list_box(_ctail_21148, _ctx), field_21722, _ctx); /*ctail<58>*/
    _match24793: ;
    return kk_std_core__ctail_map_while(xx, action, _x24792, _ctx);
  }
  kk_function_drop(action, _ctx);
  kk_std_core__list_drop(xx, _ctx);
  if (kk_std_core_types__is_CTail(_acc)) {
    kk_box_t _box_x22925 = _acc._cons.CTail._field1;
    kk_box_t* last00 = _acc._cons.CTail._field2;
    kk_std_core__list head00 = kk_std_core__list_unbox(_box_x22925, NULL);
    kk_unit_t __0 = kk_Unit;
    *(last00) = kk_std_core__list_box(kk_std_core__new_Nil(_ctx), _ctx);
    return head00;
  }
  return kk_std_core__new_Nil(_ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_core__mlift21219_op_fun24796__t {
  struct kk_function_s _base;
  kk_function_t _accm;
  kk_box_t y0;
};
static kk_std_core__list kk_std_core__mlift21219_op_fun24796(kk_function_t _fself, kk_std_core__list _ctail_21150, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_mlift21219_op_fun24796(kk_function_t _accm, kk_box_t y0, kk_context_t* _ctx) {
  struct kk_std_core__mlift21219_op_fun24796__t* _self = kk_function_alloc_as(struct kk_std_core__mlift21219_op_fun24796__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__mlift21219_op_fun24796, kk_context());
  _self->_accm = _accm;
  _self->y0 = y0;
  return &_self->_base;
}

static kk_std_core__list kk_std_core__mlift21219_op_fun24796(kk_function_t _fself, kk_std_core__list _ctail_21150, kk_context_t* _ctx) {
  struct kk_std_core__mlift21219_op_fun24796__t* _self = kk_function_as(struct kk_std_core__mlift21219_op_fun24796__t*, _fself);
  kk_function_t _accm = _self->_accm; /* (list<17715>) -> list<17715> */
  kk_box_t y0 = _self->y0; /* 17715 */
  kk_drop_match(_self, {kk_function_dup(_accm);kk_box_dup(y0);}, {}, _ctx)
  kk_std_core__list _x24797 = kk_std_core__new_Cons(kk_reuse_null, y0, _ctail_21150, _ctx); /*list<61>*/
  return kk_function_call(kk_std_core__list, (kk_function_t, kk_std_core__list, kk_context_t*), _accm, (_accm, _x24797, _ctx));
}

kk_std_core__list kk_std_core__mlift21219_op(kk_function_t _accm, kk_function_t action0, kk_std_core__list xx0, kk_std_core_types__maybe _y_204, kk_context_t* _ctx) { /* forall<a,b,e> ((list<b>) -> list<b>, action : (a) -> e maybe<b>, xx : list<a>, maybe<b>) -> e list<b> */ 
  if (kk_std_core_types__is_Just(_y_204)) {
    kk_box_t y0 = _y_204._cons.Just.value;
    return kk_std_core__ctailm_map_while(xx0, action0, kk_std_core__new_mlift21219_op_fun24796(_accm, y0, _ctx), _ctx);
  }
  kk_function_drop(action0, _ctx);
  kk_std_core__list_drop(xx0, _ctx);
  return kk_function_call(kk_std_core__list, (kk_function_t, kk_std_core__list, kk_context_t*), _accm, (_accm, kk_std_core__new_Nil(_ctx), _ctx));
}
 
// Invoke `action` on each element of a list while `action` returns `Just`


// lift anonymous function
struct kk_std_core__ctail_map_while_fun24802__t {
  struct kk_function_s _base;
  kk_function_t action1;
  kk_std_core__list xx1;
  kk_std_core_types__ctail _acc0;
};
static kk_box_t kk_std_core__ctail_map_while_fun24802(kk_function_t _fself, kk_box_t _b_22940, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_ctail_map_while_fun24802(kk_function_t action1, kk_std_core__list xx1, kk_std_core_types__ctail _acc0, kk_context_t* _ctx) {
  struct kk_std_core__ctail_map_while_fun24802__t* _self = kk_function_alloc_as(struct kk_std_core__ctail_map_while_fun24802__t, 5, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__ctail_map_while_fun24802, kk_context());
  _self->action1 = action1;
  _self->xx1 = xx1;
  _self->_acc0 = _acc0;
  return &_self->_base;
}

static kk_box_t kk_std_core__ctail_map_while_fun24802(kk_function_t _fself, kk_box_t _b_22940, kk_context_t* _ctx) {
  struct kk_std_core__ctail_map_while_fun24802__t* _self = kk_function_as(struct kk_std_core__ctail_map_while_fun24802__t*, _fself);
  kk_function_t action1 = _self->action1; /* (17714) -> 17716 maybe<17715> */
  kk_std_core__list xx1 = _self->xx1; /* list<17714> */
  kk_std_core_types__ctail _acc0 = _self->_acc0; /* ctail<list<17715>> */
  kk_drop_match(_self, {kk_function_dup(action1);kk_std_core__list_dup(xx1);kk_std_core_types__ctail_dup(_acc0);}, {}, _ctx)
  kk_std_core__list _x24803;
  kk_std_core_types__maybe _x24804 = kk_std_core_types__maybe_unbox(_b_22940, _ctx); /*maybe<17715>*/
  _x24803 = kk_std_core__mlift21218_op(_acc0, action1, xx1, _x24804, _ctx); /*list<17715>*/
  return kk_std_core__list_box(_x24803, _ctx);
}

kk_std_core__list kk_std_core__ctail_map_while(kk_std_core__list xs, kk_function_t action1, kk_std_core_types__ctail _acc0, kk_context_t* _ctx) { /* forall<a,b,e> (xs : list<a>, action : (a) -> e maybe<b>, ctail<list<b>>) -> e list<b> */ 
  kk__tailcall: ;
  if (kk_std_core__is_Nil(xs)) {
    kk_function_drop(action1, _ctx);
    if (kk_std_core_types__is_CTail(_acc0)) {
      kk_box_t _box_x22934 = _acc0._cons.CTail._field1;
      kk_box_t* last2 = _acc0._cons.CTail._field2;
      kk_std_core__list head1 = kk_std_core__list_unbox(_box_x22934, NULL);
      kk_unit_t __1 = kk_Unit;
      *(last2) = kk_std_core__list_box(kk_std_core__new_Nil(_ctx), _ctx);
      return head1;
    }
    return kk_std_core__new_Nil(_ctx);
  }
  struct kk_std_core_Cons* _con24799 = kk_std_core__as_Cons(xs);
  kk_box_t x = _con24799->head;
  kk_std_core__list xx1 = _con24799->tail;
  kk_reuse_t _ru_23402 = kk_reuse_null; /*reuse*/;
  if (kk_std_core__list_is_unique(xs)) {
    _ru_23402 = (kk_std_core__list_reuse(xs));
  }
  else {
    kk_box_dup(x);
    kk_std_core__list_dup(xx1);
    kk_std_core__list_decref(xs, _ctx);
    _ru_23402 = kk_reuse_null;
  }
  kk_std_core_types__maybe x0_21727;
  kk_function_t _x24800 = kk_function_dup(action1); /*(17714) -> 17716 maybe<17715>*/
  x0_21727 = kk_function_call(kk_std_core_types__maybe, (kk_function_t, kk_box_t, kk_context_t*), _x24800, (_x24800, x, _ctx)); /*maybe<17715>*/
  if (kk_yielding(kk_context())) {
    kk_reuse_drop(_ru_23402, _ctx);
    kk_std_core_types__maybe_drop(x0_21727, _ctx);
    kk_box_t _x24801 = kk_std_core_hnd_yield_extend(kk_std_core__new_ctail_map_while_fun24802(action1, xx1, _acc0, _ctx), _ctx); /*3991*/
    return kk_std_core__list_unbox(_x24801, _ctx);
  }
  if (kk_std_core_types__is_Just(x0_21727)) {
    kk_box_t y1 = x0_21727._cons.Just.value;
    kk_std_core__list _ctail_211470 = kk_std_core__list_hole(); /*list<17715>*/;
    kk_std_core__list _ctail_211480 = kk_std_core__new_Cons(_ru_23402, y1, _ctail_211470, _ctx); /*list<17715>*/;
    { // tailcall
      kk_std_core_types__ctail _x24805;
      kk_box_t* field_21733 = (kk_box_t*)((&kk_std_core__as_Cons(_ctail_211480)->tail)); /*cfield<list<17715>>*/;
      if (kk_std_core_types__is_CTail(_acc0)) {
        kk_box_t _box_x22947 = _acc0._cons.CTail._field1;
        kk_box_t* last01 = _acc0._cons.CTail._field2;
        kk_std_core__list head01 = kk_std_core__list_unbox(_box_x22947, NULL);
        kk_unit_t __00 = kk_Unit;
        *(last01) = kk_std_core__list_box(_ctail_211480, _ctx);
        _x24805 = kk_std_core_types__new_CTail(kk_std_core__list_box(head01, _ctx), field_21733, _ctx); /*ctail<58>*/
        goto _match24806;
      }
      _x24805 = kk_std_core_types__new_CTail(kk_std_core__list_box(_ctail_211480, _ctx), field_21733, _ctx); /*ctail<58>*/
      _match24806: ;
      xs = xx1;
      _acc0 = _x24805;
      goto kk__tailcall;
    }
  }
  kk_reuse_drop(_ru_23402, _ctx);
  kk_function_drop(action1, _ctx);
  kk_std_core__list_drop(xx1, _ctx);
  if (kk_std_core_types__is_CTail(_acc0)) {
    kk_box_t _box_x22956 = _acc0._cons.CTail._field1;
    kk_box_t* last10 = _acc0._cons.CTail._field2;
    kk_std_core__list head10 = kk_std_core__list_unbox(_box_x22956, NULL);
    kk_unit_t __10 = kk_Unit;
    *(last10) = kk_std_core__list_box(kk_std_core__new_Nil(_ctx), _ctx);
    return head10;
  }
  return kk_std_core__new_Nil(_ctx);
}
 
// Invoke `action` on each element of a list while `action` returns `Just`


// lift anonymous function
struct kk_std_core__ctailm_map_while_fun24812__t {
  struct kk_function_s _base;
  kk_function_t _accm0;
  kk_function_t action2;
  kk_std_core__list xx2;
};
static kk_box_t kk_std_core__ctailm_map_while_fun24812(kk_function_t _fself, kk_box_t _b_22968, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_ctailm_map_while_fun24812(kk_function_t _accm0, kk_function_t action2, kk_std_core__list xx2, kk_context_t* _ctx) {
  struct kk_std_core__ctailm_map_while_fun24812__t* _self = kk_function_alloc_as(struct kk_std_core__ctailm_map_while_fun24812__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__ctailm_map_while_fun24812, kk_context());
  _self->_accm0 = _accm0;
  _self->action2 = action2;
  _self->xx2 = xx2;
  return &_self->_base;
}

static kk_box_t kk_std_core__ctailm_map_while_fun24812(kk_function_t _fself, kk_box_t _b_22968, kk_context_t* _ctx) {
  struct kk_std_core__ctailm_map_while_fun24812__t* _self = kk_function_as(struct kk_std_core__ctailm_map_while_fun24812__t*, _fself);
  kk_function_t _accm0 = _self->_accm0; /* (list<17715>) -> list<17715> */
  kk_function_t action2 = _self->action2; /* (17714) -> 17716 maybe<17715> */
  kk_std_core__list xx2 = _self->xx2; /* list<17714> */
  kk_drop_match(_self, {kk_function_dup(_accm0);kk_function_dup(action2);kk_std_core__list_dup(xx2);}, {}, _ctx)
  kk_std_core__list _x24813;
  kk_std_core_types__maybe _x24814 = kk_std_core_types__maybe_unbox(_b_22968, _ctx); /*maybe<17715>*/
  _x24813 = kk_std_core__mlift21219_op(_accm0, action2, xx2, _x24814, _ctx); /*list<17715>*/
  return kk_std_core__list_box(_x24813, _ctx);
}


// lift anonymous function
struct kk_std_core__ctailm_map_while_fun24816__t {
  struct kk_function_s _base;
  kk_function_t _accm0;
  kk_box_t y2;
};
static kk_std_core__list kk_std_core__ctailm_map_while_fun24816(kk_function_t _fself, kk_std_core__list _ctail_211500, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_ctailm_map_while_fun24816(kk_function_t _accm0, kk_box_t y2, kk_context_t* _ctx) {
  struct kk_std_core__ctailm_map_while_fun24816__t* _self = kk_function_alloc_as(struct kk_std_core__ctailm_map_while_fun24816__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__ctailm_map_while_fun24816, kk_context());
  _self->_accm0 = _accm0;
  _self->y2 = y2;
  return &_self->_base;
}

static kk_std_core__list kk_std_core__ctailm_map_while_fun24816(kk_function_t _fself, kk_std_core__list _ctail_211500, kk_context_t* _ctx) {
  struct kk_std_core__ctailm_map_while_fun24816__t* _self = kk_function_as(struct kk_std_core__ctailm_map_while_fun24816__t*, _fself);
  kk_function_t _accm0 = _self->_accm0; /* (list<17715>) -> list<17715> */
  kk_box_t y2 = _self->y2; /* 17715 */
  kk_drop_match(_self, {kk_function_dup(_accm0);kk_box_dup(y2);}, {}, _ctx)
  kk_std_core__list _x24817 = kk_std_core__new_Cons(kk_reuse_null, y2, _ctail_211500, _ctx); /*list<61>*/
  return kk_function_call(kk_std_core__list, (kk_function_t, kk_std_core__list, kk_context_t*), _accm0, (_accm0, _x24817, _ctx));
}

kk_std_core__list kk_std_core__ctailm_map_while(kk_std_core__list xs0, kk_function_t action2, kk_function_t _accm0, kk_context_t* _ctx) { /* forall<a,b,e> (xs : list<a>, action : (a) -> e maybe<b>, (list<b>) -> list<b>) -> e list<b> */ 
  kk__tailcall: ;
  if (kk_std_core__is_Nil(xs0)) {
    kk_function_drop(action2, _ctx);
    return kk_function_call(kk_std_core__list, (kk_function_t, kk_std_core__list, kk_context_t*), _accm0, (_accm0, kk_std_core__new_Nil(_ctx), _ctx));
  }
  struct kk_std_core_Cons* _con24809 = kk_std_core__as_Cons(xs0);
  kk_box_t x0 = _con24809->head;
  kk_std_core__list xx2 = _con24809->tail;
  if (kk_std_core__list_is_unique(xs0)) {
    kk_std_core__list_free(xs0);
  }
  else {
    kk_box_dup(x0);
    kk_std_core__list_dup(xx2);
    kk_std_core__list_decref(xs0, _ctx);
  }
  kk_std_core_types__maybe x0_21736;
  kk_function_t _x24810 = kk_function_dup(action2); /*(17714) -> 17716 maybe<17715>*/
  x0_21736 = kk_function_call(kk_std_core_types__maybe, (kk_function_t, kk_box_t, kk_context_t*), _x24810, (_x24810, x0, _ctx)); /*maybe<17715>*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__maybe_drop(x0_21736, _ctx);
    kk_box_t _x24811 = kk_std_core_hnd_yield_extend(kk_std_core__new_ctailm_map_while_fun24812(_accm0, action2, xx2, _ctx), _ctx); /*3991*/
    return kk_std_core__list_unbox(_x24811, _ctx);
  }
  if (kk_std_core_types__is_Just(x0_21736)) {
    kk_box_t y2 = x0_21736._cons.Just.value;
    { // tailcall
      kk_function_t _x24815 = kk_std_core__new_ctailm_map_while_fun24816(_accm0, y2, _ctx); /*(list<17715>) -> list<17715>*/
      xs0 = xx2;
      _accm0 = _x24815;
      goto kk__tailcall;
    }
  }
  kk_function_drop(action2, _ctx);
  kk_std_core__list_drop(xx2, _ctx);
  return kk_function_call(kk_std_core__list, (kk_function_t, kk_std_core__list, kk_context_t*), _accm0, (_accm0, kk_std_core__new_Nil(_ctx), _ctx));
}
 
// Invoke `action` on each element of a list while `action` returns `Just`


// lift anonymous function
struct kk_std_core_map_while_fun24818__t {
  struct kk_function_s _base;
};
static kk_std_core__list kk_std_core_map_while_fun24818(kk_function_t _fself, kk_std_core__list _ctail_21149, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_map_while_fun24818(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_map_while_fun24818, _ctx)
  return kk_function_dup(_fself);
}

static kk_std_core__list kk_std_core_map_while_fun24818(kk_function_t _fself, kk_std_core__list _ctail_21149, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return _ctail_21149;
}

kk_std_core__list kk_std_core_map_while(kk_std_core__list xs1, kk_function_t action3, kk_context_t* _ctx) { /* forall<a,b,e> (xs : list<a>, action : (a) -> e maybe<b>) -> e list<b> */ 
  bool _match_23467 = kk_std_core_hnd__evv_is_affine(_ctx); /*bool*/;
  if (_match_23467) {
    return kk_std_core__ctail_map_while(xs1, action3, kk_std_core_types__new_CTailNil(_ctx), _ctx);
  }
  return kk_std_core__ctailm_map_while(xs1, action3, kk_std_core_new_map_while_fun24818(_ctx), _ctx);
}
 
// Return the maximum of two integers

kk_integer_t kk_std_core_max(kk_integer_t i, kk_integer_t j, kk_context_t* _ctx) { /* (i : int, j : int) -> int */ 
  bool _match_23466;
  kk_integer_t _x24819 = kk_integer_dup(i); /*int*/
  kk_integer_t _x24820 = kk_integer_dup(j); /*int*/
  _match_23466 = kk_integer_gte(_x24819,_x24820,kk_context()); /*bool*/
  if (_match_23466) {
    kk_integer_drop(j, _ctx);
    return i;
  }
  kk_integer_drop(i, _ctx);
  return j;
}
 
// Returns the largest element of a list of integers (or `default` (=`0`) for the empty list)


// lift anonymous function
struct kk_std_core_maximum_fun24825__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_maximum_fun24825(kk_function_t _fself, kk_box_t _b_22976, kk_box_t _b_22977, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_maximum_fun24825(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_maximum_fun24825, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_core_maximum_fun24825(kk_function_t _fself, kk_box_t _b_22976, kk_box_t _b_22977, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_integer_t _x24826;
  kk_integer_t _x24827 = kk_integer_unbox(_b_22976); /*int*/
  kk_integer_t _x24828 = kk_integer_unbox(_b_22977); /*int*/
  _x24826 = kk_std_core_max(_x24827, _x24828, _ctx); /*int*/
  return kk_integer_box(_x24826);
}

kk_integer_t kk_std_core_maximum(kk_std_core__list xs, kk_std_core_types__optional default0, kk_context_t* _ctx) { /* (xs : list<int>, default : optional<int>) -> int */ 
  if (kk_std_core__is_Nil(xs)) {
    if (kk_std_core_types__is_Optional(default0)) {
      kk_box_t _box_x22971 = default0._cons.Optional.value;
      kk_integer_t _default_17788 = kk_integer_unbox(_box_x22971);
      return _default_17788;
    }
    return kk_integer_from_small(0);
  }
  struct kk_std_core_Cons* _con24822 = kk_std_core__as_Cons(xs);
  kk_box_t _box_x22972 = _con24822->head;
  kk_std_core__list xx = _con24822->tail;
  kk_integer_t x = kk_integer_unbox(_box_x22972);
  if (kk_std_core__list_is_unique(xs)) {
    kk_std_core__list_free(xs);
  }
  else {
    kk_integer_dup(x);
    kk_std_core__list_dup(xx);
    kk_std_core__list_decref(xs, _ctx);
  }
  kk_std_core_types__optional_drop(default0, _ctx);
  kk_box_t _x24824 = kk_std_core_foldl(xx, kk_integer_box(x), kk_std_core_new_maximum_fun24825(_ctx), _ctx); /*15010*/
  return kk_integer_unbox(_x24824);
}
 
// Returns the largest element of a list of doubles (or `0` for the empty list)


// lift anonymous function
struct kk_std_core_maximum_fun24832__t_1 {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_maximum_fun24832_1(kk_function_t _fself, kk_box_t _b_22985, kk_box_t _b_22986, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_maximum_fun24832_1(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_maximum_fun24832_1, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_core_maximum_fun24832_1(kk_function_t _fself, kk_box_t _b_22985, kk_box_t _b_22986, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x24833;
  double _x24834 = kk_double_unbox(_b_22985, _ctx); /*double*/
  double _x24835 = kk_double_unbox(_b_22986, _ctx); /*double*/
  _x24833 = kk_std_core_max_1(_x24834, _x24835, _ctx); /*double*/
  return kk_double_box(_x24833, _ctx);
}

double kk_std_core_maximum_1(kk_std_core__list xs, kk_context_t* _ctx) { /* (xs : list<double>) -> double */ 
  if (kk_std_core__is_Nil(xs)) {
    return 0x0p+0;
  }
  struct kk_std_core_Cons* _con24829 = kk_std_core__as_Cons(xs);
  kk_box_t _box_x22981 = _con24829->head;
  kk_std_core__list xx = _con24829->tail;
  double x = kk_double_unbox(_box_x22981, NULL);
  if (kk_std_core__list_is_unique(xs)) {
    kk_box_drop(_box_x22981, _ctx);
    kk_std_core__list_free(xs);
  }
  else {
    kk_std_core__list_dup(xx);
    kk_std_core__list_decref(xs, _ctx);
  }
  kk_box_t _x24831 = kk_std_core_foldl(xx, kk_double_box(x, _ctx), kk_std_core_new_maximum_fun24832_1(_ctx), _ctx); /*15010*/
  return kk_double_unbox(_x24831, _ctx);
}
 
// Convert a list to a `:maybe` type, using `Nothing` for an empty list, and otherwise `Just` on the head element.
// Note: this is just `head`.

kk_std_core_types__maybe kk_std_core_maybe_3(kk_std_core__list xs, kk_context_t* _ctx) { /* forall<a> (xs : list<a>) -> maybe<a> */ 
  if (kk_std_core__is_Nil(xs)) {
    return kk_std_core_types__new_Nothing(_ctx);
  }
  struct kk_std_core_Cons* _con24838 = kk_std_core__as_Cons(xs);
  kk_box_t x = _con24838->head;
  kk_std_core__list _pat1 = _con24838->tail;
  if (kk_std_core__list_is_unique(xs)) {
    kk_std_core__list_drop(_pat1, _ctx);
    kk_std_core__list_free(xs);
  }
  else {
    kk_box_dup(x);
    kk_std_core__list_decref(xs, _ctx);
  }
  return kk_std_core_types__new_Just(x, _ctx);
}
 
// Transform an integer to a maybe type, using `Nothing` for `0`

kk_std_core_types__maybe kk_std_core_maybe_5(kk_integer_t i, kk_context_t* _ctx) { /* (i : int) -> maybe<int> */ 
  bool _match_23464;
  kk_integer_t _x24839 = kk_integer_dup(i); /*int*/
  _match_23464 = kk_integer_eq(_x24839,(kk_integer_from_small(0)),kk_context()); /*bool*/
  if (_match_23464) {
    kk_integer_drop(i, _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
  return kk_std_core_types__new_Just(kk_integer_box(i), _ctx);
}
 
// Transform a string to a maybe type, using `Nothing` for an empty string

kk_std_core_types__maybe kk_std_core_maybe_6(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> maybe<string> */ 
  bool _match_23463;
  kk_string_t _x24840 = kk_string_dup(s); /*string*/
  _match_23463 = kk_std_core_is_empty_2(_x24840, _ctx); /*bool*/
  if (_match_23463) {
    kk_string_drop(s, _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
  return kk_std_core_types__new_Just(kk_string_box(s), _ctx);
}
 
// Transform a `:null` type to a `:maybe` type. Note that it is not
// always the case that `id(x) == maybe(null(x))` (e.g. when `x = Just(Nothing)`).

kk_std_core_types__maybe kk_std_core_maybe_8(kk_std_core__null n, kk_context_t* _ctx) { /* forall<a> (n : null<a>) -> maybe<a> */ 
  return ((n).ptr == NULL ? kk_std_core_types__new_Nothing(kk_context()) : kk_std_core_types__new_Just(kk_datatype_box(n),kk_context()));
}
 
// Return the minimum of two integers

kk_integer_t kk_std_core_min(kk_integer_t i, kk_integer_t j, kk_context_t* _ctx) { /* (i : int, j : int) -> int */ 
  bool _match_23462;
  kk_integer_t _x24841 = kk_integer_dup(i); /*int*/
  kk_integer_t _x24842 = kk_integer_dup(j); /*int*/
  _match_23462 = kk_integer_lte(_x24841,_x24842,kk_context()); /*bool*/
  if (_match_23462) {
    kk_integer_drop(j, _ctx);
    return i;
  }
  kk_integer_drop(i, _ctx);
  return j;
}
 
// Returns the smallest element of a list of integers (or `default` (=`0`) for the empty list)


// lift anonymous function
struct kk_std_core_minimum_fun24847__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_minimum_fun24847(kk_function_t _fself, kk_box_t _b_23001, kk_box_t _b_23002, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_minimum_fun24847(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_minimum_fun24847, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_core_minimum_fun24847(kk_function_t _fself, kk_box_t _b_23001, kk_box_t _b_23002, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_integer_t _x24848;
  kk_integer_t _x24849 = kk_integer_unbox(_b_23001); /*int*/
  kk_integer_t _x24850 = kk_integer_unbox(_b_23002); /*int*/
  _x24848 = kk_std_core_min(_x24849, _x24850, _ctx); /*int*/
  return kk_integer_box(_x24848);
}

kk_integer_t kk_std_core_minimum(kk_std_core__list xs, kk_std_core_types__optional default0, kk_context_t* _ctx) { /* (xs : list<int>, default : optional<int>) -> int */ 
  if (kk_std_core__is_Nil(xs)) {
    if (kk_std_core_types__is_Optional(default0)) {
      kk_box_t _box_x22996 = default0._cons.Optional.value;
      kk_integer_t _default_18389 = kk_integer_unbox(_box_x22996);
      return _default_18389;
    }
    return kk_integer_from_small(0);
  }
  struct kk_std_core_Cons* _con24844 = kk_std_core__as_Cons(xs);
  kk_box_t _box_x22997 = _con24844->head;
  kk_std_core__list xx = _con24844->tail;
  kk_integer_t x = kk_integer_unbox(_box_x22997);
  if (kk_std_core__list_is_unique(xs)) {
    kk_std_core__list_free(xs);
  }
  else {
    kk_integer_dup(x);
    kk_std_core__list_dup(xx);
    kk_std_core__list_decref(xs, _ctx);
  }
  kk_std_core_types__optional_drop(default0, _ctx);
  kk_box_t _x24846 = kk_std_core_foldl(xx, kk_integer_box(x), kk_std_core_new_minimum_fun24847(_ctx), _ctx); /*15010*/
  return kk_integer_unbox(_x24846);
}
 
// Returns the smallest element of a list of doubles (or `0` for the empty list)


// lift anonymous function
struct kk_std_core_minimum_fun24854__t_1 {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_minimum_fun24854_1(kk_function_t _fself, kk_box_t _b_23010, kk_box_t _b_23011, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_minimum_fun24854_1(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_minimum_fun24854_1, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_core_minimum_fun24854_1(kk_function_t _fself, kk_box_t _b_23010, kk_box_t _b_23011, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x24855;
  double _x24856 = kk_double_unbox(_b_23010, _ctx); /*double*/
  double _x24857 = kk_double_unbox(_b_23011, _ctx); /*double*/
  _x24855 = kk_std_core_min_1(_x24856, _x24857, _ctx); /*double*/
  return kk_double_box(_x24855, _ctx);
}

double kk_std_core_minimum_1(kk_std_core__list xs, kk_context_t* _ctx) { /* (xs : list<double>) -> double */ 
  if (kk_std_core__is_Nil(xs)) {
    return 0x0p+0;
  }
  struct kk_std_core_Cons* _con24851 = kk_std_core__as_Cons(xs);
  kk_box_t _box_x23006 = _con24851->head;
  kk_std_core__list xx = _con24851->tail;
  double x = kk_double_unbox(_box_x23006, NULL);
  if (kk_std_core__list_is_unique(xs)) {
    kk_box_drop(_box_x23006, _ctx);
    kk_std_core__list_free(xs);
  }
  else {
    kk_std_core__list_dup(xx);
    kk_std_core__list_decref(xs, _ctx);
  }
  kk_box_t _x24853 = kk_std_core_foldl(xx, kk_double_box(x, _ctx), kk_std_core_new_minimum_fun24854_1(_ctx), _ctx); /*15010*/
  return kk_double_unbox(_x24853, _ctx);
}
 
// Disable tracing completely.

kk_unit_t kk_std_core_notrace(kk_context_t* _ctx) { /* () -> (st<global>) () */ 
  kk_ref_t _b_23018_23016 = kk_ref_alloc((kk_bool_box(true)),kk_context()); /*ref<global,bool>*/;
  kk_ref_set(_b_23018_23016,(kk_bool_box(false)),kk_context()); return kk_Unit;
}
 
// Transform a `:maybe` type to a `:null` type (using `null` for `Nothing`).

kk_std_core__null kk_std_core_null(kk_std_core_types__maybe x, kk_context_t* _ctx) { /* forall<a> (x : maybe<a>) -> null<a> */ 
  return (kk_std_core_types__is_Nothing(x) ? kk_datatype_from_ptr(NULL) : kk_datatype_unbox((x)._cons.Just.value));
}

kk_std_core__null kk_std_core_null_const;
 
// Left-align a string to width `width`  using `fill`  (default is a space) to fill on the right.

kk_string_t kk_std_core_pad_right(kk_string_t s, kk_integer_t width, kk_std_core_types__optional fill, kk_context_t* _ctx) { /* (s : string, width : int, fill : optional<char>) -> string */ 
  size_t w = kk_std_core_size__t(width, _ctx); /*size_t*/;
  size_t n;
  kk_string_t _x24861 = kk_string_dup(s); /*string*/
  n = kk_string_len(_x24861,kk_context()); /*size_t*/
  bool _match_23460 = (w <= n); /*bool*/;
  if (_match_23460) {
    kk_std_core_types__optional_drop(fill, _ctx);
    return s;
  }
  kk_string_t _x24862;
  kk_string_t _x24863;
  kk_char_t _x24864;
  if (kk_std_core_types__is_Optional(fill)) {
    kk_box_t _box_x23021 = fill._cons.Optional.value;
    kk_char_t _fill_18968 = kk_char_unbox(_box_x23021, NULL);
    _x24864 = _fill_18968; /*char*/
    goto _match24865;
  }
  _x24864 = ' '; /*char*/
  _match24865: ;
  _x24863 = kk_std_core_string(_x24864, _ctx); /*string*/
  size_t _x24867 = (w - n); /*size_t*/
  _x24862 = kk_std_core_repeatz(_x24863, _x24867, _ctx); /*string*/
  return kk_std_core__lp__plus__plus__1_rp_(s, _x24862, _ctx);
}
 
// Is `pre`  a prefix of `s`? If so, returns a slice
// of `s` following `pre` up to the end of `s`.

kk_std_core_types__maybe kk_std_core_starts_with(kk_string_t s, kk_string_t pre, kk_context_t* _ctx) { /* (s : string, pre : string) -> maybe<sslice> */ 
  bool _match_23459;
  kk_string_t _x24868 = kk_string_dup(s); /*string*/
  kk_string_t _x24869 = kk_string_dup(pre); /*string*/
  _match_23459 = kk_string_starts_with(_x24868,_x24869,kk_context()); /*bool*/
  if (_match_23459) {
    kk_std_core__sslice _b_23023_23022;
    kk_string_t _x24870 = kk_string_dup(s); /*string*/
    size_t _x24871;
    kk_string_t _x24872 = kk_string_dup(pre); /*string*/
    _x24871 = kk_string_len(_x24872,kk_context()); /*size_t*/
    size_t _x24873;
    size_t _x24874 = kk_string_len(s,kk_context()); /*size_t*/
    size_t _x24875 = kk_string_len(pre,kk_context()); /*size_t*/
    _x24873 = (_x24874 - _x24875); /*size_t*/
    _b_23023_23022 = kk_std_core__new_Sslice(_x24870, _x24871, _x24873, _ctx); /*sslice*/
    return kk_std_core_types__new_Just(kk_std_core__sslice_box(_b_23023_23022, _ctx), _ctx);
  }
  kk_string_drop(pre, _ctx);
  kk_string_drop(s, _ctx);
  return kk_std_core_types__new_Nothing(_ctx);
}
 
// Trim off a substring `sub` while `s` starts with that string.

kk_string_t kk_std_core_trim_left_1(kk_string_t s, kk_string_t sub, kk_context_t* _ctx) { /* (s : string, sub : string) -> string */ 
  kk__tailcall: ;
  bool _match_23457;
  kk_string_t _x24876 = kk_string_dup(sub); /*string*/
  _match_23457 = kk_std_core_is_empty_2(_x24876, _ctx); /*bool*/
  if (_match_23457) {
    kk_string_drop(sub, _ctx);
    return s;
  }
  kk_std_core_types__maybe _match_23458;
  kk_string_t _x24877 = kk_string_dup(s); /*string*/
  kk_string_t _x24878 = kk_string_dup(sub); /*string*/
  _match_23458 = kk_std_core_starts_with(_x24877, _x24878, _ctx); /*maybe<sslice>*/
  if (kk_std_core_types__is_Just(_match_23458)) {
    kk_box_t _box_x23024 = _match_23458._cons.Just.value;
    kk_std_core__sslice slice0 = kk_std_core__sslice_unbox(_box_x23024, NULL);
    kk_string_drop(s, _ctx);
    { // tailcall
      kk_string_t _x24880 = kk_std_core_string_3(slice0, _ctx); /*string*/
      s = _x24880;
      goto kk__tailcall;
    }
  }
  kk_string_drop(sub, _ctx);
  return s;
}
 
// Trim off a substring `sub` while `s` ends with that string.

kk_string_t kk_std_core_trim_right_1(kk_string_t s, kk_string_t sub, kk_context_t* _ctx) { /* (s : string, sub : string) -> string */ 
  kk__tailcall: ;
  bool _match_23455;
  kk_string_t _x24881 = kk_string_dup(sub); /*string*/
  _match_23455 = kk_std_core_is_empty_2(_x24881, _ctx); /*bool*/
  if (_match_23455) {
    kk_string_drop(sub, _ctx);
    return s;
  }
  kk_std_core_types__maybe _match_23456;
  kk_string_t _x24882 = kk_string_dup(s); /*string*/
  kk_string_t _x24883 = kk_string_dup(sub); /*string*/
  _match_23456 = kk_std_core_ends_with(_x24882, _x24883, _ctx); /*maybe<sslice>*/
  if (kk_std_core_types__is_Just(_match_23456)) {
    kk_box_t _box_x23025 = _match_23456._cons.Just.value;
    kk_std_core__sslice slice0 = kk_std_core__sslice_unbox(_box_x23025, NULL);
    kk_string_drop(s, _ctx);
    { // tailcall
      kk_string_t _x24885 = kk_std_core_string_3(slice0, _ctx); /*string*/
      s = _x24885;
      goto kk__tailcall;
    }
  }
  kk_string_drop(sub, _ctx);
  return s;
}
 
// Parse an integer using `parseInt`. If an illegal digit character is encountered the
// `default` value is returned. An empty string will also result in `default`.

kk_integer_t kk_std_core_parse_int_default(kk_string_t s, kk_std_core_types__optional default0, kk_std_core_types__optional hex, kk_context_t* _ctx) { /* (s : string, default : optional<int>, hex : optional<bool>) -> int */ 
  bool _match_23454;
  kk_string_t _x24891 = kk_string_dup(s); /*string*/
  _match_23454 = kk_std_core_is_empty_2(_x24891, _ctx); /*bool*/
  if (_match_23454) {
    kk_std_core_types__optional_drop(hex, _ctx);
    kk_string_drop(s, _ctx);
    if (kk_std_core_types__is_Optional(default0)) {
      kk_box_t _box_x23027 = default0._cons.Optional.value;
      kk_integer_t _default_19378 = kk_integer_unbox(_box_x23027);
      return _default_19378;
    }
    return kk_integer_from_small(0);
  }
  kk_std_core_types__maybe m_21740;
  kk_std_core_types__optional hex0_21743;
  kk_box_t _x24893;
  bool _x24894;
  if (kk_std_core_types__is_Optional(hex)) {
    kk_box_t _box_x23028 = hex._cons.Optional.value;
    bool _hex_19382 = kk_bool_unbox(_box_x23028);
    _x24894 = _hex_19382; /*bool*/
    goto _match24895;
  }
  _x24894 = false; /*bool*/
  _match24895: ;
  _x24893 = kk_bool_box(_x24894); /*108*/
  hex0_21743 = kk_std_core_types__new_Optional(_x24893, _ctx); /*optional<bool>*/
  kk_string_t _x24897 = kk_std_core_trim(s, _ctx); /*string*/
  bool _x24898;
  if (kk_std_core_types__is_Optional(hex0_21743)) {
    kk_box_t _box_x23031 = hex0_21743._cons.Optional.value;
    bool _hex_19366 = kk_bool_unbox(_box_x23031);
    _x24898 = _hex_19366; /*bool*/
    goto _match24899;
  }
  _x24898 = false; /*bool*/
  _match24899: ;
  m_21740 = kk_std_core_xparse_int(_x24897, _x24898, _ctx); /*maybe<int>*/
  if (kk_std_core_types__is_Nothing(m_21740)) {
    if (kk_std_core_types__is_Optional(default0)) {
      kk_box_t _box_x23032 = default0._cons.Optional.value;
      kk_integer_t _default_193780 = kk_integer_unbox(_box_x23032);
      return _default_193780;
    }
    return kk_integer_from_small(0);
  }
  kk_box_t _box_x23033 = m_21740._cons.Just.value;
  kk_integer_t x = kk_integer_unbox(_box_x23033);
  kk_std_core_types__optional_drop(default0, _ctx);
  return x;
}
 
// monadic lift

kk_std_core_types__tuple2_ kk_std_core__mlift21220_partition_acc(kk_std_core__list acc1, kk_std_core__list acc2, kk_function_t pred, kk_box_t x, kk_std_core__list xx, bool _y_213, kk_context_t* _ctx) { /* forall<a,e> (acc1 : list<a>, acc2 : list<a>, pred : (a) -> e bool, x : a, xx : list<a>, bool) -> e (list<a>, list<a>) */ 
  if (_y_213) {
    kk_std_core__list _x24903 = kk_std_core__new_Cons(kk_reuse_null, x, acc1, _ctx); /*list<61>*/
    return kk_std_core_partition_acc(xx, pred, _x24903, acc2, _ctx);
  }
  kk_std_core__list _x24904 = kk_std_core__new_Cons(kk_reuse_null, x, acc2, _ctx); /*list<61>*/
  return kk_std_core_partition_acc(xx, pred, acc1, _x24904, _ctx);
}


// lift anonymous function
struct kk_std_core_partition_acc_fun24909__t {
  struct kk_function_s _base;
  kk_std_core__list acc10;
  kk_std_core__list acc20;
  kk_function_t pred0;
  kk_box_t x0;
  kk_std_core__list xx0;
};
static kk_box_t kk_std_core_partition_acc_fun24909(kk_function_t _fself, kk_box_t _b_23037, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_partition_acc_fun24909(kk_std_core__list acc10, kk_std_core__list acc20, kk_function_t pred0, kk_box_t x0, kk_std_core__list xx0, kk_context_t* _ctx) {
  struct kk_std_core_partition_acc_fun24909__t* _self = kk_function_alloc_as(struct kk_std_core_partition_acc_fun24909__t, 6, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_partition_acc_fun24909, kk_context());
  _self->acc10 = acc10;
  _self->acc20 = acc20;
  _self->pred0 = pred0;
  _self->x0 = x0;
  _self->xx0 = xx0;
  return &_self->_base;
}

static kk_box_t kk_std_core_partition_acc_fun24909(kk_function_t _fself, kk_box_t _b_23037, kk_context_t* _ctx) {
  struct kk_std_core_partition_acc_fun24909__t* _self = kk_function_as(struct kk_std_core_partition_acc_fun24909__t*, _fself);
  kk_std_core__list acc10 = _self->acc10; /* list<19514> */
  kk_std_core__list acc20 = _self->acc20; /* list<19514> */
  kk_function_t pred0 = _self->pred0; /* (19514) -> 19515 bool */
  kk_box_t x0 = _self->x0; /* 19514 */
  kk_std_core__list xx0 = _self->xx0; /* list<19514> */
  kk_drop_match(_self, {kk_std_core__list_dup(acc10);kk_std_core__list_dup(acc20);kk_function_dup(pred0);kk_box_dup(x0);kk_std_core__list_dup(xx0);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x24910;
  bool _x24911 = kk_bool_unbox(_b_23037); /*bool*/
  _x24910 = kk_std_core__mlift21220_partition_acc(acc10, acc20, pred0, x0, xx0, _x24911, _ctx); /*(list<19514>, list<19514>)*/
  return kk_std_core_types__tuple2__box(_x24910, _ctx);
}

kk_std_core_types__tuple2_ kk_std_core_partition_acc(kk_std_core__list xs, kk_function_t pred0, kk_std_core__list acc10, kk_std_core__list acc20, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, pred : (a) -> e bool, acc1 : list<a>, acc2 : list<a>) -> e (list<a>, list<a>) */ 
  kk__tailcall: ;
  if (kk_std_core__is_Nil(xs)) {
    kk_function_drop(pred0, _ctx);
    kk_std_core__list _b_23038_23034 = kk_std_core_reverse(acc10, _ctx); /*list<19514>*/;
    kk_std_core__list _b_23039_23035 = kk_std_core_reverse(acc20, _ctx); /*list<19514>*/;
    return kk_std_core_types__new_dash__lp__comma__rp_(kk_std_core__list_box(_b_23038_23034, _ctx), kk_std_core__list_box(_b_23039_23035, _ctx), _ctx);
  }
  struct kk_std_core_Cons* _con24905 = kk_std_core__as_Cons(xs);
  kk_box_t x0 = _con24905->head;
  kk_std_core__list xx0 = _con24905->tail;
  kk_reuse_t _ru_23409 = kk_reuse_null; /*reuse*/;
  if (kk_std_core__list_is_unique(xs)) {
    _ru_23409 = (kk_std_core__list_reuse(xs));
  }
  else {
    kk_box_dup(x0);
    kk_std_core__list_dup(xx0);
    kk_std_core__list_decref(xs, _ctx);
    _ru_23409 = kk_reuse_null;
  }
  bool x0_21744;
  kk_function_t _x24907 = kk_function_dup(pred0); /*(19514) -> 19515 bool*/
  kk_box_t _x24906 = kk_box_dup(x0); /*19514*/
  x0_21744 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_context_t*), _x24907, (_x24907, _x24906, _ctx)); /*bool*/
  if (kk_yielding(kk_context())) {
    kk_reuse_drop(_ru_23409, _ctx);
    kk_box_t _x24908 = kk_std_core_hnd_yield_extend(kk_std_core_new_partition_acc_fun24909(acc10, acc20, pred0, x0, xx0, _ctx), _ctx); /*3991*/
    return kk_std_core_types__tuple2__unbox(_x24908, _ctx);
  }
  if (x0_21744) {
    { // tailcall
      kk_std_core__list _x24912;
      bool _x24913 = _ru_23409!=NULL; /*bool*/
      if (_x24913) {
        struct kk_std_core_Cons* _con24914 = (struct kk_std_core_Cons*)_ru_23409;
        _con24914->tail = acc10;
        _x24912 = kk_std_core__base_Cons(_con24914); /*list<61>*/
      }
      else {
        _x24912 = kk_std_core__new_Cons(kk_reuse_null, x0, acc10, _ctx); /*list<61>*/
      }
      xs = xx0;
      acc10 = _x24912;
      goto kk__tailcall;
    }
  }
  { // tailcall
    kk_std_core__list _x24915;
    bool _x24916 = _ru_23409!=NULL; /*bool*/
    if (_x24916) {
      struct kk_std_core_Cons* _con24917 = (struct kk_std_core_Cons*)_ru_23409;
      _con24917->tail = acc20;
      _x24915 = kk_std_core__base_Cons(_con24917); /*list<61>*/
    }
    else {
      _x24915 = kk_std_core__new_Cons(kk_reuse_null, x0, acc20, _ctx); /*list<61>*/
    }
    xs = xx0;
    acc20 = _x24915;
    goto kk__tailcall;
  }
}
 
// redirect `print` and `println` calls to a specified function.


// lift anonymous function
struct kk_std_core_print_redirect_fun24918__t {
  struct kk_function_s _base;
  kk_function_t print0;
};
static kk_box_t kk_std_core_print_redirect_fun24918(kk_function_t _fself, kk_box_t _b_23045, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_print_redirect_fun24918(kk_function_t print0, kk_context_t* _ctx) {
  struct kk_std_core_print_redirect_fun24918__t* _self = kk_function_alloc_as(struct kk_std_core_print_redirect_fun24918__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_print_redirect_fun24918, kk_context());
  _self->print0 = print0;
  return &_self->_base;
}

static kk_box_t kk_std_core_print_redirect_fun24918(kk_function_t _fself, kk_box_t _b_23045, kk_context_t* _ctx) {
  struct kk_std_core_print_redirect_fun24918__t* _self = kk_function_as(struct kk_std_core_print_redirect_fun24918__t*, _fself);
  kk_function_t print0 = _self->print0; /* (msg : string) -> console () */
  kk_drop_match(_self, {kk_function_dup(print0);}, {}, _ctx)
  kk_unit_t _x24919 = kk_Unit;
  kk_string_t _x24920 = kk_string_unbox(_b_23045); /*string*/
  kk_function_call(kk_unit_t, (kk_function_t, kk_string_t, kk_context_t*), print0, (print0, _x24920, _ctx));
  return kk_unit_box(_x24919);
}

kk_unit_t kk_std_core_print_redirect(kk_function_t print0, kk_context_t* _ctx) { /* (print : (msg : string) -> console ()) -> io () */ 
  kk_std_core_types__maybe _b_23049_23047 = kk_std_core_types__new_Just(kk_function_box(kk_std_core_new_print_redirect_fun24918(print0, _ctx)), _ctx); /*maybe<(msg : string) -> console ()>*/;
  kk_ref_t _x24921 = kk_ref_dup(kk_std_core_redirect); /*ref<global,maybe<(string) -> console ()>>*/
  kk_ref_set(_x24921,(kk_std_core_types__maybe_box(_b_23049_23047, _ctx)),kk_context()); return kk_Unit;
}
extern bool kk_std_core_remove_fun24922(kk_function_t _fself, kk_box_t x, kk_context_t* _ctx) {
  struct kk_std_core_remove_fun24922__t* _self = kk_function_as(struct kk_std_core_remove_fun24922__t*, _fself);
  kk_function_t pred = _self->pred; /* (19585) -> bool */
  kk_drop_match(_self, {kk_function_dup(pred);}, {}, _ctx)
  bool _x24923 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_context_t*), pred, (pred, x, _ctx)); /*bool*/
  return !(_x24923);
}
extern kk_unit_t kk_std_core_repeat_fun24925_1(kk_function_t _fself, kk_integer_t i, kk_context_t* _ctx) {
  struct kk_std_core_repeat_fun24925__t_1* _self = kk_function_as(struct kk_std_core_repeat_fun24925__t_1*, _fself);
  kk_function_t action = _self->action; /* () -> 19604 () */
  kk_drop_match(_self, {kk_function_dup(action);}, {}, _ctx)
  kk_integer_drop(i, _ctx);
  return kk_function_call(kk_unit_t, (kk_function_t, kk_context_t*), action, (action, _ctx));
}
 
// Create a list of `n`  repeated elementes `x`

kk_std_core__list kk_std_core__ctail_replicate(kk_box_t x, kk_integer_t n, kk_std_core_types__ctail _acc, kk_context_t* _ctx) { /* forall<a> (x : a, n : int, ctail<list<a>>) -> list<a> */ 
  kk__tailcall: ;
  bool _match_23452;
  kk_integer_t _x24926 = kk_integer_dup(n); /*int*/
  _match_23452 = kk_integer_gt(_x24926,(kk_integer_from_small(0)),kk_context()); /*bool*/
  if (_match_23452) {
    kk_std_core__list _ctail_21151 = kk_std_core__list_hole(); /*list<19661>*/;
    kk_std_core__list _ctail_21152;
    kk_box_t _x24927 = kk_box_dup(x); /*19661*/
    _ctail_21152 = kk_std_core__new_Cons(kk_reuse_null, _x24927, _ctail_21151, _ctx); /*list<19661>*/
    { // tailcall
      kk_integer_t _x24928 = kk_std_core_dec(n, _ctx); /*int*/
      kk_std_core_types__ctail _x24929;
      kk_box_t* field_21753 = (kk_box_t*)((&kk_std_core__as_Cons(_ctail_21152)->tail)); /*cfield<list<19661>>*/;
      if (kk_std_core_types__is_CTail(_acc)) {
        kk_box_t _box_x23057 = _acc._cons.CTail._field1;
        kk_box_t* last0 = _acc._cons.CTail._field2;
        kk_std_core__list head0 = kk_std_core__list_unbox(_box_x23057, NULL);
        kk_unit_t __ = kk_Unit;
        *(last0) = kk_std_core__list_box(_ctail_21152, _ctx);
        _x24929 = kk_std_core_types__new_CTail(kk_std_core__list_box(head0, _ctx), field_21753, _ctx); /*ctail<58>*/
        goto _match24930;
      }
      _x24929 = kk_std_core_types__new_CTail(kk_std_core__list_box(_ctail_21152, _ctx), field_21753, _ctx); /*ctail<58>*/
      _match24930: ;
      n = _x24928;
      _acc = _x24929;
      goto kk__tailcall;
    }
  }
  kk_integer_drop(n, _ctx);
  kk_box_drop(x, _ctx);
  if (kk_std_core_types__is_CTail(_acc)) {
    kk_box_t _box_x23066 = _acc._cons.CTail._field1;
    kk_box_t* last00 = _acc._cons.CTail._field2;
    kk_std_core__list head00 = kk_std_core__list_unbox(_box_x23066, NULL);
    kk_unit_t __0 = kk_Unit;
    *(last00) = kk_std_core__list_box(kk_std_core__new_Nil(_ctx), _ctx);
    return head00;
  }
  return kk_std_core__new_Nil(_ctx);
}
 
// Create a list of `n`  repeated elementes `x`

kk_std_core__list kk_std_core_replicate(kk_box_t x0, kk_integer_t n0, kk_context_t* _ctx) { /* forall<a> (x : a, n : int) -> list<a> */ 
  return kk_std_core__ctail_replicate(x0, n0, kk_std_core_types__new_CTailNil(_ctx), _ctx);
}

kk_string_t kk_std_core_show_tuple(kk_std_core_types__tuple2_ x, kk_function_t showfst, kk_function_t showsnd, kk_context_t* _ctx) { /* forall<a,b> (x : (a, b), showfst : (a) -> string, showsnd : (b) -> string) -> string */ 
  kk_string_t _x24933;
  kk_define_string_literal(, _s24934, 1, "(")
  _x24933 = kk_string_dup(_s24934); /*string*/
  kk_string_t _x24935;
  kk_string_t _x24936;
  kk_box_t _x24937;
  kk_box_t _x = x.fst;
  kk_box_dup(_x);
  _x24937 = _x; /*20019*/
  _x24936 = kk_function_call(kk_string_t, (kk_function_t, kk_box_t, kk_context_t*), showfst, (showfst, _x24937, _ctx)); /*string*/
  kk_string_t _x24938;
  kk_string_t _x24939;
  kk_define_string_literal(, _s24940, 1, ",")
  _x24939 = kk_string_dup(_s24940); /*string*/
  kk_string_t _x24941;
  kk_string_t _x24942;
  kk_box_t _x24943;
  kk_box_t _x0 = x.snd;
  kk_box_dup(_x0);
  kk_std_core_types__tuple2__drop(x, _ctx);
  _x24943 = _x0; /*20020*/
  _x24942 = kk_function_call(kk_string_t, (kk_function_t, kk_box_t, kk_context_t*), showsnd, (showsnd, _x24943, _ctx)); /*string*/
  kk_string_t _x24944;
  kk_define_string_literal(, _s24945, 1, ")")
  _x24944 = kk_string_dup(_s24945); /*string*/
  _x24941 = kk_std_core__lp__plus__plus__1_rp_(_x24942, _x24944, _ctx); /*string*/
  _x24938 = kk_std_core__lp__plus__plus__1_rp_(_x24939, _x24941, _ctx); /*string*/
  _x24935 = kk_std_core__lp__plus__plus__1_rp_(_x24936, _x24938, _ctx); /*string*/
  return kk_std_core__lp__plus__plus__1_rp_(_x24933, _x24935, _ctx);
}
 
// monadic lift

kk_std_core_types__tuple2_ kk_std_core__mlift21221_op(kk_std_core__list acc, kk_function_t predicate, kk_box_t y, kk_std_core__list ys, kk_std_core__list yy, bool _y_221, kk_context_t* _ctx) { /* forall<a,e> (acc : list<a>, predicate : (a) -> e bool, y : a, ys : list<a>, yy : list<a>, bool) -> e (list<a>, list<a>) */ 
  if (_y_221) {
    kk_std_core__list_drop(ys, _ctx);
    kk_std_core__list acc0_21098 = kk_std_core__new_Cons(kk_reuse_null, y, acc, _ctx); /*list<20021>*/;
    return kk_std_core__lift21060_span(predicate, yy, acc0_21098, _ctx);
  }
  kk_function_drop(predicate, _ctx);
  kk_box_drop(y, _ctx);
  kk_std_core__list_drop(yy, _ctx);
  kk_std_core__list _b_23077_23075 = kk_std_core_reverse(acc, _ctx); /*list<20021>*/;
  return kk_std_core_types__new_dash__lp__comma__rp_(kk_std_core__list_box(_b_23077_23075, _ctx), kk_std_core__list_box(ys, _ctx), _ctx);
}
 
// lift


// lift anonymous function
struct kk_std_core__lift21060_span_fun24951__t {
  struct kk_function_s _base;
  kk_std_core__list acc0;
  kk_function_t predicate0;
  kk_box_t y0;
  kk_std_core__list ys0;
  kk_std_core__list yy0;
};
static kk_box_t kk_std_core__lift21060_span_fun24951(kk_function_t _fself, kk_box_t _b_23080, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_lift21060_span_fun24951(kk_std_core__list acc0, kk_function_t predicate0, kk_box_t y0, kk_std_core__list ys0, kk_std_core__list yy0, kk_context_t* _ctx) {
  struct kk_std_core__lift21060_span_fun24951__t* _self = kk_function_alloc_as(struct kk_std_core__lift21060_span_fun24951__t, 6, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__lift21060_span_fun24951, kk_context());
  _self->acc0 = acc0;
  _self->predicate0 = predicate0;
  _self->y0 = y0;
  _self->ys0 = ys0;
  _self->yy0 = yy0;
  return &_self->_base;
}

static kk_box_t kk_std_core__lift21060_span_fun24951(kk_function_t _fself, kk_box_t _b_23080, kk_context_t* _ctx) {
  struct kk_std_core__lift21060_span_fun24951__t* _self = kk_function_as(struct kk_std_core__lift21060_span_fun24951__t*, _fself);
  kk_std_core__list acc0 = _self->acc0; /* list<20021> */
  kk_function_t predicate0 = _self->predicate0; /* (20021) -> 20022 bool */
  kk_box_t y0 = _self->y0; /* 20021 */
  kk_std_core__list ys0 = _self->ys0; /* list<20021> */
  kk_std_core__list yy0 = _self->yy0; /* list<20021> */
  kk_drop_match(_self, {kk_std_core__list_dup(acc0);kk_function_dup(predicate0);kk_box_dup(y0);kk_std_core__list_dup(ys0);kk_std_core__list_dup(yy0);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x24952;
  bool _x24953 = kk_bool_unbox(_b_23080); /*bool*/
  _x24952 = kk_std_core__mlift21221_op(acc0, predicate0, y0, ys0, yy0, _x24953, _ctx); /*(list<20021>, list<20021>)*/
  return kk_std_core_types__tuple2__box(_x24952, _ctx);
}

kk_std_core_types__tuple2_ kk_std_core__lift21060_span(kk_function_t predicate0, kk_std_core__list ys0, kk_std_core__list acc0, kk_context_t* _ctx) { /* forall<a,e> (predicate : (a) -> e bool, ys : list<a>, acc : list<a>) -> e (list<a>, list<a>) */ 
  kk__tailcall: ;
  if (kk_std_core__is_Cons(ys0)) {
    struct kk_std_core_Cons* _con24946 = kk_std_core__as_Cons(ys0);
    kk_box_t y0 = _con24946->head;
    kk_std_core__list yy0 = _con24946->tail;
    kk_box_dup(y0);
    kk_std_core__list_dup(yy0);
    kk_reuse_t _ru_23410;
    kk_std_core__list _x24947 = kk_std_core__list_dup(ys0); /*list<20021>*/
    _ru_23410 = kk_std_core__list_dropn_reuse(_x24947, ((int32_t)2), _ctx); /*reuse*/
    bool x_21758;
    kk_function_t _x24949 = kk_function_dup(predicate0); /*(20021) -> 20022 bool*/
    kk_box_t _x24948 = kk_box_dup(y0); /*20021*/
    x_21758 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_context_t*), _x24949, (_x24949, _x24948, _ctx)); /*bool*/
    if (kk_yielding(kk_context())) {
      kk_reuse_drop(_ru_23410, _ctx);
      kk_box_t _x24950 = kk_std_core_hnd_yield_extend(kk_std_core__new_lift21060_span_fun24951(acc0, predicate0, y0, ys0, yy0, _ctx), _ctx); /*3991*/
      return kk_std_core_types__tuple2__unbox(_x24950, _ctx);
    }
    if (x_21758) {
      kk_std_core__list_dropn(ys0, ((int32_t)2), _ctx);
      kk_std_core__list acc0_210980;
      bool _x24954 = _ru_23410!=NULL; /*bool*/
      if (_x24954) {
        struct kk_std_core_Cons* _con24955 = (struct kk_std_core_Cons*)_ru_23410;
        _con24955->tail = acc0;
        acc0_210980 = kk_std_core__base_Cons(_con24955); /*list<20021>*/
      }
      else {
        acc0_210980 = kk_std_core__new_Cons(kk_reuse_null, y0, acc0, _ctx); /*list<20021>*/
      }
      { // tailcall
        ys0 = yy0;
        acc0 = acc0_210980;
        goto kk__tailcall;
      }
    }
    kk_reuse_drop(_ru_23410, _ctx);
    kk_function_drop(predicate0, _ctx);
    kk_box_drop(y0, _ctx);
    kk_std_core__list_drop(yy0, _ctx);
    kk_std_core__list _b_23087_23081 = kk_std_core_reverse(acc0, _ctx); /*list<20021>*/;
    return kk_std_core_types__new_dash__lp__comma__rp_(kk_std_core__list_box(_b_23087_23081, _ctx), kk_std_core__list_box(ys0, _ctx), _ctx);
  }
  kk_function_drop(predicate0, _ctx);
  kk_std_core__list _b_23089_23083 = kk_std_core_reverse(acc0, _ctx); /*list<20021>*/;
  return kk_std_core_types__new_dash__lp__comma__rp_(kk_std_core__list_box(_b_23089_23083, _ctx), kk_std_core__list_box(ys0, _ctx), _ctx);
}
 
// Return the sum of a list of integers


// lift anonymous function
struct kk_std_core_sum_fun24957__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_sum_fun24957(kk_function_t _fself, kk_box_t _b_23094, kk_box_t _b_23095, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_sum_fun24957(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_sum_fun24957, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_core_sum_fun24957(kk_function_t _fself, kk_box_t _b_23094, kk_box_t _b_23095, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_integer_t _x24958;
  kk_integer_t _x24959 = kk_integer_unbox(_b_23094); /*int*/
  kk_integer_t _x24960 = kk_integer_unbox(_b_23095); /*int*/
  _x24958 = kk_integer_add(_x24959,_x24960,kk_context()); /*int*/
  return kk_integer_box(_x24958);
}

kk_integer_t kk_std_core_sum(kk_std_core__list xs, kk_context_t* _ctx) { /* (xs : list<int>) -> int */ 
  kk_box_t _x24956 = kk_std_core_foldl(xs, kk_integer_box(kk_integer_from_small(0)), kk_std_core_new_sum_fun24957(_ctx), _ctx); /*15010*/
  return kk_integer_unbox(_x24956);
}
 
// Return the tail of list. Returns the empty list if `xs` is empty.

kk_std_core__list kk_std_core_tail_1(kk_std_core__list xs, kk_context_t* _ctx) { /* forall<a> (xs : list<a>) -> list<a> */ 
  if (kk_std_core__is_Cons(xs)) {
    struct kk_std_core_Cons* _con24961 = kk_std_core__as_Cons(xs);
    kk_box_t _pat0 = _con24961->head;
    kk_std_core__list xx = _con24961->tail;
    if (kk_std_core__list_is_unique(xs)) {
      kk_box_drop(_pat0, _ctx);
      kk_std_core__list_free(xs);
    }
    else {
      kk_std_core__list_dup(xx);
      kk_std_core__list_decref(xs, _ctx);
    }
    return xx;
  }
  return kk_std_core__new_Nil(_ctx);
}
 
// Return the tail of a string (or the empty string)

kk_string_t kk_std_core_tail_2(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> string */ 
  kk_std_core__sslice _x24962;
  kk_std_core__sslice slice_21762;
  kk_std_core__sslice slice0 = kk_std_core_first1(s, _ctx); /*sslice*/;
  bool _match_23448;
  kk_integer_t _x24963;
  kk_std_core_types__optional _x24964 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/
  if (kk_std_core_types__is_Optional(_x24964)) {
    kk_box_t _box_x23101 = _x24964._cons.Optional.value;
    kk_integer_t _n_12425 = kk_integer_unbox(_box_x23101);
    _x24963 = _n_12425; /*int*/
    goto _match24965;
  }
  _x24963 = kk_integer_from_small(1); /*int*/
  _match24965: ;
  _match_23448 = kk_integer_eq(_x24963,(kk_integer_from_small(1)),kk_context()); /*bool*/
  if (_match_23448) {
    slice_21762 = slice0; /*sslice*/
  }
  else {
    kk_integer_t _x24967;
    kk_integer_t _x24968;
    kk_std_core_types__optional _x24969 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/
    if (kk_std_core_types__is_Optional(_x24969)) {
      kk_box_t _box_x23102 = _x24969._cons.Optional.value;
      kk_integer_t _n_124250 = kk_integer_unbox(_box_x23102);
      _x24968 = _n_124250; /*int*/
      goto _match24970;
    }
    _x24968 = kk_integer_from_small(1); /*int*/
    _match24970: ;
    _x24967 = kk_integer_sub(_x24968,(kk_integer_from_small(1)),kk_context()); /*int*/
    slice_21762 = kk_std_core_extend(slice0, _x24967, _ctx); /*sslice*/
  }
  kk_string_t s0 = slice_21762.str;
  size_t start0 = slice_21762.start;
  size_t len0 = slice_21762.len;
  kk_string_dup(s0);
  kk_std_core__sslice_drop(slice_21762, _ctx);
  kk_string_t _x24972 = kk_string_dup(s0); /*string*/
  size_t _x24973 = (start0 + len0); /*size_t*/
  size_t _x24974;
  size_t _x24975 = kk_string_len(s0,kk_context()); /*size_t*/
  size_t _x24976 = (start0 + len0); /*size_t*/
  _x24974 = (_x24975 - _x24976); /*size_t*/
  _x24962 = kk_std_core__new_Sslice(_x24972, _x24973, _x24974, _ctx); /*sslice*/
  return kk_std_core_string_3(_x24962, _ctx);
}
 
// monadic lift

kk_std_core__list kk_std_core__mlift21222_op(kk_std_core_types__ctail _acc, kk_function_t predicate, kk_box_t x, kk_std_core__list xx, bool _y_226, kk_context_t* _ctx) { /* forall<a,e> (ctail<list<a>>, predicate : (a) -> e bool, x : a, xx : list<a>, bool) -> e list<a> */ 
  if (_y_226) {
    kk_std_core__list _ctail_21153 = kk_std_core__list_hole(); /*list<20220>*/;
    kk_std_core__list _ctail_21154 = kk_std_core__new_Cons(kk_reuse_null, x, _ctail_21153, _ctx); /*list<20220>*/;
    kk_std_core_types__ctail _x24977;
    kk_box_t* field_21767 = (kk_box_t*)((&kk_std_core__as_Cons(_ctail_21154)->tail)); /*cfield<list<20220>>*/;
    if (kk_std_core_types__is_CTail(_acc)) {
      kk_box_t _box_x23109 = _acc._cons.CTail._field1;
      kk_box_t* last0 = _acc._cons.CTail._field2;
      kk_std_core__list head0 = kk_std_core__list_unbox(_box_x23109, NULL);
      kk_unit_t __ = kk_Unit;
      *(last0) = kk_std_core__list_box(_ctail_21154, _ctx);
      _x24977 = kk_std_core_types__new_CTail(kk_std_core__list_box(head0, _ctx), field_21767, _ctx); /*ctail<58>*/
      goto _match24978;
    }
    _x24977 = kk_std_core_types__new_CTail(kk_std_core__list_box(_ctail_21154, _ctx), field_21767, _ctx); /*ctail<58>*/
    _match24978: ;
    return kk_std_core__ctail_take_while(xx, predicate, _x24977, _ctx);
  }
  kk_function_drop(predicate, _ctx);
  kk_box_drop(x, _ctx);
  kk_std_core__list_drop(xx, _ctx);
  if (kk_std_core_types__is_CTail(_acc)) {
    kk_box_t _box_x23118 = _acc._cons.CTail._field1;
    kk_box_t* last00 = _acc._cons.CTail._field2;
    kk_std_core__list head00 = kk_std_core__list_unbox(_box_x23118, NULL);
    kk_unit_t __0 = kk_Unit;
    *(last00) = kk_std_core__list_box(kk_std_core__new_Nil(_ctx), _ctx);
    return head00;
  }
  return kk_std_core__new_Nil(_ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_core__mlift21223_op_fun24981__t {
  struct kk_function_s _base;
  kk_function_t _accm;
  kk_box_t x0;
};
static kk_std_core__list kk_std_core__mlift21223_op_fun24981(kk_function_t _fself, kk_std_core__list _ctail_21156, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_mlift21223_op_fun24981(kk_function_t _accm, kk_box_t x0, kk_context_t* _ctx) {
  struct kk_std_core__mlift21223_op_fun24981__t* _self = kk_function_alloc_as(struct kk_std_core__mlift21223_op_fun24981__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__mlift21223_op_fun24981, kk_context());
  _self->_accm = _accm;
  _self->x0 = x0;
  return &_self->_base;
}

static kk_std_core__list kk_std_core__mlift21223_op_fun24981(kk_function_t _fself, kk_std_core__list _ctail_21156, kk_context_t* _ctx) {
  struct kk_std_core__mlift21223_op_fun24981__t* _self = kk_function_as(struct kk_std_core__mlift21223_op_fun24981__t*, _fself);
  kk_function_t _accm = _self->_accm; /* (list<20220>) -> list<20220> */
  kk_box_t x0 = _self->x0; /* 20220 */
  kk_drop_match(_self, {kk_function_dup(_accm);kk_box_dup(x0);}, {}, _ctx)
  kk_std_core__list _x24982 = kk_std_core__new_Cons(kk_reuse_null, x0, _ctail_21156, _ctx); /*list<61>*/
  return kk_function_call(kk_std_core__list, (kk_function_t, kk_std_core__list, kk_context_t*), _accm, (_accm, _x24982, _ctx));
}

kk_std_core__list kk_std_core__mlift21223_op(kk_function_t _accm, kk_function_t predicate0, kk_box_t x0, kk_std_core__list xx0, bool _y_230, kk_context_t* _ctx) { /* forall<a,e> ((list<a>) -> list<a>, predicate : (a) -> e bool, x : a, xx : list<a>, bool) -> e list<a> */ 
  if (_y_230) {
    return kk_std_core__ctailm_take_while(xx0, predicate0, kk_std_core__new_mlift21223_op_fun24981(_accm, x0, _ctx), _ctx);
  }
  kk_function_drop(predicate0, _ctx);
  kk_box_drop(x0, _ctx);
  kk_std_core__list_drop(xx0, _ctx);
  return kk_function_call(kk_std_core__list, (kk_function_t, kk_std_core__list, kk_context_t*), _accm, (_accm, kk_std_core__new_Nil(_ctx), _ctx));
}
 
// Keep only those initial elements that satisfy `predicate`


// lift anonymous function
struct kk_std_core__ctail_take_while_fun24987__t {
  struct kk_function_s _base;
  kk_function_t predicate1;
  kk_box_t x1;
  kk_std_core__list xx1;
  kk_std_core_types__ctail _acc0;
};
static kk_box_t kk_std_core__ctail_take_while_fun24987(kk_function_t _fself, kk_box_t _b_23128, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_ctail_take_while_fun24987(kk_function_t predicate1, kk_box_t x1, kk_std_core__list xx1, kk_std_core_types__ctail _acc0, kk_context_t* _ctx) {
  struct kk_std_core__ctail_take_while_fun24987__t* _self = kk_function_alloc_as(struct kk_std_core__ctail_take_while_fun24987__t, 6, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__ctail_take_while_fun24987, kk_context());
  _self->predicate1 = predicate1;
  _self->x1 = x1;
  _self->xx1 = xx1;
  _self->_acc0 = _acc0;
  return &_self->_base;
}

static kk_box_t kk_std_core__ctail_take_while_fun24987(kk_function_t _fself, kk_box_t _b_23128, kk_context_t* _ctx) {
  struct kk_std_core__ctail_take_while_fun24987__t* _self = kk_function_as(struct kk_std_core__ctail_take_while_fun24987__t*, _fself);
  kk_function_t predicate1 = _self->predicate1; /* (20220) -> 20221 bool */
  kk_box_t x1 = _self->x1; /* 20220 */
  kk_std_core__list xx1 = _self->xx1; /* list<20220> */
  kk_std_core_types__ctail _acc0 = _self->_acc0; /* ctail<list<20220>> */
  kk_drop_match(_self, {kk_function_dup(predicate1);kk_box_dup(x1);kk_std_core__list_dup(xx1);kk_std_core_types__ctail_dup(_acc0);}, {}, _ctx)
  kk_std_core__list _x24988;
  bool _x24989 = kk_bool_unbox(_b_23128); /*bool*/
  _x24988 = kk_std_core__mlift21222_op(_acc0, predicate1, x1, xx1, _x24989, _ctx); /*list<20220>*/
  return kk_std_core__list_box(_x24988, _ctx);
}

kk_std_core__list kk_std_core__ctail_take_while(kk_std_core__list xs, kk_function_t predicate1, kk_std_core_types__ctail _acc0, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, predicate : (a) -> e bool, ctail<list<a>>) -> e list<a> */ 
  kk__tailcall: ;
  if (kk_std_core__is_Cons(xs)) {
    struct kk_std_core_Cons* _con24983 = kk_std_core__as_Cons(xs);
    kk_box_t x1 = _con24983->head;
    kk_std_core__list xx1 = _con24983->tail;
    kk_reuse_t _ru_23412 = kk_reuse_null; /*reuse*/;
    if (kk_std_core__list_is_unique(xs)) {
      _ru_23412 = (kk_std_core__list_reuse(xs));
    }
    else {
      kk_box_dup(x1);
      kk_std_core__list_dup(xx1);
      kk_std_core__list_decref(xs, _ctx);
      _ru_23412 = kk_reuse_null;
    }
    bool x0_21770;
    kk_function_t _x24985 = kk_function_dup(predicate1); /*(20220) -> 20221 bool*/
    kk_box_t _x24984 = kk_box_dup(x1); /*20220*/
    x0_21770 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_context_t*), _x24985, (_x24985, _x24984, _ctx)); /*bool*/
    if (kk_yielding(kk_context())) {
      kk_reuse_drop(_ru_23412, _ctx);
      kk_box_t _x24986 = kk_std_core_hnd_yield_extend(kk_std_core__new_ctail_take_while_fun24987(predicate1, x1, xx1, _acc0, _ctx), _ctx); /*3991*/
      return kk_std_core__list_unbox(_x24986, _ctx);
    }
    if (x0_21770) {
      kk_std_core__list _ctail_211530 = kk_std_core__list_hole(); /*list<20220>*/;
      kk_std_core__list _ctail_211540;
      bool _x24990 = _ru_23412!=NULL; /*bool*/
      if (_x24990) {
        struct kk_std_core_Cons* _con24991 = (struct kk_std_core_Cons*)_ru_23412;
        _con24991->tail = _ctail_211530;
        _ctail_211540 = kk_std_core__base_Cons(_con24991); /*list<20220>*/
      }
      else {
        _ctail_211540 = kk_std_core__new_Cons(kk_reuse_null, x1, _ctail_211530, _ctx); /*list<20220>*/
      }
      { // tailcall
        kk_std_core_types__ctail _x24992;
        kk_box_t* field_21776 = (kk_box_t*)((&kk_std_core__as_Cons(_ctail_211540)->tail)); /*cfield<list<20220>>*/;
        if (kk_std_core_types__is_CTail(_acc0)) {
          kk_box_t _box_x23135 = _acc0._cons.CTail._field1;
          kk_box_t* last2 = _acc0._cons.CTail._field2;
          kk_std_core__list head1 = kk_std_core__list_unbox(_box_x23135, NULL);
          kk_unit_t __1 = kk_Unit;
          *(last2) = kk_std_core__list_box(_ctail_211540, _ctx);
          _x24992 = kk_std_core_types__new_CTail(kk_std_core__list_box(head1, _ctx), field_21776, _ctx); /*ctail<58>*/
          goto _match24993;
        }
        _x24992 = kk_std_core_types__new_CTail(kk_std_core__list_box(_ctail_211540, _ctx), field_21776, _ctx); /*ctail<58>*/
        _match24993: ;
        xs = xx1;
        _acc0 = _x24992;
        goto kk__tailcall;
      }
    }
    kk_reuse_drop(_ru_23412, _ctx);
    kk_function_drop(predicate1, _ctx);
    kk_box_drop(x1, _ctx);
    kk_std_core__list_drop(xx1, _ctx);
    if (kk_std_core_types__is_CTail(_acc0)) {
      kk_box_t _box_x23144 = _acc0._cons.CTail._field1;
      kk_box_t* last01 = _acc0._cons.CTail._field2;
      kk_std_core__list head01 = kk_std_core__list_unbox(_box_x23144, NULL);
      kk_unit_t __00 = kk_Unit;
      *(last01) = kk_std_core__list_box(kk_std_core__new_Nil(_ctx), _ctx);
      return head01;
    }
    return kk_std_core__new_Nil(_ctx);
  }
  kk_function_drop(predicate1, _ctx);
  if (kk_std_core_types__is_CTail(_acc0)) {
    kk_box_t _box_x23149 = _acc0._cons.CTail._field1;
    kk_box_t* last10 = _acc0._cons.CTail._field2;
    kk_std_core__list head10 = kk_std_core__list_unbox(_box_x23149, NULL);
    kk_unit_t __10 = kk_Unit;
    *(last10) = kk_std_core__list_box(kk_std_core__new_Nil(_ctx), _ctx);
    return head10;
  }
  return kk_std_core__new_Nil(_ctx);
}
 
// Keep only those initial elements that satisfy `predicate`


// lift anonymous function
struct kk_std_core__ctailm_take_while_fun25001__t {
  struct kk_function_s _base;
  kk_function_t _accm0;
  kk_function_t predicate2;
  kk_box_t x2;
  kk_std_core__list xx2;
};
static kk_box_t kk_std_core__ctailm_take_while_fun25001(kk_function_t _fself, kk_box_t _b_23161, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_ctailm_take_while_fun25001(kk_function_t _accm0, kk_function_t predicate2, kk_box_t x2, kk_std_core__list xx2, kk_context_t* _ctx) {
  struct kk_std_core__ctailm_take_while_fun25001__t* _self = kk_function_alloc_as(struct kk_std_core__ctailm_take_while_fun25001__t, 5, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__ctailm_take_while_fun25001, kk_context());
  _self->_accm0 = _accm0;
  _self->predicate2 = predicate2;
  _self->x2 = x2;
  _self->xx2 = xx2;
  return &_self->_base;
}

static kk_box_t kk_std_core__ctailm_take_while_fun25001(kk_function_t _fself, kk_box_t _b_23161, kk_context_t* _ctx) {
  struct kk_std_core__ctailm_take_while_fun25001__t* _self = kk_function_as(struct kk_std_core__ctailm_take_while_fun25001__t*, _fself);
  kk_function_t _accm0 = _self->_accm0; /* (list<20220>) -> list<20220> */
  kk_function_t predicate2 = _self->predicate2; /* (20220) -> 20221 bool */
  kk_box_t x2 = _self->x2; /* 20220 */
  kk_std_core__list xx2 = _self->xx2; /* list<20220> */
  kk_drop_match(_self, {kk_function_dup(_accm0);kk_function_dup(predicate2);kk_box_dup(x2);kk_std_core__list_dup(xx2);}, {}, _ctx)
  kk_std_core__list _x25002;
  bool _x25003 = kk_bool_unbox(_b_23161); /*bool*/
  _x25002 = kk_std_core__mlift21223_op(_accm0, predicate2, x2, xx2, _x25003, _ctx); /*list<20220>*/
  return kk_std_core__list_box(_x25002, _ctx);
}


// lift anonymous function
struct kk_std_core__ctailm_take_while_fun25005__t {
  struct kk_function_s _base;
  kk_function_t _accm0;
  kk_box_t x2;
};
static kk_std_core__list kk_std_core__ctailm_take_while_fun25005(kk_function_t _fself, kk_std_core__list _ctail_211560, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_ctailm_take_while_fun25005(kk_function_t _accm0, kk_box_t x2, kk_context_t* _ctx) {
  struct kk_std_core__ctailm_take_while_fun25005__t* _self = kk_function_alloc_as(struct kk_std_core__ctailm_take_while_fun25005__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__ctailm_take_while_fun25005, kk_context());
  _self->_accm0 = _accm0;
  _self->x2 = x2;
  return &_self->_base;
}

static kk_std_core__list kk_std_core__ctailm_take_while_fun25005(kk_function_t _fself, kk_std_core__list _ctail_211560, kk_context_t* _ctx) {
  struct kk_std_core__ctailm_take_while_fun25005__t* _self = kk_function_as(struct kk_std_core__ctailm_take_while_fun25005__t*, _fself);
  kk_function_t _accm0 = _self->_accm0; /* (list<20220>) -> list<20220> */
  kk_box_t x2 = _self->x2; /* 20220 */
  kk_drop_match(_self, {kk_function_dup(_accm0);kk_box_dup(x2);}, {}, _ctx)
  kk_std_core__list _x25006 = kk_std_core__new_Cons(kk_reuse_null, x2, _ctail_211560, _ctx); /*list<61>*/
  return kk_function_call(kk_std_core__list, (kk_function_t, kk_std_core__list, kk_context_t*), _accm0, (_accm0, _x25006, _ctx));
}

kk_std_core__list kk_std_core__ctailm_take_while(kk_std_core__list xs0, kk_function_t predicate2, kk_function_t _accm0, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, predicate : (a) -> e bool, (list<a>) -> list<a>) -> e list<a> */ 
  kk__tailcall: ;
  if (kk_std_core__is_Cons(xs0)) {
    struct kk_std_core_Cons* _con24997 = kk_std_core__as_Cons(xs0);
    kk_box_t x2 = _con24997->head;
    kk_std_core__list xx2 = _con24997->tail;
    if (kk_std_core__list_is_unique(xs0)) {
      kk_std_core__list_free(xs0);
    }
    else {
      kk_box_dup(x2);
      kk_std_core__list_dup(xx2);
      kk_std_core__list_decref(xs0, _ctx);
    }
    bool x0_21781;
    kk_function_t _x24999 = kk_function_dup(predicate2); /*(20220) -> 20221 bool*/
    kk_box_t _x24998 = kk_box_dup(x2); /*20220*/
    x0_21781 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_context_t*), _x24999, (_x24999, _x24998, _ctx)); /*bool*/
    if (kk_yielding(kk_context())) {
      kk_box_t _x25000 = kk_std_core_hnd_yield_extend(kk_std_core__new_ctailm_take_while_fun25001(_accm0, predicate2, x2, xx2, _ctx), _ctx); /*3991*/
      return kk_std_core__list_unbox(_x25000, _ctx);
    }
    if (x0_21781) {
      { // tailcall
        kk_function_t _x25004 = kk_std_core__new_ctailm_take_while_fun25005(_accm0, x2, _ctx); /*(list<20220>) -> list<20220>*/
        xs0 = xx2;
        _accm0 = _x25004;
        goto kk__tailcall;
      }
    }
    kk_function_drop(predicate2, _ctx);
    kk_box_drop(x2, _ctx);
    kk_std_core__list_drop(xx2, _ctx);
    return kk_function_call(kk_std_core__list, (kk_function_t, kk_std_core__list, kk_context_t*), _accm0, (_accm0, kk_std_core__new_Nil(_ctx), _ctx));
  }
  kk_function_drop(predicate2, _ctx);
  return kk_function_call(kk_std_core__list, (kk_function_t, kk_std_core__list, kk_context_t*), _accm0, (_accm0, kk_std_core__new_Nil(_ctx), _ctx));
}
 
// Keep only those initial elements that satisfy `predicate`


// lift anonymous function
struct kk_std_core_take_while_fun25007__t {
  struct kk_function_s _base;
};
static kk_std_core__list kk_std_core_take_while_fun25007(kk_function_t _fself, kk_std_core__list _ctail_21155, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_take_while_fun25007(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_take_while_fun25007, _ctx)
  return kk_function_dup(_fself);
}

static kk_std_core__list kk_std_core_take_while_fun25007(kk_function_t _fself, kk_std_core__list _ctail_21155, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return _ctail_21155;
}

kk_std_core__list kk_std_core_take_while(kk_std_core__list xs1, kk_function_t predicate3, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, predicate : (a) -> e bool) -> e list<a> */ 
  bool _match_23445 = kk_std_core_hnd__evv_is_affine(_ctx); /*bool*/;
  if (_match_23445) {
    return kk_std_core__ctail_take_while(xs1, predicate3, kk_std_core_types__new_CTailNil(_ctx), _ctx);
  }
  return kk_std_core__ctailm_take_while(xs1, predicate3, kk_std_core_new_take_while_fun25007(_ctx), _ctx);
}
 
// Trace a message used for debug purposes.
// The behaviour is system dependent. On a browser and node it uses
// `console.log`  by default.
// Disabled if `notrace` is called.

kk_unit_t kk_std_core_trace(kk_string_t message0, kk_context_t* _ctx) { /* (message : string) -> () */ 
  bool _match_23444;
  kk_ref_t _b_23166_23165 = kk_ref_alloc((kk_bool_box(true)),kk_context()); /*ref<global,bool>*/;
  kk_box_t _x25008 = kk_ref_get(_b_23166_23165,kk_context()); /*179*/
  _match_23444 = kk_bool_unbox(_x25008); /*bool*/
  if (_match_23444) {
    kk_std_core_xtrace(message0, _ctx); return kk_Unit;
  }
  kk_string_drop(message0, _ctx);
  kk_Unit; return kk_Unit;
}

kk_unit_t kk_std_core_trace_any(kk_string_t message0, kk_box_t x, kk_context_t* _ctx) { /* forall<a> (message : string, x : a) -> () */ 
  bool _match_23443;
  kk_ref_t _b_23170_23169 = kk_ref_alloc((kk_bool_box(true)),kk_context()); /*ref<global,bool>*/;
  kk_box_t _x25009 = kk_ref_get(_b_23170_23169,kk_context()); /*179*/
  _match_23443 = kk_bool_unbox(_x25009); /*bool*/
  if (_match_23443) {
    kk_std_core_xtrace_any(message0, x, _ctx); return kk_Unit;
  }
  kk_string_drop(message0, _ctx);
  kk_box_drop(x, _ctx);
  kk_Unit; return kk_Unit;
}
 
// Truncate a string to `count` characters.

kk_string_t kk_std_core_truncate(kk_string_t s, kk_integer_t count, kk_context_t* _ctx) { /* (s : string, count : int) -> string */ 
  kk_std_core__sslice _x25010;
  kk_std_core__sslice _x25011;
  kk_std_core__sslice slice0 = kk_std_core_first1(s, _ctx); /*sslice*/;
  bool _match_23440;
  kk_integer_t _x25012;
  kk_std_core_types__optional _x25013 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/
  if (kk_std_core_types__is_Optional(_x25013)) {
    kk_box_t _box_x23172 = _x25013._cons.Optional.value;
    kk_integer_t _n_12425 = kk_integer_unbox(_box_x23172);
    _x25012 = _n_12425; /*int*/
    goto _match25014;
  }
  _x25012 = kk_integer_from_small(1); /*int*/
  _match25014: ;
  _match_23440 = kk_integer_eq(_x25012,(kk_integer_from_small(1)),kk_context()); /*bool*/
  if (_match_23440) {
    _x25011 = slice0; /*sslice*/
  }
  else {
    kk_integer_t _x25016;
    kk_integer_t _x25017;
    kk_std_core_types__optional _x25018 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/
    if (kk_std_core_types__is_Optional(_x25018)) {
      kk_box_t _box_x23173 = _x25018._cons.Optional.value;
      kk_integer_t _n_124250 = kk_integer_unbox(_box_x23173);
      _x25017 = _n_124250; /*int*/
      goto _match25019;
    }
    _x25017 = kk_integer_from_small(1); /*int*/
    _match25019: ;
    _x25016 = kk_integer_sub(_x25017,(kk_integer_from_small(1)),kk_context()); /*int*/
    _x25011 = kk_std_core_extend(slice0, _x25016, _ctx); /*sslice*/
  }
  kk_integer_t _x25021 = kk_integer_sub(count,(kk_integer_from_small(1)),kk_context()); /*int*/
  _x25010 = kk_std_core_extend(_x25011, _x25021, _ctx); /*sslice*/
  return kk_std_core_string_3(_x25010, _ctx);
}
 
// Return a default value when an exception is raised


// lift anonymous function
struct kk_std_core_try_default_fun25024__t {
  struct kk_function_s _base;
  kk_box_t value;
};
static kk_box_t kk_std_core_try_default_fun25024(kk_function_t _fself, kk_std_core_hnd__marker _b_23175, kk_std_core_hnd__ev _b_23176, kk_box_t _b_23177, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_try_default_fun25024(kk_box_t value, kk_context_t* _ctx) {
  struct kk_std_core_try_default_fun25024__t* _self = kk_function_alloc_as(struct kk_std_core_try_default_fun25024__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_try_default_fun25024, kk_context());
  _self->value = value;
  return &_self->_base;
}



// lift anonymous function
struct kk_std_core_try_default_fun25025__t {
  struct kk_function_s _base;
  kk_box_t value;
};
static kk_box_t kk_std_core_try_default_fun25025(kk_function_t _fself, kk_function_t ___wildcard__554__45, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_try_default_fun25025(kk_box_t value, kk_context_t* _ctx) {
  struct kk_std_core_try_default_fun25025__t* _self = kk_function_alloc_as(struct kk_std_core_try_default_fun25025__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_try_default_fun25025, kk_context());
  _self->value = value;
  return &_self->_base;
}

static kk_box_t kk_std_core_try_default_fun25025(kk_function_t _fself, kk_function_t ___wildcard__554__45, kk_context_t* _ctx) {
  struct kk_std_core_try_default_fun25025__t* _self = kk_function_as(struct kk_std_core_try_default_fun25025__t*, _fself);
  kk_box_t value = _self->value; /* 20439 */
  kk_drop_match(_self, {kk_box_dup(value);}, {}, _ctx)
  kk_function_drop(___wildcard__554__45, _ctx);
  return value;
}
static kk_box_t kk_std_core_try_default_fun25024(kk_function_t _fself, kk_std_core_hnd__marker _b_23175, kk_std_core_hnd__ev _b_23176, kk_box_t _b_23177, kk_context_t* _ctx) {
  struct kk_std_core_try_default_fun25024__t* _self = kk_function_as(struct kk_std_core_try_default_fun25024__t*, _fself);
  kk_box_t value = _self->value; /* 20439 */
  kk_drop_match(_self, {kk_box_dup(value);}, {}, _ctx)
  kk_std_core_hnd__ev_dropn(_b_23176, ((int32_t)3), _ctx);
  kk_box_drop(_b_23177, _ctx);
  return kk_std_core_hnd_yield_to_final(_b_23175, kk_std_core_new_try_default_fun25025(value, _ctx), _ctx);
}


// lift anonymous function
struct kk_std_core_try_default_fun25026__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_try_default_fun25026(kk_function_t _fself, kk_box_t _x, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_try_default_fun25026(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_try_default_fun25026, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_core_try_default_fun25026(kk_function_t _fself, kk_box_t _x, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return _x;
}

kk_box_t kk_std_core_try_default(kk_box_t value, kk_function_t action, kk_context_t* _ctx) { /* forall<a,e> (value : a, action : () -> <exn|e> a) -> e a */ 
  kk_std_core__hnd_exn _x25022;
  kk_std_core_hnd__clause1 _x25023 = kk_std_core_hnd__new_Clause1(kk_std_core_new_try_default_fun25024(value, _ctx), _ctx); /*std/core/hnd/clause1<52,53,54,55,56>*/
  _x25022 = kk_std_core__new_Hnd_exn(kk_reuse_null, _x25023, _ctx); /*.hnd-exn<11,12>*/
  return kk_std_core__handle_exn(((int32_t)0), _x25022, kk_std_core_new_try_default_fun25026(_ctx), action, _ctx);
}
 
// Returns a unique integer (modulo 32-bits).

kk_integer_t kk_std_core_unique(kk_context_t* _ctx) { /* () -> ndet int */ 
  kk_integer_t u;
  kk_box_t _x25027;
  kk_ref_t _x25028 = kk_ref_dup(kk_std_core_unique_count); /*ref<global,int>*/
  _x25027 = kk_ref_get(_x25028,kk_context()); /*179*/
  u = kk_integer_unbox(_x25027); /*int*/
  kk_unit_t __ = kk_Unit;
  kk_integer_t _b_23187_23185;
  kk_integer_t _x25029 = kk_integer_dup(u); /*int*/
  _b_23187_23185 = kk_integer_add(_x25029,(kk_integer_from_small(1)),kk_context()); /*int*/
  kk_ref_t _x25030 = kk_ref_dup(kk_std_core_unique_count); /*ref<global,int>*/
  kk_ref_set(_x25030,(kk_integer_box(_b_23187_23185)),kk_context());
  return u;
}
 
// Get the value of the `Just` constructor or raise an exception

kk_box_t kk_std_core_unjust(kk_std_core_types__maybe m, kk_context_t* _ctx) { /* forall<a> (m : maybe<a>) -> exn a */ 
  if (kk_std_core_types__is_Just(m)) {
    kk_box_t x = m._cons.Just.value;
    return x;
  }
  kk_std_core__exception exn_21794;
  kk_string_t _x25031;
  kk_define_string_literal(, _s25032, 37, "unexpected Nothing in std/core/unjust")
  _x25031 = kk_string_dup(_s25032); /*string*/
  kk_std_core__exception_info _x25033;
  kk_std_core_types__optional _x25034 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/
  if (kk_std_core_types__is_Optional(_x25034)) {
    kk_box_t _box_x23188 = _x25034._cons.Optional.value;
    kk_std_core__exception_info _info_14279 = kk_std_core__exception_info_unbox(_box_x23188, NULL);
    _x25033 = _info_14279; /*exception-info*/
    goto _match25035;
  }
  _x25033 = kk_std_core__new_ExnError(_ctx); /*exception-info*/
  _match25035: ;
  exn_21794 = kk_std_core__new_Exception(_x25031, _x25033, _ctx); /*exception*/
  kk_std_core_hnd__ev ev_21795;
  size_t _x25037 = ((size_t)0); /*size_t*/
  ev_21795 = kk_evv_at(_x25037,kk_context()); /*std/core/hnd/ev<.hnd-exn>*/
  struct kk_std_core_hnd_Ev* _con25038 = kk_std_core_hnd__as_Ev(ev_21795);
  kk_std_core_hnd__marker m0 = _con25038->marker;
  kk_box_t _box_x23189 = _con25038->hnd;
  kk_std_core__hnd_exn h = kk_std_core__hnd_exn_unbox(_box_x23189, NULL);
  kk_std_core__hnd_exn_dup(h);
  kk_std_core_hnd__clause1 _match_23438;
  struct kk_std_core__Hnd_exn* _con25040 = kk_std_core__as_Hnd_exn(h);
  kk_std_core_hnd__clause1 except_throw_exn = _con25040->except_throw_exn;
  if (kk_std_core__hnd_exn_is_unique(h)) {
    kk_std_core__hnd_exn_free(h);
  }
  else {
    kk_std_core_hnd__clause1_dup(except_throw_exn);
    kk_std_core__hnd_exn_decref(h, _ctx);
  }
  _match_23438 = except_throw_exn; /*forall<a> std/core/hnd/clause1<exception,a,.hnd-exn,3528,3529>*/
  kk_function_t _fun_unbox_x23193 = _match_23438.clause;
  return kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x23193, (_fun_unbox_x23193, m0, ev_21795, kk_std_core__exception_box(exn_21794, _ctx), _ctx));
}
 
// Join a list of strings with newlines

kk_string_t kk_std_core_unlines(kk_std_core__list xs, kk_context_t* _ctx) { /* (xs : list<string>) -> string */ 
  if (kk_std_core__is_Nil(xs)) {
    return kk_string_empty();
  }
  struct kk_std_core_Cons* _con25042 = kk_std_core__as_Cons(xs);
  kk_box_t _box_x23200 = _con25042->head;
  kk_std_core__list xx = _con25042->tail;
  kk_string_t x = kk_string_unbox(_box_x23200);
  if (kk_std_core__list_is_unique(xs)) {
    kk_std_core__list_free(xs);
  }
  else {
    kk_string_dup(x);
    kk_std_core__list_dup(xx);
    kk_std_core__list_decref(xs, _ctx);
  }
  kk_string_t _x25044;
  kk_define_string_literal(, _s25045, 1, "\n")
  _x25044 = kk_string_dup(_s25045); /*string*/
  return kk_std_core__lift21050_joinsep(_x25044, xx, x, _ctx);
}
 
// lift

kk_std_core_types__tuple2_ kk_std_core__lift21061_unzip(kk_std_core__list ys, kk_std_core__list acc1, kk_std_core__list acc2, kk_context_t* _ctx) { /* forall<a,b> (ys : list<(a, b)>, acc1 : list<a>, acc2 : list<b>) -> (list<a>, list<b>) */ 
  kk__tailcall: ;
  if (kk_std_core__is_Cons(ys)) {
    struct kk_std_core_Cons* _con25046 = kk_std_core__as_Cons(ys);
    kk_box_t _box_x23201 = _con25046->head;
    kk_std_core__list xx = _con25046->tail;
    kk_std_core_types__tuple2_ _pat0 = kk_std_core_types__tuple2__unbox(_box_x23201, NULL);
    kk_box_t x = _pat0.fst;
    kk_box_t y = _pat0.snd;
    kk_reuse_t _ru_23417 = kk_reuse_null; /*reuse*/;
    if (kk_std_core__list_is_unique(ys)) {
      kk_box_dup(x);
      kk_box_dup(y);
      kk_box_drop(_box_x23201, _ctx);
      _ru_23417 = (kk_std_core__list_reuse(ys));
    }
    else {
      kk_box_dup(x);
      kk_std_core__list_dup(xx);
      kk_box_dup(y);
      kk_std_core__list_decref(ys, _ctx);
      _ru_23417 = kk_reuse_null;
    }
    { // tailcall
      kk_std_core__list _x25048 = kk_std_core__new_Cons(_ru_23417, x, acc1, _ctx); /*list<61>*/
      kk_std_core__list _x25049 = kk_std_core__new_Cons(kk_reuse_null, y, acc2, _ctx); /*list<61>*/
      ys = xx;
      acc1 = _x25048;
      acc2 = _x25049;
      goto kk__tailcall;
    }
  }
  kk_std_core__list _b_23204_23202 = kk_std_core_reverse(acc1, _ctx); /*list<20592>*/;
  kk_std_core__list _b_23205_23203 = kk_std_core_reverse(acc2, _ctx); /*list<20593>*/;
  return kk_std_core_types__new_dash__lp__comma__rp_(kk_std_core__list_box(_b_23204_23202, _ctx), kk_std_core__list_box(_b_23205_23203, _ctx), _ctx);
}
 
// Convert a string to a vector of characters.

kk_vector_t kk_std_core_vector_1(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> vector<char> */ 
  return kk_string_to_chars(s,kk_context());
}
extern kk_box_t kk_std_core_vector_fun25051_2(kk_function_t _fself, size_t ___wildcard__2034__29, kk_context_t* _ctx) {
  struct kk_std_core_vector_fun25051__t_2* _self = kk_function_as(struct kk_std_core_vector_fun25051__t_2*, _fself);
  kk_box_t default0 = _self->default0; /* 20671 */
  kk_drop_match(_self, {kk_box_dup(default0);}, {}, _ctx)
  return default0;
}
extern kk_box_t kk_std_core_vector_init_fun25054(kk_function_t _fself, size_t i, kk_context_t* _ctx) {
  struct kk_std_core_vector_init_fun25054__t* _self = kk_function_as(struct kk_std_core_vector_init_fun25054__t*, _fself);
  kk_function_t f = _self->f; /* (int) -> 20759 */
  kk_drop_match(_self, {kk_function_dup(f);}, {}, _ctx)
  kk_integer_t _x25055 = kk_integer_from_size_t(i,kk_context()); /*int*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_context_t*), f, (f, _x25055, _ctx));
}
 
// monadic lift

kk_unit_t kk_std_core__mlift21224_while(kk_function_t action, kk_function_t predicate, kk_unit_t wild__, kk_context_t* _ctx) { /* forall<e> (action : () -> <div|e> (), predicate : () -> <div|e> bool, wild_ : ()) -> <div|e> () */ 
  kk_std_core_while(predicate, action, _ctx); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_std_core__mlift21225_while_fun25058__t {
  struct kk_function_s _base;
  kk_function_t action0;
  kk_function_t predicate0;
};
static kk_box_t kk_std_core__mlift21225_while_fun25058(kk_function_t _fself, kk_box_t _b_23207, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_mlift21225_while_fun25058(kk_function_t action0, kk_function_t predicate0, kk_context_t* _ctx) {
  struct kk_std_core__mlift21225_while_fun25058__t* _self = kk_function_alloc_as(struct kk_std_core__mlift21225_while_fun25058__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__mlift21225_while_fun25058, kk_context());
  _self->action0 = action0;
  _self->predicate0 = predicate0;
  return &_self->_base;
}

static kk_box_t kk_std_core__mlift21225_while_fun25058(kk_function_t _fself, kk_box_t _b_23207, kk_context_t* _ctx) {
  struct kk_std_core__mlift21225_while_fun25058__t* _self = kk_function_as(struct kk_std_core__mlift21225_while_fun25058__t*, _fself);
  kk_function_t action0 = _self->action0; /* () -> <div|20780> () */
  kk_function_t predicate0 = _self->predicate0; /* () -> <div|20780> bool */
  kk_drop_match(_self, {kk_function_dup(action0);kk_function_dup(predicate0);}, {}, _ctx)
  kk_unit_t _x25059 = kk_Unit;
  kk_unit_t _x25060 = kk_Unit;
  kk_unit_unbox(_b_23207);
  kk_std_core__mlift21224_while(action0, predicate0, _x25060, _ctx);
  return kk_unit_box(_x25059);
}

kk_unit_t kk_std_core__mlift21225_while(kk_function_t action0, kk_function_t predicate0, bool _y_245, kk_context_t* _ctx) { /* forall<e> (action : () -> <div|e> (), predicate : () -> <div|e> bool, bool) -> <div|e> () */ 
  if (_y_245) {
    kk_unit_t x_21800 = kk_Unit;
    kk_function_t _x25056 = kk_function_dup(action0); /*() -> <div|20780> ()*/
    kk_function_call(kk_unit_t, (kk_function_t, kk_context_t*), _x25056, (_x25056, _ctx));
    if (kk_yielding(kk_context())) {
      kk_box_t _x25057 = kk_std_core_hnd_yield_extend(kk_std_core__new_mlift21225_while_fun25058(action0, predicate0, _ctx), _ctx); /*3991*/
      kk_unit_unbox(_x25057); return kk_Unit;
    }
    kk_std_core__mlift21224_while(action0, predicate0, x_21800, _ctx); return kk_Unit;
  }
  kk_function_drop(action0, _ctx);
  kk_function_drop(predicate0, _ctx);
  kk_Unit; return kk_Unit;
}
 
// The `while` fun executes `action`  as long as `pred`  is `true`.


// lift anonymous function
struct kk_std_core_while_fun25063__t {
  struct kk_function_s _base;
  kk_function_t action1;
  kk_function_t predicate1;
};
static kk_box_t kk_std_core_while_fun25063(kk_function_t _fself, kk_box_t _b_23211, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_while_fun25063(kk_function_t action1, kk_function_t predicate1, kk_context_t* _ctx) {
  struct kk_std_core_while_fun25063__t* _self = kk_function_alloc_as(struct kk_std_core_while_fun25063__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_while_fun25063, kk_context());
  _self->action1 = action1;
  _self->predicate1 = predicate1;
  return &_self->_base;
}

static kk_box_t kk_std_core_while_fun25063(kk_function_t _fself, kk_box_t _b_23211, kk_context_t* _ctx) {
  struct kk_std_core_while_fun25063__t* _self = kk_function_as(struct kk_std_core_while_fun25063__t*, _fself);
  kk_function_t action1 = _self->action1; /* () -> <div|20780> () */
  kk_function_t predicate1 = _self->predicate1; /* () -> <div|20780> bool */
  kk_drop_match(_self, {kk_function_dup(action1);kk_function_dup(predicate1);}, {}, _ctx)
  kk_unit_t _x25064 = kk_Unit;
  bool _x25065 = kk_bool_unbox(_b_23211); /*bool*/
  kk_std_core__mlift21225_while(action1, predicate1, _x25065, _ctx);
  return kk_unit_box(_x25064);
}


// lift anonymous function
struct kk_std_core_while_fun25068__t {
  struct kk_function_s _base;
  kk_function_t action1;
  kk_function_t predicate1;
};
static kk_box_t kk_std_core_while_fun25068(kk_function_t _fself, kk_box_t _b_23213, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_while_fun25068(kk_function_t action1, kk_function_t predicate1, kk_context_t* _ctx) {
  struct kk_std_core_while_fun25068__t* _self = kk_function_alloc_as(struct kk_std_core_while_fun25068__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_while_fun25068, kk_context());
  _self->action1 = action1;
  _self->predicate1 = predicate1;
  return &_self->_base;
}

static kk_box_t kk_std_core_while_fun25068(kk_function_t _fself, kk_box_t _b_23213, kk_context_t* _ctx) {
  struct kk_std_core_while_fun25068__t* _self = kk_function_as(struct kk_std_core_while_fun25068__t*, _fself);
  kk_function_t action1 = _self->action1; /* () -> <div|20780> () */
  kk_function_t predicate1 = _self->predicate1; /* () -> <div|20780> bool */
  kk_drop_match(_self, {kk_function_dup(action1);kk_function_dup(predicate1);}, {}, _ctx)
  kk_unit_t _x25069 = kk_Unit;
  kk_unit_t _x25070 = kk_Unit;
  kk_unit_unbox(_b_23213);
  kk_std_core__mlift21224_while(action1, predicate1, _x25070, _ctx);
  return kk_unit_box(_x25069);
}

kk_unit_t kk_std_core_while(kk_function_t predicate1, kk_function_t action1, kk_context_t* _ctx) { /* forall<e> (predicate : () -> <div|e> bool, action : () -> <div|e> ()) -> <div|e> () */ 
  kk__tailcall: ;
  bool x_21802;
  kk_function_t _x25061 = kk_function_dup(predicate1); /*() -> <div|20780> bool*/
  x_21802 = kk_function_call(bool, (kk_function_t, kk_context_t*), _x25061, (_x25061, _ctx)); /*bool*/
  if (kk_yielding(kk_context())) {
    kk_box_t _x25062 = kk_std_core_hnd_yield_extend(kk_std_core_new_while_fun25063(action1, predicate1, _ctx), _ctx); /*3991*/
    kk_unit_unbox(_x25062); return kk_Unit;
  }
  if (x_21802) {
    kk_unit_t x0_21806 = kk_Unit;
    kk_function_t _x25066 = kk_function_dup(action1); /*() -> <div|20780> ()*/
    kk_function_call(kk_unit_t, (kk_function_t, kk_context_t*), _x25066, (_x25066, _ctx));
    if (kk_yielding(kk_context())) {
      kk_box_t _x25067 = kk_std_core_hnd_yield_extend(kk_std_core_new_while_fun25068(action1, predicate1, _ctx), _ctx); /*3991*/
      kk_unit_unbox(_x25067); return kk_Unit;
    }
    { // tailcall
      goto kk__tailcall;
    }
  }
  kk_function_drop(action1, _ctx);
  kk_function_drop(predicate1, _ctx);
  kk_Unit; return kk_Unit;
}
 
// Zip two lists together by pairing the corresponding elements.
// The returned list is only as long as the smallest input list.

kk_std_core__list kk_std_core__ctail_zip(kk_std_core__list xs, kk_std_core__list ys, kk_std_core_types__ctail _acc, kk_context_t* _ctx) { /* forall<a,b> (xs : list<a>, ys : list<b>, ctail<list<(a, b)>>) -> list<(a, b)> */ 
  kk__tailcall: ;
  if (kk_std_core__is_Cons(xs)) {
    struct kk_std_core_Cons* _con25071 = kk_std_core__as_Cons(xs);
    kk_box_t x = _con25071->head;
    kk_std_core__list xx = _con25071->tail;
    if (kk_std_core__list_is_unique(xs)) {
      kk_std_core__list_free(xs);
    }
    else {
      kk_box_dup(x);
      kk_std_core__list_dup(xx);
      kk_std_core__list_decref(xs, _ctx);
    }
    if (kk_std_core__is_Cons(ys)) {
      struct kk_std_core_Cons* _con25072 = kk_std_core__as_Cons(ys);
      kk_box_t y = _con25072->head;
      kk_std_core__list yy = _con25072->tail;
      kk_reuse_t _ru_23419 = kk_reuse_null; /*reuse*/;
      if (kk_std_core__list_is_unique(ys)) {
        _ru_23419 = (kk_std_core__list_reuse(ys));
      }
      else {
        kk_box_dup(y);
        kk_std_core__list_dup(yy);
        kk_std_core__list_decref(ys, _ctx);
        _ru_23419 = kk_reuse_null;
      }
      kk_std_core_types__tuple2_ _ctail_21157 = kk_std_core_types__new_dash__lp__comma__rp_(x, y, _ctx); /*(20823, 20824)*/;
      kk_std_core__list _ctail_21158 = kk_std_core__list_hole(); /*list<(20823, 20824)>*/;
      kk_std_core__list _ctail_21159 = kk_std_core__new_Cons(_ru_23419, kk_std_core_types__tuple2__box(_ctail_21157, _ctx), _ctail_21158, _ctx); /*list<(20823, 20824)>*/;
      { // tailcall
        kk_std_core_types__ctail _x25073;
        kk_box_t* field_21812 = (kk_box_t*)((&kk_std_core__as_Cons(_ctail_21159)->tail)); /*cfield<list<(20823, 20824)>>*/;
        if (kk_std_core_types__is_CTail(_acc)) {
          kk_box_t _box_x23228 = _acc._cons.CTail._field1;
          kk_box_t* last0 = _acc._cons.CTail._field2;
          kk_std_core__list head0 = kk_std_core__list_unbox(_box_x23228, NULL);
          kk_unit_t __ = kk_Unit;
          *(last0) = kk_std_core__list_box(_ctail_21159, _ctx);
          _x25073 = kk_std_core_types__new_CTail(kk_std_core__list_box(head0, _ctx), field_21812, _ctx); /*ctail<58>*/
          goto _match25074;
        }
        _x25073 = kk_std_core_types__new_CTail(kk_std_core__list_box(_ctail_21159, _ctx), field_21812, _ctx); /*ctail<58>*/
        _match25074: ;
        xs = xx;
        ys = yy;
        _acc = _x25073;
        goto kk__tailcall;
      }
    }
    kk_box_drop(x, _ctx);
    kk_std_core__list_drop(xx, _ctx);
    if (kk_std_core_types__is_CTail(_acc)) {
      kk_box_t _box_x23237 = _acc._cons.CTail._field1;
      kk_box_t* last00 = _acc._cons.CTail._field2;
      kk_std_core__list head00 = kk_std_core__list_unbox(_box_x23237, NULL);
      kk_unit_t __0 = kk_Unit;
      *(last00) = kk_std_core__list_box(kk_std_core__new_Nil(_ctx), _ctx);
      return head00;
    }
    return kk_std_core__new_Nil(_ctx);
  }
  kk_std_core__list_drop(ys, _ctx);
  if (kk_std_core_types__is_CTail(_acc)) {
    kk_box_t _box_x23242 = _acc._cons.CTail._field1;
    kk_box_t* last10 = _acc._cons.CTail._field2;
    kk_std_core__list head1 = kk_std_core__list_unbox(_box_x23242, NULL);
    kk_unit_t __1 = kk_Unit;
    *(last10) = kk_std_core__list_box(kk_std_core__new_Nil(_ctx), _ctx);
    return head1;
  }
  return kk_std_core__new_Nil(_ctx);
}
 
// Zip two lists together by pairing the corresponding elements.
// The returned list is only as long as the smallest input list.

kk_std_core__list kk_std_core_zip(kk_std_core__list xs0, kk_std_core__list ys0, kk_context_t* _ctx) { /* forall<a,b> (xs : list<a>, ys : list<b>) -> list<(a, b)> */ 
  return kk_std_core__ctail_zip(xs0, ys0, kk_std_core_types__new_CTailNil(_ctx), _ctx);
}
 
// monadic lift

kk_std_core__list kk_std_core__mlift21226_op(kk_std_core_types__ctail _acc, kk_function_t f, kk_std_core__list xx, kk_std_core__list yy, kk_box_t _ctail_21160, kk_context_t* _ctx) { /* forall<a,b,c,e> (ctail<list<c>>, f : (a, b) -> e c, xx : list<a>, yy : list<b>, c) -> e list<c> */ 
  kk_std_core__list _ctail_21161 = kk_std_core__list_hole(); /*list<20871>*/;
  kk_std_core__list _ctail_21162 = kk_std_core__new_Cons(kk_reuse_null, _ctail_21160, _ctail_21161, _ctx); /*list<20871>*/;
  kk_std_core_types__ctail _x25078;
  kk_box_t* field_21819 = (kk_box_t*)((&kk_std_core__as_Cons(_ctail_21162)->tail)); /*cfield<list<20871>>*/;
  if (kk_std_core_types__is_CTail(_acc)) {
    kk_box_t _box_x23257 = _acc._cons.CTail._field1;
    kk_box_t* last0 = _acc._cons.CTail._field2;
    kk_std_core__list head0 = kk_std_core__list_unbox(_box_x23257, NULL);
    kk_unit_t __ = kk_Unit;
    *(last0) = kk_std_core__list_box(_ctail_21162, _ctx);
    _x25078 = kk_std_core_types__new_CTail(kk_std_core__list_box(head0, _ctx), field_21819, _ctx); /*ctail<58>*/
    goto _match25079;
  }
  _x25078 = kk_std_core_types__new_CTail(kk_std_core__list_box(_ctail_21162, _ctx), field_21819, _ctx); /*ctail<58>*/
  _match25079: ;
  return kk_std_core__ctail_zipwith(xx, yy, f, _x25078, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_core__mlift21227_op_fun25081__t {
  struct kk_function_s _base;
  kk_function_t _accm;
  kk_box_t _ctail_21165;
};
static kk_std_core__list kk_std_core__mlift21227_op_fun25081(kk_function_t _fself, kk_std_core__list _ctail_21164, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_mlift21227_op_fun25081(kk_function_t _accm, kk_box_t _ctail_21165, kk_context_t* _ctx) {
  struct kk_std_core__mlift21227_op_fun25081__t* _self = kk_function_alloc_as(struct kk_std_core__mlift21227_op_fun25081__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__mlift21227_op_fun25081, kk_context());
  _self->_accm = _accm;
  _self->_ctail_21165 = _ctail_21165;
  return &_self->_base;
}

static kk_std_core__list kk_std_core__mlift21227_op_fun25081(kk_function_t _fself, kk_std_core__list _ctail_21164, kk_context_t* _ctx) {
  struct kk_std_core__mlift21227_op_fun25081__t* _self = kk_function_as(struct kk_std_core__mlift21227_op_fun25081__t*, _fself);
  kk_function_t _accm = _self->_accm; /* (list<20871>) -> list<20871> */
  kk_box_t _ctail_21165 = _self->_ctail_21165; /* 20871 */
  kk_drop_match(_self, {kk_function_dup(_accm);kk_box_dup(_ctail_21165);}, {}, _ctx)
  kk_std_core__list _x25082 = kk_std_core__new_Cons(kk_reuse_null, _ctail_21165, _ctail_21164, _ctx); /*list<61>*/
  return kk_function_call(kk_std_core__list, (kk_function_t, kk_std_core__list, kk_context_t*), _accm, (_accm, _x25082, _ctx));
}

kk_std_core__list kk_std_core__mlift21227_op(kk_function_t _accm, kk_function_t f0, kk_std_core__list xx0, kk_std_core__list yy0, kk_box_t _ctail_21165, kk_context_t* _ctx) { /* forall<a,b,c,e> ((list<c>) -> list<c>, f : (a, b) -> e c, xx : list<a>, yy : list<b>, c) -> e list<c> */ 
  return kk_std_core__ctailm_zipwith(xx0, yy0, f0, kk_std_core__new_mlift21227_op_fun25081(_accm, _ctail_21165, _ctx), _ctx);
}
 
// Zip two lists together by apply a function `f` to all corresponding elements.
// The returned list is only as long as the smallest input list.


// lift anonymous function
struct kk_std_core__ctail_zipwith_fun25087__t {
  struct kk_function_s _base;
  kk_function_t f1;
  kk_std_core__list xx1;
  kk_std_core__list yy1;
  kk_std_core_types__ctail _acc0;
};
static kk_box_t kk_std_core__ctail_zipwith_fun25087(kk_function_t _fself, kk_box_t _b_23271, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_ctail_zipwith_fun25087(kk_function_t f1, kk_std_core__list xx1, kk_std_core__list yy1, kk_std_core_types__ctail _acc0, kk_context_t* _ctx) {
  struct kk_std_core__ctail_zipwith_fun25087__t* _self = kk_function_alloc_as(struct kk_std_core__ctail_zipwith_fun25087__t, 6, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__ctail_zipwith_fun25087, kk_context());
  _self->f1 = f1;
  _self->xx1 = xx1;
  _self->yy1 = yy1;
  _self->_acc0 = _acc0;
  return &_self->_base;
}

static kk_box_t kk_std_core__ctail_zipwith_fun25087(kk_function_t _fself, kk_box_t _b_23271, kk_context_t* _ctx) {
  struct kk_std_core__ctail_zipwith_fun25087__t* _self = kk_function_as(struct kk_std_core__ctail_zipwith_fun25087__t*, _fself);
  kk_function_t f1 = _self->f1; /* (20869, 20870) -> 20872 20871 */
  kk_std_core__list xx1 = _self->xx1; /* list<20869> */
  kk_std_core__list yy1 = _self->yy1; /* list<20870> */
  kk_std_core_types__ctail _acc0 = _self->_acc0; /* ctail<list<20871>> */
  kk_drop_match(_self, {kk_function_dup(f1);kk_std_core__list_dup(xx1);kk_std_core__list_dup(yy1);kk_std_core_types__ctail_dup(_acc0);}, {}, _ctx)
  kk_std_core__list _x25088 = kk_std_core__mlift21226_op(_acc0, f1, xx1, yy1, _b_23271, _ctx); /*list<20871>*/
  return kk_std_core__list_box(_x25088, _ctx);
}

kk_std_core__list kk_std_core__ctail_zipwith(kk_std_core__list xs, kk_std_core__list ys, kk_function_t f1, kk_std_core_types__ctail _acc0, kk_context_t* _ctx) { /* forall<a,b,c,e> (xs : list<a>, ys : list<b>, f : (a, b) -> e c, ctail<list<c>>) -> e list<c> */ 
  kk__tailcall: ;
  if (kk_std_core__is_Cons(xs)) {
    struct kk_std_core_Cons* _con25083 = kk_std_core__as_Cons(xs);
    kk_box_t x = _con25083->head;
    kk_std_core__list xx1 = _con25083->tail;
    if (kk_std_core__list_is_unique(xs)) {
      kk_std_core__list_free(xs);
    }
    else {
      kk_box_dup(x);
      kk_std_core__list_dup(xx1);
      kk_std_core__list_decref(xs, _ctx);
    }
    if (kk_std_core__is_Cons(ys)) {
      struct kk_std_core_Cons* _con25084 = kk_std_core__as_Cons(ys);
      kk_box_t y = _con25084->head;
      kk_std_core__list yy1 = _con25084->tail;
      kk_reuse_t _ru_23421 = kk_reuse_null; /*reuse*/;
      if (kk_std_core__list_is_unique(ys)) {
        _ru_23421 = (kk_std_core__list_reuse(ys));
      }
      else {
        kk_box_dup(y);
        kk_std_core__list_dup(yy1);
        kk_std_core__list_decref(ys, _ctx);
        _ru_23421 = kk_reuse_null;
      }
      kk_box_t x0_21820;
      kk_function_t _x25085 = kk_function_dup(f1); /*(20869, 20870) -> 20872 20871*/
      x0_21820 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _x25085, (_x25085, x, y, _ctx)); /*20871*/
      if (kk_yielding(kk_context())) {
        kk_reuse_drop(_ru_23421, _ctx);
        kk_box_drop(x0_21820, _ctx);
        kk_box_t _x25086 = kk_std_core_hnd_yield_extend(kk_std_core__new_ctail_zipwith_fun25087(f1, xx1, yy1, _acc0, _ctx), _ctx); /*3991*/
        return kk_std_core__list_unbox(_x25086, _ctx);
      }
      kk_std_core__list _ctail_211610 = kk_std_core__list_hole(); /*list<20871>*/;
      kk_std_core__list _ctail_211620 = kk_std_core__new_Cons(_ru_23421, x0_21820, _ctail_211610, _ctx); /*list<20871>*/;
      { // tailcall
        kk_std_core_types__ctail _x25089;
        kk_box_t* field_21826 = (kk_box_t*)((&kk_std_core__as_Cons(_ctail_211620)->tail)); /*cfield<list<20871>>*/;
        if (kk_std_core_types__is_CTail(_acc0)) {
          kk_box_t _box_x23278 = _acc0._cons.CTail._field1;
          kk_box_t* last2 = _acc0._cons.CTail._field2;
          kk_std_core__list head1 = kk_std_core__list_unbox(_box_x23278, NULL);
          kk_unit_t __0 = kk_Unit;
          *(last2) = kk_std_core__list_box(_ctail_211620, _ctx);
          _x25089 = kk_std_core_types__new_CTail(kk_std_core__list_box(head1, _ctx), field_21826, _ctx); /*ctail<58>*/
          goto _match25090;
        }
        _x25089 = kk_std_core_types__new_CTail(kk_std_core__list_box(_ctail_211620, _ctx), field_21826, _ctx); /*ctail<58>*/
        _match25090: ;
        xs = xx1;
        ys = yy1;
        _acc0 = _x25089;
        goto kk__tailcall;
      }
    }
    kk_function_drop(f1, _ctx);
    kk_box_drop(x, _ctx);
    kk_std_core__list_drop(xx1, _ctx);
    if (kk_std_core_types__is_CTail(_acc0)) {
      kk_box_t _box_x23287 = _acc0._cons.CTail._field1;
      kk_box_t* last00 = _acc0._cons.CTail._field2;
      kk_std_core__list head00 = kk_std_core__list_unbox(_box_x23287, NULL);
      kk_unit_t __00 = kk_Unit;
      *(last00) = kk_std_core__list_box(kk_std_core__new_Nil(_ctx), _ctx);
      return head00;
    }
    return kk_std_core__new_Nil(_ctx);
  }
  kk_function_drop(f1, _ctx);
  kk_std_core__list_drop(ys, _ctx);
  if (kk_std_core_types__is_CTail(_acc0)) {
    kk_box_t _box_x23292 = _acc0._cons.CTail._field1;
    kk_box_t* last10 = _acc0._cons.CTail._field2;
    kk_std_core__list head10 = kk_std_core__list_unbox(_box_x23292, NULL);
    kk_unit_t __1 = kk_Unit;
    *(last10) = kk_std_core__list_box(kk_std_core__new_Nil(_ctx), _ctx);
    return head10;
  }
  return kk_std_core__new_Nil(_ctx);
}
 
// Zip two lists together by apply a function `f` to all corresponding elements.
// The returned list is only as long as the smallest input list.


// lift anonymous function
struct kk_std_core__ctailm_zipwith_fun25098__t {
  struct kk_function_s _base;
  kk_function_t _accm0;
  kk_function_t f2;
  kk_std_core__list xx2;
  kk_std_core__list yy2;
};
static kk_box_t kk_std_core__ctailm_zipwith_fun25098(kk_function_t _fself, kk_box_t _b_23304, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_ctailm_zipwith_fun25098(kk_function_t _accm0, kk_function_t f2, kk_std_core__list xx2, kk_std_core__list yy2, kk_context_t* _ctx) {
  struct kk_std_core__ctailm_zipwith_fun25098__t* _self = kk_function_alloc_as(struct kk_std_core__ctailm_zipwith_fun25098__t, 5, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__ctailm_zipwith_fun25098, kk_context());
  _self->_accm0 = _accm0;
  _self->f2 = f2;
  _self->xx2 = xx2;
  _self->yy2 = yy2;
  return &_self->_base;
}

static kk_box_t kk_std_core__ctailm_zipwith_fun25098(kk_function_t _fself, kk_box_t _b_23304, kk_context_t* _ctx) {
  struct kk_std_core__ctailm_zipwith_fun25098__t* _self = kk_function_as(struct kk_std_core__ctailm_zipwith_fun25098__t*, _fself);
  kk_function_t _accm0 = _self->_accm0; /* (list<20871>) -> list<20871> */
  kk_function_t f2 = _self->f2; /* (20869, 20870) -> 20872 20871 */
  kk_std_core__list xx2 = _self->xx2; /* list<20869> */
  kk_std_core__list yy2 = _self->yy2; /* list<20870> */
  kk_drop_match(_self, {kk_function_dup(_accm0);kk_function_dup(f2);kk_std_core__list_dup(xx2);kk_std_core__list_dup(yy2);}, {}, _ctx)
  kk_std_core__list _x25099 = kk_std_core__mlift21227_op(_accm0, f2, xx2, yy2, _b_23304, _ctx); /*list<20871>*/
  return kk_std_core__list_box(_x25099, _ctx);
}


// lift anonymous function
struct kk_std_core__ctailm_zipwith_fun25101__t {
  struct kk_function_s _base;
  kk_function_t _accm0;
  kk_box_t x0_21831;
};
static kk_std_core__list kk_std_core__ctailm_zipwith_fun25101(kk_function_t _fself, kk_std_core__list _ctail_211640, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_ctailm_zipwith_fun25101(kk_function_t _accm0, kk_box_t x0_21831, kk_context_t* _ctx) {
  struct kk_std_core__ctailm_zipwith_fun25101__t* _self = kk_function_alloc_as(struct kk_std_core__ctailm_zipwith_fun25101__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__ctailm_zipwith_fun25101, kk_context());
  _self->_accm0 = _accm0;
  _self->x0_21831 = x0_21831;
  return &_self->_base;
}

static kk_std_core__list kk_std_core__ctailm_zipwith_fun25101(kk_function_t _fself, kk_std_core__list _ctail_211640, kk_context_t* _ctx) {
  struct kk_std_core__ctailm_zipwith_fun25101__t* _self = kk_function_as(struct kk_std_core__ctailm_zipwith_fun25101__t*, _fself);
  kk_function_t _accm0 = _self->_accm0; /* (list<20871>) -> list<20871> */
  kk_box_t x0_21831 = _self->x0_21831; /* 20871 */
  kk_drop_match(_self, {kk_function_dup(_accm0);kk_box_dup(x0_21831);}, {}, _ctx)
  kk_std_core__list _x25102 = kk_std_core__new_Cons(kk_reuse_null, x0_21831, _ctail_211640, _ctx); /*list<61>*/
  return kk_function_call(kk_std_core__list, (kk_function_t, kk_std_core__list, kk_context_t*), _accm0, (_accm0, _x25102, _ctx));
}

kk_std_core__list kk_std_core__ctailm_zipwith(kk_std_core__list xs0, kk_std_core__list ys0, kk_function_t f2, kk_function_t _accm0, kk_context_t* _ctx) { /* forall<a,b,c,e> (xs : list<a>, ys : list<b>, f : (a, b) -> e c, (list<c>) -> list<c>) -> e list<c> */ 
  kk__tailcall: ;
  if (kk_std_core__is_Cons(xs0)) {
    struct kk_std_core_Cons* _con25094 = kk_std_core__as_Cons(xs0);
    kk_box_t x0 = _con25094->head;
    kk_std_core__list xx2 = _con25094->tail;
    if (kk_std_core__list_is_unique(xs0)) {
      kk_std_core__list_free(xs0);
    }
    else {
      kk_box_dup(x0);
      kk_std_core__list_dup(xx2);
      kk_std_core__list_decref(xs0, _ctx);
    }
    if (kk_std_core__is_Cons(ys0)) {
      struct kk_std_core_Cons* _con25095 = kk_std_core__as_Cons(ys0);
      kk_box_t y0 = _con25095->head;
      kk_std_core__list yy2 = _con25095->tail;
      if (kk_std_core__list_is_unique(ys0)) {
        kk_std_core__list_free(ys0);
      }
      else {
        kk_box_dup(y0);
        kk_std_core__list_dup(yy2);
        kk_std_core__list_decref(ys0, _ctx);
      }
      kk_box_t x0_21831;
      kk_function_t _x25096 = kk_function_dup(f2); /*(20869, 20870) -> 20872 20871*/
      x0_21831 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _x25096, (_x25096, x0, y0, _ctx)); /*20871*/
      if (kk_yielding(kk_context())) {
        kk_box_drop(x0_21831, _ctx);
        kk_box_t _x25097 = kk_std_core_hnd_yield_extend(kk_std_core__new_ctailm_zipwith_fun25098(_accm0, f2, xx2, yy2, _ctx), _ctx); /*3991*/
        return kk_std_core__list_unbox(_x25097, _ctx);
      }
      { // tailcall
        kk_function_t _x25100 = kk_std_core__new_ctailm_zipwith_fun25101(_accm0, x0_21831, _ctx); /*(list<20871>) -> list<20871>*/
        xs0 = xx2;
        ys0 = yy2;
        _accm0 = _x25100;
        goto kk__tailcall;
      }
    }
    kk_function_drop(f2, _ctx);
    kk_box_drop(x0, _ctx);
    kk_std_core__list_drop(xx2, _ctx);
    return kk_function_call(kk_std_core__list, (kk_function_t, kk_std_core__list, kk_context_t*), _accm0, (_accm0, kk_std_core__new_Nil(_ctx), _ctx));
  }
  kk_function_drop(f2, _ctx);
  kk_std_core__list_drop(ys0, _ctx);
  return kk_function_call(kk_std_core__list, (kk_function_t, kk_std_core__list, kk_context_t*), _accm0, (_accm0, kk_std_core__new_Nil(_ctx), _ctx));
}
 
// Zip two lists together by apply a function `f` to all corresponding elements.
// The returned list is only as long as the smallest input list.


// lift anonymous function
struct kk_std_core_zipwith_fun25103__t {
  struct kk_function_s _base;
};
static kk_std_core__list kk_std_core_zipwith_fun25103(kk_function_t _fself, kk_std_core__list _ctail_21163, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_zipwith_fun25103(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_zipwith_fun25103, _ctx)
  return kk_function_dup(_fself);
}

static kk_std_core__list kk_std_core_zipwith_fun25103(kk_function_t _fself, kk_std_core__list _ctail_21163, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return _ctail_21163;
}

kk_std_core__list kk_std_core_zipwith(kk_std_core__list xs1, kk_std_core__list ys1, kk_function_t f3, kk_context_t* _ctx) { /* forall<a,b,c,e> (xs : list<a>, ys : list<b>, f : (a, b) -> e c) -> e list<c> */ 
  bool _match_23432 = kk_std_core_hnd__evv_is_affine(_ctx); /*bool*/;
  if (_match_23432) {
    return kk_std_core__ctail_zipwith(xs1, ys1, f3, kk_std_core_types__new_CTailNil(_ctx), _ctx);
  }
  return kk_std_core__ctailm_zipwith(xs1, ys1, f3, kk_std_core_new_zipwith_fun25103(_ctx), _ctx);
}
 
// monadic lift

kk_std_core__list kk_std_core__mlift21228_zipwith_acc(kk_std_core__list acc, kk_function_t f, kk_integer_t i, kk_std_core__list xx, kk_std_core__list yy, kk_box_t _y_260, kk_context_t* _ctx) { /* forall<e,a,b,c> (acc : list<b>, f : (int, a, c) -> e b, i : int, xx : list<a>, yy : list<c>, b) -> e list<b> */ 
  kk_integer_t _x25104 = kk_integer_add(i,(kk_integer_from_small(1)),kk_context()); /*int*/
  kk_std_core__list _x25105 = kk_std_core__new_Cons(kk_reuse_null, _y_260, acc, _ctx); /*list<61>*/
  return kk_std_core_zipwith_acc(f, _x25104, _x25105, xx, yy, _ctx);
}


// lift anonymous function
struct kk_std_core_zipwith_acc_fun25111__t {
  struct kk_function_s _base;
  kk_std_core__list acc0;
  kk_function_t f0;
  kk_integer_t i0;
  kk_std_core__list xx0;
  kk_std_core__list yy0;
};
static kk_box_t kk_std_core_zipwith_acc_fun25111(kk_function_t _fself, kk_box_t _b_23308, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_zipwith_acc_fun25111(kk_std_core__list acc0, kk_function_t f0, kk_integer_t i0, kk_std_core__list xx0, kk_std_core__list yy0, kk_context_t* _ctx) {
  struct kk_std_core_zipwith_acc_fun25111__t* _self = kk_function_alloc_as(struct kk_std_core_zipwith_acc_fun25111__t, 6, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_zipwith_acc_fun25111, kk_context());
  _self->acc0 = acc0;
  _self->f0 = f0;
  _self->i0 = i0;
  _self->xx0 = xx0;
  _self->yy0 = yy0;
  return &_self->_base;
}

static kk_box_t kk_std_core_zipwith_acc_fun25111(kk_function_t _fself, kk_box_t _b_23308, kk_context_t* _ctx) {
  struct kk_std_core_zipwith_acc_fun25111__t* _self = kk_function_as(struct kk_std_core_zipwith_acc_fun25111__t*, _fself);
  kk_std_core__list acc0 = _self->acc0; /* list<20884> */
  kk_function_t f0 = _self->f0; /* (int, 20882, 20892) -> 20879 20884 */
  kk_integer_t i0 = _self->i0; /* int */
  kk_std_core__list xx0 = _self->xx0; /* list<20882> */
  kk_std_core__list yy0 = _self->yy0; /* list<20892> */
  kk_drop_match(_self, {kk_std_core__list_dup(acc0);kk_function_dup(f0);kk_integer_dup(i0);kk_std_core__list_dup(xx0);kk_std_core__list_dup(yy0);}, {}, _ctx)
  kk_std_core__list _x25112 = kk_std_core__mlift21228_zipwith_acc(acc0, f0, i0, xx0, yy0, _b_23308, _ctx); /*list<20884>*/
  return kk_std_core__list_box(_x25112, _ctx);
}

kk_std_core__list kk_std_core_zipwith_acc(kk_function_t f0, kk_integer_t i0, kk_std_core__list acc0, kk_std_core__list xs, kk_std_core__list ys, kk_context_t* _ctx) { /* forall<a,b,c,e> ((int, a, b) -> e c, int, list<c>, list<a>, list<b>) -> e list<c> */ 
  kk__tailcall: ;
  if (kk_std_core__is_Nil(xs)) {
    kk_function_drop(f0, _ctx);
    kk_integer_drop(i0, _ctx);
    kk_std_core__list_drop(ys, _ctx);
    return kk_std_core_reverse(acc0, _ctx);
  }
  struct kk_std_core_Cons* _con25106 = kk_std_core__as_Cons(xs);
  kk_box_t x = _con25106->head;
  kk_std_core__list xx0 = _con25106->tail;
  if (kk_std_core__list_is_unique(xs)) {
    kk_std_core__list_free(xs);
  }
  else {
    kk_box_dup(x);
    kk_std_core__list_dup(xx0);
    kk_std_core__list_decref(xs, _ctx);
  }
  if (kk_std_core__is_Nil(ys)) {
    kk_function_drop(f0, _ctx);
    kk_integer_drop(i0, _ctx);
    kk_box_drop(x, _ctx);
    kk_std_core__list_drop(xx0, _ctx);
    return kk_std_core_reverse(acc0, _ctx);
  }
  struct kk_std_core_Cons* _con25107 = kk_std_core__as_Cons(ys);
  kk_box_t y = _con25107->head;
  kk_std_core__list yy0 = _con25107->tail;
  kk_reuse_t _ru_23425 = kk_reuse_null; /*reuse*/;
  if (kk_std_core__list_is_unique(ys)) {
    _ru_23425 = (kk_std_core__list_reuse(ys));
  }
  else {
    kk_box_dup(y);
    kk_std_core__list_dup(yy0);
    kk_std_core__list_decref(ys, _ctx);
    _ru_23425 = kk_reuse_null;
  }
  kk_box_t x0_21835;
  kk_function_t _x25109 = kk_function_dup(f0); /*(int, 20882, 20892) -> 20879 20884*/
  kk_integer_t _x25108 = kk_integer_dup(i0); /*int*/
  x0_21835 = kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_box_t, kk_box_t, kk_context_t*), _x25109, (_x25109, _x25108, x, y, _ctx)); /*20884*/
  if (kk_yielding(kk_context())) {
    kk_reuse_drop(_ru_23425, _ctx);
    kk_box_drop(x0_21835, _ctx);
    kk_box_t _x25110 = kk_std_core_hnd_yield_extend(kk_std_core_new_zipwith_acc_fun25111(acc0, f0, i0, xx0, yy0, _ctx), _ctx); /*3991*/
    return kk_std_core__list_unbox(_x25110, _ctx);
  }
  { // tailcall
    kk_integer_t _x25113 = kk_integer_add(i0,(kk_integer_from_small(1)),kk_context()); /*int*/
    kk_std_core__list _x25114 = kk_std_core__new_Cons(_ru_23425, x0_21835, acc0, _ctx); /*list<61>*/
    i0 = _x25113;
    acc0 = _x25114;
    xs = xx0;
    ys = yy0;
    goto kk__tailcall;
  }
}
 
// monadic lift

kk_std_core__list kk_std_core__mlift21229_op(kk_box_t _y_264, kk_std_core__list _y_265, kk_context_t* _ctx) { /* forall<a,e> (a, list<a>) -> e list<a> */ 
  return kk_std_core__new_Cons(kk_reuse_null, _y_264, _y_265, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_core__mlift21230_op_fun25116__t {
  struct kk_function_s _base;
  kk_box_t _y_2640;
};
static kk_box_t kk_std_core__mlift21230_op_fun25116(kk_function_t _fself, kk_box_t _b_23312, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_mlift21230_op_fun25116(kk_box_t _y_2640, kk_context_t* _ctx) {
  struct kk_std_core__mlift21230_op_fun25116__t* _self = kk_function_alloc_as(struct kk_std_core__mlift21230_op_fun25116__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__mlift21230_op_fun25116, kk_context());
  _self->_y_2640 = _y_2640;
  return &_self->_base;
}

static kk_box_t kk_std_core__mlift21230_op_fun25116(kk_function_t _fself, kk_box_t _b_23312, kk_context_t* _ctx) {
  struct kk_std_core__mlift21230_op_fun25116__t* _self = kk_function_as(struct kk_std_core__mlift21230_op_fun25116__t*, _fself);
  kk_box_t _y_2640 = _self->_y_2640; /* 20958 */
  kk_drop_match(_self, {kk_box_dup(_y_2640);}, {}, _ctx)
  kk_std_core__list _x25117;
  kk_std_core__list _x25118 = kk_std_core__list_unbox(_b_23312, _ctx); /*list<20958>*/
  _x25117 = kk_std_core__mlift21229_op(_y_2640, _x25118, _ctx); /*list<20958>*/
  return kk_std_core__list_box(_x25117, _ctx);
}

kk_std_core__list kk_std_core__mlift21230_op(kk_function_t f, kk_integer_t i, kk_std_core__list xx, kk_std_core__list yy, kk_box_t _y_2640, kk_context_t* _ctx) { /* forall<a,b,c,e> (f : (int, a, b) -> e c, i : int, xx : list<a>, yy : list<b>, c) -> e list<c> */ 
  kk_integer_t i0_21101 = kk_integer_add(i,(kk_integer_from_small(1)),kk_context()); /*int*/;
  kk_std_core__list x_21839 = kk_std_core__lift21062_zipwith_indexed(f, i0_21101, xx, yy, _ctx); /*list<20958>*/;
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_21839, _ctx);
    kk_box_t _x25115 = kk_std_core_hnd_yield_extend(kk_std_core__new_mlift21230_op_fun25116(_y_2640, _ctx), _ctx); /*3991*/
    return kk_std_core__list_unbox(_x25115, _ctx);
  }
  return kk_std_core__mlift21229_op(_y_2640, x_21839, _ctx);
}
 
// lift


// lift anonymous function
struct kk_std_core__lift21062_zipwith_indexed_fun25124__t {
  struct kk_function_s _base;
  kk_function_t f0;
  kk_integer_t i0;
  kk_std_core__list xx0;
  kk_std_core__list yy0;
};
static kk_box_t kk_std_core__lift21062_zipwith_indexed_fun25124(kk_function_t _fself, kk_box_t _b_23316, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_lift21062_zipwith_indexed_fun25124(kk_function_t f0, kk_integer_t i0, kk_std_core__list xx0, kk_std_core__list yy0, kk_context_t* _ctx) {
  struct kk_std_core__lift21062_zipwith_indexed_fun25124__t* _self = kk_function_alloc_as(struct kk_std_core__lift21062_zipwith_indexed_fun25124__t, 5, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__lift21062_zipwith_indexed_fun25124, kk_context());
  _self->f0 = f0;
  _self->i0 = i0;
  _self->xx0 = xx0;
  _self->yy0 = yy0;
  return &_self->_base;
}

static kk_box_t kk_std_core__lift21062_zipwith_indexed_fun25124(kk_function_t _fself, kk_box_t _b_23316, kk_context_t* _ctx) {
  struct kk_std_core__lift21062_zipwith_indexed_fun25124__t* _self = kk_function_as(struct kk_std_core__lift21062_zipwith_indexed_fun25124__t*, _fself);
  kk_function_t f0 = _self->f0; /* (int, 20956, 20957) -> 20959 20958 */
  kk_integer_t i0 = _self->i0; /* int */
  kk_std_core__list xx0 = _self->xx0; /* list<20956> */
  kk_std_core__list yy0 = _self->yy0; /* list<20957> */
  kk_drop_match(_self, {kk_function_dup(f0);kk_integer_dup(i0);kk_std_core__list_dup(xx0);kk_std_core__list_dup(yy0);}, {}, _ctx)
  kk_std_core__list _x25125 = kk_std_core__mlift21230_op(f0, i0, xx0, yy0, _b_23316, _ctx); /*list<20958>*/
  return kk_std_core__list_box(_x25125, _ctx);
}


// lift anonymous function
struct kk_std_core__lift21062_zipwith_indexed_fun25127__t {
  struct kk_function_s _base;
  kk_box_t x0_21841;
};
static kk_box_t kk_std_core__lift21062_zipwith_indexed_fun25127(kk_function_t _fself, kk_box_t _b_23318, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_lift21062_zipwith_indexed_fun25127(kk_box_t x0_21841, kk_context_t* _ctx) {
  struct kk_std_core__lift21062_zipwith_indexed_fun25127__t* _self = kk_function_alloc_as(struct kk_std_core__lift21062_zipwith_indexed_fun25127__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__lift21062_zipwith_indexed_fun25127, kk_context());
  _self->x0_21841 = x0_21841;
  return &_self->_base;
}

static kk_box_t kk_std_core__lift21062_zipwith_indexed_fun25127(kk_function_t _fself, kk_box_t _b_23318, kk_context_t* _ctx) {
  struct kk_std_core__lift21062_zipwith_indexed_fun25127__t* _self = kk_function_as(struct kk_std_core__lift21062_zipwith_indexed_fun25127__t*, _fself);
  kk_box_t x0_21841 = _self->x0_21841; /* 20958 */
  kk_drop_match(_self, {kk_box_dup(x0_21841);}, {}, _ctx)
  kk_std_core__list _x25128;
  kk_std_core__list _x25129 = kk_std_core__list_unbox(_b_23318, _ctx); /*list<20958>*/
  _x25128 = kk_std_core__mlift21229_op(x0_21841, _x25129, _ctx); /*list<20958>*/
  return kk_std_core__list_box(_x25128, _ctx);
}

kk_std_core__list kk_std_core__lift21062_zipwith_indexed(kk_function_t f0, kk_integer_t i0, kk_std_core__list xs, kk_std_core__list ys, kk_context_t* _ctx) { /* forall<a,b,c,e> (f : (int, a, b) -> e c, i : int, xs : list<a>, ys : list<b>) -> e list<c> */ 
  if (kk_std_core__is_Cons(xs)) {
    struct kk_std_core_Cons* _con25119 = kk_std_core__as_Cons(xs);
    kk_box_t x = _con25119->head;
    kk_std_core__list xx0 = _con25119->tail;
    if (kk_std_core__list_is_unique(xs)) {
      kk_std_core__list_free(xs);
    }
    else {
      kk_box_dup(x);
      kk_std_core__list_dup(xx0);
      kk_std_core__list_decref(xs, _ctx);
    }
    if (kk_std_core__is_Cons(ys)) {
      struct kk_std_core_Cons* _con25120 = kk_std_core__as_Cons(ys);
      kk_box_t y = _con25120->head;
      kk_std_core__list yy0 = _con25120->tail;
      kk_reuse_t _ru_23427 = kk_reuse_null; /*reuse*/;
      if (kk_std_core__list_is_unique(ys)) {
        _ru_23427 = (kk_std_core__list_reuse(ys));
      }
      else {
        kk_box_dup(y);
        kk_std_core__list_dup(yy0);
        kk_std_core__list_decref(ys, _ctx);
        _ru_23427 = kk_reuse_null;
      }
      kk_box_t x0_21841;
      kk_function_t _x25122 = kk_function_dup(f0); /*(int, 20956, 20957) -> 20959 20958*/
      kk_integer_t _x25121 = kk_integer_dup(i0); /*int*/
      x0_21841 = kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_box_t, kk_box_t, kk_context_t*), _x25122, (_x25122, _x25121, x, y, _ctx)); /*20958*/
      if (kk_yielding(kk_context())) {
        kk_reuse_drop(_ru_23427, _ctx);
        kk_box_drop(x0_21841, _ctx);
        kk_box_t _x25123 = kk_std_core_hnd_yield_extend(kk_std_core__new_lift21062_zipwith_indexed_fun25124(f0, i0, xx0, yy0, _ctx), _ctx); /*3991*/
        return kk_std_core__list_unbox(_x25123, _ctx);
      }
      kk_integer_t i0_211010 = kk_integer_add(i0,(kk_integer_from_small(1)),kk_context()); /*int*/;
      kk_std_core__list x1_21845 = kk_std_core__lift21062_zipwith_indexed(f0, i0_211010, xx0, yy0, _ctx); /*list<20958>*/;
      if (kk_yielding(kk_context())) {
        kk_reuse_drop(_ru_23427, _ctx);
        kk_std_core__list_drop(x1_21845, _ctx);
        kk_box_t _x25126 = kk_std_core_hnd_yield_extend(kk_std_core__new_lift21062_zipwith_indexed_fun25127(x0_21841, _ctx), _ctx); /*3991*/
        return kk_std_core__list_unbox(_x25126, _ctx);
      }
      return kk_std_core__new_Cons(_ru_23427, x0_21841, x1_21845, _ctx);
    }
    kk_function_drop(f0, _ctx);
    kk_integer_drop(i0, _ctx);
    kk_box_drop(x, _ctx);
    kk_std_core__list_drop(xx0, _ctx);
    return kk_std_core__new_Nil(_ctx);
  }
  kk_function_drop(f0, _ctx);
  kk_integer_drop(i0, _ctx);
  kk_std_core__list_drop(ys, _ctx);
  return kk_std_core__new_Nil(_ctx);
}

// initialization
void kk_std_core__init(kk_context_t* _ctx){
  static bool _initialized = false;
  if (_initialized) return;
  _initialized = true;
  kk_std_core_types__init(_ctx);
  kk_std_core_hnd__init(_ctx);
  {
    kk_string_t _x23693;
    kk_define_string_literal(, _s23694, 8, "exn.core")
    _x23693 = kk_string_dup(_s23694); /*string*/
    kk_std_core__tag_exn = kk_std_core_hnd__new_Htag(_x23693, _ctx); /*std/core/hnd/htag<.hnd-exn>*/
  }
  {
    kk_std_core_redirect = kk_ref_alloc((kk_std_core_types__maybe_box(kk_std_core_types__new_Nothing(_ctx), _ctx)),kk_context()); /*ref<global,maybe<(string) -> console ()>>*/
  }
  {
    kk_std_core_maxListStack = kk_integer_from_small(50); /*int*/
  }
  {
    kk_std_core_trace_enabled = kk_ref_alloc((kk_bool_box(true)),kk_context()); /*ref<global,bool>*/
  }
  {
    kk_std_core_unique_count = kk_ref_alloc((kk_integer_box(kk_integer_from_small(0))),kk_context()); /*ref<global,int>*/
  }
  {
    kk_string_t _x24478 = kk_string_empty(); /*string*/
    size_t _x24480 = ((size_t)0); /*size_t*/
    size_t _x24481 = ((size_t)0); /*size_t*/
    kk_std_core_empty = kk_std_core__new_Sslice(_x24478, _x24480, _x24481, _ctx); /*sslice*/
  }
  {
    kk_std_core_null_const = kk_std_core_null(kk_std_core_types__new_Nothing(_ctx), _ctx); /*forall<a> null<a>*/
  }
}
