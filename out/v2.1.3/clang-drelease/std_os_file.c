// Koka generated module: "std/os/file", koka version: 2.1.3
#include "std_os_file.h"
/*---------------------------------------------------------------------------
  Copyright 2020, Daan Leijen, Microsoft Corporation.

  This is free software; you can redistribute it and/or modify it under the
  terms of the Apache License, Version 2.0. A copy of the License can be
  found in the file "license.txt" at the root of this distribution.
---------------------------------------------------------------------------*/

static kk_std_core__error kk_os_read_text_file_error( kk_string_t path, kk_context_t* ctx ) {
  kk_string_t content;
  const int err = kk_os_read_text_file(path,&content,ctx);
  if (err != 0) return kk_error_from_errno(err,ctx);
           else return kk_error_ok(kk_string_box(content),ctx);
}

static kk_std_core__error kk_os_write_text_file_error( kk_string_t path, kk_string_t content, kk_context_t* ctx ) {
  const int err = kk_os_write_text_file(path,content,ctx);
  if (err != 0) return kk_error_from_errno(err,ctx);
           else return kk_error_ok(kk_unit_box(kk_Unit),ctx);
}


kk_std_core__exception kk_std_os_file_prepend(kk_std_core__exception exn, kk_string_t pre, kk_context_t* _ctx) { /* (exn : exception, pre : string) -> exception */ 
  kk_string_t _x586;
  kk_string_t _x587;
  kk_string_t _x588;
  kk_define_string_literal(, _s589, 2, ": ")
  _x588 = kk_string_dup(_s589); /*string*/
  kk_string_t _x590;
  kk_string_t _x = exn.message;
  kk_string_dup(_x);
  _x590 = _x; /*string*/
  _x587 = kk_std_core__lp__plus__plus__1_rp_(_x588, _x590, _ctx); /*string*/
  _x586 = kk_std_core__lp__plus__plus__1_rp_(pre, _x587, _ctx); /*string*/
  kk_std_core__exception_info _x591;
  kk_std_core__exception_info _x0 = exn.info;
  kk_std_core__exception_info_dup(_x0);
  kk_std_core__exception_drop(exn, _ctx);
  _x591 = _x0; /*exception-info*/
  return kk_std_core__new_Exception(_x586, _x591, _ctx);
}

kk_std_core__error kk_std_os_file_read_text_file_err(kk_string_t path, kk_context_t* _ctx) { /* (path : string) -> fsys error<string> */ 
  return kk_os_read_text_file_error(path,kk_context());
}

kk_std_core__error kk_std_os_file_write_text_file_err(kk_string_t path, kk_string_t content, kk_context_t* _ctx) { /* (path : string, content : string) -> fsys error<()> */ 
  return kk_os_write_text_file_error(path,content,kk_context());
}
 
// Read a text file synchronously (using UTF8 encoding)


// lift anonymous function
struct kk_std_os_file_read_text_file_fun593__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_file_read_text_file_fun593(kk_function_t _fself, kk_box_t _b_488, kk_context_t* _ctx);
static kk_function_t kk_std_os_file_new_read_text_file_fun593(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_file_read_text_file_fun593, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_file_read_text_file_fun593(kk_function_t _fself, kk_box_t _b_488, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x594;
  kk_std_os_path__path _x595 = kk_std_os_path__path_unbox(_b_488, _ctx); /*std/os/path/path*/
  _x594 = kk_std_os_path_string(_x595, _ctx); /*string*/
  return kk_string_box(_x594);
}


// lift anonymous function
struct kk_std_os_file_read_text_file_fun599__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_file_read_text_file_fun599(kk_function_t _fself, kk_box_t _b_493, kk_context_t* _ctx);
static kk_function_t kk_std_os_file_new_read_text_file_fun599(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_file_read_text_file_fun599, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_file_read_text_file_fun599(kk_function_t _fself, kk_box_t _b_493, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core__error _x600;
  kk_string_t _x601 = kk_string_unbox(_b_493); /*string*/
  _x600 = kk_std_os_file_read_text_file_err(_x601, _ctx); /*error<string>*/
  return kk_std_core__error_box(_x600, _ctx);
}


// lift anonymous function
struct kk_std_os_file_read_text_file_fun607__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_file_read_text_file_fun607(kk_function_t _fself, kk_box_t _b_496, kk_context_t* _ctx);
static kk_function_t kk_std_os_file_new_read_text_file_fun607(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_file_read_text_file_fun607, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_file_read_text_file_fun607(kk_function_t _fself, kk_box_t _b_496, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x608;
  kk_std_os_path__path _x609 = kk_std_os_path__path_unbox(_b_496, _ctx); /*std/os/path/path*/
  _x608 = kk_std_os_path_show(_x609, _ctx); /*string*/
  return kk_string_box(_x608);
}


// lift anonymous function
struct kk_std_os_file_read_text_file_fun611__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_file_read_text_file_fun611(kk_function_t _fself, kk_box_t _b_502, kk_box_t _b_503, kk_context_t* _ctx);
static kk_function_t kk_std_os_file_new_read_text_file_fun611(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_file_read_text_file_fun611, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_file_read_text_file_fun611(kk_function_t _fself, kk_box_t _b_502, kk_box_t _b_503, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core__exception _x612;
  kk_std_core__exception _x613 = kk_std_core__exception_unbox(_b_502, _ctx); /*exception*/
  kk_string_t _x614 = kk_string_unbox(_b_503); /*string*/
  _x612 = kk_std_os_file_prepend(_x613, _x614, _ctx); /*exception*/
  return kk_std_core__exception_box(_x612, _ctx);
}

kk_string_t kk_std_os_file_read_text_file(kk_std_os_path__path path, kk_context_t* _ctx) { /* (path : std/os/path/path) -> <exn,fsys> string */ 
  kk_std_core__error _match_585;
  kk_string_t _x1;
  kk_box_t _x592;
  kk_box_t _x596;
  kk_std_os_path__path _x597 = kk_std_os_path__path_dup(path); /*std/os/path/path*/
  _x596 = kk_std_os_path__path_box(_x597, _ctx); /*3238*/
  _x592 = kk_std_core_hnd__open_none1(kk_std_os_file_new_read_text_file_fun593(_ctx), _x596, _ctx); /*3239*/
  _x1 = kk_string_unbox(_x592); /*string*/
  kk_box_t _x598 = kk_std_core_hnd__open_none1(kk_std_os_file_new_read_text_file_fun599(_ctx), kk_string_box(_x1), _ctx); /*3239*/
  _match_585 = kk_std_core__error_unbox(_x598, _ctx); /*error<string>*/
  if (kk_std_core__is_Error(_match_585)) {
    kk_std_core__exception exn = _match_585._cons.Error.exception;
    kk_std_core__exception_dup(exn);
    kk_std_core__error_drop(_match_585, _ctx);
    kk_std_core__error err_479;
    kk_std_core__exception _x602;
    kk_string_t _x2;
    kk_string_t _x603;
    kk_define_string_literal(, _s604, 25, "unable to read text file ")
    _x603 = kk_string_dup(_s604); /*string*/
    kk_string_t _x605;
    kk_box_t _x606 = kk_std_core_hnd__open_none1(kk_std_os_file_new_read_text_file_fun607(_ctx), kk_std_os_path__path_box(path, _ctx), _ctx); /*3239*/
    _x605 = kk_string_unbox(_x606); /*string*/
    _x2 = kk_std_core__lp__plus__plus__1_rp_(_x603, _x605, _ctx); /*string*/
    kk_box_t _x610 = kk_std_core_hnd__open_none2(kk_std_os_file_new_read_text_file_fun611(_ctx), kk_std_core__exception_box(exn, _ctx), kk_string_box(_x2), _ctx); /*3333*/
    _x602 = kk_std_core__exception_unbox(_x610, _ctx); /*exception*/
    err_479 = kk_std_core__new_Error(_x602, _ctx); /*error<string>*/
    if (kk_std_core__is_Error(err_479)) {
      kk_std_core__exception exn0 = err_479._cons.Error.exception;
      kk_std_core__exception_dup(exn0);
      kk_std_core__error_drop(err_479, _ctx);
      kk_box_t _x615 = kk_std_core_throw_exn(exn0, _ctx); /*11740*/
      return kk_string_unbox(_x615);
    }
    kk_box_t _box_x508 = err_479._cons.Ok.result;
    kk_string_t x = kk_string_unbox(_box_x508);
    kk_string_dup(x);
    kk_std_core__error_drop(err_479, _ctx);
    return x;
  }
  kk_box_t _box_x509 = _match_585._cons.Ok.result;
  kk_string_t content = kk_string_unbox(_box_x509);
  kk_std_os_path__path_drop(path, _ctx);
  kk_string_dup(content);
  kk_std_core__error_drop(_match_585, _ctx);
  return content;
}
 
// monadic lift


// lift anonymous function
struct kk_std_os_file__mlift476_write_text_file_fun619__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_file__mlift476_write_text_file_fun619(kk_function_t _fself, kk_box_t _b_515, kk_context_t* _ctx);
static kk_function_t kk_std_os_file__new_mlift476_write_text_file_fun619(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_file__mlift476_write_text_file_fun619, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_file__mlift476_write_text_file_fun619(kk_function_t _fself, kk_box_t _b_515, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x620;
  kk_std_os_path__path _x621 = kk_std_os_path__path_unbox(_b_515, _ctx); /*std/os/path/path*/
  _x620 = kk_std_os_path_string(_x621, _ctx); /*string*/
  return kk_string_box(_x620);
}


// lift anonymous function
struct kk_std_os_file__mlift476_write_text_file_fun625__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_file__mlift476_write_text_file_fun625(kk_function_t _fself, kk_box_t _b_521, kk_box_t _b_522, kk_context_t* _ctx);
static kk_function_t kk_std_os_file__new_mlift476_write_text_file_fun625(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_file__mlift476_write_text_file_fun625, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_file__mlift476_write_text_file_fun625(kk_function_t _fself, kk_box_t _b_521, kk_box_t _b_522, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core__error _x626;
  kk_string_t _x627 = kk_string_unbox(_b_521); /*string*/
  kk_string_t _x628 = kk_string_unbox(_b_522); /*string*/
  _x626 = kk_std_os_file_write_text_file_err(_x627, _x628, _ctx); /*error<()>*/
  return kk_std_core__error_box(_x626, _ctx);
}


// lift anonymous function
struct kk_std_os_file__mlift476_write_text_file_fun634__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_file__mlift476_write_text_file_fun634(kk_function_t _fself, kk_box_t _b_525, kk_context_t* _ctx);
static kk_function_t kk_std_os_file__new_mlift476_write_text_file_fun634(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_file__mlift476_write_text_file_fun634, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_file__mlift476_write_text_file_fun634(kk_function_t _fself, kk_box_t _b_525, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x635;
  kk_std_os_path__path _x636 = kk_std_os_path__path_unbox(_b_525, _ctx); /*std/os/path/path*/
  _x635 = kk_std_os_path_show(_x636, _ctx); /*string*/
  return kk_string_box(_x635);
}


// lift anonymous function
struct kk_std_os_file__mlift476_write_text_file_fun638__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_file__mlift476_write_text_file_fun638(kk_function_t _fself, kk_box_t _b_531, kk_box_t _b_532, kk_context_t* _ctx);
static kk_function_t kk_std_os_file__new_mlift476_write_text_file_fun638(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_file__mlift476_write_text_file_fun638, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_file__mlift476_write_text_file_fun638(kk_function_t _fself, kk_box_t _b_531, kk_box_t _b_532, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core__exception _x639;
  kk_std_core__exception _x640 = kk_std_core__exception_unbox(_b_531, _ctx); /*exception*/
  kk_string_t _x641 = kk_string_unbox(_b_532); /*string*/
  _x639 = kk_std_os_file_prepend(_x640, _x641, _ctx); /*exception*/
  return kk_std_core__exception_box(_x639, _ctx);
}

kk_unit_t kk_std_os_file__mlift476_write_text_file(kk_string_t content, kk_std_os_path__path path, kk_unit_t _c_3, kk_context_t* _ctx) { /* (content : string, path : std/os/path/path, ()) -> () */ 
  kk_std_core__error _match_584;
  kk_string_t _x10;
  kk_box_t _x618;
  kk_box_t _x622;
  kk_std_os_path__path _x623 = kk_std_os_path__path_dup(path); /*std/os/path/path*/
  _x622 = kk_std_os_path__path_box(_x623, _ctx); /*3238*/
  _x618 = kk_std_core_hnd__open_none1(kk_std_os_file__new_mlift476_write_text_file_fun619(_ctx), _x622, _ctx); /*3239*/
  _x10 = kk_string_unbox(_x618); /*string*/
  kk_box_t _x624 = kk_std_core_hnd__open_none2(kk_std_os_file__new_mlift476_write_text_file_fun625(_ctx), kk_string_box(_x10), kk_string_box(content), _ctx); /*3333*/
  _match_584 = kk_std_core__error_unbox(_x624, _ctx); /*error<()>*/
  if (kk_std_core__is_Error(_match_584)) {
    kk_std_core__exception exn = _match_584._cons.Error.exception;
    kk_std_core__exception_dup(exn);
    kk_std_core__error_drop(_match_584, _ctx);
    kk_std_core__error err_480;
    kk_std_core__exception _x629;
    kk_string_t _x20;
    kk_string_t _x630;
    kk_define_string_literal(, _s631, 26, "unable to write text file ")
    _x630 = kk_string_dup(_s631); /*string*/
    kk_string_t _x632;
    kk_box_t _x633 = kk_std_core_hnd__open_none1(kk_std_os_file__new_mlift476_write_text_file_fun634(_ctx), kk_std_os_path__path_box(path, _ctx), _ctx); /*3239*/
    _x632 = kk_string_unbox(_x633); /*string*/
    _x20 = kk_std_core__lp__plus__plus__1_rp_(_x630, _x632, _ctx); /*string*/
    kk_box_t _x637 = kk_std_core_hnd__open_none2(kk_std_os_file__new_mlift476_write_text_file_fun638(_ctx), kk_std_core__exception_box(exn, _ctx), kk_string_box(_x20), _ctx); /*3333*/
    _x629 = kk_std_core__exception_unbox(_x637, _ctx); /*exception*/
    err_480 = kk_std_core__new_Error(_x629, _ctx); /*error<()>*/
    if (kk_std_core__is_Error(err_480)) {
      kk_std_core__exception exn0 = err_480._cons.Error.exception;
      kk_std_core__exception_dup(exn0);
      kk_std_core__error_drop(err_480, _ctx);
      kk_box_t _x642 = kk_std_core_throw_exn(exn0, _ctx); /*11740*/
      kk_unit_unbox(_x642); return kk_Unit;
    }
    kk_box_t _box_x537 = err_480._cons.Ok.result;
    kk_unit_t x = kk_unit_unbox(_box_x537);
    kk_std_core__error_drop(err_480, _ctx);
    x; return kk_Unit;
  }
  kk_std_core__error_drop(_match_584, _ctx);
  kk_std_os_path__path_drop(path, _ctx);
  kk_Unit; return kk_Unit;
}
 
// Write a text file synchronously (using UTF8 encoding)


// lift anonymous function
struct kk_std_os_file_write_text_file_fun648__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_file_write_text_file_fun648(kk_function_t _fself, kk_box_t _b_545, kk_context_t* _ctx);
static kk_function_t kk_std_os_file_new_write_text_file_fun648(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_file_write_text_file_fun648, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_file_write_text_file_fun648(kk_function_t _fself, kk_box_t _b_545, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_os_path__path _x649;
  kk_std_os_path__path _x650 = kk_std_os_path__path_unbox(_b_545, _ctx); /*std/os/path/path*/
  _x649 = kk_std_os_path_nobase(_x650, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x649, _ctx);
}


// lift anonymous function
struct kk_std_os_file_write_text_file_fun654__t {
  struct kk_function_s _base;
  kk_string_t content;
  kk_std_os_path__path path;
};
static kk_box_t kk_std_os_file_write_text_file_fun654(kk_function_t _fself, kk_box_t _b_549, kk_context_t* _ctx);
static kk_function_t kk_std_os_file_new_write_text_file_fun654(kk_string_t content, kk_std_os_path__path path, kk_context_t* _ctx) {
  struct kk_std_os_file_write_text_file_fun654__t* _self = kk_function_alloc_as(struct kk_std_os_file_write_text_file_fun654__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_os_file_write_text_file_fun654, kk_context());
  _self->content = content;
  _self->path = path;
  return &_self->_base;
}

static kk_box_t kk_std_os_file_write_text_file_fun654(kk_function_t _fself, kk_box_t _b_549, kk_context_t* _ctx) {
  struct kk_std_os_file_write_text_file_fun654__t* _self = kk_function_as(struct kk_std_os_file_write_text_file_fun654__t*, _fself);
  kk_string_t content = _self->content; /* string */
  kk_std_os_path__path path = _self->path; /* std/os/path/path */
  kk_drop_match(_self, {kk_string_dup(content);kk_std_os_path__path_dup(path);}, {}, _ctx)
  kk_unit_t _x655 = kk_Unit;
  kk_unit_t _x656 = kk_Unit;
  kk_unit_unbox(_b_549);
  kk_std_os_file__mlift476_write_text_file(content, path, _x656, _ctx);
  return kk_unit_box(_x655);
}


// lift anonymous function
struct kk_std_os_file_write_text_file_fun658__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_file_write_text_file_fun658(kk_function_t _fself, kk_box_t _b_552, kk_context_t* _ctx);
static kk_function_t kk_std_os_file_new_write_text_file_fun658(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_file_write_text_file_fun658, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_file_write_text_file_fun658(kk_function_t _fself, kk_box_t _b_552, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x659;
  kk_std_os_path__path _x660 = kk_std_os_path__path_unbox(_b_552, _ctx); /*std/os/path/path*/
  _x659 = kk_std_os_path_string(_x660, _ctx); /*string*/
  return kk_string_box(_x659);
}


// lift anonymous function
struct kk_std_os_file_write_text_file_fun664__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_file_write_text_file_fun664(kk_function_t _fself, kk_box_t _b_558, kk_box_t _b_559, kk_context_t* _ctx);
static kk_function_t kk_std_os_file_new_write_text_file_fun664(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_file_write_text_file_fun664, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_file_write_text_file_fun664(kk_function_t _fself, kk_box_t _b_558, kk_box_t _b_559, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core__error _x665;
  kk_string_t _x666 = kk_string_unbox(_b_558); /*string*/
  kk_string_t _x667 = kk_string_unbox(_b_559); /*string*/
  _x665 = kk_std_os_file_write_text_file_err(_x666, _x667, _ctx); /*error<()>*/
  return kk_std_core__error_box(_x665, _ctx);
}


// lift anonymous function
struct kk_std_os_file_write_text_file_fun673__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_file_write_text_file_fun673(kk_function_t _fself, kk_box_t _b_562, kk_context_t* _ctx);
static kk_function_t kk_std_os_file_new_write_text_file_fun673(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_file_write_text_file_fun673, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_file_write_text_file_fun673(kk_function_t _fself, kk_box_t _b_562, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x674;
  kk_std_os_path__path _x675 = kk_std_os_path__path_unbox(_b_562, _ctx); /*std/os/path/path*/
  _x674 = kk_std_os_path_show(_x675, _ctx); /*string*/
  return kk_string_box(_x674);
}


// lift anonymous function
struct kk_std_os_file_write_text_file_fun677__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_file_write_text_file_fun677(kk_function_t _fself, kk_box_t _b_568, kk_box_t _b_569, kk_context_t* _ctx);
static kk_function_t kk_std_os_file_new_write_text_file_fun677(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_file_write_text_file_fun677, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_file_write_text_file_fun677(kk_function_t _fself, kk_box_t _b_568, kk_box_t _b_569, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core__exception _x678;
  kk_std_core__exception _x679 = kk_std_core__exception_unbox(_b_568, _ctx); /*exception*/
  kk_string_t _x680 = kk_string_unbox(_b_569); /*string*/
  _x678 = kk_std_os_file_prepend(_x679, _x680, _ctx); /*exception*/
  return kk_std_core__exception_box(_x678, _ctx);
}

kk_unit_t kk_std_os_file_write_text_file(kk_std_os_path__path path, kk_string_t content, kk_std_core_types__optional create_dir, kk_context_t* _ctx) { /* (path : std/os/path/path, content : string, create-dir : optional<bool>) -> <exn,fsys> () */ 
  kk_unit_t x_481 = kk_Unit;
  bool _match_583;
  if (kk_std_core_types__is_Optional(create_dir)) {
    kk_box_t _box_x542 = create_dir._cons.Optional.value;
    bool _create_dir_268 = kk_bool_unbox(_box_x542);
    kk_std_core_types__optional_drop(create_dir, _ctx);
    _match_583 = _create_dir_268; /*bool*/
    goto _match644;
  }
  _match_583 = true; /*bool*/
  _match644: ;
  if (_match_583) {
    kk_std_os_path__path _x646;
    kk_box_t _x647;
    kk_box_t _x651;
    kk_std_os_path__path _x652 = kk_std_os_path__path_dup(path); /*std/os/path/path*/
    _x651 = kk_std_os_path__path_box(_x652, _ctx); /*3238*/
    _x647 = kk_std_core_hnd__open_none1(kk_std_os_file_new_write_text_file_fun648(_ctx), _x651, _ctx); /*3239*/
    _x646 = kk_std_os_path__path_unbox(_x647, _ctx); /*std/os/path/path*/
    kk_std_os_dir_ensure_dir(_x646, _ctx);
  }
  else {
    kk_Unit;
  }
  if (kk_yielding(kk_context())) {
    kk_box_t _x653 = kk_std_core_hnd_yield_extend(kk_std_os_file_new_write_text_file_fun654(content, path, _ctx), _ctx); /*3991*/
    kk_unit_unbox(_x653); return kk_Unit;
  }
  kk_std_core__error _match_582;
  kk_string_t _x10;
  kk_box_t _x657;
  kk_box_t _x661;
  kk_std_os_path__path _x662 = kk_std_os_path__path_dup(path); /*std/os/path/path*/
  _x661 = kk_std_os_path__path_box(_x662, _ctx); /*3238*/
  _x657 = kk_std_core_hnd__open_none1(kk_std_os_file_new_write_text_file_fun658(_ctx), _x661, _ctx); /*3239*/
  _x10 = kk_string_unbox(_x657); /*string*/
  kk_box_t _x663 = kk_std_core_hnd__open_none2(kk_std_os_file_new_write_text_file_fun664(_ctx), kk_string_box(_x10), kk_string_box(content), _ctx); /*3333*/
  _match_582 = kk_std_core__error_unbox(_x663, _ctx); /*error<()>*/
  if (kk_std_core__is_Error(_match_582)) {
    kk_std_core__exception exn = _match_582._cons.Error.exception;
    kk_std_core__exception_dup(exn);
    kk_std_core__error_drop(_match_582, _ctx);
    kk_std_core__error err_485;
    kk_std_core__exception _x668;
    kk_string_t _x20;
    kk_string_t _x669;
    kk_define_string_literal(, _s670, 26, "unable to write text file ")
    _x669 = kk_string_dup(_s670); /*string*/
    kk_string_t _x671;
    kk_box_t _x672 = kk_std_core_hnd__open_none1(kk_std_os_file_new_write_text_file_fun673(_ctx), kk_std_os_path__path_box(path, _ctx), _ctx); /*3239*/
    _x671 = kk_string_unbox(_x672); /*string*/
    _x20 = kk_std_core__lp__plus__plus__1_rp_(_x669, _x671, _ctx); /*string*/
    kk_box_t _x676 = kk_std_core_hnd__open_none2(kk_std_os_file_new_write_text_file_fun677(_ctx), kk_std_core__exception_box(exn, _ctx), kk_string_box(_x20), _ctx); /*3333*/
    _x668 = kk_std_core__exception_unbox(_x676, _ctx); /*exception*/
    err_485 = kk_std_core__new_Error(_x668, _ctx); /*error<()>*/
    if (kk_std_core__is_Error(err_485)) {
      kk_std_core__exception exn0 = err_485._cons.Error.exception;
      kk_std_core__exception_dup(exn0);
      kk_std_core__error_drop(err_485, _ctx);
      kk_box_t _x681 = kk_std_core_throw_exn(exn0, _ctx); /*11740*/
      kk_unit_unbox(_x681); return kk_Unit;
    }
    kk_box_t _box_x574 = err_485._cons.Ok.result;
    kk_unit_t x0 = kk_unit_unbox(_box_x574);
    kk_std_core__error_drop(err_485, _ctx);
    x0; return kk_Unit;
  }
  kk_std_core__error_drop(_match_582, _ctx);
  kk_std_os_path__path_drop(path, _ctx);
  kk_Unit; return kk_Unit;
}

// initialization
void kk_std_os_file__init(kk_context_t* _ctx){
  static bool _initialized = false;
  if (_initialized) return;
  _initialized = true;
  kk_std_core_types__init(_ctx);
  kk_std_core_hnd__init(_ctx);
  kk_std_core__init(_ctx);
  kk_std_os_path__init(_ctx);
  kk_std_os_dir__init(_ctx);
}
