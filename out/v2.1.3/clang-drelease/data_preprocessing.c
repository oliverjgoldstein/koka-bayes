// Koka generated module: "data/preprocessing", koka version: 2.1.3
#include "data_preprocessing.h"
 
// monadic lift

kk_unit_t kk_data_preprocessing__mlift1945_all__elements__equal(kk_ref_t bool__val, kk_integer_t first__length, kk_integer_t _y_1, kk_context_t* _ctx) { /* forall<h> (bool_val : local-var<h,bool>, first_length : int, int) -> exn () */ 
  bool _match_2853 = kk_integer_neq(_y_1,first__length,kk_context()); /*bool*/;
  if (_match_2853) {
    (kk_ref_set(bool__val,(kk_bool_box(false)),kk_context())); return kk_Unit;
  }
  kk_ref_drop(bool__val, _ctx);
  kk_Unit; return kk_Unit;
}
 
// monadic lift

bool kk_data_preprocessing__mlift1946_all__elements__equal(kk_ref_t bool__val, kk_unit_t wild__0, kk_context_t* _ctx) { /* forall<h> (bool_val : local-var<h,bool>, wild_0 : ()) -> <exn,local<h>> bool */ 
  kk_box_t _x2854 = (kk_ref_get(bool__val,kk_context())); /*228*/
  return kk_bool_unbox(_x2854);
}
 
// monadic lift


// lift anonymous function
struct kk_data_preprocessing__mlift1947_all__elements__equal_fun2858__t {
  struct kk_function_s _base;
  kk_integer_t first__length;
  kk_std_core__list list;
  kk_ref_t loc;
};
static kk_unit_t kk_data_preprocessing__mlift1947_all__elements__equal_fun2858(kk_function_t _fself, kk_integer_t i, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing__new_mlift1947_all__elements__equal_fun2858(kk_integer_t first__length, kk_std_core__list list, kk_ref_t loc, kk_context_t* _ctx) {
  struct kk_data_preprocessing__mlift1947_all__elements__equal_fun2858__t* _self = kk_function_alloc_as(struct kk_data_preprocessing__mlift1947_all__elements__equal_fun2858__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_data_preprocessing__mlift1947_all__elements__equal_fun2858, kk_context());
  _self->first__length = first__length;
  _self->list = list;
  _self->loc = loc;
  return &_self->_base;
}



// lift anonymous function
struct kk_data_preprocessing__mlift1947_all__elements__equal_fun2861__t {
  struct kk_function_s _base;
  kk_integer_t first__length;
  kk_ref_t loc;
};
static kk_box_t kk_data_preprocessing__mlift1947_all__elements__equal_fun2861(kk_function_t _fself, kk_box_t _b_2199, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing__new_mlift1947_all__elements__equal_fun2861(kk_integer_t first__length, kk_ref_t loc, kk_context_t* _ctx) {
  struct kk_data_preprocessing__mlift1947_all__elements__equal_fun2861__t* _self = kk_function_alloc_as(struct kk_data_preprocessing__mlift1947_all__elements__equal_fun2861__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_data_preprocessing__mlift1947_all__elements__equal_fun2861, kk_context());
  _self->first__length = first__length;
  _self->loc = loc;
  return &_self->_base;
}

static kk_box_t kk_data_preprocessing__mlift1947_all__elements__equal_fun2861(kk_function_t _fself, kk_box_t _b_2199, kk_context_t* _ctx) {
  struct kk_data_preprocessing__mlift1947_all__elements__equal_fun2861__t* _self = kk_function_as(struct kk_data_preprocessing__mlift1947_all__elements__equal_fun2861__t*, _fself);
  kk_integer_t first__length = _self->first__length; /* int */
  kk_ref_t loc = _self->loc; /* local-var<230,bool> */
  kk_drop_match(_self, {kk_integer_dup(first__length);kk_ref_dup(loc);}, {}, _ctx)
  kk_unit_t _x2862 = kk_Unit;
  kk_integer_t _x2863 = kk_integer_unbox(_b_2199); /*int*/
  kk_data_preprocessing__mlift1945_all__elements__equal(loc, first__length, _x2863, _ctx);
  return kk_unit_box(_x2862);
}
static kk_unit_t kk_data_preprocessing__mlift1947_all__elements__equal_fun2858(kk_function_t _fself, kk_integer_t i, kk_context_t* _ctx) {
  struct kk_data_preprocessing__mlift1947_all__elements__equal_fun2858__t* _self = kk_function_as(struct kk_data_preprocessing__mlift1947_all__elements__equal_fun2858__t*, _fself);
  kk_integer_t first__length = _self->first__length; /* int */
  kk_std_core__list list = _self->list; /* list<int> */
  kk_ref_t loc = _self->loc; /* local-var<230,bool> */
  kk_drop_match(_self, {kk_integer_dup(first__length);kk_std_core__list_dup(list);kk_ref_dup(loc);}, {}, _ctx)
  kk_integer_t x0_1975;
  kk_box_t _x2859 = kk_exn_dash_get_exn_get(list, i, _ctx); /*3*/
  x0_1975 = kk_integer_unbox(_x2859); /*int*/
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x0_1975, _ctx);
    kk_box_t _x2860 = kk_std_core_hnd_yield_extend(kk_data_preprocessing__new_mlift1947_all__elements__equal_fun2861(first__length, loc, _ctx), _ctx); /*3991*/
    return kk_unit_unbox(_x2860);
  }
  return kk_data_preprocessing__mlift1945_all__elements__equal(loc, first__length, x0_1975, _ctx);
}


// lift anonymous function
struct kk_data_preprocessing__mlift1947_all__elements__equal_fun2866__t {
  struct kk_function_s _base;
  kk_ref_t loc;
};
static kk_box_t kk_data_preprocessing__mlift1947_all__elements__equal_fun2866(kk_function_t _fself, kk_box_t _b_2203, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing__new_mlift1947_all__elements__equal_fun2866(kk_ref_t loc, kk_context_t* _ctx) {
  struct kk_data_preprocessing__mlift1947_all__elements__equal_fun2866__t* _self = kk_function_alloc_as(struct kk_data_preprocessing__mlift1947_all__elements__equal_fun2866__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_data_preprocessing__mlift1947_all__elements__equal_fun2866, kk_context());
  _self->loc = loc;
  return &_self->_base;
}

static kk_box_t kk_data_preprocessing__mlift1947_all__elements__equal_fun2866(kk_function_t _fself, kk_box_t _b_2203, kk_context_t* _ctx) {
  struct kk_data_preprocessing__mlift1947_all__elements__equal_fun2866__t* _self = kk_function_as(struct kk_data_preprocessing__mlift1947_all__elements__equal_fun2866__t*, _fself);
  kk_ref_t loc = _self->loc; /* local-var<230,bool> */
  kk_drop_match(_self, {kk_ref_dup(loc);}, {}, _ctx)
  bool _x2867;
  kk_unit_t _x2868 = kk_Unit;
  kk_unit_unbox(_b_2203);
  _x2867 = kk_data_preprocessing__mlift1946_all__elements__equal(loc, _x2868, _ctx); /*bool*/
  return kk_bool_box(_x2867);
}

bool kk_data_preprocessing__mlift1947_all__elements__equal(kk_std_core__list list, kk_integer_t first__length, kk_context_t* _ctx) { /* forall<h> (list : list<int>, first_length : int) -> exn bool */ 
  kk_ref_t loc = kk_ref_alloc((kk_bool_box(true)),kk_context()); /*local-var<230,bool>*/;
  bool res;
  kk_unit_t x_1970 = kk_Unit;
  kk_integer_t end_1973;
  kk_integer_t _x2855;
  kk_std_core__list _x2856 = kk_std_core__list_dup(list); /*list<int>*/
  _x2855 = kk_std_core_length_1(_x2856, _ctx); /*int*/
  end_1973 = kk_integer_sub(_x2855,(kk_integer_from_small(1)),kk_context()); /*int*/
  kk_function_t _x2857;
  kk_ref_dup(loc);
  _x2857 = kk_data_preprocessing__new_mlift1947_all__elements__equal_fun2858(first__length, list, loc, _ctx); /*(i : int) -> <exn,local<230>> ()*/
  kk_std_core__lift21056_for(_x2857, end_1973, kk_integer_from_small(0), _ctx);
  if (kk_yielding(kk_context())) {
    kk_box_t _x2864;
    kk_function_t _x2865;
    kk_ref_dup(loc);
    _x2865 = kk_data_preprocessing__new_mlift1947_all__elements__equal_fun2866(loc, _ctx); /*(3990) -> 3992 3991*/
    _x2864 = kk_std_core_hnd_yield_extend(_x2865, _ctx); /*3991*/
    res = kk_bool_unbox(_x2864); /*bool*/
  }
  else {
    kk_ref_t _x2869 = kk_ref_dup(loc); /*local-var<230,bool>*/
    res = kk_data_preprocessing__mlift1946_all__elements__equal(_x2869, x_1970, _ctx); /*bool*/
  }
  kk_box_t _x2870 = kk_std_core_hnd_prompt_local_var(loc, kk_bool_box(res), _ctx); /*9788*/
  return kk_bool_unbox(_x2870);
}


// lift anonymous function
struct kk_data_preprocessing_all__elements__equal_fun2885__t {
  struct kk_function_s _base;
  kk_std_core__list list;
};
static kk_box_t kk_data_preprocessing_all__elements__equal_fun2885(kk_function_t _fself, kk_box_t _b_2224, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_all__elements__equal_fun2885(kk_std_core__list list, kk_context_t* _ctx) {
  struct kk_data_preprocessing_all__elements__equal_fun2885__t* _self = kk_function_alloc_as(struct kk_data_preprocessing_all__elements__equal_fun2885__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_data_preprocessing_all__elements__equal_fun2885, kk_context());
  _self->list = list;
  return &_self->_base;
}

static kk_box_t kk_data_preprocessing_all__elements__equal_fun2885(kk_function_t _fself, kk_box_t _b_2224, kk_context_t* _ctx) {
  struct kk_data_preprocessing_all__elements__equal_fun2885__t* _self = kk_function_as(struct kk_data_preprocessing_all__elements__equal_fun2885__t*, _fself);
  kk_std_core__list list = _self->list; /* list<int> */
  kk_drop_match(_self, {kk_std_core__list_dup(list);}, {}, _ctx)
  bool _x2886;
  kk_integer_t _x2887 = kk_integer_unbox(_b_2224); /*int*/
  _x2886 = kk_data_preprocessing__mlift1947_all__elements__equal(list, _x2887, _ctx); /*bool*/
  return kk_bool_box(_x2886);
}

bool kk_data_preprocessing_all__elements__equal(kk_std_core__list list, kk_context_t* _ctx) { /* (list : list<int>) -> exn bool */ 
  kk_integer_t x_1978;
  kk_std_core_types__maybe _match_2848;
  kk_std_core__list _x2871 = kk_std_core__list_dup(list); /*list<int>*/
  _match_2848 = kk_std_core__lp__lb__rb__2_rp_(_x2871, kk_integer_from_small(0), _ctx); /*maybe<12037>*/
  if (kk_std_core_types__is_Nothing(_match_2848)) {
    kk_string_t message_205;
    kk_string_t _x2872;
    kk_define_string_literal(, _s2873, 48, "ListIndexError: Invalid list indexing at index: ")
    _x2872 = kk_string_dup(_s2873); /*string*/
    kk_string_t _x2874 = kk_std_core_show(kk_integer_from_small(0), _ctx); /*string*/
    message_205 = kk_std_core__lp__plus__plus__1_rp_(_x2872, _x2874, _ctx); /*string*/
    kk_std_core__exception exn_21561;
    kk_std_core__exception_info _x2875;
    kk_std_core_types__optional _match_2850 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
    if (kk_std_core_types__is_Optional(_match_2850)) {
      kk_box_t _box_x2210 = _match_2850._cons.Optional.value;
      kk_std_core__exception_info _info_14279 = kk_std_core__exception_info_unbox(_box_x2210, NULL);
      kk_std_core__exception_info_dup(_info_14279);
      kk_std_core_types__optional_drop(_match_2850, _ctx);
      _x2875 = _info_14279; /*exception-info*/
      goto _match2876;
    }
    _x2875 = kk_std_core__new_ExnError(_ctx); /*exception-info*/
    _match2876: ;
    exn_21561 = kk_std_core__new_Exception(message_205, _x2875, _ctx); /*exception*/
    kk_std_core_hnd__ev ev_21562;
    size_t _x2878 = ((size_t)0); /*size_t*/
    ev_21562 = kk_evv_at(_x2878,kk_context()); /*std/core/hnd/ev<.hnd-exn>*/
    kk_box_t _x2879;
    struct kk_std_core_hnd_Ev* _con2880 = kk_std_core_hnd__as_Ev(ev_21562);
    kk_std_core_hnd__marker m = _con2880->marker;
    kk_box_t _box_x2211 = _con2880->hnd;
    kk_std_core__hnd_exn h = kk_std_core__hnd_exn_unbox(_box_x2211, NULL);
    kk_std_core__hnd_exn_dup(h);
    kk_std_core_hnd__clause1 _match_2849;
    struct kk_std_core__Hnd_exn* _con2882 = kk_std_core__as_Hnd_exn(h);
    kk_std_core_hnd__clause1 except_throw_exn = _con2882->except_throw_exn;
    if (kk_std_core__hnd_exn_is_unique(h)) {
      kk_std_core__hnd_exn_free(h);
    }
    else {
      kk_std_core_hnd__clause1_dup(except_throw_exn);
      kk_std_core__hnd_exn_decref(h, _ctx);
    }
    _match_2849 = except_throw_exn; /*forall<a> std/core/hnd/clause1<exception,a,.hnd-exn,3528,3529>*/
    kk_function_t _fun_unbox_x2215 = _match_2849.clause;
    _x2879 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x2215, (_fun_unbox_x2215, m, ev_21562, kk_std_core__exception_box(exn_21561, _ctx), _ctx)); /*53*/
    x_1978 = kk_integer_unbox(_x2879); /*int*/
  }
  else {
    kk_box_t _box_x2219 = _match_2848._cons.Just.value;
    kk_integer_t x0 = kk_integer_unbox(_box_x2219);
    kk_integer_dup(x0);
    kk_std_core_types__maybe_drop(_match_2848, _ctx);
    x_1978 = x0; /*int*/
  }
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_1978, _ctx);
    kk_box_t _x2884 = kk_std_core_hnd_yield_extend(kk_data_preprocessing_new_all__elements__equal_fun2885(list, _ctx), _ctx); /*3991*/
    return kk_bool_unbox(_x2884);
  }
  return kk_data_preprocessing__mlift1947_all__elements__equal(list, x_1978, _ctx);
}
extern kk_std_core_types__maybe kk_data_preprocessing_get__thunk_fun2888(kk_function_t _fself, kk_std_core__list list, kk_context_t* _ctx) {
  struct kk_data_preprocessing_get__thunk_fun2888__t* _self = kk_function_as(struct kk_data_preprocessing_get__thunk_fun2888__t*, _fself);
  kk_integer_t index = _self->index; /* int */
  kk_drop_match(_self, {kk_integer_dup(index);}, {}, _ctx)
  return kk_std_core__lp__lb__rb__2_rp_(list, index, _ctx);
}

kk_std_core__list kk_data_preprocessing_remove__maybes(kk_std_core__list list, kk_std_core__list return__list, kk_context_t* _ctx) { /* (list : list<maybe<double>>, return_list : list<double>) -> exn list<double> */ 
  kk__tailcall: ;
  if (kk_std_core__is_Nil(list)) {
    return return__list;
  }
  struct kk_std_core_Cons* _con2889 = kk_std_core__as_Cons(list);
  kk_box_t _box_x2227 = _con2889->head;
  kk_std_core__list y = _con2889->tail;
  kk_std_core_types__maybe x = kk_std_core_types__maybe_unbox(_box_x2227, NULL);
  kk_reuse_t _ru_2796 = kk_reuse_null; /*reuse*/;
  if (kk_std_core__list_is_unique(list)) {
    kk_std_core_types__maybe_dup(x);
    kk_box_drop(_box_x2227, _ctx);
    _ru_2796 = (kk_std_core__list_reuse(list));
  }
  else {
    kk_std_core_types__maybe_dup(x);
    kk_std_core__list_dup(y);
    kk_std_core__list_decref(list, _ctx);
    _ru_2796 = kk_reuse_null;
  }
  if (kk_std_core_types__is_Nothing(x)) {
    kk_reuse_drop(_ru_2796, _ctx);
    kk_std_core__list_drop(return__list, _ctx);
    kk_std_core__list_drop(y, _ctx);
    kk_std_core__exception exn_21561;
    kk_string_t _x2891;
    kk_define_string_literal(, _s2892, 69, "Preprocessing error: There are nothings! Please check the input file!")
    _x2891 = kk_string_dup(_s2892); /*string*/
    kk_std_core__exception_info _x2893;
    kk_std_core_types__optional _match_2846 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
    if (kk_std_core_types__is_Optional(_match_2846)) {
      kk_box_t _box_x2228 = _match_2846._cons.Optional.value;
      kk_std_core__exception_info _info_14279 = kk_std_core__exception_info_unbox(_box_x2228, NULL);
      kk_std_core__exception_info_dup(_info_14279);
      kk_std_core_types__optional_drop(_match_2846, _ctx);
      _x2893 = _info_14279; /*exception-info*/
      goto _match2894;
    }
    _x2893 = kk_std_core__new_ExnError(_ctx); /*exception-info*/
    _match2894: ;
    exn_21561 = kk_std_core__new_Exception(_x2891, _x2893, _ctx); /*exception*/
    kk_std_core_hnd__ev ev_21562;
    size_t _x2896 = ((size_t)0); /*size_t*/
    ev_21562 = kk_evv_at(_x2896,kk_context()); /*std/core/hnd/ev<.hnd-exn>*/
    kk_box_t _x2897;
    struct kk_std_core_hnd_Ev* _con2898 = kk_std_core_hnd__as_Ev(ev_21562);
    kk_std_core_hnd__marker m = _con2898->marker;
    kk_box_t _box_x2229 = _con2898->hnd;
    kk_std_core__hnd_exn h = kk_std_core__hnd_exn_unbox(_box_x2229, NULL);
    kk_std_core__hnd_exn_dup(h);
    kk_std_core_hnd__clause1 _match_2845;
    struct kk_std_core__Hnd_exn* _con2900 = kk_std_core__as_Hnd_exn(h);
    kk_std_core_hnd__clause1 except_throw_exn = _con2900->except_throw_exn;
    if (kk_std_core__hnd_exn_is_unique(h)) {
      kk_std_core__hnd_exn_free(h);
    }
    else {
      kk_std_core_hnd__clause1_dup(except_throw_exn);
      kk_std_core__hnd_exn_decref(h, _ctx);
    }
    _match_2845 = except_throw_exn; /*forall<a> std/core/hnd/clause1<exception,a,.hnd-exn,3528,3529>*/
    kk_function_t _fun_unbox_x2233 = _match_2845.clause;
    _x2897 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x2233, (_fun_unbox_x2233, m, ev_21562, kk_std_core__exception_box(exn_21561, _ctx), _ctx)); /*53*/
    return kk_std_core__list_unbox(_x2897, _ctx);
  }
  kk_box_t _box_x2237 = x._cons.Just.value;
  double a = kk_double_unbox(_box_x2237, NULL);
  kk_std_core_types__maybe_drop(x, _ctx);
  { // tailcall
    kk_std_core__list _x2902;
    kk_std_core__list ys_1985 = kk_std_core__new_Cons(_ru_2796, kk_double_box(a, _ctx), kk_std_core__new_Nil(_ctx), _ctx); /*list<double>*/;
    _x2902 = kk_std_core_append(return__list, ys_1985, _ctx); /*list<3560>*/
    list = y;
    return__list = _x2902;
    goto kk__tailcall;
  }
}
 
// monadic lift

kk_std_core__list kk_data_preprocessing__mlift1948_by__month(kk_std_core__list _y_12, kk_context_t* _ctx) { /* (list<maybe<double>>) -> exn list<double> */ 
  return kk_data_preprocessing_remove__maybes(_y_12, kk_std_core__new_Nil(_ctx), _ctx);
}


// lift anonymous function
struct kk_data_preprocessing_by__month_fun2904__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing_by__month_fun2904(kk_function_t _fself, kk_box_t _b_2247, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_by__month_fun2904(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing_by__month_fun2904, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_data_preprocessing_by__month_fun2907__t {
  struct kk_function_s _base;
  kk_function_t _bv_2250;
};
static kk_box_t kk_data_preprocessing_by__month_fun2907(kk_function_t _fself, kk_box_t _b_2251, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_by__month_fun2907(kk_function_t _bv_2250, kk_context_t* _ctx) {
  struct kk_data_preprocessing_by__month_fun2907__t* _self = kk_function_alloc_as(struct kk_data_preprocessing_by__month_fun2907__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_data_preprocessing_by__month_fun2907, kk_context());
  _self->_bv_2250 = _bv_2250;
  return &_self->_base;
}

static kk_box_t kk_data_preprocessing_by__month_fun2907(kk_function_t _fself, kk_box_t _b_2251, kk_context_t* _ctx) {
  struct kk_data_preprocessing_by__month_fun2907__t* _self = kk_function_as(struct kk_data_preprocessing_by__month_fun2907__t*, _fself);
  kk_function_t _bv_2250 = _self->_bv_2250; /* (list : list<double>) -> maybe<double> */
  kk_drop_match(_self, {kk_function_dup(_bv_2250);}, {}, _ctx)
  kk_std_core_types__maybe _x2908;
  kk_std_core__list _x2909 = kk_std_core__list_unbox(_b_2251, _ctx); /*list<double>*/
  _x2908 = kk_function_call(kk_std_core_types__maybe, (kk_function_t, kk_std_core__list, kk_context_t*), _bv_2250, (_bv_2250, _x2909, _ctx)); /*maybe<double>*/
  return kk_std_core_types__maybe_box(_x2908, _ctx);
}
static kk_box_t kk_data_preprocessing_by__month_fun2904(kk_function_t _fself, kk_box_t _b_2247, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_function_t _x2905;
  kk_function_t _bv_2250;
  kk_integer_t _x2906 = kk_integer_unbox(_b_2247); /*int*/
  _bv_2250 = kk_data_preprocessing_get__thunk(_x2906, _ctx); /*(list : list<double>) -> maybe<double>*/
  _x2905 = kk_data_preprocessing_new_by__month_fun2907(_bv_2250, _ctx); /*(2248) -> 2249*/
  return kk_function_box(_x2905);
}


// lift anonymous function
struct kk_data_preprocessing_by__month_fun2910__t {
  struct kk_function_s _base;
  kk_function_t _bv_2254;
};
static kk_std_core_types__maybe kk_data_preprocessing_by__month_fun2910(kk_function_t _fself, kk_std_core__list _b_2255, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_by__month_fun2910(kk_function_t _bv_2254, kk_context_t* _ctx) {
  struct kk_data_preprocessing_by__month_fun2910__t* _self = kk_function_alloc_as(struct kk_data_preprocessing_by__month_fun2910__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_data_preprocessing_by__month_fun2910, kk_context());
  _self->_bv_2254 = _bv_2254;
  return &_self->_base;
}

static kk_std_core_types__maybe kk_data_preprocessing_by__month_fun2910(kk_function_t _fself, kk_std_core__list _b_2255, kk_context_t* _ctx) {
  struct kk_data_preprocessing_by__month_fun2910__t* _self = kk_function_as(struct kk_data_preprocessing_by__month_fun2910__t*, _fself);
  kk_function_t _bv_2254 = _self->_bv_2254; /* (list : 2252) -> 2253 */
  kk_drop_match(_self, {kk_function_dup(_bv_2254);}, {}, _ctx)
  kk_box_t _x2911 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _bv_2254, (_bv_2254, kk_std_core__list_box(_b_2255, _ctx), _ctx)); /*2253*/
  return kk_std_core_types__maybe_unbox(_x2911, _ctx);
}


// lift anonymous function
struct kk_data_preprocessing_by__month_fun2912__t {
  struct kk_function_s _base;
  kk_function_t _x0_1930;
};
static kk_std_core_types__maybe kk_data_preprocessing_by__month_fun2912(kk_function_t _fself, kk_std_core__list _x1, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_by__month_fun2912(kk_function_t _x0_1930, kk_context_t* _ctx) {
  struct kk_data_preprocessing_by__month_fun2912__t* _self = kk_function_alloc_as(struct kk_data_preprocessing_by__month_fun2912__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_data_preprocessing_by__month_fun2912, kk_context());
  _self->_x0_1930 = _x0_1930;
  return &_self->_base;
}



// lift anonymous function
struct kk_data_preprocessing_by__month_fun2914__t {
  struct kk_function_s _base;
  kk_function_t _x0_1930;
};
static kk_box_t kk_data_preprocessing_by__month_fun2914(kk_function_t _fself, kk_box_t _b_2260, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_by__month_fun2914(kk_function_t _x0_1930, kk_context_t* _ctx) {
  struct kk_data_preprocessing_by__month_fun2914__t* _self = kk_function_alloc_as(struct kk_data_preprocessing_by__month_fun2914__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_data_preprocessing_by__month_fun2914, kk_context());
  _self->_x0_1930 = _x0_1930;
  return &_self->_base;
}

static kk_box_t kk_data_preprocessing_by__month_fun2914(kk_function_t _fself, kk_box_t _b_2260, kk_context_t* _ctx) {
  struct kk_data_preprocessing_by__month_fun2914__t* _self = kk_function_as(struct kk_data_preprocessing_by__month_fun2914__t*, _fself);
  kk_function_t _x0_1930 = _self->_x0_1930; /* (list : list<double>) -> maybe<double> */
  kk_drop_match(_self, {kk_function_dup(_x0_1930);}, {}, _ctx)
  kk_std_core_types__maybe _x2915;
  kk_std_core__list _x2916 = kk_std_core__list_unbox(_b_2260, _ctx); /*list<double>*/
  _x2915 = kk_function_call(kk_std_core_types__maybe, (kk_function_t, kk_std_core__list, kk_context_t*), _x0_1930, (_x0_1930, _x2916, _ctx)); /*maybe<double>*/
  return kk_std_core_types__maybe_box(_x2915, _ctx);
}
static kk_std_core_types__maybe kk_data_preprocessing_by__month_fun2912(kk_function_t _fself, kk_std_core__list _x1, kk_context_t* _ctx) {
  struct kk_data_preprocessing_by__month_fun2912__t* _self = kk_function_as(struct kk_data_preprocessing_by__month_fun2912__t*, _fself);
  kk_function_t _x0_1930 = _self->_x0_1930; /* (list : list<double>) -> maybe<double> */
  kk_drop_match(_self, {kk_function_dup(_x0_1930);}, {}, _ctx)
  kk_box_t _x2913 = kk_std_core_hnd__open_none1(kk_data_preprocessing_new_by__month_fun2914(_x0_1930, _ctx), kk_std_core__list_box(_x1, _ctx), _ctx); /*3239*/
  return kk_std_core_types__maybe_unbox(_x2913, _ctx);
}


// lift anonymous function
struct kk_data_preprocessing_by__month_fun2917__t {
  struct kk_function_s _base;
  kk_function_t _b_2265_2262;
};
static kk_box_t kk_data_preprocessing_by__month_fun2917(kk_function_t _fself, kk_box_t _b_2263, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_by__month_fun2917(kk_function_t _b_2265_2262, kk_context_t* _ctx) {
  struct kk_data_preprocessing_by__month_fun2917__t* _self = kk_function_alloc_as(struct kk_data_preprocessing_by__month_fun2917__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_data_preprocessing_by__month_fun2917, kk_context());
  _self->_b_2265_2262 = _b_2265_2262;
  return &_self->_base;
}

static kk_box_t kk_data_preprocessing_by__month_fun2917(kk_function_t _fself, kk_box_t _b_2263, kk_context_t* _ctx) {
  struct kk_data_preprocessing_by__month_fun2917__t* _self = kk_function_as(struct kk_data_preprocessing_by__month_fun2917__t*, _fself);
  kk_function_t _b_2265_2262 = _self->_b_2265_2262; /* (list<double>) -> maybe<double> */
  kk_drop_match(_self, {kk_function_dup(_b_2265_2262);}, {}, _ctx)
  kk_std_core_types__maybe _x2918;
  kk_std_core__list _x2919 = kk_std_core__list_unbox(_b_2263, _ctx); /*list<double>*/
  _x2918 = kk_function_call(kk_std_core_types__maybe, (kk_function_t, kk_std_core__list, kk_context_t*), _b_2265_2262, (_b_2265_2262, _x2919, _ctx)); /*maybe<double>*/
  return kk_std_core_types__maybe_box(_x2918, _ctx);
}


// lift anonymous function
struct kk_data_preprocessing_by__month_fun2921__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing_by__month_fun2921(kk_function_t _fself, kk_box_t _b_2269, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_by__month_fun2921(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing_by__month_fun2921, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_data_preprocessing_by__month_fun2921(kk_function_t _fself, kk_box_t _b_2269, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core__list _x2922;
  kk_std_core__list _x2923 = kk_std_core__list_unbox(_b_2269, _ctx); /*list<maybe<double>>*/
  _x2922 = kk_data_preprocessing__mlift1948_by__month(_x2923, _ctx); /*list<double>*/
  return kk_std_core__list_box(_x2922, _ctx);
}

kk_std_core__list kk_data_preprocessing_by__month(kk_std_core__list months0, kk_integer_t index, kk_context_t* _ctx) { /* (months : list<list<double>>, index : int) -> exn list<double> */ 
  kk_std_core__list x_1986;
  kk_function_t _b_2265_2262;
  kk_function_t _x0_1930;
  kk_function_t _bv_2254;
  kk_box_t _x2903 = kk_std_core_hnd__open_none1(kk_data_preprocessing_new_by__month_fun2904(_ctx), kk_integer_box(index), _ctx); /*3239*/
  _bv_2254 = kk_function_unbox(_x2903); /*(list : 2252) -> 2253*/
  _x0_1930 = kk_data_preprocessing_new_by__month_fun2910(_bv_2254, _ctx); /*(list : list<double>) -> maybe<double>*/
  _b_2265_2262 = kk_data_preprocessing_new_by__month_fun2912(_x0_1930, _ctx); /*(list<double>) -> maybe<double>*/
  x_1986 = kk_std_core_map_5(months0, kk_data_preprocessing_new_by__month_fun2917(_b_2265_2262, _ctx), _ctx); /*list<maybe<double>>*/
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_1986, _ctx);
    kk_box_t _x2920 = kk_std_core_hnd_yield_extend(kk_data_preprocessing_new_by__month_fun2921(_ctx), _ctx); /*3991*/
    return kk_std_core__list_unbox(_x2920, _ctx);
  }
  return kk_data_preprocessing_remove__maybes(x_1986, kk_std_core__new_Nil(_ctx), _ctx);
}
 
// Returns a list of lists where each list corresponds to a single year (if called with parameter 12).
// Preserves order.

kk_std_core__list kk_data_preprocessing_list__of__lists(kk_std_core__list list, kk_integer_t length, kk_context_t* _ctx) { /* (list : list<double>, length : int) -> div list<list<double>> */ 
  bool _match_2843;
  kk_integer_t _x2924 = kk_integer_dup(length); /*int*/
  _match_2843 = kk_integer_eq(_x2924,(kk_integer_from_small(0)),kk_context()); /*bool*/
  if (_match_2843) {
    kk_integer_drop(length, _ctx);
    return kk_std_core__new_Cons(kk_reuse_null, kk_std_core__list_box(list, _ctx), kk_std_core__new_Nil(_ctx), _ctx);
  }
  if (kk_std_core__is_Nil(list)) {
    kk_integer_drop(length, _ctx);
    return kk_std_core__new_Nil(_ctx);
  }
  struct kk_std_core_Cons* _con2925 = kk_std_core__as_Cons(list);
  kk_box_t _box_x2273 = _con2925->head;
  kk_reuse_t _ru_2799;
  kk_std_core__list _x2927 = kk_std_core__list_dup(list); /*list<double>*/
  _ru_2799 = kk_std_core__list_dropn_reuse(_x2927, ((int32_t)2), _ctx); /*reuse*/
  kk_std_core_types__tuple2_ list__split;
  kk_integer_t _x2928 = kk_integer_dup(length); /*int*/
  list__split = kk_std_core_split(list, _x2928, _ctx); /*(list<double>, list<double>)*/
  kk_std_core__list xs_1990;
  kk_box_t _x2929;
  kk_std_core__list _x2930;
  kk_box_t _box_x2274 = list__split.fst;
  kk_box_t _box_x2275 = list__split.snd;
  kk_std_core__list _x = kk_std_core__list_unbox(_box_x2274, NULL);
  kk_std_core__list_dup(_x);
  _x2930 = _x; /*list<double>*/
  _x2929 = kk_std_core__list_box(_x2930, _ctx); /*61*/
  xs_1990 = kk_std_core__new_Cons(_ru_2799, _x2929, kk_std_core__new_Nil(_ctx), _ctx); /*list<list<double>>*/
  kk_std_core__list ys_1991;
  kk_std_core__list _x2933;
  kk_box_t _box_x2280 = list__split.fst;
  kk_box_t _box_x2281 = list__split.snd;
  kk_std_core__list _x0 = kk_std_core__list_unbox(_box_x2281, NULL);
  kk_std_core__list_dup(_x0);
  kk_std_core_types__tuple2__drop(list__split, _ctx);
  _x2933 = _x0; /*list<double>*/
  ys_1991 = kk_data_preprocessing_list__of__lists(_x2933, length, _ctx); /*list<list<double>>*/
  return kk_std_core_append(xs_1990, ys_1991, _ctx);
}
extern kk_std_core__list kk_data_preprocessing_list__of__lists__thunk_fun2936(kk_function_t _fself, kk_std_core__list list, kk_context_t* _ctx) {
  struct kk_data_preprocessing_list__of__lists__thunk_fun2936__t* _self = kk_function_as(struct kk_data_preprocessing_list__of__lists__thunk_fun2936__t*, _fself);
  kk_integer_t length = _self->length; /* int */
  kk_drop_match(_self, {kk_integer_dup(length);}, {}, _ctx)
  return kk_data_preprocessing_list__of__lists(list, length, _ctx);
}
extern kk_box_t kk_data_preprocessing_convert__to__groups_fun2937(kk_function_t _fself, kk_box_t _b_2286, kk_context_t* _ctx) {
  struct kk_data_preprocessing_convert__to__groups_fun2937__t* _self = kk_function_as(struct kk_data_preprocessing_convert__to__groups_fun2937__t*, _fself);
  kk_function_t _b_2288_2285 = _self->_b_2288_2285; /* (list : list<double>) -> div list<list<double>> */
  kk_drop_match(_self, {kk_function_dup(_b_2288_2285);}, {}, _ctx)
  kk_std_core__list _x2938;
  kk_std_core__list _x2939 = kk_std_core__list_unbox(_b_2286, _ctx); /*list<double>*/
  _x2938 = kk_function_call(kk_std_core__list, (kk_function_t, kk_std_core__list, kk_context_t*), _b_2288_2285, (_b_2288_2285, _x2939, _ctx)); /*list<list<double>>*/
  return kk_std_core__list_box(_x2938, _ctx);
}

kk_std_core__list kk_data_preprocessing_length__months(kk_std_core__list months0, kk_context_t* _ctx) { /* (months : list<list<double>>) -> list<int> */ 
  if (kk_std_core__is_Nil(months0)) {
    return kk_std_core__new_Nil(_ctx);
  }
  struct kk_std_core_Cons* _con2940 = kk_std_core__as_Cons(months0);
  kk_box_t _box_x2289 = _con2940->head;
  kk_std_core__list y = _con2940->tail;
  kk_std_core__list x = kk_std_core__list_unbox(_box_x2289, NULL);
  kk_reuse_t _ru_2800 = kk_reuse_null; /*reuse*/;
  if (kk_std_core__list_is_unique(months0)) {
    _ru_2800 = (kk_std_core__list_reuse(months0));
  }
  else {
    kk_std_core__list_dup(x);
    kk_std_core__list_dup(y);
    kk_std_core__list_decref(months0, _ctx);
    _ru_2800 = kk_reuse_null;
  }
  kk_std_core__list xs_1994;
  kk_integer_t _b_2292_2290 = kk_std_core_length_1(x, _ctx); /*int*/;
  xs_1994 = kk_std_core__new_Cons(_ru_2800, kk_integer_box(_b_2292_2290), kk_std_core__new_Nil(_ctx), _ctx); /*list<int>*/
  kk_std_core__list ys_1995 = kk_data_preprocessing_length__months(y, _ctx); /*list<int>*/;
  return kk_std_core_append(xs_1994, ys_1995, _ctx);
}
 
// monadic lift

kk_std_core__list kk_data_preprocessing__mlift1949_months(kk_ref_t list__of__months, kk_unit_t wild__1, kk_context_t* _ctx) { /* forall<h> (list_of_months : local-var<h,list<list<double>>>, wild_1 : ()) -> <local<h>,exn> list<list<double>> */ 
  kk_box_t _x2942 = (kk_ref_get(list__of__months,kk_context())); /*228*/
  return kk_std_core__list_unbox(_x2942, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_data_preprocessing__mlift1950_months_fun2945__t {
  struct kk_function_s _base;
  kk_ref_t list__of__months;
};
static kk_box_t kk_data_preprocessing__mlift1950_months_fun2945(kk_function_t _fself, kk_box_t _b_2301, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing__new_mlift1950_months_fun2945(kk_ref_t list__of__months, kk_context_t* _ctx) {
  struct kk_data_preprocessing__mlift1950_months_fun2945__t* _self = kk_function_alloc_as(struct kk_data_preprocessing__mlift1950_months_fun2945__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_data_preprocessing__mlift1950_months_fun2945, kk_context());
  _self->list__of__months = list__of__months;
  return &_self->_base;
}

static kk_box_t kk_data_preprocessing__mlift1950_months_fun2945(kk_function_t _fself, kk_box_t _b_2301, kk_context_t* _ctx) {
  struct kk_data_preprocessing__mlift1950_months_fun2945__t* _self = kk_function_as(struct kk_data_preprocessing__mlift1950_months_fun2945__t*, _fself);
  kk_ref_t list__of__months = _self->list__of__months; /* local-var<1145,list<list<double>>> */
  kk_drop_match(_self, {kk_ref_dup(list__of__months);}, {}, _ctx)
  kk_std_core__list _x2946;
  kk_unit_t _x2947 = kk_Unit;
  kk_unit_unbox(_b_2301);
  _x2946 = kk_data_preprocessing__mlift1949_months(list__of__months, _x2947, _ctx); /*list<list<double>>*/
  return kk_std_core__list_box(_x2946, _ctx);
}

kk_std_core__list kk_data_preprocessing__mlift1950_months(kk_ref_t list__of__months, kk_std_core__list _y_19, kk_context_t* _ctx) { /* forall<h> (list_of_months : local-var<h,list<list<double>>>, list<list<double>>) -> <local<h>,exn> list<list<double>> */ 
  kk_unit_t x_1996 = kk_Unit;
  kk_std_core__list _b_2299_2297 = kk_std_core_tail_1(_y_19, _ctx); /*list<list<double>>*/;
  kk_ref_t _x2943 = kk_ref_dup(list__of__months); /*local-var<1145,list<list<double>>>*/
  (kk_ref_set(_x2943,(kk_std_core__list_box(_b_2299_2297, _ctx)),kk_context()));
  if (kk_yielding(kk_context())) {
    kk_box_t _x2944 = kk_std_core_hnd_yield_extend(kk_data_preprocessing__new_mlift1950_months_fun2945(list__of__months, _ctx), _ctx); /*3991*/
    return kk_std_core__list_unbox(_x2944, _ctx);
  }
  return kk_data_preprocessing__mlift1949_months(list__of__months, x_1996, _ctx);
}
 
// monadic lift

kk_unit_t kk_data_preprocessing__mlift1951_months(kk_std_core__list _y_15, kk_ref_t list__of__months, kk_std_core__list _y_16, kk_context_t* _ctx) { /* forall<h> (list<list<double>>, list_of_months : local-var<h,list<list<double>>>, list<double>) -> exn () */ 
  kk_std_core__list _b_2311_2309;
  kk_std_core__list ys_1999 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core__list_box(_y_16, _ctx), kk_std_core__new_Nil(_ctx), _ctx); /*list<list<double>>*/;
  _b_2311_2309 = kk_std_core_append(_y_15, ys_1999, _ctx); /*list<list<double>>*/
  (kk_ref_set(list__of__months,(kk_std_core__list_box(_b_2311_2309, _ctx)),kk_context())); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_data_preprocessing__mlift1952_months_fun2949__t {
  struct kk_function_s _base;
  kk_std_core__list _y_15;
  kk_ref_t list__of__months;
};
static kk_box_t kk_data_preprocessing__mlift1952_months_fun2949(kk_function_t _fself, kk_box_t _b_2313, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing__new_mlift1952_months_fun2949(kk_std_core__list _y_15, kk_ref_t list__of__months, kk_context_t* _ctx) {
  struct kk_data_preprocessing__mlift1952_months_fun2949__t* _self = kk_function_alloc_as(struct kk_data_preprocessing__mlift1952_months_fun2949__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_data_preprocessing__mlift1952_months_fun2949, kk_context());
  _self->_y_15 = _y_15;
  _self->list__of__months = list__of__months;
  return &_self->_base;
}

static kk_box_t kk_data_preprocessing__mlift1952_months_fun2949(kk_function_t _fself, kk_box_t _b_2313, kk_context_t* _ctx) {
  struct kk_data_preprocessing__mlift1952_months_fun2949__t* _self = kk_function_as(struct kk_data_preprocessing__mlift1952_months_fun2949__t*, _fself);
  kk_std_core__list _y_15 = _self->_y_15; /* list<list<double>> */
  kk_ref_t list__of__months = _self->list__of__months; /* local-var<1145,list<list<double>>> */
  kk_drop_match(_self, {kk_std_core__list_dup(_y_15);kk_ref_dup(list__of__months);}, {}, _ctx)
  kk_unit_t _x2950 = kk_Unit;
  kk_std_core__list _x2951 = kk_std_core__list_unbox(_b_2313, _ctx); /*list<double>*/
  kk_data_preprocessing__mlift1951_months(_y_15, list__of__months, _x2951, _ctx);
  return kk_unit_box(_x2950);
}

kk_unit_t kk_data_preprocessing__mlift1952_months(kk_integer_t i, kk_ref_t list__of__months, kk_std_core__list months0, kk_std_core__list _y_15, kk_context_t* _ctx) { /* forall<h> (i : int, list_of_months : local-var<h,list<list<double>>>, months : list<list<double>>, list<list<double>>) -> <local<h>,exn> () */ 
  kk_std_core__list x_2000 = kk_data_preprocessing_by__month(months0, i, _ctx); /*list<double>*/;
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_2000, _ctx);
    kk_box_t _x2948 = kk_std_core_hnd_yield_extend(kk_data_preprocessing__new_mlift1952_months_fun2949(_y_15, list__of__months, _ctx), _ctx); /*3991*/
    kk_unit_unbox(_x2948); return kk_Unit;
  }
  kk_data_preprocessing__mlift1951_months(_y_15, list__of__months, x_2000, _ctx); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_data_preprocessing__mlift1953_months_fun2955__t {
  struct kk_function_s _base;
  kk_ref_t list__of__months;
};
static kk_box_t kk_data_preprocessing__mlift1953_months_fun2955(kk_function_t _fself, kk_box_t _b_2319, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing__new_mlift1953_months_fun2955(kk_ref_t list__of__months, kk_context_t* _ctx) {
  struct kk_data_preprocessing__mlift1953_months_fun2955__t* _self = kk_function_alloc_as(struct kk_data_preprocessing__mlift1953_months_fun2955__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_data_preprocessing__mlift1953_months_fun2955, kk_context());
  _self->list__of__months = list__of__months;
  return &_self->_base;
}

static kk_box_t kk_data_preprocessing__mlift1953_months_fun2955(kk_function_t _fself, kk_box_t _b_2319, kk_context_t* _ctx) {
  struct kk_data_preprocessing__mlift1953_months_fun2955__t* _self = kk_function_as(struct kk_data_preprocessing__mlift1953_months_fun2955__t*, _fself);
  kk_ref_t list__of__months = _self->list__of__months; /* local-var<1145,list<list<double>>> */
  kk_drop_match(_self, {kk_ref_dup(list__of__months);}, {}, _ctx)
  kk_std_core__list _x2956;
  kk_std_core__list _x2957 = kk_std_core__list_unbox(_b_2319, _ctx); /*list<list<double>>*/
  _x2956 = kk_data_preprocessing__mlift1950_months(list__of__months, _x2957, _ctx); /*list<list<double>>*/
  return kk_std_core__list_box(_x2956, _ctx);
}

kk_std_core__list kk_data_preprocessing__mlift1953_months(kk_ref_t list__of__months, kk_unit_t wild__0, kk_context_t* _ctx) { /* forall<h> (list_of_months : local-var<h,list<list<double>>>, wild_0 : ()) -> <exn,local<h>> list<list<double>> */ 
  kk_std_core__list x_2002;
  kk_box_t _x2952;
  kk_ref_t _x2953 = kk_ref_dup(list__of__months); /*local-var<1145,list<list<double>>>*/
  _x2952 = (kk_ref_get(_x2953,kk_context())); /*228*/
  x_2002 = kk_std_core__list_unbox(_x2952, _ctx); /*list<list<double>>*/
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_2002, _ctx);
    kk_box_t _x2954 = kk_std_core_hnd_yield_extend(kk_data_preprocessing__new_mlift1953_months_fun2955(list__of__months, _ctx), _ctx); /*3991*/
    return kk_std_core__list_unbox(_x2954, _ctx);
  }
  return kk_data_preprocessing__mlift1950_months(list__of__months, x_2002, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_data_preprocessing__mlift1954_months_fun2959__t {
  struct kk_function_s _base;
  kk_ref_t loc;
  kk_std_core__list months0;
};
static kk_unit_t kk_data_preprocessing__mlift1954_months_fun2959(kk_function_t _fself, kk_integer_t i, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing__new_mlift1954_months_fun2959(kk_ref_t loc, kk_std_core__list months0, kk_context_t* _ctx) {
  struct kk_data_preprocessing__mlift1954_months_fun2959__t* _self = kk_function_alloc_as(struct kk_data_preprocessing__mlift1954_months_fun2959__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_data_preprocessing__mlift1954_months_fun2959, kk_context());
  _self->loc = loc;
  _self->months0 = months0;
  return &_self->_base;
}



// lift anonymous function
struct kk_data_preprocessing__mlift1954_months_fun2963__t {
  struct kk_function_s _base;
  kk_integer_t i;
  kk_ref_t loc;
  kk_std_core__list months0;
};
static kk_box_t kk_data_preprocessing__mlift1954_months_fun2963(kk_function_t _fself, kk_box_t _b_2331, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing__new_mlift1954_months_fun2963(kk_integer_t i, kk_ref_t loc, kk_std_core__list months0, kk_context_t* _ctx) {
  struct kk_data_preprocessing__mlift1954_months_fun2963__t* _self = kk_function_alloc_as(struct kk_data_preprocessing__mlift1954_months_fun2963__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_data_preprocessing__mlift1954_months_fun2963, kk_context());
  _self->i = i;
  _self->loc = loc;
  _self->months0 = months0;
  return &_self->_base;
}

static kk_box_t kk_data_preprocessing__mlift1954_months_fun2963(kk_function_t _fself, kk_box_t _b_2331, kk_context_t* _ctx) {
  struct kk_data_preprocessing__mlift1954_months_fun2963__t* _self = kk_function_as(struct kk_data_preprocessing__mlift1954_months_fun2963__t*, _fself);
  kk_integer_t i = _self->i; /* int */
  kk_ref_t loc = _self->loc; /* local-var<1145,list<list<double>>> */
  kk_std_core__list months0 = _self->months0; /* list<list<double>> */
  kk_drop_match(_self, {kk_integer_dup(i);kk_ref_dup(loc);kk_std_core__list_dup(months0);}, {}, _ctx)
  kk_unit_t _x2964 = kk_Unit;
  kk_std_core__list _x2965 = kk_std_core__list_unbox(_b_2331, _ctx); /*list<list<double>>*/
  kk_data_preprocessing__mlift1952_months(i, loc, months0, _x2965, _ctx);
  return kk_unit_box(_x2964);
}
static kk_unit_t kk_data_preprocessing__mlift1954_months_fun2959(kk_function_t _fself, kk_integer_t i, kk_context_t* _ctx) {
  struct kk_data_preprocessing__mlift1954_months_fun2959__t* _self = kk_function_as(struct kk_data_preprocessing__mlift1954_months_fun2959__t*, _fself);
  kk_ref_t loc = _self->loc; /* local-var<1145,list<list<double>>> */
  kk_std_core__list months0 = _self->months0; /* list<list<double>> */
  kk_drop_match(_self, {kk_ref_dup(loc);kk_std_core__list_dup(months0);}, {}, _ctx)
  kk_std_core__list x0_2012;
  kk_box_t _x2960;
  kk_ref_t _x2961 = kk_ref_dup(loc); /*local-var<1145,list<list<double>>>*/
  _x2960 = (kk_ref_get(_x2961,kk_context())); /*228*/
  x0_2012 = kk_std_core__list_unbox(_x2960, _ctx); /*list<list<double>>*/
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x0_2012, _ctx);
    kk_box_t _x2962 = kk_std_core_hnd_yield_extend(kk_data_preprocessing__new_mlift1954_months_fun2963(i, loc, months0, _ctx), _ctx); /*3991*/
    return kk_unit_unbox(_x2962);
  }
  return kk_data_preprocessing__mlift1952_months(i, loc, months0, x0_2012, _ctx);
}


// lift anonymous function
struct kk_data_preprocessing__mlift1954_months_fun2968__t {
  struct kk_function_s _base;
  kk_ref_t loc;
};
static kk_box_t kk_data_preprocessing__mlift1954_months_fun2968(kk_function_t _fself, kk_box_t _b_2335, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing__new_mlift1954_months_fun2968(kk_ref_t loc, kk_context_t* _ctx) {
  struct kk_data_preprocessing__mlift1954_months_fun2968__t* _self = kk_function_alloc_as(struct kk_data_preprocessing__mlift1954_months_fun2968__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_data_preprocessing__mlift1954_months_fun2968, kk_context());
  _self->loc = loc;
  return &_self->_base;
}

static kk_box_t kk_data_preprocessing__mlift1954_months_fun2968(kk_function_t _fself, kk_box_t _b_2335, kk_context_t* _ctx) {
  struct kk_data_preprocessing__mlift1954_months_fun2968__t* _self = kk_function_as(struct kk_data_preprocessing__mlift1954_months_fun2968__t*, _fself);
  kk_ref_t loc = _self->loc; /* local-var<1145,list<list<double>>> */
  kk_drop_match(_self, {kk_ref_dup(loc);}, {}, _ctx)
  kk_std_core__list _x2969;
  kk_unit_t _x2970 = kk_Unit;
  kk_unit_unbox(_b_2335);
  _x2969 = kk_data_preprocessing__mlift1953_months(loc, _x2970, _ctx); /*list<list<double>>*/
  return kk_std_core__list_box(_x2969, _ctx);
}

kk_std_core__list kk_data_preprocessing__mlift1954_months(kk_std_core__list months0, bool _y_14, kk_context_t* _ctx) { /* forall<h> (months : list<list<double>>, bool) -> exn list<list<double>> */ 
  kk_std_core__list init_2004 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core__list_box(kk_std_core__new_Nil(_ctx), _ctx), kk_std_core__new_Nil(_ctx), _ctx); /*list<list<double>>*/;
  kk_ref_t loc = kk_ref_alloc((kk_std_core__list_box(init_2004, _ctx)),kk_context()); /*local-var<1145,list<list<double>>>*/;
  kk_std_core__list res;
  kk_unit_t x_2007 = kk_Unit;
  kk_function_t _x2958;
  kk_ref_dup(loc);
  _x2958 = kk_data_preprocessing__new_mlift1954_months_fun2959(loc, months0, _ctx); /*(i : int) -> <exn,local<1145>> ()*/
  kk_std_core__lift21056_for(_x2958, kk_integer_from_small(11), kk_integer_from_small(0), _ctx);
  if (kk_yielding(kk_context())) {
    kk_box_t _x2966;
    kk_function_t _x2967;
    kk_ref_dup(loc);
    _x2967 = kk_data_preprocessing__new_mlift1954_months_fun2968(loc, _ctx); /*(3990) -> 3992 3991*/
    _x2966 = kk_std_core_hnd_yield_extend(_x2967, _ctx); /*3991*/
    res = kk_std_core__list_unbox(_x2966, _ctx); /*list<list<double>>*/
  }
  else {
    kk_ref_t _x2971 = kk_ref_dup(loc); /*local-var<1145,list<list<double>>>*/
    res = kk_data_preprocessing__mlift1953_months(_x2971, x_2007, _ctx); /*list<list<double>>*/
  }
  kk_box_t _x2972 = kk_std_core_hnd_prompt_local_var(loc, kk_std_core__list_box(res, _ctx), _ctx); /*9788*/
  return kk_std_core__list_unbox(_x2972, _ctx);
}
 
/* [[1,2,3,4,5,6,...12],[1,2,3,4,5,6...12]...] -> [[1,1,1,1,1,..........1,1,1,1],[2,2,2,2,2,2,......2,2,2,]] */


// lift anonymous function
struct kk_data_preprocessing_months_fun2974__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing_months_fun2974(kk_function_t _fself, kk_box_t _b_2344, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_months_fun2974(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing_months_fun2974, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_data_preprocessing_months_fun2974(kk_function_t _fself, kk_box_t _b_2344, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core__list _x2975;
  kk_std_core__list _x2976 = kk_std_core__list_unbox(_b_2344, _ctx); /*list<list<double>>*/
  _x2975 = kk_data_preprocessing_length__months(_x2976, _ctx); /*list<int>*/
  return kk_std_core__list_box(_x2975, _ctx);
}


// lift anonymous function
struct kk_data_preprocessing_months_fun2993__t {
  struct kk_function_s _base;
  kk_std_core__list list_2017;
};
static kk_box_t kk_data_preprocessing_months_fun2993(kk_function_t _fself, kk_box_t _b_2361, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_months_fun2993(kk_std_core__list list_2017, kk_context_t* _ctx) {
  struct kk_data_preprocessing_months_fun2993__t* _self = kk_function_alloc_as(struct kk_data_preprocessing_months_fun2993__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_data_preprocessing_months_fun2993, kk_context());
  _self->list_2017 = list_2017;
  return &_self->_base;
}

static kk_box_t kk_data_preprocessing_months_fun2993(kk_function_t _fself, kk_box_t _b_2361, kk_context_t* _ctx) {
  struct kk_data_preprocessing_months_fun2993__t* _self = kk_function_as(struct kk_data_preprocessing_months_fun2993__t*, _fself);
  kk_std_core__list list_2017 = _self->list_2017; /* list<int> */
  kk_drop_match(_self, {kk_std_core__list_dup(list_2017);}, {}, _ctx)
  bool _x2994;
  kk_integer_t _x2995 = kk_integer_unbox(_b_2361); /*int*/
  _x2994 = kk_data_preprocessing__mlift1947_all__elements__equal(list_2017, _x2995, _ctx); /*bool*/
  return kk_bool_box(_x2994);
}


// lift anonymous function
struct kk_data_preprocessing_months_fun2997__t {
  struct kk_function_s _base;
  kk_std_core__list months0;
};
static kk_box_t kk_data_preprocessing_months_fun2997(kk_function_t _fself, kk_box_t _b_2365, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_months_fun2997(kk_std_core__list months0, kk_context_t* _ctx) {
  struct kk_data_preprocessing_months_fun2997__t* _self = kk_function_alloc_as(struct kk_data_preprocessing_months_fun2997__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_data_preprocessing_months_fun2997, kk_context());
  _self->months0 = months0;
  return &_self->_base;
}

static kk_box_t kk_data_preprocessing_months_fun2997(kk_function_t _fself, kk_box_t _b_2365, kk_context_t* _ctx) {
  struct kk_data_preprocessing_months_fun2997__t* _self = kk_function_as(struct kk_data_preprocessing_months_fun2997__t*, _fself);
  kk_std_core__list months0 = _self->months0; /* list<list<double>> */
  kk_drop_match(_self, {kk_std_core__list_dup(months0);}, {}, _ctx)
  kk_std_core__list _x2998;
  bool _x2999 = kk_bool_unbox(_b_2365); /*bool*/
  _x2998 = kk_data_preprocessing__mlift1954_months(months0, _x2999, _ctx); /*list<list<double>>*/
  return kk_std_core__list_box(_x2998, _ctx);
}

kk_std_core__list kk_data_preprocessing_months(kk_std_core__list months0, kk_context_t* _ctx) { /* (months : list<list<double>>) -> exn list<list<double>> */ 
  bool x_2015;
  kk_std_core__list list_2017;
  kk_box_t _x2973;
  kk_box_t _x2977;
  kk_std_core__list _x2978 = kk_std_core__list_dup(months0); /*list<list<double>>*/
  _x2977 = kk_std_core__list_box(_x2978, _ctx); /*3238*/
  _x2973 = kk_std_core_hnd__open_none1(kk_data_preprocessing_new_months_fun2974(_ctx), _x2977, _ctx); /*3239*/
  list_2017 = kk_std_core__list_unbox(_x2973, _ctx); /*list<int>*/
  kk_integer_t x0_2019;
  kk_std_core_types__maybe _match_2835;
  kk_std_core__list _x2979 = kk_std_core__list_dup(list_2017); /*list<int>*/
  _match_2835 = kk_std_core__lp__lb__rb__2_rp_(_x2979, kk_integer_from_small(0), _ctx); /*maybe<12037>*/
  if (kk_std_core_types__is_Nothing(_match_2835)) {
    kk_string_t message_205;
    kk_string_t _x2980;
    kk_define_string_literal(, _s2981, 48, "ListIndexError: Invalid list indexing at index: ")
    _x2980 = kk_string_dup(_s2981); /*string*/
    kk_string_t _x2982 = kk_std_core_show(kk_integer_from_small(0), _ctx); /*string*/
    message_205 = kk_std_core__lp__plus__plus__1_rp_(_x2980, _x2982, _ctx); /*string*/
    kk_std_core__exception exn_21561;
    kk_std_core__exception_info _x2983;
    kk_std_core_types__optional _match_2837 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
    if (kk_std_core_types__is_Optional(_match_2837)) {
      kk_box_t _box_x2347 = _match_2837._cons.Optional.value;
      kk_std_core__exception_info _info_14279 = kk_std_core__exception_info_unbox(_box_x2347, NULL);
      kk_std_core__exception_info_dup(_info_14279);
      kk_std_core_types__optional_drop(_match_2837, _ctx);
      _x2983 = _info_14279; /*exception-info*/
      goto _match2984;
    }
    _x2983 = kk_std_core__new_ExnError(_ctx); /*exception-info*/
    _match2984: ;
    exn_21561 = kk_std_core__new_Exception(message_205, _x2983, _ctx); /*exception*/
    kk_std_core_hnd__ev ev_21562;
    size_t _x2986 = ((size_t)0); /*size_t*/
    ev_21562 = kk_evv_at(_x2986,kk_context()); /*std/core/hnd/ev<.hnd-exn>*/
    kk_box_t _x2987;
    struct kk_std_core_hnd_Ev* _con2988 = kk_std_core_hnd__as_Ev(ev_21562);
    kk_std_core_hnd__marker m = _con2988->marker;
    kk_box_t _box_x2348 = _con2988->hnd;
    kk_std_core__hnd_exn h = kk_std_core__hnd_exn_unbox(_box_x2348, NULL);
    kk_std_core__hnd_exn_dup(h);
    kk_std_core_hnd__clause1 _match_2836;
    struct kk_std_core__Hnd_exn* _con2990 = kk_std_core__as_Hnd_exn(h);
    kk_std_core_hnd__clause1 except_throw_exn = _con2990->except_throw_exn;
    if (kk_std_core__hnd_exn_is_unique(h)) {
      kk_std_core__hnd_exn_free(h);
    }
    else {
      kk_std_core_hnd__clause1_dup(except_throw_exn);
      kk_std_core__hnd_exn_decref(h, _ctx);
    }
    _match_2836 = except_throw_exn; /*forall<a> std/core/hnd/clause1<exception,a,.hnd-exn,3528,3529>*/
    kk_function_t _fun_unbox_x2352 = _match_2836.clause;
    _x2987 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x2352, (_fun_unbox_x2352, m, ev_21562, kk_std_core__exception_box(exn_21561, _ctx), _ctx)); /*53*/
    x0_2019 = kk_integer_unbox(_x2987); /*int*/
  }
  else {
    kk_box_t _box_x2356 = _match_2835._cons.Just.value;
    kk_integer_t x1 = kk_integer_unbox(_box_x2356);
    kk_integer_dup(x1);
    kk_std_core_types__maybe_drop(_match_2835, _ctx);
    x0_2019 = x1; /*int*/
  }
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x0_2019, _ctx);
    kk_box_t _x2992 = kk_std_core_hnd_yield_extend(kk_data_preprocessing_new_months_fun2993(list_2017, _ctx), _ctx); /*3991*/
    x_2015 = kk_bool_unbox(_x2992); /*bool*/
  }
  else {
    x_2015 = kk_data_preprocessing__mlift1947_all__elements__equal(list_2017, x0_2019, _ctx); /*bool*/
  }
  if (kk_yielding(kk_context())) {
    kk_box_t _x2996 = kk_std_core_hnd_yield_extend(kk_data_preprocessing_new_months_fun2997(months0, _ctx), _ctx); /*3991*/
    return kk_std_core__list_unbox(_x2996, _ctx);
  }
  return kk_data_preprocessing__mlift1954_months(months0, x_2015, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_data_preprocessing__mlift1955_pre__process__data_fun3000__t {
  struct kk_function_s _base;
  kk_function_t _b_2372_2369;
};
static kk_box_t kk_data_preprocessing__mlift1955_pre__process__data_fun3000(kk_function_t _fself, kk_box_t _b_2370, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing__new_mlift1955_pre__process__data_fun3000(kk_function_t _b_2372_2369, kk_context_t* _ctx) {
  struct kk_data_preprocessing__mlift1955_pre__process__data_fun3000__t* _self = kk_function_alloc_as(struct kk_data_preprocessing__mlift1955_pre__process__data_fun3000__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_data_preprocessing__mlift1955_pre__process__data_fun3000, kk_context());
  _self->_b_2372_2369 = _b_2372_2369;
  return &_self->_base;
}

static kk_box_t kk_data_preprocessing__mlift1955_pre__process__data_fun3000(kk_function_t _fself, kk_box_t _b_2370, kk_context_t* _ctx) {
  struct kk_data_preprocessing__mlift1955_pre__process__data_fun3000__t* _self = kk_function_as(struct kk_data_preprocessing__mlift1955_pre__process__data_fun3000__t*, _fself);
  kk_function_t _b_2372_2369 = _self->_b_2372_2369; /* (list : list<double>) -> div list<list<double>> */
  kk_drop_match(_self, {kk_function_dup(_b_2372_2369);}, {}, _ctx)
  kk_std_core__list _x3001;
  kk_std_core__list _x3002 = kk_std_core__list_unbox(_b_2370, _ctx); /*list<double>*/
  _x3001 = kk_function_call(kk_std_core__list, (kk_function_t, kk_std_core__list, kk_context_t*), _b_2372_2369, (_b_2372_2369, _x3002, _ctx)); /*list<list<double>>*/
  return kk_std_core__list_box(_x3001, _ctx);
}


// lift anonymous function
struct kk_data_preprocessing__mlift1955_pre__process__data_fun3003__t {
  struct kk_function_s _base;
  kk_function_t _b_2377_2374;
};
static kk_box_t kk_data_preprocessing__mlift1955_pre__process__data_fun3003(kk_function_t _fself, kk_box_t _b_2375, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing__new_mlift1955_pre__process__data_fun3003(kk_function_t _b_2377_2374, kk_context_t* _ctx) {
  struct kk_data_preprocessing__mlift1955_pre__process__data_fun3003__t* _self = kk_function_alloc_as(struct kk_data_preprocessing__mlift1955_pre__process__data_fun3003__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_data_preprocessing__mlift1955_pre__process__data_fun3003, kk_context());
  _self->_b_2377_2374 = _b_2377_2374;
  return &_self->_base;
}

static kk_box_t kk_data_preprocessing__mlift1955_pre__process__data_fun3003(kk_function_t _fself, kk_box_t _b_2375, kk_context_t* _ctx) {
  struct kk_data_preprocessing__mlift1955_pre__process__data_fun3003__t* _self = kk_function_as(struct kk_data_preprocessing__mlift1955_pre__process__data_fun3003__t*, _fself);
  kk_function_t _b_2377_2374 = _self->_b_2377_2374; /* (list : list<double>) -> div list<list<double>> */
  kk_drop_match(_self, {kk_function_dup(_b_2377_2374);}, {}, _ctx)
  kk_std_core__list _x3004;
  kk_std_core__list _x3005 = kk_std_core__list_unbox(_b_2375, _ctx); /*list<double>*/
  _x3004 = kk_function_call(kk_std_core__list, (kk_function_t, kk_std_core__list, kk_context_t*), _b_2377_2374, (_b_2377_2374, _x3005, _ctx)); /*list<list<double>>*/
  return kk_std_core__list_box(_x3004, _ctx);
}

kk_std_core_types__tuple2_ kk_data_preprocessing__mlift1955_pre__process__data(kk_std_core__list uncertainties__by__month, kk_std_core__list temperatures__by__month, kk_context_t* _ctx) { /* (uncertainties_by_month : list<list<double>>, temperatures_by_month : list<list<double>>) -> exn (list<list<list<double>>>, list<list<list<double>>>) */ 
  kk_std_core__list grouped__uncertainties__by__month;
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*std/core/hnd/evv<(<>)>*/;
  kk_std_core__list x;
  kk_function_t _b_2372_2369 = kk_data_preprocessing_list__of__lists__thunk(kk_integer_from_small(20), _ctx); /*(list : list<double>) -> div list<list<double>>*/;
  x = kk_std_core_map_5(uncertainties__by__month, kk_data_preprocessing__new_mlift1955_pre__process__data_fun3000(_b_2372_2369, _ctx), _ctx); /*list<list<list<double>>>*/
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  grouped__uncertainties__by__month = x; /*list<list<list<double>>>*/
  kk_std_core__list grouped__temperatures__by__month;
  kk_evv_t w0 = kk_evv_swap_create0(kk_context()); /*std/core/hnd/evv<(<>)>*/;
  kk_std_core__list x0;
  kk_function_t _b_2377_2374 = kk_data_preprocessing_list__of__lists__thunk(kk_integer_from_small(20), _ctx); /*(list : list<double>) -> div list<list<double>>*/;
  x0 = kk_std_core_map_5(temperatures__by__month, kk_data_preprocessing__new_mlift1955_pre__process__data_fun3003(_b_2377_2374, _ctx), _ctx); /*list<list<list<double>>>*/
  kk_unit_t keep0 = kk_Unit;
  kk_evv_set(w0,kk_context());
  grouped__temperatures__by__month = x0; /*list<list<list<double>>>*/
  return kk_std_core_types__new_dash__lp__comma__rp_(kk_std_core__list_box(grouped__uncertainties__by__month, _ctx), kk_std_core__list_box(grouped__temperatures__by__month, _ctx), _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_data_preprocessing__mlift1956_pre__process__data_fun3007__t {
  struct kk_function_s _base;
  kk_std_core__list uncertainties__by__month;
};
static kk_box_t kk_data_preprocessing__mlift1956_pre__process__data_fun3007(kk_function_t _fself, kk_box_t _b_2383, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing__new_mlift1956_pre__process__data_fun3007(kk_std_core__list uncertainties__by__month, kk_context_t* _ctx) {
  struct kk_data_preprocessing__mlift1956_pre__process__data_fun3007__t* _self = kk_function_alloc_as(struct kk_data_preprocessing__mlift1956_pre__process__data_fun3007__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_data_preprocessing__mlift1956_pre__process__data_fun3007, kk_context());
  _self->uncertainties__by__month = uncertainties__by__month;
  return &_self->_base;
}

static kk_box_t kk_data_preprocessing__mlift1956_pre__process__data_fun3007(kk_function_t _fself, kk_box_t _b_2383, kk_context_t* _ctx) {
  struct kk_data_preprocessing__mlift1956_pre__process__data_fun3007__t* _self = kk_function_as(struct kk_data_preprocessing__mlift1956_pre__process__data_fun3007__t*, _fself);
  kk_std_core__list uncertainties__by__month = _self->uncertainties__by__month; /* list<list<double>> */
  kk_drop_match(_self, {kk_std_core__list_dup(uncertainties__by__month);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x3008;
  kk_std_core__list _x3009 = kk_std_core__list_unbox(_b_2383, _ctx); /*list<list<double>>*/
  _x3008 = kk_data_preprocessing__mlift1955_pre__process__data(uncertainties__by__month, _x3009, _ctx); /*(list<list<list<double>>>, list<list<list<double>>>)*/
  return kk_std_core_types__tuple2__box(_x3008, _ctx);
}

kk_std_core_types__tuple2_ kk_data_preprocessing__mlift1956_pre__process__data(kk_std_core__list temperatures__by__year, kk_std_core__list uncertainties__by__month, kk_context_t* _ctx) { /* (temperatures_by_year : list<list<double>>, uncertainties_by_month : list<list<double>>) -> exn (list<list<list<double>>>, list<list<list<double>>>) */ 
  kk_std_core__list x_2029 = kk_data_preprocessing_months(temperatures__by__year, _ctx); /*list<list<double>>*/;
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_2029, _ctx);
    kk_box_t _x3006 = kk_std_core_hnd_yield_extend(kk_data_preprocessing__new_mlift1956_pre__process__data_fun3007(uncertainties__by__month, _ctx), _ctx); /*3991*/
    return kk_std_core_types__tuple2__unbox(_x3006, _ctx);
  }
  return kk_data_preprocessing__mlift1955_pre__process__data(uncertainties__by__month, x_2029, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_data_preprocessing__mlift1957_pre__process__data_fun3011__t {
  struct kk_function_s _base;
  kk_std_core__list temperatures__by__year;
};
static kk_box_t kk_data_preprocessing__mlift1957_pre__process__data_fun3011(kk_function_t _fself, kk_box_t _b_2387, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing__new_mlift1957_pre__process__data_fun3011(kk_std_core__list temperatures__by__year, kk_context_t* _ctx) {
  struct kk_data_preprocessing__mlift1957_pre__process__data_fun3011__t* _self = kk_function_alloc_as(struct kk_data_preprocessing__mlift1957_pre__process__data_fun3011__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_data_preprocessing__mlift1957_pre__process__data_fun3011, kk_context());
  _self->temperatures__by__year = temperatures__by__year;
  return &_self->_base;
}

static kk_box_t kk_data_preprocessing__mlift1957_pre__process__data_fun3011(kk_function_t _fself, kk_box_t _b_2387, kk_context_t* _ctx) {
  struct kk_data_preprocessing__mlift1957_pre__process__data_fun3011__t* _self = kk_function_as(struct kk_data_preprocessing__mlift1957_pre__process__data_fun3011__t*, _fself);
  kk_std_core__list temperatures__by__year = _self->temperatures__by__year; /* list<list<double>> */
  kk_drop_match(_self, {kk_std_core__list_dup(temperatures__by__year);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x3012;
  kk_std_core__list _x3013 = kk_std_core__list_unbox(_b_2387, _ctx); /*list<list<double>>*/
  _x3012 = kk_data_preprocessing__mlift1956_pre__process__data(temperatures__by__year, _x3013, _ctx); /*(list<list<list<double>>>, list<list<list<double>>>)*/
  return kk_std_core_types__tuple2__box(_x3012, _ctx);
}

kk_std_core_types__tuple2_ kk_data_preprocessing__mlift1957_pre__process__data(kk_std_core__list uncertainties, kk_std_core__list temperatures, kk_context_t* _ctx) { /* (uncertainties : list<double>, temperatures : list<double>) -> exn (list<list<list<double>>>, list<list<list<double>>>) */ 
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
  kk_std_core__list x3_2037 = kk_data_preprocessing_months(uncertainties__by__year, _ctx); /*list<list<double>>*/;
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x3_2037, _ctx);
    kk_box_t _x3010 = kk_std_core_hnd_yield_extend(kk_data_preprocessing__new_mlift1957_pre__process__data_fun3011(temperatures__by__year, _ctx), _ctx); /*3991*/
    return kk_std_core_types__tuple2__unbox(_x3010, _ctx);
  }
  return kk_data_preprocessing__mlift1956_pre__process__data(temperatures__by__year, x3_2037, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_data_preprocessing__mlift1958_pre__process__data_fun3015__t {
  struct kk_function_s _base;
  kk_std_core__list uncertainties;
};
static kk_box_t kk_data_preprocessing__mlift1958_pre__process__data_fun3015(kk_function_t _fself, kk_box_t _b_2391, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing__new_mlift1958_pre__process__data_fun3015(kk_std_core__list uncertainties, kk_context_t* _ctx) {
  struct kk_data_preprocessing__mlift1958_pre__process__data_fun3015__t* _self = kk_function_alloc_as(struct kk_data_preprocessing__mlift1958_pre__process__data_fun3015__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_data_preprocessing__mlift1958_pre__process__data_fun3015, kk_context());
  _self->uncertainties = uncertainties;
  return &_self->_base;
}

static kk_box_t kk_data_preprocessing__mlift1958_pre__process__data_fun3015(kk_function_t _fself, kk_box_t _b_2391, kk_context_t* _ctx) {
  struct kk_data_preprocessing__mlift1958_pre__process__data_fun3015__t* _self = kk_function_as(struct kk_data_preprocessing__mlift1958_pre__process__data_fun3015__t*, _fself);
  kk_std_core__list uncertainties = _self->uncertainties; /* list<double> */
  kk_drop_match(_self, {kk_std_core__list_dup(uncertainties);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x3016;
  kk_std_core__list _x3017 = kk_std_core__list_unbox(_b_2391, _ctx); /*list<double>*/
  _x3016 = kk_data_preprocessing__mlift1957_pre__process__data(uncertainties, _x3017, _ctx); /*(list<list<list<double>>>, list<list<list<double>>>)*/
  return kk_std_core_types__tuple2__box(_x3016, _ctx);
}

kk_std_core_types__tuple2_ kk_data_preprocessing__mlift1958_pre__process__data(kk_std_core__list maybe__temperatures, kk_std_core__list uncertainties, kk_context_t* _ctx) { /* (maybe_temperatures : list<maybe<double>>, uncertainties : list<double>) -> exn (list<list<list<double>>>, list<list<list<double>>>) */ 
  kk_std_core__list x_2039 = kk_data_preprocessing_remove__maybes(maybe__temperatures, kk_std_core__new_Nil(_ctx), _ctx); /*list<double>*/;
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_2039, _ctx);
    kk_box_t _x3014 = kk_std_core_hnd_yield_extend(kk_data_preprocessing__new_mlift1958_pre__process__data_fun3015(uncertainties, _ctx), _ctx); /*3991*/
    return kk_std_core_types__tuple2__unbox(_x3014, _ctx);
  }
  return kk_data_preprocessing__mlift1957_pre__process__data(uncertainties, x_2039, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_data_preprocessing__mlift1959_pre__process__data_fun3019__t {
  struct kk_function_s _base;
  kk_std_core__list maybe__temperatures;
};
static kk_box_t kk_data_preprocessing__mlift1959_pre__process__data_fun3019(kk_function_t _fself, kk_box_t _b_2411, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing__new_mlift1959_pre__process__data_fun3019(kk_std_core__list maybe__temperatures, kk_context_t* _ctx) {
  struct kk_data_preprocessing__mlift1959_pre__process__data_fun3019__t* _self = kk_function_alloc_as(struct kk_data_preprocessing__mlift1959_pre__process__data_fun3019__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_data_preprocessing__mlift1959_pre__process__data_fun3019, kk_context());
  _self->maybe__temperatures = maybe__temperatures;
  return &_self->_base;
}

static kk_box_t kk_data_preprocessing__mlift1959_pre__process__data_fun3019(kk_function_t _fself, kk_box_t _b_2411, kk_context_t* _ctx) {
  struct kk_data_preprocessing__mlift1959_pre__process__data_fun3019__t* _self = kk_function_as(struct kk_data_preprocessing__mlift1959_pre__process__data_fun3019__t*, _fself);
  kk_std_core__list maybe__temperatures = _self->maybe__temperatures; /* list<maybe<double>> */
  kk_drop_match(_self, {kk_std_core__list_dup(maybe__temperatures);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x3020;
  kk_std_core__list _x3021 = kk_std_core__list_unbox(_b_2411, _ctx); /*list<double>*/
  _x3020 = kk_data_preprocessing__mlift1958_pre__process__data(maybe__temperatures, _x3021, _ctx); /*(list<list<list<double>>>, list<list<list<double>>>)*/
  return kk_std_core_types__tuple2__box(_x3020, _ctx);
}

kk_std_core_types__tuple2_ kk_data_preprocessing__mlift1959_pre__process__data(kk_std_core__list temperatures1, kk_std_core__list uncertainties1, kk_std_core__list uncertainties2, kk_std_core__list temperatures2, kk_context_t* _ctx) { /* (temperatures1 : list<maybe<double>>, uncertainties1 : list<maybe<double>>, uncertainties2 : list<maybe<double>>, temperatures2 : list<maybe<double>>) -> <exn,fsys,div> (list<list<list<double>>>, list<list<list<double>>>) */ 
  kk_std_core__list maybe__uncertainties;
  kk_std_core__list xss_2041;
  kk_std_core__list _b_2399_2397 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core__list_box(uncertainties2, _ctx), kk_std_core__new_Nil(_ctx), _ctx); /*list<list<maybe<double>>>*/;
  xss_2041 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core__list_box(uncertainties1, _ctx), _b_2399_2397, _ctx); /*list<list<maybe<double>>>*/
  maybe__uncertainties = kk_std_core__lift21045_concat(kk_std_core__new_Nil(_ctx), xss_2041, _ctx); /*list<maybe<double>>*/
  kk_std_core__list maybe__temperatures;
  kk_std_core__list xss0_2042;
  kk_std_core__list _b_2407_2405 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core__list_box(temperatures2, _ctx), kk_std_core__new_Nil(_ctx), _ctx); /*list<list<maybe<double>>>*/;
  xss0_2042 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core__list_box(temperatures1, _ctx), _b_2407_2405, _ctx); /*list<list<maybe<double>>>*/
  maybe__temperatures = kk_std_core__lift21045_concat(kk_std_core__new_Nil(_ctx), xss0_2042, _ctx); /*list<maybe<double>>*/
  kk_std_core__list x_2043 = kk_data_preprocessing_remove__maybes(maybe__uncertainties, kk_std_core__new_Nil(_ctx), _ctx); /*list<double>*/;
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_2043, _ctx);
    kk_box_t _x3018 = kk_std_core_hnd_yield_extend(kk_data_preprocessing__new_mlift1959_pre__process__data_fun3019(maybe__temperatures, _ctx), _ctx); /*3991*/
    return kk_std_core_types__tuple2__unbox(_x3018, _ctx);
  }
  return kk_data_preprocessing__mlift1958_pre__process__data(maybe__temperatures, x_2043, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_data_preprocessing__mlift1960_pre__process__data_fun3024__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing__mlift1960_pre__process__data_fun3024(kk_function_t _fself, kk_box_t _b_2419, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing__new_mlift1960_pre__process__data_fun3024(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing__mlift1960_pre__process__data_fun3024, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_data_preprocessing__mlift1960_pre__process__data_fun3025__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing__mlift1960_pre__process__data_fun3025(kk_function_t _fself, kk_box_t _b_2416, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing__new_mlift1960_pre__process__data_fun3025(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing__mlift1960_pre__process__data_fun3025, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_data_preprocessing__mlift1960_pre__process__data_fun3025(kk_function_t _fself, kk_box_t _b_2416, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core_types__maybe _x3026;
  kk_string_t _x3027 = kk_string_unbox(_b_2416); /*string*/
  _x3026 = kk_std_num_double_parse_double(_x3027, _ctx); /*maybe<double>*/
  return kk_std_core_types__maybe_box(_x3026, _ctx);
}
static kk_box_t kk_data_preprocessing__mlift1960_pre__process__data_fun3024(kk_function_t _fself, kk_box_t _b_2419, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return kk_std_core_hnd__open_none1(kk_data_preprocessing__new_mlift1960_pre__process__data_fun3025(_ctx), _b_2419, _ctx);
}


// lift anonymous function
struct kk_data_preprocessing__mlift1960_pre__process__data_fun3029__t {
  struct kk_function_s _base;
  kk_std_core__list temperatures1;
  kk_std_core__list uncertainties1;
  kk_std_core__list uncertainties2;
};
static kk_box_t kk_data_preprocessing__mlift1960_pre__process__data_fun3029(kk_function_t _fself, kk_box_t _b_2426, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing__new_mlift1960_pre__process__data_fun3029(kk_std_core__list temperatures1, kk_std_core__list uncertainties1, kk_std_core__list uncertainties2, kk_context_t* _ctx) {
  struct kk_data_preprocessing__mlift1960_pre__process__data_fun3029__t* _self = kk_function_alloc_as(struct kk_data_preprocessing__mlift1960_pre__process__data_fun3029__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_data_preprocessing__mlift1960_pre__process__data_fun3029, kk_context());
  _self->temperatures1 = temperatures1;
  _self->uncertainties1 = uncertainties1;
  _self->uncertainties2 = uncertainties2;
  return &_self->_base;
}

static kk_box_t kk_data_preprocessing__mlift1960_pre__process__data_fun3029(kk_function_t _fself, kk_box_t _b_2426, kk_context_t* _ctx) {
  struct kk_data_preprocessing__mlift1960_pre__process__data_fun3029__t* _self = kk_function_as(struct kk_data_preprocessing__mlift1960_pre__process__data_fun3029__t*, _fself);
  kk_std_core__list temperatures1 = _self->temperatures1; /* list<maybe<double>> */
  kk_std_core__list uncertainties1 = _self->uncertainties1; /* list<maybe<double>> */
  kk_std_core__list uncertainties2 = _self->uncertainties2; /* list<maybe<double>> */
  kk_drop_match(_self, {kk_std_core__list_dup(temperatures1);kk_std_core__list_dup(uncertainties1);kk_std_core__list_dup(uncertainties2);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x3030;
  kk_std_core__list _x3031 = kk_std_core__list_unbox(_b_2426, _ctx); /*list<maybe<double>>*/
  _x3030 = kk_data_preprocessing__mlift1959_pre__process__data(temperatures1, uncertainties1, uncertainties2, _x3031, _ctx); /*(list<list<list<double>>>, list<list<list<double>>>)*/
  return kk_std_core_types__tuple2__box(_x3030, _ctx);
}

kk_std_core_types__tuple2_ kk_data_preprocessing__mlift1960_pre__process__data(kk_std_core__list temperatures1, kk_std_core__list uncertainties1, kk_std_core__list uncertainties2, kk_string_t _y_30, kk_context_t* _ctx) { /* (temperatures1 : list<maybe<double>>, uncertainties1 : list<maybe<double>>, uncertainties2 : list<maybe<double>>, string) -> <exn,fsys> (list<list<list<double>>>, list<list<list<double>>>) */ 
  kk_std_core__list x_2045;
  kk_std_core__list _b_2420_2417;
  kk_vector_t v_21689;
  kk_string_t _x3022;
  kk_define_string_literal(, _s3023, 1, "\n")
  _x3022 = kk_string_dup(_s3023); /*string*/
  v_21689 = kk_string_splitv(_y_30,_x3022,kk_context()); /*vector<string>*/
  _b_2420_2417 = kk_std_core_vlist(v_21689, kk_std_core_types__new_None(_ctx), _ctx); /*list<string>*/
  x_2045 = kk_std_core_map_5(_b_2420_2417, kk_data_preprocessing__new_mlift1960_pre__process__data_fun3024(_ctx), _ctx); /*list<maybe<double>>*/
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_2045, _ctx);
    kk_box_t _x3028 = kk_std_core_hnd_yield_extend(kk_data_preprocessing__new_mlift1960_pre__process__data_fun3029(temperatures1, uncertainties1, uncertainties2, _ctx), _ctx); /*3991*/
    return kk_std_core_types__tuple2__unbox(_x3028, _ctx);
  }
  return kk_data_preprocessing__mlift1959_pre__process__data(temperatures1, uncertainties1, uncertainties2, x_2045, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_data_preprocessing__mlift1961_pre__process__data_fun3035__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing__mlift1961_pre__process__data_fun3035(kk_function_t _fself, kk_box_t _b_2431, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing__new_mlift1961_pre__process__data_fun3035(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing__mlift1961_pre__process__data_fun3035, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_data_preprocessing__mlift1961_pre__process__data_fun3035(kk_function_t _fself, kk_box_t _b_2431, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x3036;
  kk_std_os_path__path _x3037 = kk_std_os_path__path_unbox(_b_2431, _ctx); /*std/os/path/path*/
  _x3036 = kk_std_os_path_string(_x3037, _ctx); /*string*/
  return kk_string_box(_x3036);
}


// lift anonymous function
struct kk_data_preprocessing__mlift1961_pre__process__data_fun3041__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing__mlift1961_pre__process__data_fun3041(kk_function_t _fself, kk_box_t _b_2436, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing__new_mlift1961_pre__process__data_fun3041(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing__mlift1961_pre__process__data_fun3041, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_data_preprocessing__mlift1961_pre__process__data_fun3041(kk_function_t _fself, kk_box_t _b_2436, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core__error _x3042;
  kk_string_t _x3043 = kk_string_unbox(_b_2436); /*string*/
  _x3042 = kk_std_os_file_read_text_file_err(_x3043, _ctx); /*error<string>*/
  return kk_std_core__error_box(_x3042, _ctx);
}


// lift anonymous function
struct kk_data_preprocessing__mlift1961_pre__process__data_fun3050__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing__mlift1961_pre__process__data_fun3050(kk_function_t _fself, kk_box_t _b_2439, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing__new_mlift1961_pre__process__data_fun3050(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing__mlift1961_pre__process__data_fun3050, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_data_preprocessing__mlift1961_pre__process__data_fun3050(kk_function_t _fself, kk_box_t _b_2439, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x3051;
  kk_std_os_path__path _x3052 = kk_std_os_path__path_unbox(_b_2439, _ctx); /*std/os/path/path*/
  _x3051 = kk_std_os_path_show(_x3052, _ctx); /*string*/
  return kk_string_box(_x3051);
}


// lift anonymous function
struct kk_data_preprocessing__mlift1961_pre__process__data_fun3054__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing__mlift1961_pre__process__data_fun3054(kk_function_t _fself, kk_box_t _b_2445, kk_box_t _b_2446, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing__new_mlift1961_pre__process__data_fun3054(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing__mlift1961_pre__process__data_fun3054, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_data_preprocessing__mlift1961_pre__process__data_fun3054(kk_function_t _fself, kk_box_t _b_2445, kk_box_t _b_2446, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core__exception _x3055;
  kk_std_core__exception _x3056 = kk_std_core__exception_unbox(_b_2445, _ctx); /*exception*/
  kk_string_t _x3057 = kk_string_unbox(_b_2446); /*string*/
  _x3055 = kk_std_os_file_prepend(_x3056, _x3057, _ctx); /*exception*/
  return kk_std_core__exception_box(_x3055, _ctx);
}


// lift anonymous function
struct kk_data_preprocessing__mlift1961_pre__process__data_fun3062__t {
  struct kk_function_s _base;
  kk_std_core__list temperatures1;
  kk_std_core__list uncertainties1;
  kk_std_core__list uncertainties2;
};
static kk_box_t kk_data_preprocessing__mlift1961_pre__process__data_fun3062(kk_function_t _fself, kk_box_t _b_2457, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing__new_mlift1961_pre__process__data_fun3062(kk_std_core__list temperatures1, kk_std_core__list uncertainties1, kk_std_core__list uncertainties2, kk_context_t* _ctx) {
  struct kk_data_preprocessing__mlift1961_pre__process__data_fun3062__t* _self = kk_function_alloc_as(struct kk_data_preprocessing__mlift1961_pre__process__data_fun3062__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_data_preprocessing__mlift1961_pre__process__data_fun3062, kk_context());
  _self->temperatures1 = temperatures1;
  _self->uncertainties1 = uncertainties1;
  _self->uncertainties2 = uncertainties2;
  return &_self->_base;
}

static kk_box_t kk_data_preprocessing__mlift1961_pre__process__data_fun3062(kk_function_t _fself, kk_box_t _b_2457, kk_context_t* _ctx) {
  struct kk_data_preprocessing__mlift1961_pre__process__data_fun3062__t* _self = kk_function_as(struct kk_data_preprocessing__mlift1961_pre__process__data_fun3062__t*, _fself);
  kk_std_core__list temperatures1 = _self->temperatures1; /* list<maybe<double>> */
  kk_std_core__list uncertainties1 = _self->uncertainties1; /* list<maybe<double>> */
  kk_std_core__list uncertainties2 = _self->uncertainties2; /* list<maybe<double>> */
  kk_drop_match(_self, {kk_std_core__list_dup(temperatures1);kk_std_core__list_dup(uncertainties1);kk_std_core__list_dup(uncertainties2);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x3063;
  kk_string_t _x3064 = kk_string_unbox(_b_2457); /*string*/
  _x3063 = kk_data_preprocessing__mlift1960_pre__process__data(temperatures1, uncertainties1, uncertainties2, _x3064, _ctx); /*(list<list<list<double>>>, list<list<list<double>>>)*/
  return kk_std_core_types__tuple2__box(_x3063, _ctx);
}

kk_std_core_types__tuple2_ kk_data_preprocessing__mlift1961_pre__process__data(kk_std_core__list uncertainties1, kk_std_core__list uncertainties2, kk_std_core__list temperatures1, kk_context_t* _ctx) { /* (uncertainties1 : list<maybe<double>>, uncertainties2 : list<maybe<double>>, temperatures1 : list<maybe<double>>) -> <exn,fsys,div> (list<list<list<double>>>, list<list<list<double>>>) */ 
  kk_string_t x_2049;
  kk_std_os_path__path path_2051;
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*std/core/hnd/evv<(<>)>*/;
  kk_std_os_path__path x2;
  kk_string_t _x3032;
  kk_define_string_literal(, _s3033, 32, "./data/temperature-readings2.txt")
  _x3032 = kk_string_dup(_s3033); /*string*/
  x2 = kk_std_os_path_path(_x3032, _ctx); /*std/os/path/path*/
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  path_2051 = x2; /*std/os/path/path*/
  kk_std_core__error _match_2827;
  kk_string_t _x1;
  kk_box_t _x3034;
  kk_box_t _x3038;
  kk_std_os_path__path _x3039 = kk_std_os_path__path_dup(path_2051); /*std/os/path/path*/
  _x3038 = kk_std_os_path__path_box(_x3039, _ctx); /*3238*/
  _x3034 = kk_std_core_hnd__open_none1(kk_data_preprocessing__new_mlift1961_pre__process__data_fun3035(_ctx), _x3038, _ctx); /*3239*/
  _x1 = kk_string_unbox(_x3034); /*string*/
  kk_box_t _x3040 = kk_std_core_hnd__open_none1(kk_data_preprocessing__new_mlift1961_pre__process__data_fun3041(_ctx), kk_string_box(_x1), _ctx); /*3239*/
  _match_2827 = kk_std_core__error_unbox(_x3040, _ctx); /*error<string>*/
  if (kk_std_core__is_Error(_match_2827)) {
    kk_std_core__exception exn = _match_2827._cons.Error.exception;
    kk_std_core__exception_dup(exn);
    kk_std_core__error_drop(_match_2827, _ctx);
    kk_std_core__error err_479;
    kk_std_core__exception _x3045;
    kk_string_t _x2;
    kk_string_t _x3046;
    kk_define_string_literal(, _s3047, 25, "unable to read text file ")
    _x3046 = kk_string_dup(_s3047); /*string*/
    kk_string_t _x3048;
    kk_box_t _x3049 = kk_std_core_hnd__open_none1(kk_data_preprocessing__new_mlift1961_pre__process__data_fun3050(_ctx), kk_std_os_path__path_box(path_2051, _ctx), _ctx); /*3239*/
    _x3048 = kk_string_unbox(_x3049); /*string*/
    _x2 = kk_std_core__lp__plus__plus__1_rp_(_x3046, _x3048, _ctx); /*string*/
    kk_box_t _x3053 = kk_std_core_hnd__open_none2(kk_data_preprocessing__new_mlift1961_pre__process__data_fun3054(_ctx), kk_std_core__exception_box(exn, _ctx), kk_string_box(_x2), _ctx); /*3333*/
    _x3045 = kk_std_core__exception_unbox(_x3053, _ctx); /*exception*/
    err_479 = kk_std_core__new_Error(_x3045, _ctx); /*error<string>*/
    if (kk_std_core__is_Error(err_479)) {
      kk_std_core__exception exn0 = err_479._cons.Error.exception;
      kk_std_core__exception_dup(exn0);
      kk_std_core__error_drop(err_479, _ctx);
      kk_box_t _x3058 = kk_std_core_throw_exn(exn0, _ctx); /*11740*/
      x_2049 = kk_string_unbox(_x3058); /*string*/
      goto _match3044;
    }
    kk_box_t _box_x2451 = err_479._cons.Ok.result;
    kk_string_t x0 = kk_string_unbox(_box_x2451);
    kk_string_dup(x0);
    kk_std_core__error_drop(err_479, _ctx);
    x_2049 = x0; /*string*/
    goto _match3044;
  }
  kk_box_t _box_x2452 = _match_2827._cons.Ok.result;
  kk_string_t content = kk_string_unbox(_box_x2452);
  kk_std_os_path__path_drop(path_2051, _ctx);
  kk_string_dup(content);
  kk_std_core__error_drop(_match_2827, _ctx);
  x_2049 = content; /*string*/
  _match3044: ;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_2049, _ctx);
    kk_box_t _x3061 = kk_std_core_hnd_yield_extend(kk_data_preprocessing__new_mlift1961_pre__process__data_fun3062(temperatures1, uncertainties1, uncertainties2, _ctx), _ctx); /*3991*/
    return kk_std_core_types__tuple2__unbox(_x3061, _ctx);
  }
  return kk_data_preprocessing__mlift1960_pre__process__data(temperatures1, uncertainties1, uncertainties2, x_2049, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_data_preprocessing__mlift1962_pre__process__data_fun3067__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing__mlift1962_pre__process__data_fun3067(kk_function_t _fself, kk_box_t _b_2465, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing__new_mlift1962_pre__process__data_fun3067(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing__mlift1962_pre__process__data_fun3067, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_data_preprocessing__mlift1962_pre__process__data_fun3068__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing__mlift1962_pre__process__data_fun3068(kk_function_t _fself, kk_box_t _b_2462, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing__new_mlift1962_pre__process__data_fun3068(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing__mlift1962_pre__process__data_fun3068, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_data_preprocessing__mlift1962_pre__process__data_fun3068(kk_function_t _fself, kk_box_t _b_2462, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core_types__maybe _x3069;
  kk_string_t _x3070 = kk_string_unbox(_b_2462); /*string*/
  _x3069 = kk_std_num_double_parse_double(_x3070, _ctx); /*maybe<double>*/
  return kk_std_core_types__maybe_box(_x3069, _ctx);
}
static kk_box_t kk_data_preprocessing__mlift1962_pre__process__data_fun3067(kk_function_t _fself, kk_box_t _b_2465, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return kk_std_core_hnd__open_none1(kk_data_preprocessing__new_mlift1962_pre__process__data_fun3068(_ctx), _b_2465, _ctx);
}


// lift anonymous function
struct kk_data_preprocessing__mlift1962_pre__process__data_fun3072__t {
  struct kk_function_s _base;
  kk_std_core__list uncertainties1;
  kk_std_core__list uncertainties2;
};
static kk_box_t kk_data_preprocessing__mlift1962_pre__process__data_fun3072(kk_function_t _fself, kk_box_t _b_2472, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing__new_mlift1962_pre__process__data_fun3072(kk_std_core__list uncertainties1, kk_std_core__list uncertainties2, kk_context_t* _ctx) {
  struct kk_data_preprocessing__mlift1962_pre__process__data_fun3072__t* _self = kk_function_alloc_as(struct kk_data_preprocessing__mlift1962_pre__process__data_fun3072__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_data_preprocessing__mlift1962_pre__process__data_fun3072, kk_context());
  _self->uncertainties1 = uncertainties1;
  _self->uncertainties2 = uncertainties2;
  return &_self->_base;
}

static kk_box_t kk_data_preprocessing__mlift1962_pre__process__data_fun3072(kk_function_t _fself, kk_box_t _b_2472, kk_context_t* _ctx) {
  struct kk_data_preprocessing__mlift1962_pre__process__data_fun3072__t* _self = kk_function_as(struct kk_data_preprocessing__mlift1962_pre__process__data_fun3072__t*, _fself);
  kk_std_core__list uncertainties1 = _self->uncertainties1; /* list<maybe<double>> */
  kk_std_core__list uncertainties2 = _self->uncertainties2; /* list<maybe<double>> */
  kk_drop_match(_self, {kk_std_core__list_dup(uncertainties1);kk_std_core__list_dup(uncertainties2);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x3073;
  kk_std_core__list _x3074 = kk_std_core__list_unbox(_b_2472, _ctx); /*list<maybe<double>>*/
  _x3073 = kk_data_preprocessing__mlift1961_pre__process__data(uncertainties1, uncertainties2, _x3074, _ctx); /*(list<list<list<double>>>, list<list<list<double>>>)*/
  return kk_std_core_types__tuple2__box(_x3073, _ctx);
}

kk_std_core_types__tuple2_ kk_data_preprocessing__mlift1962_pre__process__data(kk_std_core__list uncertainties1, kk_std_core__list uncertainties2, kk_string_t _y_28, kk_context_t* _ctx) { /* (uncertainties1 : list<maybe<double>>, uncertainties2 : list<maybe<double>>, string) -> <exn,fsys> (list<list<list<double>>>, list<list<list<double>>>) */ 
  kk_std_core__list x_2054;
  kk_std_core__list _b_2466_2463;
  kk_vector_t v_21689;
  kk_string_t _x3065;
  kk_define_string_literal(, _s3066, 1, "\n")
  _x3065 = kk_string_dup(_s3066); /*string*/
  v_21689 = kk_string_splitv(_y_28,_x3065,kk_context()); /*vector<string>*/
  _b_2466_2463 = kk_std_core_vlist(v_21689, kk_std_core_types__new_None(_ctx), _ctx); /*list<string>*/
  x_2054 = kk_std_core_map_5(_b_2466_2463, kk_data_preprocessing__new_mlift1962_pre__process__data_fun3067(_ctx), _ctx); /*list<maybe<double>>*/
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_2054, _ctx);
    kk_box_t _x3071 = kk_std_core_hnd_yield_extend(kk_data_preprocessing__new_mlift1962_pre__process__data_fun3072(uncertainties1, uncertainties2, _ctx), _ctx); /*3991*/
    return kk_std_core_types__tuple2__unbox(_x3071, _ctx);
  }
  return kk_data_preprocessing__mlift1961_pre__process__data(uncertainties1, uncertainties2, x_2054, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_data_preprocessing__mlift1963_pre__process__data_fun3078__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing__mlift1963_pre__process__data_fun3078(kk_function_t _fself, kk_box_t _b_2477, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing__new_mlift1963_pre__process__data_fun3078(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing__mlift1963_pre__process__data_fun3078, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_data_preprocessing__mlift1963_pre__process__data_fun3078(kk_function_t _fself, kk_box_t _b_2477, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x3079;
  kk_std_os_path__path _x3080 = kk_std_os_path__path_unbox(_b_2477, _ctx); /*std/os/path/path*/
  _x3079 = kk_std_os_path_string(_x3080, _ctx); /*string*/
  return kk_string_box(_x3079);
}


// lift anonymous function
struct kk_data_preprocessing__mlift1963_pre__process__data_fun3084__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing__mlift1963_pre__process__data_fun3084(kk_function_t _fself, kk_box_t _b_2482, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing__new_mlift1963_pre__process__data_fun3084(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing__mlift1963_pre__process__data_fun3084, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_data_preprocessing__mlift1963_pre__process__data_fun3084(kk_function_t _fself, kk_box_t _b_2482, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core__error _x3085;
  kk_string_t _x3086 = kk_string_unbox(_b_2482); /*string*/
  _x3085 = kk_std_os_file_read_text_file_err(_x3086, _ctx); /*error<string>*/
  return kk_std_core__error_box(_x3085, _ctx);
}


// lift anonymous function
struct kk_data_preprocessing__mlift1963_pre__process__data_fun3093__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing__mlift1963_pre__process__data_fun3093(kk_function_t _fself, kk_box_t _b_2485, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing__new_mlift1963_pre__process__data_fun3093(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing__mlift1963_pre__process__data_fun3093, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_data_preprocessing__mlift1963_pre__process__data_fun3093(kk_function_t _fself, kk_box_t _b_2485, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x3094;
  kk_std_os_path__path _x3095 = kk_std_os_path__path_unbox(_b_2485, _ctx); /*std/os/path/path*/
  _x3094 = kk_std_os_path_show(_x3095, _ctx); /*string*/
  return kk_string_box(_x3094);
}


// lift anonymous function
struct kk_data_preprocessing__mlift1963_pre__process__data_fun3097__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing__mlift1963_pre__process__data_fun3097(kk_function_t _fself, kk_box_t _b_2491, kk_box_t _b_2492, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing__new_mlift1963_pre__process__data_fun3097(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing__mlift1963_pre__process__data_fun3097, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_data_preprocessing__mlift1963_pre__process__data_fun3097(kk_function_t _fself, kk_box_t _b_2491, kk_box_t _b_2492, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core__exception _x3098;
  kk_std_core__exception _x3099 = kk_std_core__exception_unbox(_b_2491, _ctx); /*exception*/
  kk_string_t _x3100 = kk_string_unbox(_b_2492); /*string*/
  _x3098 = kk_std_os_file_prepend(_x3099, _x3100, _ctx); /*exception*/
  return kk_std_core__exception_box(_x3098, _ctx);
}


// lift anonymous function
struct kk_data_preprocessing__mlift1963_pre__process__data_fun3105__t {
  struct kk_function_s _base;
  kk_std_core__list uncertainties1;
  kk_std_core__list uncertainties2;
};
static kk_box_t kk_data_preprocessing__mlift1963_pre__process__data_fun3105(kk_function_t _fself, kk_box_t _b_2503, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing__new_mlift1963_pre__process__data_fun3105(kk_std_core__list uncertainties1, kk_std_core__list uncertainties2, kk_context_t* _ctx) {
  struct kk_data_preprocessing__mlift1963_pre__process__data_fun3105__t* _self = kk_function_alloc_as(struct kk_data_preprocessing__mlift1963_pre__process__data_fun3105__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_data_preprocessing__mlift1963_pre__process__data_fun3105, kk_context());
  _self->uncertainties1 = uncertainties1;
  _self->uncertainties2 = uncertainties2;
  return &_self->_base;
}

static kk_box_t kk_data_preprocessing__mlift1963_pre__process__data_fun3105(kk_function_t _fself, kk_box_t _b_2503, kk_context_t* _ctx) {
  struct kk_data_preprocessing__mlift1963_pre__process__data_fun3105__t* _self = kk_function_as(struct kk_data_preprocessing__mlift1963_pre__process__data_fun3105__t*, _fself);
  kk_std_core__list uncertainties1 = _self->uncertainties1; /* list<maybe<double>> */
  kk_std_core__list uncertainties2 = _self->uncertainties2; /* list<maybe<double>> */
  kk_drop_match(_self, {kk_std_core__list_dup(uncertainties1);kk_std_core__list_dup(uncertainties2);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x3106;
  kk_string_t _x3107 = kk_string_unbox(_b_2503); /*string*/
  _x3106 = kk_data_preprocessing__mlift1962_pre__process__data(uncertainties1, uncertainties2, _x3107, _ctx); /*(list<list<list<double>>>, list<list<list<double>>>)*/
  return kk_std_core_types__tuple2__box(_x3106, _ctx);
}

kk_std_core_types__tuple2_ kk_data_preprocessing__mlift1963_pre__process__data(kk_std_core__list uncertainties1, kk_std_core__list uncertainties2, kk_context_t* _ctx) { /* (uncertainties1 : list<maybe<double>>, uncertainties2 : list<maybe<double>>) -> <exn,fsys,div> (list<list<list<double>>>, list<list<list<double>>>) */ 
  kk_string_t x_2058;
  kk_std_os_path__path path_2060;
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*std/core/hnd/evv<(<>)>*/;
  kk_std_os_path__path x2;
  kk_string_t _x3075;
  kk_define_string_literal(, _s3076, 32, "./data/temperature-readings1.txt")
  _x3075 = kk_string_dup(_s3076); /*string*/
  x2 = kk_std_os_path_path(_x3075, _ctx); /*std/os/path/path*/
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  path_2060 = x2; /*std/os/path/path*/
  kk_std_core__error _match_2824;
  kk_string_t _x1;
  kk_box_t _x3077;
  kk_box_t _x3081;
  kk_std_os_path__path _x3082 = kk_std_os_path__path_dup(path_2060); /*std/os/path/path*/
  _x3081 = kk_std_os_path__path_box(_x3082, _ctx); /*3238*/
  _x3077 = kk_std_core_hnd__open_none1(kk_data_preprocessing__new_mlift1963_pre__process__data_fun3078(_ctx), _x3081, _ctx); /*3239*/
  _x1 = kk_string_unbox(_x3077); /*string*/
  kk_box_t _x3083 = kk_std_core_hnd__open_none1(kk_data_preprocessing__new_mlift1963_pre__process__data_fun3084(_ctx), kk_string_box(_x1), _ctx); /*3239*/
  _match_2824 = kk_std_core__error_unbox(_x3083, _ctx); /*error<string>*/
  if (kk_std_core__is_Error(_match_2824)) {
    kk_std_core__exception exn = _match_2824._cons.Error.exception;
    kk_std_core__exception_dup(exn);
    kk_std_core__error_drop(_match_2824, _ctx);
    kk_std_core__error err_479;
    kk_std_core__exception _x3088;
    kk_string_t _x2;
    kk_string_t _x3089;
    kk_define_string_literal(, _s3090, 25, "unable to read text file ")
    _x3089 = kk_string_dup(_s3090); /*string*/
    kk_string_t _x3091;
    kk_box_t _x3092 = kk_std_core_hnd__open_none1(kk_data_preprocessing__new_mlift1963_pre__process__data_fun3093(_ctx), kk_std_os_path__path_box(path_2060, _ctx), _ctx); /*3239*/
    _x3091 = kk_string_unbox(_x3092); /*string*/
    _x2 = kk_std_core__lp__plus__plus__1_rp_(_x3089, _x3091, _ctx); /*string*/
    kk_box_t _x3096 = kk_std_core_hnd__open_none2(kk_data_preprocessing__new_mlift1963_pre__process__data_fun3097(_ctx), kk_std_core__exception_box(exn, _ctx), kk_string_box(_x2), _ctx); /*3333*/
    _x3088 = kk_std_core__exception_unbox(_x3096, _ctx); /*exception*/
    err_479 = kk_std_core__new_Error(_x3088, _ctx); /*error<string>*/
    if (kk_std_core__is_Error(err_479)) {
      kk_std_core__exception exn0 = err_479._cons.Error.exception;
      kk_std_core__exception_dup(exn0);
      kk_std_core__error_drop(err_479, _ctx);
      kk_box_t _x3101 = kk_std_core_throw_exn(exn0, _ctx); /*11740*/
      x_2058 = kk_string_unbox(_x3101); /*string*/
      goto _match3087;
    }
    kk_box_t _box_x2497 = err_479._cons.Ok.result;
    kk_string_t x0 = kk_string_unbox(_box_x2497);
    kk_string_dup(x0);
    kk_std_core__error_drop(err_479, _ctx);
    x_2058 = x0; /*string*/
    goto _match3087;
  }
  kk_box_t _box_x2498 = _match_2824._cons.Ok.result;
  kk_string_t content = kk_string_unbox(_box_x2498);
  kk_std_os_path__path_drop(path_2060, _ctx);
  kk_string_dup(content);
  kk_std_core__error_drop(_match_2824, _ctx);
  x_2058 = content; /*string*/
  _match3087: ;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_2058, _ctx);
    kk_box_t _x3104 = kk_std_core_hnd_yield_extend(kk_data_preprocessing__new_mlift1963_pre__process__data_fun3105(uncertainties1, uncertainties2, _ctx), _ctx); /*3991*/
    return kk_std_core_types__tuple2__unbox(_x3104, _ctx);
  }
  return kk_data_preprocessing__mlift1962_pre__process__data(uncertainties1, uncertainties2, x_2058, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_data_preprocessing__mlift1964_pre__process__data_fun3110__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing__mlift1964_pre__process__data_fun3110(kk_function_t _fself, kk_box_t _b_2511, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing__new_mlift1964_pre__process__data_fun3110(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing__mlift1964_pre__process__data_fun3110, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_data_preprocessing__mlift1964_pre__process__data_fun3111__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing__mlift1964_pre__process__data_fun3111(kk_function_t _fself, kk_box_t _b_2508, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing__new_mlift1964_pre__process__data_fun3111(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing__mlift1964_pre__process__data_fun3111, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_data_preprocessing__mlift1964_pre__process__data_fun3111(kk_function_t _fself, kk_box_t _b_2508, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core_types__maybe _x3112;
  kk_string_t _x3113 = kk_string_unbox(_b_2508); /*string*/
  _x3112 = kk_std_num_double_parse_double(_x3113, _ctx); /*maybe<double>*/
  return kk_std_core_types__maybe_box(_x3112, _ctx);
}
static kk_box_t kk_data_preprocessing__mlift1964_pre__process__data_fun3110(kk_function_t _fself, kk_box_t _b_2511, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return kk_std_core_hnd__open_none1(kk_data_preprocessing__new_mlift1964_pre__process__data_fun3111(_ctx), _b_2511, _ctx);
}


// lift anonymous function
struct kk_data_preprocessing__mlift1964_pre__process__data_fun3115__t {
  struct kk_function_s _base;
  kk_std_core__list uncertainties1;
};
static kk_box_t kk_data_preprocessing__mlift1964_pre__process__data_fun3115(kk_function_t _fself, kk_box_t _b_2518, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing__new_mlift1964_pre__process__data_fun3115(kk_std_core__list uncertainties1, kk_context_t* _ctx) {
  struct kk_data_preprocessing__mlift1964_pre__process__data_fun3115__t* _self = kk_function_alloc_as(struct kk_data_preprocessing__mlift1964_pre__process__data_fun3115__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_data_preprocessing__mlift1964_pre__process__data_fun3115, kk_context());
  _self->uncertainties1 = uncertainties1;
  return &_self->_base;
}

static kk_box_t kk_data_preprocessing__mlift1964_pre__process__data_fun3115(kk_function_t _fself, kk_box_t _b_2518, kk_context_t* _ctx) {
  struct kk_data_preprocessing__mlift1964_pre__process__data_fun3115__t* _self = kk_function_as(struct kk_data_preprocessing__mlift1964_pre__process__data_fun3115__t*, _fself);
  kk_std_core__list uncertainties1 = _self->uncertainties1; /* list<maybe<double>> */
  kk_drop_match(_self, {kk_std_core__list_dup(uncertainties1);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x3116;
  kk_std_core__list _x3117 = kk_std_core__list_unbox(_b_2518, _ctx); /*list<maybe<double>>*/
  _x3116 = kk_data_preprocessing__mlift1963_pre__process__data(uncertainties1, _x3117, _ctx); /*(list<list<list<double>>>, list<list<list<double>>>)*/
  return kk_std_core_types__tuple2__box(_x3116, _ctx);
}

kk_std_core_types__tuple2_ kk_data_preprocessing__mlift1964_pre__process__data(kk_std_core__list uncertainties1, kk_string_t _y_26, kk_context_t* _ctx) { /* (uncertainties1 : list<maybe<double>>, string) -> <exn,fsys> (list<list<list<double>>>, list<list<list<double>>>) */ 
  kk_std_core__list x_2063;
  kk_std_core__list _b_2512_2509;
  kk_vector_t v_21689;
  kk_string_t _x3108;
  kk_define_string_literal(, _s3109, 1, "\n")
  _x3108 = kk_string_dup(_s3109); /*string*/
  v_21689 = kk_string_splitv(_y_26,_x3108,kk_context()); /*vector<string>*/
  _b_2512_2509 = kk_std_core_vlist(v_21689, kk_std_core_types__new_None(_ctx), _ctx); /*list<string>*/
  x_2063 = kk_std_core_map_5(_b_2512_2509, kk_data_preprocessing__new_mlift1964_pre__process__data_fun3110(_ctx), _ctx); /*list<maybe<double>>*/
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_2063, _ctx);
    kk_box_t _x3114 = kk_std_core_hnd_yield_extend(kk_data_preprocessing__new_mlift1964_pre__process__data_fun3115(uncertainties1, _ctx), _ctx); /*3991*/
    return kk_std_core_types__tuple2__unbox(_x3114, _ctx);
  }
  return kk_data_preprocessing__mlift1963_pre__process__data(uncertainties1, x_2063, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_data_preprocessing__mlift1965_pre__process__data_fun3121__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing__mlift1965_pre__process__data_fun3121(kk_function_t _fself, kk_box_t _b_2523, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing__new_mlift1965_pre__process__data_fun3121(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing__mlift1965_pre__process__data_fun3121, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_data_preprocessing__mlift1965_pre__process__data_fun3121(kk_function_t _fself, kk_box_t _b_2523, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x3122;
  kk_std_os_path__path _x3123 = kk_std_os_path__path_unbox(_b_2523, _ctx); /*std/os/path/path*/
  _x3122 = kk_std_os_path_string(_x3123, _ctx); /*string*/
  return kk_string_box(_x3122);
}


// lift anonymous function
struct kk_data_preprocessing__mlift1965_pre__process__data_fun3127__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing__mlift1965_pre__process__data_fun3127(kk_function_t _fself, kk_box_t _b_2528, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing__new_mlift1965_pre__process__data_fun3127(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing__mlift1965_pre__process__data_fun3127, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_data_preprocessing__mlift1965_pre__process__data_fun3127(kk_function_t _fself, kk_box_t _b_2528, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core__error _x3128;
  kk_string_t _x3129 = kk_string_unbox(_b_2528); /*string*/
  _x3128 = kk_std_os_file_read_text_file_err(_x3129, _ctx); /*error<string>*/
  return kk_std_core__error_box(_x3128, _ctx);
}


// lift anonymous function
struct kk_data_preprocessing__mlift1965_pre__process__data_fun3136__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing__mlift1965_pre__process__data_fun3136(kk_function_t _fself, kk_box_t _b_2531, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing__new_mlift1965_pre__process__data_fun3136(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing__mlift1965_pre__process__data_fun3136, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_data_preprocessing__mlift1965_pre__process__data_fun3136(kk_function_t _fself, kk_box_t _b_2531, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x3137;
  kk_std_os_path__path _x3138 = kk_std_os_path__path_unbox(_b_2531, _ctx); /*std/os/path/path*/
  _x3137 = kk_std_os_path_show(_x3138, _ctx); /*string*/
  return kk_string_box(_x3137);
}


// lift anonymous function
struct kk_data_preprocessing__mlift1965_pre__process__data_fun3140__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing__mlift1965_pre__process__data_fun3140(kk_function_t _fself, kk_box_t _b_2537, kk_box_t _b_2538, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing__new_mlift1965_pre__process__data_fun3140(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing__mlift1965_pre__process__data_fun3140, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_data_preprocessing__mlift1965_pre__process__data_fun3140(kk_function_t _fself, kk_box_t _b_2537, kk_box_t _b_2538, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core__exception _x3141;
  kk_std_core__exception _x3142 = kk_std_core__exception_unbox(_b_2537, _ctx); /*exception*/
  kk_string_t _x3143 = kk_string_unbox(_b_2538); /*string*/
  _x3141 = kk_std_os_file_prepend(_x3142, _x3143, _ctx); /*exception*/
  return kk_std_core__exception_box(_x3141, _ctx);
}


// lift anonymous function
struct kk_data_preprocessing__mlift1965_pre__process__data_fun3148__t {
  struct kk_function_s _base;
  kk_std_core__list uncertainties1;
};
static kk_box_t kk_data_preprocessing__mlift1965_pre__process__data_fun3148(kk_function_t _fself, kk_box_t _b_2549, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing__new_mlift1965_pre__process__data_fun3148(kk_std_core__list uncertainties1, kk_context_t* _ctx) {
  struct kk_data_preprocessing__mlift1965_pre__process__data_fun3148__t* _self = kk_function_alloc_as(struct kk_data_preprocessing__mlift1965_pre__process__data_fun3148__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_data_preprocessing__mlift1965_pre__process__data_fun3148, kk_context());
  _self->uncertainties1 = uncertainties1;
  return &_self->_base;
}

static kk_box_t kk_data_preprocessing__mlift1965_pre__process__data_fun3148(kk_function_t _fself, kk_box_t _b_2549, kk_context_t* _ctx) {
  struct kk_data_preprocessing__mlift1965_pre__process__data_fun3148__t* _self = kk_function_as(struct kk_data_preprocessing__mlift1965_pre__process__data_fun3148__t*, _fself);
  kk_std_core__list uncertainties1 = _self->uncertainties1; /* list<maybe<double>> */
  kk_drop_match(_self, {kk_std_core__list_dup(uncertainties1);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x3149;
  kk_string_t _x3150 = kk_string_unbox(_b_2549); /*string*/
  _x3149 = kk_data_preprocessing__mlift1964_pre__process__data(uncertainties1, _x3150, _ctx); /*(list<list<list<double>>>, list<list<list<double>>>)*/
  return kk_std_core_types__tuple2__box(_x3149, _ctx);
}

kk_std_core_types__tuple2_ kk_data_preprocessing__mlift1965_pre__process__data(kk_std_core__list uncertainties1, kk_context_t* _ctx) { /* (uncertainties1 : list<maybe<double>>) -> <exn,fsys,div> (list<list<list<double>>>, list<list<list<double>>>) */ 
  kk_string_t x_2067;
  kk_std_os_path__path path_2069;
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*std/core/hnd/evv<(<>)>*/;
  kk_std_os_path__path x2;
  kk_string_t _x3118;
  kk_define_string_literal(, _s3119, 37, "./data/measurement-uncertainties2.txt")
  _x3118 = kk_string_dup(_s3119); /*string*/
  x2 = kk_std_os_path_path(_x3118, _ctx); /*std/os/path/path*/
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  path_2069 = x2; /*std/os/path/path*/
  kk_std_core__error _match_2821;
  kk_string_t _x1;
  kk_box_t _x3120;
  kk_box_t _x3124;
  kk_std_os_path__path _x3125 = kk_std_os_path__path_dup(path_2069); /*std/os/path/path*/
  _x3124 = kk_std_os_path__path_box(_x3125, _ctx); /*3238*/
  _x3120 = kk_std_core_hnd__open_none1(kk_data_preprocessing__new_mlift1965_pre__process__data_fun3121(_ctx), _x3124, _ctx); /*3239*/
  _x1 = kk_string_unbox(_x3120); /*string*/
  kk_box_t _x3126 = kk_std_core_hnd__open_none1(kk_data_preprocessing__new_mlift1965_pre__process__data_fun3127(_ctx), kk_string_box(_x1), _ctx); /*3239*/
  _match_2821 = kk_std_core__error_unbox(_x3126, _ctx); /*error<string>*/
  if (kk_std_core__is_Error(_match_2821)) {
    kk_std_core__exception exn = _match_2821._cons.Error.exception;
    kk_std_core__exception_dup(exn);
    kk_std_core__error_drop(_match_2821, _ctx);
    kk_std_core__error err_479;
    kk_std_core__exception _x3131;
    kk_string_t _x2;
    kk_string_t _x3132;
    kk_define_string_literal(, _s3133, 25, "unable to read text file ")
    _x3132 = kk_string_dup(_s3133); /*string*/
    kk_string_t _x3134;
    kk_box_t _x3135 = kk_std_core_hnd__open_none1(kk_data_preprocessing__new_mlift1965_pre__process__data_fun3136(_ctx), kk_std_os_path__path_box(path_2069, _ctx), _ctx); /*3239*/
    _x3134 = kk_string_unbox(_x3135); /*string*/
    _x2 = kk_std_core__lp__plus__plus__1_rp_(_x3132, _x3134, _ctx); /*string*/
    kk_box_t _x3139 = kk_std_core_hnd__open_none2(kk_data_preprocessing__new_mlift1965_pre__process__data_fun3140(_ctx), kk_std_core__exception_box(exn, _ctx), kk_string_box(_x2), _ctx); /*3333*/
    _x3131 = kk_std_core__exception_unbox(_x3139, _ctx); /*exception*/
    err_479 = kk_std_core__new_Error(_x3131, _ctx); /*error<string>*/
    if (kk_std_core__is_Error(err_479)) {
      kk_std_core__exception exn0 = err_479._cons.Error.exception;
      kk_std_core__exception_dup(exn0);
      kk_std_core__error_drop(err_479, _ctx);
      kk_box_t _x3144 = kk_std_core_throw_exn(exn0, _ctx); /*11740*/
      x_2067 = kk_string_unbox(_x3144); /*string*/
      goto _match3130;
    }
    kk_box_t _box_x2543 = err_479._cons.Ok.result;
    kk_string_t x0 = kk_string_unbox(_box_x2543);
    kk_string_dup(x0);
    kk_std_core__error_drop(err_479, _ctx);
    x_2067 = x0; /*string*/
    goto _match3130;
  }
  kk_box_t _box_x2544 = _match_2821._cons.Ok.result;
  kk_string_t content = kk_string_unbox(_box_x2544);
  kk_std_os_path__path_drop(path_2069, _ctx);
  kk_string_dup(content);
  kk_std_core__error_drop(_match_2821, _ctx);
  x_2067 = content; /*string*/
  _match3130: ;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_2067, _ctx);
    kk_box_t _x3147 = kk_std_core_hnd_yield_extend(kk_data_preprocessing__new_mlift1965_pre__process__data_fun3148(uncertainties1, _ctx), _ctx); /*3991*/
    return kk_std_core_types__tuple2__unbox(_x3147, _ctx);
  }
  return kk_data_preprocessing__mlift1964_pre__process__data(uncertainties1, x_2067, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_data_preprocessing__mlift1966_pre__process__data_fun3153__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing__mlift1966_pre__process__data_fun3153(kk_function_t _fself, kk_box_t _b_2557, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing__new_mlift1966_pre__process__data_fun3153(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing__mlift1966_pre__process__data_fun3153, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_data_preprocessing__mlift1966_pre__process__data_fun3154__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing__mlift1966_pre__process__data_fun3154(kk_function_t _fself, kk_box_t _b_2554, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing__new_mlift1966_pre__process__data_fun3154(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing__mlift1966_pre__process__data_fun3154, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_data_preprocessing__mlift1966_pre__process__data_fun3154(kk_function_t _fself, kk_box_t _b_2554, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core_types__maybe _x3155;
  kk_string_t _x3156 = kk_string_unbox(_b_2554); /*string*/
  _x3155 = kk_std_num_double_parse_double(_x3156, _ctx); /*maybe<double>*/
  return kk_std_core_types__maybe_box(_x3155, _ctx);
}
static kk_box_t kk_data_preprocessing__mlift1966_pre__process__data_fun3153(kk_function_t _fself, kk_box_t _b_2557, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return kk_std_core_hnd__open_none1(kk_data_preprocessing__new_mlift1966_pre__process__data_fun3154(_ctx), _b_2557, _ctx);
}


// lift anonymous function
struct kk_data_preprocessing__mlift1966_pre__process__data_fun3158__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing__mlift1966_pre__process__data_fun3158(kk_function_t _fself, kk_box_t _b_2564, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing__new_mlift1966_pre__process__data_fun3158(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing__mlift1966_pre__process__data_fun3158, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_data_preprocessing__mlift1966_pre__process__data_fun3158(kk_function_t _fself, kk_box_t _b_2564, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core_types__tuple2_ _x3159;
  kk_std_core__list _x3160 = kk_std_core__list_unbox(_b_2564, _ctx); /*list<maybe<double>>*/
  _x3159 = kk_data_preprocessing__mlift1965_pre__process__data(_x3160, _ctx); /*(list<list<list<double>>>, list<list<list<double>>>)*/
  return kk_std_core_types__tuple2__box(_x3159, _ctx);
}

kk_std_core_types__tuple2_ kk_data_preprocessing__mlift1966_pre__process__data(kk_string_t _y_24, kk_context_t* _ctx) { /* (string) -> <exn,fsys> (list<list<list<double>>>, list<list<list<double>>>) */ 
  kk_std_core__list x_2072;
  kk_std_core__list _b_2558_2555;
  kk_vector_t v_21689;
  kk_string_t _x3151;
  kk_define_string_literal(, _s3152, 1, "\n")
  _x3151 = kk_string_dup(_s3152); /*string*/
  v_21689 = kk_string_splitv(_y_24,_x3151,kk_context()); /*vector<string>*/
  _b_2558_2555 = kk_std_core_vlist(v_21689, kk_std_core_types__new_None(_ctx), _ctx); /*list<string>*/
  x_2072 = kk_std_core_map_5(_b_2558_2555, kk_data_preprocessing__new_mlift1966_pre__process__data_fun3153(_ctx), _ctx); /*list<maybe<double>>*/
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_2072, _ctx);
    kk_box_t _x3157 = kk_std_core_hnd_yield_extend(kk_data_preprocessing__new_mlift1966_pre__process__data_fun3158(_ctx), _ctx); /*3991*/
    return kk_std_core_types__tuple2__unbox(_x3157, _ctx);
  }
  return kk_data_preprocessing__mlift1965_pre__process__data(x_2072, _ctx);
}


// lift anonymous function
struct kk_data_preprocessing_pre__process__data_fun3164__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing_pre__process__data_fun3164(kk_function_t _fself, kk_box_t _b_2568, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_pre__process__data_fun3164(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing_pre__process__data_fun3164, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_data_preprocessing_pre__process__data_fun3164(kk_function_t _fself, kk_box_t _b_2568, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x3165;
  kk_std_os_path__path _x3166 = kk_std_os_path__path_unbox(_b_2568, _ctx); /*std/os/path/path*/
  _x3165 = kk_std_os_path_string(_x3166, _ctx); /*string*/
  return kk_string_box(_x3165);
}


// lift anonymous function
struct kk_data_preprocessing_pre__process__data_fun3170__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing_pre__process__data_fun3170(kk_function_t _fself, kk_box_t _b_2573, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_pre__process__data_fun3170(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing_pre__process__data_fun3170, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_data_preprocessing_pre__process__data_fun3170(kk_function_t _fself, kk_box_t _b_2573, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core__error _x3171;
  kk_string_t _x3172 = kk_string_unbox(_b_2573); /*string*/
  _x3171 = kk_std_os_file_read_text_file_err(_x3172, _ctx); /*error<string>*/
  return kk_std_core__error_box(_x3171, _ctx);
}


// lift anonymous function
struct kk_data_preprocessing_pre__process__data_fun3179__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing_pre__process__data_fun3179(kk_function_t _fself, kk_box_t _b_2576, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_pre__process__data_fun3179(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing_pre__process__data_fun3179, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_data_preprocessing_pre__process__data_fun3179(kk_function_t _fself, kk_box_t _b_2576, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x3180;
  kk_std_os_path__path _x3181 = kk_std_os_path__path_unbox(_b_2576, _ctx); /*std/os/path/path*/
  _x3180 = kk_std_os_path_show(_x3181, _ctx); /*string*/
  return kk_string_box(_x3180);
}


// lift anonymous function
struct kk_data_preprocessing_pre__process__data_fun3183__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing_pre__process__data_fun3183(kk_function_t _fself, kk_box_t _b_2582, kk_box_t _b_2583, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_pre__process__data_fun3183(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing_pre__process__data_fun3183, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_data_preprocessing_pre__process__data_fun3183(kk_function_t _fself, kk_box_t _b_2582, kk_box_t _b_2583, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core__exception _x3184;
  kk_std_core__exception _x3185 = kk_std_core__exception_unbox(_b_2582, _ctx); /*exception*/
  kk_string_t _x3186 = kk_string_unbox(_b_2583); /*string*/
  _x3184 = kk_std_os_file_prepend(_x3185, _x3186, _ctx); /*exception*/
  return kk_std_core__exception_box(_x3184, _ctx);
}


// lift anonymous function
struct kk_data_preprocessing_pre__process__data_fun3191__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing_pre__process__data_fun3191(kk_function_t _fself, kk_box_t _b_2594, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_pre__process__data_fun3191(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing_pre__process__data_fun3191, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_data_preprocessing_pre__process__data_fun3191(kk_function_t _fself, kk_box_t _b_2594, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core_types__tuple2_ _x3192;
  kk_string_t _x3193 = kk_string_unbox(_b_2594); /*string*/
  _x3192 = kk_data_preprocessing__mlift1966_pre__process__data(_x3193, _ctx); /*(list<list<list<double>>>, list<list<list<double>>>)*/
  return kk_std_core_types__tuple2__box(_x3192, _ctx);
}


// lift anonymous function
struct kk_data_preprocessing_pre__process__data_fun3196__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing_pre__process__data_fun3196(kk_function_t _fself, kk_box_t _b_2600, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_pre__process__data_fun3196(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing_pre__process__data_fun3196, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_data_preprocessing_pre__process__data_fun3197__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing_pre__process__data_fun3197(kk_function_t _fself, kk_box_t _b_2597, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_pre__process__data_fun3197(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing_pre__process__data_fun3197, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_data_preprocessing_pre__process__data_fun3197(kk_function_t _fself, kk_box_t _b_2597, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core_types__maybe _x3198;
  kk_string_t _x3199 = kk_string_unbox(_b_2597); /*string*/
  _x3198 = kk_std_num_double_parse_double(_x3199, _ctx); /*maybe<double>*/
  return kk_std_core_types__maybe_box(_x3198, _ctx);
}
static kk_box_t kk_data_preprocessing_pre__process__data_fun3196(kk_function_t _fself, kk_box_t _b_2600, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return kk_std_core_hnd__open_none1(kk_data_preprocessing_new_pre__process__data_fun3197(_ctx), _b_2600, _ctx);
}


// lift anonymous function
struct kk_data_preprocessing_pre__process__data_fun3201__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing_pre__process__data_fun3201(kk_function_t _fself, kk_box_t _b_2607, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_pre__process__data_fun3201(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing_pre__process__data_fun3201, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_data_preprocessing_pre__process__data_fun3201(kk_function_t _fself, kk_box_t _b_2607, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core_types__tuple2_ _x3202;
  kk_std_core__list _x3203 = kk_std_core__list_unbox(_b_2607, _ctx); /*list<maybe<double>>*/
  _x3202 = kk_data_preprocessing__mlift1965_pre__process__data(_x3203, _ctx); /*(list<list<list<double>>>, list<list<list<double>>>)*/
  return kk_std_core_types__tuple2__box(_x3202, _ctx);
}


// lift anonymous function
struct kk_data_preprocessing_pre__process__data_fun3207__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing_pre__process__data_fun3207(kk_function_t _fself, kk_box_t _b_2610, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_pre__process__data_fun3207(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing_pre__process__data_fun3207, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_data_preprocessing_pre__process__data_fun3207(kk_function_t _fself, kk_box_t _b_2610, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x3208;
  kk_std_os_path__path _x3209 = kk_std_os_path__path_unbox(_b_2610, _ctx); /*std/os/path/path*/
  _x3208 = kk_std_os_path_string(_x3209, _ctx); /*string*/
  return kk_string_box(_x3208);
}


// lift anonymous function
struct kk_data_preprocessing_pre__process__data_fun3213__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing_pre__process__data_fun3213(kk_function_t _fself, kk_box_t _b_2615, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_pre__process__data_fun3213(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing_pre__process__data_fun3213, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_data_preprocessing_pre__process__data_fun3213(kk_function_t _fself, kk_box_t _b_2615, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core__error _x3214;
  kk_string_t _x3215 = kk_string_unbox(_b_2615); /*string*/
  _x3214 = kk_std_os_file_read_text_file_err(_x3215, _ctx); /*error<string>*/
  return kk_std_core__error_box(_x3214, _ctx);
}


// lift anonymous function
struct kk_data_preprocessing_pre__process__data_fun3222__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing_pre__process__data_fun3222(kk_function_t _fself, kk_box_t _b_2618, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_pre__process__data_fun3222(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing_pre__process__data_fun3222, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_data_preprocessing_pre__process__data_fun3222(kk_function_t _fself, kk_box_t _b_2618, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x3223;
  kk_std_os_path__path _x3224 = kk_std_os_path__path_unbox(_b_2618, _ctx); /*std/os/path/path*/
  _x3223 = kk_std_os_path_show(_x3224, _ctx); /*string*/
  return kk_string_box(_x3223);
}


// lift anonymous function
struct kk_data_preprocessing_pre__process__data_fun3226__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing_pre__process__data_fun3226(kk_function_t _fself, kk_box_t _b_2624, kk_box_t _b_2625, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_pre__process__data_fun3226(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing_pre__process__data_fun3226, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_data_preprocessing_pre__process__data_fun3226(kk_function_t _fself, kk_box_t _b_2624, kk_box_t _b_2625, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core__exception _x3227;
  kk_std_core__exception _x3228 = kk_std_core__exception_unbox(_b_2624, _ctx); /*exception*/
  kk_string_t _x3229 = kk_string_unbox(_b_2625); /*string*/
  _x3227 = kk_std_os_file_prepend(_x3228, _x3229, _ctx); /*exception*/
  return kk_std_core__exception_box(_x3227, _ctx);
}


// lift anonymous function
struct kk_data_preprocessing_pre__process__data_fun3234__t {
  struct kk_function_s _base;
  kk_std_core__list x3_2083;
};
static kk_box_t kk_data_preprocessing_pre__process__data_fun3234(kk_function_t _fself, kk_box_t _b_2636, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_pre__process__data_fun3234(kk_std_core__list x3_2083, kk_context_t* _ctx) {
  struct kk_data_preprocessing_pre__process__data_fun3234__t* _self = kk_function_alloc_as(struct kk_data_preprocessing_pre__process__data_fun3234__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_data_preprocessing_pre__process__data_fun3234, kk_context());
  _self->x3_2083 = x3_2083;
  return &_self->_base;
}

static kk_box_t kk_data_preprocessing_pre__process__data_fun3234(kk_function_t _fself, kk_box_t _b_2636, kk_context_t* _ctx) {
  struct kk_data_preprocessing_pre__process__data_fun3234__t* _self = kk_function_as(struct kk_data_preprocessing_pre__process__data_fun3234__t*, _fself);
  kk_std_core__list x3_2083 = _self->x3_2083; /* list<maybe<double>> */
  kk_drop_match(_self, {kk_std_core__list_dup(x3_2083);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x3235;
  kk_string_t _x3236 = kk_string_unbox(_b_2636); /*string*/
  _x3235 = kk_data_preprocessing__mlift1964_pre__process__data(x3_2083, _x3236, _ctx); /*(list<list<list<double>>>, list<list<list<double>>>)*/
  return kk_std_core_types__tuple2__box(_x3235, _ctx);
}


// lift anonymous function
struct kk_data_preprocessing_pre__process__data_fun3239__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing_pre__process__data_fun3239(kk_function_t _fself, kk_box_t _b_2642, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_pre__process__data_fun3239(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing_pre__process__data_fun3239, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_data_preprocessing_pre__process__data_fun3240__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing_pre__process__data_fun3240(kk_function_t _fself, kk_box_t _b_2639, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_pre__process__data_fun3240(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing_pre__process__data_fun3240, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_data_preprocessing_pre__process__data_fun3240(kk_function_t _fself, kk_box_t _b_2639, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core_types__maybe _x3241;
  kk_string_t _x3242 = kk_string_unbox(_b_2639); /*string*/
  _x3241 = kk_std_num_double_parse_double(_x3242, _ctx); /*maybe<double>*/
  return kk_std_core_types__maybe_box(_x3241, _ctx);
}
static kk_box_t kk_data_preprocessing_pre__process__data_fun3239(kk_function_t _fself, kk_box_t _b_2642, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return kk_std_core_hnd__open_none1(kk_data_preprocessing_new_pre__process__data_fun3240(_ctx), _b_2642, _ctx);
}


// lift anonymous function
struct kk_data_preprocessing_pre__process__data_fun3244__t {
  struct kk_function_s _base;
  kk_std_core__list x3_2083;
};
static kk_box_t kk_data_preprocessing_pre__process__data_fun3244(kk_function_t _fself, kk_box_t _b_2649, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_pre__process__data_fun3244(kk_std_core__list x3_2083, kk_context_t* _ctx) {
  struct kk_data_preprocessing_pre__process__data_fun3244__t* _self = kk_function_alloc_as(struct kk_data_preprocessing_pre__process__data_fun3244__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_data_preprocessing_pre__process__data_fun3244, kk_context());
  _self->x3_2083 = x3_2083;
  return &_self->_base;
}

static kk_box_t kk_data_preprocessing_pre__process__data_fun3244(kk_function_t _fself, kk_box_t _b_2649, kk_context_t* _ctx) {
  struct kk_data_preprocessing_pre__process__data_fun3244__t* _self = kk_function_as(struct kk_data_preprocessing_pre__process__data_fun3244__t*, _fself);
  kk_std_core__list x3_2083 = _self->x3_2083; /* list<maybe<double>> */
  kk_drop_match(_self, {kk_std_core__list_dup(x3_2083);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x3245;
  kk_std_core__list _x3246 = kk_std_core__list_unbox(_b_2649, _ctx); /*list<maybe<double>>*/
  _x3245 = kk_data_preprocessing__mlift1963_pre__process__data(x3_2083, _x3246, _ctx); /*(list<list<list<double>>>, list<list<list<double>>>)*/
  return kk_std_core_types__tuple2__box(_x3245, _ctx);
}


// lift anonymous function
struct kk_data_preprocessing_pre__process__data_fun3250__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing_pre__process__data_fun3250(kk_function_t _fself, kk_box_t _b_2652, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_pre__process__data_fun3250(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing_pre__process__data_fun3250, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_data_preprocessing_pre__process__data_fun3250(kk_function_t _fself, kk_box_t _b_2652, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x3251;
  kk_std_os_path__path _x3252 = kk_std_os_path__path_unbox(_b_2652, _ctx); /*std/os/path/path*/
  _x3251 = kk_std_os_path_string(_x3252, _ctx); /*string*/
  return kk_string_box(_x3251);
}


// lift anonymous function
struct kk_data_preprocessing_pre__process__data_fun3256__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing_pre__process__data_fun3256(kk_function_t _fself, kk_box_t _b_2657, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_pre__process__data_fun3256(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing_pre__process__data_fun3256, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_data_preprocessing_pre__process__data_fun3256(kk_function_t _fself, kk_box_t _b_2657, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core__error _x3257;
  kk_string_t _x3258 = kk_string_unbox(_b_2657); /*string*/
  _x3257 = kk_std_os_file_read_text_file_err(_x3258, _ctx); /*error<string>*/
  return kk_std_core__error_box(_x3257, _ctx);
}


// lift anonymous function
struct kk_data_preprocessing_pre__process__data_fun3265__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing_pre__process__data_fun3265(kk_function_t _fself, kk_box_t _b_2660, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_pre__process__data_fun3265(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing_pre__process__data_fun3265, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_data_preprocessing_pre__process__data_fun3265(kk_function_t _fself, kk_box_t _b_2660, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x3266;
  kk_std_os_path__path _x3267 = kk_std_os_path__path_unbox(_b_2660, _ctx); /*std/os/path/path*/
  _x3266 = kk_std_os_path_show(_x3267, _ctx); /*string*/
  return kk_string_box(_x3266);
}


// lift anonymous function
struct kk_data_preprocessing_pre__process__data_fun3269__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing_pre__process__data_fun3269(kk_function_t _fself, kk_box_t _b_2666, kk_box_t _b_2667, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_pre__process__data_fun3269(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing_pre__process__data_fun3269, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_data_preprocessing_pre__process__data_fun3269(kk_function_t _fself, kk_box_t _b_2666, kk_box_t _b_2667, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core__exception _x3270;
  kk_std_core__exception _x3271 = kk_std_core__exception_unbox(_b_2666, _ctx); /*exception*/
  kk_string_t _x3272 = kk_string_unbox(_b_2667); /*string*/
  _x3270 = kk_std_os_file_prepend(_x3271, _x3272, _ctx); /*exception*/
  return kk_std_core__exception_box(_x3270, _ctx);
}


// lift anonymous function
struct kk_data_preprocessing_pre__process__data_fun3277__t {
  struct kk_function_s _base;
  kk_std_core__list x3_2083;
  kk_std_core__list x7_2096;
};
static kk_box_t kk_data_preprocessing_pre__process__data_fun3277(kk_function_t _fself, kk_box_t _b_2678, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_pre__process__data_fun3277(kk_std_core__list x3_2083, kk_std_core__list x7_2096, kk_context_t* _ctx) {
  struct kk_data_preprocessing_pre__process__data_fun3277__t* _self = kk_function_alloc_as(struct kk_data_preprocessing_pre__process__data_fun3277__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_data_preprocessing_pre__process__data_fun3277, kk_context());
  _self->x3_2083 = x3_2083;
  _self->x7_2096 = x7_2096;
  return &_self->_base;
}

static kk_box_t kk_data_preprocessing_pre__process__data_fun3277(kk_function_t _fself, kk_box_t _b_2678, kk_context_t* _ctx) {
  struct kk_data_preprocessing_pre__process__data_fun3277__t* _self = kk_function_as(struct kk_data_preprocessing_pre__process__data_fun3277__t*, _fself);
  kk_std_core__list x3_2083 = _self->x3_2083; /* list<maybe<double>> */
  kk_std_core__list x7_2096 = _self->x7_2096; /* list<maybe<double>> */
  kk_drop_match(_self, {kk_std_core__list_dup(x3_2083);kk_std_core__list_dup(x7_2096);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x3278;
  kk_string_t _x3279 = kk_string_unbox(_b_2678); /*string*/
  _x3278 = kk_data_preprocessing__mlift1962_pre__process__data(x3_2083, x7_2096, _x3279, _ctx); /*(list<list<list<double>>>, list<list<list<double>>>)*/
  return kk_std_core_types__tuple2__box(_x3278, _ctx);
}


// lift anonymous function
struct kk_data_preprocessing_pre__process__data_fun3282__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing_pre__process__data_fun3282(kk_function_t _fself, kk_box_t _b_2684, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_pre__process__data_fun3282(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing_pre__process__data_fun3282, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_data_preprocessing_pre__process__data_fun3283__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing_pre__process__data_fun3283(kk_function_t _fself, kk_box_t _b_2681, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_pre__process__data_fun3283(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing_pre__process__data_fun3283, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_data_preprocessing_pre__process__data_fun3283(kk_function_t _fself, kk_box_t _b_2681, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core_types__maybe _x3284;
  kk_string_t _x3285 = kk_string_unbox(_b_2681); /*string*/
  _x3284 = kk_std_num_double_parse_double(_x3285, _ctx); /*maybe<double>*/
  return kk_std_core_types__maybe_box(_x3284, _ctx);
}
static kk_box_t kk_data_preprocessing_pre__process__data_fun3282(kk_function_t _fself, kk_box_t _b_2684, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return kk_std_core_hnd__open_none1(kk_data_preprocessing_new_pre__process__data_fun3283(_ctx), _b_2684, _ctx);
}


// lift anonymous function
struct kk_data_preprocessing_pre__process__data_fun3287__t {
  struct kk_function_s _base;
  kk_std_core__list x3_2083;
  kk_std_core__list x7_2096;
};
static kk_box_t kk_data_preprocessing_pre__process__data_fun3287(kk_function_t _fself, kk_box_t _b_2691, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_pre__process__data_fun3287(kk_std_core__list x3_2083, kk_std_core__list x7_2096, kk_context_t* _ctx) {
  struct kk_data_preprocessing_pre__process__data_fun3287__t* _self = kk_function_alloc_as(struct kk_data_preprocessing_pre__process__data_fun3287__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_data_preprocessing_pre__process__data_fun3287, kk_context());
  _self->x3_2083 = x3_2083;
  _self->x7_2096 = x7_2096;
  return &_self->_base;
}

static kk_box_t kk_data_preprocessing_pre__process__data_fun3287(kk_function_t _fself, kk_box_t _b_2691, kk_context_t* _ctx) {
  struct kk_data_preprocessing_pre__process__data_fun3287__t* _self = kk_function_as(struct kk_data_preprocessing_pre__process__data_fun3287__t*, _fself);
  kk_std_core__list x3_2083 = _self->x3_2083; /* list<maybe<double>> */
  kk_std_core__list x7_2096 = _self->x7_2096; /* list<maybe<double>> */
  kk_drop_match(_self, {kk_std_core__list_dup(x3_2083);kk_std_core__list_dup(x7_2096);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x3288;
  kk_std_core__list _x3289 = kk_std_core__list_unbox(_b_2691, _ctx); /*list<maybe<double>>*/
  _x3288 = kk_data_preprocessing__mlift1961_pre__process__data(x3_2083, x7_2096, _x3289, _ctx); /*(list<list<list<double>>>, list<list<list<double>>>)*/
  return kk_std_core_types__tuple2__box(_x3288, _ctx);
}


// lift anonymous function
struct kk_data_preprocessing_pre__process__data_fun3293__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing_pre__process__data_fun3293(kk_function_t _fself, kk_box_t _b_2694, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_pre__process__data_fun3293(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing_pre__process__data_fun3293, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_data_preprocessing_pre__process__data_fun3293(kk_function_t _fself, kk_box_t _b_2694, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x3294;
  kk_std_os_path__path _x3295 = kk_std_os_path__path_unbox(_b_2694, _ctx); /*std/os/path/path*/
  _x3294 = kk_std_os_path_string(_x3295, _ctx); /*string*/
  return kk_string_box(_x3294);
}


// lift anonymous function
struct kk_data_preprocessing_pre__process__data_fun3299__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing_pre__process__data_fun3299(kk_function_t _fself, kk_box_t _b_2699, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_pre__process__data_fun3299(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing_pre__process__data_fun3299, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_data_preprocessing_pre__process__data_fun3299(kk_function_t _fself, kk_box_t _b_2699, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core__error _x3300;
  kk_string_t _x3301 = kk_string_unbox(_b_2699); /*string*/
  _x3300 = kk_std_os_file_read_text_file_err(_x3301, _ctx); /*error<string>*/
  return kk_std_core__error_box(_x3300, _ctx);
}


// lift anonymous function
struct kk_data_preprocessing_pre__process__data_fun3308__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing_pre__process__data_fun3308(kk_function_t _fself, kk_box_t _b_2702, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_pre__process__data_fun3308(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing_pre__process__data_fun3308, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_data_preprocessing_pre__process__data_fun3308(kk_function_t _fself, kk_box_t _b_2702, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x3309;
  kk_std_os_path__path _x3310 = kk_std_os_path__path_unbox(_b_2702, _ctx); /*std/os/path/path*/
  _x3309 = kk_std_os_path_show(_x3310, _ctx); /*string*/
  return kk_string_box(_x3309);
}


// lift anonymous function
struct kk_data_preprocessing_pre__process__data_fun3312__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing_pre__process__data_fun3312(kk_function_t _fself, kk_box_t _b_2708, kk_box_t _b_2709, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_pre__process__data_fun3312(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing_pre__process__data_fun3312, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_data_preprocessing_pre__process__data_fun3312(kk_function_t _fself, kk_box_t _b_2708, kk_box_t _b_2709, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core__exception _x3313;
  kk_std_core__exception _x3314 = kk_std_core__exception_unbox(_b_2708, _ctx); /*exception*/
  kk_string_t _x3315 = kk_string_unbox(_b_2709); /*string*/
  _x3313 = kk_std_os_file_prepend(_x3314, _x3315, _ctx); /*exception*/
  return kk_std_core__exception_box(_x3313, _ctx);
}


// lift anonymous function
struct kk_data_preprocessing_pre__process__data_fun3320__t {
  struct kk_function_s _base;
  kk_std_core__list x13_2109;
  kk_std_core__list x3_2083;
  kk_std_core__list x7_2096;
};
static kk_box_t kk_data_preprocessing_pre__process__data_fun3320(kk_function_t _fself, kk_box_t _b_2720, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_pre__process__data_fun3320(kk_std_core__list x13_2109, kk_std_core__list x3_2083, kk_std_core__list x7_2096, kk_context_t* _ctx) {
  struct kk_data_preprocessing_pre__process__data_fun3320__t* _self = kk_function_alloc_as(struct kk_data_preprocessing_pre__process__data_fun3320__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_data_preprocessing_pre__process__data_fun3320, kk_context());
  _self->x13_2109 = x13_2109;
  _self->x3_2083 = x3_2083;
  _self->x7_2096 = x7_2096;
  return &_self->_base;
}

static kk_box_t kk_data_preprocessing_pre__process__data_fun3320(kk_function_t _fself, kk_box_t _b_2720, kk_context_t* _ctx) {
  struct kk_data_preprocessing_pre__process__data_fun3320__t* _self = kk_function_as(struct kk_data_preprocessing_pre__process__data_fun3320__t*, _fself);
  kk_std_core__list x13_2109 = _self->x13_2109; /* list<maybe<double>> */
  kk_std_core__list x3_2083 = _self->x3_2083; /* list<maybe<double>> */
  kk_std_core__list x7_2096 = _self->x7_2096; /* list<maybe<double>> */
  kk_drop_match(_self, {kk_std_core__list_dup(x13_2109);kk_std_core__list_dup(x3_2083);kk_std_core__list_dup(x7_2096);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x3321;
  kk_string_t _x3322 = kk_string_unbox(_b_2720); /*string*/
  _x3321 = kk_data_preprocessing__mlift1960_pre__process__data(x13_2109, x3_2083, x7_2096, _x3322, _ctx); /*(list<list<list<double>>>, list<list<list<double>>>)*/
  return kk_std_core_types__tuple2__box(_x3321, _ctx);
}


// lift anonymous function
struct kk_data_preprocessing_pre__process__data_fun3325__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing_pre__process__data_fun3325(kk_function_t _fself, kk_box_t _b_2726, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_pre__process__data_fun3325(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing_pre__process__data_fun3325, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_data_preprocessing_pre__process__data_fun3326__t {
  struct kk_function_s _base;
};
static kk_box_t kk_data_preprocessing_pre__process__data_fun3326(kk_function_t _fself, kk_box_t _b_2723, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_pre__process__data_fun3326(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_data_preprocessing_pre__process__data_fun3326, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_data_preprocessing_pre__process__data_fun3326(kk_function_t _fself, kk_box_t _b_2723, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core_types__maybe _x3327;
  kk_string_t _x3328 = kk_string_unbox(_b_2723); /*string*/
  _x3327 = kk_std_num_double_parse_double(_x3328, _ctx); /*maybe<double>*/
  return kk_std_core_types__maybe_box(_x3327, _ctx);
}
static kk_box_t kk_data_preprocessing_pre__process__data_fun3325(kk_function_t _fself, kk_box_t _b_2726, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return kk_std_core_hnd__open_none1(kk_data_preprocessing_new_pre__process__data_fun3326(_ctx), _b_2726, _ctx);
}


// lift anonymous function
struct kk_data_preprocessing_pre__process__data_fun3330__t {
  struct kk_function_s _base;
  kk_std_core__list x13_2109;
  kk_std_core__list x3_2083;
  kk_std_core__list x7_2096;
};
static kk_box_t kk_data_preprocessing_pre__process__data_fun3330(kk_function_t _fself, kk_box_t _b_2733, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_pre__process__data_fun3330(kk_std_core__list x13_2109, kk_std_core__list x3_2083, kk_std_core__list x7_2096, kk_context_t* _ctx) {
  struct kk_data_preprocessing_pre__process__data_fun3330__t* _self = kk_function_alloc_as(struct kk_data_preprocessing_pre__process__data_fun3330__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_data_preprocessing_pre__process__data_fun3330, kk_context());
  _self->x13_2109 = x13_2109;
  _self->x3_2083 = x3_2083;
  _self->x7_2096 = x7_2096;
  return &_self->_base;
}

static kk_box_t kk_data_preprocessing_pre__process__data_fun3330(kk_function_t _fself, kk_box_t _b_2733, kk_context_t* _ctx) {
  struct kk_data_preprocessing_pre__process__data_fun3330__t* _self = kk_function_as(struct kk_data_preprocessing_pre__process__data_fun3330__t*, _fself);
  kk_std_core__list x13_2109 = _self->x13_2109; /* list<maybe<double>> */
  kk_std_core__list x3_2083 = _self->x3_2083; /* list<maybe<double>> */
  kk_std_core__list x7_2096 = _self->x7_2096; /* list<maybe<double>> */
  kk_drop_match(_self, {kk_std_core__list_dup(x13_2109);kk_std_core__list_dup(x3_2083);kk_std_core__list_dup(x7_2096);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x3331;
  kk_std_core__list _x3332 = kk_std_core__list_unbox(_b_2733, _ctx); /*list<maybe<double>>*/
  _x3331 = kk_data_preprocessing__mlift1959_pre__process__data(x13_2109, x3_2083, x7_2096, _x3332, _ctx); /*(list<list<list<double>>>, list<list<list<double>>>)*/
  return kk_std_core_types__tuple2__box(_x3331, _ctx);
}


// lift anonymous function
struct kk_data_preprocessing_pre__process__data_fun3334__t {
  struct kk_function_s _base;
  kk_std_core__list maybe__temperatures;
};
static kk_box_t kk_data_preprocessing_pre__process__data_fun3334(kk_function_t _fself, kk_box_t _b_2751, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_pre__process__data_fun3334(kk_std_core__list maybe__temperatures, kk_context_t* _ctx) {
  struct kk_data_preprocessing_pre__process__data_fun3334__t* _self = kk_function_alloc_as(struct kk_data_preprocessing_pre__process__data_fun3334__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_data_preprocessing_pre__process__data_fun3334, kk_context());
  _self->maybe__temperatures = maybe__temperatures;
  return &_self->_base;
}

static kk_box_t kk_data_preprocessing_pre__process__data_fun3334(kk_function_t _fself, kk_box_t _b_2751, kk_context_t* _ctx) {
  struct kk_data_preprocessing_pre__process__data_fun3334__t* _self = kk_function_as(struct kk_data_preprocessing_pre__process__data_fun3334__t*, _fself);
  kk_std_core__list maybe__temperatures = _self->maybe__temperatures; /* list<maybe<double>> */
  kk_drop_match(_self, {kk_std_core__list_dup(maybe__temperatures);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x3335;
  kk_std_core__list _x3336 = kk_std_core__list_unbox(_b_2751, _ctx); /*list<double>*/
  _x3335 = kk_data_preprocessing__mlift1958_pre__process__data(maybe__temperatures, _x3336, _ctx); /*(list<list<list<double>>>, list<list<list<double>>>)*/
  return kk_std_core_types__tuple2__box(_x3335, _ctx);
}


// lift anonymous function
struct kk_data_preprocessing_pre__process__data_fun3338__t {
  struct kk_function_s _base;
  kk_std_core__list x19_2130;
};
static kk_box_t kk_data_preprocessing_pre__process__data_fun3338(kk_function_t _fself, kk_box_t _b_2753, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_pre__process__data_fun3338(kk_std_core__list x19_2130, kk_context_t* _ctx) {
  struct kk_data_preprocessing_pre__process__data_fun3338__t* _self = kk_function_alloc_as(struct kk_data_preprocessing_pre__process__data_fun3338__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_data_preprocessing_pre__process__data_fun3338, kk_context());
  _self->x19_2130 = x19_2130;
  return &_self->_base;
}

static kk_box_t kk_data_preprocessing_pre__process__data_fun3338(kk_function_t _fself, kk_box_t _b_2753, kk_context_t* _ctx) {
  struct kk_data_preprocessing_pre__process__data_fun3338__t* _self = kk_function_as(struct kk_data_preprocessing_pre__process__data_fun3338__t*, _fself);
  kk_std_core__list x19_2130 = _self->x19_2130; /* list<double> */
  kk_drop_match(_self, {kk_std_core__list_dup(x19_2130);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x3339;
  kk_std_core__list _x3340 = kk_std_core__list_unbox(_b_2753, _ctx); /*list<double>*/
  _x3339 = kk_data_preprocessing__mlift1957_pre__process__data(x19_2130, _x3340, _ctx); /*(list<list<list<double>>>, list<list<list<double>>>)*/
  return kk_std_core_types__tuple2__box(_x3339, _ctx);
}


// lift anonymous function
struct kk_data_preprocessing_pre__process__data_fun3342__t {
  struct kk_function_s _base;
  kk_std_core__list temperatures__by__year;
};
static kk_box_t kk_data_preprocessing_pre__process__data_fun3342(kk_function_t _fself, kk_box_t _b_2755, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_pre__process__data_fun3342(kk_std_core__list temperatures__by__year, kk_context_t* _ctx) {
  struct kk_data_preprocessing_pre__process__data_fun3342__t* _self = kk_function_alloc_as(struct kk_data_preprocessing_pre__process__data_fun3342__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_data_preprocessing_pre__process__data_fun3342, kk_context());
  _self->temperatures__by__year = temperatures__by__year;
  return &_self->_base;
}

static kk_box_t kk_data_preprocessing_pre__process__data_fun3342(kk_function_t _fself, kk_box_t _b_2755, kk_context_t* _ctx) {
  struct kk_data_preprocessing_pre__process__data_fun3342__t* _self = kk_function_as(struct kk_data_preprocessing_pre__process__data_fun3342__t*, _fself);
  kk_std_core__list temperatures__by__year = _self->temperatures__by__year; /* list<list<double>> */
  kk_drop_match(_self, {kk_std_core__list_dup(temperatures__by__year);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x3343;
  kk_std_core__list _x3344 = kk_std_core__list_unbox(_b_2755, _ctx); /*list<list<double>>*/
  _x3343 = kk_data_preprocessing__mlift1956_pre__process__data(temperatures__by__year, _x3344, _ctx); /*(list<list<list<double>>>, list<list<list<double>>>)*/
  return kk_std_core_types__tuple2__box(_x3343, _ctx);
}


// lift anonymous function
struct kk_data_preprocessing_pre__process__data_fun3346__t {
  struct kk_function_s _base;
  kk_std_core__list x25_2144;
};
static kk_box_t kk_data_preprocessing_pre__process__data_fun3346(kk_function_t _fself, kk_box_t _b_2757, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_pre__process__data_fun3346(kk_std_core__list x25_2144, kk_context_t* _ctx) {
  struct kk_data_preprocessing_pre__process__data_fun3346__t* _self = kk_function_alloc_as(struct kk_data_preprocessing_pre__process__data_fun3346__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_data_preprocessing_pre__process__data_fun3346, kk_context());
  _self->x25_2144 = x25_2144;
  return &_self->_base;
}

static kk_box_t kk_data_preprocessing_pre__process__data_fun3346(kk_function_t _fself, kk_box_t _b_2757, kk_context_t* _ctx) {
  struct kk_data_preprocessing_pre__process__data_fun3346__t* _self = kk_function_as(struct kk_data_preprocessing_pre__process__data_fun3346__t*, _fself);
  kk_std_core__list x25_2144 = _self->x25_2144; /* list<list<double>> */
  kk_drop_match(_self, {kk_std_core__list_dup(x25_2144);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x3347;
  kk_std_core__list _x3348 = kk_std_core__list_unbox(_b_2757, _ctx); /*list<list<double>>*/
  _x3347 = kk_data_preprocessing__mlift1955_pre__process__data(x25_2144, _x3348, _ctx); /*(list<list<list<double>>>, list<list<list<double>>>)*/
  return kk_std_core_types__tuple2__box(_x3347, _ctx);
}


// lift anonymous function
struct kk_data_preprocessing_pre__process__data_fun3349__t {
  struct kk_function_s _base;
  kk_function_t _b_2762_2759;
};
static kk_box_t kk_data_preprocessing_pre__process__data_fun3349(kk_function_t _fself, kk_box_t _b_2760, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_pre__process__data_fun3349(kk_function_t _b_2762_2759, kk_context_t* _ctx) {
  struct kk_data_preprocessing_pre__process__data_fun3349__t* _self = kk_function_alloc_as(struct kk_data_preprocessing_pre__process__data_fun3349__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_data_preprocessing_pre__process__data_fun3349, kk_context());
  _self->_b_2762_2759 = _b_2762_2759;
  return &_self->_base;
}

static kk_box_t kk_data_preprocessing_pre__process__data_fun3349(kk_function_t _fself, kk_box_t _b_2760, kk_context_t* _ctx) {
  struct kk_data_preprocessing_pre__process__data_fun3349__t* _self = kk_function_as(struct kk_data_preprocessing_pre__process__data_fun3349__t*, _fself);
  kk_function_t _b_2762_2759 = _self->_b_2762_2759; /* (list : list<double>) -> div list<list<double>> */
  kk_drop_match(_self, {kk_function_dup(_b_2762_2759);}, {}, _ctx)
  kk_std_core__list _x3350;
  kk_std_core__list _x3351 = kk_std_core__list_unbox(_b_2760, _ctx); /*list<double>*/
  _x3350 = kk_function_call(kk_std_core__list, (kk_function_t, kk_std_core__list, kk_context_t*), _b_2762_2759, (_b_2762_2759, _x3351, _ctx)); /*list<list<double>>*/
  return kk_std_core__list_box(_x3350, _ctx);
}


// lift anonymous function
struct kk_data_preprocessing_pre__process__data_fun3352__t {
  struct kk_function_s _base;
  kk_function_t _b_2767_2764;
};
static kk_box_t kk_data_preprocessing_pre__process__data_fun3352(kk_function_t _fself, kk_box_t _b_2765, kk_context_t* _ctx);
static kk_function_t kk_data_preprocessing_new_pre__process__data_fun3352(kk_function_t _b_2767_2764, kk_context_t* _ctx) {
  struct kk_data_preprocessing_pre__process__data_fun3352__t* _self = kk_function_alloc_as(struct kk_data_preprocessing_pre__process__data_fun3352__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_data_preprocessing_pre__process__data_fun3352, kk_context());
  _self->_b_2767_2764 = _b_2767_2764;
  return &_self->_base;
}

static kk_box_t kk_data_preprocessing_pre__process__data_fun3352(kk_function_t _fself, kk_box_t _b_2765, kk_context_t* _ctx) {
  struct kk_data_preprocessing_pre__process__data_fun3352__t* _self = kk_function_as(struct kk_data_preprocessing_pre__process__data_fun3352__t*, _fself);
  kk_function_t _b_2767_2764 = _self->_b_2767_2764; /* (list : list<double>) -> div list<list<double>> */
  kk_drop_match(_self, {kk_function_dup(_b_2767_2764);}, {}, _ctx)
  kk_std_core__list _x3353;
  kk_std_core__list _x3354 = kk_std_core__list_unbox(_b_2765, _ctx); /*list<double>*/
  _x3353 = kk_function_call(kk_std_core__list, (kk_function_t, kk_std_core__list, kk_context_t*), _b_2767_2764, (_b_2767_2764, _x3354, _ctx)); /*list<list<double>>*/
  return kk_std_core__list_box(_x3353, _ctx);
}

kk_std_core_types__tuple2_ kk_data_preprocessing_pre__process__data(kk_context_t* _ctx) { /* () -> <pure,fsys> (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>) */ 
  kk_string_t x_2076;
  kk_std_os_path__path path_2079;
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*std/core/hnd/evv<(<>)>*/;
  kk_std_os_path__path x2;
  kk_string_t _x3161;
  kk_define_string_literal(, _s3162, 37, "./data/measurement-uncertainties1.txt")
  _x3161 = kk_string_dup(_s3162); /*string*/
  x2 = kk_std_os_path_path(_x3161, _ctx); /*std/os/path/path*/
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  path_2079 = x2; /*std/os/path/path*/
  kk_std_core__error _match_2818;
  kk_string_t _x1;
  kk_box_t _x3163;
  kk_box_t _x3167;
  kk_std_os_path__path _x3168 = kk_std_os_path__path_dup(path_2079); /*std/os/path/path*/
  _x3167 = kk_std_os_path__path_box(_x3168, _ctx); /*3238*/
  _x3163 = kk_std_core_hnd__open_none1(kk_data_preprocessing_new_pre__process__data_fun3164(_ctx), _x3167, _ctx); /*3239*/
  _x1 = kk_string_unbox(_x3163); /*string*/
  kk_box_t _x3169 = kk_std_core_hnd__open_none1(kk_data_preprocessing_new_pre__process__data_fun3170(_ctx), kk_string_box(_x1), _ctx); /*3239*/
  _match_2818 = kk_std_core__error_unbox(_x3169, _ctx); /*error<string>*/
  if (kk_std_core__is_Error(_match_2818)) {
    kk_std_core__exception exn = _match_2818._cons.Error.exception;
    kk_std_core__exception_dup(exn);
    kk_std_core__error_drop(_match_2818, _ctx);
    kk_std_core__error err_479;
    kk_std_core__exception _x3174;
    kk_string_t _x2;
    kk_string_t _x3175;
    kk_define_string_literal(, _s3176, 25, "unable to read text file ")
    _x3175 = kk_string_dup(_s3176); /*string*/
    kk_string_t _x3177;
    kk_box_t _x3178 = kk_std_core_hnd__open_none1(kk_data_preprocessing_new_pre__process__data_fun3179(_ctx), kk_std_os_path__path_box(path_2079, _ctx), _ctx); /*3239*/
    _x3177 = kk_string_unbox(_x3178); /*string*/
    _x2 = kk_std_core__lp__plus__plus__1_rp_(_x3175, _x3177, _ctx); /*string*/
    kk_box_t _x3182 = kk_std_core_hnd__open_none2(kk_data_preprocessing_new_pre__process__data_fun3183(_ctx), kk_std_core__exception_box(exn, _ctx), kk_string_box(_x2), _ctx); /*3333*/
    _x3174 = kk_std_core__exception_unbox(_x3182, _ctx); /*exception*/
    err_479 = kk_std_core__new_Error(_x3174, _ctx); /*error<string>*/
    if (kk_std_core__is_Error(err_479)) {
      kk_std_core__exception exn0 = err_479._cons.Error.exception;
      kk_std_core__exception_dup(exn0);
      kk_std_core__error_drop(err_479, _ctx);
      kk_box_t _x3187 = kk_std_core_throw_exn(exn0, _ctx); /*11740*/
      x_2076 = kk_string_unbox(_x3187); /*string*/
      goto _match3173;
    }
    kk_box_t _box_x2588 = err_479._cons.Ok.result;
    kk_string_t x0 = kk_string_unbox(_box_x2588);
    kk_string_dup(x0);
    kk_std_core__error_drop(err_479, _ctx);
    x_2076 = x0; /*string*/
    goto _match3173;
  }
  kk_box_t _box_x2589 = _match_2818._cons.Ok.result;
  kk_string_t content = kk_string_unbox(_box_x2589);
  kk_std_os_path__path_drop(path_2079, _ctx);
  kk_string_dup(content);
  kk_std_core__error_drop(_match_2818, _ctx);
  x_2076 = content; /*string*/
  _match3173: ;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_2076, _ctx);
    kk_box_t _x3190 = kk_std_core_hnd_yield_extend(kk_data_preprocessing_new_pre__process__data_fun3191(_ctx), _ctx); /*3991*/
    return kk_std_core_types__tuple2__unbox(_x3190, _ctx);
  }
  kk_std_core__list x3_2083;
  kk_std_core__list _b_2601_2598;
  kk_vector_t v_21689;
  kk_string_t _x3194;
  kk_define_string_literal(, _s3195, 1, "\n")
  _x3194 = kk_string_dup(_s3195); /*string*/
  v_21689 = kk_string_splitv(x_2076,_x3194,kk_context()); /*vector<string>*/
  _b_2601_2598 = kk_std_core_vlist(v_21689, kk_std_core_types__new_None(_ctx), _ctx); /*list<string>*/
  x3_2083 = kk_std_core_map_5(_b_2601_2598, kk_data_preprocessing_new_pre__process__data_fun3196(_ctx), _ctx); /*list<maybe<double>>*/
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x3_2083, _ctx);
    kk_box_t _x3200 = kk_std_core_hnd_yield_extend(kk_data_preprocessing_new_pre__process__data_fun3201(_ctx), _ctx); /*3991*/
    return kk_std_core_types__tuple2__unbox(_x3200, _ctx);
  }
  kk_string_t x4_2089;
  kk_std_os_path__path path0_2092;
  kk_evv_t w0 = kk_evv_swap_create0(kk_context()); /*std/core/hnd/evv<(<>)>*/;
  kk_std_os_path__path x6;
  kk_string_t _x3204;
  kk_define_string_literal(, _s3205, 37, "./data/measurement-uncertainties2.txt")
  _x3204 = kk_string_dup(_s3205); /*string*/
  x6 = kk_std_os_path_path(_x3204, _ctx); /*std/os/path/path*/
  kk_unit_t keep0 = kk_Unit;
  kk_evv_set(w0,kk_context());
  path0_2092 = x6; /*std/os/path/path*/
  kk_std_core__error _match_2817;
  kk_string_t _x11;
  kk_box_t _x3206;
  kk_box_t _x3210;
  kk_std_os_path__path _x3211 = kk_std_os_path__path_dup(path0_2092); /*std/os/path/path*/
  _x3210 = kk_std_os_path__path_box(_x3211, _ctx); /*3238*/
  _x3206 = kk_std_core_hnd__open_none1(kk_data_preprocessing_new_pre__process__data_fun3207(_ctx), _x3210, _ctx); /*3239*/
  _x11 = kk_string_unbox(_x3206); /*string*/
  kk_box_t _x3212 = kk_std_core_hnd__open_none1(kk_data_preprocessing_new_pre__process__data_fun3213(_ctx), kk_string_box(_x11), _ctx); /*3239*/
  _match_2817 = kk_std_core__error_unbox(_x3212, _ctx); /*error<string>*/
  if (kk_std_core__is_Error(_match_2817)) {
    kk_std_core__exception exn1 = _match_2817._cons.Error.exception;
    kk_std_core__exception_dup(exn1);
    kk_std_core__error_drop(_match_2817, _ctx);
    kk_std_core__error err_4790;
    kk_std_core__exception _x3217;
    kk_string_t _x20;
    kk_string_t _x3218;
    kk_define_string_literal(, _s3219, 25, "unable to read text file ")
    _x3218 = kk_string_dup(_s3219); /*string*/
    kk_string_t _x3220;
    kk_box_t _x3221 = kk_std_core_hnd__open_none1(kk_data_preprocessing_new_pre__process__data_fun3222(_ctx), kk_std_os_path__path_box(path0_2092, _ctx), _ctx); /*3239*/
    _x3220 = kk_string_unbox(_x3221); /*string*/
    _x20 = kk_std_core__lp__plus__plus__1_rp_(_x3218, _x3220, _ctx); /*string*/
    kk_box_t _x3225 = kk_std_core_hnd__open_none2(kk_data_preprocessing_new_pre__process__data_fun3226(_ctx), kk_std_core__exception_box(exn1, _ctx), kk_string_box(_x20), _ctx); /*3333*/
    _x3217 = kk_std_core__exception_unbox(_x3225, _ctx); /*exception*/
    err_4790 = kk_std_core__new_Error(_x3217, _ctx); /*error<string>*/
    if (kk_std_core__is_Error(err_4790)) {
      kk_std_core__exception exn00 = err_4790._cons.Error.exception;
      kk_std_core__exception_dup(exn00);
      kk_std_core__error_drop(err_4790, _ctx);
      kk_box_t _x3230 = kk_std_core_throw_exn(exn00, _ctx); /*11740*/
      x4_2089 = kk_string_unbox(_x3230); /*string*/
      goto _match3216;
    }
    kk_box_t _box_x2630 = err_4790._cons.Ok.result;
    kk_string_t x5 = kk_string_unbox(_box_x2630);
    kk_string_dup(x5);
    kk_std_core__error_drop(err_4790, _ctx);
    x4_2089 = x5; /*string*/
    goto _match3216;
  }
  kk_box_t _box_x2631 = _match_2817._cons.Ok.result;
  kk_string_t content0 = kk_string_unbox(_box_x2631);
  kk_std_os_path__path_drop(path0_2092, _ctx);
  kk_string_dup(content0);
  kk_std_core__error_drop(_match_2817, _ctx);
  x4_2089 = content0; /*string*/
  _match3216: ;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x4_2089, _ctx);
    kk_box_t _x3233 = kk_std_core_hnd_yield_extend(kk_data_preprocessing_new_pre__process__data_fun3234(x3_2083, _ctx), _ctx); /*3991*/
    return kk_std_core_types__tuple2__unbox(_x3233, _ctx);
  }
  kk_std_core__list x7_2096;
  kk_std_core__list _b_2643_2640;
  kk_vector_t v_216890;
  kk_string_t _x3237;
  kk_define_string_literal(, _s3238, 1, "\n")
  _x3237 = kk_string_dup(_s3238); /*string*/
  v_216890 = kk_string_splitv(x4_2089,_x3237,kk_context()); /*vector<string>*/
  _b_2643_2640 = kk_std_core_vlist(v_216890, kk_std_core_types__new_None(_ctx), _ctx); /*list<string>*/
  x7_2096 = kk_std_core_map_5(_b_2643_2640, kk_data_preprocessing_new_pre__process__data_fun3239(_ctx), _ctx); /*list<maybe<double>>*/
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x7_2096, _ctx);
    kk_box_t _x3243 = kk_std_core_hnd_yield_extend(kk_data_preprocessing_new_pre__process__data_fun3244(x3_2083, _ctx), _ctx); /*3991*/
    return kk_std_core_types__tuple2__unbox(_x3243, _ctx);
  }
  kk_string_t x8_2102;
  kk_std_os_path__path path1_2105;
  kk_evv_t w1 = kk_evv_swap_create0(kk_context()); /*std/core/hnd/evv<(<>)>*/;
  kk_std_os_path__path x12;
  kk_string_t _x3247;
  kk_define_string_literal(, _s3248, 32, "./data/temperature-readings1.txt")
  _x3247 = kk_string_dup(_s3248); /*string*/
  x12 = kk_std_os_path_path(_x3247, _ctx); /*std/os/path/path*/
  kk_unit_t keep1 = kk_Unit;
  kk_evv_set(w1,kk_context());
  path1_2105 = x12; /*std/os/path/path*/
  kk_std_core__error _match_2816;
  kk_string_t _x13;
  kk_box_t _x3249;
  kk_box_t _x3253;
  kk_std_os_path__path _x3254 = kk_std_os_path__path_dup(path1_2105); /*std/os/path/path*/
  _x3253 = kk_std_os_path__path_box(_x3254, _ctx); /*3238*/
  _x3249 = kk_std_core_hnd__open_none1(kk_data_preprocessing_new_pre__process__data_fun3250(_ctx), _x3253, _ctx); /*3239*/
  _x13 = kk_string_unbox(_x3249); /*string*/
  kk_box_t _x3255 = kk_std_core_hnd__open_none1(kk_data_preprocessing_new_pre__process__data_fun3256(_ctx), kk_string_box(_x13), _ctx); /*3239*/
  _match_2816 = kk_std_core__error_unbox(_x3255, _ctx); /*error<string>*/
  if (kk_std_core__is_Error(_match_2816)) {
    kk_std_core__exception exn2 = _match_2816._cons.Error.exception;
    kk_std_core__exception_dup(exn2);
    kk_std_core__error_drop(_match_2816, _ctx);
    kk_std_core__error err_4791;
    kk_std_core__exception _x3260;
    kk_string_t _x21;
    kk_string_t _x3261;
    kk_define_string_literal(, _s3262, 25, "unable to read text file ")
    _x3261 = kk_string_dup(_s3262); /*string*/
    kk_string_t _x3263;
    kk_box_t _x3264 = kk_std_core_hnd__open_none1(kk_data_preprocessing_new_pre__process__data_fun3265(_ctx), kk_std_os_path__path_box(path1_2105, _ctx), _ctx); /*3239*/
    _x3263 = kk_string_unbox(_x3264); /*string*/
    _x21 = kk_std_core__lp__plus__plus__1_rp_(_x3261, _x3263, _ctx); /*string*/
    kk_box_t _x3268 = kk_std_core_hnd__open_none2(kk_data_preprocessing_new_pre__process__data_fun3269(_ctx), kk_std_core__exception_box(exn2, _ctx), kk_string_box(_x21), _ctx); /*3333*/
    _x3260 = kk_std_core__exception_unbox(_x3268, _ctx); /*exception*/
    err_4791 = kk_std_core__new_Error(_x3260, _ctx); /*error<string>*/
    if (kk_std_core__is_Error(err_4791)) {
      kk_std_core__exception exn01 = err_4791._cons.Error.exception;
      kk_std_core__exception_dup(exn01);
      kk_std_core__error_drop(err_4791, _ctx);
      kk_box_t _x3273 = kk_std_core_throw_exn(exn01, _ctx); /*11740*/
      x8_2102 = kk_string_unbox(_x3273); /*string*/
      goto _match3259;
    }
    kk_box_t _box_x2672 = err_4791._cons.Ok.result;
    kk_string_t x9 = kk_string_unbox(_box_x2672);
    kk_string_dup(x9);
    kk_std_core__error_drop(err_4791, _ctx);
    x8_2102 = x9; /*string*/
    goto _match3259;
  }
  kk_box_t _box_x2673 = _match_2816._cons.Ok.result;
  kk_string_t content1 = kk_string_unbox(_box_x2673);
  kk_std_os_path__path_drop(path1_2105, _ctx);
  kk_string_dup(content1);
  kk_std_core__error_drop(_match_2816, _ctx);
  x8_2102 = content1; /*string*/
  _match3259: ;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x8_2102, _ctx);
    kk_box_t _x3276 = kk_std_core_hnd_yield_extend(kk_data_preprocessing_new_pre__process__data_fun3277(x3_2083, x7_2096, _ctx), _ctx); /*3991*/
    return kk_std_core_types__tuple2__unbox(_x3276, _ctx);
  }
  kk_std_core__list x13_2109;
  kk_std_core__list _b_2685_2682;
  kk_vector_t v_216891;
  kk_string_t _x3280;
  kk_define_string_literal(, _s3281, 1, "\n")
  _x3280 = kk_string_dup(_s3281); /*string*/
  v_216891 = kk_string_splitv(x8_2102,_x3280,kk_context()); /*vector<string>*/
  _b_2685_2682 = kk_std_core_vlist(v_216891, kk_std_core_types__new_None(_ctx), _ctx); /*list<string>*/
  x13_2109 = kk_std_core_map_5(_b_2685_2682, kk_data_preprocessing_new_pre__process__data_fun3282(_ctx), _ctx); /*list<maybe<double>>*/
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x13_2109, _ctx);
    kk_box_t _x3286 = kk_std_core_hnd_yield_extend(kk_data_preprocessing_new_pre__process__data_fun3287(x3_2083, x7_2096, _ctx), _ctx); /*3991*/
    return kk_std_core_types__tuple2__unbox(_x3286, _ctx);
  }
  kk_string_t x14_2115;
  kk_std_os_path__path path2_2118;
  kk_evv_t w2 = kk_evv_swap_create0(kk_context()); /*std/core/hnd/evv<(<>)>*/;
  kk_std_os_path__path x17;
  kk_string_t _x3290;
  kk_define_string_literal(, _s3291, 32, "./data/temperature-readings2.txt")
  _x3290 = kk_string_dup(_s3291); /*string*/
  x17 = kk_std_os_path_path(_x3290, _ctx); /*std/os/path/path*/
  kk_unit_t keep2 = kk_Unit;
  kk_evv_set(w2,kk_context());
  path2_2118 = x17; /*std/os/path/path*/
  kk_std_core__error _match_2815;
  kk_string_t _x15;
  kk_box_t _x3292;
  kk_box_t _x3296;
  kk_std_os_path__path _x3297 = kk_std_os_path__path_dup(path2_2118); /*std/os/path/path*/
  _x3296 = kk_std_os_path__path_box(_x3297, _ctx); /*3238*/
  _x3292 = kk_std_core_hnd__open_none1(kk_data_preprocessing_new_pre__process__data_fun3293(_ctx), _x3296, _ctx); /*3239*/
  _x15 = kk_string_unbox(_x3292); /*string*/
  kk_box_t _x3298 = kk_std_core_hnd__open_none1(kk_data_preprocessing_new_pre__process__data_fun3299(_ctx), kk_string_box(_x15), _ctx); /*3239*/
  _match_2815 = kk_std_core__error_unbox(_x3298, _ctx); /*error<string>*/
  if (kk_std_core__is_Error(_match_2815)) {
    kk_std_core__exception exn3 = _match_2815._cons.Error.exception;
    kk_std_core__exception_dup(exn3);
    kk_std_core__error_drop(_match_2815, _ctx);
    kk_std_core__error err_4792;
    kk_std_core__exception _x3303;
    kk_string_t _x22;
    kk_string_t _x3304;
    kk_define_string_literal(, _s3305, 25, "unable to read text file ")
    _x3304 = kk_string_dup(_s3305); /*string*/
    kk_string_t _x3306;
    kk_box_t _x3307 = kk_std_core_hnd__open_none1(kk_data_preprocessing_new_pre__process__data_fun3308(_ctx), kk_std_os_path__path_box(path2_2118, _ctx), _ctx); /*3239*/
    _x3306 = kk_string_unbox(_x3307); /*string*/
    _x22 = kk_std_core__lp__plus__plus__1_rp_(_x3304, _x3306, _ctx); /*string*/
    kk_box_t _x3311 = kk_std_core_hnd__open_none2(kk_data_preprocessing_new_pre__process__data_fun3312(_ctx), kk_std_core__exception_box(exn3, _ctx), kk_string_box(_x22), _ctx); /*3333*/
    _x3303 = kk_std_core__exception_unbox(_x3311, _ctx); /*exception*/
    err_4792 = kk_std_core__new_Error(_x3303, _ctx); /*error<string>*/
    if (kk_std_core__is_Error(err_4792)) {
      kk_std_core__exception exn02 = err_4792._cons.Error.exception;
      kk_std_core__exception_dup(exn02);
      kk_std_core__error_drop(err_4792, _ctx);
      kk_box_t _x3316 = kk_std_core_throw_exn(exn02, _ctx); /*11740*/
      x14_2115 = kk_string_unbox(_x3316); /*string*/
      goto _match3302;
    }
    kk_box_t _box_x2714 = err_4792._cons.Ok.result;
    kk_string_t x15 = kk_string_unbox(_box_x2714);
    kk_string_dup(x15);
    kk_std_core__error_drop(err_4792, _ctx);
    x14_2115 = x15; /*string*/
    goto _match3302;
  }
  kk_box_t _box_x2715 = _match_2815._cons.Ok.result;
  kk_string_t content2 = kk_string_unbox(_box_x2715);
  kk_std_os_path__path_drop(path2_2118, _ctx);
  kk_string_dup(content2);
  kk_std_core__error_drop(_match_2815, _ctx);
  x14_2115 = content2; /*string*/
  _match3302: ;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x14_2115, _ctx);
    kk_box_t _x3319 = kk_std_core_hnd_yield_extend(kk_data_preprocessing_new_pre__process__data_fun3320(x13_2109, x3_2083, x7_2096, _ctx), _ctx); /*3991*/
    return kk_std_core_types__tuple2__unbox(_x3319, _ctx);
  }
  kk_std_core__list x18_2122;
  kk_std_core__list _b_2727_2724;
  kk_vector_t v_216892;
  kk_string_t _x3323;
  kk_define_string_literal(, _s3324, 1, "\n")
  _x3323 = kk_string_dup(_s3324); /*string*/
  v_216892 = kk_string_splitv(x14_2115,_x3323,kk_context()); /*vector<string>*/
  _b_2727_2724 = kk_std_core_vlist(v_216892, kk_std_core_types__new_None(_ctx), _ctx); /*list<string>*/
  x18_2122 = kk_std_core_map_5(_b_2727_2724, kk_data_preprocessing_new_pre__process__data_fun3325(_ctx), _ctx); /*list<maybe<double>>*/
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x18_2122, _ctx);
    kk_box_t _x3329 = kk_std_core_hnd_yield_extend(kk_data_preprocessing_new_pre__process__data_fun3330(x13_2109, x3_2083, x7_2096, _ctx), _ctx); /*3991*/
    return kk_std_core_types__tuple2__unbox(_x3329, _ctx);
  }
  kk_std_core__list maybe__uncertainties;
  kk_std_core__list xss_2128;
  kk_std_core__list _b_2739_2737 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core__list_box(x7_2096, _ctx), kk_std_core__new_Nil(_ctx), _ctx); /*list<list<maybe<double>>>*/;
  xss_2128 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core__list_box(x3_2083, _ctx), _b_2739_2737, _ctx); /*list<list<maybe<double>>>*/
  maybe__uncertainties = kk_std_core__lift21045_concat(kk_std_core__new_Nil(_ctx), xss_2128, _ctx); /*list<maybe<double>>*/
  kk_std_core__list maybe__temperatures;
  kk_std_core__list xss0_2129;
  kk_std_core__list _b_2747_2745 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core__list_box(x18_2122, _ctx), kk_std_core__new_Nil(_ctx), _ctx); /*list<list<maybe<double>>>*/;
  xss0_2129 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core__list_box(x13_2109, _ctx), _b_2747_2745, _ctx); /*list<list<maybe<double>>>*/
  maybe__temperatures = kk_std_core__lift21045_concat(kk_std_core__new_Nil(_ctx), xss0_2129, _ctx); /*list<maybe<double>>*/
  kk_std_core__list x19_2130 = kk_data_preprocessing_remove__maybes(maybe__uncertainties, kk_std_core__new_Nil(_ctx), _ctx); /*list<double>*/;
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x19_2130, _ctx);
    kk_box_t _x3333 = kk_std_core_hnd_yield_extend(kk_data_preprocessing_new_pre__process__data_fun3334(maybe__temperatures, _ctx), _ctx); /*3991*/
    return kk_std_core_types__tuple2__unbox(_x3333, _ctx);
  }
  kk_std_core__list x20_2134 = kk_data_preprocessing_remove__maybes(maybe__temperatures, kk_std_core__new_Nil(_ctx), _ctx); /*list<double>*/;
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x20_2134, _ctx);
    kk_box_t _x3337 = kk_std_core_hnd_yield_extend(kk_data_preprocessing_new_pre__process__data_fun3338(x19_2130, _ctx), _ctx); /*3991*/
    return kk_std_core_types__tuple2__unbox(_x3337, _ctx);
  }
  kk_std_core__list uncertainties__by__year;
  kk_evv_t w3 = kk_evv_swap_create0(kk_context()); /*std/core/hnd/evv<(<>)>*/;
  kk_std_core__list x22 = kk_data_preprocessing_list__of__lists(x19_2130, kk_integer_from_small(12), _ctx); /*list<list<double>>*/;
  kk_unit_t keep3 = kk_Unit;
  kk_evv_set(w3,kk_context());
  uncertainties__by__year = x22; /*list<list<double>>*/
  kk_std_core__list temperatures__by__year;
  kk_evv_t w4 = kk_evv_swap_create0(kk_context()); /*std/core/hnd/evv<(<>)>*/;
  kk_std_core__list x24 = kk_data_preprocessing_list__of__lists(x20_2134, kk_integer_from_small(12), _ctx); /*list<list<double>>*/;
  kk_unit_t keep4 = kk_Unit;
  kk_evv_set(w4,kk_context());
  temperatures__by__year = x24; /*list<list<double>>*/
  kk_std_core__list x25_2144 = kk_data_preprocessing_months(uncertainties__by__year, _ctx); /*list<list<double>>*/;
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x25_2144, _ctx);
    kk_box_t _x3341 = kk_std_core_hnd_yield_extend(kk_data_preprocessing_new_pre__process__data_fun3342(temperatures__by__year, _ctx), _ctx); /*3991*/
    return kk_std_core_types__tuple2__unbox(_x3341, _ctx);
  }
  kk_std_core__list x26_2148 = kk_data_preprocessing_months(temperatures__by__year, _ctx); /*list<list<double>>*/;
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x26_2148, _ctx);
    kk_box_t _x3345 = kk_std_core_hnd_yield_extend(kk_data_preprocessing_new_pre__process__data_fun3346(x25_2144, _ctx), _ctx); /*3991*/
    return kk_std_core_types__tuple2__unbox(_x3345, _ctx);
  }
  kk_std_core__list grouped__uncertainties__by__month;
  kk_evv_t w5 = kk_evv_swap_create0(kk_context()); /*std/core/hnd/evv<(<>)>*/;
  kk_std_core__list x28;
  kk_function_t _b_2762_2759 = kk_data_preprocessing_list__of__lists__thunk(kk_integer_from_small(20), _ctx); /*(list : list<double>) -> div list<list<double>>*/;
  x28 = kk_std_core_map_5(x25_2144, kk_data_preprocessing_new_pre__process__data_fun3349(_b_2762_2759, _ctx), _ctx); /*list<list<list<double>>>*/
  kk_unit_t keep5 = kk_Unit;
  kk_evv_set(w5,kk_context());
  grouped__uncertainties__by__month = x28; /*list<list<list<double>>>*/
  kk_std_core__list grouped__temperatures__by__month;
  kk_evv_t w6 = kk_evv_swap_create0(kk_context()); /*std/core/hnd/evv<(<>)>*/;
  kk_std_core__list x30;
  kk_function_t _b_2767_2764 = kk_data_preprocessing_list__of__lists__thunk(kk_integer_from_small(20), _ctx); /*(list : list<double>) -> div list<list<double>>*/;
  x30 = kk_std_core_map_5(x26_2148, kk_data_preprocessing_new_pre__process__data_fun3352(_b_2767_2764, _ctx), _ctx); /*list<list<list<double>>>*/
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
