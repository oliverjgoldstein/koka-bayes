// Koka generated module: "climate-experiments", koka version: 2.1.2
#include "climate_dash_experiments.h"
 
// monadic lift


// lift anonymous function
struct kk_climate_dash_experiments__mlift2581_run__climate__model_fun3814__t {
  struct kk_function_s _base;
  size_t i_2596;
};
static kk_box_t kk_climate_dash_experiments__mlift2581_run__climate__model_fun3814(kk_function_t _fself, kk_function_t _b_2785, kk_box_t _b_2786, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift2581_run__climate__model_fun3814(size_t i_2596, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2581_run__climate__model_fun3814__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift2581_run__climate__model_fun3814__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift2581_run__climate__model_fun3814, kk_context());
  _self->i_2596 = i_2596;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift2581_run__climate__model_fun3814(kk_function_t _fself, kk_function_t _b_2785, kk_box_t _b_2786, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2581_run__climate__model_fun3814__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift2581_run__climate__model_fun3814__t*, _fself);
  size_t i_2596 = _self->i_2596; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_2596, _b_2785, _b_2786, _ctx);
}

kk_unit_t kk_climate_dash_experiments__mlift2581_run__climate__model(kk_string_t name, kk_integer_t repeat__ind, kk_std_core__list _y_3, kk_context_t* _ctx) { /* (name : string, repeat_ind : int, effects-and-types/histogram<list<double>>) -> <pure,std/num/random/random,fsys,console,ndet> () */ 
  kk_string_t _x24;
  kk_string_t _x3798;
  kk_define_string_literal(, _s3799, 17, "./output-climate/")
  _x3798 = kk_string_dup(_s3799); /*string*/
  kk_string_t _x3800;
  kk_string_t _x3801 = kk_string_dup(name); /*string*/
  kk_string_t _x3802;
  kk_string_t _x3803;
  kk_define_string_literal(, _s3804, 1, "/")
  _x3803 = kk_string_dup(_s3804); /*string*/
  kk_string_t _x3805;
  kk_string_t _x3806;
  kk_string_t _x3807;
  kk_define_string_literal(, _s3808, 5, "_smc_")
  _x3807 = kk_string_dup(_s3808); /*string*/
  kk_string_t _x3809;
  kk_string_t _x3810 = kk_std_core_show(repeat__ind, _ctx); /*string*/
  kk_string_t _x3811;
  kk_define_string_literal(, _s3812, 4, ".csv")
  _x3811 = kk_string_dup(_s3812); /*string*/
  _x3809 = kk_std_core__lp__plus__plus__1_rp_(_x3810, _x3811, _ctx); /*string*/
  _x3806 = kk_std_core__lp__plus__plus__1_rp_(_x3807, _x3809, _ctx); /*string*/
  _x3805 = kk_std_core__lp__plus__plus__1_rp_(name, _x3806, _ctx); /*string*/
  _x3802 = kk_std_core__lp__plus__plus__1_rp_(_x3803, _x3805, _ctx); /*string*/
  _x3800 = kk_std_core__lp__plus__plus__1_rp_(_x3801, _x3802, _ctx); /*string*/
  _x24 = kk_std_core__lp__plus__plus__1_rp_(_x3798, _x3800, _ctx); /*string*/
  size_t i_2596 = ((size_t)0); /*std/core/hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_2596,kk_context()); /*std/core/hnd/evv<<exn,fsys,div,std/num/random/random,console,ndet>>*/;
  kk_unit_t y = kk_Unit;
  kk_output_dash_and_dash_plot_write_4(_y_3, _x24, _ctx);
  kk_unit_t __w_l713_c9 = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x3813 = kk_std_core_hnd_yield_cont(kk_climate_dash_experiments__new_mlift2581_run__climate__model_fun3814(i_2596, _ctx), _ctx); /*3*/
    kk_unit_unbox(_x3813); return kk_Unit;
  }
  y; return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_climate_dash_experiments__mlift2582_run__climate__model_fun3834__t {
  struct kk_function_s _base;
  size_t i_2608;
};
static kk_box_t kk_climate_dash_experiments__mlift2582_run__climate__model_fun3834(kk_function_t _fself, kk_function_t _b_2815, kk_box_t _b_2816, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift2582_run__climate__model_fun3834(size_t i_2608, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2582_run__climate__model_fun3834__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift2582_run__climate__model_fun3834__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift2582_run__climate__model_fun3834, kk_context());
  _self->i_2608 = i_2608;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift2582_run__climate__model_fun3834(kk_function_t _fself, kk_function_t _b_2815, kk_box_t _b_2816, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2582_run__climate__model_fun3834__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift2582_run__climate__model_fun3834__t*, _fself);
  size_t i_2608 = _self->i_2608; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_2608, _b_2815, _b_2816, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift2582_run__climate__model_fun3853__t {
  struct kk_function_s _base;
  size_t i0_2613;
};
static kk_box_t kk_climate_dash_experiments__mlift2582_run__climate__model_fun3853(kk_function_t _fself, kk_function_t _b_2845, kk_box_t _b_2846, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift2582_run__climate__model_fun3853(size_t i0_2613, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2582_run__climate__model_fun3853__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift2582_run__climate__model_fun3853__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift2582_run__climate__model_fun3853, kk_context());
  _self->i0_2613 = i0_2613;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift2582_run__climate__model_fun3853(kk_function_t _fself, kk_function_t _b_2845, kk_box_t _b_2846, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2582_run__climate__model_fun3853__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift2582_run__climate__model_fun3853__t*, _fself);
  size_t i0_2613 = _self->i0_2613; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i0_2613, _b_2845, _b_2846, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift2582_run__climate__model_fun3854__t {
  struct kk_function_s _base;
  kk_function_t _x02_2566;
};
static kk_std_core__list kk_climate_dash_experiments__mlift2582_run__climate__model_fun3854(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift2582_run__climate__model_fun3854(kk_function_t _x02_2566, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2582_run__climate__model_fun3854__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift2582_run__climate__model_fun3854__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift2582_run__climate__model_fun3854, kk_context());
  _self->_x02_2566 = _x02_2566;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift2582_run__climate__model_fun3857__t {
  struct kk_function_s _base;
  kk_function_t _x02_2566;
};
static kk_box_t kk_climate_dash_experiments__mlift2582_run__climate__model_fun3857(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift2582_run__climate__model_fun3857(kk_function_t _x02_2566, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2582_run__climate__model_fun3857__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift2582_run__climate__model_fun3857__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift2582_run__climate__model_fun3857, kk_context());
  _self->_x02_2566 = _x02_2566;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift2582_run__climate__model_fun3857(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2582_run__climate__model_fun3857__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift2582_run__climate__model_fun3857__t*, _fself);
  kk_function_t _x02_2566 = _self->_x02_2566; /* effects-and-types/model<list<double>,exn> */
  kk_drop_match(_self, {kk_function_dup(_x02_2566);}, {}, _ctx)
  kk_std_core__list _x3858 = kk_function_call(kk_std_core__list, (kk_function_t, kk_context_t*), _x02_2566, (_x02_2566, _ctx)); /*list<double>*/
  return kk_std_core__list_box(_x3858, _ctx);
}
static kk_std_core__list kk_climate_dash_experiments__mlift2582_run__climate__model_fun3854(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2582_run__climate__model_fun3854__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift2582_run__climate__model_fun3854__t*, _fself);
  kk_function_t _x02_2566 = _self->_x02_2566; /* effects-and-types/model<list<double>,exn> */
  kk_drop_match(_self, {kk_function_dup(_x02_2566);}, {}, _ctx)
  kk_vector_t _b_2863_2861;
  kk_std_core__list _x3855;
  size_t _b_2865_2859 = ((size_t)0); /*std/core/hnd/ev-index*/;
  kk_std_core__list _b_2866_2860;
  size_t _b_2867_2857 = ((size_t)2); /*std/core/hnd/ev-index*/;
  kk_std_core__list _b_2868_2858;
  size_t _b_2869_2855 = ((size_t)3); /*std/core/hnd/ev-index*/;
  _b_2868_2858 = kk_std_core__new_Cons(kk_reuse_null, kk_size_box(_b_2869_2855, _ctx), kk_std_core__new_Nil(_ctx), _ctx); /*list<std/core/hnd/ev-index>*/
  _b_2866_2860 = kk_std_core__new_Cons(kk_reuse_null, kk_size_box(_b_2867_2857, _ctx), _b_2868_2858, _ctx); /*list<std/core/hnd/ev-index>*/
  _x3855 = kk_std_core__new_Cons(kk_reuse_null, kk_size_box(_b_2865_2859, _ctx), _b_2866_2860, _ctx); /*list<0>*/
  _b_2863_2861 = kk_std_core_unvlist(_x3855, _ctx); /*vector<std/core/hnd/ev-index>*/
  kk_box_t _x3856 = kk_std_core_hnd__open0(_b_2863_2861, kk_climate_dash_experiments__new_mlift2582_run__climate__model_fun3857(_x02_2566, _ctx), _ctx); /*1*/
  return kk_std_core__list_unbox(_x3856, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift2582_run__climate__model_fun3860__t {
  struct kk_function_s _base;
  kk_function_t model_2605;
  kk_integer_t pt;
  kk_integer_t rs;
  kk_integer_t sbrs;
};
static kk_box_t kk_climate_dash_experiments__mlift2582_run__climate__model_fun3860(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift2582_run__climate__model_fun3860(kk_function_t model_2605, kk_integer_t pt, kk_integer_t rs, kk_integer_t sbrs, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2582_run__climate__model_fun3860__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift2582_run__climate__model_fun3860__t, 5, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift2582_run__climate__model_fun3860, kk_context());
  _self->model_2605 = model_2605;
  _self->pt = pt;
  _self->rs = rs;
  _self->sbrs = sbrs;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift2582_run__climate__model_fun3862__t {
  struct kk_function_s _base;
  kk_function_t model_2605;
};
static kk_box_t kk_climate_dash_experiments__mlift2582_run__climate__model_fun3862(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift2582_run__climate__model_fun3862(kk_function_t model_2605, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2582_run__climate__model_fun3862__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift2582_run__climate__model_fun3862__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift2582_run__climate__model_fun3862, kk_context());
  _self->model_2605 = model_2605;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift2582_run__climate__model_fun3864__t {
  struct kk_function_s _base;
  kk_function_t model_2605;
};
static kk_box_t kk_climate_dash_experiments__mlift2582_run__climate__model_fun3864(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift2582_run__climate__model_fun3864(kk_function_t model_2605, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2582_run__climate__model_fun3864__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift2582_run__climate__model_fun3864__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift2582_run__climate__model_fun3864, kk_context());
  _self->model_2605 = model_2605;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift2582_run__climate__model_fun3865__t {
  struct kk_function_s _base;
  kk_function_t model_2605;
};
static kk_box_t kk_climate_dash_experiments__mlift2582_run__climate__model_fun3865(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift2582_run__climate__model_fun3865(kk_function_t model_2605, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2582_run__climate__model_fun3865__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift2582_run__climate__model_fun3865__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift2582_run__climate__model_fun3865, kk_context());
  _self->model_2605 = model_2605;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift2582_run__climate__model_fun3865(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2582_run__climate__model_fun3865__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift2582_run__climate__model_fun3865__t*, _fself);
  kk_function_t model_2605 = _self->model_2605; /* () -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random,fsys,console,ndet> list<double> */
  kk_drop_match(_self, {kk_function_dup(model_2605);}, {}, _ctx)
  kk_std_core__list _x3866 = kk_function_call(kk_std_core__list, (kk_function_t, kk_context_t*), model_2605, (model_2605, _ctx)); /*list<double>*/
  return kk_std_core__list_box(_x3866, _ctx);
}
static kk_box_t kk_climate_dash_experiments__mlift2582_run__climate__model_fun3864(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2582_run__climate__model_fun3864__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift2582_run__climate__model_fun3864__t*, _fself);
  kk_function_t model_2605 = _self->model_2605; /* () -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random,fsys,console,ndet> list<double> */
  kk_drop_match(_self, {kk_function_dup(model_2605);}, {}, _ctx)
  return kk_handlers_yield__on__score(kk_climate_dash_experiments__new_mlift2582_run__climate__model_fun3865(model_2605, _ctx), _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift2582_run__climate__model_fun3867__t {
  struct kk_function_s _base;
  kk_function_t _bv_2873;
};
static kk_std_core__list kk_climate_dash_experiments__mlift2582_run__climate__model_fun3867(kk_function_t _fself, kk_integer_t _b_2874, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift2582_run__climate__model_fun3867(kk_function_t _bv_2873, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2582_run__climate__model_fun3867__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift2582_run__climate__model_fun3867__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift2582_run__climate__model_fun3867, kk_context());
  _self->_bv_2873 = _bv_2873;
  return &_self->_base;
}

static kk_std_core__list kk_climate_dash_experiments__mlift2582_run__climate__model_fun3867(kk_function_t _fself, kk_integer_t _b_2874, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2582_run__climate__model_fun3867__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift2582_run__climate__model_fun3867__t*, _fself);
  kk_function_t _bv_2873 = _self->_bv_2873; /* (a : int) -> <effects-and-types/yield|215> 214 */
  kk_drop_match(_self, {kk_function_dup(_bv_2873);}, {}, _ctx)
  kk_box_t _x3868 = kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_context_t*), _bv_2873, (_bv_2873, _b_2874, _ctx)); /*214*/
  return kk_std_core__list_unbox(_x3868, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift2582_run__climate__model_fun3869__t {
  struct kk_function_s _base;
  kk_function_t _bv_2879;
};
static kk_box_t kk_climate_dash_experiments__mlift2582_run__climate__model_fun3869(kk_function_t _fself, kk_box_t _b_2880, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift2582_run__climate__model_fun3869(kk_function_t _bv_2879, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2582_run__climate__model_fun3869__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift2582_run__climate__model_fun3869__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift2582_run__climate__model_fun3869, kk_context());
  _self->_bv_2879 = _bv_2879;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift2582_run__climate__model_fun3869(kk_function_t _fself, kk_box_t _b_2880, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2582_run__climate__model_fun3869__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift2582_run__climate__model_fun3869__t*, _fself);
  kk_function_t _bv_2879 = _self->_bv_2879; /* (a : int) -> <effects-and-types/yield,effects-and-types/sample,effects-and-types/score,div,exn,std/num/random/random,fsys,console,ndet> list<double> */
  kk_drop_match(_self, {kk_function_dup(_bv_2879);}, {}, _ctx)
  kk_std_core__list _x3870;
  kk_integer_t _x3871 = kk_integer_unbox(_b_2880); /*int*/
  _x3870 = kk_function_call(kk_std_core__list, (kk_function_t, kk_integer_t, kk_context_t*), _bv_2879, (_bv_2879, _x3871, _ctx)); /*list<double>*/
  return kk_std_core__list_box(_x3870, _ctx);
}
static kk_box_t kk_climate_dash_experiments__mlift2582_run__climate__model_fun3862(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2582_run__climate__model_fun3862__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift2582_run__climate__model_fun3862__t*, _fself);
  kk_function_t model_2605 = _self->model_2605; /* () -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random,fsys,console,ndet> list<double> */
  kk_drop_match(_self, {kk_function_dup(model_2605);}, {}, _ctx)
  kk_function_t _x3863;
  kk_function_t _bv_2879;
  kk_function_t _bv_2873 = kk_handlers_advance(kk_climate_dash_experiments__new_mlift2582_run__climate__model_fun3864(model_2605, _ctx), _ctx); /*(a : int) -> <effects-and-types/yield|215> 214*/;
  _bv_2879 = kk_climate_dash_experiments__new_mlift2582_run__climate__model_fun3867(_bv_2873, _ctx); /*(a : int) -> <effects-and-types/yield,effects-and-types/sample,effects-and-types/score,div,exn,std/num/random/random,fsys,console,ndet> list<double>*/
  _x3863 = kk_climate_dash_experiments__new_mlift2582_run__climate__model_fun3869(_bv_2879, _ctx); /*(2877) -> <effects-and-types/yield,effects-and-types/sample,effects-and-types/score,div,exn,std/num/random/random,fsys,console,ndet> 2878*/
  return kk_function_box(_x3863);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift2582_run__climate__model_fun3873__t {
  struct kk_function_s _base;
  kk_integer_t rs;
  kk_integer_t sbrs;
};
static kk_box_t kk_climate_dash_experiments__mlift2582_run__climate__model_fun3873(kk_function_t _fself, kk_box_t _b_2886, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift2582_run__climate__model_fun3873(kk_integer_t rs, kk_integer_t sbrs, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2582_run__climate__model_fun3873__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift2582_run__climate__model_fun3873__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift2582_run__climate__model_fun3873, kk_context());
  _self->rs = rs;
  _self->sbrs = sbrs;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift2582_run__climate__model_fun3873(kk_function_t _fself, kk_box_t _b_2886, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2582_run__climate__model_fun3873__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift2582_run__climate__model_fun3873__t*, _fself);
  kk_integer_t rs = _self->rs; /* int */
  kk_integer_t sbrs = _self->sbrs; /* int */
  kk_drop_match(_self, {kk_integer_dup(rs);kk_integer_dup(sbrs);}, {}, _ctx)
  kk_std_core__list _x3874;
  kk_std_core__list _x3875 = kk_std_core__list_unbox(_b_2886, _ctx); /*effects-and-types/histogram<(a : int) -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random,fsys,console,ndet> list<double>>*/
  _x3874 = kk_sequential__mlift743_smc(true, rs, sbrs, _x3875, _ctx); /*effects-and-types/histogram<24>*/
  return kk_std_core__list_box(_x3874, _ctx);
}
static kk_box_t kk_climate_dash_experiments__mlift2582_run__climate__model_fun3860(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2582_run__climate__model_fun3860__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift2582_run__climate__model_fun3860__t*, _fself);
  kk_function_t model_2605 = _self->model_2605; /* () -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random,fsys,console,ndet> list<double> */
  kk_integer_t pt = _self->pt; /* int */
  kk_integer_t rs = _self->rs; /* int */
  kk_integer_t sbrs = _self->sbrs; /* int */
  kk_drop_match(_self, {kk_function_dup(model_2605);kk_integer_dup(pt);kk_integer_dup(rs);kk_integer_dup(sbrs);}, {}, _ctx)
  kk_std_core__list _x3861;
  kk_std_core__list x_775 = kk_sampling_populate(pt, kk_climate_dash_experiments__new_mlift2582_run__climate__model_fun3862(model_2605, _ctx), _ctx); /*effects-and-types/histogram<(a : int) -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random,fsys,console,ndet> list<double>>*/;
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_775, _ctx);
    kk_box_t _x3872 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments__new_mlift2582_run__climate__model_fun3873(rs, sbrs, _ctx), _ctx); /*2*/
    _x3861 = kk_std_core__list_unbox(_x3872, _ctx); /*effects-and-types/histogram<list<double>>*/
  }
  else {
    _x3861 = kk_sequential__mlift743_smc(true, rs, sbrs, x_775, _ctx); /*effects-and-types/histogram<list<double>>*/
  }
  return kk_std_core__list_box(_x3861, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift2582_run__climate__model_fun3877__t {
  struct kk_function_s _base;
  kk_string_t name;
  kk_integer_t repeat__ind;
};
static kk_box_t kk_climate_dash_experiments__mlift2582_run__climate__model_fun3877(kk_function_t _fself, kk_box_t _b_2892, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift2582_run__climate__model_fun3877(kk_string_t name, kk_integer_t repeat__ind, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2582_run__climate__model_fun3877__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift2582_run__climate__model_fun3877__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift2582_run__climate__model_fun3877, kk_context());
  _self->name = name;
  _self->repeat__ind = repeat__ind;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift2582_run__climate__model_fun3877(kk_function_t _fself, kk_box_t _b_2892, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2582_run__climate__model_fun3877__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift2582_run__climate__model_fun3877__t*, _fself);
  kk_string_t name = _self->name; /* string */
  kk_integer_t repeat__ind = _self->repeat__ind; /* int */
  kk_drop_match(_self, {kk_string_dup(name);kk_integer_dup(repeat__ind);}, {}, _ctx)
  kk_unit_t _x3878 = kk_Unit;
  kk_std_core__list _x3879 = kk_std_core__list_unbox(_b_2892, _ctx); /*effects-and-types/histogram<list<double>>*/
  kk_climate_dash_experiments__mlift2581_run__climate__model(name, repeat__ind, _x3879, _ctx);
  return kk_unit_box(_x3878);
}

kk_unit_t kk_climate_dash_experiments__mlift2582_run__climate__model(kk_std_core_types__tuple2_ data, double diff, kk_integer_t ind, kk_string_t name, kk_integer_t pt, kk_integer_t repeat__ind, kk_integer_t rs, kk_integer_t sbrs, double subtract, kk_std_core__list _y_2, kk_context_t* _ctx) { /* (data : (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>), diff : double, ind : int, name : string, pt : int, repeat_ind : int, rs : int, sbrs : int, subtract : double, list<effects-and-types/row_vector>) -> <exn,div,std/num/random/random,fsys,console,ndet> () */ 
  kk_std_core__list_drop(_y_2, _ctx);
  kk_std_core__list x_2600;
  kk_function_t model_2605;
  kk_function_t _x02_2566;
  kk_std_core__list _x11;
  size_t i_2608 = ((size_t)0); /*std/core/hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_2608,kk_context()); /*std/core/hnd/evv<<exn,div,std/num/random/random,fsys,console,ndet>>*/;
  kk_std_core__list y;
  kk_std_core_types__maybe _match_3794;
  kk_std_core__list _x3815;
  kk_box_t _box_x2795 = data.fst;
  kk_box_t _box_x2796 = data.snd;
  kk_std_core__list _x = kk_std_core__list_unbox(_box_x2796, NULL);
  kk_std_core__list_dup(_x);
  _x3815 = _x; /*list<list<effects-and-types/row_vector>>*/
  kk_integer_t _x3818 = kk_integer_dup(ind); /*int*/
  _match_3794 = kk_std_core__lp__lb__rb__2_rp_(_x3815, _x3818, _ctx); /*maybe<1>*/
  if (kk_std_core_types__is_Nothing(_match_3794)) {
    kk_string_t message_205;
    kk_string_t _x3819;
    kk_define_string_literal(, _s3820, 48, "ListIndexError: Invalid list indexing at index: ")
    _x3819 = kk_string_dup(_s3820); /*string*/
    kk_string_t _x3821;
    kk_integer_t _x3822 = kk_integer_dup(ind); /*int*/
    _x3821 = kk_std_core_show(_x3822, _ctx); /*string*/
    message_205 = kk_std_core__lp__plus__plus__1_rp_(_x3819, _x3821, _ctx); /*string*/
    kk_std_core__exception exn_21565;
    kk_std_core__exception_info _x3823;
    kk_std_core_types__optional _x3824 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/
    if (kk_std_core_types__is_Optional(_x3824)) {
      kk_box_t _box_x2797 = _x3824._cons.Optional.value;
      kk_std_core__exception_info _info_14279 = kk_std_core__exception_info_unbox(_box_x2797, NULL);
      _x3823 = _info_14279; /*exception-info*/
      goto _match3825;
    }
    _x3823 = kk_std_core__new_ExnError(_ctx); /*exception-info*/
    _match3825: ;
    exn_21565 = kk_std_core__new_Exception(message_205, _x3823, _ctx); /*exception*/
    kk_std_core_hnd__ev ev_21566;
    size_t _x3827 = ((size_t)0); /*size_t*/
    ev_21566 = kk_evv_at(_x3827,kk_context()); /*std/core/hnd/ev<.hnd-exn>*/
    kk_box_t _x3828;
    struct kk_std_core_hnd_Ev* _con3829 = kk_std_core_hnd__as_Ev(ev_21566);
    kk_std_core_hnd__marker m = _con3829->marker;
    kk_box_t _box_x2798 = _con3829->hnd;
    kk_std_core__hnd_exn h = kk_std_core__hnd_exn_unbox(_box_x2798, NULL);
    kk_std_core__hnd_exn_dup(h);
    kk_std_core_hnd__clause1 _match_3795;
    struct kk_std_core__Hnd_exn* _con3831 = kk_std_core__as_Hnd_exn(h);
    kk_std_core_hnd__clause1 except_throw_exn = _con3831->except_throw_exn;
    if (kk_std_core__hnd_exn_is_unique(h)) {
      kk_std_core__hnd_exn_free(h);
    }
    else {
      kk_std_core_hnd__clause1_dup(except_throw_exn);
      kk_std_core__hnd_exn_decref(h, _ctx);
    }
    _match_3795 = except_throw_exn; /*forall<a> std/core/hnd/clause1<exception,a,.hnd-exn,6,7>*/
    kk_function_t _fun_unbox_x2802 = _match_3795.clause;
    _x3828 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x2802, (_fun_unbox_x2802, m, ev_21566, kk_std_core__exception_box(exn_21565, _ctx), _ctx)); /*11*/
    y = kk_std_core__list_unbox(_x3828, _ctx); /*list<effects-and-types/row_vector>*/
  }
  else {
    kk_box_t _box_x2806 = _match_3794._cons.Just.value;
    kk_std_core__list x = kk_std_core__list_unbox(_box_x2806, NULL);
    y = x; /*list<effects-and-types/row_vector>*/
  }
  kk_unit_t __w_l713_c9 = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(y, _ctx);
    kk_box_t _x3833 = kk_std_core_hnd_yield_cont(kk_climate_dash_experiments__new_mlift2582_run__climate__model_fun3834(i_2608, _ctx), _ctx); /*3*/
    _x11 = kk_std_core__list_unbox(_x3833, _ctx); /*list<effects-and-types/row_vector>*/
  }
  else {
    _x11 = y; /*list<effects-and-types/row_vector>*/
  }
  kk_std_core__list _x21;
  size_t i0_2613 = ((size_t)0); /*std/core/hnd/ev-index*/;
  kk_evv_t w0 = kk_evv_swap_create1(i0_2613,kk_context()); /*std/core/hnd/evv<<exn,div,std/num/random/random,fsys,console,ndet>>*/;
  kk_std_core__list y0;
  kk_std_core_types__maybe _match_3790;
  kk_std_core__list _x3835;
  kk_box_t _box_x2825 = data.fst;
  kk_box_t _box_x2826 = data.snd;
  kk_std_core__list _x0 = kk_std_core__list_unbox(_box_x2825, NULL);
  kk_std_core__list_dup(_x0);
  kk_std_core_types__tuple2__drop(data, _ctx);
  _x3835 = _x0; /*list<list<effects-and-types/row_vector>>*/
  kk_integer_t _x3838 = kk_integer_dup(ind); /*int*/
  _match_3790 = kk_std_core__lp__lb__rb__2_rp_(_x3835, _x3838, _ctx); /*maybe<1>*/
  if (kk_std_core_types__is_Nothing(_match_3790)) {
    kk_string_t message_2050;
    kk_string_t _x3839;
    kk_define_string_literal(, _s3840, 48, "ListIndexError: Invalid list indexing at index: ")
    _x3839 = kk_string_dup(_s3840); /*string*/
    kk_string_t _x3841 = kk_std_core_show(ind, _ctx); /*string*/
    message_2050 = kk_std_core__lp__plus__plus__1_rp_(_x3839, _x3841, _ctx); /*string*/
    kk_std_core__exception exn_215650;
    kk_std_core__exception_info _x3842;
    kk_std_core_types__optional _x3843 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/
    if (kk_std_core_types__is_Optional(_x3843)) {
      kk_box_t _box_x2827 = _x3843._cons.Optional.value;
      kk_std_core__exception_info _info_142790 = kk_std_core__exception_info_unbox(_box_x2827, NULL);
      _x3842 = _info_142790; /*exception-info*/
      goto _match3844;
    }
    _x3842 = kk_std_core__new_ExnError(_ctx); /*exception-info*/
    _match3844: ;
    exn_215650 = kk_std_core__new_Exception(message_2050, _x3842, _ctx); /*exception*/
    kk_std_core_hnd__ev ev_215660;
    size_t _x3846 = ((size_t)0); /*size_t*/
    ev_215660 = kk_evv_at(_x3846,kk_context()); /*std/core/hnd/ev<.hnd-exn>*/
    kk_box_t _x3847;
    struct kk_std_core_hnd_Ev* _con3848 = kk_std_core_hnd__as_Ev(ev_215660);
    kk_std_core_hnd__marker m0 = _con3848->marker;
    kk_box_t _box_x2828 = _con3848->hnd;
    kk_std_core__hnd_exn h0 = kk_std_core__hnd_exn_unbox(_box_x2828, NULL);
    kk_std_core__hnd_exn_dup(h0);
    kk_std_core_hnd__clause1 _match_3791;
    struct kk_std_core__Hnd_exn* _con3850 = kk_std_core__as_Hnd_exn(h0);
    kk_std_core_hnd__clause1 except_throw_exn0 = _con3850->except_throw_exn;
    if (kk_std_core__hnd_exn_is_unique(h0)) {
      kk_std_core__hnd_exn_free(h0);
    }
    else {
      kk_std_core_hnd__clause1_dup(except_throw_exn0);
      kk_std_core__hnd_exn_decref(h0, _ctx);
    }
    _match_3791 = except_throw_exn0; /*forall<a> std/core/hnd/clause1<exception,a,.hnd-exn,6,7>*/
    kk_function_t _fun_unbox_x2832 = _match_3791.clause;
    _x3847 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x2832, (_fun_unbox_x2832, m0, ev_215660, kk_std_core__exception_box(exn_215650, _ctx), _ctx)); /*11*/
    y0 = kk_std_core__list_unbox(_x3847, _ctx); /*list<effects-and-types/row_vector>*/
  }
  else {
    kk_box_t _box_x2836 = _match_3790._cons.Just.value;
    kk_std_core__list x0 = kk_std_core__list_unbox(_box_x2836, NULL);
    kk_integer_drop(ind, _ctx);
    y0 = x0; /*list<effects-and-types/row_vector>*/
  }
  kk_unit_t __w_l713_c90 = kk_Unit;
  kk_evv_set(w0,kk_context());
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(y0, _ctx);
    kk_box_t _x3852 = kk_std_core_hnd_yield_cont(kk_climate_dash_experiments__new_mlift2582_run__climate__model_fun3853(i0_2613, _ctx), _ctx); /*3*/
    _x21 = kk_std_core__list_unbox(_x3852, _ctx); /*list<effects-and-types/row_vector>*/
  }
  else {
    _x21 = y0; /*list<effects-and-types/row_vector>*/
  }
  kk_evv_t w1 = kk_evv_swap_create0(kk_context()); /*std/core/hnd/evv<(<>)>*/;
  kk_function_t x00 = kk_climate_dash_change_linear__gaussian__climate__data(_x11, _x21, false, diff, subtract, 0x1.2cccccccccccdp2, _ctx); /*effects-and-types/model<list<double>,exn>*/;
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w1,kk_context());
  _x02_2566 = x00; /*effects-and-types/model<list<double>,exn>*/
  model_2605 = kk_climate_dash_experiments__new_mlift2582_run__climate__model_fun3854(_x02_2566, _ctx); /*() -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random,fsys,console,ndet> list<double>*/
  kk_box_t _x3859 = kk_handlers_random__sampler(kk_climate_dash_experiments__new_mlift2582_run__climate__model_fun3860(model_2605, pt, rs, sbrs, _ctx), _ctx); /*312*/
  x_2600 = kk_std_core__list_unbox(_x3859, _ctx); /*effects-and-types/histogram<list<double>>*/
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_2600, _ctx);
    kk_box_t _x3876 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments__new_mlift2582_run__climate__model_fun3877(name, repeat__ind, _ctx), _ctx); /*2*/
    kk_unit_unbox(_x3876); return kk_Unit;
  }
  kk_climate_dash_experiments__mlift2581_run__climate__model(name, repeat__ind, x_2600, _ctx); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_climate_dash_experiments__mlift2583_run__climate__model_fun3899__t {
  struct kk_function_s _base;
  size_t i_2621;
};
static kk_box_t kk_climate_dash_experiments__mlift2583_run__climate__model_fun3899(kk_function_t _fself, kk_function_t _b_2915, kk_box_t _b_2916, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift2583_run__climate__model_fun3899(size_t i_2621, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2583_run__climate__model_fun3899__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift2583_run__climate__model_fun3899__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift2583_run__climate__model_fun3899, kk_context());
  _self->i_2621 = i_2621;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift2583_run__climate__model_fun3899(kk_function_t _fself, kk_function_t _b_2915, kk_box_t _b_2916, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2583_run__climate__model_fun3899__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift2583_run__climate__model_fun3899__t*, _fself);
  size_t i_2621 = _self->i_2621; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_2621, _b_2915, _b_2916, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift2583_run__climate__model_fun3901__t {
  struct kk_function_s _base;
  kk_std_core_types__tuple2_ data;
  kk_integer_t ind;
  kk_string_t name;
  kk_integer_t pt;
  kk_integer_t repeat__ind;
  kk_integer_t rs;
  kk_integer_t sbrs;
  double diff;
  double subtract;
};
static kk_box_t kk_climate_dash_experiments__mlift2583_run__climate__model_fun3901(kk_function_t _fself, kk_box_t _b_2926, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift2583_run__climate__model_fun3901(kk_std_core_types__tuple2_ data, kk_integer_t ind, kk_string_t name, kk_integer_t pt, kk_integer_t repeat__ind, kk_integer_t rs, kk_integer_t sbrs, double diff, double subtract, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2583_run__climate__model_fun3901__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift2583_run__climate__model_fun3901__t, 9, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift2583_run__climate__model_fun3901, kk_context());
  _self->data = data;
  _self->ind = ind;
  _self->name = name;
  _self->pt = pt;
  _self->repeat__ind = repeat__ind;
  _self->rs = rs;
  _self->sbrs = sbrs;
  _self->diff = diff;
  _self->subtract = subtract;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift2583_run__climate__model_fun3901(kk_function_t _fself, kk_box_t _b_2926, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2583_run__climate__model_fun3901__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift2583_run__climate__model_fun3901__t*, _fself);
  kk_std_core_types__tuple2_ data = _self->data; /* (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>) */
  kk_integer_t ind = _self->ind; /* int */
  kk_string_t name = _self->name; /* string */
  kk_integer_t pt = _self->pt; /* int */
  kk_integer_t repeat__ind = _self->repeat__ind; /* int */
  kk_integer_t rs = _self->rs; /* int */
  kk_integer_t sbrs = _self->sbrs; /* int */
  double diff = _self->diff; /* double */
  double subtract = _self->subtract; /* double */
  kk_drop_match(_self, {kk_std_core_types__tuple2__dup(data);kk_integer_dup(ind);kk_string_dup(name);kk_integer_dup(pt);kk_integer_dup(repeat__ind);kk_integer_dup(rs);kk_integer_dup(sbrs);;;}, {}, _ctx)
  kk_unit_t _x3902 = kk_Unit;
  kk_std_core__list _x3903 = kk_std_core__list_unbox(_b_2926, _ctx); /*list<effects-and-types/row_vector>*/
  kk_climate_dash_experiments__mlift2582_run__climate__model(data, diff, ind, name, pt, repeat__ind, rs, sbrs, subtract, _x3903, _ctx);
  return kk_unit_box(_x3902);
}

kk_unit_t kk_climate_dash_experiments__mlift2583_run__climate__model(kk_std_core_types__tuple2_ data, double diff, kk_integer_t ind, kk_string_t name, kk_integer_t pt, kk_integer_t repeat__ind, kk_integer_t rs, kk_integer_t sbrs, double subtract, kk_std_core__list _y_1, kk_context_t* _ctx) { /* (data : (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>), diff : double, ind : int, name : string, pt : int, repeat_ind : int, rs : int, sbrs : int, subtract : double, list<effects-and-types/row_vector>) -> <exn,div,std/num/random/random,fsys,console,ndet> () */ 
  kk_std_core__list_drop(_y_1, _ctx);
  kk_std_core__list x_2618;
  size_t i_2621 = ((size_t)0); /*std/core/hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_2621,kk_context()); /*std/core/hnd/evv<<exn,div,std/num/random/random,fsys,console,ndet>>*/;
  kk_std_core__list y;
  kk_std_core_types__maybe _match_3784;
  kk_std_core__list _x3880;
  kk_box_t _box_x2895 = data.fst;
  kk_box_t _box_x2896 = data.snd;
  kk_std_core__list _x = kk_std_core__list_unbox(_box_x2895, NULL);
  kk_std_core__list_dup(_x);
  _x3880 = _x; /*list<list<effects-and-types/row_vector>>*/
  kk_integer_t _x3883 = kk_integer_dup(ind); /*int*/
  _match_3784 = kk_std_core__lp__lb__rb__2_rp_(_x3880, _x3883, _ctx); /*maybe<1>*/
  if (kk_std_core_types__is_Nothing(_match_3784)) {
    kk_string_t message_205;
    kk_string_t _x3884;
    kk_define_string_literal(, _s3885, 48, "ListIndexError: Invalid list indexing at index: ")
    _x3884 = kk_string_dup(_s3885); /*string*/
    kk_string_t _x3886;
    kk_integer_t _x3887 = kk_integer_dup(ind); /*int*/
    _x3886 = kk_std_core_show(_x3887, _ctx); /*string*/
    message_205 = kk_std_core__lp__plus__plus__1_rp_(_x3884, _x3886, _ctx); /*string*/
    kk_std_core__exception exn_21565;
    kk_std_core__exception_info _x3888;
    kk_std_core_types__optional _x3889 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/
    if (kk_std_core_types__is_Optional(_x3889)) {
      kk_box_t _box_x2897 = _x3889._cons.Optional.value;
      kk_std_core__exception_info _info_14279 = kk_std_core__exception_info_unbox(_box_x2897, NULL);
      _x3888 = _info_14279; /*exception-info*/
      goto _match3890;
    }
    _x3888 = kk_std_core__new_ExnError(_ctx); /*exception-info*/
    _match3890: ;
    exn_21565 = kk_std_core__new_Exception(message_205, _x3888, _ctx); /*exception*/
    kk_std_core_hnd__ev ev_21566;
    size_t _x3892 = ((size_t)0); /*size_t*/
    ev_21566 = kk_evv_at(_x3892,kk_context()); /*std/core/hnd/ev<.hnd-exn>*/
    kk_box_t _x3893;
    struct kk_std_core_hnd_Ev* _con3894 = kk_std_core_hnd__as_Ev(ev_21566);
    kk_std_core_hnd__marker m = _con3894->marker;
    kk_box_t _box_x2898 = _con3894->hnd;
    kk_std_core__hnd_exn h = kk_std_core__hnd_exn_unbox(_box_x2898, NULL);
    kk_std_core__hnd_exn_dup(h);
    kk_std_core_hnd__clause1 _match_3785;
    struct kk_std_core__Hnd_exn* _con3896 = kk_std_core__as_Hnd_exn(h);
    kk_std_core_hnd__clause1 except_throw_exn = _con3896->except_throw_exn;
    if (kk_std_core__hnd_exn_is_unique(h)) {
      kk_std_core__hnd_exn_free(h);
    }
    else {
      kk_std_core_hnd__clause1_dup(except_throw_exn);
      kk_std_core__hnd_exn_decref(h, _ctx);
    }
    _match_3785 = except_throw_exn; /*forall<a> std/core/hnd/clause1<exception,a,.hnd-exn,6,7>*/
    kk_function_t _fun_unbox_x2902 = _match_3785.clause;
    _x3893 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x2902, (_fun_unbox_x2902, m, ev_21566, kk_std_core__exception_box(exn_21565, _ctx), _ctx)); /*11*/
    y = kk_std_core__list_unbox(_x3893, _ctx); /*list<effects-and-types/row_vector>*/
  }
  else {
    kk_box_t _box_x2906 = _match_3784._cons.Just.value;
    kk_std_core__list x = kk_std_core__list_unbox(_box_x2906, NULL);
    y = x; /*list<effects-and-types/row_vector>*/
  }
  kk_unit_t __w_l713_c9 = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(y, _ctx);
    kk_box_t _x3898 = kk_std_core_hnd_yield_cont(kk_climate_dash_experiments__new_mlift2583_run__climate__model_fun3899(i_2621, _ctx), _ctx); /*3*/
    x_2618 = kk_std_core__list_unbox(_x3898, _ctx); /*list<effects-and-types/row_vector>*/
  }
  else {
    x_2618 = y; /*list<effects-and-types/row_vector>*/
  }
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_2618, _ctx);
    kk_box_t _x3900 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments__new_mlift2583_run__climate__model_fun3901(data, ind, name, pt, repeat__ind, rs, sbrs, diff, subtract, _ctx), _ctx); /*2*/
    kk_unit_unbox(_x3900); return kk_Unit;
  }
  kk_climate_dash_experiments__mlift2582_run__climate__model(data, diff, ind, name, pt, repeat__ind, rs, sbrs, subtract, x_2618, _ctx); return kk_Unit;
}
 
// monadic lift

kk_unit_t kk_climate_dash_experiments__mlift2584_run__climate__model(kk_std_core__list wild__0, kk_context_t* _ctx) { /* (wild_0 : list<()>) -> <console,div,exn,fsys,ndet,std/num/random/random> () */ 
  kk_std_core__list_drop(wild__0, _ctx);
  kk_string_t _x3904;
  kk_define_string_literal(, _s3905, 11, "End of SMC.")
  _x3904 = kk_string_dup(_s3905); /*string*/
  kk_std_core_printsln(_x3904, _ctx); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_climate_dash_experiments__mlift2585_run__climate__model_fun3943__t {
  struct kk_function_s _base;
  kk_std_core_types__tuple2_ data;
  kk_std_core__list pre__data;
  kk_integer_t pt;
  kk_std_core_types__optional repeat__num;
  kk_integer_t rs;
  kk_integer_t sbrs;
};
static kk_box_t kk_climate_dash_experiments__mlift2585_run__climate__model_fun3943(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift2585_run__climate__model_fun3943(kk_std_core_types__tuple2_ data, kk_std_core__list pre__data, kk_integer_t pt, kk_std_core_types__optional repeat__num, kk_integer_t rs, kk_integer_t sbrs, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2585_run__climate__model_fun3943__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift2585_run__climate__model_fun3943__t, 9, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift2585_run__climate__model_fun3943, kk_context());
  _self->data = data;
  _self->pre__data = pre__data;
  _self->pt = pt;
  _self->repeat__num = repeat__num;
  _self->rs = rs;
  _self->sbrs = sbrs;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift2585_run__climate__model_fun3948__t {
  struct kk_function_s _base;
  kk_std_core_types__tuple2_ data;
  kk_integer_t pt;
  kk_std_core_types__optional repeat__num;
  kk_integer_t rs;
  kk_integer_t sbrs;
};
static kk_box_t kk_climate_dash_experiments__mlift2585_run__climate__model_fun3948(kk_function_t _fself, kk_box_t _b_3091, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift2585_run__climate__model_fun3948(kk_std_core_types__tuple2_ data, kk_integer_t pt, kk_std_core_types__optional repeat__num, kk_integer_t rs, kk_integer_t sbrs, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2585_run__climate__model_fun3948__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift2585_run__climate__model_fun3948__t, 8, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift2585_run__climate__model_fun3948, kk_context());
  _self->data = data;
  _self->pt = pt;
  _self->repeat__num = repeat__num;
  _self->rs = rs;
  _self->sbrs = sbrs;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift2585_run__climate__model_fun3950__t {
  struct kk_function_s _base;
  kk_box_t _b_3091;
  kk_std_core_types__tuple2_ data;
  kk_integer_t pt;
  kk_integer_t rs;
  kk_integer_t sbrs;
};
static kk_unit_t kk_climate_dash_experiments__mlift2585_run__climate__model_fun3950(kk_function_t _fself, kk_integer_t repeat__ind, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift2585_run__climate__model_fun3950(kk_box_t _b_3091, kk_std_core_types__tuple2_ data, kk_integer_t pt, kk_integer_t rs, kk_integer_t sbrs, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2585_run__climate__model_fun3950__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift2585_run__climate__model_fun3950__t, 7, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift2585_run__climate__model_fun3950, kk_context());
  _self->_b_3091 = _b_3091;
  _self->data = data;
  _self->pt = pt;
  _self->rs = rs;
  _self->sbrs = sbrs;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift2585_run__climate__model_fun3957__t {
  struct kk_function_s _base;
  kk_std_core_types__tuple2_ data;
  kk_integer_t ind;
  kk_string_t name;
  kk_integer_t pt;
  kk_integer_t repeat__ind;
  kk_integer_t rs;
  kk_integer_t sbrs;
  double diff;
  double subtract;
};
static kk_box_t kk_climate_dash_experiments__mlift2585_run__climate__model_fun3957(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift2585_run__climate__model_fun3957(kk_std_core_types__tuple2_ data, kk_integer_t ind, kk_string_t name, kk_integer_t pt, kk_integer_t repeat__ind, kk_integer_t rs, kk_integer_t sbrs, double diff, double subtract, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2585_run__climate__model_fun3957__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift2585_run__climate__model_fun3957__t, 9, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift2585_run__climate__model_fun3957, kk_context());
  _self->data = data;
  _self->ind = ind;
  _self->name = name;
  _self->pt = pt;
  _self->repeat__ind = repeat__ind;
  _self->rs = rs;
  _self->sbrs = sbrs;
  _self->diff = diff;
  _self->subtract = subtract;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift2585_run__climate__model_fun3978__t {
  struct kk_function_s _base;
  size_t i_2637;
};
static kk_box_t kk_climate_dash_experiments__mlift2585_run__climate__model_fun3978(kk_function_t _fself, kk_function_t _b_3074, kk_box_t _b_3075, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift2585_run__climate__model_fun3978(size_t i_2637, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2585_run__climate__model_fun3978__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift2585_run__climate__model_fun3978__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift2585_run__climate__model_fun3978, kk_context());
  _self->i_2637 = i_2637;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift2585_run__climate__model_fun3978(kk_function_t _fself, kk_function_t _b_3074, kk_box_t _b_3075, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2585_run__climate__model_fun3978__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift2585_run__climate__model_fun3978__t*, _fself);
  size_t i_2637 = _self->i_2637; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_2637, _b_3074, _b_3075, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift2585_run__climate__model_fun3980__t {
  struct kk_function_s _base;
  kk_std_core_types__tuple2_ data;
  kk_integer_t ind;
  kk_string_t name;
  kk_integer_t pt;
  kk_integer_t repeat__ind;
  kk_integer_t rs;
  kk_integer_t sbrs;
  double diff;
  double subtract;
};
static kk_box_t kk_climate_dash_experiments__mlift2585_run__climate__model_fun3980(kk_function_t _fself, kk_box_t _b_3085, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift2585_run__climate__model_fun3980(kk_std_core_types__tuple2_ data, kk_integer_t ind, kk_string_t name, kk_integer_t pt, kk_integer_t repeat__ind, kk_integer_t rs, kk_integer_t sbrs, double diff, double subtract, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2585_run__climate__model_fun3980__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift2585_run__climate__model_fun3980__t, 9, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift2585_run__climate__model_fun3980, kk_context());
  _self->data = data;
  _self->ind = ind;
  _self->name = name;
  _self->pt = pt;
  _self->repeat__ind = repeat__ind;
  _self->rs = rs;
  _self->sbrs = sbrs;
  _self->diff = diff;
  _self->subtract = subtract;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift2585_run__climate__model_fun3980(kk_function_t _fself, kk_box_t _b_3085, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2585_run__climate__model_fun3980__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift2585_run__climate__model_fun3980__t*, _fself);
  kk_std_core_types__tuple2_ data = _self->data; /* (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>) */
  kk_integer_t ind = _self->ind; /* int */
  kk_string_t name = _self->name; /* string */
  kk_integer_t pt = _self->pt; /* int */
  kk_integer_t repeat__ind = _self->repeat__ind; /* int */
  kk_integer_t rs = _self->rs; /* int */
  kk_integer_t sbrs = _self->sbrs; /* int */
  double diff = _self->diff; /* double */
  double subtract = _self->subtract; /* double */
  kk_drop_match(_self, {kk_std_core_types__tuple2__dup(data);kk_integer_dup(ind);kk_string_dup(name);kk_integer_dup(pt);kk_integer_dup(repeat__ind);kk_integer_dup(rs);kk_integer_dup(sbrs);;;}, {}, _ctx)
  kk_unit_t _x3981 = kk_Unit;
  kk_std_core__list _x3982 = kk_std_core__list_unbox(_b_3085, _ctx); /*list<effects-and-types/row_vector>*/
  kk_climate_dash_experiments__mlift2583_run__climate__model(data, diff, ind, name, pt, repeat__ind, rs, sbrs, subtract, _x3982, _ctx);
  return kk_unit_box(_x3981);
}
static kk_box_t kk_climate_dash_experiments__mlift2585_run__climate__model_fun3957(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2585_run__climate__model_fun3957__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift2585_run__climate__model_fun3957__t*, _fself);
  kk_std_core_types__tuple2_ data = _self->data; /* (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>) */
  kk_integer_t ind = _self->ind; /* int */
  kk_string_t name = _self->name; /* string */
  kk_integer_t pt = _self->pt; /* int */
  kk_integer_t repeat__ind = _self->repeat__ind; /* int */
  kk_integer_t rs = _self->rs; /* int */
  kk_integer_t sbrs = _self->sbrs; /* int */
  double diff = _self->diff; /* double */
  double subtract = _self->subtract; /* double */
  kk_drop_match(_self, {kk_std_core_types__tuple2__dup(data);kk_integer_dup(ind);kk_string_dup(name);kk_integer_dup(pt);kk_integer_dup(repeat__ind);kk_integer_dup(rs);kk_integer_dup(sbrs);;;}, {}, _ctx)
  kk_unit_t _x3958 = kk_Unit;
  kk_std_core__list x0_2634;
  size_t i_2637 = ((size_t)0); /*std/core/hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_2637,kk_context()); /*std/core/hnd/evv<<exn,div,std/num/random/random,fsys,console,ndet>>*/;
  kk_std_core__list y;
  kk_std_core_types__maybe _match_3779;
  kk_std_core__list _x3959;
  kk_box_t _box_x3054 = data.fst;
  kk_box_t _box_x3055 = data.snd;
  kk_std_core__list _x = kk_std_core__list_unbox(_box_x3055, NULL);
  kk_std_core__list_dup(_x);
  _x3959 = _x; /*list<list<effects-and-types/row_vector>>*/
  kk_integer_t _x3962 = kk_integer_dup(ind); /*int*/
  _match_3779 = kk_std_core__lp__lb__rb__2_rp_(_x3959, _x3962, _ctx); /*maybe<1>*/
  if (kk_std_core_types__is_Nothing(_match_3779)) {
    kk_string_t message_205;
    kk_string_t _x3963;
    kk_define_string_literal(, _s3964, 48, "ListIndexError: Invalid list indexing at index: ")
    _x3963 = kk_string_dup(_s3964); /*string*/
    kk_string_t _x3965;
    kk_integer_t _x3966 = kk_integer_dup(ind); /*int*/
    _x3965 = kk_std_core_show(_x3966, _ctx); /*string*/
    message_205 = kk_std_core__lp__plus__plus__1_rp_(_x3963, _x3965, _ctx); /*string*/
    kk_std_core__exception exn_21565;
    kk_std_core__exception_info _x3967;
    kk_std_core_types__optional _x3968 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/
    if (kk_std_core_types__is_Optional(_x3968)) {
      kk_box_t _box_x3056 = _x3968._cons.Optional.value;
      kk_std_core__exception_info _info_14279 = kk_std_core__exception_info_unbox(_box_x3056, NULL);
      _x3967 = _info_14279; /*exception-info*/
      goto _match3969;
    }
    _x3967 = kk_std_core__new_ExnError(_ctx); /*exception-info*/
    _match3969: ;
    exn_21565 = kk_std_core__new_Exception(message_205, _x3967, _ctx); /*exception*/
    kk_std_core_hnd__ev ev_21566;
    size_t _x3971 = ((size_t)0); /*size_t*/
    ev_21566 = kk_evv_at(_x3971,kk_context()); /*std/core/hnd/ev<.hnd-exn>*/
    kk_box_t _x3972;
    struct kk_std_core_hnd_Ev* _con3973 = kk_std_core_hnd__as_Ev(ev_21566);
    kk_std_core_hnd__marker m = _con3973->marker;
    kk_box_t _box_x3057 = _con3973->hnd;
    kk_std_core__hnd_exn h = kk_std_core__hnd_exn_unbox(_box_x3057, NULL);
    kk_std_core__hnd_exn_dup(h);
    kk_std_core_hnd__clause1 _match_3780;
    struct kk_std_core__Hnd_exn* _con3975 = kk_std_core__as_Hnd_exn(h);
    kk_std_core_hnd__clause1 except_throw_exn = _con3975->except_throw_exn;
    if (kk_std_core__hnd_exn_is_unique(h)) {
      kk_std_core__hnd_exn_free(h);
    }
    else {
      kk_std_core_hnd__clause1_dup(except_throw_exn);
      kk_std_core__hnd_exn_decref(h, _ctx);
    }
    _match_3780 = except_throw_exn; /*forall<a> std/core/hnd/clause1<exception,a,.hnd-exn,6,7>*/
    kk_function_t _fun_unbox_x3061 = _match_3780.clause;
    _x3972 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x3061, (_fun_unbox_x3061, m, ev_21566, kk_std_core__exception_box(exn_21565, _ctx), _ctx)); /*11*/
    y = kk_std_core__list_unbox(_x3972, _ctx); /*list<effects-and-types/row_vector>*/
  }
  else {
    kk_box_t _box_x3065 = _match_3779._cons.Just.value;
    kk_std_core__list x = kk_std_core__list_unbox(_box_x3065, NULL);
    y = x; /*list<effects-and-types/row_vector>*/
  }
  kk_unit_t __w_l713_c9 = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(y, _ctx);
    kk_box_t _x3977 = kk_std_core_hnd_yield_cont(kk_climate_dash_experiments__new_mlift2585_run__climate__model_fun3978(i_2637, _ctx), _ctx); /*3*/
    x0_2634 = kk_std_core__list_unbox(_x3977, _ctx); /*list<effects-and-types/row_vector>*/
  }
  else {
    x0_2634 = y; /*list<effects-and-types/row_vector>*/
  }
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x0_2634, _ctx);
    kk_box_t _x3979 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments__new_mlift2585_run__climate__model_fun3980(data, ind, name, pt, repeat__ind, rs, sbrs, diff, subtract, _ctx), _ctx); /*2*/
    kk_unit_unbox(_x3979);
  }
  else {
    kk_climate_dash_experiments__mlift2583_run__climate__model(data, diff, ind, name, pt, repeat__ind, rs, sbrs, subtract, x0_2634, _ctx);
  }
  return kk_unit_box(_x3958);
}
static kk_unit_t kk_climate_dash_experiments__mlift2585_run__climate__model_fun3950(kk_function_t _fself, kk_integer_t repeat__ind, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2585_run__climate__model_fun3950__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift2585_run__climate__model_fun3950__t*, _fself);
  kk_box_t _b_3091 = _self->_b_3091; /* 1 */
  kk_std_core_types__tuple2_ data = _self->data; /* (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>) */
  kk_integer_t pt = _self->pt; /* int */
  kk_integer_t rs = _self->rs; /* int */
  kk_integer_t sbrs = _self->sbrs; /* int */
  kk_drop_match(_self, {kk_box_dup(_b_3091);kk_std_core_types__tuple2__dup(data);kk_integer_dup(pt);kk_integer_dup(rs);kk_integer_dup(sbrs);}, {}, _ctx)
  kk_box_t _x3951;
  kk_std_core_types__tuple2_ _match_3776 = kk_std_core_types__tuple2__unbox(_b_3091, _ctx); /*(int, (double, double, string))*/;
  kk_box_t _box_x3049 = _match_3776.fst;
  kk_box_t _box_x3050 = _match_3776.snd;
  kk_integer_t ind = kk_integer_unbox(_box_x3049);
  kk_std_core_types__tuple3_ _pat2 = kk_std_core_types__tuple3__unbox(_box_x3050, NULL);
  kk_box_t _box_x3051 = _pat2.fst;
  kk_box_t _box_x3052 = _pat2.snd;
  kk_box_t _box_x3053 = _pat2.thd;
  double diff = kk_double_unbox(_box_x3051, NULL);
  double subtract = kk_double_unbox(_box_x3052, NULL);
  kk_string_t name = kk_string_unbox(_box_x3053);
  kk_integer_dup(ind);
  kk_string_dup(name);
  kk_std_core_types__tuple2__drop(_match_3776, _ctx);
  _x3951 = kk_std_time_timer_print_elapsed(kk_climate_dash_experiments__new_mlift2585_run__climate__model_fun3957(data, ind, name, pt, repeat__ind, rs, sbrs, diff, subtract, _ctx), kk_std_core_types__new_None(_ctx), _ctx); /*453*/
  return kk_unit_unbox(_x3951);
}
static kk_box_t kk_climate_dash_experiments__mlift2585_run__climate__model_fun3948(kk_function_t _fself, kk_box_t _b_3091, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2585_run__climate__model_fun3948__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift2585_run__climate__model_fun3948__t*, _fself);
  kk_std_core_types__tuple2_ data = _self->data; /* (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>) */
  kk_integer_t pt = _self->pt; /* int */
  kk_std_core_types__optional repeat__num = _self->repeat__num; /* optional<int> */
  kk_integer_t rs = _self->rs; /* int */
  kk_integer_t sbrs = _self->sbrs; /* int */
  kk_drop_match(_self, {kk_std_core_types__tuple2__dup(data);kk_integer_dup(pt);kk_std_core_types__optional_dup(repeat__num);kk_integer_dup(rs);kk_integer_dup(sbrs);}, {}, _ctx)
  kk_unit_t _x3949 = kk_Unit;
  kk_integer_t _x3983;
  if (kk_std_core_types__is_Optional(repeat__num)) {
    kk_box_t _box_x3088 = repeat__num._cons.Optional.value;
    kk_integer_t _repeat__num_20 = kk_integer_unbox(_box_x3088);
    _x3983 = _repeat__num_20; /*int*/
    goto _match3984;
  }
  _x3983 = kk_integer_from_small(8); /*int*/
  _match3984: ;
  kk_std_core__lift21056_for(kk_climate_dash_experiments__new_mlift2585_run__climate__model_fun3950(_b_3091, data, pt, rs, sbrs, _ctx), _x3983, kk_integer_from_small(1), _ctx);
  return kk_unit_box(_x3949);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift2585_run__climate__model_fun3987__t {
  struct kk_function_s _base;
};
static kk_box_t kk_climate_dash_experiments__mlift2585_run__climate__model_fun3987(kk_function_t _fself, kk_box_t _b_3100, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift2585_run__climate__model_fun3987(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_climate_dash_experiments__mlift2585_run__climate__model_fun3987, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_climate_dash_experiments__mlift2585_run__climate__model_fun3987(kk_function_t _fself, kk_box_t _b_3100, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_unit_t _x3988 = kk_Unit;
  kk_std_core__list _x3989 = kk_std_core__list_unbox(_b_3100, _ctx); /*list<()>*/
  kk_climate_dash_experiments__mlift2584_run__climate__model(_x3989, _ctx);
  return kk_unit_box(_x3988);
}
static kk_box_t kk_climate_dash_experiments__mlift2585_run__climate__model_fun3943(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2585_run__climate__model_fun3943__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift2585_run__climate__model_fun3943__t*, _fself);
  kk_std_core_types__tuple2_ data = _self->data; /* (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>) */
  kk_std_core__list pre__data = _self->pre__data; /* list<(double, double, string)> */
  kk_integer_t pt = _self->pt; /* int */
  kk_std_core_types__optional repeat__num = _self->repeat__num; /* optional<int> */
  kk_integer_t rs = _self->rs; /* int */
  kk_integer_t sbrs = _self->sbrs; /* int */
  kk_drop_match(_self, {kk_std_core_types__tuple2__dup(data);kk_std_core__list_dup(pre__data);kk_integer_dup(pt);kk_std_core_types__optional_dup(repeat__num);kk_integer_dup(rs);kk_integer_dup(sbrs);}, {}, _ctx)
  kk_unit_t _x3944 = kk_Unit;
  kk_unit_t __ = kk_Unit;
  kk_string_t _x3945;
  kk_define_string_literal(, _s3946, 10, "Begin SMC:")
  _x3945 = kk_string_dup(_s3946); /*string*/
  kk_std_core_printsln(_x3945, _ctx);
  kk_std_core__list x_2627;
  kk_std_core__list _b_3092_3089;
  kk_std_core__list _x3947 = kk_std_core__lift21053_list(kk_integer_from_small(0), kk_integer_from_small(11), kk_std_core__new_Nil(_ctx), _ctx); /*list<int>*/
  _b_3092_3089 = kk_std_core_zip(_x3947, pre__data, _ctx); /*list<(int, (double, double, string))>*/
  x_2627 = kk_std_core_map_5(_b_3092_3089, kk_climate_dash_experiments__new_mlift2585_run__climate__model_fun3948(data, pt, repeat__num, rs, sbrs, _ctx), _ctx); /*list<()>*/
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_2627, _ctx);
    kk_box_t _x3986 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments__new_mlift2585_run__climate__model_fun3987(_ctx), _ctx); /*2*/
    kk_unit_unbox(_x3986);
  }
  else {
    kk_climate_dash_experiments__mlift2584_run__climate__model(x_2627, _ctx);
  }
  return kk_unit_box(_x3944);
}

kk_unit_t kk_climate_dash_experiments__mlift2585_run__climate__model(kk_integer_t pt, kk_std_core_types__optional repeat__num, kk_integer_t rs, kk_integer_t sbrs, kk_std_core_types__tuple2_ data, kk_context_t* _ctx) { /* (pt : int, repeat_num : optional<int>, rs : int, sbrs : int, data : (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>)) -> <div,exn,fsys,console,ndet,std/num/random/random> () */ 
  kk_std_core__list pre__data;
  kk_std_core_types__tuple3_ _b_2989_2987;
  kk_box_t _x3906;
  kk_string_t _x3907;
  kk_define_string_literal(, _s3908, 3, "jan")
  _x3907 = kk_string_dup(_s3908); /*string*/
  _x3906 = kk_string_box(_x3907); /*10*/
  _b_2989_2987 = kk_std_core_types__new_dash__lp__comma__comma__rp_(kk_double_box(0x1.4p3, _ctx), kk_double_box(-0x1.8p1, _ctx), _x3906, _ctx); /*(double, double, string)*/
  kk_std_core__list _b_2990_2988;
  kk_std_core_types__tuple3_ _b_2994_2985;
  kk_box_t _x3909;
  kk_string_t _x3910;
  kk_define_string_literal(, _s3911, 3, "feb")
  _x3910 = kk_string_dup(_s3911); /*string*/
  _x3909 = kk_string_box(_x3910); /*10*/
  _b_2994_2985 = kk_std_core_types__new_dash__lp__comma__comma__rp_(kk_double_box(0x1p3, _ctx), kk_double_box(-0x1p0, _ctx), _x3909, _ctx); /*(double, double, string)*/
  kk_std_core__list _b_2995_2986;
  kk_std_core_types__tuple3_ _b_2999_2983;
  kk_box_t _x3912;
  kk_string_t _x3913;
  kk_define_string_literal(, _s3914, 3, "mar")
  _x3913 = kk_string_dup(_s3914); /*string*/
  _x3912 = kk_string_box(_x3913); /*10*/
  _b_2999_2983 = kk_std_core_types__new_dash__lp__comma__comma__rp_(kk_double_box(0x1.cp2, _ctx), kk_double_box(0x1p0, _ctx), _x3912, _ctx); /*(double, double, string)*/
  kk_std_core__list _b_3000_2984;
  kk_std_core_types__tuple3_ _b_3004_2981;
  kk_box_t _x3915;
  kk_string_t _x3916;
  kk_define_string_literal(, _s3917, 3, "apr")
  _x3916 = kk_string_dup(_s3917); /*string*/
  _x3915 = kk_string_box(_x3916); /*10*/
  _b_3004_2981 = kk_std_core_types__new_dash__lp__comma__comma__rp_(kk_double_box(0x1.8p2, _ctx), kk_double_box(0x1.4p2, _ctx), _x3915, _ctx); /*(double, double, string)*/
  kk_std_core__list _b_3005_2982;
  kk_std_core_types__tuple3_ _b_3009_2979;
  kk_box_t _x3918;
  kk_string_t _x3919;
  kk_define_string_literal(, _s3920, 3, "may")
  _x3919 = kk_string_dup(_s3920); /*string*/
  _x3918 = kk_string_box(_x3919); /*10*/
  _b_3009_2979 = kk_std_core_types__new_dash__lp__comma__comma__rp_(kk_double_box(0x1p3, _ctx), kk_double_box(0x1.2p3, _ctx), _x3918, _ctx); /*(double, double, string)*/
  kk_std_core__list _b_3010_2980;
  kk_std_core_types__tuple3_ _b_3014_2977;
  kk_box_t _x3921;
  kk_string_t _x3922;
  kk_define_string_literal(, _s3923, 3, "jun")
  _x3922 = kk_string_dup(_s3923); /*string*/
  _x3921 = kk_string_box(_x3922); /*10*/
  _b_3014_2977 = kk_std_core_types__new_dash__lp__comma__comma__rp_(kk_double_box(0x1p3, _ctx), kk_double_box(0x1.4p3, _ctx), _x3921, _ctx); /*(double, double, string)*/
  kk_std_core__list _b_3015_2978;
  kk_std_core_types__tuple3_ _b_3019_2975;
  kk_box_t _x3924;
  kk_string_t _x3925;
  kk_define_string_literal(, _s3926, 3, "jul")
  _x3925 = kk_string_dup(_s3926); /*string*/
  _x3924 = kk_string_box(_x3925); /*10*/
  _b_3019_2975 = kk_std_core_types__new_dash__lp__comma__comma__rp_(kk_double_box(0x1.2p3, _ctx), kk_double_box(0x1.6p3, _ctx), _x3924, _ctx); /*(double, double, string)*/
  kk_std_core__list _b_3020_2976;
  kk_std_core_types__tuple3_ _b_3024_2973;
  kk_box_t _x3927;
  kk_string_t _x3928;
  kk_define_string_literal(, _s3929, 3, "aug")
  _x3928 = kk_string_dup(_s3929); /*string*/
  _x3927 = kk_string_box(_x3928); /*10*/
  _b_3024_2973 = kk_std_core_types__new_dash__lp__comma__comma__rp_(kk_double_box(0x1.8p2, _ctx), kk_double_box(0x1.6p3, _ctx), _x3927, _ctx); /*(double, double, string)*/
  kk_std_core__list _b_3025_2974;
  kk_std_core_types__tuple3_ _b_3029_2971;
  kk_box_t _x3930;
  kk_string_t _x3931;
  kk_define_string_literal(, _s3932, 3, "sep")
  _x3931 = kk_string_dup(_s3932); /*string*/
  _x3930 = kk_string_box(_x3931); /*10*/
  _b_3029_2971 = kk_std_core_types__new_dash__lp__comma__comma__rp_(kk_double_box(0x1.4p2, _ctx), kk_double_box(0x1.4p3, _ctx), _x3930, _ctx); /*(double, double, string)*/
  kk_std_core__list _b_3030_2972;
  kk_std_core_types__tuple3_ _b_3034_2969;
  kk_box_t _x3933;
  kk_string_t _x3934;
  kk_define_string_literal(, _s3935, 3, "oct")
  _x3934 = kk_string_dup(_s3935); /*string*/
  _x3933 = kk_string_box(_x3934); /*10*/
  _b_3034_2969 = kk_std_core_types__new_dash__lp__comma__comma__rp_(kk_double_box(0x1.2p3, _ctx), kk_double_box(0x1p0, _ctx), _x3933, _ctx); /*(double, double, string)*/
  kk_std_core__list _b_3035_2970;
  kk_std_core_types__tuple3_ _b_3039_2967;
  kk_box_t _x3936;
  kk_string_t _x3937;
  kk_define_string_literal(, _s3938, 3, "nov")
  _x3937 = kk_string_dup(_s3938); /*string*/
  _x3936 = kk_string_box(_x3937); /*10*/
  _b_3039_2967 = kk_std_core_types__new_dash__lp__comma__comma__rp_(kk_double_box(0x1.cp2, _ctx), kk_double_box(0x1p1, _ctx), _x3936, _ctx); /*(double, double, string)*/
  kk_std_core__list _b_3040_2968;
  kk_std_core_types__tuple3_ _b_3044_2965;
  kk_box_t _x3939;
  kk_string_t _x3940;
  kk_define_string_literal(, _s3941, 3, "dec")
  _x3940 = kk_string_dup(_s3941); /*string*/
  _x3939 = kk_string_box(_x3940); /*10*/
  _b_3044_2965 = kk_std_core_types__new_dash__lp__comma__comma__rp_(kk_double_box(0x1.8p2, _ctx), kk_double_box(-0x1p0, _ctx), _x3939, _ctx); /*(double, double, string)*/
  _b_3040_2968 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core_types__tuple3__box(_b_3044_2965, _ctx), kk_std_core__new_Nil(_ctx), _ctx); /*list<(double, double, string)>*/
  _b_3035_2970 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core_types__tuple3__box(_b_3039_2967, _ctx), _b_3040_2968, _ctx); /*list<(double, double, string)>*/
  _b_3030_2972 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core_types__tuple3__box(_b_3034_2969, _ctx), _b_3035_2970, _ctx); /*list<(double, double, string)>*/
  _b_3025_2974 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core_types__tuple3__box(_b_3029_2971, _ctx), _b_3030_2972, _ctx); /*list<(double, double, string)>*/
  _b_3020_2976 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core_types__tuple3__box(_b_3024_2973, _ctx), _b_3025_2974, _ctx); /*list<(double, double, string)>*/
  _b_3015_2978 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core_types__tuple3__box(_b_3019_2975, _ctx), _b_3020_2976, _ctx); /*list<(double, double, string)>*/
  _b_3010_2980 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core_types__tuple3__box(_b_3014_2977, _ctx), _b_3015_2978, _ctx); /*list<(double, double, string)>*/
  _b_3005_2982 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core_types__tuple3__box(_b_3009_2979, _ctx), _b_3010_2980, _ctx); /*list<(double, double, string)>*/
  _b_3000_2984 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core_types__tuple3__box(_b_3004_2981, _ctx), _b_3005_2982, _ctx); /*list<(double, double, string)>*/
  _b_2995_2986 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core_types__tuple3__box(_b_2999_2983, _ctx), _b_3000_2984, _ctx); /*list<(double, double, string)>*/
  _b_2990_2988 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core_types__tuple3__box(_b_2994_2985, _ctx), _b_2995_2986, _ctx); /*list<(double, double, string)>*/
  pre__data = kk_std_core__new_Cons(kk_reuse_null, kk_std_core_types__tuple3__box(_b_2989_2987, _ctx), _b_2990_2988, _ctx); /*list<(double, double, string)>*/
  kk_box_t _x3942 = kk_std_time_timer_print_elapsed(kk_climate_dash_experiments__new_mlift2585_run__climate__model_fun3943(data, pre__data, pt, repeat__num, rs, sbrs, _ctx), kk_std_core_types__new_None(_ctx), _ctx); /*453*/
  kk_unit_unbox(_x3942); return kk_Unit;
}


// lift anonymous function
struct kk_climate_dash_experiments_run__climate__model_fun3991__t {
  struct kk_function_s _base;
  size_t i_2644;
};
static kk_box_t kk_climate_dash_experiments_run__climate__model_fun3991(kk_function_t _fself, kk_function_t _b_3111, kk_box_t _b_3112, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__climate__model_fun3991(size_t i_2644, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__climate__model_fun3991__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__climate__model_fun3991__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__climate__model_fun3991, kk_context());
  _self->i_2644 = i_2644;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments_run__climate__model_fun3991(kk_function_t _fself, kk_function_t _b_3111, kk_box_t _b_3112, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__climate__model_fun3991__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__climate__model_fun3991__t*, _fself);
  size_t i_2644 = _self->i_2644; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_2644, _b_3111, _b_3112, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments_run__climate__model_fun3993__t {
  struct kk_function_s _base;
  kk_integer_t pt;
  kk_std_core_types__optional repeat__num;
  kk_integer_t rs;
  kk_integer_t sbrs;
};
static kk_box_t kk_climate_dash_experiments_run__climate__model_fun3993(kk_function_t _fself, kk_box_t _b_3122, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__climate__model_fun3993(kk_integer_t pt, kk_std_core_types__optional repeat__num, kk_integer_t rs, kk_integer_t sbrs, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__climate__model_fun3993__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__climate__model_fun3993__t, 6, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__climate__model_fun3993, kk_context());
  _self->pt = pt;
  _self->repeat__num = repeat__num;
  _self->rs = rs;
  _self->sbrs = sbrs;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments_run__climate__model_fun3993(kk_function_t _fself, kk_box_t _b_3122, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__climate__model_fun3993__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__climate__model_fun3993__t*, _fself);
  kk_integer_t pt = _self->pt; /* int */
  kk_std_core_types__optional repeat__num = _self->repeat__num; /* optional<int> */
  kk_integer_t rs = _self->rs; /* int */
  kk_integer_t sbrs = _self->sbrs; /* int */
  kk_drop_match(_self, {kk_integer_dup(pt);kk_std_core_types__optional_dup(repeat__num);kk_integer_dup(rs);kk_integer_dup(sbrs);}, {}, _ctx)
  kk_unit_t _x3994 = kk_Unit;
  kk_std_core_types__tuple2_ _x3995 = kk_std_core_types__tuple2__unbox(_b_3122, _ctx); /*(list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>)*/
  kk_climate_dash_experiments__mlift2585_run__climate__model(pt, repeat__num, rs, sbrs, _x3995, _ctx);
  return kk_unit_box(_x3994);
}


// lift anonymous function
struct kk_climate_dash_experiments_run__climate__model_fun4033__t {
  struct kk_function_s _base;
  kk_std_core__list pre__data;
  kk_integer_t pt;
  kk_std_core_types__optional repeat__num;
  kk_integer_t rs;
  kk_integer_t sbrs;
  kk_std_core_types__tuple2_ x_2641;
};
static kk_box_t kk_climate_dash_experiments_run__climate__model_fun4033(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__climate__model_fun4033(kk_std_core__list pre__data, kk_integer_t pt, kk_std_core_types__optional repeat__num, kk_integer_t rs, kk_integer_t sbrs, kk_std_core_types__tuple2_ x_2641, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__climate__model_fun4033__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__climate__model_fun4033__t, 9, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__climate__model_fun4033, kk_context());
  _self->pre__data = pre__data;
  _self->pt = pt;
  _self->repeat__num = repeat__num;
  _self->rs = rs;
  _self->sbrs = sbrs;
  _self->x_2641 = x_2641;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments_run__climate__model_fun4038__t {
  struct kk_function_s _base;
  kk_integer_t pt;
  kk_std_core_types__optional repeat__num;
  kk_integer_t rs;
  kk_integer_t sbrs;
  kk_std_core_types__tuple2_ x_2641;
};
static kk_box_t kk_climate_dash_experiments_run__climate__model_fun4038(kk_function_t _fself, kk_box_t _b_3285, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__climate__model_fun4038(kk_integer_t pt, kk_std_core_types__optional repeat__num, kk_integer_t rs, kk_integer_t sbrs, kk_std_core_types__tuple2_ x_2641, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__climate__model_fun4038__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__climate__model_fun4038__t, 8, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__climate__model_fun4038, kk_context());
  _self->pt = pt;
  _self->repeat__num = repeat__num;
  _self->rs = rs;
  _self->sbrs = sbrs;
  _self->x_2641 = x_2641;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments_run__climate__model_fun4040__t {
  struct kk_function_s _base;
  kk_box_t _b_3285;
  kk_integer_t pt;
  kk_integer_t rs;
  kk_integer_t sbrs;
  kk_std_core_types__tuple2_ x_2641;
};
static kk_unit_t kk_climate_dash_experiments_run__climate__model_fun4040(kk_function_t _fself, kk_integer_t repeat__ind, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__climate__model_fun4040(kk_box_t _b_3285, kk_integer_t pt, kk_integer_t rs, kk_integer_t sbrs, kk_std_core_types__tuple2_ x_2641, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__climate__model_fun4040__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__climate__model_fun4040__t, 7, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__climate__model_fun4040, kk_context());
  _self->_b_3285 = _b_3285;
  _self->pt = pt;
  _self->rs = rs;
  _self->sbrs = sbrs;
  _self->x_2641 = x_2641;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments_run__climate__model_fun4047__t {
  struct kk_function_s _base;
  kk_integer_t ind;
  kk_string_t name;
  kk_integer_t pt;
  kk_integer_t repeat__ind;
  kk_integer_t rs;
  kk_integer_t sbrs;
  kk_std_core_types__tuple2_ x_2641;
  double diff;
  double subtract;
};
static kk_box_t kk_climate_dash_experiments_run__climate__model_fun4047(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__climate__model_fun4047(kk_integer_t ind, kk_string_t name, kk_integer_t pt, kk_integer_t repeat__ind, kk_integer_t rs, kk_integer_t sbrs, kk_std_core_types__tuple2_ x_2641, double diff, double subtract, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__climate__model_fun4047__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__climate__model_fun4047__t, 9, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__climate__model_fun4047, kk_context());
  _self->ind = ind;
  _self->name = name;
  _self->pt = pt;
  _self->repeat__ind = repeat__ind;
  _self->rs = rs;
  _self->sbrs = sbrs;
  _self->x_2641 = x_2641;
  _self->diff = diff;
  _self->subtract = subtract;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments_run__climate__model_fun4068__t {
  struct kk_function_s _base;
  size_t i0_2658;
};
static kk_box_t kk_climate_dash_experiments_run__climate__model_fun4068(kk_function_t _fself, kk_function_t _b_3268, kk_box_t _b_3269, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__climate__model_fun4068(size_t i0_2658, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__climate__model_fun4068__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__climate__model_fun4068__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__climate__model_fun4068, kk_context());
  _self->i0_2658 = i0_2658;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments_run__climate__model_fun4068(kk_function_t _fself, kk_function_t _b_3268, kk_box_t _b_3269, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__climate__model_fun4068__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__climate__model_fun4068__t*, _fself);
  size_t i0_2658 = _self->i0_2658; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i0_2658, _b_3268, _b_3269, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments_run__climate__model_fun4070__t {
  struct kk_function_s _base;
  kk_integer_t ind;
  kk_string_t name;
  kk_integer_t pt;
  kk_integer_t repeat__ind;
  kk_integer_t rs;
  kk_integer_t sbrs;
  kk_std_core_types__tuple2_ x_2641;
  double diff;
  double subtract;
};
static kk_box_t kk_climate_dash_experiments_run__climate__model_fun4070(kk_function_t _fself, kk_box_t _b_3279, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__climate__model_fun4070(kk_integer_t ind, kk_string_t name, kk_integer_t pt, kk_integer_t repeat__ind, kk_integer_t rs, kk_integer_t sbrs, kk_std_core_types__tuple2_ x_2641, double diff, double subtract, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__climate__model_fun4070__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__climate__model_fun4070__t, 9, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__climate__model_fun4070, kk_context());
  _self->ind = ind;
  _self->name = name;
  _self->pt = pt;
  _self->repeat__ind = repeat__ind;
  _self->rs = rs;
  _self->sbrs = sbrs;
  _self->x_2641 = x_2641;
  _self->diff = diff;
  _self->subtract = subtract;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments_run__climate__model_fun4070(kk_function_t _fself, kk_box_t _b_3279, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__climate__model_fun4070__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__climate__model_fun4070__t*, _fself);
  kk_integer_t ind = _self->ind; /* int */
  kk_string_t name = _self->name; /* string */
  kk_integer_t pt = _self->pt; /* int */
  kk_integer_t repeat__ind = _self->repeat__ind; /* int */
  kk_integer_t rs = _self->rs; /* int */
  kk_integer_t sbrs = _self->sbrs; /* int */
  kk_std_core_types__tuple2_ x_2641 = _self->x_2641; /* (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>) */
  double diff = _self->diff; /* double */
  double subtract = _self->subtract; /* double */
  kk_drop_match(_self, {kk_integer_dup(ind);kk_string_dup(name);kk_integer_dup(pt);kk_integer_dup(repeat__ind);kk_integer_dup(rs);kk_integer_dup(sbrs);kk_std_core_types__tuple2__dup(x_2641);;;}, {}, _ctx)
  kk_unit_t _x4071 = kk_Unit;
  kk_std_core__list _x4072 = kk_std_core__list_unbox(_b_3279, _ctx); /*list<effects-and-types/row_vector>*/
  kk_climate_dash_experiments__mlift2583_run__climate__model(x_2641, diff, ind, name, pt, repeat__ind, rs, sbrs, subtract, _x4072, _ctx);
  return kk_unit_box(_x4071);
}
static kk_box_t kk_climate_dash_experiments_run__climate__model_fun4047(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__climate__model_fun4047__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__climate__model_fun4047__t*, _fself);
  kk_integer_t ind = _self->ind; /* int */
  kk_string_t name = _self->name; /* string */
  kk_integer_t pt = _self->pt; /* int */
  kk_integer_t repeat__ind = _self->repeat__ind; /* int */
  kk_integer_t rs = _self->rs; /* int */
  kk_integer_t sbrs = _self->sbrs; /* int */
  kk_std_core_types__tuple2_ x_2641 = _self->x_2641; /* (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>) */
  double diff = _self->diff; /* double */
  double subtract = _self->subtract; /* double */
  kk_drop_match(_self, {kk_integer_dup(ind);kk_string_dup(name);kk_integer_dup(pt);kk_integer_dup(repeat__ind);kk_integer_dup(rs);kk_integer_dup(sbrs);kk_std_core_types__tuple2__dup(x_2641);;;}, {}, _ctx)
  kk_unit_t _x4048 = kk_Unit;
  kk_std_core__list x1_2655;
  size_t i0_2658 = ((size_t)0); /*std/core/hnd/ev-index*/;
  kk_evv_t w0 = kk_evv_swap_create1(i0_2658,kk_context()); /*std/core/hnd/evv<<exn,div,std/num/random/random,fsys,console,ndet>>*/;
  kk_std_core__list y0;
  kk_std_core_types__maybe _match_3771;
  kk_std_core__list _x4049;
  kk_box_t _box_x3248 = x_2641.fst;
  kk_box_t _box_x3249 = x_2641.snd;
  kk_std_core__list _x = kk_std_core__list_unbox(_box_x3249, NULL);
  kk_std_core__list_dup(_x);
  _x4049 = _x; /*list<list<effects-and-types/row_vector>>*/
  kk_integer_t _x4052 = kk_integer_dup(ind); /*int*/
  _match_3771 = kk_std_core__lp__lb__rb__2_rp_(_x4049, _x4052, _ctx); /*maybe<1>*/
  if (kk_std_core_types__is_Nothing(_match_3771)) {
    kk_string_t message_205;
    kk_string_t _x4053;
    kk_define_string_literal(, _s4054, 48, "ListIndexError: Invalid list indexing at index: ")
    _x4053 = kk_string_dup(_s4054); /*string*/
    kk_string_t _x4055;
    kk_integer_t _x4056 = kk_integer_dup(ind); /*int*/
    _x4055 = kk_std_core_show(_x4056, _ctx); /*string*/
    message_205 = kk_std_core__lp__plus__plus__1_rp_(_x4053, _x4055, _ctx); /*string*/
    kk_std_core__exception exn_21565;
    kk_std_core__exception_info _x4057;
    kk_std_core_types__optional _x4058 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/
    if (kk_std_core_types__is_Optional(_x4058)) {
      kk_box_t _box_x3250 = _x4058._cons.Optional.value;
      kk_std_core__exception_info _info_14279 = kk_std_core__exception_info_unbox(_box_x3250, NULL);
      _x4057 = _info_14279; /*exception-info*/
      goto _match4059;
    }
    _x4057 = kk_std_core__new_ExnError(_ctx); /*exception-info*/
    _match4059: ;
    exn_21565 = kk_std_core__new_Exception(message_205, _x4057, _ctx); /*exception*/
    kk_std_core_hnd__ev ev_21566;
    size_t _x4061 = ((size_t)0); /*size_t*/
    ev_21566 = kk_evv_at(_x4061,kk_context()); /*std/core/hnd/ev<.hnd-exn>*/
    kk_box_t _x4062;
    struct kk_std_core_hnd_Ev* _con4063 = kk_std_core_hnd__as_Ev(ev_21566);
    kk_std_core_hnd__marker m = _con4063->marker;
    kk_box_t _box_x3251 = _con4063->hnd;
    kk_std_core__hnd_exn h = kk_std_core__hnd_exn_unbox(_box_x3251, NULL);
    kk_std_core__hnd_exn_dup(h);
    kk_std_core_hnd__clause1 _match_3772;
    struct kk_std_core__Hnd_exn* _con4065 = kk_std_core__as_Hnd_exn(h);
    kk_std_core_hnd__clause1 except_throw_exn = _con4065->except_throw_exn;
    if (kk_std_core__hnd_exn_is_unique(h)) {
      kk_std_core__hnd_exn_free(h);
    }
    else {
      kk_std_core_hnd__clause1_dup(except_throw_exn);
      kk_std_core__hnd_exn_decref(h, _ctx);
    }
    _match_3772 = except_throw_exn; /*forall<a> std/core/hnd/clause1<exception,a,.hnd-exn,6,7>*/
    kk_function_t _fun_unbox_x3255 = _match_3772.clause;
    _x4062 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x3255, (_fun_unbox_x3255, m, ev_21566, kk_std_core__exception_box(exn_21565, _ctx), _ctx)); /*11*/
    y0 = kk_std_core__list_unbox(_x4062, _ctx); /*list<effects-and-types/row_vector>*/
  }
  else {
    kk_box_t _box_x3259 = _match_3771._cons.Just.value;
    kk_std_core__list x = kk_std_core__list_unbox(_box_x3259, NULL);
    y0 = x; /*list<effects-and-types/row_vector>*/
  }
  kk_unit_t __w_l713_c9 = kk_Unit;
  kk_evv_set(w0,kk_context());
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(y0, _ctx);
    kk_box_t _x4067 = kk_std_core_hnd_yield_cont(kk_climate_dash_experiments_new_run__climate__model_fun4068(i0_2658, _ctx), _ctx); /*3*/
    x1_2655 = kk_std_core__list_unbox(_x4067, _ctx); /*list<effects-and-types/row_vector>*/
  }
  else {
    x1_2655 = y0; /*list<effects-and-types/row_vector>*/
  }
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x1_2655, _ctx);
    kk_box_t _x4069 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments_new_run__climate__model_fun4070(ind, name, pt, repeat__ind, rs, sbrs, x_2641, diff, subtract, _ctx), _ctx); /*2*/
    kk_unit_unbox(_x4069);
  }
  else {
    kk_climate_dash_experiments__mlift2583_run__climate__model(x_2641, diff, ind, name, pt, repeat__ind, rs, sbrs, subtract, x1_2655, _ctx);
  }
  return kk_unit_box(_x4048);
}
static kk_unit_t kk_climate_dash_experiments_run__climate__model_fun4040(kk_function_t _fself, kk_integer_t repeat__ind, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__climate__model_fun4040__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__climate__model_fun4040__t*, _fself);
  kk_box_t _b_3285 = _self->_b_3285; /* 1 */
  kk_integer_t pt = _self->pt; /* int */
  kk_integer_t rs = _self->rs; /* int */
  kk_integer_t sbrs = _self->sbrs; /* int */
  kk_std_core_types__tuple2_ x_2641 = _self->x_2641; /* (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>) */
  kk_drop_match(_self, {kk_box_dup(_b_3285);kk_integer_dup(pt);kk_integer_dup(rs);kk_integer_dup(sbrs);kk_std_core_types__tuple2__dup(x_2641);}, {}, _ctx)
  kk_box_t _x4041;
  kk_std_core_types__tuple2_ _match_3768 = kk_std_core_types__tuple2__unbox(_b_3285, _ctx); /*(int, (double, double, string))*/;
  kk_box_t _box_x3243 = _match_3768.fst;
  kk_box_t _box_x3244 = _match_3768.snd;
  kk_integer_t ind = kk_integer_unbox(_box_x3243);
  kk_std_core_types__tuple3_ _pat20 = kk_std_core_types__tuple3__unbox(_box_x3244, NULL);
  kk_box_t _box_x3245 = _pat20.fst;
  kk_box_t _box_x3246 = _pat20.snd;
  kk_box_t _box_x3247 = _pat20.thd;
  double diff = kk_double_unbox(_box_x3245, NULL);
  double subtract = kk_double_unbox(_box_x3246, NULL);
  kk_string_t name = kk_string_unbox(_box_x3247);
  kk_integer_dup(ind);
  kk_string_dup(name);
  kk_std_core_types__tuple2__drop(_match_3768, _ctx);
  _x4041 = kk_std_time_timer_print_elapsed(kk_climate_dash_experiments_new_run__climate__model_fun4047(ind, name, pt, repeat__ind, rs, sbrs, x_2641, diff, subtract, _ctx), kk_std_core_types__new_None(_ctx), _ctx); /*453*/
  return kk_unit_unbox(_x4041);
}
static kk_box_t kk_climate_dash_experiments_run__climate__model_fun4038(kk_function_t _fself, kk_box_t _b_3285, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__climate__model_fun4038__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__climate__model_fun4038__t*, _fself);
  kk_integer_t pt = _self->pt; /* int */
  kk_std_core_types__optional repeat__num = _self->repeat__num; /* optional<int> */
  kk_integer_t rs = _self->rs; /* int */
  kk_integer_t sbrs = _self->sbrs; /* int */
  kk_std_core_types__tuple2_ x_2641 = _self->x_2641; /* (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>) */
  kk_drop_match(_self, {kk_integer_dup(pt);kk_std_core_types__optional_dup(repeat__num);kk_integer_dup(rs);kk_integer_dup(sbrs);kk_std_core_types__tuple2__dup(x_2641);}, {}, _ctx)
  kk_unit_t _x4039 = kk_Unit;
  kk_integer_t _x4073;
  if (kk_std_core_types__is_Optional(repeat__num)) {
    kk_box_t _box_x3282 = repeat__num._cons.Optional.value;
    kk_integer_t _repeat__num_20 = kk_integer_unbox(_box_x3282);
    _x4073 = _repeat__num_20; /*int*/
    goto _match4074;
  }
  _x4073 = kk_integer_from_small(8); /*int*/
  _match4074: ;
  kk_std_core__lift21056_for(kk_climate_dash_experiments_new_run__climate__model_fun4040(_b_3285, pt, rs, sbrs, x_2641, _ctx), _x4073, kk_integer_from_small(1), _ctx);
  return kk_unit_box(_x4039);
}


// lift anonymous function
struct kk_climate_dash_experiments_run__climate__model_fun4077__t {
  struct kk_function_s _base;
};
static kk_box_t kk_climate_dash_experiments_run__climate__model_fun4077(kk_function_t _fself, kk_box_t _b_3294, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__climate__model_fun4077(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_climate_dash_experiments_run__climate__model_fun4077, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_climate_dash_experiments_run__climate__model_fun4077(kk_function_t _fself, kk_box_t _b_3294, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_unit_t _x4078 = kk_Unit;
  kk_std_core__list _x4079 = kk_std_core__list_unbox(_b_3294, _ctx); /*list<()>*/
  kk_climate_dash_experiments__mlift2584_run__climate__model(_x4079, _ctx);
  return kk_unit_box(_x4078);
}
static kk_box_t kk_climate_dash_experiments_run__climate__model_fun4033(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__climate__model_fun4033__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__climate__model_fun4033__t*, _fself);
  kk_std_core__list pre__data = _self->pre__data; /* list<(double, double, string)> */
  kk_integer_t pt = _self->pt; /* int */
  kk_std_core_types__optional repeat__num = _self->repeat__num; /* optional<int> */
  kk_integer_t rs = _self->rs; /* int */
  kk_integer_t sbrs = _self->sbrs; /* int */
  kk_std_core_types__tuple2_ x_2641 = _self->x_2641; /* (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>) */
  kk_drop_match(_self, {kk_std_core__list_dup(pre__data);kk_integer_dup(pt);kk_std_core_types__optional_dup(repeat__num);kk_integer_dup(rs);kk_integer_dup(sbrs);kk_std_core_types__tuple2__dup(x_2641);}, {}, _ctx)
  kk_unit_t _x4034 = kk_Unit;
  kk_unit_t __ = kk_Unit;
  kk_string_t _x4035;
  kk_define_string_literal(, _s4036, 10, "Begin SMC:")
  _x4035 = kk_string_dup(_s4036); /*string*/
  kk_std_core_printsln(_x4035, _ctx);
  kk_std_core__list x0_2648;
  kk_std_core__list _b_3286_3283;
  kk_std_core__list _x4037 = kk_std_core__lift21053_list(kk_integer_from_small(0), kk_integer_from_small(11), kk_std_core__new_Nil(_ctx), _ctx); /*list<int>*/
  _b_3286_3283 = kk_std_core_zip(_x4037, pre__data, _ctx); /*list<(int, (double, double, string))>*/
  x0_2648 = kk_std_core_map_5(_b_3286_3283, kk_climate_dash_experiments_new_run__climate__model_fun4038(pt, repeat__num, rs, sbrs, x_2641, _ctx), _ctx); /*list<()>*/
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x0_2648, _ctx);
    kk_box_t _x4076 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments_new_run__climate__model_fun4077(_ctx), _ctx); /*2*/
    kk_unit_unbox(_x4076);
  }
  else {
    kk_climate_dash_experiments__mlift2584_run__climate__model(x0_2648, _ctx);
  }
  return kk_unit_box(_x4034);
}

kk_unit_t kk_climate_dash_experiments_run__climate__model(kk_integer_t pt, kk_integer_t rs, kk_integer_t sbrs, kk_integer_t t__steps, kk_integer_t burnin, kk_std_core_types__optional repeat__num, kk_context_t* _ctx) { /* (pt : int, rs : int, sbrs : int, t_steps : int, burnin : int, repeat_num : optional<int>) -> <pure,console,fsys,ndet,std/num/random/random> () */ 
  kk_integer_drop(burnin, _ctx);
  kk_integer_drop(t__steps, _ctx);
  kk_std_core_types__tuple2_ x_2641;
  size_t i_2644 = ((size_t)0); /*std/core/hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_2644,kk_context()); /*std/core/hnd/evv<<div,exn,fsys,console,ndet,std/num/random/random>>*/;
  kk_std_core_types__tuple2_ y = kk_data_preprocessing_pre__process__data(_ctx); /*(list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>)*/;
  kk_unit_t __w_l679_c9 = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_std_core_types__tuple2__drop(y, _ctx);
    kk_box_t _x3990 = kk_std_core_hnd_yield_cont(kk_climate_dash_experiments_new_run__climate__model_fun3991(i_2644, _ctx), _ctx); /*3*/
    x_2641 = kk_std_core_types__tuple2__unbox(_x3990, _ctx); /*(list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>)*/
  }
  else {
    x_2641 = y; /*(list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>)*/
  }
  if (kk_yielding(kk_context())) {
    kk_std_core_types__tuple2__drop(x_2641, _ctx);
    kk_box_t _x3992 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments_new_run__climate__model_fun3993(pt, repeat__num, rs, sbrs, _ctx), _ctx); /*2*/
    kk_unit_unbox(_x3992); return kk_Unit;
  }
  kk_std_core__list pre__data;
  kk_std_core_types__tuple3_ _b_3183_3181;
  kk_box_t _x3996;
  kk_string_t _x3997;
  kk_define_string_literal(, _s3998, 3, "jan")
  _x3997 = kk_string_dup(_s3998); /*string*/
  _x3996 = kk_string_box(_x3997); /*10*/
  _b_3183_3181 = kk_std_core_types__new_dash__lp__comma__comma__rp_(kk_double_box(0x1.4p3, _ctx), kk_double_box(-0x1.8p1, _ctx), _x3996, _ctx); /*(double, double, string)*/
  kk_std_core__list _b_3184_3182;
  kk_std_core_types__tuple3_ _b_3188_3179;
  kk_box_t _x3999;
  kk_string_t _x4000;
  kk_define_string_literal(, _s4001, 3, "feb")
  _x4000 = kk_string_dup(_s4001); /*string*/
  _x3999 = kk_string_box(_x4000); /*10*/
  _b_3188_3179 = kk_std_core_types__new_dash__lp__comma__comma__rp_(kk_double_box(0x1p3, _ctx), kk_double_box(-0x1p0, _ctx), _x3999, _ctx); /*(double, double, string)*/
  kk_std_core__list _b_3189_3180;
  kk_std_core_types__tuple3_ _b_3193_3177;
  kk_box_t _x4002;
  kk_string_t _x4003;
  kk_define_string_literal(, _s4004, 3, "mar")
  _x4003 = kk_string_dup(_s4004); /*string*/
  _x4002 = kk_string_box(_x4003); /*10*/
  _b_3193_3177 = kk_std_core_types__new_dash__lp__comma__comma__rp_(kk_double_box(0x1.cp2, _ctx), kk_double_box(0x1p0, _ctx), _x4002, _ctx); /*(double, double, string)*/
  kk_std_core__list _b_3194_3178;
  kk_std_core_types__tuple3_ _b_3198_3175;
  kk_box_t _x4005;
  kk_string_t _x4006;
  kk_define_string_literal(, _s4007, 3, "apr")
  _x4006 = kk_string_dup(_s4007); /*string*/
  _x4005 = kk_string_box(_x4006); /*10*/
  _b_3198_3175 = kk_std_core_types__new_dash__lp__comma__comma__rp_(kk_double_box(0x1.8p2, _ctx), kk_double_box(0x1.4p2, _ctx), _x4005, _ctx); /*(double, double, string)*/
  kk_std_core__list _b_3199_3176;
  kk_std_core_types__tuple3_ _b_3203_3173;
  kk_box_t _x4008;
  kk_string_t _x4009;
  kk_define_string_literal(, _s4010, 3, "may")
  _x4009 = kk_string_dup(_s4010); /*string*/
  _x4008 = kk_string_box(_x4009); /*10*/
  _b_3203_3173 = kk_std_core_types__new_dash__lp__comma__comma__rp_(kk_double_box(0x1p3, _ctx), kk_double_box(0x1.2p3, _ctx), _x4008, _ctx); /*(double, double, string)*/
  kk_std_core__list _b_3204_3174;
  kk_std_core_types__tuple3_ _b_3208_3171;
  kk_box_t _x4011;
  kk_string_t _x4012;
  kk_define_string_literal(, _s4013, 3, "jun")
  _x4012 = kk_string_dup(_s4013); /*string*/
  _x4011 = kk_string_box(_x4012); /*10*/
  _b_3208_3171 = kk_std_core_types__new_dash__lp__comma__comma__rp_(kk_double_box(0x1p3, _ctx), kk_double_box(0x1.4p3, _ctx), _x4011, _ctx); /*(double, double, string)*/
  kk_std_core__list _b_3209_3172;
  kk_std_core_types__tuple3_ _b_3213_3169;
  kk_box_t _x4014;
  kk_string_t _x4015;
  kk_define_string_literal(, _s4016, 3, "jul")
  _x4015 = kk_string_dup(_s4016); /*string*/
  _x4014 = kk_string_box(_x4015); /*10*/
  _b_3213_3169 = kk_std_core_types__new_dash__lp__comma__comma__rp_(kk_double_box(0x1.2p3, _ctx), kk_double_box(0x1.6p3, _ctx), _x4014, _ctx); /*(double, double, string)*/
  kk_std_core__list _b_3214_3170;
  kk_std_core_types__tuple3_ _b_3218_3167;
  kk_box_t _x4017;
  kk_string_t _x4018;
  kk_define_string_literal(, _s4019, 3, "aug")
  _x4018 = kk_string_dup(_s4019); /*string*/
  _x4017 = kk_string_box(_x4018); /*10*/
  _b_3218_3167 = kk_std_core_types__new_dash__lp__comma__comma__rp_(kk_double_box(0x1.8p2, _ctx), kk_double_box(0x1.6p3, _ctx), _x4017, _ctx); /*(double, double, string)*/
  kk_std_core__list _b_3219_3168;
  kk_std_core_types__tuple3_ _b_3223_3165;
  kk_box_t _x4020;
  kk_string_t _x4021;
  kk_define_string_literal(, _s4022, 3, "sep")
  _x4021 = kk_string_dup(_s4022); /*string*/
  _x4020 = kk_string_box(_x4021); /*10*/
  _b_3223_3165 = kk_std_core_types__new_dash__lp__comma__comma__rp_(kk_double_box(0x1.4p2, _ctx), kk_double_box(0x1.4p3, _ctx), _x4020, _ctx); /*(double, double, string)*/
  kk_std_core__list _b_3224_3166;
  kk_std_core_types__tuple3_ _b_3228_3163;
  kk_box_t _x4023;
  kk_string_t _x4024;
  kk_define_string_literal(, _s4025, 3, "oct")
  _x4024 = kk_string_dup(_s4025); /*string*/
  _x4023 = kk_string_box(_x4024); /*10*/
  _b_3228_3163 = kk_std_core_types__new_dash__lp__comma__comma__rp_(kk_double_box(0x1.2p3, _ctx), kk_double_box(0x1p0, _ctx), _x4023, _ctx); /*(double, double, string)*/
  kk_std_core__list _b_3229_3164;
  kk_std_core_types__tuple3_ _b_3233_3161;
  kk_box_t _x4026;
  kk_string_t _x4027;
  kk_define_string_literal(, _s4028, 3, "nov")
  _x4027 = kk_string_dup(_s4028); /*string*/
  _x4026 = kk_string_box(_x4027); /*10*/
  _b_3233_3161 = kk_std_core_types__new_dash__lp__comma__comma__rp_(kk_double_box(0x1.cp2, _ctx), kk_double_box(0x1p1, _ctx), _x4026, _ctx); /*(double, double, string)*/
  kk_std_core__list _b_3234_3162;
  kk_std_core_types__tuple3_ _b_3238_3159;
  kk_box_t _x4029;
  kk_string_t _x4030;
  kk_define_string_literal(, _s4031, 3, "dec")
  _x4030 = kk_string_dup(_s4031); /*string*/
  _x4029 = kk_string_box(_x4030); /*10*/
  _b_3238_3159 = kk_std_core_types__new_dash__lp__comma__comma__rp_(kk_double_box(0x1.8p2, _ctx), kk_double_box(-0x1p0, _ctx), _x4029, _ctx); /*(double, double, string)*/
  _b_3234_3162 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core_types__tuple3__box(_b_3238_3159, _ctx), kk_std_core__new_Nil(_ctx), _ctx); /*list<(double, double, string)>*/
  _b_3229_3164 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core_types__tuple3__box(_b_3233_3161, _ctx), _b_3234_3162, _ctx); /*list<(double, double, string)>*/
  _b_3224_3166 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core_types__tuple3__box(_b_3228_3163, _ctx), _b_3229_3164, _ctx); /*list<(double, double, string)>*/
  _b_3219_3168 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core_types__tuple3__box(_b_3223_3165, _ctx), _b_3224_3166, _ctx); /*list<(double, double, string)>*/
  _b_3214_3170 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core_types__tuple3__box(_b_3218_3167, _ctx), _b_3219_3168, _ctx); /*list<(double, double, string)>*/
  _b_3209_3172 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core_types__tuple3__box(_b_3213_3169, _ctx), _b_3214_3170, _ctx); /*list<(double, double, string)>*/
  _b_3204_3174 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core_types__tuple3__box(_b_3208_3171, _ctx), _b_3209_3172, _ctx); /*list<(double, double, string)>*/
  _b_3199_3176 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core_types__tuple3__box(_b_3203_3173, _ctx), _b_3204_3174, _ctx); /*list<(double, double, string)>*/
  _b_3194_3178 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core_types__tuple3__box(_b_3198_3175, _ctx), _b_3199_3176, _ctx); /*list<(double, double, string)>*/
  _b_3189_3180 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core_types__tuple3__box(_b_3193_3177, _ctx), _b_3194_3178, _ctx); /*list<(double, double, string)>*/
  _b_3184_3182 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core_types__tuple3__box(_b_3188_3179, _ctx), _b_3189_3180, _ctx); /*list<(double, double, string)>*/
  pre__data = kk_std_core__new_Cons(kk_reuse_null, kk_std_core_types__tuple3__box(_b_3183_3181, _ctx), _b_3184_3182, _ctx); /*list<(double, double, string)>*/
  kk_box_t _x4032 = kk_std_time_timer_print_elapsed(kk_climate_dash_experiments_new_run__climate__model_fun4033(pre__data, pt, repeat__num, rs, sbrs, x_2641, _ctx), kk_std_core_types__new_None(_ctx), _ctx); /*453*/
  kk_unit_unbox(_x4032); return kk_Unit;
}
 
// monadic lift

kk_unit_t kk_climate_dash_experiments__mlift2586_run__experiments(kk_std_core__list wild__7, kk_context_t* _ctx) { /* (wild_7 : list<(list<(list<double>, (double, double))>, trace/trace<(double, double),<effects-and-types/sample,effects-and-types/score,div,console,ndet,exn,std/num/random/random>>)>) -> <ndet,console,div,effects-and-types/sample,exn,std/num/random/random> () */ 
  kk_std_core__list_drop(wild__7, _ctx);
  kk_string_t _x4080;
  kk_define_string_literal(, _s4081, 21, "Completed Trace MCMC!")
  _x4080 = kk_string_dup(_s4081); /*string*/
  kk_std_core_printsln(_x4080, _ctx); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_climate_dash_experiments__mlift2587_run__experiments_fun4085__t {
  struct kk_function_s _base;
  kk_std_core__list data__50;
  kk_std_core__list data__points;
};
static kk_box_t kk_climate_dash_experiments__mlift2587_run__experiments_fun4085(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift2587_run__experiments_fun4085(kk_std_core__list data__50, kk_std_core__list data__points, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2587_run__experiments_fun4085__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift2587_run__experiments_fun4085__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift2587_run__experiments_fun4085, kk_context());
  _self->data__50 = data__50;
  _self->data__points = data__points;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift2587_run__experiments_fun4087__t {
  struct kk_function_s _base;
  kk_std_core__list data__50;
};
static kk_box_t kk_climate_dash_experiments__mlift2587_run__experiments_fun4087(kk_function_t _fself, kk_box_t _b_3327, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift2587_run__experiments_fun4087(kk_std_core__list data__50, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2587_run__experiments_fun4087__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift2587_run__experiments_fun4087__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift2587_run__experiments_fun4087, kk_context());
  _self->data__50 = data__50;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift2587_run__experiments_fun4090__t {
  struct kk_function_s _base;
  kk_std_core__list data__50;
  kk_integer_t sz1;
};
static kk_box_t kk_climate_dash_experiments__mlift2587_run__experiments_fun4090(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift2587_run__experiments_fun4090(kk_std_core__list data__50, kk_integer_t sz1, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2587_run__experiments_fun4090__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift2587_run__experiments_fun4090__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift2587_run__experiments_fun4090, kk_context());
  _self->data__50 = data__50;
  _self->sz1 = sz1;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift2587_run__experiments_fun4093__t {
  struct kk_function_s _base;
};
static kk_box_t kk_climate_dash_experiments__mlift2587_run__experiments_fun4093(kk_function_t _fself, kk_box_t _b_3306, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift2587_run__experiments_fun4093(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_climate_dash_experiments__mlift2587_run__experiments_fun4093, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift2587_run__experiments_fun4096__t {
  struct kk_function_s _base;
  kk_function_t _bv_3308;
};
static kk_box_t kk_climate_dash_experiments__mlift2587_run__experiments_fun4096(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift2587_run__experiments_fun4096(kk_function_t _bv_3308, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2587_run__experiments_fun4096__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift2587_run__experiments_fun4096__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift2587_run__experiments_fun4096, kk_context());
  _self->_bv_3308 = _bv_3308;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift2587_run__experiments_fun4096(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2587_run__experiments_fun4096__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift2587_run__experiments_fun4096__t*, _fself);
  kk_function_t _bv_3308 = _self->_bv_3308; /* effects-and-types/model<(double, double),div> */
  kk_drop_match(_self, {kk_function_dup(_bv_3308);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x4097 = kk_function_call(kk_std_core_types__tuple2_, (kk_function_t, kk_context_t*), _bv_3308, (_bv_3308, _ctx)); /*(double, double)*/
  return kk_std_core_types__tuple2__box(_x4097, _ctx);
}
static kk_box_t kk_climate_dash_experiments__mlift2587_run__experiments_fun4093(kk_function_t _fself, kk_box_t _b_3306, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_function_t _x4094;
  kk_function_t _bv_3308;
  kk_std_core__list _x4095 = kk_std_core__list_unbox(_b_3306, _ctx); /*list<(double, bool)>*/
  _bv_3308 = kk_model_dash_resources_logistic__regression(_x4095, _ctx); /*effects-and-types/model<(double, double),div>*/
  _x4094 = kk_climate_dash_experiments__new_mlift2587_run__experiments_fun4096(_bv_3308, _ctx); /*() -> <div,effects-and-types/sample,effects-and-types/score> 3307*/
  return kk_function_box(_x4094);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift2587_run__experiments_fun4098__t {
  struct kk_function_s _base;
  kk_function_t _bv_3310;
};
static kk_std_core_types__tuple2_ kk_climate_dash_experiments__mlift2587_run__experiments_fun4098(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift2587_run__experiments_fun4098(kk_function_t _bv_3310, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2587_run__experiments_fun4098__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift2587_run__experiments_fun4098__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift2587_run__experiments_fun4098, kk_context());
  _self->_bv_3310 = _bv_3310;
  return &_self->_base;
}

static kk_std_core_types__tuple2_ kk_climate_dash_experiments__mlift2587_run__experiments_fun4098(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2587_run__experiments_fun4098__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift2587_run__experiments_fun4098__t*, _fself);
  kk_function_t _bv_3310 = _self->_bv_3310; /* () -> <.Box|.Box> 3309 */
  kk_drop_match(_self, {kk_function_dup(_bv_3310);}, {}, _ctx)
  kk_box_t _x4099 = kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), _bv_3310, (_bv_3310, _ctx)); /*3309*/
  return kk_std_core_types__tuple2__unbox(_x4099, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift2587_run__experiments_fun4100__t {
  struct kk_function_s _base;
  kk_function_t _x07_2579;
};
static kk_std_core_types__tuple2_ kk_climate_dash_experiments__mlift2587_run__experiments_fun4100(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift2587_run__experiments_fun4100(kk_function_t _x07_2579, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2587_run__experiments_fun4100__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift2587_run__experiments_fun4100__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift2587_run__experiments_fun4100, kk_context());
  _self->_x07_2579 = _x07_2579;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift2587_run__experiments_fun4103__t {
  struct kk_function_s _base;
  kk_function_t _x07_2579;
};
static kk_box_t kk_climate_dash_experiments__mlift2587_run__experiments_fun4103(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift2587_run__experiments_fun4103(kk_function_t _x07_2579, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2587_run__experiments_fun4103__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift2587_run__experiments_fun4103__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift2587_run__experiments_fun4103, kk_context());
  _self->_x07_2579 = _x07_2579;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift2587_run__experiments_fun4103(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2587_run__experiments_fun4103__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift2587_run__experiments_fun4103__t*, _fself);
  kk_function_t _x07_2579 = _self->_x07_2579; /* effects-and-types/model<(double, double),div> */
  kk_drop_match(_self, {kk_function_dup(_x07_2579);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x4104 = kk_function_call(kk_std_core_types__tuple2_, (kk_function_t, kk_context_t*), _x07_2579, (_x07_2579, _ctx)); /*(double, double)*/
  return kk_std_core_types__tuple2__box(_x4104, _ctx);
}
static kk_std_core_types__tuple2_ kk_climate_dash_experiments__mlift2587_run__experiments_fun4100(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2587_run__experiments_fun4100__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift2587_run__experiments_fun4100__t*, _fself);
  kk_function_t _x07_2579 = _self->_x07_2579; /* effects-and-types/model<(double, double),div> */
  kk_drop_match(_self, {kk_function_dup(_x07_2579);}, {}, _ctx)
  kk_vector_t _b_3341_3317;
  kk_std_core__list _x4101;
  size_t _b_3343_3315 = ((size_t)2); /*std/core/hnd/ev-index*/;
  kk_std_core__list _b_3344_3316;
  size_t _b_3345_3313 = ((size_t)3); /*std/core/hnd/ev-index*/;
  _b_3344_3316 = kk_std_core__new_Cons(kk_reuse_null, kk_size_box(_b_3345_3313, _ctx), kk_std_core__new_Nil(_ctx), _ctx); /*list<std/core/hnd/ev-index>*/
  _x4101 = kk_std_core__new_Cons(kk_reuse_null, kk_size_box(_b_3343_3315, _ctx), _b_3344_3316, _ctx); /*list<0>*/
  _b_3341_3317 = kk_std_core_unvlist(_x4101, _ctx); /*vector<std/core/hnd/ev-index>*/
  kk_box_t _x4102 = kk_std_core_hnd__open0(_b_3341_3317, kk_climate_dash_experiments__new_mlift2587_run__experiments_fun4103(_x07_2579, _ctx), _ctx); /*1*/
  return kk_std_core_types__tuple2__unbox(_x4102, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift2587_run__experiments_fun4105__t {
  struct kk_function_s _base;
  kk_function_t _b_3337_3319;
};
static kk_box_t kk_climate_dash_experiments__mlift2587_run__experiments_fun4105(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift2587_run__experiments_fun4105(kk_function_t _b_3337_3319, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2587_run__experiments_fun4105__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift2587_run__experiments_fun4105__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift2587_run__experiments_fun4105, kk_context());
  _self->_b_3337_3319 = _b_3337_3319;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift2587_run__experiments_fun4105(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2587_run__experiments_fun4105__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift2587_run__experiments_fun4105__t*, _fself);
  kk_function_t _b_3337_3319 = _self->_b_3337_3319; /* () -> <div,effects-and-types/sample,effects-and-types/score> (double, double) */
  kk_drop_match(_self, {kk_function_dup(_b_3337_3319);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x4106 = kk_function_call(kk_std_core_types__tuple2_, (kk_function_t, kk_context_t*), _b_3337_3319, (_b_3337_3319, _ctx)); /*(double, double)*/
  return kk_std_core_types__tuple2__box(_x4106, _ctx);
}
static kk_box_t kk_climate_dash_experiments__mlift2587_run__experiments_fun4090(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2587_run__experiments_fun4090__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift2587_run__experiments_fun4090__t*, _fself);
  kk_std_core__list data__50 = _self->data__50; /* list<(double, bool)> */
  kk_integer_t sz1 = _self->sz1; /* int */
  kk_drop_match(_self, {kk_std_core__list_dup(data__50);kk_integer_dup(sz1);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x4091;
  kk_function_t _b_3337_3319;
  kk_function_t _x07_2579;
  kk_function_t _bv_3310;
  kk_box_t _x4092 = kk_std_core_hnd__open_none1(kk_climate_dash_experiments__new_mlift2587_run__experiments_fun4093(_ctx), kk_std_core__list_box(data__50, _ctx), _ctx); /*2*/
  _bv_3310 = kk_function_unbox(_x4092); /*() -> <.Box|.Box> 3309*/
  _x07_2579 = kk_climate_dash_experiments__new_mlift2587_run__experiments_fun4098(_bv_3310, _ctx); /*effects-and-types/model<(double, double),div>*/
  _b_3337_3319 = kk_climate_dash_experiments__new_mlift2587_run__experiments_fun4100(_x07_2579, _ctx); /*() -> <div,effects-and-types/sample,effects-and-types/score> (double, double)*/
  kk_effects_dash_and_dash_types__exp _b_3339_3321 = kk_effects_dash_and_dash_types__new_Exp(0x0p+0, _ctx); /*effects-and-types/exp*/;
  _x4091 = kk_trace_tmcmc(kk_climate_dash_experiments__new_mlift2587_run__experiments_fun4105(_b_3337_3319, _ctx), sz1, _b_3339_3321, kk_integer_from_small(0), _ctx); /*(list<(list<double>, 1382)>, trace/trace<1382,<effects-and-types/sample,effects-and-types/score,div|1383>>)*/
  return kk_std_core_types__tuple2__box(_x4091, _ctx);
}
static kk_box_t kk_climate_dash_experiments__mlift2587_run__experiments_fun4087(kk_function_t _fself, kk_box_t _b_3327, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2587_run__experiments_fun4087__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift2587_run__experiments_fun4087__t*, _fself);
  kk_std_core__list data__50 = _self->data__50; /* list<(double, bool)> */
  kk_drop_match(_self, {kk_std_core__list_dup(data__50);}, {}, _ctx)
  kk_std_core_types__tuple2_ _match_3765 = kk_std_core_types__tuple2__unbox(_b_3327, _ctx); /*(int, list<(double, bool)>)*/;
  kk_box_t _box_x3302 = _match_3765.fst;
  kk_box_t _box_x3303 = _match_3765.snd;
  kk_integer_t sz1 = kk_integer_unbox(_box_x3302);
  kk_integer_dup(sz1);
  kk_std_core_types__tuple2__drop(_match_3765, _ctx);
  return kk_std_time_timer_print_elapsed(kk_climate_dash_experiments__new_mlift2587_run__experiments_fun4090(data__50, sz1, _ctx), kk_std_core_types__new_None(_ctx), _ctx);
}
static kk_box_t kk_climate_dash_experiments__mlift2587_run__experiments_fun4085(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2587_run__experiments_fun4085__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift2587_run__experiments_fun4085__t*, _fself);
  kk_std_core__list data__50 = _self->data__50; /* list<(double, bool)> */
  kk_std_core__list data__points = _self->data__points; /* list<(int, list<(double, bool)>)> */
  kk_drop_match(_self, {kk_std_core__list_dup(data__50);kk_std_core__list_dup(data__points);}, {}, _ctx)
  kk_std_core__list _x4086 = kk_std_core_map_5(data__points, kk_climate_dash_experiments__new_mlift2587_run__experiments_fun4087(data__50, _ctx), _ctx); /*list<2>*/
  return kk_std_core__list_box(_x4086, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift2587_run__experiments_fun4108__t {
  struct kk_function_s _base;
};
static kk_box_t kk_climate_dash_experiments__mlift2587_run__experiments_fun4108(kk_function_t _fself, kk_box_t _b_3348, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift2587_run__experiments_fun4108(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_climate_dash_experiments__mlift2587_run__experiments_fun4108, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_climate_dash_experiments__mlift2587_run__experiments_fun4108(kk_function_t _fself, kk_box_t _b_3348, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_unit_t _x4109 = kk_Unit;
  kk_std_core__list _x4110 = kk_std_core__list_unbox(_b_3348, _ctx); /*list<(list<(list<double>, (double, double))>, trace/trace<(double, double),<effects-and-types/sample,effects-and-types/score,div,console,ndet,exn,std/num/random/random>>)>*/
  kk_climate_dash_experiments__mlift2586_run__experiments(_x4110, _ctx);
  return kk_unit_box(_x4109);
}

kk_unit_t kk_climate_dash_experiments__mlift2587_run__experiments(kk_std_core__list data__50, kk_std_core__list data__points, kk_std_core__list wild__5, kk_context_t* _ctx) { /* (data_50 : list<(double, bool)>, data_points : list<(int, list<(double, bool)>)>, wild_5 : list<(list<(list<double>, (double, double))>, trace/trace<(double, double),<effects-and-types/sample,effects-and-types/score,div,console,ndet,exn,std/num/random/random>>)>) -> <ndet,console,div,effects-and-types/sample,exn,std/num/random/random> () */ 
  kk_std_core__list_drop(wild__5, _ctx);
  kk_unit_t __6 = kk_Unit;
  kk_string_t _x4082;
  kk_define_string_literal(, _s4083, 7, "Mid-way")
  _x4082 = kk_string_dup(_s4083); /*string*/
  kk_std_core_printsln(_x4082, _ctx);
  kk_std_core__list x_2664;
  kk_box_t _x4084 = kk_std_time_timer_print_elapsed(kk_climate_dash_experiments__new_mlift2587_run__experiments_fun4085(data__50, data__points, _ctx), kk_std_core_types__new_None(_ctx), _ctx); /*453*/
  x_2664 = kk_std_core__list_unbox(_x4084, _ctx); /*list<(list<(list<double>, (double, double))>, trace/trace<(double, double),<effects-and-types/sample,effects-and-types/score,div,console,ndet,exn,std/num/random/random>>)>*/
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_2664, _ctx);
    kk_box_t _x4107 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments__new_mlift2587_run__experiments_fun4108(_ctx), _ctx); /*2*/
    kk_unit_unbox(_x4107); return kk_Unit;
  }
  kk_climate_dash_experiments__mlift2586_run__experiments(x_2664, _ctx); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_climate_dash_experiments__mlift2588_run__experiments_fun4113__t {
  struct kk_function_s _base;
  kk_std_core__list data__50;
};
static kk_box_t kk_climate_dash_experiments__mlift2588_run__experiments_fun4113(kk_function_t _fself, kk_box_t _b_3394, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift2588_run__experiments_fun4113(kk_std_core__list data__50, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2588_run__experiments_fun4113__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift2588_run__experiments_fun4113__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift2588_run__experiments_fun4113, kk_context());
  _self->data__50 = data__50;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift2588_run__experiments_fun4116__t {
  struct kk_function_s _base;
  kk_std_core__list data__50;
  kk_integer_t sz0;
};
static kk_box_t kk_climate_dash_experiments__mlift2588_run__experiments_fun4116(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift2588_run__experiments_fun4116(kk_std_core__list data__50, kk_integer_t sz0, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2588_run__experiments_fun4116__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift2588_run__experiments_fun4116__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift2588_run__experiments_fun4116, kk_context());
  _self->data__50 = data__50;
  _self->sz0 = sz0;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift2588_run__experiments_fun4119__t {
  struct kk_function_s _base;
};
static kk_box_t kk_climate_dash_experiments__mlift2588_run__experiments_fun4119(kk_function_t _fself, kk_box_t _b_3354, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift2588_run__experiments_fun4119(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_climate_dash_experiments__mlift2588_run__experiments_fun4119, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift2588_run__experiments_fun4122__t {
  struct kk_function_s _base;
  kk_function_t _bv_3356;
};
static kk_box_t kk_climate_dash_experiments__mlift2588_run__experiments_fun4122(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift2588_run__experiments_fun4122(kk_function_t _bv_3356, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2588_run__experiments_fun4122__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift2588_run__experiments_fun4122__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift2588_run__experiments_fun4122, kk_context());
  _self->_bv_3356 = _bv_3356;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift2588_run__experiments_fun4122(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2588_run__experiments_fun4122__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift2588_run__experiments_fun4122__t*, _fself);
  kk_function_t _bv_3356 = _self->_bv_3356; /* effects-and-types/model<(double, double),div> */
  kk_drop_match(_self, {kk_function_dup(_bv_3356);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x4123 = kk_function_call(kk_std_core_types__tuple2_, (kk_function_t, kk_context_t*), _bv_3356, (_bv_3356, _ctx)); /*(double, double)*/
  return kk_std_core_types__tuple2__box(_x4123, _ctx);
}
static kk_box_t kk_climate_dash_experiments__mlift2588_run__experiments_fun4119(kk_function_t _fself, kk_box_t _b_3354, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_function_t _x4120;
  kk_function_t _bv_3356;
  kk_std_core__list _x4121 = kk_std_core__list_unbox(_b_3354, _ctx); /*list<(double, bool)>*/
  _bv_3356 = kk_model_dash_resources_logistic__regression(_x4121, _ctx); /*effects-and-types/model<(double, double),div>*/
  _x4120 = kk_climate_dash_experiments__new_mlift2588_run__experiments_fun4122(_bv_3356, _ctx); /*() -> <div,effects-and-types/sample,effects-and-types/score> 3355*/
  return kk_function_box(_x4120);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift2588_run__experiments_fun4124__t {
  struct kk_function_s _base;
  kk_function_t _bv_3358;
};
static kk_std_core_types__tuple2_ kk_climate_dash_experiments__mlift2588_run__experiments_fun4124(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift2588_run__experiments_fun4124(kk_function_t _bv_3358, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2588_run__experiments_fun4124__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift2588_run__experiments_fun4124__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift2588_run__experiments_fun4124, kk_context());
  _self->_bv_3358 = _bv_3358;
  return &_self->_base;
}

static kk_std_core_types__tuple2_ kk_climate_dash_experiments__mlift2588_run__experiments_fun4124(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2588_run__experiments_fun4124__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift2588_run__experiments_fun4124__t*, _fself);
  kk_function_t _bv_3358 = _self->_bv_3358; /* () -> <.Box|.Box> 3357 */
  kk_drop_match(_self, {kk_function_dup(_bv_3358);}, {}, _ctx)
  kk_box_t _x4125 = kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), _bv_3358, (_bv_3358, _ctx)); /*3357*/
  return kk_std_core_types__tuple2__unbox(_x4125, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift2588_run__experiments_fun4126__t {
  struct kk_function_s _base;
  kk_function_t _x03_2575;
};
static kk_std_core_types__tuple2_ kk_climate_dash_experiments__mlift2588_run__experiments_fun4126(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift2588_run__experiments_fun4126(kk_function_t _x03_2575, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2588_run__experiments_fun4126__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift2588_run__experiments_fun4126__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift2588_run__experiments_fun4126, kk_context());
  _self->_x03_2575 = _x03_2575;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift2588_run__experiments_fun4129__t {
  struct kk_function_s _base;
  kk_function_t _x03_2575;
};
static kk_box_t kk_climate_dash_experiments__mlift2588_run__experiments_fun4129(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift2588_run__experiments_fun4129(kk_function_t _x03_2575, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2588_run__experiments_fun4129__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift2588_run__experiments_fun4129__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift2588_run__experiments_fun4129, kk_context());
  _self->_x03_2575 = _x03_2575;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift2588_run__experiments_fun4129(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2588_run__experiments_fun4129__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift2588_run__experiments_fun4129__t*, _fself);
  kk_function_t _x03_2575 = _self->_x03_2575; /* effects-and-types/model<(double, double),div> */
  kk_drop_match(_self, {kk_function_dup(_x03_2575);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x4130 = kk_function_call(kk_std_core_types__tuple2_, (kk_function_t, kk_context_t*), _x03_2575, (_x03_2575, _ctx)); /*(double, double)*/
  return kk_std_core_types__tuple2__box(_x4130, _ctx);
}
static kk_std_core_types__tuple2_ kk_climate_dash_experiments__mlift2588_run__experiments_fun4126(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2588_run__experiments_fun4126__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift2588_run__experiments_fun4126__t*, _fself);
  kk_function_t _x03_2575 = _self->_x03_2575; /* effects-and-types/model<(double, double),div> */
  kk_drop_match(_self, {kk_function_dup(_x03_2575);}, {}, _ctx)
  kk_vector_t _b_3367_3365;
  kk_std_core__list _x4127;
  size_t _b_3369_3363 = ((size_t)2); /*std/core/hnd/ev-index*/;
  kk_std_core__list _b_3370_3364;
  size_t _b_3371_3361 = ((size_t)4); /*std/core/hnd/ev-index*/;
  _b_3370_3364 = kk_std_core__new_Cons(kk_reuse_null, kk_size_box(_b_3371_3361, _ctx), kk_std_core__new_Nil(_ctx), _ctx); /*list<std/core/hnd/ev-index>*/
  _x4127 = kk_std_core__new_Cons(kk_reuse_null, kk_size_box(_b_3369_3363, _ctx), _b_3370_3364, _ctx); /*list<0>*/
  _b_3367_3365 = kk_std_core_unvlist(_x4127, _ctx); /*vector<std/core/hnd/ev-index>*/
  kk_box_t _x4128 = kk_std_core_hnd__open0(_b_3367_3365, kk_climate_dash_experiments__new_mlift2588_run__experiments_fun4129(_x03_2575, _ctx), _ctx); /*1*/
  return kk_std_core_types__tuple2__unbox(_x4128, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift2588_run__experiments_fun4132__t {
  struct kk_function_s _base;
  kk_function_t model_2670;
  kk_integer_t sz0;
};
static kk_box_t kk_climate_dash_experiments__mlift2588_run__experiments_fun4132(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift2588_run__experiments_fun4132(kk_function_t model_2670, kk_integer_t sz0, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2588_run__experiments_fun4132__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift2588_run__experiments_fun4132__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift2588_run__experiments_fun4132, kk_context());
  _self->model_2670 = model_2670;
  _self->sz0 = sz0;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift2588_run__experiments_fun4134__t {
  struct kk_function_s _base;
  kk_function_t model_2670;
};
static kk_box_t kk_climate_dash_experiments__mlift2588_run__experiments_fun4134(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift2588_run__experiments_fun4134(kk_function_t model_2670, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2588_run__experiments_fun4134__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift2588_run__experiments_fun4134__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift2588_run__experiments_fun4134, kk_context());
  _self->model_2670 = model_2670;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift2588_run__experiments_fun4136__t {
  struct kk_function_s _base;
  kk_function_t model_2670;
};
static kk_box_t kk_climate_dash_experiments__mlift2588_run__experiments_fun4136(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift2588_run__experiments_fun4136(kk_function_t model_2670, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2588_run__experiments_fun4136__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift2588_run__experiments_fun4136__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift2588_run__experiments_fun4136, kk_context());
  _self->model_2670 = model_2670;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift2588_run__experiments_fun4137__t {
  struct kk_function_s _base;
  kk_function_t model_2670;
};
static kk_box_t kk_climate_dash_experiments__mlift2588_run__experiments_fun4137(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift2588_run__experiments_fun4137(kk_function_t model_2670, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2588_run__experiments_fun4137__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift2588_run__experiments_fun4137__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift2588_run__experiments_fun4137, kk_context());
  _self->model_2670 = model_2670;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift2588_run__experiments_fun4137(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2588_run__experiments_fun4137__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift2588_run__experiments_fun4137__t*, _fself);
  kk_function_t model_2670 = _self->model_2670; /* () -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random,console,ndet,effects-and-types/sample> (double, double) */
  kk_drop_match(_self, {kk_function_dup(model_2670);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x4138 = kk_function_call(kk_std_core_types__tuple2_, (kk_function_t, kk_context_t*), model_2670, (model_2670, _ctx)); /*(double, double)*/
  return kk_std_core_types__tuple2__box(_x4138, _ctx);
}
static kk_box_t kk_climate_dash_experiments__mlift2588_run__experiments_fun4136(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2588_run__experiments_fun4136__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift2588_run__experiments_fun4136__t*, _fself);
  kk_function_t model_2670 = _self->model_2670; /* () -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random,console,ndet,effects-and-types/sample> (double, double) */
  kk_drop_match(_self, {kk_function_dup(model_2670);}, {}, _ctx)
  return kk_handlers_yield__on__score(kk_climate_dash_experiments__new_mlift2588_run__experiments_fun4137(model_2670, _ctx), _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift2588_run__experiments_fun4139__t {
  struct kk_function_s _base;
  kk_function_t _bv_3375;
};
static kk_std_core_types__tuple2_ kk_climate_dash_experiments__mlift2588_run__experiments_fun4139(kk_function_t _fself, kk_integer_t _b_3376, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift2588_run__experiments_fun4139(kk_function_t _bv_3375, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2588_run__experiments_fun4139__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift2588_run__experiments_fun4139__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift2588_run__experiments_fun4139, kk_context());
  _self->_bv_3375 = _bv_3375;
  return &_self->_base;
}

static kk_std_core_types__tuple2_ kk_climate_dash_experiments__mlift2588_run__experiments_fun4139(kk_function_t _fself, kk_integer_t _b_3376, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2588_run__experiments_fun4139__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift2588_run__experiments_fun4139__t*, _fself);
  kk_function_t _bv_3375 = _self->_bv_3375; /* (a : int) -> <effects-and-types/yield|215> 214 */
  kk_drop_match(_self, {kk_function_dup(_bv_3375);}, {}, _ctx)
  kk_box_t _x4140 = kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_context_t*), _bv_3375, (_bv_3375, _b_3376, _ctx)); /*214*/
  return kk_std_core_types__tuple2__unbox(_x4140, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift2588_run__experiments_fun4141__t {
  struct kk_function_s _base;
  kk_function_t _bv_3381;
};
static kk_box_t kk_climate_dash_experiments__mlift2588_run__experiments_fun4141(kk_function_t _fself, kk_box_t _b_3382, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift2588_run__experiments_fun4141(kk_function_t _bv_3381, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2588_run__experiments_fun4141__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift2588_run__experiments_fun4141__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift2588_run__experiments_fun4141, kk_context());
  _self->_bv_3381 = _bv_3381;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift2588_run__experiments_fun4141(kk_function_t _fself, kk_box_t _b_3382, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2588_run__experiments_fun4141__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift2588_run__experiments_fun4141__t*, _fself);
  kk_function_t _bv_3381 = _self->_bv_3381; /* (a : int) -> <effects-and-types/yield,effects-and-types/sample,effects-and-types/score,div,exn,std/num/random/random,console,ndet,effects-and-types/sample> (double, double) */
  kk_drop_match(_self, {kk_function_dup(_bv_3381);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x4142;
  kk_integer_t _x4143 = kk_integer_unbox(_b_3382); /*int*/
  _x4142 = kk_function_call(kk_std_core_types__tuple2_, (kk_function_t, kk_integer_t, kk_context_t*), _bv_3381, (_bv_3381, _x4143, _ctx)); /*(double, double)*/
  return kk_std_core_types__tuple2__box(_x4142, _ctx);
}
static kk_box_t kk_climate_dash_experiments__mlift2588_run__experiments_fun4134(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2588_run__experiments_fun4134__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift2588_run__experiments_fun4134__t*, _fself);
  kk_function_t model_2670 = _self->model_2670; /* () -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random,console,ndet,effects-and-types/sample> (double, double) */
  kk_drop_match(_self, {kk_function_dup(model_2670);}, {}, _ctx)
  kk_function_t _x4135;
  kk_function_t _bv_3381;
  kk_function_t _bv_3375 = kk_handlers_advance(kk_climate_dash_experiments__new_mlift2588_run__experiments_fun4136(model_2670, _ctx), _ctx); /*(a : int) -> <effects-and-types/yield|215> 214*/;
  _bv_3381 = kk_climate_dash_experiments__new_mlift2588_run__experiments_fun4139(_bv_3375, _ctx); /*(a : int) -> <effects-and-types/yield,effects-and-types/sample,effects-and-types/score,div,exn,std/num/random/random,console,ndet,effects-and-types/sample> (double, double)*/
  _x4135 = kk_climate_dash_experiments__new_mlift2588_run__experiments_fun4141(_bv_3381, _ctx); /*(3379) -> <effects-and-types/yield,effects-and-types/sample,effects-and-types/score,div,exn,std/num/random/random,console,ndet,effects-and-types/sample> 3380*/
  return kk_function_box(_x4135);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift2588_run__experiments_fun4145__t {
  struct kk_function_s _base;
};
static kk_box_t kk_climate_dash_experiments__mlift2588_run__experiments_fun4145(kk_function_t _fself, kk_box_t _b_3388, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift2588_run__experiments_fun4145(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_climate_dash_experiments__mlift2588_run__experiments_fun4145, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_climate_dash_experiments__mlift2588_run__experiments_fun4145(kk_function_t _fself, kk_box_t _b_3388, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core__list _x4146;
  kk_std_core__list _x4147 = kk_std_core__list_unbox(_b_3388, _ctx); /*effects-and-types/histogram<(a : int) -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random,console,ndet,effects-and-types/sample> (double, double)>*/
  _x4146 = kk_sequential__mlift743_smc(true, kk_integer_from_small(50), kk_integer_from_small(1), _x4147, _ctx); /*effects-and-types/histogram<24>*/
  return kk_std_core__list_box(_x4146, _ctx);
}
static kk_box_t kk_climate_dash_experiments__mlift2588_run__experiments_fun4132(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2588_run__experiments_fun4132__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift2588_run__experiments_fun4132__t*, _fself);
  kk_function_t model_2670 = _self->model_2670; /* () -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random,console,ndet,effects-and-types/sample> (double, double) */
  kk_integer_t sz0 = _self->sz0; /* int */
  kk_drop_match(_self, {kk_function_dup(model_2670);kk_integer_dup(sz0);}, {}, _ctx)
  kk_std_core__list _x4133;
  kk_std_core__list x_775 = kk_sampling_populate(sz0, kk_climate_dash_experiments__new_mlift2588_run__experiments_fun4134(model_2670, _ctx), _ctx); /*effects-and-types/histogram<(a : int) -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random,console,ndet,effects-and-types/sample> (double, double)>*/;
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_775, _ctx);
    kk_box_t _x4144 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments__new_mlift2588_run__experiments_fun4145(_ctx), _ctx); /*2*/
    _x4133 = kk_std_core__list_unbox(_x4144, _ctx); /*effects-and-types/histogram<(double, double)>*/
  }
  else {
    _x4133 = kk_sequential__mlift743_smc(true, kk_integer_from_small(50), kk_integer_from_small(1), x_775, _ctx); /*effects-and-types/histogram<(double, double)>*/
  }
  return kk_std_core__list_box(_x4133, _ctx);
}
static kk_box_t kk_climate_dash_experiments__mlift2588_run__experiments_fun4116(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2588_run__experiments_fun4116__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift2588_run__experiments_fun4116__t*, _fself);
  kk_std_core__list data__50 = _self->data__50; /* list<(double, bool)> */
  kk_integer_t sz0 = _self->sz0; /* int */
  kk_drop_match(_self, {kk_std_core__list_dup(data__50);kk_integer_dup(sz0);}, {}, _ctx)
  kk_std_core__list _x4117;
  kk_function_t model_2670;
  kk_function_t _x03_2575;
  kk_function_t _bv_3358;
  kk_box_t _x4118 = kk_std_core_hnd__open_none1(kk_climate_dash_experiments__new_mlift2588_run__experiments_fun4119(_ctx), kk_std_core__list_box(data__50, _ctx), _ctx); /*2*/
  _bv_3358 = kk_function_unbox(_x4118); /*() -> <.Box|.Box> 3357*/
  _x03_2575 = kk_climate_dash_experiments__new_mlift2588_run__experiments_fun4124(_bv_3358, _ctx); /*effects-and-types/model<(double, double),div>*/
  model_2670 = kk_climate_dash_experiments__new_mlift2588_run__experiments_fun4126(_x03_2575, _ctx); /*() -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random,console,ndet,effects-and-types/sample> (double, double)*/
  kk_box_t _x4131 = kk_handlers_random__sampler(kk_climate_dash_experiments__new_mlift2588_run__experiments_fun4132(model_2670, sz0, _ctx), _ctx); /*312*/
  _x4117 = kk_std_core__list_unbox(_x4131, _ctx); /*effects-and-types/histogram<(double, double)>*/
  return kk_std_core__list_box(_x4117, _ctx);
}
static kk_box_t kk_climate_dash_experiments__mlift2588_run__experiments_fun4113(kk_function_t _fself, kk_box_t _b_3394, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2588_run__experiments_fun4113__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift2588_run__experiments_fun4113__t*, _fself);
  kk_std_core__list data__50 = _self->data__50; /* list<(double, bool)> */
  kk_drop_match(_self, {kk_std_core__list_dup(data__50);}, {}, _ctx)
  kk_std_core_types__tuple2_ _match_3762 = kk_std_core_types__tuple2__unbox(_b_3394, _ctx); /*(int, list<(double, bool)>)*/;
  kk_box_t _box_x3350 = _match_3762.fst;
  kk_box_t _box_x3351 = _match_3762.snd;
  kk_integer_t sz0 = kk_integer_unbox(_box_x3350);
  kk_integer_dup(sz0);
  kk_std_core_types__tuple2__drop(_match_3762, _ctx);
  return kk_std_time_timer_print_elapsed(kk_climate_dash_experiments__new_mlift2588_run__experiments_fun4116(data__50, sz0, _ctx), kk_std_core_types__new_None(_ctx), _ctx);
}

kk_std_core__list kk_climate_dash_experiments__mlift2588_run__experiments(kk_std_core__list data__50, kk_std_core__list data__points, kk_std_core__list wild__0, kk_context_t* _ctx) { /* (data_50 : list<(double, bool)>, data_points : list<(int, list<(double, bool)>)>, wild_0 : list<effects-and-types/histogram<(double, double)>>) -> <console,div,exn,ndet,std/num/random/random,effects-and-types/sample> list<effects-and-types/histogram<(double, double)>> */ 
  kk_std_core__list_drop(wild__0, _ctx);
  kk_unit_t __1 = kk_Unit;
  kk_string_t _x4111;
  kk_define_string_literal(, _s4112, 7, "Mid-way")
  _x4111 = kk_string_dup(_s4112); /*string*/
  kk_std_core_printsln(_x4111, _ctx);
  return kk_std_core_map_5(data__points, kk_climate_dash_experiments__new_mlift2588_run__experiments_fun4113(data__50, _ctx), _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_climate_dash_experiments__mlift2589_run__experiments_fun4154__t {
  struct kk_function_s _base;
  kk_std_core__list data__points;
};
static kk_box_t kk_climate_dash_experiments__mlift2589_run__experiments_fun4154(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift2589_run__experiments_fun4154(kk_std_core__list data__points, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2589_run__experiments_fun4154__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift2589_run__experiments_fun4154__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift2589_run__experiments_fun4154, kk_context());
  _self->data__points = data__points;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift2589_run__experiments_fun4156__t {
  struct kk_function_s _base;
};
static kk_box_t kk_climate_dash_experiments__mlift2589_run__experiments_fun4156(kk_function_t _fself, kk_box_t _b_3428, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift2589_run__experiments_fun4156(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_climate_dash_experiments__mlift2589_run__experiments_fun4156, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift2589_run__experiments_fun4159__t {
  struct kk_function_s _base;
  kk_std_core__list data__vals0;
};
static kk_box_t kk_climate_dash_experiments__mlift2589_run__experiments_fun4159(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift2589_run__experiments_fun4159(kk_std_core__list data__vals0, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2589_run__experiments_fun4159__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift2589_run__experiments_fun4159__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift2589_run__experiments_fun4159, kk_context());
  _self->data__vals0 = data__vals0;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift2589_run__experiments_fun4162__t {
  struct kk_function_s _base;
};
static kk_box_t kk_climate_dash_experiments__mlift2589_run__experiments_fun4162(kk_function_t _fself, kk_box_t _b_3407, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift2589_run__experiments_fun4162(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_climate_dash_experiments__mlift2589_run__experiments_fun4162, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift2589_run__experiments_fun4165__t {
  struct kk_function_s _base;
  kk_function_t _bv_3409;
};
static kk_box_t kk_climate_dash_experiments__mlift2589_run__experiments_fun4165(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift2589_run__experiments_fun4165(kk_function_t _bv_3409, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2589_run__experiments_fun4165__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift2589_run__experiments_fun4165__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift2589_run__experiments_fun4165, kk_context());
  _self->_bv_3409 = _bv_3409;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift2589_run__experiments_fun4165(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2589_run__experiments_fun4165__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift2589_run__experiments_fun4165__t*, _fself);
  kk_function_t _bv_3409 = _self->_bv_3409; /* effects-and-types/model<(double, double),div> */
  kk_drop_match(_self, {kk_function_dup(_bv_3409);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x4166 = kk_function_call(kk_std_core_types__tuple2_, (kk_function_t, kk_context_t*), _bv_3409, (_bv_3409, _ctx)); /*(double, double)*/
  return kk_std_core_types__tuple2__box(_x4166, _ctx);
}
static kk_box_t kk_climate_dash_experiments__mlift2589_run__experiments_fun4162(kk_function_t _fself, kk_box_t _b_3407, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_function_t _x4163;
  kk_function_t _bv_3409;
  kk_std_core__list _x4164 = kk_std_core__list_unbox(_b_3407, _ctx); /*list<(double, bool)>*/
  _bv_3409 = kk_model_dash_resources_logistic__regression(_x4164, _ctx); /*effects-and-types/model<(double, double),div>*/
  _x4163 = kk_climate_dash_experiments__new_mlift2589_run__experiments_fun4165(_bv_3409, _ctx); /*() -> <div,effects-and-types/sample,effects-and-types/score> 3408*/
  return kk_function_box(_x4163);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift2589_run__experiments_fun4167__t {
  struct kk_function_s _base;
  kk_function_t _bv_3411;
};
static kk_std_core_types__tuple2_ kk_climate_dash_experiments__mlift2589_run__experiments_fun4167(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift2589_run__experiments_fun4167(kk_function_t _bv_3411, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2589_run__experiments_fun4167__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift2589_run__experiments_fun4167__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift2589_run__experiments_fun4167, kk_context());
  _self->_bv_3411 = _bv_3411;
  return &_self->_base;
}

static kk_std_core_types__tuple2_ kk_climate_dash_experiments__mlift2589_run__experiments_fun4167(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2589_run__experiments_fun4167__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift2589_run__experiments_fun4167__t*, _fself);
  kk_function_t _bv_3411 = _self->_bv_3411; /* () -> <.Box|.Box> 3410 */
  kk_drop_match(_self, {kk_function_dup(_bv_3411);}, {}, _ctx)
  kk_box_t _x4168 = kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), _bv_3411, (_bv_3411, _ctx)); /*3410*/
  return kk_std_core_types__tuple2__unbox(_x4168, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift2589_run__experiments_fun4169__t {
  struct kk_function_s _base;
  kk_function_t _x05_2577;
};
static kk_std_core_types__tuple2_ kk_climate_dash_experiments__mlift2589_run__experiments_fun4169(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift2589_run__experiments_fun4169(kk_function_t _x05_2577, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2589_run__experiments_fun4169__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift2589_run__experiments_fun4169__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift2589_run__experiments_fun4169, kk_context());
  _self->_x05_2577 = _x05_2577;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift2589_run__experiments_fun4172__t {
  struct kk_function_s _base;
  kk_function_t _x05_2577;
};
static kk_box_t kk_climate_dash_experiments__mlift2589_run__experiments_fun4172(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift2589_run__experiments_fun4172(kk_function_t _x05_2577, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2589_run__experiments_fun4172__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift2589_run__experiments_fun4172__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift2589_run__experiments_fun4172, kk_context());
  _self->_x05_2577 = _x05_2577;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift2589_run__experiments_fun4172(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2589_run__experiments_fun4172__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift2589_run__experiments_fun4172__t*, _fself);
  kk_function_t _x05_2577 = _self->_x05_2577; /* effects-and-types/model<(double, double),div> */
  kk_drop_match(_self, {kk_function_dup(_x05_2577);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x4173 = kk_function_call(kk_std_core_types__tuple2_, (kk_function_t, kk_context_t*), _x05_2577, (_x05_2577, _ctx)); /*(double, double)*/
  return kk_std_core_types__tuple2__box(_x4173, _ctx);
}
static kk_std_core_types__tuple2_ kk_climate_dash_experiments__mlift2589_run__experiments_fun4169(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2589_run__experiments_fun4169__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift2589_run__experiments_fun4169__t*, _fself);
  kk_function_t _x05_2577 = _self->_x05_2577; /* effects-and-types/model<(double, double),div> */
  kk_drop_match(_self, {kk_function_dup(_x05_2577);}, {}, _ctx)
  kk_vector_t _b_3442_3418;
  kk_std_core__list _x4170;
  size_t _b_3444_3416 = ((size_t)2); /*std/core/hnd/ev-index*/;
  kk_std_core__list _b_3445_3417;
  size_t _b_3446_3414 = ((size_t)3); /*std/core/hnd/ev-index*/;
  _b_3445_3417 = kk_std_core__new_Cons(kk_reuse_null, kk_size_box(_b_3446_3414, _ctx), kk_std_core__new_Nil(_ctx), _ctx); /*list<std/core/hnd/ev-index>*/
  _x4170 = kk_std_core__new_Cons(kk_reuse_null, kk_size_box(_b_3444_3416, _ctx), _b_3445_3417, _ctx); /*list<0>*/
  _b_3442_3418 = kk_std_core_unvlist(_x4170, _ctx); /*vector<std/core/hnd/ev-index>*/
  kk_box_t _x4171 = kk_std_core_hnd__open0(_b_3442_3418, kk_climate_dash_experiments__new_mlift2589_run__experiments_fun4172(_x05_2577, _ctx), _ctx); /*1*/
  return kk_std_core_types__tuple2__unbox(_x4171, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift2589_run__experiments_fun4174__t {
  struct kk_function_s _base;
  kk_function_t _b_3438_3420;
};
static kk_box_t kk_climate_dash_experiments__mlift2589_run__experiments_fun4174(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift2589_run__experiments_fun4174(kk_function_t _b_3438_3420, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2589_run__experiments_fun4174__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift2589_run__experiments_fun4174__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift2589_run__experiments_fun4174, kk_context());
  _self->_b_3438_3420 = _b_3438_3420;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift2589_run__experiments_fun4174(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2589_run__experiments_fun4174__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift2589_run__experiments_fun4174__t*, _fself);
  kk_function_t _b_3438_3420 = _self->_b_3438_3420; /* () -> <div,effects-and-types/sample,effects-and-types/score> (double, double) */
  kk_drop_match(_self, {kk_function_dup(_b_3438_3420);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x4175 = kk_function_call(kk_std_core_types__tuple2_, (kk_function_t, kk_context_t*), _b_3438_3420, (_b_3438_3420, _ctx)); /*(double, double)*/
  return kk_std_core_types__tuple2__box(_x4175, _ctx);
}
static kk_box_t kk_climate_dash_experiments__mlift2589_run__experiments_fun4159(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2589_run__experiments_fun4159__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift2589_run__experiments_fun4159__t*, _fself);
  kk_std_core__list data__vals0 = _self->data__vals0; /* list<(double, bool)> */
  kk_drop_match(_self, {kk_std_core__list_dup(data__vals0);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x4160;
  kk_function_t _b_3438_3420;
  kk_function_t _x05_2577;
  kk_function_t _bv_3411;
  kk_box_t _x4161 = kk_std_core_hnd__open_none1(kk_climate_dash_experiments__new_mlift2589_run__experiments_fun4162(_ctx), kk_std_core__list_box(data__vals0, _ctx), _ctx); /*2*/
  _bv_3411 = kk_function_unbox(_x4161); /*() -> <.Box|.Box> 3410*/
  _x05_2577 = kk_climate_dash_experiments__new_mlift2589_run__experiments_fun4167(_bv_3411, _ctx); /*effects-and-types/model<(double, double),div>*/
  _b_3438_3420 = kk_climate_dash_experiments__new_mlift2589_run__experiments_fun4169(_x05_2577, _ctx); /*() -> <div,effects-and-types/sample,effects-and-types/score> (double, double)*/
  kk_effects_dash_and_dash_types__exp _b_3440_3422 = kk_effects_dash_and_dash_types__new_Exp(0x0p+0, _ctx); /*effects-and-types/exp*/;
  _x4160 = kk_trace_tmcmc(kk_climate_dash_experiments__new_mlift2589_run__experiments_fun4174(_b_3438_3420, _ctx), kk_integer_from_small(100), _b_3440_3422, kk_integer_from_small(0), _ctx); /*(list<(list<double>, 1382)>, trace/trace<1382,<effects-and-types/sample,effects-and-types/score,div|1383>>)*/
  return kk_std_core_types__tuple2__box(_x4160, _ctx);
}
static kk_box_t kk_climate_dash_experiments__mlift2589_run__experiments_fun4156(kk_function_t _fself, kk_box_t _b_3428, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core_types__tuple2_ _match_3761 = kk_std_core_types__tuple2__unbox(_b_3428, _ctx); /*(int, list<(double, bool)>)*/;
  kk_box_t _box_x3403 = _match_3761.fst;
  kk_box_t _box_x3404 = _match_3761.snd;
  kk_std_core__list data__vals0 = kk_std_core__list_unbox(_box_x3404, NULL);
  kk_std_core__list_dup(data__vals0);
  kk_std_core_types__tuple2__drop(_match_3761, _ctx);
  return kk_std_time_timer_print_elapsed(kk_climate_dash_experiments__new_mlift2589_run__experiments_fun4159(data__vals0, _ctx), kk_std_core_types__new_None(_ctx), _ctx);
}
static kk_box_t kk_climate_dash_experiments__mlift2589_run__experiments_fun4154(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2589_run__experiments_fun4154__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift2589_run__experiments_fun4154__t*, _fself);
  kk_std_core__list data__points = _self->data__points; /* list<(int, list<(double, bool)>)> */
  kk_drop_match(_self, {kk_std_core__list_dup(data__points);}, {}, _ctx)
  kk_std_core__list _x4155 = kk_std_core_map_5(data__points, kk_climate_dash_experiments__new_mlift2589_run__experiments_fun4156(_ctx), _ctx); /*list<2>*/
  return kk_std_core__list_box(_x4155, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift2589_run__experiments_fun4177__t {
  struct kk_function_s _base;
  kk_std_core__list data__50;
  kk_std_core__list data__points;
};
static kk_box_t kk_climate_dash_experiments__mlift2589_run__experiments_fun4177(kk_function_t _fself, kk_box_t _b_3449, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift2589_run__experiments_fun4177(kk_std_core__list data__50, kk_std_core__list data__points, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2589_run__experiments_fun4177__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift2589_run__experiments_fun4177__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift2589_run__experiments_fun4177, kk_context());
  _self->data__50 = data__50;
  _self->data__points = data__points;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift2589_run__experiments_fun4177(kk_function_t _fself, kk_box_t _b_3449, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2589_run__experiments_fun4177__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift2589_run__experiments_fun4177__t*, _fself);
  kk_std_core__list data__50 = _self->data__50; /* list<(double, bool)> */
  kk_std_core__list data__points = _self->data__points; /* list<(int, list<(double, bool)>)> */
  kk_drop_match(_self, {kk_std_core__list_dup(data__50);kk_std_core__list_dup(data__points);}, {}, _ctx)
  kk_unit_t _x4178 = kk_Unit;
  kk_std_core__list _x4179 = kk_std_core__list_unbox(_b_3449, _ctx); /*list<(list<(list<double>, (double, double))>, trace/trace<(double, double),<effects-and-types/sample,effects-and-types/score,div,console,ndet,exn,std/num/random/random>>)>*/
  kk_climate_dash_experiments__mlift2587_run__experiments(data__50, data__points, _x4179, _ctx);
  return kk_unit_box(_x4178);
}

kk_unit_t kk_climate_dash_experiments__mlift2589_run__experiments(kk_std_core__list data__50, kk_std_core__list data__points, kk_std_core__list wild__2, kk_context_t* _ctx) { /* (data_50 : list<(double, bool)>, data_points : list<(int, list<(double, bool)>)>, wild_2 : list<effects-and-types/histogram<(double, double)>>) -> <ndet,console,div,exn,std/num/random/random,effects-and-types/sample> () */ 
  kk_std_core__list_drop(wild__2, _ctx);
  kk_unit_t __3 = kk_Unit;
  kk_string_t _x4148;
  kk_define_string_literal(, _s4149, 33, "Completed Sequential Monte Carlo!")
  _x4148 = kk_string_dup(_s4149); /*string*/
  kk_std_core_printsln(_x4148, _ctx);
  kk_unit_t __4 = kk_Unit;
  kk_string_t _x4150;
  kk_define_string_literal(, _s4151, 19, "Running Trace MCMC!")
  _x4150 = kk_string_dup(_s4151); /*string*/
  kk_std_core_printsln(_x4150, _ctx);
  kk_std_core__list x_2674;
  kk_box_t _x4152;
  kk_function_t _x4153;
  kk_std_core__list_dup(data__points);
  _x4153 = kk_climate_dash_experiments__new_mlift2589_run__experiments_fun4154(data__points, _ctx); /*() -> <ndet,console|454> 453*/
  _x4152 = kk_std_time_timer_print_elapsed(_x4153, kk_std_core_types__new_None(_ctx), _ctx); /*453*/
  x_2674 = kk_std_core__list_unbox(_x4152, _ctx); /*list<(list<(list<double>, (double, double))>, trace/trace<(double, double),<effects-and-types/sample,effects-and-types/score,div,console,ndet,exn,std/num/random/random>>)>*/
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_2674, _ctx);
    kk_box_t _x4176 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments__new_mlift2589_run__experiments_fun4177(data__50, data__points, _ctx), _ctx); /*2*/
    kk_unit_unbox(_x4176); return kk_Unit;
  }
  kk_climate_dash_experiments__mlift2587_run__experiments(data__50, data__points, x_2674, _ctx); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_climate_dash_experiments__mlift2590_run__experiments_fun4180__t {
  struct kk_function_s _base;
  kk_std_core__list data__50;
  kk_std_core__list data__points;
};
static kk_unit_t kk_climate_dash_experiments__mlift2590_run__experiments_fun4180(kk_function_t _fself, kk_integer_t i1, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift2590_run__experiments_fun4180(kk_std_core__list data__50, kk_std_core__list data__points, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2590_run__experiments_fun4180__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift2590_run__experiments_fun4180__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift2590_run__experiments_fun4180, kk_context());
  _self->data__50 = data__50;
  _self->data__points = data__points;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift2590_run__experiments_fun4185__t {
  struct kk_function_s _base;
  kk_std_core__list data__50;
  kk_std_core__list data__points;
};
static kk_box_t kk_climate_dash_experiments__mlift2590_run__experiments_fun4185(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift2590_run__experiments_fun4185(kk_std_core__list data__50, kk_std_core__list data__points, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2590_run__experiments_fun4185__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift2590_run__experiments_fun4185__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift2590_run__experiments_fun4185, kk_context());
  _self->data__50 = data__50;
  _self->data__points = data__points;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift2590_run__experiments_fun4188__t {
  struct kk_function_s _base;
};
static kk_box_t kk_climate_dash_experiments__mlift2590_run__experiments_fun4188(kk_function_t _fself, kk_box_t _b_3496, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift2590_run__experiments_fun4188(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_climate_dash_experiments__mlift2590_run__experiments_fun4188, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift2590_run__experiments_fun4191__t {
  struct kk_function_s _base;
  kk_std_core__list data__vals;
  kk_integer_t sz;
};
static kk_box_t kk_climate_dash_experiments__mlift2590_run__experiments_fun4191(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift2590_run__experiments_fun4191(kk_std_core__list data__vals, kk_integer_t sz, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2590_run__experiments_fun4191__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift2590_run__experiments_fun4191__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift2590_run__experiments_fun4191, kk_context());
  _self->data__vals = data__vals;
  _self->sz = sz;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift2590_run__experiments_fun4194__t {
  struct kk_function_s _base;
};
static kk_box_t kk_climate_dash_experiments__mlift2590_run__experiments_fun4194(kk_function_t _fself, kk_box_t _b_3456, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift2590_run__experiments_fun4194(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_climate_dash_experiments__mlift2590_run__experiments_fun4194, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift2590_run__experiments_fun4197__t {
  struct kk_function_s _base;
  kk_function_t _bv_3458;
};
static kk_box_t kk_climate_dash_experiments__mlift2590_run__experiments_fun4197(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift2590_run__experiments_fun4197(kk_function_t _bv_3458, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2590_run__experiments_fun4197__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift2590_run__experiments_fun4197__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift2590_run__experiments_fun4197, kk_context());
  _self->_bv_3458 = _bv_3458;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift2590_run__experiments_fun4197(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2590_run__experiments_fun4197__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift2590_run__experiments_fun4197__t*, _fself);
  kk_function_t _bv_3458 = _self->_bv_3458; /* effects-and-types/model<(double, double),div> */
  kk_drop_match(_self, {kk_function_dup(_bv_3458);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x4198 = kk_function_call(kk_std_core_types__tuple2_, (kk_function_t, kk_context_t*), _bv_3458, (_bv_3458, _ctx)); /*(double, double)*/
  return kk_std_core_types__tuple2__box(_x4198, _ctx);
}
static kk_box_t kk_climate_dash_experiments__mlift2590_run__experiments_fun4194(kk_function_t _fself, kk_box_t _b_3456, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_function_t _x4195;
  kk_function_t _bv_3458;
  kk_std_core__list _x4196 = kk_std_core__list_unbox(_b_3456, _ctx); /*list<(double, bool)>*/
  _bv_3458 = kk_model_dash_resources_logistic__regression(_x4196, _ctx); /*effects-and-types/model<(double, double),div>*/
  _x4195 = kk_climate_dash_experiments__new_mlift2590_run__experiments_fun4197(_bv_3458, _ctx); /*() -> <div,effects-and-types/sample,effects-and-types/score> 3457*/
  return kk_function_box(_x4195);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift2590_run__experiments_fun4199__t {
  struct kk_function_s _base;
  kk_function_t _bv_3460;
};
static kk_std_core_types__tuple2_ kk_climate_dash_experiments__mlift2590_run__experiments_fun4199(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift2590_run__experiments_fun4199(kk_function_t _bv_3460, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2590_run__experiments_fun4199__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift2590_run__experiments_fun4199__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift2590_run__experiments_fun4199, kk_context());
  _self->_bv_3460 = _bv_3460;
  return &_self->_base;
}

static kk_std_core_types__tuple2_ kk_climate_dash_experiments__mlift2590_run__experiments_fun4199(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2590_run__experiments_fun4199__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift2590_run__experiments_fun4199__t*, _fself);
  kk_function_t _bv_3460 = _self->_bv_3460; /* () -> <.Box|.Box> 3459 */
  kk_drop_match(_self, {kk_function_dup(_bv_3460);}, {}, _ctx)
  kk_box_t _x4200 = kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), _bv_3460, (_bv_3460, _ctx)); /*3459*/
  return kk_std_core_types__tuple2__unbox(_x4200, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift2590_run__experiments_fun4201__t {
  struct kk_function_s _base;
  kk_function_t _x01_2573;
};
static kk_std_core_types__tuple2_ kk_climate_dash_experiments__mlift2590_run__experiments_fun4201(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift2590_run__experiments_fun4201(kk_function_t _x01_2573, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2590_run__experiments_fun4201__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift2590_run__experiments_fun4201__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift2590_run__experiments_fun4201, kk_context());
  _self->_x01_2573 = _x01_2573;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift2590_run__experiments_fun4204__t {
  struct kk_function_s _base;
  kk_function_t _x01_2573;
};
static kk_box_t kk_climate_dash_experiments__mlift2590_run__experiments_fun4204(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift2590_run__experiments_fun4204(kk_function_t _x01_2573, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2590_run__experiments_fun4204__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift2590_run__experiments_fun4204__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift2590_run__experiments_fun4204, kk_context());
  _self->_x01_2573 = _x01_2573;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift2590_run__experiments_fun4204(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2590_run__experiments_fun4204__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift2590_run__experiments_fun4204__t*, _fself);
  kk_function_t _x01_2573 = _self->_x01_2573; /* effects-and-types/model<(double, double),div> */
  kk_drop_match(_self, {kk_function_dup(_x01_2573);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x4205 = kk_function_call(kk_std_core_types__tuple2_, (kk_function_t, kk_context_t*), _x01_2573, (_x01_2573, _ctx)); /*(double, double)*/
  return kk_std_core_types__tuple2__box(_x4205, _ctx);
}
static kk_std_core_types__tuple2_ kk_climate_dash_experiments__mlift2590_run__experiments_fun4201(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2590_run__experiments_fun4201__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift2590_run__experiments_fun4201__t*, _fself);
  kk_function_t _x01_2573 = _self->_x01_2573; /* effects-and-types/model<(double, double),div> */
  kk_drop_match(_self, {kk_function_dup(_x01_2573);}, {}, _ctx)
  kk_vector_t _b_3469_3467;
  kk_std_core__list _x4202;
  size_t _b_3471_3465 = ((size_t)2); /*std/core/hnd/ev-index*/;
  kk_std_core__list _b_3472_3466;
  size_t _b_3473_3463 = ((size_t)4); /*std/core/hnd/ev-index*/;
  _b_3472_3466 = kk_std_core__new_Cons(kk_reuse_null, kk_size_box(_b_3473_3463, _ctx), kk_std_core__new_Nil(_ctx), _ctx); /*list<std/core/hnd/ev-index>*/
  _x4202 = kk_std_core__new_Cons(kk_reuse_null, kk_size_box(_b_3471_3465, _ctx), _b_3472_3466, _ctx); /*list<0>*/
  _b_3469_3467 = kk_std_core_unvlist(_x4202, _ctx); /*vector<std/core/hnd/ev-index>*/
  kk_box_t _x4203 = kk_std_core_hnd__open0(_b_3469_3467, kk_climate_dash_experiments__new_mlift2590_run__experiments_fun4204(_x01_2573, _ctx), _ctx); /*1*/
  return kk_std_core_types__tuple2__unbox(_x4203, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift2590_run__experiments_fun4207__t {
  struct kk_function_s _base;
  kk_function_t model_2687;
  kk_integer_t sz;
};
static kk_box_t kk_climate_dash_experiments__mlift2590_run__experiments_fun4207(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift2590_run__experiments_fun4207(kk_function_t model_2687, kk_integer_t sz, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2590_run__experiments_fun4207__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift2590_run__experiments_fun4207__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift2590_run__experiments_fun4207, kk_context());
  _self->model_2687 = model_2687;
  _self->sz = sz;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift2590_run__experiments_fun4209__t {
  struct kk_function_s _base;
  kk_function_t model_2687;
};
static kk_box_t kk_climate_dash_experiments__mlift2590_run__experiments_fun4209(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift2590_run__experiments_fun4209(kk_function_t model_2687, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2590_run__experiments_fun4209__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift2590_run__experiments_fun4209__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift2590_run__experiments_fun4209, kk_context());
  _self->model_2687 = model_2687;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift2590_run__experiments_fun4211__t {
  struct kk_function_s _base;
  kk_function_t model_2687;
};
static kk_box_t kk_climate_dash_experiments__mlift2590_run__experiments_fun4211(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift2590_run__experiments_fun4211(kk_function_t model_2687, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2590_run__experiments_fun4211__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift2590_run__experiments_fun4211__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift2590_run__experiments_fun4211, kk_context());
  _self->model_2687 = model_2687;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift2590_run__experiments_fun4212__t {
  struct kk_function_s _base;
  kk_function_t model_2687;
};
static kk_box_t kk_climate_dash_experiments__mlift2590_run__experiments_fun4212(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift2590_run__experiments_fun4212(kk_function_t model_2687, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2590_run__experiments_fun4212__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift2590_run__experiments_fun4212__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift2590_run__experiments_fun4212, kk_context());
  _self->model_2687 = model_2687;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift2590_run__experiments_fun4212(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2590_run__experiments_fun4212__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift2590_run__experiments_fun4212__t*, _fself);
  kk_function_t model_2687 = _self->model_2687; /* () -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random,console,ndet,effects-and-types/sample> (double, double) */
  kk_drop_match(_self, {kk_function_dup(model_2687);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x4213 = kk_function_call(kk_std_core_types__tuple2_, (kk_function_t, kk_context_t*), model_2687, (model_2687, _ctx)); /*(double, double)*/
  return kk_std_core_types__tuple2__box(_x4213, _ctx);
}
static kk_box_t kk_climate_dash_experiments__mlift2590_run__experiments_fun4211(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2590_run__experiments_fun4211__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift2590_run__experiments_fun4211__t*, _fself);
  kk_function_t model_2687 = _self->model_2687; /* () -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random,console,ndet,effects-and-types/sample> (double, double) */
  kk_drop_match(_self, {kk_function_dup(model_2687);}, {}, _ctx)
  return kk_handlers_yield__on__score(kk_climate_dash_experiments__new_mlift2590_run__experiments_fun4212(model_2687, _ctx), _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift2590_run__experiments_fun4214__t {
  struct kk_function_s _base;
  kk_function_t _bv_3477;
};
static kk_std_core_types__tuple2_ kk_climate_dash_experiments__mlift2590_run__experiments_fun4214(kk_function_t _fself, kk_integer_t _b_3478, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift2590_run__experiments_fun4214(kk_function_t _bv_3477, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2590_run__experiments_fun4214__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift2590_run__experiments_fun4214__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift2590_run__experiments_fun4214, kk_context());
  _self->_bv_3477 = _bv_3477;
  return &_self->_base;
}

static kk_std_core_types__tuple2_ kk_climate_dash_experiments__mlift2590_run__experiments_fun4214(kk_function_t _fself, kk_integer_t _b_3478, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2590_run__experiments_fun4214__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift2590_run__experiments_fun4214__t*, _fself);
  kk_function_t _bv_3477 = _self->_bv_3477; /* (a : int) -> <effects-and-types/yield|215> 214 */
  kk_drop_match(_self, {kk_function_dup(_bv_3477);}, {}, _ctx)
  kk_box_t _x4215 = kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_context_t*), _bv_3477, (_bv_3477, _b_3478, _ctx)); /*214*/
  return kk_std_core_types__tuple2__unbox(_x4215, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift2590_run__experiments_fun4216__t {
  struct kk_function_s _base;
  kk_function_t _bv_3483;
};
static kk_box_t kk_climate_dash_experiments__mlift2590_run__experiments_fun4216(kk_function_t _fself, kk_box_t _b_3484, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift2590_run__experiments_fun4216(kk_function_t _bv_3483, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2590_run__experiments_fun4216__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift2590_run__experiments_fun4216__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift2590_run__experiments_fun4216, kk_context());
  _self->_bv_3483 = _bv_3483;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift2590_run__experiments_fun4216(kk_function_t _fself, kk_box_t _b_3484, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2590_run__experiments_fun4216__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift2590_run__experiments_fun4216__t*, _fself);
  kk_function_t _bv_3483 = _self->_bv_3483; /* (a : int) -> <effects-and-types/yield,effects-and-types/sample,effects-and-types/score,div,exn,std/num/random/random,console,ndet,effects-and-types/sample> (double, double) */
  kk_drop_match(_self, {kk_function_dup(_bv_3483);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x4217;
  kk_integer_t _x4218 = kk_integer_unbox(_b_3484); /*int*/
  _x4217 = kk_function_call(kk_std_core_types__tuple2_, (kk_function_t, kk_integer_t, kk_context_t*), _bv_3483, (_bv_3483, _x4218, _ctx)); /*(double, double)*/
  return kk_std_core_types__tuple2__box(_x4217, _ctx);
}
static kk_box_t kk_climate_dash_experiments__mlift2590_run__experiments_fun4209(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2590_run__experiments_fun4209__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift2590_run__experiments_fun4209__t*, _fself);
  kk_function_t model_2687 = _self->model_2687; /* () -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random,console,ndet,effects-and-types/sample> (double, double) */
  kk_drop_match(_self, {kk_function_dup(model_2687);}, {}, _ctx)
  kk_function_t _x4210;
  kk_function_t _bv_3483;
  kk_function_t _bv_3477 = kk_handlers_advance(kk_climate_dash_experiments__new_mlift2590_run__experiments_fun4211(model_2687, _ctx), _ctx); /*(a : int) -> <effects-and-types/yield|215> 214*/;
  _bv_3483 = kk_climate_dash_experiments__new_mlift2590_run__experiments_fun4214(_bv_3477, _ctx); /*(a : int) -> <effects-and-types/yield,effects-and-types/sample,effects-and-types/score,div,exn,std/num/random/random,console,ndet,effects-and-types/sample> (double, double)*/
  _x4210 = kk_climate_dash_experiments__new_mlift2590_run__experiments_fun4216(_bv_3483, _ctx); /*(3481) -> <effects-and-types/yield,effects-and-types/sample,effects-and-types/score,div,exn,std/num/random/random,console,ndet,effects-and-types/sample> 3482*/
  return kk_function_box(_x4210);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift2590_run__experiments_fun4220__t {
  struct kk_function_s _base;
  kk_integer_t sz;
};
static kk_box_t kk_climate_dash_experiments__mlift2590_run__experiments_fun4220(kk_function_t _fself, kk_box_t _b_3490, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift2590_run__experiments_fun4220(kk_integer_t sz, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2590_run__experiments_fun4220__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift2590_run__experiments_fun4220__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift2590_run__experiments_fun4220, kk_context());
  _self->sz = sz;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift2590_run__experiments_fun4220(kk_function_t _fself, kk_box_t _b_3490, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2590_run__experiments_fun4220__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift2590_run__experiments_fun4220__t*, _fself);
  kk_integer_t sz = _self->sz; /* int */
  kk_drop_match(_self, {kk_integer_dup(sz);}, {}, _ctx)
  kk_std_core__list _x4221;
  kk_std_core__list _x4222 = kk_std_core__list_unbox(_b_3490, _ctx); /*effects-and-types/histogram<(a : int) -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random,console,ndet,effects-and-types/sample> (double, double)>*/
  _x4221 = kk_sequential__mlift743_smc(true, sz, kk_integer_from_small(4), _x4222, _ctx); /*effects-and-types/histogram<24>*/
  return kk_std_core__list_box(_x4221, _ctx);
}
static kk_box_t kk_climate_dash_experiments__mlift2590_run__experiments_fun4207(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2590_run__experiments_fun4207__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift2590_run__experiments_fun4207__t*, _fself);
  kk_function_t model_2687 = _self->model_2687; /* () -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random,console,ndet,effects-and-types/sample> (double, double) */
  kk_integer_t sz = _self->sz; /* int */
  kk_drop_match(_self, {kk_function_dup(model_2687);kk_integer_dup(sz);}, {}, _ctx)
  kk_std_core__list _x4208;
  kk_std_core__list x_775 = kk_sampling_populate(kk_integer_from_small(100), kk_climate_dash_experiments__new_mlift2590_run__experiments_fun4209(model_2687, _ctx), _ctx); /*effects-and-types/histogram<(a : int) -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random,console,ndet,effects-and-types/sample> (double, double)>*/;
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_775, _ctx);
    kk_box_t _x4219 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments__new_mlift2590_run__experiments_fun4220(sz, _ctx), _ctx); /*2*/
    _x4208 = kk_std_core__list_unbox(_x4219, _ctx); /*effects-and-types/histogram<(double, double)>*/
  }
  else {
    _x4208 = kk_sequential__mlift743_smc(true, sz, kk_integer_from_small(4), x_775, _ctx); /*effects-and-types/histogram<(double, double)>*/
  }
  return kk_std_core__list_box(_x4208, _ctx);
}
static kk_box_t kk_climate_dash_experiments__mlift2590_run__experiments_fun4191(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2590_run__experiments_fun4191__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift2590_run__experiments_fun4191__t*, _fself);
  kk_std_core__list data__vals = _self->data__vals; /* list<(double, bool)> */
  kk_integer_t sz = _self->sz; /* int */
  kk_drop_match(_self, {kk_std_core__list_dup(data__vals);kk_integer_dup(sz);}, {}, _ctx)
  kk_std_core__list _x4192;
  kk_function_t model_2687;
  kk_function_t _x01_2573;
  kk_function_t _bv_3460;
  kk_box_t _x4193 = kk_std_core_hnd__open_none1(kk_climate_dash_experiments__new_mlift2590_run__experiments_fun4194(_ctx), kk_std_core__list_box(data__vals, _ctx), _ctx); /*2*/
  _bv_3460 = kk_function_unbox(_x4193); /*() -> <.Box|.Box> 3459*/
  _x01_2573 = kk_climate_dash_experiments__new_mlift2590_run__experiments_fun4199(_bv_3460, _ctx); /*effects-and-types/model<(double, double),div>*/
  model_2687 = kk_climate_dash_experiments__new_mlift2590_run__experiments_fun4201(_x01_2573, _ctx); /*() -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random,console,ndet,effects-and-types/sample> (double, double)*/
  kk_box_t _x4206 = kk_handlers_random__sampler(kk_climate_dash_experiments__new_mlift2590_run__experiments_fun4207(model_2687, sz, _ctx), _ctx); /*312*/
  _x4192 = kk_std_core__list_unbox(_x4206, _ctx); /*effects-and-types/histogram<(double, double)>*/
  return kk_std_core__list_box(_x4192, _ctx);
}
static kk_box_t kk_climate_dash_experiments__mlift2590_run__experiments_fun4188(kk_function_t _fself, kk_box_t _b_3496, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core_types__tuple2_ _match_3758 = kk_std_core_types__tuple2__unbox(_b_3496, _ctx); /*(int, list<(double, bool)>)*/;
  kk_box_t _box_x3452 = _match_3758.fst;
  kk_box_t _box_x3453 = _match_3758.snd;
  kk_integer_t sz = kk_integer_unbox(_box_x3452);
  kk_std_core__list data__vals = kk_std_core__list_unbox(_box_x3453, NULL);
  return kk_std_time_timer_print_elapsed(kk_climate_dash_experiments__new_mlift2590_run__experiments_fun4191(data__vals, sz, _ctx), kk_std_core_types__new_None(_ctx), _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift2590_run__experiments_fun4224__t {
  struct kk_function_s _base;
  kk_std_core__list data__50;
  kk_std_core__list data__points;
};
static kk_box_t kk_climate_dash_experiments__mlift2590_run__experiments_fun4224(kk_function_t _fself, kk_box_t _b_3506, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift2590_run__experiments_fun4224(kk_std_core__list data__50, kk_std_core__list data__points, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2590_run__experiments_fun4224__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift2590_run__experiments_fun4224__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift2590_run__experiments_fun4224, kk_context());
  _self->data__50 = data__50;
  _self->data__points = data__points;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift2590_run__experiments_fun4224(kk_function_t _fself, kk_box_t _b_3506, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2590_run__experiments_fun4224__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift2590_run__experiments_fun4224__t*, _fself);
  kk_std_core__list data__50 = _self->data__50; /* list<(double, bool)> */
  kk_std_core__list data__points = _self->data__points; /* list<(int, list<(double, bool)>)> */
  kk_drop_match(_self, {kk_std_core__list_dup(data__50);kk_std_core__list_dup(data__points);}, {}, _ctx)
  kk_std_core__list _x4225;
  kk_std_core__list _x4226 = kk_std_core__list_unbox(_b_3506, _ctx); /*list<effects-and-types/histogram<(double, double)>>*/
  _x4225 = kk_climate_dash_experiments__mlift2588_run__experiments(data__50, data__points, _x4226, _ctx); /*list<effects-and-types/histogram<(double, double)>>*/
  return kk_std_core__list_box(_x4225, _ctx);
}
static kk_box_t kk_climate_dash_experiments__mlift2590_run__experiments_fun4185(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2590_run__experiments_fun4185__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift2590_run__experiments_fun4185__t*, _fself);
  kk_std_core__list data__50 = _self->data__50; /* list<(double, bool)> */
  kk_std_core__list data__points = _self->data__points; /* list<(int, list<(double, bool)>)> */
  kk_drop_match(_self, {kk_std_core__list_dup(data__50);kk_std_core__list_dup(data__points);}, {}, _ctx)
  kk_std_core__list _x4186;
  kk_std_core__list x0_2682;
  kk_std_core__list _x4187 = kk_std_core__list_dup(data__points); /*list<(int, list<(double, bool)>)>*/
  x0_2682 = kk_std_core_map_5(_x4187, kk_climate_dash_experiments__new_mlift2590_run__experiments_fun4188(_ctx), _ctx); /*list<effects-and-types/histogram<(double, double)>>*/
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x0_2682, _ctx);
    kk_box_t _x4223 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments__new_mlift2590_run__experiments_fun4224(data__50, data__points, _ctx), _ctx); /*2*/
    _x4186 = kk_std_core__list_unbox(_x4223, _ctx); /*list<effects-and-types/histogram<(double, double)>>*/
  }
  else {
    _x4186 = kk_climate_dash_experiments__mlift2588_run__experiments(data__50, data__points, x0_2682, _ctx); /*list<effects-and-types/histogram<(double, double)>>*/
  }
  return kk_std_core__list_box(_x4186, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift2590_run__experiments_fun4228__t {
  struct kk_function_s _base;
  kk_std_core__list data__50;
  kk_std_core__list data__points;
};
static kk_box_t kk_climate_dash_experiments__mlift2590_run__experiments_fun4228(kk_function_t _fself, kk_box_t _b_3514, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift2590_run__experiments_fun4228(kk_std_core__list data__50, kk_std_core__list data__points, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2590_run__experiments_fun4228__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift2590_run__experiments_fun4228__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift2590_run__experiments_fun4228, kk_context());
  _self->data__50 = data__50;
  _self->data__points = data__points;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift2590_run__experiments_fun4228(kk_function_t _fself, kk_box_t _b_3514, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2590_run__experiments_fun4228__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift2590_run__experiments_fun4228__t*, _fself);
  kk_std_core__list data__50 = _self->data__50; /* list<(double, bool)> */
  kk_std_core__list data__points = _self->data__points; /* list<(int, list<(double, bool)>)> */
  kk_drop_match(_self, {kk_std_core__list_dup(data__50);kk_std_core__list_dup(data__points);}, {}, _ctx)
  kk_unit_t _x4229 = kk_Unit;
  kk_std_core__list _x4230 = kk_std_core__list_unbox(_b_3514, _ctx); /*list<effects-and-types/histogram<(double, double)>>*/
  kk_climate_dash_experiments__mlift2589_run__experiments(data__50, data__points, _x4230, _ctx);
  return kk_unit_box(_x4229);
}
static kk_unit_t kk_climate_dash_experiments__mlift2590_run__experiments_fun4180(kk_function_t _fself, kk_integer_t i1, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2590_run__experiments_fun4180__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift2590_run__experiments_fun4180__t*, _fself);
  kk_std_core__list data__50 = _self->data__50; /* list<(double, bool)> */
  kk_std_core__list data__points = _self->data__points; /* list<(int, list<(double, bool)>)> */
  kk_drop_match(_self, {kk_std_core__list_dup(data__50);kk_std_core__list_dup(data__points);}, {}, _ctx)
  kk_integer_drop(i1, _ctx);
  kk_unit_t __ = kk_Unit;
  kk_string_t _x4181;
  kk_define_string_literal(, _s4182, 31, "Running Sequential Monte Carlo!")
  _x4181 = kk_string_dup(_s4182); /*string*/
  kk_std_core_printsln(_x4181, _ctx);
  kk_std_core__list x_2680;
  kk_box_t _x4183;
  kk_function_t _x4184;
  kk_std_core__list_dup(data__50);
  kk_std_core__list_dup(data__points);
  _x4184 = kk_climate_dash_experiments__new_mlift2590_run__experiments_fun4185(data__50, data__points, _ctx); /*() -> <ndet,console|454> 453*/
  _x4183 = kk_std_time_timer_print_elapsed(_x4184, kk_std_core_types__new_None(_ctx), _ctx); /*453*/
  x_2680 = kk_std_core__list_unbox(_x4183, _ctx); /*list<effects-and-types/histogram<(double, double)>>*/
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_2680, _ctx);
    kk_box_t _x4227 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments__new_mlift2590_run__experiments_fun4228(data__50, data__points, _ctx), _ctx); /*2*/
    return kk_unit_unbox(_x4227);
  }
  return kk_climate_dash_experiments__mlift2589_run__experiments(data__50, data__points, x_2680, _ctx);
}

kk_unit_t kk_climate_dash_experiments__mlift2590_run__experiments(kk_std_core__list data__points, kk_std_core_types__optional number__of__repeats, kk_std_core__list data__50, kk_context_t* _ctx) { /* (data_points : list<(int, list<(double, bool)>)>, number_of_repeats : optional<int>, data_50 : list<(double, bool)>) -> <std/num/random/random,console,div,exn,ndet,effects-and-types/sample> () */ 
  kk_integer_t _x4231;
  if (kk_std_core_types__is_Optional(number__of__repeats)) {
    kk_box_t _box_x3515 = number__of__repeats._cons.Optional.value;
    kk_integer_t _number__of__repeats_1078 = kk_integer_unbox(_box_x3515);
    _x4231 = _number__of__repeats_1078; /*int*/
    goto _match4232;
  }
  _x4231 = kk_integer_from_small(4); /*int*/
  _match4232: ;
  kk_std_core__lift21056_for(kk_climate_dash_experiments__new_mlift2590_run__experiments_fun4180(data__50, data__points, _ctx), _x4231, kk_integer_from_small(1), _ctx); return kk_Unit;
}
 
// monadic lift

kk_std_core_types__tuple2_ kk_climate_dash_experiments__mlift2591_run__experiments(kk_integer_t i0, kk_std_core__list _y_11, kk_context_t* _ctx) { /* (i0 : int, list<(double, bool)>) -> <std/num/random/random,console,div,exn,ndet,effects-and-types/sample> (int, list<(double, bool)>) */ 
  return kk_std_core_types__new_dash__lp__comma__rp_(kk_integer_box(i0), kk_std_core__list_box(_y_11, _ctx), _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_climate_dash_experiments__mlift2592_run__experiments_fun4235__t {
  struct kk_function_s _base;
  size_t i_2691;
};
static kk_box_t kk_climate_dash_experiments__mlift2592_run__experiments_fun4235(kk_function_t _fself, kk_function_t _b_3527, kk_box_t _b_3528, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift2592_run__experiments_fun4235(size_t i_2691, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2592_run__experiments_fun4235__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift2592_run__experiments_fun4235__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift2592_run__experiments_fun4235, kk_context());
  _self->i_2691 = i_2691;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift2592_run__experiments_fun4235(kk_function_t _fself, kk_function_t _b_3527, kk_box_t _b_3528, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2592_run__experiments_fun4235__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift2592_run__experiments_fun4235__t*, _fself);
  size_t i_2691 = _self->i_2691; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_2691, _b_3527, _b_3528, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift2592_run__experiments_fun4237__t {
  struct kk_function_s _base;
  kk_std_core__list data__points;
  kk_std_core_types__optional number__of__repeats;
};
static kk_box_t kk_climate_dash_experiments__mlift2592_run__experiments_fun4237(kk_function_t _fself, kk_box_t _b_3538, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift2592_run__experiments_fun4237(kk_std_core__list data__points, kk_std_core_types__optional number__of__repeats, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2592_run__experiments_fun4237__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift2592_run__experiments_fun4237__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift2592_run__experiments_fun4237, kk_context());
  _self->data__points = data__points;
  _self->number__of__repeats = number__of__repeats;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift2592_run__experiments_fun4237(kk_function_t _fself, kk_box_t _b_3538, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2592_run__experiments_fun4237__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift2592_run__experiments_fun4237__t*, _fself);
  kk_std_core__list data__points = _self->data__points; /* list<(int, list<(double, bool)>)> */
  kk_std_core_types__optional number__of__repeats = _self->number__of__repeats; /* optional<int> */
  kk_drop_match(_self, {kk_std_core__list_dup(data__points);kk_std_core_types__optional_dup(number__of__repeats);}, {}, _ctx)
  kk_unit_t _x4238 = kk_Unit;
  kk_std_core__list _x4239 = kk_std_core__list_unbox(_b_3538, _ctx); /*list<(double, bool)>*/
  kk_climate_dash_experiments__mlift2590_run__experiments(data__points, number__of__repeats, _x4239, _ctx);
  return kk_unit_box(_x4238);
}

kk_unit_t kk_climate_dash_experiments__mlift2592_run__experiments(kk_std_core_types__optional number__of__repeats, kk_std_core__list data__points, kk_context_t* _ctx) { /* (number_of_repeats : optional<int>, data_points : list<(int, list<(double, bool)>)>) -> <std/num/random/random,console,div,exn,ndet,effects-and-types/sample> () */ 
  kk_std_core__list x_2689;
  size_t i_2691 = ((size_t)1); /*std/core/hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_2691,kk_context()); /*std/core/hnd/evv<<std/num/random/random,console,div,exn,ndet,effects-and-types/sample>>*/;
  kk_std_core__list y = kk_model_dash_resources_generate__synthetic__lr__data(kk_integer_from_small(50), _ctx); /*list<(double, bool)>*/;
  kk_unit_t __w_l696_c9 = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(y, _ctx);
    kk_box_t _x4234 = kk_std_core_hnd_yield_cont(kk_climate_dash_experiments__new_mlift2592_run__experiments_fun4235(i_2691, _ctx), _ctx); /*3*/
    x_2689 = kk_std_core__list_unbox(_x4234, _ctx); /*list<(double, bool)>*/
  }
  else {
    x_2689 = y; /*list<(double, bool)>*/
  }
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_2689, _ctx);
    kk_box_t _x4236 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments__new_mlift2592_run__experiments_fun4237(data__points, number__of__repeats, _ctx), _ctx); /*2*/
    kk_unit_unbox(_x4236); return kk_Unit;
  }
  kk_climate_dash_experiments__mlift2590_run__experiments(data__points, number__of__repeats, x_2689, _ctx); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_climate_dash_experiments__mlift2593_run__experiments_fun4240__t {
  struct kk_function_s _base;
};
static kk_box_t kk_climate_dash_experiments__mlift2593_run__experiments_fun4240(kk_function_t _fself, kk_box_t _b_3560, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift2593_run__experiments_fun4240(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_climate_dash_experiments__mlift2593_run__experiments_fun4240, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift2593_run__experiments_fun4245__t {
  struct kk_function_s _base;
  size_t i_2698;
};
static kk_box_t kk_climate_dash_experiments__mlift2593_run__experiments_fun4245(kk_function_t _fself, kk_function_t _b_3546, kk_box_t _b_3547, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift2593_run__experiments_fun4245(size_t i_2698, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2593_run__experiments_fun4245__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift2593_run__experiments_fun4245__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift2593_run__experiments_fun4245, kk_context());
  _self->i_2698 = i_2698;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift2593_run__experiments_fun4245(kk_function_t _fself, kk_function_t _b_3546, kk_box_t _b_3547, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2593_run__experiments_fun4245__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift2593_run__experiments_fun4245__t*, _fself);
  size_t i_2698 = _self->i_2698; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_2698, _b_3546, _b_3547, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift2593_run__experiments_fun4247__t {
  struct kk_function_s _base;
  kk_box_t _b_3560;
};
static kk_box_t kk_climate_dash_experiments__mlift2593_run__experiments_fun4247(kk_function_t _fself, kk_box_t _b_3557, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift2593_run__experiments_fun4247(kk_box_t _b_3560, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2593_run__experiments_fun4247__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift2593_run__experiments_fun4247__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift2593_run__experiments_fun4247, kk_context());
  _self->_b_3560 = _b_3560;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift2593_run__experiments_fun4247(kk_function_t _fself, kk_box_t _b_3557, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2593_run__experiments_fun4247__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift2593_run__experiments_fun4247__t*, _fself);
  kk_box_t _b_3560 = _self->_b_3560; /* 1 */
  kk_drop_match(_self, {kk_box_dup(_b_3560);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x4248;
  kk_integer_t _x4249 = kk_integer_unbox(_b_3560); /*int*/
  kk_std_core__list _x4250 = kk_std_core__list_unbox(_b_3557, _ctx); /*list<(double, bool)>*/
  _x4248 = kk_climate_dash_experiments__mlift2591_run__experiments(_x4249, _x4250, _ctx); /*(int, list<(double, bool)>)*/
  return kk_std_core_types__tuple2__box(_x4248, _ctx);
}
static kk_box_t kk_climate_dash_experiments__mlift2593_run__experiments_fun4240(kk_function_t _fself, kk_box_t _b_3560, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core_types__tuple2_ _x4241;
  kk_std_core__list x0_2696;
  size_t i_2698 = ((size_t)1); /*std/core/hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_2698,kk_context()); /*std/core/hnd/evv<<std/num/random/random,console,div,exn,ndet,effects-and-types/sample>>*/;
  kk_std_core__list y;
  kk_integer_t _x4242;
  kk_box_t _x4243 = kk_box_dup(_b_3560); /*1*/
  _x4242 = kk_integer_unbox(_x4243); /*int*/
  y = kk_model_dash_resources_generate__synthetic__lr__data(_x4242, _ctx); /*list<(double, bool)>*/
  kk_unit_t __w_l696_c9 = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(y, _ctx);
    kk_box_t _x4244 = kk_std_core_hnd_yield_cont(kk_climate_dash_experiments__new_mlift2593_run__experiments_fun4245(i_2698, _ctx), _ctx); /*3*/
    x0_2696 = kk_std_core__list_unbox(_x4244, _ctx); /*list<(double, bool)>*/
  }
  else {
    x0_2696 = y; /*list<(double, bool)>*/
  }
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x0_2696, _ctx);
    kk_box_t _x4246 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments__new_mlift2593_run__experiments_fun4247(_b_3560, _ctx), _ctx); /*2*/
    _x4241 = kk_std_core_types__tuple2__unbox(_x4246, _ctx); /*(int, list<(double, bool)>)*/
  }
  else {
    kk_integer_t _x4251 = kk_integer_unbox(_b_3560); /*int*/
    _x4241 = kk_climate_dash_experiments__mlift2591_run__experiments(_x4251, x0_2696, _ctx); /*(int, list<(double, bool)>)*/
  }
  return kk_std_core_types__tuple2__box(_x4241, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift2593_run__experiments_fun4253__t {
  struct kk_function_s _base;
  kk_std_core_types__optional number__of__repeats;
};
static kk_box_t kk_climate_dash_experiments__mlift2593_run__experiments_fun4253(kk_function_t _fself, kk_box_t _b_3567, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift2593_run__experiments_fun4253(kk_std_core_types__optional number__of__repeats, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2593_run__experiments_fun4253__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift2593_run__experiments_fun4253__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift2593_run__experiments_fun4253, kk_context());
  _self->number__of__repeats = number__of__repeats;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift2593_run__experiments_fun4253(kk_function_t _fself, kk_box_t _b_3567, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift2593_run__experiments_fun4253__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift2593_run__experiments_fun4253__t*, _fself);
  kk_std_core_types__optional number__of__repeats = _self->number__of__repeats; /* optional<int> */
  kk_drop_match(_self, {kk_std_core_types__optional_dup(number__of__repeats);}, {}, _ctx)
  kk_unit_t _x4254 = kk_Unit;
  kk_std_core__list _x4255 = kk_std_core__list_unbox(_b_3567, _ctx); /*list<(int, list<(double, bool)>)>*/
  kk_climate_dash_experiments__mlift2592_run__experiments(number__of__repeats, _x4255, _ctx);
  return kk_unit_box(_x4254);
}

kk_unit_t kk_climate_dash_experiments__mlift2593_run__experiments(kk_std_core_types__optional number__of__repeats, kk_std_core__list _y_10, kk_context_t* _ctx) { /* (number_of_repeats : optional<int>, list<int>) -> <std/num/random/random,console,div,exn,ndet,effects-and-types/sample> () */ 
  kk_std_core__list x_2694 = kk_std_core_map_5(_y_10, kk_climate_dash_experiments__new_mlift2593_run__experiments_fun4240(_ctx), _ctx); /*list<(int, list<(double, bool)>)>*/;
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_2694, _ctx);
    kk_box_t _x4252 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments__new_mlift2593_run__experiments_fun4253(number__of__repeats, _ctx), _ctx); /*2*/
    kk_unit_unbox(_x4252); return kk_Unit;
  }
  kk_climate_dash_experiments__mlift2592_run__experiments(number__of__repeats, x_2694, _ctx); return kk_Unit;
}
 
// Original code has 10 as the max_number_of_data_points, but thi reaches max_memory (heap size of 4 GB on my computer) nad cca 10GB of core data


// lift anonymous function
struct kk_climate_dash_experiments_run__experiments_fun4259__t {
  struct kk_function_s _base;
};
static kk_box_t kk_climate_dash_experiments_run__experiments_fun4259(kk_function_t _fself, kk_box_t _b_3573, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__experiments_fun4259(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_climate_dash_experiments_run__experiments_fun4259, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_climate_dash_experiments_run__experiments_fun4259(kk_function_t _fself, kk_box_t _b_3573, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_integer_t _x4260;
  kk_integer_t _x4261 = kk_integer_unbox(_b_3573); /*int*/
  _x4260 = kk_integer_mul(_x4261,(kk_integer_from_small(100)),kk_context()); /*int*/
  return kk_integer_box(_x4260);
}


// lift anonymous function
struct kk_climate_dash_experiments_run__experiments_fun4263__t {
  struct kk_function_s _base;
  kk_std_core_types__optional number__of__repeats;
};
static kk_box_t kk_climate_dash_experiments_run__experiments_fun4263(kk_function_t _fself, kk_box_t _b_3578, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__experiments_fun4263(kk_std_core_types__optional number__of__repeats, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun4263__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__experiments_fun4263__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__experiments_fun4263, kk_context());
  _self->number__of__repeats = number__of__repeats;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments_run__experiments_fun4263(kk_function_t _fself, kk_box_t _b_3578, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun4263__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__experiments_fun4263__t*, _fself);
  kk_std_core_types__optional number__of__repeats = _self->number__of__repeats; /* optional<int> */
  kk_drop_match(_self, {kk_std_core_types__optional_dup(number__of__repeats);}, {}, _ctx)
  kk_unit_t _x4264 = kk_Unit;
  kk_std_core__list _x4265 = kk_std_core__list_unbox(_b_3578, _ctx); /*list<int>*/
  kk_climate_dash_experiments__mlift2593_run__experiments(number__of__repeats, _x4265, _ctx);
  return kk_unit_box(_x4264);
}


// lift anonymous function
struct kk_climate_dash_experiments_run__experiments_fun4266__t {
  struct kk_function_s _base;
};
static kk_box_t kk_climate_dash_experiments_run__experiments_fun4266(kk_function_t _fself, kk_box_t _b_3598, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__experiments_fun4266(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_climate_dash_experiments_run__experiments_fun4266, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_climate_dash_experiments_run__experiments_fun4271__t {
  struct kk_function_s _base;
  size_t i1_2712;
};
static kk_box_t kk_climate_dash_experiments_run__experiments_fun4271(kk_function_t _fself, kk_function_t _b_3584, kk_box_t _b_3585, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__experiments_fun4271(size_t i1_2712, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun4271__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__experiments_fun4271__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__experiments_fun4271, kk_context());
  _self->i1_2712 = i1_2712;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments_run__experiments_fun4271(kk_function_t _fself, kk_function_t _b_3584, kk_box_t _b_3585, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun4271__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__experiments_fun4271__t*, _fself);
  size_t i1_2712 = _self->i1_2712; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i1_2712, _b_3584, _b_3585, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments_run__experiments_fun4273__t {
  struct kk_function_s _base;
  kk_box_t _b_3598;
};
static kk_box_t kk_climate_dash_experiments_run__experiments_fun4273(kk_function_t _fself, kk_box_t _b_3595, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__experiments_fun4273(kk_box_t _b_3598, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun4273__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__experiments_fun4273__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__experiments_fun4273, kk_context());
  _self->_b_3598 = _b_3598;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments_run__experiments_fun4273(kk_function_t _fself, kk_box_t _b_3595, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun4273__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__experiments_fun4273__t*, _fself);
  kk_box_t _b_3598 = _self->_b_3598; /* 1 */
  kk_drop_match(_self, {kk_box_dup(_b_3598);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x4274;
  kk_integer_t _x4275 = kk_integer_unbox(_b_3598); /*int*/
  kk_std_core__list _x4276 = kk_std_core__list_unbox(_b_3595, _ctx); /*list<(double, bool)>*/
  _x4274 = kk_climate_dash_experiments__mlift2591_run__experiments(_x4275, _x4276, _ctx); /*(int, list<(double, bool)>)*/
  return kk_std_core_types__tuple2__box(_x4274, _ctx);
}
static kk_box_t kk_climate_dash_experiments_run__experiments_fun4266(kk_function_t _fself, kk_box_t _b_3598, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core_types__tuple2_ _x4267;
  kk_std_core__list x1_2710;
  size_t i1_2712 = ((size_t)1); /*std/core/hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i1_2712,kk_context()); /*std/core/hnd/evv<<std/num/random/random,console,div,exn,ndet,effects-and-types/sample>>*/;
  kk_std_core__list y;
  kk_integer_t _x4268;
  kk_box_t _x4269 = kk_box_dup(_b_3598); /*1*/
  _x4268 = kk_integer_unbox(_x4269); /*int*/
  y = kk_model_dash_resources_generate__synthetic__lr__data(_x4268, _ctx); /*list<(double, bool)>*/
  kk_unit_t __w_l696_c9 = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(y, _ctx);
    kk_box_t _x4270 = kk_std_core_hnd_yield_cont(kk_climate_dash_experiments_new_run__experiments_fun4271(i1_2712, _ctx), _ctx); /*3*/
    x1_2710 = kk_std_core__list_unbox(_x4270, _ctx); /*list<(double, bool)>*/
  }
  else {
    x1_2710 = y; /*list<(double, bool)>*/
  }
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x1_2710, _ctx);
    kk_box_t _x4272 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments_new_run__experiments_fun4273(_b_3598, _ctx), _ctx); /*2*/
    _x4267 = kk_std_core_types__tuple2__unbox(_x4272, _ctx); /*(int, list<(double, bool)>)*/
  }
  else {
    kk_integer_t _x4277 = kk_integer_unbox(_b_3598); /*int*/
    _x4267 = kk_climate_dash_experiments__mlift2591_run__experiments(_x4277, x1_2710, _ctx); /*(int, list<(double, bool)>)*/
  }
  return kk_std_core_types__tuple2__box(_x4267, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments_run__experiments_fun4279__t {
  struct kk_function_s _base;
  kk_std_core_types__optional number__of__repeats;
};
static kk_box_t kk_climate_dash_experiments_run__experiments_fun4279(kk_function_t _fself, kk_box_t _b_3605, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__experiments_fun4279(kk_std_core_types__optional number__of__repeats, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun4279__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__experiments_fun4279__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__experiments_fun4279, kk_context());
  _self->number__of__repeats = number__of__repeats;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments_run__experiments_fun4279(kk_function_t _fself, kk_box_t _b_3605, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun4279__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__experiments_fun4279__t*, _fself);
  kk_std_core_types__optional number__of__repeats = _self->number__of__repeats; /* optional<int> */
  kk_drop_match(_self, {kk_std_core_types__optional_dup(number__of__repeats);}, {}, _ctx)
  kk_unit_t _x4280 = kk_Unit;
  kk_std_core__list _x4281 = kk_std_core__list_unbox(_b_3605, _ctx); /*list<(int, list<(double, bool)>)>*/
  kk_climate_dash_experiments__mlift2592_run__experiments(number__of__repeats, _x4281, _ctx);
  return kk_unit_box(_x4280);
}


// lift anonymous function
struct kk_climate_dash_experiments_run__experiments_fun4283__t {
  struct kk_function_s _base;
  size_t i2_2719;
};
static kk_box_t kk_climate_dash_experiments_run__experiments_fun4283(kk_function_t _fself, kk_function_t _b_3611, kk_box_t _b_3612, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__experiments_fun4283(size_t i2_2719, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun4283__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__experiments_fun4283__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__experiments_fun4283, kk_context());
  _self->i2_2719 = i2_2719;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments_run__experiments_fun4283(kk_function_t _fself, kk_function_t _b_3611, kk_box_t _b_3612, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun4283__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__experiments_fun4283__t*, _fself);
  size_t i2_2719 = _self->i2_2719; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i2_2719, _b_3611, _b_3612, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments_run__experiments_fun4285__t {
  struct kk_function_s _base;
  kk_std_core_types__optional number__of__repeats;
  kk_std_core__list x0_2707;
};
static kk_box_t kk_climate_dash_experiments_run__experiments_fun4285(kk_function_t _fself, kk_box_t _b_3622, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__experiments_fun4285(kk_std_core_types__optional number__of__repeats, kk_std_core__list x0_2707, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun4285__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__experiments_fun4285__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__experiments_fun4285, kk_context());
  _self->number__of__repeats = number__of__repeats;
  _self->x0_2707 = x0_2707;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments_run__experiments_fun4285(kk_function_t _fself, kk_box_t _b_3622, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun4285__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__experiments_fun4285__t*, _fself);
  kk_std_core_types__optional number__of__repeats = _self->number__of__repeats; /* optional<int> */
  kk_std_core__list x0_2707 = _self->x0_2707; /* list<(int, list<(double, bool)>)> */
  kk_drop_match(_self, {kk_std_core_types__optional_dup(number__of__repeats);kk_std_core__list_dup(x0_2707);}, {}, _ctx)
  kk_unit_t _x4286 = kk_Unit;
  kk_std_core__list _x4287 = kk_std_core__list_unbox(_b_3622, _ctx); /*list<(double, bool)>*/
  kk_climate_dash_experiments__mlift2590_run__experiments(x0_2707, number__of__repeats, _x4287, _ctx);
  return kk_unit_box(_x4286);
}


// lift anonymous function
struct kk_climate_dash_experiments_run__experiments_fun4288__t {
  struct kk_function_s _base;
  kk_std_core__list x0_2707;
  kk_std_core__list x3_2716;
};
static kk_unit_t kk_climate_dash_experiments_run__experiments_fun4288(kk_function_t _fself, kk_integer_t i10, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__experiments_fun4288(kk_std_core__list x0_2707, kk_std_core__list x3_2716, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun4288__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__experiments_fun4288__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__experiments_fun4288, kk_context());
  _self->x0_2707 = x0_2707;
  _self->x3_2716 = x3_2716;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments_run__experiments_fun4293__t {
  struct kk_function_s _base;
  kk_std_core__list x0_2707;
  kk_std_core__list x3_2716;
};
static kk_box_t kk_climate_dash_experiments_run__experiments_fun4293(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__experiments_fun4293(kk_std_core__list x0_2707, kk_std_core__list x3_2716, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun4293__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__experiments_fun4293__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__experiments_fun4293, kk_context());
  _self->x0_2707 = x0_2707;
  _self->x3_2716 = x3_2716;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments_run__experiments_fun4296__t {
  struct kk_function_s _base;
};
static kk_box_t kk_climate_dash_experiments_run__experiments_fun4296(kk_function_t _fself, kk_box_t _b_3667, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__experiments_fun4296(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_climate_dash_experiments_run__experiments_fun4296, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_climate_dash_experiments_run__experiments_fun4299__t {
  struct kk_function_s _base;
  kk_std_core__list data__vals;
  kk_integer_t sz;
};
static kk_box_t kk_climate_dash_experiments_run__experiments_fun4299(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__experiments_fun4299(kk_std_core__list data__vals, kk_integer_t sz, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun4299__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__experiments_fun4299__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__experiments_fun4299, kk_context());
  _self->data__vals = data__vals;
  _self->sz = sz;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments_run__experiments_fun4302__t {
  struct kk_function_s _base;
};
static kk_box_t kk_climate_dash_experiments_run__experiments_fun4302(kk_function_t _fself, kk_box_t _b_3627, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__experiments_fun4302(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_climate_dash_experiments_run__experiments_fun4302, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_climate_dash_experiments_run__experiments_fun4305__t {
  struct kk_function_s _base;
  kk_function_t _bv_3629;
};
static kk_box_t kk_climate_dash_experiments_run__experiments_fun4305(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__experiments_fun4305(kk_function_t _bv_3629, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun4305__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__experiments_fun4305__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__experiments_fun4305, kk_context());
  _self->_bv_3629 = _bv_3629;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments_run__experiments_fun4305(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun4305__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__experiments_fun4305__t*, _fself);
  kk_function_t _bv_3629 = _self->_bv_3629; /* effects-and-types/model<(double, double),div> */
  kk_drop_match(_self, {kk_function_dup(_bv_3629);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x4306 = kk_function_call(kk_std_core_types__tuple2_, (kk_function_t, kk_context_t*), _bv_3629, (_bv_3629, _ctx)); /*(double, double)*/
  return kk_std_core_types__tuple2__box(_x4306, _ctx);
}
static kk_box_t kk_climate_dash_experiments_run__experiments_fun4302(kk_function_t _fself, kk_box_t _b_3627, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_function_t _x4303;
  kk_function_t _bv_3629;
  kk_std_core__list _x4304 = kk_std_core__list_unbox(_b_3627, _ctx); /*list<(double, bool)>*/
  _bv_3629 = kk_model_dash_resources_logistic__regression(_x4304, _ctx); /*effects-and-types/model<(double, double),div>*/
  _x4303 = kk_climate_dash_experiments_new_run__experiments_fun4305(_bv_3629, _ctx); /*() -> <div,effects-and-types/sample,effects-and-types/score> 3628*/
  return kk_function_box(_x4303);
}


// lift anonymous function
struct kk_climate_dash_experiments_run__experiments_fun4307__t {
  struct kk_function_s _base;
  kk_function_t _bv_3631;
};
static kk_std_core_types__tuple2_ kk_climate_dash_experiments_run__experiments_fun4307(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__experiments_fun4307(kk_function_t _bv_3631, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun4307__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__experiments_fun4307__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__experiments_fun4307, kk_context());
  _self->_bv_3631 = _bv_3631;
  return &_self->_base;
}

static kk_std_core_types__tuple2_ kk_climate_dash_experiments_run__experiments_fun4307(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun4307__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__experiments_fun4307__t*, _fself);
  kk_function_t _bv_3631 = _self->_bv_3631; /* () -> <.Box|.Box> 3630 */
  kk_drop_match(_self, {kk_function_dup(_bv_3631);}, {}, _ctx)
  kk_box_t _x4308 = kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), _bv_3631, (_bv_3631, _ctx)); /*3630*/
  return kk_std_core_types__tuple2__unbox(_x4308, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments_run__experiments_fun4309__t {
  struct kk_function_s _base;
  kk_function_t _x01_2573;
};
static kk_std_core_types__tuple2_ kk_climate_dash_experiments_run__experiments_fun4309(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__experiments_fun4309(kk_function_t _x01_2573, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun4309__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__experiments_fun4309__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__experiments_fun4309, kk_context());
  _self->_x01_2573 = _x01_2573;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments_run__experiments_fun4312__t {
  struct kk_function_s _base;
  kk_function_t _x01_2573;
};
static kk_box_t kk_climate_dash_experiments_run__experiments_fun4312(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__experiments_fun4312(kk_function_t _x01_2573, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun4312__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__experiments_fun4312__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__experiments_fun4312, kk_context());
  _self->_x01_2573 = _x01_2573;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments_run__experiments_fun4312(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun4312__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__experiments_fun4312__t*, _fself);
  kk_function_t _x01_2573 = _self->_x01_2573; /* effects-and-types/model<(double, double),div> */
  kk_drop_match(_self, {kk_function_dup(_x01_2573);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x4313 = kk_function_call(kk_std_core_types__tuple2_, (kk_function_t, kk_context_t*), _x01_2573, (_x01_2573, _ctx)); /*(double, double)*/
  return kk_std_core_types__tuple2__box(_x4313, _ctx);
}
static kk_std_core_types__tuple2_ kk_climate_dash_experiments_run__experiments_fun4309(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun4309__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__experiments_fun4309__t*, _fself);
  kk_function_t _x01_2573 = _self->_x01_2573; /* effects-and-types/model<(double, double),div> */
  kk_drop_match(_self, {kk_function_dup(_x01_2573);}, {}, _ctx)
  kk_vector_t _b_3640_3638;
  kk_std_core__list _x4310;
  size_t _b_3642_3636 = ((size_t)2); /*std/core/hnd/ev-index*/;
  kk_std_core__list _b_3643_3637;
  size_t _b_3644_3634 = ((size_t)4); /*std/core/hnd/ev-index*/;
  _b_3643_3637 = kk_std_core__new_Cons(kk_reuse_null, kk_size_box(_b_3644_3634, _ctx), kk_std_core__new_Nil(_ctx), _ctx); /*list<std/core/hnd/ev-index>*/
  _x4310 = kk_std_core__new_Cons(kk_reuse_null, kk_size_box(_b_3642_3636, _ctx), _b_3643_3637, _ctx); /*list<0>*/
  _b_3640_3638 = kk_std_core_unvlist(_x4310, _ctx); /*vector<std/core/hnd/ev-index>*/
  kk_box_t _x4311 = kk_std_core_hnd__open0(_b_3640_3638, kk_climate_dash_experiments_new_run__experiments_fun4312(_x01_2573, _ctx), _ctx); /*1*/
  return kk_std_core_types__tuple2__unbox(_x4311, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments_run__experiments_fun4315__t {
  struct kk_function_s _base;
  kk_function_t model_2734;
  kk_integer_t sz;
};
static kk_box_t kk_climate_dash_experiments_run__experiments_fun4315(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__experiments_fun4315(kk_function_t model_2734, kk_integer_t sz, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun4315__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__experiments_fun4315__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__experiments_fun4315, kk_context());
  _self->model_2734 = model_2734;
  _self->sz = sz;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments_run__experiments_fun4317__t {
  struct kk_function_s _base;
  kk_function_t model_2734;
};
static kk_box_t kk_climate_dash_experiments_run__experiments_fun4317(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__experiments_fun4317(kk_function_t model_2734, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun4317__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__experiments_fun4317__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__experiments_fun4317, kk_context());
  _self->model_2734 = model_2734;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments_run__experiments_fun4319__t {
  struct kk_function_s _base;
  kk_function_t model_2734;
};
static kk_box_t kk_climate_dash_experiments_run__experiments_fun4319(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__experiments_fun4319(kk_function_t model_2734, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun4319__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__experiments_fun4319__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__experiments_fun4319, kk_context());
  _self->model_2734 = model_2734;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments_run__experiments_fun4320__t {
  struct kk_function_s _base;
  kk_function_t model_2734;
};
static kk_box_t kk_climate_dash_experiments_run__experiments_fun4320(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__experiments_fun4320(kk_function_t model_2734, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun4320__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__experiments_fun4320__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__experiments_fun4320, kk_context());
  _self->model_2734 = model_2734;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments_run__experiments_fun4320(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun4320__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__experiments_fun4320__t*, _fself);
  kk_function_t model_2734 = _self->model_2734; /* () -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random,console,ndet,effects-and-types/sample> (double, double) */
  kk_drop_match(_self, {kk_function_dup(model_2734);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x4321 = kk_function_call(kk_std_core_types__tuple2_, (kk_function_t, kk_context_t*), model_2734, (model_2734, _ctx)); /*(double, double)*/
  return kk_std_core_types__tuple2__box(_x4321, _ctx);
}
static kk_box_t kk_climate_dash_experiments_run__experiments_fun4319(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun4319__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__experiments_fun4319__t*, _fself);
  kk_function_t model_2734 = _self->model_2734; /* () -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random,console,ndet,effects-and-types/sample> (double, double) */
  kk_drop_match(_self, {kk_function_dup(model_2734);}, {}, _ctx)
  return kk_handlers_yield__on__score(kk_climate_dash_experiments_new_run__experiments_fun4320(model_2734, _ctx), _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments_run__experiments_fun4322__t {
  struct kk_function_s _base;
  kk_function_t _bv_3648;
};
static kk_std_core_types__tuple2_ kk_climate_dash_experiments_run__experiments_fun4322(kk_function_t _fself, kk_integer_t _b_3649, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__experiments_fun4322(kk_function_t _bv_3648, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun4322__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__experiments_fun4322__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__experiments_fun4322, kk_context());
  _self->_bv_3648 = _bv_3648;
  return &_self->_base;
}

static kk_std_core_types__tuple2_ kk_climate_dash_experiments_run__experiments_fun4322(kk_function_t _fself, kk_integer_t _b_3649, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun4322__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__experiments_fun4322__t*, _fself);
  kk_function_t _bv_3648 = _self->_bv_3648; /* (a : int) -> <effects-and-types/yield|215> 214 */
  kk_drop_match(_self, {kk_function_dup(_bv_3648);}, {}, _ctx)
  kk_box_t _x4323 = kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_context_t*), _bv_3648, (_bv_3648, _b_3649, _ctx)); /*214*/
  return kk_std_core_types__tuple2__unbox(_x4323, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments_run__experiments_fun4324__t {
  struct kk_function_s _base;
  kk_function_t _bv_3654;
};
static kk_box_t kk_climate_dash_experiments_run__experiments_fun4324(kk_function_t _fself, kk_box_t _b_3655, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__experiments_fun4324(kk_function_t _bv_3654, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun4324__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__experiments_fun4324__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__experiments_fun4324, kk_context());
  _self->_bv_3654 = _bv_3654;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments_run__experiments_fun4324(kk_function_t _fself, kk_box_t _b_3655, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun4324__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__experiments_fun4324__t*, _fself);
  kk_function_t _bv_3654 = _self->_bv_3654; /* (a : int) -> <effects-and-types/yield,effects-and-types/sample,effects-and-types/score,div,exn,std/num/random/random,console,ndet,effects-and-types/sample> (double, double) */
  kk_drop_match(_self, {kk_function_dup(_bv_3654);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x4325;
  kk_integer_t _x4326 = kk_integer_unbox(_b_3655); /*int*/
  _x4325 = kk_function_call(kk_std_core_types__tuple2_, (kk_function_t, kk_integer_t, kk_context_t*), _bv_3654, (_bv_3654, _x4326, _ctx)); /*(double, double)*/
  return kk_std_core_types__tuple2__box(_x4325, _ctx);
}
static kk_box_t kk_climate_dash_experiments_run__experiments_fun4317(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun4317__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__experiments_fun4317__t*, _fself);
  kk_function_t model_2734 = _self->model_2734; /* () -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random,console,ndet,effects-and-types/sample> (double, double) */
  kk_drop_match(_self, {kk_function_dup(model_2734);}, {}, _ctx)
  kk_function_t _x4318;
  kk_function_t _bv_3654;
  kk_function_t _bv_3648 = kk_handlers_advance(kk_climate_dash_experiments_new_run__experiments_fun4319(model_2734, _ctx), _ctx); /*(a : int) -> <effects-and-types/yield|215> 214*/;
  _bv_3654 = kk_climate_dash_experiments_new_run__experiments_fun4322(_bv_3648, _ctx); /*(a : int) -> <effects-and-types/yield,effects-and-types/sample,effects-and-types/score,div,exn,std/num/random/random,console,ndet,effects-and-types/sample> (double, double)*/
  _x4318 = kk_climate_dash_experiments_new_run__experiments_fun4324(_bv_3654, _ctx); /*(3652) -> <effects-and-types/yield,effects-and-types/sample,effects-and-types/score,div,exn,std/num/random/random,console,ndet,effects-and-types/sample> 3653*/
  return kk_function_box(_x4318);
}


// lift anonymous function
struct kk_climate_dash_experiments_run__experiments_fun4328__t {
  struct kk_function_s _base;
  kk_integer_t sz;
};
static kk_box_t kk_climate_dash_experiments_run__experiments_fun4328(kk_function_t _fself, kk_box_t _b_3661, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__experiments_fun4328(kk_integer_t sz, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun4328__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__experiments_fun4328__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__experiments_fun4328, kk_context());
  _self->sz = sz;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments_run__experiments_fun4328(kk_function_t _fself, kk_box_t _b_3661, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun4328__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__experiments_fun4328__t*, _fself);
  kk_integer_t sz = _self->sz; /* int */
  kk_drop_match(_self, {kk_integer_dup(sz);}, {}, _ctx)
  kk_std_core__list _x4329;
  kk_std_core__list _x4330 = kk_std_core__list_unbox(_b_3661, _ctx); /*effects-and-types/histogram<(a : int) -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random,console,ndet,effects-and-types/sample> (double, double)>*/
  _x4329 = kk_sequential__mlift743_smc(true, sz, kk_integer_from_small(4), _x4330, _ctx); /*effects-and-types/histogram<24>*/
  return kk_std_core__list_box(_x4329, _ctx);
}
static kk_box_t kk_climate_dash_experiments_run__experiments_fun4315(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun4315__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__experiments_fun4315__t*, _fself);
  kk_function_t model_2734 = _self->model_2734; /* () -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random,console,ndet,effects-and-types/sample> (double, double) */
  kk_integer_t sz = _self->sz; /* int */
  kk_drop_match(_self, {kk_function_dup(model_2734);kk_integer_dup(sz);}, {}, _ctx)
  kk_std_core__list _x4316;
  kk_std_core__list x_775 = kk_sampling_populate(kk_integer_from_small(100), kk_climate_dash_experiments_new_run__experiments_fun4317(model_2734, _ctx), _ctx); /*effects-and-types/histogram<(a : int) -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random,console,ndet,effects-and-types/sample> (double, double)>*/;
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_775, _ctx);
    kk_box_t _x4327 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments_new_run__experiments_fun4328(sz, _ctx), _ctx); /*2*/
    _x4316 = kk_std_core__list_unbox(_x4327, _ctx); /*effects-and-types/histogram<(double, double)>*/
  }
  else {
    _x4316 = kk_sequential__mlift743_smc(true, sz, kk_integer_from_small(4), x_775, _ctx); /*effects-and-types/histogram<(double, double)>*/
  }
  return kk_std_core__list_box(_x4316, _ctx);
}
static kk_box_t kk_climate_dash_experiments_run__experiments_fun4299(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun4299__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__experiments_fun4299__t*, _fself);
  kk_std_core__list data__vals = _self->data__vals; /* list<(double, bool)> */
  kk_integer_t sz = _self->sz; /* int */
  kk_drop_match(_self, {kk_std_core__list_dup(data__vals);kk_integer_dup(sz);}, {}, _ctx)
  kk_std_core__list _x4300;
  kk_function_t model_2734;
  kk_function_t _x01_2573;
  kk_function_t _bv_3631;
  kk_box_t _x4301 = kk_std_core_hnd__open_none1(kk_climate_dash_experiments_new_run__experiments_fun4302(_ctx), kk_std_core__list_box(data__vals, _ctx), _ctx); /*2*/
  _bv_3631 = kk_function_unbox(_x4301); /*() -> <.Box|.Box> 3630*/
  _x01_2573 = kk_climate_dash_experiments_new_run__experiments_fun4307(_bv_3631, _ctx); /*effects-and-types/model<(double, double),div>*/
  model_2734 = kk_climate_dash_experiments_new_run__experiments_fun4309(_x01_2573, _ctx); /*() -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random,console,ndet,effects-and-types/sample> (double, double)*/
  kk_box_t _x4314 = kk_handlers_random__sampler(kk_climate_dash_experiments_new_run__experiments_fun4315(model_2734, sz, _ctx), _ctx); /*312*/
  _x4300 = kk_std_core__list_unbox(_x4314, _ctx); /*effects-and-types/histogram<(double, double)>*/
  return kk_std_core__list_box(_x4300, _ctx);
}
static kk_box_t kk_climate_dash_experiments_run__experiments_fun4296(kk_function_t _fself, kk_box_t _b_3667, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core_types__tuple2_ _match_3746 = kk_std_core_types__tuple2__unbox(_b_3667, _ctx); /*(int, list<(double, bool)>)*/;
  kk_box_t _box_x3623 = _match_3746.fst;
  kk_box_t _box_x3624 = _match_3746.snd;
  kk_integer_t sz = kk_integer_unbox(_box_x3623);
  kk_std_core__list data__vals = kk_std_core__list_unbox(_box_x3624, NULL);
  return kk_std_time_timer_print_elapsed(kk_climate_dash_experiments_new_run__experiments_fun4299(data__vals, sz, _ctx), kk_std_core_types__new_None(_ctx), _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments_run__experiments_fun4332__t {
  struct kk_function_s _base;
  kk_std_core__list x0_2707;
  kk_std_core__list x3_2716;
};
static kk_box_t kk_climate_dash_experiments_run__experiments_fun4332(kk_function_t _fself, kk_box_t _b_3677, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__experiments_fun4332(kk_std_core__list x0_2707, kk_std_core__list x3_2716, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun4332__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__experiments_fun4332__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__experiments_fun4332, kk_context());
  _self->x0_2707 = x0_2707;
  _self->x3_2716 = x3_2716;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments_run__experiments_fun4332(kk_function_t _fself, kk_box_t _b_3677, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun4332__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__experiments_fun4332__t*, _fself);
  kk_std_core__list x0_2707 = _self->x0_2707; /* list<(int, list<(double, bool)>)> */
  kk_std_core__list x3_2716 = _self->x3_2716; /* list<(double, bool)> */
  kk_drop_match(_self, {kk_std_core__list_dup(x0_2707);kk_std_core__list_dup(x3_2716);}, {}, _ctx)
  kk_std_core__list _x4333;
  kk_std_core__list _x4334 = kk_std_core__list_unbox(_b_3677, _ctx); /*list<effects-and-types/histogram<(double, double)>>*/
  _x4333 = kk_climate_dash_experiments__mlift2588_run__experiments(x3_2716, x0_2707, _x4334, _ctx); /*list<effects-and-types/histogram<(double, double)>>*/
  return kk_std_core__list_box(_x4333, _ctx);
}
static kk_box_t kk_climate_dash_experiments_run__experiments_fun4293(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun4293__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__experiments_fun4293__t*, _fself);
  kk_std_core__list x0_2707 = _self->x0_2707; /* list<(int, list<(double, bool)>)> */
  kk_std_core__list x3_2716 = _self->x3_2716; /* list<(double, bool)> */
  kk_drop_match(_self, {kk_std_core__list_dup(x0_2707);kk_std_core__list_dup(x3_2716);}, {}, _ctx)
  kk_std_core__list _x4294;
  kk_std_core__list x6_2729;
  kk_std_core__list _x4295 = kk_std_core__list_dup(x0_2707); /*list<(int, list<(double, bool)>)>*/
  x6_2729 = kk_std_core_map_5(_x4295, kk_climate_dash_experiments_new_run__experiments_fun4296(_ctx), _ctx); /*list<effects-and-types/histogram<(double, double)>>*/
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x6_2729, _ctx);
    kk_box_t _x4331 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments_new_run__experiments_fun4332(x0_2707, x3_2716, _ctx), _ctx); /*2*/
    _x4294 = kk_std_core__list_unbox(_x4331, _ctx); /*list<effects-and-types/histogram<(double, double)>>*/
  }
  else {
    _x4294 = kk_climate_dash_experiments__mlift2588_run__experiments(x3_2716, x0_2707, x6_2729, _ctx); /*list<effects-and-types/histogram<(double, double)>>*/
  }
  return kk_std_core__list_box(_x4294, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments_run__experiments_fun4336__t {
  struct kk_function_s _base;
  kk_std_core__list x0_2707;
  kk_std_core__list x3_2716;
};
static kk_box_t kk_climate_dash_experiments_run__experiments_fun4336(kk_function_t _fself, kk_box_t _b_3685, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__experiments_fun4336(kk_std_core__list x0_2707, kk_std_core__list x3_2716, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun4336__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__experiments_fun4336__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__experiments_fun4336, kk_context());
  _self->x0_2707 = x0_2707;
  _self->x3_2716 = x3_2716;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments_run__experiments_fun4336(kk_function_t _fself, kk_box_t _b_3685, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun4336__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__experiments_fun4336__t*, _fself);
  kk_std_core__list x0_2707 = _self->x0_2707; /* list<(int, list<(double, bool)>)> */
  kk_std_core__list x3_2716 = _self->x3_2716; /* list<(double, bool)> */
  kk_drop_match(_self, {kk_std_core__list_dup(x0_2707);kk_std_core__list_dup(x3_2716);}, {}, _ctx)
  kk_unit_t _x4337 = kk_Unit;
  kk_std_core__list _x4338 = kk_std_core__list_unbox(_b_3685, _ctx); /*list<effects-and-types/histogram<(double, double)>>*/
  kk_climate_dash_experiments__mlift2589_run__experiments(x3_2716, x0_2707, _x4338, _ctx);
  return kk_unit_box(_x4337);
}
static kk_unit_t kk_climate_dash_experiments_run__experiments_fun4288(kk_function_t _fself, kk_integer_t i10, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun4288__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__experiments_fun4288__t*, _fself);
  kk_std_core__list x0_2707 = _self->x0_2707; /* list<(int, list<(double, bool)>)> */
  kk_std_core__list x3_2716 = _self->x3_2716; /* list<(double, bool)> */
  kk_drop_match(_self, {kk_std_core__list_dup(x0_2707);kk_std_core__list_dup(x3_2716);}, {}, _ctx)
  kk_integer_drop(i10, _ctx);
  kk_unit_t __ = kk_Unit;
  kk_string_t _x4289;
  kk_define_string_literal(, _s4290, 31, "Running Sequential Monte Carlo!")
  _x4289 = kk_string_dup(_s4290); /*string*/
  kk_std_core_printsln(_x4289, _ctx);
  kk_std_core__list x5_2727;
  kk_box_t _x4291;
  kk_function_t _x4292;
  kk_std_core__list_dup(x0_2707);
  kk_std_core__list_dup(x3_2716);
  _x4292 = kk_climate_dash_experiments_new_run__experiments_fun4293(x0_2707, x3_2716, _ctx); /*() -> <ndet,console|454> 453*/
  _x4291 = kk_std_time_timer_print_elapsed(_x4292, kk_std_core_types__new_None(_ctx), _ctx); /*453*/
  x5_2727 = kk_std_core__list_unbox(_x4291, _ctx); /*list<effects-and-types/histogram<(double, double)>>*/
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x5_2727, _ctx);
    kk_box_t _x4335 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments_new_run__experiments_fun4336(x0_2707, x3_2716, _ctx), _ctx); /*2*/
    return kk_unit_unbox(_x4335);
  }
  return kk_climate_dash_experiments__mlift2589_run__experiments(x3_2716, x0_2707, x5_2727, _ctx);
}

kk_unit_t kk_climate_dash_experiments_run__experiments(kk_std_core_types__optional number__of__repeats, kk_std_core_types__optional max__number__of__data__points, kk_context_t* _ctx) { /* (number_of_repeats : optional<int>, max_number_of_data_points : optional<int>) -> <pure,console,ndet,std/num/random/random,effects-and-types/sample> () */ 
  kk_std_core__list x_2701;
  kk_std_core__list _b_3574_3571;
  kk_integer_t _x4256;
  if (kk_std_core_types__is_Optional(max__number__of__data__points)) {
    kk_box_t _box_x3570 = max__number__of__data__points._cons.Optional.value;
    kk_integer_t _max__number__of__data__points_1082 = kk_integer_unbox(_box_x3570);
    _x4256 = _max__number__of__data__points_1082; /*int*/
    goto _match4257;
  }
  _x4256 = kk_integer_from_small(3); /*int*/
  _match4257: ;
  _b_3574_3571 = kk_std_core__lift21053_list(kk_integer_from_small(0), _x4256, kk_std_core__new_Nil(_ctx), _ctx); /*list<int>*/
  x_2701 = kk_std_core_map_5(_b_3574_3571, kk_climate_dash_experiments_new_run__experiments_fun4259(_ctx), _ctx); /*list<int>*/
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_2701, _ctx);
    kk_box_t _x4262 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments_new_run__experiments_fun4263(number__of__repeats, _ctx), _ctx); /*2*/
    kk_unit_unbox(_x4262); return kk_Unit;
  }
  kk_std_core__list x0_2707 = kk_std_core_map_5(x_2701, kk_climate_dash_experiments_new_run__experiments_fun4266(_ctx), _ctx); /*list<(int, list<(double, bool)>)>*/;
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x0_2707, _ctx);
    kk_box_t _x4278 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments_new_run__experiments_fun4279(number__of__repeats, _ctx), _ctx); /*2*/
    kk_unit_unbox(_x4278); return kk_Unit;
  }
  kk_std_core__list x3_2716;
  size_t i2_2719 = ((size_t)1); /*std/core/hnd/ev-index*/;
  kk_evv_t w0 = kk_evv_swap_create1(i2_2719,kk_context()); /*std/core/hnd/evv<<std/num/random/random,console,div,exn,ndet,effects-and-types/sample>>*/;
  kk_std_core__list y0 = kk_model_dash_resources_generate__synthetic__lr__data(kk_integer_from_small(50), _ctx); /*list<(double, bool)>*/;
  kk_unit_t __w_l696_c90 = kk_Unit;
  kk_evv_set(w0,kk_context());
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(y0, _ctx);
    kk_box_t _x4282 = kk_std_core_hnd_yield_cont(kk_climate_dash_experiments_new_run__experiments_fun4283(i2_2719, _ctx), _ctx); /*3*/
    x3_2716 = kk_std_core__list_unbox(_x4282, _ctx); /*list<(double, bool)>*/
  }
  else {
    x3_2716 = y0; /*list<(double, bool)>*/
  }
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x3_2716, _ctx);
    kk_box_t _x4284 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments_new_run__experiments_fun4285(number__of__repeats, x0_2707, _ctx), _ctx); /*2*/
    kk_unit_unbox(_x4284); return kk_Unit;
  }
  kk_integer_t _x4339;
  if (kk_std_core_types__is_Optional(number__of__repeats)) {
    kk_box_t _box_x3686 = number__of__repeats._cons.Optional.value;
    kk_integer_t _number__of__repeats_1078 = kk_integer_unbox(_box_x3686);
    _x4339 = _number__of__repeats_1078; /*int*/
    goto _match4340;
  }
  _x4339 = kk_integer_from_small(4); /*int*/
  _match4340: ;
  kk_std_core__lift21056_for(kk_climate_dash_experiments_new_run__experiments_fun4288(x0_2707, x3_2716, _ctx), _x4339, kk_integer_from_small(1), _ctx); return kk_Unit;
}
 
// monadic lift

kk_unit_t kk_climate_dash_experiments__mlift2594_main(kk_unit_t wild__3, kk_context_t* _ctx) { /* (wild_3 : ()) -> <pure,console,fsys,ndet,std/num/random/random> () */ 
  kk_unit_t __4 = kk_Unit;
  kk_string_t _x4342;
  kk_define_string_literal(, _s4343, 24, "Completed Climate Model!")
  _x4342 = kk_string_dup(_s4343); /*string*/
  kk_std_core_printsln(_x4342, _ctx);
  kk_string_t _x4344;
  kk_define_string_literal(, _s4345, 19, "Finished running...")
  _x4344 = kk_string_dup(_s4345); /*string*/
  kk_std_core_printsln(_x4344, _ctx); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_climate_dash_experiments__mlift2595_main_fun4351__t {
  struct kk_function_s _base;
};
static kk_box_t kk_climate_dash_experiments__mlift2595_main_fun4351(kk_function_t _fself, kk_box_t _b_3696, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift2595_main_fun4351(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_climate_dash_experiments__mlift2595_main_fun4351, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_climate_dash_experiments__mlift2595_main_fun4351(kk_function_t _fself, kk_box_t _b_3696, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_unit_t _x4352 = kk_Unit;
  kk_unit_t _x4353 = kk_Unit;
  kk_unit_unbox(_b_3696);
  kk_climate_dash_experiments__mlift2594_main(_x4353, _ctx);
  return kk_unit_box(_x4352);
}

kk_unit_t kk_climate_dash_experiments__mlift2595_main(kk_unit_t wild__0, kk_context_t* _ctx) { /* (wild_0 : ()) -> <std/num/random/random,console,div,exn,fsys,ndet> () */ 
  kk_unit_t __1 = kk_Unit;
  kk_string_t _x4346;
  kk_define_string_literal(, _s4347, 29, "Completed Timing Experiments!")
  _x4346 = kk_string_dup(_s4347); /*string*/
  kk_std_core_printsln(_x4346, _ctx);
  kk_unit_t __2 = kk_Unit;
  kk_string_t _x4348;
  kk_define_string_literal(, _s4349, 24, "Running Climate Model...")
  _x4348 = kk_string_dup(_s4349); /*string*/
  kk_std_core_printsln(_x4348, _ctx);
  kk_unit_t x_2740 = kk_Unit;
  kk_climate_dash_experiments_run__climate__model(kk_integer_from_small(2000), kk_integer_from_small(131), kk_integer_from_small(2), kk_integer_from_int(100000, _ctx), kk_integer_from_int(80000, _ctx), kk_std_core_types__new_None(_ctx), _ctx);
  if (kk_yielding(kk_context())) {
    kk_box_t _x4350 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments__new_mlift2595_main_fun4351(_ctx), _ctx); /*2*/
    kk_unit_unbox(_x4350); return kk_Unit;
  }
  kk_climate_dash_experiments__mlift2594_main(x_2740, _ctx); return kk_Unit;
}


// lift anonymous function
struct kk_climate_dash_experiments_main_fun4357__t {
  struct kk_function_s _base;
};
static kk_box_t kk_climate_dash_experiments_main_fun4357(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_main_fun4357(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_climate_dash_experiments_main_fun4357, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_climate_dash_experiments_main_fun4357(kk_function_t _fself, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return kk_unit_box(kk_Unit);
}


// lift anonymous function
struct kk_climate_dash_experiments_main_fun4359__t {
  struct kk_function_s _base;
};
static kk_box_t kk_climate_dash_experiments_main_fun4359(kk_function_t _fself, kk_box_t _b_3701, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_main_fun4359(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_climate_dash_experiments_main_fun4359, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_climate_dash_experiments_main_fun4359(kk_function_t _fself, kk_box_t _b_3701, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_unit_t _x4360 = kk_Unit;
  kk_unit_t _x4361 = kk_Unit;
  kk_unit_unbox(_b_3701);
  kk_climate_dash_experiments__mlift2595_main(_x4361, _ctx);
  return kk_unit_box(_x4360);
}


// lift anonymous function
struct kk_climate_dash_experiments_main_fun4367__t {
  struct kk_function_s _base;
};
static kk_box_t kk_climate_dash_experiments_main_fun4367(kk_function_t _fself, kk_box_t _b_3703, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_main_fun4367(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_climate_dash_experiments_main_fun4367, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_climate_dash_experiments_main_fun4367(kk_function_t _fself, kk_box_t _b_3703, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_unit_t _x4368 = kk_Unit;
  kk_unit_t _x4369 = kk_Unit;
  kk_unit_unbox(_b_3703);
  kk_climate_dash_experiments__mlift2594_main(_x4369, _ctx);
  return kk_unit_box(_x4368);
}

kk_unit_t kk_climate_dash_experiments_main(kk_context_t* _ctx) { /* () -> <pure,console,fsys,ndet,std/num/random/random> () */ 
  kk_unit_t __ = kk_Unit;
  kk_string_t _x4354;
  kk_define_string_literal(, _s4355, 29, "Running Timing Experiments...")
  _x4354 = kk_string_dup(_s4355); /*string*/
  kk_std_core_printsln(_x4354, _ctx);
  kk_unit_t x_2743 = kk_Unit;
  kk_box_t _x4356 = kk_handlers_random__sampler(kk_climate_dash_experiments_new_main_fun4357(_ctx), _ctx); /*312*/
  kk_unit_unbox(_x4356);
  if (kk_yielding(kk_context())) {
    kk_box_t _x4358 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments_new_main_fun4359(_ctx), _ctx); /*2*/
    kk_unit_unbox(_x4358); return kk_Unit;
  }
  kk_unit_t __1 = kk_Unit;
  kk_string_t _x4362;
  kk_define_string_literal(, _s4363, 29, "Completed Timing Experiments!")
  _x4362 = kk_string_dup(_s4363); /*string*/
  kk_std_core_printsln(_x4362, _ctx);
  kk_unit_t __2 = kk_Unit;
  kk_string_t _x4364;
  kk_define_string_literal(, _s4365, 24, "Running Climate Model...")
  _x4364 = kk_string_dup(_s4365); /*string*/
  kk_std_core_printsln(_x4364, _ctx);
  kk_unit_t x0_2749 = kk_Unit;
  kk_climate_dash_experiments_run__climate__model(kk_integer_from_small(2000), kk_integer_from_small(131), kk_integer_from_small(2), kk_integer_from_int(100000, _ctx), kk_integer_from_int(80000, _ctx), kk_std_core_types__new_None(_ctx), _ctx);
  if (kk_yielding(kk_context())) {
    kk_box_t _x4366 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments_new_main_fun4367(_ctx), _ctx); /*2*/
    kk_unit_unbox(_x4366); return kk_Unit;
  }
  kk_unit_t __4 = kk_Unit;
  kk_string_t _x4370;
  kk_define_string_literal(, _s4371, 24, "Completed Climate Model!")
  _x4370 = kk_string_dup(_s4371); /*string*/
  kk_std_core_printsln(_x4370, _ctx);
  kk_string_t _x4372;
  kk_define_string_literal(, _s4373, 19, "Finished running...")
  _x4372 = kk_string_dup(_s4373); /*string*/
  kk_std_core_printsln(_x4372, _ctx); return kk_Unit;
}


// lift anonymous function
struct kk_climate_dash_experiments__hmain_fun4375__t {
  struct kk_function_s _base;
};
static kk_box_t kk_climate_dash_experiments__hmain_fun4375(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_hmain_fun4375(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_climate_dash_experiments__hmain_fun4375, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_climate_dash_experiments__hmain_fun4375(kk_function_t _fself, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  int32_t _x4376 = kk_std_num_random_srandom_int32(_ctx); /*int32*/
  return kk_int32_box(_x4376, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__hmain_fun4378__t {
  struct kk_function_s _base;
};
static kk_box_t kk_climate_dash_experiments__hmain_fun4378(kk_function_t _fself, kk_box_t _b_3717, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_hmain_fun4378(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_climate_dash_experiments__hmain_fun4378, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_climate_dash_experiments__hmain_fun4378(kk_function_t _fself, kk_box_t _b_3717, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return _b_3717;
}


// lift anonymous function
struct kk_climate_dash_experiments__hmain_fun4379__t {
  struct kk_function_s _base;
};
static kk_box_t kk_climate_dash_experiments__hmain_fun4379(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_hmain_fun4379(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_climate_dash_experiments__hmain_fun4379, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_climate_dash_experiments__hmain_fun4381__t {
  struct kk_function_s _base;
};
static kk_unit_t kk_climate_dash_experiments__hmain_fun4381(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_hmain_fun4381(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_climate_dash_experiments__hmain_fun4381, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_climate_dash_experiments__hmain_fun4385__t {
  struct kk_function_s _base;
};
static kk_box_t kk_climate_dash_experiments__hmain_fun4385(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_hmain_fun4385(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_climate_dash_experiments__hmain_fun4385, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_climate_dash_experiments__hmain_fun4385(kk_function_t _fself, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return kk_unit_box(kk_Unit);
}


// lift anonymous function
struct kk_climate_dash_experiments__hmain_fun4387__t {
  struct kk_function_s _base;
};
static kk_box_t kk_climate_dash_experiments__hmain_fun4387(kk_function_t _fself, kk_box_t _b_3710, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_hmain_fun4387(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_climate_dash_experiments__hmain_fun4387, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_climate_dash_experiments__hmain_fun4387(kk_function_t _fself, kk_box_t _b_3710, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_unit_t _x4388 = kk_Unit;
  kk_unit_t _x4389 = kk_Unit;
  kk_unit_unbox(_b_3710);
  kk_climate_dash_experiments__mlift2595_main(_x4389, _ctx);
  return kk_unit_box(_x4388);
}


// lift anonymous function
struct kk_climate_dash_experiments__hmain_fun4395__t {
  struct kk_function_s _base;
};
static kk_box_t kk_climate_dash_experiments__hmain_fun4395(kk_function_t _fself, kk_box_t _b_3712, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_hmain_fun4395(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_climate_dash_experiments__hmain_fun4395, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_climate_dash_experiments__hmain_fun4395(kk_function_t _fself, kk_box_t _b_3712, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_unit_t _x4396 = kk_Unit;
  kk_unit_t _x4397 = kk_Unit;
  kk_unit_unbox(_b_3712);
  kk_climate_dash_experiments__mlift2594_main(_x4397, _ctx);
  return kk_unit_box(_x4396);
}
static kk_unit_t kk_climate_dash_experiments__hmain_fun4381(kk_function_t _fself, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_unit_t __ = kk_Unit;
  kk_string_t _x4382;
  kk_define_string_literal(, _s4383, 29, "Running Timing Experiments...")
  _x4382 = kk_string_dup(_s4383); /*string*/
  kk_std_core_printsln(_x4382, _ctx);
  kk_unit_t x_2743 = kk_Unit;
  kk_box_t _x4384 = kk_handlers_random__sampler(kk_climate_dash_experiments__new_hmain_fun4385(_ctx), _ctx); /*312*/
  kk_unit_unbox(_x4384);
  if (kk_yielding(kk_context())) {
    kk_box_t _x4386 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments__new_hmain_fun4387(_ctx), _ctx); /*2*/
    return kk_unit_unbox(_x4386);
  }
  kk_unit_t __1 = kk_Unit;
  kk_string_t _x4390;
  kk_define_string_literal(, _s4391, 29, "Completed Timing Experiments!")
  _x4390 = kk_string_dup(_s4391); /*string*/
  kk_std_core_printsln(_x4390, _ctx);
  kk_unit_t __2 = kk_Unit;
  kk_string_t _x4392;
  kk_define_string_literal(, _s4393, 24, "Running Climate Model...")
  _x4392 = kk_string_dup(_s4393); /*string*/
  kk_std_core_printsln(_x4392, _ctx);
  kk_unit_t x0_2749 = kk_Unit;
  kk_climate_dash_experiments_run__climate__model(kk_integer_from_small(2000), kk_integer_from_small(131), kk_integer_from_small(2), kk_integer_from_int(100000, _ctx), kk_integer_from_int(80000, _ctx), kk_std_core_types__new_None(_ctx), _ctx);
  if (kk_yielding(kk_context())) {
    kk_box_t _x4394 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments__new_hmain_fun4395(_ctx), _ctx); /*2*/
    return kk_unit_unbox(_x4394);
  }
  kk_unit_t __4 = kk_Unit;
  kk_string_t _x4398;
  kk_define_string_literal(, _s4399, 24, "Completed Climate Model!")
  _x4398 = kk_string_dup(_s4399); /*string*/
  kk_std_core_printsln(_x4398, _ctx);
  kk_string_t _x4400;
  kk_define_string_literal(, _s4401, 19, "Finished running...")
  _x4400 = kk_string_dup(_s4401); /*string*/
  return kk_std_core_printsln(_x4400, _ctx);
}
static kk_box_t kk_climate_dash_experiments__hmain_fun4379(kk_function_t _fself, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_unit_t _x4380 = kk_Unit;
  kk_std_core__default_exn(kk_climate_dash_experiments__new_hmain_fun4381(_ctx), _ctx);
  return kk_unit_box(_x4380);
}

kk_unit_t kk_climate_dash_experiments__hmain(kk_context_t* _ctx) { /* () -> <console,div,fsys,ndet> () */ 
  int32_t _b_3718_3713 = ((int32_t)1); /*int32*/;
  kk_std_num_random__hnd_random _b_3719_3714;
  kk_std_core_hnd__clause0 _x4374 = kk_std_core_hnd_clause_tail_noyield0(kk_climate_dash_experiments__new_hmain_fun4375(_ctx), _ctx); /*std/core/hnd/clause0<3,4,1,2>*/
  _b_3719_3714 = kk_std_num_random__new_Hnd_random(kk_reuse_null, _x4374, _ctx); /*std/num/random/.hnd-random<<ndet,console,div,fsys>,()>*/
  kk_box_t _x4377 = kk_std_num_random__handle_random(_b_3718_3713, _b_3719_3714, kk_climate_dash_experiments__new_hmain_fun4378(_ctx), kk_climate_dash_experiments__new_hmain_fun4379(_ctx), _ctx); /*2*/
  kk_unit_unbox(_x4377); return kk_Unit;
}

// main entry
int main(int argc, char** argv) {
  kk_context_t* _ctx = kk_main_start(argc, argv);
  kk_climate_dash_experiments__init(_ctx);
  kk_climate_dash_experiments__hmain(_ctx);
  kk_main_end(_ctx);
  return 0;
}

// initialization
void kk_climate_dash_experiments__init(kk_context_t* _ctx){
  static bool _initialized = false;
  if (_initialized) return;
  _initialized = true;
  kk_std_core_types__init(_ctx);
  kk_std_core_hnd__init(_ctx);
  kk_std_core__init(_ctx);
  kk_std_text_parse__init(_ctx);
  kk_std_num_int32__init(_ctx);
  kk_std_num_double__init(_ctx);
  kk_std_num_decimal__init(_ctx);
  kk_std_num_ddouble__init(_ctx);
  kk_std_num_random__init(_ctx);
  kk_std_time_date__init(_ctx);
  kk_std_time_timestamp__init(_ctx);
  kk_std_time_duration__init(_ctx);
  kk_std_time_instant__init(_ctx);
  kk_std_time_timer__init(_ctx);
  kk_std_os_path__init(_ctx);
  kk_std_os_dir__init(_ctx);
  kk_std_os_file__init(_ctx);
  kk_effects_dash_and_dash_types__init(_ctx);
  kk_exponents__init(_ctx);
  kk_output_dash_and_dash_plot__init(_ctx);
  kk_handlers__init(_ctx);
  kk_sampling__init(_ctx);
  kk_sequential__init(_ctx);
  kk_exn_dash_get__init(_ctx);
  kk_model_dash_resources__init(_ctx);
  kk_trace__init(_ctx);
  kk_pmmh__init(_ctx);
  kk_climate_dash_change__init(_ctx);
  kk_data_preprocessing__init(_ctx);
}
