// Koka generated module: "std/os/path", koka version: 2.1.2
#include "std_os_path.h"

kk_std_os_path__path kk_std_os_path__copy(kk_std_os_path__path _this, kk_std_core_types__optional root0, kk_std_core_types__optional parts0, kk_context_t* _ctx) { /* (path, root : optional<string>, parts : optional<list<string>>) -> path */ 
  kk_string_t _x3326;
  if (kk_std_core_types__is_Optional(root0)) {
    kk_box_t _box_x2906 = root0._cons.Optional.value;
    kk_string_t _root_105 = kk_string_unbox(_box_x2906);
    _x3326 = _root_105; /*string*/
    goto _match3327;
  }
  kk_string_t _x = _this.root;
  kk_string_dup(_x);
  _x3326 = _x; /*string*/
  _match3327: ;
  kk_std_core__list _x3329;
  if (kk_std_core_types__is_Optional(parts0)) {
    kk_box_t _box_x2907 = parts0._cons.Optional.value;
    kk_std_core__list _parts_111 = kk_std_core__list_unbox(_box_x2907, NULL);
    kk_std_os_path__path_drop(_this, _ctx);
    _x3329 = _parts_111; /*list<string>*/
    goto _match3330;
  }
  kk_std_core__list _x0 = _this.parts;
  kk_std_core__list_dup(_x0);
  kk_std_os_path__path_drop(_this, _ctx);
  _x3329 = _x0; /*list<string>*/
  _match3330: ;
  return kk_std_os_path__new_Path(_x3326, _x3329, _ctx);
}

kk_string_t kk_std_os_path_xapp_path(kk_context_t* _ctx) { /* () -> io string */ 
  return kk_os_app_path(kk_context());
}
 
// Return the base name of a path (stem name + extension)
// `"/foo/bar.txt".path.basename === "bar.txt"`
// `"/foo".path.basename === "foo"`

kk_string_t kk_std_os_path_basename(kk_std_os_path__path p, kk_context_t* _ctx) { /* (p : path) -> string */ 
  kk_std_core__list _match_3325;
  kk_std_core__list _x = p.parts;
  kk_std_core__list_dup(_x);
  kk_std_os_path__path_drop(p, _ctx);
  _match_3325 = _x; /*list<string>*/
  if (kk_std_core__is_Cons(_match_3325)) {
    struct kk_std_core_Cons* _con3332 = kk_std_core__as_Cons(_match_3325);
    kk_box_t _box_x2908 = _con3332->head;
    kk_std_core__list _pat0 = _con3332->tail;
    kk_string_t x = kk_string_unbox(_box_x2908);
    if (kk_std_core__list_is_unique(_match_3325)) {
      kk_std_core__list_drop(_pat0, _ctx);
      kk_std_core__list_free(_match_3325);
    }
    else {
      kk_string_dup(x);
      kk_std_core__list_decref(_match_3325, _ctx);
    }
    return x;
  }
  return kk_string_empty();
}
 
// Remove the basename and only keep the root and directory name portion of the path.
// `nobase("foo/bar.ext".path) == "foo")`

kk_std_os_path__path kk_std_os_path_nobase(kk_std_os_path__path p, kk_context_t* _ctx) { /* (p : path) -> path */ 
  kk_std_core_types__optional _arg_249;
  kk_box_t _x3335;
  kk_std_core__list _x3336;
  kk_std_core__list _match_3324;
  kk_std_core__list _x = p.parts;
  kk_std_core__list_dup(_x);
  _match_3324 = _x; /*list<string>*/
  if (kk_std_core__is_Cons(_match_3324)) {
    struct kk_std_core_Cons* _con3338 = kk_std_core__as_Cons(_match_3324);
    kk_box_t _box_x2909 = _con3338->head;
    kk_std_core__list xx = _con3338->tail;
    if (kk_std_core__list_is_unique(_match_3324)) {
      kk_box_drop(_box_x2909, _ctx);
      kk_std_core__list_free(_match_3324);
    }
    else {
      kk_std_core__list_dup(xx);
      kk_std_core__list_decref(_match_3324, _ctx);
    }
    _x3336 = xx; /*list<string>*/
    goto _match3337;
  }
  _x3336 = kk_std_core__new_Nil(_ctx); /*list<string>*/
  _match3337: ;
  _x3335 = kk_std_core__list_box(_x3336, _ctx); /*108*/
  _arg_249 = kk_std_core_types__new_Optional(_x3335, _ctx); /*optional<list<string>>*/
  kk_string_t _x3340;
  kk_std_core_types__optional _x3341 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/
  if (kk_std_core_types__is_Optional(_x3341)) {
    kk_box_t _box_x2912 = _x3341._cons.Optional.value;
    kk_string_t _root_105 = kk_string_unbox(_box_x2912);
    _x3340 = _root_105; /*string*/
    goto _match3342;
  }
  kk_string_t _x0 = p.root;
  kk_string_dup(_x0);
  _x3340 = _x0; /*string*/
  _match3342: ;
  kk_std_core__list _x3344;
  if (kk_std_core_types__is_Optional(_arg_249)) {
    kk_box_t _box_x2913 = _arg_249._cons.Optional.value;
    kk_std_core__list _parts_111 = kk_std_core__list_unbox(_box_x2913, NULL);
    kk_std_os_path__path_drop(p, _ctx);
    _x3344 = _parts_111; /*list<string>*/
    goto _match3345;
  }
  kk_std_core__list _x1 = p.parts;
  kk_std_core__list_dup(_x1);
  kk_std_os_path__path_drop(p, _ctx);
  _x3344 = _x1; /*list<string>*/
  _match3345: ;
  return kk_std_os_path__new_Path(_x3340, _x3344, _ctx);
}

kk_std_core_types__tuple2_ kk_std_os_path_split_parts(kk_std_core__list parts0, kk_context_t* _ctx) { /* (parts : list<string>) -> (string, list<string>) */ 
  kk_std_core__list _b_2918_2916;
  kk_std_core__list _x3347 = kk_std_core__list_dup(parts0); /*list<string>*/
  _b_2918_2916 = kk_std_core_tail_1(_x3347, _ctx); /*list<string>*/
  kk_box_t _x3348;
  kk_string_t _x3349;
  if (kk_std_core__is_Cons(parts0)) {
    struct kk_std_core_Cons* _con3351 = kk_std_core__as_Cons(parts0);
    kk_box_t _box_x2914 = _con3351->head;
    kk_std_core__list _pat0 = _con3351->tail;
    kk_string_t x = kk_string_unbox(_box_x2914);
    if (kk_std_core__list_is_unique(parts0)) {
      kk_std_core__list_drop(_pat0, _ctx);
      kk_std_core__list_free(parts0);
    }
    else {
      kk_string_dup(x);
      kk_std_core__list_decref(parts0, _ctx);
    }
    _x3349 = x; /*string*/
    goto _match3350;
  }
  _x3349 = kk_string_empty(); /*string*/
  _match3350: ;
  _x3348 = kk_string_box(_x3349); /*6*/
  return kk_std_core_types__new_dash__lp__comma__rp_(_x3348, kk_std_core__list_box(_b_2918_2916, _ctx), _ctx);
}

kk_string_t kk_std_os_path_xrealpath(kk_string_t p, kk_context_t* _ctx) { /* (p : string) -> io string */ 
  return kk_os_realpath(p,kk_context());
}
 
// Return the directory part of a path (including the rootname)
// `"/foo/bar.txt".path.dirname === "/foo"`
// `"/foo".path.dirname === "/"`

kk_string_t kk_std_os_path_dirname(kk_std_os_path__path p, kk_context_t* _ctx) { /* (p : path) -> string */ 
  kk_string_t _x3354;
  kk_string_t _x = p.root;
  kk_string_dup(_x);
  _x3354 = _x; /*string*/
  kk_string_t _x3355;
  kk_std_core__list xs_2726;
  kk_std_core__list _x3356;
  kk_std_core__list _match_3322;
  kk_std_core__list _x0 = p.parts;
  kk_std_core__list_dup(_x0);
  kk_std_os_path__path_drop(p, _ctx);
  _match_3322 = _x0; /*list<string>*/
  if (kk_std_core__is_Cons(_match_3322)) {
    struct kk_std_core_Cons* _con3358 = kk_std_core__as_Cons(_match_3322);
    kk_box_t _box_x2919 = _con3358->head;
    kk_std_core__list xx = _con3358->tail;
    if (kk_std_core__list_is_unique(_match_3322)) {
      kk_box_drop(_box_x2919, _ctx);
      kk_std_core__list_free(_match_3322);
    }
    else {
      kk_std_core__list_dup(xx);
      kk_std_core__list_decref(_match_3322, _ctx);
    }
    _x3356 = xx; /*list<string>*/
    goto _match3357;
  }
  _x3356 = kk_std_core__new_Nil(_ctx); /*list<string>*/
  _match3357: ;
  xs_2726 = kk_std_core__lift21047_reverse_append(kk_std_core__new_Nil(_ctx), _x3356, _ctx); /*list<string>*/
  if (kk_std_core__is_Nil(xs_2726)) {
    _x3355 = kk_string_empty(); /*string*/
  }
  else {
    struct kk_std_core_Cons* _con3361 = kk_std_core__as_Cons(xs_2726);
    kk_box_t _box_x2920 = _con3361->head;
    kk_std_core__list xx0 = _con3361->tail;
    kk_string_t x = kk_string_unbox(_box_x2920);
    if (kk_std_core__list_is_unique(xs_2726)) {
      kk_std_core__list_free(xs_2726);
    }
    else {
      kk_string_dup(x);
      kk_std_core__list_dup(xx0);
      kk_std_core__list_decref(xs_2726, _ctx);
    }
    kk_string_t _x3363;
    kk_define_string_literal(, _s3364, 1, "/")
    _x3363 = kk_string_dup(_s3364); /*string*/
    _x3355 = kk_std_core__lift21050_joinsep(_x3363, xx0, x, _ctx); /*string*/
  }
  return kk_std_core__lp__plus__plus__1_rp_(_x3354, _x3355, _ctx);
}

kk_string_t kk_std_os_path_xhomedir(kk_context_t* _ctx) { /* () -> io string */ 
  return kk_os_home_dir(kk_context());
}
 
// Remove the directory and root and only keep the base name (file name) portion of the path.
// `nodir("foo/bar.ext".path) === "bar.ext"`

kk_std_os_path__path kk_std_os_path_nodir(kk_std_os_path__path p, kk_context_t* _ctx) { /* (p : path) -> path */ 
  kk_std_core_types__optional root_2734;
  kk_box_t _x3366;
  kk_string_t _x3367 = kk_string_empty(); /*string*/
  _x3366 = kk_string_box(_x3367); /*108*/
  root_2734 = kk_std_core_types__new_Optional(_x3366, _ctx); /*optional<string>*/
  kk_std_core_types__optional parts_2735;
  kk_std_core__list _b_2924_2923;
  kk_std_core__list _x3369;
  kk_std_core__list _x1 = p.parts;
  kk_std_core__list_dup(_x1);
  _x3369 = _x1; /*list<string>*/
  _b_2924_2923 = kk_std_core_take(_x3369, kk_integer_from_small(1), _ctx); /*list<string>*/
  parts_2735 = kk_std_core_types__new_Optional(kk_std_core__list_box(_b_2924_2923, _ctx), _ctx); /*optional<list<string>>*/
  kk_string_t _x3370;
  if (kk_std_core_types__is_Optional(root_2734)) {
    kk_box_t _box_x2925 = root_2734._cons.Optional.value;
    kk_string_t _root_105 = kk_string_unbox(_box_x2925);
    _x3370 = _root_105; /*string*/
    goto _match3371;
  }
  kk_string_t _x = p.root;
  kk_string_dup(_x);
  _x3370 = _x; /*string*/
  _match3371: ;
  kk_std_core__list _x3373;
  if (kk_std_core_types__is_Optional(parts_2735)) {
    kk_box_t _box_x2926 = parts_2735._cons.Optional.value;
    kk_std_core__list _parts_111 = kk_std_core__list_unbox(_box_x2926, NULL);
    kk_std_os_path__path_drop(p, _ctx);
    _x3373 = _parts_111; /*list<string>*/
    goto _match3374;
  }
  kk_std_core__list _x0 = p.parts;
  kk_std_core__list_dup(_x0);
  kk_std_os_path__path_drop(p, _ctx);
  _x3373 = _x0; /*list<string>*/
  _match3374: ;
  return kk_std_os_path__new_Path(_x3370, _x3373, _ctx);
}
 
// Return the last directory component name (or the empty string).
// `"c:/foo/bar/tst.txt".path.parentname === "bar"

kk_string_t kk_std_os_path_parentname(kk_std_os_path__path p, kk_context_t* _ctx) { /* (p : path) -> string */ 
  kk_std_core__list _match_3320;
  kk_std_core__list _match_3321;
  kk_std_core__list _x = p.parts;
  kk_std_core__list_dup(_x);
  kk_std_os_path__path_drop(p, _ctx);
  _match_3321 = _x; /*list<string>*/
  if (kk_std_core__is_Cons(_match_3321)) {
    struct kk_std_core_Cons* _con3377 = kk_std_core__as_Cons(_match_3321);
    kk_box_t _box_x2927 = _con3377->head;
    kk_std_core__list xx = _con3377->tail;
    if (kk_std_core__list_is_unique(_match_3321)) {
      kk_box_drop(_box_x2927, _ctx);
      kk_std_core__list_free(_match_3321);
    }
    else {
      kk_std_core__list_dup(xx);
      kk_std_core__list_decref(_match_3321, _ctx);
    }
    _match_3320 = xx; /*list<string>*/
    goto _match3376;
  }
  _match_3320 = kk_std_core__new_Nil(_ctx); /*list<string>*/
  _match3376: ;
  if (kk_std_core__is_Cons(_match_3320)) {
    struct kk_std_core_Cons* _con3379 = kk_std_core__as_Cons(_match_3320);
    kk_box_t _box_x2928 = _con3379->head;
    kk_std_core__list _pat0 = _con3379->tail;
    kk_string_t x = kk_string_unbox(_box_x2928);
    if (kk_std_core__list_is_unique(_match_3320)) {
      kk_std_core__list_drop(_pat0, _ctx);
      kk_std_core__list_free(_match_3320);
    }
    else {
      kk_string_dup(x);
      kk_std_core__list_decref(_match_3320, _ctx);
    }
    return x;
  }
  return kk_string_empty();
}
 
// Return the OS specific directory separator (`"/"` or `"\\"`)

kk_string_t kk_std_os_path_partsep(kk_context_t* _ctx) { /* () -> ndet string */ 
  return kk_os_dir_sep(kk_context());
}
 
// Return the OS specific path separator (`';'` or `':'`)

kk_string_t kk_std_os_path_pathsep(kk_context_t* _ctx) { /* () -> ndet string */ 
  return kk_os_path_sep(kk_context());
}

kk_string_t kk_std_os_path_xtempdir(kk_context_t* _ctx) { /* () -> io string */ 
  return kk_os_temp_dir(kk_context());
}
 
// Is a path empty?

bool kk_std_os_path_is_empty(kk_std_os_path__path p, kk_context_t* _ctx) { /* (p : path) -> bool */ 
  bool _match_3318;
  kk_string_t _x3382;
  kk_string_t _x = p.root;
  kk_string_dup(_x);
  _x3382 = _x; /*string*/
  kk_string_t _x3383 = kk_string_empty(); /*string*/
  _match_3318 = kk_string_is_eq(_x3382,_x3383,kk_context()); /*bool*/
  if (_match_3318) {
    kk_std_core__list _match_3319;
    kk_std_core__list _x0 = p.parts;
    kk_std_core__list_dup(_x0);
    kk_std_os_path__path_drop(p, _ctx);
    _match_3319 = _x0; /*list<string>*/
    if (kk_std_core__is_Nil(_match_3319)) {
      return true;
    }
    kk_std_core__list_drop(_match_3319, _ctx);
    return false;
  }
  kk_std_os_path__path_drop(p, _ctx);
  return false;
}

kk_std_core__list kk_std_os_path_push_part(kk_string_t dir, kk_std_core__list dirs, kk_context_t* _ctx) { /* (dir : string, dirs : list<string>) -> list<string> */ 
  bool _match_3313;
  bool _match_3316;
  kk_string_t _x3386 = kk_string_dup(dir); /*string*/
  kk_string_t _x3387;
  kk_define_string_literal(, _s3388, 1, ".")
  _x3387 = kk_string_dup(_s3388); /*string*/
  _match_3316 = kk_string_is_eq(_x3386,_x3387,kk_context()); /*bool*/
  if (_match_3316) {
    _match_3313 = true; /*bool*/
  }
  else {
    kk_string_t _x3389 = kk_string_dup(dir); /*string*/
    kk_string_t _x3390 = kk_string_empty(); /*string*/
    _match_3313 = kk_string_is_eq(_x3389,_x3390,kk_context()); /*bool*/
  }
  if (_match_3313) {
    kk_string_drop(dir, _ctx);
    return dirs;
  }
  bool _match_3314;
  bool _match_3315;
  kk_string_t _x3392 = kk_string_dup(dir); /*string*/
  kk_string_t _x3393;
  kk_define_string_literal(, _s3394, 2, "..")
  _x3393 = kk_string_dup(_s3394); /*string*/
  _match_3315 = kk_string_is_eq(_x3392,_x3393,kk_context()); /*bool*/
  if (_match_3315) {
    kk_std_core__list _x3395 = kk_std_core__list_dup(dirs); /*list<string>*/
    _match_3314 = kk_std_core_is_cons(_x3395, _ctx); /*bool*/
  }
  else {
    _match_3314 = false; /*bool*/
  }
  if (_match_3314) {
    kk_string_drop(dir, _ctx);
    return kk_std_core_tail_1(dirs, _ctx);
  }
  return kk_std_core__new_Cons(kk_reuse_null, kk_string_box(dir), dirs, _ctx);
}

kk_std_core__list kk_std_os_path_push_parts(kk_std_core__list parts0, kk_std_core__list dirs, kk_context_t* _ctx) { /* (parts : list<string>, dirs : list<string>) -> list<string> */ 
  kk__tailcall: ;
  if (kk_std_core__is_Cons(parts0)) {
    struct kk_std_core_Cons* _con3396 = kk_std_core__as_Cons(parts0);
    kk_box_t _box_x2933 = _con3396->head;
    kk_std_core__list rest = _con3396->tail;
    kk_string_t part = kk_string_unbox(_box_x2933);
    if (kk_std_core__list_is_unique(parts0)) {
      kk_std_core__list_free(parts0);
    }
    else {
      kk_string_dup(part);
      kk_std_core__list_dup(rest);
      kk_std_core__list_decref(parts0, _ctx);
    }
    { // tailcall
      kk_std_core__list _x3398 = kk_std_os_path_push_part(part, dirs, _ctx); /*list<string>*/
      parts0 = rest;
      dirs = _x3398;
      goto kk__tailcall;
    }
  }
  return dirs;
}
 
// monadic lift

bool kk_std_os_path__mlift2698_proot(kk_char_t wild__4, kk_context_t* _ctx) { /* (wild_4 : char) -> std/text/parse/parse bool */ 
  return false;
}
 
// monadic lift

bool kk_std_os_path__mlift2699_proot(kk_unit_t wild__5, kk_context_t* _ctx) { /* (wild_5 : ()) -> std/text/parse/parse bool */ 
  return true;
}
 
// monadic lift

kk_unit_t kk_std_os_path__mlift2700_proot(kk_char_t wild__0, kk_context_t* _ctx) { /* (wild_0 : char) -> std/text/parse/parse () */ 
  kk_Unit; return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_std_os_path__mlift2701_proot_fun3400__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path__mlift2701_proot_fun3400(kk_function_t _fself, kk_box_t _b_2935, kk_context_t* _ctx);
static kk_function_t kk_std_os_path__new_mlift2701_proot_fun3400(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path__mlift2701_proot_fun3400, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_path__mlift2701_proot_fun3400(kk_function_t _fself, kk_box_t _b_2935, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_unit_t _x3401 = kk_Unit;
  kk_char_t _x3402 = kk_char_unbox(_b_2935, _ctx); /*char*/
  kk_std_os_path__mlift2700_proot(_x3402, _ctx);
  return kk_unit_box(_x3401);
}

kk_unit_t kk_std_os_path__mlift2701_proot(kk_char_t wild__, kk_context_t* _ctx) { /* (wild_ : char) -> std/text/parse/parse () */ 
  kk_char_t x_2748 = kk_std_text_parse_char(':', _ctx); /*char*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x3399 = kk_std_core_hnd_yield_extend(kk_std_os_path__new_mlift2701_proot_fun3400(_ctx), _ctx); /*3991*/
    kk_unit_unbox(_x3399); return kk_Unit;
  }
  kk_std_os_path__mlift2700_proot(x_2748, _ctx); return kk_Unit;
}
 
// monadic lift

kk_unit_t kk_std_os_path__mlift2702_proot(kk_std_core__list wild__2, kk_context_t* _ctx) { /* (wild_2 : list<char>) -> std/text/parse/parse () */ 
  kk_std_core__list_drop(wild__2, _ctx);
  kk_Unit; return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_std_os_path__mlift2703_proot_fun3403__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path__mlift2703_proot_fun3403(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_os_path__new_mlift2703_proot_fun3403(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path__mlift2703_proot_fun3403, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_path__mlift2703_proot_fun3403(kk_function_t _fself, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_char_t _x3404;
  kk_string_t _x3405;
  kk_define_string_literal(, _s3406, 1, "/")
  _x3405 = kk_string_dup(_s3406); /*string*/
  _x3404 = kk_std_text_parse_none_of(_x3405, _ctx); /*char*/
  return kk_char_box(_x3404, _ctx);
}


// lift anonymous function
struct kk_std_os_path__mlift2703_proot_fun3408__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path__mlift2703_proot_fun3408(kk_function_t _fself, kk_box_t _b_2940, kk_context_t* _ctx);
static kk_function_t kk_std_os_path__new_mlift2703_proot_fun3408(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path__mlift2703_proot_fun3408, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_path__mlift2703_proot_fun3408(kk_function_t _fself, kk_box_t _b_2940, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_unit_t _x3409 = kk_Unit;
  kk_std_core__list _x3410 = kk_std_core__list_unbox(_b_2940, _ctx); /*list<char>*/
  kk_std_os_path__mlift2702_proot(_x3410, _ctx);
  return kk_unit_box(_x3409);
}

kk_unit_t kk_std_os_path__mlift2703_proot(kk_char_t wild__1, kk_context_t* _ctx) { /* (wild_1 : char) -> std/text/parse/parse () */ 
  kk_std_core__list x_2750 = kk_std_text_parse_many1(kk_std_os_path__new_mlift2703_proot_fun3403(_ctx), _ctx); /*list<char>*/;
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_2750, _ctx);
    kk_box_t _x3407 = kk_std_core_hnd_yield_extend(kk_std_os_path__new_mlift2703_proot_fun3408(_ctx), _ctx); /*3991*/
    kk_unit_unbox(_x3407); return kk_Unit;
  }
  kk_std_os_path__mlift2702_proot(x_2750, _ctx); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_std_os_path__mlift2704_proot_fun3412__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path__mlift2704_proot_fun3412(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_os_path__new_mlift2704_proot_fun3412(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path__mlift2704_proot_fun3412, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_std_os_path__mlift2704_proot_fun3415__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path__mlift2704_proot_fun3415(kk_function_t _fself, kk_box_t _b_2943, kk_context_t* _ctx);
static kk_function_t kk_std_os_path__new_mlift2704_proot_fun3415(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path__mlift2704_proot_fun3415, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_path__mlift2704_proot_fun3415(kk_function_t _fself, kk_box_t _b_2943, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  bool _x3416;
  kk_char_t _x3417 = kk_char_unbox(_b_2943, _ctx); /*char*/
  _x3416 = kk_std_os_path__mlift2698_proot(_x3417, _ctx); /*bool*/
  return kk_bool_box(_x3416);
}
static kk_box_t kk_std_os_path__mlift2704_proot_fun3412(kk_function_t _fself, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  bool _x3413;
  kk_char_t x_2752 = kk_std_text_parse_char('/', _ctx); /*char*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x3414 = kk_std_core_hnd_yield_extend(kk_std_os_path__new_mlift2704_proot_fun3415(_ctx), _ctx); /*3991*/
    _x3413 = kk_bool_unbox(_x3414); /*bool*/
  }
  else {
    _x3413 = kk_std_os_path__mlift2698_proot(x_2752, _ctx); /*bool*/
  }
  return kk_bool_box(_x3413);
}


// lift anonymous function
struct kk_std_os_path__mlift2704_proot_fun3418__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path__mlift2704_proot_fun3418(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_os_path__new_mlift2704_proot_fun3418(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path__mlift2704_proot_fun3418, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_std_os_path__mlift2704_proot_fun3421__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path__mlift2704_proot_fun3421(kk_function_t _fself, kk_box_t _b_2945, kk_context_t* _ctx);
static kk_function_t kk_std_os_path__new_mlift2704_proot_fun3421(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path__mlift2704_proot_fun3421, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_path__mlift2704_proot_fun3421(kk_function_t _fself, kk_box_t _b_2945, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  bool _x3422;
  kk_unit_t _x3423 = kk_Unit;
  kk_unit_unbox(_b_2945);
  _x3422 = kk_std_os_path__mlift2699_proot(_x3423, _ctx); /*bool*/
  return kk_bool_box(_x3422);
}
static kk_box_t kk_std_os_path__mlift2704_proot_fun3418(kk_function_t _fself, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  bool _x3419;
  kk_unit_t x0_2754 = kk_Unit;
  kk_std_text_parse_eof(_ctx);
  if (kk_yielding(kk_context())) {
    kk_box_t _x3420 = kk_std_core_hnd_yield_extend(kk_std_os_path__new_mlift2704_proot_fun3421(_ctx), _ctx); /*3991*/
    _x3419 = kk_bool_unbox(_x3420); /*bool*/
  }
  else {
    _x3419 = kk_std_os_path__mlift2699_proot(x0_2754, _ctx); /*bool*/
  }
  return kk_bool_box(_x3419);
}

bool kk_std_os_path__mlift2704_proot(kk_unit_t wild__3, kk_context_t* _ctx) { /* (wild_3 : ()) -> std/text/parse/parse bool */ 
  kk_box_t _x3411 = kk_std_text_parse__lp__bar__bar__rp_(kk_std_os_path__new_mlift2704_proot_fun3412(_ctx), kk_std_os_path__new_mlift2704_proot_fun3418(_ctx), _ctx); /*1032*/
  return kk_bool_unbox(_x3411);
}


// lift anonymous function
struct kk_std_os_path_proot_fun3425__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path_proot_fun3425(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_os_path_new_proot_fun3425(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path_proot_fun3425, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_std_os_path_proot_fun3428__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path_proot_fun3428(kk_function_t _fself, kk_box_t _b_2953, kk_context_t* _ctx);
static kk_function_t kk_std_os_path_new_proot_fun3428(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path_proot_fun3428, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_path_proot_fun3428(kk_function_t _fself, kk_box_t _b_2953, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_unit_t _x3429 = kk_Unit;
  kk_char_t _x3430 = kk_char_unbox(_b_2953, _ctx); /*char*/
  kk_std_os_path__mlift2701_proot(_x3430, _ctx);
  return kk_unit_box(_x3429);
}
static kk_box_t kk_std_os_path_proot_fun3425(kk_function_t _fself, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_unit_t _x3426 = kk_Unit;
  kk_char_t x0_2759 = kk_std_text_parse_alpha(_ctx); /*char*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x3427 = kk_std_core_hnd_yield_extend(kk_std_os_path_new_proot_fun3428(_ctx), _ctx); /*3991*/
    kk_unit_unbox(_x3427);
  }
  else {
    kk_std_os_path__mlift2701_proot(x0_2759, _ctx);
  }
  return kk_unit_box(_x3426);
}


// lift anonymous function
struct kk_std_os_path_proot_fun3431__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path_proot_fun3431(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_os_path_new_proot_fun3431(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path_proot_fun3431, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_std_os_path_proot_fun3434__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path_proot_fun3434(kk_function_t _fself, kk_box_t _b_2955, kk_context_t* _ctx);
static kk_function_t kk_std_os_path_new_proot_fun3434(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path_proot_fun3434, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_path_proot_fun3434(kk_function_t _fself, kk_box_t _b_2955, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_unit_t _x3435 = kk_Unit;
  kk_char_t _x3436 = kk_char_unbox(_b_2955, _ctx); /*char*/
  kk_std_os_path__mlift2703_proot(_x3436, _ctx);
  return kk_unit_box(_x3435);
}
static kk_box_t kk_std_os_path_proot_fun3431(kk_function_t _fself, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_unit_t _x3432 = kk_Unit;
  kk_char_t x1_2761 = kk_std_text_parse_char('/', _ctx); /*char*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x3433 = kk_std_core_hnd_yield_extend(kk_std_os_path_new_proot_fun3434(_ctx), _ctx); /*3991*/
    kk_unit_unbox(_x3433);
  }
  else {
    kk_std_os_path__mlift2703_proot(x1_2761, _ctx);
  }
  return kk_unit_box(_x3432);
}


// lift anonymous function
struct kk_std_os_path_proot_fun3438__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path_proot_fun3438(kk_function_t _fself, kk_box_t _b_2963, kk_context_t* _ctx);
static kk_function_t kk_std_os_path_new_proot_fun3438(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path_proot_fun3438, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_path_proot_fun3438(kk_function_t _fself, kk_box_t _b_2963, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  bool _x3439;
  kk_unit_t _x3440 = kk_Unit;
  kk_unit_unbox(_b_2963);
  _x3439 = kk_std_os_path__mlift2704_proot(_x3440, _ctx); /*bool*/
  return kk_bool_box(_x3439);
}


// lift anonymous function
struct kk_std_os_path_proot_fun3441__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path_proot_fun3441(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_os_path_new_proot_fun3441(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path_proot_fun3441, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_std_os_path_proot_fun3444__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path_proot_fun3444(kk_function_t _fself, kk_box_t _b_2965, kk_context_t* _ctx);
static kk_function_t kk_std_os_path_new_proot_fun3444(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path_proot_fun3444, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_path_proot_fun3444(kk_function_t _fself, kk_box_t _b_2965, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  bool _x3445;
  kk_char_t _x3446 = kk_char_unbox(_b_2965, _ctx); /*char*/
  _x3445 = kk_std_os_path__mlift2698_proot(_x3446, _ctx); /*bool*/
  return kk_bool_box(_x3445);
}
static kk_box_t kk_std_os_path_proot_fun3441(kk_function_t _fself, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  bool _x3442;
  kk_char_t x2_2764 = kk_std_text_parse_char('/', _ctx); /*char*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x3443 = kk_std_core_hnd_yield_extend(kk_std_os_path_new_proot_fun3444(_ctx), _ctx); /*3991*/
    _x3442 = kk_bool_unbox(_x3443); /*bool*/
  }
  else {
    _x3442 = kk_std_os_path__mlift2698_proot(x2_2764, _ctx); /*bool*/
  }
  return kk_bool_box(_x3442);
}


// lift anonymous function
struct kk_std_os_path_proot_fun3447__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path_proot_fun3447(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_os_path_new_proot_fun3447(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path_proot_fun3447, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_std_os_path_proot_fun3450__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path_proot_fun3450(kk_function_t _fself, kk_box_t _b_2967, kk_context_t* _ctx);
static kk_function_t kk_std_os_path_new_proot_fun3450(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path_proot_fun3450, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_path_proot_fun3450(kk_function_t _fself, kk_box_t _b_2967, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  bool _x3451;
  kk_unit_t _x3452 = kk_Unit;
  kk_unit_unbox(_b_2967);
  _x3451 = kk_std_os_path__mlift2699_proot(_x3452, _ctx); /*bool*/
  return kk_bool_box(_x3451);
}
static kk_box_t kk_std_os_path_proot_fun3447(kk_function_t _fself, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  bool _x3448;
  kk_unit_t x3_2766 = kk_Unit;
  kk_std_text_parse_eof(_ctx);
  if (kk_yielding(kk_context())) {
    kk_box_t _x3449 = kk_std_core_hnd_yield_extend(kk_std_os_path_new_proot_fun3450(_ctx), _ctx); /*3991*/
    _x3448 = kk_bool_unbox(_x3449); /*bool*/
  }
  else {
    _x3448 = kk_std_os_path__mlift2699_proot(x3_2766, _ctx); /*bool*/
  }
  return kk_bool_box(_x3448);
}

bool kk_std_os_path_proot(kk_context_t* _ctx) { /* () -> std/text/parse/parse bool */ 
  kk_unit_t x_2756 = kk_Unit;
  kk_box_t _x3424 = kk_std_text_parse__lp__bar__bar__rp_(kk_std_os_path_new_proot_fun3425(_ctx), kk_std_os_path_new_proot_fun3431(_ctx), _ctx); /*1032*/
  kk_unit_unbox(_x3424);
  kk_box_t _x3437;
  if (kk_yielding(kk_context())) {
    _x3437 = kk_std_core_hnd_yield_extend(kk_std_os_path_new_proot_fun3438(_ctx), _ctx); /*3991*/
  }
  else {
    _x3437 = kk_std_text_parse__lp__bar__bar__rp_(kk_std_os_path_new_proot_fun3441(_ctx), kk_std_os_path_new_proot_fun3447(_ctx), _ctx); /*3991*/
  }
  return kk_bool_unbox(_x3437);
}
 
// Convert a `:path` to a normalized `:string` path.
// If this results in an empty string, the current directory path `"."` is returned.
// `"c:/foo/test.txt".path.string -> "c:/foo/test.txt"`
// `"c:\\foo\\test.txt".path.string -> "c:/foo/test.txt"`
// `"/foo//./bar/../test.txt".path.string -> "/foo/test.txt"`

kk_string_t kk_std_os_path_string(kk_std_os_path__path p, kk_context_t* _ctx) { /* (p : path) -> string */ 
  kk_string_t s;
  kk_string_t _x3453;
  kk_string_t _x = p.root;
  kk_string_dup(_x);
  _x3453 = _x; /*string*/
  kk_string_t _x3454;
  kk_std_core__list xs_2769;
  kk_std_core__list _x3455;
  kk_std_core__list _x0 = p.parts;
  kk_std_core__list_dup(_x0);
  kk_std_os_path__path_drop(p, _ctx);
  _x3455 = _x0; /*list<string>*/
  xs_2769 = kk_std_core__lift21047_reverse_append(kk_std_core__new_Nil(_ctx), _x3455, _ctx); /*list<string>*/
  if (kk_std_core__is_Nil(xs_2769)) {
    _x3454 = kk_string_empty(); /*string*/
  }
  else {
    struct kk_std_core_Cons* _con3457 = kk_std_core__as_Cons(xs_2769);
    kk_box_t _box_x2975 = _con3457->head;
    kk_std_core__list xx = _con3457->tail;
    kk_string_t x = kk_string_unbox(_box_x2975);
    if (kk_std_core__list_is_unique(xs_2769)) {
      kk_std_core__list_free(xs_2769);
    }
    else {
      kk_string_dup(x);
      kk_std_core__list_dup(xx);
      kk_std_core__list_decref(xs_2769, _ctx);
    }
    kk_string_t _x3459;
    kk_define_string_literal(, _s3460, 1, "/")
    _x3459 = kk_string_dup(_s3460); /*string*/
    _x3454 = kk_std_core__lift21050_joinsep(_x3459, xx, x, _ctx); /*string*/
  }
  s = kk_std_core__lp__plus__plus__1_rp_(_x3453, _x3454, _ctx); /*string*/
  bool _match_3303;
  kk_string_t _x3461 = kk_string_dup(s); /*string*/
  _match_3303 = kk_std_core_is_empty_2(_x3461, _ctx); /*bool*/
  if (_match_3303) {
    kk_string_drop(s, _ctx);
    kk_define_string_literal(, _s3462, 1, ".")
    return kk_string_dup(_s3462);
  }
  return s;
}
 
// Create a normalized `:path` from a path string.


// lift anonymous function
struct kk_std_os_path_path_fun3484__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path_path_fun3484(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_os_path_new_path_fun3484(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path_path_fun3484, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_path_path_fun3484(kk_function_t _fself, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  bool _x3485 = kk_std_os_path_proot(_ctx); /*bool*/
  return kk_bool_box(_x3485);
}

kk_std_os_path__path kk_std_os_path_path(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> path */ 
  bool _match_3299;
  kk_string_t _x3476 = kk_string_dup(s); /*string*/
  _match_3299 = kk_std_core_is_empty_2(_x3476, _ctx); /*bool*/
  if (_match_3299) {
    kk_string_drop(s, _ctx);
    kk_string_t _x3477 = kk_string_empty(); /*string*/
    return kk_std_os_path__new_Path(_x3477, kk_std_core__new_Nil(_ctx), _ctx);
  }
  kk_string_t t;
  kk_string_t _x3479;
  kk_define_string_literal(, _s3480, 1, "\\")
  _x3479 = kk_string_dup(_s3480); /*string*/
  kk_string_t _x3481;
  kk_define_string_literal(, _s3482, 1, "/")
  _x3481 = kk_string_dup(_s3482); /*string*/
  t = kk_string_replace_all(s,_x3479,_x3481,kk_context()); /*string*/
  kk_std_core_types__maybe _match_3300;
  kk_string_t _x3483 = kk_string_dup(t); /*string*/
  _match_3300 = kk_std_text_parse_starts_with(_x3483, kk_std_os_path_new_path_fun3484(_ctx), _ctx); /*maybe<(2486, sslice)>*/
  if (kk_std_core_types__is_Nothing(_match_3300)) {
    kk_std_core__list parts0;
    kk_std_core__list _x3486;
    kk_vector_t v_21693;
    kk_string_t _x3487;
    kk_define_string_literal(, _s3488, 1, "/")
    _x3487 = kk_string_dup(_s3488); /*string*/
    v_21693 = kk_string_splitv(t,_x3487,kk_context()); /*vector<string>*/
    _x3486 = kk_std_core_vlist(v_21693, kk_std_core_types__new_None(_ctx), _ctx); /*list<2154>*/
    kk_std_core__list _x3489;
    kk_std_core_types__optional _x3490 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/
    if (kk_std_core_types__is_Optional(_x3490)) {
      kk_box_t _box_x2981 = _x3490._cons.Optional.value;
      kk_std_core__list _dirs_1291 = kk_std_core__list_unbox(_box_x2981, NULL);
      _x3489 = _dirs_1291; /*list<string>*/
      goto _match3491;
    }
    _x3489 = kk_std_core__new_Nil(_ctx); /*list<string>*/
    _match3491: ;
    parts0 = kk_std_os_path_push_parts(_x3486, _x3489, _ctx); /*list<string>*/
    kk_string_t _x3493 = kk_string_empty(); /*string*/
    return kk_std_os_path__new_Path(_x3493, parts0, _ctx);
  }
  kk_box_t _box_x2982 = _match_3300._cons.Just.value;
  kk_std_core_types__tuple2_ _pat3 = kk_std_core_types__tuple2__unbox(_box_x2982, NULL);
  kk_box_t _box_x2983 = _pat3.fst;
  kk_box_t _box_x2984 = _pat3.snd;
  bool eof = kk_bool_unbox(_box_x2983);
  kk_std_core__sslice rest = kk_std_core__sslice_unbox(_box_x2984, NULL);
  kk_string_drop(t, _ctx);
  kk_std_core__sslice_dup(rest);
  kk_std_core_types__maybe_drop(_match_3300, _ctx);
  kk_string_t root0_2780;
  kk_string_t _x3498;
  kk_std_core__sslice _x3499;
  kk_std_core__sslice _x3500 = kk_std_core__sslice_dup(rest); /*sslice*/
  _x3499 = kk_std_core_before(_x3500, _ctx); /*sslice*/
  _x3498 = kk_std_core_string_3(_x3499, _ctx); /*string*/
  kk_string_t _x3501;
  if (eof) {
    kk_define_string_literal(, _s3502, 1, "/")
    _x3501 = kk_string_dup(_s3502); /*string*/
  }
  else {
    _x3501 = kk_string_empty(); /*string*/
  }
  root0_2780 = kk_std_core__lp__plus__plus__1_rp_(_x3498, _x3501, _ctx); /*string*/
  kk_string_t s2_2781 = kk_std_core_string_3(rest, _ctx); /*string*/;
  kk_std_core__list parts00;
  kk_std_core__list _x3504;
  kk_vector_t v_216930;
  kk_string_t _x3505;
  kk_define_string_literal(, _s3506, 1, "/")
  _x3505 = kk_string_dup(_s3506); /*string*/
  v_216930 = kk_string_splitv(s2_2781,_x3505,kk_context()); /*vector<string>*/
  _x3504 = kk_std_core_vlist(v_216930, kk_std_core_types__new_None(_ctx), _ctx); /*list<2154>*/
  kk_std_core__list _x3507;
  kk_std_core_types__optional _x3508 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/
  if (kk_std_core_types__is_Optional(_x3508)) {
    kk_box_t _box_x2985 = _x3508._cons.Optional.value;
    kk_std_core__list _dirs_12910 = kk_std_core__list_unbox(_box_x2985, NULL);
    _x3507 = _dirs_12910; /*list<string>*/
    goto _match3509;
  }
  _x3507 = kk_std_core__new_Nil(_ctx); /*list<string>*/
  _match3509: ;
  parts00 = kk_std_os_path_push_parts(_x3504, _x3507, _ctx); /*list<string>*/
  return kk_std_os_path__new_Path(root0_2780, parts00, _ctx);
}
 
// Add two paths together using left-associative operator `(/)`.
// Keeps the root of `p1` and discards the root name of `p2`.
// `"/a/" / "b/foo.txt"          === "/a/b/foo.txt"`
// `"/a/foo.txt" / "/b/bar.txt"  === "/a/foo.txt/b/bar.txt"`
// `"c:/foo" / "d:/bar"          === "c:/foo/bar"`

kk_std_os_path__path kk_std_os_path__lp__fs__rp_(kk_std_os_path__path p1, kk_std_os_path__path p2, kk_context_t* _ctx) { /* (p1 : path, p2 : path) -> path */ 
  kk_std_core_types__optional root_2785;
  kk_box_t _x3511;
  kk_string_t _x3512;
  kk_string_t _x = p1.root;
  kk_string_dup(_x);
  _x3512 = _x; /*string*/
  _x3511 = kk_string_box(_x3512); /*108*/
  root_2785 = kk_std_core_types__new_Optional(_x3511, _ctx); /*optional<string>*/
  kk_std_core_types__optional parts_2786;
  kk_std_core__list _b_2991_2990;
  kk_std_core__list _x3513;
  kk_std_core__list _x3514;
  kk_std_core__list _x0 = p2.parts;
  kk_std_core__list_dup(_x0);
  kk_std_os_path__path_drop(p2, _ctx);
  _x3514 = _x0; /*list<string>*/
  _x3513 = kk_std_core__lift21047_reverse_append(kk_std_core__new_Nil(_ctx), _x3514, _ctx); /*list<2501>*/
  kk_std_core__list _x3515;
  kk_std_core__list _x1 = p1.parts;
  kk_std_core__list_dup(_x1);
  kk_std_os_path__path_drop(p1, _ctx);
  _x3515 = _x1; /*list<string>*/
  _b_2991_2990 = kk_std_os_path_push_parts(_x3513, _x3515, _ctx); /*list<string>*/
  parts_2786 = kk_std_core_types__new_Optional(kk_std_core__list_box(_b_2991_2990, _ctx), _ctx); /*optional<list<string>>*/
  kk_string_t _x3516;
  if (kk_std_core_types__is_Optional(root_2785)) {
    kk_box_t _box_x2992 = root_2785._cons.Optional.value;
    kk_string_t _root_1093 = kk_string_unbox(_box_x2992);
    _x3516 = _root_1093; /*string*/
    goto _match3517;
  }
  _x3516 = kk_string_empty(); /*string*/
  _match3517: ;
  kk_std_core__list _x3520;
  if (kk_std_core_types__is_Optional(parts_2786)) {
    kk_box_t _box_x2993 = parts_2786._cons.Optional.value;
    kk_std_core__list _parts_1098 = kk_std_core__list_unbox(_box_x2993, NULL);
    _x3520 = _parts_1098; /*list<string>*/
    goto _match3521;
  }
  _x3520 = kk_std_core__new_Nil(_ctx); /*list<string>*/
  _match3521: ;
  return kk_std_os_path__new_Path(_x3516, _x3520, _ctx);
}
 
// Convenience function that adds a string path.

kk_std_os_path__path kk_std_os_path__lp__fs__1_rp_(kk_std_os_path__path p1, kk_string_t p2, kk_context_t* _ctx) { /* (p1 : path, p2 : string) -> path */ 
  kk_std_os_path__path p20_2792 = kk_std_os_path_path(p2, _ctx); /*std/os/path/path*/;
  kk_std_core_types__optional root_2793;
  kk_box_t _x3523;
  kk_string_t _x3524;
  kk_string_t _x = p1.root;
  kk_string_dup(_x);
  _x3524 = _x; /*string*/
  _x3523 = kk_string_box(_x3524); /*108*/
  root_2793 = kk_std_core_types__new_Optional(_x3523, _ctx); /*optional<string>*/
  kk_std_core_types__optional parts_2794;
  kk_std_core__list _b_2997_2996;
  kk_std_core__list _x3525;
  kk_std_core__list _x3526;
  kk_std_core__list _x0 = p20_2792.parts;
  kk_std_core__list_dup(_x0);
  kk_std_os_path__path_drop(p20_2792, _ctx);
  _x3526 = _x0; /*list<string>*/
  _x3525 = kk_std_core__lift21047_reverse_append(kk_std_core__new_Nil(_ctx), _x3526, _ctx); /*list<2501>*/
  kk_std_core__list _x3527;
  kk_std_core__list _x1 = p1.parts;
  kk_std_core__list_dup(_x1);
  kk_std_os_path__path_drop(p1, _ctx);
  _x3527 = _x1; /*list<string>*/
  _b_2997_2996 = kk_std_os_path_push_parts(_x3525, _x3527, _ctx); /*list<string>*/
  parts_2794 = kk_std_core_types__new_Optional(kk_std_core__list_box(_b_2997_2996, _ctx), _ctx); /*optional<list<string>>*/
  kk_string_t _x3528;
  if (kk_std_core_types__is_Optional(root_2793)) {
    kk_box_t _box_x2998 = root_2793._cons.Optional.value;
    kk_string_t _root_1093 = kk_string_unbox(_box_x2998);
    _x3528 = _root_1093; /*string*/
    goto _match3529;
  }
  _x3528 = kk_string_empty(); /*string*/
  _match3529: ;
  kk_std_core__list _x3532;
  if (kk_std_core_types__is_Optional(parts_2794)) {
    kk_box_t _box_x2999 = parts_2794._cons.Optional.value;
    kk_std_core__list _parts_1098 = kk_std_core__list_unbox(_box_x2999, NULL);
    _x3532 = _parts_1098; /*list<string>*/
    goto _match3533;
  }
  _x3532 = kk_std_core__new_Nil(_ctx); /*list<string>*/
  _match3533: ;
  return kk_std_os_path__new_Path(_x3528, _x3532, _ctx);
}
 
// Convenience function that adds two strings into a path.

kk_std_os_path__path kk_std_os_path__lp__fs__2_rp_(kk_string_t p1, kk_string_t p2, kk_context_t* _ctx) { /* (p1 : string, p2 : string) -> path */ 
  kk_std_os_path__path p10_2799 = kk_std_os_path_path(p1, _ctx); /*std/os/path/path*/;
  kk_std_os_path__path p20_2800 = kk_std_os_path_path(p2, _ctx); /*std/os/path/path*/;
  kk_std_core_types__optional root_2801;
  kk_box_t _x3535;
  kk_string_t _x3536;
  kk_string_t _x = p10_2799.root;
  kk_string_dup(_x);
  _x3536 = _x; /*string*/
  _x3535 = kk_string_box(_x3536); /*108*/
  root_2801 = kk_std_core_types__new_Optional(_x3535, _ctx); /*optional<string>*/
  kk_std_core_types__optional parts_2802;
  kk_std_core__list _b_3003_3002;
  kk_std_core__list _x3537;
  kk_std_core__list _x3538;
  kk_std_core__list _x0 = p20_2800.parts;
  kk_std_core__list_dup(_x0);
  kk_std_os_path__path_drop(p20_2800, _ctx);
  _x3538 = _x0; /*list<string>*/
  _x3537 = kk_std_core__lift21047_reverse_append(kk_std_core__new_Nil(_ctx), _x3538, _ctx); /*list<2501>*/
  kk_std_core__list _x3539;
  kk_std_core__list _x1 = p10_2799.parts;
  kk_std_core__list_dup(_x1);
  kk_std_os_path__path_drop(p10_2799, _ctx);
  _x3539 = _x1; /*list<string>*/
  _b_3003_3002 = kk_std_os_path_push_parts(_x3537, _x3539, _ctx); /*list<string>*/
  parts_2802 = kk_std_core_types__new_Optional(kk_std_core__list_box(_b_3003_3002, _ctx), _ctx); /*optional<list<string>>*/
  kk_string_t _x3540;
  if (kk_std_core_types__is_Optional(root_2801)) {
    kk_box_t _box_x3004 = root_2801._cons.Optional.value;
    kk_string_t _root_1093 = kk_string_unbox(_box_x3004);
    _x3540 = _root_1093; /*string*/
    goto _match3541;
  }
  _x3540 = kk_string_empty(); /*string*/
  _match3541: ;
  kk_std_core__list _x3544;
  if (kk_std_core_types__is_Optional(parts_2802)) {
    kk_box_t _box_x3005 = parts_2802._cons.Optional.value;
    kk_std_core__list _parts_1098 = kk_std_core__list_unbox(_box_x3005, NULL);
    _x3544 = _parts_1098; /*list<string>*/
    goto _match3545;
  }
  _x3544 = kk_std_core__new_Nil(_ctx); /*list<string>*/
  _match3545: ;
  return kk_std_os_path__new_Path(_x3540, _x3544, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_os_path__mlift2705_app_path_fun3548__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path__mlift2705_app_path_fun3548(kk_function_t _fself, kk_box_t _b_3008, kk_context_t* _ctx);
static kk_function_t kk_std_os_path__new_mlift2705_app_path_fun3548(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path__mlift2705_app_path_fun3548, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_path__mlift2705_app_path_fun3548(kk_function_t _fself, kk_box_t _b_3008, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_os_path__path _x3549;
  kk_string_t _x3550 = kk_string_unbox(_b_3008); /*string*/
  _x3549 = kk_std_os_path_path(_x3550, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x3549, _ctx);
}

kk_std_os_path__path kk_std_os_path__mlift2705_app_path(kk_string_t _y_14, kk_context_t* _ctx) { /* (string) -> io path */ 
  kk_box_t _x3547 = kk_std_core_hnd__open_none1(kk_std_os_path__new_mlift2705_app_path_fun3548(_ctx), kk_string_box(_y_14), _ctx); /*3239*/
  return kk_std_os_path__path_unbox(_x3547, _ctx);
}
 
// Return the path to the currently executing application.


// lift anonymous function
struct kk_std_os_path_app_path_fun3552__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path_app_path_fun3552(kk_function_t _fself, kk_box_t _b_3012, kk_context_t* _ctx);
static kk_function_t kk_std_os_path_new_app_path_fun3552(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path_app_path_fun3552, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_path_app_path_fun3552(kk_function_t _fself, kk_box_t _b_3012, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_os_path__path _x3553;
  kk_string_t _x3554 = kk_string_unbox(_b_3012); /*string*/
  _x3553 = kk_std_os_path__mlift2705_app_path(_x3554, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x3553, _ctx);
}


// lift anonymous function
struct kk_std_os_path_app_path_fun3555__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path_app_path_fun3555(kk_function_t _fself, kk_box_t _b_3015, kk_context_t* _ctx);
static kk_function_t kk_std_os_path_new_app_path_fun3555(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path_app_path_fun3555, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_path_app_path_fun3555(kk_function_t _fself, kk_box_t _b_3015, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_os_path__path _x3556;
  kk_string_t _x3557 = kk_string_unbox(_b_3015); /*string*/
  _x3556 = kk_std_os_path_path(_x3557, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x3556, _ctx);
}

kk_std_os_path__path kk_std_os_path_app_path(kk_context_t* _ctx) { /* () -> io path */ 
  kk_string_t x_2807 = kk_std_os_path_xapp_path(_ctx); /*string*/;
  kk_box_t _x3551;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_2807, _ctx);
    _x3551 = kk_std_core_hnd_yield_extend(kk_std_os_path_new_app_path_fun3552(_ctx), _ctx); /*3991*/
  }
  else {
    _x3551 = kk_std_core_hnd__open_none1(kk_std_os_path_new_app_path_fun3555(_ctx), kk_string_box(x_2807), _ctx); /*3991*/
  }
  return kk_std_os_path__path_unbox(_x3551, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_os_path__mlift2706_appdir_fun3559__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path__mlift2706_appdir_fun3559(kk_function_t _fself, kk_box_t _b_3021, kk_context_t* _ctx);
static kk_function_t kk_std_os_path__new_mlift2706_appdir_fun3559(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path__mlift2706_appdir_fun3559, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_path__mlift2706_appdir_fun3559(kk_function_t _fself, kk_box_t _b_3021, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_os_path__path _x3560;
  kk_std_os_path__path _x3561 = kk_std_os_path__path_unbox(_b_3021, _ctx); /*std/os/path/path*/
  _x3560 = kk_std_os_path_nobase(_x3561, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x3560, _ctx);
}

kk_std_os_path__path kk_std_os_path__mlift2706_appdir(kk_std_os_path__path p, bool _c_16, kk_context_t* _ctx) { /* (p : path, bool) -> path */ 
  if (_c_16) {
    kk_box_t _x3558 = kk_std_core_hnd__open_none1(kk_std_os_path__new_mlift2706_appdir_fun3559(_ctx), kk_std_os_path__path_box(p, _ctx), _ctx); /*3239*/
    return kk_std_os_path__path_unbox(_x3558, _ctx);
  }
  return p;
}
 
// monadic lift


// lift anonymous function
struct kk_std_os_path__mlift2707_appdir_fun3563__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path__mlift2707_appdir_fun3563(kk_function_t _fself, kk_box_t _b_3026, kk_context_t* _ctx);
static kk_function_t kk_std_os_path__new_mlift2707_appdir_fun3563(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path__mlift2707_appdir_fun3563, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_path__mlift2707_appdir_fun3563(kk_function_t _fself, kk_box_t _b_3026, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_os_path__path _x3564;
  kk_std_os_path__path _x3565 = kk_std_os_path__path_unbox(_b_3026, _ctx); /*std/os/path/path*/
  _x3564 = kk_std_os_path_nobase(_x3565, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x3564, _ctx);
}


// lift anonymous function
struct kk_std_os_path__mlift2707_appdir_fun3568__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path__mlift2707_appdir_fun3568(kk_function_t _fself, kk_box_t _b_3031, kk_context_t* _ctx);
static kk_function_t kk_std_os_path__new_mlift2707_appdir_fun3568(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path__mlift2707_appdir_fun3568, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_path__mlift2707_appdir_fun3568(kk_function_t _fself, kk_box_t _b_3031, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x3569;
  kk_std_os_path__path _x3570 = kk_std_os_path__path_unbox(_b_3031, _ctx); /*std/os/path/path*/
  _x3569 = kk_std_os_path_basename(_x3570, _ctx); /*string*/
  return kk_string_box(_x3569);
}


// lift anonymous function
struct kk_std_os_path__mlift2707_appdir_fun3577__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path__mlift2707_appdir_fun3577(kk_function_t _fself, kk_box_t _b_3034, kk_context_t* _ctx);
static kk_function_t kk_std_os_path__new_mlift2707_appdir_fun3577(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path__mlift2707_appdir_fun3577, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_path__mlift2707_appdir_fun3577(kk_function_t _fself, kk_box_t _b_3034, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x3578;
  kk_std_os_path__path _x3579 = kk_std_os_path__path_unbox(_b_3034, _ctx); /*std/os/path/path*/
  _x3578 = kk_std_os_path_basename(_x3579, _ctx); /*string*/
  return kk_string_box(_x3578);
}


// lift anonymous function
struct kk_std_os_path__mlift2707_appdir_fun3585__t {
  struct kk_function_s _base;
  kk_std_os_path__path p;
};
static kk_box_t kk_std_os_path__mlift2707_appdir_fun3585(kk_function_t _fself, kk_box_t _b_3040, kk_context_t* _ctx);
static kk_function_t kk_std_os_path__new_mlift2707_appdir_fun3585(kk_std_os_path__path p, kk_context_t* _ctx) {
  struct kk_std_os_path__mlift2707_appdir_fun3585__t* _self = kk_function_alloc_as(struct kk_std_os_path__mlift2707_appdir_fun3585__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_os_path__mlift2707_appdir_fun3585, kk_context());
  _self->p = p;
  return &_self->_base;
}

static kk_box_t kk_std_os_path__mlift2707_appdir_fun3585(kk_function_t _fself, kk_box_t _b_3040, kk_context_t* _ctx) {
  struct kk_std_os_path__mlift2707_appdir_fun3585__t* _self = kk_function_as(struct kk_std_os_path__mlift2707_appdir_fun3585__t*, _fself);
  kk_std_os_path__path p = _self->p; /* std/os/path/path */
  kk_drop_match(_self, {kk_std_os_path__path_dup(p);}, {}, _ctx)
  kk_std_os_path__path _x3586;
  bool _x3587 = kk_bool_unbox(_b_3040); /*bool*/
  _x3586 = kk_std_os_path__mlift2706_appdir(p, _x3587, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x3586, _ctx);
}

kk_std_os_path__path kk_std_os_path__mlift2707_appdir(kk_std_os_path__path _y_15, kk_context_t* _ctx) { /* (path) -> io path */ 
  kk_std_os_path__path p;
  kk_box_t _x3562 = kk_std_core_hnd__open_none1(kk_std_os_path__new_mlift2707_appdir_fun3563(_ctx), kk_std_os_path__path_box(_y_15, _ctx), _ctx); /*3239*/
  p = kk_std_os_path__path_unbox(_x3562, _ctx); /*std/os/path/path*/
  bool x_2811;
  bool _match_3297;
  kk_string_t _x3566;
  kk_box_t _x3567;
  kk_box_t _x3571;
  kk_std_os_path__path _x3572 = kk_std_os_path__path_dup(p); /*std/os/path/path*/
  _x3571 = kk_std_os_path__path_box(_x3572, _ctx); /*3238*/
  _x3567 = kk_std_core_hnd__open_none1(kk_std_os_path__new_mlift2707_appdir_fun3568(_ctx), _x3571, _ctx); /*3239*/
  _x3566 = kk_string_unbox(_x3567); /*string*/
  kk_string_t _x3573;
  kk_define_string_literal(, _s3574, 3, "bin")
  _x3573 = kk_string_dup(_s3574); /*string*/
  _match_3297 = kk_string_is_eq(_x3566,_x3573,kk_context()); /*bool*/
  if (_match_3297) {
    x_2811 = true; /*bool*/
  }
  else {
    kk_string_t _x3575;
    kk_box_t _x3576;
    kk_box_t _x3580;
    kk_std_os_path__path _x3581 = kk_std_os_path__path_dup(p); /*std/os/path/path*/
    _x3580 = kk_std_os_path__path_box(_x3581, _ctx); /*3238*/
    _x3576 = kk_std_core_hnd__open_none1(kk_std_os_path__new_mlift2707_appdir_fun3577(_ctx), _x3580, _ctx); /*3239*/
    _x3575 = kk_string_unbox(_x3576); /*string*/
    kk_string_t _x3582;
    kk_define_string_literal(, _s3583, 3, "exe")
    _x3582 = kk_string_dup(_s3583); /*string*/
    x_2811 = kk_string_is_eq(_x3575,_x3582,kk_context()); /*bool*/
  }
  if (kk_yielding(kk_context())) {
    kk_box_t _x3584 = kk_std_core_hnd_yield_extend(kk_std_os_path__new_mlift2707_appdir_fun3585(p, _ctx), _ctx); /*3991*/
    return kk_std_os_path__path_unbox(_x3584, _ctx);
  }
  return kk_std_os_path__mlift2706_appdir(p, x_2811, _ctx);
}
 
// Return the base directory that contains the currently running application.
// First tries `app-path().nobase`; if that ends in the ``bin`` or ``exe`` directory it
// returns the parent of that directory.


// lift anonymous function
struct kk_std_os_path_appdir_fun3589__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path_appdir_fun3589(kk_function_t _fself, kk_box_t _b_3044, kk_context_t* _ctx);
static kk_function_t kk_std_os_path_new_appdir_fun3589(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path_appdir_fun3589, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_path_appdir_fun3589(kk_function_t _fself, kk_box_t _b_3044, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_os_path__path _x3590;
  kk_std_os_path__path _x3591 = kk_std_os_path__path_unbox(_b_3044, _ctx); /*std/os/path/path*/
  _x3590 = kk_std_os_path__mlift2707_appdir(_x3591, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x3590, _ctx);
}


// lift anonymous function
struct kk_std_os_path_appdir_fun3593__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path_appdir_fun3593(kk_function_t _fself, kk_box_t _b_3047, kk_context_t* _ctx);
static kk_function_t kk_std_os_path_new_appdir_fun3593(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path_appdir_fun3593, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_path_appdir_fun3593(kk_function_t _fself, kk_box_t _b_3047, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_os_path__path _x3594;
  kk_std_os_path__path _x3595 = kk_std_os_path__path_unbox(_b_3047, _ctx); /*std/os/path/path*/
  _x3594 = kk_std_os_path_nobase(_x3595, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x3594, _ctx);
}


// lift anonymous function
struct kk_std_os_path_appdir_fun3598__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path_appdir_fun3598(kk_function_t _fself, kk_box_t _b_3052, kk_context_t* _ctx);
static kk_function_t kk_std_os_path_new_appdir_fun3598(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path_appdir_fun3598, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_path_appdir_fun3598(kk_function_t _fself, kk_box_t _b_3052, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x3599;
  kk_std_os_path__path _x3600 = kk_std_os_path__path_unbox(_b_3052, _ctx); /*std/os/path/path*/
  _x3599 = kk_std_os_path_basename(_x3600, _ctx); /*string*/
  return kk_string_box(_x3599);
}


// lift anonymous function
struct kk_std_os_path_appdir_fun3607__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path_appdir_fun3607(kk_function_t _fself, kk_box_t _b_3055, kk_context_t* _ctx);
static kk_function_t kk_std_os_path_new_appdir_fun3607(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path_appdir_fun3607, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_path_appdir_fun3607(kk_function_t _fself, kk_box_t _b_3055, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x3608;
  kk_std_os_path__path _x3609 = kk_std_os_path__path_unbox(_b_3055, _ctx); /*std/os/path/path*/
  _x3608 = kk_std_os_path_basename(_x3609, _ctx); /*string*/
  return kk_string_box(_x3608);
}


// lift anonymous function
struct kk_std_os_path_appdir_fun3615__t {
  struct kk_function_s _base;
  kk_std_os_path__path p;
};
static kk_box_t kk_std_os_path_appdir_fun3615(kk_function_t _fself, kk_box_t _b_3061, kk_context_t* _ctx);
static kk_function_t kk_std_os_path_new_appdir_fun3615(kk_std_os_path__path p, kk_context_t* _ctx) {
  struct kk_std_os_path_appdir_fun3615__t* _self = kk_function_alloc_as(struct kk_std_os_path_appdir_fun3615__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_os_path_appdir_fun3615, kk_context());
  _self->p = p;
  return &_self->_base;
}

static kk_box_t kk_std_os_path_appdir_fun3615(kk_function_t _fself, kk_box_t _b_3061, kk_context_t* _ctx) {
  struct kk_std_os_path_appdir_fun3615__t* _self = kk_function_as(struct kk_std_os_path_appdir_fun3615__t*, _fself);
  kk_std_os_path__path p = _self->p; /* std/os/path/path */
  kk_drop_match(_self, {kk_std_os_path__path_dup(p);}, {}, _ctx)
  kk_std_os_path__path _x3616;
  bool _x3617 = kk_bool_unbox(_b_3061); /*bool*/
  _x3616 = kk_std_os_path__mlift2706_appdir(p, _x3617, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x3616, _ctx);
}


// lift anonymous function
struct kk_std_os_path_appdir_fun3619__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path_appdir_fun3619(kk_function_t _fself, kk_box_t _b_3064, kk_context_t* _ctx);
static kk_function_t kk_std_os_path_new_appdir_fun3619(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path_appdir_fun3619, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_path_appdir_fun3619(kk_function_t _fself, kk_box_t _b_3064, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_os_path__path _x3620;
  kk_std_os_path__path _x3621 = kk_std_os_path__path_unbox(_b_3064, _ctx); /*std/os/path/path*/
  _x3620 = kk_std_os_path_nobase(_x3621, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x3620, _ctx);
}

kk_std_os_path__path kk_std_os_path_appdir(kk_context_t* _ctx) { /* () -> io path */ 
  kk_std_os_path__path x_2813 = kk_std_os_path_app_path(_ctx); /*std/os/path/path*/;
  if (kk_yielding(kk_context())) {
    kk_std_os_path__path_drop(x_2813, _ctx);
    kk_box_t _x3588 = kk_std_core_hnd_yield_extend(kk_std_os_path_new_appdir_fun3589(_ctx), _ctx); /*3991*/
    return kk_std_os_path__path_unbox(_x3588, _ctx);
  }
  kk_std_os_path__path p;
  kk_box_t _x3592 = kk_std_core_hnd__open_none1(kk_std_os_path_new_appdir_fun3593(_ctx), kk_std_os_path__path_box(x_2813, _ctx), _ctx); /*3239*/
  p = kk_std_os_path__path_unbox(_x3592, _ctx); /*std/os/path/path*/
  bool x0_2817;
  bool _match_3295;
  kk_string_t _x3596;
  kk_box_t _x3597;
  kk_box_t _x3601;
  kk_std_os_path__path _x3602 = kk_std_os_path__path_dup(p); /*std/os/path/path*/
  _x3601 = kk_std_os_path__path_box(_x3602, _ctx); /*3238*/
  _x3597 = kk_std_core_hnd__open_none1(kk_std_os_path_new_appdir_fun3598(_ctx), _x3601, _ctx); /*3239*/
  _x3596 = kk_string_unbox(_x3597); /*string*/
  kk_string_t _x3603;
  kk_define_string_literal(, _s3604, 3, "bin")
  _x3603 = kk_string_dup(_s3604); /*string*/
  _match_3295 = kk_string_is_eq(_x3596,_x3603,kk_context()); /*bool*/
  if (_match_3295) {
    x0_2817 = true; /*bool*/
  }
  else {
    kk_string_t _x3605;
    kk_box_t _x3606;
    kk_box_t _x3610;
    kk_std_os_path__path _x3611 = kk_std_os_path__path_dup(p); /*std/os/path/path*/
    _x3610 = kk_std_os_path__path_box(_x3611, _ctx); /*3238*/
    _x3606 = kk_std_core_hnd__open_none1(kk_std_os_path_new_appdir_fun3607(_ctx), _x3610, _ctx); /*3239*/
    _x3605 = kk_string_unbox(_x3606); /*string*/
    kk_string_t _x3612;
    kk_define_string_literal(, _s3613, 3, "exe")
    _x3612 = kk_string_dup(_s3613); /*string*/
    x0_2817 = kk_string_is_eq(_x3605,_x3612,kk_context()); /*bool*/
  }
  if (kk_yielding(kk_context())) {
    kk_box_t _x3614 = kk_std_core_hnd_yield_extend(kk_std_os_path_new_appdir_fun3615(p, _ctx), _ctx); /*3991*/
    return kk_std_os_path__path_unbox(_x3614, _ctx);
  }
  if (x0_2817) {
    kk_box_t _x3618 = kk_std_core_hnd__open_none1(kk_std_os_path_new_appdir_fun3619(_ctx), kk_std_os_path__path_box(p, _ctx), _ctx); /*3239*/
    return kk_std_os_path__path_unbox(_x3618, _ctx);
  }
  return p;
}
 
// Change the base name of a path

kk_std_os_path__path kk_std_os_path_change_base(kk_std_os_path__path p, kk_string_t basename0, kk_context_t* _ctx) { /* (p : path, basename : string) -> path */ 
  kk_std_os_path__path q = kk_std_os_path_nobase(p, _ctx); /*std/os/path/path*/;
  kk_std_core_types__optional dirs_2823;
  kk_box_t _x3622;
  kk_std_core__list _x3623;
  kk_std_core__list _x0 = q.parts;
  kk_std_core__list_dup(_x0);
  _x3623 = _x0; /*list<string>*/
  _x3622 = kk_std_core__list_box(_x3623, _ctx); /*108*/
  dirs_2823 = kk_std_core_types__new_Optional(_x3622, _ctx); /*optional<list<string>>*/
  kk_std_core__list parts0;
  kk_std_core__list _x3624;
  kk_vector_t v_21693;
  kk_string_t _x3625;
  kk_define_string_literal(, _s3626, 1, "/")
  _x3625 = kk_string_dup(_s3626); /*string*/
  v_21693 = kk_string_splitv(basename0,_x3625,kk_context()); /*vector<string>*/
  _x3624 = kk_std_core_vlist(v_21693, kk_std_core_types__new_None(_ctx), _ctx); /*list<2154>*/
  kk_std_core__list _x3627;
  if (kk_std_core_types__is_Optional(dirs_2823)) {
    kk_box_t _box_x3072 = dirs_2823._cons.Optional.value;
    kk_std_core__list _dirs_1291 = kk_std_core__list_unbox(_box_x3072, NULL);
    _x3627 = _dirs_1291; /*list<string>*/
    goto _match3628;
  }
  _x3627 = kk_std_core__new_Nil(_ctx); /*list<string>*/
  _match3628: ;
  parts0 = kk_std_os_path_push_parts(_x3624, _x3627, _ctx); /*list<string>*/
  kk_string_t _x3630;
  kk_string_t _x = q.root;
  kk_string_dup(_x);
  kk_std_os_path__path_drop(q, _ctx);
  _x3630 = _x; /*string*/
  return kk_std_os_path__new_Path(_x3630, parts0, _ctx);
}

kk_std_core_types__tuple2_ kk_std_os_path_split_base(kk_string_t basename0, kk_context_t* _ctx) { /* (basename : string) -> (string, string) */ 
  kk_std_core_types__maybe _match_3291;
  size_t i;
  kk_string_t _x3631 = kk_string_dup(basename0); /*string*/
  kk_string_t _x3632;
  kk_define_string_literal(, _s3633, 1, ".")
  _x3632 = kk_string_dup(_s3633); /*string*/
  i = kk_string_last_index_of1(_x3631,_x3632,kk_context()); /*size_t*/
  bool _match_3292 = kk_std_core_is_zero_1(i, _ctx); /*bool*/;
  if (_match_3292) {
    _match_3291 = kk_std_core_types__new_Nothing(_ctx); /*forall<a> maybe<a>*/
  }
  else {
    kk_std_core__sslice _b_3079_3073;
    kk_string_t _x3634 = kk_string_dup(basename0); /*string*/
    size_t _x3635 = kk_std_core_decr_1(i, _ctx); /*size_t*/
    size_t _x3636;
    kk_string_t _x3637;
    kk_define_string_literal(, _s3638, 1, ".")
    _x3637 = kk_string_dup(_s3638); /*string*/
    _x3636 = kk_string_len(_x3637,kk_context()); /*size_t*/
    _b_3079_3073 = kk_std_core__new_Sslice(_x3634, _x3635, _x3636, _ctx); /*sslice*/
    _match_3291 = kk_std_core_types__new_Just(kk_std_core__sslice_box(_b_3079_3073, _ctx), _ctx); /*forall<a> maybe<a>*/
  }
  if (kk_std_core_types__is_Just(_match_3291)) {
    kk_box_t _box_x3074 = _match_3291._cons.Just.value;
    kk_std_core__sslice slice = kk_std_core__sslice_unbox(_box_x3074, NULL);
    kk_string_drop(basename0, _ctx);
    kk_string_t _b_3080_3075;
    kk_std_core__sslice _x3640;
    kk_std_core__sslice _x3641 = kk_std_core__sslice_dup(slice); /*sslice*/
    _x3640 = kk_std_core_before(_x3641, _ctx); /*sslice*/
    _b_3080_3075 = kk_std_core_string_3(_x3640, _ctx); /*string*/
    kk_string_t _b_3081_3076;
    kk_std_core__sslice _x3642 = kk_std_core_after(slice, _ctx); /*sslice*/
    _b_3081_3076 = kk_std_core_string_3(_x3642, _ctx); /*string*/
    return kk_std_core_types__new_dash__lp__comma__rp_(kk_string_box(_b_3080_3075), kk_string_box(_b_3081_3076), _ctx);
  }
  kk_box_t _x3643;
  kk_string_t _x3644 = kk_string_empty(); /*string*/
  _x3643 = kk_string_box(_x3644); /*7*/
  return kk_std_core_types__new_dash__lp__comma__rp_(kk_string_box(basename0), _x3643, _ctx);
}
 
// Change the extension of a path.
// Only adds a dot if the extname does not already start with a dot.

kk_std_os_path__path kk_std_os_path_change_ext(kk_std_os_path__path p, kk_string_t extname0, kk_context_t* _ctx) { /* (p : path, extname : string) -> path */ 
  kk_string_t _match_3286;
  kk_std_core__list _match_3290;
  kk_std_core__list _x = p.parts;
  kk_std_core__list_dup(_x);
  _match_3290 = _x; /*list<string>*/
  if (kk_std_core__is_Cons(_match_3290)) {
    struct kk_std_core_Cons* _con3647 = kk_std_core__as_Cons(_match_3290);
    kk_box_t _box_x3084 = _con3647->head;
    kk_std_core__list _pat0 = _con3647->tail;
    kk_string_t x = kk_string_unbox(_box_x3084);
    if (kk_std_core__list_is_unique(_match_3290)) {
      kk_std_core__list_drop(_pat0, _ctx);
      kk_std_core__list_free(_match_3290);
    }
    else {
      kk_string_dup(x);
      kk_std_core__list_decref(_match_3290, _ctx);
    }
    _match_3286 = x; /*string*/
    goto _match3646;
  }
  _match_3286 = kk_string_empty(); /*string*/
  _match3646: ;
  kk_std_core__list _match_3285;
  kk_std_core__list _x3650;
  kk_std_core__list _x0 = p.parts;
  kk_std_core__list_dup(_x0);
  _x3650 = _x0; /*list<string>*/
  _match_3285 = kk_std_core_tail_1(_x3650, _ctx); /*list<20131>*/
  kk_std_core_types__tuple2_ _match_3287 = kk_std_os_path_split_base(_match_3286, _ctx); /*(string, string)*/;
  kk_box_t _box_x3085 = _match_3287.fst;
  kk_box_t _box_x3086 = _match_3287.snd;
  kk_string_t stemname0 = kk_string_unbox(_box_x3085);
  kk_string_dup(stemname0);
  kk_std_core_types__tuple2__drop(_match_3287, _ctx);
  kk_string_t newext;
  bool _match_3288;
  kk_std_core_types__maybe m_2834;
  bool _match_3289;
  kk_string_t _x3653 = kk_string_dup(extname0); /*string*/
  kk_string_t _x3654;
  kk_define_string_literal(, _s3655, 1, ".")
  _x3654 = kk_string_dup(_s3655); /*string*/
  _match_3289 = kk_string_starts_with(_x3653,_x3654,kk_context()); /*bool*/
  if (_match_3289) {
    kk_std_core__sslice _b_3088_3087;
    kk_string_t _x3656 = kk_string_dup(extname0); /*string*/
    size_t _x3657;
    kk_string_t _x3658;
    kk_define_string_literal(, _s3659, 1, ".")
    _x3658 = kk_string_dup(_s3659); /*string*/
    _x3657 = kk_string_len(_x3658,kk_context()); /*size_t*/
    size_t _x3660;
    size_t _x3661;
    kk_string_t _x3662 = kk_string_dup(extname0); /*string*/
    _x3661 = kk_string_len(_x3662,kk_context()); /*size_t*/
    size_t _x3663;
    kk_string_t _x3664;
    kk_define_string_literal(, _s3665, 1, ".")
    _x3664 = kk_string_dup(_s3665); /*string*/
    _x3663 = kk_string_len(_x3664,kk_context()); /*size_t*/
    _x3660 = (_x3661 - _x3663); /*size_t*/
    _b_3088_3087 = kk_std_core__new_Sslice(_x3656, _x3657, _x3660, _ctx); /*sslice*/
    m_2834 = kk_std_core_types__new_Just(kk_std_core__sslice_box(_b_3088_3087, _ctx), _ctx); /*maybe<sslice>*/
  }
  else {
    m_2834 = kk_std_core_types__new_Nothing(_ctx); /*maybe<sslice>*/
  }
  if (kk_std_core_types__is_Nothing(m_2834)) {
    _match_3288 = false; /*bool*/
  }
  else {
    kk_std_core_types__maybe_drop(m_2834, _ctx);
    _match_3288 = true; /*bool*/
  }
  if (_match_3288) {
    newext = extname0; /*string*/
  }
  else {
    kk_string_t _x3666;
    kk_define_string_literal(, _s3667, 1, ".")
    _x3666 = kk_string_dup(_s3667); /*string*/
    newext = kk_std_core__lp__plus__plus__1_rp_(_x3666, extname0, _ctx); /*string*/
  }
  kk_string_t s0_2838 = kk_std_core__lp__plus__plus__1_rp_(stemname0, newext, _ctx); /*string*/;
  kk_std_core_types__optional dirs0_2839 = kk_std_core_types__new_Optional(kk_std_core__list_box(_match_3285, _ctx), _ctx); /*optional<list<string>>*/;
  kk_std_core__list parts0;
  kk_std_core__list _x3668;
  kk_vector_t v_21693;
  kk_string_t _x3669;
  kk_define_string_literal(, _s3670, 1, "/")
  _x3669 = kk_string_dup(_s3670); /*string*/
  v_21693 = kk_string_splitv(s0_2838,_x3669,kk_context()); /*vector<string>*/
  _x3668 = kk_std_core_vlist(v_21693, kk_std_core_types__new_None(_ctx), _ctx); /*list<2154>*/
  kk_std_core__list _x3671;
  if (kk_std_core_types__is_Optional(dirs0_2839)) {
    kk_box_t _box_x3091 = dirs0_2839._cons.Optional.value;
    kk_std_core__list _dirs_1291 = kk_std_core__list_unbox(_box_x3091, NULL);
    _x3671 = _dirs_1291; /*list<string>*/
    goto _match3672;
  }
  _x3671 = kk_std_core__new_Nil(_ctx); /*list<string>*/
  _match3672: ;
  parts0 = kk_std_os_path_push_parts(_x3668, _x3671, _ctx); /*list<string>*/
  kk_string_t _x3674;
  kk_string_t _x00 = p.root;
  kk_string_dup(_x00);
  kk_std_os_path__path_drop(p, _ctx);
  _x3674 = _x00; /*string*/
  return kk_std_os_path__new_Path(_x3674, parts0, _ctx);
}
 
// Return the extension of path (without the preceding dot (`'.'`))
// `"/foo/bar.svg.txt".path.extname === "txt"`

kk_string_t kk_std_os_path_extname(kk_std_os_path__path p, kk_context_t* _ctx) { /* (p : path) -> string */ 
  kk_std_core_types__tuple2_ _this_2843;
  kk_string_t basename_2844 = kk_std_os_path_basename(p, _ctx); /*string*/;
  kk_std_core_types__maybe _match_3283;
  size_t i;
  kk_string_t _x3675 = kk_string_dup(basename_2844); /*string*/
  kk_string_t _x3676;
  kk_define_string_literal(, _s3677, 1, ".")
  _x3676 = kk_string_dup(_s3677); /*string*/
  i = kk_string_last_index_of1(_x3675,_x3676,kk_context()); /*size_t*/
  bool _match_3284 = kk_std_core_is_zero_1(i, _ctx); /*bool*/;
  if (_match_3284) {
    _match_3283 = kk_std_core_types__new_Nothing(_ctx); /*forall<a> maybe<a>*/
  }
  else {
    kk_std_core__sslice _b_3098_3092;
    kk_string_t _x3678 = kk_string_dup(basename_2844); /*string*/
    size_t _x3679 = kk_std_core_decr_1(i, _ctx); /*size_t*/
    size_t _x3680;
    kk_string_t _x3681;
    kk_define_string_literal(, _s3682, 1, ".")
    _x3681 = kk_string_dup(_s3682); /*string*/
    _x3680 = kk_string_len(_x3681,kk_context()); /*size_t*/
    _b_3098_3092 = kk_std_core__new_Sslice(_x3678, _x3679, _x3680, _ctx); /*sslice*/
    _match_3283 = kk_std_core_types__new_Just(kk_std_core__sslice_box(_b_3098_3092, _ctx), _ctx); /*forall<a> maybe<a>*/
  }
  if (kk_std_core_types__is_Just(_match_3283)) {
    kk_box_t _box_x3093 = _match_3283._cons.Just.value;
    kk_std_core__sslice slice = kk_std_core__sslice_unbox(_box_x3093, NULL);
    kk_string_drop(basename_2844, _ctx);
    kk_string_t _b_3099_3094;
    kk_std_core__sslice _x3685;
    kk_std_core__sslice _x3686 = kk_std_core__sslice_dup(slice); /*sslice*/
    _x3685 = kk_std_core_before(_x3686, _ctx); /*sslice*/
    _b_3099_3094 = kk_std_core_string_3(_x3685, _ctx); /*string*/
    kk_string_t _b_3100_3095;
    kk_std_core__sslice _x3687 = kk_std_core_after(slice, _ctx); /*sslice*/
    _b_3100_3095 = kk_std_core_string_3(_x3687, _ctx); /*string*/
    _this_2843 = kk_std_core_types__new_dash__lp__comma__rp_(kk_string_box(_b_3099_3094), kk_string_box(_b_3100_3095), _ctx); /*(string, string)*/
    goto _match3683;
  }
  kk_box_t _x3688;
  kk_string_t _x3689 = kk_string_empty(); /*string*/
  _x3688 = kk_string_box(_x3689); /*7*/
  _this_2843 = kk_std_core_types__new_dash__lp__comma__rp_(kk_string_box(basename_2844), _x3688, _ctx); /*(string, string)*/
  _match3683: ;
  kk_box_t _box_x3103 = _this_2843.fst;
  kk_box_t _box_x3104 = _this_2843.snd;
  kk_string_t _x = kk_string_unbox(_box_x3104);
  kk_string_dup(_x);
  kk_std_core_types__tuple2__drop(_this_2843, _ctx);
  return _x;
}
 
// Change the stem name of a path

kk_std_os_path__path kk_std_os_path_change_stem(kk_std_os_path__path p, kk_string_t stemname0, kk_context_t* _ctx) { /* (p : path, stemname : string) -> path */ 
  kk_string_t ext;
  kk_std_os_path__path _x3693 = kk_std_os_path__path_dup(p); /*std/os/path/path*/
  ext = kk_std_os_path_extname(_x3693, _ctx); /*string*/
  kk_string_t basename_2848;
  kk_string_t _x3694;
  bool _match_3282;
  kk_string_t _x3695 = kk_string_dup(ext); /*string*/
  _match_3282 = kk_std_core_is_empty_2(_x3695, _ctx); /*bool*/
  if (_match_3282) {
    kk_string_drop(ext, _ctx);
    _x3694 = kk_string_empty(); /*string*/
  }
  else {
    kk_string_t _x3697;
    kk_define_string_literal(, _s3698, 1, ".")
    _x3697 = kk_string_dup(_s3698); /*string*/
    _x3694 = kk_std_core__lp__plus__plus__1_rp_(_x3697, ext, _ctx); /*string*/
  }
  basename_2848 = kk_std_core__lp__plus__plus__1_rp_(stemname0, _x3694, _ctx); /*string*/
  kk_std_os_path__path q = kk_std_os_path_nobase(p, _ctx); /*std/os/path/path*/;
  kk_std_core_types__optional dirs_2851;
  kk_box_t _x3699;
  kk_std_core__list _x3700;
  kk_std_core__list _x0 = q.parts;
  kk_std_core__list_dup(_x0);
  _x3700 = _x0; /*list<string>*/
  _x3699 = kk_std_core__list_box(_x3700, _ctx); /*108*/
  dirs_2851 = kk_std_core_types__new_Optional(_x3699, _ctx); /*optional<list<string>>*/
  kk_std_core__list parts0;
  kk_std_core__list _x3701;
  kk_vector_t v_21693;
  kk_string_t _x3702;
  kk_define_string_literal(, _s3703, 1, "/")
  _x3702 = kk_string_dup(_s3703); /*string*/
  v_21693 = kk_string_splitv(basename_2848,_x3702,kk_context()); /*vector<string>*/
  _x3701 = kk_std_core_vlist(v_21693, kk_std_core_types__new_None(_ctx), _ctx); /*list<2154>*/
  kk_std_core__list _x3704;
  if (kk_std_core_types__is_Optional(dirs_2851)) {
    kk_box_t _box_x3107 = dirs_2851._cons.Optional.value;
    kk_std_core__list _dirs_1291 = kk_std_core__list_unbox(_box_x3107, NULL);
    _x3704 = _dirs_1291; /*list<string>*/
    goto _match3705;
  }
  _x3704 = kk_std_core__new_Nil(_ctx); /*list<string>*/
  _match3705: ;
  parts0 = kk_std_os_path_push_parts(_x3701, _x3704, _ctx); /*list<string>*/
  kk_string_t _x3707;
  kk_string_t _x = q.root;
  kk_string_dup(_x);
  kk_std_os_path__path_drop(q, _ctx);
  _x3707 = _x; /*string*/
  return kk_std_os_path__new_Path(_x3707, parts0, _ctx);
}
 
// Combine multiple paths using `(/)`.


// lift anonymous function
struct kk_std_os_path_combine_fun3720__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path_combine_fun3720(kk_function_t _fself, kk_box_t _b_3114, kk_box_t _b_3115, kk_context_t* _ctx);
static kk_function_t kk_std_os_path_new_combine_fun3720(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path_combine_fun3720, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_path_combine_fun3720(kk_function_t _fself, kk_box_t _b_3114, kk_box_t _b_3115, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_os_path__path _x3721;
  kk_std_os_path__path _x3722 = kk_std_os_path__path_unbox(_b_3114, _ctx); /*std/os/path/path*/
  kk_std_os_path__path _x3723 = kk_std_os_path__path_unbox(_b_3115, _ctx); /*std/os/path/path*/
  _x3721 = kk_std_os_path__lp__fs__rp_(_x3722, _x3723, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x3721, _ctx);
}

kk_std_os_path__path kk_std_os_path_combine(kk_std_core__list ps, kk_context_t* _ctx) { /* (ps : list<path>) -> path */ 
  if (kk_std_core__is_Nil(ps)) {
    kk_string_t _x3708;
    kk_std_core_types__optional _x3709 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/
    if (kk_std_core_types__is_Optional(_x3709)) {
      kk_box_t _box_x3108 = _x3709._cons.Optional.value;
      kk_string_t _root_1093 = kk_string_unbox(_box_x3108);
      _x3708 = _root_1093; /*string*/
      goto _match3710;
    }
    _x3708 = kk_string_empty(); /*string*/
    _match3710: ;
    kk_std_core__list _x3713;
    kk_std_core_types__optional _x3714 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/
    if (kk_std_core_types__is_Optional(_x3714)) {
      kk_box_t _box_x3109 = _x3714._cons.Optional.value;
      kk_std_core__list _parts_1098 = kk_std_core__list_unbox(_box_x3109, NULL);
      _x3713 = _parts_1098; /*list<string>*/
      goto _match3715;
    }
    _x3713 = kk_std_core__new_Nil(_ctx); /*list<string>*/
    _match3715: ;
    return kk_std_os_path__new_Path(_x3708, _x3713, _ctx);
  }
  struct kk_std_core_Cons* _con3717 = kk_std_core__as_Cons(ps);
  kk_box_t _box_x3110 = _con3717->head;
  kk_std_core__list pp = _con3717->tail;
  kk_std_os_path__path p = kk_std_os_path__path_unbox(_box_x3110, NULL);
  if (kk_std_core__list_is_unique(ps)) {
    kk_std_os_path__path_dup(p);
    kk_box_drop(_box_x3110, _ctx);
    kk_std_core__list_free(ps);
  }
  else {
    kk_std_os_path__path_dup(p);
    kk_std_core__list_dup(pp);
    kk_std_core__list_decref(ps, _ctx);
  }
  kk_box_t _x3719 = kk_std_core_foldl(pp, kk_std_os_path__path_box(p, _ctx), kk_std_os_path_new_combine_fun3720(_ctx), _ctx); /*15010*/
  return kk_std_os_path__path_unbox(_x3719, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_os_path__mlift2708_realpath_fun3725__t_1 {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path__mlift2708_realpath_fun3725_1(kk_function_t _fself, kk_box_t _b_3121, kk_context_t* _ctx);
static kk_function_t kk_std_os_path__new_mlift2708_realpath_fun3725_1(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path__mlift2708_realpath_fun3725_1, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_path__mlift2708_realpath_fun3725_1(kk_function_t _fself, kk_box_t _b_3121, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_os_path__path _x3726;
  kk_string_t _x3727 = kk_string_unbox(_b_3121); /*string*/
  _x3726 = kk_std_os_path_path(_x3727, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x3726, _ctx);
}

kk_std_os_path__path kk_std_os_path__mlift2708_realpath_1(kk_string_t _y_18, kk_context_t* _ctx) { /* (string) -> io path */ 
  kk_box_t _x3724 = kk_std_core_hnd__open_none1(kk_std_os_path__new_mlift2708_realpath_fun3725_1(_ctx), kk_string_box(_y_18), _ctx); /*3239*/
  return kk_std_os_path__path_unbox(_x3724, _ctx);
}
 
// Convert a path to the absolute path on the file system.
// The overload on a plain string is necessary as it allows
// for unnormalized paths with `".."` parts. For example
// `"/foo/symlink/../test.txt"` may resolve to `"/bar/test.txt"` if
// ``symlink`` is a symbolic link to a sub directory of `"/bar"`.


// lift anonymous function
struct kk_std_os_path_realpath_fun3729__t_1 {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path_realpath_fun3729_1(kk_function_t _fself, kk_box_t _b_3125, kk_context_t* _ctx);
static kk_function_t kk_std_os_path_new_realpath_fun3729_1(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path_realpath_fun3729_1, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_path_realpath_fun3729_1(kk_function_t _fself, kk_box_t _b_3125, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_os_path__path _x3730;
  kk_string_t _x3731 = kk_string_unbox(_b_3125); /*string*/
  _x3730 = kk_std_os_path__mlift2708_realpath_1(_x3731, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x3730, _ctx);
}


// lift anonymous function
struct kk_std_os_path_realpath_fun3732__t_1 {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path_realpath_fun3732_1(kk_function_t _fself, kk_box_t _b_3128, kk_context_t* _ctx);
static kk_function_t kk_std_os_path_new_realpath_fun3732_1(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path_realpath_fun3732_1, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_path_realpath_fun3732_1(kk_function_t _fself, kk_box_t _b_3128, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_os_path__path _x3733;
  kk_string_t _x3734 = kk_string_unbox(_b_3128); /*string*/
  _x3733 = kk_std_os_path_path(_x3734, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x3733, _ctx);
}

kk_std_os_path__path kk_std_os_path_realpath_1(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> io path */ 
  kk_string_t x_2858 = kk_std_os_path_xrealpath(s, _ctx); /*string*/;
  kk_box_t _x3728;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_2858, _ctx);
    _x3728 = kk_std_core_hnd_yield_extend(kk_std_os_path_new_realpath_fun3729_1(_ctx), _ctx); /*3991*/
  }
  else {
    _x3728 = kk_std_core_hnd__open_none1(kk_std_os_path_new_realpath_fun3732_1(_ctx), kk_string_box(x_2858), _ctx); /*3991*/
  }
  return kk_std_os_path__path_unbox(_x3728, _ctx);
}
 
// Convert a path to the absolute path on the file system.
// The path is not required to exist on disk. However, if it
// exists any permissions and symbolic links are resolved fully.
// `".".realpath` (to get the current working directory)
// `"/foo".realpath` (to resolve the full root, like `"c:/foo"` on windows)


// lift anonymous function
struct kk_std_os_path_realpath_fun3736__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path_realpath_fun3736(kk_function_t _fself, kk_box_t _b_3134, kk_context_t* _ctx);
static kk_function_t kk_std_os_path_new_realpath_fun3736(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path_realpath_fun3736, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_path_realpath_fun3736(kk_function_t _fself, kk_box_t _b_3134, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x3737;
  kk_std_os_path__path _x3738 = kk_std_os_path__path_unbox(_b_3134, _ctx); /*std/os/path/path*/
  _x3737 = kk_std_os_path_string(_x3738, _ctx); /*string*/
  return kk_string_box(_x3737);
}


// lift anonymous function
struct kk_std_os_path_realpath_fun3740__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path_realpath_fun3740(kk_function_t _fself, kk_box_t _b_3138, kk_context_t* _ctx);
static kk_function_t kk_std_os_path_new_realpath_fun3740(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path_realpath_fun3740, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_path_realpath_fun3740(kk_function_t _fself, kk_box_t _b_3138, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_os_path__path _x3741;
  kk_string_t _x3742 = kk_string_unbox(_b_3138); /*string*/
  _x3741 = kk_std_os_path__mlift2708_realpath_1(_x3742, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x3741, _ctx);
}


// lift anonymous function
struct kk_std_os_path_realpath_fun3743__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path_realpath_fun3743(kk_function_t _fself, kk_box_t _b_3141, kk_context_t* _ctx);
static kk_function_t kk_std_os_path_new_realpath_fun3743(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path_realpath_fun3743, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_path_realpath_fun3743(kk_function_t _fself, kk_box_t _b_3141, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_os_path__path _x3744;
  kk_string_t _x3745 = kk_string_unbox(_b_3141); /*string*/
  _x3744 = kk_std_os_path_path(_x3745, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x3744, _ctx);
}

kk_std_os_path__path kk_std_os_path_realpath(kk_std_os_path__path p, kk_context_t* _ctx) { /* (p : path) -> io path */ 
  kk_string_t s_2862;
  kk_box_t _x3735 = kk_std_core_hnd__open_none1(kk_std_os_path_new_realpath_fun3736(_ctx), kk_std_os_path__path_box(p, _ctx), _ctx); /*3239*/
  s_2862 = kk_string_unbox(_x3735); /*string*/
  kk_string_t x_2863 = kk_std_os_path_xrealpath(s_2862, _ctx); /*string*/;
  kk_box_t _x3739;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_2863, _ctx);
    _x3739 = kk_std_core_hnd_yield_extend(kk_std_os_path_new_realpath_fun3740(_ctx), _ctx); /*3991*/
  }
  else {
    _x3739 = kk_std_core_hnd__open_none1(kk_std_os_path_new_realpath_fun3743(_ctx), kk_string_box(x_2863), _ctx); /*3991*/
  }
  return kk_std_os_path__path_unbox(_x3739, _ctx);
}
 
// Returns the current working directory.
// Equal to `".".realpath`.


// lift anonymous function
struct kk_std_os_path_cwd_fun3749__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path_cwd_fun3749(kk_function_t _fself, kk_box_t _b_3146, kk_context_t* _ctx);
static kk_function_t kk_std_os_path_new_cwd_fun3749(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path_cwd_fun3749, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_path_cwd_fun3749(kk_function_t _fself, kk_box_t _b_3146, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_os_path__path _x3750;
  kk_string_t _x3751 = kk_string_unbox(_b_3146); /*string*/
  _x3750 = kk_std_os_path__mlift2708_realpath_1(_x3751, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x3750, _ctx);
}


// lift anonymous function
struct kk_std_os_path_cwd_fun3752__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path_cwd_fun3752(kk_function_t _fself, kk_box_t _b_3149, kk_context_t* _ctx);
static kk_function_t kk_std_os_path_new_cwd_fun3752(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path_cwd_fun3752, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_path_cwd_fun3752(kk_function_t _fself, kk_box_t _b_3149, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_os_path__path _x3753;
  kk_string_t _x3754 = kk_string_unbox(_b_3149); /*string*/
  _x3753 = kk_std_os_path_path(_x3754, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x3753, _ctx);
}

kk_std_os_path__path kk_std_os_path_cwd(kk_context_t* _ctx) { /* () -> io path */ 
  kk_string_t x_2868;
  kk_string_t _x3746;
  kk_define_string_literal(, _s3747, 1, ".")
  _x3746 = kk_string_dup(_s3747); /*string*/
  x_2868 = kk_std_os_path_xrealpath(_x3746, _ctx); /*string*/
  kk_box_t _x3748;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_2868, _ctx);
    _x3748 = kk_std_core_hnd_yield_extend(kk_std_os_path_new_cwd_fun3749(_ctx), _ctx); /*3991*/
  }
  else {
    _x3748 = kk_std_core_hnd__open_none1(kk_std_os_path_new_cwd_fun3752(_ctx), kk_string_box(x_2868), _ctx); /*3991*/
  }
  return kk_std_os_path__path_unbox(_x3748, _ctx);
}
 
// If a path has no extension, set it to the provided one.

kk_std_os_path__path kk_std_os_path_default_ext(kk_std_os_path__path p, kk_string_t newext, kk_context_t* _ctx) { /* (p : path, newext : string) -> path */ 
  bool _match_3276;
  kk_string_t s_2872;
  kk_std_os_path__path _x3755 = kk_std_os_path__path_dup(p); /*std/os/path/path*/
  s_2872 = kk_std_os_path_extname(_x3755, _ctx); /*string*/
  kk_string_t _x3756 = kk_string_empty(); /*string*/
  _match_3276 = kk_string_is_eq(s_2872,_x3756,kk_context()); /*bool*/
  if (_match_3276) {
    return kk_std_os_path_change_ext(p, newext, _ctx);
  }
  kk_string_drop(newext, _ctx);
  return p;
}
 
// monadic lift


// lift anonymous function
struct kk_std_os_path__mlift2709_homedir_fun3759__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path__mlift2709_homedir_fun3759(kk_function_t _fself, kk_box_t _b_3155, kk_context_t* _ctx);
static kk_function_t kk_std_os_path__new_mlift2709_homedir_fun3759(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path__mlift2709_homedir_fun3759, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_path__mlift2709_homedir_fun3759(kk_function_t _fself, kk_box_t _b_3155, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_os_path__path _x3760;
  kk_string_t _x3761 = kk_string_unbox(_b_3155); /*string*/
  _x3760 = kk_std_os_path_path(_x3761, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x3760, _ctx);
}

kk_std_os_path__path kk_std_os_path__mlift2709_homedir(kk_string_t _y_21, kk_context_t* _ctx) { /* (string) -> io path */ 
  kk_box_t _x3758 = kk_std_core_hnd__open_none1(kk_std_os_path__new_mlift2709_homedir_fun3759(_ctx), kk_string_box(_y_21), _ctx); /*3239*/
  return kk_std_os_path__path_unbox(_x3758, _ctx);
}
 
// Return the home directory of the current user.


// lift anonymous function
struct kk_std_os_path_homedir_fun3763__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path_homedir_fun3763(kk_function_t _fself, kk_box_t _b_3159, kk_context_t* _ctx);
static kk_function_t kk_std_os_path_new_homedir_fun3763(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path_homedir_fun3763, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_path_homedir_fun3763(kk_function_t _fself, kk_box_t _b_3159, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_os_path__path _x3764;
  kk_string_t _x3765 = kk_string_unbox(_b_3159); /*string*/
  _x3764 = kk_std_os_path__mlift2709_homedir(_x3765, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x3764, _ctx);
}


// lift anonymous function
struct kk_std_os_path_homedir_fun3766__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path_homedir_fun3766(kk_function_t _fself, kk_box_t _b_3162, kk_context_t* _ctx);
static kk_function_t kk_std_os_path_new_homedir_fun3766(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path_homedir_fun3766, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_path_homedir_fun3766(kk_function_t _fself, kk_box_t _b_3162, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_os_path__path _x3767;
  kk_string_t _x3768 = kk_string_unbox(_b_3162); /*string*/
  _x3767 = kk_std_os_path_path(_x3768, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x3767, _ctx);
}

kk_std_os_path__path kk_std_os_path_homedir(kk_context_t* _ctx) { /* () -> io path */ 
  kk_string_t x_2873 = kk_std_os_path_xhomedir(_ctx); /*string*/;
  kk_box_t _x3762;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_2873, _ctx);
    _x3762 = kk_std_core_hnd_yield_extend(kk_std_os_path_new_homedir_fun3763(_ctx), _ctx); /*3991*/
  }
  else {
    _x3762 = kk_std_core_hnd__open_none1(kk_std_os_path_new_homedir_fun3766(_ctx), kk_string_box(x_2873), _ctx); /*3991*/
  }
  return kk_std_os_path__path_unbox(_x3762, _ctx);
}

kk_std_core__list kk_std_os_path__ctail_paths_collect(kk_std_core__list ps, kk_std_core_types__ctail _acc, kk_context_t* _ctx) { /* (ps : list<string>, ctail<list<path>>) -> list<path> */ 
  kk__tailcall: ;
  if (kk_std_core__is_Cons(ps)) {
    struct kk_std_core_Cons* _con3775 = kk_std_core__as_Cons(ps);
    kk_box_t _box_x3166 = _con3775->head;
    kk_std_core__list _pat0 = _con3775->tail;
    if (kk_std_core__is_Cons(_pat0)) {
      struct kk_std_core_Cons* _con3777 = kk_std_core__as_Cons(_pat0);
      kk_string_t root0 = kk_string_unbox(_box_x3166);
      kk_box_t _box_x3167 = _con3777->head;
      kk_std_core__list rest = _con3777->tail;
      kk_string_t part = kk_string_unbox(_box_x3167);
      bool _match_3271;
      kk_integer_t _x3779;
      kk_string_t _x3780 = kk_string_dup(root0); /*string*/
      _x3779 = kk_std_core_count_1(_x3780, _ctx); /*int*/
      _match_3271 = kk_integer_eq(_x3779,(kk_integer_from_small(1)),kk_context()); /*bool*/
      bool _x3781;
      if (_match_3271) {
        bool _match_3272;
        kk_char_t c_2879;
        kk_std_core_types__maybe m_2880;
        kk_string_t _x3782 = kk_string_dup(root0); /*string*/
        m_2880 = kk_std_core_head_char(_x3782, _ctx); /*maybe<char>*/
        if (kk_std_core_types__is_Nothing(m_2880)) {
          c_2879 = ' '; /*char*/
        }
        else {
          kk_box_t _box_x3168 = m_2880._cons.Just.value;
          kk_char_t x = kk_char_unbox(_box_x3168, NULL);
          c_2879 = x; /*char*/
        }
        bool _match_3274 = kk_std_core_is_lower(c_2879, _ctx); /*bool*/;
        if (_match_3274) {
          _match_3272 = true; /*bool*/
        }
        else {
          _match_3272 = kk_std_core_is_upper(c_2879, _ctx); /*bool*/
        }
        if (_match_3272) {
          bool _match_3273;
          bool _x3784;
          kk_string_t _x3785 = kk_string_dup(part); /*string*/
          _x3784 = kk_std_core_is_empty_2(_x3785, _ctx); /*bool*/
          _match_3273 = !(_x3784); /*bool*/
          if (_match_3273) {
            kk_string_t _x3786;
            kk_define_string_literal(, _s3787, 2, "/\\")
            _x3786 = kk_string_dup(_s3787); /*string*/
            kk_string_t _x3788;
            kk_string_t _x3789 = kk_string_dup(part); /*string*/
            _x3788 = kk_std_core_head_3(_x3789, _ctx); /*string*/
            _x3781 = kk_string_contains(_x3786,_x3788,kk_context()); /*bool*/
          }
          else {
            _x3781 = false; /*bool*/
          }
        }
        else {
          _x3781 = false; /*bool*/
        }
      }
      else {
        _x3781 = false; /*bool*/
      }
      if (_x3781) {
        kk_reuse_t _ru_3265 = kk_reuse_null; /*reuse*/;
        if (kk_std_core__list_is_unique(ps)) {
          if (kk_std_core__list_is_unique(_pat0)) {
            _ru_3265 = (kk_std_core__list_reuse(_pat0));
          }
          else {
            kk_string_dup(part);
            kk_std_core__list_dup(rest);
            kk_std_core__list_decref(_pat0, _ctx);
            _ru_3265 = kk_reuse_null;
          }
          kk_std_core__list_free(ps);
        }
        else {
          kk_string_dup(part);
          kk_std_core__list_dup(rest);
          kk_string_dup(root0);
          _ru_3265 = kk_reuse_null;
          kk_std_core__list_decref(ps, _ctx);
        }
        kk_std_os_path__path _ctail_2683;
        kk_string_t _x3790;
        kk_string_t _x3791;
        kk_string_t _x3792;
        kk_define_string_literal(, _s3793, 1, ":")
        _x3792 = kk_string_dup(_s3793); /*string*/
        _x3791 = kk_std_core__lp__plus__plus__1_rp_(_x3792, part, _ctx); /*string*/
        _x3790 = kk_std_core__lp__plus__plus__1_rp_(root0, _x3791, _ctx); /*string*/
        _ctail_2683 = kk_std_os_path_path(_x3790, _ctx); /*std/os/path/path*/
        kk_std_core__list _ctail_2684 = kk_std_core__list_hole(); /*list<std/os/path/path>*/;
        kk_std_core__list _ctail_2685 = kk_std_core__new_Cons(_ru_3265, kk_std_os_path__path_box(_ctail_2683, _ctx), _ctail_2684, _ctx); /*list<std/os/path/path>*/;
        { // tailcall
          kk_std_core_types__ctail _x3794;
          kk_box_t* field_2884 = (kk_box_t*)((&kk_std_core__as_Cons(_ctail_2685)->tail)); /*cfield<list<std/os/path/path>>*/;
          if (kk_std_core_types__is_CTail(_acc)) {
            kk_box_t _box_x3179 = _acc._cons.CTail._field1;
            kk_box_t* last = _acc._cons.CTail._field2;
            kk_std_core__list head = kk_std_core__list_unbox(_box_x3179, NULL);
            kk_unit_t __ = kk_Unit;
            *(last) = kk_std_core__list_box(_ctail_2685, _ctx);
            _x3794 = kk_std_core_types__new_CTail(kk_std_core__list_box(head, _ctx), field_2884, _ctx); /*ctail<58>*/
            goto _match3795;
          }
          _x3794 = kk_std_core_types__new_CTail(kk_std_core__list_box(_ctail_2685, _ctx), field_2884, _ctx); /*ctail<58>*/
          _match3795: ;
          ps = rest;
          _acc = _x3794;
          goto kk__tailcall;
        }
      }
    }
  }
  if (kk_std_core__is_Cons(ps)) {
    struct kk_std_core_Cons* _con3797 = kk_std_core__as_Cons(ps);
    kk_box_t _box_x3188 = _con3797->head;
    kk_std_core__list rest0 = _con3797->tail;
    kk_string_t part0 = kk_string_unbox(_box_x3188);
    kk_reuse_t _ru_3266 = kk_reuse_null; /*reuse*/;
    if (kk_std_core__list_is_unique(ps)) {
      _ru_3266 = (kk_std_core__list_reuse(ps));
    }
    else {
      kk_string_dup(part0);
      kk_std_core__list_dup(rest0);
      kk_std_core__list_decref(ps, _ctx);
      _ru_3266 = kk_reuse_null;
    }
    kk_std_os_path__path _ctail_2686 = kk_std_os_path_path(part0, _ctx); /*std/os/path/path*/;
    kk_std_core__list _ctail_2687 = kk_std_core__list_hole(); /*list<std/os/path/path>*/;
    kk_std_core__list _ctail_2688 = kk_std_core__new_Cons(_ru_3266, kk_std_os_path__path_box(_ctail_2686, _ctx), _ctail_2687, _ctx); /*list<std/os/path/path>*/;
    { // tailcall
      kk_std_core_types__ctail _x3799;
      kk_box_t* field0_2887 = (kk_box_t*)((&kk_std_core__as_Cons(_ctail_2688)->tail)); /*cfield<list<std/os/path/path>>*/;
      if (kk_std_core_types__is_CTail(_acc)) {
        kk_box_t _box_x3199 = _acc._cons.CTail._field1;
        kk_box_t* last0 = _acc._cons.CTail._field2;
        kk_std_core__list head0 = kk_std_core__list_unbox(_box_x3199, NULL);
        kk_unit_t __0 = kk_Unit;
        *(last0) = kk_std_core__list_box(_ctail_2688, _ctx);
        _x3799 = kk_std_core_types__new_CTail(kk_std_core__list_box(head0, _ctx), field0_2887, _ctx); /*ctail<58>*/
        goto _match3800;
      }
      _x3799 = kk_std_core_types__new_CTail(kk_std_core__list_box(_ctail_2688, _ctx), field0_2887, _ctx); /*ctail<58>*/
      _match3800: ;
      ps = rest0;
      _acc = _x3799;
      goto kk__tailcall;
    }
  }
  if (kk_std_core_types__is_CTail(_acc)) {
    kk_box_t _box_x3208 = _acc._cons.CTail._field1;
    kk_box_t* last1 = _acc._cons.CTail._field2;
    kk_std_core__list head1 = kk_std_core__list_unbox(_box_x3208, NULL);
    kk_unit_t __1 = kk_Unit;
    *(last1) = kk_std_core__list_box(kk_std_core__new_Nil(_ctx), _ctx);
    return head1;
  }
  return kk_std_core__new_Nil(_ctx);
}

kk_std_core__list kk_std_os_path_paths_collect(kk_std_core__list ps0, kk_context_t* _ctx) { /* (ps : list<string>) -> list<path> */ 
  return kk_std_os_path__ctail_paths_collect(ps0, kk_std_core_types__new_CTailNil(_ctx), _ctx);
}
 
// Show a path as a string.


// lift anonymous function
struct kk_std_os_path_show_fun3814__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path_show_fun3814(kk_function_t _fself, kk_box_t _b_3223, kk_context_t* _ctx);
static kk_function_t kk_std_os_path_new_show_fun3814(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path_show_fun3814, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_path_show_fun3814(kk_function_t _fself, kk_box_t _b_3223, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x3815;
  kk_char_t _x3816 = kk_char_unbox(_b_3223, _ctx); /*char*/
  _x3815 = kk_std_core_show_char(_x3816, _ctx); /*string*/
  return kk_string_box(_x3815);
}

kk_string_t kk_std_os_path_show(kk_std_os_path__path p, kk_context_t* _ctx) { /* (p : path) -> string */ 
  kk_string_t s_2892 = kk_std_os_path_string(p, _ctx); /*string*/;
  kk_string_t _x3810;
  kk_define_string_literal(, _s3811, 1, "\"")
  _x3810 = kk_string_dup(_s3811); /*string*/
  kk_string_t _x3812;
  kk_string_t _x3813;
  kk_std_core__list xs_21467;
  kk_std_core__list _b_3224_3221 = kk_std_core_list_4(s_2892, _ctx); /*list<char>*/;
  xs_21467 = kk_std_core_map_5(_b_3224_3221, kk_std_os_path_new_show_fun3814(_ctx), _ctx); /*list<string>*/
  if (kk_std_core__is_Nil(xs_21467)) {
    _x3813 = kk_string_empty(); /*string*/
  }
  else {
    struct kk_std_core_Cons* _con3818 = kk_std_core__as_Cons(xs_21467);
    kk_box_t _box_x3226 = _con3818->head;
    kk_std_core__list xx = _con3818->tail;
    kk_string_t x = kk_string_unbox(_box_x3226);
    if (kk_std_core__list_is_unique(xs_21467)) {
      kk_std_core__list_free(xs_21467);
    }
    else {
      kk_string_dup(x);
      kk_std_core__list_dup(xx);
      kk_std_core__list_decref(xs_21467, _ctx);
    }
    kk_string_t _x3820 = kk_string_empty(); /*string*/
    _x3813 = kk_std_core__lift21050_joinsep(_x3820, xx, x, _ctx); /*string*/
  }
  kk_string_t _x3822;
  kk_define_string_literal(, _s3823, 1, "\"")
  _x3822 = kk_string_dup(_s3823); /*string*/
  _x3812 = kk_std_core__lp__plus__plus__1_rp_(_x3813, _x3822, _ctx); /*string*/
  return kk_std_core__lp__plus__plus__1_rp_(_x3810, _x3812, _ctx);
}
 
// Return the stem name of path.
// `"/foo/bar.svg.txt".path.extname === "foo.svg"`

kk_string_t kk_std_os_path_stemname(kk_std_os_path__path p, kk_context_t* _ctx) { /* (p : path) -> string */ 
  kk_std_core_types__tuple2_ _this_2893;
  kk_string_t basename_2894 = kk_std_os_path_basename(p, _ctx); /*string*/;
  kk_std_core_types__maybe _match_3269;
  size_t i;
  kk_string_t _x3824 = kk_string_dup(basename_2894); /*string*/
  kk_string_t _x3825;
  kk_define_string_literal(, _s3826, 1, ".")
  _x3825 = kk_string_dup(_s3826); /*string*/
  i = kk_string_last_index_of1(_x3824,_x3825,kk_context()); /*size_t*/
  bool _match_3270 = kk_std_core_is_zero_1(i, _ctx); /*bool*/;
  if (_match_3270) {
    _match_3269 = kk_std_core_types__new_Nothing(_ctx); /*forall<a> maybe<a>*/
  }
  else {
    kk_std_core__sslice _b_3233_3227;
    kk_string_t _x3827 = kk_string_dup(basename_2894); /*string*/
    size_t _x3828 = kk_std_core_decr_1(i, _ctx); /*size_t*/
    size_t _x3829;
    kk_string_t _x3830;
    kk_define_string_literal(, _s3831, 1, ".")
    _x3830 = kk_string_dup(_s3831); /*string*/
    _x3829 = kk_string_len(_x3830,kk_context()); /*size_t*/
    _b_3233_3227 = kk_std_core__new_Sslice(_x3827, _x3828, _x3829, _ctx); /*sslice*/
    _match_3269 = kk_std_core_types__new_Just(kk_std_core__sslice_box(_b_3233_3227, _ctx), _ctx); /*forall<a> maybe<a>*/
  }
  if (kk_std_core_types__is_Just(_match_3269)) {
    kk_box_t _box_x3228 = _match_3269._cons.Just.value;
    kk_std_core__sslice slice = kk_std_core__sslice_unbox(_box_x3228, NULL);
    kk_string_drop(basename_2894, _ctx);
    kk_string_t _b_3234_3229;
    kk_std_core__sslice _x3834;
    kk_std_core__sslice _x3835 = kk_std_core__sslice_dup(slice); /*sslice*/
    _x3834 = kk_std_core_before(_x3835, _ctx); /*sslice*/
    _b_3234_3229 = kk_std_core_string_3(_x3834, _ctx); /*string*/
    kk_string_t _b_3235_3230;
    kk_std_core__sslice _x3836 = kk_std_core_after(slice, _ctx); /*sslice*/
    _b_3235_3230 = kk_std_core_string_3(_x3836, _ctx); /*string*/
    _this_2893 = kk_std_core_types__new_dash__lp__comma__rp_(kk_string_box(_b_3234_3229), kk_string_box(_b_3235_3230), _ctx); /*(string, string)*/
    goto _match3832;
  }
  kk_box_t _x3837;
  kk_string_t _x3838 = kk_string_empty(); /*string*/
  _x3837 = kk_string_box(_x3838); /*7*/
  _this_2893 = kk_std_core_types__new_dash__lp__comma__rp_(kk_string_box(basename_2894), _x3837, _ctx); /*(string, string)*/
  _match3832: ;
  kk_box_t _box_x3238 = _this_2893.fst;
  kk_box_t _box_x3239 = _this_2893.snd;
  kk_string_t _x = kk_string_unbox(_box_x3238);
  kk_string_dup(_x);
  kk_std_core_types__tuple2__drop(_this_2893, _ctx);
  return _x;
}
 
// monadic lift


// lift anonymous function
struct kk_std_os_path__mlift2710_tempdir_fun3843__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path__mlift2710_tempdir_fun3843(kk_function_t _fself, kk_box_t _b_3242, kk_context_t* _ctx);
static kk_function_t kk_std_os_path__new_mlift2710_tempdir_fun3843(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path__mlift2710_tempdir_fun3843, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_path__mlift2710_tempdir_fun3843(kk_function_t _fself, kk_box_t _b_3242, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_os_path__path _x3844;
  kk_string_t _x3845 = kk_string_unbox(_b_3242); /*string*/
  _x3844 = kk_std_os_path_path(_x3845, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x3844, _ctx);
}

kk_std_os_path__path kk_std_os_path__mlift2710_tempdir(kk_string_t _y_22, kk_context_t* _ctx) { /* (string) -> io path */ 
  kk_box_t _x3842 = kk_std_core_hnd__open_none1(kk_std_os_path__new_mlift2710_tempdir_fun3843(_ctx), kk_string_box(_y_22), _ctx); /*3239*/
  return kk_std_os_path__path_unbox(_x3842, _ctx);
}
 
// Return the temporary directory for the current user.


// lift anonymous function
struct kk_std_os_path_tempdir_fun3847__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path_tempdir_fun3847(kk_function_t _fself, kk_box_t _b_3246, kk_context_t* _ctx);
static kk_function_t kk_std_os_path_new_tempdir_fun3847(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path_tempdir_fun3847, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_path_tempdir_fun3847(kk_function_t _fself, kk_box_t _b_3246, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_os_path__path _x3848;
  kk_string_t _x3849 = kk_string_unbox(_b_3246); /*string*/
  _x3848 = kk_std_os_path__mlift2710_tempdir(_x3849, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x3848, _ctx);
}


// lift anonymous function
struct kk_std_os_path_tempdir_fun3850__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path_tempdir_fun3850(kk_function_t _fself, kk_box_t _b_3249, kk_context_t* _ctx);
static kk_function_t kk_std_os_path_new_tempdir_fun3850(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path_tempdir_fun3850, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_path_tempdir_fun3850(kk_function_t _fself, kk_box_t _b_3249, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_os_path__path _x3851;
  kk_string_t _x3852 = kk_string_unbox(_b_3249); /*string*/
  _x3851 = kk_std_os_path_path(_x3852, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x3851, _ctx);
}

kk_std_os_path__path kk_std_os_path_tempdir(kk_context_t* _ctx) { /* () -> io path */ 
  kk_string_t x_2897 = kk_std_os_path_xtempdir(_ctx); /*string*/;
  kk_box_t _x3846;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_2897, _ctx);
    _x3846 = kk_std_core_hnd_yield_extend(kk_std_os_path_new_tempdir_fun3847(_ctx), _ctx); /*3991*/
  }
  else {
    _x3846 = kk_std_core_hnd__open_none1(kk_std_os_path_new_tempdir_fun3850(_ctx), kk_string_box(x_2897), _ctx); /*3991*/
  }
  return kk_std_os_path__path_unbox(_x3846, _ctx);
}

// initialization
void kk_std_os_path__init(kk_context_t* _ctx){
  static bool _initialized = false;
  if (_initialized) return;
  _initialized = true;
  kk_std_core_types__init(_ctx);
  kk_std_core_hnd__init(_ctx);
  kk_std_core__init(_ctx);
  kk_std_text_parse__init(_ctx);
}
