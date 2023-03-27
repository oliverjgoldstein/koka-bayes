// Koka generated module: "sampling", koka version: 2.1.3
#include "sampling.h"


// lift anonymous function
struct kk_sampling_sum__weights_fun1107__t {
  struct kk_function_s _base;
};
static kk_box_t kk_sampling_sum__weights_fun1107(kk_function_t _fself, kk_box_t _b_884, kk_box_t _b_885, kk_context_t* _ctx);
static kk_function_t kk_sampling_new_sum__weights_fun1107(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_sampling_sum__weights_fun1107, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_sampling_sum__weights_fun1107(kk_function_t _fself, kk_box_t _b_884, kk_box_t _b_885, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_effects_dash_and_dash_types__exp _x1108;
  kk_std_core_types__tuple2_ _match_1105 = kk_std_core_types__tuple2__unbox(_b_885, _ctx); /*(effects-and-types/exp, 86)*/;
  kk_box_t _box_x880 = _match_1105.fst;
  kk_effects_dash_and_dash_types__exp w = kk_effects_dash_and_dash_types__exp_unbox(_box_x880, NULL);
  kk_std_core_types__tuple2__drop(_match_1105, _ctx);
  kk_effects_dash_and_dash_types__exp _x1110 = kk_effects_dash_and_dash_types__exp_unbox(_b_884, _ctx); /*effects-and-types/exp*/
  _x1108 = kk_exponents_plus__exp(_x1110, w, _ctx); /*effects-and-types/exp*/
  return kk_effects_dash_and_dash_types__exp_box(_x1108, _ctx);
}

kk_effects_dash_and_dash_types__exp kk_sampling_sum__weights(kk_std_core__list histogram, kk_context_t* _ctx) { /* forall<a> (histogram : effects-and-types/histogram<a>) -> effects-and-types/exp */ 
  kk_box_t _x1106 = kk_std_core_foldl(histogram, kk_effects_dash_and_dash_types__exp_box(kk_exponents_zero_exp, _ctx), kk_sampling_new_sum__weights_fun1107(_ctx), _ctx); /*15010*/
  return kk_effects_dash_and_dash_types__exp_unbox(_x1106, _ctx);
}
 
// monadic lift

kk_box_t kk_sampling__mlift823_populate(kk_function_t model, kk_unit_t wild__, kk_context_t* _ctx) { /* forall<a,e> (model : () -> <effects-and-types/score|e> a, wild_ : ()) -> <effects-and-types/score|e> a */ 
  return kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), model, (model, _ctx));
}


// lift anonymous function
struct kk_sampling_populate_fun1112__t {
  struct kk_function_s _base;
  kk_integer_t k;
  kk_function_t model;
};
static kk_box_t kk_sampling_populate_fun1112(kk_function_t _fself, kk_integer_t _b_920, kk_context_t* _ctx);
static kk_function_t kk_sampling_new_populate_fun1112(kk_integer_t k, kk_function_t model, kk_context_t* _ctx) {
  struct kk_sampling_populate_fun1112__t* _self = kk_function_alloc_as(struct kk_sampling_populate_fun1112__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_sampling_populate_fun1112, kk_context());
  _self->k = k;
  _self->model = model;
  return &_self->_base;
}



// lift anonymous function
struct kk_sampling_populate_fun1115__t {
  struct kk_function_s _base;
  kk_integer_t k;
  kk_function_t model;
};
static kk_box_t kk_sampling_populate_fun1115(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_sampling_new_populate_fun1115(kk_integer_t k, kk_function_t model, kk_context_t* _ctx) {
  struct kk_sampling_populate_fun1115__t* _self = kk_function_alloc_as(struct kk_sampling_populate_fun1115__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_sampling_populate_fun1115, kk_context());
  _self->k = k;
  _self->model = model;
  return &_self->_base;
}



// lift anonymous function
struct kk_sampling_populate_fun1119__t {
  struct kk_function_s _base;
};
static kk_box_t kk_sampling_populate_fun1119(kk_function_t _fself, kk_box_t _b_894, kk_box_t _b_895, kk_context_t* _ctx);
static kk_function_t kk_sampling_new_populate_fun1119(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_sampling_populate_fun1119, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_sampling_populate_fun1119(kk_function_t _fself, kk_box_t _b_894, kk_box_t _b_895, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_effects_dash_and_dash_types__exp _x1120;
  kk_effects_dash_and_dash_types__exp _x1121 = kk_effects_dash_and_dash_types__exp_unbox(_b_894, _ctx); /*effects-and-types/exp*/
  kk_effects_dash_and_dash_types__exp _x1122 = kk_effects_dash_and_dash_types__exp_unbox(_b_895, _ctx); /*effects-and-types/exp*/
  _x1120 = kk_exponents_div__exp(_x1121, _x1122, _ctx); /*effects-and-types/exp*/
  return kk_effects_dash_and_dash_types__exp_box(_x1120, _ctx);
}


// lift anonymous function
struct kk_sampling_populate_fun1125__t {
  struct kk_function_s _base;
  size_t i0_833;
};
static kk_box_t kk_sampling_populate_fun1125(kk_function_t _fself, kk_function_t _b_904, kk_box_t _b_905, kk_context_t* _ctx);
static kk_function_t kk_sampling_new_populate_fun1125(size_t i0_833, kk_context_t* _ctx) {
  struct kk_sampling_populate_fun1125__t* _self = kk_function_alloc_as(struct kk_sampling_populate_fun1125__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_sampling_populate_fun1125, kk_context());
  _self->i0_833 = i0_833;
  return &_self->_base;
}

static kk_box_t kk_sampling_populate_fun1125(kk_function_t _fself, kk_function_t _b_904, kk_box_t _b_905, kk_context_t* _ctx) {
  struct kk_sampling_populate_fun1125__t* _self = kk_function_as(struct kk_sampling_populate_fun1125__t*, _fself);
  size_t i0_833 = _self->i0_833; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i0_833, _b_904, _b_905, _ctx);
}


// lift anonymous function
struct kk_sampling_populate_fun1126__t {
  struct kk_function_s _base;
  kk_function_t model;
};
static kk_box_t kk_sampling_populate_fun1126(kk_function_t _fself, kk_box_t _b_915, kk_context_t* _ctx);
static kk_function_t kk_sampling_new_populate_fun1126(kk_function_t model, kk_context_t* _ctx) {
  struct kk_sampling_populate_fun1126__t* _self = kk_function_alloc_as(struct kk_sampling_populate_fun1126__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_sampling_populate_fun1126, kk_context());
  _self->model = model;
  return &_self->_base;
}

static kk_box_t kk_sampling_populate_fun1126(kk_function_t _fself, kk_box_t _b_915, kk_context_t* _ctx) {
  struct kk_sampling_populate_fun1126__t* _self = kk_function_as(struct kk_sampling_populate_fun1126__t*, _fself);
  kk_function_t model = _self->model; /* () -> <effects-and-types/score|173> 172 */
  kk_drop_match(_self, {kk_function_dup(model);}, {}, _ctx)
  kk_unit_t _x1127 = kk_Unit;
  kk_unit_unbox(_b_915);
  return kk_sampling__mlift823_populate(model, _x1127, _ctx);
}
static kk_box_t kk_sampling_populate_fun1115(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_sampling_populate_fun1115__t* _self = kk_function_as(struct kk_sampling_populate_fun1115__t*, _fself);
  kk_integer_t k = _self->k; /* int */
  kk_function_t model = _self->model; /* () -> <effects-and-types/score|173> 172 */
  kk_drop_match(_self, {kk_integer_dup(k);kk_function_dup(model);}, {}, _ctx)
  kk_unit_t x_831 = kk_Unit;
  kk_effects_dash_and_dash_types__exp _x1;
  kk_effects_dash_and_dash_types__exp _x10 = kk_effects_dash_and_dash_types__new_Exp(0x0p+0, _ctx); /*effects-and-types/exp*/;
  kk_effects_dash_and_dash_types__exp _x2;
  double _x1116;
  double _x1117 = kk_integer_as_double(k,kk_context()); /*double*/
  _x1116 = log(_x1117); /*double*/
  _x2 = kk_effects_dash_and_dash_types__new_Exp(_x1116, _ctx); /*effects-and-types/exp*/
  kk_box_t _x1118 = kk_std_core_hnd__open_none2(kk_sampling_new_populate_fun1119(_ctx), kk_effects_dash_and_dash_types__exp_box(_x10, _ctx), kk_effects_dash_and_dash_types__exp_box(_x2, _ctx), _ctx); /*3333*/
  _x1 = kk_effects_dash_and_dash_types__exp_unbox(_x1118, _ctx); /*effects-and-types/exp*/
  size_t i0_833;
  kk_std_core_hnd__htag _x1123 = kk_std_core_hnd__htag_dup(kk_effects_dash_and_dash_types__tag_score); /*std/core/hnd/htag<effects-and-types/.hnd-score>*/
  i0_833 = kk_std_core_hnd__evv_index(_x1123, _ctx); /*std/core/hnd/ev-index*/
  kk_evv_t w = kk_evv_swap_create1(i0_833,kk_context()); /*std/core/hnd/evv<<effects-and-types/score|173>>*/;
  kk_unit_t y = kk_Unit;
  kk_effects_dash_and_dash_types_score(_x1, _ctx);
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x1124 = kk_std_core_hnd_yield_cont(kk_sampling_new_populate_fun1125(i0_833, _ctx), _ctx); /*3820*/
    kk_unit_unbox(_x1124);
  }
  else {
    y;
  }
  if (kk_yielding(kk_context())) {
    return kk_std_core_hnd_yield_extend(kk_sampling_new_populate_fun1126(model, _ctx), _ctx);
  }
  return kk_sampling__mlift823_populate(model, x_831, _ctx);
}
static kk_box_t kk_sampling_populate_fun1112(kk_function_t _fself, kk_integer_t _b_920, kk_context_t* _ctx) {
  struct kk_sampling_populate_fun1112__t* _self = kk_function_as(struct kk_sampling_populate_fun1112__t*, _fself);
  kk_integer_t k = _self->k; /* int */
  kk_function_t model = _self->model; /* () -> <effects-and-types/score|173> 172 */
  kk_drop_match(_self, {kk_integer_dup(k);kk_function_dup(model);}, {}, _ctx)
  kk_integer_drop(_b_920, _ctx);
  kk_std_core_types__tuple2_ _x1113;
  kk_effects_dash_and_dash_types__exp _x1114 = kk_effects_dash_and_dash_types__new_Exp(0x0p+0, _ctx); /*effects-and-types/exp*/
  _x1113 = kk_handlers_weighted(_x1114, kk_sampling_new_populate_fun1115(k, model, _ctx), _ctx); /*(effects-and-types/exp, 2370)*/
  return kk_std_core_types__tuple2__box(_x1113, _ctx);
}

kk_std_core__list kk_sampling_populate(kk_integer_t k, kk_function_t model, kk_context_t* _ctx) { /* forall<a,e> (k : int, model : () -> <effects-and-types/score|e> a) -> e effects-and-types/histogram<a> */ 
  kk_function_t _x1111;
  kk_integer_dup(k);
  _x1111 = kk_sampling_new_populate_fun1112(k, model, _ctx); /*(int) -> 6016 6015*/
  return kk_std_core__lift21054_list_1(_x1111, kk_integer_from_small(1), k, kk_std_core__new_Nil(_ctx), _ctx);
}
 
// lift

kk_box_t kk_sampling__lift812_weighted__choice(double fuel, kk_std_core__list ws, kk_context_t* _ctx) { /* forall<a> (fuel : double, ws : list<(double, a)>) -> exn a */ 
  kk__tailcall: ;
  if (kk_std_core__is_Nil(ws)) {
    kk_std_core__exception exn_21561;
    kk_string_t _x1128;
    kk_define_string_literal(, _s1129, 62, "Histogram is empty! Cannot select any element when resampling!")
    _x1128 = kk_string_dup(_s1129); /*string*/
    kk_std_core__exception_info _x1130;
    kk_std_core_types__optional _match_1102 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
    if (kk_std_core_types__is_Optional(_match_1102)) {
      kk_box_t _box_x928 = _match_1102._cons.Optional.value;
      kk_std_core__exception_info _info_14279 = kk_std_core__exception_info_unbox(_box_x928, NULL);
      kk_std_core__exception_info_dup(_info_14279);
      kk_std_core_types__optional_drop(_match_1102, _ctx);
      _x1130 = _info_14279; /*exception-info*/
      goto _match1131;
    }
    _x1130 = kk_std_core__new_ExnError(_ctx); /*exception-info*/
    _match1131: ;
    exn_21561 = kk_std_core__new_Exception(_x1128, _x1130, _ctx); /*exception*/
    kk_std_core_hnd__ev ev_21562;
    size_t _x1133 = ((size_t)0); /*size_t*/
    ev_21562 = kk_evv_at(_x1133,kk_context()); /*std/core/hnd/ev<.hnd-exn>*/
    struct kk_std_core_hnd_Ev* _con1134 = kk_std_core_hnd__as_Ev(ev_21562);
    kk_std_core_hnd__marker m = _con1134->marker;
    kk_box_t _box_x929 = _con1134->hnd;
    kk_std_core__hnd_exn h = kk_std_core__hnd_exn_unbox(_box_x929, NULL);
    kk_std_core__hnd_exn_dup(h);
    kk_std_core_hnd__clause1 _match_1101;
    struct kk_std_core__Hnd_exn* _con1136 = kk_std_core__as_Hnd_exn(h);
    kk_std_core_hnd__clause1 except_throw_exn = _con1136->except_throw_exn;
    if (kk_std_core__hnd_exn_is_unique(h)) {
      kk_std_core__hnd_exn_free(h);
    }
    else {
      kk_std_core_hnd__clause1_dup(except_throw_exn);
      kk_std_core__hnd_exn_decref(h, _ctx);
    }
    _match_1101 = except_throw_exn; /*forall<a> std/core/hnd/clause1<exception,a,.hnd-exn,3528,3529>*/
    kk_function_t _fun_unbox_x933 = _match_1101.clause;
    return kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x933, (_fun_unbox_x933, m, ev_21562, kk_std_core__exception_box(exn_21561, _ctx), _ctx));
  }
  struct kk_std_core_Cons* _con1137 = kk_std_core__as_Cons(ws);
  kk_box_t _box_x937 = _con1137->head;
  kk_std_core__list wxs = _con1137->tail;
  kk_std_core_types__tuple2_ _pat10 = kk_std_core_types__tuple2__unbox(_box_x937, NULL);
  kk_box_t _box_x938 = _pat10.fst;
  kk_box_t x = _pat10.snd;
  double w = kk_double_unbox(_box_x938, NULL);
  if (kk_std_core__list_is_unique(ws)) {
    kk_box_dup(x);
    kk_box_drop(_box_x937, _ctx);
    kk_std_core__list_free(ws);
  }
  else {
    kk_std_core__list_dup(wxs);
    kk_box_dup(x);
    kk_std_core__list_decref(ws, _ctx);
  }
  double fuel__new = (fuel - w); /*double*/;
  bool _match_1100 = (fuel__new <= (0x0p+0)); /*bool*/;
  if (_match_1100) {
    kk_std_core__list_drop(wxs, _ctx);
    return x;
  }
  kk_box_drop(x, _ctx);
  { // tailcall
    fuel = fuel__new;
    ws = wxs;
    goto kk__tailcall;
  }
}
 
// monadic lift


// lift anonymous function
struct kk_sampling__mlift824_weighted__choice_fun1140__t {
  struct kk_function_s _base;
  size_t i_838;
};
static kk_box_t kk_sampling__mlift824_weighted__choice_fun1140(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx);
static kk_function_t kk_sampling__new_mlift824_weighted__choice_fun1140(size_t i_838, kk_context_t* _ctx) {
  struct kk_sampling__mlift824_weighted__choice_fun1140__t* _self = kk_function_alloc_as(struct kk_sampling__mlift824_weighted__choice_fun1140__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_sampling__mlift824_weighted__choice_fun1140, kk_context());
  _self->i_838 = i_838;
  return &_self->_base;
}

static kk_box_t kk_sampling__mlift824_weighted__choice_fun1140(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_sampling__mlift824_weighted__choice_fun1140__t* _self = kk_function_as(struct kk_sampling__mlift824_weighted__choice_fun1140__t*, _fself);
  size_t i_838 = _self->i_838; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_838, cont, res, _ctx);
}

kk_box_t kk_sampling__mlift824_weighted__choice(kk_std_core__list histogram, double total__w, double _y_8, kk_context_t* _ctx) { /* forall<a> (histogram : list<(double, a)>, total_w : double, double) -> <effects-and-types/sample,exn> a */ 
  double total__fuel = (total__w * _y_8); /*double*/;
  size_t i_838 = ((size_t)0); /*std/core/hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_838,kk_context()); /*std/core/hnd/evv<<exn,effects-and-types/sample>>*/;
  kk_box_t y = kk_sampling__lift812_weighted__choice(total__fuel, histogram, _ctx); /*291*/;
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_drop(y, _ctx);
    return kk_std_core_hnd_yield_cont(kk_sampling__new_mlift824_weighted__choice_fun1140(i_838, _ctx), _ctx);
  }
  return y;
}
 
// This chooses a histogram with the probabilirt of


// lift anonymous function
struct kk_sampling_weighted__choice_fun1147__t {
  struct kk_function_s _base;
  size_t i_845;
};
static kk_box_t kk_sampling_weighted__choice_fun1147(kk_function_t _fself, kk_function_t _b_955, kk_box_t _b_956, kk_context_t* _ctx);
static kk_function_t kk_sampling_new_weighted__choice_fun1147(size_t i_845, kk_context_t* _ctx) {
  struct kk_sampling_weighted__choice_fun1147__t* _self = kk_function_alloc_as(struct kk_sampling_weighted__choice_fun1147__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_sampling_weighted__choice_fun1147, kk_context());
  _self->i_845 = i_845;
  return &_self->_base;
}

static kk_box_t kk_sampling_weighted__choice_fun1147(kk_function_t _fself, kk_function_t _b_955, kk_box_t _b_956, kk_context_t* _ctx) {
  struct kk_sampling_weighted__choice_fun1147__t* _self = kk_function_as(struct kk_sampling_weighted__choice_fun1147__t*, _fself);
  size_t i_845 = _self->i_845; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_845, _b_955, _b_956, _ctx);
}


// lift anonymous function
struct kk_sampling_weighted__choice_fun1148__t {
  struct kk_function_s _base;
  kk_std_core__list histogram;
  double total__w;
};
static kk_box_t kk_sampling_weighted__choice_fun1148(kk_function_t _fself, kk_box_t _b_966, kk_context_t* _ctx);
static kk_function_t kk_sampling_new_weighted__choice_fun1148(kk_std_core__list histogram, double total__w, kk_context_t* _ctx) {
  struct kk_sampling_weighted__choice_fun1148__t* _self = kk_function_alloc_as(struct kk_sampling_weighted__choice_fun1148__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_sampling_weighted__choice_fun1148, kk_context());
  _self->histogram = histogram;
  _self->total__w = total__w;
  return &_self->_base;
}

static kk_box_t kk_sampling_weighted__choice_fun1148(kk_function_t _fself, kk_box_t _b_966, kk_context_t* _ctx) {
  struct kk_sampling_weighted__choice_fun1148__t* _self = kk_function_as(struct kk_sampling_weighted__choice_fun1148__t*, _fself);
  kk_std_core__list histogram = _self->histogram; /* list<(double, 291)> */
  double total__w = _self->total__w; /* double */
  kk_drop_match(_self, {kk_std_core__list_dup(histogram);;}, {}, _ctx)
  double _x1149 = kk_double_unbox(_b_966, _ctx); /*double*/
  return kk_sampling__mlift824_weighted__choice(histogram, total__w, _x1149, _ctx);
}


// lift anonymous function
struct kk_sampling_weighted__choice_fun1150__t {
  struct kk_function_s _base;
  size_t i0_848;
};
static kk_box_t kk_sampling_weighted__choice_fun1150(kk_function_t _fself, kk_function_t cont0, kk_box_t res0, kk_context_t* _ctx);
static kk_function_t kk_sampling_new_weighted__choice_fun1150(size_t i0_848, kk_context_t* _ctx) {
  struct kk_sampling_weighted__choice_fun1150__t* _self = kk_function_alloc_as(struct kk_sampling_weighted__choice_fun1150__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_sampling_weighted__choice_fun1150, kk_context());
  _self->i0_848 = i0_848;
  return &_self->_base;
}

static kk_box_t kk_sampling_weighted__choice_fun1150(kk_function_t _fself, kk_function_t cont0, kk_box_t res0, kk_context_t* _ctx) {
  struct kk_sampling_weighted__choice_fun1150__t* _self = kk_function_as(struct kk_sampling_weighted__choice_fun1150__t*, _fself);
  size_t i0_848 = _self->i0_848; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i0_848, cont0, res0, _ctx);
}

kk_box_t kk_sampling_weighted__choice(double total__w, kk_std_core__list histogram, kk_context_t* _ctx) { /* forall<a> (total_w : double, histogram : list<(double, a)>) -> <exn,effects-and-types/sample> a */ 
  double x_842;
  size_t i_845 = ((size_t)1); /*std/core/hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_845,kk_context()); /*std/core/hnd/evv<<effects-and-types/sample,exn>>*/;
  double y;
  kk_std_core_hnd__ev ev_404;
  size_t _x1141 = ((size_t)0); /*size_t*/
  ev_404 = kk_evv_at(_x1141,kk_context()); /*std/core/hnd/ev<effects-and-types/.hnd-sample>*/
  kk_box_t _x1142;
  struct kk_std_core_hnd_Ev* _con1143 = kk_std_core_hnd__as_Ev(ev_404);
  kk_std_core_hnd__marker m = _con1143->marker;
  kk_box_t _box_x942 = _con1143->hnd;
  kk_effects_dash_and_dash_types__hnd_sample h = kk_effects_dash_and_dash_types__hnd_sample_unbox(_box_x942, NULL);
  kk_effects_dash_and_dash_types__hnd_sample_dup(h);
  kk_std_core_hnd__clause0 _match_1098;
  struct kk_effects_dash_and_dash_types__Hnd_sample* _con1145 = kk_effects_dash_and_dash_types__as_Hnd_sample(h);
  kk_std_core_hnd__clause0 fun_sample = _con1145->fun_sample;
  if (kk_effects_dash_and_dash_types__hnd_sample_is_unique(h)) {
    kk_effects_dash_and_dash_types__hnd_sample_free(h);
  }
  else {
    kk_std_core_hnd__clause0_dup(fun_sample);
    kk_effects_dash_and_dash_types__hnd_sample_decref(h, _ctx);
  }
  _match_1098 = fun_sample; /*std/core/hnd/clause0<double,effects-and-types/.hnd-sample,3435,3436>*/
  kk_function_t _fun_unbox_x945 = _match_1098.clause;
  _x1142 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x945, (_fun_unbox_x945, m, ev_404, _ctx)); /*37*/
  y = kk_double_unbox(_x1142, _ctx); /*double*/
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x1146 = kk_std_core_hnd_yield_cont(kk_sampling_new_weighted__choice_fun1147(i_845, _ctx), _ctx); /*3820*/
    x_842 = kk_double_unbox(_x1146, _ctx); /*double*/
  }
  else {
    x_842 = y; /*double*/
  }
  if (kk_yielding(kk_context())) {
    return kk_std_core_hnd_yield_extend(kk_sampling_new_weighted__choice_fun1148(histogram, total__w, _ctx), _ctx);
  }
  double total__fuel = (total__w * x_842); /*double*/;
  size_t i0_848 = ((size_t)0); /*std/core/hnd/ev-index*/;
  kk_evv_t w0 = kk_evv_swap_create1(i0_848,kk_context()); /*std/core/hnd/evv<<exn,effects-and-types/sample>>*/;
  kk_box_t y0 = kk_sampling__lift812_weighted__choice(total__fuel, histogram, _ctx); /*291*/;
  kk_unit_t __0 = kk_Unit;
  kk_evv_set(w0,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_drop(y0, _ctx);
    return kk_std_core_hnd_yield_cont(kk_sampling_new_weighted__choice_fun1150(i0_848, _ctx), _ctx);
  }
  return y0;
}


// lift anonymous function
struct kk_sampling_sum__histogram_fun1152__t {
  struct kk_function_s _base;
};
static kk_box_t kk_sampling_sum__histogram_fun1152(kk_function_t _fself, kk_box_t _b_973, kk_box_t _b_974, kk_context_t* _ctx);
static kk_function_t kk_sampling_new_sum__histogram_fun1152(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_sampling_sum__histogram_fun1152, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_sampling_sum__histogram_fun1152(kk_function_t _fself, kk_box_t _b_973, kk_box_t _b_974, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x1153;
  kk_std_core_types__tuple2_ _match_1094 = kk_std_core_types__tuple2__unbox(_b_974, _ctx); /*(effects-and-types/exp, 334)*/;
  kk_box_t _box_x969 = _match_1094.fst;
  kk_effects_dash_and_dash_types__exp w = kk_effects_dash_and_dash_types__exp_unbox(_box_x969, NULL);
  kk_std_core_types__tuple2__drop(_match_1094, _ctx);
  double _x1155 = kk_double_unbox(_b_973, _ctx); /*double*/
  double _x1156 = kk_exponents_exp__to__double(w, _ctx); /*double*/
  _x1153 = (_x1155 + _x1156); /*double*/
  return kk_double_box(_x1153, _ctx);
}

double kk_sampling_sum__histogram(kk_std_core__list hist, kk_context_t* _ctx) { /* forall<a> (hist : effects-and-types/histogram<a>) -> double */ 
  kk_box_t _x1151 = kk_std_core_foldl(hist, kk_double_box(0x0p+0, _ctx), kk_sampling_new_sum__histogram_fun1152(_ctx), _ctx); /*15010*/
  return kk_double_unbox(_x1151, _ctx);
}


// lift anonymous function
struct kk_sampling_normalise_fun1158__t {
  struct kk_function_s _base;
  kk_effects_dash_and_dash_types__exp total;
};
static kk_box_t kk_sampling_normalise_fun1158(kk_function_t _fself, kk_box_t _b_986, kk_context_t* _ctx);
static kk_function_t kk_sampling_new_normalise_fun1158(kk_effects_dash_and_dash_types__exp total, kk_context_t* _ctx) {
  struct kk_sampling_normalise_fun1158__t* _self = kk_function_alloc_as(struct kk_sampling_normalise_fun1158__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_sampling_normalise_fun1158, kk_context());
  _self->total = total;
  return &_self->_base;
}

static kk_box_t kk_sampling_normalise_fun1158(kk_function_t _fself, kk_box_t _b_986, kk_context_t* _ctx) {
  struct kk_sampling_normalise_fun1158__t* _self = kk_function_as(struct kk_sampling_normalise_fun1158__t*, _fself);
  kk_effects_dash_and_dash_types__exp total = _self->total; /* effects-and-types/exp */
  kk_drop_match(_self, {kk_effects_dash_and_dash_types__exp_dup(total);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x1159;
  kk_effects_dash_and_dash_types__exp _b_990_982;
  kk_effects_dash_and_dash_types__exp _match_1092;
  kk_std_core_types__tuple2_ _match_1093;
  kk_box_t _x1160 = kk_box_dup(_b_986); /*7319*/
  _match_1093 = kk_std_core_types__tuple2__unbox(_x1160, _ctx); /*(effects-and-types/exp, 598)*/
  kk_box_t _box_x980 = _match_1093.fst;
  kk_effects_dash_and_dash_types__exp _x = kk_effects_dash_and_dash_types__exp_unbox(_box_x980, NULL);
  kk_std_core_types__tuple2__drop(_match_1093, _ctx);
  _match_1092 = _x; /*effects-and-types/exp*/
  double xe = _match_1092.i;
  double ye = total.i;
  double _x1162 = (xe - ye); /*double*/
  _b_990_982 = kk_effects_dash_and_dash_types__new_Exp(_x1162, _ctx); /*effects-and-types/exp*/
  kk_box_t _x1163;
  kk_std_core_types__tuple2_ _match_1091 = kk_std_core_types__tuple2__unbox(_b_986, _ctx); /*(effects-and-types/exp, 598)*/;
  kk_box_t _box_x981 = _match_1091.fst;
  kk_box_t _x0 = _match_1091.snd;
  kk_box_dup(_x0);
  kk_std_core_types__tuple2__drop(_match_1091, _ctx);
  _x1163 = _x0; /*598*/
  _x1159 = kk_std_core_types__new_dash__lp__comma__rp_(kk_effects_dash_and_dash_types__exp_box(_b_990_982, _ctx), _x1163, _ctx); /*(6, 7)*/
  return kk_std_core_types__tuple2__box(_x1159, _ctx);
}

kk_std_core__list kk_sampling_normalise(kk_std_core__list histogram, kk_context_t* _ctx) { /* forall<a> (histogram : effects-and-types/histogram<a>) -> effects-and-types/histogram<a> */ 
  kk_effects_dash_and_dash_types__exp total;
  kk_std_core__list _x1157 = kk_std_core__list_dup(histogram); /*effects-and-types/histogram<598>*/
  total = kk_sampling_sum__weights(_x1157, _ctx); /*effects-and-types/exp*/
  return kk_std_core_map_5(histogram, kk_sampling_new_normalise_fun1158(total, _ctx), _ctx);
}
 
// monadic lift

kk_std_core__list kk_sampling__mlift825_importance__sampling(kk_std_core__list _y_10, kk_context_t* _ctx) { /* forall<a,e> (effects-and-types/histogram<a>) -> <std/num/random/random,effects-and-types/sample|e> effects-and-types/histogram<a> */ 
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*std/core/hnd/evv<(<>)>*/;
  kk_std_core__list x = kk_sampling_normalise(_y_10, _ctx); /*effects-and-types/histogram<626>*/;
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  return x;
}


// lift anonymous function
struct kk_sampling_importance__sampling_fun1166__t {
  struct kk_function_s _base;
  kk_function_t model;
};
static kk_box_t kk_sampling_importance__sampling_fun1166(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_sampling_new_importance__sampling_fun1166(kk_function_t model, kk_context_t* _ctx) {
  struct kk_sampling_importance__sampling_fun1166__t* _self = kk_function_alloc_as(struct kk_sampling_importance__sampling_fun1166__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_sampling_importance__sampling_fun1166, kk_context());
  _self->model = model;
  return &_self->_base;
}



// lift anonymous function
struct kk_sampling_importance__sampling_fun1169__t {
  struct kk_function_s _base;
};
static kk_box_t kk_sampling_importance__sampling_fun1169(kk_function_t _fself, kk_box_t _b_993, kk_context_t* _ctx);
static kk_function_t kk_sampling_new_importance__sampling_fun1169(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_sampling_importance__sampling_fun1169, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_sampling_importance__sampling_fun1169(kk_function_t _fself, kk_box_t _b_993, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core__list _x1170;
  kk_std_core__list _x1171 = kk_std_core__list_unbox(_b_993, _ctx); /*effects-and-types/histogram<626>*/
  _x1170 = kk_sampling__mlift825_importance__sampling(_x1171, _ctx); /*effects-and-types/histogram<626>*/
  return kk_std_core__list_box(_x1170, _ctx);
}
static kk_box_t kk_sampling_importance__sampling_fun1166(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_sampling_importance__sampling_fun1166__t* _self = kk_function_as(struct kk_sampling_importance__sampling_fun1166__t*, _fself);
  kk_function_t model = _self->model; /* effects-and-types/model<626,<std/num/random/random|627>> */
  kk_drop_match(_self, {kk_function_dup(model);}, {}, _ctx)
  kk_std_core__list _x1167;
  kk_std_core__list x_858 = kk_sampling_populate(kk_integer_from_small(2000), model, _ctx); /*effects-and-types/histogram<626>*/;
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_858, _ctx);
    kk_box_t _x1168 = kk_std_core_hnd_yield_extend(kk_sampling_new_importance__sampling_fun1169(_ctx), _ctx); /*3991*/
    _x1167 = kk_std_core__list_unbox(_x1168, _ctx); /*effects-and-types/histogram<626>*/
  }
  else {
    _x1167 = kk_sampling__mlift825_importance__sampling(x_858, _ctx); /*effects-and-types/histogram<626>*/
  }
  return kk_std_core__list_box(_x1167, _ctx);
}

kk_std_core__list kk_sampling_importance__sampling(kk_function_t model, kk_context_t* _ctx) { /* forall<a,e> (model : effects-and-types/model<a,<std/num/random/random|e>>) -> <std/num/random/random|e> effects-and-types/histogram<a> */ 
  kk_box_t _x1165 = kk_handlers_random__sampler(kk_sampling_new_importance__sampling_fun1166(model, _ctx), _ctx); /*801*/
  return kk_std_core__list_unbox(_x1165, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_sampling__mlift826_resample_fun1173__t {
  struct kk_function_s _base;
};
static kk_box_t kk_sampling__mlift826_resample_fun1173(kk_function_t _fself, kk_box_t _b_1006, kk_box_t _b_1007, kk_context_t* _ctx);
static kk_function_t kk_sampling__new_mlift826_resample_fun1173(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_sampling__mlift826_resample_fun1173, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_sampling__mlift826_resample_fun1173(kk_function_t _fself, kk_box_t _b_1006, kk_box_t _b_1007, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x1174 = kk_double_unbox(_b_1006, _ctx); /*double*/
  kk_std_core__list _x1175 = kk_std_core__list_unbox(_b_1007, _ctx); /*list<(double, 811)>*/
  return kk_sampling_weighted__choice(_x1174, _x1175, _ctx);
}

kk_box_t kk_sampling__mlift826_resample(kk_std_core__list histogram__dbl, double total__w__dbl, kk_unit_t wild__, kk_context_t* _ctx) { /* forall<a> (histogram_dbl : list<(double, a)>, total_w_dbl : double, wild_ : ()) -> <effects-and-types/score,exn,effects-and-types/sample> a */ 
  kk_vector_t _b_1008_1002;
  kk_std_core__list _x1172;
  size_t _b_1012_1000 = ((size_t)0); /*std/core/hnd/ev-index*/;
  kk_std_core__list _b_1013_1001;
  size_t _b_1014_998 = ((size_t)1); /*std/core/hnd/ev-index*/;
  _b_1013_1001 = kk_std_core__new_Cons(kk_reuse_null, kk_size_box(_b_1014_998, _ctx), kk_std_core__new_Nil(_ctx), _ctx); /*list<std/core/hnd/ev-index>*/
  _x1172 = kk_std_core__new_Cons(kk_reuse_null, kk_size_box(_b_1012_1000, _ctx), _b_1013_1001, _ctx); /*list<0>*/
  _b_1008_1002 = kk_std_core_unvlist(_x1172, _ctx); /*vector<std/core/hnd/ev-index>*/
  return kk_std_core_hnd__open2(_b_1008_1002, kk_sampling__new_mlift826_resample_fun1173(_ctx), kk_double_box(total__w__dbl, _ctx), kk_std_core__list_box(histogram__dbl, _ctx), _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_sampling__mlift827_resample_fun1176__t {
  struct kk_function_s _base;
  kk_std_core__list histogram__dbl;
  kk_effects_dash_and_dash_types__exp total__w;
  double total__w__dbl;
};
static kk_box_t kk_sampling__mlift827_resample_fun1176(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_sampling__new_mlift827_resample_fun1176(kk_std_core__list histogram__dbl, kk_effects_dash_and_dash_types__exp total__w, double total__w__dbl, kk_context_t* _ctx) {
  struct kk_sampling__mlift827_resample_fun1176__t* _self = kk_function_alloc_as(struct kk_sampling__mlift827_resample_fun1176__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_sampling__mlift827_resample_fun1176, kk_context());
  _self->histogram__dbl = histogram__dbl;
  _self->total__w = total__w;
  _self->total__w__dbl = total__w__dbl;
  return &_self->_base;
}



// lift anonymous function
struct kk_sampling__mlift827_resample_fun1178__t {
  struct kk_function_s _base;
  size_t i_862;
};
static kk_box_t kk_sampling__mlift827_resample_fun1178(kk_function_t _fself, kk_function_t _b_1021, kk_box_t _b_1022, kk_context_t* _ctx);
static kk_function_t kk_sampling__new_mlift827_resample_fun1178(size_t i_862, kk_context_t* _ctx) {
  struct kk_sampling__mlift827_resample_fun1178__t* _self = kk_function_alloc_as(struct kk_sampling__mlift827_resample_fun1178__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_sampling__mlift827_resample_fun1178, kk_context());
  _self->i_862 = i_862;
  return &_self->_base;
}

static kk_box_t kk_sampling__mlift827_resample_fun1178(kk_function_t _fself, kk_function_t _b_1021, kk_box_t _b_1022, kk_context_t* _ctx) {
  struct kk_sampling__mlift827_resample_fun1178__t* _self = kk_function_as(struct kk_sampling__mlift827_resample_fun1178__t*, _fself);
  size_t i_862 = _self->i_862; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_862, _b_1021, _b_1022, _ctx);
}


// lift anonymous function
struct kk_sampling__mlift827_resample_fun1179__t {
  struct kk_function_s _base;
  kk_std_core__list histogram__dbl;
  double total__w__dbl;
};
static kk_box_t kk_sampling__mlift827_resample_fun1179(kk_function_t _fself, kk_box_t _b_1032, kk_context_t* _ctx);
static kk_function_t kk_sampling__new_mlift827_resample_fun1179(kk_std_core__list histogram__dbl, double total__w__dbl, kk_context_t* _ctx) {
  struct kk_sampling__mlift827_resample_fun1179__t* _self = kk_function_alloc_as(struct kk_sampling__mlift827_resample_fun1179__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_sampling__mlift827_resample_fun1179, kk_context());
  _self->histogram__dbl = histogram__dbl;
  _self->total__w__dbl = total__w__dbl;
  return &_self->_base;
}

static kk_box_t kk_sampling__mlift827_resample_fun1179(kk_function_t _fself, kk_box_t _b_1032, kk_context_t* _ctx) {
  struct kk_sampling__mlift827_resample_fun1179__t* _self = kk_function_as(struct kk_sampling__mlift827_resample_fun1179__t*, _fself);
  kk_std_core__list histogram__dbl = _self->histogram__dbl; /* list<(double, 811)> */
  double total__w__dbl = _self->total__w__dbl; /* double */
  kk_drop_match(_self, {kk_std_core__list_dup(histogram__dbl);;}, {}, _ctx)
  kk_unit_t _x1180 = kk_Unit;
  kk_unit_unbox(_b_1032);
  return kk_sampling__mlift826_resample(histogram__dbl, total__w__dbl, _x1180, _ctx);
}
static kk_box_t kk_sampling__mlift827_resample_fun1176(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_sampling__mlift827_resample_fun1176__t* _self = kk_function_as(struct kk_sampling__mlift827_resample_fun1176__t*, _fself);
  kk_std_core__list histogram__dbl = _self->histogram__dbl; /* list<(double, 811)> */
  kk_effects_dash_and_dash_types__exp total__w = _self->total__w; /* effects-and-types/exp */
  double total__w__dbl = _self->total__w__dbl; /* double */
  kk_drop_match(_self, {kk_std_core__list_dup(histogram__dbl);kk_effects_dash_and_dash_types__exp_dup(total__w);;}, {}, _ctx)
  kk_unit_t x_860 = kk_Unit;
  size_t i_862 = ((size_t)2); /*std/core/hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_862,kk_context()); /*std/core/hnd/evv<<effects-and-types/score,exn,effects-and-types/sample>>*/;
  kk_unit_t y = kk_Unit;
  kk_effects_dash_and_dash_types_score(total__w, _ctx);
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x1177 = kk_std_core_hnd_yield_cont(kk_sampling__new_mlift827_resample_fun1178(i_862, _ctx), _ctx); /*3820*/
    kk_unit_unbox(_x1177);
  }
  else {
    y;
  }
  if (kk_yielding(kk_context())) {
    return kk_std_core_hnd_yield_extend(kk_sampling__new_mlift827_resample_fun1179(histogram__dbl, total__w__dbl, _ctx), _ctx);
  }
  return kk_sampling__mlift826_resample(histogram__dbl, total__w__dbl, x_860, _ctx);
}

kk_std_core__list kk_sampling__mlift827_resample(kk_integer_t n, kk_effects_dash_and_dash_types__exp total__w, double total__w__dbl, kk_std_core__list histogram__dbl, kk_context_t* _ctx) { /* forall<a> (n : int, total_w : effects-and-types/exp, total_w_dbl : double, histogram_dbl : list<(double, a)>) -> <exn,effects-and-types/sample> effects-and-types/histogram<a> */ 
  return kk_sampling_populate(n, kk_sampling__new_mlift827_resample_fun1176(histogram__dbl, total__w, total__w__dbl, _ctx), _ctx);
}


// lift anonymous function
struct kk_sampling_resample_fun1184__t {
  struct kk_function_s _base;
};
static kk_box_t kk_sampling_resample_fun1184(kk_function_t _fself, kk_box_t _b_1037, kk_context_t* _ctx);
static kk_function_t kk_sampling_new_resample_fun1184(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_sampling_resample_fun1184, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_sampling_resample_fun1184(kk_function_t _fself, kk_box_t _b_1037, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x1185;
  kk_effects_dash_and_dash_types__exp _x1186 = kk_effects_dash_and_dash_types__exp_unbox(_b_1037, _ctx); /*effects-and-types/exp*/
  _x1185 = kk_exponents_exp__to__double(_x1186, _ctx); /*double*/
  return kk_double_box(_x1185, _ctx);
}


// lift anonymous function
struct kk_sampling_resample_fun1187__t {
  struct kk_function_s _base;
};
static kk_box_t kk_sampling_resample_fun1187(kk_function_t _fself, kk_box_t _b_1048, kk_context_t* _ctx);
static kk_function_t kk_sampling_new_resample_fun1187(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_sampling_resample_fun1187, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_sampling_resample_fun1191__t {
  struct kk_function_s _base;
};
static kk_box_t kk_sampling_resample_fun1191(kk_function_t _fself, kk_box_t _b_1043, kk_context_t* _ctx);
static kk_function_t kk_sampling_new_resample_fun1191(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_sampling_resample_fun1191, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_sampling_resample_fun1191(kk_function_t _fself, kk_box_t _b_1043, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x1192;
  kk_effects_dash_and_dash_types__exp _x1193 = kk_effects_dash_and_dash_types__exp_unbox(_b_1043, _ctx); /*effects-and-types/exp*/
  _x1192 = kk_exponents_exp__to__double(_x1193, _ctx); /*double*/
  return kk_double_box(_x1192, _ctx);
}
static kk_box_t kk_sampling_resample_fun1187(kk_function_t _fself, kk_box_t _b_1048, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core_types__tuple2_ _x1188;
  kk_std_core_types__tuple2_ _match_1087 = kk_std_core_types__tuple2__unbox(_b_1048, _ctx); /*(effects-and-types/exp, 811)*/;
  kk_box_t _box_x1040 = _match_1087.fst;
  kk_box_t x2 = _match_1087.snd;
  kk_effects_dash_and_dash_types__exp w0 = kk_effects_dash_and_dash_types__exp_unbox(_box_x1040, NULL);
  kk_box_dup(x2);
  kk_std_core_types__tuple2__drop(_match_1087, _ctx);
  double _b_1052_1044;
  kk_box_t _x1190 = kk_std_core_hnd__open_none1(kk_sampling_new_resample_fun1191(_ctx), kk_effects_dash_and_dash_types__exp_box(w0, _ctx), _ctx); /*3239*/
  _b_1052_1044 = kk_double_unbox(_x1190, _ctx); /*double*/
  _x1188 = kk_std_core_types__new_dash__lp__comma__rp_(kk_double_box(_b_1052_1044, _ctx), x2, _ctx); /*(6, 7)*/
  return kk_std_core_types__tuple2__box(_x1188, _ctx);
}


// lift anonymous function
struct kk_sampling_resample_fun1195__t {
  struct kk_function_s _base;
  kk_integer_t n;
  kk_effects_dash_and_dash_types__exp total__w;
  double total__w__dbl;
};
static kk_box_t kk_sampling_resample_fun1195(kk_function_t _fself, kk_box_t _b_1057, kk_context_t* _ctx);
static kk_function_t kk_sampling_new_resample_fun1195(kk_integer_t n, kk_effects_dash_and_dash_types__exp total__w, double total__w__dbl, kk_context_t* _ctx) {
  struct kk_sampling_resample_fun1195__t* _self = kk_function_alloc_as(struct kk_sampling_resample_fun1195__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_sampling_resample_fun1195, kk_context());
  _self->n = n;
  _self->total__w = total__w;
  _self->total__w__dbl = total__w__dbl;
  return &_self->_base;
}

static kk_box_t kk_sampling_resample_fun1195(kk_function_t _fself, kk_box_t _b_1057, kk_context_t* _ctx) {
  struct kk_sampling_resample_fun1195__t* _self = kk_function_as(struct kk_sampling_resample_fun1195__t*, _fself);
  kk_integer_t n = _self->n; /* int */
  kk_effects_dash_and_dash_types__exp total__w = _self->total__w; /* effects-and-types/exp */
  double total__w__dbl = _self->total__w__dbl; /* double */
  kk_drop_match(_self, {kk_integer_dup(n);kk_effects_dash_and_dash_types__exp_dup(total__w);;}, {}, _ctx)
  kk_std_core__list _x1196;
  kk_std_core__list _x1197 = kk_std_core__list_unbox(_b_1057, _ctx); /*list<(double, 811)>*/
  _x1196 = kk_sampling__mlift827_resample(n, total__w, total__w__dbl, _x1197, _ctx); /*effects-and-types/histogram<811>*/
  return kk_std_core__list_box(_x1196, _ctx);
}


// lift anonymous function
struct kk_sampling_resample_fun1198__t {
  struct kk_function_s _base;
  kk_std_core__list x0_867;
  kk_effects_dash_and_dash_types__exp total__w;
  double total__w__dbl;
};
static kk_box_t kk_sampling_resample_fun1198(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_sampling_new_resample_fun1198(kk_std_core__list x0_867, kk_effects_dash_and_dash_types__exp total__w, double total__w__dbl, kk_context_t* _ctx) {
  struct kk_sampling_resample_fun1198__t* _self = kk_function_alloc_as(struct kk_sampling_resample_fun1198__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_sampling_resample_fun1198, kk_context());
  _self->x0_867 = x0_867;
  _self->total__w = total__w;
  _self->total__w__dbl = total__w__dbl;
  return &_self->_base;
}



// lift anonymous function
struct kk_sampling_resample_fun1200__t {
  struct kk_function_s _base;
  size_t i_873;
};
static kk_box_t kk_sampling_resample_fun1200(kk_function_t _fself, kk_function_t _b_1063, kk_box_t _b_1064, kk_context_t* _ctx);
static kk_function_t kk_sampling_new_resample_fun1200(size_t i_873, kk_context_t* _ctx) {
  struct kk_sampling_resample_fun1200__t* _self = kk_function_alloc_as(struct kk_sampling_resample_fun1200__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_sampling_resample_fun1200, kk_context());
  _self->i_873 = i_873;
  return &_self->_base;
}

static kk_box_t kk_sampling_resample_fun1200(kk_function_t _fself, kk_function_t _b_1063, kk_box_t _b_1064, kk_context_t* _ctx) {
  struct kk_sampling_resample_fun1200__t* _self = kk_function_as(struct kk_sampling_resample_fun1200__t*, _fself);
  size_t i_873 = _self->i_873; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_873, _b_1063, _b_1064, _ctx);
}


// lift anonymous function
struct kk_sampling_resample_fun1201__t {
  struct kk_function_s _base;
  kk_std_core__list x0_867;
  double total__w__dbl;
};
static kk_box_t kk_sampling_resample_fun1201(kk_function_t _fself, kk_box_t _b_1074, kk_context_t* _ctx);
static kk_function_t kk_sampling_new_resample_fun1201(kk_std_core__list x0_867, double total__w__dbl, kk_context_t* _ctx) {
  struct kk_sampling_resample_fun1201__t* _self = kk_function_alloc_as(struct kk_sampling_resample_fun1201__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_sampling_resample_fun1201, kk_context());
  _self->x0_867 = x0_867;
  _self->total__w__dbl = total__w__dbl;
  return &_self->_base;
}

static kk_box_t kk_sampling_resample_fun1201(kk_function_t _fself, kk_box_t _b_1074, kk_context_t* _ctx) {
  struct kk_sampling_resample_fun1201__t* _self = kk_function_as(struct kk_sampling_resample_fun1201__t*, _fself);
  kk_std_core__list x0_867 = _self->x0_867; /* list<(double, 811)> */
  double total__w__dbl = _self->total__w__dbl; /* double */
  kk_drop_match(_self, {kk_std_core__list_dup(x0_867);;}, {}, _ctx)
  kk_unit_t _x1202 = kk_Unit;
  kk_unit_unbox(_b_1074);
  return kk_sampling__mlift826_resample(x0_867, total__w__dbl, _x1202, _ctx);
}
static kk_box_t kk_sampling_resample_fun1198(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_sampling_resample_fun1198__t* _self = kk_function_as(struct kk_sampling_resample_fun1198__t*, _fself);
  kk_std_core__list x0_867 = _self->x0_867; /* list<(double, 811)> */
  kk_effects_dash_and_dash_types__exp total__w = _self->total__w; /* effects-and-types/exp */
  double total__w__dbl = _self->total__w__dbl; /* double */
  kk_drop_match(_self, {kk_std_core__list_dup(x0_867);kk_effects_dash_and_dash_types__exp_dup(total__w);;}, {}, _ctx)
  kk_unit_t x3_871 = kk_Unit;
  size_t i_873 = ((size_t)2); /*std/core/hnd/ev-index*/;
  kk_evv_t w1 = kk_evv_swap_create1(i_873,kk_context()); /*std/core/hnd/evv<<effects-and-types/score,exn,effects-and-types/sample>>*/;
  kk_unit_t y = kk_Unit;
  kk_effects_dash_and_dash_types_score(total__w, _ctx);
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w1,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x1199 = kk_std_core_hnd_yield_cont(kk_sampling_new_resample_fun1200(i_873, _ctx), _ctx); /*3820*/
    kk_unit_unbox(_x1199);
  }
  else {
    y;
  }
  if (kk_yielding(kk_context())) {
    return kk_std_core_hnd_yield_extend(kk_sampling_new_resample_fun1201(x0_867, total__w__dbl, _ctx), _ctx);
  }
  return kk_sampling__mlift826_resample(x0_867, total__w__dbl, x3_871, _ctx);
}

kk_std_core__list kk_sampling_resample(kk_std_core__list histogram, kk_context_t* _ctx) { /* forall<a> (histogram : effects-and-types/histogram<a>) -> <exn,effects-and-types/sample> effects-and-types/histogram<a> */ 
  kk_integer_t n;
  kk_std_core__list _x1181 = kk_std_core__list_dup(histogram); /*effects-and-types/histogram<811>*/
  n = kk_std_core_length_1(_x1181, _ctx); /*int*/
  kk_effects_dash_and_dash_types__exp total__w;
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*std/core/hnd/evv<(<>)>*/;
  kk_effects_dash_and_dash_types__exp x;
  kk_std_core__list _x1182 = kk_std_core__list_dup(histogram); /*effects-and-types/histogram<811>*/
  x = kk_sampling_sum__weights(_x1182, _ctx); /*effects-and-types/exp*/
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  total__w = x; /*effects-and-types/exp*/
  double total__w__dbl;
  kk_box_t _x1183 = kk_std_core_hnd__open_none1(kk_sampling_new_resample_fun1184(_ctx), kk_effects_dash_and_dash_types__exp_box(total__w, _ctx), _ctx); /*3239*/
  total__w__dbl = kk_double_unbox(_x1183, _ctx); /*double*/
  kk_std_core__list x0_867 = kk_std_core_map_5(histogram, kk_sampling_new_resample_fun1187(_ctx), _ctx); /*list<(double, 811)>*/;
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x0_867, _ctx);
    kk_box_t _x1194 = kk_std_core_hnd_yield_extend(kk_sampling_new_resample_fun1195(n, total__w, total__w__dbl, _ctx), _ctx); /*3991*/
    return kk_std_core__list_unbox(_x1194, _ctx);
  }
  return kk_sampling_populate(n, kk_sampling_new_resample_fun1198(x0_867, total__w, total__w__dbl, _ctx), _ctx);
}

// initialization
void kk_sampling__init(kk_context_t* _ctx){
  static bool _initialized = false;
  if (_initialized) return;
  _initialized = true;
  kk_std_core_types__init(_ctx);
  kk_std_core_hnd__init(_ctx);
  kk_std_core__init(_ctx);
  kk_std_num_double__init(_ctx);
  kk_std_num_random__init(_ctx);
  kk_effects_dash_and_dash_types__init(_ctx);
  kk_exponents__init(_ctx);
  kk_handlers__init(_ctx);
}
