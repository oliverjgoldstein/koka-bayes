// Koka generated module: "output-and-plot", koka version: 2.1.3
#include "output_dash_and_dash_plot.h"
 
// monadic lift

kk_string_t kk_output_dash_and_dash_plot__mlift5053_list_join(kk_std_core__list xs, kk_context_t* _ctx) { /* forall<e> (xs : list<string>) -> e string */ 
  kk_string_t _x5458;
  kk_define_string_literal(, _s5459, 1, "[")
  _x5458 = kk_string_dup(_s5459); /*string*/
  kk_string_t _x5460;
  kk_string_t _x5461;
  if (kk_std_core__is_Nil(xs)) {
    _x5461 = kk_string_empty(); /*string*/
  }
  else {
    struct kk_std_core_Cons* _con5463 = kk_std_core__as_Cons(xs);
    kk_box_t _box_x5139 = _con5463->head;
    kk_std_core__list xx = _con5463->tail;
    kk_string_t x = kk_string_unbox(_box_x5139);
    if (kk_std_core__list_is_unique(xs)) {
      kk_std_core__list_free(xs);
    }
    else {
      kk_string_dup(x);
      kk_std_core__list_dup(xx);
      kk_std_core__list_decref(xs, _ctx);
    }
    kk_string_t _x5465;
    kk_define_string_literal(, _s5466, 1, ",")
    _x5465 = kk_string_dup(_s5466); /*string*/
    _x5461 = kk_std_core__lift21050_joinsep(_x5465, xx, x, _ctx); /*string*/
  }
  kk_string_t _x5467;
  kk_define_string_literal(, _s5468, 1, "]")
  _x5467 = kk_string_dup(_s5468); /*string*/
  _x5460 = kk_std_core__lp__plus__plus__1_rp_(_x5461, _x5467, _ctx); /*string*/
  return kk_std_core__lp__plus__plus__1_rp_(_x5458, _x5460, _ctx);
}


// lift anonymous function
struct kk_output_dash_and_dash_plot_list_join_fun5469__t {
  struct kk_function_s _base;
  kk_function_t elem;
};
static kk_box_t kk_output_dash_and_dash_plot_list_join_fun5469(kk_function_t _fself, kk_integer_t _b_5144, kk_context_t* _ctx);
static kk_function_t kk_output_dash_and_dash_plot_new_list_join_fun5469(kk_function_t elem, kk_context_t* _ctx) {
  struct kk_output_dash_and_dash_plot_list_join_fun5469__t* _self = kk_function_alloc_as(struct kk_output_dash_and_dash_plot_list_join_fun5469__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_output_dash_and_dash_plot_list_join_fun5469, kk_context());
  _self->elem = elem;
  return &_self->_base;
}

static kk_box_t kk_output_dash_and_dash_plot_list_join_fun5469(kk_function_t _fself, kk_integer_t _b_5144, kk_context_t* _ctx) {
  struct kk_output_dash_and_dash_plot_list_join_fun5469__t* _self = kk_function_as(struct kk_output_dash_and_dash_plot_list_join_fun5469__t*, _fself);
  kk_function_t elem = _self->elem; /* (int) -> 5 string */
  kk_drop_match(_self, {kk_function_dup(elem);}, {}, _ctx)
  kk_string_t _x5470 = kk_function_call(kk_string_t, (kk_function_t, kk_integer_t, kk_context_t*), elem, (elem, _b_5144, _ctx)); /*string*/
  return kk_string_box(_x5470);
}


// lift anonymous function
struct kk_output_dash_and_dash_plot_list_join_fun5472__t {
  struct kk_function_s _base;
};
static kk_box_t kk_output_dash_and_dash_plot_list_join_fun5472(kk_function_t _fself, kk_box_t _b_5150, kk_context_t* _ctx);
static kk_function_t kk_output_dash_and_dash_plot_new_list_join_fun5472(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_output_dash_and_dash_plot_list_join_fun5472, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_output_dash_and_dash_plot_list_join_fun5472(kk_function_t _fself, kk_box_t _b_5150, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x5473;
  kk_std_core__list _x5474 = kk_std_core__list_unbox(_b_5150, _ctx); /*list<string>*/
  _x5473 = kk_output_dash_and_dash_plot__mlift5053_list_join(_x5474, _ctx); /*string*/
  return kk_string_box(_x5473);
}

kk_string_t kk_output_dash_and_dash_plot_list_join(kk_integer_t len, kk_function_t elem, kk_context_t* _ctx) { /* forall<e> (len : int, elem : (int) -> e string) -> e string */ 
  kk_std_core__list x_5056 = kk_std_core__lift21054_list_1(kk_output_dash_and_dash_plot_new_list_join_fun5469(elem, _ctx), kk_integer_from_small(1), len, kk_std_core__new_Nil(_ctx), _ctx); /*list<string>*/;
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_5056, _ctx);
    kk_box_t _x5471 = kk_std_core_hnd_yield_extend(kk_output_dash_and_dash_plot_new_list_join_fun5472(_ctx), _ctx); /*2*/
    return kk_string_unbox(_x5471);
  }
  kk_string_t _x5475;
  kk_define_string_literal(, _s5476, 1, "[")
  _x5475 = kk_string_dup(_s5476); /*string*/
  kk_string_t _x5477;
  kk_string_t _x5478;
  if (kk_std_core__is_Nil(x_5056)) {
    _x5478 = kk_string_empty(); /*string*/
  }
  else {
    struct kk_std_core_Cons* _con5480 = kk_std_core__as_Cons(x_5056);
    kk_box_t _box_x5151 = _con5480->head;
    kk_std_core__list xx = _con5480->tail;
    kk_string_t x = kk_string_unbox(_box_x5151);
    if (kk_std_core__list_is_unique(x_5056)) {
      kk_std_core__list_free(x_5056);
    }
    else {
      kk_string_dup(x);
      kk_std_core__list_dup(xx);
      kk_std_core__list_decref(x_5056, _ctx);
    }
    kk_string_t _x5482;
    kk_define_string_literal(, _s5483, 1, ",")
    _x5482 = kk_string_dup(_s5483); /*string*/
    _x5478 = kk_std_core__lift21050_joinsep(_x5482, xx, x, _ctx); /*string*/
  }
  kk_string_t _x5484;
  kk_define_string_literal(, _s5485, 1, "]")
  _x5484 = kk_string_dup(_s5485); /*string*/
  _x5477 = kk_std_core__lp__plus__plus__1_rp_(_x5478, _x5484, _ctx); /*string*/
  return kk_std_core__lp__plus__plus__1_rp_(_x5475, _x5477, _ctx);
}


// lift anonymous function
struct kk_output_dash_and_dash_plot_list__to__csv_fun5492__t {
  struct kk_function_s _base;
  kk_ref_t loc;
  kk_std_core__list xs;
};
static kk_unit_t kk_output_dash_and_dash_plot_list__to__csv_fun5492(kk_function_t _fself, kk_integer_t i, kk_context_t* _ctx);
static kk_function_t kk_output_dash_and_dash_plot_new_list__to__csv_fun5492(kk_ref_t loc, kk_std_core__list xs, kk_context_t* _ctx) {
  struct kk_output_dash_and_dash_plot_list__to__csv_fun5492__t* _self = kk_function_alloc_as(struct kk_output_dash_and_dash_plot_list__to__csv_fun5492__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_output_dash_and_dash_plot_list__to__csv_fun5492, kk_context());
  _self->loc = loc;
  _self->xs = xs;
  return &_self->_base;
}

static kk_unit_t kk_output_dash_and_dash_plot_list__to__csv_fun5492(kk_function_t _fself, kk_integer_t i, kk_context_t* _ctx) {
  struct kk_output_dash_and_dash_plot_list__to__csv_fun5492__t* _self = kk_function_as(struct kk_output_dash_and_dash_plot_list__to__csv_fun5492__t*, _fself);
  kk_ref_t loc = _self->loc; /* local-var<global,string> */
  kk_std_core__list xs = _self->xs; /* list<double> */
  kk_drop_match(_self, {kk_ref_dup(loc);kk_std_core__list_dup(xs);}, {}, _ctx)
  kk_string_t str;
  kk_std_core_types__maybe _match_5456 = kk_std_core__lp__lb__rb__2_rp_(xs, i, _ctx); /*maybe<1>*/;
  if (kk_std_core_types__is_Nothing(_match_5456)) {
    str = kk_string_empty(); /*string*/
  }
  else {
    kk_box_t _box_x5156 = _match_5456._cons.Just.value;
    double x = kk_double_unbox(_box_x5156, NULL);
    kk_std_core_types__maybe_drop(_match_5456, _ctx);
    kk_string_t _x5495;
    kk_std_core_types__optional _x5496 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(1)), _ctx); /*optional<35>*/
    _x5495 = kk_std_core_show_fixed(x, _x5496, _ctx); /*string*/
    kk_string_t _x5497;
    kk_define_string_literal(, _s5498, 1, ",")
    _x5497 = kk_string_dup(_s5498); /*string*/
    str = kk_std_core__lp__plus__plus__1_rp_(_x5495, _x5497, _ctx); /*string*/
  }
  kk_string_t _b_5163_5161;
  kk_string_t _x5499;
  kk_box_t _x5500;
  kk_ref_t _x5501 = kk_ref_dup(loc); /*local-var<global,string>*/
  _x5500 = (kk_ref_get(_x5501,kk_context())); /*0*/
  _x5499 = kk_string_unbox(_x5500); /*string*/
  _b_5163_5161 = kk_std_core__lp__plus__plus__1_rp_(_x5499, str, _ctx); /*string*/
  return (kk_ref_set(loc,(kk_string_box(_b_5163_5161)),kk_context()));
}

kk_string_t kk_output_dash_and_dash_plot_list__to__csv(kk_std_core__list xs, kk_context_t* _ctx) { /* (xs : list<double>) -> string */ 
  kk_ref_t loc;
  kk_box_t _x5486;
  kk_string_t _x5487 = kk_string_empty(); /*string*/
  _x5486 = kk_string_box(_x5487); /*0*/
  loc = kk_ref_alloc(_x5486,kk_context()); /*local-var<global,string>*/
  kk_string_t res;
  kk_unit_t __ = kk_Unit;
  kk_integer_t end_5070;
  kk_integer_t _x5489;
  kk_std_core__list _x5490 = kk_std_core__list_dup(xs); /*list<double>*/
  _x5489 = kk_std_core_length_1(_x5490, _ctx); /*int*/
  end_5070 = kk_integer_sub(_x5489,(kk_integer_from_small(2)),kk_context()); /*int*/
  kk_function_t _x5491;
  kk_ref_dup(loc);
  kk_std_core__list_dup(xs);
  _x5491 = kk_output_dash_and_dash_plot_new_list__to__csv_fun5492(loc, xs, _ctx); /*(i : int) -> (local<global>) ()*/
  kk_std_core__lift21056_for(_x5491, end_5070, kk_integer_from_small(0), _ctx);
  kk_string_t str0;
  kk_std_core_types__maybe _match_5455;
  kk_std_core__list _x5502 = kk_std_core__list_dup(xs); /*list<double>*/
  kk_integer_t _x5503;
  kk_integer_t _x5504 = kk_std_core_length_1(xs, _ctx); /*int*/
  _x5503 = kk_integer_sub(_x5504,(kk_integer_from_small(1)),kk_context()); /*int*/
  _match_5455 = kk_std_core__lp__lb__rb__2_rp_(_x5502, _x5503, _ctx); /*maybe<1>*/
  if (kk_std_core_types__is_Nothing(_match_5455)) {
    str0 = kk_string_empty(); /*string*/
  }
  else {
    kk_box_t _box_x5165 = _match_5455._cons.Just.value;
    double x0 = kk_double_unbox(_box_x5165, NULL);
    kk_std_core_types__maybe_drop(_match_5455, _ctx);
    kk_std_core_types__optional _x5507 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(1)), _ctx); /*optional<35>*/
    str0 = kk_std_core_show_fixed(x0, _x5507, _ctx); /*string*/
  }
  kk_unit_t __0 = kk_Unit;
  kk_string_t _b_5172_5170;
  kk_string_t _x5508;
  kk_box_t _x5509;
  kk_ref_t _x5510 = kk_ref_dup(loc); /*local-var<global,string>*/
  _x5509 = (kk_ref_get(_x5510,kk_context())); /*0*/
  _x5508 = kk_string_unbox(_x5509); /*string*/
  kk_string_t _x5511;
  kk_string_t _x5512;
  kk_define_string_literal(, _s5513, 1, "\n")
  _x5512 = kk_string_dup(_s5513); /*string*/
  _x5511 = kk_std_core__lp__plus__plus__1_rp_(str0, _x5512, _ctx); /*string*/
  _b_5172_5170 = kk_std_core__lp__plus__plus__1_rp_(_x5508, _x5511, _ctx); /*string*/
  kk_ref_t _x5514 = kk_ref_dup(loc); /*local-var<global,string>*/
  (kk_ref_set(_x5514,(kk_string_box(_b_5172_5170)),kk_context()));
  kk_box_t _x5515;
  kk_ref_t _x5516 = kk_ref_dup(loc); /*local-var<global,string>*/
  _x5515 = (kk_ref_get(_x5516,kk_context())); /*0*/
  res = kk_string_unbox(_x5515); /*string*/
  kk_box_t _x5517 = kk_std_core_hnd_prompt_local_var(loc, kk_string_box(res), _ctx); /*2*/
  return kk_string_unbox(_x5517);
}

kk_string_t kk_output_dash_and_dash_plot_show__head(kk_std_core__list tmcmc__result, kk_context_t* _ctx) { /* (tmcmc_result : list<(list<double>, double)>) -> string */ 
  kk_std_core_types__maybe _match_5454 = kk_std_core_last(tmcmc__result, _ctx); /*maybe<1>*/;
  if (kk_std_core_types__is_Nothing(_match_5454)) {
    return kk_string_empty();
  }
  kk_box_t _box_x5180 = _match_5454._cons.Just.value;
  kk_std_core_types__tuple2_ _pat1 = kk_std_core_types__tuple2__unbox(_box_x5180, NULL);
  kk_box_t _box_x5181 = _pat1.fst;
  kk_box_t _box_x5182 = _pat1.snd;
  double a = kk_double_unbox(_box_x5182, NULL);
  kk_std_core_types__maybe_drop(_match_5454, _ctx);
  kk_std_core_types__optional _x5522 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(1)), _ctx); /*optional<35>*/
  return kk_std_core_show_fixed(a, _x5522, _ctx);
}
 
// These both ignore the trace of the results.


// lift anonymous function
struct kk_output_dash_and_dash_plot_show__trace__single_fun5529__t {
  struct kk_function_s _base;
  kk_ref_t loc;
  kk_std_core__list tmcmc__result;
};
static kk_unit_t kk_output_dash_and_dash_plot_show__trace__single_fun5529(kk_function_t _fself, kk_integer_t i, kk_context_t* _ctx);
static kk_function_t kk_output_dash_and_dash_plot_new_show__trace__single_fun5529(kk_ref_t loc, kk_std_core__list tmcmc__result, kk_context_t* _ctx) {
  struct kk_output_dash_and_dash_plot_show__trace__single_fun5529__t* _self = kk_function_alloc_as(struct kk_output_dash_and_dash_plot_show__trace__single_fun5529__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_output_dash_and_dash_plot_show__trace__single_fun5529, kk_context());
  _self->loc = loc;
  _self->tmcmc__result = tmcmc__result;
  return &_self->_base;
}

static kk_unit_t kk_output_dash_and_dash_plot_show__trace__single_fun5529(kk_function_t _fself, kk_integer_t i, kk_context_t* _ctx) {
  struct kk_output_dash_and_dash_plot_show__trace__single_fun5529__t* _self = kk_function_as(struct kk_output_dash_and_dash_plot_show__trace__single_fun5529__t*, _fself);
  kk_ref_t loc = _self->loc; /* local-var<global,string> */
  kk_std_core__list tmcmc__result = _self->tmcmc__result; /* list<(list<double>, double)> */
  kk_drop_match(_self, {kk_ref_dup(loc);kk_std_core__list_dup(tmcmc__result);}, {}, _ctx)
  kk_string_t str;
  kk_std_core_types__maybe _match_5453 = kk_std_core__lp__lb__rb__2_rp_(tmcmc__result, i, _ctx); /*maybe<1>*/;
  if (kk_std_core_types__is_Nothing(_match_5453)) {
    str = kk_string_empty(); /*string*/
  }
  else {
    kk_box_t _box_x5187 = _match_5453._cons.Just.value;
    kk_std_core_types__tuple2_ _pat1 = kk_std_core_types__tuple2__unbox(_box_x5187, NULL);
    kk_box_t _box_x5188 = _pat1.fst;
    kk_box_t _box_x5189 = _pat1.snd;
    double a = kk_double_unbox(_box_x5189, NULL);
    kk_std_core_types__maybe_drop(_match_5453, _ctx);
    kk_std_core_types__optional _x5534 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(1)), _ctx); /*optional<35>*/
    str = kk_std_core_show_fixed(a, _x5534, _ctx); /*string*/
  }
  kk_string_t _b_5196_5194;
  kk_string_t _x5535;
  kk_box_t _x5536;
  kk_ref_t _x5537 = kk_ref_dup(loc); /*local-var<global,string>*/
  _x5536 = (kk_ref_get(_x5537,kk_context())); /*0*/
  _x5535 = kk_string_unbox(_x5536); /*string*/
  kk_string_t _x5538;
  kk_string_t _x5539;
  kk_define_string_literal(, _s5540, 1, "\n")
  _x5539 = kk_string_dup(_s5540); /*string*/
  _x5538 = kk_std_core__lp__plus__plus__1_rp_(str, _x5539, _ctx); /*string*/
  _b_5196_5194 = kk_std_core__lp__plus__plus__1_rp_(_x5535, _x5538, _ctx); /*string*/
  return (kk_ref_set(loc,(kk_string_box(_b_5196_5194)),kk_context()));
}

kk_string_t kk_output_dash_and_dash_plot_show__trace__single(kk_std_core__list tmcmc__result, kk_context_t* _ctx) { /* (tmcmc_result : list<(list<double>, double)>) -> string */ 
  kk_ref_t loc;
  kk_box_t _x5523;
  kk_string_t _x5524 = kk_string_empty(); /*string*/
  _x5523 = kk_string_box(_x5524); /*0*/
  loc = kk_ref_alloc(_x5523,kk_context()); /*local-var<global,string>*/
  kk_string_t res;
  kk_unit_t __ = kk_Unit;
  kk_integer_t end_5077;
  kk_integer_t _x5526;
  kk_std_core__list _x5527 = kk_std_core__list_dup(tmcmc__result); /*list<(list<double>, double)>*/
  _x5526 = kk_std_core_length_1(_x5527, _ctx); /*int*/
  end_5077 = kk_integer_sub(_x5526,(kk_integer_from_small(1)),kk_context()); /*int*/
  kk_function_t _x5528;
  kk_ref_dup(loc);
  _x5528 = kk_output_dash_and_dash_plot_new_show__trace__single_fun5529(loc, tmcmc__result, _ctx); /*(i : int) -> (local<global>) ()*/
  kk_std_core__lift21056_for(_x5528, end_5077, kk_integer_from_small(0), _ctx);
  kk_box_t _x5541;
  kk_ref_t _x5542 = kk_ref_dup(loc); /*local-var<global,string>*/
  _x5541 = (kk_ref_get(_x5542,kk_context())); /*0*/
  res = kk_string_unbox(_x5541); /*string*/
  kk_box_t _x5543 = kk_std_core_hnd_prompt_local_var(loc, kk_string_box(res), _ctx); /*2*/
  return kk_string_unbox(_x5543);
}


// lift anonymous function
struct kk_output_dash_and_dash_plot_show_fun5550__t {
  struct kk_function_s _base;
  kk_std_core__list hist;
  kk_ref_t loc;
};
static kk_unit_t kk_output_dash_and_dash_plot_show_fun5550(kk_function_t _fself, kk_integer_t i, kk_context_t* _ctx);
static kk_function_t kk_output_dash_and_dash_plot_new_show_fun5550(kk_std_core__list hist, kk_ref_t loc, kk_context_t* _ctx) {
  struct kk_output_dash_and_dash_plot_show_fun5550__t* _self = kk_function_alloc_as(struct kk_output_dash_and_dash_plot_show_fun5550__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_output_dash_and_dash_plot_show_fun5550, kk_context());
  _self->hist = hist;
  _self->loc = loc;
  return &_self->_base;
}

static kk_unit_t kk_output_dash_and_dash_plot_show_fun5550(kk_function_t _fself, kk_integer_t i, kk_context_t* _ctx) {
  struct kk_output_dash_and_dash_plot_show_fun5550__t* _self = kk_function_as(struct kk_output_dash_and_dash_plot_show_fun5550__t*, _fself);
  kk_std_core__list hist = _self->hist; /* effects-and-types/histogram<double> */
  kk_ref_t loc = _self->loc; /* local-var<global,string> */
  kk_drop_match(_self, {kk_std_core__list_dup(hist);kk_ref_dup(loc);}, {}, _ctx)
  kk_string_t str;
  kk_std_core_types__maybe _match_5452 = kk_std_core__lp__lb__rb__2_rp_(hist, i, _ctx); /*maybe<1>*/;
  if (kk_std_core_types__is_Nothing(_match_5452)) {
    str = kk_string_empty(); /*string*/
  }
  else {
    kk_box_t _box_x5206 = _match_5452._cons.Just.value;
    kk_std_core_types__tuple2_ x = kk_std_core_types__tuple2__unbox(_box_x5206, NULL);
    kk_std_core_types__tuple2__dup(x);
    kk_std_core_types__maybe_drop(_match_5452, _ctx);
    kk_box_t _box_x5207 = x.fst;
    kk_box_t _box_x5208 = x.snd;
    kk_effects_dash_and_dash_types__exp _pat2 = kk_effects_dash_and_dash_types__exp_unbox(_box_x5207, NULL);
    double a = kk_double_unbox(_box_x5208, NULL);
    double dbl = _pat2.i;
    kk_std_core_types__tuple2__drop(x, _ctx);
    kk_string_t _x5555;
    kk_std_num_ddouble__ddouble _x5556;
    kk_std_num_ddouble__ddouble _x5557 = kk_std_num_ddouble_ddouble(dbl, _ctx); /*std/num/ddouble/ddouble*/
    _x5556 = kk_std_num_ddouble_exp(_x5557, _ctx); /*std/num/ddouble/ddouble*/
    kk_std_core_types__optional _x5558 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(1)), _ctx); /*optional<35>*/
    _x5555 = kk_std_num_ddouble_show_fixed(_x5556, _x5558, _ctx); /*string*/
    kk_string_t _x5559;
    kk_string_t _x5560;
    kk_define_string_literal(, _s5561, 2, ", ")
    _x5560 = kk_string_dup(_s5561); /*string*/
    kk_string_t _x5562;
    kk_std_core_types__optional _x5563 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(1)), _ctx); /*optional<35>*/
    _x5562 = kk_std_core_show_fixed(a, _x5563, _ctx); /*string*/
    _x5559 = kk_std_core__lp__plus__plus__1_rp_(_x5560, _x5562, _ctx); /*string*/
    str = kk_std_core__lp__plus__plus__1_rp_(_x5555, _x5559, _ctx); /*string*/
  }
  kk_string_t _b_5217_5215;
  kk_string_t _x5564;
  kk_box_t _x5565;
  kk_ref_t _x5566 = kk_ref_dup(loc); /*local-var<global,string>*/
  _x5565 = (kk_ref_get(_x5566,kk_context())); /*0*/
  _x5564 = kk_string_unbox(_x5565); /*string*/
  kk_string_t _x5567;
  kk_string_t _x5568;
  kk_define_string_literal(, _s5569, 1, "\n")
  _x5568 = kk_string_dup(_s5569); /*string*/
  _x5567 = kk_std_core__lp__plus__plus__1_rp_(str, _x5568, _ctx); /*string*/
  _b_5217_5215 = kk_std_core__lp__plus__plus__1_rp_(_x5564, _x5567, _ctx); /*string*/
  return (kk_ref_set(loc,(kk_string_box(_b_5217_5215)),kk_context()));
}

kk_string_t kk_output_dash_and_dash_plot_show(kk_std_core__list hist, kk_context_t* _ctx) { /* (hist : effects-and-types/histogram<double>) -> string */ 
  kk_ref_t loc;
  kk_box_t _x5544;
  kk_string_t _x5545 = kk_string_empty(); /*string*/
  _x5544 = kk_string_box(_x5545); /*0*/
  loc = kk_ref_alloc(_x5544,kk_context()); /*local-var<global,string>*/
  kk_string_t res;
  kk_unit_t __ = kk_Unit;
  kk_integer_t end_5084;
  kk_integer_t _x5547;
  kk_std_core__list _x5548 = kk_std_core__list_dup(hist); /*effects-and-types/histogram<double>*/
  _x5547 = kk_std_core_length_1(_x5548, _ctx); /*int*/
  end_5084 = kk_integer_sub(_x5547,(kk_integer_from_small(1)),kk_context()); /*int*/
  kk_function_t _x5549;
  kk_ref_dup(loc);
  _x5549 = kk_output_dash_and_dash_plot_new_show_fun5550(hist, loc, _ctx); /*(i : int) -> (local<global>) ()*/
  kk_std_core__lift21056_for(_x5549, end_5084, kk_integer_from_small(0), _ctx);
  kk_box_t _x5570;
  kk_ref_t _x5571 = kk_ref_dup(loc); /*local-var<global,string>*/
  _x5570 = (kk_ref_get(_x5571,kk_context())); /*0*/
  res = kk_string_unbox(_x5570); /*string*/
  kk_box_t _x5572 = kk_std_core_hnd_prompt_local_var(loc, kk_string_box(res), _ctx); /*2*/
  return kk_string_unbox(_x5572);
}


// lift anonymous function
struct kk_output_dash_and_dash_plot_show_fun5579__t_1 {
  struct kk_function_s _base;
  kk_std_core__list hist;
  kk_ref_t loc;
};
static kk_unit_t kk_output_dash_and_dash_plot_show_fun5579_1(kk_function_t _fself, kk_integer_t i, kk_context_t* _ctx);
static kk_function_t kk_output_dash_and_dash_plot_new_show_fun5579_1(kk_std_core__list hist, kk_ref_t loc, kk_context_t* _ctx) {
  struct kk_output_dash_and_dash_plot_show_fun5579__t_1* _self = kk_function_alloc_as(struct kk_output_dash_and_dash_plot_show_fun5579__t_1, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_output_dash_and_dash_plot_show_fun5579_1, kk_context());
  _self->hist = hist;
  _self->loc = loc;
  return &_self->_base;
}

static kk_unit_t kk_output_dash_and_dash_plot_show_fun5579_1(kk_function_t _fself, kk_integer_t i, kk_context_t* _ctx) {
  struct kk_output_dash_and_dash_plot_show_fun5579__t_1* _self = kk_function_as(struct kk_output_dash_and_dash_plot_show_fun5579__t_1*, _fself);
  kk_std_core__list hist = _self->hist; /* effects-and-types/histogram<(double, double)> */
  kk_ref_t loc = _self->loc; /* local-var<global,string> */
  kk_drop_match(_self, {kk_std_core__list_dup(hist);kk_ref_dup(loc);}, {}, _ctx)
  kk_string_t str;
  kk_std_core_types__maybe _match_5451 = kk_std_core__lp__lb__rb__2_rp_(hist, i, _ctx); /*maybe<1>*/;
  if (kk_std_core_types__is_Nothing(_match_5451)) {
    str = kk_string_empty(); /*string*/
  }
  else {
    kk_box_t _box_x5227 = _match_5451._cons.Just.value;
    kk_std_core_types__tuple2_ x = kk_std_core_types__tuple2__unbox(_box_x5227, NULL);
    kk_std_core_types__tuple2__dup(x);
    kk_std_core_types__maybe_drop(_match_5451, _ctx);
    kk_box_t _box_x5228 = x.fst;
    kk_box_t _box_x5229 = x.snd;
    kk_effects_dash_and_dash_types__exp _pat2 = kk_effects_dash_and_dash_types__exp_unbox(_box_x5228, NULL);
    kk_std_core_types__tuple2_ _pat3 = kk_std_core_types__tuple2__unbox(_box_x5229, NULL);
    double dbl = _pat2.i;
    kk_box_t _box_x5230 = _pat3.fst;
    kk_box_t _box_x5231 = _pat3.snd;
    double db1 = kk_double_unbox(_box_x5230, NULL);
    double db2 = kk_double_unbox(_box_x5231, NULL);
    kk_std_core_types__tuple2__drop(x, _ctx);
    kk_string_t _x5586;
    kk_std_num_ddouble__ddouble _x5587;
    kk_std_num_ddouble__ddouble _x5588 = kk_std_num_ddouble_ddouble(dbl, _ctx); /*std/num/ddouble/ddouble*/
    _x5587 = kk_std_num_ddouble_exp(_x5588, _ctx); /*std/num/ddouble/ddouble*/
    kk_std_core_types__optional _x5589 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(1)), _ctx); /*optional<35>*/
    _x5586 = kk_std_num_ddouble_show_fixed(_x5587, _x5589, _ctx); /*string*/
    kk_string_t _x5590;
    kk_string_t _x5591;
    kk_define_string_literal(, _s5592, 2, ", ")
    _x5591 = kk_string_dup(_s5592); /*string*/
    kk_string_t _x5593;
    kk_string_t _x5594;
    kk_std_core_types__optional _x5595 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(1)), _ctx); /*optional<35>*/
    _x5594 = kk_std_core_show_fixed(db1, _x5595, _ctx); /*string*/
    kk_string_t _x5596;
    kk_string_t _x5597;
    kk_define_string_literal(, _s5598, 2, ", ")
    _x5597 = kk_string_dup(_s5598); /*string*/
    kk_string_t _x5599;
    kk_std_core_types__optional _x5600 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(1)), _ctx); /*optional<35>*/
    _x5599 = kk_std_core_show_fixed(db2, _x5600, _ctx); /*string*/
    _x5596 = kk_std_core__lp__plus__plus__1_rp_(_x5597, _x5599, _ctx); /*string*/
    _x5593 = kk_std_core__lp__plus__plus__1_rp_(_x5594, _x5596, _ctx); /*string*/
    _x5590 = kk_std_core__lp__plus__plus__1_rp_(_x5591, _x5593, _ctx); /*string*/
    str = kk_std_core__lp__plus__plus__1_rp_(_x5586, _x5590, _ctx); /*string*/
  }
  kk_string_t _b_5242_5240;
  kk_string_t _x5601;
  kk_box_t _x5602;
  kk_ref_t _x5603 = kk_ref_dup(loc); /*local-var<global,string>*/
  _x5602 = (kk_ref_get(_x5603,kk_context())); /*0*/
  _x5601 = kk_string_unbox(_x5602); /*string*/
  kk_string_t _x5604;
  kk_string_t _x5605;
  kk_define_string_literal(, _s5606, 1, "\n")
  _x5605 = kk_string_dup(_s5606); /*string*/
  _x5604 = kk_std_core__lp__plus__plus__1_rp_(str, _x5605, _ctx); /*string*/
  _b_5242_5240 = kk_std_core__lp__plus__plus__1_rp_(_x5601, _x5604, _ctx); /*string*/
  return (kk_ref_set(loc,(kk_string_box(_b_5242_5240)),kk_context()));
}

kk_string_t kk_output_dash_and_dash_plot_show_1(kk_std_core__list hist, kk_context_t* _ctx) { /* (hist : effects-and-types/histogram<(double, double)>) -> string */ 
  kk_ref_t loc;
  kk_box_t _x5573;
  kk_string_t _x5574 = kk_string_empty(); /*string*/
  _x5573 = kk_string_box(_x5574); /*0*/
  loc = kk_ref_alloc(_x5573,kk_context()); /*local-var<global,string>*/
  kk_string_t res;
  kk_unit_t __ = kk_Unit;
  kk_integer_t end_5091;
  kk_integer_t _x5576;
  kk_std_core__list _x5577 = kk_std_core__list_dup(hist); /*effects-and-types/histogram<(double, double)>*/
  _x5576 = kk_std_core_length_1(_x5577, _ctx); /*int*/
  end_5091 = kk_integer_sub(_x5576,(kk_integer_from_small(1)),kk_context()); /*int*/
  kk_function_t _x5578;
  kk_ref_dup(loc);
  _x5578 = kk_output_dash_and_dash_plot_new_show_fun5579_1(hist, loc, _ctx); /*(i : int) -> (local<global>) ()*/
  kk_std_core__lift21056_for(_x5578, end_5091, kk_integer_from_small(0), _ctx);
  kk_box_t _x5607;
  kk_ref_t _x5608 = kk_ref_dup(loc); /*local-var<global,string>*/
  _x5607 = (kk_ref_get(_x5608,kk_context())); /*0*/
  res = kk_string_unbox(_x5607); /*string*/
  kk_box_t _x5609 = kk_std_core_hnd_prompt_local_var(loc, kk_string_box(res), _ctx); /*2*/
  return kk_string_unbox(_x5609);
}


// lift anonymous function
struct kk_output_dash_and_dash_plot_show_fun5616__t_2 {
  struct kk_function_s _base;
  kk_std_core__list hist;
  kk_ref_t loc;
};
static kk_unit_t kk_output_dash_and_dash_plot_show_fun5616_2(kk_function_t _fself, kk_integer_t i, kk_context_t* _ctx);
static kk_function_t kk_output_dash_and_dash_plot_new_show_fun5616_2(kk_std_core__list hist, kk_ref_t loc, kk_context_t* _ctx) {
  struct kk_output_dash_and_dash_plot_show_fun5616__t_2* _self = kk_function_alloc_as(struct kk_output_dash_and_dash_plot_show_fun5616__t_2, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_output_dash_and_dash_plot_show_fun5616_2, kk_context());
  _self->hist = hist;
  _self->loc = loc;
  return &_self->_base;
}



// lift anonymous function
struct kk_output_dash_and_dash_plot_show_fun5629__t_2 {
  struct kk_function_s _base;
  kk_ref_t loc;
  kk_std_core__list lst;
};
static kk_unit_t kk_output_dash_and_dash_plot_show_fun5629_2(kk_function_t _fself, kk_integer_t j, kk_context_t* _ctx);
static kk_function_t kk_output_dash_and_dash_plot_new_show_fun5629_2(kk_ref_t loc, kk_std_core__list lst, kk_context_t* _ctx) {
  struct kk_output_dash_and_dash_plot_show_fun5629__t_2* _self = kk_function_alloc_as(struct kk_output_dash_and_dash_plot_show_fun5629__t_2, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_output_dash_and_dash_plot_show_fun5629_2, kk_context());
  _self->loc = loc;
  _self->lst = lst;
  return &_self->_base;
}

static kk_unit_t kk_output_dash_and_dash_plot_show_fun5629_2(kk_function_t _fself, kk_integer_t j, kk_context_t* _ctx) {
  struct kk_output_dash_and_dash_plot_show_fun5629__t_2* _self = kk_function_as(struct kk_output_dash_and_dash_plot_show_fun5629__t_2*, _fself);
  kk_ref_t loc = _self->loc; /* local-var<global,string> */
  kk_std_core__list lst = _self->lst; /* list<double> */
  kk_drop_match(_self, {kk_ref_dup(loc);kk_std_core__list_dup(lst);}, {}, _ctx)
  kk_string_t str;
  kk_std_core_types__maybe _match_5450 = kk_std_core__lp__lb__rb__2_rp_(lst, j, _ctx); /*maybe<1>*/;
  if (kk_std_core_types__is_Nothing(_match_5450)) {
    str = kk_string_empty(); /*string*/
  }
  else {
    kk_box_t _box_x5258 = _match_5450._cons.Just.value;
    double u = kk_double_unbox(_box_x5258, NULL);
    kk_std_core_types__maybe_drop(_match_5450, _ctx);
    kk_string_t _x5632;
    kk_std_core_types__optional _x5633 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(1)), _ctx); /*optional<35>*/
    _x5632 = kk_std_core_show_fixed(u, _x5633, _ctx); /*string*/
    kk_string_t _x5634;
    kk_define_string_literal(, _s5635, 1, ",")
    _x5634 = kk_string_dup(_s5635); /*string*/
    str = kk_std_core__lp__plus__plus__1_rp_(_x5632, _x5634, _ctx); /*string*/
  }
  kk_string_t _b_5265_5263;
  kk_string_t _x5636;
  kk_box_t _x5637;
  kk_ref_t _x5638 = kk_ref_dup(loc); /*local-var<global,string>*/
  _x5637 = (kk_ref_get(_x5638,kk_context())); /*0*/
  _x5636 = kk_string_unbox(_x5637); /*string*/
  _b_5265_5263 = kk_std_core__lp__plus__plus__1_rp_(_x5636, str, _ctx); /*string*/
  return (kk_ref_set(loc,(kk_string_box(_b_5265_5263)),kk_context()));
}
static kk_unit_t kk_output_dash_and_dash_plot_show_fun5616_2(kk_function_t _fself, kk_integer_t i, kk_context_t* _ctx) {
  struct kk_output_dash_and_dash_plot_show_fun5616__t_2* _self = kk_function_as(struct kk_output_dash_and_dash_plot_show_fun5616__t_2*, _fself);
  kk_std_core__list hist = _self->hist; /* effects-and-types/histogram<list<double>> */
  kk_ref_t loc = _self->loc; /* local-var<global,string> */
  kk_drop_match(_self, {kk_std_core__list_dup(hist);kk_ref_dup(loc);}, {}, _ctx)
  kk_unit_t __0 = kk_Unit;
  kk_std_core_types__maybe _match_5448 = kk_std_core__lp__lb__rb__2_rp_(hist, i, _ctx); /*maybe<1>*/;
  if (kk_std_core_types__is_Nothing(_match_5448)) {
    kk_string_t _b_5274_5254;
    kk_string_t _x5617;
    kk_box_t _x5618;
    kk_ref_t _x5619 = kk_ref_dup(loc); /*local-var<global,string>*/
    _x5618 = (kk_ref_get(_x5619,kk_context())); /*0*/
    _x5617 = kk_string_unbox(_x5618); /*string*/
    kk_string_t _x5620 = kk_string_empty(); /*string*/
    _b_5274_5254 = kk_std_core__lp__plus__plus__1_rp_(_x5617, _x5620, _ctx); /*string*/
    kk_ref_t _x5622 = kk_ref_dup(loc); /*local-var<global,string>*/
    (kk_ref_set(_x5622,(kk_string_box(_b_5274_5254)),kk_context()));
  }
  else {
    kk_box_t _box_x5255 = _match_5448._cons.Just.value;
    kk_std_core_types__tuple2_ x = kk_std_core_types__tuple2__unbox(_box_x5255, NULL);
    kk_std_core_types__tuple2__dup(x);
    kk_std_core_types__maybe_drop(_match_5448, _ctx);
    kk_box_t _box_x5256 = x.fst;
    kk_box_t _box_x5257 = x.snd;
    kk_effects_dash_and_dash_types__exp _pat2 = kk_effects_dash_and_dash_types__exp_unbox(_box_x5256, NULL);
    kk_std_core__list lst = kk_std_core__list_unbox(_box_x5257, NULL);
    kk_std_core__list_dup(lst);
    kk_std_core_types__tuple2__drop(x, _ctx);
    kk_unit_t __ = kk_Unit;
    kk_integer_t end0_5101;
    kk_integer_t _x5626;
    kk_std_core__list _x5627 = kk_std_core__list_dup(lst); /*list<double>*/
    _x5626 = kk_std_core_length_1(_x5627, _ctx); /*int*/
    end0_5101 = kk_integer_sub(_x5626,(kk_integer_from_small(2)),kk_context()); /*int*/
    kk_function_t _x5628;
    kk_ref_dup(loc);
    kk_std_core__list_dup(lst);
    _x5628 = kk_output_dash_and_dash_plot_new_show_fun5629_2(loc, lst, _ctx); /*(j : int) -> (local<global>) ()*/
    kk_std_core__lift21056_for(_x5628, end0_5101, kk_integer_from_small(0), _ctx);
    kk_string_t str0;
    kk_std_core_types__maybe _match_5449;
    kk_std_core__list _x5639 = kk_std_core__list_dup(lst); /*list<double>*/
    kk_integer_t _x5640;
    kk_integer_t _x5641 = kk_std_core_length_1(lst, _ctx); /*int*/
    _x5640 = kk_integer_sub(_x5641,(kk_integer_from_small(1)),kk_context()); /*int*/
    _match_5449 = kk_std_core__lp__lb__rb__2_rp_(_x5639, _x5640, _ctx); /*maybe<1>*/
    if (kk_std_core_types__is_Nothing(_match_5449)) {
      str0 = kk_string_empty(); /*string*/
    }
    else {
      kk_box_t _box_x5267 = _match_5449._cons.Just.value;
      double u0 = kk_double_unbox(_box_x5267, NULL);
      kk_std_core_types__maybe_drop(_match_5449, _ctx);
      kk_std_core_types__optional _x5644 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(1)), _ctx); /*optional<35>*/
      str0 = kk_std_core_show_fixed(u0, _x5644, _ctx); /*string*/
    }
    kk_string_t _b_5277_5272;
    kk_string_t _x5645;
    kk_box_t _x5646;
    kk_ref_t _x5647 = kk_ref_dup(loc); /*local-var<global,string>*/
    _x5646 = (kk_ref_get(_x5647,kk_context())); /*0*/
    _x5645 = kk_string_unbox(_x5646); /*string*/
    _b_5277_5272 = kk_std_core__lp__plus__plus__1_rp_(_x5645, str0, _ctx); /*string*/
    kk_ref_t _x5648 = kk_ref_dup(loc); /*local-var<global,string>*/
    (kk_ref_set(_x5648,(kk_string_box(_b_5277_5272)),kk_context()));
  }
  kk_string_t _b_5283_5281;
  kk_string_t _x5649;
  kk_box_t _x5650;
  kk_ref_t _x5651 = kk_ref_dup(loc); /*local-var<global,string>*/
  _x5650 = (kk_ref_get(_x5651,kk_context())); /*0*/
  _x5649 = kk_string_unbox(_x5650); /*string*/
  kk_string_t _x5652;
  kk_define_string_literal(, _s5653, 1, "\n")
  _x5652 = kk_string_dup(_s5653); /*string*/
  _b_5283_5281 = kk_std_core__lp__plus__plus__1_rp_(_x5649, _x5652, _ctx); /*string*/
  return (kk_ref_set(loc,(kk_string_box(_b_5283_5281)),kk_context()));
}

kk_string_t kk_output_dash_and_dash_plot_show_2(kk_std_core__list hist, kk_context_t* _ctx) { /* (hist : effects-and-types/histogram<list<double>>) -> string */ 
  kk_ref_t loc;
  kk_box_t _x5610;
  kk_string_t _x5611 = kk_string_empty(); /*string*/
  _x5610 = kk_string_box(_x5611); /*0*/
  loc = kk_ref_alloc(_x5610,kk_context()); /*local-var<global,string>*/
  kk_string_t res;
  kk_unit_t __1 = kk_Unit;
  kk_integer_t end_5098;
  kk_integer_t _x5613;
  kk_std_core__list _x5614 = kk_std_core__list_dup(hist); /*effects-and-types/histogram<list<double>>*/
  _x5613 = kk_std_core_length_1(_x5614, _ctx); /*int*/
  end_5098 = kk_integer_sub(_x5613,(kk_integer_from_small(1)),kk_context()); /*int*/
  kk_function_t _x5615;
  kk_ref_dup(loc);
  _x5615 = kk_output_dash_and_dash_plot_new_show_fun5616_2(hist, loc, _ctx); /*(i : int) -> (local<global>) ()*/
  kk_std_core__lift21056_for(_x5615, end_5098, kk_integer_from_small(0), _ctx);
  kk_box_t _x5654;
  kk_ref_t _x5655 = kk_ref_dup(loc); /*local-var<global,string>*/
  _x5654 = (kk_ref_get(_x5655,kk_context())); /*0*/
  res = kk_string_unbox(_x5654); /*string*/
  kk_box_t _x5656 = kk_std_core_hnd_prompt_local_var(loc, kk_string_box(res), _ctx); /*2*/
  return kk_string_unbox(_x5656);
}

kk_string_t kk_output_dash_and_dash_plot_show_3(kk_std_core_types__tuple2_ ls, kk_context_t* _ctx) { /* (ls : (list<int>, list<int>)) -> string */ 
  kk_box_t _box_x5291 = ls.fst;
  kk_box_t _box_x5292 = ls.snd;
  kk_std_core__list l1 = kk_std_core__list_unbox(_box_x5291, NULL);
  kk_std_core__list l2 = kk_std_core__list_unbox(_box_x5292, NULL);
  kk_std_core__list_dup(l1);
  kk_std_core__list_dup(l2);
  kk_std_core_types__tuple2__drop(ls, _ctx);
  kk_string_t _x5659 = kk_std_core_show_8(l1, _ctx); /*string*/
  kk_string_t _x5660 = kk_std_core_show_8(l2, _ctx); /*string*/
  return kk_std_core__lp__plus__plus__1_rp_(_x5659, _x5660, _ctx);
}


// lift anonymous function
struct kk_output_dash_and_dash_plot_show_fun5667__t_4 {
  struct kk_function_s _base;
  kk_ref_t loc;
  kk_std_core__list xs;
};
static kk_unit_t kk_output_dash_and_dash_plot_show_fun5667_4(kk_function_t _fself, kk_integer_t i, kk_context_t* _ctx);
static kk_function_t kk_output_dash_and_dash_plot_new_show_fun5667_4(kk_ref_t loc, kk_std_core__list xs, kk_context_t* _ctx) {
  struct kk_output_dash_and_dash_plot_show_fun5667__t_4* _self = kk_function_alloc_as(struct kk_output_dash_and_dash_plot_show_fun5667__t_4, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_output_dash_and_dash_plot_show_fun5667_4, kk_context());
  _self->loc = loc;
  _self->xs = xs;
  return &_self->_base;
}

static kk_unit_t kk_output_dash_and_dash_plot_show_fun5667_4(kk_function_t _fself, kk_integer_t i, kk_context_t* _ctx) {
  struct kk_output_dash_and_dash_plot_show_fun5667__t_4* _self = kk_function_as(struct kk_output_dash_and_dash_plot_show_fun5667__t_4*, _fself);
  kk_ref_t loc = _self->loc; /* local-var<global,string> */
  kk_std_core__list xs = _self->xs; /* list<double> */
  kk_drop_match(_self, {kk_ref_dup(loc);kk_std_core__list_dup(xs);}, {}, _ctx)
  bool _match_5445;
  kk_integer_t _x5668 = kk_integer_dup(i); /*int*/
  kk_integer_t _x5669;
  kk_integer_t _x5670;
  kk_std_core__list _x5671 = kk_std_core__list_dup(xs); /*list<double>*/
  _x5670 = kk_std_core_length_1(_x5671, _ctx); /*int*/
  _x5669 = kk_integer_sub(_x5670,(kk_integer_from_small(1)),kk_context()); /*int*/
  _match_5445 = kk_integer_lt(_x5668,_x5669,kk_context()); /*bool*/
  if (_match_5445) {
    kk_string_t str;
    kk_std_core_types__maybe _match_5447 = kk_std_core__lp__lb__rb__2_rp_(xs, i, _ctx); /*maybe<1>*/;
    if (kk_std_core_types__is_Nothing(_match_5447)) {
      str = kk_string_empty(); /*string*/
    }
    else {
      kk_box_t _box_x5295 = _match_5447._cons.Just.value;
      double x = kk_double_unbox(_box_x5295, NULL);
      kk_std_core_types__maybe_drop(_match_5447, _ctx);
      kk_string_t _x5674;
      kk_std_core_types__optional _x5675 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(1)), _ctx); /*optional<35>*/
      _x5674 = kk_std_core_show_fixed(x, _x5675, _ctx); /*string*/
      kk_string_t _x5676;
      kk_define_string_literal(, _s5677, 1, ",")
      _x5676 = kk_string_dup(_s5677); /*string*/
      str = kk_std_core__lp__plus__plus__1_rp_(_x5674, _x5676, _ctx); /*string*/
    }
    kk_string_t _b_5308_5300;
    kk_string_t _x5678;
    kk_box_t _x5679;
    kk_ref_t _x5680 = kk_ref_dup(loc); /*local-var<global,string>*/
    _x5679 = (kk_ref_get(_x5680,kk_context())); /*0*/
    _x5678 = kk_string_unbox(_x5679); /*string*/
    _b_5308_5300 = kk_std_core__lp__plus__plus__1_rp_(_x5678, str, _ctx); /*string*/
    return (kk_ref_set(loc,(kk_string_box(_b_5308_5300)),kk_context()));
  }
  kk_string_t str0;
  kk_std_core_types__maybe _match_5446 = kk_std_core__lp__lb__rb__2_rp_(xs, i, _ctx); /*maybe<1>*/;
  if (kk_std_core_types__is_Nothing(_match_5446)) {
    str0 = kk_string_empty(); /*string*/
  }
  else {
    kk_box_t _box_x5301 = _match_5446._cons.Just.value;
    double x0 = kk_double_unbox(_box_x5301, NULL);
    kk_std_core_types__maybe_drop(_match_5446, _ctx);
    kk_std_core_types__optional _x5683 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(1)), _ctx); /*optional<35>*/
    str0 = kk_std_core_show_fixed(x0, _x5683, _ctx); /*string*/
  }
  kk_string_t _b_5311_5306;
  kk_string_t _x5684;
  kk_box_t _x5685;
  kk_ref_t _x5686 = kk_ref_dup(loc); /*local-var<global,string>*/
  _x5685 = (kk_ref_get(_x5686,kk_context())); /*0*/
  _x5684 = kk_string_unbox(_x5685); /*string*/
  _b_5311_5306 = kk_std_core__lp__plus__plus__1_rp_(_x5684, str0, _ctx); /*string*/
  return (kk_ref_set(loc,(kk_string_box(_b_5311_5306)),kk_context()));
}

kk_string_t kk_output_dash_and_dash_plot_show_4(kk_std_core__list xs, kk_context_t* _ctx) { /* (xs : list<double>) -> string */ 
  kk_ref_t loc;
  kk_box_t _x5661;
  kk_string_t _x5662;
  kk_define_string_literal(, _s5663, 1, "[")
  _x5662 = kk_string_dup(_s5663); /*string*/
  _x5661 = kk_string_box(_x5662); /*0*/
  loc = kk_ref_alloc(_x5661,kk_context()); /*local-var<global,string>*/
  kk_string_t res;
  kk_unit_t __ = kk_Unit;
  kk_integer_t end_5108;
  kk_integer_t _x5664;
  kk_std_core__list _x5665 = kk_std_core__list_dup(xs); /*list<double>*/
  _x5664 = kk_std_core_length_1(_x5665, _ctx); /*int*/
  end_5108 = kk_integer_sub(_x5664,(kk_integer_from_small(1)),kk_context()); /*int*/
  kk_function_t _x5666;
  kk_ref_dup(loc);
  _x5666 = kk_output_dash_and_dash_plot_new_show_fun5667_4(loc, xs, _ctx); /*(i : int) -> (local<global>) ()*/
  kk_std_core__lift21056_for(_x5666, end_5108, kk_integer_from_small(0), _ctx);
  kk_unit_t __0 = kk_Unit;
  kk_string_t _b_5317_5315;
  kk_string_t _x5687;
  kk_box_t _x5688;
  kk_ref_t _x5689 = kk_ref_dup(loc); /*local-var<global,string>*/
  _x5688 = (kk_ref_get(_x5689,kk_context())); /*0*/
  _x5687 = kk_string_unbox(_x5688); /*string*/
  kk_string_t _x5690;
  kk_define_string_literal(, _s5691, 1, "]")
  _x5690 = kk_string_dup(_s5691); /*string*/
  _b_5317_5315 = kk_std_core__lp__plus__plus__1_rp_(_x5687, _x5690, _ctx); /*string*/
  kk_ref_t _x5692 = kk_ref_dup(loc); /*local-var<global,string>*/
  (kk_ref_set(_x5692,(kk_string_box(_b_5317_5315)),kk_context()));
  kk_box_t _x5693;
  kk_ref_t _x5694 = kk_ref_dup(loc); /*local-var<global,string>*/
  _x5693 = (kk_ref_get(_x5694,kk_context())); /*0*/
  res = kk_string_unbox(_x5693); /*string*/
  kk_box_t _x5695 = kk_std_core_hnd_prompt_local_var(loc, kk_string_box(res), _ctx); /*2*/
  return kk_string_unbox(_x5695);
}


// lift anonymous function
struct kk_output_dash_and_dash_plot_show_fun5696__t_5 {
  struct kk_function_s _base;
};
static kk_box_t kk_output_dash_and_dash_plot_show_fun5696_5(kk_function_t _fself, kk_box_t _b_5327, kk_context_t* _ctx);
static kk_function_t kk_output_dash_and_dash_plot_new_show_fun5696_5(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_output_dash_and_dash_plot_show_fun5696_5, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_output_dash_and_dash_plot_show_fun5696_5(kk_function_t _fself, kk_box_t _b_5327, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x5697;
  kk_std_core__list _x5698 = kk_std_core__list_unbox(_b_5327, _ctx); /*list<double>*/
  _x5697 = kk_output_dash_and_dash_plot_show_4(_x5698, _ctx); /*string*/
  return kk_string_box(_x5697);
}

kk_string_t kk_output_dash_and_dash_plot_show_5(kk_std_core__list x, kk_context_t* _ctx) { /* (x : list<list<double>>) -> string */ 
  kk_std_core__list xs_5110 = kk_std_core_map_5(x, kk_output_dash_and_dash_plot_new_show_fun5696_5(_ctx), _ctx); /*list<string>*/;
  if (kk_std_core__is_Nil(xs_5110)) {
    return kk_string_empty();
  }
  struct kk_std_core_Cons* _con5700 = kk_std_core__as_Cons(xs_5110);
  kk_box_t _box_x5330 = _con5700->head;
  kk_std_core__list xx = _con5700->tail;
  kk_string_t x0 = kk_string_unbox(_box_x5330);
  if (kk_std_core__list_is_unique(xs_5110)) {
    kk_std_core__list_free(xs_5110);
  }
  else {
    kk_string_dup(x0);
    kk_std_core__list_dup(xx);
    kk_std_core__list_decref(xs_5110, _ctx);
  }
  kk_string_t _x5702 = kk_string_empty(); /*string*/
  return kk_std_core__lift21050_joinsep(_x5702, xx, x0, _ctx);
}


// lift anonymous function
struct kk_output_dash_and_dash_plot_show_fun5704__t_6 {
  struct kk_function_s _base;
};
static kk_box_t kk_output_dash_and_dash_plot_show_fun5704_6(kk_function_t _fself, kk_box_t _b_5333, kk_context_t* _ctx);
static kk_function_t kk_output_dash_and_dash_plot_new_show_fun5704_6(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_output_dash_and_dash_plot_show_fun5704_6, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_output_dash_and_dash_plot_show_fun5704_6(kk_function_t _fself, kk_box_t _b_5333, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x5705;
  kk_std_core__list _x5706 = kk_std_core__list_unbox(_b_5333, _ctx); /*list<list<double>>*/
  _x5705 = kk_output_dash_and_dash_plot_show_5(_x5706, _ctx); /*string*/
  return kk_string_box(_x5705);
}

kk_string_t kk_output_dash_and_dash_plot_show_6(kk_std_core__list x, kk_context_t* _ctx) { /* (x : list<list<list<double>>>) -> string */ 
  kk_std_core__list xs_5111 = kk_std_core_map_5(x, kk_output_dash_and_dash_plot_new_show_fun5704_6(_ctx), _ctx); /*list<string>*/;
  if (kk_std_core__is_Nil(xs_5111)) {
    return kk_string_empty();
  }
  struct kk_std_core_Cons* _con5708 = kk_std_core__as_Cons(xs_5111);
  kk_box_t _box_x5336 = _con5708->head;
  kk_std_core__list xx = _con5708->tail;
  kk_string_t x0 = kk_string_unbox(_box_x5336);
  if (kk_std_core__list_is_unique(xs_5111)) {
    kk_std_core__list_free(xs_5111);
  }
  else {
    kk_string_dup(x0);
    kk_std_core__list_dup(xx);
    kk_std_core__list_decref(xs_5111, _ctx);
  }
  kk_string_t _x5710 = kk_string_empty(); /*string*/
  return kk_std_core__lift21050_joinsep(_x5710, xx, x0, _ctx);
}


// lift anonymous function
struct kk_output_dash_and_dash_plot_show_fun5714__t_7 {
  struct kk_function_s _base;
  kk_std_core__list hist;
};
static kk_unit_t kk_output_dash_and_dash_plot_show_fun5714_7(kk_function_t _fself, kk_integer_t i, kk_context_t* _ctx);
static kk_function_t kk_output_dash_and_dash_plot_new_show_fun5714_7(kk_std_core__list hist, kk_context_t* _ctx) {
  struct kk_output_dash_and_dash_plot_show_fun5714__t_7* _self = kk_function_alloc_as(struct kk_output_dash_and_dash_plot_show_fun5714__t_7, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_output_dash_and_dash_plot_show_fun5714_7, kk_context());
  _self->hist = hist;
  return &_self->_base;
}

static kk_unit_t kk_output_dash_and_dash_plot_show_fun5714_7(kk_function_t _fself, kk_integer_t i, kk_context_t* _ctx) {
  struct kk_output_dash_and_dash_plot_show_fun5714__t_7* _self = kk_function_as(struct kk_output_dash_and_dash_plot_show_fun5714__t_7*, _fself);
  kk_std_core__list hist = _self->hist; /* effects-and-types/histogram<(double) -> double> */
  kk_drop_match(_self, {kk_std_core__list_dup(hist);}, {}, _ctx)
  kk_string_t str;
  kk_std_core_types__maybe _match_5444 = kk_std_core__lp__lb__rb__2_rp_(hist, i, _ctx); /*maybe<1>*/;
  if (kk_std_core_types__is_Nothing(_match_5444)) {
    str = kk_string_empty(); /*string*/
  }
  else {
    kk_box_t _box_x5337 = _match_5444._cons.Just.value;
    kk_std_core_types__tuple2_ x = kk_std_core_types__tuple2__unbox(_box_x5337, NULL);
    kk_std_core_types__tuple2__dup(x);
    kk_std_core_types__maybe_drop(_match_5444, _ctx);
    kk_box_t _box_x5338 = x.fst;
    kk_box_t _fun_unbox_x5342 = x.snd;
    kk_effects_dash_and_dash_types__exp _pat2 = kk_effects_dash_and_dash_types__exp_unbox(_box_x5338, NULL);
    double dbl = _pat2.i;
    kk_box_dup(_fun_unbox_x5342);
    kk_std_core_types__tuple2__drop(x, _ctx);
    kk_string_t _x5718;
    kk_define_string_literal(, _s5719, 1, "(")
    _x5718 = kk_string_dup(_s5719); /*string*/
    kk_string_t _x5720;
    kk_string_t _x5721;
    kk_std_num_ddouble__ddouble _x5722;
    kk_std_num_ddouble__ddouble _x5723 = kk_std_num_ddouble_ddouble(dbl, _ctx); /*std/num/ddouble/ddouble*/
    _x5722 = kk_std_num_ddouble_exp(_x5723, _ctx); /*std/num/ddouble/ddouble*/
    kk_std_core_types__optional _x5724 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(1)), _ctx); /*optional<35>*/
    _x5721 = kk_std_num_ddouble_show_fixed(_x5722, _x5724, _ctx); /*string*/
    kk_string_t _x5725;
    kk_string_t _x5726;
    kk_define_string_literal(, _s5727, 2, ", ")
    _x5726 = kk_string_dup(_s5727); /*string*/
    kk_string_t _x5728;
    kk_string_t _x5729;
    double _x5730;
    kk_box_t _x5731;
    kk_function_t _x5732 = kk_function_unbox(_fun_unbox_x5342); /*(5343) -> 5344*/
    _x5731 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x5732, (_x5732, kk_double_box(0x1.9p6, _ctx), _ctx)); /*5344*/
    _x5730 = kk_double_unbox(_x5731, _ctx); /*double*/
    kk_std_core_types__optional _x5733 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(1)), _ctx); /*optional<35>*/
    _x5729 = kk_std_core_show_fixed(_x5730, _x5733, _ctx); /*string*/
    kk_string_t _x5734;
    kk_define_string_literal(, _s5735, 1, ")")
    _x5734 = kk_string_dup(_s5735); /*string*/
    _x5728 = kk_std_core__lp__plus__plus__1_rp_(_x5729, _x5734, _ctx); /*string*/
    _x5725 = kk_std_core__lp__plus__plus__1_rp_(_x5726, _x5728, _ctx); /*string*/
    _x5720 = kk_std_core__lp__plus__plus__1_rp_(_x5721, _x5725, _ctx); /*string*/
    str = kk_std_core__lp__plus__plus__1_rp_(_x5718, _x5720, _ctx); /*string*/
  }
  return kk_std_core_println(str, _ctx);
}

kk_integer_t kk_output_dash_and_dash_plot_show_7(kk_std_core__list hist, kk_context_t* _ctx) { /* (hist : effects-and-types/histogram<(double) -> double>) -> console int */ 
  kk_unit_t __ = kk_Unit;
  kk_integer_t end_5113;
  kk_integer_t _x5712;
  kk_std_core__list _x5713 = kk_std_core__list_dup(hist); /*effects-and-types/histogram<(double) -> double>*/
  _x5712 = kk_std_core_length_1(_x5713, _ctx); /*int*/
  end_5113 = kk_integer_sub(_x5712,(kk_integer_from_small(1)),kk_context()); /*int*/
  kk_std_core__lift21056_for(kk_output_dash_and_dash_plot_new_show_fun5714_7(hist, _ctx), end_5113, kk_integer_from_small(0), _ctx);
  return kk_integer_from_small(0);
}


// lift anonymous function
struct kk_output_dash_and_dash_plot_plot_fun5738__t {
  struct kk_function_s _base;
  kk_function_t f;
  double stp;
};
static kk_box_t kk_output_dash_and_dash_plot_plot_fun5738(kk_function_t _fself, kk_integer_t _b_5357, kk_context_t* _ctx);
static kk_function_t kk_output_dash_and_dash_plot_new_plot_fun5738(kk_function_t f, double stp, kk_context_t* _ctx) {
  struct kk_output_dash_and_dash_plot_plot_fun5738__t* _self = kk_function_alloc_as(struct kk_output_dash_and_dash_plot_plot_fun5738__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_output_dash_and_dash_plot_plot_fun5738, kk_context());
  _self->f = f;
  _self->stp = stp;
  return &_self->_base;
}

static kk_box_t kk_output_dash_and_dash_plot_plot_fun5738(kk_function_t _fself, kk_integer_t _b_5357, kk_context_t* _ctx) {
  struct kk_output_dash_and_dash_plot_plot_fun5738__t* _self = kk_function_as(struct kk_output_dash_and_dash_plot_plot_fun5738__t*, _fself);
  kk_function_t f = _self->f; /* (double) -> double */
  double stp = _self->stp; /* double */
  kk_drop_match(_self, {kk_function_dup(f);;}, {}, _ctx)
  kk_string_t _x5739;
  double x0;
  double _x5740;
  double _x5741 = kk_integer_as_double(_b_5357,kk_context()); /*double*/
  _x5740 = (stp * _x5741); /*double*/
  x0 = ((0x0p+0) + _x5740); /*double*/
  double y = kk_function_call(double, (kk_function_t, double, kk_context_t*), f, (f, x0, _ctx)); /*double*/;
  kk_string_t _x5742;
  kk_define_string_literal(, _s5743, 1, "[")
  _x5742 = kk_string_dup(_s5743); /*string*/
  kk_string_t _x5744;
  kk_string_t _x5745;
  kk_std_core_types__optional _x5746 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(6)), _ctx); /*optional<35>*/
  _x5745 = kk_std_core_show_1(x0, _x5746, _ctx); /*string*/
  kk_string_t _x5747;
  kk_string_t _x5748;
  kk_define_string_literal(, _s5749, 1, ",")
  _x5748 = kk_string_dup(_s5749); /*string*/
  kk_string_t _x5750;
  kk_string_t _x5751;
  kk_std_core_types__optional _x5752 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(6)), _ctx); /*optional<35>*/
  _x5751 = kk_std_core_show_1(y, _x5752, _ctx); /*string*/
  kk_string_t _x5753;
  kk_define_string_literal(, _s5754, 1, "]")
  _x5753 = kk_string_dup(_s5754); /*string*/
  _x5750 = kk_std_core__lp__plus__plus__1_rp_(_x5751, _x5753, _ctx); /*string*/
  _x5747 = kk_std_core__lp__plus__plus__1_rp_(_x5748, _x5750, _ctx); /*string*/
  _x5744 = kk_std_core__lp__plus__plus__1_rp_(_x5745, _x5747, _ctx); /*string*/
  _x5739 = kk_std_core__lp__plus__plus__1_rp_(_x5742, _x5744, _ctx); /*string*/
  return kk_string_box(_x5739);
}


// lift anonymous function
struct kk_output_dash_and_dash_plot_plot_fun5756__t {
  struct kk_function_s _base;
};
static kk_box_t kk_output_dash_and_dash_plot_plot_fun5756(kk_function_t _fself, kk_box_t _b_5366, kk_context_t* _ctx);
static kk_function_t kk_output_dash_and_dash_plot_new_plot_fun5756(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_output_dash_and_dash_plot_plot_fun5756, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_output_dash_and_dash_plot_plot_fun5756(kk_function_t _fself, kk_box_t _b_5366, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x5757;
  kk_std_core__list _x5758 = kk_std_core__list_unbox(_b_5366, _ctx); /*list<string>*/
  _x5757 = kk_output_dash_and_dash_plot__mlift5053_list_join(_x5758, _ctx); /*string*/
  return kk_string_box(_x5757);
}

kk_string_t kk_output_dash_and_dash_plot_plot(kk_function_t f, kk_context_t* _ctx) { /* (f : (double) -> double) -> string */ 
  double stp;
  double _x5736 = (0x1p2 - (0x0p+0)); /*double*/
  double _x5737 = kk_integer_as_double((kk_integer_from_small(100)),kk_context()); /*double*/
  stp = (_x5736 / _x5737); /*double*/
  kk_std_core__list x_5117 = kk_std_core__lift21054_list_1(kk_output_dash_and_dash_plot_new_plot_fun5738(f, stp, _ctx), kk_integer_from_small(1), kk_integer_from_small(100), kk_std_core__new_Nil(_ctx), _ctx); /*list<string>*/;
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_5117, _ctx);
    kk_box_t _x5755 = kk_std_core_hnd_yield_extend(kk_output_dash_and_dash_plot_new_plot_fun5756(_ctx), _ctx); /*2*/
    return kk_string_unbox(_x5755);
  }
  kk_string_t _x5759;
  kk_define_string_literal(, _s5760, 1, "[")
  _x5759 = kk_string_dup(_s5760); /*string*/
  kk_string_t _x5761;
  kk_string_t _x5762;
  if (kk_std_core__is_Nil(x_5117)) {
    _x5762 = kk_string_empty(); /*string*/
  }
  else {
    struct kk_std_core_Cons* _con5764 = kk_std_core__as_Cons(x_5117);
    kk_box_t _box_x5367 = _con5764->head;
    kk_std_core__list xx = _con5764->tail;
    kk_string_t x = kk_string_unbox(_box_x5367);
    if (kk_std_core__list_is_unique(x_5117)) {
      kk_std_core__list_free(x_5117);
    }
    else {
      kk_string_dup(x);
      kk_std_core__list_dup(xx);
      kk_std_core__list_decref(x_5117, _ctx);
    }
    kk_string_t _x5766;
    kk_define_string_literal(, _s5767, 1, ",")
    _x5766 = kk_string_dup(_s5767); /*string*/
    _x5762 = kk_std_core__lift21050_joinsep(_x5766, xx, x, _ctx); /*string*/
  }
  kk_string_t _x5768;
  kk_define_string_literal(, _s5769, 1, "]")
  _x5768 = kk_string_dup(_s5769); /*string*/
  _x5761 = kk_std_core__lp__plus__plus__1_rp_(_x5762, _x5768, _ctx); /*string*/
  return kk_std_core__lp__plus__plus__1_rp_(_x5759, _x5761, _ctx);
}
extern double kk_output_dash_and_dash_plot_example_plot_fun5770(kk_function_t _fself, double x, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return (0x1p1 * x);
}


// lift anonymous function
struct kk_output_dash_and_dash_plot_show__trace_fun5777__t {
  struct kk_function_s _base;
  kk_ref_t loc;
  kk_std_core__list tmcmc__result;
};
static kk_unit_t kk_output_dash_and_dash_plot_show__trace_fun5777(kk_function_t _fself, kk_integer_t i, kk_context_t* _ctx);
static kk_function_t kk_output_dash_and_dash_plot_new_show__trace_fun5777(kk_ref_t loc, kk_std_core__list tmcmc__result, kk_context_t* _ctx) {
  struct kk_output_dash_and_dash_plot_show__trace_fun5777__t* _self = kk_function_alloc_as(struct kk_output_dash_and_dash_plot_show__trace_fun5777__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_output_dash_and_dash_plot_show__trace_fun5777, kk_context());
  _self->loc = loc;
  _self->tmcmc__result = tmcmc__result;
  return &_self->_base;
}

static kk_unit_t kk_output_dash_and_dash_plot_show__trace_fun5777(kk_function_t _fself, kk_integer_t i, kk_context_t* _ctx) {
  struct kk_output_dash_and_dash_plot_show__trace_fun5777__t* _self = kk_function_as(struct kk_output_dash_and_dash_plot_show__trace_fun5777__t*, _fself);
  kk_ref_t loc = _self->loc; /* local-var<global,string> */
  kk_std_core__list tmcmc__result = _self->tmcmc__result; /* list<(list<double>, list<double>)> */
  kk_drop_match(_self, {kk_ref_dup(loc);kk_std_core__list_dup(tmcmc__result);}, {}, _ctx)
  kk_string_t str;
  kk_std_core_types__maybe _match_5442 = kk_std_core__lp__lb__rb__2_rp_(tmcmc__result, i, _ctx); /*maybe<1>*/;
  if (kk_std_core_types__is_Nothing(_match_5442)) {
    str = kk_string_empty(); /*string*/
  }
  else {
    kk_box_t _box_x5372 = _match_5442._cons.Just.value;
    kk_std_core_types__tuple2_ _pat1 = kk_std_core_types__tuple2__unbox(_box_x5372, NULL);
    kk_box_t _box_x5373 = _pat1.fst;
    kk_box_t _box_x5374 = _pat1.snd;
    kk_std_core__list a = kk_std_core__list_unbox(_box_x5374, NULL);
    kk_std_core__list_dup(a);
    kk_std_core_types__maybe_drop(_match_5442, _ctx);
    str = kk_output_dash_and_dash_plot_list__to__csv(a, _ctx); /*string*/
  }
  kk_string_t _b_5379_5377;
  kk_string_t _x5782;
  kk_box_t _x5783;
  kk_ref_t _x5784 = kk_ref_dup(loc); /*local-var<global,string>*/
  _x5783 = (kk_ref_get(_x5784,kk_context())); /*0*/
  _x5782 = kk_string_unbox(_x5783); /*string*/
  _b_5379_5377 = kk_std_core__lp__plus__plus__1_rp_(_x5782, str, _ctx); /*string*/
  return (kk_ref_set(loc,(kk_string_box(_b_5379_5377)),kk_context()));
}

kk_string_t kk_output_dash_and_dash_plot_show__trace(kk_std_core__list tmcmc__result, kk_context_t* _ctx) { /* (tmcmc_result : list<(list<double>, list<double>)>) -> string */ 
  kk_ref_t loc;
  kk_box_t _x5771;
  kk_string_t _x5772 = kk_string_empty(); /*string*/
  _x5771 = kk_string_box(_x5772); /*0*/
  loc = kk_ref_alloc(_x5771,kk_context()); /*local-var<global,string>*/
  kk_string_t res;
  kk_unit_t __ = kk_Unit;
  kk_integer_t end_5131;
  kk_integer_t _x5774;
  kk_std_core__list _x5775 = kk_std_core__list_dup(tmcmc__result); /*list<(list<double>, list<double>)>*/
  _x5774 = kk_std_core_length_1(_x5775, _ctx); /*int*/
  end_5131 = kk_integer_sub(_x5774,(kk_integer_from_small(1)),kk_context()); /*int*/
  kk_function_t _x5776;
  kk_ref_dup(loc);
  _x5776 = kk_output_dash_and_dash_plot_new_show__trace_fun5777(loc, tmcmc__result, _ctx); /*(i : int) -> (local<global>) ()*/
  kk_std_core__lift21056_for(_x5776, end_5131, kk_integer_from_small(0), _ctx);
  kk_box_t _x5785;
  kk_ref_t _x5786 = kk_ref_dup(loc); /*local-var<global,string>*/
  _x5785 = (kk_ref_get(_x5786,kk_context())); /*0*/
  res = kk_string_unbox(_x5785); /*string*/
  kk_box_t _x5787 = kk_std_core_hnd_prompt_local_var(loc, kk_string_box(res), _ctx); /*2*/
  return kk_string_unbox(_x5787);
}


// lift anonymous function
struct kk_output_dash_and_dash_plot_write_fun5790__t {
  struct kk_function_s _base;
};
static kk_box_t kk_output_dash_and_dash_plot_write_fun5790(kk_function_t _fself, kk_box_t _b_5389, kk_context_t* _ctx);
static kk_function_t kk_output_dash_and_dash_plot_new_write_fun5790(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_output_dash_and_dash_plot_write_fun5790, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_output_dash_and_dash_plot_write_fun5790(kk_function_t _fself, kk_box_t _b_5389, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_os_path__path _x5791;
  kk_string_t _x5792 = kk_string_unbox(_b_5389); /*string*/
  _x5791 = kk_std_os_path_path(_x5792, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x5791, _ctx);
}


// lift anonymous function
struct kk_output_dash_and_dash_plot_write_fun5795__t {
  struct kk_function_s _base;
};
static kk_box_t kk_output_dash_and_dash_plot_write_fun5795(kk_function_t _fself, kk_box_t _b_5392, kk_context_t* _ctx);
static kk_function_t kk_output_dash_and_dash_plot_new_write_fun5795(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_output_dash_and_dash_plot_write_fun5795, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_output_dash_and_dash_plot_write_fun5795(kk_function_t _fself, kk_box_t _b_5392, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x5796;
  kk_std_core__list _x5797 = kk_std_core__list_unbox(_b_5392, _ctx); /*list<(list<double>, double)>*/
  _x5796 = kk_output_dash_and_dash_plot_show__trace__single(_x5797, _ctx); /*string*/
  return kk_string_box(_x5796);
}

kk_unit_t kk_output_dash_and_dash_plot_write(kk_std_core__list trace, kk_string_t filename, kk_context_t* _ctx) { /* (trace : list<(list<double>, double)>, filename : string) -> <exn,fsys> () */ 
  kk_std_os_path__path _x5788;
  kk_box_t _x5789 = kk_std_core_hnd__open_none1(kk_output_dash_and_dash_plot_new_write_fun5790(_ctx), kk_string_box(filename), _ctx); /*2*/
  _x5788 = kk_std_os_path__path_unbox(_x5789, _ctx); /*std/os/path/path*/
  kk_string_t _x5793;
  kk_box_t _x5794 = kk_std_core_hnd__open_none1(kk_output_dash_and_dash_plot_new_write_fun5795(_ctx), kk_std_core__list_box(trace, _ctx), _ctx); /*2*/
  _x5793 = kk_string_unbox(_x5794); /*string*/
  kk_std_os_file_write_text_file(_x5788, _x5793, kk_std_core_types__new_None(_ctx), _ctx); return kk_Unit;
}


// lift anonymous function
struct kk_output_dash_and_dash_plot_write_fun5800__t_1 {
  struct kk_function_s _base;
};
static kk_box_t kk_output_dash_and_dash_plot_write_fun5800_1(kk_function_t _fself, kk_box_t _b_5399, kk_context_t* _ctx);
static kk_function_t kk_output_dash_and_dash_plot_new_write_fun5800_1(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_output_dash_and_dash_plot_write_fun5800_1, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_output_dash_and_dash_plot_write_fun5800_1(kk_function_t _fself, kk_box_t _b_5399, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_os_path__path _x5801;
  kk_string_t _x5802 = kk_string_unbox(_b_5399); /*string*/
  _x5801 = kk_std_os_path_path(_x5802, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x5801, _ctx);
}


// lift anonymous function
struct kk_output_dash_and_dash_plot_write_fun5805__t_1 {
  struct kk_function_s _base;
};
static kk_box_t kk_output_dash_and_dash_plot_write_fun5805_1(kk_function_t _fself, kk_box_t _b_5402, kk_context_t* _ctx);
static kk_function_t kk_output_dash_and_dash_plot_new_write_fun5805_1(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_output_dash_and_dash_plot_write_fun5805_1, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_output_dash_and_dash_plot_write_fun5805_1(kk_function_t _fself, kk_box_t _b_5402, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x5806;
  kk_std_core__list _x5807 = kk_std_core__list_unbox(_b_5402, _ctx); /*list<(list<double>, list<double>)>*/
  _x5806 = kk_output_dash_and_dash_plot_show__trace(_x5807, _ctx); /*string*/
  return kk_string_box(_x5806);
}

kk_unit_t kk_output_dash_and_dash_plot_write_1(kk_std_core__list trace, kk_string_t filename, kk_context_t* _ctx) { /* (trace : list<(list<double>, list<double>)>, filename : string) -> <exn,fsys> () */ 
  kk_std_os_path__path _x5798;
  kk_box_t _x5799 = kk_std_core_hnd__open_none1(kk_output_dash_and_dash_plot_new_write_fun5800_1(_ctx), kk_string_box(filename), _ctx); /*2*/
  _x5798 = kk_std_os_path__path_unbox(_x5799, _ctx); /*std/os/path/path*/
  kk_string_t _x5803;
  kk_box_t _x5804 = kk_std_core_hnd__open_none1(kk_output_dash_and_dash_plot_new_write_fun5805_1(_ctx), kk_std_core__list_box(trace, _ctx), _ctx); /*2*/
  _x5803 = kk_string_unbox(_x5804); /*string*/
  kk_std_os_file_write_text_file(_x5798, _x5803, kk_std_core_types__new_None(_ctx), _ctx); return kk_Unit;
}


// lift anonymous function
struct kk_output_dash_and_dash_plot_write_fun5810__t_2 {
  struct kk_function_s _base;
};
static kk_box_t kk_output_dash_and_dash_plot_write_fun5810_2(kk_function_t _fself, kk_box_t _b_5409, kk_context_t* _ctx);
static kk_function_t kk_output_dash_and_dash_plot_new_write_fun5810_2(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_output_dash_and_dash_plot_write_fun5810_2, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_output_dash_and_dash_plot_write_fun5810_2(kk_function_t _fself, kk_box_t _b_5409, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_os_path__path _x5811;
  kk_string_t _x5812 = kk_string_unbox(_b_5409); /*string*/
  _x5811 = kk_std_os_path_path(_x5812, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x5811, _ctx);
}


// lift anonymous function
struct kk_output_dash_and_dash_plot_write_fun5815__t_2 {
  struct kk_function_s _base;
};
static kk_box_t kk_output_dash_and_dash_plot_write_fun5815_2(kk_function_t _fself, kk_box_t _b_5412, kk_context_t* _ctx);
static kk_function_t kk_output_dash_and_dash_plot_new_write_fun5815_2(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_output_dash_and_dash_plot_write_fun5815_2, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_output_dash_and_dash_plot_write_fun5815_2(kk_function_t _fself, kk_box_t _b_5412, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x5816;
  kk_std_core__list _x5817 = kk_std_core__list_unbox(_b_5412, _ctx); /*effects-and-types/histogram<double>*/
  _x5816 = kk_output_dash_and_dash_plot_show(_x5817, _ctx); /*string*/
  return kk_string_box(_x5816);
}

kk_unit_t kk_output_dash_and_dash_plot_write_2(kk_std_core__list hist, kk_string_t filename, kk_context_t* _ctx) { /* (hist : effects-and-types/histogram<double>, filename : string) -> <exn,fsys> () */ 
  kk_std_os_path__path _x5808;
  kk_box_t _x5809 = kk_std_core_hnd__open_none1(kk_output_dash_and_dash_plot_new_write_fun5810_2(_ctx), kk_string_box(filename), _ctx); /*2*/
  _x5808 = kk_std_os_path__path_unbox(_x5809, _ctx); /*std/os/path/path*/
  kk_string_t _x5813;
  kk_box_t _x5814 = kk_std_core_hnd__open_none1(kk_output_dash_and_dash_plot_new_write_fun5815_2(_ctx), kk_std_core__list_box(hist, _ctx), _ctx); /*2*/
  _x5813 = kk_string_unbox(_x5814); /*string*/
  kk_std_os_file_write_text_file(_x5808, _x5813, kk_std_core_types__new_None(_ctx), _ctx); return kk_Unit;
}


// lift anonymous function
struct kk_output_dash_and_dash_plot_write_fun5820__t_3 {
  struct kk_function_s _base;
};
static kk_box_t kk_output_dash_and_dash_plot_write_fun5820_3(kk_function_t _fself, kk_box_t _b_5419, kk_context_t* _ctx);
static kk_function_t kk_output_dash_and_dash_plot_new_write_fun5820_3(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_output_dash_and_dash_plot_write_fun5820_3, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_output_dash_and_dash_plot_write_fun5820_3(kk_function_t _fself, kk_box_t _b_5419, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_os_path__path _x5821;
  kk_string_t _x5822 = kk_string_unbox(_b_5419); /*string*/
  _x5821 = kk_std_os_path_path(_x5822, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x5821, _ctx);
}


// lift anonymous function
struct kk_output_dash_and_dash_plot_write_fun5825__t_3 {
  struct kk_function_s _base;
};
static kk_box_t kk_output_dash_and_dash_plot_write_fun5825_3(kk_function_t _fself, kk_box_t _b_5422, kk_context_t* _ctx);
static kk_function_t kk_output_dash_and_dash_plot_new_write_fun5825_3(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_output_dash_and_dash_plot_write_fun5825_3, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_output_dash_and_dash_plot_write_fun5825_3(kk_function_t _fself, kk_box_t _b_5422, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x5826;
  kk_std_core__list _x5827 = kk_std_core__list_unbox(_b_5422, _ctx); /*effects-and-types/histogram<(double, double)>*/
  _x5826 = kk_output_dash_and_dash_plot_show_1(_x5827, _ctx); /*string*/
  return kk_string_box(_x5826);
}

kk_unit_t kk_output_dash_and_dash_plot_write_3(kk_std_core__list hist, kk_string_t filename, kk_context_t* _ctx) { /* (hist : effects-and-types/histogram<(double, double)>, filename : string) -> <exn,fsys> () */ 
  kk_std_os_path__path _x5818;
  kk_box_t _x5819 = kk_std_core_hnd__open_none1(kk_output_dash_and_dash_plot_new_write_fun5820_3(_ctx), kk_string_box(filename), _ctx); /*2*/
  _x5818 = kk_std_os_path__path_unbox(_x5819, _ctx); /*std/os/path/path*/
  kk_string_t _x5823;
  kk_box_t _x5824 = kk_std_core_hnd__open_none1(kk_output_dash_and_dash_plot_new_write_fun5825_3(_ctx), kk_std_core__list_box(hist, _ctx), _ctx); /*2*/
  _x5823 = kk_string_unbox(_x5824); /*string*/
  kk_std_os_file_write_text_file(_x5818, _x5823, kk_std_core_types__new_None(_ctx), _ctx); return kk_Unit;
}


// lift anonymous function
struct kk_output_dash_and_dash_plot_write_fun5830__t_4 {
  struct kk_function_s _base;
};
static kk_box_t kk_output_dash_and_dash_plot_write_fun5830_4(kk_function_t _fself, kk_box_t _b_5429, kk_context_t* _ctx);
static kk_function_t kk_output_dash_and_dash_plot_new_write_fun5830_4(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_output_dash_and_dash_plot_write_fun5830_4, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_output_dash_and_dash_plot_write_fun5830_4(kk_function_t _fself, kk_box_t _b_5429, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_os_path__path _x5831;
  kk_string_t _x5832 = kk_string_unbox(_b_5429); /*string*/
  _x5831 = kk_std_os_path_path(_x5832, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x5831, _ctx);
}


// lift anonymous function
struct kk_output_dash_and_dash_plot_write_fun5835__t_4 {
  struct kk_function_s _base;
};
static kk_box_t kk_output_dash_and_dash_plot_write_fun5835_4(kk_function_t _fself, kk_box_t _b_5432, kk_context_t* _ctx);
static kk_function_t kk_output_dash_and_dash_plot_new_write_fun5835_4(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_output_dash_and_dash_plot_write_fun5835_4, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_output_dash_and_dash_plot_write_fun5835_4(kk_function_t _fself, kk_box_t _b_5432, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x5836;
  kk_std_core__list _x5837 = kk_std_core__list_unbox(_b_5432, _ctx); /*effects-and-types/histogram<list<double>>*/
  _x5836 = kk_output_dash_and_dash_plot_show_2(_x5837, _ctx); /*string*/
  return kk_string_box(_x5836);
}

kk_unit_t kk_output_dash_and_dash_plot_write_4(kk_std_core__list hist, kk_string_t filename, kk_context_t* _ctx) { /* (hist : effects-and-types/histogram<list<double>>, filename : string) -> <exn,fsys> () */ 
  kk_std_os_path__path _x5828;
  kk_box_t _x5829 = kk_std_core_hnd__open_none1(kk_output_dash_and_dash_plot_new_write_fun5830_4(_ctx), kk_string_box(filename), _ctx); /*2*/
  _x5828 = kk_std_os_path__path_unbox(_x5829, _ctx); /*std/os/path/path*/
  kk_string_t _x5833;
  kk_box_t _x5834 = kk_std_core_hnd__open_none1(kk_output_dash_and_dash_plot_new_write_fun5835_4(_ctx), kk_std_core__list_box(hist, _ctx), _ctx); /*2*/
  _x5833 = kk_string_unbox(_x5834); /*string*/
  kk_std_os_file_write_text_file(_x5828, _x5833, kk_std_core_types__new_None(_ctx), _ctx); return kk_Unit;
}

// initialization
void kk_output_dash_and_dash_plot__init(kk_context_t* _ctx){
  static bool _initialized = false;
  if (_initialized) return;
  _initialized = true;
  kk_std_core_types__init(_ctx);
  kk_std_core_hnd__init(_ctx);
  kk_std_core__init(_ctx);
  kk_effects_dash_and_dash_types__init(_ctx);
  kk_std_num_ddouble__init(_ctx);
  kk_std_os_path__init(_ctx);
  kk_std_os_file__init(_ctx);
}
