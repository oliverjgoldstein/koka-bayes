// Koka generated module: "climate-experiments", koka version: 2.1.3
#include "climate_dash_experiments.h"
 
// monadic lift


// lift anonymous function
struct kk_climate_dash_experiments__mlift4683_run__climate__model_fun6270__t {
  struct kk_function_s _base;
};
static kk_box_t kk_climate_dash_experiments__mlift4683_run__climate__model_fun6270(kk_function_t _fself, kk_box_t _b_4951, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift4683_run__climate__model_fun6270(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_climate_dash_experiments__mlift4683_run__climate__model_fun6270, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_climate_dash_experiments__mlift4683_run__climate__model_fun6270(kk_function_t _fself, kk_box_t _b_4951, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_os_path__path _x6271;
  kk_string_t _x6272 = kk_string_unbox(_b_4951); /*string*/
  _x6271 = kk_std_os_path_path(_x6272, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x6271, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift4683_run__climate__model_fun6275__t {
  struct kk_function_s _base;
};
static kk_box_t kk_climate_dash_experiments__mlift4683_run__climate__model_fun6275(kk_function_t _fself, kk_box_t _b_4956, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift4683_run__climate__model_fun6275(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_climate_dash_experiments__mlift4683_run__climate__model_fun6275, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_climate_dash_experiments__mlift4683_run__climate__model_fun6275(kk_function_t _fself, kk_box_t _b_4956, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x6276;
  kk_std_core__list _x6277 = kk_std_core__list_unbox(_b_4956, _ctx); /*list<(list<double>, list<double>)>*/
  _x6276 = kk_output_dash_and_dash_plot_show__trace(_x6277, _ctx); /*string*/
  return kk_string_box(_x6276);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift4683_run__climate__model_fun6283__t {
  struct kk_function_s _base;
  size_t i_4701;
};
static kk_box_t kk_climate_dash_experiments__mlift4683_run__climate__model_fun6283(kk_function_t _fself, kk_function_t _b_4966, kk_box_t _b_4967, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift4683_run__climate__model_fun6283(size_t i_4701, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4683_run__climate__model_fun6283__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift4683_run__climate__model_fun6283__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift4683_run__climate__model_fun6283, kk_context());
  _self->i_4701 = i_4701;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift4683_run__climate__model_fun6283(kk_function_t _fself, kk_function_t _b_4966, kk_box_t _b_4967, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4683_run__climate__model_fun6283__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift4683_run__climate__model_fun6283__t*, _fself);
  size_t i_4701 = _self->i_4701; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_4701, _b_4966, _b_4967, _ctx);
}

kk_unit_t kk_climate_dash_experiments__mlift4683_run__climate__model(kk_string_t name0, kk_std_core_types__tuple2_ _y_12, kk_context_t* _ctx) { /* (name0 : string, (list<(list<double>, list<double>)>, tmcmc/trace<list<double>,<effects-and-types/sample,effects-and-types/score,div,exn,fsys,console,ndet,std/num/random/random>>)) -> <effects-and-types/sample,div,exn,fsys,console,ndet,std/num/random/random> () */ 
  kk_string_t _x210;
  kk_string_t _x6260;
  kk_define_string_literal(, _s6261, 17, "./output-climate/")
  _x6260 = kk_string_dup(_s6261); /*string*/
  kk_string_t _x6262;
  kk_string_t _x6263;
  kk_string_t _x6264;
  kk_define_string_literal(, _s6265, 1, "/")
  _x6264 = kk_string_dup(_s6265); /*string*/
  kk_string_t _x6266;
  kk_define_string_literal(, _s6267, 25, "tmcmc_exp_two_results.csv")
  _x6266 = kk_string_dup(_s6267); /*string*/
  _x6263 = kk_std_core__lp__plus__plus__1_rp_(_x6264, _x6266, _ctx); /*string*/
  _x6262 = kk_std_core__lp__plus__plus__1_rp_(name0, _x6263, _ctx); /*string*/
  _x210 = kk_std_core__lp__plus__plus__1_rp_(_x6260, _x6262, _ctx); /*string*/
  size_t i_4701 = ((size_t)0); /*std/core/hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_4701,kk_context()); /*std/core/hnd/evv<<exn,fsys,div,effects-and-types/sample,console,ndet,std/num/random/random>>*/;
  kk_unit_t y = kk_Unit;
  kk_std_os_path__path _x6268;
  kk_box_t _x6269 = kk_std_core_hnd__open_none1(kk_climate_dash_experiments__new_mlift4683_run__climate__model_fun6270(_ctx), kk_string_box(_x210), _ctx); /*2*/
  _x6268 = kk_std_os_path__path_unbox(_x6269, _ctx); /*std/os/path/path*/
  kk_string_t _x6273;
  kk_box_t _x6274;
  kk_box_t _x6278;
  kk_std_core__list _x6279;
  kk_box_t _box_x4952 = _y_12.fst;
  kk_box_t _box_x4953 = _y_12.snd;
  kk_std_core__list _x = kk_std_core__list_unbox(_box_x4952, NULL);
  kk_std_core__list_dup(_x);
  kk_std_core_types__tuple2__drop(_y_12, _ctx);
  _x6279 = _x; /*list<(list<double>, list<double>)>*/
  _x6278 = kk_std_core__list_box(_x6279, _ctx); /*1*/
  _x6274 = kk_std_core_hnd__open_none1(kk_climate_dash_experiments__new_mlift4683_run__climate__model_fun6275(_ctx), _x6278, _ctx); /*2*/
  _x6273 = kk_string_unbox(_x6274); /*string*/
  kk_std_os_file_write_text_file(_x6268, _x6273, kk_std_core_types__new_None(_ctx), _ctx);
  kk_unit_t __w_l717_c9 = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x6282 = kk_std_core_hnd_yield_cont(kk_climate_dash_experiments__new_mlift4683_run__climate__model_fun6283(i_4701, _ctx), _ctx); /*3*/
    kk_unit_unbox(_x6282); return kk_Unit;
  }
  y; return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_climate_dash_experiments__mlift4684_run__climate__model_fun6302__t {
  struct kk_function_s _base;
  size_t i_4708;
};
static kk_box_t kk_climate_dash_experiments__mlift4684_run__climate__model_fun6302(kk_function_t _fself, kk_function_t _b_4996, kk_box_t _b_4997, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift4684_run__climate__model_fun6302(size_t i_4708, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4684_run__climate__model_fun6302__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift4684_run__climate__model_fun6302__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift4684_run__climate__model_fun6302, kk_context());
  _self->i_4708 = i_4708;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift4684_run__climate__model_fun6302(kk_function_t _fself, kk_function_t _b_4996, kk_box_t _b_4997, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4684_run__climate__model_fun6302__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift4684_run__climate__model_fun6302__t*, _fself);
  size_t i_4708 = _self->i_4708; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_4708, _b_4996, _b_4997, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift4684_run__climate__model_fun6320__t {
  struct kk_function_s _base;
  size_t i0_4713;
};
static kk_box_t kk_climate_dash_experiments__mlift4684_run__climate__model_fun6320(kk_function_t _fself, kk_function_t _b_5026, kk_box_t _b_5027, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift4684_run__climate__model_fun6320(size_t i0_4713, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4684_run__climate__model_fun6320__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift4684_run__climate__model_fun6320__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift4684_run__climate__model_fun6320, kk_context());
  _self->i0_4713 = i0_4713;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift4684_run__climate__model_fun6320(kk_function_t _fself, kk_function_t _b_5026, kk_box_t _b_5027, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4684_run__climate__model_fun6320__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift4684_run__climate__model_fun6320__t*, _fself);
  size_t i0_4713 = _self->i0_4713; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i0_4713, _b_5026, _b_5027, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift4684_run__climate__model_fun6321__t {
  struct kk_function_s _base;
  kk_function_t _x09_4668;
};
static kk_std_core__list kk_climate_dash_experiments__mlift4684_run__climate__model_fun6321(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift4684_run__climate__model_fun6321(kk_function_t _x09_4668, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4684_run__climate__model_fun6321__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift4684_run__climate__model_fun6321__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift4684_run__climate__model_fun6321, kk_context());
  _self->_x09_4668 = _x09_4668;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift4684_run__climate__model_fun6324__t {
  struct kk_function_s _base;
  kk_function_t _x09_4668;
};
static kk_box_t kk_climate_dash_experiments__mlift4684_run__climate__model_fun6324(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift4684_run__climate__model_fun6324(kk_function_t _x09_4668, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4684_run__climate__model_fun6324__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift4684_run__climate__model_fun6324__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift4684_run__climate__model_fun6324, kk_context());
  _self->_x09_4668 = _x09_4668;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift4684_run__climate__model_fun6324(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4684_run__climate__model_fun6324__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift4684_run__climate__model_fun6324__t*, _fself);
  kk_function_t _x09_4668 = _self->_x09_4668; /* effects-and-types/model<list<double>,exn> */
  kk_drop_match(_self, {kk_function_dup(_x09_4668);}, {}, _ctx)
  kk_std_core__list _x6325 = kk_function_call(kk_std_core__list, (kk_function_t, kk_context_t*), _x09_4668, (_x09_4668, _ctx)); /*list<double>*/
  return kk_std_core__list_box(_x6325, _ctx);
}
static kk_std_core__list kk_climate_dash_experiments__mlift4684_run__climate__model_fun6321(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4684_run__climate__model_fun6321__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift4684_run__climate__model_fun6321__t*, _fself);
  kk_function_t _x09_4668 = _self->_x09_4668; /* effects-and-types/model<list<double>,exn> */
  kk_drop_match(_self, {kk_function_dup(_x09_4668);}, {}, _ctx)
  kk_vector_t _b_5052_5042;
  kk_std_core__list _x6322;
  size_t _b_5054_5040 = ((size_t)0); /*std/core/hnd/ev-index*/;
  kk_std_core__list _b_5055_5041;
  size_t _b_5056_5038 = ((size_t)2); /*std/core/hnd/ev-index*/;
  kk_std_core__list _b_5057_5039;
  size_t _b_5058_5036 = ((size_t)3); /*std/core/hnd/ev-index*/;
  _b_5057_5039 = kk_std_core__new_Cons(kk_reuse_null, kk_size_box(_b_5058_5036, _ctx), kk_std_core__new_Nil(_ctx), _ctx); /*list<std/core/hnd/ev-index>*/
  _b_5055_5041 = kk_std_core__new_Cons(kk_reuse_null, kk_size_box(_b_5056_5038, _ctx), _b_5057_5039, _ctx); /*list<std/core/hnd/ev-index>*/
  _x6322 = kk_std_core__new_Cons(kk_reuse_null, kk_size_box(_b_5054_5040, _ctx), _b_5055_5041, _ctx); /*list<0>*/
  _b_5052_5042 = kk_std_core_unvlist(_x6322, _ctx); /*vector<std/core/hnd/ev-index>*/
  kk_box_t _x6323 = kk_std_core_hnd__open0(_b_5052_5042, kk_climate_dash_experiments__new_mlift4684_run__climate__model_fun6324(_x09_4668, _ctx), _ctx); /*1*/
  return kk_std_core__list_unbox(_x6323, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift4684_run__climate__model_fun6326__t {
  struct kk_function_s _base;
  kk_function_t _b_5048_5044;
};
static kk_box_t kk_climate_dash_experiments__mlift4684_run__climate__model_fun6326(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift4684_run__climate__model_fun6326(kk_function_t _b_5048_5044, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4684_run__climate__model_fun6326__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift4684_run__climate__model_fun6326__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift4684_run__climate__model_fun6326, kk_context());
  _self->_b_5048_5044 = _b_5048_5044;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift4684_run__climate__model_fun6326(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4684_run__climate__model_fun6326__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift4684_run__climate__model_fun6326__t*, _fself);
  kk_function_t _b_5048_5044 = _self->_b_5048_5044; /* () -> <effects-and-types/sample,effects-and-types/score,exn> list<double> */
  kk_drop_match(_self, {kk_function_dup(_b_5048_5044);}, {}, _ctx)
  kk_std_core__list _x6327 = kk_function_call(kk_std_core__list, (kk_function_t, kk_context_t*), _b_5048_5044, (_b_5048_5044, _ctx)); /*list<double>*/
  return kk_std_core__list_box(_x6327, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift4684_run__climate__model_fun6329__t {
  struct kk_function_s _base;
  kk_string_t name0;
};
static kk_box_t kk_climate_dash_experiments__mlift4684_run__climate__model_fun6329(kk_function_t _fself, kk_box_t _b_5061, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift4684_run__climate__model_fun6329(kk_string_t name0, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4684_run__climate__model_fun6329__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift4684_run__climate__model_fun6329__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift4684_run__climate__model_fun6329, kk_context());
  _self->name0 = name0;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift4684_run__climate__model_fun6329(kk_function_t _fself, kk_box_t _b_5061, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4684_run__climate__model_fun6329__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift4684_run__climate__model_fun6329__t*, _fself);
  kk_string_t name0 = _self->name0; /* string */
  kk_drop_match(_self, {kk_string_dup(name0);}, {}, _ctx)
  kk_unit_t _x6330 = kk_Unit;
  kk_std_core_types__tuple2_ _x6331 = kk_std_core_types__tuple2__unbox(_b_5061, _ctx); /*(list<(list<double>, list<double>)>, tmcmc/trace<list<double>,<effects-and-types/sample,effects-and-types/score,div,exn,fsys,console,ndet,std/num/random/random>>)*/
  kk_climate_dash_experiments__mlift4683_run__climate__model(name0, _x6331, _ctx);
  return kk_unit_box(_x6330);
}

kk_unit_t kk_climate_dash_experiments__mlift4684_run__climate__model(kk_integer_t burnin, kk_std_core_types__tuple2_ data, double diff0, kk_integer_t ind0, kk_string_t name0, double subtract0, kk_integer_t t__steps, kk_std_core__list _y_11, kk_context_t* _ctx) { /* (burnin : int, data : (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>), diff0 : double, ind0 : int, name0 : string, subtract0 : double, t_steps : int, list<effects-and-types/row_vector>) -> <exn,div,effects-and-types/sample,fsys,console,ndet,std/num/random/random> () */ 
  kk_std_core__list_drop(_y_11, _ctx);
  kk_std_core_types__tuple2_ x_4705;
  kk_function_t _b_5048_5044;
  kk_function_t _x09_4668;
  kk_std_core__list _x17;
  size_t i_4708 = ((size_t)0); /*std/core/hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_4708,kk_context()); /*std/core/hnd/evv<<exn,div,effects-and-types/sample,fsys,console,ndet,std/num/random/random>>*/;
  kk_std_core__list y;
  kk_std_core_types__maybe _match_6256;
  kk_std_core__list _x6284;
  kk_box_t _box_x4976 = data.fst;
  kk_box_t _box_x4977 = data.snd;
  kk_std_core__list _x = kk_std_core__list_unbox(_box_x4977, NULL);
  kk_std_core__list_dup(_x);
  _x6284 = _x; /*list<list<effects-and-types/row_vector>>*/
  kk_integer_t _x6287 = kk_integer_dup(ind0); /*int*/
  _match_6256 = kk_std_core__lp__lb__rb__2_rp_(_x6284, _x6287, _ctx); /*maybe<1>*/
  if (kk_std_core_types__is_Nothing(_match_6256)) {
    kk_string_t message_205;
    kk_string_t _x6288;
    kk_define_string_literal(, _s6289, 48, "ListIndexError: Invalid list indexing at index: ")
    _x6288 = kk_string_dup(_s6289); /*string*/
    kk_string_t _x6290;
    kk_integer_t _x6291 = kk_integer_dup(ind0); /*int*/
    _x6290 = kk_std_core_show(_x6291, _ctx); /*string*/
    message_205 = kk_std_core__lp__plus__plus__1_rp_(_x6288, _x6290, _ctx); /*string*/
    kk_std_core__exception exn_21561;
    kk_std_core__exception_info _x6292;
    kk_std_core_types__optional _match_6258 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
    if (kk_std_core_types__is_Optional(_match_6258)) {
      kk_box_t _box_x4978 = _match_6258._cons.Optional.value;
      kk_std_core__exception_info _info_14279 = kk_std_core__exception_info_unbox(_box_x4978, NULL);
      kk_std_core__exception_info_dup(_info_14279);
      kk_std_core_types__optional_drop(_match_6258, _ctx);
      _x6292 = _info_14279; /*exception-info*/
      goto _match6293;
    }
    _x6292 = kk_std_core__new_ExnError(_ctx); /*exception-info*/
    _match6293: ;
    exn_21561 = kk_std_core__new_Exception(message_205, _x6292, _ctx); /*exception*/
    kk_std_core_hnd__ev ev_21562;
    size_t _x6295 = ((size_t)0); /*size_t*/
    ev_21562 = kk_evv_at(_x6295,kk_context()); /*std/core/hnd/ev<.hnd-exn>*/
    kk_box_t _x6296;
    struct kk_std_core_hnd_Ev* _con6297 = kk_std_core_hnd__as_Ev(ev_21562);
    kk_std_core_hnd__marker m = _con6297->marker;
    kk_box_t _box_x4979 = _con6297->hnd;
    kk_std_core__hnd_exn h = kk_std_core__hnd_exn_unbox(_box_x4979, NULL);
    kk_std_core__hnd_exn_dup(h);
    kk_std_core_hnd__clause1 _match_6257;
    struct kk_std_core__Hnd_exn* _con6299 = kk_std_core__as_Hnd_exn(h);
    kk_std_core_hnd__clause1 except_throw_exn = _con6299->except_throw_exn;
    if (kk_std_core__hnd_exn_is_unique(h)) {
      kk_std_core__hnd_exn_free(h);
    }
    else {
      kk_std_core_hnd__clause1_dup(except_throw_exn);
      kk_std_core__hnd_exn_decref(h, _ctx);
    }
    _match_6257 = except_throw_exn; /*forall<a> std/core/hnd/clause1<exception,a,.hnd-exn,7,8>*/
    kk_function_t _fun_unbox_x4983 = _match_6257.clause;
    _x6296 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x4983, (_fun_unbox_x4983, m, ev_21562, kk_std_core__exception_box(exn_21561, _ctx), _ctx)); /*11*/
    y = kk_std_core__list_unbox(_x6296, _ctx); /*list<effects-and-types/row_vector>*/
  }
  else {
    kk_box_t _box_x4987 = _match_6256._cons.Just.value;
    kk_std_core__list x = kk_std_core__list_unbox(_box_x4987, NULL);
    kk_std_core__list_dup(x);
    kk_std_core_types__maybe_drop(_match_6256, _ctx);
    y = x; /*list<effects-and-types/row_vector>*/
  }
  kk_unit_t __w_l717_c9 = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(y, _ctx);
    kk_box_t _x6301 = kk_std_core_hnd_yield_cont(kk_climate_dash_experiments__new_mlift4684_run__climate__model_fun6302(i_4708, _ctx), _ctx); /*3*/
    _x17 = kk_std_core__list_unbox(_x6301, _ctx); /*list<effects-and-types/row_vector>*/
  }
  else {
    _x17 = y; /*list<effects-and-types/row_vector>*/
  }
  kk_std_core__list _x27;
  size_t i0_4713 = ((size_t)0); /*std/core/hnd/ev-index*/;
  kk_evv_t w0 = kk_evv_swap_create1(i0_4713,kk_context()); /*std/core/hnd/evv<<exn,div,effects-and-types/sample,fsys,console,ndet,std/num/random/random>>*/;
  kk_std_core__list y0;
  kk_std_core_types__maybe _match_6252;
  kk_std_core__list _x6303;
  kk_box_t _box_x5006 = data.fst;
  kk_box_t _box_x5007 = data.snd;
  kk_std_core__list _x0 = kk_std_core__list_unbox(_box_x5006, NULL);
  kk_std_core__list_dup(_x0);
  kk_std_core_types__tuple2__drop(data, _ctx);
  _x6303 = _x0; /*list<list<effects-and-types/row_vector>>*/
  kk_integer_t _x6306 = kk_integer_dup(ind0); /*int*/
  _match_6252 = kk_std_core__lp__lb__rb__2_rp_(_x6303, _x6306, _ctx); /*maybe<1>*/
  if (kk_std_core_types__is_Nothing(_match_6252)) {
    kk_string_t message_2050;
    kk_string_t _x6307;
    kk_define_string_literal(, _s6308, 48, "ListIndexError: Invalid list indexing at index: ")
    _x6307 = kk_string_dup(_s6308); /*string*/
    kk_string_t _x6309 = kk_std_core_show(ind0, _ctx); /*string*/
    message_2050 = kk_std_core__lp__plus__plus__1_rp_(_x6307, _x6309, _ctx); /*string*/
    kk_std_core__exception exn_215610;
    kk_std_core__exception_info _x6310;
    kk_std_core_types__optional _match_6254 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
    if (kk_std_core_types__is_Optional(_match_6254)) {
      kk_box_t _box_x5008 = _match_6254._cons.Optional.value;
      kk_std_core__exception_info _info_142790 = kk_std_core__exception_info_unbox(_box_x5008, NULL);
      kk_std_core__exception_info_dup(_info_142790);
      kk_std_core_types__optional_drop(_match_6254, _ctx);
      _x6310 = _info_142790; /*exception-info*/
      goto _match6311;
    }
    _x6310 = kk_std_core__new_ExnError(_ctx); /*exception-info*/
    _match6311: ;
    exn_215610 = kk_std_core__new_Exception(message_2050, _x6310, _ctx); /*exception*/
    kk_std_core_hnd__ev ev_215620;
    size_t _x6313 = ((size_t)0); /*size_t*/
    ev_215620 = kk_evv_at(_x6313,kk_context()); /*std/core/hnd/ev<.hnd-exn>*/
    kk_box_t _x6314;
    struct kk_std_core_hnd_Ev* _con6315 = kk_std_core_hnd__as_Ev(ev_215620);
    kk_std_core_hnd__marker m0 = _con6315->marker;
    kk_box_t _box_x5009 = _con6315->hnd;
    kk_std_core__hnd_exn h0 = kk_std_core__hnd_exn_unbox(_box_x5009, NULL);
    kk_std_core__hnd_exn_dup(h0);
    kk_std_core_hnd__clause1 _match_6253;
    struct kk_std_core__Hnd_exn* _con6317 = kk_std_core__as_Hnd_exn(h0);
    kk_std_core_hnd__clause1 except_throw_exn0 = _con6317->except_throw_exn;
    if (kk_std_core__hnd_exn_is_unique(h0)) {
      kk_std_core__hnd_exn_free(h0);
    }
    else {
      kk_std_core_hnd__clause1_dup(except_throw_exn0);
      kk_std_core__hnd_exn_decref(h0, _ctx);
    }
    _match_6253 = except_throw_exn0; /*forall<a> std/core/hnd/clause1<exception,a,.hnd-exn,7,8>*/
    kk_function_t _fun_unbox_x5013 = _match_6253.clause;
    _x6314 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x5013, (_fun_unbox_x5013, m0, ev_215620, kk_std_core__exception_box(exn_215610, _ctx), _ctx)); /*11*/
    y0 = kk_std_core__list_unbox(_x6314, _ctx); /*list<effects-and-types/row_vector>*/
  }
  else {
    kk_box_t _box_x5017 = _match_6252._cons.Just.value;
    kk_std_core__list x0 = kk_std_core__list_unbox(_box_x5017, NULL);
    kk_integer_drop(ind0, _ctx);
    kk_std_core__list_dup(x0);
    kk_std_core_types__maybe_drop(_match_6252, _ctx);
    y0 = x0; /*list<effects-and-types/row_vector>*/
  }
  kk_unit_t __w_l717_c90 = kk_Unit;
  kk_evv_set(w0,kk_context());
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(y0, _ctx);
    kk_box_t _x6319 = kk_std_core_hnd_yield_cont(kk_climate_dash_experiments__new_mlift4684_run__climate__model_fun6320(i0_4713, _ctx), _ctx); /*3*/
    _x27 = kk_std_core__list_unbox(_x6319, _ctx); /*list<effects-and-types/row_vector>*/
  }
  else {
    _x27 = y0; /*list<effects-and-types/row_vector>*/
  }
  kk_evv_t w1 = kk_evv_swap_create0(kk_context()); /*std/core/hnd/evv<(<>)>*/;
  kk_function_t x00 = kk_climate_dash_change_linear__gaussian__climate__data(_x17, _x27, false, diff0, subtract0, 0x1.2cccccccccccdp2, _ctx); /*effects-and-types/model<list<double>,exn>*/;
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w1,kk_context());
  _x09_4668 = x00; /*effects-and-types/model<list<double>,exn>*/
  _b_5048_5044 = kk_climate_dash_experiments__new_mlift4684_run__climate__model_fun6321(_x09_4668, _ctx); /*() -> <effects-and-types/sample,effects-and-types/score,exn> list<double>*/
  kk_effects_dash_and_dash_types__exp _b_5050_5046 = kk_effects_dash_and_dash_types__new_Exp(0x0p+0, _ctx); /*effects-and-types/exp*/;
  x_4705 = kk_tmcmc_tmcmc(kk_climate_dash_experiments__new_mlift4684_run__climate__model_fun6326(_b_5048_5044, _ctx), t__steps, _b_5050_5046, burnin, _ctx); /*(list<(list<double>, list<double>)>, tmcmc/trace<list<double>,<effects-and-types/sample,effects-and-types/score,div,exn,fsys,console,ndet,std/num/random/random>>)*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__tuple2__drop(x_4705, _ctx);
    kk_box_t _x6328 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments__new_mlift4684_run__climate__model_fun6329(name0, _ctx), _ctx); /*2*/
    kk_unit_unbox(_x6328); return kk_Unit;
  }
  kk_climate_dash_experiments__mlift4683_run__climate__model(name0, x_4705, _ctx); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_climate_dash_experiments__mlift4685_run__climate__model_fun6350__t {
  struct kk_function_s _base;
  size_t i_4721;
};
static kk_box_t kk_climate_dash_experiments__mlift4685_run__climate__model_fun6350(kk_function_t _fself, kk_function_t _b_5084, kk_box_t _b_5085, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift4685_run__climate__model_fun6350(size_t i_4721, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4685_run__climate__model_fun6350__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift4685_run__climate__model_fun6350__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift4685_run__climate__model_fun6350, kk_context());
  _self->i_4721 = i_4721;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift4685_run__climate__model_fun6350(kk_function_t _fself, kk_function_t _b_5084, kk_box_t _b_5085, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4685_run__climate__model_fun6350__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift4685_run__climate__model_fun6350__t*, _fself);
  size_t i_4721 = _self->i_4721; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_4721, _b_5084, _b_5085, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift4685_run__climate__model_fun6352__t {
  struct kk_function_s _base;
  kk_integer_t burnin;
  kk_std_core_types__tuple2_ data;
  kk_integer_t ind0;
  kk_string_t name0;
  kk_integer_t t__steps;
  double diff0;
  double subtract0;
};
static kk_box_t kk_climate_dash_experiments__mlift4685_run__climate__model_fun6352(kk_function_t _fself, kk_box_t _b_5095, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift4685_run__climate__model_fun6352(kk_integer_t burnin, kk_std_core_types__tuple2_ data, kk_integer_t ind0, kk_string_t name0, kk_integer_t t__steps, double diff0, double subtract0, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4685_run__climate__model_fun6352__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift4685_run__climate__model_fun6352__t, 7, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift4685_run__climate__model_fun6352, kk_context());
  _self->burnin = burnin;
  _self->data = data;
  _self->ind0 = ind0;
  _self->name0 = name0;
  _self->t__steps = t__steps;
  _self->diff0 = diff0;
  _self->subtract0 = subtract0;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift4685_run__climate__model_fun6352(kk_function_t _fself, kk_box_t _b_5095, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4685_run__climate__model_fun6352__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift4685_run__climate__model_fun6352__t*, _fself);
  kk_integer_t burnin = _self->burnin; /* int */
  kk_std_core_types__tuple2_ data = _self->data; /* (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>) */
  kk_integer_t ind0 = _self->ind0; /* int */
  kk_string_t name0 = _self->name0; /* string */
  kk_integer_t t__steps = _self->t__steps; /* int */
  double diff0 = _self->diff0; /* double */
  double subtract0 = _self->subtract0; /* double */
  kk_drop_match(_self, {kk_integer_dup(burnin);kk_std_core_types__tuple2__dup(data);kk_integer_dup(ind0);kk_string_dup(name0);kk_integer_dup(t__steps);;;}, {}, _ctx)
  kk_unit_t _x6353 = kk_Unit;
  kk_std_core__list _x6354 = kk_std_core__list_unbox(_b_5095, _ctx); /*list<effects-and-types/row_vector>*/
  kk_climate_dash_experiments__mlift4684_run__climate__model(burnin, data, diff0, ind0, name0, subtract0, t__steps, _x6354, _ctx);
  return kk_unit_box(_x6353);
}

kk_unit_t kk_climate_dash_experiments__mlift4685_run__climate__model(kk_integer_t burnin, kk_std_core_types__tuple2_ data, double diff0, kk_integer_t ind0, kk_string_t name0, double subtract0, kk_integer_t t__steps, kk_std_core__list _y_10, kk_context_t* _ctx) { /* (burnin : int, data : (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>), diff0 : double, ind0 : int, name0 : string, subtract0 : double, t_steps : int, list<effects-and-types/row_vector>) -> <exn,div,effects-and-types/sample,fsys,console,ndet,std/num/random/random> () */ 
  kk_std_core__list_drop(_y_10, _ctx);
  kk_std_core__list x_4718;
  size_t i_4721 = ((size_t)0); /*std/core/hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_4721,kk_context()); /*std/core/hnd/evv<<exn,div,effects-and-types/sample,fsys,console,ndet,std/num/random/random>>*/;
  kk_std_core__list y;
  kk_std_core_types__maybe _match_6247;
  kk_std_core__list _x6332;
  kk_box_t _box_x5064 = data.fst;
  kk_box_t _box_x5065 = data.snd;
  kk_std_core__list _x = kk_std_core__list_unbox(_box_x5064, NULL);
  kk_std_core__list_dup(_x);
  _x6332 = _x; /*list<list<effects-and-types/row_vector>>*/
  kk_integer_t _x6335 = kk_integer_dup(ind0); /*int*/
  _match_6247 = kk_std_core__lp__lb__rb__2_rp_(_x6332, _x6335, _ctx); /*maybe<1>*/
  if (kk_std_core_types__is_Nothing(_match_6247)) {
    kk_string_t message_205;
    kk_string_t _x6336;
    kk_define_string_literal(, _s6337, 48, "ListIndexError: Invalid list indexing at index: ")
    _x6336 = kk_string_dup(_s6337); /*string*/
    kk_string_t _x6338;
    kk_integer_t _x6339 = kk_integer_dup(ind0); /*int*/
    _x6338 = kk_std_core_show(_x6339, _ctx); /*string*/
    message_205 = kk_std_core__lp__plus__plus__1_rp_(_x6336, _x6338, _ctx); /*string*/
    kk_std_core__exception exn_21561;
    kk_std_core__exception_info _x6340;
    kk_std_core_types__optional _match_6249 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
    if (kk_std_core_types__is_Optional(_match_6249)) {
      kk_box_t _box_x5066 = _match_6249._cons.Optional.value;
      kk_std_core__exception_info _info_14279 = kk_std_core__exception_info_unbox(_box_x5066, NULL);
      kk_std_core__exception_info_dup(_info_14279);
      kk_std_core_types__optional_drop(_match_6249, _ctx);
      _x6340 = _info_14279; /*exception-info*/
      goto _match6341;
    }
    _x6340 = kk_std_core__new_ExnError(_ctx); /*exception-info*/
    _match6341: ;
    exn_21561 = kk_std_core__new_Exception(message_205, _x6340, _ctx); /*exception*/
    kk_std_core_hnd__ev ev_21562;
    size_t _x6343 = ((size_t)0); /*size_t*/
    ev_21562 = kk_evv_at(_x6343,kk_context()); /*std/core/hnd/ev<.hnd-exn>*/
    kk_box_t _x6344;
    struct kk_std_core_hnd_Ev* _con6345 = kk_std_core_hnd__as_Ev(ev_21562);
    kk_std_core_hnd__marker m = _con6345->marker;
    kk_box_t _box_x5067 = _con6345->hnd;
    kk_std_core__hnd_exn h = kk_std_core__hnd_exn_unbox(_box_x5067, NULL);
    kk_std_core__hnd_exn_dup(h);
    kk_std_core_hnd__clause1 _match_6248;
    struct kk_std_core__Hnd_exn* _con6347 = kk_std_core__as_Hnd_exn(h);
    kk_std_core_hnd__clause1 except_throw_exn = _con6347->except_throw_exn;
    if (kk_std_core__hnd_exn_is_unique(h)) {
      kk_std_core__hnd_exn_free(h);
    }
    else {
      kk_std_core_hnd__clause1_dup(except_throw_exn);
      kk_std_core__hnd_exn_decref(h, _ctx);
    }
    _match_6248 = except_throw_exn; /*forall<a> std/core/hnd/clause1<exception,a,.hnd-exn,7,8>*/
    kk_function_t _fun_unbox_x5071 = _match_6248.clause;
    _x6344 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x5071, (_fun_unbox_x5071, m, ev_21562, kk_std_core__exception_box(exn_21561, _ctx), _ctx)); /*11*/
    y = kk_std_core__list_unbox(_x6344, _ctx); /*list<effects-and-types/row_vector>*/
  }
  else {
    kk_box_t _box_x5075 = _match_6247._cons.Just.value;
    kk_std_core__list x = kk_std_core__list_unbox(_box_x5075, NULL);
    kk_std_core__list_dup(x);
    kk_std_core_types__maybe_drop(_match_6247, _ctx);
    y = x; /*list<effects-and-types/row_vector>*/
  }
  kk_unit_t __w_l717_c9 = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(y, _ctx);
    kk_box_t _x6349 = kk_std_core_hnd_yield_cont(kk_climate_dash_experiments__new_mlift4685_run__climate__model_fun6350(i_4721, _ctx), _ctx); /*3*/
    x_4718 = kk_std_core__list_unbox(_x6349, _ctx); /*list<effects-and-types/row_vector>*/
  }
  else {
    x_4718 = y; /*list<effects-and-types/row_vector>*/
  }
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_4718, _ctx);
    kk_box_t _x6351 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments__new_mlift4685_run__climate__model_fun6352(burnin, data, ind0, name0, t__steps, diff0, subtract0, _ctx), _ctx); /*2*/
    kk_unit_unbox(_x6351); return kk_Unit;
  }
  kk_climate_dash_experiments__mlift4684_run__climate__model(burnin, data, diff0, ind0, name0, subtract0, t__steps, x_4718, _ctx); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_climate_dash_experiments__mlift4686_run__climate__model_fun6365__t {
  struct kk_function_s _base;
};
static kk_box_t kk_climate_dash_experiments__mlift4686_run__climate__model_fun6365(kk_function_t _fself, kk_box_t _b_5100, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift4686_run__climate__model_fun6365(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_climate_dash_experiments__mlift4686_run__climate__model_fun6365, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_climate_dash_experiments__mlift4686_run__climate__model_fun6365(kk_function_t _fself, kk_box_t _b_5100, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_os_path__path _x6366;
  kk_string_t _x6367 = kk_string_unbox(_b_5100); /*string*/
  _x6366 = kk_std_os_path_path(_x6367, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x6366, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift4686_run__climate__model_fun6370__t {
  struct kk_function_s _base;
};
static kk_box_t kk_climate_dash_experiments__mlift4686_run__climate__model_fun6370(kk_function_t _fself, kk_box_t _b_5105, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift4686_run__climate__model_fun6370(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_climate_dash_experiments__mlift4686_run__climate__model_fun6370, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_climate_dash_experiments__mlift4686_run__climate__model_fun6370(kk_function_t _fself, kk_box_t _b_5105, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x6371;
  kk_std_core__list _x6372 = kk_std_core__list_unbox(_b_5105, _ctx); /*list<(list<double>, list<double>)>*/
  _x6371 = kk_output_dash_and_dash_plot_show__trace(_x6372, _ctx); /*string*/
  return kk_string_box(_x6371);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift4686_run__climate__model_fun6378__t {
  struct kk_function_s _base;
  size_t i_4726;
};
static kk_box_t kk_climate_dash_experiments__mlift4686_run__climate__model_fun6378(kk_function_t _fself, kk_function_t _b_5115, kk_box_t _b_5116, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift4686_run__climate__model_fun6378(size_t i_4726, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4686_run__climate__model_fun6378__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift4686_run__climate__model_fun6378__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift4686_run__climate__model_fun6378, kk_context());
  _self->i_4726 = i_4726;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift4686_run__climate__model_fun6378(kk_function_t _fself, kk_function_t _b_5115, kk_box_t _b_5116, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4686_run__climate__model_fun6378__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift4686_run__climate__model_fun6378__t*, _fself);
  size_t i_4726 = _self->i_4726; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_4726, _b_5115, _b_5116, _ctx);
}

kk_unit_t kk_climate_dash_experiments__mlift4686_run__climate__model(kk_string_t name, kk_std_core_types__tuple2_ _y_3, kk_context_t* _ctx) { /* (name : string, (list<(list<double>, list<double>)>, tmcmc/trace<list<double>,<effects-and-types/sample,effects-and-types/score,div,exn,fsys,console,ndet,std/num/random/random>>)) -> <effects-and-types/sample,div,exn,fsys,console,ndet,std/num/random/random> () */ 
  kk_string_t _x24;
  kk_string_t _x6355;
  kk_define_string_literal(, _s6356, 17, "./output-climate/")
  _x6355 = kk_string_dup(_s6356); /*string*/
  kk_string_t _x6357;
  kk_string_t _x6358;
  kk_string_t _x6359;
  kk_define_string_literal(, _s6360, 1, "/")
  _x6359 = kk_string_dup(_s6360); /*string*/
  kk_string_t _x6361;
  kk_define_string_literal(, _s6362, 17, "tmcmc_results.csv")
  _x6361 = kk_string_dup(_s6362); /*string*/
  _x6358 = kk_std_core__lp__plus__plus__1_rp_(_x6359, _x6361, _ctx); /*string*/
  _x6357 = kk_std_core__lp__plus__plus__1_rp_(name, _x6358, _ctx); /*string*/
  _x24 = kk_std_core__lp__plus__plus__1_rp_(_x6355, _x6357, _ctx); /*string*/
  size_t i_4726 = ((size_t)0); /*std/core/hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_4726,kk_context()); /*std/core/hnd/evv<<exn,fsys,div,effects-and-types/sample,console,ndet,std/num/random/random>>*/;
  kk_unit_t y = kk_Unit;
  kk_std_os_path__path _x6363;
  kk_box_t _x6364 = kk_std_core_hnd__open_none1(kk_climate_dash_experiments__new_mlift4686_run__climate__model_fun6365(_ctx), kk_string_box(_x24), _ctx); /*2*/
  _x6363 = kk_std_os_path__path_unbox(_x6364, _ctx); /*std/os/path/path*/
  kk_string_t _x6368;
  kk_box_t _x6369;
  kk_box_t _x6373;
  kk_std_core__list _x6374;
  kk_box_t _box_x5101 = _y_3.fst;
  kk_box_t _box_x5102 = _y_3.snd;
  kk_std_core__list _x = kk_std_core__list_unbox(_box_x5101, NULL);
  kk_std_core__list_dup(_x);
  kk_std_core_types__tuple2__drop(_y_3, _ctx);
  _x6374 = _x; /*list<(list<double>, list<double>)>*/
  _x6373 = kk_std_core__list_box(_x6374, _ctx); /*1*/
  _x6369 = kk_std_core_hnd__open_none1(kk_climate_dash_experiments__new_mlift4686_run__climate__model_fun6370(_ctx), _x6373, _ctx); /*2*/
  _x6368 = kk_string_unbox(_x6369); /*string*/
  kk_std_os_file_write_text_file(_x6363, _x6368, kk_std_core_types__new_None(_ctx), _ctx);
  kk_unit_t __w_l717_c9 = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x6377 = kk_std_core_hnd_yield_cont(kk_climate_dash_experiments__new_mlift4686_run__climate__model_fun6378(i_4726, _ctx), _ctx); /*3*/
    kk_unit_unbox(_x6377); return kk_Unit;
  }
  y; return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_climate_dash_experiments__mlift4687_run__climate__model_fun6397__t {
  struct kk_function_s _base;
  size_t i_4733;
};
static kk_box_t kk_climate_dash_experiments__mlift4687_run__climate__model_fun6397(kk_function_t _fself, kk_function_t _b_5145, kk_box_t _b_5146, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift4687_run__climate__model_fun6397(size_t i_4733, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4687_run__climate__model_fun6397__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift4687_run__climate__model_fun6397__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift4687_run__climate__model_fun6397, kk_context());
  _self->i_4733 = i_4733;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift4687_run__climate__model_fun6397(kk_function_t _fself, kk_function_t _b_5145, kk_box_t _b_5146, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4687_run__climate__model_fun6397__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift4687_run__climate__model_fun6397__t*, _fself);
  size_t i_4733 = _self->i_4733; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_4733, _b_5145, _b_5146, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift4687_run__climate__model_fun6415__t {
  struct kk_function_s _base;
  size_t i0_4738;
};
static kk_box_t kk_climate_dash_experiments__mlift4687_run__climate__model_fun6415(kk_function_t _fself, kk_function_t _b_5175, kk_box_t _b_5176, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift4687_run__climate__model_fun6415(size_t i0_4738, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4687_run__climate__model_fun6415__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift4687_run__climate__model_fun6415__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift4687_run__climate__model_fun6415, kk_context());
  _self->i0_4738 = i0_4738;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift4687_run__climate__model_fun6415(kk_function_t _fself, kk_function_t _b_5175, kk_box_t _b_5176, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4687_run__climate__model_fun6415__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift4687_run__climate__model_fun6415__t*, _fself);
  size_t i0_4738 = _self->i0_4738; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i0_4738, _b_5175, _b_5176, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift4687_run__climate__model_fun6416__t {
  struct kk_function_s _base;
  kk_function_t _x02_4661;
};
static kk_std_core__list kk_climate_dash_experiments__mlift4687_run__climate__model_fun6416(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift4687_run__climate__model_fun6416(kk_function_t _x02_4661, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4687_run__climate__model_fun6416__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift4687_run__climate__model_fun6416__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift4687_run__climate__model_fun6416, kk_context());
  _self->_x02_4661 = _x02_4661;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift4687_run__climate__model_fun6419__t {
  struct kk_function_s _base;
  kk_function_t _x02_4661;
};
static kk_box_t kk_climate_dash_experiments__mlift4687_run__climate__model_fun6419(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift4687_run__climate__model_fun6419(kk_function_t _x02_4661, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4687_run__climate__model_fun6419__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift4687_run__climate__model_fun6419__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift4687_run__climate__model_fun6419, kk_context());
  _self->_x02_4661 = _x02_4661;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift4687_run__climate__model_fun6419(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4687_run__climate__model_fun6419__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift4687_run__climate__model_fun6419__t*, _fself);
  kk_function_t _x02_4661 = _self->_x02_4661; /* effects-and-types/model<list<double>,exn> */
  kk_drop_match(_self, {kk_function_dup(_x02_4661);}, {}, _ctx)
  kk_std_core__list _x6420 = kk_function_call(kk_std_core__list, (kk_function_t, kk_context_t*), _x02_4661, (_x02_4661, _ctx)); /*list<double>*/
  return kk_std_core__list_box(_x6420, _ctx);
}
static kk_std_core__list kk_climate_dash_experiments__mlift4687_run__climate__model_fun6416(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4687_run__climate__model_fun6416__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift4687_run__climate__model_fun6416__t*, _fself);
  kk_function_t _x02_4661 = _self->_x02_4661; /* effects-and-types/model<list<double>,exn> */
  kk_drop_match(_self, {kk_function_dup(_x02_4661);}, {}, _ctx)
  kk_vector_t _b_5201_5191;
  kk_std_core__list _x6417;
  size_t _b_5203_5189 = ((size_t)0); /*std/core/hnd/ev-index*/;
  kk_std_core__list _b_5204_5190;
  size_t _b_5205_5187 = ((size_t)2); /*std/core/hnd/ev-index*/;
  kk_std_core__list _b_5206_5188;
  size_t _b_5207_5185 = ((size_t)3); /*std/core/hnd/ev-index*/;
  _b_5206_5188 = kk_std_core__new_Cons(kk_reuse_null, kk_size_box(_b_5207_5185, _ctx), kk_std_core__new_Nil(_ctx), _ctx); /*list<std/core/hnd/ev-index>*/
  _b_5204_5190 = kk_std_core__new_Cons(kk_reuse_null, kk_size_box(_b_5205_5187, _ctx), _b_5206_5188, _ctx); /*list<std/core/hnd/ev-index>*/
  _x6417 = kk_std_core__new_Cons(kk_reuse_null, kk_size_box(_b_5203_5189, _ctx), _b_5204_5190, _ctx); /*list<0>*/
  _b_5201_5191 = kk_std_core_unvlist(_x6417, _ctx); /*vector<std/core/hnd/ev-index>*/
  kk_box_t _x6418 = kk_std_core_hnd__open0(_b_5201_5191, kk_climate_dash_experiments__new_mlift4687_run__climate__model_fun6419(_x02_4661, _ctx), _ctx); /*1*/
  return kk_std_core__list_unbox(_x6418, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift4687_run__climate__model_fun6421__t {
  struct kk_function_s _base;
  kk_function_t _b_5197_5193;
};
static kk_box_t kk_climate_dash_experiments__mlift4687_run__climate__model_fun6421(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift4687_run__climate__model_fun6421(kk_function_t _b_5197_5193, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4687_run__climate__model_fun6421__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift4687_run__climate__model_fun6421__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift4687_run__climate__model_fun6421, kk_context());
  _self->_b_5197_5193 = _b_5197_5193;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift4687_run__climate__model_fun6421(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4687_run__climate__model_fun6421__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift4687_run__climate__model_fun6421__t*, _fself);
  kk_function_t _b_5197_5193 = _self->_b_5197_5193; /* () -> <effects-and-types/sample,effects-and-types/score,exn> list<double> */
  kk_drop_match(_self, {kk_function_dup(_b_5197_5193);}, {}, _ctx)
  kk_std_core__list _x6422 = kk_function_call(kk_std_core__list, (kk_function_t, kk_context_t*), _b_5197_5193, (_b_5197_5193, _ctx)); /*list<double>*/
  return kk_std_core__list_box(_x6422, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift4687_run__climate__model_fun6424__t {
  struct kk_function_s _base;
  kk_string_t name;
};
static kk_box_t kk_climate_dash_experiments__mlift4687_run__climate__model_fun6424(kk_function_t _fself, kk_box_t _b_5210, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift4687_run__climate__model_fun6424(kk_string_t name, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4687_run__climate__model_fun6424__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift4687_run__climate__model_fun6424__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift4687_run__climate__model_fun6424, kk_context());
  _self->name = name;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift4687_run__climate__model_fun6424(kk_function_t _fself, kk_box_t _b_5210, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4687_run__climate__model_fun6424__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift4687_run__climate__model_fun6424__t*, _fself);
  kk_string_t name = _self->name; /* string */
  kk_drop_match(_self, {kk_string_dup(name);}, {}, _ctx)
  kk_unit_t _x6425 = kk_Unit;
  kk_std_core_types__tuple2_ _x6426 = kk_std_core_types__tuple2__unbox(_b_5210, _ctx); /*(list<(list<double>, list<double>)>, tmcmc/trace<list<double>,<effects-and-types/sample,effects-and-types/score,div,exn,fsys,console,ndet,std/num/random/random>>)*/
  kk_climate_dash_experiments__mlift4686_run__climate__model(name, _x6426, _ctx);
  return kk_unit_box(_x6425);
}

kk_unit_t kk_climate_dash_experiments__mlift4687_run__climate__model(kk_integer_t burnin, kk_std_core_types__tuple2_ data, double diff, kk_integer_t ind, kk_string_t name, double subtract, kk_integer_t t__steps, kk_std_core__list _y_2, kk_context_t* _ctx) { /* (burnin : int, data : (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>), diff : double, ind : int, name : string, subtract : double, t_steps : int, list<effects-and-types/row_vector>) -> <exn,div,effects-and-types/sample,fsys,console,ndet,std/num/random/random> () */ 
  kk_std_core__list_drop(_y_2, _ctx);
  kk_std_core_types__tuple2_ x_4730;
  kk_function_t _b_5197_5193;
  kk_function_t _x02_4661;
  kk_std_core__list _x11;
  size_t i_4733 = ((size_t)0); /*std/core/hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_4733,kk_context()); /*std/core/hnd/evv<<exn,div,effects-and-types/sample,fsys,console,ndet,std/num/random/random>>*/;
  kk_std_core__list y;
  kk_std_core_types__maybe _match_6241;
  kk_std_core__list _x6379;
  kk_box_t _box_x5125 = data.fst;
  kk_box_t _box_x5126 = data.snd;
  kk_std_core__list _x = kk_std_core__list_unbox(_box_x5126, NULL);
  kk_std_core__list_dup(_x);
  _x6379 = _x; /*list<list<effects-and-types/row_vector>>*/
  kk_integer_t _x6382 = kk_integer_dup(ind); /*int*/
  _match_6241 = kk_std_core__lp__lb__rb__2_rp_(_x6379, _x6382, _ctx); /*maybe<1>*/
  if (kk_std_core_types__is_Nothing(_match_6241)) {
    kk_string_t message_205;
    kk_string_t _x6383;
    kk_define_string_literal(, _s6384, 48, "ListIndexError: Invalid list indexing at index: ")
    _x6383 = kk_string_dup(_s6384); /*string*/
    kk_string_t _x6385;
    kk_integer_t _x6386 = kk_integer_dup(ind); /*int*/
    _x6385 = kk_std_core_show(_x6386, _ctx); /*string*/
    message_205 = kk_std_core__lp__plus__plus__1_rp_(_x6383, _x6385, _ctx); /*string*/
    kk_std_core__exception exn_21561;
    kk_std_core__exception_info _x6387;
    kk_std_core_types__optional _match_6243 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
    if (kk_std_core_types__is_Optional(_match_6243)) {
      kk_box_t _box_x5127 = _match_6243._cons.Optional.value;
      kk_std_core__exception_info _info_14279 = kk_std_core__exception_info_unbox(_box_x5127, NULL);
      kk_std_core__exception_info_dup(_info_14279);
      kk_std_core_types__optional_drop(_match_6243, _ctx);
      _x6387 = _info_14279; /*exception-info*/
      goto _match6388;
    }
    _x6387 = kk_std_core__new_ExnError(_ctx); /*exception-info*/
    _match6388: ;
    exn_21561 = kk_std_core__new_Exception(message_205, _x6387, _ctx); /*exception*/
    kk_std_core_hnd__ev ev_21562;
    size_t _x6390 = ((size_t)0); /*size_t*/
    ev_21562 = kk_evv_at(_x6390,kk_context()); /*std/core/hnd/ev<.hnd-exn>*/
    kk_box_t _x6391;
    struct kk_std_core_hnd_Ev* _con6392 = kk_std_core_hnd__as_Ev(ev_21562);
    kk_std_core_hnd__marker m = _con6392->marker;
    kk_box_t _box_x5128 = _con6392->hnd;
    kk_std_core__hnd_exn h = kk_std_core__hnd_exn_unbox(_box_x5128, NULL);
    kk_std_core__hnd_exn_dup(h);
    kk_std_core_hnd__clause1 _match_6242;
    struct kk_std_core__Hnd_exn* _con6394 = kk_std_core__as_Hnd_exn(h);
    kk_std_core_hnd__clause1 except_throw_exn = _con6394->except_throw_exn;
    if (kk_std_core__hnd_exn_is_unique(h)) {
      kk_std_core__hnd_exn_free(h);
    }
    else {
      kk_std_core_hnd__clause1_dup(except_throw_exn);
      kk_std_core__hnd_exn_decref(h, _ctx);
    }
    _match_6242 = except_throw_exn; /*forall<a> std/core/hnd/clause1<exception,a,.hnd-exn,7,8>*/
    kk_function_t _fun_unbox_x5132 = _match_6242.clause;
    _x6391 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x5132, (_fun_unbox_x5132, m, ev_21562, kk_std_core__exception_box(exn_21561, _ctx), _ctx)); /*11*/
    y = kk_std_core__list_unbox(_x6391, _ctx); /*list<effects-and-types/row_vector>*/
  }
  else {
    kk_box_t _box_x5136 = _match_6241._cons.Just.value;
    kk_std_core__list x = kk_std_core__list_unbox(_box_x5136, NULL);
    kk_std_core__list_dup(x);
    kk_std_core_types__maybe_drop(_match_6241, _ctx);
    y = x; /*list<effects-and-types/row_vector>*/
  }
  kk_unit_t __w_l717_c9 = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(y, _ctx);
    kk_box_t _x6396 = kk_std_core_hnd_yield_cont(kk_climate_dash_experiments__new_mlift4687_run__climate__model_fun6397(i_4733, _ctx), _ctx); /*3*/
    _x11 = kk_std_core__list_unbox(_x6396, _ctx); /*list<effects-and-types/row_vector>*/
  }
  else {
    _x11 = y; /*list<effects-and-types/row_vector>*/
  }
  kk_std_core__list _x21;
  size_t i0_4738 = ((size_t)0); /*std/core/hnd/ev-index*/;
  kk_evv_t w0 = kk_evv_swap_create1(i0_4738,kk_context()); /*std/core/hnd/evv<<exn,div,effects-and-types/sample,fsys,console,ndet,std/num/random/random>>*/;
  kk_std_core__list y0;
  kk_std_core_types__maybe _match_6237;
  kk_std_core__list _x6398;
  kk_box_t _box_x5155 = data.fst;
  kk_box_t _box_x5156 = data.snd;
  kk_std_core__list _x0 = kk_std_core__list_unbox(_box_x5155, NULL);
  kk_std_core__list_dup(_x0);
  kk_std_core_types__tuple2__drop(data, _ctx);
  _x6398 = _x0; /*list<list<effects-and-types/row_vector>>*/
  kk_integer_t _x6401 = kk_integer_dup(ind); /*int*/
  _match_6237 = kk_std_core__lp__lb__rb__2_rp_(_x6398, _x6401, _ctx); /*maybe<1>*/
  if (kk_std_core_types__is_Nothing(_match_6237)) {
    kk_string_t message_2050;
    kk_string_t _x6402;
    kk_define_string_literal(, _s6403, 48, "ListIndexError: Invalid list indexing at index: ")
    _x6402 = kk_string_dup(_s6403); /*string*/
    kk_string_t _x6404 = kk_std_core_show(ind, _ctx); /*string*/
    message_2050 = kk_std_core__lp__plus__plus__1_rp_(_x6402, _x6404, _ctx); /*string*/
    kk_std_core__exception exn_215610;
    kk_std_core__exception_info _x6405;
    kk_std_core_types__optional _match_6239 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
    if (kk_std_core_types__is_Optional(_match_6239)) {
      kk_box_t _box_x5157 = _match_6239._cons.Optional.value;
      kk_std_core__exception_info _info_142790 = kk_std_core__exception_info_unbox(_box_x5157, NULL);
      kk_std_core__exception_info_dup(_info_142790);
      kk_std_core_types__optional_drop(_match_6239, _ctx);
      _x6405 = _info_142790; /*exception-info*/
      goto _match6406;
    }
    _x6405 = kk_std_core__new_ExnError(_ctx); /*exception-info*/
    _match6406: ;
    exn_215610 = kk_std_core__new_Exception(message_2050, _x6405, _ctx); /*exception*/
    kk_std_core_hnd__ev ev_215620;
    size_t _x6408 = ((size_t)0); /*size_t*/
    ev_215620 = kk_evv_at(_x6408,kk_context()); /*std/core/hnd/ev<.hnd-exn>*/
    kk_box_t _x6409;
    struct kk_std_core_hnd_Ev* _con6410 = kk_std_core_hnd__as_Ev(ev_215620);
    kk_std_core_hnd__marker m0 = _con6410->marker;
    kk_box_t _box_x5158 = _con6410->hnd;
    kk_std_core__hnd_exn h0 = kk_std_core__hnd_exn_unbox(_box_x5158, NULL);
    kk_std_core__hnd_exn_dup(h0);
    kk_std_core_hnd__clause1 _match_6238;
    struct kk_std_core__Hnd_exn* _con6412 = kk_std_core__as_Hnd_exn(h0);
    kk_std_core_hnd__clause1 except_throw_exn0 = _con6412->except_throw_exn;
    if (kk_std_core__hnd_exn_is_unique(h0)) {
      kk_std_core__hnd_exn_free(h0);
    }
    else {
      kk_std_core_hnd__clause1_dup(except_throw_exn0);
      kk_std_core__hnd_exn_decref(h0, _ctx);
    }
    _match_6238 = except_throw_exn0; /*forall<a> std/core/hnd/clause1<exception,a,.hnd-exn,7,8>*/
    kk_function_t _fun_unbox_x5162 = _match_6238.clause;
    _x6409 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x5162, (_fun_unbox_x5162, m0, ev_215620, kk_std_core__exception_box(exn_215610, _ctx), _ctx)); /*11*/
    y0 = kk_std_core__list_unbox(_x6409, _ctx); /*list<effects-and-types/row_vector>*/
  }
  else {
    kk_box_t _box_x5166 = _match_6237._cons.Just.value;
    kk_std_core__list x0 = kk_std_core__list_unbox(_box_x5166, NULL);
    kk_integer_drop(ind, _ctx);
    kk_std_core__list_dup(x0);
    kk_std_core_types__maybe_drop(_match_6237, _ctx);
    y0 = x0; /*list<effects-and-types/row_vector>*/
  }
  kk_unit_t __w_l717_c90 = kk_Unit;
  kk_evv_set(w0,kk_context());
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(y0, _ctx);
    kk_box_t _x6414 = kk_std_core_hnd_yield_cont(kk_climate_dash_experiments__new_mlift4687_run__climate__model_fun6415(i0_4738, _ctx), _ctx); /*3*/
    _x21 = kk_std_core__list_unbox(_x6414, _ctx); /*list<effects-and-types/row_vector>*/
  }
  else {
    _x21 = y0; /*list<effects-and-types/row_vector>*/
  }
  kk_evv_t w1 = kk_evv_swap_create0(kk_context()); /*std/core/hnd/evv<(<>)>*/;
  kk_function_t x00 = kk_climate_dash_change_linear__gaussian__climate__data(_x11, _x21, false, diff, subtract, 0x1.2cccccccccccdp2, _ctx); /*effects-and-types/model<list<double>,exn>*/;
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w1,kk_context());
  _x02_4661 = x00; /*effects-and-types/model<list<double>,exn>*/
  _b_5197_5193 = kk_climate_dash_experiments__new_mlift4687_run__climate__model_fun6416(_x02_4661, _ctx); /*() -> <effects-and-types/sample,effects-and-types/score,exn> list<double>*/
  kk_effects_dash_and_dash_types__exp _b_5199_5195 = kk_effects_dash_and_dash_types__new_Exp(0x0p+0, _ctx); /*effects-and-types/exp*/;
  x_4730 = kk_tmcmc_tmcmc(kk_climate_dash_experiments__new_mlift4687_run__climate__model_fun6421(_b_5197_5193, _ctx), t__steps, _b_5199_5195, burnin, _ctx); /*(list<(list<double>, list<double>)>, tmcmc/trace<list<double>,<effects-and-types/sample,effects-and-types/score,div,exn,fsys,console,ndet,std/num/random/random>>)*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__tuple2__drop(x_4730, _ctx);
    kk_box_t _x6423 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments__new_mlift4687_run__climate__model_fun6424(name, _ctx), _ctx); /*2*/
    kk_unit_unbox(_x6423); return kk_Unit;
  }
  kk_climate_dash_experiments__mlift4686_run__climate__model(name, x_4730, _ctx); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_climate_dash_experiments__mlift4688_run__climate__model_fun6445__t {
  struct kk_function_s _base;
  size_t i_4746;
};
static kk_box_t kk_climate_dash_experiments__mlift4688_run__climate__model_fun6445(kk_function_t _fself, kk_function_t _b_5233, kk_box_t _b_5234, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift4688_run__climate__model_fun6445(size_t i_4746, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4688_run__climate__model_fun6445__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift4688_run__climate__model_fun6445__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift4688_run__climate__model_fun6445, kk_context());
  _self->i_4746 = i_4746;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift4688_run__climate__model_fun6445(kk_function_t _fself, kk_function_t _b_5233, kk_box_t _b_5234, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4688_run__climate__model_fun6445__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift4688_run__climate__model_fun6445__t*, _fself);
  size_t i_4746 = _self->i_4746; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_4746, _b_5233, _b_5234, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift4688_run__climate__model_fun6447__t {
  struct kk_function_s _base;
  kk_integer_t burnin;
  kk_std_core_types__tuple2_ data;
  kk_integer_t ind;
  kk_string_t name;
  kk_integer_t t__steps;
  double diff;
  double subtract;
};
static kk_box_t kk_climate_dash_experiments__mlift4688_run__climate__model_fun6447(kk_function_t _fself, kk_box_t _b_5244, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift4688_run__climate__model_fun6447(kk_integer_t burnin, kk_std_core_types__tuple2_ data, kk_integer_t ind, kk_string_t name, kk_integer_t t__steps, double diff, double subtract, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4688_run__climate__model_fun6447__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift4688_run__climate__model_fun6447__t, 7, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift4688_run__climate__model_fun6447, kk_context());
  _self->burnin = burnin;
  _self->data = data;
  _self->ind = ind;
  _self->name = name;
  _self->t__steps = t__steps;
  _self->diff = diff;
  _self->subtract = subtract;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift4688_run__climate__model_fun6447(kk_function_t _fself, kk_box_t _b_5244, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4688_run__climate__model_fun6447__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift4688_run__climate__model_fun6447__t*, _fself);
  kk_integer_t burnin = _self->burnin; /* int */
  kk_std_core_types__tuple2_ data = _self->data; /* (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>) */
  kk_integer_t ind = _self->ind; /* int */
  kk_string_t name = _self->name; /* string */
  kk_integer_t t__steps = _self->t__steps; /* int */
  double diff = _self->diff; /* double */
  double subtract = _self->subtract; /* double */
  kk_drop_match(_self, {kk_integer_dup(burnin);kk_std_core_types__tuple2__dup(data);kk_integer_dup(ind);kk_string_dup(name);kk_integer_dup(t__steps);;;}, {}, _ctx)
  kk_unit_t _x6448 = kk_Unit;
  kk_std_core__list _x6449 = kk_std_core__list_unbox(_b_5244, _ctx); /*list<effects-and-types/row_vector>*/
  kk_climate_dash_experiments__mlift4687_run__climate__model(burnin, data, diff, ind, name, subtract, t__steps, _x6449, _ctx);
  return kk_unit_box(_x6448);
}

kk_unit_t kk_climate_dash_experiments__mlift4688_run__climate__model(kk_integer_t burnin, kk_std_core_types__tuple2_ data, double diff, kk_integer_t ind, kk_string_t name, double subtract, kk_integer_t t__steps, kk_std_core__list _y_1, kk_context_t* _ctx) { /* (burnin : int, data : (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>), diff : double, ind : int, name : string, subtract : double, t_steps : int, list<effects-and-types/row_vector>) -> <exn,div,effects-and-types/sample,fsys,console,ndet,std/num/random/random> () */ 
  kk_std_core__list_drop(_y_1, _ctx);
  kk_std_core__list x_4743;
  size_t i_4746 = ((size_t)0); /*std/core/hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_4746,kk_context()); /*std/core/hnd/evv<<exn,div,effects-and-types/sample,fsys,console,ndet,std/num/random/random>>*/;
  kk_std_core__list y;
  kk_std_core_types__maybe _match_6232;
  kk_std_core__list _x6427;
  kk_box_t _box_x5213 = data.fst;
  kk_box_t _box_x5214 = data.snd;
  kk_std_core__list _x = kk_std_core__list_unbox(_box_x5213, NULL);
  kk_std_core__list_dup(_x);
  _x6427 = _x; /*list<list<effects-and-types/row_vector>>*/
  kk_integer_t _x6430 = kk_integer_dup(ind); /*int*/
  _match_6232 = kk_std_core__lp__lb__rb__2_rp_(_x6427, _x6430, _ctx); /*maybe<1>*/
  if (kk_std_core_types__is_Nothing(_match_6232)) {
    kk_string_t message_205;
    kk_string_t _x6431;
    kk_define_string_literal(, _s6432, 48, "ListIndexError: Invalid list indexing at index: ")
    _x6431 = kk_string_dup(_s6432); /*string*/
    kk_string_t _x6433;
    kk_integer_t _x6434 = kk_integer_dup(ind); /*int*/
    _x6433 = kk_std_core_show(_x6434, _ctx); /*string*/
    message_205 = kk_std_core__lp__plus__plus__1_rp_(_x6431, _x6433, _ctx); /*string*/
    kk_std_core__exception exn_21561;
    kk_std_core__exception_info _x6435;
    kk_std_core_types__optional _match_6234 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
    if (kk_std_core_types__is_Optional(_match_6234)) {
      kk_box_t _box_x5215 = _match_6234._cons.Optional.value;
      kk_std_core__exception_info _info_14279 = kk_std_core__exception_info_unbox(_box_x5215, NULL);
      kk_std_core__exception_info_dup(_info_14279);
      kk_std_core_types__optional_drop(_match_6234, _ctx);
      _x6435 = _info_14279; /*exception-info*/
      goto _match6436;
    }
    _x6435 = kk_std_core__new_ExnError(_ctx); /*exception-info*/
    _match6436: ;
    exn_21561 = kk_std_core__new_Exception(message_205, _x6435, _ctx); /*exception*/
    kk_std_core_hnd__ev ev_21562;
    size_t _x6438 = ((size_t)0); /*size_t*/
    ev_21562 = kk_evv_at(_x6438,kk_context()); /*std/core/hnd/ev<.hnd-exn>*/
    kk_box_t _x6439;
    struct kk_std_core_hnd_Ev* _con6440 = kk_std_core_hnd__as_Ev(ev_21562);
    kk_std_core_hnd__marker m = _con6440->marker;
    kk_box_t _box_x5216 = _con6440->hnd;
    kk_std_core__hnd_exn h = kk_std_core__hnd_exn_unbox(_box_x5216, NULL);
    kk_std_core__hnd_exn_dup(h);
    kk_std_core_hnd__clause1 _match_6233;
    struct kk_std_core__Hnd_exn* _con6442 = kk_std_core__as_Hnd_exn(h);
    kk_std_core_hnd__clause1 except_throw_exn = _con6442->except_throw_exn;
    if (kk_std_core__hnd_exn_is_unique(h)) {
      kk_std_core__hnd_exn_free(h);
    }
    else {
      kk_std_core_hnd__clause1_dup(except_throw_exn);
      kk_std_core__hnd_exn_decref(h, _ctx);
    }
    _match_6233 = except_throw_exn; /*forall<a> std/core/hnd/clause1<exception,a,.hnd-exn,7,8>*/
    kk_function_t _fun_unbox_x5220 = _match_6233.clause;
    _x6439 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x5220, (_fun_unbox_x5220, m, ev_21562, kk_std_core__exception_box(exn_21561, _ctx), _ctx)); /*11*/
    y = kk_std_core__list_unbox(_x6439, _ctx); /*list<effects-and-types/row_vector>*/
  }
  else {
    kk_box_t _box_x5224 = _match_6232._cons.Just.value;
    kk_std_core__list x = kk_std_core__list_unbox(_box_x5224, NULL);
    kk_std_core__list_dup(x);
    kk_std_core_types__maybe_drop(_match_6232, _ctx);
    y = x; /*list<effects-and-types/row_vector>*/
  }
  kk_unit_t __w_l717_c9 = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(y, _ctx);
    kk_box_t _x6444 = kk_std_core_hnd_yield_cont(kk_climate_dash_experiments__new_mlift4688_run__climate__model_fun6445(i_4746, _ctx), _ctx); /*3*/
    x_4743 = kk_std_core__list_unbox(_x6444, _ctx); /*list<effects-and-types/row_vector>*/
  }
  else {
    x_4743 = y; /*list<effects-and-types/row_vector>*/
  }
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_4743, _ctx);
    kk_box_t _x6446 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments__new_mlift4688_run__climate__model_fun6447(burnin, data, ind, name, t__steps, diff, subtract, _ctx), _ctx); /*2*/
    kk_unit_unbox(_x6446); return kk_Unit;
  }
  kk_climate_dash_experiments__mlift4687_run__climate__model(burnin, data, diff, ind, name, subtract, t__steps, x_4743, _ctx); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_climate_dash_experiments__mlift4689_run__climate__model_fun6453__t {
  struct kk_function_s _base;
  kk_integer_t burnin;
  kk_std_core_types__tuple2_ data;
  kk_std_core__list pre__data;
  kk_integer_t t__steps;
};
static kk_box_t kk_climate_dash_experiments__mlift4689_run__climate__model_fun6453(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift4689_run__climate__model_fun6453(kk_integer_t burnin, kk_std_core_types__tuple2_ data, kk_std_core__list pre__data, kk_integer_t t__steps, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4689_run__climate__model_fun6453__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift4689_run__climate__model_fun6453__t, 6, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift4689_run__climate__model_fun6453, kk_context());
  _self->burnin = burnin;
  _self->data = data;
  _self->pre__data = pre__data;
  _self->t__steps = t__steps;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift4689_run__climate__model_fun6454__t {
  struct kk_function_s _base;
  kk_integer_t burnin;
  kk_std_core_types__tuple2_ data;
  kk_std_core__list pre__data;
  kk_integer_t t__steps;
};
static kk_box_t kk_climate_dash_experiments__mlift4689_run__climate__model_fun6454(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift4689_run__climate__model_fun6454(kk_integer_t burnin, kk_std_core_types__tuple2_ data, kk_std_core__list pre__data, kk_integer_t t__steps, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4689_run__climate__model_fun6454__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift4689_run__climate__model_fun6454__t, 6, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift4689_run__climate__model_fun6454, kk_context());
  _self->burnin = burnin;
  _self->data = data;
  _self->pre__data = pre__data;
  _self->t__steps = t__steps;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift4689_run__climate__model_fun6457__t {
  struct kk_function_s _base;
  kk_integer_t burnin;
  kk_std_core_types__tuple2_ data;
  kk_integer_t t__steps;
};
static kk_box_t kk_climate_dash_experiments__mlift4689_run__climate__model_fun6457(kk_function_t _fself, kk_box_t _b_5288, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift4689_run__climate__model_fun6457(kk_integer_t burnin, kk_std_core_types__tuple2_ data, kk_integer_t t__steps, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4689_run__climate__model_fun6457__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift4689_run__climate__model_fun6457__t, 5, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift4689_run__climate__model_fun6457, kk_context());
  _self->burnin = burnin;
  _self->data = data;
  _self->t__steps = t__steps;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift4689_run__climate__model_fun6463__t {
  struct kk_function_s _base;
  kk_integer_t burnin;
  kk_std_core_types__tuple2_ data;
  kk_integer_t ind0;
  kk_string_t name0;
  kk_integer_t t__steps;
  double diff0;
  double subtract0;
};
static kk_box_t kk_climate_dash_experiments__mlift4689_run__climate__model_fun6463(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift4689_run__climate__model_fun6463(kk_integer_t burnin, kk_std_core_types__tuple2_ data, kk_integer_t ind0, kk_string_t name0, kk_integer_t t__steps, double diff0, double subtract0, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4689_run__climate__model_fun6463__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift4689_run__climate__model_fun6463__t, 7, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift4689_run__climate__model_fun6463, kk_context());
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
struct kk_climate_dash_experiments__mlift4689_run__climate__model_fun6483__t {
  struct kk_function_s _base;
  size_t i_4756;
};
static kk_box_t kk_climate_dash_experiments__mlift4689_run__climate__model_fun6483(kk_function_t _fself, kk_function_t _b_5272, kk_box_t _b_5273, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift4689_run__climate__model_fun6483(size_t i_4756, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4689_run__climate__model_fun6483__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift4689_run__climate__model_fun6483__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift4689_run__climate__model_fun6483, kk_context());
  _self->i_4756 = i_4756;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift4689_run__climate__model_fun6483(kk_function_t _fself, kk_function_t _b_5272, kk_box_t _b_5273, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4689_run__climate__model_fun6483__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift4689_run__climate__model_fun6483__t*, _fself);
  size_t i_4756 = _self->i_4756; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_4756, _b_5272, _b_5273, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift4689_run__climate__model_fun6485__t {
  struct kk_function_s _base;
  kk_integer_t burnin;
  kk_std_core_types__tuple2_ data;
  kk_integer_t ind0;
  kk_string_t name0;
  kk_integer_t t__steps;
  double diff0;
  double subtract0;
};
static kk_box_t kk_climate_dash_experiments__mlift4689_run__climate__model_fun6485(kk_function_t _fself, kk_box_t _b_5283, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift4689_run__climate__model_fun6485(kk_integer_t burnin, kk_std_core_types__tuple2_ data, kk_integer_t ind0, kk_string_t name0, kk_integer_t t__steps, double diff0, double subtract0, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4689_run__climate__model_fun6485__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift4689_run__climate__model_fun6485__t, 7, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift4689_run__climate__model_fun6485, kk_context());
  _self->burnin = burnin;
  _self->data = data;
  _self->ind0 = ind0;
  _self->name0 = name0;
  _self->t__steps = t__steps;
  _self->diff0 = diff0;
  _self->subtract0 = subtract0;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift4689_run__climate__model_fun6485(kk_function_t _fself, kk_box_t _b_5283, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4689_run__climate__model_fun6485__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift4689_run__climate__model_fun6485__t*, _fself);
  kk_integer_t burnin = _self->burnin; /* int */
  kk_std_core_types__tuple2_ data = _self->data; /* (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>) */
  kk_integer_t ind0 = _self->ind0; /* int */
  kk_string_t name0 = _self->name0; /* string */
  kk_integer_t t__steps = _self->t__steps; /* int */
  double diff0 = _self->diff0; /* double */
  double subtract0 = _self->subtract0; /* double */
  kk_drop_match(_self, {kk_integer_dup(burnin);kk_std_core_types__tuple2__dup(data);kk_integer_dup(ind0);kk_string_dup(name0);kk_integer_dup(t__steps);;;}, {}, _ctx)
  kk_unit_t _x6486 = kk_Unit;
  kk_std_core__list _x6487 = kk_std_core__list_unbox(_b_5283, _ctx); /*list<effects-and-types/row_vector>*/
  kk_climate_dash_experiments__mlift4685_run__climate__model(burnin, data, diff0, ind0, name0, subtract0, t__steps, _x6487, _ctx);
  return kk_unit_box(_x6486);
}
static kk_box_t kk_climate_dash_experiments__mlift4689_run__climate__model_fun6463(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4689_run__climate__model_fun6463__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift4689_run__climate__model_fun6463__t*, _fself);
  kk_integer_t burnin = _self->burnin; /* int */
  kk_std_core_types__tuple2_ data = _self->data; /* (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>) */
  kk_integer_t ind0 = _self->ind0; /* int */
  kk_string_t name0 = _self->name0; /* string */
  kk_integer_t t__steps = _self->t__steps; /* int */
  double diff0 = _self->diff0; /* double */
  double subtract0 = _self->subtract0; /* double */
  kk_drop_match(_self, {kk_integer_dup(burnin);kk_std_core_types__tuple2__dup(data);kk_integer_dup(ind0);kk_string_dup(name0);kk_integer_dup(t__steps);;;}, {}, _ctx)
  kk_unit_t _x6464 = kk_Unit;
  kk_std_core__list x_4753;
  size_t i_4756 = ((size_t)0); /*std/core/hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_4756,kk_context()); /*std/core/hnd/evv<<exn,div,effects-and-types/sample,fsys,console,ndet,std/num/random/random>>*/;
  kk_std_core__list y;
  kk_std_core_types__maybe _match_6227;
  kk_std_core__list _x6465;
  kk_box_t _box_x5252 = data.fst;
  kk_box_t _box_x5253 = data.snd;
  kk_std_core__list _x = kk_std_core__list_unbox(_box_x5253, NULL);
  kk_std_core__list_dup(_x);
  _x6465 = _x; /*list<list<effects-and-types/row_vector>>*/
  kk_integer_t _x6468 = kk_integer_dup(ind0); /*int*/
  _match_6227 = kk_std_core__lp__lb__rb__2_rp_(_x6465, _x6468, _ctx); /*maybe<1>*/
  if (kk_std_core_types__is_Nothing(_match_6227)) {
    kk_string_t message_205;
    kk_string_t _x6469;
    kk_define_string_literal(, _s6470, 48, "ListIndexError: Invalid list indexing at index: ")
    _x6469 = kk_string_dup(_s6470); /*string*/
    kk_string_t _x6471;
    kk_integer_t _x6472 = kk_integer_dup(ind0); /*int*/
    _x6471 = kk_std_core_show(_x6472, _ctx); /*string*/
    message_205 = kk_std_core__lp__plus__plus__1_rp_(_x6469, _x6471, _ctx); /*string*/
    kk_std_core__exception exn_21561;
    kk_std_core__exception_info _x6473;
    kk_std_core_types__optional _match_6229 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
    if (kk_std_core_types__is_Optional(_match_6229)) {
      kk_box_t _box_x5254 = _match_6229._cons.Optional.value;
      kk_std_core__exception_info _info_14279 = kk_std_core__exception_info_unbox(_box_x5254, NULL);
      kk_std_core__exception_info_dup(_info_14279);
      kk_std_core_types__optional_drop(_match_6229, _ctx);
      _x6473 = _info_14279; /*exception-info*/
      goto _match6474;
    }
    _x6473 = kk_std_core__new_ExnError(_ctx); /*exception-info*/
    _match6474: ;
    exn_21561 = kk_std_core__new_Exception(message_205, _x6473, _ctx); /*exception*/
    kk_std_core_hnd__ev ev_21562;
    size_t _x6476 = ((size_t)0); /*size_t*/
    ev_21562 = kk_evv_at(_x6476,kk_context()); /*std/core/hnd/ev<.hnd-exn>*/
    kk_box_t _x6477;
    struct kk_std_core_hnd_Ev* _con6478 = kk_std_core_hnd__as_Ev(ev_21562);
    kk_std_core_hnd__marker m = _con6478->marker;
    kk_box_t _box_x5255 = _con6478->hnd;
    kk_std_core__hnd_exn h = kk_std_core__hnd_exn_unbox(_box_x5255, NULL);
    kk_std_core__hnd_exn_dup(h);
    kk_std_core_hnd__clause1 _match_6228;
    struct kk_std_core__Hnd_exn* _con6480 = kk_std_core__as_Hnd_exn(h);
    kk_std_core_hnd__clause1 except_throw_exn = _con6480->except_throw_exn;
    if (kk_std_core__hnd_exn_is_unique(h)) {
      kk_std_core__hnd_exn_free(h);
    }
    else {
      kk_std_core_hnd__clause1_dup(except_throw_exn);
      kk_std_core__hnd_exn_decref(h, _ctx);
    }
    _match_6228 = except_throw_exn; /*forall<a> std/core/hnd/clause1<exception,a,.hnd-exn,7,8>*/
    kk_function_t _fun_unbox_x5259 = _match_6228.clause;
    _x6477 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x5259, (_fun_unbox_x5259, m, ev_21562, kk_std_core__exception_box(exn_21561, _ctx), _ctx)); /*11*/
    y = kk_std_core__list_unbox(_x6477, _ctx); /*list<effects-and-types/row_vector>*/
  }
  else {
    kk_box_t _box_x5263 = _match_6227._cons.Just.value;
    kk_std_core__list x = kk_std_core__list_unbox(_box_x5263, NULL);
    kk_std_core__list_dup(x);
    kk_std_core_types__maybe_drop(_match_6227, _ctx);
    y = x; /*list<effects-and-types/row_vector>*/
  }
  kk_unit_t __w_l717_c9 = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(y, _ctx);
    kk_box_t _x6482 = kk_std_core_hnd_yield_cont(kk_climate_dash_experiments__new_mlift4689_run__climate__model_fun6483(i_4756, _ctx), _ctx); /*3*/
    x_4753 = kk_std_core__list_unbox(_x6482, _ctx); /*list<effects-and-types/row_vector>*/
  }
  else {
    x_4753 = y; /*list<effects-and-types/row_vector>*/
  }
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_4753, _ctx);
    kk_box_t _x6484 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments__new_mlift4689_run__climate__model_fun6485(burnin, data, ind0, name0, t__steps, diff0, subtract0, _ctx), _ctx); /*2*/
    kk_unit_unbox(_x6484);
  }
  else {
    kk_climate_dash_experiments__mlift4685_run__climate__model(burnin, data, diff0, ind0, name0, subtract0, t__steps, x_4753, _ctx);
  }
  return kk_unit_box(_x6464);
}
static kk_box_t kk_climate_dash_experiments__mlift4689_run__climate__model_fun6457(kk_function_t _fself, kk_box_t _b_5288, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4689_run__climate__model_fun6457__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift4689_run__climate__model_fun6457__t*, _fself);
  kk_integer_t burnin = _self->burnin; /* int */
  kk_std_core_types__tuple2_ data = _self->data; /* (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>) */
  kk_integer_t t__steps = _self->t__steps; /* int */
  kk_drop_match(_self, {kk_integer_dup(burnin);kk_std_core_types__tuple2__dup(data);kk_integer_dup(t__steps);}, {}, _ctx)
  kk_std_core_types__tuple2_ _match_6224 = kk_std_core_types__tuple2__unbox(_b_5288, _ctx); /*(int, (double, double, string))*/;
  kk_box_t _box_x5247 = _match_6224.fst;
  kk_box_t _box_x5248 = _match_6224.snd;
  kk_integer_t ind0 = kk_integer_unbox(_box_x5247);
  kk_std_core_types__tuple3_ _pat4 = kk_std_core_types__tuple3__unbox(_box_x5248, NULL);
  kk_box_t _box_x5249 = _pat4.fst;
  kk_box_t _box_x5250 = _pat4.snd;
  kk_box_t _box_x5251 = _pat4.thd;
  double diff0 = kk_double_unbox(_box_x5249, NULL);
  double subtract0 = kk_double_unbox(_box_x5250, NULL);
  kk_string_t name0 = kk_string_unbox(_box_x5251);
  kk_integer_dup(ind0);
  kk_string_dup(name0);
  kk_std_core_types__tuple2__drop(_match_6224, _ctx);
  return kk_std_time_timer_print_elapsed(kk_climate_dash_experiments__new_mlift4689_run__climate__model_fun6463(burnin, data, ind0, name0, t__steps, diff0, subtract0, _ctx), kk_std_core_types__new_None(_ctx), _ctx);
}
static kk_box_t kk_climate_dash_experiments__mlift4689_run__climate__model_fun6454(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4689_run__climate__model_fun6454__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift4689_run__climate__model_fun6454__t*, _fself);
  kk_integer_t burnin = _self->burnin; /* int */
  kk_std_core_types__tuple2_ data = _self->data; /* (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>) */
  kk_std_core__list pre__data = _self->pre__data; /* list<(double, double, string)> */
  kk_integer_t t__steps = _self->t__steps; /* int */
  kk_drop_match(_self, {kk_integer_dup(burnin);kk_std_core_types__tuple2__dup(data);kk_std_core__list_dup(pre__data);kk_integer_dup(t__steps);}, {}, _ctx)
  kk_std_core__list _x6455;
  kk_std_core__list _b_5295_5286;
  kk_std_core__list _x6456 = kk_std_core__lift21053_list(kk_integer_from_small(0), kk_integer_from_small(11), kk_std_core__new_Nil(_ctx), _ctx); /*list<int>*/
  _b_5295_5286 = kk_std_core_zip(_x6456, pre__data, _ctx); /*list<(int, (double, double, string))>*/
  _x6455 = kk_std_core_map_5(_b_5295_5286, kk_climate_dash_experiments__new_mlift4689_run__climate__model_fun6457(burnin, data, t__steps, _ctx), _ctx); /*list<2>*/
  return kk_std_core__list_box(_x6455, _ctx);
}
static kk_box_t kk_climate_dash_experiments__mlift4689_run__climate__model_fun6453(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4689_run__climate__model_fun6453__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift4689_run__climate__model_fun6453__t*, _fself);
  kk_integer_t burnin = _self->burnin; /* int */
  kk_std_core_types__tuple2_ data = _self->data; /* (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>) */
  kk_std_core__list pre__data = _self->pre__data; /* list<(double, double, string)> */
  kk_integer_t t__steps = _self->t__steps; /* int */
  kk_drop_match(_self, {kk_integer_dup(burnin);kk_std_core_types__tuple2__dup(data);kk_std_core__list_dup(pre__data);kk_integer_dup(t__steps);}, {}, _ctx)
  return kk_handlers_random__sampler(kk_climate_dash_experiments__new_mlift4689_run__climate__model_fun6454(burnin, data, pre__data, t__steps, _ctx), _ctx);
}

kk_std_core__list kk_climate_dash_experiments__mlift4689_run__climate__model(kk_integer_t burnin, kk_std_core_types__tuple2_ data, kk_std_core__list pre__data, kk_integer_t t__steps, kk_std_core__list wild__1, kk_context_t* _ctx) { /* (burnin : int, data : (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>), pre_data : list<(double, double, string)>, t_steps : int, wild_1 : list<()>) -> <ndet,console,div,exn,fsys,std/num/random/random> list<()> */ 
  kk_std_core__list_drop(wild__1, _ctx);
  kk_unit_t __2 = kk_Unit;
  kk_string_t _x6450;
  kk_define_string_literal(, _s6451, 39, "Beginning to start TMCMC experiment #2:")
  _x6450 = kk_string_dup(_s6451); /*string*/
  kk_std_core_printsln(_x6450, _ctx);
  kk_box_t _x6452 = kk_std_time_timer_print_elapsed(kk_climate_dash_experiments__new_mlift4689_run__climate__model_fun6453(burnin, data, pre__data, t__steps, _ctx), kk_std_core_types__new_None(_ctx), _ctx); /*0*/
  return kk_std_core__list_unbox(_x6452, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_climate_dash_experiments__mlift4690_run__climate__model_fun6530__t {
  struct kk_function_s _base;
  kk_integer_t burnin;
  kk_std_core_types__tuple2_ data;
  kk_std_core__list pre__data;
  kk_integer_t t__steps;
};
static kk_box_t kk_climate_dash_experiments__mlift4690_run__climate__model_fun6530(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift4690_run__climate__model_fun6530(kk_integer_t burnin, kk_std_core_types__tuple2_ data, kk_std_core__list pre__data, kk_integer_t t__steps, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4690_run__climate__model_fun6530__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift4690_run__climate__model_fun6530__t, 6, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift4690_run__climate__model_fun6530, kk_context());
  _self->burnin = burnin;
  _self->data = data;
  _self->pre__data = pre__data;
  _self->t__steps = t__steps;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift4690_run__climate__model_fun6531__t {
  struct kk_function_s _base;
  kk_integer_t burnin;
  kk_std_core_types__tuple2_ data;
  kk_std_core__list pre__data;
  kk_integer_t t__steps;
};
static kk_box_t kk_climate_dash_experiments__mlift4690_run__climate__model_fun6531(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift4690_run__climate__model_fun6531(kk_integer_t burnin, kk_std_core_types__tuple2_ data, kk_std_core__list pre__data, kk_integer_t t__steps, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4690_run__climate__model_fun6531__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift4690_run__climate__model_fun6531__t, 6, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift4690_run__climate__model_fun6531, kk_context());
  _self->burnin = burnin;
  _self->data = data;
  _self->pre__data = pre__data;
  _self->t__steps = t__steps;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift4690_run__climate__model_fun6534__t {
  struct kk_function_s _base;
  kk_integer_t burnin;
  kk_std_core_types__tuple2_ data;
  kk_integer_t t__steps;
};
static kk_box_t kk_climate_dash_experiments__mlift4690_run__climate__model_fun6534(kk_function_t _fself, kk_box_t _b_5463, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift4690_run__climate__model_fun6534(kk_integer_t burnin, kk_std_core_types__tuple2_ data, kk_integer_t t__steps, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4690_run__climate__model_fun6534__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift4690_run__climate__model_fun6534__t, 5, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift4690_run__climate__model_fun6534, kk_context());
  _self->burnin = burnin;
  _self->data = data;
  _self->t__steps = t__steps;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift4690_run__climate__model_fun6540__t {
  struct kk_function_s _base;
  kk_integer_t burnin;
  kk_std_core_types__tuple2_ data;
  kk_integer_t ind;
  kk_string_t name;
  kk_integer_t t__steps;
  double diff;
  double subtract;
};
static kk_box_t kk_climate_dash_experiments__mlift4690_run__climate__model_fun6540(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift4690_run__climate__model_fun6540(kk_integer_t burnin, kk_std_core_types__tuple2_ data, kk_integer_t ind, kk_string_t name, kk_integer_t t__steps, double diff, double subtract, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4690_run__climate__model_fun6540__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift4690_run__climate__model_fun6540__t, 7, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift4690_run__climate__model_fun6540, kk_context());
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
struct kk_climate_dash_experiments__mlift4690_run__climate__model_fun6560__t {
  struct kk_function_s _base;
  size_t i_4769;
};
static kk_box_t kk_climate_dash_experiments__mlift4690_run__climate__model_fun6560(kk_function_t _fself, kk_function_t _b_5447, kk_box_t _b_5448, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift4690_run__climate__model_fun6560(size_t i_4769, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4690_run__climate__model_fun6560__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift4690_run__climate__model_fun6560__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift4690_run__climate__model_fun6560, kk_context());
  _self->i_4769 = i_4769;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift4690_run__climate__model_fun6560(kk_function_t _fself, kk_function_t _b_5447, kk_box_t _b_5448, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4690_run__climate__model_fun6560__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift4690_run__climate__model_fun6560__t*, _fself);
  size_t i_4769 = _self->i_4769; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_4769, _b_5447, _b_5448, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift4690_run__climate__model_fun6562__t {
  struct kk_function_s _base;
  kk_integer_t burnin;
  kk_std_core_types__tuple2_ data;
  kk_integer_t ind;
  kk_string_t name;
  kk_integer_t t__steps;
  double diff;
  double subtract;
};
static kk_box_t kk_climate_dash_experiments__mlift4690_run__climate__model_fun6562(kk_function_t _fself, kk_box_t _b_5458, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift4690_run__climate__model_fun6562(kk_integer_t burnin, kk_std_core_types__tuple2_ data, kk_integer_t ind, kk_string_t name, kk_integer_t t__steps, double diff, double subtract, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4690_run__climate__model_fun6562__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift4690_run__climate__model_fun6562__t, 7, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift4690_run__climate__model_fun6562, kk_context());
  _self->burnin = burnin;
  _self->data = data;
  _self->ind = ind;
  _self->name = name;
  _self->t__steps = t__steps;
  _self->diff = diff;
  _self->subtract = subtract;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift4690_run__climate__model_fun6562(kk_function_t _fself, kk_box_t _b_5458, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4690_run__climate__model_fun6562__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift4690_run__climate__model_fun6562__t*, _fself);
  kk_integer_t burnin = _self->burnin; /* int */
  kk_std_core_types__tuple2_ data = _self->data; /* (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>) */
  kk_integer_t ind = _self->ind; /* int */
  kk_string_t name = _self->name; /* string */
  kk_integer_t t__steps = _self->t__steps; /* int */
  double diff = _self->diff; /* double */
  double subtract = _self->subtract; /* double */
  kk_drop_match(_self, {kk_integer_dup(burnin);kk_std_core_types__tuple2__dup(data);kk_integer_dup(ind);kk_string_dup(name);kk_integer_dup(t__steps);;;}, {}, _ctx)
  kk_unit_t _x6563 = kk_Unit;
  kk_std_core__list _x6564 = kk_std_core__list_unbox(_b_5458, _ctx); /*list<effects-and-types/row_vector>*/
  kk_climate_dash_experiments__mlift4688_run__climate__model(burnin, data, diff, ind, name, subtract, t__steps, _x6564, _ctx);
  return kk_unit_box(_x6563);
}
static kk_box_t kk_climate_dash_experiments__mlift4690_run__climate__model_fun6540(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4690_run__climate__model_fun6540__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift4690_run__climate__model_fun6540__t*, _fself);
  kk_integer_t burnin = _self->burnin; /* int */
  kk_std_core_types__tuple2_ data = _self->data; /* (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>) */
  kk_integer_t ind = _self->ind; /* int */
  kk_string_t name = _self->name; /* string */
  kk_integer_t t__steps = _self->t__steps; /* int */
  double diff = _self->diff; /* double */
  double subtract = _self->subtract; /* double */
  kk_drop_match(_self, {kk_integer_dup(burnin);kk_std_core_types__tuple2__dup(data);kk_integer_dup(ind);kk_string_dup(name);kk_integer_dup(t__steps);;;}, {}, _ctx)
  kk_unit_t _x6541 = kk_Unit;
  kk_std_core__list x0_4766;
  size_t i_4769 = ((size_t)0); /*std/core/hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_4769,kk_context()); /*std/core/hnd/evv<<exn,div,effects-and-types/sample,fsys,console,ndet,std/num/random/random>>*/;
  kk_std_core__list y;
  kk_std_core_types__maybe _match_6221;
  kk_std_core__list _x6542;
  kk_box_t _box_x5427 = data.fst;
  kk_box_t _box_x5428 = data.snd;
  kk_std_core__list _x = kk_std_core__list_unbox(_box_x5428, NULL);
  kk_std_core__list_dup(_x);
  _x6542 = _x; /*list<list<effects-and-types/row_vector>>*/
  kk_integer_t _x6545 = kk_integer_dup(ind); /*int*/
  _match_6221 = kk_std_core__lp__lb__rb__2_rp_(_x6542, _x6545, _ctx); /*maybe<1>*/
  if (kk_std_core_types__is_Nothing(_match_6221)) {
    kk_string_t message_205;
    kk_string_t _x6546;
    kk_define_string_literal(, _s6547, 48, "ListIndexError: Invalid list indexing at index: ")
    _x6546 = kk_string_dup(_s6547); /*string*/
    kk_string_t _x6548;
    kk_integer_t _x6549 = kk_integer_dup(ind); /*int*/
    _x6548 = kk_std_core_show(_x6549, _ctx); /*string*/
    message_205 = kk_std_core__lp__plus__plus__1_rp_(_x6546, _x6548, _ctx); /*string*/
    kk_std_core__exception exn_21561;
    kk_std_core__exception_info _x6550;
    kk_std_core_types__optional _match_6223 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
    if (kk_std_core_types__is_Optional(_match_6223)) {
      kk_box_t _box_x5429 = _match_6223._cons.Optional.value;
      kk_std_core__exception_info _info_14279 = kk_std_core__exception_info_unbox(_box_x5429, NULL);
      kk_std_core__exception_info_dup(_info_14279);
      kk_std_core_types__optional_drop(_match_6223, _ctx);
      _x6550 = _info_14279; /*exception-info*/
      goto _match6551;
    }
    _x6550 = kk_std_core__new_ExnError(_ctx); /*exception-info*/
    _match6551: ;
    exn_21561 = kk_std_core__new_Exception(message_205, _x6550, _ctx); /*exception*/
    kk_std_core_hnd__ev ev_21562;
    size_t _x6553 = ((size_t)0); /*size_t*/
    ev_21562 = kk_evv_at(_x6553,kk_context()); /*std/core/hnd/ev<.hnd-exn>*/
    kk_box_t _x6554;
    struct kk_std_core_hnd_Ev* _con6555 = kk_std_core_hnd__as_Ev(ev_21562);
    kk_std_core_hnd__marker m = _con6555->marker;
    kk_box_t _box_x5430 = _con6555->hnd;
    kk_std_core__hnd_exn h = kk_std_core__hnd_exn_unbox(_box_x5430, NULL);
    kk_std_core__hnd_exn_dup(h);
    kk_std_core_hnd__clause1 _match_6222;
    struct kk_std_core__Hnd_exn* _con6557 = kk_std_core__as_Hnd_exn(h);
    kk_std_core_hnd__clause1 except_throw_exn = _con6557->except_throw_exn;
    if (kk_std_core__hnd_exn_is_unique(h)) {
      kk_std_core__hnd_exn_free(h);
    }
    else {
      kk_std_core_hnd__clause1_dup(except_throw_exn);
      kk_std_core__hnd_exn_decref(h, _ctx);
    }
    _match_6222 = except_throw_exn; /*forall<a> std/core/hnd/clause1<exception,a,.hnd-exn,7,8>*/
    kk_function_t _fun_unbox_x5434 = _match_6222.clause;
    _x6554 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x5434, (_fun_unbox_x5434, m, ev_21562, kk_std_core__exception_box(exn_21561, _ctx), _ctx)); /*11*/
    y = kk_std_core__list_unbox(_x6554, _ctx); /*list<effects-and-types/row_vector>*/
  }
  else {
    kk_box_t _box_x5438 = _match_6221._cons.Just.value;
    kk_std_core__list x = kk_std_core__list_unbox(_box_x5438, NULL);
    kk_std_core__list_dup(x);
    kk_std_core_types__maybe_drop(_match_6221, _ctx);
    y = x; /*list<effects-and-types/row_vector>*/
  }
  kk_unit_t __w_l717_c9 = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(y, _ctx);
    kk_box_t _x6559 = kk_std_core_hnd_yield_cont(kk_climate_dash_experiments__new_mlift4690_run__climate__model_fun6560(i_4769, _ctx), _ctx); /*3*/
    x0_4766 = kk_std_core__list_unbox(_x6559, _ctx); /*list<effects-and-types/row_vector>*/
  }
  else {
    x0_4766 = y; /*list<effects-and-types/row_vector>*/
  }
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x0_4766, _ctx);
    kk_box_t _x6561 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments__new_mlift4690_run__climate__model_fun6562(burnin, data, ind, name, t__steps, diff, subtract, _ctx), _ctx); /*2*/
    kk_unit_unbox(_x6561);
  }
  else {
    kk_climate_dash_experiments__mlift4688_run__climate__model(burnin, data, diff, ind, name, subtract, t__steps, x0_4766, _ctx);
  }
  return kk_unit_box(_x6541);
}
static kk_box_t kk_climate_dash_experiments__mlift4690_run__climate__model_fun6534(kk_function_t _fself, kk_box_t _b_5463, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4690_run__climate__model_fun6534__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift4690_run__climate__model_fun6534__t*, _fself);
  kk_integer_t burnin = _self->burnin; /* int */
  kk_std_core_types__tuple2_ data = _self->data; /* (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>) */
  kk_integer_t t__steps = _self->t__steps; /* int */
  kk_drop_match(_self, {kk_integer_dup(burnin);kk_std_core_types__tuple2__dup(data);kk_integer_dup(t__steps);}, {}, _ctx)
  kk_std_core_types__tuple2_ _match_6218 = kk_std_core_types__tuple2__unbox(_b_5463, _ctx); /*(int, (double, double, string))*/;
  kk_box_t _box_x5422 = _match_6218.fst;
  kk_box_t _box_x5423 = _match_6218.snd;
  kk_integer_t ind = kk_integer_unbox(_box_x5422);
  kk_std_core_types__tuple3_ _pat2 = kk_std_core_types__tuple3__unbox(_box_x5423, NULL);
  kk_box_t _box_x5424 = _pat2.fst;
  kk_box_t _box_x5425 = _pat2.snd;
  kk_box_t _box_x5426 = _pat2.thd;
  double diff = kk_double_unbox(_box_x5424, NULL);
  double subtract = kk_double_unbox(_box_x5425, NULL);
  kk_string_t name = kk_string_unbox(_box_x5426);
  kk_integer_dup(ind);
  kk_string_dup(name);
  kk_std_core_types__tuple2__drop(_match_6218, _ctx);
  return kk_std_time_timer_print_elapsed(kk_climate_dash_experiments__new_mlift4690_run__climate__model_fun6540(burnin, data, ind, name, t__steps, diff, subtract, _ctx), kk_std_core_types__new_None(_ctx), _ctx);
}
static kk_box_t kk_climate_dash_experiments__mlift4690_run__climate__model_fun6531(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4690_run__climate__model_fun6531__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift4690_run__climate__model_fun6531__t*, _fself);
  kk_integer_t burnin = _self->burnin; /* int */
  kk_std_core_types__tuple2_ data = _self->data; /* (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>) */
  kk_std_core__list pre__data = _self->pre__data; /* list<(double, double, string)> */
  kk_integer_t t__steps = _self->t__steps; /* int */
  kk_drop_match(_self, {kk_integer_dup(burnin);kk_std_core_types__tuple2__dup(data);kk_std_core__list_dup(pre__data);kk_integer_dup(t__steps);}, {}, _ctx)
  kk_std_core__list _x6532;
  kk_std_core__list _b_5470_5461;
  kk_std_core__list _x6533 = kk_std_core__lift21053_list(kk_integer_from_small(0), kk_integer_from_small(11), kk_std_core__new_Nil(_ctx), _ctx); /*list<int>*/
  _b_5470_5461 = kk_std_core_zip(_x6533, pre__data, _ctx); /*list<(int, (double, double, string))>*/
  _x6532 = kk_std_core_map_5(_b_5470_5461, kk_climate_dash_experiments__new_mlift4690_run__climate__model_fun6534(burnin, data, t__steps, _ctx), _ctx); /*list<2>*/
  return kk_std_core__list_box(_x6532, _ctx);
}
static kk_box_t kk_climate_dash_experiments__mlift4690_run__climate__model_fun6530(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4690_run__climate__model_fun6530__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift4690_run__climate__model_fun6530__t*, _fself);
  kk_integer_t burnin = _self->burnin; /* int */
  kk_std_core_types__tuple2_ data = _self->data; /* (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>) */
  kk_std_core__list pre__data = _self->pre__data; /* list<(double, double, string)> */
  kk_integer_t t__steps = _self->t__steps; /* int */
  kk_drop_match(_self, {kk_integer_dup(burnin);kk_std_core_types__tuple2__dup(data);kk_std_core__list_dup(pre__data);kk_integer_dup(t__steps);}, {}, _ctx)
  return kk_handlers_random__sampler(kk_climate_dash_experiments__new_mlift4690_run__climate__model_fun6531(burnin, data, pre__data, t__steps, _ctx), _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift4690_run__climate__model_fun6566__t {
  struct kk_function_s _base;
  kk_integer_t burnin;
  kk_std_core_types__tuple2_ data;
  kk_std_core__list pre__data;
  kk_integer_t t__steps;
};
static kk_box_t kk_climate_dash_experiments__mlift4690_run__climate__model_fun6566(kk_function_t _fself, kk_box_t _b_5478, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift4690_run__climate__model_fun6566(kk_integer_t burnin, kk_std_core_types__tuple2_ data, kk_std_core__list pre__data, kk_integer_t t__steps, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4690_run__climate__model_fun6566__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift4690_run__climate__model_fun6566__t, 6, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift4690_run__climate__model_fun6566, kk_context());
  _self->burnin = burnin;
  _self->data = data;
  _self->pre__data = pre__data;
  _self->t__steps = t__steps;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift4690_run__climate__model_fun6566(kk_function_t _fself, kk_box_t _b_5478, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4690_run__climate__model_fun6566__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift4690_run__climate__model_fun6566__t*, _fself);
  kk_integer_t burnin = _self->burnin; /* int */
  kk_std_core_types__tuple2_ data = _self->data; /* (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>) */
  kk_std_core__list pre__data = _self->pre__data; /* list<(double, double, string)> */
  kk_integer_t t__steps = _self->t__steps; /* int */
  kk_drop_match(_self, {kk_integer_dup(burnin);kk_std_core_types__tuple2__dup(data);kk_std_core__list_dup(pre__data);kk_integer_dup(t__steps);}, {}, _ctx)
  kk_std_core__list _x6567;
  kk_std_core__list _x6568 = kk_std_core__list_unbox(_b_5478, _ctx); /*list<()>*/
  _x6567 = kk_climate_dash_experiments__mlift4689_run__climate__model(burnin, data, pre__data, t__steps, _x6568, _ctx); /*list<()>*/
  return kk_std_core__list_box(_x6567, _ctx);
}

kk_std_core__list kk_climate_dash_experiments__mlift4690_run__climate__model(kk_integer_t burnin, kk_integer_t t__steps, kk_std_core_types__tuple2_ data, kk_context_t* _ctx) { /* (burnin : int, t_steps : int, data : (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>)) -> <div,exn,fsys,console,ndet,std/num/random/random> list<()> */ 
  kk_std_core__list pre__data;
  kk_std_core_types__tuple3_ _b_5362_5360;
  kk_box_t _x6488;
  kk_string_t _x6489;
  kk_define_string_literal(, _s6490, 3, "jan")
  _x6489 = kk_string_dup(_s6490); /*string*/
  _x6488 = kk_string_box(_x6489); /*10*/
  _b_5362_5360 = kk_std_core_types__new_dash__lp__comma__comma__rp_(kk_double_box(0x1.4p3, _ctx), kk_double_box(-0x1.8p1, _ctx), _x6488, _ctx); /*(double, double, string)*/
  kk_std_core__list _b_5363_5361;
  kk_std_core_types__tuple3_ _b_5367_5358;
  kk_box_t _x6491;
  kk_string_t _x6492;
  kk_define_string_literal(, _s6493, 3, "feb")
  _x6492 = kk_string_dup(_s6493); /*string*/
  _x6491 = kk_string_box(_x6492); /*10*/
  _b_5367_5358 = kk_std_core_types__new_dash__lp__comma__comma__rp_(kk_double_box(0x1p3, _ctx), kk_double_box(-0x1p0, _ctx), _x6491, _ctx); /*(double, double, string)*/
  kk_std_core__list _b_5368_5359;
  kk_std_core_types__tuple3_ _b_5372_5356;
  kk_box_t _x6494;
  kk_string_t _x6495;
  kk_define_string_literal(, _s6496, 3, "mar")
  _x6495 = kk_string_dup(_s6496); /*string*/
  _x6494 = kk_string_box(_x6495); /*10*/
  _b_5372_5356 = kk_std_core_types__new_dash__lp__comma__comma__rp_(kk_double_box(0x1.cp2, _ctx), kk_double_box(0x1p0, _ctx), _x6494, _ctx); /*(double, double, string)*/
  kk_std_core__list _b_5373_5357;
  kk_std_core_types__tuple3_ _b_5377_5354;
  kk_box_t _x6497;
  kk_string_t _x6498;
  kk_define_string_literal(, _s6499, 3, "apr")
  _x6498 = kk_string_dup(_s6499); /*string*/
  _x6497 = kk_string_box(_x6498); /*10*/
  _b_5377_5354 = kk_std_core_types__new_dash__lp__comma__comma__rp_(kk_double_box(0x1.8p2, _ctx), kk_double_box(0x1.4p2, _ctx), _x6497, _ctx); /*(double, double, string)*/
  kk_std_core__list _b_5378_5355;
  kk_std_core_types__tuple3_ _b_5382_5352;
  kk_box_t _x6500;
  kk_string_t _x6501;
  kk_define_string_literal(, _s6502, 3, "may")
  _x6501 = kk_string_dup(_s6502); /*string*/
  _x6500 = kk_string_box(_x6501); /*10*/
  _b_5382_5352 = kk_std_core_types__new_dash__lp__comma__comma__rp_(kk_double_box(0x1p3, _ctx), kk_double_box(0x1.2p3, _ctx), _x6500, _ctx); /*(double, double, string)*/
  kk_std_core__list _b_5383_5353;
  kk_std_core_types__tuple3_ _b_5387_5350;
  kk_box_t _x6503;
  kk_string_t _x6504;
  kk_define_string_literal(, _s6505, 3, "jun")
  _x6504 = kk_string_dup(_s6505); /*string*/
  _x6503 = kk_string_box(_x6504); /*10*/
  _b_5387_5350 = kk_std_core_types__new_dash__lp__comma__comma__rp_(kk_double_box(0x1p3, _ctx), kk_double_box(0x1.4p3, _ctx), _x6503, _ctx); /*(double, double, string)*/
  kk_std_core__list _b_5388_5351;
  kk_std_core_types__tuple3_ _b_5392_5348;
  kk_box_t _x6506;
  kk_string_t _x6507;
  kk_define_string_literal(, _s6508, 3, "jul")
  _x6507 = kk_string_dup(_s6508); /*string*/
  _x6506 = kk_string_box(_x6507); /*10*/
  _b_5392_5348 = kk_std_core_types__new_dash__lp__comma__comma__rp_(kk_double_box(0x1.2p3, _ctx), kk_double_box(0x1.6p3, _ctx), _x6506, _ctx); /*(double, double, string)*/
  kk_std_core__list _b_5393_5349;
  kk_std_core_types__tuple3_ _b_5397_5346;
  kk_box_t _x6509;
  kk_string_t _x6510;
  kk_define_string_literal(, _s6511, 3, "aug")
  _x6510 = kk_string_dup(_s6511); /*string*/
  _x6509 = kk_string_box(_x6510); /*10*/
  _b_5397_5346 = kk_std_core_types__new_dash__lp__comma__comma__rp_(kk_double_box(0x1.8p2, _ctx), kk_double_box(0x1.6p3, _ctx), _x6509, _ctx); /*(double, double, string)*/
  kk_std_core__list _b_5398_5347;
  kk_std_core_types__tuple3_ _b_5402_5344;
  kk_box_t _x6512;
  kk_string_t _x6513;
  kk_define_string_literal(, _s6514, 3, "sep")
  _x6513 = kk_string_dup(_s6514); /*string*/
  _x6512 = kk_string_box(_x6513); /*10*/
  _b_5402_5344 = kk_std_core_types__new_dash__lp__comma__comma__rp_(kk_double_box(0x1.4p2, _ctx), kk_double_box(0x1.4p3, _ctx), _x6512, _ctx); /*(double, double, string)*/
  kk_std_core__list _b_5403_5345;
  kk_std_core_types__tuple3_ _b_5407_5342;
  kk_box_t _x6515;
  kk_string_t _x6516;
  kk_define_string_literal(, _s6517, 3, "oct")
  _x6516 = kk_string_dup(_s6517); /*string*/
  _x6515 = kk_string_box(_x6516); /*10*/
  _b_5407_5342 = kk_std_core_types__new_dash__lp__comma__comma__rp_(kk_double_box(0x1.2p3, _ctx), kk_double_box(0x1p0, _ctx), _x6515, _ctx); /*(double, double, string)*/
  kk_std_core__list _b_5408_5343;
  kk_std_core_types__tuple3_ _b_5412_5340;
  kk_box_t _x6518;
  kk_string_t _x6519;
  kk_define_string_literal(, _s6520, 3, "nov")
  _x6519 = kk_string_dup(_s6520); /*string*/
  _x6518 = kk_string_box(_x6519); /*10*/
  _b_5412_5340 = kk_std_core_types__new_dash__lp__comma__comma__rp_(kk_double_box(0x1.cp2, _ctx), kk_double_box(0x1p1, _ctx), _x6518, _ctx); /*(double, double, string)*/
  kk_std_core__list _b_5413_5341;
  kk_std_core_types__tuple3_ _b_5417_5338;
  kk_box_t _x6521;
  kk_string_t _x6522;
  kk_define_string_literal(, _s6523, 3, "dec")
  _x6522 = kk_string_dup(_s6523); /*string*/
  _x6521 = kk_string_box(_x6522); /*10*/
  _b_5417_5338 = kk_std_core_types__new_dash__lp__comma__comma__rp_(kk_double_box(0x1.8p2, _ctx), kk_double_box(-0x1p0, _ctx), _x6521, _ctx); /*(double, double, string)*/
  _b_5413_5341 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core_types__tuple3__box(_b_5417_5338, _ctx), kk_std_core__new_Nil(_ctx), _ctx); /*list<(double, double, string)>*/
  _b_5408_5343 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core_types__tuple3__box(_b_5412_5340, _ctx), _b_5413_5341, _ctx); /*list<(double, double, string)>*/
  _b_5403_5345 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core_types__tuple3__box(_b_5407_5342, _ctx), _b_5408_5343, _ctx); /*list<(double, double, string)>*/
  _b_5398_5347 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core_types__tuple3__box(_b_5402_5344, _ctx), _b_5403_5345, _ctx); /*list<(double, double, string)>*/
  _b_5393_5349 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core_types__tuple3__box(_b_5397_5346, _ctx), _b_5398_5347, _ctx); /*list<(double, double, string)>*/
  _b_5388_5351 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core_types__tuple3__box(_b_5392_5348, _ctx), _b_5393_5349, _ctx); /*list<(double, double, string)>*/
  _b_5383_5353 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core_types__tuple3__box(_b_5387_5350, _ctx), _b_5388_5351, _ctx); /*list<(double, double, string)>*/
  _b_5378_5355 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core_types__tuple3__box(_b_5382_5352, _ctx), _b_5383_5353, _ctx); /*list<(double, double, string)>*/
  _b_5373_5357 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core_types__tuple3__box(_b_5377_5354, _ctx), _b_5378_5355, _ctx); /*list<(double, double, string)>*/
  _b_5368_5359 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core_types__tuple3__box(_b_5372_5356, _ctx), _b_5373_5357, _ctx); /*list<(double, double, string)>*/
  _b_5363_5361 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core_types__tuple3__box(_b_5367_5358, _ctx), _b_5368_5359, _ctx); /*list<(double, double, string)>*/
  pre__data = kk_std_core__new_Cons(kk_reuse_null, kk_std_core_types__tuple3__box(_b_5362_5360, _ctx), _b_5363_5361, _ctx); /*list<(double, double, string)>*/
  kk_unit_t __ = kk_Unit;
  kk_string_t _x6524;
  kk_define_string_literal(, _s6525, 93, "Starting to run the climate model! Run with -O2 --showelapsed flag to improve execution time.")
  _x6524 = kk_string_dup(_s6525); /*string*/
  kk_std_core_printsln(_x6524, _ctx);
  kk_unit_t __0 = kk_Unit;
  kk_string_t _x6526;
  kk_define_string_literal(, _s6527, 39, "Beginning to start TMCMC experiment #1:")
  _x6526 = kk_string_dup(_s6527); /*string*/
  kk_std_core_printsln(_x6526, _ctx);
  kk_std_core__list x_4762;
  kk_box_t _x6528;
  kk_function_t _x6529;
  kk_integer_dup(burnin);
  kk_std_core_types__tuple2__dup(data);
  kk_std_core__list_dup(pre__data);
  kk_integer_dup(t__steps);
  _x6529 = kk_climate_dash_experiments__new_mlift4690_run__climate__model_fun6530(burnin, data, pre__data, t__steps, _ctx); /*() -> <ndet,console|1> 0*/
  _x6528 = kk_std_time_timer_print_elapsed(_x6529, kk_std_core_types__new_None(_ctx), _ctx); /*0*/
  x_4762 = kk_std_core__list_unbox(_x6528, _ctx); /*list<()>*/
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_4762, _ctx);
    kk_box_t _x6565 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments__new_mlift4690_run__climate__model_fun6566(burnin, data, pre__data, t__steps, _ctx), _ctx); /*2*/
    return kk_std_core__list_unbox(_x6565, _ctx);
  }
  return kk_climate_dash_experiments__mlift4689_run__climate__model(burnin, data, pre__data, t__steps, x_4762, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments_run__climate__model_fun6570__t {
  struct kk_function_s _base;
  size_t i_4776;
};
static kk_box_t kk_climate_dash_experiments_run__climate__model_fun6570(kk_function_t _fself, kk_function_t _b_5486, kk_box_t _b_5487, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__climate__model_fun6570(size_t i_4776, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__climate__model_fun6570__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__climate__model_fun6570__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__climate__model_fun6570, kk_context());
  _self->i_4776 = i_4776;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments_run__climate__model_fun6570(kk_function_t _fself, kk_function_t _b_5486, kk_box_t _b_5487, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__climate__model_fun6570__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__climate__model_fun6570__t*, _fself);
  size_t i_4776 = _self->i_4776; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_4776, _b_5486, _b_5487, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments_run__climate__model_fun6572__t {
  struct kk_function_s _base;
  kk_integer_t burnin;
  kk_integer_t t__steps;
};
static kk_box_t kk_climate_dash_experiments_run__climate__model_fun6572(kk_function_t _fself, kk_box_t _b_5497, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__climate__model_fun6572(kk_integer_t burnin, kk_integer_t t__steps, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__climate__model_fun6572__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__climate__model_fun6572__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__climate__model_fun6572, kk_context());
  _self->burnin = burnin;
  _self->t__steps = t__steps;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments_run__climate__model_fun6572(kk_function_t _fself, kk_box_t _b_5497, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__climate__model_fun6572__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__climate__model_fun6572__t*, _fself);
  kk_integer_t burnin = _self->burnin; /* int */
  kk_integer_t t__steps = _self->t__steps; /* int */
  kk_drop_match(_self, {kk_integer_dup(burnin);kk_integer_dup(t__steps);}, {}, _ctx)
  kk_std_core__list _x6573;
  kk_std_core_types__tuple2_ _x6574 = kk_std_core_types__tuple2__unbox(_b_5497, _ctx); /*(list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>)*/
  _x6573 = kk_climate_dash_experiments__mlift4690_run__climate__model(burnin, t__steps, _x6574, _ctx); /*list<()>*/
  return kk_std_core__list_box(_x6573, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments_run__climate__model_fun6617__t {
  struct kk_function_s _base;
  kk_integer_t burnin;
  kk_std_core__list pre__data;
  kk_integer_t t__steps;
  kk_std_core_types__tuple2_ x_4773;
};
static kk_box_t kk_climate_dash_experiments_run__climate__model_fun6617(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__climate__model_fun6617(kk_integer_t burnin, kk_std_core__list pre__data, kk_integer_t t__steps, kk_std_core_types__tuple2_ x_4773, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__climate__model_fun6617__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__climate__model_fun6617__t, 6, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__climate__model_fun6617, kk_context());
  _self->burnin = burnin;
  _self->pre__data = pre__data;
  _self->t__steps = t__steps;
  _self->x_4773 = x_4773;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments_run__climate__model_fun6618__t {
  struct kk_function_s _base;
  kk_integer_t burnin;
  kk_std_core__list pre__data;
  kk_integer_t t__steps;
  kk_std_core_types__tuple2_ x_4773;
};
static kk_box_t kk_climate_dash_experiments_run__climate__model_fun6618(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__climate__model_fun6618(kk_integer_t burnin, kk_std_core__list pre__data, kk_integer_t t__steps, kk_std_core_types__tuple2_ x_4773, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__climate__model_fun6618__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__climate__model_fun6618__t, 6, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__climate__model_fun6618, kk_context());
  _self->burnin = burnin;
  _self->pre__data = pre__data;
  _self->t__steps = t__steps;
  _self->x_4773 = x_4773;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments_run__climate__model_fun6621__t {
  struct kk_function_s _base;
  kk_integer_t burnin;
  kk_integer_t t__steps;
  kk_std_core_types__tuple2_ x_4773;
};
static kk_box_t kk_climate_dash_experiments_run__climate__model_fun6621(kk_function_t _fself, kk_box_t _b_5659, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__climate__model_fun6621(kk_integer_t burnin, kk_integer_t t__steps, kk_std_core_types__tuple2_ x_4773, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__climate__model_fun6621__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__climate__model_fun6621__t, 5, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__climate__model_fun6621, kk_context());
  _self->burnin = burnin;
  _self->t__steps = t__steps;
  _self->x_4773 = x_4773;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments_run__climate__model_fun6627__t {
  struct kk_function_s _base;
  kk_integer_t burnin;
  kk_integer_t ind;
  kk_string_t name;
  kk_integer_t t__steps;
  kk_std_core_types__tuple2_ x_4773;
  double diff;
  double subtract;
};
static kk_box_t kk_climate_dash_experiments_run__climate__model_fun6627(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__climate__model_fun6627(kk_integer_t burnin, kk_integer_t ind, kk_string_t name, kk_integer_t t__steps, kk_std_core_types__tuple2_ x_4773, double diff, double subtract, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__climate__model_fun6627__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__climate__model_fun6627__t, 7, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__climate__model_fun6627, kk_context());
  _self->burnin = burnin;
  _self->ind = ind;
  _self->name = name;
  _self->t__steps = t__steps;
  _self->x_4773 = x_4773;
  _self->diff = diff;
  _self->subtract = subtract;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments_run__climate__model_fun6647__t {
  struct kk_function_s _base;
  size_t i0_4789;
};
static kk_box_t kk_climate_dash_experiments_run__climate__model_fun6647(kk_function_t _fself, kk_function_t _b_5643, kk_box_t _b_5644, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__climate__model_fun6647(size_t i0_4789, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__climate__model_fun6647__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__climate__model_fun6647__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__climate__model_fun6647, kk_context());
  _self->i0_4789 = i0_4789;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments_run__climate__model_fun6647(kk_function_t _fself, kk_function_t _b_5643, kk_box_t _b_5644, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__climate__model_fun6647__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__climate__model_fun6647__t*, _fself);
  size_t i0_4789 = _self->i0_4789; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i0_4789, _b_5643, _b_5644, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments_run__climate__model_fun6649__t {
  struct kk_function_s _base;
  kk_integer_t burnin;
  kk_integer_t ind;
  kk_string_t name;
  kk_integer_t t__steps;
  kk_std_core_types__tuple2_ x_4773;
  double diff;
  double subtract;
};
static kk_box_t kk_climate_dash_experiments_run__climate__model_fun6649(kk_function_t _fself, kk_box_t _b_5654, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__climate__model_fun6649(kk_integer_t burnin, kk_integer_t ind, kk_string_t name, kk_integer_t t__steps, kk_std_core_types__tuple2_ x_4773, double diff, double subtract, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__climate__model_fun6649__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__climate__model_fun6649__t, 7, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__climate__model_fun6649, kk_context());
  _self->burnin = burnin;
  _self->ind = ind;
  _self->name = name;
  _self->t__steps = t__steps;
  _self->x_4773 = x_4773;
  _self->diff = diff;
  _self->subtract = subtract;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments_run__climate__model_fun6649(kk_function_t _fself, kk_box_t _b_5654, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__climate__model_fun6649__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__climate__model_fun6649__t*, _fself);
  kk_integer_t burnin = _self->burnin; /* int */
  kk_integer_t ind = _self->ind; /* int */
  kk_string_t name = _self->name; /* string */
  kk_integer_t t__steps = _self->t__steps; /* int */
  kk_std_core_types__tuple2_ x_4773 = _self->x_4773; /* (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>) */
  double diff = _self->diff; /* double */
  double subtract = _self->subtract; /* double */
  kk_drop_match(_self, {kk_integer_dup(burnin);kk_integer_dup(ind);kk_string_dup(name);kk_integer_dup(t__steps);kk_std_core_types__tuple2__dup(x_4773);;;}, {}, _ctx)
  kk_unit_t _x6650 = kk_Unit;
  kk_std_core__list _x6651 = kk_std_core__list_unbox(_b_5654, _ctx); /*list<effects-and-types/row_vector>*/
  kk_climate_dash_experiments__mlift4688_run__climate__model(burnin, x_4773, diff, ind, name, subtract, t__steps, _x6651, _ctx);
  return kk_unit_box(_x6650);
}
static kk_box_t kk_climate_dash_experiments_run__climate__model_fun6627(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__climate__model_fun6627__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__climate__model_fun6627__t*, _fself);
  kk_integer_t burnin = _self->burnin; /* int */
  kk_integer_t ind = _self->ind; /* int */
  kk_string_t name = _self->name; /* string */
  kk_integer_t t__steps = _self->t__steps; /* int */
  kk_std_core_types__tuple2_ x_4773 = _self->x_4773; /* (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>) */
  double diff = _self->diff; /* double */
  double subtract = _self->subtract; /* double */
  kk_drop_match(_self, {kk_integer_dup(burnin);kk_integer_dup(ind);kk_string_dup(name);kk_integer_dup(t__steps);kk_std_core_types__tuple2__dup(x_4773);;;}, {}, _ctx)
  kk_unit_t _x6628 = kk_Unit;
  kk_std_core__list x1_4786;
  size_t i0_4789 = ((size_t)0); /*std/core/hnd/ev-index*/;
  kk_evv_t w0 = kk_evv_swap_create1(i0_4789,kk_context()); /*std/core/hnd/evv<<exn,div,effects-and-types/sample,fsys,console,ndet,std/num/random/random>>*/;
  kk_std_core__list y0;
  kk_std_core_types__maybe _match_6213;
  kk_std_core__list _x6629;
  kk_box_t _box_x5623 = x_4773.fst;
  kk_box_t _box_x5624 = x_4773.snd;
  kk_std_core__list _x = kk_std_core__list_unbox(_box_x5624, NULL);
  kk_std_core__list_dup(_x);
  _x6629 = _x; /*list<list<effects-and-types/row_vector>>*/
  kk_integer_t _x6632 = kk_integer_dup(ind); /*int*/
  _match_6213 = kk_std_core__lp__lb__rb__2_rp_(_x6629, _x6632, _ctx); /*maybe<1>*/
  if (kk_std_core_types__is_Nothing(_match_6213)) {
    kk_string_t message_205;
    kk_string_t _x6633;
    kk_define_string_literal(, _s6634, 48, "ListIndexError: Invalid list indexing at index: ")
    _x6633 = kk_string_dup(_s6634); /*string*/
    kk_string_t _x6635;
    kk_integer_t _x6636 = kk_integer_dup(ind); /*int*/
    _x6635 = kk_std_core_show(_x6636, _ctx); /*string*/
    message_205 = kk_std_core__lp__plus__plus__1_rp_(_x6633, _x6635, _ctx); /*string*/
    kk_std_core__exception exn_21561;
    kk_std_core__exception_info _x6637;
    kk_std_core_types__optional _match_6215 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
    if (kk_std_core_types__is_Optional(_match_6215)) {
      kk_box_t _box_x5625 = _match_6215._cons.Optional.value;
      kk_std_core__exception_info _info_14279 = kk_std_core__exception_info_unbox(_box_x5625, NULL);
      kk_std_core__exception_info_dup(_info_14279);
      kk_std_core_types__optional_drop(_match_6215, _ctx);
      _x6637 = _info_14279; /*exception-info*/
      goto _match6638;
    }
    _x6637 = kk_std_core__new_ExnError(_ctx); /*exception-info*/
    _match6638: ;
    exn_21561 = kk_std_core__new_Exception(message_205, _x6637, _ctx); /*exception*/
    kk_std_core_hnd__ev ev_21562;
    size_t _x6640 = ((size_t)0); /*size_t*/
    ev_21562 = kk_evv_at(_x6640,kk_context()); /*std/core/hnd/ev<.hnd-exn>*/
    kk_box_t _x6641;
    struct kk_std_core_hnd_Ev* _con6642 = kk_std_core_hnd__as_Ev(ev_21562);
    kk_std_core_hnd__marker m = _con6642->marker;
    kk_box_t _box_x5626 = _con6642->hnd;
    kk_std_core__hnd_exn h = kk_std_core__hnd_exn_unbox(_box_x5626, NULL);
    kk_std_core__hnd_exn_dup(h);
    kk_std_core_hnd__clause1 _match_6214;
    struct kk_std_core__Hnd_exn* _con6644 = kk_std_core__as_Hnd_exn(h);
    kk_std_core_hnd__clause1 except_throw_exn = _con6644->except_throw_exn;
    if (kk_std_core__hnd_exn_is_unique(h)) {
      kk_std_core__hnd_exn_free(h);
    }
    else {
      kk_std_core_hnd__clause1_dup(except_throw_exn);
      kk_std_core__hnd_exn_decref(h, _ctx);
    }
    _match_6214 = except_throw_exn; /*forall<a> std/core/hnd/clause1<exception,a,.hnd-exn,7,8>*/
    kk_function_t _fun_unbox_x5630 = _match_6214.clause;
    _x6641 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x5630, (_fun_unbox_x5630, m, ev_21562, kk_std_core__exception_box(exn_21561, _ctx), _ctx)); /*11*/
    y0 = kk_std_core__list_unbox(_x6641, _ctx); /*list<effects-and-types/row_vector>*/
  }
  else {
    kk_box_t _box_x5634 = _match_6213._cons.Just.value;
    kk_std_core__list x = kk_std_core__list_unbox(_box_x5634, NULL);
    kk_std_core__list_dup(x);
    kk_std_core_types__maybe_drop(_match_6213, _ctx);
    y0 = x; /*list<effects-and-types/row_vector>*/
  }
  kk_unit_t __w_l717_c9 = kk_Unit;
  kk_evv_set(w0,kk_context());
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(y0, _ctx);
    kk_box_t _x6646 = kk_std_core_hnd_yield_cont(kk_climate_dash_experiments_new_run__climate__model_fun6647(i0_4789, _ctx), _ctx); /*3*/
    x1_4786 = kk_std_core__list_unbox(_x6646, _ctx); /*list<effects-and-types/row_vector>*/
  }
  else {
    x1_4786 = y0; /*list<effects-and-types/row_vector>*/
  }
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x1_4786, _ctx);
    kk_box_t _x6648 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments_new_run__climate__model_fun6649(burnin, ind, name, t__steps, x_4773, diff, subtract, _ctx), _ctx); /*2*/
    kk_unit_unbox(_x6648);
  }
  else {
    kk_climate_dash_experiments__mlift4688_run__climate__model(burnin, x_4773, diff, ind, name, subtract, t__steps, x1_4786, _ctx);
  }
  return kk_unit_box(_x6628);
}
static kk_box_t kk_climate_dash_experiments_run__climate__model_fun6621(kk_function_t _fself, kk_box_t _b_5659, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__climate__model_fun6621__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__climate__model_fun6621__t*, _fself);
  kk_integer_t burnin = _self->burnin; /* int */
  kk_integer_t t__steps = _self->t__steps; /* int */
  kk_std_core_types__tuple2_ x_4773 = _self->x_4773; /* (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>) */
  kk_drop_match(_self, {kk_integer_dup(burnin);kk_integer_dup(t__steps);kk_std_core_types__tuple2__dup(x_4773);}, {}, _ctx)
  kk_std_core_types__tuple2_ _match_6210 = kk_std_core_types__tuple2__unbox(_b_5659, _ctx); /*(int, (double, double, string))*/;
  kk_box_t _box_x5618 = _match_6210.fst;
  kk_box_t _box_x5619 = _match_6210.snd;
  kk_integer_t ind = kk_integer_unbox(_box_x5618);
  kk_std_core_types__tuple3_ _pat20 = kk_std_core_types__tuple3__unbox(_box_x5619, NULL);
  kk_box_t _box_x5620 = _pat20.fst;
  kk_box_t _box_x5621 = _pat20.snd;
  kk_box_t _box_x5622 = _pat20.thd;
  double diff = kk_double_unbox(_box_x5620, NULL);
  double subtract = kk_double_unbox(_box_x5621, NULL);
  kk_string_t name = kk_string_unbox(_box_x5622);
  kk_integer_dup(ind);
  kk_string_dup(name);
  kk_std_core_types__tuple2__drop(_match_6210, _ctx);
  return kk_std_time_timer_print_elapsed(kk_climate_dash_experiments_new_run__climate__model_fun6627(burnin, ind, name, t__steps, x_4773, diff, subtract, _ctx), kk_std_core_types__new_None(_ctx), _ctx);
}
static kk_box_t kk_climate_dash_experiments_run__climate__model_fun6618(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__climate__model_fun6618__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__climate__model_fun6618__t*, _fself);
  kk_integer_t burnin = _self->burnin; /* int */
  kk_std_core__list pre__data = _self->pre__data; /* list<(double, double, string)> */
  kk_integer_t t__steps = _self->t__steps; /* int */
  kk_std_core_types__tuple2_ x_4773 = _self->x_4773; /* (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>) */
  kk_drop_match(_self, {kk_integer_dup(burnin);kk_std_core__list_dup(pre__data);kk_integer_dup(t__steps);kk_std_core_types__tuple2__dup(x_4773);}, {}, _ctx)
  kk_std_core__list _x6619;
  kk_std_core__list _b_5666_5657;
  kk_std_core__list _x6620 = kk_std_core__lift21053_list(kk_integer_from_small(0), kk_integer_from_small(11), kk_std_core__new_Nil(_ctx), _ctx); /*list<int>*/
  _b_5666_5657 = kk_std_core_zip(_x6620, pre__data, _ctx); /*list<(int, (double, double, string))>*/
  _x6619 = kk_std_core_map_5(_b_5666_5657, kk_climate_dash_experiments_new_run__climate__model_fun6621(burnin, t__steps, x_4773, _ctx), _ctx); /*list<2>*/
  return kk_std_core__list_box(_x6619, _ctx);
}
static kk_box_t kk_climate_dash_experiments_run__climate__model_fun6617(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__climate__model_fun6617__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__climate__model_fun6617__t*, _fself);
  kk_integer_t burnin = _self->burnin; /* int */
  kk_std_core__list pre__data = _self->pre__data; /* list<(double, double, string)> */
  kk_integer_t t__steps = _self->t__steps; /* int */
  kk_std_core_types__tuple2_ x_4773 = _self->x_4773; /* (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>) */
  kk_drop_match(_self, {kk_integer_dup(burnin);kk_std_core__list_dup(pre__data);kk_integer_dup(t__steps);kk_std_core_types__tuple2__dup(x_4773);}, {}, _ctx)
  return kk_handlers_random__sampler(kk_climate_dash_experiments_new_run__climate__model_fun6618(burnin, pre__data, t__steps, x_4773, _ctx), _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments_run__climate__model_fun6653__t {
  struct kk_function_s _base;
  kk_integer_t burnin;
  kk_std_core__list pre__data;
  kk_integer_t t__steps;
  kk_std_core_types__tuple2_ x_4773;
};
static kk_box_t kk_climate_dash_experiments_run__climate__model_fun6653(kk_function_t _fself, kk_box_t _b_5674, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__climate__model_fun6653(kk_integer_t burnin, kk_std_core__list pre__data, kk_integer_t t__steps, kk_std_core_types__tuple2_ x_4773, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__climate__model_fun6653__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__climate__model_fun6653__t, 6, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__climate__model_fun6653, kk_context());
  _self->burnin = burnin;
  _self->pre__data = pre__data;
  _self->t__steps = t__steps;
  _self->x_4773 = x_4773;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments_run__climate__model_fun6653(kk_function_t _fself, kk_box_t _b_5674, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__climate__model_fun6653__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__climate__model_fun6653__t*, _fself);
  kk_integer_t burnin = _self->burnin; /* int */
  kk_std_core__list pre__data = _self->pre__data; /* list<(double, double, string)> */
  kk_integer_t t__steps = _self->t__steps; /* int */
  kk_std_core_types__tuple2_ x_4773 = _self->x_4773; /* (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>) */
  kk_drop_match(_self, {kk_integer_dup(burnin);kk_std_core__list_dup(pre__data);kk_integer_dup(t__steps);kk_std_core_types__tuple2__dup(x_4773);}, {}, _ctx)
  kk_std_core__list _x6654;
  kk_std_core__list _x6655 = kk_std_core__list_unbox(_b_5674, _ctx); /*list<()>*/
  _x6654 = kk_climate_dash_experiments__mlift4689_run__climate__model(burnin, x_4773, pre__data, t__steps, _x6655, _ctx); /*list<()>*/
  return kk_std_core__list_box(_x6654, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments_run__climate__model_fun6659__t {
  struct kk_function_s _base;
  kk_integer_t burnin;
  kk_std_core__list pre__data;
  kk_integer_t t__steps;
  kk_std_core_types__tuple2_ x_4773;
};
static kk_box_t kk_climate_dash_experiments_run__climate__model_fun6659(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__climate__model_fun6659(kk_integer_t burnin, kk_std_core__list pre__data, kk_integer_t t__steps, kk_std_core_types__tuple2_ x_4773, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__climate__model_fun6659__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__climate__model_fun6659__t, 6, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__climate__model_fun6659, kk_context());
  _self->burnin = burnin;
  _self->pre__data = pre__data;
  _self->t__steps = t__steps;
  _self->x_4773 = x_4773;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments_run__climate__model_fun6660__t {
  struct kk_function_s _base;
  kk_integer_t burnin;
  kk_std_core__list pre__data;
  kk_integer_t t__steps;
  kk_std_core_types__tuple2_ x_4773;
};
static kk_box_t kk_climate_dash_experiments_run__climate__model_fun6660(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__climate__model_fun6660(kk_integer_t burnin, kk_std_core__list pre__data, kk_integer_t t__steps, kk_std_core_types__tuple2_ x_4773, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__climate__model_fun6660__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__climate__model_fun6660__t, 6, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__climate__model_fun6660, kk_context());
  _self->burnin = burnin;
  _self->pre__data = pre__data;
  _self->t__steps = t__steps;
  _self->x_4773 = x_4773;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments_run__climate__model_fun6663__t {
  struct kk_function_s _base;
  kk_integer_t burnin;
  kk_integer_t t__steps;
  kk_std_core_types__tuple2_ x_4773;
};
static kk_box_t kk_climate_dash_experiments_run__climate__model_fun6663(kk_function_t _fself, kk_box_t _b_5716, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__climate__model_fun6663(kk_integer_t burnin, kk_integer_t t__steps, kk_std_core_types__tuple2_ x_4773, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__climate__model_fun6663__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__climate__model_fun6663__t, 5, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__climate__model_fun6663, kk_context());
  _self->burnin = burnin;
  _self->t__steps = t__steps;
  _self->x_4773 = x_4773;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments_run__climate__model_fun6669__t {
  struct kk_function_s _base;
  kk_integer_t burnin;
  kk_integer_t ind0;
  kk_string_t name0;
  kk_integer_t t__steps;
  kk_std_core_types__tuple2_ x_4773;
  double diff0;
  double subtract0;
};
static kk_box_t kk_climate_dash_experiments_run__climate__model_fun6669(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__climate__model_fun6669(kk_integer_t burnin, kk_integer_t ind0, kk_string_t name0, kk_integer_t t__steps, kk_std_core_types__tuple2_ x_4773, double diff0, double subtract0, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__climate__model_fun6669__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__climate__model_fun6669__t, 7, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__climate__model_fun6669, kk_context());
  _self->burnin = burnin;
  _self->ind0 = ind0;
  _self->name0 = name0;
  _self->t__steps = t__steps;
  _self->x_4773 = x_4773;
  _self->diff0 = diff0;
  _self->subtract0 = subtract0;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments_run__climate__model_fun6689__t {
  struct kk_function_s _base;
  size_t i1_4800;
};
static kk_box_t kk_climate_dash_experiments_run__climate__model_fun6689(kk_function_t _fself, kk_function_t _b_5700, kk_box_t _b_5701, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__climate__model_fun6689(size_t i1_4800, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__climate__model_fun6689__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__climate__model_fun6689__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__climate__model_fun6689, kk_context());
  _self->i1_4800 = i1_4800;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments_run__climate__model_fun6689(kk_function_t _fself, kk_function_t _b_5700, kk_box_t _b_5701, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__climate__model_fun6689__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__climate__model_fun6689__t*, _fself);
  size_t i1_4800 = _self->i1_4800; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i1_4800, _b_5700, _b_5701, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments_run__climate__model_fun6691__t {
  struct kk_function_s _base;
  kk_integer_t burnin;
  kk_integer_t ind0;
  kk_string_t name0;
  kk_integer_t t__steps;
  kk_std_core_types__tuple2_ x_4773;
  double diff0;
  double subtract0;
};
static kk_box_t kk_climate_dash_experiments_run__climate__model_fun6691(kk_function_t _fself, kk_box_t _b_5711, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__climate__model_fun6691(kk_integer_t burnin, kk_integer_t ind0, kk_string_t name0, kk_integer_t t__steps, kk_std_core_types__tuple2_ x_4773, double diff0, double subtract0, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__climate__model_fun6691__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__climate__model_fun6691__t, 7, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__climate__model_fun6691, kk_context());
  _self->burnin = burnin;
  _self->ind0 = ind0;
  _self->name0 = name0;
  _self->t__steps = t__steps;
  _self->x_4773 = x_4773;
  _self->diff0 = diff0;
  _self->subtract0 = subtract0;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments_run__climate__model_fun6691(kk_function_t _fself, kk_box_t _b_5711, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__climate__model_fun6691__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__climate__model_fun6691__t*, _fself);
  kk_integer_t burnin = _self->burnin; /* int */
  kk_integer_t ind0 = _self->ind0; /* int */
  kk_string_t name0 = _self->name0; /* string */
  kk_integer_t t__steps = _self->t__steps; /* int */
  kk_std_core_types__tuple2_ x_4773 = _self->x_4773; /* (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>) */
  double diff0 = _self->diff0; /* double */
  double subtract0 = _self->subtract0; /* double */
  kk_drop_match(_self, {kk_integer_dup(burnin);kk_integer_dup(ind0);kk_string_dup(name0);kk_integer_dup(t__steps);kk_std_core_types__tuple2__dup(x_4773);;;}, {}, _ctx)
  kk_unit_t _x6692 = kk_Unit;
  kk_std_core__list _x6693 = kk_std_core__list_unbox(_b_5711, _ctx); /*list<effects-and-types/row_vector>*/
  kk_climate_dash_experiments__mlift4685_run__climate__model(burnin, x_4773, diff0, ind0, name0, subtract0, t__steps, _x6693, _ctx);
  return kk_unit_box(_x6692);
}
static kk_box_t kk_climate_dash_experiments_run__climate__model_fun6669(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__climate__model_fun6669__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__climate__model_fun6669__t*, _fself);
  kk_integer_t burnin = _self->burnin; /* int */
  kk_integer_t ind0 = _self->ind0; /* int */
  kk_string_t name0 = _self->name0; /* string */
  kk_integer_t t__steps = _self->t__steps; /* int */
  kk_std_core_types__tuple2_ x_4773 = _self->x_4773; /* (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>) */
  double diff0 = _self->diff0; /* double */
  double subtract0 = _self->subtract0; /* double */
  kk_drop_match(_self, {kk_integer_dup(burnin);kk_integer_dup(ind0);kk_string_dup(name0);kk_integer_dup(t__steps);kk_std_core_types__tuple2__dup(x_4773);;;}, {}, _ctx)
  kk_unit_t _x6670 = kk_Unit;
  kk_std_core__list x3_4797;
  size_t i1_4800 = ((size_t)0); /*std/core/hnd/ev-index*/;
  kk_evv_t w1 = kk_evv_swap_create1(i1_4800,kk_context()); /*std/core/hnd/evv<<exn,div,effects-and-types/sample,fsys,console,ndet,std/num/random/random>>*/;
  kk_std_core__list y1;
  kk_std_core_types__maybe _match_6207;
  kk_std_core__list _x6671;
  kk_box_t _box_x5680 = x_4773.fst;
  kk_box_t _box_x5681 = x_4773.snd;
  kk_std_core__list _x0 = kk_std_core__list_unbox(_box_x5681, NULL);
  kk_std_core__list_dup(_x0);
  _x6671 = _x0; /*list<list<effects-and-types/row_vector>>*/
  kk_integer_t _x6674 = kk_integer_dup(ind0); /*int*/
  _match_6207 = kk_std_core__lp__lb__rb__2_rp_(_x6671, _x6674, _ctx); /*maybe<1>*/
  if (kk_std_core_types__is_Nothing(_match_6207)) {
    kk_string_t message_2050;
    kk_string_t _x6675;
    kk_define_string_literal(, _s6676, 48, "ListIndexError: Invalid list indexing at index: ")
    _x6675 = kk_string_dup(_s6676); /*string*/
    kk_string_t _x6677;
    kk_integer_t _x6678 = kk_integer_dup(ind0); /*int*/
    _x6677 = kk_std_core_show(_x6678, _ctx); /*string*/
    message_2050 = kk_std_core__lp__plus__plus__1_rp_(_x6675, _x6677, _ctx); /*string*/
    kk_std_core__exception exn_215610;
    kk_std_core__exception_info _x6679;
    kk_std_core_types__optional _match_6209 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
    if (kk_std_core_types__is_Optional(_match_6209)) {
      kk_box_t _box_x5682 = _match_6209._cons.Optional.value;
      kk_std_core__exception_info _info_142790 = kk_std_core__exception_info_unbox(_box_x5682, NULL);
      kk_std_core__exception_info_dup(_info_142790);
      kk_std_core_types__optional_drop(_match_6209, _ctx);
      _x6679 = _info_142790; /*exception-info*/
      goto _match6680;
    }
    _x6679 = kk_std_core__new_ExnError(_ctx); /*exception-info*/
    _match6680: ;
    exn_215610 = kk_std_core__new_Exception(message_2050, _x6679, _ctx); /*exception*/
    kk_std_core_hnd__ev ev_215620;
    size_t _x6682 = ((size_t)0); /*size_t*/
    ev_215620 = kk_evv_at(_x6682,kk_context()); /*std/core/hnd/ev<.hnd-exn>*/
    kk_box_t _x6683;
    struct kk_std_core_hnd_Ev* _con6684 = kk_std_core_hnd__as_Ev(ev_215620);
    kk_std_core_hnd__marker m0 = _con6684->marker;
    kk_box_t _box_x5683 = _con6684->hnd;
    kk_std_core__hnd_exn h0 = kk_std_core__hnd_exn_unbox(_box_x5683, NULL);
    kk_std_core__hnd_exn_dup(h0);
    kk_std_core_hnd__clause1 _match_6208;
    struct kk_std_core__Hnd_exn* _con6686 = kk_std_core__as_Hnd_exn(h0);
    kk_std_core_hnd__clause1 except_throw_exn0 = _con6686->except_throw_exn;
    if (kk_std_core__hnd_exn_is_unique(h0)) {
      kk_std_core__hnd_exn_free(h0);
    }
    else {
      kk_std_core_hnd__clause1_dup(except_throw_exn0);
      kk_std_core__hnd_exn_decref(h0, _ctx);
    }
    _match_6208 = except_throw_exn0; /*forall<a> std/core/hnd/clause1<exception,a,.hnd-exn,7,8>*/
    kk_function_t _fun_unbox_x5687 = _match_6208.clause;
    _x6683 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x5687, (_fun_unbox_x5687, m0, ev_215620, kk_std_core__exception_box(exn_215610, _ctx), _ctx)); /*11*/
    y1 = kk_std_core__list_unbox(_x6683, _ctx); /*list<effects-and-types/row_vector>*/
  }
  else {
    kk_box_t _box_x5691 = _match_6207._cons.Just.value;
    kk_std_core__list x0 = kk_std_core__list_unbox(_box_x5691, NULL);
    kk_std_core__list_dup(x0);
    kk_std_core_types__maybe_drop(_match_6207, _ctx);
    y1 = x0; /*list<effects-and-types/row_vector>*/
  }
  kk_unit_t __w_l717_c90 = kk_Unit;
  kk_evv_set(w1,kk_context());
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(y1, _ctx);
    kk_box_t _x6688 = kk_std_core_hnd_yield_cont(kk_climate_dash_experiments_new_run__climate__model_fun6689(i1_4800, _ctx), _ctx); /*3*/
    x3_4797 = kk_std_core__list_unbox(_x6688, _ctx); /*list<effects-and-types/row_vector>*/
  }
  else {
    x3_4797 = y1; /*list<effects-and-types/row_vector>*/
  }
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x3_4797, _ctx);
    kk_box_t _x6690 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments_new_run__climate__model_fun6691(burnin, ind0, name0, t__steps, x_4773, diff0, subtract0, _ctx), _ctx); /*2*/
    kk_unit_unbox(_x6690);
  }
  else {
    kk_climate_dash_experiments__mlift4685_run__climate__model(burnin, x_4773, diff0, ind0, name0, subtract0, t__steps, x3_4797, _ctx);
  }
  return kk_unit_box(_x6670);
}
static kk_box_t kk_climate_dash_experiments_run__climate__model_fun6663(kk_function_t _fself, kk_box_t _b_5716, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__climate__model_fun6663__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__climate__model_fun6663__t*, _fself);
  kk_integer_t burnin = _self->burnin; /* int */
  kk_integer_t t__steps = _self->t__steps; /* int */
  kk_std_core_types__tuple2_ x_4773 = _self->x_4773; /* (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>) */
  kk_drop_match(_self, {kk_integer_dup(burnin);kk_integer_dup(t__steps);kk_std_core_types__tuple2__dup(x_4773);}, {}, _ctx)
  kk_std_core_types__tuple2_ _match_6204 = kk_std_core_types__tuple2__unbox(_b_5716, _ctx); /*(int, (double, double, string))*/;
  kk_box_t _box_x5675 = _match_6204.fst;
  kk_box_t _box_x5676 = _match_6204.snd;
  kk_integer_t ind0 = kk_integer_unbox(_box_x5675);
  kk_std_core_types__tuple3_ _pat400 = kk_std_core_types__tuple3__unbox(_box_x5676, NULL);
  kk_box_t _box_x5677 = _pat400.fst;
  kk_box_t _box_x5678 = _pat400.snd;
  kk_box_t _box_x5679 = _pat400.thd;
  double diff0 = kk_double_unbox(_box_x5677, NULL);
  double subtract0 = kk_double_unbox(_box_x5678, NULL);
  kk_string_t name0 = kk_string_unbox(_box_x5679);
  kk_integer_dup(ind0);
  kk_string_dup(name0);
  kk_std_core_types__tuple2__drop(_match_6204, _ctx);
  return kk_std_time_timer_print_elapsed(kk_climate_dash_experiments_new_run__climate__model_fun6669(burnin, ind0, name0, t__steps, x_4773, diff0, subtract0, _ctx), kk_std_core_types__new_None(_ctx), _ctx);
}
static kk_box_t kk_climate_dash_experiments_run__climate__model_fun6660(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__climate__model_fun6660__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__climate__model_fun6660__t*, _fself);
  kk_integer_t burnin = _self->burnin; /* int */
  kk_std_core__list pre__data = _self->pre__data; /* list<(double, double, string)> */
  kk_integer_t t__steps = _self->t__steps; /* int */
  kk_std_core_types__tuple2_ x_4773 = _self->x_4773; /* (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>) */
  kk_drop_match(_self, {kk_integer_dup(burnin);kk_std_core__list_dup(pre__data);kk_integer_dup(t__steps);kk_std_core_types__tuple2__dup(x_4773);}, {}, _ctx)
  kk_std_core__list _x6661;
  kk_std_core__list _b_5727_5714;
  kk_std_core__list _x6662 = kk_std_core__lift21053_list(kk_integer_from_small(0), kk_integer_from_small(11), kk_std_core__new_Nil(_ctx), _ctx); /*list<int>*/
  _b_5727_5714 = kk_std_core_zip(_x6662, pre__data, _ctx); /*list<(int, (double, double, string))>*/
  _x6661 = kk_std_core_map_5(_b_5727_5714, kk_climate_dash_experiments_new_run__climate__model_fun6663(burnin, t__steps, x_4773, _ctx), _ctx); /*list<2>*/
  return kk_std_core__list_box(_x6661, _ctx);
}
static kk_box_t kk_climate_dash_experiments_run__climate__model_fun6659(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__climate__model_fun6659__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__climate__model_fun6659__t*, _fself);
  kk_integer_t burnin = _self->burnin; /* int */
  kk_std_core__list pre__data = _self->pre__data; /* list<(double, double, string)> */
  kk_integer_t t__steps = _self->t__steps; /* int */
  kk_std_core_types__tuple2_ x_4773 = _self->x_4773; /* (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>) */
  kk_drop_match(_self, {kk_integer_dup(burnin);kk_std_core__list_dup(pre__data);kk_integer_dup(t__steps);kk_std_core_types__tuple2__dup(x_4773);}, {}, _ctx)
  return kk_handlers_random__sampler(kk_climate_dash_experiments_new_run__climate__model_fun6660(burnin, pre__data, t__steps, x_4773, _ctx), _ctx);
}

kk_std_core__list kk_climate_dash_experiments_run__climate__model(kk_integer_t pt, kk_integer_t rs, kk_integer_t sbrs, kk_integer_t t__steps, kk_integer_t burnin, kk_std_core_types__optional repeat__num, kk_context_t* _ctx) { /* (pt : int, rs : int, sbrs : int, t_steps : int, burnin : int, repeat_num : optional<int>) -> <pure,console,fsys,ndet,std/num/random/random> list<()> */ 
  kk_integer_drop(pt, _ctx);
  kk_std_core_types__optional_drop(repeat__num, _ctx);
  kk_integer_drop(rs, _ctx);
  kk_integer_drop(sbrs, _ctx);
  kk_std_core_types__tuple2_ x_4773;
  size_t i_4776 = ((size_t)0); /*std/core/hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_4776,kk_context()); /*std/core/hnd/evv<<div,exn,fsys,console,ndet,std/num/random/random>>*/;
  kk_std_core_types__tuple2_ y = kk_data_preprocessing_pre__process__data(_ctx); /*(list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>)*/;
  kk_unit_t __w_l683_c9 = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_std_core_types__tuple2__drop(y, _ctx);
    kk_box_t _x6569 = kk_std_core_hnd_yield_cont(kk_climate_dash_experiments_new_run__climate__model_fun6570(i_4776, _ctx), _ctx); /*3*/
    x_4773 = kk_std_core_types__tuple2__unbox(_x6569, _ctx); /*(list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>)*/
  }
  else {
    x_4773 = y; /*(list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>)*/
  }
  if (kk_yielding(kk_context())) {
    kk_std_core_types__tuple2__drop(x_4773, _ctx);
    kk_box_t _x6571 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments_new_run__climate__model_fun6572(burnin, t__steps, _ctx), _ctx); /*2*/
    return kk_std_core__list_unbox(_x6571, _ctx);
  }
  kk_std_core__list pre__data;
  kk_std_core_types__tuple3_ _b_5558_5556;
  kk_box_t _x6575;
  kk_string_t _x6576;
  kk_define_string_literal(, _s6577, 3, "jan")
  _x6576 = kk_string_dup(_s6577); /*string*/
  _x6575 = kk_string_box(_x6576); /*10*/
  _b_5558_5556 = kk_std_core_types__new_dash__lp__comma__comma__rp_(kk_double_box(0x1.4p3, _ctx), kk_double_box(-0x1.8p1, _ctx), _x6575, _ctx); /*(double, double, string)*/
  kk_std_core__list _b_5559_5557;
  kk_std_core_types__tuple3_ _b_5563_5554;
  kk_box_t _x6578;
  kk_string_t _x6579;
  kk_define_string_literal(, _s6580, 3, "feb")
  _x6579 = kk_string_dup(_s6580); /*string*/
  _x6578 = kk_string_box(_x6579); /*10*/
  _b_5563_5554 = kk_std_core_types__new_dash__lp__comma__comma__rp_(kk_double_box(0x1p3, _ctx), kk_double_box(-0x1p0, _ctx), _x6578, _ctx); /*(double, double, string)*/
  kk_std_core__list _b_5564_5555;
  kk_std_core_types__tuple3_ _b_5568_5552;
  kk_box_t _x6581;
  kk_string_t _x6582;
  kk_define_string_literal(, _s6583, 3, "mar")
  _x6582 = kk_string_dup(_s6583); /*string*/
  _x6581 = kk_string_box(_x6582); /*10*/
  _b_5568_5552 = kk_std_core_types__new_dash__lp__comma__comma__rp_(kk_double_box(0x1.cp2, _ctx), kk_double_box(0x1p0, _ctx), _x6581, _ctx); /*(double, double, string)*/
  kk_std_core__list _b_5569_5553;
  kk_std_core_types__tuple3_ _b_5573_5550;
  kk_box_t _x6584;
  kk_string_t _x6585;
  kk_define_string_literal(, _s6586, 3, "apr")
  _x6585 = kk_string_dup(_s6586); /*string*/
  _x6584 = kk_string_box(_x6585); /*10*/
  _b_5573_5550 = kk_std_core_types__new_dash__lp__comma__comma__rp_(kk_double_box(0x1.8p2, _ctx), kk_double_box(0x1.4p2, _ctx), _x6584, _ctx); /*(double, double, string)*/
  kk_std_core__list _b_5574_5551;
  kk_std_core_types__tuple3_ _b_5578_5548;
  kk_box_t _x6587;
  kk_string_t _x6588;
  kk_define_string_literal(, _s6589, 3, "may")
  _x6588 = kk_string_dup(_s6589); /*string*/
  _x6587 = kk_string_box(_x6588); /*10*/
  _b_5578_5548 = kk_std_core_types__new_dash__lp__comma__comma__rp_(kk_double_box(0x1p3, _ctx), kk_double_box(0x1.2p3, _ctx), _x6587, _ctx); /*(double, double, string)*/
  kk_std_core__list _b_5579_5549;
  kk_std_core_types__tuple3_ _b_5583_5546;
  kk_box_t _x6590;
  kk_string_t _x6591;
  kk_define_string_literal(, _s6592, 3, "jun")
  _x6591 = kk_string_dup(_s6592); /*string*/
  _x6590 = kk_string_box(_x6591); /*10*/
  _b_5583_5546 = kk_std_core_types__new_dash__lp__comma__comma__rp_(kk_double_box(0x1p3, _ctx), kk_double_box(0x1.4p3, _ctx), _x6590, _ctx); /*(double, double, string)*/
  kk_std_core__list _b_5584_5547;
  kk_std_core_types__tuple3_ _b_5588_5544;
  kk_box_t _x6593;
  kk_string_t _x6594;
  kk_define_string_literal(, _s6595, 3, "jul")
  _x6594 = kk_string_dup(_s6595); /*string*/
  _x6593 = kk_string_box(_x6594); /*10*/
  _b_5588_5544 = kk_std_core_types__new_dash__lp__comma__comma__rp_(kk_double_box(0x1.2p3, _ctx), kk_double_box(0x1.6p3, _ctx), _x6593, _ctx); /*(double, double, string)*/
  kk_std_core__list _b_5589_5545;
  kk_std_core_types__tuple3_ _b_5593_5542;
  kk_box_t _x6596;
  kk_string_t _x6597;
  kk_define_string_literal(, _s6598, 3, "aug")
  _x6597 = kk_string_dup(_s6598); /*string*/
  _x6596 = kk_string_box(_x6597); /*10*/
  _b_5593_5542 = kk_std_core_types__new_dash__lp__comma__comma__rp_(kk_double_box(0x1.8p2, _ctx), kk_double_box(0x1.6p3, _ctx), _x6596, _ctx); /*(double, double, string)*/
  kk_std_core__list _b_5594_5543;
  kk_std_core_types__tuple3_ _b_5598_5540;
  kk_box_t _x6599;
  kk_string_t _x6600;
  kk_define_string_literal(, _s6601, 3, "sep")
  _x6600 = kk_string_dup(_s6601); /*string*/
  _x6599 = kk_string_box(_x6600); /*10*/
  _b_5598_5540 = kk_std_core_types__new_dash__lp__comma__comma__rp_(kk_double_box(0x1.4p2, _ctx), kk_double_box(0x1.4p3, _ctx), _x6599, _ctx); /*(double, double, string)*/
  kk_std_core__list _b_5599_5541;
  kk_std_core_types__tuple3_ _b_5603_5538;
  kk_box_t _x6602;
  kk_string_t _x6603;
  kk_define_string_literal(, _s6604, 3, "oct")
  _x6603 = kk_string_dup(_s6604); /*string*/
  _x6602 = kk_string_box(_x6603); /*10*/
  _b_5603_5538 = kk_std_core_types__new_dash__lp__comma__comma__rp_(kk_double_box(0x1.2p3, _ctx), kk_double_box(0x1p0, _ctx), _x6602, _ctx); /*(double, double, string)*/
  kk_std_core__list _b_5604_5539;
  kk_std_core_types__tuple3_ _b_5608_5536;
  kk_box_t _x6605;
  kk_string_t _x6606;
  kk_define_string_literal(, _s6607, 3, "nov")
  _x6606 = kk_string_dup(_s6607); /*string*/
  _x6605 = kk_string_box(_x6606); /*10*/
  _b_5608_5536 = kk_std_core_types__new_dash__lp__comma__comma__rp_(kk_double_box(0x1.cp2, _ctx), kk_double_box(0x1p1, _ctx), _x6605, _ctx); /*(double, double, string)*/
  kk_std_core__list _b_5609_5537;
  kk_std_core_types__tuple3_ _b_5613_5534;
  kk_box_t _x6608;
  kk_string_t _x6609;
  kk_define_string_literal(, _s6610, 3, "dec")
  _x6609 = kk_string_dup(_s6610); /*string*/
  _x6608 = kk_string_box(_x6609); /*10*/
  _b_5613_5534 = kk_std_core_types__new_dash__lp__comma__comma__rp_(kk_double_box(0x1.8p2, _ctx), kk_double_box(-0x1p0, _ctx), _x6608, _ctx); /*(double, double, string)*/
  _b_5609_5537 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core_types__tuple3__box(_b_5613_5534, _ctx), kk_std_core__new_Nil(_ctx), _ctx); /*list<(double, double, string)>*/
  _b_5604_5539 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core_types__tuple3__box(_b_5608_5536, _ctx), _b_5609_5537, _ctx); /*list<(double, double, string)>*/
  _b_5599_5541 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core_types__tuple3__box(_b_5603_5538, _ctx), _b_5604_5539, _ctx); /*list<(double, double, string)>*/
  _b_5594_5543 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core_types__tuple3__box(_b_5598_5540, _ctx), _b_5599_5541, _ctx); /*list<(double, double, string)>*/
  _b_5589_5545 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core_types__tuple3__box(_b_5593_5542, _ctx), _b_5594_5543, _ctx); /*list<(double, double, string)>*/
  _b_5584_5547 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core_types__tuple3__box(_b_5588_5544, _ctx), _b_5589_5545, _ctx); /*list<(double, double, string)>*/
  _b_5579_5549 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core_types__tuple3__box(_b_5583_5546, _ctx), _b_5584_5547, _ctx); /*list<(double, double, string)>*/
  _b_5574_5551 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core_types__tuple3__box(_b_5578_5548, _ctx), _b_5579_5549, _ctx); /*list<(double, double, string)>*/
  _b_5569_5553 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core_types__tuple3__box(_b_5573_5550, _ctx), _b_5574_5551, _ctx); /*list<(double, double, string)>*/
  _b_5564_5555 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core_types__tuple3__box(_b_5568_5552, _ctx), _b_5569_5553, _ctx); /*list<(double, double, string)>*/
  _b_5559_5557 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core_types__tuple3__box(_b_5563_5554, _ctx), _b_5564_5555, _ctx); /*list<(double, double, string)>*/
  pre__data = kk_std_core__new_Cons(kk_reuse_null, kk_std_core_types__tuple3__box(_b_5558_5556, _ctx), _b_5559_5557, _ctx); /*list<(double, double, string)>*/
  kk_unit_t __ = kk_Unit;
  kk_string_t _x6611;
  kk_define_string_literal(, _s6612, 93, "Starting to run the climate model! Run with -O2 --showelapsed flag to improve execution time.")
  _x6611 = kk_string_dup(_s6612); /*string*/
  kk_std_core_printsln(_x6611, _ctx);
  kk_unit_t __0 = kk_Unit;
  kk_string_t _x6613;
  kk_define_string_literal(, _s6614, 39, "Beginning to start TMCMC experiment #1:")
  _x6613 = kk_string_dup(_s6614); /*string*/
  kk_std_core_printsln(_x6613, _ctx);
  kk_std_core__list x0_4781;
  kk_box_t _x6615;
  kk_function_t _x6616;
  kk_integer_dup(burnin);
  kk_std_core__list_dup(pre__data);
  kk_integer_dup(t__steps);
  kk_std_core_types__tuple2__dup(x_4773);
  _x6616 = kk_climate_dash_experiments_new_run__climate__model_fun6617(burnin, pre__data, t__steps, x_4773, _ctx); /*() -> <ndet,console|1> 0*/
  _x6615 = kk_std_time_timer_print_elapsed(_x6616, kk_std_core_types__new_None(_ctx), _ctx); /*0*/
  x0_4781 = kk_std_core__list_unbox(_x6615, _ctx); /*list<()>*/
  kk_std_core__list_drop(x0_4781, _ctx);
  if (kk_yielding(kk_context())) {
    kk_box_t _x6652 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments_new_run__climate__model_fun6653(burnin, pre__data, t__steps, x_4773, _ctx), _ctx); /*2*/
    return kk_std_core__list_unbox(_x6652, _ctx);
  }
  kk_unit_t __2 = kk_Unit;
  kk_string_t _x6656;
  kk_define_string_literal(, _s6657, 39, "Beginning to start TMCMC experiment #2:")
  _x6656 = kk_string_dup(_s6657); /*string*/
  kk_std_core_printsln(_x6656, _ctx);
  kk_box_t _x6658 = kk_std_time_timer_print_elapsed(kk_climate_dash_experiments_new_run__climate__model_fun6659(burnin, pre__data, t__steps, x_4773, _ctx), kk_std_core_types__new_None(_ctx), _ctx); /*0*/
  return kk_std_core__list_unbox(_x6658, _ctx);
}
 
// monadic lift

kk_unit_t kk_climate_dash_experiments__mlift4691_run__experiments(kk_integer_t i1, kk_std_core__list wild__10, kk_context_t* _ctx) { /* (i1 : int, wild_10 : list<(list<(list<double>, (double, double))>, tmcmc/trace<(double, double),<effects-and-types/sample,effects-and-types/score,div,console,ndet,exn,std/num/random/random>>)>) -> <console,div,ndet,effects-and-types/sample,exn,std/num/random/random> () */ 
  kk_std_core__list_drop(wild__10, _ctx);
  kk_unit_t __11 = kk_Unit;
  kk_string_t _x6694;
  kk_define_string_literal(, _s6695, 21, "Completed Trace MCMC!")
  _x6694 = kk_string_dup(_s6695); /*string*/
  kk_std_core_printsln(_x6694, _ctx);
  kk_unit_t __12 = kk_Unit;
  kk_string_t _x6696 = kk_string_empty(); /*string*/
  kk_std_core_printsln(_x6696, _ctx);
  kk_unit_t __13 = kk_Unit;
  kk_string_t _x6698;
  kk_define_string_literal(, _s6699, 37, ".....................................")
  _x6698 = kk_string_dup(_s6699); /*string*/
  kk_std_core_printsln(_x6698, _ctx);
  kk_unit_t __14 = kk_Unit;
  kk_string_t s2_4807;
  kk_string_t _x6700;
  kk_define_string_literal(, _s6701, 17, "Completed Round #")
  _x6700 = kk_string_dup(_s6701); /*string*/
  kk_string_t _x6702 = kk_std_core_show(i1, _ctx); /*string*/
  s2_4807 = kk_std_core__lp__plus__plus__1_rp_(_x6700, _x6702, _ctx); /*string*/
  kk_std_core_printsln(s2_4807, _ctx);
  kk_unit_t __15 = kk_Unit;
  kk_string_t _x6703;
  kk_define_string_literal(, _s6704, 37, ".....................................")
  _x6703 = kk_string_dup(_s6704); /*string*/
  kk_std_core_printsln(_x6703, _ctx);
  kk_unit_t __16 = kk_Unit;
  kk_string_t _x6705 = kk_string_empty(); /*string*/
  kk_std_core_printsln(_x6705, _ctx);
  kk_unit_t __17 = kk_Unit;
  kk_string_t _x6707 = kk_string_empty(); /*string*/
  kk_std_core_printsln(_x6707, _ctx);
  kk_unit_t __18 = kk_Unit;
  kk_string_t _x6709 = kk_string_empty(); /*string*/
  kk_std_core_printsln(_x6709, _ctx);
  kk_string_t _x6711 = kk_string_empty(); /*string*/
  kk_std_core_printsln(_x6711, _ctx); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_climate_dash_experiments__mlift4692_run__experiments_fun6717__t {
  struct kk_function_s _base;
  kk_std_core__list data__50;
};
static kk_box_t kk_climate_dash_experiments__mlift4692_run__experiments_fun6717(kk_function_t _fself, kk_box_t _b_5759, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift4692_run__experiments_fun6717(kk_std_core__list data__50, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4692_run__experiments_fun6717__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift4692_run__experiments_fun6717__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift4692_run__experiments_fun6717, kk_context());
  _self->data__50 = data__50;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift4692_run__experiments_fun6720__t {
  struct kk_function_s _base;
  kk_std_core__list data__50;
  kk_integer_t sz1;
};
static kk_box_t kk_climate_dash_experiments__mlift4692_run__experiments_fun6720(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift4692_run__experiments_fun6720(kk_std_core__list data__50, kk_integer_t sz1, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4692_run__experiments_fun6720__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift4692_run__experiments_fun6720__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift4692_run__experiments_fun6720, kk_context());
  _self->data__50 = data__50;
  _self->sz1 = sz1;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift4692_run__experiments_fun6723__t {
  struct kk_function_s _base;
};
static kk_box_t kk_climate_dash_experiments__mlift4692_run__experiments_fun6723(kk_function_t _fself, kk_box_t _b_5738, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift4692_run__experiments_fun6723(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_climate_dash_experiments__mlift4692_run__experiments_fun6723, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift4692_run__experiments_fun6726__t {
  struct kk_function_s _base;
  kk_function_t _bv_5740;
};
static kk_box_t kk_climate_dash_experiments__mlift4692_run__experiments_fun6726(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift4692_run__experiments_fun6726(kk_function_t _bv_5740, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4692_run__experiments_fun6726__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift4692_run__experiments_fun6726__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift4692_run__experiments_fun6726, kk_context());
  _self->_bv_5740 = _bv_5740;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift4692_run__experiments_fun6726(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4692_run__experiments_fun6726__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift4692_run__experiments_fun6726__t*, _fself);
  kk_function_t _bv_5740 = _self->_bv_5740; /* effects-and-types/model<(double, double),div> */
  kk_drop_match(_self, {kk_function_dup(_bv_5740);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x6727 = kk_function_call(kk_std_core_types__tuple2_, (kk_function_t, kk_context_t*), _bv_5740, (_bv_5740, _ctx)); /*(double, double)*/
  return kk_std_core_types__tuple2__box(_x6727, _ctx);
}
static kk_box_t kk_climate_dash_experiments__mlift4692_run__experiments_fun6723(kk_function_t _fself, kk_box_t _b_5738, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_function_t _x6724;
  kk_function_t _bv_5740;
  kk_std_core__list _x6725 = kk_std_core__list_unbox(_b_5738, _ctx); /*list<(double, bool)>*/
  _bv_5740 = kk_model_dash_resources_logistic__regression(_x6725, _ctx); /*effects-and-types/model<(double, double),div>*/
  _x6724 = kk_climate_dash_experiments__new_mlift4692_run__experiments_fun6726(_bv_5740, _ctx); /*() -> <effects-and-types/sample,effects-and-types/score,div> 5739*/
  return kk_function_box(_x6724);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift4692_run__experiments_fun6728__t {
  struct kk_function_s _base;
  kk_function_t _bv_5742;
};
static kk_std_core_types__tuple2_ kk_climate_dash_experiments__mlift4692_run__experiments_fun6728(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift4692_run__experiments_fun6728(kk_function_t _bv_5742, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4692_run__experiments_fun6728__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift4692_run__experiments_fun6728__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift4692_run__experiments_fun6728, kk_context());
  _self->_bv_5742 = _bv_5742;
  return &_self->_base;
}

static kk_std_core_types__tuple2_ kk_climate_dash_experiments__mlift4692_run__experiments_fun6728(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4692_run__experiments_fun6728__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift4692_run__experiments_fun6728__t*, _fself);
  kk_function_t _bv_5742 = _self->_bv_5742; /* () -> <.Box|.Box> 5741 */
  kk_drop_match(_self, {kk_function_dup(_bv_5742);}, {}, _ctx)
  kk_box_t _x6729 = kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), _bv_5742, (_bv_5742, _ctx)); /*5741*/
  return kk_std_core_types__tuple2__unbox(_x6729, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift4692_run__experiments_fun6730__t {
  struct kk_function_s _base;
  kk_function_t _x07_4681;
};
static kk_std_core_types__tuple2_ kk_climate_dash_experiments__mlift4692_run__experiments_fun6730(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift4692_run__experiments_fun6730(kk_function_t _x07_4681, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4692_run__experiments_fun6730__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift4692_run__experiments_fun6730__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift4692_run__experiments_fun6730, kk_context());
  _self->_x07_4681 = _x07_4681;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift4692_run__experiments_fun6733__t {
  struct kk_function_s _base;
  kk_function_t _x07_4681;
};
static kk_box_t kk_climate_dash_experiments__mlift4692_run__experiments_fun6733(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift4692_run__experiments_fun6733(kk_function_t _x07_4681, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4692_run__experiments_fun6733__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift4692_run__experiments_fun6733__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift4692_run__experiments_fun6733, kk_context());
  _self->_x07_4681 = _x07_4681;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift4692_run__experiments_fun6733(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4692_run__experiments_fun6733__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift4692_run__experiments_fun6733__t*, _fself);
  kk_function_t _x07_4681 = _self->_x07_4681; /* effects-and-types/model<(double, double),div> */
  kk_drop_match(_self, {kk_function_dup(_x07_4681);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x6734 = kk_function_call(kk_std_core_types__tuple2_, (kk_function_t, kk_context_t*), _x07_4681, (_x07_4681, _ctx)); /*(double, double)*/
  return kk_std_core_types__tuple2__box(_x6734, _ctx);
}
static kk_std_core_types__tuple2_ kk_climate_dash_experiments__mlift4692_run__experiments_fun6730(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4692_run__experiments_fun6730__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift4692_run__experiments_fun6730__t*, _fself);
  kk_function_t _x07_4681 = _self->_x07_4681; /* effects-and-types/model<(double, double),div> */
  kk_drop_match(_self, {kk_function_dup(_x07_4681);}, {}, _ctx)
  kk_vector_t _b_5769_5749;
  kk_std_core__list _x6731;
  size_t _b_5771_5747 = ((size_t)2); /*std/core/hnd/ev-index*/;
  kk_std_core__list _b_5772_5748;
  size_t _b_5773_5745 = ((size_t)3); /*std/core/hnd/ev-index*/;
  _b_5772_5748 = kk_std_core__new_Cons(kk_reuse_null, kk_size_box(_b_5773_5745, _ctx), kk_std_core__new_Nil(_ctx), _ctx); /*list<std/core/hnd/ev-index>*/
  _x6731 = kk_std_core__new_Cons(kk_reuse_null, kk_size_box(_b_5771_5747, _ctx), _b_5772_5748, _ctx); /*list<0>*/
  _b_5769_5749 = kk_std_core_unvlist(_x6731, _ctx); /*vector<std/core/hnd/ev-index>*/
  kk_box_t _x6732 = kk_std_core_hnd__open0(_b_5769_5749, kk_climate_dash_experiments__new_mlift4692_run__experiments_fun6733(_x07_4681, _ctx), _ctx); /*1*/
  return kk_std_core_types__tuple2__unbox(_x6732, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift4692_run__experiments_fun6735__t {
  struct kk_function_s _base;
  kk_function_t _b_5765_5751;
};
static kk_box_t kk_climate_dash_experiments__mlift4692_run__experiments_fun6735(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift4692_run__experiments_fun6735(kk_function_t _b_5765_5751, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4692_run__experiments_fun6735__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift4692_run__experiments_fun6735__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift4692_run__experiments_fun6735, kk_context());
  _self->_b_5765_5751 = _b_5765_5751;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift4692_run__experiments_fun6735(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4692_run__experiments_fun6735__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift4692_run__experiments_fun6735__t*, _fself);
  kk_function_t _b_5765_5751 = _self->_b_5765_5751; /* () -> <effects-and-types/sample,effects-and-types/score,div> (double, double) */
  kk_drop_match(_self, {kk_function_dup(_b_5765_5751);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x6736 = kk_function_call(kk_std_core_types__tuple2_, (kk_function_t, kk_context_t*), _b_5765_5751, (_b_5765_5751, _ctx)); /*(double, double)*/
  return kk_std_core_types__tuple2__box(_x6736, _ctx);
}
static kk_box_t kk_climate_dash_experiments__mlift4692_run__experiments_fun6720(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4692_run__experiments_fun6720__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift4692_run__experiments_fun6720__t*, _fself);
  kk_std_core__list data__50 = _self->data__50; /* list<(double, bool)> */
  kk_integer_t sz1 = _self->sz1; /* int */
  kk_drop_match(_self, {kk_std_core__list_dup(data__50);kk_integer_dup(sz1);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x6721;
  kk_function_t _b_5765_5751;
  kk_function_t _x07_4681;
  kk_function_t _bv_5742;
  kk_box_t _x6722 = kk_std_core_hnd__open_none1(kk_climate_dash_experiments__new_mlift4692_run__experiments_fun6723(_ctx), kk_std_core__list_box(data__50, _ctx), _ctx); /*2*/
  _bv_5742 = kk_function_unbox(_x6722); /*() -> <.Box|.Box> 5741*/
  _x07_4681 = kk_climate_dash_experiments__new_mlift4692_run__experiments_fun6728(_bv_5742, _ctx); /*effects-and-types/model<(double, double),div>*/
  _b_5765_5751 = kk_climate_dash_experiments__new_mlift4692_run__experiments_fun6730(_x07_4681, _ctx); /*() -> <effects-and-types/sample,effects-and-types/score,div> (double, double)*/
  kk_effects_dash_and_dash_types__exp _b_5767_5753 = kk_effects_dash_and_dash_types__new_Exp(0x0p+0, _ctx); /*effects-and-types/exp*/;
  _x6721 = kk_tmcmc_tmcmc(kk_climate_dash_experiments__new_mlift4692_run__experiments_fun6735(_b_5765_5751, _ctx), sz1, _b_5767_5753, kk_integer_from_small(0), _ctx); /*(list<(list<double>, 0)>, tmcmc/trace<0,<effects-and-types/sample,effects-and-types/score,div|1>>)*/
  return kk_std_core_types__tuple2__box(_x6721, _ctx);
}
static kk_box_t kk_climate_dash_experiments__mlift4692_run__experiments_fun6717(kk_function_t _fself, kk_box_t _b_5759, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4692_run__experiments_fun6717__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift4692_run__experiments_fun6717__t*, _fself);
  kk_std_core__list data__50 = _self->data__50; /* list<(double, bool)> */
  kk_drop_match(_self, {kk_std_core__list_dup(data__50);}, {}, _ctx)
  kk_std_core_types__tuple2_ _match_6201 = kk_std_core_types__tuple2__unbox(_b_5759, _ctx); /*(int, list<(double, bool)>)*/;
  kk_box_t _box_x5734 = _match_6201.fst;
  kk_box_t _box_x5735 = _match_6201.snd;
  kk_integer_t sz1 = kk_integer_unbox(_box_x5734);
  kk_integer_dup(sz1);
  kk_std_core_types__tuple2__drop(_match_6201, _ctx);
  return kk_std_time_timer_print_elapsed(kk_climate_dash_experiments__new_mlift4692_run__experiments_fun6720(data__50, sz1, _ctx), kk_std_core_types__new_None(_ctx), _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift4692_run__experiments_fun6738__t {
  struct kk_function_s _base;
  kk_integer_t i1;
};
static kk_box_t kk_climate_dash_experiments__mlift4692_run__experiments_fun6738(kk_function_t _fself, kk_box_t _b_5776, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift4692_run__experiments_fun6738(kk_integer_t i1, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4692_run__experiments_fun6738__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift4692_run__experiments_fun6738__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift4692_run__experiments_fun6738, kk_context());
  _self->i1 = i1;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift4692_run__experiments_fun6738(kk_function_t _fself, kk_box_t _b_5776, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4692_run__experiments_fun6738__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift4692_run__experiments_fun6738__t*, _fself);
  kk_integer_t i1 = _self->i1; /* int */
  kk_drop_match(_self, {kk_integer_dup(i1);}, {}, _ctx)
  kk_unit_t _x6739 = kk_Unit;
  kk_std_core__list _x6740 = kk_std_core__list_unbox(_b_5776, _ctx); /*list<(list<(list<double>, (double, double))>, tmcmc/trace<(double, double),<effects-and-types/sample,effects-and-types/score,div,console,ndet,exn,std/num/random/random>>)>*/
  kk_climate_dash_experiments__mlift4691_run__experiments(i1, _x6740, _ctx);
  return kk_unit_box(_x6739);
}

kk_unit_t kk_climate_dash_experiments__mlift4692_run__experiments(kk_std_core__list data__50, kk_std_core__list data__points, kk_integer_t i1, kk_std_core__list wild__7, kk_context_t* _ctx) { /* (data_50 : list<(double, bool)>, data_points : list<(int, list<(double, bool)>)>, i1 : int, wild_7 : list<(list<(list<double>, (double, double))>, tmcmc/trace<(double, double),<effects-and-types/sample,effects-and-types/score,div,console,ndet,exn,std/num/random/random>>)>) -> <console,div,ndet,effects-and-types/sample,exn,std/num/random/random> () */ 
  kk_std_core__list_drop(wild__7, _ctx);
  kk_unit_t __8 = kk_Unit;
  kk_string_t _x6713;
  kk_define_string_literal(, _s6714, 18, "Mid-way with TMCMC")
  _x6713 = kk_string_dup(_s6714); /*string*/
  kk_std_core_printsln(_x6713, _ctx);
  kk_unit_t __9 = kk_Unit;
  kk_string_t _x6715;
  kk_define_string_literal(, _s6716, 46, "Running TMCMC with increasing number of steps:")
  _x6715 = kk_string_dup(_s6716); /*string*/
  kk_std_core_printsln(_x6715, _ctx);
  kk_std_core__list x_4815 = kk_std_core_map_5(data__points, kk_climate_dash_experiments__new_mlift4692_run__experiments_fun6717(data__50, _ctx), _ctx); /*list<(list<(list<double>, (double, double))>, tmcmc/trace<(double, double),<effects-and-types/sample,effects-and-types/score,div,console,ndet,exn,std/num/random/random>>)>*/;
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_4815, _ctx);
    kk_box_t _x6737 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments__new_mlift4692_run__experiments_fun6738(i1, _ctx), _ctx); /*2*/
    kk_unit_unbox(_x6737); return kk_Unit;
  }
  kk_climate_dash_experiments__mlift4691_run__experiments(i1, x_4815, _ctx); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_climate_dash_experiments__mlift4693_run__experiments_fun6746__t {
  struct kk_function_s _base;
};
static kk_box_t kk_climate_dash_experiments__mlift4693_run__experiments_fun6746(kk_function_t _fself, kk_box_t _b_5804, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift4693_run__experiments_fun6746(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_climate_dash_experiments__mlift4693_run__experiments_fun6746, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift4693_run__experiments_fun6749__t {
  struct kk_function_s _base;
  kk_std_core__list data__vals0;
};
static kk_box_t kk_climate_dash_experiments__mlift4693_run__experiments_fun6749(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift4693_run__experiments_fun6749(kk_std_core__list data__vals0, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4693_run__experiments_fun6749__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift4693_run__experiments_fun6749__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift4693_run__experiments_fun6749, kk_context());
  _self->data__vals0 = data__vals0;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift4693_run__experiments_fun6752__t {
  struct kk_function_s _base;
};
static kk_box_t kk_climate_dash_experiments__mlift4693_run__experiments_fun6752(kk_function_t _fself, kk_box_t _b_5783, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift4693_run__experiments_fun6752(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_climate_dash_experiments__mlift4693_run__experiments_fun6752, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift4693_run__experiments_fun6755__t {
  struct kk_function_s _base;
  kk_function_t _bv_5785;
};
static kk_box_t kk_climate_dash_experiments__mlift4693_run__experiments_fun6755(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift4693_run__experiments_fun6755(kk_function_t _bv_5785, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4693_run__experiments_fun6755__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift4693_run__experiments_fun6755__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift4693_run__experiments_fun6755, kk_context());
  _self->_bv_5785 = _bv_5785;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift4693_run__experiments_fun6755(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4693_run__experiments_fun6755__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift4693_run__experiments_fun6755__t*, _fself);
  kk_function_t _bv_5785 = _self->_bv_5785; /* effects-and-types/model<(double, double),div> */
  kk_drop_match(_self, {kk_function_dup(_bv_5785);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x6756 = kk_function_call(kk_std_core_types__tuple2_, (kk_function_t, kk_context_t*), _bv_5785, (_bv_5785, _ctx)); /*(double, double)*/
  return kk_std_core_types__tuple2__box(_x6756, _ctx);
}
static kk_box_t kk_climate_dash_experiments__mlift4693_run__experiments_fun6752(kk_function_t _fself, kk_box_t _b_5783, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_function_t _x6753;
  kk_function_t _bv_5785;
  kk_std_core__list _x6754 = kk_std_core__list_unbox(_b_5783, _ctx); /*list<(double, bool)>*/
  _bv_5785 = kk_model_dash_resources_logistic__regression(_x6754, _ctx); /*effects-and-types/model<(double, double),div>*/
  _x6753 = kk_climate_dash_experiments__new_mlift4693_run__experiments_fun6755(_bv_5785, _ctx); /*() -> <effects-and-types/sample,effects-and-types/score,div> 5784*/
  return kk_function_box(_x6753);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift4693_run__experiments_fun6757__t {
  struct kk_function_s _base;
  kk_function_t _bv_5787;
};
static kk_std_core_types__tuple2_ kk_climate_dash_experiments__mlift4693_run__experiments_fun6757(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift4693_run__experiments_fun6757(kk_function_t _bv_5787, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4693_run__experiments_fun6757__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift4693_run__experiments_fun6757__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift4693_run__experiments_fun6757, kk_context());
  _self->_bv_5787 = _bv_5787;
  return &_self->_base;
}

static kk_std_core_types__tuple2_ kk_climate_dash_experiments__mlift4693_run__experiments_fun6757(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4693_run__experiments_fun6757__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift4693_run__experiments_fun6757__t*, _fself);
  kk_function_t _bv_5787 = _self->_bv_5787; /* () -> <.Box|.Box> 5786 */
  kk_drop_match(_self, {kk_function_dup(_bv_5787);}, {}, _ctx)
  kk_box_t _x6758 = kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), _bv_5787, (_bv_5787, _ctx)); /*5786*/
  return kk_std_core_types__tuple2__unbox(_x6758, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift4693_run__experiments_fun6759__t {
  struct kk_function_s _base;
  kk_function_t _x05_4679;
};
static kk_std_core_types__tuple2_ kk_climate_dash_experiments__mlift4693_run__experiments_fun6759(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift4693_run__experiments_fun6759(kk_function_t _x05_4679, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4693_run__experiments_fun6759__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift4693_run__experiments_fun6759__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift4693_run__experiments_fun6759, kk_context());
  _self->_x05_4679 = _x05_4679;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift4693_run__experiments_fun6762__t {
  struct kk_function_s _base;
  kk_function_t _x05_4679;
};
static kk_box_t kk_climate_dash_experiments__mlift4693_run__experiments_fun6762(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift4693_run__experiments_fun6762(kk_function_t _x05_4679, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4693_run__experiments_fun6762__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift4693_run__experiments_fun6762__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift4693_run__experiments_fun6762, kk_context());
  _self->_x05_4679 = _x05_4679;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift4693_run__experiments_fun6762(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4693_run__experiments_fun6762__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift4693_run__experiments_fun6762__t*, _fself);
  kk_function_t _x05_4679 = _self->_x05_4679; /* effects-and-types/model<(double, double),div> */
  kk_drop_match(_self, {kk_function_dup(_x05_4679);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x6763 = kk_function_call(kk_std_core_types__tuple2_, (kk_function_t, kk_context_t*), _x05_4679, (_x05_4679, _ctx)); /*(double, double)*/
  return kk_std_core_types__tuple2__box(_x6763, _ctx);
}
static kk_std_core_types__tuple2_ kk_climate_dash_experiments__mlift4693_run__experiments_fun6759(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4693_run__experiments_fun6759__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift4693_run__experiments_fun6759__t*, _fself);
  kk_function_t _x05_4679 = _self->_x05_4679; /* effects-and-types/model<(double, double),div> */
  kk_drop_match(_self, {kk_function_dup(_x05_4679);}, {}, _ctx)
  kk_vector_t _b_5814_5794;
  kk_std_core__list _x6760;
  size_t _b_5816_5792 = ((size_t)2); /*std/core/hnd/ev-index*/;
  kk_std_core__list _b_5817_5793;
  size_t _b_5818_5790 = ((size_t)3); /*std/core/hnd/ev-index*/;
  _b_5817_5793 = kk_std_core__new_Cons(kk_reuse_null, kk_size_box(_b_5818_5790, _ctx), kk_std_core__new_Nil(_ctx), _ctx); /*list<std/core/hnd/ev-index>*/
  _x6760 = kk_std_core__new_Cons(kk_reuse_null, kk_size_box(_b_5816_5792, _ctx), _b_5817_5793, _ctx); /*list<0>*/
  _b_5814_5794 = kk_std_core_unvlist(_x6760, _ctx); /*vector<std/core/hnd/ev-index>*/
  kk_box_t _x6761 = kk_std_core_hnd__open0(_b_5814_5794, kk_climate_dash_experiments__new_mlift4693_run__experiments_fun6762(_x05_4679, _ctx), _ctx); /*1*/
  return kk_std_core_types__tuple2__unbox(_x6761, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift4693_run__experiments_fun6764__t {
  struct kk_function_s _base;
  kk_function_t _b_5810_5796;
};
static kk_box_t kk_climate_dash_experiments__mlift4693_run__experiments_fun6764(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift4693_run__experiments_fun6764(kk_function_t _b_5810_5796, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4693_run__experiments_fun6764__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift4693_run__experiments_fun6764__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift4693_run__experiments_fun6764, kk_context());
  _self->_b_5810_5796 = _b_5810_5796;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift4693_run__experiments_fun6764(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4693_run__experiments_fun6764__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift4693_run__experiments_fun6764__t*, _fself);
  kk_function_t _b_5810_5796 = _self->_b_5810_5796; /* () -> <effects-and-types/sample,effects-and-types/score,div> (double, double) */
  kk_drop_match(_self, {kk_function_dup(_b_5810_5796);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x6765 = kk_function_call(kk_std_core_types__tuple2_, (kk_function_t, kk_context_t*), _b_5810_5796, (_b_5810_5796, _ctx)); /*(double, double)*/
  return kk_std_core_types__tuple2__box(_x6765, _ctx);
}
static kk_box_t kk_climate_dash_experiments__mlift4693_run__experiments_fun6749(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4693_run__experiments_fun6749__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift4693_run__experiments_fun6749__t*, _fself);
  kk_std_core__list data__vals0 = _self->data__vals0; /* list<(double, bool)> */
  kk_drop_match(_self, {kk_std_core__list_dup(data__vals0);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x6750;
  kk_function_t _b_5810_5796;
  kk_function_t _x05_4679;
  kk_function_t _bv_5787;
  kk_box_t _x6751 = kk_std_core_hnd__open_none1(kk_climate_dash_experiments__new_mlift4693_run__experiments_fun6752(_ctx), kk_std_core__list_box(data__vals0, _ctx), _ctx); /*2*/
  _bv_5787 = kk_function_unbox(_x6751); /*() -> <.Box|.Box> 5786*/
  _x05_4679 = kk_climate_dash_experiments__new_mlift4693_run__experiments_fun6757(_bv_5787, _ctx); /*effects-and-types/model<(double, double),div>*/
  _b_5810_5796 = kk_climate_dash_experiments__new_mlift4693_run__experiments_fun6759(_x05_4679, _ctx); /*() -> <effects-and-types/sample,effects-and-types/score,div> (double, double)*/
  kk_effects_dash_and_dash_types__exp _b_5812_5798 = kk_effects_dash_and_dash_types__new_Exp(0x0p+0, _ctx); /*effects-and-types/exp*/;
  _x6750 = kk_tmcmc_tmcmc(kk_climate_dash_experiments__new_mlift4693_run__experiments_fun6764(_b_5810_5796, _ctx), kk_integer_from_small(100), _b_5812_5798, kk_integer_from_small(0), _ctx); /*(list<(list<double>, 0)>, tmcmc/trace<0,<effects-and-types/sample,effects-and-types/score,div|1>>)*/
  return kk_std_core_types__tuple2__box(_x6750, _ctx);
}
static kk_box_t kk_climate_dash_experiments__mlift4693_run__experiments_fun6746(kk_function_t _fself, kk_box_t _b_5804, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core_types__tuple2_ _match_6199 = kk_std_core_types__tuple2__unbox(_b_5804, _ctx); /*(int, list<(double, bool)>)*/;
  kk_box_t _box_x5779 = _match_6199.fst;
  kk_box_t _box_x5780 = _match_6199.snd;
  kk_std_core__list data__vals0 = kk_std_core__list_unbox(_box_x5780, NULL);
  kk_std_core__list_dup(data__vals0);
  kk_std_core_types__tuple2__drop(_match_6199, _ctx);
  return kk_std_time_timer_print_elapsed(kk_climate_dash_experiments__new_mlift4693_run__experiments_fun6749(data__vals0, _ctx), kk_std_core_types__new_None(_ctx), _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift4693_run__experiments_fun6767__t {
  struct kk_function_s _base;
  kk_std_core__list data__50;
  kk_std_core__list data__points;
  kk_integer_t i1;
};
static kk_box_t kk_climate_dash_experiments__mlift4693_run__experiments_fun6767(kk_function_t _fself, kk_box_t _b_5821, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift4693_run__experiments_fun6767(kk_std_core__list data__50, kk_std_core__list data__points, kk_integer_t i1, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4693_run__experiments_fun6767__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift4693_run__experiments_fun6767__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift4693_run__experiments_fun6767, kk_context());
  _self->data__50 = data__50;
  _self->data__points = data__points;
  _self->i1 = i1;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift4693_run__experiments_fun6767(kk_function_t _fself, kk_box_t _b_5821, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4693_run__experiments_fun6767__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift4693_run__experiments_fun6767__t*, _fself);
  kk_std_core__list data__50 = _self->data__50; /* list<(double, bool)> */
  kk_std_core__list data__points = _self->data__points; /* list<(int, list<(double, bool)>)> */
  kk_integer_t i1 = _self->i1; /* int */
  kk_drop_match(_self, {kk_std_core__list_dup(data__50);kk_std_core__list_dup(data__points);kk_integer_dup(i1);}, {}, _ctx)
  kk_unit_t _x6768 = kk_Unit;
  kk_std_core__list _x6769 = kk_std_core__list_unbox(_b_5821, _ctx); /*list<(list<(list<double>, (double, double))>, tmcmc/trace<(double, double),<effects-and-types/sample,effects-and-types/score,div,console,ndet,exn,std/num/random/random>>)>*/
  kk_climate_dash_experiments__mlift4692_run__experiments(data__50, data__points, i1, _x6769, _ctx);
  return kk_unit_box(_x6768);
}

kk_unit_t kk_climate_dash_experiments__mlift4693_run__experiments(kk_std_core__list data__50, kk_std_core__list data__points, kk_integer_t i1, kk_std_core__list wild__4, kk_context_t* _ctx) { /* (data_50 : list<(double, bool)>, data_points : list<(int, list<(double, bool)>)>, i1 : int, wild_4 : list<effects-and-types/histogram<(double, double)>>) -> <console,div,exn,ndet,std/num/random/random,effects-and-types/sample> () */ 
  kk_std_core__list_drop(wild__4, _ctx);
  kk_unit_t __5 = kk_Unit;
  kk_string_t _x6741;
  kk_define_string_literal(, _s6742, 14, "Completed SMC!")
  _x6741 = kk_string_dup(_s6742); /*string*/
  kk_std_core_printsln(_x6741, _ctx);
  kk_unit_t __6 = kk_Unit;
  kk_string_t _x6743;
  kk_define_string_literal(, _s6744, 40, "Running TMCMC with increasing data size:")
  _x6743 = kk_string_dup(_s6744); /*string*/
  kk_std_core_printsln(_x6743, _ctx);
  kk_std_core__list x_4819;
  kk_std_core__list _x6745 = kk_std_core__list_dup(data__points); /*list<(int, list<(double, bool)>)>*/
  x_4819 = kk_std_core_map_5(_x6745, kk_climate_dash_experiments__new_mlift4693_run__experiments_fun6746(_ctx), _ctx); /*list<(list<(list<double>, (double, double))>, tmcmc/trace<(double, double),<effects-and-types/sample,effects-and-types/score,div,console,ndet,exn,std/num/random/random>>)>*/
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_4819, _ctx);
    kk_box_t _x6766 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments__new_mlift4693_run__experiments_fun6767(data__50, data__points, i1, _ctx), _ctx); /*2*/
    kk_unit_unbox(_x6766); return kk_Unit;
  }
  kk_climate_dash_experiments__mlift4692_run__experiments(data__50, data__points, i1, x_4819, _ctx); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_climate_dash_experiments__mlift4694_run__experiments_fun6776__t {
  struct kk_function_s _base;
  kk_std_core__list data__50;
};
static kk_box_t kk_climate_dash_experiments__mlift4694_run__experiments_fun6776(kk_function_t _fself, kk_box_t _b_5868, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift4694_run__experiments_fun6776(kk_std_core__list data__50, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4694_run__experiments_fun6776__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift4694_run__experiments_fun6776__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift4694_run__experiments_fun6776, kk_context());
  _self->data__50 = data__50;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift4694_run__experiments_fun6779__t {
  struct kk_function_s _base;
  kk_std_core__list data__50;
  kk_integer_t sz0;
};
static kk_box_t kk_climate_dash_experiments__mlift4694_run__experiments_fun6779(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift4694_run__experiments_fun6779(kk_std_core__list data__50, kk_integer_t sz0, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4694_run__experiments_fun6779__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift4694_run__experiments_fun6779__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift4694_run__experiments_fun6779, kk_context());
  _self->data__50 = data__50;
  _self->sz0 = sz0;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift4694_run__experiments_fun6782__t {
  struct kk_function_s _base;
};
static kk_box_t kk_climate_dash_experiments__mlift4694_run__experiments_fun6782(kk_function_t _fself, kk_box_t _b_5828, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift4694_run__experiments_fun6782(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_climate_dash_experiments__mlift4694_run__experiments_fun6782, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift4694_run__experiments_fun6785__t {
  struct kk_function_s _base;
  kk_function_t _bv_5830;
};
static kk_box_t kk_climate_dash_experiments__mlift4694_run__experiments_fun6785(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift4694_run__experiments_fun6785(kk_function_t _bv_5830, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4694_run__experiments_fun6785__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift4694_run__experiments_fun6785__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift4694_run__experiments_fun6785, kk_context());
  _self->_bv_5830 = _bv_5830;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift4694_run__experiments_fun6785(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4694_run__experiments_fun6785__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift4694_run__experiments_fun6785__t*, _fself);
  kk_function_t _bv_5830 = _self->_bv_5830; /* effects-and-types/model<(double, double),div> */
  kk_drop_match(_self, {kk_function_dup(_bv_5830);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x6786 = kk_function_call(kk_std_core_types__tuple2_, (kk_function_t, kk_context_t*), _bv_5830, (_bv_5830, _ctx)); /*(double, double)*/
  return kk_std_core_types__tuple2__box(_x6786, _ctx);
}
static kk_box_t kk_climate_dash_experiments__mlift4694_run__experiments_fun6782(kk_function_t _fself, kk_box_t _b_5828, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_function_t _x6783;
  kk_function_t _bv_5830;
  kk_std_core__list _x6784 = kk_std_core__list_unbox(_b_5828, _ctx); /*list<(double, bool)>*/
  _bv_5830 = kk_model_dash_resources_logistic__regression(_x6784, _ctx); /*effects-and-types/model<(double, double),div>*/
  _x6783 = kk_climate_dash_experiments__new_mlift4694_run__experiments_fun6785(_bv_5830, _ctx); /*() -> <effects-and-types/sample,effects-and-types/score,div> 5829*/
  return kk_function_box(_x6783);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift4694_run__experiments_fun6787__t {
  struct kk_function_s _base;
  kk_function_t _bv_5832;
};
static kk_std_core_types__tuple2_ kk_climate_dash_experiments__mlift4694_run__experiments_fun6787(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift4694_run__experiments_fun6787(kk_function_t _bv_5832, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4694_run__experiments_fun6787__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift4694_run__experiments_fun6787__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift4694_run__experiments_fun6787, kk_context());
  _self->_bv_5832 = _bv_5832;
  return &_self->_base;
}

static kk_std_core_types__tuple2_ kk_climate_dash_experiments__mlift4694_run__experiments_fun6787(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4694_run__experiments_fun6787__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift4694_run__experiments_fun6787__t*, _fself);
  kk_function_t _bv_5832 = _self->_bv_5832; /* () -> <.Box|.Box> 5831 */
  kk_drop_match(_self, {kk_function_dup(_bv_5832);}, {}, _ctx)
  kk_box_t _x6788 = kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), _bv_5832, (_bv_5832, _ctx)); /*5831*/
  return kk_std_core_types__tuple2__unbox(_x6788, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift4694_run__experiments_fun6789__t {
  struct kk_function_s _base;
  kk_function_t _x03_4677;
};
static kk_std_core_types__tuple2_ kk_climate_dash_experiments__mlift4694_run__experiments_fun6789(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift4694_run__experiments_fun6789(kk_function_t _x03_4677, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4694_run__experiments_fun6789__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift4694_run__experiments_fun6789__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift4694_run__experiments_fun6789, kk_context());
  _self->_x03_4677 = _x03_4677;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift4694_run__experiments_fun6792__t {
  struct kk_function_s _base;
  kk_function_t _x03_4677;
};
static kk_box_t kk_climate_dash_experiments__mlift4694_run__experiments_fun6792(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift4694_run__experiments_fun6792(kk_function_t _x03_4677, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4694_run__experiments_fun6792__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift4694_run__experiments_fun6792__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift4694_run__experiments_fun6792, kk_context());
  _self->_x03_4677 = _x03_4677;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift4694_run__experiments_fun6792(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4694_run__experiments_fun6792__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift4694_run__experiments_fun6792__t*, _fself);
  kk_function_t _x03_4677 = _self->_x03_4677; /* effects-and-types/model<(double, double),div> */
  kk_drop_match(_self, {kk_function_dup(_x03_4677);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x6793 = kk_function_call(kk_std_core_types__tuple2_, (kk_function_t, kk_context_t*), _x03_4677, (_x03_4677, _ctx)); /*(double, double)*/
  return kk_std_core_types__tuple2__box(_x6793, _ctx);
}
static kk_std_core_types__tuple2_ kk_climate_dash_experiments__mlift4694_run__experiments_fun6789(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4694_run__experiments_fun6789__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift4694_run__experiments_fun6789__t*, _fself);
  kk_function_t _x03_4677 = _self->_x03_4677; /* effects-and-types/model<(double, double),div> */
  kk_drop_match(_self, {kk_function_dup(_x03_4677);}, {}, _ctx)
  kk_vector_t _b_5841_5839;
  kk_std_core__list _x6790;
  size_t _b_5843_5837 = ((size_t)2); /*std/core/hnd/ev-index*/;
  kk_std_core__list _b_5844_5838;
  size_t _b_5845_5835 = ((size_t)4); /*std/core/hnd/ev-index*/;
  _b_5844_5838 = kk_std_core__new_Cons(kk_reuse_null, kk_size_box(_b_5845_5835, _ctx), kk_std_core__new_Nil(_ctx), _ctx); /*list<std/core/hnd/ev-index>*/
  _x6790 = kk_std_core__new_Cons(kk_reuse_null, kk_size_box(_b_5843_5837, _ctx), _b_5844_5838, _ctx); /*list<0>*/
  _b_5841_5839 = kk_std_core_unvlist(_x6790, _ctx); /*vector<std/core/hnd/ev-index>*/
  kk_box_t _x6791 = kk_std_core_hnd__open0(_b_5841_5839, kk_climate_dash_experiments__new_mlift4694_run__experiments_fun6792(_x03_4677, _ctx), _ctx); /*1*/
  return kk_std_core_types__tuple2__unbox(_x6791, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift4694_run__experiments_fun6795__t {
  struct kk_function_s _base;
  kk_function_t model_4828;
  kk_integer_t sz0;
};
static kk_box_t kk_climate_dash_experiments__mlift4694_run__experiments_fun6795(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift4694_run__experiments_fun6795(kk_function_t model_4828, kk_integer_t sz0, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4694_run__experiments_fun6795__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift4694_run__experiments_fun6795__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift4694_run__experiments_fun6795, kk_context());
  _self->model_4828 = model_4828;
  _self->sz0 = sz0;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift4694_run__experiments_fun6797__t {
  struct kk_function_s _base;
  kk_function_t model_4828;
};
static kk_box_t kk_climate_dash_experiments__mlift4694_run__experiments_fun6797(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift4694_run__experiments_fun6797(kk_function_t model_4828, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4694_run__experiments_fun6797__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift4694_run__experiments_fun6797__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift4694_run__experiments_fun6797, kk_context());
  _self->model_4828 = model_4828;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift4694_run__experiments_fun6799__t {
  struct kk_function_s _base;
  kk_function_t model_4828;
};
static kk_box_t kk_climate_dash_experiments__mlift4694_run__experiments_fun6799(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift4694_run__experiments_fun6799(kk_function_t model_4828, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4694_run__experiments_fun6799__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift4694_run__experiments_fun6799__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift4694_run__experiments_fun6799, kk_context());
  _self->model_4828 = model_4828;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift4694_run__experiments_fun6800__t {
  struct kk_function_s _base;
  kk_function_t model_4828;
};
static kk_box_t kk_climate_dash_experiments__mlift4694_run__experiments_fun6800(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift4694_run__experiments_fun6800(kk_function_t model_4828, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4694_run__experiments_fun6800__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift4694_run__experiments_fun6800__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift4694_run__experiments_fun6800, kk_context());
  _self->model_4828 = model_4828;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift4694_run__experiments_fun6800(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4694_run__experiments_fun6800__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift4694_run__experiments_fun6800__t*, _fself);
  kk_function_t model_4828 = _self->model_4828; /* () -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random,console,ndet,effects-and-types/sample> (double, double) */
  kk_drop_match(_self, {kk_function_dup(model_4828);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x6801 = kk_function_call(kk_std_core_types__tuple2_, (kk_function_t, kk_context_t*), model_4828, (model_4828, _ctx)); /*(double, double)*/
  return kk_std_core_types__tuple2__box(_x6801, _ctx);
}
static kk_box_t kk_climate_dash_experiments__mlift4694_run__experiments_fun6799(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4694_run__experiments_fun6799__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift4694_run__experiments_fun6799__t*, _fself);
  kk_function_t model_4828 = _self->model_4828; /* () -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random,console,ndet,effects-and-types/sample> (double, double) */
  kk_drop_match(_self, {kk_function_dup(model_4828);}, {}, _ctx)
  return kk_handlers_yield__on__score(kk_climate_dash_experiments__new_mlift4694_run__experiments_fun6800(model_4828, _ctx), _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift4694_run__experiments_fun6802__t {
  struct kk_function_s _base;
  kk_function_t _bv_5849;
};
static kk_std_core_types__tuple2_ kk_climate_dash_experiments__mlift4694_run__experiments_fun6802(kk_function_t _fself, kk_integer_t _b_5850, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift4694_run__experiments_fun6802(kk_function_t _bv_5849, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4694_run__experiments_fun6802__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift4694_run__experiments_fun6802__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift4694_run__experiments_fun6802, kk_context());
  _self->_bv_5849 = _bv_5849;
  return &_self->_base;
}

static kk_std_core_types__tuple2_ kk_climate_dash_experiments__mlift4694_run__experiments_fun6802(kk_function_t _fself, kk_integer_t _b_5850, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4694_run__experiments_fun6802__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift4694_run__experiments_fun6802__t*, _fself);
  kk_function_t _bv_5849 = _self->_bv_5849; /* (steps : int) -> <effects-and-types/yield|1> 0 */
  kk_drop_match(_self, {kk_function_dup(_bv_5849);}, {}, _ctx)
  kk_box_t _x6803 = kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_context_t*), _bv_5849, (_bv_5849, _b_5850, _ctx)); /*0*/
  return kk_std_core_types__tuple2__unbox(_x6803, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift4694_run__experiments_fun6804__t {
  struct kk_function_s _base;
  kk_function_t _bv_5855;
};
static kk_box_t kk_climate_dash_experiments__mlift4694_run__experiments_fun6804(kk_function_t _fself, kk_box_t _b_5856, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift4694_run__experiments_fun6804(kk_function_t _bv_5855, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4694_run__experiments_fun6804__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift4694_run__experiments_fun6804__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift4694_run__experiments_fun6804, kk_context());
  _self->_bv_5855 = _bv_5855;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift4694_run__experiments_fun6804(kk_function_t _fself, kk_box_t _b_5856, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4694_run__experiments_fun6804__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift4694_run__experiments_fun6804__t*, _fself);
  kk_function_t _bv_5855 = _self->_bv_5855; /* (steps : int) -> <effects-and-types/yield,effects-and-types/sample,effects-and-types/score,div,exn,std/num/random/random,console,ndet,effects-and-types/sample> (double, double) */
  kk_drop_match(_self, {kk_function_dup(_bv_5855);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x6805;
  kk_integer_t _x6806 = kk_integer_unbox(_b_5856); /*int*/
  _x6805 = kk_function_call(kk_std_core_types__tuple2_, (kk_function_t, kk_integer_t, kk_context_t*), _bv_5855, (_bv_5855, _x6806, _ctx)); /*(double, double)*/
  return kk_std_core_types__tuple2__box(_x6805, _ctx);
}
static kk_box_t kk_climate_dash_experiments__mlift4694_run__experiments_fun6797(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4694_run__experiments_fun6797__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift4694_run__experiments_fun6797__t*, _fself);
  kk_function_t model_4828 = _self->model_4828; /* () -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random,console,ndet,effects-and-types/sample> (double, double) */
  kk_drop_match(_self, {kk_function_dup(model_4828);}, {}, _ctx)
  kk_function_t _x6798;
  kk_function_t _bv_5855;
  kk_function_t _bv_5849 = kk_handlers_advance(kk_climate_dash_experiments__new_mlift4694_run__experiments_fun6799(model_4828, _ctx), _ctx); /*(steps : int) -> <effects-and-types/yield|1> 0*/;
  _bv_5855 = kk_climate_dash_experiments__new_mlift4694_run__experiments_fun6802(_bv_5849, _ctx); /*(steps : int) -> <effects-and-types/yield,effects-and-types/sample,effects-and-types/score,div,exn,std/num/random/random,console,ndet,effects-and-types/sample> (double, double)*/
  _x6798 = kk_climate_dash_experiments__new_mlift4694_run__experiments_fun6804(_bv_5855, _ctx); /*(5853) -> <effects-and-types/yield,effects-and-types/sample,effects-and-types/score,div,exn,std/num/random/random,console,ndet,effects-and-types/sample> 5854*/
  return kk_function_box(_x6798);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift4694_run__experiments_fun6808__t {
  struct kk_function_s _base;
};
static kk_box_t kk_climate_dash_experiments__mlift4694_run__experiments_fun6808(kk_function_t _fself, kk_box_t _b_5862, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift4694_run__experiments_fun6808(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_climate_dash_experiments__mlift4694_run__experiments_fun6808, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_climate_dash_experiments__mlift4694_run__experiments_fun6808(kk_function_t _fself, kk_box_t _b_5862, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core__list _x6809;
  kk_std_core__list _x6810 = kk_std_core__list_unbox(_b_5862, _ctx); /*effects-and-types/histogram<(steps : int) -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random,console,ndet,effects-and-types/sample> (double, double)>*/
  _x6809 = kk_smc__mlift512_smc(true, kk_integer_from_small(1), kk_integer_from_small(50), _x6810, _ctx); /*effects-and-types/histogram<1>*/
  return kk_std_core__list_box(_x6809, _ctx);
}
static kk_box_t kk_climate_dash_experiments__mlift4694_run__experiments_fun6795(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4694_run__experiments_fun6795__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift4694_run__experiments_fun6795__t*, _fself);
  kk_function_t model_4828 = _self->model_4828; /* () -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random,console,ndet,effects-and-types/sample> (double, double) */
  kk_integer_t sz0 = _self->sz0; /* int */
  kk_drop_match(_self, {kk_function_dup(model_4828);kk_integer_dup(sz0);}, {}, _ctx)
  kk_std_core__list _x6796;
  kk_std_core__list x_538 = kk_sampling_populate(sz0, kk_climate_dash_experiments__new_mlift4694_run__experiments_fun6797(model_4828, _ctx), _ctx); /*effects-and-types/histogram<(steps : int) -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random,console,ndet,effects-and-types/sample> (double, double)>*/;
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_538, _ctx);
    kk_box_t _x6807 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments__new_mlift4694_run__experiments_fun6808(_ctx), _ctx); /*2*/
    _x6796 = kk_std_core__list_unbox(_x6807, _ctx); /*effects-and-types/histogram<(double, double)>*/
  }
  else {
    _x6796 = kk_smc__mlift512_smc(true, kk_integer_from_small(1), kk_integer_from_small(50), x_538, _ctx); /*effects-and-types/histogram<(double, double)>*/
  }
  return kk_std_core__list_box(_x6796, _ctx);
}
static kk_box_t kk_climate_dash_experiments__mlift4694_run__experiments_fun6779(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4694_run__experiments_fun6779__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift4694_run__experiments_fun6779__t*, _fself);
  kk_std_core__list data__50 = _self->data__50; /* list<(double, bool)> */
  kk_integer_t sz0 = _self->sz0; /* int */
  kk_drop_match(_self, {kk_std_core__list_dup(data__50);kk_integer_dup(sz0);}, {}, _ctx)
  kk_std_core__list _x6780;
  kk_function_t model_4828;
  kk_function_t _x03_4677;
  kk_function_t _bv_5832;
  kk_box_t _x6781 = kk_std_core_hnd__open_none1(kk_climate_dash_experiments__new_mlift4694_run__experiments_fun6782(_ctx), kk_std_core__list_box(data__50, _ctx), _ctx); /*2*/
  _bv_5832 = kk_function_unbox(_x6781); /*() -> <.Box|.Box> 5831*/
  _x03_4677 = kk_climate_dash_experiments__new_mlift4694_run__experiments_fun6787(_bv_5832, _ctx); /*effects-and-types/model<(double, double),div>*/
  model_4828 = kk_climate_dash_experiments__new_mlift4694_run__experiments_fun6789(_x03_4677, _ctx); /*() -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random,console,ndet,effects-and-types/sample> (double, double)*/
  kk_box_t _x6794 = kk_handlers_random__sampler(kk_climate_dash_experiments__new_mlift4694_run__experiments_fun6795(model_4828, sz0, _ctx), _ctx); /*0*/
  _x6780 = kk_std_core__list_unbox(_x6794, _ctx); /*effects-and-types/histogram<(double, double)>*/
  return kk_std_core__list_box(_x6780, _ctx);
}
static kk_box_t kk_climate_dash_experiments__mlift4694_run__experiments_fun6776(kk_function_t _fself, kk_box_t _b_5868, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4694_run__experiments_fun6776__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift4694_run__experiments_fun6776__t*, _fself);
  kk_std_core__list data__50 = _self->data__50; /* list<(double, bool)> */
  kk_drop_match(_self, {kk_std_core__list_dup(data__50);}, {}, _ctx)
  kk_std_core_types__tuple2_ _match_6196 = kk_std_core_types__tuple2__unbox(_b_5868, _ctx); /*(int, list<(double, bool)>)*/;
  kk_box_t _box_x5824 = _match_6196.fst;
  kk_box_t _box_x5825 = _match_6196.snd;
  kk_integer_t sz0 = kk_integer_unbox(_box_x5824);
  kk_integer_dup(sz0);
  kk_std_core_types__tuple2__drop(_match_6196, _ctx);
  return kk_std_time_timer_print_elapsed(kk_climate_dash_experiments__new_mlift4694_run__experiments_fun6779(data__50, sz0, _ctx), kk_std_core_types__new_None(_ctx), _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift4694_run__experiments_fun6812__t {
  struct kk_function_s _base;
  kk_std_core__list data__50;
  kk_std_core__list data__points;
  kk_integer_t i1;
};
static kk_box_t kk_climate_dash_experiments__mlift4694_run__experiments_fun6812(kk_function_t _fself, kk_box_t _b_5878, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift4694_run__experiments_fun6812(kk_std_core__list data__50, kk_std_core__list data__points, kk_integer_t i1, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4694_run__experiments_fun6812__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift4694_run__experiments_fun6812__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift4694_run__experiments_fun6812, kk_context());
  _self->data__50 = data__50;
  _self->data__points = data__points;
  _self->i1 = i1;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift4694_run__experiments_fun6812(kk_function_t _fself, kk_box_t _b_5878, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4694_run__experiments_fun6812__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift4694_run__experiments_fun6812__t*, _fself);
  kk_std_core__list data__50 = _self->data__50; /* list<(double, bool)> */
  kk_std_core__list data__points = _self->data__points; /* list<(int, list<(double, bool)>)> */
  kk_integer_t i1 = _self->i1; /* int */
  kk_drop_match(_self, {kk_std_core__list_dup(data__50);kk_std_core__list_dup(data__points);kk_integer_dup(i1);}, {}, _ctx)
  kk_unit_t _x6813 = kk_Unit;
  kk_std_core__list _x6814 = kk_std_core__list_unbox(_b_5878, _ctx); /*list<effects-and-types/histogram<(double, double)>>*/
  kk_climate_dash_experiments__mlift4693_run__experiments(data__50, data__points, i1, _x6814, _ctx);
  return kk_unit_box(_x6813);
}

kk_unit_t kk_climate_dash_experiments__mlift4694_run__experiments(kk_std_core__list data__50, kk_std_core__list data__points, kk_integer_t i1, kk_std_core__list wild__1, kk_context_t* _ctx) { /* (data_50 : list<(double, bool)>, data_points : list<(int, list<(double, bool)>)>, i1 : int, wild_1 : list<effects-and-types/histogram<(double, double)>>) -> <console,div,exn,ndet,std/num/random/random,effects-and-types/sample> () */ 
  kk_std_core__list_drop(wild__1, _ctx);
  kk_unit_t __2 = kk_Unit;
  kk_string_t _x6770;
  kk_define_string_literal(, _s6771, 16, "Mid-way with SMC")
  _x6770 = kk_string_dup(_s6771); /*string*/
  kk_std_core_printsln(_x6770, _ctx);
  kk_unit_t __3 = kk_Unit;
  kk_string_t _x6772;
  kk_define_string_literal(, _s6773, 48, "Running SMC with increasing number of particles:")
  _x6772 = kk_string_dup(_s6773); /*string*/
  kk_std_core_printsln(_x6772, _ctx);
  kk_std_core__list x_4823;
  kk_std_core__list _x6774 = kk_std_core__list_dup(data__points); /*list<(int, list<(double, bool)>)>*/
  kk_function_t _x6775;
  kk_std_core__list_dup(data__50);
  _x6775 = kk_climate_dash_experiments__new_mlift4694_run__experiments_fun6776(data__50, _ctx); /*(1) -> 3 0*/
  x_4823 = kk_std_core_map_5(_x6774, _x6775, _ctx); /*list<effects-and-types/histogram<(double, double)>>*/
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_4823, _ctx);
    kk_box_t _x6811 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments__new_mlift4694_run__experiments_fun6812(data__50, data__points, i1, _ctx), _ctx); /*2*/
    kk_unit_unbox(_x6811); return kk_Unit;
  }
  kk_climate_dash_experiments__mlift4693_run__experiments(data__50, data__points, i1, x_4823, _ctx); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_climate_dash_experiments__mlift4695_run__experiments_fun6815__t {
  struct kk_function_s _base;
  kk_std_core__list data__50;
  kk_std_core__list data__points;
};
static kk_unit_t kk_climate_dash_experiments__mlift4695_run__experiments_fun6815(kk_function_t _fself, kk_integer_t i1, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift4695_run__experiments_fun6815(kk_std_core__list data__50, kk_std_core__list data__points, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4695_run__experiments_fun6815__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift4695_run__experiments_fun6815__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift4695_run__experiments_fun6815, kk_context());
  _self->data__50 = data__50;
  _self->data__points = data__points;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift4695_run__experiments_fun6823__t {
  struct kk_function_s _base;
};
static kk_box_t kk_climate_dash_experiments__mlift4695_run__experiments_fun6823(kk_function_t _fself, kk_box_t _b_5925, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift4695_run__experiments_fun6823(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_climate_dash_experiments__mlift4695_run__experiments_fun6823, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift4695_run__experiments_fun6826__t {
  struct kk_function_s _base;
  kk_std_core__list data__vals;
  kk_integer_t sz;
};
static kk_box_t kk_climate_dash_experiments__mlift4695_run__experiments_fun6826(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift4695_run__experiments_fun6826(kk_std_core__list data__vals, kk_integer_t sz, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4695_run__experiments_fun6826__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift4695_run__experiments_fun6826__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift4695_run__experiments_fun6826, kk_context());
  _self->data__vals = data__vals;
  _self->sz = sz;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift4695_run__experiments_fun6829__t {
  struct kk_function_s _base;
};
static kk_box_t kk_climate_dash_experiments__mlift4695_run__experiments_fun6829(kk_function_t _fself, kk_box_t _b_5885, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift4695_run__experiments_fun6829(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_climate_dash_experiments__mlift4695_run__experiments_fun6829, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift4695_run__experiments_fun6832__t {
  struct kk_function_s _base;
  kk_function_t _bv_5887;
};
static kk_box_t kk_climate_dash_experiments__mlift4695_run__experiments_fun6832(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift4695_run__experiments_fun6832(kk_function_t _bv_5887, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4695_run__experiments_fun6832__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift4695_run__experiments_fun6832__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift4695_run__experiments_fun6832, kk_context());
  _self->_bv_5887 = _bv_5887;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift4695_run__experiments_fun6832(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4695_run__experiments_fun6832__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift4695_run__experiments_fun6832__t*, _fself);
  kk_function_t _bv_5887 = _self->_bv_5887; /* effects-and-types/model<(double, double),div> */
  kk_drop_match(_self, {kk_function_dup(_bv_5887);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x6833 = kk_function_call(kk_std_core_types__tuple2_, (kk_function_t, kk_context_t*), _bv_5887, (_bv_5887, _ctx)); /*(double, double)*/
  return kk_std_core_types__tuple2__box(_x6833, _ctx);
}
static kk_box_t kk_climate_dash_experiments__mlift4695_run__experiments_fun6829(kk_function_t _fself, kk_box_t _b_5885, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_function_t _x6830;
  kk_function_t _bv_5887;
  kk_std_core__list _x6831 = kk_std_core__list_unbox(_b_5885, _ctx); /*list<(double, bool)>*/
  _bv_5887 = kk_model_dash_resources_logistic__regression(_x6831, _ctx); /*effects-and-types/model<(double, double),div>*/
  _x6830 = kk_climate_dash_experiments__new_mlift4695_run__experiments_fun6832(_bv_5887, _ctx); /*() -> <effects-and-types/sample,effects-and-types/score,div> 5886*/
  return kk_function_box(_x6830);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift4695_run__experiments_fun6834__t {
  struct kk_function_s _base;
  kk_function_t _bv_5889;
};
static kk_std_core_types__tuple2_ kk_climate_dash_experiments__mlift4695_run__experiments_fun6834(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift4695_run__experiments_fun6834(kk_function_t _bv_5889, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4695_run__experiments_fun6834__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift4695_run__experiments_fun6834__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift4695_run__experiments_fun6834, kk_context());
  _self->_bv_5889 = _bv_5889;
  return &_self->_base;
}

static kk_std_core_types__tuple2_ kk_climate_dash_experiments__mlift4695_run__experiments_fun6834(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4695_run__experiments_fun6834__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift4695_run__experiments_fun6834__t*, _fself);
  kk_function_t _bv_5889 = _self->_bv_5889; /* () -> <.Box|.Box> 5888 */
  kk_drop_match(_self, {kk_function_dup(_bv_5889);}, {}, _ctx)
  kk_box_t _x6835 = kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), _bv_5889, (_bv_5889, _ctx)); /*5888*/
  return kk_std_core_types__tuple2__unbox(_x6835, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift4695_run__experiments_fun6836__t {
  struct kk_function_s _base;
  kk_function_t _x01_4675;
};
static kk_std_core_types__tuple2_ kk_climate_dash_experiments__mlift4695_run__experiments_fun6836(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift4695_run__experiments_fun6836(kk_function_t _x01_4675, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4695_run__experiments_fun6836__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift4695_run__experiments_fun6836__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift4695_run__experiments_fun6836, kk_context());
  _self->_x01_4675 = _x01_4675;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift4695_run__experiments_fun6839__t {
  struct kk_function_s _base;
  kk_function_t _x01_4675;
};
static kk_box_t kk_climate_dash_experiments__mlift4695_run__experiments_fun6839(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift4695_run__experiments_fun6839(kk_function_t _x01_4675, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4695_run__experiments_fun6839__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift4695_run__experiments_fun6839__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift4695_run__experiments_fun6839, kk_context());
  _self->_x01_4675 = _x01_4675;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift4695_run__experiments_fun6839(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4695_run__experiments_fun6839__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift4695_run__experiments_fun6839__t*, _fself);
  kk_function_t _x01_4675 = _self->_x01_4675; /* effects-and-types/model<(double, double),div> */
  kk_drop_match(_self, {kk_function_dup(_x01_4675);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x6840 = kk_function_call(kk_std_core_types__tuple2_, (kk_function_t, kk_context_t*), _x01_4675, (_x01_4675, _ctx)); /*(double, double)*/
  return kk_std_core_types__tuple2__box(_x6840, _ctx);
}
static kk_std_core_types__tuple2_ kk_climate_dash_experiments__mlift4695_run__experiments_fun6836(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4695_run__experiments_fun6836__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift4695_run__experiments_fun6836__t*, _fself);
  kk_function_t _x01_4675 = _self->_x01_4675; /* effects-and-types/model<(double, double),div> */
  kk_drop_match(_self, {kk_function_dup(_x01_4675);}, {}, _ctx)
  kk_vector_t _b_5898_5896;
  kk_std_core__list _x6837;
  size_t _b_5900_5894 = ((size_t)2); /*std/core/hnd/ev-index*/;
  kk_std_core__list _b_5901_5895;
  size_t _b_5902_5892 = ((size_t)4); /*std/core/hnd/ev-index*/;
  _b_5901_5895 = kk_std_core__new_Cons(kk_reuse_null, kk_size_box(_b_5902_5892, _ctx), kk_std_core__new_Nil(_ctx), _ctx); /*list<std/core/hnd/ev-index>*/
  _x6837 = kk_std_core__new_Cons(kk_reuse_null, kk_size_box(_b_5900_5894, _ctx), _b_5901_5895, _ctx); /*list<0>*/
  _b_5898_5896 = kk_std_core_unvlist(_x6837, _ctx); /*vector<std/core/hnd/ev-index>*/
  kk_box_t _x6838 = kk_std_core_hnd__open0(_b_5898_5896, kk_climate_dash_experiments__new_mlift4695_run__experiments_fun6839(_x01_4675, _ctx), _ctx); /*1*/
  return kk_std_core_types__tuple2__unbox(_x6838, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift4695_run__experiments_fun6842__t {
  struct kk_function_s _base;
  kk_function_t model_4840;
  kk_integer_t sz;
};
static kk_box_t kk_climate_dash_experiments__mlift4695_run__experiments_fun6842(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift4695_run__experiments_fun6842(kk_function_t model_4840, kk_integer_t sz, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4695_run__experiments_fun6842__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift4695_run__experiments_fun6842__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift4695_run__experiments_fun6842, kk_context());
  _self->model_4840 = model_4840;
  _self->sz = sz;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift4695_run__experiments_fun6844__t {
  struct kk_function_s _base;
  kk_function_t model_4840;
};
static kk_box_t kk_climate_dash_experiments__mlift4695_run__experiments_fun6844(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift4695_run__experiments_fun6844(kk_function_t model_4840, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4695_run__experiments_fun6844__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift4695_run__experiments_fun6844__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift4695_run__experiments_fun6844, kk_context());
  _self->model_4840 = model_4840;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift4695_run__experiments_fun6846__t {
  struct kk_function_s _base;
  kk_function_t model_4840;
};
static kk_box_t kk_climate_dash_experiments__mlift4695_run__experiments_fun6846(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift4695_run__experiments_fun6846(kk_function_t model_4840, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4695_run__experiments_fun6846__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift4695_run__experiments_fun6846__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift4695_run__experiments_fun6846, kk_context());
  _self->model_4840 = model_4840;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift4695_run__experiments_fun6847__t {
  struct kk_function_s _base;
  kk_function_t model_4840;
};
static kk_box_t kk_climate_dash_experiments__mlift4695_run__experiments_fun6847(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift4695_run__experiments_fun6847(kk_function_t model_4840, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4695_run__experiments_fun6847__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift4695_run__experiments_fun6847__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift4695_run__experiments_fun6847, kk_context());
  _self->model_4840 = model_4840;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift4695_run__experiments_fun6847(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4695_run__experiments_fun6847__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift4695_run__experiments_fun6847__t*, _fself);
  kk_function_t model_4840 = _self->model_4840; /* () -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random,console,ndet,effects-and-types/sample> (double, double) */
  kk_drop_match(_self, {kk_function_dup(model_4840);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x6848 = kk_function_call(kk_std_core_types__tuple2_, (kk_function_t, kk_context_t*), model_4840, (model_4840, _ctx)); /*(double, double)*/
  return kk_std_core_types__tuple2__box(_x6848, _ctx);
}
static kk_box_t kk_climate_dash_experiments__mlift4695_run__experiments_fun6846(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4695_run__experiments_fun6846__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift4695_run__experiments_fun6846__t*, _fself);
  kk_function_t model_4840 = _self->model_4840; /* () -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random,console,ndet,effects-and-types/sample> (double, double) */
  kk_drop_match(_self, {kk_function_dup(model_4840);}, {}, _ctx)
  return kk_handlers_yield__on__score(kk_climate_dash_experiments__new_mlift4695_run__experiments_fun6847(model_4840, _ctx), _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift4695_run__experiments_fun6849__t {
  struct kk_function_s _base;
  kk_function_t _bv_5906;
};
static kk_std_core_types__tuple2_ kk_climate_dash_experiments__mlift4695_run__experiments_fun6849(kk_function_t _fself, kk_integer_t _b_5907, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift4695_run__experiments_fun6849(kk_function_t _bv_5906, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4695_run__experiments_fun6849__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift4695_run__experiments_fun6849__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift4695_run__experiments_fun6849, kk_context());
  _self->_bv_5906 = _bv_5906;
  return &_self->_base;
}

static kk_std_core_types__tuple2_ kk_climate_dash_experiments__mlift4695_run__experiments_fun6849(kk_function_t _fself, kk_integer_t _b_5907, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4695_run__experiments_fun6849__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift4695_run__experiments_fun6849__t*, _fself);
  kk_function_t _bv_5906 = _self->_bv_5906; /* (steps : int) -> <effects-and-types/yield|1> 0 */
  kk_drop_match(_self, {kk_function_dup(_bv_5906);}, {}, _ctx)
  kk_box_t _x6850 = kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_context_t*), _bv_5906, (_bv_5906, _b_5907, _ctx)); /*0*/
  return kk_std_core_types__tuple2__unbox(_x6850, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift4695_run__experiments_fun6851__t {
  struct kk_function_s _base;
  kk_function_t _bv_5912;
};
static kk_box_t kk_climate_dash_experiments__mlift4695_run__experiments_fun6851(kk_function_t _fself, kk_box_t _b_5913, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift4695_run__experiments_fun6851(kk_function_t _bv_5912, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4695_run__experiments_fun6851__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift4695_run__experiments_fun6851__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift4695_run__experiments_fun6851, kk_context());
  _self->_bv_5912 = _bv_5912;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift4695_run__experiments_fun6851(kk_function_t _fself, kk_box_t _b_5913, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4695_run__experiments_fun6851__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift4695_run__experiments_fun6851__t*, _fself);
  kk_function_t _bv_5912 = _self->_bv_5912; /* (steps : int) -> <effects-and-types/yield,effects-and-types/sample,effects-and-types/score,div,exn,std/num/random/random,console,ndet,effects-and-types/sample> (double, double) */
  kk_drop_match(_self, {kk_function_dup(_bv_5912);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x6852;
  kk_integer_t _x6853 = kk_integer_unbox(_b_5913); /*int*/
  _x6852 = kk_function_call(kk_std_core_types__tuple2_, (kk_function_t, kk_integer_t, kk_context_t*), _bv_5912, (_bv_5912, _x6853, _ctx)); /*(double, double)*/
  return kk_std_core_types__tuple2__box(_x6852, _ctx);
}
static kk_box_t kk_climate_dash_experiments__mlift4695_run__experiments_fun6844(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4695_run__experiments_fun6844__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift4695_run__experiments_fun6844__t*, _fself);
  kk_function_t model_4840 = _self->model_4840; /* () -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random,console,ndet,effects-and-types/sample> (double, double) */
  kk_drop_match(_self, {kk_function_dup(model_4840);}, {}, _ctx)
  kk_function_t _x6845;
  kk_function_t _bv_5912;
  kk_function_t _bv_5906 = kk_handlers_advance(kk_climate_dash_experiments__new_mlift4695_run__experiments_fun6846(model_4840, _ctx), _ctx); /*(steps : int) -> <effects-and-types/yield|1> 0*/;
  _bv_5912 = kk_climate_dash_experiments__new_mlift4695_run__experiments_fun6849(_bv_5906, _ctx); /*(steps : int) -> <effects-and-types/yield,effects-and-types/sample,effects-and-types/score,div,exn,std/num/random/random,console,ndet,effects-and-types/sample> (double, double)*/
  _x6845 = kk_climate_dash_experiments__new_mlift4695_run__experiments_fun6851(_bv_5912, _ctx); /*(5910) -> <effects-and-types/yield,effects-and-types/sample,effects-and-types/score,div,exn,std/num/random/random,console,ndet,effects-and-types/sample> 5911*/
  return kk_function_box(_x6845);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift4695_run__experiments_fun6855__t {
  struct kk_function_s _base;
  kk_integer_t sz;
};
static kk_box_t kk_climate_dash_experiments__mlift4695_run__experiments_fun6855(kk_function_t _fself, kk_box_t _b_5919, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift4695_run__experiments_fun6855(kk_integer_t sz, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4695_run__experiments_fun6855__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift4695_run__experiments_fun6855__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift4695_run__experiments_fun6855, kk_context());
  _self->sz = sz;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift4695_run__experiments_fun6855(kk_function_t _fself, kk_box_t _b_5919, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4695_run__experiments_fun6855__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift4695_run__experiments_fun6855__t*, _fself);
  kk_integer_t sz = _self->sz; /* int */
  kk_drop_match(_self, {kk_integer_dup(sz);}, {}, _ctx)
  kk_std_core__list _x6856;
  kk_std_core__list _x6857 = kk_std_core__list_unbox(_b_5919, _ctx); /*effects-and-types/histogram<(steps : int) -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random,console,ndet,effects-and-types/sample> (double, double)>*/
  _x6856 = kk_smc__mlift512_smc(true, kk_integer_from_small(1), sz, _x6857, _ctx); /*effects-and-types/histogram<1>*/
  return kk_std_core__list_box(_x6856, _ctx);
}
static kk_box_t kk_climate_dash_experiments__mlift4695_run__experiments_fun6842(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4695_run__experiments_fun6842__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift4695_run__experiments_fun6842__t*, _fself);
  kk_function_t model_4840 = _self->model_4840; /* () -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random,console,ndet,effects-and-types/sample> (double, double) */
  kk_integer_t sz = _self->sz; /* int */
  kk_drop_match(_self, {kk_function_dup(model_4840);kk_integer_dup(sz);}, {}, _ctx)
  kk_std_core__list _x6843;
  kk_std_core__list x_538 = kk_sampling_populate(kk_integer_from_small(100), kk_climate_dash_experiments__new_mlift4695_run__experiments_fun6844(model_4840, _ctx), _ctx); /*effects-and-types/histogram<(steps : int) -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random,console,ndet,effects-and-types/sample> (double, double)>*/;
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_538, _ctx);
    kk_box_t _x6854 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments__new_mlift4695_run__experiments_fun6855(sz, _ctx), _ctx); /*2*/
    _x6843 = kk_std_core__list_unbox(_x6854, _ctx); /*effects-and-types/histogram<(double, double)>*/
  }
  else {
    _x6843 = kk_smc__mlift512_smc(true, kk_integer_from_small(1), sz, x_538, _ctx); /*effects-and-types/histogram<(double, double)>*/
  }
  return kk_std_core__list_box(_x6843, _ctx);
}
static kk_box_t kk_climate_dash_experiments__mlift4695_run__experiments_fun6826(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4695_run__experiments_fun6826__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift4695_run__experiments_fun6826__t*, _fself);
  kk_std_core__list data__vals = _self->data__vals; /* list<(double, bool)> */
  kk_integer_t sz = _self->sz; /* int */
  kk_drop_match(_self, {kk_std_core__list_dup(data__vals);kk_integer_dup(sz);}, {}, _ctx)
  kk_std_core__list _x6827;
  kk_function_t model_4840;
  kk_function_t _x01_4675;
  kk_function_t _bv_5889;
  kk_box_t _x6828 = kk_std_core_hnd__open_none1(kk_climate_dash_experiments__new_mlift4695_run__experiments_fun6829(_ctx), kk_std_core__list_box(data__vals, _ctx), _ctx); /*2*/
  _bv_5889 = kk_function_unbox(_x6828); /*() -> <.Box|.Box> 5888*/
  _x01_4675 = kk_climate_dash_experiments__new_mlift4695_run__experiments_fun6834(_bv_5889, _ctx); /*effects-and-types/model<(double, double),div>*/
  model_4840 = kk_climate_dash_experiments__new_mlift4695_run__experiments_fun6836(_x01_4675, _ctx); /*() -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random,console,ndet,effects-and-types/sample> (double, double)*/
  kk_box_t _x6841 = kk_handlers_random__sampler(kk_climate_dash_experiments__new_mlift4695_run__experiments_fun6842(model_4840, sz, _ctx), _ctx); /*0*/
  _x6827 = kk_std_core__list_unbox(_x6841, _ctx); /*effects-and-types/histogram<(double, double)>*/
  return kk_std_core__list_box(_x6827, _ctx);
}
static kk_box_t kk_climate_dash_experiments__mlift4695_run__experiments_fun6823(kk_function_t _fself, kk_box_t _b_5925, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core_types__tuple2_ _match_6193 = kk_std_core_types__tuple2__unbox(_b_5925, _ctx); /*(int, list<(double, bool)>)*/;
  kk_box_t _box_x5881 = _match_6193.fst;
  kk_box_t _box_x5882 = _match_6193.snd;
  kk_integer_t sz = kk_integer_unbox(_box_x5881);
  kk_std_core__list data__vals = kk_std_core__list_unbox(_box_x5882, NULL);
  kk_std_core__list_dup(data__vals);
  kk_integer_dup(sz);
  kk_std_core_types__tuple2__drop(_match_6193, _ctx);
  return kk_std_time_timer_print_elapsed(kk_climate_dash_experiments__new_mlift4695_run__experiments_fun6826(data__vals, sz, _ctx), kk_std_core_types__new_None(_ctx), _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift4695_run__experiments_fun6859__t {
  struct kk_function_s _base;
  kk_std_core__list data__50;
  kk_std_core__list data__points;
  kk_integer_t i1;
};
static kk_box_t kk_climate_dash_experiments__mlift4695_run__experiments_fun6859(kk_function_t _fself, kk_box_t _b_5935, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift4695_run__experiments_fun6859(kk_std_core__list data__50, kk_std_core__list data__points, kk_integer_t i1, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4695_run__experiments_fun6859__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift4695_run__experiments_fun6859__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift4695_run__experiments_fun6859, kk_context());
  _self->data__50 = data__50;
  _self->data__points = data__points;
  _self->i1 = i1;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift4695_run__experiments_fun6859(kk_function_t _fself, kk_box_t _b_5935, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4695_run__experiments_fun6859__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift4695_run__experiments_fun6859__t*, _fself);
  kk_std_core__list data__50 = _self->data__50; /* list<(double, bool)> */
  kk_std_core__list data__points = _self->data__points; /* list<(int, list<(double, bool)>)> */
  kk_integer_t i1 = _self->i1; /* int */
  kk_drop_match(_self, {kk_std_core__list_dup(data__50);kk_std_core__list_dup(data__points);kk_integer_dup(i1);}, {}, _ctx)
  kk_unit_t _x6860 = kk_Unit;
  kk_std_core__list _x6861 = kk_std_core__list_unbox(_b_5935, _ctx); /*list<effects-and-types/histogram<(double, double)>>*/
  kk_climate_dash_experiments__mlift4694_run__experiments(data__50, data__points, i1, _x6861, _ctx);
  return kk_unit_box(_x6860);
}
static kk_unit_t kk_climate_dash_experiments__mlift4695_run__experiments_fun6815(kk_function_t _fself, kk_integer_t i1, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4695_run__experiments_fun6815__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift4695_run__experiments_fun6815__t*, _fself);
  kk_std_core__list data__50 = _self->data__50; /* list<(double, bool)> */
  kk_std_core__list data__points = _self->data__points; /* list<(int, list<(double, bool)>)> */
  kk_drop_match(_self, {kk_std_core__list_dup(data__50);kk_std_core__list_dup(data__points);}, {}, _ctx)
  kk_unit_t __ = kk_Unit;
  kk_string_t s_4833;
  kk_string_t _x6816;
  kk_define_string_literal(, _s6817, 7, "Round #")
  _x6816 = kk_string_dup(_s6817); /*string*/
  kk_string_t _x6818;
  kk_integer_t _x6819 = kk_integer_dup(i1); /*int*/
  _x6818 = kk_std_core_show(_x6819, _ctx); /*string*/
  s_4833 = kk_std_core__lp__plus__plus__1_rp_(_x6816, _x6818, _ctx); /*string*/
  kk_std_core_printsln(s_4833, _ctx);
  kk_unit_t __0 = kk_Unit;
  kk_string_t _x6820;
  kk_define_string_literal(, _s6821, 38, "Running SMC with increasing data size:")
  _x6820 = kk_string_dup(_s6821); /*string*/
  kk_std_core_printsln(_x6820, _ctx);
  kk_std_core__list x_4835;
  kk_std_core__list _x6822 = kk_std_core__list_dup(data__points); /*list<(int, list<(double, bool)>)>*/
  x_4835 = kk_std_core_map_5(_x6822, kk_climate_dash_experiments__new_mlift4695_run__experiments_fun6823(_ctx), _ctx); /*list<effects-and-types/histogram<(double, double)>>*/
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_4835, _ctx);
    kk_box_t _x6858 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments__new_mlift4695_run__experiments_fun6859(data__50, data__points, i1, _ctx), _ctx); /*2*/
    return kk_unit_unbox(_x6858);
  }
  return kk_climate_dash_experiments__mlift4694_run__experiments(data__50, data__points, i1, x_4835, _ctx);
}

kk_unit_t kk_climate_dash_experiments__mlift4695_run__experiments(kk_std_core__list data__points, kk_std_core_types__optional number__of__repeats, kk_std_core__list data__50, kk_context_t* _ctx) { /* (data_points : list<(int, list<(double, bool)>)>, number_of_repeats : optional<int>, data_50 : list<(double, bool)>) -> <std/num/random/random,console,div,exn,ndet,effects-and-types/sample> () */ 
  kk_integer_t _x6862;
  if (kk_std_core_types__is_Optional(number__of__repeats)) {
    kk_box_t _box_x5936 = number__of__repeats._cons.Optional.value;
    kk_integer_t _number__of__repeats_2659 = kk_integer_unbox(_box_x5936);
    kk_integer_dup(_number__of__repeats_2659);
    kk_std_core_types__optional_drop(number__of__repeats, _ctx);
    _x6862 = _number__of__repeats_2659; /*int*/
    goto _match6863;
  }
  _x6862 = kk_integer_from_small(4); /*int*/
  _match6863: ;
  kk_std_core__lift21056_for(kk_climate_dash_experiments__new_mlift4695_run__experiments_fun6815(data__50, data__points, _ctx), _x6862, kk_integer_from_small(1), _ctx); return kk_Unit;
}
 
// monadic lift

kk_std_core_types__tuple2_ kk_climate_dash_experiments__mlift4696_run__experiments(kk_integer_t i0, kk_std_core__list _y_20, kk_context_t* _ctx) { /* (i0 : int, list<(double, bool)>) -> <std/num/random/random,console,div,exn,ndet,effects-and-types/sample> (int, list<(double, bool)>) */ 
  return kk_std_core_types__new_dash__lp__comma__rp_(kk_integer_box(i0), kk_std_core__list_box(_y_20, _ctx), _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_climate_dash_experiments__mlift4697_run__experiments_fun6866__t {
  struct kk_function_s _base;
  size_t i_4844;
};
static kk_box_t kk_climate_dash_experiments__mlift4697_run__experiments_fun6866(kk_function_t _fself, kk_function_t _b_5948, kk_box_t _b_5949, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift4697_run__experiments_fun6866(size_t i_4844, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4697_run__experiments_fun6866__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift4697_run__experiments_fun6866__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift4697_run__experiments_fun6866, kk_context());
  _self->i_4844 = i_4844;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift4697_run__experiments_fun6866(kk_function_t _fself, kk_function_t _b_5948, kk_box_t _b_5949, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4697_run__experiments_fun6866__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift4697_run__experiments_fun6866__t*, _fself);
  size_t i_4844 = _self->i_4844; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_4844, _b_5948, _b_5949, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift4697_run__experiments_fun6868__t {
  struct kk_function_s _base;
  kk_std_core__list data__points;
  kk_std_core_types__optional number__of__repeats;
};
static kk_box_t kk_climate_dash_experiments__mlift4697_run__experiments_fun6868(kk_function_t _fself, kk_box_t _b_5959, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift4697_run__experiments_fun6868(kk_std_core__list data__points, kk_std_core_types__optional number__of__repeats, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4697_run__experiments_fun6868__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift4697_run__experiments_fun6868__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift4697_run__experiments_fun6868, kk_context());
  _self->data__points = data__points;
  _self->number__of__repeats = number__of__repeats;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift4697_run__experiments_fun6868(kk_function_t _fself, kk_box_t _b_5959, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4697_run__experiments_fun6868__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift4697_run__experiments_fun6868__t*, _fself);
  kk_std_core__list data__points = _self->data__points; /* list<(int, list<(double, bool)>)> */
  kk_std_core_types__optional number__of__repeats = _self->number__of__repeats; /* optional<int> */
  kk_drop_match(_self, {kk_std_core__list_dup(data__points);kk_std_core_types__optional_dup(number__of__repeats);}, {}, _ctx)
  kk_unit_t _x6869 = kk_Unit;
  kk_std_core__list _x6870 = kk_std_core__list_unbox(_b_5959, _ctx); /*list<(double, bool)>*/
  kk_climate_dash_experiments__mlift4695_run__experiments(data__points, number__of__repeats, _x6870, _ctx);
  return kk_unit_box(_x6869);
}

kk_unit_t kk_climate_dash_experiments__mlift4697_run__experiments(kk_std_core_types__optional number__of__repeats, kk_std_core__list data__points, kk_context_t* _ctx) { /* (number_of_repeats : optional<int>, data_points : list<(int, list<(double, bool)>)>) -> <std/num/random/random,console,div,exn,ndet,effects-and-types/sample> () */ 
  kk_std_core__list x_4842;
  size_t i_4844 = ((size_t)1); /*std/core/hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_4844,kk_context()); /*std/core/hnd/evv<<std/num/random/random,console,div,exn,ndet,effects-and-types/sample>>*/;
  kk_std_core__list y = kk_model_dash_resources_generate__synthetic__lr__data(kk_integer_from_small(50), _ctx); /*list<(double, bool)>*/;
  kk_unit_t __w_l700_c9 = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(y, _ctx);
    kk_box_t _x6865 = kk_std_core_hnd_yield_cont(kk_climate_dash_experiments__new_mlift4697_run__experiments_fun6866(i_4844, _ctx), _ctx); /*3*/
    x_4842 = kk_std_core__list_unbox(_x6865, _ctx); /*list<(double, bool)>*/
  }
  else {
    x_4842 = y; /*list<(double, bool)>*/
  }
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_4842, _ctx);
    kk_box_t _x6867 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments__new_mlift4697_run__experiments_fun6868(data__points, number__of__repeats, _ctx), _ctx); /*2*/
    kk_unit_unbox(_x6867); return kk_Unit;
  }
  kk_climate_dash_experiments__mlift4695_run__experiments(data__points, number__of__repeats, x_4842, _ctx); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_climate_dash_experiments__mlift4698_run__experiments_fun6871__t {
  struct kk_function_s _base;
};
static kk_box_t kk_climate_dash_experiments__mlift4698_run__experiments_fun6871(kk_function_t _fself, kk_box_t _b_5981, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift4698_run__experiments_fun6871(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_climate_dash_experiments__mlift4698_run__experiments_fun6871, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_climate_dash_experiments__mlift4698_run__experiments_fun6876__t {
  struct kk_function_s _base;
  size_t i_4851;
};
static kk_box_t kk_climate_dash_experiments__mlift4698_run__experiments_fun6876(kk_function_t _fself, kk_function_t _b_5967, kk_box_t _b_5968, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift4698_run__experiments_fun6876(size_t i_4851, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4698_run__experiments_fun6876__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift4698_run__experiments_fun6876__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift4698_run__experiments_fun6876, kk_context());
  _self->i_4851 = i_4851;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift4698_run__experiments_fun6876(kk_function_t _fself, kk_function_t _b_5967, kk_box_t _b_5968, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4698_run__experiments_fun6876__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift4698_run__experiments_fun6876__t*, _fself);
  size_t i_4851 = _self->i_4851; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_4851, _b_5967, _b_5968, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift4698_run__experiments_fun6878__t {
  struct kk_function_s _base;
  kk_box_t _b_5981;
};
static kk_box_t kk_climate_dash_experiments__mlift4698_run__experiments_fun6878(kk_function_t _fself, kk_box_t _b_5978, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift4698_run__experiments_fun6878(kk_box_t _b_5981, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4698_run__experiments_fun6878__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift4698_run__experiments_fun6878__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift4698_run__experiments_fun6878, kk_context());
  _self->_b_5981 = _b_5981;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift4698_run__experiments_fun6878(kk_function_t _fself, kk_box_t _b_5978, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4698_run__experiments_fun6878__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift4698_run__experiments_fun6878__t*, _fself);
  kk_box_t _b_5981 = _self->_b_5981; /* 1 */
  kk_drop_match(_self, {kk_box_dup(_b_5981);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x6879;
  kk_integer_t _x6880 = kk_integer_unbox(_b_5981); /*int*/
  kk_std_core__list _x6881 = kk_std_core__list_unbox(_b_5978, _ctx); /*list<(double, bool)>*/
  _x6879 = kk_climate_dash_experiments__mlift4696_run__experiments(_x6880, _x6881, _ctx); /*(int, list<(double, bool)>)*/
  return kk_std_core_types__tuple2__box(_x6879, _ctx);
}
static kk_box_t kk_climate_dash_experiments__mlift4698_run__experiments_fun6871(kk_function_t _fself, kk_box_t _b_5981, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core_types__tuple2_ _x6872;
  kk_std_core__list x0_4849;
  size_t i_4851 = ((size_t)1); /*std/core/hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_4851,kk_context()); /*std/core/hnd/evv<<std/num/random/random,console,div,exn,ndet,effects-and-types/sample>>*/;
  kk_std_core__list y;
  kk_integer_t _x6873;
  kk_box_t _x6874 = kk_box_dup(_b_5981); /*1*/
  _x6873 = kk_integer_unbox(_x6874); /*int*/
  y = kk_model_dash_resources_generate__synthetic__lr__data(_x6873, _ctx); /*list<(double, bool)>*/
  kk_unit_t __w_l700_c9 = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(y, _ctx);
    kk_box_t _x6875 = kk_std_core_hnd_yield_cont(kk_climate_dash_experiments__new_mlift4698_run__experiments_fun6876(i_4851, _ctx), _ctx); /*3*/
    x0_4849 = kk_std_core__list_unbox(_x6875, _ctx); /*list<(double, bool)>*/
  }
  else {
    x0_4849 = y; /*list<(double, bool)>*/
  }
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x0_4849, _ctx);
    kk_box_t _x6877 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments__new_mlift4698_run__experiments_fun6878(_b_5981, _ctx), _ctx); /*2*/
    _x6872 = kk_std_core_types__tuple2__unbox(_x6877, _ctx); /*(int, list<(double, bool)>)*/
  }
  else {
    kk_integer_t _x6882 = kk_integer_unbox(_b_5981); /*int*/
    _x6872 = kk_climate_dash_experiments__mlift4696_run__experiments(_x6882, x0_4849, _ctx); /*(int, list<(double, bool)>)*/
  }
  return kk_std_core_types__tuple2__box(_x6872, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__mlift4698_run__experiments_fun6884__t {
  struct kk_function_s _base;
  kk_std_core_types__optional number__of__repeats;
};
static kk_box_t kk_climate_dash_experiments__mlift4698_run__experiments_fun6884(kk_function_t _fself, kk_box_t _b_5988, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_mlift4698_run__experiments_fun6884(kk_std_core_types__optional number__of__repeats, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4698_run__experiments_fun6884__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__mlift4698_run__experiments_fun6884__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__mlift4698_run__experiments_fun6884, kk_context());
  _self->number__of__repeats = number__of__repeats;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__mlift4698_run__experiments_fun6884(kk_function_t _fself, kk_box_t _b_5988, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__mlift4698_run__experiments_fun6884__t* _self = kk_function_as(struct kk_climate_dash_experiments__mlift4698_run__experiments_fun6884__t*, _fself);
  kk_std_core_types__optional number__of__repeats = _self->number__of__repeats; /* optional<int> */
  kk_drop_match(_self, {kk_std_core_types__optional_dup(number__of__repeats);}, {}, _ctx)
  kk_unit_t _x6885 = kk_Unit;
  kk_std_core__list _x6886 = kk_std_core__list_unbox(_b_5988, _ctx); /*list<(int, list<(double, bool)>)>*/
  kk_climate_dash_experiments__mlift4697_run__experiments(number__of__repeats, _x6886, _ctx);
  return kk_unit_box(_x6885);
}

kk_unit_t kk_climate_dash_experiments__mlift4698_run__experiments(kk_std_core_types__optional number__of__repeats, kk_std_core__list _y_19, kk_context_t* _ctx) { /* (number_of_repeats : optional<int>, list<int>) -> <std/num/random/random,console,div,exn,ndet,effects-and-types/sample> () */ 
  kk_std_core__list x_4847 = kk_std_core_map_5(_y_19, kk_climate_dash_experiments__new_mlift4698_run__experiments_fun6871(_ctx), _ctx); /*list<(int, list<(double, bool)>)>*/;
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_4847, _ctx);
    kk_box_t _x6883 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments__new_mlift4698_run__experiments_fun6884(number__of__repeats, _ctx), _ctx); /*2*/
    kk_unit_unbox(_x6883); return kk_Unit;
  }
  kk_climate_dash_experiments__mlift4697_run__experiments(number__of__repeats, x_4847, _ctx); return kk_Unit;
}
 
// Original code has 10 as the max_number_of_data_points, but this reaches max_memory (heap size of 4 GB on my computer) nad cca 10GB of core data


// lift anonymous function
struct kk_climate_dash_experiments_run__experiments_fun6890__t {
  struct kk_function_s _base;
};
static kk_box_t kk_climate_dash_experiments_run__experiments_fun6890(kk_function_t _fself, kk_box_t _b_5994, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__experiments_fun6890(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_climate_dash_experiments_run__experiments_fun6890, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_climate_dash_experiments_run__experiments_fun6890(kk_function_t _fself, kk_box_t _b_5994, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_integer_t _x6891;
  kk_integer_t _x6892 = kk_integer_unbox(_b_5994); /*int*/
  _x6891 = kk_integer_mul(_x6892,(kk_integer_from_small(100)),kk_context()); /*int*/
  return kk_integer_box(_x6891);
}


// lift anonymous function
struct kk_climate_dash_experiments_run__experiments_fun6894__t {
  struct kk_function_s _base;
  kk_std_core_types__optional number__of__repeats;
};
static kk_box_t kk_climate_dash_experiments_run__experiments_fun6894(kk_function_t _fself, kk_box_t _b_5999, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__experiments_fun6894(kk_std_core_types__optional number__of__repeats, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun6894__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__experiments_fun6894__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__experiments_fun6894, kk_context());
  _self->number__of__repeats = number__of__repeats;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments_run__experiments_fun6894(kk_function_t _fself, kk_box_t _b_5999, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun6894__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__experiments_fun6894__t*, _fself);
  kk_std_core_types__optional number__of__repeats = _self->number__of__repeats; /* optional<int> */
  kk_drop_match(_self, {kk_std_core_types__optional_dup(number__of__repeats);}, {}, _ctx)
  kk_unit_t _x6895 = kk_Unit;
  kk_std_core__list _x6896 = kk_std_core__list_unbox(_b_5999, _ctx); /*list<int>*/
  kk_climate_dash_experiments__mlift4698_run__experiments(number__of__repeats, _x6896, _ctx);
  return kk_unit_box(_x6895);
}


// lift anonymous function
struct kk_climate_dash_experiments_run__experiments_fun6897__t {
  struct kk_function_s _base;
};
static kk_box_t kk_climate_dash_experiments_run__experiments_fun6897(kk_function_t _fself, kk_box_t _b_6019, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__experiments_fun6897(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_climate_dash_experiments_run__experiments_fun6897, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_climate_dash_experiments_run__experiments_fun6902__t {
  struct kk_function_s _base;
  size_t i1_4865;
};
static kk_box_t kk_climate_dash_experiments_run__experiments_fun6902(kk_function_t _fself, kk_function_t _b_6005, kk_box_t _b_6006, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__experiments_fun6902(size_t i1_4865, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun6902__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__experiments_fun6902__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__experiments_fun6902, kk_context());
  _self->i1_4865 = i1_4865;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments_run__experiments_fun6902(kk_function_t _fself, kk_function_t _b_6005, kk_box_t _b_6006, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun6902__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__experiments_fun6902__t*, _fself);
  size_t i1_4865 = _self->i1_4865; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i1_4865, _b_6005, _b_6006, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments_run__experiments_fun6904__t {
  struct kk_function_s _base;
  kk_box_t _b_6019;
};
static kk_box_t kk_climate_dash_experiments_run__experiments_fun6904(kk_function_t _fself, kk_box_t _b_6016, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__experiments_fun6904(kk_box_t _b_6019, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun6904__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__experiments_fun6904__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__experiments_fun6904, kk_context());
  _self->_b_6019 = _b_6019;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments_run__experiments_fun6904(kk_function_t _fself, kk_box_t _b_6016, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun6904__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__experiments_fun6904__t*, _fself);
  kk_box_t _b_6019 = _self->_b_6019; /* 1 */
  kk_drop_match(_self, {kk_box_dup(_b_6019);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x6905;
  kk_integer_t _x6906 = kk_integer_unbox(_b_6019); /*int*/
  kk_std_core__list _x6907 = kk_std_core__list_unbox(_b_6016, _ctx); /*list<(double, bool)>*/
  _x6905 = kk_climate_dash_experiments__mlift4696_run__experiments(_x6906, _x6907, _ctx); /*(int, list<(double, bool)>)*/
  return kk_std_core_types__tuple2__box(_x6905, _ctx);
}
static kk_box_t kk_climate_dash_experiments_run__experiments_fun6897(kk_function_t _fself, kk_box_t _b_6019, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core_types__tuple2_ _x6898;
  kk_std_core__list x1_4863;
  size_t i1_4865 = ((size_t)1); /*std/core/hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i1_4865,kk_context()); /*std/core/hnd/evv<<std/num/random/random,console,div,exn,ndet,effects-and-types/sample>>*/;
  kk_std_core__list y;
  kk_integer_t _x6899;
  kk_box_t _x6900 = kk_box_dup(_b_6019); /*1*/
  _x6899 = kk_integer_unbox(_x6900); /*int*/
  y = kk_model_dash_resources_generate__synthetic__lr__data(_x6899, _ctx); /*list<(double, bool)>*/
  kk_unit_t __w_l700_c9 = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(y, _ctx);
    kk_box_t _x6901 = kk_std_core_hnd_yield_cont(kk_climate_dash_experiments_new_run__experiments_fun6902(i1_4865, _ctx), _ctx); /*3*/
    x1_4863 = kk_std_core__list_unbox(_x6901, _ctx); /*list<(double, bool)>*/
  }
  else {
    x1_4863 = y; /*list<(double, bool)>*/
  }
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x1_4863, _ctx);
    kk_box_t _x6903 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments_new_run__experiments_fun6904(_b_6019, _ctx), _ctx); /*2*/
    _x6898 = kk_std_core_types__tuple2__unbox(_x6903, _ctx); /*(int, list<(double, bool)>)*/
  }
  else {
    kk_integer_t _x6908 = kk_integer_unbox(_b_6019); /*int*/
    _x6898 = kk_climate_dash_experiments__mlift4696_run__experiments(_x6908, x1_4863, _ctx); /*(int, list<(double, bool)>)*/
  }
  return kk_std_core_types__tuple2__box(_x6898, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments_run__experiments_fun6910__t {
  struct kk_function_s _base;
  kk_std_core_types__optional number__of__repeats;
};
static kk_box_t kk_climate_dash_experiments_run__experiments_fun6910(kk_function_t _fself, kk_box_t _b_6026, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__experiments_fun6910(kk_std_core_types__optional number__of__repeats, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun6910__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__experiments_fun6910__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__experiments_fun6910, kk_context());
  _self->number__of__repeats = number__of__repeats;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments_run__experiments_fun6910(kk_function_t _fself, kk_box_t _b_6026, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun6910__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__experiments_fun6910__t*, _fself);
  kk_std_core_types__optional number__of__repeats = _self->number__of__repeats; /* optional<int> */
  kk_drop_match(_self, {kk_std_core_types__optional_dup(number__of__repeats);}, {}, _ctx)
  kk_unit_t _x6911 = kk_Unit;
  kk_std_core__list _x6912 = kk_std_core__list_unbox(_b_6026, _ctx); /*list<(int, list<(double, bool)>)>*/
  kk_climate_dash_experiments__mlift4697_run__experiments(number__of__repeats, _x6912, _ctx);
  return kk_unit_box(_x6911);
}


// lift anonymous function
struct kk_climate_dash_experiments_run__experiments_fun6914__t {
  struct kk_function_s _base;
  size_t i2_4872;
};
static kk_box_t kk_climate_dash_experiments_run__experiments_fun6914(kk_function_t _fself, kk_function_t _b_6032, kk_box_t _b_6033, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__experiments_fun6914(size_t i2_4872, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun6914__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__experiments_fun6914__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__experiments_fun6914, kk_context());
  _self->i2_4872 = i2_4872;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments_run__experiments_fun6914(kk_function_t _fself, kk_function_t _b_6032, kk_box_t _b_6033, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun6914__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__experiments_fun6914__t*, _fself);
  size_t i2_4872 = _self->i2_4872; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i2_4872, _b_6032, _b_6033, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments_run__experiments_fun6916__t {
  struct kk_function_s _base;
  kk_std_core_types__optional number__of__repeats;
  kk_std_core__list x0_4860;
};
static kk_box_t kk_climate_dash_experiments_run__experiments_fun6916(kk_function_t _fself, kk_box_t _b_6043, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__experiments_fun6916(kk_std_core_types__optional number__of__repeats, kk_std_core__list x0_4860, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun6916__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__experiments_fun6916__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__experiments_fun6916, kk_context());
  _self->number__of__repeats = number__of__repeats;
  _self->x0_4860 = x0_4860;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments_run__experiments_fun6916(kk_function_t _fself, kk_box_t _b_6043, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun6916__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__experiments_fun6916__t*, _fself);
  kk_std_core_types__optional number__of__repeats = _self->number__of__repeats; /* optional<int> */
  kk_std_core__list x0_4860 = _self->x0_4860; /* list<(int, list<(double, bool)>)> */
  kk_drop_match(_self, {kk_std_core_types__optional_dup(number__of__repeats);kk_std_core__list_dup(x0_4860);}, {}, _ctx)
  kk_unit_t _x6917 = kk_Unit;
  kk_std_core__list _x6918 = kk_std_core__list_unbox(_b_6043, _ctx); /*list<(double, bool)>*/
  kk_climate_dash_experiments__mlift4695_run__experiments(x0_4860, number__of__repeats, _x6918, _ctx);
  return kk_unit_box(_x6917);
}


// lift anonymous function
struct kk_climate_dash_experiments_run__experiments_fun6919__t {
  struct kk_function_s _base;
  kk_std_core__list x0_4860;
  kk_std_core__list x3_4869;
};
static kk_unit_t kk_climate_dash_experiments_run__experiments_fun6919(kk_function_t _fself, kk_integer_t i10, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__experiments_fun6919(kk_std_core__list x0_4860, kk_std_core__list x3_4869, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun6919__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__experiments_fun6919__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__experiments_fun6919, kk_context());
  _self->x0_4860 = x0_4860;
  _self->x3_4869 = x3_4869;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments_run__experiments_fun6927__t {
  struct kk_function_s _base;
};
static kk_box_t kk_climate_dash_experiments_run__experiments_fun6927(kk_function_t _fself, kk_box_t _b_6088, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__experiments_fun6927(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_climate_dash_experiments_run__experiments_fun6927, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_climate_dash_experiments_run__experiments_fun6930__t {
  struct kk_function_s _base;
  kk_std_core__list data__vals;
  kk_integer_t sz;
};
static kk_box_t kk_climate_dash_experiments_run__experiments_fun6930(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__experiments_fun6930(kk_std_core__list data__vals, kk_integer_t sz, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun6930__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__experiments_fun6930__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__experiments_fun6930, kk_context());
  _self->data__vals = data__vals;
  _self->sz = sz;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments_run__experiments_fun6933__t {
  struct kk_function_s _base;
};
static kk_box_t kk_climate_dash_experiments_run__experiments_fun6933(kk_function_t _fself, kk_box_t _b_6048, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__experiments_fun6933(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_climate_dash_experiments_run__experiments_fun6933, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_climate_dash_experiments_run__experiments_fun6936__t {
  struct kk_function_s _base;
  kk_function_t _bv_6050;
};
static kk_box_t kk_climate_dash_experiments_run__experiments_fun6936(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__experiments_fun6936(kk_function_t _bv_6050, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun6936__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__experiments_fun6936__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__experiments_fun6936, kk_context());
  _self->_bv_6050 = _bv_6050;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments_run__experiments_fun6936(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun6936__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__experiments_fun6936__t*, _fself);
  kk_function_t _bv_6050 = _self->_bv_6050; /* effects-and-types/model<(double, double),div> */
  kk_drop_match(_self, {kk_function_dup(_bv_6050);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x6937 = kk_function_call(kk_std_core_types__tuple2_, (kk_function_t, kk_context_t*), _bv_6050, (_bv_6050, _ctx)); /*(double, double)*/
  return kk_std_core_types__tuple2__box(_x6937, _ctx);
}
static kk_box_t kk_climate_dash_experiments_run__experiments_fun6933(kk_function_t _fself, kk_box_t _b_6048, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_function_t _x6934;
  kk_function_t _bv_6050;
  kk_std_core__list _x6935 = kk_std_core__list_unbox(_b_6048, _ctx); /*list<(double, bool)>*/
  _bv_6050 = kk_model_dash_resources_logistic__regression(_x6935, _ctx); /*effects-and-types/model<(double, double),div>*/
  _x6934 = kk_climate_dash_experiments_new_run__experiments_fun6936(_bv_6050, _ctx); /*() -> <effects-and-types/sample,effects-and-types/score,div> 6049*/
  return kk_function_box(_x6934);
}


// lift anonymous function
struct kk_climate_dash_experiments_run__experiments_fun6938__t {
  struct kk_function_s _base;
  kk_function_t _bv_6052;
};
static kk_std_core_types__tuple2_ kk_climate_dash_experiments_run__experiments_fun6938(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__experiments_fun6938(kk_function_t _bv_6052, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun6938__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__experiments_fun6938__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__experiments_fun6938, kk_context());
  _self->_bv_6052 = _bv_6052;
  return &_self->_base;
}

static kk_std_core_types__tuple2_ kk_climate_dash_experiments_run__experiments_fun6938(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun6938__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__experiments_fun6938__t*, _fself);
  kk_function_t _bv_6052 = _self->_bv_6052; /* () -> <.Box|.Box> 6051 */
  kk_drop_match(_self, {kk_function_dup(_bv_6052);}, {}, _ctx)
  kk_box_t _x6939 = kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), _bv_6052, (_bv_6052, _ctx)); /*6051*/
  return kk_std_core_types__tuple2__unbox(_x6939, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments_run__experiments_fun6940__t {
  struct kk_function_s _base;
  kk_function_t _x01_4675;
};
static kk_std_core_types__tuple2_ kk_climate_dash_experiments_run__experiments_fun6940(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__experiments_fun6940(kk_function_t _x01_4675, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun6940__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__experiments_fun6940__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__experiments_fun6940, kk_context());
  _self->_x01_4675 = _x01_4675;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments_run__experiments_fun6943__t {
  struct kk_function_s _base;
  kk_function_t _x01_4675;
};
static kk_box_t kk_climate_dash_experiments_run__experiments_fun6943(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__experiments_fun6943(kk_function_t _x01_4675, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun6943__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__experiments_fun6943__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__experiments_fun6943, kk_context());
  _self->_x01_4675 = _x01_4675;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments_run__experiments_fun6943(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun6943__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__experiments_fun6943__t*, _fself);
  kk_function_t _x01_4675 = _self->_x01_4675; /* effects-and-types/model<(double, double),div> */
  kk_drop_match(_self, {kk_function_dup(_x01_4675);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x6944 = kk_function_call(kk_std_core_types__tuple2_, (kk_function_t, kk_context_t*), _x01_4675, (_x01_4675, _ctx)); /*(double, double)*/
  return kk_std_core_types__tuple2__box(_x6944, _ctx);
}
static kk_std_core_types__tuple2_ kk_climate_dash_experiments_run__experiments_fun6940(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun6940__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__experiments_fun6940__t*, _fself);
  kk_function_t _x01_4675 = _self->_x01_4675; /* effects-and-types/model<(double, double),div> */
  kk_drop_match(_self, {kk_function_dup(_x01_4675);}, {}, _ctx)
  kk_vector_t _b_6061_6059;
  kk_std_core__list _x6941;
  size_t _b_6063_6057 = ((size_t)2); /*std/core/hnd/ev-index*/;
  kk_std_core__list _b_6064_6058;
  size_t _b_6065_6055 = ((size_t)4); /*std/core/hnd/ev-index*/;
  _b_6064_6058 = kk_std_core__new_Cons(kk_reuse_null, kk_size_box(_b_6065_6055, _ctx), kk_std_core__new_Nil(_ctx), _ctx); /*list<std/core/hnd/ev-index>*/
  _x6941 = kk_std_core__new_Cons(kk_reuse_null, kk_size_box(_b_6063_6057, _ctx), _b_6064_6058, _ctx); /*list<0>*/
  _b_6061_6059 = kk_std_core_unvlist(_x6941, _ctx); /*vector<std/core/hnd/ev-index>*/
  kk_box_t _x6942 = kk_std_core_hnd__open0(_b_6061_6059, kk_climate_dash_experiments_new_run__experiments_fun6943(_x01_4675, _ctx), _ctx); /*1*/
  return kk_std_core_types__tuple2__unbox(_x6942, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments_run__experiments_fun6946__t {
  struct kk_function_s _base;
  kk_function_t model_4886;
  kk_integer_t sz;
};
static kk_box_t kk_climate_dash_experiments_run__experiments_fun6946(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__experiments_fun6946(kk_function_t model_4886, kk_integer_t sz, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun6946__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__experiments_fun6946__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__experiments_fun6946, kk_context());
  _self->model_4886 = model_4886;
  _self->sz = sz;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments_run__experiments_fun6948__t {
  struct kk_function_s _base;
  kk_function_t model_4886;
};
static kk_box_t kk_climate_dash_experiments_run__experiments_fun6948(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__experiments_fun6948(kk_function_t model_4886, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun6948__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__experiments_fun6948__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__experiments_fun6948, kk_context());
  _self->model_4886 = model_4886;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments_run__experiments_fun6950__t {
  struct kk_function_s _base;
  kk_function_t model_4886;
};
static kk_box_t kk_climate_dash_experiments_run__experiments_fun6950(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__experiments_fun6950(kk_function_t model_4886, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun6950__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__experiments_fun6950__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__experiments_fun6950, kk_context());
  _self->model_4886 = model_4886;
  return &_self->_base;
}



// lift anonymous function
struct kk_climate_dash_experiments_run__experiments_fun6951__t {
  struct kk_function_s _base;
  kk_function_t model_4886;
};
static kk_box_t kk_climate_dash_experiments_run__experiments_fun6951(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__experiments_fun6951(kk_function_t model_4886, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun6951__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__experiments_fun6951__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__experiments_fun6951, kk_context());
  _self->model_4886 = model_4886;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments_run__experiments_fun6951(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun6951__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__experiments_fun6951__t*, _fself);
  kk_function_t model_4886 = _self->model_4886; /* () -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random,console,ndet,effects-and-types/sample> (double, double) */
  kk_drop_match(_self, {kk_function_dup(model_4886);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x6952 = kk_function_call(kk_std_core_types__tuple2_, (kk_function_t, kk_context_t*), model_4886, (model_4886, _ctx)); /*(double, double)*/
  return kk_std_core_types__tuple2__box(_x6952, _ctx);
}
static kk_box_t kk_climate_dash_experiments_run__experiments_fun6950(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun6950__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__experiments_fun6950__t*, _fself);
  kk_function_t model_4886 = _self->model_4886; /* () -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random,console,ndet,effects-and-types/sample> (double, double) */
  kk_drop_match(_self, {kk_function_dup(model_4886);}, {}, _ctx)
  return kk_handlers_yield__on__score(kk_climate_dash_experiments_new_run__experiments_fun6951(model_4886, _ctx), _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments_run__experiments_fun6953__t {
  struct kk_function_s _base;
  kk_function_t _bv_6069;
};
static kk_std_core_types__tuple2_ kk_climate_dash_experiments_run__experiments_fun6953(kk_function_t _fself, kk_integer_t _b_6070, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__experiments_fun6953(kk_function_t _bv_6069, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun6953__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__experiments_fun6953__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__experiments_fun6953, kk_context());
  _self->_bv_6069 = _bv_6069;
  return &_self->_base;
}

static kk_std_core_types__tuple2_ kk_climate_dash_experiments_run__experiments_fun6953(kk_function_t _fself, kk_integer_t _b_6070, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun6953__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__experiments_fun6953__t*, _fself);
  kk_function_t _bv_6069 = _self->_bv_6069; /* (steps : int) -> <effects-and-types/yield|1> 0 */
  kk_drop_match(_self, {kk_function_dup(_bv_6069);}, {}, _ctx)
  kk_box_t _x6954 = kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_context_t*), _bv_6069, (_bv_6069, _b_6070, _ctx)); /*0*/
  return kk_std_core_types__tuple2__unbox(_x6954, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments_run__experiments_fun6955__t {
  struct kk_function_s _base;
  kk_function_t _bv_6075;
};
static kk_box_t kk_climate_dash_experiments_run__experiments_fun6955(kk_function_t _fself, kk_box_t _b_6076, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__experiments_fun6955(kk_function_t _bv_6075, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun6955__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__experiments_fun6955__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__experiments_fun6955, kk_context());
  _self->_bv_6075 = _bv_6075;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments_run__experiments_fun6955(kk_function_t _fself, kk_box_t _b_6076, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun6955__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__experiments_fun6955__t*, _fself);
  kk_function_t _bv_6075 = _self->_bv_6075; /* (steps : int) -> <effects-and-types/yield,effects-and-types/sample,effects-and-types/score,div,exn,std/num/random/random,console,ndet,effects-and-types/sample> (double, double) */
  kk_drop_match(_self, {kk_function_dup(_bv_6075);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x6956;
  kk_integer_t _x6957 = kk_integer_unbox(_b_6076); /*int*/
  _x6956 = kk_function_call(kk_std_core_types__tuple2_, (kk_function_t, kk_integer_t, kk_context_t*), _bv_6075, (_bv_6075, _x6957, _ctx)); /*(double, double)*/
  return kk_std_core_types__tuple2__box(_x6956, _ctx);
}
static kk_box_t kk_climate_dash_experiments_run__experiments_fun6948(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun6948__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__experiments_fun6948__t*, _fself);
  kk_function_t model_4886 = _self->model_4886; /* () -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random,console,ndet,effects-and-types/sample> (double, double) */
  kk_drop_match(_self, {kk_function_dup(model_4886);}, {}, _ctx)
  kk_function_t _x6949;
  kk_function_t _bv_6075;
  kk_function_t _bv_6069 = kk_handlers_advance(kk_climate_dash_experiments_new_run__experiments_fun6950(model_4886, _ctx), _ctx); /*(steps : int) -> <effects-and-types/yield|1> 0*/;
  _bv_6075 = kk_climate_dash_experiments_new_run__experiments_fun6953(_bv_6069, _ctx); /*(steps : int) -> <effects-and-types/yield,effects-and-types/sample,effects-and-types/score,div,exn,std/num/random/random,console,ndet,effects-and-types/sample> (double, double)*/
  _x6949 = kk_climate_dash_experiments_new_run__experiments_fun6955(_bv_6075, _ctx); /*(6073) -> <effects-and-types/yield,effects-and-types/sample,effects-and-types/score,div,exn,std/num/random/random,console,ndet,effects-and-types/sample> 6074*/
  return kk_function_box(_x6949);
}


// lift anonymous function
struct kk_climate_dash_experiments_run__experiments_fun6959__t {
  struct kk_function_s _base;
  kk_integer_t sz;
};
static kk_box_t kk_climate_dash_experiments_run__experiments_fun6959(kk_function_t _fself, kk_box_t _b_6082, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__experiments_fun6959(kk_integer_t sz, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun6959__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__experiments_fun6959__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__experiments_fun6959, kk_context());
  _self->sz = sz;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments_run__experiments_fun6959(kk_function_t _fself, kk_box_t _b_6082, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun6959__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__experiments_fun6959__t*, _fself);
  kk_integer_t sz = _self->sz; /* int */
  kk_drop_match(_self, {kk_integer_dup(sz);}, {}, _ctx)
  kk_std_core__list _x6960;
  kk_std_core__list _x6961 = kk_std_core__list_unbox(_b_6082, _ctx); /*effects-and-types/histogram<(steps : int) -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random,console,ndet,effects-and-types/sample> (double, double)>*/
  _x6960 = kk_smc__mlift512_smc(true, kk_integer_from_small(1), sz, _x6961, _ctx); /*effects-and-types/histogram<1>*/
  return kk_std_core__list_box(_x6960, _ctx);
}
static kk_box_t kk_climate_dash_experiments_run__experiments_fun6946(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun6946__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__experiments_fun6946__t*, _fself);
  kk_function_t model_4886 = _self->model_4886; /* () -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random,console,ndet,effects-and-types/sample> (double, double) */
  kk_integer_t sz = _self->sz; /* int */
  kk_drop_match(_self, {kk_function_dup(model_4886);kk_integer_dup(sz);}, {}, _ctx)
  kk_std_core__list _x6947;
  kk_std_core__list x_538 = kk_sampling_populate(kk_integer_from_small(100), kk_climate_dash_experiments_new_run__experiments_fun6948(model_4886, _ctx), _ctx); /*effects-and-types/histogram<(steps : int) -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random,console,ndet,effects-and-types/sample> (double, double)>*/;
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_538, _ctx);
    kk_box_t _x6958 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments_new_run__experiments_fun6959(sz, _ctx), _ctx); /*2*/
    _x6947 = kk_std_core__list_unbox(_x6958, _ctx); /*effects-and-types/histogram<(double, double)>*/
  }
  else {
    _x6947 = kk_smc__mlift512_smc(true, kk_integer_from_small(1), sz, x_538, _ctx); /*effects-and-types/histogram<(double, double)>*/
  }
  return kk_std_core__list_box(_x6947, _ctx);
}
static kk_box_t kk_climate_dash_experiments_run__experiments_fun6930(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun6930__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__experiments_fun6930__t*, _fself);
  kk_std_core__list data__vals = _self->data__vals; /* list<(double, bool)> */
  kk_integer_t sz = _self->sz; /* int */
  kk_drop_match(_self, {kk_std_core__list_dup(data__vals);kk_integer_dup(sz);}, {}, _ctx)
  kk_std_core__list _x6931;
  kk_function_t model_4886;
  kk_function_t _x01_4675;
  kk_function_t _bv_6052;
  kk_box_t _x6932 = kk_std_core_hnd__open_none1(kk_climate_dash_experiments_new_run__experiments_fun6933(_ctx), kk_std_core__list_box(data__vals, _ctx), _ctx); /*2*/
  _bv_6052 = kk_function_unbox(_x6932); /*() -> <.Box|.Box> 6051*/
  _x01_4675 = kk_climate_dash_experiments_new_run__experiments_fun6938(_bv_6052, _ctx); /*effects-and-types/model<(double, double),div>*/
  model_4886 = kk_climate_dash_experiments_new_run__experiments_fun6940(_x01_4675, _ctx); /*() -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random,console,ndet,effects-and-types/sample> (double, double)*/
  kk_box_t _x6945 = kk_handlers_random__sampler(kk_climate_dash_experiments_new_run__experiments_fun6946(model_4886, sz, _ctx), _ctx); /*0*/
  _x6931 = kk_std_core__list_unbox(_x6945, _ctx); /*effects-and-types/histogram<(double, double)>*/
  return kk_std_core__list_box(_x6931, _ctx);
}
static kk_box_t kk_climate_dash_experiments_run__experiments_fun6927(kk_function_t _fself, kk_box_t _b_6088, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core_types__tuple2_ _match_6182 = kk_std_core_types__tuple2__unbox(_b_6088, _ctx); /*(int, list<(double, bool)>)*/;
  kk_box_t _box_x6044 = _match_6182.fst;
  kk_box_t _box_x6045 = _match_6182.snd;
  kk_integer_t sz = kk_integer_unbox(_box_x6044);
  kk_std_core__list data__vals = kk_std_core__list_unbox(_box_x6045, NULL);
  kk_std_core__list_dup(data__vals);
  kk_integer_dup(sz);
  kk_std_core_types__tuple2__drop(_match_6182, _ctx);
  return kk_std_time_timer_print_elapsed(kk_climate_dash_experiments_new_run__experiments_fun6930(data__vals, sz, _ctx), kk_std_core_types__new_None(_ctx), _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments_run__experiments_fun6963__t {
  struct kk_function_s _base;
  kk_integer_t i10;
  kk_std_core__list x0_4860;
  kk_std_core__list x3_4869;
};
static kk_box_t kk_climate_dash_experiments_run__experiments_fun6963(kk_function_t _fself, kk_box_t _b_6098, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_run__experiments_fun6963(kk_integer_t i10, kk_std_core__list x0_4860, kk_std_core__list x3_4869, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun6963__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments_run__experiments_fun6963__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments_run__experiments_fun6963, kk_context());
  _self->i10 = i10;
  _self->x0_4860 = x0_4860;
  _self->x3_4869 = x3_4869;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments_run__experiments_fun6963(kk_function_t _fself, kk_box_t _b_6098, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun6963__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__experiments_fun6963__t*, _fself);
  kk_integer_t i10 = _self->i10; /* int */
  kk_std_core__list x0_4860 = _self->x0_4860; /* list<(int, list<(double, bool)>)> */
  kk_std_core__list x3_4869 = _self->x3_4869; /* list<(double, bool)> */
  kk_drop_match(_self, {kk_integer_dup(i10);kk_std_core__list_dup(x0_4860);kk_std_core__list_dup(x3_4869);}, {}, _ctx)
  kk_unit_t _x6964 = kk_Unit;
  kk_std_core__list _x6965 = kk_std_core__list_unbox(_b_6098, _ctx); /*list<effects-and-types/histogram<(double, double)>>*/
  kk_climate_dash_experiments__mlift4694_run__experiments(x3_4869, x0_4860, i10, _x6965, _ctx);
  return kk_unit_box(_x6964);
}
static kk_unit_t kk_climate_dash_experiments_run__experiments_fun6919(kk_function_t _fself, kk_integer_t i10, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments_run__experiments_fun6919__t* _self = kk_function_as(struct kk_climate_dash_experiments_run__experiments_fun6919__t*, _fself);
  kk_std_core__list x0_4860 = _self->x0_4860; /* list<(int, list<(double, bool)>)> */
  kk_std_core__list x3_4869 = _self->x3_4869; /* list<(double, bool)> */
  kk_drop_match(_self, {kk_std_core__list_dup(x0_4860);kk_std_core__list_dup(x3_4869);}, {}, _ctx)
  kk_unit_t __ = kk_Unit;
  kk_string_t s_4879;
  kk_string_t _x6920;
  kk_define_string_literal(, _s6921, 7, "Round #")
  _x6920 = kk_string_dup(_s6921); /*string*/
  kk_string_t _x6922;
  kk_integer_t _x6923 = kk_integer_dup(i10); /*int*/
  _x6922 = kk_std_core_show(_x6923, _ctx); /*string*/
  s_4879 = kk_std_core__lp__plus__plus__1_rp_(_x6920, _x6922, _ctx); /*string*/
  kk_std_core_printsln(s_4879, _ctx);
  kk_unit_t __0 = kk_Unit;
  kk_string_t _x6924;
  kk_define_string_literal(, _s6925, 38, "Running SMC with increasing data size:")
  _x6924 = kk_string_dup(_s6925); /*string*/
  kk_std_core_printsln(_x6924, _ctx);
  kk_std_core__list x5_4881;
  kk_std_core__list _x6926 = kk_std_core__list_dup(x0_4860); /*list<(int, list<(double, bool)>)>*/
  x5_4881 = kk_std_core_map_5(_x6926, kk_climate_dash_experiments_new_run__experiments_fun6927(_ctx), _ctx); /*list<effects-and-types/histogram<(double, double)>>*/
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x5_4881, _ctx);
    kk_box_t _x6962 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments_new_run__experiments_fun6963(i10, x0_4860, x3_4869, _ctx), _ctx); /*2*/
    return kk_unit_unbox(_x6962);
  }
  return kk_climate_dash_experiments__mlift4694_run__experiments(x3_4869, x0_4860, i10, x5_4881, _ctx);
}

kk_unit_t kk_climate_dash_experiments_run__experiments(kk_std_core_types__optional number__of__repeats, kk_std_core_types__optional max__number__of__data__points, kk_context_t* _ctx) { /* (number_of_repeats : optional<int>, max_number_of_data_points : optional<int>) -> <pure,console,ndet,std/num/random/random,effects-and-types/sample> () */ 
  kk_std_core__list x_4854;
  kk_std_core__list _b_5995_5992;
  kk_integer_t _x6887;
  if (kk_std_core_types__is_Optional(max__number__of__data__points)) {
    kk_box_t _box_x5991 = max__number__of__data__points._cons.Optional.value;
    kk_integer_t _max__number__of__data__points_2663 = kk_integer_unbox(_box_x5991);
    kk_integer_dup(_max__number__of__data__points_2663);
    kk_std_core_types__optional_drop(max__number__of__data__points, _ctx);
    _x6887 = _max__number__of__data__points_2663; /*int*/
    goto _match6888;
  }
  _x6887 = kk_integer_from_small(3); /*int*/
  _match6888: ;
  _b_5995_5992 = kk_std_core__lift21053_list(kk_integer_from_small(0), _x6887, kk_std_core__new_Nil(_ctx), _ctx); /*list<int>*/
  x_4854 = kk_std_core_map_5(_b_5995_5992, kk_climate_dash_experiments_new_run__experiments_fun6890(_ctx), _ctx); /*list<int>*/
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_4854, _ctx);
    kk_box_t _x6893 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments_new_run__experiments_fun6894(number__of__repeats, _ctx), _ctx); /*2*/
    kk_unit_unbox(_x6893); return kk_Unit;
  }
  kk_std_core__list x0_4860 = kk_std_core_map_5(x_4854, kk_climate_dash_experiments_new_run__experiments_fun6897(_ctx), _ctx); /*list<(int, list<(double, bool)>)>*/;
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x0_4860, _ctx);
    kk_box_t _x6909 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments_new_run__experiments_fun6910(number__of__repeats, _ctx), _ctx); /*2*/
    kk_unit_unbox(_x6909); return kk_Unit;
  }
  kk_std_core__list x3_4869;
  size_t i2_4872 = ((size_t)1); /*std/core/hnd/ev-index*/;
  kk_evv_t w0 = kk_evv_swap_create1(i2_4872,kk_context()); /*std/core/hnd/evv<<std/num/random/random,console,div,exn,ndet,effects-and-types/sample>>*/;
  kk_std_core__list y0 = kk_model_dash_resources_generate__synthetic__lr__data(kk_integer_from_small(50), _ctx); /*list<(double, bool)>*/;
  kk_unit_t __w_l700_c90 = kk_Unit;
  kk_evv_set(w0,kk_context());
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(y0, _ctx);
    kk_box_t _x6913 = kk_std_core_hnd_yield_cont(kk_climate_dash_experiments_new_run__experiments_fun6914(i2_4872, _ctx), _ctx); /*3*/
    x3_4869 = kk_std_core__list_unbox(_x6913, _ctx); /*list<(double, bool)>*/
  }
  else {
    x3_4869 = y0; /*list<(double, bool)>*/
  }
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x3_4869, _ctx);
    kk_box_t _x6915 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments_new_run__experiments_fun6916(number__of__repeats, x0_4860, _ctx), _ctx); /*2*/
    kk_unit_unbox(_x6915); return kk_Unit;
  }
  kk_integer_t _x6966;
  if (kk_std_core_types__is_Optional(number__of__repeats)) {
    kk_box_t _box_x6099 = number__of__repeats._cons.Optional.value;
    kk_integer_t _number__of__repeats_2659 = kk_integer_unbox(_box_x6099);
    kk_integer_dup(_number__of__repeats_2659);
    kk_std_core_types__optional_drop(number__of__repeats, _ctx);
    _x6966 = _number__of__repeats_2659; /*int*/
    goto _match6967;
  }
  _x6966 = kk_integer_from_small(4); /*int*/
  _match6967: ;
  kk_std_core__lift21056_for(kk_climate_dash_experiments_new_run__experiments_fun6919(x0_4860, x3_4869, _ctx), _x6966, kk_integer_from_small(1), _ctx); return kk_Unit;
}
 
// monadic lift

kk_unit_t kk_climate_dash_experiments__mlift4699_main(kk_std_core__list wild__0, kk_context_t* _ctx) { /* (wild_0 : list<()>) -> <pure,console,fsys,ndet,std/num/random/random> () */ 
  kk_std_core__list_drop(wild__0, _ctx);
  kk_unit_t __1 = kk_Unit;
  kk_string_t _x6969;
  kk_define_string_literal(, _s6970, 24, "Completed Climate Model!")
  _x6969 = kk_string_dup(_s6970); /*string*/
  kk_std_core_printsln(_x6969, _ctx);
  kk_string_t _x6971;
  kk_define_string_literal(, _s6972, 19, "Finished running...")
  _x6971 = kk_string_dup(_s6972); /*string*/
  kk_std_core_printsln(_x6971, _ctx); return kk_Unit;
}


// lift anonymous function
struct kk_climate_dash_experiments_main_fun6977__t {
  struct kk_function_s _base;
};
static kk_box_t kk_climate_dash_experiments_main_fun6977(kk_function_t _fself, kk_box_t _b_6111, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments_new_main_fun6977(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_climate_dash_experiments_main_fun6977, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_climate_dash_experiments_main_fun6977(kk_function_t _fself, kk_box_t _b_6111, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_unit_t _x6978 = kk_Unit;
  kk_std_core__list _x6979 = kk_std_core__list_unbox(_b_6111, _ctx); /*list<()>*/
  kk_climate_dash_experiments__mlift4699_main(_x6979, _ctx);
  return kk_unit_box(_x6978);
}

kk_unit_t kk_climate_dash_experiments_main(kk_context_t* _ctx) { /* () -> <pure,console,fsys,ndet,std/num/random/random> () */ 
  kk_unit_t __ = kk_Unit;
  kk_string_t _x6973;
  kk_define_string_literal(, _s6974, 24, "Running Climate Model...")
  _x6973 = kk_string_dup(_s6974); /*string*/
  kk_std_core_printsln(_x6973, _ctx);
  kk_std_core__list x_4891;
  kk_std_core_types__optional _x6975 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(8)), _ctx); /*optional<35>*/
  x_4891 = kk_climate_dash_experiments_run__climate__model(kk_integer_from_small(2000), kk_integer_from_small(131), kk_integer_from_small(2), kk_integer_from_int(100000, _ctx), kk_integer_from_int(80000, _ctx), _x6975, _ctx); /*list<()>*/
  kk_std_core__list_drop(x_4891, _ctx);
  if (kk_yielding(kk_context())) {
    kk_box_t _x6976 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments_new_main_fun6977(_ctx), _ctx); /*2*/
    kk_unit_unbox(_x6976); return kk_Unit;
  }
  kk_unit_t __1 = kk_Unit;
  kk_string_t _x6980;
  kk_define_string_literal(, _s6981, 24, "Completed Climate Model!")
  _x6980 = kk_string_dup(_s6981); /*string*/
  kk_std_core_printsln(_x6980, _ctx);
  kk_string_t _x6982;
  kk_define_string_literal(, _s6983, 19, "Finished running...")
  _x6982 = kk_string_dup(_s6983); /*string*/
  kk_std_core_printsln(_x6982, _ctx); return kk_Unit;
}


// lift anonymous function
struct kk_climate_dash_experiments__hmain_fun6985__t {
  struct kk_function_s _base;
};
static kk_box_t kk_climate_dash_experiments__hmain_fun6985(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_hmain_fun6985(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_climate_dash_experiments__hmain_fun6985, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_climate_dash_experiments__hmain_fun6985(kk_function_t _fself, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  int32_t _x6986 = kk_std_num_random_srandom_int32(_ctx); /*int32*/
  return kk_int32_box(_x6986, _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__hmain_fun6988__t {
  struct kk_function_s _base;
};
static kk_box_t kk_climate_dash_experiments__hmain_fun6988(kk_function_t _fself, kk_box_t _b_6135, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_hmain_fun6988(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_climate_dash_experiments__hmain_fun6988, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_climate_dash_experiments__hmain_fun6988(kk_function_t _fself, kk_box_t _b_6135, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return _b_6135;
}


// lift anonymous function
struct kk_climate_dash_experiments__hmain_fun6989__t {
  struct kk_function_s _base;
};
static kk_box_t kk_climate_dash_experiments__hmain_fun6989(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_hmain_fun6989(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_climate_dash_experiments__hmain_fun6989, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_climate_dash_experiments__hmain_fun6992__t {
  struct kk_function_s _base;
};
static kk_box_t kk_climate_dash_experiments__hmain_fun6992(kk_function_t _fself, kk_std_core_hnd__marker _b_6119, kk_std_core_hnd__ev _b_6120, kk_box_t _b_6121, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_hmain_fun6992(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_climate_dash_experiments__hmain_fun6992, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_climate_dash_experiments__hmain_fun6993__t {
  struct kk_function_s _base;
  kk_box_t _b_6121;
};
static kk_box_t kk_climate_dash_experiments__hmain_fun6993(kk_function_t _fself, kk_function_t _b_6116, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_hmain_fun6993(kk_box_t _b_6121, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__hmain_fun6993__t* _self = kk_function_alloc_as(struct kk_climate_dash_experiments__hmain_fun6993__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_experiments__hmain_fun6993, kk_context());
  _self->_b_6121 = _b_6121;
  return &_self->_base;
}

static kk_box_t kk_climate_dash_experiments__hmain_fun6993(kk_function_t _fself, kk_function_t _b_6116, kk_context_t* _ctx) {
  struct kk_climate_dash_experiments__hmain_fun6993__t* _self = kk_function_as(struct kk_climate_dash_experiments__hmain_fun6993__t*, _fself);
  kk_box_t _b_6121 = _self->_b_6121; /* 16 */
  kk_drop_match(_self, {kk_box_dup(_b_6121);}, {}, _ctx)
  kk_function_drop(_b_6116, _ctx);
  kk_unit_t _x6994 = kk_Unit;
  kk_unit_t __w_l2631_c17 = kk_Unit;
  kk_string_t _x6995;
  kk_define_string_literal(, _s6996, 20, "uncaught exception: ")
  _x6995 = kk_string_dup(_s6996); /*string*/
  kk_std_core_prints(_x6995, _ctx);
  kk_string_t _x6997;
  kk_std_core__exception _match_6176 = kk_std_core__exception_unbox(_b_6121, _ctx); /*exception*/;
  kk_string_t _x0 = _match_6176.message;
  kk_string_dup(_x0);
  kk_std_core__exception_drop(_match_6176, _ctx);
  _x6997 = _x0; /*string*/
  kk_std_core_printsln(_x6997, _ctx);
  return kk_unit_box(_x6994);
}
static kk_box_t kk_climate_dash_experiments__hmain_fun6992(kk_function_t _fself, kk_std_core_hnd__marker _b_6119, kk_std_core_hnd__ev _b_6120, kk_box_t _b_6121, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core_hnd__ev_dropn(_b_6120, ((int32_t)3), _ctx);
  return kk_std_core_hnd_yield_to_final(_b_6119, kk_climate_dash_experiments__new_hmain_fun6993(_b_6121, _ctx), _ctx);
}


// lift anonymous function
struct kk_climate_dash_experiments__hmain_fun6999__t {
  struct kk_function_s _base;
};
static kk_box_t kk_climate_dash_experiments__hmain_fun6999(kk_function_t _fself, kk_box_t _b_6130, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_hmain_fun6999(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_climate_dash_experiments__hmain_fun6999, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_climate_dash_experiments__hmain_fun6999(kk_function_t _fself, kk_box_t _b_6130, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return _b_6130;
}


// lift anonymous function
struct kk_climate_dash_experiments__hmain_fun7000__t {
  struct kk_function_s _base;
};
static kk_box_t kk_climate_dash_experiments__hmain_fun7000(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_hmain_fun7000(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_climate_dash_experiments__hmain_fun7000, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_climate_dash_experiments__hmain_fun7006__t {
  struct kk_function_s _base;
};
static kk_box_t kk_climate_dash_experiments__hmain_fun7006(kk_function_t _fself, kk_box_t _b_6125, kk_context_t* _ctx);
static kk_function_t kk_climate_dash_experiments__new_hmain_fun7006(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_climate_dash_experiments__hmain_fun7006, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_climate_dash_experiments__hmain_fun7006(kk_function_t _fself, kk_box_t _b_6125, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_unit_t _x7007 = kk_Unit;
  kk_std_core__list _x7008 = kk_std_core__list_unbox(_b_6125, _ctx); /*list<()>*/
  kk_climate_dash_experiments__mlift4699_main(_x7008, _ctx);
  return kk_unit_box(_x7007);
}
static kk_box_t kk_climate_dash_experiments__hmain_fun7000(kk_function_t _fself, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_unit_t _x7001 = kk_Unit;
  kk_unit_t __ = kk_Unit;
  kk_string_t _x7002;
  kk_define_string_literal(, _s7003, 24, "Running Climate Model...")
  _x7002 = kk_string_dup(_s7003); /*string*/
  kk_std_core_printsln(_x7002, _ctx);
  kk_std_core__list x_4899;
  kk_std_core_types__optional _x7004 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(8)), _ctx); /*optional<35>*/
  x_4899 = kk_climate_dash_experiments_run__climate__model(kk_integer_from_small(2000), kk_integer_from_small(131), kk_integer_from_small(2), kk_integer_from_int(100000, _ctx), kk_integer_from_int(80000, _ctx), _x7004, _ctx); /*list<()>*/
  kk_std_core__list_drop(x_4899, _ctx);
  if (kk_yielding(kk_context())) {
    kk_box_t _x7005 = kk_std_core_hnd_yield_extend(kk_climate_dash_experiments__new_hmain_fun7006(_ctx), _ctx); /*2*/
    kk_unit_unbox(_x7005);
  }
  else {
    kk_unit_t __1 = kk_Unit;
    kk_string_t _x7009;
    kk_define_string_literal(, _s7010, 24, "Completed Climate Model!")
    _x7009 = kk_string_dup(_s7010); /*string*/
    kk_std_core_printsln(_x7009, _ctx);
    kk_string_t _x7011;
    kk_define_string_literal(, _s7012, 19, "Finished running...")
    _x7011 = kk_string_dup(_s7012); /*string*/
    kk_std_core_printsln(_x7011, _ctx);
  }
  return kk_unit_box(_x7001);
}
static kk_box_t kk_climate_dash_experiments__hmain_fun6989(kk_function_t _fself, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_unit_t _x6990 = kk_Unit;
  int32_t _b_6142_6126 = ((int32_t)0); /*int32*/;
  kk_std_core__hnd_exn _b_6143_6127;
  kk_std_core_hnd__clause1 _x6991 = kk_std_core_hnd__new_Clause1(kk_climate_dash_experiments__new_hmain_fun6992(_ctx), _ctx); /*std/core/hnd/clause1<16,17,18,19,20>*/
  _b_6143_6127 = kk_std_core__new_Hnd_exn(kk_reuse_null, _x6991, _ctx); /*.hnd-exn<<console,div,fsys,ndet,std/num/random/random>,()>*/
  kk_box_t _x6998 = kk_std_core__handle_exn(_b_6142_6126, _b_6143_6127, kk_climate_dash_experiments__new_hmain_fun6999(_ctx), kk_climate_dash_experiments__new_hmain_fun7000(_ctx), _ctx); /*3*/
  kk_unit_unbox(_x6998);
  return kk_unit_box(_x6990);
}

kk_unit_t kk_climate_dash_experiments__hmain(kk_context_t* _ctx) { /* () -> <console,div,fsys,ndet> () */ 
  int32_t _b_6136_6131 = ((int32_t)1); /*int32*/;
  kk_std_num_random__hnd_random _b_6137_6132;
  kk_std_core_hnd__clause0 _x6984 = kk_std_core_hnd_clause_tail_noyield0(kk_climate_dash_experiments__new_hmain_fun6985(_ctx), _ctx); /*std/core/hnd/clause0<3,4,1,2>*/
  _b_6137_6132 = kk_std_num_random__new_Hnd_random(kk_reuse_null, _x6984, _ctx); /*std/num/random/.hnd-random<<ndet,console,div,fsys>,()>*/
  kk_box_t _x6987 = kk_std_num_random__handle_random(_b_6136_6131, _b_6137_6132, kk_climate_dash_experiments__new_hmain_fun6988(_ctx), kk_climate_dash_experiments__new_hmain_fun6989(_ctx), _ctx); /*2*/
  kk_unit_unbox(_x6987); return kk_Unit;
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
  kk_std_time_timer__init(_ctx);
  kk_std_os_path__init(_ctx);
  kk_std_os_dir__init(_ctx);
  kk_std_os_file__init(_ctx);
  kk_effects_dash_and_dash_types__init(_ctx);
  kk_output_dash_and_dash_plot__init(_ctx);
  kk_exponents__init(_ctx);
  kk_handlers__init(_ctx);
  kk_sampling__init(_ctx);
  kk_smc__init(_ctx);
  kk_model_dash_resources__init(_ctx);
  kk_tmcmc__init(_ctx);
  kk_pmmh__init(_ctx);
  kk_exn_dash_get__init(_ctx);
  kk_climate_dash_change__init(_ctx);
  kk_data_preprocessing__init(_ctx);
}
