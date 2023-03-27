// Koka generated module: "std/os/path", koka version: 2.1.3
#include "std_os_path.h"

kk_std_os_path__path kk_std_os_path__copy(kk_std_os_path__path _this, kk_std_core_types__optional root0, kk_std_core_types__optional parts0, kk_context_t* _ctx) { /* (path, root : optional<string>, parts : optional<list<string>>) -> path */ 
  kk_string_t _x3318;
  if (kk_std_core_types__is_Optional(root0)) {
    kk_box_t _box_x2905 = root0._cons.Optional.value;
    kk_string_t _root_105 = kk_string_unbox(_box_x2905);
    kk_string_dup(_root_105);
    kk_std_core_types__optional_drop(root0, _ctx);
    _x3318 = _root_105; /*string*/
    goto _match3319;
  }
  kk_string_t _x = _this.root;
  kk_string_dup(_x);
  _x3318 = _x; /*string*/
  _match3319: ;
  kk_std_core__list _x3321;
  if (kk_std_core_types__is_Optional(parts0)) {
    kk_box_t _box_x2906 = parts0._cons.Optional.value;
    kk_std_core__list _parts_111 = kk_std_core__list_unbox(_box_x2906, NULL);
    kk_std_core__list_dup(_parts_111);
    kk_std_core_types__optional_drop(parts0, _ctx);
    kk_std_os_path__path_drop(_this, _ctx);
    _x3321 = _parts_111; /*list<string>*/
    goto _match3322;
  }
  kk_std_core__list _x0 = _this.parts;
  kk_std_core__list_dup(_x0);
  kk_std_os_path__path_drop(_this, _ctx);
  _x3321 = _x0; /*list<string>*/
  _match3322: ;
  return kk_std_os_path__new_Path(_x3318, _x3321, _ctx);
}

kk_string_t kk_std_os_path_xapp_path(kk_context_t* _ctx) { /* () -> io string */ 
  return kk_os_app_path(kk_context());
}
 
// Return the base name of a path (stem name + extension)
// `"/foo/bar.txt".path.basename === "bar.txt"`
// `"/foo".path.basename === "foo"`

kk_string_t kk_std_os_path_basename(kk_std_os_path__path p, kk_context_t* _ctx) { /* (p : path) -> string */ 
  kk_std_core__list _match_3317;
  kk_std_core__list _x = p.parts;
  kk_std_core__list_dup(_x);
  kk_std_os_path__path_drop(p, _ctx);
  _match_3317 = _x; /*list<string>*/
  if (kk_std_core__is_Cons(_match_3317)) {
    struct kk_std_core_Cons* _con3324 = kk_std_core__as_Cons(_match_3317);
    kk_box_t _box_x2907 = _con3324->head;
    kk_std_core__list _pat0 = _con3324->tail;
    kk_string_t x = kk_string_unbox(_box_x2907);
    if (kk_std_core__list_is_unique(_match_3317)) {
      kk_std_core__list_drop(_pat0, _ctx);
      kk_std_core__list_free(_match_3317);
    }
    else {
      kk_string_dup(x);
      kk_std_core__list_decref(_match_3317, _ctx);
    }
    return x;
  }
  return kk_string_empty();
}
 
// Remove the basename and only keep the root and directory name portion of the path.
// `nobase("foo/bar.ext".path) == "foo")`

kk_std_os_path__path kk_std_os_path_nobase(kk_std_os_path__path p, kk_context_t* _ctx) { /* (p : path) -> path */ 
  kk_std_core_types__optional _arg_249;
  kk_box_t _x3327;
  kk_std_core__list _x3328;
  kk_std_core__list _match_3316;
  kk_std_core__list _x = p.parts;
  kk_std_core__list_dup(_x);
  _match_3316 = _x; /*list<string>*/
  if (kk_std_core__is_Cons(_match_3316)) {
    struct kk_std_core_Cons* _con3330 = kk_std_core__as_Cons(_match_3316);
    kk_box_t _box_x2908 = _con3330->head;
    kk_std_core__list xx = _con3330->tail;
    if (kk_std_core__list_is_unique(_match_3316)) {
      kk_box_drop(_box_x2908, _ctx);
      kk_std_core__list_free(_match_3316);
    }
    else {
      kk_std_core__list_dup(xx);
      kk_std_core__list_decref(_match_3316, _ctx);
    }
    _x3328 = xx; /*list<string>*/
    goto _match3329;
  }
  _x3328 = kk_std_core__new_Nil(_ctx); /*list<string>*/
  _match3329: ;
  _x3327 = kk_std_core__list_box(_x3328, _ctx); /*108*/
  _arg_249 = kk_std_core_types__new_Optional(_x3327, _ctx); /*optional<list<string>>*/
  kk_string_t _x3332;
  kk_std_core_types__optional _match_3315 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
  if (kk_std_core_types__is_Optional(_match_3315)) {
    kk_box_t _box_x2911 = _match_3315._cons.Optional.value;
    kk_string_t _root_105 = kk_string_unbox(_box_x2911);
    kk_string_dup(_root_105);
    kk_std_core_types__optional_drop(_match_3315, _ctx);
    _x3332 = _root_105; /*string*/
    goto _match3333;
  }
  kk_string_t _x0 = p.root;
  kk_string_dup(_x0);
  _x3332 = _x0; /*string*/
  _match3333: ;
  kk_std_core__list _x3335;
  if (kk_std_core_types__is_Optional(_arg_249)) {
    kk_box_t _box_x2912 = _arg_249._cons.Optional.value;
    kk_std_core__list _parts_111 = kk_std_core__list_unbox(_box_x2912, NULL);
    kk_std_os_path__path_drop(p, _ctx);
    kk_std_core__list_dup(_parts_111);
    kk_std_core_types__optional_drop(_arg_249, _ctx);
    _x3335 = _parts_111; /*list<string>*/
    goto _match3336;
  }
  kk_std_core__list _x1 = p.parts;
  kk_std_core__list_dup(_x1);
  kk_std_os_path__path_drop(p, _ctx);
  _x3335 = _x1; /*list<string>*/
  _match3336: ;
  return kk_std_os_path__new_Path(_x3332, _x3335, _ctx);
}

kk_std_core_types__tuple2_ kk_std_os_path_split_parts(kk_std_core__list parts0, kk_context_t* _ctx) { /* (parts : list<string>) -> (string, list<string>) */ 
  kk_std_core__list _b_2917_2915;
  kk_std_core__list _x3338 = kk_std_core__list_dup(parts0); /*list<string>*/
  _b_2917_2915 = kk_std_core_tail_1(_x3338, _ctx); /*list<string>*/
  kk_box_t _x3339;
  kk_string_t _x3340;
  if (kk_std_core__is_Cons(parts0)) {
    struct kk_std_core_Cons* _con3342 = kk_std_core__as_Cons(parts0);
    kk_box_t _box_x2913 = _con3342->head;
    kk_std_core__list _pat0 = _con3342->tail;
    kk_string_t x = kk_string_unbox(_box_x2913);
    if (kk_std_core__list_is_unique(parts0)) {
      kk_std_core__list_drop(_pat0, _ctx);
      kk_std_core__list_free(parts0);
    }
    else {
      kk_string_dup(x);
      kk_std_core__list_decref(parts0, _ctx);
    }
    _x3340 = x; /*string*/
    goto _match3341;
  }
  _x3340 = kk_string_empty(); /*string*/
  _match3341: ;
  _x3339 = kk_string_box(_x3340); /*6*/
  return kk_std_core_types__new_dash__lp__comma__rp_(_x3339, kk_std_core__list_box(_b_2917_2915, _ctx), _ctx);
}

kk_string_t kk_std_os_path_xrealpath(kk_string_t p, kk_context_t* _ctx) { /* (p : string) -> io string */ 
  return kk_os_realpath(p,kk_context());
}
 
// Return the directory part of a path (including the rootname)
// `"/foo/bar.txt".path.dirname === "/foo"`
// `"/foo".path.dirname === "/"`

kk_string_t kk_std_os_path_dirname(kk_std_os_path__path p, kk_context_t* _ctx) { /* (p : path) -> string */ 
  kk_string_t _x3345;
  kk_string_t _x = p.root;
  kk_string_dup(_x);
  _x3345 = _x; /*string*/
  kk_string_t _x3346;
  kk_std_core__list xs_2726;
  kk_std_core__list _x3347;
  kk_std_core__list _match_3314;
  kk_std_core__list _x0 = p.parts;
  kk_std_core__list_dup(_x0);
  kk_std_os_path__path_drop(p, _ctx);
  _match_3314 = _x0; /*list<string>*/
  if (kk_std_core__is_Cons(_match_3314)) {
    struct kk_std_core_Cons* _con3349 = kk_std_core__as_Cons(_match_3314);
    kk_box_t _box_x2918 = _con3349->head;
    kk_std_core__list xx = _con3349->tail;
    if (kk_std_core__list_is_unique(_match_3314)) {
      kk_box_drop(_box_x2918, _ctx);
      kk_std_core__list_free(_match_3314);
    }
    else {
      kk_std_core__list_dup(xx);
      kk_std_core__list_decref(_match_3314, _ctx);
    }
    _x3347 = xx; /*list<string>*/
    goto _match3348;
  }
  _x3347 = kk_std_core__new_Nil(_ctx); /*list<string>*/
  _match3348: ;
  xs_2726 = kk_std_core__lift21047_reverse_append(kk_std_core__new_Nil(_ctx), _x3347, _ctx); /*list<string>*/
  if (kk_std_core__is_Nil(xs_2726)) {
    _x3346 = kk_string_empty(); /*string*/
  }
  else {
    struct kk_std_core_Cons* _con3352 = kk_std_core__as_Cons(xs_2726);
    kk_box_t _box_x2919 = _con3352->head;
    kk_std_core__list xx0 = _con3352->tail;
    kk_string_t x = kk_string_unbox(_box_x2919);
    if (kk_std_core__list_is_unique(xs_2726)) {
      kk_std_core__list_free(xs_2726);
    }
    else {
      kk_string_dup(x);
      kk_std_core__list_dup(xx0);
      kk_std_core__list_decref(xs_2726, _ctx);
    }
    kk_string_t _x3354;
    kk_define_string_literal(, _s3355, 1, "/")
    _x3354 = kk_string_dup(_s3355); /*string*/
    _x3346 = kk_std_core__lift21050_joinsep(_x3354, xx0, x, _ctx); /*string*/
  }
  return kk_std_core__lp__plus__plus__1_rp_(_x3345, _x3346, _ctx);
}

kk_string_t kk_std_os_path_xhomedir(kk_context_t* _ctx) { /* () -> io string */ 
  return kk_os_home_dir(kk_context());
}
 
// Remove the directory and root and only keep the base name (file name) portion of the path.
// `nodir("foo/bar.ext".path) === "bar.ext"`

kk_std_os_path__path kk_std_os_path_nodir(kk_std_os_path__path p, kk_context_t* _ctx) { /* (p : path) -> path */ 
  kk_std_core_types__optional root_2734;
  kk_box_t _x3357;
  kk_string_t _x3358 = kk_string_empty(); /*string*/
  _x3357 = kk_string_box(_x3358); /*108*/
  root_2734 = kk_std_core_types__new_Optional(_x3357, _ctx); /*optional<string>*/
  kk_std_core_types__optional parts_2735;
  kk_std_core__list _b_2923_2922;
  kk_std_core__list _x3360;
  kk_std_core__list _x1 = p.parts;
  kk_std_core__list_dup(_x1);
  _x3360 = _x1; /*list<string>*/
  _b_2923_2922 = kk_std_core_take(_x3360, kk_integer_from_small(1), _ctx); /*list<string>*/
  parts_2735 = kk_std_core_types__new_Optional(kk_std_core__list_box(_b_2923_2922, _ctx), _ctx); /*optional<list<string>>*/
  kk_string_t _x3361;
  if (kk_std_core_types__is_Optional(root_2734)) {
    kk_box_t _box_x2924 = root_2734._cons.Optional.value;
    kk_string_t _root_105 = kk_string_unbox(_box_x2924);
    kk_string_dup(_root_105);
    kk_std_core_types__optional_drop(root_2734, _ctx);
    _x3361 = _root_105; /*string*/
    goto _match3362;
  }
  kk_string_t _x = p.root;
  kk_string_dup(_x);
  _x3361 = _x; /*string*/
  _match3362: ;
  kk_std_core__list _x3364;
  if (kk_std_core_types__is_Optional(parts_2735)) {
    kk_box_t _box_x2925 = parts_2735._cons.Optional.value;
    kk_std_core__list _parts_111 = kk_std_core__list_unbox(_box_x2925, NULL);
    kk_std_core__list_dup(_parts_111);
    kk_std_core_types__optional_drop(parts_2735, _ctx);
    kk_std_os_path__path_drop(p, _ctx);
    _x3364 = _parts_111; /*list<string>*/
    goto _match3365;
  }
  kk_std_core__list _x0 = p.parts;
  kk_std_core__list_dup(_x0);
  kk_std_os_path__path_drop(p, _ctx);
  _x3364 = _x0; /*list<string>*/
  _match3365: ;
  return kk_std_os_path__new_Path(_x3361, _x3364, _ctx);
}
 
// Return the last directory component name (or the empty string).
// `"c:/foo/bar/tst.txt".path.parentname === "bar"

kk_string_t kk_std_os_path_parentname(kk_std_os_path__path p, kk_context_t* _ctx) { /* (p : path) -> string */ 
  kk_std_core__list _match_3312;
  kk_std_core__list _match_3313;
  kk_std_core__list _x = p.parts;
  kk_std_core__list_dup(_x);
  kk_std_os_path__path_drop(p, _ctx);
  _match_3313 = _x; /*list<string>*/
  if (kk_std_core__is_Cons(_match_3313)) {
    struct kk_std_core_Cons* _con3368 = kk_std_core__as_Cons(_match_3313);
    kk_box_t _box_x2926 = _con3368->head;
    kk_std_core__list xx = _con3368->tail;
    if (kk_std_core__list_is_unique(_match_3313)) {
      kk_box_drop(_box_x2926, _ctx);
      kk_std_core__list_free(_match_3313);
    }
    else {
      kk_std_core__list_dup(xx);
      kk_std_core__list_decref(_match_3313, _ctx);
    }
    _match_3312 = xx; /*list<string>*/
    goto _match3367;
  }
  _match_3312 = kk_std_core__new_Nil(_ctx); /*list<string>*/
  _match3367: ;
  if (kk_std_core__is_Cons(_match_3312)) {
    struct kk_std_core_Cons* _con3370 = kk_std_core__as_Cons(_match_3312);
    kk_box_t _box_x2927 = _con3370->head;
    kk_std_core__list _pat0 = _con3370->tail;
    kk_string_t x = kk_string_unbox(_box_x2927);
    if (kk_std_core__list_is_unique(_match_3312)) {
      kk_std_core__list_drop(_pat0, _ctx);
      kk_std_core__list_free(_match_3312);
    }
    else {
      kk_string_dup(x);
      kk_std_core__list_decref(_match_3312, _ctx);
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
  bool _match_3310;
  kk_string_t _x3373;
  kk_string_t _x = p.root;
  kk_string_dup(_x);
  _x3373 = _x; /*string*/
  kk_string_t _x3374 = kk_string_empty(); /*string*/
  _match_3310 = kk_string_is_eq(_x3373,_x3374,kk_context()); /*bool*/
  if (_match_3310) {
    kk_std_core__list _match_3311;
    kk_std_core__list _x0 = p.parts;
    kk_std_core__list_dup(_x0);
    kk_std_os_path__path_drop(p, _ctx);
    _match_3311 = _x0; /*list<string>*/
    if (kk_std_core__is_Nil(_match_3311)) {
      return true;
    }
    kk_std_core__list_drop(_match_3311, _ctx);
    return false;
  }
  kk_std_os_path__path_drop(p, _ctx);
  return false;
}

kk_std_core__list kk_std_os_path_push_part(kk_string_t dir, kk_std_core__list dirs, kk_context_t* _ctx) { /* (dir : string, dirs : list<string>) -> list<string> */ 
  bool _match_3305;
  bool _match_3308;
  kk_string_t _x3377 = kk_string_dup(dir); /*string*/
  kk_string_t _x3378;
  kk_define_string_literal(, _s3379, 1, ".")
  _x3378 = kk_string_dup(_s3379); /*string*/
  _match_3308 = kk_string_is_eq(_x3377,_x3378,kk_context()); /*bool*/
  if (_match_3308) {
    _match_3305 = true; /*bool*/
  }
  else {
    kk_string_t _x3380 = kk_string_dup(dir); /*string*/
    kk_string_t _x3381 = kk_string_empty(); /*string*/
    _match_3305 = kk_string_is_eq(_x3380,_x3381,kk_context()); /*bool*/
  }
  if (_match_3305) {
    kk_string_drop(dir, _ctx);
    return dirs;
  }
  bool _match_3306;
  bool _match_3307;
  kk_string_t _x3383 = kk_string_dup(dir); /*string*/
  kk_string_t _x3384;
  kk_define_string_literal(, _s3385, 2, "..")
  _x3384 = kk_string_dup(_s3385); /*string*/
  _match_3307 = kk_string_is_eq(_x3383,_x3384,kk_context()); /*bool*/
  if (_match_3307) {
    kk_std_core__list _x3386 = kk_std_core__list_dup(dirs); /*list<string>*/
    _match_3306 = kk_std_core_is_cons(_x3386, _ctx); /*bool*/
  }
  else {
    _match_3306 = false; /*bool*/
  }
  if (_match_3306) {
    kk_string_drop(dir, _ctx);
    return kk_std_core_tail_1(dirs, _ctx);
  }
  return kk_std_core__new_Cons(kk_reuse_null, kk_string_box(dir), dirs, _ctx);
}

kk_std_core__list kk_std_os_path_push_parts(kk_std_core__list parts0, kk_std_core__list dirs, kk_context_t* _ctx) { /* (parts : list<string>, dirs : list<string>) -> list<string> */ 
  kk__tailcall: ;
  if (kk_std_core__is_Cons(parts0)) {
    struct kk_std_core_Cons* _con3387 = kk_std_core__as_Cons(parts0);
    kk_box_t _box_x2932 = _con3387->head;
    kk_std_core__list rest = _con3387->tail;
    kk_string_t part = kk_string_unbox(_box_x2932);
    if (kk_std_core__list_is_unique(parts0)) {
      kk_std_core__list_free(parts0);
    }
    else {
      kk_string_dup(part);
      kk_std_core__list_dup(rest);
      kk_std_core__list_decref(parts0, _ctx);
    }
    { // tailcall
      kk_std_core__list _x3389 = kk_std_os_path_push_part(part, dirs, _ctx); /*list<string>*/
      parts0 = rest;
      dirs = _x3389;
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
struct kk_std_os_path__mlift2701_proot_fun3391__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path__mlift2701_proot_fun3391(kk_function_t _fself, kk_box_t _b_2934, kk_context_t* _ctx);
static kk_function_t kk_std_os_path__new_mlift2701_proot_fun3391(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path__mlift2701_proot_fun3391, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_path__mlift2701_proot_fun3391(kk_function_t _fself, kk_box_t _b_2934, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_unit_t _x3392 = kk_Unit;
  kk_char_t _x3393 = kk_char_unbox(_b_2934, _ctx); /*char*/
  kk_std_os_path__mlift2700_proot(_x3393, _ctx);
  return kk_unit_box(_x3392);
}

kk_unit_t kk_std_os_path__mlift2701_proot(kk_char_t wild__, kk_context_t* _ctx) { /* (wild_ : char) -> std/text/parse/parse () */ 
  kk_char_t x_2748 = kk_std_text_parse_char(':', _ctx); /*char*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x3390 = kk_std_core_hnd_yield_extend(kk_std_os_path__new_mlift2701_proot_fun3391(_ctx), _ctx); /*3991*/
    kk_unit_unbox(_x3390); return kk_Unit;
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
struct kk_std_os_path__mlift2703_proot_fun3394__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path__mlift2703_proot_fun3394(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_os_path__new_mlift2703_proot_fun3394(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path__mlift2703_proot_fun3394, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_path__mlift2703_proot_fun3394(kk_function_t _fself, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_char_t _x3395;
  kk_string_t _x3396;
  kk_define_string_literal(, _s3397, 1, "/")
  _x3396 = kk_string_dup(_s3397); /*string*/
  _x3395 = kk_std_text_parse_none_of(_x3396, _ctx); /*char*/
  return kk_char_box(_x3395, _ctx);
}


// lift anonymous function
struct kk_std_os_path__mlift2703_proot_fun3399__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path__mlift2703_proot_fun3399(kk_function_t _fself, kk_box_t _b_2939, kk_context_t* _ctx);
static kk_function_t kk_std_os_path__new_mlift2703_proot_fun3399(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path__mlift2703_proot_fun3399, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_path__mlift2703_proot_fun3399(kk_function_t _fself, kk_box_t _b_2939, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_unit_t _x3400 = kk_Unit;
  kk_std_core__list _x3401 = kk_std_core__list_unbox(_b_2939, _ctx); /*list<char>*/
  kk_std_os_path__mlift2702_proot(_x3401, _ctx);
  return kk_unit_box(_x3400);
}

kk_unit_t kk_std_os_path__mlift2703_proot(kk_char_t wild__1, kk_context_t* _ctx) { /* (wild_1 : char) -> std/text/parse/parse () */ 
  kk_std_core__list x_2750 = kk_std_text_parse_many1(kk_std_os_path__new_mlift2703_proot_fun3394(_ctx), _ctx); /*list<char>*/;
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_2750, _ctx);
    kk_box_t _x3398 = kk_std_core_hnd_yield_extend(kk_std_os_path__new_mlift2703_proot_fun3399(_ctx), _ctx); /*3991*/
    kk_unit_unbox(_x3398); return kk_Unit;
  }
  kk_std_os_path__mlift2702_proot(x_2750, _ctx); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_std_os_path__mlift2704_proot_fun3403__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path__mlift2704_proot_fun3403(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_os_path__new_mlift2704_proot_fun3403(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path__mlift2704_proot_fun3403, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_std_os_path__mlift2704_proot_fun3406__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path__mlift2704_proot_fun3406(kk_function_t _fself, kk_box_t _b_2942, kk_context_t* _ctx);
static kk_function_t kk_std_os_path__new_mlift2704_proot_fun3406(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path__mlift2704_proot_fun3406, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_path__mlift2704_proot_fun3406(kk_function_t _fself, kk_box_t _b_2942, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  bool _x3407;
  kk_char_t _x3408 = kk_char_unbox(_b_2942, _ctx); /*char*/
  _x3407 = kk_std_os_path__mlift2698_proot(_x3408, _ctx); /*bool*/
  return kk_bool_box(_x3407);
}
static kk_box_t kk_std_os_path__mlift2704_proot_fun3403(kk_function_t _fself, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  bool _x3404;
  kk_char_t x_2752 = kk_std_text_parse_char('/', _ctx); /*char*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x3405 = kk_std_core_hnd_yield_extend(kk_std_os_path__new_mlift2704_proot_fun3406(_ctx), _ctx); /*3991*/
    _x3404 = kk_bool_unbox(_x3405); /*bool*/
  }
  else {
    _x3404 = kk_std_os_path__mlift2698_proot(x_2752, _ctx); /*bool*/
  }
  return kk_bool_box(_x3404);
}


// lift anonymous function
struct kk_std_os_path__mlift2704_proot_fun3409__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path__mlift2704_proot_fun3409(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_os_path__new_mlift2704_proot_fun3409(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path__mlift2704_proot_fun3409, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_std_os_path__mlift2704_proot_fun3412__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path__mlift2704_proot_fun3412(kk_function_t _fself, kk_box_t _b_2944, kk_context_t* _ctx);
static kk_function_t kk_std_os_path__new_mlift2704_proot_fun3412(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path__mlift2704_proot_fun3412, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_path__mlift2704_proot_fun3412(kk_function_t _fself, kk_box_t _b_2944, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  bool _x3413;
  kk_unit_t _x3414 = kk_Unit;
  kk_unit_unbox(_b_2944);
  _x3413 = kk_std_os_path__mlift2699_proot(_x3414, _ctx); /*bool*/
  return kk_bool_box(_x3413);
}
static kk_box_t kk_std_os_path__mlift2704_proot_fun3409(kk_function_t _fself, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  bool _x3410;
  kk_unit_t x0_2754 = kk_Unit;
  kk_std_text_parse_eof(_ctx);
  if (kk_yielding(kk_context())) {
    kk_box_t _x3411 = kk_std_core_hnd_yield_extend(kk_std_os_path__new_mlift2704_proot_fun3412(_ctx), _ctx); /*3991*/
    _x3410 = kk_bool_unbox(_x3411); /*bool*/
  }
  else {
    _x3410 = kk_std_os_path__mlift2699_proot(x0_2754, _ctx); /*bool*/
  }
  return kk_bool_box(_x3410);
}

bool kk_std_os_path__mlift2704_proot(kk_unit_t wild__3, kk_context_t* _ctx) { /* (wild_3 : ()) -> std/text/parse/parse bool */ 
  kk_box_t _x3402 = kk_std_text_parse__lp__bar__bar__rp_(kk_std_os_path__new_mlift2704_proot_fun3403(_ctx), kk_std_os_path__new_mlift2704_proot_fun3409(_ctx), _ctx); /*1032*/
  return kk_bool_unbox(_x3402);
}


// lift anonymous function
struct kk_std_os_path_proot_fun3416__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path_proot_fun3416(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_os_path_new_proot_fun3416(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path_proot_fun3416, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_std_os_path_proot_fun3419__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path_proot_fun3419(kk_function_t _fself, kk_box_t _b_2952, kk_context_t* _ctx);
static kk_function_t kk_std_os_path_new_proot_fun3419(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path_proot_fun3419, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_path_proot_fun3419(kk_function_t _fself, kk_box_t _b_2952, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_unit_t _x3420 = kk_Unit;
  kk_char_t _x3421 = kk_char_unbox(_b_2952, _ctx); /*char*/
  kk_std_os_path__mlift2701_proot(_x3421, _ctx);
  return kk_unit_box(_x3420);
}
static kk_box_t kk_std_os_path_proot_fun3416(kk_function_t _fself, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_unit_t _x3417 = kk_Unit;
  kk_char_t x0_2759 = kk_std_text_parse_alpha(_ctx); /*char*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x3418 = kk_std_core_hnd_yield_extend(kk_std_os_path_new_proot_fun3419(_ctx), _ctx); /*3991*/
    kk_unit_unbox(_x3418);
  }
  else {
    kk_std_os_path__mlift2701_proot(x0_2759, _ctx);
  }
  return kk_unit_box(_x3417);
}


// lift anonymous function
struct kk_std_os_path_proot_fun3422__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path_proot_fun3422(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_os_path_new_proot_fun3422(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path_proot_fun3422, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_std_os_path_proot_fun3425__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path_proot_fun3425(kk_function_t _fself, kk_box_t _b_2954, kk_context_t* _ctx);
static kk_function_t kk_std_os_path_new_proot_fun3425(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path_proot_fun3425, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_path_proot_fun3425(kk_function_t _fself, kk_box_t _b_2954, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_unit_t _x3426 = kk_Unit;
  kk_char_t _x3427 = kk_char_unbox(_b_2954, _ctx); /*char*/
  kk_std_os_path__mlift2703_proot(_x3427, _ctx);
  return kk_unit_box(_x3426);
}
static kk_box_t kk_std_os_path_proot_fun3422(kk_function_t _fself, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_unit_t _x3423 = kk_Unit;
  kk_char_t x1_2761 = kk_std_text_parse_char('/', _ctx); /*char*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x3424 = kk_std_core_hnd_yield_extend(kk_std_os_path_new_proot_fun3425(_ctx), _ctx); /*3991*/
    kk_unit_unbox(_x3424);
  }
  else {
    kk_std_os_path__mlift2703_proot(x1_2761, _ctx);
  }
  return kk_unit_box(_x3423);
}


// lift anonymous function
struct kk_std_os_path_proot_fun3429__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path_proot_fun3429(kk_function_t _fself, kk_box_t _b_2962, kk_context_t* _ctx);
static kk_function_t kk_std_os_path_new_proot_fun3429(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path_proot_fun3429, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_path_proot_fun3429(kk_function_t _fself, kk_box_t _b_2962, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  bool _x3430;
  kk_unit_t _x3431 = kk_Unit;
  kk_unit_unbox(_b_2962);
  _x3430 = kk_std_os_path__mlift2704_proot(_x3431, _ctx); /*bool*/
  return kk_bool_box(_x3430);
}


// lift anonymous function
struct kk_std_os_path_proot_fun3432__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path_proot_fun3432(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_os_path_new_proot_fun3432(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path_proot_fun3432, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_std_os_path_proot_fun3435__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path_proot_fun3435(kk_function_t _fself, kk_box_t _b_2964, kk_context_t* _ctx);
static kk_function_t kk_std_os_path_new_proot_fun3435(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path_proot_fun3435, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_path_proot_fun3435(kk_function_t _fself, kk_box_t _b_2964, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  bool _x3436;
  kk_char_t _x3437 = kk_char_unbox(_b_2964, _ctx); /*char*/
  _x3436 = kk_std_os_path__mlift2698_proot(_x3437, _ctx); /*bool*/
  return kk_bool_box(_x3436);
}
static kk_box_t kk_std_os_path_proot_fun3432(kk_function_t _fself, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  bool _x3433;
  kk_char_t x2_2764 = kk_std_text_parse_char('/', _ctx); /*char*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x3434 = kk_std_core_hnd_yield_extend(kk_std_os_path_new_proot_fun3435(_ctx), _ctx); /*3991*/
    _x3433 = kk_bool_unbox(_x3434); /*bool*/
  }
  else {
    _x3433 = kk_std_os_path__mlift2698_proot(x2_2764, _ctx); /*bool*/
  }
  return kk_bool_box(_x3433);
}


// lift anonymous function
struct kk_std_os_path_proot_fun3438__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path_proot_fun3438(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_os_path_new_proot_fun3438(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path_proot_fun3438, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_std_os_path_proot_fun3441__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path_proot_fun3441(kk_function_t _fself, kk_box_t _b_2966, kk_context_t* _ctx);
static kk_function_t kk_std_os_path_new_proot_fun3441(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path_proot_fun3441, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_path_proot_fun3441(kk_function_t _fself, kk_box_t _b_2966, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  bool _x3442;
  kk_unit_t _x3443 = kk_Unit;
  kk_unit_unbox(_b_2966);
  _x3442 = kk_std_os_path__mlift2699_proot(_x3443, _ctx); /*bool*/
  return kk_bool_box(_x3442);
}
static kk_box_t kk_std_os_path_proot_fun3438(kk_function_t _fself, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  bool _x3439;
  kk_unit_t x3_2766 = kk_Unit;
  kk_std_text_parse_eof(_ctx);
  if (kk_yielding(kk_context())) {
    kk_box_t _x3440 = kk_std_core_hnd_yield_extend(kk_std_os_path_new_proot_fun3441(_ctx), _ctx); /*3991*/
    _x3439 = kk_bool_unbox(_x3440); /*bool*/
  }
  else {
    _x3439 = kk_std_os_path__mlift2699_proot(x3_2766, _ctx); /*bool*/
  }
  return kk_bool_box(_x3439);
}

bool kk_std_os_path_proot(kk_context_t* _ctx) { /* () -> std/text/parse/parse bool */ 
  kk_unit_t x_2756 = kk_Unit;
  kk_box_t _x3415 = kk_std_text_parse__lp__bar__bar__rp_(kk_std_os_path_new_proot_fun3416(_ctx), kk_std_os_path_new_proot_fun3422(_ctx), _ctx); /*1032*/
  kk_unit_unbox(_x3415);
  kk_box_t _x3428;
  if (kk_yielding(kk_context())) {
    _x3428 = kk_std_core_hnd_yield_extend(kk_std_os_path_new_proot_fun3429(_ctx), _ctx); /*3991*/
  }
  else {
    _x3428 = kk_std_text_parse__lp__bar__bar__rp_(kk_std_os_path_new_proot_fun3432(_ctx), kk_std_os_path_new_proot_fun3438(_ctx), _ctx); /*3991*/
  }
  return kk_bool_unbox(_x3428);
}
 
// Convert a `:path` to a normalized `:string` path.
// If this results in an empty string, the current directory path `"."` is returned.
// `"c:/foo/test.txt".path.string -> "c:/foo/test.txt"`
// `"c:\\foo\\test.txt".path.string -> "c:/foo/test.txt"`
// `"/foo//./bar/../test.txt".path.string -> "/foo/test.txt"`

kk_string_t kk_std_os_path_string(kk_std_os_path__path p, kk_context_t* _ctx) { /* (p : path) -> string */ 
  kk_string_t s;
  kk_string_t _x3444;
  kk_string_t _x = p.root;
  kk_string_dup(_x);
  _x3444 = _x; /*string*/
  kk_string_t _x3445;
  kk_std_core__list xs_2769;
  kk_std_core__list _x3446;
  kk_std_core__list _x0 = p.parts;
  kk_std_core__list_dup(_x0);
  kk_std_os_path__path_drop(p, _ctx);
  _x3446 = _x0; /*list<string>*/
  xs_2769 = kk_std_core__lift21047_reverse_append(kk_std_core__new_Nil(_ctx), _x3446, _ctx); /*list<string>*/
  if (kk_std_core__is_Nil(xs_2769)) {
    _x3445 = kk_string_empty(); /*string*/
  }
  else {
    struct kk_std_core_Cons* _con3448 = kk_std_core__as_Cons(xs_2769);
    kk_box_t _box_x2974 = _con3448->head;
    kk_std_core__list xx = _con3448->tail;
    kk_string_t x = kk_string_unbox(_box_x2974);
    if (kk_std_core__list_is_unique(xs_2769)) {
      kk_std_core__list_free(xs_2769);
    }
    else {
      kk_string_dup(x);
      kk_std_core__list_dup(xx);
      kk_std_core__list_decref(xs_2769, _ctx);
    }
    kk_string_t _x3450;
    kk_define_string_literal(, _s3451, 1, "/")
    _x3450 = kk_string_dup(_s3451); /*string*/
    _x3445 = kk_std_core__lift21050_joinsep(_x3450, xx, x, _ctx); /*string*/
  }
  s = kk_std_core__lp__plus__plus__1_rp_(_x3444, _x3445, _ctx); /*string*/
  bool _match_3295;
  kk_string_t _x3452 = kk_string_dup(s); /*string*/
  _match_3295 = kk_std_core_is_empty_2(_x3452, _ctx); /*bool*/
  if (_match_3295) {
    kk_string_drop(s, _ctx);
    kk_define_string_literal(, _s3453, 1, ".")
    return kk_string_dup(_s3453);
  }
  return s;
}

kk_std_os_path__path kk_std_os_path_path_parts(kk_string_t root0, kk_string_t s, kk_std_core_types__optional dirs, kk_context_t* _ctx) { /* (root : string, s : string, dirs : optional<list<string>>) -> path */ 
  kk_std_core__list parts0;
  kk_std_core__list _x3461;
  kk_vector_t v_21689;
  kk_string_t _x3462;
  kk_define_string_literal(, _s3463, 1, "/")
  _x3462 = kk_string_dup(_s3463); /*string*/
  v_21689 = kk_string_splitv(s,_x3462,kk_context()); /*vector<string>*/
  _x3461 = kk_std_core_vlist(v_21689, kk_std_core_types__new_None(_ctx), _ctx); /*list<2154>*/
  kk_std_core__list _x3464;
  if (kk_std_core_types__is_Optional(dirs)) {
    kk_box_t _box_x2977 = dirs._cons.Optional.value;
    kk_std_core__list _dirs_1291 = kk_std_core__list_unbox(_box_x2977, NULL);
    kk_std_core__list_dup(_dirs_1291);
    kk_std_core_types__optional_drop(dirs, _ctx);
    _x3464 = _dirs_1291; /*list<string>*/
    goto _match3465;
  }
  _x3464 = kk_std_core__new_Nil(_ctx); /*list<string>*/
  _match3465: ;
  parts0 = kk_std_os_path_push_parts(_x3461, _x3464, _ctx); /*list<string>*/
  return kk_std_os_path__new_Path(root0, parts0, _ctx);
}
 
// Create a normalized `:path` from a path string.


// lift anonymous function
struct kk_std_os_path_path_fun3475__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path_path_fun3475(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_os_path_new_path_fun3475(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path_path_fun3475, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_path_path_fun3475(kk_function_t _fself, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  bool _x3476 = kk_std_os_path_proot(_ctx); /*bool*/
  return kk_bool_box(_x3476);
}

kk_std_os_path__path kk_std_os_path_path(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> path */ 
  bool _match_3291;
  kk_string_t _x3467 = kk_string_dup(s); /*string*/
  _match_3291 = kk_std_core_is_empty_2(_x3467, _ctx); /*bool*/
  if (_match_3291) {
    kk_string_drop(s, _ctx);
    kk_string_t _x3468 = kk_string_empty(); /*string*/
    return kk_std_os_path__new_Path(_x3468, kk_std_core__new_Nil(_ctx), _ctx);
  }
  kk_string_t t;
  kk_string_t _x3470;
  kk_define_string_literal(, _s3471, 1, "\\")
  _x3470 = kk_string_dup(_s3471); /*string*/
  kk_string_t _x3472;
  kk_define_string_literal(, _s3473, 1, "/")
  _x3472 = kk_string_dup(_s3473); /*string*/
  t = kk_string_replace_all(s,_x3470,_x3472,kk_context()); /*string*/
  kk_std_core_types__maybe _match_3292;
  kk_string_t _x3474 = kk_string_dup(t); /*string*/
  _match_3292 = kk_std_text_parse_starts_with(_x3474, kk_std_os_path_new_path_fun3475(_ctx), _ctx); /*maybe<(2486, sslice)>*/
  if (kk_std_core_types__is_Nothing(_match_3292)) {
    kk_std_core__list parts0;
    kk_std_core__list _x3477;
    kk_vector_t v_21689;
    kk_string_t _x3478;
    kk_define_string_literal(, _s3479, 1, "/")
    _x3478 = kk_string_dup(_s3479); /*string*/
    v_21689 = kk_string_splitv(t,_x3478,kk_context()); /*vector<string>*/
    _x3477 = kk_std_core_vlist(v_21689, kk_std_core_types__new_None(_ctx), _ctx); /*list<2154>*/
    kk_std_core__list _x3480;
    kk_std_core_types__optional _match_3294 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
    if (kk_std_core_types__is_Optional(_match_3294)) {
      kk_box_t _box_x2980 = _match_3294._cons.Optional.value;
      kk_std_core__list _dirs_1291 = kk_std_core__list_unbox(_box_x2980, NULL);
      kk_std_core__list_dup(_dirs_1291);
      kk_std_core_types__optional_drop(_match_3294, _ctx);
      _x3480 = _dirs_1291; /*list<string>*/
      goto _match3481;
    }
    _x3480 = kk_std_core__new_Nil(_ctx); /*list<string>*/
    _match3481: ;
    parts0 = kk_std_os_path_push_parts(_x3477, _x3480, _ctx); /*list<string>*/
    kk_string_t _x3483 = kk_string_empty(); /*string*/
    return kk_std_os_path__new_Path(_x3483, parts0, _ctx);
  }
  kk_box_t _box_x2981 = _match_3292._cons.Just.value;
  kk_std_core_types__tuple2_ _pat3 = kk_std_core_types__tuple2__unbox(_box_x2981, NULL);
  kk_box_t _box_x2982 = _pat3.fst;
  kk_box_t _box_x2983 = _pat3.snd;
  bool eof = kk_bool_unbox(_box_x2982);
  kk_std_core__sslice rest = kk_std_core__sslice_unbox(_box_x2983, NULL);
  kk_string_drop(t, _ctx);
  kk_std_core__sslice_dup(rest);
  kk_std_core_types__maybe_drop(_match_3292, _ctx);
  kk_string_t root0_2780;
  kk_string_t _x3488;
  kk_std_core__sslice _x3489;
  kk_std_core__sslice _x3490 = kk_std_core__sslice_dup(rest); /*sslice*/
  _x3489 = kk_std_core_before(_x3490, _ctx); /*sslice*/
  _x3488 = kk_std_core_string_3(_x3489, _ctx); /*string*/
  kk_string_t _x3491;
  if (eof) {
    kk_define_string_literal(, _s3492, 1, "/")
    _x3491 = kk_string_dup(_s3492); /*string*/
  }
  else {
    _x3491 = kk_string_empty(); /*string*/
  }
  root0_2780 = kk_std_core__lp__plus__plus__1_rp_(_x3488, _x3491, _ctx); /*string*/
  kk_string_t s2_2781 = kk_std_core_string_3(rest, _ctx); /*string*/;
  kk_std_core__list parts00;
  kk_std_core__list _x3494;
  kk_vector_t v_216890;
  kk_string_t _x3495;
  kk_define_string_literal(, _s3496, 1, "/")
  _x3495 = kk_string_dup(_s3496); /*string*/
  v_216890 = kk_string_splitv(s2_2781,_x3495,kk_context()); /*vector<string>*/
  _x3494 = kk_std_core_vlist(v_216890, kk_std_core_types__new_None(_ctx), _ctx); /*list<2154>*/
  kk_std_core__list _x3497;
  kk_std_core_types__optional _match_3293 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
  if (kk_std_core_types__is_Optional(_match_3293)) {
    kk_box_t _box_x2984 = _match_3293._cons.Optional.value;
    kk_std_core__list _dirs_12910 = kk_std_core__list_unbox(_box_x2984, NULL);
    kk_std_core__list_dup(_dirs_12910);
    kk_std_core_types__optional_drop(_match_3293, _ctx);
    _x3497 = _dirs_12910; /*list<string>*/
    goto _match3498;
  }
  _x3497 = kk_std_core__new_Nil(_ctx); /*list<string>*/
  _match3498: ;
  parts00 = kk_std_os_path_push_parts(_x3494, _x3497, _ctx); /*list<string>*/
  return kk_std_os_path__new_Path(root0_2780, parts00, _ctx);
}
 
// Add two paths together using left-associative operator `(/)`.
// Keeps the root of `p1` and discards the root name of `p2`.
// `"/a/" / "b/foo.txt"          === "/a/b/foo.txt"`
// `"/a/foo.txt" / "/b/bar.txt"  === "/a/foo.txt/b/bar.txt"`
// `"c:/foo" / "d:/bar"          === "c:/foo/bar"`

kk_std_os_path__path kk_std_os_path__lp__fs__rp_(kk_std_os_path__path p1, kk_std_os_path__path p2, kk_context_t* _ctx) { /* (p1 : path, p2 : path) -> path */ 
  kk_std_core_types__optional root_2785;
  kk_box_t _x3500;
  kk_string_t _x3501;
  kk_string_t _x = p1.root;
  kk_string_dup(_x);
  _x3501 = _x; /*string*/
  _x3500 = kk_string_box(_x3501); /*108*/
  root_2785 = kk_std_core_types__new_Optional(_x3500, _ctx); /*optional<string>*/
  kk_std_core_types__optional parts_2786;
  kk_std_core__list _b_2990_2989;
  kk_std_core__list _x3502;
  kk_std_core__list _x3503;
  kk_std_core__list _x0 = p2.parts;
  kk_std_core__list_dup(_x0);
  kk_std_os_path__path_drop(p2, _ctx);
  _x3503 = _x0; /*list<string>*/
  _x3502 = kk_std_core__lift21047_reverse_append(kk_std_core__new_Nil(_ctx), _x3503, _ctx); /*list<2501>*/
  kk_std_core__list _x3504;
  kk_std_core__list _x1 = p1.parts;
  kk_std_core__list_dup(_x1);
  kk_std_os_path__path_drop(p1, _ctx);
  _x3504 = _x1; /*list<string>*/
  _b_2990_2989 = kk_std_os_path_push_parts(_x3502, _x3504, _ctx); /*list<string>*/
  parts_2786 = kk_std_core_types__new_Optional(kk_std_core__list_box(_b_2990_2989, _ctx), _ctx); /*optional<list<string>>*/
  kk_string_t _x3505;
  if (kk_std_core_types__is_Optional(root_2785)) {
    kk_box_t _box_x2991 = root_2785._cons.Optional.value;
    kk_string_t _root_1093 = kk_string_unbox(_box_x2991);
    kk_string_dup(_root_1093);
    kk_std_core_types__optional_drop(root_2785, _ctx);
    _x3505 = _root_1093; /*string*/
    goto _match3506;
  }
  _x3505 = kk_string_empty(); /*string*/
  _match3506: ;
  kk_std_core__list _x3509;
  if (kk_std_core_types__is_Optional(parts_2786)) {
    kk_box_t _box_x2992 = parts_2786._cons.Optional.value;
    kk_std_core__list _parts_1098 = kk_std_core__list_unbox(_box_x2992, NULL);
    kk_std_core__list_dup(_parts_1098);
    kk_std_core_types__optional_drop(parts_2786, _ctx);
    _x3509 = _parts_1098; /*list<string>*/
    goto _match3510;
  }
  _x3509 = kk_std_core__new_Nil(_ctx); /*list<string>*/
  _match3510: ;
  return kk_std_os_path__new_Path(_x3505, _x3509, _ctx);
}
 
// Convenience function that adds a string path.

kk_std_os_path__path kk_std_os_path__lp__fs__1_rp_(kk_std_os_path__path p1, kk_string_t p2, kk_context_t* _ctx) { /* (p1 : path, p2 : string) -> path */ 
  kk_std_os_path__path p20_2792 = kk_std_os_path_path(p2, _ctx); /*std/os/path/path*/;
  kk_std_core_types__optional root_2793;
  kk_box_t _x3512;
  kk_string_t _x3513;
  kk_string_t _x = p1.root;
  kk_string_dup(_x);
  _x3513 = _x; /*string*/
  _x3512 = kk_string_box(_x3513); /*108*/
  root_2793 = kk_std_core_types__new_Optional(_x3512, _ctx); /*optional<string>*/
  kk_std_core_types__optional parts_2794;
  kk_std_core__list _b_2996_2995;
  kk_std_core__list _x3514;
  kk_std_core__list _x3515;
  kk_std_core__list _x0 = p20_2792.parts;
  kk_std_core__list_dup(_x0);
  kk_std_os_path__path_drop(p20_2792, _ctx);
  _x3515 = _x0; /*list<string>*/
  _x3514 = kk_std_core__lift21047_reverse_append(kk_std_core__new_Nil(_ctx), _x3515, _ctx); /*list<2501>*/
  kk_std_core__list _x3516;
  kk_std_core__list _x1 = p1.parts;
  kk_std_core__list_dup(_x1);
  kk_std_os_path__path_drop(p1, _ctx);
  _x3516 = _x1; /*list<string>*/
  _b_2996_2995 = kk_std_os_path_push_parts(_x3514, _x3516, _ctx); /*list<string>*/
  parts_2794 = kk_std_core_types__new_Optional(kk_std_core__list_box(_b_2996_2995, _ctx), _ctx); /*optional<list<string>>*/
  kk_string_t _x3517;
  if (kk_std_core_types__is_Optional(root_2793)) {
    kk_box_t _box_x2997 = root_2793._cons.Optional.value;
    kk_string_t _root_1093 = kk_string_unbox(_box_x2997);
    kk_string_dup(_root_1093);
    kk_std_core_types__optional_drop(root_2793, _ctx);
    _x3517 = _root_1093; /*string*/
    goto _match3518;
  }
  _x3517 = kk_string_empty(); /*string*/
  _match3518: ;
  kk_std_core__list _x3521;
  if (kk_std_core_types__is_Optional(parts_2794)) {
    kk_box_t _box_x2998 = parts_2794._cons.Optional.value;
    kk_std_core__list _parts_1098 = kk_std_core__list_unbox(_box_x2998, NULL);
    kk_std_core__list_dup(_parts_1098);
    kk_std_core_types__optional_drop(parts_2794, _ctx);
    _x3521 = _parts_1098; /*list<string>*/
    goto _match3522;
  }
  _x3521 = kk_std_core__new_Nil(_ctx); /*list<string>*/
  _match3522: ;
  return kk_std_os_path__new_Path(_x3517, _x3521, _ctx);
}
 
// Convenience function that adds two strings into a path.

kk_std_os_path__path kk_std_os_path__lp__fs__2_rp_(kk_string_t p1, kk_string_t p2, kk_context_t* _ctx) { /* (p1 : string, p2 : string) -> path */ 
  kk_std_os_path__path p10_2799 = kk_std_os_path_path(p1, _ctx); /*std/os/path/path*/;
  kk_std_os_path__path p20_2800 = kk_std_os_path_path(p2, _ctx); /*std/os/path/path*/;
  kk_std_core_types__optional root_2801;
  kk_box_t _x3524;
  kk_string_t _x3525;
  kk_string_t _x = p10_2799.root;
  kk_string_dup(_x);
  _x3525 = _x; /*string*/
  _x3524 = kk_string_box(_x3525); /*108*/
  root_2801 = kk_std_core_types__new_Optional(_x3524, _ctx); /*optional<string>*/
  kk_std_core_types__optional parts_2802;
  kk_std_core__list _b_3002_3001;
  kk_std_core__list _x3526;
  kk_std_core__list _x3527;
  kk_std_core__list _x0 = p20_2800.parts;
  kk_std_core__list_dup(_x0);
  kk_std_os_path__path_drop(p20_2800, _ctx);
  _x3527 = _x0; /*list<string>*/
  _x3526 = kk_std_core__lift21047_reverse_append(kk_std_core__new_Nil(_ctx), _x3527, _ctx); /*list<2501>*/
  kk_std_core__list _x3528;
  kk_std_core__list _x1 = p10_2799.parts;
  kk_std_core__list_dup(_x1);
  kk_std_os_path__path_drop(p10_2799, _ctx);
  _x3528 = _x1; /*list<string>*/
  _b_3002_3001 = kk_std_os_path_push_parts(_x3526, _x3528, _ctx); /*list<string>*/
  parts_2802 = kk_std_core_types__new_Optional(kk_std_core__list_box(_b_3002_3001, _ctx), _ctx); /*optional<list<string>>*/
  kk_string_t _x3529;
  if (kk_std_core_types__is_Optional(root_2801)) {
    kk_box_t _box_x3003 = root_2801._cons.Optional.value;
    kk_string_t _root_1093 = kk_string_unbox(_box_x3003);
    kk_string_dup(_root_1093);
    kk_std_core_types__optional_drop(root_2801, _ctx);
    _x3529 = _root_1093; /*string*/
    goto _match3530;
  }
  _x3529 = kk_string_empty(); /*string*/
  _match3530: ;
  kk_std_core__list _x3533;
  if (kk_std_core_types__is_Optional(parts_2802)) {
    kk_box_t _box_x3004 = parts_2802._cons.Optional.value;
    kk_std_core__list _parts_1098 = kk_std_core__list_unbox(_box_x3004, NULL);
    kk_std_core__list_dup(_parts_1098);
    kk_std_core_types__optional_drop(parts_2802, _ctx);
    _x3533 = _parts_1098; /*list<string>*/
    goto _match3534;
  }
  _x3533 = kk_std_core__new_Nil(_ctx); /*list<string>*/
  _match3534: ;
  return kk_std_os_path__new_Path(_x3529, _x3533, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_os_path__mlift2705_app_path_fun3537__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path__mlift2705_app_path_fun3537(kk_function_t _fself, kk_box_t _b_3007, kk_context_t* _ctx);
static kk_function_t kk_std_os_path__new_mlift2705_app_path_fun3537(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path__mlift2705_app_path_fun3537, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_path__mlift2705_app_path_fun3537(kk_function_t _fself, kk_box_t _b_3007, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_os_path__path _x3538;
  kk_string_t _x3539 = kk_string_unbox(_b_3007); /*string*/
  _x3538 = kk_std_os_path_path(_x3539, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x3538, _ctx);
}

kk_std_os_path__path kk_std_os_path__mlift2705_app_path(kk_string_t _y_14, kk_context_t* _ctx) { /* (string) -> io path */ 
  kk_box_t _x3536 = kk_std_core_hnd__open_none1(kk_std_os_path__new_mlift2705_app_path_fun3537(_ctx), kk_string_box(_y_14), _ctx); /*3239*/
  return kk_std_os_path__path_unbox(_x3536, _ctx);
}
 
// Return the path to the currently executing application.


// lift anonymous function
struct kk_std_os_path_app_path_fun3541__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path_app_path_fun3541(kk_function_t _fself, kk_box_t _b_3011, kk_context_t* _ctx);
static kk_function_t kk_std_os_path_new_app_path_fun3541(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path_app_path_fun3541, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_path_app_path_fun3541(kk_function_t _fself, kk_box_t _b_3011, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_os_path__path _x3542;
  kk_string_t _x3543 = kk_string_unbox(_b_3011); /*string*/
  _x3542 = kk_std_os_path__mlift2705_app_path(_x3543, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x3542, _ctx);
}


// lift anonymous function
struct kk_std_os_path_app_path_fun3544__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path_app_path_fun3544(kk_function_t _fself, kk_box_t _b_3014, kk_context_t* _ctx);
static kk_function_t kk_std_os_path_new_app_path_fun3544(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path_app_path_fun3544, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_path_app_path_fun3544(kk_function_t _fself, kk_box_t _b_3014, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_os_path__path _x3545;
  kk_string_t _x3546 = kk_string_unbox(_b_3014); /*string*/
  _x3545 = kk_std_os_path_path(_x3546, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x3545, _ctx);
}

kk_std_os_path__path kk_std_os_path_app_path(kk_context_t* _ctx) { /* () -> io path */ 
  kk_string_t x_2807 = kk_std_os_path_xapp_path(_ctx); /*string*/;
  kk_box_t _x3540;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_2807, _ctx);
    _x3540 = kk_std_core_hnd_yield_extend(kk_std_os_path_new_app_path_fun3541(_ctx), _ctx); /*3991*/
  }
  else {
    _x3540 = kk_std_core_hnd__open_none1(kk_std_os_path_new_app_path_fun3544(_ctx), kk_string_box(x_2807), _ctx); /*3991*/
  }
  return kk_std_os_path__path_unbox(_x3540, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_os_path__mlift2706_appdir_fun3548__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path__mlift2706_appdir_fun3548(kk_function_t _fself, kk_box_t _b_3020, kk_context_t* _ctx);
static kk_function_t kk_std_os_path__new_mlift2706_appdir_fun3548(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path__mlift2706_appdir_fun3548, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_path__mlift2706_appdir_fun3548(kk_function_t _fself, kk_box_t _b_3020, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_os_path__path _x3549;
  kk_std_os_path__path _x3550 = kk_std_os_path__path_unbox(_b_3020, _ctx); /*std/os/path/path*/
  _x3549 = kk_std_os_path_nobase(_x3550, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x3549, _ctx);
}

kk_std_os_path__path kk_std_os_path__mlift2706_appdir(kk_std_os_path__path p, bool _c_16, kk_context_t* _ctx) { /* (p : path, bool) -> path */ 
  if (_c_16) {
    kk_box_t _x3547 = kk_std_core_hnd__open_none1(kk_std_os_path__new_mlift2706_appdir_fun3548(_ctx), kk_std_os_path__path_box(p, _ctx), _ctx); /*3239*/
    return kk_std_os_path__path_unbox(_x3547, _ctx);
  }
  return p;
}
 
// monadic lift


// lift anonymous function
struct kk_std_os_path__mlift2707_appdir_fun3552__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path__mlift2707_appdir_fun3552(kk_function_t _fself, kk_box_t _b_3025, kk_context_t* _ctx);
static kk_function_t kk_std_os_path__new_mlift2707_appdir_fun3552(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path__mlift2707_appdir_fun3552, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_path__mlift2707_appdir_fun3552(kk_function_t _fself, kk_box_t _b_3025, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_os_path__path _x3553;
  kk_std_os_path__path _x3554 = kk_std_os_path__path_unbox(_b_3025, _ctx); /*std/os/path/path*/
  _x3553 = kk_std_os_path_nobase(_x3554, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x3553, _ctx);
}


// lift anonymous function
struct kk_std_os_path__mlift2707_appdir_fun3557__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path__mlift2707_appdir_fun3557(kk_function_t _fself, kk_box_t _b_3030, kk_context_t* _ctx);
static kk_function_t kk_std_os_path__new_mlift2707_appdir_fun3557(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path__mlift2707_appdir_fun3557, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_path__mlift2707_appdir_fun3557(kk_function_t _fself, kk_box_t _b_3030, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x3558;
  kk_std_os_path__path _x3559 = kk_std_os_path__path_unbox(_b_3030, _ctx); /*std/os/path/path*/
  _x3558 = kk_std_os_path_basename(_x3559, _ctx); /*string*/
  return kk_string_box(_x3558);
}


// lift anonymous function
struct kk_std_os_path__mlift2707_appdir_fun3566__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path__mlift2707_appdir_fun3566(kk_function_t _fself, kk_box_t _b_3033, kk_context_t* _ctx);
static kk_function_t kk_std_os_path__new_mlift2707_appdir_fun3566(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path__mlift2707_appdir_fun3566, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_path__mlift2707_appdir_fun3566(kk_function_t _fself, kk_box_t _b_3033, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x3567;
  kk_std_os_path__path _x3568 = kk_std_os_path__path_unbox(_b_3033, _ctx); /*std/os/path/path*/
  _x3567 = kk_std_os_path_basename(_x3568, _ctx); /*string*/
  return kk_string_box(_x3567);
}


// lift anonymous function
struct kk_std_os_path__mlift2707_appdir_fun3574__t {
  struct kk_function_s _base;
  kk_std_os_path__path p;
};
static kk_box_t kk_std_os_path__mlift2707_appdir_fun3574(kk_function_t _fself, kk_box_t _b_3039, kk_context_t* _ctx);
static kk_function_t kk_std_os_path__new_mlift2707_appdir_fun3574(kk_std_os_path__path p, kk_context_t* _ctx) {
  struct kk_std_os_path__mlift2707_appdir_fun3574__t* _self = kk_function_alloc_as(struct kk_std_os_path__mlift2707_appdir_fun3574__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_os_path__mlift2707_appdir_fun3574, kk_context());
  _self->p = p;
  return &_self->_base;
}

static kk_box_t kk_std_os_path__mlift2707_appdir_fun3574(kk_function_t _fself, kk_box_t _b_3039, kk_context_t* _ctx) {
  struct kk_std_os_path__mlift2707_appdir_fun3574__t* _self = kk_function_as(struct kk_std_os_path__mlift2707_appdir_fun3574__t*, _fself);
  kk_std_os_path__path p = _self->p; /* std/os/path/path */
  kk_drop_match(_self, {kk_std_os_path__path_dup(p);}, {}, _ctx)
  kk_std_os_path__path _x3575;
  bool _x3576 = kk_bool_unbox(_b_3039); /*bool*/
  _x3575 = kk_std_os_path__mlift2706_appdir(p, _x3576, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x3575, _ctx);
}

kk_std_os_path__path kk_std_os_path__mlift2707_appdir(kk_std_os_path__path _y_15, kk_context_t* _ctx) { /* (path) -> io path */ 
  kk_std_os_path__path p;
  kk_box_t _x3551 = kk_std_core_hnd__open_none1(kk_std_os_path__new_mlift2707_appdir_fun3552(_ctx), kk_std_os_path__path_box(_y_15, _ctx), _ctx); /*3239*/
  p = kk_std_os_path__path_unbox(_x3551, _ctx); /*std/os/path/path*/
  bool x_2811;
  bool _match_3289;
  kk_string_t _x3555;
  kk_box_t _x3556;
  kk_box_t _x3560;
  kk_std_os_path__path _x3561 = kk_std_os_path__path_dup(p); /*std/os/path/path*/
  _x3560 = kk_std_os_path__path_box(_x3561, _ctx); /*3238*/
  _x3556 = kk_std_core_hnd__open_none1(kk_std_os_path__new_mlift2707_appdir_fun3557(_ctx), _x3560, _ctx); /*3239*/
  _x3555 = kk_string_unbox(_x3556); /*string*/
  kk_string_t _x3562;
  kk_define_string_literal(, _s3563, 3, "bin")
  _x3562 = kk_string_dup(_s3563); /*string*/
  _match_3289 = kk_string_is_eq(_x3555,_x3562,kk_context()); /*bool*/
  if (_match_3289) {
    x_2811 = true; /*bool*/
  }
  else {
    kk_string_t _x3564;
    kk_box_t _x3565;
    kk_box_t _x3569;
    kk_std_os_path__path _x3570 = kk_std_os_path__path_dup(p); /*std/os/path/path*/
    _x3569 = kk_std_os_path__path_box(_x3570, _ctx); /*3238*/
    _x3565 = kk_std_core_hnd__open_none1(kk_std_os_path__new_mlift2707_appdir_fun3566(_ctx), _x3569, _ctx); /*3239*/
    _x3564 = kk_string_unbox(_x3565); /*string*/
    kk_string_t _x3571;
    kk_define_string_literal(, _s3572, 3, "exe")
    _x3571 = kk_string_dup(_s3572); /*string*/
    x_2811 = kk_string_is_eq(_x3564,_x3571,kk_context()); /*bool*/
  }
  if (kk_yielding(kk_context())) {
    kk_box_t _x3573 = kk_std_core_hnd_yield_extend(kk_std_os_path__new_mlift2707_appdir_fun3574(p, _ctx), _ctx); /*3991*/
    return kk_std_os_path__path_unbox(_x3573, _ctx);
  }
  return kk_std_os_path__mlift2706_appdir(p, x_2811, _ctx);
}
 
// Return the base directory that contains the currently running application.
// First tries `app-path().nobase`; if that ends in the ``bin`` or ``exe`` directory it
// returns the parent of that directory.


// lift anonymous function
struct kk_std_os_path_appdir_fun3578__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path_appdir_fun3578(kk_function_t _fself, kk_box_t _b_3043, kk_context_t* _ctx);
static kk_function_t kk_std_os_path_new_appdir_fun3578(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path_appdir_fun3578, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_path_appdir_fun3578(kk_function_t _fself, kk_box_t _b_3043, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_os_path__path _x3579;
  kk_std_os_path__path _x3580 = kk_std_os_path__path_unbox(_b_3043, _ctx); /*std/os/path/path*/
  _x3579 = kk_std_os_path__mlift2707_appdir(_x3580, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x3579, _ctx);
}


// lift anonymous function
struct kk_std_os_path_appdir_fun3582__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path_appdir_fun3582(kk_function_t _fself, kk_box_t _b_3046, kk_context_t* _ctx);
static kk_function_t kk_std_os_path_new_appdir_fun3582(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path_appdir_fun3582, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_path_appdir_fun3582(kk_function_t _fself, kk_box_t _b_3046, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_os_path__path _x3583;
  kk_std_os_path__path _x3584 = kk_std_os_path__path_unbox(_b_3046, _ctx); /*std/os/path/path*/
  _x3583 = kk_std_os_path_nobase(_x3584, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x3583, _ctx);
}


// lift anonymous function
struct kk_std_os_path_appdir_fun3587__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path_appdir_fun3587(kk_function_t _fself, kk_box_t _b_3051, kk_context_t* _ctx);
static kk_function_t kk_std_os_path_new_appdir_fun3587(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path_appdir_fun3587, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_path_appdir_fun3587(kk_function_t _fself, kk_box_t _b_3051, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x3588;
  kk_std_os_path__path _x3589 = kk_std_os_path__path_unbox(_b_3051, _ctx); /*std/os/path/path*/
  _x3588 = kk_std_os_path_basename(_x3589, _ctx); /*string*/
  return kk_string_box(_x3588);
}


// lift anonymous function
struct kk_std_os_path_appdir_fun3596__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path_appdir_fun3596(kk_function_t _fself, kk_box_t _b_3054, kk_context_t* _ctx);
static kk_function_t kk_std_os_path_new_appdir_fun3596(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path_appdir_fun3596, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_path_appdir_fun3596(kk_function_t _fself, kk_box_t _b_3054, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x3597;
  kk_std_os_path__path _x3598 = kk_std_os_path__path_unbox(_b_3054, _ctx); /*std/os/path/path*/
  _x3597 = kk_std_os_path_basename(_x3598, _ctx); /*string*/
  return kk_string_box(_x3597);
}


// lift anonymous function
struct kk_std_os_path_appdir_fun3604__t {
  struct kk_function_s _base;
  kk_std_os_path__path p;
};
static kk_box_t kk_std_os_path_appdir_fun3604(kk_function_t _fself, kk_box_t _b_3060, kk_context_t* _ctx);
static kk_function_t kk_std_os_path_new_appdir_fun3604(kk_std_os_path__path p, kk_context_t* _ctx) {
  struct kk_std_os_path_appdir_fun3604__t* _self = kk_function_alloc_as(struct kk_std_os_path_appdir_fun3604__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_os_path_appdir_fun3604, kk_context());
  _self->p = p;
  return &_self->_base;
}

static kk_box_t kk_std_os_path_appdir_fun3604(kk_function_t _fself, kk_box_t _b_3060, kk_context_t* _ctx) {
  struct kk_std_os_path_appdir_fun3604__t* _self = kk_function_as(struct kk_std_os_path_appdir_fun3604__t*, _fself);
  kk_std_os_path__path p = _self->p; /* std/os/path/path */
  kk_drop_match(_self, {kk_std_os_path__path_dup(p);}, {}, _ctx)
  kk_std_os_path__path _x3605;
  bool _x3606 = kk_bool_unbox(_b_3060); /*bool*/
  _x3605 = kk_std_os_path__mlift2706_appdir(p, _x3606, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x3605, _ctx);
}


// lift anonymous function
struct kk_std_os_path_appdir_fun3608__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path_appdir_fun3608(kk_function_t _fself, kk_box_t _b_3063, kk_context_t* _ctx);
static kk_function_t kk_std_os_path_new_appdir_fun3608(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path_appdir_fun3608, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_path_appdir_fun3608(kk_function_t _fself, kk_box_t _b_3063, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_os_path__path _x3609;
  kk_std_os_path__path _x3610 = kk_std_os_path__path_unbox(_b_3063, _ctx); /*std/os/path/path*/
  _x3609 = kk_std_os_path_nobase(_x3610, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x3609, _ctx);
}

kk_std_os_path__path kk_std_os_path_appdir(kk_context_t* _ctx) { /* () -> io path */ 
  kk_std_os_path__path x_2813 = kk_std_os_path_app_path(_ctx); /*std/os/path/path*/;
  if (kk_yielding(kk_context())) {
    kk_std_os_path__path_drop(x_2813, _ctx);
    kk_box_t _x3577 = kk_std_core_hnd_yield_extend(kk_std_os_path_new_appdir_fun3578(_ctx), _ctx); /*3991*/
    return kk_std_os_path__path_unbox(_x3577, _ctx);
  }
  kk_std_os_path__path p;
  kk_box_t _x3581 = kk_std_core_hnd__open_none1(kk_std_os_path_new_appdir_fun3582(_ctx), kk_std_os_path__path_box(x_2813, _ctx), _ctx); /*3239*/
  p = kk_std_os_path__path_unbox(_x3581, _ctx); /*std/os/path/path*/
  bool x0_2817;
  bool _match_3287;
  kk_string_t _x3585;
  kk_box_t _x3586;
  kk_box_t _x3590;
  kk_std_os_path__path _x3591 = kk_std_os_path__path_dup(p); /*std/os/path/path*/
  _x3590 = kk_std_os_path__path_box(_x3591, _ctx); /*3238*/
  _x3586 = kk_std_core_hnd__open_none1(kk_std_os_path_new_appdir_fun3587(_ctx), _x3590, _ctx); /*3239*/
  _x3585 = kk_string_unbox(_x3586); /*string*/
  kk_string_t _x3592;
  kk_define_string_literal(, _s3593, 3, "bin")
  _x3592 = kk_string_dup(_s3593); /*string*/
  _match_3287 = kk_string_is_eq(_x3585,_x3592,kk_context()); /*bool*/
  if (_match_3287) {
    x0_2817 = true; /*bool*/
  }
  else {
    kk_string_t _x3594;
    kk_box_t _x3595;
    kk_box_t _x3599;
    kk_std_os_path__path _x3600 = kk_std_os_path__path_dup(p); /*std/os/path/path*/
    _x3599 = kk_std_os_path__path_box(_x3600, _ctx); /*3238*/
    _x3595 = kk_std_core_hnd__open_none1(kk_std_os_path_new_appdir_fun3596(_ctx), _x3599, _ctx); /*3239*/
    _x3594 = kk_string_unbox(_x3595); /*string*/
    kk_string_t _x3601;
    kk_define_string_literal(, _s3602, 3, "exe")
    _x3601 = kk_string_dup(_s3602); /*string*/
    x0_2817 = kk_string_is_eq(_x3594,_x3601,kk_context()); /*bool*/
  }
  if (kk_yielding(kk_context())) {
    kk_box_t _x3603 = kk_std_core_hnd_yield_extend(kk_std_os_path_new_appdir_fun3604(p, _ctx), _ctx); /*3991*/
    return kk_std_os_path__path_unbox(_x3603, _ctx);
  }
  if (x0_2817) {
    kk_box_t _x3607 = kk_std_core_hnd__open_none1(kk_std_os_path_new_appdir_fun3608(_ctx), kk_std_os_path__path_box(p, _ctx), _ctx); /*3239*/
    return kk_std_os_path__path_unbox(_x3607, _ctx);
  }
  return p;
}
 
// Change the base name of a path

kk_std_os_path__path kk_std_os_path_change_base(kk_std_os_path__path p, kk_string_t basename0, kk_context_t* _ctx) { /* (p : path, basename : string) -> path */ 
  kk_std_os_path__path q = kk_std_os_path_nobase(p, _ctx); /*std/os/path/path*/;
  kk_std_core_types__optional dirs_2823;
  kk_box_t _x3611;
  kk_std_core__list _x3612;
  kk_std_core__list _x0 = q.parts;
  kk_std_core__list_dup(_x0);
  _x3612 = _x0; /*list<string>*/
  _x3611 = kk_std_core__list_box(_x3612, _ctx); /*108*/
  dirs_2823 = kk_std_core_types__new_Optional(_x3611, _ctx); /*optional<list<string>>*/
  kk_std_core__list parts0;
  kk_std_core__list _x3613;
  kk_vector_t v_21689;
  kk_string_t _x3614;
  kk_define_string_literal(, _s3615, 1, "/")
  _x3614 = kk_string_dup(_s3615); /*string*/
  v_21689 = kk_string_splitv(basename0,_x3614,kk_context()); /*vector<string>*/
  _x3613 = kk_std_core_vlist(v_21689, kk_std_core_types__new_None(_ctx), _ctx); /*list<2154>*/
  kk_std_core__list _x3616;
  if (kk_std_core_types__is_Optional(dirs_2823)) {
    kk_box_t _box_x3071 = dirs_2823._cons.Optional.value;
    kk_std_core__list _dirs_1291 = kk_std_core__list_unbox(_box_x3071, NULL);
    kk_std_core__list_dup(_dirs_1291);
    kk_std_core_types__optional_drop(dirs_2823, _ctx);
    _x3616 = _dirs_1291; /*list<string>*/
    goto _match3617;
  }
  _x3616 = kk_std_core__new_Nil(_ctx); /*list<string>*/
  _match3617: ;
  parts0 = kk_std_os_path_push_parts(_x3613, _x3616, _ctx); /*list<string>*/
  kk_string_t _x3619;
  kk_string_t _x = q.root;
  kk_string_dup(_x);
  kk_std_os_path__path_drop(q, _ctx);
  _x3619 = _x; /*string*/
  return kk_std_os_path__new_Path(_x3619, parts0, _ctx);
}

kk_std_core_types__tuple2_ kk_std_os_path_split_base(kk_string_t basename0, kk_context_t* _ctx) { /* (basename : string) -> (string, string) */ 
  kk_std_core_types__maybe _match_3283;
  size_t i;
  kk_string_t _x3620 = kk_string_dup(basename0); /*string*/
  kk_string_t _x3621;
  kk_define_string_literal(, _s3622, 1, ".")
  _x3621 = kk_string_dup(_s3622); /*string*/
  i = kk_string_last_index_of1(_x3620,_x3621,kk_context()); /*size_t*/
  bool _match_3284 = kk_std_core_is_zero_1(i, _ctx); /*bool*/;
  if (_match_3284) {
    _match_3283 = kk_std_core_types__new_Nothing(_ctx); /*forall<a> maybe<a>*/
  }
  else {
    kk_std_core__sslice _b_3078_3072;
    kk_string_t _x3623 = kk_string_dup(basename0); /*string*/
    size_t _x3624 = kk_std_core_decr_1(i, _ctx); /*size_t*/
    size_t _x3625;
    kk_string_t _x3626;
    kk_define_string_literal(, _s3627, 1, ".")
    _x3626 = kk_string_dup(_s3627); /*string*/
    _x3625 = kk_string_len(_x3626,kk_context()); /*size_t*/
    _b_3078_3072 = kk_std_core__new_Sslice(_x3623, _x3624, _x3625, _ctx); /*sslice*/
    _match_3283 = kk_std_core_types__new_Just(kk_std_core__sslice_box(_b_3078_3072, _ctx), _ctx); /*forall<a> maybe<a>*/
  }
  if (kk_std_core_types__is_Just(_match_3283)) {
    kk_box_t _box_x3073 = _match_3283._cons.Just.value;
    kk_std_core__sslice slice = kk_std_core__sslice_unbox(_box_x3073, NULL);
    kk_string_drop(basename0, _ctx);
    kk_std_core__sslice_dup(slice);
    kk_std_core_types__maybe_drop(_match_3283, _ctx);
    kk_string_t _b_3079_3074;
    kk_std_core__sslice _x3629;
    kk_std_core__sslice _x3630 = kk_std_core__sslice_dup(slice); /*sslice*/
    _x3629 = kk_std_core_before(_x3630, _ctx); /*sslice*/
    _b_3079_3074 = kk_std_core_string_3(_x3629, _ctx); /*string*/
    kk_string_t _b_3080_3075;
    kk_std_core__sslice _x3631 = kk_std_core_after(slice, _ctx); /*sslice*/
    _b_3080_3075 = kk_std_core_string_3(_x3631, _ctx); /*string*/
    return kk_std_core_types__new_dash__lp__comma__rp_(kk_string_box(_b_3079_3074), kk_string_box(_b_3080_3075), _ctx);
  }
  kk_box_t _x3632;
  kk_string_t _x3633 = kk_string_empty(); /*string*/
  _x3632 = kk_string_box(_x3633); /*7*/
  return kk_std_core_types__new_dash__lp__comma__rp_(kk_string_box(basename0), _x3632, _ctx);
}
 
// Change the extension of a path.
// Only adds a dot if the extname does not already start with a dot.

kk_std_os_path__path kk_std_os_path_change_ext(kk_std_os_path__path p, kk_string_t extname0, kk_context_t* _ctx) { /* (p : path, extname : string) -> path */ 
  kk_string_t _match_3278;
  kk_std_core__list _match_3282;
  kk_std_core__list _x = p.parts;
  kk_std_core__list_dup(_x);
  _match_3282 = _x; /*list<string>*/
  if (kk_std_core__is_Cons(_match_3282)) {
    struct kk_std_core_Cons* _con3636 = kk_std_core__as_Cons(_match_3282);
    kk_box_t _box_x3083 = _con3636->head;
    kk_std_core__list _pat0 = _con3636->tail;
    kk_string_t x = kk_string_unbox(_box_x3083);
    if (kk_std_core__list_is_unique(_match_3282)) {
      kk_std_core__list_drop(_pat0, _ctx);
      kk_std_core__list_free(_match_3282);
    }
    else {
      kk_string_dup(x);
      kk_std_core__list_decref(_match_3282, _ctx);
    }
    _match_3278 = x; /*string*/
    goto _match3635;
  }
  _match_3278 = kk_string_empty(); /*string*/
  _match3635: ;
  kk_std_core__list _match_3277;
  kk_std_core__list _x3639;
  kk_std_core__list _x0 = p.parts;
  kk_std_core__list_dup(_x0);
  _x3639 = _x0; /*list<string>*/
  _match_3277 = kk_std_core_tail_1(_x3639, _ctx); /*list<20131>*/
  kk_std_core_types__tuple2_ _match_3279 = kk_std_os_path_split_base(_match_3278, _ctx); /*(string, string)*/;
  kk_box_t _box_x3084 = _match_3279.fst;
  kk_box_t _box_x3085 = _match_3279.snd;
  kk_string_t stemname0 = kk_string_unbox(_box_x3084);
  kk_string_dup(stemname0);
  kk_std_core_types__tuple2__drop(_match_3279, _ctx);
  kk_string_t newext;
  bool _match_3280;
  kk_std_core_types__maybe m_2834;
  bool _match_3281;
  kk_string_t _x3642 = kk_string_dup(extname0); /*string*/
  kk_string_t _x3643;
  kk_define_string_literal(, _s3644, 1, ".")
  _x3643 = kk_string_dup(_s3644); /*string*/
  _match_3281 = kk_string_starts_with(_x3642,_x3643,kk_context()); /*bool*/
  if (_match_3281) {
    kk_std_core__sslice _b_3087_3086;
    kk_string_t _x3645 = kk_string_dup(extname0); /*string*/
    size_t _x3646;
    kk_string_t _x3647;
    kk_define_string_literal(, _s3648, 1, ".")
    _x3647 = kk_string_dup(_s3648); /*string*/
    _x3646 = kk_string_len(_x3647,kk_context()); /*size_t*/
    size_t _x3649;
    size_t _x3650;
    kk_string_t _x3651 = kk_string_dup(extname0); /*string*/
    _x3650 = kk_string_len(_x3651,kk_context()); /*size_t*/
    size_t _x3652;
    kk_string_t _x3653;
    kk_define_string_literal(, _s3654, 1, ".")
    _x3653 = kk_string_dup(_s3654); /*string*/
    _x3652 = kk_string_len(_x3653,kk_context()); /*size_t*/
    _x3649 = (_x3650 - _x3652); /*size_t*/
    _b_3087_3086 = kk_std_core__new_Sslice(_x3645, _x3646, _x3649, _ctx); /*sslice*/
    m_2834 = kk_std_core_types__new_Just(kk_std_core__sslice_box(_b_3087_3086, _ctx), _ctx); /*maybe<sslice>*/
  }
  else {
    m_2834 = kk_std_core_types__new_Nothing(_ctx); /*maybe<sslice>*/
  }
  if (kk_std_core_types__is_Nothing(m_2834)) {
    _match_3280 = false; /*bool*/
  }
  else {
    kk_std_core_types__maybe_drop(m_2834, _ctx);
    _match_3280 = true; /*bool*/
  }
  if (_match_3280) {
    newext = extname0; /*string*/
  }
  else {
    kk_string_t _x3655;
    kk_define_string_literal(, _s3656, 1, ".")
    _x3655 = kk_string_dup(_s3656); /*string*/
    newext = kk_std_core__lp__plus__plus__1_rp_(_x3655, extname0, _ctx); /*string*/
  }
  kk_string_t s0_2838 = kk_std_core__lp__plus__plus__1_rp_(stemname0, newext, _ctx); /*string*/;
  kk_std_core_types__optional dirs0_2839 = kk_std_core_types__new_Optional(kk_std_core__list_box(_match_3277, _ctx), _ctx); /*optional<list<string>>*/;
  kk_std_core__list parts0;
  kk_std_core__list _x3657;
  kk_vector_t v_21689;
  kk_string_t _x3658;
  kk_define_string_literal(, _s3659, 1, "/")
  _x3658 = kk_string_dup(_s3659); /*string*/
  v_21689 = kk_string_splitv(s0_2838,_x3658,kk_context()); /*vector<string>*/
  _x3657 = kk_std_core_vlist(v_21689, kk_std_core_types__new_None(_ctx), _ctx); /*list<2154>*/
  kk_std_core__list _x3660;
  if (kk_std_core_types__is_Optional(dirs0_2839)) {
    kk_box_t _box_x3090 = dirs0_2839._cons.Optional.value;
    kk_std_core__list _dirs_1291 = kk_std_core__list_unbox(_box_x3090, NULL);
    kk_std_core__list_dup(_dirs_1291);
    kk_std_core_types__optional_drop(dirs0_2839, _ctx);
    _x3660 = _dirs_1291; /*list<string>*/
    goto _match3661;
  }
  _x3660 = kk_std_core__new_Nil(_ctx); /*list<string>*/
  _match3661: ;
  parts0 = kk_std_os_path_push_parts(_x3657, _x3660, _ctx); /*list<string>*/
  kk_string_t _x3663;
  kk_string_t _x00 = p.root;
  kk_string_dup(_x00);
  kk_std_os_path__path_drop(p, _ctx);
  _x3663 = _x00; /*string*/
  return kk_std_os_path__new_Path(_x3663, parts0, _ctx);
}
 
// Return the extension of path (without the preceding dot (`'.'`))
// `"/foo/bar.svg.txt".path.extname === "txt"`

kk_string_t kk_std_os_path_extname(kk_std_os_path__path p, kk_context_t* _ctx) { /* (p : path) -> string */ 
  kk_std_core_types__tuple2_ _this_2843;
  kk_string_t basename_2844 = kk_std_os_path_basename(p, _ctx); /*string*/;
  kk_std_core_types__maybe _match_3275;
  size_t i;
  kk_string_t _x3664 = kk_string_dup(basename_2844); /*string*/
  kk_string_t _x3665;
  kk_define_string_literal(, _s3666, 1, ".")
  _x3665 = kk_string_dup(_s3666); /*string*/
  i = kk_string_last_index_of1(_x3664,_x3665,kk_context()); /*size_t*/
  bool _match_3276 = kk_std_core_is_zero_1(i, _ctx); /*bool*/;
  if (_match_3276) {
    _match_3275 = kk_std_core_types__new_Nothing(_ctx); /*forall<a> maybe<a>*/
  }
  else {
    kk_std_core__sslice _b_3097_3091;
    kk_string_t _x3667 = kk_string_dup(basename_2844); /*string*/
    size_t _x3668 = kk_std_core_decr_1(i, _ctx); /*size_t*/
    size_t _x3669;
    kk_string_t _x3670;
    kk_define_string_literal(, _s3671, 1, ".")
    _x3670 = kk_string_dup(_s3671); /*string*/
    _x3669 = kk_string_len(_x3670,kk_context()); /*size_t*/
    _b_3097_3091 = kk_std_core__new_Sslice(_x3667, _x3668, _x3669, _ctx); /*sslice*/
    _match_3275 = kk_std_core_types__new_Just(kk_std_core__sslice_box(_b_3097_3091, _ctx), _ctx); /*forall<a> maybe<a>*/
  }
  if (kk_std_core_types__is_Just(_match_3275)) {
    kk_box_t _box_x3092 = _match_3275._cons.Just.value;
    kk_std_core__sslice slice = kk_std_core__sslice_unbox(_box_x3092, NULL);
    kk_string_drop(basename_2844, _ctx);
    kk_std_core__sslice_dup(slice);
    kk_std_core_types__maybe_drop(_match_3275, _ctx);
    kk_string_t _b_3098_3093;
    kk_std_core__sslice _x3674;
    kk_std_core__sslice _x3675 = kk_std_core__sslice_dup(slice); /*sslice*/
    _x3674 = kk_std_core_before(_x3675, _ctx); /*sslice*/
    _b_3098_3093 = kk_std_core_string_3(_x3674, _ctx); /*string*/
    kk_string_t _b_3099_3094;
    kk_std_core__sslice _x3676 = kk_std_core_after(slice, _ctx); /*sslice*/
    _b_3099_3094 = kk_std_core_string_3(_x3676, _ctx); /*string*/
    _this_2843 = kk_std_core_types__new_dash__lp__comma__rp_(kk_string_box(_b_3098_3093), kk_string_box(_b_3099_3094), _ctx); /*(string, string)*/
    goto _match3672;
  }
  kk_box_t _x3677;
  kk_string_t _x3678 = kk_string_empty(); /*string*/
  _x3677 = kk_string_box(_x3678); /*7*/
  _this_2843 = kk_std_core_types__new_dash__lp__comma__rp_(kk_string_box(basename_2844), _x3677, _ctx); /*(string, string)*/
  _match3672: ;
  kk_box_t _box_x3102 = _this_2843.fst;
  kk_box_t _box_x3103 = _this_2843.snd;
  kk_string_t _x = kk_string_unbox(_box_x3103);
  kk_string_dup(_x);
  kk_std_core_types__tuple2__drop(_this_2843, _ctx);
  return _x;
}
 
// Change the stem name of a path

kk_std_os_path__path kk_std_os_path_change_stem(kk_std_os_path__path p, kk_string_t stemname0, kk_context_t* _ctx) { /* (p : path, stemname : string) -> path */ 
  kk_string_t ext;
  kk_std_os_path__path _x3682 = kk_std_os_path__path_dup(p); /*std/os/path/path*/
  ext = kk_std_os_path_extname(_x3682, _ctx); /*string*/
  kk_string_t basename_2848;
  kk_string_t _x3683;
  bool _match_3274;
  kk_string_t _x3684 = kk_string_dup(ext); /*string*/
  _match_3274 = kk_std_core_is_empty_2(_x3684, _ctx); /*bool*/
  if (_match_3274) {
    kk_string_drop(ext, _ctx);
    _x3683 = kk_string_empty(); /*string*/
  }
  else {
    kk_string_t _x3686;
    kk_define_string_literal(, _s3687, 1, ".")
    _x3686 = kk_string_dup(_s3687); /*string*/
    _x3683 = kk_std_core__lp__plus__plus__1_rp_(_x3686, ext, _ctx); /*string*/
  }
  basename_2848 = kk_std_core__lp__plus__plus__1_rp_(stemname0, _x3683, _ctx); /*string*/
  kk_std_os_path__path q = kk_std_os_path_nobase(p, _ctx); /*std/os/path/path*/;
  kk_std_core_types__optional dirs_2851;
  kk_box_t _x3688;
  kk_std_core__list _x3689;
  kk_std_core__list _x0 = q.parts;
  kk_std_core__list_dup(_x0);
  _x3689 = _x0; /*list<string>*/
  _x3688 = kk_std_core__list_box(_x3689, _ctx); /*108*/
  dirs_2851 = kk_std_core_types__new_Optional(_x3688, _ctx); /*optional<list<string>>*/
  kk_std_core__list parts0;
  kk_std_core__list _x3690;
  kk_vector_t v_21689;
  kk_string_t _x3691;
  kk_define_string_literal(, _s3692, 1, "/")
  _x3691 = kk_string_dup(_s3692); /*string*/
  v_21689 = kk_string_splitv(basename_2848,_x3691,kk_context()); /*vector<string>*/
  _x3690 = kk_std_core_vlist(v_21689, kk_std_core_types__new_None(_ctx), _ctx); /*list<2154>*/
  kk_std_core__list _x3693;
  if (kk_std_core_types__is_Optional(dirs_2851)) {
    kk_box_t _box_x3106 = dirs_2851._cons.Optional.value;
    kk_std_core__list _dirs_1291 = kk_std_core__list_unbox(_box_x3106, NULL);
    kk_std_core__list_dup(_dirs_1291);
    kk_std_core_types__optional_drop(dirs_2851, _ctx);
    _x3693 = _dirs_1291; /*list<string>*/
    goto _match3694;
  }
  _x3693 = kk_std_core__new_Nil(_ctx); /*list<string>*/
  _match3694: ;
  parts0 = kk_std_os_path_push_parts(_x3690, _x3693, _ctx); /*list<string>*/
  kk_string_t _x3696;
  kk_string_t _x = q.root;
  kk_string_dup(_x);
  kk_std_os_path__path_drop(q, _ctx);
  _x3696 = _x; /*string*/
  return kk_std_os_path__new_Path(_x3696, parts0, _ctx);
}
 
// Combine multiple paths using `(/)`.


// lift anonymous function
struct kk_std_os_path_combine_fun3707__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path_combine_fun3707(kk_function_t _fself, kk_box_t _b_3113, kk_box_t _b_3114, kk_context_t* _ctx);
static kk_function_t kk_std_os_path_new_combine_fun3707(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path_combine_fun3707, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_path_combine_fun3707(kk_function_t _fself, kk_box_t _b_3113, kk_box_t _b_3114, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_os_path__path _x3708;
  kk_std_os_path__path _x3709 = kk_std_os_path__path_unbox(_b_3113, _ctx); /*std/os/path/path*/
  kk_std_os_path__path _x3710 = kk_std_os_path__path_unbox(_b_3114, _ctx); /*std/os/path/path*/
  _x3708 = kk_std_os_path__lp__fs__rp_(_x3709, _x3710, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x3708, _ctx);
}

kk_std_os_path__path kk_std_os_path_combine(kk_std_core__list ps, kk_context_t* _ctx) { /* (ps : list<path>) -> path */ 
  if (kk_std_core__is_Nil(ps)) {
    kk_string_t _x3697;
    kk_std_core_types__optional _match_3273 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
    if (kk_std_core_types__is_Optional(_match_3273)) {
      kk_box_t _box_x3107 = _match_3273._cons.Optional.value;
      kk_string_t _root_1093 = kk_string_unbox(_box_x3107);
      kk_string_dup(_root_1093);
      kk_std_core_types__optional_drop(_match_3273, _ctx);
      _x3697 = _root_1093; /*string*/
      goto _match3698;
    }
    _x3697 = kk_string_empty(); /*string*/
    _match3698: ;
    kk_std_core__list _x3701;
    kk_std_core_types__optional _match_3272 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
    if (kk_std_core_types__is_Optional(_match_3272)) {
      kk_box_t _box_x3108 = _match_3272._cons.Optional.value;
      kk_std_core__list _parts_1098 = kk_std_core__list_unbox(_box_x3108, NULL);
      kk_std_core__list_dup(_parts_1098);
      kk_std_core_types__optional_drop(_match_3272, _ctx);
      _x3701 = _parts_1098; /*list<string>*/
      goto _match3702;
    }
    _x3701 = kk_std_core__new_Nil(_ctx); /*list<string>*/
    _match3702: ;
    return kk_std_os_path__new_Path(_x3697, _x3701, _ctx);
  }
  struct kk_std_core_Cons* _con3704 = kk_std_core__as_Cons(ps);
  kk_box_t _box_x3109 = _con3704->head;
  kk_std_core__list pp = _con3704->tail;
  kk_std_os_path__path p = kk_std_os_path__path_unbox(_box_x3109, NULL);
  if (kk_std_core__list_is_unique(ps)) {
    kk_std_os_path__path_dup(p);
    kk_box_drop(_box_x3109, _ctx);
    kk_std_core__list_free(ps);
  }
  else {
    kk_std_os_path__path_dup(p);
    kk_std_core__list_dup(pp);
    kk_std_core__list_decref(ps, _ctx);
  }
  kk_box_t _x3706 = kk_std_core_foldl(pp, kk_std_os_path__path_box(p, _ctx), kk_std_os_path_new_combine_fun3707(_ctx), _ctx); /*15010*/
  return kk_std_os_path__path_unbox(_x3706, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_os_path__mlift2708_realpath_fun3712__t_1 {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path__mlift2708_realpath_fun3712_1(kk_function_t _fself, kk_box_t _b_3120, kk_context_t* _ctx);
static kk_function_t kk_std_os_path__new_mlift2708_realpath_fun3712_1(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path__mlift2708_realpath_fun3712_1, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_path__mlift2708_realpath_fun3712_1(kk_function_t _fself, kk_box_t _b_3120, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_os_path__path _x3713;
  kk_string_t _x3714 = kk_string_unbox(_b_3120); /*string*/
  _x3713 = kk_std_os_path_path(_x3714, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x3713, _ctx);
}

kk_std_os_path__path kk_std_os_path__mlift2708_realpath_1(kk_string_t _y_18, kk_context_t* _ctx) { /* (string) -> io path */ 
  kk_box_t _x3711 = kk_std_core_hnd__open_none1(kk_std_os_path__new_mlift2708_realpath_fun3712_1(_ctx), kk_string_box(_y_18), _ctx); /*3239*/
  return kk_std_os_path__path_unbox(_x3711, _ctx);
}
 
// Convert a path to the absolute path on the file system.
// The overload on a plain string is necessary as it allows
// for unnormalized paths with `".."` parts. For example
// `"/foo/symlink/../test.txt"` may resolve to `"/bar/test.txt"` if
// ``symlink`` is a symbolic link to a sub directory of `"/bar"`.


// lift anonymous function
struct kk_std_os_path_realpath_fun3716__t_1 {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path_realpath_fun3716_1(kk_function_t _fself, kk_box_t _b_3124, kk_context_t* _ctx);
static kk_function_t kk_std_os_path_new_realpath_fun3716_1(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path_realpath_fun3716_1, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_path_realpath_fun3716_1(kk_function_t _fself, kk_box_t _b_3124, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_os_path__path _x3717;
  kk_string_t _x3718 = kk_string_unbox(_b_3124); /*string*/
  _x3717 = kk_std_os_path__mlift2708_realpath_1(_x3718, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x3717, _ctx);
}


// lift anonymous function
struct kk_std_os_path_realpath_fun3719__t_1 {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path_realpath_fun3719_1(kk_function_t _fself, kk_box_t _b_3127, kk_context_t* _ctx);
static kk_function_t kk_std_os_path_new_realpath_fun3719_1(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path_realpath_fun3719_1, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_path_realpath_fun3719_1(kk_function_t _fself, kk_box_t _b_3127, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_os_path__path _x3720;
  kk_string_t _x3721 = kk_string_unbox(_b_3127); /*string*/
  _x3720 = kk_std_os_path_path(_x3721, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x3720, _ctx);
}

kk_std_os_path__path kk_std_os_path_realpath_1(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> io path */ 
  kk_string_t x_2858 = kk_std_os_path_xrealpath(s, _ctx); /*string*/;
  kk_box_t _x3715;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_2858, _ctx);
    _x3715 = kk_std_core_hnd_yield_extend(kk_std_os_path_new_realpath_fun3716_1(_ctx), _ctx); /*3991*/
  }
  else {
    _x3715 = kk_std_core_hnd__open_none1(kk_std_os_path_new_realpath_fun3719_1(_ctx), kk_string_box(x_2858), _ctx); /*3991*/
  }
  return kk_std_os_path__path_unbox(_x3715, _ctx);
}
 
// Convert a path to the absolute path on the file system.
// The path is not required to exist on disk. However, if it
// exists any permissions and symbolic links are resolved fully.
// `".".realpath` (to get the current working directory)
// `"/foo".realpath` (to resolve the full root, like `"c:/foo"` on windows)


// lift anonymous function
struct kk_std_os_path_realpath_fun3723__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path_realpath_fun3723(kk_function_t _fself, kk_box_t _b_3133, kk_context_t* _ctx);
static kk_function_t kk_std_os_path_new_realpath_fun3723(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path_realpath_fun3723, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_path_realpath_fun3723(kk_function_t _fself, kk_box_t _b_3133, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x3724;
  kk_std_os_path__path _x3725 = kk_std_os_path__path_unbox(_b_3133, _ctx); /*std/os/path/path*/
  _x3724 = kk_std_os_path_string(_x3725, _ctx); /*string*/
  return kk_string_box(_x3724);
}


// lift anonymous function
struct kk_std_os_path_realpath_fun3727__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path_realpath_fun3727(kk_function_t _fself, kk_box_t _b_3137, kk_context_t* _ctx);
static kk_function_t kk_std_os_path_new_realpath_fun3727(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path_realpath_fun3727, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_path_realpath_fun3727(kk_function_t _fself, kk_box_t _b_3137, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_os_path__path _x3728;
  kk_string_t _x3729 = kk_string_unbox(_b_3137); /*string*/
  _x3728 = kk_std_os_path__mlift2708_realpath_1(_x3729, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x3728, _ctx);
}


// lift anonymous function
struct kk_std_os_path_realpath_fun3730__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path_realpath_fun3730(kk_function_t _fself, kk_box_t _b_3140, kk_context_t* _ctx);
static kk_function_t kk_std_os_path_new_realpath_fun3730(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path_realpath_fun3730, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_path_realpath_fun3730(kk_function_t _fself, kk_box_t _b_3140, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_os_path__path _x3731;
  kk_string_t _x3732 = kk_string_unbox(_b_3140); /*string*/
  _x3731 = kk_std_os_path_path(_x3732, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x3731, _ctx);
}

kk_std_os_path__path kk_std_os_path_realpath(kk_std_os_path__path p, kk_context_t* _ctx) { /* (p : path) -> io path */ 
  kk_string_t s_2862;
  kk_box_t _x3722 = kk_std_core_hnd__open_none1(kk_std_os_path_new_realpath_fun3723(_ctx), kk_std_os_path__path_box(p, _ctx), _ctx); /*3239*/
  s_2862 = kk_string_unbox(_x3722); /*string*/
  kk_string_t x_2863 = kk_std_os_path_xrealpath(s_2862, _ctx); /*string*/;
  kk_box_t _x3726;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_2863, _ctx);
    _x3726 = kk_std_core_hnd_yield_extend(kk_std_os_path_new_realpath_fun3727(_ctx), _ctx); /*3991*/
  }
  else {
    _x3726 = kk_std_core_hnd__open_none1(kk_std_os_path_new_realpath_fun3730(_ctx), kk_string_box(x_2863), _ctx); /*3991*/
  }
  return kk_std_os_path__path_unbox(_x3726, _ctx);
}
 
// Returns the current working directory.
// Equal to `".".realpath`.


// lift anonymous function
struct kk_std_os_path_cwd_fun3736__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path_cwd_fun3736(kk_function_t _fself, kk_box_t _b_3145, kk_context_t* _ctx);
static kk_function_t kk_std_os_path_new_cwd_fun3736(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path_cwd_fun3736, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_path_cwd_fun3736(kk_function_t _fself, kk_box_t _b_3145, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_os_path__path _x3737;
  kk_string_t _x3738 = kk_string_unbox(_b_3145); /*string*/
  _x3737 = kk_std_os_path__mlift2708_realpath_1(_x3738, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x3737, _ctx);
}


// lift anonymous function
struct kk_std_os_path_cwd_fun3739__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path_cwd_fun3739(kk_function_t _fself, kk_box_t _b_3148, kk_context_t* _ctx);
static kk_function_t kk_std_os_path_new_cwd_fun3739(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path_cwd_fun3739, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_path_cwd_fun3739(kk_function_t _fself, kk_box_t _b_3148, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_os_path__path _x3740;
  kk_string_t _x3741 = kk_string_unbox(_b_3148); /*string*/
  _x3740 = kk_std_os_path_path(_x3741, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x3740, _ctx);
}

kk_std_os_path__path kk_std_os_path_cwd(kk_context_t* _ctx) { /* () -> io path */ 
  kk_string_t x_2868;
  kk_string_t _x3733;
  kk_define_string_literal(, _s3734, 1, ".")
  _x3733 = kk_string_dup(_s3734); /*string*/
  x_2868 = kk_std_os_path_xrealpath(_x3733, _ctx); /*string*/
  kk_box_t _x3735;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_2868, _ctx);
    _x3735 = kk_std_core_hnd_yield_extend(kk_std_os_path_new_cwd_fun3736(_ctx), _ctx); /*3991*/
  }
  else {
    _x3735 = kk_std_core_hnd__open_none1(kk_std_os_path_new_cwd_fun3739(_ctx), kk_string_box(x_2868), _ctx); /*3991*/
  }
  return kk_std_os_path__path_unbox(_x3735, _ctx);
}
 
// If a path has no extension, set it to the provided one.

kk_std_os_path__path kk_std_os_path_default_ext(kk_std_os_path__path p, kk_string_t newext, kk_context_t* _ctx) { /* (p : path, newext : string) -> path */ 
  bool _match_3268;
  kk_string_t s_2872;
  kk_std_os_path__path _x3742 = kk_std_os_path__path_dup(p); /*std/os/path/path*/
  s_2872 = kk_std_os_path_extname(_x3742, _ctx); /*string*/
  kk_string_t _x3743 = kk_string_empty(); /*string*/
  _match_3268 = kk_string_is_eq(s_2872,_x3743,kk_context()); /*bool*/
  if (_match_3268) {
    return kk_std_os_path_change_ext(p, newext, _ctx);
  }
  kk_string_drop(newext, _ctx);
  return p;
}
 
// monadic lift


// lift anonymous function
struct kk_std_os_path__mlift2709_homedir_fun3746__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path__mlift2709_homedir_fun3746(kk_function_t _fself, kk_box_t _b_3154, kk_context_t* _ctx);
static kk_function_t kk_std_os_path__new_mlift2709_homedir_fun3746(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path__mlift2709_homedir_fun3746, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_path__mlift2709_homedir_fun3746(kk_function_t _fself, kk_box_t _b_3154, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_os_path__path _x3747;
  kk_string_t _x3748 = kk_string_unbox(_b_3154); /*string*/
  _x3747 = kk_std_os_path_path(_x3748, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x3747, _ctx);
}

kk_std_os_path__path kk_std_os_path__mlift2709_homedir(kk_string_t _y_21, kk_context_t* _ctx) { /* (string) -> io path */ 
  kk_box_t _x3745 = kk_std_core_hnd__open_none1(kk_std_os_path__new_mlift2709_homedir_fun3746(_ctx), kk_string_box(_y_21), _ctx); /*3239*/
  return kk_std_os_path__path_unbox(_x3745, _ctx);
}
 
// Return the home directory of the current user.


// lift anonymous function
struct kk_std_os_path_homedir_fun3750__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path_homedir_fun3750(kk_function_t _fself, kk_box_t _b_3158, kk_context_t* _ctx);
static kk_function_t kk_std_os_path_new_homedir_fun3750(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path_homedir_fun3750, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_path_homedir_fun3750(kk_function_t _fself, kk_box_t _b_3158, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_os_path__path _x3751;
  kk_string_t _x3752 = kk_string_unbox(_b_3158); /*string*/
  _x3751 = kk_std_os_path__mlift2709_homedir(_x3752, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x3751, _ctx);
}


// lift anonymous function
struct kk_std_os_path_homedir_fun3753__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path_homedir_fun3753(kk_function_t _fself, kk_box_t _b_3161, kk_context_t* _ctx);
static kk_function_t kk_std_os_path_new_homedir_fun3753(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path_homedir_fun3753, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_path_homedir_fun3753(kk_function_t _fself, kk_box_t _b_3161, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_os_path__path _x3754;
  kk_string_t _x3755 = kk_string_unbox(_b_3161); /*string*/
  _x3754 = kk_std_os_path_path(_x3755, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x3754, _ctx);
}

kk_std_os_path__path kk_std_os_path_homedir(kk_context_t* _ctx) { /* () -> io path */ 
  kk_string_t x_2873 = kk_std_os_path_xhomedir(_ctx); /*string*/;
  kk_box_t _x3749;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_2873, _ctx);
    _x3749 = kk_std_core_hnd_yield_extend(kk_std_os_path_new_homedir_fun3750(_ctx), _ctx); /*3991*/
  }
  else {
    _x3749 = kk_std_core_hnd__open_none1(kk_std_os_path_new_homedir_fun3753(_ctx), kk_string_box(x_2873), _ctx); /*3991*/
  }
  return kk_std_os_path__path_unbox(_x3749, _ctx);
}

kk_std_core__list kk_std_os_path__ctail_paths_collect(kk_std_core__list ps, kk_std_core_types__ctail _acc, kk_context_t* _ctx) { /* (ps : list<string>, ctail<list<path>>) -> list<path> */ 
  kk__tailcall: ;
  if (kk_std_core__is_Cons(ps)) {
    struct kk_std_core_Cons* _con3762 = kk_std_core__as_Cons(ps);
    kk_box_t _box_x3165 = _con3762->head;
    kk_std_core__list _pat0 = _con3762->tail;
    if (kk_std_core__is_Cons(_pat0)) {
      struct kk_std_core_Cons* _con3764 = kk_std_core__as_Cons(_pat0);
      kk_string_t root0 = kk_string_unbox(_box_x3165);
      kk_box_t _box_x3166 = _con3764->head;
      kk_std_core__list rest = _con3764->tail;
      kk_string_t part = kk_string_unbox(_box_x3166);
      bool _match_3263;
      kk_integer_t _x3766;
      kk_string_t _x3767 = kk_string_dup(root0); /*string*/
      _x3766 = kk_std_core_count_1(_x3767, _ctx); /*int*/
      _match_3263 = kk_integer_eq(_x3766,(kk_integer_from_small(1)),kk_context()); /*bool*/
      bool _x3768;
      if (_match_3263) {
        bool _match_3264;
        kk_char_t c_2879;
        kk_std_core_types__maybe m_2880;
        kk_string_t _x3769 = kk_string_dup(root0); /*string*/
        m_2880 = kk_std_core_head_char(_x3769, _ctx); /*maybe<char>*/
        if (kk_std_core_types__is_Nothing(m_2880)) {
          c_2879 = ' '; /*char*/
        }
        else {
          kk_box_t _box_x3167 = m_2880._cons.Just.value;
          kk_char_t x = kk_char_unbox(_box_x3167, NULL);
          kk_std_core_types__maybe_drop(m_2880, _ctx);
          c_2879 = x; /*char*/
        }
        bool _match_3266 = kk_std_core_is_lower(c_2879, _ctx); /*bool*/;
        if (_match_3266) {
          _match_3264 = true; /*bool*/
        }
        else {
          _match_3264 = kk_std_core_is_upper(c_2879, _ctx); /*bool*/
        }
        if (_match_3264) {
          bool _match_3265;
          bool _x3771;
          kk_string_t _x3772 = kk_string_dup(part); /*string*/
          _x3771 = kk_std_core_is_empty_2(_x3772, _ctx); /*bool*/
          _match_3265 = !(_x3771); /*bool*/
          if (_match_3265) {
            kk_string_t _x3773;
            kk_define_string_literal(, _s3774, 2, "/\\")
            _x3773 = kk_string_dup(_s3774); /*string*/
            kk_string_t _x3775;
            kk_string_t _x3776 = kk_string_dup(part); /*string*/
            _x3775 = kk_std_core_head_3(_x3776, _ctx); /*string*/
            _x3768 = kk_string_contains(_x3773,_x3775,kk_context()); /*bool*/
          }
          else {
            _x3768 = false; /*bool*/
          }
        }
        else {
          _x3768 = false; /*bool*/
        }
      }
      else {
        _x3768 = false; /*bool*/
      }
      if (_x3768) {
        kk_reuse_t _ru_3258 = kk_reuse_null; /*reuse*/;
        if (kk_std_core__list_is_unique(ps)) {
          if (kk_std_core__list_is_unique(_pat0)) {
            _ru_3258 = (kk_std_core__list_reuse(_pat0));
          }
          else {
            kk_string_dup(part);
            kk_std_core__list_dup(rest);
            kk_std_core__list_decref(_pat0, _ctx);
            _ru_3258 = kk_reuse_null;
          }
          kk_std_core__list_free(ps);
        }
        else {
          kk_string_dup(part);
          kk_std_core__list_dup(rest);
          kk_string_dup(root0);
          _ru_3258 = kk_reuse_null;
          kk_std_core__list_decref(ps, _ctx);
        }
        kk_std_os_path__path _ctail_2683;
        kk_string_t _x3777;
        kk_string_t _x3778;
        kk_string_t _x3779;
        kk_define_string_literal(, _s3780, 1, ":")
        _x3779 = kk_string_dup(_s3780); /*string*/
        _x3778 = kk_std_core__lp__plus__plus__1_rp_(_x3779, part, _ctx); /*string*/
        _x3777 = kk_std_core__lp__plus__plus__1_rp_(root0, _x3778, _ctx); /*string*/
        _ctail_2683 = kk_std_os_path_path(_x3777, _ctx); /*std/os/path/path*/
        kk_std_core__list _ctail_2684 = kk_std_core__list_hole(); /*list<std/os/path/path>*/;
        kk_std_core__list _ctail_2685 = kk_std_core__new_Cons(_ru_3258, kk_std_os_path__path_box(_ctail_2683, _ctx), _ctail_2684, _ctx); /*list<std/os/path/path>*/;
        { // tailcall
          kk_std_core_types__ctail _x3781;
          kk_box_t* field_2884 = (kk_box_t*)((&kk_std_core__as_Cons(_ctail_2685)->tail)); /*cfield<list<std/os/path/path>>*/;
          if (kk_std_core_types__is_CTail(_acc)) {
            kk_box_t _box_x3178 = _acc._cons.CTail._field1;
            kk_box_t* last = _acc._cons.CTail._field2;
            kk_std_core__list head = kk_std_core__list_unbox(_box_x3178, NULL);
            kk_std_core__list_dup(head);
            kk_std_core_types__ctail_drop(_acc, _ctx);
            kk_unit_t __ = kk_Unit;
            *(last) = kk_std_core__list_box(_ctail_2685, _ctx);
            _x3781 = kk_std_core_types__new_CTail(kk_std_core__list_box(head, _ctx), field_2884, _ctx); /*ctail<58>*/
            goto _match3782;
          }
          _x3781 = kk_std_core_types__new_CTail(kk_std_core__list_box(_ctail_2685, _ctx), field_2884, _ctx); /*ctail<58>*/
          _match3782: ;
          ps = rest;
          _acc = _x3781;
          goto kk__tailcall;
        }
      }
    }
  }
  if (kk_std_core__is_Cons(ps)) {
    struct kk_std_core_Cons* _con3784 = kk_std_core__as_Cons(ps);
    kk_box_t _box_x3187 = _con3784->head;
    kk_std_core__list rest0 = _con3784->tail;
    kk_string_t part0 = kk_string_unbox(_box_x3187);
    kk_reuse_t _ru_3259 = kk_reuse_null; /*reuse*/;
    if (kk_std_core__list_is_unique(ps)) {
      _ru_3259 = (kk_std_core__list_reuse(ps));
    }
    else {
      kk_string_dup(part0);
      kk_std_core__list_dup(rest0);
      kk_std_core__list_decref(ps, _ctx);
      _ru_3259 = kk_reuse_null;
    }
    kk_std_os_path__path _ctail_2686 = kk_std_os_path_path(part0, _ctx); /*std/os/path/path*/;
    kk_std_core__list _ctail_2687 = kk_std_core__list_hole(); /*list<std/os/path/path>*/;
    kk_std_core__list _ctail_2688 = kk_std_core__new_Cons(_ru_3259, kk_std_os_path__path_box(_ctail_2686, _ctx), _ctail_2687, _ctx); /*list<std/os/path/path>*/;
    { // tailcall
      kk_std_core_types__ctail _x3786;
      kk_box_t* field0_2887 = (kk_box_t*)((&kk_std_core__as_Cons(_ctail_2688)->tail)); /*cfield<list<std/os/path/path>>*/;
      if (kk_std_core_types__is_CTail(_acc)) {
        kk_box_t _box_x3198 = _acc._cons.CTail._field1;
        kk_box_t* last0 = _acc._cons.CTail._field2;
        kk_std_core__list head0 = kk_std_core__list_unbox(_box_x3198, NULL);
        kk_std_core__list_dup(head0);
        kk_std_core_types__ctail_drop(_acc, _ctx);
        kk_unit_t __0 = kk_Unit;
        *(last0) = kk_std_core__list_box(_ctail_2688, _ctx);
        _x3786 = kk_std_core_types__new_CTail(kk_std_core__list_box(head0, _ctx), field0_2887, _ctx); /*ctail<58>*/
        goto _match3787;
      }
      _x3786 = kk_std_core_types__new_CTail(kk_std_core__list_box(_ctail_2688, _ctx), field0_2887, _ctx); /*ctail<58>*/
      _match3787: ;
      ps = rest0;
      _acc = _x3786;
      goto kk__tailcall;
    }
  }
  if (kk_std_core_types__is_CTail(_acc)) {
    kk_box_t _box_x3207 = _acc._cons.CTail._field1;
    kk_box_t* last1 = _acc._cons.CTail._field2;
    kk_std_core__list head1 = kk_std_core__list_unbox(_box_x3207, NULL);
    kk_std_core__list_dup(head1);
    kk_std_core_types__ctail_drop(_acc, _ctx);
    kk_unit_t __1 = kk_Unit;
    *(last1) = kk_std_core__list_box(kk_std_core__new_Nil(_ctx), _ctx);
    return head1;
  }
  return kk_std_core__new_Nil(_ctx);
}

kk_std_core__list kk_std_os_path_paths_collect(kk_std_core__list ps0, kk_context_t* _ctx) { /* (ps : list<string>) -> list<path> */ 
  return kk_std_os_path__ctail_paths_collect(ps0, kk_std_core_types__new_CTailNil(_ctx), _ctx);
}
 
// Return the stem name of path.
// `"/foo/bar.svg.txt".path.extname === "foo.svg"`

kk_string_t kk_std_os_path_stemname(kk_std_os_path__path p, kk_context_t* _ctx) { /* (p : path) -> string */ 
  kk_std_core_types__tuple2_ _this_2892;
  kk_string_t basename_2893 = kk_std_os_path_basename(p, _ctx); /*string*/;
  kk_std_core_types__maybe _match_3261;
  size_t i;
  kk_string_t _x3798 = kk_string_dup(basename_2893); /*string*/
  kk_string_t _x3799;
  kk_define_string_literal(, _s3800, 1, ".")
  _x3799 = kk_string_dup(_s3800); /*string*/
  i = kk_string_last_index_of1(_x3798,_x3799,kk_context()); /*size_t*/
  bool _match_3262 = kk_std_core_is_zero_1(i, _ctx); /*bool*/;
  if (_match_3262) {
    _match_3261 = kk_std_core_types__new_Nothing(_ctx); /*forall<a> maybe<a>*/
  }
  else {
    kk_std_core__sslice _b_3226_3220;
    kk_string_t _x3801 = kk_string_dup(basename_2893); /*string*/
    size_t _x3802 = kk_std_core_decr_1(i, _ctx); /*size_t*/
    size_t _x3803;
    kk_string_t _x3804;
    kk_define_string_literal(, _s3805, 1, ".")
    _x3804 = kk_string_dup(_s3805); /*string*/
    _x3803 = kk_string_len(_x3804,kk_context()); /*size_t*/
    _b_3226_3220 = kk_std_core__new_Sslice(_x3801, _x3802, _x3803, _ctx); /*sslice*/
    _match_3261 = kk_std_core_types__new_Just(kk_std_core__sslice_box(_b_3226_3220, _ctx), _ctx); /*forall<a> maybe<a>*/
  }
  if (kk_std_core_types__is_Just(_match_3261)) {
    kk_box_t _box_x3221 = _match_3261._cons.Just.value;
    kk_std_core__sslice slice = kk_std_core__sslice_unbox(_box_x3221, NULL);
    kk_string_drop(basename_2893, _ctx);
    kk_std_core__sslice_dup(slice);
    kk_std_core_types__maybe_drop(_match_3261, _ctx);
    kk_string_t _b_3227_3222;
    kk_std_core__sslice _x3808;
    kk_std_core__sslice _x3809 = kk_std_core__sslice_dup(slice); /*sslice*/
    _x3808 = kk_std_core_before(_x3809, _ctx); /*sslice*/
    _b_3227_3222 = kk_std_core_string_3(_x3808, _ctx); /*string*/
    kk_string_t _b_3228_3223;
    kk_std_core__sslice _x3810 = kk_std_core_after(slice, _ctx); /*sslice*/
    _b_3228_3223 = kk_std_core_string_3(_x3810, _ctx); /*string*/
    _this_2892 = kk_std_core_types__new_dash__lp__comma__rp_(kk_string_box(_b_3227_3222), kk_string_box(_b_3228_3223), _ctx); /*(string, string)*/
    goto _match3806;
  }
  kk_box_t _x3811;
  kk_string_t _x3812 = kk_string_empty(); /*string*/
  _x3811 = kk_string_box(_x3812); /*7*/
  _this_2892 = kk_std_core_types__new_dash__lp__comma__rp_(kk_string_box(basename_2893), _x3811, _ctx); /*(string, string)*/
  _match3806: ;
  kk_box_t _box_x3231 = _this_2892.fst;
  kk_box_t _box_x3232 = _this_2892.snd;
  kk_string_t _x = kk_string_unbox(_box_x3231);
  kk_string_dup(_x);
  kk_std_core_types__tuple2__drop(_this_2892, _ctx);
  return _x;
}
 
// monadic lift


// lift anonymous function
struct kk_std_os_path__mlift2710_tempdir_fun3817__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path__mlift2710_tempdir_fun3817(kk_function_t _fself, kk_box_t _b_3235, kk_context_t* _ctx);
static kk_function_t kk_std_os_path__new_mlift2710_tempdir_fun3817(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path__mlift2710_tempdir_fun3817, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_path__mlift2710_tempdir_fun3817(kk_function_t _fself, kk_box_t _b_3235, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_os_path__path _x3818;
  kk_string_t _x3819 = kk_string_unbox(_b_3235); /*string*/
  _x3818 = kk_std_os_path_path(_x3819, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x3818, _ctx);
}

kk_std_os_path__path kk_std_os_path__mlift2710_tempdir(kk_string_t _y_22, kk_context_t* _ctx) { /* (string) -> io path */ 
  kk_box_t _x3816 = kk_std_core_hnd__open_none1(kk_std_os_path__new_mlift2710_tempdir_fun3817(_ctx), kk_string_box(_y_22), _ctx); /*3239*/
  return kk_std_os_path__path_unbox(_x3816, _ctx);
}
 
// Return the temporary directory for the current user.


// lift anonymous function
struct kk_std_os_path_tempdir_fun3821__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path_tempdir_fun3821(kk_function_t _fself, kk_box_t _b_3239, kk_context_t* _ctx);
static kk_function_t kk_std_os_path_new_tempdir_fun3821(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path_tempdir_fun3821, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_path_tempdir_fun3821(kk_function_t _fself, kk_box_t _b_3239, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_os_path__path _x3822;
  kk_string_t _x3823 = kk_string_unbox(_b_3239); /*string*/
  _x3822 = kk_std_os_path__mlift2710_tempdir(_x3823, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x3822, _ctx);
}


// lift anonymous function
struct kk_std_os_path_tempdir_fun3824__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path_tempdir_fun3824(kk_function_t _fself, kk_box_t _b_3242, kk_context_t* _ctx);
static kk_function_t kk_std_os_path_new_tempdir_fun3824(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path_tempdir_fun3824, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_os_path_tempdir_fun3824(kk_function_t _fself, kk_box_t _b_3242, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_os_path__path _x3825;
  kk_string_t _x3826 = kk_string_unbox(_b_3242); /*string*/
  _x3825 = kk_std_os_path_path(_x3826, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x3825, _ctx);
}

kk_std_os_path__path kk_std_os_path_tempdir(kk_context_t* _ctx) { /* () -> io path */ 
  kk_string_t x_2896 = kk_std_os_path_xtempdir(_ctx); /*string*/;
  kk_box_t _x3820;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_2896, _ctx);
    _x3820 = kk_std_core_hnd_yield_extend(kk_std_os_path_new_tempdir_fun3821(_ctx), _ctx); /*3991*/
  }
  else {
    _x3820 = kk_std_core_hnd__open_none1(kk_std_os_path_new_tempdir_fun3824(_ctx), kk_string_box(x_2896), _ctx); /*3991*/
  }
  return kk_std_os_path__path_unbox(_x3820, _ctx);
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
