// Koka generated module: "data/preprocessing", koka version: 2.1.3
#include "data_preprocessing.h"
 
// monadic lift

kk_unit_t kk_data_preprocessing__mlift1946_all__elements__equal(kk_ref_t bool__val, kk_integer_t first__length, kk_integer_t _y_1, kk_context_t* _ctx) { /* forall<h> (bool_val : local-var<h,bool>, first_length : int, int) -> exn () */ 
  bool _match_2858 = kk_integer_neq(_y_1,first__length,kk_context()); /*bool*/;
  if (_match_2858) {
    (kk_ref_set(bool__val,(kk_bool_box(false)),kk_context())); return kk_Unit;
  }
  kk_ref_drop(bool__val, _ctx);
  kk_Unit; return kk_Unit;
}
 
// monadic lift

bool kk_data_preprocessing__mlift1947_all__elements__equal(kk_ref_t bool__val, kk_unit_t wild__0, kk_context_t* _ctx) { /* forall<h> (bool_val : local-var<h,bool>, wild_0 : ()) -> <exn,local<h>> bool */ 
  kk_box_t _x2859 = (kk_ref_get(bool__val,kk_context())); /*0*/
  return kk_bool_unbox(_x2859);
}
 
// monadic lift


// lift anonymous function
struct kk_data_preprocessing__mlift1948_all__elements__equal_fun2863__t {
  struct kk_function_s _base;
  kk_integer_t first__length;
  kk_std_core__list list;
  kk_ref_t loc;
};
static kk_unit_t kk_data_preprocessing__mlift1948_all__elements__equal_fun2863(kk_function_t _fself, kk_integer_t i, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing__new_mlift1948_all__elements__equal_fun2863(kk_integer_t first__length, kk_std_core__list list, kk_ref_t loc, kk_context_t* _ctx) {
  struct kk_data_preprocessing__mlift1948_all__elements__equal_fun2863__t* _self = kk_function_alloc_as(struct kk_data_preprocessing__mlift1948_all__elements__equal_fun2863__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_data_preprocessing__mlift1948_all__elements__equal_fun2863, kk_context());
  _self->first__length = first__length;
  _self->list = list;
  _self->loc = loc;
  return &_self->_base;
}



// lift anonymous function
struct kk_data_preprocessing__mlift1948_all__elements__equal_fun2866__t {
  struct kk_function_s _base;
  kk_integer_t first__length;
  kk_ref_t loc;
};
static kk_box_t kk_data_preprocessing__mlift1948_all__elements__equal_fun2866(kk_function_t _fself, kk_box_t _b_2201, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing__new_mlift1948_all__elements__equal_fun2866(kk_integer_t first__length, kk_ref_t loc, kk_context_t* _ctx) {
  struct kk_data_preprocessing__mlift1948_all__elements__equal_fun2866__t* _self = kk_function_alloc_as(struct kk_data_preprocessing__mlift1948_all__elements__equal_fun2866__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_data_preprocessing__mlift1948_all__elements__equal_fun2866, kk_context());
  _self->first__length = first__length;
  _self->loc = loc;
  return &_self->_base;
}

static kk_box_t kk_data_preprocessing__mlift1948_all__elements__equal_fun2866(kk_function_t _fself, kk_box_t _b_2201, kk_context_t* _ctx) {
  struct kk_data_preprocessing__mlift1948_all__elements__equal_fun2866__t* _self = kk_function_as(struct kk_data_preprocessing__mlift1948_all__elements__equal_fun2866__t*, _fself);
  kk_integer_t first__length = _self->first__length; /* int */
  kk_ref_t loc = _self->loc; /* local-var<230,bool> */
  kk_drop_match(_self, {kk_integer_dup(first__length);kk_ref_dup(loc);}, {}, _ctx)
  kk_unit_t _x2867 = kk_Unit;
  kk_integer_t _x2868 = kk_integer_unbox(_b_2201); /*int*/
  kk_data_preprocessing__mlift1946_all__elements__equal(loc, first__length, _x2868, _ctx);
  return kk_unit_box(_x2867);
}
static kk_unit_t kk_data_preprocessing__mlift1948_all__elements__equal_fun2863(kk_function_t _fself, kk_integer_t i, kk_context_t* _ctx) {
  struct kk_data_preprocessing__mlift1948_all__elements__equal_fun2863__t* _self = kk_function_as(struct kk_data_preprocessing__mlift1948_all__elements__equal_fun2863__t*, _fself);
  kk_integer_t first__length = _self->first__length; /* int */
  kk_std_core__list list = _self->list; /* list<int> */
  kk_ref_t loc = _self->loc; /* local-var<230,bool> */
  kk_drop_match(_self, {kk_integer_dup(first__length);kk_std_core__list_dup(list);kk_ref_dup(loc);}, {}, _ctx)
  kk_integer_t x0_1976;
  kk_box_t _x2864 = kk_exn_dash_get_exn_get(list, i, _ctx); /*3*/
  x0_1976 = kk_integer_unbox(_x2864); /*int*/
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x0_1976, _ctx);
    kk_box_t _x2865 = kk_std_core_hnd_yield_extend(kk_data_preprocessing__new_mlift1948_all__elements__equal_fun2866(first__length, loc, _ctx), _ctx); /*2*/
    return kk_unit_unbox(_x2865);
  }
  return kk_data_preprocessing__mlift1946_all__elements__equal(loc, first__length, x0_1976, _ctx);
}


// lift anonymous function
struct kk_data_preprocessing__mlift1948_all__elements__equal_fun2871__t {
  struct kk_function_s _base;
  kk_ref_t loc;
};
static kk_box_t kk_data_preprocessing__mlift1948_all__elements__equal_fun2871(kk_function_t _fself, kk_box_t _b_2205, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing__new_mlift1948_all__elements__equal_fun2871(kk_ref_t loc, kk_context_t* _ctx) {
  struct kk_data_preprocessing__mlift1948_all__elements__equal_fun2871__t* _self = kk_function_alloc_as(struct kk_data_preprocessing__mlift1948_all__elements__equal_fun2871__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_data_preprocessing__mlift1948_all__elements__equal_fun2871, kk_context());
  _self->loc = loc;
  return &_self->_base;
}

static kk_box_t kk_data_preprocessing__mlift1948_all__elements__equal_fun2871(kk_function_t _fself, kk_box_t _b_2205, kk_context_t* _ctx) {
  struct kk_data_preprocessing__mlift1948_all__elements__equal_fun2871__t* _self = kk_function_as(struct kk_data_preprocessing__mlift1948_all__elements__equal_fun2871__t*, _fself);
  kk_ref_t loc = _self->loc; /* local-var<230,bool> */
  kk_drop_match(_self, {kk_ref_dup(loc);}, {}, _ctx)
  bool _x2872;
  kk_unit_t _x2873 = kk_Unit;
  kk_unit_unbox(_b_2205);
  _x2872 = kk_data_preprocessing__mlift1947_all__elements__equal(loc, _x2873, _ctx); /*bool*/
  return kk_bool_box(_x2872);
}

bool kk_data_preprocessing__mlift1948_all__elements__equal(kk_std_core__list list, kk_integer_t first__length, kk_context_t* _ctx) { /* forall<h> (list : list<int>, first_length : int) -> exn bool */ 
  kk_ref_t loc = kk_ref_alloc((kk_bool_box(true)),kk_context()); /*local-var<230,bool>*/;
  bool res;
  kk_unit_t x_1971 = kk_Unit;
  kk_integer_t end_1974;
  kk_integer_t _x2860;
  kk_std_core__list _x2861 = kk_std_core__list_dup(list); /*list<int>*/
  _x2860 = kk_std_core_length_1(_x2861, _ctx); /*int*/
  end_1974 = kk_integer_sub(_x2860,(kk_integer_from_small(1)),kk_context()); /*int*/
  kk_function_t _x2862;
  kk_ref_dup(loc);
  _x2862 = kk_data_preprocessing__new_mlift1948_all__elements__equal_fun2863(first__length, list, loc, _ctx); /*(i : int) -> <exn,local<230>> ()*/
  kk_std_core__lift21056_for(_x2862, end_1974, kk_integer_from_small(0), _ctx);
  if (kk_yielding(kk_context())) {
    kk_box_t _x2869;
    kk_function_t _x2870;
    kk_ref_dup(loc);
    _x2870 = kk_data_preprocessing__new_mlift1948_all__elements__equal_fun2871(loc, _ctx); /*(1) -> 3 2*/
    _x2869 = kk_std_core_hnd_yield_extend(_x2870, _ctx); /*2*/
    res = kk_bool_unbox(_x2869); /*bool*/
  }
  else {
    kk_ref_t _x2874 = kk_ref_dup(loc); /*local-var<230,bool>*/
    res = kk_data_preprocessing__mlift1947_all__elements__equal(_x2874, x_1971, _ctx); /*bool*/
  }
  kk_box_t _x2875 = kk_std_core_hnd_prompt_local_var(loc, kk_bool_box(res), _ctx); /*2*/
  return kk_bool_unbox(_x2875);
}


// lift anonymous function
struct kk_data_preprocessing_all__elements__equal_fun2893__t {
  struct kk_function_s _base;
  kk_std_core__list list;
};
static kk_box_t kk_data_preprocessing_all__elements__equal_fun2893(kk_function_t _fself, kk_box_t _b_2226, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_all__elements__equal_fun2893(kk_std_core__list list, kk_context_t* _ctx) {
  struct kk_data_preprocessing_all__elements__equal_fun2893__t* _self = kk_function_alloc_as(struct kk_data_preprocessing_all__elements__equal_fun2893__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_data_preprocessing_all__elements__equal_fun2893, kk_context());
  _self->list = list;
  return &_self->_base;
}

static kk_box_t kk_data_preprocessing_all__elements__equal_fun2893(kk_function_t _fself, kk_box_t _b_2226, kk_context_t* _ctx) {
  struct kk_data_preprocessing_all__elements__equal_fun2893__t* _self = kk_function_as(struct kk_data_preprocessing_all__elements__equal_fun2893__t*, _fself);
  kk_std_core__list list = _self->list; /* list<int> */
  kk_drop_match(_self, {kk_std_core__list_dup(list);}, {}, _ctx)
  bool _x2894;
  kk_integer_t _x2895 = kk_integer_unbox(_b_2226); /*int*/
  _x2894 = kk_data_preprocessing__mlift1948_all__elements__equal(list, _x2895, _ctx); /*bool*/
  return kk_bool_box(_x2894);
}

bool kk_data_preprocessing_all__elements__equal(kk_std_core__list list, kk_context_t* _ctx) { /* (list : list<int>) -> exn bool */ 
  kk_unit_t __ = kk_Unit;
  bool condition_1980;
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*std/core/hnd/evv<(<>)>*/;
  bool x;
  kk_std_core__list _x2876 = kk_std_core__list_dup(list); /*list<int>*/
  x = kk_exn_dash_get_non__empty(_x2876, _ctx); /*bool*/
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  condition_1980 = x; /*bool*/
  bool _match_2855 = !(condition_1980); /*bool*/;
  if (_match_2855) {
    kk_string_t _x2877;
    kk_define_string_literal(, _s2878, 23, "List must be non_empty!")
    _x2877 = kk_string_dup(_s2878); /*string*/
    kk_std_core_unsafe_assert_fail(_x2877, _ctx);
  }
  else {
    kk_Unit;
  }
  kk_integer_t x0_1983;
  kk_std_core_types__maybe _match_2852;
  kk_std_core__list _x2879 = kk_std_core__list_dup(list); /*list<int>*/
  _match_2852 = kk_std_core__lp__lb__rb__2_rp_(_x2879, kk_integer_from_small(0), _ctx); /*maybe<1>*/
  if (kk_std_core_types__is_Nothing(_match_2852)) {
    kk_string_t message_205;
    kk_string_t _x2880;
    kk_define_string_literal(, _s2881, 48, "ListIndexError: Invalid list indexing at index: ")
    _x2880 = kk_string_dup(_s2881); /*string*/
    kk_string_t _x2882 = kk_std_core_show(kk_integer_from_small(0), _ctx); /*string*/
    message_205 = kk_std_core__lp__plus__plus__1_rp_(_x2880, _x2882, _ctx); /*string*/
    kk_std_core__exception exn_21561;
    kk_std_core__exception_info _x2883;
    kk_std_core_types__optional _match_2854 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
    if (kk_std_core_types__is_Optional(_match_2854)) {
      kk_box_t _box_x2212 = _match_2854._cons.Optional.value;
      kk_std_core__exception_info _info_14279 = kk_std_core__exception_info_unbox(_box_x2212, NULL);
      kk_std_core__exception_info_dup(_info_14279);
      kk_std_core_types__optional_drop(_match_2854, _ctx);
      _x2883 = _info_14279; /*exception-info*/
      goto _match2884;
    }
    _x2883 = kk_std_core__new_ExnError(_ctx); /*exception-info*/
    _match2884: ;
    exn_21561 = kk_std_core__new_Exception(message_205, _x2883, _ctx); /*exception*/
    kk_std_core_hnd__ev ev_21562;
    size_t _x2886 = ((size_t)0); /*size_t*/
    ev_21562 = kk_evv_at(_x2886,kk_context()); /*std/core/hnd/ev<.hnd-exn>*/
    kk_box_t _x2887;
    struct kk_std_core_hnd_Ev* _con2888 = kk_std_core_hnd__as_Ev(ev_21562);
    kk_std_core_hnd__marker m = _con2888->marker;
    kk_box_t _box_x2213 = _con2888->hnd;
    kk_std_core__hnd_exn h = kk_std_core__hnd_exn_unbox(_box_x2213, NULL);
    kk_std_core__hnd_exn_dup(h);
    kk_std_core_hnd__clause1 _match_2853;
    struct kk_std_core__Hnd_exn* _con2890 = kk_std_core__as_Hnd_exn(h);
    kk_std_core_hnd__clause1 except_throw_exn = _con2890->except_throw_exn;
    if (kk_std_core__hnd_exn_is_unique(h)) {
      kk_std_core__hnd_exn_free(h);
    }
    else {
      kk_std_core_hnd__clause1_dup(except_throw_exn);
      kk_std_core__hnd_exn_decref(h, _ctx);
    }
    _match_2853 = except_throw_exn; /*forall<a> std/core/hnd/clause1<exception,a,.hnd-exn,6,7>*/
    kk_function_t _fun_unbox_x2217 = _match_2853.clause;
    _x2887 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x2217, (_fun_unbox_x2217, m, ev_21562, kk_std_core__exception_box(exn_21561, _ctx), _ctx)); /*11*/
    x0_1983 = kk_integer_unbox(_x2887); /*int*/
  }
  else {
    kk_box_t _box_x2221 = _match_2852._cons.Just.value;
    kk_integer_t x2 = kk_integer_unbox(_box_x2221);
    kk_integer_dup(x2);
    kk_std_core_types__maybe_drop(_match_2852, _ctx);
    x0_1983 = x2; /*int*/
  }
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x0_1983, _ctx);
    kk_box_t _x2892 = kk_std_core_hnd_yield_extend(kk_data_preprocessing_new_all__elements__equal_fun2893(list, _ctx), _ctx); /*2*/
    return kk_bool_unbox(_x2892);
  }
  return kk_data_preprocessing__mlift1948_all__elements__equal(list, x0_1983, _ctx);
}
extern kk_std_core_types__maybe kk_data_preprocessing_get__thunk_fun2896(kk_function_t _fself, kk_std_core__list list, kk_context_t* _ctx) {
  struct kk_data_preprocessing_get__thunk_fun2896__t* _self = kk_function_as(struct kk_data_preprocessing_get__thunk_fun2896__t*, _fself);
  kk_integer_t index = _self->index; /* int */
  kk_drop_match(_self, {kk_integer_dup(index);}, {}, _ctx)
  return kk_std_core__lp__lb__rb__2_rp_(list, index, _ctx);
}

kk_std_core__list kk_data_preprocessing_remove__maybes(kk_std_core__list list, kk_std_core__list return__list, kk_context_t* _ctx) { /* (list : list<maybe<double>>, return_list : list<double>) -> exn list<double> */ 
  kk__tailcall: ;
  if (kk_std_core__is_Nil(list)) {
    return return__list;
  }
  struct kk_std_core_Cons* _con2897 = kk_std_core__as_Cons(list);
  kk_box_t _box_x2229 = _con2897->head;
  kk_std_core__list y = _con2897->tail;
  kk_std_core_types__maybe x = kk_std_core_types__maybe_unbox(_box_x2229, NULL);
  kk_reuse_t _ru_2798 = kk_reuse_null; /*reuse*/;
  if (kk_std_core__list_is_unique(list)) {
    kk_std_core_types__maybe_dup(x);
    kk_box_drop(_box_x2229, _ctx);
    _ru_2798 = (kk_std_core__list_reuse(list));
  }
  else {
    kk_std_core_types__maybe_dup(x);
    kk_std_core__list_dup(y);
    kk_std_core__list_decref(list, _ctx);
    _ru_2798 = kk_reuse_null;
  }
  if (kk_std_core_types__is_Nothing(x)) {
    kk_reuse_drop(_ru_2798, _ctx);
    kk_std_core__list_drop(return__list, _ctx);
    kk_std_core__list_drop(y, _ctx);
    kk_std_core__exception exn_21561;
    kk_string_t _x2899;
    kk_define_string_literal(, _s2900, 69, "Preprocessing error: There are nothings! Please check the input file!")
    _x2899 = kk_string_dup(_s2900); /*string*/
    kk_std_core__exception_info _x2901;
    kk_std_core_types__optional _match_2850 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
    if (kk_std_core_types__is_Optional(_match_2850)) {
      kk_box_t _box_x2230 = _match_2850._cons.Optional.value;
      kk_std_core__exception_info _info_14279 = kk_std_core__exception_info_unbox(_box_x2230, NULL);
      kk_std_core__exception_info_dup(_info_14279);
      kk_std_core_types__optional_drop(_match_2850, _ctx);
      _x2901 = _info_14279; /*exception-info*/
      goto _match2902;
    }
    _x2901 = kk_std_core__new_ExnError(_ctx); /*exception-info*/
    _match2902: ;
    exn_21561 = kk_std_core__new_Exception(_x2899, _x2901, _ctx); /*exception*/
    kk_std_core_hnd__ev ev_21562;
    size_t _x2904 = ((size_t)0); /*size_t*/
    ev_21562 = kk_evv_at(_x2904,kk_context()); /*std/core/hnd/ev<.hnd-exn>*/
    kk_box_t _x2905;
    struct kk_std_core_hnd_Ev* _con2906 = kk_std_core_hnd__as_Ev(ev_21562);
    kk_std_core_hnd__marker m = _con2906->marker;
    kk_box_t _box_x2231 = _con2906->hnd;
    kk_std_core__hnd_exn h = kk_std_core__hnd_exn_unbox(_box_x2231, NULL);
    kk_std_core__hnd_exn_dup(h);
    kk_std_core_hnd__clause1 _match_2849;
    struct kk_std_core__Hnd_exn* _con2908 = kk_std_core__as_Hnd_exn(h);
    kk_std_core_hnd__clause1 except_throw_exn = _con2908->except_throw_exn;
    if (kk_std_core__hnd_exn_is_unique(h)) {
      kk_std_core__hnd_exn_free(h);
    }
    else {
      kk_std_core_hnd__clause1_dup(except_throw_exn);
      kk_std_core__hnd_exn_decref(h, _ctx);
    }
    _match_2849 = except_throw_exn; /*forall<a> std/core/hnd/clause1<exception,a,.hnd-exn,6,7>*/
    kk_function_t _fun_unbox_x2235 = _match_2849.clause;
    _x2905 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x2235, (_fun_unbox_x2235, m, ev_21562, kk_std_core__exception_box(exn_21561, _ctx), _ctx)); /*11*/
    return kk_std_core__list_unbox(_x2905, _ctx);
  }
  kk_box_t _box_x2239 = x._cons.Just.value;
  double a = kk_double_unbox(_box_x2239, NULL);
  kk_std_core_types__maybe_drop(x, _ctx);
  { // tailcall
    kk_std_core__list _x2910;
    kk_std_core__list ys_1990 = kk_std_core__new_Cons(_ru_2798, kk_double_box(a, _ctx), kk_std_core__new_Nil(_ctx), _ctx); /*list<double>*/;
    _x2910 = kk_std_core_append(return__list, ys_1990, _ctx); /*list<1>*/
    list = y;
    return__list = _x2910;
    goto kk__tailcall;
  }
}
 
// monadic lift

kk_std_core__list kk_data_preprocessing__mlift1949_by__month(kk_std_core__list _y_12, kk_context_t* _ctx) { /* (list<maybe<double>>) -> exn list<double> */ 
  return kk_data_preprocessing_remove__maybes(_y_12, kk_std_core__new_Nil(_ctx), _ctx);
}


// lift anonymous function
struct kk_data_preprocessing_by__month_fun2912__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing_by__month_fun2912(kk_function_t _fself, kk_box_t _b_2249, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_by__month_fun2912(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing_by__month_fun2912, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_data_preprocessing_by__month_fun2915__t {
  struct kk_function_s _base;
  kk_function_t _bv_2252;
};
static kk_box_t kk_data_preprocessing_by__month_fun2915(kk_function_t _fself, kk_box_t _b_2253, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_by__month_fun2915(kk_function_t _bv_2252, kk_context_t* _ctx) {
  struct kk_data_preprocessing_by__month_fun2915__t* _self = kk_function_alloc_as(struct kk_data_preprocessing_by__month_fun2915__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_data_preprocessing_by__month_fun2915, kk_context());
  _self->_bv_2252 = _bv_2252;
  return &_self->_base;
}

static kk_box_t kk_data_preprocessing_by__month_fun2915(kk_function_t _fself, kk_box_t _b_2253, kk_context_t* _ctx) {
  struct kk_data_preprocessing_by__month_fun2915__t* _self = kk_function_as(struct kk_data_preprocessing_by__month_fun2915__t*, _fself);
  kk_function_t _bv_2252 = _self->_bv_2252; /* (list : list<double>) -> maybe<double> */
  kk_drop_match(_self, {kk_function_dup(_bv_2252);}, {}, _ctx)
  kk_std_core_types__maybe _x2916;
  kk_std_core__list _x2917 = kk_std_core__list_unbox(_b_2253, _ctx); /*list<double>*/
  _x2916 = kk_function_call(kk_std_core_types__maybe, (kk_function_t, kk_std_core__list, kk_context_t*), _bv_2252, (_bv_2252, _x2917, _ctx)); /*maybe<double>*/
  return kk_std_core_types__maybe_box(_x2916, _ctx);
}
static kk_box_t kk_data_preprocessing_by__month_fun2912(kk_function_t _fself, kk_box_t _b_2249, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_function_t _x2913;
  kk_function_t _bv_2252;
  kk_integer_t _x2914 = kk_integer_unbox(_b_2249); /*int*/
  _bv_2252 = kk_data_preprocessing_get__thunk(_x2914, _ctx); /*(list : list<double>) -> maybe<double>*/
  _x2913 = kk_data_preprocessing_new_by__month_fun2915(_bv_2252, _ctx); /*(2250) -> 2251*/
  return kk_function_box(_x2913);
}


// lift anonymous function
struct kk_data_preprocessing_by__month_fun2918__t {
  struct kk_function_s _base;
  kk_function_t _bv_2256;
};
static kk_std_core_types__maybe kk_data_preprocessing_by__month_fun2918(kk_function_t _fself, kk_std_core__list _b_2257, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_by__month_fun2918(kk_function_t _bv_2256, kk_context_t* _ctx) {
  struct kk_data_preprocessing_by__month_fun2918__t* _self = kk_function_alloc_as(struct kk_data_preprocessing_by__month_fun2918__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_data_preprocessing_by__month_fun2918, kk_context());
  _self->_bv_2256 = _bv_2256;
  return &_self->_base;
}

static kk_std_core_types__maybe kk_data_preprocessing_by__month_fun2918(kk_function_t _fself, kk_std_core__list _b_2257, kk_context_t* _ctx) {
  struct kk_data_preprocessing_by__month_fun2918__t* _self = kk_function_as(struct kk_data_preprocessing_by__month_fun2918__t*, _fself);
  kk_function_t _bv_2256 = _self->_bv_2256; /* (list : 2254) -> 2255 */
  kk_drop_match(_self, {kk_function_dup(_bv_2256);}, {}, _ctx)
  kk_box_t _x2919 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _bv_2256, (_bv_2256, kk_std_core__list_box(_b_2257, _ctx), _ctx)); /*2255*/
  return kk_std_core_types__maybe_unbox(_x2919, _ctx);
}


// lift anonymous function
struct kk_data_preprocessing_by__month_fun2920__t {
  struct kk_function_s _base;
  kk_function_t _x0_1931;
};
static kk_std_core_types__maybe kk_data_preprocessing_by__month_fun2920(kk_function_t _fself, kk_std_core__list _x1, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_by__month_fun2920(kk_function_t _x0_1931, kk_context_t* _ctx) {
  struct kk_data_preprocessing_by__month_fun2920__t* _self = kk_function_alloc_as(struct kk_data_preprocessing_by__month_fun2920__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_data_preprocessing_by__month_fun2920, kk_context());
  _self->_x0_1931 = _x0_1931;
  return &_self->_base;
}



// lift anonymous function
struct kk_data_preprocessing_by__month_fun2922__t {
  struct kk_function_s _base;
  kk_function_t _x0_1931;
};
static kk_box_t kk_data_preprocessing_by__month_fun2922(kk_function_t _fself, kk_box_t _b_2262, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_by__month_fun2922(kk_function_t _x0_1931, kk_context_t* _ctx) {
  struct kk_data_preprocessing_by__month_fun2922__t* _self = kk_function_alloc_as(struct kk_data_preprocessing_by__month_fun2922__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_data_preprocessing_by__month_fun2922, kk_context());
  _self->_x0_1931 = _x0_1931;
  return &_self->_base;
}

static kk_box_t kk_data_preprocessing_by__month_fun2922(kk_function_t _fself, kk_box_t _b_2262, kk_context_t* _ctx) {
  struct kk_data_preprocessing_by__month_fun2922__t* _self = kk_function_as(struct kk_data_preprocessing_by__month_fun2922__t*, _fself);
  kk_function_t _x0_1931 = _self->_x0_1931; /* (list : list<double>) -> maybe<double> */
  kk_drop_match(_self, {kk_function_dup(_x0_1931);}, {}, _ctx)
  kk_std_core_types__maybe _x2923;
  kk_std_core__list _x2924 = kk_std_core__list_unbox(_b_2262, _ctx); /*list<double>*/
  _x2923 = kk_function_call(kk_std_core_types__maybe, (kk_function_t, kk_std_core__list, kk_context_t*), _x0_1931, (_x0_1931, _x2924, _ctx)); /*maybe<double>*/
  return kk_std_core_types__maybe_box(_x2923, _ctx);
}
static kk_std_core_types__maybe kk_data_preprocessing_by__month_fun2920(kk_function_t _fself, kk_std_core__list _x1, kk_context_t* _ctx) {
  struct kk_data_preprocessing_by__month_fun2920__t* _self = kk_function_as(struct kk_data_preprocessing_by__month_fun2920__t*, _fself);
  kk_function_t _x0_1931 = _self->_x0_1931; /* (list : list<double>) -> maybe<double> */
  kk_drop_match(_self, {kk_function_dup(_x0_1931);}, {}, _ctx)
  kk_box_t _x2921 = kk_std_core_hnd__open_none1(kk_data_preprocessing_new_by__month_fun2922(_x0_1931, _ctx), kk_std_core__list_box(_x1, _ctx), _ctx); /*2*/
  return kk_std_core_types__maybe_unbox(_x2921, _ctx);
}


// lift anonymous function
struct kk_data_preprocessing_by__month_fun2925__t {
  struct kk_function_s _base;
  kk_function_t _b_2267_2264;
};
static kk_box_t kk_data_preprocessing_by__month_fun2925(kk_function_t _fself, kk_box_t _b_2265, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_by__month_fun2925(kk_function_t _b_2267_2264, kk_context_t* _ctx) {
  struct kk_data_preprocessing_by__month_fun2925__t* _self = kk_function_alloc_as(struct kk_data_preprocessing_by__month_fun2925__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_data_preprocessing_by__month_fun2925, kk_context());
  _self->_b_2267_2264 = _b_2267_2264;
  return &_self->_base;
}

static kk_box_t kk_data_preprocessing_by__month_fun2925(kk_function_t _fself, kk_box_t _b_2265, kk_context_t* _ctx) {
  struct kk_data_preprocessing_by__month_fun2925__t* _self = kk_function_as(struct kk_data_preprocessing_by__month_fun2925__t*, _fself);
  kk_function_t _b_2267_2264 = _self->_b_2267_2264; /* (list<double>) -> maybe<double> */
  kk_drop_match(_self, {kk_function_dup(_b_2267_2264);}, {}, _ctx)
  kk_std_core_types__maybe _x2926;
  kk_std_core__list _x2927 = kk_std_core__list_unbox(_b_2265, _ctx); /*list<double>*/
  _x2926 = kk_function_call(kk_std_core_types__maybe, (kk_function_t, kk_std_core__list, kk_context_t*), _b_2267_2264, (_b_2267_2264, _x2927, _ctx)); /*maybe<double>*/
  return kk_std_core_types__maybe_box(_x2926, _ctx);
}


// lift anonymous function
struct kk_data_preprocessing_by__month_fun2929__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing_by__month_fun2929(kk_function_t _fself, kk_box_t _b_2271, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_by__month_fun2929(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing_by__month_fun2929, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_data_preprocessing_by__month_fun2929(kk_function_t _fself, kk_box_t _b_2271, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core__list _x2930;
  kk_std_core__list _x2931 = kk_std_core__list_unbox(_b_2271, _ctx); /*list<maybe<double>>*/
  _x2930 = kk_data_preprocessing__mlift1949_by__month(_x2931, _ctx); /*list<double>*/
  return kk_std_core__list_box(_x2930, _ctx);
}

kk_std_core__list kk_data_preprocessing_by__month(kk_std_core__list months0, kk_integer_t index, kk_context_t* _ctx) { /* (months : list<list<double>>, index : int) -> exn list<double> */ 
  kk_std_core__list x_1991;
  kk_function_t _b_2267_2264;
  kk_function_t _x0_1931;
  kk_function_t _bv_2256;
  kk_box_t _x2911 = kk_std_core_hnd__open_none1(kk_data_preprocessing_new_by__month_fun2912(_ctx), kk_integer_box(index), _ctx); /*2*/
  _bv_2256 = kk_function_unbox(_x2911); /*(list : 2254) -> 2255*/
  _x0_1931 = kk_data_preprocessing_new_by__month_fun2918(_bv_2256, _ctx); /*(list : list<double>) -> maybe<double>*/
  _b_2267_2264 = kk_data_preprocessing_new_by__month_fun2920(_x0_1931, _ctx); /*(list<double>) -> maybe<double>*/
  x_1991 = kk_std_core_map_5(months0, kk_data_preprocessing_new_by__month_fun2925(_b_2267_2264, _ctx), _ctx); /*list<maybe<double>>*/
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_1991, _ctx);
    kk_box_t _x2928 = kk_std_core_hnd_yield_extend(kk_data_preprocessing_new_by__month_fun2929(_ctx), _ctx); /*2*/
    return kk_std_core__list_unbox(_x2928, _ctx);
  }
  return kk_data_preprocessing_remove__maybes(x_1991, kk_std_core__new_Nil(_ctx), _ctx);
}
 
// Returns a list of lists where each list corresponds to a single year (if called with parameter 12).
// Preserves order.

kk_std_core__list kk_data_preprocessing_list__of__lists(kk_std_core__list list, kk_integer_t length, kk_context_t* _ctx) { /* (list : list<double>, length : int) -> div list<list<double>> */ 
  bool _match_2847;
  kk_integer_t _x2932 = kk_integer_dup(length); /*int*/
  _match_2847 = kk_integer_eq(_x2932,(kk_integer_from_small(0)),kk_context()); /*bool*/
  if (_match_2847) {
    kk_integer_drop(length, _ctx);
    return kk_std_core__new_Cons(kk_reuse_null, kk_std_core__list_box(list, _ctx), kk_std_core__new_Nil(_ctx), _ctx);
  }
  if (kk_std_core__is_Nil(list)) {
    kk_integer_drop(length, _ctx);
    return kk_std_core__new_Nil(_ctx);
  }
  struct kk_std_core_Cons* _con2933 = kk_std_core__as_Cons(list);
  kk_box_t _box_x2275 = _con2933->head;
  kk_reuse_t _ru_2801;
  kk_std_core__list _x2935 = kk_std_core__list_dup(list); /*list<double>*/
  _ru_2801 = kk_std_core__list_dropn_reuse(_x2935, ((int32_t)2), _ctx); /*reuse*/
  kk_std_core_types__tuple2_ list__split;
  kk_integer_t _x2936 = kk_integer_dup(length); /*int*/
  list__split = kk_std_core_split(list, _x2936, _ctx); /*(list<double>, list<double>)*/
  kk_std_core__list xs_1995;
  kk_box_t _x2937;
  kk_std_core__list _x2938;
  kk_box_t _box_x2276 = list__split.fst;
  kk_box_t _box_x2277 = list__split.snd;
  kk_std_core__list _x = kk_std_core__list_unbox(_box_x2276, NULL);
  kk_std_core__list_dup(_x);
  _x2938 = _x; /*list<double>*/
  _x2937 = kk_std_core__list_box(_x2938, _ctx); /*9*/
  xs_1995 = kk_std_core__new_Cons(_ru_2801, _x2937, kk_std_core__new_Nil(_ctx), _ctx); /*list<list<double>>*/
  kk_std_core__list ys_1996;
  kk_std_core__list _x2941;
  kk_box_t _box_x2282 = list__split.fst;
  kk_box_t _box_x2283 = list__split.snd;
  kk_std_core__list _x0 = kk_std_core__list_unbox(_box_x2283, NULL);
  kk_std_core__list_dup(_x0);
  kk_std_core_types__tuple2__drop(list__split, _ctx);
  _x2941 = _x0; /*list<double>*/
  ys_1996 = kk_data_preprocessing_list__of__lists(_x2941, length, _ctx); /*list<list<double>>*/
  return kk_std_core_append(xs_1995, ys_1996, _ctx);
}
extern kk_std_core__list kk_data_preprocessing_list__of__lists__thunk_fun2944(kk_function_t _fself, kk_std_core__list list, kk_context_t* _ctx) {
  struct kk_data_preprocessing_list__of__lists__thunk_fun2944__t* _self = kk_function_as(struct kk_data_preprocessing_list__of__lists__thunk_fun2944__t*, _fself);
  kk_integer_t length = _self->length; /* int */
  kk_drop_match(_self, {kk_integer_dup(length);}, {}, _ctx)
  return kk_data_preprocessing_list__of__lists(list, length, _ctx);
}
extern kk_box_t kk_data_preprocessing_convert__to__groups_fun2945(kk_function_t _fself, kk_box_t _b_2288, kk_context_t* _ctx) {
  struct kk_data_preprocessing_convert__to__groups_fun2945__t* _self = kk_function_as(struct kk_data_preprocessing_convert__to__groups_fun2945__t*, _fself);
  kk_function_t _b_2290_2287 = _self->_b_2290_2287; /* (list : list<double>) -> div list<list<double>> */
  kk_drop_match(_self, {kk_function_dup(_b_2290_2287);}, {}, _ctx)
  kk_std_core__list _x2946;
  kk_std_core__list _x2947 = kk_std_core__list_unbox(_b_2288, _ctx); /*list<double>*/
  _x2946 = kk_function_call(kk_std_core__list, (kk_function_t, kk_std_core__list, kk_context_t*), _b_2290_2287, (_b_2290_2287, _x2947, _ctx)); /*list<list<double>>*/
  return kk_std_core__list_box(_x2946, _ctx);
}

kk_std_core__list kk_data_preprocessing_length__months(kk_std_core__list months0, kk_context_t* _ctx) { /* (months : list<list<double>>) -> list<int> */ 
  if (kk_std_core__is_Nil(months0)) {
    return kk_std_core__new_Nil(_ctx);
  }
  struct kk_std_core_Cons* _con2948 = kk_std_core__as_Cons(months0);
  kk_box_t _box_x2291 = _con2948->head;
  kk_std_core__list y = _con2948->tail;
  kk_std_core__list x = kk_std_core__list_unbox(_box_x2291, NULL);
  kk_reuse_t _ru_2802 = kk_reuse_null; /*reuse*/;
  if (kk_std_core__list_is_unique(months0)) {
    _ru_2802 = (kk_std_core__list_reuse(months0));
  }
  else {
    kk_std_core__list_dup(x);
    kk_std_core__list_dup(y);
    kk_std_core__list_decref(months0, _ctx);
    _ru_2802 = kk_reuse_null;
  }
  kk_std_core__list xs_1999;
  kk_integer_t _b_2294_2292 = kk_std_core_length_1(x, _ctx); /*int*/;
  xs_1999 = kk_std_core__new_Cons(_ru_2802, kk_integer_box(_b_2294_2292), kk_std_core__new_Nil(_ctx), _ctx); /*list<int>*/
  kk_std_core__list ys_2000 = kk_data_preprocessing_length__months(y, _ctx); /*list<int>*/;
  return kk_std_core_append(xs_1999, ys_2000, _ctx);
}
 
// monadic lift

kk_std_core__list kk_data_preprocessing__mlift1950_months(kk_ref_t list__of__months, kk_unit_t wild__1, kk_context_t* _ctx) { /* forall<h> (list_of_months : local-var<h,list<list<double>>>, wild_1 : ()) -> <local<h>,exn> list<list<double>> */ 
  kk_box_t _x2950 = (kk_ref_get(list__of__months,kk_context())); /*0*/
  return kk_std_core__list_unbox(_x2950, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_data_preprocessing__mlift1951_months_fun2953__t {
  struct kk_function_s _base;
  kk_ref_t list__of__months;
};
static kk_box_t kk_data_preprocessing__mlift1951_months_fun2953(kk_function_t _fself, kk_box_t _b_2303, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing__new_mlift1951_months_fun2953(kk_ref_t list__of__months, kk_context_t* _ctx) {
  struct kk_data_preprocessing__mlift1951_months_fun2953__t* _self = kk_function_alloc_as(struct kk_data_preprocessing__mlift1951_months_fun2953__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_data_preprocessing__mlift1951_months_fun2953, kk_context());
  _self->list__of__months = list__of__months;
  return &_self->_base;
}

static kk_box_t kk_data_preprocessing__mlift1951_months_fun2953(kk_function_t _fself, kk_box_t _b_2303, kk_context_t* _ctx) {
  struct kk_data_preprocessing__mlift1951_months_fun2953__t* _self = kk_function_as(struct kk_data_preprocessing__mlift1951_months_fun2953__t*, _fself);
  kk_ref_t list__of__months = _self->list__of__months; /* local-var<1145,list<list<double>>> */
  kk_drop_match(_self, {kk_ref_dup(list__of__months);}, {}, _ctx)
  kk_std_core__list _x2954;
  kk_unit_t _x2955 = kk_Unit;
  kk_unit_unbox(_b_2303);
  _x2954 = kk_data_preprocessing__mlift1950_months(list__of__months, _x2955, _ctx); /*list<list<double>>*/
  return kk_std_core__list_box(_x2954, _ctx);
}

kk_std_core__list kk_data_preprocessing__mlift1951_months(kk_ref_t list__of__months, kk_std_core__list _y_19, kk_context_t* _ctx) { /* forall<h> (list_of_months : local-var<h,list<list<double>>>, list<list<double>>) -> <local<h>,exn> list<list<double>> */ 
  kk_unit_t x_2001 = kk_Unit;
  kk_std_core__list _b_2301_2299 = kk_std_core_tail_1(_y_19, _ctx); /*list<list<double>>*/;
  kk_ref_t _x2951 = kk_ref_dup(list__of__months); /*local-var<1145,list<list<double>>>*/
  (kk_ref_set(_x2951,(kk_std_core__list_box(_b_2301_2299, _ctx)),kk_context()));
  if (kk_yielding(kk_context())) {
    kk_box_t _x2952 = kk_std_core_hnd_yield_extend(kk_data_preprocessing__new_mlift1951_months_fun2953(list__of__months, _ctx), _ctx); /*2*/
    return kk_std_core__list_unbox(_x2952, _ctx);
  }
  return kk_data_preprocessing__mlift1950_months(list__of__months, x_2001, _ctx);
}
 
// monadic lift

kk_unit_t kk_data_preprocessing__mlift1952_months(kk_std_core__list _y_15, kk_ref_t list__of__months, kk_std_core__list _y_16, kk_context_t* _ctx) { /* forall<h> (list<list<double>>, list_of_months : local-var<h,list<list<double>>>, list<double>) -> exn () */ 
  kk_std_core__list _b_2313_2311;
  kk_std_core__list ys_2004 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core__list_box(_y_16, _ctx), kk_std_core__new_Nil(_ctx), _ctx); /*list<list<double>>*/;
  _b_2313_2311 = kk_std_core_append(_y_15, ys_2004, _ctx); /*list<list<double>>*/
  (kk_ref_set(list__of__months,(kk_std_core__list_box(_b_2313_2311, _ctx)),kk_context())); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_data_preprocessing__mlift1953_months_fun2957__t {
  struct kk_function_s _base;
  kk_std_core__list _y_15;
  kk_ref_t list__of__months;
};
static kk_box_t kk_data_preprocessing__mlift1953_months_fun2957(kk_function_t _fself, kk_box_t _b_2315, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing__new_mlift1953_months_fun2957(kk_std_core__list _y_15, kk_ref_t list__of__months, kk_context_t* _ctx) {
  struct kk_data_preprocessing__mlift1953_months_fun2957__t* _self = kk_function_alloc_as(struct kk_data_preprocessing__mlift1953_months_fun2957__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_data_preprocessing__mlift1953_months_fun2957, kk_context());
  _self->_y_15 = _y_15;
  _self->list__of__months = list__of__months;
  return &_self->_base;
}

static kk_box_t kk_data_preprocessing__mlift1953_months_fun2957(kk_function_t _fself, kk_box_t _b_2315, kk_context_t* _ctx) {
  struct kk_data_preprocessing__mlift1953_months_fun2957__t* _self = kk_function_as(struct kk_data_preprocessing__mlift1953_months_fun2957__t*, _fself);
  kk_std_core__list _y_15 = _self->_y_15; /* list<list<double>> */
  kk_ref_t list__of__months = _self->list__of__months; /* local-var<1145,list<list<double>>> */
  kk_drop_match(_self, {kk_std_core__list_dup(_y_15);kk_ref_dup(list__of__months);}, {}, _ctx)
  kk_unit_t _x2958 = kk_Unit;
  kk_std_core__list _x2959 = kk_std_core__list_unbox(_b_2315, _ctx); /*list<double>*/
  kk_data_preprocessing__mlift1952_months(_y_15, list__of__months, _x2959, _ctx);
  return kk_unit_box(_x2958);
}

kk_unit_t kk_data_preprocessing__mlift1953_months(kk_integer_t i, kk_ref_t list__of__months, kk_std_core__list months0, kk_std_core__list _y_15, kk_context_t* _ctx) { /* forall<h> (i : int, list_of_months : local-var<h,list<list<double>>>, months : list<list<double>>, list<list<double>>) -> <local<h>,exn> () */ 
  kk_std_core__list x_2005 = kk_data_preprocessing_by__month(months0, i, _ctx); /*list<double>*/;
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_2005, _ctx);
    kk_box_t _x2956 = kk_std_core_hnd_yield_extend(kk_data_preprocessing__new_mlift1953_months_fun2957(_y_15, list__of__months, _ctx), _ctx); /*2*/
    kk_unit_unbox(_x2956); return kk_Unit;
  }
  kk_data_preprocessing__mlift1952_months(_y_15, list__of__months, x_2005, _ctx); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_data_preprocessing__mlift1954_months_fun2963__t {
  struct kk_function_s _base;
  kk_ref_t list__of__months;
};
static kk_box_t kk_data_preprocessing__mlift1954_months_fun2963(kk_function_t _fself, kk_box_t _b_2321, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing__new_mlift1954_months_fun2963(kk_ref_t list__of__months, kk_context_t* _ctx) {
  struct kk_data_preprocessing__mlift1954_months_fun2963__t* _self = kk_function_alloc_as(struct kk_data_preprocessing__mlift1954_months_fun2963__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_data_preprocessing__mlift1954_months_fun2963, kk_context());
  _self->list__of__months = list__of__months;
  return &_self->_base;
}

static kk_box_t kk_data_preprocessing__mlift1954_months_fun2963(kk_function_t _fself, kk_box_t _b_2321, kk_context_t* _ctx) {
  struct kk_data_preprocessing__mlift1954_months_fun2963__t* _self = kk_function_as(struct kk_data_preprocessing__mlift1954_months_fun2963__t*, _fself);
  kk_ref_t list__of__months = _self->list__of__months; /* local-var<1145,list<list<double>>> */
  kk_drop_match(_self, {kk_ref_dup(list__of__months);}, {}, _ctx)
  kk_std_core__list _x2964;
  kk_std_core__list _x2965 = kk_std_core__list_unbox(_b_2321, _ctx); /*list<list<double>>*/
  _x2964 = kk_data_preprocessing__mlift1951_months(list__of__months, _x2965, _ctx); /*list<list<double>>*/
  return kk_std_core__list_box(_x2964, _ctx);
}

kk_std_core__list kk_data_preprocessing__mlift1954_months(kk_ref_t list__of__months, kk_unit_t wild__0, kk_context_t* _ctx) { /* forall<h> (list_of_months : local-var<h,list<list<double>>>, wild_0 : ()) -> <exn,local<h>> list<list<double>> */ 
  kk_std_core__list x_2007;
  kk_box_t _x2960;
  kk_ref_t _x2961 = kk_ref_dup(list__of__months); /*local-var<1145,list<list<double>>>*/
  _x2960 = (kk_ref_get(_x2961,kk_context())); /*0*/
  x_2007 = kk_std_core__list_unbox(_x2960, _ctx); /*list<list<double>>*/
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_2007, _ctx);
    kk_box_t _x2962 = kk_std_core_hnd_yield_extend(kk_data_preprocessing__new_mlift1954_months_fun2963(list__of__months, _ctx), _ctx); /*2*/
    return kk_std_core__list_unbox(_x2962, _ctx);
  }
  return kk_data_preprocessing__mlift1951_months(list__of__months, x_2007, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_data_preprocessing__mlift1955_months_fun2969__t {
  struct kk_function_s _base;
  kk_ref_t loc;
  kk_std_core__list months0;
};
static kk_unit_t kk_data_preprocessing__mlift1955_months_fun2969(kk_function_t _fself, kk_integer_t i, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing__new_mlift1955_months_fun2969(kk_ref_t loc, kk_std_core__list months0, kk_context_t* _ctx) {
  struct kk_data_preprocessing__mlift1955_months_fun2969__t* _self = kk_function_alloc_as(struct kk_data_preprocessing__mlift1955_months_fun2969__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_data_preprocessing__mlift1955_months_fun2969, kk_context());
  _self->loc = loc;
  _self->months0 = months0;
  return &_self->_base;
}



// lift anonymous function
struct kk_data_preprocessing__mlift1955_months_fun2973__t {
  struct kk_function_s _base;
  kk_integer_t i;
  kk_ref_t loc;
  kk_std_core__list months0;
};
static kk_box_t kk_data_preprocessing__mlift1955_months_fun2973(kk_function_t _fself, kk_box_t _b_2333, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing__new_mlift1955_months_fun2973(kk_integer_t i, kk_ref_t loc, kk_std_core__list months0, kk_context_t* _ctx) {
  struct kk_data_preprocessing__mlift1955_months_fun2973__t* _self = kk_function_alloc_as(struct kk_data_preprocessing__mlift1955_months_fun2973__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_data_preprocessing__mlift1955_months_fun2973, kk_context());
  _self->i = i;
  _self->loc = loc;
  _self->months0 = months0;
  return &_self->_base;
}

static kk_box_t kk_data_preprocessing__mlift1955_months_fun2973(kk_function_t _fself, kk_box_t _b_2333, kk_context_t* _ctx) {
  struct kk_data_preprocessing__mlift1955_months_fun2973__t* _self = kk_function_as(struct kk_data_preprocessing__mlift1955_months_fun2973__t*, _fself);
  kk_integer_t i = _self->i; /* int */
  kk_ref_t loc = _self->loc; /* local-var<1145,list<list<double>>> */
  kk_std_core__list months0 = _self->months0; /* list<list<double>> */
  kk_drop_match(_self, {kk_integer_dup(i);kk_ref_dup(loc);kk_std_core__list_dup(months0);}, {}, _ctx)
  kk_unit_t _x2974 = kk_Unit;
  kk_std_core__list _x2975 = kk_std_core__list_unbox(_b_2333, _ctx); /*list<list<double>>*/
  kk_data_preprocessing__mlift1953_months(i, loc, months0, _x2975, _ctx);
  return kk_unit_box(_x2974);
}
static kk_unit_t kk_data_preprocessing__mlift1955_months_fun2969(kk_function_t _fself, kk_integer_t i, kk_context_t* _ctx) {
  struct kk_data_preprocessing__mlift1955_months_fun2969__t* _self = kk_function_as(struct kk_data_preprocessing__mlift1955_months_fun2969__t*, _fself);
  kk_ref_t loc = _self->loc; /* local-var<1145,list<list<double>>> */
  kk_std_core__list months0 = _self->months0; /* list<list<double>> */
  kk_drop_match(_self, {kk_ref_dup(loc);kk_std_core__list_dup(months0);}, {}, _ctx)
  kk_std_core__list x0_2019;
  kk_box_t _x2970;
  kk_ref_t _x2971 = kk_ref_dup(loc); /*local-var<1145,list<list<double>>>*/
  _x2970 = (kk_ref_get(_x2971,kk_context())); /*0*/
  x0_2019 = kk_std_core__list_unbox(_x2970, _ctx); /*list<list<double>>*/
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x0_2019, _ctx);
    kk_box_t _x2972 = kk_std_core_hnd_yield_extend(kk_data_preprocessing__new_mlift1955_months_fun2973(i, loc, months0, _ctx), _ctx); /*2*/
    return kk_unit_unbox(_x2972);
  }
  return kk_data_preprocessing__mlift1953_months(i, loc, months0, x0_2019, _ctx);
}


// lift anonymous function
struct kk_data_preprocessing__mlift1955_months_fun2978__t {
  struct kk_function_s _base;
  kk_ref_t loc;
};
static kk_box_t kk_data_preprocessing__mlift1955_months_fun2978(kk_function_t _fself, kk_box_t _b_2337, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing__new_mlift1955_months_fun2978(kk_ref_t loc, kk_context_t* _ctx) {
  struct kk_data_preprocessing__mlift1955_months_fun2978__t* _self = kk_function_alloc_as(struct kk_data_preprocessing__mlift1955_months_fun2978__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_data_preprocessing__mlift1955_months_fun2978, kk_context());
  _self->loc = loc;
  return &_self->_base;
}

static kk_box_t kk_data_preprocessing__mlift1955_months_fun2978(kk_function_t _fself, kk_box_t _b_2337, kk_context_t* _ctx) {
  struct kk_data_preprocessing__mlift1955_months_fun2978__t* _self = kk_function_as(struct kk_data_preprocessing__mlift1955_months_fun2978__t*, _fself);
  kk_ref_t loc = _self->loc; /* local-var<1145,list<list<double>>> */
  kk_drop_match(_self, {kk_ref_dup(loc);}, {}, _ctx)
  kk_std_core__list _x2979;
  kk_unit_t _x2980 = kk_Unit;
  kk_unit_unbox(_b_2337);
  _x2979 = kk_data_preprocessing__mlift1954_months(loc, _x2980, _ctx); /*list<list<double>>*/
  return kk_std_core__list_box(_x2979, _ctx);
}

kk_std_core__list kk_data_preprocessing__mlift1955_months(kk_std_core__list months0, bool _y_14, kk_context_t* _ctx) { /* forall<h> (months : list<list<double>>, bool) -> exn list<list<double>> */ 
  kk_unit_t __ = kk_Unit;
  bool _match_2843 = !(_y_14); /*bool*/;
  if (_match_2843) {
    kk_string_t _x2966;
    kk_define_string_literal(, _s2967, 28, "Month lengths must be equal!")
    _x2966 = kk_string_dup(_s2967); /*string*/
    kk_std_core_unsafe_assert_fail(_x2966, _ctx);
  }
  else {
    kk_Unit;
  }
  kk_std_core__list init_2011 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core__list_box(kk_std_core__new_Nil(_ctx), _ctx), kk_std_core__new_Nil(_ctx), _ctx); /*list<list<double>>*/;
  kk_ref_t loc = kk_ref_alloc((kk_std_core__list_box(init_2011, _ctx)),kk_context()); /*local-var<1145,list<list<double>>>*/;
  kk_std_core__list res;
  kk_unit_t x_2014 = kk_Unit;
  kk_function_t _x2968;
  kk_ref_dup(loc);
  _x2968 = kk_data_preprocessing__new_mlift1955_months_fun2969(loc, months0, _ctx); /*(i : int) -> <exn,local<1145>> ()*/
  kk_std_core__lift21056_for(_x2968, kk_integer_from_small(11), kk_integer_from_small(0), _ctx);
  if (kk_yielding(kk_context())) {
    kk_box_t _x2976;
    kk_function_t _x2977;
    kk_ref_dup(loc);
    _x2977 = kk_data_preprocessing__new_mlift1955_months_fun2978(loc, _ctx); /*(1) -> 3 2*/
    _x2976 = kk_std_core_hnd_yield_extend(_x2977, _ctx); /*2*/
    res = kk_std_core__list_unbox(_x2976, _ctx); /*list<list<double>>*/
  }
  else {
    kk_ref_t _x2981 = kk_ref_dup(loc); /*local-var<1145,list<list<double>>>*/
    res = kk_data_preprocessing__mlift1954_months(_x2981, x_2014, _ctx); /*list<list<double>>*/
  }
  kk_box_t _x2982 = kk_std_core_hnd_prompt_local_var(loc, kk_std_core__list_box(res, _ctx), _ctx); /*2*/
  return kk_std_core__list_unbox(_x2982, _ctx);
}
 
/* [[1,2,3,4,5,6,...12],[1,2,3,4,5,6...12]...] -> [[1,1,1,1,1,..........1,1,1,1],[2,2,2,2,2,2,......2,2,2,]] */


// lift anonymous function
struct kk_data_preprocessing_months_fun2984__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing_months_fun2984(kk_function_t _fself, kk_box_t _b_2346, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_months_fun2984(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing_months_fun2984, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_data_preprocessing_months_fun2984(kk_function_t _fself, kk_box_t _b_2346, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core__list _x2985;
  kk_std_core__list _x2986 = kk_std_core__list_unbox(_b_2346, _ctx); /*list<list<double>>*/
  _x2985 = kk_data_preprocessing_length__months(_x2986, _ctx); /*list<int>*/
  return kk_std_core__list_box(_x2985, _ctx);
}


// lift anonymous function
struct kk_data_preprocessing_months_fun3006__t {
  struct kk_function_s _base;
  kk_std_core__list list_2167;
};
static kk_box_t kk_data_preprocessing_months_fun3006(kk_function_t _fself, kk_box_t _b_2363, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_months_fun3006(kk_std_core__list list_2167, kk_context_t* _ctx) {
  struct kk_data_preprocessing_months_fun3006__t* _self = kk_function_alloc_as(struct kk_data_preprocessing_months_fun3006__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_data_preprocessing_months_fun3006, kk_context());
  _self->list_2167 = list_2167;
  return &_self->_base;
}

static kk_box_t kk_data_preprocessing_months_fun3006(kk_function_t _fself, kk_box_t _b_2363, kk_context_t* _ctx) {
  struct kk_data_preprocessing_months_fun3006__t* _self = kk_function_as(struct kk_data_preprocessing_months_fun3006__t*, _fself);
  kk_std_core__list list_2167 = _self->list_2167; /* list<int> */
  kk_drop_match(_self, {kk_std_core__list_dup(list_2167);}, {}, _ctx)
  bool _x3007;
  kk_integer_t _x3008 = kk_integer_unbox(_b_2363); /*int*/
  _x3007 = kk_data_preprocessing__mlift1948_all__elements__equal(list_2167, _x3008, _ctx); /*bool*/
  return kk_bool_box(_x3007);
}


// lift anonymous function
struct kk_data_preprocessing_months_fun3010__t {
  struct kk_function_s _base;
  kk_std_core__list months0;
};
static kk_box_t kk_data_preprocessing_months_fun3010(kk_function_t _fself, kk_box_t _b_2367, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_months_fun3010(kk_std_core__list months0, kk_context_t* _ctx) {
  struct kk_data_preprocessing_months_fun3010__t* _self = kk_function_alloc_as(struct kk_data_preprocessing_months_fun3010__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_data_preprocessing_months_fun3010, kk_context());
  _self->months0 = months0;
  return &_self->_base;
}

static kk_box_t kk_data_preprocessing_months_fun3010(kk_function_t _fself, kk_box_t _b_2367, kk_context_t* _ctx) {
  struct kk_data_preprocessing_months_fun3010__t* _self = kk_function_as(struct kk_data_preprocessing_months_fun3010__t*, _fself);
  kk_std_core__list months0 = _self->months0; /* list<list<double>> */
  kk_drop_match(_self, {kk_std_core__list_dup(months0);}, {}, _ctx)
  kk_std_core__list _x3011;
  bool _x3012 = kk_bool_unbox(_b_2367); /*bool*/
  _x3011 = kk_data_preprocessing__mlift1955_months(months0, _x3012, _ctx); /*list<list<double>>*/
  return kk_std_core__list_box(_x3011, _ctx);
}

kk_std_core__list kk_data_preprocessing_months(kk_std_core__list months0, kk_context_t* _ctx) { /* (months : list<list<double>>) -> exn list<list<double>> */ 
  bool x_2022;
  kk_std_core__list list_2167;
  kk_box_t _x2983;
  kk_box_t _x2987;
  kk_std_core__list _x2988 = kk_std_core__list_dup(months0); /*list<list<double>>*/
  _x2987 = kk_std_core__list_box(_x2988, _ctx); /*1*/
  _x2983 = kk_std_core_hnd__open_none1(kk_data_preprocessing_new_months_fun2984(_ctx), _x2987, _ctx); /*2*/
  list_2167 = kk_std_core__list_unbox(_x2983, _ctx); /*list<int>*/
  kk_unit_t __ = kk_Unit;
  bool condition_1980;
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*std/core/hnd/evv<(<>)>*/;
  bool x;
  kk_std_core__list _x2989 = kk_std_core__list_dup(list_2167); /*list<int>*/
  x = kk_exn_dash_get_non__empty(_x2989, _ctx); /*bool*/
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  condition_1980 = x; /*bool*/
  bool _match_2840 = !(condition_1980); /*bool*/;
  if (_match_2840) {
    kk_string_t _x2990;
    kk_define_string_literal(, _s2991, 23, "List must be non_empty!")
    _x2990 = kk_string_dup(_s2991); /*string*/
    kk_std_core_unsafe_assert_fail(_x2990, _ctx);
  }
  else {
    kk_Unit;
  }
  kk_integer_t x0_1983;
  kk_std_core_types__maybe _match_2837;
  kk_std_core__list _x2992 = kk_std_core__list_dup(list_2167); /*list<int>*/
  _match_2837 = kk_std_core__lp__lb__rb__2_rp_(_x2992, kk_integer_from_small(0), _ctx); /*maybe<1>*/
  if (kk_std_core_types__is_Nothing(_match_2837)) {
    kk_string_t message_205;
    kk_string_t _x2993;
    kk_define_string_literal(, _s2994, 48, "ListIndexError: Invalid list indexing at index: ")
    _x2993 = kk_string_dup(_s2994); /*string*/
    kk_string_t _x2995 = kk_std_core_show(kk_integer_from_small(0), _ctx); /*string*/
    message_205 = kk_std_core__lp__plus__plus__1_rp_(_x2993, _x2995, _ctx); /*string*/
    kk_std_core__exception exn_21561;
    kk_std_core__exception_info _x2996;
    kk_std_core_types__optional _match_2839 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
    if (kk_std_core_types__is_Optional(_match_2839)) {
      kk_box_t _box_x2349 = _match_2839._cons.Optional.value;
      kk_std_core__exception_info _info_14279 = kk_std_core__exception_info_unbox(_box_x2349, NULL);
      kk_std_core__exception_info_dup(_info_14279);
      kk_std_core_types__optional_drop(_match_2839, _ctx);
      _x2996 = _info_14279; /*exception-info*/
      goto _match2997;
    }
    _x2996 = kk_std_core__new_ExnError(_ctx); /*exception-info*/
    _match2997: ;
    exn_21561 = kk_std_core__new_Exception(message_205, _x2996, _ctx); /*exception*/
    kk_std_core_hnd__ev ev_21562;
    size_t _x2999 = ((size_t)0); /*size_t*/
    ev_21562 = kk_evv_at(_x2999,kk_context()); /*std/core/hnd/ev<.hnd-exn>*/
    kk_box_t _x3000;
    struct kk_std_core_hnd_Ev* _con3001 = kk_std_core_hnd__as_Ev(ev_21562);
    kk_std_core_hnd__marker m = _con3001->marker;
    kk_box_t _box_x2350 = _con3001->hnd;
    kk_std_core__hnd_exn h = kk_std_core__hnd_exn_unbox(_box_x2350, NULL);
    kk_std_core__hnd_exn_dup(h);
    kk_std_core_hnd__clause1 _match_2838;
    struct kk_std_core__Hnd_exn* _con3003 = kk_std_core__as_Hnd_exn(h);
    kk_std_core_hnd__clause1 except_throw_exn = _con3003->except_throw_exn;
    if (kk_std_core__hnd_exn_is_unique(h)) {
      kk_std_core__hnd_exn_free(h);
    }
    else {
      kk_std_core_hnd__clause1_dup(except_throw_exn);
      kk_std_core__hnd_exn_decref(h, _ctx);
    }
    _match_2838 = except_throw_exn; /*forall<a> std/core/hnd/clause1<exception,a,.hnd-exn,6,7>*/
    kk_function_t _fun_unbox_x2354 = _match_2838.clause;
    _x3000 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x2354, (_fun_unbox_x2354, m, ev_21562, kk_std_core__exception_box(exn_21561, _ctx), _ctx)); /*11*/
    x0_1983 = kk_integer_unbox(_x3000); /*int*/
  }
  else {
    kk_box_t _box_x2358 = _match_2837._cons.Just.value;
    kk_integer_t x2 = kk_integer_unbox(_box_x2358);
    kk_integer_dup(x2);
    kk_std_core_types__maybe_drop(_match_2837, _ctx);
    x0_1983 = x2; /*int*/
  }
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x0_1983, _ctx);
    kk_box_t _x3005 = kk_std_core_hnd_yield_extend(kk_data_preprocessing_new_months_fun3006(list_2167, _ctx), _ctx); /*2*/
    x_2022 = kk_bool_unbox(_x3005); /*bool*/
  }
  else {
    x_2022 = kk_data_preprocessing__mlift1948_all__elements__equal(list_2167, x0_1983, _ctx); /*bool*/
  }
  if (kk_yielding(kk_context())) {
    kk_box_t _x3009 = kk_std_core_hnd_yield_extend(kk_data_preprocessing_new_months_fun3010(months0, _ctx), _ctx); /*2*/
    return kk_std_core__list_unbox(_x3009, _ctx);
  }
  return kk_data_preprocessing__mlift1955_months(months0, x_2022, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_data_preprocessing__mlift1956_pre__process__data_fun3013__t {
  struct kk_function_s _base;
  kk_function_t _b_2374_2371;
};
static kk_box_t kk_data_preprocessing__mlift1956_pre__process__data_fun3013(kk_function_t _fself, kk_box_t _b_2372, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing__new_mlift1956_pre__process__data_fun3013(kk_function_t _b_2374_2371, kk_context_t* _ctx) {
  struct kk_data_preprocessing__mlift1956_pre__process__data_fun3013__t* _self = kk_function_alloc_as(struct kk_data_preprocessing__mlift1956_pre__process__data_fun3013__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_data_preprocessing__mlift1956_pre__process__data_fun3013, kk_context());
  _self->_b_2374_2371 = _b_2374_2371;
  return &_self->_base;
}

static kk_box_t kk_data_preprocessing__mlift1956_pre__process__data_fun3013(kk_function_t _fself, kk_box_t _b_2372, kk_context_t* _ctx) {
  struct kk_data_preprocessing__mlift1956_pre__process__data_fun3013__t* _self = kk_function_as(struct kk_data_preprocessing__mlift1956_pre__process__data_fun3013__t*, _fself);
  kk_function_t _b_2374_2371 = _self->_b_2374_2371; /* (list : list<double>) -> div list<list<double>> */
  kk_drop_match(_self, {kk_function_dup(_b_2374_2371);}, {}, _ctx)
  kk_std_core__list _x3014;
  kk_std_core__list _x3015 = kk_std_core__list_unbox(_b_2372, _ctx); /*list<double>*/
  _x3014 = kk_function_call(kk_std_core__list, (kk_function_t, kk_std_core__list, kk_context_t*), _b_2374_2371, (_b_2374_2371, _x3015, _ctx)); /*list<list<double>>*/
  return kk_std_core__list_box(_x3014, _ctx);
}


// lift anonymous function
struct kk_data_preprocessing__mlift1956_pre__process__data_fun3016__t {
  struct kk_function_s _base;
  kk_function_t _b_2379_2376;
};
static kk_box_t kk_data_preprocessing__mlift1956_pre__process__data_fun3016(kk_function_t _fself, kk_box_t _b_2377, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing__new_mlift1956_pre__process__data_fun3016(kk_function_t _b_2379_2376, kk_context_t* _ctx) {
  struct kk_data_preprocessing__mlift1956_pre__process__data_fun3016__t* _self = kk_function_alloc_as(struct kk_data_preprocessing__mlift1956_pre__process__data_fun3016__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_data_preprocessing__mlift1956_pre__process__data_fun3016, kk_context());
  _self->_b_2379_2376 = _b_2379_2376;
  return &_self->_base;
}

static kk_box_t kk_data_preprocessing__mlift1956_pre__process__data_fun3016(kk_function_t _fself, kk_box_t _b_2377, kk_context_t* _ctx) {
  struct kk_data_preprocessing__mlift1956_pre__process__data_fun3016__t* _self = kk_function_as(struct kk_data_preprocessing__mlift1956_pre__process__data_fun3016__t*, _fself);
  kk_function_t _b_2379_2376 = _self->_b_2379_2376; /* (list : list<double>) -> div list<list<double>> */
  kk_drop_match(_self, {kk_function_dup(_b_2379_2376);}, {}, _ctx)
  kk_std_core__list _x3017;
  kk_std_core__list _x3018 = kk_std_core__list_unbox(_b_2377, _ctx); /*list<double>*/
  _x3017 = kk_function_call(kk_std_core__list, (kk_function_t, kk_std_core__list, kk_context_t*), _b_2379_2376, (_b_2379_2376, _x3018, _ctx)); /*list<list<double>>*/
  return kk_std_core__list_box(_x3017, _ctx);
}

kk_std_core_types__tuple2_ kk_data_preprocessing__mlift1956_pre__process__data(kk_std_core__list uncertainties__by__month, kk_std_core__list temperatures__by__month, kk_context_t* _ctx) { /* (uncertainties_by_month : list<list<double>>, temperatures_by_month : list<list<double>>) -> exn (list<list<list<double>>>, list<list<list<double>>>) */ 
  kk_std_core__list grouped__uncertainties__by__month;
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*std/core/hnd/evv<(<>)>*/;
  kk_std_core__list x;
  kk_function_t _b_2374_2371 = kk_data_preprocessing_list__of__lists__thunk(kk_integer_from_small(20), _ctx); /*(list : list<double>) -> div list<list<double>>*/;
  x = kk_std_core_map_5(uncertainties__by__month, kk_data_preprocessing__new_mlift1956_pre__process__data_fun3013(_b_2374_2371, _ctx), _ctx); /*list<list<list<double>>>*/
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  grouped__uncertainties__by__month = x; /*list<list<list<double>>>*/
  kk_std_core__list grouped__temperatures__by__month;
  kk_evv_t w0 = kk_evv_swap_create0(kk_context()); /*std/core/hnd/evv<(<>)>*/;
  kk_std_core__list x0;
  kk_function_t _b_2379_2376 = kk_data_preprocessing_list__of__lists__thunk(kk_integer_from_small(20), _ctx); /*(list : list<double>) -> div list<list<double>>*/;
  x0 = kk_std_core_map_5(temperatures__by__month, kk_data_preprocessing__new_mlift1956_pre__process__data_fun3016(_b_2379_2376, _ctx), _ctx); /*list<list<list<double>>>*/
  kk_unit_t keep0 = kk_Unit;
  kk_evv_set(w0,kk_context());
  grouped__temperatures__by__month = x0; /*list<list<list<double>>>*/
  return kk_std_core_types__new_dash__lp__comma__rp_(kk_std_core__list_box(grouped__uncertainties__by__month, _ctx), kk_std_core__list_box(grouped__temperatures__by__month, _ctx), _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_data_preprocessing__mlift1957_pre__process__data_fun3020__t {
  struct kk_function_s _base;
  kk_std_core__list uncertainties__by__month;
};
static kk_box_t kk_data_preprocessing__mlift1957_pre__process__data_fun3020(kk_function_t _fself, kk_box_t _b_2385, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing__new_mlift1957_pre__process__data_fun3020(kk_std_core__list uncertainties__by__month, kk_context_t* _ctx) {
  struct kk_data_preprocessing__mlift1957_pre__process__data_fun3020__t* _self = kk_function_alloc_as(struct kk_data_preprocessing__mlift1957_pre__process__data_fun3020__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_data_preprocessing__mlift1957_pre__process__data_fun3020, kk_context());
  _self->uncertainties__by__month = uncertainties__by__month;
  return &_self->_base;
}

static kk_box_t kk_data_preprocessing__mlift1957_pre__process__data_fun3020(kk_function_t _fself, kk_box_t _b_2385, kk_context_t* _ctx) {
  struct kk_data_preprocessing__mlift1957_pre__process__data_fun3020__t* _self = kk_function_as(struct kk_data_preprocessing__mlift1957_pre__process__data_fun3020__t*, _fself);
  kk_std_core__list uncertainties__by__month = _self->uncertainties__by__month; /* list<list<double>> */
  kk_drop_match(_self, {kk_std_core__list_dup(uncertainties__by__month);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x3021;
  kk_std_core__list _x3022 = kk_std_core__list_unbox(_b_2385, _ctx); /*list<list<double>>*/
  _x3021 = kk_data_preprocessing__mlift1956_pre__process__data(uncertainties__by__month, _x3022, _ctx); /*(list<list<list<double>>>, list<list<list<double>>>)*/
  return kk_std_core_types__tuple2__box(_x3021, _ctx);
}

kk_std_core_types__tuple2_ kk_data_preprocessing__mlift1957_pre__process__data(kk_std_core__list temperatures__by__year, kk_std_core__list uncertainties__by__month, kk_context_t* _ctx) { /* (temperatures_by_year : list<list<double>>, uncertainties_by_month : list<list<double>>) -> exn (list<list<list<double>>>, list<list<list<double>>>) */ 
  kk_std_core__list x_2030 = kk_data_preprocessing_months(temperatures__by__year, _ctx); /*list<list<double>>*/;
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_2030, _ctx);
    kk_box_t _x3019 = kk_std_core_hnd_yield_extend(kk_data_preprocessing__new_mlift1957_pre__process__data_fun3020(uncertainties__by__month, _ctx), _ctx); /*2*/
    return kk_std_core_types__tuple2__unbox(_x3019, _ctx);
  }
  return kk_data_preprocessing__mlift1956_pre__process__data(uncertainties__by__month, x_2030, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_data_preprocessing__mlift1958_pre__process__data_fun3024__t {
  struct kk_function_s _base;
  kk_std_core__list temperatures__by__year;
};
static kk_box_t kk_data_preprocessing__mlift1958_pre__process__data_fun3024(kk_function_t _fself, kk_box_t _b_2389, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing__new_mlift1958_pre__process__data_fun3024(kk_std_core__list temperatures__by__year, kk_context_t* _ctx) {
  struct kk_data_preprocessing__mlift1958_pre__process__data_fun3024__t* _self = kk_function_alloc_as(struct kk_data_preprocessing__mlift1958_pre__process__data_fun3024__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_data_preprocessing__mlift1958_pre__process__data_fun3024, kk_context());
  _self->temperatures__by__year = temperatures__by__year;
  return &_self->_base;
}

static kk_box_t kk_data_preprocessing__mlift1958_pre__process__data_fun3024(kk_function_t _fself, kk_box_t _b_2389, kk_context_t* _ctx) {
  struct kk_data_preprocessing__mlift1958_pre__process__data_fun3024__t* _self = kk_function_as(struct kk_data_preprocessing__mlift1958_pre__process__data_fun3024__t*, _fself);
  kk_std_core__list temperatures__by__year = _self->temperatures__by__year; /* list<list<double>> */
  kk_drop_match(_self, {kk_std_core__list_dup(temperatures__by__year);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x3025;
  kk_std_core__list _x3026 = kk_std_core__list_unbox(_b_2389, _ctx); /*list<list<double>>*/
  _x3025 = kk_data_preprocessing__mlift1957_pre__process__data(temperatures__by__year, _x3026, _ctx); /*(list<list<list<double>>>, list<list<list<double>>>)*/
  return kk_std_core_types__tuple2__box(_x3025, _ctx);
}

kk_std_core_types__tuple2_ kk_data_preprocessing__mlift1958_pre__process__data(kk_std_core__list uncertainties, kk_std_core__list temperatures, kk_context_t* _ctx) { /* (uncertainties : list<double>, temperatures : list<double>) -> exn (list<list<list<double>>>, list<list<list<double>>>) */ 
  kk_std_core__list uncertainties__by__year;
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*std/core/hnd/evv<(<>)>*/;
  kk_std_core__list x = kk_data_preprocessing_list__of__lists(uncertainties, kk_integer_from_small(12), _ctx); /*list<list<double>>*/;
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  uncertainties__by__year = x; /*list<list<double>>*/
  kk_std_core__list temperatures__by__year;
  kk_evv_t w0 = kk_evv_swap_create0(kk_context()); /*std/core/hnd/evv<(<>)>*/;
  kk_std_core__list x0 = kk_data_preprocessing_list__of__lists(temperatures, kk_integer_from_small(12), _ctx); /*list<list<double>>*/;
  kk_unit_t keep0 = kk_Unit;
  kk_evv_set(w0,kk_context());
  temperatures__by__year = x0; /*list<list<double>>*/
  kk_std_core__list x3_2038 = kk_data_preprocessing_months(uncertainties__by__year, _ctx); /*list<list<double>>*/;
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x3_2038, _ctx);
    kk_box_t _x3023 = kk_std_core_hnd_yield_extend(kk_data_preprocessing__new_mlift1958_pre__process__data_fun3024(temperatures__by__year, _ctx), _ctx); /*2*/
    return kk_std_core_types__tuple2__unbox(_x3023, _ctx);
  }
  return kk_data_preprocessing__mlift1957_pre__process__data(temperatures__by__year, x3_2038, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_data_preprocessing__mlift1959_pre__process__data_fun3028__t {
  struct kk_function_s _base;
  kk_std_core__list uncertainties;
};
static kk_box_t kk_data_preprocessing__mlift1959_pre__process__data_fun3028(kk_function_t _fself, kk_box_t _b_2393, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing__new_mlift1959_pre__process__data_fun3028(kk_std_core__list uncertainties, kk_context_t* _ctx) {
  struct kk_data_preprocessing__mlift1959_pre__process__data_fun3028__t* _self = kk_function_alloc_as(struct kk_data_preprocessing__mlift1959_pre__process__data_fun3028__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_data_preprocessing__mlift1959_pre__process__data_fun3028, kk_context());
  _self->uncertainties = uncertainties;
  return &_self->_base;
}

static kk_box_t kk_data_preprocessing__mlift1959_pre__process__data_fun3028(kk_function_t _fself, kk_box_t _b_2393, kk_context_t* _ctx) {
  struct kk_data_preprocessing__mlift1959_pre__process__data_fun3028__t* _self = kk_function_as(struct kk_data_preprocessing__mlift1959_pre__process__data_fun3028__t*, _fself);
  kk_std_core__list uncertainties = _self->uncertainties; /* list<double> */
  kk_drop_match(_self, {kk_std_core__list_dup(uncertainties);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x3029;
  kk_std_core__list _x3030 = kk_std_core__list_unbox(_b_2393, _ctx); /*list<double>*/
  _x3029 = kk_data_preprocessing__mlift1958_pre__process__data(uncertainties, _x3030, _ctx); /*(list<list<list<double>>>, list<list<list<double>>>)*/
  return kk_std_core_types__tuple2__box(_x3029, _ctx);
}

kk_std_core_types__tuple2_ kk_data_preprocessing__mlift1959_pre__process__data(kk_std_core__list maybe__temperatures, kk_std_core__list uncertainties, kk_context_t* _ctx) { /* (maybe_temperatures : list<maybe<double>>, uncertainties : list<double>) -> exn (list<list<list<double>>>, list<list<list<double>>>) */ 
  kk_std_core__list x_2040 = kk_data_preprocessing_remove__maybes(maybe__temperatures, kk_std_core__new_Nil(_ctx), _ctx); /*list<double>*/;
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_2040, _ctx);
    kk_box_t _x3027 = kk_std_core_hnd_yield_extend(kk_data_preprocessing__new_mlift1959_pre__process__data_fun3028(uncertainties, _ctx), _ctx); /*2*/
    return kk_std_core_types__tuple2__unbox(_x3027, _ctx);
  }
  return kk_data_preprocessing__mlift1958_pre__process__data(uncertainties, x_2040, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_data_preprocessing__mlift1960_pre__process__data_fun3032__t {
  struct kk_function_s _base;
  kk_std_core__list maybe__temperatures;
};
static kk_box_t kk_data_preprocessing__mlift1960_pre__process__data_fun3032(kk_function_t _fself, kk_box_t _b_2413, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing__new_mlift1960_pre__process__data_fun3032(kk_std_core__list maybe__temperatures, kk_context_t* _ctx) {
  struct kk_data_preprocessing__mlift1960_pre__process__data_fun3032__t* _self = kk_function_alloc_as(struct kk_data_preprocessing__mlift1960_pre__process__data_fun3032__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_data_preprocessing__mlift1960_pre__process__data_fun3032, kk_context());
  _self->maybe__temperatures = maybe__temperatures;
  return &_self->_base;
}

static kk_box_t kk_data_preprocessing__mlift1960_pre__process__data_fun3032(kk_function_t _fself, kk_box_t _b_2413, kk_context_t* _ctx) {
  struct kk_data_preprocessing__mlift1960_pre__process__data_fun3032__t* _self = kk_function_as(struct kk_data_preprocessing__mlift1960_pre__process__data_fun3032__t*, _fself);
  kk_std_core__list maybe__temperatures = _self->maybe__temperatures; /* list<maybe<double>> */
  kk_drop_match(_self, {kk_std_core__list_dup(maybe__temperatures);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x3033;
  kk_std_core__list _x3034 = kk_std_core__list_unbox(_b_2413, _ctx); /*list<double>*/
  _x3033 = kk_data_preprocessing__mlift1959_pre__process__data(maybe__temperatures, _x3034, _ctx); /*(list<list<list<double>>>, list<list<list<double>>>)*/
  return kk_std_core_types__tuple2__box(_x3033, _ctx);
}

kk_std_core_types__tuple2_ kk_data_preprocessing__mlift1960_pre__process__data(kk_std_core__list temperatures1, kk_std_core__list uncertainties1, kk_std_core__list uncertainties2, kk_std_core__list temperatures2, kk_context_t* _ctx) { /* (temperatures1 : list<maybe<double>>, uncertainties1 : list<maybe<double>>, uncertainties2 : list<maybe<double>>, temperatures2 : list<maybe<double>>) -> <exn,fsys,div> (list<list<list<double>>>, list<list<list<double>>>) */ 
  kk_std_core__list maybe__uncertainties;
  kk_std_core__list xss_2042;
  kk_std_core__list _b_2401_2399 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core__list_box(uncertainties2, _ctx), kk_std_core__new_Nil(_ctx), _ctx); /*list<list<maybe<double>>>*/;
  xss_2042 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core__list_box(uncertainties1, _ctx), _b_2401_2399, _ctx); /*list<list<maybe<double>>>*/
  maybe__uncertainties = kk_std_core__lift21045_concat(kk_std_core__new_Nil(_ctx), xss_2042, _ctx); /*list<maybe<double>>*/
  kk_std_core__list maybe__temperatures;
  kk_std_core__list xss0_2043;
  kk_std_core__list _b_2409_2407 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core__list_box(temperatures2, _ctx), kk_std_core__new_Nil(_ctx), _ctx); /*list<list<maybe<double>>>*/;
  xss0_2043 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core__list_box(temperatures1, _ctx), _b_2409_2407, _ctx); /*list<list<maybe<double>>>*/
  maybe__temperatures = kk_std_core__lift21045_concat(kk_std_core__new_Nil(_ctx), xss0_2043, _ctx); /*list<maybe<double>>*/
  kk_std_core__list x_2044 = kk_data_preprocessing_remove__maybes(maybe__uncertainties, kk_std_core__new_Nil(_ctx), _ctx); /*list<double>*/;
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_2044, _ctx);
    kk_box_t _x3031 = kk_std_core_hnd_yield_extend(kk_data_preprocessing__new_mlift1960_pre__process__data_fun3032(maybe__temperatures, _ctx), _ctx); /*2*/
    return kk_std_core_types__tuple2__unbox(_x3031, _ctx);
  }
  return kk_data_preprocessing__mlift1959_pre__process__data(maybe__temperatures, x_2044, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_data_preprocessing__mlift1961_pre__process__data_fun3037__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing__mlift1961_pre__process__data_fun3037(kk_function_t _fself, kk_box_t _b_2421, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing__new_mlift1961_pre__process__data_fun3037(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing__mlift1961_pre__process__data_fun3037, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_data_preprocessing__mlift1961_pre__process__data_fun3038__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing__mlift1961_pre__process__data_fun3038(kk_function_t _fself, kk_box_t _b_2418, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing__new_mlift1961_pre__process__data_fun3038(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing__mlift1961_pre__process__data_fun3038, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_data_preprocessing__mlift1961_pre__process__data_fun3038(kk_function_t _fself, kk_box_t _b_2418, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core_types__maybe _x3039;
  kk_string_t _x3040 = kk_string_unbox(_b_2418); /*string*/
  _x3039 = kk_std_num_double_parse_double(_x3040, _ctx); /*maybe<double>*/
  return kk_std_core_types__maybe_box(_x3039, _ctx);
}
static kk_box_t kk_data_preprocessing__mlift1961_pre__process__data_fun3037(kk_function_t _fself, kk_box_t _b_2421, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return kk_std_core_hnd__open_none1(kk_data_preprocessing__new_mlift1961_pre__process__data_fun3038(_ctx), _b_2421, _ctx);
}


// lift anonymous function
struct kk_data_preprocessing__mlift1961_pre__process__data_fun3042__t {
  struct kk_function_s _base;
  kk_std_core__list temperatures1;
  kk_std_core__list uncertainties1;
  kk_std_core__list uncertainties2;
};
static kk_box_t kk_data_preprocessing__mlift1961_pre__process__data_fun3042(kk_function_t _fself, kk_box_t _b_2428, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing__new_mlift1961_pre__process__data_fun3042(kk_std_core__list temperatures1, kk_std_core__list uncertainties1, kk_std_core__list uncertainties2, kk_context_t* _ctx) {
  struct kk_data_preprocessing__mlift1961_pre__process__data_fun3042__t* _self = kk_function_alloc_as(struct kk_data_preprocessing__mlift1961_pre__process__data_fun3042__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_data_preprocessing__mlift1961_pre__process__data_fun3042, kk_context());
  _self->temperatures1 = temperatures1;
  _self->uncertainties1 = uncertainties1;
  _self->uncertainties2 = uncertainties2;
  return &_self->_base;
}

static kk_box_t kk_data_preprocessing__mlift1961_pre__process__data_fun3042(kk_function_t _fself, kk_box_t _b_2428, kk_context_t* _ctx) {
  struct kk_data_preprocessing__mlift1961_pre__process__data_fun3042__t* _self = kk_function_as(struct kk_data_preprocessing__mlift1961_pre__process__data_fun3042__t*, _fself);
  kk_std_core__list temperatures1 = _self->temperatures1; /* list<maybe<double>> */
  kk_std_core__list uncertainties1 = _self->uncertainties1; /* list<maybe<double>> */
  kk_std_core__list uncertainties2 = _self->uncertainties2; /* list<maybe<double>> */
  kk_drop_match(_self, {kk_std_core__list_dup(temperatures1);kk_std_core__list_dup(uncertainties1);kk_std_core__list_dup(uncertainties2);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x3043;
  kk_std_core__list _x3044 = kk_std_core__list_unbox(_b_2428, _ctx); /*list<maybe<double>>*/
  _x3043 = kk_data_preprocessing__mlift1960_pre__process__data(temperatures1, uncertainties1, uncertainties2, _x3044, _ctx); /*(list<list<list<double>>>, list<list<list<double>>>)*/
  return kk_std_core_types__tuple2__box(_x3043, _ctx);
}

kk_std_core_types__tuple2_ kk_data_preprocessing__mlift1961_pre__process__data(kk_std_core__list temperatures1, kk_std_core__list uncertainties1, kk_std_core__list uncertainties2, kk_string_t _y_30, kk_context_t* _ctx) { /* (temperatures1 : list<maybe<double>>, uncertainties1 : list<maybe<double>>, uncertainties2 : list<maybe<double>>, string) -> <exn,fsys> (list<list<list<double>>>, list<list<list<double>>>) */ 
  kk_std_core__list x_2046;
  kk_std_core__list _b_2422_2419;
  kk_vector_t v_21689;
  kk_string_t _x3035;
  kk_define_string_literal(, _s3036, 1, "\n")
  _x3035 = kk_string_dup(_s3036); /*string*/
  v_21689 = kk_string_splitv(_y_30,_x3035,kk_context()); /*vector<string>*/
  _b_2422_2419 = kk_std_core_vlist(v_21689, kk_std_core_types__new_None(_ctx), _ctx); /*list<string>*/
  x_2046 = kk_std_core_map_5(_b_2422_2419, kk_data_preprocessing__new_mlift1961_pre__process__data_fun3037(_ctx), _ctx); /*list<maybe<double>>*/
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_2046, _ctx);
    kk_box_t _x3041 = kk_std_core_hnd_yield_extend(kk_data_preprocessing__new_mlift1961_pre__process__data_fun3042(temperatures1, uncertainties1, uncertainties2, _ctx), _ctx); /*2*/
    return kk_std_core_types__tuple2__unbox(_x3041, _ctx);
  }
  return kk_data_preprocessing__mlift1960_pre__process__data(temperatures1, uncertainties1, uncertainties2, x_2046, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_data_preprocessing__mlift1962_pre__process__data_fun3048__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing__mlift1962_pre__process__data_fun3048(kk_function_t _fself, kk_box_t _b_2433, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing__new_mlift1962_pre__process__data_fun3048(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing__mlift1962_pre__process__data_fun3048, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_data_preprocessing__mlift1962_pre__process__data_fun3048(kk_function_t _fself, kk_box_t _b_2433, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x3049;
  kk_std_os_path__path _x3050 = kk_std_os_path__path_unbox(_b_2433, _ctx); /*std/os/path/path*/
  _x3049 = kk_std_os_path_string(_x3050, _ctx); /*string*/
  return kk_string_box(_x3049);
}


// lift anonymous function
struct kk_data_preprocessing__mlift1962_pre__process__data_fun3054__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing__mlift1962_pre__process__data_fun3054(kk_function_t _fself, kk_box_t _b_2438, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing__new_mlift1962_pre__process__data_fun3054(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing__mlift1962_pre__process__data_fun3054, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_data_preprocessing__mlift1962_pre__process__data_fun3054(kk_function_t _fself, kk_box_t _b_2438, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core__error _x3055;
  kk_string_t _x3056 = kk_string_unbox(_b_2438); /*string*/
  _x3055 = kk_std_os_file_read_text_file_err(_x3056, _ctx); /*error<string>*/
  return kk_std_core__error_box(_x3055, _ctx);
}


// lift anonymous function
struct kk_data_preprocessing__mlift1962_pre__process__data_fun3063__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing__mlift1962_pre__process__data_fun3063(kk_function_t _fself, kk_box_t _b_2441, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing__new_mlift1962_pre__process__data_fun3063(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing__mlift1962_pre__process__data_fun3063, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_data_preprocessing__mlift1962_pre__process__data_fun3063(kk_function_t _fself, kk_box_t _b_2441, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x3064;
  kk_std_os_path__path _x3065 = kk_std_os_path__path_unbox(_b_2441, _ctx); /*std/os/path/path*/
  _x3064 = kk_std_os_path_show(_x3065, _ctx); /*string*/
  return kk_string_box(_x3064);
}


// lift anonymous function
struct kk_data_preprocessing__mlift1962_pre__process__data_fun3067__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing__mlift1962_pre__process__data_fun3067(kk_function_t _fself, kk_box_t _b_2447, kk_box_t _b_2448, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing__new_mlift1962_pre__process__data_fun3067(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing__mlift1962_pre__process__data_fun3067, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_data_preprocessing__mlift1962_pre__process__data_fun3067(kk_function_t _fself, kk_box_t _b_2447, kk_box_t _b_2448, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core__exception _x3068;
  kk_std_core__exception _x3069 = kk_std_core__exception_unbox(_b_2447, _ctx); /*exception*/
  kk_string_t _x3070 = kk_string_unbox(_b_2448); /*string*/
  _x3068 = kk_std_os_file_prepend(_x3069, _x3070, _ctx); /*exception*/
  return kk_std_core__exception_box(_x3068, _ctx);
}


// lift anonymous function
struct kk_data_preprocessing__mlift1962_pre__process__data_fun3075__t {
  struct kk_function_s _base;
  kk_std_core__list temperatures1;
  kk_std_core__list uncertainties1;
  kk_std_core__list uncertainties2;
};
static kk_box_t kk_data_preprocessing__mlift1962_pre__process__data_fun3075(kk_function_t _fself, kk_box_t _b_2459, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing__new_mlift1962_pre__process__data_fun3075(kk_std_core__list temperatures1, kk_std_core__list uncertainties1, kk_std_core__list uncertainties2, kk_context_t* _ctx) {
  struct kk_data_preprocessing__mlift1962_pre__process__data_fun3075__t* _self = kk_function_alloc_as(struct kk_data_preprocessing__mlift1962_pre__process__data_fun3075__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_data_preprocessing__mlift1962_pre__process__data_fun3075, kk_context());
  _self->temperatures1 = temperatures1;
  _self->uncertainties1 = uncertainties1;
  _self->uncertainties2 = uncertainties2;
  return &_self->_base;
}

static kk_box_t kk_data_preprocessing__mlift1962_pre__process__data_fun3075(kk_function_t _fself, kk_box_t _b_2459, kk_context_t* _ctx) {
  struct kk_data_preprocessing__mlift1962_pre__process__data_fun3075__t* _self = kk_function_as(struct kk_data_preprocessing__mlift1962_pre__process__data_fun3075__t*, _fself);
  kk_std_core__list temperatures1 = _self->temperatures1; /* list<maybe<double>> */
  kk_std_core__list uncertainties1 = _self->uncertainties1; /* list<maybe<double>> */
  kk_std_core__list uncertainties2 = _self->uncertainties2; /* list<maybe<double>> */
  kk_drop_match(_self, {kk_std_core__list_dup(temperatures1);kk_std_core__list_dup(uncertainties1);kk_std_core__list_dup(uncertainties2);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x3076;
  kk_string_t _x3077 = kk_string_unbox(_b_2459); /*string*/
  _x3076 = kk_data_preprocessing__mlift1961_pre__process__data(temperatures1, uncertainties1, uncertainties2, _x3077, _ctx); /*(list<list<list<double>>>, list<list<list<double>>>)*/
  return kk_std_core_types__tuple2__box(_x3076, _ctx);
}

kk_std_core_types__tuple2_ kk_data_preprocessing__mlift1962_pre__process__data(kk_std_core__list uncertainties1, kk_std_core__list uncertainties2, kk_std_core__list temperatures1, kk_context_t* _ctx) { /* (uncertainties1 : list<maybe<double>>, uncertainties2 : list<maybe<double>>, temperatures1 : list<maybe<double>>) -> <exn,fsys,div> (list<list<list<double>>>, list<list<list<double>>>) */ 
  kk_string_t x_2050;
  kk_std_os_path__path path_2052;
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*std/core/hnd/evv<(<>)>*/;
  kk_std_os_path__path x2;
  kk_string_t _x3045;
  kk_define_string_literal(, _s3046, 32, "./data/temperature-readings2.txt")
  _x3045 = kk_string_dup(_s3046); /*string*/
  x2 = kk_std_os_path_path(_x3045, _ctx); /*std/os/path/path*/
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  path_2052 = x2; /*std/os/path/path*/
  kk_std_core__error _match_2829;
  kk_string_t _x1;
  kk_box_t _x3047;
  kk_box_t _x3051;
  kk_std_os_path__path _x3052 = kk_std_os_path__path_dup(path_2052); /*std/os/path/path*/
  _x3051 = kk_std_os_path__path_box(_x3052, _ctx); /*1*/
  _x3047 = kk_std_core_hnd__open_none1(kk_data_preprocessing__new_mlift1962_pre__process__data_fun3048(_ctx), _x3051, _ctx); /*2*/
  _x1 = kk_string_unbox(_x3047); /*string*/
  kk_box_t _x3053 = kk_std_core_hnd__open_none1(kk_data_preprocessing__new_mlift1962_pre__process__data_fun3054(_ctx), kk_string_box(_x1), _ctx); /*2*/
  _match_2829 = kk_std_core__error_unbox(_x3053, _ctx); /*error<string>*/
  if (kk_std_core__is_Error(_match_2829)) {
    kk_std_core__exception exn = _match_2829._cons.Error.exception;
    kk_std_core__exception_dup(exn);
    kk_std_core__error_drop(_match_2829, _ctx);
    kk_std_core__error err_479;
    kk_std_core__exception _x3058;
    kk_string_t _x2;
    kk_string_t _x3059;
    kk_define_string_literal(, _s3060, 25, "unable to read text file ")
    _x3059 = kk_string_dup(_s3060); /*string*/
    kk_string_t _x3061;
    kk_box_t _x3062 = kk_std_core_hnd__open_none1(kk_data_preprocessing__new_mlift1962_pre__process__data_fun3063(_ctx), kk_std_os_path__path_box(path_2052, _ctx), _ctx); /*2*/
    _x3061 = kk_string_unbox(_x3062); /*string*/
    _x2 = kk_std_core__lp__plus__plus__1_rp_(_x3059, _x3061, _ctx); /*string*/
    kk_box_t _x3066 = kk_std_core_hnd__open_none2(kk_data_preprocessing__new_mlift1962_pre__process__data_fun3067(_ctx), kk_std_core__exception_box(exn, _ctx), kk_string_box(_x2), _ctx); /*3*/
    _x3058 = kk_std_core__exception_unbox(_x3066, _ctx); /*exception*/
    err_479 = kk_std_core__new_Error(_x3058, _ctx); /*error<string>*/
    if (kk_std_core__is_Error(err_479)) {
      kk_std_core__exception exn0 = err_479._cons.Error.exception;
      kk_std_core__exception_dup(exn0);
      kk_std_core__error_drop(err_479, _ctx);
      kk_box_t _x3071 = kk_std_core_throw_exn(exn0, _ctx); /*1*/
      x_2050 = kk_string_unbox(_x3071); /*string*/
      goto _match3057;
    }
    kk_box_t _box_x2453 = err_479._cons.Ok.result;
    kk_string_t x0 = kk_string_unbox(_box_x2453);
    kk_string_dup(x0);
    kk_std_core__error_drop(err_479, _ctx);
    x_2050 = x0; /*string*/
    goto _match3057;
  }
  kk_box_t _box_x2454 = _match_2829._cons.Ok.result;
  kk_string_t content = kk_string_unbox(_box_x2454);
  kk_std_os_path__path_drop(path_2052, _ctx);
  kk_string_dup(content);
  kk_std_core__error_drop(_match_2829, _ctx);
  x_2050 = content; /*string*/
  _match3057: ;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_2050, _ctx);
    kk_box_t _x3074 = kk_std_core_hnd_yield_extend(kk_data_preprocessing__new_mlift1962_pre__process__data_fun3075(temperatures1, uncertainties1, uncertainties2, _ctx), _ctx); /*2*/
    return kk_std_core_types__tuple2__unbox(_x3074, _ctx);
  }
  return kk_data_preprocessing__mlift1961_pre__process__data(temperatures1, uncertainties1, uncertainties2, x_2050, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_data_preprocessing__mlift1963_pre__process__data_fun3080__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing__mlift1963_pre__process__data_fun3080(kk_function_t _fself, kk_box_t _b_2467, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing__new_mlift1963_pre__process__data_fun3080(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing__mlift1963_pre__process__data_fun3080, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_data_preprocessing__mlift1963_pre__process__data_fun3081__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing__mlift1963_pre__process__data_fun3081(kk_function_t _fself, kk_box_t _b_2464, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing__new_mlift1963_pre__process__data_fun3081(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing__mlift1963_pre__process__data_fun3081, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_data_preprocessing__mlift1963_pre__process__data_fun3081(kk_function_t _fself, kk_box_t _b_2464, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core_types__maybe _x3082;
  kk_string_t _x3083 = kk_string_unbox(_b_2464); /*string*/
  _x3082 = kk_std_num_double_parse_double(_x3083, _ctx); /*maybe<double>*/
  return kk_std_core_types__maybe_box(_x3082, _ctx);
}
static kk_box_t kk_data_preprocessing__mlift1963_pre__process__data_fun3080(kk_function_t _fself, kk_box_t _b_2467, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return kk_std_core_hnd__open_none1(kk_data_preprocessing__new_mlift1963_pre__process__data_fun3081(_ctx), _b_2467, _ctx);
}


// lift anonymous function
struct kk_data_preprocessing__mlift1963_pre__process__data_fun3085__t {
  struct kk_function_s _base;
  kk_std_core__list uncertainties1;
  kk_std_core__list uncertainties2;
};
static kk_box_t kk_data_preprocessing__mlift1963_pre__process__data_fun3085(kk_function_t _fself, kk_box_t _b_2474, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing__new_mlift1963_pre__process__data_fun3085(kk_std_core__list uncertainties1, kk_std_core__list uncertainties2, kk_context_t* _ctx) {
  struct kk_data_preprocessing__mlift1963_pre__process__data_fun3085__t* _self = kk_function_alloc_as(struct kk_data_preprocessing__mlift1963_pre__process__data_fun3085__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_data_preprocessing__mlift1963_pre__process__data_fun3085, kk_context());
  _self->uncertainties1 = uncertainties1;
  _self->uncertainties2 = uncertainties2;
  return &_self->_base;
}

static kk_box_t kk_data_preprocessing__mlift1963_pre__process__data_fun3085(kk_function_t _fself, kk_box_t _b_2474, kk_context_t* _ctx) {
  struct kk_data_preprocessing__mlift1963_pre__process__data_fun3085__t* _self = kk_function_as(struct kk_data_preprocessing__mlift1963_pre__process__data_fun3085__t*, _fself);
  kk_std_core__list uncertainties1 = _self->uncertainties1; /* list<maybe<double>> */
  kk_std_core__list uncertainties2 = _self->uncertainties2; /* list<maybe<double>> */
  kk_drop_match(_self, {kk_std_core__list_dup(uncertainties1);kk_std_core__list_dup(uncertainties2);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x3086;
  kk_std_core__list _x3087 = kk_std_core__list_unbox(_b_2474, _ctx); /*list<maybe<double>>*/
  _x3086 = kk_data_preprocessing__mlift1962_pre__process__data(uncertainties1, uncertainties2, _x3087, _ctx); /*(list<list<list<double>>>, list<list<list<double>>>)*/
  return kk_std_core_types__tuple2__box(_x3086, _ctx);
}

kk_std_core_types__tuple2_ kk_data_preprocessing__mlift1963_pre__process__data(kk_std_core__list uncertainties1, kk_std_core__list uncertainties2, kk_string_t _y_28, kk_context_t* _ctx) { /* (uncertainties1 : list<maybe<double>>, uncertainties2 : list<maybe<double>>, string) -> <exn,fsys> (list<list<list<double>>>, list<list<list<double>>>) */ 
  kk_std_core__list x_2055;
  kk_std_core__list _b_2468_2465;
  kk_vector_t v_21689;
  kk_string_t _x3078;
  kk_define_string_literal(, _s3079, 1, "\n")
  _x3078 = kk_string_dup(_s3079); /*string*/
  v_21689 = kk_string_splitv(_y_28,_x3078,kk_context()); /*vector<string>*/
  _b_2468_2465 = kk_std_core_vlist(v_21689, kk_std_core_types__new_None(_ctx), _ctx); /*list<string>*/
  x_2055 = kk_std_core_map_5(_b_2468_2465, kk_data_preprocessing__new_mlift1963_pre__process__data_fun3080(_ctx), _ctx); /*list<maybe<double>>*/
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_2055, _ctx);
    kk_box_t _x3084 = kk_std_core_hnd_yield_extend(kk_data_preprocessing__new_mlift1963_pre__process__data_fun3085(uncertainties1, uncertainties2, _ctx), _ctx); /*2*/
    return kk_std_core_types__tuple2__unbox(_x3084, _ctx);
  }
  return kk_data_preprocessing__mlift1962_pre__process__data(uncertainties1, uncertainties2, x_2055, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_data_preprocessing__mlift1964_pre__process__data_fun3091__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing__mlift1964_pre__process__data_fun3091(kk_function_t _fself, kk_box_t _b_2479, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing__new_mlift1964_pre__process__data_fun3091(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing__mlift1964_pre__process__data_fun3091, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_data_preprocessing__mlift1964_pre__process__data_fun3091(kk_function_t _fself, kk_box_t _b_2479, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x3092;
  kk_std_os_path__path _x3093 = kk_std_os_path__path_unbox(_b_2479, _ctx); /*std/os/path/path*/
  _x3092 = kk_std_os_path_string(_x3093, _ctx); /*string*/
  return kk_string_box(_x3092);
}


// lift anonymous function
struct kk_data_preprocessing__mlift1964_pre__process__data_fun3097__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing__mlift1964_pre__process__data_fun3097(kk_function_t _fself, kk_box_t _b_2484, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing__new_mlift1964_pre__process__data_fun3097(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing__mlift1964_pre__process__data_fun3097, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_data_preprocessing__mlift1964_pre__process__data_fun3097(kk_function_t _fself, kk_box_t _b_2484, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core__error _x3098;
  kk_string_t _x3099 = kk_string_unbox(_b_2484); /*string*/
  _x3098 = kk_std_os_file_read_text_file_err(_x3099, _ctx); /*error<string>*/
  return kk_std_core__error_box(_x3098, _ctx);
}


// lift anonymous function
struct kk_data_preprocessing__mlift1964_pre__process__data_fun3106__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing__mlift1964_pre__process__data_fun3106(kk_function_t _fself, kk_box_t _b_2487, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing__new_mlift1964_pre__process__data_fun3106(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing__mlift1964_pre__process__data_fun3106, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_data_preprocessing__mlift1964_pre__process__data_fun3106(kk_function_t _fself, kk_box_t _b_2487, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x3107;
  kk_std_os_path__path _x3108 = kk_std_os_path__path_unbox(_b_2487, _ctx); /*std/os/path/path*/
  _x3107 = kk_std_os_path_show(_x3108, _ctx); /*string*/
  return kk_string_box(_x3107);
}


// lift anonymous function
struct kk_data_preprocessing__mlift1964_pre__process__data_fun3110__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing__mlift1964_pre__process__data_fun3110(kk_function_t _fself, kk_box_t _b_2493, kk_box_t _b_2494, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing__new_mlift1964_pre__process__data_fun3110(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing__mlift1964_pre__process__data_fun3110, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_data_preprocessing__mlift1964_pre__process__data_fun3110(kk_function_t _fself, kk_box_t _b_2493, kk_box_t _b_2494, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core__exception _x3111;
  kk_std_core__exception _x3112 = kk_std_core__exception_unbox(_b_2493, _ctx); /*exception*/
  kk_string_t _x3113 = kk_string_unbox(_b_2494); /*string*/
  _x3111 = kk_std_os_file_prepend(_x3112, _x3113, _ctx); /*exception*/
  return kk_std_core__exception_box(_x3111, _ctx);
}


// lift anonymous function
struct kk_data_preprocessing__mlift1964_pre__process__data_fun3118__t {
  struct kk_function_s _base;
  kk_std_core__list uncertainties1;
  kk_std_core__list uncertainties2;
};
static kk_box_t kk_data_preprocessing__mlift1964_pre__process__data_fun3118(kk_function_t _fself, kk_box_t _b_2505, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing__new_mlift1964_pre__process__data_fun3118(kk_std_core__list uncertainties1, kk_std_core__list uncertainties2, kk_context_t* _ctx) {
  struct kk_data_preprocessing__mlift1964_pre__process__data_fun3118__t* _self = kk_function_alloc_as(struct kk_data_preprocessing__mlift1964_pre__process__data_fun3118__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_data_preprocessing__mlift1964_pre__process__data_fun3118, kk_context());
  _self->uncertainties1 = uncertainties1;
  _self->uncertainties2 = uncertainties2;
  return &_self->_base;
}

static kk_box_t kk_data_preprocessing__mlift1964_pre__process__data_fun3118(kk_function_t _fself, kk_box_t _b_2505, kk_context_t* _ctx) {
  struct kk_data_preprocessing__mlift1964_pre__process__data_fun3118__t* _self = kk_function_as(struct kk_data_preprocessing__mlift1964_pre__process__data_fun3118__t*, _fself);
  kk_std_core__list uncertainties1 = _self->uncertainties1; /* list<maybe<double>> */
  kk_std_core__list uncertainties2 = _self->uncertainties2; /* list<maybe<double>> */
  kk_drop_match(_self, {kk_std_core__list_dup(uncertainties1);kk_std_core__list_dup(uncertainties2);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x3119;
  kk_string_t _x3120 = kk_string_unbox(_b_2505); /*string*/
  _x3119 = kk_data_preprocessing__mlift1963_pre__process__data(uncertainties1, uncertainties2, _x3120, _ctx); /*(list<list<list<double>>>, list<list<list<double>>>)*/
  return kk_std_core_types__tuple2__box(_x3119, _ctx);
}

kk_std_core_types__tuple2_ kk_data_preprocessing__mlift1964_pre__process__data(kk_std_core__list uncertainties1, kk_std_core__list uncertainties2, kk_context_t* _ctx) { /* (uncertainties1 : list<maybe<double>>, uncertainties2 : list<maybe<double>>) -> <exn,fsys,div> (list<list<list<double>>>, list<list<list<double>>>) */ 
  kk_string_t x_2059;
  kk_std_os_path__path path_2061;
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*std/core/hnd/evv<(<>)>*/;
  kk_std_os_path__path x2;
  kk_string_t _x3088;
  kk_define_string_literal(, _s3089, 32, "./data/temperature-readings1.txt")
  _x3088 = kk_string_dup(_s3089); /*string*/
  x2 = kk_std_os_path_path(_x3088, _ctx); /*std/os/path/path*/
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  path_2061 = x2; /*std/os/path/path*/
  kk_std_core__error _match_2826;
  kk_string_t _x1;
  kk_box_t _x3090;
  kk_box_t _x3094;
  kk_std_os_path__path _x3095 = kk_std_os_path__path_dup(path_2061); /*std/os/path/path*/
  _x3094 = kk_std_os_path__path_box(_x3095, _ctx); /*1*/
  _x3090 = kk_std_core_hnd__open_none1(kk_data_preprocessing__new_mlift1964_pre__process__data_fun3091(_ctx), _x3094, _ctx); /*2*/
  _x1 = kk_string_unbox(_x3090); /*string*/
  kk_box_t _x3096 = kk_std_core_hnd__open_none1(kk_data_preprocessing__new_mlift1964_pre__process__data_fun3097(_ctx), kk_string_box(_x1), _ctx); /*2*/
  _match_2826 = kk_std_core__error_unbox(_x3096, _ctx); /*error<string>*/
  if (kk_std_core__is_Error(_match_2826)) {
    kk_std_core__exception exn = _match_2826._cons.Error.exception;
    kk_std_core__exception_dup(exn);
    kk_std_core__error_drop(_match_2826, _ctx);
    kk_std_core__error err_479;
    kk_std_core__exception _x3101;
    kk_string_t _x2;
    kk_string_t _x3102;
    kk_define_string_literal(, _s3103, 25, "unable to read text file ")
    _x3102 = kk_string_dup(_s3103); /*string*/
    kk_string_t _x3104;
    kk_box_t _x3105 = kk_std_core_hnd__open_none1(kk_data_preprocessing__new_mlift1964_pre__process__data_fun3106(_ctx), kk_std_os_path__path_box(path_2061, _ctx), _ctx); /*2*/
    _x3104 = kk_string_unbox(_x3105); /*string*/
    _x2 = kk_std_core__lp__plus__plus__1_rp_(_x3102, _x3104, _ctx); /*string*/
    kk_box_t _x3109 = kk_std_core_hnd__open_none2(kk_data_preprocessing__new_mlift1964_pre__process__data_fun3110(_ctx), kk_std_core__exception_box(exn, _ctx), kk_string_box(_x2), _ctx); /*3*/
    _x3101 = kk_std_core__exception_unbox(_x3109, _ctx); /*exception*/
    err_479 = kk_std_core__new_Error(_x3101, _ctx); /*error<string>*/
    if (kk_std_core__is_Error(err_479)) {
      kk_std_core__exception exn0 = err_479._cons.Error.exception;
      kk_std_core__exception_dup(exn0);
      kk_std_core__error_drop(err_479, _ctx);
      kk_box_t _x3114 = kk_std_core_throw_exn(exn0, _ctx); /*1*/
      x_2059 = kk_string_unbox(_x3114); /*string*/
      goto _match3100;
    }
    kk_box_t _box_x2499 = err_479._cons.Ok.result;
    kk_string_t x0 = kk_string_unbox(_box_x2499);
    kk_string_dup(x0);
    kk_std_core__error_drop(err_479, _ctx);
    x_2059 = x0; /*string*/
    goto _match3100;
  }
  kk_box_t _box_x2500 = _match_2826._cons.Ok.result;
  kk_string_t content = kk_string_unbox(_box_x2500);
  kk_std_os_path__path_drop(path_2061, _ctx);
  kk_string_dup(content);
  kk_std_core__error_drop(_match_2826, _ctx);
  x_2059 = content; /*string*/
  _match3100: ;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_2059, _ctx);
    kk_box_t _x3117 = kk_std_core_hnd_yield_extend(kk_data_preprocessing__new_mlift1964_pre__process__data_fun3118(uncertainties1, uncertainties2, _ctx), _ctx); /*2*/
    return kk_std_core_types__tuple2__unbox(_x3117, _ctx);
  }
  return kk_data_preprocessing__mlift1963_pre__process__data(uncertainties1, uncertainties2, x_2059, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_data_preprocessing__mlift1965_pre__process__data_fun3123__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing__mlift1965_pre__process__data_fun3123(kk_function_t _fself, kk_box_t _b_2513, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing__new_mlift1965_pre__process__data_fun3123(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing__mlift1965_pre__process__data_fun3123, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_data_preprocessing__mlift1965_pre__process__data_fun3124__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing__mlift1965_pre__process__data_fun3124(kk_function_t _fself, kk_box_t _b_2510, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing__new_mlift1965_pre__process__data_fun3124(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing__mlift1965_pre__process__data_fun3124, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_data_preprocessing__mlift1965_pre__process__data_fun3124(kk_function_t _fself, kk_box_t _b_2510, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core_types__maybe _x3125;
  kk_string_t _x3126 = kk_string_unbox(_b_2510); /*string*/
  _x3125 = kk_std_num_double_parse_double(_x3126, _ctx); /*maybe<double>*/
  return kk_std_core_types__maybe_box(_x3125, _ctx);
}
static kk_box_t kk_data_preprocessing__mlift1965_pre__process__data_fun3123(kk_function_t _fself, kk_box_t _b_2513, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return kk_std_core_hnd__open_none1(kk_data_preprocessing__new_mlift1965_pre__process__data_fun3124(_ctx), _b_2513, _ctx);
}


// lift anonymous function
struct kk_data_preprocessing__mlift1965_pre__process__data_fun3128__t {
  struct kk_function_s _base;
  kk_std_core__list uncertainties1;
};
static kk_box_t kk_data_preprocessing__mlift1965_pre__process__data_fun3128(kk_function_t _fself, kk_box_t _b_2520, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing__new_mlift1965_pre__process__data_fun3128(kk_std_core__list uncertainties1, kk_context_t* _ctx) {
  struct kk_data_preprocessing__mlift1965_pre__process__data_fun3128__t* _self = kk_function_alloc_as(struct kk_data_preprocessing__mlift1965_pre__process__data_fun3128__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_data_preprocessing__mlift1965_pre__process__data_fun3128, kk_context());
  _self->uncertainties1 = uncertainties1;
  return &_self->_base;
}

static kk_box_t kk_data_preprocessing__mlift1965_pre__process__data_fun3128(kk_function_t _fself, kk_box_t _b_2520, kk_context_t* _ctx) {
  struct kk_data_preprocessing__mlift1965_pre__process__data_fun3128__t* _self = kk_function_as(struct kk_data_preprocessing__mlift1965_pre__process__data_fun3128__t*, _fself);
  kk_std_core__list uncertainties1 = _self->uncertainties1; /* list<maybe<double>> */
  kk_drop_match(_self, {kk_std_core__list_dup(uncertainties1);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x3129;
  kk_std_core__list _x3130 = kk_std_core__list_unbox(_b_2520, _ctx); /*list<maybe<double>>*/
  _x3129 = kk_data_preprocessing__mlift1964_pre__process__data(uncertainties1, _x3130, _ctx); /*(list<list<list<double>>>, list<list<list<double>>>)*/
  return kk_std_core_types__tuple2__box(_x3129, _ctx);
}

kk_std_core_types__tuple2_ kk_data_preprocessing__mlift1965_pre__process__data(kk_std_core__list uncertainties1, kk_string_t _y_26, kk_context_t* _ctx) { /* (uncertainties1 : list<maybe<double>>, string) -> <exn,fsys> (list<list<list<double>>>, list<list<list<double>>>) */ 
  kk_std_core__list x_2064;
  kk_std_core__list _b_2514_2511;
  kk_vector_t v_21689;
  kk_string_t _x3121;
  kk_define_string_literal(, _s3122, 1, "\n")
  _x3121 = kk_string_dup(_s3122); /*string*/
  v_21689 = kk_string_splitv(_y_26,_x3121,kk_context()); /*vector<string>*/
  _b_2514_2511 = kk_std_core_vlist(v_21689, kk_std_core_types__new_None(_ctx), _ctx); /*list<string>*/
  x_2064 = kk_std_core_map_5(_b_2514_2511, kk_data_preprocessing__new_mlift1965_pre__process__data_fun3123(_ctx), _ctx); /*list<maybe<double>>*/
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_2064, _ctx);
    kk_box_t _x3127 = kk_std_core_hnd_yield_extend(kk_data_preprocessing__new_mlift1965_pre__process__data_fun3128(uncertainties1, _ctx), _ctx); /*2*/
    return kk_std_core_types__tuple2__unbox(_x3127, _ctx);
  }
  return kk_data_preprocessing__mlift1964_pre__process__data(uncertainties1, x_2064, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_data_preprocessing__mlift1966_pre__process__data_fun3134__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing__mlift1966_pre__process__data_fun3134(kk_function_t _fself, kk_box_t _b_2525, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing__new_mlift1966_pre__process__data_fun3134(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing__mlift1966_pre__process__data_fun3134, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_data_preprocessing__mlift1966_pre__process__data_fun3134(kk_function_t _fself, kk_box_t _b_2525, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x3135;
  kk_std_os_path__path _x3136 = kk_std_os_path__path_unbox(_b_2525, _ctx); /*std/os/path/path*/
  _x3135 = kk_std_os_path_string(_x3136, _ctx); /*string*/
  return kk_string_box(_x3135);
}


// lift anonymous function
struct kk_data_preprocessing__mlift1966_pre__process__data_fun3140__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing__mlift1966_pre__process__data_fun3140(kk_function_t _fself, kk_box_t _b_2530, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing__new_mlift1966_pre__process__data_fun3140(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing__mlift1966_pre__process__data_fun3140, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_data_preprocessing__mlift1966_pre__process__data_fun3140(kk_function_t _fself, kk_box_t _b_2530, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core__error _x3141;
  kk_string_t _x3142 = kk_string_unbox(_b_2530); /*string*/
  _x3141 = kk_std_os_file_read_text_file_err(_x3142, _ctx); /*error<string>*/
  return kk_std_core__error_box(_x3141, _ctx);
}


// lift anonymous function
struct kk_data_preprocessing__mlift1966_pre__process__data_fun3149__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing__mlift1966_pre__process__data_fun3149(kk_function_t _fself, kk_box_t _b_2533, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing__new_mlift1966_pre__process__data_fun3149(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing__mlift1966_pre__process__data_fun3149, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_data_preprocessing__mlift1966_pre__process__data_fun3149(kk_function_t _fself, kk_box_t _b_2533, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x3150;
  kk_std_os_path__path _x3151 = kk_std_os_path__path_unbox(_b_2533, _ctx); /*std/os/path/path*/
  _x3150 = kk_std_os_path_show(_x3151, _ctx); /*string*/
  return kk_string_box(_x3150);
}


// lift anonymous function
struct kk_data_preprocessing__mlift1966_pre__process__data_fun3153__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing__mlift1966_pre__process__data_fun3153(kk_function_t _fself, kk_box_t _b_2539, kk_box_t _b_2540, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing__new_mlift1966_pre__process__data_fun3153(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing__mlift1966_pre__process__data_fun3153, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_data_preprocessing__mlift1966_pre__process__data_fun3153(kk_function_t _fself, kk_box_t _b_2539, kk_box_t _b_2540, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core__exception _x3154;
  kk_std_core__exception _x3155 = kk_std_core__exception_unbox(_b_2539, _ctx); /*exception*/
  kk_string_t _x3156 = kk_string_unbox(_b_2540); /*string*/
  _x3154 = kk_std_os_file_prepend(_x3155, _x3156, _ctx); /*exception*/
  return kk_std_core__exception_box(_x3154, _ctx);
}


// lift anonymous function
struct kk_data_preprocessing__mlift1966_pre__process__data_fun3161__t {
  struct kk_function_s _base;
  kk_std_core__list uncertainties1;
};
static kk_box_t kk_data_preprocessing__mlift1966_pre__process__data_fun3161(kk_function_t _fself, kk_box_t _b_2551, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing__new_mlift1966_pre__process__data_fun3161(kk_std_core__list uncertainties1, kk_context_t* _ctx) {
  struct kk_data_preprocessing__mlift1966_pre__process__data_fun3161__t* _self = kk_function_alloc_as(struct kk_data_preprocessing__mlift1966_pre__process__data_fun3161__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_data_preprocessing__mlift1966_pre__process__data_fun3161, kk_context());
  _self->uncertainties1 = uncertainties1;
  return &_self->_base;
}

static kk_box_t kk_data_preprocessing__mlift1966_pre__process__data_fun3161(kk_function_t _fself, kk_box_t _b_2551, kk_context_t* _ctx) {
  struct kk_data_preprocessing__mlift1966_pre__process__data_fun3161__t* _self = kk_function_as(struct kk_data_preprocessing__mlift1966_pre__process__data_fun3161__t*, _fself);
  kk_std_core__list uncertainties1 = _self->uncertainties1; /* list<maybe<double>> */
  kk_drop_match(_self, {kk_std_core__list_dup(uncertainties1);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x3162;
  kk_string_t _x3163 = kk_string_unbox(_b_2551); /*string*/
  _x3162 = kk_data_preprocessing__mlift1965_pre__process__data(uncertainties1, _x3163, _ctx); /*(list<list<list<double>>>, list<list<list<double>>>)*/
  return kk_std_core_types__tuple2__box(_x3162, _ctx);
}

kk_std_core_types__tuple2_ kk_data_preprocessing__mlift1966_pre__process__data(kk_std_core__list uncertainties1, kk_context_t* _ctx) { /* (uncertainties1 : list<maybe<double>>) -> <exn,fsys,div> (list<list<list<double>>>, list<list<list<double>>>) */ 
  kk_string_t x_2068;
  kk_std_os_path__path path_2070;
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*std/core/hnd/evv<(<>)>*/;
  kk_std_os_path__path x2;
  kk_string_t _x3131;
  kk_define_string_literal(, _s3132, 37, "./data/measurement-uncertainties2.txt")
  _x3131 = kk_string_dup(_s3132); /*string*/
  x2 = kk_std_os_path_path(_x3131, _ctx); /*std/os/path/path*/
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  path_2070 = x2; /*std/os/path/path*/
  kk_std_core__error _match_2823;
  kk_string_t _x1;
  kk_box_t _x3133;
  kk_box_t _x3137;
  kk_std_os_path__path _x3138 = kk_std_os_path__path_dup(path_2070); /*std/os/path/path*/
  _x3137 = kk_std_os_path__path_box(_x3138, _ctx); /*1*/
  _x3133 = kk_std_core_hnd__open_none1(kk_data_preprocessing__new_mlift1966_pre__process__data_fun3134(_ctx), _x3137, _ctx); /*2*/
  _x1 = kk_string_unbox(_x3133); /*string*/
  kk_box_t _x3139 = kk_std_core_hnd__open_none1(kk_data_preprocessing__new_mlift1966_pre__process__data_fun3140(_ctx), kk_string_box(_x1), _ctx); /*2*/
  _match_2823 = kk_std_core__error_unbox(_x3139, _ctx); /*error<string>*/
  if (kk_std_core__is_Error(_match_2823)) {
    kk_std_core__exception exn = _match_2823._cons.Error.exception;
    kk_std_core__exception_dup(exn);
    kk_std_core__error_drop(_match_2823, _ctx);
    kk_std_core__error err_479;
    kk_std_core__exception _x3144;
    kk_string_t _x2;
    kk_string_t _x3145;
    kk_define_string_literal(, _s3146, 25, "unable to read text file ")
    _x3145 = kk_string_dup(_s3146); /*string*/
    kk_string_t _x3147;
    kk_box_t _x3148 = kk_std_core_hnd__open_none1(kk_data_preprocessing__new_mlift1966_pre__process__data_fun3149(_ctx), kk_std_os_path__path_box(path_2070, _ctx), _ctx); /*2*/
    _x3147 = kk_string_unbox(_x3148); /*string*/
    _x2 = kk_std_core__lp__plus__plus__1_rp_(_x3145, _x3147, _ctx); /*string*/
    kk_box_t _x3152 = kk_std_core_hnd__open_none2(kk_data_preprocessing__new_mlift1966_pre__process__data_fun3153(_ctx), kk_std_core__exception_box(exn, _ctx), kk_string_box(_x2), _ctx); /*3*/
    _x3144 = kk_std_core__exception_unbox(_x3152, _ctx); /*exception*/
    err_479 = kk_std_core__new_Error(_x3144, _ctx); /*error<string>*/
    if (kk_std_core__is_Error(err_479)) {
      kk_std_core__exception exn0 = err_479._cons.Error.exception;
      kk_std_core__exception_dup(exn0);
      kk_std_core__error_drop(err_479, _ctx);
      kk_box_t _x3157 = kk_std_core_throw_exn(exn0, _ctx); /*1*/
      x_2068 = kk_string_unbox(_x3157); /*string*/
      goto _match3143;
    }
    kk_box_t _box_x2545 = err_479._cons.Ok.result;
    kk_string_t x0 = kk_string_unbox(_box_x2545);
    kk_string_dup(x0);
    kk_std_core__error_drop(err_479, _ctx);
    x_2068 = x0; /*string*/
    goto _match3143;
  }
  kk_box_t _box_x2546 = _match_2823._cons.Ok.result;
  kk_string_t content = kk_string_unbox(_box_x2546);
  kk_std_os_path__path_drop(path_2070, _ctx);
  kk_string_dup(content);
  kk_std_core__error_drop(_match_2823, _ctx);
  x_2068 = content; /*string*/
  _match3143: ;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_2068, _ctx);
    kk_box_t _x3160 = kk_std_core_hnd_yield_extend(kk_data_preprocessing__new_mlift1966_pre__process__data_fun3161(uncertainties1, _ctx), _ctx); /*2*/
    return kk_std_core_types__tuple2__unbox(_x3160, _ctx);
  }
  return kk_data_preprocessing__mlift1965_pre__process__data(uncertainties1, x_2068, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_data_preprocessing__mlift1967_pre__process__data_fun3166__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing__mlift1967_pre__process__data_fun3166(kk_function_t _fself, kk_box_t _b_2559, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing__new_mlift1967_pre__process__data_fun3166(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing__mlift1967_pre__process__data_fun3166, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_data_preprocessing__mlift1967_pre__process__data_fun3167__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing__mlift1967_pre__process__data_fun3167(kk_function_t _fself, kk_box_t _b_2556, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing__new_mlift1967_pre__process__data_fun3167(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing__mlift1967_pre__process__data_fun3167, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_data_preprocessing__mlift1967_pre__process__data_fun3167(kk_function_t _fself, kk_box_t _b_2556, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core_types__maybe _x3168;
  kk_string_t _x3169 = kk_string_unbox(_b_2556); /*string*/
  _x3168 = kk_std_num_double_parse_double(_x3169, _ctx); /*maybe<double>*/
  return kk_std_core_types__maybe_box(_x3168, _ctx);
}
static kk_box_t kk_data_preprocessing__mlift1967_pre__process__data_fun3166(kk_function_t _fself, kk_box_t _b_2559, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return kk_std_core_hnd__open_none1(kk_data_preprocessing__new_mlift1967_pre__process__data_fun3167(_ctx), _b_2559, _ctx);
}


// lift anonymous function
struct kk_data_preprocessing__mlift1967_pre__process__data_fun3171__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing__mlift1967_pre__process__data_fun3171(kk_function_t _fself, kk_box_t _b_2566, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing__new_mlift1967_pre__process__data_fun3171(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing__mlift1967_pre__process__data_fun3171, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_data_preprocessing__mlift1967_pre__process__data_fun3171(kk_function_t _fself, kk_box_t _b_2566, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core_types__tuple2_ _x3172;
  kk_std_core__list _x3173 = kk_std_core__list_unbox(_b_2566, _ctx); /*list<maybe<double>>*/
  _x3172 = kk_data_preprocessing__mlift1966_pre__process__data(_x3173, _ctx); /*(list<list<list<double>>>, list<list<list<double>>>)*/
  return kk_std_core_types__tuple2__box(_x3172, _ctx);
}

kk_std_core_types__tuple2_ kk_data_preprocessing__mlift1967_pre__process__data(kk_string_t _y_24, kk_context_t* _ctx) { /* (string) -> <exn,fsys> (list<list<list<double>>>, list<list<list<double>>>) */ 
  kk_std_core__list x_2073;
  kk_std_core__list _b_2560_2557;
  kk_vector_t v_21689;
  kk_string_t _x3164;
  kk_define_string_literal(, _s3165, 1, "\n")
  _x3164 = kk_string_dup(_s3165); /*string*/
  v_21689 = kk_string_splitv(_y_24,_x3164,kk_context()); /*vector<string>*/
  _b_2560_2557 = kk_std_core_vlist(v_21689, kk_std_core_types__new_None(_ctx), _ctx); /*list<string>*/
  x_2073 = kk_std_core_map_5(_b_2560_2557, kk_data_preprocessing__new_mlift1967_pre__process__data_fun3166(_ctx), _ctx); /*list<maybe<double>>*/
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_2073, _ctx);
    kk_box_t _x3170 = kk_std_core_hnd_yield_extend(kk_data_preprocessing__new_mlift1967_pre__process__data_fun3171(_ctx), _ctx); /*2*/
    return kk_std_core_types__tuple2__unbox(_x3170, _ctx);
  }
  return kk_data_preprocessing__mlift1966_pre__process__data(x_2073, _ctx);
}


// lift anonymous function
struct kk_data_preprocessing_pre__process__data_fun3177__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing_pre__process__data_fun3177(kk_function_t _fself, kk_box_t _b_2570, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_pre__process__data_fun3177(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing_pre__process__data_fun3177, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_data_preprocessing_pre__process__data_fun3177(kk_function_t _fself, kk_box_t _b_2570, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x3178;
  kk_std_os_path__path _x3179 = kk_std_os_path__path_unbox(_b_2570, _ctx); /*std/os/path/path*/
  _x3178 = kk_std_os_path_string(_x3179, _ctx); /*string*/
  return kk_string_box(_x3178);
}


// lift anonymous function
struct kk_data_preprocessing_pre__process__data_fun3183__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing_pre__process__data_fun3183(kk_function_t _fself, kk_box_t _b_2575, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_pre__process__data_fun3183(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing_pre__process__data_fun3183, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_data_preprocessing_pre__process__data_fun3183(kk_function_t _fself, kk_box_t _b_2575, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core__error _x3184;
  kk_string_t _x3185 = kk_string_unbox(_b_2575); /*string*/
  _x3184 = kk_std_os_file_read_text_file_err(_x3185, _ctx); /*error<string>*/
  return kk_std_core__error_box(_x3184, _ctx);
}


// lift anonymous function
struct kk_data_preprocessing_pre__process__data_fun3192__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing_pre__process__data_fun3192(kk_function_t _fself, kk_box_t _b_2578, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_pre__process__data_fun3192(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing_pre__process__data_fun3192, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_data_preprocessing_pre__process__data_fun3192(kk_function_t _fself, kk_box_t _b_2578, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x3193;
  kk_std_os_path__path _x3194 = kk_std_os_path__path_unbox(_b_2578, _ctx); /*std/os/path/path*/
  _x3193 = kk_std_os_path_show(_x3194, _ctx); /*string*/
  return kk_string_box(_x3193);
}


// lift anonymous function
struct kk_data_preprocessing_pre__process__data_fun3196__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing_pre__process__data_fun3196(kk_function_t _fself, kk_box_t _b_2584, kk_box_t _b_2585, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_pre__process__data_fun3196(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing_pre__process__data_fun3196, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_data_preprocessing_pre__process__data_fun3196(kk_function_t _fself, kk_box_t _b_2584, kk_box_t _b_2585, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core__exception _x3197;
  kk_std_core__exception _x3198 = kk_std_core__exception_unbox(_b_2584, _ctx); /*exception*/
  kk_string_t _x3199 = kk_string_unbox(_b_2585); /*string*/
  _x3197 = kk_std_os_file_prepend(_x3198, _x3199, _ctx); /*exception*/
  return kk_std_core__exception_box(_x3197, _ctx);
}


// lift anonymous function
struct kk_data_preprocessing_pre__process__data_fun3204__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing_pre__process__data_fun3204(kk_function_t _fself, kk_box_t _b_2596, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_pre__process__data_fun3204(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing_pre__process__data_fun3204, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_data_preprocessing_pre__process__data_fun3204(kk_function_t _fself, kk_box_t _b_2596, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core_types__tuple2_ _x3205;
  kk_string_t _x3206 = kk_string_unbox(_b_2596); /*string*/
  _x3205 = kk_data_preprocessing__mlift1967_pre__process__data(_x3206, _ctx); /*(list<list<list<double>>>, list<list<list<double>>>)*/
  return kk_std_core_types__tuple2__box(_x3205, _ctx);
}


// lift anonymous function
struct kk_data_preprocessing_pre__process__data_fun3209__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing_pre__process__data_fun3209(kk_function_t _fself, kk_box_t _b_2602, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_pre__process__data_fun3209(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing_pre__process__data_fun3209, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_data_preprocessing_pre__process__data_fun3210__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing_pre__process__data_fun3210(kk_function_t _fself, kk_box_t _b_2599, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_pre__process__data_fun3210(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing_pre__process__data_fun3210, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_data_preprocessing_pre__process__data_fun3210(kk_function_t _fself, kk_box_t _b_2599, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core_types__maybe _x3211;
  kk_string_t _x3212 = kk_string_unbox(_b_2599); /*string*/
  _x3211 = kk_std_num_double_parse_double(_x3212, _ctx); /*maybe<double>*/
  return kk_std_core_types__maybe_box(_x3211, _ctx);
}
static kk_box_t kk_data_preprocessing_pre__process__data_fun3209(kk_function_t _fself, kk_box_t _b_2602, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return kk_std_core_hnd__open_none1(kk_data_preprocessing_new_pre__process__data_fun3210(_ctx), _b_2602, _ctx);
}


// lift anonymous function
struct kk_data_preprocessing_pre__process__data_fun3214__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing_pre__process__data_fun3214(kk_function_t _fself, kk_box_t _b_2609, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_pre__process__data_fun3214(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing_pre__process__data_fun3214, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_data_preprocessing_pre__process__data_fun3214(kk_function_t _fself, kk_box_t _b_2609, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core_types__tuple2_ _x3215;
  kk_std_core__list _x3216 = kk_std_core__list_unbox(_b_2609, _ctx); /*list<maybe<double>>*/
  _x3215 = kk_data_preprocessing__mlift1966_pre__process__data(_x3216, _ctx); /*(list<list<list<double>>>, list<list<list<double>>>)*/
  return kk_std_core_types__tuple2__box(_x3215, _ctx);
}


// lift anonymous function
struct kk_data_preprocessing_pre__process__data_fun3220__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing_pre__process__data_fun3220(kk_function_t _fself, kk_box_t _b_2612, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_pre__process__data_fun3220(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing_pre__process__data_fun3220, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_data_preprocessing_pre__process__data_fun3220(kk_function_t _fself, kk_box_t _b_2612, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x3221;
  kk_std_os_path__path _x3222 = kk_std_os_path__path_unbox(_b_2612, _ctx); /*std/os/path/path*/
  _x3221 = kk_std_os_path_string(_x3222, _ctx); /*string*/
  return kk_string_box(_x3221);
}


// lift anonymous function
struct kk_data_preprocessing_pre__process__data_fun3226__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing_pre__process__data_fun3226(kk_function_t _fself, kk_box_t _b_2617, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_pre__process__data_fun3226(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing_pre__process__data_fun3226, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_data_preprocessing_pre__process__data_fun3226(kk_function_t _fself, kk_box_t _b_2617, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core__error _x3227;
  kk_string_t _x3228 = kk_string_unbox(_b_2617); /*string*/
  _x3227 = kk_std_os_file_read_text_file_err(_x3228, _ctx); /*error<string>*/
  return kk_std_core__error_box(_x3227, _ctx);
}


// lift anonymous function
struct kk_data_preprocessing_pre__process__data_fun3235__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing_pre__process__data_fun3235(kk_function_t _fself, kk_box_t _b_2620, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_pre__process__data_fun3235(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing_pre__process__data_fun3235, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_data_preprocessing_pre__process__data_fun3235(kk_function_t _fself, kk_box_t _b_2620, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x3236;
  kk_std_os_path__path _x3237 = kk_std_os_path__path_unbox(_b_2620, _ctx); /*std/os/path/path*/
  _x3236 = kk_std_os_path_show(_x3237, _ctx); /*string*/
  return kk_string_box(_x3236);
}


// lift anonymous function
struct kk_data_preprocessing_pre__process__data_fun3239__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing_pre__process__data_fun3239(kk_function_t _fself, kk_box_t _b_2626, kk_box_t _b_2627, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_pre__process__data_fun3239(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing_pre__process__data_fun3239, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_data_preprocessing_pre__process__data_fun3239(kk_function_t _fself, kk_box_t _b_2626, kk_box_t _b_2627, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core__exception _x3240;
  kk_std_core__exception _x3241 = kk_std_core__exception_unbox(_b_2626, _ctx); /*exception*/
  kk_string_t _x3242 = kk_string_unbox(_b_2627); /*string*/
  _x3240 = kk_std_os_file_prepend(_x3241, _x3242, _ctx); /*exception*/
  return kk_std_core__exception_box(_x3240, _ctx);
}


// lift anonymous function
struct kk_data_preprocessing_pre__process__data_fun3247__t {
  struct kk_function_s _base;
  kk_std_core__list x3_2084;
};
static kk_box_t kk_data_preprocessing_pre__process__data_fun3247(kk_function_t _fself, kk_box_t _b_2638, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_pre__process__data_fun3247(kk_std_core__list x3_2084, kk_context_t* _ctx) {
  struct kk_data_preprocessing_pre__process__data_fun3247__t* _self = kk_function_alloc_as(struct kk_data_preprocessing_pre__process__data_fun3247__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_data_preprocessing_pre__process__data_fun3247, kk_context());
  _self->x3_2084 = x3_2084;
  return &_self->_base;
}

static kk_box_t kk_data_preprocessing_pre__process__data_fun3247(kk_function_t _fself, kk_box_t _b_2638, kk_context_t* _ctx) {
  struct kk_data_preprocessing_pre__process__data_fun3247__t* _self = kk_function_as(struct kk_data_preprocessing_pre__process__data_fun3247__t*, _fself);
  kk_std_core__list x3_2084 = _self->x3_2084; /* list<maybe<double>> */
  kk_drop_match(_self, {kk_std_core__list_dup(x3_2084);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x3248;
  kk_string_t _x3249 = kk_string_unbox(_b_2638); /*string*/
  _x3248 = kk_data_preprocessing__mlift1965_pre__process__data(x3_2084, _x3249, _ctx); /*(list<list<list<double>>>, list<list<list<double>>>)*/
  return kk_std_core_types__tuple2__box(_x3248, _ctx);
}


// lift anonymous function
struct kk_data_preprocessing_pre__process__data_fun3252__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing_pre__process__data_fun3252(kk_function_t _fself, kk_box_t _b_2644, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_pre__process__data_fun3252(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing_pre__process__data_fun3252, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_data_preprocessing_pre__process__data_fun3253__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing_pre__process__data_fun3253(kk_function_t _fself, kk_box_t _b_2641, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_pre__process__data_fun3253(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing_pre__process__data_fun3253, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_data_preprocessing_pre__process__data_fun3253(kk_function_t _fself, kk_box_t _b_2641, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core_types__maybe _x3254;
  kk_string_t _x3255 = kk_string_unbox(_b_2641); /*string*/
  _x3254 = kk_std_num_double_parse_double(_x3255, _ctx); /*maybe<double>*/
  return kk_std_core_types__maybe_box(_x3254, _ctx);
}
static kk_box_t kk_data_preprocessing_pre__process__data_fun3252(kk_function_t _fself, kk_box_t _b_2644, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return kk_std_core_hnd__open_none1(kk_data_preprocessing_new_pre__process__data_fun3253(_ctx), _b_2644, _ctx);
}


// lift anonymous function
struct kk_data_preprocessing_pre__process__data_fun3257__t {
  struct kk_function_s _base;
  kk_std_core__list x3_2084;
};
static kk_box_t kk_data_preprocessing_pre__process__data_fun3257(kk_function_t _fself, kk_box_t _b_2651, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_pre__process__data_fun3257(kk_std_core__list x3_2084, kk_context_t* _ctx) {
  struct kk_data_preprocessing_pre__process__data_fun3257__t* _self = kk_function_alloc_as(struct kk_data_preprocessing_pre__process__data_fun3257__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_data_preprocessing_pre__process__data_fun3257, kk_context());
  _self->x3_2084 = x3_2084;
  return &_self->_base;
}

static kk_box_t kk_data_preprocessing_pre__process__data_fun3257(kk_function_t _fself, kk_box_t _b_2651, kk_context_t* _ctx) {
  struct kk_data_preprocessing_pre__process__data_fun3257__t* _self = kk_function_as(struct kk_data_preprocessing_pre__process__data_fun3257__t*, _fself);
  kk_std_core__list x3_2084 = _self->x3_2084; /* list<maybe<double>> */
  kk_drop_match(_self, {kk_std_core__list_dup(x3_2084);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x3258;
  kk_std_core__list _x3259 = kk_std_core__list_unbox(_b_2651, _ctx); /*list<maybe<double>>*/
  _x3258 = kk_data_preprocessing__mlift1964_pre__process__data(x3_2084, _x3259, _ctx); /*(list<list<list<double>>>, list<list<list<double>>>)*/
  return kk_std_core_types__tuple2__box(_x3258, _ctx);
}


// lift anonymous function
struct kk_data_preprocessing_pre__process__data_fun3263__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing_pre__process__data_fun3263(kk_function_t _fself, kk_box_t _b_2654, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_pre__process__data_fun3263(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing_pre__process__data_fun3263, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_data_preprocessing_pre__process__data_fun3263(kk_function_t _fself, kk_box_t _b_2654, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x3264;
  kk_std_os_path__path _x3265 = kk_std_os_path__path_unbox(_b_2654, _ctx); /*std/os/path/path*/
  _x3264 = kk_std_os_path_string(_x3265, _ctx); /*string*/
  return kk_string_box(_x3264);
}


// lift anonymous function
struct kk_data_preprocessing_pre__process__data_fun3269__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing_pre__process__data_fun3269(kk_function_t _fself, kk_box_t _b_2659, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_pre__process__data_fun3269(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing_pre__process__data_fun3269, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_data_preprocessing_pre__process__data_fun3269(kk_function_t _fself, kk_box_t _b_2659, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core__error _x3270;
  kk_string_t _x3271 = kk_string_unbox(_b_2659); /*string*/
  _x3270 = kk_std_os_file_read_text_file_err(_x3271, _ctx); /*error<string>*/
  return kk_std_core__error_box(_x3270, _ctx);
}


// lift anonymous function
struct kk_data_preprocessing_pre__process__data_fun3278__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing_pre__process__data_fun3278(kk_function_t _fself, kk_box_t _b_2662, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_pre__process__data_fun3278(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing_pre__process__data_fun3278, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_data_preprocessing_pre__process__data_fun3278(kk_function_t _fself, kk_box_t _b_2662, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x3279;
  kk_std_os_path__path _x3280 = kk_std_os_path__path_unbox(_b_2662, _ctx); /*std/os/path/path*/
  _x3279 = kk_std_os_path_show(_x3280, _ctx); /*string*/
  return kk_string_box(_x3279);
}


// lift anonymous function
struct kk_data_preprocessing_pre__process__data_fun3282__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing_pre__process__data_fun3282(kk_function_t _fself, kk_box_t _b_2668, kk_box_t _b_2669, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_pre__process__data_fun3282(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing_pre__process__data_fun3282, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_data_preprocessing_pre__process__data_fun3282(kk_function_t _fself, kk_box_t _b_2668, kk_box_t _b_2669, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core__exception _x3283;
  kk_std_core__exception _x3284 = kk_std_core__exception_unbox(_b_2668, _ctx); /*exception*/
  kk_string_t _x3285 = kk_string_unbox(_b_2669); /*string*/
  _x3283 = kk_std_os_file_prepend(_x3284, _x3285, _ctx); /*exception*/
  return kk_std_core__exception_box(_x3283, _ctx);
}


// lift anonymous function
struct kk_data_preprocessing_pre__process__data_fun3290__t {
  struct kk_function_s _base;
  kk_std_core__list x3_2084;
  kk_std_core__list x7_2097;
};
static kk_box_t kk_data_preprocessing_pre__process__data_fun3290(kk_function_t _fself, kk_box_t _b_2680, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_pre__process__data_fun3290(kk_std_core__list x3_2084, kk_std_core__list x7_2097, kk_context_t* _ctx) {
  struct kk_data_preprocessing_pre__process__data_fun3290__t* _self = kk_function_alloc_as(struct kk_data_preprocessing_pre__process__data_fun3290__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_data_preprocessing_pre__process__data_fun3290, kk_context());
  _self->x3_2084 = x3_2084;
  _self->x7_2097 = x7_2097;
  return &_self->_base;
}

static kk_box_t kk_data_preprocessing_pre__process__data_fun3290(kk_function_t _fself, kk_box_t _b_2680, kk_context_t* _ctx) {
  struct kk_data_preprocessing_pre__process__data_fun3290__t* _self = kk_function_as(struct kk_data_preprocessing_pre__process__data_fun3290__t*, _fself);
  kk_std_core__list x3_2084 = _self->x3_2084; /* list<maybe<double>> */
  kk_std_core__list x7_2097 = _self->x7_2097; /* list<maybe<double>> */
  kk_drop_match(_self, {kk_std_core__list_dup(x3_2084);kk_std_core__list_dup(x7_2097);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x3291;
  kk_string_t _x3292 = kk_string_unbox(_b_2680); /*string*/
  _x3291 = kk_data_preprocessing__mlift1963_pre__process__data(x3_2084, x7_2097, _x3292, _ctx); /*(list<list<list<double>>>, list<list<list<double>>>)*/
  return kk_std_core_types__tuple2__box(_x3291, _ctx);
}


// lift anonymous function
struct kk_data_preprocessing_pre__process__data_fun3295__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing_pre__process__data_fun3295(kk_function_t _fself, kk_box_t _b_2686, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_pre__process__data_fun3295(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing_pre__process__data_fun3295, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_data_preprocessing_pre__process__data_fun3296__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing_pre__process__data_fun3296(kk_function_t _fself, kk_box_t _b_2683, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_pre__process__data_fun3296(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing_pre__process__data_fun3296, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_data_preprocessing_pre__process__data_fun3296(kk_function_t _fself, kk_box_t _b_2683, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core_types__maybe _x3297;
  kk_string_t _x3298 = kk_string_unbox(_b_2683); /*string*/
  _x3297 = kk_std_num_double_parse_double(_x3298, _ctx); /*maybe<double>*/
  return kk_std_core_types__maybe_box(_x3297, _ctx);
}
static kk_box_t kk_data_preprocessing_pre__process__data_fun3295(kk_function_t _fself, kk_box_t _b_2686, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return kk_std_core_hnd__open_none1(kk_data_preprocessing_new_pre__process__data_fun3296(_ctx), _b_2686, _ctx);
}


// lift anonymous function
struct kk_data_preprocessing_pre__process__data_fun3300__t {
  struct kk_function_s _base;
  kk_std_core__list x3_2084;
  kk_std_core__list x7_2097;
};
static kk_box_t kk_data_preprocessing_pre__process__data_fun3300(kk_function_t _fself, kk_box_t _b_2693, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_pre__process__data_fun3300(kk_std_core__list x3_2084, kk_std_core__list x7_2097, kk_context_t* _ctx) {
  struct kk_data_preprocessing_pre__process__data_fun3300__t* _self = kk_function_alloc_as(struct kk_data_preprocessing_pre__process__data_fun3300__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_data_preprocessing_pre__process__data_fun3300, kk_context());
  _self->x3_2084 = x3_2084;
  _self->x7_2097 = x7_2097;
  return &_self->_base;
}

static kk_box_t kk_data_preprocessing_pre__process__data_fun3300(kk_function_t _fself, kk_box_t _b_2693, kk_context_t* _ctx) {
  struct kk_data_preprocessing_pre__process__data_fun3300__t* _self = kk_function_as(struct kk_data_preprocessing_pre__process__data_fun3300__t*, _fself);
  kk_std_core__list x3_2084 = _self->x3_2084; /* list<maybe<double>> */
  kk_std_core__list x7_2097 = _self->x7_2097; /* list<maybe<double>> */
  kk_drop_match(_self, {kk_std_core__list_dup(x3_2084);kk_std_core__list_dup(x7_2097);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x3301;
  kk_std_core__list _x3302 = kk_std_core__list_unbox(_b_2693, _ctx); /*list<maybe<double>>*/
  _x3301 = kk_data_preprocessing__mlift1962_pre__process__data(x3_2084, x7_2097, _x3302, _ctx); /*(list<list<list<double>>>, list<list<list<double>>>)*/
  return kk_std_core_types__tuple2__box(_x3301, _ctx);
}


// lift anonymous function
struct kk_data_preprocessing_pre__process__data_fun3306__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing_pre__process__data_fun3306(kk_function_t _fself, kk_box_t _b_2696, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_pre__process__data_fun3306(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing_pre__process__data_fun3306, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_data_preprocessing_pre__process__data_fun3306(kk_function_t _fself, kk_box_t _b_2696, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x3307;
  kk_std_os_path__path _x3308 = kk_std_os_path__path_unbox(_b_2696, _ctx); /*std/os/path/path*/
  _x3307 = kk_std_os_path_string(_x3308, _ctx); /*string*/
  return kk_string_box(_x3307);
}


// lift anonymous function
struct kk_data_preprocessing_pre__process__data_fun3312__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing_pre__process__data_fun3312(kk_function_t _fself, kk_box_t _b_2701, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_pre__process__data_fun3312(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing_pre__process__data_fun3312, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_data_preprocessing_pre__process__data_fun3312(kk_function_t _fself, kk_box_t _b_2701, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core__error _x3313;
  kk_string_t _x3314 = kk_string_unbox(_b_2701); /*string*/
  _x3313 = kk_std_os_file_read_text_file_err(_x3314, _ctx); /*error<string>*/
  return kk_std_core__error_box(_x3313, _ctx);
}


// lift anonymous function
struct kk_data_preprocessing_pre__process__data_fun3321__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing_pre__process__data_fun3321(kk_function_t _fself, kk_box_t _b_2704, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_pre__process__data_fun3321(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing_pre__process__data_fun3321, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_data_preprocessing_pre__process__data_fun3321(kk_function_t _fself, kk_box_t _b_2704, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x3322;
  kk_std_os_path__path _x3323 = kk_std_os_path__path_unbox(_b_2704, _ctx); /*std/os/path/path*/
  _x3322 = kk_std_os_path_show(_x3323, _ctx); /*string*/
  return kk_string_box(_x3322);
}


// lift anonymous function
struct kk_data_preprocessing_pre__process__data_fun3325__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing_pre__process__data_fun3325(kk_function_t _fself, kk_box_t _b_2710, kk_box_t _b_2711, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_pre__process__data_fun3325(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing_pre__process__data_fun3325, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_data_preprocessing_pre__process__data_fun3325(kk_function_t _fself, kk_box_t _b_2710, kk_box_t _b_2711, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core__exception _x3326;
  kk_std_core__exception _x3327 = kk_std_core__exception_unbox(_b_2710, _ctx); /*exception*/
  kk_string_t _x3328 = kk_string_unbox(_b_2711); /*string*/
  _x3326 = kk_std_os_file_prepend(_x3327, _x3328, _ctx); /*exception*/
  return kk_std_core__exception_box(_x3326, _ctx);
}


// lift anonymous function
struct kk_data_preprocessing_pre__process__data_fun3333__t {
  struct kk_function_s _base;
  kk_std_core__list x13_2110;
  kk_std_core__list x3_2084;
  kk_std_core__list x7_2097;
};
static kk_box_t kk_data_preprocessing_pre__process__data_fun3333(kk_function_t _fself, kk_box_t _b_2722, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_pre__process__data_fun3333(kk_std_core__list x13_2110, kk_std_core__list x3_2084, kk_std_core__list x7_2097, kk_context_t* _ctx) {
  struct kk_data_preprocessing_pre__process__data_fun3333__t* _self = kk_function_alloc_as(struct kk_data_preprocessing_pre__process__data_fun3333__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_data_preprocessing_pre__process__data_fun3333, kk_context());
  _self->x13_2110 = x13_2110;
  _self->x3_2084 = x3_2084;
  _self->x7_2097 = x7_2097;
  return &_self->_base;
}

static kk_box_t kk_data_preprocessing_pre__process__data_fun3333(kk_function_t _fself, kk_box_t _b_2722, kk_context_t* _ctx) {
  struct kk_data_preprocessing_pre__process__data_fun3333__t* _self = kk_function_as(struct kk_data_preprocessing_pre__process__data_fun3333__t*, _fself);
  kk_std_core__list x13_2110 = _self->x13_2110; /* list<maybe<double>> */
  kk_std_core__list x3_2084 = _self->x3_2084; /* list<maybe<double>> */
  kk_std_core__list x7_2097 = _self->x7_2097; /* list<maybe<double>> */
  kk_drop_match(_self, {kk_std_core__list_dup(x13_2110);kk_std_core__list_dup(x3_2084);kk_std_core__list_dup(x7_2097);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x3334;
  kk_string_t _x3335 = kk_string_unbox(_b_2722); /*string*/
  _x3334 = kk_data_preprocessing__mlift1961_pre__process__data(x13_2110, x3_2084, x7_2097, _x3335, _ctx); /*(list<list<list<double>>>, list<list<list<double>>>)*/
  return kk_std_core_types__tuple2__box(_x3334, _ctx);
}


// lift anonymous function
struct kk_data_preprocessing_pre__process__data_fun3338__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing_pre__process__data_fun3338(kk_function_t _fself, kk_box_t _b_2728, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_pre__process__data_fun3338(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing_pre__process__data_fun3338, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_data_preprocessing_pre__process__data_fun3339__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing_pre__process__data_fun3339(kk_function_t _fself, kk_box_t _b_2725, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_pre__process__data_fun3339(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing_pre__process__data_fun3339, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_data_preprocessing_pre__process__data_fun3339(kk_function_t _fself, kk_box_t _b_2725, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core_types__maybe _x3340;
  kk_string_t _x3341 = kk_string_unbox(_b_2725); /*string*/
  _x3340 = kk_std_num_double_parse_double(_x3341, _ctx); /*maybe<double>*/
  return kk_std_core_types__maybe_box(_x3340, _ctx);
}
static kk_box_t kk_data_preprocessing_pre__process__data_fun3338(kk_function_t _fself, kk_box_t _b_2728, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return kk_std_core_hnd__open_none1(kk_data_preprocessing_new_pre__process__data_fun3339(_ctx), _b_2728, _ctx);
}


// lift anonymous function
struct kk_data_preprocessing_pre__process__data_fun3343__t {
  struct kk_function_s _base;
  kk_std_core__list x13_2110;
  kk_std_core__list x3_2084;
  kk_std_core__list x7_2097;
};
static kk_box_t kk_data_preprocessing_pre__process__data_fun3343(kk_function_t _fself, kk_box_t _b_2735, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_pre__process__data_fun3343(kk_std_core__list x13_2110, kk_std_core__list x3_2084, kk_std_core__list x7_2097, kk_context_t* _ctx) {
  struct kk_data_preprocessing_pre__process__data_fun3343__t* _self = kk_function_alloc_as(struct kk_data_preprocessing_pre__process__data_fun3343__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_data_preprocessing_pre__process__data_fun3343, kk_context());
  _self->x13_2110 = x13_2110;
  _self->x3_2084 = x3_2084;
  _self->x7_2097 = x7_2097;
  return &_self->_base;
}

static kk_box_t kk_data_preprocessing_pre__process__data_fun3343(kk_function_t _fself, kk_box_t _b_2735, kk_context_t* _ctx) {
  struct kk_data_preprocessing_pre__process__data_fun3343__t* _self = kk_function_as(struct kk_data_preprocessing_pre__process__data_fun3343__t*, _fself);
  kk_std_core__list x13_2110 = _self->x13_2110; /* list<maybe<double>> */
  kk_std_core__list x3_2084 = _self->x3_2084; /* list<maybe<double>> */
  kk_std_core__list x7_2097 = _self->x7_2097; /* list<maybe<double>> */
  kk_drop_match(_self, {kk_std_core__list_dup(x13_2110);kk_std_core__list_dup(x3_2084);kk_std_core__list_dup(x7_2097);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x3344;
  kk_std_core__list _x3345 = kk_std_core__list_unbox(_b_2735, _ctx); /*list<maybe<double>>*/
  _x3344 = kk_data_preprocessing__mlift1960_pre__process__data(x13_2110, x3_2084, x7_2097, _x3345, _ctx); /*(list<list<list<double>>>, list<list<list<double>>>)*/
  return kk_std_core_types__tuple2__box(_x3344, _ctx);
}


// lift anonymous function
struct kk_data_preprocessing_pre__process__data_fun3347__t {
  struct kk_function_s _base;
  kk_std_core__list maybe__temperatures;
};
static kk_box_t kk_data_preprocessing_pre__process__data_fun3347(kk_function_t _fself, kk_box_t _b_2753, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_pre__process__data_fun3347(kk_std_core__list maybe__temperatures, kk_context_t* _ctx) {
  struct kk_data_preprocessing_pre__process__data_fun3347__t* _self = kk_function_alloc_as(struct kk_data_preprocessing_pre__process__data_fun3347__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_data_preprocessing_pre__process__data_fun3347, kk_context());
  _self->maybe__temperatures = maybe__temperatures;
  return &_self->_base;
}

static kk_box_t kk_data_preprocessing_pre__process__data_fun3347(kk_function_t _fself, kk_box_t _b_2753, kk_context_t* _ctx) {
  struct kk_data_preprocessing_pre__process__data_fun3347__t* _self = kk_function_as(struct kk_data_preprocessing_pre__process__data_fun3347__t*, _fself);
  kk_std_core__list maybe__temperatures = _self->maybe__temperatures; /* list<maybe<double>> */
  kk_drop_match(_self, {kk_std_core__list_dup(maybe__temperatures);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x3348;
  kk_std_core__list _x3349 = kk_std_core__list_unbox(_b_2753, _ctx); /*list<double>*/
  _x3348 = kk_data_preprocessing__mlift1959_pre__process__data(maybe__temperatures, _x3349, _ctx); /*(list<list<list<double>>>, list<list<list<double>>>)*/
  return kk_std_core_types__tuple2__box(_x3348, _ctx);
}


// lift anonymous function
struct kk_data_preprocessing_pre__process__data_fun3351__t {
  struct kk_function_s _base;
  kk_std_core__list x19_2131;
};
static kk_box_t kk_data_preprocessing_pre__process__data_fun3351(kk_function_t _fself, kk_box_t _b_2755, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_pre__process__data_fun3351(kk_std_core__list x19_2131, kk_context_t* _ctx) {
  struct kk_data_preprocessing_pre__process__data_fun3351__t* _self = kk_function_alloc_as(struct kk_data_preprocessing_pre__process__data_fun3351__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_data_preprocessing_pre__process__data_fun3351, kk_context());
  _self->x19_2131 = x19_2131;
  return &_self->_base;
}

static kk_box_t kk_data_preprocessing_pre__process__data_fun3351(kk_function_t _fself, kk_box_t _b_2755, kk_context_t* _ctx) {
  struct kk_data_preprocessing_pre__process__data_fun3351__t* _self = kk_function_as(struct kk_data_preprocessing_pre__process__data_fun3351__t*, _fself);
  kk_std_core__list x19_2131 = _self->x19_2131; /* list<double> */
  kk_drop_match(_self, {kk_std_core__list_dup(x19_2131);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x3352;
  kk_std_core__list _x3353 = kk_std_core__list_unbox(_b_2755, _ctx); /*list<double>*/
  _x3352 = kk_data_preprocessing__mlift1958_pre__process__data(x19_2131, _x3353, _ctx); /*(list<list<list<double>>>, list<list<list<double>>>)*/
  return kk_std_core_types__tuple2__box(_x3352, _ctx);
}


// lift anonymous function
struct kk_data_preprocessing_pre__process__data_fun3355__t {
  struct kk_function_s _base;
  kk_std_core__list temperatures__by__year;
};
static kk_box_t kk_data_preprocessing_pre__process__data_fun3355(kk_function_t _fself, kk_box_t _b_2757, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_pre__process__data_fun3355(kk_std_core__list temperatures__by__year, kk_context_t* _ctx) {
  struct kk_data_preprocessing_pre__process__data_fun3355__t* _self = kk_function_alloc_as(struct kk_data_preprocessing_pre__process__data_fun3355__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_data_preprocessing_pre__process__data_fun3355, kk_context());
  _self->temperatures__by__year = temperatures__by__year;
  return &_self->_base;
}

static kk_box_t kk_data_preprocessing_pre__process__data_fun3355(kk_function_t _fself, kk_box_t _b_2757, kk_context_t* _ctx) {
  struct kk_data_preprocessing_pre__process__data_fun3355__t* _self = kk_function_as(struct kk_data_preprocessing_pre__process__data_fun3355__t*, _fself);
  kk_std_core__list temperatures__by__year = _self->temperatures__by__year; /* list<list<double>> */
  kk_drop_match(_self, {kk_std_core__list_dup(temperatures__by__year);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x3356;
  kk_std_core__list _x3357 = kk_std_core__list_unbox(_b_2757, _ctx); /*list<list<double>>*/
  _x3356 = kk_data_preprocessing__mlift1957_pre__process__data(temperatures__by__year, _x3357, _ctx); /*(list<list<list<double>>>, list<list<list<double>>>)*/
  return kk_std_core_types__tuple2__box(_x3356, _ctx);
}


// lift anonymous function
struct kk_data_preprocessing_pre__process__data_fun3359__t {
  struct kk_function_s _base;
  kk_std_core__list x25_2145;
};
static kk_box_t kk_data_preprocessing_pre__process__data_fun3359(kk_function_t _fself, kk_box_t _b_2759, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_pre__process__data_fun3359(kk_std_core__list x25_2145, kk_context_t* _ctx) {
  struct kk_data_preprocessing_pre__process__data_fun3359__t* _self = kk_function_alloc_as(struct kk_data_preprocessing_pre__process__data_fun3359__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_data_preprocessing_pre__process__data_fun3359, kk_context());
  _self->x25_2145 = x25_2145;
  return &_self->_base;
}

static kk_box_t kk_data_preprocessing_pre__process__data_fun3359(kk_function_t _fself, kk_box_t _b_2759, kk_context_t* _ctx) {
  struct kk_data_preprocessing_pre__process__data_fun3359__t* _self = kk_function_as(struct kk_data_preprocessing_pre__process__data_fun3359__t*, _fself);
  kk_std_core__list x25_2145 = _self->x25_2145; /* list<list<double>> */
  kk_drop_match(_self, {kk_std_core__list_dup(x25_2145);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x3360;
  kk_std_core__list _x3361 = kk_std_core__list_unbox(_b_2759, _ctx); /*list<list<double>>*/
  _x3360 = kk_data_preprocessing__mlift1956_pre__process__data(x25_2145, _x3361, _ctx); /*(list<list<list<double>>>, list<list<list<double>>>)*/
  return kk_std_core_types__tuple2__box(_x3360, _ctx);
}


// lift anonymous function
struct kk_data_preprocessing_pre__process__data_fun3362__t {
  struct kk_function_s _base;
  kk_function_t _b_2764_2761;
};
static kk_box_t kk_data_preprocessing_pre__process__data_fun3362(kk_function_t _fself, kk_box_t _b_2762, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_pre__process__data_fun3362(kk_function_t _b_2764_2761, kk_context_t* _ctx) {
  struct kk_data_preprocessing_pre__process__data_fun3362__t* _self = kk_function_alloc_as(struct kk_data_preprocessing_pre__process__data_fun3362__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_data_preprocessing_pre__process__data_fun3362, kk_context());
  _self->_b_2764_2761 = _b_2764_2761;
  return &_self->_base;
}

static kk_box_t kk_data_preprocessing_pre__process__data_fun3362(kk_function_t _fself, kk_box_t _b_2762, kk_context_t* _ctx) {
  struct kk_data_preprocessing_pre__process__data_fun3362__t* _self = kk_function_as(struct kk_data_preprocessing_pre__process__data_fun3362__t*, _fself);
  kk_function_t _b_2764_2761 = _self->_b_2764_2761; /* (list : list<double>) -> div list<list<double>> */
  kk_drop_match(_self, {kk_function_dup(_b_2764_2761);}, {}, _ctx)
  kk_std_core__list _x3363;
  kk_std_core__list _x3364 = kk_std_core__list_unbox(_b_2762, _ctx); /*list<double>*/
  _x3363 = kk_function_call(kk_std_core__list, (kk_function_t, kk_std_core__list, kk_context_t*), _b_2764_2761, (_b_2764_2761, _x3364, _ctx)); /*list<list<double>>*/
  return kk_std_core__list_box(_x3363, _ctx);
}


// lift anonymous function
struct kk_data_preprocessing_pre__process__data_fun3365__t {
  struct kk_function_s _base;
  kk_function_t _b_2769_2766;
};
static kk_box_t kk_data_preprocessing_pre__process__data_fun3365(kk_function_t _fself, kk_box_t _b_2767, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_pre__process__data_fun3365(kk_function_t _b_2769_2766, kk_context_t* _ctx) {
  struct kk_data_preprocessing_pre__process__data_fun3365__t* _self = kk_function_alloc_as(struct kk_data_preprocessing_pre__process__data_fun3365__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_data_preprocessing_pre__process__data_fun3365, kk_context());
  _self->_b_2769_2766 = _b_2769_2766;
  return &_self->_base;
}

static kk_box_t kk_data_preprocessing_pre__process__data_fun3365(kk_function_t _fself, kk_box_t _b_2767, kk_context_t* _ctx) {
  struct kk_data_preprocessing_pre__process__data_fun3365__t* _self = kk_function_as(struct kk_data_preprocessing_pre__process__data_fun3365__t*, _fself);
  kk_function_t _b_2769_2766 = _self->_b_2769_2766; /* (list : list<double>) -> div list<list<double>> */
  kk_drop_match(_self, {kk_function_dup(_b_2769_2766);}, {}, _ctx)
  kk_std_core__list _x3366;
  kk_std_core__list _x3367 = kk_std_core__list_unbox(_b_2767, _ctx); /*list<double>*/
  _x3366 = kk_function_call(kk_std_core__list, (kk_function_t, kk_std_core__list, kk_context_t*), _b_2769_2766, (_b_2769_2766, _x3367, _ctx)); /*list<list<double>>*/
  return kk_std_core__list_box(_x3366, _ctx);
}

kk_std_core_types__tuple2_ kk_data_preprocessing_pre__process__data(kk_context_t* _ctx) { /* () -> <pure,fsys> (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>) */ 
  kk_string_t x_2077;
  kk_std_os_path__path path_2080;
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*std/core/hnd/evv<(<>)>*/;
  kk_std_os_path__path x2;
  kk_string_t _x3174;
  kk_define_string_literal(, _s3175, 37, "./data/measurement-uncertainties1.txt")
  _x3174 = kk_string_dup(_s3175); /*string*/
  x2 = kk_std_os_path_path(_x3174, _ctx); /*std/os/path/path*/
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  path_2080 = x2; /*std/os/path/path*/
  kk_std_core__error _match_2820;
  kk_string_t _x1;
  kk_box_t _x3176;
  kk_box_t _x3180;
  kk_std_os_path__path _x3181 = kk_std_os_path__path_dup(path_2080); /*std/os/path/path*/
  _x3180 = kk_std_os_path__path_box(_x3181, _ctx); /*1*/
  _x3176 = kk_std_core_hnd__open_none1(kk_data_preprocessing_new_pre__process__data_fun3177(_ctx), _x3180, _ctx); /*2*/
  _x1 = kk_string_unbox(_x3176); /*string*/
  kk_box_t _x3182 = kk_std_core_hnd__open_none1(kk_data_preprocessing_new_pre__process__data_fun3183(_ctx), kk_string_box(_x1), _ctx); /*2*/
  _match_2820 = kk_std_core__error_unbox(_x3182, _ctx); /*error<string>*/
  if (kk_std_core__is_Error(_match_2820)) {
    kk_std_core__exception exn = _match_2820._cons.Error.exception;
    kk_std_core__exception_dup(exn);
    kk_std_core__error_drop(_match_2820, _ctx);
    kk_std_core__error err_479;
    kk_std_core__exception _x3187;
    kk_string_t _x2;
    kk_string_t _x3188;
    kk_define_string_literal(, _s3189, 25, "unable to read text file ")
    _x3188 = kk_string_dup(_s3189); /*string*/
    kk_string_t _x3190;
    kk_box_t _x3191 = kk_std_core_hnd__open_none1(kk_data_preprocessing_new_pre__process__data_fun3192(_ctx), kk_std_os_path__path_box(path_2080, _ctx), _ctx); /*2*/
    _x3190 = kk_string_unbox(_x3191); /*string*/
    _x2 = kk_std_core__lp__plus__plus__1_rp_(_x3188, _x3190, _ctx); /*string*/
    kk_box_t _x3195 = kk_std_core_hnd__open_none2(kk_data_preprocessing_new_pre__process__data_fun3196(_ctx), kk_std_core__exception_box(exn, _ctx), kk_string_box(_x2), _ctx); /*3*/
    _x3187 = kk_std_core__exception_unbox(_x3195, _ctx); /*exception*/
    err_479 = kk_std_core__new_Error(_x3187, _ctx); /*error<string>*/
    if (kk_std_core__is_Error(err_479)) {
      kk_std_core__exception exn0 = err_479._cons.Error.exception;
      kk_std_core__exception_dup(exn0);
      kk_std_core__error_drop(err_479, _ctx);
      kk_box_t _x3200 = kk_std_core_throw_exn(exn0, _ctx); /*1*/
      x_2077 = kk_string_unbox(_x3200); /*string*/
      goto _match3186;
    }
    kk_box_t _box_x2590 = err_479._cons.Ok.result;
    kk_string_t x0 = kk_string_unbox(_box_x2590);
    kk_string_dup(x0);
    kk_std_core__error_drop(err_479, _ctx);
    x_2077 = x0; /*string*/
    goto _match3186;
  }
  kk_box_t _box_x2591 = _match_2820._cons.Ok.result;
  kk_string_t content = kk_string_unbox(_box_x2591);
  kk_std_os_path__path_drop(path_2080, _ctx);
  kk_string_dup(content);
  kk_std_core__error_drop(_match_2820, _ctx);
  x_2077 = content; /*string*/
  _match3186: ;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_2077, _ctx);
    kk_box_t _x3203 = kk_std_core_hnd_yield_extend(kk_data_preprocessing_new_pre__process__data_fun3204(_ctx), _ctx); /*2*/
    return kk_std_core_types__tuple2__unbox(_x3203, _ctx);
  }
  kk_std_core__list x3_2084;
  kk_std_core__list _b_2603_2600;
  kk_vector_t v_21689;
  kk_string_t _x3207;
  kk_define_string_literal(, _s3208, 1, "\n")
  _x3207 = kk_string_dup(_s3208); /*string*/
  v_21689 = kk_string_splitv(x_2077,_x3207,kk_context()); /*vector<string>*/
  _b_2603_2600 = kk_std_core_vlist(v_21689, kk_std_core_types__new_None(_ctx), _ctx); /*list<string>*/
  x3_2084 = kk_std_core_map_5(_b_2603_2600, kk_data_preprocessing_new_pre__process__data_fun3209(_ctx), _ctx); /*list<maybe<double>>*/
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x3_2084, _ctx);
    kk_box_t _x3213 = kk_std_core_hnd_yield_extend(kk_data_preprocessing_new_pre__process__data_fun3214(_ctx), _ctx); /*2*/
    return kk_std_core_types__tuple2__unbox(_x3213, _ctx);
  }
  kk_string_t x4_2090;
  kk_std_os_path__path path0_2093;
  kk_evv_t w0 = kk_evv_swap_create0(kk_context()); /*std/core/hnd/evv<(<>)>*/;
  kk_std_os_path__path x6;
  kk_string_t _x3217;
  kk_define_string_literal(, _s3218, 37, "./data/measurement-uncertainties2.txt")
  _x3217 = kk_string_dup(_s3218); /*string*/
  x6 = kk_std_os_path_path(_x3217, _ctx); /*std/os/path/path*/
  kk_unit_t keep0 = kk_Unit;
  kk_evv_set(w0,kk_context());
  path0_2093 = x6; /*std/os/path/path*/
  kk_std_core__error _match_2819;
  kk_string_t _x11;
  kk_box_t _x3219;
  kk_box_t _x3223;
  kk_std_os_path__path _x3224 = kk_std_os_path__path_dup(path0_2093); /*std/os/path/path*/
  _x3223 = kk_std_os_path__path_box(_x3224, _ctx); /*1*/
  _x3219 = kk_std_core_hnd__open_none1(kk_data_preprocessing_new_pre__process__data_fun3220(_ctx), _x3223, _ctx); /*2*/
  _x11 = kk_string_unbox(_x3219); /*string*/
  kk_box_t _x3225 = kk_std_core_hnd__open_none1(kk_data_preprocessing_new_pre__process__data_fun3226(_ctx), kk_string_box(_x11), _ctx); /*2*/
  _match_2819 = kk_std_core__error_unbox(_x3225, _ctx); /*error<string>*/
  if (kk_std_core__is_Error(_match_2819)) {
    kk_std_core__exception exn1 = _match_2819._cons.Error.exception;
    kk_std_core__exception_dup(exn1);
    kk_std_core__error_drop(_match_2819, _ctx);
    kk_std_core__error err_4790;
    kk_std_core__exception _x3230;
    kk_string_t _x20;
    kk_string_t _x3231;
    kk_define_string_literal(, _s3232, 25, "unable to read text file ")
    _x3231 = kk_string_dup(_s3232); /*string*/
    kk_string_t _x3233;
    kk_box_t _x3234 = kk_std_core_hnd__open_none1(kk_data_preprocessing_new_pre__process__data_fun3235(_ctx), kk_std_os_path__path_box(path0_2093, _ctx), _ctx); /*2*/
    _x3233 = kk_string_unbox(_x3234); /*string*/
    _x20 = kk_std_core__lp__plus__plus__1_rp_(_x3231, _x3233, _ctx); /*string*/
    kk_box_t _x3238 = kk_std_core_hnd__open_none2(kk_data_preprocessing_new_pre__process__data_fun3239(_ctx), kk_std_core__exception_box(exn1, _ctx), kk_string_box(_x20), _ctx); /*3*/
    _x3230 = kk_std_core__exception_unbox(_x3238, _ctx); /*exception*/
    err_4790 = kk_std_core__new_Error(_x3230, _ctx); /*error<string>*/
    if (kk_std_core__is_Error(err_4790)) {
      kk_std_core__exception exn00 = err_4790._cons.Error.exception;
      kk_std_core__exception_dup(exn00);
      kk_std_core__error_drop(err_4790, _ctx);
      kk_box_t _x3243 = kk_std_core_throw_exn(exn00, _ctx); /*1*/
      x4_2090 = kk_string_unbox(_x3243); /*string*/
      goto _match3229;
    }
    kk_box_t _box_x2632 = err_4790._cons.Ok.result;
    kk_string_t x5 = kk_string_unbox(_box_x2632);
    kk_string_dup(x5);
    kk_std_core__error_drop(err_4790, _ctx);
    x4_2090 = x5; /*string*/
    goto _match3229;
  }
  kk_box_t _box_x2633 = _match_2819._cons.Ok.result;
  kk_string_t content0 = kk_string_unbox(_box_x2633);
  kk_std_os_path__path_drop(path0_2093, _ctx);
  kk_string_dup(content0);
  kk_std_core__error_drop(_match_2819, _ctx);
  x4_2090 = content0; /*string*/
  _match3229: ;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x4_2090, _ctx);
    kk_box_t _x3246 = kk_std_core_hnd_yield_extend(kk_data_preprocessing_new_pre__process__data_fun3247(x3_2084, _ctx), _ctx); /*2*/
    return kk_std_core_types__tuple2__unbox(_x3246, _ctx);
  }
  kk_std_core__list x7_2097;
  kk_std_core__list _b_2645_2642;
  kk_vector_t v_216890;
  kk_string_t _x3250;
  kk_define_string_literal(, _s3251, 1, "\n")
  _x3250 = kk_string_dup(_s3251); /*string*/
  v_216890 = kk_string_splitv(x4_2090,_x3250,kk_context()); /*vector<string>*/
  _b_2645_2642 = kk_std_core_vlist(v_216890, kk_std_core_types__new_None(_ctx), _ctx); /*list<string>*/
  x7_2097 = kk_std_core_map_5(_b_2645_2642, kk_data_preprocessing_new_pre__process__data_fun3252(_ctx), _ctx); /*list<maybe<double>>*/
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x7_2097, _ctx);
    kk_box_t _x3256 = kk_std_core_hnd_yield_extend(kk_data_preprocessing_new_pre__process__data_fun3257(x3_2084, _ctx), _ctx); /*2*/
    return kk_std_core_types__tuple2__unbox(_x3256, _ctx);
  }
  kk_string_t x8_2103;
  kk_std_os_path__path path1_2106;
  kk_evv_t w1 = kk_evv_swap_create0(kk_context()); /*std/core/hnd/evv<(<>)>*/;
  kk_std_os_path__path x12;
  kk_string_t _x3260;
  kk_define_string_literal(, _s3261, 32, "./data/temperature-readings1.txt")
  _x3260 = kk_string_dup(_s3261); /*string*/
  x12 = kk_std_os_path_path(_x3260, _ctx); /*std/os/path/path*/
  kk_unit_t keep1 = kk_Unit;
  kk_evv_set(w1,kk_context());
  path1_2106 = x12; /*std/os/path/path*/
  kk_std_core__error _match_2818;
  kk_string_t _x13;
  kk_box_t _x3262;
  kk_box_t _x3266;
  kk_std_os_path__path _x3267 = kk_std_os_path__path_dup(path1_2106); /*std/os/path/path*/
  _x3266 = kk_std_os_path__path_box(_x3267, _ctx); /*1*/
  _x3262 = kk_std_core_hnd__open_none1(kk_data_preprocessing_new_pre__process__data_fun3263(_ctx), _x3266, _ctx); /*2*/
  _x13 = kk_string_unbox(_x3262); /*string*/
  kk_box_t _x3268 = kk_std_core_hnd__open_none1(kk_data_preprocessing_new_pre__process__data_fun3269(_ctx), kk_string_box(_x13), _ctx); /*2*/
  _match_2818 = kk_std_core__error_unbox(_x3268, _ctx); /*error<string>*/
  if (kk_std_core__is_Error(_match_2818)) {
    kk_std_core__exception exn2 = _match_2818._cons.Error.exception;
    kk_std_core__exception_dup(exn2);
    kk_std_core__error_drop(_match_2818, _ctx);
    kk_std_core__error err_4791;
    kk_std_core__exception _x3273;
    kk_string_t _x21;
    kk_string_t _x3274;
    kk_define_string_literal(, _s3275, 25, "unable to read text file ")
    _x3274 = kk_string_dup(_s3275); /*string*/
    kk_string_t _x3276;
    kk_box_t _x3277 = kk_std_core_hnd__open_none1(kk_data_preprocessing_new_pre__process__data_fun3278(_ctx), kk_std_os_path__path_box(path1_2106, _ctx), _ctx); /*2*/
    _x3276 = kk_string_unbox(_x3277); /*string*/
    _x21 = kk_std_core__lp__plus__plus__1_rp_(_x3274, _x3276, _ctx); /*string*/
    kk_box_t _x3281 = kk_std_core_hnd__open_none2(kk_data_preprocessing_new_pre__process__data_fun3282(_ctx), kk_std_core__exception_box(exn2, _ctx), kk_string_box(_x21), _ctx); /*3*/
    _x3273 = kk_std_core__exception_unbox(_x3281, _ctx); /*exception*/
    err_4791 = kk_std_core__new_Error(_x3273, _ctx); /*error<string>*/
    if (kk_std_core__is_Error(err_4791)) {
      kk_std_core__exception exn01 = err_4791._cons.Error.exception;
      kk_std_core__exception_dup(exn01);
      kk_std_core__error_drop(err_4791, _ctx);
      kk_box_t _x3286 = kk_std_core_throw_exn(exn01, _ctx); /*1*/
      x8_2103 = kk_string_unbox(_x3286); /*string*/
      goto _match3272;
    }
    kk_box_t _box_x2674 = err_4791._cons.Ok.result;
    kk_string_t x9 = kk_string_unbox(_box_x2674);
    kk_string_dup(x9);
    kk_std_core__error_drop(err_4791, _ctx);
    x8_2103 = x9; /*string*/
    goto _match3272;
  }
  kk_box_t _box_x2675 = _match_2818._cons.Ok.result;
  kk_string_t content1 = kk_string_unbox(_box_x2675);
  kk_std_os_path__path_drop(path1_2106, _ctx);
  kk_string_dup(content1);
  kk_std_core__error_drop(_match_2818, _ctx);
  x8_2103 = content1; /*string*/
  _match3272: ;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x8_2103, _ctx);
    kk_box_t _x3289 = kk_std_core_hnd_yield_extend(kk_data_preprocessing_new_pre__process__data_fun3290(x3_2084, x7_2097, _ctx), _ctx); /*2*/
    return kk_std_core_types__tuple2__unbox(_x3289, _ctx);
  }
  kk_std_core__list x13_2110;
  kk_std_core__list _b_2687_2684;
  kk_vector_t v_216891;
  kk_string_t _x3293;
  kk_define_string_literal(, _s3294, 1, "\n")
  _x3293 = kk_string_dup(_s3294); /*string*/
  v_216891 = kk_string_splitv(x8_2103,_x3293,kk_context()); /*vector<string>*/
  _b_2687_2684 = kk_std_core_vlist(v_216891, kk_std_core_types__new_None(_ctx), _ctx); /*list<string>*/
  x13_2110 = kk_std_core_map_5(_b_2687_2684, kk_data_preprocessing_new_pre__process__data_fun3295(_ctx), _ctx); /*list<maybe<double>>*/
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x13_2110, _ctx);
    kk_box_t _x3299 = kk_std_core_hnd_yield_extend(kk_data_preprocessing_new_pre__process__data_fun3300(x3_2084, x7_2097, _ctx), _ctx); /*2*/
    return kk_std_core_types__tuple2__unbox(_x3299, _ctx);
  }
  kk_string_t x14_2116;
  kk_std_os_path__path path2_2119;
  kk_evv_t w2 = kk_evv_swap_create0(kk_context()); /*std/core/hnd/evv<(<>)>*/;
  kk_std_os_path__path x17;
  kk_string_t _x3303;
  kk_define_string_literal(, _s3304, 32, "./data/temperature-readings2.txt")
  _x3303 = kk_string_dup(_s3304); /*string*/
  x17 = kk_std_os_path_path(_x3303, _ctx); /*std/os/path/path*/
  kk_unit_t keep2 = kk_Unit;
  kk_evv_set(w2,kk_context());
  path2_2119 = x17; /*std/os/path/path*/
  kk_std_core__error _match_2817;
  kk_string_t _x15;
  kk_box_t _x3305;
  kk_box_t _x3309;
  kk_std_os_path__path _x3310 = kk_std_os_path__path_dup(path2_2119); /*std/os/path/path*/
  _x3309 = kk_std_os_path__path_box(_x3310, _ctx); /*1*/
  _x3305 = kk_std_core_hnd__open_none1(kk_data_preprocessing_new_pre__process__data_fun3306(_ctx), _x3309, _ctx); /*2*/
  _x15 = kk_string_unbox(_x3305); /*string*/
  kk_box_t _x3311 = kk_std_core_hnd__open_none1(kk_data_preprocessing_new_pre__process__data_fun3312(_ctx), kk_string_box(_x15), _ctx); /*2*/
  _match_2817 = kk_std_core__error_unbox(_x3311, _ctx); /*error<string>*/
  if (kk_std_core__is_Error(_match_2817)) {
    kk_std_core__exception exn3 = _match_2817._cons.Error.exception;
    kk_std_core__exception_dup(exn3);
    kk_std_core__error_drop(_match_2817, _ctx);
    kk_std_core__error err_4792;
    kk_std_core__exception _x3316;
    kk_string_t _x22;
    kk_string_t _x3317;
    kk_define_string_literal(, _s3318, 25, "unable to read text file ")
    _x3317 = kk_string_dup(_s3318); /*string*/
    kk_string_t _x3319;
    kk_box_t _x3320 = kk_std_core_hnd__open_none1(kk_data_preprocessing_new_pre__process__data_fun3321(_ctx), kk_std_os_path__path_box(path2_2119, _ctx), _ctx); /*2*/
    _x3319 = kk_string_unbox(_x3320); /*string*/
    _x22 = kk_std_core__lp__plus__plus__1_rp_(_x3317, _x3319, _ctx); /*string*/
    kk_box_t _x3324 = kk_std_core_hnd__open_none2(kk_data_preprocessing_new_pre__process__data_fun3325(_ctx), kk_std_core__exception_box(exn3, _ctx), kk_string_box(_x22), _ctx); /*3*/
    _x3316 = kk_std_core__exception_unbox(_x3324, _ctx); /*exception*/
    err_4792 = kk_std_core__new_Error(_x3316, _ctx); /*error<string>*/
    if (kk_std_core__is_Error(err_4792)) {
      kk_std_core__exception exn02 = err_4792._cons.Error.exception;
      kk_std_core__exception_dup(exn02);
      kk_std_core__error_drop(err_4792, _ctx);
      kk_box_t _x3329 = kk_std_core_throw_exn(exn02, _ctx); /*1*/
      x14_2116 = kk_string_unbox(_x3329); /*string*/
      goto _match3315;
    }
    kk_box_t _box_x2716 = err_4792._cons.Ok.result;
    kk_string_t x15 = kk_string_unbox(_box_x2716);
    kk_string_dup(x15);
    kk_std_core__error_drop(err_4792, _ctx);
    x14_2116 = x15; /*string*/
    goto _match3315;
  }
  kk_box_t _box_x2717 = _match_2817._cons.Ok.result;
  kk_string_t content2 = kk_string_unbox(_box_x2717);
  kk_std_os_path__path_drop(path2_2119, _ctx);
  kk_string_dup(content2);
  kk_std_core__error_drop(_match_2817, _ctx);
  x14_2116 = content2; /*string*/
  _match3315: ;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x14_2116, _ctx);
    kk_box_t _x3332 = kk_std_core_hnd_yield_extend(kk_data_preprocessing_new_pre__process__data_fun3333(x13_2110, x3_2084, x7_2097, _ctx), _ctx); /*2*/
    return kk_std_core_types__tuple2__unbox(_x3332, _ctx);
  }
  kk_std_core__list x18_2123;
  kk_std_core__list _b_2729_2726;
  kk_vector_t v_216892;
  kk_string_t _x3336;
  kk_define_string_literal(, _s3337, 1, "\n")
  _x3336 = kk_string_dup(_s3337); /*string*/
  v_216892 = kk_string_splitv(x14_2116,_x3336,kk_context()); /*vector<string>*/
  _b_2729_2726 = kk_std_core_vlist(v_216892, kk_std_core_types__new_None(_ctx), _ctx); /*list<string>*/
  x18_2123 = kk_std_core_map_5(_b_2729_2726, kk_data_preprocessing_new_pre__process__data_fun3338(_ctx), _ctx); /*list<maybe<double>>*/
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x18_2123, _ctx);
    kk_box_t _x3342 = kk_std_core_hnd_yield_extend(kk_data_preprocessing_new_pre__process__data_fun3343(x13_2110, x3_2084, x7_2097, _ctx), _ctx); /*2*/
    return kk_std_core_types__tuple2__unbox(_x3342, _ctx);
  }
  kk_std_core__list maybe__uncertainties;
  kk_std_core__list xss_2129;
  kk_std_core__list _b_2741_2739 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core__list_box(x7_2097, _ctx), kk_std_core__new_Nil(_ctx), _ctx); /*list<list<maybe<double>>>*/;
  xss_2129 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core__list_box(x3_2084, _ctx), _b_2741_2739, _ctx); /*list<list<maybe<double>>>*/
  maybe__uncertainties = kk_std_core__lift21045_concat(kk_std_core__new_Nil(_ctx), xss_2129, _ctx); /*list<maybe<double>>*/
  kk_std_core__list maybe__temperatures;
  kk_std_core__list xss0_2130;
  kk_std_core__list _b_2749_2747 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core__list_box(x18_2123, _ctx), kk_std_core__new_Nil(_ctx), _ctx); /*list<list<maybe<double>>>*/;
  xss0_2130 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core__list_box(x13_2110, _ctx), _b_2749_2747, _ctx); /*list<list<maybe<double>>>*/
  maybe__temperatures = kk_std_core__lift21045_concat(kk_std_core__new_Nil(_ctx), xss0_2130, _ctx); /*list<maybe<double>>*/
  kk_std_core__list x19_2131 = kk_data_preprocessing_remove__maybes(maybe__uncertainties, kk_std_core__new_Nil(_ctx), _ctx); /*list<double>*/;
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x19_2131, _ctx);
    kk_box_t _x3346 = kk_std_core_hnd_yield_extend(kk_data_preprocessing_new_pre__process__data_fun3347(maybe__temperatures, _ctx), _ctx); /*2*/
    return kk_std_core_types__tuple2__unbox(_x3346, _ctx);
  }
  kk_std_core__list x20_2135 = kk_data_preprocessing_remove__maybes(maybe__temperatures, kk_std_core__new_Nil(_ctx), _ctx); /*list<double>*/;
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x20_2135, _ctx);
    kk_box_t _x3350 = kk_std_core_hnd_yield_extend(kk_data_preprocessing_new_pre__process__data_fun3351(x19_2131, _ctx), _ctx); /*2*/
    return kk_std_core_types__tuple2__unbox(_x3350, _ctx);
  }
  kk_std_core__list uncertainties__by__year;
  kk_evv_t w3 = kk_evv_swap_create0(kk_context()); /*std/core/hnd/evv<(<>)>*/;
  kk_std_core__list x22 = kk_data_preprocessing_list__of__lists(x19_2131, kk_integer_from_small(12), _ctx); /*list<list<double>>*/;
  kk_unit_t keep3 = kk_Unit;
  kk_evv_set(w3,kk_context());
  uncertainties__by__year = x22; /*list<list<double>>*/
  kk_std_core__list temperatures__by__year;
  kk_evv_t w4 = kk_evv_swap_create0(kk_context()); /*std/core/hnd/evv<(<>)>*/;
  kk_std_core__list x24 = kk_data_preprocessing_list__of__lists(x20_2135, kk_integer_from_small(12), _ctx); /*list<list<double>>*/;
  kk_unit_t keep4 = kk_Unit;
  kk_evv_set(w4,kk_context());
  temperatures__by__year = x24; /*list<list<double>>*/
  kk_std_core__list x25_2145 = kk_data_preprocessing_months(uncertainties__by__year, _ctx); /*list<list<double>>*/;
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x25_2145, _ctx);
    kk_box_t _x3354 = kk_std_core_hnd_yield_extend(kk_data_preprocessing_new_pre__process__data_fun3355(temperatures__by__year, _ctx), _ctx); /*2*/
    return kk_std_core_types__tuple2__unbox(_x3354, _ctx);
  }
  kk_std_core__list x26_2149 = kk_data_preprocessing_months(temperatures__by__year, _ctx); /*list<list<double>>*/;
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x26_2149, _ctx);
    kk_box_t _x3358 = kk_std_core_hnd_yield_extend(kk_data_preprocessing_new_pre__process__data_fun3359(x25_2145, _ctx), _ctx); /*2*/
    return kk_std_core_types__tuple2__unbox(_x3358, _ctx);
  }
  kk_std_core__list grouped__uncertainties__by__month;
  kk_evv_t w5 = kk_evv_swap_create0(kk_context()); /*std/core/hnd/evv<(<>)>*/;
  kk_std_core__list x28;
  kk_function_t _b_2764_2761 = kk_data_preprocessing_list__of__lists__thunk(kk_integer_from_small(20), _ctx); /*(list : list<double>) -> div list<list<double>>*/;
  x28 = kk_std_core_map_5(x25_2145, kk_data_preprocessing_new_pre__process__data_fun3362(_b_2764_2761, _ctx), _ctx); /*list<list<list<double>>>*/
  kk_unit_t keep5 = kk_Unit;
  kk_evv_set(w5,kk_context());
  grouped__uncertainties__by__month = x28; /*list<list<list<double>>>*/
  kk_std_core__list grouped__temperatures__by__month;
  kk_evv_t w6 = kk_evv_swap_create0(kk_context()); /*std/core/hnd/evv<(<>)>*/;
  kk_std_core__list x30;
  kk_function_t _b_2769_2766 = kk_data_preprocessing_list__of__lists__thunk(kk_integer_from_small(20), _ctx); /*(list : list<double>) -> div list<list<double>>*/;
  x30 = kk_std_core_map_5(x26_2149, kk_data_preprocessing_new_pre__process__data_fun3365(_b_2769_2766, _ctx), _ctx); /*list<list<list<double>>>*/
  kk_unit_t keep6 = kk_Unit;
  kk_evv_set(w6,kk_context());
  grouped__temperatures__by__month = x30; /*list<list<list<double>>>*/
  return kk_std_core_types__new_dash__lp__comma__rp_(kk_std_core__list_box(grouped__uncertainties__by__month, _ctx), kk_std_core__list_box(grouped__temperatures__by__month, _ctx), _ctx);
}

// initialization
void kk_data_preprocessing__init(kk_context_t* _ctx){
  static bool _initialized = false;
  if (_initialized) return;
  _initialized = true;
  kk_std_core_types__init(_ctx);
  kk_std_core_hnd__init(_ctx);
  kk_std_core__init(_ctx);
  kk_std_num_double__init(_ctx);
  kk_std_os_path__init(_ctx);
  kk_std_os_file__init(_ctx);
  kk_exn_dash_get__init(_ctx);
}
