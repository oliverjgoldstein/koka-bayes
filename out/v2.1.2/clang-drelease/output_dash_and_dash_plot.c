// Koka generated module: "output-and-plot", koka version: 2.1.2
#include "output_dash_and_dash_plot.h"
 
// monadic lift

kk_string_t kk_output_dash_and_dash_plot__mlift6203_list_join(kk_std_core__list xs, kk_context_t* _ctx) { /* forall<e> (xs : list<string>) -> e string */ 
  kk_string_t _x6768;
  kk_define_string_literal(, _s6769, 1, "[")
  _x6768 = kk_string_dup(_s6769); /*string*/
  kk_string_t _x6770;
  kk_string_t _x6771;
  if (kk_std_core__is_Nil(xs)) {
    _x6771 = kk_string_empty(); /*string*/
  }
  else {
    struct kk_std_core_Cons* _con6773 = kk_std_core__as_Cons(xs);
    kk_box_t _box_x6314 = _con6773->head;
    kk_std_core__list xx = _con6773->tail;
    kk_string_t x = kk_string_unbox(_box_x6314);
    if (kk_std_core__list_is_unique(xs)) {
      kk_std_core__list_free(xs);
    }
    else {
      kk_string_dup(x);
      kk_std_core__list_dup(xx);
      kk_std_core__list_decref(xs, _ctx);
    }
    kk_string_t _x6775;
    kk_define_string_literal(, _s6776, 1, ",")
    _x6775 = kk_string_dup(_s6776); /*string*/
    _x6771 = kk_std_core__lift21050_joinsep(_x6775, xx, x, _ctx); /*string*/
  }
  kk_string_t _x6777;
  kk_define_string_literal(, _s6778, 1, "]")
  _x6777 = kk_string_dup(_s6778); /*string*/
  _x6770 = kk_std_core__lp__plus__plus__1_rp_(_x6771, _x6777, _ctx); /*string*/
  return kk_std_core__lp__plus__plus__1_rp_(_x6768, _x6770, _ctx);
}


// lift anonymous function
struct kk_output_dash_and_dash_plot_list_join_fun6779__t {
  struct kk_function_s _base;
  kk_function_t elem;
};
static kk_box_t kk_output_dash_and_dash_plot_list_join_fun6779(kk_function_t _fself, kk_integer_t _b_6319, kk_context_t* _ctx);
static kk_function_t kk_output_dash_and_dash_plot_new_list_join_fun6779(kk_function_t elem, kk_context_t* _ctx) {
  struct kk_output_dash_and_dash_plot_list_join_fun6779__t* _self = kk_function_alloc_as(struct kk_output_dash_and_dash_plot_list_join_fun6779__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_output_dash_and_dash_plot_list_join_fun6779, kk_context());
  _self->elem = elem;
  return &_self->_base;
}

static kk_box_t kk_output_dash_and_dash_plot_list_join_fun6779(kk_function_t _fself, kk_integer_t _b_6319, kk_context_t* _ctx) {
  struct kk_output_dash_and_dash_plot_list_join_fun6779__t* _self = kk_function_as(struct kk_output_dash_and_dash_plot_list_join_fun6779__t*, _fself);
  kk_function_t elem = _self->elem; /* (int) -> 5 string */
  kk_drop_match(_self, {kk_function_dup(elem);}, {}, _ctx)
  kk_string_t _x6780 = kk_function_call(kk_string_t, (kk_function_t, kk_integer_t, kk_context_t*), elem, (elem, _b_6319, _ctx)); /*string*/
  return kk_string_box(_x6780);
}


// lift anonymous function
struct kk_output_dash_and_dash_plot_list_join_fun6782__t {
  struct kk_function_s _base;
};
static kk_box_t kk_output_dash_and_dash_plot_list_join_fun6782(kk_function_t _fself, kk_box_t _b_6325, kk_context_t* _ctx);
static kk_function_t kk_output_dash_and_dash_plot_new_list_join_fun6782(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_output_dash_and_dash_plot_list_join_fun6782, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_output_dash_and_dash_plot_list_join_fun6782(kk_function_t _fself, kk_box_t _b_6325, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x6783;
  kk_std_core__list _x6784 = kk_std_core__list_unbox(_b_6325, _ctx); /*list<string>*/
  _x6783 = kk_output_dash_and_dash_plot__mlift6203_list_join(_x6784, _ctx); /*string*/
  return kk_string_box(_x6783);
}

kk_string_t kk_output_dash_and_dash_plot_list_join(kk_integer_t len, kk_function_t elem, kk_context_t* _ctx) { /* forall<e> (len : int, elem : (int) -> e string) -> e string */ 
  kk_std_core__list x_6207 = kk_std_core__lift21054_list_1(kk_output_dash_and_dash_plot_new_list_join_fun6779(elem, _ctx), kk_integer_from_small(1), len, kk_std_core__new_Nil(_ctx), _ctx); /*list<string>*/;
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_6207, _ctx);
    kk_box_t _x6781 = kk_std_core_hnd_yield_extend(kk_output_dash_and_dash_plot_new_list_join_fun6782(_ctx), _ctx); /*2*/
    return kk_string_unbox(_x6781);
  }
  kk_string_t _x6785;
  kk_define_string_literal(, _s6786, 1, "[")
  _x6785 = kk_string_dup(_s6786); /*string*/
  kk_string_t _x6787;
  kk_string_t _x6788;
  if (kk_std_core__is_Nil(x_6207)) {
    _x6788 = kk_string_empty(); /*string*/
  }
  else {
    struct kk_std_core_Cons* _con6790 = kk_std_core__as_Cons(x_6207);
    kk_box_t _box_x6326 = _con6790->head;
    kk_std_core__list xx = _con6790->tail;
    kk_string_t x = kk_string_unbox(_box_x6326);
    if (kk_std_core__list_is_unique(x_6207)) {
      kk_std_core__list_free(x_6207);
    }
    else {
      kk_string_dup(x);
      kk_std_core__list_dup(xx);
      kk_std_core__list_decref(x_6207, _ctx);
    }
    kk_string_t _x6792;
    kk_define_string_literal(, _s6793, 1, ",")
    _x6792 = kk_string_dup(_s6793); /*string*/
    _x6788 = kk_std_core__lift21050_joinsep(_x6792, xx, x, _ctx); /*string*/
  }
  kk_string_t _x6794;
  kk_define_string_literal(, _s6795, 1, "]")
  _x6794 = kk_string_dup(_s6795); /*string*/
  _x6787 = kk_std_core__lp__plus__plus__1_rp_(_x6788, _x6794, _ctx); /*string*/
  return kk_std_core__lp__plus__plus__1_rp_(_x6785, _x6787, _ctx);
}


// lift anonymous function
struct kk_output_dash_and_dash_plot_list__to__csv_fun6802__t {
  struct kk_function_s _base;
  kk_ref_t loc;
  kk_std_core__list xs;
};
static kk_unit_t kk_output_dash_and_dash_plot_list__to__csv_fun6802(kk_function_t _fself, kk_integer_t i, kk_context_t* _ctx);
static kk_function_t kk_output_dash_and_dash_plot_new_list__to__csv_fun6802(kk_ref_t loc, kk_std_core__list xs, kk_context_t* _ctx) {
  struct kk_output_dash_and_dash_plot_list__to__csv_fun6802__t* _self = kk_function_alloc_as(struct kk_output_dash_and_dash_plot_list__to__csv_fun6802__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_output_dash_and_dash_plot_list__to__csv_fun6802, kk_context());
  _self->loc = loc;
  _self->xs = xs;
  return &_self->_base;
}

static kk_unit_t kk_output_dash_and_dash_plot_list__to__csv_fun6802(kk_function_t _fself, kk_integer_t i, kk_context_t* _ctx) {
  struct kk_output_dash_and_dash_plot_list__to__csv_fun6802__t* _self = kk_function_as(struct kk_output_dash_and_dash_plot_list__to__csv_fun6802__t*, _fself);
  kk_ref_t loc = _self->loc; /* local-var<global,string> */
  kk_std_core__list xs = _self->xs; /* list<double> */
  kk_drop_match(_self, {kk_ref_dup(loc);kk_std_core__list_dup(xs);}, {}, _ctx)
  kk_string_t str;
  kk_std_core_types__maybe _match_6766 = kk_std_core__lp__lb__rb__2_rp_(xs, i, _ctx); /*maybe<1>*/;
  if (kk_std_core_types__is_Nothing(_match_6766)) {
    str = kk_string_empty(); /*string*/
  }
  else {
    kk_box_t _box_x6331 = _match_6766._cons.Just.value;
    double x = kk_double_unbox(_box_x6331, NULL);
    kk_string_t _x6805 = kk_std_core_show_fixed(x, kk_std_core_types__new_None(_ctx), _ctx); /*string*/
    kk_string_t _x6806;
    kk_define_string_literal(, _s6807, 1, ",")
    _x6806 = kk_string_dup(_s6807); /*string*/
    str = kk_std_core__lp__plus__plus__1_rp_(_x6805, _x6806, _ctx); /*string*/
  }
  kk_string_t _b_6336_6334;
  kk_string_t _x6808;
  kk_box_t _x6809;
  kk_ref_t _x6810 = kk_ref_dup(loc); /*local-var<global,string>*/
  _x6809 = (kk_ref_get(_x6810,kk_context())); /*0*/
  _x6808 = kk_string_unbox(_x6809); /*string*/
  _b_6336_6334 = kk_std_core__lp__plus__plus__1_rp_(_x6808, str, _ctx); /*string*/
  return (kk_ref_set(loc,(kk_string_box(_b_6336_6334)),kk_context()));
}

kk_string_t kk_output_dash_and_dash_plot_list__to__csv(kk_std_core__list xs, kk_context_t* _ctx) { /* (xs : list<double>) -> string */ 
  kk_ref_t loc;
  kk_box_t _x6796;
  kk_string_t _x6797 = kk_string_empty(); /*string*/
  _x6796 = kk_string_box(_x6797); /*0*/
  loc = kk_ref_alloc(_x6796,kk_context()); /*local-var<global,string>*/
  kk_string_t res;
  kk_unit_t __ = kk_Unit;
  kk_integer_t end_6221;
  kk_integer_t _x6799;
  kk_std_core__list _x6800 = kk_std_core__list_dup(xs); /*list<double>*/
  _x6799 = kk_std_core_length_1(_x6800, _ctx); /*int*/
  end_6221 = kk_integer_sub(_x6799,(kk_integer_from_small(2)),kk_context()); /*int*/
  kk_function_t _x6801;
  kk_ref_dup(loc);
  kk_std_core__list_dup(xs);
  _x6801 = kk_output_dash_and_dash_plot_new_list__to__csv_fun6802(loc, xs, _ctx); /*(i : int) -> (local<global>) ()*/
  kk_std_core__lift21056_for(_x6801, end_6221, kk_integer_from_small(0), _ctx);
  kk_string_t str0;
  kk_std_core_types__maybe _match_6765;
  kk_std_core__list _x6811 = kk_std_core__list_dup(xs); /*list<double>*/
  kk_integer_t _x6812;
  kk_integer_t _x6813 = kk_std_core_length_1(xs, _ctx); /*int*/
  _x6812 = kk_integer_sub(_x6813,(kk_integer_from_small(1)),kk_context()); /*int*/
  _match_6765 = kk_std_core__lp__lb__rb__2_rp_(_x6811, _x6812, _ctx); /*maybe<1>*/
  if (kk_std_core_types__is_Nothing(_match_6765)) {
    str0 = kk_string_empty(); /*string*/
  }
  else {
    kk_box_t _box_x6338 = _match_6765._cons.Just.value;
    double x0 = kk_double_unbox(_box_x6338, NULL);
    str0 = kk_std_core_show_fixed(x0, kk_std_core_types__new_None(_ctx), _ctx); /*string*/
  }
  kk_unit_t __0 = kk_Unit;
  kk_string_t _b_6343_6341;
  kk_string_t _x6816;
  kk_box_t _x6817;
  kk_ref_t _x6818 = kk_ref_dup(loc); /*local-var<global,string>*/
  _x6817 = (kk_ref_get(_x6818,kk_context())); /*0*/
  _x6816 = kk_string_unbox(_x6817); /*string*/
  kk_string_t _x6819;
  kk_string_t _x6820;
  kk_define_string_literal(, _s6821, 1, "\n")
  _x6820 = kk_string_dup(_s6821); /*string*/
  _x6819 = kk_std_core__lp__plus__plus__1_rp_(str0, _x6820, _ctx); /*string*/
  _b_6343_6341 = kk_std_core__lp__plus__plus__1_rp_(_x6816, _x6819, _ctx); /*string*/
  kk_ref_t _x6822 = kk_ref_dup(loc); /*local-var<global,string>*/
  (kk_ref_set(_x6822,(kk_string_box(_b_6343_6341)),kk_context()));
  kk_box_t _x6823;
  kk_ref_t _x6824 = kk_ref_dup(loc); /*local-var<global,string>*/
  _x6823 = (kk_ref_get(_x6824,kk_context())); /*0*/
  res = kk_string_unbox(_x6823); /*string*/
  kk_box_t _x6825 = kk_std_core_hnd_prompt_local_var(loc, kk_string_box(res), _ctx); /*2*/
  return kk_string_unbox(_x6825);
}

kk_std_core__list kk_output_dash_and_dash_plot_gen_filenames(kk_string_t filename, kk_context_t* _ctx) { /* (filename : string) -> list<string> */ 
  kk_string_t _b_6361_6359;
  kk_string_t _x6826 = kk_string_dup(filename); /*string*/
  kk_string_t _x6827;
  kk_define_string_literal(, _s6828, 12, "_tmcmc_1.csv")
  _x6827 = kk_string_dup(_s6828); /*string*/
  _b_6361_6359 = kk_std_core__lp__plus__plus__1_rp_(_x6826, _x6827, _ctx); /*string*/
  kk_std_core__list _b_6362_6360;
  kk_string_t _b_6363_6357;
  kk_string_t _x6829 = kk_string_dup(filename); /*string*/
  kk_string_t _x6830;
  kk_define_string_literal(, _s6831, 12, "_tmcmc_2.csv")
  _x6830 = kk_string_dup(_s6831); /*string*/
  _b_6363_6357 = kk_std_core__lp__plus__plus__1_rp_(_x6829, _x6830, _ctx); /*string*/
  kk_std_core__list _b_6364_6358;
  kk_string_t _b_6365_6355;
  kk_string_t _x6832 = kk_string_dup(filename); /*string*/
  kk_string_t _x6833;
  kk_define_string_literal(, _s6834, 12, "_tmcmc_3.csv")
  _x6833 = kk_string_dup(_s6834); /*string*/
  _b_6365_6355 = kk_std_core__lp__plus__plus__1_rp_(_x6832, _x6833, _ctx); /*string*/
  kk_std_core__list _b_6366_6356;
  kk_string_t _b_6367_6353;
  kk_string_t _x6835 = kk_string_dup(filename); /*string*/
  kk_string_t _x6836;
  kk_define_string_literal(, _s6837, 12, "_tmcmc_4.csv")
  _x6836 = kk_string_dup(_s6837); /*string*/
  _b_6367_6353 = kk_std_core__lp__plus__plus__1_rp_(_x6835, _x6836, _ctx); /*string*/
  kk_std_core__list _b_6368_6354;
  kk_string_t _b_6369_6351;
  kk_string_t _x6838;
  kk_define_string_literal(, _s6839, 12, "_tmcmc_5.csv")
  _x6838 = kk_string_dup(_s6839); /*string*/
  _b_6369_6351 = kk_std_core__lp__plus__plus__1_rp_(filename, _x6838, _ctx); /*string*/
  _b_6368_6354 = kk_std_core__new_Cons(kk_reuse_null, kk_string_box(_b_6369_6351), kk_std_core__new_Nil(_ctx), _ctx); /*list<string>*/
  _b_6366_6356 = kk_std_core__new_Cons(kk_reuse_null, kk_string_box(_b_6367_6353), _b_6368_6354, _ctx); /*list<string>*/
  _b_6364_6358 = kk_std_core__new_Cons(kk_reuse_null, kk_string_box(_b_6365_6355), _b_6366_6356, _ctx); /*list<string>*/
  _b_6362_6360 = kk_std_core__new_Cons(kk_reuse_null, kk_string_box(_b_6363_6357), _b_6364_6358, _ctx); /*list<string>*/
  return kk_std_core__new_Cons(kk_reuse_null, kk_string_box(_b_6361_6359), _b_6362_6360, _ctx);
}

kk_std_core__list kk_output_dash_and_dash_plot_gen_filenames2(kk_string_t filename, kk_context_t* _ctx) { /* (filename : string) -> list<string> */ 
  kk_string_t _b_6381_6379;
  kk_string_t _x6840 = kk_string_dup(filename); /*string*/
  kk_string_t _x6841;
  kk_define_string_literal(, _s6842, 12, "_tmcmc_6.csv")
  _x6841 = kk_string_dup(_s6842); /*string*/
  _b_6381_6379 = kk_std_core__lp__plus__plus__1_rp_(_x6840, _x6841, _ctx); /*string*/
  kk_std_core__list _b_6382_6380;
  kk_string_t _b_6383_6377;
  kk_string_t _x6843 = kk_string_dup(filename); /*string*/
  kk_string_t _x6844;
  kk_define_string_literal(, _s6845, 12, "_tmcmc_7.csv")
  _x6844 = kk_string_dup(_s6845); /*string*/
  _b_6383_6377 = kk_std_core__lp__plus__plus__1_rp_(_x6843, _x6844, _ctx); /*string*/
  kk_std_core__list _b_6384_6378;
  kk_string_t _b_6385_6375;
  kk_string_t _x6846 = kk_string_dup(filename); /*string*/
  kk_string_t _x6847;
  kk_define_string_literal(, _s6848, 12, "_tmcmc_8.csv")
  _x6847 = kk_string_dup(_s6848); /*string*/
  _b_6385_6375 = kk_std_core__lp__plus__plus__1_rp_(_x6846, _x6847, _ctx); /*string*/
  kk_std_core__list _b_6386_6376;
  kk_string_t _b_6387_6373;
  kk_string_t _x6849 = kk_string_dup(filename); /*string*/
  kk_string_t _x6850;
  kk_define_string_literal(, _s6851, 12, "_tmcmc_9.csv")
  _x6850 = kk_string_dup(_s6851); /*string*/
  _b_6387_6373 = kk_std_core__lp__plus__plus__1_rp_(_x6849, _x6850, _ctx); /*string*/
  kk_std_core__list _b_6388_6374;
  kk_string_t _b_6389_6371;
  kk_string_t _x6852;
  kk_define_string_literal(, _s6853, 13, "_tmcmc_10.csv")
  _x6852 = kk_string_dup(_s6853); /*string*/
  _b_6389_6371 = kk_std_core__lp__plus__plus__1_rp_(filename, _x6852, _ctx); /*string*/
  _b_6388_6374 = kk_std_core__new_Cons(kk_reuse_null, kk_string_box(_b_6389_6371), kk_std_core__new_Nil(_ctx), _ctx); /*list<string>*/
  _b_6386_6376 = kk_std_core__new_Cons(kk_reuse_null, kk_string_box(_b_6387_6373), _b_6388_6374, _ctx); /*list<string>*/
  _b_6384_6378 = kk_std_core__new_Cons(kk_reuse_null, kk_string_box(_b_6385_6375), _b_6386_6376, _ctx); /*list<string>*/
  _b_6382_6380 = kk_std_core__new_Cons(kk_reuse_null, kk_string_box(_b_6383_6377), _b_6384_6378, _ctx); /*list<string>*/
  return kk_std_core__new_Cons(kk_reuse_null, kk_string_box(_b_6381_6379), _b_6382_6380, _ctx);
}
 
// These both ignore the trace of the results.


// lift anonymous function
struct kk_output_dash_and_dash_plot_show_fun6864__t {
  struct kk_function_s _base;
  kk_ref_t loc;
  kk_std_core__list tmcmc__result;
};
static kk_unit_t kk_output_dash_and_dash_plot_show_fun6864(kk_function_t _fself, kk_integer_t i, kk_context_t* _ctx);
static kk_function_t kk_output_dash_and_dash_plot_new_show_fun6864(kk_ref_t loc, kk_std_core__list tmcmc__result, kk_context_t* _ctx) {
  struct kk_output_dash_and_dash_plot_show_fun6864__t* _self = kk_function_alloc_as(struct kk_output_dash_and_dash_plot_show_fun6864__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_output_dash_and_dash_plot_show_fun6864, kk_context());
  _self->loc = loc;
  _self->tmcmc__result = tmcmc__result;
  return &_self->_base;
}

static kk_unit_t kk_output_dash_and_dash_plot_show_fun6864(kk_function_t _fself, kk_integer_t i, kk_context_t* _ctx) {
  struct kk_output_dash_and_dash_plot_show_fun6864__t* _self = kk_function_as(struct kk_output_dash_and_dash_plot_show_fun6864__t*, _fself);
  kk_ref_t loc = _self->loc; /* local-var<global,string> */
  kk_std_core__list tmcmc__result = _self->tmcmc__result; /* list<(list<double>, double)> */
  kk_drop_match(_self, {kk_ref_dup(loc);kk_std_core__list_dup(tmcmc__result);}, {}, _ctx)
  kk_string_t str;
  kk_std_core_types__maybe _match_6763 = kk_std_core__lp__lb__rb__2_rp_(tmcmc__result, i, _ctx); /*maybe<1>*/;
  if (kk_std_core_types__is_Nothing(_match_6763)) {
    str = kk_string_empty(); /*string*/
  }
  else {
    kk_box_t _box_x6396 = _match_6763._cons.Just.value;
    kk_std_core_types__tuple2_ _pat1 = kk_std_core_types__tuple2__unbox(_box_x6396, NULL);
    kk_box_t _box_x6397 = _pat1.fst;
    kk_box_t _box_x6398 = _pat1.snd;
    double a = kk_double_unbox(_box_x6398, NULL);
    str = kk_std_core_show_fixed(a, kk_std_core_types__new_None(_ctx), _ctx); /*string*/
  }
  kk_string_t _b_6403_6401;
  kk_string_t _x6869;
  kk_box_t _x6870;
  kk_ref_t _x6871 = kk_ref_dup(loc); /*local-var<global,string>*/
  _x6870 = (kk_ref_get(_x6871,kk_context())); /*0*/
  _x6869 = kk_string_unbox(_x6870); /*string*/
  kk_string_t _x6872;
  kk_string_t _x6873;
  kk_define_string_literal(, _s6874, 1, "\n")
  _x6873 = kk_string_dup(_s6874); /*string*/
  _x6872 = kk_std_core__lp__plus__plus__1_rp_(str, _x6873, _ctx); /*string*/
  _b_6403_6401 = kk_std_core__lp__plus__plus__1_rp_(_x6869, _x6872, _ctx); /*string*/
  return (kk_ref_set(loc,(kk_string_box(_b_6403_6401)),kk_context()));
}

kk_string_t kk_output_dash_and_dash_plot_show(kk_std_core__list tmcmc__result, kk_context_t* _ctx) { /* (tmcmc_result : list<(list<double>, double)>) -> string */ 
  kk_ref_t loc;
  kk_box_t _x6858;
  kk_string_t _x6859 = kk_string_empty(); /*string*/
  _x6858 = kk_string_box(_x6859); /*0*/
  loc = kk_ref_alloc(_x6858,kk_context()); /*local-var<global,string>*/
  kk_string_t res;
  kk_unit_t __ = kk_Unit;
  kk_integer_t end_6228;
  kk_integer_t _x6861;
  kk_std_core__list _x6862 = kk_std_core__list_dup(tmcmc__result); /*list<(list<double>, double)>*/
  _x6861 = kk_std_core_length_1(_x6862, _ctx); /*int*/
  end_6228 = kk_integer_sub(_x6861,(kk_integer_from_small(1)),kk_context()); /*int*/
  kk_function_t _x6863;
  kk_ref_dup(loc);
  _x6863 = kk_output_dash_and_dash_plot_new_show_fun6864(loc, tmcmc__result, _ctx); /*(i : int) -> (local<global>) ()*/
  kk_std_core__lift21056_for(_x6863, end_6228, kk_integer_from_small(0), _ctx);
  kk_box_t _x6875;
  kk_ref_t _x6876 = kk_ref_dup(loc); /*local-var<global,string>*/
  _x6875 = (kk_ref_get(_x6876,kk_context())); /*0*/
  res = kk_string_unbox(_x6875); /*string*/
  kk_box_t _x6877 = kk_std_core_hnd_prompt_local_var(loc, kk_string_box(res), _ctx); /*2*/
  return kk_string_unbox(_x6877);
}


// lift anonymous function
struct kk_output_dash_and_dash_plot_show_fun6884__t_1 {
  struct kk_function_s _base;
  kk_ref_t loc;
  kk_std_core__list tmcmc__result;
};
static kk_unit_t kk_output_dash_and_dash_plot_show_fun6884_1(kk_function_t _fself, kk_integer_t i, kk_context_t* _ctx);
static kk_function_t kk_output_dash_and_dash_plot_new_show_fun6884_1(kk_ref_t loc, kk_std_core__list tmcmc__result, kk_context_t* _ctx) {
  struct kk_output_dash_and_dash_plot_show_fun6884__t_1* _self = kk_function_alloc_as(struct kk_output_dash_and_dash_plot_show_fun6884__t_1, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_output_dash_and_dash_plot_show_fun6884_1, kk_context());
  _self->loc = loc;
  _self->tmcmc__result = tmcmc__result;
  return &_self->_base;
}

static kk_unit_t kk_output_dash_and_dash_plot_show_fun6884_1(kk_function_t _fself, kk_integer_t i, kk_context_t* _ctx) {
  struct kk_output_dash_and_dash_plot_show_fun6884__t_1* _self = kk_function_as(struct kk_output_dash_and_dash_plot_show_fun6884__t_1*, _fself);
  kk_ref_t loc = _self->loc; /* local-var<global,string> */
  kk_std_core__list tmcmc__result = _self->tmcmc__result; /* list<(list<double>, list<double>)> */
  kk_drop_match(_self, {kk_ref_dup(loc);kk_std_core__list_dup(tmcmc__result);}, {}, _ctx)
  kk_string_t str;
  kk_std_core_types__maybe _match_6762 = kk_std_core__lp__lb__rb__2_rp_(tmcmc__result, i, _ctx); /*maybe<1>*/;
  if (kk_std_core_types__is_Nothing(_match_6762)) {
    str = kk_string_empty(); /*string*/
  }
  else {
    kk_box_t _box_x6413 = _match_6762._cons.Just.value;
    kk_std_core_types__tuple2_ _pat1 = kk_std_core_types__tuple2__unbox(_box_x6413, NULL);
    kk_box_t _box_x6414 = _pat1.fst;
    kk_box_t _box_x6415 = _pat1.snd;
    kk_std_core__list a = kk_std_core__list_unbox(_box_x6415, NULL);
    str = kk_output_dash_and_dash_plot_list__to__csv(a, _ctx); /*string*/
  }
  kk_string_t _b_6420_6418;
  kk_string_t _x6889;
  kk_box_t _x6890;
  kk_ref_t _x6891 = kk_ref_dup(loc); /*local-var<global,string>*/
  _x6890 = (kk_ref_get(_x6891,kk_context())); /*0*/
  _x6889 = kk_string_unbox(_x6890); /*string*/
  _b_6420_6418 = kk_std_core__lp__plus__plus__1_rp_(_x6889, str, _ctx); /*string*/
  return (kk_ref_set(loc,(kk_string_box(_b_6420_6418)),kk_context()));
}

kk_string_t kk_output_dash_and_dash_plot_show_1(kk_std_core__list tmcmc__result, kk_context_t* _ctx) { /* (tmcmc_result : list<(list<double>, list<double>)>) -> string */ 
  kk_ref_t loc;
  kk_box_t _x6878;
  kk_string_t _x6879 = kk_string_empty(); /*string*/
  _x6878 = kk_string_box(_x6879); /*0*/
  loc = kk_ref_alloc(_x6878,kk_context()); /*local-var<global,string>*/
  kk_string_t res;
  kk_unit_t __ = kk_Unit;
  kk_integer_t end_6235;
  kk_integer_t _x6881;
  kk_std_core__list _x6882 = kk_std_core__list_dup(tmcmc__result); /*list<(list<double>, list<double>)>*/
  _x6881 = kk_std_core_length_1(_x6882, _ctx); /*int*/
  end_6235 = kk_integer_sub(_x6881,(kk_integer_from_small(1)),kk_context()); /*int*/
  kk_function_t _x6883;
  kk_ref_dup(loc);
  _x6883 = kk_output_dash_and_dash_plot_new_show_fun6884_1(loc, tmcmc__result, _ctx); /*(i : int) -> (local<global>) ()*/
  kk_std_core__lift21056_for(_x6883, end_6235, kk_integer_from_small(0), _ctx);
  kk_box_t _x6892;
  kk_ref_t _x6893 = kk_ref_dup(loc); /*local-var<global,string>*/
  _x6892 = (kk_ref_get(_x6893,kk_context())); /*0*/
  res = kk_string_unbox(_x6892); /*string*/
  kk_box_t _x6894 = kk_std_core_hnd_prompt_local_var(loc, kk_string_box(res), _ctx); /*2*/
  return kk_string_unbox(_x6894);
}


// lift anonymous function
struct kk_output_dash_and_dash_plot_show_fun6901__t_2 {
  struct kk_function_s _base;
  kk_std_core__list hist;
  kk_ref_t loc;
};
static kk_unit_t kk_output_dash_and_dash_plot_show_fun6901_2(kk_function_t _fself, kk_integer_t i, kk_context_t* _ctx);
static kk_function_t kk_output_dash_and_dash_plot_new_show_fun6901_2(kk_std_core__list hist, kk_ref_t loc, kk_context_t* _ctx) {
  struct kk_output_dash_and_dash_plot_show_fun6901__t_2* _self = kk_function_alloc_as(struct kk_output_dash_and_dash_plot_show_fun6901__t_2, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_output_dash_and_dash_plot_show_fun6901_2, kk_context());
  _self->hist = hist;
  _self->loc = loc;
  return &_self->_base;
}

static kk_unit_t kk_output_dash_and_dash_plot_show_fun6901_2(kk_function_t _fself, kk_integer_t i, kk_context_t* _ctx) {
  struct kk_output_dash_and_dash_plot_show_fun6901__t_2* _self = kk_function_as(struct kk_output_dash_and_dash_plot_show_fun6901__t_2*, _fself);
  kk_std_core__list hist = _self->hist; /* effects-and-types/histogram<double> */
  kk_ref_t loc = _self->loc; /* local-var<global,string> */
  kk_drop_match(_self, {kk_std_core__list_dup(hist);kk_ref_dup(loc);}, {}, _ctx)
  kk_string_t str;
  kk_std_core_types__maybe _match_6761 = kk_std_core__lp__lb__rb__2_rp_(hist, i, _ctx); /*maybe<1>*/;
  if (kk_std_core_types__is_Nothing(_match_6761)) {
    str = kk_string_empty(); /*string*/
  }
  else {
    kk_box_t _box_x6430 = _match_6761._cons.Just.value;
    kk_std_core_types__tuple2_ x = kk_std_core_types__tuple2__unbox(_box_x6430, NULL);
    kk_box_t _box_x6431 = x.fst;
    kk_box_t _box_x6432 = x.snd;
    kk_effects_dash_and_dash_types__exp _pat2 = kk_effects_dash_and_dash_types__exp_unbox(_box_x6431, NULL);
    double a = kk_double_unbox(_box_x6432, NULL);
    double dbl = _pat2.i;
    kk_string_t _x6906;
    kk_std_num_ddouble__ddouble _x6907;
    kk_std_num_ddouble__ddouble _x6908 = kk_std_num_ddouble_ddouble(dbl, _ctx); /*std/num/ddouble/ddouble*/
    _x6907 = kk_std_num_ddouble_exp(_x6908, _ctx); /*std/num/ddouble/ddouble*/
    _x6906 = kk_std_num_ddouble_show_fixed(_x6907, kk_std_core_types__new_None(_ctx), _ctx); /*string*/
    kk_string_t _x6909;
    kk_string_t _x6910;
    kk_define_string_literal(, _s6911, 2, ", ")
    _x6910 = kk_string_dup(_s6911); /*string*/
    kk_string_t _x6912 = kk_std_core_show_fixed(a, kk_std_core_types__new_None(_ctx), _ctx); /*string*/
    _x6909 = kk_std_core__lp__plus__plus__1_rp_(_x6910, _x6912, _ctx); /*string*/
    str = kk_std_core__lp__plus__plus__1_rp_(_x6906, _x6909, _ctx); /*string*/
  }
  kk_string_t _b_6437_6435;
  kk_string_t _x6913;
  kk_box_t _x6914;
  kk_ref_t _x6915 = kk_ref_dup(loc); /*local-var<global,string>*/
  _x6914 = (kk_ref_get(_x6915,kk_context())); /*0*/
  _x6913 = kk_string_unbox(_x6914); /*string*/
  kk_string_t _x6916;
  kk_string_t _x6917;
  kk_define_string_literal(, _s6918, 1, "\n")
  _x6917 = kk_string_dup(_s6918); /*string*/
  _x6916 = kk_std_core__lp__plus__plus__1_rp_(str, _x6917, _ctx); /*string*/
  _b_6437_6435 = kk_std_core__lp__plus__plus__1_rp_(_x6913, _x6916, _ctx); /*string*/
  return (kk_ref_set(loc,(kk_string_box(_b_6437_6435)),kk_context()));
}

kk_string_t kk_output_dash_and_dash_plot_show_2(kk_std_core__list hist, kk_context_t* _ctx) { /* (hist : effects-and-types/histogram<double>) -> string */ 
  kk_ref_t loc;
  kk_box_t _x6895;
  kk_string_t _x6896 = kk_string_empty(); /*string*/
  _x6895 = kk_string_box(_x6896); /*0*/
  loc = kk_ref_alloc(_x6895,kk_context()); /*local-var<global,string>*/
  kk_string_t res;
  kk_unit_t __ = kk_Unit;
  kk_integer_t end_6242;
  kk_integer_t _x6898;
  kk_std_core__list _x6899 = kk_std_core__list_dup(hist); /*effects-and-types/histogram<double>*/
  _x6898 = kk_std_core_length_1(_x6899, _ctx); /*int*/
  end_6242 = kk_integer_sub(_x6898,(kk_integer_from_small(1)),kk_context()); /*int*/
  kk_function_t _x6900;
  kk_ref_dup(loc);
  _x6900 = kk_output_dash_and_dash_plot_new_show_fun6901_2(hist, loc, _ctx); /*(i : int) -> (local<global>) ()*/
  kk_std_core__lift21056_for(_x6900, end_6242, kk_integer_from_small(0), _ctx);
  kk_box_t _x6919;
  kk_ref_t _x6920 = kk_ref_dup(loc); /*local-var<global,string>*/
  _x6919 = (kk_ref_get(_x6920,kk_context())); /*0*/
  res = kk_string_unbox(_x6919); /*string*/
  kk_box_t _x6921 = kk_std_core_hnd_prompt_local_var(loc, kk_string_box(res), _ctx); /*2*/
  return kk_string_unbox(_x6921);
}


// lift anonymous function
struct kk_output_dash_and_dash_plot_show_fun6928__t_3 {
  struct kk_function_s _base;
  kk_std_core__list hist;
  kk_ref_t loc;
};
static kk_unit_t kk_output_dash_and_dash_plot_show_fun6928_3(kk_function_t _fself, kk_integer_t i, kk_context_t* _ctx);
static kk_function_t kk_output_dash_and_dash_plot_new_show_fun6928_3(kk_std_core__list hist, kk_ref_t loc, kk_context_t* _ctx) {
  struct kk_output_dash_and_dash_plot_show_fun6928__t_3* _self = kk_function_alloc_as(struct kk_output_dash_and_dash_plot_show_fun6928__t_3, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_output_dash_and_dash_plot_show_fun6928_3, kk_context());
  _self->hist = hist;
  _self->loc = loc;
  return &_self->_base;
}

static kk_unit_t kk_output_dash_and_dash_plot_show_fun6928_3(kk_function_t _fself, kk_integer_t i, kk_context_t* _ctx) {
  struct kk_output_dash_and_dash_plot_show_fun6928__t_3* _self = kk_function_as(struct kk_output_dash_and_dash_plot_show_fun6928__t_3*, _fself);
  kk_std_core__list hist = _self->hist; /* effects-and-types/histogram<(double, double)> */
  kk_ref_t loc = _self->loc; /* local-var<global,string> */
  kk_drop_match(_self, {kk_std_core__list_dup(hist);kk_ref_dup(loc);}, {}, _ctx)
  kk_string_t str;
  kk_std_core_types__maybe _match_6760 = kk_std_core__lp__lb__rb__2_rp_(hist, i, _ctx); /*maybe<1>*/;
  if (kk_std_core_types__is_Nothing(_match_6760)) {
    str = kk_string_empty(); /*string*/
  }
  else {
    kk_box_t _box_x6447 = _match_6760._cons.Just.value;
    kk_std_core_types__tuple2_ x = kk_std_core_types__tuple2__unbox(_box_x6447, NULL);
    kk_box_t _box_x6448 = x.fst;
    kk_box_t _box_x6449 = x.snd;
    kk_effects_dash_and_dash_types__exp _pat2 = kk_effects_dash_and_dash_types__exp_unbox(_box_x6448, NULL);
    kk_std_core_types__tuple2_ _pat3 = kk_std_core_types__tuple2__unbox(_box_x6449, NULL);
    double dbl = _pat2.i;
    kk_box_t _box_x6450 = _pat3.fst;
    kk_box_t _box_x6451 = _pat3.snd;
    double db1 = kk_double_unbox(_box_x6450, NULL);
    double db2 = kk_double_unbox(_box_x6451, NULL);
    kk_std_core_types__tuple2__drop(x, _ctx);
    kk_string_t _x6935;
    kk_std_num_ddouble__ddouble _x6936;
    kk_std_num_ddouble__ddouble _x6937 = kk_std_num_ddouble_ddouble(dbl, _ctx); /*std/num/ddouble/ddouble*/
    _x6936 = kk_std_num_ddouble_exp(_x6937, _ctx); /*std/num/ddouble/ddouble*/
    _x6935 = kk_std_num_ddouble_show_fixed(_x6936, kk_std_core_types__new_None(_ctx), _ctx); /*string*/
    kk_string_t _x6938;
    kk_string_t _x6939;
    kk_define_string_literal(, _s6940, 2, ", ")
    _x6939 = kk_string_dup(_s6940); /*string*/
    kk_string_t _x6941;
    kk_string_t _x6942 = kk_std_core_show_fixed(db1, kk_std_core_types__new_None(_ctx), _ctx); /*string*/
    kk_string_t _x6943;
    kk_string_t _x6944;
    kk_define_string_literal(, _s6945, 2, ", ")
    _x6944 = kk_string_dup(_s6945); /*string*/
    kk_string_t _x6946 = kk_std_core_show_fixed(db2, kk_std_core_types__new_None(_ctx), _ctx); /*string*/
    _x6943 = kk_std_core__lp__plus__plus__1_rp_(_x6944, _x6946, _ctx); /*string*/
    _x6941 = kk_std_core__lp__plus__plus__1_rp_(_x6942, _x6943, _ctx); /*string*/
    _x6938 = kk_std_core__lp__plus__plus__1_rp_(_x6939, _x6941, _ctx); /*string*/
    str = kk_std_core__lp__plus__plus__1_rp_(_x6935, _x6938, _ctx); /*string*/
  }
  kk_string_t _b_6456_6454;
  kk_string_t _x6947;
  kk_box_t _x6948;
  kk_ref_t _x6949 = kk_ref_dup(loc); /*local-var<global,string>*/
  _x6948 = (kk_ref_get(_x6949,kk_context())); /*0*/
  _x6947 = kk_string_unbox(_x6948); /*string*/
  kk_string_t _x6950;
  kk_string_t _x6951;
  kk_define_string_literal(, _s6952, 1, "\n")
  _x6951 = kk_string_dup(_s6952); /*string*/
  _x6950 = kk_std_core__lp__plus__plus__1_rp_(str, _x6951, _ctx); /*string*/
  _b_6456_6454 = kk_std_core__lp__plus__plus__1_rp_(_x6947, _x6950, _ctx); /*string*/
  return (kk_ref_set(loc,(kk_string_box(_b_6456_6454)),kk_context()));
}

kk_string_t kk_output_dash_and_dash_plot_show_3(kk_std_core__list hist, kk_context_t* _ctx) { /* (hist : effects-and-types/histogram<(double, double)>) -> string */ 
  kk_ref_t loc;
  kk_box_t _x6922;
  kk_string_t _x6923 = kk_string_empty(); /*string*/
  _x6922 = kk_string_box(_x6923); /*0*/
  loc = kk_ref_alloc(_x6922,kk_context()); /*local-var<global,string>*/
  kk_string_t res;
  kk_unit_t __ = kk_Unit;
  kk_integer_t end_6249;
  kk_integer_t _x6925;
  kk_std_core__list _x6926 = kk_std_core__list_dup(hist); /*effects-and-types/histogram<(double, double)>*/
  _x6925 = kk_std_core_length_1(_x6926, _ctx); /*int*/
  end_6249 = kk_integer_sub(_x6925,(kk_integer_from_small(1)),kk_context()); /*int*/
  kk_function_t _x6927;
  kk_ref_dup(loc);
  _x6927 = kk_output_dash_and_dash_plot_new_show_fun6928_3(hist, loc, _ctx); /*(i : int) -> (local<global>) ()*/
  kk_std_core__lift21056_for(_x6927, end_6249, kk_integer_from_small(0), _ctx);
  kk_box_t _x6953;
  kk_ref_t _x6954 = kk_ref_dup(loc); /*local-var<global,string>*/
  _x6953 = (kk_ref_get(_x6954,kk_context())); /*0*/
  res = kk_string_unbox(_x6953); /*string*/
  kk_box_t _x6955 = kk_std_core_hnd_prompt_local_var(loc, kk_string_box(res), _ctx); /*2*/
  return kk_string_unbox(_x6955);
}


// lift anonymous function
struct kk_output_dash_and_dash_plot_show_fun6962__t_4 {
  struct kk_function_s _base;
  kk_std_core__list hist;
  kk_ref_t loc;
};
static kk_unit_t kk_output_dash_and_dash_plot_show_fun6962_4(kk_function_t _fself, kk_integer_t i, kk_context_t* _ctx);
static kk_function_t kk_output_dash_and_dash_plot_new_show_fun6962_4(kk_std_core__list hist, kk_ref_t loc, kk_context_t* _ctx) {
  struct kk_output_dash_and_dash_plot_show_fun6962__t_4* _self = kk_function_alloc_as(struct kk_output_dash_and_dash_plot_show_fun6962__t_4, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_output_dash_and_dash_plot_show_fun6962_4, kk_context());
  _self->hist = hist;
  _self->loc = loc;
  return &_self->_base;
}



// lift anonymous function
struct kk_output_dash_and_dash_plot_show_fun6975__t_4 {
  struct kk_function_s _base;
  kk_ref_t loc;
  kk_std_core__list lst;
};
static kk_unit_t kk_output_dash_and_dash_plot_show_fun6975_4(kk_function_t _fself, kk_integer_t j, kk_context_t* _ctx);
static kk_function_t kk_output_dash_and_dash_plot_new_show_fun6975_4(kk_ref_t loc, kk_std_core__list lst, kk_context_t* _ctx) {
  struct kk_output_dash_and_dash_plot_show_fun6975__t_4* _self = kk_function_alloc_as(struct kk_output_dash_and_dash_plot_show_fun6975__t_4, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_output_dash_and_dash_plot_show_fun6975_4, kk_context());
  _self->loc = loc;
  _self->lst = lst;
  return &_self->_base;
}

static kk_unit_t kk_output_dash_and_dash_plot_show_fun6975_4(kk_function_t _fself, kk_integer_t j, kk_context_t* _ctx) {
  struct kk_output_dash_and_dash_plot_show_fun6975__t_4* _self = kk_function_as(struct kk_output_dash_and_dash_plot_show_fun6975__t_4*, _fself);
  kk_ref_t loc = _self->loc; /* local-var<global,string> */
  kk_std_core__list lst = _self->lst; /* list<double> */
  kk_drop_match(_self, {kk_ref_dup(loc);kk_std_core__list_dup(lst);}, {}, _ctx)
  kk_string_t str;
  kk_std_core_types__maybe _match_6759 = kk_std_core__lp__lb__rb__2_rp_(lst, j, _ctx); /*maybe<1>*/;
  if (kk_std_core_types__is_Nothing(_match_6759)) {
    str = kk_string_empty(); /*string*/
  }
  else {
    kk_box_t _box_x6472 = _match_6759._cons.Just.value;
    double u = kk_double_unbox(_box_x6472, NULL);
    kk_string_t _x6978 = kk_std_core_show_fixed(u, kk_std_core_types__new_None(_ctx), _ctx); /*string*/
    kk_string_t _x6979;
    kk_define_string_literal(, _s6980, 1, ",")
    _x6979 = kk_string_dup(_s6980); /*string*/
    str = kk_std_core__lp__plus__plus__1_rp_(_x6978, _x6979, _ctx); /*string*/
  }
  kk_string_t _b_6477_6475;
  kk_string_t _x6981;
  kk_box_t _x6982;
  kk_ref_t _x6983 = kk_ref_dup(loc); /*local-var<global,string>*/
  _x6982 = (kk_ref_get(_x6983,kk_context())); /*0*/
  _x6981 = kk_string_unbox(_x6982); /*string*/
  _b_6477_6475 = kk_std_core__lp__plus__plus__1_rp_(_x6981, str, _ctx); /*string*/
  return (kk_ref_set(loc,(kk_string_box(_b_6477_6475)),kk_context()));
}
static kk_unit_t kk_output_dash_and_dash_plot_show_fun6962_4(kk_function_t _fself, kk_integer_t i, kk_context_t* _ctx) {
  struct kk_output_dash_and_dash_plot_show_fun6962__t_4* _self = kk_function_as(struct kk_output_dash_and_dash_plot_show_fun6962__t_4*, _fself);
  kk_std_core__list hist = _self->hist; /* effects-and-types/histogram<list<double>> */
  kk_ref_t loc = _self->loc; /* local-var<global,string> */
  kk_drop_match(_self, {kk_std_core__list_dup(hist);kk_ref_dup(loc);}, {}, _ctx)
  kk_unit_t __0 = kk_Unit;
  kk_std_core_types__maybe _match_6757 = kk_std_core__lp__lb__rb__2_rp_(hist, i, _ctx); /*maybe<1>*/;
  if (kk_std_core_types__is_Nothing(_match_6757)) {
    kk_string_t _b_6484_6468;
    kk_string_t _x6963;
    kk_box_t _x6964;
    kk_ref_t _x6965 = kk_ref_dup(loc); /*local-var<global,string>*/
    _x6964 = (kk_ref_get(_x6965,kk_context())); /*0*/
    _x6963 = kk_string_unbox(_x6964); /*string*/
    kk_string_t _x6966 = kk_string_empty(); /*string*/
    _b_6484_6468 = kk_std_core__lp__plus__plus__1_rp_(_x6963, _x6966, _ctx); /*string*/
    kk_ref_t _x6968 = kk_ref_dup(loc); /*local-var<global,string>*/
    (kk_ref_set(_x6968,(kk_string_box(_b_6484_6468)),kk_context()));
  }
  else {
    kk_box_t _box_x6469 = _match_6757._cons.Just.value;
    kk_std_core_types__tuple2_ x = kk_std_core_types__tuple2__unbox(_box_x6469, NULL);
    kk_box_t _box_x6470 = x.fst;
    kk_box_t _box_x6471 = x.snd;
    kk_effects_dash_and_dash_types__exp _pat2 = kk_effects_dash_and_dash_types__exp_unbox(_box_x6470, NULL);
    kk_std_core__list lst = kk_std_core__list_unbox(_box_x6471, NULL);
    kk_std_core__list_dup(lst);
    kk_std_core_types__tuple2__drop(x, _ctx);
    kk_unit_t __ = kk_Unit;
    kk_integer_t end0_6259;
    kk_integer_t _x6972;
    kk_std_core__list _x6973 = kk_std_core__list_dup(lst); /*list<double>*/
    _x6972 = kk_std_core_length_1(_x6973, _ctx); /*int*/
    end0_6259 = kk_integer_sub(_x6972,(kk_integer_from_small(2)),kk_context()); /*int*/
    kk_function_t _x6974;
    kk_ref_dup(loc);
    kk_std_core__list_dup(lst);
    _x6974 = kk_output_dash_and_dash_plot_new_show_fun6975_4(loc, lst, _ctx); /*(j : int) -> (local<global>) ()*/
    kk_std_core__lift21056_for(_x6974, end0_6259, kk_integer_from_small(0), _ctx);
    kk_string_t str0;
    kk_std_core_types__maybe _match_6758;
    kk_std_core__list _x6984 = kk_std_core__list_dup(lst); /*list<double>*/
    kk_integer_t _x6985;
    kk_integer_t _x6986 = kk_std_core_length_1(lst, _ctx); /*int*/
    _x6985 = kk_integer_sub(_x6986,(kk_integer_from_small(1)),kk_context()); /*int*/
    _match_6758 = kk_std_core__lp__lb__rb__2_rp_(_x6984, _x6985, _ctx); /*maybe<1>*/
    if (kk_std_core_types__is_Nothing(_match_6758)) {
      str0 = kk_string_empty(); /*string*/
    }
    else {
      kk_box_t _box_x6479 = _match_6758._cons.Just.value;
      double u0 = kk_double_unbox(_box_x6479, NULL);
      str0 = kk_std_core_show_fixed(u0, kk_std_core_types__new_None(_ctx), _ctx); /*string*/
    }
    kk_string_t _b_6487_6482;
    kk_string_t _x6989;
    kk_box_t _x6990;
    kk_ref_t _x6991 = kk_ref_dup(loc); /*local-var<global,string>*/
    _x6990 = (kk_ref_get(_x6991,kk_context())); /*0*/
    _x6989 = kk_string_unbox(_x6990); /*string*/
    _b_6487_6482 = kk_std_core__lp__plus__plus__1_rp_(_x6989, str0, _ctx); /*string*/
    kk_ref_t _x6992 = kk_ref_dup(loc); /*local-var<global,string>*/
    (kk_ref_set(_x6992,(kk_string_box(_b_6487_6482)),kk_context()));
  }
  kk_string_t _b_6493_6491;
  kk_string_t _x6993;
  kk_box_t _x6994;
  kk_ref_t _x6995 = kk_ref_dup(loc); /*local-var<global,string>*/
  _x6994 = (kk_ref_get(_x6995,kk_context())); /*0*/
  _x6993 = kk_string_unbox(_x6994); /*string*/
  kk_string_t _x6996;
  kk_define_string_literal(, _s6997, 1, "\n")
  _x6996 = kk_string_dup(_s6997); /*string*/
  _b_6493_6491 = kk_std_core__lp__plus__plus__1_rp_(_x6993, _x6996, _ctx); /*string*/
  return (kk_ref_set(loc,(kk_string_box(_b_6493_6491)),kk_context()));
}

kk_string_t kk_output_dash_and_dash_plot_show_4(kk_std_core__list hist, kk_context_t* _ctx) { /* (hist : effects-and-types/histogram<list<double>>) -> string */ 
  kk_ref_t loc;
  kk_box_t _x6956;
  kk_string_t _x6957 = kk_string_empty(); /*string*/
  _x6956 = kk_string_box(_x6957); /*0*/
  loc = kk_ref_alloc(_x6956,kk_context()); /*local-var<global,string>*/
  kk_string_t res;
  kk_unit_t __1 = kk_Unit;
  kk_integer_t end_6256;
  kk_integer_t _x6959;
  kk_std_core__list _x6960 = kk_std_core__list_dup(hist); /*effects-and-types/histogram<list<double>>*/
  _x6959 = kk_std_core_length_1(_x6960, _ctx); /*int*/
  end_6256 = kk_integer_sub(_x6959,(kk_integer_from_small(1)),kk_context()); /*int*/
  kk_function_t _x6961;
  kk_ref_dup(loc);
  _x6961 = kk_output_dash_and_dash_plot_new_show_fun6962_4(hist, loc, _ctx); /*(i : int) -> (local<global>) ()*/
  kk_std_core__lift21056_for(_x6961, end_6256, kk_integer_from_small(0), _ctx);
  kk_box_t _x6998;
  kk_ref_t _x6999 = kk_ref_dup(loc); /*local-var<global,string>*/
  _x6998 = (kk_ref_get(_x6999,kk_context())); /*0*/
  res = kk_string_unbox(_x6998); /*string*/
  kk_box_t _x7000 = kk_std_core_hnd_prompt_local_var(loc, kk_string_box(res), _ctx); /*2*/
  return kk_string_unbox(_x7000);
}


// lift anonymous function
struct kk_output_dash_and_dash_plot_show_fun7011__t_6 {
  struct kk_function_s _base;
  kk_ref_t loc;
  kk_std_core__list xs;
};
static kk_unit_t kk_output_dash_and_dash_plot_show_fun7011_6(kk_function_t _fself, kk_integer_t i, kk_context_t* _ctx);
static kk_function_t kk_output_dash_and_dash_plot_new_show_fun7011_6(kk_ref_t loc, kk_std_core__list xs, kk_context_t* _ctx) {
  struct kk_output_dash_and_dash_plot_show_fun7011__t_6* _self = kk_function_alloc_as(struct kk_output_dash_and_dash_plot_show_fun7011__t_6, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_output_dash_and_dash_plot_show_fun7011_6, kk_context());
  _self->loc = loc;
  _self->xs = xs;
  return &_self->_base;
}

static kk_unit_t kk_output_dash_and_dash_plot_show_fun7011_6(kk_function_t _fself, kk_integer_t i, kk_context_t* _ctx) {
  struct kk_output_dash_and_dash_plot_show_fun7011__t_6* _self = kk_function_as(struct kk_output_dash_and_dash_plot_show_fun7011__t_6*, _fself);
  kk_ref_t loc = _self->loc; /* local-var<global,string> */
  kk_std_core__list xs = _self->xs; /* list<double> */
  kk_drop_match(_self, {kk_ref_dup(loc);kk_std_core__list_dup(xs);}, {}, _ctx)
  bool _match_6754;
  kk_integer_t _x7012 = kk_integer_dup(i); /*int*/
  kk_integer_t _x7013;
  kk_integer_t _x7014;
  kk_std_core__list _x7015 = kk_std_core__list_dup(xs); /*list<double>*/
  _x7014 = kk_std_core_length_1(_x7015, _ctx); /*int*/
  _x7013 = kk_integer_sub(_x7014,(kk_integer_from_small(1)),kk_context()); /*int*/
  _match_6754 = kk_integer_lt(_x7012,_x7013,kk_context()); /*bool*/
  if (_match_6754) {
    kk_string_t str;
    kk_std_core_types__maybe _match_6756 = kk_std_core__lp__lb__rb__2_rp_(xs, i, _ctx); /*maybe<1>*/;
    if (kk_std_core_types__is_Nothing(_match_6756)) {
      str = kk_string_empty(); /*string*/
    }
    else {
      kk_box_t _box_x6505 = _match_6756._cons.Just.value;
      double x = kk_double_unbox(_box_x6505, NULL);
      kk_string_t _x7018 = kk_std_core_show_fixed(x, kk_std_core_types__new_None(_ctx), _ctx); /*string*/
      kk_string_t _x7019;
      kk_define_string_literal(, _s7020, 1, ",")
      _x7019 = kk_string_dup(_s7020); /*string*/
      str = kk_std_core__lp__plus__plus__1_rp_(_x7018, _x7019, _ctx); /*string*/
    }
    kk_string_t _b_6514_6508;
    kk_string_t _x7021;
    kk_box_t _x7022;
    kk_ref_t _x7023 = kk_ref_dup(loc); /*local-var<global,string>*/
    _x7022 = (kk_ref_get(_x7023,kk_context())); /*0*/
    _x7021 = kk_string_unbox(_x7022); /*string*/
    _b_6514_6508 = kk_std_core__lp__plus__plus__1_rp_(_x7021, str, _ctx); /*string*/
    return (kk_ref_set(loc,(kk_string_box(_b_6514_6508)),kk_context()));
  }
  kk_string_t str0;
  kk_std_core_types__maybe _match_6755 = kk_std_core__lp__lb__rb__2_rp_(xs, i, _ctx); /*maybe<1>*/;
  if (kk_std_core_types__is_Nothing(_match_6755)) {
    str0 = kk_string_empty(); /*string*/
  }
  else {
    kk_box_t _box_x6509 = _match_6755._cons.Just.value;
    double x0 = kk_double_unbox(_box_x6509, NULL);
    str0 = kk_std_core_show_fixed(x0, kk_std_core_types__new_None(_ctx), _ctx); /*string*/
  }
  kk_string_t _b_6517_6512;
  kk_string_t _x7026;
  kk_box_t _x7027;
  kk_ref_t _x7028 = kk_ref_dup(loc); /*local-var<global,string>*/
  _x7027 = (kk_ref_get(_x7028,kk_context())); /*0*/
  _x7026 = kk_string_unbox(_x7027); /*string*/
  _b_6517_6512 = kk_std_core__lp__plus__plus__1_rp_(_x7026, str0, _ctx); /*string*/
  return (kk_ref_set(loc,(kk_string_box(_b_6517_6512)),kk_context()));
}

kk_string_t kk_output_dash_and_dash_plot_show_6(kk_std_core__list xs, kk_context_t* _ctx) { /* (xs : list<double>) -> string */ 
  kk_ref_t loc;
  kk_box_t _x7005;
  kk_string_t _x7006;
  kk_define_string_literal(, _s7007, 1, "[")
  _x7006 = kk_string_dup(_s7007); /*string*/
  _x7005 = kk_string_box(_x7006); /*0*/
  loc = kk_ref_alloc(_x7005,kk_context()); /*local-var<global,string>*/
  kk_string_t res;
  kk_unit_t __ = kk_Unit;
  kk_integer_t end_6266;
  kk_integer_t _x7008;
  kk_std_core__list _x7009 = kk_std_core__list_dup(xs); /*list<double>*/
  _x7008 = kk_std_core_length_1(_x7009, _ctx); /*int*/
  end_6266 = kk_integer_sub(_x7008,(kk_integer_from_small(1)),kk_context()); /*int*/
  kk_function_t _x7010;
  kk_ref_dup(loc);
  _x7010 = kk_output_dash_and_dash_plot_new_show_fun7011_6(loc, xs, _ctx); /*(i : int) -> (local<global>) ()*/
  kk_std_core__lift21056_for(_x7010, end_6266, kk_integer_from_small(0), _ctx);
  kk_unit_t __0 = kk_Unit;
  kk_string_t _b_6523_6521;
  kk_string_t _x7029;
  kk_box_t _x7030;
  kk_ref_t _x7031 = kk_ref_dup(loc); /*local-var<global,string>*/
  _x7030 = (kk_ref_get(_x7031,kk_context())); /*0*/
  _x7029 = kk_string_unbox(_x7030); /*string*/
  kk_string_t _x7032;
  kk_define_string_literal(, _s7033, 1, "]")
  _x7032 = kk_string_dup(_s7033); /*string*/
  _b_6523_6521 = kk_std_core__lp__plus__plus__1_rp_(_x7029, _x7032, _ctx); /*string*/
  kk_ref_t _x7034 = kk_ref_dup(loc); /*local-var<global,string>*/
  (kk_ref_set(_x7034,(kk_string_box(_b_6523_6521)),kk_context()));
  kk_box_t _x7035;
  kk_ref_t _x7036 = kk_ref_dup(loc); /*local-var<global,string>*/
  _x7035 = (kk_ref_get(_x7036,kk_context())); /*0*/
  res = kk_string_unbox(_x7035); /*string*/
  kk_box_t _x7037 = kk_std_core_hnd_prompt_local_var(loc, kk_string_box(res), _ctx); /*2*/
  return kk_string_unbox(_x7037);
}


// lift anonymous function
struct kk_output_dash_and_dash_plot_show_fun7038__t_7 {
  struct kk_function_s _base;
};
static kk_box_t kk_output_dash_and_dash_plot_show_fun7038_7(kk_function_t _fself, kk_box_t _b_6533, kk_context_t* _ctx);
static kk_function_t kk_output_dash_and_dash_plot_new_show_fun7038_7(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_output_dash_and_dash_plot_show_fun7038_7, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_output_dash_and_dash_plot_show_fun7038_7(kk_function_t _fself, kk_box_t _b_6533, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x7039;
  kk_std_core__list _x7040 = kk_std_core__list_unbox(_b_6533, _ctx); /*list<double>*/
  _x7039 = kk_output_dash_and_dash_plot_show_6(_x7040, _ctx); /*string*/
  return kk_string_box(_x7039);
}

kk_string_t kk_output_dash_and_dash_plot_show_7(kk_std_core__list x, kk_context_t* _ctx) { /* (x : list<list<double>>) -> string */ 
  kk_std_core__list xs_6268 = kk_std_core_map_5(x, kk_output_dash_and_dash_plot_new_show_fun7038_7(_ctx), _ctx); /*list<string>*/;
  if (kk_std_core__is_Nil(xs_6268)) {
    return kk_string_empty();
  }
  struct kk_std_core_Cons* _con7042 = kk_std_core__as_Cons(xs_6268);
  kk_box_t _box_x6536 = _con7042->head;
  kk_std_core__list xx = _con7042->tail;
  kk_string_t x0 = kk_string_unbox(_box_x6536);
  if (kk_std_core__list_is_unique(xs_6268)) {
    kk_std_core__list_free(xs_6268);
  }
  else {
    kk_string_dup(x0);
    kk_std_core__list_dup(xx);
    kk_std_core__list_decref(xs_6268, _ctx);
  }
  kk_string_t _x7044 = kk_string_empty(); /*string*/
  return kk_std_core__lift21050_joinsep(_x7044, xx, x0, _ctx);
}


// lift anonymous function
struct kk_output_dash_and_dash_plot_show_fun7046__t_8 {
  struct kk_function_s _base;
};
static kk_box_t kk_output_dash_and_dash_plot_show_fun7046_8(kk_function_t _fself, kk_box_t _b_6539, kk_context_t* _ctx);
static kk_function_t kk_output_dash_and_dash_plot_new_show_fun7046_8(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_output_dash_and_dash_plot_show_fun7046_8, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_output_dash_and_dash_plot_show_fun7046_8(kk_function_t _fself, kk_box_t _b_6539, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x7047;
  kk_std_core__list _x7048 = kk_std_core__list_unbox(_b_6539, _ctx); /*list<list<double>>*/
  _x7047 = kk_output_dash_and_dash_plot_show_7(_x7048, _ctx); /*string*/
  return kk_string_box(_x7047);
}

kk_string_t kk_output_dash_and_dash_plot_show_8(kk_std_core__list x, kk_context_t* _ctx) { /* (x : list<list<list<double>>>) -> string */ 
  kk_std_core__list xs_6269 = kk_std_core_map_5(x, kk_output_dash_and_dash_plot_new_show_fun7046_8(_ctx), _ctx); /*list<string>*/;
  if (kk_std_core__is_Nil(xs_6269)) {
    return kk_string_empty();
  }
  struct kk_std_core_Cons* _con7050 = kk_std_core__as_Cons(xs_6269);
  kk_box_t _box_x6542 = _con7050->head;
  kk_std_core__list xx = _con7050->tail;
  kk_string_t x0 = kk_string_unbox(_box_x6542);
  if (kk_std_core__list_is_unique(xs_6269)) {
    kk_std_core__list_free(xs_6269);
  }
  else {
    kk_string_dup(x0);
    kk_std_core__list_dup(xx);
    kk_std_core__list_decref(xs_6269, _ctx);
  }
  kk_string_t _x7052 = kk_string_empty(); /*string*/
  return kk_std_core__lift21050_joinsep(_x7052, xx, x0, _ctx);
}


// lift anonymous function
struct kk_output_dash_and_dash_plot_show_fun7056__t_9 {
  struct kk_function_s _base;
  kk_std_core__list hist;
};
static kk_unit_t kk_output_dash_and_dash_plot_show_fun7056_9(kk_function_t _fself, kk_integer_t i, kk_context_t* _ctx);
static kk_function_t kk_output_dash_and_dash_plot_new_show_fun7056_9(kk_std_core__list hist, kk_context_t* _ctx) {
  struct kk_output_dash_and_dash_plot_show_fun7056__t_9* _self = kk_function_alloc_as(struct kk_output_dash_and_dash_plot_show_fun7056__t_9, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_output_dash_and_dash_plot_show_fun7056_9, kk_context());
  _self->hist = hist;
  return &_self->_base;
}

static kk_unit_t kk_output_dash_and_dash_plot_show_fun7056_9(kk_function_t _fself, kk_integer_t i, kk_context_t* _ctx) {
  struct kk_output_dash_and_dash_plot_show_fun7056__t_9* _self = kk_function_as(struct kk_output_dash_and_dash_plot_show_fun7056__t_9*, _fself);
  kk_std_core__list hist = _self->hist; /* effects-and-types/histogram<(double) -> double> */
  kk_drop_match(_self, {kk_std_core__list_dup(hist);}, {}, _ctx)
  kk_string_t str;
  kk_std_core_types__maybe _match_6753 = kk_std_core__lp__lb__rb__2_rp_(hist, i, _ctx); /*maybe<1>*/;
  if (kk_std_core_types__is_Nothing(_match_6753)) {
    str = kk_string_empty(); /*string*/
  }
  else {
    kk_box_t _box_x6543 = _match_6753._cons.Just.value;
    kk_std_core_types__tuple2_ x = kk_std_core_types__tuple2__unbox(_box_x6543, NULL);
    kk_box_t _box_x6544 = x.fst;
    kk_box_t _fun_unbox_x6548 = x.snd;
    kk_effects_dash_and_dash_types__exp _pat2 = kk_effects_dash_and_dash_types__exp_unbox(_box_x6544, NULL);
    double dbl = _pat2.i;
    kk_string_t _x7060;
    kk_define_string_literal(, _s7061, 1, "(")
    _x7060 = kk_string_dup(_s7061); /*string*/
    kk_string_t _x7062;
    kk_string_t _x7063;
    kk_std_num_ddouble__ddouble _x7064;
    kk_std_num_ddouble__ddouble _x7065 = kk_std_num_ddouble_ddouble(dbl, _ctx); /*std/num/ddouble/ddouble*/
    _x7064 = kk_std_num_ddouble_exp(_x7065, _ctx); /*std/num/ddouble/ddouble*/
    _x7063 = kk_std_num_ddouble_show_fixed(_x7064, kk_std_core_types__new_None(_ctx), _ctx); /*string*/
    kk_string_t _x7066;
    kk_string_t _x7067;
    kk_define_string_literal(, _s7068, 2, ", ")
    _x7067 = kk_string_dup(_s7068); /*string*/
    kk_string_t _x7069;
    kk_string_t _x7070;
    double _x7071;
    kk_box_t _x7072;
    kk_function_t _x7073 = kk_function_unbox(_fun_unbox_x6548); /*(6549) -> 6550*/
    _x7072 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x7073, (_x7073, kk_double_box(0x1.9p6, _ctx), _ctx)); /*6550*/
    _x7071 = kk_double_unbox(_x7072, _ctx); /*double*/
    _x7070 = kk_std_core_show_fixed(_x7071, kk_std_core_types__new_None(_ctx), _ctx); /*string*/
    kk_string_t _x7074;
    kk_define_string_literal(, _s7075, 1, ")")
    _x7074 = kk_string_dup(_s7075); /*string*/
    _x7069 = kk_std_core__lp__plus__plus__1_rp_(_x7070, _x7074, _ctx); /*string*/
    _x7066 = kk_std_core__lp__plus__plus__1_rp_(_x7067, _x7069, _ctx); /*string*/
    _x7062 = kk_std_core__lp__plus__plus__1_rp_(_x7063, _x7066, _ctx); /*string*/
    str = kk_std_core__lp__plus__plus__1_rp_(_x7060, _x7062, _ctx); /*string*/
  }
  return kk_std_core_println(str, _ctx);
}

kk_integer_t kk_output_dash_and_dash_plot_show_9(kk_std_core__list hist, kk_context_t* _ctx) { /* (hist : effects-and-types/histogram<(double) -> double>) -> console int */ 
  kk_unit_t __ = kk_Unit;
  kk_integer_t end_6271;
  kk_integer_t _x7054;
  kk_std_core__list _x7055 = kk_std_core__list_dup(hist); /*effects-and-types/histogram<(double) -> double>*/
  _x7054 = kk_std_core_length_1(_x7055, _ctx); /*int*/
  end_6271 = kk_integer_sub(_x7054,(kk_integer_from_small(1)),kk_context()); /*int*/
  kk_std_core__lift21056_for(kk_output_dash_and_dash_plot_new_show_fun7056_9(hist, _ctx), end_6271, kk_integer_from_small(0), _ctx);
  return kk_integer_from_small(0);
}


// lift anonymous function
struct kk_output_dash_and_dash_plot_plot_fun7078__t {
  struct kk_function_s _base;
  kk_function_t f;
  double stp;
};
static kk_box_t kk_output_dash_and_dash_plot_plot_fun7078(kk_function_t _fself, kk_integer_t _b_6559, kk_context_t* _ctx);
static kk_function_t kk_output_dash_and_dash_plot_new_plot_fun7078(kk_function_t f, double stp, kk_context_t* _ctx) {
  struct kk_output_dash_and_dash_plot_plot_fun7078__t* _self = kk_function_alloc_as(struct kk_output_dash_and_dash_plot_plot_fun7078__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_output_dash_and_dash_plot_plot_fun7078, kk_context());
  _self->f = f;
  _self->stp = stp;
  return &_self->_base;
}

static kk_box_t kk_output_dash_and_dash_plot_plot_fun7078(kk_function_t _fself, kk_integer_t _b_6559, kk_context_t* _ctx) {
  struct kk_output_dash_and_dash_plot_plot_fun7078__t* _self = kk_function_as(struct kk_output_dash_and_dash_plot_plot_fun7078__t*, _fself);
  kk_function_t f = _self->f; /* (double) -> double */
  double stp = _self->stp; /* double */
  kk_drop_match(_self, {kk_function_dup(f);;}, {}, _ctx)
  kk_string_t _x7079;
  double x0;
  double _x7080;
  double _x7081 = kk_integer_as_double(_b_6559,kk_context()); /*double*/
  _x7080 = (stp * _x7081); /*double*/
  x0 = ((0x0p+0) + _x7080); /*double*/
  double y = kk_function_call(double, (kk_function_t, double, kk_context_t*), f, (f, x0, _ctx)); /*double*/;
  kk_string_t _x7082;
  kk_define_string_literal(, _s7083, 1, "[")
  _x7082 = kk_string_dup(_s7083); /*string*/
  kk_string_t _x7084;
  kk_string_t _x7085;
  kk_std_core_types__optional _x7086 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(6)), _ctx); /*optional<35>*/
  _x7085 = kk_std_core_show_1(x0, _x7086, _ctx); /*string*/
  kk_string_t _x7087;
  kk_string_t _x7088;
  kk_define_string_literal(, _s7089, 1, ",")
  _x7088 = kk_string_dup(_s7089); /*string*/
  kk_string_t _x7090;
  kk_string_t _x7091;
  kk_std_core_types__optional _x7092 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(6)), _ctx); /*optional<35>*/
  _x7091 = kk_std_core_show_1(y, _x7092, _ctx); /*string*/
  kk_string_t _x7093;
  kk_define_string_literal(, _s7094, 1, "]")
  _x7093 = kk_string_dup(_s7094); /*string*/
  _x7090 = kk_std_core__lp__plus__plus__1_rp_(_x7091, _x7093, _ctx); /*string*/
  _x7087 = kk_std_core__lp__plus__plus__1_rp_(_x7088, _x7090, _ctx); /*string*/
  _x7084 = kk_std_core__lp__plus__plus__1_rp_(_x7085, _x7087, _ctx); /*string*/
  _x7079 = kk_std_core__lp__plus__plus__1_rp_(_x7082, _x7084, _ctx); /*string*/
  return kk_string_box(_x7079);
}


// lift anonymous function
struct kk_output_dash_and_dash_plot_plot_fun7096__t {
  struct kk_function_s _base;
};
static kk_box_t kk_output_dash_and_dash_plot_plot_fun7096(kk_function_t _fself, kk_box_t _b_6568, kk_context_t* _ctx);
static kk_function_t kk_output_dash_and_dash_plot_new_plot_fun7096(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_output_dash_and_dash_plot_plot_fun7096, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_output_dash_and_dash_plot_plot_fun7096(kk_function_t _fself, kk_box_t _b_6568, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x7097;
  kk_std_core__list _x7098 = kk_std_core__list_unbox(_b_6568, _ctx); /*list<string>*/
  _x7097 = kk_output_dash_and_dash_plot__mlift6203_list_join(_x7098, _ctx); /*string*/
  return kk_string_box(_x7097);
}

kk_string_t kk_output_dash_and_dash_plot_plot(kk_function_t f, kk_context_t* _ctx) { /* (f : (double) -> double) -> string */ 
  double stp;
  double _x7076 = (0x1p2 - (0x0p+0)); /*double*/
  double _x7077 = kk_integer_as_double((kk_integer_from_small(100)),kk_context()); /*double*/
  stp = (_x7076 / _x7077); /*double*/
  kk_std_core__list x_6275 = kk_std_core__lift21054_list_1(kk_output_dash_and_dash_plot_new_plot_fun7078(f, stp, _ctx), kk_integer_from_small(1), kk_integer_from_small(100), kk_std_core__new_Nil(_ctx), _ctx); /*list<string>*/;
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_6275, _ctx);
    kk_box_t _x7095 = kk_std_core_hnd_yield_extend(kk_output_dash_and_dash_plot_new_plot_fun7096(_ctx), _ctx); /*2*/
    return kk_string_unbox(_x7095);
  }
  kk_string_t _x7099;
  kk_define_string_literal(, _s7100, 1, "[")
  _x7099 = kk_string_dup(_s7100); /*string*/
  kk_string_t _x7101;
  kk_string_t _x7102;
  if (kk_std_core__is_Nil(x_6275)) {
    _x7102 = kk_string_empty(); /*string*/
  }
  else {
    struct kk_std_core_Cons* _con7104 = kk_std_core__as_Cons(x_6275);
    kk_box_t _box_x6569 = _con7104->head;
    kk_std_core__list xx = _con7104->tail;
    kk_string_t x = kk_string_unbox(_box_x6569);
    if (kk_std_core__list_is_unique(x_6275)) {
      kk_std_core__list_free(x_6275);
    }
    else {
      kk_string_dup(x);
      kk_std_core__list_dup(xx);
      kk_std_core__list_decref(x_6275, _ctx);
    }
    kk_string_t _x7106;
    kk_define_string_literal(, _s7107, 1, ",")
    _x7106 = kk_string_dup(_s7107); /*string*/
    _x7102 = kk_std_core__lift21050_joinsep(_x7106, xx, x, _ctx); /*string*/
  }
  kk_string_t _x7108;
  kk_define_string_literal(, _s7109, 1, "]")
  _x7108 = kk_string_dup(_s7109); /*string*/
  _x7101 = kk_std_core__lp__plus__plus__1_rp_(_x7102, _x7108, _ctx); /*string*/
  return kk_std_core__lp__plus__plus__1_rp_(_x7099, _x7101, _ctx);
}
extern double kk_output_dash_and_dash_plot_example_plot_fun7110(kk_function_t _fself, double x, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return (0x1p1 * x);
}


// lift anonymous function
struct kk_output_dash_and_dash_plot_showspecial_fun7117__t {
  struct kk_function_s _base;
  kk_ref_t loc;
  kk_std_core__list tmcmc__result;
};
static kk_unit_t kk_output_dash_and_dash_plot_showspecial_fun7117(kk_function_t _fself, kk_integer_t i, kk_context_t* _ctx);
static kk_function_t kk_output_dash_and_dash_plot_new_showspecial_fun7117(kk_ref_t loc, kk_std_core__list tmcmc__result, kk_context_t* _ctx) {
  struct kk_output_dash_and_dash_plot_showspecial_fun7117__t* _self = kk_function_alloc_as(struct kk_output_dash_and_dash_plot_showspecial_fun7117__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_output_dash_and_dash_plot_showspecial_fun7117, kk_context());
  _self->loc = loc;
  _self->tmcmc__result = tmcmc__result;
  return &_self->_base;
}

static kk_unit_t kk_output_dash_and_dash_plot_showspecial_fun7117(kk_function_t _fself, kk_integer_t i, kk_context_t* _ctx) {
  struct kk_output_dash_and_dash_plot_showspecial_fun7117__t* _self = kk_function_as(struct kk_output_dash_and_dash_plot_showspecial_fun7117__t*, _fself);
  kk_ref_t loc = _self->loc; /* local-var<global,string> */
  kk_std_core__list tmcmc__result = _self->tmcmc__result; /* list<(list<double>, list<double>)> */
  kk_drop_match(_self, {kk_ref_dup(loc);kk_std_core__list_dup(tmcmc__result);}, {}, _ctx)
  kk_string_t str;
  kk_std_core_types__maybe _match_6751 = kk_std_core__lp__lb__rb__2_rp_(tmcmc__result, i, _ctx); /*maybe<1>*/;
  if (kk_std_core_types__is_Nothing(_match_6751)) {
    kk_define_string_literal(, _s7118, 5, "EMPTY")
    str = kk_string_dup(_s7118); /*string*/
  }
  else {
    kk_box_t _box_x6574 = _match_6751._cons.Just.value;
    kk_std_core_types__tuple2_ _pat1 = kk_std_core_types__tuple2__unbox(_box_x6574, NULL);
    kk_box_t _box_x6575 = _pat1.fst;
    kk_box_t _box_x6576 = _pat1.snd;
    kk_std_core__list a = kk_std_core__list_unbox(_box_x6576, NULL);
    str = kk_output_dash_and_dash_plot_list__to__csv(a, _ctx); /*string*/
  }
  kk_string_t _b_6581_6579;
  kk_string_t _x7122;
  kk_box_t _x7123;
  kk_ref_t _x7124 = kk_ref_dup(loc); /*local-var<global,string>*/
  _x7123 = (kk_ref_get(_x7124,kk_context())); /*0*/
  _x7122 = kk_string_unbox(_x7123); /*string*/
  _b_6581_6579 = kk_std_core__lp__plus__plus__1_rp_(_x7122, str, _ctx); /*string*/
  return (kk_ref_set(loc,(kk_string_box(_b_6581_6579)),kk_context()));
}

kk_string_t kk_output_dash_and_dash_plot_showspecial(kk_std_core__list tmcmc__result, kk_context_t* _ctx) { /* (tmcmc_result : list<(list<double>, list<double>)>) -> string */ 
  kk_ref_t loc;
  kk_box_t _x7111;
  kk_string_t _x7112 = kk_string_empty(); /*string*/
  _x7111 = kk_string_box(_x7112); /*0*/
  loc = kk_ref_alloc(_x7111,kk_context()); /*local-var<global,string>*/
  kk_string_t res;
  kk_unit_t __ = kk_Unit;
  kk_integer_t end_6289;
  kk_integer_t _x7114;
  kk_std_core__list _x7115 = kk_std_core__list_dup(tmcmc__result); /*list<(list<double>, list<double>)>*/
  _x7114 = kk_std_core_length_1(_x7115, _ctx); /*int*/
  end_6289 = kk_integer_sub(_x7114,(kk_integer_from_small(1)),kk_context()); /*int*/
  kk_function_t _x7116;
  kk_ref_dup(loc);
  _x7116 = kk_output_dash_and_dash_plot_new_showspecial_fun7117(loc, tmcmc__result, _ctx); /*(i : int) -> (local<global>) ()*/
  kk_std_core__lift21056_for(_x7116, end_6289, kk_integer_from_small(0), _ctx);
  kk_box_t _x7125;
  kk_ref_t _x7126 = kk_ref_dup(loc); /*local-var<global,string>*/
  _x7125 = (kk_ref_get(_x7126,kk_context())); /*0*/
  res = kk_string_unbox(_x7125); /*string*/
  kk_box_t _x7127 = kk_std_core_hnd_prompt_local_var(loc, kk_string_box(res), _ctx); /*2*/
  return kk_string_unbox(_x7127);
}


// lift anonymous function
struct kk_output_dash_and_dash_plot_write_fun7130__t {
  struct kk_function_s _base;
};
static kk_box_t kk_output_dash_and_dash_plot_write_fun7130(kk_function_t _fself, kk_box_t _b_6591, kk_context_t* _ctx);
static kk_function_t kk_output_dash_and_dash_plot_new_write_fun7130(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_output_dash_and_dash_plot_write_fun7130, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_output_dash_and_dash_plot_write_fun7130(kk_function_t _fself, kk_box_t _b_6591, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_os_path__path _x7131;
  kk_string_t _x7132 = kk_string_unbox(_b_6591); /*string*/
  _x7131 = kk_std_os_path_path(_x7132, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x7131, _ctx);
}


// lift anonymous function
struct kk_output_dash_and_dash_plot_write_fun7135__t {
  struct kk_function_s _base;
};
static kk_box_t kk_output_dash_and_dash_plot_write_fun7135(kk_function_t _fself, kk_box_t _b_6594, kk_context_t* _ctx);
static kk_function_t kk_output_dash_and_dash_plot_new_write_fun7135(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_output_dash_and_dash_plot_write_fun7135, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_output_dash_and_dash_plot_write_fun7135(kk_function_t _fself, kk_box_t _b_6594, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x7136;
  kk_std_core__list _x7137 = kk_std_core__list_unbox(_b_6594, _ctx); /*list<(list<double>, double)>*/
  _x7136 = kk_output_dash_and_dash_plot_show(_x7137, _ctx); /*string*/
  return kk_string_box(_x7136);
}

kk_unit_t kk_output_dash_and_dash_plot_write(kk_std_core__list trace, kk_string_t filename, kk_context_t* _ctx) { /* (trace : list<(list<double>, double)>, filename : string) -> <exn,fsys> () */ 
  kk_std_os_path__path _x7128;
  kk_box_t _x7129 = kk_std_core_hnd__open_none1(kk_output_dash_and_dash_plot_new_write_fun7130(_ctx), kk_string_box(filename), _ctx); /*2*/
  _x7128 = kk_std_os_path__path_unbox(_x7129, _ctx); /*std/os/path/path*/
  kk_string_t _x7133;
  kk_box_t _x7134 = kk_std_core_hnd__open_none1(kk_output_dash_and_dash_plot_new_write_fun7135(_ctx), kk_std_core__list_box(trace, _ctx), _ctx); /*2*/
  _x7133 = kk_string_unbox(_x7134); /*string*/
  kk_std_os_file_write_text_file(_x7128, _x7133, kk_std_core_types__new_None(_ctx), _ctx); return kk_Unit;
}


// lift anonymous function
struct kk_output_dash_and_dash_plot_write_fun7140__t_1 {
  struct kk_function_s _base;
};
static kk_box_t kk_output_dash_and_dash_plot_write_fun7140_1(kk_function_t _fself, kk_box_t _b_6601, kk_context_t* _ctx);
static kk_function_t kk_output_dash_and_dash_plot_new_write_fun7140_1(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_output_dash_and_dash_plot_write_fun7140_1, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_output_dash_and_dash_plot_write_fun7140_1(kk_function_t _fself, kk_box_t _b_6601, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_os_path__path _x7141;
  kk_string_t _x7142 = kk_string_unbox(_b_6601); /*string*/
  _x7141 = kk_std_os_path_path(_x7142, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x7141, _ctx);
}


// lift anonymous function
struct kk_output_dash_and_dash_plot_write_fun7145__t_1 {
  struct kk_function_s _base;
};
static kk_box_t kk_output_dash_and_dash_plot_write_fun7145_1(kk_function_t _fself, kk_box_t _b_6604, kk_context_t* _ctx);
static kk_function_t kk_output_dash_and_dash_plot_new_write_fun7145_1(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_output_dash_and_dash_plot_write_fun7145_1, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_output_dash_and_dash_plot_write_fun7145_1(kk_function_t _fself, kk_box_t _b_6604, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x7146;
  kk_std_core__list _x7147 = kk_std_core__list_unbox(_b_6604, _ctx); /*list<(list<double>, list<double>)>*/
  _x7146 = kk_output_dash_and_dash_plot_show_1(_x7147, _ctx); /*string*/
  return kk_string_box(_x7146);
}

kk_unit_t kk_output_dash_and_dash_plot_write_1(kk_std_core__list trace, kk_string_t filename, kk_context_t* _ctx) { /* (trace : list<(list<double>, list<double>)>, filename : string) -> <exn,fsys> () */ 
  kk_std_os_path__path _x7138;
  kk_box_t _x7139 = kk_std_core_hnd__open_none1(kk_output_dash_and_dash_plot_new_write_fun7140_1(_ctx), kk_string_box(filename), _ctx); /*2*/
  _x7138 = kk_std_os_path__path_unbox(_x7139, _ctx); /*std/os/path/path*/
  kk_string_t _x7143;
  kk_box_t _x7144 = kk_std_core_hnd__open_none1(kk_output_dash_and_dash_plot_new_write_fun7145_1(_ctx), kk_std_core__list_box(trace, _ctx), _ctx); /*2*/
  _x7143 = kk_string_unbox(_x7144); /*string*/
  kk_std_os_file_write_text_file(_x7138, _x7143, kk_std_core_types__new_None(_ctx), _ctx); return kk_Unit;
}


// lift anonymous function
struct kk_output_dash_and_dash_plot_write_fun7150__t_2 {
  struct kk_function_s _base;
};
static kk_box_t kk_output_dash_and_dash_plot_write_fun7150_2(kk_function_t _fself, kk_box_t _b_6611, kk_context_t* _ctx);
static kk_function_t kk_output_dash_and_dash_plot_new_write_fun7150_2(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_output_dash_and_dash_plot_write_fun7150_2, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_output_dash_and_dash_plot_write_fun7150_2(kk_function_t _fself, kk_box_t _b_6611, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_os_path__path _x7151;
  kk_string_t _x7152 = kk_string_unbox(_b_6611); /*string*/
  _x7151 = kk_std_os_path_path(_x7152, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x7151, _ctx);
}


// lift anonymous function
struct kk_output_dash_and_dash_plot_write_fun7155__t_2 {
  struct kk_function_s _base;
};
static kk_box_t kk_output_dash_and_dash_plot_write_fun7155_2(kk_function_t _fself, kk_box_t _b_6614, kk_context_t* _ctx);
static kk_function_t kk_output_dash_and_dash_plot_new_write_fun7155_2(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_output_dash_and_dash_plot_write_fun7155_2, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_output_dash_and_dash_plot_write_fun7155_2(kk_function_t _fself, kk_box_t _b_6614, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x7156;
  kk_std_core__list _x7157 = kk_std_core__list_unbox(_b_6614, _ctx); /*effects-and-types/histogram<double>*/
  _x7156 = kk_output_dash_and_dash_plot_show_2(_x7157, _ctx); /*string*/
  return kk_string_box(_x7156);
}

kk_unit_t kk_output_dash_and_dash_plot_write_2(kk_std_core__list hist, kk_string_t filename, kk_context_t* _ctx) { /* (hist : effects-and-types/histogram<double>, filename : string) -> <exn,fsys> () */ 
  kk_std_os_path__path _x7148;
  kk_box_t _x7149 = kk_std_core_hnd__open_none1(kk_output_dash_and_dash_plot_new_write_fun7150_2(_ctx), kk_string_box(filename), _ctx); /*2*/
  _x7148 = kk_std_os_path__path_unbox(_x7149, _ctx); /*std/os/path/path*/
  kk_string_t _x7153;
  kk_box_t _x7154 = kk_std_core_hnd__open_none1(kk_output_dash_and_dash_plot_new_write_fun7155_2(_ctx), kk_std_core__list_box(hist, _ctx), _ctx); /*2*/
  _x7153 = kk_string_unbox(_x7154); /*string*/
  kk_std_os_file_write_text_file(_x7148, _x7153, kk_std_core_types__new_None(_ctx), _ctx); return kk_Unit;
}


// lift anonymous function
struct kk_output_dash_and_dash_plot_write_fun7160__t_3 {
  struct kk_function_s _base;
};
static kk_box_t kk_output_dash_and_dash_plot_write_fun7160_3(kk_function_t _fself, kk_box_t _b_6621, kk_context_t* _ctx);
static kk_function_t kk_output_dash_and_dash_plot_new_write_fun7160_3(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_output_dash_and_dash_plot_write_fun7160_3, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_output_dash_and_dash_plot_write_fun7160_3(kk_function_t _fself, kk_box_t _b_6621, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_os_path__path _x7161;
  kk_string_t _x7162 = kk_string_unbox(_b_6621); /*string*/
  _x7161 = kk_std_os_path_path(_x7162, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x7161, _ctx);
}


// lift anonymous function
struct kk_output_dash_and_dash_plot_write_fun7165__t_3 {
  struct kk_function_s _base;
};
static kk_box_t kk_output_dash_and_dash_plot_write_fun7165_3(kk_function_t _fself, kk_box_t _b_6624, kk_context_t* _ctx);
static kk_function_t kk_output_dash_and_dash_plot_new_write_fun7165_3(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_output_dash_and_dash_plot_write_fun7165_3, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_output_dash_and_dash_plot_write_fun7165_3(kk_function_t _fself, kk_box_t _b_6624, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x7166;
  kk_std_core__list _x7167 = kk_std_core__list_unbox(_b_6624, _ctx); /*effects-and-types/histogram<(double, double)>*/
  _x7166 = kk_output_dash_and_dash_plot_show_3(_x7167, _ctx); /*string*/
  return kk_string_box(_x7166);
}

kk_unit_t kk_output_dash_and_dash_plot_write_3(kk_std_core__list hist, kk_string_t filename, kk_context_t* _ctx) { /* (hist : effects-and-types/histogram<(double, double)>, filename : string) -> <exn,fsys> () */ 
  kk_std_os_path__path _x7158;
  kk_box_t _x7159 = kk_std_core_hnd__open_none1(kk_output_dash_and_dash_plot_new_write_fun7160_3(_ctx), kk_string_box(filename), _ctx); /*2*/
  _x7158 = kk_std_os_path__path_unbox(_x7159, _ctx); /*std/os/path/path*/
  kk_string_t _x7163;
  kk_box_t _x7164 = kk_std_core_hnd__open_none1(kk_output_dash_and_dash_plot_new_write_fun7165_3(_ctx), kk_std_core__list_box(hist, _ctx), _ctx); /*2*/
  _x7163 = kk_string_unbox(_x7164); /*string*/
  kk_std_os_file_write_text_file(_x7158, _x7163, kk_std_core_types__new_None(_ctx), _ctx); return kk_Unit;
}


// lift anonymous function
struct kk_output_dash_and_dash_plot_write_fun7170__t_4 {
  struct kk_function_s _base;
};
static kk_box_t kk_output_dash_and_dash_plot_write_fun7170_4(kk_function_t _fself, kk_box_t _b_6631, kk_context_t* _ctx);
static kk_function_t kk_output_dash_and_dash_plot_new_write_fun7170_4(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_output_dash_and_dash_plot_write_fun7170_4, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_output_dash_and_dash_plot_write_fun7170_4(kk_function_t _fself, kk_box_t _b_6631, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_os_path__path _x7171;
  kk_string_t _x7172 = kk_string_unbox(_b_6631); /*string*/
  _x7171 = kk_std_os_path_path(_x7172, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x7171, _ctx);
}


// lift anonymous function
struct kk_output_dash_and_dash_plot_write_fun7175__t_4 {
  struct kk_function_s _base;
};
static kk_box_t kk_output_dash_and_dash_plot_write_fun7175_4(kk_function_t _fself, kk_box_t _b_6634, kk_context_t* _ctx);
static kk_function_t kk_output_dash_and_dash_plot_new_write_fun7175_4(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_output_dash_and_dash_plot_write_fun7175_4, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_output_dash_and_dash_plot_write_fun7175_4(kk_function_t _fself, kk_box_t _b_6634, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x7176;
  kk_std_core__list _x7177 = kk_std_core__list_unbox(_b_6634, _ctx); /*effects-and-types/histogram<list<double>>*/
  _x7176 = kk_output_dash_and_dash_plot_show_4(_x7177, _ctx); /*string*/
  return kk_string_box(_x7176);
}

kk_unit_t kk_output_dash_and_dash_plot_write_4(kk_std_core__list hist, kk_string_t filename, kk_context_t* _ctx) { /* (hist : effects-and-types/histogram<list<double>>, filename : string) -> <exn,fsys> () */ 
  kk_std_os_path__path _x7168;
  kk_box_t _x7169 = kk_std_core_hnd__open_none1(kk_output_dash_and_dash_plot_new_write_fun7170_4(_ctx), kk_string_box(filename), _ctx); /*2*/
  _x7168 = kk_std_os_path__path_unbox(_x7169, _ctx); /*std/os/path/path*/
  kk_string_t _x7173;
  kk_box_t _x7174 = kk_std_core_hnd__open_none1(kk_output_dash_and_dash_plot_new_write_fun7175_4(_ctx), kk_std_core__list_box(hist, _ctx), _ctx); /*2*/
  _x7173 = kk_string_unbox(_x7174); /*string*/
  kk_std_os_file_write_text_file(_x7168, _x7173, kk_std_core_types__new_None(_ctx), _ctx); return kk_Unit;
}
 
// monadic lift

kk_unit_t kk_output_dash_and_dash_plot__mlift6204_write_awk(kk_string_t fname, kk_unit_t wild__, kk_context_t* _ctx) { /* (fname : string, wild_ : ()) -> <exn,fsys> () */ 
  kk_std_core_println(fname, _ctx); return kk_Unit;
}


// lift anonymous function
struct kk_output_dash_and_dash_plot_write_awk_fun7179__t {
  struct kk_function_s _base;
};
static kk_box_t kk_output_dash_and_dash_plot_write_awk_fun7179(kk_function_t _fself, kk_box_t _b_6641, kk_context_t* _ctx);
static kk_function_t kk_output_dash_and_dash_plot_new_write_awk_fun7179(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_output_dash_and_dash_plot_write_awk_fun7179, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_output_dash_and_dash_plot_write_awk_fun7179(kk_function_t _fself, kk_box_t _b_6641, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core__list _x7180;
  kk_string_t _x7181 = kk_string_unbox(_b_6641); /*string*/
  _x7180 = kk_output_dash_and_dash_plot_gen_filenames(_x7181, _ctx); /*list<string>*/
  return kk_std_core__list_box(_x7180, _ctx);
}


// lift anonymous function
struct kk_output_dash_and_dash_plot_write_awk_fun7184__t {
  struct kk_function_s _base;
  kk_std_core__list filenames;
  kk_std_core__list trace__vals;
};
static kk_unit_t kk_output_dash_and_dash_plot_write_awk_fun7184(kk_function_t _fself, kk_integer_t i, kk_context_t* _ctx);
static kk_function_t kk_output_dash_and_dash_plot_new_write_awk_fun7184(kk_std_core__list filenames, kk_std_core__list trace__vals, kk_context_t* _ctx) {
  struct kk_output_dash_and_dash_plot_write_awk_fun7184__t* _self = kk_function_alloc_as(struct kk_output_dash_and_dash_plot_write_awk_fun7184__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_output_dash_and_dash_plot_write_awk_fun7184, kk_context());
  _self->filenames = filenames;
  _self->trace__vals = trace__vals;
  return &_self->_base;
}



// lift anonymous function
struct kk_output_dash_and_dash_plot_write_awk_fun7212__t {
  struct kk_function_s _base;
};
static kk_box_t kk_output_dash_and_dash_plot_write_awk_fun7212(kk_function_t _fself, kk_box_t _b_6666, kk_context_t* _ctx);
static kk_function_t kk_output_dash_and_dash_plot_new_write_awk_fun7212(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_output_dash_and_dash_plot_write_awk_fun7212, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_output_dash_and_dash_plot_write_awk_fun7212(kk_function_t _fself, kk_box_t _b_6666, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_os_path__path _x7213;
  kk_string_t _x7214 = kk_string_unbox(_b_6666); /*string*/
  _x7213 = kk_std_os_path_path(_x7214, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x7213, _ctx);
}


// lift anonymous function
struct kk_output_dash_and_dash_plot_write_awk_fun7219__t {
  struct kk_function_s _base;
};
static kk_box_t kk_output_dash_and_dash_plot_write_awk_fun7219(kk_function_t _fself, kk_box_t _b_6669, kk_context_t* _ctx);
static kk_function_t kk_output_dash_and_dash_plot_new_write_awk_fun7219(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_output_dash_and_dash_plot_write_awk_fun7219, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_output_dash_and_dash_plot_write_awk_fun7219(kk_function_t _fself, kk_box_t _b_6669, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x7220;
  kk_std_core__list _x7221 = kk_std_core__list_unbox(_b_6669, _ctx); /*list<(list<double>, list<double>)>*/
  _x7220 = kk_output_dash_and_dash_plot_showspecial(_x7221, _ctx); /*string*/
  return kk_string_box(_x7220);
}


// lift anonymous function
struct kk_output_dash_and_dash_plot_write_awk_fun7223__t {
  struct kk_function_s _base;
  kk_string_t fname;
};
static kk_box_t kk_output_dash_and_dash_plot_write_awk_fun7223(kk_function_t _fself, kk_box_t _b_6675, kk_context_t* _ctx);
static kk_function_t kk_output_dash_and_dash_plot_new_write_awk_fun7223(kk_string_t fname, kk_context_t* _ctx) {
  struct kk_output_dash_and_dash_plot_write_awk_fun7223__t* _self = kk_function_alloc_as(struct kk_output_dash_and_dash_plot_write_awk_fun7223__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_output_dash_and_dash_plot_write_awk_fun7223, kk_context());
  _self->fname = fname;
  return &_self->_base;
}

static kk_box_t kk_output_dash_and_dash_plot_write_awk_fun7223(kk_function_t _fself, kk_box_t _b_6675, kk_context_t* _ctx) {
  struct kk_output_dash_and_dash_plot_write_awk_fun7223__t* _self = kk_function_as(struct kk_output_dash_and_dash_plot_write_awk_fun7223__t*, _fself);
  kk_string_t fname = _self->fname; /* string */
  kk_drop_match(_self, {kk_string_dup(fname);}, {}, _ctx)
  kk_unit_t _x7224 = kk_Unit;
  kk_unit_t _x7225 = kk_Unit;
  kk_unit_unbox(_b_6675);
  kk_output_dash_and_dash_plot__mlift6204_write_awk(fname, _x7225, _ctx);
  return kk_unit_box(_x7224);
}
static kk_unit_t kk_output_dash_and_dash_plot_write_awk_fun7184(kk_function_t _fself, kk_integer_t i, kk_context_t* _ctx) {
  struct kk_output_dash_and_dash_plot_write_awk_fun7184__t* _self = kk_function_as(struct kk_output_dash_and_dash_plot_write_awk_fun7184__t*, _fself);
  kk_std_core__list filenames = _self->filenames; /* list<string> */
  kk_std_core__list trace__vals = _self->trace__vals; /* list<list<(list<double>, list<double>)>> */
  kk_drop_match(_self, {kk_std_core__list_dup(filenames);kk_std_core__list_dup(trace__vals);}, {}, _ctx)
  kk_std_core_types__maybe _match_6744;
  kk_integer_t _x7185 = kk_integer_dup(i); /*int*/
  _match_6744 = kk_std_core__lp__lb__rb__2_rp_(trace__vals, _x7185, _ctx); /*maybe<1>*/
  if (kk_std_core_types__is_Nothing(_match_6744)) {
    kk_std_core__list_drop(filenames, _ctx);
    kk_integer_drop(i, _ctx);
    kk_std_core__exception exn_21565;
    kk_string_t _x7186;
    kk_define_string_literal(, _s7187, 8, "No list!")
    _x7186 = kk_string_dup(_s7187); /*string*/
    kk_std_core__exception_info _x7188;
    kk_std_core_types__optional _x7189 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/
    if (kk_std_core_types__is_Optional(_x7189)) {
      kk_box_t _box_x6644 = _x7189._cons.Optional.value;
      kk_std_core__exception_info _info_14279 = kk_std_core__exception_info_unbox(_box_x6644, NULL);
      _x7188 = _info_14279; /*exception-info*/
      goto _match7190;
    }
    _x7188 = kk_std_core__new_ExnError(_ctx); /*exception-info*/
    _match7190: ;
    exn_21565 = kk_std_core__new_Exception(_x7186, _x7188, _ctx); /*exception*/
    kk_std_core_hnd__ev ev_21566;
    size_t _x7192 = ((size_t)0); /*size_t*/
    ev_21566 = kk_evv_at(_x7192,kk_context()); /*std/core/hnd/ev<.hnd-exn>*/
    kk_box_t _x7193;
    struct kk_std_core_hnd_Ev* _con7194 = kk_std_core_hnd__as_Ev(ev_21566);
    kk_std_core_hnd__marker m = _con7194->marker;
    kk_box_t _box_x6645 = _con7194->hnd;
    kk_std_core__hnd_exn h = kk_std_core__hnd_exn_unbox(_box_x6645, NULL);
    kk_std_core__hnd_exn_dup(h);
    kk_std_core_hnd__clause1 _match_6749;
    struct kk_std_core__Hnd_exn* _con7196 = kk_std_core__as_Hnd_exn(h);
    kk_std_core_hnd__clause1 except_throw_exn = _con7196->except_throw_exn;
    if (kk_std_core__hnd_exn_is_unique(h)) {
      kk_std_core__hnd_exn_free(h);
    }
    else {
      kk_std_core_hnd__clause1_dup(except_throw_exn);
      kk_std_core__hnd_exn_decref(h, _ctx);
    }
    _match_6749 = except_throw_exn; /*forall<a> std/core/hnd/clause1<exception,a,.hnd-exn,6,7>*/
    kk_function_t _fun_unbox_x6649 = _match_6749.clause;
    _x7193 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x6649, (_fun_unbox_x6649, m, ev_21566, kk_std_core__exception_box(exn_21565, _ctx), _ctx)); /*11*/
    return kk_unit_unbox(_x7193);
  }
  kk_box_t _box_x6653 = _match_6744._cons.Just.value;
  kk_std_core__list lst__lst = kk_std_core__list_unbox(_box_x6653, NULL);
  kk_std_core_types__maybe _match_6745 = kk_std_core__lp__lb__rb__2_rp_(filenames, i, _ctx); /*maybe<1>*/;
  if (kk_std_core_types__is_Nothing(_match_6745)) {
    kk_std_core__list_drop(lst__lst, _ctx);
    kk_std_core__exception exn_215650;
    kk_string_t _x7198;
    kk_define_string_literal(, _s7199, 12, "No filename!")
    _x7198 = kk_string_dup(_s7199); /*string*/
    kk_std_core__exception_info _x7200;
    kk_std_core_types__optional _x7201 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/
    if (kk_std_core_types__is_Optional(_x7201)) {
      kk_box_t _box_x6654 = _x7201._cons.Optional.value;
      kk_std_core__exception_info _info_142790 = kk_std_core__exception_info_unbox(_box_x6654, NULL);
      _x7200 = _info_142790; /*exception-info*/
      goto _match7202;
    }
    _x7200 = kk_std_core__new_ExnError(_ctx); /*exception-info*/
    _match7202: ;
    exn_215650 = kk_std_core__new_Exception(_x7198, _x7200, _ctx); /*exception*/
    kk_std_core_hnd__ev ev_215660;
    size_t _x7204 = ((size_t)0); /*size_t*/
    ev_215660 = kk_evv_at(_x7204,kk_context()); /*std/core/hnd/ev<.hnd-exn>*/
    kk_box_t _x7205;
    struct kk_std_core_hnd_Ev* _con7206 = kk_std_core_hnd__as_Ev(ev_215660);
    kk_std_core_hnd__marker m0 = _con7206->marker;
    kk_box_t _box_x6655 = _con7206->hnd;
    kk_std_core__hnd_exn h0 = kk_std_core__hnd_exn_unbox(_box_x6655, NULL);
    kk_std_core__hnd_exn_dup(h0);
    kk_std_core_hnd__clause1 _match_6747;
    struct kk_std_core__Hnd_exn* _con7208 = kk_std_core__as_Hnd_exn(h0);
    kk_std_core_hnd__clause1 except_throw_exn0 = _con7208->except_throw_exn;
    if (kk_std_core__hnd_exn_is_unique(h0)) {
      kk_std_core__hnd_exn_free(h0);
    }
    else {
      kk_std_core_hnd__clause1_dup(except_throw_exn0);
      kk_std_core__hnd_exn_decref(h0, _ctx);
    }
    _match_6747 = except_throw_exn0; /*forall<a> std/core/hnd/clause1<exception,a,.hnd-exn,6,7>*/
    kk_function_t _fun_unbox_x6659 = _match_6747.clause;
    _x7205 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x6659, (_fun_unbox_x6659, m0, ev_215660, kk_std_core__exception_box(exn_215650, _ctx), _ctx)); /*11*/
    return kk_unit_unbox(_x7205);
  }
  kk_box_t _box_x6663 = _match_6745._cons.Just.value;
  kk_string_t fname = kk_string_unbox(_box_x6663);
  kk_unit_t x_6298 = kk_Unit;
  kk_std_os_path__path _x7210;
  kk_box_t _x7211;
  kk_box_t _x7215;
  kk_string_t _x7216 = kk_string_dup(fname); /*string*/
  _x7215 = kk_string_box(_x7216); /*1*/
  _x7211 = kk_std_core_hnd__open_none1(kk_output_dash_and_dash_plot_new_write_awk_fun7212(_ctx), _x7215, _ctx); /*2*/
  _x7210 = kk_std_os_path__path_unbox(_x7211, _ctx); /*std/os/path/path*/
  kk_string_t _x7217;
  kk_box_t _x7218 = kk_std_core_hnd__open_none1(kk_output_dash_and_dash_plot_new_write_awk_fun7219(_ctx), kk_std_core__list_box(lst__lst, _ctx), _ctx); /*2*/
  _x7217 = kk_string_unbox(_x7218); /*string*/
  kk_std_os_file_write_text_file(_x7210, _x7217, kk_std_core_types__new_None(_ctx), _ctx);
  if (kk_yielding(kk_context())) {
    kk_box_t _x7222 = kk_std_core_hnd_yield_extend(kk_output_dash_and_dash_plot_new_write_awk_fun7223(fname, _ctx), _ctx); /*2*/
    return kk_unit_unbox(_x7222);
  }
  return kk_output_dash_and_dash_plot__mlift6204_write_awk(fname, x_6298, _ctx);
}

kk_unit_t kk_output_dash_and_dash_plot_write_awk(kk_std_core__list trace__vals, kk_string_t filename, kk_context_t* _ctx) { /* (trace_vals : list<list<(list<double>, list<double>)>>, filename : string) -> <console,exn,fsys> () */ 
  kk_std_core__list filenames;
  kk_box_t _x7178 = kk_std_core_hnd__open_none1(kk_output_dash_and_dash_plot_new_write_awk_fun7179(_ctx), kk_string_box(filename), _ctx); /*2*/
  filenames = kk_std_core__list_unbox(_x7178, _ctx); /*list<string>*/
  kk_integer_t end_6292;
  kk_integer_t _x7182;
  kk_std_core__list _x7183 = kk_std_core__list_dup(trace__vals); /*list<list<(list<double>, list<double>)>>*/
  _x7182 = kk_std_core_length_1(_x7183, _ctx); /*int*/
  end_6292 = kk_integer_sub(_x7182,(kk_integer_from_small(1)),kk_context()); /*int*/
  kk_std_core__lift21056_for(kk_output_dash_and_dash_plot_new_write_awk_fun7184(filenames, trace__vals, _ctx), end_6292, kk_integer_from_small(0), _ctx); return kk_Unit;
}


// lift anonymous function
struct kk_output_dash_and_dash_plot_write_awk2_fun7227__t {
  struct kk_function_s _base;
};
static kk_box_t kk_output_dash_and_dash_plot_write_awk2_fun7227(kk_function_t _fself, kk_box_t _b_6686, kk_context_t* _ctx);
static kk_function_t kk_output_dash_and_dash_plot_new_write_awk2_fun7227(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_output_dash_and_dash_plot_write_awk2_fun7227, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_output_dash_and_dash_plot_write_awk2_fun7227(kk_function_t _fself, kk_box_t _b_6686, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core__list _x7228;
  kk_string_t _x7229 = kk_string_unbox(_b_6686); /*string*/
  _x7228 = kk_output_dash_and_dash_plot_gen_filenames2(_x7229, _ctx); /*list<string>*/
  return kk_std_core__list_box(_x7228, _ctx);
}


// lift anonymous function
struct kk_output_dash_and_dash_plot_write_awk2_fun7232__t {
  struct kk_function_s _base;
  kk_std_core__list filenames;
  kk_std_core__list trace__vals;
};
static kk_unit_t kk_output_dash_and_dash_plot_write_awk2_fun7232(kk_function_t _fself, kk_integer_t i, kk_context_t* _ctx);
static kk_function_t kk_output_dash_and_dash_plot_new_write_awk2_fun7232(kk_std_core__list filenames, kk_std_core__list trace__vals, kk_context_t* _ctx) {
  struct kk_output_dash_and_dash_plot_write_awk2_fun7232__t* _self = kk_function_alloc_as(struct kk_output_dash_and_dash_plot_write_awk2_fun7232__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_output_dash_and_dash_plot_write_awk2_fun7232, kk_context());
  _self->filenames = filenames;
  _self->trace__vals = trace__vals;
  return &_self->_base;
}



// lift anonymous function
struct kk_output_dash_and_dash_plot_write_awk2_fun7260__t {
  struct kk_function_s _base;
};
static kk_box_t kk_output_dash_and_dash_plot_write_awk2_fun7260(kk_function_t _fself, kk_box_t _b_6711, kk_context_t* _ctx);
static kk_function_t kk_output_dash_and_dash_plot_new_write_awk2_fun7260(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_output_dash_and_dash_plot_write_awk2_fun7260, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_output_dash_and_dash_plot_write_awk2_fun7260(kk_function_t _fself, kk_box_t _b_6711, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_os_path__path _x7261;
  kk_string_t _x7262 = kk_string_unbox(_b_6711); /*string*/
  _x7261 = kk_std_os_path_path(_x7262, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x7261, _ctx);
}


// lift anonymous function
struct kk_output_dash_and_dash_plot_write_awk2_fun7265__t {
  struct kk_function_s _base;
};
static kk_box_t kk_output_dash_and_dash_plot_write_awk2_fun7265(kk_function_t _fself, kk_box_t _b_6714, kk_context_t* _ctx);
static kk_function_t kk_output_dash_and_dash_plot_new_write_awk2_fun7265(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_output_dash_and_dash_plot_write_awk2_fun7265, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_output_dash_and_dash_plot_write_awk2_fun7265(kk_function_t _fself, kk_box_t _b_6714, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x7266;
  kk_std_core__list _x7267 = kk_std_core__list_unbox(_b_6714, _ctx); /*list<(list<double>, list<double>)>*/
  _x7266 = kk_output_dash_and_dash_plot_showspecial(_x7267, _ctx); /*string*/
  return kk_string_box(_x7266);
}
static kk_unit_t kk_output_dash_and_dash_plot_write_awk2_fun7232(kk_function_t _fself, kk_integer_t i, kk_context_t* _ctx) {
  struct kk_output_dash_and_dash_plot_write_awk2_fun7232__t* _self = kk_function_as(struct kk_output_dash_and_dash_plot_write_awk2_fun7232__t*, _fself);
  kk_std_core__list filenames = _self->filenames; /* list<string> */
  kk_std_core__list trace__vals = _self->trace__vals; /* list<list<(list<double>, list<double>)>> */
  kk_drop_match(_self, {kk_std_core__list_dup(filenames);kk_std_core__list_dup(trace__vals);}, {}, _ctx)
  kk_std_core_types__maybe _match_6738;
  kk_integer_t _x7233 = kk_integer_dup(i); /*int*/
  _match_6738 = kk_std_core__lp__lb__rb__2_rp_(trace__vals, _x7233, _ctx); /*maybe<1>*/
  if (kk_std_core_types__is_Nothing(_match_6738)) {
    kk_std_core__list_drop(filenames, _ctx);
    kk_integer_drop(i, _ctx);
    kk_std_core__exception exn_21565;
    kk_string_t _x7234;
    kk_define_string_literal(, _s7235, 8, "No list!")
    _x7234 = kk_string_dup(_s7235); /*string*/
    kk_std_core__exception_info _x7236;
    kk_std_core_types__optional _x7237 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/
    if (kk_std_core_types__is_Optional(_x7237)) {
      kk_box_t _box_x6689 = _x7237._cons.Optional.value;
      kk_std_core__exception_info _info_14279 = kk_std_core__exception_info_unbox(_box_x6689, NULL);
      _x7236 = _info_14279; /*exception-info*/
      goto _match7238;
    }
    _x7236 = kk_std_core__new_ExnError(_ctx); /*exception-info*/
    _match7238: ;
    exn_21565 = kk_std_core__new_Exception(_x7234, _x7236, _ctx); /*exception*/
    kk_std_core_hnd__ev ev_21566;
    size_t _x7240 = ((size_t)0); /*size_t*/
    ev_21566 = kk_evv_at(_x7240,kk_context()); /*std/core/hnd/ev<.hnd-exn>*/
    kk_box_t _x7241;
    struct kk_std_core_hnd_Ev* _con7242 = kk_std_core_hnd__as_Ev(ev_21566);
    kk_std_core_hnd__marker m = _con7242->marker;
    kk_box_t _box_x6690 = _con7242->hnd;
    kk_std_core__hnd_exn h = kk_std_core__hnd_exn_unbox(_box_x6690, NULL);
    kk_std_core__hnd_exn_dup(h);
    kk_std_core_hnd__clause1 _match_6742;
    struct kk_std_core__Hnd_exn* _con7244 = kk_std_core__as_Hnd_exn(h);
    kk_std_core_hnd__clause1 except_throw_exn = _con7244->except_throw_exn;
    if (kk_std_core__hnd_exn_is_unique(h)) {
      kk_std_core__hnd_exn_free(h);
    }
    else {
      kk_std_core_hnd__clause1_dup(except_throw_exn);
      kk_std_core__hnd_exn_decref(h, _ctx);
    }
    _match_6742 = except_throw_exn; /*forall<a> std/core/hnd/clause1<exception,a,.hnd-exn,6,7>*/
    kk_function_t _fun_unbox_x6694 = _match_6742.clause;
    _x7241 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x6694, (_fun_unbox_x6694, m, ev_21566, kk_std_core__exception_box(exn_21565, _ctx), _ctx)); /*11*/
    return kk_unit_unbox(_x7241);
  }
  kk_box_t _box_x6698 = _match_6738._cons.Just.value;
  kk_std_core__list lst__lst = kk_std_core__list_unbox(_box_x6698, NULL);
  kk_std_core_types__maybe _match_6739 = kk_std_core__lp__lb__rb__2_rp_(filenames, i, _ctx); /*maybe<1>*/;
  if (kk_std_core_types__is_Nothing(_match_6739)) {
    kk_std_core__list_drop(lst__lst, _ctx);
    kk_std_core__exception exn_215650;
    kk_string_t _x7246;
    kk_define_string_literal(, _s7247, 12, "No filename!")
    _x7246 = kk_string_dup(_s7247); /*string*/
    kk_std_core__exception_info _x7248;
    kk_std_core_types__optional _x7249 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/
    if (kk_std_core_types__is_Optional(_x7249)) {
      kk_box_t _box_x6699 = _x7249._cons.Optional.value;
      kk_std_core__exception_info _info_142790 = kk_std_core__exception_info_unbox(_box_x6699, NULL);
      _x7248 = _info_142790; /*exception-info*/
      goto _match7250;
    }
    _x7248 = kk_std_core__new_ExnError(_ctx); /*exception-info*/
    _match7250: ;
    exn_215650 = kk_std_core__new_Exception(_x7246, _x7248, _ctx); /*exception*/
    kk_std_core_hnd__ev ev_215660;
    size_t _x7252 = ((size_t)0); /*size_t*/
    ev_215660 = kk_evv_at(_x7252,kk_context()); /*std/core/hnd/ev<.hnd-exn>*/
    kk_box_t _x7253;
    struct kk_std_core_hnd_Ev* _con7254 = kk_std_core_hnd__as_Ev(ev_215660);
    kk_std_core_hnd__marker m0 = _con7254->marker;
    kk_box_t _box_x6700 = _con7254->hnd;
    kk_std_core__hnd_exn h0 = kk_std_core__hnd_exn_unbox(_box_x6700, NULL);
    kk_std_core__hnd_exn_dup(h0);
    kk_std_core_hnd__clause1 _match_6740;
    struct kk_std_core__Hnd_exn* _con7256 = kk_std_core__as_Hnd_exn(h0);
    kk_std_core_hnd__clause1 except_throw_exn0 = _con7256->except_throw_exn;
    if (kk_std_core__hnd_exn_is_unique(h0)) {
      kk_std_core__hnd_exn_free(h0);
    }
    else {
      kk_std_core_hnd__clause1_dup(except_throw_exn0);
      kk_std_core__hnd_exn_decref(h0, _ctx);
    }
    _match_6740 = except_throw_exn0; /*forall<a> std/core/hnd/clause1<exception,a,.hnd-exn,6,7>*/
    kk_function_t _fun_unbox_x6704 = _match_6740.clause;
    _x7253 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x6704, (_fun_unbox_x6704, m0, ev_215660, kk_std_core__exception_box(exn_215650, _ctx), _ctx)); /*11*/
    return kk_unit_unbox(_x7253);
  }
  kk_box_t _box_x6708 = _match_6739._cons.Just.value;
  kk_string_t fname = kk_string_unbox(_box_x6708);
  kk_std_os_path__path _x7258;
  kk_box_t _x7259 = kk_std_core_hnd__open_none1(kk_output_dash_and_dash_plot_new_write_awk2_fun7260(_ctx), kk_string_box(fname), _ctx); /*2*/
  _x7258 = kk_std_os_path__path_unbox(_x7259, _ctx); /*std/os/path/path*/
  kk_string_t _x7263;
  kk_box_t _x7264 = kk_std_core_hnd__open_none1(kk_output_dash_and_dash_plot_new_write_awk2_fun7265(_ctx), kk_std_core__list_box(lst__lst, _ctx), _ctx); /*2*/
  _x7263 = kk_string_unbox(_x7264); /*string*/
  return kk_std_os_file_write_text_file(_x7258, _x7263, kk_std_core_types__new_None(_ctx), _ctx);
}

kk_unit_t kk_output_dash_and_dash_plot_write_awk2(kk_std_core__list trace__vals, kk_string_t filename, kk_context_t* _ctx) { /* (trace_vals : list<list<(list<double>, list<double>)>>, filename : string) -> <exn,fsys> () */ 
  kk_std_core__list filenames;
  kk_box_t _x7226 = kk_std_core_hnd__open_none1(kk_output_dash_and_dash_plot_new_write_awk2_fun7227(_ctx), kk_string_box(filename), _ctx); /*2*/
  filenames = kk_std_core__list_unbox(_x7226, _ctx); /*list<string>*/
  kk_integer_t end_6301;
  kk_integer_t _x7230;
  kk_std_core__list _x7231 = kk_std_core__list_dup(trace__vals); /*list<list<(list<double>, list<double>)>>*/
  _x7230 = kk_std_core_length_1(_x7231, _ctx); /*int*/
  end_6301 = kk_integer_sub(_x7230,(kk_integer_from_small(1)),kk_context()); /*int*/
  kk_std_core__lift21056_for(kk_output_dash_and_dash_plot_new_write_awk2_fun7232(filenames, trace__vals, _ctx), end_6301, kk_integer_from_small(0), _ctx); return kk_Unit;
}

// initialization
void kk_output_dash_and_dash_plot__init(kk_context_t* _ctx){
  static bool _initialized = false;
  if (_initialized) return;
  _initialized = true;
  kk_std_core_types__init(_ctx);
  kk_std_core_hnd__init(_ctx);
  kk_std_core__init(_ctx);
  kk_std_num_ddouble__init(_ctx);
  kk_std_os_path__init(_ctx);
  kk_std_os_file__init(_ctx);
  kk_effects_dash_and_dash_types__init(_ctx);
}
