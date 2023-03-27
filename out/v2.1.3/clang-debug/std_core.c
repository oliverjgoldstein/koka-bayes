// Koka generated module: "std/core", koka version: 2.1.3
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
  kk_std_core__list_drop(xs,ctx);  // todo: drop while visiting?
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
  kk_string_drop(s,ctx);
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
  kk_std_core__sslice_drop(sslice,ctx);
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
  kk_string_t _x23650;
  if (kk_std_core_types__is_Optional(message0)) {
    kk_box_t _box_x21893 = message0._cons.Optional.value;
    kk_string_t _message_1673 = kk_string_unbox(_box_x21893);
    kk_string_dup(_message_1673);
    kk_std_core_types__optional_drop(message0, _ctx);
    _x23650 = _message_1673; /*string*/
    goto _match23651;
  }
  kk_string_t _x = _this.message;
  kk_string_dup(_x);
  _x23650 = _x; /*string*/
  _match23651: ;
  kk_std_core__exception_info _x23653;
  if (kk_std_core_types__is_Optional(info0)) {
    kk_box_t _box_x21894 = info0._cons.Optional.value;
    kk_std_core__exception_info _info_1679 = kk_std_core__exception_info_unbox(_box_x21894, NULL);
    kk_std_core__exception_info_dup(_info_1679);
    kk_std_core_types__optional_drop(info0, _ctx);
    kk_std_core__exception_drop(_this, _ctx);
    _x23653 = _info_1679; /*exception-info*/
    goto _match23654;
  }
  kk_std_core__exception_info _x0 = _this.info;
  kk_std_core__exception_info_dup(_x0);
  kk_std_core__exception_drop(_this, _ctx);
  _x23653 = _x0; /*exception-info*/
  _match23654: ;
  return kk_std_core__new_Exception(_x23650, _x23653, _ctx);
}
 
// monadic lift

kk_std_core__delayed kk_std_core__mlift21167_op(kk_ref_t _c_0, kk_context_t* _ctx) { /* forall<e,a> (ref<global,either<() -> e a,a>>) -> delayed<e,a> */ 
  return kk_std_core__new_Delay(_c_0, _ctx);
}


// lift anonymous function
struct kk_std_core__copy_fun23657__t_1 {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core__copy_fun23657_1(kk_function_t _fself, kk_box_t _b_21896, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_copy_fun23657_1(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core__copy_fun23657_1, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_core__copy_fun23657_1(kk_function_t _fself, kk_box_t _b_21896, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core__delayed _x23658;
  kk_ref_t _x23659 = kk_ref_unbox(_b_21896, _ctx); /*ref<global,either<() -> 1724 1725,1725>>*/
  _x23658 = kk_std_core__mlift21167_op(_x23659, _ctx); /*delayed<1724,1725>*/
  return kk_std_core__delayed_box(_x23658, _ctx);
}

kk_std_core__delayed kk_std_core__copy_1(kk_std_core__delayed _this, kk_std_core_types__optional dref0, kk_context_t* _ctx) { /* forall<e,a> (delayed<e,a>, dref : optional<ref<global,either<() -> e a,a>>>) -> delayed<e,a> */ 
  if (kk_yielding(kk_context())) {
    kk_std_core__delayed_drop(_this, _ctx);
    kk_std_core_types__optional_drop(dref0, _ctx);
    kk_box_t _x23656 = kk_std_core_hnd_yield_extend(kk_std_core__new_copy_fun23657_1(_ctx), _ctx); /*3991*/
    return kk_std_core__delayed_unbox(_x23656, _ctx);
  }
  kk_ref_t _x23660;
  if (kk_std_core_types__is_Optional(dref0)) {
    kk_box_t _box_x21897 = dref0._cons.Optional.value;
    kk_ref_t _dref_1712 = kk_ref_unbox(_box_x21897, NULL);
    kk_ref_dup(_dref_1712);
    kk_std_core_types__optional_drop(dref0, _ctx);
    kk_std_core__delayed_drop(_this, _ctx);
    _x23660 = _dref_1712; /*ref<global,either<() -> 1724 1725,1725>>*/
    goto _match23661;
  }
  kk_ref_t _x = _this.dref;
  _x23660 = _x; /*ref<global,either<() -> 1724 1725,1725>>*/
  _match23661: ;
  return kk_std_core__new_Delay(_x23660, _ctx);
}

kk_std_core__sslice kk_std_core__copy_2(kk_std_core__sslice _this, kk_std_core_types__optional str0, kk_std_core_types__optional start0, kk_std_core_types__optional len0, kk_context_t* _ctx) { /* (sslice, str : optional<string>, start : optional<size_t>, len : optional<size_t>) -> sslice */ 
  kk_string_t _x23664;
  if (kk_std_core_types__is_Optional(str0)) {
    kk_box_t _box_x21900 = str0._cons.Optional.value;
    kk_string_t _str_1813 = kk_string_unbox(_box_x21900);
    kk_string_dup(_str_1813);
    kk_std_core_types__optional_drop(str0, _ctx);
    _x23664 = _str_1813; /*string*/
    goto _match23665;
  }
  kk_string_t _x = _this.str;
  kk_string_dup(_x);
  _x23664 = _x; /*string*/
  _match23665: ;
  size_t _x23667;
  if (kk_std_core_types__is_Optional(start0)) {
    kk_box_t _box_x21901 = start0._cons.Optional.value;
    size_t _start_1819 = kk_size_unbox(_box_x21901, NULL);
    kk_std_core_types__optional_drop(start0, _ctx);
    _x23667 = _start_1819; /*size_t*/
    goto _match23668;
  }
  size_t _x0 = _this.start;
  _x23667 = _x0; /*size_t*/
  _match23668: ;
  size_t _x23670;
  if (kk_std_core_types__is_Optional(len0)) {
    kk_box_t _box_x21902 = len0._cons.Optional.value;
    size_t _len_1825 = kk_size_unbox(_box_x21902, NULL);
    kk_std_core_types__optional_drop(len0, _ctx);
    kk_std_core__sslice_drop(_this, _ctx);
    _x23670 = _len_1825; /*size_t*/
    goto _match23671;
  }
  size_t _x1 = _this.len;
  kk_std_core__sslice_drop(_this, _ctx);
  _x23670 = _x1; /*size_t*/
  _match23671: ;
  return kk_std_core__new_Sslice(_x23664, _x23667, _x23670, _ctx);
}

kk_std_core__stream kk_std_core__copy_3(kk_std_core__stream _this, kk_std_core_types__optional head0, kk_std_core_types__optional tail0, kk_context_t* _ctx) { /* forall<a> (stream<a>, head : optional<a>, tail : optional<stream<a>>) -> stream<a> */ 
  kk_box_t _x23675;
  if (kk_std_core_types__is_Optional(head0)) {
    kk_box_t _head_1875 = head0._cons.Optional.value;
    _x23675 = _head_1875; /*1892*/
  }
  else {
    struct kk_std_core_Next* _con23676 = kk_std_core__as_Next(_this);
    kk_box_t _x = _con23676->head;
    kk_box_dup(_x);
    _x23675 = _x; /*1892*/
  }
  kk_std_core__stream _x23677;
  if (kk_std_core_types__is_Optional(tail0)) {
    kk_box_t _box_x21903 = tail0._cons.Optional.value;
    kk_std_core__stream _tail_1882 = kk_std_core__stream_unbox(_box_x21903, NULL);
    kk_std_core__stream_dup(_tail_1882);
    kk_std_core_types__optional_drop(tail0, _ctx);
    kk_std_core__stream_drop(_this, _ctx);
    _x23677 = _tail_1882; /*stream<1892>*/
    goto _match23678;
  }
  struct kk_std_core_Next* _con23680 = kk_std_core__as_Next(_this);
  kk_box_t _pat01 = _con23680->head;
  kk_std_core__stream _x0 = _con23680->tail;
  if (kk_std_core__stream_is_unique(_this)) {
    kk_box_drop(_pat01, _ctx);
    kk_std_core__stream_free(_this);
  }
  else {
    kk_std_core__stream_dup(_x0);
    kk_std_core__stream_decref(_this, _ctx);
  }
  _x23677 = _x0; /*stream<1892>*/
  _match23678: ;
  return kk_std_core__new_Next(kk_reuse_null, _x23675, _x23677, _ctx);
}
 
// runtime tag for the `:exn` effect

kk_std_core_hnd__htag kk_std_core__tag_exn;
 
// handler for the `:exn` effect

kk_box_t kk_std_core__handle_exn(int32_t cfc, kk_std_core__hnd_exn hnd, kk_function_t ret, kk_function_t action, kk_context_t* _ctx) { /* forall<a,e,b> (cfc : int32, hnd : .hnd-exn<e,b>, ret : (res : a) -> e b, action : () -> <exn|e> a) -> e b */ 
  kk_std_core_hnd__htag _x23684 = kk_std_core_hnd__htag_dup(kk_std_core__tag_exn); /*std/core/hnd/htag<.hnd-exn>*/
  return kk_std_core_hnd__hhandle(_x23684, cfc, kk_std_core__hnd_exn_box(hnd, _ctx), ret, action, _ctx);
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
  kk_std_core__list _x23687;
  if (kk_std_core_types__is_Optional(tail0)) {
    kk_box_t _box_x21917 = tail0._cons.Optional.value;
    kk_std_core__list _tail_2144 = kk_std_core__list_unbox(_box_x21917, NULL);
    kk_std_core__list_dup(_tail_2144);
    kk_std_core_types__optional_drop(tail0, _ctx);
    _x23687 = _tail_2144; /*list<2154>*/
    goto _match23688;
  }
  _x23687 = kk_std_core__new_Nil(_ctx); /*list<2154>*/
  _match23688: ;
  return kk_vector_to_list(v,_x23687,kk_context());
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
  kk_integer_t _x23690;
  if (kk_std_core_types__is_Optional(upto)) {
    kk_box_t _box_x21918 = upto._cons.Optional.value;
    kk_integer_t _upto_2243 = kk_integer_unbox(_box_x21918);
    kk_integer_dup(_upto_2243);
    kk_std_core_types__optional_drop(upto, _ctx);
    _x23690 = _upto_2243; /*int*/
    goto _match23691;
  }
  _x23690 = kk_integer_from_small(-1); /*int*/
  _match23691: ;
  return kk_slice_common_prefix(s,t,_x23690,kk_context());
}
 
// lift

kk_std_core__list kk_std_core__ctail_lift21045_concat(kk_std_core__list ys, kk_std_core__list zss, kk_std_core_types__ctail _acc, kk_context_t* _ctx) { /* forall<a> (ys : list<a>, zss : list<list<a>>, ctail<list<a>>) -> list<a> */ 
  kk__tailcall: ;
  if (kk_std_core__is_Cons(ys)) {
    struct kk_std_core_Cons* _con23693 = kk_std_core__as_Cons(ys);
    kk_box_t y = _con23693->head;
    kk_std_core__list yy = _con23693->tail;
    kk_reuse_t _ru_23322 = kk_reuse_null; /*reuse*/;
    if (kk_std_core__list_is_unique(ys)) {
      _ru_23322 = (kk_std_core__list_reuse(ys));
    }
    else {
      kk_box_dup(y);
      kk_std_core__list_dup(yy);
      kk_std_core__list_decref(ys, _ctx);
      _ru_23322 = kk_reuse_null;
    }
    kk_std_core__list _ctail_21107 = kk_std_core__list_hole(); /*list<2291>*/;
    kk_std_core__list _ctail_21108;
    bool _x23694 = _ru_23322!=NULL; /*bool*/
    if (_x23694) {
      struct kk_std_core_Cons* _con23695 = (struct kk_std_core_Cons*)_ru_23322;
      _con23695->tail = _ctail_21107;
      _ctail_21108 = kk_std_core__base_Cons(_con23695); /*list<2291>*/
    }
    else {
      _ctail_21108 = kk_std_core__new_Cons(kk_reuse_null, y, _ctail_21107, _ctx); /*list<2291>*/
    }
    { // tailcall
      kk_std_core_types__ctail _x23696;
      kk_box_t* field_21247 = (kk_box_t*)((&kk_std_core__as_Cons(_ctail_21108)->tail)); /*cfield<list<2291>>*/;
      if (kk_std_core_types__is_CTail(_acc)) {
        kk_box_t _box_x21925 = _acc._cons.CTail._field1;
        kk_box_t* last0 = _acc._cons.CTail._field2;
        kk_std_core__list head0 = kk_std_core__list_unbox(_box_x21925, NULL);
        kk_std_core__list_dup(head0);
        kk_std_core_types__ctail_drop(_acc, _ctx);
        kk_unit_t __ = kk_Unit;
        *(last0) = kk_std_core__list_box(_ctail_21108, _ctx);
        _x23696 = kk_std_core_types__new_CTail(kk_std_core__list_box(head0, _ctx), field_21247, _ctx); /*ctail<58>*/
        goto _match23697;
      }
      _x23696 = kk_std_core_types__new_CTail(kk_std_core__list_box(_ctail_21108, _ctx), field_21247, _ctx); /*ctail<58>*/
      _match23697: ;
      ys = yy;
      _acc = _x23696;
      goto kk__tailcall;
    }
  }
  if (kk_std_core__is_Cons(zss)) {
    struct kk_std_core_Cons* _con23699 = kk_std_core__as_Cons(zss);
    kk_box_t _box_x21934 = _con23699->head;
    kk_std_core__list zzs = _con23699->tail;
    kk_std_core__list zs = kk_std_core__list_unbox(_box_x21934, NULL);
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
    kk_box_t _box_x21935 = _acc._cons.CTail._field1;
    kk_box_t* last00 = _acc._cons.CTail._field2;
    kk_std_core__list head00 = kk_std_core__list_unbox(_box_x21935, NULL);
    kk_std_core__list_dup(head00);
    kk_std_core_types__ctail_drop(_acc, _ctx);
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
extern kk_box_t kk_std_core_const_fun23702_1(kk_function_t _fself, kk_box_t ___wildcard__123__7, kk_context_t* _ctx) {
  struct kk_std_core_const_fun23702__t_1* _self = kk_function_as(struct kk_std_core_const_fun23702__t_1*, _fself);
  kk_box_t default0 = _self->default0; /* 2319 */
  kk_drop_match(_self, {kk_box_dup(default0);}, {}, _ctx)
  kk_box_drop(___wildcard__123__7, _ctx);
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
  kk_box_dup(x);
  kk_std_core__error_drop(t, _ctx);
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
struct kk_std_core__ctail_lift21046_flatmap_fun23712__t {
  struct kk_function_s _base;
  kk_function_t f1;
  kk_std_core__list zz1;
  kk_std_core_types__ctail _acc0;
};
static kk_box_t kk_std_core__ctail_lift21046_flatmap_fun23712(kk_function_t _fself, kk_box_t _b_21962, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_ctail_lift21046_flatmap_fun23712(kk_function_t f1, kk_std_core__list zz1, kk_std_core_types__ctail _acc0, kk_context_t* _ctx) {
  struct kk_std_core__ctail_lift21046_flatmap_fun23712__t* _self = kk_function_alloc_as(struct kk_std_core__ctail_lift21046_flatmap_fun23712__t, 5, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__ctail_lift21046_flatmap_fun23712, kk_context());
  _self->f1 = f1;
  _self->zz1 = zz1;
  _self->_acc0 = _acc0;
  return &_self->_base;
}

static kk_box_t kk_std_core__ctail_lift21046_flatmap_fun23712(kk_function_t _fself, kk_box_t _b_21962, kk_context_t* _ctx) {
  struct kk_std_core__ctail_lift21046_flatmap_fun23712__t* _self = kk_function_as(struct kk_std_core__ctail_lift21046_flatmap_fun23712__t*, _fself);
  kk_function_t f1 = _self->f1; /* (2421) -> 2423 list<2422> */
  kk_std_core__list zz1 = _self->zz1; /* list<2421> */
  kk_std_core_types__ctail _acc0 = _self->_acc0; /* ctail<list<2422>> */
  kk_drop_match(_self, {kk_function_dup(f1);kk_std_core__list_dup(zz1);kk_std_core_types__ctail_dup(_acc0);}, {}, _ctx)
  kk_std_core__list _x23713;
  kk_std_core__list _x23714 = kk_std_core__list_unbox(_b_21962, _ctx); /*list<2422>*/
  _x23713 = kk_std_core__mlift21168_op(_acc0, f1, zz1, _x23714, _ctx); /*list<2422>*/
  return kk_std_core__list_box(_x23713, _ctx);
}

kk_std_core__list kk_std_core__ctail_lift21046_flatmap(kk_function_t f1, kk_std_core__list ys, kk_std_core__list zs, kk_std_core_types__ctail _acc0, kk_context_t* _ctx) { /* forall<a,b,e> (f : (a) -> e list<b>, ys : list<b>, zs : list<a>, ctail<list<b>>) -> e list<b> */ 
  kk__tailcall: ;
  if (kk_std_core__is_Cons(ys)) {
    struct kk_std_core_Cons* _con23703 = kk_std_core__as_Cons(ys);
    kk_box_t y = _con23703->head;
    kk_std_core__list yy = _con23703->tail;
    kk_reuse_t _ru_23324 = kk_reuse_null; /*reuse*/;
    if (kk_std_core__list_is_unique(ys)) {
      _ru_23324 = (kk_std_core__list_reuse(ys));
    }
    else {
      kk_box_dup(y);
      kk_std_core__list_dup(yy);
      kk_std_core__list_decref(ys, _ctx);
      _ru_23324 = kk_reuse_null;
    }
    kk_std_core__list _ctail_21109 = kk_std_core__list_hole(); /*list<2422>*/;
    kk_std_core__list _ctail_21110;
    bool _x23704 = _ru_23324!=NULL; /*bool*/
    if (_x23704) {
      struct kk_std_core_Cons* _con23705 = (struct kk_std_core_Cons*)_ru_23324;
      _con23705->tail = _ctail_21109;
      _ctail_21110 = kk_std_core__base_Cons(_con23705); /*list<2422>*/
    }
    else {
      _ctail_21110 = kk_std_core__new_Cons(kk_reuse_null, y, _ctail_21109, _ctx); /*list<2422>*/
    }
    { // tailcall
      kk_std_core_types__ctail _x23706;
      kk_box_t* field_21252 = (kk_box_t*)((&kk_std_core__as_Cons(_ctail_21110)->tail)); /*cfield<list<2422>>*/;
      if (kk_std_core_types__is_CTail(_acc0)) {
        kk_box_t _box_x21952 = _acc0._cons.CTail._field1;
        kk_box_t* last0 = _acc0._cons.CTail._field2;
        kk_std_core__list head0 = kk_std_core__list_unbox(_box_x21952, NULL);
        kk_std_core__list_dup(head0);
        kk_std_core_types__ctail_drop(_acc0, _ctx);
        kk_unit_t __ = kk_Unit;
        *(last0) = kk_std_core__list_box(_ctail_21110, _ctx);
        _x23706 = kk_std_core_types__new_CTail(kk_std_core__list_box(head0, _ctx), field_21252, _ctx); /*ctail<58>*/
        goto _match23707;
      }
      _x23706 = kk_std_core_types__new_CTail(kk_std_core__list_box(_ctail_21110, _ctx), field_21252, _ctx); /*ctail<58>*/
      _match23707: ;
      ys = yy;
      _acc0 = _x23706;
      goto kk__tailcall;
    }
  }
  if (kk_std_core__is_Cons(zs)) {
    struct kk_std_core_Cons* _con23709 = kk_std_core__as_Cons(zs);
    kk_box_t z = _con23709->head;
    kk_std_core__list zz1 = _con23709->tail;
    if (kk_std_core__list_is_unique(zs)) {
      kk_std_core__list_free(zs);
    }
    else {
      kk_box_dup(z);
      kk_std_core__list_dup(zz1);
      kk_std_core__list_decref(zs, _ctx);
    }
    kk_std_core__list x_21253;
    kk_function_t _x23710 = kk_function_dup(f1); /*(2421) -> 2423 list<2422>*/
    x_21253 = kk_function_call(kk_std_core__list, (kk_function_t, kk_box_t, kk_context_t*), _x23710, (_x23710, z, _ctx)); /*list<2422>*/
    if (kk_yielding(kk_context())) {
      kk_std_core__list_drop(x_21253, _ctx);
      kk_box_t _x23711 = kk_std_core_hnd_yield_extend(kk_std_core__new_ctail_lift21046_flatmap_fun23712(f1, zz1, _acc0, _ctx), _ctx); /*3991*/
      return kk_std_core__list_unbox(_x23711, _ctx);
    }
    { // tailcall
      ys = x_21253;
      zs = zz1;
      goto kk__tailcall;
    }
  }
  kk_function_drop(f1, _ctx);
  if (kk_std_core_types__is_CTail(_acc0)) {
    kk_box_t _box_x21963 = _acc0._cons.CTail._field1;
    kk_box_t* last00 = _acc0._cons.CTail._field2;
    kk_std_core__list head00 = kk_std_core__list_unbox(_box_x21963, NULL);
    kk_std_core__list_dup(head00);
    kk_std_core_types__ctail_drop(_acc0, _ctx);
    kk_unit_t __0 = kk_Unit;
    *(last00) = kk_std_core__list_box(kk_std_core__new_Nil(_ctx), _ctx);
    return head00;
  }
  return kk_std_core__new_Nil(_ctx);
}
 
// lift


// lift anonymous function
struct kk_std_core__ctailm_lift21046_flatmap_fun23718__t {
  struct kk_function_s _base;
  kk_function_t _accm0;
  kk_box_t y0;
};
static kk_std_core__list kk_std_core__ctailm_lift21046_flatmap_fun23718(kk_function_t _fself, kk_std_core__list _ctail_21112, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_ctailm_lift21046_flatmap_fun23718(kk_function_t _accm0, kk_box_t y0, kk_context_t* _ctx) {
  struct kk_std_core__ctailm_lift21046_flatmap_fun23718__t* _self = kk_function_alloc_as(struct kk_std_core__ctailm_lift21046_flatmap_fun23718__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__ctailm_lift21046_flatmap_fun23718, kk_context());
  _self->_accm0 = _accm0;
  _self->y0 = y0;
  return &_self->_base;
}

static kk_std_core__list kk_std_core__ctailm_lift21046_flatmap_fun23718(kk_function_t _fself, kk_std_core__list _ctail_21112, kk_context_t* _ctx) {
  struct kk_std_core__ctailm_lift21046_flatmap_fun23718__t* _self = kk_function_as(struct kk_std_core__ctailm_lift21046_flatmap_fun23718__t*, _fself);
  kk_function_t _accm0 = _self->_accm0; /* (list<2422>) -> list<2422> */
  kk_box_t y0 = _self->y0; /* 2422 */
  kk_drop_match(_self, {kk_function_dup(_accm0);kk_box_dup(y0);}, {}, _ctx)
  kk_std_core__list _x23719 = kk_std_core__new_Cons(kk_reuse_null, y0, _ctail_21112, _ctx); /*list<61>*/
  return kk_function_call(kk_std_core__list, (kk_function_t, kk_std_core__list, kk_context_t*), _accm0, (_accm0, _x23719, _ctx));
}


// lift anonymous function
struct kk_std_core__ctailm_lift21046_flatmap_fun23723__t {
  struct kk_function_s _base;
  kk_function_t _accm0;
  kk_function_t f2;
  kk_std_core__list zz2;
};
static kk_box_t kk_std_core__ctailm_lift21046_flatmap_fun23723(kk_function_t _fself, kk_box_t _b_21975, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_ctailm_lift21046_flatmap_fun23723(kk_function_t _accm0, kk_function_t f2, kk_std_core__list zz2, kk_context_t* _ctx) {
  struct kk_std_core__ctailm_lift21046_flatmap_fun23723__t* _self = kk_function_alloc_as(struct kk_std_core__ctailm_lift21046_flatmap_fun23723__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__ctailm_lift21046_flatmap_fun23723, kk_context());
  _self->_accm0 = _accm0;
  _self->f2 = f2;
  _self->zz2 = zz2;
  return &_self->_base;
}

static kk_box_t kk_std_core__ctailm_lift21046_flatmap_fun23723(kk_function_t _fself, kk_box_t _b_21975, kk_context_t* _ctx) {
  struct kk_std_core__ctailm_lift21046_flatmap_fun23723__t* _self = kk_function_as(struct kk_std_core__ctailm_lift21046_flatmap_fun23723__t*, _fself);
  kk_function_t _accm0 = _self->_accm0; /* (list<2422>) -> list<2422> */
  kk_function_t f2 = _self->f2; /* (2421) -> 2423 list<2422> */
  kk_std_core__list zz2 = _self->zz2; /* list<2421> */
  kk_drop_match(_self, {kk_function_dup(_accm0);kk_function_dup(f2);kk_std_core__list_dup(zz2);}, {}, _ctx)
  kk_std_core__list _x23724;
  kk_std_core__list _x23725 = kk_std_core__list_unbox(_b_21975, _ctx); /*list<2422>*/
  _x23724 = kk_std_core__mlift21169_op(_accm0, f2, zz2, _x23725, _ctx); /*list<2422>*/
  return kk_std_core__list_box(_x23724, _ctx);
}

kk_std_core__list kk_std_core__ctailm_lift21046_flatmap(kk_function_t f2, kk_std_core__list ys0, kk_std_core__list zs0, kk_function_t _accm0, kk_context_t* _ctx) { /* forall<a,b,e> (f : (a) -> e list<b>, ys : list<b>, zs : list<a>, (list<b>) -> list<b>) -> e list<b> */ 
  kk__tailcall: ;
  if (kk_std_core__is_Cons(ys0)) {
    struct kk_std_core_Cons* _con23716 = kk_std_core__as_Cons(ys0);
    kk_box_t y0 = _con23716->head;
    kk_std_core__list yy0 = _con23716->tail;
    if (kk_std_core__list_is_unique(ys0)) {
      kk_std_core__list_free(ys0);
    }
    else {
      kk_box_dup(y0);
      kk_std_core__list_dup(yy0);
      kk_std_core__list_decref(ys0, _ctx);
    }
    { // tailcall
      kk_function_t _x23717 = kk_std_core__new_ctailm_lift21046_flatmap_fun23718(_accm0, y0, _ctx); /*(list<2422>) -> list<2422>*/
      ys0 = yy0;
      _accm0 = _x23717;
      goto kk__tailcall;
    }
  }
  if (kk_std_core__is_Cons(zs0)) {
    struct kk_std_core_Cons* _con23720 = kk_std_core__as_Cons(zs0);
    kk_box_t z0 = _con23720->head;
    kk_std_core__list zz2 = _con23720->tail;
    if (kk_std_core__list_is_unique(zs0)) {
      kk_std_core__list_free(zs0);
    }
    else {
      kk_box_dup(z0);
      kk_std_core__list_dup(zz2);
      kk_std_core__list_decref(zs0, _ctx);
    }
    kk_std_core__list x_21259;
    kk_function_t _x23721 = kk_function_dup(f2); /*(2421) -> 2423 list<2422>*/
    x_21259 = kk_function_call(kk_std_core__list, (kk_function_t, kk_box_t, kk_context_t*), _x23721, (_x23721, z0, _ctx)); /*list<2422>*/
    if (kk_yielding(kk_context())) {
      kk_std_core__list_drop(x_21259, _ctx);
      kk_box_t _x23722 = kk_std_core_hnd_yield_extend(kk_std_core__new_ctailm_lift21046_flatmap_fun23723(_accm0, f2, zz2, _ctx), _ctx); /*3991*/
      return kk_std_core__list_unbox(_x23722, _ctx);
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
struct kk_std_core__lift21046_flatmap_fun23726__t {
  struct kk_function_s _base;
};
static kk_std_core__list kk_std_core__lift21046_flatmap_fun23726(kk_function_t _fself, kk_std_core__list _ctail_21111, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_lift21046_flatmap_fun23726(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core__lift21046_flatmap_fun23726, _ctx)
  return kk_function_dup(_fself);
}

static kk_std_core__list kk_std_core__lift21046_flatmap_fun23726(kk_function_t _fself, kk_std_core__list _ctail_21111, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return _ctail_21111;
}

kk_std_core__list kk_std_core__lift21046_flatmap(kk_function_t f3, kk_std_core__list ys1, kk_std_core__list zs1, kk_context_t* _ctx) { /* forall<a,b,e> (f : (a) -> e list<b>, ys : list<b>, zs : list<a>) -> e list<b> */ 
  bool _match_23637 = kk_std_core_hnd__evv_is_affine(_ctx); /*bool*/;
  if (_match_23637) {
    return kk_std_core__ctail_lift21046_flatmap(f3, ys1, zs1, kk_std_core_types__new_CTailNil(_ctx), _ctx);
  }
  return kk_std_core__ctailm_lift21046_flatmap(f3, ys1, zs1, kk_std_core__new_lift21046_flatmap_fun23726(_ctx), _ctx);
}
 
// lift

kk_std_core__list kk_std_core__lift21047_reverse_append(kk_std_core__list acc, kk_std_core__list ys, kk_context_t* _ctx) { /* forall<a> (acc : list<a>, ys : list<a>) -> list<a> */ 
  kk__tailcall: ;
  if (kk_std_core__is_Cons(ys)) {
    struct kk_std_core_Cons* _con23727 = kk_std_core__as_Cons(ys);
    kk_box_t x = _con23727->head;
    kk_std_core__list xx = _con23727->tail;
    kk_reuse_t _ru_23328 = kk_reuse_null; /*reuse*/;
    if (kk_std_core__list_is_unique(ys)) {
      _ru_23328 = (kk_std_core__list_reuse(ys));
    }
    else {
      kk_box_dup(x);
      kk_std_core__list_dup(xx);
      kk_std_core__list_decref(ys, _ctx);
      _ru_23328 = kk_reuse_null;
    }
    { // tailcall
      kk_std_core__list _x23728;
      bool _x23729 = _ru_23328!=NULL; /*bool*/
      if (_x23729) {
        struct kk_std_core_Cons* _con23730 = (struct kk_std_core_Cons*)_ru_23328;
        _con23730->tail = acc;
        _x23728 = kk_std_core__base_Cons(_con23730); /*list<61>*/
      }
      else {
        _x23728 = kk_std_core__new_Cons(kk_reuse_null, x, acc, _ctx); /*list<61>*/
      }
      acc = _x23728;
      ys = xx;
      goto kk__tailcall;
    }
  }
  return acc;
}
 
// monadic lift

kk_box_t kk_std_core__mlift21170_force(kk_ref_t r, kk_box_t x0, kk_context_t* _ctx) { /* forall<a,e> (r : ref<global,either<() -> e a,a>>, x0 : a) -> <st<global>,div|e> a */ 
  kk_unit_t __ = kk_Unit;
  kk_std_core_types__either _b_21981_21979;
  kk_box_t _x23731 = kk_box_dup(x0); /*2610*/
  _b_21981_21979 = kk_std_core_types__new_Right(_x23731, _ctx); /*either<() -> 2611 2610,2610>*/
  kk_ref_set(r,(kk_std_core_types__either_box(_b_21981_21979, _ctx)),kk_context());
  return x0;
}
 
// Force a delayed value; the value is computed only on the first
// call to `force` and cached afterwards.


// lift anonymous function
struct kk_std_core_force_fun23735__t {
  struct kk_function_s _base;
  kk_std_core__delayed delayed;
};
static kk_box_t kk_std_core_force_fun23735(kk_function_t _fself, kk_box_t x00, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_force_fun23735(kk_std_core__delayed delayed, kk_context_t* _ctx) {
  struct kk_std_core_force_fun23735__t* _self = kk_function_alloc_as(struct kk_std_core_force_fun23735__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_force_fun23735, kk_context());
  _self->delayed = delayed;
  return &_self->_base;
}

static kk_box_t kk_std_core_force_fun23735(kk_function_t _fself, kk_box_t x00, kk_context_t* _ctx) {
  struct kk_std_core_force_fun23735__t* _self = kk_function_as(struct kk_std_core_force_fun23735__t*, _fself);
  kk_std_core__delayed delayed = _self->delayed; /* delayed<2611,2610> */
  kk_drop_match(_self, {kk_std_core__delayed_dup(delayed);}, {}, _ctx)
  kk_ref_t _x23736;
  kk_ref_t _x0 = delayed.dref;
  _x23736 = _x0; /*ref<global,either<() -> 2611 2610,2610>>*/
  return kk_std_core__mlift21170_force(_x23736, x00, _ctx);
}

kk_box_t kk_std_core_force(kk_std_core__delayed delayed, kk_context_t* _ctx) { /* forall<a,e> (delayed : delayed<e,a>) -> e a */ 
  kk_std_core_types__either _match_23635;
  kk_box_t _x23732;
  kk_ref_t _x23733;
  kk_ref_t _x = delayed.dref;
  kk_ref_dup(_x);
  _x23733 = _x; /*ref<global,either<() -> 2611 2610,2610>>*/
  _x23732 = kk_ref_get(_x23733,kk_context()); /*179*/
  _match_23635 = kk_std_core_types__either_unbox(_x23732, _ctx); /*either<() -> 2611 2610,2610>*/
  if (kk_std_core_types__is_Right(_match_23635)) {
    kk_box_t x = _match_23635._cons.Right.right;
    kk_std_core__delayed_drop(delayed, _ctx);
    return x;
  }
  kk_box_t _fun_unbox_x21984 = _match_23635._cons.Left.left;
  kk_box_t x0_21265;
  kk_function_t _x23734 = kk_function_unbox(_fun_unbox_x21984); /*() -> 2611 21985*/
  x0_21265 = kk_std_core_hnd__mask_builtin(_x23734, _ctx); /*2610*/
  kk_function_t next_21266 = kk_std_core_new_force_fun23735(delayed, _ctx); /*(2610) -> <st<global>,div|2611> 2610*/;
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
    struct kk_std_core_Cons* _con23737 = kk_std_core__as_Cons(ys);
    kk_box_t y = _con23737->head;
    kk_std_core__list yy = _con23737->tail;
    kk_reuse_t _ru_23329 = kk_reuse_null; /*reuse*/;
    if (kk_std_core__list_is_unique(ys)) {
      _ru_23329 = (kk_std_core__list_reuse(ys));
    }
    else {
      kk_box_dup(y);
      kk_std_core__list_dup(yy);
      kk_std_core__list_decref(ys, _ctx);
      _ru_23329 = kk_reuse_null;
    }
    kk_std_core__list _ctail_21113;
    kk_std_core__list _ru_23641 = kk_std_core__list_hole(); /*list<2637>*/;
    bool _x23738 = _ru_23329!=NULL; /*bool*/
    if (_x23738) {
      struct kk_std_core_Cons* _con23739 = (struct kk_std_core_Cons*)_ru_23329;
      _con23739->tail = _ru_23641;
      _ctail_21113 = kk_std_core__base_Cons(_con23739); /*list<2637>*/
    }
    else {
      _ctail_21113 = kk_std_core__new_Cons(kk_reuse_null, y, _ru_23641, _ctx); /*list<2637>*/
    }
    kk_std_core__list _ctail_21114;
    kk_box_t _x23740 = kk_box_dup(s); /*2637*/
    kk_std_core__list _x23741 = kk_std_core__list_dup(_ctail_21113); /*list<2637>*/
    _ctail_21114 = kk_std_core__new_Cons(kk_reuse_null, _x23740, _x23741, _ctx); /*list<2637>*/
    { // tailcall
      kk_std_core_types__ctail _x23742;
      kk_box_t* field_21269;
      kk_std_core__list_drop(_ctail_21113, _ctx);
      field_21269 = (kk_box_t*)((&kk_std_core__as_Cons(_ctail_21113)->tail)); /*cfield<list<2637>>*/
      if (kk_std_core_types__is_CTail(_acc)) {
        kk_box_t _box_x21993 = _acc._cons.CTail._field1;
        kk_box_t* last0 = _acc._cons.CTail._field2;
        kk_std_core__list head0 = kk_std_core__list_unbox(_box_x21993, NULL);
        kk_std_core__list_dup(head0);
        kk_std_core_types__ctail_drop(_acc, _ctx);
        kk_unit_t __ = kk_Unit;
        *(last0) = kk_std_core__list_box(_ctail_21114, _ctx);
        _x23742 = kk_std_core_types__new_CTail(kk_std_core__list_box(head0, _ctx), field_21269, _ctx); /*ctail<58>*/
        goto _match23743;
      }
      _x23742 = kk_std_core_types__new_CTail(kk_std_core__list_box(_ctail_21114, _ctx), field_21269, _ctx); /*ctail<58>*/
      _match23743: ;
      ys = yy;
      _acc = _x23742;
      goto kk__tailcall;
    }
  }
  kk_box_drop(s, _ctx);
  if (kk_std_core_types__is_CTail(_acc)) {
    kk_box_t _box_x22002 = _acc._cons.CTail._field1;
    kk_box_t* last00 = _acc._cons.CTail._field2;
    kk_std_core__list head00 = kk_std_core__list_unbox(_box_x22002, NULL);
    kk_std_core__list_dup(head00);
    kk_std_core_types__ctail_drop(_acc, _ctx);
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
    struct kk_std_core_Cons* _con23746 = kk_std_core__as_Cons(xs);
    kk_box_t x = _con23746->head;
    kk_std_core__list xx = _con23746->tail;
    kk_reuse_t _ru_23330 = kk_reuse_null; /*reuse*/;
    if (kk_std_core__list_is_unique(xs)) {
      _ru_23330 = (kk_std_core__list_reuse(xs));
    }
    else {
      kk_box_dup(x);
      kk_std_core__list_dup(xx);
      kk_std_core__list_decref(xs, _ctx);
      _ru_23330 = kk_reuse_null;
    }
    kk_std_core__list _ru_23642 = kk_std_core__lift21048_intersperse(xx, sep, _ctx); /*list<2637>*/;
    bool _x23747 = _ru_23330!=NULL; /*bool*/
    if (_x23747) {
      struct kk_std_core_Cons* _con23748 = (struct kk_std_core_Cons*)_ru_23330;
      _con23748->tail = _ru_23642;
      return kk_std_core__base_Cons(_con23748);
    }
    return kk_std_core__new_Cons(kk_reuse_null, x, _ru_23642, _ctx);
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
  kk_std_core_types__ctail _x23750;
  kk_box_t* field_21274 = (kk_box_t*)((&kk_std_core__as_Cons(_ctail_21117)->tail)); /*cfield<list<2738>>*/;
  if (kk_std_core_types__is_CTail(_acc)) {
    kk_box_t _box_x22017 = _acc._cons.CTail._field1;
    kk_box_t* last0 = _acc._cons.CTail._field2;
    kk_std_core__list head0 = kk_std_core__list_unbox(_box_x22017, NULL);
    kk_std_core__list_dup(head0);
    kk_std_core_types__ctail_drop(_acc, _ctx);
    kk_unit_t __ = kk_Unit;
    *(last0) = kk_std_core__list_box(_ctail_21117, _ctx);
    _x23750 = kk_std_core_types__new_CTail(kk_std_core__list_box(head0, _ctx), field_21274, _ctx); /*ctail<58>*/
    goto _match23751;
  }
  _x23750 = kk_std_core_types__new_CTail(kk_std_core__list_box(_ctail_21117, _ctx), field_21274, _ctx); /*ctail<58>*/
  _match23751: ;
  return kk_std_core__ctail_lift21049_map_peek(f, yy, _x23750, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_core__mlift21172_op_fun23753__t {
  struct kk_function_s _base;
  kk_function_t _accm;
  kk_box_t _ctail_21120;
};
static kk_std_core__list kk_std_core__mlift21172_op_fun23753(kk_function_t _fself, kk_std_core__list _ctail_21119, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_mlift21172_op_fun23753(kk_function_t _accm, kk_box_t _ctail_21120, kk_context_t* _ctx) {
  struct kk_std_core__mlift21172_op_fun23753__t* _self = kk_function_alloc_as(struct kk_std_core__mlift21172_op_fun23753__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__mlift21172_op_fun23753, kk_context());
  _self->_accm = _accm;
  _self->_ctail_21120 = _ctail_21120;
  return &_self->_base;
}

static kk_std_core__list kk_std_core__mlift21172_op_fun23753(kk_function_t _fself, kk_std_core__list _ctail_21119, kk_context_t* _ctx) {
  struct kk_std_core__mlift21172_op_fun23753__t* _self = kk_function_as(struct kk_std_core__mlift21172_op_fun23753__t*, _fself);
  kk_function_t _accm = _self->_accm; /* (list<2738>) -> list<2738> */
  kk_box_t _ctail_21120 = _self->_ctail_21120; /* 2738 */
  kk_drop_match(_self, {kk_function_dup(_accm);kk_box_dup(_ctail_21120);}, {}, _ctx)
  kk_std_core__list _x23754 = kk_std_core__new_Cons(kk_reuse_null, _ctail_21120, _ctail_21119, _ctx); /*list<61>*/
  return kk_function_call(kk_std_core__list, (kk_function_t, kk_std_core__list, kk_context_t*), _accm, (_accm, _x23754, _ctx));
}

kk_std_core__list kk_std_core__mlift21172_op(kk_function_t _accm, kk_function_t f0, kk_std_core__list yy0, kk_box_t _ctail_21120, kk_context_t* _ctx) { /* forall<a,b,e> ((list<b>) -> list<b>, f : (value : a, rest : list<a>) -> e b, yy : list<a>, b) -> e list<b> */ 
  return kk_std_core__ctailm_lift21049_map_peek(f0, yy0, kk_std_core__new_mlift21172_op_fun23753(_accm, _ctail_21120, _ctx), _ctx);
}
 
// lift


// lift anonymous function
struct kk_std_core__ctail_lift21049_map_peek_fun23759__t {
  struct kk_function_s _base;
  kk_function_t f1;
  kk_std_core__list yy1;
  kk_std_core_types__ctail _acc0;
};
static kk_box_t kk_std_core__ctail_lift21049_map_peek_fun23759(kk_function_t _fself, kk_box_t _b_22031, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_ctail_lift21049_map_peek_fun23759(kk_function_t f1, kk_std_core__list yy1, kk_std_core_types__ctail _acc0, kk_context_t* _ctx) {
  struct kk_std_core__ctail_lift21049_map_peek_fun23759__t* _self = kk_function_alloc_as(struct kk_std_core__ctail_lift21049_map_peek_fun23759__t, 5, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__ctail_lift21049_map_peek_fun23759, kk_context());
  _self->f1 = f1;
  _self->yy1 = yy1;
  _self->_acc0 = _acc0;
  return &_self->_base;
}

static kk_box_t kk_std_core__ctail_lift21049_map_peek_fun23759(kk_function_t _fself, kk_box_t _b_22031, kk_context_t* _ctx) {
  struct kk_std_core__ctail_lift21049_map_peek_fun23759__t* _self = kk_function_as(struct kk_std_core__ctail_lift21049_map_peek_fun23759__t*, _fself);
  kk_function_t f1 = _self->f1; /* (value : 2737, rest : list<2737>) -> 2739 2738 */
  kk_std_core__list yy1 = _self->yy1; /* list<2737> */
  kk_std_core_types__ctail _acc0 = _self->_acc0; /* ctail<list<2738>> */
  kk_drop_match(_self, {kk_function_dup(f1);kk_std_core__list_dup(yy1);kk_std_core_types__ctail_dup(_acc0);}, {}, _ctx)
  kk_std_core__list _x23760 = kk_std_core__mlift21171_op(_acc0, f1, yy1, _b_22031, _ctx); /*list<2738>*/
  return kk_std_core__list_box(_x23760, _ctx);
}

kk_std_core__list kk_std_core__ctail_lift21049_map_peek(kk_function_t f1, kk_std_core__list ys, kk_std_core_types__ctail _acc0, kk_context_t* _ctx) { /* forall<a,b,e> (f : (value : a, rest : list<a>) -> e b, ys : list<a>, ctail<list<b>>) -> e list<b> */ 
  kk__tailcall: ;
  if (kk_std_core__is_Cons(ys)) {
    struct kk_std_core_Cons* _con23755 = kk_std_core__as_Cons(ys);
    kk_box_t y = _con23755->head;
    kk_std_core__list yy1 = _con23755->tail;
    kk_reuse_t _ru_23331 = kk_reuse_null; /*reuse*/;
    if (kk_std_core__list_is_unique(ys)) {
      _ru_23331 = (kk_std_core__list_reuse(ys));
    }
    else {
      kk_box_dup(y);
      kk_std_core__list_dup(yy1);
      kk_std_core__list_decref(ys, _ctx);
      _ru_23331 = kk_reuse_null;
    }
    kk_box_t x_21275;
    kk_function_t _x23757 = kk_function_dup(f1); /*(value : 2737, rest : list<2737>) -> 2739 2738*/
    kk_std_core__list _x23756 = kk_std_core__list_dup(yy1); /*list<2737>*/
    x_21275 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_std_core__list, kk_context_t*), _x23757, (_x23757, y, _x23756, _ctx)); /*2738*/
    if (kk_yielding(kk_context())) {
      kk_reuse_drop(_ru_23331, _ctx);
      kk_box_drop(x_21275, _ctx);
      kk_box_t _x23758 = kk_std_core_hnd_yield_extend(kk_std_core__new_ctail_lift21049_map_peek_fun23759(f1, yy1, _acc0, _ctx), _ctx); /*3991*/
      return kk_std_core__list_unbox(_x23758, _ctx);
    }
    kk_std_core__list _ctail_211160 = kk_std_core__list_hole(); /*list<2738>*/;
    kk_std_core__list _ctail_211170 = kk_std_core__new_Cons(_ru_23331, x_21275, _ctail_211160, _ctx); /*list<2738>*/;
    { // tailcall
      kk_std_core_types__ctail _x23761;
      kk_box_t* field_21281 = (kk_box_t*)((&kk_std_core__as_Cons(_ctail_211170)->tail)); /*cfield<list<2738>>*/;
      if (kk_std_core_types__is_CTail(_acc0)) {
        kk_box_t _box_x22038 = _acc0._cons.CTail._field1;
        kk_box_t* last2 = _acc0._cons.CTail._field2;
        kk_std_core__list head1 = kk_std_core__list_unbox(_box_x22038, NULL);
        kk_std_core__list_dup(head1);
        kk_std_core_types__ctail_drop(_acc0, _ctx);
        kk_unit_t __0 = kk_Unit;
        *(last2) = kk_std_core__list_box(_ctail_211170, _ctx);
        _x23761 = kk_std_core_types__new_CTail(kk_std_core__list_box(head1, _ctx), field_21281, _ctx); /*ctail<58>*/
        goto _match23762;
      }
      _x23761 = kk_std_core_types__new_CTail(kk_std_core__list_box(_ctail_211170, _ctx), field_21281, _ctx); /*ctail<58>*/
      _match23762: ;
      ys = yy1;
      _acc0 = _x23761;
      goto kk__tailcall;
    }
  }
  kk_function_drop(f1, _ctx);
  if (kk_std_core_types__is_CTail(_acc0)) {
    kk_box_t _box_x22047 = _acc0._cons.CTail._field1;
    kk_box_t* last00 = _acc0._cons.CTail._field2;
    kk_std_core__list head00 = kk_std_core__list_unbox(_box_x22047, NULL);
    kk_std_core__list_dup(head00);
    kk_std_core_types__ctail_drop(_acc0, _ctx);
    kk_unit_t __00 = kk_Unit;
    *(last00) = kk_std_core__list_box(kk_std_core__new_Nil(_ctx), _ctx);
    return head00;
  }
  return kk_std_core__new_Nil(_ctx);
}
 
// lift


// lift anonymous function
struct kk_std_core__ctailm_lift21049_map_peek_fun23769__t {
  struct kk_function_s _base;
  kk_function_t _accm0;
  kk_function_t f2;
  kk_std_core__list yy2;
};
static kk_box_t kk_std_core__ctailm_lift21049_map_peek_fun23769(kk_function_t _fself, kk_box_t _b_22059, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_ctailm_lift21049_map_peek_fun23769(kk_function_t _accm0, kk_function_t f2, kk_std_core__list yy2, kk_context_t* _ctx) {
  struct kk_std_core__ctailm_lift21049_map_peek_fun23769__t* _self = kk_function_alloc_as(struct kk_std_core__ctailm_lift21049_map_peek_fun23769__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__ctailm_lift21049_map_peek_fun23769, kk_context());
  _self->_accm0 = _accm0;
  _self->f2 = f2;
  _self->yy2 = yy2;
  return &_self->_base;
}

static kk_box_t kk_std_core__ctailm_lift21049_map_peek_fun23769(kk_function_t _fself, kk_box_t _b_22059, kk_context_t* _ctx) {
  struct kk_std_core__ctailm_lift21049_map_peek_fun23769__t* _self = kk_function_as(struct kk_std_core__ctailm_lift21049_map_peek_fun23769__t*, _fself);
  kk_function_t _accm0 = _self->_accm0; /* (list<2738>) -> list<2738> */
  kk_function_t f2 = _self->f2; /* (value : 2737, rest : list<2737>) -> 2739 2738 */
  kk_std_core__list yy2 = _self->yy2; /* list<2737> */
  kk_drop_match(_self, {kk_function_dup(_accm0);kk_function_dup(f2);kk_std_core__list_dup(yy2);}, {}, _ctx)
  kk_std_core__list _x23770 = kk_std_core__mlift21172_op(_accm0, f2, yy2, _b_22059, _ctx); /*list<2738>*/
  return kk_std_core__list_box(_x23770, _ctx);
}


// lift anonymous function
struct kk_std_core__ctailm_lift21049_map_peek_fun23772__t {
  struct kk_function_s _base;
  kk_function_t _accm0;
  kk_box_t x_21284;
};
static kk_std_core__list kk_std_core__ctailm_lift21049_map_peek_fun23772(kk_function_t _fself, kk_std_core__list _ctail_211190, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_ctailm_lift21049_map_peek_fun23772(kk_function_t _accm0, kk_box_t x_21284, kk_context_t* _ctx) {
  struct kk_std_core__ctailm_lift21049_map_peek_fun23772__t* _self = kk_function_alloc_as(struct kk_std_core__ctailm_lift21049_map_peek_fun23772__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__ctailm_lift21049_map_peek_fun23772, kk_context());
  _self->_accm0 = _accm0;
  _self->x_21284 = x_21284;
  return &_self->_base;
}

static kk_std_core__list kk_std_core__ctailm_lift21049_map_peek_fun23772(kk_function_t _fself, kk_std_core__list _ctail_211190, kk_context_t* _ctx) {
  struct kk_std_core__ctailm_lift21049_map_peek_fun23772__t* _self = kk_function_as(struct kk_std_core__ctailm_lift21049_map_peek_fun23772__t*, _fself);
  kk_function_t _accm0 = _self->_accm0; /* (list<2738>) -> list<2738> */
  kk_box_t x_21284 = _self->x_21284; /* 2738 */
  kk_drop_match(_self, {kk_function_dup(_accm0);kk_box_dup(x_21284);}, {}, _ctx)
  kk_std_core__list _x23773 = kk_std_core__new_Cons(kk_reuse_null, x_21284, _ctail_211190, _ctx); /*list<61>*/
  return kk_function_call(kk_std_core__list, (kk_function_t, kk_std_core__list, kk_context_t*), _accm0, (_accm0, _x23773, _ctx));
}

kk_std_core__list kk_std_core__ctailm_lift21049_map_peek(kk_function_t f2, kk_std_core__list ys0, kk_function_t _accm0, kk_context_t* _ctx) { /* forall<a,b,e> (f : (value : a, rest : list<a>) -> e b, ys : list<a>, (list<b>) -> list<b>) -> e list<b> */ 
  kk__tailcall: ;
  if (kk_std_core__is_Cons(ys0)) {
    struct kk_std_core_Cons* _con23765 = kk_std_core__as_Cons(ys0);
    kk_box_t y0 = _con23765->head;
    kk_std_core__list yy2 = _con23765->tail;
    if (kk_std_core__list_is_unique(ys0)) {
      kk_std_core__list_free(ys0);
    }
    else {
      kk_box_dup(y0);
      kk_std_core__list_dup(yy2);
      kk_std_core__list_decref(ys0, _ctx);
    }
    kk_box_t x_21284;
    kk_function_t _x23767 = kk_function_dup(f2); /*(value : 2737, rest : list<2737>) -> 2739 2738*/
    kk_std_core__list _x23766 = kk_std_core__list_dup(yy2); /*list<2737>*/
    x_21284 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_std_core__list, kk_context_t*), _x23767, (_x23767, y0, _x23766, _ctx)); /*2738*/
    if (kk_yielding(kk_context())) {
      kk_box_drop(x_21284, _ctx);
      kk_box_t _x23768 = kk_std_core_hnd_yield_extend(kk_std_core__new_ctailm_lift21049_map_peek_fun23769(_accm0, f2, yy2, _ctx), _ctx); /*3991*/
      return kk_std_core__list_unbox(_x23768, _ctx);
    }
    { // tailcall
      kk_function_t _x23771 = kk_std_core__new_ctailm_lift21049_map_peek_fun23772(_accm0, x_21284, _ctx); /*(list<2738>) -> list<2738>*/
      ys0 = yy2;
      _accm0 = _x23771;
      goto kk__tailcall;
    }
  }
  kk_function_drop(f2, _ctx);
  return kk_function_call(kk_std_core__list, (kk_function_t, kk_std_core__list, kk_context_t*), _accm0, (_accm0, kk_std_core__new_Nil(_ctx), _ctx));
}
 
// lift


// lift anonymous function
struct kk_std_core__lift21049_map_peek_fun23774__t {
  struct kk_function_s _base;
};
static kk_std_core__list kk_std_core__lift21049_map_peek_fun23774(kk_function_t _fself, kk_std_core__list _ctail_21118, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_lift21049_map_peek_fun23774(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core__lift21049_map_peek_fun23774, _ctx)
  return kk_function_dup(_fself);
}

static kk_std_core__list kk_std_core__lift21049_map_peek_fun23774(kk_function_t _fself, kk_std_core__list _ctail_21118, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return _ctail_21118;
}

kk_std_core__list kk_std_core__lift21049_map_peek(kk_function_t f3, kk_std_core__list ys1, kk_context_t* _ctx) { /* forall<a,b,e> (f : (value : a, rest : list<a>) -> e b, ys : list<a>) -> e list<b> */ 
  bool _match_23632 = kk_std_core_hnd__evv_is_affine(_ctx); /*bool*/;
  if (_match_23632) {
    return kk_std_core__ctail_lift21049_map_peek(f3, ys1, kk_std_core_types__new_CTailNil(_ctx), _ctx);
  }
  return kk_std_core__ctailm_lift21049_map_peek(f3, ys1, kk_std_core__new_lift21049_map_peek_fun23774(_ctx), _ctx);
}

kk_integer_t kk_std_core_maxListStack;

kk_ref_t kk_std_core_trace_enabled;
 
// Compose two funs `f` and `g`.


// lift anonymous function
struct kk_std_core_o_fun23776__t {
  struct kk_function_s _base;
  kk_function_t f;
  kk_function_t g;
};
static kk_box_t kk_std_core_o_fun23776(kk_function_t _fself, kk_box_t x, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_o_fun23776(kk_function_t f, kk_function_t g, kk_context_t* _ctx) {
  struct kk_std_core_o_fun23776__t* _self = kk_function_alloc_as(struct kk_std_core_o_fun23776__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_o_fun23776, kk_context());
  _self->f = f;
  _self->g = g;
  return &_self->_base;
}

static kk_box_t kk_std_core_o_fun23776(kk_function_t _fself, kk_box_t x, kk_context_t* _ctx) {
  struct kk_std_core_o_fun23776__t* _self = kk_function_as(struct kk_std_core_o_fun23776__t*, _fself);
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
  return kk_std_core_new_o_fun23776(f, g, _ctx);
}
 
// Given a total function to calculate a value `:a`, return
// a total function that only calculates the value once and then
// returns the cached result.


// lift anonymous function
struct kk_std_core_once_fun23779__t {
  struct kk_function_s _base;
  kk_function_t calc;
  kk_ref_t r;
};
static kk_box_t kk_std_core_once_fun23779(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_once_fun23779(kk_function_t calc, kk_ref_t r, kk_context_t* _ctx) {
  struct kk_std_core_once_fun23779__t* _self = kk_function_alloc_as(struct kk_std_core_once_fun23779__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_once_fun23779, kk_context());
  _self->calc = calc;
  _self->r = r;
  return &_self->_base;
}

static kk_box_t kk_std_core_once_fun23779(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_core_once_fun23779__t* _self = kk_function_as(struct kk_std_core_once_fun23779__t*, _fself);
  kk_function_t calc = _self->calc; /* () -> 2945 */
  kk_ref_t r = _self->r; /* ref<_2851,maybe<2945>> */
  kk_drop_match(_self, {kk_function_dup(calc);kk_ref_dup(r);}, {}, _ctx)
  kk_std_core_types__maybe _match_23630;
  kk_box_t _x23780;
  kk_ref_t _x23781 = kk_ref_dup(r); /*ref<_2851,maybe<2945>>*/
  _x23780 = kk_ref_get(_x23781,kk_context()); /*179*/
  _match_23630 = kk_std_core_types__maybe_unbox(_x23780, _ctx); /*maybe<2945>*/
  if (kk_std_core_types__is_Just(_match_23630)) {
    kk_box_t x = _match_23630._cons.Just.value;
    kk_function_drop(calc, _ctx);
    kk_ref_drop(r, _ctx);
    return x;
  }
  kk_box_t x0 = kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), calc, (calc, _ctx)); /*2945*/;
  kk_unit_t __ = kk_Unit;
  kk_std_core_types__maybe _b_22071_22069;
  kk_box_t _x23782 = kk_box_dup(x0); /*2945*/
  _b_22071_22069 = kk_std_core_types__new_Just(_x23782, _ctx); /*maybe<2945>*/
  kk_ref_set(r,(kk_std_core_types__maybe_box(_b_22071_22069, _ctx)),kk_context());
  return x0;
}

kk_function_t kk_std_core_once(kk_function_t calc, kk_context_t* _ctx) { /* forall<a> (calc : () -> a) -> (() -> a) */ 
  kk_ref_t r = kk_ref_alloc((kk_std_core_types__maybe_box(kk_std_core_types__new_Nothing(_ctx), _ctx)),kk_context()); /*ref<_2851,maybe<2945>>*/;
  return kk_std_core_new_once_fun23779(calc, r, _ctx);
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
    struct kk_std_core_Cons* _con23793 = kk_std_core__as_Cons(xs);
    kk_box_t x = _con23793->head;
    kk_std_core__list xx = _con23793->tail;
    kk_reuse_t _ru_23333 = kk_reuse_null; /*reuse*/;
    if (kk_std_core__list_is_unique(xs)) {
      _ru_23333 = (kk_std_core__list_reuse(xs));
    }
    else {
      kk_box_dup(x);
      kk_std_core__list_dup(xx);
      kk_std_core__list_decref(xs, _ctx);
      _ru_23333 = kk_reuse_null;
    }
    kk_std_core__list _ctail_21121 = kk_std_core__list_hole(); /*list<3560>*/;
    kk_std_core__list _ctail_21122;
    bool _x23794 = _ru_23333!=NULL; /*bool*/
    if (_x23794) {
      struct kk_std_core_Cons* _con23795 = (struct kk_std_core_Cons*)_ru_23333;
      _con23795->tail = _ctail_21121;
      _ctail_21122 = kk_std_core__base_Cons(_con23795); /*list<3560>*/
    }
    else {
      _ctail_21122 = kk_std_core__new_Cons(kk_reuse_null, x, _ctail_21121, _ctx); /*list<3560>*/
    }
    { // tailcall
      kk_std_core_types__ctail _x23796;
      kk_box_t* field_21296 = (kk_box_t*)((&kk_std_core__as_Cons(_ctail_21122)->tail)); /*cfield<list<3560>>*/;
      if (kk_std_core_types__is_CTail(_acc)) {
        kk_box_t _box_x22081 = _acc._cons.CTail._field1;
        kk_box_t* last0 = _acc._cons.CTail._field2;
        kk_std_core__list head0 = kk_std_core__list_unbox(_box_x22081, NULL);
        kk_std_core__list_dup(head0);
        kk_std_core_types__ctail_drop(_acc, _ctx);
        kk_unit_t __ = kk_Unit;
        *(last0) = kk_std_core__list_box(_ctail_21122, _ctx);
        _x23796 = kk_std_core_types__new_CTail(kk_std_core__list_box(head0, _ctx), field_21296, _ctx); /*ctail<58>*/
        goto _match23797;
      }
      _x23796 = kk_std_core_types__new_CTail(kk_std_core__list_box(_ctail_21122, _ctx), field_21296, _ctx); /*ctail<58>*/
      _match23797: ;
      xs = xx;
      _acc = _x23796;
      goto kk__tailcall;
    }
  }
  kk_box_t _x23799 = kk_std_core_types__ctail_resolve(_acc, kk_std_core__list_box(ys, _ctx), _ctx); /*-1*/
  return kk_std_core__list_unbox(_x23799, _ctx);
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
  kk_std_core_types__maybe _match_23629;
  kk_box_t _x23802;
  kk_ref_t _x23803 = kk_ref_dup(kk_std_core_redirect); /*ref<global,maybe<(string) -> console ()>>*/
  _x23802 = kk_ref_get(_x23803,kk_context()); /*179*/
  _match_23629 = kk_std_core_types__maybe_unbox(_x23802, _ctx); /*maybe<(string) -> console ()>*/
  if (kk_std_core_types__is_Nothing(_match_23629)) {
    kk_std_core_xprintsln(s, _ctx); return kk_Unit;
  }
  kk_box_t _fun_unbox_x22102 = _match_23629._cons.Just.value;
  kk_string_t _b_22107_22105;
  kk_string_t _x23804;
  kk_define_string_literal(, _s23805, 1, "\n")
  _x23804 = kk_string_dup(_s23805); /*string*/
  _b_22107_22105 = kk_std_core__lp__plus__plus__1_rp_(s, _x23804, _ctx); /*string*/
  kk_box_t _x23806;
  kk_function_t _x23807 = kk_function_unbox(_fun_unbox_x22102); /*(22103) -> console 22104*/
  _x23806 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x23807, (_x23807, kk_string_box(_b_22107_22105), _ctx)); /*22104*/
  kk_unit_unbox(_x23806); return kk_Unit;
}

kk_std_core_types__order kk_std_core_order(kk_integer_t i, kk_context_t* _ctx) { /* (i : int) -> order */ 
  bool _match_23626;
  kk_integer_t _x23812 = kk_integer_dup(i); /*int*/
  _match_23626 = kk_integer_lt(_x23812,(kk_integer_from_small(0)),kk_context()); /*bool*/
  if (_match_23626) {
    kk_integer_drop(i, _ctx);
    return kk_std_core_types__new_Lt(_ctx);
  }
  bool _match_23627 = kk_integer_gt(i,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  if (_match_23627) {
    return kk_std_core_types__new_Gt(_ctx);
  }
  return kk_std_core_types__new_Eq(_ctx);
}
 
// Compare two strings.
// Uses the character codes directly for comparison

kk_std_core_types__order kk_std_core_compare_4(kk_string_t x, kk_string_t y, kk_context_t* _ctx) { /* (x : string, y : string) -> order */ 
  kk_integer_t i_21297 = kk_std_core_string_compare(x, y, _ctx); /*int*/;
  bool _match_23624;
  kk_integer_t _x23813 = kk_integer_dup(i_21297); /*int*/
  _match_23624 = kk_integer_lt(_x23813,(kk_integer_from_small(0)),kk_context()); /*bool*/
  if (_match_23624) {
    kk_integer_drop(i_21297, _ctx);
    return kk_std_core_types__new_Lt(_ctx);
  }
  bool _match_23625 = kk_integer_gt(i_21297,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  if (_match_23625) {
    return kk_std_core_types__new_Gt(_ctx);
  }
  return kk_std_core_types__new_Eq(_ctx);
}

bool kk_std_core__lp__lt__7_rp_(kk_string_t x, kk_string_t y, kk_context_t* _ctx) { /* (x : string, y : string) -> bool */ 
  kk_std_core_types__order x0_21298 = kk_std_core_compare_4(x, y, _ctx); /*order*/;
  kk_integer_t _x23814 = kk_std_core_int_5(x0_21298, _ctx); /*int*/
  kk_integer_t _x23815;
  kk_std_core_types__order _x23816 = kk_std_core_types__new_Lt(_ctx); /*order*/
  if (kk_std_core_types__is_Lt(_x23816)) {
    _x23815 = kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context()); /*int*/
    goto _match23817;
  }
  if (kk_std_core_types__is_Eq(_x23816)) {
    _x23815 = kk_integer_from_small(0); /*int*/
    goto _match23817;
  }
  _x23815 = kk_integer_from_small(1); /*int*/
  _match23817: ;
  return kk_integer_eq(_x23814,_x23815,kk_context());
}

bool kk_std_core__lp__gt__5_rp_(kk_string_t x, kk_string_t y, kk_context_t* _ctx) { /* (x : string, y : string) -> bool */ 
  kk_std_core_types__order x0_21300 = kk_std_core_compare_4(x, y, _ctx); /*order*/;
  kk_integer_t _x23820 = kk_std_core_int_5(x0_21300, _ctx); /*int*/
  kk_integer_t _x23821;
  kk_std_core_types__order _x23822 = kk_std_core_types__new_Gt(_ctx); /*order*/
  if (kk_std_core_types__is_Lt(_x23822)) {
    _x23821 = kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context()); /*int*/
    goto _match23823;
  }
  if (kk_std_core_types__is_Eq(_x23822)) {
    _x23821 = kk_integer_from_small(0); /*int*/
    goto _match23823;
  }
  _x23821 = kk_integer_from_small(1); /*int*/
  _match23823: ;
  return kk_integer_eq(_x23820,_x23821,kk_context());
}

bool kk_std_core__lp__gt__eq__5_rp_(kk_string_t x, kk_string_t y, kk_context_t* _ctx) { /* (x : string, y : string) -> bool */ 
  kk_std_core_types__order x0_21302 = kk_std_core_compare_4(x, y, _ctx); /*order*/;
  kk_integer_t _x23827 = kk_std_core_int_5(x0_21302, _ctx); /*int*/
  kk_integer_t _x23828;
  kk_std_core_types__order _x23829 = kk_std_core_types__new_Lt(_ctx); /*order*/
  if (kk_std_core_types__is_Lt(_x23829)) {
    _x23828 = kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context()); /*int*/
    goto _match23830;
  }
  if (kk_std_core_types__is_Eq(_x23829)) {
    _x23828 = kk_integer_from_small(0); /*int*/
    goto _match23830;
  }
  _x23828 = kk_integer_from_small(1); /*int*/
  _match23830: ;
  return kk_integer_gt(_x23827,_x23828,kk_context());
}
 
// lift

kk_string_t kk_std_core__lift21050_joinsep(kk_string_t sep, kk_std_core__list ys, kk_string_t acc, kk_context_t* _ctx) { /* (sep : string, ys : list<string>, acc : string) -> string */ 
  kk__tailcall: ;
  if (kk_std_core__is_Cons(ys)) {
    struct kk_std_core_Cons* _con23831 = kk_std_core__as_Cons(ys);
    kk_box_t _box_x22108 = _con23831->head;
    kk_std_core__list yy = _con23831->tail;
    kk_string_t y = kk_string_unbox(_box_x22108);
    if (kk_std_core__list_is_unique(ys)) {
      kk_std_core__list_free(ys);
    }
    else {
      kk_string_dup(y);
      kk_std_core__list_dup(yy);
      kk_std_core__list_decref(ys, _ctx);
    }
    kk_string_t acc0_21072;
    kk_string_t _x23833;
    kk_string_t _x23834 = kk_string_dup(sep); /*string*/
    _x23833 = kk_std_core__lp__plus__plus__1_rp_(_x23834, y, _ctx); /*string*/
    acc0_21072 = kk_std_core__lp__plus__plus__1_rp_(acc, _x23833, _ctx); /*string*/
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
  struct kk_std_core_Cons* _con23836 = kk_std_core__as_Cons(xs);
  kk_box_t _box_x22109 = _con23836->head;
  kk_std_core__list xx = _con23836->tail;
  kk_string_t x = kk_string_unbox(_box_x22109);
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
  struct kk_std_core_Cons* _con23839 = kk_std_core__as_Cons(xs);
  kk_box_t _box_x22110 = _con23839->head;
  kk_std_core__list xx = _con23839->tail;
  kk_string_t x = kk_string_unbox(_box_x22110);
  if (kk_std_core__list_is_unique(xs)) {
    kk_std_core__list_free(xs);
  }
  else {
    kk_string_dup(x);
    kk_std_core__list_dup(xx);
    kk_std_core__list_decref(xs, _ctx);
  }
  kk_string_t _x23841 = kk_string_empty(); /*string*/
  return kk_std_core__lift21050_joinsep(_x23841, xx, x, _ctx);
}

size_t kk_std_core_decr_1(size_t i, kk_context_t* _ctx) { /* (i : size_t) -> size_t */ 
  return (i - 1);
}

bool kk_std_core__lp__lt__eq__7_rp_(kk_string_t x, kk_string_t y, kk_context_t* _ctx) { /* (x : string, y : string) -> bool */ 
  kk_std_core_types__order x0_21306 = kk_std_core_compare_4(x, y, _ctx); /*order*/;
  kk_integer_t _x23848 = kk_std_core_int_5(x0_21306, _ctx); /*int*/
  kk_integer_t _x23849;
  kk_std_core_types__order _x23850 = kk_std_core_types__new_Gt(_ctx); /*order*/
  if (kk_std_core_types__is_Lt(_x23850)) {
    _x23849 = kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context()); /*int*/
    goto _match23851;
  }
  if (kk_std_core_types__is_Eq(_x23850)) {
    _x23849 = kk_integer_from_small(0); /*int*/
    goto _match23851;
  }
  _x23849 = kk_integer_from_small(1); /*int*/
  _match23851: ;
  return kk_integer_lt(_x23848,_x23849,kk_context());
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
struct kk_std_core__lift21051_forz_fun23854__t {
  struct kk_function_s _base;
  kk_function_t action0;
  size_t end0;
  size_t i0;
};
static kk_box_t kk_std_core__lift21051_forz_fun23854(kk_function_t _fself, kk_box_t _b_22112, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_lift21051_forz_fun23854(kk_function_t action0, size_t end0, size_t i0, kk_context_t* _ctx) {
  struct kk_std_core__lift21051_forz_fun23854__t* _self = kk_function_alloc_as(struct kk_std_core__lift21051_forz_fun23854__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__lift21051_forz_fun23854, kk_context());
  _self->action0 = action0;
  _self->end0 = end0;
  _self->i0 = i0;
  return &_self->_base;
}

static kk_box_t kk_std_core__lift21051_forz_fun23854(kk_function_t _fself, kk_box_t _b_22112, kk_context_t* _ctx) {
  struct kk_std_core__lift21051_forz_fun23854__t* _self = kk_function_as(struct kk_std_core__lift21051_forz_fun23854__t*, _fself);
  kk_function_t action0 = _self->action0; /* (size_t) -> 5520 () */
  size_t end0 = _self->end0; /* size_t */
  size_t i0 = _self->i0; /* size_t */
  kk_drop_match(_self, {kk_function_dup(action0);;;}, {}, _ctx)
  kk_unit_t _x23855 = kk_Unit;
  kk_unit_t _x23856 = kk_Unit;
  kk_unit_unbox(_b_22112);
  kk_std_core__mlift21173_op(action0, end0, i0, _x23856, _ctx);
  return kk_unit_box(_x23855);
}

kk_unit_t kk_std_core__lift21051_forz(kk_function_t action0, size_t end0, size_t i0, kk_context_t* _ctx) { /* forall<e> (action : (size_t) -> e (), end : size_t, i : size_t) -> e () */ 
  kk__tailcall: ;
  bool _match_23612 = (i0 <= end0); /*bool*/;
  if (_match_23612) {
    kk_unit_t x_21308 = kk_Unit;
    kk_function_t _x23852 = kk_function_dup(action0); /*(size_t) -> 5520 ()*/
    kk_function_call(kk_unit_t, (kk_function_t, size_t, kk_context_t*), _x23852, (_x23852, i0, _ctx));
    if (kk_yielding(kk_context())) {
      kk_box_t _x23853 = kk_std_core_hnd_yield_extend(kk_std_core__new_lift21051_forz_fun23854(action0, end0, i0, _ctx), _ctx); /*3991*/
      kk_unit_unbox(_x23853); return kk_Unit;
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
struct kk_std_core_foreach_indexedz_fun23859__t {
  struct kk_function_s _base;
  kk_function_t f;
  kk_vector_t v;
};
static kk_unit_t kk_std_core_foreach_indexedz_fun23859(kk_function_t _fself, size_t i, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_foreach_indexedz_fun23859(kk_function_t f, kk_vector_t v, kk_context_t* _ctx) {
  struct kk_std_core_foreach_indexedz_fun23859__t* _self = kk_function_alloc_as(struct kk_std_core_foreach_indexedz_fun23859__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_foreach_indexedz_fun23859, kk_context());
  _self->f = f;
  _self->v = v;
  return &_self->_base;
}

static kk_unit_t kk_std_core_foreach_indexedz_fun23859(kk_function_t _fself, size_t i, kk_context_t* _ctx) {
  struct kk_std_core_foreach_indexedz_fun23859__t* _self = kk_function_as(struct kk_std_core_foreach_indexedz_fun23859__t*, _fself);
  kk_function_t f = _self->f; /* (5617, size_t) -> 5618 () */
  kk_vector_t v = _self->v; /* vector<5617> */
  kk_drop_match(_self, {kk_function_dup(f);kk_vector_dup(v);}, {}, _ctx)
  kk_box_t _x23860 = kk_vector_at(v,i); /*216*/
  return kk_function_call(kk_unit_t, (kk_function_t, kk_box_t, size_t, kk_context_t*), f, (f, _x23860, i, _ctx));
}

kk_unit_t kk_std_core_foreach_indexedz(kk_vector_t v, kk_function_t f, kk_context_t* _ctx) { /* forall<a,e> (v : vector<a>, f : (a, size_t) -> e ()) -> e () */ 
  size_t start_21312 = ((size_t)0); /*size_t*/;
  size_t end_21313;
  size_t _x23857;
  kk_vector_t _x23858 = kk_vector_dup(v); /*vector<5617>*/
  _x23857 = kk_vector_len(_x23858); /*size_t*/
  end_21313 = kk_std_core_decr_1(_x23857, _ctx); /*size_t*/
  kk_std_core__lift21051_forz(kk_std_core_new_foreach_indexedz_fun23859(f, v, _ctx), end_21313, start_21312, _ctx); return kk_Unit;
}
 
// lift

kk_integer_t kk_std_core__lift21052_length_1(kk_std_core__list ys, kk_integer_t acc, kk_context_t* _ctx) { /* forall<a> (ys : list<a>, acc : int) -> int */ 
  kk__tailcall: ;
  if (kk_std_core__is_Cons(ys)) {
    struct kk_std_core_Cons* _con23861 = kk_std_core__as_Cons(ys);
    kk_box_t _pat0 = _con23861->head;
    kk_std_core__list yy = _con23861->tail;
    if (kk_std_core__list_is_unique(ys)) {
      kk_box_drop(_pat0, _ctx);
      kk_std_core__list_free(ys);
    }
    else {
      kk_std_core__list_dup(yy);
      kk_std_core__list_decref(ys, _ctx);
    }
    { // tailcall
      kk_integer_t _x23862 = kk_integer_add(acc,(kk_integer_from_small(1)),kk_context()); /*int*/
      ys = yy;
      acc = _x23862;
      goto kk__tailcall;
    }
  }
  return acc;
}
 
// lift

kk_std_core__list kk_std_core__lift21053_list(kk_integer_t low, kk_integer_t high, kk_std_core__list acc, kk_context_t* _ctx) { /* (low : int, high : int, acc : list<int>) -> list<int> */ 
  kk__tailcall: ;
  bool _match_23611;
  kk_integer_t _x23864 = kk_integer_dup(low); /*int*/
  kk_integer_t _x23865 = kk_integer_dup(high); /*int*/
  _match_23611 = kk_integer_gt(_x23864,_x23865,kk_context()); /*bool*/
  if (_match_23611) {
    kk_integer_drop(high, _ctx);
    kk_integer_drop(low, _ctx);
    return acc;
  }
  { // tailcall
    kk_integer_t _x23866;
    kk_integer_t _x23867 = kk_integer_dup(high); /*int*/
    _x23866 = kk_integer_sub(_x23867,(kk_integer_from_small(1)),kk_context()); /*int*/
    kk_std_core__list _x23868 = kk_std_core__new_Cons(kk_reuse_null, kk_integer_box(high), acc, _ctx); /*list<61>*/
    high = _x23866;
    acc = _x23868;
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
struct kk_std_core__lift21054_list_fun23874__t_1 {
  struct kk_function_s _base;
  kk_std_core__list acc0;
  kk_function_t f0;
  kk_integer_t high0_210760;
  kk_integer_t low0;
};
static kk_box_t kk_std_core__lift21054_list_fun23874_1(kk_function_t _fself, kk_box_t _b_22120, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_lift21054_list_fun23874_1(kk_std_core__list acc0, kk_function_t f0, kk_integer_t high0_210760, kk_integer_t low0, kk_context_t* _ctx) {
  struct kk_std_core__lift21054_list_fun23874__t_1* _self = kk_function_alloc_as(struct kk_std_core__lift21054_list_fun23874__t_1, 5, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__lift21054_list_fun23874_1, kk_context());
  _self->acc0 = acc0;
  _self->f0 = f0;
  _self->high0_210760 = high0_210760;
  _self->low0 = low0;
  return &_self->_base;
}

static kk_box_t kk_std_core__lift21054_list_fun23874_1(kk_function_t _fself, kk_box_t _b_22120, kk_context_t* _ctx) {
  struct kk_std_core__lift21054_list_fun23874__t_1* _self = kk_function_as(struct kk_std_core__lift21054_list_fun23874__t_1*, _fself);
  kk_std_core__list acc0 = _self->acc0; /* list<6015> */
  kk_function_t f0 = _self->f0; /* (int) -> 6016 6015 */
  kk_integer_t high0_210760 = _self->high0_210760; /* int */
  kk_integer_t low0 = _self->low0; /* int */
  kk_drop_match(_self, {kk_std_core__list_dup(acc0);kk_function_dup(f0);kk_integer_dup(high0_210760);kk_integer_dup(low0);}, {}, _ctx)
  kk_std_core__list _x23875 = kk_std_core__mlift21174_op(acc0, f0, high0_210760, low0, _b_22120, _ctx); /*list<6015>*/
  return kk_std_core__list_box(_x23875, _ctx);
}

kk_std_core__list kk_std_core__lift21054_list_1(kk_function_t f0, kk_integer_t low0, kk_integer_t high, kk_std_core__list acc0, kk_context_t* _ctx) { /* forall<a,e> (f : (int) -> e a, low : int, high : int, acc : list<a>) -> e list<a> */ 
  kk__tailcall: ;
  bool _match_23609;
  kk_integer_t _x23869 = kk_integer_dup(low0); /*int*/
  kk_integer_t _x23870 = kk_integer_dup(high); /*int*/
  _match_23609 = kk_integer_gt(_x23869,_x23870,kk_context()); /*bool*/
  if (_match_23609) {
    kk_function_drop(f0, _ctx);
    kk_integer_drop(high, _ctx);
    kk_integer_drop(low0, _ctx);
    return acc0;
  }
  kk_integer_t high0_210760;
  kk_integer_t _x23871 = kk_integer_dup(high); /*int*/
  high0_210760 = kk_integer_sub(_x23871,(kk_integer_from_small(1)),kk_context()); /*int*/
  kk_box_t x_21315;
  kk_function_t _x23872 = kk_function_dup(f0); /*(int) -> 6016 6015*/
  x_21315 = kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_context_t*), _x23872, (_x23872, high, _ctx)); /*6015*/
  if (kk_yielding(kk_context())) {
    kk_box_drop(x_21315, _ctx);
    kk_box_t _x23873 = kk_std_core_hnd_yield_extend(kk_std_core__new_lift21054_list_fun23874_1(acc0, f0, high0_210760, low0, _ctx), _ctx); /*3991*/
    return kk_std_core__list_unbox(_x23873, _ctx);
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
  kk_std_core_types__ctail _x23876;
  kk_box_t* field_21321 = (kk_box_t*)((&kk_std_core__as_Cons(_ctail_21125)->tail)); /*cfield<list<7320>>*/;
  if (kk_std_core_types__is_CTail(_acc)) {
    kk_box_t _box_x22129 = _acc._cons.CTail._field1;
    kk_box_t* last0 = _acc._cons.CTail._field2;
    kk_std_core__list head0 = kk_std_core__list_unbox(_box_x22129, NULL);
    kk_std_core__list_dup(head0);
    kk_std_core_types__ctail_drop(_acc, _ctx);
    kk_unit_t __ = kk_Unit;
    *(last0) = kk_std_core__list_box(_ctail_21125, _ctx);
    _x23876 = kk_std_core_types__new_CTail(kk_std_core__list_box(head0, _ctx), field_21321, _ctx); /*ctail<58>*/
    goto _match23877;
  }
  _x23876 = kk_std_core_types__new_CTail(kk_std_core__list_box(_ctail_21125, _ctx), field_21321, _ctx); /*ctail<58>*/
  _match23877: ;
  return kk_std_core__ctail_map_5(xx, f, _x23876, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_core__mlift21176_op_fun23879__t {
  struct kk_function_s _base;
  kk_function_t _accm;
  kk_box_t _ctail_21128;
};
static kk_std_core__list kk_std_core__mlift21176_op_fun23879(kk_function_t _fself, kk_std_core__list _ctail_21127, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_mlift21176_op_fun23879(kk_function_t _accm, kk_box_t _ctail_21128, kk_context_t* _ctx) {
  struct kk_std_core__mlift21176_op_fun23879__t* _self = kk_function_alloc_as(struct kk_std_core__mlift21176_op_fun23879__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__mlift21176_op_fun23879, kk_context());
  _self->_accm = _accm;
  _self->_ctail_21128 = _ctail_21128;
  return &_self->_base;
}

static kk_std_core__list kk_std_core__mlift21176_op_fun23879(kk_function_t _fself, kk_std_core__list _ctail_21127, kk_context_t* _ctx) {
  struct kk_std_core__mlift21176_op_fun23879__t* _self = kk_function_as(struct kk_std_core__mlift21176_op_fun23879__t*, _fself);
  kk_function_t _accm = _self->_accm; /* (list<7320>) -> list<7320> */
  kk_box_t _ctail_21128 = _self->_ctail_21128; /* 7320 */
  kk_drop_match(_self, {kk_function_dup(_accm);kk_box_dup(_ctail_21128);}, {}, _ctx)
  kk_std_core__list _x23880 = kk_std_core__new_Cons(kk_reuse_null, _ctail_21128, _ctail_21127, _ctx); /*list<61>*/
  return kk_function_call(kk_std_core__list, (kk_function_t, kk_std_core__list, kk_context_t*), _accm, (_accm, _x23880, _ctx));
}

kk_std_core__list kk_std_core__mlift21176_op(kk_function_t _accm, kk_function_t f0, kk_std_core__list xx0, kk_box_t _ctail_21128, kk_context_t* _ctx) { /* forall<a,b,e> ((list<b>) -> list<b>, f : (a) -> e b, xx : list<a>, b) -> e list<b> */ 
  return kk_std_core__ctailm_map_5(xx0, f0, kk_std_core__new_mlift21176_op_fun23879(_accm, _ctail_21128, _ctx), _ctx);
}
 
// Apply a function `f`  to each element of the input list in sequence.


// lift anonymous function
struct kk_std_core__ctail_map_fun23884__t_5 {
  struct kk_function_s _base;
  kk_function_t f1;
  kk_std_core__list xx1;
  kk_std_core_types__ctail _acc0;
};
static kk_box_t kk_std_core__ctail_map_fun23884_5(kk_function_t _fself, kk_box_t _b_22143, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_ctail_map_fun23884_5(kk_function_t f1, kk_std_core__list xx1, kk_std_core_types__ctail _acc0, kk_context_t* _ctx) {
  struct kk_std_core__ctail_map_fun23884__t_5* _self = kk_function_alloc_as(struct kk_std_core__ctail_map_fun23884__t_5, 5, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__ctail_map_fun23884_5, kk_context());
  _self->f1 = f1;
  _self->xx1 = xx1;
  _self->_acc0 = _acc0;
  return &_self->_base;
}

static kk_box_t kk_std_core__ctail_map_fun23884_5(kk_function_t _fself, kk_box_t _b_22143, kk_context_t* _ctx) {
  struct kk_std_core__ctail_map_fun23884__t_5* _self = kk_function_as(struct kk_std_core__ctail_map_fun23884__t_5*, _fself);
  kk_function_t f1 = _self->f1; /* (7319) -> 7321 7320 */
  kk_std_core__list xx1 = _self->xx1; /* list<7319> */
  kk_std_core_types__ctail _acc0 = _self->_acc0; /* ctail<list<7320>> */
  kk_drop_match(_self, {kk_function_dup(f1);kk_std_core__list_dup(xx1);kk_std_core_types__ctail_dup(_acc0);}, {}, _ctx)
  kk_std_core__list _x23885 = kk_std_core__mlift21175_op(_acc0, f1, xx1, _b_22143, _ctx); /*list<7320>*/
  return kk_std_core__list_box(_x23885, _ctx);
}

kk_std_core__list kk_std_core__ctail_map_5(kk_std_core__list xs, kk_function_t f1, kk_std_core_types__ctail _acc0, kk_context_t* _ctx) { /* forall<a,b,e> (xs : list<a>, f : (a) -> e b, ctail<list<b>>) -> e list<b> */ 
  kk__tailcall: ;
  if (kk_std_core__is_Cons(xs)) {
    struct kk_std_core_Cons* _con23881 = kk_std_core__as_Cons(xs);
    kk_box_t x = _con23881->head;
    kk_std_core__list xx1 = _con23881->tail;
    kk_reuse_t _ru_23338 = kk_reuse_null; /*reuse*/;
    if (kk_std_core__list_is_unique(xs)) {
      _ru_23338 = (kk_std_core__list_reuse(xs));
    }
    else {
      kk_box_dup(x);
      kk_std_core__list_dup(xx1);
      kk_std_core__list_decref(xs, _ctx);
      _ru_23338 = kk_reuse_null;
    }
    kk_box_t x0_21322;
    kk_function_t _x23882 = kk_function_dup(f1); /*(7319) -> 7321 7320*/
    x0_21322 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x23882, (_x23882, x, _ctx)); /*7320*/
    if (kk_yielding(kk_context())) {
      kk_reuse_drop(_ru_23338, _ctx);
      kk_box_drop(x0_21322, _ctx);
      kk_box_t _x23883 = kk_std_core_hnd_yield_extend(kk_std_core__new_ctail_map_fun23884_5(f1, xx1, _acc0, _ctx), _ctx); /*3991*/
      return kk_std_core__list_unbox(_x23883, _ctx);
    }
    kk_std_core__list _ctail_211240 = kk_std_core__list_hole(); /*list<7320>*/;
    kk_std_core__list _ctail_211250 = kk_std_core__new_Cons(_ru_23338, x0_21322, _ctail_211240, _ctx); /*list<7320>*/;
    { // tailcall
      kk_std_core_types__ctail _x23886;
      kk_box_t* field_21328 = (kk_box_t*)((&kk_std_core__as_Cons(_ctail_211250)->tail)); /*cfield<list<7320>>*/;
      if (kk_std_core_types__is_CTail(_acc0)) {
        kk_box_t _box_x22150 = _acc0._cons.CTail._field1;
        kk_box_t* last2 = _acc0._cons.CTail._field2;
        kk_std_core__list head1 = kk_std_core__list_unbox(_box_x22150, NULL);
        kk_std_core__list_dup(head1);
        kk_std_core_types__ctail_drop(_acc0, _ctx);
        kk_unit_t __0 = kk_Unit;
        *(last2) = kk_std_core__list_box(_ctail_211250, _ctx);
        _x23886 = kk_std_core_types__new_CTail(kk_std_core__list_box(head1, _ctx), field_21328, _ctx); /*ctail<58>*/
        goto _match23887;
      }
      _x23886 = kk_std_core_types__new_CTail(kk_std_core__list_box(_ctail_211250, _ctx), field_21328, _ctx); /*ctail<58>*/
      _match23887: ;
      xs = xx1;
      _acc0 = _x23886;
      goto kk__tailcall;
    }
  }
  kk_function_drop(f1, _ctx);
  if (kk_std_core_types__is_CTail(_acc0)) {
    kk_box_t _box_x22159 = _acc0._cons.CTail._field1;
    kk_box_t* last00 = _acc0._cons.CTail._field2;
    kk_std_core__list head00 = kk_std_core__list_unbox(_box_x22159, NULL);
    kk_std_core__list_dup(head00);
    kk_std_core_types__ctail_drop(_acc0, _ctx);
    kk_unit_t __00 = kk_Unit;
    *(last00) = kk_std_core__list_box(kk_std_core__new_Nil(_ctx), _ctx);
    return head00;
  }
  return kk_std_core__new_Nil(_ctx);
}
 
// Apply a function `f`  to each element of the input list in sequence.


// lift anonymous function
struct kk_std_core__ctailm_map_fun23893__t_5 {
  struct kk_function_s _base;
  kk_function_t _accm0;
  kk_function_t f2;
  kk_std_core__list xx2;
};
static kk_box_t kk_std_core__ctailm_map_fun23893_5(kk_function_t _fself, kk_box_t _b_22171, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_ctailm_map_fun23893_5(kk_function_t _accm0, kk_function_t f2, kk_std_core__list xx2, kk_context_t* _ctx) {
  struct kk_std_core__ctailm_map_fun23893__t_5* _self = kk_function_alloc_as(struct kk_std_core__ctailm_map_fun23893__t_5, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__ctailm_map_fun23893_5, kk_context());
  _self->_accm0 = _accm0;
  _self->f2 = f2;
  _self->xx2 = xx2;
  return &_self->_base;
}

static kk_box_t kk_std_core__ctailm_map_fun23893_5(kk_function_t _fself, kk_box_t _b_22171, kk_context_t* _ctx) {
  struct kk_std_core__ctailm_map_fun23893__t_5* _self = kk_function_as(struct kk_std_core__ctailm_map_fun23893__t_5*, _fself);
  kk_function_t _accm0 = _self->_accm0; /* (list<7320>) -> list<7320> */
  kk_function_t f2 = _self->f2; /* (7319) -> 7321 7320 */
  kk_std_core__list xx2 = _self->xx2; /* list<7319> */
  kk_drop_match(_self, {kk_function_dup(_accm0);kk_function_dup(f2);kk_std_core__list_dup(xx2);}, {}, _ctx)
  kk_std_core__list _x23894 = kk_std_core__mlift21176_op(_accm0, f2, xx2, _b_22171, _ctx); /*list<7320>*/
  return kk_std_core__list_box(_x23894, _ctx);
}


// lift anonymous function
struct kk_std_core__ctailm_map_fun23896__t_5 {
  struct kk_function_s _base;
  kk_function_t _accm0;
  kk_box_t x0_21331;
};
static kk_std_core__list kk_std_core__ctailm_map_fun23896_5(kk_function_t _fself, kk_std_core__list _ctail_211270, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_ctailm_map_fun23896_5(kk_function_t _accm0, kk_box_t x0_21331, kk_context_t* _ctx) {
  struct kk_std_core__ctailm_map_fun23896__t_5* _self = kk_function_alloc_as(struct kk_std_core__ctailm_map_fun23896__t_5, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__ctailm_map_fun23896_5, kk_context());
  _self->_accm0 = _accm0;
  _self->x0_21331 = x0_21331;
  return &_self->_base;
}

static kk_std_core__list kk_std_core__ctailm_map_fun23896_5(kk_function_t _fself, kk_std_core__list _ctail_211270, kk_context_t* _ctx) {
  struct kk_std_core__ctailm_map_fun23896__t_5* _self = kk_function_as(struct kk_std_core__ctailm_map_fun23896__t_5*, _fself);
  kk_function_t _accm0 = _self->_accm0; /* (list<7320>) -> list<7320> */
  kk_box_t x0_21331 = _self->x0_21331; /* 7320 */
  kk_drop_match(_self, {kk_function_dup(_accm0);kk_box_dup(x0_21331);}, {}, _ctx)
  kk_std_core__list _x23897 = kk_std_core__new_Cons(kk_reuse_null, x0_21331, _ctail_211270, _ctx); /*list<61>*/
  return kk_function_call(kk_std_core__list, (kk_function_t, kk_std_core__list, kk_context_t*), _accm0, (_accm0, _x23897, _ctx));
}

kk_std_core__list kk_std_core__ctailm_map_5(kk_std_core__list xs0, kk_function_t f2, kk_function_t _accm0, kk_context_t* _ctx) { /* forall<a,b,e> (xs : list<a>, f : (a) -> e b, (list<b>) -> list<b>) -> e list<b> */ 
  kk__tailcall: ;
  if (kk_std_core__is_Cons(xs0)) {
    struct kk_std_core_Cons* _con23890 = kk_std_core__as_Cons(xs0);
    kk_box_t x0 = _con23890->head;
    kk_std_core__list xx2 = _con23890->tail;
    if (kk_std_core__list_is_unique(xs0)) {
      kk_std_core__list_free(xs0);
    }
    else {
      kk_box_dup(x0);
      kk_std_core__list_dup(xx2);
      kk_std_core__list_decref(xs0, _ctx);
    }
    kk_box_t x0_21331;
    kk_function_t _x23891 = kk_function_dup(f2); /*(7319) -> 7321 7320*/
    x0_21331 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x23891, (_x23891, x0, _ctx)); /*7320*/
    if (kk_yielding(kk_context())) {
      kk_box_drop(x0_21331, _ctx);
      kk_box_t _x23892 = kk_std_core_hnd_yield_extend(kk_std_core__new_ctailm_map_fun23893_5(_accm0, f2, xx2, _ctx), _ctx); /*3991*/
      return kk_std_core__list_unbox(_x23892, _ctx);
    }
    { // tailcall
      kk_function_t _x23895 = kk_std_core__new_ctailm_map_fun23896_5(_accm0, x0_21331, _ctx); /*(list<7320>) -> list<7320>*/
      xs0 = xx2;
      _accm0 = _x23895;
      goto kk__tailcall;
    }
  }
  kk_function_drop(f2, _ctx);
  return kk_function_call(kk_std_core__list, (kk_function_t, kk_std_core__list, kk_context_t*), _accm0, (_accm0, kk_std_core__new_Nil(_ctx), _ctx));
}
 
// Apply a function `f`  to each element of the input list in sequence.


// lift anonymous function
struct kk_std_core_map_fun23898__t_5 {
  struct kk_function_s _base;
};
static kk_std_core__list kk_std_core_map_fun23898_5(kk_function_t _fself, kk_std_core__list _ctail_21126, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_map_fun23898_5(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_map_fun23898_5, _ctx)
  return kk_function_dup(_fself);
}

static kk_std_core__list kk_std_core_map_fun23898_5(kk_function_t _fself, kk_std_core__list _ctail_21126, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return _ctail_21126;
}

kk_std_core__list kk_std_core_map_5(kk_std_core__list xs1, kk_function_t f3, kk_context_t* _ctx) { /* forall<a,b,e> (xs : list<a>, f : (a) -> e b) -> e list<b> */ 
  bool _match_23606 = kk_std_core_hnd__evv_is_affine(_ctx); /*bool*/;
  if (_match_23606) {
    return kk_std_core__ctail_map_5(xs1, f3, kk_std_core_types__new_CTailNil(_ctx), _ctx);
  }
  return kk_std_core__ctailm_map_5(xs1, f3, kk_std_core_new_map_fun23898_5(_ctx), _ctx);
}
 
// Create a list of characters from `lo`  to `hi`  (inclusive).


// lift anonymous function
struct kk_std_core_list_fun23899__t_2 {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_list_fun23899_2(kk_function_t _fself, kk_box_t _b_22176, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_list_fun23899_2(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_list_fun23899_2, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_core_list_fun23899_2(kk_function_t _fself, kk_box_t _b_22176, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_char_t _x23900;
  kk_integer_t _x23901 = kk_integer_unbox(_b_22176); /*int*/
  _x23900 = kk_integer_clamp32(_x23901,kk_context()); /*char*/
  return kk_char_box(_x23900, _ctx);
}

kk_std_core__list kk_std_core_list_2(kk_char_t lo, kk_char_t hi, kk_context_t* _ctx) { /* (lo : char, hi : char) -> total list<char> */ 
  kk_std_core__list _b_22177_22174;
  kk_integer_t lo0_21335 = kk_integer_from_int(lo,kk_context()); /*int*/;
  kk_integer_t hi0_21336 = kk_integer_from_int(hi,kk_context()); /*int*/;
  _b_22177_22174 = kk_std_core__lift21053_list(lo0_21335, hi0_21336, kk_std_core__new_Nil(_ctx), _ctx); /*list<int>*/
  return kk_std_core_map_5(_b_22177_22174, kk_std_core_new_list_fun23899_2(_ctx), _ctx);
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
struct kk_std_core_map_fun23903__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_map_fun23903(kk_function_t _fself, kk_box_t _b_22180, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_map_fun23903(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_map_fun23903, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_core_map_fun23903(kk_function_t _fself, kk_box_t _b_22180, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core_types__maybe _x23904 = kk_std_core__mlift21177_map(_b_22180, _ctx); /*maybe<6436>*/
  return kk_std_core_types__maybe_box(_x23904, _ctx);
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
    kk_box_t _x23902 = kk_std_core_hnd_yield_extend(kk_std_core_new_map_fun23903(_ctx), _ctx); /*3991*/
    return kk_std_core_types__maybe_unbox(_x23902, _ctx);
  }
  return kk_std_core_types__new_Just(x0_21337, _ctx);
}
 
// monadic lift

kk_std_core_types__either kk_std_core__mlift21178_map_1(kk_box_t _y_61, kk_context_t* _ctx) { /* forall<a,b,e> (b) -> e either<a,b> */ 
  return kk_std_core_types__new_Right(_y_61, _ctx);
}
 
// Map over the `Right` component of an `:either` type.


// lift anonymous function
struct kk_std_core_map_fun23906__t_1 {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_map_fun23906_1(kk_function_t _fself, kk_box_t _b_22184, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_map_fun23906_1(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_map_fun23906_1, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_core_map_fun23906_1(kk_function_t _fself, kk_box_t _b_22184, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core_types__either _x23907 = kk_std_core__mlift21178_map_1(_b_22184, _ctx); /*either<6472,6474>*/
  return kk_std_core_types__either_box(_x23907, _ctx);
}

kk_std_core_types__either kk_std_core_map_1(kk_std_core_types__either e, kk_function_t f, kk_context_t* _ctx) { /* forall<a,b,c,e> (e : either<a,b>, f : (b) -> e c) -> e either<a,c> */ 
  if (kk_std_core_types__is_Right(e)) {
    kk_box_t x = e._cons.Right.right;
    kk_box_t x0_21341 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), f, (f, x, _ctx)); /*6474*/;
    if (kk_yielding(kk_context())) {
      kk_box_drop(x0_21341, _ctx);
      kk_box_t _x23905 = kk_std_core_hnd_yield_extend(kk_std_core_new_map_fun23906_1(_ctx), _ctx); /*3991*/
      return kk_std_core_types__either_unbox(_x23905, _ctx);
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
struct kk_std_core__mlift21180_map_fun23910__t_2 {
  struct kk_function_s _base;
  kk_box_t _y_63;
};
static kk_box_t kk_std_core__mlift21180_map_fun23910_2(kk_function_t _fself, kk_box_t _b_22188, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_mlift21180_map_fun23910_2(kk_box_t _y_63, kk_context_t* _ctx) {
  struct kk_std_core__mlift21180_map_fun23910__t_2* _self = kk_function_alloc_as(struct kk_std_core__mlift21180_map_fun23910__t_2, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__mlift21180_map_fun23910_2, kk_context());
  _self->_y_63 = _y_63;
  return &_self->_base;
}

static kk_box_t kk_std_core__mlift21180_map_fun23910_2(kk_function_t _fself, kk_box_t _b_22188, kk_context_t* _ctx) {
  struct kk_std_core__mlift21180_map_fun23910__t_2* _self = kk_function_as(struct kk_std_core__mlift21180_map_fun23910__t_2*, _fself);
  kk_box_t _y_63 = _self->_y_63; /* 6635 */
  kk_drop_match(_self, {kk_box_dup(_y_63);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x23911 = kk_std_core__mlift21179_map_2(_y_63, _b_22188, _ctx); /*(6635, 6635)*/
  return kk_std_core_types__tuple2__box(_x23911, _ctx);
}

kk_std_core_types__tuple2_ kk_std_core__mlift21180_map_2(kk_function_t f, kk_std_core_types__tuple2_ t, kk_box_t _y_63, kk_context_t* _ctx) { /* forall<a,b,e> (f : (a) -> e b, t : (a, a), b) -> e (b, b) */ 
  kk_box_t x_21345;
  kk_box_t _x23908;
  kk_box_t _x = t.snd;
  kk_box_dup(_x);
  kk_std_core_types__tuple2__drop(t, _ctx);
  _x23908 = _x; /*6634*/
  x_21345 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), f, (f, _x23908, _ctx)); /*6635*/
  if (kk_yielding(kk_context())) {
    kk_box_drop(x_21345, _ctx);
    kk_box_t _x23909 = kk_std_core_hnd_yield_extend(kk_std_core__new_mlift21180_map_fun23910_2(_y_63, _ctx), _ctx); /*3991*/
    return kk_std_core_types__tuple2__unbox(_x23909, _ctx);
  }
  return kk_std_core__mlift21179_map_2(_y_63, x_21345, _ctx);
}


// lift anonymous function
struct kk_std_core_map_fun23915__t_2 {
  struct kk_function_s _base;
  kk_function_t f;
  kk_std_core_types__tuple2_ t;
};
static kk_box_t kk_std_core_map_fun23915_2(kk_function_t _fself, kk_box_t _b_22192, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_map_fun23915_2(kk_function_t f, kk_std_core_types__tuple2_ t, kk_context_t* _ctx) {
  struct kk_std_core_map_fun23915__t_2* _self = kk_function_alloc_as(struct kk_std_core_map_fun23915__t_2, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_map_fun23915_2, kk_context());
  _self->f = f;
  _self->t = t;
  return &_self->_base;
}

static kk_box_t kk_std_core_map_fun23915_2(kk_function_t _fself, kk_box_t _b_22192, kk_context_t* _ctx) {
  struct kk_std_core_map_fun23915__t_2* _self = kk_function_as(struct kk_std_core_map_fun23915__t_2*, _fself);
  kk_function_t f = _self->f; /* (6634) -> 6636 6635 */
  kk_std_core_types__tuple2_ t = _self->t; /* (6634, 6634) */
  kk_drop_match(_self, {kk_function_dup(f);kk_std_core_types__tuple2__dup(t);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x23916 = kk_std_core__mlift21180_map_2(f, t, _b_22192, _ctx); /*(6635, 6635)*/
  return kk_std_core_types__tuple2__box(_x23916, _ctx);
}


// lift anonymous function
struct kk_std_core_map_fun23919__t_2 {
  struct kk_function_s _base;
  kk_box_t x_21348;
};
static kk_box_t kk_std_core_map_fun23919_2(kk_function_t _fself, kk_box_t _b_22194, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_map_fun23919_2(kk_box_t x_21348, kk_context_t* _ctx) {
  struct kk_std_core_map_fun23919__t_2* _self = kk_function_alloc_as(struct kk_std_core_map_fun23919__t_2, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_map_fun23919_2, kk_context());
  _self->x_21348 = x_21348;
  return &_self->_base;
}

static kk_box_t kk_std_core_map_fun23919_2(kk_function_t _fself, kk_box_t _b_22194, kk_context_t* _ctx) {
  struct kk_std_core_map_fun23919__t_2* _self = kk_function_as(struct kk_std_core_map_fun23919__t_2*, _fself);
  kk_box_t x_21348 = _self->x_21348; /* 6635 */
  kk_drop_match(_self, {kk_box_dup(x_21348);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x23920 = kk_std_core__mlift21179_map_2(x_21348, _b_22194, _ctx); /*(6635, 6635)*/
  return kk_std_core_types__tuple2__box(_x23920, _ctx);
}

kk_std_core_types__tuple2_ kk_std_core_map_2(kk_std_core_types__tuple2_ t, kk_function_t f, kk_context_t* _ctx) { /* forall<a,b,e> (t : (a, a), f : (a) -> e b) -> e (b, b) */ 
  kk_box_t x_21348;
  kk_function_t _x23913 = kk_function_dup(f); /*(6634) -> 6636 6635*/
  kk_box_t _x23912;
  kk_box_t _x = t.fst;
  kk_box_dup(_x);
  _x23912 = _x; /*6634*/
  x_21348 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x23913, (_x23913, _x23912, _ctx)); /*6635*/
  if (kk_yielding(kk_context())) {
    kk_box_drop(x_21348, _ctx);
    kk_box_t _x23914 = kk_std_core_hnd_yield_extend(kk_std_core_new_map_fun23915_2(f, t, _ctx), _ctx); /*3991*/
    return kk_std_core_types__tuple2__unbox(_x23914, _ctx);
  }
  kk_box_t x0_21353;
  kk_box_t _x23917;
  kk_box_t _x0 = t.snd;
  kk_box_dup(_x0);
  kk_std_core_types__tuple2__drop(t, _ctx);
  _x23917 = _x0; /*6634*/
  x0_21353 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), f, (f, _x23917, _ctx)); /*6635*/
  if (kk_yielding(kk_context())) {
    kk_box_drop(x0_21353, _ctx);
    kk_box_t _x23918 = kk_std_core_hnd_yield_extend(kk_std_core_new_map_fun23919_2(x_21348, _ctx), _ctx); /*3991*/
    return kk_std_core_types__tuple2__unbox(_x23918, _ctx);
  }
  return kk_std_core_types__new_dash__lp__comma__rp_(x_21348, x0_21353, _ctx);
}
 
// monadic lift

kk_std_core_types__tuple3_ kk_std_core__mlift21181_map_3(kk_box_t _y_65, kk_box_t _y_66, kk_box_t _y_67, kk_context_t* _ctx) { /* forall<a,e> (a, a, a) -> e (a, a, a) */ 
  return kk_std_core_types__new_dash__lp__comma__comma__rp_(_y_65, _y_66, _y_67, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_core__mlift21182_map_fun23923__t_3 {
  struct kk_function_s _base;
  kk_box_t _y_65;
  kk_box_t _y_66;
};
static kk_box_t kk_std_core__mlift21182_map_fun23923_3(kk_function_t _fself, kk_box_t _b_22200, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_mlift21182_map_fun23923_3(kk_box_t _y_65, kk_box_t _y_66, kk_context_t* _ctx) {
  struct kk_std_core__mlift21182_map_fun23923__t_3* _self = kk_function_alloc_as(struct kk_std_core__mlift21182_map_fun23923__t_3, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__mlift21182_map_fun23923_3, kk_context());
  _self->_y_65 = _y_65;
  _self->_y_66 = _y_66;
  return &_self->_base;
}

static kk_box_t kk_std_core__mlift21182_map_fun23923_3(kk_function_t _fself, kk_box_t _b_22200, kk_context_t* _ctx) {
  struct kk_std_core__mlift21182_map_fun23923__t_3* _self = kk_function_as(struct kk_std_core__mlift21182_map_fun23923__t_3*, _fself);
  kk_box_t _y_65 = _self->_y_65; /* 6875 */
  kk_box_t _y_66 = _self->_y_66; /* 6875 */
  kk_drop_match(_self, {kk_box_dup(_y_65);kk_box_dup(_y_66);}, {}, _ctx)
  kk_std_core_types__tuple3_ _x23924 = kk_std_core__mlift21181_map_3(_y_65, _y_66, _b_22200, _ctx); /*(6875, 6875, 6875)*/
  return kk_std_core_types__tuple3__box(_x23924, _ctx);
}

kk_std_core_types__tuple3_ kk_std_core__mlift21182_map_3(kk_box_t _y_65, kk_function_t f, kk_std_core_types__tuple3_ t, kk_box_t _y_66, kk_context_t* _ctx) { /* forall<a,b,e> (b, f : (a) -> e b, t : (a, a, a), b) -> e (b, b, b) */ 
  kk_box_t x_21358;
  kk_box_t _x23921;
  kk_box_t _x = t.thd;
  kk_box_dup(_x);
  kk_std_core_types__tuple3__drop(t, _ctx);
  _x23921 = _x; /*6874*/
  x_21358 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), f, (f, _x23921, _ctx)); /*6875*/
  if (kk_yielding(kk_context())) {
    kk_box_drop(x_21358, _ctx);
    kk_box_t _x23922 = kk_std_core_hnd_yield_extend(kk_std_core__new_mlift21182_map_fun23923_3(_y_65, _y_66, _ctx), _ctx); /*3991*/
    return kk_std_core_types__tuple3__unbox(_x23922, _ctx);
  }
  return kk_std_core__mlift21181_map_3(_y_65, _y_66, x_21358, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_core__mlift21183_map_fun23928__t_3 {
  struct kk_function_s _base;
  kk_box_t _y_65;
  kk_function_t f;
  kk_std_core_types__tuple3_ t;
};
static kk_box_t kk_std_core__mlift21183_map_fun23928_3(kk_function_t _fself, kk_box_t _b_22204, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_mlift21183_map_fun23928_3(kk_box_t _y_65, kk_function_t f, kk_std_core_types__tuple3_ t, kk_context_t* _ctx) {
  struct kk_std_core__mlift21183_map_fun23928__t_3* _self = kk_function_alloc_as(struct kk_std_core__mlift21183_map_fun23928__t_3, 6, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__mlift21183_map_fun23928_3, kk_context());
  _self->_y_65 = _y_65;
  _self->f = f;
  _self->t = t;
  return &_self->_base;
}

static kk_box_t kk_std_core__mlift21183_map_fun23928_3(kk_function_t _fself, kk_box_t _b_22204, kk_context_t* _ctx) {
  struct kk_std_core__mlift21183_map_fun23928__t_3* _self = kk_function_as(struct kk_std_core__mlift21183_map_fun23928__t_3*, _fself);
  kk_box_t _y_65 = _self->_y_65; /* 6875 */
  kk_function_t f = _self->f; /* (6874) -> 6876 6875 */
  kk_std_core_types__tuple3_ t = _self->t; /* (6874, 6874, 6874) */
  kk_drop_match(_self, {kk_box_dup(_y_65);kk_function_dup(f);kk_std_core_types__tuple3__dup(t);}, {}, _ctx)
  kk_std_core_types__tuple3_ _x23929 = kk_std_core__mlift21182_map_3(_y_65, f, t, _b_22204, _ctx); /*(6875, 6875, 6875)*/
  return kk_std_core_types__tuple3__box(_x23929, _ctx);
}

kk_std_core_types__tuple3_ kk_std_core__mlift21183_map_3(kk_function_t f, kk_std_core_types__tuple3_ t, kk_box_t _y_65, kk_context_t* _ctx) { /* forall<a,b,e> (f : (a) -> e b, t : (a, a, a), b) -> e (b, b, b) */ 
  kk_box_t x_21361;
  kk_function_t _x23926 = kk_function_dup(f); /*(6874) -> 6876 6875*/
  kk_box_t _x23925;
  kk_box_t _x = t.snd;
  kk_box_dup(_x);
  _x23925 = _x; /*6874*/
  x_21361 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x23926, (_x23926, _x23925, _ctx)); /*6875*/
  if (kk_yielding(kk_context())) {
    kk_box_drop(x_21361, _ctx);
    kk_box_t _x23927 = kk_std_core_hnd_yield_extend(kk_std_core__new_mlift21183_map_fun23928_3(_y_65, f, t, _ctx), _ctx); /*3991*/
    return kk_std_core_types__tuple3__unbox(_x23927, _ctx);
  }
  return kk_std_core__mlift21182_map_3(_y_65, f, t, x_21361, _ctx);
}


// lift anonymous function
struct kk_std_core_map_fun23933__t_3 {
  struct kk_function_s _base;
  kk_function_t f;
  kk_std_core_types__tuple3_ t;
};
static kk_box_t kk_std_core_map_fun23933_3(kk_function_t _fself, kk_box_t _b_22208, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_map_fun23933_3(kk_function_t f, kk_std_core_types__tuple3_ t, kk_context_t* _ctx) {
  struct kk_std_core_map_fun23933__t_3* _self = kk_function_alloc_as(struct kk_std_core_map_fun23933__t_3, 5, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_map_fun23933_3, kk_context());
  _self->f = f;
  _self->t = t;
  return &_self->_base;
}

static kk_box_t kk_std_core_map_fun23933_3(kk_function_t _fself, kk_box_t _b_22208, kk_context_t* _ctx) {
  struct kk_std_core_map_fun23933__t_3* _self = kk_function_as(struct kk_std_core_map_fun23933__t_3*, _fself);
  kk_function_t f = _self->f; /* (6874) -> 6876 6875 */
  kk_std_core_types__tuple3_ t = _self->t; /* (6874, 6874, 6874) */
  kk_drop_match(_self, {kk_function_dup(f);kk_std_core_types__tuple3__dup(t);}, {}, _ctx)
  kk_std_core_types__tuple3_ _x23934 = kk_std_core__mlift21183_map_3(f, t, _b_22208, _ctx); /*(6875, 6875, 6875)*/
  return kk_std_core_types__tuple3__box(_x23934, _ctx);
}


// lift anonymous function
struct kk_std_core_map_fun23938__t_3 {
  struct kk_function_s _base;
  kk_function_t f;
  kk_std_core_types__tuple3_ t;
  kk_box_t x_21364;
};
static kk_box_t kk_std_core_map_fun23938_3(kk_function_t _fself, kk_box_t _b_22210, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_map_fun23938_3(kk_function_t f, kk_std_core_types__tuple3_ t, kk_box_t x_21364, kk_context_t* _ctx) {
  struct kk_std_core_map_fun23938__t_3* _self = kk_function_alloc_as(struct kk_std_core_map_fun23938__t_3, 6, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_map_fun23938_3, kk_context());
  _self->f = f;
  _self->t = t;
  _self->x_21364 = x_21364;
  return &_self->_base;
}

static kk_box_t kk_std_core_map_fun23938_3(kk_function_t _fself, kk_box_t _b_22210, kk_context_t* _ctx) {
  struct kk_std_core_map_fun23938__t_3* _self = kk_function_as(struct kk_std_core_map_fun23938__t_3*, _fself);
  kk_function_t f = _self->f; /* (6874) -> 6876 6875 */
  kk_std_core_types__tuple3_ t = _self->t; /* (6874, 6874, 6874) */
  kk_box_t x_21364 = _self->x_21364; /* 6875 */
  kk_drop_match(_self, {kk_function_dup(f);kk_std_core_types__tuple3__dup(t);kk_box_dup(x_21364);}, {}, _ctx)
  kk_std_core_types__tuple3_ _x23939 = kk_std_core__mlift21182_map_3(x_21364, f, t, _b_22210, _ctx); /*(6875, 6875, 6875)*/
  return kk_std_core_types__tuple3__box(_x23939, _ctx);
}


// lift anonymous function
struct kk_std_core_map_fun23942__t_3 {
  struct kk_function_s _base;
  kk_box_t x_21364;
  kk_box_t x0_21369;
};
static kk_box_t kk_std_core_map_fun23942_3(kk_function_t _fself, kk_box_t _b_22212, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_map_fun23942_3(kk_box_t x_21364, kk_box_t x0_21369, kk_context_t* _ctx) {
  struct kk_std_core_map_fun23942__t_3* _self = kk_function_alloc_as(struct kk_std_core_map_fun23942__t_3, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_map_fun23942_3, kk_context());
  _self->x_21364 = x_21364;
  _self->x0_21369 = x0_21369;
  return &_self->_base;
}

static kk_box_t kk_std_core_map_fun23942_3(kk_function_t _fself, kk_box_t _b_22212, kk_context_t* _ctx) {
  struct kk_std_core_map_fun23942__t_3* _self = kk_function_as(struct kk_std_core_map_fun23942__t_3*, _fself);
  kk_box_t x_21364 = _self->x_21364; /* 6875 */
  kk_box_t x0_21369 = _self->x0_21369; /* 6875 */
  kk_drop_match(_self, {kk_box_dup(x_21364);kk_box_dup(x0_21369);}, {}, _ctx)
  kk_std_core_types__tuple3_ _x23943 = kk_std_core__mlift21181_map_3(x_21364, x0_21369, _b_22212, _ctx); /*(6875, 6875, 6875)*/
  return kk_std_core_types__tuple3__box(_x23943, _ctx);
}

kk_std_core_types__tuple3_ kk_std_core_map_3(kk_std_core_types__tuple3_ t, kk_function_t f, kk_context_t* _ctx) { /* forall<a,b,e> (t : (a, a, a), f : (a) -> e b) -> e (b, b, b) */ 
  kk_box_t x_21364;
  kk_function_t _x23931 = kk_function_dup(f); /*(6874) -> 6876 6875*/
  kk_box_t _x23930;
  kk_box_t _x = t.fst;
  kk_box_dup(_x);
  _x23930 = _x; /*6874*/
  x_21364 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x23931, (_x23931, _x23930, _ctx)); /*6875*/
  if (kk_yielding(kk_context())) {
    kk_box_drop(x_21364, _ctx);
    kk_box_t _x23932 = kk_std_core_hnd_yield_extend(kk_std_core_new_map_fun23933_3(f, t, _ctx), _ctx); /*3991*/
    return kk_std_core_types__tuple3__unbox(_x23932, _ctx);
  }
  kk_box_t x0_21369;
  kk_function_t _x23936 = kk_function_dup(f); /*(6874) -> 6876 6875*/
  kk_box_t _x23935;
  kk_box_t _x0 = t.snd;
  kk_box_dup(_x0);
  _x23935 = _x0; /*6874*/
  x0_21369 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x23936, (_x23936, _x23935, _ctx)); /*6875*/
  if (kk_yielding(kk_context())) {
    kk_box_drop(x0_21369, _ctx);
    kk_box_t _x23937 = kk_std_core_hnd_yield_extend(kk_std_core_new_map_fun23938_3(f, t, x_21364, _ctx), _ctx); /*3991*/
    return kk_std_core_types__tuple3__unbox(_x23937, _ctx);
  }
  kk_box_t x1_21374;
  kk_box_t _x23940;
  kk_box_t _x1 = t.thd;
  kk_box_dup(_x1);
  kk_std_core_types__tuple3__drop(t, _ctx);
  _x23940 = _x1; /*6874*/
  x1_21374 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), f, (f, _x23940, _ctx)); /*6875*/
  if (kk_yielding(kk_context())) {
    kk_box_drop(x1_21374, _ctx);
    kk_box_t _x23941 = kk_std_core_hnd_yield_extend(kk_std_core_new_map_fun23942_3(x_21364, x0_21369, _ctx), _ctx); /*3991*/
    return kk_std_core_types__tuple3__unbox(_x23941, _ctx);
  }
  return kk_std_core_types__new_dash__lp__comma__comma__rp_(x_21364, x0_21369, x1_21374, _ctx);
}
 
// monadic lift

kk_std_core_types__tuple4_ kk_std_core__mlift21184_map_4(kk_box_t _y_68, kk_box_t _y_69, kk_box_t _y_70, kk_box_t _y_71, kk_context_t* _ctx) { /* forall<a,e> (a, a, a, a) -> e (a, a, a, a) */ 
  return kk_std_core_types__new_dash__lp__comma__comma__comma__rp_(kk_reuse_null, _y_68, _y_69, _y_70, _y_71, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_core__mlift21185_map_fun23947__t_4 {
  struct kk_function_s _base;
  kk_box_t _y_68;
  kk_box_t _y_69;
  kk_box_t _y_70;
};
static kk_box_t kk_std_core__mlift21185_map_fun23947_4(kk_function_t _fself, kk_box_t _b_22220, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_mlift21185_map_fun23947_4(kk_box_t _y_68, kk_box_t _y_69, kk_box_t _y_70, kk_context_t* _ctx) {
  struct kk_std_core__mlift21185_map_fun23947__t_4* _self = kk_function_alloc_as(struct kk_std_core__mlift21185_map_fun23947__t_4, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__mlift21185_map_fun23947_4, kk_context());
  _self->_y_68 = _y_68;
  _self->_y_69 = _y_69;
  _self->_y_70 = _y_70;
  return &_self->_base;
}

static kk_box_t kk_std_core__mlift21185_map_fun23947_4(kk_function_t _fself, kk_box_t _b_22220, kk_context_t* _ctx) {
  struct kk_std_core__mlift21185_map_fun23947__t_4* _self = kk_function_as(struct kk_std_core__mlift21185_map_fun23947__t_4*, _fself);
  kk_box_t _y_68 = _self->_y_68; /* 7188 */
  kk_box_t _y_69 = _self->_y_69; /* 7188 */
  kk_box_t _y_70 = _self->_y_70; /* 7188 */
  kk_drop_match(_self, {kk_box_dup(_y_68);kk_box_dup(_y_69);kk_box_dup(_y_70);}, {}, _ctx)
  kk_std_core_types__tuple4_ _x23948 = kk_std_core__mlift21184_map_4(_y_68, _y_69, _y_70, _b_22220, _ctx); /*(7188, 7188, 7188, 7188)*/
  return kk_std_core_types__tuple4__box(_x23948, _ctx);
}

kk_std_core_types__tuple4_ kk_std_core__mlift21185_map_4(kk_box_t _y_68, kk_box_t _y_69, kk_function_t f, kk_std_core_types__tuple4_ t, kk_box_t _y_70, kk_context_t* _ctx) { /* forall<a,b,e> (b, b, f : (a) -> e b, t : (a, a, a, a), b) -> e (b, b, b, b) */ 
  kk_box_t x_21379;
  kk_box_t _x23944;
  struct kk_std_core_types__Tuple4_* _con23945 = kk_std_core_types__as_dash__lp__comma__comma__comma__rp_(t);
  kk_box_t _pat00 = _con23945->fst;
  kk_box_t _pat10 = _con23945->snd;
  kk_box_t _pat2 = _con23945->thd;
  kk_box_t _x = _con23945->field4;
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
  _x23944 = _x; /*7187*/
  x_21379 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), f, (f, _x23944, _ctx)); /*7188*/
  if (kk_yielding(kk_context())) {
    kk_box_drop(x_21379, _ctx);
    kk_box_t _x23946 = kk_std_core_hnd_yield_extend(kk_std_core__new_mlift21185_map_fun23947_4(_y_68, _y_69, _y_70, _ctx), _ctx); /*3991*/
    return kk_std_core_types__tuple4__unbox(_x23946, _ctx);
  }
  return kk_std_core__mlift21184_map_4(_y_68, _y_69, _y_70, x_21379, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_core__mlift21186_map_fun23953__t_4 {
  struct kk_function_s _base;
  kk_box_t _y_68;
  kk_box_t _y_69;
  kk_function_t f;
  kk_std_core_types__tuple4_ t;
};
static kk_box_t kk_std_core__mlift21186_map_fun23953_4(kk_function_t _fself, kk_box_t _b_22224, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_mlift21186_map_fun23953_4(kk_box_t _y_68, kk_box_t _y_69, kk_function_t f, kk_std_core_types__tuple4_ t, kk_context_t* _ctx) {
  struct kk_std_core__mlift21186_map_fun23953__t_4* _self = kk_function_alloc_as(struct kk_std_core__mlift21186_map_fun23953__t_4, 5, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__mlift21186_map_fun23953_4, kk_context());
  _self->_y_68 = _y_68;
  _self->_y_69 = _y_69;
  _self->f = f;
  _self->t = t;
  return &_self->_base;
}

static kk_box_t kk_std_core__mlift21186_map_fun23953_4(kk_function_t _fself, kk_box_t _b_22224, kk_context_t* _ctx) {
  struct kk_std_core__mlift21186_map_fun23953__t_4* _self = kk_function_as(struct kk_std_core__mlift21186_map_fun23953__t_4*, _fself);
  kk_box_t _y_68 = _self->_y_68; /* 7188 */
  kk_box_t _y_69 = _self->_y_69; /* 7188 */
  kk_function_t f = _self->f; /* (7187) -> 7189 7188 */
  kk_std_core_types__tuple4_ t = _self->t; /* (7187, 7187, 7187, 7187) */
  kk_drop_match(_self, {kk_box_dup(_y_68);kk_box_dup(_y_69);kk_function_dup(f);kk_std_core_types__tuple4__dup(t);}, {}, _ctx)
  kk_std_core_types__tuple4_ _x23954 = kk_std_core__mlift21185_map_4(_y_68, _y_69, f, t, _b_22224, _ctx); /*(7188, 7188, 7188, 7188)*/
  return kk_std_core_types__tuple4__box(_x23954, _ctx);
}

kk_std_core_types__tuple4_ kk_std_core__mlift21186_map_4(kk_box_t _y_68, kk_function_t f, kk_std_core_types__tuple4_ t, kk_box_t _y_69, kk_context_t* _ctx) { /* forall<a,b,e> (b, f : (a) -> e b, t : (a, a, a, a), b) -> e (b, b, b, b) */ 
  kk_box_t x_21382;
  kk_function_t _x23951 = kk_function_dup(f); /*(7187) -> 7189 7188*/
  kk_box_t _x23949;
  struct kk_std_core_types__Tuple4_* _con23950 = kk_std_core_types__as_dash__lp__comma__comma__comma__rp_(t);
  kk_box_t _x = _con23950->thd;
  kk_box_dup(_x);
  _x23949 = _x; /*7187*/
  x_21382 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x23951, (_x23951, _x23949, _ctx)); /*7188*/
  if (kk_yielding(kk_context())) {
    kk_box_drop(x_21382, _ctx);
    kk_box_t _x23952 = kk_std_core_hnd_yield_extend(kk_std_core__new_mlift21186_map_fun23953_4(_y_68, _y_69, f, t, _ctx), _ctx); /*3991*/
    return kk_std_core_types__tuple4__unbox(_x23952, _ctx);
  }
  return kk_std_core__mlift21185_map_4(_y_68, _y_69, f, t, x_21382, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_core__mlift21187_map_fun23959__t_4 {
  struct kk_function_s _base;
  kk_box_t _y_68;
  kk_function_t f;
  kk_std_core_types__tuple4_ t;
};
static kk_box_t kk_std_core__mlift21187_map_fun23959_4(kk_function_t _fself, kk_box_t _b_22228, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_mlift21187_map_fun23959_4(kk_box_t _y_68, kk_function_t f, kk_std_core_types__tuple4_ t, kk_context_t* _ctx) {
  struct kk_std_core__mlift21187_map_fun23959__t_4* _self = kk_function_alloc_as(struct kk_std_core__mlift21187_map_fun23959__t_4, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__mlift21187_map_fun23959_4, kk_context());
  _self->_y_68 = _y_68;
  _self->f = f;
  _self->t = t;
  return &_self->_base;
}

static kk_box_t kk_std_core__mlift21187_map_fun23959_4(kk_function_t _fself, kk_box_t _b_22228, kk_context_t* _ctx) {
  struct kk_std_core__mlift21187_map_fun23959__t_4* _self = kk_function_as(struct kk_std_core__mlift21187_map_fun23959__t_4*, _fself);
  kk_box_t _y_68 = _self->_y_68; /* 7188 */
  kk_function_t f = _self->f; /* (7187) -> 7189 7188 */
  kk_std_core_types__tuple4_ t = _self->t; /* (7187, 7187, 7187, 7187) */
  kk_drop_match(_self, {kk_box_dup(_y_68);kk_function_dup(f);kk_std_core_types__tuple4__dup(t);}, {}, _ctx)
  kk_std_core_types__tuple4_ _x23960 = kk_std_core__mlift21186_map_4(_y_68, f, t, _b_22228, _ctx); /*(7188, 7188, 7188, 7188)*/
  return kk_std_core_types__tuple4__box(_x23960, _ctx);
}

kk_std_core_types__tuple4_ kk_std_core__mlift21187_map_4(kk_function_t f, kk_std_core_types__tuple4_ t, kk_box_t _y_68, kk_context_t* _ctx) { /* forall<a,b,e> (f : (a) -> e b, t : (a, a, a, a), b) -> e (b, b, b, b) */ 
  kk_box_t x_21385;
  kk_function_t _x23957 = kk_function_dup(f); /*(7187) -> 7189 7188*/
  kk_box_t _x23955;
  struct kk_std_core_types__Tuple4_* _con23956 = kk_std_core_types__as_dash__lp__comma__comma__comma__rp_(t);
  kk_box_t _x = _con23956->snd;
  kk_box_dup(_x);
  _x23955 = _x; /*7187*/
  x_21385 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x23957, (_x23957, _x23955, _ctx)); /*7188*/
  if (kk_yielding(kk_context())) {
    kk_box_drop(x_21385, _ctx);
    kk_box_t _x23958 = kk_std_core_hnd_yield_extend(kk_std_core__new_mlift21187_map_fun23959_4(_y_68, f, t, _ctx), _ctx); /*3991*/
    return kk_std_core_types__tuple4__unbox(_x23958, _ctx);
  }
  return kk_std_core__mlift21186_map_4(_y_68, f, t, x_21385, _ctx);
}


// lift anonymous function
struct kk_std_core_map_fun23965__t_4 {
  struct kk_function_s _base;
  kk_function_t f;
  kk_std_core_types__tuple4_ t;
};
static kk_box_t kk_std_core_map_fun23965_4(kk_function_t _fself, kk_box_t _b_22232, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_map_fun23965_4(kk_function_t f, kk_std_core_types__tuple4_ t, kk_context_t* _ctx) {
  struct kk_std_core_map_fun23965__t_4* _self = kk_function_alloc_as(struct kk_std_core_map_fun23965__t_4, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_map_fun23965_4, kk_context());
  _self->f = f;
  _self->t = t;
  return &_self->_base;
}

static kk_box_t kk_std_core_map_fun23965_4(kk_function_t _fself, kk_box_t _b_22232, kk_context_t* _ctx) {
  struct kk_std_core_map_fun23965__t_4* _self = kk_function_as(struct kk_std_core_map_fun23965__t_4*, _fself);
  kk_function_t f = _self->f; /* (7187) -> 7189 7188 */
  kk_std_core_types__tuple4_ t = _self->t; /* (7187, 7187, 7187, 7187) */
  kk_drop_match(_self, {kk_function_dup(f);kk_std_core_types__tuple4__dup(t);}, {}, _ctx)
  kk_std_core_types__tuple4_ _x23966 = kk_std_core__mlift21187_map_4(f, t, _b_22232, _ctx); /*(7188, 7188, 7188, 7188)*/
  return kk_std_core_types__tuple4__box(_x23966, _ctx);
}


// lift anonymous function
struct kk_std_core_map_fun23971__t_4 {
  struct kk_function_s _base;
  kk_function_t f;
  kk_std_core_types__tuple4_ t;
  kk_box_t x_21388;
};
static kk_box_t kk_std_core_map_fun23971_4(kk_function_t _fself, kk_box_t _b_22234, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_map_fun23971_4(kk_function_t f, kk_std_core_types__tuple4_ t, kk_box_t x_21388, kk_context_t* _ctx) {
  struct kk_std_core_map_fun23971__t_4* _self = kk_function_alloc_as(struct kk_std_core_map_fun23971__t_4, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_map_fun23971_4, kk_context());
  _self->f = f;
  _self->t = t;
  _self->x_21388 = x_21388;
  return &_self->_base;
}

static kk_box_t kk_std_core_map_fun23971_4(kk_function_t _fself, kk_box_t _b_22234, kk_context_t* _ctx) {
  struct kk_std_core_map_fun23971__t_4* _self = kk_function_as(struct kk_std_core_map_fun23971__t_4*, _fself);
  kk_function_t f = _self->f; /* (7187) -> 7189 7188 */
  kk_std_core_types__tuple4_ t = _self->t; /* (7187, 7187, 7187, 7187) */
  kk_box_t x_21388 = _self->x_21388; /* 7188 */
  kk_drop_match(_self, {kk_function_dup(f);kk_std_core_types__tuple4__dup(t);kk_box_dup(x_21388);}, {}, _ctx)
  kk_std_core_types__tuple4_ _x23972 = kk_std_core__mlift21186_map_4(x_21388, f, t, _b_22234, _ctx); /*(7188, 7188, 7188, 7188)*/
  return kk_std_core_types__tuple4__box(_x23972, _ctx);
}


// lift anonymous function
struct kk_std_core_map_fun23977__t_4 {
  struct kk_function_s _base;
  kk_function_t f;
  kk_std_core_types__tuple4_ t;
  kk_box_t x_21388;
  kk_box_t x0_21393;
};
static kk_box_t kk_std_core_map_fun23977_4(kk_function_t _fself, kk_box_t _b_22236, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_map_fun23977_4(kk_function_t f, kk_std_core_types__tuple4_ t, kk_box_t x_21388, kk_box_t x0_21393, kk_context_t* _ctx) {
  struct kk_std_core_map_fun23977__t_4* _self = kk_function_alloc_as(struct kk_std_core_map_fun23977__t_4, 5, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_map_fun23977_4, kk_context());
  _self->f = f;
  _self->t = t;
  _self->x_21388 = x_21388;
  _self->x0_21393 = x0_21393;
  return &_self->_base;
}

static kk_box_t kk_std_core_map_fun23977_4(kk_function_t _fself, kk_box_t _b_22236, kk_context_t* _ctx) {
  struct kk_std_core_map_fun23977__t_4* _self = kk_function_as(struct kk_std_core_map_fun23977__t_4*, _fself);
  kk_function_t f = _self->f; /* (7187) -> 7189 7188 */
  kk_std_core_types__tuple4_ t = _self->t; /* (7187, 7187, 7187, 7187) */
  kk_box_t x_21388 = _self->x_21388; /* 7188 */
  kk_box_t x0_21393 = _self->x0_21393; /* 7188 */
  kk_drop_match(_self, {kk_function_dup(f);kk_std_core_types__tuple4__dup(t);kk_box_dup(x_21388);kk_box_dup(x0_21393);}, {}, _ctx)
  kk_std_core_types__tuple4_ _x23978 = kk_std_core__mlift21185_map_4(x_21388, x0_21393, f, t, _b_22236, _ctx); /*(7188, 7188, 7188, 7188)*/
  return kk_std_core_types__tuple4__box(_x23978, _ctx);
}


// lift anonymous function
struct kk_std_core_map_fun23982__t_4 {
  struct kk_function_s _base;
  kk_box_t x_21388;
  kk_box_t x0_21393;
  kk_box_t x1_21398;
};
static kk_box_t kk_std_core_map_fun23982_4(kk_function_t _fself, kk_box_t _b_22238, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_map_fun23982_4(kk_box_t x_21388, kk_box_t x0_21393, kk_box_t x1_21398, kk_context_t* _ctx) {
  struct kk_std_core_map_fun23982__t_4* _self = kk_function_alloc_as(struct kk_std_core_map_fun23982__t_4, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_map_fun23982_4, kk_context());
  _self->x_21388 = x_21388;
  _self->x0_21393 = x0_21393;
  _self->x1_21398 = x1_21398;
  return &_self->_base;
}

static kk_box_t kk_std_core_map_fun23982_4(kk_function_t _fself, kk_box_t _b_22238, kk_context_t* _ctx) {
  struct kk_std_core_map_fun23982__t_4* _self = kk_function_as(struct kk_std_core_map_fun23982__t_4*, _fself);
  kk_box_t x_21388 = _self->x_21388; /* 7188 */
  kk_box_t x0_21393 = _self->x0_21393; /* 7188 */
  kk_box_t x1_21398 = _self->x1_21398; /* 7188 */
  kk_drop_match(_self, {kk_box_dup(x_21388);kk_box_dup(x0_21393);kk_box_dup(x1_21398);}, {}, _ctx)
  kk_std_core_types__tuple4_ _x23983 = kk_std_core__mlift21184_map_4(x_21388, x0_21393, x1_21398, _b_22238, _ctx); /*(7188, 7188, 7188, 7188)*/
  return kk_std_core_types__tuple4__box(_x23983, _ctx);
}

kk_std_core_types__tuple4_ kk_std_core_map_4(kk_std_core_types__tuple4_ t, kk_function_t f, kk_context_t* _ctx) { /* forall<a,b,e> (t : (a, a, a, a), f : (a) -> e b) -> e (b, b, b, b) */ 
  kk_box_t x_21388;
  kk_function_t _x23963 = kk_function_dup(f); /*(7187) -> 7189 7188*/
  kk_box_t _x23961;
  struct kk_std_core_types__Tuple4_* _con23962 = kk_std_core_types__as_dash__lp__comma__comma__comma__rp_(t);
  kk_box_t _x = _con23962->fst;
  kk_box_dup(_x);
  _x23961 = _x; /*7187*/
  x_21388 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x23963, (_x23963, _x23961, _ctx)); /*7188*/
  if (kk_yielding(kk_context())) {
    kk_box_drop(x_21388, _ctx);
    kk_box_t _x23964 = kk_std_core_hnd_yield_extend(kk_std_core_new_map_fun23965_4(f, t, _ctx), _ctx); /*3991*/
    return kk_std_core_types__tuple4__unbox(_x23964, _ctx);
  }
  kk_box_t x0_21393;
  kk_function_t _x23969 = kk_function_dup(f); /*(7187) -> 7189 7188*/
  kk_box_t _x23967;
  struct kk_std_core_types__Tuple4_* _con23968 = kk_std_core_types__as_dash__lp__comma__comma__comma__rp_(t);
  kk_box_t _x0 = _con23968->snd;
  kk_box_dup(_x0);
  _x23967 = _x0; /*7187*/
  x0_21393 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x23969, (_x23969, _x23967, _ctx)); /*7188*/
  if (kk_yielding(kk_context())) {
    kk_box_drop(x0_21393, _ctx);
    kk_box_t _x23970 = kk_std_core_hnd_yield_extend(kk_std_core_new_map_fun23971_4(f, t, x_21388, _ctx), _ctx); /*3991*/
    return kk_std_core_types__tuple4__unbox(_x23970, _ctx);
  }
  kk_box_t x1_21398;
  kk_function_t _x23975 = kk_function_dup(f); /*(7187) -> 7189 7188*/
  kk_box_t _x23973;
  struct kk_std_core_types__Tuple4_* _con23974 = kk_std_core_types__as_dash__lp__comma__comma__comma__rp_(t);
  kk_box_t _x1 = _con23974->thd;
  kk_box_dup(_x1);
  _x23973 = _x1; /*7187*/
  x1_21398 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x23975, (_x23975, _x23973, _ctx)); /*7188*/
  if (kk_yielding(kk_context())) {
    kk_box_drop(x1_21398, _ctx);
    kk_box_t _x23976 = kk_std_core_hnd_yield_extend(kk_std_core_new_map_fun23977_4(f, t, x_21388, x0_21393, _ctx), _ctx); /*3991*/
    return kk_std_core_types__tuple4__unbox(_x23976, _ctx);
  }
  kk_box_t x2_21403;
  kk_box_t _x23979;
  struct kk_std_core_types__Tuple4_* _con23980 = kk_std_core_types__as_dash__lp__comma__comma__comma__rp_(t);
  kk_box_t _pat06 = _con23980->fst;
  kk_box_t _pat13 = _con23980->snd;
  kk_box_t _pat22 = _con23980->thd;
  kk_box_t _x2 = _con23980->field4;
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
  _x23979 = _x2; /*7187*/
  x2_21403 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), f, (f, _x23979, _ctx)); /*7188*/
  if (kk_yielding(kk_context())) {
    kk_box_drop(x2_21403, _ctx);
    kk_box_t _x23981 = kk_std_core_hnd_yield_extend(kk_std_core_new_map_fun23982_4(x_21388, x0_21393, x1_21398, _ctx), _ctx); /*3991*/
    return kk_std_core_types__tuple4__unbox(_x23981, _ctx);
  }
  return kk_std_core_types__new_dash__lp__comma__comma__comma__rp_(kk_reuse_null, x_21388, x0_21393, x1_21398, x2_21403, _ctx);
}
 
// Apply a function `f` to each character in a string


// lift anonymous function
struct kk_std_core_map_fun23984__t_6 {
  struct kk_function_s _base;
  kk_function_t f;
};
static kk_box_t kk_std_core_map_fun23984_6(kk_function_t _fself, kk_box_t _b_22249, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_map_fun23984_6(kk_function_t f, kk_context_t* _ctx) {
  struct kk_std_core_map_fun23984__t_6* _self = kk_function_alloc_as(struct kk_std_core_map_fun23984__t_6, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_map_fun23984_6, kk_context());
  _self->f = f;
  return &_self->_base;
}

static kk_box_t kk_std_core_map_fun23984_6(kk_function_t _fself, kk_box_t _b_22249, kk_context_t* _ctx) {
  struct kk_std_core_map_fun23984__t_6* _self = kk_function_as(struct kk_std_core_map_fun23984__t_6*, _fself);
  kk_function_t f = _self->f; /* (char) -> 7678 char */
  kk_drop_match(_self, {kk_function_dup(f);}, {}, _ctx)
  kk_char_t _x23985;
  kk_char_t _x23986 = kk_char_unbox(_b_22249, _ctx); /*char*/
  _x23985 = kk_function_call(kk_char_t, (kk_function_t, kk_char_t, kk_context_t*), f, (f, _x23986, _ctx)); /*char*/
  return kk_char_box(_x23985, _ctx);
}


// lift anonymous function
struct kk_std_core_map_fun23988__t_6 {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_map_fun23988_6(kk_function_t _fself, kk_box_t _b_22253, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_map_fun23988_6(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_map_fun23988_6, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_core_map_fun23988_6(kk_function_t _fself, kk_box_t _b_22253, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x23989;
  kk_std_core__list _x23990 = kk_std_core__list_unbox(_b_22253, _ctx); /*list<char>*/
  _x23989 = kk_std_core_string_2(_x23990, _ctx); /*string*/
  return kk_string_box(_x23989);
}

kk_string_t kk_std_core_map_6(kk_string_t s, kk_function_t f, kk_context_t* _ctx) { /* forall<e> (s : string, f : (char) -> e char) -> e string */ 
  kk_std_core__list x_21408;
  kk_std_core__list _b_22250_22247 = kk_std_core_list_4(s, _ctx); /*list<char>*/;
  x_21408 = kk_std_core_map_5(_b_22250_22247, kk_std_core_new_map_fun23984_6(f, _ctx), _ctx); /*list<char>*/
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_21408, _ctx);
    kk_box_t _x23987 = kk_std_core_hnd_yield_extend(kk_std_core_new_map_fun23988_6(_ctx), _ctx); /*3991*/
    return kk_string_unbox(_x23987);
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
struct kk_std_core_map_fun23997__t_7 {
  struct kk_function_s _base;
  kk_function_t f;
  kk_vector_t v;
  kk_vector_t w;
};
static kk_unit_t kk_std_core_map_fun23997_7(kk_function_t _fself, size_t i, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_map_fun23997_7(kk_function_t f, kk_vector_t v, kk_vector_t w, kk_context_t* _ctx) {
  struct kk_std_core_map_fun23997__t_7* _self = kk_function_alloc_as(struct kk_std_core_map_fun23997__t_7, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_map_fun23997_7, kk_context());
  _self->f = f;
  _self->v = v;
  _self->w = w;
  return &_self->_base;
}



// lift anonymous function
struct kk_std_core_map_fun23999__t_7 {
  struct kk_function_s _base;
  kk_vector_t w;
  size_t i;
};
static kk_box_t kk_std_core_map_fun23999_7(kk_function_t _fself, kk_box_t _b_22256, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_map_fun23999_7(kk_vector_t w, size_t i, kk_context_t* _ctx) {
  struct kk_std_core_map_fun23999__t_7* _self = kk_function_alloc_as(struct kk_std_core_map_fun23999__t_7, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_map_fun23999_7, kk_context());
  _self->w = w;
  _self->i = i;
  return &_self->_base;
}

static kk_box_t kk_std_core_map_fun23999_7(kk_function_t _fself, kk_box_t _b_22256, kk_context_t* _ctx) {
  struct kk_std_core_map_fun23999__t_7* _self = kk_function_as(struct kk_std_core_map_fun23999__t_7*, _fself);
  kk_vector_t w = _self->w; /* vector<7733> */
  size_t i = _self->i; /* size_t */
  kk_drop_match(_self, {kk_vector_dup(w);;}, {}, _ctx)
  kk_unit_t _x24000 = kk_Unit;
  kk_std_core__mlift21188_map_7(i, w, _b_22256, _ctx);
  return kk_unit_box(_x24000);
}
static kk_unit_t kk_std_core_map_fun23997_7(kk_function_t _fself, size_t i, kk_context_t* _ctx) {
  struct kk_std_core_map_fun23997__t_7* _self = kk_function_as(struct kk_std_core_map_fun23997__t_7*, _fself);
  kk_function_t f = _self->f; /* (7732) -> 7734 7733 */
  kk_vector_t v = _self->v; /* vector<7732> */
  kk_vector_t w = _self->w; /* vector<7733> */
  kk_drop_match(_self, {kk_function_dup(f);kk_vector_dup(v);kk_vector_dup(w);}, {}, _ctx)
  kk_box_t x0_21418 = kk_vector_at(v,i); /*7732*/;
  kk_box_t x1_21420 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), f, (f, x0_21418, _ctx)); /*7733*/;
  if (kk_yielding(kk_context())) {
    kk_box_drop(x1_21420, _ctx);
    kk_box_t _x23998 = kk_std_core_hnd_yield_extend(kk_std_core_new_map_fun23999_7(w, i, _ctx), _ctx); /*3991*/
    return kk_unit_unbox(_x23998);
  }
  return kk_std_core__mlift21188_map_7(i, w, x1_21420, _ctx);
}


// lift anonymous function
struct kk_std_core_map_fun24002__t_7 {
  struct kk_function_s _base;
  kk_vector_t w;
};
static kk_box_t kk_std_core_map_fun24002_7(kk_function_t _fself, kk_box_t _b_22260, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_map_fun24002_7(kk_vector_t w, kk_context_t* _ctx) {
  struct kk_std_core_map_fun24002__t_7* _self = kk_function_alloc_as(struct kk_std_core_map_fun24002__t_7, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_map_fun24002_7, kk_context());
  _self->w = w;
  return &_self->_base;
}

static kk_box_t kk_std_core_map_fun24002_7(kk_function_t _fself, kk_box_t _b_22260, kk_context_t* _ctx) {
  struct kk_std_core_map_fun24002__t_7* _self = kk_function_as(struct kk_std_core_map_fun24002__t_7*, _fself);
  kk_vector_t w = _self->w; /* vector<7733> */
  kk_drop_match(_self, {kk_vector_dup(w);}, {}, _ctx)
  kk_vector_t _x24003;
  kk_unit_t _x24004 = kk_Unit;
  kk_unit_unbox(_b_22260);
  _x24003 = kk_std_core__mlift21189_map_7(w, _x24004, _ctx); /*vector<7733>*/
  return kk_vector_box(_x24003, _ctx);
}

kk_vector_t kk_std_core_map_7(kk_vector_t v, kk_function_t f, kk_context_t* _ctx) { /* forall<a,b,e> (v : vector<a>, f : (a) -> e b) -> e vector<b> */ 
  kk_vector_t w;
  size_t _x23991;
  kk_integer_t _x23992;
  kk_vector_t _x23993 = kk_vector_dup(v); /*vector<7732>*/
  _x23992 = kk_std_core_length_2(_x23993, _ctx); /*int*/
  _x23991 = kk_std_core_size__t(_x23992, _ctx); /*size_t*/
  w = kk_vector_allocz(_x23991,kk_context()); /*vector<7733>*/
  kk_unit_t x_21410 = kk_Unit;
  size_t start_21415 = ((size_t)0); /*size_t*/;
  size_t end_21416;
  size_t _x23994;
  kk_vector_t _x23995 = kk_vector_dup(v); /*vector<7732>*/
  _x23994 = kk_vector_len(_x23995); /*size_t*/
  end_21416 = kk_std_core_decr_1(_x23994, _ctx); /*size_t*/
  kk_function_t _x23996;
  kk_vector_dup(w);
  _x23996 = kk_std_core_new_map_fun23997_7(f, v, w, _ctx); /*(i : size_t) -> 7734 ()*/
  kk_std_core__lift21051_forz(_x23996, end_21416, start_21415, _ctx);
  if (kk_yielding(kk_context())) {
    kk_box_t _x24001 = kk_std_core_hnd_yield_extend(kk_std_core_new_map_fun24002_7(w, _ctx), _ctx); /*3991*/
    return kk_vector_unbox(_x24001, _ctx);
  }
  return w;
}
 
// Right-align a string to width `width`  using `fill`  (default is a space) to fill from the left.

kk_string_t kk_std_core_pad_left(kk_string_t s, kk_integer_t width, kk_std_core_types__optional fill, kk_context_t* _ctx) { /* (s : string, width : int, fill : optional<char>) -> string */ 
  size_t w = kk_std_core_size__t(width, _ctx); /*size_t*/;
  size_t n;
  kk_string_t _x24005 = kk_string_dup(s); /*string*/
  n = kk_string_len(_x24005,kk_context()); /*size_t*/
  bool _match_23585 = (w <= n); /*bool*/;
  if (_match_23585) {
    kk_std_core_types__optional_drop(fill, _ctx);
    return s;
  }
  kk_string_t _x24006;
  kk_string_t _x24007;
  kk_char_t _x24008;
  if (kk_std_core_types__is_Optional(fill)) {
    kk_box_t _box_x22263 = fill._cons.Optional.value;
    kk_char_t _fill_8417 = kk_char_unbox(_box_x22263, NULL);
    kk_std_core_types__optional_drop(fill, _ctx);
    _x24008 = _fill_8417; /*char*/
    goto _match24009;
  }
  _x24008 = ' '; /*char*/
  _match24009: ;
  _x24007 = kk_std_core_string(_x24008, _ctx); /*string*/
  size_t _x24011 = (w - n); /*size_t*/
  _x24006 = kk_std_core_repeatz(_x24007, _x24011, _ctx); /*string*/
  return kk_std_core__lp__plus__plus__1_rp_(_x24006, s, _ctx);
}
 
// Show an `:int` as a hexadecimal value.
// The `width`  parameter specifies how wide the hex value is where `"0"`  is used to align.
// The `use-capitals` parameter (= `True`) determines if captical letters should be used to display the hexadecimal digits.
// The `pre` (=`"0x"`) is an optional prefix for the number (goes between the sign and the number).

kk_string_t kk_std_core_show_hex(kk_integer_t i, kk_std_core_types__optional width, kk_std_core_types__optional use_capitals, kk_std_core_types__optional pre, kk_context_t* _ctx) { /* (i : int, width : optional<int>, use-capitals : optional<bool>, pre : optional<string>) -> string */ 
  kk_string_t _x24012;
  bool _match_23584;
  kk_integer_t _x24013 = kk_integer_dup(i); /*int*/
  _match_23584 = kk_integer_lt(_x24013,(kk_integer_from_small(0)),kk_context()); /*bool*/
  if (_match_23584) {
    kk_define_string_literal(, _s24014, 1, "-")
    _x24012 = kk_string_dup(_s24014); /*string*/
  }
  else {
    _x24012 = kk_string_empty(); /*string*/
  }
  kk_string_t _x24016;
  kk_string_t _x24017;
  if (kk_std_core_types__is_Optional(pre)) {
    kk_box_t _box_x22264 = pre._cons.Optional.value;
    kk_string_t _pre_8591 = kk_string_unbox(_box_x22264);
    kk_string_dup(_pre_8591);
    kk_std_core_types__optional_drop(pre, _ctx);
    _x24017 = _pre_8591; /*string*/
    goto _match24018;
  }
  kk_define_string_literal(, _s24020, 2, "0x")
  _x24017 = kk_string_dup(_s24020); /*string*/
  _match24018: ;
  kk_string_t _x24021;
  kk_string_t s_21423;
  kk_integer_t _x24022 = kk_integer_abs(i,kk_context()); /*int*/
  bool _x24023;
  if (kk_std_core_types__is_Optional(use_capitals)) {
    kk_box_t _box_x22265 = use_capitals._cons.Optional.value;
    bool _use_capitals_8587 = kk_bool_unbox(_box_x22265);
    kk_std_core_types__optional_drop(use_capitals, _ctx);
    _x24023 = _use_capitals_8587; /*bool*/
    goto _match24024;
  }
  _x24023 = true; /*bool*/
  _match24024: ;
  s_21423 = kk_std_core_int_show_hex(_x24022, _x24023, _ctx); /*string*/
  kk_std_core_types__optional fill_21425 = kk_std_core_types__new_Optional(kk_char_box('0', _ctx), _ctx); /*optional<char>*/;
  size_t w;
  kk_integer_t _x24026;
  if (kk_std_core_types__is_Optional(width)) {
    kk_box_t _box_x22268 = width._cons.Optional.value;
    kk_integer_t _width_8583 = kk_integer_unbox(_box_x22268);
    kk_integer_dup(_width_8583);
    kk_std_core_types__optional_drop(width, _ctx);
    _x24026 = _width_8583; /*int*/
    goto _match24027;
  }
  _x24026 = kk_integer_from_small(1); /*int*/
  _match24027: ;
  w = kk_std_core_size__t(_x24026, _ctx); /*size_t*/
  size_t n;
  kk_string_t _x24029 = kk_string_dup(s_21423); /*string*/
  n = kk_string_len(_x24029,kk_context()); /*size_t*/
  bool _match_23583 = (w <= n); /*bool*/;
  if (_match_23583) {
    kk_std_core_types__optional_drop(fill_21425, _ctx);
    _x24021 = s_21423; /*string*/
  }
  else {
    kk_string_t _x24030;
    kk_string_t _x24031;
    kk_char_t _x24032;
    if (kk_std_core_types__is_Optional(fill_21425)) {
      kk_box_t _box_x22269 = fill_21425._cons.Optional.value;
      kk_char_t _fill_8417 = kk_char_unbox(_box_x22269, NULL);
      kk_std_core_types__optional_drop(fill_21425, _ctx);
      _x24032 = _fill_8417; /*char*/
      goto _match24033;
    }
    _x24032 = ' '; /*char*/
    _match24033: ;
    _x24031 = kk_std_core_string(_x24032, _ctx); /*string*/
    size_t _x24035 = (w - n); /*size_t*/
    _x24030 = kk_std_core_repeatz(_x24031, _x24035, _ctx); /*string*/
    _x24021 = kk_std_core__lp__plus__plus__1_rp_(_x24030, s_21423, _ctx); /*string*/
  }
  _x24016 = kk_std_core__lp__plus__plus__1_rp_(_x24017, _x24021, _ctx); /*string*/
  return kk_std_core__lp__plus__plus__1_rp_(_x24012, _x24016, _ctx);
}
 
// Is the integer positive (stricly greater than zero)

bool kk_std_core_is_pos_2(kk_integer_t i, kk_context_t* _ctx) { /* (i : int) -> bool */ 
  kk_std_core_types__order x_21426 = kk_int_as_order(kk_integer_signum(i,kk_context()),kk_context()); /*order*/;
  kk_integer_t _x24036 = kk_std_core_int_5(x_21426, _ctx); /*int*/
  kk_integer_t _x24037;
  kk_std_core_types__order _x24038 = kk_std_core_types__new_Gt(_ctx); /*order*/
  if (kk_std_core_types__is_Lt(_x24038)) {
    _x24037 = kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context()); /*int*/
    goto _match24039;
  }
  if (kk_std_core_types__is_Eq(_x24038)) {
    _x24037 = kk_integer_from_small(0); /*int*/
    goto _match24039;
  }
  _x24037 = kk_integer_from_small(1); /*int*/
  _match24039: ;
  return kk_integer_eq(_x24036,_x24037,kk_context());
}
 
// Show a character as a string

kk_string_t kk_std_core_show_char(kk_char_t c, kk_context_t* _ctx) { /* (c : char) -> string */ 
  bool _match_23560;
  bool _match_23578 = (c < (' ')); /*bool*/;
  if (_match_23578) {
    _match_23560 = true; /*bool*/
  }
  else {
    _match_23560 = (c > ('~')); /*bool*/
  }
  if (_match_23560) {
    bool _match_23564 = (c == 0x000A); /*bool*/;
    if (_match_23564) {
      kk_define_string_literal(, _s24045, 2, "\\n")
      return kk_string_dup(_s24045);
    }
    bool _match_23565 = (c == 0x000D); /*bool*/;
    if (_match_23565) {
      kk_define_string_literal(, _s24046, 2, "\\r")
      return kk_string_dup(_s24046);
    }
    bool _match_23566 = (c == 0x0009); /*bool*/;
    if (_match_23566) {
      kk_define_string_literal(, _s24047, 2, "\\t")
      return kk_string_dup(_s24047);
    }
    bool _match_23567;
    kk_integer_t _x24048 = kk_integer_from_int(c,kk_context()); /*int*/
    _match_23567 = kk_integer_lte(_x24048,(kk_integer_from_small(255)),kk_context()); /*bool*/
    if (_match_23567) {
      kk_string_t _x24049;
      kk_define_string_literal(, _s24050, 2, "\\x")
      _x24049 = kk_string_dup(_s24050); /*string*/
      kk_string_t _x24051;
      kk_integer_t _arg_9350 = kk_integer_from_int(c,kk_context()); /*int*/;
      kk_std_core_types__optional _arg_9351 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(2)), _ctx); /*optional<int>*/;
      kk_std_core_types__optional _arg_9353;
      kk_box_t _x24052;
      kk_string_t _x24053 = kk_string_empty(); /*string*/
      _x24052 = kk_string_box(_x24053); /*108*/
      _arg_9353 = kk_std_core_types__new_Optional(_x24052, _ctx); /*optional<string>*/
      kk_string_t _x24055;
      bool _match_23577;
      kk_integer_t _x24056 = kk_integer_dup(_arg_9350); /*int*/
      _match_23577 = kk_integer_lt(_x24056,(kk_integer_from_small(0)),kk_context()); /*bool*/
      if (_match_23577) {
        kk_define_string_literal(, _s24057, 1, "-")
        _x24055 = kk_string_dup(_s24057); /*string*/
      }
      else {
        _x24055 = kk_string_empty(); /*string*/
      }
      kk_string_t _x24059;
      kk_string_t _x24060;
      if (kk_std_core_types__is_Optional(_arg_9353)) {
        kk_box_t _box_x22274 = _arg_9353._cons.Optional.value;
        kk_string_t _pre_8591 = kk_string_unbox(_box_x22274);
        kk_string_dup(_pre_8591);
        kk_std_core_types__optional_drop(_arg_9353, _ctx);
        _x24060 = _pre_8591; /*string*/
        goto _match24061;
      }
      kk_define_string_literal(, _s24063, 2, "0x")
      _x24060 = kk_string_dup(_s24063); /*string*/
      _match24061: ;
      kk_string_t _x24064;
      kk_string_t s_21433;
      kk_integer_t _x24065 = kk_integer_abs(_arg_9350,kk_context()); /*int*/
      bool _x24066;
      kk_std_core_types__optional _match_23576 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
      if (kk_std_core_types__is_Optional(_match_23576)) {
        kk_box_t _box_x22275 = _match_23576._cons.Optional.value;
        bool _use_capitals_8587 = kk_bool_unbox(_box_x22275);
        kk_std_core_types__optional_drop(_match_23576, _ctx);
        _x24066 = _use_capitals_8587; /*bool*/
        goto _match24067;
      }
      _x24066 = true; /*bool*/
      _match24067: ;
      s_21433 = kk_std_core_int_show_hex(_x24065, _x24066, _ctx); /*string*/
      kk_std_core_types__optional fill_21435 = kk_std_core_types__new_Optional(kk_char_box('0', _ctx), _ctx); /*optional<char>*/;
      size_t w;
      kk_integer_t _x24069;
      if (kk_std_core_types__is_Optional(_arg_9351)) {
        kk_box_t _box_x22278 = _arg_9351._cons.Optional.value;
        kk_integer_t _width_8583 = kk_integer_unbox(_box_x22278);
        kk_integer_dup(_width_8583);
        kk_std_core_types__optional_drop(_arg_9351, _ctx);
        _x24069 = _width_8583; /*int*/
        goto _match24070;
      }
      _x24069 = kk_integer_from_small(1); /*int*/
      _match24070: ;
      w = kk_std_core_size__t(_x24069, _ctx); /*size_t*/
      size_t n;
      kk_string_t _x24072 = kk_string_dup(s_21433); /*string*/
      n = kk_string_len(_x24072,kk_context()); /*size_t*/
      bool _match_23575 = (w <= n); /*bool*/;
      if (_match_23575) {
        kk_std_core_types__optional_drop(fill_21435, _ctx);
        _x24064 = s_21433; /*string*/
      }
      else {
        kk_string_t _x24073;
        kk_string_t _x24074;
        kk_char_t _x24075;
        if (kk_std_core_types__is_Optional(fill_21435)) {
          kk_box_t _box_x22279 = fill_21435._cons.Optional.value;
          kk_char_t _fill_8417 = kk_char_unbox(_box_x22279, NULL);
          kk_std_core_types__optional_drop(fill_21435, _ctx);
          _x24075 = _fill_8417; /*char*/
          goto _match24076;
        }
        _x24075 = ' '; /*char*/
        _match24076: ;
        _x24074 = kk_std_core_string(_x24075, _ctx); /*string*/
        size_t _x24078 = (w - n); /*size_t*/
        _x24073 = kk_std_core_repeatz(_x24074, _x24078, _ctx); /*string*/
        _x24064 = kk_std_core__lp__plus__plus__1_rp_(_x24073, s_21433, _ctx); /*string*/
      }
      _x24059 = kk_std_core__lp__plus__plus__1_rp_(_x24060, _x24064, _ctx); /*string*/
      _x24051 = kk_std_core__lp__plus__plus__1_rp_(_x24055, _x24059, _ctx); /*string*/
      return kk_std_core__lp__plus__plus__1_rp_(_x24049, _x24051, _ctx);
    }
    bool _match_23568;
    kk_integer_t _x24079 = kk_integer_from_int(c,kk_context()); /*int*/
    _match_23568 = kk_integer_lte(_x24079,(kk_integer_from_int(65535, _ctx)),kk_context()); /*bool*/
    if (_match_23568) {
      kk_string_t _x24080;
      kk_define_string_literal(, _s24081, 2, "\\u")
      _x24080 = kk_string_dup(_s24081); /*string*/
      kk_string_t _x24082;
      kk_integer_t _arg_9482 = kk_integer_from_int(c,kk_context()); /*int*/;
      kk_std_core_types__optional _arg_9483 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(4)), _ctx); /*optional<int>*/;
      kk_std_core_types__optional _arg_9485;
      kk_box_t _x24083;
      kk_string_t _x24084 = kk_string_empty(); /*string*/
      _x24083 = kk_string_box(_x24084); /*108*/
      _arg_9485 = kk_std_core_types__new_Optional(_x24083, _ctx); /*optional<string>*/
      kk_string_t _x24086;
      bool _match_23574;
      kk_integer_t _x24087 = kk_integer_dup(_arg_9482); /*int*/
      _match_23574 = kk_integer_lt(_x24087,(kk_integer_from_small(0)),kk_context()); /*bool*/
      if (_match_23574) {
        kk_define_string_literal(, _s24088, 1, "-")
        _x24086 = kk_string_dup(_s24088); /*string*/
      }
      else {
        _x24086 = kk_string_empty(); /*string*/
      }
      kk_string_t _x24090;
      kk_string_t _x24091;
      if (kk_std_core_types__is_Optional(_arg_9485)) {
        kk_box_t _box_x22284 = _arg_9485._cons.Optional.value;
        kk_string_t _pre_85910 = kk_string_unbox(_box_x22284);
        kk_string_dup(_pre_85910);
        kk_std_core_types__optional_drop(_arg_9485, _ctx);
        _x24091 = _pre_85910; /*string*/
        goto _match24092;
      }
      kk_define_string_literal(, _s24094, 2, "0x")
      _x24091 = kk_string_dup(_s24094); /*string*/
      _match24092: ;
      kk_string_t _x24095;
      kk_string_t s0_21440;
      kk_integer_t _x24096 = kk_integer_abs(_arg_9482,kk_context()); /*int*/
      bool _x24097;
      kk_std_core_types__optional _match_23573 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
      if (kk_std_core_types__is_Optional(_match_23573)) {
        kk_box_t _box_x22285 = _match_23573._cons.Optional.value;
        bool _use_capitals_85870 = kk_bool_unbox(_box_x22285);
        kk_std_core_types__optional_drop(_match_23573, _ctx);
        _x24097 = _use_capitals_85870; /*bool*/
        goto _match24098;
      }
      _x24097 = true; /*bool*/
      _match24098: ;
      s0_21440 = kk_std_core_int_show_hex(_x24096, _x24097, _ctx); /*string*/
      kk_std_core_types__optional fill0_21442 = kk_std_core_types__new_Optional(kk_char_box('0', _ctx), _ctx); /*optional<char>*/;
      size_t w0;
      kk_integer_t _x24100;
      if (kk_std_core_types__is_Optional(_arg_9483)) {
        kk_box_t _box_x22288 = _arg_9483._cons.Optional.value;
        kk_integer_t _width_85830 = kk_integer_unbox(_box_x22288);
        kk_integer_dup(_width_85830);
        kk_std_core_types__optional_drop(_arg_9483, _ctx);
        _x24100 = _width_85830; /*int*/
        goto _match24101;
      }
      _x24100 = kk_integer_from_small(1); /*int*/
      _match24101: ;
      w0 = kk_std_core_size__t(_x24100, _ctx); /*size_t*/
      size_t n0;
      kk_string_t _x24103 = kk_string_dup(s0_21440); /*string*/
      n0 = kk_string_len(_x24103,kk_context()); /*size_t*/
      bool _match_23572 = (w0 <= n0); /*bool*/;
      if (_match_23572) {
        kk_std_core_types__optional_drop(fill0_21442, _ctx);
        _x24095 = s0_21440; /*string*/
      }
      else {
        kk_string_t _x24104;
        kk_string_t _x24105;
        kk_char_t _x24106;
        if (kk_std_core_types__is_Optional(fill0_21442)) {
          kk_box_t _box_x22289 = fill0_21442._cons.Optional.value;
          kk_char_t _fill_84170 = kk_char_unbox(_box_x22289, NULL);
          kk_std_core_types__optional_drop(fill0_21442, _ctx);
          _x24106 = _fill_84170; /*char*/
          goto _match24107;
        }
        _x24106 = ' '; /*char*/
        _match24107: ;
        _x24105 = kk_std_core_string(_x24106, _ctx); /*string*/
        size_t _x24109 = (w0 - n0); /*size_t*/
        _x24104 = kk_std_core_repeatz(_x24105, _x24109, _ctx); /*string*/
        _x24095 = kk_std_core__lp__plus__plus__1_rp_(_x24104, s0_21440, _ctx); /*string*/
      }
      _x24090 = kk_std_core__lp__plus__plus__1_rp_(_x24091, _x24095, _ctx); /*string*/
      _x24082 = kk_std_core__lp__plus__plus__1_rp_(_x24086, _x24090, _ctx); /*string*/
      return kk_std_core__lp__plus__plus__1_rp_(_x24080, _x24082, _ctx);
    }
    kk_string_t _x24110;
    kk_define_string_literal(, _s24111, 2, "\\U")
    _x24110 = kk_string_dup(_s24111); /*string*/
    kk_string_t _x24112;
    kk_integer_t _arg_9538 = kk_integer_from_int(c,kk_context()); /*int*/;
    kk_std_core_types__optional _arg_9539 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(6)), _ctx); /*optional<int>*/;
    kk_std_core_types__optional _arg_9541;
    kk_box_t _x24113;
    kk_string_t _x24114 = kk_string_empty(); /*string*/
    _x24113 = kk_string_box(_x24114); /*108*/
    _arg_9541 = kk_std_core_types__new_Optional(_x24113, _ctx); /*optional<string>*/
    kk_string_t _x24116;
    bool _match_23571;
    kk_integer_t _x24117 = kk_integer_dup(_arg_9538); /*int*/
    _match_23571 = kk_integer_lt(_x24117,(kk_integer_from_small(0)),kk_context()); /*bool*/
    if (_match_23571) {
      kk_define_string_literal(, _s24118, 1, "-")
      _x24116 = kk_string_dup(_s24118); /*string*/
    }
    else {
      _x24116 = kk_string_empty(); /*string*/
    }
    kk_string_t _x24120;
    kk_string_t _x24121;
    if (kk_std_core_types__is_Optional(_arg_9541)) {
      kk_box_t _box_x22294 = _arg_9541._cons.Optional.value;
      kk_string_t _pre_85911 = kk_string_unbox(_box_x22294);
      kk_string_dup(_pre_85911);
      kk_std_core_types__optional_drop(_arg_9541, _ctx);
      _x24121 = _pre_85911; /*string*/
      goto _match24122;
    }
    kk_define_string_literal(, _s24124, 2, "0x")
    _x24121 = kk_string_dup(_s24124); /*string*/
    _match24122: ;
    kk_string_t _x24125;
    kk_string_t s1_21447;
    kk_integer_t _x24126 = kk_integer_abs(_arg_9538,kk_context()); /*int*/
    bool _x24127;
    kk_std_core_types__optional _match_23570 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
    if (kk_std_core_types__is_Optional(_match_23570)) {
      kk_box_t _box_x22295 = _match_23570._cons.Optional.value;
      bool _use_capitals_85871 = kk_bool_unbox(_box_x22295);
      kk_std_core_types__optional_drop(_match_23570, _ctx);
      _x24127 = _use_capitals_85871; /*bool*/
      goto _match24128;
    }
    _x24127 = true; /*bool*/
    _match24128: ;
    s1_21447 = kk_std_core_int_show_hex(_x24126, _x24127, _ctx); /*string*/
    kk_std_core_types__optional fill1_21449 = kk_std_core_types__new_Optional(kk_char_box('0', _ctx), _ctx); /*optional<char>*/;
    size_t w1;
    kk_integer_t _x24130;
    if (kk_std_core_types__is_Optional(_arg_9539)) {
      kk_box_t _box_x22298 = _arg_9539._cons.Optional.value;
      kk_integer_t _width_85831 = kk_integer_unbox(_box_x22298);
      kk_integer_dup(_width_85831);
      kk_std_core_types__optional_drop(_arg_9539, _ctx);
      _x24130 = _width_85831; /*int*/
      goto _match24131;
    }
    _x24130 = kk_integer_from_small(1); /*int*/
    _match24131: ;
    w1 = kk_std_core_size__t(_x24130, _ctx); /*size_t*/
    size_t n1;
    kk_string_t _x24133 = kk_string_dup(s1_21447); /*string*/
    n1 = kk_string_len(_x24133,kk_context()); /*size_t*/
    bool _match_23569 = (w1 <= n1); /*bool*/;
    if (_match_23569) {
      kk_std_core_types__optional_drop(fill1_21449, _ctx);
      _x24125 = s1_21447; /*string*/
    }
    else {
      kk_string_t _x24134;
      kk_string_t _x24135;
      kk_char_t _x24136;
      if (kk_std_core_types__is_Optional(fill1_21449)) {
        kk_box_t _box_x22299 = fill1_21449._cons.Optional.value;
        kk_char_t _fill_84171 = kk_char_unbox(_box_x22299, NULL);
        kk_std_core_types__optional_drop(fill1_21449, _ctx);
        _x24136 = _fill_84171; /*char*/
        goto _match24137;
      }
      _x24136 = ' '; /*char*/
      _match24137: ;
      _x24135 = kk_std_core_string(_x24136, _ctx); /*string*/
      size_t _x24139 = (w1 - n1); /*size_t*/
      _x24134 = kk_std_core_repeatz(_x24135, _x24139, _ctx); /*string*/
      _x24125 = kk_std_core__lp__plus__plus__1_rp_(_x24134, s1_21447, _ctx); /*string*/
    }
    _x24120 = kk_std_core__lp__plus__plus__1_rp_(_x24121, _x24125, _ctx); /*string*/
    _x24112 = kk_std_core__lp__plus__plus__1_rp_(_x24116, _x24120, _ctx); /*string*/
    return kk_std_core__lp__plus__plus__1_rp_(_x24110, _x24112, _ctx);
  }
  bool _match_23561 = (c == ('\'')); /*bool*/;
  if (_match_23561) {
    kk_define_string_literal(, _s24140, 2, "\\\'")
    return kk_string_dup(_s24140);
  }
  bool _match_23562 = (c == ('"')); /*bool*/;
  if (_match_23562) {
    kk_define_string_literal(, _s24141, 2, "\\\"")
    return kk_string_dup(_s24141);
  }
  bool _match_23563 = (c == ('\\')); /*bool*/;
  if (_match_23563) {
    kk_define_string_literal(, _s24142, 2, "\\\\")
    return kk_string_dup(_s24142);
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
  bool _match_23558;
  bool _match_23559 = (dabs < (0x1.203af9ee75616p-50)); /*bool*/;
  if (_match_23559) {
    _match_23558 = true; /*bool*/
  }
  else {
    _match_23558 = (dabs > (0x1.b1ae4d6e2ef5p69)); /*bool*/
  }
  if (_match_23558) {
    kk_std_core_types__optional precision0_21451;
    kk_box_t _x24147;
    kk_integer_t _x24148;
    if (kk_std_core_types__is_Optional(precision)) {
      kk_box_t _box_x22301 = precision._cons.Optional.value;
      kk_integer_t _precision_9673 = kk_integer_unbox(_box_x22301);
      kk_integer_dup(_precision_9673);
      kk_std_core_types__optional_drop(precision, _ctx);
      _x24148 = _precision_9673; /*int*/
      goto _match24149;
    }
    _x24148 = kk_integer_from_small(-2); /*int*/
    _match24149: ;
    _x24147 = kk_integer_box(_x24148); /*108*/
    precision0_21451 = kk_std_core_types__new_Optional(_x24147, _ctx); /*optional<int>*/
    int32_t _x24151;
    kk_integer_t _x24152;
    if (kk_std_core_types__is_Optional(precision0_21451)) {
      kk_box_t _box_x22304 = precision0_21451._cons.Optional.value;
      kk_integer_t _precision_9662 = kk_integer_unbox(_box_x22304);
      kk_integer_dup(_precision_9662);
      kk_std_core_types__optional_drop(precision0_21451, _ctx);
      _x24152 = _precision_9662; /*int*/
      goto _match24153;
    }
    _x24152 = kk_integer_from_small(-17); /*int*/
    _match24153: ;
    _x24151 = kk_std_core_int32(_x24152, _ctx); /*int32*/
    return kk_std_core_show_expx(d, _x24151, _ctx);
  }
  int32_t _x24155;
  kk_integer_t _x24156;
  if (kk_std_core_types__is_Optional(precision)) {
    kk_box_t _box_x22305 = precision._cons.Optional.value;
    kk_integer_t _precision_96730 = kk_integer_unbox(_box_x22305);
    kk_integer_dup(_precision_96730);
    kk_std_core_types__optional_drop(precision, _ctx);
    _x24156 = _precision_96730; /*int*/
    goto _match24157;
  }
  _x24156 = kk_integer_from_small(-2); /*int*/
  _match24157: ;
  _x24155 = kk_std_core_int32(_x24156, _ctx); /*int32*/
  return kk_std_core_show_fixedx(d, _x24155, _ctx);
}
 
// monadic lift

kk_string_t kk_std_core__mlift21190_show_list(kk_std_core__list _y_75, kk_context_t* _ctx) { /* forall<e> (list<string>) -> e string */ 
  kk_string_t _x24159;
  kk_define_string_literal(, _s24160, 1, "[")
  _x24159 = kk_string_dup(_s24160); /*string*/
  kk_string_t _x24161;
  kk_string_t _x24162;
  if (kk_std_core__is_Nil(_y_75)) {
    _x24162 = kk_string_empty(); /*string*/
  }
  else {
    struct kk_std_core_Cons* _con24164 = kk_std_core__as_Cons(_y_75);
    kk_box_t _box_x22306 = _con24164->head;
    kk_std_core__list xx = _con24164->tail;
    kk_string_t x = kk_string_unbox(_box_x22306);
    if (kk_std_core__list_is_unique(_y_75)) {
      kk_std_core__list_free(_y_75);
    }
    else {
      kk_string_dup(x);
      kk_std_core__list_dup(xx);
      kk_std_core__list_decref(_y_75, _ctx);
    }
    kk_string_t _x24166;
    kk_define_string_literal(, _s24167, 1, ",")
    _x24166 = kk_string_dup(_s24167); /*string*/
    _x24162 = kk_std_core__lift21050_joinsep(_x24166, xx, x, _ctx); /*string*/
  }
  kk_string_t _x24168;
  kk_define_string_literal(, _s24169, 1, "]")
  _x24168 = kk_string_dup(_s24169); /*string*/
  _x24161 = kk_std_core__lp__plus__plus__1_rp_(_x24162, _x24168, _ctx); /*string*/
  return kk_std_core__lp__plus__plus__1_rp_(_x24159, _x24161, _ctx);
}
 
// Convert a list to a string


// lift anonymous function
struct kk_std_core_show_list_fun24170__t {
  struct kk_function_s _base;
  kk_function_t show_elem;
};
static kk_box_t kk_std_core_show_list_fun24170(kk_function_t _fself, kk_box_t _b_22309, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_show_list_fun24170(kk_function_t show_elem, kk_context_t* _ctx) {
  struct kk_std_core_show_list_fun24170__t* _self = kk_function_alloc_as(struct kk_std_core_show_list_fun24170__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_show_list_fun24170, kk_context());
  _self->show_elem = show_elem;
  return &_self->_base;
}

static kk_box_t kk_std_core_show_list_fun24170(kk_function_t _fself, kk_box_t _b_22309, kk_context_t* _ctx) {
  struct kk_std_core_show_list_fun24170__t* _self = kk_function_as(struct kk_std_core_show_list_fun24170__t*, _fself);
  kk_function_t show_elem = _self->show_elem; /* (10296) -> 10297 string */
  kk_drop_match(_self, {kk_function_dup(show_elem);}, {}, _ctx)
  kk_string_t _x24171 = kk_function_call(kk_string_t, (kk_function_t, kk_box_t, kk_context_t*), show_elem, (show_elem, _b_22309, _ctx)); /*string*/
  return kk_string_box(_x24171);
}


// lift anonymous function
struct kk_std_core_show_list_fun24173__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_show_list_fun24173(kk_function_t _fself, kk_box_t _b_22313, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_show_list_fun24173(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_show_list_fun24173, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_core_show_list_fun24173(kk_function_t _fself, kk_box_t _b_22313, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x24174;
  kk_std_core__list _x24175 = kk_std_core__list_unbox(_b_22313, _ctx); /*list<string>*/
  _x24174 = kk_std_core__mlift21190_show_list(_x24175, _ctx); /*string*/
  return kk_string_box(_x24174);
}

kk_string_t kk_std_core_show_list(kk_std_core__list xs, kk_function_t show_elem, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, show-elem : (a) -> e string) -> e string */ 
  kk_std_core__list x_21454 = kk_std_core_map_5(xs, kk_std_core_new_show_list_fun24170(show_elem, _ctx), _ctx); /*list<string>*/;
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_21454, _ctx);
    kk_box_t _x24172 = kk_std_core_hnd_yield_extend(kk_std_core_new_show_list_fun24173(_ctx), _ctx); /*3991*/
    return kk_string_unbox(_x24172);
  }
  kk_string_t _x24176;
  kk_define_string_literal(, _s24177, 1, "[")
  _x24176 = kk_string_dup(_s24177); /*string*/
  kk_string_t _x24178;
  kk_string_t _x24179;
  if (kk_std_core__is_Nil(x_21454)) {
    _x24179 = kk_string_empty(); /*string*/
  }
  else {
    struct kk_std_core_Cons* _con24181 = kk_std_core__as_Cons(x_21454);
    kk_box_t _box_x22314 = _con24181->head;
    kk_std_core__list xx = _con24181->tail;
    kk_string_t x = kk_string_unbox(_box_x22314);
    if (kk_std_core__list_is_unique(x_21454)) {
      kk_std_core__list_free(x_21454);
    }
    else {
      kk_string_dup(x);
      kk_std_core__list_dup(xx);
      kk_std_core__list_decref(x_21454, _ctx);
    }
    kk_string_t _x24183;
    kk_define_string_literal(, _s24184, 1, ",")
    _x24183 = kk_string_dup(_s24184); /*string*/
    _x24179 = kk_std_core__lift21050_joinsep(_x24183, xx, x, _ctx); /*string*/
  }
  kk_string_t _x24185;
  kk_define_string_literal(, _s24186, 1, "]")
  _x24185 = kk_string_dup(_s24186); /*string*/
  _x24178 = kk_std_core__lp__plus__plus__1_rp_(_x24179, _x24185, _ctx); /*string*/
  return kk_std_core__lp__plus__plus__1_rp_(_x24176, _x24178, _ctx);
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
  bool _match_23553;
  bool _match_23556 = (dabs >= (0x1.4f8b588e368f1p-17)); /*bool*/;
  if (_match_23556) {
    _match_23553 = (dabs < (0x1.b1ae4d6e2ef5p69)); /*bool*/
  }
  else {
    _match_23553 = false; /*bool*/
  }
  if (_match_23553) {
    kk_std_core_types__optional precision0_21461;
    kk_box_t _x24187;
    kk_integer_t _x24188;
    if (kk_std_core_types__is_Optional(precision)) {
      kk_box_t _box_x22317 = precision._cons.Optional.value;
      kk_integer_t _precision_10416 = kk_integer_unbox(_box_x22317);
      kk_integer_dup(_precision_10416);
      kk_std_core_types__optional_drop(precision, _ctx);
      _x24188 = _precision_10416; /*int*/
      goto _match24189;
    }
    _x24188 = kk_integer_from_small(-17); /*int*/
    _match24189: ;
    _x24187 = kk_integer_box(_x24188); /*108*/
    precision0_21461 = kk_std_core_types__new_Optional(_x24187, _ctx); /*optional<int>*/
    double dabs0 = kk_double_abs(d); /*double*/;
    bool _match_23554;
    bool _match_23555 = (dabs0 < (0x1.203af9ee75616p-50)); /*bool*/;
    if (_match_23555) {
      _match_23554 = true; /*bool*/
    }
    else {
      _match_23554 = (dabs0 > (0x1.b1ae4d6e2ef5p69)); /*bool*/
    }
    if (_match_23554) {
      kk_std_core_types__optional precision1_21463;
      kk_box_t _x24191;
      kk_integer_t _x24192;
      if (kk_std_core_types__is_Optional(precision0_21461)) {
        kk_box_t _box_x22320 = precision0_21461._cons.Optional.value;
        kk_integer_t _precision_9673 = kk_integer_unbox(_box_x22320);
        kk_integer_dup(_precision_9673);
        kk_std_core_types__optional_drop(precision0_21461, _ctx);
        _x24192 = _precision_9673; /*int*/
        goto _match24193;
      }
      _x24192 = kk_integer_from_small(-2); /*int*/
      _match24193: ;
      _x24191 = kk_integer_box(_x24192); /*108*/
      precision1_21463 = kk_std_core_types__new_Optional(_x24191, _ctx); /*optional<int>*/
      int32_t _x24195;
      kk_integer_t _x24196;
      if (kk_std_core_types__is_Optional(precision1_21463)) {
        kk_box_t _box_x22323 = precision1_21463._cons.Optional.value;
        kk_integer_t _precision_9662 = kk_integer_unbox(_box_x22323);
        kk_integer_dup(_precision_9662);
        kk_std_core_types__optional_drop(precision1_21463, _ctx);
        _x24196 = _precision_9662; /*int*/
        goto _match24197;
      }
      _x24196 = kk_integer_from_small(-17); /*int*/
      _match24197: ;
      _x24195 = kk_std_core_int32(_x24196, _ctx); /*int32*/
      return kk_std_core_show_expx(d, _x24195, _ctx);
    }
    int32_t _x24199;
    kk_integer_t _x24200;
    if (kk_std_core_types__is_Optional(precision0_21461)) {
      kk_box_t _box_x22324 = precision0_21461._cons.Optional.value;
      kk_integer_t _precision_96730 = kk_integer_unbox(_box_x22324);
      kk_integer_dup(_precision_96730);
      kk_std_core_types__optional_drop(precision0_21461, _ctx);
      _x24200 = _precision_96730; /*int*/
      goto _match24201;
    }
    _x24200 = kk_integer_from_small(-2); /*int*/
    _match24201: ;
    _x24199 = kk_std_core_int32(_x24200, _ctx); /*int32*/
    return kk_std_core_show_fixedx(d, _x24199, _ctx);
  }
  kk_std_core_types__optional precision2_21465;
  kk_box_t _x24203;
  kk_integer_t _x24204;
  if (kk_std_core_types__is_Optional(precision)) {
    kk_box_t _box_x22325 = precision._cons.Optional.value;
    kk_integer_t _precision_104160 = kk_integer_unbox(_box_x22325);
    kk_integer_dup(_precision_104160);
    kk_std_core_types__optional_drop(precision, _ctx);
    _x24204 = _precision_104160; /*int*/
    goto _match24205;
  }
  _x24204 = kk_integer_from_small(-17); /*int*/
  _match24205: ;
  _x24203 = kk_integer_box(_x24204); /*108*/
  precision2_21465 = kk_std_core_types__new_Optional(_x24203, _ctx); /*optional<int>*/
  int32_t _x24207;
  kk_integer_t _x24208;
  if (kk_std_core_types__is_Optional(precision2_21465)) {
    kk_box_t _box_x22328 = precision2_21465._cons.Optional.value;
    kk_integer_t _precision_96620 = kk_integer_unbox(_box_x22328);
    kk_integer_dup(_precision_96620);
    kk_std_core_types__optional_drop(precision2_21465, _ctx);
    _x24208 = _precision_96620; /*int*/
    goto _match24209;
  }
  _x24208 = kk_integer_from_small(-17); /*int*/
  _match24209: ;
  _x24207 = kk_std_core_int32(_x24208, _ctx); /*int32*/
  return kk_std_core_show_expx(d, _x24207, _ctx);
}
 
// Show a string as a string literal


// lift anonymous function
struct kk_std_core_show_fun24221__t_3 {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_show_fun24221_3(kk_function_t _fself, kk_box_t _b_22331, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_show_fun24221_3(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_show_fun24221_3, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_core_show_fun24221_3(kk_function_t _fself, kk_box_t _b_22331, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x24222;
  kk_char_t _x24223 = kk_char_unbox(_b_22331, _ctx); /*char*/
  _x24222 = kk_std_core_show_char(_x24223, _ctx); /*string*/
  return kk_string_box(_x24222);
}

kk_string_t kk_std_core_show_3(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> string */ 
  kk_string_t _x24217;
  kk_define_string_literal(, _s24218, 1, "\"")
  _x24217 = kk_string_dup(_s24218); /*string*/
  kk_string_t _x24219;
  kk_string_t _x24220;
  kk_std_core__list xs_21467;
  kk_std_core__list _b_22332_22329 = kk_std_core_list_4(s, _ctx); /*list<char>*/;
  xs_21467 = kk_std_core_map_5(_b_22332_22329, kk_std_core_new_show_fun24221_3(_ctx), _ctx); /*list<string>*/
  if (kk_std_core__is_Nil(xs_21467)) {
    _x24220 = kk_string_empty(); /*string*/
  }
  else {
    struct kk_std_core_Cons* _con24225 = kk_std_core__as_Cons(xs_21467);
    kk_box_t _box_x22334 = _con24225->head;
    kk_std_core__list xx = _con24225->tail;
    kk_string_t x = kk_string_unbox(_box_x22334);
    if (kk_std_core__list_is_unique(xs_21467)) {
      kk_std_core__list_free(xs_21467);
    }
    else {
      kk_string_dup(x);
      kk_std_core__list_dup(xx);
      kk_std_core__list_decref(xs_21467, _ctx);
    }
    kk_string_t _x24227 = kk_string_empty(); /*string*/
    _x24220 = kk_std_core__lift21050_joinsep(_x24227, xx, x, _ctx); /*string*/
  }
  kk_string_t _x24229;
  kk_define_string_literal(, _s24230, 1, "\"")
  _x24229 = kk_string_dup(_s24230); /*string*/
  _x24219 = kk_std_core__lp__plus__plus__1_rp_(_x24220, _x24229, _ctx); /*string*/
  return kk_std_core__lp__plus__plus__1_rp_(_x24217, _x24219, _ctx);
}
extern kk_string_t kk_std_core_show_fun24235_7(kk_function_t _fself, kk_box_t _b_22337, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x24236 = kk_string_unbox(_b_22337); /*string*/
  return kk_std_core_show_3(_x24236, _ctx);
}
extern kk_string_t kk_std_core_show_fun24237_8(kk_function_t _fself, kk_box_t _b_22342, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_integer_t _x24238 = kk_integer_unbox(_b_22342); /*int*/
  return kk_std_core_show(_x24238, _ctx);
}
extern kk_string_t kk_std_core_show_fun24239_9(kk_function_t _fself, kk_box_t _b_22347, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  bool _x24240 = kk_bool_unbox(_b_22347); /*bool*/
  return kk_std_core_show_4(_x24240, _ctx);
}

kk_unit_t kk_std_core_prints(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> console () */ 
  kk_std_core_types__maybe _match_23552;
  kk_box_t _x24248;
  kk_ref_t _x24249 = kk_ref_dup(kk_std_core_redirect); /*ref<global,maybe<(string) -> console ()>>*/
  _x24248 = kk_ref_get(_x24249,kk_context()); /*179*/
  _match_23552 = kk_std_core_types__maybe_unbox(_x24248, _ctx); /*maybe<(string) -> console ()>*/
  if (kk_std_core_types__is_Nothing(_match_23552)) {
    kk_std_core_xprints(s, _ctx); return kk_Unit;
  }
  kk_box_t _fun_unbox_x22354 = _match_23552._cons.Just.value;
  kk_box_t _x24250;
  kk_function_t _x24251 = kk_function_unbox(_fun_unbox_x22354); /*(22355) -> console 22356*/
  _x24250 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x24251, (_x24251, kk_string_box(s), _ctx)); /*22356*/
  kk_unit_unbox(_x24250); return kk_Unit;
}


// lift anonymous function
struct kk_std_core__default_exn_fun24257__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core__default_exn_fun24257(kk_function_t _fself, kk_std_core_hnd__marker _b_22376, kk_std_core_hnd__ev _b_22377, kk_box_t _b_22378, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_default_exn_fun24257(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core__default_exn_fun24257, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_std_core__default_exn_fun24258__t {
  struct kk_function_s _base;
  kk_box_t _b_22378;
};
static kk_box_t kk_std_core__default_exn_fun24258(kk_function_t _fself, kk_function_t _b_22373, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_default_exn_fun24258(kk_box_t _b_22378, kk_context_t* _ctx) {
  struct kk_std_core__default_exn_fun24258__t* _self = kk_function_alloc_as(struct kk_std_core__default_exn_fun24258__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__default_exn_fun24258, kk_context());
  _self->_b_22378 = _b_22378;
  return &_self->_base;
}

static kk_box_t kk_std_core__default_exn_fun24258(kk_function_t _fself, kk_function_t _b_22373, kk_context_t* _ctx) {
  struct kk_std_core__default_exn_fun24258__t* _self = kk_function_as(struct kk_std_core__default_exn_fun24258__t*, _fself);
  kk_box_t _b_22378 = _self->_b_22378; /* 52 */
  kk_drop_match(_self, {kk_box_dup(_b_22378);}, {}, _ctx)
  kk_function_drop(_b_22373, _ctx);
  kk_unit_t _x24259 = kk_Unit;
  kk_unit_t __ = kk_Unit;
  kk_string_t _x24260;
  kk_define_string_literal(, _s24261, 20, "uncaught exception: ")
  _x24260 = kk_string_dup(_s24261); /*string*/
  kk_std_core_prints(_x24260, _ctx);
  kk_string_t _x24262;
  kk_std_core__exception _match_23550 = kk_std_core__exception_unbox(_b_22378, _ctx); /*exception*/;
  kk_string_t _x = _match_23550.message;
  kk_string_dup(_x);
  kk_std_core__exception_drop(_match_23550, _ctx);
  _x24262 = _x; /*string*/
  kk_std_core_printsln(_x24262, _ctx);
  return kk_unit_box(_x24259);
}
static kk_box_t kk_std_core__default_exn_fun24257(kk_function_t _fself, kk_std_core_hnd__marker _b_22376, kk_std_core_hnd__ev _b_22377, kk_box_t _b_22378, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core_hnd__ev_dropn(_b_22377, ((int32_t)3), _ctx);
  return kk_std_core_hnd_yield_to_final(_b_22376, kk_std_core__new_default_exn_fun24258(_b_22378, _ctx), _ctx);
}


// lift anonymous function
struct kk_std_core__default_exn_fun24264__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core__default_exn_fun24264(kk_function_t _fself, kk_box_t _b_22383, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_default_exn_fun24264(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core__default_exn_fun24264, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_core__default_exn_fun24264(kk_function_t _fself, kk_box_t _b_22383, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return _b_22383;
}


// lift anonymous function
struct kk_std_core__default_exn_fun24265__t {
  struct kk_function_s _base;
  kk_function_t action;
};
static kk_box_t kk_std_core__default_exn_fun24265(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_default_exn_fun24265(kk_function_t action, kk_context_t* _ctx) {
  struct kk_std_core__default_exn_fun24265__t* _self = kk_function_alloc_as(struct kk_std_core__default_exn_fun24265__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__default_exn_fun24265, kk_context());
  _self->action = action;
  return &_self->_base;
}

static kk_box_t kk_std_core__default_exn_fun24265(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_core__default_exn_fun24265__t* _self = kk_function_as(struct kk_std_core__default_exn_fun24265__t*, _fself);
  kk_function_t action = _self->action; /* () -> <exn,console|11881> () */
  kk_drop_match(_self, {kk_function_dup(action);}, {}, _ctx)
  kk_unit_t _x24266 = kk_Unit;
  kk_function_call(kk_unit_t, (kk_function_t, kk_context_t*), action, (action, _ctx));
  return kk_unit_box(_x24266);
}

kk_unit_t kk_std_core__default_exn(kk_function_t action, kk_context_t* _ctx) { /* forall<e> (action : () -> <console,exn|e> ()) -> <console|e> () */ 
  int32_t _b_22384_22379 = ((int32_t)0); /*int32*/;
  kk_std_core__hnd_exn _b_22385_22380;
  kk_std_core_hnd__clause1 _x24256 = kk_std_core_hnd__new_Clause1(kk_std_core__new_default_exn_fun24257(_ctx), _ctx); /*std/core/hnd/clause1<52,53,54,55,56>*/
  _b_22385_22380 = kk_std_core__new_Hnd_exn(kk_reuse_null, _x24256, _ctx); /*.hnd-exn<<console|11881>,()>*/
  kk_box_t _x24263 = kk_std_core__handle_exn(_b_22384_22379, _b_22385_22380, kk_std_core__new_default_exn_fun24264(_ctx), kk_std_core__new_default_exn_fun24265(action, _ctx), _ctx); /*1966*/
  kk_unit_unbox(_x24263); return kk_Unit;
}
 
// Get (zero-based) element `n`  of a list. Return a `:maybe` type.

kk_std_core_types__maybe kk_std_core__lp__lb__rb__2_rp_(kk_std_core__list xs, kk_integer_t n, kk_context_t* _ctx) { /* forall<a> (xs : list<a>, n : int) -> maybe<a> */ 
  kk__tailcall: ;
  if (kk_std_core__is_Cons(xs)) {
    struct kk_std_core_Cons* _con24267 = kk_std_core__as_Cons(xs);
    kk_box_t x = _con24267->head;
    kk_std_core__list xx = _con24267->tail;
    if (kk_std_core__list_is_unique(xs)) {
      kk_std_core__list_free(xs);
    }
    else {
      kk_box_dup(x);
      kk_std_core__list_dup(xx);
      kk_std_core__list_decref(xs, _ctx);
    }
    bool _match_23548;
    kk_integer_t _x24268 = kk_integer_dup(n); /*int*/
    _match_23548 = kk_integer_gt(_x24268,(kk_integer_from_small(0)),kk_context()); /*bool*/
    if (_match_23548) {
      kk_box_drop(x, _ctx);
      { // tailcall
        kk_integer_t _x24269 = kk_integer_sub(n,(kk_integer_from_small(1)),kk_context()); /*int*/
        xs = xx;
        n = _x24269;
        goto kk__tailcall;
      }
    }
    kk_std_core__list_drop(xx, _ctx);
    bool _match_23549 = kk_integer_eq(n,(kk_integer_from_small(0)),kk_context()); /*bool*/;
    if (_match_23549) {
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
  kk_string_t _x24272 = kk_string_dup(s); /*string*/
  size_t _x24273 = (start0 + len0); /*size_t*/
  size_t _x24274;
  size_t _x24275 = kk_string_len(s,kk_context()); /*size_t*/
  size_t _x24276 = (start0 + len0); /*size_t*/
  _x24274 = (_x24275 - _x24276); /*size_t*/
  return kk_std_core__new_Sslice(_x24272, _x24273, _x24274, _ctx);
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
struct kk_std_core_all_fun24280__t {
  struct kk_function_s _base;
  kk_function_t predicate0;
  kk_std_core__list xx0;
};
static kk_box_t kk_std_core_all_fun24280(kk_function_t _fself, kk_box_t _b_22397, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_all_fun24280(kk_function_t predicate0, kk_std_core__list xx0, kk_context_t* _ctx) {
  struct kk_std_core_all_fun24280__t* _self = kk_function_alloc_as(struct kk_std_core_all_fun24280__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_all_fun24280, kk_context());
  _self->predicate0 = predicate0;
  _self->xx0 = xx0;
  return &_self->_base;
}

static kk_box_t kk_std_core_all_fun24280(kk_function_t _fself, kk_box_t _b_22397, kk_context_t* _ctx) {
  struct kk_std_core_all_fun24280__t* _self = kk_function_as(struct kk_std_core_all_fun24280__t*, _fself);
  kk_function_t predicate0 = _self->predicate0; /* (12206) -> 12207 bool */
  kk_std_core__list xx0 = _self->xx0; /* list<12206> */
  kk_drop_match(_self, {kk_function_dup(predicate0);kk_std_core__list_dup(xx0);}, {}, _ctx)
  bool _x24281;
  bool _x24282 = kk_bool_unbox(_b_22397); /*bool*/
  _x24281 = kk_std_core__mlift21191_all(predicate0, xx0, _x24282, _ctx); /*bool*/
  return kk_bool_box(_x24281);
}

bool kk_std_core_all(kk_std_core__list xs, kk_function_t predicate0, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, predicate : (a) -> e bool) -> e bool */ 
  kk__tailcall: ;
  if (kk_std_core__is_Cons(xs)) {
    struct kk_std_core_Cons* _con24277 = kk_std_core__as_Cons(xs);
    kk_box_t x = _con24277->head;
    kk_std_core__list xx0 = _con24277->tail;
    if (kk_std_core__list_is_unique(xs)) {
      kk_std_core__list_free(xs);
    }
    else {
      kk_box_dup(x);
      kk_std_core__list_dup(xx0);
      kk_std_core__list_decref(xs, _ctx);
    }
    bool x0_21477;
    kk_function_t _x24278 = kk_function_dup(predicate0); /*(12206) -> 12207 bool*/
    x0_21477 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_context_t*), _x24278, (_x24278, x, _ctx)); /*bool*/
    if (kk_yielding(kk_context())) {
      kk_box_t _x24279 = kk_std_core_hnd_yield_extend(kk_std_core_new_all_fun24280(predicate0, xx0, _ctx), _ctx); /*3991*/
      return kk_bool_unbox(_x24279);
    }
    if (x0_21477) {
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
struct kk_std_core_any_fun24286__t {
  struct kk_function_s _base;
  kk_function_t predicate0;
  kk_std_core__list xx0;
};
static kk_box_t kk_std_core_any_fun24286(kk_function_t _fself, kk_box_t _b_22401, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_any_fun24286(kk_function_t predicate0, kk_std_core__list xx0, kk_context_t* _ctx) {
  struct kk_std_core_any_fun24286__t* _self = kk_function_alloc_as(struct kk_std_core_any_fun24286__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_any_fun24286, kk_context());
  _self->predicate0 = predicate0;
  _self->xx0 = xx0;
  return &_self->_base;
}

static kk_box_t kk_std_core_any_fun24286(kk_function_t _fself, kk_box_t _b_22401, kk_context_t* _ctx) {
  struct kk_std_core_any_fun24286__t* _self = kk_function_as(struct kk_std_core_any_fun24286__t*, _fself);
  kk_function_t predicate0 = _self->predicate0; /* (12234) -> 12235 bool */
  kk_std_core__list xx0 = _self->xx0; /* list<12234> */
  kk_drop_match(_self, {kk_function_dup(predicate0);kk_std_core__list_dup(xx0);}, {}, _ctx)
  bool _x24287;
  bool _x24288 = kk_bool_unbox(_b_22401); /*bool*/
  _x24287 = kk_std_core__mlift21192_any(predicate0, xx0, _x24288, _ctx); /*bool*/
  return kk_bool_box(_x24287);
}

bool kk_std_core_any(kk_std_core__list xs, kk_function_t predicate0, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, predicate : (a) -> e bool) -> e bool */ 
  kk__tailcall: ;
  if (kk_std_core__is_Cons(xs)) {
    struct kk_std_core_Cons* _con24283 = kk_std_core__as_Cons(xs);
    kk_box_t x = _con24283->head;
    kk_std_core__list xx0 = _con24283->tail;
    if (kk_std_core__list_is_unique(xs)) {
      kk_std_core__list_free(xs);
    }
    else {
      kk_box_dup(x);
      kk_std_core__list_dup(xx0);
      kk_std_core__list_decref(xs, _ctx);
    }
    bool x0_21481;
    kk_function_t _x24284 = kk_function_dup(predicate0); /*(12234) -> 12235 bool*/
    x0_21481 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_context_t*), _x24284, (_x24284, x, _ctx)); /*bool*/
    if (kk_yielding(kk_context())) {
      kk_box_t _x24285 = kk_std_core_hnd_yield_extend(kk_std_core_new_any_fun24286(predicate0, xx0, _ctx), _ctx); /*3991*/
      return kk_bool_unbox(_x24285);
    }
    if (x0_21481) {
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
  bool _match_23544;
  size_t _x24289;
  kk_vector_t _x24290 = kk_vector_dup(v); /*vector<12323>*/
  _x24289 = kk_vector_len(_x24290); /*size_t*/
  _match_23544 = (_x24289 <= idx); /*bool*/
  if (_match_23544) {
    kk_vector_drop(v, _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
  kk_box_t _x24291 = kk_vector_at(v,idx); /*216*/
  return kk_std_core_types__new_Just(_x24291, _ctx);
}
 
// O(`n`). The first `n` (default = `1`) characters in a string.

kk_std_core__sslice kk_std_core_first(kk_string_t s, kk_std_core_types__optional n, kk_context_t* _ctx) { /* (s : string, n : optional<int>) -> sslice */ 
  kk_std_core__sslice slice0 = kk_std_core_first1(s, _ctx); /*sslice*/;
  bool _match_23543;
  kk_integer_t _x24295;
  if (kk_std_core_types__is_Optional(n)) {
    kk_box_t _box_x22404 = n._cons.Optional.value;
    kk_integer_t _n_12425 = kk_integer_unbox(_box_x22404);
    kk_integer_dup(_n_12425);
    _x24295 = _n_12425; /*int*/
    goto _match24296;
  }
  _x24295 = kk_integer_from_small(1); /*int*/
  _match24296: ;
  _match_23543 = kk_integer_eq(_x24295,(kk_integer_from_small(1)),kk_context()); /*bool*/
  if (_match_23543) {
    kk_std_core_types__optional_drop(n, _ctx);
    return slice0;
  }
  kk_integer_t _x24298;
  kk_integer_t _x24299;
  if (kk_std_core_types__is_Optional(n)) {
    kk_box_t _box_x22405 = n._cons.Optional.value;
    kk_integer_t _n_124250 = kk_integer_unbox(_box_x22405);
    kk_integer_dup(_n_124250);
    kk_std_core_types__optional_drop(n, _ctx);
    _x24299 = _n_124250; /*int*/
    goto _match24300;
  }
  _x24299 = kk_integer_from_small(1); /*int*/
  _match24300: ;
  _x24298 = kk_integer_sub(_x24299,(kk_integer_from_small(1)),kk_context()); /*int*/
  return kk_std_core_extend(slice0, _x24298, _ctx);
}
 
// Convert the first character of a string to uppercase.

kk_string_t kk_std_core_capitalize(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> string */ 
  kk_string_t _x24302;
  kk_string_t _x24303;
  kk_std_core__sslice _x24304;
  kk_std_core__sslice slice0;
  kk_string_t _x24305 = kk_string_dup(s); /*string*/
  slice0 = kk_std_core_first1(_x24305, _ctx); /*sslice*/
  bool _match_23540;
  kk_integer_t _x24306;
  kk_std_core_types__optional _match_23542 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
  if (kk_std_core_types__is_Optional(_match_23542)) {
    kk_box_t _box_x22406 = _match_23542._cons.Optional.value;
    kk_integer_t _n_12425 = kk_integer_unbox(_box_x22406);
    kk_integer_dup(_n_12425);
    kk_std_core_types__optional_drop(_match_23542, _ctx);
    _x24306 = _n_12425; /*int*/
    goto _match24307;
  }
  _x24306 = kk_integer_from_small(1); /*int*/
  _match24307: ;
  _match_23540 = kk_integer_eq(_x24306,(kk_integer_from_small(1)),kk_context()); /*bool*/
  if (_match_23540) {
    _x24304 = slice0; /*sslice*/
  }
  else {
    kk_integer_t _x24309;
    kk_integer_t _x24310;
    kk_std_core_types__optional _match_23541 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
    if (kk_std_core_types__is_Optional(_match_23541)) {
      kk_box_t _box_x22407 = _match_23541._cons.Optional.value;
      kk_integer_t _n_124250 = kk_integer_unbox(_box_x22407);
      kk_integer_dup(_n_124250);
      kk_std_core_types__optional_drop(_match_23541, _ctx);
      _x24310 = _n_124250; /*int*/
      goto _match24311;
    }
    _x24310 = kk_integer_from_small(1); /*int*/
    _match24311: ;
    _x24309 = kk_integer_sub(_x24310,(kk_integer_from_small(1)),kk_context()); /*int*/
    _x24304 = kk_std_core_extend(slice0, _x24309, _ctx); /*sslice*/
  }
  _x24303 = kk_std_core_string_3(_x24304, _ctx); /*string*/
  _x24302 = kk_std_core_to_upper(_x24303, _ctx); /*string*/
  kk_string_t _x24313;
  kk_std_core__sslice _x24314;
  kk_std_core__sslice slice0_21487;
  kk_std_core__sslice slice1 = kk_std_core_first1(s, _ctx); /*sslice*/;
  bool _match_23537;
  kk_integer_t _x24315;
  kk_std_core_types__optional _match_23539 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
  if (kk_std_core_types__is_Optional(_match_23539)) {
    kk_box_t _box_x22408 = _match_23539._cons.Optional.value;
    kk_integer_t _n_124251 = kk_integer_unbox(_box_x22408);
    kk_integer_dup(_n_124251);
    kk_std_core_types__optional_drop(_match_23539, _ctx);
    _x24315 = _n_124251; /*int*/
    goto _match24316;
  }
  _x24315 = kk_integer_from_small(1); /*int*/
  _match24316: ;
  _match_23537 = kk_integer_eq(_x24315,(kk_integer_from_small(1)),kk_context()); /*bool*/
  if (_match_23537) {
    slice0_21487 = slice1; /*sslice*/
  }
  else {
    kk_integer_t _x24318;
    kk_integer_t _x24319;
    kk_std_core_types__optional _match_23538 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
    if (kk_std_core_types__is_Optional(_match_23538)) {
      kk_box_t _box_x22409 = _match_23538._cons.Optional.value;
      kk_integer_t _n_124252 = kk_integer_unbox(_box_x22409);
      kk_integer_dup(_n_124252);
      kk_std_core_types__optional_drop(_match_23538, _ctx);
      _x24319 = _n_124252; /*int*/
      goto _match24320;
    }
    _x24319 = kk_integer_from_small(1); /*int*/
    _match24320: ;
    _x24318 = kk_integer_sub(_x24319,(kk_integer_from_small(1)),kk_context()); /*int*/
    slice0_21487 = kk_std_core_extend(slice1, _x24318, _ctx); /*sslice*/
  }
  kk_string_t s1 = slice0_21487.str;
  size_t start0 = slice0_21487.start;
  size_t len0 = slice0_21487.len;
  kk_string_dup(s1);
  kk_std_core__sslice_drop(slice0_21487, _ctx);
  kk_string_t _x24322 = kk_string_dup(s1); /*string*/
  size_t _x24323 = (start0 + len0); /*size_t*/
  size_t _x24324;
  size_t _x24325 = kk_string_len(s1,kk_context()); /*size_t*/
  size_t _x24326 = (start0 + len0); /*size_t*/
  _x24324 = (_x24325 - _x24326); /*size_t*/
  _x24314 = kk_std_core__new_Sslice(_x24322, _x24323, _x24324, _ctx); /*sslice*/
  _x24313 = kk_std_core_string_3(_x24314, _ctx); /*string*/
  return kk_std_core__lp__plus__plus__1_rp_(_x24302, _x24313, _ctx);
}
 
// Catch any exception raised in `action` and handle it.
// Use `on-exn` or `on-exit` when appropiate.


// lift anonymous function
struct kk_std_core_try_fun24329__t {
  struct kk_function_s _base;
  kk_function_t hndl;
};
static kk_box_t kk_std_core_try_fun24329(kk_function_t _fself, kk_box_t _b_22411, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_try_fun24329(kk_function_t hndl, kk_context_t* _ctx) {
  struct kk_std_core_try_fun24329__t* _self = kk_function_alloc_as(struct kk_std_core_try_fun24329__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_try_fun24329, kk_context());
  _self->hndl = hndl;
  return &_self->_base;
}

static kk_box_t kk_std_core_try_fun24329(kk_function_t _fself, kk_box_t _b_22411, kk_context_t* _ctx) {
  struct kk_std_core_try_fun24329__t* _self = kk_function_as(struct kk_std_core_try_fun24329__t*, _fself);
  kk_function_t hndl = _self->hndl; /* (exception) -> 12648 12647 */
  kk_drop_match(_self, {kk_function_dup(hndl);}, {}, _ctx)
  kk_std_core__exception _x24330 = kk_std_core__exception_unbox(_b_22411, _ctx); /*exception*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_std_core__exception, kk_context_t*), hndl, (hndl, _x24330, _ctx));
}


// lift anonymous function
struct kk_std_core_try_fun24331__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_try_fun24331(kk_function_t _fself, kk_box_t _x, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_try_fun24331(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_try_fun24331, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_core_try_fun24331(kk_function_t _fself, kk_box_t _x, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return _x;
}

kk_box_t kk_std_core_try(kk_function_t action, kk_function_t hndl, kk_context_t* _ctx) { /* forall<a,e> (action : () -> <exn|e> a, hndl : (exception) -> e a) -> e a */ 
  kk_std_core__hnd_exn _x24327;
  kk_std_core_hnd__clause1 _x24328 = kk_std_core_hnd_clause_never1(kk_std_core_new_try_fun24329(hndl, _ctx), _ctx); /*std/core/hnd/clause1<7986,7987,7989,7988,7990>*/
  _x24327 = kk_std_core__new_Hnd_exn(kk_reuse_null, _x24328, _ctx); /*.hnd-exn<11,12>*/
  return kk_std_core__handle_exn(((int32_t)0), _x24327, kk_std_core_new_try_fun24331(_ctx), action, _ctx);
}
 
// monadic lift

kk_std_core__error kk_std_core__mlift21193_try_1(kk_box_t _y_87, kk_context_t* _ctx) { /* forall<a,e> (a) -> <exn|e> error<a> */ 
  return kk_std_core__new_Ok(_y_87, _ctx);
}
 
// Transform an exception effect to an  `:error` type.


// lift anonymous function
struct kk_std_core_try_fun24333__t_1 {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_try_fun24333_1(kk_function_t _fself, kk_std_core_hnd__marker _b_22418, kk_std_core_hnd__ev _b_22419, kk_box_t _b_22420, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_try_fun24333_1(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_try_fun24333_1, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_std_core_try_fun24334__t_1 {
  struct kk_function_s _base;
  kk_box_t _b_22420;
};
static kk_box_t kk_std_core_try_fun24334_1(kk_function_t _fself, kk_function_t _b_22415, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_try_fun24334_1(kk_box_t _b_22420, kk_context_t* _ctx) {
  struct kk_std_core_try_fun24334__t_1* _self = kk_function_alloc_as(struct kk_std_core_try_fun24334__t_1, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_try_fun24334_1, kk_context());
  _self->_b_22420 = _b_22420;
  return &_self->_base;
}

static kk_box_t kk_std_core_try_fun24334_1(kk_function_t _fself, kk_function_t _b_22415, kk_context_t* _ctx) {
  struct kk_std_core_try_fun24334__t_1* _self = kk_function_as(struct kk_std_core_try_fun24334__t_1*, _fself);
  kk_box_t _b_22420 = _self->_b_22420; /* 52 */
  kk_drop_match(_self, {kk_box_dup(_b_22420);}, {}, _ctx)
  kk_function_drop(_b_22415, _ctx);
  kk_std_core__error _x24335;
  kk_std_core__exception _x24336 = kk_std_core__exception_unbox(_b_22420, _ctx); /*exception*/
  _x24335 = kk_std_core__new_Error(_x24336, _ctx); /*error<30>*/
  return kk_std_core__error_box(_x24335, _ctx);
}
static kk_box_t kk_std_core_try_fun24333_1(kk_function_t _fself, kk_std_core_hnd__marker _b_22418, kk_std_core_hnd__ev _b_22419, kk_box_t _b_22420, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core_hnd__ev_dropn(_b_22419, ((int32_t)3), _ctx);
  return kk_std_core_hnd_yield_to_final(_b_22418, kk_std_core_new_try_fun24334_1(_b_22420, _ctx), _ctx);
}


// lift anonymous function
struct kk_std_core_try_fun24338__t_1 {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_try_fun24338_1(kk_function_t _fself, kk_box_t _b_22427, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_try_fun24338_1(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_try_fun24338_1, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_core_try_fun24338_1(kk_function_t _fself, kk_box_t _b_22427, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return _b_22427;
}


// lift anonymous function
struct kk_std_core_try_fun24339__t_1 {
  struct kk_function_s _base;
  kk_function_t action;
};
static kk_box_t kk_std_core_try_fun24339_1(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_try_fun24339_1(kk_function_t action, kk_context_t* _ctx) {
  struct kk_std_core_try_fun24339__t_1* _self = kk_function_alloc_as(struct kk_std_core_try_fun24339__t_1, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_try_fun24339_1, kk_context());
  _self->action = action;
  return &_self->_base;
}



// lift anonymous function
struct kk_std_core_try_fun24342__t_1 {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_try_fun24342_1(kk_function_t _fself, kk_box_t _b_22422, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_try_fun24342_1(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_try_fun24342_1, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_core_try_fun24342_1(kk_function_t _fself, kk_box_t _b_22422, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core__error _x24343 = kk_std_core__mlift21193_try_1(_b_22422, _ctx); /*error<12686>*/
  return kk_std_core__error_box(_x24343, _ctx);
}
static kk_box_t kk_std_core_try_fun24339_1(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_core_try_fun24339__t_1* _self = kk_function_as(struct kk_std_core_try_fun24339__t_1*, _fself);
  kk_function_t action = _self->action; /* () -> <exn|12687> 12686 */
  kk_drop_match(_self, {kk_function_dup(action);}, {}, _ctx)
  kk_std_core__error _x24340;
  kk_box_t x_21492 = kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), action, (action, _ctx)); /*12686*/;
  if (kk_yielding(kk_context())) {
    kk_box_drop(x_21492, _ctx);
    kk_box_t _x24341 = kk_std_core_hnd_yield_extend(kk_std_core_new_try_fun24342_1(_ctx), _ctx); /*3991*/
    _x24340 = kk_std_core__error_unbox(_x24341, _ctx); /*error<12686>*/
  }
  else {
    _x24340 = kk_std_core__mlift21193_try_1(x_21492, _ctx); /*error<12686>*/
  }
  return kk_std_core__error_box(_x24340, _ctx);
}

kk_std_core__error kk_std_core_try_1(kk_function_t action, kk_context_t* _ctx) { /* forall<a,e> (action : () -> <exn|e> a) -> e error<a> */ 
  int32_t _b_22428_22423 = ((int32_t)0); /*int32*/;
  kk_std_core__hnd_exn _b_22429_22424;
  kk_std_core_hnd__clause1 _x24332 = kk_std_core_hnd__new_Clause1(kk_std_core_new_try_fun24333_1(_ctx), _ctx); /*std/core/hnd/clause1<52,53,54,55,56>*/
  _b_22429_22424 = kk_std_core__new_Hnd_exn(kk_reuse_null, _x24332, _ctx); /*.hnd-exn<12687,error<12686>>*/
  kk_box_t _x24337 = kk_std_core__handle_exn(_b_22428_22423, _b_22429_22424, kk_std_core_new_try_fun24338_1(_ctx), kk_std_core_new_try_fun24339_1(action, _ctx), _ctx); /*1966*/
  return kk_std_core__error_unbox(_x24337, _ctx);
}

kk_std_core_types__tuple2_ kk_std_core_cdivmod_exp10(kk_integer_t i, kk_integer_t n, kk_context_t* _ctx) { /* (i : int, n : int) -> (int, int) */ 
  bool _match_23535;
  kk_integer_t _x24346 = kk_integer_dup(n); /*int*/
  _match_23535 = kk_integer_lte(_x24346,(kk_integer_from_small(0)),kk_context()); /*bool*/
  if (_match_23535) {
    kk_integer_drop(n, _ctx);
    return kk_std_core_types__new_dash__lp__comma__rp_(kk_integer_box(i), kk_integer_box(kk_integer_from_small(0)), _ctx);
  }
  kk_integer_t cq;
  kk_integer_t _x24347 = kk_integer_dup(i); /*int*/
  kk_integer_t _x24348 = kk_integer_dup(n); /*int*/
  cq = kk_std_core_cdiv_exp10(_x24347, _x24348, _ctx); /*int*/
  kk_integer_t cr;
  kk_integer_t _x24349;
  kk_integer_t _x24350 = kk_integer_dup(cq); /*int*/
  _x24349 = kk_std_core_mul_exp10(_x24350, n, _ctx); /*int*/
  cr = kk_integer_sub(i,_x24349,kk_context()); /*int*/
  return kk_std_core_types__new_dash__lp__comma__rp_(kk_integer_box(cq), kk_integer_box(cr), _ctx);
}
 
// Concatenate a list of `:maybe` values

kk_std_core__list kk_std_core__ctail_concat_maybe(kk_std_core__list xs, kk_std_core_types__ctail _acc, kk_context_t* _ctx) { /* forall<a> (xs : list<maybe<a>>, ctail<list<a>>) -> list<a> */ 
  kk__tailcall: ;
  if (kk_std_core__is_Cons(xs)) {
    struct kk_std_core_Cons* _con24351 = kk_std_core__as_Cons(xs);
    kk_box_t _box_x22450 = _con24351->head;
    kk_std_core__list xx = _con24351->tail;
    kk_std_core_types__maybe x = kk_std_core_types__maybe_unbox(_box_x22450, NULL);
    kk_reuse_t _ru_23355 = kk_reuse_null; /*reuse*/;
    if (kk_std_core__list_is_unique(xs)) {
      kk_std_core_types__maybe_dup(x);
      kk_box_drop(_box_x22450, _ctx);
      _ru_23355 = (kk_std_core__list_reuse(xs));
    }
    else {
      kk_std_core_types__maybe_dup(x);
      kk_std_core__list_dup(xx);
      kk_std_core__list_decref(xs, _ctx);
      _ru_23355 = kk_reuse_null;
    }
    if (kk_std_core_types__is_Just(x)) {
      kk_box_t y = x._cons.Just.value;
      kk_std_core__list _ctail_21129 = kk_std_core__list_hole(); /*list<12852>*/;
      kk_std_core__list _ctail_21130 = kk_std_core__new_Cons(_ru_23355, y, _ctail_21129, _ctx); /*list<12852>*/;
      { // tailcall
        kk_std_core_types__ctail _x24353;
        kk_box_t* field_21496 = (kk_box_t*)((&kk_std_core__as_Cons(_ctail_21130)->tail)); /*cfield<list<12852>>*/;
        if (kk_std_core_types__is_CTail(_acc)) {
          kk_box_t _box_x22457 = _acc._cons.CTail._field1;
          kk_box_t* last0 = _acc._cons.CTail._field2;
          kk_std_core__list head0 = kk_std_core__list_unbox(_box_x22457, NULL);
          kk_std_core__list_dup(head0);
          kk_std_core_types__ctail_drop(_acc, _ctx);
          kk_unit_t __ = kk_Unit;
          *(last0) = kk_std_core__list_box(_ctail_21130, _ctx);
          _x24353 = kk_std_core_types__new_CTail(kk_std_core__list_box(head0, _ctx), field_21496, _ctx); /*ctail<58>*/
          goto _match24354;
        }
        _x24353 = kk_std_core_types__new_CTail(kk_std_core__list_box(_ctail_21130, _ctx), field_21496, _ctx); /*ctail<58>*/
        _match24354: ;
        xs = xx;
        _acc = _x24353;
        goto kk__tailcall;
      }
    }
    kk_reuse_drop(_ru_23355, _ctx);
    { // tailcall
      xs = xx;
      goto kk__tailcall;
    }
  }
  if (kk_std_core_types__is_CTail(_acc)) {
    kk_box_t _box_x22466 = _acc._cons.CTail._field1;
    kk_box_t* last00 = _acc._cons.CTail._field2;
    kk_std_core__list head00 = kk_std_core__list_unbox(_box_x22466, NULL);
    kk_std_core__list_dup(head00);
    kk_std_core_types__ctail_drop(_acc, _ctx);
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
struct kk_std_core__lift21055_for_whilez_fun24359__t {
  struct kk_function_s _base;
  kk_function_t action0;
  size_t end0;
  size_t i0;
};
static kk_box_t kk_std_core__lift21055_for_whilez_fun24359(kk_function_t _fself, kk_box_t _b_22476, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_lift21055_for_whilez_fun24359(kk_function_t action0, size_t end0, size_t i0, kk_context_t* _ctx) {
  struct kk_std_core__lift21055_for_whilez_fun24359__t* _self = kk_function_alloc_as(struct kk_std_core__lift21055_for_whilez_fun24359__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__lift21055_for_whilez_fun24359, kk_context());
  _self->action0 = action0;
  _self->end0 = end0;
  _self->i0 = i0;
  return &_self->_base;
}

static kk_box_t kk_std_core__lift21055_for_whilez_fun24359(kk_function_t _fself, kk_box_t _b_22476, kk_context_t* _ctx) {
  struct kk_std_core__lift21055_for_whilez_fun24359__t* _self = kk_function_as(struct kk_std_core__lift21055_for_whilez_fun24359__t*, _fself);
  kk_function_t action0 = _self->action0; /* (size_t) -> 12854 maybe<12853> */
  size_t end0 = _self->end0; /* size_t */
  size_t i0 = _self->i0; /* size_t */
  kk_drop_match(_self, {kk_function_dup(action0);;;}, {}, _ctx)
  kk_std_core_types__maybe _x24360;
  kk_std_core_types__maybe _x24361 = kk_std_core_types__maybe_unbox(_b_22476, _ctx); /*maybe<12853>*/
  _x24360 = kk_std_core__mlift21194_op(action0, end0, i0, _x24361, _ctx); /*maybe<12853>*/
  return kk_std_core_types__maybe_box(_x24360, _ctx);
}

kk_std_core_types__maybe kk_std_core__lift21055_for_whilez(kk_function_t action0, size_t end0, size_t i0, kk_context_t* _ctx) { /* forall<a,e> (action : (size_t) -> e maybe<a>, end : size_t, i : size_t) -> e maybe<a> */ 
  kk__tailcall: ;
  bool _match_23533 = (i0 <= end0); /*bool*/;
  if (_match_23533) {
    kk_std_core_types__maybe x_21499;
    kk_function_t _x24357 = kk_function_dup(action0); /*(size_t) -> 12854 maybe<12853>*/
    x_21499 = kk_function_call(kk_std_core_types__maybe, (kk_function_t, size_t, kk_context_t*), _x24357, (_x24357, i0, _ctx)); /*maybe<12853>*/
    if (kk_yielding(kk_context())) {
      kk_std_core_types__maybe_drop(x_21499, _ctx);
      kk_box_t _x24358 = kk_std_core_hnd_yield_extend(kk_std_core__new_lift21055_for_whilez_fun24359(action0, end0, i0, _ctx), _ctx); /*3991*/
      return kk_std_core_types__maybe_unbox(_x24358, _ctx);
    }
    if (kk_std_core_types__is_Nothing(x_21499)) {
      size_t i0_210830 = kk_std_core_incr_1(i0, _ctx); /*size_t*/;
      { // tailcall
        i0 = i0_210830;
        goto kk__tailcall;
      }
    }
    kk_box_t x0 = x_21499._cons.Just.value;
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
struct kk_std_core_foreach_while_fun24368__t {
  struct kk_function_s _base;
  kk_function_t action0;
  kk_std_core__list xx0;
};
static kk_box_t kk_std_core_foreach_while_fun24368(kk_function_t _fself, kk_box_t _b_22480, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_foreach_while_fun24368(kk_function_t action0, kk_std_core__list xx0, kk_context_t* _ctx) {
  struct kk_std_core_foreach_while_fun24368__t* _self = kk_function_alloc_as(struct kk_std_core_foreach_while_fun24368__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_foreach_while_fun24368, kk_context());
  _self->action0 = action0;
  _self->xx0 = xx0;
  return &_self->_base;
}

static kk_box_t kk_std_core_foreach_while_fun24368(kk_function_t _fself, kk_box_t _b_22480, kk_context_t* _ctx) {
  struct kk_std_core_foreach_while_fun24368__t* _self = kk_function_as(struct kk_std_core_foreach_while_fun24368__t*, _fself);
  kk_function_t action0 = _self->action0; /* (13066) -> 13068 maybe<13067> */
  kk_std_core__list xx0 = _self->xx0; /* list<13066> */
  kk_drop_match(_self, {kk_function_dup(action0);kk_std_core__list_dup(xx0);}, {}, _ctx)
  kk_std_core_types__maybe _x24369;
  kk_std_core_types__maybe _x24370 = kk_std_core_types__maybe_unbox(_b_22480, _ctx); /*maybe<13067>*/
  _x24369 = kk_std_core__mlift21195_foreach_while(action0, xx0, _x24370, _ctx); /*maybe<13067>*/
  return kk_std_core_types__maybe_box(_x24369, _ctx);
}

kk_std_core_types__maybe kk_std_core_foreach_while(kk_std_core__list xs, kk_function_t action0, kk_context_t* _ctx) { /* forall<a,b,e> (xs : list<a>, action : (a) -> e maybe<b>) -> e maybe<b> */ 
  kk__tailcall: ;
  if (kk_std_core__is_Nil(xs)) {
    kk_function_drop(action0, _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
  struct kk_std_core_Cons* _con24365 = kk_std_core__as_Cons(xs);
  kk_box_t x = _con24365->head;
  kk_std_core__list xx0 = _con24365->tail;
  if (kk_std_core__list_is_unique(xs)) {
    kk_std_core__list_free(xs);
  }
  else {
    kk_box_dup(x);
    kk_std_core__list_dup(xx0);
    kk_std_core__list_decref(xs, _ctx);
  }
  kk_std_core_types__maybe x0_21503;
  kk_function_t _x24366 = kk_function_dup(action0); /*(13066) -> 13068 maybe<13067>*/
  x0_21503 = kk_function_call(kk_std_core_types__maybe, (kk_function_t, kk_box_t, kk_context_t*), _x24366, (_x24366, x, _ctx)); /*maybe<13067>*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__maybe_drop(x0_21503, _ctx);
    kk_box_t _x24367 = kk_std_core_hnd_yield_extend(kk_std_core_new_foreach_while_fun24368(action0, xx0, _ctx), _ctx); /*3991*/
    return kk_std_core_types__maybe_unbox(_x24367, _ctx);
  }
  if (kk_std_core_types__is_Nothing(x0_21503)) {
    { // tailcall
      xs = xx0;
      goto kk__tailcall;
    }
  }
  kk_function_drop(action0, _ctx);
  kk_std_core__list_drop(xx0, _ctx);
  return x0_21503;
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
struct kk_std_core_foreach_while_fun24376__t_1 {
  struct kk_function_s _base;
  kk_function_t action0;
  kk_std_core__sslice rest0;
};
static kk_box_t kk_std_core_foreach_while_fun24376_1(kk_function_t _fself, kk_box_t _b_22487, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_foreach_while_fun24376_1(kk_function_t action0, kk_std_core__sslice rest0, kk_context_t* _ctx) {
  struct kk_std_core_foreach_while_fun24376__t_1* _self = kk_function_alloc_as(struct kk_std_core_foreach_while_fun24376__t_1, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_foreach_while_fun24376_1, kk_context());
  _self->action0 = action0;
  _self->rest0 = rest0;
  return &_self->_base;
}

static kk_box_t kk_std_core_foreach_while_fun24376_1(kk_function_t _fself, kk_box_t _b_22487, kk_context_t* _ctx) {
  struct kk_std_core_foreach_while_fun24376__t_1* _self = kk_function_as(struct kk_std_core_foreach_while_fun24376__t_1*, _fself);
  kk_function_t action0 = _self->action0; /* (c : char) -> 13155 maybe<13154> */
  kk_std_core__sslice rest0 = _self->rest0; /* sslice */
  kk_drop_match(_self, {kk_function_dup(action0);kk_std_core__sslice_dup(rest0);}, {}, _ctx)
  kk_std_core_types__maybe _x24377;
  kk_std_core_types__maybe _x24378 = kk_std_core_types__maybe_unbox(_b_22487, _ctx); /*maybe<13154>*/
  _x24377 = kk_std_core__mlift21196_foreach_while_1(action0, rest0, _x24378, _ctx); /*maybe<13154>*/
  return kk_std_core_types__maybe_box(_x24377, _ctx);
}

kk_std_core_types__maybe kk_std_core_foreach_while_1(kk_std_core__sslice slice0, kk_function_t action0, kk_context_t* _ctx) { /* forall<a,e> (slice : sslice, action : (c : char) -> e maybe<a>) -> e maybe<a> */ 
  kk__tailcall: ;
  kk_std_core_types__maybe _match_23530 = kk_std_core_next(slice0, _ctx); /*maybe<(char, sslice)>*/;
  if (kk_std_core_types__is_Nothing(_match_23530)) {
    kk_function_drop(action0, _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
  kk_box_t _box_x22483 = _match_23530._cons.Just.value;
  kk_std_core_types__tuple2_ _pat1 = kk_std_core_types__tuple2__unbox(_box_x22483, NULL);
  kk_box_t _box_x22484 = _pat1.fst;
  kk_box_t _box_x22485 = _pat1.snd;
  kk_char_t c = kk_char_unbox(_box_x22484, NULL);
  kk_std_core__sslice rest0 = kk_std_core__sslice_unbox(_box_x22485, NULL);
  kk_std_core__sslice_dup(rest0);
  kk_std_core_types__maybe_drop(_match_23530, _ctx);
  kk_std_core_types__maybe x_21507;
  kk_function_t _x24374 = kk_function_dup(action0); /*(c : char) -> 13155 maybe<13154>*/
  x_21507 = kk_function_call(kk_std_core_types__maybe, (kk_function_t, kk_char_t, kk_context_t*), _x24374, (_x24374, c, _ctx)); /*maybe<13154>*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__maybe_drop(x_21507, _ctx);
    kk_box_t _x24375 = kk_std_core_hnd_yield_extend(kk_std_core_new_foreach_while_fun24376_1(action0, rest0, _ctx), _ctx); /*3991*/
    return kk_std_core_types__maybe_unbox(_x24375, _ctx);
  }
  if (kk_std_core_types__is_Nothing(x_21507)) {
    { // tailcall
      slice0 = rest0;
      goto kk__tailcall;
    }
  }
  kk_function_drop(action0, _ctx);
  kk_std_core__sslice_drop(rest0, _ctx);
  return x_21507;
}
 
// Invoke a function `f` for each element in a vector `v`.
// If `f` returns `Just`, the iteration is stopped early and the result is returned.


// lift anonymous function
struct kk_std_core_foreach_while_fun24382__t_3 {
  struct kk_function_s _base;
  kk_function_t f;
  kk_vector_t v;
};
static kk_std_core_types__maybe kk_std_core_foreach_while_fun24382_3(kk_function_t _fself, size_t i, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_foreach_while_fun24382_3(kk_function_t f, kk_vector_t v, kk_context_t* _ctx) {
  struct kk_std_core_foreach_while_fun24382__t_3* _self = kk_function_alloc_as(struct kk_std_core_foreach_while_fun24382__t_3, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_foreach_while_fun24382_3, kk_context());
  _self->f = f;
  _self->v = v;
  return &_self->_base;
}

static kk_std_core_types__maybe kk_std_core_foreach_while_fun24382_3(kk_function_t _fself, size_t i, kk_context_t* _ctx) {
  struct kk_std_core_foreach_while_fun24382__t_3* _self = kk_function_as(struct kk_std_core_foreach_while_fun24382__t_3*, _fself);
  kk_function_t f = _self->f; /* (13257) -> 13259 maybe<13258> */
  kk_vector_t v = _self->v; /* vector<13257> */
  kk_drop_match(_self, {kk_function_dup(f);kk_vector_dup(v);}, {}, _ctx)
  kk_box_t _x24383 = kk_vector_at(v,i); /*216*/
  return kk_function_call(kk_std_core_types__maybe, (kk_function_t, kk_box_t, kk_context_t*), f, (f, _x24383, _ctx));
}

kk_std_core_types__maybe kk_std_core_foreach_while_3(kk_vector_t v, kk_function_t f, kk_context_t* _ctx) { /* forall<a,b,e> (v : vector<a>, f : (a) -> e maybe<b>) -> e maybe<b> */ 
  size_t start_21511 = ((size_t)0); /*size_t*/;
  size_t end_21512;
  size_t _x24380;
  kk_vector_t _x24381 = kk_vector_dup(v); /*vector<13257>*/
  _x24380 = kk_vector_len(_x24381); /*size_t*/
  end_21512 = kk_std_core_decr_1(_x24380, _ctx); /*size_t*/
  return kk_std_core__lift21055_for_whilez(kk_std_core_new_foreach_while_fun24382_3(f, v, _ctx), end_21512, start_21511, _ctx);
}
 
// monadic lift

kk_unit_t kk_std_core__mlift21197_foreach(kk_function_t action, kk_std_core__list xx, kk_unit_t wild__, kk_context_t* _ctx) { /* forall<a,e> (action : (a) -> e (), xx : list<a>, wild_ : ()) -> e () */ 
  kk_std_core_foreach(xx, action, _ctx); return kk_Unit;
}
 
// Invoke `action` for each element of a list


// lift anonymous function
struct kk_std_core_foreach_fun24387__t {
  struct kk_function_s _base;
  kk_function_t action0;
  kk_std_core__list xx0;
};
static kk_box_t kk_std_core_foreach_fun24387(kk_function_t _fself, kk_box_t _b_22491, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_foreach_fun24387(kk_function_t action0, kk_std_core__list xx0, kk_context_t* _ctx) {
  struct kk_std_core_foreach_fun24387__t* _self = kk_function_alloc_as(struct kk_std_core_foreach_fun24387__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_foreach_fun24387, kk_context());
  _self->action0 = action0;
  _self->xx0 = xx0;
  return &_self->_base;
}

static kk_box_t kk_std_core_foreach_fun24387(kk_function_t _fself, kk_box_t _b_22491, kk_context_t* _ctx) {
  struct kk_std_core_foreach_fun24387__t* _self = kk_function_as(struct kk_std_core_foreach_fun24387__t*, _fself);
  kk_function_t action0 = _self->action0; /* (13452) -> 13453 () */
  kk_std_core__list xx0 = _self->xx0; /* list<13452> */
  kk_drop_match(_self, {kk_function_dup(action0);kk_std_core__list_dup(xx0);}, {}, _ctx)
  kk_unit_t _x24388 = kk_Unit;
  kk_unit_t _x24389 = kk_Unit;
  kk_unit_unbox(_b_22491);
  kk_std_core__mlift21197_foreach(action0, xx0, _x24389, _ctx);
  return kk_unit_box(_x24388);
}

kk_unit_t kk_std_core_foreach(kk_std_core__list xs, kk_function_t action0, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, action : (a) -> e ()) -> e () */ 
  kk__tailcall: ;
  if (kk_std_core__is_Nil(xs)) {
    kk_function_drop(action0, _ctx);
    kk_Unit; return kk_Unit;
  }
  struct kk_std_core_Cons* _con24384 = kk_std_core__as_Cons(xs);
  kk_box_t x = _con24384->head;
  kk_std_core__list xx0 = _con24384->tail;
  if (kk_std_core__list_is_unique(xs)) {
    kk_std_core__list_free(xs);
  }
  else {
    kk_box_dup(x);
    kk_std_core__list_dup(xx0);
    kk_std_core__list_decref(xs, _ctx);
  }
  kk_unit_t x0_21514 = kk_Unit;
  kk_function_t _x24385 = kk_function_dup(action0); /*(13452) -> 13453 ()*/
  kk_function_call(kk_unit_t, (kk_function_t, kk_box_t, kk_context_t*), _x24385, (_x24385, x, _ctx));
  if (kk_yielding(kk_context())) {
    kk_box_t _x24386 = kk_std_core_hnd_yield_extend(kk_std_core_new_foreach_fun24387(action0, xx0, _ctx), _ctx); /*3991*/
    kk_unit_unbox(_x24386); return kk_Unit;
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
struct kk_std_core_foreach_fun24390__t_1 {
  struct kk_function_s _base;
  kk_function_t action;
};
static kk_std_core_types__maybe kk_std_core_foreach_fun24390_1(kk_function_t _fself, kk_char_t c, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_foreach_fun24390_1(kk_function_t action, kk_context_t* _ctx) {
  struct kk_std_core_foreach_fun24390__t_1* _self = kk_function_alloc_as(struct kk_std_core_foreach_fun24390__t_1, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_foreach_fun24390_1, kk_context());
  _self->action = action;
  return &_self->_base;
}



// lift anonymous function
struct kk_std_core_foreach_fun24392__t_1 {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_foreach_fun24392_1(kk_function_t _fself, kk_box_t _b_22495, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_foreach_fun24392_1(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_foreach_fun24392_1, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_core_foreach_fun24392_1(kk_function_t _fself, kk_box_t _b_22495, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core_types__maybe _x24393;
  kk_unit_t _x24394 = kk_Unit;
  kk_unit_unbox(_b_22495);
  _x24393 = kk_std_core__mlift21198_foreach_1(_x24394, _ctx); /*maybe<_13498>*/
  return kk_std_core_types__maybe_box(_x24393, _ctx);
}
static kk_std_core_types__maybe kk_std_core_foreach_fun24390_1(kk_function_t _fself, kk_char_t c, kk_context_t* _ctx) {
  struct kk_std_core_foreach_fun24390__t_1* _self = kk_function_as(struct kk_std_core_foreach_fun24390__t_1*, _fself);
  kk_function_t action = _self->action; /* (c : char) -> 13511 () */
  kk_drop_match(_self, {kk_function_dup(action);}, {}, _ctx)
  kk_unit_t x0_21521 = kk_Unit;
  kk_function_call(kk_unit_t, (kk_function_t, kk_char_t, kk_context_t*), action, (action, c, _ctx));
  if (kk_yielding(kk_context())) {
    kk_box_t _x24391 = kk_std_core_hnd_yield_extend(kk_std_core_new_foreach_fun24392_1(_ctx), _ctx); /*3991*/
    return kk_std_core_types__maybe_unbox(_x24391, _ctx);
  }
  return kk_std_core__mlift21198_foreach_1(x0_21521, _ctx);
}


// lift anonymous function
struct kk_std_core_foreach_fun24396__t_1 {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_foreach_fun24396_1(kk_function_t _fself, kk_box_t _b_22499, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_foreach_fun24396_1(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_foreach_fun24396_1, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_core_foreach_fun24396_1(kk_function_t _fself, kk_box_t _b_22499, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_unit_t _x24397 = kk_Unit;
  kk_std_core_types__maybe _x24398 = kk_std_core_types__maybe_unbox(_b_22499, _ctx); /*maybe<_13498>*/
  kk_std_core__mlift21199_foreach_1(_x24398, _ctx);
  return kk_unit_box(_x24397);
}

kk_unit_t kk_std_core_foreach_1(kk_std_core__sslice slice0, kk_function_t action, kk_context_t* _ctx) { /* forall<e> (slice : sslice, action : (c : char) -> e ()) -> e () */ 
  kk_std_core_types__maybe x_21518 = kk_std_core_foreach_while_1(slice0, kk_std_core_new_foreach_fun24390_1(action, _ctx), _ctx); /*maybe<_13498>*/;
  kk_std_core_types__maybe_drop(x_21518, _ctx);
  if (kk_yielding(kk_context())) {
    kk_box_t _x24395 = kk_std_core_hnd_yield_extend(kk_std_core_new_foreach_fun24396_1(_ctx), _ctx); /*3991*/
    kk_unit_unbox(_x24395); return kk_Unit;
  }
  kk_Unit; return kk_Unit;
}
 
// Invoke a function for each character in a string


// lift anonymous function
struct kk_std_core_foreach_fun24399__t_2 {
  struct kk_function_s _base;
  kk_function_t action;
};
static kk_std_core_types__maybe kk_std_core_foreach_fun24399_2(kk_function_t _fself, kk_char_t c, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_foreach_fun24399_2(kk_function_t action, kk_context_t* _ctx) {
  struct kk_std_core_foreach_fun24399__t_2* _self = kk_function_alloc_as(struct kk_std_core_foreach_fun24399__t_2, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_foreach_fun24399_2, kk_context());
  _self->action = action;
  return &_self->_base;
}



// lift anonymous function
struct kk_std_core_foreach_fun24401__t_2 {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_foreach_fun24401_2(kk_function_t _fself, kk_box_t _b_22503, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_foreach_fun24401_2(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_foreach_fun24401_2, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_core_foreach_fun24401_2(kk_function_t _fself, kk_box_t _b_22503, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core_types__maybe _x24402;
  kk_unit_t _x24403 = kk_Unit;
  kk_unit_unbox(_b_22503);
  _x24402 = kk_std_core__mlift21198_foreach_1(_x24403, _ctx); /*maybe<_13498>*/
  return kk_std_core_types__maybe_box(_x24402, _ctx);
}
static kk_std_core_types__maybe kk_std_core_foreach_fun24399_2(kk_function_t _fself, kk_char_t c, kk_context_t* _ctx) {
  struct kk_std_core_foreach_fun24399__t_2* _self = kk_function_as(struct kk_std_core_foreach_fun24399__t_2*, _fself);
  kk_function_t action = _self->action; /* (c : char) -> 13550 () */
  kk_drop_match(_self, {kk_function_dup(action);}, {}, _ctx)
  kk_unit_t x0_21529 = kk_Unit;
  kk_function_call(kk_unit_t, (kk_function_t, kk_char_t, kk_context_t*), action, (action, c, _ctx));
  if (kk_yielding(kk_context())) {
    kk_box_t _x24400 = kk_std_core_hnd_yield_extend(kk_std_core_new_foreach_fun24401_2(_ctx), _ctx); /*3991*/
    return kk_std_core_types__maybe_unbox(_x24400, _ctx);
  }
  return kk_std_core__mlift21198_foreach_1(x0_21529, _ctx);
}


// lift anonymous function
struct kk_std_core_foreach_fun24405__t_2 {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_foreach_fun24405_2(kk_function_t _fself, kk_box_t _b_22507, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_foreach_fun24405_2(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_foreach_fun24405_2, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_core_foreach_fun24405_2(kk_function_t _fself, kk_box_t _b_22507, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_unit_t _x24406 = kk_Unit;
  kk_std_core_types__maybe _x24407 = kk_std_core_types__maybe_unbox(_b_22507, _ctx); /*maybe<_13498>*/
  kk_std_core__mlift21199_foreach_1(_x24407, _ctx);
  return kk_unit_box(_x24406);
}

kk_unit_t kk_std_core_foreach_2(kk_string_t s, kk_function_t action, kk_context_t* _ctx) { /* forall<e> (s : string, action : (c : char) -> e ()) -> e () */ 
  kk_std_core__sslice slice_21524 = kk_std_core_slice(s, _ctx); /*sslice*/;
  kk_std_core_types__maybe x_21526 = kk_std_core_foreach_while_1(slice_21524, kk_std_core_new_foreach_fun24399_2(action, _ctx), _ctx); /*maybe<_13498>*/;
  kk_std_core_types__maybe_drop(x_21526, _ctx);
  if (kk_yielding(kk_context())) {
    kk_box_t _x24404 = kk_std_core_hnd_yield_extend(kk_std_core_new_foreach_fun24405_2(_ctx), _ctx); /*3991*/
    kk_unit_unbox(_x24404); return kk_Unit;
  }
  kk_Unit; return kk_Unit;
}
 
// Invoke a function `f` for each element in a vector `v`


// lift anonymous function
struct kk_std_core_foreach_fun24410__t_3 {
  struct kk_function_s _base;
  kk_function_t f;
  kk_vector_t v;
};
static kk_unit_t kk_std_core_foreach_fun24410_3(kk_function_t _fself, size_t i, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_foreach_fun24410_3(kk_function_t f, kk_vector_t v, kk_context_t* _ctx) {
  struct kk_std_core_foreach_fun24410__t_3* _self = kk_function_alloc_as(struct kk_std_core_foreach_fun24410__t_3, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_foreach_fun24410_3, kk_context());
  _self->f = f;
  _self->v = v;
  return &_self->_base;
}

static kk_unit_t kk_std_core_foreach_fun24410_3(kk_function_t _fself, size_t i, kk_context_t* _ctx) {
  struct kk_std_core_foreach_fun24410__t_3* _self = kk_function_as(struct kk_std_core_foreach_fun24410__t_3*, _fself);
  kk_function_t f = _self->f; /* (13565) -> 13566 () */
  kk_vector_t v = _self->v; /* vector<13565> */
  kk_drop_match(_self, {kk_function_dup(f);kk_vector_dup(v);}, {}, _ctx)
  kk_box_t x_21537 = kk_vector_at(v,i); /*13565*/;
  return kk_function_call(kk_unit_t, (kk_function_t, kk_box_t, kk_context_t*), f, (f, x_21537, _ctx));
}

kk_unit_t kk_std_core_foreach_3(kk_vector_t v, kk_function_t f, kk_context_t* _ctx) { /* forall<a,e> (v : vector<a>, f : (a) -> e ()) -> e () */ 
  size_t start_21534 = ((size_t)0); /*size_t*/;
  size_t end_21535;
  size_t _x24408;
  kk_vector_t _x24409 = kk_vector_dup(v); /*vector<13565>*/
  _x24408 = kk_vector_len(_x24409); /*size_t*/
  end_21535 = kk_std_core_decr_1(_x24408, _ctx); /*size_t*/
  kk_std_core__lift21051_forz(kk_std_core_new_foreach_fun24410_3(f, v, _ctx), end_21535, start_21534, _ctx); return kk_Unit;
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
struct kk_std_core_count_fun24412__t_3 {
  struct kk_function_s _base;
  kk_ref_t loc;
  kk_function_t pred;
};
static kk_std_core_types__maybe kk_std_core_count_fun24412_3(kk_function_t _fself, kk_char_t c, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_count_fun24412_3(kk_ref_t loc, kk_function_t pred, kk_context_t* _ctx) {
  struct kk_std_core_count_fun24412__t_3* _self = kk_function_alloc_as(struct kk_std_core_count_fun24412__t_3, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_count_fun24412_3, kk_context());
  _self->loc = loc;
  _self->pred = pred;
  return &_self->_base;
}



// lift anonymous function
struct kk_std_core_count_fun24417__t_3 {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_count_fun24417_3(kk_function_t _fself, kk_box_t _b_22519, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_count_fun24417_3(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_count_fun24417_3, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_core_count_fun24417_3(kk_function_t _fself, kk_box_t _b_22519, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core_types__maybe _x24418;
  kk_unit_t _x24419 = kk_Unit;
  kk_unit_unbox(_b_22519);
  _x24418 = kk_std_core__mlift21198_foreach_1(_x24419, _ctx); /*maybe<_13498>*/
  return kk_std_core_types__maybe_box(_x24418, _ctx);
}
static kk_std_core_types__maybe kk_std_core_count_fun24412_3(kk_function_t _fself, kk_char_t c, kk_context_t* _ctx) {
  struct kk_std_core_count_fun24412__t_3* _self = kk_function_as(struct kk_std_core_count_fun24412__t_3*, _fself);
  kk_ref_t loc = _self->loc; /* local-var<global,int> */
  kk_function_t pred = _self->pred; /* (char) -> bool */
  kk_drop_match(_self, {kk_ref_dup(loc);kk_function_dup(pred);}, {}, _ctx)
  kk_unit_t x0_21550 = kk_Unit;
  bool _match_23524 = kk_function_call(bool, (kk_function_t, kk_char_t, kk_context_t*), pred, (pred, c, _ctx)); /*bool*/;
  if (_match_23524) {
    kk_integer_t _b_22516_22514;
    kk_integer_t _x24413;
    kk_box_t _x24414;
    kk_ref_t _x24415 = kk_ref_dup(loc); /*local-var<global,int>*/
    _x24414 = (kk_ref_get(_x24415,kk_context())); /*228*/
    _x24413 = kk_integer_unbox(_x24414); /*int*/
    _b_22516_22514 = kk_integer_add(_x24413,(kk_integer_from_small(1)),kk_context()); /*int*/
    (kk_ref_set(loc,(kk_integer_box(_b_22516_22514)),kk_context()));
  }
  else {
    kk_ref_drop(loc, _ctx);
    kk_Unit;
  }
  if (kk_yielding(kk_context())) {
    kk_box_t _x24416 = kk_std_core_hnd_yield_extend(kk_std_core_new_count_fun24417_3(_ctx), _ctx); /*3991*/
    return kk_std_core_types__maybe_unbox(_x24416, _ctx);
  }
  return kk_std_core__mlift21198_foreach_1(x0_21550, _ctx);
}


// lift anonymous function
struct kk_std_core_count_fun24421__t_3 {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_count_fun24421_3(kk_function_t _fself, kk_box_t _b_22523, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_count_fun24421_3(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_count_fun24421_3, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_core_count_fun24421_3(kk_function_t _fself, kk_box_t _b_22523, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_unit_t _x24422 = kk_Unit;
  kk_std_core_types__maybe _x24423 = kk_std_core_types__maybe_unbox(_b_22523, _ctx); /*maybe<_13498>*/
  kk_std_core__mlift21199_foreach_1(_x24423, _ctx);
  return kk_unit_box(_x24422);
}

kk_integer_t kk_std_core_count_3(kk_string_t s, kk_function_t pred, kk_context_t* _ctx) { /* (s : string, pred : (char) -> bool) -> int */ 
  kk_ref_t loc = kk_ref_alloc((kk_integer_box(kk_integer_from_small(0))),kk_context()); /*local-var<global,int>*/;
  kk_integer_t res;
  kk_unit_t __ = kk_Unit;
  kk_std_core__sslice slice_21545 = kk_std_core_slice(s, _ctx); /*sslice*/;
  kk_std_core_types__maybe x_21547;
  kk_function_t _x24411;
  kk_ref_dup(loc);
  _x24411 = kk_std_core_new_count_fun24412_3(loc, pred, _ctx); /*(c : char) -> (local<global>) maybe<_13498>*/
  x_21547 = kk_std_core_foreach_while_1(slice_21545, _x24411, _ctx); /*maybe<_13498>*/
  kk_std_core_types__maybe_drop(x_21547, _ctx);
  if (kk_yielding(kk_context())) {
    kk_box_t _x24420 = kk_std_core_hnd_yield_extend(kk_std_core_new_count_fun24421_3(_ctx), _ctx); /*3991*/
    kk_unit_unbox(_x24420);
  }
  else {
    kk_Unit;
  }
  kk_box_t _x24424;
  kk_ref_t _x24425 = kk_ref_dup(loc); /*local-var<global,int>*/
  _x24424 = (kk_ref_get(_x24425,kk_context())); /*228*/
  res = kk_integer_unbox(_x24424); /*int*/
  kk_box_t _x24426 = kk_std_core_hnd_prompt_local_var(loc, kk_integer_box(res), _ctx); /*9788*/
  return kk_integer_unbox(_x24426);
}
 
// Is the integer negative (stricly smaller than zero)

bool kk_std_core_is_neg_2(kk_integer_t i, kk_context_t* _ctx) { /* (i : int) -> bool */ 
  kk_std_core_types__order x_21555 = kk_int_as_order(kk_integer_signum(i,kk_context()),kk_context()); /*order*/;
  kk_integer_t _x24428 = kk_std_core_int_5(x_21555, _ctx); /*int*/
  kk_integer_t _x24429;
  kk_std_core_types__order _x24430 = kk_std_core_types__new_Lt(_ctx); /*order*/
  if (kk_std_core_types__is_Lt(_x24430)) {
    _x24429 = kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context()); /*int*/
    goto _match24431;
  }
  if (kk_std_core_types__is_Eq(_x24430)) {
    _x24429 = kk_integer_from_small(0); /*int*/
    goto _match24431;
  }
  _x24429 = kk_integer_from_small(1); /*int*/
  _match24431: ;
  return kk_integer_eq(_x24428,_x24429,kk_context());
}

kk_std_core_types__tuple2_ kk_std_core_divmod_exp10(kk_integer_t i, kk_integer_t n, kk_context_t* _ctx) { /* (i : int, n : int) -> (int, int) */ 
  kk_std_core_types__tuple2_ _match_23519;
  kk_integer_t _x24432 = kk_integer_dup(n); /*int*/
  _match_23519 = kk_std_core_cdivmod_exp10(i, _x24432, _ctx); /*(int, int)*/
  kk_box_t _box_x22537 = _match_23519.fst;
  kk_box_t _box_x22538 = _match_23519.snd;
  kk_integer_t cq = kk_integer_unbox(_box_x22537);
  kk_integer_t cr = kk_integer_unbox(_box_x22538);
  kk_integer_dup(cq);
  kk_integer_dup(cr);
  kk_std_core_types__tuple2__drop(_match_23519, _ctx);
  bool _match_23520;
  bool _x24435;
  kk_integer_t _x24436 = kk_integer_dup(cr); /*int*/
  _x24435 = kk_std_core_is_neg_2(_x24436, _ctx); /*bool*/
  _match_23520 = !(_x24435); /*bool*/
  if (_match_23520) {
    kk_integer_drop(n, _ctx);
    return kk_std_core_types__new_dash__lp__comma__rp_(kk_integer_box(cq), kk_integer_box(cr), _ctx);
  }
  kk_integer_t _b_22545_22541 = kk_std_core_dec(cq, _ctx); /*int*/;
  kk_integer_t _b_22546_22542;
  kk_integer_t _x24437 = kk_std_core_exp10(n, _ctx); /*int*/
  _b_22546_22542 = kk_integer_add(cr,_x24437,kk_context()); /*int*/
  return kk_std_core_types__new_dash__lp__comma__rp_(kk_integer_box(_b_22545_22541), kk_integer_box(_b_22546_22542), _ctx);
}
 
// Drop the first `n` elements of a list (or fewer if the list is shorter than `n`)

kk_std_core__list kk_std_core_drop(kk_std_core__list xs, kk_integer_t n, kk_context_t* _ctx) { /* forall<a> (xs : list<a>, n : int) -> list<a> */ 
  kk__tailcall: ;
  if (kk_std_core__is_Cons(xs)) {
    struct kk_std_core_Cons* _con24438 = kk_std_core__as_Cons(xs);
    kk_box_t _pat0 = _con24438->head;
    kk_std_core__list xx = _con24438->tail;
    kk_integer_t _x24439 = kk_integer_dup(n); /*int*/
    if (kk_integer_gt(_x24439,(kk_integer_from_small(0)),kk_context())) {
      if (kk_std_core__list_is_unique(xs)) {
        kk_box_drop(_pat0, _ctx);
        kk_std_core__list_free(xs);
      }
      else {
        kk_std_core__list_dup(xx);
        kk_std_core__list_decref(xs, _ctx);
      }
      { // tailcall
        kk_integer_t _x24440 = kk_integer_sub(n,(kk_integer_from_small(1)),kk_context()); /*int*/
        xs = xx;
        n = _x24440;
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
struct kk_std_core_drop_while_fun24444__t {
  struct kk_function_s _base;
  kk_function_t predicate0;
  kk_std_core__list xs0;
  kk_std_core__list xx0;
};
static kk_box_t kk_std_core_drop_while_fun24444(kk_function_t _fself, kk_box_t _b_22548, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_drop_while_fun24444(kk_function_t predicate0, kk_std_core__list xs0, kk_std_core__list xx0, kk_context_t* _ctx) {
  struct kk_std_core_drop_while_fun24444__t* _self = kk_function_alloc_as(struct kk_std_core_drop_while_fun24444__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_drop_while_fun24444, kk_context());
  _self->predicate0 = predicate0;
  _self->xs0 = xs0;
  _self->xx0 = xx0;
  return &_self->_base;
}

static kk_box_t kk_std_core_drop_while_fun24444(kk_function_t _fself, kk_box_t _b_22548, kk_context_t* _ctx) {
  struct kk_std_core_drop_while_fun24444__t* _self = kk_function_as(struct kk_std_core_drop_while_fun24444__t*, _fself);
  kk_function_t predicate0 = _self->predicate0; /* (14165) -> 14166 bool */
  kk_std_core__list xs0 = _self->xs0; /* list<14165> */
  kk_std_core__list xx0 = _self->xx0; /* list<14165> */
  kk_drop_match(_self, {kk_function_dup(predicate0);kk_std_core__list_dup(xs0);kk_std_core__list_dup(xx0);}, {}, _ctx)
  kk_std_core__list _x24445;
  bool _x24446 = kk_bool_unbox(_b_22548); /*bool*/
  _x24445 = kk_std_core__mlift21200_drop_while(predicate0, xs0, xx0, _x24446, _ctx); /*list<14165>*/
  return kk_std_core__list_box(_x24445, _ctx);
}

kk_std_core__list kk_std_core_drop_while(kk_std_core__list xs0, kk_function_t predicate0, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, predicate : (a) -> e bool) -> e list<a> */ 
  kk__tailcall: ;
  if (kk_std_core__is_Cons(xs0)) {
    struct kk_std_core_Cons* _con24441 = kk_std_core__as_Cons(xs0);
    kk_box_t x = _con24441->head;
    kk_std_core__list xx0 = _con24441->tail;
    kk_box_dup(x);
    kk_std_core__list_dup(xx0);
    bool x0_21557;
    kk_function_t _x24442 = kk_function_dup(predicate0); /*(14165) -> 14166 bool*/
    x0_21557 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_context_t*), _x24442, (_x24442, x, _ctx)); /*bool*/
    if (kk_yielding(kk_context())) {
      kk_box_t _x24443 = kk_std_core_hnd_yield_extend(kk_std_core_new_drop_while_fun24444(predicate0, xs0, xx0, _ctx), _ctx); /*3991*/
      return kk_std_core__list_unbox(_x24443, _ctx);
    }
    if (x0_21557) {
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
  bool _match_23517;
  kk_string_t _x24451 = kk_string_dup(s); /*string*/
  kk_string_t _x24452 = kk_string_dup(post); /*string*/
  _match_23517 = kk_std_core_xends_with(_x24451, _x24452, _ctx); /*bool*/
  if (_match_23517) {
    kk_std_core__sslice _b_22552_22551;
    kk_string_t _x24453 = kk_string_dup(s); /*string*/
    size_t _x24454 = ((size_t)0); /*size_t*/
    size_t _x24455;
    size_t _x24456 = kk_string_len(s,kk_context()); /*size_t*/
    size_t _x24457 = kk_string_len(post,kk_context()); /*size_t*/
    _x24455 = (_x24456 - _x24457); /*size_t*/
    _b_22552_22551 = kk_std_core__new_Sslice(_x24453, _x24454, _x24455, _ctx); /*sslice*/
    return kk_std_core_types__new_Just(kk_std_core__sslice_box(_b_22552_22551, _ctx), _ctx);
  }
  kk_string_drop(post, _ctx);
  kk_string_drop(s, _ctx);
  return kk_std_core_types__new_Nothing(_ctx);
}
 
// Throw an exception with a specified message.

kk_box_t kk_std_core_throw(kk_string_t message0, kk_std_core_types__optional info0, kk_context_t* _ctx) { /* forall<a> (message : string, info : optional<exception-info>) -> exn a */ 
  kk_std_core__exception exn_21561;
  kk_std_core__exception_info _x24458;
  if (kk_std_core_types__is_Optional(info0)) {
    kk_box_t _box_x22553 = info0._cons.Optional.value;
    kk_std_core__exception_info _info_14279 = kk_std_core__exception_info_unbox(_box_x22553, NULL);
    kk_std_core__exception_info_dup(_info_14279);
    kk_std_core_types__optional_drop(info0, _ctx);
    _x24458 = _info_14279; /*exception-info*/
    goto _match24459;
  }
  _x24458 = kk_std_core__new_ExnError(_ctx); /*exception-info*/
  _match24459: ;
  exn_21561 = kk_std_core__new_Exception(message0, _x24458, _ctx); /*exception*/
  kk_std_core_hnd__ev ev_21562;
  size_t _x24461 = ((size_t)0); /*size_t*/
  ev_21562 = kk_evv_at(_x24461,kk_context()); /*std/core/hnd/ev<.hnd-exn>*/
  struct kk_std_core_hnd_Ev* _con24462 = kk_std_core_hnd__as_Ev(ev_21562);
  kk_std_core_hnd__marker m = _con24462->marker;
  kk_box_t _box_x22554 = _con24462->hnd;
  kk_std_core__hnd_exn h = kk_std_core__hnd_exn_unbox(_box_x22554, NULL);
  kk_std_core__hnd_exn_dup(h);
  kk_std_core_hnd__clause1 _match_23516;
  struct kk_std_core__Hnd_exn* _con24464 = kk_std_core__as_Hnd_exn(h);
  kk_std_core_hnd__clause1 except_throw_exn = _con24464->except_throw_exn;
  if (kk_std_core__hnd_exn_is_unique(h)) {
    kk_std_core__hnd_exn_free(h);
  }
  else {
    kk_std_core_hnd__clause1_dup(except_throw_exn);
    kk_std_core__hnd_exn_decref(h, _ctx);
  }
  _match_23516 = except_throw_exn; /*forall<a> std/core/hnd/clause1<exception,a,.hnd-exn,3528,3529>*/
  kk_function_t _fun_unbox_x22558 = _match_23516.clause;
  return kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x22558, (_fun_unbox_x22558, m, ev_21562, kk_std_core__exception_box(exn_21561, _ctx), _ctx));
}
 
// Transform an `:error` type back to an `exn` effect.

kk_box_t kk_std_core_throw_1(kk_std_core__error err, kk_context_t* _ctx) { /* forall<a> (err : error<a>) -> exn a */ 
  if (kk_std_core__is_Error(err)) {
    kk_std_core__exception exn0 = err._cons.Error.exception;
    kk_std_core__exception_dup(exn0);
    kk_std_core__error_drop(err, _ctx);
    return kk_std_core_throw_exn(exn0, _ctx);
  }
  kk_box_t x = err._cons.Ok.result;
  kk_box_dup(x);
  kk_std_core__error_drop(err, _ctx);
  return x;
}
 
// monadic lift

kk_box_t kk_std_core__mlift21201_error_pattern(kk_string_t definition, kk_string_t location, kk_string_t _c_122, kk_context_t* _ctx) { /* forall<a> (definition : string, location : string, string) -> a */ 
  kk_string_t message_21565;
  kk_string_t _x24465 = kk_string_dup(location); /*string*/
  kk_string_t _x24466;
  kk_string_t _x24467;
  kk_define_string_literal(, _s24468, 23, ": pattern match failure")
  _x24467 = kk_string_dup(_s24468); /*string*/
  _x24466 = kk_std_core__lp__plus__plus__1_rp_(_c_122, _x24467, _ctx); /*string*/
  message_21565 = kk_std_core__lp__plus__plus__1_rp_(_x24465, _x24466, _ctx); /*string*/
  kk_std_core_types__optional info_21566;
  kk_std_core__exception_info _b_22566_22565 = kk_std_core__new_ExnPattern(kk_reuse_null, location, definition, _ctx); /*exception-info*/;
  info_21566 = kk_std_core_types__new_Optional(kk_std_core__exception_info_box(_b_22566_22565, _ctx), _ctx); /*optional<exception-info>*/
  kk_std_core__exception exn_21567;
  kk_std_core__exception_info _x24469;
  if (kk_std_core_types__is_Optional(info_21566)) {
    kk_box_t _box_x22567 = info_21566._cons.Optional.value;
    kk_std_core__exception_info _info_14279 = kk_std_core__exception_info_unbox(_box_x22567, NULL);
    kk_std_core__exception_info_dup(_info_14279);
    kk_std_core_types__optional_drop(info_21566, _ctx);
    _x24469 = _info_14279; /*exception-info*/
    goto _match24470;
  }
  _x24469 = kk_std_core__new_ExnError(_ctx); /*exception-info*/
  _match24470: ;
  exn_21567 = kk_std_core__new_Exception(message_21565, _x24469, _ctx); /*exception*/
  kk_std_core_hnd__ev ev_21568;
  size_t _x24472 = ((size_t)0); /*size_t*/
  ev_21568 = kk_evv_at(_x24472,kk_context()); /*std/core/hnd/ev<.hnd-exn>*/
  struct kk_std_core_hnd_Ev* _con24473 = kk_std_core_hnd__as_Ev(ev_21568);
  kk_std_core_hnd__marker m = _con24473->marker;
  kk_box_t _box_x22568 = _con24473->hnd;
  kk_std_core__hnd_exn h = kk_std_core__hnd_exn_unbox(_box_x22568, NULL);
  kk_std_core__hnd_exn_dup(h);
  kk_std_core_hnd__clause1 _match_23515;
  struct kk_std_core__Hnd_exn* _con24475 = kk_std_core__as_Hnd_exn(h);
  kk_std_core_hnd__clause1 except_throw_exn = _con24475->except_throw_exn;
  if (kk_std_core__hnd_exn_is_unique(h)) {
    kk_std_core__hnd_exn_free(h);
  }
  else {
    kk_std_core_hnd__clause1_dup(except_throw_exn);
    kk_std_core__hnd_exn_decref(h, _ctx);
  }
  _match_23515 = except_throw_exn; /*forall<a> std/core/hnd/clause1<exception,a,.hnd-exn,3528,3529>*/
  kk_function_t _fun_unbox_x22572 = _match_23515.clause;
  return kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x22572, (_fun_unbox_x22572, m, ev_21568, kk_std_core__exception_box(exn_21567, _ctx), _ctx));
}
 
// Raise a pattern match exception. This is function is used internally by the
// compiler to generate error messages on pattern match failures.


// lift anonymous function
struct kk_std_core_error_pattern_fun24481__t {
  struct kk_function_s _base;
  kk_string_t definition;
  kk_string_t location;
};
static kk_box_t kk_std_core_error_pattern_fun24481(kk_function_t _fself, kk_box_t _b_22580, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_error_pattern_fun24481(kk_string_t definition, kk_string_t location, kk_context_t* _ctx) {
  struct kk_std_core_error_pattern_fun24481__t* _self = kk_function_alloc_as(struct kk_std_core_error_pattern_fun24481__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_error_pattern_fun24481, kk_context());
  _self->definition = definition;
  _self->location = location;
  return &_self->_base;
}

static kk_box_t kk_std_core_error_pattern_fun24481(kk_function_t _fself, kk_box_t _b_22580, kk_context_t* _ctx) {
  struct kk_std_core_error_pattern_fun24481__t* _self = kk_function_as(struct kk_std_core_error_pattern_fun24481__t*, _fself);
  kk_string_t definition = _self->definition; /* string */
  kk_string_t location = _self->location; /* string */
  kk_drop_match(_self, {kk_string_dup(definition);kk_string_dup(location);}, {}, _ctx)
  kk_string_t _x24482 = kk_string_unbox(_b_22580); /*string*/
  return kk_std_core__mlift21201_error_pattern(definition, location, _x24482, _ctx);
}

kk_box_t kk_std_core_error_pattern(kk_string_t location, kk_string_t definition, kk_context_t* _ctx) { /* forall<a> (location : string, definition : string) -> exn a */ 
  kk_string_t x_21571;
  bool _match_23514;
  kk_string_t _x24476 = kk_string_dup(definition); /*string*/
  _match_23514 = kk_std_core_is_empty_2(_x24476, _ctx); /*bool*/
  if (_match_23514) {
    x_21571 = kk_string_empty(); /*string*/
  }
  else {
    kk_string_t _x24478;
    kk_define_string_literal(, _s24479, 2, ": ")
    _x24478 = kk_string_dup(_s24479); /*string*/
    kk_string_t _x24480 = kk_string_dup(definition); /*string*/
    x_21571 = kk_std_core__lp__plus__plus__1_rp_(_x24478, _x24480, _ctx); /*string*/
  }
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_21571, _ctx);
    return kk_std_core_hnd_yield_extend(kk_std_core_new_error_pattern_fun24481(definition, location, _ctx), _ctx);
  }
  kk_string_t message_21575;
  kk_string_t _x24483 = kk_string_dup(location); /*string*/
  kk_string_t _x24484;
  kk_string_t _x24485;
  kk_define_string_literal(, _s24486, 23, ": pattern match failure")
  _x24485 = kk_string_dup(_s24486); /*string*/
  _x24484 = kk_std_core__lp__plus__plus__1_rp_(x_21571, _x24485, _ctx); /*string*/
  message_21575 = kk_std_core__lp__plus__plus__1_rp_(_x24483, _x24484, _ctx); /*string*/
  kk_std_core_types__optional info_21576;
  kk_std_core__exception_info _b_22582_22581 = kk_std_core__new_ExnPattern(kk_reuse_null, location, definition, _ctx); /*exception-info*/;
  info_21576 = kk_std_core_types__new_Optional(kk_std_core__exception_info_box(_b_22582_22581, _ctx), _ctx); /*optional<exception-info>*/
  kk_std_core__exception exn_21577;
  kk_std_core__exception_info _x24487;
  if (kk_std_core_types__is_Optional(info_21576)) {
    kk_box_t _box_x22583 = info_21576._cons.Optional.value;
    kk_std_core__exception_info _info_14279 = kk_std_core__exception_info_unbox(_box_x22583, NULL);
    kk_std_core__exception_info_dup(_info_14279);
    kk_std_core_types__optional_drop(info_21576, _ctx);
    _x24487 = _info_14279; /*exception-info*/
    goto _match24488;
  }
  _x24487 = kk_std_core__new_ExnError(_ctx); /*exception-info*/
  _match24488: ;
  exn_21577 = kk_std_core__new_Exception(message_21575, _x24487, _ctx); /*exception*/
  kk_std_core_hnd__ev ev_21578;
  size_t _x24490 = ((size_t)0); /*size_t*/
  ev_21578 = kk_evv_at(_x24490,kk_context()); /*std/core/hnd/ev<.hnd-exn>*/
  struct kk_std_core_hnd_Ev* _con24491 = kk_std_core_hnd__as_Ev(ev_21578);
  kk_std_core_hnd__marker m = _con24491->marker;
  kk_box_t _box_x22584 = _con24491->hnd;
  kk_std_core__hnd_exn h = kk_std_core__hnd_exn_unbox(_box_x22584, NULL);
  kk_std_core__hnd_exn_dup(h);
  kk_std_core_hnd__clause1 _match_23513;
  struct kk_std_core__Hnd_exn* _con24493 = kk_std_core__as_Hnd_exn(h);
  kk_std_core_hnd__clause1 except_throw_exn = _con24493->except_throw_exn;
  if (kk_std_core__hnd_exn_is_unique(h)) {
    kk_std_core__hnd_exn_free(h);
  }
  else {
    kk_std_core_hnd__clause1_dup(except_throw_exn);
    kk_std_core__hnd_exn_decref(h, _ctx);
  }
  _match_23513 = except_throw_exn; /*forall<a> std/core/hnd/clause1<exception,a,.hnd-exn,3528,3529>*/
  kk_function_t _fun_unbox_x22588 = _match_23513.clause;
  return kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x22588, (_fun_unbox_x22588, m, ev_21578, kk_std_core__exception_box(exn_21577, _ctx), _ctx));
}
 
// monadic lift

kk_std_core__list kk_std_core__mlift21202_op(kk_std_core_types__ctail _acc, kk_function_t pred, kk_box_t x, kk_std_core__list xx, bool _y_125, kk_context_t* _ctx) { /* forall<a,e> (ctail<list<a>>, pred : (a) -> e bool, x : a, xx : list<a>, bool) -> e list<a> */ 
  if (_y_125) {
    kk_std_core__list _ctail_21131 = kk_std_core__list_hole(); /*list<14526>*/;
    kk_std_core__list _ctail_21132 = kk_std_core__new_Cons(kk_reuse_null, x, _ctail_21131, _ctx); /*list<14526>*/;
    kk_std_core_types__ctail _x24495;
    kk_box_t* field_21583 = (kk_box_t*)((&kk_std_core__as_Cons(_ctail_21132)->tail)); /*cfield<list<14526>>*/;
    if (kk_std_core_types__is_CTail(_acc)) {
      kk_box_t _box_x22603 = _acc._cons.CTail._field1;
      kk_box_t* last0 = _acc._cons.CTail._field2;
      kk_std_core__list head0 = kk_std_core__list_unbox(_box_x22603, NULL);
      kk_std_core__list_dup(head0);
      kk_std_core_types__ctail_drop(_acc, _ctx);
      kk_unit_t __ = kk_Unit;
      *(last0) = kk_std_core__list_box(_ctail_21132, _ctx);
      _x24495 = kk_std_core_types__new_CTail(kk_std_core__list_box(head0, _ctx), field_21583, _ctx); /*ctail<58>*/
      goto _match24496;
    }
    _x24495 = kk_std_core_types__new_CTail(kk_std_core__list_box(_ctail_21132, _ctx), field_21583, _ctx); /*ctail<58>*/
    _match24496: ;
    return kk_std_core__ctail_filter(xx, pred, _x24495, _ctx);
  }
  kk_box_drop(x, _ctx);
  return kk_std_core__ctail_filter(xx, pred, _acc, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_core__mlift21203_op_fun24498__t {
  struct kk_function_s _base;
  kk_function_t _accm;
  kk_box_t x0;
};
static kk_std_core__list kk_std_core__mlift21203_op_fun24498(kk_function_t _fself, kk_std_core__list _ctail_21134, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_mlift21203_op_fun24498(kk_function_t _accm, kk_box_t x0, kk_context_t* _ctx) {
  struct kk_std_core__mlift21203_op_fun24498__t* _self = kk_function_alloc_as(struct kk_std_core__mlift21203_op_fun24498__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__mlift21203_op_fun24498, kk_context());
  _self->_accm = _accm;
  _self->x0 = x0;
  return &_self->_base;
}

static kk_std_core__list kk_std_core__mlift21203_op_fun24498(kk_function_t _fself, kk_std_core__list _ctail_21134, kk_context_t* _ctx) {
  struct kk_std_core__mlift21203_op_fun24498__t* _self = kk_function_as(struct kk_std_core__mlift21203_op_fun24498__t*, _fself);
  kk_function_t _accm = _self->_accm; /* (list<14526>) -> list<14526> */
  kk_box_t x0 = _self->x0; /* 14526 */
  kk_drop_match(_self, {kk_function_dup(_accm);kk_box_dup(x0);}, {}, _ctx)
  kk_std_core__list _x24499 = kk_std_core__new_Cons(kk_reuse_null, x0, _ctail_21134, _ctx); /*list<61>*/
  return kk_function_call(kk_std_core__list, (kk_function_t, kk_std_core__list, kk_context_t*), _accm, (_accm, _x24499, _ctx));
}

kk_std_core__list kk_std_core__mlift21203_op(kk_function_t _accm, kk_function_t pred0, kk_box_t x0, kk_std_core__list xx0, bool _y_130, kk_context_t* _ctx) { /* forall<a,e> ((list<a>) -> list<a>, pred : (a) -> e bool, x : a, xx : list<a>, bool) -> e list<a> */ 
  if (_y_130) {
    return kk_std_core__ctailm_filter(xx0, pred0, kk_std_core__new_mlift21203_op_fun24498(_accm, x0, _ctx), _ctx);
  }
  kk_box_drop(x0, _ctx);
  return kk_std_core__ctailm_filter(xx0, pred0, _accm, _ctx);
}
 
// Retain only those elements of a list that satisfy the given predicate `pred`.
// For example: `filter([1,2,3],odd?) == [1,3]`


// lift anonymous function
struct kk_std_core__ctail_filter_fun24504__t {
  struct kk_function_s _base;
  kk_function_t pred1;
  kk_box_t x1;
  kk_std_core__list xx1;
  kk_std_core_types__ctail _acc0;
};
static kk_box_t kk_std_core__ctail_filter_fun24504(kk_function_t _fself, kk_box_t _b_22617, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_ctail_filter_fun24504(kk_function_t pred1, kk_box_t x1, kk_std_core__list xx1, kk_std_core_types__ctail _acc0, kk_context_t* _ctx) {
  struct kk_std_core__ctail_filter_fun24504__t* _self = kk_function_alloc_as(struct kk_std_core__ctail_filter_fun24504__t, 6, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__ctail_filter_fun24504, kk_context());
  _self->pred1 = pred1;
  _self->x1 = x1;
  _self->xx1 = xx1;
  _self->_acc0 = _acc0;
  return &_self->_base;
}

static kk_box_t kk_std_core__ctail_filter_fun24504(kk_function_t _fself, kk_box_t _b_22617, kk_context_t* _ctx) {
  struct kk_std_core__ctail_filter_fun24504__t* _self = kk_function_as(struct kk_std_core__ctail_filter_fun24504__t*, _fself);
  kk_function_t pred1 = _self->pred1; /* (14526) -> 14527 bool */
  kk_box_t x1 = _self->x1; /* 14526 */
  kk_std_core__list xx1 = _self->xx1; /* list<14526> */
  kk_std_core_types__ctail _acc0 = _self->_acc0; /* ctail<list<14526>> */
  kk_drop_match(_self, {kk_function_dup(pred1);kk_box_dup(x1);kk_std_core__list_dup(xx1);kk_std_core_types__ctail_dup(_acc0);}, {}, _ctx)
  kk_std_core__list _x24505;
  bool _x24506 = kk_bool_unbox(_b_22617); /*bool*/
  _x24505 = kk_std_core__mlift21202_op(_acc0, pred1, x1, xx1, _x24506, _ctx); /*list<14526>*/
  return kk_std_core__list_box(_x24505, _ctx);
}

kk_std_core__list kk_std_core__ctail_filter(kk_std_core__list xs, kk_function_t pred1, kk_std_core_types__ctail _acc0, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, pred : (a) -> e bool, ctail<list<a>>) -> e list<a> */ 
  kk__tailcall: ;
  if (kk_std_core__is_Cons(xs)) {
    struct kk_std_core_Cons* _con24500 = kk_std_core__as_Cons(xs);
    kk_box_t x1 = _con24500->head;
    kk_std_core__list xx1 = _con24500->tail;
    kk_reuse_t _ru_23366 = kk_reuse_null; /*reuse*/;
    if (kk_std_core__list_is_unique(xs)) {
      _ru_23366 = (kk_std_core__list_reuse(xs));
    }
    else {
      kk_box_dup(x1);
      kk_std_core__list_dup(xx1);
      kk_std_core__list_decref(xs, _ctx);
      _ru_23366 = kk_reuse_null;
    }
    bool x0_21584;
    kk_function_t _x24502 = kk_function_dup(pred1); /*(14526) -> 14527 bool*/
    kk_box_t _x24501 = kk_box_dup(x1); /*14526*/
    x0_21584 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_context_t*), _x24502, (_x24502, _x24501, _ctx)); /*bool*/
    if (kk_yielding(kk_context())) {
      kk_reuse_drop(_ru_23366, _ctx);
      kk_box_t _x24503 = kk_std_core_hnd_yield_extend(kk_std_core__new_ctail_filter_fun24504(pred1, x1, xx1, _acc0, _ctx), _ctx); /*3991*/
      return kk_std_core__list_unbox(_x24503, _ctx);
    }
    if (x0_21584) {
      kk_std_core__list _ctail_211310 = kk_std_core__list_hole(); /*list<14526>*/;
      kk_std_core__list _ctail_211320;
      bool _x24507 = _ru_23366!=NULL; /*bool*/
      if (_x24507) {
        struct kk_std_core_Cons* _con24508 = (struct kk_std_core_Cons*)_ru_23366;
        _con24508->tail = _ctail_211310;
        _ctail_211320 = kk_std_core__base_Cons(_con24508); /*list<14526>*/
      }
      else {
        _ctail_211320 = kk_std_core__new_Cons(kk_reuse_null, x1, _ctail_211310, _ctx); /*list<14526>*/
      }
      { // tailcall
        kk_std_core_types__ctail _x24509;
        kk_box_t* field_21590 = (kk_box_t*)((&kk_std_core__as_Cons(_ctail_211320)->tail)); /*cfield<list<14526>>*/;
        if (kk_std_core_types__is_CTail(_acc0)) {
          kk_box_t _box_x22624 = _acc0._cons.CTail._field1;
          kk_box_t* last2 = _acc0._cons.CTail._field2;
          kk_std_core__list head1 = kk_std_core__list_unbox(_box_x22624, NULL);
          kk_std_core__list_dup(head1);
          kk_std_core_types__ctail_drop(_acc0, _ctx);
          kk_unit_t __0 = kk_Unit;
          *(last2) = kk_std_core__list_box(_ctail_211320, _ctx);
          _x24509 = kk_std_core_types__new_CTail(kk_std_core__list_box(head1, _ctx), field_21590, _ctx); /*ctail<58>*/
          goto _match24510;
        }
        _x24509 = kk_std_core_types__new_CTail(kk_std_core__list_box(_ctail_211320, _ctx), field_21590, _ctx); /*ctail<58>*/
        _match24510: ;
        xs = xx1;
        _acc0 = _x24509;
        goto kk__tailcall;
      }
    }
    kk_reuse_drop(_ru_23366, _ctx);
    kk_box_drop(x1, _ctx);
    { // tailcall
      xs = xx1;
      goto kk__tailcall;
    }
  }
  kk_function_drop(pred1, _ctx);
  if (kk_std_core_types__is_CTail(_acc0)) {
    kk_box_t _box_x22633 = _acc0._cons.CTail._field1;
    kk_box_t* last00 = _acc0._cons.CTail._field2;
    kk_std_core__list head00 = kk_std_core__list_unbox(_box_x22633, NULL);
    kk_std_core__list_dup(head00);
    kk_std_core_types__ctail_drop(_acc0, _ctx);
    kk_unit_t __00 = kk_Unit;
    *(last00) = kk_std_core__list_box(kk_std_core__new_Nil(_ctx), _ctx);
    return head00;
  }
  return kk_std_core__new_Nil(_ctx);
}
 
// Retain only those elements of a list that satisfy the given predicate `pred`.
// For example: `filter([1,2,3],odd?) == [1,3]`


// lift anonymous function
struct kk_std_core__ctailm_filter_fun24517__t {
  struct kk_function_s _base;
  kk_function_t _accm0;
  kk_function_t pred2;
  kk_box_t x2;
  kk_std_core__list xx2;
};
static kk_box_t kk_std_core__ctailm_filter_fun24517(kk_function_t _fself, kk_box_t _b_22645, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_ctailm_filter_fun24517(kk_function_t _accm0, kk_function_t pred2, kk_box_t x2, kk_std_core__list xx2, kk_context_t* _ctx) {
  struct kk_std_core__ctailm_filter_fun24517__t* _self = kk_function_alloc_as(struct kk_std_core__ctailm_filter_fun24517__t, 5, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__ctailm_filter_fun24517, kk_context());
  _self->_accm0 = _accm0;
  _self->pred2 = pred2;
  _self->x2 = x2;
  _self->xx2 = xx2;
  return &_self->_base;
}

static kk_box_t kk_std_core__ctailm_filter_fun24517(kk_function_t _fself, kk_box_t _b_22645, kk_context_t* _ctx) {
  struct kk_std_core__ctailm_filter_fun24517__t* _self = kk_function_as(struct kk_std_core__ctailm_filter_fun24517__t*, _fself);
  kk_function_t _accm0 = _self->_accm0; /* (list<14526>) -> list<14526> */
  kk_function_t pred2 = _self->pred2; /* (14526) -> 14527 bool */
  kk_box_t x2 = _self->x2; /* 14526 */
  kk_std_core__list xx2 = _self->xx2; /* list<14526> */
  kk_drop_match(_self, {kk_function_dup(_accm0);kk_function_dup(pred2);kk_box_dup(x2);kk_std_core__list_dup(xx2);}, {}, _ctx)
  kk_std_core__list _x24518;
  bool _x24519 = kk_bool_unbox(_b_22645); /*bool*/
  _x24518 = kk_std_core__mlift21203_op(_accm0, pred2, x2, xx2, _x24519, _ctx); /*list<14526>*/
  return kk_std_core__list_box(_x24518, _ctx);
}


// lift anonymous function
struct kk_std_core__ctailm_filter_fun24521__t {
  struct kk_function_s _base;
  kk_function_t _accm0;
  kk_box_t x2;
};
static kk_std_core__list kk_std_core__ctailm_filter_fun24521(kk_function_t _fself, kk_std_core__list _ctail_211340, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_ctailm_filter_fun24521(kk_function_t _accm0, kk_box_t x2, kk_context_t* _ctx) {
  struct kk_std_core__ctailm_filter_fun24521__t* _self = kk_function_alloc_as(struct kk_std_core__ctailm_filter_fun24521__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__ctailm_filter_fun24521, kk_context());
  _self->_accm0 = _accm0;
  _self->x2 = x2;
  return &_self->_base;
}

static kk_std_core__list kk_std_core__ctailm_filter_fun24521(kk_function_t _fself, kk_std_core__list _ctail_211340, kk_context_t* _ctx) {
  struct kk_std_core__ctailm_filter_fun24521__t* _self = kk_function_as(struct kk_std_core__ctailm_filter_fun24521__t*, _fself);
  kk_function_t _accm0 = _self->_accm0; /* (list<14526>) -> list<14526> */
  kk_box_t x2 = _self->x2; /* 14526 */
  kk_drop_match(_self, {kk_function_dup(_accm0);kk_box_dup(x2);}, {}, _ctx)
  kk_std_core__list _x24522 = kk_std_core__new_Cons(kk_reuse_null, x2, _ctail_211340, _ctx); /*list<61>*/
  return kk_function_call(kk_std_core__list, (kk_function_t, kk_std_core__list, kk_context_t*), _accm0, (_accm0, _x24522, _ctx));
}

kk_std_core__list kk_std_core__ctailm_filter(kk_std_core__list xs0, kk_function_t pred2, kk_function_t _accm0, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, pred : (a) -> e bool, (list<a>) -> list<a>) -> e list<a> */ 
  kk__tailcall: ;
  if (kk_std_core__is_Cons(xs0)) {
    struct kk_std_core_Cons* _con24513 = kk_std_core__as_Cons(xs0);
    kk_box_t x2 = _con24513->head;
    kk_std_core__list xx2 = _con24513->tail;
    if (kk_std_core__list_is_unique(xs0)) {
      kk_std_core__list_free(xs0);
    }
    else {
      kk_box_dup(x2);
      kk_std_core__list_dup(xx2);
      kk_std_core__list_decref(xs0, _ctx);
    }
    bool x0_21593;
    kk_function_t _x24515 = kk_function_dup(pred2); /*(14526) -> 14527 bool*/
    kk_box_t _x24514 = kk_box_dup(x2); /*14526*/
    x0_21593 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_context_t*), _x24515, (_x24515, _x24514, _ctx)); /*bool*/
    if (kk_yielding(kk_context())) {
      kk_box_t _x24516 = kk_std_core_hnd_yield_extend(kk_std_core__new_ctailm_filter_fun24517(_accm0, pred2, x2, xx2, _ctx), _ctx); /*3991*/
      return kk_std_core__list_unbox(_x24516, _ctx);
    }
    if (x0_21593) {
      { // tailcall
        kk_function_t _x24520 = kk_std_core__new_ctailm_filter_fun24521(_accm0, x2, _ctx); /*(list<14526>) -> list<14526>*/
        xs0 = xx2;
        _accm0 = _x24520;
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
struct kk_std_core_filter_fun24523__t {
  struct kk_function_s _base;
};
static kk_std_core__list kk_std_core_filter_fun24523(kk_function_t _fself, kk_std_core__list _ctail_21133, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_filter_fun24523(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_filter_fun24523, _ctx)
  return kk_function_dup(_fself);
}

static kk_std_core__list kk_std_core_filter_fun24523(kk_function_t _fself, kk_std_core__list _ctail_21133, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return _ctail_21133;
}

kk_std_core__list kk_std_core_filter(kk_std_core__list xs1, kk_function_t pred3, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, pred : (a) -> e bool) -> e list<a> */ 
  bool _match_23509 = kk_std_core_hnd__evv_is_affine(_ctx); /*bool*/;
  if (_match_23509) {
    return kk_std_core__ctail_filter(xs1, pred3, kk_std_core_types__new_CTailNil(_ctx), _ctx);
  }
  return kk_std_core__ctailm_filter(xs1, pred3, kk_std_core_new_filter_fun24523(_ctx), _ctx);
}
 
// monadic lift

kk_std_core__list kk_std_core__mlift21204_op(kk_std_core_types__ctail _acc, kk_function_t pred, kk_std_core__list xx, kk_std_core_types__maybe _y_138, kk_context_t* _ctx) { /* forall<a,b,e> (ctail<list<b>>, pred : (a) -> e maybe<b>, xx : list<a>, maybe<b>) -> e list<b> */ 
  if (kk_std_core_types__is_Nothing(_y_138)) {
    return kk_std_core__ctail_filter_map(xx, pred, _acc, _ctx);
  }
  kk_box_t y = _y_138._cons.Just.value;
  kk_std_core__list _ctail_21135 = kk_std_core__list_hole(); /*list<14572>*/;
  kk_std_core__list _ctail_21136 = kk_std_core__new_Cons(kk_reuse_null, y, _ctail_21135, _ctx); /*list<14572>*/;
  kk_std_core_types__ctail _x24524;
  kk_box_t* field_21599 = (kk_box_t*)((&kk_std_core__as_Cons(_ctail_21136)->tail)); /*cfield<list<14572>>*/;
  if (kk_std_core_types__is_CTail(_acc)) {
    kk_box_t _box_x22654 = _acc._cons.CTail._field1;
    kk_box_t* last0 = _acc._cons.CTail._field2;
    kk_std_core__list head0 = kk_std_core__list_unbox(_box_x22654, NULL);
    kk_std_core__list_dup(head0);
    kk_std_core_types__ctail_drop(_acc, _ctx);
    kk_unit_t __ = kk_Unit;
    *(last0) = kk_std_core__list_box(_ctail_21136, _ctx);
    _x24524 = kk_std_core_types__new_CTail(kk_std_core__list_box(head0, _ctx), field_21599, _ctx); /*ctail<58>*/
    goto _match24525;
  }
  _x24524 = kk_std_core_types__new_CTail(kk_std_core__list_box(_ctail_21136, _ctx), field_21599, _ctx); /*ctail<58>*/
  _match24525: ;
  return kk_std_core__ctail_filter_map(xx, pred, _x24524, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_core__mlift21205_op_fun24527__t {
  struct kk_function_s _base;
  kk_function_t _accm;
  kk_box_t y0;
};
static kk_std_core__list kk_std_core__mlift21205_op_fun24527(kk_function_t _fself, kk_std_core__list _ctail_21138, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_mlift21205_op_fun24527(kk_function_t _accm, kk_box_t y0, kk_context_t* _ctx) {
  struct kk_std_core__mlift21205_op_fun24527__t* _self = kk_function_alloc_as(struct kk_std_core__mlift21205_op_fun24527__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__mlift21205_op_fun24527, kk_context());
  _self->_accm = _accm;
  _self->y0 = y0;
  return &_self->_base;
}

static kk_std_core__list kk_std_core__mlift21205_op_fun24527(kk_function_t _fself, kk_std_core__list _ctail_21138, kk_context_t* _ctx) {
  struct kk_std_core__mlift21205_op_fun24527__t* _self = kk_function_as(struct kk_std_core__mlift21205_op_fun24527__t*, _fself);
  kk_function_t _accm = _self->_accm; /* (list<14572>) -> list<14572> */
  kk_box_t y0 = _self->y0; /* 14572 */
  kk_drop_match(_self, {kk_function_dup(_accm);kk_box_dup(y0);}, {}, _ctx)
  kk_std_core__list _x24528 = kk_std_core__new_Cons(kk_reuse_null, y0, _ctail_21138, _ctx); /*list<61>*/
  return kk_function_call(kk_std_core__list, (kk_function_t, kk_std_core__list, kk_context_t*), _accm, (_accm, _x24528, _ctx));
}

kk_std_core__list kk_std_core__mlift21205_op(kk_function_t _accm, kk_function_t pred0, kk_std_core__list xx0, kk_std_core_types__maybe _y_143, kk_context_t* _ctx) { /* forall<a,b,e> ((list<b>) -> list<b>, pred : (a) -> e maybe<b>, xx : list<a>, maybe<b>) -> e list<b> */ 
  if (kk_std_core_types__is_Nothing(_y_143)) {
    return kk_std_core__ctailm_filter_map(xx0, pred0, _accm, _ctx);
  }
  kk_box_t y0 = _y_143._cons.Just.value;
  return kk_std_core__ctailm_filter_map(xx0, pred0, kk_std_core__new_mlift21205_op_fun24527(_accm, y0, _ctx), _ctx);
}
 
// Retain only those elements of a list that satisfy the given predicate `pred`.
// For example: `filterMap([1,2,3],fn(i) { if (i.odd?) then Nothing else Just(i*i) }) == [4]`


// lift anonymous function
struct kk_std_core__ctail_filter_map_fun24533__t {
  struct kk_function_s _base;
  kk_function_t pred1;
  kk_std_core__list xx1;
  kk_std_core_types__ctail _acc0;
};
static kk_box_t kk_std_core__ctail_filter_map_fun24533(kk_function_t _fself, kk_box_t _b_22673, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_ctail_filter_map_fun24533(kk_function_t pred1, kk_std_core__list xx1, kk_std_core_types__ctail _acc0, kk_context_t* _ctx) {
  struct kk_std_core__ctail_filter_map_fun24533__t* _self = kk_function_alloc_as(struct kk_std_core__ctail_filter_map_fun24533__t, 5, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__ctail_filter_map_fun24533, kk_context());
  _self->pred1 = pred1;
  _self->xx1 = xx1;
  _self->_acc0 = _acc0;
  return &_self->_base;
}

static kk_box_t kk_std_core__ctail_filter_map_fun24533(kk_function_t _fself, kk_box_t _b_22673, kk_context_t* _ctx) {
  struct kk_std_core__ctail_filter_map_fun24533__t* _self = kk_function_as(struct kk_std_core__ctail_filter_map_fun24533__t*, _fself);
  kk_function_t pred1 = _self->pred1; /* (14571) -> 14573 maybe<14572> */
  kk_std_core__list xx1 = _self->xx1; /* list<14571> */
  kk_std_core_types__ctail _acc0 = _self->_acc0; /* ctail<list<14572>> */
  kk_drop_match(_self, {kk_function_dup(pred1);kk_std_core__list_dup(xx1);kk_std_core_types__ctail_dup(_acc0);}, {}, _ctx)
  kk_std_core__list _x24534;
  kk_std_core_types__maybe _x24535 = kk_std_core_types__maybe_unbox(_b_22673, _ctx); /*maybe<14572>*/
  _x24534 = kk_std_core__mlift21204_op(_acc0, pred1, xx1, _x24535, _ctx); /*list<14572>*/
  return kk_std_core__list_box(_x24534, _ctx);
}

kk_std_core__list kk_std_core__ctail_filter_map(kk_std_core__list xs, kk_function_t pred1, kk_std_core_types__ctail _acc0, kk_context_t* _ctx) { /* forall<a,b,e> (xs : list<a>, pred : (a) -> e maybe<b>, ctail<list<b>>) -> e list<b> */ 
  kk__tailcall: ;
  if (kk_std_core__is_Nil(xs)) {
    kk_function_drop(pred1, _ctx);
    if (kk_std_core_types__is_CTail(_acc0)) {
      kk_box_t _box_x22667 = _acc0._cons.CTail._field1;
      kk_box_t* last2 = _acc0._cons.CTail._field2;
      kk_std_core__list head1 = kk_std_core__list_unbox(_box_x22667, NULL);
      kk_std_core__list_dup(head1);
      kk_std_core_types__ctail_drop(_acc0, _ctx);
      kk_unit_t __0 = kk_Unit;
      *(last2) = kk_std_core__list_box(kk_std_core__new_Nil(_ctx), _ctx);
      return head1;
    }
    return kk_std_core__new_Nil(_ctx);
  }
  struct kk_std_core_Cons* _con24530 = kk_std_core__as_Cons(xs);
  kk_box_t x = _con24530->head;
  kk_std_core__list xx1 = _con24530->tail;
  kk_reuse_t _ru_23368 = kk_reuse_null; /*reuse*/;
  if (kk_std_core__list_is_unique(xs)) {
    _ru_23368 = (kk_std_core__list_reuse(xs));
  }
  else {
    kk_box_dup(x);
    kk_std_core__list_dup(xx1);
    kk_std_core__list_decref(xs, _ctx);
    _ru_23368 = kk_reuse_null;
  }
  kk_std_core_types__maybe x0_21602;
  kk_function_t _x24531 = kk_function_dup(pred1); /*(14571) -> 14573 maybe<14572>*/
  x0_21602 = kk_function_call(kk_std_core_types__maybe, (kk_function_t, kk_box_t, kk_context_t*), _x24531, (_x24531, x, _ctx)); /*maybe<14572>*/
  if (kk_yielding(kk_context())) {
    kk_reuse_drop(_ru_23368, _ctx);
    kk_std_core_types__maybe_drop(x0_21602, _ctx);
    kk_box_t _x24532 = kk_std_core_hnd_yield_extend(kk_std_core__new_ctail_filter_map_fun24533(pred1, xx1, _acc0, _ctx), _ctx); /*3991*/
    return kk_std_core__list_unbox(_x24532, _ctx);
  }
  if (kk_std_core_types__is_Nothing(x0_21602)) {
    kk_reuse_drop(_ru_23368, _ctx);
    { // tailcall
      xs = xx1;
      goto kk__tailcall;
    }
  }
  kk_box_t y1 = x0_21602._cons.Just.value;
  kk_std_core__list _ctail_211350 = kk_std_core__list_hole(); /*list<14572>*/;
  kk_std_core__list _ctail_211360 = kk_std_core__new_Cons(_ru_23368, y1, _ctail_211350, _ctx); /*list<14572>*/;
  { // tailcall
    kk_std_core_types__ctail _x24536;
    kk_box_t* field_21608 = (kk_box_t*)((&kk_std_core__as_Cons(_ctail_211360)->tail)); /*cfield<list<14572>>*/;
    if (kk_std_core_types__is_CTail(_acc0)) {
      kk_box_t _box_x22680 = _acc0._cons.CTail._field1;
      kk_box_t* last00 = _acc0._cons.CTail._field2;
      kk_std_core__list head00 = kk_std_core__list_unbox(_box_x22680, NULL);
      kk_std_core__list_dup(head00);
      kk_std_core_types__ctail_drop(_acc0, _ctx);
      kk_unit_t __00 = kk_Unit;
      *(last00) = kk_std_core__list_box(_ctail_211360, _ctx);
      _x24536 = kk_std_core_types__new_CTail(kk_std_core__list_box(head00, _ctx), field_21608, _ctx); /*ctail<58>*/
      goto _match24537;
    }
    _x24536 = kk_std_core_types__new_CTail(kk_std_core__list_box(_ctail_211360, _ctx), field_21608, _ctx); /*ctail<58>*/
    _match24537: ;
    xs = xx1;
    _acc0 = _x24536;
    goto kk__tailcall;
  }
}
 
// Retain only those elements of a list that satisfy the given predicate `pred`.
// For example: `filterMap([1,2,3],fn(i) { if (i.odd?) then Nothing else Just(i*i) }) == [4]`


// lift anonymous function
struct kk_std_core__ctailm_filter_map_fun24542__t {
  struct kk_function_s _base;
  kk_function_t _accm0;
  kk_function_t pred2;
  kk_std_core__list xx2;
};
static kk_box_t kk_std_core__ctailm_filter_map_fun24542(kk_function_t _fself, kk_box_t _b_22696, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_ctailm_filter_map_fun24542(kk_function_t _accm0, kk_function_t pred2, kk_std_core__list xx2, kk_context_t* _ctx) {
  struct kk_std_core__ctailm_filter_map_fun24542__t* _self = kk_function_alloc_as(struct kk_std_core__ctailm_filter_map_fun24542__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__ctailm_filter_map_fun24542, kk_context());
  _self->_accm0 = _accm0;
  _self->pred2 = pred2;
  _self->xx2 = xx2;
  return &_self->_base;
}

static kk_box_t kk_std_core__ctailm_filter_map_fun24542(kk_function_t _fself, kk_box_t _b_22696, kk_context_t* _ctx) {
  struct kk_std_core__ctailm_filter_map_fun24542__t* _self = kk_function_as(struct kk_std_core__ctailm_filter_map_fun24542__t*, _fself);
  kk_function_t _accm0 = _self->_accm0; /* (list<14572>) -> list<14572> */
  kk_function_t pred2 = _self->pred2; /* (14571) -> 14573 maybe<14572> */
  kk_std_core__list xx2 = _self->xx2; /* list<14571> */
  kk_drop_match(_self, {kk_function_dup(_accm0);kk_function_dup(pred2);kk_std_core__list_dup(xx2);}, {}, _ctx)
  kk_std_core__list _x24543;
  kk_std_core_types__maybe _x24544 = kk_std_core_types__maybe_unbox(_b_22696, _ctx); /*maybe<14572>*/
  _x24543 = kk_std_core__mlift21205_op(_accm0, pred2, xx2, _x24544, _ctx); /*list<14572>*/
  return kk_std_core__list_box(_x24543, _ctx);
}


// lift anonymous function
struct kk_std_core__ctailm_filter_map_fun24546__t {
  struct kk_function_s _base;
  kk_function_t _accm0;
  kk_box_t y2;
};
static kk_std_core__list kk_std_core__ctailm_filter_map_fun24546(kk_function_t _fself, kk_std_core__list _ctail_211380, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_ctailm_filter_map_fun24546(kk_function_t _accm0, kk_box_t y2, kk_context_t* _ctx) {
  struct kk_std_core__ctailm_filter_map_fun24546__t* _self = kk_function_alloc_as(struct kk_std_core__ctailm_filter_map_fun24546__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__ctailm_filter_map_fun24546, kk_context());
  _self->_accm0 = _accm0;
  _self->y2 = y2;
  return &_self->_base;
}

static kk_std_core__list kk_std_core__ctailm_filter_map_fun24546(kk_function_t _fself, kk_std_core__list _ctail_211380, kk_context_t* _ctx) {
  struct kk_std_core__ctailm_filter_map_fun24546__t* _self = kk_function_as(struct kk_std_core__ctailm_filter_map_fun24546__t*, _fself);
  kk_function_t _accm0 = _self->_accm0; /* (list<14572>) -> list<14572> */
  kk_box_t y2 = _self->y2; /* 14572 */
  kk_drop_match(_self, {kk_function_dup(_accm0);kk_box_dup(y2);}, {}, _ctx)
  kk_std_core__list _x24547 = kk_std_core__new_Cons(kk_reuse_null, y2, _ctail_211380, _ctx); /*list<61>*/
  return kk_function_call(kk_std_core__list, (kk_function_t, kk_std_core__list, kk_context_t*), _accm0, (_accm0, _x24547, _ctx));
}

kk_std_core__list kk_std_core__ctailm_filter_map(kk_std_core__list xs0, kk_function_t pred2, kk_function_t _accm0, kk_context_t* _ctx) { /* forall<a,b,e> (xs : list<a>, pred : (a) -> e maybe<b>, (list<b>) -> list<b>) -> e list<b> */ 
  kk__tailcall: ;
  if (kk_std_core__is_Nil(xs0)) {
    kk_function_drop(pred2, _ctx);
    return kk_function_call(kk_std_core__list, (kk_function_t, kk_std_core__list, kk_context_t*), _accm0, (_accm0, kk_std_core__new_Nil(_ctx), _ctx));
  }
  struct kk_std_core_Cons* _con24539 = kk_std_core__as_Cons(xs0);
  kk_box_t x0 = _con24539->head;
  kk_std_core__list xx2 = _con24539->tail;
  if (kk_std_core__list_is_unique(xs0)) {
    kk_std_core__list_free(xs0);
  }
  else {
    kk_box_dup(x0);
    kk_std_core__list_dup(xx2);
    kk_std_core__list_decref(xs0, _ctx);
  }
  kk_std_core_types__maybe x0_21609;
  kk_function_t _x24540 = kk_function_dup(pred2); /*(14571) -> 14573 maybe<14572>*/
  x0_21609 = kk_function_call(kk_std_core_types__maybe, (kk_function_t, kk_box_t, kk_context_t*), _x24540, (_x24540, x0, _ctx)); /*maybe<14572>*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__maybe_drop(x0_21609, _ctx);
    kk_box_t _x24541 = kk_std_core_hnd_yield_extend(kk_std_core__new_ctailm_filter_map_fun24542(_accm0, pred2, xx2, _ctx), _ctx); /*3991*/
    return kk_std_core__list_unbox(_x24541, _ctx);
  }
  if (kk_std_core_types__is_Nothing(x0_21609)) {
    { // tailcall
      xs0 = xx2;
      goto kk__tailcall;
    }
  }
  kk_box_t y2 = x0_21609._cons.Just.value;
  { // tailcall
    kk_function_t _x24545 = kk_std_core__new_ctailm_filter_map_fun24546(_accm0, y2, _ctx); /*(list<14572>) -> list<14572>*/
    xs0 = xx2;
    _accm0 = _x24545;
    goto kk__tailcall;
  }
}
 
// Retain only those elements of a list that satisfy the given predicate `pred`.
// For example: `filterMap([1,2,3],fn(i) { if (i.odd?) then Nothing else Just(i*i) }) == [4]`


// lift anonymous function
struct kk_std_core_filter_map_fun24548__t {
  struct kk_function_s _base;
};
static kk_std_core__list kk_std_core_filter_map_fun24548(kk_function_t _fself, kk_std_core__list _ctail_21137, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_filter_map_fun24548(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_filter_map_fun24548, _ctx)
  return kk_function_dup(_fself);
}

static kk_std_core__list kk_std_core_filter_map_fun24548(kk_function_t _fself, kk_std_core__list _ctail_21137, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return _ctail_21137;
}

kk_std_core__list kk_std_core_filter_map(kk_std_core__list xs1, kk_function_t pred3, kk_context_t* _ctx) { /* forall<a,b,e> (xs : list<a>, pred : (a) -> e maybe<b>) -> e list<b> */ 
  bool _match_23506 = kk_std_core_hnd__evv_is_affine(_ctx); /*bool*/;
  if (_match_23506) {
    return kk_std_core__ctail_filter_map(xs1, pred3, kk_std_core_types__new_CTailNil(_ctx), _ctx);
  }
  return kk_std_core__ctailm_filter_map(xs1, pred3, kk_std_core_new_filter_map_fun24548(_ctx), _ctx);
}

bool kk_std_core_is_zero_1(size_t i, kk_context_t* _ctx) { /* (i : size_t) -> bool */ 
  return (i == 0);
}
 
// Find the first element satisfying some predicate


// lift anonymous function
struct kk_std_core_find_fun24549__t {
  struct kk_function_s _base;
  kk_function_t pred;
};
static kk_std_core_types__maybe kk_std_core_find_fun24549(kk_function_t _fself, kk_box_t x, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_find_fun24549(kk_function_t pred, kk_context_t* _ctx) {
  struct kk_std_core_find_fun24549__t* _self = kk_function_alloc_as(struct kk_std_core_find_fun24549__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_find_fun24549, kk_context());
  _self->pred = pred;
  return &_self->_base;
}

static kk_std_core_types__maybe kk_std_core_find_fun24549(kk_function_t _fself, kk_box_t x, kk_context_t* _ctx) {
  struct kk_std_core_find_fun24549__t* _self = kk_function_as(struct kk_std_core_find_fun24549__t*, _fself);
  kk_function_t pred = _self->pred; /* (14688) -> bool */
  kk_drop_match(_self, {kk_function_dup(pred);}, {}, _ctx)
  bool _match_23505;
  kk_box_t _x24550 = kk_box_dup(x); /*14688*/
  _match_23505 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_context_t*), pred, (pred, _x24550, _ctx)); /*bool*/
  if (_match_23505) {
    return kk_std_core_types__new_Just(x, _ctx);
  }
  kk_box_drop(x, _ctx);
  return kk_std_core_types__new_Nothing(_ctx);
}

kk_std_core_types__maybe kk_std_core_find(kk_std_core__list xs, kk_function_t pred, kk_context_t* _ctx) { /* forall<a> (xs : list<a>, pred : (a) -> bool) -> maybe<a> */ 
  return kk_std_core_foreach_while(xs, kk_std_core_new_find_fun24549(pred, _ctx), _ctx);
}
 
// O(n). If it occurs, return the position of substring `sub` in `s`, tupled with
// the position just following the substring `sub`.

kk_std_core_types__maybe kk_std_core_find_1(kk_string_t s, kk_string_t sub, kk_context_t* _ctx) { /* (s : string, sub : string) -> maybe<sslice> */ 
  size_t i;
  kk_string_t _x24551 = kk_string_dup(s); /*string*/
  kk_string_t _x24552 = kk_string_dup(sub); /*string*/
  i = kk_string_index_of1(_x24551,_x24552,kk_context()); /*size_t*/
  bool _match_23504 = kk_std_core_is_zero_1(i, _ctx); /*bool*/;
  if (_match_23504) {
    kk_string_drop(s, _ctx);
    kk_string_drop(sub, _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
  kk_std_core__sslice _b_22700_22699;
  size_t _x24553 = kk_std_core_decr_1(i, _ctx); /*size_t*/
  size_t _x24554 = kk_string_len(sub,kk_context()); /*size_t*/
  _b_22700_22699 = kk_std_core__new_Sslice(s, _x24553, _x24554, _ctx); /*sslice*/
  return kk_std_core_types__new_Just(kk_std_core__sslice_box(_b_22700_22699, _ctx), _ctx);
}
 
// Return the last index of substring `sub` in `s` if it occurs.

kk_std_core_types__maybe kk_std_core_find_last(kk_string_t s, kk_string_t sub, kk_context_t* _ctx) { /* (s : string, sub : string) -> maybe<sslice> */ 
  size_t i;
  kk_string_t _x24555 = kk_string_dup(s); /*string*/
  kk_string_t _x24556 = kk_string_dup(sub); /*string*/
  i = kk_string_last_index_of1(_x24555,_x24556,kk_context()); /*size_t*/
  bool _match_23503 = kk_std_core_is_zero_1(i, _ctx); /*bool*/;
  if (_match_23503) {
    kk_string_drop(s, _ctx);
    kk_string_drop(sub, _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
  kk_std_core__sslice _b_22702_22701;
  size_t _x24557 = kk_std_core_decr_1(i, _ctx); /*size_t*/
  size_t _x24558 = kk_string_len(sub,kk_context()); /*size_t*/
  _b_22702_22701 = kk_std_core__new_Sslice(s, _x24557, _x24558, _ctx); /*sslice*/
  return kk_std_core_types__new_Just(kk_std_core__sslice_box(_b_22702_22701, _ctx), _ctx);
}
 
// monadic lift

kk_std_core__list kk_std_core__mlift21206_op(kk_std_core_types__ctail _acc, kk_function_t f, kk_std_core__list xx, kk_std_core_types__maybe _y_151, kk_context_t* _ctx) { /* forall<a,b,e> (ctail<list<b>>, f : (a) -> e maybe<b>, xx : list<a>, maybe<b>) -> e list<b> */ 
  if (kk_std_core_types__is_Just(_y_151)) {
    kk_box_t y = _y_151._cons.Just.value;
    kk_std_core__list _ctail_21139 = kk_std_core__list_hole(); /*list<14928>*/;
    kk_std_core__list _ctail_21140 = kk_std_core__new_Cons(kk_reuse_null, y, _ctail_21139, _ctx); /*list<14928>*/;
    kk_std_core_types__ctail _x24561;
    kk_box_t* field_21615 = (kk_box_t*)((&kk_std_core__as_Cons(_ctail_21140)->tail)); /*cfield<list<14928>>*/;
    if (kk_std_core_types__is_CTail(_acc)) {
      kk_box_t _box_x22709 = _acc._cons.CTail._field1;
      kk_box_t* last0 = _acc._cons.CTail._field2;
      kk_std_core__list head0 = kk_std_core__list_unbox(_box_x22709, NULL);
      kk_std_core__list_dup(head0);
      kk_std_core_types__ctail_drop(_acc, _ctx);
      kk_unit_t __ = kk_Unit;
      *(last0) = kk_std_core__list_box(_ctail_21140, _ctx);
      _x24561 = kk_std_core_types__new_CTail(kk_std_core__list_box(head0, _ctx), field_21615, _ctx); /*ctail<58>*/
      goto _match24562;
    }
    _x24561 = kk_std_core_types__new_CTail(kk_std_core__list_box(_ctail_21140, _ctx), field_21615, _ctx); /*ctail<58>*/
    _match24562: ;
    return kk_std_core__ctail_flatmap_maybe(xx, f, _x24561, _ctx);
  }
  return kk_std_core__ctail_flatmap_maybe(xx, f, _acc, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_core__mlift21207_op_fun24564__t {
  struct kk_function_s _base;
  kk_function_t _accm;
  kk_box_t y0;
};
static kk_std_core__list kk_std_core__mlift21207_op_fun24564(kk_function_t _fself, kk_std_core__list _ctail_21142, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_mlift21207_op_fun24564(kk_function_t _accm, kk_box_t y0, kk_context_t* _ctx) {
  struct kk_std_core__mlift21207_op_fun24564__t* _self = kk_function_alloc_as(struct kk_std_core__mlift21207_op_fun24564__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__mlift21207_op_fun24564, kk_context());
  _self->_accm = _accm;
  _self->y0 = y0;
  return &_self->_base;
}

static kk_std_core__list kk_std_core__mlift21207_op_fun24564(kk_function_t _fself, kk_std_core__list _ctail_21142, kk_context_t* _ctx) {
  struct kk_std_core__mlift21207_op_fun24564__t* _self = kk_function_as(struct kk_std_core__mlift21207_op_fun24564__t*, _fself);
  kk_function_t _accm = _self->_accm; /* (list<14928>) -> list<14928> */
  kk_box_t y0 = _self->y0; /* 14928 */
  kk_drop_match(_self, {kk_function_dup(_accm);kk_box_dup(y0);}, {}, _ctx)
  kk_std_core__list _x24565 = kk_std_core__new_Cons(kk_reuse_null, y0, _ctail_21142, _ctx); /*list<61>*/
  return kk_function_call(kk_std_core__list, (kk_function_t, kk_std_core__list, kk_context_t*), _accm, (_accm, _x24565, _ctx));
}

kk_std_core__list kk_std_core__mlift21207_op(kk_function_t _accm, kk_function_t f0, kk_std_core__list xx0, kk_std_core_types__maybe _y_156, kk_context_t* _ctx) { /* forall<a,b,e> ((list<b>) -> list<b>, f : (a) -> e maybe<b>, xx : list<a>, maybe<b>) -> e list<b> */ 
  if (kk_std_core_types__is_Just(_y_156)) {
    kk_box_t y0 = _y_156._cons.Just.value;
    return kk_std_core__ctailm_flatmap_maybe(xx0, f0, kk_std_core__new_mlift21207_op_fun24564(_accm, y0, _ctx), _ctx);
  }
  return kk_std_core__ctailm_flatmap_maybe(xx0, f0, _accm, _ctx);
}
 
// Concatenate the `Just` result elements from applying a function to all elements.


// lift anonymous function
struct kk_std_core__ctail_flatmap_maybe_fun24569__t {
  struct kk_function_s _base;
  kk_function_t f1;
  kk_std_core__list xx1;
  kk_std_core_types__ctail _acc0;
};
static kk_box_t kk_std_core__ctail_flatmap_maybe_fun24569(kk_function_t _fself, kk_box_t _b_22723, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_ctail_flatmap_maybe_fun24569(kk_function_t f1, kk_std_core__list xx1, kk_std_core_types__ctail _acc0, kk_context_t* _ctx) {
  struct kk_std_core__ctail_flatmap_maybe_fun24569__t* _self = kk_function_alloc_as(struct kk_std_core__ctail_flatmap_maybe_fun24569__t, 5, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__ctail_flatmap_maybe_fun24569, kk_context());
  _self->f1 = f1;
  _self->xx1 = xx1;
  _self->_acc0 = _acc0;
  return &_self->_base;
}

static kk_box_t kk_std_core__ctail_flatmap_maybe_fun24569(kk_function_t _fself, kk_box_t _b_22723, kk_context_t* _ctx) {
  struct kk_std_core__ctail_flatmap_maybe_fun24569__t* _self = kk_function_as(struct kk_std_core__ctail_flatmap_maybe_fun24569__t*, _fself);
  kk_function_t f1 = _self->f1; /* (14927) -> 14929 maybe<14928> */
  kk_std_core__list xx1 = _self->xx1; /* list<14927> */
  kk_std_core_types__ctail _acc0 = _self->_acc0; /* ctail<list<14928>> */
  kk_drop_match(_self, {kk_function_dup(f1);kk_std_core__list_dup(xx1);kk_std_core_types__ctail_dup(_acc0);}, {}, _ctx)
  kk_std_core__list _x24570;
  kk_std_core_types__maybe _x24571 = kk_std_core_types__maybe_unbox(_b_22723, _ctx); /*maybe<14928>*/
  _x24570 = kk_std_core__mlift21206_op(_acc0, f1, xx1, _x24571, _ctx); /*list<14928>*/
  return kk_std_core__list_box(_x24570, _ctx);
}

kk_std_core__list kk_std_core__ctail_flatmap_maybe(kk_std_core__list xs, kk_function_t f1, kk_std_core_types__ctail _acc0, kk_context_t* _ctx) { /* forall<a,b,e> (xs : list<a>, f : (a) -> e maybe<b>, ctail<list<b>>) -> e list<b> */ 
  kk__tailcall: ;
  if (kk_std_core__is_Cons(xs)) {
    struct kk_std_core_Cons* _con24566 = kk_std_core__as_Cons(xs);
    kk_box_t x = _con24566->head;
    kk_std_core__list xx1 = _con24566->tail;
    kk_reuse_t _ru_23370 = kk_reuse_null; /*reuse*/;
    if (kk_std_core__list_is_unique(xs)) {
      _ru_23370 = (kk_std_core__list_reuse(xs));
    }
    else {
      kk_box_dup(x);
      kk_std_core__list_dup(xx1);
      kk_std_core__list_decref(xs, _ctx);
      _ru_23370 = kk_reuse_null;
    }
    kk_std_core_types__maybe x0_21616;
    kk_function_t _x24567 = kk_function_dup(f1); /*(14927) -> 14929 maybe<14928>*/
    x0_21616 = kk_function_call(kk_std_core_types__maybe, (kk_function_t, kk_box_t, kk_context_t*), _x24567, (_x24567, x, _ctx)); /*maybe<14928>*/
    if (kk_yielding(kk_context())) {
      kk_reuse_drop(_ru_23370, _ctx);
      kk_std_core_types__maybe_drop(x0_21616, _ctx);
      kk_box_t _x24568 = kk_std_core_hnd_yield_extend(kk_std_core__new_ctail_flatmap_maybe_fun24569(f1, xx1, _acc0, _ctx), _ctx); /*3991*/
      return kk_std_core__list_unbox(_x24568, _ctx);
    }
    if (kk_std_core_types__is_Just(x0_21616)) {
      kk_box_t y1 = x0_21616._cons.Just.value;
      kk_std_core__list _ctail_211390 = kk_std_core__list_hole(); /*list<14928>*/;
      kk_std_core__list _ctail_211400 = kk_std_core__new_Cons(_ru_23370, y1, _ctail_211390, _ctx); /*list<14928>*/;
      { // tailcall
        kk_std_core_types__ctail _x24572;
        kk_box_t* field_21622 = (kk_box_t*)((&kk_std_core__as_Cons(_ctail_211400)->tail)); /*cfield<list<14928>>*/;
        if (kk_std_core_types__is_CTail(_acc0)) {
          kk_box_t _box_x22730 = _acc0._cons.CTail._field1;
          kk_box_t* last2 = _acc0._cons.CTail._field2;
          kk_std_core__list head1 = kk_std_core__list_unbox(_box_x22730, NULL);
          kk_std_core__list_dup(head1);
          kk_std_core_types__ctail_drop(_acc0, _ctx);
          kk_unit_t __0 = kk_Unit;
          *(last2) = kk_std_core__list_box(_ctail_211400, _ctx);
          _x24572 = kk_std_core_types__new_CTail(kk_std_core__list_box(head1, _ctx), field_21622, _ctx); /*ctail<58>*/
          goto _match24573;
        }
        _x24572 = kk_std_core_types__new_CTail(kk_std_core__list_box(_ctail_211400, _ctx), field_21622, _ctx); /*ctail<58>*/
        _match24573: ;
        xs = xx1;
        _acc0 = _x24572;
        goto kk__tailcall;
      }
    }
    kk_reuse_drop(_ru_23370, _ctx);
    { // tailcall
      xs = xx1;
      goto kk__tailcall;
    }
  }
  kk_function_drop(f1, _ctx);
  if (kk_std_core_types__is_CTail(_acc0)) {
    kk_box_t _box_x22739 = _acc0._cons.CTail._field1;
    kk_box_t* last00 = _acc0._cons.CTail._field2;
    kk_std_core__list head00 = kk_std_core__list_unbox(_box_x22739, NULL);
    kk_std_core__list_dup(head00);
    kk_std_core_types__ctail_drop(_acc0, _ctx);
    kk_unit_t __00 = kk_Unit;
    *(last00) = kk_std_core__list_box(kk_std_core__new_Nil(_ctx), _ctx);
    return head00;
  }
  return kk_std_core__new_Nil(_ctx);
}
 
// Concatenate the `Just` result elements from applying a function to all elements.


// lift anonymous function
struct kk_std_core__ctailm_flatmap_maybe_fun24579__t {
  struct kk_function_s _base;
  kk_function_t _accm0;
  kk_function_t f2;
  kk_std_core__list xx2;
};
static kk_box_t kk_std_core__ctailm_flatmap_maybe_fun24579(kk_function_t _fself, kk_box_t _b_22751, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_ctailm_flatmap_maybe_fun24579(kk_function_t _accm0, kk_function_t f2, kk_std_core__list xx2, kk_context_t* _ctx) {
  struct kk_std_core__ctailm_flatmap_maybe_fun24579__t* _self = kk_function_alloc_as(struct kk_std_core__ctailm_flatmap_maybe_fun24579__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__ctailm_flatmap_maybe_fun24579, kk_context());
  _self->_accm0 = _accm0;
  _self->f2 = f2;
  _self->xx2 = xx2;
  return &_self->_base;
}

static kk_box_t kk_std_core__ctailm_flatmap_maybe_fun24579(kk_function_t _fself, kk_box_t _b_22751, kk_context_t* _ctx) {
  struct kk_std_core__ctailm_flatmap_maybe_fun24579__t* _self = kk_function_as(struct kk_std_core__ctailm_flatmap_maybe_fun24579__t*, _fself);
  kk_function_t _accm0 = _self->_accm0; /* (list<14928>) -> list<14928> */
  kk_function_t f2 = _self->f2; /* (14927) -> 14929 maybe<14928> */
  kk_std_core__list xx2 = _self->xx2; /* list<14927> */
  kk_drop_match(_self, {kk_function_dup(_accm0);kk_function_dup(f2);kk_std_core__list_dup(xx2);}, {}, _ctx)
  kk_std_core__list _x24580;
  kk_std_core_types__maybe _x24581 = kk_std_core_types__maybe_unbox(_b_22751, _ctx); /*maybe<14928>*/
  _x24580 = kk_std_core__mlift21207_op(_accm0, f2, xx2, _x24581, _ctx); /*list<14928>*/
  return kk_std_core__list_box(_x24580, _ctx);
}


// lift anonymous function
struct kk_std_core__ctailm_flatmap_maybe_fun24583__t {
  struct kk_function_s _base;
  kk_function_t _accm0;
  kk_box_t y2;
};
static kk_std_core__list kk_std_core__ctailm_flatmap_maybe_fun24583(kk_function_t _fself, kk_std_core__list _ctail_211420, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_ctailm_flatmap_maybe_fun24583(kk_function_t _accm0, kk_box_t y2, kk_context_t* _ctx) {
  struct kk_std_core__ctailm_flatmap_maybe_fun24583__t* _self = kk_function_alloc_as(struct kk_std_core__ctailm_flatmap_maybe_fun24583__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__ctailm_flatmap_maybe_fun24583, kk_context());
  _self->_accm0 = _accm0;
  _self->y2 = y2;
  return &_self->_base;
}

static kk_std_core__list kk_std_core__ctailm_flatmap_maybe_fun24583(kk_function_t _fself, kk_std_core__list _ctail_211420, kk_context_t* _ctx) {
  struct kk_std_core__ctailm_flatmap_maybe_fun24583__t* _self = kk_function_as(struct kk_std_core__ctailm_flatmap_maybe_fun24583__t*, _fself);
  kk_function_t _accm0 = _self->_accm0; /* (list<14928>) -> list<14928> */
  kk_box_t y2 = _self->y2; /* 14928 */
  kk_drop_match(_self, {kk_function_dup(_accm0);kk_box_dup(y2);}, {}, _ctx)
  kk_std_core__list _x24584 = kk_std_core__new_Cons(kk_reuse_null, y2, _ctail_211420, _ctx); /*list<61>*/
  return kk_function_call(kk_std_core__list, (kk_function_t, kk_std_core__list, kk_context_t*), _accm0, (_accm0, _x24584, _ctx));
}

kk_std_core__list kk_std_core__ctailm_flatmap_maybe(kk_std_core__list xs0, kk_function_t f2, kk_function_t _accm0, kk_context_t* _ctx) { /* forall<a,b,e> (xs : list<a>, f : (a) -> e maybe<b>, (list<b>) -> list<b>) -> e list<b> */ 
  kk__tailcall: ;
  if (kk_std_core__is_Cons(xs0)) {
    struct kk_std_core_Cons* _con24576 = kk_std_core__as_Cons(xs0);
    kk_box_t x0 = _con24576->head;
    kk_std_core__list xx2 = _con24576->tail;
    if (kk_std_core__list_is_unique(xs0)) {
      kk_std_core__list_free(xs0);
    }
    else {
      kk_box_dup(x0);
      kk_std_core__list_dup(xx2);
      kk_std_core__list_decref(xs0, _ctx);
    }
    kk_std_core_types__maybe x0_21625;
    kk_function_t _x24577 = kk_function_dup(f2); /*(14927) -> 14929 maybe<14928>*/
    x0_21625 = kk_function_call(kk_std_core_types__maybe, (kk_function_t, kk_box_t, kk_context_t*), _x24577, (_x24577, x0, _ctx)); /*maybe<14928>*/
    if (kk_yielding(kk_context())) {
      kk_std_core_types__maybe_drop(x0_21625, _ctx);
      kk_box_t _x24578 = kk_std_core_hnd_yield_extend(kk_std_core__new_ctailm_flatmap_maybe_fun24579(_accm0, f2, xx2, _ctx), _ctx); /*3991*/
      return kk_std_core__list_unbox(_x24578, _ctx);
    }
    if (kk_std_core_types__is_Just(x0_21625)) {
      kk_box_t y2 = x0_21625._cons.Just.value;
      { // tailcall
        kk_function_t _x24582 = kk_std_core__new_ctailm_flatmap_maybe_fun24583(_accm0, y2, _ctx); /*(list<14928>) -> list<14928>*/
        xs0 = xx2;
        _accm0 = _x24582;
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
struct kk_std_core_flatmap_maybe_fun24585__t {
  struct kk_function_s _base;
};
static kk_std_core__list kk_std_core_flatmap_maybe_fun24585(kk_function_t _fself, kk_std_core__list _ctail_21141, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_flatmap_maybe_fun24585(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_flatmap_maybe_fun24585, _ctx)
  return kk_function_dup(_fself);
}

static kk_std_core__list kk_std_core_flatmap_maybe_fun24585(kk_function_t _fself, kk_std_core__list _ctail_21141, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return _ctail_21141;
}

kk_std_core__list kk_std_core_flatmap_maybe(kk_std_core__list xs1, kk_function_t f3, kk_context_t* _ctx) { /* forall<a,b,e> (xs : list<a>, f : (a) -> e maybe<b>) -> e list<b> */ 
  bool _match_23500 = kk_std_core_hnd__evv_is_affine(_ctx); /*bool*/;
  if (_match_23500) {
    return kk_std_core__ctail_flatmap_maybe(xs1, f3, kk_std_core_types__new_CTailNil(_ctx), _ctx);
  }
  return kk_std_core__ctailm_flatmap_maybe(xs1, f3, kk_std_core_new_flatmap_maybe_fun24585(_ctx), _ctx);
}

kk_box_t kk_std_core_fold_int(kk_integer_t start0, kk_integer_t end, kk_box_t init0, kk_function_t f, kk_context_t* _ctx) { /* forall<a> (start : int, end : int, init : a, f : (int, a) -> a) -> a */ 
  kk__tailcall: ;
  bool _match_23499;
  kk_integer_t _x24586 = kk_integer_dup(start0); /*int*/
  kk_integer_t _x24587 = kk_integer_dup(end); /*int*/
  _match_23499 = kk_integer_gte(_x24586,_x24587,kk_context()); /*bool*/
  if (_match_23499) {
    kk_integer_drop(end, _ctx);
    kk_function_drop(f, _ctx);
    kk_integer_drop(start0, _ctx);
    return init0;
  }
  kk_box_t x;
  kk_function_t _x24589 = kk_function_dup(f); /*(int, 15007) -> 15007*/
  kk_integer_t _x24588 = kk_integer_dup(start0); /*int*/
  x = kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_box_t, kk_context_t*), _x24589, (_x24589, _x24588, init0, _ctx)); /*15007*/
  { // tailcall
    kk_integer_t _x24590 = kk_std_core_inc(start0, _ctx); /*int*/
    start0 = _x24590;
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
struct kk_std_core_foldl_fun24593__t {
  struct kk_function_s _base;
  kk_function_t f0;
  kk_std_core__list xx0;
};
static kk_box_t kk_std_core_foldl_fun24593(kk_function_t _fself, kk_box_t _y_1640, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_foldl_fun24593(kk_function_t f0, kk_std_core__list xx0, kk_context_t* _ctx) {
  struct kk_std_core_foldl_fun24593__t* _self = kk_function_alloc_as(struct kk_std_core_foldl_fun24593__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_foldl_fun24593, kk_context());
  _self->f0 = f0;
  _self->xx0 = xx0;
  return &_self->_base;
}

static kk_box_t kk_std_core_foldl_fun24593(kk_function_t _fself, kk_box_t _y_1640, kk_context_t* _ctx) {
  struct kk_std_core_foldl_fun24593__t* _self = kk_function_as(struct kk_std_core_foldl_fun24593__t*, _fself);
  kk_function_t f0 = _self->f0; /* (15010, 15015) -> 15012 15010 */
  kk_std_core__list xx0 = _self->xx0; /* list<15015> */
  kk_drop_match(_self, {kk_function_dup(f0);kk_std_core__list_dup(xx0);}, {}, _ctx)
  return kk_std_core__mlift21208_foldl(f0, xx0, _y_1640, _ctx);
}

kk_box_t kk_std_core_foldl(kk_std_core__list xs, kk_box_t z, kk_function_t f0, kk_context_t* _ctx) { /* forall<a,b,e> (list<a>, b, (b, a) -> e b) -> e b */ 
  kk__tailcall: ;
  if (kk_std_core__is_Cons(xs)) {
    struct kk_std_core_Cons* _con24591 = kk_std_core__as_Cons(xs);
    kk_box_t x = _con24591->head;
    kk_std_core__list xx0 = _con24591->tail;
    if (kk_std_core__list_is_unique(xs)) {
      kk_std_core__list_free(xs);
    }
    else {
      kk_box_dup(x);
      kk_std_core__list_dup(xx0);
      kk_std_core__list_decref(xs, _ctx);
    }
    kk_box_t x0_21629;
    kk_function_t _x24592 = kk_function_dup(f0); /*(15010, 15015) -> 15012 15010*/
    x0_21629 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _x24592, (_x24592, z, x, _ctx)); /*15010*/
    if (kk_yielding(kk_context())) {
      kk_box_drop(x0_21629, _ctx);
      return kk_std_core_hnd_yield_extend(kk_std_core_new_foldl_fun24593(f0, xx0, _ctx), _ctx);
    }
    { // tailcall
      xs = xx0;
      z = x0_21629;
      goto kk__tailcall;
    }
  }
  kk_function_drop(f0, _ctx);
  return z;
}


// lift anonymous function
struct kk_std_core_foldl1_fun24605__t {
  struct kk_function_s _base;
  size_t i_21633;
};
static kk_box_t kk_std_core_foldl1_fun24605(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_foldl1_fun24605(size_t i_21633, kk_context_t* _ctx) {
  struct kk_std_core_foldl1_fun24605__t* _self = kk_function_alloc_as(struct kk_std_core_foldl1_fun24605__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_foldl1_fun24605, kk_context());
  _self->i_21633 = i_21633;
  return &_self->_base;
}

static kk_box_t kk_std_core_foldl1_fun24605(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_std_core_foldl1_fun24605__t* _self = kk_function_as(struct kk_std_core_foldl1_fun24605__t*, _fself);
  size_t i_21633 = _self->i_21633; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_21633, cont, res, _ctx);
}

kk_box_t kk_std_core_foldl1(kk_std_core__list xs, kk_function_t f, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, f : (a, a) -> <exn|e> a) -> <exn|e> a */ 
  if (kk_std_core__is_Cons(xs)) {
    struct kk_std_core_Cons* _con24594 = kk_std_core__as_Cons(xs);
    kk_box_t x = _con24594->head;
    kk_std_core__list xx = _con24594->tail;
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
  size_t i_21633;
  kk_std_core_hnd__htag _x24595 = kk_std_core_hnd__htag_dup(kk_std_core__tag_exn); /*std/core/hnd/htag<.hnd-exn>*/
  i_21633 = kk_std_core_hnd__evv_index(_x24595, _ctx); /*std/core/hnd/ev-index*/
  kk_evv_t w = kk_evv_swap_create1(i_21633,kk_context()); /*std/core/hnd/evv<<exn|15087>>*/;
  kk_box_t y;
  kk_std_core__exception exn_21561;
  kk_string_t _x24596;
  kk_define_string_literal(, _s24597, 33, "unexpected Nil in std/core/foldl1")
  _x24596 = kk_string_dup(_s24597); /*string*/
  kk_std_core__exception_info _x24598;
  kk_std_core_types__optional _match_23497 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
  if (kk_std_core_types__is_Optional(_match_23497)) {
    kk_box_t _box_x22754 = _match_23497._cons.Optional.value;
    kk_std_core__exception_info _info_14279 = kk_std_core__exception_info_unbox(_box_x22754, NULL);
    kk_std_core__exception_info_dup(_info_14279);
    kk_std_core_types__optional_drop(_match_23497, _ctx);
    _x24598 = _info_14279; /*exception-info*/
    goto _match24599;
  }
  _x24598 = kk_std_core__new_ExnError(_ctx); /*exception-info*/
  _match24599: ;
  exn_21561 = kk_std_core__new_Exception(_x24596, _x24598, _ctx); /*exception*/
  kk_std_core_hnd__ev ev_21562;
  size_t _x24601 = ((size_t)0); /*size_t*/
  ev_21562 = kk_evv_at(_x24601,kk_context()); /*std/core/hnd/ev<.hnd-exn>*/
  struct kk_std_core_hnd_Ev* _con24602 = kk_std_core_hnd__as_Ev(ev_21562);
  kk_std_core_hnd__marker m = _con24602->marker;
  kk_box_t _box_x22755 = _con24602->hnd;
  kk_std_core__hnd_exn h = kk_std_core__hnd_exn_unbox(_box_x22755, NULL);
  kk_std_core__hnd_exn_dup(h);
  kk_std_core_hnd__clause1 _match_23496;
  struct kk_std_core__Hnd_exn* _con24604 = kk_std_core__as_Hnd_exn(h);
  kk_std_core_hnd__clause1 except_throw_exn = _con24604->except_throw_exn;
  if (kk_std_core__hnd_exn_is_unique(h)) {
    kk_std_core__hnd_exn_free(h);
  }
  else {
    kk_std_core_hnd__clause1_dup(except_throw_exn);
    kk_std_core__hnd_exn_decref(h, _ctx);
  }
  _match_23496 = except_throw_exn; /*forall<a> std/core/hnd/clause1<exception,a,.hnd-exn,3528,3529>*/
  kk_function_t _fun_unbox_x22759 = _match_23496.clause;
  y = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x22759, (_fun_unbox_x22759, m, ev_21562, kk_std_core__exception_box(exn_21561, _ctx), _ctx)); /*15086*/
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_drop(y, _ctx);
    return kk_std_core_hnd_yield_cont(kk_std_core_new_foldl1_fun24605(i_21633, _ctx), _ctx);
  }
  return y;
}
extern kk_box_t kk_std_core_foldr_fun24607(kk_function_t _fself, kk_box_t x, kk_box_t y, kk_context_t* _ctx) {
  struct kk_std_core_foldr_fun24607__t* _self = kk_function_as(struct kk_std_core_foldr_fun24607__t*, _fself);
  kk_function_t f = _self->f; /* (15105, 15101) -> 15103 15101 */
  kk_drop_match(_self, {kk_function_dup(f);}, {}, _ctx)
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), f, (f, y, x, _ctx));
}


// lift anonymous function
struct kk_std_core_foldr1_fun24619__t {
  struct kk_function_s _base;
  size_t i_21641;
};
static kk_box_t kk_std_core_foldr1_fun24619(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_foldr1_fun24619(size_t i_21641, kk_context_t* _ctx) {
  struct kk_std_core_foldr1_fun24619__t* _self = kk_function_alloc_as(struct kk_std_core_foldr1_fun24619__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_foldr1_fun24619, kk_context());
  _self->i_21641 = i_21641;
  return &_self->_base;
}

static kk_box_t kk_std_core_foldr1_fun24619(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_std_core_foldr1_fun24619__t* _self = kk_function_as(struct kk_std_core_foldr1_fun24619__t*, _fself);
  size_t i_21641 = _self->i_21641; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_21641, cont, res, _ctx);
}

kk_box_t kk_std_core_foldr1(kk_std_core__list xs, kk_function_t f, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, f : (a, a) -> <exn|e> a) -> <exn|e> a */ 
  kk_std_core__list xs0_21639 = kk_std_core_reverse(xs, _ctx); /*list<15139>*/;
  if (kk_std_core__is_Cons(xs0_21639)) {
    struct kk_std_core_Cons* _con24608 = kk_std_core__as_Cons(xs0_21639);
    kk_box_t x = _con24608->head;
    kk_std_core__list xx = _con24608->tail;
    if (kk_std_core__list_is_unique(xs0_21639)) {
      kk_std_core__list_free(xs0_21639);
    }
    else {
      kk_box_dup(x);
      kk_std_core__list_dup(xx);
      kk_std_core__list_decref(xs0_21639, _ctx);
    }
    return kk_std_core_foldl(xx, x, f, _ctx);
  }
  kk_function_drop(f, _ctx);
  size_t i_21641;
  kk_std_core_hnd__htag _x24609 = kk_std_core_hnd__htag_dup(kk_std_core__tag_exn); /*std/core/hnd/htag<.hnd-exn>*/
  i_21641 = kk_std_core_hnd__evv_index(_x24609, _ctx); /*std/core/hnd/ev-index*/
  kk_evv_t w = kk_evv_swap_create1(i_21641,kk_context()); /*std/core/hnd/evv<<exn|15140>>*/;
  kk_box_t y;
  kk_std_core__exception exn_21561;
  kk_string_t _x24610;
  kk_define_string_literal(, _s24611, 33, "unexpected Nil in std/core/foldl1")
  _x24610 = kk_string_dup(_s24611); /*string*/
  kk_std_core__exception_info _x24612;
  kk_std_core_types__optional _match_23494 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
  if (kk_std_core_types__is_Optional(_match_23494)) {
    kk_box_t _box_x22766 = _match_23494._cons.Optional.value;
    kk_std_core__exception_info _info_14279 = kk_std_core__exception_info_unbox(_box_x22766, NULL);
    kk_std_core__exception_info_dup(_info_14279);
    kk_std_core_types__optional_drop(_match_23494, _ctx);
    _x24612 = _info_14279; /*exception-info*/
    goto _match24613;
  }
  _x24612 = kk_std_core__new_ExnError(_ctx); /*exception-info*/
  _match24613: ;
  exn_21561 = kk_std_core__new_Exception(_x24610, _x24612, _ctx); /*exception*/
  kk_std_core_hnd__ev ev_21562;
  size_t _x24615 = ((size_t)0); /*size_t*/
  ev_21562 = kk_evv_at(_x24615,kk_context()); /*std/core/hnd/ev<.hnd-exn>*/
  struct kk_std_core_hnd_Ev* _con24616 = kk_std_core_hnd__as_Ev(ev_21562);
  kk_std_core_hnd__marker m = _con24616->marker;
  kk_box_t _box_x22767 = _con24616->hnd;
  kk_std_core__hnd_exn h = kk_std_core__hnd_exn_unbox(_box_x22767, NULL);
  kk_std_core__hnd_exn_dup(h);
  kk_std_core_hnd__clause1 _match_23493;
  struct kk_std_core__Hnd_exn* _con24618 = kk_std_core__as_Hnd_exn(h);
  kk_std_core_hnd__clause1 except_throw_exn = _con24618->except_throw_exn;
  if (kk_std_core__hnd_exn_is_unique(h)) {
    kk_std_core__hnd_exn_free(h);
  }
  else {
    kk_std_core_hnd__clause1_dup(except_throw_exn);
    kk_std_core__hnd_exn_decref(h, _ctx);
  }
  _match_23493 = except_throw_exn; /*forall<a> std/core/hnd/clause1<exception,a,.hnd-exn,3528,3529>*/
  kk_function_t _fun_unbox_x22771 = _match_23493.clause;
  y = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x22771, (_fun_unbox_x22771, m, ev_21562, kk_std_core__exception_box(exn_21561, _ctx), _ctx)); /*15139*/
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_drop(y, _ctx);
    return kk_std_core_hnd_yield_cont(kk_std_core_new_foldr1_fun24619(i_21641, _ctx), _ctx);
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
struct kk_std_core__lift21056_for_fun24625__t {
  struct kk_function_s _base;
  kk_function_t action0;
  kk_integer_t end0;
  kk_integer_t i0;
};
static kk_box_t kk_std_core__lift21056_for_fun24625(kk_function_t _fself, kk_box_t _b_22779, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_lift21056_for_fun24625(kk_function_t action0, kk_integer_t end0, kk_integer_t i0, kk_context_t* _ctx) {
  struct kk_std_core__lift21056_for_fun24625__t* _self = kk_function_alloc_as(struct kk_std_core__lift21056_for_fun24625__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__lift21056_for_fun24625, kk_context());
  _self->action0 = action0;
  _self->end0 = end0;
  _self->i0 = i0;
  return &_self->_base;
}

static kk_box_t kk_std_core__lift21056_for_fun24625(kk_function_t _fself, kk_box_t _b_22779, kk_context_t* _ctx) {
  struct kk_std_core__lift21056_for_fun24625__t* _self = kk_function_as(struct kk_std_core__lift21056_for_fun24625__t*, _fself);
  kk_function_t action0 = _self->action0; /* (int) -> 15141 () */
  kk_integer_t end0 = _self->end0; /* int */
  kk_integer_t i0 = _self->i0; /* int */
  kk_drop_match(_self, {kk_function_dup(action0);kk_integer_dup(end0);kk_integer_dup(i0);}, {}, _ctx)
  kk_unit_t _x24626 = kk_Unit;
  kk_unit_t _x24627 = kk_Unit;
  kk_unit_unbox(_b_22779);
  kk_std_core__mlift21209_op(action0, end0, i0, _x24627, _ctx);
  return kk_unit_box(_x24626);
}

kk_unit_t kk_std_core__lift21056_for(kk_function_t action0, kk_integer_t end0, kk_integer_t i0, kk_context_t* _ctx) { /* forall<e> (action : (int) -> e (), end : int, i : int) -> e () */ 
  kk__tailcall: ;
  bool _match_23490;
  kk_integer_t _x24620 = kk_integer_dup(i0); /*int*/
  kk_integer_t _x24621 = kk_integer_dup(end0); /*int*/
  _match_23490 = kk_integer_lte(_x24620,_x24621,kk_context()); /*bool*/
  if (_match_23490) {
    kk_unit_t x_21645 = kk_Unit;
    kk_function_t _x24623 = kk_function_dup(action0); /*(int) -> 15141 ()*/
    kk_integer_t _x24622 = kk_integer_dup(i0); /*int*/
    kk_function_call(kk_unit_t, (kk_function_t, kk_integer_t, kk_context_t*), _x24623, (_x24623, _x24622, _ctx));
    if (kk_yielding(kk_context())) {
      kk_box_t _x24624 = kk_std_core_hnd_yield_extend(kk_std_core__new_lift21056_for_fun24625(action0, end0, i0, _ctx), _ctx); /*3991*/
      kk_unit_unbox(_x24624); return kk_Unit;
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
struct kk_std_core__lift21057_for_while_fun24633__t {
  struct kk_function_s _base;
  kk_function_t action0;
  kk_integer_t end0;
  kk_integer_t i0;
};
static kk_box_t kk_std_core__lift21057_for_while_fun24633(kk_function_t _fself, kk_box_t _b_22783, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_lift21057_for_while_fun24633(kk_function_t action0, kk_integer_t end0, kk_integer_t i0, kk_context_t* _ctx) {
  struct kk_std_core__lift21057_for_while_fun24633__t* _self = kk_function_alloc_as(struct kk_std_core__lift21057_for_while_fun24633__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__lift21057_for_while_fun24633, kk_context());
  _self->action0 = action0;
  _self->end0 = end0;
  _self->i0 = i0;
  return &_self->_base;
}

static kk_box_t kk_std_core__lift21057_for_while_fun24633(kk_function_t _fself, kk_box_t _b_22783, kk_context_t* _ctx) {
  struct kk_std_core__lift21057_for_while_fun24633__t* _self = kk_function_as(struct kk_std_core__lift21057_for_while_fun24633__t*, _fself);
  kk_function_t action0 = _self->action0; /* (int) -> 15194 maybe<15193> */
  kk_integer_t end0 = _self->end0; /* int */
  kk_integer_t i0 = _self->i0; /* int */
  kk_drop_match(_self, {kk_function_dup(action0);kk_integer_dup(end0);kk_integer_dup(i0);}, {}, _ctx)
  kk_std_core_types__maybe _x24634;
  kk_std_core_types__maybe _x24635 = kk_std_core_types__maybe_unbox(_b_22783, _ctx); /*maybe<15193>*/
  _x24634 = kk_std_core__mlift21210_op(action0, end0, i0, _x24635, _ctx); /*maybe<15193>*/
  return kk_std_core_types__maybe_box(_x24634, _ctx);
}

kk_std_core_types__maybe kk_std_core__lift21057_for_while(kk_function_t action0, kk_integer_t end0, kk_integer_t i0, kk_context_t* _ctx) { /* forall<a,e> (action : (int) -> e maybe<a>, end : int, i : int) -> e maybe<a> */ 
  kk__tailcall: ;
  bool _match_23488;
  kk_integer_t _x24628 = kk_integer_dup(i0); /*int*/
  kk_integer_t _x24629 = kk_integer_dup(end0); /*int*/
  _match_23488 = kk_integer_lte(_x24628,_x24629,kk_context()); /*bool*/
  if (_match_23488) {
    kk_std_core_types__maybe x_21649;
    kk_function_t _x24631 = kk_function_dup(action0); /*(int) -> 15194 maybe<15193>*/
    kk_integer_t _x24630 = kk_integer_dup(i0); /*int*/
    x_21649 = kk_function_call(kk_std_core_types__maybe, (kk_function_t, kk_integer_t, kk_context_t*), _x24631, (_x24631, _x24630, _ctx)); /*maybe<15193>*/
    if (kk_yielding(kk_context())) {
      kk_std_core_types__maybe_drop(x_21649, _ctx);
      kk_box_t _x24632 = kk_std_core_hnd_yield_extend(kk_std_core__new_lift21057_for_while_fun24633(action0, end0, i0, _ctx), _ctx); /*3991*/
      return kk_std_core_types__maybe_unbox(_x24632, _ctx);
    }
    if (kk_std_core_types__is_Nothing(x_21649)) {
      kk_integer_t i0_210870 = kk_std_core_inc(i0, _ctx); /*int*/;
      { // tailcall
        i0 = i0_210870;
        goto kk__tailcall;
      }
    }
    kk_box_t x0 = x_21649._cons.Just.value;
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
  kk_integer_t _b_22789_22787 = kk_integer_add(_y_185,(kk_integer_from_small(1)),kk_context()); /*int*/;
  (kk_ref_set(i,(kk_integer_box(_b_22789_22787)),kk_context())); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_std_core__mlift21212_foreach_indexed_fun24639__t {
  struct kk_function_s _base;
  kk_ref_t i;
};
static kk_box_t kk_std_core__mlift21212_foreach_indexed_fun24639(kk_function_t _fself, kk_box_t _b_22793, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_mlift21212_foreach_indexed_fun24639(kk_ref_t i, kk_context_t* _ctx) {
  struct kk_std_core__mlift21212_foreach_indexed_fun24639__t* _self = kk_function_alloc_as(struct kk_std_core__mlift21212_foreach_indexed_fun24639__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__mlift21212_foreach_indexed_fun24639, kk_context());
  _self->i = i;
  return &_self->_base;
}

static kk_box_t kk_std_core__mlift21212_foreach_indexed_fun24639(kk_function_t _fself, kk_box_t _b_22793, kk_context_t* _ctx) {
  struct kk_std_core__mlift21212_foreach_indexed_fun24639__t* _self = kk_function_as(struct kk_std_core__mlift21212_foreach_indexed_fun24639__t*, _fself);
  kk_ref_t i = _self->i; /* local-var<15373,int> */
  kk_drop_match(_self, {kk_ref_dup(i);}, {}, _ctx)
  kk_unit_t _x24640 = kk_Unit;
  kk_integer_t _x24641 = kk_integer_unbox(_b_22793); /*int*/
  kk_std_core__mlift21211_foreach_indexed(i, _x24641, _ctx);
  return kk_unit_box(_x24640);
}

kk_unit_t kk_std_core__mlift21212_foreach_indexed(kk_ref_t i, kk_unit_t wild__, kk_context_t* _ctx) { /* forall<h,e> (i : local-var<h,int>, wild_ : ()) -> <local<h>|e> () */ 
  kk_integer_t x_21653;
  kk_box_t _x24636;
  kk_ref_t _x24637 = kk_ref_dup(i); /*local-var<15373,int>*/
  _x24636 = (kk_ref_get(_x24637,kk_context())); /*228*/
  x_21653 = kk_integer_unbox(_x24636); /*int*/
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_21653, _ctx);
    kk_box_t _x24638 = kk_std_core_hnd_yield_extend(kk_std_core__new_mlift21212_foreach_indexed_fun24639(i, _ctx), _ctx); /*3991*/
    kk_unit_unbox(_x24638); return kk_Unit;
  }
  kk_std_core__mlift21211_foreach_indexed(i, x_21653, _ctx); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_std_core__mlift21213_foreach_indexed_fun24643__t {
  struct kk_function_s _base;
  kk_ref_t i;
};
static kk_box_t kk_std_core__mlift21213_foreach_indexed_fun24643(kk_function_t _fself, kk_box_t _b_22797, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_mlift21213_foreach_indexed_fun24643(kk_ref_t i, kk_context_t* _ctx) {
  struct kk_std_core__mlift21213_foreach_indexed_fun24643__t* _self = kk_function_alloc_as(struct kk_std_core__mlift21213_foreach_indexed_fun24643__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__mlift21213_foreach_indexed_fun24643, kk_context());
  _self->i = i;
  return &_self->_base;
}

static kk_box_t kk_std_core__mlift21213_foreach_indexed_fun24643(kk_function_t _fself, kk_box_t _b_22797, kk_context_t* _ctx) {
  struct kk_std_core__mlift21213_foreach_indexed_fun24643__t* _self = kk_function_as(struct kk_std_core__mlift21213_foreach_indexed_fun24643__t*, _fself);
  kk_ref_t i = _self->i; /* local-var<15373,int> */
  kk_drop_match(_self, {kk_ref_dup(i);}, {}, _ctx)
  kk_unit_t _x24644 = kk_Unit;
  kk_unit_t _x24645 = kk_Unit;
  kk_unit_unbox(_b_22797);
  kk_std_core__mlift21212_foreach_indexed(i, _x24645, _ctx);
  return kk_unit_box(_x24644);
}

kk_unit_t kk_std_core__mlift21213_foreach_indexed(kk_function_t action, kk_ref_t i, kk_box_t x, kk_integer_t j, kk_context_t* _ctx) { /* forall<h,a,e> (action : (int, a) -> e (), i : local-var<h,int>, x : a, j : int) -> <local<h>|e> () */ 
  kk_unit_t x0_21655 = kk_Unit;
  kk_function_call(kk_unit_t, (kk_function_t, kk_integer_t, kk_box_t, kk_context_t*), action, (action, j, x, _ctx));
  if (kk_yielding(kk_context())) {
    kk_box_t _x24642 = kk_std_core_hnd_yield_extend(kk_std_core__new_mlift21213_foreach_indexed_fun24643(i, _ctx), _ctx); /*3991*/
    kk_unit_unbox(_x24642); return kk_Unit;
  }
  kk_std_core__mlift21212_foreach_indexed(i, x0_21655, _ctx); return kk_Unit;
}
 
// Invoke `action` for each element of a list, passing also the position of the element.


// lift anonymous function
struct kk_std_core_foreach_indexed_fun24647__t {
  struct kk_function_s _base;
  kk_function_t action;
  kk_ref_t loc;
};
static kk_unit_t kk_std_core_foreach_indexed_fun24647(kk_function_t _fself, kk_box_t x, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_foreach_indexed_fun24647(kk_function_t action, kk_ref_t loc, kk_context_t* _ctx) {
  struct kk_std_core_foreach_indexed_fun24647__t* _self = kk_function_alloc_as(struct kk_std_core_foreach_indexed_fun24647__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_foreach_indexed_fun24647, kk_context());
  _self->action = action;
  _self->loc = loc;
  return &_self->_base;
}



// lift anonymous function
struct kk_std_core_foreach_indexed_fun24651__t {
  struct kk_function_s _base;
  kk_function_t action;
  kk_ref_t loc;
  kk_box_t x;
};
static kk_box_t kk_std_core_foreach_indexed_fun24651(kk_function_t _fself, kk_box_t _b_22805, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_foreach_indexed_fun24651(kk_function_t action, kk_ref_t loc, kk_box_t x, kk_context_t* _ctx) {
  struct kk_std_core_foreach_indexed_fun24651__t* _self = kk_function_alloc_as(struct kk_std_core_foreach_indexed_fun24651__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_foreach_indexed_fun24651, kk_context());
  _self->action = action;
  _self->loc = loc;
  _self->x = x;
  return &_self->_base;
}

static kk_box_t kk_std_core_foreach_indexed_fun24651(kk_function_t _fself, kk_box_t _b_22805, kk_context_t* _ctx) {
  struct kk_std_core_foreach_indexed_fun24651__t* _self = kk_function_as(struct kk_std_core_foreach_indexed_fun24651__t*, _fself);
  kk_function_t action = _self->action; /* (int, 15379) -> 15380 () */
  kk_ref_t loc = _self->loc; /* local-var<global,int> */
  kk_box_t x = _self->x; /* 15379 */
  kk_drop_match(_self, {kk_function_dup(action);kk_ref_dup(loc);kk_box_dup(x);}, {}, _ctx)
  kk_unit_t _x24652 = kk_Unit;
  kk_integer_t _x24653 = kk_integer_unbox(_b_22805); /*int*/
  kk_std_core__mlift21213_foreach_indexed(action, loc, x, _x24653, _ctx);
  return kk_unit_box(_x24652);
}
static kk_unit_t kk_std_core_foreach_indexed_fun24647(kk_function_t _fself, kk_box_t x, kk_context_t* _ctx) {
  struct kk_std_core_foreach_indexed_fun24647__t* _self = kk_function_as(struct kk_std_core_foreach_indexed_fun24647__t*, _fself);
  kk_function_t action = _self->action; /* (int, 15379) -> 15380 () */
  kk_ref_t loc = _self->loc; /* local-var<global,int> */
  kk_drop_match(_self, {kk_function_dup(action);kk_ref_dup(loc);}, {}, _ctx)
  kk_integer_t x0_21662;
  kk_box_t _x24648;
  kk_ref_t _x24649 = kk_ref_dup(loc); /*local-var<global,int>*/
  _x24648 = (kk_ref_get(_x24649,kk_context())); /*228*/
  x0_21662 = kk_integer_unbox(_x24648); /*int*/
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x0_21662, _ctx);
    kk_box_t _x24650 = kk_std_core_hnd_yield_extend(kk_std_core_new_foreach_indexed_fun24651(action, loc, x, _ctx), _ctx); /*3991*/
    return kk_unit_unbox(_x24650);
  }
  return kk_std_core__mlift21213_foreach_indexed(action, loc, x, x0_21662, _ctx);
}

kk_unit_t kk_std_core_foreach_indexed(kk_std_core__list xs, kk_function_t action, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, action : (int, a) -> e ()) -> e () */ 
  kk_ref_t loc = kk_ref_alloc((kk_integer_box(kk_integer_from_small(0))),kk_context()); /*local-var<global,int>*/;
  kk_unit_t res = kk_Unit;
  kk_function_t _x24646;
  kk_ref_dup(loc);
  _x24646 = kk_std_core_new_foreach_indexed_fun24647(action, loc, _ctx); /*(x : 15379) -> <local<global>|15380> ()*/
  kk_std_core_foreach(xs, _x24646, _ctx);
  kk_box_t _x24654 = kk_std_core_hnd_prompt_local_var(loc, kk_unit_box(res), _ctx); /*9788*/
  kk_unit_unbox(_x24654); return kk_Unit;
}
 
// Invoke a function `f` for each element in a vector `v`


// lift anonymous function
struct kk_std_core_foreach_indexed_fun24657__t_1 {
  struct kk_function_s _base;
  kk_function_t f;
  kk_vector_t v;
};
static kk_unit_t kk_std_core_foreach_indexed_fun24657_1(kk_function_t _fself, size_t i, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_foreach_indexed_fun24657_1(kk_function_t f, kk_vector_t v, kk_context_t* _ctx) {
  struct kk_std_core_foreach_indexed_fun24657__t_1* _self = kk_function_alloc_as(struct kk_std_core_foreach_indexed_fun24657__t_1, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_foreach_indexed_fun24657_1, kk_context());
  _self->f = f;
  _self->v = v;
  return &_self->_base;
}

static kk_unit_t kk_std_core_foreach_indexed_fun24657_1(kk_function_t _fself, size_t i, kk_context_t* _ctx) {
  struct kk_std_core_foreach_indexed_fun24657__t_1* _self = kk_function_as(struct kk_std_core_foreach_indexed_fun24657__t_1*, _fself);
  kk_function_t f = _self->f; /* (15418, int) -> 15419 () */
  kk_vector_t v = _self->v; /* vector<15418> */
  kk_drop_match(_self, {kk_function_dup(f);kk_vector_dup(v);}, {}, _ctx)
  kk_box_t x_21669 = kk_vector_at(v,i); /*15418*/;
  kk_integer_t _x24658 = kk_integer_from_size_t(i,kk_context()); /*int*/
  return kk_function_call(kk_unit_t, (kk_function_t, kk_box_t, kk_integer_t, kk_context_t*), f, (f, x_21669, _x24658, _ctx));
}

kk_unit_t kk_std_core_foreach_indexed_1(kk_vector_t v, kk_function_t f, kk_context_t* _ctx) { /* forall<a,e> (v : vector<a>, f : (a, int) -> e ()) -> e () */ 
  size_t start_21666 = ((size_t)0); /*size_t*/;
  size_t end_21667;
  size_t _x24655;
  kk_vector_t _x24656 = kk_vector_dup(v); /*vector<15418>*/
  _x24655 = kk_vector_len(_x24656); /*size_t*/
  end_21667 = kk_std_core_decr_1(_x24655, _ctx); /*size_t*/
  kk_std_core__lift21051_forz(kk_std_core_new_foreach_indexed_fun24657_1(f, v, _ctx), end_21667, start_21666, _ctx); return kk_Unit;
}
 
// Return the head of list if the list is not empty.

kk_std_core_types__maybe kk_std_core_head_1(kk_std_core__list xs, kk_context_t* _ctx) { /* forall<a> (xs : list<a>) -> maybe<a> */ 
  if (kk_std_core__is_Cons(xs)) {
    struct kk_std_core_Cons* _con24666 = kk_std_core__as_Cons(xs);
    kk_box_t x = _con24666->head;
    kk_std_core__list _pat0 = _con24666->tail;
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
    struct kk_std_core_Cons* _con24667 = kk_std_core__as_Cons(xs);
    kk_box_t x = _con24667->head;
    kk_std_core__list _pat0 = _con24667->tail;
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
  kk_std_core__sslice _x24668;
  kk_std_core__sslice slice0 = kk_std_core_first1(s, _ctx); /*sslice*/;
  bool _match_23482;
  kk_integer_t _x24669;
  kk_std_core_types__optional _match_23484 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
  if (kk_std_core_types__is_Optional(_match_23484)) {
    kk_box_t _box_x22812 = _match_23484._cons.Optional.value;
    kk_integer_t _n_12425 = kk_integer_unbox(_box_x22812);
    kk_integer_dup(_n_12425);
    kk_std_core_types__optional_drop(_match_23484, _ctx);
    _x24669 = _n_12425; /*int*/
    goto _match24670;
  }
  _x24669 = kk_integer_from_small(1); /*int*/
  _match24670: ;
  _match_23482 = kk_integer_eq(_x24669,(kk_integer_from_small(1)),kk_context()); /*bool*/
  if (_match_23482) {
    _x24668 = slice0; /*sslice*/
  }
  else {
    kk_integer_t _x24672;
    kk_integer_t _x24673;
    kk_std_core_types__optional _match_23483 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
    if (kk_std_core_types__is_Optional(_match_23483)) {
      kk_box_t _box_x22813 = _match_23483._cons.Optional.value;
      kk_integer_t _n_124250 = kk_integer_unbox(_box_x22813);
      kk_integer_dup(_n_124250);
      kk_std_core_types__optional_drop(_match_23483, _ctx);
      _x24673 = _n_124250; /*int*/
      goto _match24674;
    }
    _x24673 = kk_integer_from_small(1); /*int*/
    _match24674: ;
    _x24672 = kk_integer_sub(_x24673,(kk_integer_from_small(1)),kk_context()); /*int*/
    _x24668 = kk_std_core_extend(slice0, _x24672, _ctx); /*sslice*/
  }
  return kk_std_core_string_3(_x24668, _ctx);
}
extern kk_std_core_types__maybe kk_std_core_head_char_fun24677(kk_function_t _fself, kk_char_t _b_22814, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return kk_std_core_types__new_Just(kk_char_box(_b_22814, _ctx), _ctx);
}

kk_integer_t kk_std_core_index_of_acc(kk_std_core__list xs, kk_function_t pred, kk_integer_t idx, kk_context_t* _ctx) { /* forall<a> (xs : list<a>, pred : (a) -> bool, idx : int) -> int */ 
  kk__tailcall: ;
  if (kk_std_core__is_Nil(xs)) {
    kk_integer_drop(idx, _ctx);
    kk_function_drop(pred, _ctx);
    return kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context());
  }
  struct kk_std_core_Cons* _con24678 = kk_std_core__as_Cons(xs);
  kk_box_t x = _con24678->head;
  kk_std_core__list xx = _con24678->tail;
  if (kk_std_core__list_is_unique(xs)) {
    kk_std_core__list_free(xs);
  }
  else {
    kk_box_dup(x);
    kk_std_core__list_dup(xx);
    kk_std_core__list_decref(xs, _ctx);
  }
  bool _match_23481;
  kk_function_t _x24679 = kk_function_dup(pred); /*(15989) -> bool*/
  _match_23481 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_context_t*), _x24679, (_x24679, x, _ctx)); /*bool*/
  if (_match_23481) {
    kk_function_drop(pred, _ctx);
    kk_std_core__list_drop(xx, _ctx);
    return idx;
  }
  { // tailcall
    kk_integer_t _x24680 = kk_integer_add(idx,(kk_integer_from_small(1)),kk_context()); /*int*/
    xs = xx;
    idx = _x24680;
    goto kk__tailcall;
  }
}
 
// Return the list without its last element.
// Return an empty list for an empty list.

kk_std_core__list kk_std_core__ctail_init(kk_std_core__list xs, kk_std_core_types__ctail _acc, kk_context_t* _ctx) { /* forall<a> (xs : list<a>, ctail<list<a>>) -> list<a> */ 
  kk__tailcall: ;
  if (kk_std_core__is_Cons(xs)) {
    struct kk_std_core_Cons* _con24681 = kk_std_core__as_Cons(xs);
    kk_box_t x = _con24681->head;
    kk_std_core__list xx = _con24681->tail;
    if (kk_std_core__is_Cons(xx)) {
      struct kk_std_core_Cons* _con24682 = kk_std_core__as_Cons(xx);
      if (kk_std_core__list_is_unique(xs)) {
        kk_std_core__list_free(xs);
      }
      else {
        kk_box_dup(x);
        kk_std_core__list_dup(xx);
        kk_std_core__list_decref(xs, _ctx);
      }
      kk_reuse_t _ru_23383;
      kk_std_core__list _x24683 = kk_std_core__list_dup(xx); /*list<16026>*/
      _ru_23383 = kk_std_core__list_dropn_reuse(_x24683, ((int32_t)2), _ctx); /*reuse*/
      kk_std_core__list _ctail_21143 = kk_std_core__list_hole(); /*list<16026>*/;
      kk_std_core__list _ctail_21144 = kk_std_core__new_Cons(_ru_23383, x, _ctail_21143, _ctx); /*list<16026>*/;
      { // tailcall
        kk_std_core_types__ctail _x24684;
        kk_box_t* field_21680 = (kk_box_t*)((&kk_std_core__as_Cons(_ctail_21144)->tail)); /*cfield<list<16026>>*/;
        if (kk_std_core_types__is_CTail(_acc)) {
          kk_box_t _box_x22821 = _acc._cons.CTail._field1;
          kk_box_t* last0 = _acc._cons.CTail._field2;
          kk_std_core__list head0 = kk_std_core__list_unbox(_box_x22821, NULL);
          kk_std_core__list_dup(head0);
          kk_std_core_types__ctail_drop(_acc, _ctx);
          kk_unit_t __ = kk_Unit;
          *(last0) = kk_std_core__list_box(_ctail_21144, _ctx);
          _x24684 = kk_std_core_types__new_CTail(kk_std_core__list_box(head0, _ctx), field_21680, _ctx); /*ctail<58>*/
          goto _match24685;
        }
        _x24684 = kk_std_core_types__new_CTail(kk_std_core__list_box(_ctail_21144, _ctx), field_21680, _ctx); /*ctail<58>*/
        _match24685: ;
        xs = xx;
        _acc = _x24684;
        goto kk__tailcall;
      }
    }
  }
  kk_std_core__list_drop(xs, _ctx);
  if (kk_std_core_types__is_CTail(_acc)) {
    kk_box_t _box_x22830 = _acc._cons.CTail._field1;
    kk_box_t* last00 = _acc._cons.CTail._field2;
    kk_std_core__list head00 = kk_std_core__list_unbox(_box_x22830, NULL);
    kk_std_core__list_dup(head00);
    kk_std_core_types__ctail_drop(_acc, _ctx);
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
  bool _match_23472 = kk_std_core_is_digit(c, _ctx); /*bool*/;
  if (_match_23472) {
    return true;
  }
  bool _match_23473;
  bool _match_23475 = (c >= ('a')); /*bool*/;
  if (_match_23475) {
    _match_23473 = (c <= ('f')); /*bool*/
  }
  else {
    _match_23473 = false; /*bool*/
  }
  if (_match_23473) {
    return true;
  }
  bool _match_23474 = (c >= ('A')); /*bool*/;
  if (_match_23474) {
    return (c <= ('F'));
  }
  return false;
}
 
// Tests if a character is an element of `" \t\n\r"`

bool kk_std_core_is_white(kk_char_t c, kk_context_t* _ctx) { /* (c : char) -> bool */ 
  bool _match_23469 = (c == (' ')); /*bool*/;
  if (_match_23469) {
    return true;
  }
  bool _match_23470 = (c == 0x0009); /*bool*/;
  if (_match_23470) {
    return true;
  }
  bool _match_23471 = (c == 0x000A); /*bool*/;
  if (_match_23471) {
    return true;
  }
  return (c == 0x000D);
}
 
// Return the last element of a list (or `Nothing` for the empty list)

kk_std_core_types__maybe kk_std_core_last(kk_std_core__list xs, kk_context_t* _ctx) { /* forall<a> (xs : list<a>) -> maybe<a> */ 
  kk__tailcall: ;
  if (kk_std_core__is_Cons(xs)) {
    struct kk_std_core_Cons* _con24694 = kk_std_core__as_Cons(xs);
    kk_box_t x = _con24694->head;
    kk_std_core__list _pat0 = _con24694->tail;
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
    struct kk_std_core_Cons* _con24695 = kk_std_core__as_Cons(xs);
    kk_box_t _pat2 = _con24695->head;
    kk_std_core__list xx = _con24695->tail;
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
    struct kk_std_core_Cons* _con24696 = kk_std_core__as_Cons(xs);
    kk_box_t x = _con24696->head;
    kk_std_core__list _pat0 = _con24696->tail;
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
    struct kk_std_core_Cons* _con24697 = kk_std_core__as_Cons(xs);
    kk_box_t _pat2 = _con24697->head;
    kk_std_core__list xx = _con24697->tail;
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
  bool _match_23468;
  kk_integer_t _x24698;
  if (kk_std_core_types__is_Optional(n)) {
    kk_box_t _box_x22839 = n._cons.Optional.value;
    kk_integer_t _n_16953 = kk_integer_unbox(_box_x22839);
    kk_integer_dup(_n_16953);
    _x24698 = _n_16953; /*int*/
    goto _match24699;
  }
  _x24698 = kk_integer_from_small(1); /*int*/
  _match24699: ;
  _match_23468 = kk_integer_eq(_x24698,(kk_integer_from_small(1)),kk_context()); /*bool*/
  if (_match_23468) {
    kk_std_core_types__optional_drop(n, _ctx);
    return slice0;
  }
  kk_std_core__sslice _x24701;
  kk_integer_t _x24702;
  kk_integer_t _x24703;
  if (kk_std_core_types__is_Optional(n)) {
    kk_box_t _box_x22840 = n._cons.Optional.value;
    kk_integer_t _n_169530 = kk_integer_unbox(_box_x22840);
    kk_integer_dup(_n_169530);
    _x24703 = _n_169530; /*int*/
    goto _match24704;
  }
  _x24703 = kk_integer_from_small(1); /*int*/
  _match24704: ;
  _x24702 = kk_integer_sub((kk_integer_from_small(1)),_x24703,kk_context()); /*int*/
  _x24701 = kk_std_core_advance(slice0, _x24702, _ctx); /*sslice*/
  kk_integer_t _x24706;
  kk_integer_t _x24707;
  if (kk_std_core_types__is_Optional(n)) {
    kk_box_t _box_x22841 = n._cons.Optional.value;
    kk_integer_t _n_169531 = kk_integer_unbox(_box_x22841);
    kk_integer_dup(_n_169531);
    kk_std_core_types__optional_drop(n, _ctx);
    _x24707 = _n_169531; /*int*/
    goto _match24708;
  }
  _x24707 = kk_integer_from_small(1); /*int*/
  _match24708: ;
  _x24706 = kk_integer_sub(_x24707,(kk_integer_from_small(1)),kk_context()); /*int*/
  return kk_std_core_extend(_x24701, _x24706, _ctx);
}
 
// Take the first `n` elements of a list (or fewer if the list is shorter than `n`)

kk_std_core__list kk_std_core__ctail_take(kk_std_core__list xs, kk_integer_t n, kk_std_core_types__ctail _acc, kk_context_t* _ctx) { /* forall<a> (xs : list<a>, n : int, ctail<list<a>>) -> list<a> */ 
  kk__tailcall: ;
  if (kk_std_core__is_Cons(xs)) {
    struct kk_std_core_Cons* _con24710 = kk_std_core__as_Cons(xs);
    kk_box_t x = _con24710->head;
    kk_std_core__list xx = _con24710->tail;
    kk_integer_t _x24711 = kk_integer_dup(n); /*int*/
    if (kk_integer_gt(_x24711,(kk_integer_from_small(0)),kk_context())) {
      kk_reuse_t _ru_23388 = kk_reuse_null; /*reuse*/;
      if (kk_std_core__list_is_unique(xs)) {
        _ru_23388 = (kk_std_core__list_reuse(xs));
      }
      else {
        kk_box_dup(x);
        kk_std_core__list_dup(xx);
        kk_std_core__list_decref(xs, _ctx);
        _ru_23388 = kk_reuse_null;
      }
      kk_std_core__list _ctail_21145 = kk_std_core__list_hole(); /*list<17137>*/;
      kk_std_core__list _ctail_21146;
      bool _x24712 = _ru_23388!=NULL; /*bool*/
      if (_x24712) {
        struct kk_std_core_Cons* _con24713 = (struct kk_std_core_Cons*)_ru_23388;
        _con24713->tail = _ctail_21145;
        _ctail_21146 = kk_std_core__base_Cons(_con24713); /*list<17137>*/
      }
      else {
        _ctail_21146 = kk_std_core__new_Cons(kk_reuse_null, x, _ctail_21145, _ctx); /*list<17137>*/
      }
      { // tailcall
        kk_integer_t _x24714 = kk_integer_sub(n,(kk_integer_from_small(1)),kk_context()); /*int*/
        kk_std_core_types__ctail _x24715;
        kk_box_t* field_21686 = (kk_box_t*)((&kk_std_core__as_Cons(_ctail_21146)->tail)); /*cfield<list<17137>>*/;
        if (kk_std_core_types__is_CTail(_acc)) {
          kk_box_t _box_x22848 = _acc._cons.CTail._field1;
          kk_box_t* last0 = _acc._cons.CTail._field2;
          kk_std_core__list head0 = kk_std_core__list_unbox(_box_x22848, NULL);
          kk_std_core__list_dup(head0);
          kk_std_core_types__ctail_drop(_acc, _ctx);
          kk_unit_t __ = kk_Unit;
          *(last0) = kk_std_core__list_box(_ctail_21146, _ctx);
          _x24715 = kk_std_core_types__new_CTail(kk_std_core__list_box(head0, _ctx), field_21686, _ctx); /*ctail<58>*/
          goto _match24716;
        }
        _x24715 = kk_std_core_types__new_CTail(kk_std_core__list_box(_ctail_21146, _ctx), field_21686, _ctx); /*ctail<58>*/
        _match24716: ;
        xs = xx;
        n = _x24714;
        _acc = _x24715;
        goto kk__tailcall;
      }
    }
  }
  kk_integer_drop(n, _ctx);
  kk_std_core__list_drop(xs, _ctx);
  if (kk_std_core_types__is_CTail(_acc)) {
    kk_box_t _box_x22857 = _acc._cons.CTail._field1;
    kk_box_t* last00 = _acc._cons.CTail._field2;
    kk_std_core__list head00 = kk_std_core__list_unbox(_box_x22857, NULL);
    kk_std_core__list_dup(head00);
    kk_std_core_types__ctail_drop(_acc, _ctx);
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
  kk_std_core__list _b_22868_22866;
  kk_std_core__list _x24719 = kk_std_core__list_dup(xs); /*list<17157>*/
  kk_integer_t _x24720 = kk_integer_dup(n); /*int*/
  _b_22868_22866 = kk_std_core_take(_x24719, _x24720, _ctx); /*list<17157>*/
  kk_std_core__list _b_22869_22867 = kk_std_core_drop(xs, n, _ctx); /*list<17157>*/;
  return kk_std_core_types__new_dash__lp__comma__rp_(kk_std_core__list_box(_b_22868_22866, _ctx), kk_std_core__list_box(_b_22869_22867, _ctx), _ctx);
}
 
// Lookup the first element satisfying some predicate


// lift anonymous function
struct kk_std_core_lookup_fun24724__t {
  struct kk_function_s _base;
  kk_function_t pred;
};
static kk_std_core_types__maybe kk_std_core_lookup_fun24724(kk_function_t _fself, kk_box_t _b_22872, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_lookup_fun24724(kk_function_t pred, kk_context_t* _ctx) {
  struct kk_std_core_lookup_fun24724__t* _self = kk_function_alloc_as(struct kk_std_core_lookup_fun24724__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_lookup_fun24724, kk_context());
  _self->pred = pred;
  return &_self->_base;
}

static kk_std_core_types__maybe kk_std_core_lookup_fun24724(kk_function_t _fself, kk_box_t _b_22872, kk_context_t* _ctx) {
  struct kk_std_core_lookup_fun24724__t* _self = kk_function_as(struct kk_std_core_lookup_fun24724__t*, _fself);
  kk_function_t pred = _self->pred; /* (17530) -> bool */
  kk_drop_match(_self, {kk_function_dup(pred);}, {}, _ctx)
  bool _match_23465;
  kk_box_t _x24725;
  kk_std_core_types__tuple2_ _match_23467;
  kk_box_t _x24726 = kk_box_dup(_b_22872); /*13066*/
  _match_23467 = kk_std_core_types__tuple2__unbox(_x24726, _ctx); /*(17530, 17531)*/
  kk_box_t _x = _match_23467.fst;
  kk_box_dup(_x);
  kk_std_core_types__tuple2__drop(_match_23467, _ctx);
  _x24725 = _x; /*17530*/
  _match_23465 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_context_t*), pred, (pred, _x24725, _ctx)); /*bool*/
  if (_match_23465) {
    kk_box_t _x24727;
    kk_std_core_types__tuple2_ _match_23466 = kk_std_core_types__tuple2__unbox(_b_22872, _ctx); /*(17530, 17531)*/;
    kk_box_t _x0 = _match_23466.snd;
    kk_box_dup(_x0);
    kk_std_core_types__tuple2__drop(_match_23466, _ctx);
    _x24727 = _x0; /*17531*/
    return kk_std_core_types__new_Just(_x24727, _ctx);
  }
  kk_box_drop(_b_22872, _ctx);
  return kk_std_core_types__new_Nothing(_ctx);
}

kk_std_core_types__maybe kk_std_core_lookup(kk_std_core__list xs, kk_function_t pred, kk_context_t* _ctx) { /* forall<a,b> (xs : list<(a, b)>, pred : (a) -> bool) -> maybe<b> */ 
  return kk_std_core_foreach_while(xs, kk_std_core_new_lookup_fun24724(pred, _ctx), _ctx);
}
 
// monadic lift

kk_std_core__list kk_std_core__mlift21214_op(kk_box_t _y_192, kk_std_core__list _y_193, kk_context_t* _ctx) { /* forall<a,e> (a, list<a>) -> e list<a> */ 
  return kk_std_core__new_Cons(kk_reuse_null, _y_192, _y_193, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_core__mlift21215_op_fun24729__t {
  struct kk_function_s _base;
  kk_box_t _y_1920;
};
static kk_box_t kk_std_core__mlift21215_op_fun24729(kk_function_t _fself, kk_box_t _b_22877, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_mlift21215_op_fun24729(kk_box_t _y_1920, kk_context_t* _ctx) {
  struct kk_std_core__mlift21215_op_fun24729__t* _self = kk_function_alloc_as(struct kk_std_core__mlift21215_op_fun24729__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__mlift21215_op_fun24729, kk_context());
  _self->_y_1920 = _y_1920;
  return &_self->_base;
}

static kk_box_t kk_std_core__mlift21215_op_fun24729(kk_function_t _fself, kk_box_t _b_22877, kk_context_t* _ctx) {
  struct kk_std_core__mlift21215_op_fun24729__t* _self = kk_function_as(struct kk_std_core__mlift21215_op_fun24729__t*, _fself);
  kk_box_t _y_1920 = _self->_y_1920; /* 17533 */
  kk_drop_match(_self, {kk_box_dup(_y_1920);}, {}, _ctx)
  kk_std_core__list _x24730;
  kk_std_core__list _x24731 = kk_std_core__list_unbox(_b_22877, _ctx); /*list<17533>*/
  _x24730 = kk_std_core__mlift21214_op(_y_1920, _x24731, _ctx); /*list<17533>*/
  return kk_std_core__list_box(_x24730, _ctx);
}

kk_std_core__list kk_std_core__mlift21215_op(kk_function_t f, kk_integer_t i, kk_std_core__list yy, kk_box_t _y_1920, kk_context_t* _ctx) { /* forall<a,b,e> (f : (idx : int, value : a) -> e b, i : int, yy : list<a>, b) -> e list<b> */ 
  kk_integer_t i0_21090 = kk_integer_add(i,(kk_integer_from_small(1)),kk_context()); /*int*/;
  kk_std_core__list x_21696 = kk_std_core__lift21058_map_indexed(f, yy, i0_21090, _ctx); /*list<17533>*/;
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_21696, _ctx);
    kk_box_t _x24728 = kk_std_core_hnd_yield_extend(kk_std_core__new_mlift21215_op_fun24729(_y_1920, _ctx), _ctx); /*3991*/
    return kk_std_core__list_unbox(_x24728, _ctx);
  }
  return kk_std_core__mlift21214_op(_y_1920, x_21696, _ctx);
}
 
// lift


// lift anonymous function
struct kk_std_core__lift21058_map_indexed_fun24736__t {
  struct kk_function_s _base;
  kk_function_t f0;
  kk_integer_t i0;
  kk_std_core__list yy0;
};
static kk_box_t kk_std_core__lift21058_map_indexed_fun24736(kk_function_t _fself, kk_box_t _b_22881, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_lift21058_map_indexed_fun24736(kk_function_t f0, kk_integer_t i0, kk_std_core__list yy0, kk_context_t* _ctx) {
  struct kk_std_core__lift21058_map_indexed_fun24736__t* _self = kk_function_alloc_as(struct kk_std_core__lift21058_map_indexed_fun24736__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__lift21058_map_indexed_fun24736, kk_context());
  _self->f0 = f0;
  _self->i0 = i0;
  _self->yy0 = yy0;
  return &_self->_base;
}

static kk_box_t kk_std_core__lift21058_map_indexed_fun24736(kk_function_t _fself, kk_box_t _b_22881, kk_context_t* _ctx) {
  struct kk_std_core__lift21058_map_indexed_fun24736__t* _self = kk_function_as(struct kk_std_core__lift21058_map_indexed_fun24736__t*, _fself);
  kk_function_t f0 = _self->f0; /* (idx : int, value : 17532) -> 17534 17533 */
  kk_integer_t i0 = _self->i0; /* int */
  kk_std_core__list yy0 = _self->yy0; /* list<17532> */
  kk_drop_match(_self, {kk_function_dup(f0);kk_integer_dup(i0);kk_std_core__list_dup(yy0);}, {}, _ctx)
  kk_std_core__list _x24737 = kk_std_core__mlift21215_op(f0, i0, yy0, _b_22881, _ctx); /*list<17533>*/
  return kk_std_core__list_box(_x24737, _ctx);
}


// lift anonymous function
struct kk_std_core__lift21058_map_indexed_fun24739__t {
  struct kk_function_s _base;
  kk_box_t x_21698;
};
static kk_box_t kk_std_core__lift21058_map_indexed_fun24739(kk_function_t _fself, kk_box_t _b_22883, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_lift21058_map_indexed_fun24739(kk_box_t x_21698, kk_context_t* _ctx) {
  struct kk_std_core__lift21058_map_indexed_fun24739__t* _self = kk_function_alloc_as(struct kk_std_core__lift21058_map_indexed_fun24739__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__lift21058_map_indexed_fun24739, kk_context());
  _self->x_21698 = x_21698;
  return &_self->_base;
}

static kk_box_t kk_std_core__lift21058_map_indexed_fun24739(kk_function_t _fself, kk_box_t _b_22883, kk_context_t* _ctx) {
  struct kk_std_core__lift21058_map_indexed_fun24739__t* _self = kk_function_as(struct kk_std_core__lift21058_map_indexed_fun24739__t*, _fself);
  kk_box_t x_21698 = _self->x_21698; /* 17533 */
  kk_drop_match(_self, {kk_box_dup(x_21698);}, {}, _ctx)
  kk_std_core__list _x24740;
  kk_std_core__list _x24741 = kk_std_core__list_unbox(_b_22883, _ctx); /*list<17533>*/
  _x24740 = kk_std_core__mlift21214_op(x_21698, _x24741, _ctx); /*list<17533>*/
  return kk_std_core__list_box(_x24740, _ctx);
}

kk_std_core__list kk_std_core__lift21058_map_indexed(kk_function_t f0, kk_std_core__list ys, kk_integer_t i0, kk_context_t* _ctx) { /* forall<a,b,e> (f : (idx : int, value : a) -> e b, ys : list<a>, i : int) -> e list<b> */ 
  if (kk_std_core__is_Cons(ys)) {
    struct kk_std_core_Cons* _con24732 = kk_std_core__as_Cons(ys);
    kk_box_t y = _con24732->head;
    kk_std_core__list yy0 = _con24732->tail;
    kk_reuse_t _ru_23389 = kk_reuse_null; /*reuse*/;
    if (kk_std_core__list_is_unique(ys)) {
      _ru_23389 = (kk_std_core__list_reuse(ys));
    }
    else {
      kk_box_dup(y);
      kk_std_core__list_dup(yy0);
      kk_std_core__list_decref(ys, _ctx);
      _ru_23389 = kk_reuse_null;
    }
    kk_box_t x_21698;
    kk_function_t _x24734 = kk_function_dup(f0); /*(idx : int, value : 17532) -> 17534 17533*/
    kk_integer_t _x24733 = kk_integer_dup(i0); /*int*/
    x_21698 = kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_box_t, kk_context_t*), _x24734, (_x24734, _x24733, y, _ctx)); /*17533*/
    if (kk_yielding(kk_context())) {
      kk_reuse_drop(_ru_23389, _ctx);
      kk_box_drop(x_21698, _ctx);
      kk_box_t _x24735 = kk_std_core_hnd_yield_extend(kk_std_core__new_lift21058_map_indexed_fun24736(f0, i0, yy0, _ctx), _ctx); /*3991*/
      return kk_std_core__list_unbox(_x24735, _ctx);
    }
    kk_integer_t i0_210900 = kk_integer_add(i0,(kk_integer_from_small(1)),kk_context()); /*int*/;
    kk_std_core__list x0_21702 = kk_std_core__lift21058_map_indexed(f0, yy0, i0_210900, _ctx); /*list<17533>*/;
    if (kk_yielding(kk_context())) {
      kk_reuse_drop(_ru_23389, _ctx);
      kk_std_core__list_drop(x0_21702, _ctx);
      kk_box_t _x24738 = kk_std_core_hnd_yield_extend(kk_std_core__new_lift21058_map_indexed_fun24739(x_21698, _ctx), _ctx); /*3991*/
      return kk_std_core__list_unbox(_x24738, _ctx);
    }
    return kk_std_core__new_Cons(_ru_23389, x_21698, x0_21702, _ctx);
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
struct kk_std_core__mlift21217_op_fun24743__t {
  struct kk_function_s _base;
  kk_box_t _y_1960;
};
static kk_box_t kk_std_core__mlift21217_op_fun24743(kk_function_t _fself, kk_box_t _b_22889, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_mlift21217_op_fun24743(kk_box_t _y_1960, kk_context_t* _ctx) {
  struct kk_std_core__mlift21217_op_fun24743__t* _self = kk_function_alloc_as(struct kk_std_core__mlift21217_op_fun24743__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__mlift21217_op_fun24743, kk_context());
  _self->_y_1960 = _y_1960;
  return &_self->_base;
}

static kk_box_t kk_std_core__mlift21217_op_fun24743(kk_function_t _fself, kk_box_t _b_22889, kk_context_t* _ctx) {
  struct kk_std_core__mlift21217_op_fun24743__t* _self = kk_function_as(struct kk_std_core__mlift21217_op_fun24743__t*, _fself);
  kk_box_t _y_1960 = _self->_y_1960; /* 17604 */
  kk_drop_match(_self, {kk_box_dup(_y_1960);}, {}, _ctx)
  kk_std_core__list _x24744;
  kk_std_core__list _x24745 = kk_std_core__list_unbox(_b_22889, _ctx); /*list<17604>*/
  _x24744 = kk_std_core__mlift21216_op(_y_1960, _x24745, _ctx); /*list<17604>*/
  return kk_std_core__list_box(_x24744, _ctx);
}

kk_std_core__list kk_std_core__mlift21217_op(kk_function_t f, kk_integer_t i, kk_std_core__list yy, kk_box_t _y_1960, kk_context_t* _ctx) { /* forall<a,b,e> (f : (idx : int, value : a, rest : list<a>) -> e b, i : int, yy : list<a>, b) -> e list<b> */ 
  kk_integer_t i0_21094 = kk_integer_add(i,(kk_integer_from_small(1)),kk_context()); /*int*/;
  kk_std_core__list x_21706 = kk_std_core__lift21059_map_indexed_peek(f, yy, i0_21094, _ctx); /*list<17604>*/;
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_21706, _ctx);
    kk_box_t _x24742 = kk_std_core_hnd_yield_extend(kk_std_core__new_mlift21217_op_fun24743(_y_1960, _ctx), _ctx); /*3991*/
    return kk_std_core__list_unbox(_x24742, _ctx);
  }
  return kk_std_core__mlift21216_op(_y_1960, x_21706, _ctx);
}
 
// lift


// lift anonymous function
struct kk_std_core__lift21059_map_indexed_peek_fun24751__t {
  struct kk_function_s _base;
  kk_function_t f0;
  kk_integer_t i0;
  kk_std_core__list yy0;
};
static kk_box_t kk_std_core__lift21059_map_indexed_peek_fun24751(kk_function_t _fself, kk_box_t _b_22893, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_lift21059_map_indexed_peek_fun24751(kk_function_t f0, kk_integer_t i0, kk_std_core__list yy0, kk_context_t* _ctx) {
  struct kk_std_core__lift21059_map_indexed_peek_fun24751__t* _self = kk_function_alloc_as(struct kk_std_core__lift21059_map_indexed_peek_fun24751__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__lift21059_map_indexed_peek_fun24751, kk_context());
  _self->f0 = f0;
  _self->i0 = i0;
  _self->yy0 = yy0;
  return &_self->_base;
}

static kk_box_t kk_std_core__lift21059_map_indexed_peek_fun24751(kk_function_t _fself, kk_box_t _b_22893, kk_context_t* _ctx) {
  struct kk_std_core__lift21059_map_indexed_peek_fun24751__t* _self = kk_function_as(struct kk_std_core__lift21059_map_indexed_peek_fun24751__t*, _fself);
  kk_function_t f0 = _self->f0; /* (idx : int, value : 17603, rest : list<17603>) -> 17605 17604 */
  kk_integer_t i0 = _self->i0; /* int */
  kk_std_core__list yy0 = _self->yy0; /* list<17603> */
  kk_drop_match(_self, {kk_function_dup(f0);kk_integer_dup(i0);kk_std_core__list_dup(yy0);}, {}, _ctx)
  kk_std_core__list _x24752 = kk_std_core__mlift21217_op(f0, i0, yy0, _b_22893, _ctx); /*list<17604>*/
  return kk_std_core__list_box(_x24752, _ctx);
}


// lift anonymous function
struct kk_std_core__lift21059_map_indexed_peek_fun24754__t {
  struct kk_function_s _base;
  kk_box_t x_21708;
};
static kk_box_t kk_std_core__lift21059_map_indexed_peek_fun24754(kk_function_t _fself, kk_box_t _b_22895, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_lift21059_map_indexed_peek_fun24754(kk_box_t x_21708, kk_context_t* _ctx) {
  struct kk_std_core__lift21059_map_indexed_peek_fun24754__t* _self = kk_function_alloc_as(struct kk_std_core__lift21059_map_indexed_peek_fun24754__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__lift21059_map_indexed_peek_fun24754, kk_context());
  _self->x_21708 = x_21708;
  return &_self->_base;
}

static kk_box_t kk_std_core__lift21059_map_indexed_peek_fun24754(kk_function_t _fself, kk_box_t _b_22895, kk_context_t* _ctx) {
  struct kk_std_core__lift21059_map_indexed_peek_fun24754__t* _self = kk_function_as(struct kk_std_core__lift21059_map_indexed_peek_fun24754__t*, _fself);
  kk_box_t x_21708 = _self->x_21708; /* 17604 */
  kk_drop_match(_self, {kk_box_dup(x_21708);}, {}, _ctx)
  kk_std_core__list _x24755;
  kk_std_core__list _x24756 = kk_std_core__list_unbox(_b_22895, _ctx); /*list<17604>*/
  _x24755 = kk_std_core__mlift21216_op(x_21708, _x24756, _ctx); /*list<17604>*/
  return kk_std_core__list_box(_x24755, _ctx);
}

kk_std_core__list kk_std_core__lift21059_map_indexed_peek(kk_function_t f0, kk_std_core__list ys, kk_integer_t i0, kk_context_t* _ctx) { /* forall<a,b,e> (f : (idx : int, value : a, rest : list<a>) -> e b, ys : list<a>, i : int) -> e list<b> */ 
  if (kk_std_core__is_Cons(ys)) {
    struct kk_std_core_Cons* _con24746 = kk_std_core__as_Cons(ys);
    kk_box_t y = _con24746->head;
    kk_std_core__list yy0 = _con24746->tail;
    kk_reuse_t _ru_23390 = kk_reuse_null; /*reuse*/;
    if (kk_std_core__list_is_unique(ys)) {
      _ru_23390 = (kk_std_core__list_reuse(ys));
    }
    else {
      kk_box_dup(y);
      kk_std_core__list_dup(yy0);
      kk_std_core__list_decref(ys, _ctx);
      _ru_23390 = kk_reuse_null;
    }
    kk_box_t x_21708;
    kk_function_t _x24749 = kk_function_dup(f0); /*(idx : int, value : 17603, rest : list<17603>) -> 17605 17604*/
    kk_integer_t _x24747 = kk_integer_dup(i0); /*int*/
    kk_std_core__list _x24748 = kk_std_core__list_dup(yy0); /*list<17603>*/
    x_21708 = kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_box_t, kk_std_core__list, kk_context_t*), _x24749, (_x24749, _x24747, y, _x24748, _ctx)); /*17604*/
    if (kk_yielding(kk_context())) {
      kk_reuse_drop(_ru_23390, _ctx);
      kk_box_drop(x_21708, _ctx);
      kk_box_t _x24750 = kk_std_core_hnd_yield_extend(kk_std_core__new_lift21059_map_indexed_peek_fun24751(f0, i0, yy0, _ctx), _ctx); /*3991*/
      return kk_std_core__list_unbox(_x24750, _ctx);
    }
    kk_integer_t i0_210940 = kk_integer_add(i0,(kk_integer_from_small(1)),kk_context()); /*int*/;
    kk_std_core__list x0_21712 = kk_std_core__lift21059_map_indexed_peek(f0, yy0, i0_210940, _ctx); /*list<17604>*/;
    if (kk_yielding(kk_context())) {
      kk_reuse_drop(_ru_23390, _ctx);
      kk_std_core__list_drop(x0_21712, _ctx);
      kk_box_t _x24753 = kk_std_core_hnd_yield_extend(kk_std_core__new_lift21059_map_indexed_peek_fun24754(x_21708, _ctx), _ctx); /*3991*/
      return kk_std_core__list_unbox(_x24753, _ctx);
    }
    return kk_std_core__new_Cons(_ru_23390, x_21708, x0_21712, _ctx);
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
    kk_std_core_types__ctail _x24757;
    kk_box_t* field_21718 = (kk_box_t*)((&kk_std_core__as_Cons(_ctail_21148)->tail)); /*cfield<list<17715>>*/;
    if (kk_std_core_types__is_CTail(_acc)) {
      kk_box_t _box_x22906 = _acc._cons.CTail._field1;
      kk_box_t* last0 = _acc._cons.CTail._field2;
      kk_std_core__list head0 = kk_std_core__list_unbox(_box_x22906, NULL);
      kk_std_core__list_dup(head0);
      kk_std_core_types__ctail_drop(_acc, _ctx);
      kk_unit_t __ = kk_Unit;
      *(last0) = kk_std_core__list_box(_ctail_21148, _ctx);
      _x24757 = kk_std_core_types__new_CTail(kk_std_core__list_box(head0, _ctx), field_21718, _ctx); /*ctail<58>*/
      goto _match24758;
    }
    _x24757 = kk_std_core_types__new_CTail(kk_std_core__list_box(_ctail_21148, _ctx), field_21718, _ctx); /*ctail<58>*/
    _match24758: ;
    return kk_std_core__ctail_map_while(xx, action, _x24757, _ctx);
  }
  kk_function_drop(action, _ctx);
  kk_std_core__list_drop(xx, _ctx);
  if (kk_std_core_types__is_CTail(_acc)) {
    kk_box_t _box_x22915 = _acc._cons.CTail._field1;
    kk_box_t* last00 = _acc._cons.CTail._field2;
    kk_std_core__list head00 = kk_std_core__list_unbox(_box_x22915, NULL);
    kk_std_core__list_dup(head00);
    kk_std_core_types__ctail_drop(_acc, _ctx);
    kk_unit_t __0 = kk_Unit;
    *(last00) = kk_std_core__list_box(kk_std_core__new_Nil(_ctx), _ctx);
    return head00;
  }
  return kk_std_core__new_Nil(_ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_core__mlift21219_op_fun24761__t {
  struct kk_function_s _base;
  kk_function_t _accm;
  kk_box_t y0;
};
static kk_std_core__list kk_std_core__mlift21219_op_fun24761(kk_function_t _fself, kk_std_core__list _ctail_21150, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_mlift21219_op_fun24761(kk_function_t _accm, kk_box_t y0, kk_context_t* _ctx) {
  struct kk_std_core__mlift21219_op_fun24761__t* _self = kk_function_alloc_as(struct kk_std_core__mlift21219_op_fun24761__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__mlift21219_op_fun24761, kk_context());
  _self->_accm = _accm;
  _self->y0 = y0;
  return &_self->_base;
}

static kk_std_core__list kk_std_core__mlift21219_op_fun24761(kk_function_t _fself, kk_std_core__list _ctail_21150, kk_context_t* _ctx) {
  struct kk_std_core__mlift21219_op_fun24761__t* _self = kk_function_as(struct kk_std_core__mlift21219_op_fun24761__t*, _fself);
  kk_function_t _accm = _self->_accm; /* (list<17715>) -> list<17715> */
  kk_box_t y0 = _self->y0; /* 17715 */
  kk_drop_match(_self, {kk_function_dup(_accm);kk_box_dup(y0);}, {}, _ctx)
  kk_std_core__list _x24762 = kk_std_core__new_Cons(kk_reuse_null, y0, _ctail_21150, _ctx); /*list<61>*/
  return kk_function_call(kk_std_core__list, (kk_function_t, kk_std_core__list, kk_context_t*), _accm, (_accm, _x24762, _ctx));
}

kk_std_core__list kk_std_core__mlift21219_op(kk_function_t _accm, kk_function_t action0, kk_std_core__list xx0, kk_std_core_types__maybe _y_204, kk_context_t* _ctx) { /* forall<a,b,e> ((list<b>) -> list<b>, action : (a) -> e maybe<b>, xx : list<a>, maybe<b>) -> e list<b> */ 
  if (kk_std_core_types__is_Just(_y_204)) {
    kk_box_t y0 = _y_204._cons.Just.value;
    return kk_std_core__ctailm_map_while(xx0, action0, kk_std_core__new_mlift21219_op_fun24761(_accm, y0, _ctx), _ctx);
  }
  kk_function_drop(action0, _ctx);
  kk_std_core__list_drop(xx0, _ctx);
  return kk_function_call(kk_std_core__list, (kk_function_t, kk_std_core__list, kk_context_t*), _accm, (_accm, kk_std_core__new_Nil(_ctx), _ctx));
}
 
// Invoke `action` on each element of a list while `action` returns `Just`


// lift anonymous function
struct kk_std_core__ctail_map_while_fun24767__t {
  struct kk_function_s _base;
  kk_function_t action1;
  kk_std_core__list xx1;
  kk_std_core_types__ctail _acc0;
};
static kk_box_t kk_std_core__ctail_map_while_fun24767(kk_function_t _fself, kk_box_t _b_22930, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_ctail_map_while_fun24767(kk_function_t action1, kk_std_core__list xx1, kk_std_core_types__ctail _acc0, kk_context_t* _ctx) {
  struct kk_std_core__ctail_map_while_fun24767__t* _self = kk_function_alloc_as(struct kk_std_core__ctail_map_while_fun24767__t, 5, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__ctail_map_while_fun24767, kk_context());
  _self->action1 = action1;
  _self->xx1 = xx1;
  _self->_acc0 = _acc0;
  return &_self->_base;
}

static kk_box_t kk_std_core__ctail_map_while_fun24767(kk_function_t _fself, kk_box_t _b_22930, kk_context_t* _ctx) {
  struct kk_std_core__ctail_map_while_fun24767__t* _self = kk_function_as(struct kk_std_core__ctail_map_while_fun24767__t*, _fself);
  kk_function_t action1 = _self->action1; /* (17714) -> 17716 maybe<17715> */
  kk_std_core__list xx1 = _self->xx1; /* list<17714> */
  kk_std_core_types__ctail _acc0 = _self->_acc0; /* ctail<list<17715>> */
  kk_drop_match(_self, {kk_function_dup(action1);kk_std_core__list_dup(xx1);kk_std_core_types__ctail_dup(_acc0);}, {}, _ctx)
  kk_std_core__list _x24768;
  kk_std_core_types__maybe _x24769 = kk_std_core_types__maybe_unbox(_b_22930, _ctx); /*maybe<17715>*/
  _x24768 = kk_std_core__mlift21218_op(_acc0, action1, xx1, _x24769, _ctx); /*list<17715>*/
  return kk_std_core__list_box(_x24768, _ctx);
}

kk_std_core__list kk_std_core__ctail_map_while(kk_std_core__list xs, kk_function_t action1, kk_std_core_types__ctail _acc0, kk_context_t* _ctx) { /* forall<a,b,e> (xs : list<a>, action : (a) -> e maybe<b>, ctail<list<b>>) -> e list<b> */ 
  kk__tailcall: ;
  if (kk_std_core__is_Nil(xs)) {
    kk_function_drop(action1, _ctx);
    if (kk_std_core_types__is_CTail(_acc0)) {
      kk_box_t _box_x22924 = _acc0._cons.CTail._field1;
      kk_box_t* last2 = _acc0._cons.CTail._field2;
      kk_std_core__list head1 = kk_std_core__list_unbox(_box_x22924, NULL);
      kk_std_core__list_dup(head1);
      kk_std_core_types__ctail_drop(_acc0, _ctx);
      kk_unit_t __1 = kk_Unit;
      *(last2) = kk_std_core__list_box(kk_std_core__new_Nil(_ctx), _ctx);
      return head1;
    }
    return kk_std_core__new_Nil(_ctx);
  }
  struct kk_std_core_Cons* _con24764 = kk_std_core__as_Cons(xs);
  kk_box_t x = _con24764->head;
  kk_std_core__list xx1 = _con24764->tail;
  kk_reuse_t _ru_23391 = kk_reuse_null; /*reuse*/;
  if (kk_std_core__list_is_unique(xs)) {
    _ru_23391 = (kk_std_core__list_reuse(xs));
  }
  else {
    kk_box_dup(x);
    kk_std_core__list_dup(xx1);
    kk_std_core__list_decref(xs, _ctx);
    _ru_23391 = kk_reuse_null;
  }
  kk_std_core_types__maybe x0_21723;
  kk_function_t _x24765 = kk_function_dup(action1); /*(17714) -> 17716 maybe<17715>*/
  x0_21723 = kk_function_call(kk_std_core_types__maybe, (kk_function_t, kk_box_t, kk_context_t*), _x24765, (_x24765, x, _ctx)); /*maybe<17715>*/
  if (kk_yielding(kk_context())) {
    kk_reuse_drop(_ru_23391, _ctx);
    kk_std_core_types__maybe_drop(x0_21723, _ctx);
    kk_box_t _x24766 = kk_std_core_hnd_yield_extend(kk_std_core__new_ctail_map_while_fun24767(action1, xx1, _acc0, _ctx), _ctx); /*3991*/
    return kk_std_core__list_unbox(_x24766, _ctx);
  }
  if (kk_std_core_types__is_Just(x0_21723)) {
    kk_box_t y1 = x0_21723._cons.Just.value;
    kk_std_core__list _ctail_211470 = kk_std_core__list_hole(); /*list<17715>*/;
    kk_std_core__list _ctail_211480 = kk_std_core__new_Cons(_ru_23391, y1, _ctail_211470, _ctx); /*list<17715>*/;
    { // tailcall
      kk_std_core_types__ctail _x24770;
      kk_box_t* field_21729 = (kk_box_t*)((&kk_std_core__as_Cons(_ctail_211480)->tail)); /*cfield<list<17715>>*/;
      if (kk_std_core_types__is_CTail(_acc0)) {
        kk_box_t _box_x22937 = _acc0._cons.CTail._field1;
        kk_box_t* last01 = _acc0._cons.CTail._field2;
        kk_std_core__list head01 = kk_std_core__list_unbox(_box_x22937, NULL);
        kk_std_core__list_dup(head01);
        kk_std_core_types__ctail_drop(_acc0, _ctx);
        kk_unit_t __00 = kk_Unit;
        *(last01) = kk_std_core__list_box(_ctail_211480, _ctx);
        _x24770 = kk_std_core_types__new_CTail(kk_std_core__list_box(head01, _ctx), field_21729, _ctx); /*ctail<58>*/
        goto _match24771;
      }
      _x24770 = kk_std_core_types__new_CTail(kk_std_core__list_box(_ctail_211480, _ctx), field_21729, _ctx); /*ctail<58>*/
      _match24771: ;
      xs = xx1;
      _acc0 = _x24770;
      goto kk__tailcall;
    }
  }
  kk_reuse_drop(_ru_23391, _ctx);
  kk_function_drop(action1, _ctx);
  kk_std_core__list_drop(xx1, _ctx);
  if (kk_std_core_types__is_CTail(_acc0)) {
    kk_box_t _box_x22946 = _acc0._cons.CTail._field1;
    kk_box_t* last10 = _acc0._cons.CTail._field2;
    kk_std_core__list head10 = kk_std_core__list_unbox(_box_x22946, NULL);
    kk_std_core__list_dup(head10);
    kk_std_core_types__ctail_drop(_acc0, _ctx);
    kk_unit_t __10 = kk_Unit;
    *(last10) = kk_std_core__list_box(kk_std_core__new_Nil(_ctx), _ctx);
    return head10;
  }
  return kk_std_core__new_Nil(_ctx);
}
 
// Invoke `action` on each element of a list while `action` returns `Just`


// lift anonymous function
struct kk_std_core__ctailm_map_while_fun24777__t {
  struct kk_function_s _base;
  kk_function_t _accm0;
  kk_function_t action2;
  kk_std_core__list xx2;
};
static kk_box_t kk_std_core__ctailm_map_while_fun24777(kk_function_t _fself, kk_box_t _b_22958, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_ctailm_map_while_fun24777(kk_function_t _accm0, kk_function_t action2, kk_std_core__list xx2, kk_context_t* _ctx) {
  struct kk_std_core__ctailm_map_while_fun24777__t* _self = kk_function_alloc_as(struct kk_std_core__ctailm_map_while_fun24777__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__ctailm_map_while_fun24777, kk_context());
  _self->_accm0 = _accm0;
  _self->action2 = action2;
  _self->xx2 = xx2;
  return &_self->_base;
}

static kk_box_t kk_std_core__ctailm_map_while_fun24777(kk_function_t _fself, kk_box_t _b_22958, kk_context_t* _ctx) {
  struct kk_std_core__ctailm_map_while_fun24777__t* _self = kk_function_as(struct kk_std_core__ctailm_map_while_fun24777__t*, _fself);
  kk_function_t _accm0 = _self->_accm0; /* (list<17715>) -> list<17715> */
  kk_function_t action2 = _self->action2; /* (17714) -> 17716 maybe<17715> */
  kk_std_core__list xx2 = _self->xx2; /* list<17714> */
  kk_drop_match(_self, {kk_function_dup(_accm0);kk_function_dup(action2);kk_std_core__list_dup(xx2);}, {}, _ctx)
  kk_std_core__list _x24778;
  kk_std_core_types__maybe _x24779 = kk_std_core_types__maybe_unbox(_b_22958, _ctx); /*maybe<17715>*/
  _x24778 = kk_std_core__mlift21219_op(_accm0, action2, xx2, _x24779, _ctx); /*list<17715>*/
  return kk_std_core__list_box(_x24778, _ctx);
}


// lift anonymous function
struct kk_std_core__ctailm_map_while_fun24781__t {
  struct kk_function_s _base;
  kk_function_t _accm0;
  kk_box_t y2;
};
static kk_std_core__list kk_std_core__ctailm_map_while_fun24781(kk_function_t _fself, kk_std_core__list _ctail_211500, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_ctailm_map_while_fun24781(kk_function_t _accm0, kk_box_t y2, kk_context_t* _ctx) {
  struct kk_std_core__ctailm_map_while_fun24781__t* _self = kk_function_alloc_as(struct kk_std_core__ctailm_map_while_fun24781__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__ctailm_map_while_fun24781, kk_context());
  _self->_accm0 = _accm0;
  _self->y2 = y2;
  return &_self->_base;
}

static kk_std_core__list kk_std_core__ctailm_map_while_fun24781(kk_function_t _fself, kk_std_core__list _ctail_211500, kk_context_t* _ctx) {
  struct kk_std_core__ctailm_map_while_fun24781__t* _self = kk_function_as(struct kk_std_core__ctailm_map_while_fun24781__t*, _fself);
  kk_function_t _accm0 = _self->_accm0; /* (list<17715>) -> list<17715> */
  kk_box_t y2 = _self->y2; /* 17715 */
  kk_drop_match(_self, {kk_function_dup(_accm0);kk_box_dup(y2);}, {}, _ctx)
  kk_std_core__list _x24782 = kk_std_core__new_Cons(kk_reuse_null, y2, _ctail_211500, _ctx); /*list<61>*/
  return kk_function_call(kk_std_core__list, (kk_function_t, kk_std_core__list, kk_context_t*), _accm0, (_accm0, _x24782, _ctx));
}

kk_std_core__list kk_std_core__ctailm_map_while(kk_std_core__list xs0, kk_function_t action2, kk_function_t _accm0, kk_context_t* _ctx) { /* forall<a,b,e> (xs : list<a>, action : (a) -> e maybe<b>, (list<b>) -> list<b>) -> e list<b> */ 
  kk__tailcall: ;
  if (kk_std_core__is_Nil(xs0)) {
    kk_function_drop(action2, _ctx);
    return kk_function_call(kk_std_core__list, (kk_function_t, kk_std_core__list, kk_context_t*), _accm0, (_accm0, kk_std_core__new_Nil(_ctx), _ctx));
  }
  struct kk_std_core_Cons* _con24774 = kk_std_core__as_Cons(xs0);
  kk_box_t x0 = _con24774->head;
  kk_std_core__list xx2 = _con24774->tail;
  if (kk_std_core__list_is_unique(xs0)) {
    kk_std_core__list_free(xs0);
  }
  else {
    kk_box_dup(x0);
    kk_std_core__list_dup(xx2);
    kk_std_core__list_decref(xs0, _ctx);
  }
  kk_std_core_types__maybe x0_21732;
  kk_function_t _x24775 = kk_function_dup(action2); /*(17714) -> 17716 maybe<17715>*/
  x0_21732 = kk_function_call(kk_std_core_types__maybe, (kk_function_t, kk_box_t, kk_context_t*), _x24775, (_x24775, x0, _ctx)); /*maybe<17715>*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__maybe_drop(x0_21732, _ctx);
    kk_box_t _x24776 = kk_std_core_hnd_yield_extend(kk_std_core__new_ctailm_map_while_fun24777(_accm0, action2, xx2, _ctx), _ctx); /*3991*/
    return kk_std_core__list_unbox(_x24776, _ctx);
  }
  if (kk_std_core_types__is_Just(x0_21732)) {
    kk_box_t y2 = x0_21732._cons.Just.value;
    { // tailcall
      kk_function_t _x24780 = kk_std_core__new_ctailm_map_while_fun24781(_accm0, y2, _ctx); /*(list<17715>) -> list<17715>*/
      xs0 = xx2;
      _accm0 = _x24780;
      goto kk__tailcall;
    }
  }
  kk_function_drop(action2, _ctx);
  kk_std_core__list_drop(xx2, _ctx);
  return kk_function_call(kk_std_core__list, (kk_function_t, kk_std_core__list, kk_context_t*), _accm0, (_accm0, kk_std_core__new_Nil(_ctx), _ctx));
}
 
// Invoke `action` on each element of a list while `action` returns `Just`


// lift anonymous function
struct kk_std_core_map_while_fun24783__t {
  struct kk_function_s _base;
};
static kk_std_core__list kk_std_core_map_while_fun24783(kk_function_t _fself, kk_std_core__list _ctail_21149, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_map_while_fun24783(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_map_while_fun24783, _ctx)
  return kk_function_dup(_fself);
}

static kk_std_core__list kk_std_core_map_while_fun24783(kk_function_t _fself, kk_std_core__list _ctail_21149, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return _ctail_21149;
}

kk_std_core__list kk_std_core_map_while(kk_std_core__list xs1, kk_function_t action3, kk_context_t* _ctx) { /* forall<a,b,e> (xs : list<a>, action : (a) -> e maybe<b>) -> e list<b> */ 
  bool _match_23456 = kk_std_core_hnd__evv_is_affine(_ctx); /*bool*/;
  if (_match_23456) {
    return kk_std_core__ctail_map_while(xs1, action3, kk_std_core_types__new_CTailNil(_ctx), _ctx);
  }
  return kk_std_core__ctailm_map_while(xs1, action3, kk_std_core_new_map_while_fun24783(_ctx), _ctx);
}
 
// Return the maximum of two integers

kk_integer_t kk_std_core_max(kk_integer_t i, kk_integer_t j, kk_context_t* _ctx) { /* (i : int, j : int) -> int */ 
  bool _match_23455;
  kk_integer_t _x24784 = kk_integer_dup(i); /*int*/
  kk_integer_t _x24785 = kk_integer_dup(j); /*int*/
  _match_23455 = kk_integer_gte(_x24784,_x24785,kk_context()); /*bool*/
  if (_match_23455) {
    kk_integer_drop(j, _ctx);
    return i;
  }
  kk_integer_drop(i, _ctx);
  return j;
}
 
// Returns the largest element of a list of integers (or `default` (=`0`) for the empty list)


// lift anonymous function
struct kk_std_core_maximum_fun24790__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_maximum_fun24790(kk_function_t _fself, kk_box_t _b_22966, kk_box_t _b_22967, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_maximum_fun24790(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_maximum_fun24790, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_core_maximum_fun24790(kk_function_t _fself, kk_box_t _b_22966, kk_box_t _b_22967, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_integer_t _x24791;
  kk_integer_t _x24792 = kk_integer_unbox(_b_22966); /*int*/
  kk_integer_t _x24793 = kk_integer_unbox(_b_22967); /*int*/
  _x24791 = kk_std_core_max(_x24792, _x24793, _ctx); /*int*/
  return kk_integer_box(_x24791);
}

kk_integer_t kk_std_core_maximum(kk_std_core__list xs, kk_std_core_types__optional default0, kk_context_t* _ctx) { /* (xs : list<int>, default : optional<int>) -> int */ 
  if (kk_std_core__is_Nil(xs)) {
    if (kk_std_core_types__is_Optional(default0)) {
      kk_box_t _box_x22961 = default0._cons.Optional.value;
      kk_integer_t _default_17788 = kk_integer_unbox(_box_x22961);
      kk_integer_dup(_default_17788);
      kk_std_core_types__optional_drop(default0, _ctx);
      return _default_17788;
    }
    return kk_integer_from_small(0);
  }
  struct kk_std_core_Cons* _con24787 = kk_std_core__as_Cons(xs);
  kk_box_t _box_x22962 = _con24787->head;
  kk_std_core__list xx = _con24787->tail;
  kk_integer_t x = kk_integer_unbox(_box_x22962);
  if (kk_std_core__list_is_unique(xs)) {
    kk_std_core__list_free(xs);
  }
  else {
    kk_integer_dup(x);
    kk_std_core__list_dup(xx);
    kk_std_core__list_decref(xs, _ctx);
  }
  kk_std_core_types__optional_drop(default0, _ctx);
  kk_box_t _x24789 = kk_std_core_foldl(xx, kk_integer_box(x), kk_std_core_new_maximum_fun24790(_ctx), _ctx); /*15010*/
  return kk_integer_unbox(_x24789);
}
 
// Returns the largest element of a list of doubles (or `0` for the empty list)


// lift anonymous function
struct kk_std_core_maximum_fun24797__t_1 {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_maximum_fun24797_1(kk_function_t _fself, kk_box_t _b_22975, kk_box_t _b_22976, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_maximum_fun24797_1(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_maximum_fun24797_1, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_core_maximum_fun24797_1(kk_function_t _fself, kk_box_t _b_22975, kk_box_t _b_22976, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x24798;
  double _x24799 = kk_double_unbox(_b_22975, _ctx); /*double*/
  double _x24800 = kk_double_unbox(_b_22976, _ctx); /*double*/
  _x24798 = kk_std_core_max_1(_x24799, _x24800, _ctx); /*double*/
  return kk_double_box(_x24798, _ctx);
}

double kk_std_core_maximum_1(kk_std_core__list xs, kk_context_t* _ctx) { /* (xs : list<double>) -> double */ 
  if (kk_std_core__is_Nil(xs)) {
    return 0x0p+0;
  }
  struct kk_std_core_Cons* _con24794 = kk_std_core__as_Cons(xs);
  kk_box_t _box_x22971 = _con24794->head;
  kk_std_core__list xx = _con24794->tail;
  double x = kk_double_unbox(_box_x22971, NULL);
  if (kk_std_core__list_is_unique(xs)) {
    kk_box_drop(_box_x22971, _ctx);
    kk_std_core__list_free(xs);
  }
  else {
    kk_std_core__list_dup(xx);
    kk_std_core__list_decref(xs, _ctx);
  }
  kk_box_t _x24796 = kk_std_core_foldl(xx, kk_double_box(x, _ctx), kk_std_core_new_maximum_fun24797_1(_ctx), _ctx); /*15010*/
  return kk_double_unbox(_x24796, _ctx);
}
 
// Convert a list to a `:maybe` type, using `Nothing` for an empty list, and otherwise `Just` on the head element.
// Note: this is just `head`.

kk_std_core_types__maybe kk_std_core_maybe_3(kk_std_core__list xs, kk_context_t* _ctx) { /* forall<a> (xs : list<a>) -> maybe<a> */ 
  if (kk_std_core__is_Nil(xs)) {
    return kk_std_core_types__new_Nothing(_ctx);
  }
  struct kk_std_core_Cons* _con24803 = kk_std_core__as_Cons(xs);
  kk_box_t x = _con24803->head;
  kk_std_core__list _pat1 = _con24803->tail;
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
  bool _match_23453;
  kk_integer_t _x24804 = kk_integer_dup(i); /*int*/
  _match_23453 = kk_integer_eq(_x24804,(kk_integer_from_small(0)),kk_context()); /*bool*/
  if (_match_23453) {
    kk_integer_drop(i, _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
  return kk_std_core_types__new_Just(kk_integer_box(i), _ctx);
}
 
// Transform a string to a maybe type, using `Nothing` for an empty string

kk_std_core_types__maybe kk_std_core_maybe_6(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> maybe<string> */ 
  bool _match_23452;
  kk_string_t _x24805 = kk_string_dup(s); /*string*/
  _match_23452 = kk_std_core_is_empty_2(_x24805, _ctx); /*bool*/
  if (_match_23452) {
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
  bool _match_23451;
  kk_integer_t _x24806 = kk_integer_dup(i); /*int*/
  kk_integer_t _x24807 = kk_integer_dup(j); /*int*/
  _match_23451 = kk_integer_lte(_x24806,_x24807,kk_context()); /*bool*/
  if (_match_23451) {
    kk_integer_drop(j, _ctx);
    return i;
  }
  kk_integer_drop(i, _ctx);
  return j;
}
 
// Returns the smallest element of a list of integers (or `default` (=`0`) for the empty list)


// lift anonymous function
struct kk_std_core_minimum_fun24812__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_minimum_fun24812(kk_function_t _fself, kk_box_t _b_22991, kk_box_t _b_22992, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_minimum_fun24812(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_minimum_fun24812, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_core_minimum_fun24812(kk_function_t _fself, kk_box_t _b_22991, kk_box_t _b_22992, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_integer_t _x24813;
  kk_integer_t _x24814 = kk_integer_unbox(_b_22991); /*int*/
  kk_integer_t _x24815 = kk_integer_unbox(_b_22992); /*int*/
  _x24813 = kk_std_core_min(_x24814, _x24815, _ctx); /*int*/
  return kk_integer_box(_x24813);
}

kk_integer_t kk_std_core_minimum(kk_std_core__list xs, kk_std_core_types__optional default0, kk_context_t* _ctx) { /* (xs : list<int>, default : optional<int>) -> int */ 
  if (kk_std_core__is_Nil(xs)) {
    if (kk_std_core_types__is_Optional(default0)) {
      kk_box_t _box_x22986 = default0._cons.Optional.value;
      kk_integer_t _default_18389 = kk_integer_unbox(_box_x22986);
      kk_integer_dup(_default_18389);
      kk_std_core_types__optional_drop(default0, _ctx);
      return _default_18389;
    }
    return kk_integer_from_small(0);
  }
  struct kk_std_core_Cons* _con24809 = kk_std_core__as_Cons(xs);
  kk_box_t _box_x22987 = _con24809->head;
  kk_std_core__list xx = _con24809->tail;
  kk_integer_t x = kk_integer_unbox(_box_x22987);
  if (kk_std_core__list_is_unique(xs)) {
    kk_std_core__list_free(xs);
  }
  else {
    kk_integer_dup(x);
    kk_std_core__list_dup(xx);
    kk_std_core__list_decref(xs, _ctx);
  }
  kk_std_core_types__optional_drop(default0, _ctx);
  kk_box_t _x24811 = kk_std_core_foldl(xx, kk_integer_box(x), kk_std_core_new_minimum_fun24812(_ctx), _ctx); /*15010*/
  return kk_integer_unbox(_x24811);
}
 
// Returns the smallest element of a list of doubles (or `0` for the empty list)


// lift anonymous function
struct kk_std_core_minimum_fun24819__t_1 {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_minimum_fun24819_1(kk_function_t _fself, kk_box_t _b_23000, kk_box_t _b_23001, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_minimum_fun24819_1(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_minimum_fun24819_1, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_core_minimum_fun24819_1(kk_function_t _fself, kk_box_t _b_23000, kk_box_t _b_23001, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x24820;
  double _x24821 = kk_double_unbox(_b_23000, _ctx); /*double*/
  double _x24822 = kk_double_unbox(_b_23001, _ctx); /*double*/
  _x24820 = kk_std_core_min_1(_x24821, _x24822, _ctx); /*double*/
  return kk_double_box(_x24820, _ctx);
}

double kk_std_core_minimum_1(kk_std_core__list xs, kk_context_t* _ctx) { /* (xs : list<double>) -> double */ 
  if (kk_std_core__is_Nil(xs)) {
    return 0x0p+0;
  }
  struct kk_std_core_Cons* _con24816 = kk_std_core__as_Cons(xs);
  kk_box_t _box_x22996 = _con24816->head;
  kk_std_core__list xx = _con24816->tail;
  double x = kk_double_unbox(_box_x22996, NULL);
  if (kk_std_core__list_is_unique(xs)) {
    kk_box_drop(_box_x22996, _ctx);
    kk_std_core__list_free(xs);
  }
  else {
    kk_std_core__list_dup(xx);
    kk_std_core__list_decref(xs, _ctx);
  }
  kk_box_t _x24818 = kk_std_core_foldl(xx, kk_double_box(x, _ctx), kk_std_core_new_minimum_fun24819_1(_ctx), _ctx); /*15010*/
  return kk_double_unbox(_x24818, _ctx);
}
 
// Disable tracing completely.

kk_unit_t kk_std_core_notrace(kk_context_t* _ctx) { /* () -> (st<global>) () */ 
  kk_ref_t _b_23008_23006 = kk_ref_alloc((kk_bool_box(true)),kk_context()); /*ref<global,bool>*/;
  kk_ref_set(_b_23008_23006,(kk_bool_box(false)),kk_context()); return kk_Unit;
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
  kk_string_t _x24826 = kk_string_dup(s); /*string*/
  n = kk_string_len(_x24826,kk_context()); /*size_t*/
  bool _match_23449 = (w <= n); /*bool*/;
  if (_match_23449) {
    kk_std_core_types__optional_drop(fill, _ctx);
    return s;
  }
  kk_string_t _x24827;
  kk_string_t _x24828;
  kk_char_t _x24829;
  if (kk_std_core_types__is_Optional(fill)) {
    kk_box_t _box_x23011 = fill._cons.Optional.value;
    kk_char_t _fill_18968 = kk_char_unbox(_box_x23011, NULL);
    kk_std_core_types__optional_drop(fill, _ctx);
    _x24829 = _fill_18968; /*char*/
    goto _match24830;
  }
  _x24829 = ' '; /*char*/
  _match24830: ;
  _x24828 = kk_std_core_string(_x24829, _ctx); /*string*/
  size_t _x24832 = (w - n); /*size_t*/
  _x24827 = kk_std_core_repeatz(_x24828, _x24832, _ctx); /*string*/
  return kk_std_core__lp__plus__plus__1_rp_(s, _x24827, _ctx);
}
 
// Is `pre`  a prefix of `s`? If so, returns a slice
// of `s` following `pre` up to the end of `s`.

kk_std_core_types__maybe kk_std_core_starts_with(kk_string_t s, kk_string_t pre, kk_context_t* _ctx) { /* (s : string, pre : string) -> maybe<sslice> */ 
  bool _match_23448;
  kk_string_t _x24833 = kk_string_dup(s); /*string*/
  kk_string_t _x24834 = kk_string_dup(pre); /*string*/
  _match_23448 = kk_string_starts_with(_x24833,_x24834,kk_context()); /*bool*/
  if (_match_23448) {
    kk_std_core__sslice _b_23013_23012;
    kk_string_t _x24835 = kk_string_dup(s); /*string*/
    size_t _x24836;
    kk_string_t _x24837 = kk_string_dup(pre); /*string*/
    _x24836 = kk_string_len(_x24837,kk_context()); /*size_t*/
    size_t _x24838;
    size_t _x24839 = kk_string_len(s,kk_context()); /*size_t*/
    size_t _x24840 = kk_string_len(pre,kk_context()); /*size_t*/
    _x24838 = (_x24839 - _x24840); /*size_t*/
    _b_23013_23012 = kk_std_core__new_Sslice(_x24835, _x24836, _x24838, _ctx); /*sslice*/
    return kk_std_core_types__new_Just(kk_std_core__sslice_box(_b_23013_23012, _ctx), _ctx);
  }
  kk_string_drop(pre, _ctx);
  kk_string_drop(s, _ctx);
  return kk_std_core_types__new_Nothing(_ctx);
}
 
// Trim off a substring `sub` while `s` starts with that string.

kk_string_t kk_std_core_trim_left_1(kk_string_t s, kk_string_t sub, kk_context_t* _ctx) { /* (s : string, sub : string) -> string */ 
  kk__tailcall: ;
  bool _match_23446;
  kk_string_t _x24841 = kk_string_dup(sub); /*string*/
  _match_23446 = kk_std_core_is_empty_2(_x24841, _ctx); /*bool*/
  if (_match_23446) {
    kk_string_drop(sub, _ctx);
    return s;
  }
  kk_std_core_types__maybe _match_23447;
  kk_string_t _x24842 = kk_string_dup(s); /*string*/
  kk_string_t _x24843 = kk_string_dup(sub); /*string*/
  _match_23447 = kk_std_core_starts_with(_x24842, _x24843, _ctx); /*maybe<sslice>*/
  if (kk_std_core_types__is_Just(_match_23447)) {
    kk_box_t _box_x23014 = _match_23447._cons.Just.value;
    kk_std_core__sslice slice0 = kk_std_core__sslice_unbox(_box_x23014, NULL);
    kk_string_drop(s, _ctx);
    kk_std_core__sslice_dup(slice0);
    kk_std_core_types__maybe_drop(_match_23447, _ctx);
    { // tailcall
      kk_string_t _x24845 = kk_std_core_string_3(slice0, _ctx); /*string*/
      s = _x24845;
      goto kk__tailcall;
    }
  }
  kk_string_drop(sub, _ctx);
  return s;
}
 
// Trim off a substring `sub` while `s` ends with that string.

kk_string_t kk_std_core_trim_right_1(kk_string_t s, kk_string_t sub, kk_context_t* _ctx) { /* (s : string, sub : string) -> string */ 
  kk__tailcall: ;
  bool _match_23444;
  kk_string_t _x24846 = kk_string_dup(sub); /*string*/
  _match_23444 = kk_std_core_is_empty_2(_x24846, _ctx); /*bool*/
  if (_match_23444) {
    kk_string_drop(sub, _ctx);
    return s;
  }
  kk_std_core_types__maybe _match_23445;
  kk_string_t _x24847 = kk_string_dup(s); /*string*/
  kk_string_t _x24848 = kk_string_dup(sub); /*string*/
  _match_23445 = kk_std_core_ends_with(_x24847, _x24848, _ctx); /*maybe<sslice>*/
  if (kk_std_core_types__is_Just(_match_23445)) {
    kk_box_t _box_x23015 = _match_23445._cons.Just.value;
    kk_std_core__sslice slice0 = kk_std_core__sslice_unbox(_box_x23015, NULL);
    kk_string_drop(s, _ctx);
    kk_std_core__sslice_dup(slice0);
    kk_std_core_types__maybe_drop(_match_23445, _ctx);
    { // tailcall
      kk_string_t _x24850 = kk_std_core_string_3(slice0, _ctx); /*string*/
      s = _x24850;
      goto kk__tailcall;
    }
  }
  kk_string_drop(sub, _ctx);
  return s;
}
 
// Parse an integer using `parseInt`. If an illegal digit character is encountered the
// `default` value is returned. An empty string will also result in `default`.

kk_integer_t kk_std_core_parse_int_default(kk_string_t s, kk_std_core_types__optional default0, kk_std_core_types__optional hex, kk_context_t* _ctx) { /* (s : string, default : optional<int>, hex : optional<bool>) -> int */ 
  bool _match_23443;
  kk_string_t _x24856 = kk_string_dup(s); /*string*/
  _match_23443 = kk_std_core_is_empty_2(_x24856, _ctx); /*bool*/
  if (_match_23443) {
    kk_std_core_types__optional_drop(hex, _ctx);
    kk_string_drop(s, _ctx);
    if (kk_std_core_types__is_Optional(default0)) {
      kk_box_t _box_x23017 = default0._cons.Optional.value;
      kk_integer_t _default_19378 = kk_integer_unbox(_box_x23017);
      kk_integer_dup(_default_19378);
      kk_std_core_types__optional_drop(default0, _ctx);
      return _default_19378;
    }
    return kk_integer_from_small(0);
  }
  kk_std_core_types__maybe m_21736;
  kk_std_core_types__optional hex0_21739;
  kk_box_t _x24858;
  bool _x24859;
  if (kk_std_core_types__is_Optional(hex)) {
    kk_box_t _box_x23018 = hex._cons.Optional.value;
    bool _hex_19382 = kk_bool_unbox(_box_x23018);
    kk_std_core_types__optional_drop(hex, _ctx);
    _x24859 = _hex_19382; /*bool*/
    goto _match24860;
  }
  _x24859 = false; /*bool*/
  _match24860: ;
  _x24858 = kk_bool_box(_x24859); /*108*/
  hex0_21739 = kk_std_core_types__new_Optional(_x24858, _ctx); /*optional<bool>*/
  kk_string_t _x24862 = kk_std_core_trim(s, _ctx); /*string*/
  bool _x24863;
  if (kk_std_core_types__is_Optional(hex0_21739)) {
    kk_box_t _box_x23021 = hex0_21739._cons.Optional.value;
    bool _hex_19366 = kk_bool_unbox(_box_x23021);
    kk_std_core_types__optional_drop(hex0_21739, _ctx);
    _x24863 = _hex_19366; /*bool*/
    goto _match24864;
  }
  _x24863 = false; /*bool*/
  _match24864: ;
  m_21736 = kk_std_core_xparse_int(_x24862, _x24863, _ctx); /*maybe<int>*/
  if (kk_std_core_types__is_Nothing(m_21736)) {
    if (kk_std_core_types__is_Optional(default0)) {
      kk_box_t _box_x23022 = default0._cons.Optional.value;
      kk_integer_t _default_193780 = kk_integer_unbox(_box_x23022);
      kk_integer_dup(_default_193780);
      kk_std_core_types__optional_drop(default0, _ctx);
      return _default_193780;
    }
    return kk_integer_from_small(0);
  }
  kk_box_t _box_x23023 = m_21736._cons.Just.value;
  kk_integer_t x = kk_integer_unbox(_box_x23023);
  kk_integer_dup(x);
  kk_std_core_types__maybe_drop(m_21736, _ctx);
  kk_std_core_types__optional_drop(default0, _ctx);
  return x;
}
 
// monadic lift

kk_std_core_types__tuple2_ kk_std_core__mlift21220_partition_acc(kk_std_core__list acc1, kk_std_core__list acc2, kk_function_t pred, kk_box_t x, kk_std_core__list xx, bool _y_213, kk_context_t* _ctx) { /* forall<a,e> (acc1 : list<a>, acc2 : list<a>, pred : (a) -> e bool, x : a, xx : list<a>, bool) -> e (list<a>, list<a>) */ 
  if (_y_213) {
    kk_std_core__list _x24868 = kk_std_core__new_Cons(kk_reuse_null, x, acc1, _ctx); /*list<61>*/
    return kk_std_core_partition_acc(xx, pred, _x24868, acc2, _ctx);
  }
  kk_std_core__list _x24869 = kk_std_core__new_Cons(kk_reuse_null, x, acc2, _ctx); /*list<61>*/
  return kk_std_core_partition_acc(xx, pred, acc1, _x24869, _ctx);
}


// lift anonymous function
struct kk_std_core_partition_acc_fun24874__t {
  struct kk_function_s _base;
  kk_std_core__list acc10;
  kk_std_core__list acc20;
  kk_function_t pred0;
  kk_box_t x0;
  kk_std_core__list xx0;
};
static kk_box_t kk_std_core_partition_acc_fun24874(kk_function_t _fself, kk_box_t _b_23027, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_partition_acc_fun24874(kk_std_core__list acc10, kk_std_core__list acc20, kk_function_t pred0, kk_box_t x0, kk_std_core__list xx0, kk_context_t* _ctx) {
  struct kk_std_core_partition_acc_fun24874__t* _self = kk_function_alloc_as(struct kk_std_core_partition_acc_fun24874__t, 6, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_partition_acc_fun24874, kk_context());
  _self->acc10 = acc10;
  _self->acc20 = acc20;
  _self->pred0 = pred0;
  _self->x0 = x0;
  _self->xx0 = xx0;
  return &_self->_base;
}

static kk_box_t kk_std_core_partition_acc_fun24874(kk_function_t _fself, kk_box_t _b_23027, kk_context_t* _ctx) {
  struct kk_std_core_partition_acc_fun24874__t* _self = kk_function_as(struct kk_std_core_partition_acc_fun24874__t*, _fself);
  kk_std_core__list acc10 = _self->acc10; /* list<19514> */
  kk_std_core__list acc20 = _self->acc20; /* list<19514> */
  kk_function_t pred0 = _self->pred0; /* (19514) -> 19515 bool */
  kk_box_t x0 = _self->x0; /* 19514 */
  kk_std_core__list xx0 = _self->xx0; /* list<19514> */
  kk_drop_match(_self, {kk_std_core__list_dup(acc10);kk_std_core__list_dup(acc20);kk_function_dup(pred0);kk_box_dup(x0);kk_std_core__list_dup(xx0);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x24875;
  bool _x24876 = kk_bool_unbox(_b_23027); /*bool*/
  _x24875 = kk_std_core__mlift21220_partition_acc(acc10, acc20, pred0, x0, xx0, _x24876, _ctx); /*(list<19514>, list<19514>)*/
  return kk_std_core_types__tuple2__box(_x24875, _ctx);
}

kk_std_core_types__tuple2_ kk_std_core_partition_acc(kk_std_core__list xs, kk_function_t pred0, kk_std_core__list acc10, kk_std_core__list acc20, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, pred : (a) -> e bool, acc1 : list<a>, acc2 : list<a>) -> e (list<a>, list<a>) */ 
  kk__tailcall: ;
  if (kk_std_core__is_Nil(xs)) {
    kk_function_drop(pred0, _ctx);
    kk_std_core__list _b_23028_23024 = kk_std_core_reverse(acc10, _ctx); /*list<19514>*/;
    kk_std_core__list _b_23029_23025 = kk_std_core_reverse(acc20, _ctx); /*list<19514>*/;
    return kk_std_core_types__new_dash__lp__comma__rp_(kk_std_core__list_box(_b_23028_23024, _ctx), kk_std_core__list_box(_b_23029_23025, _ctx), _ctx);
  }
  struct kk_std_core_Cons* _con24870 = kk_std_core__as_Cons(xs);
  kk_box_t x0 = _con24870->head;
  kk_std_core__list xx0 = _con24870->tail;
  kk_reuse_t _ru_23398 = kk_reuse_null; /*reuse*/;
  if (kk_std_core__list_is_unique(xs)) {
    _ru_23398 = (kk_std_core__list_reuse(xs));
  }
  else {
    kk_box_dup(x0);
    kk_std_core__list_dup(xx0);
    kk_std_core__list_decref(xs, _ctx);
    _ru_23398 = kk_reuse_null;
  }
  bool x0_21740;
  kk_function_t _x24872 = kk_function_dup(pred0); /*(19514) -> 19515 bool*/
  kk_box_t _x24871 = kk_box_dup(x0); /*19514*/
  x0_21740 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_context_t*), _x24872, (_x24872, _x24871, _ctx)); /*bool*/
  if (kk_yielding(kk_context())) {
    kk_reuse_drop(_ru_23398, _ctx);
    kk_box_t _x24873 = kk_std_core_hnd_yield_extend(kk_std_core_new_partition_acc_fun24874(acc10, acc20, pred0, x0, xx0, _ctx), _ctx); /*3991*/
    return kk_std_core_types__tuple2__unbox(_x24873, _ctx);
  }
  if (x0_21740) {
    { // tailcall
      kk_std_core__list _x24877;
      bool _x24878 = _ru_23398!=NULL; /*bool*/
      if (_x24878) {
        struct kk_std_core_Cons* _con24879 = (struct kk_std_core_Cons*)_ru_23398;
        _con24879->tail = acc10;
        _x24877 = kk_std_core__base_Cons(_con24879); /*list<61>*/
      }
      else {
        _x24877 = kk_std_core__new_Cons(kk_reuse_null, x0, acc10, _ctx); /*list<61>*/
      }
      xs = xx0;
      acc10 = _x24877;
      goto kk__tailcall;
    }
  }
  { // tailcall
    kk_std_core__list _x24880;
    bool _x24881 = _ru_23398!=NULL; /*bool*/
    if (_x24881) {
      struct kk_std_core_Cons* _con24882 = (struct kk_std_core_Cons*)_ru_23398;
      _con24882->tail = acc20;
      _x24880 = kk_std_core__base_Cons(_con24882); /*list<61>*/
    }
    else {
      _x24880 = kk_std_core__new_Cons(kk_reuse_null, x0, acc20, _ctx); /*list<61>*/
    }
    xs = xx0;
    acc20 = _x24880;
    goto kk__tailcall;
  }
}
 
// redirect `print` and `println` calls to a specified function.


// lift anonymous function
struct kk_std_core_print_redirect_fun24883__t {
  struct kk_function_s _base;
  kk_function_t print0;
};
static kk_box_t kk_std_core_print_redirect_fun24883(kk_function_t _fself, kk_box_t _b_23035, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_print_redirect_fun24883(kk_function_t print0, kk_context_t* _ctx) {
  struct kk_std_core_print_redirect_fun24883__t* _self = kk_function_alloc_as(struct kk_std_core_print_redirect_fun24883__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_print_redirect_fun24883, kk_context());
  _self->print0 = print0;
  return &_self->_base;
}

static kk_box_t kk_std_core_print_redirect_fun24883(kk_function_t _fself, kk_box_t _b_23035, kk_context_t* _ctx) {
  struct kk_std_core_print_redirect_fun24883__t* _self = kk_function_as(struct kk_std_core_print_redirect_fun24883__t*, _fself);
  kk_function_t print0 = _self->print0; /* (msg : string) -> console () */
  kk_drop_match(_self, {kk_function_dup(print0);}, {}, _ctx)
  kk_unit_t _x24884 = kk_Unit;
  kk_string_t _x24885 = kk_string_unbox(_b_23035); /*string*/
  kk_function_call(kk_unit_t, (kk_function_t, kk_string_t, kk_context_t*), print0, (print0, _x24885, _ctx));
  return kk_unit_box(_x24884);
}

kk_unit_t kk_std_core_print_redirect(kk_function_t print0, kk_context_t* _ctx) { /* (print : (msg : string) -> console ()) -> io () */ 
  kk_std_core_types__maybe _b_23039_23037 = kk_std_core_types__new_Just(kk_function_box(kk_std_core_new_print_redirect_fun24883(print0, _ctx)), _ctx); /*maybe<(msg : string) -> console ()>*/;
  kk_ref_t _x24886 = kk_ref_dup(kk_std_core_redirect); /*ref<global,maybe<(string) -> console ()>>*/
  kk_ref_set(_x24886,(kk_std_core_types__maybe_box(_b_23039_23037, _ctx)),kk_context()); return kk_Unit;
}
extern bool kk_std_core_remove_fun24887(kk_function_t _fself, kk_box_t x, kk_context_t* _ctx) {
  struct kk_std_core_remove_fun24887__t* _self = kk_function_as(struct kk_std_core_remove_fun24887__t*, _fself);
  kk_function_t pred = _self->pred; /* (19585) -> bool */
  kk_drop_match(_self, {kk_function_dup(pred);}, {}, _ctx)
  bool _x24888 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_context_t*), pred, (pred, x, _ctx)); /*bool*/
  return !(_x24888);
}
extern kk_unit_t kk_std_core_repeat_fun24890_1(kk_function_t _fself, kk_integer_t i, kk_context_t* _ctx) {
  struct kk_std_core_repeat_fun24890__t_1* _self = kk_function_as(struct kk_std_core_repeat_fun24890__t_1*, _fself);
  kk_function_t action = _self->action; /* () -> 19604 () */
  kk_drop_match(_self, {kk_function_dup(action);}, {}, _ctx)
  kk_integer_drop(i, _ctx);
  return kk_function_call(kk_unit_t, (kk_function_t, kk_context_t*), action, (action, _ctx));
}
 
// Create a list of `n`  repeated elementes `x`

kk_std_core__list kk_std_core__ctail_replicate(kk_box_t x, kk_integer_t n, kk_std_core_types__ctail _acc, kk_context_t* _ctx) { /* forall<a> (x : a, n : int, ctail<list<a>>) -> list<a> */ 
  kk__tailcall: ;
  bool _match_23441;
  kk_integer_t _x24891 = kk_integer_dup(n); /*int*/
  _match_23441 = kk_integer_gt(_x24891,(kk_integer_from_small(0)),kk_context()); /*bool*/
  if (_match_23441) {
    kk_std_core__list _ctail_21151 = kk_std_core__list_hole(); /*list<19661>*/;
    kk_std_core__list _ctail_21152;
    kk_box_t _x24892 = kk_box_dup(x); /*19661*/
    _ctail_21152 = kk_std_core__new_Cons(kk_reuse_null, _x24892, _ctail_21151, _ctx); /*list<19661>*/
    { // tailcall
      kk_integer_t _x24893 = kk_std_core_dec(n, _ctx); /*int*/
      kk_std_core_types__ctail _x24894;
      kk_box_t* field_21749 = (kk_box_t*)((&kk_std_core__as_Cons(_ctail_21152)->tail)); /*cfield<list<19661>>*/;
      if (kk_std_core_types__is_CTail(_acc)) {
        kk_box_t _box_x23047 = _acc._cons.CTail._field1;
        kk_box_t* last0 = _acc._cons.CTail._field2;
        kk_std_core__list head0 = kk_std_core__list_unbox(_box_x23047, NULL);
        kk_std_core__list_dup(head0);
        kk_std_core_types__ctail_drop(_acc, _ctx);
        kk_unit_t __ = kk_Unit;
        *(last0) = kk_std_core__list_box(_ctail_21152, _ctx);
        _x24894 = kk_std_core_types__new_CTail(kk_std_core__list_box(head0, _ctx), field_21749, _ctx); /*ctail<58>*/
        goto _match24895;
      }
      _x24894 = kk_std_core_types__new_CTail(kk_std_core__list_box(_ctail_21152, _ctx), field_21749, _ctx); /*ctail<58>*/
      _match24895: ;
      n = _x24893;
      _acc = _x24894;
      goto kk__tailcall;
    }
  }
  kk_integer_drop(n, _ctx);
  kk_box_drop(x, _ctx);
  if (kk_std_core_types__is_CTail(_acc)) {
    kk_box_t _box_x23056 = _acc._cons.CTail._field1;
    kk_box_t* last00 = _acc._cons.CTail._field2;
    kk_std_core__list head00 = kk_std_core__list_unbox(_box_x23056, NULL);
    kk_std_core__list_dup(head00);
    kk_std_core_types__ctail_drop(_acc, _ctx);
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
  kk_string_t _x24898;
  kk_define_string_literal(, _s24899, 1, "(")
  _x24898 = kk_string_dup(_s24899); /*string*/
  kk_string_t _x24900;
  kk_string_t _x24901;
  kk_box_t _x24902;
  kk_box_t _x = x.fst;
  kk_box_dup(_x);
  _x24902 = _x; /*20019*/
  _x24901 = kk_function_call(kk_string_t, (kk_function_t, kk_box_t, kk_context_t*), showfst, (showfst, _x24902, _ctx)); /*string*/
  kk_string_t _x24903;
  kk_string_t _x24904;
  kk_define_string_literal(, _s24905, 1, ",")
  _x24904 = kk_string_dup(_s24905); /*string*/
  kk_string_t _x24906;
  kk_string_t _x24907;
  kk_box_t _x24908;
  kk_box_t _x0 = x.snd;
  kk_box_dup(_x0);
  kk_std_core_types__tuple2__drop(x, _ctx);
  _x24908 = _x0; /*20020*/
  _x24907 = kk_function_call(kk_string_t, (kk_function_t, kk_box_t, kk_context_t*), showsnd, (showsnd, _x24908, _ctx)); /*string*/
  kk_string_t _x24909;
  kk_define_string_literal(, _s24910, 1, ")")
  _x24909 = kk_string_dup(_s24910); /*string*/
  _x24906 = kk_std_core__lp__plus__plus__1_rp_(_x24907, _x24909, _ctx); /*string*/
  _x24903 = kk_std_core__lp__plus__plus__1_rp_(_x24904, _x24906, _ctx); /*string*/
  _x24900 = kk_std_core__lp__plus__plus__1_rp_(_x24901, _x24903, _ctx); /*string*/
  return kk_std_core__lp__plus__plus__1_rp_(_x24898, _x24900, _ctx);
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
  kk_std_core__list _b_23067_23065 = kk_std_core_reverse(acc, _ctx); /*list<20021>*/;
  return kk_std_core_types__new_dash__lp__comma__rp_(kk_std_core__list_box(_b_23067_23065, _ctx), kk_std_core__list_box(ys, _ctx), _ctx);
}
 
// lift


// lift anonymous function
struct kk_std_core__lift21060_span_fun24916__t {
  struct kk_function_s _base;
  kk_std_core__list acc0;
  kk_function_t predicate0;
  kk_box_t y0;
  kk_std_core__list ys0;
  kk_std_core__list yy0;
};
static kk_box_t kk_std_core__lift21060_span_fun24916(kk_function_t _fself, kk_box_t _b_23070, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_lift21060_span_fun24916(kk_std_core__list acc0, kk_function_t predicate0, kk_box_t y0, kk_std_core__list ys0, kk_std_core__list yy0, kk_context_t* _ctx) {
  struct kk_std_core__lift21060_span_fun24916__t* _self = kk_function_alloc_as(struct kk_std_core__lift21060_span_fun24916__t, 6, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__lift21060_span_fun24916, kk_context());
  _self->acc0 = acc0;
  _self->predicate0 = predicate0;
  _self->y0 = y0;
  _self->ys0 = ys0;
  _self->yy0 = yy0;
  return &_self->_base;
}

static kk_box_t kk_std_core__lift21060_span_fun24916(kk_function_t _fself, kk_box_t _b_23070, kk_context_t* _ctx) {
  struct kk_std_core__lift21060_span_fun24916__t* _self = kk_function_as(struct kk_std_core__lift21060_span_fun24916__t*, _fself);
  kk_std_core__list acc0 = _self->acc0; /* list<20021> */
  kk_function_t predicate0 = _self->predicate0; /* (20021) -> 20022 bool */
  kk_box_t y0 = _self->y0; /* 20021 */
  kk_std_core__list ys0 = _self->ys0; /* list<20021> */
  kk_std_core__list yy0 = _self->yy0; /* list<20021> */
  kk_drop_match(_self, {kk_std_core__list_dup(acc0);kk_function_dup(predicate0);kk_box_dup(y0);kk_std_core__list_dup(ys0);kk_std_core__list_dup(yy0);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x24917;
  bool _x24918 = kk_bool_unbox(_b_23070); /*bool*/
  _x24917 = kk_std_core__mlift21221_op(acc0, predicate0, y0, ys0, yy0, _x24918, _ctx); /*(list<20021>, list<20021>)*/
  return kk_std_core_types__tuple2__box(_x24917, _ctx);
}

kk_std_core_types__tuple2_ kk_std_core__lift21060_span(kk_function_t predicate0, kk_std_core__list ys0, kk_std_core__list acc0, kk_context_t* _ctx) { /* forall<a,e> (predicate : (a) -> e bool, ys : list<a>, acc : list<a>) -> e (list<a>, list<a>) */ 
  kk__tailcall: ;
  if (kk_std_core__is_Cons(ys0)) {
    struct kk_std_core_Cons* _con24911 = kk_std_core__as_Cons(ys0);
    kk_box_t y0 = _con24911->head;
    kk_std_core__list yy0 = _con24911->tail;
    kk_box_dup(y0);
    kk_std_core__list_dup(yy0);
    kk_reuse_t _ru_23399;
    kk_std_core__list _x24912 = kk_std_core__list_dup(ys0); /*list<20021>*/
    _ru_23399 = kk_std_core__list_dropn_reuse(_x24912, ((int32_t)2), _ctx); /*reuse*/
    bool x_21754;
    kk_function_t _x24914 = kk_function_dup(predicate0); /*(20021) -> 20022 bool*/
    kk_box_t _x24913 = kk_box_dup(y0); /*20021*/
    x_21754 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_context_t*), _x24914, (_x24914, _x24913, _ctx)); /*bool*/
    if (kk_yielding(kk_context())) {
      kk_reuse_drop(_ru_23399, _ctx);
      kk_box_t _x24915 = kk_std_core_hnd_yield_extend(kk_std_core__new_lift21060_span_fun24916(acc0, predicate0, y0, ys0, yy0, _ctx), _ctx); /*3991*/
      return kk_std_core_types__tuple2__unbox(_x24915, _ctx);
    }
    if (x_21754) {
      kk_std_core__list_dropn(ys0, ((int32_t)2), _ctx);
      kk_std_core__list acc0_210980;
      bool _x24919 = _ru_23399!=NULL; /*bool*/
      if (_x24919) {
        struct kk_std_core_Cons* _con24920 = (struct kk_std_core_Cons*)_ru_23399;
        _con24920->tail = acc0;
        acc0_210980 = kk_std_core__base_Cons(_con24920); /*list<20021>*/
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
    kk_reuse_drop(_ru_23399, _ctx);
    kk_function_drop(predicate0, _ctx);
    kk_box_drop(y0, _ctx);
    kk_std_core__list_drop(yy0, _ctx);
    kk_std_core__list _b_23077_23071 = kk_std_core_reverse(acc0, _ctx); /*list<20021>*/;
    return kk_std_core_types__new_dash__lp__comma__rp_(kk_std_core__list_box(_b_23077_23071, _ctx), kk_std_core__list_box(ys0, _ctx), _ctx);
  }
  kk_function_drop(predicate0, _ctx);
  kk_std_core__list _b_23079_23073 = kk_std_core_reverse(acc0, _ctx); /*list<20021>*/;
  return kk_std_core_types__new_dash__lp__comma__rp_(kk_std_core__list_box(_b_23079_23073, _ctx), kk_std_core__list_box(ys0, _ctx), _ctx);
}
 
// Return the sum of a list of integers


// lift anonymous function
struct kk_std_core_sum_fun24922__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_sum_fun24922(kk_function_t _fself, kk_box_t _b_23084, kk_box_t _b_23085, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_sum_fun24922(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_sum_fun24922, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_core_sum_fun24922(kk_function_t _fself, kk_box_t _b_23084, kk_box_t _b_23085, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_integer_t _x24923;
  kk_integer_t _x24924 = kk_integer_unbox(_b_23084); /*int*/
  kk_integer_t _x24925 = kk_integer_unbox(_b_23085); /*int*/
  _x24923 = kk_integer_add(_x24924,_x24925,kk_context()); /*int*/
  return kk_integer_box(_x24923);
}

kk_integer_t kk_std_core_sum(kk_std_core__list xs, kk_context_t* _ctx) { /* (xs : list<int>) -> int */ 
  kk_box_t _x24921 = kk_std_core_foldl(xs, kk_integer_box(kk_integer_from_small(0)), kk_std_core_new_sum_fun24922(_ctx), _ctx); /*15010*/
  return kk_integer_unbox(_x24921);
}
 
// Return the tail of list. Returns the empty list if `xs` is empty.

kk_std_core__list kk_std_core_tail_1(kk_std_core__list xs, kk_context_t* _ctx) { /* forall<a> (xs : list<a>) -> list<a> */ 
  if (kk_std_core__is_Cons(xs)) {
    struct kk_std_core_Cons* _con24926 = kk_std_core__as_Cons(xs);
    kk_box_t _pat0 = _con24926->head;
    kk_std_core__list xx = _con24926->tail;
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
  kk_std_core__sslice _x24927;
  kk_std_core__sslice slice_21758;
  kk_std_core__sslice slice0 = kk_std_core_first1(s, _ctx); /*sslice*/;
  bool _match_23437;
  kk_integer_t _x24928;
  kk_std_core_types__optional _match_23439 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
  if (kk_std_core_types__is_Optional(_match_23439)) {
    kk_box_t _box_x23091 = _match_23439._cons.Optional.value;
    kk_integer_t _n_12425 = kk_integer_unbox(_box_x23091);
    kk_integer_dup(_n_12425);
    kk_std_core_types__optional_drop(_match_23439, _ctx);
    _x24928 = _n_12425; /*int*/
    goto _match24929;
  }
  _x24928 = kk_integer_from_small(1); /*int*/
  _match24929: ;
  _match_23437 = kk_integer_eq(_x24928,(kk_integer_from_small(1)),kk_context()); /*bool*/
  if (_match_23437) {
    slice_21758 = slice0; /*sslice*/
  }
  else {
    kk_integer_t _x24931;
    kk_integer_t _x24932;
    kk_std_core_types__optional _match_23438 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
    if (kk_std_core_types__is_Optional(_match_23438)) {
      kk_box_t _box_x23092 = _match_23438._cons.Optional.value;
      kk_integer_t _n_124250 = kk_integer_unbox(_box_x23092);
      kk_integer_dup(_n_124250);
      kk_std_core_types__optional_drop(_match_23438, _ctx);
      _x24932 = _n_124250; /*int*/
      goto _match24933;
    }
    _x24932 = kk_integer_from_small(1); /*int*/
    _match24933: ;
    _x24931 = kk_integer_sub(_x24932,(kk_integer_from_small(1)),kk_context()); /*int*/
    slice_21758 = kk_std_core_extend(slice0, _x24931, _ctx); /*sslice*/
  }
  kk_string_t s0 = slice_21758.str;
  size_t start0 = slice_21758.start;
  size_t len0 = slice_21758.len;
  kk_string_dup(s0);
  kk_std_core__sslice_drop(slice_21758, _ctx);
  kk_string_t _x24935 = kk_string_dup(s0); /*string*/
  size_t _x24936 = (start0 + len0); /*size_t*/
  size_t _x24937;
  size_t _x24938 = kk_string_len(s0,kk_context()); /*size_t*/
  size_t _x24939 = (start0 + len0); /*size_t*/
  _x24937 = (_x24938 - _x24939); /*size_t*/
  _x24927 = kk_std_core__new_Sslice(_x24935, _x24936, _x24937, _ctx); /*sslice*/
  return kk_std_core_string_3(_x24927, _ctx);
}
 
// monadic lift

kk_std_core__list kk_std_core__mlift21222_op(kk_std_core_types__ctail _acc, kk_function_t predicate, kk_box_t x, kk_std_core__list xx, bool _y_226, kk_context_t* _ctx) { /* forall<a,e> (ctail<list<a>>, predicate : (a) -> e bool, x : a, xx : list<a>, bool) -> e list<a> */ 
  if (_y_226) {
    kk_std_core__list _ctail_21153 = kk_std_core__list_hole(); /*list<20220>*/;
    kk_std_core__list _ctail_21154 = kk_std_core__new_Cons(kk_reuse_null, x, _ctail_21153, _ctx); /*list<20220>*/;
    kk_std_core_types__ctail _x24940;
    kk_box_t* field_21763 = (kk_box_t*)((&kk_std_core__as_Cons(_ctail_21154)->tail)); /*cfield<list<20220>>*/;
    if (kk_std_core_types__is_CTail(_acc)) {
      kk_box_t _box_x23099 = _acc._cons.CTail._field1;
      kk_box_t* last0 = _acc._cons.CTail._field2;
      kk_std_core__list head0 = kk_std_core__list_unbox(_box_x23099, NULL);
      kk_std_core__list_dup(head0);
      kk_std_core_types__ctail_drop(_acc, _ctx);
      kk_unit_t __ = kk_Unit;
      *(last0) = kk_std_core__list_box(_ctail_21154, _ctx);
      _x24940 = kk_std_core_types__new_CTail(kk_std_core__list_box(head0, _ctx), field_21763, _ctx); /*ctail<58>*/
      goto _match24941;
    }
    _x24940 = kk_std_core_types__new_CTail(kk_std_core__list_box(_ctail_21154, _ctx), field_21763, _ctx); /*ctail<58>*/
    _match24941: ;
    return kk_std_core__ctail_take_while(xx, predicate, _x24940, _ctx);
  }
  kk_function_drop(predicate, _ctx);
  kk_box_drop(x, _ctx);
  kk_std_core__list_drop(xx, _ctx);
  if (kk_std_core_types__is_CTail(_acc)) {
    kk_box_t _box_x23108 = _acc._cons.CTail._field1;
    kk_box_t* last00 = _acc._cons.CTail._field2;
    kk_std_core__list head00 = kk_std_core__list_unbox(_box_x23108, NULL);
    kk_std_core__list_dup(head00);
    kk_std_core_types__ctail_drop(_acc, _ctx);
    kk_unit_t __0 = kk_Unit;
    *(last00) = kk_std_core__list_box(kk_std_core__new_Nil(_ctx), _ctx);
    return head00;
  }
  return kk_std_core__new_Nil(_ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_core__mlift21223_op_fun24944__t {
  struct kk_function_s _base;
  kk_function_t _accm;
  kk_box_t x0;
};
static kk_std_core__list kk_std_core__mlift21223_op_fun24944(kk_function_t _fself, kk_std_core__list _ctail_21156, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_mlift21223_op_fun24944(kk_function_t _accm, kk_box_t x0, kk_context_t* _ctx) {
  struct kk_std_core__mlift21223_op_fun24944__t* _self = kk_function_alloc_as(struct kk_std_core__mlift21223_op_fun24944__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__mlift21223_op_fun24944, kk_context());
  _self->_accm = _accm;
  _self->x0 = x0;
  return &_self->_base;
}

static kk_std_core__list kk_std_core__mlift21223_op_fun24944(kk_function_t _fself, kk_std_core__list _ctail_21156, kk_context_t* _ctx) {
  struct kk_std_core__mlift21223_op_fun24944__t* _self = kk_function_as(struct kk_std_core__mlift21223_op_fun24944__t*, _fself);
  kk_function_t _accm = _self->_accm; /* (list<20220>) -> list<20220> */
  kk_box_t x0 = _self->x0; /* 20220 */
  kk_drop_match(_self, {kk_function_dup(_accm);kk_box_dup(x0);}, {}, _ctx)
  kk_std_core__list _x24945 = kk_std_core__new_Cons(kk_reuse_null, x0, _ctail_21156, _ctx); /*list<61>*/
  return kk_function_call(kk_std_core__list, (kk_function_t, kk_std_core__list, kk_context_t*), _accm, (_accm, _x24945, _ctx));
}

kk_std_core__list kk_std_core__mlift21223_op(kk_function_t _accm, kk_function_t predicate0, kk_box_t x0, kk_std_core__list xx0, bool _y_230, kk_context_t* _ctx) { /* forall<a,e> ((list<a>) -> list<a>, predicate : (a) -> e bool, x : a, xx : list<a>, bool) -> e list<a> */ 
  if (_y_230) {
    return kk_std_core__ctailm_take_while(xx0, predicate0, kk_std_core__new_mlift21223_op_fun24944(_accm, x0, _ctx), _ctx);
  }
  kk_function_drop(predicate0, _ctx);
  kk_box_drop(x0, _ctx);
  kk_std_core__list_drop(xx0, _ctx);
  return kk_function_call(kk_std_core__list, (kk_function_t, kk_std_core__list, kk_context_t*), _accm, (_accm, kk_std_core__new_Nil(_ctx), _ctx));
}
 
// Keep only those initial elements that satisfy `predicate`


// lift anonymous function
struct kk_std_core__ctail_take_while_fun24950__t {
  struct kk_function_s _base;
  kk_function_t predicate1;
  kk_box_t x1;
  kk_std_core__list xx1;
  kk_std_core_types__ctail _acc0;
};
static kk_box_t kk_std_core__ctail_take_while_fun24950(kk_function_t _fself, kk_box_t _b_23118, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_ctail_take_while_fun24950(kk_function_t predicate1, kk_box_t x1, kk_std_core__list xx1, kk_std_core_types__ctail _acc0, kk_context_t* _ctx) {
  struct kk_std_core__ctail_take_while_fun24950__t* _self = kk_function_alloc_as(struct kk_std_core__ctail_take_while_fun24950__t, 6, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__ctail_take_while_fun24950, kk_context());
  _self->predicate1 = predicate1;
  _self->x1 = x1;
  _self->xx1 = xx1;
  _self->_acc0 = _acc0;
  return &_self->_base;
}

static kk_box_t kk_std_core__ctail_take_while_fun24950(kk_function_t _fself, kk_box_t _b_23118, kk_context_t* _ctx) {
  struct kk_std_core__ctail_take_while_fun24950__t* _self = kk_function_as(struct kk_std_core__ctail_take_while_fun24950__t*, _fself);
  kk_function_t predicate1 = _self->predicate1; /* (20220) -> 20221 bool */
  kk_box_t x1 = _self->x1; /* 20220 */
  kk_std_core__list xx1 = _self->xx1; /* list<20220> */
  kk_std_core_types__ctail _acc0 = _self->_acc0; /* ctail<list<20220>> */
  kk_drop_match(_self, {kk_function_dup(predicate1);kk_box_dup(x1);kk_std_core__list_dup(xx1);kk_std_core_types__ctail_dup(_acc0);}, {}, _ctx)
  kk_std_core__list _x24951;
  bool _x24952 = kk_bool_unbox(_b_23118); /*bool*/
  _x24951 = kk_std_core__mlift21222_op(_acc0, predicate1, x1, xx1, _x24952, _ctx); /*list<20220>*/
  return kk_std_core__list_box(_x24951, _ctx);
}

kk_std_core__list kk_std_core__ctail_take_while(kk_std_core__list xs, kk_function_t predicate1, kk_std_core_types__ctail _acc0, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, predicate : (a) -> e bool, ctail<list<a>>) -> e list<a> */ 
  kk__tailcall: ;
  if (kk_std_core__is_Cons(xs)) {
    struct kk_std_core_Cons* _con24946 = kk_std_core__as_Cons(xs);
    kk_box_t x1 = _con24946->head;
    kk_std_core__list xx1 = _con24946->tail;
    kk_reuse_t _ru_23401 = kk_reuse_null; /*reuse*/;
    if (kk_std_core__list_is_unique(xs)) {
      _ru_23401 = (kk_std_core__list_reuse(xs));
    }
    else {
      kk_box_dup(x1);
      kk_std_core__list_dup(xx1);
      kk_std_core__list_decref(xs, _ctx);
      _ru_23401 = kk_reuse_null;
    }
    bool x0_21766;
    kk_function_t _x24948 = kk_function_dup(predicate1); /*(20220) -> 20221 bool*/
    kk_box_t _x24947 = kk_box_dup(x1); /*20220*/
    x0_21766 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_context_t*), _x24948, (_x24948, _x24947, _ctx)); /*bool*/
    if (kk_yielding(kk_context())) {
      kk_reuse_drop(_ru_23401, _ctx);
      kk_box_t _x24949 = kk_std_core_hnd_yield_extend(kk_std_core__new_ctail_take_while_fun24950(predicate1, x1, xx1, _acc0, _ctx), _ctx); /*3991*/
      return kk_std_core__list_unbox(_x24949, _ctx);
    }
    if (x0_21766) {
      kk_std_core__list _ctail_211530 = kk_std_core__list_hole(); /*list<20220>*/;
      kk_std_core__list _ctail_211540;
      bool _x24953 = _ru_23401!=NULL; /*bool*/
      if (_x24953) {
        struct kk_std_core_Cons* _con24954 = (struct kk_std_core_Cons*)_ru_23401;
        _con24954->tail = _ctail_211530;
        _ctail_211540 = kk_std_core__base_Cons(_con24954); /*list<20220>*/
      }
      else {
        _ctail_211540 = kk_std_core__new_Cons(kk_reuse_null, x1, _ctail_211530, _ctx); /*list<20220>*/
      }
      { // tailcall
        kk_std_core_types__ctail _x24955;
        kk_box_t* field_21772 = (kk_box_t*)((&kk_std_core__as_Cons(_ctail_211540)->tail)); /*cfield<list<20220>>*/;
        if (kk_std_core_types__is_CTail(_acc0)) {
          kk_box_t _box_x23125 = _acc0._cons.CTail._field1;
          kk_box_t* last2 = _acc0._cons.CTail._field2;
          kk_std_core__list head1 = kk_std_core__list_unbox(_box_x23125, NULL);
          kk_std_core__list_dup(head1);
          kk_std_core_types__ctail_drop(_acc0, _ctx);
          kk_unit_t __1 = kk_Unit;
          *(last2) = kk_std_core__list_box(_ctail_211540, _ctx);
          _x24955 = kk_std_core_types__new_CTail(kk_std_core__list_box(head1, _ctx), field_21772, _ctx); /*ctail<58>*/
          goto _match24956;
        }
        _x24955 = kk_std_core_types__new_CTail(kk_std_core__list_box(_ctail_211540, _ctx), field_21772, _ctx); /*ctail<58>*/
        _match24956: ;
        xs = xx1;
        _acc0 = _x24955;
        goto kk__tailcall;
      }
    }
    kk_reuse_drop(_ru_23401, _ctx);
    kk_function_drop(predicate1, _ctx);
    kk_box_drop(x1, _ctx);
    kk_std_core__list_drop(xx1, _ctx);
    if (kk_std_core_types__is_CTail(_acc0)) {
      kk_box_t _box_x23134 = _acc0._cons.CTail._field1;
      kk_box_t* last01 = _acc0._cons.CTail._field2;
      kk_std_core__list head01 = kk_std_core__list_unbox(_box_x23134, NULL);
      kk_std_core__list_dup(head01);
      kk_std_core_types__ctail_drop(_acc0, _ctx);
      kk_unit_t __00 = kk_Unit;
      *(last01) = kk_std_core__list_box(kk_std_core__new_Nil(_ctx), _ctx);
      return head01;
    }
    return kk_std_core__new_Nil(_ctx);
  }
  kk_function_drop(predicate1, _ctx);
  if (kk_std_core_types__is_CTail(_acc0)) {
    kk_box_t _box_x23139 = _acc0._cons.CTail._field1;
    kk_box_t* last10 = _acc0._cons.CTail._field2;
    kk_std_core__list head10 = kk_std_core__list_unbox(_box_x23139, NULL);
    kk_std_core__list_dup(head10);
    kk_std_core_types__ctail_drop(_acc0, _ctx);
    kk_unit_t __10 = kk_Unit;
    *(last10) = kk_std_core__list_box(kk_std_core__new_Nil(_ctx), _ctx);
    return head10;
  }
  return kk_std_core__new_Nil(_ctx);
}
 
// Keep only those initial elements that satisfy `predicate`


// lift anonymous function
struct kk_std_core__ctailm_take_while_fun24964__t {
  struct kk_function_s _base;
  kk_function_t _accm0;
  kk_function_t predicate2;
  kk_box_t x2;
  kk_std_core__list xx2;
};
static kk_box_t kk_std_core__ctailm_take_while_fun24964(kk_function_t _fself, kk_box_t _b_23151, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_ctailm_take_while_fun24964(kk_function_t _accm0, kk_function_t predicate2, kk_box_t x2, kk_std_core__list xx2, kk_context_t* _ctx) {
  struct kk_std_core__ctailm_take_while_fun24964__t* _self = kk_function_alloc_as(struct kk_std_core__ctailm_take_while_fun24964__t, 5, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__ctailm_take_while_fun24964, kk_context());
  _self->_accm0 = _accm0;
  _self->predicate2 = predicate2;
  _self->x2 = x2;
  _self->xx2 = xx2;
  return &_self->_base;
}

static kk_box_t kk_std_core__ctailm_take_while_fun24964(kk_function_t _fself, kk_box_t _b_23151, kk_context_t* _ctx) {
  struct kk_std_core__ctailm_take_while_fun24964__t* _self = kk_function_as(struct kk_std_core__ctailm_take_while_fun24964__t*, _fself);
  kk_function_t _accm0 = _self->_accm0; /* (list<20220>) -> list<20220> */
  kk_function_t predicate2 = _self->predicate2; /* (20220) -> 20221 bool */
  kk_box_t x2 = _self->x2; /* 20220 */
  kk_std_core__list xx2 = _self->xx2; /* list<20220> */
  kk_drop_match(_self, {kk_function_dup(_accm0);kk_function_dup(predicate2);kk_box_dup(x2);kk_std_core__list_dup(xx2);}, {}, _ctx)
  kk_std_core__list _x24965;
  bool _x24966 = kk_bool_unbox(_b_23151); /*bool*/
  _x24965 = kk_std_core__mlift21223_op(_accm0, predicate2, x2, xx2, _x24966, _ctx); /*list<20220>*/
  return kk_std_core__list_box(_x24965, _ctx);
}


// lift anonymous function
struct kk_std_core__ctailm_take_while_fun24968__t {
  struct kk_function_s _base;
  kk_function_t _accm0;
  kk_box_t x2;
};
static kk_std_core__list kk_std_core__ctailm_take_while_fun24968(kk_function_t _fself, kk_std_core__list _ctail_211560, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_ctailm_take_while_fun24968(kk_function_t _accm0, kk_box_t x2, kk_context_t* _ctx) {
  struct kk_std_core__ctailm_take_while_fun24968__t* _self = kk_function_alloc_as(struct kk_std_core__ctailm_take_while_fun24968__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__ctailm_take_while_fun24968, kk_context());
  _self->_accm0 = _accm0;
  _self->x2 = x2;
  return &_self->_base;
}

static kk_std_core__list kk_std_core__ctailm_take_while_fun24968(kk_function_t _fself, kk_std_core__list _ctail_211560, kk_context_t* _ctx) {
  struct kk_std_core__ctailm_take_while_fun24968__t* _self = kk_function_as(struct kk_std_core__ctailm_take_while_fun24968__t*, _fself);
  kk_function_t _accm0 = _self->_accm0; /* (list<20220>) -> list<20220> */
  kk_box_t x2 = _self->x2; /* 20220 */
  kk_drop_match(_self, {kk_function_dup(_accm0);kk_box_dup(x2);}, {}, _ctx)
  kk_std_core__list _x24969 = kk_std_core__new_Cons(kk_reuse_null, x2, _ctail_211560, _ctx); /*list<61>*/
  return kk_function_call(kk_std_core__list, (kk_function_t, kk_std_core__list, kk_context_t*), _accm0, (_accm0, _x24969, _ctx));
}

kk_std_core__list kk_std_core__ctailm_take_while(kk_std_core__list xs0, kk_function_t predicate2, kk_function_t _accm0, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, predicate : (a) -> e bool, (list<a>) -> list<a>) -> e list<a> */ 
  kk__tailcall: ;
  if (kk_std_core__is_Cons(xs0)) {
    struct kk_std_core_Cons* _con24960 = kk_std_core__as_Cons(xs0);
    kk_box_t x2 = _con24960->head;
    kk_std_core__list xx2 = _con24960->tail;
    if (kk_std_core__list_is_unique(xs0)) {
      kk_std_core__list_free(xs0);
    }
    else {
      kk_box_dup(x2);
      kk_std_core__list_dup(xx2);
      kk_std_core__list_decref(xs0, _ctx);
    }
    bool x0_21777;
    kk_function_t _x24962 = kk_function_dup(predicate2); /*(20220) -> 20221 bool*/
    kk_box_t _x24961 = kk_box_dup(x2); /*20220*/
    x0_21777 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_context_t*), _x24962, (_x24962, _x24961, _ctx)); /*bool*/
    if (kk_yielding(kk_context())) {
      kk_box_t _x24963 = kk_std_core_hnd_yield_extend(kk_std_core__new_ctailm_take_while_fun24964(_accm0, predicate2, x2, xx2, _ctx), _ctx); /*3991*/
      return kk_std_core__list_unbox(_x24963, _ctx);
    }
    if (x0_21777) {
      { // tailcall
        kk_function_t _x24967 = kk_std_core__new_ctailm_take_while_fun24968(_accm0, x2, _ctx); /*(list<20220>) -> list<20220>*/
        xs0 = xx2;
        _accm0 = _x24967;
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
struct kk_std_core_take_while_fun24970__t {
  struct kk_function_s _base;
};
static kk_std_core__list kk_std_core_take_while_fun24970(kk_function_t _fself, kk_std_core__list _ctail_21155, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_take_while_fun24970(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_take_while_fun24970, _ctx)
  return kk_function_dup(_fself);
}

static kk_std_core__list kk_std_core_take_while_fun24970(kk_function_t _fself, kk_std_core__list _ctail_21155, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return _ctail_21155;
}

kk_std_core__list kk_std_core_take_while(kk_std_core__list xs1, kk_function_t predicate3, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, predicate : (a) -> e bool) -> e list<a> */ 
  bool _match_23434 = kk_std_core_hnd__evv_is_affine(_ctx); /*bool*/;
  if (_match_23434) {
    return kk_std_core__ctail_take_while(xs1, predicate3, kk_std_core_types__new_CTailNil(_ctx), _ctx);
  }
  return kk_std_core__ctailm_take_while(xs1, predicate3, kk_std_core_new_take_while_fun24970(_ctx), _ctx);
}
 
// Trace a message used for debug purposes.
// The behaviour is system dependent. On a browser and node it uses
// `console.log`  by default.
// Disabled if `notrace` is called.

kk_unit_t kk_std_core_trace(kk_string_t message0, kk_context_t* _ctx) { /* (message : string) -> () */ 
  bool _match_23433;
  kk_ref_t _b_23156_23155 = kk_ref_alloc((kk_bool_box(true)),kk_context()); /*ref<global,bool>*/;
  kk_box_t _x24971 = kk_ref_get(_b_23156_23155,kk_context()); /*179*/
  _match_23433 = kk_bool_unbox(_x24971); /*bool*/
  if (_match_23433) {
    kk_std_core_xtrace(message0, _ctx); return kk_Unit;
  }
  kk_string_drop(message0, _ctx);
  kk_Unit; return kk_Unit;
}

kk_unit_t kk_std_core_trace_any(kk_string_t message0, kk_box_t x, kk_context_t* _ctx) { /* forall<a> (message : string, x : a) -> () */ 
  bool _match_23432;
  kk_ref_t _b_23160_23159 = kk_ref_alloc((kk_bool_box(true)),kk_context()); /*ref<global,bool>*/;
  kk_box_t _x24972 = kk_ref_get(_b_23160_23159,kk_context()); /*179*/
  _match_23432 = kk_bool_unbox(_x24972); /*bool*/
  if (_match_23432) {
    kk_std_core_xtrace_any(message0, x, _ctx); return kk_Unit;
  }
  kk_string_drop(message0, _ctx);
  kk_box_drop(x, _ctx);
  kk_Unit; return kk_Unit;
}
 
// Truncate a string to `count` characters.

kk_string_t kk_std_core_truncate(kk_string_t s, kk_integer_t count, kk_context_t* _ctx) { /* (s : string, count : int) -> string */ 
  kk_std_core__sslice _x24973;
  kk_std_core__sslice _x24974;
  kk_std_core__sslice slice0 = kk_std_core_first1(s, _ctx); /*sslice*/;
  bool _match_23429;
  kk_integer_t _x24975;
  kk_std_core_types__optional _match_23431 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
  if (kk_std_core_types__is_Optional(_match_23431)) {
    kk_box_t _box_x23162 = _match_23431._cons.Optional.value;
    kk_integer_t _n_12425 = kk_integer_unbox(_box_x23162);
    kk_integer_dup(_n_12425);
    kk_std_core_types__optional_drop(_match_23431, _ctx);
    _x24975 = _n_12425; /*int*/
    goto _match24976;
  }
  _x24975 = kk_integer_from_small(1); /*int*/
  _match24976: ;
  _match_23429 = kk_integer_eq(_x24975,(kk_integer_from_small(1)),kk_context()); /*bool*/
  if (_match_23429) {
    _x24974 = slice0; /*sslice*/
  }
  else {
    kk_integer_t _x24978;
    kk_integer_t _x24979;
    kk_std_core_types__optional _match_23430 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
    if (kk_std_core_types__is_Optional(_match_23430)) {
      kk_box_t _box_x23163 = _match_23430._cons.Optional.value;
      kk_integer_t _n_124250 = kk_integer_unbox(_box_x23163);
      kk_integer_dup(_n_124250);
      kk_std_core_types__optional_drop(_match_23430, _ctx);
      _x24979 = _n_124250; /*int*/
      goto _match24980;
    }
    _x24979 = kk_integer_from_small(1); /*int*/
    _match24980: ;
    _x24978 = kk_integer_sub(_x24979,(kk_integer_from_small(1)),kk_context()); /*int*/
    _x24974 = kk_std_core_extend(slice0, _x24978, _ctx); /*sslice*/
  }
  kk_integer_t _x24982 = kk_integer_sub(count,(kk_integer_from_small(1)),kk_context()); /*int*/
  _x24973 = kk_std_core_extend(_x24974, _x24982, _ctx); /*sslice*/
  return kk_std_core_string_3(_x24973, _ctx);
}
 
// Return a default value when an exception is raised


// lift anonymous function
struct kk_std_core_try_default_fun24985__t {
  struct kk_function_s _base;
  kk_box_t value;
};
static kk_box_t kk_std_core_try_default_fun24985(kk_function_t _fself, kk_std_core_hnd__marker _b_23165, kk_std_core_hnd__ev _b_23166, kk_box_t _b_23167, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_try_default_fun24985(kk_box_t value, kk_context_t* _ctx) {
  struct kk_std_core_try_default_fun24985__t* _self = kk_function_alloc_as(struct kk_std_core_try_default_fun24985__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_try_default_fun24985, kk_context());
  _self->value = value;
  return &_self->_base;
}



// lift anonymous function
struct kk_std_core_try_default_fun24986__t {
  struct kk_function_s _base;
  kk_box_t value;
};
static kk_box_t kk_std_core_try_default_fun24986(kk_function_t _fself, kk_function_t ___wildcard__554__45, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_try_default_fun24986(kk_box_t value, kk_context_t* _ctx) {
  struct kk_std_core_try_default_fun24986__t* _self = kk_function_alloc_as(struct kk_std_core_try_default_fun24986__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_try_default_fun24986, kk_context());
  _self->value = value;
  return &_self->_base;
}

static kk_box_t kk_std_core_try_default_fun24986(kk_function_t _fself, kk_function_t ___wildcard__554__45, kk_context_t* _ctx) {
  struct kk_std_core_try_default_fun24986__t* _self = kk_function_as(struct kk_std_core_try_default_fun24986__t*, _fself);
  kk_box_t value = _self->value; /* 20439 */
  kk_drop_match(_self, {kk_box_dup(value);}, {}, _ctx)
  kk_function_drop(___wildcard__554__45, _ctx);
  return value;
}
static kk_box_t kk_std_core_try_default_fun24985(kk_function_t _fself, kk_std_core_hnd__marker _b_23165, kk_std_core_hnd__ev _b_23166, kk_box_t _b_23167, kk_context_t* _ctx) {
  struct kk_std_core_try_default_fun24985__t* _self = kk_function_as(struct kk_std_core_try_default_fun24985__t*, _fself);
  kk_box_t value = _self->value; /* 20439 */
  kk_drop_match(_self, {kk_box_dup(value);}, {}, _ctx)
  kk_std_core_hnd__ev_dropn(_b_23166, ((int32_t)3), _ctx);
  kk_box_drop(_b_23167, _ctx);
  return kk_std_core_hnd_yield_to_final(_b_23165, kk_std_core_new_try_default_fun24986(value, _ctx), _ctx);
}


// lift anonymous function
struct kk_std_core_try_default_fun24987__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_try_default_fun24987(kk_function_t _fself, kk_box_t _x, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_try_default_fun24987(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_try_default_fun24987, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_core_try_default_fun24987(kk_function_t _fself, kk_box_t _x, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return _x;
}

kk_box_t kk_std_core_try_default(kk_box_t value, kk_function_t action, kk_context_t* _ctx) { /* forall<a,e> (value : a, action : () -> <exn|e> a) -> e a */ 
  kk_std_core__hnd_exn _x24983;
  kk_std_core_hnd__clause1 _x24984 = kk_std_core_hnd__new_Clause1(kk_std_core_new_try_default_fun24985(value, _ctx), _ctx); /*std/core/hnd/clause1<52,53,54,55,56>*/
  _x24983 = kk_std_core__new_Hnd_exn(kk_reuse_null, _x24984, _ctx); /*.hnd-exn<11,12>*/
  return kk_std_core__handle_exn(((int32_t)0), _x24983, kk_std_core_new_try_default_fun24987(_ctx), action, _ctx);
}
 
// Returns a unique integer (modulo 32-bits).

kk_integer_t kk_std_core_unique(kk_context_t* _ctx) { /* () -> ndet int */ 
  kk_integer_t u;
  kk_box_t _x24988;
  kk_ref_t _x24989 = kk_ref_dup(kk_std_core_unique_count); /*ref<global,int>*/
  _x24988 = kk_ref_get(_x24989,kk_context()); /*179*/
  u = kk_integer_unbox(_x24988); /*int*/
  kk_unit_t __ = kk_Unit;
  kk_integer_t _b_23177_23175;
  kk_integer_t _x24990 = kk_integer_dup(u); /*int*/
  _b_23177_23175 = kk_integer_add(_x24990,(kk_integer_from_small(1)),kk_context()); /*int*/
  kk_ref_t _x24991 = kk_ref_dup(kk_std_core_unique_count); /*ref<global,int>*/
  kk_ref_set(_x24991,(kk_integer_box(_b_23177_23175)),kk_context());
  return u;
}
 
// Get the value of the `Just` constructor or raise an exception

kk_box_t kk_std_core_unjust(kk_std_core_types__maybe m, kk_context_t* _ctx) { /* forall<a> (m : maybe<a>) -> exn a */ 
  if (kk_std_core_types__is_Just(m)) {
    kk_box_t x = m._cons.Just.value;
    return x;
  }
  kk_std_core__exception exn_21790;
  kk_string_t _x24992;
  kk_define_string_literal(, _s24993, 37, "unexpected Nothing in std/core/unjust")
  _x24992 = kk_string_dup(_s24993); /*string*/
  kk_std_core__exception_info _x24994;
  kk_std_core_types__optional _match_23428 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
  if (kk_std_core_types__is_Optional(_match_23428)) {
    kk_box_t _box_x23178 = _match_23428._cons.Optional.value;
    kk_std_core__exception_info _info_14279 = kk_std_core__exception_info_unbox(_box_x23178, NULL);
    kk_std_core__exception_info_dup(_info_14279);
    kk_std_core_types__optional_drop(_match_23428, _ctx);
    _x24994 = _info_14279; /*exception-info*/
    goto _match24995;
  }
  _x24994 = kk_std_core__new_ExnError(_ctx); /*exception-info*/
  _match24995: ;
  exn_21790 = kk_std_core__new_Exception(_x24992, _x24994, _ctx); /*exception*/
  kk_std_core_hnd__ev ev_21791;
  size_t _x24997 = ((size_t)0); /*size_t*/
  ev_21791 = kk_evv_at(_x24997,kk_context()); /*std/core/hnd/ev<.hnd-exn>*/
  struct kk_std_core_hnd_Ev* _con24998 = kk_std_core_hnd__as_Ev(ev_21791);
  kk_std_core_hnd__marker m0 = _con24998->marker;
  kk_box_t _box_x23179 = _con24998->hnd;
  kk_std_core__hnd_exn h = kk_std_core__hnd_exn_unbox(_box_x23179, NULL);
  kk_std_core__hnd_exn_dup(h);
  kk_std_core_hnd__clause1 _match_23427;
  struct kk_std_core__Hnd_exn* _con25000 = kk_std_core__as_Hnd_exn(h);
  kk_std_core_hnd__clause1 except_throw_exn = _con25000->except_throw_exn;
  if (kk_std_core__hnd_exn_is_unique(h)) {
    kk_std_core__hnd_exn_free(h);
  }
  else {
    kk_std_core_hnd__clause1_dup(except_throw_exn);
    kk_std_core__hnd_exn_decref(h, _ctx);
  }
  _match_23427 = except_throw_exn; /*forall<a> std/core/hnd/clause1<exception,a,.hnd-exn,3528,3529>*/
  kk_function_t _fun_unbox_x23183 = _match_23427.clause;
  return kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x23183, (_fun_unbox_x23183, m0, ev_21791, kk_std_core__exception_box(exn_21790, _ctx), _ctx));
}
 
// Join a list of strings with newlines

kk_string_t kk_std_core_unlines(kk_std_core__list xs, kk_context_t* _ctx) { /* (xs : list<string>) -> string */ 
  if (kk_std_core__is_Nil(xs)) {
    return kk_string_empty();
  }
  struct kk_std_core_Cons* _con25002 = kk_std_core__as_Cons(xs);
  kk_box_t _box_x23190 = _con25002->head;
  kk_std_core__list xx = _con25002->tail;
  kk_string_t x = kk_string_unbox(_box_x23190);
  if (kk_std_core__list_is_unique(xs)) {
    kk_std_core__list_free(xs);
  }
  else {
    kk_string_dup(x);
    kk_std_core__list_dup(xx);
    kk_std_core__list_decref(xs, _ctx);
  }
  kk_string_t _x25004;
  kk_define_string_literal(, _s25005, 1, "\n")
  _x25004 = kk_string_dup(_s25005); /*string*/
  return kk_std_core__lift21050_joinsep(_x25004, xx, x, _ctx);
}
 
// lift

kk_std_core_types__tuple2_ kk_std_core__lift21061_unzip(kk_std_core__list ys, kk_std_core__list acc1, kk_std_core__list acc2, kk_context_t* _ctx) { /* forall<a,b> (ys : list<(a, b)>, acc1 : list<a>, acc2 : list<b>) -> (list<a>, list<b>) */ 
  kk__tailcall: ;
  if (kk_std_core__is_Cons(ys)) {
    struct kk_std_core_Cons* _con25006 = kk_std_core__as_Cons(ys);
    kk_box_t _box_x23191 = _con25006->head;
    kk_std_core__list xx = _con25006->tail;
    kk_std_core_types__tuple2_ _pat0 = kk_std_core_types__tuple2__unbox(_box_x23191, NULL);
    kk_box_t x = _pat0.fst;
    kk_box_t y = _pat0.snd;
    kk_reuse_t _ru_23406 = kk_reuse_null; /*reuse*/;
    if (kk_std_core__list_is_unique(ys)) {
      kk_box_dup(x);
      kk_box_dup(y);
      kk_box_drop(_box_x23191, _ctx);
      _ru_23406 = (kk_std_core__list_reuse(ys));
    }
    else {
      kk_box_dup(x);
      kk_std_core__list_dup(xx);
      kk_box_dup(y);
      kk_std_core__list_decref(ys, _ctx);
      _ru_23406 = kk_reuse_null;
    }
    { // tailcall
      kk_std_core__list _x25008 = kk_std_core__new_Cons(_ru_23406, x, acc1, _ctx); /*list<61>*/
      kk_std_core__list _x25009 = kk_std_core__new_Cons(kk_reuse_null, y, acc2, _ctx); /*list<61>*/
      ys = xx;
      acc1 = _x25008;
      acc2 = _x25009;
      goto kk__tailcall;
    }
  }
  kk_std_core__list _b_23194_23192 = kk_std_core_reverse(acc1, _ctx); /*list<20592>*/;
  kk_std_core__list _b_23195_23193 = kk_std_core_reverse(acc2, _ctx); /*list<20593>*/;
  return kk_std_core_types__new_dash__lp__comma__rp_(kk_std_core__list_box(_b_23194_23192, _ctx), kk_std_core__list_box(_b_23195_23193, _ctx), _ctx);
}
 
// Convert a string to a vector of characters.

kk_vector_t kk_std_core_vector_1(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> vector<char> */ 
  return kk_string_to_chars(s,kk_context());
}
extern kk_box_t kk_std_core_vector_fun25011_2(kk_function_t _fself, size_t ___wildcard__2033__29, kk_context_t* _ctx) {
  struct kk_std_core_vector_fun25011__t_2* _self = kk_function_as(struct kk_std_core_vector_fun25011__t_2*, _fself);
  kk_box_t default0 = _self->default0; /* 20671 */
  kk_drop_match(_self, {kk_box_dup(default0);}, {}, _ctx)
  return default0;
}
extern kk_box_t kk_std_core_vector_init_fun25014(kk_function_t _fself, size_t i, kk_context_t* _ctx) {
  struct kk_std_core_vector_init_fun25014__t* _self = kk_function_as(struct kk_std_core_vector_init_fun25014__t*, _fself);
  kk_function_t f = _self->f; /* (int) -> 20759 */
  kk_drop_match(_self, {kk_function_dup(f);}, {}, _ctx)
  kk_integer_t _x25015 = kk_integer_from_size_t(i,kk_context()); /*int*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_context_t*), f, (f, _x25015, _ctx));
}
 
// monadic lift

kk_unit_t kk_std_core__mlift21224_while(kk_function_t action, kk_function_t predicate, kk_unit_t wild__, kk_context_t* _ctx) { /* forall<e> (action : () -> <div|e> (), predicate : () -> <div|e> bool, wild_ : ()) -> <div|e> () */ 
  kk_std_core_while(predicate, action, _ctx); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_std_core__mlift21225_while_fun25018__t {
  struct kk_function_s _base;
  kk_function_t action0;
  kk_function_t predicate0;
};
static kk_box_t kk_std_core__mlift21225_while_fun25018(kk_function_t _fself, kk_box_t _b_23197, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_mlift21225_while_fun25018(kk_function_t action0, kk_function_t predicate0, kk_context_t* _ctx) {
  struct kk_std_core__mlift21225_while_fun25018__t* _self = kk_function_alloc_as(struct kk_std_core__mlift21225_while_fun25018__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__mlift21225_while_fun25018, kk_context());
  _self->action0 = action0;
  _self->predicate0 = predicate0;
  return &_self->_base;
}

static kk_box_t kk_std_core__mlift21225_while_fun25018(kk_function_t _fself, kk_box_t _b_23197, kk_context_t* _ctx) {
  struct kk_std_core__mlift21225_while_fun25018__t* _self = kk_function_as(struct kk_std_core__mlift21225_while_fun25018__t*, _fself);
  kk_function_t action0 = _self->action0; /* () -> <div|20780> () */
  kk_function_t predicate0 = _self->predicate0; /* () -> <div|20780> bool */
  kk_drop_match(_self, {kk_function_dup(action0);kk_function_dup(predicate0);}, {}, _ctx)
  kk_unit_t _x25019 = kk_Unit;
  kk_unit_t _x25020 = kk_Unit;
  kk_unit_unbox(_b_23197);
  kk_std_core__mlift21224_while(action0, predicate0, _x25020, _ctx);
  return kk_unit_box(_x25019);
}

kk_unit_t kk_std_core__mlift21225_while(kk_function_t action0, kk_function_t predicate0, bool _y_245, kk_context_t* _ctx) { /* forall<e> (action : () -> <div|e> (), predicate : () -> <div|e> bool, bool) -> <div|e> () */ 
  if (_y_245) {
    kk_unit_t x_21796 = kk_Unit;
    kk_function_t _x25016 = kk_function_dup(action0); /*() -> <div|20780> ()*/
    kk_function_call(kk_unit_t, (kk_function_t, kk_context_t*), _x25016, (_x25016, _ctx));
    if (kk_yielding(kk_context())) {
      kk_box_t _x25017 = kk_std_core_hnd_yield_extend(kk_std_core__new_mlift21225_while_fun25018(action0, predicate0, _ctx), _ctx); /*3991*/
      kk_unit_unbox(_x25017); return kk_Unit;
    }
    kk_std_core__mlift21224_while(action0, predicate0, x_21796, _ctx); return kk_Unit;
  }
  kk_function_drop(action0, _ctx);
  kk_function_drop(predicate0, _ctx);
  kk_Unit; return kk_Unit;
}
 
// The `while` fun executes `action`  as long as `pred`  is `true`.


// lift anonymous function
struct kk_std_core_while_fun25023__t {
  struct kk_function_s _base;
  kk_function_t action1;
  kk_function_t predicate1;
};
static kk_box_t kk_std_core_while_fun25023(kk_function_t _fself, kk_box_t _b_23201, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_while_fun25023(kk_function_t action1, kk_function_t predicate1, kk_context_t* _ctx) {
  struct kk_std_core_while_fun25023__t* _self = kk_function_alloc_as(struct kk_std_core_while_fun25023__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_while_fun25023, kk_context());
  _self->action1 = action1;
  _self->predicate1 = predicate1;
  return &_self->_base;
}

static kk_box_t kk_std_core_while_fun25023(kk_function_t _fself, kk_box_t _b_23201, kk_context_t* _ctx) {
  struct kk_std_core_while_fun25023__t* _self = kk_function_as(struct kk_std_core_while_fun25023__t*, _fself);
  kk_function_t action1 = _self->action1; /* () -> <div|20780> () */
  kk_function_t predicate1 = _self->predicate1; /* () -> <div|20780> bool */
  kk_drop_match(_self, {kk_function_dup(action1);kk_function_dup(predicate1);}, {}, _ctx)
  kk_unit_t _x25024 = kk_Unit;
  bool _x25025 = kk_bool_unbox(_b_23201); /*bool*/
  kk_std_core__mlift21225_while(action1, predicate1, _x25025, _ctx);
  return kk_unit_box(_x25024);
}


// lift anonymous function
struct kk_std_core_while_fun25028__t {
  struct kk_function_s _base;
  kk_function_t action1;
  kk_function_t predicate1;
};
static kk_box_t kk_std_core_while_fun25028(kk_function_t _fself, kk_box_t _b_23203, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_while_fun25028(kk_function_t action1, kk_function_t predicate1, kk_context_t* _ctx) {
  struct kk_std_core_while_fun25028__t* _self = kk_function_alloc_as(struct kk_std_core_while_fun25028__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_while_fun25028, kk_context());
  _self->action1 = action1;
  _self->predicate1 = predicate1;
  return &_self->_base;
}

static kk_box_t kk_std_core_while_fun25028(kk_function_t _fself, kk_box_t _b_23203, kk_context_t* _ctx) {
  struct kk_std_core_while_fun25028__t* _self = kk_function_as(struct kk_std_core_while_fun25028__t*, _fself);
  kk_function_t action1 = _self->action1; /* () -> <div|20780> () */
  kk_function_t predicate1 = _self->predicate1; /* () -> <div|20780> bool */
  kk_drop_match(_self, {kk_function_dup(action1);kk_function_dup(predicate1);}, {}, _ctx)
  kk_unit_t _x25029 = kk_Unit;
  kk_unit_t _x25030 = kk_Unit;
  kk_unit_unbox(_b_23203);
  kk_std_core__mlift21224_while(action1, predicate1, _x25030, _ctx);
  return kk_unit_box(_x25029);
}

kk_unit_t kk_std_core_while(kk_function_t predicate1, kk_function_t action1, kk_context_t* _ctx) { /* forall<e> (predicate : () -> <div|e> bool, action : () -> <div|e> ()) -> <div|e> () */ 
  kk__tailcall: ;
  bool x_21798;
  kk_function_t _x25021 = kk_function_dup(predicate1); /*() -> <div|20780> bool*/
  x_21798 = kk_function_call(bool, (kk_function_t, kk_context_t*), _x25021, (_x25021, _ctx)); /*bool*/
  if (kk_yielding(kk_context())) {
    kk_box_t _x25022 = kk_std_core_hnd_yield_extend(kk_std_core_new_while_fun25023(action1, predicate1, _ctx), _ctx); /*3991*/
    kk_unit_unbox(_x25022); return kk_Unit;
  }
  if (x_21798) {
    kk_unit_t x0_21802 = kk_Unit;
    kk_function_t _x25026 = kk_function_dup(action1); /*() -> <div|20780> ()*/
    kk_function_call(kk_unit_t, (kk_function_t, kk_context_t*), _x25026, (_x25026, _ctx));
    if (kk_yielding(kk_context())) {
      kk_box_t _x25027 = kk_std_core_hnd_yield_extend(kk_std_core_new_while_fun25028(action1, predicate1, _ctx), _ctx); /*3991*/
      kk_unit_unbox(_x25027); return kk_Unit;
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
    struct kk_std_core_Cons* _con25031 = kk_std_core__as_Cons(xs);
    kk_box_t x = _con25031->head;
    kk_std_core__list xx = _con25031->tail;
    if (kk_std_core__list_is_unique(xs)) {
      kk_std_core__list_free(xs);
    }
    else {
      kk_box_dup(x);
      kk_std_core__list_dup(xx);
      kk_std_core__list_decref(xs, _ctx);
    }
    if (kk_std_core__is_Cons(ys)) {
      struct kk_std_core_Cons* _con25032 = kk_std_core__as_Cons(ys);
      kk_box_t y = _con25032->head;
      kk_std_core__list yy = _con25032->tail;
      kk_reuse_t _ru_23408 = kk_reuse_null; /*reuse*/;
      if (kk_std_core__list_is_unique(ys)) {
        _ru_23408 = (kk_std_core__list_reuse(ys));
      }
      else {
        kk_box_dup(y);
        kk_std_core__list_dup(yy);
        kk_std_core__list_decref(ys, _ctx);
        _ru_23408 = kk_reuse_null;
      }
      kk_std_core_types__tuple2_ _ctail_21157 = kk_std_core_types__new_dash__lp__comma__rp_(x, y, _ctx); /*(20823, 20824)*/;
      kk_std_core__list _ctail_21158 = kk_std_core__list_hole(); /*list<(20823, 20824)>*/;
      kk_std_core__list _ctail_21159 = kk_std_core__new_Cons(_ru_23408, kk_std_core_types__tuple2__box(_ctail_21157, _ctx), _ctail_21158, _ctx); /*list<(20823, 20824)>*/;
      { // tailcall
        kk_std_core_types__ctail _x25033;
        kk_box_t* field_21808 = (kk_box_t*)((&kk_std_core__as_Cons(_ctail_21159)->tail)); /*cfield<list<(20823, 20824)>>*/;
        if (kk_std_core_types__is_CTail(_acc)) {
          kk_box_t _box_x23218 = _acc._cons.CTail._field1;
          kk_box_t* last0 = _acc._cons.CTail._field2;
          kk_std_core__list head0 = kk_std_core__list_unbox(_box_x23218, NULL);
          kk_std_core__list_dup(head0);
          kk_std_core_types__ctail_drop(_acc, _ctx);
          kk_unit_t __ = kk_Unit;
          *(last0) = kk_std_core__list_box(_ctail_21159, _ctx);
          _x25033 = kk_std_core_types__new_CTail(kk_std_core__list_box(head0, _ctx), field_21808, _ctx); /*ctail<58>*/
          goto _match25034;
        }
        _x25033 = kk_std_core_types__new_CTail(kk_std_core__list_box(_ctail_21159, _ctx), field_21808, _ctx); /*ctail<58>*/
        _match25034: ;
        xs = xx;
        ys = yy;
        _acc = _x25033;
        goto kk__tailcall;
      }
    }
    kk_box_drop(x, _ctx);
    kk_std_core__list_drop(xx, _ctx);
    if (kk_std_core_types__is_CTail(_acc)) {
      kk_box_t _box_x23227 = _acc._cons.CTail._field1;
      kk_box_t* last00 = _acc._cons.CTail._field2;
      kk_std_core__list head00 = kk_std_core__list_unbox(_box_x23227, NULL);
      kk_std_core__list_dup(head00);
      kk_std_core_types__ctail_drop(_acc, _ctx);
      kk_unit_t __0 = kk_Unit;
      *(last00) = kk_std_core__list_box(kk_std_core__new_Nil(_ctx), _ctx);
      return head00;
    }
    return kk_std_core__new_Nil(_ctx);
  }
  kk_std_core__list_drop(ys, _ctx);
  if (kk_std_core_types__is_CTail(_acc)) {
    kk_box_t _box_x23232 = _acc._cons.CTail._field1;
    kk_box_t* last10 = _acc._cons.CTail._field2;
    kk_std_core__list head1 = kk_std_core__list_unbox(_box_x23232, NULL);
    kk_std_core__list_dup(head1);
    kk_std_core_types__ctail_drop(_acc, _ctx);
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
  kk_std_core_types__ctail _x25038;
  kk_box_t* field_21815 = (kk_box_t*)((&kk_std_core__as_Cons(_ctail_21162)->tail)); /*cfield<list<20871>>*/;
  if (kk_std_core_types__is_CTail(_acc)) {
    kk_box_t _box_x23247 = _acc._cons.CTail._field1;
    kk_box_t* last0 = _acc._cons.CTail._field2;
    kk_std_core__list head0 = kk_std_core__list_unbox(_box_x23247, NULL);
    kk_std_core__list_dup(head0);
    kk_std_core_types__ctail_drop(_acc, _ctx);
    kk_unit_t __ = kk_Unit;
    *(last0) = kk_std_core__list_box(_ctail_21162, _ctx);
    _x25038 = kk_std_core_types__new_CTail(kk_std_core__list_box(head0, _ctx), field_21815, _ctx); /*ctail<58>*/
    goto _match25039;
  }
  _x25038 = kk_std_core_types__new_CTail(kk_std_core__list_box(_ctail_21162, _ctx), field_21815, _ctx); /*ctail<58>*/
  _match25039: ;
  return kk_std_core__ctail_zipwith(xx, yy, f, _x25038, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_core__mlift21227_op_fun25041__t {
  struct kk_function_s _base;
  kk_function_t _accm;
  kk_box_t _ctail_21165;
};
static kk_std_core__list kk_std_core__mlift21227_op_fun25041(kk_function_t _fself, kk_std_core__list _ctail_21164, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_mlift21227_op_fun25041(kk_function_t _accm, kk_box_t _ctail_21165, kk_context_t* _ctx) {
  struct kk_std_core__mlift21227_op_fun25041__t* _self = kk_function_alloc_as(struct kk_std_core__mlift21227_op_fun25041__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__mlift21227_op_fun25041, kk_context());
  _self->_accm = _accm;
  _self->_ctail_21165 = _ctail_21165;
  return &_self->_base;
}

static kk_std_core__list kk_std_core__mlift21227_op_fun25041(kk_function_t _fself, kk_std_core__list _ctail_21164, kk_context_t* _ctx) {
  struct kk_std_core__mlift21227_op_fun25041__t* _self = kk_function_as(struct kk_std_core__mlift21227_op_fun25041__t*, _fself);
  kk_function_t _accm = _self->_accm; /* (list<20871>) -> list<20871> */
  kk_box_t _ctail_21165 = _self->_ctail_21165; /* 20871 */
  kk_drop_match(_self, {kk_function_dup(_accm);kk_box_dup(_ctail_21165);}, {}, _ctx)
  kk_std_core__list _x25042 = kk_std_core__new_Cons(kk_reuse_null, _ctail_21165, _ctail_21164, _ctx); /*list<61>*/
  return kk_function_call(kk_std_core__list, (kk_function_t, kk_std_core__list, kk_context_t*), _accm, (_accm, _x25042, _ctx));
}

kk_std_core__list kk_std_core__mlift21227_op(kk_function_t _accm, kk_function_t f0, kk_std_core__list xx0, kk_std_core__list yy0, kk_box_t _ctail_21165, kk_context_t* _ctx) { /* forall<a,b,c,e> ((list<c>) -> list<c>, f : (a, b) -> e c, xx : list<a>, yy : list<b>, c) -> e list<c> */ 
  return kk_std_core__ctailm_zipwith(xx0, yy0, f0, kk_std_core__new_mlift21227_op_fun25041(_accm, _ctail_21165, _ctx), _ctx);
}
 
// Zip two lists together by apply a function `f` to all corresponding elements.
// The returned list is only as long as the smallest input list.


// lift anonymous function
struct kk_std_core__ctail_zipwith_fun25047__t {
  struct kk_function_s _base;
  kk_function_t f1;
  kk_std_core__list xx1;
  kk_std_core__list yy1;
  kk_std_core_types__ctail _acc0;
};
static kk_box_t kk_std_core__ctail_zipwith_fun25047(kk_function_t _fself, kk_box_t _b_23261, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_ctail_zipwith_fun25047(kk_function_t f1, kk_std_core__list xx1, kk_std_core__list yy1, kk_std_core_types__ctail _acc0, kk_context_t* _ctx) {
  struct kk_std_core__ctail_zipwith_fun25047__t* _self = kk_function_alloc_as(struct kk_std_core__ctail_zipwith_fun25047__t, 6, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__ctail_zipwith_fun25047, kk_context());
  _self->f1 = f1;
  _self->xx1 = xx1;
  _self->yy1 = yy1;
  _self->_acc0 = _acc0;
  return &_self->_base;
}

static kk_box_t kk_std_core__ctail_zipwith_fun25047(kk_function_t _fself, kk_box_t _b_23261, kk_context_t* _ctx) {
  struct kk_std_core__ctail_zipwith_fun25047__t* _self = kk_function_as(struct kk_std_core__ctail_zipwith_fun25047__t*, _fself);
  kk_function_t f1 = _self->f1; /* (20869, 20870) -> 20872 20871 */
  kk_std_core__list xx1 = _self->xx1; /* list<20869> */
  kk_std_core__list yy1 = _self->yy1; /* list<20870> */
  kk_std_core_types__ctail _acc0 = _self->_acc0; /* ctail<list<20871>> */
  kk_drop_match(_self, {kk_function_dup(f1);kk_std_core__list_dup(xx1);kk_std_core__list_dup(yy1);kk_std_core_types__ctail_dup(_acc0);}, {}, _ctx)
  kk_std_core__list _x25048 = kk_std_core__mlift21226_op(_acc0, f1, xx1, yy1, _b_23261, _ctx); /*list<20871>*/
  return kk_std_core__list_box(_x25048, _ctx);
}

kk_std_core__list kk_std_core__ctail_zipwith(kk_std_core__list xs, kk_std_core__list ys, kk_function_t f1, kk_std_core_types__ctail _acc0, kk_context_t* _ctx) { /* forall<a,b,c,e> (xs : list<a>, ys : list<b>, f : (a, b) -> e c, ctail<list<c>>) -> e list<c> */ 
  kk__tailcall: ;
  if (kk_std_core__is_Cons(xs)) {
    struct kk_std_core_Cons* _con25043 = kk_std_core__as_Cons(xs);
    kk_box_t x = _con25043->head;
    kk_std_core__list xx1 = _con25043->tail;
    if (kk_std_core__list_is_unique(xs)) {
      kk_std_core__list_free(xs);
    }
    else {
      kk_box_dup(x);
      kk_std_core__list_dup(xx1);
      kk_std_core__list_decref(xs, _ctx);
    }
    if (kk_std_core__is_Cons(ys)) {
      struct kk_std_core_Cons* _con25044 = kk_std_core__as_Cons(ys);
      kk_box_t y = _con25044->head;
      kk_std_core__list yy1 = _con25044->tail;
      kk_reuse_t _ru_23410 = kk_reuse_null; /*reuse*/;
      if (kk_std_core__list_is_unique(ys)) {
        _ru_23410 = (kk_std_core__list_reuse(ys));
      }
      else {
        kk_box_dup(y);
        kk_std_core__list_dup(yy1);
        kk_std_core__list_decref(ys, _ctx);
        _ru_23410 = kk_reuse_null;
      }
      kk_box_t x0_21816;
      kk_function_t _x25045 = kk_function_dup(f1); /*(20869, 20870) -> 20872 20871*/
      x0_21816 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _x25045, (_x25045, x, y, _ctx)); /*20871*/
      if (kk_yielding(kk_context())) {
        kk_reuse_drop(_ru_23410, _ctx);
        kk_box_drop(x0_21816, _ctx);
        kk_box_t _x25046 = kk_std_core_hnd_yield_extend(kk_std_core__new_ctail_zipwith_fun25047(f1, xx1, yy1, _acc0, _ctx), _ctx); /*3991*/
        return kk_std_core__list_unbox(_x25046, _ctx);
      }
      kk_std_core__list _ctail_211610 = kk_std_core__list_hole(); /*list<20871>*/;
      kk_std_core__list _ctail_211620 = kk_std_core__new_Cons(_ru_23410, x0_21816, _ctail_211610, _ctx); /*list<20871>*/;
      { // tailcall
        kk_std_core_types__ctail _x25049;
        kk_box_t* field_21822 = (kk_box_t*)((&kk_std_core__as_Cons(_ctail_211620)->tail)); /*cfield<list<20871>>*/;
        if (kk_std_core_types__is_CTail(_acc0)) {
          kk_box_t _box_x23268 = _acc0._cons.CTail._field1;
          kk_box_t* last2 = _acc0._cons.CTail._field2;
          kk_std_core__list head1 = kk_std_core__list_unbox(_box_x23268, NULL);
          kk_std_core__list_dup(head1);
          kk_std_core_types__ctail_drop(_acc0, _ctx);
          kk_unit_t __0 = kk_Unit;
          *(last2) = kk_std_core__list_box(_ctail_211620, _ctx);
          _x25049 = kk_std_core_types__new_CTail(kk_std_core__list_box(head1, _ctx), field_21822, _ctx); /*ctail<58>*/
          goto _match25050;
        }
        _x25049 = kk_std_core_types__new_CTail(kk_std_core__list_box(_ctail_211620, _ctx), field_21822, _ctx); /*ctail<58>*/
        _match25050: ;
        xs = xx1;
        ys = yy1;
        _acc0 = _x25049;
        goto kk__tailcall;
      }
    }
    kk_function_drop(f1, _ctx);
    kk_box_drop(x, _ctx);
    kk_std_core__list_drop(xx1, _ctx);
    if (kk_std_core_types__is_CTail(_acc0)) {
      kk_box_t _box_x23277 = _acc0._cons.CTail._field1;
      kk_box_t* last00 = _acc0._cons.CTail._field2;
      kk_std_core__list head00 = kk_std_core__list_unbox(_box_x23277, NULL);
      kk_std_core__list_dup(head00);
      kk_std_core_types__ctail_drop(_acc0, _ctx);
      kk_unit_t __00 = kk_Unit;
      *(last00) = kk_std_core__list_box(kk_std_core__new_Nil(_ctx), _ctx);
      return head00;
    }
    return kk_std_core__new_Nil(_ctx);
  }
  kk_function_drop(f1, _ctx);
  kk_std_core__list_drop(ys, _ctx);
  if (kk_std_core_types__is_CTail(_acc0)) {
    kk_box_t _box_x23282 = _acc0._cons.CTail._field1;
    kk_box_t* last10 = _acc0._cons.CTail._field2;
    kk_std_core__list head10 = kk_std_core__list_unbox(_box_x23282, NULL);
    kk_std_core__list_dup(head10);
    kk_std_core_types__ctail_drop(_acc0, _ctx);
    kk_unit_t __1 = kk_Unit;
    *(last10) = kk_std_core__list_box(kk_std_core__new_Nil(_ctx), _ctx);
    return head10;
  }
  return kk_std_core__new_Nil(_ctx);
}
 
// Zip two lists together by apply a function `f` to all corresponding elements.
// The returned list is only as long as the smallest input list.


// lift anonymous function
struct kk_std_core__ctailm_zipwith_fun25058__t {
  struct kk_function_s _base;
  kk_function_t _accm0;
  kk_function_t f2;
  kk_std_core__list xx2;
  kk_std_core__list yy2;
};
static kk_box_t kk_std_core__ctailm_zipwith_fun25058(kk_function_t _fself, kk_box_t _b_23294, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_ctailm_zipwith_fun25058(kk_function_t _accm0, kk_function_t f2, kk_std_core__list xx2, kk_std_core__list yy2, kk_context_t* _ctx) {
  struct kk_std_core__ctailm_zipwith_fun25058__t* _self = kk_function_alloc_as(struct kk_std_core__ctailm_zipwith_fun25058__t, 5, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__ctailm_zipwith_fun25058, kk_context());
  _self->_accm0 = _accm0;
  _self->f2 = f2;
  _self->xx2 = xx2;
  _self->yy2 = yy2;
  return &_self->_base;
}

static kk_box_t kk_std_core__ctailm_zipwith_fun25058(kk_function_t _fself, kk_box_t _b_23294, kk_context_t* _ctx) {
  struct kk_std_core__ctailm_zipwith_fun25058__t* _self = kk_function_as(struct kk_std_core__ctailm_zipwith_fun25058__t*, _fself);
  kk_function_t _accm0 = _self->_accm0; /* (list<20871>) -> list<20871> */
  kk_function_t f2 = _self->f2; /* (20869, 20870) -> 20872 20871 */
  kk_std_core__list xx2 = _self->xx2; /* list<20869> */
  kk_std_core__list yy2 = _self->yy2; /* list<20870> */
  kk_drop_match(_self, {kk_function_dup(_accm0);kk_function_dup(f2);kk_std_core__list_dup(xx2);kk_std_core__list_dup(yy2);}, {}, _ctx)
  kk_std_core__list _x25059 = kk_std_core__mlift21227_op(_accm0, f2, xx2, yy2, _b_23294, _ctx); /*list<20871>*/
  return kk_std_core__list_box(_x25059, _ctx);
}


// lift anonymous function
struct kk_std_core__ctailm_zipwith_fun25061__t {
  struct kk_function_s _base;
  kk_function_t _accm0;
  kk_box_t x0_21827;
};
static kk_std_core__list kk_std_core__ctailm_zipwith_fun25061(kk_function_t _fself, kk_std_core__list _ctail_211640, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_ctailm_zipwith_fun25061(kk_function_t _accm0, kk_box_t x0_21827, kk_context_t* _ctx) {
  struct kk_std_core__ctailm_zipwith_fun25061__t* _self = kk_function_alloc_as(struct kk_std_core__ctailm_zipwith_fun25061__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__ctailm_zipwith_fun25061, kk_context());
  _self->_accm0 = _accm0;
  _self->x0_21827 = x0_21827;
  return &_self->_base;
}

static kk_std_core__list kk_std_core__ctailm_zipwith_fun25061(kk_function_t _fself, kk_std_core__list _ctail_211640, kk_context_t* _ctx) {
  struct kk_std_core__ctailm_zipwith_fun25061__t* _self = kk_function_as(struct kk_std_core__ctailm_zipwith_fun25061__t*, _fself);
  kk_function_t _accm0 = _self->_accm0; /* (list<20871>) -> list<20871> */
  kk_box_t x0_21827 = _self->x0_21827; /* 20871 */
  kk_drop_match(_self, {kk_function_dup(_accm0);kk_box_dup(x0_21827);}, {}, _ctx)
  kk_std_core__list _x25062 = kk_std_core__new_Cons(kk_reuse_null, x0_21827, _ctail_211640, _ctx); /*list<61>*/
  return kk_function_call(kk_std_core__list, (kk_function_t, kk_std_core__list, kk_context_t*), _accm0, (_accm0, _x25062, _ctx));
}

kk_std_core__list kk_std_core__ctailm_zipwith(kk_std_core__list xs0, kk_std_core__list ys0, kk_function_t f2, kk_function_t _accm0, kk_context_t* _ctx) { /* forall<a,b,c,e> (xs : list<a>, ys : list<b>, f : (a, b) -> e c, (list<c>) -> list<c>) -> e list<c> */ 
  kk__tailcall: ;
  if (kk_std_core__is_Cons(xs0)) {
    struct kk_std_core_Cons* _con25054 = kk_std_core__as_Cons(xs0);
    kk_box_t x0 = _con25054->head;
    kk_std_core__list xx2 = _con25054->tail;
    if (kk_std_core__list_is_unique(xs0)) {
      kk_std_core__list_free(xs0);
    }
    else {
      kk_box_dup(x0);
      kk_std_core__list_dup(xx2);
      kk_std_core__list_decref(xs0, _ctx);
    }
    if (kk_std_core__is_Cons(ys0)) {
      struct kk_std_core_Cons* _con25055 = kk_std_core__as_Cons(ys0);
      kk_box_t y0 = _con25055->head;
      kk_std_core__list yy2 = _con25055->tail;
      if (kk_std_core__list_is_unique(ys0)) {
        kk_std_core__list_free(ys0);
      }
      else {
        kk_box_dup(y0);
        kk_std_core__list_dup(yy2);
        kk_std_core__list_decref(ys0, _ctx);
      }
      kk_box_t x0_21827;
      kk_function_t _x25056 = kk_function_dup(f2); /*(20869, 20870) -> 20872 20871*/
      x0_21827 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _x25056, (_x25056, x0, y0, _ctx)); /*20871*/
      if (kk_yielding(kk_context())) {
        kk_box_drop(x0_21827, _ctx);
        kk_box_t _x25057 = kk_std_core_hnd_yield_extend(kk_std_core__new_ctailm_zipwith_fun25058(_accm0, f2, xx2, yy2, _ctx), _ctx); /*3991*/
        return kk_std_core__list_unbox(_x25057, _ctx);
      }
      { // tailcall
        kk_function_t _x25060 = kk_std_core__new_ctailm_zipwith_fun25061(_accm0, x0_21827, _ctx); /*(list<20871>) -> list<20871>*/
        xs0 = xx2;
        ys0 = yy2;
        _accm0 = _x25060;
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
struct kk_std_core_zipwith_fun25063__t {
  struct kk_function_s _base;
};
static kk_std_core__list kk_std_core_zipwith_fun25063(kk_function_t _fself, kk_std_core__list _ctail_21163, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_zipwith_fun25063(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_zipwith_fun25063, _ctx)
  return kk_function_dup(_fself);
}

static kk_std_core__list kk_std_core_zipwith_fun25063(kk_function_t _fself, kk_std_core__list _ctail_21163, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return _ctail_21163;
}

kk_std_core__list kk_std_core_zipwith(kk_std_core__list xs1, kk_std_core__list ys1, kk_function_t f3, kk_context_t* _ctx) { /* forall<a,b,c,e> (xs : list<a>, ys : list<b>, f : (a, b) -> e c) -> e list<c> */ 
  bool _match_23421 = kk_std_core_hnd__evv_is_affine(_ctx); /*bool*/;
  if (_match_23421) {
    return kk_std_core__ctail_zipwith(xs1, ys1, f3, kk_std_core_types__new_CTailNil(_ctx), _ctx);
  }
  return kk_std_core__ctailm_zipwith(xs1, ys1, f3, kk_std_core_new_zipwith_fun25063(_ctx), _ctx);
}
 
// monadic lift

kk_std_core__list kk_std_core__mlift21228_zipwith_acc(kk_std_core__list acc, kk_function_t f, kk_integer_t i, kk_std_core__list xx, kk_std_core__list yy, kk_box_t _y_260, kk_context_t* _ctx) { /* forall<e,a,b,c> (acc : list<b>, f : (int, a, c) -> e b, i : int, xx : list<a>, yy : list<c>, b) -> e list<b> */ 
  kk_integer_t _x25064 = kk_integer_add(i,(kk_integer_from_small(1)),kk_context()); /*int*/
  kk_std_core__list _x25065 = kk_std_core__new_Cons(kk_reuse_null, _y_260, acc, _ctx); /*list<61>*/
  return kk_std_core_zipwith_acc(f, _x25064, _x25065, xx, yy, _ctx);
}


// lift anonymous function
struct kk_std_core_zipwith_acc_fun25071__t {
  struct kk_function_s _base;
  kk_std_core__list acc0;
  kk_function_t f0;
  kk_integer_t i0;
  kk_std_core__list xx0;
  kk_std_core__list yy0;
};
static kk_box_t kk_std_core_zipwith_acc_fun25071(kk_function_t _fself, kk_box_t _b_23298, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_zipwith_acc_fun25071(kk_std_core__list acc0, kk_function_t f0, kk_integer_t i0, kk_std_core__list xx0, kk_std_core__list yy0, kk_context_t* _ctx) {
  struct kk_std_core_zipwith_acc_fun25071__t* _self = kk_function_alloc_as(struct kk_std_core_zipwith_acc_fun25071__t, 6, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core_zipwith_acc_fun25071, kk_context());
  _self->acc0 = acc0;
  _self->f0 = f0;
  _self->i0 = i0;
  _self->xx0 = xx0;
  _self->yy0 = yy0;
  return &_self->_base;
}

static kk_box_t kk_std_core_zipwith_acc_fun25071(kk_function_t _fself, kk_box_t _b_23298, kk_context_t* _ctx) {
  struct kk_std_core_zipwith_acc_fun25071__t* _self = kk_function_as(struct kk_std_core_zipwith_acc_fun25071__t*, _fself);
  kk_std_core__list acc0 = _self->acc0; /* list<20884> */
  kk_function_t f0 = _self->f0; /* (int, 20882, 20892) -> 20879 20884 */
  kk_integer_t i0 = _self->i0; /* int */
  kk_std_core__list xx0 = _self->xx0; /* list<20882> */
  kk_std_core__list yy0 = _self->yy0; /* list<20892> */
  kk_drop_match(_self, {kk_std_core__list_dup(acc0);kk_function_dup(f0);kk_integer_dup(i0);kk_std_core__list_dup(xx0);kk_std_core__list_dup(yy0);}, {}, _ctx)
  kk_std_core__list _x25072 = kk_std_core__mlift21228_zipwith_acc(acc0, f0, i0, xx0, yy0, _b_23298, _ctx); /*list<20884>*/
  return kk_std_core__list_box(_x25072, _ctx);
}

kk_std_core__list kk_std_core_zipwith_acc(kk_function_t f0, kk_integer_t i0, kk_std_core__list acc0, kk_std_core__list xs, kk_std_core__list ys, kk_context_t* _ctx) { /* forall<a,b,c,e> ((int, a, b) -> e c, int, list<c>, list<a>, list<b>) -> e list<c> */ 
  kk__tailcall: ;
  if (kk_std_core__is_Nil(xs)) {
    kk_function_drop(f0, _ctx);
    kk_integer_drop(i0, _ctx);
    kk_std_core__list_drop(ys, _ctx);
    return kk_std_core_reverse(acc0, _ctx);
  }
  struct kk_std_core_Cons* _con25066 = kk_std_core__as_Cons(xs);
  kk_box_t x = _con25066->head;
  kk_std_core__list xx0 = _con25066->tail;
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
  struct kk_std_core_Cons* _con25067 = kk_std_core__as_Cons(ys);
  kk_box_t y = _con25067->head;
  kk_std_core__list yy0 = _con25067->tail;
  kk_reuse_t _ru_23414 = kk_reuse_null; /*reuse*/;
  if (kk_std_core__list_is_unique(ys)) {
    _ru_23414 = (kk_std_core__list_reuse(ys));
  }
  else {
    kk_box_dup(y);
    kk_std_core__list_dup(yy0);
    kk_std_core__list_decref(ys, _ctx);
    _ru_23414 = kk_reuse_null;
  }
  kk_box_t x0_21831;
  kk_function_t _x25069 = kk_function_dup(f0); /*(int, 20882, 20892) -> 20879 20884*/
  kk_integer_t _x25068 = kk_integer_dup(i0); /*int*/
  x0_21831 = kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_box_t, kk_box_t, kk_context_t*), _x25069, (_x25069, _x25068, x, y, _ctx)); /*20884*/
  if (kk_yielding(kk_context())) {
    kk_reuse_drop(_ru_23414, _ctx);
    kk_box_drop(x0_21831, _ctx);
    kk_box_t _x25070 = kk_std_core_hnd_yield_extend(kk_std_core_new_zipwith_acc_fun25071(acc0, f0, i0, xx0, yy0, _ctx), _ctx); /*3991*/
    return kk_std_core__list_unbox(_x25070, _ctx);
  }
  { // tailcall
    kk_integer_t _x25073 = kk_integer_add(i0,(kk_integer_from_small(1)),kk_context()); /*int*/
    kk_std_core__list _x25074 = kk_std_core__new_Cons(_ru_23414, x0_21831, acc0, _ctx); /*list<61>*/
    i0 = _x25073;
    acc0 = _x25074;
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
struct kk_std_core__mlift21230_op_fun25076__t {
  struct kk_function_s _base;
  kk_box_t _y_2640;
};
static kk_box_t kk_std_core__mlift21230_op_fun25076(kk_function_t _fself, kk_box_t _b_23302, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_mlift21230_op_fun25076(kk_box_t _y_2640, kk_context_t* _ctx) {
  struct kk_std_core__mlift21230_op_fun25076__t* _self = kk_function_alloc_as(struct kk_std_core__mlift21230_op_fun25076__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__mlift21230_op_fun25076, kk_context());
  _self->_y_2640 = _y_2640;
  return &_self->_base;
}

static kk_box_t kk_std_core__mlift21230_op_fun25076(kk_function_t _fself, kk_box_t _b_23302, kk_context_t* _ctx) {
  struct kk_std_core__mlift21230_op_fun25076__t* _self = kk_function_as(struct kk_std_core__mlift21230_op_fun25076__t*, _fself);
  kk_box_t _y_2640 = _self->_y_2640; /* 20958 */
  kk_drop_match(_self, {kk_box_dup(_y_2640);}, {}, _ctx)
  kk_std_core__list _x25077;
  kk_std_core__list _x25078 = kk_std_core__list_unbox(_b_23302, _ctx); /*list<20958>*/
  _x25077 = kk_std_core__mlift21229_op(_y_2640, _x25078, _ctx); /*list<20958>*/
  return kk_std_core__list_box(_x25077, _ctx);
}

kk_std_core__list kk_std_core__mlift21230_op(kk_function_t f, kk_integer_t i, kk_std_core__list xx, kk_std_core__list yy, kk_box_t _y_2640, kk_context_t* _ctx) { /* forall<a,b,c,e> (f : (int, a, b) -> e c, i : int, xx : list<a>, yy : list<b>, c) -> e list<c> */ 
  kk_integer_t i0_21101 = kk_integer_add(i,(kk_integer_from_small(1)),kk_context()); /*int*/;
  kk_std_core__list x_21835 = kk_std_core__lift21062_zipwith_indexed(f, i0_21101, xx, yy, _ctx); /*list<20958>*/;
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_21835, _ctx);
    kk_box_t _x25075 = kk_std_core_hnd_yield_extend(kk_std_core__new_mlift21230_op_fun25076(_y_2640, _ctx), _ctx); /*3991*/
    return kk_std_core__list_unbox(_x25075, _ctx);
  }
  return kk_std_core__mlift21229_op(_y_2640, x_21835, _ctx);
}
 
// lift


// lift anonymous function
struct kk_std_core__lift21062_zipwith_indexed_fun25084__t {
  struct kk_function_s _base;
  kk_function_t f0;
  kk_integer_t i0;
  kk_std_core__list xx0;
  kk_std_core__list yy0;
};
static kk_box_t kk_std_core__lift21062_zipwith_indexed_fun25084(kk_function_t _fself, kk_box_t _b_23306, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_lift21062_zipwith_indexed_fun25084(kk_function_t f0, kk_integer_t i0, kk_std_core__list xx0, kk_std_core__list yy0, kk_context_t* _ctx) {
  struct kk_std_core__lift21062_zipwith_indexed_fun25084__t* _self = kk_function_alloc_as(struct kk_std_core__lift21062_zipwith_indexed_fun25084__t, 5, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__lift21062_zipwith_indexed_fun25084, kk_context());
  _self->f0 = f0;
  _self->i0 = i0;
  _self->xx0 = xx0;
  _self->yy0 = yy0;
  return &_self->_base;
}

static kk_box_t kk_std_core__lift21062_zipwith_indexed_fun25084(kk_function_t _fself, kk_box_t _b_23306, kk_context_t* _ctx) {
  struct kk_std_core__lift21062_zipwith_indexed_fun25084__t* _self = kk_function_as(struct kk_std_core__lift21062_zipwith_indexed_fun25084__t*, _fself);
  kk_function_t f0 = _self->f0; /* (int, 20956, 20957) -> 20959 20958 */
  kk_integer_t i0 = _self->i0; /* int */
  kk_std_core__list xx0 = _self->xx0; /* list<20956> */
  kk_std_core__list yy0 = _self->yy0; /* list<20957> */
  kk_drop_match(_self, {kk_function_dup(f0);kk_integer_dup(i0);kk_std_core__list_dup(xx0);kk_std_core__list_dup(yy0);}, {}, _ctx)
  kk_std_core__list _x25085 = kk_std_core__mlift21230_op(f0, i0, xx0, yy0, _b_23306, _ctx); /*list<20958>*/
  return kk_std_core__list_box(_x25085, _ctx);
}


// lift anonymous function
struct kk_std_core__lift21062_zipwith_indexed_fun25087__t {
  struct kk_function_s _base;
  kk_box_t x0_21837;
};
static kk_box_t kk_std_core__lift21062_zipwith_indexed_fun25087(kk_function_t _fself, kk_box_t _b_23308, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_lift21062_zipwith_indexed_fun25087(kk_box_t x0_21837, kk_context_t* _ctx) {
  struct kk_std_core__lift21062_zipwith_indexed_fun25087__t* _self = kk_function_alloc_as(struct kk_std_core__lift21062_zipwith_indexed_fun25087__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_core__lift21062_zipwith_indexed_fun25087, kk_context());
  _self->x0_21837 = x0_21837;
  return &_self->_base;
}

static kk_box_t kk_std_core__lift21062_zipwith_indexed_fun25087(kk_function_t _fself, kk_box_t _b_23308, kk_context_t* _ctx) {
  struct kk_std_core__lift21062_zipwith_indexed_fun25087__t* _self = kk_function_as(struct kk_std_core__lift21062_zipwith_indexed_fun25087__t*, _fself);
  kk_box_t x0_21837 = _self->x0_21837; /* 20958 */
  kk_drop_match(_self, {kk_box_dup(x0_21837);}, {}, _ctx)
  kk_std_core__list _x25088;
  kk_std_core__list _x25089 = kk_std_core__list_unbox(_b_23308, _ctx); /*list<20958>*/
  _x25088 = kk_std_core__mlift21229_op(x0_21837, _x25089, _ctx); /*list<20958>*/
  return kk_std_core__list_box(_x25088, _ctx);
}

kk_std_core__list kk_std_core__lift21062_zipwith_indexed(kk_function_t f0, kk_integer_t i0, kk_std_core__list xs, kk_std_core__list ys, kk_context_t* _ctx) { /* forall<a,b,c,e> (f : (int, a, b) -> e c, i : int, xs : list<a>, ys : list<b>) -> e list<c> */ 
  if (kk_std_core__is_Cons(xs)) {
    struct kk_std_core_Cons* _con25079 = kk_std_core__as_Cons(xs);
    kk_box_t x = _con25079->head;
    kk_std_core__list xx0 = _con25079->tail;
    if (kk_std_core__list_is_unique(xs)) {
      kk_std_core__list_free(xs);
    }
    else {
      kk_box_dup(x);
      kk_std_core__list_dup(xx0);
      kk_std_core__list_decref(xs, _ctx);
    }
    if (kk_std_core__is_Cons(ys)) {
      struct kk_std_core_Cons* _con25080 = kk_std_core__as_Cons(ys);
      kk_box_t y = _con25080->head;
      kk_std_core__list yy0 = _con25080->tail;
      kk_reuse_t _ru_23416 = kk_reuse_null; /*reuse*/;
      if (kk_std_core__list_is_unique(ys)) {
        _ru_23416 = (kk_std_core__list_reuse(ys));
      }
      else {
        kk_box_dup(y);
        kk_std_core__list_dup(yy0);
        kk_std_core__list_decref(ys, _ctx);
        _ru_23416 = kk_reuse_null;
      }
      kk_box_t x0_21837;
      kk_function_t _x25082 = kk_function_dup(f0); /*(int, 20956, 20957) -> 20959 20958*/
      kk_integer_t _x25081 = kk_integer_dup(i0); /*int*/
      x0_21837 = kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_box_t, kk_box_t, kk_context_t*), _x25082, (_x25082, _x25081, x, y, _ctx)); /*20958*/
      if (kk_yielding(kk_context())) {
        kk_reuse_drop(_ru_23416, _ctx);
        kk_box_drop(x0_21837, _ctx);
        kk_box_t _x25083 = kk_std_core_hnd_yield_extend(kk_std_core__new_lift21062_zipwith_indexed_fun25084(f0, i0, xx0, yy0, _ctx), _ctx); /*3991*/
        return kk_std_core__list_unbox(_x25083, _ctx);
      }
      kk_integer_t i0_211010 = kk_integer_add(i0,(kk_integer_from_small(1)),kk_context()); /*int*/;
      kk_std_core__list x1_21841 = kk_std_core__lift21062_zipwith_indexed(f0, i0_211010, xx0, yy0, _ctx); /*list<20958>*/;
      if (kk_yielding(kk_context())) {
        kk_reuse_drop(_ru_23416, _ctx);
        kk_std_core__list_drop(x1_21841, _ctx);
        kk_box_t _x25086 = kk_std_core_hnd_yield_extend(kk_std_core__new_lift21062_zipwith_indexed_fun25087(x0_21837, _ctx), _ctx); /*3991*/
        return kk_std_core__list_unbox(_x25086, _ctx);
      }
      return kk_std_core__new_Cons(_ru_23416, x0_21837, x1_21841, _ctx);
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
    kk_string_t _x23682;
    kk_define_string_literal(, _s23683, 8, "exn.core")
    _x23682 = kk_string_dup(_s23683); /*string*/
    kk_std_core__tag_exn = kk_std_core_hnd__new_Htag(_x23682, _ctx); /*std/core/hnd/htag<.hnd-exn>*/
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
    kk_string_t _x24447 = kk_string_empty(); /*string*/
    size_t _x24449 = ((size_t)0); /*size_t*/
    size_t _x24450 = ((size_t)0); /*size_t*/
    kk_std_core_empty = kk_std_core__new_Sslice(_x24447, _x24449, _x24450, _ctx); /*sslice*/
  }
  {
    kk_std_core_null_const = kk_std_core_null(kk_std_core_types__new_Nothing(_ctx), _ctx); /*forall<a> null<a>*/
  }
}
