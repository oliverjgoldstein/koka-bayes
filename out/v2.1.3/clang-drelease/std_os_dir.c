// Koka generated module: "std/os/dir", koka version: 2.1.3
#include "std_os_dir.h"
/*---------------------------------------------------------------------------
  Copyright 2020, Daan Leijen, Microsoft Corporation.

  This is free software; you can redistribute it and/or modify it under the
  terms of the Apache License, Version 2.0. A copy of the License can be
  found in the file "license.txt" at the root of this distribution.
---------------------------------------------------------------------------*/

static kk_std_core__error kk_os_ensure_dir_error( kk_string_t path, kk_integer_t mode, kk_context_t* ctx ) {
  int m  = kk_integer_clamp32(mode,ctx);
  const int err = kk_os_ensure_dir(path,m,ctx);
  if (err != 0) return kk_error_from_errno(err,ctx);
           else return kk_error_ok(kk_unit_box(kk_Unit),ctx);
}

static kk_std_core__error kk_os_copy_file_error( kk_string_t from, kk_string_t to, bool preserve_mtime, kk_context_t* ctx ) {
  const int err = kk_os_copy_file(from,to,preserve_mtime,ctx);
  if (err != 0) return kk_error_from_errno(err,ctx);
           else return kk_error_ok(kk_unit_box(kk_Unit),ctx);
}

static kk_std_core__error kk_os_list_directory_prim( kk_string_t dir, kk_context_t* ctx ) {
  kk_vector_t contents;
  const int err = kk_os_list_directory(dir,&contents,ctx);
  if (err != 0) return kk_error_from_errno(err,ctx);
           else return kk_error_ok(kk_vector_box(contents,ctx),ctx);
}


kk_std_core__exception kk_std_os_dir_prepend(kk_std_core__exception exn, kk_string_t pre, kk_context_t* _ctx) { /* (exn : exception, pre : string) -> exception */ 
  kk_string_t _x1821;
  kk_string_t _x1822;
  kk_string_t _x1823;
  kk_define_string_literal(, _s1824, 2, ": ")
  _x1823 = kk_string_dup(_s1824); /*string*/
  kk_string_t _x1825;
  kk_string_t _x = exn.message;
  kk_string_dup(_x);
  _x1825 = _x; /*string*/
  _x1822 = kk_std_core__lp__plus__plus__1_rp_(_x1823, _x1825, _ctx); /*string*/
  _x1821 = kk_std_core__lp__plus__plus__1_rp_(pre, _x1822, _ctx); /*string*/
  kk_std_core__exception_info _x1826;
  kk_std_core__exception_info _x0 = exn.info;
  kk_std_core__exception_info_dup(_x0);
  kk_std_core__exception_drop(exn, _ctx);
  _x1826 = _x0; /*exception-info*/
  return kk_std_core__new_Exception(_x1821, _x1826, _ctx);
}

kk_std_core__error kk_std_os_dir_prim_copy_file(kk_string_t from, kk_string_t to, bool preserve_mtime, kk_context_t* _ctx) { /* (from : string, to : string, preserve-mtime : bool) -> fsys error<()> */ 
  return kk_os_copy_file_error(from,to,preserve_mtime,kk_context());
}

kk_std_core__error kk_std_os_dir_ensure_dir_err(kk_string_t path, kk_integer_t mode, kk_context_t* _ctx) { /* (path : string, mode : int) -> fsys error<()> */ 
  return kk_os_ensure_dir_error(path,mode,kk_context());
}

bool kk_std_os_dir_prim_is_dir(kk_string_t dir, kk_context_t* _ctx) { /* (dir : string) -> fsys bool */ 
  return kk_os_is_directory(dir,kk_context());
}

kk_std_core__error kk_std_os_dir_prim_list_dir(kk_string_t dir, kk_context_t* _ctx) { /* (dir : string) -> fsys error<vector<string>> */ 
  return kk_os_list_directory_prim(dir,kk_context());
}

bool kk_std_os_dir_prim_is_file(kk_string_t path, kk_context_t* _ctx) { /* (path : string) -> fsys bool */ 
  return kk_os_is_file(path,kk_context());
}
 
// Copy a file.


// lift anonymous function
struct kk_std_os_dir_copy_file_fun1828__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_dir_copy_file_fun1828(kk_function_t _fself, kk_box_t _b_1475, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir_new_copy_file_fun1828(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_dir_copy_file_fun1828, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_dir_copy_file_fun1828(kk_function_t _fself, kk_box_t _b_1475, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x1829;
  kk_std_os_path__path _x1830 = kk_std_os_path__path_unbox(_b_1475, _ctx); /*std/os/path/path*/
  _x1829 = kk_std_os_path_string(_x1830, _ctx); /*string*/
  return kk_string_box(_x1829);
}


// lift anonymous function
struct kk_std_os_dir_copy_file_fun1834__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_dir_copy_file_fun1834(kk_function_t _fself, kk_box_t _b_1480, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir_new_copy_file_fun1834(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_dir_copy_file_fun1834, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_dir_copy_file_fun1834(kk_function_t _fself, kk_box_t _b_1480, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x1835;
  kk_std_os_path__path _x1836 = kk_std_os_path__path_unbox(_b_1480, _ctx); /*std/os/path/path*/
  _x1835 = kk_std_os_path_string(_x1836, _ctx); /*string*/
  return kk_string_box(_x1835);
}


// lift anonymous function
struct kk_std_os_dir_copy_file_fun1848__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_dir_copy_file_fun1848(kk_function_t _fself, kk_box_t _b_1486, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir_new_copy_file_fun1848(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_dir_copy_file_fun1848, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_dir_copy_file_fun1848(kk_function_t _fself, kk_box_t _b_1486, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x1849;
  kk_std_os_path__path _x1850 = kk_std_os_path__path_unbox(_b_1486, _ctx); /*std/os/path/path*/
  _x1849 = kk_std_os_path_show(_x1850, _ctx); /*string*/
  return kk_string_box(_x1849);
}


// lift anonymous function
struct kk_std_os_dir_copy_file_fun1856__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_dir_copy_file_fun1856(kk_function_t _fself, kk_box_t _b_1489, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir_new_copy_file_fun1856(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_dir_copy_file_fun1856, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_dir_copy_file_fun1856(kk_function_t _fself, kk_box_t _b_1489, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x1857;
  kk_std_os_path__path _x1858 = kk_std_os_path__path_unbox(_b_1489, _ctx); /*std/os/path/path*/
  _x1857 = kk_std_os_path_show(_x1858, _ctx); /*string*/
  return kk_string_box(_x1857);
}


// lift anonymous function
struct kk_std_os_dir_copy_file_fun1860__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_dir_copy_file_fun1860(kk_function_t _fself, kk_box_t _b_1497, kk_box_t _b_1498, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir_new_copy_file_fun1860(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_dir_copy_file_fun1860, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_dir_copy_file_fun1860(kk_function_t _fself, kk_box_t _b_1497, kk_box_t _b_1498, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core__exception _x1861;
  kk_std_core__exception _x1862 = kk_std_core__exception_unbox(_b_1497, _ctx); /*exception*/
  kk_string_t _x1863 = kk_string_unbox(_b_1498); /*string*/
  _x1861 = kk_std_os_dir_prepend(_x1862, _x1863, _ctx); /*exception*/
  return kk_std_core__exception_box(_x1861, _ctx);
}

kk_unit_t kk_std_os_dir_copy_file(kk_std_os_path__path from, kk_std_os_path__path to, kk_std_core_types__optional preserve_mtime, kk_context_t* _ctx) { /* (from : std/os/path/path, to : std/os/path/path, preserve-mtime : optional<bool>) -> <exn,fsys> () */ 
  kk_std_core__error _match_1820;
  kk_string_t _x1;
  kk_box_t _x1827;
  kk_box_t _x1831;
  kk_std_os_path__path _x1832 = kk_std_os_path__path_dup(from); /*std/os/path/path*/
  _x1831 = kk_std_os_path__path_box(_x1832, _ctx); /*3238*/
  _x1827 = kk_std_core_hnd__open_none1(kk_std_os_dir_new_copy_file_fun1828(_ctx), _x1831, _ctx); /*3239*/
  _x1 = kk_string_unbox(_x1827); /*string*/
  kk_string_t _x2;
  kk_box_t _x1833;
  kk_box_t _x1837;
  kk_std_os_path__path _x1838 = kk_std_os_path__path_dup(to); /*std/os/path/path*/
  _x1837 = kk_std_os_path__path_box(_x1838, _ctx); /*3238*/
  _x1833 = kk_std_core_hnd__open_none1(kk_std_os_dir_new_copy_file_fun1834(_ctx), _x1837, _ctx); /*3239*/
  _x2 = kk_string_unbox(_x1833); /*string*/
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*std/core/hnd/evv<(<>)>*/;
  kk_std_core__error x;
  bool _x1839;
  if (kk_std_core_types__is_Optional(preserve_mtime)) {
    kk_box_t _box_x1483 = preserve_mtime._cons.Optional.value;
    bool _preserve_mtime_127 = kk_bool_unbox(_box_x1483);
    kk_std_core_types__optional_drop(preserve_mtime, _ctx);
    _x1839 = _preserve_mtime_127; /*bool*/
    goto _match1840;
  }
  _x1839 = true; /*bool*/
  _match1840: ;
  x = kk_std_os_dir_prim_copy_file(_x1, _x2, _x1839, _ctx); /*error<()>*/
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  _match_1820 = x; /*error<()>*/
  if (kk_std_core__is_Error(_match_1820)) {
    kk_std_core__exception exn = _match_1820._cons.Error.exception;
    kk_std_core__exception_dup(exn);
    kk_std_core__error_drop(_match_1820, _ctx);
    kk_std_core__error err_1416;
    kk_std_core__exception _x1842;
    kk_string_t _x20;
    kk_string_t _x1843;
    kk_define_string_literal(, _s1844, 15, "unable to copy ")
    _x1843 = kk_string_dup(_s1844); /*string*/
    kk_string_t _x1845;
    kk_string_t _x1846;
    kk_box_t _x1847 = kk_std_core_hnd__open_none1(kk_std_os_dir_new_copy_file_fun1848(_ctx), kk_std_os_path__path_box(from, _ctx), _ctx); /*3239*/
    _x1846 = kk_string_unbox(_x1847); /*string*/
    kk_string_t _x1851;
    kk_string_t _x1852;
    kk_define_string_literal(, _s1853, 4, " to ")
    _x1852 = kk_string_dup(_s1853); /*string*/
    kk_string_t _x1854;
    kk_box_t _x1855 = kk_std_core_hnd__open_none1(kk_std_os_dir_new_copy_file_fun1856(_ctx), kk_std_os_path__path_box(to, _ctx), _ctx); /*3239*/
    _x1854 = kk_string_unbox(_x1855); /*string*/
    _x1851 = kk_std_core__lp__plus__plus__1_rp_(_x1852, _x1854, _ctx); /*string*/
    _x1845 = kk_std_core__lp__plus__plus__1_rp_(_x1846, _x1851, _ctx); /*string*/
    _x20 = kk_std_core__lp__plus__plus__1_rp_(_x1843, _x1845, _ctx); /*string*/
    kk_box_t _x1859 = kk_std_core_hnd__open_none2(kk_std_os_dir_new_copy_file_fun1860(_ctx), kk_std_core__exception_box(exn, _ctx), kk_string_box(_x20), _ctx); /*3333*/
    _x1842 = kk_std_core__exception_unbox(_x1859, _ctx); /*exception*/
    err_1416 = kk_std_core__new_Error(_x1842, _ctx); /*error<()>*/
    if (kk_std_core__is_Error(err_1416)) {
      kk_std_core__exception exn0 = err_1416._cons.Error.exception;
      kk_std_core__exception_dup(exn0);
      kk_std_core__error_drop(err_1416, _ctx);
      kk_box_t _x1864 = kk_std_core_throw_exn(exn0, _ctx); /*11740*/
      kk_unit_unbox(_x1864); return kk_Unit;
    }
    kk_box_t _box_x1503 = err_1416._cons.Ok.result;
    kk_unit_t x0 = kk_unit_unbox(_box_x1503);
    kk_std_core__error_drop(err_1416, _ctx);
    x0; return kk_Unit;
  }
  kk_std_core__error_drop(_match_1820, _ctx);
  kk_std_os_path__path_drop(from, _ctx);
  kk_std_os_path__path_drop(to, _ctx);
  kk_Unit; return kk_Unit;
}
 
// Ensure a directory path exists


// lift anonymous function
struct kk_std_os_dir_ensure_dir_fun1867__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_dir_ensure_dir_fun1867(kk_function_t _fself, kk_box_t _b_1507, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir_new_ensure_dir_fun1867(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_dir_ensure_dir_fun1867, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_dir_ensure_dir_fun1867(kk_function_t _fself, kk_box_t _b_1507, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x1868;
  kk_std_os_path__path _x1869 = kk_std_os_path__path_unbox(_b_1507, _ctx); /*std/os/path/path*/
  _x1868 = kk_std_os_path_string(_x1869, _ctx); /*string*/
  return kk_string_box(_x1868);
}


// lift anonymous function
struct kk_std_os_dir_ensure_dir_fun1877__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_dir_ensure_dir_fun1877(kk_function_t _fself, kk_box_t _b_1512, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir_new_ensure_dir_fun1877(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_dir_ensure_dir_fun1877, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_dir_ensure_dir_fun1877(kk_function_t _fself, kk_box_t _b_1512, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x1878;
  kk_std_os_path__path _x1879 = kk_std_os_path__path_unbox(_b_1512, _ctx); /*std/os/path/path*/
  _x1878 = kk_std_os_path_show(_x1879, _ctx); /*string*/
  return kk_string_box(_x1878);
}


// lift anonymous function
struct kk_std_os_dir_ensure_dir_fun1881__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_dir_ensure_dir_fun1881(kk_function_t _fself, kk_box_t _b_1518, kk_box_t _b_1519, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir_new_ensure_dir_fun1881(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_dir_ensure_dir_fun1881, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_dir_ensure_dir_fun1881(kk_function_t _fself, kk_box_t _b_1518, kk_box_t _b_1519, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core__exception _x1882;
  kk_std_core__exception _x1883 = kk_std_core__exception_unbox(_b_1518, _ctx); /*exception*/
  kk_string_t _x1884 = kk_string_unbox(_b_1519); /*string*/
  _x1882 = kk_std_os_dir_prepend(_x1883, _x1884, _ctx); /*exception*/
  return kk_std_core__exception_box(_x1882, _ctx);
}

kk_unit_t kk_std_os_dir_ensure_dir(kk_std_os_path__path dir, kk_context_t* _ctx) { /* (dir : std/os/path/path) -> <exn,fsys> () */ 
  kk_std_core__error _match_1819;
  kk_string_t _x1;
  kk_box_t _x1866;
  kk_box_t _x1870;
  kk_std_os_path__path _x1871 = kk_std_os_path__path_dup(dir); /*std/os/path/path*/
  _x1870 = kk_std_os_path__path_box(_x1871, _ctx); /*3238*/
  _x1866 = kk_std_core_hnd__open_none1(kk_std_os_dir_new_ensure_dir_fun1867(_ctx), _x1870, _ctx); /*3239*/
  _x1 = kk_string_unbox(_x1866); /*string*/
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*std/core/hnd/evv<(<>)>*/;
  kk_std_core__error x = kk_std_os_dir_ensure_dir_err(_x1, kk_integer_from_small(-1), _ctx); /*error<()>*/;
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  _match_1819 = x; /*error<()>*/
  if (kk_std_core__is_Error(_match_1819)) {
    kk_std_core__exception exn = _match_1819._cons.Error.exception;
    kk_std_core__exception_dup(exn);
    kk_std_core__error_drop(_match_1819, _ctx);
    kk_std_core__error err_1420;
    kk_std_core__exception _x1872;
    kk_string_t _x20;
    kk_string_t _x1873;
    kk_define_string_literal(, _s1874, 27, "unable to create directory ")
    _x1873 = kk_string_dup(_s1874); /*string*/
    kk_string_t _x1875;
    kk_box_t _x1876 = kk_std_core_hnd__open_none1(kk_std_os_dir_new_ensure_dir_fun1877(_ctx), kk_std_os_path__path_box(dir, _ctx), _ctx); /*3239*/
    _x1875 = kk_string_unbox(_x1876); /*string*/
    _x20 = kk_std_core__lp__plus__plus__1_rp_(_x1873, _x1875, _ctx); /*string*/
    kk_box_t _x1880 = kk_std_core_hnd__open_none2(kk_std_os_dir_new_ensure_dir_fun1881(_ctx), kk_std_core__exception_box(exn, _ctx), kk_string_box(_x20), _ctx); /*3333*/
    _x1872 = kk_std_core__exception_unbox(_x1880, _ctx); /*exception*/
    err_1420 = kk_std_core__new_Error(_x1872, _ctx); /*error<()>*/
    if (kk_std_core__is_Error(err_1420)) {
      kk_std_core__exception exn0 = err_1420._cons.Error.exception;
      kk_std_core__exception_dup(exn0);
      kk_std_core__error_drop(err_1420, _ctx);
      kk_box_t _x1885 = kk_std_core_throw_exn(exn0, _ctx); /*11740*/
      kk_unit_unbox(_x1885); return kk_Unit;
    }
    kk_box_t _box_x1524 = err_1420._cons.Ok.result;
    kk_unit_t x0 = kk_unit_unbox(_box_x1524);
    kk_std_core__error_drop(err_1420, _ctx);
    x0; return kk_Unit;
  }
  kk_box_t _box_x1525 = _match_1819._cons.Ok.result;
  kk_unit_t _pat3 = kk_unit_unbox(_box_x1525);
  kk_std_core__error_drop(_match_1819, _ctx);
  kk_std_os_path__path_drop(dir, _ctx);
  kk_Unit; return kk_Unit;
}
 
// List directory contents (excluding `.` and `..`).
// Returns a list of full paths (not just the names in the directory).


// lift anonymous function
struct kk_std_os_dir_list_directory_fun1892__t {
  struct kk_function_s _base;
  kk_std_os_path__path dir;
};
static kk_box_t kk_std_os_dir_list_directory_fun1892(kk_function_t _fself, kk_box_t _b_1536, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir_new_list_directory_fun1892(kk_std_os_path__path dir, kk_context_t* _ctx) {
  struct kk_std_os_dir_list_directory_fun1892__t* _self = kk_function_alloc_as(struct kk_std_os_dir_list_directory_fun1892__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_os_dir_list_directory_fun1892, kk_context());
  _self->dir = dir;
  return &_self->_base;
}

static kk_box_t kk_std_os_dir_list_directory_fun1892(kk_function_t _fself, kk_box_t _b_1536, kk_context_t* _ctx) {
  struct kk_std_os_dir_list_directory_fun1892__t* _self = kk_function_as(struct kk_std_os_dir_list_directory_fun1892__t*, _fself);
  kk_std_os_path__path dir = _self->dir; /* std/os/path/path */
  kk_drop_match(_self, {kk_std_os_path__path_dup(dir);}, {}, _ctx)
  kk_std_os_path__path _x1893;
  kk_std_os_path__path p2_1422;
  kk_string_t _x1894 = kk_string_unbox(_b_1536); /*string*/
  p2_1422 = kk_std_os_path_path(_x1894, _ctx); /*std/os/path/path*/
  kk_std_core_types__optional root_2785;
  kk_box_t _x1895;
  kk_string_t _x1896;
  kk_string_t _x = dir.root;
  kk_string_dup(_x);
  _x1896 = _x; /*string*/
  _x1895 = kk_string_box(_x1896); /*108*/
  root_2785 = kk_std_core_types__new_Optional(_x1895, _ctx); /*optional<string>*/
  kk_std_core_types__optional parts_2786;
  kk_std_core__list _b_1531_1530;
  kk_std_core__list _x1897;
  kk_std_core__list _x1898;
  kk_std_core__list _x0 = p2_1422.parts;
  kk_std_core__list_dup(_x0);
  kk_std_os_path__path_drop(p2_1422, _ctx);
  _x1898 = _x0; /*list<string>*/
  _x1897 = kk_std_core__lift21047_reverse_append(kk_std_core__new_Nil(_ctx), _x1898, _ctx); /*list<2501>*/
  kk_std_core__list _x1899;
  kk_std_core__list _x1 = dir.parts;
  kk_std_core__list_dup(_x1);
  kk_std_os_path__path_drop(dir, _ctx);
  _x1899 = _x1; /*list<string>*/
  _b_1531_1530 = kk_std_os_path_push_parts(_x1897, _x1899, _ctx); /*list<string>*/
  parts_2786 = kk_std_core_types__new_Optional(kk_std_core__list_box(_b_1531_1530, _ctx), _ctx); /*optional<list<string>>*/
  kk_string_t _x1900;
  if (kk_std_core_types__is_Optional(root_2785)) {
    kk_box_t _box_x1532 = root_2785._cons.Optional.value;
    kk_string_t _root_1093 = kk_string_unbox(_box_x1532);
    kk_string_dup(_root_1093);
    kk_std_core_types__optional_drop(root_2785, _ctx);
    _x1900 = _root_1093; /*string*/
    goto _match1901;
  }
  _x1900 = kk_string_empty(); /*string*/
  _match1901: ;
  kk_std_core__list _x1904;
  if (kk_std_core_types__is_Optional(parts_2786)) {
    kk_box_t _box_x1533 = parts_2786._cons.Optional.value;
    kk_std_core__list _parts_1098 = kk_std_core__list_unbox(_box_x1533, NULL);
    kk_std_core__list_dup(_parts_1098);
    kk_std_core_types__optional_drop(parts_2786, _ctx);
    _x1904 = _parts_1098; /*list<string>*/
    goto _match1905;
  }
  _x1904 = kk_std_core__new_Nil(_ctx); /*list<string>*/
  _match1905: ;
  _x1893 = kk_std_os_path__new_Path(_x1900, _x1904, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x1893, _ctx);
}

kk_std_core__list kk_std_os_dir_list_directory(kk_std_os_path__path dir, kk_context_t* _ctx) { /* (dir : std/os/path/path) -> fsys list<std/os/path/path> */ 
  kk_std_core__error _match_1818;
  kk_string_t _x1889;
  kk_std_os_path__path _x1890 = kk_std_os_path__path_dup(dir); /*std/os/path/path*/
  _x1889 = kk_std_os_path_string(_x1890, _ctx); /*string*/
  _match_1818 = kk_std_os_dir_prim_list_dir(_x1889, _ctx); /*error<vector<string>>*/
  if (kk_std_core__is_Error(_match_1818)) {
    kk_std_core__exception _pat0 = _match_1818._cons.Error.exception;
    kk_std_core__error_drop(_match_1818, _ctx);
    kk_std_os_path__path_drop(dir, _ctx);
    return kk_std_core__new_Nil(_ctx);
  }
  kk_box_t _box_x1527 = _match_1818._cons.Ok.result;
  kk_vector_t contents = kk_vector_unbox(_box_x1527, NULL);
  kk_vector_dup(contents);
  kk_std_core__error_drop(_match_1818, _ctx);
  kk_std_core__list _b_1537_1534 = kk_std_core_list_5(contents, _ctx); /*list<string>*/;
  return kk_std_core_map_5(_b_1537_1534, kk_std_os_dir_new_list_directory_fun1892(dir, _ctx), _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_os_dir__mlift1407_copy_directory_fun1907__t {
  struct kk_function_s _base;
  kk_std_os_path__path to;
};
static kk_unit_t kk_std_os_dir__mlift1407_copy_directory_fun1907(kk_function_t _fself, kk_box_t _b_1552, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir__new_mlift1407_copy_directory_fun1907(kk_std_os_path__path to, kk_context_t* _ctx) {
  struct kk_std_os_dir__mlift1407_copy_directory_fun1907__t* _self = kk_function_alloc_as(struct kk_std_os_dir__mlift1407_copy_directory_fun1907__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_os_dir__mlift1407_copy_directory_fun1907, kk_context());
  _self->to = to;
  return &_self->_base;
}



// lift anonymous function
struct kk_std_os_dir__mlift1407_copy_directory_fun1912__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_dir__mlift1407_copy_directory_fun1912(kk_function_t _fself, kk_box_t _b_1542, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir__new_mlift1407_copy_directory_fun1912(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_dir__mlift1407_copy_directory_fun1912, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_dir__mlift1407_copy_directory_fun1912(kk_function_t _fself, kk_box_t _b_1542, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_os_path__path _x1913;
  kk_std_os_path__path _x1914 = kk_std_os_path__path_unbox(_b_1542, _ctx); /*std/os/path/path*/
  _x1913 = kk_std_os_path_nodir(_x1914, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x1913, _ctx);
}


// lift anonymous function
struct kk_std_os_dir__mlift1407_copy_directory_fun1916__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_dir__mlift1407_copy_directory_fun1916(kk_function_t _fself, kk_box_t _b_1548, kk_box_t _b_1549, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir__new_mlift1407_copy_directory_fun1916(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_dir__mlift1407_copy_directory_fun1916, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_dir__mlift1407_copy_directory_fun1916(kk_function_t _fself, kk_box_t _b_1548, kk_box_t _b_1549, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_os_path__path _x1917;
  kk_std_os_path__path _x1918 = kk_std_os_path__path_unbox(_b_1548, _ctx); /*std/os/path/path*/
  kk_std_os_path__path _x1919 = kk_std_os_path__path_unbox(_b_1549, _ctx); /*std/os/path/path*/
  _x1917 = kk_std_os_path__lp__fs__rp_(_x1918, _x1919, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x1917, _ctx);
}
static kk_unit_t kk_std_os_dir__mlift1407_copy_directory_fun1907(kk_function_t _fself, kk_box_t _b_1552, kk_context_t* _ctx) {
  struct kk_std_os_dir__mlift1407_copy_directory_fun1907__t* _self = kk_function_as(struct kk_std_os_dir__mlift1407_copy_directory_fun1907__t*, _fself);
  kk_std_os_path__path to = _self->to; /* std/os/path/path */
  kk_drop_match(_self, {kk_std_os_path__path_dup(to);}, {}, _ctx)
  kk_std_os_path__path _x1908;
  kk_box_t _x1909 = kk_box_dup(_b_1552); /*13452*/
  _x1908 = kk_std_os_path__path_unbox(_x1909, _ctx); /*std/os/path/path*/
  kk_std_os_path__path _x1910;
  kk_std_os_path__path _x20;
  kk_box_t _x1911 = kk_std_core_hnd__open_none1(kk_std_os_dir__new_mlift1407_copy_directory_fun1912(_ctx), _b_1552, _ctx); /*3239*/
  _x20 = kk_std_os_path__path_unbox(_x1911, _ctx); /*std/os/path/path*/
  kk_box_t _x1915 = kk_std_core_hnd__open_none2(kk_std_os_dir__new_mlift1407_copy_directory_fun1916(_ctx), kk_std_os_path__path_box(to, _ctx), kk_std_os_path__path_box(_x20, _ctx), _ctx); /*3333*/
  _x1910 = kk_std_os_path__path_unbox(_x1915, _ctx); /*std/os/path/path*/
  return kk_std_os_dir_copy_directory(_x1908, _x1910, _ctx);
}

kk_unit_t kk_std_os_dir__mlift1407_copy_directory(kk_std_core__list dirs, kk_std_os_path__path to, kk_unit_t wild__0, kk_context_t* _ctx) { /* (dirs : list<std/os/path/path>, to : std/os/path/path, wild_0 : ()) -> <exn,fsys,div> () */ 
  kk_std_core_foreach(dirs, kk_std_os_dir__new_mlift1407_copy_directory_fun1907(to, _ctx), _ctx); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_std_os_dir__mlift1408_copy_directory_fun1923__t {
  struct kk_function_s _base;
  kk_std_os_path__path to0;
};
static kk_unit_t kk_std_os_dir__mlift1408_copy_directory_fun1923(kk_function_t _fself, kk_box_t _b_1607, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir__new_mlift1408_copy_directory_fun1923(kk_std_os_path__path to0, kk_context_t* _ctx) {
  struct kk_std_os_dir__mlift1408_copy_directory_fun1923__t* _self = kk_function_alloc_as(struct kk_std_os_dir__mlift1408_copy_directory_fun1923__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_os_dir__mlift1408_copy_directory_fun1923, kk_context());
  _self->to0 = to0;
  return &_self->_base;
}



// lift anonymous function
struct kk_std_os_dir__mlift1408_copy_directory_fun1925__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_dir__mlift1408_copy_directory_fun1925(kk_function_t _fself, kk_box_t _b_1563, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir__new_mlift1408_copy_directory_fun1925(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_dir__mlift1408_copy_directory_fun1925, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_dir__mlift1408_copy_directory_fun1925(kk_function_t _fself, kk_box_t _b_1563, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_os_path__path _x1926;
  kk_std_os_path__path _x1927 = kk_std_os_path__path_unbox(_b_1563, _ctx); /*std/os/path/path*/
  _x1926 = kk_std_os_path_nodir(_x1927, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x1926, _ctx);
}


// lift anonymous function
struct kk_std_os_dir__mlift1408_copy_directory_fun1930__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_dir__mlift1408_copy_directory_fun1930(kk_function_t _fself, kk_box_t _b_1569, kk_box_t _b_1570, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir__new_mlift1408_copy_directory_fun1930(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_dir__mlift1408_copy_directory_fun1930, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_dir__mlift1408_copy_directory_fun1930(kk_function_t _fself, kk_box_t _b_1569, kk_box_t _b_1570, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_os_path__path _x1931;
  kk_std_os_path__path _x1932 = kk_std_os_path__path_unbox(_b_1569, _ctx); /*std/os/path/path*/
  kk_std_os_path__path _x1933 = kk_std_os_path__path_unbox(_b_1570, _ctx); /*std/os/path/path*/
  _x1931 = kk_std_os_path__lp__fs__rp_(_x1932, _x1933, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x1931, _ctx);
}


// lift anonymous function
struct kk_std_os_dir__mlift1408_copy_directory_fun1935__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_dir__mlift1408_copy_directory_fun1935(kk_function_t _fself, kk_box_t _b_1576, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir__new_mlift1408_copy_directory_fun1935(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_dir__mlift1408_copy_directory_fun1935, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_dir__mlift1408_copy_directory_fun1935(kk_function_t _fself, kk_box_t _b_1576, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x1936;
  kk_std_os_path__path _x1937 = kk_std_os_path__path_unbox(_b_1576, _ctx); /*std/os/path/path*/
  _x1936 = kk_std_os_path_string(_x1937, _ctx); /*string*/
  return kk_string_box(_x1936);
}


// lift anonymous function
struct kk_std_os_dir__mlift1408_copy_directory_fun1940__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_dir__mlift1408_copy_directory_fun1940(kk_function_t _fself, kk_box_t _b_1581, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir__new_mlift1408_copy_directory_fun1940(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_dir__mlift1408_copy_directory_fun1940, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_dir__mlift1408_copy_directory_fun1940(kk_function_t _fself, kk_box_t _b_1581, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x1941;
  kk_std_os_path__path _x1942 = kk_std_os_path__path_unbox(_b_1581, _ctx); /*std/os/path/path*/
  _x1941 = kk_std_os_path_string(_x1942, _ctx); /*string*/
  return kk_string_box(_x1941);
}


// lift anonymous function
struct kk_std_os_dir__mlift1408_copy_directory_fun1954__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_dir__mlift1408_copy_directory_fun1954(kk_function_t _fself, kk_box_t _b_1587, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir__new_mlift1408_copy_directory_fun1954(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_dir__mlift1408_copy_directory_fun1954, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_dir__mlift1408_copy_directory_fun1954(kk_function_t _fself, kk_box_t _b_1587, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x1955;
  kk_std_os_path__path _x1956 = kk_std_os_path__path_unbox(_b_1587, _ctx); /*std/os/path/path*/
  _x1955 = kk_std_os_path_show(_x1956, _ctx); /*string*/
  return kk_string_box(_x1955);
}


// lift anonymous function
struct kk_std_os_dir__mlift1408_copy_directory_fun1962__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_dir__mlift1408_copy_directory_fun1962(kk_function_t _fself, kk_box_t _b_1590, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir__new_mlift1408_copy_directory_fun1962(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_dir__mlift1408_copy_directory_fun1962, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_dir__mlift1408_copy_directory_fun1962(kk_function_t _fself, kk_box_t _b_1590, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x1963;
  kk_std_os_path__path _x1964 = kk_std_os_path__path_unbox(_b_1590, _ctx); /*std/os/path/path*/
  _x1963 = kk_std_os_path_show(_x1964, _ctx); /*string*/
  return kk_string_box(_x1963);
}


// lift anonymous function
struct kk_std_os_dir__mlift1408_copy_directory_fun1966__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_dir__mlift1408_copy_directory_fun1966(kk_function_t _fself, kk_box_t _b_1598, kk_box_t _b_1599, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir__new_mlift1408_copy_directory_fun1966(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_dir__mlift1408_copy_directory_fun1966, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_dir__mlift1408_copy_directory_fun1966(kk_function_t _fself, kk_box_t _b_1598, kk_box_t _b_1599, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core__exception _x1967;
  kk_std_core__exception _x1968 = kk_std_core__exception_unbox(_b_1598, _ctx); /*exception*/
  kk_string_t _x1969 = kk_string_unbox(_b_1599); /*string*/
  _x1967 = kk_std_os_dir_prepend(_x1968, _x1969, _ctx); /*exception*/
  return kk_std_core__exception_box(_x1967, _ctx);
}
static kk_unit_t kk_std_os_dir__mlift1408_copy_directory_fun1923(kk_function_t _fself, kk_box_t _b_1607, kk_context_t* _ctx) {
  struct kk_std_os_dir__mlift1408_copy_directory_fun1923__t* _self = kk_function_as(struct kk_std_os_dir__mlift1408_copy_directory_fun1923__t*, _fself);
  kk_std_os_path__path to0 = _self->to0; /* std/os/path/path */
  kk_drop_match(_self, {kk_std_os_path__path_dup(to0);}, {}, _ctx)
  kk_std_os_path__path to0_1426;
  kk_std_os_path__path _x21;
  kk_box_t _x1924;
  kk_box_t _x1928 = kk_box_dup(_b_1607); /*13452*/
  _x1924 = kk_std_core_hnd__open_none1(kk_std_os_dir__new_mlift1408_copy_directory_fun1925(_ctx), _x1928, _ctx); /*3239*/
  _x21 = kk_std_os_path__path_unbox(_x1924, _ctx); /*std/os/path/path*/
  kk_box_t _x1929 = kk_std_core_hnd__open_none2(kk_std_os_dir__new_mlift1408_copy_directory_fun1930(_ctx), kk_std_os_path__path_box(to0, _ctx), kk_std_os_path__path_box(_x21, _ctx), _ctx); /*3333*/
  to0_1426 = kk_std_os_path__path_unbox(_x1929, _ctx); /*std/os/path/path*/
  kk_std_core__error _match_1816;
  kk_string_t _x1;
  kk_box_t _x1934;
  kk_box_t _x1938 = kk_box_dup(_b_1607); /*13452*/
  _x1934 = kk_std_core_hnd__open_none1(kk_std_os_dir__new_mlift1408_copy_directory_fun1935(_ctx), _x1938, _ctx); /*3239*/
  _x1 = kk_string_unbox(_x1934); /*string*/
  kk_string_t _x2;
  kk_box_t _x1939;
  kk_box_t _x1943;
  kk_std_os_path__path _x1944 = kk_std_os_path__path_dup(to0_1426); /*std/os/path/path*/
  _x1943 = kk_std_os_path__path_box(_x1944, _ctx); /*3238*/
  _x1939 = kk_std_core_hnd__open_none1(kk_std_os_dir__new_mlift1408_copy_directory_fun1940(_ctx), _x1943, _ctx); /*3239*/
  _x2 = kk_string_unbox(_x1939); /*string*/
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*std/core/hnd/evv<(<>)>*/;
  kk_std_core__error x0;
  bool _x1945;
  kk_std_core_types__optional _match_1817 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
  if (kk_std_core_types__is_Optional(_match_1817)) {
    kk_box_t _box_x1584 = _match_1817._cons.Optional.value;
    bool _preserve_mtime_127 = kk_bool_unbox(_box_x1584);
    kk_std_core_types__optional_drop(_match_1817, _ctx);
    _x1945 = _preserve_mtime_127; /*bool*/
    goto _match1946;
  }
  _x1945 = true; /*bool*/
  _match1946: ;
  x0 = kk_std_os_dir_prim_copy_file(_x1, _x2, _x1945, _ctx); /*error<()>*/
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  _match_1816 = x0; /*error<()>*/
  if (kk_std_core__is_Error(_match_1816)) {
    kk_std_core__exception exn = _match_1816._cons.Error.exception;
    kk_std_core__exception_dup(exn);
    kk_std_core__error_drop(_match_1816, _ctx);
    kk_std_core__error err_1432;
    kk_std_core__exception _x1948;
    kk_string_t _x200;
    kk_string_t _x1949;
    kk_define_string_literal(, _s1950, 15, "unable to copy ")
    _x1949 = kk_string_dup(_s1950); /*string*/
    kk_string_t _x1951;
    kk_string_t _x1952;
    kk_box_t _x1953 = kk_std_core_hnd__open_none1(kk_std_os_dir__new_mlift1408_copy_directory_fun1954(_ctx), _b_1607, _ctx); /*3239*/
    _x1952 = kk_string_unbox(_x1953); /*string*/
    kk_string_t _x1957;
    kk_string_t _x1958;
    kk_define_string_literal(, _s1959, 4, " to ")
    _x1958 = kk_string_dup(_s1959); /*string*/
    kk_string_t _x1960;
    kk_box_t _x1961 = kk_std_core_hnd__open_none1(kk_std_os_dir__new_mlift1408_copy_directory_fun1962(_ctx), kk_std_os_path__path_box(to0_1426, _ctx), _ctx); /*3239*/
    _x1960 = kk_string_unbox(_x1961); /*string*/
    _x1957 = kk_std_core__lp__plus__plus__1_rp_(_x1958, _x1960, _ctx); /*string*/
    _x1951 = kk_std_core__lp__plus__plus__1_rp_(_x1952, _x1957, _ctx); /*string*/
    _x200 = kk_std_core__lp__plus__plus__1_rp_(_x1949, _x1951, _ctx); /*string*/
    kk_box_t _x1965 = kk_std_core_hnd__open_none2(kk_std_os_dir__new_mlift1408_copy_directory_fun1966(_ctx), kk_std_core__exception_box(exn, _ctx), kk_string_box(_x200), _ctx); /*3333*/
    _x1948 = kk_std_core__exception_unbox(_x1965, _ctx); /*exception*/
    err_1432 = kk_std_core__new_Error(_x1948, _ctx); /*error<()>*/
    if (kk_std_core__is_Error(err_1432)) {
      kk_std_core__exception exn0 = err_1432._cons.Error.exception;
      kk_std_core__exception_dup(exn0);
      kk_std_core__error_drop(err_1432, _ctx);
      kk_box_t _x1970 = kk_std_core_throw_exn(exn0, _ctx); /*11740*/
      return kk_unit_unbox(_x1970);
    }
    kk_box_t _box_x1604 = err_1432._cons.Ok.result;
    kk_unit_t x4 = kk_unit_unbox(_box_x1604);
    kk_std_core__error_drop(err_1432, _ctx);
    return x4;
  }
  kk_box_drop(_b_1607, _ctx);
  kk_std_core__error_drop(_match_1816, _ctx);
  kk_std_os_path__path_drop(to0_1426, _ctx);
  return kk_Unit;
}


// lift anonymous function
struct kk_std_os_dir__mlift1408_copy_directory_fun1973__t {
  struct kk_function_s _base;
  kk_std_core__list dirs0;
  kk_std_os_path__path to0;
};
static kk_box_t kk_std_os_dir__mlift1408_copy_directory_fun1973(kk_function_t _fself, kk_box_t _b_1613, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir__new_mlift1408_copy_directory_fun1973(kk_std_core__list dirs0, kk_std_os_path__path to0, kk_context_t* _ctx) {
  struct kk_std_os_dir__mlift1408_copy_directory_fun1973__t* _self = kk_function_alloc_as(struct kk_std_os_dir__mlift1408_copy_directory_fun1973__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_os_dir__mlift1408_copy_directory_fun1973, kk_context());
  _self->dirs0 = dirs0;
  _self->to0 = to0;
  return &_self->_base;
}

static kk_box_t kk_std_os_dir__mlift1408_copy_directory_fun1973(kk_function_t _fself, kk_box_t _b_1613, kk_context_t* _ctx) {
  struct kk_std_os_dir__mlift1408_copy_directory_fun1973__t* _self = kk_function_as(struct kk_std_os_dir__mlift1408_copy_directory_fun1973__t*, _fself);
  kk_std_core__list dirs0 = _self->dirs0; /* list<std/os/path/path> */
  kk_std_os_path__path to0 = _self->to0; /* std/os/path/path */
  kk_drop_match(_self, {kk_std_core__list_dup(dirs0);kk_std_os_path__path_dup(to0);}, {}, _ctx)
  kk_unit_t _x1974 = kk_Unit;
  kk_unit_t _x1975 = kk_Unit;
  kk_unit_unbox(_b_1613);
  kk_std_os_dir__mlift1407_copy_directory(dirs0, to0, _x1975, _ctx);
  return kk_unit_box(_x1974);
}

kk_unit_t kk_std_os_dir__mlift1408_copy_directory(kk_std_os_path__path to0, kk_std_core_types__tuple2_ _y_5, kk_context_t* _ctx) { /* (to : std/os/path/path, (list<std/os/path/path>, list<std/os/path/path>)) -> <fsys,div,exn> () */ 
  kk_box_t _box_x1559 = _y_5.fst;
  kk_box_t _box_x1560 = _y_5.snd;
  kk_std_core__list dirs0 = kk_std_core__list_unbox(_box_x1559, NULL);
  kk_std_core__list files = kk_std_core__list_unbox(_box_x1560, NULL);
  kk_std_core__list_dup(dirs0);
  kk_std_core__list_dup(files);
  kk_std_core_types__tuple2__drop(_y_5, _ctx);
  kk_unit_t x_1423 = kk_Unit;
  kk_function_t _x1922;
  kk_std_os_path__path_dup(to0);
  _x1922 = kk_std_os_dir__new_mlift1408_copy_directory_fun1923(to0, _ctx); /*(13452) -> 13453 ()*/
  kk_std_core_foreach(files, _x1922, _ctx);
  if (kk_yielding(kk_context())) {
    kk_box_t _x1972 = kk_std_core_hnd_yield_extend(kk_std_os_dir__new_mlift1408_copy_directory_fun1973(dirs0, to0, _ctx), _ctx); /*3991*/
    kk_unit_unbox(_x1972); return kk_Unit;
  }
  kk_std_os_dir__mlift1407_copy_directory(dirs0, to0, x_1423, _ctx); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_std_os_dir__mlift1409_copy_directory_fun1977__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_dir__mlift1409_copy_directory_fun1977(kk_function_t _fself, kk_box_t _b_1618, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir__new_mlift1409_copy_directory_fun1977(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_dir__mlift1409_copy_directory_fun1977, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_dir__mlift1409_copy_directory_fun1977(kk_function_t _fself, kk_box_t _b_1618, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core__list _x1978;
  kk_std_os_path__path _x1979 = kk_std_os_path__path_unbox(_b_1618, _ctx); /*std/os/path/path*/
  _x1978 = kk_std_os_dir_list_directory(_x1979, _ctx); /*list<std/os/path/path>*/
  return kk_std_core__list_box(_x1978, _ctx);
}


// lift anonymous function
struct kk_std_os_dir__mlift1409_copy_directory_fun1980__t {
  struct kk_function_s _base;
};
static bool kk_std_os_dir__mlift1409_copy_directory_fun1980(kk_function_t _fself, kk_box_t _b_1628, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir__new_mlift1409_copy_directory_fun1980(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_dir__mlift1409_copy_directory_fun1980, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_std_os_dir__mlift1409_copy_directory_fun1982__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_dir__mlift1409_copy_directory_fun1982(kk_function_t _fself, kk_box_t _b_1623, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir__new_mlift1409_copy_directory_fun1982(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_dir__mlift1409_copy_directory_fun1982, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_dir__mlift1409_copy_directory_fun1982(kk_function_t _fself, kk_box_t _b_1623, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  bool _x1983;
  kk_std_os_path__path _x1984 = kk_std_os_path__path_unbox(_b_1623, _ctx); /*std/os/path/path*/
  _x1983 = kk_std_os_dir_is_directory(_x1984, _ctx); /*bool*/
  return kk_bool_box(_x1983);
}
static bool kk_std_os_dir__mlift1409_copy_directory_fun1980(kk_function_t _fself, kk_box_t _b_1628, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_box_t _x1981 = kk_std_core_hnd__open_none1(kk_std_os_dir__new_mlift1409_copy_directory_fun1982(_ctx), _b_1628, _ctx); /*3239*/
  return kk_bool_unbox(_x1981);
}


// lift anonymous function
struct kk_std_os_dir__mlift1409_copy_directory_fun1986__t {
  struct kk_function_s _base;
  kk_std_os_path__path to1;
};
static kk_box_t kk_std_os_dir__mlift1409_copy_directory_fun1986(kk_function_t _fself, kk_box_t _b_1637, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir__new_mlift1409_copy_directory_fun1986(kk_std_os_path__path to1, kk_context_t* _ctx) {
  struct kk_std_os_dir__mlift1409_copy_directory_fun1986__t* _self = kk_function_alloc_as(struct kk_std_os_dir__mlift1409_copy_directory_fun1986__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_os_dir__mlift1409_copy_directory_fun1986, kk_context());
  _self->to1 = to1;
  return &_self->_base;
}

static kk_box_t kk_std_os_dir__mlift1409_copy_directory_fun1986(kk_function_t _fself, kk_box_t _b_1637, kk_context_t* _ctx) {
  struct kk_std_os_dir__mlift1409_copy_directory_fun1986__t* _self = kk_function_as(struct kk_std_os_dir__mlift1409_copy_directory_fun1986__t*, _fself);
  kk_std_os_path__path to1 = _self->to1; /* std/os/path/path */
  kk_drop_match(_self, {kk_std_os_path__path_dup(to1);}, {}, _ctx)
  kk_unit_t _x1987 = kk_Unit;
  kk_std_core_types__tuple2_ _x1988 = kk_std_core_types__tuple2__unbox(_b_1637, _ctx); /*(list<std/os/path/path>, list<std/os/path/path>)*/
  kk_std_os_dir__mlift1408_copy_directory(to1, _x1988, _ctx);
  return kk_unit_box(_x1987);
}

kk_unit_t kk_std_os_dir__mlift1409_copy_directory(kk_std_os_path__path dir, kk_std_os_path__path to1, kk_unit_t wild__, kk_context_t* _ctx) { /* (dir : std/os/path/path, to : std/os/path/path, wild_ : ()) -> <exn,fsys> () */ 
  kk_std_core__list all;
  kk_box_t _x1976 = kk_std_core_hnd__open_none1(kk_std_os_dir__new_mlift1409_copy_directory_fun1977(_ctx), kk_std_os_path__path_box(dir, _ctx), _ctx); /*3239*/
  all = kk_std_core__list_unbox(_x1976, _ctx); /*list<std/os/path/path>*/
  kk_std_core_types__tuple2_ x_1433 = kk_std_core_partition_acc(all, kk_std_os_dir__new_mlift1409_copy_directory_fun1980(_ctx), kk_std_core__new_Nil(_ctx), kk_std_core__new_Nil(_ctx), _ctx); /*(list<std/os/path/path>, list<std/os/path/path>)*/;
  if (kk_yielding(kk_context())) {
    kk_std_core_types__tuple2__drop(x_1433, _ctx);
    kk_box_t _x1985 = kk_std_core_hnd_yield_extend(kk_std_os_dir__new_mlift1409_copy_directory_fun1986(to1, _ctx), _ctx); /*3991*/
    kk_unit_unbox(_x1985); return kk_Unit;
  }
  kk_std_os_dir__mlift1408_copy_directory(to1, x_1433, _ctx); return kk_Unit;
}


// lift anonymous function
struct kk_std_os_dir_copy_directory_fun1991__t {
  struct kk_function_s _base;
  kk_std_os_path__path dir0;
  kk_std_os_path__path to2;
};
static kk_box_t kk_std_os_dir_copy_directory_fun1991(kk_function_t _fself, kk_box_t _b_1641, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir_new_copy_directory_fun1991(kk_std_os_path__path dir0, kk_std_os_path__path to2, kk_context_t* _ctx) {
  struct kk_std_os_dir_copy_directory_fun1991__t* _self = kk_function_alloc_as(struct kk_std_os_dir_copy_directory_fun1991__t, 5, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_os_dir_copy_directory_fun1991, kk_context());
  _self->dir0 = dir0;
  _self->to2 = to2;
  return &_self->_base;
}

static kk_box_t kk_std_os_dir_copy_directory_fun1991(kk_function_t _fself, kk_box_t _b_1641, kk_context_t* _ctx) {
  struct kk_std_os_dir_copy_directory_fun1991__t* _self = kk_function_as(struct kk_std_os_dir_copy_directory_fun1991__t*, _fself);
  kk_std_os_path__path dir0 = _self->dir0; /* std/os/path/path */
  kk_std_os_path__path to2 = _self->to2; /* std/os/path/path */
  kk_drop_match(_self, {kk_std_os_path__path_dup(dir0);kk_std_os_path__path_dup(to2);}, {}, _ctx)
  kk_unit_t _x1992 = kk_Unit;
  kk_unit_t _x1993 = kk_Unit;
  kk_unit_unbox(_b_1641);
  kk_std_os_dir__mlift1409_copy_directory(dir0, to2, _x1993, _ctx);
  return kk_unit_box(_x1992);
}


// lift anonymous function
struct kk_std_os_dir_copy_directory_fun1995__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_dir_copy_directory_fun1995(kk_function_t _fself, kk_box_t _b_1644, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir_new_copy_directory_fun1995(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_dir_copy_directory_fun1995, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_dir_copy_directory_fun1995(kk_function_t _fself, kk_box_t _b_1644, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core__list _x1996;
  kk_std_os_path__path _x1997 = kk_std_os_path__path_unbox(_b_1644, _ctx); /*std/os/path/path*/
  _x1996 = kk_std_os_dir_list_directory(_x1997, _ctx); /*list<std/os/path/path>*/
  return kk_std_core__list_box(_x1996, _ctx);
}


// lift anonymous function
struct kk_std_os_dir_copy_directory_fun1998__t {
  struct kk_function_s _base;
};
static bool kk_std_os_dir_copy_directory_fun1998(kk_function_t _fself, kk_box_t _b_1654, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir_new_copy_directory_fun1998(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_dir_copy_directory_fun1998, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_std_os_dir_copy_directory_fun2000__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_dir_copy_directory_fun2000(kk_function_t _fself, kk_box_t _b_1649, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir_new_copy_directory_fun2000(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_dir_copy_directory_fun2000, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_dir_copy_directory_fun2000(kk_function_t _fself, kk_box_t _b_1649, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  bool _x2001;
  kk_std_os_path__path _x2002 = kk_std_os_path__path_unbox(_b_1649, _ctx); /*std/os/path/path*/
  _x2001 = kk_std_os_dir_is_directory(_x2002, _ctx); /*bool*/
  return kk_bool_box(_x2001);
}
static bool kk_std_os_dir_copy_directory_fun1998(kk_function_t _fself, kk_box_t _b_1654, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_box_t _x1999 = kk_std_core_hnd__open_none1(kk_std_os_dir_new_copy_directory_fun2000(_ctx), _b_1654, _ctx); /*3239*/
  return kk_bool_unbox(_x1999);
}


// lift anonymous function
struct kk_std_os_dir_copy_directory_fun2004__t {
  struct kk_function_s _base;
  kk_std_os_path__path to2;
};
static kk_box_t kk_std_os_dir_copy_directory_fun2004(kk_function_t _fself, kk_box_t _b_1663, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir_new_copy_directory_fun2004(kk_std_os_path__path to2, kk_context_t* _ctx) {
  struct kk_std_os_dir_copy_directory_fun2004__t* _self = kk_function_alloc_as(struct kk_std_os_dir_copy_directory_fun2004__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_os_dir_copy_directory_fun2004, kk_context());
  _self->to2 = to2;
  return &_self->_base;
}

static kk_box_t kk_std_os_dir_copy_directory_fun2004(kk_function_t _fself, kk_box_t _b_1663, kk_context_t* _ctx) {
  struct kk_std_os_dir_copy_directory_fun2004__t* _self = kk_function_as(struct kk_std_os_dir_copy_directory_fun2004__t*, _fself);
  kk_std_os_path__path to2 = _self->to2; /* std/os/path/path */
  kk_drop_match(_self, {kk_std_os_path__path_dup(to2);}, {}, _ctx)
  kk_unit_t _x2005 = kk_Unit;
  kk_std_core_types__tuple2_ _x2006 = kk_std_core_types__tuple2__unbox(_b_1663, _ctx); /*(list<std/os/path/path>, list<std/os/path/path>)*/
  kk_std_os_dir__mlift1408_copy_directory(to2, _x2006, _ctx);
  return kk_unit_box(_x2005);
}


// lift anonymous function
struct kk_std_os_dir_copy_directory_fun2010__t {
  struct kk_function_s _base;
  kk_std_os_path__path to2;
};
static kk_unit_t kk_std_os_dir_copy_directory_fun2010(kk_function_t _fself, kk_box_t _b_1712, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir_new_copy_directory_fun2010(kk_std_os_path__path to2, kk_context_t* _ctx) {
  struct kk_std_os_dir_copy_directory_fun2010__t* _self = kk_function_alloc_as(struct kk_std_os_dir_copy_directory_fun2010__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_os_dir_copy_directory_fun2010, kk_context());
  _self->to2 = to2;
  return &_self->_base;
}



// lift anonymous function
struct kk_std_os_dir_copy_directory_fun2012__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_dir_copy_directory_fun2012(kk_function_t _fself, kk_box_t _b_1668, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir_new_copy_directory_fun2012(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_dir_copy_directory_fun2012, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_dir_copy_directory_fun2012(kk_function_t _fself, kk_box_t _b_1668, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_os_path__path _x2013;
  kk_std_os_path__path _x2014 = kk_std_os_path__path_unbox(_b_1668, _ctx); /*std/os/path/path*/
  _x2013 = kk_std_os_path_nodir(_x2014, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x2013, _ctx);
}


// lift anonymous function
struct kk_std_os_dir_copy_directory_fun2017__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_dir_copy_directory_fun2017(kk_function_t _fself, kk_box_t _b_1674, kk_box_t _b_1675, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir_new_copy_directory_fun2017(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_dir_copy_directory_fun2017, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_dir_copy_directory_fun2017(kk_function_t _fself, kk_box_t _b_1674, kk_box_t _b_1675, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_os_path__path _x2018;
  kk_std_os_path__path _x2019 = kk_std_os_path__path_unbox(_b_1674, _ctx); /*std/os/path/path*/
  kk_std_os_path__path _x2020 = kk_std_os_path__path_unbox(_b_1675, _ctx); /*std/os/path/path*/
  _x2018 = kk_std_os_path__lp__fs__rp_(_x2019, _x2020, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x2018, _ctx);
}


// lift anonymous function
struct kk_std_os_dir_copy_directory_fun2022__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_dir_copy_directory_fun2022(kk_function_t _fself, kk_box_t _b_1681, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir_new_copy_directory_fun2022(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_dir_copy_directory_fun2022, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_dir_copy_directory_fun2022(kk_function_t _fself, kk_box_t _b_1681, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x2023;
  kk_std_os_path__path _x2024 = kk_std_os_path__path_unbox(_b_1681, _ctx); /*std/os/path/path*/
  _x2023 = kk_std_os_path_string(_x2024, _ctx); /*string*/
  return kk_string_box(_x2023);
}


// lift anonymous function
struct kk_std_os_dir_copy_directory_fun2027__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_dir_copy_directory_fun2027(kk_function_t _fself, kk_box_t _b_1686, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir_new_copy_directory_fun2027(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_dir_copy_directory_fun2027, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_dir_copy_directory_fun2027(kk_function_t _fself, kk_box_t _b_1686, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x2028;
  kk_std_os_path__path _x2029 = kk_std_os_path__path_unbox(_b_1686, _ctx); /*std/os/path/path*/
  _x2028 = kk_std_os_path_string(_x2029, _ctx); /*string*/
  return kk_string_box(_x2028);
}


// lift anonymous function
struct kk_std_os_dir_copy_directory_fun2041__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_dir_copy_directory_fun2041(kk_function_t _fself, kk_box_t _b_1692, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir_new_copy_directory_fun2041(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_dir_copy_directory_fun2041, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_dir_copy_directory_fun2041(kk_function_t _fself, kk_box_t _b_1692, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x2042;
  kk_std_os_path__path _x2043 = kk_std_os_path__path_unbox(_b_1692, _ctx); /*std/os/path/path*/
  _x2042 = kk_std_os_path_show(_x2043, _ctx); /*string*/
  return kk_string_box(_x2042);
}


// lift anonymous function
struct kk_std_os_dir_copy_directory_fun2049__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_dir_copy_directory_fun2049(kk_function_t _fself, kk_box_t _b_1695, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir_new_copy_directory_fun2049(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_dir_copy_directory_fun2049, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_dir_copy_directory_fun2049(kk_function_t _fself, kk_box_t _b_1695, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x2050;
  kk_std_os_path__path _x2051 = kk_std_os_path__path_unbox(_b_1695, _ctx); /*std/os/path/path*/
  _x2050 = kk_std_os_path_show(_x2051, _ctx); /*string*/
  return kk_string_box(_x2050);
}


// lift anonymous function
struct kk_std_os_dir_copy_directory_fun2053__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_dir_copy_directory_fun2053(kk_function_t _fself, kk_box_t _b_1703, kk_box_t _b_1704, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir_new_copy_directory_fun2053(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_dir_copy_directory_fun2053, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_dir_copy_directory_fun2053(kk_function_t _fself, kk_box_t _b_1703, kk_box_t _b_1704, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core__exception _x2054;
  kk_std_core__exception _x2055 = kk_std_core__exception_unbox(_b_1703, _ctx); /*exception*/
  kk_string_t _x2056 = kk_string_unbox(_b_1704); /*string*/
  _x2054 = kk_std_os_dir_prepend(_x2055, _x2056, _ctx); /*exception*/
  return kk_std_core__exception_box(_x2054, _ctx);
}
static kk_unit_t kk_std_os_dir_copy_directory_fun2010(kk_function_t _fself, kk_box_t _b_1712, kk_context_t* _ctx) {
  struct kk_std_os_dir_copy_directory_fun2010__t* _self = kk_function_as(struct kk_std_os_dir_copy_directory_fun2010__t*, _fself);
  kk_std_os_path__path to2 = _self->to2; /* std/os/path/path */
  kk_drop_match(_self, {kk_std_os_path__path_dup(to2);}, {}, _ctx)
  kk_std_os_path__path to0_1451;
  kk_std_os_path__path _x210;
  kk_box_t _x2011;
  kk_box_t _x2015 = kk_box_dup(_b_1712); /*13452*/
  _x2011 = kk_std_core_hnd__open_none1(kk_std_os_dir_new_copy_directory_fun2012(_ctx), _x2015, _ctx); /*3239*/
  _x210 = kk_std_os_path__path_unbox(_x2011, _ctx); /*std/os/path/path*/
  kk_box_t _x2016 = kk_std_core_hnd__open_none2(kk_std_os_dir_new_copy_directory_fun2017(_ctx), kk_std_os_path__path_box(to2, _ctx), kk_std_os_path__path_box(_x210, _ctx), _ctx); /*3333*/
  to0_1451 = kk_std_os_path__path_unbox(_x2016, _ctx); /*std/os/path/path*/
  kk_std_core__error _match_1812;
  kk_string_t _x11;
  kk_box_t _x2021;
  kk_box_t _x2025 = kk_box_dup(_b_1712); /*13452*/
  _x2021 = kk_std_core_hnd__open_none1(kk_std_os_dir_new_copy_directory_fun2022(_ctx), _x2025, _ctx); /*3239*/
  _x11 = kk_string_unbox(_x2021); /*string*/
  kk_string_t _x22;
  kk_box_t _x2026;
  kk_box_t _x2030;
  kk_std_os_path__path _x2031 = kk_std_os_path__path_dup(to0_1451); /*std/os/path/path*/
  _x2030 = kk_std_os_path__path_box(_x2031, _ctx); /*3238*/
  _x2026 = kk_std_core_hnd__open_none1(kk_std_os_dir_new_copy_directory_fun2027(_ctx), _x2030, _ctx); /*3239*/
  _x22 = kk_string_unbox(_x2026); /*string*/
  kk_evv_t w0 = kk_evv_swap_create0(kk_context()); /*std/core/hnd/evv<(<>)>*/;
  kk_std_core__error x40;
  bool _x2032;
  kk_std_core_types__optional _match_1813 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
  if (kk_std_core_types__is_Optional(_match_1813)) {
    kk_box_t _box_x1689 = _match_1813._cons.Optional.value;
    bool _preserve_mtime_1270 = kk_bool_unbox(_box_x1689);
    kk_std_core_types__optional_drop(_match_1813, _ctx);
    _x2032 = _preserve_mtime_1270; /*bool*/
    goto _match2033;
  }
  _x2032 = true; /*bool*/
  _match2033: ;
  x40 = kk_std_os_dir_prim_copy_file(_x11, _x22, _x2032, _ctx); /*error<()>*/
  kk_unit_t keep0 = kk_Unit;
  kk_evv_set(w0,kk_context());
  _match_1812 = x40; /*error<()>*/
  if (kk_std_core__is_Error(_match_1812)) {
    kk_std_core__exception exn1 = _match_1812._cons.Error.exception;
    kk_std_core__exception_dup(exn1);
    kk_std_core__error_drop(_match_1812, _ctx);
    kk_std_core__error err_1457;
    kk_std_core__exception _x2035;
    kk_string_t _x201;
    kk_string_t _x2036;
    kk_define_string_literal(, _s2037, 15, "unable to copy ")
    _x2036 = kk_string_dup(_s2037); /*string*/
    kk_string_t _x2038;
    kk_string_t _x2039;
    kk_box_t _x2040 = kk_std_core_hnd__open_none1(kk_std_os_dir_new_copy_directory_fun2041(_ctx), _b_1712, _ctx); /*3239*/
    _x2039 = kk_string_unbox(_x2040); /*string*/
    kk_string_t _x2044;
    kk_string_t _x2045;
    kk_define_string_literal(, _s2046, 4, " to ")
    _x2045 = kk_string_dup(_s2046); /*string*/
    kk_string_t _x2047;
    kk_box_t _x2048 = kk_std_core_hnd__open_none1(kk_std_os_dir_new_copy_directory_fun2049(_ctx), kk_std_os_path__path_box(to0_1451, _ctx), _ctx); /*3239*/
    _x2047 = kk_string_unbox(_x2048); /*string*/
    _x2044 = kk_std_core__lp__plus__plus__1_rp_(_x2045, _x2047, _ctx); /*string*/
    _x2038 = kk_std_core__lp__plus__plus__1_rp_(_x2039, _x2044, _ctx); /*string*/
    _x201 = kk_std_core__lp__plus__plus__1_rp_(_x2036, _x2038, _ctx); /*string*/
    kk_box_t _x2052 = kk_std_core_hnd__open_none2(kk_std_os_dir_new_copy_directory_fun2053(_ctx), kk_std_core__exception_box(exn1, _ctx), kk_string_box(_x201), _ctx); /*3333*/
    _x2035 = kk_std_core__exception_unbox(_x2052, _ctx); /*exception*/
    err_1457 = kk_std_core__new_Error(_x2035, _ctx); /*error<()>*/
    if (kk_std_core__is_Error(err_1457)) {
      kk_std_core__exception exn00 = err_1457._cons.Error.exception;
      kk_std_core__exception_dup(exn00);
      kk_std_core__error_drop(err_1457, _ctx);
      kk_box_t _x2057 = kk_std_core_throw_exn(exn00, _ctx); /*11740*/
      return kk_unit_unbox(_x2057);
    }
    kk_box_t _box_x1709 = err_1457._cons.Ok.result;
    kk_unit_t x5 = kk_unit_unbox(_box_x1709);
    kk_std_core__error_drop(err_1457, _ctx);
    return x5;
  }
  kk_box_drop(_b_1712, _ctx);
  kk_std_core__error_drop(_match_1812, _ctx);
  kk_std_os_path__path_drop(to0_1451, _ctx);
  return kk_Unit;
}


// lift anonymous function
struct kk_std_os_dir_copy_directory_fun2060__t {
  struct kk_function_s _base;
  kk_std_core__list dirs1;
  kk_std_os_path__path to2;
};
static kk_box_t kk_std_os_dir_copy_directory_fun2060(kk_function_t _fself, kk_box_t _b_1718, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir_new_copy_directory_fun2060(kk_std_core__list dirs1, kk_std_os_path__path to2, kk_context_t* _ctx) {
  struct kk_std_os_dir_copy_directory_fun2060__t* _self = kk_function_alloc_as(struct kk_std_os_dir_copy_directory_fun2060__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_os_dir_copy_directory_fun2060, kk_context());
  _self->dirs1 = dirs1;
  _self->to2 = to2;
  return &_self->_base;
}

static kk_box_t kk_std_os_dir_copy_directory_fun2060(kk_function_t _fself, kk_box_t _b_1718, kk_context_t* _ctx) {
  struct kk_std_os_dir_copy_directory_fun2060__t* _self = kk_function_as(struct kk_std_os_dir_copy_directory_fun2060__t*, _fself);
  kk_std_core__list dirs1 = _self->dirs1; /* list<std/os/path/path> */
  kk_std_os_path__path to2 = _self->to2; /* std/os/path/path */
  kk_drop_match(_self, {kk_std_core__list_dup(dirs1);kk_std_os_path__path_dup(to2);}, {}, _ctx)
  kk_unit_t _x2061 = kk_Unit;
  kk_unit_t _x2062 = kk_Unit;
  kk_unit_unbox(_b_1718);
  kk_std_os_dir__mlift1407_copy_directory(dirs1, to2, _x2062, _ctx);
  return kk_unit_box(_x2061);
}


// lift anonymous function
struct kk_std_os_dir_copy_directory_fun2063__t {
  struct kk_function_s _base;
  kk_std_os_path__path to2;
};
static kk_unit_t kk_std_os_dir_copy_directory_fun2063(kk_function_t _fself, kk_box_t _b_1731, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir_new_copy_directory_fun2063(kk_std_os_path__path to2, kk_context_t* _ctx) {
  struct kk_std_os_dir_copy_directory_fun2063__t* _self = kk_function_alloc_as(struct kk_std_os_dir_copy_directory_fun2063__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_os_dir_copy_directory_fun2063, kk_context());
  _self->to2 = to2;
  return &_self->_base;
}



// lift anonymous function
struct kk_std_os_dir_copy_directory_fun2068__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_dir_copy_directory_fun2068(kk_function_t _fself, kk_box_t _b_1721, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir_new_copy_directory_fun2068(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_dir_copy_directory_fun2068, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_dir_copy_directory_fun2068(kk_function_t _fself, kk_box_t _b_1721, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_os_path__path _x2069;
  kk_std_os_path__path _x2070 = kk_std_os_path__path_unbox(_b_1721, _ctx); /*std/os/path/path*/
  _x2069 = kk_std_os_path_nodir(_x2070, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x2069, _ctx);
}


// lift anonymous function
struct kk_std_os_dir_copy_directory_fun2072__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_dir_copy_directory_fun2072(kk_function_t _fself, kk_box_t _b_1727, kk_box_t _b_1728, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir_new_copy_directory_fun2072(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_dir_copy_directory_fun2072, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_dir_copy_directory_fun2072(kk_function_t _fself, kk_box_t _b_1727, kk_box_t _b_1728, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_os_path__path _x2073;
  kk_std_os_path__path _x2074 = kk_std_os_path__path_unbox(_b_1727, _ctx); /*std/os/path/path*/
  kk_std_os_path__path _x2075 = kk_std_os_path__path_unbox(_b_1728, _ctx); /*std/os/path/path*/
  _x2073 = kk_std_os_path__lp__fs__rp_(_x2074, _x2075, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x2073, _ctx);
}
static kk_unit_t kk_std_os_dir_copy_directory_fun2063(kk_function_t _fself, kk_box_t _b_1731, kk_context_t* _ctx) {
  struct kk_std_os_dir_copy_directory_fun2063__t* _self = kk_function_as(struct kk_std_os_dir_copy_directory_fun2063__t*, _fself);
  kk_std_os_path__path to2 = _self->to2; /* std/os/path/path */
  kk_drop_match(_self, {kk_std_os_path__path_dup(to2);}, {}, _ctx)
  kk_std_os_path__path _x2064;
  kk_box_t _x2065 = kk_box_dup(_b_1731); /*13452*/
  _x2064 = kk_std_os_path__path_unbox(_x2065, _ctx); /*std/os/path/path*/
  kk_std_os_path__path _x2066;
  kk_std_os_path__path _x2000;
  kk_box_t _x2067 = kk_std_core_hnd__open_none1(kk_std_os_dir_new_copy_directory_fun2068(_ctx), _b_1731, _ctx); /*3239*/
  _x2000 = kk_std_os_path__path_unbox(_x2067, _ctx); /*std/os/path/path*/
  kk_box_t _x2071 = kk_std_core_hnd__open_none2(kk_std_os_dir_new_copy_directory_fun2072(_ctx), kk_std_os_path__path_box(to2, _ctx), kk_std_os_path__path_box(_x2000, _ctx), _ctx); /*3333*/
  _x2066 = kk_std_os_path__path_unbox(_x2071, _ctx); /*std/os/path/path*/
  return kk_std_os_dir_copy_directory(_x2064, _x2066, _ctx);
}

kk_unit_t kk_std_os_dir_copy_directory(kk_std_os_path__path dir0, kk_std_os_path__path to2, kk_context_t* _ctx) { /* (dir : std/os/path/path, to : std/os/path/path) -> <pure,fsys> () */ 
  kk_unit_t x_1437 = kk_Unit;
  kk_std_os_path__path _x1989 = kk_std_os_path__path_dup(to2); /*std/os/path/path*/
  kk_std_os_dir_ensure_dir(_x1989, _ctx);
  if (kk_yielding(kk_context())) {
    kk_box_t _x1990 = kk_std_core_hnd_yield_extend(kk_std_os_dir_new_copy_directory_fun1991(dir0, to2, _ctx), _ctx); /*3991*/
    kk_unit_unbox(_x1990); return kk_Unit;
  }
  kk_std_core__list all0;
  kk_box_t _x1994 = kk_std_core_hnd__open_none1(kk_std_os_dir_new_copy_directory_fun1995(_ctx), kk_std_os_path__path_box(dir0, _ctx), _ctx); /*3239*/
  all0 = kk_std_core__list_unbox(_x1994, _ctx); /*list<std/os/path/path>*/
  kk_std_core_types__tuple2_ x0_1441 = kk_std_core_partition_acc(all0, kk_std_os_dir_new_copy_directory_fun1998(_ctx), kk_std_core__new_Nil(_ctx), kk_std_core__new_Nil(_ctx), _ctx); /*(list<std/os/path/path>, list<std/os/path/path>)*/;
  if (kk_yielding(kk_context())) {
    kk_std_core_types__tuple2__drop(x0_1441, _ctx);
    kk_box_t _x2003 = kk_std_core_hnd_yield_extend(kk_std_os_dir_new_copy_directory_fun2004(to2, _ctx), _ctx); /*3991*/
    kk_unit_unbox(_x2003); return kk_Unit;
  }
  kk_box_t _box_x1664 = x0_1441.fst;
  kk_box_t _box_x1665 = x0_1441.snd;
  kk_std_core__list dirs1 = kk_std_core__list_unbox(_box_x1664, NULL);
  kk_std_core__list files0 = kk_std_core__list_unbox(_box_x1665, NULL);
  kk_std_core__list_dup(dirs1);
  kk_std_core__list_dup(files0);
  kk_std_core_types__tuple2__drop(x0_1441, _ctx);
  kk_unit_t x1_1447 = kk_Unit;
  kk_function_t _x2009;
  kk_std_os_path__path_dup(to2);
  _x2009 = kk_std_os_dir_new_copy_directory_fun2010(to2, _ctx); /*(13452) -> 13453 ()*/
  kk_std_core_foreach(files0, _x2009, _ctx);
  if (kk_yielding(kk_context())) {
    kk_box_t _x2059 = kk_std_core_hnd_yield_extend(kk_std_os_dir_new_copy_directory_fun2060(dirs1, to2, _ctx), _ctx); /*3991*/
    kk_unit_unbox(_x2059); return kk_Unit;
  }
  kk_std_core_foreach(dirs1, kk_std_os_dir_new_copy_directory_fun2063(to2, _ctx), _ctx); return kk_Unit;
}
 
// Copy a file to a directory


// lift anonymous function
struct kk_std_os_dir_copy_file_to_dir_fun2077__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_dir_copy_file_to_dir_fun2077(kk_function_t _fself, kk_box_t _b_1746, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir_new_copy_file_to_dir_fun2077(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_dir_copy_file_to_dir_fun2077, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_dir_copy_file_to_dir_fun2077(kk_function_t _fself, kk_box_t _b_1746, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_os_path__path _x2078;
  kk_std_os_path__path _x2079 = kk_std_os_path__path_unbox(_b_1746, _ctx); /*std/os/path/path*/
  _x2078 = kk_std_os_path_nodir(_x2079, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x2078, _ctx);
}


// lift anonymous function
struct kk_std_os_dir_copy_file_to_dir_fun2083__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_dir_copy_file_to_dir_fun2083(kk_function_t _fself, kk_box_t _b_1752, kk_box_t _b_1753, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir_new_copy_file_to_dir_fun2083(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_dir_copy_file_to_dir_fun2083, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_dir_copy_file_to_dir_fun2083(kk_function_t _fself, kk_box_t _b_1752, kk_box_t _b_1753, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_os_path__path _x2084;
  kk_std_os_path__path _x2085 = kk_std_os_path__path_unbox(_b_1752, _ctx); /*std/os/path/path*/
  kk_std_os_path__path _x2086 = kk_std_os_path__path_unbox(_b_1753, _ctx); /*std/os/path/path*/
  _x2084 = kk_std_os_path__lp__fs__rp_(_x2085, _x2086, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x2084, _ctx);
}


// lift anonymous function
struct kk_std_os_dir_copy_file_to_dir_fun2088__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_dir_copy_file_to_dir_fun2088(kk_function_t _fself, kk_box_t _b_1759, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir_new_copy_file_to_dir_fun2088(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_dir_copy_file_to_dir_fun2088, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_dir_copy_file_to_dir_fun2088(kk_function_t _fself, kk_box_t _b_1759, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x2089;
  kk_std_os_path__path _x2090 = kk_std_os_path__path_unbox(_b_1759, _ctx); /*std/os/path/path*/
  _x2089 = kk_std_os_path_string(_x2090, _ctx); /*string*/
  return kk_string_box(_x2089);
}


// lift anonymous function
struct kk_std_os_dir_copy_file_to_dir_fun2094__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_dir_copy_file_to_dir_fun2094(kk_function_t _fself, kk_box_t _b_1764, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir_new_copy_file_to_dir_fun2094(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_dir_copy_file_to_dir_fun2094, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_dir_copy_file_to_dir_fun2094(kk_function_t _fself, kk_box_t _b_1764, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x2095;
  kk_std_os_path__path _x2096 = kk_std_os_path__path_unbox(_b_1764, _ctx); /*std/os/path/path*/
  _x2095 = kk_std_os_path_string(_x2096, _ctx); /*string*/
  return kk_string_box(_x2095);
}


// lift anonymous function
struct kk_std_os_dir_copy_file_to_dir_fun2108__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_dir_copy_file_to_dir_fun2108(kk_function_t _fself, kk_box_t _b_1770, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir_new_copy_file_to_dir_fun2108(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_dir_copy_file_to_dir_fun2108, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_dir_copy_file_to_dir_fun2108(kk_function_t _fself, kk_box_t _b_1770, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x2109;
  kk_std_os_path__path _x2110 = kk_std_os_path__path_unbox(_b_1770, _ctx); /*std/os/path/path*/
  _x2109 = kk_std_os_path_show(_x2110, _ctx); /*string*/
  return kk_string_box(_x2109);
}


// lift anonymous function
struct kk_std_os_dir_copy_file_to_dir_fun2116__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_dir_copy_file_to_dir_fun2116(kk_function_t _fself, kk_box_t _b_1773, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir_new_copy_file_to_dir_fun2116(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_dir_copy_file_to_dir_fun2116, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_dir_copy_file_to_dir_fun2116(kk_function_t _fself, kk_box_t _b_1773, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x2117;
  kk_std_os_path__path _x2118 = kk_std_os_path__path_unbox(_b_1773, _ctx); /*std/os/path/path*/
  _x2117 = kk_std_os_path_show(_x2118, _ctx); /*string*/
  return kk_string_box(_x2117);
}


// lift anonymous function
struct kk_std_os_dir_copy_file_to_dir_fun2120__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_dir_copy_file_to_dir_fun2120(kk_function_t _fself, kk_box_t _b_1781, kk_box_t _b_1782, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir_new_copy_file_to_dir_fun2120(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_dir_copy_file_to_dir_fun2120, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_dir_copy_file_to_dir_fun2120(kk_function_t _fself, kk_box_t _b_1781, kk_box_t _b_1782, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core__exception _x2121;
  kk_std_core__exception _x2122 = kk_std_core__exception_unbox(_b_1781, _ctx); /*exception*/
  kk_string_t _x2123 = kk_string_unbox(_b_1782); /*string*/
  _x2121 = kk_std_os_dir_prepend(_x2122, _x2123, _ctx); /*exception*/
  return kk_std_core__exception_box(_x2121, _ctx);
}

kk_unit_t kk_std_os_dir_copy_file_to_dir(kk_std_os_path__path from, kk_std_os_path__path dir, kk_context_t* _ctx) { /* (from : std/os/path/path, dir : std/os/path/path) -> <exn,fsys> () */ 
  kk_std_os_path__path to_1460;
  kk_std_os_path__path _x21;
  kk_box_t _x2076;
  kk_box_t _x2080;
  kk_std_os_path__path _x2081 = kk_std_os_path__path_dup(from); /*std/os/path/path*/
  _x2080 = kk_std_os_path__path_box(_x2081, _ctx); /*3238*/
  _x2076 = kk_std_core_hnd__open_none1(kk_std_os_dir_new_copy_file_to_dir_fun2077(_ctx), _x2080, _ctx); /*3239*/
  _x21 = kk_std_os_path__path_unbox(_x2076, _ctx); /*std/os/path/path*/
  kk_box_t _x2082 = kk_std_core_hnd__open_none2(kk_std_os_dir_new_copy_file_to_dir_fun2083(_ctx), kk_std_os_path__path_box(dir, _ctx), kk_std_os_path__path_box(_x21, _ctx), _ctx); /*3333*/
  to_1460 = kk_std_os_path__path_unbox(_x2082, _ctx); /*std/os/path/path*/
  kk_std_core__error _match_1807;
  kk_string_t _x1;
  kk_box_t _x2087;
  kk_box_t _x2091;
  kk_std_os_path__path _x2092 = kk_std_os_path__path_dup(from); /*std/os/path/path*/
  _x2091 = kk_std_os_path__path_box(_x2092, _ctx); /*3238*/
  _x2087 = kk_std_core_hnd__open_none1(kk_std_os_dir_new_copy_file_to_dir_fun2088(_ctx), _x2091, _ctx); /*3239*/
  _x1 = kk_string_unbox(_x2087); /*string*/
  kk_string_t _x2;
  kk_box_t _x2093;
  kk_box_t _x2097;
  kk_std_os_path__path _x2098 = kk_std_os_path__path_dup(to_1460); /*std/os/path/path*/
  _x2097 = kk_std_os_path__path_box(_x2098, _ctx); /*3238*/
  _x2093 = kk_std_core_hnd__open_none1(kk_std_os_dir_new_copy_file_to_dir_fun2094(_ctx), _x2097, _ctx); /*3239*/
  _x2 = kk_string_unbox(_x2093); /*string*/
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*std/core/hnd/evv<(<>)>*/;
  kk_std_core__error x;
  bool _x2099;
  kk_std_core_types__optional _match_1808 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
  if (kk_std_core_types__is_Optional(_match_1808)) {
    kk_box_t _box_x1767 = _match_1808._cons.Optional.value;
    bool _preserve_mtime_127 = kk_bool_unbox(_box_x1767);
    kk_std_core_types__optional_drop(_match_1808, _ctx);
    _x2099 = _preserve_mtime_127; /*bool*/
    goto _match2100;
  }
  _x2099 = true; /*bool*/
  _match2100: ;
  x = kk_std_os_dir_prim_copy_file(_x1, _x2, _x2099, _ctx); /*error<()>*/
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  _match_1807 = x; /*error<()>*/
  if (kk_std_core__is_Error(_match_1807)) {
    kk_std_core__exception exn = _match_1807._cons.Error.exception;
    kk_std_core__exception_dup(exn);
    kk_std_core__error_drop(_match_1807, _ctx);
    kk_std_core__error err_1466;
    kk_std_core__exception _x2102;
    kk_string_t _x20;
    kk_string_t _x2103;
    kk_define_string_literal(, _s2104, 15, "unable to copy ")
    _x2103 = kk_string_dup(_s2104); /*string*/
    kk_string_t _x2105;
    kk_string_t _x2106;
    kk_box_t _x2107 = kk_std_core_hnd__open_none1(kk_std_os_dir_new_copy_file_to_dir_fun2108(_ctx), kk_std_os_path__path_box(from, _ctx), _ctx); /*3239*/
    _x2106 = kk_string_unbox(_x2107); /*string*/
    kk_string_t _x2111;
    kk_string_t _x2112;
    kk_define_string_literal(, _s2113, 4, " to ")
    _x2112 = kk_string_dup(_s2113); /*string*/
    kk_string_t _x2114;
    kk_box_t _x2115 = kk_std_core_hnd__open_none1(kk_std_os_dir_new_copy_file_to_dir_fun2116(_ctx), kk_std_os_path__path_box(to_1460, _ctx), _ctx); /*3239*/
    _x2114 = kk_string_unbox(_x2115); /*string*/
    _x2111 = kk_std_core__lp__plus__plus__1_rp_(_x2112, _x2114, _ctx); /*string*/
    _x2105 = kk_std_core__lp__plus__plus__1_rp_(_x2106, _x2111, _ctx); /*string*/
    _x20 = kk_std_core__lp__plus__plus__1_rp_(_x2103, _x2105, _ctx); /*string*/
    kk_box_t _x2119 = kk_std_core_hnd__open_none2(kk_std_os_dir_new_copy_file_to_dir_fun2120(_ctx), kk_std_core__exception_box(exn, _ctx), kk_string_box(_x20), _ctx); /*3333*/
    _x2102 = kk_std_core__exception_unbox(_x2119, _ctx); /*exception*/
    err_1466 = kk_std_core__new_Error(_x2102, _ctx); /*error<()>*/
    if (kk_std_core__is_Error(err_1466)) {
      kk_std_core__exception exn0 = err_1466._cons.Error.exception;
      kk_std_core__exception_dup(exn0);
      kk_std_core__error_drop(err_1466, _ctx);
      kk_box_t _x2124 = kk_std_core_throw_exn(exn0, _ctx); /*11740*/
      kk_unit_unbox(_x2124); return kk_Unit;
    }
    kk_box_t _box_x1787 = err_1466._cons.Ok.result;
    kk_unit_t x0 = kk_unit_unbox(_box_x1787);
    kk_std_core__error_drop(err_1466, _ctx);
    x0; return kk_Unit;
  }
  kk_std_core__error_drop(_match_1807, _ctx);
  kk_std_os_path__path_drop(from, _ctx);
  kk_std_os_path__path_drop(to_1460, _ctx);
  kk_Unit; return kk_Unit;
}
 
// Recursively list all the entries under a directory.


// lift anonymous function
struct kk_std_os_dir_list_directory_recursive_fun2131__t {
  struct kk_function_s _base;
};
static bool kk_std_os_dir_list_directory_recursive_fun2131(kk_function_t _fself, kk_box_t _b_1792, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir_new_list_directory_recursive_fun2131(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_dir_list_directory_recursive_fun2131, _ctx)
  return kk_function_dup(_fself);
}

static bool kk_std_os_dir_list_directory_recursive_fun2131(kk_function_t _fself, kk_box_t _b_1792, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_os_path__path _x2132 = kk_std_os_path__path_unbox(_b_1792, _ctx); /*std/os/path/path*/
  return kk_std_os_dir_is_directory(_x2132, _ctx);
}


// lift anonymous function
struct kk_std_os_dir_list_directory_recursive_fun2133__t {
  struct kk_function_s _base;
  kk_std_core_types__optional max_depth;
};
static kk_std_core__list kk_std_os_dir_list_directory_recursive_fun2133(kk_function_t _fself, kk_box_t _b_1800, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir_new_list_directory_recursive_fun2133(kk_std_core_types__optional max_depth, kk_context_t* _ctx) {
  struct kk_std_os_dir_list_directory_recursive_fun2133__t* _self = kk_function_alloc_as(struct kk_std_os_dir_list_directory_recursive_fun2133__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_os_dir_list_directory_recursive_fun2133, kk_context());
  _self->max_depth = max_depth;
  return &_self->_base;
}

static kk_std_core__list kk_std_os_dir_list_directory_recursive_fun2133(kk_function_t _fself, kk_box_t _b_1800, kk_context_t* _ctx) {
  struct kk_std_os_dir_list_directory_recursive_fun2133__t* _self = kk_function_as(struct kk_std_os_dir_list_directory_recursive_fun2133__t*, _fself);
  kk_std_core_types__optional max_depth = _self->max_depth; /* optional<int> */
  kk_drop_match(_self, {kk_std_core_types__optional_dup(max_depth);}, {}, _ctx)
  kk_std_os_path__path _x2134 = kk_std_os_path__path_unbox(_b_1800, _ctx); /*std/os/path/path*/
  kk_std_core_types__optional _x2135;
  kk_integer_t _b_1805_1796;
  kk_integer_t _x2136;
  if (kk_std_core_types__is_Optional(max_depth)) {
    kk_box_t _box_x1795 = max_depth._cons.Optional.value;
    kk_integer_t _max_depth_12820 = kk_integer_unbox(_box_x1795);
    kk_integer_dup(_max_depth_12820);
    kk_std_core_types__optional_drop(max_depth, _ctx);
    _x2136 = _max_depth_12820; /*int*/
    goto _match2137;
  }
  _x2136 = kk_integer_from_small(1000); /*int*/
  _match2137: ;
  _b_1805_1796 = kk_integer_sub(_x2136,(kk_integer_from_small(1)),kk_context()); /*int*/
  _x2135 = kk_std_core_types__new_Optional(kk_integer_box(_b_1805_1796), _ctx); /*optional<108>*/
  return kk_std_os_dir_list_directory_recursive(_x2134, _x2135, _ctx);
}

kk_std_core__list kk_std_os_dir_list_directory_recursive(kk_std_os_path__path dir, kk_std_core_types__optional max_depth, kk_context_t* _ctx) { /* (dir : std/os/path/path, max-depth : optional<int>) -> <div,fsys> list<std/os/path/path> */ 
  bool _match_1806;
  kk_integer_t _x2127;
  if (kk_std_core_types__is_Optional(max_depth)) {
    kk_box_t _box_x1789 = max_depth._cons.Optional.value;
    kk_integer_t _max_depth_1282 = kk_integer_unbox(_box_x1789);
    kk_integer_dup(_max_depth_1282);
    _x2127 = _max_depth_1282; /*int*/
    goto _match2128;
  }
  _x2127 = kk_integer_from_small(1000); /*int*/
  _match2128: ;
  _match_1806 = kk_integer_lt(_x2127,(kk_integer_from_small(0)),kk_context()); /*bool*/
  if (_match_1806) {
    kk_std_os_path__path_drop(dir, _ctx);
    kk_std_core_types__optional_drop(max_depth, _ctx);
    return kk_std_core__new_Nil(_ctx);
  }
  kk_std_core__list all = kk_std_os_dir_list_directory(dir, _ctx); /*list<std/os/path/path>*/;
  kk_std_core__list dirs;
  kk_std_core__list _x2130 = kk_std_core__list_dup(all); /*list<std/os/path/path>*/
  dirs = kk_std_core_filter(_x2130, kk_std_os_dir_new_list_directory_recursive_fun2131(_ctx), _ctx); /*list<std/os/path/path>*/
  kk_std_core__list ys_1468 = kk_std_core__lift21046_flatmap(kk_std_os_dir_new_list_directory_recursive_fun2133(max_depth, _ctx), kk_std_core__new_Nil(_ctx), dirs, _ctx); /*list<std/os/path/path>*/;
  return kk_std_core_append(all, ys_1468, _ctx);
}

// initialization
void kk_std_os_dir__init(kk_context_t* _ctx){
  static bool _initialized = false;
  if (_initialized) return;
  _initialized = true;
  kk_std_core_types__init(_ctx);
  kk_std_core_hnd__init(_ctx);
  kk_std_core__init(_ctx);
  kk_std_os_path__init(_ctx);
}
