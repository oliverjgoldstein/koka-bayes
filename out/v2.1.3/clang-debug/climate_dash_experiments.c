// Koka generated module: "climate-experiments", koka version: 2.1.3
#include "climate_dash_experiments.h"
 
// monadic lift


// lift anonymous function
struct kk_climate_dash_experiments__mlift5628_run__climate__model_fun7589__t {
  struct kk_function_s _base;
  size_t i_5651;
};
static kk_box_t kk_climate_dash_experiments__mlift5628_run__climate__model_fun7589(kk_function_t _fself, kk_function_t _b_5986, kk_box_t _b_5987, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5628_run__climate__model_fun7589(size_t i_5651, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5628_run__climate__model_fun7589__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5628_run__climate__model_fun7589__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5628_run__climate__model_fun7589, kk_context());
  _self->i_5651 = i_5651;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift5628_run__climate__model_fun7589(kk_function_t _fself, kk_function_t _b_5986, kk_box_t _b_5987, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5628_run__climate__model_fun7589__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5628_run__climate__model_fun7589__t*, _fself);
  size_t i_5651 = _self->i_5651; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_5651, _b_5986, _b_5987, _ctx);
}

kk_unit_t kk_climate_dash_experiments__mlift5628_run__climate__model(kk_string_t name1, kk_integer_t repeat__ind, kk_std_core__list _y_21, kk_context_t* _ctx) { /* (name1 : string, repeat_ind : int, effects-and-types/histogram<list<double>>) -> <pure,std/num/random/random,fsys,console,ndet> () */ 
  kk_string_t _x216;
  kk_string_t _x7573;
  kk_define_string_literal(, _s7574, 17, "./output-climate/")
  _x7573 = kk_string_dup(_s7574); /*string*/
  kk_string_t _x7575;
  kk_string_t _x7576 = kk_string_dup(name1); /*string*/
  kk_string_t _x7577;
  kk_string_t _x7578;
  kk_define_string_literal(, _s7579, 1, "/")
  _x7578 = kk_string_dup(_s7579); /*string*/
  kk_string_t _x7580;
  kk_string_t _x7581;
  kk_string_t _x7582;
  kk_define_string_literal(, _s7583, 5, "_smc_")
  _x7582 = kk_string_dup(_s7583); /*string*/
  kk_string_t _x7584;
  kk_string_t _x7585 = kk_std_core_show(repeat__ind, _ctx); /*string*/
  kk_string_t _x7586;
  kk_define_string_literal(, _s7587, 4, ".csv")
  _x7586 = kk_string_dup(_s7587); /*string*/
  _x7584 = kk_std_core__lp__plus__plus__1_rp_(_x7585, _x7586, _ctx); /*string*/
  _x7581 = kk_std_core__lp__plus__plus__1_rp_(_x7582, _x7584, _ctx); /*string*/
  _x7580 = kk_std_core__lp__plus__plus__1_rp_(name1, _x7581, _ctx); /*string*/
  _x7577 = kk_std_core__lp__plus__plus__1_rp_(_x7578, _x7580, _ctx); /*string*/
  _x7575 = kk_std_core__lp__plus__plus__1_rp_(_x7576, _x7577, _ctx); /*string*/
  _x216 = kk_std_core__lp__plus__plus__1_rp_(_x7573, _x7575, _ctx); /*string*/
  size_t i_5651 = ((size_t)0); /*std/core/hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_5651,kk_context()); /*std/core/hnd/evv<<exn,fsys,div,std/num/random/random,console,ndet>>*/;
  kk_unit_t y = kk_Unit;
  kk_output_dash_and_dash_plot_write_4(_y_21, _x216, _ctx);
  kk_unit_t __w_l717_c9 = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x7588 = kk_std_core_hnd_yield_cont(kk_climate_dash_experiments__new_mlift5628_run__climate__model_fun7589(i_5651, _ctx), _ctx); /*3*/
    kk_unit_unbox(_x7588); return kk_Unit;
  }
  y; return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_climate_dash_experiments__mlift5629_run__climate__model_fun7608__t {
  struct kk_function_s _base;
  size_t i_5663;
};
static kk_box_t kk_climate_dash_experiments__mlift5629_run__climate__model_fun7608(kk_function_t _fself, kk_function_t _b_6016, kk_box_t _b_6017, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5629_run__climate__model_fun7608(size_t i_5663, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5629_run__climate__model_fun7608__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5629_run__climate__model_fun7608__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5629_run__climate__model_fun7608, kk_context());
  _self->i_5663 = i_5663;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift5629_run__climate__model_fun7608(kk_function_t _fself, kk_function_t _b_6016, kk_box_t _b_6017, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5629_run__climate__model_fun7608__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5629_run__climate__model_fun7608__t*, _fself);
  size_t i_5663 = _self->i_5663; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_5663, _b_6016, _b_6017, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift5629_run__climate__model_fun7626__t {
  struct kk_function_s _base;
  size_t i0_5668;
};
static kk_box_t kk_climate_dash_experiments__mlift5629_run__climate__model_fun7626(kk_function_t _fself, kk_function_t _b_6046, kk_box_t _b_6047, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5629_run__climate__model_fun7626(size_t i0_5668, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5629_run__climate__model_fun7626__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5629_run__climate__model_fun7626__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5629_run__climate__model_fun7626, kk_context());
  _self->i0_5668 = i0_5668;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift5629_run__climate__model_fun7626(kk_function_t _fself, kk_function_t _b_6046, kk_box_t _b_6047, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5629_run__climate__model_fun7626__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5629_run__climate__model_fun7626__t*, _fself);
  size_t i0_5668 = _self->i0_5668; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i0_5668, _b_6046, _b_6047, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift5629_run__climate__model_fun7627__t {
  struct kk_function_s _base;
  kk_function_t _x016_5613;
};
static kk_std_core__list kk_climate_dash_experiments__mlift5629_run__climate__model_fun7627(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5629_run__climate__model_fun7627(kk_function_t _x016_5613, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5629_run__climate__model_fun7627__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5629_run__climate__model_fun7627__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5629_run__climate__model_fun7627, kk_context());
  _self->_x016_5613 = _x016_5613;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift5629_run__climate__model_fun7630__t {
  struct kk_function_s _base;
  kk_function_t _x016_5613;
};
static kk_box_t kk_climate_dash_experiments__mlift5629_run__climate__model_fun7630(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5629_run__climate__model_fun7630(kk_function_t _x016_5613, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5629_run__climate__model_fun7630__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5629_run__climate__model_fun7630__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5629_run__climate__model_fun7630, kk_context());
  _self->_x016_5613 = _x016_5613;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift5629_run__climate__model_fun7630(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5629_run__climate__model_fun7630__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5629_run__climate__model_fun7630__t*, _fself);
  kk_function_t _x016_5613 = _self->_x016_5613; /* effects-and-types/model<list<double>,exn> */
  kk_drop_match(_self, {kk_function_dup(_x016_5613);}, {}, _ctx)
  kk_std_core__list _x7631 = kk_function_call(kk_std_core__list, (kk_function_t, kk_context_t*), _x016_5613, (_x016_5613, _ctx)); /*list<double>*/
  return kk_std_core__list_box(_x7631, _ctx);
}
static kk_std_core__list kk_climate_dash_experiments__mlift5629_run__climate__model_fun7627(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5629_run__climate__model_fun7627__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5629_run__climate__model_fun7627__t*, _fself);
  kk_function_t _x016_5613 = _self->_x016_5613; /* effects-and-types/model<list<double>,exn> */
  kk_drop_match(_self, {kk_function_dup(_x016_5613);}, {}, _ctx)
  kk_vector_t _b_6064_6062;
  kk_std_core__list _x7628;
  size_t _b_6066_6060 = ((size_t)0); /*std/core/hnd/ev-index*/;
  kk_std_core__list _b_6067_6061;
  size_t _b_6068_6058 = ((size_t)2); /*std/core/hnd/ev-index*/;
  kk_std_core__list _b_6069_6059;
  size_t _b_6070_6056 = ((size_t)3); /*std/core/hnd/ev-index*/;
  _b_6069_6059 = kk_std_core__new_Cons(kk_reuse_null, kk_size_box(_b_6070_6056, _ctx), kk_std_core__new_Nil(_ctx), _ctx); /*list<std/core/hnd/ev-index>*/
  _b_6067_6061 = kk_std_core__new_Cons(kk_reuse_null, kk_size_box(_b_6068_6058, _ctx), _b_6069_6059, _ctx); /*list<std/core/hnd/ev-index>*/
  _x7628 = kk_std_core__new_Cons(kk_reuse_null, kk_size_box(_b_6066_6060, _ctx), _b_6067_6061, _ctx); /*list<0>*/
  _b_6064_6062 = kk_std_core_unvlist(_x7628, _ctx); /*vector<std/core/hnd/ev-index>*/
  kk_box_t _x7629 = kk_std_core_hnd__open0(_b_6064_6062, kk_climate_dash_experiments__new_mlift5629_run__climate__model_fun7630(_x016_5613, _ctx), _ctx); /*1*/
  return kk_std_core__list_unbox(_x7629, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift5629_run__climate__model_fun7633__t {
  struct kk_function_s _base;
  kk_function_t model_5660;
  kk_integer_t pt;
  kk_integer_t rs;
  kk_integer_t sbrs;
};
static kk_box_t kk_climate_dash_experiments__mlift5629_run__climate__model_fun7633(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5629_run__climate__model_fun7633(kk_function_t model_5660, kk_integer_t pt, kk_integer_t rs, kk_integer_t sbrs, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5629_run__climate__model_fun7633__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5629_run__climate__model_fun7633__t, 5, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5629_run__climate__model_fun7633, kk_context());
  _self->model_5660 = model_5660;
  _self->pt = pt;
  _self->rs = rs;
  _self->sbrs = sbrs;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift5629_run__climate__model_fun7635__t {
  struct kk_function_s _base;
  kk_function_t model_5660;
};
static kk_box_t kk_climate_dash_experiments__mlift5629_run__climate__model_fun7635(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5629_run__climate__model_fun7635(kk_function_t model_5660, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5629_run__climate__model_fun7635__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5629_run__climate__model_fun7635__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5629_run__climate__model_fun7635, kk_context());
  _self->model_5660 = model_5660;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift5629_run__climate__model_fun7637__t {
  struct kk_function_s _base;
  kk_function_t model_5660;
};
static kk_box_t kk_climate_dash_experiments__mlift5629_run__climate__model_fun7637(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5629_run__climate__model_fun7637(kk_function_t model_5660, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5629_run__climate__model_fun7637__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5629_run__climate__model_fun7637__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5629_run__climate__model_fun7637, kk_context());
  _self->model_5660 = model_5660;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift5629_run__climate__model_fun7638__t {
  struct kk_function_s _base;
  kk_function_t model_5660;
};
static kk_box_t kk_climate_dash_experiments__mlift5629_run__climate__model_fun7638(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5629_run__climate__model_fun7638(kk_function_t model_5660, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5629_run__climate__model_fun7638__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5629_run__climate__model_fun7638__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5629_run__climate__model_fun7638, kk_context());
  _self->model_5660 = model_5660;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift5629_run__climate__model_fun7638(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5629_run__climate__model_fun7638__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5629_run__climate__model_fun7638__t*, _fself);
  kk_function_t model_5660 = _self->model_5660; /* () -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random,fsys,console,ndet> list<double> */
  kk_drop_match(_self, {kk_function_dup(model_5660);}, {}, _ctx)
  kk_std_core__list _x7639 = kk_function_call(kk_std_core__list, (kk_function_t, kk_context_t*), model_5660, (model_5660, _ctx)); /*list<double>*/
  return kk_std_core__list_box(_x7639, _ctx);
}
static kk_box_t kk_climate_dash_experiments__mlift5629_run__climate__model_fun7637(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5629_run__climate__model_fun7637__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5629_run__climate__model_fun7637__t*, _fself);
  kk_function_t model_5660 = _self->model_5660; /* () -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random,fsys,console,ndet> list<double> */
  kk_drop_match(_self, {kk_function_dup(model_5660);}, {}, _ctx)
  return kk_handlers_yield__on__score(kk_climate_dash_experiments__new_mlift5629_run__climate__model_fun7638(model_5660, _ctx), _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift5629_run__climate__model_fun7640__t {
  struct kk_function_s _base;
  kk_function_t _bv_6074;
};
static kk_std_core__list kk_climate_dash_experiments__mlift5629_run__climate__model_fun7640(kk_function_t _fself, kk_integer_t _b_6075, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5629_run__climate__model_fun7640(kk_function_t _bv_6074, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5629_run__climate__model_fun7640__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5629_run__climate__model_fun7640__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5629_run__climate__model_fun7640, kk_context());
  _self->_bv_6074 = _bv_6074;
  return &_self->_base;
}

static kk_std_core__list kk_climate_dash_experiments__mlift5629_run__climate__model_fun7640(kk_function_t _fself, kk_integer_t _b_6075, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5629_run__climate__model_fun7640__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5629_run__climate__model_fun7640__t*, _fself);
  kk_function_t _bv_6074 = _self->_bv_6074; /* (a : int) -> <effects-and-types/yield|1> 0 */
  kk_drop_match(_self, {kk_function_dup(_bv_6074);}, {}, _ctx)
  kk_box_t _x7641 = kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_context_t*), _bv_6074, (_bv_6074, _b_6075, _ctx)); /*0*/
  return kk_std_core__list_unbox(_x7641, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift5629_run__climate__model_fun7642__t {
  struct kk_function_s _base;
  kk_function_t _bv_6080;
};
static kk_box_t kk_climate_dash_experiments__mlift5629_run__climate__model_fun7642(kk_function_t _fself, kk_box_t _b_6081, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5629_run__climate__model_fun7642(kk_function_t _bv_6080, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5629_run__climate__model_fun7642__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5629_run__climate__model_fun7642__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5629_run__climate__model_fun7642, kk_context());
  _self->_bv_6080 = _bv_6080;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift5629_run__climate__model_fun7642(kk_function_t _fself, kk_box_t _b_6081, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5629_run__climate__model_fun7642__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5629_run__climate__model_fun7642__t*, _fself);
  kk_function_t _bv_6080 = _self->_bv_6080; /* (a : int) -> <effects-and-types/yield,effects-and-types/sample,effects-and-types/score,div,exn,std/num/random/random,fsys,console,ndet> list<double> */
  kk_drop_match(_self, {kk_function_dup(_bv_6080);}, {}, _ctx)
  kk_std_core__list _x7643;
  kk_integer_t _x7644 = kk_integer_unbox(_b_6081); /*int*/
  _x7643 = kk_function_call(kk_std_core__list, (kk_function_t, kk_integer_t, kk_context_t*), _bv_6080, (_bv_6080, _x7644, _ctx)); /*list<double>*/
  return kk_std_core__list_box(_x7643, _ctx);
}
static kk_box_t kk_climate_dash_experiments__mlift5629_run__climate__model_fun7635(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5629_run__climate__model_fun7635__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5629_run__climate__model_fun7635__t*, _fself);
  kk_function_t model_5660 = _self->model_5660; /* () -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random,fsys,console,ndet> list<double> */
  kk_drop_match(_self, {kk_function_dup(model_5660);}, {}, _ctx)
  kk_function_t _x7636;
  kk_function_t _bv_6080;
  kk_function_t _bv_6074 = kk_handlers_advance(kk_climate_dash_experiments__new_mlift5629_run__climate__model_fun7637(model_5660, _ctx), _ctx); /*(a : int) -> <effects-and-types/yield|1> 0*/;
  _bv_6080 = kk_climate_dash_experiments__new_mlift5629_run__climate__model_fun7640(_bv_6074, _ctx); /*(a : int) -> <effects-and-types/yield,effects-and-types/sample,effects-and-types/score,div,exn,std/num/random/random,fsys,console,ndet> list<double>*/
  _x7636 = kk_climate_dash_experiments__new_mlift5629_run__climate__model_fun7642(_bv_6080, _ctx); /*(6078) -> <effects-and-types/yield,effects-and-types/sample,effects-and-types/score,div,exn,std/num/random/random,fsys,console,ndet> 6079*/
  return kk_function_box(_x7636);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift5629_run__climate__model_fun7646__t {
  struct kk_function_s _base;
  kk_integer_t rs;
  kk_integer_t sbrs;
};
static kk_box_t kk_climate_dash_experiments__mlift5629_run__climate__model_fun7646(kk_function_t _fself, kk_box_t _b_6087, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5629_run__climate__model_fun7646(kk_integer_t rs, kk_integer_t sbrs, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5629_run__climate__model_fun7646__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5629_run__climate__model_fun7646__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5629_run__climate__model_fun7646, kk_context());
  _self->rs = rs;
  _self->sbrs = sbrs;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift5629_run__climate__model_fun7646(kk_function_t _fself, kk_box_t _b_6087, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5629_run__climate__model_fun7646__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5629_run__climate__model_fun7646__t*, _fself);
  kk_integer_t rs = _self->rs; /* int */
  kk_integer_t sbrs = _self->sbrs; /* int */
  kk_drop_match(_self, {kk_integer_dup(rs);kk_integer_dup(sbrs);}, {}, _ctx)
  kk_std_core__list _x7647;
  kk_std_core__list _x7648 = kk_std_core__list_unbox(_b_6087, _ctx); /*effects-and-types/histogram<(a : int) -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random,fsys,console,ndet> list<double>>*/
  _x7647 = kk_smc__mlift743_smc(true, rs, sbrs, _x7648, _ctx); /*effects-and-types/histogram<24>*/
  return kk_std_core__list_box(_x7647, _ctx);
}
static kk_box_t kk_climate_dash_experiments__mlift5629_run__climate__model_fun7633(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5629_run__climate__model_fun7633__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5629_run__climate__model_fun7633__t*, _fself);
  kk_function_t model_5660 = _self->model_5660; /* () -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random,fsys,console,ndet> list<double> */
  kk_integer_t pt = _self->pt; /* int */
  kk_integer_t rs = _self->rs; /* int */
  kk_integer_t sbrs = _self->sbrs; /* int */
  kk_drop_match(_self, {kk_function_dup(model_5660);kk_integer_dup(pt);kk_integer_dup(rs);kk_integer_dup(sbrs);}, {}, _ctx)
  kk_std_core__list _x7634;
  kk_std_core__list x_775 = kk_sampling_populate(pt, kk_climate_dash_experiments__new_mlift5629_run__climate__model_fun7635(model_5660, _ctx), _ctx); /*effects-and-types/histogram<(a : int) -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random,fsys,console,ndet> list<double>>*/;
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_775, _ctx);
    kk_box_t _x7645 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments__new_mlift5629_run__climate__model_fun7646(rs, sbrs, _ctx), _ctx); /*2*/
    _x7634 = kk_std_core__list_unbox(_x7645, _ctx); /*effects-and-types/histogram<list<double>>*/
  }
  else {
    _x7634 = kk_smc__mlift743_smc(true, rs, sbrs, x_775, _ctx); /*effects-and-types/histogram<list<double>>*/
  }
  return kk_std_core__list_box(_x7634, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift5629_run__climate__model_fun7650__t {
  struct kk_function_s _base;
  kk_string_t name1;
  kk_integer_t repeat__ind;
};
static kk_box_t kk_climate_dash_experiments__mlift5629_run__climate__model_fun7650(kk_function_t _fself, kk_box_t _b_6093, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5629_run__climate__model_fun7650(kk_string_t name1, kk_integer_t repeat__ind, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5629_run__climate__model_fun7650__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5629_run__climate__model_fun7650__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5629_run__climate__model_fun7650, kk_context());
  _self->name1 = name1;
  _self->repeat__ind = repeat__ind;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift5629_run__climate__model_fun7650(kk_function_t _fself, kk_box_t _b_6093, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5629_run__climate__model_fun7650__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5629_run__climate__model_fun7650__t*, _fself);
  kk_string_t name1 = _self->name1; /* string */
  kk_integer_t repeat__ind = _self->repeat__ind; /* int */
  kk_drop_match(_self, {kk_string_dup(name1);kk_integer_dup(repeat__ind);}, {}, _ctx)
  kk_unit_t _x7651 = kk_Unit;
  kk_std_core__list _x7652 = kk_std_core__list_unbox(_b_6093, _ctx); /*effects-and-types/histogram<list<double>>*/
  kk_climate_dash_experiments__mlift5628_run__climate__model(name1, repeat__ind, _x7652, _ctx);
  return kk_unit_box(_x7651);
}

kk_unit_t kk_climate_dash_experiments__mlift5629_run__climate__model(kk_std_core_types__tuple2_ data, double diff1, kk_integer_t ind1, kk_string_t name1, kk_integer_t pt, kk_integer_t repeat__ind, kk_integer_t rs, kk_integer_t sbrs, double subtract1, kk_std_core__list _y_20, kk_context_t* _ctx) { /* (data : (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>), diff1 : double, ind1 : int, name1 : string, pt : int, repeat_ind : int, rs : int, sbrs : int, subtract1 : double, list<effects-and-types/row_vector>) -> <exn,div,std/num/random/random,fsys,console,ndet> () */ 
  kk_std_core__list_drop(_y_20, _ctx);
  kk_std_core__list x_5655;
  kk_function_t model_5660;
  kk_function_t _x016_5613;
  kk_std_core__list _x113;
  size_t i_5663 = ((size_t)0); /*std/core/hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_5663,kk_context()); /*std/core/hnd/evv<<exn,div,std/num/random/random,fsys,console,ndet>>*/;
  kk_std_core__list y;
  kk_std_core_types__maybe _match_7569;
  kk_std_core__list _x7590;
  kk_box_t _box_x5996 = data.fst;
  kk_box_t _box_x5997 = data.snd;
  kk_std_core__list _x = kk_std_core__list_unbox(_box_x5997, NULL);
  kk_std_core__list_dup(_x);
  _x7590 = _x; /*list<list<effects-and-types/row_vector>>*/
  kk_integer_t _x7593 = kk_integer_dup(ind1); /*int*/
  _match_7569 = kk_std_core__lp__lb__rb__2_rp_(_x7590, _x7593, _ctx); /*maybe<1>*/
  if (kk_std_core_types__is_Nothing(_match_7569)) {
    kk_string_t message_205;
    kk_string_t _x7594;
    kk_define_string_literal(, _s7595, 48, "ListIndexError: Invalid list indexing at index: ")
    _x7594 = kk_string_dup(_s7595); /*string*/
    kk_string_t _x7596;
    kk_integer_t _x7597 = kk_integer_dup(ind1); /*int*/
    _x7596 = kk_std_core_show(_x7597, _ctx); /*string*/
    message_205 = kk_std_core__lp__plus__plus__1_rp_(_x7594, _x7596, _ctx); /*string*/
    kk_std_core__exception exn_21561;
    kk_std_core__exception_info _x7598;
    kk_std_core_types__optional _match_7571 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
    if (kk_std_core_types__is_Optional(_match_7571)) {
      kk_box_t _box_x5998 = _match_7571._cons.Optional.value;
      kk_std_core__exception_info _info_14279 = kk_std_core__exception_info_unbox(_box_x5998, NULL);
      kk_std_core__exception_info_dup(_info_14279);
      kk_std_core_types__optional_drop(_match_7571, _ctx);
      _x7598 = _info_14279; /*exception-info*/
      goto _match7599;
    }
    _x7598 = kk_std_core__new_ExnError(_ctx); /*exception-info*/
    _match7599: ;
    exn_21561 = kk_std_core__new_Exception(message_205, _x7598, _ctx); /*exception*/
    kk_std_core_hnd__ev ev_21562;
    size_t _x7601 = ((size_t)0); /*size_t*/
    ev_21562 = kk_evv_at(_x7601,kk_context()); /*std/core/hnd/ev<.hnd-exn>*/
    kk_box_t _x7602;
    struct kk_std_core_hnd_Ev* _con7603 = kk_std_core_hnd__as_Ev(ev_21562);
    kk_std_core_hnd__marker m = _con7603->marker;
    kk_box_t _box_x5999 = _con7603->hnd;
    kk_std_core__hnd_exn h = kk_std_core__hnd_exn_unbox(_box_x5999, NULL);
    kk_std_core__hnd_exn_dup(h);
    kk_std_core_hnd__clause1 _match_7570;
    struct kk_std_core__Hnd_exn* _con7605 = kk_std_core__as_Hnd_exn(h);
    kk_std_core_hnd__clause1 except_throw_exn = _con7605->except_throw_exn;
    if (kk_std_core__hnd_exn_is_unique(h)) {
      kk_std_core__hnd_exn_free(h);
    }
    else {
      kk_std_core_hnd__clause1_dup(except_throw_exn);
      kk_std_core__hnd_exn_decref(h, _ctx);
    }
    _match_7570 = except_throw_exn; /*forall<a> std/core/hnd/clause1<exception,a,.hnd-exn,7,8>*/
    kk_function_t _fun_unbox_x6003 = _match_7570.clause;
    _x7602 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x6003, (_fun_unbox_x6003, m, ev_21562, kk_std_core__exception_box(exn_21561, _ctx), _ctx)); /*11*/
    y = kk_std_core__list_unbox(_x7602, _ctx); /*list<effects-and-types/row_vector>*/
  }
  else {
    kk_box_t _box_x6007 = _match_7569._cons.Just.value;
    kk_std_core__list x = kk_std_core__list_unbox(_box_x6007, NULL);
    kk_std_core__list_dup(x);
    kk_std_core_types__maybe_drop(_match_7569, _ctx);
    y = x; /*list<effects-and-types/row_vector>*/
  }
  kk_unit_t __w_l717_c9 = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(y, _ctx);
    kk_box_t _x7607 = kk_std_core_hnd_yield_cont(kk_climate_dash_experiments__new_mlift5629_run__climate__model_fun7608(i_5663, _ctx), _ctx); /*3*/
    _x113 = kk_std_core__list_unbox(_x7607, _ctx); /*list<effects-and-types/row_vector>*/
  }
  else {
    _x113 = y; /*list<effects-and-types/row_vector>*/
  }
  kk_std_core__list _x213;
  size_t i0_5668 = ((size_t)0); /*std/core/hnd/ev-index*/;
  kk_evv_t w0 = kk_evv_swap_create1(i0_5668,kk_context()); /*std/core/hnd/evv<<exn,div,std/num/random/random,fsys,console,ndet>>*/;
  kk_std_core__list y0;
  kk_std_core_types__maybe _match_7565;
  kk_std_core__list _x7609;
  kk_box_t _box_x6026 = data.fst;
  kk_box_t _box_x6027 = data.snd;
  kk_std_core__list _x0 = kk_std_core__list_unbox(_box_x6026, NULL);
  kk_std_core__list_dup(_x0);
  kk_std_core_types__tuple2__drop(data, _ctx);
  _x7609 = _x0; /*list<list<effects-and-types/row_vector>>*/
  kk_integer_t _x7612 = kk_integer_dup(ind1); /*int*/
  _match_7565 = kk_std_core__lp__lb__rb__2_rp_(_x7609, _x7612, _ctx); /*maybe<1>*/
  if (kk_std_core_types__is_Nothing(_match_7565)) {
    kk_string_t message_2050;
    kk_string_t _x7613;
    kk_define_string_literal(, _s7614, 48, "ListIndexError: Invalid list indexing at index: ")
    _x7613 = kk_string_dup(_s7614); /*string*/
    kk_string_t _x7615 = kk_std_core_show(ind1, _ctx); /*string*/
    message_2050 = kk_std_core__lp__plus__plus__1_rp_(_x7613, _x7615, _ctx); /*string*/
    kk_std_core__exception exn_215610;
    kk_std_core__exception_info _x7616;
    kk_std_core_types__optional _match_7567 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
    if (kk_std_core_types__is_Optional(_match_7567)) {
      kk_box_t _box_x6028 = _match_7567._cons.Optional.value;
      kk_std_core__exception_info _info_142790 = kk_std_core__exception_info_unbox(_box_x6028, NULL);
      kk_std_core__exception_info_dup(_info_142790);
      kk_std_core_types__optional_drop(_match_7567, _ctx);
      _x7616 = _info_142790; /*exception-info*/
      goto _match7617;
    }
    _x7616 = kk_std_core__new_ExnError(_ctx); /*exception-info*/
    _match7617: ;
    exn_215610 = kk_std_core__new_Exception(message_2050, _x7616, _ctx); /*exception*/
    kk_std_core_hnd__ev ev_215620;
    size_t _x7619 = ((size_t)0); /*size_t*/
    ev_215620 = kk_evv_at(_x7619,kk_context()); /*std/core/hnd/ev<.hnd-exn>*/
    kk_box_t _x7620;
    struct kk_std_core_hnd_Ev* _con7621 = kk_std_core_hnd__as_Ev(ev_215620);
    kk_std_core_hnd__marker m0 = _con7621->marker;
    kk_box_t _box_x6029 = _con7621->hnd;
    kk_std_core__hnd_exn h0 = kk_std_core__hnd_exn_unbox(_box_x6029, NULL);
    kk_std_core__hnd_exn_dup(h0);
    kk_std_core_hnd__clause1 _match_7566;
    struct kk_std_core__Hnd_exn* _con7623 = kk_std_core__as_Hnd_exn(h0);
    kk_std_core_hnd__clause1 except_throw_exn0 = _con7623->except_throw_exn;
    if (kk_std_core__hnd_exn_is_unique(h0)) {
      kk_std_core__hnd_exn_free(h0);
    }
    else {
      kk_std_core_hnd__clause1_dup(except_throw_exn0);
      kk_std_core__hnd_exn_decref(h0, _ctx);
    }
    _match_7566 = except_throw_exn0; /*forall<a> std/core/hnd/clause1<exception,a,.hnd-exn,7,8>*/
    kk_function_t _fun_unbox_x6033 = _match_7566.clause;
    _x7620 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x6033, (_fun_unbox_x6033, m0, ev_215620, kk_std_core__exception_box(exn_215610, _ctx), _ctx)); /*11*/
    y0 = kk_std_core__list_unbox(_x7620, _ctx); /*list<effects-and-types/row_vector>*/
  }
  else {
    kk_box_t _box_x6037 = _match_7565._cons.Just.value;
    kk_std_core__list x0 = kk_std_core__list_unbox(_box_x6037, NULL);
    kk_integer_drop(ind1, _ctx);
    kk_std_core__list_dup(x0);
    kk_std_core_types__maybe_drop(_match_7565, _ctx);
    y0 = x0; /*list<effects-and-types/row_vector>*/
  }
  kk_unit_t __w_l717_c90 = kk_Unit;
  kk_evv_set(w0,kk_context());
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(y0, _ctx);
    kk_box_t _x7625 = kk_std_core_hnd_yield_cont(kk_climate_dash_experiments__new_mlift5629_run__climate__model_fun7626(i0_5668, _ctx), _ctx); /*3*/
    _x213 = kk_std_core__list_unbox(_x7625, _ctx); /*list<effects-and-types/row_vector>*/
  }
  else {
    _x213 = y0; /*list<effects-and-types/row_vector>*/
  }
  kk_evv_t w1 = kk_evv_swap_create0(kk_context()); /*std/core/hnd/evv<(<>)>*/;
  kk_function_t x00 = kk_climate_dash_change_linear__gaussian__climate__data(_x113, _x213, false, diff1, subtract1, 0x1.2cccccccccccdp2, _ctx); /*effects-and-types/model<list<double>,exn>*/;
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w1,kk_context());
  _x016_5613 = x00; /*effects-and-types/model<list<double>,exn>*/
  model_5660 = kk_climate_dash_experiments__new_mlift5629_run__climate__model_fun7627(_x016_5613, _ctx); /*() -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random,fsys,console,ndet> list<double>*/
  kk_box_t _x7632 = kk_handlers_random__sampler(kk_climate_dash_experiments__new_mlift5629_run__climate__model_fun7633(model_5660, pt, rs, sbrs, _ctx), _ctx); /*0*/
  x_5655 = kk_std_core__list_unbox(_x7632, _ctx); /*effects-and-types/histogram<list<double>>*/
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_5655, _ctx);
    kk_box_t _x7649 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments__new_mlift5629_run__climate__model_fun7650(name1, repeat__ind, _ctx), _ctx); /*2*/
    kk_unit_unbox(_x7649); return kk_Unit;
  }
  kk_climate_dash_experiments__mlift5628_run__climate__model(name1, repeat__ind, x_5655, _ctx); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_climate_dash_experiments__mlift5630_run__climate__model_fun7671__t {
  struct kk_function_s _base;
  size_t i_5676;
};
static kk_box_t kk_climate_dash_experiments__mlift5630_run__climate__model_fun7671(kk_function_t _fself, kk_function_t _b_6116, kk_box_t _b_6117, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5630_run__climate__model_fun7671(size_t i_5676, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5630_run__climate__model_fun7671__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5630_run__climate__model_fun7671__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5630_run__climate__model_fun7671, kk_context());
  _self->i_5676 = i_5676;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift5630_run__climate__model_fun7671(kk_function_t _fself, kk_function_t _b_6116, kk_box_t _b_6117, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5630_run__climate__model_fun7671__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5630_run__climate__model_fun7671__t*, _fself);
  size_t i_5676 = _self->i_5676; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_5676, _b_6116, _b_6117, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift5630_run__climate__model_fun7673__t {
  struct kk_function_s _base;
  kk_std_core_types__tuple2_ data;
  kk_integer_t ind1;
  kk_string_t name1;
  kk_integer_t pt;
  kk_integer_t repeat__ind;
  kk_integer_t rs;
  kk_integer_t sbrs;
  double diff1;
  double subtract1;
};
static kk_box_t kk_climate_dash_experiments__mlift5630_run__climate__model_fun7673(kk_function_t _fself, kk_box_t _b_6127, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5630_run__climate__model_fun7673(kk_std_core_types__tuple2_ data, kk_integer_t ind1, kk_string_t name1, kk_integer_t pt, kk_integer_t repeat__ind, kk_integer_t rs, kk_integer_t sbrs, double diff1, double subtract1, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5630_run__climate__model_fun7673__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5630_run__climate__model_fun7673__t, 9, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5630_run__climate__model_fun7673, kk_context());
  _self->data = data;
  _self->ind1 = ind1;
  _self->name1 = name1;
  _self->pt = pt;
  _self->repeat__ind = repeat__ind;
  _self->rs = rs;
  _self->sbrs = sbrs;
  _self->diff1 = diff1;
  _self->subtract1 = subtract1;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift5630_run__climate__model_fun7673(kk_function_t _fself, kk_box_t _b_6127, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5630_run__climate__model_fun7673__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5630_run__climate__model_fun7673__t*, _fself);
  kk_std_core_types__tuple2_ data = _self->data; /* (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>) */
  kk_integer_t ind1 = _self->ind1; /* int */
  kk_string_t name1 = _self->name1; /* string */
  kk_integer_t pt = _self->pt; /* int */
  kk_integer_t repeat__ind = _self->repeat__ind; /* int */
  kk_integer_t rs = _self->rs; /* int */
  kk_integer_t sbrs = _self->sbrs; /* int */
  double diff1 = _self->diff1; /* double */
  double subtract1 = _self->subtract1; /* double */
  kk_drop_match(_self, {kk_std_core_types__tuple2__dup(data);kk_integer_dup(ind1);kk_string_dup(name1);kk_integer_dup(pt);kk_integer_dup(repeat__ind);kk_integer_dup(rs);kk_integer_dup(sbrs);;;}, {}, _ctx)
  kk_unit_t _x7674 = kk_Unit;
  kk_std_core__list _x7675 = kk_std_core__list_unbox(_b_6127, _ctx); /*list<effects-and-types/row_vector>*/
  kk_climate_dash_experiments__mlift5629_run__climate__model(data, diff1, ind1, name1, pt, repeat__ind, rs, sbrs, subtract1, _x7675, _ctx);
  return kk_unit_box(_x7674);
}

kk_unit_t kk_climate_dash_experiments__mlift5630_run__climate__model(kk_std_core_types__tuple2_ data, double diff1, kk_integer_t ind1, kk_string_t name1, kk_integer_t pt, kk_integer_t repeat__ind, kk_integer_t rs, kk_integer_t sbrs, double subtract1, kk_std_core__list _y_19, kk_context_t* _ctx) { /* (data : (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>), diff1 : double, ind1 : int, name1 : string, pt : int, repeat_ind : int, rs : int, sbrs : int, subtract1 : double, list<effects-and-types/row_vector>) -> <exn,div,std/num/random/random,fsys,console,ndet> () */ 
  kk_std_core__list_drop(_y_19, _ctx);
  kk_std_core__list x_5673;
  size_t i_5676 = ((size_t)0); /*std/core/hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_5676,kk_context()); /*std/core/hnd/evv<<exn,div,std/num/random/random,fsys,console,ndet>>*/;
  kk_std_core__list y;
  kk_std_core_types__maybe _match_7559;
  kk_std_core__list _x7653;
  kk_box_t _box_x6096 = data.fst;
  kk_box_t _box_x6097 = data.snd;
  kk_std_core__list _x = kk_std_core__list_unbox(_box_x6096, NULL);
  kk_std_core__list_dup(_x);
  _x7653 = _x; /*list<list<effects-and-types/row_vector>>*/
  kk_integer_t _x7656 = kk_integer_dup(ind1); /*int*/
  _match_7559 = kk_std_core__lp__lb__rb__2_rp_(_x7653, _x7656, _ctx); /*maybe<1>*/
  if (kk_std_core_types__is_Nothing(_match_7559)) {
    kk_string_t message_205;
    kk_string_t _x7657;
    kk_define_string_literal(, _s7658, 48, "ListIndexError: Invalid list indexing at index: ")
    _x7657 = kk_string_dup(_s7658); /*string*/
    kk_string_t _x7659;
    kk_integer_t _x7660 = kk_integer_dup(ind1); /*int*/
    _x7659 = kk_std_core_show(_x7660, _ctx); /*string*/
    message_205 = kk_std_core__lp__plus__plus__1_rp_(_x7657, _x7659, _ctx); /*string*/
    kk_std_core__exception exn_21561;
    kk_std_core__exception_info _x7661;
    kk_std_core_types__optional _match_7561 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
    if (kk_std_core_types__is_Optional(_match_7561)) {
      kk_box_t _box_x6098 = _match_7561._cons.Optional.value;
      kk_std_core__exception_info _info_14279 = kk_std_core__exception_info_unbox(_box_x6098, NULL);
      kk_std_core__exception_info_dup(_info_14279);
      kk_std_core_types__optional_drop(_match_7561, _ctx);
      _x7661 = _info_14279; /*exception-info*/
      goto _match7662;
    }
    _x7661 = kk_std_core__new_ExnError(_ctx); /*exception-info*/
    _match7662: ;
    exn_21561 = kk_std_core__new_Exception(message_205, _x7661, _ctx); /*exception*/
    kk_std_core_hnd__ev ev_21562;
    size_t _x7664 = ((size_t)0); /*size_t*/
    ev_21562 = kk_evv_at(_x7664,kk_context()); /*std/core/hnd/ev<.hnd-exn>*/
    kk_box_t _x7665;
    struct kk_std_core_hnd_Ev* _con7666 = kk_std_core_hnd__as_Ev(ev_21562);
    kk_std_core_hnd__marker m = _con7666->marker;
    kk_box_t _box_x6099 = _con7666->hnd;
    kk_std_core__hnd_exn h = kk_std_core__hnd_exn_unbox(_box_x6099, NULL);
    kk_std_core__hnd_exn_dup(h);
    kk_std_core_hnd__clause1 _match_7560;
    struct kk_std_core__Hnd_exn* _con7668 = kk_std_core__as_Hnd_exn(h);
    kk_std_core_hnd__clause1 except_throw_exn = _con7668->except_throw_exn;
    if (kk_std_core__hnd_exn_is_unique(h)) {
      kk_std_core__hnd_exn_free(h);
    }
    else {
      kk_std_core_hnd__clause1_dup(except_throw_exn);
      kk_std_core__hnd_exn_decref(h, _ctx);
    }
    _match_7560 = except_throw_exn; /*forall<a> std/core/hnd/clause1<exception,a,.hnd-exn,7,8>*/
    kk_function_t _fun_unbox_x6103 = _match_7560.clause;
    _x7665 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x6103, (_fun_unbox_x6103, m, ev_21562, kk_std_core__exception_box(exn_21561, _ctx), _ctx)); /*11*/
    y = kk_std_core__list_unbox(_x7665, _ctx); /*list<effects-and-types/row_vector>*/
  }
  else {
    kk_box_t _box_x6107 = _match_7559._cons.Just.value;
    kk_std_core__list x = kk_std_core__list_unbox(_box_x6107, NULL);
    kk_std_core__list_dup(x);
    kk_std_core_types__maybe_drop(_match_7559, _ctx);
    y = x; /*list<effects-and-types/row_vector>*/
  }
  kk_unit_t __w_l717_c9 = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(y, _ctx);
    kk_box_t _x7670 = kk_std_core_hnd_yield_cont(kk_climate_dash_experiments__new_mlift5630_run__climate__model_fun7671(i_5676, _ctx), _ctx); /*3*/
    x_5673 = kk_std_core__list_unbox(_x7670, _ctx); /*list<effects-and-types/row_vector>*/
  }
  else {
    x_5673 = y; /*list<effects-and-types/row_vector>*/
  }
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_5673, _ctx);
    kk_box_t _x7672 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments__new_mlift5630_run__climate__model_fun7673(data, ind1, name1, pt, repeat__ind, rs, sbrs, diff1, subtract1, _ctx), _ctx); /*2*/
    kk_unit_unbox(_x7672); return kk_Unit;
  }
  kk_climate_dash_experiments__mlift5629_run__climate__model(data, diff1, ind1, name1, pt, repeat__ind, rs, sbrs, subtract1, x_5673, _ctx); return kk_Unit;
}
 
// monadic lift

kk_unit_t kk_climate_dash_experiments__mlift5631_run__climate__model(kk_std_core__list wild__5, kk_context_t* _ctx) { /* (wild_5 : list<()>) -> <console,div,exn,fsys,ndet,std/num/random/random> () */ 
  kk_std_core__list_drop(wild__5, _ctx);
  kk_string_t _x7676;
  kk_define_string_literal(, _s7677, 11, "End of SMC!")
  _x7676 = kk_string_dup(_s7677); /*string*/
  kk_std_core_printsln(_x7676, _ctx); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_climate_dash_experiments__mlift5632_run__climate__model_fun7688__t {
  struct kk_function_s _base;
};
static kk_box_t kk_climate_dash_experiments__mlift5632_run__climate__model_fun7688(kk_function_t _fself, kk_box_t _b_6132, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5632_run__climate__model_fun7688(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_climate_dash_experiments__mlift5632_run__climate__model_fun7688, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_climate_dash_experiments__mlift5632_run__climate__model_fun7688(kk_function_t _fself, kk_box_t _b_6132, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_os_path__path _x7689;
  kk_string_t _x7690 = kk_string_unbox(_b_6132); /*string*/
  _x7689 = kk_std_os_path_path(_x7690, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x7689, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift5632_run__climate__model_fun7693__t {
  struct kk_function_s _base;
};
static kk_box_t kk_climate_dash_experiments__mlift5632_run__climate__model_fun7693(kk_function_t _fself, kk_box_t _b_6137, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5632_run__climate__model_fun7693(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_climate_dash_experiments__mlift5632_run__climate__model_fun7693, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_climate_dash_experiments__mlift5632_run__climate__model_fun7693(kk_function_t _fself, kk_box_t _b_6137, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x7694;
  kk_std_core__list _x7695 = kk_std_core__list_unbox(_b_6137, _ctx); /*list<(list<double>, list<double>)>*/
  _x7694 = kk_output_dash_and_dash_plot_show__trace(_x7695, _ctx); /*string*/
  return kk_string_box(_x7694);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift5632_run__climate__model_fun7701__t {
  struct kk_function_s _base;
  size_t i_5682;
};
static kk_box_t kk_climate_dash_experiments__mlift5632_run__climate__model_fun7701(kk_function_t _fself, kk_function_t _b_6147, kk_box_t _b_6148, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5632_run__climate__model_fun7701(size_t i_5682, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5632_run__climate__model_fun7701__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5632_run__climate__model_fun7701__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5632_run__climate__model_fun7701, kk_context());
  _self->i_5682 = i_5682;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift5632_run__climate__model_fun7701(kk_function_t _fself, kk_function_t _b_6147, kk_box_t _b_6148, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5632_run__climate__model_fun7701__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5632_run__climate__model_fun7701__t*, _fself);
  size_t i_5682 = _self->i_5682; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_5682, _b_6147, _b_6148, _ctx);
}

kk_unit_t kk_climate_dash_experiments__mlift5632_run__climate__model(kk_string_t name0, kk_std_core_types__tuple2_ _y_12, kk_context_t* _ctx) { /* (name0 : string, (list<(list<double>, list<double>)>, tmcmc/trace<list<double>,<effects-and-types/sample,effects-and-types/score,div,exn,fsys,console,ndet,std/num/random/random>>)) -> <effects-and-types/sample,div,exn,fsys,console,ndet,std/num/random/random> () */ 
  kk_string_t _x210;
  kk_string_t _x7678;
  kk_define_string_literal(, _s7679, 17, "./output-climate/")
  _x7678 = kk_string_dup(_s7679); /*string*/
  kk_string_t _x7680;
  kk_string_t _x7681;
  kk_string_t _x7682;
  kk_define_string_literal(, _s7683, 1, "/")
  _x7682 = kk_string_dup(_s7683); /*string*/
  kk_string_t _x7684;
  kk_define_string_literal(, _s7685, 25, "tmcmc_exp_two_results.csv")
  _x7684 = kk_string_dup(_s7685); /*string*/
  _x7681 = kk_std_core__lp__plus__plus__1_rp_(_x7682, _x7684, _ctx); /*string*/
  _x7680 = kk_std_core__lp__plus__plus__1_rp_(name0, _x7681, _ctx); /*string*/
  _x210 = kk_std_core__lp__plus__plus__1_rp_(_x7678, _x7680, _ctx); /*string*/
  size_t i_5682 = ((size_t)0); /*std/core/hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_5682,kk_context()); /*std/core/hnd/evv<<exn,fsys,div,effects-and-types/sample,console,ndet,std/num/random/random>>*/;
  kk_unit_t y = kk_Unit;
  kk_std_os_path__path _x7686;
  kk_box_t _x7687 = kk_std_core_hnd__open_none1(kk_climate_dash_experiments__new_mlift5632_run__climate__model_fun7688(_ctx), kk_string_box(_x210), _ctx); /*2*/
  _x7686 = kk_std_os_path__path_unbox(_x7687, _ctx); /*std/os/path/path*/
  kk_string_t _x7691;
  kk_box_t _x7692;
  kk_box_t _x7696;
  kk_std_core__list _x7697;
  kk_box_t _box_x6133 = _y_12.fst;
  kk_box_t _box_x6134 = _y_12.snd;
  kk_std_core__list _x = kk_std_core__list_unbox(_box_x6133, NULL);
  kk_std_core__list_dup(_x);
  kk_std_core_types__tuple2__drop(_y_12, _ctx);
  _x7697 = _x; /*list<(list<double>, list<double>)>*/
  _x7696 = kk_std_core__list_box(_x7697, _ctx); /*1*/
  _x7692 = kk_std_core_hnd__open_none1(kk_climate_dash_experiments__new_mlift5632_run__climate__model_fun7693(_ctx), _x7696, _ctx); /*2*/
  _x7691 = kk_string_unbox(_x7692); /*string*/
  kk_std_os_file_write_text_file(_x7686, _x7691, kk_std_core_types__new_None(_ctx), _ctx);
  kk_unit_t __w_l717_c9 = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x7700 = kk_std_core_hnd_yield_cont(kk_climate_dash_experiments__new_mlift5632_run__climate__model_fun7701(i_5682, _ctx), _ctx); /*3*/
    kk_unit_unbox(_x7700); return kk_Unit;
  }
  y; return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_climate_dash_experiments__mlift5633_run__climate__model_fun7720__t {
  struct kk_function_s _base;
  size_t i_5689;
};
static kk_box_t kk_climate_dash_experiments__mlift5633_run__climate__model_fun7720(kk_function_t _fself, kk_function_t _b_6177, kk_box_t _b_6178, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5633_run__climate__model_fun7720(size_t i_5689, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5633_run__climate__model_fun7720__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5633_run__climate__model_fun7720__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5633_run__climate__model_fun7720, kk_context());
  _self->i_5689 = i_5689;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift5633_run__climate__model_fun7720(kk_function_t _fself, kk_function_t _b_6177, kk_box_t _b_6178, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5633_run__climate__model_fun7720__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5633_run__climate__model_fun7720__t*, _fself);
  size_t i_5689 = _self->i_5689; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_5689, _b_6177, _b_6178, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift5633_run__climate__model_fun7738__t {
  struct kk_function_s _base;
  size_t i0_5694;
};
static kk_box_t kk_climate_dash_experiments__mlift5633_run__climate__model_fun7738(kk_function_t _fself, kk_function_t _b_6207, kk_box_t _b_6208, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5633_run__climate__model_fun7738(size_t i0_5694, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5633_run__climate__model_fun7738__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5633_run__climate__model_fun7738__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5633_run__climate__model_fun7738, kk_context());
  _self->i0_5694 = i0_5694;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift5633_run__climate__model_fun7738(kk_function_t _fself, kk_function_t _b_6207, kk_box_t _b_6208, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5633_run__climate__model_fun7738__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5633_run__climate__model_fun7738__t*, _fself);
  size_t i0_5694 = _self->i0_5694; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i0_5694, _b_6207, _b_6208, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift5633_run__climate__model_fun7739__t {
  struct kk_function_s _base;
  kk_function_t _x09_5606;
};
static kk_std_core__list kk_climate_dash_experiments__mlift5633_run__climate__model_fun7739(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5633_run__climate__model_fun7739(kk_function_t _x09_5606, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5633_run__climate__model_fun7739__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5633_run__climate__model_fun7739__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5633_run__climate__model_fun7739, kk_context());
  _self->_x09_5606 = _x09_5606;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift5633_run__climate__model_fun7742__t {
  struct kk_function_s _base;
  kk_function_t _x09_5606;
};
static kk_box_t kk_climate_dash_experiments__mlift5633_run__climate__model_fun7742(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5633_run__climate__model_fun7742(kk_function_t _x09_5606, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5633_run__climate__model_fun7742__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5633_run__climate__model_fun7742__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5633_run__climate__model_fun7742, kk_context());
  _self->_x09_5606 = _x09_5606;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift5633_run__climate__model_fun7742(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5633_run__climate__model_fun7742__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5633_run__climate__model_fun7742__t*, _fself);
  kk_function_t _x09_5606 = _self->_x09_5606; /* effects-and-types/model<list<double>,exn> */
  kk_drop_match(_self, {kk_function_dup(_x09_5606);}, {}, _ctx)
  kk_std_core__list _x7743 = kk_function_call(kk_std_core__list, (kk_function_t, kk_context_t*), _x09_5606, (_x09_5606, _ctx)); /*list<double>*/
  return kk_std_core__list_box(_x7743, _ctx);
}
static kk_std_core__list kk_climate_dash_experiments__mlift5633_run__climate__model_fun7739(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5633_run__climate__model_fun7739__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5633_run__climate__model_fun7739__t*, _fself);
  kk_function_t _x09_5606 = _self->_x09_5606; /* effects-and-types/model<list<double>,exn> */
  kk_drop_match(_self, {kk_function_dup(_x09_5606);}, {}, _ctx)
  kk_vector_t _b_6233_6223;
  kk_std_core__list _x7740;
  size_t _b_6235_6221 = ((size_t)0); /*std/core/hnd/ev-index*/;
  kk_std_core__list _b_6236_6222;
  size_t _b_6237_6219 = ((size_t)2); /*std/core/hnd/ev-index*/;
  kk_std_core__list _b_6238_6220;
  size_t _b_6239_6217 = ((size_t)3); /*std/core/hnd/ev-index*/;
  _b_6238_6220 = kk_std_core__new_Cons(kk_reuse_null, kk_size_box(_b_6239_6217, _ctx), kk_std_core__new_Nil(_ctx), _ctx); /*list<std/core/hnd/ev-index>*/
  _b_6236_6222 = kk_std_core__new_Cons(kk_reuse_null, kk_size_box(_b_6237_6219, _ctx), _b_6238_6220, _ctx); /*list<std/core/hnd/ev-index>*/
  _x7740 = kk_std_core__new_Cons(kk_reuse_null, kk_size_box(_b_6235_6221, _ctx), _b_6236_6222, _ctx); /*list<0>*/
  _b_6233_6223 = kk_std_core_unvlist(_x7740, _ctx); /*vector<std/core/hnd/ev-index>*/
  kk_box_t _x7741 = kk_std_core_hnd__open0(_b_6233_6223, kk_climate_dash_experiments__new_mlift5633_run__climate__model_fun7742(_x09_5606, _ctx), _ctx); /*1*/
  return kk_std_core__list_unbox(_x7741, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift5633_run__climate__model_fun7744__t {
  struct kk_function_s _base;
  kk_function_t _b_6229_6225;
};
static kk_box_t kk_climate_dash_experiments__mlift5633_run__climate__model_fun7744(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5633_run__climate__model_fun7744(kk_function_t _b_6229_6225, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5633_run__climate__model_fun7744__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5633_run__climate__model_fun7744__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5633_run__climate__model_fun7744, kk_context());
  _self->_b_6229_6225 = _b_6229_6225;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift5633_run__climate__model_fun7744(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5633_run__climate__model_fun7744__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5633_run__climate__model_fun7744__t*, _fself);
  kk_function_t _b_6229_6225 = _self->_b_6229_6225; /* () -> <exn,effects-and-types/sample,effects-and-types/score> list<double> */
  kk_drop_match(_self, {kk_function_dup(_b_6229_6225);}, {}, _ctx)
  kk_std_core__list _x7745 = kk_function_call(kk_std_core__list, (kk_function_t, kk_context_t*), _b_6229_6225, (_b_6229_6225, _ctx)); /*list<double>*/
  return kk_std_core__list_box(_x7745, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift5633_run__climate__model_fun7747__t {
  struct kk_function_s _base;
  kk_string_t name0;
};
static kk_box_t kk_climate_dash_experiments__mlift5633_run__climate__model_fun7747(kk_function_t _fself, kk_box_t _b_6242, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5633_run__climate__model_fun7747(kk_string_t name0, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5633_run__climate__model_fun7747__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5633_run__climate__model_fun7747__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5633_run__climate__model_fun7747, kk_context());
  _self->name0 = name0;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift5633_run__climate__model_fun7747(kk_function_t _fself, kk_box_t _b_6242, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5633_run__climate__model_fun7747__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5633_run__climate__model_fun7747__t*, _fself);
  kk_string_t name0 = _self->name0; /* string */
  kk_drop_match(_self, {kk_string_dup(name0);}, {}, _ctx)
  kk_unit_t _x7748 = kk_Unit;
  kk_std_core_types__tuple2_ _x7749 = kk_std_core_types__tuple2__unbox(_b_6242, _ctx); /*(list<(list<double>, list<double>)>, tmcmc/trace<list<double>,<effects-and-types/sample,effects-and-types/score,div,exn,fsys,console,ndet,std/num/random/random>>)*/
  kk_climate_dash_experiments__mlift5632_run__climate__model(name0, _x7749, _ctx);
  return kk_unit_box(_x7748);
}

kk_unit_t kk_climate_dash_experiments__mlift5633_run__climate__model(kk_integer_t burnin, kk_std_core_types__tuple2_ data, double diff0, kk_integer_t ind0, kk_string_t name0, double subtract0, kk_integer_t t__steps, kk_std_core__list _y_11, kk_context_t* _ctx) { /* (burnin : int, data : (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>), diff0 : double, ind0 : int, name0 : string, subtract0 : double, t_steps : int, list<effects-and-types/row_vector>) -> <exn,div,effects-and-types/sample,fsys,console,ndet,std/num/random/random> () */ 
  kk_std_core__list_drop(_y_11, _ctx);
  kk_std_core_types__tuple2_ x_5686;
  kk_function_t _b_6229_6225;
  kk_function_t _x09_5606;
  kk_std_core__list _x17;
  size_t i_5689 = ((size_t)0); /*std/core/hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_5689,kk_context()); /*std/core/hnd/evv<<exn,div,effects-and-types/sample,fsys,console,ndet,std/num/random/random>>*/;
  kk_std_core__list y;
  kk_std_core_types__maybe _match_7553;
  kk_std_core__list _x7702;
  kk_box_t _box_x6157 = data.fst;
  kk_box_t _box_x6158 = data.snd;
  kk_std_core__list _x = kk_std_core__list_unbox(_box_x6158, NULL);
  kk_std_core__list_dup(_x);
  _x7702 = _x; /*list<list<effects-and-types/row_vector>>*/
  kk_integer_t _x7705 = kk_integer_dup(ind0); /*int*/
  _match_7553 = kk_std_core__lp__lb__rb__2_rp_(_x7702, _x7705, _ctx); /*maybe<1>*/
  if (kk_std_core_types__is_Nothing(_match_7553)) {
    kk_string_t message_205;
    kk_string_t _x7706;
    kk_define_string_literal(, _s7707, 48, "ListIndexError: Invalid list indexing at index: ")
    _x7706 = kk_string_dup(_s7707); /*string*/
    kk_string_t _x7708;
    kk_integer_t _x7709 = kk_integer_dup(ind0); /*int*/
    _x7708 = kk_std_core_show(_x7709, _ctx); /*string*/
    message_205 = kk_std_core__lp__plus__plus__1_rp_(_x7706, _x7708, _ctx); /*string*/
    kk_std_core__exception exn_21561;
    kk_std_core__exception_info _x7710;
    kk_std_core_types__optional _match_7555 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
    if (kk_std_core_types__is_Optional(_match_7555)) {
      kk_box_t _box_x6159 = _match_7555._cons.Optional.value;
      kk_std_core__exception_info _info_14279 = kk_std_core__exception_info_unbox(_box_x6159, NULL);
      kk_std_core__exception_info_dup(_info_14279);
      kk_std_core_types__optional_drop(_match_7555, _ctx);
      _x7710 = _info_14279; /*exception-info*/
      goto _match7711;
    }
    _x7710 = kk_std_core__new_ExnError(_ctx); /*exception-info*/
    _match7711: ;
    exn_21561 = kk_std_core__new_Exception(message_205, _x7710, _ctx); /*exception*/
    kk_std_core_hnd__ev ev_21562;
    size_t _x7713 = ((size_t)0); /*size_t*/
    ev_21562 = kk_evv_at(_x7713,kk_context()); /*std/core/hnd/ev<.hnd-exn>*/
    kk_box_t _x7714;
    struct kk_std_core_hnd_Ev* _con7715 = kk_std_core_hnd__as_Ev(ev_21562);
    kk_std_core_hnd__marker m = _con7715->marker;
    kk_box_t _box_x6160 = _con7715->hnd;
    kk_std_core__hnd_exn h = kk_std_core__hnd_exn_unbox(_box_x6160, NULL);
    kk_std_core__hnd_exn_dup(h);
    kk_std_core_hnd__clause1 _match_7554;
    struct kk_std_core__Hnd_exn* _con7717 = kk_std_core__as_Hnd_exn(h);
    kk_std_core_hnd__clause1 except_throw_exn = _con7717->except_throw_exn;
    if (kk_std_core__hnd_exn_is_unique(h)) {
      kk_std_core__hnd_exn_free(h);
    }
    else {
      kk_std_core_hnd__clause1_dup(except_throw_exn);
      kk_std_core__hnd_exn_decref(h, _ctx);
    }
    _match_7554 = except_throw_exn; /*forall<a> std/core/hnd/clause1<exception,a,.hnd-exn,7,8>*/
    kk_function_t _fun_unbox_x6164 = _match_7554.clause;
    _x7714 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x6164, (_fun_unbox_x6164, m, ev_21562, kk_std_core__exception_box(exn_21561, _ctx), _ctx)); /*11*/
    y = kk_std_core__list_unbox(_x7714, _ctx); /*list<effects-and-types/row_vector>*/
  }
  else {
    kk_box_t _box_x6168 = _match_7553._cons.Just.value;
    kk_std_core__list x = kk_std_core__list_unbox(_box_x6168, NULL);
    kk_std_core__list_dup(x);
    kk_std_core_types__maybe_drop(_match_7553, _ctx);
    y = x; /*list<effects-and-types/row_vector>*/
  }
  kk_unit_t __w_l717_c9 = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(y, _ctx);
    kk_box_t _x7719 = kk_std_core_hnd_yield_cont(kk_climate_dash_experiments__new_mlift5633_run__climate__model_fun7720(i_5689, _ctx), _ctx); /*3*/
    _x17 = kk_std_core__list_unbox(_x7719, _ctx); /*list<effects-and-types/row_vector>*/
  }
  else {
    _x17 = y; /*list<effects-and-types/row_vector>*/
  }
  kk_std_core__list _x27;
  size_t i0_5694 = ((size_t)0); /*std/core/hnd/ev-index*/;
  kk_evv_t w0 = kk_evv_swap_create1(i0_5694,kk_context()); /*std/core/hnd/evv<<exn,div,effects-and-types/sample,fsys,console,ndet,std/num/random/random>>*/;
  kk_std_core__list y0;
  kk_std_core_types__maybe _match_7549;
  kk_std_core__list _x7721;
  kk_box_t _box_x6187 = data.fst;
  kk_box_t _box_x6188 = data.snd;
  kk_std_core__list _x0 = kk_std_core__list_unbox(_box_x6187, NULL);
  kk_std_core__list_dup(_x0);
  kk_std_core_types__tuple2__drop(data, _ctx);
  _x7721 = _x0; /*list<list<effects-and-types/row_vector>>*/
  kk_integer_t _x7724 = kk_integer_dup(ind0); /*int*/
  _match_7549 = kk_std_core__lp__lb__rb__2_rp_(_x7721, _x7724, _ctx); /*maybe<1>*/
  if (kk_std_core_types__is_Nothing(_match_7549)) {
    kk_string_t message_2050;
    kk_string_t _x7725;
    kk_define_string_literal(, _s7726, 48, "ListIndexError: Invalid list indexing at index: ")
    _x7725 = kk_string_dup(_s7726); /*string*/
    kk_string_t _x7727 = kk_std_core_show(ind0, _ctx); /*string*/
    message_2050 = kk_std_core__lp__plus__plus__1_rp_(_x7725, _x7727, _ctx); /*string*/
    kk_std_core__exception exn_215610;
    kk_std_core__exception_info _x7728;
    kk_std_core_types__optional _match_7551 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
    if (kk_std_core_types__is_Optional(_match_7551)) {
      kk_box_t _box_x6189 = _match_7551._cons.Optional.value;
      kk_std_core__exception_info _info_142790 = kk_std_core__exception_info_unbox(_box_x6189, NULL);
      kk_std_core__exception_info_dup(_info_142790);
      kk_std_core_types__optional_drop(_match_7551, _ctx);
      _x7728 = _info_142790; /*exception-info*/
      goto _match7729;
    }
    _x7728 = kk_std_core__new_ExnError(_ctx); /*exception-info*/
    _match7729: ;
    exn_215610 = kk_std_core__new_Exception(message_2050, _x7728, _ctx); /*exception*/
    kk_std_core_hnd__ev ev_215620;
    size_t _x7731 = ((size_t)0); /*size_t*/
    ev_215620 = kk_evv_at(_x7731,kk_context()); /*std/core/hnd/ev<.hnd-exn>*/
    kk_box_t _x7732;
    struct kk_std_core_hnd_Ev* _con7733 = kk_std_core_hnd__as_Ev(ev_215620);
    kk_std_core_hnd__marker m0 = _con7733->marker;
    kk_box_t _box_x6190 = _con7733->hnd;
    kk_std_core__hnd_exn h0 = kk_std_core__hnd_exn_unbox(_box_x6190, NULL);
    kk_std_core__hnd_exn_dup(h0);
    kk_std_core_hnd__clause1 _match_7550;
    struct kk_std_core__Hnd_exn* _con7735 = kk_std_core__as_Hnd_exn(h0);
    kk_std_core_hnd__clause1 except_throw_exn0 = _con7735->except_throw_exn;
    if (kk_std_core__hnd_exn_is_unique(h0)) {
      kk_std_core__hnd_exn_free(h0);
    }
    else {
      kk_std_core_hnd__clause1_dup(except_throw_exn0);
      kk_std_core__hnd_exn_decref(h0, _ctx);
    }
    _match_7550 = except_throw_exn0; /*forall<a> std/core/hnd/clause1<exception,a,.hnd-exn,7,8>*/
    kk_function_t _fun_unbox_x6194 = _match_7550.clause;
    _x7732 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x6194, (_fun_unbox_x6194, m0, ev_215620, kk_std_core__exception_box(exn_215610, _ctx), _ctx)); /*11*/
    y0 = kk_std_core__list_unbox(_x7732, _ctx); /*list<effects-and-types/row_vector>*/
  }
  else {
    kk_box_t _box_x6198 = _match_7549._cons.Just.value;
    kk_std_core__list x0 = kk_std_core__list_unbox(_box_x6198, NULL);
    kk_integer_drop(ind0, _ctx);
    kk_std_core__list_dup(x0);
    kk_std_core_types__maybe_drop(_match_7549, _ctx);
    y0 = x0; /*list<effects-and-types/row_vector>*/
  }
  kk_unit_t __w_l717_c90 = kk_Unit;
  kk_evv_set(w0,kk_context());
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(y0, _ctx);
    kk_box_t _x7737 = kk_std_core_hnd_yield_cont(kk_climate_dash_experiments__new_mlift5633_run__climate__model_fun7738(i0_5694, _ctx), _ctx); /*3*/
    _x27 = kk_std_core__list_unbox(_x7737, _ctx); /*list<effects-and-types/row_vector>*/
  }
  else {
    _x27 = y0; /*list<effects-and-types/row_vector>*/
  }
  kk_evv_t w1 = kk_evv_swap_create0(kk_context()); /*std/core/hnd/evv<(<>)>*/;
  kk_function_t x00 = kk_climate_dash_change_linear__gaussian__climate__data(_x17, _x27, false, diff0, subtract0, 0x1.2cccccccccccdp2, _ctx); /*effects-and-types/model<list<double>,exn>*/;
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w1,kk_context());
  _x09_5606 = x00; /*effects-and-types/model<list<double>,exn>*/
  _b_6229_6225 = kk_climate_dash_experiments__new_mlift5633_run__climate__model_fun7739(_x09_5606, _ctx); /*() -> <exn,effects-and-types/sample,effects-and-types/score> list<double>*/
  kk_effects_dash_and_dash_types__exp _b_6231_6227 = kk_effects_dash_and_dash_types__new_Exp(0x0p+0, _ctx); /*effects-and-types/exp*/;
  x_5686 = kk_tmcmc_tmcmc(kk_climate_dash_experiments__new_mlift5633_run__climate__model_fun7744(_b_6229_6225, _ctx), t__steps, _b_6231_6227, burnin, _ctx); /*(list<(list<double>, list<double>)>, tmcmc/trace<list<double>,<effects-and-types/sample,effects-and-types/score,div,exn,fsys,console,ndet,std/num/random/random>>)*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__tuple2__drop(x_5686, _ctx);
    kk_box_t _x7746 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments__new_mlift5633_run__climate__model_fun7747(name0, _ctx), _ctx); /*2*/
    kk_unit_unbox(_x7746); return kk_Unit;
  }
  kk_climate_dash_experiments__mlift5632_run__climate__model(name0, x_5686, _ctx); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_climate_dash_experiments__mlift5634_run__climate__model_fun7768__t {
  struct kk_function_s _base;
  size_t i_5702;
};
static kk_box_t kk_climate_dash_experiments__mlift5634_run__climate__model_fun7768(kk_function_t _fself, kk_function_t _b_6265, kk_box_t _b_6266, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5634_run__climate__model_fun7768(size_t i_5702, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5634_run__climate__model_fun7768__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5634_run__climate__model_fun7768__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5634_run__climate__model_fun7768, kk_context());
  _self->i_5702 = i_5702;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift5634_run__climate__model_fun7768(kk_function_t _fself, kk_function_t _b_6265, kk_box_t _b_6266, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5634_run__climate__model_fun7768__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5634_run__climate__model_fun7768__t*, _fself);
  size_t i_5702 = _self->i_5702; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_5702, _b_6265, _b_6266, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift5634_run__climate__model_fun7770__t {
  struct kk_function_s _base;
  kk_integer_t burnin;
  kk_std_core_types__tuple2_ data;
  kk_integer_t ind0;
  kk_string_t name0;
  kk_integer_t t__steps;
  double diff0;
  double subtract0;
};
static kk_box_t kk_climate_dash_experiments__mlift5634_run__climate__model_fun7770(kk_function_t _fself, kk_box_t _b_6276, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5634_run__climate__model_fun7770(kk_integer_t burnin, kk_std_core_types__tuple2_ data, kk_integer_t ind0, kk_string_t name0, kk_integer_t t__steps, double diff0, double subtract0, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5634_run__climate__model_fun7770__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5634_run__climate__model_fun7770__t, 7, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5634_run__climate__model_fun7770, kk_context());
  _self->burnin = burnin;
  _self->data = data;
  _self->ind0 = ind0;
  _self->name0 = name0;
  _self->t__steps = t__steps;
  _self->diff0 = diff0;
  _self->subtract0 = subtract0;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift5634_run__climate__model_fun7770(kk_function_t _fself, kk_box_t _b_6276, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5634_run__climate__model_fun7770__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5634_run__climate__model_fun7770__t*, _fself);
  kk_integer_t burnin = _self->burnin; /* int */
  kk_std_core_types__tuple2_ data = _self->data; /* (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>) */
  kk_integer_t ind0 = _self->ind0; /* int */
  kk_string_t name0 = _self->name0; /* string */
  kk_integer_t t__steps = _self->t__steps; /* int */
  double diff0 = _self->diff0; /* double */
  double subtract0 = _self->subtract0; /* double */
  kk_drop_match(_self, {kk_integer_dup(burnin);kk_std_core_types__tuple2__dup(data);kk_integer_dup(ind0);kk_string_dup(name0);kk_integer_dup(t__steps);;;}, {}, _ctx)
  kk_unit_t _x7771 = kk_Unit;
  kk_std_core__list _x7772 = kk_std_core__list_unbox(_b_6276, _ctx); /*list<effects-and-types/row_vector>*/
  kk_climate_dash_experiments__mlift5633_run__climate__model(burnin, data, diff0, ind0, name0, subtract0, t__steps, _x7772, _ctx);
  return kk_unit_box(_x7771);
}

kk_unit_t kk_climate_dash_experiments__mlift5634_run__climate__model(kk_integer_t burnin, kk_std_core_types__tuple2_ data, double diff0, kk_integer_t ind0, kk_string_t name0, double subtract0, kk_integer_t t__steps, kk_std_core__list _y_10, kk_context_t* _ctx) { /* (burnin : int, data : (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>), diff0 : double, ind0 : int, name0 : string, subtract0 : double, t_steps : int, list<effects-and-types/row_vector>) -> <exn,div,effects-and-types/sample,fsys,console,ndet,std/num/random/random> () */ 
  kk_std_core__list_drop(_y_10, _ctx);
  kk_std_core__list x_5699;
  size_t i_5702 = ((size_t)0); /*std/core/hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_5702,kk_context()); /*std/core/hnd/evv<<exn,div,effects-and-types/sample,fsys,console,ndet,std/num/random/random>>*/;
  kk_std_core__list y;
  kk_std_core_types__maybe _match_7544;
  kk_std_core__list _x7750;
  kk_box_t _box_x6245 = data.fst;
  kk_box_t _box_x6246 = data.snd;
  kk_std_core__list _x = kk_std_core__list_unbox(_box_x6245, NULL);
  kk_std_core__list_dup(_x);
  _x7750 = _x; /*list<list<effects-and-types/row_vector>>*/
  kk_integer_t _x7753 = kk_integer_dup(ind0); /*int*/
  _match_7544 = kk_std_core__lp__lb__rb__2_rp_(_x7750, _x7753, _ctx); /*maybe<1>*/
  if (kk_std_core_types__is_Nothing(_match_7544)) {
    kk_string_t message_205;
    kk_string_t _x7754;
    kk_define_string_literal(, _s7755, 48, "ListIndexError: Invalid list indexing at index: ")
    _x7754 = kk_string_dup(_s7755); /*string*/
    kk_string_t _x7756;
    kk_integer_t _x7757 = kk_integer_dup(ind0); /*int*/
    _x7756 = kk_std_core_show(_x7757, _ctx); /*string*/
    message_205 = kk_std_core__lp__plus__plus__1_rp_(_x7754, _x7756, _ctx); /*string*/
    kk_std_core__exception exn_21561;
    kk_std_core__exception_info _x7758;
    kk_std_core_types__optional _match_7546 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
    if (kk_std_core_types__is_Optional(_match_7546)) {
      kk_box_t _box_x6247 = _match_7546._cons.Optional.value;
      kk_std_core__exception_info _info_14279 = kk_std_core__exception_info_unbox(_box_x6247, NULL);
      kk_std_core__exception_info_dup(_info_14279);
      kk_std_core_types__optional_drop(_match_7546, _ctx);
      _x7758 = _info_14279; /*exception-info*/
      goto _match7759;
    }
    _x7758 = kk_std_core__new_ExnError(_ctx); /*exception-info*/
    _match7759: ;
    exn_21561 = kk_std_core__new_Exception(message_205, _x7758, _ctx); /*exception*/
    kk_std_core_hnd__ev ev_21562;
    size_t _x7761 = ((size_t)0); /*size_t*/
    ev_21562 = kk_evv_at(_x7761,kk_context()); /*std/core/hnd/ev<.hnd-exn>*/
    kk_box_t _x7762;
    struct kk_std_core_hnd_Ev* _con7763 = kk_std_core_hnd__as_Ev(ev_21562);
    kk_std_core_hnd__marker m = _con7763->marker;
    kk_box_t _box_x6248 = _con7763->hnd;
    kk_std_core__hnd_exn h = kk_std_core__hnd_exn_unbox(_box_x6248, NULL);
    kk_std_core__hnd_exn_dup(h);
    kk_std_core_hnd__clause1 _match_7545;
    struct kk_std_core__Hnd_exn* _con7765 = kk_std_core__as_Hnd_exn(h);
    kk_std_core_hnd__clause1 except_throw_exn = _con7765->except_throw_exn;
    if (kk_std_core__hnd_exn_is_unique(h)) {
      kk_std_core__hnd_exn_free(h);
    }
    else {
      kk_std_core_hnd__clause1_dup(except_throw_exn);
      kk_std_core__hnd_exn_decref(h, _ctx);
    }
    _match_7545 = except_throw_exn; /*forall<a> std/core/hnd/clause1<exception,a,.hnd-exn,7,8>*/
    kk_function_t _fun_unbox_x6252 = _match_7545.clause;
    _x7762 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x6252, (_fun_unbox_x6252, m, ev_21562, kk_std_core__exception_box(exn_21561, _ctx), _ctx)); /*11*/
    y = kk_std_core__list_unbox(_x7762, _ctx); /*list<effects-and-types/row_vector>*/
  }
  else {
    kk_box_t _box_x6256 = _match_7544._cons.Just.value;
    kk_std_core__list x = kk_std_core__list_unbox(_box_x6256, NULL);
    kk_std_core__list_dup(x);
    kk_std_core_types__maybe_drop(_match_7544, _ctx);
    y = x; /*list<effects-and-types/row_vector>*/
  }
  kk_unit_t __w_l717_c9 = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(y, _ctx);
    kk_box_t _x7767 = kk_std_core_hnd_yield_cont(kk_climate_dash_experiments__new_mlift5634_run__climate__model_fun7768(i_5702, _ctx), _ctx); /*3*/
    x_5699 = kk_std_core__list_unbox(_x7767, _ctx); /*list<effects-and-types/row_vector>*/
  }
  else {
    x_5699 = y; /*list<effects-and-types/row_vector>*/
  }
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_5699, _ctx);
    kk_box_t _x7769 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments__new_mlift5634_run__climate__model_fun7770(burnin, data, ind0, name0, t__steps, diff0, subtract0, _ctx), _ctx); /*2*/
    kk_unit_unbox(_x7769); return kk_Unit;
  }
  kk_climate_dash_experiments__mlift5633_run__climate__model(burnin, data, diff0, ind0, name0, subtract0, t__steps, x_5699, _ctx); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_climate_dash_experiments__mlift5635_run__climate__model_fun7774__t {
  struct kk_function_s _base;
  kk_std_core_types__tuple2_ data;
  kk_std_core__list pre__data;
  kk_integer_t pt;
  kk_std_core_types__optional repeat__num;
  kk_integer_t rs;
  kk_integer_t sbrs;
};
static kk_box_t kk_climate_dash_experiments__mlift5635_run__climate__model_fun7774(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5635_run__climate__model_fun7774(kk_std_core_types__tuple2_ data, kk_std_core__list pre__data, kk_integer_t pt, kk_std_core_types__optional repeat__num, kk_integer_t rs, kk_integer_t sbrs, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5635_run__climate__model_fun7774__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5635_run__climate__model_fun7774__t, 9, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5635_run__climate__model_fun7774, kk_context());
  _self->data = data;
  _self->pre__data = pre__data;
  _self->pt = pt;
  _self->repeat__num = repeat__num;
  _self->rs = rs;
  _self->sbrs = sbrs;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift5635_run__climate__model_fun7779__t {
  struct kk_function_s _base;
  kk_std_core_types__tuple2_ data;
  kk_integer_t pt;
  kk_std_core_types__optional repeat__num;
  kk_integer_t rs;
  kk_integer_t sbrs;
};
static kk_box_t kk_climate_dash_experiments__mlift5635_run__climate__model_fun7779(kk_function_t _fself, kk_box_t _b_6321, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5635_run__climate__model_fun7779(kk_std_core_types__tuple2_ data, kk_integer_t pt, kk_std_core_types__optional repeat__num, kk_integer_t rs, kk_integer_t sbrs, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5635_run__climate__model_fun7779__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5635_run__climate__model_fun7779__t, 8, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5635_run__climate__model_fun7779, kk_context());
  _self->data = data;
  _self->pt = pt;
  _self->repeat__num = repeat__num;
  _self->rs = rs;
  _self->sbrs = sbrs;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift5635_run__climate__model_fun7781__t {
  struct kk_function_s _base;
  kk_box_t _b_6321;
  kk_std_core_types__tuple2_ data;
  kk_integer_t pt;
  kk_integer_t rs;
  kk_integer_t sbrs;
};
static kk_unit_t kk_climate_dash_experiments__mlift5635_run__climate__model_fun7781(kk_function_t _fself, kk_integer_t repeat__ind, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5635_run__climate__model_fun7781(kk_box_t _b_6321, kk_std_core_types__tuple2_ data, kk_integer_t pt, kk_integer_t rs, kk_integer_t sbrs, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5635_run__climate__model_fun7781__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5635_run__climate__model_fun7781__t, 7, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5635_run__climate__model_fun7781, kk_context());
  _self->_b_6321 = _b_6321;
  _self->data = data;
  _self->pt = pt;
  _self->rs = rs;
  _self->sbrs = sbrs;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift5635_run__climate__model_fun7788__t {
  struct kk_function_s _base;
  kk_std_core_types__tuple2_ data;
  kk_integer_t ind1;
  kk_string_t name1;
  kk_integer_t pt;
  kk_integer_t repeat__ind;
  kk_integer_t rs;
  kk_integer_t sbrs;
  double diff1;
  double subtract1;
};
static kk_box_t kk_climate_dash_experiments__mlift5635_run__climate__model_fun7788(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5635_run__climate__model_fun7788(kk_std_core_types__tuple2_ data, kk_integer_t ind1, kk_string_t name1, kk_integer_t pt, kk_integer_t repeat__ind, kk_integer_t rs, kk_integer_t sbrs, double diff1, double subtract1, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5635_run__climate__model_fun7788__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5635_run__climate__model_fun7788__t, 9, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5635_run__climate__model_fun7788, kk_context());
  _self->data = data;
  _self->ind1 = ind1;
  _self->name1 = name1;
  _self->pt = pt;
  _self->repeat__ind = repeat__ind;
  _self->rs = rs;
  _self->sbrs = sbrs;
  _self->diff1 = diff1;
  _self->subtract1 = subtract1;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift5635_run__climate__model_fun7808__t {
  struct kk_function_s _base;
  size_t i_5717;
};
static kk_box_t kk_climate_dash_experiments__mlift5635_run__climate__model_fun7808(kk_function_t _fself, kk_function_t _b_6304, kk_box_t _b_6305, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5635_run__climate__model_fun7808(size_t i_5717, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5635_run__climate__model_fun7808__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5635_run__climate__model_fun7808__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5635_run__climate__model_fun7808, kk_context());
  _self->i_5717 = i_5717;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift5635_run__climate__model_fun7808(kk_function_t _fself, kk_function_t _b_6304, kk_box_t _b_6305, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5635_run__climate__model_fun7808__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5635_run__climate__model_fun7808__t*, _fself);
  size_t i_5717 = _self->i_5717; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_5717, _b_6304, _b_6305, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift5635_run__climate__model_fun7810__t {
  struct kk_function_s _base;
  kk_std_core_types__tuple2_ data;
  kk_integer_t ind1;
  kk_string_t name1;
  kk_integer_t pt;
  kk_integer_t repeat__ind;
  kk_integer_t rs;
  kk_integer_t sbrs;
  double diff1;
  double subtract1;
};
static kk_box_t kk_climate_dash_experiments__mlift5635_run__climate__model_fun7810(kk_function_t _fself, kk_box_t _b_6315, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5635_run__climate__model_fun7810(kk_std_core_types__tuple2_ data, kk_integer_t ind1, kk_string_t name1, kk_integer_t pt, kk_integer_t repeat__ind, kk_integer_t rs, kk_integer_t sbrs, double diff1, double subtract1, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5635_run__climate__model_fun7810__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5635_run__climate__model_fun7810__t, 9, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5635_run__climate__model_fun7810, kk_context());
  _self->data = data;
  _self->ind1 = ind1;
  _self->name1 = name1;
  _self->pt = pt;
  _self->repeat__ind = repeat__ind;
  _self->rs = rs;
  _self->sbrs = sbrs;
  _self->diff1 = diff1;
  _self->subtract1 = subtract1;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift5635_run__climate__model_fun7810(kk_function_t _fself, kk_box_t _b_6315, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5635_run__climate__model_fun7810__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5635_run__climate__model_fun7810__t*, _fself);
  kk_std_core_types__tuple2_ data = _self->data; /* (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>) */
  kk_integer_t ind1 = _self->ind1; /* int */
  kk_string_t name1 = _self->name1; /* string */
  kk_integer_t pt = _self->pt; /* int */
  kk_integer_t repeat__ind = _self->repeat__ind; /* int */
  kk_integer_t rs = _self->rs; /* int */
  kk_integer_t sbrs = _self->sbrs; /* int */
  double diff1 = _self->diff1; /* double */
  double subtract1 = _self->subtract1; /* double */
  kk_drop_match(_self, {kk_std_core_types__tuple2__dup(data);kk_integer_dup(ind1);kk_string_dup(name1);kk_integer_dup(pt);kk_integer_dup(repeat__ind);kk_integer_dup(rs);kk_integer_dup(sbrs);;;}, {}, _ctx)
  kk_unit_t _x7811 = kk_Unit;
  kk_std_core__list _x7812 = kk_std_core__list_unbox(_b_6315, _ctx); /*list<effects-and-types/row_vector>*/
  kk_climate_dash_experiments__mlift5630_run__climate__model(data, diff1, ind1, name1, pt, repeat__ind, rs, sbrs, subtract1, _x7812, _ctx);
  return kk_unit_box(_x7811);
}
static kk_box_t kk_climate_dash_experiments__mlift5635_run__climate__model_fun7788(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5635_run__climate__model_fun7788__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5635_run__climate__model_fun7788__t*, _fself);
  kk_std_core_types__tuple2_ data = _self->data; /* (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>) */
  kk_integer_t ind1 = _self->ind1; /* int */
  kk_string_t name1 = _self->name1; /* string */
  kk_integer_t pt = _self->pt; /* int */
  kk_integer_t repeat__ind = _self->repeat__ind; /* int */
  kk_integer_t rs = _self->rs; /* int */
  kk_integer_t sbrs = _self->sbrs; /* int */
  double diff1 = _self->diff1; /* double */
  double subtract1 = _self->subtract1; /* double */
  kk_drop_match(_self, {kk_std_core_types__tuple2__dup(data);kk_integer_dup(ind1);kk_string_dup(name1);kk_integer_dup(pt);kk_integer_dup(repeat__ind);kk_integer_dup(rs);kk_integer_dup(sbrs);;;}, {}, _ctx)
  kk_unit_t _x7789 = kk_Unit;
  kk_std_core__list x0_5714;
  size_t i_5717 = ((size_t)0); /*std/core/hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_5717,kk_context()); /*std/core/hnd/evv<<exn,div,std/num/random/random,fsys,console,ndet>>*/;
  kk_std_core__list y;
  kk_std_core_types__maybe _match_7539;
  kk_std_core__list _x7790;
  kk_box_t _box_x6284 = data.fst;
  kk_box_t _box_x6285 = data.snd;
  kk_std_core__list _x = kk_std_core__list_unbox(_box_x6285, NULL);
  kk_std_core__list_dup(_x);
  _x7790 = _x; /*list<list<effects-and-types/row_vector>>*/
  kk_integer_t _x7793 = kk_integer_dup(ind1); /*int*/
  _match_7539 = kk_std_core__lp__lb__rb__2_rp_(_x7790, _x7793, _ctx); /*maybe<1>*/
  if (kk_std_core_types__is_Nothing(_match_7539)) {
    kk_string_t message_205;
    kk_string_t _x7794;
    kk_define_string_literal(, _s7795, 48, "ListIndexError: Invalid list indexing at index: ")
    _x7794 = kk_string_dup(_s7795); /*string*/
    kk_string_t _x7796;
    kk_integer_t _x7797 = kk_integer_dup(ind1); /*int*/
    _x7796 = kk_std_core_show(_x7797, _ctx); /*string*/
    message_205 = kk_std_core__lp__plus__plus__1_rp_(_x7794, _x7796, _ctx); /*string*/
    kk_std_core__exception exn_21561;
    kk_std_core__exception_info _x7798;
    kk_std_core_types__optional _match_7541 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
    if (kk_std_core_types__is_Optional(_match_7541)) {
      kk_box_t _box_x6286 = _match_7541._cons.Optional.value;
      kk_std_core__exception_info _info_14279 = kk_std_core__exception_info_unbox(_box_x6286, NULL);
      kk_std_core__exception_info_dup(_info_14279);
      kk_std_core_types__optional_drop(_match_7541, _ctx);
      _x7798 = _info_14279; /*exception-info*/
      goto _match7799;
    }
    _x7798 = kk_std_core__new_ExnError(_ctx); /*exception-info*/
    _match7799: ;
    exn_21561 = kk_std_core__new_Exception(message_205, _x7798, _ctx); /*exception*/
    kk_std_core_hnd__ev ev_21562;
    size_t _x7801 = ((size_t)0); /*size_t*/
    ev_21562 = kk_evv_at(_x7801,kk_context()); /*std/core/hnd/ev<.hnd-exn>*/
    kk_box_t _x7802;
    struct kk_std_core_hnd_Ev* _con7803 = kk_std_core_hnd__as_Ev(ev_21562);
    kk_std_core_hnd__marker m = _con7803->marker;
    kk_box_t _box_x6287 = _con7803->hnd;
    kk_std_core__hnd_exn h = kk_std_core__hnd_exn_unbox(_box_x6287, NULL);
    kk_std_core__hnd_exn_dup(h);
    kk_std_core_hnd__clause1 _match_7540;
    struct kk_std_core__Hnd_exn* _con7805 = kk_std_core__as_Hnd_exn(h);
    kk_std_core_hnd__clause1 except_throw_exn = _con7805->except_throw_exn;
    if (kk_std_core__hnd_exn_is_unique(h)) {
      kk_std_core__hnd_exn_free(h);
    }
    else {
      kk_std_core_hnd__clause1_dup(except_throw_exn);
      kk_std_core__hnd_exn_decref(h, _ctx);
    }
    _match_7540 = except_throw_exn; /*forall<a> std/core/hnd/clause1<exception,a,.hnd-exn,7,8>*/
    kk_function_t _fun_unbox_x6291 = _match_7540.clause;
    _x7802 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x6291, (_fun_unbox_x6291, m, ev_21562, kk_std_core__exception_box(exn_21561, _ctx), _ctx)); /*11*/
    y = kk_std_core__list_unbox(_x7802, _ctx); /*list<effects-and-types/row_vector>*/
  }
  else {
    kk_box_t _box_x6295 = _match_7539._cons.Just.value;
    kk_std_core__list x = kk_std_core__list_unbox(_box_x6295, NULL);
    kk_std_core__list_dup(x);
    kk_std_core_types__maybe_drop(_match_7539, _ctx);
    y = x; /*list<effects-and-types/row_vector>*/
  }
  kk_unit_t __w_l717_c9 = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(y, _ctx);
    kk_box_t _x7807 = kk_std_core_hnd_yield_cont(kk_climate_dash_experiments__new_mlift5635_run__climate__model_fun7808(i_5717, _ctx), _ctx); /*3*/
    x0_5714 = kk_std_core__list_unbox(_x7807, _ctx); /*list<effects-and-types/row_vector>*/
  }
  else {
    x0_5714 = y; /*list<effects-and-types/row_vector>*/
  }
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x0_5714, _ctx);
    kk_box_t _x7809 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments__new_mlift5635_run__climate__model_fun7810(data, ind1, name1, pt, repeat__ind, rs, sbrs, diff1, subtract1, _ctx), _ctx); /*2*/
    kk_unit_unbox(_x7809);
  }
  else {
    kk_climate_dash_experiments__mlift5630_run__climate__model(data, diff1, ind1, name1, pt, repeat__ind, rs, sbrs, subtract1, x0_5714, _ctx);
  }
  return kk_unit_box(_x7789);
}
static kk_unit_t kk_climate_dash_experiments__mlift5635_run__climate__model_fun7781(kk_function_t _fself, kk_integer_t repeat__ind, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5635_run__climate__model_fun7781__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5635_run__climate__model_fun7781__t*, _fself);
  kk_box_t _b_6321 = _self->_b_6321; /* 1 */
  kk_std_core_types__tuple2_ data = _self->data; /* (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>) */
  kk_integer_t pt = _self->pt; /* int */
  kk_integer_t rs = _self->rs; /* int */
  kk_integer_t sbrs = _self->sbrs; /* int */
  kk_drop_match(_self, {kk_box_dup(_b_6321);kk_std_core_types__tuple2__dup(data);kk_integer_dup(pt);kk_integer_dup(rs);kk_integer_dup(sbrs);}, {}, _ctx)
  kk_box_t _x7782;
  kk_std_core_types__tuple2_ _match_7536 = kk_std_core_types__tuple2__unbox(_b_6321, _ctx); /*(int, (double, double, string))*/;
  kk_box_t _box_x6279 = _match_7536.fst;
  kk_box_t _box_x6280 = _match_7536.snd;
  kk_integer_t ind1 = kk_integer_unbox(_box_x6279);
  kk_std_core_types__tuple3_ _pat6 = kk_std_core_types__tuple3__unbox(_box_x6280, NULL);
  kk_box_t _box_x6281 = _pat6.fst;
  kk_box_t _box_x6282 = _pat6.snd;
  kk_box_t _box_x6283 = _pat6.thd;
  double diff1 = kk_double_unbox(_box_x6281, NULL);
  double subtract1 = kk_double_unbox(_box_x6282, NULL);
  kk_string_t name1 = kk_string_unbox(_box_x6283);
  kk_integer_dup(ind1);
  kk_string_dup(name1);
  kk_std_core_types__tuple2__drop(_match_7536, _ctx);
  _x7782 = kk_std_time_timer_print_elapsed(kk_climate_dash_experiments__new_mlift5635_run__climate__model_fun7788(data, ind1, name1, pt, repeat__ind, rs, sbrs, diff1, subtract1, _ctx), kk_std_core_types__new_None(_ctx), _ctx); /*0*/
  return kk_unit_unbox(_x7782);
}
static kk_box_t kk_climate_dash_experiments__mlift5635_run__climate__model_fun7779(kk_function_t _fself, kk_box_t _b_6321, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5635_run__climate__model_fun7779__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5635_run__climate__model_fun7779__t*, _fself);
  kk_std_core_types__tuple2_ data = _self->data; /* (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>) */
  kk_integer_t pt = _self->pt; /* int */
  kk_std_core_types__optional repeat__num = _self->repeat__num; /* optional<int> */
  kk_integer_t rs = _self->rs; /* int */
  kk_integer_t sbrs = _self->sbrs; /* int */
  kk_drop_match(_self, {kk_std_core_types__tuple2__dup(data);kk_integer_dup(pt);kk_std_core_types__optional_dup(repeat__num);kk_integer_dup(rs);kk_integer_dup(sbrs);}, {}, _ctx)
  kk_unit_t _x7780 = kk_Unit;
  kk_integer_t _x7813;
  if (kk_std_core_types__is_Optional(repeat__num)) {
    kk_box_t _box_x6318 = repeat__num._cons.Optional.value;
    kk_integer_t _repeat__num_20 = kk_integer_unbox(_box_x6318);
    kk_integer_dup(_repeat__num_20);
    kk_std_core_types__optional_drop(repeat__num, _ctx);
    _x7813 = _repeat__num_20; /*int*/
    goto _match7814;
  }
  _x7813 = kk_integer_from_small(8); /*int*/
  _match7814: ;
  kk_std_core__lift21056_for(kk_climate_dash_experiments__new_mlift5635_run__climate__model_fun7781(_b_6321, data, pt, rs, sbrs, _ctx), _x7813, kk_integer_from_small(1), _ctx);
  return kk_unit_box(_x7780);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift5635_run__climate__model_fun7817__t {
  struct kk_function_s _base;
};
static kk_box_t kk_climate_dash_experiments__mlift5635_run__climate__model_fun7817(kk_function_t _fself, kk_box_t _b_6330, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5635_run__climate__model_fun7817(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_climate_dash_experiments__mlift5635_run__climate__model_fun7817, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_climate_dash_experiments__mlift5635_run__climate__model_fun7817(kk_function_t _fself, kk_box_t _b_6330, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_unit_t _x7818 = kk_Unit;
  kk_std_core__list _x7819 = kk_std_core__list_unbox(_b_6330, _ctx); /*list<()>*/
  kk_climate_dash_experiments__mlift5631_run__climate__model(_x7819, _ctx);
  return kk_unit_box(_x7818);
}
static kk_box_t kk_climate_dash_experiments__mlift5635_run__climate__model_fun7774(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5635_run__climate__model_fun7774__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5635_run__climate__model_fun7774__t*, _fself);
  kk_std_core_types__tuple2_ data = _self->data; /* (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>) */
  kk_std_core__list pre__data = _self->pre__data; /* list<(double, double, string)> */
  kk_integer_t pt = _self->pt; /* int */
  kk_std_core_types__optional repeat__num = _self->repeat__num; /* optional<int> */
  kk_integer_t rs = _self->rs; /* int */
  kk_integer_t sbrs = _self->sbrs; /* int */
  kk_drop_match(_self, {kk_std_core_types__tuple2__dup(data);kk_std_core__list_dup(pre__data);kk_integer_dup(pt);kk_std_core_types__optional_dup(repeat__num);kk_integer_dup(rs);kk_integer_dup(sbrs);}, {}, _ctx)
  kk_unit_t _x7775 = kk_Unit;
  kk_unit_t __4 = kk_Unit;
  kk_string_t _x7776;
  kk_define_string_literal(, _s7777, 23, "Beginning to start SMC:")
  _x7776 = kk_string_dup(_s7777); /*string*/
  kk_std_core_printsln(_x7776, _ctx);
  kk_std_core__list x_5707;
  kk_std_core__list _b_6322_6319;
  kk_std_core__list _x7778 = kk_std_core__lift21053_list(kk_integer_from_small(0), kk_integer_from_small(11), kk_std_core__new_Nil(_ctx), _ctx); /*list<int>*/
  _b_6322_6319 = kk_std_core_zip(_x7778, pre__data, _ctx); /*list<(int, (double, double, string))>*/
  x_5707 = kk_std_core_map_5(_b_6322_6319, kk_climate_dash_experiments__new_mlift5635_run__climate__model_fun7779(data, pt, repeat__num, rs, sbrs, _ctx), _ctx); /*list<()>*/
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_5707, _ctx);
    kk_box_t _x7816 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments__new_mlift5635_run__climate__model_fun7817(_ctx), _ctx); /*2*/
    kk_unit_unbox(_x7816);
  }
  else {
    kk_climate_dash_experiments__mlift5631_run__climate__model(x_5707, _ctx);
  }
  return kk_unit_box(_x7775);
}

kk_unit_t kk_climate_dash_experiments__mlift5635_run__climate__model(kk_std_core_types__tuple2_ data, kk_std_core__list pre__data, kk_integer_t pt, kk_std_core_types__optional repeat__num, kk_integer_t rs, kk_integer_t sbrs, kk_std_core__list wild__3, kk_context_t* _ctx) { /* (data : (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>), pre_data : list<(double, double, string)>, pt : int, repeat_num : optional<int>, rs : int, sbrs : int, wild_3 : list<()>) -> <ndet,console,div,exn,fsys,std/num/random/random> () */ 
  kk_std_core__list_drop(wild__3, _ctx);
  kk_box_t _x7773 = kk_std_time_timer_print_elapsed(kk_climate_dash_experiments__new_mlift5635_run__climate__model_fun7774(data, pre__data, pt, repeat__num, rs, sbrs, _ctx), kk_std_core_types__new_None(_ctx), _ctx); /*0*/
  kk_unit_unbox(_x7773); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_climate_dash_experiments__mlift5636_run__climate__model_fun7830__t {
  struct kk_function_s _base;
};
static kk_box_t kk_climate_dash_experiments__mlift5636_run__climate__model_fun7830(kk_function_t _fself, kk_box_t _b_6338, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5636_run__climate__model_fun7830(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_climate_dash_experiments__mlift5636_run__climate__model_fun7830, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_climate_dash_experiments__mlift5636_run__climate__model_fun7830(kk_function_t _fself, kk_box_t _b_6338, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_os_path__path _x7831;
  kk_string_t _x7832 = kk_string_unbox(_b_6338); /*string*/
  _x7831 = kk_std_os_path_path(_x7832, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x7831, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift5636_run__climate__model_fun7835__t {
  struct kk_function_s _base;
};
static kk_box_t kk_climate_dash_experiments__mlift5636_run__climate__model_fun7835(kk_function_t _fself, kk_box_t _b_6343, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5636_run__climate__model_fun7835(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_climate_dash_experiments__mlift5636_run__climate__model_fun7835, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_climate_dash_experiments__mlift5636_run__climate__model_fun7835(kk_function_t _fself, kk_box_t _b_6343, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x7836;
  kk_std_core__list _x7837 = kk_std_core__list_unbox(_b_6343, _ctx); /*list<(list<double>, list<double>)>*/
  _x7836 = kk_output_dash_and_dash_plot_show__trace(_x7837, _ctx); /*string*/
  return kk_string_box(_x7836);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift5636_run__climate__model_fun7843__t {
  struct kk_function_s _base;
  size_t i_5722;
};
static kk_box_t kk_climate_dash_experiments__mlift5636_run__climate__model_fun7843(kk_function_t _fself, kk_function_t _b_6353, kk_box_t _b_6354, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5636_run__climate__model_fun7843(size_t i_5722, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5636_run__climate__model_fun7843__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5636_run__climate__model_fun7843__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5636_run__climate__model_fun7843, kk_context());
  _self->i_5722 = i_5722;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift5636_run__climate__model_fun7843(kk_function_t _fself, kk_function_t _b_6353, kk_box_t _b_6354, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5636_run__climate__model_fun7843__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5636_run__climate__model_fun7843__t*, _fself);
  size_t i_5722 = _self->i_5722; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_5722, _b_6353, _b_6354, _ctx);
}

kk_unit_t kk_climate_dash_experiments__mlift5636_run__climate__model(kk_string_t name, kk_std_core_types__tuple2_ _y_3, kk_context_t* _ctx) { /* (name : string, (list<(list<double>, list<double>)>, tmcmc/trace<list<double>,<effects-and-types/sample,effects-and-types/score,div,exn,fsys,console,ndet,std/num/random/random>>)) -> <effects-and-types/sample,div,exn,fsys,console,ndet,std/num/random/random> () */ 
  kk_string_t _x24;
  kk_string_t _x7820;
  kk_define_string_literal(, _s7821, 17, "./output-climate/")
  _x7820 = kk_string_dup(_s7821); /*string*/
  kk_string_t _x7822;
  kk_string_t _x7823;
  kk_string_t _x7824;
  kk_define_string_literal(, _s7825, 1, "/")
  _x7824 = kk_string_dup(_s7825); /*string*/
  kk_string_t _x7826;
  kk_define_string_literal(, _s7827, 17, "tmcmc_results.csv")
  _x7826 = kk_string_dup(_s7827); /*string*/
  _x7823 = kk_std_core__lp__plus__plus__1_rp_(_x7824, _x7826, _ctx); /*string*/
  _x7822 = kk_std_core__lp__plus__plus__1_rp_(name, _x7823, _ctx); /*string*/
  _x24 = kk_std_core__lp__plus__plus__1_rp_(_x7820, _x7822, _ctx); /*string*/
  size_t i_5722 = ((size_t)0); /*std/core/hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_5722,kk_context()); /*std/core/hnd/evv<<exn,fsys,div,effects-and-types/sample,console,ndet,std/num/random/random>>*/;
  kk_unit_t y = kk_Unit;
  kk_std_os_path__path _x7828;
  kk_box_t _x7829 = kk_std_core_hnd__open_none1(kk_climate_dash_experiments__new_mlift5636_run__climate__model_fun7830(_ctx), kk_string_box(_x24), _ctx); /*2*/
  _x7828 = kk_std_os_path__path_unbox(_x7829, _ctx); /*std/os/path/path*/
  kk_string_t _x7833;
  kk_box_t _x7834;
  kk_box_t _x7838;
  kk_std_core__list _x7839;
  kk_box_t _box_x6339 = _y_3.fst;
  kk_box_t _box_x6340 = _y_3.snd;
  kk_std_core__list _x = kk_std_core__list_unbox(_box_x6339, NULL);
  kk_std_core__list_dup(_x);
  kk_std_core_types__tuple2__drop(_y_3, _ctx);
  _x7839 = _x; /*list<(list<double>, list<double>)>*/
  _x7838 = kk_std_core__list_box(_x7839, _ctx); /*1*/
  _x7834 = kk_std_core_hnd__open_none1(kk_climate_dash_experiments__new_mlift5636_run__climate__model_fun7835(_ctx), _x7838, _ctx); /*2*/
  _x7833 = kk_string_unbox(_x7834); /*string*/
  kk_std_os_file_write_text_file(_x7828, _x7833, kk_std_core_types__new_None(_ctx), _ctx);
  kk_unit_t __w_l717_c9 = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x7842 = kk_std_core_hnd_yield_cont(kk_climate_dash_experiments__new_mlift5636_run__climate__model_fun7843(i_5722, _ctx), _ctx); /*3*/
    kk_unit_unbox(_x7842); return kk_Unit;
  }
  y; return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_climate_dash_experiments__mlift5637_run__climate__model_fun7862__t {
  struct kk_function_s _base;
  size_t i_5729;
};
static kk_box_t kk_climate_dash_experiments__mlift5637_run__climate__model_fun7862(kk_function_t _fself, kk_function_t _b_6383, kk_box_t _b_6384, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5637_run__climate__model_fun7862(size_t i_5729, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5637_run__climate__model_fun7862__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5637_run__climate__model_fun7862__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5637_run__climate__model_fun7862, kk_context());
  _self->i_5729 = i_5729;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift5637_run__climate__model_fun7862(kk_function_t _fself, kk_function_t _b_6383, kk_box_t _b_6384, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5637_run__climate__model_fun7862__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5637_run__climate__model_fun7862__t*, _fself);
  size_t i_5729 = _self->i_5729; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_5729, _b_6383, _b_6384, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift5637_run__climate__model_fun7880__t {
  struct kk_function_s _base;
  size_t i0_5734;
};
static kk_box_t kk_climate_dash_experiments__mlift5637_run__climate__model_fun7880(kk_function_t _fself, kk_function_t _b_6413, kk_box_t _b_6414, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5637_run__climate__model_fun7880(size_t i0_5734, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5637_run__climate__model_fun7880__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5637_run__climate__model_fun7880__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5637_run__climate__model_fun7880, kk_context());
  _self->i0_5734 = i0_5734;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift5637_run__climate__model_fun7880(kk_function_t _fself, kk_function_t _b_6413, kk_box_t _b_6414, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5637_run__climate__model_fun7880__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5637_run__climate__model_fun7880__t*, _fself);
  size_t i0_5734 = _self->i0_5734; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i0_5734, _b_6413, _b_6414, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift5637_run__climate__model_fun7881__t {
  struct kk_function_s _base;
  kk_function_t _x02_5599;
};
static kk_std_core__list kk_climate_dash_experiments__mlift5637_run__climate__model_fun7881(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5637_run__climate__model_fun7881(kk_function_t _x02_5599, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5637_run__climate__model_fun7881__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5637_run__climate__model_fun7881__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5637_run__climate__model_fun7881, kk_context());
  _self->_x02_5599 = _x02_5599;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift5637_run__climate__model_fun7884__t {
  struct kk_function_s _base;
  kk_function_t _x02_5599;
};
static kk_box_t kk_climate_dash_experiments__mlift5637_run__climate__model_fun7884(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5637_run__climate__model_fun7884(kk_function_t _x02_5599, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5637_run__climate__model_fun7884__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5637_run__climate__model_fun7884__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5637_run__climate__model_fun7884, kk_context());
  _self->_x02_5599 = _x02_5599;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift5637_run__climate__model_fun7884(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5637_run__climate__model_fun7884__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5637_run__climate__model_fun7884__t*, _fself);
  kk_function_t _x02_5599 = _self->_x02_5599; /* effects-and-types/model<list<double>,exn> */
  kk_drop_match(_self, {kk_function_dup(_x02_5599);}, {}, _ctx)
  kk_std_core__list _x7885 = kk_function_call(kk_std_core__list, (kk_function_t, kk_context_t*), _x02_5599, (_x02_5599, _ctx)); /*list<double>*/
  return kk_std_core__list_box(_x7885, _ctx);
}
static kk_std_core__list kk_climate_dash_experiments__mlift5637_run__climate__model_fun7881(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5637_run__climate__model_fun7881__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5637_run__climate__model_fun7881__t*, _fself);
  kk_function_t _x02_5599 = _self->_x02_5599; /* effects-and-types/model<list<double>,exn> */
  kk_drop_match(_self, {kk_function_dup(_x02_5599);}, {}, _ctx)
  kk_vector_t _b_6439_6429;
  kk_std_core__list _x7882;
  size_t _b_6441_6427 = ((size_t)0); /*std/core/hnd/ev-index*/;
  kk_std_core__list _b_6442_6428;
  size_t _b_6443_6425 = ((size_t)2); /*std/core/hnd/ev-index*/;
  kk_std_core__list _b_6444_6426;
  size_t _b_6445_6423 = ((size_t)3); /*std/core/hnd/ev-index*/;
  _b_6444_6426 = kk_std_core__new_Cons(kk_reuse_null, kk_size_box(_b_6445_6423, _ctx), kk_std_core__new_Nil(_ctx), _ctx); /*list<std/core/hnd/ev-index>*/
  _b_6442_6428 = kk_std_core__new_Cons(kk_reuse_null, kk_size_box(_b_6443_6425, _ctx), _b_6444_6426, _ctx); /*list<std/core/hnd/ev-index>*/
  _x7882 = kk_std_core__new_Cons(kk_reuse_null, kk_size_box(_b_6441_6427, _ctx), _b_6442_6428, _ctx); /*list<0>*/
  _b_6439_6429 = kk_std_core_unvlist(_x7882, _ctx); /*vector<std/core/hnd/ev-index>*/
  kk_box_t _x7883 = kk_std_core_hnd__open0(_b_6439_6429, kk_climate_dash_experiments__new_mlift5637_run__climate__model_fun7884(_x02_5599, _ctx), _ctx); /*1*/
  return kk_std_core__list_unbox(_x7883, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift5637_run__climate__model_fun7886__t {
  struct kk_function_s _base;
  kk_function_t _b_6435_6431;
};
static kk_box_t kk_climate_dash_experiments__mlift5637_run__climate__model_fun7886(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5637_run__climate__model_fun7886(kk_function_t _b_6435_6431, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5637_run__climate__model_fun7886__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5637_run__climate__model_fun7886__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5637_run__climate__model_fun7886, kk_context());
  _self->_b_6435_6431 = _b_6435_6431;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift5637_run__climate__model_fun7886(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5637_run__climate__model_fun7886__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5637_run__climate__model_fun7886__t*, _fself);
  kk_function_t _b_6435_6431 = _self->_b_6435_6431; /* () -> <exn,effects-and-types/sample,effects-and-types/score> list<double> */
  kk_drop_match(_self, {kk_function_dup(_b_6435_6431);}, {}, _ctx)
  kk_std_core__list _x7887 = kk_function_call(kk_std_core__list, (kk_function_t, kk_context_t*), _b_6435_6431, (_b_6435_6431, _ctx)); /*list<double>*/
  return kk_std_core__list_box(_x7887, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift5637_run__climate__model_fun7889__t {
  struct kk_function_s _base;
  kk_string_t name;
};
static kk_box_t kk_climate_dash_experiments__mlift5637_run__climate__model_fun7889(kk_function_t _fself, kk_box_t _b_6448, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5637_run__climate__model_fun7889(kk_string_t name, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5637_run__climate__model_fun7889__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5637_run__climate__model_fun7889__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5637_run__climate__model_fun7889, kk_context());
  _self->name = name;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift5637_run__climate__model_fun7889(kk_function_t _fself, kk_box_t _b_6448, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5637_run__climate__model_fun7889__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5637_run__climate__model_fun7889__t*, _fself);
  kk_string_t name = _self->name; /* string */
  kk_drop_match(_self, {kk_string_dup(name);}, {}, _ctx)
  kk_unit_t _x7890 = kk_Unit;
  kk_std_core_types__tuple2_ _x7891 = kk_std_core_types__tuple2__unbox(_b_6448, _ctx); /*(list<(list<double>, list<double>)>, tmcmc/trace<list<double>,<effects-and-types/sample,effects-and-types/score,div,exn,fsys,console,ndet,std/num/random/random>>)*/
  kk_climate_dash_experiments__mlift5636_run__climate__model(name, _x7891, _ctx);
  return kk_unit_box(_x7890);
}

kk_unit_t kk_climate_dash_experiments__mlift5637_run__climate__model(kk_integer_t burnin, kk_std_core_types__tuple2_ data, double diff, kk_integer_t ind, kk_string_t name, double subtract, kk_integer_t t__steps, kk_std_core__list _y_2, kk_context_t* _ctx) { /* (burnin : int, data : (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>), diff : double, ind : int, name : string, subtract : double, t_steps : int, list<effects-and-types/row_vector>) -> <exn,div,effects-and-types/sample,fsys,console,ndet,std/num/random/random> () */ 
  kk_std_core__list_drop(_y_2, _ctx);
  kk_std_core_types__tuple2_ x_5726;
  kk_function_t _b_6435_6431;
  kk_function_t _x02_5599;
  kk_std_core__list _x11;
  size_t i_5729 = ((size_t)0); /*std/core/hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_5729,kk_context()); /*std/core/hnd/evv<<exn,div,effects-and-types/sample,fsys,console,ndet,std/num/random/random>>*/;
  kk_std_core__list y;
  kk_std_core_types__maybe _match_7531;
  kk_std_core__list _x7844;
  kk_box_t _box_x6363 = data.fst;
  kk_box_t _box_x6364 = data.snd;
  kk_std_core__list _x = kk_std_core__list_unbox(_box_x6364, NULL);
  kk_std_core__list_dup(_x);
  _x7844 = _x; /*list<list<effects-and-types/row_vector>>*/
  kk_integer_t _x7847 = kk_integer_dup(ind); /*int*/
  _match_7531 = kk_std_core__lp__lb__rb__2_rp_(_x7844, _x7847, _ctx); /*maybe<1>*/
  if (kk_std_core_types__is_Nothing(_match_7531)) {
    kk_string_t message_205;
    kk_string_t _x7848;
    kk_define_string_literal(, _s7849, 48, "ListIndexError: Invalid list indexing at index: ")
    _x7848 = kk_string_dup(_s7849); /*string*/
    kk_string_t _x7850;
    kk_integer_t _x7851 = kk_integer_dup(ind); /*int*/
    _x7850 = kk_std_core_show(_x7851, _ctx); /*string*/
    message_205 = kk_std_core__lp__plus__plus__1_rp_(_x7848, _x7850, _ctx); /*string*/
    kk_std_core__exception exn_21561;
    kk_std_core__exception_info _x7852;
    kk_std_core_types__optional _match_7533 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
    if (kk_std_core_types__is_Optional(_match_7533)) {
      kk_box_t _box_x6365 = _match_7533._cons.Optional.value;
      kk_std_core__exception_info _info_14279 = kk_std_core__exception_info_unbox(_box_x6365, NULL);
      kk_std_core__exception_info_dup(_info_14279);
      kk_std_core_types__optional_drop(_match_7533, _ctx);
      _x7852 = _info_14279; /*exception-info*/
      goto _match7853;
    }
    _x7852 = kk_std_core__new_ExnError(_ctx); /*exception-info*/
    _match7853: ;
    exn_21561 = kk_std_core__new_Exception(message_205, _x7852, _ctx); /*exception*/
    kk_std_core_hnd__ev ev_21562;
    size_t _x7855 = ((size_t)0); /*size_t*/
    ev_21562 = kk_evv_at(_x7855,kk_context()); /*std/core/hnd/ev<.hnd-exn>*/
    kk_box_t _x7856;
    struct kk_std_core_hnd_Ev* _con7857 = kk_std_core_hnd__as_Ev(ev_21562);
    kk_std_core_hnd__marker m = _con7857->marker;
    kk_box_t _box_x6366 = _con7857->hnd;
    kk_std_core__hnd_exn h = kk_std_core__hnd_exn_unbox(_box_x6366, NULL);
    kk_std_core__hnd_exn_dup(h);
    kk_std_core_hnd__clause1 _match_7532;
    struct kk_std_core__Hnd_exn* _con7859 = kk_std_core__as_Hnd_exn(h);
    kk_std_core_hnd__clause1 except_throw_exn = _con7859->except_throw_exn;
    if (kk_std_core__hnd_exn_is_unique(h)) {
      kk_std_core__hnd_exn_free(h);
    }
    else {
      kk_std_core_hnd__clause1_dup(except_throw_exn);
      kk_std_core__hnd_exn_decref(h, _ctx);
    }
    _match_7532 = except_throw_exn; /*forall<a> std/core/hnd/clause1<exception,a,.hnd-exn,7,8>*/
    kk_function_t _fun_unbox_x6370 = _match_7532.clause;
    _x7856 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x6370, (_fun_unbox_x6370, m, ev_21562, kk_std_core__exception_box(exn_21561, _ctx), _ctx)); /*11*/
    y = kk_std_core__list_unbox(_x7856, _ctx); /*list<effects-and-types/row_vector>*/
  }
  else {
    kk_box_t _box_x6374 = _match_7531._cons.Just.value;
    kk_std_core__list x = kk_std_core__list_unbox(_box_x6374, NULL);
    kk_std_core__list_dup(x);
    kk_std_core_types__maybe_drop(_match_7531, _ctx);
    y = x; /*list<effects-and-types/row_vector>*/
  }
  kk_unit_t __w_l717_c9 = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(y, _ctx);
    kk_box_t _x7861 = kk_std_core_hnd_yield_cont(kk_climate_dash_experiments__new_mlift5637_run__climate__model_fun7862(i_5729, _ctx), _ctx); /*3*/
    _x11 = kk_std_core__list_unbox(_x7861, _ctx); /*list<effects-and-types/row_vector>*/
  }
  else {
    _x11 = y; /*list<effects-and-types/row_vector>*/
  }
  kk_std_core__list _x21;
  size_t i0_5734 = ((size_t)0); /*std/core/hnd/ev-index*/;
  kk_evv_t w0 = kk_evv_swap_create1(i0_5734,kk_context()); /*std/core/hnd/evv<<exn,div,effects-and-types/sample,fsys,console,ndet,std/num/random/random>>*/;
  kk_std_core__list y0;
  kk_std_core_types__maybe _match_7527;
  kk_std_core__list _x7863;
  kk_box_t _box_x6393 = data.fst;
  kk_box_t _box_x6394 = data.snd;
  kk_std_core__list _x0 = kk_std_core__list_unbox(_box_x6393, NULL);
  kk_std_core__list_dup(_x0);
  kk_std_core_types__tuple2__drop(data, _ctx);
  _x7863 = _x0; /*list<list<effects-and-types/row_vector>>*/
  kk_integer_t _x7866 = kk_integer_dup(ind); /*int*/
  _match_7527 = kk_std_core__lp__lb__rb__2_rp_(_x7863, _x7866, _ctx); /*maybe<1>*/
  if (kk_std_core_types__is_Nothing(_match_7527)) {
    kk_string_t message_2050;
    kk_string_t _x7867;
    kk_define_string_literal(, _s7868, 48, "ListIndexError: Invalid list indexing at index: ")
    _x7867 = kk_string_dup(_s7868); /*string*/
    kk_string_t _x7869 = kk_std_core_show(ind, _ctx); /*string*/
    message_2050 = kk_std_core__lp__plus__plus__1_rp_(_x7867, _x7869, _ctx); /*string*/
    kk_std_core__exception exn_215610;
    kk_std_core__exception_info _x7870;
    kk_std_core_types__optional _match_7529 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
    if (kk_std_core_types__is_Optional(_match_7529)) {
      kk_box_t _box_x6395 = _match_7529._cons.Optional.value;
      kk_std_core__exception_info _info_142790 = kk_std_core__exception_info_unbox(_box_x6395, NULL);
      kk_std_core__exception_info_dup(_info_142790);
      kk_std_core_types__optional_drop(_match_7529, _ctx);
      _x7870 = _info_142790; /*exception-info*/
      goto _match7871;
    }
    _x7870 = kk_std_core__new_ExnError(_ctx); /*exception-info*/
    _match7871: ;
    exn_215610 = kk_std_core__new_Exception(message_2050, _x7870, _ctx); /*exception*/
    kk_std_core_hnd__ev ev_215620;
    size_t _x7873 = ((size_t)0); /*size_t*/
    ev_215620 = kk_evv_at(_x7873,kk_context()); /*std/core/hnd/ev<.hnd-exn>*/
    kk_box_t _x7874;
    struct kk_std_core_hnd_Ev* _con7875 = kk_std_core_hnd__as_Ev(ev_215620);
    kk_std_core_hnd__marker m0 = _con7875->marker;
    kk_box_t _box_x6396 = _con7875->hnd;
    kk_std_core__hnd_exn h0 = kk_std_core__hnd_exn_unbox(_box_x6396, NULL);
    kk_std_core__hnd_exn_dup(h0);
    kk_std_core_hnd__clause1 _match_7528;
    struct kk_std_core__Hnd_exn* _con7877 = kk_std_core__as_Hnd_exn(h0);
    kk_std_core_hnd__clause1 except_throw_exn0 = _con7877->except_throw_exn;
    if (kk_std_core__hnd_exn_is_unique(h0)) {
      kk_std_core__hnd_exn_free(h0);
    }
    else {
      kk_std_core_hnd__clause1_dup(except_throw_exn0);
      kk_std_core__hnd_exn_decref(h0, _ctx);
    }
    _match_7528 = except_throw_exn0; /*forall<a> std/core/hnd/clause1<exception,a,.hnd-exn,7,8>*/
    kk_function_t _fun_unbox_x6400 = _match_7528.clause;
    _x7874 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x6400, (_fun_unbox_x6400, m0, ev_215620, kk_std_core__exception_box(exn_215610, _ctx), _ctx)); /*11*/
    y0 = kk_std_core__list_unbox(_x7874, _ctx); /*list<effects-and-types/row_vector>*/
  }
  else {
    kk_box_t _box_x6404 = _match_7527._cons.Just.value;
    kk_std_core__list x0 = kk_std_core__list_unbox(_box_x6404, NULL);
    kk_integer_drop(ind, _ctx);
    kk_std_core__list_dup(x0);
    kk_std_core_types__maybe_drop(_match_7527, _ctx);
    y0 = x0; /*list<effects-and-types/row_vector>*/
  }
  kk_unit_t __w_l717_c90 = kk_Unit;
  kk_evv_set(w0,kk_context());
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(y0, _ctx);
    kk_box_t _x7879 = kk_std_core_hnd_yield_cont(kk_climate_dash_experiments__new_mlift5637_run__climate__model_fun7880(i0_5734, _ctx), _ctx); /*3*/
    _x21 = kk_std_core__list_unbox(_x7879, _ctx); /*list<effects-and-types/row_vector>*/
  }
  else {
    _x21 = y0; /*list<effects-and-types/row_vector>*/
  }
  kk_evv_t w1 = kk_evv_swap_create0(kk_context()); /*std/core/hnd/evv<(<>)>*/;
  kk_function_t x00 = kk_climate_dash_change_linear__gaussian__climate__data(_x11, _x21, false, diff, subtract, 0x1.2cccccccccccdp2, _ctx); /*effects-and-types/model<list<double>,exn>*/;
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w1,kk_context());
  _x02_5599 = x00; /*effects-and-types/model<list<double>,exn>*/
  _b_6435_6431 = kk_climate_dash_experiments__new_mlift5637_run__climate__model_fun7881(_x02_5599, _ctx); /*() -> <exn,effects-and-types/sample,effects-and-types/score> list<double>*/
  kk_effects_dash_and_dash_types__exp _b_6437_6433 = kk_effects_dash_and_dash_types__new_Exp(0x0p+0, _ctx); /*effects-and-types/exp*/;
  x_5726 = kk_tmcmc_tmcmc(kk_climate_dash_experiments__new_mlift5637_run__climate__model_fun7886(_b_6435_6431, _ctx), t__steps, _b_6437_6433, burnin, _ctx); /*(list<(list<double>, list<double>)>, tmcmc/trace<list<double>,<effects-and-types/sample,effects-and-types/score,div,exn,fsys,console,ndet,std/num/random/random>>)*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__tuple2__drop(x_5726, _ctx);
    kk_box_t _x7888 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments__new_mlift5637_run__climate__model_fun7889(name, _ctx), _ctx); /*2*/
    kk_unit_unbox(_x7888); return kk_Unit;
  }
  kk_climate_dash_experiments__mlift5636_run__climate__model(name, x_5726, _ctx); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_climate_dash_experiments__mlift5638_run__climate__model_fun7910__t {
  struct kk_function_s _base;
  size_t i_5742;
};
static kk_box_t kk_climate_dash_experiments__mlift5638_run__climate__model_fun7910(kk_function_t _fself, kk_function_t _b_6471, kk_box_t _b_6472, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5638_run__climate__model_fun7910(size_t i_5742, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5638_run__climate__model_fun7910__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5638_run__climate__model_fun7910__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5638_run__climate__model_fun7910, kk_context());
  _self->i_5742 = i_5742;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift5638_run__climate__model_fun7910(kk_function_t _fself, kk_function_t _b_6471, kk_box_t _b_6472, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5638_run__climate__model_fun7910__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5638_run__climate__model_fun7910__t*, _fself);
  size_t i_5742 = _self->i_5742; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_5742, _b_6471, _b_6472, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift5638_run__climate__model_fun7912__t {
  struct kk_function_s _base;
  kk_integer_t burnin;
  kk_std_core_types__tuple2_ data;
  kk_integer_t ind;
  kk_string_t name;
  kk_integer_t t__steps;
  double diff;
  double subtract;
};
static kk_box_t kk_climate_dash_experiments__mlift5638_run__climate__model_fun7912(kk_function_t _fself, kk_box_t _b_6482, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5638_run__climate__model_fun7912(kk_integer_t burnin, kk_std_core_types__tuple2_ data, kk_integer_t ind, kk_string_t name, kk_integer_t t__steps, double diff, double subtract, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5638_run__climate__model_fun7912__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5638_run__climate__model_fun7912__t, 7, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5638_run__climate__model_fun7912, kk_context());
  _self->burnin = burnin;
  _self->data = data;
  _self->ind = ind;
  _self->name = name;
  _self->t__steps = t__steps;
  _self->diff = diff;
  _self->subtract = subtract;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift5638_run__climate__model_fun7912(kk_function_t _fself, kk_box_t _b_6482, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5638_run__climate__model_fun7912__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5638_run__climate__model_fun7912__t*, _fself);
  kk_integer_t burnin = _self->burnin; /* int */
  kk_std_core_types__tuple2_ data = _self->data; /* (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>) */
  kk_integer_t ind = _self->ind; /* int */
  kk_string_t name = _self->name; /* string */
  kk_integer_t t__steps = _self->t__steps; /* int */
  double diff = _self->diff; /* double */
  double subtract = _self->subtract; /* double */
  kk_drop_match(_self, {kk_integer_dup(burnin);kk_std_core_types__tuple2__dup(data);kk_integer_dup(ind);kk_string_dup(name);kk_integer_dup(t__steps);;;}, {}, _ctx)
  kk_unit_t _x7913 = kk_Unit;
  kk_std_core__list _x7914 = kk_std_core__list_unbox(_b_6482, _ctx); /*list<effects-and-types/row_vector>*/
  kk_climate_dash_experiments__mlift5637_run__climate__model(burnin, data, diff, ind, name, subtract, t__steps, _x7914, _ctx);
  return kk_unit_box(_x7913);
}

kk_unit_t kk_climate_dash_experiments__mlift5638_run__climate__model(kk_integer_t burnin, kk_std_core_types__tuple2_ data, double diff, kk_integer_t ind, kk_string_t name, double subtract, kk_integer_t t__steps, kk_std_core__list _y_1, kk_context_t* _ctx) { /* (burnin : int, data : (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>), diff : double, ind : int, name : string, subtract : double, t_steps : int, list<effects-and-types/row_vector>) -> <exn,div,effects-and-types/sample,fsys,console,ndet,std/num/random/random> () */ 
  kk_std_core__list_drop(_y_1, _ctx);
  kk_std_core__list x_5739;
  size_t i_5742 = ((size_t)0); /*std/core/hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_5742,kk_context()); /*std/core/hnd/evv<<exn,div,effects-and-types/sample,fsys,console,ndet,std/num/random/random>>*/;
  kk_std_core__list y;
  kk_std_core_types__maybe _match_7522;
  kk_std_core__list _x7892;
  kk_box_t _box_x6451 = data.fst;
  kk_box_t _box_x6452 = data.snd;
  kk_std_core__list _x = kk_std_core__list_unbox(_box_x6451, NULL);
  kk_std_core__list_dup(_x);
  _x7892 = _x; /*list<list<effects-and-types/row_vector>>*/
  kk_integer_t _x7895 = kk_integer_dup(ind); /*int*/
  _match_7522 = kk_std_core__lp__lb__rb__2_rp_(_x7892, _x7895, _ctx); /*maybe<1>*/
  if (kk_std_core_types__is_Nothing(_match_7522)) {
    kk_string_t message_205;
    kk_string_t _x7896;
    kk_define_string_literal(, _s7897, 48, "ListIndexError: Invalid list indexing at index: ")
    _x7896 = kk_string_dup(_s7897); /*string*/
    kk_string_t _x7898;
    kk_integer_t _x7899 = kk_integer_dup(ind); /*int*/
    _x7898 = kk_std_core_show(_x7899, _ctx); /*string*/
    message_205 = kk_std_core__lp__plus__plus__1_rp_(_x7896, _x7898, _ctx); /*string*/
    kk_std_core__exception exn_21561;
    kk_std_core__exception_info _x7900;
    kk_std_core_types__optional _match_7524 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
    if (kk_std_core_types__is_Optional(_match_7524)) {
      kk_box_t _box_x6453 = _match_7524._cons.Optional.value;
      kk_std_core__exception_info _info_14279 = kk_std_core__exception_info_unbox(_box_x6453, NULL);
      kk_std_core__exception_info_dup(_info_14279);
      kk_std_core_types__optional_drop(_match_7524, _ctx);
      _x7900 = _info_14279; /*exception-info*/
      goto _match7901;
    }
    _x7900 = kk_std_core__new_ExnError(_ctx); /*exception-info*/
    _match7901: ;
    exn_21561 = kk_std_core__new_Exception(message_205, _x7900, _ctx); /*exception*/
    kk_std_core_hnd__ev ev_21562;
    size_t _x7903 = ((size_t)0); /*size_t*/
    ev_21562 = kk_evv_at(_x7903,kk_context()); /*std/core/hnd/ev<.hnd-exn>*/
    kk_box_t _x7904;
    struct kk_std_core_hnd_Ev* _con7905 = kk_std_core_hnd__as_Ev(ev_21562);
    kk_std_core_hnd__marker m = _con7905->marker;
    kk_box_t _box_x6454 = _con7905->hnd;
    kk_std_core__hnd_exn h = kk_std_core__hnd_exn_unbox(_box_x6454, NULL);
    kk_std_core__hnd_exn_dup(h);
    kk_std_core_hnd__clause1 _match_7523;
    struct kk_std_core__Hnd_exn* _con7907 = kk_std_core__as_Hnd_exn(h);
    kk_std_core_hnd__clause1 except_throw_exn = _con7907->except_throw_exn;
    if (kk_std_core__hnd_exn_is_unique(h)) {
      kk_std_core__hnd_exn_free(h);
    }
    else {
      kk_std_core_hnd__clause1_dup(except_throw_exn);
      kk_std_core__hnd_exn_decref(h, _ctx);
    }
    _match_7523 = except_throw_exn; /*forall<a> std/core/hnd/clause1<exception,a,.hnd-exn,7,8>*/
    kk_function_t _fun_unbox_x6458 = _match_7523.clause;
    _x7904 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x6458, (_fun_unbox_x6458, m, ev_21562, kk_std_core__exception_box(exn_21561, _ctx), _ctx)); /*11*/
    y = kk_std_core__list_unbox(_x7904, _ctx); /*list<effects-and-types/row_vector>*/
  }
  else {
    kk_box_t _box_x6462 = _match_7522._cons.Just.value;
    kk_std_core__list x = kk_std_core__list_unbox(_box_x6462, NULL);
    kk_std_core__list_dup(x);
    kk_std_core_types__maybe_drop(_match_7522, _ctx);
    y = x; /*list<effects-and-types/row_vector>*/
  }
  kk_unit_t __w_l717_c9 = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(y, _ctx);
    kk_box_t _x7909 = kk_std_core_hnd_yield_cont(kk_climate_dash_experiments__new_mlift5638_run__climate__model_fun7910(i_5742, _ctx), _ctx); /*3*/
    x_5739 = kk_std_core__list_unbox(_x7909, _ctx); /*list<effects-and-types/row_vector>*/
  }
  else {
    x_5739 = y; /*list<effects-and-types/row_vector>*/
  }
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_5739, _ctx);
    kk_box_t _x7911 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments__new_mlift5638_run__climate__model_fun7912(burnin, data, ind, name, t__steps, diff, subtract, _ctx), _ctx); /*2*/
    kk_unit_unbox(_x7911); return kk_Unit;
  }
  kk_climate_dash_experiments__mlift5637_run__climate__model(burnin, data, diff, ind, name, subtract, t__steps, x_5739, _ctx); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_climate_dash_experiments__mlift5639_run__climate__model_fun7919__t {
  struct kk_function_s _base;
  kk_integer_t burnin;
  kk_std_core_types__tuple2_ data;
  kk_std_core__list pre__data;
  kk_integer_t t__steps;
};
static kk_box_t kk_climate_dash_experiments__mlift5639_run__climate__model_fun7919(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5639_run__climate__model_fun7919(kk_integer_t burnin, kk_std_core_types__tuple2_ data, kk_std_core__list pre__data, kk_integer_t t__steps, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5639_run__climate__model_fun7919__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5639_run__climate__model_fun7919__t, 6, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5639_run__climate__model_fun7919, kk_context());
  _self->burnin = burnin;
  _self->data = data;
  _self->pre__data = pre__data;
  _self->t__steps = t__steps;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift5639_run__climate__model_fun7920__t {
  struct kk_function_s _base;
  kk_integer_t burnin;
  kk_std_core_types__tuple2_ data;
  kk_std_core__list pre__data;
  kk_integer_t t__steps;
};
static kk_box_t kk_climate_dash_experiments__mlift5639_run__climate__model_fun7920(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5639_run__climate__model_fun7920(kk_integer_t burnin, kk_std_core_types__tuple2_ data, kk_std_core__list pre__data, kk_integer_t t__steps, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5639_run__climate__model_fun7920__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5639_run__climate__model_fun7920__t, 6, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5639_run__climate__model_fun7920, kk_context());
  _self->burnin = burnin;
  _self->data = data;
  _self->pre__data = pre__data;
  _self->t__steps = t__steps;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift5639_run__climate__model_fun7923__t {
  struct kk_function_s _base;
  kk_integer_t burnin;
  kk_std_core_types__tuple2_ data;
  kk_integer_t t__steps;
};
static kk_box_t kk_climate_dash_experiments__mlift5639_run__climate__model_fun7923(kk_function_t _fself, kk_box_t _b_6526, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5639_run__climate__model_fun7923(kk_integer_t burnin, kk_std_core_types__tuple2_ data, kk_integer_t t__steps, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5639_run__climate__model_fun7923__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5639_run__climate__model_fun7923__t, 5, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5639_run__climate__model_fun7923, kk_context());
  _self->burnin = burnin;
  _self->data = data;
  _self->t__steps = t__steps;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift5639_run__climate__model_fun7929__t {
  struct kk_function_s _base;
  kk_integer_t burnin;
  kk_std_core_types__tuple2_ data;
  kk_integer_t ind0;
  kk_string_t name0;
  kk_integer_t t__steps;
  double diff0;
  double subtract0;
};
static kk_box_t kk_climate_dash_experiments__mlift5639_run__climate__model_fun7929(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5639_run__climate__model_fun7929(kk_integer_t burnin, kk_std_core_types__tuple2_ data, kk_integer_t ind0, kk_string_t name0, kk_integer_t t__steps, double diff0, double subtract0, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5639_run__climate__model_fun7929__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5639_run__climate__model_fun7929__t, 7, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5639_run__climate__model_fun7929, kk_context());
  _self->burnin = burnin;
  _self->data = data;
  _self->ind0 = ind0;
  _self->name0 = name0;
  _self->t__steps = t__steps;
  _self->diff0 = diff0;
  _self->subtract0 = subtract0;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift5639_run__climate__model_fun7949__t {
  struct kk_function_s _base;
  size_t i_5754;
};
static kk_box_t kk_climate_dash_experiments__mlift5639_run__climate__model_fun7949(kk_function_t _fself, kk_function_t _b_6510, kk_box_t _b_6511, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5639_run__climate__model_fun7949(size_t i_5754, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5639_run__climate__model_fun7949__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5639_run__climate__model_fun7949__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5639_run__climate__model_fun7949, kk_context());
  _self->i_5754 = i_5754;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift5639_run__climate__model_fun7949(kk_function_t _fself, kk_function_t _b_6510, kk_box_t _b_6511, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5639_run__climate__model_fun7949__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5639_run__climate__model_fun7949__t*, _fself);
  size_t i_5754 = _self->i_5754; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_5754, _b_6510, _b_6511, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift5639_run__climate__model_fun7951__t {
  struct kk_function_s _base;
  kk_integer_t burnin;
  kk_std_core_types__tuple2_ data;
  kk_integer_t ind0;
  kk_string_t name0;
  kk_integer_t t__steps;
  double diff0;
  double subtract0;
};
static kk_box_t kk_climate_dash_experiments__mlift5639_run__climate__model_fun7951(kk_function_t _fself, kk_box_t _b_6521, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5639_run__climate__model_fun7951(kk_integer_t burnin, kk_std_core_types__tuple2_ data, kk_integer_t ind0, kk_string_t name0, kk_integer_t t__steps, double diff0, double subtract0, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5639_run__climate__model_fun7951__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5639_run__climate__model_fun7951__t, 7, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5639_run__climate__model_fun7951, kk_context());
  _self->burnin = burnin;
  _self->data = data;
  _self->ind0 = ind0;
  _self->name0 = name0;
  _self->t__steps = t__steps;
  _self->diff0 = diff0;
  _self->subtract0 = subtract0;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift5639_run__climate__model_fun7951(kk_function_t _fself, kk_box_t _b_6521, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5639_run__climate__model_fun7951__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5639_run__climate__model_fun7951__t*, _fself);
  kk_integer_t burnin = _self->burnin; /* int */
  kk_std_core_types__tuple2_ data = _self->data; /* (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>) */
  kk_integer_t ind0 = _self->ind0; /* int */
  kk_string_t name0 = _self->name0; /* string */
  kk_integer_t t__steps = _self->t__steps; /* int */
  double diff0 = _self->diff0; /* double */
  double subtract0 = _self->subtract0; /* double */
  kk_drop_match(_self, {kk_integer_dup(burnin);kk_std_core_types__tuple2__dup(data);kk_integer_dup(ind0);kk_string_dup(name0);kk_integer_dup(t__steps);;;}, {}, _ctx)
  kk_unit_t _x7952 = kk_Unit;
  kk_std_core__list _x7953 = kk_std_core__list_unbox(_b_6521, _ctx); /*list<effects-and-types/row_vector>*/
  kk_climate_dash_experiments__mlift5634_run__climate__model(burnin, data, diff0, ind0, name0, subtract0, t__steps, _x7953, _ctx);
  return kk_unit_box(_x7952);
}
static kk_box_t kk_climate_dash_experiments__mlift5639_run__climate__model_fun7929(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5639_run__climate__model_fun7929__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5639_run__climate__model_fun7929__t*, _fself);
  kk_integer_t burnin = _self->burnin; /* int */
  kk_std_core_types__tuple2_ data = _self->data; /* (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>) */
  kk_integer_t ind0 = _self->ind0; /* int */
  kk_string_t name0 = _self->name0; /* string */
  kk_integer_t t__steps = _self->t__steps; /* int */
  double diff0 = _self->diff0; /* double */
  double subtract0 = _self->subtract0; /* double */
  kk_drop_match(_self, {kk_integer_dup(burnin);kk_std_core_types__tuple2__dup(data);kk_integer_dup(ind0);kk_string_dup(name0);kk_integer_dup(t__steps);;;}, {}, _ctx)
  kk_unit_t _x7930 = kk_Unit;
  kk_std_core__list x0_5751;
  size_t i_5754 = ((size_t)0); /*std/core/hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_5754,kk_context()); /*std/core/hnd/evv<<exn,div,effects-and-types/sample,fsys,console,ndet,std/num/random/random>>*/;
  kk_std_core__list y;
  kk_std_core_types__maybe _match_7517;
  kk_std_core__list _x7931;
  kk_box_t _box_x6490 = data.fst;
  kk_box_t _box_x6491 = data.snd;
  kk_std_core__list _x = kk_std_core__list_unbox(_box_x6491, NULL);
  kk_std_core__list_dup(_x);
  _x7931 = _x; /*list<list<effects-and-types/row_vector>>*/
  kk_integer_t _x7934 = kk_integer_dup(ind0); /*int*/
  _match_7517 = kk_std_core__lp__lb__rb__2_rp_(_x7931, _x7934, _ctx); /*maybe<1>*/
  if (kk_std_core_types__is_Nothing(_match_7517)) {
    kk_string_t message_205;
    kk_string_t _x7935;
    kk_define_string_literal(, _s7936, 48, "ListIndexError: Invalid list indexing at index: ")
    _x7935 = kk_string_dup(_s7936); /*string*/
    kk_string_t _x7937;
    kk_integer_t _x7938 = kk_integer_dup(ind0); /*int*/
    _x7937 = kk_std_core_show(_x7938, _ctx); /*string*/
    message_205 = kk_std_core__lp__plus__plus__1_rp_(_x7935, _x7937, _ctx); /*string*/
    kk_std_core__exception exn_21561;
    kk_std_core__exception_info _x7939;
    kk_std_core_types__optional _match_7519 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
    if (kk_std_core_types__is_Optional(_match_7519)) {
      kk_box_t _box_x6492 = _match_7519._cons.Optional.value;
      kk_std_core__exception_info _info_14279 = kk_std_core__exception_info_unbox(_box_x6492, NULL);
      kk_std_core__exception_info_dup(_info_14279);
      kk_std_core_types__optional_drop(_match_7519, _ctx);
      _x7939 = _info_14279; /*exception-info*/
      goto _match7940;
    }
    _x7939 = kk_std_core__new_ExnError(_ctx); /*exception-info*/
    _match7940: ;
    exn_21561 = kk_std_core__new_Exception(message_205, _x7939, _ctx); /*exception*/
    kk_std_core_hnd__ev ev_21562;
    size_t _x7942 = ((size_t)0); /*size_t*/
    ev_21562 = kk_evv_at(_x7942,kk_context()); /*std/core/hnd/ev<.hnd-exn>*/
    kk_box_t _x7943;
    struct kk_std_core_hnd_Ev* _con7944 = kk_std_core_hnd__as_Ev(ev_21562);
    kk_std_core_hnd__marker m = _con7944->marker;
    kk_box_t _box_x6493 = _con7944->hnd;
    kk_std_core__hnd_exn h = kk_std_core__hnd_exn_unbox(_box_x6493, NULL);
    kk_std_core__hnd_exn_dup(h);
    kk_std_core_hnd__clause1 _match_7518;
    struct kk_std_core__Hnd_exn* _con7946 = kk_std_core__as_Hnd_exn(h);
    kk_std_core_hnd__clause1 except_throw_exn = _con7946->except_throw_exn;
    if (kk_std_core__hnd_exn_is_unique(h)) {
      kk_std_core__hnd_exn_free(h);
    }
    else {
      kk_std_core_hnd__clause1_dup(except_throw_exn);
      kk_std_core__hnd_exn_decref(h, _ctx);
    }
    _match_7518 = except_throw_exn; /*forall<a> std/core/hnd/clause1<exception,a,.hnd-exn,7,8>*/
    kk_function_t _fun_unbox_x6497 = _match_7518.clause;
    _x7943 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x6497, (_fun_unbox_x6497, m, ev_21562, kk_std_core__exception_box(exn_21561, _ctx), _ctx)); /*11*/
    y = kk_std_core__list_unbox(_x7943, _ctx); /*list<effects-and-types/row_vector>*/
  }
  else {
    kk_box_t _box_x6501 = _match_7517._cons.Just.value;
    kk_std_core__list x = kk_std_core__list_unbox(_box_x6501, NULL);
    kk_std_core__list_dup(x);
    kk_std_core_types__maybe_drop(_match_7517, _ctx);
    y = x; /*list<effects-and-types/row_vector>*/
  }
  kk_unit_t __w_l717_c9 = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(y, _ctx);
    kk_box_t _x7948 = kk_std_core_hnd_yield_cont(kk_climate_dash_experiments__new_mlift5639_run__climate__model_fun7949(i_5754, _ctx), _ctx); /*3*/
    x0_5751 = kk_std_core__list_unbox(_x7948, _ctx); /*list<effects-and-types/row_vector>*/
  }
  else {
    x0_5751 = y; /*list<effects-and-types/row_vector>*/
  }
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x0_5751, _ctx);
    kk_box_t _x7950 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments__new_mlift5639_run__climate__model_fun7951(burnin, data, ind0, name0, t__steps, diff0, subtract0, _ctx), _ctx); /*2*/
    kk_unit_unbox(_x7950);
  }
  else {
    kk_climate_dash_experiments__mlift5634_run__climate__model(burnin, data, diff0, ind0, name0, subtract0, t__steps, x0_5751, _ctx);
  }
  return kk_unit_box(_x7930);
}
static kk_box_t kk_climate_dash_experiments__mlift5639_run__climate__model_fun7923(kk_function_t _fself, kk_box_t _b_6526, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5639_run__climate__model_fun7923__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5639_run__climate__model_fun7923__t*, _fself);
  kk_integer_t burnin = _self->burnin; /* int */
  kk_std_core_types__tuple2_ data = _self->data; /* (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>) */
  kk_integer_t t__steps = _self->t__steps; /* int */
  kk_drop_match(_self, {kk_integer_dup(burnin);kk_std_core_types__tuple2__dup(data);kk_integer_dup(t__steps);}, {}, _ctx)
  kk_std_core_types__tuple2_ _match_7514 = kk_std_core_types__tuple2__unbox(_b_6526, _ctx); /*(int, (double, double, string))*/;
  kk_box_t _box_x6485 = _match_7514.fst;
  kk_box_t _box_x6486 = _match_7514.snd;
  kk_integer_t ind0 = kk_integer_unbox(_box_x6485);
  kk_std_core_types__tuple3_ _pat4 = kk_std_core_types__tuple3__unbox(_box_x6486, NULL);
  kk_box_t _box_x6487 = _pat4.fst;
  kk_box_t _box_x6488 = _pat4.snd;
  kk_box_t _box_x6489 = _pat4.thd;
  double diff0 = kk_double_unbox(_box_x6487, NULL);
  double subtract0 = kk_double_unbox(_box_x6488, NULL);
  kk_string_t name0 = kk_string_unbox(_box_x6489);
  kk_integer_dup(ind0);
  kk_string_dup(name0);
  kk_std_core_types__tuple2__drop(_match_7514, _ctx);
  return kk_std_time_timer_print_elapsed(kk_climate_dash_experiments__new_mlift5639_run__climate__model_fun7929(burnin, data, ind0, name0, t__steps, diff0, subtract0, _ctx), kk_std_core_types__new_None(_ctx), _ctx);
}
static kk_box_t kk_climate_dash_experiments__mlift5639_run__climate__model_fun7920(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5639_run__climate__model_fun7920__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5639_run__climate__model_fun7920__t*, _fself);
  kk_integer_t burnin = _self->burnin; /* int */
  kk_std_core_types__tuple2_ data = _self->data; /* (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>) */
  kk_std_core__list pre__data = _self->pre__data; /* list<(double, double, string)> */
  kk_integer_t t__steps = _self->t__steps; /* int */
  kk_drop_match(_self, {kk_integer_dup(burnin);kk_std_core_types__tuple2__dup(data);kk_std_core__list_dup(pre__data);kk_integer_dup(t__steps);}, {}, _ctx)
  kk_std_core__list _x7921;
  kk_std_core__list _b_6533_6524;
  kk_std_core__list _x7922 = kk_std_core__lift21053_list(kk_integer_from_small(0), kk_integer_from_small(11), kk_std_core__new_Nil(_ctx), _ctx); /*list<int>*/
  _b_6533_6524 = kk_std_core_zip(_x7922, pre__data, _ctx); /*list<(int, (double, double, string))>*/
  _x7921 = kk_std_core_map_5(_b_6533_6524, kk_climate_dash_experiments__new_mlift5639_run__climate__model_fun7923(burnin, data, t__steps, _ctx), _ctx); /*list<2>*/
  return kk_std_core__list_box(_x7921, _ctx);
}
static kk_box_t kk_climate_dash_experiments__mlift5639_run__climate__model_fun7919(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5639_run__climate__model_fun7919__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5639_run__climate__model_fun7919__t*, _fself);
  kk_integer_t burnin = _self->burnin; /* int */
  kk_std_core_types__tuple2_ data = _self->data; /* (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>) */
  kk_std_core__list pre__data = _self->pre__data; /* list<(double, double, string)> */
  kk_integer_t t__steps = _self->t__steps; /* int */
  kk_drop_match(_self, {kk_integer_dup(burnin);kk_std_core_types__tuple2__dup(data);kk_std_core__list_dup(pre__data);kk_integer_dup(t__steps);}, {}, _ctx)
  return kk_handlers_random__sampler(kk_climate_dash_experiments__new_mlift5639_run__climate__model_fun7920(burnin, data, pre__data, t__steps, _ctx), _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift5639_run__climate__model_fun7955__t {
  struct kk_function_s _base;
  kk_std_core_types__tuple2_ data;
  kk_std_core__list pre__data;
  kk_integer_t pt;
  kk_std_core_types__optional repeat__num;
  kk_integer_t rs;
  kk_integer_t sbrs;
};
static kk_box_t kk_climate_dash_experiments__mlift5639_run__climate__model_fun7955(kk_function_t _fself, kk_box_t _b_6541, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5639_run__climate__model_fun7955(kk_std_core_types__tuple2_ data, kk_std_core__list pre__data, kk_integer_t pt, kk_std_core_types__optional repeat__num, kk_integer_t rs, kk_integer_t sbrs, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5639_run__climate__model_fun7955__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5639_run__climate__model_fun7955__t, 9, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5639_run__climate__model_fun7955, kk_context());
  _self->data = data;
  _self->pre__data = pre__data;
  _self->pt = pt;
  _self->repeat__num = repeat__num;
  _self->rs = rs;
  _self->sbrs = sbrs;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift5639_run__climate__model_fun7955(kk_function_t _fself, kk_box_t _b_6541, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5639_run__climate__model_fun7955__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5639_run__climate__model_fun7955__t*, _fself);
  kk_std_core_types__tuple2_ data = _self->data; /* (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>) */
  kk_std_core__list pre__data = _self->pre__data; /* list<(double, double, string)> */
  kk_integer_t pt = _self->pt; /* int */
  kk_std_core_types__optional repeat__num = _self->repeat__num; /* optional<int> */
  kk_integer_t rs = _self->rs; /* int */
  kk_integer_t sbrs = _self->sbrs; /* int */
  kk_drop_match(_self, {kk_std_core_types__tuple2__dup(data);kk_std_core__list_dup(pre__data);kk_integer_dup(pt);kk_std_core_types__optional_dup(repeat__num);kk_integer_dup(rs);kk_integer_dup(sbrs);}, {}, _ctx)
  kk_unit_t _x7956 = kk_Unit;
  kk_std_core__list _x7957 = kk_std_core__list_unbox(_b_6541, _ctx); /*list<()>*/
  kk_climate_dash_experiments__mlift5635_run__climate__model(data, pre__data, pt, repeat__num, rs, sbrs, _x7957, _ctx);
  return kk_unit_box(_x7956);
}

kk_unit_t kk_climate_dash_experiments__mlift5639_run__climate__model(kk_integer_t burnin, kk_std_core_types__tuple2_ data, kk_std_core__list pre__data, kk_integer_t pt, kk_std_core_types__optional repeat__num, kk_integer_t rs, kk_integer_t sbrs, kk_integer_t t__steps, kk_std_core__list wild__1, kk_context_t* _ctx) { /* (burnin : int, data : (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>), pre_data : list<(double, double, string)>, pt : int, repeat_num : optional<int>, rs : int, sbrs : int, t_steps : int, wild_1 : list<()>) -> <ndet,console,div,exn,fsys,std/num/random/random> () */ 
  kk_std_core__list_drop(wild__1, _ctx);
  kk_unit_t __2 = kk_Unit;
  kk_string_t _x7915;
  kk_define_string_literal(, _s7916, 39, "Beginning to start TMCMC experiment #2:")
  _x7915 = kk_string_dup(_s7916); /*string*/
  kk_std_core_printsln(_x7915, _ctx);
  kk_std_core__list x_5747;
  kk_box_t _x7917;
  kk_function_t _x7918;
  kk_std_core_types__tuple2__dup(data);
  kk_std_core__list_dup(pre__data);
  _x7918 = kk_climate_dash_experiments__new_mlift5639_run__climate__model_fun7919(burnin, data, pre__data, t__steps, _ctx); /*() -> <ndet,console|1> 0*/
  _x7917 = kk_std_time_timer_print_elapsed(_x7918, kk_std_core_types__new_None(_ctx), _ctx); /*0*/
  x_5747 = kk_std_core__list_unbox(_x7917, _ctx); /*list<()>*/
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_5747, _ctx);
    kk_box_t _x7954 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments__new_mlift5639_run__climate__model_fun7955(data, pre__data, pt, repeat__num, rs, sbrs, _ctx), _ctx); /*2*/
    kk_unit_unbox(_x7954); return kk_Unit;
  }
  kk_climate_dash_experiments__mlift5635_run__climate__model(data, pre__data, pt, repeat__num, rs, sbrs, x_5747, _ctx); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_climate_dash_experiments__mlift5640_run__climate__model_fun8000__t {
  struct kk_function_s _base;
  kk_integer_t burnin;
  kk_std_core_types__tuple2_ data;
  kk_std_core__list pre__data;
  kk_integer_t t__steps;
};
static kk_box_t kk_climate_dash_experiments__mlift5640_run__climate__model_fun8000(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5640_run__climate__model_fun8000(kk_integer_t burnin, kk_std_core_types__tuple2_ data, kk_std_core__list pre__data, kk_integer_t t__steps, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5640_run__climate__model_fun8000__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5640_run__climate__model_fun8000__t, 6, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5640_run__climate__model_fun8000, kk_context());
  _self->burnin = burnin;
  _self->data = data;
  _self->pre__data = pre__data;
  _self->t__steps = t__steps;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift5640_run__climate__model_fun8001__t {
  struct kk_function_s _base;
  kk_integer_t burnin;
  kk_std_core_types__tuple2_ data;
  kk_std_core__list pre__data;
  kk_integer_t t__steps;
};
static kk_box_t kk_climate_dash_experiments__mlift5640_run__climate__model_fun8001(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5640_run__climate__model_fun8001(kk_integer_t burnin, kk_std_core_types__tuple2_ data, kk_std_core__list pre__data, kk_integer_t t__steps, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5640_run__climate__model_fun8001__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5640_run__climate__model_fun8001__t, 6, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5640_run__climate__model_fun8001, kk_context());
  _self->burnin = burnin;
  _self->data = data;
  _self->pre__data = pre__data;
  _self->t__steps = t__steps;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift5640_run__climate__model_fun8004__t {
  struct kk_function_s _base;
  kk_integer_t burnin;
  kk_std_core_types__tuple2_ data;
  kk_integer_t t__steps;
};
static kk_box_t kk_climate_dash_experiments__mlift5640_run__climate__model_fun8004(kk_function_t _fself, kk_box_t _b_6705, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5640_run__climate__model_fun8004(kk_integer_t burnin, kk_std_core_types__tuple2_ data, kk_integer_t t__steps, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5640_run__climate__model_fun8004__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5640_run__climate__model_fun8004__t, 5, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5640_run__climate__model_fun8004, kk_context());
  _self->burnin = burnin;
  _self->data = data;
  _self->t__steps = t__steps;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift5640_run__climate__model_fun8010__t {
  struct kk_function_s _base;
  kk_integer_t burnin;
  kk_std_core_types__tuple2_ data;
  kk_integer_t ind;
  kk_string_t name;
  kk_integer_t t__steps;
  double diff;
  double subtract;
};
static kk_box_t kk_climate_dash_experiments__mlift5640_run__climate__model_fun8010(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5640_run__climate__model_fun8010(kk_integer_t burnin, kk_std_core_types__tuple2_ data, kk_integer_t ind, kk_string_t name, kk_integer_t t__steps, double diff, double subtract, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5640_run__climate__model_fun8010__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5640_run__climate__model_fun8010__t, 7, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5640_run__climate__model_fun8010, kk_context());
  _self->burnin = burnin;
  _self->data = data;
  _self->ind = ind;
  _self->name = name;
  _self->t__steps = t__steps;
  _self->diff = diff;
  _self->subtract = subtract;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift5640_run__climate__model_fun8030__t {
  struct kk_function_s _base;
  size_t i_5767;
};
static kk_box_t kk_climate_dash_experiments__mlift5640_run__climate__model_fun8030(kk_function_t _fself, kk_function_t _b_6689, kk_box_t _b_6690, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5640_run__climate__model_fun8030(size_t i_5767, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5640_run__climate__model_fun8030__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5640_run__climate__model_fun8030__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5640_run__climate__model_fun8030, kk_context());
  _self->i_5767 = i_5767;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift5640_run__climate__model_fun8030(kk_function_t _fself, kk_function_t _b_6689, kk_box_t _b_6690, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5640_run__climate__model_fun8030__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5640_run__climate__model_fun8030__t*, _fself);
  size_t i_5767 = _self->i_5767; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_5767, _b_6689, _b_6690, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift5640_run__climate__model_fun8032__t {
  struct kk_function_s _base;
  kk_integer_t burnin;
  kk_std_core_types__tuple2_ data;
  kk_integer_t ind;
  kk_string_t name;
  kk_integer_t t__steps;
  double diff;
  double subtract;
};
static kk_box_t kk_climate_dash_experiments__mlift5640_run__climate__model_fun8032(kk_function_t _fself, kk_box_t _b_6700, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5640_run__climate__model_fun8032(kk_integer_t burnin, kk_std_core_types__tuple2_ data, kk_integer_t ind, kk_string_t name, kk_integer_t t__steps, double diff, double subtract, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5640_run__climate__model_fun8032__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5640_run__climate__model_fun8032__t, 7, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5640_run__climate__model_fun8032, kk_context());
  _self->burnin = burnin;
  _self->data = data;
  _self->ind = ind;
  _self->name = name;
  _self->t__steps = t__steps;
  _self->diff = diff;
  _self->subtract = subtract;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift5640_run__climate__model_fun8032(kk_function_t _fself, kk_box_t _b_6700, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5640_run__climate__model_fun8032__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5640_run__climate__model_fun8032__t*, _fself);
  kk_integer_t burnin = _self->burnin; /* int */
  kk_std_core_types__tuple2_ data = _self->data; /* (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>) */
  kk_integer_t ind = _self->ind; /* int */
  kk_string_t name = _self->name; /* string */
  kk_integer_t t__steps = _self->t__steps; /* int */
  double diff = _self->diff; /* double */
  double subtract = _self->subtract; /* double */
  kk_drop_match(_self, {kk_integer_dup(burnin);kk_std_core_types__tuple2__dup(data);kk_integer_dup(ind);kk_string_dup(name);kk_integer_dup(t__steps);;;}, {}, _ctx)
  kk_unit_t _x8033 = kk_Unit;
  kk_std_core__list _x8034 = kk_std_core__list_unbox(_b_6700, _ctx); /*list<effects-and-types/row_vector>*/
  kk_climate_dash_experiments__mlift5638_run__climate__model(burnin, data, diff, ind, name, subtract, t__steps, _x8034, _ctx);
  return kk_unit_box(_x8033);
}
static kk_box_t kk_climate_dash_experiments__mlift5640_run__climate__model_fun8010(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5640_run__climate__model_fun8010__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5640_run__climate__model_fun8010__t*, _fself);
  kk_integer_t burnin = _self->burnin; /* int */
  kk_std_core_types__tuple2_ data = _self->data; /* (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>) */
  kk_integer_t ind = _self->ind; /* int */
  kk_string_t name = _self->name; /* string */
  kk_integer_t t__steps = _self->t__steps; /* int */
  double diff = _self->diff; /* double */
  double subtract = _self->subtract; /* double */
  kk_drop_match(_self, {kk_integer_dup(burnin);kk_std_core_types__tuple2__dup(data);kk_integer_dup(ind);kk_string_dup(name);kk_integer_dup(t__steps);;;}, {}, _ctx)
  kk_unit_t _x8011 = kk_Unit;
  kk_std_core__list x0_5764;
  size_t i_5767 = ((size_t)0); /*std/core/hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_5767,kk_context()); /*std/core/hnd/evv<<exn,div,effects-and-types/sample,fsys,console,ndet,std/num/random/random>>*/;
  kk_std_core__list y;
  kk_std_core_types__maybe _match_7510;
  kk_std_core__list _x8012;
  kk_box_t _box_x6669 = data.fst;
  kk_box_t _box_x6670 = data.snd;
  kk_std_core__list _x = kk_std_core__list_unbox(_box_x6670, NULL);
  kk_std_core__list_dup(_x);
  _x8012 = _x; /*list<list<effects-and-types/row_vector>>*/
  kk_integer_t _x8015 = kk_integer_dup(ind); /*int*/
  _match_7510 = kk_std_core__lp__lb__rb__2_rp_(_x8012, _x8015, _ctx); /*maybe<1>*/
  if (kk_std_core_types__is_Nothing(_match_7510)) {
    kk_string_t message_205;
    kk_string_t _x8016;
    kk_define_string_literal(, _s8017, 48, "ListIndexError: Invalid list indexing at index: ")
    _x8016 = kk_string_dup(_s8017); /*string*/
    kk_string_t _x8018;
    kk_integer_t _x8019 = kk_integer_dup(ind); /*int*/
    _x8018 = kk_std_core_show(_x8019, _ctx); /*string*/
    message_205 = kk_std_core__lp__plus__plus__1_rp_(_x8016, _x8018, _ctx); /*string*/
    kk_std_core__exception exn_21561;
    kk_std_core__exception_info _x8020;
    kk_std_core_types__optional _match_7512 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
    if (kk_std_core_types__is_Optional(_match_7512)) {
      kk_box_t _box_x6671 = _match_7512._cons.Optional.value;
      kk_std_core__exception_info _info_14279 = kk_std_core__exception_info_unbox(_box_x6671, NULL);
      kk_std_core__exception_info_dup(_info_14279);
      kk_std_core_types__optional_drop(_match_7512, _ctx);
      _x8020 = _info_14279; /*exception-info*/
      goto _match8021;
    }
    _x8020 = kk_std_core__new_ExnError(_ctx); /*exception-info*/
    _match8021: ;
    exn_21561 = kk_std_core__new_Exception(message_205, _x8020, _ctx); /*exception*/
    kk_std_core_hnd__ev ev_21562;
    size_t _x8023 = ((size_t)0); /*size_t*/
    ev_21562 = kk_evv_at(_x8023,kk_context()); /*std/core/hnd/ev<.hnd-exn>*/
    kk_box_t _x8024;
    struct kk_std_core_hnd_Ev* _con8025 = kk_std_core_hnd__as_Ev(ev_21562);
    kk_std_core_hnd__marker m = _con8025->marker;
    kk_box_t _box_x6672 = _con8025->hnd;
    kk_std_core__hnd_exn h = kk_std_core__hnd_exn_unbox(_box_x6672, NULL);
    kk_std_core__hnd_exn_dup(h);
    kk_std_core_hnd__clause1 _match_7511;
    struct kk_std_core__Hnd_exn* _con8027 = kk_std_core__as_Hnd_exn(h);
    kk_std_core_hnd__clause1 except_throw_exn = _con8027->except_throw_exn;
    if (kk_std_core__hnd_exn_is_unique(h)) {
      kk_std_core__hnd_exn_free(h);
    }
    else {
      kk_std_core_hnd__clause1_dup(except_throw_exn);
      kk_std_core__hnd_exn_decref(h, _ctx);
    }
    _match_7511 = except_throw_exn; /*forall<a> std/core/hnd/clause1<exception,a,.hnd-exn,7,8>*/
    kk_function_t _fun_unbox_x6676 = _match_7511.clause;
    _x8024 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x6676, (_fun_unbox_x6676, m, ev_21562, kk_std_core__exception_box(exn_21561, _ctx), _ctx)); /*11*/
    y = kk_std_core__list_unbox(_x8024, _ctx); /*list<effects-and-types/row_vector>*/
  }
  else {
    kk_box_t _box_x6680 = _match_7510._cons.Just.value;
    kk_std_core__list x = kk_std_core__list_unbox(_box_x6680, NULL);
    kk_std_core__list_dup(x);
    kk_std_core_types__maybe_drop(_match_7510, _ctx);
    y = x; /*list<effects-and-types/row_vector>*/
  }
  kk_unit_t __w_l717_c9 = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(y, _ctx);
    kk_box_t _x8029 = kk_std_core_hnd_yield_cont(kk_climate_dash_experiments__new_mlift5640_run__climate__model_fun8030(i_5767, _ctx), _ctx); /*3*/
    x0_5764 = kk_std_core__list_unbox(_x8029, _ctx); /*list<effects-and-types/row_vector>*/
  }
  else {
    x0_5764 = y; /*list<effects-and-types/row_vector>*/
  }
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x0_5764, _ctx);
    kk_box_t _x8031 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments__new_mlift5640_run__climate__model_fun8032(burnin, data, ind, name, t__steps, diff, subtract, _ctx), _ctx); /*2*/
    kk_unit_unbox(_x8031);
  }
  else {
    kk_climate_dash_experiments__mlift5638_run__climate__model(burnin, data, diff, ind, name, subtract, t__steps, x0_5764, _ctx);
  }
  return kk_unit_box(_x8011);
}
static kk_box_t kk_climate_dash_experiments__mlift5640_run__climate__model_fun8004(kk_function_t _fself, kk_box_t _b_6705, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5640_run__climate__model_fun8004__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5640_run__climate__model_fun8004__t*, _fself);
  kk_integer_t burnin = _self->burnin; /* int */
  kk_std_core_types__tuple2_ data = _self->data; /* (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>) */
  kk_integer_t t__steps = _self->t__steps; /* int */
  kk_drop_match(_self, {kk_integer_dup(burnin);kk_std_core_types__tuple2__dup(data);kk_integer_dup(t__steps);}, {}, _ctx)
  kk_std_core_types__tuple2_ _match_7507 = kk_std_core_types__tuple2__unbox(_b_6705, _ctx); /*(int, (double, double, string))*/;
  kk_box_t _box_x6664 = _match_7507.fst;
  kk_box_t _box_x6665 = _match_7507.snd;
  kk_integer_t ind = kk_integer_unbox(_box_x6664);
  kk_std_core_types__tuple3_ _pat2 = kk_std_core_types__tuple3__unbox(_box_x6665, NULL);
  kk_box_t _box_x6666 = _pat2.fst;
  kk_box_t _box_x6667 = _pat2.snd;
  kk_box_t _box_x6668 = _pat2.thd;
  double diff = kk_double_unbox(_box_x6666, NULL);
  double subtract = kk_double_unbox(_box_x6667, NULL);
  kk_string_t name = kk_string_unbox(_box_x6668);
  kk_integer_dup(ind);
  kk_string_dup(name);
  kk_std_core_types__tuple2__drop(_match_7507, _ctx);
  return kk_std_time_timer_print_elapsed(kk_climate_dash_experiments__new_mlift5640_run__climate__model_fun8010(burnin, data, ind, name, t__steps, diff, subtract, _ctx), kk_std_core_types__new_None(_ctx), _ctx);
}
static kk_box_t kk_climate_dash_experiments__mlift5640_run__climate__model_fun8001(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5640_run__climate__model_fun8001__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5640_run__climate__model_fun8001__t*, _fself);
  kk_integer_t burnin = _self->burnin; /* int */
  kk_std_core_types__tuple2_ data = _self->data; /* (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>) */
  kk_std_core__list pre__data = _self->pre__data; /* list<(double, double, string)> */
  kk_integer_t t__steps = _self->t__steps; /* int */
  kk_drop_match(_self, {kk_integer_dup(burnin);kk_std_core_types__tuple2__dup(data);kk_std_core__list_dup(pre__data);kk_integer_dup(t__steps);}, {}, _ctx)
  kk_std_core__list _x8002;
  kk_std_core__list _b_6712_6703;
  kk_std_core__list _x8003 = kk_std_core__lift21053_list(kk_integer_from_small(0), kk_integer_from_small(11), kk_std_core__new_Nil(_ctx), _ctx); /*list<int>*/
  _b_6712_6703 = kk_std_core_zip(_x8003, pre__data, _ctx); /*list<(int, (double, double, string))>*/
  _x8002 = kk_std_core_map_5(_b_6712_6703, kk_climate_dash_experiments__new_mlift5640_run__climate__model_fun8004(burnin, data, t__steps, _ctx), _ctx); /*list<2>*/
  return kk_std_core__list_box(_x8002, _ctx);
}
static kk_box_t kk_climate_dash_experiments__mlift5640_run__climate__model_fun8000(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5640_run__climate__model_fun8000__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5640_run__climate__model_fun8000__t*, _fself);
  kk_integer_t burnin = _self->burnin; /* int */
  kk_std_core_types__tuple2_ data = _self->data; /* (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>) */
  kk_std_core__list pre__data = _self->pre__data; /* list<(double, double, string)> */
  kk_integer_t t__steps = _self->t__steps; /* int */
  kk_drop_match(_self, {kk_integer_dup(burnin);kk_std_core_types__tuple2__dup(data);kk_std_core__list_dup(pre__data);kk_integer_dup(t__steps);}, {}, _ctx)
  return kk_handlers_random__sampler(kk_climate_dash_experiments__new_mlift5640_run__climate__model_fun8001(burnin, data, pre__data, t__steps, _ctx), _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift5640_run__climate__model_fun8036__t {
  struct kk_function_s _base;
  kk_integer_t burnin;
  kk_std_core_types__tuple2_ data;
  kk_std_core__list pre__data;
  kk_integer_t pt;
  kk_std_core_types__optional repeat__num;
  kk_integer_t rs;
  kk_integer_t sbrs;
  kk_integer_t t__steps;
};
static kk_box_t kk_climate_dash_experiments__mlift5640_run__climate__model_fun8036(kk_function_t _fself, kk_box_t _b_6720, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5640_run__climate__model_fun8036(kk_integer_t burnin, kk_std_core_types__tuple2_ data, kk_std_core__list pre__data, kk_integer_t pt, kk_std_core_types__optional repeat__num, kk_integer_t rs, kk_integer_t sbrs, kk_integer_t t__steps, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5640_run__climate__model_fun8036__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5640_run__climate__model_fun8036__t, 11, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5640_run__climate__model_fun8036, kk_context());
  _self->burnin = burnin;
  _self->data = data;
  _self->pre__data = pre__data;
  _self->pt = pt;
  _self->repeat__num = repeat__num;
  _self->rs = rs;
  _self->sbrs = sbrs;
  _self->t__steps = t__steps;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift5640_run__climate__model_fun8036(kk_function_t _fself, kk_box_t _b_6720, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5640_run__climate__model_fun8036__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5640_run__climate__model_fun8036__t*, _fself);
  kk_integer_t burnin = _self->burnin; /* int */
  kk_std_core_types__tuple2_ data = _self->data; /* (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>) */
  kk_std_core__list pre__data = _self->pre__data; /* list<(double, double, string)> */
  kk_integer_t pt = _self->pt; /* int */
  kk_std_core_types__optional repeat__num = _self->repeat__num; /* optional<int> */
  kk_integer_t rs = _self->rs; /* int */
  kk_integer_t sbrs = _self->sbrs; /* int */
  kk_integer_t t__steps = _self->t__steps; /* int */
  kk_drop_match(_self, {kk_integer_dup(burnin);kk_std_core_types__tuple2__dup(data);kk_std_core__list_dup(pre__data);kk_integer_dup(pt);kk_std_core_types__optional_dup(repeat__num);kk_integer_dup(rs);kk_integer_dup(sbrs);kk_integer_dup(t__steps);}, {}, _ctx)
  kk_unit_t _x8037 = kk_Unit;
  kk_std_core__list _x8038 = kk_std_core__list_unbox(_b_6720, _ctx); /*list<()>*/
  kk_climate_dash_experiments__mlift5639_run__climate__model(burnin, data, pre__data, pt, repeat__num, rs, sbrs, t__steps, _x8038, _ctx);
  return kk_unit_box(_x8037);
}

kk_unit_t kk_climate_dash_experiments__mlift5640_run__climate__model(kk_integer_t burnin, kk_integer_t pt, kk_std_core_types__optional repeat__num, kk_integer_t rs, kk_integer_t sbrs, kk_integer_t t__steps, kk_std_core_types__tuple2_ data, kk_context_t* _ctx) { /* (burnin : int, pt : int, repeat_num : optional<int>, rs : int, sbrs : int, t_steps : int, data : (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>)) -> <div,exn,fsys,console,ndet,std/num/random/random> () */ 
  kk_std_core__list pre__data;
  kk_std_core_types__tuple3_ _b_6604_6602;
  kk_box_t _x7958;
  kk_string_t _x7959;
  kk_define_string_literal(, _s7960, 3, "jan")
  _x7959 = kk_string_dup(_s7960); /*string*/
  _x7958 = kk_string_box(_x7959); /*10*/
  _b_6604_6602 = kk_std_core_types__new_dash__lp__comma__comma__rp_(kk_double_box(0x1.4p3, _ctx), kk_double_box(-0x1.8p1, _ctx), _x7958, _ctx); /*(double, double, string)*/
  kk_std_core__list _b_6605_6603;
  kk_std_core_types__tuple3_ _b_6609_6600;
  kk_box_t _x7961;
  kk_string_t _x7962;
  kk_define_string_literal(, _s7963, 3, "feb")
  _x7962 = kk_string_dup(_s7963); /*string*/
  _x7961 = kk_string_box(_x7962); /*10*/
  _b_6609_6600 = kk_std_core_types__new_dash__lp__comma__comma__rp_(kk_double_box(0x1p3, _ctx), kk_double_box(-0x1p0, _ctx), _x7961, _ctx); /*(double, double, string)*/
  kk_std_core__list _b_6610_6601;
  kk_std_core_types__tuple3_ _b_6614_6598;
  kk_box_t _x7964;
  kk_string_t _x7965;
  kk_define_string_literal(, _s7966, 3, "mar")
  _x7965 = kk_string_dup(_s7966); /*string*/
  _x7964 = kk_string_box(_x7965); /*10*/
  _b_6614_6598 = kk_std_core_types__new_dash__lp__comma__comma__rp_(kk_double_box(0x1.cp2, _ctx), kk_double_box(0x1p0, _ctx), _x7964, _ctx); /*(double, double, string)*/
  kk_std_core__list _b_6615_6599;
  kk_std_core_types__tuple3_ _b_6619_6596;
  kk_box_t _x7967;
  kk_string_t _x7968;
  kk_define_string_literal(, _s7969, 3, "apr")
  _x7968 = kk_string_dup(_s7969); /*string*/
  _x7967 = kk_string_box(_x7968); /*10*/
  _b_6619_6596 = kk_std_core_types__new_dash__lp__comma__comma__rp_(kk_double_box(0x1.8p2, _ctx), kk_double_box(0x1.4p2, _ctx), _x7967, _ctx); /*(double, double, string)*/
  kk_std_core__list _b_6620_6597;
  kk_std_core_types__tuple3_ _b_6624_6594;
  kk_box_t _x7970;
  kk_string_t _x7971;
  kk_define_string_literal(, _s7972, 3, "may")
  _x7971 = kk_string_dup(_s7972); /*string*/
  _x7970 = kk_string_box(_x7971); /*10*/
  _b_6624_6594 = kk_std_core_types__new_dash__lp__comma__comma__rp_(kk_double_box(0x1p3, _ctx), kk_double_box(0x1.2p3, _ctx), _x7970, _ctx); /*(double, double, string)*/
  kk_std_core__list _b_6625_6595;
  kk_std_core_types__tuple3_ _b_6629_6592;
  kk_box_t _x7973;
  kk_string_t _x7974;
  kk_define_string_literal(, _s7975, 3, "jun")
  _x7974 = kk_string_dup(_s7975); /*string*/
  _x7973 = kk_string_box(_x7974); /*10*/
  _b_6629_6592 = kk_std_core_types__new_dash__lp__comma__comma__rp_(kk_double_box(0x1p3, _ctx), kk_double_box(0x1.4p3, _ctx), _x7973, _ctx); /*(double, double, string)*/
  kk_std_core__list _b_6630_6593;
  kk_std_core_types__tuple3_ _b_6634_6590;
  kk_box_t _x7976;
  kk_string_t _x7977;
  kk_define_string_literal(, _s7978, 3, "jul")
  _x7977 = kk_string_dup(_s7978); /*string*/
  _x7976 = kk_string_box(_x7977); /*10*/
  _b_6634_6590 = kk_std_core_types__new_dash__lp__comma__comma__rp_(kk_double_box(0x1.2p3, _ctx), kk_double_box(0x1.6p3, _ctx), _x7976, _ctx); /*(double, double, string)*/
  kk_std_core__list _b_6635_6591;
  kk_std_core_types__tuple3_ _b_6639_6588;
  kk_box_t _x7979;
  kk_string_t _x7980;
  kk_define_string_literal(, _s7981, 3, "aug")
  _x7980 = kk_string_dup(_s7981); /*string*/
  _x7979 = kk_string_box(_x7980); /*10*/
  _b_6639_6588 = kk_std_core_types__new_dash__lp__comma__comma__rp_(kk_double_box(0x1.8p2, _ctx), kk_double_box(0x1.6p3, _ctx), _x7979, _ctx); /*(double, double, string)*/
  kk_std_core__list _b_6640_6589;
  kk_std_core_types__tuple3_ _b_6644_6586;
  kk_box_t _x7982;
  kk_string_t _x7983;
  kk_define_string_literal(, _s7984, 3, "sep")
  _x7983 = kk_string_dup(_s7984); /*string*/
  _x7982 = kk_string_box(_x7983); /*10*/
  _b_6644_6586 = kk_std_core_types__new_dash__lp__comma__comma__rp_(kk_double_box(0x1.4p2, _ctx), kk_double_box(0x1.4p3, _ctx), _x7982, _ctx); /*(double, double, string)*/
  kk_std_core__list _b_6645_6587;
  kk_std_core_types__tuple3_ _b_6649_6584;
  kk_box_t _x7985;
  kk_string_t _x7986;
  kk_define_string_literal(, _s7987, 3, "oct")
  _x7986 = kk_string_dup(_s7987); /*string*/
  _x7985 = kk_string_box(_x7986); /*10*/
  _b_6649_6584 = kk_std_core_types__new_dash__lp__comma__comma__rp_(kk_double_box(0x1.2p3, _ctx), kk_double_box(0x1p0, _ctx), _x7985, _ctx); /*(double, double, string)*/
  kk_std_core__list _b_6650_6585;
  kk_std_core_types__tuple3_ _b_6654_6582;
  kk_box_t _x7988;
  kk_string_t _x7989;
  kk_define_string_literal(, _s7990, 3, "nov")
  _x7989 = kk_string_dup(_s7990); /*string*/
  _x7988 = kk_string_box(_x7989); /*10*/
  _b_6654_6582 = kk_std_core_types__new_dash__lp__comma__comma__rp_(kk_double_box(0x1.cp2, _ctx), kk_double_box(0x1p1, _ctx), _x7988, _ctx); /*(double, double, string)*/
  kk_std_core__list _b_6655_6583;
  kk_std_core_types__tuple3_ _b_6659_6580;
  kk_box_t _x7991;
  kk_string_t _x7992;
  kk_define_string_literal(, _s7993, 3, "dec")
  _x7992 = kk_string_dup(_s7993); /*string*/
  _x7991 = kk_string_box(_x7992); /*10*/
  _b_6659_6580 = kk_std_core_types__new_dash__lp__comma__comma__rp_(kk_double_box(0x1.8p2, _ctx), kk_double_box(-0x1p0, _ctx), _x7991, _ctx); /*(double, double, string)*/
  _b_6655_6583 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core_types__tuple3__box(_b_6659_6580, _ctx), kk_std_core__new_Nil(_ctx), _ctx); /*list<(double, double, string)>*/
  _b_6650_6585 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core_types__tuple3__box(_b_6654_6582, _ctx), _b_6655_6583, _ctx); /*list<(double, double, string)>*/
  _b_6645_6587 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core_types__tuple3__box(_b_6649_6584, _ctx), _b_6650_6585, _ctx); /*list<(double, double, string)>*/
  _b_6640_6589 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core_types__tuple3__box(_b_6644_6586, _ctx), _b_6645_6587, _ctx); /*list<(double, double, string)>*/
  _b_6635_6591 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core_types__tuple3__box(_b_6639_6588, _ctx), _b_6640_6589, _ctx); /*list<(double, double, string)>*/
  _b_6630_6593 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core_types__tuple3__box(_b_6634_6590, _ctx), _b_6635_6591, _ctx); /*list<(double, double, string)>*/
  _b_6625_6595 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core_types__tuple3__box(_b_6629_6592, _ctx), _b_6630_6593, _ctx); /*list<(double, double, string)>*/
  _b_6620_6597 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core_types__tuple3__box(_b_6624_6594, _ctx), _b_6625_6595, _ctx); /*list<(double, double, string)>*/
  _b_6615_6599 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core_types__tuple3__box(_b_6619_6596, _ctx), _b_6620_6597, _ctx); /*list<(double, double, string)>*/
  _b_6610_6601 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core_types__tuple3__box(_b_6614_6598, _ctx), _b_6615_6599, _ctx); /*list<(double, double, string)>*/
  _b_6605_6603 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core_types__tuple3__box(_b_6609_6600, _ctx), _b_6610_6601, _ctx); /*list<(double, double, string)>*/
  pre__data = kk_std_core__new_Cons(kk_reuse_null, kk_std_core_types__tuple3__box(_b_6604_6602, _ctx), _b_6605_6603, _ctx); /*list<(double, double, string)>*/
  kk_unit_t __ = kk_Unit;
  kk_string_t _x7994;
  kk_define_string_literal(, _s7995, 93, "Starting to run the climate model! Run with -O2 --showelapsed flag to improve execution time.")
  _x7994 = kk_string_dup(_s7995); /*string*/
  kk_std_core_printsln(_x7994, _ctx);
  kk_unit_t __0 = kk_Unit;
  kk_string_t _x7996;
  kk_define_string_literal(, _s7997, 39, "Beginning to start TMCMC experiment #1:")
  _x7996 = kk_string_dup(_s7997); /*string*/
  kk_std_core_printsln(_x7996, _ctx);
  kk_std_core__list x_5760;
  kk_box_t _x7998;
  kk_function_t _x7999;
  kk_integer_dup(burnin);
  kk_std_core_types__tuple2__dup(data);
  kk_std_core__list_dup(pre__data);
  kk_integer_dup(t__steps);
  _x7999 = kk_climate_dash_experiments__new_mlift5640_run__climate__model_fun8000(burnin, data, pre__data, t__steps, _ctx); /*() -> <ndet,console|1> 0*/
  _x7998 = kk_std_time_timer_print_elapsed(_x7999, kk_std_core_types__new_None(_ctx), _ctx); /*0*/
  x_5760 = kk_std_core__list_unbox(_x7998, _ctx); /*list<()>*/
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_5760, _ctx);
    kk_box_t _x8035 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments__new_mlift5640_run__climate__model_fun8036(burnin, data, pre__data, pt, repeat__num, rs, sbrs, t__steps, _ctx), _ctx); /*2*/
    kk_unit_unbox(_x8035); return kk_Unit;
  }
  kk_climate_dash_experiments__mlift5639_run__climate__model(burnin, data, pre__data, pt, repeat__num, rs, sbrs, t__steps, x_5760, _ctx); return kk_Unit;
}


// lift anonymous function
struct kk_climate_dash_experiments_run__climate__model_fun8040__t {
  struct kk_function_s _base;
  size_t i_5774;
};
static kk_box_t kk_climate_dash_experiments_run__climate__model_fun8040(kk_function_t _fself, kk_function_t _b_6728, kk_box_t _b_6729, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__climate__model_fun8040(size_t i_5774, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__climate__model_fun8040__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__climate__model_fun8040__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__climate__model_fun8040, kk_context());
  _self->i_5774 = i_5774;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments_run__climate__model_fun8040(kk_function_t _fself, kk_function_t _b_6728, kk_box_t _b_6729, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__climate__model_fun8040__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__climate__model_fun8040__t*, _fself);
  size_t i_5774 = _self->i_5774; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_5774, _b_6728, _b_6729, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments_run__climate__model_fun8042__t {
  struct kk_function_s _base;
  kk_integer_t burnin;
  kk_integer_t pt;
  kk_std_core_types__optional repeat__num;
  kk_integer_t rs;
  kk_integer_t sbrs;
  kk_integer_t t__steps;
};
static kk_box_t kk_climate_dash_experiments_run__climate__model_fun8042(kk_function_t _fself, kk_box_t _b_6739, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__climate__model_fun8042(kk_integer_t burnin, kk_integer_t pt, kk_std_core_types__optional repeat__num, kk_integer_t rs, kk_integer_t sbrs, kk_integer_t t__steps, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__climate__model_fun8042__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__climate__model_fun8042__t, 8, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__climate__model_fun8042, kk_context());
  _self->burnin = burnin;
  _self->pt = pt;
  _self->repeat__num = repeat__num;
  _self->rs = rs;
  _self->sbrs = sbrs;
  _self->t__steps = t__steps;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments_run__climate__model_fun8042(kk_function_t _fself, kk_box_t _b_6739, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__climate__model_fun8042__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__climate__model_fun8042__t*, _fself);
  kk_integer_t burnin = _self->burnin; /* int */
  kk_integer_t pt = _self->pt; /* int */
  kk_std_core_types__optional repeat__num = _self->repeat__num; /* optional<int> */
  kk_integer_t rs = _self->rs; /* int */
  kk_integer_t sbrs = _self->sbrs; /* int */
  kk_integer_t t__steps = _self->t__steps; /* int */
  kk_drop_match(_self, {kk_integer_dup(burnin);kk_integer_dup(pt);kk_std_core_types__optional_dup(repeat__num);kk_integer_dup(rs);kk_integer_dup(sbrs);kk_integer_dup(t__steps);}, {}, _ctx)
  kk_unit_t _x8043 = kk_Unit;
  kk_std_core_types__tuple2_ _x8044 = kk_std_core_types__tuple2__unbox(_b_6739, _ctx); /*(list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>)*/
  kk_climate_dash_experiments__mlift5640_run__climate__model(burnin, pt, repeat__num, rs, sbrs, t__steps, _x8044, _ctx);
  return kk_unit_box(_x8043);
}


// lift anonymous function
struct kk_climate_dash_experiments_run__climate__model_fun8087__t {
  struct kk_function_s _base;
  kk_integer_t burnin;
  kk_std_core__list pre__data;
  kk_integer_t t__steps;
  kk_std_core_types__tuple2_ x_5771;
};
static kk_box_t kk_climate_dash_experiments_run__climate__model_fun8087(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__climate__model_fun8087(kk_integer_t burnin, kk_std_core__list pre__data, kk_integer_t t__steps, kk_std_core_types__tuple2_ x_5771, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__climate__model_fun8087__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__climate__model_fun8087__t, 6, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__climate__model_fun8087, kk_context());
  _self->burnin = burnin;
  _self->pre__data = pre__data;
  _self->t__steps = t__steps;
  _self->x_5771 = x_5771;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments_run__climate__model_fun8088__t {
  struct kk_function_s _base;
  kk_integer_t burnin;
  kk_std_core__list pre__data;
  kk_integer_t t__steps;
  kk_std_core_types__tuple2_ x_5771;
};
static kk_box_t kk_climate_dash_experiments_run__climate__model_fun8088(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__climate__model_fun8088(kk_integer_t burnin, kk_std_core__list pre__data, kk_integer_t t__steps, kk_std_core_types__tuple2_ x_5771, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__climate__model_fun8088__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__climate__model_fun8088__t, 6, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__climate__model_fun8088, kk_context());
  _self->burnin = burnin;
  _self->pre__data = pre__data;
  _self->t__steps = t__steps;
  _self->x_5771 = x_5771;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments_run__climate__model_fun8091__t {
  struct kk_function_s _base;
  kk_integer_t burnin;
  kk_integer_t t__steps;
  kk_std_core_types__tuple2_ x_5771;
};
static kk_box_t kk_climate_dash_experiments_run__climate__model_fun8091(kk_function_t _fself, kk_box_t _b_6901, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__climate__model_fun8091(kk_integer_t burnin, kk_integer_t t__steps, kk_std_core_types__tuple2_ x_5771, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__climate__model_fun8091__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__climate__model_fun8091__t, 5, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__climate__model_fun8091, kk_context());
  _self->burnin = burnin;
  _self->t__steps = t__steps;
  _self->x_5771 = x_5771;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments_run__climate__model_fun8097__t {
  struct kk_function_s _base;
  kk_integer_t burnin;
  kk_integer_t ind;
  kk_string_t name;
  kk_integer_t t__steps;
  kk_std_core_types__tuple2_ x_5771;
  double diff;
  double subtract;
};
static kk_box_t kk_climate_dash_experiments_run__climate__model_fun8097(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__climate__model_fun8097(kk_integer_t burnin, kk_integer_t ind, kk_string_t name, kk_integer_t t__steps, kk_std_core_types__tuple2_ x_5771, double diff, double subtract, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__climate__model_fun8097__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__climate__model_fun8097__t, 7, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__climate__model_fun8097, kk_context());
  _self->burnin = burnin;
  _self->ind = ind;
  _self->name = name;
  _self->t__steps = t__steps;
  _self->x_5771 = x_5771;
  _self->diff = diff;
  _self->subtract = subtract;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments_run__climate__model_fun8117__t {
  struct kk_function_s _base;
  size_t i0_5787;
};
static kk_box_t kk_climate_dash_experiments_run__climate__model_fun8117(kk_function_t _fself, kk_function_t _b_6885, kk_box_t _b_6886, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__climate__model_fun8117(size_t i0_5787, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__climate__model_fun8117__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__climate__model_fun8117__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__climate__model_fun8117, kk_context());
  _self->i0_5787 = i0_5787;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments_run__climate__model_fun8117(kk_function_t _fself, kk_function_t _b_6885, kk_box_t _b_6886, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__climate__model_fun8117__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__climate__model_fun8117__t*, _fself);
  size_t i0_5787 = _self->i0_5787; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i0_5787, _b_6885, _b_6886, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments_run__climate__model_fun8119__t {
  struct kk_function_s _base;
  kk_integer_t burnin;
  kk_integer_t ind;
  kk_string_t name;
  kk_integer_t t__steps;
  kk_std_core_types__tuple2_ x_5771;
  double diff;
  double subtract;
};
static kk_box_t kk_climate_dash_experiments_run__climate__model_fun8119(kk_function_t _fself, kk_box_t _b_6896, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__climate__model_fun8119(kk_integer_t burnin, kk_integer_t ind, kk_string_t name, kk_integer_t t__steps, kk_std_core_types__tuple2_ x_5771, double diff, double subtract, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__climate__model_fun8119__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__climate__model_fun8119__t, 7, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__climate__model_fun8119, kk_context());
  _self->burnin = burnin;
  _self->ind = ind;
  _self->name = name;
  _self->t__steps = t__steps;
  _self->x_5771 = x_5771;
  _self->diff = diff;
  _self->subtract = subtract;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments_run__climate__model_fun8119(kk_function_t _fself, kk_box_t _b_6896, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__climate__model_fun8119__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__climate__model_fun8119__t*, _fself);
  kk_integer_t burnin = _self->burnin; /* int */
  kk_integer_t ind = _self->ind; /* int */
  kk_string_t name = _self->name; /* string */
  kk_integer_t t__steps = _self->t__steps; /* int */
  kk_std_core_types__tuple2_ x_5771 = _self->x_5771; /* (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>) */
  double diff = _self->diff; /* double */
  double subtract = _self->subtract; /* double */
  kk_drop_match(_self, {kk_integer_dup(burnin);kk_integer_dup(ind);kk_string_dup(name);kk_integer_dup(t__steps);kk_std_core_types__tuple2__dup(x_5771);;;}, {}, _ctx)
  kk_unit_t _x8120 = kk_Unit;
  kk_std_core__list _x8121 = kk_std_core__list_unbox(_b_6896, _ctx); /*list<effects-and-types/row_vector>*/
  kk_climate_dash_experiments__mlift5638_run__climate__model(burnin, x_5771, diff, ind, name, subtract, t__steps, _x8121, _ctx);
  return kk_unit_box(_x8120);
}
static kk_box_t kk_climate_dash_experiments_run__climate__model_fun8097(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__climate__model_fun8097__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__climate__model_fun8097__t*, _fself);
  kk_integer_t burnin = _self->burnin; /* int */
  kk_integer_t ind = _self->ind; /* int */
  kk_string_t name = _self->name; /* string */
  kk_integer_t t__steps = _self->t__steps; /* int */
  kk_std_core_types__tuple2_ x_5771 = _self->x_5771; /* (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>) */
  double diff = _self->diff; /* double */
  double subtract = _self->subtract; /* double */
  kk_drop_match(_self, {kk_integer_dup(burnin);kk_integer_dup(ind);kk_string_dup(name);kk_integer_dup(t__steps);kk_std_core_types__tuple2__dup(x_5771);;;}, {}, _ctx)
  kk_unit_t _x8098 = kk_Unit;
  kk_std_core__list x1_5784;
  size_t i0_5787 = ((size_t)0); /*std/core/hnd/ev-index*/;
  kk_evv_t w0 = kk_evv_swap_create1(i0_5787,kk_context()); /*std/core/hnd/evv<<exn,div,effects-and-types/sample,fsys,console,ndet,std/num/random/random>>*/;
  kk_std_core__list y0;
  kk_std_core_types__maybe _match_7502;
  kk_std_core__list _x8099;
  kk_box_t _box_x6865 = x_5771.fst;
  kk_box_t _box_x6866 = x_5771.snd;
  kk_std_core__list _x = kk_std_core__list_unbox(_box_x6866, NULL);
  kk_std_core__list_dup(_x);
  _x8099 = _x; /*list<list<effects-and-types/row_vector>>*/
  kk_integer_t _x8102 = kk_integer_dup(ind); /*int*/
  _match_7502 = kk_std_core__lp__lb__rb__2_rp_(_x8099, _x8102, _ctx); /*maybe<1>*/
  if (kk_std_core_types__is_Nothing(_match_7502)) {
    kk_string_t message_205;
    kk_string_t _x8103;
    kk_define_string_literal(, _s8104, 48, "ListIndexError: Invalid list indexing at index: ")
    _x8103 = kk_string_dup(_s8104); /*string*/
    kk_string_t _x8105;
    kk_integer_t _x8106 = kk_integer_dup(ind); /*int*/
    _x8105 = kk_std_core_show(_x8106, _ctx); /*string*/
    message_205 = kk_std_core__lp__plus__plus__1_rp_(_x8103, _x8105, _ctx); /*string*/
    kk_std_core__exception exn_21561;
    kk_std_core__exception_info _x8107;
    kk_std_core_types__optional _match_7504 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
    if (kk_std_core_types__is_Optional(_match_7504)) {
      kk_box_t _box_x6867 = _match_7504._cons.Optional.value;
      kk_std_core__exception_info _info_14279 = kk_std_core__exception_info_unbox(_box_x6867, NULL);
      kk_std_core__exception_info_dup(_info_14279);
      kk_std_core_types__optional_drop(_match_7504, _ctx);
      _x8107 = _info_14279; /*exception-info*/
      goto _match8108;
    }
    _x8107 = kk_std_core__new_ExnError(_ctx); /*exception-info*/
    _match8108: ;
    exn_21561 = kk_std_core__new_Exception(message_205, _x8107, _ctx); /*exception*/
    kk_std_core_hnd__ev ev_21562;
    size_t _x8110 = ((size_t)0); /*size_t*/
    ev_21562 = kk_evv_at(_x8110,kk_context()); /*std/core/hnd/ev<.hnd-exn>*/
    kk_box_t _x8111;
    struct kk_std_core_hnd_Ev* _con8112 = kk_std_core_hnd__as_Ev(ev_21562);
    kk_std_core_hnd__marker m = _con8112->marker;
    kk_box_t _box_x6868 = _con8112->hnd;
    kk_std_core__hnd_exn h = kk_std_core__hnd_exn_unbox(_box_x6868, NULL);
    kk_std_core__hnd_exn_dup(h);
    kk_std_core_hnd__clause1 _match_7503;
    struct kk_std_core__Hnd_exn* _con8114 = kk_std_core__as_Hnd_exn(h);
    kk_std_core_hnd__clause1 except_throw_exn = _con8114->except_throw_exn;
    if (kk_std_core__hnd_exn_is_unique(h)) {
      kk_std_core__hnd_exn_free(h);
    }
    else {
      kk_std_core_hnd__clause1_dup(except_throw_exn);
      kk_std_core__hnd_exn_decref(h, _ctx);
    }
    _match_7503 = except_throw_exn; /*forall<a> std/core/hnd/clause1<exception,a,.hnd-exn,7,8>*/
    kk_function_t _fun_unbox_x6872 = _match_7503.clause;
    _x8111 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x6872, (_fun_unbox_x6872, m, ev_21562, kk_std_core__exception_box(exn_21561, _ctx), _ctx)); /*11*/
    y0 = kk_std_core__list_unbox(_x8111, _ctx); /*list<effects-and-types/row_vector>*/
  }
  else {
    kk_box_t _box_x6876 = _match_7502._cons.Just.value;
    kk_std_core__list x = kk_std_core__list_unbox(_box_x6876, NULL);
    kk_std_core__list_dup(x);
    kk_std_core_types__maybe_drop(_match_7502, _ctx);
    y0 = x; /*list<effects-and-types/row_vector>*/
  }
  kk_unit_t __w_l717_c9 = kk_Unit;
  kk_evv_set(w0,kk_context());
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(y0, _ctx);
    kk_box_t _x8116 = kk_std_core_hnd_yield_cont(kk_climate_dash_experiments_new_run__climate__model_fun8117(i0_5787, _ctx), _ctx); /*3*/
    x1_5784 = kk_std_core__list_unbox(_x8116, _ctx); /*list<effects-and-types/row_vector>*/
  }
  else {
    x1_5784 = y0; /*list<effects-and-types/row_vector>*/
  }
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x1_5784, _ctx);
    kk_box_t _x8118 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments_new_run__climate__model_fun8119(burnin, ind, name, t__steps, x_5771, diff, subtract, _ctx), _ctx); /*2*/
    kk_unit_unbox(_x8118);
  }
  else {
    kk_climate_dash_experiments__mlift5638_run__climate__model(burnin, x_5771, diff, ind, name, subtract, t__steps, x1_5784, _ctx);
  }
  return kk_unit_box(_x8098);
}
static kk_box_t kk_climate_dash_experiments_run__climate__model_fun8091(kk_function_t _fself, kk_box_t _b_6901, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__climate__model_fun8091__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__climate__model_fun8091__t*, _fself);
  kk_integer_t burnin = _self->burnin; /* int */
  kk_integer_t t__steps = _self->t__steps; /* int */
  kk_std_core_types__tuple2_ x_5771 = _self->x_5771; /* (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>) */
  kk_drop_match(_self, {kk_integer_dup(burnin);kk_integer_dup(t__steps);kk_std_core_types__tuple2__dup(x_5771);}, {}, _ctx)
  kk_std_core_types__tuple2_ _match_7499 = kk_std_core_types__tuple2__unbox(_b_6901, _ctx); /*(int, (double, double, string))*/;
  kk_box_t _box_x6860 = _match_7499.fst;
  kk_box_t _box_x6861 = _match_7499.snd;
  kk_integer_t ind = kk_integer_unbox(_box_x6860);
  kk_std_core_types__tuple3_ _pat20 = kk_std_core_types__tuple3__unbox(_box_x6861, NULL);
  kk_box_t _box_x6862 = _pat20.fst;
  kk_box_t _box_x6863 = _pat20.snd;
  kk_box_t _box_x6864 = _pat20.thd;
  double diff = kk_double_unbox(_box_x6862, NULL);
  double subtract = kk_double_unbox(_box_x6863, NULL);
  kk_string_t name = kk_string_unbox(_box_x6864);
  kk_integer_dup(ind);
  kk_string_dup(name);
  kk_std_core_types__tuple2__drop(_match_7499, _ctx);
  return kk_std_time_timer_print_elapsed(kk_climate_dash_experiments_new_run__climate__model_fun8097(burnin, ind, name, t__steps, x_5771, diff, subtract, _ctx), kk_std_core_types__new_None(_ctx), _ctx);
}
static kk_box_t kk_climate_dash_experiments_run__climate__model_fun8088(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__climate__model_fun8088__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__climate__model_fun8088__t*, _fself);
  kk_integer_t burnin = _self->burnin; /* int */
  kk_std_core__list pre__data = _self->pre__data; /* list<(double, double, string)> */
  kk_integer_t t__steps = _self->t__steps; /* int */
  kk_std_core_types__tuple2_ x_5771 = _self->x_5771; /* (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>) */
  kk_drop_match(_self, {kk_integer_dup(burnin);kk_std_core__list_dup(pre__data);kk_integer_dup(t__steps);kk_std_core_types__tuple2__dup(x_5771);}, {}, _ctx)
  kk_std_core__list _x8089;
  kk_std_core__list _b_6908_6899;
  kk_std_core__list _x8090 = kk_std_core__lift21053_list(kk_integer_from_small(0), kk_integer_from_small(11), kk_std_core__new_Nil(_ctx), _ctx); /*list<int>*/
  _b_6908_6899 = kk_std_core_zip(_x8090, pre__data, _ctx); /*list<(int, (double, double, string))>*/
  _x8089 = kk_std_core_map_5(_b_6908_6899, kk_climate_dash_experiments_new_run__climate__model_fun8091(burnin, t__steps, x_5771, _ctx), _ctx); /*list<2>*/
  return kk_std_core__list_box(_x8089, _ctx);
}
static kk_box_t kk_climate_dash_experiments_run__climate__model_fun8087(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__climate__model_fun8087__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__climate__model_fun8087__t*, _fself);
  kk_integer_t burnin = _self->burnin; /* int */
  kk_std_core__list pre__data = _self->pre__data; /* list<(double, double, string)> */
  kk_integer_t t__steps = _self->t__steps; /* int */
  kk_std_core_types__tuple2_ x_5771 = _self->x_5771; /* (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>) */
  kk_drop_match(_self, {kk_integer_dup(burnin);kk_std_core__list_dup(pre__data);kk_integer_dup(t__steps);kk_std_core_types__tuple2__dup(x_5771);}, {}, _ctx)
  return kk_handlers_random__sampler(kk_climate_dash_experiments_new_run__climate__model_fun8088(burnin, pre__data, t__steps, x_5771, _ctx), _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments_run__climate__model_fun8123__t {
  struct kk_function_s _base;
  kk_integer_t burnin;
  kk_std_core__list pre__data;
  kk_integer_t pt;
  kk_std_core_types__optional repeat__num;
  kk_integer_t rs;
  kk_integer_t sbrs;
  kk_integer_t t__steps;
  kk_std_core_types__tuple2_ x_5771;
};
static kk_box_t kk_climate_dash_experiments_run__climate__model_fun8123(kk_function_t _fself, kk_box_t _b_6916, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__climate__model_fun8123(kk_integer_t burnin, kk_std_core__list pre__data, kk_integer_t pt, kk_std_core_types__optional repeat__num, kk_integer_t rs, kk_integer_t sbrs, kk_integer_t t__steps, kk_std_core_types__tuple2_ x_5771, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__climate__model_fun8123__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__climate__model_fun8123__t, 11, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__climate__model_fun8123, kk_context());
  _self->burnin = burnin;
  _self->pre__data = pre__data;
  _self->pt = pt;
  _self->repeat__num = repeat__num;
  _self->rs = rs;
  _self->sbrs = sbrs;
  _self->t__steps = t__steps;
  _self->x_5771 = x_5771;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments_run__climate__model_fun8123(kk_function_t _fself, kk_box_t _b_6916, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__climate__model_fun8123__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__climate__model_fun8123__t*, _fself);
  kk_integer_t burnin = _self->burnin; /* int */
  kk_std_core__list pre__data = _self->pre__data; /* list<(double, double, string)> */
  kk_integer_t pt = _self->pt; /* int */
  kk_std_core_types__optional repeat__num = _self->repeat__num; /* optional<int> */
  kk_integer_t rs = _self->rs; /* int */
  kk_integer_t sbrs = _self->sbrs; /* int */
  kk_integer_t t__steps = _self->t__steps; /* int */
  kk_std_core_types__tuple2_ x_5771 = _self->x_5771; /* (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>) */
  kk_drop_match(_self, {kk_integer_dup(burnin);kk_std_core__list_dup(pre__data);kk_integer_dup(pt);kk_std_core_types__optional_dup(repeat__num);kk_integer_dup(rs);kk_integer_dup(sbrs);kk_integer_dup(t__steps);kk_std_core_types__tuple2__dup(x_5771);}, {}, _ctx)
  kk_unit_t _x8124 = kk_Unit;
  kk_std_core__list _x8125 = kk_std_core__list_unbox(_b_6916, _ctx); /*list<()>*/
  kk_climate_dash_experiments__mlift5639_run__climate__model(burnin, x_5771, pre__data, pt, repeat__num, rs, sbrs, t__steps, _x8125, _ctx);
  return kk_unit_box(_x8124);
}


// lift anonymous function
struct kk_climate_dash_experiments_run__climate__model_fun8130__t {
  struct kk_function_s _base;
  kk_integer_t burnin;
  kk_std_core__list pre__data;
  kk_integer_t t__steps;
  kk_std_core_types__tuple2_ x_5771;
};
static kk_box_t kk_climate_dash_experiments_run__climate__model_fun8130(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__climate__model_fun8130(kk_integer_t burnin, kk_std_core__list pre__data, kk_integer_t t__steps, kk_std_core_types__tuple2_ x_5771, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__climate__model_fun8130__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__climate__model_fun8130__t, 6, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__climate__model_fun8130, kk_context());
  _self->burnin = burnin;
  _self->pre__data = pre__data;
  _self->t__steps = t__steps;
  _self->x_5771 = x_5771;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments_run__climate__model_fun8131__t {
  struct kk_function_s _base;
  kk_integer_t burnin;
  kk_std_core__list pre__data;
  kk_integer_t t__steps;
  kk_std_core_types__tuple2_ x_5771;
};
static kk_box_t kk_climate_dash_experiments_run__climate__model_fun8131(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__climate__model_fun8131(kk_integer_t burnin, kk_std_core__list pre__data, kk_integer_t t__steps, kk_std_core_types__tuple2_ x_5771, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__climate__model_fun8131__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__climate__model_fun8131__t, 6, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__climate__model_fun8131, kk_context());
  _self->burnin = burnin;
  _self->pre__data = pre__data;
  _self->t__steps = t__steps;
  _self->x_5771 = x_5771;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments_run__climate__model_fun8134__t {
  struct kk_function_s _base;
  kk_integer_t burnin;
  kk_integer_t t__steps;
  kk_std_core_types__tuple2_ x_5771;
};
static kk_box_t kk_climate_dash_experiments_run__climate__model_fun8134(kk_function_t _fself, kk_box_t _b_6958, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__climate__model_fun8134(kk_integer_t burnin, kk_integer_t t__steps, kk_std_core_types__tuple2_ x_5771, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__climate__model_fun8134__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__climate__model_fun8134__t, 5, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__climate__model_fun8134, kk_context());
  _self->burnin = burnin;
  _self->t__steps = t__steps;
  _self->x_5771 = x_5771;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments_run__climate__model_fun8140__t {
  struct kk_function_s _base;
  kk_integer_t burnin;
  kk_integer_t ind0;
  kk_string_t name0;
  kk_integer_t t__steps;
  kk_std_core_types__tuple2_ x_5771;
  double diff0;
  double subtract0;
};
static kk_box_t kk_climate_dash_experiments_run__climate__model_fun8140(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__climate__model_fun8140(kk_integer_t burnin, kk_integer_t ind0, kk_string_t name0, kk_integer_t t__steps, kk_std_core_types__tuple2_ x_5771, double diff0, double subtract0, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__climate__model_fun8140__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__climate__model_fun8140__t, 7, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__climate__model_fun8140, kk_context());
  _self->burnin = burnin;
  _self->ind0 = ind0;
  _self->name0 = name0;
  _self->t__steps = t__steps;
  _self->x_5771 = x_5771;
  _self->diff0 = diff0;
  _self->subtract0 = subtract0;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments_run__climate__model_fun8160__t {
  struct kk_function_s _base;
  size_t i1_5801;
};
static kk_box_t kk_climate_dash_experiments_run__climate__model_fun8160(kk_function_t _fself, kk_function_t _b_6942, kk_box_t _b_6943, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__climate__model_fun8160(size_t i1_5801, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__climate__model_fun8160__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__climate__model_fun8160__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__climate__model_fun8160, kk_context());
  _self->i1_5801 = i1_5801;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments_run__climate__model_fun8160(kk_function_t _fself, kk_function_t _b_6942, kk_box_t _b_6943, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__climate__model_fun8160__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__climate__model_fun8160__t*, _fself);
  size_t i1_5801 = _self->i1_5801; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i1_5801, _b_6942, _b_6943, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments_run__climate__model_fun8162__t {
  struct kk_function_s _base;
  kk_integer_t burnin;
  kk_integer_t ind0;
  kk_string_t name0;
  kk_integer_t t__steps;
  kk_std_core_types__tuple2_ x_5771;
  double diff0;
  double subtract0;
};
static kk_box_t kk_climate_dash_experiments_run__climate__model_fun8162(kk_function_t _fself, kk_box_t _b_6953, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__climate__model_fun8162(kk_integer_t burnin, kk_integer_t ind0, kk_string_t name0, kk_integer_t t__steps, kk_std_core_types__tuple2_ x_5771, double diff0, double subtract0, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__climate__model_fun8162__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__climate__model_fun8162__t, 7, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__climate__model_fun8162, kk_context());
  _self->burnin = burnin;
  _self->ind0 = ind0;
  _self->name0 = name0;
  _self->t__steps = t__steps;
  _self->x_5771 = x_5771;
  _self->diff0 = diff0;
  _self->subtract0 = subtract0;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments_run__climate__model_fun8162(kk_function_t _fself, kk_box_t _b_6953, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__climate__model_fun8162__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__climate__model_fun8162__t*, _fself);
  kk_integer_t burnin = _self->burnin; /* int */
  kk_integer_t ind0 = _self->ind0; /* int */
  kk_string_t name0 = _self->name0; /* string */
  kk_integer_t t__steps = _self->t__steps; /* int */
  kk_std_core_types__tuple2_ x_5771 = _self->x_5771; /* (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>) */
  double diff0 = _self->diff0; /* double */
  double subtract0 = _self->subtract0; /* double */
  kk_drop_match(_self, {kk_integer_dup(burnin);kk_integer_dup(ind0);kk_string_dup(name0);kk_integer_dup(t__steps);kk_std_core_types__tuple2__dup(x_5771);;;}, {}, _ctx)
  kk_unit_t _x8163 = kk_Unit;
  kk_std_core__list _x8164 = kk_std_core__list_unbox(_b_6953, _ctx); /*list<effects-and-types/row_vector>*/
  kk_climate_dash_experiments__mlift5634_run__climate__model(burnin, x_5771, diff0, ind0, name0, subtract0, t__steps, _x8164, _ctx);
  return kk_unit_box(_x8163);
}
static kk_box_t kk_climate_dash_experiments_run__climate__model_fun8140(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__climate__model_fun8140__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__climate__model_fun8140__t*, _fself);
  kk_integer_t burnin = _self->burnin; /* int */
  kk_integer_t ind0 = _self->ind0; /* int */
  kk_string_t name0 = _self->name0; /* string */
  kk_integer_t t__steps = _self->t__steps; /* int */
  kk_std_core_types__tuple2_ x_5771 = _self->x_5771; /* (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>) */
  double diff0 = _self->diff0; /* double */
  double subtract0 = _self->subtract0; /* double */
  kk_drop_match(_self, {kk_integer_dup(burnin);kk_integer_dup(ind0);kk_string_dup(name0);kk_integer_dup(t__steps);kk_std_core_types__tuple2__dup(x_5771);;;}, {}, _ctx)
  kk_unit_t _x8141 = kk_Unit;
  kk_std_core__list x4_5798;
  size_t i1_5801 = ((size_t)0); /*std/core/hnd/ev-index*/;
  kk_evv_t w1 = kk_evv_swap_create1(i1_5801,kk_context()); /*std/core/hnd/evv<<exn,div,effects-and-types/sample,fsys,console,ndet,std/num/random/random>>*/;
  kk_std_core__list y1;
  kk_std_core_types__maybe _match_7496;
  kk_std_core__list _x8142;
  kk_box_t _box_x6922 = x_5771.fst;
  kk_box_t _box_x6923 = x_5771.snd;
  kk_std_core__list _x0 = kk_std_core__list_unbox(_box_x6923, NULL);
  kk_std_core__list_dup(_x0);
  _x8142 = _x0; /*list<list<effects-and-types/row_vector>>*/
  kk_integer_t _x8145 = kk_integer_dup(ind0); /*int*/
  _match_7496 = kk_std_core__lp__lb__rb__2_rp_(_x8142, _x8145, _ctx); /*maybe<1>*/
  if (kk_std_core_types__is_Nothing(_match_7496)) {
    kk_string_t message_2050;
    kk_string_t _x8146;
    kk_define_string_literal(, _s8147, 48, "ListIndexError: Invalid list indexing at index: ")
    _x8146 = kk_string_dup(_s8147); /*string*/
    kk_string_t _x8148;
    kk_integer_t _x8149 = kk_integer_dup(ind0); /*int*/
    _x8148 = kk_std_core_show(_x8149, _ctx); /*string*/
    message_2050 = kk_std_core__lp__plus__plus__1_rp_(_x8146, _x8148, _ctx); /*string*/
    kk_std_core__exception exn_215610;
    kk_std_core__exception_info _x8150;
    kk_std_core_types__optional _match_7498 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
    if (kk_std_core_types__is_Optional(_match_7498)) {
      kk_box_t _box_x6924 = _match_7498._cons.Optional.value;
      kk_std_core__exception_info _info_142790 = kk_std_core__exception_info_unbox(_box_x6924, NULL);
      kk_std_core__exception_info_dup(_info_142790);
      kk_std_core_types__optional_drop(_match_7498, _ctx);
      _x8150 = _info_142790; /*exception-info*/
      goto _match8151;
    }
    _x8150 = kk_std_core__new_ExnError(_ctx); /*exception-info*/
    _match8151: ;
    exn_215610 = kk_std_core__new_Exception(message_2050, _x8150, _ctx); /*exception*/
    kk_std_core_hnd__ev ev_215620;
    size_t _x8153 = ((size_t)0); /*size_t*/
    ev_215620 = kk_evv_at(_x8153,kk_context()); /*std/core/hnd/ev<.hnd-exn>*/
    kk_box_t _x8154;
    struct kk_std_core_hnd_Ev* _con8155 = kk_std_core_hnd__as_Ev(ev_215620);
    kk_std_core_hnd__marker m0 = _con8155->marker;
    kk_box_t _box_x6925 = _con8155->hnd;
    kk_std_core__hnd_exn h0 = kk_std_core__hnd_exn_unbox(_box_x6925, NULL);
    kk_std_core__hnd_exn_dup(h0);
    kk_std_core_hnd__clause1 _match_7497;
    struct kk_std_core__Hnd_exn* _con8157 = kk_std_core__as_Hnd_exn(h0);
    kk_std_core_hnd__clause1 except_throw_exn0 = _con8157->except_throw_exn;
    if (kk_std_core__hnd_exn_is_unique(h0)) {
      kk_std_core__hnd_exn_free(h0);
    }
    else {
      kk_std_core_hnd__clause1_dup(except_throw_exn0);
      kk_std_core__hnd_exn_decref(h0, _ctx);
    }
    _match_7497 = except_throw_exn0; /*forall<a> std/core/hnd/clause1<exception,a,.hnd-exn,7,8>*/
    kk_function_t _fun_unbox_x6929 = _match_7497.clause;
    _x8154 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x6929, (_fun_unbox_x6929, m0, ev_215620, kk_std_core__exception_box(exn_215610, _ctx), _ctx)); /*11*/
    y1 = kk_std_core__list_unbox(_x8154, _ctx); /*list<effects-and-types/row_vector>*/
  }
  else {
    kk_box_t _box_x6933 = _match_7496._cons.Just.value;
    kk_std_core__list x0 = kk_std_core__list_unbox(_box_x6933, NULL);
    kk_std_core__list_dup(x0);
    kk_std_core_types__maybe_drop(_match_7496, _ctx);
    y1 = x0; /*list<effects-and-types/row_vector>*/
  }
  kk_unit_t __w_l717_c90 = kk_Unit;
  kk_evv_set(w1,kk_context());
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(y1, _ctx);
    kk_box_t _x8159 = kk_std_core_hnd_yield_cont(kk_climate_dash_experiments_new_run__climate__model_fun8160(i1_5801, _ctx), _ctx); /*3*/
    x4_5798 = kk_std_core__list_unbox(_x8159, _ctx); /*list<effects-and-types/row_vector>*/
  }
  else {
    x4_5798 = y1; /*list<effects-and-types/row_vector>*/
  }
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x4_5798, _ctx);
    kk_box_t _x8161 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments_new_run__climate__model_fun8162(burnin, ind0, name0, t__steps, x_5771, diff0, subtract0, _ctx), _ctx); /*2*/
    kk_unit_unbox(_x8161);
  }
  else {
    kk_climate_dash_experiments__mlift5634_run__climate__model(burnin, x_5771, diff0, ind0, name0, subtract0, t__steps, x4_5798, _ctx);
  }
  return kk_unit_box(_x8141);
}
static kk_box_t kk_climate_dash_experiments_run__climate__model_fun8134(kk_function_t _fself, kk_box_t _b_6958, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__climate__model_fun8134__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__climate__model_fun8134__t*, _fself);
  kk_integer_t burnin = _self->burnin; /* int */
  kk_integer_t t__steps = _self->t__steps; /* int */
  kk_std_core_types__tuple2_ x_5771 = _self->x_5771; /* (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>) */
  kk_drop_match(_self, {kk_integer_dup(burnin);kk_integer_dup(t__steps);kk_std_core_types__tuple2__dup(x_5771);}, {}, _ctx)
  kk_std_core_types__tuple2_ _match_7493 = kk_std_core_types__tuple2__unbox(_b_6958, _ctx); /*(int, (double, double, string))*/;
  kk_box_t _box_x6917 = _match_7493.fst;
  kk_box_t _box_x6918 = _match_7493.snd;
  kk_integer_t ind0 = kk_integer_unbox(_box_x6917);
  kk_std_core_types__tuple3_ _pat400 = kk_std_core_types__tuple3__unbox(_box_x6918, NULL);
  kk_box_t _box_x6919 = _pat400.fst;
  kk_box_t _box_x6920 = _pat400.snd;
  kk_box_t _box_x6921 = _pat400.thd;
  double diff0 = kk_double_unbox(_box_x6919, NULL);
  double subtract0 = kk_double_unbox(_box_x6920, NULL);
  kk_string_t name0 = kk_string_unbox(_box_x6921);
  kk_integer_dup(ind0);
  kk_string_dup(name0);
  kk_std_core_types__tuple2__drop(_match_7493, _ctx);
  return kk_std_time_timer_print_elapsed(kk_climate_dash_experiments_new_run__climate__model_fun8140(burnin, ind0, name0, t__steps, x_5771, diff0, subtract0, _ctx), kk_std_core_types__new_None(_ctx), _ctx);
}
static kk_box_t kk_climate_dash_experiments_run__climate__model_fun8131(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__climate__model_fun8131__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__climate__model_fun8131__t*, _fself);
  kk_integer_t burnin = _self->burnin; /* int */
  kk_std_core__list pre__data = _self->pre__data; /* list<(double, double, string)> */
  kk_integer_t t__steps = _self->t__steps; /* int */
  kk_std_core_types__tuple2_ x_5771 = _self->x_5771; /* (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>) */
  kk_drop_match(_self, {kk_integer_dup(burnin);kk_std_core__list_dup(pre__data);kk_integer_dup(t__steps);kk_std_core_types__tuple2__dup(x_5771);}, {}, _ctx)
  kk_std_core__list _x8132;
  kk_std_core__list _b_6965_6956;
  kk_std_core__list _x8133 = kk_std_core__lift21053_list(kk_integer_from_small(0), kk_integer_from_small(11), kk_std_core__new_Nil(_ctx), _ctx); /*list<int>*/
  _b_6965_6956 = kk_std_core_zip(_x8133, pre__data, _ctx); /*list<(int, (double, double, string))>*/
  _x8132 = kk_std_core_map_5(_b_6965_6956, kk_climate_dash_experiments_new_run__climate__model_fun8134(burnin, t__steps, x_5771, _ctx), _ctx); /*list<2>*/
  return kk_std_core__list_box(_x8132, _ctx);
}
static kk_box_t kk_climate_dash_experiments_run__climate__model_fun8130(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__climate__model_fun8130__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__climate__model_fun8130__t*, _fself);
  kk_integer_t burnin = _self->burnin; /* int */
  kk_std_core__list pre__data = _self->pre__data; /* list<(double, double, string)> */
  kk_integer_t t__steps = _self->t__steps; /* int */
  kk_std_core_types__tuple2_ x_5771 = _self->x_5771; /* (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>) */
  kk_drop_match(_self, {kk_integer_dup(burnin);kk_std_core__list_dup(pre__data);kk_integer_dup(t__steps);kk_std_core_types__tuple2__dup(x_5771);}, {}, _ctx)
  return kk_handlers_random__sampler(kk_climate_dash_experiments_new_run__climate__model_fun8131(burnin, pre__data, t__steps, x_5771, _ctx), _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments_run__climate__model_fun8166__t {
  struct kk_function_s _base;
  kk_std_core__list pre__data;
  kk_integer_t pt;
  kk_std_core_types__optional repeat__num;
  kk_integer_t rs;
  kk_integer_t sbrs;
  kk_std_core_types__tuple2_ x_5771;
};
static kk_box_t kk_climate_dash_experiments_run__climate__model_fun8166(kk_function_t _fself, kk_box_t _b_6973, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__climate__model_fun8166(kk_std_core__list pre__data, kk_integer_t pt, kk_std_core_types__optional repeat__num, kk_integer_t rs, kk_integer_t sbrs, kk_std_core_types__tuple2_ x_5771, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__climate__model_fun8166__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__climate__model_fun8166__t, 9, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__climate__model_fun8166, kk_context());
  _self->pre__data = pre__data;
  _self->pt = pt;
  _self->repeat__num = repeat__num;
  _self->rs = rs;
  _self->sbrs = sbrs;
  _self->x_5771 = x_5771;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments_run__climate__model_fun8166(kk_function_t _fself, kk_box_t _b_6973, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__climate__model_fun8166__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__climate__model_fun8166__t*, _fself);
  kk_std_core__list pre__data = _self->pre__data; /* list<(double, double, string)> */
  kk_integer_t pt = _self->pt; /* int */
  kk_std_core_types__optional repeat__num = _self->repeat__num; /* optional<int> */
  kk_integer_t rs = _self->rs; /* int */
  kk_integer_t sbrs = _self->sbrs; /* int */
  kk_std_core_types__tuple2_ x_5771 = _self->x_5771; /* (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>) */
  kk_drop_match(_self, {kk_std_core__list_dup(pre__data);kk_integer_dup(pt);kk_std_core_types__optional_dup(repeat__num);kk_integer_dup(rs);kk_integer_dup(sbrs);kk_std_core_types__tuple2__dup(x_5771);}, {}, _ctx)
  kk_unit_t _x8167 = kk_Unit;
  kk_std_core__list _x8168 = kk_std_core__list_unbox(_b_6973, _ctx); /*list<()>*/
  kk_climate_dash_experiments__mlift5635_run__climate__model(x_5771, pre__data, pt, repeat__num, rs, sbrs, _x8168, _ctx);
  return kk_unit_box(_x8167);
}


// lift anonymous function
struct kk_climate_dash_experiments_run__climate__model_fun8169__t {
  struct kk_function_s _base;
  kk_std_core__list pre__data;
  kk_integer_t pt;
  kk_std_core_types__optional repeat__num;
  kk_integer_t rs;
  kk_integer_t sbrs;
  kk_std_core_types__tuple2_ x_5771;
};
static kk_box_t kk_climate_dash_experiments_run__climate__model_fun8169(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__climate__model_fun8169(kk_std_core__list pre__data, kk_integer_t pt, kk_std_core_types__optional repeat__num, kk_integer_t rs, kk_integer_t sbrs, kk_std_core_types__tuple2_ x_5771, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__climate__model_fun8169__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__climate__model_fun8169__t, 9, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__climate__model_fun8169, kk_context());
  _self->pre__data = pre__data;
  _self->pt = pt;
  _self->repeat__num = repeat__num;
  _self->rs = rs;
  _self->sbrs = sbrs;
  _self->x_5771 = x_5771;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments_run__climate__model_fun8174__t {
  struct kk_function_s _base;
  kk_integer_t pt;
  kk_std_core_types__optional repeat__num;
  kk_integer_t rs;
  kk_integer_t sbrs;
  kk_std_core_types__tuple2_ x_5771;
};
static kk_box_t kk_climate_dash_experiments_run__climate__model_fun8174(kk_function_t _fself, kk_box_t _b_7016, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__climate__model_fun8174(kk_integer_t pt, kk_std_core_types__optional repeat__num, kk_integer_t rs, kk_integer_t sbrs, kk_std_core_types__tuple2_ x_5771, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__climate__model_fun8174__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__climate__model_fun8174__t, 8, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__climate__model_fun8174, kk_context());
  _self->pt = pt;
  _self->repeat__num = repeat__num;
  _self->rs = rs;
  _self->sbrs = sbrs;
  _self->x_5771 = x_5771;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments_run__climate__model_fun8176__t {
  struct kk_function_s _base;
  kk_box_t _b_7016;
  kk_integer_t pt;
  kk_integer_t rs;
  kk_integer_t sbrs;
  kk_std_core_types__tuple2_ x_5771;
};
static kk_unit_t kk_climate_dash_experiments_run__climate__model_fun8176(kk_function_t _fself, kk_integer_t repeat__ind, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__climate__model_fun8176(kk_box_t _b_7016, kk_integer_t pt, kk_integer_t rs, kk_integer_t sbrs, kk_std_core_types__tuple2_ x_5771, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__climate__model_fun8176__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__climate__model_fun8176__t, 7, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__climate__model_fun8176, kk_context());
  _self->_b_7016 = _b_7016;
  _self->pt = pt;
  _self->rs = rs;
  _self->sbrs = sbrs;
  _self->x_5771 = x_5771;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments_run__climate__model_fun8183__t {
  struct kk_function_s _base;
  kk_integer_t ind1;
  kk_string_t name1;
  kk_integer_t pt;
  kk_integer_t repeat__ind;
  kk_integer_t rs;
  kk_integer_t sbrs;
  kk_std_core_types__tuple2_ x_5771;
  double diff1;
  double subtract1;
};
static kk_box_t kk_climate_dash_experiments_run__climate__model_fun8183(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__climate__model_fun8183(kk_integer_t ind1, kk_string_t name1, kk_integer_t pt, kk_integer_t repeat__ind, kk_integer_t rs, kk_integer_t sbrs, kk_std_core_types__tuple2_ x_5771, double diff1, double subtract1, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__climate__model_fun8183__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__climate__model_fun8183__t, 9, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__climate__model_fun8183, kk_context());
  _self->ind1 = ind1;
  _self->name1 = name1;
  _self->pt = pt;
  _self->repeat__ind = repeat__ind;
  _self->rs = rs;
  _self->sbrs = sbrs;
  _self->x_5771 = x_5771;
  _self->diff1 = diff1;
  _self->subtract1 = subtract1;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments_run__climate__model_fun8203__t {
  struct kk_function_s _base;
  size_t i2_5817;
};
static kk_box_t kk_climate_dash_experiments_run__climate__model_fun8203(kk_function_t _fself, kk_function_t _b_6999, kk_box_t _b_7000, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__climate__model_fun8203(size_t i2_5817, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__climate__model_fun8203__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__climate__model_fun8203__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__climate__model_fun8203, kk_context());
  _self->i2_5817 = i2_5817;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments_run__climate__model_fun8203(kk_function_t _fself, kk_function_t _b_6999, kk_box_t _b_7000, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__climate__model_fun8203__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__climate__model_fun8203__t*, _fself);
  size_t i2_5817 = _self->i2_5817; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i2_5817, _b_6999, _b_7000, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments_run__climate__model_fun8205__t {
  struct kk_function_s _base;
  kk_integer_t ind1;
  kk_string_t name1;
  kk_integer_t pt;
  kk_integer_t repeat__ind;
  kk_integer_t rs;
  kk_integer_t sbrs;
  kk_std_core_types__tuple2_ x_5771;
  double diff1;
  double subtract1;
};
static kk_box_t kk_climate_dash_experiments_run__climate__model_fun8205(kk_function_t _fself, kk_box_t _b_7010, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__climate__model_fun8205(kk_integer_t ind1, kk_string_t name1, kk_integer_t pt, kk_integer_t repeat__ind, kk_integer_t rs, kk_integer_t sbrs, kk_std_core_types__tuple2_ x_5771, double diff1, double subtract1, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__climate__model_fun8205__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__climate__model_fun8205__t, 9, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__climate__model_fun8205, kk_context());
  _self->ind1 = ind1;
  _self->name1 = name1;
  _self->pt = pt;
  _self->repeat__ind = repeat__ind;
  _self->rs = rs;
  _self->sbrs = sbrs;
  _self->x_5771 = x_5771;
  _self->diff1 = diff1;
  _self->subtract1 = subtract1;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments_run__climate__model_fun8205(kk_function_t _fself, kk_box_t _b_7010, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__climate__model_fun8205__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__climate__model_fun8205__t*, _fself);
  kk_integer_t ind1 = _self->ind1; /* int */
  kk_string_t name1 = _self->name1; /* string */
  kk_integer_t pt = _self->pt; /* int */
  kk_integer_t repeat__ind = _self->repeat__ind; /* int */
  kk_integer_t rs = _self->rs; /* int */
  kk_integer_t sbrs = _self->sbrs; /* int */
  kk_std_core_types__tuple2_ x_5771 = _self->x_5771; /* (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>) */
  double diff1 = _self->diff1; /* double */
  double subtract1 = _self->subtract1; /* double */
  kk_drop_match(_self, {kk_integer_dup(ind1);kk_string_dup(name1);kk_integer_dup(pt);kk_integer_dup(repeat__ind);kk_integer_dup(rs);kk_integer_dup(sbrs);kk_std_core_types__tuple2__dup(x_5771);;;}, {}, _ctx)
  kk_unit_t _x8206 = kk_Unit;
  kk_std_core__list _x8207 = kk_std_core__list_unbox(_b_7010, _ctx); /*list<effects-and-types/row_vector>*/
  kk_climate_dash_experiments__mlift5630_run__climate__model(x_5771, diff1, ind1, name1, pt, repeat__ind, rs, sbrs, subtract1, _x8207, _ctx);
  return kk_unit_box(_x8206);
}
static kk_box_t kk_climate_dash_experiments_run__climate__model_fun8183(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__climate__model_fun8183__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__climate__model_fun8183__t*, _fself);
  kk_integer_t ind1 = _self->ind1; /* int */
  kk_string_t name1 = _self->name1; /* string */
  kk_integer_t pt = _self->pt; /* int */
  kk_integer_t repeat__ind = _self->repeat__ind; /* int */
  kk_integer_t rs = _self->rs; /* int */
  kk_integer_t sbrs = _self->sbrs; /* int */
  kk_std_core_types__tuple2_ x_5771 = _self->x_5771; /* (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>) */
  double diff1 = _self->diff1; /* double */
  double subtract1 = _self->subtract1; /* double */
  kk_drop_match(_self, {kk_integer_dup(ind1);kk_string_dup(name1);kk_integer_dup(pt);kk_integer_dup(repeat__ind);kk_integer_dup(rs);kk_integer_dup(sbrs);kk_std_core_types__tuple2__dup(x_5771);;;}, {}, _ctx)
  kk_unit_t _x8184 = kk_Unit;
  kk_std_core__list x6_5814;
  size_t i2_5817 = ((size_t)0); /*std/core/hnd/ev-index*/;
  kk_evv_t w2 = kk_evv_swap_create1(i2_5817,kk_context()); /*std/core/hnd/evv<<exn,div,std/num/random/random,fsys,console,ndet>>*/;
  kk_std_core__list y2;
  kk_std_core_types__maybe _match_7490;
  kk_std_core__list _x8185;
  kk_box_t _box_x6979 = x_5771.fst;
  kk_box_t _box_x6980 = x_5771.snd;
  kk_std_core__list _x2 = kk_std_core__list_unbox(_box_x6980, NULL);
  kk_std_core__list_dup(_x2);
  _x8185 = _x2; /*list<list<effects-and-types/row_vector>>*/
  kk_integer_t _x8188 = kk_integer_dup(ind1); /*int*/
  _match_7490 = kk_std_core__lp__lb__rb__2_rp_(_x8185, _x8188, _ctx); /*maybe<1>*/
  if (kk_std_core_types__is_Nothing(_match_7490)) {
    kk_string_t message_2051;
    kk_string_t _x8189;
    kk_define_string_literal(, _s8190, 48, "ListIndexError: Invalid list indexing at index: ")
    _x8189 = kk_string_dup(_s8190); /*string*/
    kk_string_t _x8191;
    kk_integer_t _x8192 = kk_integer_dup(ind1); /*int*/
    _x8191 = kk_std_core_show(_x8192, _ctx); /*string*/
    message_2051 = kk_std_core__lp__plus__plus__1_rp_(_x8189, _x8191, _ctx); /*string*/
    kk_std_core__exception exn_215611;
    kk_std_core__exception_info _x8193;
    kk_std_core_types__optional _match_7492 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
    if (kk_std_core_types__is_Optional(_match_7492)) {
      kk_box_t _box_x6981 = _match_7492._cons.Optional.value;
      kk_std_core__exception_info _info_142791 = kk_std_core__exception_info_unbox(_box_x6981, NULL);
      kk_std_core__exception_info_dup(_info_142791);
      kk_std_core_types__optional_drop(_match_7492, _ctx);
      _x8193 = _info_142791; /*exception-info*/
      goto _match8194;
    }
    _x8193 = kk_std_core__new_ExnError(_ctx); /*exception-info*/
    _match8194: ;
    exn_215611 = kk_std_core__new_Exception(message_2051, _x8193, _ctx); /*exception*/
    kk_std_core_hnd__ev ev_215621;
    size_t _x8196 = ((size_t)0); /*size_t*/
    ev_215621 = kk_evv_at(_x8196,kk_context()); /*std/core/hnd/ev<.hnd-exn>*/
    kk_box_t _x8197;
    struct kk_std_core_hnd_Ev* _con8198 = kk_std_core_hnd__as_Ev(ev_215621);
    kk_std_core_hnd__marker m1 = _con8198->marker;
    kk_box_t _box_x6982 = _con8198->hnd;
    kk_std_core__hnd_exn h1 = kk_std_core__hnd_exn_unbox(_box_x6982, NULL);
    kk_std_core__hnd_exn_dup(h1);
    kk_std_core_hnd__clause1 _match_7491;
    struct kk_std_core__Hnd_exn* _con8200 = kk_std_core__as_Hnd_exn(h1);
    kk_std_core_hnd__clause1 except_throw_exn1 = _con8200->except_throw_exn;
    if (kk_std_core__hnd_exn_is_unique(h1)) {
      kk_std_core__hnd_exn_free(h1);
    }
    else {
      kk_std_core_hnd__clause1_dup(except_throw_exn1);
      kk_std_core__hnd_exn_decref(h1, _ctx);
    }
    _match_7491 = except_throw_exn1; /*forall<a> std/core/hnd/clause1<exception,a,.hnd-exn,7,8>*/
    kk_function_t _fun_unbox_x6986 = _match_7491.clause;
    _x8197 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x6986, (_fun_unbox_x6986, m1, ev_215621, kk_std_core__exception_box(exn_215611, _ctx), _ctx)); /*11*/
    y2 = kk_std_core__list_unbox(_x8197, _ctx); /*list<effects-and-types/row_vector>*/
  }
  else {
    kk_box_t _box_x6990 = _match_7490._cons.Just.value;
    kk_std_core__list x1 = kk_std_core__list_unbox(_box_x6990, NULL);
    kk_std_core__list_dup(x1);
    kk_std_core_types__maybe_drop(_match_7490, _ctx);
    y2 = x1; /*list<effects-and-types/row_vector>*/
  }
  kk_unit_t __w_l717_c91 = kk_Unit;
  kk_evv_set(w2,kk_context());
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(y2, _ctx);
    kk_box_t _x8202 = kk_std_core_hnd_yield_cont(kk_climate_dash_experiments_new_run__climate__model_fun8203(i2_5817, _ctx), _ctx); /*3*/
    x6_5814 = kk_std_core__list_unbox(_x8202, _ctx); /*list<effects-and-types/row_vector>*/
  }
  else {
    x6_5814 = y2; /*list<effects-and-types/row_vector>*/
  }
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x6_5814, _ctx);
    kk_box_t _x8204 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments_new_run__climate__model_fun8205(ind1, name1, pt, repeat__ind, rs, sbrs, x_5771, diff1, subtract1, _ctx), _ctx); /*2*/
    kk_unit_unbox(_x8204);
  }
  else {
    kk_climate_dash_experiments__mlift5630_run__climate__model(x_5771, diff1, ind1, name1, pt, repeat__ind, rs, sbrs, subtract1, x6_5814, _ctx);
  }
  return kk_unit_box(_x8184);
}
static kk_unit_t kk_climate_dash_experiments_run__climate__model_fun8176(kk_function_t _fself, kk_integer_t repeat__ind, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__climate__model_fun8176__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__climate__model_fun8176__t*, _fself);
  kk_box_t _b_7016 = _self->_b_7016; /* 1 */
  kk_integer_t pt = _self->pt; /* int */
  kk_integer_t rs = _self->rs; /* int */
  kk_integer_t sbrs = _self->sbrs; /* int */
  kk_std_core_types__tuple2_ x_5771 = _self->x_5771; /* (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>) */
  kk_drop_match(_self, {kk_box_dup(_b_7016);kk_integer_dup(pt);kk_integer_dup(rs);kk_integer_dup(sbrs);kk_std_core_types__tuple2__dup(x_5771);}, {}, _ctx)
  kk_box_t _x8177;
  kk_std_core_types__tuple2_ _match_7487 = kk_std_core_types__tuple2__unbox(_b_7016, _ctx); /*(int, (double, double, string))*/;
  kk_box_t _box_x6974 = _match_7487.fst;
  kk_box_t _box_x6975 = _match_7487.snd;
  kk_integer_t ind1 = kk_integer_unbox(_box_x6974);
  kk_std_core_types__tuple3_ _pat600 = kk_std_core_types__tuple3__unbox(_box_x6975, NULL);
  kk_box_t _box_x6976 = _pat600.fst;
  kk_box_t _box_x6977 = _pat600.snd;
  kk_box_t _box_x6978 = _pat600.thd;
  double diff1 = kk_double_unbox(_box_x6976, NULL);
  double subtract1 = kk_double_unbox(_box_x6977, NULL);
  kk_string_t name1 = kk_string_unbox(_box_x6978);
  kk_integer_dup(ind1);
  kk_string_dup(name1);
  kk_std_core_types__tuple2__drop(_match_7487, _ctx);
  _x8177 = kk_std_time_timer_print_elapsed(kk_climate_dash_experiments_new_run__climate__model_fun8183(ind1, name1, pt, repeat__ind, rs, sbrs, x_5771, diff1, subtract1, _ctx), kk_std_core_types__new_None(_ctx), _ctx); /*0*/
  return kk_unit_unbox(_x8177);
}
static kk_box_t kk_climate_dash_experiments_run__climate__model_fun8174(kk_function_t _fself, kk_box_t _b_7016, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__climate__model_fun8174__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__climate__model_fun8174__t*, _fself);
  kk_integer_t pt = _self->pt; /* int */
  kk_std_core_types__optional repeat__num = _self->repeat__num; /* optional<int> */
  kk_integer_t rs = _self->rs; /* int */
  kk_integer_t sbrs = _self->sbrs; /* int */
  kk_std_core_types__tuple2_ x_5771 = _self->x_5771; /* (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>) */
  kk_drop_match(_self, {kk_integer_dup(pt);kk_std_core_types__optional_dup(repeat__num);kk_integer_dup(rs);kk_integer_dup(sbrs);kk_std_core_types__tuple2__dup(x_5771);}, {}, _ctx)
  kk_unit_t _x8175 = kk_Unit;
  kk_integer_t _x8208;
  if (kk_std_core_types__is_Optional(repeat__num)) {
    kk_box_t _box_x7013 = repeat__num._cons.Optional.value;
    kk_integer_t _repeat__num_20 = kk_integer_unbox(_box_x7013);
    kk_integer_dup(_repeat__num_20);
    kk_std_core_types__optional_drop(repeat__num, _ctx);
    _x8208 = _repeat__num_20; /*int*/
    goto _match8209;
  }
  _x8208 = kk_integer_from_small(8); /*int*/
  _match8209: ;
  kk_std_core__lift21056_for(kk_climate_dash_experiments_new_run__climate__model_fun8176(_b_7016, pt, rs, sbrs, x_5771, _ctx), _x8208, kk_integer_from_small(1), _ctx);
  return kk_unit_box(_x8175);
}


// lift anonymous function
struct kk_climate_dash_experiments_run__climate__model_fun8212__t {
  struct kk_function_s _base;
};
static kk_box_t kk_climate_dash_experiments_run__climate__model_fun8212(kk_function_t _fself, kk_box_t _b_7025, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__climate__model_fun8212(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_climate_dash_experiments_run__climate__model_fun8212, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_climate_dash_experiments_run__climate__model_fun8212(kk_function_t _fself, kk_box_t _b_7025, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_unit_t _x8213 = kk_Unit;
  kk_std_core__list _x8214 = kk_std_core__list_unbox(_b_7025, _ctx); /*list<()>*/
  kk_climate_dash_experiments__mlift5631_run__climate__model(_x8214, _ctx);
  return kk_unit_box(_x8213);
}
static kk_box_t kk_climate_dash_experiments_run__climate__model_fun8169(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__climate__model_fun8169__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__climate__model_fun8169__t*, _fself);
  kk_std_core__list pre__data = _self->pre__data; /* list<(double, double, string)> */
  kk_integer_t pt = _self->pt; /* int */
  kk_std_core_types__optional repeat__num = _self->repeat__num; /* optional<int> */
  kk_integer_t rs = _self->rs; /* int */
  kk_integer_t sbrs = _self->sbrs; /* int */
  kk_std_core_types__tuple2_ x_5771 = _self->x_5771; /* (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>) */
  kk_drop_match(_self, {kk_std_core__list_dup(pre__data);kk_integer_dup(pt);kk_std_core_types__optional_dup(repeat__num);kk_integer_dup(rs);kk_integer_dup(sbrs);kk_std_core_types__tuple2__dup(x_5771);}, {}, _ctx)
  kk_unit_t _x8170 = kk_Unit;
  kk_unit_t __4 = kk_Unit;
  kk_string_t _x8171;
  kk_define_string_literal(, _s8172, 23, "Beginning to start SMC:")
  _x8171 = kk_string_dup(_s8172); /*string*/
  kk_std_core_printsln(_x8171, _ctx);
  kk_std_core__list x5_5807;
  kk_std_core__list _b_7017_7014;
  kk_std_core__list _x8173 = kk_std_core__lift21053_list(kk_integer_from_small(0), kk_integer_from_small(11), kk_std_core__new_Nil(_ctx), _ctx); /*list<int>*/
  _b_7017_7014 = kk_std_core_zip(_x8173, pre__data, _ctx); /*list<(int, (double, double, string))>*/
  x5_5807 = kk_std_core_map_5(_b_7017_7014, kk_climate_dash_experiments_new_run__climate__model_fun8174(pt, repeat__num, rs, sbrs, x_5771, _ctx), _ctx); /*list<()>*/
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x5_5807, _ctx);
    kk_box_t _x8211 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments_new_run__climate__model_fun8212(_ctx), _ctx); /*2*/
    kk_unit_unbox(_x8211);
  }
  else {
    kk_climate_dash_experiments__mlift5631_run__climate__model(x5_5807, _ctx);
  }
  return kk_unit_box(_x8170);
}

kk_unit_t kk_climate_dash_experiments_run__climate__model(kk_integer_t pt, kk_integer_t rs, kk_integer_t sbrs, kk_integer_t t__steps, kk_integer_t burnin, kk_std_core_types__optional repeat__num, kk_context_t* _ctx) { /* (pt : int, rs : int, sbrs : int, t_steps : int, burnin : int, repeat_num : optional<int>) -> <pure,console,fsys,ndet,std/num/random/random> () */ 
  kk_std_core_types__tuple2_ x_5771;
  size_t i_5774 = ((size_t)0); /*std/core/hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_5774,kk_context()); /*std/core/hnd/evv<<div,exn,fsys,console,ndet,std/num/random/random>>*/;
  kk_std_core_types__tuple2_ y = kk_data_preprocessing_pre__process__data(_ctx); /*(list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>)*/;
  kk_unit_t __w_l683_c9 = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_std_core_types__tuple2__drop(y, _ctx);
    kk_box_t _x8039 = kk_std_core_hnd_yield_cont(kk_climate_dash_experiments_new_run__climate__model_fun8040(i_5774, _ctx), _ctx); /*3*/
    x_5771 = kk_std_core_types__tuple2__unbox(_x8039, _ctx); /*(list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>)*/
  }
  else {
    x_5771 = y; /*(list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>)*/
  }
  if (kk_yielding(kk_context())) {
    kk_std_core_types__tuple2__drop(x_5771, _ctx);
    kk_box_t _x8041 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments_new_run__climate__model_fun8042(burnin, pt, repeat__num, rs, sbrs, t__steps, _ctx), _ctx); /*2*/
    kk_unit_unbox(_x8041); return kk_Unit;
  }
  kk_std_core__list pre__data;
  kk_std_core_types__tuple3_ _b_6800_6798;
  kk_box_t _x8045;
  kk_string_t _x8046;
  kk_define_string_literal(, _s8047, 3, "jan")
  _x8046 = kk_string_dup(_s8047); /*string*/
  _x8045 = kk_string_box(_x8046); /*10*/
  _b_6800_6798 = kk_std_core_types__new_dash__lp__comma__comma__rp_(kk_double_box(0x1.4p3, _ctx), kk_double_box(-0x1.8p1, _ctx), _x8045, _ctx); /*(double, double, string)*/
  kk_std_core__list _b_6801_6799;
  kk_std_core_types__tuple3_ _b_6805_6796;
  kk_box_t _x8048;
  kk_string_t _x8049;
  kk_define_string_literal(, _s8050, 3, "feb")
  _x8049 = kk_string_dup(_s8050); /*string*/
  _x8048 = kk_string_box(_x8049); /*10*/
  _b_6805_6796 = kk_std_core_types__new_dash__lp__comma__comma__rp_(kk_double_box(0x1p3, _ctx), kk_double_box(-0x1p0, _ctx), _x8048, _ctx); /*(double, double, string)*/
  kk_std_core__list _b_6806_6797;
  kk_std_core_types__tuple3_ _b_6810_6794;
  kk_box_t _x8051;
  kk_string_t _x8052;
  kk_define_string_literal(, _s8053, 3, "mar")
  _x8052 = kk_string_dup(_s8053); /*string*/
  _x8051 = kk_string_box(_x8052); /*10*/
  _b_6810_6794 = kk_std_core_types__new_dash__lp__comma__comma__rp_(kk_double_box(0x1.cp2, _ctx), kk_double_box(0x1p0, _ctx), _x8051, _ctx); /*(double, double, string)*/
  kk_std_core__list _b_6811_6795;
  kk_std_core_types__tuple3_ _b_6815_6792;
  kk_box_t _x8054;
  kk_string_t _x8055;
  kk_define_string_literal(, _s8056, 3, "apr")
  _x8055 = kk_string_dup(_s8056); /*string*/
  _x8054 = kk_string_box(_x8055); /*10*/
  _b_6815_6792 = kk_std_core_types__new_dash__lp__comma__comma__rp_(kk_double_box(0x1.8p2, _ctx), kk_double_box(0x1.4p2, _ctx), _x8054, _ctx); /*(double, double, string)*/
  kk_std_core__list _b_6816_6793;
  kk_std_core_types__tuple3_ _b_6820_6790;
  kk_box_t _x8057;
  kk_string_t _x8058;
  kk_define_string_literal(, _s8059, 3, "may")
  _x8058 = kk_string_dup(_s8059); /*string*/
  _x8057 = kk_string_box(_x8058); /*10*/
  _b_6820_6790 = kk_std_core_types__new_dash__lp__comma__comma__rp_(kk_double_box(0x1p3, _ctx), kk_double_box(0x1.2p3, _ctx), _x8057, _ctx); /*(double, double, string)*/
  kk_std_core__list _b_6821_6791;
  kk_std_core_types__tuple3_ _b_6825_6788;
  kk_box_t _x8060;
  kk_string_t _x8061;
  kk_define_string_literal(, _s8062, 3, "jun")
  _x8061 = kk_string_dup(_s8062); /*string*/
  _x8060 = kk_string_box(_x8061); /*10*/
  _b_6825_6788 = kk_std_core_types__new_dash__lp__comma__comma__rp_(kk_double_box(0x1p3, _ctx), kk_double_box(0x1.4p3, _ctx), _x8060, _ctx); /*(double, double, string)*/
  kk_std_core__list _b_6826_6789;
  kk_std_core_types__tuple3_ _b_6830_6786;
  kk_box_t _x8063;
  kk_string_t _x8064;
  kk_define_string_literal(, _s8065, 3, "jul")
  _x8064 = kk_string_dup(_s8065); /*string*/
  _x8063 = kk_string_box(_x8064); /*10*/
  _b_6830_6786 = kk_std_core_types__new_dash__lp__comma__comma__rp_(kk_double_box(0x1.2p3, _ctx), kk_double_box(0x1.6p3, _ctx), _x8063, _ctx); /*(double, double, string)*/
  kk_std_core__list _b_6831_6787;
  kk_std_core_types__tuple3_ _b_6835_6784;
  kk_box_t _x8066;
  kk_string_t _x8067;
  kk_define_string_literal(, _s8068, 3, "aug")
  _x8067 = kk_string_dup(_s8068); /*string*/
  _x8066 = kk_string_box(_x8067); /*10*/
  _b_6835_6784 = kk_std_core_types__new_dash__lp__comma__comma__rp_(kk_double_box(0x1.8p2, _ctx), kk_double_box(0x1.6p3, _ctx), _x8066, _ctx); /*(double, double, string)*/
  kk_std_core__list _b_6836_6785;
  kk_std_core_types__tuple3_ _b_6840_6782;
  kk_box_t _x8069;
  kk_string_t _x8070;
  kk_define_string_literal(, _s8071, 3, "sep")
  _x8070 = kk_string_dup(_s8071); /*string*/
  _x8069 = kk_string_box(_x8070); /*10*/
  _b_6840_6782 = kk_std_core_types__new_dash__lp__comma__comma__rp_(kk_double_box(0x1.4p2, _ctx), kk_double_box(0x1.4p3, _ctx), _x8069, _ctx); /*(double, double, string)*/
  kk_std_core__list _b_6841_6783;
  kk_std_core_types__tuple3_ _b_6845_6780;
  kk_box_t _x8072;
  kk_string_t _x8073;
  kk_define_string_literal(, _s8074, 3, "oct")
  _x8073 = kk_string_dup(_s8074); /*string*/
  _x8072 = kk_string_box(_x8073); /*10*/
  _b_6845_6780 = kk_std_core_types__new_dash__lp__comma__comma__rp_(kk_double_box(0x1.2p3, _ctx), kk_double_box(0x1p0, _ctx), _x8072, _ctx); /*(double, double, string)*/
  kk_std_core__list _b_6846_6781;
  kk_std_core_types__tuple3_ _b_6850_6778;
  kk_box_t _x8075;
  kk_string_t _x8076;
  kk_define_string_literal(, _s8077, 3, "nov")
  _x8076 = kk_string_dup(_s8077); /*string*/
  _x8075 = kk_string_box(_x8076); /*10*/
  _b_6850_6778 = kk_std_core_types__new_dash__lp__comma__comma__rp_(kk_double_box(0x1.cp2, _ctx), kk_double_box(0x1p1, _ctx), _x8075, _ctx); /*(double, double, string)*/
  kk_std_core__list _b_6851_6779;
  kk_std_core_types__tuple3_ _b_6855_6776;
  kk_box_t _x8078;
  kk_string_t _x8079;
  kk_define_string_literal(, _s8080, 3, "dec")
  _x8079 = kk_string_dup(_s8080); /*string*/
  _x8078 = kk_string_box(_x8079); /*10*/
  _b_6855_6776 = kk_std_core_types__new_dash__lp__comma__comma__rp_(kk_double_box(0x1.8p2, _ctx), kk_double_box(-0x1p0, _ctx), _x8078, _ctx); /*(double, double, string)*/
  _b_6851_6779 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core_types__tuple3__box(_b_6855_6776, _ctx), kk_std_core__new_Nil(_ctx), _ctx); /*list<(double, double, string)>*/
  _b_6846_6781 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core_types__tuple3__box(_b_6850_6778, _ctx), _b_6851_6779, _ctx); /*list<(double, double, string)>*/
  _b_6841_6783 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core_types__tuple3__box(_b_6845_6780, _ctx), _b_6846_6781, _ctx); /*list<(double, double, string)>*/
  _b_6836_6785 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core_types__tuple3__box(_b_6840_6782, _ctx), _b_6841_6783, _ctx); /*list<(double, double, string)>*/
  _b_6831_6787 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core_types__tuple3__box(_b_6835_6784, _ctx), _b_6836_6785, _ctx); /*list<(double, double, string)>*/
  _b_6826_6789 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core_types__tuple3__box(_b_6830_6786, _ctx), _b_6831_6787, _ctx); /*list<(double, double, string)>*/
  _b_6821_6791 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core_types__tuple3__box(_b_6825_6788, _ctx), _b_6826_6789, _ctx); /*list<(double, double, string)>*/
  _b_6816_6793 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core_types__tuple3__box(_b_6820_6790, _ctx), _b_6821_6791, _ctx); /*list<(double, double, string)>*/
  _b_6811_6795 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core_types__tuple3__box(_b_6815_6792, _ctx), _b_6816_6793, _ctx); /*list<(double, double, string)>*/
  _b_6806_6797 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core_types__tuple3__box(_b_6810_6794, _ctx), _b_6811_6795, _ctx); /*list<(double, double, string)>*/
  _b_6801_6799 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core_types__tuple3__box(_b_6805_6796, _ctx), _b_6806_6797, _ctx); /*list<(double, double, string)>*/
  pre__data = kk_std_core__new_Cons(kk_reuse_null, kk_std_core_types__tuple3__box(_b_6800_6798, _ctx), _b_6801_6799, _ctx); /*list<(double, double, string)>*/
  kk_unit_t __ = kk_Unit;
  kk_string_t _x8081;
  kk_define_string_literal(, _s8082, 93, "Starting to run the climate model! Run with -O2 --showelapsed flag to improve execution time.")
  _x8081 = kk_string_dup(_s8082); /*string*/
  kk_std_core_printsln(_x8081, _ctx);
  kk_unit_t __0 = kk_Unit;
  kk_string_t _x8083;
  kk_define_string_literal(, _s8084, 39, "Beginning to start TMCMC experiment #1:")
  _x8083 = kk_string_dup(_s8084); /*string*/
  kk_std_core_printsln(_x8083, _ctx);
  kk_std_core__list x0_5779;
  kk_box_t _x8085;
  kk_function_t _x8086;
  kk_integer_dup(burnin);
  kk_std_core__list_dup(pre__data);
  kk_integer_dup(t__steps);
  kk_std_core_types__tuple2__dup(x_5771);
  _x8086 = kk_climate_dash_experiments_new_run__climate__model_fun8087(burnin, pre__data, t__steps, x_5771, _ctx); /*() -> <ndet,console|1> 0*/
  _x8085 = kk_std_time_timer_print_elapsed(_x8086, kk_std_core_types__new_None(_ctx), _ctx); /*0*/
  x0_5779 = kk_std_core__list_unbox(_x8085, _ctx); /*list<()>*/
  kk_std_core__list_drop(x0_5779, _ctx);
  if (kk_yielding(kk_context())) {
    kk_box_t _x8122 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments_new_run__climate__model_fun8123(burnin, pre__data, pt, repeat__num, rs, sbrs, t__steps, x_5771, _ctx), _ctx); /*2*/
    kk_unit_unbox(_x8122); return kk_Unit;
  }
  kk_unit_t __2 = kk_Unit;
  kk_string_t _x8126;
  kk_define_string_literal(, _s8127, 39, "Beginning to start TMCMC experiment #2:")
  _x8126 = kk_string_dup(_s8127); /*string*/
  kk_std_core_printsln(_x8126, _ctx);
  kk_std_core__list x3_5793;
  kk_box_t _x8128;
  kk_function_t _x8129;
  kk_std_core__list_dup(pre__data);
  kk_std_core_types__tuple2__dup(x_5771);
  _x8129 = kk_climate_dash_experiments_new_run__climate__model_fun8130(burnin, pre__data, t__steps, x_5771, _ctx); /*() -> <ndet,console|1> 0*/
  _x8128 = kk_std_time_timer_print_elapsed(_x8129, kk_std_core_types__new_None(_ctx), _ctx); /*0*/
  x3_5793 = kk_std_core__list_unbox(_x8128, _ctx); /*list<()>*/
  kk_std_core__list_drop(x3_5793, _ctx);
  kk_box_t _x8165;
  if (kk_yielding(kk_context())) {
    _x8165 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments_new_run__climate__model_fun8166(pre__data, pt, repeat__num, rs, sbrs, x_5771, _ctx), _ctx); /*2*/
  }
  else {
    _x8165 = kk_std_time_timer_print_elapsed(kk_climate_dash_experiments_new_run__climate__model_fun8169(pre__data, pt, repeat__num, rs, sbrs, x_5771, _ctx), kk_std_core_types__new_None(_ctx), _ctx); /*2*/
  }
  kk_unit_unbox(_x8165); return kk_Unit;
}
 
// monadic lift

kk_unit_t kk_climate_dash_experiments__mlift5641_run__experiments(kk_integer_t i1, kk_std_core__list wild__10, kk_context_t* _ctx) { /* (i1 : int, wild_10 : list<(list<(list<double>, (double, double))>, tmcmc/trace<(double, double),<effects-and-types/sample,effects-and-types/score,div,console,ndet,exn,std/num/random/random>>)>) -> <console,div,ndet,effects-and-types/sample,exn,std/num/random/random> () */ 
  kk_std_core__list_drop(wild__10, _ctx);
  kk_unit_t __11 = kk_Unit;
  kk_string_t _x8215;
  kk_define_string_literal(, _s8216, 21, "Completed Trace MCMC!")
  _x8215 = kk_string_dup(_s8216); /*string*/
  kk_std_core_printsln(_x8215, _ctx);
  kk_unit_t __12 = kk_Unit;
  kk_string_t _x8217 = kk_string_empty(); /*string*/
  kk_std_core_printsln(_x8217, _ctx);
  kk_unit_t __13 = kk_Unit;
  kk_string_t _x8219;
  kk_define_string_literal(, _s8220, 37, ".....................................")
  _x8219 = kk_string_dup(_s8220); /*string*/
  kk_std_core_printsln(_x8219, _ctx);
  kk_unit_t __14 = kk_Unit;
  kk_string_t s2_5824;
  kk_string_t _x8221;
  kk_define_string_literal(, _s8222, 17, "Completed Round #")
  _x8221 = kk_string_dup(_s8222); /*string*/
  kk_string_t _x8223 = kk_std_core_show(i1, _ctx); /*string*/
  s2_5824 = kk_std_core__lp__plus__plus__1_rp_(_x8221, _x8223, _ctx); /*string*/
  kk_std_core_printsln(s2_5824, _ctx);
  kk_unit_t __15 = kk_Unit;
  kk_string_t _x8224;
  kk_define_string_literal(, _s8225, 37, ".....................................")
  _x8224 = kk_string_dup(_s8225); /*string*/
  kk_std_core_printsln(_x8224, _ctx);
  kk_unit_t __16 = kk_Unit;
  kk_string_t _x8226 = kk_string_empty(); /*string*/
  kk_std_core_printsln(_x8226, _ctx);
  kk_unit_t __17 = kk_Unit;
  kk_string_t _x8228 = kk_string_empty(); /*string*/
  kk_std_core_printsln(_x8228, _ctx);
  kk_unit_t __18 = kk_Unit;
  kk_string_t _x8230 = kk_string_empty(); /*string*/
  kk_std_core_printsln(_x8230, _ctx);
  kk_string_t _x8232 = kk_string_empty(); /*string*/
  kk_std_core_printsln(_x8232, _ctx); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_climate_dash_experiments__mlift5642_run__experiments_fun8238__t {
  struct kk_function_s _base;
  kk_std_core__list data__50;
};
static kk_box_t kk_climate_dash_experiments__mlift5642_run__experiments_fun8238(kk_function_t _fself, kk_box_t _b_7062, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5642_run__experiments_fun8238(kk_std_core__list data__50, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5642_run__experiments_fun8238__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5642_run__experiments_fun8238__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5642_run__experiments_fun8238, kk_context());
  _self->data__50 = data__50;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift5642_run__experiments_fun8241__t {
  struct kk_function_s _base;
  kk_std_core__list data__50;
  kk_integer_t sz1;
};
static kk_box_t kk_climate_dash_experiments__mlift5642_run__experiments_fun8241(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5642_run__experiments_fun8241(kk_std_core__list data__50, kk_integer_t sz1, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5642_run__experiments_fun8241__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5642_run__experiments_fun8241__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5642_run__experiments_fun8241, kk_context());
  _self->data__50 = data__50;
  _self->sz1 = sz1;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift5642_run__experiments_fun8244__t {
  struct kk_function_s _base;
};
static kk_box_t kk_climate_dash_experiments__mlift5642_run__experiments_fun8244(kk_function_t _fself, kk_box_t _b_7041, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5642_run__experiments_fun8244(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_climate_dash_experiments__mlift5642_run__experiments_fun8244, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift5642_run__experiments_fun8247__t {
  struct kk_function_s _base;
  kk_function_t _bv_7043;
};
static kk_box_t kk_climate_dash_experiments__mlift5642_run__experiments_fun8247(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5642_run__experiments_fun8247(kk_function_t _bv_7043, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5642_run__experiments_fun8247__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5642_run__experiments_fun8247__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5642_run__experiments_fun8247, kk_context());
  _self->_bv_7043 = _bv_7043;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift5642_run__experiments_fun8247(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5642_run__experiments_fun8247__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5642_run__experiments_fun8247__t*, _fself);
  kk_function_t _bv_7043 = _self->_bv_7043; /* effects-and-types/model<(double, double),div> */
  kk_drop_match(_self, {kk_function_dup(_bv_7043);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x8248 = kk_function_call(kk_std_core_types__tuple2_, (kk_function_t, kk_context_t*), _bv_7043, (_bv_7043, _ctx)); /*(double, double)*/
  return kk_std_core_types__tuple2__box(_x8248, _ctx);
}
static kk_box_t kk_climate_dash_experiments__mlift5642_run__experiments_fun8244(kk_function_t _fself, kk_box_t _b_7041, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_function_t _x8245;
  kk_function_t _bv_7043;
  kk_std_core__list _x8246 = kk_std_core__list_unbox(_b_7041, _ctx); /*list<(double, bool)>*/
  _bv_7043 = kk_model_dash_resources_logistic__regression(_x8246, _ctx); /*effects-and-types/model<(double, double),div>*/
  _x8245 = kk_climate_dash_experiments__new_mlift5642_run__experiments_fun8247(_bv_7043, _ctx); /*() -> <effects-and-types/sample,effects-and-types/score,div> 7042*/
  return kk_function_box(_x8245);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift5642_run__experiments_fun8249__t {
  struct kk_function_s _base;
  kk_function_t _bv_7045;
};
static kk_std_core_types__tuple2_ kk_climate_dash_experiments__mlift5642_run__experiments_fun8249(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5642_run__experiments_fun8249(kk_function_t _bv_7045, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5642_run__experiments_fun8249__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5642_run__experiments_fun8249__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5642_run__experiments_fun8249, kk_context());
  _self->_bv_7045 = _bv_7045;
  return &_self->_base;
}

static kk_std_core_types__tuple2_ kk_climate_dash_experiments__mlift5642_run__experiments_fun8249(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5642_run__experiments_fun8249__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5642_run__experiments_fun8249__t*, _fself);
  kk_function_t _bv_7045 = _self->_bv_7045; /* () -> <.Box|.Box> 7044 */
  kk_drop_match(_self, {kk_function_dup(_bv_7045);}, {}, _ctx)
  kk_box_t _x8250 = kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), _bv_7045, (_bv_7045, _ctx)); /*7044*/
  return kk_std_core_types__tuple2__unbox(_x8250, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift5642_run__experiments_fun8251__t {
  struct kk_function_s _base;
  kk_function_t _x07_5626;
};
static kk_std_core_types__tuple2_ kk_climate_dash_experiments__mlift5642_run__experiments_fun8251(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5642_run__experiments_fun8251(kk_function_t _x07_5626, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5642_run__experiments_fun8251__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5642_run__experiments_fun8251__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5642_run__experiments_fun8251, kk_context());
  _self->_x07_5626 = _x07_5626;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift5642_run__experiments_fun8254__t {
  struct kk_function_s _base;
  kk_function_t _x07_5626;
};
static kk_box_t kk_climate_dash_experiments__mlift5642_run__experiments_fun8254(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5642_run__experiments_fun8254(kk_function_t _x07_5626, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5642_run__experiments_fun8254__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5642_run__experiments_fun8254__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5642_run__experiments_fun8254, kk_context());
  _self->_x07_5626 = _x07_5626;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift5642_run__experiments_fun8254(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5642_run__experiments_fun8254__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5642_run__experiments_fun8254__t*, _fself);
  kk_function_t _x07_5626 = _self->_x07_5626; /* effects-and-types/model<(double, double),div> */
  kk_drop_match(_self, {kk_function_dup(_x07_5626);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x8255 = kk_function_call(kk_std_core_types__tuple2_, (kk_function_t, kk_context_t*), _x07_5626, (_x07_5626, _ctx)); /*(double, double)*/
  return kk_std_core_types__tuple2__box(_x8255, _ctx);
}
static kk_std_core_types__tuple2_ kk_climate_dash_experiments__mlift5642_run__experiments_fun8251(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5642_run__experiments_fun8251__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5642_run__experiments_fun8251__t*, _fself);
  kk_function_t _x07_5626 = _self->_x07_5626; /* effects-and-types/model<(double, double),div> */
  kk_drop_match(_self, {kk_function_dup(_x07_5626);}, {}, _ctx)
  kk_vector_t _b_7072_7052;
  kk_std_core__list _x8252;
  size_t _b_7074_7050 = ((size_t)2); /*std/core/hnd/ev-index*/;
  kk_std_core__list _b_7075_7051;
  size_t _b_7076_7048 = ((size_t)3); /*std/core/hnd/ev-index*/;
  _b_7075_7051 = kk_std_core__new_Cons(kk_reuse_null, kk_size_box(_b_7076_7048, _ctx), kk_std_core__new_Nil(_ctx), _ctx); /*list<std/core/hnd/ev-index>*/
  _x8252 = kk_std_core__new_Cons(kk_reuse_null, kk_size_box(_b_7074_7050, _ctx), _b_7075_7051, _ctx); /*list<0>*/
  _b_7072_7052 = kk_std_core_unvlist(_x8252, _ctx); /*vector<std/core/hnd/ev-index>*/
  kk_box_t _x8253 = kk_std_core_hnd__open0(_b_7072_7052, kk_climate_dash_experiments__new_mlift5642_run__experiments_fun8254(_x07_5626, _ctx), _ctx); /*1*/
  return kk_std_core_types__tuple2__unbox(_x8253, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift5642_run__experiments_fun8256__t {
  struct kk_function_s _base;
  kk_function_t _b_7068_7054;
};
static kk_box_t kk_climate_dash_experiments__mlift5642_run__experiments_fun8256(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5642_run__experiments_fun8256(kk_function_t _b_7068_7054, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5642_run__experiments_fun8256__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5642_run__experiments_fun8256__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5642_run__experiments_fun8256, kk_context());
  _self->_b_7068_7054 = _b_7068_7054;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift5642_run__experiments_fun8256(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5642_run__experiments_fun8256__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5642_run__experiments_fun8256__t*, _fself);
  kk_function_t _b_7068_7054 = _self->_b_7068_7054; /* () -> <effects-and-types/sample,effects-and-types/score,div> (double, double) */
  kk_drop_match(_self, {kk_function_dup(_b_7068_7054);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x8257 = kk_function_call(kk_std_core_types__tuple2_, (kk_function_t, kk_context_t*), _b_7068_7054, (_b_7068_7054, _ctx)); /*(double, double)*/
  return kk_std_core_types__tuple2__box(_x8257, _ctx);
}
static kk_box_t kk_climate_dash_experiments__mlift5642_run__experiments_fun8241(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5642_run__experiments_fun8241__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5642_run__experiments_fun8241__t*, _fself);
  kk_std_core__list data__50 = _self->data__50; /* list<(double, bool)> */
  kk_integer_t sz1 = _self->sz1; /* int */
  kk_drop_match(_self, {kk_std_core__list_dup(data__50);kk_integer_dup(sz1);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x8242;
  kk_function_t _b_7068_7054;
  kk_function_t _x07_5626;
  kk_function_t _bv_7045;
  kk_box_t _x8243 = kk_std_core_hnd__open_none1(kk_climate_dash_experiments__new_mlift5642_run__experiments_fun8244(_ctx), kk_std_core__list_box(data__50, _ctx), _ctx); /*2*/
  _bv_7045 = kk_function_unbox(_x8243); /*() -> <.Box|.Box> 7044*/
  _x07_5626 = kk_climate_dash_experiments__new_mlift5642_run__experiments_fun8249(_bv_7045, _ctx); /*effects-and-types/model<(double, double),div>*/
  _b_7068_7054 = kk_climate_dash_experiments__new_mlift5642_run__experiments_fun8251(_x07_5626, _ctx); /*() -> <effects-and-types/sample,effects-and-types/score,div> (double, double)*/
  kk_effects_dash_and_dash_types__exp _b_7070_7056 = kk_effects_dash_and_dash_types__new_Exp(0x0p+0, _ctx); /*effects-and-types/exp*/;
  _x8242 = kk_tmcmc_tmcmc(kk_climate_dash_experiments__new_mlift5642_run__experiments_fun8256(_b_7068_7054, _ctx), sz1, _b_7070_7056, kk_integer_from_small(0), _ctx); /*(list<(list<double>, 0)>, tmcmc/trace<0,<effects-and-types/sample,effects-and-types/score,div|1>>)*/
  return kk_std_core_types__tuple2__box(_x8242, _ctx);
}
static kk_box_t kk_climate_dash_experiments__mlift5642_run__experiments_fun8238(kk_function_t _fself, kk_box_t _b_7062, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5642_run__experiments_fun8238__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5642_run__experiments_fun8238__t*, _fself);
  kk_std_core__list data__50 = _self->data__50; /* list<(double, bool)> */
  kk_drop_match(_self, {kk_std_core__list_dup(data__50);}, {}, _ctx)
  kk_std_core_types__tuple2_ _match_7482 = kk_std_core_types__tuple2__unbox(_b_7062, _ctx); /*(int, list<(double, bool)>)*/;
  kk_box_t _box_x7037 = _match_7482.fst;
  kk_box_t _box_x7038 = _match_7482.snd;
  kk_integer_t sz1 = kk_integer_unbox(_box_x7037);
  kk_integer_dup(sz1);
  kk_std_core_types__tuple2__drop(_match_7482, _ctx);
  return kk_std_time_timer_print_elapsed(kk_climate_dash_experiments__new_mlift5642_run__experiments_fun8241(data__50, sz1, _ctx), kk_std_core_types__new_None(_ctx), _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift5642_run__experiments_fun8259__t {
  struct kk_function_s _base;
  kk_integer_t i1;
};
static kk_box_t kk_climate_dash_experiments__mlift5642_run__experiments_fun8259(kk_function_t _fself, kk_box_t _b_7079, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5642_run__experiments_fun8259(kk_integer_t i1, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5642_run__experiments_fun8259__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5642_run__experiments_fun8259__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5642_run__experiments_fun8259, kk_context());
  _self->i1 = i1;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift5642_run__experiments_fun8259(kk_function_t _fself, kk_box_t _b_7079, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5642_run__experiments_fun8259__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5642_run__experiments_fun8259__t*, _fself);
  kk_integer_t i1 = _self->i1; /* int */
  kk_drop_match(_self, {kk_integer_dup(i1);}, {}, _ctx)
  kk_unit_t _x8260 = kk_Unit;
  kk_std_core__list _x8261 = kk_std_core__list_unbox(_b_7079, _ctx); /*list<(list<(list<double>, (double, double))>, tmcmc/trace<(double, double),<effects-and-types/sample,effects-and-types/score,div,console,ndet,exn,std/num/random/random>>)>*/
  kk_climate_dash_experiments__mlift5641_run__experiments(i1, _x8261, _ctx);
  return kk_unit_box(_x8260);
}

kk_unit_t kk_climate_dash_experiments__mlift5642_run__experiments(kk_std_core__list data__50, kk_std_core__list data__points, kk_integer_t i1, kk_std_core__list wild__7, kk_context_t* _ctx) { /* (data_50 : list<(double, bool)>, data_points : list<(int, list<(double, bool)>)>, i1 : int, wild_7 : list<(list<(list<double>, (double, double))>, tmcmc/trace<(double, double),<effects-and-types/sample,effects-and-types/score,div,console,ndet,exn,std/num/random/random>>)>) -> <console,div,ndet,effects-and-types/sample,exn,std/num/random/random> () */ 
  kk_std_core__list_drop(wild__7, _ctx);
  kk_unit_t __8 = kk_Unit;
  kk_string_t _x8234;
  kk_define_string_literal(, _s8235, 18, "Mid-way with TMCMC")
  _x8234 = kk_string_dup(_s8235); /*string*/
  kk_std_core_printsln(_x8234, _ctx);
  kk_unit_t __9 = kk_Unit;
  kk_string_t _x8236;
  kk_define_string_literal(, _s8237, 46, "Running TMCMC with increasing number of steps:")
  _x8236 = kk_string_dup(_s8237); /*string*/
  kk_std_core_printsln(_x8236, _ctx);
  kk_std_core__list x_5832 = kk_std_core_map_5(data__points, kk_climate_dash_experiments__new_mlift5642_run__experiments_fun8238(data__50, _ctx), _ctx); /*list<(list<(list<double>, (double, double))>, tmcmc/trace<(double, double),<effects-and-types/sample,effects-and-types/score,div,console,ndet,exn,std/num/random/random>>)>*/;
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_5832, _ctx);
    kk_box_t _x8258 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments__new_mlift5642_run__experiments_fun8259(i1, _ctx), _ctx); /*2*/
    kk_unit_unbox(_x8258); return kk_Unit;
  }
  kk_climate_dash_experiments__mlift5641_run__experiments(i1, x_5832, _ctx); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_climate_dash_experiments__mlift5643_run__experiments_fun8267__t {
  struct kk_function_s _base;
};
static kk_box_t kk_climate_dash_experiments__mlift5643_run__experiments_fun8267(kk_function_t _fself, kk_box_t _b_7107, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5643_run__experiments_fun8267(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_climate_dash_experiments__mlift5643_run__experiments_fun8267, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift5643_run__experiments_fun8270__t {
  struct kk_function_s _base;
  kk_std_core__list data__vals0;
};
static kk_box_t kk_climate_dash_experiments__mlift5643_run__experiments_fun8270(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5643_run__experiments_fun8270(kk_std_core__list data__vals0, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5643_run__experiments_fun8270__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5643_run__experiments_fun8270__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5643_run__experiments_fun8270, kk_context());
  _self->data__vals0 = data__vals0;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift5643_run__experiments_fun8273__t {
  struct kk_function_s _base;
};
static kk_box_t kk_climate_dash_experiments__mlift5643_run__experiments_fun8273(kk_function_t _fself, kk_box_t _b_7086, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5643_run__experiments_fun8273(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_climate_dash_experiments__mlift5643_run__experiments_fun8273, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift5643_run__experiments_fun8276__t {
  struct kk_function_s _base;
  kk_function_t _bv_7088;
};
static kk_box_t kk_climate_dash_experiments__mlift5643_run__experiments_fun8276(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5643_run__experiments_fun8276(kk_function_t _bv_7088, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5643_run__experiments_fun8276__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5643_run__experiments_fun8276__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5643_run__experiments_fun8276, kk_context());
  _self->_bv_7088 = _bv_7088;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift5643_run__experiments_fun8276(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5643_run__experiments_fun8276__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5643_run__experiments_fun8276__t*, _fself);
  kk_function_t _bv_7088 = _self->_bv_7088; /* effects-and-types/model<(double, double),div> */
  kk_drop_match(_self, {kk_function_dup(_bv_7088);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x8277 = kk_function_call(kk_std_core_types__tuple2_, (kk_function_t, kk_context_t*), _bv_7088, (_bv_7088, _ctx)); /*(double, double)*/
  return kk_std_core_types__tuple2__box(_x8277, _ctx);
}
static kk_box_t kk_climate_dash_experiments__mlift5643_run__experiments_fun8273(kk_function_t _fself, kk_box_t _b_7086, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_function_t _x8274;
  kk_function_t _bv_7088;
  kk_std_core__list _x8275 = kk_std_core__list_unbox(_b_7086, _ctx); /*list<(double, bool)>*/
  _bv_7088 = kk_model_dash_resources_logistic__regression(_x8275, _ctx); /*effects-and-types/model<(double, double),div>*/
  _x8274 = kk_climate_dash_experiments__new_mlift5643_run__experiments_fun8276(_bv_7088, _ctx); /*() -> <effects-and-types/sample,effects-and-types/score,div> 7087*/
  return kk_function_box(_x8274);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift5643_run__experiments_fun8278__t {
  struct kk_function_s _base;
  kk_function_t _bv_7090;
};
static kk_std_core_types__tuple2_ kk_climate_dash_experiments__mlift5643_run__experiments_fun8278(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5643_run__experiments_fun8278(kk_function_t _bv_7090, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5643_run__experiments_fun8278__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5643_run__experiments_fun8278__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5643_run__experiments_fun8278, kk_context());
  _self->_bv_7090 = _bv_7090;
  return &_self->_base;
}

static kk_std_core_types__tuple2_ kk_climate_dash_experiments__mlift5643_run__experiments_fun8278(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5643_run__experiments_fun8278__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5643_run__experiments_fun8278__t*, _fself);
  kk_function_t _bv_7090 = _self->_bv_7090; /* () -> <.Box|.Box> 7089 */
  kk_drop_match(_self, {kk_function_dup(_bv_7090);}, {}, _ctx)
  kk_box_t _x8279 = kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), _bv_7090, (_bv_7090, _ctx)); /*7089*/
  return kk_std_core_types__tuple2__unbox(_x8279, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift5643_run__experiments_fun8280__t {
  struct kk_function_s _base;
  kk_function_t _x05_5624;
};
static kk_std_core_types__tuple2_ kk_climate_dash_experiments__mlift5643_run__experiments_fun8280(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5643_run__experiments_fun8280(kk_function_t _x05_5624, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5643_run__experiments_fun8280__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5643_run__experiments_fun8280__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5643_run__experiments_fun8280, kk_context());
  _self->_x05_5624 = _x05_5624;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift5643_run__experiments_fun8283__t {
  struct kk_function_s _base;
  kk_function_t _x05_5624;
};
static kk_box_t kk_climate_dash_experiments__mlift5643_run__experiments_fun8283(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5643_run__experiments_fun8283(kk_function_t _x05_5624, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5643_run__experiments_fun8283__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5643_run__experiments_fun8283__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5643_run__experiments_fun8283, kk_context());
  _self->_x05_5624 = _x05_5624;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift5643_run__experiments_fun8283(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5643_run__experiments_fun8283__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5643_run__experiments_fun8283__t*, _fself);
  kk_function_t _x05_5624 = _self->_x05_5624; /* effects-and-types/model<(double, double),div> */
  kk_drop_match(_self, {kk_function_dup(_x05_5624);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x8284 = kk_function_call(kk_std_core_types__tuple2_, (kk_function_t, kk_context_t*), _x05_5624, (_x05_5624, _ctx)); /*(double, double)*/
  return kk_std_core_types__tuple2__box(_x8284, _ctx);
}
static kk_std_core_types__tuple2_ kk_climate_dash_experiments__mlift5643_run__experiments_fun8280(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5643_run__experiments_fun8280__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5643_run__experiments_fun8280__t*, _fself);
  kk_function_t _x05_5624 = _self->_x05_5624; /* effects-and-types/model<(double, double),div> */
  kk_drop_match(_self, {kk_function_dup(_x05_5624);}, {}, _ctx)
  kk_vector_t _b_7117_7097;
  kk_std_core__list _x8281;
  size_t _b_7119_7095 = ((size_t)2); /*std/core/hnd/ev-index*/;
  kk_std_core__list _b_7120_7096;
  size_t _b_7121_7093 = ((size_t)3); /*std/core/hnd/ev-index*/;
  _b_7120_7096 = kk_std_core__new_Cons(kk_reuse_null, kk_size_box(_b_7121_7093, _ctx), kk_std_core__new_Nil(_ctx), _ctx); /*list<std/core/hnd/ev-index>*/
  _x8281 = kk_std_core__new_Cons(kk_reuse_null, kk_size_box(_b_7119_7095, _ctx), _b_7120_7096, _ctx); /*list<0>*/
  _b_7117_7097 = kk_std_core_unvlist(_x8281, _ctx); /*vector<std/core/hnd/ev-index>*/
  kk_box_t _x8282 = kk_std_core_hnd__open0(_b_7117_7097, kk_climate_dash_experiments__new_mlift5643_run__experiments_fun8283(_x05_5624, _ctx), _ctx); /*1*/
  return kk_std_core_types__tuple2__unbox(_x8282, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift5643_run__experiments_fun8285__t {
  struct kk_function_s _base;
  kk_function_t _b_7113_7099;
};
static kk_box_t kk_climate_dash_experiments__mlift5643_run__experiments_fun8285(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5643_run__experiments_fun8285(kk_function_t _b_7113_7099, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5643_run__experiments_fun8285__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5643_run__experiments_fun8285__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5643_run__experiments_fun8285, kk_context());
  _self->_b_7113_7099 = _b_7113_7099;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift5643_run__experiments_fun8285(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5643_run__experiments_fun8285__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5643_run__experiments_fun8285__t*, _fself);
  kk_function_t _b_7113_7099 = _self->_b_7113_7099; /* () -> <effects-and-types/sample,effects-and-types/score,div> (double, double) */
  kk_drop_match(_self, {kk_function_dup(_b_7113_7099);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x8286 = kk_function_call(kk_std_core_types__tuple2_, (kk_function_t, kk_context_t*), _b_7113_7099, (_b_7113_7099, _ctx)); /*(double, double)*/
  return kk_std_core_types__tuple2__box(_x8286, _ctx);
}
static kk_box_t kk_climate_dash_experiments__mlift5643_run__experiments_fun8270(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5643_run__experiments_fun8270__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5643_run__experiments_fun8270__t*, _fself);
  kk_std_core__list data__vals0 = _self->data__vals0; /* list<(double, bool)> */
  kk_drop_match(_self, {kk_std_core__list_dup(data__vals0);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x8271;
  kk_function_t _b_7113_7099;
  kk_function_t _x05_5624;
  kk_function_t _bv_7090;
  kk_box_t _x8272 = kk_std_core_hnd__open_none1(kk_climate_dash_experiments__new_mlift5643_run__experiments_fun8273(_ctx), kk_std_core__list_box(data__vals0, _ctx), _ctx); /*2*/
  _bv_7090 = kk_function_unbox(_x8272); /*() -> <.Box|.Box> 7089*/
  _x05_5624 = kk_climate_dash_experiments__new_mlift5643_run__experiments_fun8278(_bv_7090, _ctx); /*effects-and-types/model<(double, double),div>*/
  _b_7113_7099 = kk_climate_dash_experiments__new_mlift5643_run__experiments_fun8280(_x05_5624, _ctx); /*() -> <effects-and-types/sample,effects-and-types/score,div> (double, double)*/
  kk_effects_dash_and_dash_types__exp _b_7115_7101 = kk_effects_dash_and_dash_types__new_Exp(0x0p+0, _ctx); /*effects-and-types/exp*/;
  _x8271 = kk_tmcmc_tmcmc(kk_climate_dash_experiments__new_mlift5643_run__experiments_fun8285(_b_7113_7099, _ctx), kk_integer_from_small(100), _b_7115_7101, kk_integer_from_small(0), _ctx); /*(list<(list<double>, 0)>, tmcmc/trace<0,<effects-and-types/sample,effects-and-types/score,div|1>>)*/
  return kk_std_core_types__tuple2__box(_x8271, _ctx);
}
static kk_box_t kk_climate_dash_experiments__mlift5643_run__experiments_fun8267(kk_function_t _fself, kk_box_t _b_7107, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core_types__tuple2_ _match_7480 = kk_std_core_types__tuple2__unbox(_b_7107, _ctx); /*(int, list<(double, bool)>)*/;
  kk_box_t _box_x7082 = _match_7480.fst;
  kk_box_t _box_x7083 = _match_7480.snd;
  kk_std_core__list data__vals0 = kk_std_core__list_unbox(_box_x7083, NULL);
  kk_std_core__list_dup(data__vals0);
  kk_std_core_types__tuple2__drop(_match_7480, _ctx);
  return kk_std_time_timer_print_elapsed(kk_climate_dash_experiments__new_mlift5643_run__experiments_fun8270(data__vals0, _ctx), kk_std_core_types__new_None(_ctx), _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift5643_run__experiments_fun8288__t {
  struct kk_function_s _base;
  kk_std_core__list data__50;
  kk_std_core__list data__points;
  kk_integer_t i1;
};
static kk_box_t kk_climate_dash_experiments__mlift5643_run__experiments_fun8288(kk_function_t _fself, kk_box_t _b_7124, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5643_run__experiments_fun8288(kk_std_core__list data__50, kk_std_core__list data__points, kk_integer_t i1, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5643_run__experiments_fun8288__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5643_run__experiments_fun8288__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5643_run__experiments_fun8288, kk_context());
  _self->data__50 = data__50;
  _self->data__points = data__points;
  _self->i1 = i1;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift5643_run__experiments_fun8288(kk_function_t _fself, kk_box_t _b_7124, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5643_run__experiments_fun8288__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5643_run__experiments_fun8288__t*, _fself);
  kk_std_core__list data__50 = _self->data__50; /* list<(double, bool)> */
  kk_std_core__list data__points = _self->data__points; /* list<(int, list<(double, bool)>)> */
  kk_integer_t i1 = _self->i1; /* int */
  kk_drop_match(_self, {kk_std_core__list_dup(data__50);kk_std_core__list_dup(data__points);kk_integer_dup(i1);}, {}, _ctx)
  kk_unit_t _x8289 = kk_Unit;
  kk_std_core__list _x8290 = kk_std_core__list_unbox(_b_7124, _ctx); /*list<(list<(list<double>, (double, double))>, tmcmc/trace<(double, double),<effects-and-types/sample,effects-and-types/score,div,console,ndet,exn,std/num/random/random>>)>*/
  kk_climate_dash_experiments__mlift5642_run__experiments(data__50, data__points, i1, _x8290, _ctx);
  return kk_unit_box(_x8289);
}

kk_unit_t kk_climate_dash_experiments__mlift5643_run__experiments(kk_std_core__list data__50, kk_std_core__list data__points, kk_integer_t i1, kk_std_core__list wild__4, kk_context_t* _ctx) { /* (data_50 : list<(double, bool)>, data_points : list<(int, list<(double, bool)>)>, i1 : int, wild_4 : list<effects-and-types/histogram<(double, double)>>) -> <console,div,exn,ndet,std/num/random/random,effects-and-types/sample> () */ 
  kk_std_core__list_drop(wild__4, _ctx);
  kk_unit_t __5 = kk_Unit;
  kk_string_t _x8262;
  kk_define_string_literal(, _s8263, 14, "Completed SMC!")
  _x8262 = kk_string_dup(_s8263); /*string*/
  kk_std_core_printsln(_x8262, _ctx);
  kk_unit_t __6 = kk_Unit;
  kk_string_t _x8264;
  kk_define_string_literal(, _s8265, 40, "Running TMCMC with increasing data size:")
  _x8264 = kk_string_dup(_s8265); /*string*/
  kk_std_core_printsln(_x8264, _ctx);
  kk_std_core__list x_5836;
  kk_std_core__list _x8266 = kk_std_core__list_dup(data__points); /*list<(int, list<(double, bool)>)>*/
  x_5836 = kk_std_core_map_5(_x8266, kk_climate_dash_experiments__new_mlift5643_run__experiments_fun8267(_ctx), _ctx); /*list<(list<(list<double>, (double, double))>, tmcmc/trace<(double, double),<effects-and-types/sample,effects-and-types/score,div,console,ndet,exn,std/num/random/random>>)>*/
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_5836, _ctx);
    kk_box_t _x8287 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments__new_mlift5643_run__experiments_fun8288(data__50, data__points, i1, _ctx), _ctx); /*2*/
    kk_unit_unbox(_x8287); return kk_Unit;
  }
  kk_climate_dash_experiments__mlift5642_run__experiments(data__50, data__points, i1, x_5836, _ctx); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_climate_dash_experiments__mlift5644_run__experiments_fun8297__t {
  struct kk_function_s _base;
  kk_std_core__list data__50;
};
static kk_box_t kk_climate_dash_experiments__mlift5644_run__experiments_fun8297(kk_function_t _fself, kk_box_t _b_7171, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5644_run__experiments_fun8297(kk_std_core__list data__50, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5644_run__experiments_fun8297__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5644_run__experiments_fun8297__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5644_run__experiments_fun8297, kk_context());
  _self->data__50 = data__50;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift5644_run__experiments_fun8300__t {
  struct kk_function_s _base;
  kk_std_core__list data__50;
  kk_integer_t sz0;
};
static kk_box_t kk_climate_dash_experiments__mlift5644_run__experiments_fun8300(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5644_run__experiments_fun8300(kk_std_core__list data__50, kk_integer_t sz0, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5644_run__experiments_fun8300__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5644_run__experiments_fun8300__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5644_run__experiments_fun8300, kk_context());
  _self->data__50 = data__50;
  _self->sz0 = sz0;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift5644_run__experiments_fun8303__t {
  struct kk_function_s _base;
};
static kk_box_t kk_climate_dash_experiments__mlift5644_run__experiments_fun8303(kk_function_t _fself, kk_box_t _b_7131, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5644_run__experiments_fun8303(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_climate_dash_experiments__mlift5644_run__experiments_fun8303, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift5644_run__experiments_fun8306__t {
  struct kk_function_s _base;
  kk_function_t _bv_7133;
};
static kk_box_t kk_climate_dash_experiments__mlift5644_run__experiments_fun8306(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5644_run__experiments_fun8306(kk_function_t _bv_7133, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5644_run__experiments_fun8306__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5644_run__experiments_fun8306__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5644_run__experiments_fun8306, kk_context());
  _self->_bv_7133 = _bv_7133;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift5644_run__experiments_fun8306(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5644_run__experiments_fun8306__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5644_run__experiments_fun8306__t*, _fself);
  kk_function_t _bv_7133 = _self->_bv_7133; /* effects-and-types/model<(double, double),div> */
  kk_drop_match(_self, {kk_function_dup(_bv_7133);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x8307 = kk_function_call(kk_std_core_types__tuple2_, (kk_function_t, kk_context_t*), _bv_7133, (_bv_7133, _ctx)); /*(double, double)*/
  return kk_std_core_types__tuple2__box(_x8307, _ctx);
}
static kk_box_t kk_climate_dash_experiments__mlift5644_run__experiments_fun8303(kk_function_t _fself, kk_box_t _b_7131, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_function_t _x8304;
  kk_function_t _bv_7133;
  kk_std_core__list _x8305 = kk_std_core__list_unbox(_b_7131, _ctx); /*list<(double, bool)>*/
  _bv_7133 = kk_model_dash_resources_logistic__regression(_x8305, _ctx); /*effects-and-types/model<(double, double),div>*/
  _x8304 = kk_climate_dash_experiments__new_mlift5644_run__experiments_fun8306(_bv_7133, _ctx); /*() -> <effects-and-types/sample,effects-and-types/score,div> 7132*/
  return kk_function_box(_x8304);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift5644_run__experiments_fun8308__t {
  struct kk_function_s _base;
  kk_function_t _bv_7135;
};
static kk_std_core_types__tuple2_ kk_climate_dash_experiments__mlift5644_run__experiments_fun8308(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5644_run__experiments_fun8308(kk_function_t _bv_7135, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5644_run__experiments_fun8308__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5644_run__experiments_fun8308__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5644_run__experiments_fun8308, kk_context());
  _self->_bv_7135 = _bv_7135;
  return &_self->_base;
}

static kk_std_core_types__tuple2_ kk_climate_dash_experiments__mlift5644_run__experiments_fun8308(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5644_run__experiments_fun8308__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5644_run__experiments_fun8308__t*, _fself);
  kk_function_t _bv_7135 = _self->_bv_7135; /* () -> <.Box|.Box> 7134 */
  kk_drop_match(_self, {kk_function_dup(_bv_7135);}, {}, _ctx)
  kk_box_t _x8309 = kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), _bv_7135, (_bv_7135, _ctx)); /*7134*/
  return kk_std_core_types__tuple2__unbox(_x8309, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift5644_run__experiments_fun8310__t {
  struct kk_function_s _base;
  kk_function_t _x03_5622;
};
static kk_std_core_types__tuple2_ kk_climate_dash_experiments__mlift5644_run__experiments_fun8310(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5644_run__experiments_fun8310(kk_function_t _x03_5622, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5644_run__experiments_fun8310__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5644_run__experiments_fun8310__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5644_run__experiments_fun8310, kk_context());
  _self->_x03_5622 = _x03_5622;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift5644_run__experiments_fun8313__t {
  struct kk_function_s _base;
  kk_function_t _x03_5622;
};
static kk_box_t kk_climate_dash_experiments__mlift5644_run__experiments_fun8313(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5644_run__experiments_fun8313(kk_function_t _x03_5622, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5644_run__experiments_fun8313__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5644_run__experiments_fun8313__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5644_run__experiments_fun8313, kk_context());
  _self->_x03_5622 = _x03_5622;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift5644_run__experiments_fun8313(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5644_run__experiments_fun8313__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5644_run__experiments_fun8313__t*, _fself);
  kk_function_t _x03_5622 = _self->_x03_5622; /* effects-and-types/model<(double, double),div> */
  kk_drop_match(_self, {kk_function_dup(_x03_5622);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x8314 = kk_function_call(kk_std_core_types__tuple2_, (kk_function_t, kk_context_t*), _x03_5622, (_x03_5622, _ctx)); /*(double, double)*/
  return kk_std_core_types__tuple2__box(_x8314, _ctx);
}
static kk_std_core_types__tuple2_ kk_climate_dash_experiments__mlift5644_run__experiments_fun8310(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5644_run__experiments_fun8310__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5644_run__experiments_fun8310__t*, _fself);
  kk_function_t _x03_5622 = _self->_x03_5622; /* effects-and-types/model<(double, double),div> */
  kk_drop_match(_self, {kk_function_dup(_x03_5622);}, {}, _ctx)
  kk_vector_t _b_7144_7142;
  kk_std_core__list _x8311;
  size_t _b_7146_7140 = ((size_t)2); /*std/core/hnd/ev-index*/;
  kk_std_core__list _b_7147_7141;
  size_t _b_7148_7138 = ((size_t)4); /*std/core/hnd/ev-index*/;
  _b_7147_7141 = kk_std_core__new_Cons(kk_reuse_null, kk_size_box(_b_7148_7138, _ctx), kk_std_core__new_Nil(_ctx), _ctx); /*list<std/core/hnd/ev-index>*/
  _x8311 = kk_std_core__new_Cons(kk_reuse_null, kk_size_box(_b_7146_7140, _ctx), _b_7147_7141, _ctx); /*list<0>*/
  _b_7144_7142 = kk_std_core_unvlist(_x8311, _ctx); /*vector<std/core/hnd/ev-index>*/
  kk_box_t _x8312 = kk_std_core_hnd__open0(_b_7144_7142, kk_climate_dash_experiments__new_mlift5644_run__experiments_fun8313(_x03_5622, _ctx), _ctx); /*1*/
  return kk_std_core_types__tuple2__unbox(_x8312, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift5644_run__experiments_fun8316__t {
  struct kk_function_s _base;
  kk_function_t model_5845;
  kk_integer_t sz0;
};
static kk_box_t kk_climate_dash_experiments__mlift5644_run__experiments_fun8316(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5644_run__experiments_fun8316(kk_function_t model_5845, kk_integer_t sz0, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5644_run__experiments_fun8316__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5644_run__experiments_fun8316__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5644_run__experiments_fun8316, kk_context());
  _self->model_5845 = model_5845;
  _self->sz0 = sz0;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift5644_run__experiments_fun8318__t {
  struct kk_function_s _base;
  kk_function_t model_5845;
};
static kk_box_t kk_climate_dash_experiments__mlift5644_run__experiments_fun8318(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5644_run__experiments_fun8318(kk_function_t model_5845, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5644_run__experiments_fun8318__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5644_run__experiments_fun8318__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5644_run__experiments_fun8318, kk_context());
  _self->model_5845 = model_5845;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift5644_run__experiments_fun8320__t {
  struct kk_function_s _base;
  kk_function_t model_5845;
};
static kk_box_t kk_climate_dash_experiments__mlift5644_run__experiments_fun8320(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5644_run__experiments_fun8320(kk_function_t model_5845, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5644_run__experiments_fun8320__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5644_run__experiments_fun8320__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5644_run__experiments_fun8320, kk_context());
  _self->model_5845 = model_5845;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift5644_run__experiments_fun8321__t {
  struct kk_function_s _base;
  kk_function_t model_5845;
};
static kk_box_t kk_climate_dash_experiments__mlift5644_run__experiments_fun8321(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5644_run__experiments_fun8321(kk_function_t model_5845, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5644_run__experiments_fun8321__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5644_run__experiments_fun8321__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5644_run__experiments_fun8321, kk_context());
  _self->model_5845 = model_5845;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift5644_run__experiments_fun8321(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5644_run__experiments_fun8321__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5644_run__experiments_fun8321__t*, _fself);
  kk_function_t model_5845 = _self->model_5845; /* () -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random,console,ndet,effects-and-types/sample> (double, double) */
  kk_drop_match(_self, {kk_function_dup(model_5845);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x8322 = kk_function_call(kk_std_core_types__tuple2_, (kk_function_t, kk_context_t*), model_5845, (model_5845, _ctx)); /*(double, double)*/
  return kk_std_core_types__tuple2__box(_x8322, _ctx);
}
static kk_box_t kk_climate_dash_experiments__mlift5644_run__experiments_fun8320(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5644_run__experiments_fun8320__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5644_run__experiments_fun8320__t*, _fself);
  kk_function_t model_5845 = _self->model_5845; /* () -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random,console,ndet,effects-and-types/sample> (double, double) */
  kk_drop_match(_self, {kk_function_dup(model_5845);}, {}, _ctx)
  return kk_handlers_yield__on__score(kk_climate_dash_experiments__new_mlift5644_run__experiments_fun8321(model_5845, _ctx), _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift5644_run__experiments_fun8323__t {
  struct kk_function_s _base;
  kk_function_t _bv_7152;
};
static kk_std_core_types__tuple2_ kk_climate_dash_experiments__mlift5644_run__experiments_fun8323(kk_function_t _fself, kk_integer_t _b_7153, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5644_run__experiments_fun8323(kk_function_t _bv_7152, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5644_run__experiments_fun8323__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5644_run__experiments_fun8323__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5644_run__experiments_fun8323, kk_context());
  _self->_bv_7152 = _bv_7152;
  return &_self->_base;
}

static kk_std_core_types__tuple2_ kk_climate_dash_experiments__mlift5644_run__experiments_fun8323(kk_function_t _fself, kk_integer_t _b_7153, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5644_run__experiments_fun8323__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5644_run__experiments_fun8323__t*, _fself);
  kk_function_t _bv_7152 = _self->_bv_7152; /* (a : int) -> <effects-and-types/yield|1> 0 */
  kk_drop_match(_self, {kk_function_dup(_bv_7152);}, {}, _ctx)
  kk_box_t _x8324 = kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_context_t*), _bv_7152, (_bv_7152, _b_7153, _ctx)); /*0*/
  return kk_std_core_types__tuple2__unbox(_x8324, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift5644_run__experiments_fun8325__t {
  struct kk_function_s _base;
  kk_function_t _bv_7158;
};
static kk_box_t kk_climate_dash_experiments__mlift5644_run__experiments_fun8325(kk_function_t _fself, kk_box_t _b_7159, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5644_run__experiments_fun8325(kk_function_t _bv_7158, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5644_run__experiments_fun8325__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5644_run__experiments_fun8325__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5644_run__experiments_fun8325, kk_context());
  _self->_bv_7158 = _bv_7158;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift5644_run__experiments_fun8325(kk_function_t _fself, kk_box_t _b_7159, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5644_run__experiments_fun8325__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5644_run__experiments_fun8325__t*, _fself);
  kk_function_t _bv_7158 = _self->_bv_7158; /* (a : int) -> <effects-and-types/yield,effects-and-types/sample,effects-and-types/score,div,exn,std/num/random/random,console,ndet,effects-and-types/sample> (double, double) */
  kk_drop_match(_self, {kk_function_dup(_bv_7158);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x8326;
  kk_integer_t _x8327 = kk_integer_unbox(_b_7159); /*int*/
  _x8326 = kk_function_call(kk_std_core_types__tuple2_, (kk_function_t, kk_integer_t, kk_context_t*), _bv_7158, (_bv_7158, _x8327, _ctx)); /*(double, double)*/
  return kk_std_core_types__tuple2__box(_x8326, _ctx);
}
static kk_box_t kk_climate_dash_experiments__mlift5644_run__experiments_fun8318(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5644_run__experiments_fun8318__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5644_run__experiments_fun8318__t*, _fself);
  kk_function_t model_5845 = _self->model_5845; /* () -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random,console,ndet,effects-and-types/sample> (double, double) */
  kk_drop_match(_self, {kk_function_dup(model_5845);}, {}, _ctx)
  kk_function_t _x8319;
  kk_function_t _bv_7158;
  kk_function_t _bv_7152 = kk_handlers_advance(kk_climate_dash_experiments__new_mlift5644_run__experiments_fun8320(model_5845, _ctx), _ctx); /*(a : int) -> <effects-and-types/yield|1> 0*/;
  _bv_7158 = kk_climate_dash_experiments__new_mlift5644_run__experiments_fun8323(_bv_7152, _ctx); /*(a : int) -> <effects-and-types/yield,effects-and-types/sample,effects-and-types/score,div,exn,std/num/random/random,console,ndet,effects-and-types/sample> (double, double)*/
  _x8319 = kk_climate_dash_experiments__new_mlift5644_run__experiments_fun8325(_bv_7158, _ctx); /*(7156) -> <effects-and-types/yield,effects-and-types/sample,effects-and-types/score,div,exn,std/num/random/random,console,ndet,effects-and-types/sample> 7157*/
  return kk_function_box(_x8319);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift5644_run__experiments_fun8329__t {
  struct kk_function_s _base;
};
static kk_box_t kk_climate_dash_experiments__mlift5644_run__experiments_fun8329(kk_function_t _fself, kk_box_t _b_7165, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5644_run__experiments_fun8329(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_climate_dash_experiments__mlift5644_run__experiments_fun8329, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_climate_dash_experiments__mlift5644_run__experiments_fun8329(kk_function_t _fself, kk_box_t _b_7165, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core__list _x8330;
  kk_std_core__list _x8331 = kk_std_core__list_unbox(_b_7165, _ctx); /*effects-and-types/histogram<(a : int) -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random,console,ndet,effects-and-types/sample> (double, double)>*/
  _x8330 = kk_smc__mlift743_smc(true, kk_integer_from_small(50), kk_integer_from_small(1), _x8331, _ctx); /*effects-and-types/histogram<24>*/
  return kk_std_core__list_box(_x8330, _ctx);
}
static kk_box_t kk_climate_dash_experiments__mlift5644_run__experiments_fun8316(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5644_run__experiments_fun8316__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5644_run__experiments_fun8316__t*, _fself);
  kk_function_t model_5845 = _self->model_5845; /* () -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random,console,ndet,effects-and-types/sample> (double, double) */
  kk_integer_t sz0 = _self->sz0; /* int */
  kk_drop_match(_self, {kk_function_dup(model_5845);kk_integer_dup(sz0);}, {}, _ctx)
  kk_std_core__list _x8317;
  kk_std_core__list x_775 = kk_sampling_populate(sz0, kk_climate_dash_experiments__new_mlift5644_run__experiments_fun8318(model_5845, _ctx), _ctx); /*effects-and-types/histogram<(a : int) -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random,console,ndet,effects-and-types/sample> (double, double)>*/;
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_775, _ctx);
    kk_box_t _x8328 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments__new_mlift5644_run__experiments_fun8329(_ctx), _ctx); /*2*/
    _x8317 = kk_std_core__list_unbox(_x8328, _ctx); /*effects-and-types/histogram<(double, double)>*/
  }
  else {
    _x8317 = kk_smc__mlift743_smc(true, kk_integer_from_small(50), kk_integer_from_small(1), x_775, _ctx); /*effects-and-types/histogram<(double, double)>*/
  }
  return kk_std_core__list_box(_x8317, _ctx);
}
static kk_box_t kk_climate_dash_experiments__mlift5644_run__experiments_fun8300(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5644_run__experiments_fun8300__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5644_run__experiments_fun8300__t*, _fself);
  kk_std_core__list data__50 = _self->data__50; /* list<(double, bool)> */
  kk_integer_t sz0 = _self->sz0; /* int */
  kk_drop_match(_self, {kk_std_core__list_dup(data__50);kk_integer_dup(sz0);}, {}, _ctx)
  kk_std_core__list _x8301;
  kk_function_t model_5845;
  kk_function_t _x03_5622;
  kk_function_t _bv_7135;
  kk_box_t _x8302 = kk_std_core_hnd__open_none1(kk_climate_dash_experiments__new_mlift5644_run__experiments_fun8303(_ctx), kk_std_core__list_box(data__50, _ctx), _ctx); /*2*/
  _bv_7135 = kk_function_unbox(_x8302); /*() -> <.Box|.Box> 7134*/
  _x03_5622 = kk_climate_dash_experiments__new_mlift5644_run__experiments_fun8308(_bv_7135, _ctx); /*effects-and-types/model<(double, double),div>*/
  model_5845 = kk_climate_dash_experiments__new_mlift5644_run__experiments_fun8310(_x03_5622, _ctx); /*() -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random,console,ndet,effects-and-types/sample> (double, double)*/
  kk_box_t _x8315 = kk_handlers_random__sampler(kk_climate_dash_experiments__new_mlift5644_run__experiments_fun8316(model_5845, sz0, _ctx), _ctx); /*0*/
  _x8301 = kk_std_core__list_unbox(_x8315, _ctx); /*effects-and-types/histogram<(double, double)>*/
  return kk_std_core__list_box(_x8301, _ctx);
}
static kk_box_t kk_climate_dash_experiments__mlift5644_run__experiments_fun8297(kk_function_t _fself, kk_box_t _b_7171, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5644_run__experiments_fun8297__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5644_run__experiments_fun8297__t*, _fself);
  kk_std_core__list data__50 = _self->data__50; /* list<(double, bool)> */
  kk_drop_match(_self, {kk_std_core__list_dup(data__50);}, {}, _ctx)
  kk_std_core_types__tuple2_ _match_7477 = kk_std_core_types__tuple2__unbox(_b_7171, _ctx); /*(int, list<(double, bool)>)*/;
  kk_box_t _box_x7127 = _match_7477.fst;
  kk_box_t _box_x7128 = _match_7477.snd;
  kk_integer_t sz0 = kk_integer_unbox(_box_x7127);
  kk_integer_dup(sz0);
  kk_std_core_types__tuple2__drop(_match_7477, _ctx);
  return kk_std_time_timer_print_elapsed(kk_climate_dash_experiments__new_mlift5644_run__experiments_fun8300(data__50, sz0, _ctx), kk_std_core_types__new_None(_ctx), _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift5644_run__experiments_fun8333__t {
  struct kk_function_s _base;
  kk_std_core__list data__50;
  kk_std_core__list data__points;
  kk_integer_t i1;
};
static kk_box_t kk_climate_dash_experiments__mlift5644_run__experiments_fun8333(kk_function_t _fself, kk_box_t _b_7181, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5644_run__experiments_fun8333(kk_std_core__list data__50, kk_std_core__list data__points, kk_integer_t i1, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5644_run__experiments_fun8333__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5644_run__experiments_fun8333__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5644_run__experiments_fun8333, kk_context());
  _self->data__50 = data__50;
  _self->data__points = data__points;
  _self->i1 = i1;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift5644_run__experiments_fun8333(kk_function_t _fself, kk_box_t _b_7181, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5644_run__experiments_fun8333__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5644_run__experiments_fun8333__t*, _fself);
  kk_std_core__list data__50 = _self->data__50; /* list<(double, bool)> */
  kk_std_core__list data__points = _self->data__points; /* list<(int, list<(double, bool)>)> */
  kk_integer_t i1 = _self->i1; /* int */
  kk_drop_match(_self, {kk_std_core__list_dup(data__50);kk_std_core__list_dup(data__points);kk_integer_dup(i1);}, {}, _ctx)
  kk_unit_t _x8334 = kk_Unit;
  kk_std_core__list _x8335 = kk_std_core__list_unbox(_b_7181, _ctx); /*list<effects-and-types/histogram<(double, double)>>*/
  kk_climate_dash_experiments__mlift5643_run__experiments(data__50, data__points, i1, _x8335, _ctx);
  return kk_unit_box(_x8334);
}

kk_unit_t kk_climate_dash_experiments__mlift5644_run__experiments(kk_std_core__list data__50, kk_std_core__list data__points, kk_integer_t i1, kk_std_core__list wild__1, kk_context_t* _ctx) { /* (data_50 : list<(double, bool)>, data_points : list<(int, list<(double, bool)>)>, i1 : int, wild_1 : list<effects-and-types/histogram<(double, double)>>) -> <console,div,exn,ndet,std/num/random/random,effects-and-types/sample> () */ 
  kk_std_core__list_drop(wild__1, _ctx);
  kk_unit_t __2 = kk_Unit;
  kk_string_t _x8291;
  kk_define_string_literal(, _s8292, 16, "Mid-way with SMC")
  _x8291 = kk_string_dup(_s8292); /*string*/
  kk_std_core_printsln(_x8291, _ctx);
  kk_unit_t __3 = kk_Unit;
  kk_string_t _x8293;
  kk_define_string_literal(, _s8294, 48, "Running SMC with increasing number of particles:")
  _x8293 = kk_string_dup(_s8294); /*string*/
  kk_std_core_printsln(_x8293, _ctx);
  kk_std_core__list x_5840;
  kk_std_core__list _x8295 = kk_std_core__list_dup(data__points); /*list<(int, list<(double, bool)>)>*/
  kk_function_t _x8296;
  kk_std_core__list_dup(data__50);
  _x8296 = kk_climate_dash_experiments__new_mlift5644_run__experiments_fun8297(data__50, _ctx); /*(1) -> 3 0*/
  x_5840 = kk_std_core_map_5(_x8295, _x8296, _ctx); /*list<effects-and-types/histogram<(double, double)>>*/
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_5840, _ctx);
    kk_box_t _x8332 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments__new_mlift5644_run__experiments_fun8333(data__50, data__points, i1, _ctx), _ctx); /*2*/
    kk_unit_unbox(_x8332); return kk_Unit;
  }
  kk_climate_dash_experiments__mlift5643_run__experiments(data__50, data__points, i1, x_5840, _ctx); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_climate_dash_experiments__mlift5645_run__experiments_fun8336__t {
  struct kk_function_s _base;
  kk_std_core__list data__50;
  kk_std_core__list data__points;
};
static kk_unit_t kk_climate_dash_experiments__mlift5645_run__experiments_fun8336(kk_function_t _fself, kk_integer_t i1, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5645_run__experiments_fun8336(kk_std_core__list data__50, kk_std_core__list data__points, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5645_run__experiments_fun8336__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5645_run__experiments_fun8336__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5645_run__experiments_fun8336, kk_context());
  _self->data__50 = data__50;
  _self->data__points = data__points;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift5645_run__experiments_fun8344__t {
  struct kk_function_s _base;
};
static kk_box_t kk_climate_dash_experiments__mlift5645_run__experiments_fun8344(kk_function_t _fself, kk_box_t _b_7228, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5645_run__experiments_fun8344(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_climate_dash_experiments__mlift5645_run__experiments_fun8344, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift5645_run__experiments_fun8347__t {
  struct kk_function_s _base;
  kk_std_core__list data__vals;
  kk_integer_t sz;
};
static kk_box_t kk_climate_dash_experiments__mlift5645_run__experiments_fun8347(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5645_run__experiments_fun8347(kk_std_core__list data__vals, kk_integer_t sz, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5645_run__experiments_fun8347__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5645_run__experiments_fun8347__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5645_run__experiments_fun8347, kk_context());
  _self->data__vals = data__vals;
  _self->sz = sz;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift5645_run__experiments_fun8350__t {
  struct kk_function_s _base;
};
static kk_box_t kk_climate_dash_experiments__mlift5645_run__experiments_fun8350(kk_function_t _fself, kk_box_t _b_7188, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5645_run__experiments_fun8350(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_climate_dash_experiments__mlift5645_run__experiments_fun8350, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift5645_run__experiments_fun8353__t {
  struct kk_function_s _base;
  kk_function_t _bv_7190;
};
static kk_box_t kk_climate_dash_experiments__mlift5645_run__experiments_fun8353(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5645_run__experiments_fun8353(kk_function_t _bv_7190, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5645_run__experiments_fun8353__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5645_run__experiments_fun8353__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5645_run__experiments_fun8353, kk_context());
  _self->_bv_7190 = _bv_7190;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift5645_run__experiments_fun8353(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5645_run__experiments_fun8353__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5645_run__experiments_fun8353__t*, _fself);
  kk_function_t _bv_7190 = _self->_bv_7190; /* effects-and-types/model<(double, double),div> */
  kk_drop_match(_self, {kk_function_dup(_bv_7190);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x8354 = kk_function_call(kk_std_core_types__tuple2_, (kk_function_t, kk_context_t*), _bv_7190, (_bv_7190, _ctx)); /*(double, double)*/
  return kk_std_core_types__tuple2__box(_x8354, _ctx);
}
static kk_box_t kk_climate_dash_experiments__mlift5645_run__experiments_fun8350(kk_function_t _fself, kk_box_t _b_7188, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_function_t _x8351;
  kk_function_t _bv_7190;
  kk_std_core__list _x8352 = kk_std_core__list_unbox(_b_7188, _ctx); /*list<(double, bool)>*/
  _bv_7190 = kk_model_dash_resources_logistic__regression(_x8352, _ctx); /*effects-and-types/model<(double, double),div>*/
  _x8351 = kk_climate_dash_experiments__new_mlift5645_run__experiments_fun8353(_bv_7190, _ctx); /*() -> <effects-and-types/sample,effects-and-types/score,div> 7189*/
  return kk_function_box(_x8351);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift5645_run__experiments_fun8355__t {
  struct kk_function_s _base;
  kk_function_t _bv_7192;
};
static kk_std_core_types__tuple2_ kk_climate_dash_experiments__mlift5645_run__experiments_fun8355(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5645_run__experiments_fun8355(kk_function_t _bv_7192, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5645_run__experiments_fun8355__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5645_run__experiments_fun8355__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5645_run__experiments_fun8355, kk_context());
  _self->_bv_7192 = _bv_7192;
  return &_self->_base;
}

static kk_std_core_types__tuple2_ kk_climate_dash_experiments__mlift5645_run__experiments_fun8355(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5645_run__experiments_fun8355__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5645_run__experiments_fun8355__t*, _fself);
  kk_function_t _bv_7192 = _self->_bv_7192; /* () -> <.Box|.Box> 7191 */
  kk_drop_match(_self, {kk_function_dup(_bv_7192);}, {}, _ctx)
  kk_box_t _x8356 = kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), _bv_7192, (_bv_7192, _ctx)); /*7191*/
  return kk_std_core_types__tuple2__unbox(_x8356, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift5645_run__experiments_fun8357__t {
  struct kk_function_s _base;
  kk_function_t _x01_5620;
};
static kk_std_core_types__tuple2_ kk_climate_dash_experiments__mlift5645_run__experiments_fun8357(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5645_run__experiments_fun8357(kk_function_t _x01_5620, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5645_run__experiments_fun8357__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5645_run__experiments_fun8357__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5645_run__experiments_fun8357, kk_context());
  _self->_x01_5620 = _x01_5620;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift5645_run__experiments_fun8360__t {
  struct kk_function_s _base;
  kk_function_t _x01_5620;
};
static kk_box_t kk_climate_dash_experiments__mlift5645_run__experiments_fun8360(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5645_run__experiments_fun8360(kk_function_t _x01_5620, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5645_run__experiments_fun8360__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5645_run__experiments_fun8360__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5645_run__experiments_fun8360, kk_context());
  _self->_x01_5620 = _x01_5620;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift5645_run__experiments_fun8360(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5645_run__experiments_fun8360__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5645_run__experiments_fun8360__t*, _fself);
  kk_function_t _x01_5620 = _self->_x01_5620; /* effects-and-types/model<(double, double),div> */
  kk_drop_match(_self, {kk_function_dup(_x01_5620);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x8361 = kk_function_call(kk_std_core_types__tuple2_, (kk_function_t, kk_context_t*), _x01_5620, (_x01_5620, _ctx)); /*(double, double)*/
  return kk_std_core_types__tuple2__box(_x8361, _ctx);
}
static kk_std_core_types__tuple2_ kk_climate_dash_experiments__mlift5645_run__experiments_fun8357(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5645_run__experiments_fun8357__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5645_run__experiments_fun8357__t*, _fself);
  kk_function_t _x01_5620 = _self->_x01_5620; /* effects-and-types/model<(double, double),div> */
  kk_drop_match(_self, {kk_function_dup(_x01_5620);}, {}, _ctx)
  kk_vector_t _b_7201_7199;
  kk_std_core__list _x8358;
  size_t _b_7203_7197 = ((size_t)2); /*std/core/hnd/ev-index*/;
  kk_std_core__list _b_7204_7198;
  size_t _b_7205_7195 = ((size_t)4); /*std/core/hnd/ev-index*/;
  _b_7204_7198 = kk_std_core__new_Cons(kk_reuse_null, kk_size_box(_b_7205_7195, _ctx), kk_std_core__new_Nil(_ctx), _ctx); /*list<std/core/hnd/ev-index>*/
  _x8358 = kk_std_core__new_Cons(kk_reuse_null, kk_size_box(_b_7203_7197, _ctx), _b_7204_7198, _ctx); /*list<0>*/
  _b_7201_7199 = kk_std_core_unvlist(_x8358, _ctx); /*vector<std/core/hnd/ev-index>*/
  kk_box_t _x8359 = kk_std_core_hnd__open0(_b_7201_7199, kk_climate_dash_experiments__new_mlift5645_run__experiments_fun8360(_x01_5620, _ctx), _ctx); /*1*/
  return kk_std_core_types__tuple2__unbox(_x8359, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift5645_run__experiments_fun8363__t {
  struct kk_function_s _base;
  kk_function_t model_5857;
  kk_integer_t sz;
};
static kk_box_t kk_climate_dash_experiments__mlift5645_run__experiments_fun8363(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5645_run__experiments_fun8363(kk_function_t model_5857, kk_integer_t sz, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5645_run__experiments_fun8363__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5645_run__experiments_fun8363__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5645_run__experiments_fun8363, kk_context());
  _self->model_5857 = model_5857;
  _self->sz = sz;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift5645_run__experiments_fun8365__t {
  struct kk_function_s _base;
  kk_function_t model_5857;
};
static kk_box_t kk_climate_dash_experiments__mlift5645_run__experiments_fun8365(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5645_run__experiments_fun8365(kk_function_t model_5857, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5645_run__experiments_fun8365__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5645_run__experiments_fun8365__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5645_run__experiments_fun8365, kk_context());
  _self->model_5857 = model_5857;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift5645_run__experiments_fun8367__t {
  struct kk_function_s _base;
  kk_function_t model_5857;
};
static kk_box_t kk_climate_dash_experiments__mlift5645_run__experiments_fun8367(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5645_run__experiments_fun8367(kk_function_t model_5857, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5645_run__experiments_fun8367__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5645_run__experiments_fun8367__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5645_run__experiments_fun8367, kk_context());
  _self->model_5857 = model_5857;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift5645_run__experiments_fun8368__t {
  struct kk_function_s _base;
  kk_function_t model_5857;
};
static kk_box_t kk_climate_dash_experiments__mlift5645_run__experiments_fun8368(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5645_run__experiments_fun8368(kk_function_t model_5857, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5645_run__experiments_fun8368__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5645_run__experiments_fun8368__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5645_run__experiments_fun8368, kk_context());
  _self->model_5857 = model_5857;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift5645_run__experiments_fun8368(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5645_run__experiments_fun8368__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5645_run__experiments_fun8368__t*, _fself);
  kk_function_t model_5857 = _self->model_5857; /* () -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random,console,ndet,effects-and-types/sample> (double, double) */
  kk_drop_match(_self, {kk_function_dup(model_5857);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x8369 = kk_function_call(kk_std_core_types__tuple2_, (kk_function_t, kk_context_t*), model_5857, (model_5857, _ctx)); /*(double, double)*/
  return kk_std_core_types__tuple2__box(_x8369, _ctx);
}
static kk_box_t kk_climate_dash_experiments__mlift5645_run__experiments_fun8367(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5645_run__experiments_fun8367__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5645_run__experiments_fun8367__t*, _fself);
  kk_function_t model_5857 = _self->model_5857; /* () -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random,console,ndet,effects-and-types/sample> (double, double) */
  kk_drop_match(_self, {kk_function_dup(model_5857);}, {}, _ctx)
  return kk_handlers_yield__on__score(kk_climate_dash_experiments__new_mlift5645_run__experiments_fun8368(model_5857, _ctx), _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift5645_run__experiments_fun8370__t {
  struct kk_function_s _base;
  kk_function_t _bv_7209;
};
static kk_std_core_types__tuple2_ kk_climate_dash_experiments__mlift5645_run__experiments_fun8370(kk_function_t _fself, kk_integer_t _b_7210, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5645_run__experiments_fun8370(kk_function_t _bv_7209, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5645_run__experiments_fun8370__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5645_run__experiments_fun8370__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5645_run__experiments_fun8370, kk_context());
  _self->_bv_7209 = _bv_7209;
  return &_self->_base;
}

static kk_std_core_types__tuple2_ kk_climate_dash_experiments__mlift5645_run__experiments_fun8370(kk_function_t _fself, kk_integer_t _b_7210, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5645_run__experiments_fun8370__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5645_run__experiments_fun8370__t*, _fself);
  kk_function_t _bv_7209 = _self->_bv_7209; /* (a : int) -> <effects-and-types/yield|1> 0 */
  kk_drop_match(_self, {kk_function_dup(_bv_7209);}, {}, _ctx)
  kk_box_t _x8371 = kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_context_t*), _bv_7209, (_bv_7209, _b_7210, _ctx)); /*0*/
  return kk_std_core_types__tuple2__unbox(_x8371, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift5645_run__experiments_fun8372__t {
  struct kk_function_s _base;
  kk_function_t _bv_7215;
};
static kk_box_t kk_climate_dash_experiments__mlift5645_run__experiments_fun8372(kk_function_t _fself, kk_box_t _b_7216, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5645_run__experiments_fun8372(kk_function_t _bv_7215, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5645_run__experiments_fun8372__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5645_run__experiments_fun8372__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5645_run__experiments_fun8372, kk_context());
  _self->_bv_7215 = _bv_7215;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift5645_run__experiments_fun8372(kk_function_t _fself, kk_box_t _b_7216, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5645_run__experiments_fun8372__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5645_run__experiments_fun8372__t*, _fself);
  kk_function_t _bv_7215 = _self->_bv_7215; /* (a : int) -> <effects-and-types/yield,effects-and-types/sample,effects-and-types/score,div,exn,std/num/random/random,console,ndet,effects-and-types/sample> (double, double) */
  kk_drop_match(_self, {kk_function_dup(_bv_7215);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x8373;
  kk_integer_t _x8374 = kk_integer_unbox(_b_7216); /*int*/
  _x8373 = kk_function_call(kk_std_core_types__tuple2_, (kk_function_t, kk_integer_t, kk_context_t*), _bv_7215, (_bv_7215, _x8374, _ctx)); /*(double, double)*/
  return kk_std_core_types__tuple2__box(_x8373, _ctx);
}
static kk_box_t kk_climate_dash_experiments__mlift5645_run__experiments_fun8365(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5645_run__experiments_fun8365__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5645_run__experiments_fun8365__t*, _fself);
  kk_function_t model_5857 = _self->model_5857; /* () -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random,console,ndet,effects-and-types/sample> (double, double) */
  kk_drop_match(_self, {kk_function_dup(model_5857);}, {}, _ctx)
  kk_function_t _x8366;
  kk_function_t _bv_7215;
  kk_function_t _bv_7209 = kk_handlers_advance(kk_climate_dash_experiments__new_mlift5645_run__experiments_fun8367(model_5857, _ctx), _ctx); /*(a : int) -> <effects-and-types/yield|1> 0*/;
  _bv_7215 = kk_climate_dash_experiments__new_mlift5645_run__experiments_fun8370(_bv_7209, _ctx); /*(a : int) -> <effects-and-types/yield,effects-and-types/sample,effects-and-types/score,div,exn,std/num/random/random,console,ndet,effects-and-types/sample> (double, double)*/
  _x8366 = kk_climate_dash_experiments__new_mlift5645_run__experiments_fun8372(_bv_7215, _ctx); /*(7213) -> <effects-and-types/yield,effects-and-types/sample,effects-and-types/score,div,exn,std/num/random/random,console,ndet,effects-and-types/sample> 7214*/
  return kk_function_box(_x8366);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift5645_run__experiments_fun8376__t {
  struct kk_function_s _base;
  kk_integer_t sz;
};
static kk_box_t kk_climate_dash_experiments__mlift5645_run__experiments_fun8376(kk_function_t _fself, kk_box_t _b_7222, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5645_run__experiments_fun8376(kk_integer_t sz, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5645_run__experiments_fun8376__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5645_run__experiments_fun8376__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5645_run__experiments_fun8376, kk_context());
  _self->sz = sz;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift5645_run__experiments_fun8376(kk_function_t _fself, kk_box_t _b_7222, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5645_run__experiments_fun8376__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5645_run__experiments_fun8376__t*, _fself);
  kk_integer_t sz = _self->sz; /* int */
  kk_drop_match(_self, {kk_integer_dup(sz);}, {}, _ctx)
  kk_std_core__list _x8377;
  kk_std_core__list _x8378 = kk_std_core__list_unbox(_b_7222, _ctx); /*effects-and-types/histogram<(a : int) -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random,console,ndet,effects-and-types/sample> (double, double)>*/
  _x8377 = kk_smc__mlift743_smc(true, sz, kk_integer_from_small(1), _x8378, _ctx); /*effects-and-types/histogram<24>*/
  return kk_std_core__list_box(_x8377, _ctx);
}
static kk_box_t kk_climate_dash_experiments__mlift5645_run__experiments_fun8363(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5645_run__experiments_fun8363__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5645_run__experiments_fun8363__t*, _fself);
  kk_function_t model_5857 = _self->model_5857; /* () -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random,console,ndet,effects-and-types/sample> (double, double) */
  kk_integer_t sz = _self->sz; /* int */
  kk_drop_match(_self, {kk_function_dup(model_5857);kk_integer_dup(sz);}, {}, _ctx)
  kk_std_core__list _x8364;
  kk_std_core__list x_775 = kk_sampling_populate(kk_integer_from_small(100), kk_climate_dash_experiments__new_mlift5645_run__experiments_fun8365(model_5857, _ctx), _ctx); /*effects-and-types/histogram<(a : int) -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random,console,ndet,effects-and-types/sample> (double, double)>*/;
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_775, _ctx);
    kk_box_t _x8375 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments__new_mlift5645_run__experiments_fun8376(sz, _ctx), _ctx); /*2*/
    _x8364 = kk_std_core__list_unbox(_x8375, _ctx); /*effects-and-types/histogram<(double, double)>*/
  }
  else {
    _x8364 = kk_smc__mlift743_smc(true, sz, kk_integer_from_small(1), x_775, _ctx); /*effects-and-types/histogram<(double, double)>*/
  }
  return kk_std_core__list_box(_x8364, _ctx);
}
static kk_box_t kk_climate_dash_experiments__mlift5645_run__experiments_fun8347(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5645_run__experiments_fun8347__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5645_run__experiments_fun8347__t*, _fself);
  kk_std_core__list data__vals = _self->data__vals; /* list<(double, bool)> */
  kk_integer_t sz = _self->sz; /* int */
  kk_drop_match(_self, {kk_std_core__list_dup(data__vals);kk_integer_dup(sz);}, {}, _ctx)
  kk_std_core__list _x8348;
  kk_function_t model_5857;
  kk_function_t _x01_5620;
  kk_function_t _bv_7192;
  kk_box_t _x8349 = kk_std_core_hnd__open_none1(kk_climate_dash_experiments__new_mlift5645_run__experiments_fun8350(_ctx), kk_std_core__list_box(data__vals, _ctx), _ctx); /*2*/
  _bv_7192 = kk_function_unbox(_x8349); /*() -> <.Box|.Box> 7191*/
  _x01_5620 = kk_climate_dash_experiments__new_mlift5645_run__experiments_fun8355(_bv_7192, _ctx); /*effects-and-types/model<(double, double),div>*/
  model_5857 = kk_climate_dash_experiments__new_mlift5645_run__experiments_fun8357(_x01_5620, _ctx); /*() -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random,console,ndet,effects-and-types/sample> (double, double)*/
  kk_box_t _x8362 = kk_handlers_random__sampler(kk_climate_dash_experiments__new_mlift5645_run__experiments_fun8363(model_5857, sz, _ctx), _ctx); /*0*/
  _x8348 = kk_std_core__list_unbox(_x8362, _ctx); /*effects-and-types/histogram<(double, double)>*/
  return kk_std_core__list_box(_x8348, _ctx);
}
static kk_box_t kk_climate_dash_experiments__mlift5645_run__experiments_fun8344(kk_function_t _fself, kk_box_t _b_7228, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core_types__tuple2_ _match_7474 = kk_std_core_types__tuple2__unbox(_b_7228, _ctx); /*(int, list<(double, bool)>)*/;
  kk_box_t _box_x7184 = _match_7474.fst;
  kk_box_t _box_x7185 = _match_7474.snd;
  kk_integer_t sz = kk_integer_unbox(_box_x7184);
  kk_std_core__list data__vals = kk_std_core__list_unbox(_box_x7185, NULL);
  kk_std_core__list_dup(data__vals);
  kk_integer_dup(sz);
  kk_std_core_types__tuple2__drop(_match_7474, _ctx);
  return kk_std_time_timer_print_elapsed(kk_climate_dash_experiments__new_mlift5645_run__experiments_fun8347(data__vals, sz, _ctx), kk_std_core_types__new_None(_ctx), _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift5645_run__experiments_fun8380__t {
  struct kk_function_s _base;
  kk_std_core__list data__50;
  kk_std_core__list data__points;
  kk_integer_t i1;
};
static kk_box_t kk_climate_dash_experiments__mlift5645_run__experiments_fun8380(kk_function_t _fself, kk_box_t _b_7238, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5645_run__experiments_fun8380(kk_std_core__list data__50, kk_std_core__list data__points, kk_integer_t i1, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5645_run__experiments_fun8380__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5645_run__experiments_fun8380__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5645_run__experiments_fun8380, kk_context());
  _self->data__50 = data__50;
  _self->data__points = data__points;
  _self->i1 = i1;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift5645_run__experiments_fun8380(kk_function_t _fself, kk_box_t _b_7238, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5645_run__experiments_fun8380__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5645_run__experiments_fun8380__t*, _fself);
  kk_std_core__list data__50 = _self->data__50; /* list<(double, bool)> */
  kk_std_core__list data__points = _self->data__points; /* list<(int, list<(double, bool)>)> */
  kk_integer_t i1 = _self->i1; /* int */
  kk_drop_match(_self, {kk_std_core__list_dup(data__50);kk_std_core__list_dup(data__points);kk_integer_dup(i1);}, {}, _ctx)
  kk_unit_t _x8381 = kk_Unit;
  kk_std_core__list _x8382 = kk_std_core__list_unbox(_b_7238, _ctx); /*list<effects-and-types/histogram<(double, double)>>*/
  kk_climate_dash_experiments__mlift5644_run__experiments(data__50, data__points, i1, _x8382, _ctx);
  return kk_unit_box(_x8381);
}
static kk_unit_t kk_climate_dash_experiments__mlift5645_run__experiments_fun8336(kk_function_t _fself, kk_integer_t i1, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5645_run__experiments_fun8336__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5645_run__experiments_fun8336__t*, _fself);
  kk_std_core__list data__50 = _self->data__50; /* list<(double, bool)> */
  kk_std_core__list data__points = _self->data__points; /* list<(int, list<(double, bool)>)> */
  kk_drop_match(_self, {kk_std_core__list_dup(data__50);kk_std_core__list_dup(data__points);}, {}, _ctx)
  kk_unit_t __ = kk_Unit;
  kk_string_t s_5850;
  kk_string_t _x8337;
  kk_define_string_literal(, _s8338, 7, "Round #")
  _x8337 = kk_string_dup(_s8338); /*string*/
  kk_string_t _x8339;
  kk_integer_t _x8340 = kk_integer_dup(i1); /*int*/
  _x8339 = kk_std_core_show(_x8340, _ctx); /*string*/
  s_5850 = kk_std_core__lp__plus__plus__1_rp_(_x8337, _x8339, _ctx); /*string*/
  kk_std_core_printsln(s_5850, _ctx);
  kk_unit_t __0 = kk_Unit;
  kk_string_t _x8341;
  kk_define_string_literal(, _s8342, 38, "Running SMC with increasing data size:")
  _x8341 = kk_string_dup(_s8342); /*string*/
  kk_std_core_printsln(_x8341, _ctx);
  kk_std_core__list x_5852;
  kk_std_core__list _x8343 = kk_std_core__list_dup(data__points); /*list<(int, list<(double, bool)>)>*/
  x_5852 = kk_std_core_map_5(_x8343, kk_climate_dash_experiments__new_mlift5645_run__experiments_fun8344(_ctx), _ctx); /*list<effects-and-types/histogram<(double, double)>>*/
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_5852, _ctx);
    kk_box_t _x8379 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments__new_mlift5645_run__experiments_fun8380(data__50, data__points, i1, _ctx), _ctx); /*2*/
    return kk_unit_unbox(_x8379);
  }
  return kk_climate_dash_experiments__mlift5644_run__experiments(data__50, data__points, i1, x_5852, _ctx);
}

kk_unit_t kk_climate_dash_experiments__mlift5645_run__experiments(kk_std_core__list data__points, kk_std_core_types__optional number__of__repeats, kk_std_core__list data__50, kk_context_t* _ctx) { /* (data_points : list<(int, list<(double, bool)>)>, number_of_repeats : optional<int>, data_50 : list<(double, bool)>) -> <std/num/random/random,console,div,exn,ndet,effects-and-types/sample> () */ 
  kk_integer_t _x8383;
  if (kk_std_core_types__is_Optional(number__of__repeats)) {
    kk_box_t _box_x7239 = number__of__repeats._cons.Optional.value;
    kk_integer_t _number__of__repeats_3556 = kk_integer_unbox(_box_x7239);
    kk_integer_dup(_number__of__repeats_3556);
    kk_std_core_types__optional_drop(number__of__repeats, _ctx);
    _x8383 = _number__of__repeats_3556; /*int*/
    goto _match8384;
  }
  _x8383 = kk_integer_from_small(4); /*int*/
  _match8384: ;
  kk_std_core__lift21056_for(kk_climate_dash_experiments__new_mlift5645_run__experiments_fun8336(data__50, data__points, _ctx), _x8383, kk_integer_from_small(1), _ctx); return kk_Unit;
}
 
// monadic lift

kk_std_core_types__tuple2_ kk_climate_dash_experiments__mlift5646_run__experiments(kk_integer_t i0, kk_std_core__list _y_29, kk_context_t* _ctx) { /* (i0 : int, list<(double, bool)>) -> <std/num/random/random,console,div,exn,ndet,effects-and-types/sample> (int, list<(double, bool)>) */ 
  return kk_std_core_types__new_dash__lp__comma__rp_(kk_integer_box(i0), kk_std_core__list_box(_y_29, _ctx), _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_climate_dash_experiments__mlift5647_run__experiments_fun8387__t {
  struct kk_function_s _base;
  size_t i_5861;
};
static kk_box_t kk_climate_dash_experiments__mlift5647_run__experiments_fun8387(kk_function_t _fself, kk_function_t _b_7251, kk_box_t _b_7252, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5647_run__experiments_fun8387(size_t i_5861, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5647_run__experiments_fun8387__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5647_run__experiments_fun8387__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5647_run__experiments_fun8387, kk_context());
  _self->i_5861 = i_5861;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift5647_run__experiments_fun8387(kk_function_t _fself, kk_function_t _b_7251, kk_box_t _b_7252, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5647_run__experiments_fun8387__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5647_run__experiments_fun8387__t*, _fself);
  size_t i_5861 = _self->i_5861; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_5861, _b_7251, _b_7252, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift5647_run__experiments_fun8389__t {
  struct kk_function_s _base;
  kk_std_core__list data__points;
  kk_std_core_types__optional number__of__repeats;
};
static kk_box_t kk_climate_dash_experiments__mlift5647_run__experiments_fun8389(kk_function_t _fself, kk_box_t _b_7262, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5647_run__experiments_fun8389(kk_std_core__list data__points, kk_std_core_types__optional number__of__repeats, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5647_run__experiments_fun8389__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5647_run__experiments_fun8389__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5647_run__experiments_fun8389, kk_context());
  _self->data__points = data__points;
  _self->number__of__repeats = number__of__repeats;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift5647_run__experiments_fun8389(kk_function_t _fself, kk_box_t _b_7262, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5647_run__experiments_fun8389__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5647_run__experiments_fun8389__t*, _fself);
  kk_std_core__list data__points = _self->data__points; /* list<(int, list<(double, bool)>)> */
  kk_std_core_types__optional number__of__repeats = _self->number__of__repeats; /* optional<int> */
  kk_drop_match(_self, {kk_std_core__list_dup(data__points);kk_std_core_types__optional_dup(number__of__repeats);}, {}, _ctx)
  kk_unit_t _x8390 = kk_Unit;
  kk_std_core__list _x8391 = kk_std_core__list_unbox(_b_7262, _ctx); /*list<(double, bool)>*/
  kk_climate_dash_experiments__mlift5645_run__experiments(data__points, number__of__repeats, _x8391, _ctx);
  return kk_unit_box(_x8390);
}

kk_unit_t kk_climate_dash_experiments__mlift5647_run__experiments(kk_std_core_types__optional number__of__repeats, kk_std_core__list data__points, kk_context_t* _ctx) { /* (number_of_repeats : optional<int>, data_points : list<(int, list<(double, bool)>)>) -> <std/num/random/random,console,div,exn,ndet,effects-and-types/sample> () */ 
  kk_std_core__list x_5859;
  size_t i_5861 = ((size_t)1); /*std/core/hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_5861,kk_context()); /*std/core/hnd/evv<<std/num/random/random,console,div,exn,ndet,effects-and-types/sample>>*/;
  kk_std_core__list y = kk_model_dash_resources_generate__synthetic__lr__data(kk_integer_from_small(50), _ctx); /*list<(double, bool)>*/;
  kk_unit_t __w_l700_c9 = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(y, _ctx);
    kk_box_t _x8386 = kk_std_core_hnd_yield_cont(kk_climate_dash_experiments__new_mlift5647_run__experiments_fun8387(i_5861, _ctx), _ctx); /*3*/
    x_5859 = kk_std_core__list_unbox(_x8386, _ctx); /*list<(double, bool)>*/
  }
  else {
    x_5859 = y; /*list<(double, bool)>*/
  }
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_5859, _ctx);
    kk_box_t _x8388 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments__new_mlift5647_run__experiments_fun8389(data__points, number__of__repeats, _ctx), _ctx); /*2*/
    kk_unit_unbox(_x8388); return kk_Unit;
  }
  kk_climate_dash_experiments__mlift5645_run__experiments(data__points, number__of__repeats, x_5859, _ctx); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_climate_dash_experiments__mlift5648_run__experiments_fun8392__t {
  struct kk_function_s _base;
};
static kk_box_t kk_climate_dash_experiments__mlift5648_run__experiments_fun8392(kk_function_t _fself, kk_box_t _b_7284, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5648_run__experiments_fun8392(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_climate_dash_experiments__mlift5648_run__experiments_fun8392, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift5648_run__experiments_fun8397__t {
  struct kk_function_s _base;
  size_t i_5868;
};
static kk_box_t kk_climate_dash_experiments__mlift5648_run__experiments_fun8397(kk_function_t _fself, kk_function_t _b_7270, kk_box_t _b_7271, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5648_run__experiments_fun8397(size_t i_5868, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5648_run__experiments_fun8397__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5648_run__experiments_fun8397__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5648_run__experiments_fun8397, kk_context());
  _self->i_5868 = i_5868;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift5648_run__experiments_fun8397(kk_function_t _fself, kk_function_t _b_7270, kk_box_t _b_7271, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5648_run__experiments_fun8397__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5648_run__experiments_fun8397__t*, _fself);
  size_t i_5868 = _self->i_5868; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_5868, _b_7270, _b_7271, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift5648_run__experiments_fun8399__t {
  struct kk_function_s _base;
  kk_box_t _b_7284;
};
static kk_box_t kk_climate_dash_experiments__mlift5648_run__experiments_fun8399(kk_function_t _fself, kk_box_t _b_7281, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5648_run__experiments_fun8399(kk_box_t _b_7284, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5648_run__experiments_fun8399__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5648_run__experiments_fun8399__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5648_run__experiments_fun8399, kk_context());
  _self->_b_7284 = _b_7284;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift5648_run__experiments_fun8399(kk_function_t _fself, kk_box_t _b_7281, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5648_run__experiments_fun8399__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5648_run__experiments_fun8399__t*, _fself);
  kk_box_t _b_7284 = _self->_b_7284; /* 1 */
  kk_drop_match(_self, {kk_box_dup(_b_7284);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x8400;
  kk_integer_t _x8401 = kk_integer_unbox(_b_7284); /*int*/
  kk_std_core__list _x8402 = kk_std_core__list_unbox(_b_7281, _ctx); /*list<(double, bool)>*/
  _x8400 = kk_climate_dash_experiments__mlift5646_run__experiments(_x8401, _x8402, _ctx); /*(int, list<(double, bool)>)*/
  return kk_std_core_types__tuple2__box(_x8400, _ctx);
}
static kk_box_t kk_climate_dash_experiments__mlift5648_run__experiments_fun8392(kk_function_t _fself, kk_box_t _b_7284, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core_types__tuple2_ _x8393;
  kk_std_core__list x0_5866;
  size_t i_5868 = ((size_t)1); /*std/core/hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_5868,kk_context()); /*std/core/hnd/evv<<std/num/random/random,console,div,exn,ndet,effects-and-types/sample>>*/;
  kk_std_core__list y;
  kk_integer_t _x8394;
  kk_box_t _x8395 = kk_box_dup(_b_7284); /*1*/
  _x8394 = kk_integer_unbox(_x8395); /*int*/
  y = kk_model_dash_resources_generate__synthetic__lr__data(_x8394, _ctx); /*list<(double, bool)>*/
  kk_unit_t __w_l700_c9 = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(y, _ctx);
    kk_box_t _x8396 = kk_std_core_hnd_yield_cont(kk_climate_dash_experiments__new_mlift5648_run__experiments_fun8397(i_5868, _ctx), _ctx); /*3*/
    x0_5866 = kk_std_core__list_unbox(_x8396, _ctx); /*list<(double, bool)>*/
  }
  else {
    x0_5866 = y; /*list<(double, bool)>*/
  }
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x0_5866, _ctx);
    kk_box_t _x8398 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments__new_mlift5648_run__experiments_fun8399(_b_7284, _ctx), _ctx); /*2*/
    _x8393 = kk_std_core_types__tuple2__unbox(_x8398, _ctx); /*(int, list<(double, bool)>)*/
  }
  else {
    kk_integer_t _x8403 = kk_integer_unbox(_b_7284); /*int*/
    _x8393 = kk_climate_dash_experiments__mlift5646_run__experiments(_x8403, x0_5866, _ctx); /*(int, list<(double, bool)>)*/
  }
  return kk_std_core_types__tuple2__box(_x8393, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift5648_run__experiments_fun8405__t {
  struct kk_function_s _base;
  kk_std_core_types__optional number__of__repeats;
};
static kk_box_t kk_climate_dash_experiments__mlift5648_run__experiments_fun8405(kk_function_t _fself, kk_box_t _b_7291, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5648_run__experiments_fun8405(kk_std_core_types__optional number__of__repeats, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5648_run__experiments_fun8405__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift5648_run__experiments_fun8405__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift5648_run__experiments_fun8405, kk_context());
  _self->number__of__repeats = number__of__repeats;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift5648_run__experiments_fun8405(kk_function_t _fself, kk_box_t _b_7291, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift5648_run__experiments_fun8405__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift5648_run__experiments_fun8405__t*, _fself);
  kk_std_core_types__optional number__of__repeats = _self->number__of__repeats; /* optional<int> */
  kk_drop_match(_self, {kk_std_core_types__optional_dup(number__of__repeats);}, {}, _ctx)
  kk_unit_t _x8406 = kk_Unit;
  kk_std_core__list _x8407 = kk_std_core__list_unbox(_b_7291, _ctx); /*list<(int, list<(double, bool)>)>*/
  kk_climate_dash_experiments__mlift5647_run__experiments(number__of__repeats, _x8407, _ctx);
  return kk_unit_box(_x8406);
}

kk_unit_t kk_climate_dash_experiments__mlift5648_run__experiments(kk_std_core_types__optional number__of__repeats, kk_std_core__list _y_28, kk_context_t* _ctx) { /* (number_of_repeats : optional<int>, list<int>) -> <std/num/random/random,console,div,exn,ndet,effects-and-types/sample> () */ 
  kk_std_core__list x_5864 = kk_std_core_map_5(_y_28, kk_climate_dash_experiments__new_mlift5648_run__experiments_fun8392(_ctx), _ctx); /*list<(int, list<(double, bool)>)>*/;
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_5864, _ctx);
    kk_box_t _x8404 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments__new_mlift5648_run__experiments_fun8405(number__of__repeats, _ctx), _ctx); /*2*/
    kk_unit_unbox(_x8404); return kk_Unit;
  }
  kk_climate_dash_experiments__mlift5647_run__experiments(number__of__repeats, x_5864, _ctx); return kk_Unit;
}
 
// Original code has 10 as the max_number_of_data_points, but this reaches max_memory (heap size of 4 GB on my computer) nad cca 10GB of core data


// lift anonymous function
struct kk_climate_dash_experiments_run__experiments_fun8411__t {
  struct kk_function_s _base;
};
static kk_box_t kk_climate_dash_experiments_run__experiments_fun8411(kk_function_t _fself, kk_box_t _b_7297, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__experiments_fun8411(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_climate_dash_experiments_run__experiments_fun8411, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_climate_dash_experiments_run__experiments_fun8411(kk_function_t _fself, kk_box_t _b_7297, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_integer_t _x8412;
  kk_integer_t _x8413 = kk_integer_unbox(_b_7297); /*int*/
  _x8412 = kk_integer_mul(_x8413,(kk_integer_from_small(100)),kk_context()); /*int*/
  return kk_integer_box(_x8412);
}


// lift anonymous function
struct kk_climate_dash_experiments_run__experiments_fun8415__t {
  struct kk_function_s _base;
  kk_std_core_types__optional number__of__repeats;
};
static kk_box_t kk_climate_dash_experiments_run__experiments_fun8415(kk_function_t _fself, kk_box_t _b_7302, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__experiments_fun8415(kk_std_core_types__optional number__of__repeats, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun8415__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__experiments_fun8415__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__experiments_fun8415, kk_context());
  _self->number__of__repeats = number__of__repeats;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments_run__experiments_fun8415(kk_function_t _fself, kk_box_t _b_7302, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun8415__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__experiments_fun8415__t*, _fself);
  kk_std_core_types__optional number__of__repeats = _self->number__of__repeats; /* optional<int> */
  kk_drop_match(_self, {kk_std_core_types__optional_dup(number__of__repeats);}, {}, _ctx)
  kk_unit_t _x8416 = kk_Unit;
  kk_std_core__list _x8417 = kk_std_core__list_unbox(_b_7302, _ctx); /*list<int>*/
  kk_climate_dash_experiments__mlift5648_run__experiments(number__of__repeats, _x8417, _ctx);
  return kk_unit_box(_x8416);
}


// lift anonymous function
struct kk_climate_dash_experiments_run__experiments_fun8418__t {
  struct kk_function_s _base;
};
static kk_box_t kk_climate_dash_experiments_run__experiments_fun8418(kk_function_t _fself, kk_box_t _b_7322, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__experiments_fun8418(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_climate_dash_experiments_run__experiments_fun8418, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_climate_dash_experiments_run__experiments_fun8423__t {
  struct kk_function_s _base;
  size_t i1_5882;
};
static kk_box_t kk_climate_dash_experiments_run__experiments_fun8423(kk_function_t _fself, kk_function_t _b_7308, kk_box_t _b_7309, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__experiments_fun8423(size_t i1_5882, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun8423__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__experiments_fun8423__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__experiments_fun8423, kk_context());
  _self->i1_5882 = i1_5882;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments_run__experiments_fun8423(kk_function_t _fself, kk_function_t _b_7308, kk_box_t _b_7309, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun8423__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__experiments_fun8423__t*, _fself);
  size_t i1_5882 = _self->i1_5882; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i1_5882, _b_7308, _b_7309, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments_run__experiments_fun8425__t {
  struct kk_function_s _base;
  kk_box_t _b_7322;
};
static kk_box_t kk_climate_dash_experiments_run__experiments_fun8425(kk_function_t _fself, kk_box_t _b_7319, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__experiments_fun8425(kk_box_t _b_7322, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun8425__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__experiments_fun8425__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__experiments_fun8425, kk_context());
  _self->_b_7322 = _b_7322;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments_run__experiments_fun8425(kk_function_t _fself, kk_box_t _b_7319, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun8425__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__experiments_fun8425__t*, _fself);
  kk_box_t _b_7322 = _self->_b_7322; /* 1 */
  kk_drop_match(_self, {kk_box_dup(_b_7322);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x8426;
  kk_integer_t _x8427 = kk_integer_unbox(_b_7322); /*int*/
  kk_std_core__list _x8428 = kk_std_core__list_unbox(_b_7319, _ctx); /*list<(double, bool)>*/
  _x8426 = kk_climate_dash_experiments__mlift5646_run__experiments(_x8427, _x8428, _ctx); /*(int, list<(double, bool)>)*/
  return kk_std_core_types__tuple2__box(_x8426, _ctx);
}
static kk_box_t kk_climate_dash_experiments_run__experiments_fun8418(kk_function_t _fself, kk_box_t _b_7322, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core_types__tuple2_ _x8419;
  kk_std_core__list x1_5880;
  size_t i1_5882 = ((size_t)1); /*std/core/hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i1_5882,kk_context()); /*std/core/hnd/evv<<std/num/random/random,console,div,exn,ndet,effects-and-types/sample>>*/;
  kk_std_core__list y;
  kk_integer_t _x8420;
  kk_box_t _x8421 = kk_box_dup(_b_7322); /*1*/
  _x8420 = kk_integer_unbox(_x8421); /*int*/
  y = kk_model_dash_resources_generate__synthetic__lr__data(_x8420, _ctx); /*list<(double, bool)>*/
  kk_unit_t __w_l700_c9 = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(y, _ctx);
    kk_box_t _x8422 = kk_std_core_hnd_yield_cont(kk_climate_dash_experiments_new_run__experiments_fun8423(i1_5882, _ctx), _ctx); /*3*/
    x1_5880 = kk_std_core__list_unbox(_x8422, _ctx); /*list<(double, bool)>*/
  }
  else {
    x1_5880 = y; /*list<(double, bool)>*/
  }
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x1_5880, _ctx);
    kk_box_t _x8424 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments_new_run__experiments_fun8425(_b_7322, _ctx), _ctx); /*2*/
    _x8419 = kk_std_core_types__tuple2__unbox(_x8424, _ctx); /*(int, list<(double, bool)>)*/
  }
  else {
    kk_integer_t _x8429 = kk_integer_unbox(_b_7322); /*int*/
    _x8419 = kk_climate_dash_experiments__mlift5646_run__experiments(_x8429, x1_5880, _ctx); /*(int, list<(double, bool)>)*/
  }
  return kk_std_core_types__tuple2__box(_x8419, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments_run__experiments_fun8431__t {
  struct kk_function_s _base;
  kk_std_core_types__optional number__of__repeats;
};
static kk_box_t kk_climate_dash_experiments_run__experiments_fun8431(kk_function_t _fself, kk_box_t _b_7329, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__experiments_fun8431(kk_std_core_types__optional number__of__repeats, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun8431__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__experiments_fun8431__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__experiments_fun8431, kk_context());
  _self->number__of__repeats = number__of__repeats;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments_run__experiments_fun8431(kk_function_t _fself, kk_box_t _b_7329, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun8431__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__experiments_fun8431__t*, _fself);
  kk_std_core_types__optional number__of__repeats = _self->number__of__repeats; /* optional<int> */
  kk_drop_match(_self, {kk_std_core_types__optional_dup(number__of__repeats);}, {}, _ctx)
  kk_unit_t _x8432 = kk_Unit;
  kk_std_core__list _x8433 = kk_std_core__list_unbox(_b_7329, _ctx); /*list<(int, list<(double, bool)>)>*/
  kk_climate_dash_experiments__mlift5647_run__experiments(number__of__repeats, _x8433, _ctx);
  return kk_unit_box(_x8432);
}


// lift anonymous function
struct kk_climate_dash_experiments_run__experiments_fun8435__t {
  struct kk_function_s _base;
  size_t i2_5889;
};
static kk_box_t kk_climate_dash_experiments_run__experiments_fun8435(kk_function_t _fself, kk_function_t _b_7335, kk_box_t _b_7336, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__experiments_fun8435(size_t i2_5889, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun8435__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__experiments_fun8435__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__experiments_fun8435, kk_context());
  _self->i2_5889 = i2_5889;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments_run__experiments_fun8435(kk_function_t _fself, kk_function_t _b_7335, kk_box_t _b_7336, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun8435__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__experiments_fun8435__t*, _fself);
  size_t i2_5889 = _self->i2_5889; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i2_5889, _b_7335, _b_7336, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments_run__experiments_fun8437__t {
  struct kk_function_s _base;
  kk_std_core_types__optional number__of__repeats;
  kk_std_core__list x0_5877;
};
static kk_box_t kk_climate_dash_experiments_run__experiments_fun8437(kk_function_t _fself, kk_box_t _b_7346, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__experiments_fun8437(kk_std_core_types__optional number__of__repeats, kk_std_core__list x0_5877, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun8437__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__experiments_fun8437__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__experiments_fun8437, kk_context());
  _self->number__of__repeats = number__of__repeats;
  _self->x0_5877 = x0_5877;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments_run__experiments_fun8437(kk_function_t _fself, kk_box_t _b_7346, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun8437__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__experiments_fun8437__t*, _fself);
  kk_std_core_types__optional number__of__repeats = _self->number__of__repeats; /* optional<int> */
  kk_std_core__list x0_5877 = _self->x0_5877; /* list<(int, list<(double, bool)>)> */
  kk_drop_match(_self, {kk_std_core_types__optional_dup(number__of__repeats);kk_std_core__list_dup(x0_5877);}, {}, _ctx)
  kk_unit_t _x8438 = kk_Unit;
  kk_std_core__list _x8439 = kk_std_core__list_unbox(_b_7346, _ctx); /*list<(double, bool)>*/
  kk_climate_dash_experiments__mlift5645_run__experiments(x0_5877, number__of__repeats, _x8439, _ctx);
  return kk_unit_box(_x8438);
}


// lift anonymous function
struct kk_climate_dash_experiments_run__experiments_fun8440__t {
  struct kk_function_s _base;
  kk_std_core__list x0_5877;
  kk_std_core__list x3_5886;
};
static kk_unit_t kk_climate_dash_experiments_run__experiments_fun8440(kk_function_t _fself, kk_integer_t i10, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__experiments_fun8440(kk_std_core__list x0_5877, kk_std_core__list x3_5886, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun8440__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__experiments_fun8440__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__experiments_fun8440, kk_context());
  _self->x0_5877 = x0_5877;
  _self->x3_5886 = x3_5886;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments_run__experiments_fun8448__t {
  struct kk_function_s _base;
};
static kk_box_t kk_climate_dash_experiments_run__experiments_fun8448(kk_function_t _fself, kk_box_t _b_7391, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__experiments_fun8448(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_climate_dash_experiments_run__experiments_fun8448, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_climate_dash_experiments_run__experiments_fun8451__t {
  struct kk_function_s _base;
  kk_std_core__list data__vals;
  kk_integer_t sz;
};
static kk_box_t kk_climate_dash_experiments_run__experiments_fun8451(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__experiments_fun8451(kk_std_core__list data__vals, kk_integer_t sz, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun8451__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__experiments_fun8451__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__experiments_fun8451, kk_context());
  _self->data__vals = data__vals;
  _self->sz = sz;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments_run__experiments_fun8454__t {
  struct kk_function_s _base;
};
static kk_box_t kk_climate_dash_experiments_run__experiments_fun8454(kk_function_t _fself, kk_box_t _b_7351, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__experiments_fun8454(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_climate_dash_experiments_run__experiments_fun8454, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_climate_dash_experiments_run__experiments_fun8457__t {
  struct kk_function_s _base;
  kk_function_t _bv_7353;
};
static kk_box_t kk_climate_dash_experiments_run__experiments_fun8457(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__experiments_fun8457(kk_function_t _bv_7353, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun8457__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__experiments_fun8457__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__experiments_fun8457, kk_context());
  _self->_bv_7353 = _bv_7353;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments_run__experiments_fun8457(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun8457__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__experiments_fun8457__t*, _fself);
  kk_function_t _bv_7353 = _self->_bv_7353; /* effects-and-types/model<(double, double),div> */
  kk_drop_match(_self, {kk_function_dup(_bv_7353);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x8458 = kk_function_call(kk_std_core_types__tuple2_, (kk_function_t, kk_context_t*), _bv_7353, (_bv_7353, _ctx)); /*(double, double)*/
  return kk_std_core_types__tuple2__box(_x8458, _ctx);
}
static kk_box_t kk_climate_dash_experiments_run__experiments_fun8454(kk_function_t _fself, kk_box_t _b_7351, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_function_t _x8455;
  kk_function_t _bv_7353;
  kk_std_core__list _x8456 = kk_std_core__list_unbox(_b_7351, _ctx); /*list<(double, bool)>*/
  _bv_7353 = kk_model_dash_resources_logistic__regression(_x8456, _ctx); /*effects-and-types/model<(double, double),div>*/
  _x8455 = kk_climate_dash_experiments_new_run__experiments_fun8457(_bv_7353, _ctx); /*() -> <effects-and-types/sample,effects-and-types/score,div> 7352*/
  return kk_function_box(_x8455);
}


// lift anonymous function
struct kk_climate_dash_experiments_run__experiments_fun8459__t {
  struct kk_function_s _base;
  kk_function_t _bv_7355;
};
static kk_std_core_types__tuple2_ kk_climate_dash_experiments_run__experiments_fun8459(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__experiments_fun8459(kk_function_t _bv_7355, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun8459__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__experiments_fun8459__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__experiments_fun8459, kk_context());
  _self->_bv_7355 = _bv_7355;
  return &_self->_base;
}

static kk_std_core_types__tuple2_ kk_climate_dash_experiments_run__experiments_fun8459(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun8459__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__experiments_fun8459__t*, _fself);
  kk_function_t _bv_7355 = _self->_bv_7355; /* () -> <.Box|.Box> 7354 */
  kk_drop_match(_self, {kk_function_dup(_bv_7355);}, {}, _ctx)
  kk_box_t _x8460 = kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), _bv_7355, (_bv_7355, _ctx)); /*7354*/
  return kk_std_core_types__tuple2__unbox(_x8460, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments_run__experiments_fun8461__t {
  struct kk_function_s _base;
  kk_function_t _x01_5620;
};
static kk_std_core_types__tuple2_ kk_climate_dash_experiments_run__experiments_fun8461(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__experiments_fun8461(kk_function_t _x01_5620, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun8461__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__experiments_fun8461__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__experiments_fun8461, kk_context());
  _self->_x01_5620 = _x01_5620;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments_run__experiments_fun8464__t {
  struct kk_function_s _base;
  kk_function_t _x01_5620;
};
static kk_box_t kk_climate_dash_experiments_run__experiments_fun8464(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__experiments_fun8464(kk_function_t _x01_5620, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun8464__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__experiments_fun8464__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__experiments_fun8464, kk_context());
  _self->_x01_5620 = _x01_5620;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments_run__experiments_fun8464(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun8464__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__experiments_fun8464__t*, _fself);
  kk_function_t _x01_5620 = _self->_x01_5620; /* effects-and-types/model<(double, double),div> */
  kk_drop_match(_self, {kk_function_dup(_x01_5620);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x8465 = kk_function_call(kk_std_core_types__tuple2_, (kk_function_t, kk_context_t*), _x01_5620, (_x01_5620, _ctx)); /*(double, double)*/
  return kk_std_core_types__tuple2__box(_x8465, _ctx);
}
static kk_std_core_types__tuple2_ kk_climate_dash_experiments_run__experiments_fun8461(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun8461__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__experiments_fun8461__t*, _fself);
  kk_function_t _x01_5620 = _self->_x01_5620; /* effects-and-types/model<(double, double),div> */
  kk_drop_match(_self, {kk_function_dup(_x01_5620);}, {}, _ctx)
  kk_vector_t _b_7364_7362;
  kk_std_core__list _x8462;
  size_t _b_7366_7360 = ((size_t)2); /*std/core/hnd/ev-index*/;
  kk_std_core__list _b_7367_7361;
  size_t _b_7368_7358 = ((size_t)4); /*std/core/hnd/ev-index*/;
  _b_7367_7361 = kk_std_core__new_Cons(kk_reuse_null, kk_size_box(_b_7368_7358, _ctx), kk_std_core__new_Nil(_ctx), _ctx); /*list<std/core/hnd/ev-index>*/
  _x8462 = kk_std_core__new_Cons(kk_reuse_null, kk_size_box(_b_7366_7360, _ctx), _b_7367_7361, _ctx); /*list<0>*/
  _b_7364_7362 = kk_std_core_unvlist(_x8462, _ctx); /*vector<std/core/hnd/ev-index>*/
  kk_box_t _x8463 = kk_std_core_hnd__open0(_b_7364_7362, kk_climate_dash_experiments_new_run__experiments_fun8464(_x01_5620, _ctx), _ctx); /*1*/
  return kk_std_core_types__tuple2__unbox(_x8463, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments_run__experiments_fun8467__t {
  struct kk_function_s _base;
  kk_function_t model_5903;
  kk_integer_t sz;
};
static kk_box_t kk_climate_dash_experiments_run__experiments_fun8467(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__experiments_fun8467(kk_function_t model_5903, kk_integer_t sz, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun8467__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__experiments_fun8467__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__experiments_fun8467, kk_context());
  _self->model_5903 = model_5903;
  _self->sz = sz;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments_run__experiments_fun8469__t {
  struct kk_function_s _base;
  kk_function_t model_5903;
};
static kk_box_t kk_climate_dash_experiments_run__experiments_fun8469(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__experiments_fun8469(kk_function_t model_5903, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun8469__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__experiments_fun8469__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__experiments_fun8469, kk_context());
  _self->model_5903 = model_5903;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments_run__experiments_fun8471__t {
  struct kk_function_s _base;
  kk_function_t model_5903;
};
static kk_box_t kk_climate_dash_experiments_run__experiments_fun8471(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__experiments_fun8471(kk_function_t model_5903, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun8471__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__experiments_fun8471__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__experiments_fun8471, kk_context());
  _self->model_5903 = model_5903;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments_run__experiments_fun8472__t {
  struct kk_function_s _base;
  kk_function_t model_5903;
};
static kk_box_t kk_climate_dash_experiments_run__experiments_fun8472(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__experiments_fun8472(kk_function_t model_5903, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun8472__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__experiments_fun8472__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__experiments_fun8472, kk_context());
  _self->model_5903 = model_5903;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments_run__experiments_fun8472(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun8472__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__experiments_fun8472__t*, _fself);
  kk_function_t model_5903 = _self->model_5903; /* () -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random,console,ndet,effects-and-types/sample> (double, double) */
  kk_drop_match(_self, {kk_function_dup(model_5903);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x8473 = kk_function_call(kk_std_core_types__tuple2_, (kk_function_t, kk_context_t*), model_5903, (model_5903, _ctx)); /*(double, double)*/
  return kk_std_core_types__tuple2__box(_x8473, _ctx);
}
static kk_box_t kk_climate_dash_experiments_run__experiments_fun8471(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun8471__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__experiments_fun8471__t*, _fself);
  kk_function_t model_5903 = _self->model_5903; /* () -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random,console,ndet,effects-and-types/sample> (double, double) */
  kk_drop_match(_self, {kk_function_dup(model_5903);}, {}, _ctx)
  return kk_handlers_yield__on__score(kk_climate_dash_experiments_new_run__experiments_fun8472(model_5903, _ctx), _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments_run__experiments_fun8474__t {
  struct kk_function_s _base;
  kk_function_t _bv_7372;
};
static kk_std_core_types__tuple2_ kk_climate_dash_experiments_run__experiments_fun8474(kk_function_t _fself, kk_integer_t _b_7373, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__experiments_fun8474(kk_function_t _bv_7372, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun8474__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__experiments_fun8474__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__experiments_fun8474, kk_context());
  _self->_bv_7372 = _bv_7372;
  return &_self->_base;
}

static kk_std_core_types__tuple2_ kk_climate_dash_experiments_run__experiments_fun8474(kk_function_t _fself, kk_integer_t _b_7373, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun8474__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__experiments_fun8474__t*, _fself);
  kk_function_t _bv_7372 = _self->_bv_7372; /* (a : int) -> <effects-and-types/yield|1> 0 */
  kk_drop_match(_self, {kk_function_dup(_bv_7372);}, {}, _ctx)
  kk_box_t _x8475 = kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_context_t*), _bv_7372, (_bv_7372, _b_7373, _ctx)); /*0*/
  return kk_std_core_types__tuple2__unbox(_x8475, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments_run__experiments_fun8476__t {
  struct kk_function_s _base;
  kk_function_t _bv_7378;
};
static kk_box_t kk_climate_dash_experiments_run__experiments_fun8476(kk_function_t _fself, kk_box_t _b_7379, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__experiments_fun8476(kk_function_t _bv_7378, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun8476__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__experiments_fun8476__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__experiments_fun8476, kk_context());
  _self->_bv_7378 = _bv_7378;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments_run__experiments_fun8476(kk_function_t _fself, kk_box_t _b_7379, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun8476__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__experiments_fun8476__t*, _fself);
  kk_function_t _bv_7378 = _self->_bv_7378; /* (a : int) -> <effects-and-types/yield,effects-and-types/sample,effects-and-types/score,div,exn,std/num/random/random,console,ndet,effects-and-types/sample> (double, double) */
  kk_drop_match(_self, {kk_function_dup(_bv_7378);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x8477;
  kk_integer_t _x8478 = kk_integer_unbox(_b_7379); /*int*/
  _x8477 = kk_function_call(kk_std_core_types__tuple2_, (kk_function_t, kk_integer_t, kk_context_t*), _bv_7378, (_bv_7378, _x8478, _ctx)); /*(double, double)*/
  return kk_std_core_types__tuple2__box(_x8477, _ctx);
}
static kk_box_t kk_climate_dash_experiments_run__experiments_fun8469(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun8469__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__experiments_fun8469__t*, _fself);
  kk_function_t model_5903 = _self->model_5903; /* () -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random,console,ndet,effects-and-types/sample> (double, double) */
  kk_drop_match(_self, {kk_function_dup(model_5903);}, {}, _ctx)
  kk_function_t _x8470;
  kk_function_t _bv_7378;
  kk_function_t _bv_7372 = kk_handlers_advance(kk_climate_dash_experiments_new_run__experiments_fun8471(model_5903, _ctx), _ctx); /*(a : int) -> <effects-and-types/yield|1> 0*/;
  _bv_7378 = kk_climate_dash_experiments_new_run__experiments_fun8474(_bv_7372, _ctx); /*(a : int) -> <effects-and-types/yield,effects-and-types/sample,effects-and-types/score,div,exn,std/num/random/random,console,ndet,effects-and-types/sample> (double, double)*/
  _x8470 = kk_climate_dash_experiments_new_run__experiments_fun8476(_bv_7378, _ctx); /*(7376) -> <effects-and-types/yield,effects-and-types/sample,effects-and-types/score,div,exn,std/num/random/random,console,ndet,effects-and-types/sample> 7377*/
  return kk_function_box(_x8470);
}


// lift anonymous function
struct kk_climate_dash_experiments_run__experiments_fun8480__t {
  struct kk_function_s _base;
  kk_integer_t sz;
};
static kk_box_t kk_climate_dash_experiments_run__experiments_fun8480(kk_function_t _fself, kk_box_t _b_7385, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__experiments_fun8480(kk_integer_t sz, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun8480__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__experiments_fun8480__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__experiments_fun8480, kk_context());
  _self->sz = sz;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments_run__experiments_fun8480(kk_function_t _fself, kk_box_t _b_7385, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun8480__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__experiments_fun8480__t*, _fself);
  kk_integer_t sz = _self->sz; /* int */
  kk_drop_match(_self, {kk_integer_dup(sz);}, {}, _ctx)
  kk_std_core__list _x8481;
  kk_std_core__list _x8482 = kk_std_core__list_unbox(_b_7385, _ctx); /*effects-and-types/histogram<(a : int) -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random,console,ndet,effects-and-types/sample> (double, double)>*/
  _x8481 = kk_smc__mlift743_smc(true, sz, kk_integer_from_small(1), _x8482, _ctx); /*effects-and-types/histogram<24>*/
  return kk_std_core__list_box(_x8481, _ctx);
}
static kk_box_t kk_climate_dash_experiments_run__experiments_fun8467(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun8467__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__experiments_fun8467__t*, _fself);
  kk_function_t model_5903 = _self->model_5903; /* () -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random,console,ndet,effects-and-types/sample> (double, double) */
  kk_integer_t sz = _self->sz; /* int */
  kk_drop_match(_self, {kk_function_dup(model_5903);kk_integer_dup(sz);}, {}, _ctx)
  kk_std_core__list _x8468;
  kk_std_core__list x_775 = kk_sampling_populate(kk_integer_from_small(100), kk_climate_dash_experiments_new_run__experiments_fun8469(model_5903, _ctx), _ctx); /*effects-and-types/histogram<(a : int) -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random,console,ndet,effects-and-types/sample> (double, double)>*/;
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_775, _ctx);
    kk_box_t _x8479 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments_new_run__experiments_fun8480(sz, _ctx), _ctx); /*2*/
    _x8468 = kk_std_core__list_unbox(_x8479, _ctx); /*effects-and-types/histogram<(double, double)>*/
  }
  else {
    _x8468 = kk_smc__mlift743_smc(true, sz, kk_integer_from_small(1), x_775, _ctx); /*effects-and-types/histogram<(double, double)>*/
  }
  return kk_std_core__list_box(_x8468, _ctx);
}
static kk_box_t kk_climate_dash_experiments_run__experiments_fun8451(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun8451__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__experiments_fun8451__t*, _fself);
  kk_std_core__list data__vals = _self->data__vals; /* list<(double, bool)> */
  kk_integer_t sz = _self->sz; /* int */
  kk_drop_match(_self, {kk_std_core__list_dup(data__vals);kk_integer_dup(sz);}, {}, _ctx)
  kk_std_core__list _x8452;
  kk_function_t model_5903;
  kk_function_t _x01_5620;
  kk_function_t _bv_7355;
  kk_box_t _x8453 = kk_std_core_hnd__open_none1(kk_climate_dash_experiments_new_run__experiments_fun8454(_ctx), kk_std_core__list_box(data__vals, _ctx), _ctx); /*2*/
  _bv_7355 = kk_function_unbox(_x8453); /*() -> <.Box|.Box> 7354*/
  _x01_5620 = kk_climate_dash_experiments_new_run__experiments_fun8459(_bv_7355, _ctx); /*effects-and-types/model<(double, double),div>*/
  model_5903 = kk_climate_dash_experiments_new_run__experiments_fun8461(_x01_5620, _ctx); /*() -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random,console,ndet,effects-and-types/sample> (double, double)*/
  kk_box_t _x8466 = kk_handlers_random__sampler(kk_climate_dash_experiments_new_run__experiments_fun8467(model_5903, sz, _ctx), _ctx); /*0*/
  _x8452 = kk_std_core__list_unbox(_x8466, _ctx); /*effects-and-types/histogram<(double, double)>*/
  return kk_std_core__list_box(_x8452, _ctx);
}
static kk_box_t kk_climate_dash_experiments_run__experiments_fun8448(kk_function_t _fself, kk_box_t _b_7391, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core_types__tuple2_ _match_7463 = kk_std_core_types__tuple2__unbox(_b_7391, _ctx); /*(int, list<(double, bool)>)*/;
  kk_box_t _box_x7347 = _match_7463.fst;
  kk_box_t _box_x7348 = _match_7463.snd;
  kk_integer_t sz = kk_integer_unbox(_box_x7347);
  kk_std_core__list data__vals = kk_std_core__list_unbox(_box_x7348, NULL);
  kk_std_core__list_dup(data__vals);
  kk_integer_dup(sz);
  kk_std_core_types__tuple2__drop(_match_7463, _ctx);
  return kk_std_time_timer_print_elapsed(kk_climate_dash_experiments_new_run__experiments_fun8451(data__vals, sz, _ctx), kk_std_core_types__new_None(_ctx), _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments_run__experiments_fun8484__t {
  struct kk_function_s _base;
  kk_integer_t i10;
  kk_std_core__list x0_5877;
  kk_std_core__list x3_5886;
};
static kk_box_t kk_climate_dash_experiments_run__experiments_fun8484(kk_function_t _fself, kk_box_t _b_7401, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__experiments_fun8484(kk_integer_t i10, kk_std_core__list x0_5877, kk_std_core__list x3_5886, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun8484__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__experiments_fun8484__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__experiments_fun8484, kk_context());
  _self->i10 = i10;
  _self->x0_5877 = x0_5877;
  _self->x3_5886 = x3_5886;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments_run__experiments_fun8484(kk_function_t _fself, kk_box_t _b_7401, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun8484__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__experiments_fun8484__t*, _fself);
  kk_integer_t i10 = _self->i10; /* int */
  kk_std_core__list x0_5877 = _self->x0_5877; /* list<(int, list<(double, bool)>)> */
  kk_std_core__list x3_5886 = _self->x3_5886; /* list<(double, bool)> */
  kk_drop_match(_self, {kk_integer_dup(i10);kk_std_core__list_dup(x0_5877);kk_std_core__list_dup(x3_5886);}, {}, _ctx)
  kk_unit_t _x8485 = kk_Unit;
  kk_std_core__list _x8486 = kk_std_core__list_unbox(_b_7401, _ctx); /*list<effects-and-types/histogram<(double, double)>>*/
  kk_climate_dash_experiments__mlift5644_run__experiments(x3_5886, x0_5877, i10, _x8486, _ctx);
  return kk_unit_box(_x8485);
}
static kk_unit_t kk_climate_dash_experiments_run__experiments_fun8440(kk_function_t _fself, kk_integer_t i10, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun8440__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__experiments_fun8440__t*, _fself);
  kk_std_core__list x0_5877 = _self->x0_5877; /* list<(int, list<(double, bool)>)> */
  kk_std_core__list x3_5886 = _self->x3_5886; /* list<(double, bool)> */
  kk_drop_match(_self, {kk_std_core__list_dup(x0_5877);kk_std_core__list_dup(x3_5886);}, {}, _ctx)
  kk_unit_t __ = kk_Unit;
  kk_string_t s_5896;
  kk_string_t _x8441;
  kk_define_string_literal(, _s8442, 7, "Round #")
  _x8441 = kk_string_dup(_s8442); /*string*/
  kk_string_t _x8443;
  kk_integer_t _x8444 = kk_integer_dup(i10); /*int*/
  _x8443 = kk_std_core_show(_x8444, _ctx); /*string*/
  s_5896 = kk_std_core__lp__plus__plus__1_rp_(_x8441, _x8443, _ctx); /*string*/
  kk_std_core_printsln(s_5896, _ctx);
  kk_unit_t __0 = kk_Unit;
  kk_string_t _x8445;
  kk_define_string_literal(, _s8446, 38, "Running SMC with increasing data size:")
  _x8445 = kk_string_dup(_s8446); /*string*/
  kk_std_core_printsln(_x8445, _ctx);
  kk_std_core__list x5_5898;
  kk_std_core__list _x8447 = kk_std_core__list_dup(x0_5877); /*list<(int, list<(double, bool)>)>*/
  x5_5898 = kk_std_core_map_5(_x8447, kk_climate_dash_experiments_new_run__experiments_fun8448(_ctx), _ctx); /*list<effects-and-types/histogram<(double, double)>>*/
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x5_5898, _ctx);
    kk_box_t _x8483 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments_new_run__experiments_fun8484(i10, x0_5877, x3_5886, _ctx), _ctx); /*2*/
    return kk_unit_unbox(_x8483);
  }
  return kk_climate_dash_experiments__mlift5644_run__experiments(x3_5886, x0_5877, i10, x5_5898, _ctx);
}

kk_unit_t kk_climate_dash_experiments_run__experiments(kk_std_core_types__optional number__of__repeats, kk_std_core_types__optional max__number__of__data__points, kk_context_t* _ctx) { /* (number_of_repeats : optional<int>, max_number_of_data_points : optional<int>) -> <pure,console,ndet,std/num/random/random,effects-and-types/sample> () */ 
  kk_std_core__list x_5871;
  kk_std_core__list _b_7298_7295;
  kk_integer_t _x8408;
  if (kk_std_core_types__is_Optional(max__number__of__data__points)) {
    kk_box_t _box_x7294 = max__number__of__data__points._cons.Optional.value;
    kk_integer_t _max__number__of__data__points_3560 = kk_integer_unbox(_box_x7294);
    kk_integer_dup(_max__number__of__data__points_3560);
    kk_std_core_types__optional_drop(max__number__of__data__points, _ctx);
    _x8408 = _max__number__of__data__points_3560; /*int*/
    goto _match8409;
  }
  _x8408 = kk_integer_from_small(3); /*int*/
  _match8409: ;
  _b_7298_7295 = kk_std_core__lift21053_list(kk_integer_from_small(0), _x8408, kk_std_core__new_Nil(_ctx), _ctx); /*list<int>*/
  x_5871 = kk_std_core_map_5(_b_7298_7295, kk_climate_dash_experiments_new_run__experiments_fun8411(_ctx), _ctx); /*list<int>*/
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_5871, _ctx);
    kk_box_t _x8414 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments_new_run__experiments_fun8415(number__of__repeats, _ctx), _ctx); /*2*/
    kk_unit_unbox(_x8414); return kk_Unit;
  }
  kk_std_core__list x0_5877 = kk_std_core_map_5(x_5871, kk_climate_dash_experiments_new_run__experiments_fun8418(_ctx), _ctx); /*list<(int, list<(double, bool)>)>*/;
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x0_5877, _ctx);
    kk_box_t _x8430 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments_new_run__experiments_fun8431(number__of__repeats, _ctx), _ctx); /*2*/
    kk_unit_unbox(_x8430); return kk_Unit;
  }
  kk_std_core__list x3_5886;
  size_t i2_5889 = ((size_t)1); /*std/core/hnd/ev-index*/;
  kk_evv_t w0 = kk_evv_swap_create1(i2_5889,kk_context()); /*std/core/hnd/evv<<std/num/random/random,console,div,exn,ndet,effects-and-types/sample>>*/;
  kk_std_core__list y0 = kk_model_dash_resources_generate__synthetic__lr__data(kk_integer_from_small(50), _ctx); /*list<(double, bool)>*/;
  kk_unit_t __w_l700_c90 = kk_Unit;
  kk_evv_set(w0,kk_context());
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(y0, _ctx);
    kk_box_t _x8434 = kk_std_core_hnd_yield_cont(kk_climate_dash_experiments_new_run__experiments_fun8435(i2_5889, _ctx), _ctx); /*3*/
    x3_5886 = kk_std_core__list_unbox(_x8434, _ctx); /*list<(double, bool)>*/
  }
  else {
    x3_5886 = y0; /*list<(double, bool)>*/
  }
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x3_5886, _ctx);
    kk_box_t _x8436 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments_new_run__experiments_fun8437(number__of__repeats, x0_5877, _ctx), _ctx); /*2*/
    kk_unit_unbox(_x8436); return kk_Unit;
  }
  kk_integer_t _x8487;
  if (kk_std_core_types__is_Optional(number__of__repeats)) {
    kk_box_t _box_x7402 = number__of__repeats._cons.Optional.value;
    kk_integer_t _number__of__repeats_3556 = kk_integer_unbox(_box_x7402);
    kk_integer_dup(_number__of__repeats_3556);
    kk_std_core_types__optional_drop(number__of__repeats, _ctx);
    _x8487 = _number__of__repeats_3556; /*int*/
    goto _match8488;
  }
  _x8487 = kk_integer_from_small(4); /*int*/
  _match8488: ;
  kk_std_core__lift21056_for(kk_climate_dash_experiments_new_run__experiments_fun8440(x0_5877, x3_5886, _ctx), _x8487, kk_integer_from_small(1), _ctx); return kk_Unit;
}
 
// monadic lift

kk_unit_t kk_climate_dash_experiments__mlift5649_main(kk_unit_t wild__3, kk_context_t* _ctx) { /* (wild_3 : ()) -> <pure,console,fsys,ndet,std/num/random/random> () */ 
  kk_unit_t __4 = kk_Unit;
  kk_string_t _x8490;
  kk_define_string_literal(, _s8491, 24, "Completed Climate Model!")
  _x8490 = kk_string_dup(_s8491); /*string*/
  kk_std_core_printsln(_x8490, _ctx);
  kk_string_t _x8492;
  kk_define_string_literal(, _s8493, 19, "Finished running...")
  _x8492 = kk_string_dup(_s8493); /*string*/
  kk_std_core_printsln(_x8492, _ctx); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_climate_dash_experiments__mlift5650_main_fun8500__t {
  struct kk_function_s _base;
};
static kk_box_t kk_climate_dash_experiments__mlift5650_main_fun8500(kk_function_t _fself, kk_box_t _b_7414, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift5650_main_fun8500(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_climate_dash_experiments__mlift5650_main_fun8500, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_climate_dash_experiments__mlift5650_main_fun8500(kk_function_t _fself, kk_box_t _b_7414, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_unit_t _x8501 = kk_Unit;
  kk_unit_t _x8502 = kk_Unit;
  kk_unit_unbox(_b_7414);
  kk_climate_dash_experiments__mlift5649_main(_x8502, _ctx);
  return kk_unit_box(_x8501);
}

kk_unit_t kk_climate_dash_experiments__mlift5650_main(kk_unit_t wild__0, kk_context_t* _ctx) { /* (wild_0 : ()) -> <std/num/random/random,console,div,exn,fsys,ndet> () */ 
  kk_unit_t __1 = kk_Unit;
  kk_string_t _x8494;
  kk_define_string_literal(, _s8495, 29, "Completed Timing Experiments!")
  _x8494 = kk_string_dup(_s8495); /*string*/
  kk_std_core_printsln(_x8494, _ctx);
  kk_unit_t __2 = kk_Unit;
  kk_string_t _x8496;
  kk_define_string_literal(, _s8497, 24, "Running Climate Model...")
  _x8496 = kk_string_dup(_s8497); /*string*/
  kk_std_core_printsln(_x8496, _ctx);
  kk_unit_t x_5909 = kk_Unit;
  kk_std_core_types__optional _x8498 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(8)), _ctx); /*optional<35>*/
  kk_climate_dash_experiments_run__climate__model(kk_integer_from_small(2000), kk_integer_from_small(131), kk_integer_from_small(2), kk_integer_from_int(100000, _ctx), kk_integer_from_int(80000, _ctx), _x8498, _ctx);
  if (kk_yielding(kk_context())) {
    kk_box_t _x8499 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments__new_mlift5650_main_fun8500(_ctx), _ctx); /*2*/
    kk_unit_unbox(_x8499); return kk_Unit;
  }
  kk_climate_dash_experiments__mlift5649_main(x_5909, _ctx); return kk_Unit;
}


// lift anonymous function
struct kk_climate_dash_experiments_main_fun8506__t {
  struct kk_function_s _base;
};
static kk_box_t kk_climate_dash_experiments_main_fun8506(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_main_fun8506(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_climate_dash_experiments_main_fun8506, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_climate_dash_experiments_main_fun8506(kk_function_t _fself, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return kk_unit_box(kk_Unit);
}


// lift anonymous function
struct kk_climate_dash_experiments_main_fun8508__t {
  struct kk_function_s _base;
};
static kk_box_t kk_climate_dash_experiments_main_fun8508(kk_function_t _fself, kk_box_t _b_7419, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_main_fun8508(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_climate_dash_experiments_main_fun8508, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_climate_dash_experiments_main_fun8508(kk_function_t _fself, kk_box_t _b_7419, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_unit_t _x8509 = kk_Unit;
  kk_unit_t _x8510 = kk_Unit;
  kk_unit_unbox(_b_7419);
  kk_climate_dash_experiments__mlift5650_main(_x8510, _ctx);
  return kk_unit_box(_x8509);
}


// lift anonymous function
struct kk_climate_dash_experiments_main_fun8517__t {
  struct kk_function_s _base;
};
static kk_box_t kk_climate_dash_experiments_main_fun8517(kk_function_t _fself, kk_box_t _b_7423, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_main_fun8517(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_climate_dash_experiments_main_fun8517, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_climate_dash_experiments_main_fun8517(kk_function_t _fself, kk_box_t _b_7423, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_unit_t _x8518 = kk_Unit;
  kk_unit_t _x8519 = kk_Unit;
  kk_unit_unbox(_b_7423);
  kk_climate_dash_experiments__mlift5649_main(_x8519, _ctx);
  return kk_unit_box(_x8518);
}

kk_unit_t kk_climate_dash_experiments_main(kk_context_t* _ctx) { /* () -> <pure,console,fsys,ndet,std/num/random/random> () */ 
  kk_unit_t __ = kk_Unit;
  kk_string_t _x8503;
  kk_define_string_literal(, _s8504, 29, "Running Timing Experiments...")
  _x8503 = kk_string_dup(_s8504); /*string*/
  kk_std_core_printsln(_x8503, _ctx);
  kk_unit_t x_5912 = kk_Unit;
  kk_box_t _x8505 = kk_handlers_random__sampler(kk_climate_dash_experiments_new_main_fun8506(_ctx), _ctx); /*0*/
  kk_unit_unbox(_x8505);
  if (kk_yielding(kk_context())) {
    kk_box_t _x8507 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments_new_main_fun8508(_ctx), _ctx); /*2*/
    kk_unit_unbox(_x8507); return kk_Unit;
  }
  kk_unit_t __1 = kk_Unit;
  kk_string_t _x8511;
  kk_define_string_literal(, _s8512, 29, "Completed Timing Experiments!")
  _x8511 = kk_string_dup(_s8512); /*string*/
  kk_std_core_printsln(_x8511, _ctx);
  kk_unit_t __2 = kk_Unit;
  kk_string_t _x8513;
  kk_define_string_literal(, _s8514, 24, "Running Climate Model...")
  _x8513 = kk_string_dup(_s8514); /*string*/
  kk_std_core_printsln(_x8513, _ctx);
  kk_unit_t x0_5918 = kk_Unit;
  kk_std_core_types__optional _x8515 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(8)), _ctx); /*optional<35>*/
  kk_climate_dash_experiments_run__climate__model(kk_integer_from_small(2000), kk_integer_from_small(131), kk_integer_from_small(2), kk_integer_from_int(100000, _ctx), kk_integer_from_int(80000, _ctx), _x8515, _ctx);
  if (kk_yielding(kk_context())) {
    kk_box_t _x8516 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments_new_main_fun8517(_ctx), _ctx); /*2*/
    kk_unit_unbox(_x8516); return kk_Unit;
  }
  kk_unit_t __4 = kk_Unit;
  kk_string_t _x8520;
  kk_define_string_literal(, _s8521, 24, "Completed Climate Model!")
  _x8520 = kk_string_dup(_s8521); /*string*/
  kk_std_core_printsln(_x8520, _ctx);
  kk_string_t _x8522;
  kk_define_string_literal(, _s8523, 19, "Finished running...")
  _x8522 = kk_string_dup(_s8523); /*string*/
  kk_std_core_printsln(_x8522, _ctx); return kk_Unit;
}

// initialization
void kk_climate_dash_experiments__init(kk_context_t* _ctx){
  static bool _initialized = false;
  if (_initialized) return;
  _initialized = true;
  kk_std_core_types__init(_ctx);
  kk_std_core_hnd__init(_ctx);
  kk_std_core__init(_ctx);
  kk_std_num_random__init(_ctx);
  kk_std_time_timer__init(_ctx);
  kk_effects_dash_and_dash_types__init(_ctx);
  kk_std_os_path__init(_ctx);
  kk_std_os_file__init(_ctx);
  kk_output_dash_and_dash_plot__init(_ctx);
  kk_handlers__init(_ctx);
  kk_sampling__init(_ctx);
  kk_smc__init(_ctx);
  kk_model_dash_resources__init(_ctx);
  kk_tmcmc__init(_ctx);
  kk_climate_dash_change__init(_ctx);
  kk_data_preprocessing__init(_ctx);
}
