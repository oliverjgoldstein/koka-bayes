// Koka generated module: "sampling", koka version: 2.1.3
#include "sampling.h"


// lift anonymous function
struct kk_sampling_sum__weights_fun989__t {
  struct kk_function_s _base;
};
static kk_box_t kk_sampling_sum__weights_fun989(kk_function_t _fself, kk_box_t _b_801, kk_box_t _b_802, kk_context_t* _ctx);
static kk_function_t kk_sampling_new_sum__weights_fun989(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_sampling_sum__weights_fun989, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_sampling_sum__weights_fun989(kk_function_t _fself, kk_box_t _b_801, kk_box_t _b_802, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_effects_dash_and_dash_types__exp _x990;
  kk_std_core_types__tuple2_ _match_986 = kk_std_core_types__tuple2__unbox(_b_802, _ctx); /*(effects-and-types/exp, 101)*/;
  kk_box_t _box_x797 = _match_986.fst;
  kk_effects_dash_and_dash_types__exp w = kk_effects_dash_and_dash_types__exp_unbox(_box_x797, NULL);
  kk_std_core_types__tuple2__drop(_match_986, _ctx);
  kk_effects_dash_and_dash_types__exp _x992 = kk_effects_dash_and_dash_types__exp_unbox(_b_801, _ctx); /*effects-and-types/exp*/
  _x990 = kk_exponents_plus__exp(_x992, w, _ctx); /*effects-and-types/exp*/
  return kk_effects_dash_and_dash_types__exp_box(_x990, _ctx);
}

kk_effects_dash_and_dash_types__exp kk_sampling_sum__weights(kk_std_core__list histogram, kk_context_t* _ctx) { /* forall<a> (histogram : effects-and-types/histogram<a>) -> effects-and-types/exp */ 
  kk_effects_dash_and_dash_types__exp _b_804_799;
  double _x987 = log((0x0p+0)); /*double*/
  _b_804_799 = kk_effects_dash_and_dash_types__new_Exp(_x987, _ctx); /*effects-and-types/exp*/
  kk_box_t _x988 = kk_std_core_foldl(histogram, kk_effects_dash_and_dash_types__exp_box(_b_804_799, _ctx), kk_sampling_new_sum__weights_fun989(_ctx), _ctx); /*2*/
  return kk_effects_dash_and_dash_types__exp_unbox(_x988, _ctx);
}
 
// monadic lift

kk_box_t kk_sampling__mlift749_populate(kk_function_t model, kk_unit_t wild__, kk_context_t* _ctx) { /* forall<a,e> (model : () -> <effects-and-types/score|e> a, wild_ : ()) -> <effects-and-types/score|e> a */ 
  return kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), model, (model, _ctx));
}


// lift anonymous function
struct kk_sampling_populate_fun994__t {
  struct kk_function_s _base;
  kk_integer_t k;
  kk_function_t model;
};
static kk_box_t kk_sampling_populate_fun994(kk_function_t _fself, kk_integer_t _b_837, kk_context_t* _ctx);
static kk_function_t kk_sampling_new_populate_fun994(kk_integer_t k, kk_function_t model, kk_context_t* _ctx) {
  struct kk_sampling_populate_fun994__t* _self = kk_function_alloc_as(struct kk_sampling_populate_fun994__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_sampling_populate_fun994, kk_context());
  _self->k = k;
  _self->model = model;
  return &_self->_base;
}



// lift anonymous function
struct kk_sampling_populate_fun997__t {
  struct kk_function_s _base;
  kk_integer_t k;
  kk_function_t model;
};
static kk_box_t kk_sampling_populate_fun997(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_sampling_new_populate_fun997(kk_integer_t k, kk_function_t model, kk_context_t* _ctx) {
  struct kk_sampling_populate_fun997__t* _self = kk_function_alloc_as(struct kk_sampling_populate_fun997__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_sampling_populate_fun997, kk_context());
  _self->k = k;
  _self->model = model;
  return &_self->_base;
}



// lift anonymous function
struct kk_sampling_populate_fun1001__t {
  struct kk_function_s _base;
};
static kk_box_t kk_sampling_populate_fun1001(kk_function_t _fself, kk_box_t _b_811, kk_box_t _b_812, kk_context_t* _ctx);
static kk_function_t kk_sampling_new_populate_fun1001(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_sampling_populate_fun1001, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_sampling_populate_fun1001(kk_function_t _fself, kk_box_t _b_811, kk_box_t _b_812, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_effects_dash_and_dash_types__exp _x1002;
  kk_effects_dash_and_dash_types__exp _x1003 = kk_effects_dash_and_dash_types__exp_unbox(_b_811, _ctx); /*effects-and-types/exp*/
  kk_effects_dash_and_dash_types__exp _x1004 = kk_effects_dash_and_dash_types__exp_unbox(_b_812, _ctx); /*effects-and-types/exp*/
  _x1002 = kk_exponents_div__exp(_x1003, _x1004, _ctx); /*effects-and-types/exp*/
  return kk_effects_dash_and_dash_types__exp_box(_x1002, _ctx);
}


// lift anonymous function
struct kk_sampling_populate_fun1007__t {
  struct kk_function_s _base;
  size_t i0_758;
};
static kk_box_t kk_sampling_populate_fun1007(kk_function_t _fself, kk_function_t _b_821, kk_box_t _b_822, kk_context_t* _ctx);
static kk_function_t kk_sampling_new_populate_fun1007(size_t i0_758, kk_context_t* _ctx) {
  struct kk_sampling_populate_fun1007__t* _self = kk_function_alloc_as(struct kk_sampling_populate_fun1007__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_sampling_populate_fun1007, kk_context());
  _self->i0_758 = i0_758;
  return &_self->_base;
}

static kk_box_t kk_sampling_populate_fun1007(kk_function_t _fself, kk_function_t _b_821, kk_box_t _b_822, kk_context_t* _ctx) {
  struct kk_sampling_populate_fun1007__t* _self = kk_function_as(struct kk_sampling_populate_fun1007__t*, _fself);
  size_t i0_758 = _self->i0_758; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i0_758, _b_821, _b_822, _ctx);
}


// lift anonymous function
struct kk_sampling_populate_fun1008__t {
  struct kk_function_s _base;
  kk_function_t model;
};
static kk_box_t kk_sampling_populate_fun1008(kk_function_t _fself, kk_box_t _b_832, kk_context_t* _ctx);
static kk_function_t kk_sampling_new_populate_fun1008(kk_function_t model, kk_context_t* _ctx) {
  struct kk_sampling_populate_fun1008__t* _self = kk_function_alloc_as(struct kk_sampling_populate_fun1008__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_sampling_populate_fun1008, kk_context());
  _self->model = model;
  return &_self->_base;
}

static kk_box_t kk_sampling_populate_fun1008(kk_function_t _fself, kk_box_t _b_832, kk_context_t* _ctx) {
  struct kk_sampling_populate_fun1008__t* _self = kk_function_as(struct kk_sampling_populate_fun1008__t*, _fself);
  kk_function_t model = _self->model; /* () -> <effects-and-types/score|188> 187 */
  kk_drop_match(_self, {kk_function_dup(model);}, {}, _ctx)
  kk_unit_t _x1009 = kk_Unit;
  kk_unit_unbox(_b_832);
  return kk_sampling__mlift749_populate(model, _x1009, _ctx);
}
static kk_box_t kk_sampling_populate_fun997(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_sampling_populate_fun997__t* _self = kk_function_as(struct kk_sampling_populate_fun997__t*, _fself);
  kk_integer_t k = _self->k; /* int */
  kk_function_t model = _self->model; /* () -> <effects-and-types/score|188> 187 */
  kk_drop_match(_self, {kk_integer_dup(k);kk_function_dup(model);}, {}, _ctx)
  kk_unit_t x_756 = kk_Unit;
  kk_effects_dash_and_dash_types__exp _x1;
  kk_effects_dash_and_dash_types__exp _x10 = kk_effects_dash_and_dash_types__new_Exp(0x0p+0, _ctx); /*effects-and-types/exp*/;
  kk_effects_dash_and_dash_types__exp _x2;
  double _x998;
  double _x999 = kk_integer_as_double(k,kk_context()); /*double*/
  _x998 = log(_x999); /*double*/
  _x2 = kk_effects_dash_and_dash_types__new_Exp(_x998, _ctx); /*effects-and-types/exp*/
  kk_box_t _x1000 = kk_std_core_hnd__open_none2(kk_sampling_new_populate_fun1001(_ctx), kk_effects_dash_and_dash_types__exp_box(_x10, _ctx), kk_effects_dash_and_dash_types__exp_box(_x2, _ctx), _ctx); /*3*/
  _x1 = kk_effects_dash_and_dash_types__exp_unbox(_x1000, _ctx); /*effects-and-types/exp*/
  size_t i0_758;
  kk_std_core_hnd__htag _x1005 = kk_std_core_hnd__htag_dup(kk_effects_dash_and_dash_types__tag_score); /*std/core/hnd/htag<effects-and-types/.hnd-score>*/
  i0_758 = kk_std_core_hnd__evv_index(_x1005, _ctx); /*std/core/hnd/ev-index*/
  kk_evv_t w = kk_evv_swap_create1(i0_758,kk_context()); /*std/core/hnd/evv<<effects-and-types/score|188>>*/;
  kk_unit_t y = kk_Unit;
  kk_effects_dash_and_dash_types_score(_x1, _ctx);
  kk_unit_t __w_l700_c9 = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x1006 = kk_std_core_hnd_yield_cont(kk_sampling_new_populate_fun1007(i0_758, _ctx), _ctx); /*3*/
    kk_unit_unbox(_x1006);
  }
  else {
    y;
  }
  if (kk_yielding(kk_context())) {
    return kk_std_core_hnd_yield_extend(kk_sampling_new_populate_fun1008(model, _ctx), _ctx);
  }
  return kk_sampling__mlift749_populate(model, x_756, _ctx);
}
static kk_box_t kk_sampling_populate_fun994(kk_function_t _fself, kk_integer_t _b_837, kk_context_t* _ctx) {
  struct kk_sampling_populate_fun994__t* _self = kk_function_as(struct kk_sampling_populate_fun994__t*, _fself);
  kk_integer_t k = _self->k; /* int */
  kk_function_t model = _self->model; /* () -> <effects-and-types/score|188> 187 */
  kk_drop_match(_self, {kk_integer_dup(k);kk_function_dup(model);}, {}, _ctx)
  kk_integer_drop(_b_837, _ctx);
  kk_std_core_types__tuple2_ _x995;
  kk_effects_dash_and_dash_types__exp _x996 = kk_effects_dash_and_dash_types__new_Exp(0x0p+0, _ctx); /*effects-and-types/exp*/
  _x995 = kk_handlers_weighted(_x996, kk_sampling_new_populate_fun997(k, model, _ctx), _ctx); /*(effects-and-types/exp, 1897)*/
  return kk_std_core_types__tuple2__box(_x995, _ctx);
}

kk_std_core__list kk_sampling_populate(kk_integer_t k, kk_function_t model, kk_context_t* _ctx) { /* forall<a,e> (k : int, model : () -> <effects-and-types/score|e> a) -> e effects-and-types/histogram<a> */ 
  kk_function_t _x993;
  kk_integer_dup(k);
  _x993 = kk_sampling_new_populate_fun994(k, model, _ctx); /*(int) -> 2 1*/
  return kk_std_core__lift21054_list_1(_x993, kk_integer_from_small(1), k, kk_std_core__new_Nil(_ctx), _ctx);
}


// lift anonymous function
struct kk_sampling_sum__histogram_fun1011__t {
  struct kk_function_s _base;
};
static kk_box_t kk_sampling_sum__histogram_fun1011(kk_function_t _fself, kk_box_t _b_849, kk_box_t _b_850, kk_context_t* _ctx);
static kk_function_t kk_sampling_new_sum__histogram_fun1011(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_sampling_sum__histogram_fun1011, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_sampling_sum__histogram_fun1011(kk_function_t _fself, kk_box_t _b_849, kk_box_t _b_850, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x1012;
  kk_std_core_types__tuple2_ _match_983 = kk_std_core_types__tuple2__unbox(_b_850, _ctx); /*(effects-and-types/exp, 255)*/;
  kk_box_t _box_x845 = _match_983.fst;
  kk_effects_dash_and_dash_types__exp _pat0 = kk_effects_dash_and_dash_types__exp_unbox(_box_x845, NULL);
  double w = _pat0.i;
  kk_std_core_types__tuple2__drop(_match_983, _ctx);
  double _x1014 = pow((0x1.5bf0a8b145769p1),w); /*double*/
  double _x1015 = kk_double_unbox(_b_849, _ctx); /*double*/
  _x1012 = (_x1014 + _x1015); /*double*/
  return kk_double_box(_x1012, _ctx);
}

double kk_sampling_sum__histogram(kk_std_core__list hist, kk_context_t* _ctx) { /* forall<a> (hist : effects-and-types/histogram<a>) -> double */ 
  kk_box_t _x1010 = kk_std_core_foldl(hist, kk_double_box(0x0p+0, _ctx), kk_sampling_new_sum__histogram_fun1011(_ctx), _ctx); /*2*/
  return kk_double_unbox(_x1010, _ctx);
}


// lift anonymous function
struct kk_sampling_normalise_fun1017__t {
  struct kk_function_s _base;
  kk_effects_dash_and_dash_types__exp total;
};
static kk_box_t kk_sampling_normalise_fun1017(kk_function_t _fself, kk_box_t _b_862, kk_context_t* _ctx);
static kk_function_t kk_sampling_new_normalise_fun1017(kk_effects_dash_and_dash_types__exp total, kk_context_t* _ctx) {
  struct kk_sampling_normalise_fun1017__t* _self = kk_function_alloc_as(struct kk_sampling_normalise_fun1017__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_sampling_normalise_fun1017, kk_context());
  _self->total = total;
  return &_self->_base;
}

static kk_box_t kk_sampling_normalise_fun1017(kk_function_t _fself, kk_box_t _b_862, kk_context_t* _ctx) {
  struct kk_sampling_normalise_fun1017__t* _self = kk_function_as(struct kk_sampling_normalise_fun1017__t*, _fself);
  kk_effects_dash_and_dash_types__exp total = _self->total; /* effects-and-types/exp */
  kk_drop_match(_self, {kk_effects_dash_and_dash_types__exp_dup(total);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x1018;
  kk_effects_dash_and_dash_types__exp _b_866_858;
  kk_effects_dash_and_dash_types__exp _match_981;
  kk_std_core_types__tuple2_ _match_982;
  kk_box_t _x1019 = kk_box_dup(_b_862); /*1*/
  _match_982 = kk_std_core_types__tuple2__unbox(_x1019, _ctx); /*(effects-and-types/exp, 519)*/
  kk_box_t _box_x856 = _match_982.fst;
  kk_effects_dash_and_dash_types__exp _x = kk_effects_dash_and_dash_types__exp_unbox(_box_x856, NULL);
  kk_std_core_types__tuple2__drop(_match_982, _ctx);
  _match_981 = _x; /*effects-and-types/exp*/
  double j = _match_981.i;
  double t = total.i;
  double _x1021 = (j - t); /*double*/
  _b_866_858 = kk_effects_dash_and_dash_types__new_Exp(_x1021, _ctx); /*effects-and-types/exp*/
  kk_box_t _x1022;
  kk_std_core_types__tuple2_ _match_980 = kk_std_core_types__tuple2__unbox(_b_862, _ctx); /*(effects-and-types/exp, 519)*/;
  kk_box_t _box_x857 = _match_980.fst;
  kk_box_t _x0 = _match_980.snd;
  kk_box_dup(_x0);
  kk_std_core_types__tuple2__drop(_match_980, _ctx);
  _x1022 = _x0; /*519*/
  _x1018 = kk_std_core_types__new_dash__lp__comma__rp_(kk_effects_dash_and_dash_types__exp_box(_b_866_858, _ctx), _x1022, _ctx); /*(4, 5)*/
  return kk_std_core_types__tuple2__box(_x1018, _ctx);
}

kk_std_core__list kk_sampling_normalise(kk_std_core__list histogram, kk_context_t* _ctx) { /* forall<a> (histogram : effects-and-types/histogram<a>) -> effects-and-types/histogram<a> */ 
  kk_effects_dash_and_dash_types__exp total;
  kk_std_core__list _x1016 = kk_std_core__list_dup(histogram); /*effects-and-types/histogram<519>*/
  total = kk_sampling_sum__weights(_x1016, _ctx); /*effects-and-types/exp*/
  return kk_std_core_map_5(histogram, kk_sampling_new_normalise_fun1017(total, _ctx), _ctx);
}
 
// monadic lift

kk_std_core__list kk_sampling__mlift750_importance__sampling(kk_std_core__list _y_4, kk_context_t* _ctx) { /* forall<a,e> (effects-and-types/histogram<a>) -> <std/num/random/random,effects-and-types/sample|e> effects-and-types/histogram<a> */ 
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*std/core/hnd/evv<(<>)>*/;
  kk_std_core__list x = kk_sampling_normalise(_y_4, _ctx); /*effects-and-types/histogram<547>*/;
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  return x;
}


// lift anonymous function
struct kk_sampling_importance__sampling_fun1025__t {
  struct kk_function_s _base;
  kk_function_t model;
};
static kk_box_t kk_sampling_importance__sampling_fun1025(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_sampling_new_importance__sampling_fun1025(kk_function_t model, kk_context_t* _ctx) {
  struct kk_sampling_importance__sampling_fun1025__t* _self = kk_function_alloc_as(struct kk_sampling_importance__sampling_fun1025__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_sampling_importance__sampling_fun1025, kk_context());
  _self->model = model;
  return &_self->_base;
}



// lift anonymous function
struct kk_sampling_importance__sampling_fun1028__t {
  struct kk_function_s _base;
};
static kk_box_t kk_sampling_importance__sampling_fun1028(kk_function_t _fself, kk_box_t _b_869, kk_context_t* _ctx);
static kk_function_t kk_sampling_new_importance__sampling_fun1028(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_sampling_importance__sampling_fun1028, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_sampling_importance__sampling_fun1028(kk_function_t _fself, kk_box_t _b_869, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core__list _x1029;
  kk_std_core__list _x1030 = kk_std_core__list_unbox(_b_869, _ctx); /*effects-and-types/histogram<547>*/
  _x1029 = kk_sampling__mlift750_importance__sampling(_x1030, _ctx); /*effects-and-types/histogram<547>*/
  return kk_std_core__list_box(_x1029, _ctx);
}
static kk_box_t kk_sampling_importance__sampling_fun1025(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_sampling_importance__sampling_fun1025__t* _self = kk_function_as(struct kk_sampling_importance__sampling_fun1025__t*, _fself);
  kk_function_t model = _self->model; /* effects-and-types/model<547,<std/num/random/random|548>> */
  kk_drop_match(_self, {kk_function_dup(model);}, {}, _ctx)
  kk_std_core__list _x1026;
  kk_std_core__list x_767 = kk_sampling_populate(kk_integer_from_small(2000), model, _ctx); /*effects-and-types/histogram<547>*/;
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_767, _ctx);
    kk_box_t _x1027 = kk_std_core_hnd_yield_extend(kk_sampling_new_importance__sampling_fun1028(_ctx), _ctx); /*2*/
    _x1026 = kk_std_core__list_unbox(_x1027, _ctx); /*effects-and-types/histogram<547>*/
  }
  else {
    _x1026 = kk_sampling__mlift750_importance__sampling(x_767, _ctx); /*effects-and-types/histogram<547>*/
  }
  return kk_std_core__list_box(_x1026, _ctx);
}

kk_std_core__list kk_sampling_importance__sampling(kk_function_t model, kk_context_t* _ctx) { /* forall<a,e> (model : effects-and-types/model<a,<std/num/random/random|e>>) -> <std/num/random/random|e> effects-and-types/histogram<a> */ 
  kk_box_t _x1024 = kk_handlers_random__sampler(kk_sampling_new_importance__sampling_fun1025(model, _ctx), _ctx); /*328*/
  return kk_std_core__list_unbox(_x1024, _ctx);
}
 
// lift


// lift anonymous function
struct kk_sampling__lift737_weighted__choice_fun1045__t {
  struct kk_function_s _base;
};
static kk_box_t kk_sampling__lift737_weighted__choice_fun1045(kk_function_t _fself, kk_box_t _b_887, kk_context_t* _ctx);
static kk_function_t kk_sampling__new_lift737_weighted__choice_fun1045(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_sampling__lift737_weighted__choice_fun1045, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_sampling__lift737_weighted__choice_fun1045(kk_function_t _fself, kk_box_t _b_887, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x1046;
  kk_effects_dash_and_dash_types__exp _x1047 = kk_effects_dash_and_dash_types__exp_unbox(_b_887, _ctx); /*effects-and-types/exp*/
  _x1046 = kk_exponents_exp__to__double(_x1047, _ctx); /*double*/
  return kk_double_box(_x1046, _ctx);
}

kk_box_t kk_sampling__lift737_weighted__choice(double fuel, kk_std_core__list ws, kk_context_t* _ctx) { /* forall<a> (fuel : double, ws : list<(effects-and-types/exp, a)>) -> exn a */ 
  kk__tailcall: ;
  if (kk_std_core__is_Nil(ws)) {
    kk_std_core__exception exn_21561;
    kk_string_t _x1031;
    kk_define_string_literal(, _s1032, 62, "Histogram is empty! Cannot select any element when resampling!")
    _x1031 = kk_string_dup(_s1032); /*string*/
    kk_std_core__exception_info _x1033;
    kk_std_core_types__optional _match_978 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
    if (kk_std_core_types__is_Optional(_match_978)) {
      kk_box_t _box_x874 = _match_978._cons.Optional.value;
      kk_std_core__exception_info _info_14279 = kk_std_core__exception_info_unbox(_box_x874, NULL);
      kk_std_core__exception_info_dup(_info_14279);
      kk_std_core_types__optional_drop(_match_978, _ctx);
      _x1033 = _info_14279; /*exception-info*/
      goto _match1034;
    }
    _x1033 = kk_std_core__new_ExnError(_ctx); /*exception-info*/
    _match1034: ;
    exn_21561 = kk_std_core__new_Exception(_x1031, _x1033, _ctx); /*exception*/
    kk_std_core_hnd__ev ev_21562;
    size_t _x1036 = ((size_t)0); /*size_t*/
    ev_21562 = kk_evv_at(_x1036,kk_context()); /*std/core/hnd/ev<.hnd-exn>*/
    struct kk_std_core_hnd_Ev* _con1037 = kk_std_core_hnd__as_Ev(ev_21562);
    kk_std_core_hnd__marker m = _con1037->marker;
    kk_box_t _box_x875 = _con1037->hnd;
    kk_std_core__hnd_exn h = kk_std_core__hnd_exn_unbox(_box_x875, NULL);
    kk_std_core__hnd_exn_dup(h);
    kk_std_core_hnd__clause1 _match_977;
    struct kk_std_core__Hnd_exn* _con1039 = kk_std_core__as_Hnd_exn(h);
    kk_std_core_hnd__clause1 except_throw_exn = _con1039->except_throw_exn;
    if (kk_std_core__hnd_exn_is_unique(h)) {
      kk_std_core__hnd_exn_free(h);
    }
    else {
      kk_std_core_hnd__clause1_dup(except_throw_exn);
      kk_std_core__hnd_exn_decref(h, _ctx);
    }
    _match_977 = except_throw_exn; /*forall<a> std/core/hnd/clause1<exception,a,.hnd-exn,6,7>*/
    kk_function_t _fun_unbox_x879 = _match_977.clause;
    return kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x879, (_fun_unbox_x879, m, ev_21562, kk_std_core__exception_box(exn_21561, _ctx), _ctx));
  }
  struct kk_std_core_Cons* _con1040 = kk_std_core__as_Cons(ws);
  kk_box_t _box_x883 = _con1040->head;
  kk_std_core__list wxs = _con1040->tail;
  kk_std_core_types__tuple2_ _pat10 = kk_std_core_types__tuple2__unbox(_box_x883, NULL);
  kk_box_t _box_x884 = _pat10.fst;
  kk_box_t x = _pat10.snd;
  kk_effects_dash_and_dash_types__exp w = kk_effects_dash_and_dash_types__exp_unbox(_box_x884, NULL);
  if (kk_std_core__list_is_unique(ws)) {
    kk_box_dup(x);
    kk_box_drop(_box_x883, _ctx);
    kk_std_core__list_free(ws);
  }
  else {
    kk_std_core__list_dup(wxs);
    kk_box_dup(x);
    kk_std_core__list_decref(ws, _ctx);
  }
  double fuel__new;
  double _x1043;
  kk_box_t _x1044 = kk_std_core_hnd__open_none1(kk_sampling__new_lift737_weighted__choice_fun1045(_ctx), kk_effects_dash_and_dash_types__exp_box(w, _ctx), _ctx); /*2*/
  _x1043 = kk_double_unbox(_x1044, _ctx); /*double*/
  fuel__new = (fuel - _x1043); /*double*/
  bool _match_976 = (fuel__new <= (0x0p+0)); /*bool*/;
  if (_match_976) {
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
struct kk_sampling__mlift751_weighted__choice_fun1050__t {
  struct kk_function_s _base;
};
static kk_box_t kk_sampling__mlift751_weighted__choice_fun1050(kk_function_t _fself, kk_box_t _b_895, kk_context_t* _ctx);
static kk_function_t kk_sampling__new_mlift751_weighted__choice_fun1050(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_sampling__mlift751_weighted__choice_fun1050, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_sampling__mlift751_weighted__choice_fun1050(kk_function_t _fself, kk_box_t _b_895, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x1051;
  kk_effects_dash_and_dash_types__exp _x1052 = kk_effects_dash_and_dash_types__exp_unbox(_b_895, _ctx); /*effects-and-types/exp*/
  _x1051 = kk_exponents_exp__to__double(_x1052, _ctx); /*double*/
  return kk_double_box(_x1051, _ctx);
}


// lift anonymous function
struct kk_sampling__mlift751_weighted__choice_fun1053__t {
  struct kk_function_s _base;
  size_t i_771;
};
static kk_box_t kk_sampling__mlift751_weighted__choice_fun1053(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx);
static kk_function_t kk_sampling__new_mlift751_weighted__choice_fun1053(size_t i_771, kk_context_t* _ctx) {
  struct kk_sampling__mlift751_weighted__choice_fun1053__t* _self = kk_function_alloc_as(struct kk_sampling__mlift751_weighted__choice_fun1053__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_sampling__mlift751_weighted__choice_fun1053, kk_context());
  _self->i_771 = i_771;
  return &_self->_base;
}

static kk_box_t kk_sampling__mlift751_weighted__choice_fun1053(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_sampling__mlift751_weighted__choice_fun1053__t* _self = kk_function_as(struct kk_sampling__mlift751_weighted__choice_fun1053__t*, _fself);
  size_t i_771 = _self->i_771; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_771, cont, res, _ctx);
}

kk_box_t kk_sampling__mlift751_weighted__choice(kk_std_core__list histogram, kk_effects_dash_and_dash_types__exp total__w, double _y_10, kk_context_t* _ctx) { /* forall<a> (histogram : effects-and-types/histogram<a>, total_w : effects-and-types/exp, double) -> <effects-and-types/sample,exn> a */ 
  double total__fuel;
  double _x1048;
  kk_box_t _x1049 = kk_std_core_hnd__open_none1(kk_sampling__new_mlift751_weighted__choice_fun1050(_ctx), kk_effects_dash_and_dash_types__exp_box(total__w, _ctx), _ctx); /*2*/
  _x1048 = kk_double_unbox(_x1049, _ctx); /*double*/
  total__fuel = (_x1048 * _y_10); /*double*/
  size_t i_771 = ((size_t)0); /*std/core/hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_771,kk_context()); /*std/core/hnd/evv<<exn,effects-and-types/sample>>*/;
  kk_box_t y = kk_sampling__lift737_weighted__choice(total__fuel, histogram, _ctx); /*677*/;
  kk_unit_t __w_l717_c9 = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_drop(y, _ctx);
    return kk_std_core_hnd_yield_cont(kk_sampling__new_mlift751_weighted__choice_fun1053(i_771, _ctx), _ctx);
  }
  return y;
}
 
// This chooses a histogram with the probabilirt of


// lift anonymous function
struct kk_sampling_weighted__choice_fun1061__t {
  struct kk_function_s _base;
  size_t i_780;
};
static kk_box_t kk_sampling_weighted__choice_fun1061(kk_function_t _fself, kk_function_t _b_911, kk_box_t _b_912, kk_context_t* _ctx);
static kk_function_t kk_sampling_new_weighted__choice_fun1061(size_t i_780, kk_context_t* _ctx) {
  struct kk_sampling_weighted__choice_fun1061__t* _self = kk_function_alloc_as(struct kk_sampling_weighted__choice_fun1061__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_sampling_weighted__choice_fun1061, kk_context());
  _self->i_780 = i_780;
  return &_self->_base;
}

static kk_box_t kk_sampling_weighted__choice_fun1061(kk_function_t _fself, kk_function_t _b_911, kk_box_t _b_912, kk_context_t* _ctx) {
  struct kk_sampling_weighted__choice_fun1061__t* _self = kk_function_as(struct kk_sampling_weighted__choice_fun1061__t*, _fself);
  size_t i_780 = _self->i_780; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_780, _b_911, _b_912, _ctx);
}


// lift anonymous function
struct kk_sampling_weighted__choice_fun1062__t {
  struct kk_function_s _base;
  kk_std_core__list histogram;
  kk_effects_dash_and_dash_types__exp total__w;
};
static kk_box_t kk_sampling_weighted__choice_fun1062(kk_function_t _fself, kk_box_t _b_922, kk_context_t* _ctx);
static kk_function_t kk_sampling_new_weighted__choice_fun1062(kk_std_core__list histogram, kk_effects_dash_and_dash_types__exp total__w, kk_context_t* _ctx) {
  struct kk_sampling_weighted__choice_fun1062__t* _self = kk_function_alloc_as(struct kk_sampling_weighted__choice_fun1062__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_sampling_weighted__choice_fun1062, kk_context());
  _self->histogram = histogram;
  _self->total__w = total__w;
  return &_self->_base;
}

static kk_box_t kk_sampling_weighted__choice_fun1062(kk_function_t _fself, kk_box_t _b_922, kk_context_t* _ctx) {
  struct kk_sampling_weighted__choice_fun1062__t* _self = kk_function_as(struct kk_sampling_weighted__choice_fun1062__t*, _fself);
  kk_std_core__list histogram = _self->histogram; /* effects-and-types/histogram<677> */
  kk_effects_dash_and_dash_types__exp total__w = _self->total__w; /* effects-and-types/exp */
  kk_drop_match(_self, {kk_std_core__list_dup(histogram);kk_effects_dash_and_dash_types__exp_dup(total__w);}, {}, _ctx)
  double _x1063 = kk_double_unbox(_b_922, _ctx); /*double*/
  return kk_sampling__mlift751_weighted__choice(histogram, total__w, _x1063, _ctx);
}


// lift anonymous function
struct kk_sampling_weighted__choice_fun1066__t {
  struct kk_function_s _base;
};
static kk_box_t kk_sampling_weighted__choice_fun1066(kk_function_t _fself, kk_box_t _b_925, kk_context_t* _ctx);
static kk_function_t kk_sampling_new_weighted__choice_fun1066(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_sampling_weighted__choice_fun1066, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_sampling_weighted__choice_fun1066(kk_function_t _fself, kk_box_t _b_925, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x1067;
  kk_effects_dash_and_dash_types__exp _x1068 = kk_effects_dash_and_dash_types__exp_unbox(_b_925, _ctx); /*effects-and-types/exp*/
  _x1067 = kk_exponents_exp__to__double(_x1068, _ctx); /*double*/
  return kk_double_box(_x1067, _ctx);
}


// lift anonymous function
struct kk_sampling_weighted__choice_fun1069__t {
  struct kk_function_s _base;
  size_t i0_783;
};
static kk_box_t kk_sampling_weighted__choice_fun1069(kk_function_t _fself, kk_function_t cont0, kk_box_t res0, kk_context_t* _ctx);
static kk_function_t kk_sampling_new_weighted__choice_fun1069(size_t i0_783, kk_context_t* _ctx) {
  struct kk_sampling_weighted__choice_fun1069__t* _self = kk_function_alloc_as(struct kk_sampling_weighted__choice_fun1069__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_sampling_weighted__choice_fun1069, kk_context());
  _self->i0_783 = i0_783;
  return &_self->_base;
}

static kk_box_t kk_sampling_weighted__choice_fun1069(kk_function_t _fself, kk_function_t cont0, kk_box_t res0, kk_context_t* _ctx) {
  struct kk_sampling_weighted__choice_fun1069__t* _self = kk_function_as(struct kk_sampling_weighted__choice_fun1069__t*, _fself);
  size_t i0_783 = _self->i0_783; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i0_783, cont0, res0, _ctx);
}

kk_box_t kk_sampling_weighted__choice(kk_std_core__list histogram, kk_context_t* _ctx) { /* forall<a> (histogram : effects-and-types/histogram<a>) -> <exn,effects-and-types/sample> a */ 
  kk_effects_dash_and_dash_types__exp total__w;
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*std/core/hnd/evv<(<>)>*/;
  kk_effects_dash_and_dash_types__exp x;
  kk_std_core__list _x1054 = kk_std_core__list_dup(histogram); /*effects-and-types/histogram<677>*/
  x = kk_sampling_sum__weights(_x1054, _ctx); /*effects-and-types/exp*/
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  total__w = x; /*effects-and-types/exp*/
  double x0_777;
  size_t i_780 = ((size_t)1); /*std/core/hnd/ev-index*/;
  kk_evv_t w0 = kk_evv_swap_create1(i_780,kk_context()); /*std/core/hnd/evv<<effects-and-types/sample,exn>>*/;
  double y;
  kk_std_core_hnd__ev ev_404;
  size_t _x1055 = ((size_t)0); /*size_t*/
  ev_404 = kk_evv_at(_x1055,kk_context()); /*std/core/hnd/ev<effects-and-types/.hnd-sample>*/
  kk_box_t _x1056;
  struct kk_std_core_hnd_Ev* _con1057 = kk_std_core_hnd__as_Ev(ev_404);
  kk_std_core_hnd__marker m = _con1057->marker;
  kk_box_t _box_x898 = _con1057->hnd;
  kk_effects_dash_and_dash_types__hnd_sample h = kk_effects_dash_and_dash_types__hnd_sample_unbox(_box_x898, NULL);
  kk_effects_dash_and_dash_types__hnd_sample_dup(h);
  kk_std_core_hnd__clause0 _match_974;
  struct kk_effects_dash_and_dash_types__Hnd_sample* _con1059 = kk_effects_dash_and_dash_types__as_Hnd_sample(h);
  kk_std_core_hnd__clause0 fun_sample = _con1059->fun_sample;
  if (kk_effects_dash_and_dash_types__hnd_sample_is_unique(h)) {
    kk_effects_dash_and_dash_types__hnd_sample_free(h);
  }
  else {
    kk_std_core_hnd__clause0_dup(fun_sample);
    kk_effects_dash_and_dash_types__hnd_sample_decref(h, _ctx);
  }
  _match_974 = fun_sample; /*std/core/hnd/clause0<double,effects-and-types/.hnd-sample,6,7>*/
  kk_function_t _fun_unbox_x901 = _match_974.clause;
  _x1056 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x901, (_fun_unbox_x901, m, ev_404, _ctx)); /*6*/
  y = kk_double_unbox(_x1056, _ctx); /*double*/
  kk_unit_t __w_l683_c9 = kk_Unit;
  kk_evv_set(w0,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x1060 = kk_std_core_hnd_yield_cont(kk_sampling_new_weighted__choice_fun1061(i_780, _ctx), _ctx); /*3*/
    x0_777 = kk_double_unbox(_x1060, _ctx); /*double*/
  }
  else {
    x0_777 = y; /*double*/
  }
  if (kk_yielding(kk_context())) {
    return kk_std_core_hnd_yield_extend(kk_sampling_new_weighted__choice_fun1062(histogram, total__w, _ctx), _ctx);
  }
  double total__fuel;
  double _x1064;
  kk_box_t _x1065 = kk_std_core_hnd__open_none1(kk_sampling_new_weighted__choice_fun1066(_ctx), kk_effects_dash_and_dash_types__exp_box(total__w, _ctx), _ctx); /*2*/
  _x1064 = kk_double_unbox(_x1065, _ctx); /*double*/
  total__fuel = (_x1064 * x0_777); /*double*/
  size_t i0_783 = ((size_t)0); /*std/core/hnd/ev-index*/;
  kk_evv_t w1 = kk_evv_swap_create1(i0_783,kk_context()); /*std/core/hnd/evv<<exn,effects-and-types/sample>>*/;
  kk_box_t y0 = kk_sampling__lift737_weighted__choice(total__fuel, histogram, _ctx); /*677*/;
  kk_unit_t __w_l717_c9 = kk_Unit;
  kk_evv_set(w1,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_drop(y0, _ctx);
    return kk_std_core_hnd_yield_cont(kk_sampling_new_weighted__choice_fun1069(i0_783, _ctx), _ctx);
  }
  return y0;
}
 
// monadic lift


// lift anonymous function
struct kk_sampling__mlift752_resample_fun1071__t {
  struct kk_function_s _base;
};
static kk_box_t kk_sampling__mlift752_resample_fun1071(kk_function_t _fself, kk_box_t _b_937, kk_context_t* _ctx);
static kk_function_t kk_sampling__new_mlift752_resample_fun1071(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_sampling__mlift752_resample_fun1071, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_sampling__mlift752_resample_fun1071(kk_function_t _fself, kk_box_t _b_937, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core__list _x1072 = kk_std_core__list_unbox(_b_937, _ctx); /*effects-and-types/histogram<736>*/
  return kk_sampling_weighted__choice(_x1072, _ctx);
}

kk_box_t kk_sampling__mlift752_resample(kk_std_core__list histogram, kk_unit_t wild__, kk_context_t* _ctx) { /* forall<a> (histogram : effects-and-types/histogram<a>, wild_ : ()) -> <effects-and-types/score,exn,effects-and-types/sample> a */ 
  kk_vector_t _b_938_934;
  kk_std_core__list _x1070;
  size_t _b_941_932 = ((size_t)0); /*std/core/hnd/ev-index*/;
  kk_std_core__list _b_942_933;
  size_t _b_943_930 = ((size_t)1); /*std/core/hnd/ev-index*/;
  _b_942_933 = kk_std_core__new_Cons(kk_reuse_null, kk_size_box(_b_943_930, _ctx), kk_std_core__new_Nil(_ctx), _ctx); /*list<std/core/hnd/ev-index>*/
  _x1070 = kk_std_core__new_Cons(kk_reuse_null, kk_size_box(_b_941_932, _ctx), _b_942_933, _ctx); /*list<0>*/
  _b_938_934 = kk_std_core_unvlist(_x1070, _ctx); /*vector<std/core/hnd/ev-index>*/
  return kk_std_core_hnd__open1(_b_938_934, kk_sampling__new_mlift752_resample_fun1071(_ctx), kk_std_core__list_box(histogram, _ctx), _ctx);
}


// lift anonymous function
struct kk_sampling_resample_fun1075__t {
  struct kk_function_s _base;
  kk_std_core__list histogram;
  kk_effects_dash_and_dash_types__exp total__w;
};
static kk_box_t kk_sampling_resample_fun1075(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_sampling_new_resample_fun1075(kk_std_core__list histogram, kk_effects_dash_and_dash_types__exp total__w, kk_context_t* _ctx) {
  struct kk_sampling_resample_fun1075__t* _self = kk_function_alloc_as(struct kk_sampling_resample_fun1075__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_sampling_resample_fun1075, kk_context());
  _self->histogram = histogram;
  _self->total__w = total__w;
  return &_self->_base;
}



// lift anonymous function
struct kk_sampling_resample_fun1077__t {
  struct kk_function_s _base;
  size_t i_791;
};
static kk_box_t kk_sampling_resample_fun1077(kk_function_t _fself, kk_function_t _b_950, kk_box_t _b_951, kk_context_t* _ctx);
static kk_function_t kk_sampling_new_resample_fun1077(size_t i_791, kk_context_t* _ctx) {
  struct kk_sampling_resample_fun1077__t* _self = kk_function_alloc_as(struct kk_sampling_resample_fun1077__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_sampling_resample_fun1077, kk_context());
  _self->i_791 = i_791;
  return &_self->_base;
}

static kk_box_t kk_sampling_resample_fun1077(kk_function_t _fself, kk_function_t _b_950, kk_box_t _b_951, kk_context_t* _ctx) {
  struct kk_sampling_resample_fun1077__t* _self = kk_function_as(struct kk_sampling_resample_fun1077__t*, _fself);
  size_t i_791 = _self->i_791; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_791, _b_950, _b_951, _ctx);
}


// lift anonymous function
struct kk_sampling_resample_fun1078__t {
  struct kk_function_s _base;
  kk_std_core__list histogram;
};
static kk_box_t kk_sampling_resample_fun1078(kk_function_t _fself, kk_box_t _b_961, kk_context_t* _ctx);
static kk_function_t kk_sampling_new_resample_fun1078(kk_std_core__list histogram, kk_context_t* _ctx) {
  struct kk_sampling_resample_fun1078__t* _self = kk_function_alloc_as(struct kk_sampling_resample_fun1078__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_sampling_resample_fun1078, kk_context());
  _self->histogram = histogram;
  return &_self->_base;
}

static kk_box_t kk_sampling_resample_fun1078(kk_function_t _fself, kk_box_t _b_961, kk_context_t* _ctx) {
  struct kk_sampling_resample_fun1078__t* _self = kk_function_as(struct kk_sampling_resample_fun1078__t*, _fself);
  kk_std_core__list histogram = _self->histogram; /* effects-and-types/histogram<736> */
  kk_drop_match(_self, {kk_std_core__list_dup(histogram);}, {}, _ctx)
  kk_unit_t _x1079 = kk_Unit;
  kk_unit_unbox(_b_961);
  return kk_sampling__mlift752_resample(histogram, _x1079, _ctx);
}
static kk_box_t kk_sampling_resample_fun1075(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_sampling_resample_fun1075__t* _self = kk_function_as(struct kk_sampling_resample_fun1075__t*, _fself);
  kk_std_core__list histogram = _self->histogram; /* effects-and-types/histogram<736> */
  kk_effects_dash_and_dash_types__exp total__w = _self->total__w; /* effects-and-types/exp */
  kk_drop_match(_self, {kk_std_core__list_dup(histogram);kk_effects_dash_and_dash_types__exp_dup(total__w);}, {}, _ctx)
  kk_unit_t x0_789 = kk_Unit;
  size_t i_791 = ((size_t)2); /*std/core/hnd/ev-index*/;
  kk_evv_t w0 = kk_evv_swap_create1(i_791,kk_context()); /*std/core/hnd/evv<<effects-and-types/score,exn,effects-and-types/sample>>*/;
  kk_unit_t y = kk_Unit;
  kk_effects_dash_and_dash_types_score(total__w, _ctx);
  kk_unit_t __w_l700_c9 = kk_Unit;
  kk_evv_set(w0,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x1076 = kk_std_core_hnd_yield_cont(kk_sampling_new_resample_fun1077(i_791, _ctx), _ctx); /*3*/
    kk_unit_unbox(_x1076);
  }
  else {
    y;
  }
  if (kk_yielding(kk_context())) {
    return kk_std_core_hnd_yield_extend(kk_sampling_new_resample_fun1078(histogram, _ctx), _ctx);
  }
  return kk_sampling__mlift752_resample(histogram, x0_789, _ctx);
}

kk_std_core__list kk_sampling_resample(kk_std_core__list histogram, kk_context_t* _ctx) { /* forall<a> (histogram : effects-and-types/histogram<a>) -> <exn,effects-and-types/sample> effects-and-types/histogram<a> */ 
  kk_integer_t n;
  kk_std_core__list _x1073 = kk_std_core__list_dup(histogram); /*effects-and-types/histogram<736>*/
  n = kk_std_core_length_1(_x1073, _ctx); /*int*/
  kk_effects_dash_and_dash_types__exp total__w;
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*std/core/hnd/evv<(<>)>*/;
  kk_effects_dash_and_dash_types__exp x;
  kk_std_core__list _x1074 = kk_std_core__list_dup(histogram); /*effects-and-types/histogram<736>*/
  x = kk_sampling_sum__weights(_x1074, _ctx); /*effects-and-types/exp*/
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  total__w = x; /*effects-and-types/exp*/
  return kk_sampling_populate(n, kk_sampling_new_resample_fun1075(histogram, total__w, _ctx), _ctx);
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
