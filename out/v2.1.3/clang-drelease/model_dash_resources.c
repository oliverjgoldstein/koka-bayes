// Koka generated module: "model-resources", koka version: 2.1.3
#include "model_dash_resources.h"
 
// monadic lift

bool kk_model_dash_resources__mlift3168_bernoulli(double p, double g, kk_context_t* _ctx) { /* (p : double, g : double) -> effects-and-types/sample bool */ 
  bool _match_4506 = (g < p); /*bool*/;
  if (_match_4506) {
    return true;
  }
  return false;
}


// lift anonymous function
struct kk_model_dash_resources_bernoulli_fun4508__t {
  struct kk_function_s _base;
  double p;
};
static kk_box_t kk_model_dash_resources_bernoulli_fun4508(kk_function_t _fself, kk_box_t _b_3503, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources_new_bernoulli_fun4508(double p, kk_context_t* _ctx) {
  struct kk_model_dash_resources_bernoulli_fun4508__t* _self = kk_function_alloc_as(struct kk_model_dash_resources_bernoulli_fun4508__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_model_dash_resources_bernoulli_fun4508, kk_context());
  _self->p = p;
  return &_self->_base;
}

static kk_box_t kk_model_dash_resources_bernoulli_fun4508(kk_function_t _fself, kk_box_t _b_3503, kk_context_t* _ctx) {
  struct kk_model_dash_resources_bernoulli_fun4508__t* _self = kk_function_as(struct kk_model_dash_resources_bernoulli_fun4508__t*, _fself);
  double p = _self->p; /* double */
  kk_drop_match(_self, {;}, {}, _ctx)
  bool _x4509;
  double _x4510 = kk_double_unbox(_b_3503, _ctx); /*double*/
  _x4509 = kk_model_dash_resources__mlift3168_bernoulli(p, _x4510, _ctx); /*bool*/
  return kk_bool_box(_x4509);
}

bool kk_model_dash_resources_bernoulli(double p, kk_context_t* _ctx) { /* (p : double) -> effects-and-types/sample bool */ 
  double x_3198 = kk_effects_dash_and_dash_types_sample(_ctx); /*double*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x4507 = kk_std_core_hnd_yield_extend(kk_model_dash_resources_new_bernoulli_fun4508(p, _ctx), _ctx); /*2*/
    return kk_bool_unbox(_x4507);
  }
  bool _match_4505 = (x_3198 < p); /*bool*/;
  if (_match_4505) {
    return true;
  }
  return false;
}

double kk_model_dash_resources_box_muller(double u1, double u2, kk_context_t* _ctx) { /* (u1 : double, u2 : double) -> double */ 
  double _x4511;
  double _x4512;
  double _x4513 = log(u1); /*double*/
  _x4512 = ((-0x1p1) * _x4513); /*double*/
  _x4511 = sqrt(_x4512); /*double*/
  double _x4514;
  double _x4515 = ((0x1.921fb54442d18p2) * u2); /*double*/
  _x4514 = cos(_x4515); /*double*/
  return (_x4511 * _x4514);
}

kk_std_core__list kk_model_dash_resources_dataset;

kk_std_core__list kk_model_dash_resources_gaussian__dataset;

kk_std_core__list kk_model_dash_resources_gaussian__five;

kk_effects_dash_and_dash_types__exp kk_model_dash_resources_normal__pdf(double mean, double sdv, double x, kk_context_t* _ctx) { /* (mean : double, sdv : double, x : double) -> effects-and-types/exp */ 
  kk_effects_dash_and_dash_types__exp _pat__30__13_3202;
  double _x4516;
  double _x4517;
  double _x4518;
  double x0_3204 = (x - mean); /*double*/;
  _x4518 = (x0_3204 * x0_3204); /*double*/
  double _x4519;
  double _x4520 = kk_model_dash_resources_square(sdv, _ctx); /*double*/
  _x4519 = (0x1p1 * _x4520); /*double*/
  _x4517 = (_x4518 / _x4519); /*double*/
  _x4516 = ((0x0p+0) - _x4517); /*double*/
  _pat__30__13_3202 = kk_effects_dash_and_dash_types__new_Exp(_x4516, _ctx); /*effects-and-types/exp*/
  kk_effects_dash_and_dash_types__exp _pat__30__28_3203;
  double x1_3205;
  double _x4521;
  double _x4522;
  double _x4523 = (0x1p1 * (0x1.921fb54442d18p1)); /*double*/
  _x4522 = sqrt(_x4523); /*double*/
  _x4521 = (sdv * _x4522); /*double*/
  x1_3205 = log(_x4521); /*double*/
  _pat__30__28_3203 = kk_effects_dash_and_dash_types__new_Exp(x1_3205, _ctx); /*effects-and-types/exp*/
  double xe = _pat__30__13_3202.i;
  double ye = _pat__30__28_3203.i;
  double _x4524 = (xe - ye); /*double*/
  return kk_effects_dash_and_dash_types__new_Exp(_x4524, _ctx);
}
 
// monadic lift

kk_function_t kk_model_dash_resources__mlift3169_fit(kk_function_t f, kk_std_core__list wild__, kk_context_t* _ctx) { /* (f : (double) -> double, wild_ : list<()>) -> <effects-and-types/score,std/num/random/random,effects-and-types/sample> ((double) -> double) */ 
  kk_std_core__list_drop(wild__, _ctx);
  return f;
}
 
// monadic lift


// lift anonymous function
struct kk_model_dash_resources__mlift3170_fit_fun4526__t {
  struct kk_function_s _base;
  kk_function_t f;
};
static kk_box_t kk_model_dash_resources__mlift3170_fit_fun4526(kk_function_t _fself, kk_box_t _b_3663, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources__new_mlift3170_fit_fun4526(kk_function_t f, kk_context_t* _ctx) {
  struct kk_model_dash_resources__mlift3170_fit_fun4526__t* _self = kk_function_alloc_as(struct kk_model_dash_resources__mlift3170_fit_fun4526__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_model_dash_resources__mlift3170_fit_fun4526, kk_context());
  _self->f = f;
  return &_self->_base;
}



// lift anonymous function
struct kk_model_dash_resources__mlift3170_fit_fun4531__t {
  struct kk_function_s _base;
  kk_function_t f;
};
static kk_box_t kk_model_dash_resources__mlift3170_fit_fun4531(kk_function_t _fself, kk_box_t _b_3650, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources__new_mlift3170_fit_fun4531(kk_function_t f, kk_context_t* _ctx) {
  struct kk_model_dash_resources__mlift3170_fit_fun4531__t* _self = kk_function_alloc_as(struct kk_model_dash_resources__mlift3170_fit_fun4531__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_model_dash_resources__mlift3170_fit_fun4531, kk_context());
  _self->f = f;
  return &_self->_base;
}

static kk_box_t kk_model_dash_resources__mlift3170_fit_fun4531(kk_function_t _fself, kk_box_t _b_3650, kk_context_t* _ctx) {
  struct kk_model_dash_resources__mlift3170_fit_fun4531__t* _self = kk_function_as(struct kk_model_dash_resources__mlift3170_fit_fun4531__t*, _fself);
  kk_function_t f = _self->f; /* (double) -> double */
  kk_drop_match(_self, {kk_function_dup(f);}, {}, _ctx)
  double _x4532;
  double _x4533 = kk_double_unbox(_b_3650, _ctx); /*double*/
  _x4532 = kk_function_call(double, (kk_function_t, double, kk_context_t*), f, (f, _x4533, _ctx)); /*double*/
  return kk_double_box(_x4532, _ctx);
}


// lift anonymous function
struct kk_model_dash_resources__mlift3170_fit_fun4544__t {
  struct kk_function_s _base;
  size_t i_3212;
};
static kk_box_t kk_model_dash_resources__mlift3170_fit_fun4544(kk_function_t _fself, kk_function_t _b_3658, kk_box_t _b_3659, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources__new_mlift3170_fit_fun4544(size_t i_3212, kk_context_t* _ctx) {
  struct kk_model_dash_resources__mlift3170_fit_fun4544__t* _self = kk_function_alloc_as(struct kk_model_dash_resources__mlift3170_fit_fun4544__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_model_dash_resources__mlift3170_fit_fun4544, kk_context());
  _self->i_3212 = i_3212;
  return &_self->_base;
}

static kk_box_t kk_model_dash_resources__mlift3170_fit_fun4544(kk_function_t _fself, kk_function_t _b_3658, kk_box_t _b_3659, kk_context_t* _ctx) {
  struct kk_model_dash_resources__mlift3170_fit_fun4544__t* _self = kk_function_as(struct kk_model_dash_resources__mlift3170_fit_fun4544__t*, _fself);
  size_t i_3212 = _self->i_3212; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_3212, _b_3658, _b_3659, _ctx);
}
static kk_box_t kk_model_dash_resources__mlift3170_fit_fun4526(kk_function_t _fself, kk_box_t _b_3663, kk_context_t* _ctx) {
  struct kk_model_dash_resources__mlift3170_fit_fun4526__t* _self = kk_function_as(struct kk_model_dash_resources__mlift3170_fit_fun4526__t*, _fself);
  kk_function_t f = _self->f; /* (double) -> double */
  kk_drop_match(_self, {kk_function_dup(f);}, {}, _ctx)
  kk_unit_t _x4527 = kk_Unit;
  kk_std_core_types__tuple2_ _match_4502 = kk_std_core_types__tuple2__unbox(_b_3663, _ctx); /*(double, double)*/;
  kk_box_t _box_x3646 = _match_4502.fst;
  kk_box_t _box_x3647 = _match_4502.snd;
  double x0 = kk_double_unbox(_box_x3646, NULL);
  double y = kk_double_unbox(_box_x3647, NULL);
  kk_std_core_types__tuple2__drop(_match_4502, _ctx);
  kk_effects_dash_and_dash_types__exp _x1;
  double _x10;
  kk_box_t _x4530 = kk_std_core_hnd__open_none1(kk_model_dash_resources__new_mlift3170_fit_fun4531(f, _ctx), kk_double_box(x0, _ctx), _ctx); /*2*/
  _x10 = kk_double_unbox(_x4530, _ctx); /*double*/
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*std/core/hnd/evv<(<>)>*/;
  kk_effects_dash_and_dash_types__exp x4;
  kk_effects_dash_and_dash_types__exp _pat__30__13_3202;
  double _x4534;
  double _x4535;
  double _x4536;
  double x0_3204 = (y - _x10); /*double*/;
  _x4536 = (x0_3204 * x0_3204); /*double*/
  double _x4537;
  double _x4538 = kk_model_dash_resources_square(0x1p-2, _ctx); /*double*/
  _x4537 = (0x1p1 * _x4538); /*double*/
  _x4535 = (_x4536 / _x4537); /*double*/
  _x4534 = ((0x0p+0) - _x4535); /*double*/
  _pat__30__13_3202 = kk_effects_dash_and_dash_types__new_Exp(_x4534, _ctx); /*effects-and-types/exp*/
  kk_effects_dash_and_dash_types__exp _pat__30__28_3203;
  double x1_3205;
  double _x4539;
  double _x4540;
  double _x4541 = (0x1p1 * (0x1.921fb54442d18p1)); /*double*/
  _x4540 = sqrt(_x4541); /*double*/
  _x4539 = ((0x1p-2) * _x4540); /*double*/
  x1_3205 = log(_x4539); /*double*/
  _pat__30__28_3203 = kk_effects_dash_and_dash_types__new_Exp(x1_3205, _ctx); /*effects-and-types/exp*/
  double xe = _pat__30__13_3202.i;
  double ye = _pat__30__28_3203.i;
  double _x4542 = (xe - ye); /*double*/
  x4 = kk_effects_dash_and_dash_types__new_Exp(_x4542, _ctx); /*effects-and-types/exp*/
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  _x1 = x4; /*effects-and-types/exp*/
  size_t i_3212 = ((size_t)2); /*std/core/hnd/ev-index*/;
  kk_evv_t w0 = kk_evv_swap_create1(i_3212,kk_context()); /*std/core/hnd/evv<<effects-and-types/score,std/num/random/random,effects-and-types/sample>>*/;
  kk_unit_t y0 = kk_Unit;
  kk_effects_dash_and_dash_types_score(_x1, _ctx);
  kk_unit_t __w_l700_c9 = kk_Unit;
  kk_evv_set(w0,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x4543 = kk_std_core_hnd_yield_cont(kk_model_dash_resources__new_mlift3170_fit_fun4544(i_3212, _ctx), _ctx); /*3*/
    kk_unit_unbox(_x4543);
  }
  else {
    y0;
  }
  return kk_unit_box(_x4527);
}


// lift anonymous function
struct kk_model_dash_resources__mlift3170_fit_fun4546__t {
  struct kk_function_s _base;
  kk_function_t f;
};
static kk_box_t kk_model_dash_resources__mlift3170_fit_fun4546(kk_function_t _fself, kk_box_t _b_3675, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources__new_mlift3170_fit_fun4546(kk_function_t f, kk_context_t* _ctx) {
  struct kk_model_dash_resources__mlift3170_fit_fun4546__t* _self = kk_function_alloc_as(struct kk_model_dash_resources__mlift3170_fit_fun4546__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_model_dash_resources__mlift3170_fit_fun4546, kk_context());
  _self->f = f;
  return &_self->_base;
}



// lift anonymous function
struct kk_model_dash_resources__mlift3170_fit_fun4549__t {
  struct kk_function_s _base;
  kk_function_t _bv_3678;
};
static kk_box_t kk_model_dash_resources__mlift3170_fit_fun4549(kk_function_t _fself, kk_box_t _b_3679, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources__new_mlift3170_fit_fun4549(kk_function_t _bv_3678, kk_context_t* _ctx) {
  struct kk_model_dash_resources__mlift3170_fit_fun4549__t* _self = kk_function_alloc_as(struct kk_model_dash_resources__mlift3170_fit_fun4549__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_model_dash_resources__mlift3170_fit_fun4549, kk_context());
  _self->_bv_3678 = _bv_3678;
  return &_self->_base;
}

static kk_box_t kk_model_dash_resources__mlift3170_fit_fun4549(kk_function_t _fself, kk_box_t _b_3679, kk_context_t* _ctx) {
  struct kk_model_dash_resources__mlift3170_fit_fun4549__t* _self = kk_function_as(struct kk_model_dash_resources__mlift3170_fit_fun4549__t*, _fself);
  kk_function_t _bv_3678 = _self->_bv_3678; /* (double) -> double */
  kk_drop_match(_self, {kk_function_dup(_bv_3678);}, {}, _ctx)
  double _x4550;
  double _x4551 = kk_double_unbox(_b_3679, _ctx); /*double*/
  _x4550 = kk_function_call(double, (kk_function_t, double, kk_context_t*), _bv_3678, (_bv_3678, _x4551, _ctx)); /*double*/
  return kk_double_box(_x4550, _ctx);
}
static kk_box_t kk_model_dash_resources__mlift3170_fit_fun4546(kk_function_t _fself, kk_box_t _b_3675, kk_context_t* _ctx) {
  struct kk_model_dash_resources__mlift3170_fit_fun4546__t* _self = kk_function_as(struct kk_model_dash_resources__mlift3170_fit_fun4546__t*, _fself);
  kk_function_t f = _self->f; /* (double) -> double */
  kk_drop_match(_self, {kk_function_dup(f);}, {}, _ctx)
  kk_function_t _x4547;
  kk_function_t _bv_3678;
  kk_std_core__list _x4548 = kk_std_core__list_unbox(_b_3675, _ctx); /*list<()>*/
  _bv_3678 = kk_model_dash_resources__mlift3169_fit(f, _x4548, _ctx); /*(double) -> double*/
  _x4547 = kk_model_dash_resources__new_mlift3170_fit_fun4549(_bv_3678, _ctx); /*(3676) -> 3677*/
  return kk_function_box(_x4547);
}


// lift anonymous function
struct kk_model_dash_resources__mlift3170_fit_fun4552__t {
  struct kk_function_s _base;
  kk_function_t _bv_3682;
};
static double kk_model_dash_resources__mlift3170_fit_fun4552(kk_function_t _fself, double _b_3683, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources__new_mlift3170_fit_fun4552(kk_function_t _bv_3682, kk_context_t* _ctx) {
  struct kk_model_dash_resources__mlift3170_fit_fun4552__t* _self = kk_function_alloc_as(struct kk_model_dash_resources__mlift3170_fit_fun4552__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_model_dash_resources__mlift3170_fit_fun4552, kk_context());
  _self->_bv_3682 = _bv_3682;
  return &_self->_base;
}

static double kk_model_dash_resources__mlift3170_fit_fun4552(kk_function_t _fself, double _b_3683, kk_context_t* _ctx) {
  struct kk_model_dash_resources__mlift3170_fit_fun4552__t* _self = kk_function_as(struct kk_model_dash_resources__mlift3170_fit_fun4552__t*, _fself);
  kk_function_t _bv_3682 = _self->_bv_3682; /* (3680) -> 3681 */
  kk_drop_match(_self, {kk_function_dup(_bv_3682);}, {}, _ctx)
  kk_box_t _x4553 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _bv_3682, (_bv_3682, kk_double_box(_b_3683, _ctx), _ctx)); /*3681*/
  return kk_double_unbox(_x4553, _ctx);
}

kk_function_t kk_model_dash_resources__mlift3170_fit(kk_std_core__list dataset0, kk_function_t f, kk_context_t* _ctx) { /* (dataset : effects-and-types/two_d_data, f : (double) -> double) -> <effects-and-types/sample,effects-and-types/score,std/num/random/random> ((double) -> double) */ 
  kk_std_core__list x_3206;
  kk_function_t _x4525;
  kk_function_dup(f);
  _x4525 = kk_model_dash_resources__new_mlift3170_fit_fun4526(f, _ctx); /*(1) -> 3 2*/
  x_3206 = kk_std_core_map_5(dataset0, _x4525, _ctx); /*list<()>*/
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_3206, _ctx);
    kk_function_t _bv_3682;
    kk_box_t _x4545 = kk_std_core_hnd_yield_extend(kk_model_dash_resources__new_mlift3170_fit_fun4546(f, _ctx), _ctx); /*2*/
    _bv_3682 = kk_function_unbox(_x4545); /*(3680) -> 3681*/
    return kk_model_dash_resources__new_mlift3170_fit_fun4552(_bv_3682, _ctx);
  }
  return kk_model_dash_resources__mlift3169_fit(f, x_3206, _ctx);
}


// lift anonymous function
struct kk_model_dash_resources_fit_fun4554__t {
  struct kk_function_s _base;
  kk_std_core__list dataset0;
  kk_function_t model;
};
static kk_function_t kk_model_dash_resources_fit_fun4554(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources_new_fit_fun4554(kk_std_core__list dataset0, kk_function_t model, kk_context_t* _ctx) {
  struct kk_model_dash_resources_fit_fun4554__t* _self = kk_function_alloc_as(struct kk_model_dash_resources_fit_fun4554__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_model_dash_resources_fit_fun4554, kk_context());
  _self->dataset0 = dataset0;
  _self->model = model;
  return &_self->_base;
}



// lift anonymous function
struct kk_model_dash_resources_fit_fun4556__t {
  struct kk_function_s _base;
  kk_std_core__list dataset0;
};
static kk_box_t kk_model_dash_resources_fit_fun4556(kk_function_t _fself, kk_box_t _b_3687, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources_new_fit_fun4556(kk_std_core__list dataset0, kk_context_t* _ctx) {
  struct kk_model_dash_resources_fit_fun4556__t* _self = kk_function_alloc_as(struct kk_model_dash_resources_fit_fun4556__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_model_dash_resources_fit_fun4556, kk_context());
  _self->dataset0 = dataset0;
  return &_self->_base;
}



// lift anonymous function
struct kk_model_dash_resources_fit_fun4558__t {
  struct kk_function_s _base;
  kk_box_t _b_3687;
};
static double kk_model_dash_resources_fit_fun4558(kk_function_t _fself, double _b_3690, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources_new_fit_fun4558(kk_box_t _b_3687, kk_context_t* _ctx) {
  struct kk_model_dash_resources_fit_fun4558__t* _self = kk_function_alloc_as(struct kk_model_dash_resources_fit_fun4558__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_model_dash_resources_fit_fun4558, kk_context());
  _self->_b_3687 = _b_3687;
  return &_self->_base;
}

static double kk_model_dash_resources_fit_fun4558(kk_function_t _fself, double _b_3690, kk_context_t* _ctx) {
  struct kk_model_dash_resources_fit_fun4558__t* _self = kk_function_as(struct kk_model_dash_resources_fit_fun4558__t*, _fself);
  kk_box_t _b_3687 = _self->_b_3687; /* 1 */
  kk_drop_match(_self, {kk_box_dup(_b_3687);}, {}, _ctx)
  kk_box_t _x4559;
  kk_function_t _x4560 = kk_function_unbox(_b_3687); /*(3688) -> 3689*/
  _x4559 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x4560, (_x4560, kk_double_box(_b_3690, _ctx), _ctx)); /*3689*/
  return kk_double_unbox(_x4559, _ctx);
}


// lift anonymous function
struct kk_model_dash_resources_fit_fun4561__t {
  struct kk_function_s _base;
  kk_function_t _bv_3693;
};
static kk_box_t kk_model_dash_resources_fit_fun4561(kk_function_t _fself, kk_box_t _b_3694, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources_new_fit_fun4561(kk_function_t _bv_3693, kk_context_t* _ctx) {
  struct kk_model_dash_resources_fit_fun4561__t* _self = kk_function_alloc_as(struct kk_model_dash_resources_fit_fun4561__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_model_dash_resources_fit_fun4561, kk_context());
  _self->_bv_3693 = _bv_3693;
  return &_self->_base;
}

static kk_box_t kk_model_dash_resources_fit_fun4561(kk_function_t _fself, kk_box_t _b_3694, kk_context_t* _ctx) {
  struct kk_model_dash_resources_fit_fun4561__t* _self = kk_function_as(struct kk_model_dash_resources_fit_fun4561__t*, _fself);
  kk_function_t _bv_3693 = _self->_bv_3693; /* (double) -> double */
  kk_drop_match(_self, {kk_function_dup(_bv_3693);}, {}, _ctx)
  double _x4562;
  double _x4563 = kk_double_unbox(_b_3694, _ctx); /*double*/
  _x4562 = kk_function_call(double, (kk_function_t, double, kk_context_t*), _bv_3693, (_bv_3693, _x4563, _ctx)); /*double*/
  return kk_double_box(_x4562, _ctx);
}
static kk_box_t kk_model_dash_resources_fit_fun4556(kk_function_t _fself, kk_box_t _b_3687, kk_context_t* _ctx) {
  struct kk_model_dash_resources_fit_fun4556__t* _self = kk_function_as(struct kk_model_dash_resources_fit_fun4556__t*, _fself);
  kk_std_core__list dataset0 = _self->dataset0; /* effects-and-types/two_d_data */
  kk_drop_match(_self, {kk_std_core__list_dup(dataset0);}, {}, _ctx)
  kk_function_t _x4557;
  kk_function_t _bv_3693 = kk_model_dash_resources__mlift3170_fit(dataset0, kk_model_dash_resources_new_fit_fun4558(_b_3687, _ctx), _ctx); /*(double) -> double*/;
  _x4557 = kk_model_dash_resources_new_fit_fun4561(_bv_3693, _ctx); /*(3691) -> 3692*/
  return kk_function_box(_x4557);
}


// lift anonymous function
struct kk_model_dash_resources_fit_fun4564__t {
  struct kk_function_s _base;
  kk_function_t _bv_3697;
};
static double kk_model_dash_resources_fit_fun4564(kk_function_t _fself, double _b_3698, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources_new_fit_fun4564(kk_function_t _bv_3697, kk_context_t* _ctx) {
  struct kk_model_dash_resources_fit_fun4564__t* _self = kk_function_alloc_as(struct kk_model_dash_resources_fit_fun4564__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_model_dash_resources_fit_fun4564, kk_context());
  _self->_bv_3697 = _bv_3697;
  return &_self->_base;
}

static double kk_model_dash_resources_fit_fun4564(kk_function_t _fself, double _b_3698, kk_context_t* _ctx) {
  struct kk_model_dash_resources_fit_fun4564__t* _self = kk_function_as(struct kk_model_dash_resources_fit_fun4564__t*, _fself);
  kk_function_t _bv_3697 = _self->_bv_3697; /* (3695) -> 3696 */
  kk_drop_match(_self, {kk_function_dup(_bv_3697);}, {}, _ctx)
  kk_box_t _x4565 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _bv_3697, (_bv_3697, kk_double_box(_b_3698, _ctx), _ctx)); /*3696*/
  return kk_double_unbox(_x4565, _ctx);
}


// lift anonymous function
struct kk_model_dash_resources_fit_fun4567__t {
  struct kk_function_s _base;
  kk_function_t x_3215;
};
static kk_box_t kk_model_dash_resources_fit_fun4567(kk_function_t _fself, kk_box_t _b_3716, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources_new_fit_fun4567(kk_function_t x_3215, kk_context_t* _ctx) {
  struct kk_model_dash_resources_fit_fun4567__t* _self = kk_function_alloc_as(struct kk_model_dash_resources_fit_fun4567__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_model_dash_resources_fit_fun4567, kk_context());
  _self->x_3215 = x_3215;
  return &_self->_base;
}



// lift anonymous function
struct kk_model_dash_resources_fit_fun4572__t {
  struct kk_function_s _base;
  kk_function_t x_3215;
};
static kk_box_t kk_model_dash_resources_fit_fun4572(kk_function_t _fself, kk_box_t _b_3703, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources_new_fit_fun4572(kk_function_t x_3215, kk_context_t* _ctx) {
  struct kk_model_dash_resources_fit_fun4572__t* _self = kk_function_alloc_as(struct kk_model_dash_resources_fit_fun4572__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_model_dash_resources_fit_fun4572, kk_context());
  _self->x_3215 = x_3215;
  return &_self->_base;
}

static kk_box_t kk_model_dash_resources_fit_fun4572(kk_function_t _fself, kk_box_t _b_3703, kk_context_t* _ctx) {
  struct kk_model_dash_resources_fit_fun4572__t* _self = kk_function_as(struct kk_model_dash_resources_fit_fun4572__t*, _fself);
  kk_function_t x_3215 = _self->x_3215; /* (double) -> double */
  kk_drop_match(_self, {kk_function_dup(x_3215);}, {}, _ctx)
  double _x4573;
  double _x4574 = kk_double_unbox(_b_3703, _ctx); /*double*/
  _x4573 = kk_function_call(double, (kk_function_t, double, kk_context_t*), x_3215, (x_3215, _x4574, _ctx)); /*double*/
  return kk_double_box(_x4573, _ctx);
}


// lift anonymous function
struct kk_model_dash_resources_fit_fun4585__t {
  struct kk_function_s _base;
  size_t i_3226;
};
static kk_box_t kk_model_dash_resources_fit_fun4585(kk_function_t _fself, kk_function_t _b_3711, kk_box_t _b_3712, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources_new_fit_fun4585(size_t i_3226, kk_context_t* _ctx) {
  struct kk_model_dash_resources_fit_fun4585__t* _self = kk_function_alloc_as(struct kk_model_dash_resources_fit_fun4585__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_model_dash_resources_fit_fun4585, kk_context());
  _self->i_3226 = i_3226;
  return &_self->_base;
}

static kk_box_t kk_model_dash_resources_fit_fun4585(kk_function_t _fself, kk_function_t _b_3711, kk_box_t _b_3712, kk_context_t* _ctx) {
  struct kk_model_dash_resources_fit_fun4585__t* _self = kk_function_as(struct kk_model_dash_resources_fit_fun4585__t*, _fself);
  size_t i_3226 = _self->i_3226; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_3226, _b_3711, _b_3712, _ctx);
}
static kk_box_t kk_model_dash_resources_fit_fun4567(kk_function_t _fself, kk_box_t _b_3716, kk_context_t* _ctx) {
  struct kk_model_dash_resources_fit_fun4567__t* _self = kk_function_as(struct kk_model_dash_resources_fit_fun4567__t*, _fself);
  kk_function_t x_3215 = _self->x_3215; /* (double) -> double */
  kk_drop_match(_self, {kk_function_dup(x_3215);}, {}, _ctx)
  kk_unit_t _x4568 = kk_Unit;
  kk_std_core_types__tuple2_ _match_4499 = kk_std_core_types__tuple2__unbox(_b_3716, _ctx); /*(double, double)*/;
  kk_box_t _box_x3699 = _match_4499.fst;
  kk_box_t _box_x3700 = _match_4499.snd;
  double x1 = kk_double_unbox(_box_x3699, NULL);
  double y = kk_double_unbox(_box_x3700, NULL);
  kk_std_core_types__tuple2__drop(_match_4499, _ctx);
  kk_effects_dash_and_dash_types__exp _x1;
  double _x10;
  kk_box_t _x4571 = kk_std_core_hnd__open_none1(kk_model_dash_resources_new_fit_fun4572(x_3215, _ctx), kk_double_box(x1, _ctx), _ctx); /*2*/
  _x10 = kk_double_unbox(_x4571, _ctx); /*double*/
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*std/core/hnd/evv<(<>)>*/;
  kk_effects_dash_and_dash_types__exp x4;
  kk_effects_dash_and_dash_types__exp _pat__30__13_3202;
  double _x4575;
  double _x4576;
  double _x4577;
  double x0_3204 = (y - _x10); /*double*/;
  _x4577 = (x0_3204 * x0_3204); /*double*/
  double _x4578;
  double _x4579 = kk_model_dash_resources_square(0x1p-2, _ctx); /*double*/
  _x4578 = (0x1p1 * _x4579); /*double*/
  _x4576 = (_x4577 / _x4578); /*double*/
  _x4575 = ((0x0p+0) - _x4576); /*double*/
  _pat__30__13_3202 = kk_effects_dash_and_dash_types__new_Exp(_x4575, _ctx); /*effects-and-types/exp*/
  kk_effects_dash_and_dash_types__exp _pat__30__28_3203;
  double x1_3205;
  double _x4580;
  double _x4581;
  double _x4582 = (0x1p1 * (0x1.921fb54442d18p1)); /*double*/
  _x4581 = sqrt(_x4582); /*double*/
  _x4580 = ((0x1p-2) * _x4581); /*double*/
  x1_3205 = log(_x4580); /*double*/
  _pat__30__28_3203 = kk_effects_dash_and_dash_types__new_Exp(x1_3205, _ctx); /*effects-and-types/exp*/
  double xe = _pat__30__13_3202.i;
  double ye = _pat__30__28_3203.i;
  double _x4583 = (xe - ye); /*double*/
  x4 = kk_effects_dash_and_dash_types__new_Exp(_x4583, _ctx); /*effects-and-types/exp*/
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  _x1 = x4; /*effects-and-types/exp*/
  size_t i_3226 = ((size_t)2); /*std/core/hnd/ev-index*/;
  kk_evv_t w0 = kk_evv_swap_create1(i_3226,kk_context()); /*std/core/hnd/evv<<effects-and-types/score,std/num/random/random,effects-and-types/sample>>*/;
  kk_unit_t y0 = kk_Unit;
  kk_effects_dash_and_dash_types_score(_x1, _ctx);
  kk_unit_t __w_l700_c9 = kk_Unit;
  kk_evv_set(w0,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x4584 = kk_std_core_hnd_yield_cont(kk_model_dash_resources_new_fit_fun4585(i_3226, _ctx), _ctx); /*3*/
    kk_unit_unbox(_x4584);
  }
  else {
    y0;
  }
  return kk_unit_box(_x4568);
}


// lift anonymous function
struct kk_model_dash_resources_fit_fun4587__t {
  struct kk_function_s _base;
  kk_function_t x_3215;
};
static kk_box_t kk_model_dash_resources_fit_fun4587(kk_function_t _fself, kk_box_t _b_3728, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources_new_fit_fun4587(kk_function_t x_3215, kk_context_t* _ctx) {
  struct kk_model_dash_resources_fit_fun4587__t* _self = kk_function_alloc_as(struct kk_model_dash_resources_fit_fun4587__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_model_dash_resources_fit_fun4587, kk_context());
  _self->x_3215 = x_3215;
  return &_self->_base;
}



// lift anonymous function
struct kk_model_dash_resources_fit_fun4590__t {
  struct kk_function_s _base;
  kk_function_t _bv_3731;
};
static kk_box_t kk_model_dash_resources_fit_fun4590(kk_function_t _fself, kk_box_t _b_3732, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources_new_fit_fun4590(kk_function_t _bv_3731, kk_context_t* _ctx) {
  struct kk_model_dash_resources_fit_fun4590__t* _self = kk_function_alloc_as(struct kk_model_dash_resources_fit_fun4590__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_model_dash_resources_fit_fun4590, kk_context());
  _self->_bv_3731 = _bv_3731;
  return &_self->_base;
}

static kk_box_t kk_model_dash_resources_fit_fun4590(kk_function_t _fself, kk_box_t _b_3732, kk_context_t* _ctx) {
  struct kk_model_dash_resources_fit_fun4590__t* _self = kk_function_as(struct kk_model_dash_resources_fit_fun4590__t*, _fself);
  kk_function_t _bv_3731 = _self->_bv_3731; /* (double) -> double */
  kk_drop_match(_self, {kk_function_dup(_bv_3731);}, {}, _ctx)
  double _x4591;
  double _x4592 = kk_double_unbox(_b_3732, _ctx); /*double*/
  _x4591 = kk_function_call(double, (kk_function_t, double, kk_context_t*), _bv_3731, (_bv_3731, _x4592, _ctx)); /*double*/
  return kk_double_box(_x4591, _ctx);
}
static kk_box_t kk_model_dash_resources_fit_fun4587(kk_function_t _fself, kk_box_t _b_3728, kk_context_t* _ctx) {
  struct kk_model_dash_resources_fit_fun4587__t* _self = kk_function_as(struct kk_model_dash_resources_fit_fun4587__t*, _fself);
  kk_function_t x_3215 = _self->x_3215; /* (double) -> double */
  kk_drop_match(_self, {kk_function_dup(x_3215);}, {}, _ctx)
  kk_function_t _x4588;
  kk_function_t _bv_3731;
  kk_std_core__list _x4589 = kk_std_core__list_unbox(_b_3728, _ctx); /*list<()>*/
  _bv_3731 = kk_model_dash_resources__mlift3169_fit(x_3215, _x4589, _ctx); /*(double) -> double*/
  _x4588 = kk_model_dash_resources_new_fit_fun4590(_bv_3731, _ctx); /*(3729) -> 3730*/
  return kk_function_box(_x4588);
}


// lift anonymous function
struct kk_model_dash_resources_fit_fun4593__t {
  struct kk_function_s _base;
  kk_function_t _bv_3735;
};
static double kk_model_dash_resources_fit_fun4593(kk_function_t _fself, double _b_3736, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources_new_fit_fun4593(kk_function_t _bv_3735, kk_context_t* _ctx) {
  struct kk_model_dash_resources_fit_fun4593__t* _self = kk_function_alloc_as(struct kk_model_dash_resources_fit_fun4593__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_model_dash_resources_fit_fun4593, kk_context());
  _self->_bv_3735 = _bv_3735;
  return &_self->_base;
}

static double kk_model_dash_resources_fit_fun4593(kk_function_t _fself, double _b_3736, kk_context_t* _ctx) {
  struct kk_model_dash_resources_fit_fun4593__t* _self = kk_function_as(struct kk_model_dash_resources_fit_fun4593__t*, _fself);
  kk_function_t _bv_3735 = _self->_bv_3735; /* (3733) -> 3734 */
  kk_drop_match(_self, {kk_function_dup(_bv_3735);}, {}, _ctx)
  kk_box_t _x4594 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _bv_3735, (_bv_3735, kk_double_box(_b_3736, _ctx), _ctx)); /*3734*/
  return kk_double_unbox(_x4594, _ctx);
}
static kk_function_t kk_model_dash_resources_fit_fun4554(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_model_dash_resources_fit_fun4554__t* _self = kk_function_as(struct kk_model_dash_resources_fit_fun4554__t*, _fself);
  kk_std_core__list dataset0 = _self->dataset0; /* effects-and-types/two_d_data */
  kk_function_t model = _self->model; /* effects-and-types/regression */
  kk_drop_match(_self, {kk_std_core__list_dup(dataset0);kk_function_dup(model);}, {}, _ctx)
  kk_function_t x_3215 = kk_function_call(kk_function_t, (kk_function_t, kk_context_t*), model, (model, _ctx)); /*(double) -> double*/;
  if (kk_yielding(kk_context())) {
    kk_function_drop(x_3215, _ctx);
    kk_function_t _bv_3697;
    kk_box_t _x4555 = kk_std_core_hnd_yield_extend(kk_model_dash_resources_new_fit_fun4556(dataset0, _ctx), _ctx); /*2*/
    _bv_3697 = kk_function_unbox(_x4555); /*(3695) -> 3696*/
    return kk_model_dash_resources_new_fit_fun4564(_bv_3697, _ctx);
  }
  kk_std_core__list x0_3219;
  kk_function_t _x4566;
  kk_function_dup(x_3215);
  _x4566 = kk_model_dash_resources_new_fit_fun4567(x_3215, _ctx); /*(1) -> 3 2*/
  x0_3219 = kk_std_core_map_5(dataset0, _x4566, _ctx); /*list<()>*/
  kk_std_core__list_drop(x0_3219, _ctx);
  if (kk_yielding(kk_context())) {
    kk_function_t _bv_3735;
    kk_box_t _x4586 = kk_std_core_hnd_yield_extend(kk_model_dash_resources_new_fit_fun4587(x_3215, _ctx), _ctx); /*2*/
    _bv_3735 = kk_function_unbox(_x4586); /*(3733) -> 3734*/
    return kk_model_dash_resources_new_fit_fun4593(_bv_3735, _ctx);
  }
  return x_3215;
}

kk_function_t kk_model_dash_resources_fit(kk_function_t model, kk_std_core__list dataset0, kk_context_t* _ctx) { /* (model : effects-and-types/regression, dataset : effects-and-types/two_d_data) -> effects-and-types/regression */ 
  return kk_model_dash_resources_new_fit_fun4554(dataset0, model, _ctx);
}
 
// monadic lift

double kk_model_dash_resources__mlift3171_fit__1d__gaussian(double f, kk_std_core__list wild__, kk_context_t* _ctx) { /* (f : double, wild_ : list<()>) -> <effects-and-types/score,std/num/random/random,effects-and-types/sample> double */ 
  kk_std_core__list_drop(wild__, _ctx);
  return f;
}
 
// monadic lift


// lift anonymous function
struct kk_model_dash_resources__mlift3172_fit__1d__gaussian_fun4595__t {
  struct kk_function_s _base;
  double f;
};
static kk_box_t kk_model_dash_resources__mlift3172_fit__1d__gaussian_fun4595(kk_function_t _fself, kk_box_t _b_3751, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources__new_mlift3172_fit__1d__gaussian_fun4595(double f, kk_context_t* _ctx) {
  struct kk_model_dash_resources__mlift3172_fit__1d__gaussian_fun4595__t* _self = kk_function_alloc_as(struct kk_model_dash_resources__mlift3172_fit__1d__gaussian_fun4595__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_model_dash_resources__mlift3172_fit__1d__gaussian_fun4595, kk_context());
  _self->f = f;
  return &_self->_base;
}



// lift anonymous function
struct kk_model_dash_resources__mlift3172_fit__1d__gaussian_fun4608__t {
  struct kk_function_s _base;
  size_t i_3236;
};
static kk_box_t kk_model_dash_resources__mlift3172_fit__1d__gaussian_fun4608(kk_function_t _fself, kk_function_t _b_3746, kk_box_t _b_3747, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources__new_mlift3172_fit__1d__gaussian_fun4608(size_t i_3236, kk_context_t* _ctx) {
  struct kk_model_dash_resources__mlift3172_fit__1d__gaussian_fun4608__t* _self = kk_function_alloc_as(struct kk_model_dash_resources__mlift3172_fit__1d__gaussian_fun4608__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_model_dash_resources__mlift3172_fit__1d__gaussian_fun4608, kk_context());
  _self->i_3236 = i_3236;
  return &_self->_base;
}

static kk_box_t kk_model_dash_resources__mlift3172_fit__1d__gaussian_fun4608(kk_function_t _fself, kk_function_t _b_3746, kk_box_t _b_3747, kk_context_t* _ctx) {
  struct kk_model_dash_resources__mlift3172_fit__1d__gaussian_fun4608__t* _self = kk_function_as(struct kk_model_dash_resources__mlift3172_fit__1d__gaussian_fun4608__t*, _fself);
  size_t i_3236 = _self->i_3236; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_3236, _b_3746, _b_3747, _ctx);
}
static kk_box_t kk_model_dash_resources__mlift3172_fit__1d__gaussian_fun4595(kk_function_t _fself, kk_box_t _b_3751, kk_context_t* _ctx) {
  struct kk_model_dash_resources__mlift3172_fit__1d__gaussian_fun4595__t* _self = kk_function_as(struct kk_model_dash_resources__mlift3172_fit__1d__gaussian_fun4595__t*, _fself);
  double f = _self->f; /* double */
  kk_drop_match(_self, {;}, {}, _ctx)
  kk_unit_t _x4596 = kk_Unit;
  kk_effects_dash_and_dash_types__exp _x1;
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*std/core/hnd/evv<(<>)>*/;
  kk_effects_dash_and_dash_types__exp x4;
  kk_effects_dash_and_dash_types__exp _pat__30__13_3202;
  double _x4597;
  double _x4598;
  double _x4599;
  double x0_3204;
  double _x4600 = kk_double_unbox(_b_3751, _ctx); /*double*/
  x0_3204 = (_x4600 - f); /*double*/
  _x4599 = (x0_3204 * x0_3204); /*double*/
  double _x4601;
  double _x4602 = kk_model_dash_resources_square(0x1p0, _ctx); /*double*/
  _x4601 = (0x1p1 * _x4602); /*double*/
  _x4598 = (_x4599 / _x4601); /*double*/
  _x4597 = ((0x0p+0) - _x4598); /*double*/
  _pat__30__13_3202 = kk_effects_dash_and_dash_types__new_Exp(_x4597, _ctx); /*effects-and-types/exp*/
  kk_effects_dash_and_dash_types__exp _pat__30__28_3203;
  double x1_3205;
  double _x4603;
  double _x4604;
  double _x4605 = (0x1p1 * (0x1.921fb54442d18p1)); /*double*/
  _x4604 = sqrt(_x4605); /*double*/
  _x4603 = (0x1p0 * _x4604); /*double*/
  x1_3205 = log(_x4603); /*double*/
  _pat__30__28_3203 = kk_effects_dash_and_dash_types__new_Exp(x1_3205, _ctx); /*effects-and-types/exp*/
  double xe = _pat__30__13_3202.i;
  double ye = _pat__30__28_3203.i;
  double _x4606 = (xe - ye); /*double*/
  x4 = kk_effects_dash_and_dash_types__new_Exp(_x4606, _ctx); /*effects-and-types/exp*/
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  _x1 = x4; /*effects-and-types/exp*/
  size_t i_3236 = ((size_t)2); /*std/core/hnd/ev-index*/;
  kk_evv_t w0 = kk_evv_swap_create1(i_3236,kk_context()); /*std/core/hnd/evv<<effects-and-types/score,std/num/random/random,effects-and-types/sample>>*/;
  kk_unit_t y = kk_Unit;
  kk_effects_dash_and_dash_types_score(_x1, _ctx);
  kk_unit_t __w_l700_c9 = kk_Unit;
  kk_evv_set(w0,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x4607 = kk_std_core_hnd_yield_cont(kk_model_dash_resources__new_mlift3172_fit__1d__gaussian_fun4608(i_3236, _ctx), _ctx); /*3*/
    kk_unit_unbox(_x4607);
  }
  else {
    y;
  }
  return kk_unit_box(_x4596);
}


// lift anonymous function
struct kk_model_dash_resources__mlift3172_fit__1d__gaussian_fun4610__t {
  struct kk_function_s _base;
  double f;
};
static kk_box_t kk_model_dash_resources__mlift3172_fit__1d__gaussian_fun4610(kk_function_t _fself, kk_box_t _b_3763, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources__new_mlift3172_fit__1d__gaussian_fun4610(double f, kk_context_t* _ctx) {
  struct kk_model_dash_resources__mlift3172_fit__1d__gaussian_fun4610__t* _self = kk_function_alloc_as(struct kk_model_dash_resources__mlift3172_fit__1d__gaussian_fun4610__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_model_dash_resources__mlift3172_fit__1d__gaussian_fun4610, kk_context());
  _self->f = f;
  return &_self->_base;
}

static kk_box_t kk_model_dash_resources__mlift3172_fit__1d__gaussian_fun4610(kk_function_t _fself, kk_box_t _b_3763, kk_context_t* _ctx) {
  struct kk_model_dash_resources__mlift3172_fit__1d__gaussian_fun4610__t* _self = kk_function_as(struct kk_model_dash_resources__mlift3172_fit__1d__gaussian_fun4610__t*, _fself);
  double f = _self->f; /* double */
  kk_drop_match(_self, {;}, {}, _ctx)
  double _x4611;
  kk_std_core__list _x4612 = kk_std_core__list_unbox(_b_3763, _ctx); /*list<()>*/
  _x4611 = kk_model_dash_resources__mlift3171_fit__1d__gaussian(f, _x4612, _ctx); /*double*/
  return kk_double_box(_x4611, _ctx);
}

double kk_model_dash_resources__mlift3172_fit__1d__gaussian(kk_std_core__list dataset0, double f, kk_context_t* _ctx) { /* (dataset : effects-and-types/data_1d, f : double) -> <effects-and-types/sample,effects-and-types/score,std/num/random/random> double */ 
  kk_std_core__list x_3230 = kk_std_core_map_5(dataset0, kk_model_dash_resources__new_mlift3172_fit__1d__gaussian_fun4595(f, _ctx), _ctx); /*list<()>*/;
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_3230, _ctx);
    kk_box_t _x4609 = kk_std_core_hnd_yield_extend(kk_model_dash_resources__new_mlift3172_fit__1d__gaussian_fun4610(f, _ctx), _ctx); /*2*/
    return kk_double_unbox(_x4609, _ctx);
  }
  return kk_model_dash_resources__mlift3171_fit__1d__gaussian(f, x_3230, _ctx);
}


// lift anonymous function
struct kk_model_dash_resources_fit__1d__gaussian_fun4613__t {
  struct kk_function_s _base;
  kk_std_core__list dataset0;
  kk_function_t model;
};
static double kk_model_dash_resources_fit__1d__gaussian_fun4613(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources_new_fit__1d__gaussian_fun4613(kk_std_core__list dataset0, kk_function_t model, kk_context_t* _ctx) {
  struct kk_model_dash_resources_fit__1d__gaussian_fun4613__t* _self = kk_function_alloc_as(struct kk_model_dash_resources_fit__1d__gaussian_fun4613__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_model_dash_resources_fit__1d__gaussian_fun4613, kk_context());
  _self->dataset0 = dataset0;
  _self->model = model;
  return &_self->_base;
}



// lift anonymous function
struct kk_model_dash_resources_fit__1d__gaussian_fun4615__t {
  struct kk_function_s _base;
  kk_std_core__list dataset0;
};
static kk_box_t kk_model_dash_resources_fit__1d__gaussian_fun4615(kk_function_t _fself, kk_box_t _b_3767, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources_new_fit__1d__gaussian_fun4615(kk_std_core__list dataset0, kk_context_t* _ctx) {
  struct kk_model_dash_resources_fit__1d__gaussian_fun4615__t* _self = kk_function_alloc_as(struct kk_model_dash_resources_fit__1d__gaussian_fun4615__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_model_dash_resources_fit__1d__gaussian_fun4615, kk_context());
  _self->dataset0 = dataset0;
  return &_self->_base;
}

static kk_box_t kk_model_dash_resources_fit__1d__gaussian_fun4615(kk_function_t _fself, kk_box_t _b_3767, kk_context_t* _ctx) {
  struct kk_model_dash_resources_fit__1d__gaussian_fun4615__t* _self = kk_function_as(struct kk_model_dash_resources_fit__1d__gaussian_fun4615__t*, _fself);
  kk_std_core__list dataset0 = _self->dataset0; /* effects-and-types/data_1d */
  kk_drop_match(_self, {kk_std_core__list_dup(dataset0);}, {}, _ctx)
  double _x4616;
  double _x4617 = kk_double_unbox(_b_3767, _ctx); /*double*/
  _x4616 = kk_model_dash_resources__mlift3172_fit__1d__gaussian(dataset0, _x4617, _ctx); /*double*/
  return kk_double_box(_x4616, _ctx);
}


// lift anonymous function
struct kk_model_dash_resources_fit__1d__gaussian_fun4618__t {
  struct kk_function_s _base;
  double x_3239;
};
static kk_box_t kk_model_dash_resources_fit__1d__gaussian_fun4618(kk_function_t _fself, kk_box_t _b_3778, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources_new_fit__1d__gaussian_fun4618(double x_3239, kk_context_t* _ctx) {
  struct kk_model_dash_resources_fit__1d__gaussian_fun4618__t* _self = kk_function_alloc_as(struct kk_model_dash_resources_fit__1d__gaussian_fun4618__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_model_dash_resources_fit__1d__gaussian_fun4618, kk_context());
  _self->x_3239 = x_3239;
  return &_self->_base;
}



// lift anonymous function
struct kk_model_dash_resources_fit__1d__gaussian_fun4631__t {
  struct kk_function_s _base;
  size_t i_3250;
};
static kk_box_t kk_model_dash_resources_fit__1d__gaussian_fun4631(kk_function_t _fself, kk_function_t _b_3773, kk_box_t _b_3774, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources_new_fit__1d__gaussian_fun4631(size_t i_3250, kk_context_t* _ctx) {
  struct kk_model_dash_resources_fit__1d__gaussian_fun4631__t* _self = kk_function_alloc_as(struct kk_model_dash_resources_fit__1d__gaussian_fun4631__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_model_dash_resources_fit__1d__gaussian_fun4631, kk_context());
  _self->i_3250 = i_3250;
  return &_self->_base;
}

static kk_box_t kk_model_dash_resources_fit__1d__gaussian_fun4631(kk_function_t _fself, kk_function_t _b_3773, kk_box_t _b_3774, kk_context_t* _ctx) {
  struct kk_model_dash_resources_fit__1d__gaussian_fun4631__t* _self = kk_function_as(struct kk_model_dash_resources_fit__1d__gaussian_fun4631__t*, _fself);
  size_t i_3250 = _self->i_3250; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_3250, _b_3773, _b_3774, _ctx);
}
static kk_box_t kk_model_dash_resources_fit__1d__gaussian_fun4618(kk_function_t _fself, kk_box_t _b_3778, kk_context_t* _ctx) {
  struct kk_model_dash_resources_fit__1d__gaussian_fun4618__t* _self = kk_function_as(struct kk_model_dash_resources_fit__1d__gaussian_fun4618__t*, _fself);
  double x_3239 = _self->x_3239; /* double */
  kk_drop_match(_self, {;}, {}, _ctx)
  kk_unit_t _x4619 = kk_Unit;
  kk_effects_dash_and_dash_types__exp _x1;
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*std/core/hnd/evv<(<>)>*/;
  kk_effects_dash_and_dash_types__exp x4;
  kk_effects_dash_and_dash_types__exp _pat__30__13_3202;
  double _x4620;
  double _x4621;
  double _x4622;
  double x0_3204;
  double _x4623 = kk_double_unbox(_b_3778, _ctx); /*double*/
  x0_3204 = (_x4623 - x_3239); /*double*/
  _x4622 = (x0_3204 * x0_3204); /*double*/
  double _x4624;
  double _x4625 = kk_model_dash_resources_square(0x1p0, _ctx); /*double*/
  _x4624 = (0x1p1 * _x4625); /*double*/
  _x4621 = (_x4622 / _x4624); /*double*/
  _x4620 = ((0x0p+0) - _x4621); /*double*/
  _pat__30__13_3202 = kk_effects_dash_and_dash_types__new_Exp(_x4620, _ctx); /*effects-and-types/exp*/
  kk_effects_dash_and_dash_types__exp _pat__30__28_3203;
  double x1_3205;
  double _x4626;
  double _x4627;
  double _x4628 = (0x1p1 * (0x1.921fb54442d18p1)); /*double*/
  _x4627 = sqrt(_x4628); /*double*/
  _x4626 = (0x1p0 * _x4627); /*double*/
  x1_3205 = log(_x4626); /*double*/
  _pat__30__28_3203 = kk_effects_dash_and_dash_types__new_Exp(x1_3205, _ctx); /*effects-and-types/exp*/
  double xe = _pat__30__13_3202.i;
  double ye = _pat__30__28_3203.i;
  double _x4629 = (xe - ye); /*double*/
  x4 = kk_effects_dash_and_dash_types__new_Exp(_x4629, _ctx); /*effects-and-types/exp*/
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  _x1 = x4; /*effects-and-types/exp*/
  size_t i_3250 = ((size_t)2); /*std/core/hnd/ev-index*/;
  kk_evv_t w0 = kk_evv_swap_create1(i_3250,kk_context()); /*std/core/hnd/evv<<effects-and-types/score,std/num/random/random,effects-and-types/sample>>*/;
  kk_unit_t y = kk_Unit;
  kk_effects_dash_and_dash_types_score(_x1, _ctx);
  kk_unit_t __w_l700_c9 = kk_Unit;
  kk_evv_set(w0,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x4630 = kk_std_core_hnd_yield_cont(kk_model_dash_resources_new_fit__1d__gaussian_fun4631(i_3250, _ctx), _ctx); /*3*/
    kk_unit_unbox(_x4630);
  }
  else {
    y;
  }
  return kk_unit_box(_x4619);
}


// lift anonymous function
struct kk_model_dash_resources_fit__1d__gaussian_fun4633__t {
  struct kk_function_s _base;
  double x_3239;
};
static kk_box_t kk_model_dash_resources_fit__1d__gaussian_fun4633(kk_function_t _fself, kk_box_t _b_3790, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources_new_fit__1d__gaussian_fun4633(double x_3239, kk_context_t* _ctx) {
  struct kk_model_dash_resources_fit__1d__gaussian_fun4633__t* _self = kk_function_alloc_as(struct kk_model_dash_resources_fit__1d__gaussian_fun4633__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_model_dash_resources_fit__1d__gaussian_fun4633, kk_context());
  _self->x_3239 = x_3239;
  return &_self->_base;
}

static kk_box_t kk_model_dash_resources_fit__1d__gaussian_fun4633(kk_function_t _fself, kk_box_t _b_3790, kk_context_t* _ctx) {
  struct kk_model_dash_resources_fit__1d__gaussian_fun4633__t* _self = kk_function_as(struct kk_model_dash_resources_fit__1d__gaussian_fun4633__t*, _fself);
  double x_3239 = _self->x_3239; /* double */
  kk_drop_match(_self, {;}, {}, _ctx)
  double _x4634;
  kk_std_core__list _x4635 = kk_std_core__list_unbox(_b_3790, _ctx); /*list<()>*/
  _x4634 = kk_model_dash_resources__mlift3171_fit__1d__gaussian(x_3239, _x4635, _ctx); /*double*/
  return kk_double_box(_x4634, _ctx);
}
static double kk_model_dash_resources_fit__1d__gaussian_fun4613(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_model_dash_resources_fit__1d__gaussian_fun4613__t* _self = kk_function_as(struct kk_model_dash_resources_fit__1d__gaussian_fun4613__t*, _fself);
  kk_std_core__list dataset0 = _self->dataset0; /* effects-and-types/data_1d */
  kk_function_t model = _self->model; /* effects-and-types/nmodel<double> */
  kk_drop_match(_self, {kk_std_core__list_dup(dataset0);kk_function_dup(model);}, {}, _ctx)
  double x_3239 = kk_function_call(double, (kk_function_t, kk_context_t*), model, (model, _ctx)); /*double*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x4614 = kk_std_core_hnd_yield_extend(kk_model_dash_resources_new_fit__1d__gaussian_fun4615(dataset0, _ctx), _ctx); /*2*/
    return kk_double_unbox(_x4614, _ctx);
  }
  kk_std_core__list x0_3243 = kk_std_core_map_5(dataset0, kk_model_dash_resources_new_fit__1d__gaussian_fun4618(x_3239, _ctx), _ctx); /*list<()>*/;
  kk_std_core__list_drop(x0_3243, _ctx);
  if (kk_yielding(kk_context())) {
    kk_box_t _x4632 = kk_std_core_hnd_yield_extend(kk_model_dash_resources_new_fit__1d__gaussian_fun4633(x_3239, _ctx), _ctx); /*2*/
    return kk_double_unbox(_x4632, _ctx);
  }
  return x_3239;
}

kk_function_t kk_model_dash_resources_fit__1d__gaussian(kk_function_t model, kk_std_core__list dataset0, kk_context_t* _ctx) { /* (model : effects-and-types/nmodel<double>, dataset : effects-and-types/data_1d) -> effects-and-types/nmodel<double> */ 
  return kk_model_dash_resources_new_fit__1d__gaussian_fun4613(dataset0, model, _ctx);
}


// lift anonymous function
struct kk_model_dash_resources_gamma_fun4644__t {
  struct kk_function_s _base;
  kk_ref_t a;
  kk_std_core__list p;
  double hh;
};
static kk_unit_t kk_model_dash_resources_gamma_fun4644(kk_function_t _fself, kk_integer_t i, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources_new_gamma_fun4644(kk_ref_t a, kk_std_core__list p, double hh, kk_context_t* _ctx) {
  struct kk_model_dash_resources_gamma_fun4644__t* _self = kk_function_alloc_as(struct kk_model_dash_resources_gamma_fun4644__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_model_dash_resources_gamma_fun4644, kk_context());
  _self->a = a;
  _self->p = p;
  _self->hh = hh;
  return &_self->_base;
}

static kk_unit_t kk_model_dash_resources_gamma_fun4644(kk_function_t _fself, kk_integer_t i, kk_context_t* _ctx) {
  struct kk_model_dash_resources_gamma_fun4644__t* _self = kk_function_as(struct kk_model_dash_resources_gamma_fun4644__t*, _fself);
  kk_ref_t a = _self->a; /* ref<981,double> */
  kk_std_core__list p = _self->p; /* list<double> */
  double hh = _self->hh; /* double */
  kk_drop_match(_self, {kk_ref_dup(a);kk_std_core__list_dup(p);;}, {}, _ctx)
  double new__p;
  kk_std_core_types__maybe _match_4491;
  kk_integer_t _x4645 = kk_integer_dup(i); /*int*/
  _match_4491 = kk_std_core__lp__lb__rb__2_rp_(p, _x4645, _ctx); /*maybe<1>*/
  if (kk_std_core_types__is_Nothing(_match_4491)) {
    new__p = 0x0p+0; /*double*/
  }
  else {
    kk_box_t _box_x3833 = _match_4491._cons.Just.value;
    double aa = kk_double_unbox(_box_x3833, NULL);
    kk_std_core_types__maybe_drop(_match_4491, _ctx);
    new__p = aa; /*double*/
  }
  double _b_3838_3836;
  double _x4647;
  kk_box_t _x4648;
  kk_ref_t _x4649 = kk_ref_dup(a); /*ref<981,double>*/
  _x4648 = kk_ref_get(_x4649,kk_context()); /*1*/
  _x4647 = kk_double_unbox(_x4648, _ctx); /*double*/
  double _x4650;
  double _x4651;
  double _x4652 = kk_integer_as_double(i,kk_context()); /*double*/
  _x4651 = (hh + _x4652); /*double*/
  _x4650 = (new__p / _x4651); /*double*/
  _b_3838_3836 = (_x4647 + _x4650); /*double*/
  return kk_ref_set(a,(kk_double_box(_b_3838_3836, _ctx)),kk_context());
}

double kk_model_dash_resources_gamma(double x, kk_context_t* _ctx) { /* forall<h> (double) -> <st<h>,div> double */ 
  kk_std_core__list p;
  kk_std_core__list _b_3814_3812;
  kk_std_core__list _b_3816_3810;
  kk_std_core__list _b_3818_3808;
  kk_std_core__list _b_3820_3806;
  kk_std_core__list _b_3822_3804;
  kk_std_core__list _b_3824_3802;
  kk_std_core__list _b_3826_3800;
  kk_std_core__list _b_3828_3798 = kk_std_core__new_Cons(kk_reuse_null, kk_double_box(0x1.435508f3faeefp-23, _ctx), kk_std_core__new_Nil(_ctx), _ctx); /*list<double>*/;
  _b_3826_3800 = kk_std_core__new_Cons(kk_reuse_null, kk_double_box(0x1.4f0514e4e324fp-17, _ctx), _b_3828_3798, _ctx); /*list<double>*/
  _b_3824_3802 = kk_std_core__new_Cons(kk_reuse_null, kk_double_box(-0x1.1bcb2992b2855p-3, _ctx), _b_3826_3800, _ctx); /*list<double>*/
  _b_3822_3804 = kk_std_core__new_Cons(kk_reuse_null, kk_double_box(0x1.903c27f8b9c81p3, _ctx), _b_3824_3802, _ctx); /*list<double>*/
  _b_3820_3806 = kk_std_core__new_Cons(kk_reuse_null, kk_double_box(-0x1.613ae51a32f5dp7, _ctx), _b_3822_3804, _ctx); /*list<double>*/
  _b_3818_3808 = kk_std_core__new_Cons(kk_reuse_null, kk_double_box(0x1.81a9661d3b4d8p9, _ctx), _b_3820_3806, _ctx); /*list<double>*/
  _b_3816_3810 = kk_std_core__new_Cons(kk_reuse_null, kk_double_box(-0x1.3ac8e8ed4171bp10, _ctx), _b_3818_3808, _ctx); /*list<double>*/
  _b_3814_3812 = kk_std_core__new_Cons(kk_reuse_null, kk_double_box(0x1.52429b6c30b05p9, _ctx), _b_3816_3810, _ctx); /*list<double>*/
  p = kk_std_core__new_Cons(kk_reuse_null, kk_double_box(0x1.ffffffffff95p-1, _ctx), _b_3814_3812, _ctx); /*list<double>*/
  bool _match_4490 = (x < (0x1p-1)); /*bool*/;
  if (_match_4490) {
    kk_std_core__list_drop(p, _ctx);
    double _x4636;
    double _x4637;
    double _x4638 = ((0x1.921fb54442d18p1) * x); /*double*/
    _x4637 = sin(_x4638); /*double*/
    double _x4639;
    double _x4640 = (0x1p0 - x); /*double*/
    _x4639 = kk_model_dash_resources_gamma(_x4640, _ctx); /*double*/
    _x4636 = (_x4637 * _x4639); /*double*/
    return ((0x1.921fb54442d18p1) / _x4636);
  }
  double hh = (x - 0x1p0); /*double*/;
  kk_ref_t a = kk_ref_alloc((kk_double_box(0x1.ffffffffff95p-1, _ctx)),kk_context()); /*ref<981,double>*/;
  double t;
  double _x4641 = (hh + (0x1.cp2)); /*double*/
  t = (_x4641 + (0x1p-1)); /*double*/
  kk_unit_t __0 = kk_Unit;
  kk_integer_t end_3255;
  kk_std_core__list _x4642 = kk_std_core__list_dup(p); /*list<double>*/
  end_3255 = kk_std_core_length_1(_x4642, _ctx); /*int*/
  kk_function_t _x4643;
  kk_ref_dup(a);
  _x4643 = kk_model_dash_resources_new_gamma_fun4644(a, p, hh, _ctx); /*(i : int) -> <read<981>,write<981>,alloc<981>,div> ()*/
  kk_std_core__lift21056_for(_x4643, end_3255, kk_integer_from_small(1), _ctx);
  double _x4653;
  double _x4654;
  double _x4655;
  double _x4656 = (0x1p1 * (0x1.921fb54442d18p1)); /*double*/
  _x4655 = sqrt(_x4656); /*double*/
  double _x4657;
  double _x4658 = (hh + (0x1p-1)); /*double*/
  _x4657 = pow(t,_x4658); /*double*/
  _x4654 = (_x4655 * _x4657); /*double*/
  double _x4659;
  double _x4660 = ((0x0p+0) - t); /*double*/
  _x4659 = exp(_x4660); /*double*/
  _x4653 = (_x4654 * _x4659); /*double*/
  double _x4661;
  kk_box_t _x4662 = kk_ref_get(a,kk_context()); /*1*/
  _x4661 = kk_double_unbox(_x4662, _ctx); /*double*/
  return (_x4653 * _x4661);
}
 
// monadic lift


// lift anonymous function
struct kk_model_dash_resources__mlift3173_standard_normal_fun4664__t {
  struct kk_function_s _base;
};
static kk_box_t kk_model_dash_resources__mlift3173_standard_normal_fun4664(kk_function_t _fself, kk_box_t _b_3845, kk_box_t _b_3846, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources__new_mlift3173_standard_normal_fun4664(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_model_dash_resources__mlift3173_standard_normal_fun4664, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_model_dash_resources__mlift3173_standard_normal_fun4664(kk_function_t _fself, kk_box_t _b_3845, kk_box_t _b_3846, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x4665;
  double _x4666 = kk_double_unbox(_b_3845, _ctx); /*double*/
  double _x4667 = kk_double_unbox(_b_3846, _ctx); /*double*/
  _x4665 = kk_model_dash_resources_box_muller(_x4666, _x4667, _ctx); /*double*/
  return kk_double_box(_x4665, _ctx);
}

double kk_model_dash_resources__mlift3173_standard_normal(double _y_8, double _y_9, kk_context_t* _ctx) { /* (double, double) -> effects-and-types/sample double */ 
  kk_box_t _x4663 = kk_std_core_hnd__open_none2(kk_model_dash_resources__new_mlift3173_standard_normal_fun4664(_ctx), kk_double_box(_y_8, _ctx), kk_double_box(_y_9, _ctx), _ctx); /*3*/
  return kk_double_unbox(_x4663, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_model_dash_resources__mlift3174_standard_normal_fun4669__t {
  struct kk_function_s _base;
  double _y_8;
};
static kk_box_t kk_model_dash_resources__mlift3174_standard_normal_fun4669(kk_function_t _fself, kk_box_t _b_3851, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources__new_mlift3174_standard_normal_fun4669(double _y_8, kk_context_t* _ctx) {
  struct kk_model_dash_resources__mlift3174_standard_normal_fun4669__t* _self = kk_function_alloc_as(struct kk_model_dash_resources__mlift3174_standard_normal_fun4669__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_model_dash_resources__mlift3174_standard_normal_fun4669, kk_context());
  _self->_y_8 = _y_8;
  return &_self->_base;
}

static kk_box_t kk_model_dash_resources__mlift3174_standard_normal_fun4669(kk_function_t _fself, kk_box_t _b_3851, kk_context_t* _ctx) {
  struct kk_model_dash_resources__mlift3174_standard_normal_fun4669__t* _self = kk_function_as(struct kk_model_dash_resources__mlift3174_standard_normal_fun4669__t*, _fself);
  double _y_8 = _self->_y_8; /* double */
  kk_drop_match(_self, {;}, {}, _ctx)
  double _x4670;
  double _x4671 = kk_double_unbox(_b_3851, _ctx); /*double*/
  _x4670 = kk_model_dash_resources__mlift3173_standard_normal(_y_8, _x4671, _ctx); /*double*/
  return kk_double_box(_x4670, _ctx);
}

double kk_model_dash_resources__mlift3174_standard_normal(double _y_8, kk_context_t* _ctx) { /* (double) -> effects-and-types/sample double */ 
  double x_3257 = kk_effects_dash_and_dash_types_sample(_ctx); /*double*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x4668 = kk_std_core_hnd_yield_extend(kk_model_dash_resources__new_mlift3174_standard_normal_fun4669(_y_8, _ctx), _ctx); /*2*/
    return kk_double_unbox(_x4668, _ctx);
  }
  return kk_model_dash_resources__mlift3173_standard_normal(_y_8, x_3257, _ctx);
}


// lift anonymous function
struct kk_model_dash_resources_standard_normal_fun4673__t {
  struct kk_function_s _base;
};
static kk_box_t kk_model_dash_resources_standard_normal_fun4673(kk_function_t _fself, kk_box_t _b_3855, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources_new_standard_normal_fun4673(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_model_dash_resources_standard_normal_fun4673, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_model_dash_resources_standard_normal_fun4673(kk_function_t _fself, kk_box_t _b_3855, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x4674;
  double _x4675 = kk_double_unbox(_b_3855, _ctx); /*double*/
  _x4674 = kk_model_dash_resources__mlift3174_standard_normal(_x4675, _ctx); /*double*/
  return kk_double_box(_x4674, _ctx);
}


// lift anonymous function
struct kk_model_dash_resources_standard_normal_fun4677__t {
  struct kk_function_s _base;
  double x_3259;
};
static kk_box_t kk_model_dash_resources_standard_normal_fun4677(kk_function_t _fself, kk_box_t _b_3857, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources_new_standard_normal_fun4677(double x_3259, kk_context_t* _ctx) {
  struct kk_model_dash_resources_standard_normal_fun4677__t* _self = kk_function_alloc_as(struct kk_model_dash_resources_standard_normal_fun4677__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_model_dash_resources_standard_normal_fun4677, kk_context());
  _self->x_3259 = x_3259;
  return &_self->_base;
}

static kk_box_t kk_model_dash_resources_standard_normal_fun4677(kk_function_t _fself, kk_box_t _b_3857, kk_context_t* _ctx) {
  struct kk_model_dash_resources_standard_normal_fun4677__t* _self = kk_function_as(struct kk_model_dash_resources_standard_normal_fun4677__t*, _fself);
  double x_3259 = _self->x_3259; /* double */
  kk_drop_match(_self, {;}, {}, _ctx)
  double _x4678;
  double _x4679 = kk_double_unbox(_b_3857, _ctx); /*double*/
  _x4678 = kk_model_dash_resources__mlift3173_standard_normal(x_3259, _x4679, _ctx); /*double*/
  return kk_double_box(_x4678, _ctx);
}


// lift anonymous function
struct kk_model_dash_resources_standard_normal_fun4680__t {
  struct kk_function_s _base;
};
static kk_box_t kk_model_dash_resources_standard_normal_fun4680(kk_function_t _fself, kk_box_t _b_3861, kk_box_t _b_3862, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources_new_standard_normal_fun4680(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_model_dash_resources_standard_normal_fun4680, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_model_dash_resources_standard_normal_fun4680(kk_function_t _fself, kk_box_t _b_3861, kk_box_t _b_3862, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x4681;
  double _x4682 = kk_double_unbox(_b_3861, _ctx); /*double*/
  double _x4683 = kk_double_unbox(_b_3862, _ctx); /*double*/
  _x4681 = kk_model_dash_resources_box_muller(_x4682, _x4683, _ctx); /*double*/
  return kk_double_box(_x4681, _ctx);
}

double kk_model_dash_resources_standard_normal(kk_context_t* _ctx) { /* () -> effects-and-types/sample double */ 
  double x_3259 = kk_effects_dash_and_dash_types_sample(_ctx); /*double*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x4672 = kk_std_core_hnd_yield_extend(kk_model_dash_resources_new_standard_normal_fun4673(_ctx), _ctx); /*2*/
    return kk_double_unbox(_x4672, _ctx);
  }
  double x0_3263 = kk_effects_dash_and_dash_types_sample(_ctx); /*double*/;
  kk_box_t _x4676;
  if (kk_yielding(kk_context())) {
    _x4676 = kk_std_core_hnd_yield_extend(kk_model_dash_resources_new_standard_normal_fun4677(x_3259, _ctx), _ctx); /*2*/
  }
  else {
    _x4676 = kk_std_core_hnd__open_none2(kk_model_dash_resources_new_standard_normal_fun4680(_ctx), kk_double_box(x_3259, _ctx), kk_double_box(x0_3263, _ctx), _ctx); /*2*/
  }
  return kk_double_unbox(_x4676, _ctx);
}
 
// monadic lift

double kk_model_dash_resources__mlift3175_normal(double mean, double sdv, double _y_10, kk_context_t* _ctx) { /* (mean : double, sdv : double, double) -> effects-and-types/sample double */ 
  double _x4684 = (_y_10 * sdv); /*double*/
  return (mean + _x4684);
}


// lift anonymous function
struct kk_model_dash_resources_normal_fun4686__t {
  struct kk_function_s _base;
  double mean;
  double sdv;
};
static kk_box_t kk_model_dash_resources_normal_fun4686(kk_function_t _fself, kk_box_t _b_3870, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources_new_normal_fun4686(double mean, double sdv, kk_context_t* _ctx) {
  struct kk_model_dash_resources_normal_fun4686__t* _self = kk_function_alloc_as(struct kk_model_dash_resources_normal_fun4686__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_model_dash_resources_normal_fun4686, kk_context());
  _self->mean = mean;
  _self->sdv = sdv;
  return &_self->_base;
}

static kk_box_t kk_model_dash_resources_normal_fun4686(kk_function_t _fself, kk_box_t _b_3870, kk_context_t* _ctx) {
  struct kk_model_dash_resources_normal_fun4686__t* _self = kk_function_as(struct kk_model_dash_resources_normal_fun4686__t*, _fself);
  double mean = _self->mean; /* double */
  double sdv = _self->sdv; /* double */
  kk_drop_match(_self, {;;}, {}, _ctx)
  double _x4687;
  double _x4688 = kk_double_unbox(_b_3870, _ctx); /*double*/
  _x4687 = kk_model_dash_resources__mlift3175_normal(mean, sdv, _x4688, _ctx); /*double*/
  return kk_double_box(_x4687, _ctx);
}

double kk_model_dash_resources_normal(double mean, double sdv, kk_context_t* _ctx) { /* (mean : double, sdv : double) -> effects-and-types/sample double */ 
  double x_3267 = kk_model_dash_resources_standard_normal(_ctx); /*double*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x4685 = kk_std_core_hnd_yield_extend(kk_model_dash_resources_new_normal_fun4686(mean, sdv, _ctx), _ctx); /*2*/
    return kk_double_unbox(_x4685, _ctx);
  }
  double _x4689 = (x_3267 * sdv); /*double*/
  return (mean + _x4689);
}


// lift anonymous function
struct kk_model_dash_resources_gaussian__model_fun4690__t {
  struct kk_function_s _base;
};
static double kk_model_dash_resources_gaussian__model_fun4690(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources_new_gaussian__model_fun4690(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_model_dash_resources_gaussian__model_fun4690, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_model_dash_resources_gaussian__model_fun4692__t {
  struct kk_function_s _base;
};
static kk_box_t kk_model_dash_resources_gaussian__model_fun4692(kk_function_t _fself, kk_box_t _b_3874, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources_new_gaussian__model_fun4692(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_model_dash_resources_gaussian__model_fun4692, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_model_dash_resources_gaussian__model_fun4692(kk_function_t _fself, kk_box_t _b_3874, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x4693;
  double _x4694 = kk_double_unbox(_b_3874, _ctx); /*double*/
  _x4693 = kk_model_dash_resources__mlift3175_normal(0x0p+0, 0x1.4p3, _x4694, _ctx); /*double*/
  return kk_double_box(_x4693, _ctx);
}


// lift anonymous function
struct kk_model_dash_resources_gaussian__model_fun4697__t {
  struct kk_function_s _base;
  size_t i_3271;
};
static kk_box_t kk_model_dash_resources_gaussian__model_fun4697(kk_function_t _fself, kk_function_t _b_3882, kk_box_t _b_3883, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources_new_gaussian__model_fun4697(size_t i_3271, kk_context_t* _ctx) {
  struct kk_model_dash_resources_gaussian__model_fun4697__t* _self = kk_function_alloc_as(struct kk_model_dash_resources_gaussian__model_fun4697__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_model_dash_resources_gaussian__model_fun4697, kk_context());
  _self->i_3271 = i_3271;
  return &_self->_base;
}

static kk_box_t kk_model_dash_resources_gaussian__model_fun4697(kk_function_t _fself, kk_function_t _b_3882, kk_box_t _b_3883, kk_context_t* _ctx) {
  struct kk_model_dash_resources_gaussian__model_fun4697__t* _self = kk_function_as(struct kk_model_dash_resources_gaussian__model_fun4697__t*, _fself);
  size_t i_3271 = _self->i_3271; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_3271, _b_3882, _b_3883, _ctx);
}
static double kk_model_dash_resources_gaussian__model_fun4690(kk_function_t _fself, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  size_t i_3271 = ((size_t)1); /*std/core/hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_3271,kk_context()); /*std/core/hnd/evv<<effects-and-types/sample,std/num/random/random,effects-and-types/score>>*/;
  double y;
  double x_3267 = kk_model_dash_resources_standard_normal(_ctx); /*double*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x4691 = kk_std_core_hnd_yield_extend(kk_model_dash_resources_new_gaussian__model_fun4692(_ctx), _ctx); /*2*/
    y = kk_double_unbox(_x4691, _ctx); /*double*/
  }
  else {
    double _x4695 = (x_3267 * (0x1.4p3)); /*double*/
    y = ((0x0p+0) + _x4695); /*double*/
  }
  kk_unit_t __w_l717_c9 = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x4696 = kk_std_core_hnd_yield_cont(kk_model_dash_resources_new_gaussian__model_fun4697(i_3271, _ctx), _ctx); /*3*/
    return kk_double_unbox(_x4696, _ctx);
  }
  return y;
}

kk_function_t kk_model_dash_resources_gaussian__model(kk_context_t* _ctx) { /* () -> effects-and-types/nmodel<double> */ 
  return kk_model_dash_resources_new_gaussian__model_fun4690(_ctx);
}
 
// monadic lift

kk_std_core_types__tuple2_ kk_model_dash_resources__mlift3176_generate__synthetic__lr__data(double _y_12, bool _y_13, kk_context_t* _ctx) { /* (double, bool) -> <effects-and-types/sample,std/num/random/random> (double, bool) */ 
  double _b_3894_3892 = (_y_12 * (0x1.4p3)); /*double*/;
  return kk_std_core_types__new_dash__lp__comma__rp_(kk_double_box(_b_3894_3892, _ctx), kk_bool_box(_y_13), _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_model_dash_resources__mlift3177_generate__synthetic__lr__data_fun4699__t {
  struct kk_function_s _base;
};
static kk_box_t kk_model_dash_resources__mlift3177_generate__synthetic__lr__data_fun4699(kk_function_t _fself, kk_box_t _b_3897, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources__new_mlift3177_generate__synthetic__lr__data_fun4699(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_model_dash_resources__mlift3177_generate__synthetic__lr__data_fun4699, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_model_dash_resources__mlift3177_generate__synthetic__lr__data_fun4699(kk_function_t _fself, kk_box_t _b_3897, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  bool _x4700;
  double _x4701 = kk_double_unbox(_b_3897, _ctx); /*double*/
  _x4700 = kk_model_dash_resources__mlift3168_bernoulli(0x1p-1, _x4701, _ctx); /*bool*/
  return kk_bool_box(_x4700);
}


// lift anonymous function
struct kk_model_dash_resources__mlift3177_generate__synthetic__lr__data_fun4703__t {
  struct kk_function_s _base;
  size_t i_3277;
};
static kk_box_t kk_model_dash_resources__mlift3177_generate__synthetic__lr__data_fun4703(kk_function_t _fself, kk_function_t _b_3905, kk_box_t _b_3906, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources__new_mlift3177_generate__synthetic__lr__data_fun4703(size_t i_3277, kk_context_t* _ctx) {
  struct kk_model_dash_resources__mlift3177_generate__synthetic__lr__data_fun4703__t* _self = kk_function_alloc_as(struct kk_model_dash_resources__mlift3177_generate__synthetic__lr__data_fun4703__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_model_dash_resources__mlift3177_generate__synthetic__lr__data_fun4703, kk_context());
  _self->i_3277 = i_3277;
  return &_self->_base;
}

static kk_box_t kk_model_dash_resources__mlift3177_generate__synthetic__lr__data_fun4703(kk_function_t _fself, kk_function_t _b_3905, kk_box_t _b_3906, kk_context_t* _ctx) {
  struct kk_model_dash_resources__mlift3177_generate__synthetic__lr__data_fun4703__t* _self = kk_function_as(struct kk_model_dash_resources__mlift3177_generate__synthetic__lr__data_fun4703__t*, _fself);
  size_t i_3277 = _self->i_3277; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_3277, _b_3905, _b_3906, _ctx);
}


// lift anonymous function
struct kk_model_dash_resources__mlift3177_generate__synthetic__lr__data_fun4705__t {
  struct kk_function_s _base;
  double _y_12;
};
static kk_box_t kk_model_dash_resources__mlift3177_generate__synthetic__lr__data_fun4705(kk_function_t _fself, kk_box_t _b_3916, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources__new_mlift3177_generate__synthetic__lr__data_fun4705(double _y_12, kk_context_t* _ctx) {
  struct kk_model_dash_resources__mlift3177_generate__synthetic__lr__data_fun4705__t* _self = kk_function_alloc_as(struct kk_model_dash_resources__mlift3177_generate__synthetic__lr__data_fun4705__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_model_dash_resources__mlift3177_generate__synthetic__lr__data_fun4705, kk_context());
  _self->_y_12 = _y_12;
  return &_self->_base;
}

static kk_box_t kk_model_dash_resources__mlift3177_generate__synthetic__lr__data_fun4705(kk_function_t _fself, kk_box_t _b_3916, kk_context_t* _ctx) {
  struct kk_model_dash_resources__mlift3177_generate__synthetic__lr__data_fun4705__t* _self = kk_function_as(struct kk_model_dash_resources__mlift3177_generate__synthetic__lr__data_fun4705__t*, _fself);
  double _y_12 = _self->_y_12; /* double */
  kk_drop_match(_self, {;}, {}, _ctx)
  kk_std_core_types__tuple2_ _x4706;
  bool _x4707 = kk_bool_unbox(_b_3916); /*bool*/
  _x4706 = kk_model_dash_resources__mlift3176_generate__synthetic__lr__data(_y_12, _x4707, _ctx); /*(double, bool)*/
  return kk_std_core_types__tuple2__box(_x4706, _ctx);
}

kk_std_core_types__tuple2_ kk_model_dash_resources__mlift3177_generate__synthetic__lr__data(double _y_12, kk_context_t* _ctx) { /* (double) -> <effects-and-types/sample,std/num/random/random> (double, bool) */ 
  bool x_3275;
  size_t i_3277 = ((size_t)1); /*std/core/hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_3277,kk_context()); /*std/core/hnd/evv<<effects-and-types/sample,std/num/random/random>>*/;
  bool y;
  double x_3198 = kk_effects_dash_and_dash_types_sample(_ctx); /*double*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x4698 = kk_std_core_hnd_yield_extend(kk_model_dash_resources__new_mlift3177_generate__synthetic__lr__data_fun4699(_ctx), _ctx); /*2*/
    y = kk_bool_unbox(_x4698); /*bool*/
  }
  else {
    bool _match_4483 = (x_3198 < (0x1p-1)); /*bool*/;
    if (_match_4483) {
      y = true; /*bool*/
    }
    else {
      y = false; /*bool*/
    }
  }
  kk_unit_t __w_l700_c9 = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x4702 = kk_std_core_hnd_yield_cont(kk_model_dash_resources__new_mlift3177_generate__synthetic__lr__data_fun4703(i_3277, _ctx), _ctx); /*3*/
    x_3275 = kk_bool_unbox(_x4702); /*bool*/
  }
  else {
    x_3275 = y; /*bool*/
  }
  if (kk_yielding(kk_context())) {
    kk_box_t _x4704 = kk_std_core_hnd_yield_extend(kk_model_dash_resources__new_mlift3177_generate__synthetic__lr__data_fun4705(_y_12, _ctx), _ctx); /*2*/
    return kk_std_core_types__tuple2__unbox(_x4704, _ctx);
  }
  return kk_model_dash_resources__mlift3176_generate__synthetic__lr__data(_y_12, x_3275, _ctx);
}


// lift anonymous function
struct kk_model_dash_resources_generate__synthetic__lr__data_fun4708__t {
  struct kk_function_s _base;
};
static kk_box_t kk_model_dash_resources_generate__synthetic__lr__data_fun4708(kk_function_t _fself, kk_integer_t _b_3949, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources_new_generate__synthetic__lr__data_fun4708(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_model_dash_resources_generate__synthetic__lr__data_fun4708, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_model_dash_resources_generate__synthetic__lr__data_fun4709__t {
  struct kk_function_s _base;
};
static kk_box_t kk_model_dash_resources_generate__synthetic__lr__data_fun4709(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources_new_generate__synthetic__lr__data_fun4709(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_model_dash_resources_generate__synthetic__lr__data_fun4709, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_model_dash_resources_generate__synthetic__lr__data_fun4717__t {
  struct kk_function_s _base;
  size_t i0_3285;
};
static kk_box_t kk_model_dash_resources_generate__synthetic__lr__data_fun4717(kk_function_t _fself, kk_function_t _b_3932, kk_box_t _b_3933, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources_new_generate__synthetic__lr__data_fun4717(size_t i0_3285, kk_context_t* _ctx) {
  struct kk_model_dash_resources_generate__synthetic__lr__data_fun4717__t* _self = kk_function_alloc_as(struct kk_model_dash_resources_generate__synthetic__lr__data_fun4717__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_model_dash_resources_generate__synthetic__lr__data_fun4717, kk_context());
  _self->i0_3285 = i0_3285;
  return &_self->_base;
}

static kk_box_t kk_model_dash_resources_generate__synthetic__lr__data_fun4717(kk_function_t _fself, kk_function_t _b_3932, kk_box_t _b_3933, kk_context_t* _ctx) {
  struct kk_model_dash_resources_generate__synthetic__lr__data_fun4717__t* _self = kk_function_as(struct kk_model_dash_resources_generate__synthetic__lr__data_fun4717__t*, _fself);
  size_t i0_3285 = _self->i0_3285; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i0_3285, _b_3932, _b_3933, _ctx);
}


// lift anonymous function
struct kk_model_dash_resources_generate__synthetic__lr__data_fun4719__t {
  struct kk_function_s _base;
};
static kk_box_t kk_model_dash_resources_generate__synthetic__lr__data_fun4719(kk_function_t _fself, kk_box_t _b_3943, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources_new_generate__synthetic__lr__data_fun4719(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_model_dash_resources_generate__synthetic__lr__data_fun4719, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_model_dash_resources_generate__synthetic__lr__data_fun4719(kk_function_t _fself, kk_box_t _b_3943, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core_types__tuple2_ _x4720;
  double _x4721 = kk_double_unbox(_b_3943, _ctx); /*double*/
  _x4720 = kk_model_dash_resources__mlift3177_generate__synthetic__lr__data(_x4721, _ctx); /*(double, bool)*/
  return kk_std_core_types__tuple2__box(_x4720, _ctx);
}
static kk_box_t kk_model_dash_resources_generate__synthetic__lr__data_fun4709(kk_function_t _fself, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core_types__tuple2_ _x4710;
  double x_3283;
  size_t i0_3285 = ((size_t)1); /*std/core/hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i0_3285,kk_context()); /*std/core/hnd/evv<<effects-and-types/sample,std/num/random/random>>*/;
  double y;
  kk_std_core_hnd__ev ev_404;
  size_t _x4711 = ((size_t)0); /*size_t*/
  ev_404 = kk_evv_at(_x4711,kk_context()); /*std/core/hnd/ev<effects-and-types/.hnd-sample>*/
  kk_box_t _x4712;
  struct kk_std_core_hnd_Ev* _con4713 = kk_std_core_hnd__as_Ev(ev_404);
  kk_std_core_hnd__marker m = _con4713->marker;
  kk_box_t _box_x3919 = _con4713->hnd;
  kk_effects_dash_and_dash_types__hnd_sample h = kk_effects_dash_and_dash_types__hnd_sample_unbox(_box_x3919, NULL);
  kk_effects_dash_and_dash_types__hnd_sample_dup(h);
  kk_std_core_hnd__clause0 _match_4479;
  struct kk_effects_dash_and_dash_types__Hnd_sample* _con4715 = kk_effects_dash_and_dash_types__as_Hnd_sample(h);
  kk_std_core_hnd__clause0 fun_sample = _con4715->fun_sample;
  if (kk_effects_dash_and_dash_types__hnd_sample_is_unique(h)) {
    kk_effects_dash_and_dash_types__hnd_sample_free(h);
  }
  else {
    kk_std_core_hnd__clause0_dup(fun_sample);
    kk_effects_dash_and_dash_types__hnd_sample_decref(h, _ctx);
  }
  _match_4479 = fun_sample; /*std/core/hnd/clause0<double,effects-and-types/.hnd-sample,1,2>*/
  kk_function_t _fun_unbox_x3922 = _match_4479.clause;
  _x4712 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x3922, (_fun_unbox_x3922, m, ev_404, _ctx)); /*6*/
  y = kk_double_unbox(_x4712, _ctx); /*double*/
  kk_unit_t __w_l683_c9 = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x4716 = kk_std_core_hnd_yield_cont(kk_model_dash_resources_new_generate__synthetic__lr__data_fun4717(i0_3285, _ctx), _ctx); /*3*/
    x_3283 = kk_double_unbox(_x4716, _ctx); /*double*/
  }
  else {
    x_3283 = y; /*double*/
  }
  if (kk_yielding(kk_context())) {
    kk_box_t _x4718 = kk_std_core_hnd_yield_extend(kk_model_dash_resources_new_generate__synthetic__lr__data_fun4719(_ctx), _ctx); /*2*/
    _x4710 = kk_std_core_types__tuple2__unbox(_x4718, _ctx); /*(double, bool)*/
  }
  else {
    _x4710 = kk_model_dash_resources__mlift3177_generate__synthetic__lr__data(x_3283, _ctx); /*(double, bool)*/
  }
  return kk_std_core_types__tuple2__box(_x4710, _ctx);
}
static kk_box_t kk_model_dash_resources_generate__synthetic__lr__data_fun4708(kk_function_t _fself, kk_integer_t _b_3949, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_integer_drop(_b_3949, _ctx);
  return kk_handlers_random__sampler(kk_model_dash_resources_new_generate__synthetic__lr__data_fun4709(_ctx), _ctx);
}

kk_std_core__list kk_model_dash_resources_generate__synthetic__lr__data(kk_integer_t num, kk_context_t* _ctx) { /* (num : int) -> std/num/random/random list<(double, bool)> */ 
  return kk_std_core__lift21054_list_1(kk_model_dash_resources_new_generate__synthetic__lr__data_fun4708(_ctx), kk_integer_from_small(1), num, kk_std_core__new_Nil(_ctx), _ctx);
}
 
// monadic lift

double kk_model_dash_resources__mlift3178_grandx(double c, double d, double w, double z, double _y_17, kk_context_t* _ctx) { /* (c : double, d : double, w : double, z : double, double) -> effects-and-types/sample double */ 
  bool _match_4476;
  double _x4722 = log(_y_17); /*double*/
  double _x4723;
  double _x4724;
  double _x4725;
  double _x4726;
  double _x4727 = pow(z,0x1p1); /*double*/
  _x4726 = ((0x1p-1) * _x4727); /*double*/
  _x4725 = (_x4726 + d); /*double*/
  double _x4728 = (d * w); /*double*/
  _x4724 = (_x4725 - _x4728); /*double*/
  double _x4729;
  double _x4730 = log(w); /*double*/
  _x4729 = (d * _x4730); /*double*/
  _x4723 = (_x4724 + _x4729); /*double*/
  _match_4476 = (_x4722 > _x4723); /*bool*/
  if (_match_4476) {
    return kk_model_dash_resources_grandx(d, c, w, _ctx);
  }
  return w;
}
 
// monadic lift


// lift anonymous function
struct kk_model_dash_resources__mlift3179_grandx_fun4736__t {
  struct kk_function_s _base;
  double c0;
  double d0;
  double w0;
  double z0;
};
static kk_box_t kk_model_dash_resources__mlift3179_grandx_fun4736(kk_function_t _fself, kk_box_t _b_3958, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources__new_mlift3179_grandx_fun4736(double c0, double d0, double w0, double z0, kk_context_t* _ctx) {
  struct kk_model_dash_resources__mlift3179_grandx_fun4736__t* _self = kk_function_alloc_as(struct kk_model_dash_resources__mlift3179_grandx_fun4736__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_model_dash_resources__mlift3179_grandx_fun4736, kk_context());
  _self->c0 = c0;
  _self->d0 = d0;
  _self->w0 = w0;
  _self->z0 = z0;
  return &_self->_base;
}

static kk_box_t kk_model_dash_resources__mlift3179_grandx_fun4736(kk_function_t _fself, kk_box_t _b_3958, kk_context_t* _ctx) {
  struct kk_model_dash_resources__mlift3179_grandx_fun4736__t* _self = kk_function_as(struct kk_model_dash_resources__mlift3179_grandx_fun4736__t*, _fself);
  double c0 = _self->c0; /* double */
  double d0 = _self->d0; /* double */
  double w0 = _self->w0; /* double */
  double z0 = _self->z0; /* double */
  kk_drop_match(_self, {;;;;}, {}, _ctx)
  double _x4737;
  double _x4738 = kk_double_unbox(_b_3958, _ctx); /*double*/
  _x4737 = kk_model_dash_resources__mlift3178_grandx(c0, d0, w0, z0, _x4738, _ctx); /*double*/
  return kk_double_box(_x4737, _ctx);
}

double kk_model_dash_resources__mlift3179_grandx(double c0, double d0, double z0, kk_context_t* _ctx) { /* (c : double, d : double, z : double) -> effects-and-types/sample double */ 
  double w0;
  double _x4731;
  double _x4732 = (c0 * z0); /*double*/
  _x4731 = (0x1p0 + _x4732); /*double*/
  w0 = pow(_x4731,(0x1.8p1)); /*double*/
  bool _match_4474;
  double _x4733;
  double _x4734 = (0x1p0 / c0); /*double*/
  _x4733 = ((0x0p+0) - _x4734); /*double*/
  _match_4474 = (z0 > _x4733); /*bool*/
  if (_match_4474) {
    double x_3287 = kk_effects_dash_and_dash_types_sample(_ctx); /*double*/;
    if (kk_yielding(kk_context())) {
      kk_box_t _x4735 = kk_std_core_hnd_yield_extend(kk_model_dash_resources__new_mlift3179_grandx_fun4736(c0, d0, w0, z0, _ctx), _ctx); /*2*/
      return kk_double_unbox(_x4735, _ctx);
    }
    return kk_model_dash_resources__mlift3178_grandx(c0, d0, w0, z0, x_3287, _ctx);
  }
  return kk_model_dash_resources_grandx(d0, c0, w0, _ctx);
}


// lift anonymous function
struct kk_model_dash_resources_grandx_fun4740__t {
  struct kk_function_s _base;
};
static kk_box_t kk_model_dash_resources_grandx_fun4740(kk_function_t _fself, kk_box_t _b_3962, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources_new_grandx_fun4740(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_model_dash_resources_grandx_fun4740, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_model_dash_resources_grandx_fun4740(kk_function_t _fself, kk_box_t _b_3962, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x4741;
  double _x4742 = kk_double_unbox(_b_3962, _ctx); /*double*/
  _x4741 = kk_model_dash_resources__mlift3175_normal(0x0p+0, 0x1p0, _x4742, _ctx); /*double*/
  return kk_double_box(_x4741, _ctx);
}


// lift anonymous function
struct kk_model_dash_resources_grandx_fun4745__t {
  struct kk_function_s _base;
  double c1;
  double d1;
};
static kk_box_t kk_model_dash_resources_grandx_fun4745(kk_function_t _fself, kk_box_t _b_3966, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources_new_grandx_fun4745(double c1, double d1, kk_context_t* _ctx) {
  struct kk_model_dash_resources_grandx_fun4745__t* _self = kk_function_alloc_as(struct kk_model_dash_resources_grandx_fun4745__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_model_dash_resources_grandx_fun4745, kk_context());
  _self->c1 = c1;
  _self->d1 = d1;
  return &_self->_base;
}

static kk_box_t kk_model_dash_resources_grandx_fun4745(kk_function_t _fself, kk_box_t _b_3966, kk_context_t* _ctx) {
  struct kk_model_dash_resources_grandx_fun4745__t* _self = kk_function_as(struct kk_model_dash_resources_grandx_fun4745__t*, _fself);
  double c1 = _self->c1; /* double */
  double d1 = _self->d1; /* double */
  kk_drop_match(_self, {;;}, {}, _ctx)
  double _x4746;
  double _x4747 = kk_double_unbox(_b_3966, _ctx); /*double*/
  _x4746 = kk_model_dash_resources__mlift3179_grandx(c1, d1, _x4747, _ctx); /*double*/
  return kk_double_box(_x4746, _ctx);
}


// lift anonymous function
struct kk_model_dash_resources_grandx_fun4753__t {
  struct kk_function_s _base;
  double c1;
  double d1;
  double w1;
  double x_3289;
};
static kk_box_t kk_model_dash_resources_grandx_fun4753(kk_function_t _fself, kk_box_t _b_3968, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources_new_grandx_fun4753(double c1, double d1, double w1, double x_3289, kk_context_t* _ctx) {
  struct kk_model_dash_resources_grandx_fun4753__t* _self = kk_function_alloc_as(struct kk_model_dash_resources_grandx_fun4753__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_model_dash_resources_grandx_fun4753, kk_context());
  _self->c1 = c1;
  _self->d1 = d1;
  _self->w1 = w1;
  _self->x_3289 = x_3289;
  return &_self->_base;
}

static kk_box_t kk_model_dash_resources_grandx_fun4753(kk_function_t _fself, kk_box_t _b_3968, kk_context_t* _ctx) {
  struct kk_model_dash_resources_grandx_fun4753__t* _self = kk_function_as(struct kk_model_dash_resources_grandx_fun4753__t*, _fself);
  double c1 = _self->c1; /* double */
  double d1 = _self->d1; /* double */
  double w1 = _self->w1; /* double */
  double x_3289 = _self->x_3289; /* double */
  kk_drop_match(_self, {;;;;}, {}, _ctx)
  double _x4754;
  double _x4755 = kk_double_unbox(_b_3968, _ctx); /*double*/
  _x4754 = kk_model_dash_resources__mlift3178_grandx(c1, d1, w1, x_3289, _x4755, _ctx); /*double*/
  return kk_double_box(_x4754, _ctx);
}

double kk_model_dash_resources_grandx(double d1, double c1, double v, kk_context_t* _ctx) { /* (d : double, c : double, v : double) -> <div,effects-and-types/sample> double */ 
  kk__tailcall: ;
  double x_3289;
  double x0_3294 = kk_model_dash_resources_standard_normal(_ctx); /*double*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x4739 = kk_std_core_hnd_yield_extend(kk_model_dash_resources_new_grandx_fun4740(_ctx), _ctx); /*2*/
    x_3289 = kk_double_unbox(_x4739, _ctx); /*double*/
  }
  else {
    double _x4743 = (x0_3294 * 0x1p0); /*double*/
    x_3289 = ((0x0p+0) + _x4743); /*double*/
  }
  if (kk_yielding(kk_context())) {
    kk_box_t _x4744 = kk_std_core_hnd_yield_extend(kk_model_dash_resources_new_grandx_fun4745(c1, d1, _ctx), _ctx); /*2*/
    return kk_double_unbox(_x4744, _ctx);
  }
  double w1;
  double _x4748;
  double _x4749 = (c1 * x_3289); /*double*/
  _x4748 = (0x1p0 + _x4749); /*double*/
  w1 = pow(_x4748,(0x1.8p1)); /*double*/
  bool _match_4470;
  double _x4750;
  double _x4751 = (0x1p0 / c1); /*double*/
  _x4750 = ((0x0p+0) - _x4751); /*double*/
  _match_4470 = (x_3289 > _x4750); /*bool*/
  if (_match_4470) {
    double x1_3299 = kk_effects_dash_and_dash_types_sample(_ctx); /*double*/;
    if (kk_yielding(kk_context())) {
      kk_box_t _x4752 = kk_std_core_hnd_yield_extend(kk_model_dash_resources_new_grandx_fun4753(c1, d1, w1, x_3289, _ctx), _ctx); /*2*/
      return kk_double_unbox(_x4752, _ctx);
    }
    bool _match_4472;
    double _x4756 = log(x1_3299); /*double*/
    double _x4757;
    double _x4758;
    double _x4759;
    double _x4760;
    double _x4761 = pow(x_3289,0x1p1); /*double*/
    _x4760 = ((0x1p-1) * _x4761); /*double*/
    _x4759 = (_x4760 + d1); /*double*/
    double _x4762 = (d1 * w1); /*double*/
    _x4758 = (_x4759 - _x4762); /*double*/
    double _x4763;
    double _x4764 = log(w1); /*double*/
    _x4763 = (d1 * _x4764); /*double*/
    _x4757 = (_x4758 + _x4763); /*double*/
    _match_4472 = (_x4756 > _x4757); /*bool*/
    if (_match_4472) {
      { // tailcall
        v = w1;
        goto kk__tailcall;
      }
    }
    return w1;
  }
  { // tailcall
    v = w1;
    goto kk__tailcall;
  }
}
 
// monadic lift

double kk_model_dash_resources__mlift3180_grand(double alpha, double x, double _y_23, kk_context_t* _ctx) { /* (alpha : double, x : double, double) -> effects-and-types/sample double */ 
  double _x4765;
  double _x4766 = (0x1p0 / alpha); /*double*/
  _x4765 = pow(_y_23,_x4766); /*double*/
  return (x * _x4765);
}
 
// monadic lift


// lift anonymous function
struct kk_model_dash_resources__mlift3181_grand_fun4768__t {
  struct kk_function_s _base;
  double alpha0;
  double x0;
};
static kk_box_t kk_model_dash_resources__mlift3181_grand_fun4768(kk_function_t _fself, kk_box_t _b_3974, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources__new_mlift3181_grand_fun4768(double alpha0, double x0, kk_context_t* _ctx) {
  struct kk_model_dash_resources__mlift3181_grand_fun4768__t* _self = kk_function_alloc_as(struct kk_model_dash_resources__mlift3181_grand_fun4768__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_model_dash_resources__mlift3181_grand_fun4768, kk_context());
  _self->alpha0 = alpha0;
  _self->x0 = x0;
  return &_self->_base;
}

static kk_box_t kk_model_dash_resources__mlift3181_grand_fun4768(kk_function_t _fself, kk_box_t _b_3974, kk_context_t* _ctx) {
  struct kk_model_dash_resources__mlift3181_grand_fun4768__t* _self = kk_function_as(struct kk_model_dash_resources__mlift3181_grand_fun4768__t*, _fself);
  double alpha0 = _self->alpha0; /* double */
  double x0 = _self->x0; /* double */
  kk_drop_match(_self, {;;}, {}, _ctx)
  double _x4769;
  double _x4770 = kk_double_unbox(_b_3974, _ctx); /*double*/
  _x4769 = kk_model_dash_resources__mlift3180_grand(alpha0, x0, _x4770, _ctx); /*double*/
  return kk_double_box(_x4769, _ctx);
}

double kk_model_dash_resources__mlift3181_grand(double alpha0, double x0, kk_context_t* _ctx) { /* (alpha : double, x : double) -> <effects-and-types/sample,div> double */ 
  double x0_3303 = kk_effects_dash_and_dash_types_sample(_ctx); /*double*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x4767 = kk_std_core_hnd_yield_extend(kk_model_dash_resources__new_mlift3181_grand_fun4768(alpha0, x0, _ctx), _ctx); /*2*/
    return kk_double_unbox(_x4767, _ctx);
  }
  return kk_model_dash_resources__mlift3180_grand(alpha0, x0, x0_3303, _ctx);
}
 
// monadic lift

double kk_model_dash_resources__mlift3182_grand(double beta, double d, double v, kk_context_t* _ctx) { /* (beta : double, d : double, v : double) -> <div,effects-and-types/sample> double */ 
  double _x4771 = (d * v); /*double*/
  return (_x4771 / beta);
}


// lift anonymous function
struct kk_model_dash_resources_grand_fun4774__t {
  struct kk_function_s _base;
  double alpha1;
};
static kk_box_t kk_model_dash_resources_grand_fun4774(kk_function_t _fself, kk_box_t _b_3978, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources_new_grand_fun4774(double alpha1, kk_context_t* _ctx) {
  struct kk_model_dash_resources_grand_fun4774__t* _self = kk_function_alloc_as(struct kk_model_dash_resources_grand_fun4774__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_model_dash_resources_grand_fun4774, kk_context());
  _self->alpha1 = alpha1;
  return &_self->_base;
}

static kk_box_t kk_model_dash_resources_grand_fun4774(kk_function_t _fself, kk_box_t _b_3978, kk_context_t* _ctx) {
  struct kk_model_dash_resources_grand_fun4774__t* _self = kk_function_as(struct kk_model_dash_resources_grand_fun4774__t*, _fself);
  double alpha1 = _self->alpha1; /* double */
  kk_drop_match(_self, {;}, {}, _ctx)
  double _x4775;
  double _x4776 = kk_double_unbox(_b_3978, _ctx); /*double*/
  _x4775 = kk_model_dash_resources__mlift3181_grand(alpha1, _x4776, _ctx); /*double*/
  return kk_double_box(_x4775, _ctx);
}


// lift anonymous function
struct kk_model_dash_resources_grand_fun4778__t {
  struct kk_function_s _base;
  double alpha1;
  double x_3305;
};
static kk_box_t kk_model_dash_resources_grand_fun4778(kk_function_t _fself, kk_box_t _b_3980, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources_new_grand_fun4778(double alpha1, double x_3305, kk_context_t* _ctx) {
  struct kk_model_dash_resources_grand_fun4778__t* _self = kk_function_alloc_as(struct kk_model_dash_resources_grand_fun4778__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_model_dash_resources_grand_fun4778, kk_context());
  _self->alpha1 = alpha1;
  _self->x_3305 = x_3305;
  return &_self->_base;
}

static kk_box_t kk_model_dash_resources_grand_fun4778(kk_function_t _fself, kk_box_t _b_3980, kk_context_t* _ctx) {
  struct kk_model_dash_resources_grand_fun4778__t* _self = kk_function_as(struct kk_model_dash_resources_grand_fun4778__t*, _fself);
  double alpha1 = _self->alpha1; /* double */
  double x_3305 = _self->x_3305; /* double */
  kk_drop_match(_self, {;;}, {}, _ctx)
  double _x4779;
  double _x4780 = kk_double_unbox(_b_3980, _ctx); /*double*/
  _x4779 = kk_model_dash_resources__mlift3180_grand(alpha1, x_3305, _x4780, _ctx); /*double*/
  return kk_double_box(_x4779, _ctx);
}


// lift anonymous function
struct kk_model_dash_resources_grand_fun4787__t {
  struct kk_function_s _base;
  double beta0;
  double d0;
};
static kk_box_t kk_model_dash_resources_grand_fun4787(kk_function_t _fself, kk_box_t _b_3982, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources_new_grand_fun4787(double beta0, double d0, kk_context_t* _ctx) {
  struct kk_model_dash_resources_grand_fun4787__t* _self = kk_function_alloc_as(struct kk_model_dash_resources_grand_fun4787__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_model_dash_resources_grand_fun4787, kk_context());
  _self->beta0 = beta0;
  _self->d0 = d0;
  return &_self->_base;
}

static kk_box_t kk_model_dash_resources_grand_fun4787(kk_function_t _fself, kk_box_t _b_3982, kk_context_t* _ctx) {
  struct kk_model_dash_resources_grand_fun4787__t* _self = kk_function_as(struct kk_model_dash_resources_grand_fun4787__t*, _fself);
  double beta0 = _self->beta0; /* double */
  double d0 = _self->d0; /* double */
  kk_drop_match(_self, {;;}, {}, _ctx)
  double _x4788;
  double _x4789 = kk_double_unbox(_b_3982, _ctx); /*double*/
  _x4788 = kk_model_dash_resources__mlift3182_grand(beta0, d0, _x4789, _ctx); /*double*/
  return kk_double_box(_x4788, _ctx);
}

double kk_model_dash_resources_grand(double alpha1, double beta0, kk_context_t* _ctx) { /* (alpha : double, beta : double) -> <div,effects-and-types/sample> double */ 
  bool _match_4464 = (alpha1 <= 0x1p0); /*bool*/;
  if (_match_4464) {
    double x_3305;
    double _x4772 = (alpha1 + 0x1p0); /*double*/
    x_3305 = kk_model_dash_resources_grand(_x4772, beta0, _ctx); /*double*/
    if (kk_yielding(kk_context())) {
      kk_box_t _x4773 = kk_std_core_hnd_yield_extend(kk_model_dash_resources_new_grand_fun4774(alpha1, _ctx), _ctx); /*2*/
      return kk_double_unbox(_x4773, _ctx);
    }
    double x2_3309 = kk_effects_dash_and_dash_types_sample(_ctx); /*double*/;
    if (kk_yielding(kk_context())) {
      kk_box_t _x4777 = kk_std_core_hnd_yield_extend(kk_model_dash_resources_new_grand_fun4778(alpha1, x_3305, _ctx), _ctx); /*2*/
      return kk_double_unbox(_x4777, _ctx);
    }
    double _x4781;
    double _x4782 = (0x1p0 / alpha1); /*double*/
    _x4781 = pow(x2_3309,_x4782); /*double*/
    return (x_3305 * _x4781);
  }
  double d0;
  double _x4783 = (0x1p0 / (0x1.8p1)); /*double*/
  d0 = (alpha1 - _x4783); /*double*/
  double c;
  double _x4784;
  double _x4785 = ((0x1.2p3) * d0); /*double*/
  _x4784 = sqrt(_x4785); /*double*/
  c = (0x1p0 / _x4784); /*double*/
  double x3_3313 = kk_model_dash_resources_grandx(d0, c, 0x0p+0, _ctx); /*double*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x4786 = kk_std_core_hnd_yield_extend(kk_model_dash_resources_new_grand_fun4787(beta0, d0, _ctx), _ctx); /*2*/
    return kk_double_unbox(_x4786, _ctx);
  }
  double _x4790 = (d0 * x3_3313); /*double*/
  return (_x4790 / beta0);
}
 
// monadic lift


// lift anonymous function
struct kk_model_dash_resources__mlift3183_logistic__regression_fun4793__t {
  struct kk_function_s _base;
  size_t i_3317;
};
static kk_box_t kk_model_dash_resources__mlift3183_logistic__regression_fun4793(kk_function_t _fself, kk_function_t _b_3994, kk_box_t _b_3995, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources__new_mlift3183_logistic__regression_fun4793(size_t i_3317, kk_context_t* _ctx) {
  struct kk_model_dash_resources__mlift3183_logistic__regression_fun4793__t* _self = kk_function_alloc_as(struct kk_model_dash_resources__mlift3183_logistic__regression_fun4793__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_model_dash_resources__mlift3183_logistic__regression_fun4793, kk_context());
  _self->i_3317 = i_3317;
  return &_self->_base;
}

static kk_box_t kk_model_dash_resources__mlift3183_logistic__regression_fun4793(kk_function_t _fself, kk_function_t _b_3994, kk_box_t _b_3995, kk_context_t* _ctx) {
  struct kk_model_dash_resources__mlift3183_logistic__regression_fun4793__t* _self = kk_function_as(struct kk_model_dash_resources__mlift3183_logistic__regression_fun4793__t*, _fself);
  size_t i_3317 = _self->i_3317; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_3317, _b_3994, _b_3995, _ctx);
}


// lift anonymous function
struct kk_model_dash_resources__mlift3183_logistic__regression_fun4797__t {
  struct kk_function_s _base;
  size_t i0_3320;
};
static kk_box_t kk_model_dash_resources__mlift3183_logistic__regression_fun4797(kk_function_t _fself, kk_function_t _b_4002, kk_box_t _b_4003, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources__new_mlift3183_logistic__regression_fun4797(size_t i0_3320, kk_context_t* _ctx) {
  struct kk_model_dash_resources__mlift3183_logistic__regression_fun4797__t* _self = kk_function_alloc_as(struct kk_model_dash_resources__mlift3183_logistic__regression_fun4797__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_model_dash_resources__mlift3183_logistic__regression_fun4797, kk_context());
  _self->i0_3320 = i0_3320;
  return &_self->_base;
}

static kk_box_t kk_model_dash_resources__mlift3183_logistic__regression_fun4797(kk_function_t _fself, kk_function_t _b_4002, kk_box_t _b_4003, kk_context_t* _ctx) {
  struct kk_model_dash_resources__mlift3183_logistic__regression_fun4797__t* _self = kk_function_as(struct kk_model_dash_resources__mlift3183_logistic__regression_fun4797__t*, _fself);
  size_t i0_3320 = _self->i0_3320; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i0_3320, _b_4002, _b_4003, _ctx);
}

kk_unit_t kk_model_dash_resources__mlift3183_logistic__regression(bool label, double p, kk_context_t* _ctx) { /* (label : bool, p : double) -> <effects-and-types/sample,effects-and-types/score> () */ 
  if (label) {
    kk_effects_dash_and_dash_types__exp _x13;
    double _x4791 = log(p); /*double*/
    _x13 = kk_effects_dash_and_dash_types__new_Exp(_x4791, _ctx); /*effects-and-types/exp*/
    size_t i_3317 = ((size_t)1); /*std/core/hnd/ev-index*/;
    kk_evv_t w = kk_evv_swap_create1(i_3317,kk_context()); /*std/core/hnd/evv<<effects-and-types/score,effects-and-types/sample>>*/;
    kk_unit_t y = kk_Unit;
    kk_effects_dash_and_dash_types_score(_x13, _ctx);
    kk_unit_t __w_l700_c9 = kk_Unit;
    kk_evv_set(w,kk_context());
    if (kk_yielding(kk_context())) {
      kk_box_t _x4792 = kk_std_core_hnd_yield_cont(kk_model_dash_resources__new_mlift3183_logistic__regression_fun4793(i_3317, _ctx), _ctx); /*3*/
      kk_unit_unbox(_x4792); return kk_Unit;
    }
    y; return kk_Unit;
  }
  kk_effects_dash_and_dash_types__exp _x14;
  double _x4794;
  double _x4795 = (0x1p0 - p); /*double*/
  _x4794 = log(_x4795); /*double*/
  _x14 = kk_effects_dash_and_dash_types__new_Exp(_x4794, _ctx); /*effects-and-types/exp*/
  size_t i0_3320 = ((size_t)1); /*std/core/hnd/ev-index*/;
  kk_evv_t w0 = kk_evv_swap_create1(i0_3320,kk_context()); /*std/core/hnd/evv<<effects-and-types/score,effects-and-types/sample>>*/;
  kk_unit_t y0 = kk_Unit;
  kk_effects_dash_and_dash_types_score(_x14, _ctx);
  kk_unit_t __w_l700_c90 = kk_Unit;
  kk_evv_set(w0,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x4796 = kk_std_core_hnd_yield_cont(kk_model_dash_resources__new_mlift3183_logistic__regression_fun4797(i0_3320, _ctx), _ctx); /*3*/
    kk_unit_unbox(_x4796); return kk_Unit;
  }
  y0; return kk_Unit;
}
 
// monadic lift

kk_std_core_types__tuple2_ kk_model_dash_resources__mlift3184_logistic__regression(double b, double m, kk_std_core__list wild__, kk_context_t* _ctx) { /* (b : double, m : double, wild_ : list<()>) -> <effects-and-types/sample,effects-and-types/score,div> (double, double) */ 
  kk_std_core__list_drop(wild__, _ctx);
  return kk_std_core_types__new_dash__lp__comma__rp_(kk_double_box(m, _ctx), kk_double_box(b, _ctx), _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_model_dash_resources__mlift3185_logistic__regression_fun4798__t {
  struct kk_function_s _base;
  double b;
  double m;
  double sigma;
};
static kk_box_t kk_model_dash_resources__mlift3185_logistic__regression_fun4798(kk_function_t _fself, kk_box_t _b_4048, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources__new_mlift3185_logistic__regression_fun4798(double b, double m, double sigma, kk_context_t* _ctx) {
  struct kk_model_dash_resources__mlift3185_logistic__regression_fun4798__t* _self = kk_function_alloc_as(struct kk_model_dash_resources__mlift3185_logistic__regression_fun4798__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_model_dash_resources__mlift3185_logistic__regression_fun4798, kk_context());
  _self->b = b;
  _self->m = m;
  _self->sigma = sigma;
  return &_self->_base;
}



// lift anonymous function
struct kk_model_dash_resources__mlift3185_logistic__regression_fun4807__t {
  struct kk_function_s _base;
  double mean_3331;
  double sigma;
};
static kk_box_t kk_model_dash_resources__mlift3185_logistic__regression_fun4807(kk_function_t _fself, kk_box_t _b_4026, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources__new_mlift3185_logistic__regression_fun4807(double mean_3331, double sigma, kk_context_t* _ctx) {
  struct kk_model_dash_resources__mlift3185_logistic__regression_fun4807__t* _self = kk_function_alloc_as(struct kk_model_dash_resources__mlift3185_logistic__regression_fun4807__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_model_dash_resources__mlift3185_logistic__regression_fun4807, kk_context());
  _self->mean_3331 = mean_3331;
  _self->sigma = sigma;
  return &_self->_base;
}

static kk_box_t kk_model_dash_resources__mlift3185_logistic__regression_fun4807(kk_function_t _fself, kk_box_t _b_4026, kk_context_t* _ctx) {
  struct kk_model_dash_resources__mlift3185_logistic__regression_fun4807__t* _self = kk_function_as(struct kk_model_dash_resources__mlift3185_logistic__regression_fun4807__t*, _fself);
  double mean_3331 = _self->mean_3331; /* double */
  double sigma = _self->sigma; /* double */
  kk_drop_match(_self, {;;}, {}, _ctx)
  double _x4808;
  double _x4809 = kk_double_unbox(_b_4026, _ctx); /*double*/
  _x4808 = kk_model_dash_resources__mlift3175_normal(mean_3331, sigma, _x4809, _ctx); /*double*/
  return kk_double_box(_x4808, _ctx);
}


// lift anonymous function
struct kk_model_dash_resources__mlift3185_logistic__regression_fun4812__t {
  struct kk_function_s _base;
  size_t i_3327;
};
static kk_box_t kk_model_dash_resources__mlift3185_logistic__regression_fun4812(kk_function_t _fself, kk_function_t _b_4034, kk_box_t _b_4035, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources__new_mlift3185_logistic__regression_fun4812(size_t i_3327, kk_context_t* _ctx) {
  struct kk_model_dash_resources__mlift3185_logistic__regression_fun4812__t* _self = kk_function_alloc_as(struct kk_model_dash_resources__mlift3185_logistic__regression_fun4812__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_model_dash_resources__mlift3185_logistic__regression_fun4812, kk_context());
  _self->i_3327 = i_3327;
  return &_self->_base;
}

static kk_box_t kk_model_dash_resources__mlift3185_logistic__regression_fun4812(kk_function_t _fself, kk_function_t _b_4034, kk_box_t _b_4035, kk_context_t* _ctx) {
  struct kk_model_dash_resources__mlift3185_logistic__regression_fun4812__t* _self = kk_function_as(struct kk_model_dash_resources__mlift3185_logistic__regression_fun4812__t*, _fself);
  size_t i_3327 = _self->i_3327; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_3327, _b_4034, _b_4035, _ctx);
}


// lift anonymous function
struct kk_model_dash_resources__mlift3185_logistic__regression_fun4814__t {
  struct kk_function_s _base;
  bool label;
};
static kk_box_t kk_model_dash_resources__mlift3185_logistic__regression_fun4814(kk_function_t _fself, kk_box_t _b_4045, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources__new_mlift3185_logistic__regression_fun4814(bool label, kk_context_t* _ctx) {
  struct kk_model_dash_resources__mlift3185_logistic__regression_fun4814__t* _self = kk_function_alloc_as(struct kk_model_dash_resources__mlift3185_logistic__regression_fun4814__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_model_dash_resources__mlift3185_logistic__regression_fun4814, kk_context());
  _self->label = label;
  return &_self->_base;
}

static kk_box_t kk_model_dash_resources__mlift3185_logistic__regression_fun4814(kk_function_t _fself, kk_box_t _b_4045, kk_context_t* _ctx) {
  struct kk_model_dash_resources__mlift3185_logistic__regression_fun4814__t* _self = kk_function_as(struct kk_model_dash_resources__mlift3185_logistic__regression_fun4814__t*, _fself);
  bool label = _self->label; /* bool */
  kk_drop_match(_self, {;}, {}, _ctx)
  kk_unit_t _x4815 = kk_Unit;
  double _x4816 = kk_double_unbox(_b_4045, _ctx); /*double*/
  kk_model_dash_resources__mlift3183_logistic__regression(label, _x4816, _ctx);
  return kk_unit_box(_x4815);
}
static kk_box_t kk_model_dash_resources__mlift3185_logistic__regression_fun4798(kk_function_t _fself, kk_box_t _b_4048, kk_context_t* _ctx) {
  struct kk_model_dash_resources__mlift3185_logistic__regression_fun4798__t* _self = kk_function_as(struct kk_model_dash_resources__mlift3185_logistic__regression_fun4798__t*, _fself);
  double b = _self->b; /* double */
  double m = _self->m; /* double */
  double sigma = _self->sigma; /* double */
  kk_drop_match(_self, {;;;}, {}, _ctx)
  kk_unit_t _x4799 = kk_Unit;
  kk_std_core_types__tuple2_ _match_4458 = kk_std_core_types__tuple2__unbox(_b_4048, _ctx); /*(double, bool)*/;
  kk_box_t _box_x4023 = _match_4458.fst;
  kk_box_t _box_x4024 = _match_4458.snd;
  double x1 = kk_double_unbox(_box_x4023, NULL);
  bool label = kk_bool_unbox(_box_x4024);
  kk_std_core_types__tuple2__drop(_match_4458, _ctx);
  double x0_3325;
  size_t i_3327 = ((size_t)0); /*std/core/hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_3327,kk_context()); /*std/core/hnd/evv<<effects-and-types/sample,effects-and-types/score>>*/;
  double y;
  double _x4802;
  double _x4803;
  double _x4804;
  double mean_3331;
  double _x4805 = (m * x1); /*double*/
  mean_3331 = (_x4805 + b); /*double*/
  double x3_3333 = kk_model_dash_resources_standard_normal(_ctx); /*double*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x4806 = kk_std_core_hnd_yield_extend(kk_model_dash_resources__new_mlift3185_logistic__regression_fun4807(mean_3331, sigma, _ctx), _ctx); /*2*/
    _x4804 = kk_double_unbox(_x4806, _ctx); /*double*/
  }
  else {
    double _x4810 = (x3_3333 * sigma); /*double*/
    _x4804 = (mean_3331 + _x4810); /*double*/
  }
  _x4803 = pow((0x1.5bf0a8b145769p1),_x4804); /*double*/
  _x4802 = (0x1p0 + _x4803); /*double*/
  y = (0x1p0 / _x4802); /*double*/
  kk_unit_t __w_l700_c9 = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x4811 = kk_std_core_hnd_yield_cont(kk_model_dash_resources__new_mlift3185_logistic__regression_fun4812(i_3327, _ctx), _ctx); /*3*/
    x0_3325 = kk_double_unbox(_x4811, _ctx); /*double*/
  }
  else {
    x0_3325 = y; /*double*/
  }
  if (kk_yielding(kk_context())) {
    kk_box_t _x4813 = kk_std_core_hnd_yield_extend(kk_model_dash_resources__new_mlift3185_logistic__regression_fun4814(label, _ctx), _ctx); /*2*/
    kk_unit_unbox(_x4813);
  }
  else {
    kk_model_dash_resources__mlift3183_logistic__regression(label, x0_3325, _ctx);
  }
  return kk_unit_box(_x4799);
}


// lift anonymous function
struct kk_model_dash_resources__mlift3185_logistic__regression_fun4818__t {
  struct kk_function_s _base;
  double b;
  double m;
};
static kk_box_t kk_model_dash_resources__mlift3185_logistic__regression_fun4818(kk_function_t _fself, kk_box_t _b_4055, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources__new_mlift3185_logistic__regression_fun4818(double b, double m, kk_context_t* _ctx) {
  struct kk_model_dash_resources__mlift3185_logistic__regression_fun4818__t* _self = kk_function_alloc_as(struct kk_model_dash_resources__mlift3185_logistic__regression_fun4818__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_model_dash_resources__mlift3185_logistic__regression_fun4818, kk_context());
  _self->b = b;
  _self->m = m;
  return &_self->_base;
}

static kk_box_t kk_model_dash_resources__mlift3185_logistic__regression_fun4818(kk_function_t _fself, kk_box_t _b_4055, kk_context_t* _ctx) {
  struct kk_model_dash_resources__mlift3185_logistic__regression_fun4818__t* _self = kk_function_as(struct kk_model_dash_resources__mlift3185_logistic__regression_fun4818__t*, _fself);
  double b = _self->b; /* double */
  double m = _self->m; /* double */
  kk_drop_match(_self, {;;}, {}, _ctx)
  kk_std_core_types__tuple2_ _x4819;
  kk_std_core__list _x4820 = kk_std_core__list_unbox(_b_4055, _ctx); /*list<()>*/
  _x4819 = kk_model_dash_resources__mlift3184_logistic__regression(b, m, _x4820, _ctx); /*(double, double)*/
  return kk_std_core_types__tuple2__box(_x4819, _ctx);
}

kk_std_core_types__tuple2_ kk_model_dash_resources__mlift3185_logistic__regression(double b, kk_std_core__list dat, double m, double sigma, kk_context_t* _ctx) { /* (b : double, dat : list<(double, bool)>, m : double, sigma : double) -> <div,effects-and-types/sample,effects-and-types/score> (double, double) */ 
  kk_std_core__list x_3323 = kk_std_core_map_5(dat, kk_model_dash_resources__new_mlift3185_logistic__regression_fun4798(b, m, sigma, _ctx), _ctx); /*list<()>*/;
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_3323, _ctx);
    kk_box_t _x4817 = kk_std_core_hnd_yield_extend(kk_model_dash_resources__new_mlift3185_logistic__regression_fun4818(b, m, _ctx), _ctx); /*2*/
    return kk_std_core_types__tuple2__unbox(_x4817, _ctx);
  }
  return kk_model_dash_resources__mlift3184_logistic__regression(b, m, x_3323, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_model_dash_resources__mlift3186_logistic__regression_fun4822__t {
  struct kk_function_s _base;
  size_t i_3339;
};
static kk_box_t kk_model_dash_resources__mlift3186_logistic__regression_fun4822(kk_function_t _fself, kk_function_t _b_4063, kk_box_t _b_4064, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources__new_mlift3186_logistic__regression_fun4822(size_t i_3339, kk_context_t* _ctx) {
  struct kk_model_dash_resources__mlift3186_logistic__regression_fun4822__t* _self = kk_function_alloc_as(struct kk_model_dash_resources__mlift3186_logistic__regression_fun4822__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_model_dash_resources__mlift3186_logistic__regression_fun4822, kk_context());
  _self->i_3339 = i_3339;
  return &_self->_base;
}

static kk_box_t kk_model_dash_resources__mlift3186_logistic__regression_fun4822(kk_function_t _fself, kk_function_t _b_4063, kk_box_t _b_4064, kk_context_t* _ctx) {
  struct kk_model_dash_resources__mlift3186_logistic__regression_fun4822__t* _self = kk_function_as(struct kk_model_dash_resources__mlift3186_logistic__regression_fun4822__t*, _fself);
  size_t i_3339 = _self->i_3339; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_3339, _b_4063, _b_4064, _ctx);
}


// lift anonymous function
struct kk_model_dash_resources__mlift3186_logistic__regression_fun4824__t {
  struct kk_function_s _base;
  kk_std_core__list dat;
  double b;
  double m;
};
static kk_box_t kk_model_dash_resources__mlift3186_logistic__regression_fun4824(kk_function_t _fself, kk_box_t _b_4074, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources__new_mlift3186_logistic__regression_fun4824(kk_std_core__list dat, double b, double m, kk_context_t* _ctx) {
  struct kk_model_dash_resources__mlift3186_logistic__regression_fun4824__t* _self = kk_function_alloc_as(struct kk_model_dash_resources__mlift3186_logistic__regression_fun4824__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_model_dash_resources__mlift3186_logistic__regression_fun4824, kk_context());
  _self->dat = dat;
  _self->b = b;
  _self->m = m;
  return &_self->_base;
}

static kk_box_t kk_model_dash_resources__mlift3186_logistic__regression_fun4824(kk_function_t _fself, kk_box_t _b_4074, kk_context_t* _ctx) {
  struct kk_model_dash_resources__mlift3186_logistic__regression_fun4824__t* _self = kk_function_as(struct kk_model_dash_resources__mlift3186_logistic__regression_fun4824__t*, _fself);
  kk_std_core__list dat = _self->dat; /* list<(double, bool)> */
  double b = _self->b; /* double */
  double m = _self->m; /* double */
  kk_drop_match(_self, {kk_std_core__list_dup(dat);;;}, {}, _ctx)
  kk_std_core_types__tuple2_ _x4825;
  double _x4826 = kk_double_unbox(_b_4074, _ctx); /*double*/
  _x4825 = kk_model_dash_resources__mlift3185_logistic__regression(b, dat, m, _x4826, _ctx); /*(double, double)*/
  return kk_std_core_types__tuple2__box(_x4825, _ctx);
}

kk_std_core_types__tuple2_ kk_model_dash_resources__mlift3186_logistic__regression(kk_std_core__list dat, double m, double b, kk_context_t* _ctx) { /* (dat : list<(double, bool)>, m : double, b : double) -> <effects-and-types/sample,div,effects-and-types/score> (double, double) */ 
  double x_3337;
  size_t i_3339 = ((size_t)0); /*std/core/hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_3339,kk_context()); /*std/core/hnd/evv<<div,effects-and-types/sample,effects-and-types/score>>*/;
  double y = kk_model_dash_resources_grand(0x0p+0, 0x1p0, _ctx); /*double*/;
  kk_unit_t __w_l717_c9 = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x4821 = kk_std_core_hnd_yield_cont(kk_model_dash_resources__new_mlift3186_logistic__regression_fun4822(i_3339, _ctx), _ctx); /*3*/
    x_3337 = kk_double_unbox(_x4821, _ctx); /*double*/
  }
  else {
    x_3337 = y; /*double*/
  }
  if (kk_yielding(kk_context())) {
    kk_box_t _x4823 = kk_std_core_hnd_yield_extend(kk_model_dash_resources__new_mlift3186_logistic__regression_fun4824(dat, b, m, _ctx), _ctx); /*2*/
    return kk_std_core_types__tuple2__unbox(_x4823, _ctx);
  }
  return kk_model_dash_resources__mlift3185_logistic__regression(b, dat, m, x_3337, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_model_dash_resources__mlift3187_logistic__regression_fun4828__t {
  struct kk_function_s _base;
};
static kk_box_t kk_model_dash_resources__mlift3187_logistic__regression_fun4828(kk_function_t _fself, kk_box_t _b_4078, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources__new_mlift3187_logistic__regression_fun4828(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_model_dash_resources__mlift3187_logistic__regression_fun4828, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_model_dash_resources__mlift3187_logistic__regression_fun4828(kk_function_t _fself, kk_box_t _b_4078, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x4829;
  double _x4830 = kk_double_unbox(_b_4078, _ctx); /*double*/
  _x4829 = kk_model_dash_resources__mlift3175_normal(0x0p+0, 0x1p0, _x4830, _ctx); /*double*/
  return kk_double_box(_x4829, _ctx);
}


// lift anonymous function
struct kk_model_dash_resources__mlift3187_logistic__regression_fun4833__t {
  struct kk_function_s _base;
  size_t i_3345;
};
static kk_box_t kk_model_dash_resources__mlift3187_logistic__regression_fun4833(kk_function_t _fself, kk_function_t _b_4086, kk_box_t _b_4087, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources__new_mlift3187_logistic__regression_fun4833(size_t i_3345, kk_context_t* _ctx) {
  struct kk_model_dash_resources__mlift3187_logistic__regression_fun4833__t* _self = kk_function_alloc_as(struct kk_model_dash_resources__mlift3187_logistic__regression_fun4833__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_model_dash_resources__mlift3187_logistic__regression_fun4833, kk_context());
  _self->i_3345 = i_3345;
  return &_self->_base;
}

static kk_box_t kk_model_dash_resources__mlift3187_logistic__regression_fun4833(kk_function_t _fself, kk_function_t _b_4086, kk_box_t _b_4087, kk_context_t* _ctx) {
  struct kk_model_dash_resources__mlift3187_logistic__regression_fun4833__t* _self = kk_function_as(struct kk_model_dash_resources__mlift3187_logistic__regression_fun4833__t*, _fself);
  size_t i_3345 = _self->i_3345; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_3345, _b_4086, _b_4087, _ctx);
}


// lift anonymous function
struct kk_model_dash_resources__mlift3187_logistic__regression_fun4835__t {
  struct kk_function_s _base;
  kk_std_core__list dat;
  double m;
};
static kk_box_t kk_model_dash_resources__mlift3187_logistic__regression_fun4835(kk_function_t _fself, kk_box_t _b_4097, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources__new_mlift3187_logistic__regression_fun4835(kk_std_core__list dat, double m, kk_context_t* _ctx) {
  struct kk_model_dash_resources__mlift3187_logistic__regression_fun4835__t* _self = kk_function_alloc_as(struct kk_model_dash_resources__mlift3187_logistic__regression_fun4835__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_model_dash_resources__mlift3187_logistic__regression_fun4835, kk_context());
  _self->dat = dat;
  _self->m = m;
  return &_self->_base;
}

static kk_box_t kk_model_dash_resources__mlift3187_logistic__regression_fun4835(kk_function_t _fself, kk_box_t _b_4097, kk_context_t* _ctx) {
  struct kk_model_dash_resources__mlift3187_logistic__regression_fun4835__t* _self = kk_function_as(struct kk_model_dash_resources__mlift3187_logistic__regression_fun4835__t*, _fself);
  kk_std_core__list dat = _self->dat; /* list<(double, bool)> */
  double m = _self->m; /* double */
  kk_drop_match(_self, {kk_std_core__list_dup(dat);;}, {}, _ctx)
  kk_std_core_types__tuple2_ _x4836;
  double _x4837 = kk_double_unbox(_b_4097, _ctx); /*double*/
  _x4836 = kk_model_dash_resources__mlift3186_logistic__regression(dat, m, _x4837, _ctx); /*(double, double)*/
  return kk_std_core_types__tuple2__box(_x4836, _ctx);
}

kk_std_core_types__tuple2_ kk_model_dash_resources__mlift3187_logistic__regression(kk_std_core__list dat, double m, kk_context_t* _ctx) { /* (dat : list<(double, bool)>, m : double) -> <effects-and-types/sample,div,effects-and-types/score> (double, double) */ 
  double x_3343;
  size_t i_3345 = ((size_t)0); /*std/core/hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_3345,kk_context()); /*std/core/hnd/evv<<effects-and-types/sample,div,effects-and-types/score>>*/;
  double y;
  double x_3267 = kk_model_dash_resources_standard_normal(_ctx); /*double*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x4827 = kk_std_core_hnd_yield_extend(kk_model_dash_resources__new_mlift3187_logistic__regression_fun4828(_ctx), _ctx); /*2*/
    y = kk_double_unbox(_x4827, _ctx); /*double*/
  }
  else {
    double _x4831 = (x_3267 * 0x1p0); /*double*/
    y = ((0x0p+0) + _x4831); /*double*/
  }
  kk_unit_t __w_l717_c9 = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x4832 = kk_std_core_hnd_yield_cont(kk_model_dash_resources__new_mlift3187_logistic__regression_fun4833(i_3345, _ctx), _ctx); /*3*/
    x_3343 = kk_double_unbox(_x4832, _ctx); /*double*/
  }
  else {
    x_3343 = y; /*double*/
  }
  if (kk_yielding(kk_context())) {
    kk_box_t _x4834 = kk_std_core_hnd_yield_extend(kk_model_dash_resources__new_mlift3187_logistic__regression_fun4835(dat, m, _ctx), _ctx); /*2*/
    return kk_std_core_types__tuple2__unbox(_x4834, _ctx);
  }
  return kk_model_dash_resources__mlift3186_logistic__regression(dat, m, x_3343, _ctx);
}


// lift anonymous function
struct kk_model_dash_resources_logistic__regression_fun4838__t {
  struct kk_function_s _base;
  kk_std_core__list dat;
};
static kk_std_core_types__tuple2_ kk_model_dash_resources_logistic__regression_fun4838(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources_new_logistic__regression_fun4838(kk_std_core__list dat, kk_context_t* _ctx) {
  struct kk_model_dash_resources_logistic__regression_fun4838__t* _self = kk_function_alloc_as(struct kk_model_dash_resources_logistic__regression_fun4838__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_model_dash_resources_logistic__regression_fun4838, kk_context());
  _self->dat = dat;
  return &_self->_base;
}



// lift anonymous function
struct kk_model_dash_resources_logistic__regression_fun4840__t {
  struct kk_function_s _base;
};
static kk_box_t kk_model_dash_resources_logistic__regression_fun4840(kk_function_t _fself, kk_box_t _b_4101, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources_new_logistic__regression_fun4840(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_model_dash_resources_logistic__regression_fun4840, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_model_dash_resources_logistic__regression_fun4840(kk_function_t _fself, kk_box_t _b_4101, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x4841;
  double _x4842 = kk_double_unbox(_b_4101, _ctx); /*double*/
  _x4841 = kk_model_dash_resources__mlift3175_normal(0x0p+0, 0x1p0, _x4842, _ctx); /*double*/
  return kk_double_box(_x4841, _ctx);
}


// lift anonymous function
struct kk_model_dash_resources_logistic__regression_fun4845__t {
  struct kk_function_s _base;
  size_t i_3352;
};
static kk_box_t kk_model_dash_resources_logistic__regression_fun4845(kk_function_t _fself, kk_function_t _b_4109, kk_box_t _b_4110, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources_new_logistic__regression_fun4845(size_t i_3352, kk_context_t* _ctx) {
  struct kk_model_dash_resources_logistic__regression_fun4845__t* _self = kk_function_alloc_as(struct kk_model_dash_resources_logistic__regression_fun4845__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_model_dash_resources_logistic__regression_fun4845, kk_context());
  _self->i_3352 = i_3352;
  return &_self->_base;
}

static kk_box_t kk_model_dash_resources_logistic__regression_fun4845(kk_function_t _fself, kk_function_t _b_4109, kk_box_t _b_4110, kk_context_t* _ctx) {
  struct kk_model_dash_resources_logistic__regression_fun4845__t* _self = kk_function_as(struct kk_model_dash_resources_logistic__regression_fun4845__t*, _fself);
  size_t i_3352 = _self->i_3352; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_3352, _b_4109, _b_4110, _ctx);
}


// lift anonymous function
struct kk_model_dash_resources_logistic__regression_fun4847__t {
  struct kk_function_s _base;
  kk_std_core__list dat;
};
static kk_box_t kk_model_dash_resources_logistic__regression_fun4847(kk_function_t _fself, kk_box_t _b_4120, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources_new_logistic__regression_fun4847(kk_std_core__list dat, kk_context_t* _ctx) {
  struct kk_model_dash_resources_logistic__regression_fun4847__t* _self = kk_function_alloc_as(struct kk_model_dash_resources_logistic__regression_fun4847__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_model_dash_resources_logistic__regression_fun4847, kk_context());
  _self->dat = dat;
  return &_self->_base;
}

static kk_box_t kk_model_dash_resources_logistic__regression_fun4847(kk_function_t _fself, kk_box_t _b_4120, kk_context_t* _ctx) {
  struct kk_model_dash_resources_logistic__regression_fun4847__t* _self = kk_function_as(struct kk_model_dash_resources_logistic__regression_fun4847__t*, _fself);
  kk_std_core__list dat = _self->dat; /* list<(double, bool)> */
  kk_drop_match(_self, {kk_std_core__list_dup(dat);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x4848;
  double _x4849 = kk_double_unbox(_b_4120, _ctx); /*double*/
  _x4848 = kk_model_dash_resources__mlift3187_logistic__regression(dat, _x4849, _ctx); /*(double, double)*/
  return kk_std_core_types__tuple2__box(_x4848, _ctx);
}


// lift anonymous function
struct kk_model_dash_resources_logistic__regression_fun4851__t {
  struct kk_function_s _base;
};
static kk_box_t kk_model_dash_resources_logistic__regression_fun4851(kk_function_t _fself, kk_box_t _b_4122, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources_new_logistic__regression_fun4851(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_model_dash_resources_logistic__regression_fun4851, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_model_dash_resources_logistic__regression_fun4851(kk_function_t _fself, kk_box_t _b_4122, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x4852;
  double _x4853 = kk_double_unbox(_b_4122, _ctx); /*double*/
  _x4852 = kk_model_dash_resources__mlift3175_normal(0x0p+0, 0x1p0, _x4853, _ctx); /*double*/
  return kk_double_box(_x4852, _ctx);
}


// lift anonymous function
struct kk_model_dash_resources_logistic__regression_fun4856__t {
  struct kk_function_s _base;
  size_t i0_3360;
};
static kk_box_t kk_model_dash_resources_logistic__regression_fun4856(kk_function_t _fself, kk_function_t _b_4130, kk_box_t _b_4131, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources_new_logistic__regression_fun4856(size_t i0_3360, kk_context_t* _ctx) {
  struct kk_model_dash_resources_logistic__regression_fun4856__t* _self = kk_function_alloc_as(struct kk_model_dash_resources_logistic__regression_fun4856__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_model_dash_resources_logistic__regression_fun4856, kk_context());
  _self->i0_3360 = i0_3360;
  return &_self->_base;
}

static kk_box_t kk_model_dash_resources_logistic__regression_fun4856(kk_function_t _fself, kk_function_t _b_4130, kk_box_t _b_4131, kk_context_t* _ctx) {
  struct kk_model_dash_resources_logistic__regression_fun4856__t* _self = kk_function_as(struct kk_model_dash_resources_logistic__regression_fun4856__t*, _fself);
  size_t i0_3360 = _self->i0_3360; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i0_3360, _b_4130, _b_4131, _ctx);
}


// lift anonymous function
struct kk_model_dash_resources_logistic__regression_fun4858__t {
  struct kk_function_s _base;
  kk_std_core__list dat;
  double x_3349;
};
static kk_box_t kk_model_dash_resources_logistic__regression_fun4858(kk_function_t _fself, kk_box_t _b_4141, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources_new_logistic__regression_fun4858(kk_std_core__list dat, double x_3349, kk_context_t* _ctx) {
  struct kk_model_dash_resources_logistic__regression_fun4858__t* _self = kk_function_alloc_as(struct kk_model_dash_resources_logistic__regression_fun4858__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_model_dash_resources_logistic__regression_fun4858, kk_context());
  _self->dat = dat;
  _self->x_3349 = x_3349;
  return &_self->_base;
}

static kk_box_t kk_model_dash_resources_logistic__regression_fun4858(kk_function_t _fself, kk_box_t _b_4141, kk_context_t* _ctx) {
  struct kk_model_dash_resources_logistic__regression_fun4858__t* _self = kk_function_as(struct kk_model_dash_resources_logistic__regression_fun4858__t*, _fself);
  kk_std_core__list dat = _self->dat; /* list<(double, bool)> */
  double x_3349 = _self->x_3349; /* double */
  kk_drop_match(_self, {kk_std_core__list_dup(dat);;}, {}, _ctx)
  kk_std_core_types__tuple2_ _x4859;
  double _x4860 = kk_double_unbox(_b_4141, _ctx); /*double*/
  _x4859 = kk_model_dash_resources__mlift3186_logistic__regression(dat, x_3349, _x4860, _ctx); /*(double, double)*/
  return kk_std_core_types__tuple2__box(_x4859, _ctx);
}


// lift anonymous function
struct kk_model_dash_resources_logistic__regression_fun4862__t {
  struct kk_function_s _base;
  size_t i1_3368;
};
static kk_box_t kk_model_dash_resources_logistic__regression_fun4862(kk_function_t _fself, kk_function_t _b_4147, kk_box_t _b_4148, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources_new_logistic__regression_fun4862(size_t i1_3368, kk_context_t* _ctx) {
  struct kk_model_dash_resources_logistic__regression_fun4862__t* _self = kk_function_alloc_as(struct kk_model_dash_resources_logistic__regression_fun4862__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_model_dash_resources_logistic__regression_fun4862, kk_context());
  _self->i1_3368 = i1_3368;
  return &_self->_base;
}

static kk_box_t kk_model_dash_resources_logistic__regression_fun4862(kk_function_t _fself, kk_function_t _b_4147, kk_box_t _b_4148, kk_context_t* _ctx) {
  struct kk_model_dash_resources_logistic__regression_fun4862__t* _self = kk_function_as(struct kk_model_dash_resources_logistic__regression_fun4862__t*, _fself);
  size_t i1_3368 = _self->i1_3368; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i1_3368, _b_4147, _b_4148, _ctx);
}


// lift anonymous function
struct kk_model_dash_resources_logistic__regression_fun4864__t {
  struct kk_function_s _base;
  kk_std_core__list dat;
  double x_3349;
  double x0_3357;
};
static kk_box_t kk_model_dash_resources_logistic__regression_fun4864(kk_function_t _fself, kk_box_t _b_4158, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources_new_logistic__regression_fun4864(kk_std_core__list dat, double x_3349, double x0_3357, kk_context_t* _ctx) {
  struct kk_model_dash_resources_logistic__regression_fun4864__t* _self = kk_function_alloc_as(struct kk_model_dash_resources_logistic__regression_fun4864__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_model_dash_resources_logistic__regression_fun4864, kk_context());
  _self->dat = dat;
  _self->x_3349 = x_3349;
  _self->x0_3357 = x0_3357;
  return &_self->_base;
}

static kk_box_t kk_model_dash_resources_logistic__regression_fun4864(kk_function_t _fself, kk_box_t _b_4158, kk_context_t* _ctx) {
  struct kk_model_dash_resources_logistic__regression_fun4864__t* _self = kk_function_as(struct kk_model_dash_resources_logistic__regression_fun4864__t*, _fself);
  kk_std_core__list dat = _self->dat; /* list<(double, bool)> */
  double x_3349 = _self->x_3349; /* double */
  double x0_3357 = _self->x0_3357; /* double */
  kk_drop_match(_self, {kk_std_core__list_dup(dat);;;}, {}, _ctx)
  kk_std_core_types__tuple2_ _x4865;
  double _x4866 = kk_double_unbox(_b_4158, _ctx); /*double*/
  _x4865 = kk_model_dash_resources__mlift3185_logistic__regression(x0_3357, dat, x_3349, _x4866, _ctx); /*(double, double)*/
  return kk_std_core_types__tuple2__box(_x4865, _ctx);
}


// lift anonymous function
struct kk_model_dash_resources_logistic__regression_fun4867__t {
  struct kk_function_s _base;
  double x_3349;
  double x0_3357;
  double x3_3365;
};
static kk_box_t kk_model_dash_resources_logistic__regression_fun4867(kk_function_t _fself, kk_box_t _b_4184, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources_new_logistic__regression_fun4867(double x_3349, double x0_3357, double x3_3365, kk_context_t* _ctx) {
  struct kk_model_dash_resources_logistic__regression_fun4867__t* _self = kk_function_alloc_as(struct kk_model_dash_resources_logistic__regression_fun4867__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_model_dash_resources_logistic__regression_fun4867, kk_context());
  _self->x_3349 = x_3349;
  _self->x0_3357 = x0_3357;
  _self->x3_3365 = x3_3365;
  return &_self->_base;
}



// lift anonymous function
struct kk_model_dash_resources_logistic__regression_fun4876__t {
  struct kk_function_s _base;
  double mean_3382;
  double x3_3365;
};
static kk_box_t kk_model_dash_resources_logistic__regression_fun4876(kk_function_t _fself, kk_box_t _b_4162, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources_new_logistic__regression_fun4876(double mean_3382, double x3_3365, kk_context_t* _ctx) {
  struct kk_model_dash_resources_logistic__regression_fun4876__t* _self = kk_function_alloc_as(struct kk_model_dash_resources_logistic__regression_fun4876__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_model_dash_resources_logistic__regression_fun4876, kk_context());
  _self->mean_3382 = mean_3382;
  _self->x3_3365 = x3_3365;
  return &_self->_base;
}

static kk_box_t kk_model_dash_resources_logistic__regression_fun4876(kk_function_t _fself, kk_box_t _b_4162, kk_context_t* _ctx) {
  struct kk_model_dash_resources_logistic__regression_fun4876__t* _self = kk_function_as(struct kk_model_dash_resources_logistic__regression_fun4876__t*, _fself);
  double mean_3382 = _self->mean_3382; /* double */
  double x3_3365 = _self->x3_3365; /* double */
  kk_drop_match(_self, {;;}, {}, _ctx)
  double _x4877;
  double _x4878 = kk_double_unbox(_b_4162, _ctx); /*double*/
  _x4877 = kk_model_dash_resources__mlift3175_normal(mean_3382, x3_3365, _x4878, _ctx); /*double*/
  return kk_double_box(_x4877, _ctx);
}


// lift anonymous function
struct kk_model_dash_resources_logistic__regression_fun4881__t {
  struct kk_function_s _base;
  size_t i2_3378;
};
static kk_box_t kk_model_dash_resources_logistic__regression_fun4881(kk_function_t _fself, kk_function_t _b_4170, kk_box_t _b_4171, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources_new_logistic__regression_fun4881(size_t i2_3378, kk_context_t* _ctx) {
  struct kk_model_dash_resources_logistic__regression_fun4881__t* _self = kk_function_alloc_as(struct kk_model_dash_resources_logistic__regression_fun4881__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_model_dash_resources_logistic__regression_fun4881, kk_context());
  _self->i2_3378 = i2_3378;
  return &_self->_base;
}

static kk_box_t kk_model_dash_resources_logistic__regression_fun4881(kk_function_t _fself, kk_function_t _b_4170, kk_box_t _b_4171, kk_context_t* _ctx) {
  struct kk_model_dash_resources_logistic__regression_fun4881__t* _self = kk_function_as(struct kk_model_dash_resources_logistic__regression_fun4881__t*, _fself);
  size_t i2_3378 = _self->i2_3378; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i2_3378, _b_4170, _b_4171, _ctx);
}


// lift anonymous function
struct kk_model_dash_resources_logistic__regression_fun4883__t {
  struct kk_function_s _base;
  bool label;
};
static kk_box_t kk_model_dash_resources_logistic__regression_fun4883(kk_function_t _fself, kk_box_t _b_4181, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources_new_logistic__regression_fun4883(bool label, kk_context_t* _ctx) {
  struct kk_model_dash_resources_logistic__regression_fun4883__t* _self = kk_function_alloc_as(struct kk_model_dash_resources_logistic__regression_fun4883__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_model_dash_resources_logistic__regression_fun4883, kk_context());
  _self->label = label;
  return &_self->_base;
}

static kk_box_t kk_model_dash_resources_logistic__regression_fun4883(kk_function_t _fself, kk_box_t _b_4181, kk_context_t* _ctx) {
  struct kk_model_dash_resources_logistic__regression_fun4883__t* _self = kk_function_as(struct kk_model_dash_resources_logistic__regression_fun4883__t*, _fself);
  bool label = _self->label; /* bool */
  kk_drop_match(_self, {;}, {}, _ctx)
  kk_unit_t _x4884 = kk_Unit;
  double _x4885 = kk_double_unbox(_b_4181, _ctx); /*double*/
  kk_model_dash_resources__mlift3183_logistic__regression(label, _x4885, _ctx);
  return kk_unit_box(_x4884);
}
static kk_box_t kk_model_dash_resources_logistic__regression_fun4867(kk_function_t _fself, kk_box_t _b_4184, kk_context_t* _ctx) {
  struct kk_model_dash_resources_logistic__regression_fun4867__t* _self = kk_function_as(struct kk_model_dash_resources_logistic__regression_fun4867__t*, _fself);
  double x_3349 = _self->x_3349; /* double */
  double x0_3357 = _self->x0_3357; /* double */
  double x3_3365 = _self->x3_3365; /* double */
  kk_drop_match(_self, {;;;}, {}, _ctx)
  kk_unit_t _x4868 = kk_Unit;
  kk_std_core_types__tuple2_ _match_4443 = kk_std_core_types__tuple2__unbox(_b_4184, _ctx); /*(double, bool)*/;
  kk_box_t _box_x4159 = _match_4443.fst;
  kk_box_t _box_x4160 = _match_4443.snd;
  double x12 = kk_double_unbox(_box_x4159, NULL);
  bool label = kk_bool_unbox(_box_x4160);
  kk_std_core_types__tuple2__drop(_match_4443, _ctx);
  double x5_3376;
  size_t i2_3378 = ((size_t)0); /*std/core/hnd/ev-index*/;
  kk_evv_t w2 = kk_evv_swap_create1(i2_3378,kk_context()); /*std/core/hnd/evv<<effects-and-types/sample,effects-and-types/score>>*/;
  double y2;
  double _x4871;
  double _x4872;
  double _x4873;
  double mean_3382;
  double _x4874 = (x_3349 * x12); /*double*/
  mean_3382 = (_x4874 + x0_3357); /*double*/
  double x7_3384 = kk_model_dash_resources_standard_normal(_ctx); /*double*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x4875 = kk_std_core_hnd_yield_extend(kk_model_dash_resources_new_logistic__regression_fun4876(mean_3382, x3_3365, _ctx), _ctx); /*2*/
    _x4873 = kk_double_unbox(_x4875, _ctx); /*double*/
  }
  else {
    double _x4879 = (x7_3384 * x3_3365); /*double*/
    _x4873 = (mean_3382 + _x4879); /*double*/
  }
  _x4872 = pow((0x1.5bf0a8b145769p1),_x4873); /*double*/
  _x4871 = (0x1p0 + _x4872); /*double*/
  y2 = (0x1p0 / _x4871); /*double*/
  kk_unit_t __w_l700_c9 = kk_Unit;
  kk_evv_set(w2,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x4880 = kk_std_core_hnd_yield_cont(kk_model_dash_resources_new_logistic__regression_fun4881(i2_3378, _ctx), _ctx); /*3*/
    x5_3376 = kk_double_unbox(_x4880, _ctx); /*double*/
  }
  else {
    x5_3376 = y2; /*double*/
  }
  if (kk_yielding(kk_context())) {
    kk_box_t _x4882 = kk_std_core_hnd_yield_extend(kk_model_dash_resources_new_logistic__regression_fun4883(label, _ctx), _ctx); /*2*/
    kk_unit_unbox(_x4882);
  }
  else {
    kk_model_dash_resources__mlift3183_logistic__regression(label, x5_3376, _ctx);
  }
  return kk_unit_box(_x4868);
}


// lift anonymous function
struct kk_model_dash_resources_logistic__regression_fun4887__t {
  struct kk_function_s _base;
  double x_3349;
  double x0_3357;
};
static kk_box_t kk_model_dash_resources_logistic__regression_fun4887(kk_function_t _fself, kk_box_t _b_4191, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources_new_logistic__regression_fun4887(double x_3349, double x0_3357, kk_context_t* _ctx) {
  struct kk_model_dash_resources_logistic__regression_fun4887__t* _self = kk_function_alloc_as(struct kk_model_dash_resources_logistic__regression_fun4887__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_model_dash_resources_logistic__regression_fun4887, kk_context());
  _self->x_3349 = x_3349;
  _self->x0_3357 = x0_3357;
  return &_self->_base;
}

static kk_box_t kk_model_dash_resources_logistic__regression_fun4887(kk_function_t _fself, kk_box_t _b_4191, kk_context_t* _ctx) {
  struct kk_model_dash_resources_logistic__regression_fun4887__t* _self = kk_function_as(struct kk_model_dash_resources_logistic__regression_fun4887__t*, _fself);
  double x_3349 = _self->x_3349; /* double */
  double x0_3357 = _self->x0_3357; /* double */
  kk_drop_match(_self, {;;}, {}, _ctx)
  kk_std_core_types__tuple2_ _x4888;
  kk_std_core__list _x4889 = kk_std_core__list_unbox(_b_4191, _ctx); /*list<()>*/
  _x4888 = kk_model_dash_resources__mlift3184_logistic__regression(x0_3357, x_3349, _x4889, _ctx); /*(double, double)*/
  return kk_std_core_types__tuple2__box(_x4888, _ctx);
}
static kk_std_core_types__tuple2_ kk_model_dash_resources_logistic__regression_fun4838(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_model_dash_resources_logistic__regression_fun4838__t* _self = kk_function_as(struct kk_model_dash_resources_logistic__regression_fun4838__t*, _fself);
  kk_std_core__list dat = _self->dat; /* list<(double, bool)> */
  kk_drop_match(_self, {kk_std_core__list_dup(dat);}, {}, _ctx)
  double x_3349;
  size_t i_3352 = ((size_t)0); /*std/core/hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_3352,kk_context()); /*std/core/hnd/evv<<effects-and-types/sample,div,effects-and-types/score>>*/;
  double y;
  double x_3267 = kk_model_dash_resources_standard_normal(_ctx); /*double*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x4839 = kk_std_core_hnd_yield_extend(kk_model_dash_resources_new_logistic__regression_fun4840(_ctx), _ctx); /*2*/
    y = kk_double_unbox(_x4839, _ctx); /*double*/
  }
  else {
    double _x4843 = (x_3267 * 0x1p0); /*double*/
    y = ((0x0p+0) + _x4843); /*double*/
  }
  kk_unit_t __w_l717_c9 = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x4844 = kk_std_core_hnd_yield_cont(kk_model_dash_resources_new_logistic__regression_fun4845(i_3352, _ctx), _ctx); /*3*/
    x_3349 = kk_double_unbox(_x4844, _ctx); /*double*/
  }
  else {
    x_3349 = y; /*double*/
  }
  if (kk_yielding(kk_context())) {
    kk_box_t _x4846 = kk_std_core_hnd_yield_extend(kk_model_dash_resources_new_logistic__regression_fun4847(dat, _ctx), _ctx); /*2*/
    return kk_std_core_types__tuple2__unbox(_x4846, _ctx);
  }
  double x0_3357;
  size_t i0_3360 = ((size_t)0); /*std/core/hnd/ev-index*/;
  kk_evv_t w0 = kk_evv_swap_create1(i0_3360,kk_context()); /*std/core/hnd/evv<<effects-and-types/sample,div,effects-and-types/score>>*/;
  double y0;
  double x_32670 = kk_model_dash_resources_standard_normal(_ctx); /*double*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x4850 = kk_std_core_hnd_yield_extend(kk_model_dash_resources_new_logistic__regression_fun4851(_ctx), _ctx); /*2*/
    y0 = kk_double_unbox(_x4850, _ctx); /*double*/
  }
  else {
    double _x4854 = (x_32670 * 0x1p0); /*double*/
    y0 = ((0x0p+0) + _x4854); /*double*/
  }
  kk_unit_t __w_l717_c90 = kk_Unit;
  kk_evv_set(w0,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x4855 = kk_std_core_hnd_yield_cont(kk_model_dash_resources_new_logistic__regression_fun4856(i0_3360, _ctx), _ctx); /*3*/
    x0_3357 = kk_double_unbox(_x4855, _ctx); /*double*/
  }
  else {
    x0_3357 = y0; /*double*/
  }
  if (kk_yielding(kk_context())) {
    kk_box_t _x4857 = kk_std_core_hnd_yield_extend(kk_model_dash_resources_new_logistic__regression_fun4858(dat, x_3349, _ctx), _ctx); /*2*/
    return kk_std_core_types__tuple2__unbox(_x4857, _ctx);
  }
  double x3_3365;
  size_t i1_3368 = ((size_t)0); /*std/core/hnd/ev-index*/;
  kk_evv_t w1 = kk_evv_swap_create1(i1_3368,kk_context()); /*std/core/hnd/evv<<div,effects-and-types/sample,effects-and-types/score>>*/;
  double y1 = kk_model_dash_resources_grand(0x0p+0, 0x1p0, _ctx); /*double*/;
  kk_unit_t __w_l717_c91 = kk_Unit;
  kk_evv_set(w1,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x4861 = kk_std_core_hnd_yield_cont(kk_model_dash_resources_new_logistic__regression_fun4862(i1_3368, _ctx), _ctx); /*3*/
    x3_3365 = kk_double_unbox(_x4861, _ctx); /*double*/
  }
  else {
    x3_3365 = y1; /*double*/
  }
  if (kk_yielding(kk_context())) {
    kk_box_t _x4863 = kk_std_core_hnd_yield_extend(kk_model_dash_resources_new_logistic__regression_fun4864(dat, x_3349, x0_3357, _ctx), _ctx); /*2*/
    return kk_std_core_types__tuple2__unbox(_x4863, _ctx);
  }
  kk_std_core__list x4_3373 = kk_std_core_map_5(dat, kk_model_dash_resources_new_logistic__regression_fun4867(x_3349, x0_3357, x3_3365, _ctx), _ctx); /*list<()>*/;
  kk_std_core__list_drop(x4_3373, _ctx);
  if (kk_yielding(kk_context())) {
    kk_box_t _x4886 = kk_std_core_hnd_yield_extend(kk_model_dash_resources_new_logistic__regression_fun4887(x_3349, x0_3357, _ctx), _ctx); /*2*/
    return kk_std_core_types__tuple2__unbox(_x4886, _ctx);
  }
  return kk_std_core_types__new_dash__lp__comma__rp_(kk_double_box(x_3349, _ctx), kk_double_box(x0_3357, _ctx), _ctx);
}

kk_function_t kk_model_dash_resources_logistic__regression(kk_std_core__list dat, kk_context_t* _ctx) { /* (dat : list<(double, bool)>) -> effects-and-types/model<(double, double),div> */ 
  return kk_model_dash_resources_new_logistic__regression_fun4838(dat, _ctx);
}
extern double kk_model_dash_resources_params_fun4890(kk_function_t _fself, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return kk_model_dash_resources_grand(0x1p0, 0x1p0, _ctx);
}
 
// monadic lift

kk_std_core__list kk_model_dash_resources__mlift3188_op(kk_function_t obs, double s, double x, double x_sq_, kk_std_core__list xs, kk_std_core__list ys, kk_unit_t wild__, kk_context_t* _ctx) { /* (obs : (x : double, y : double) -> <std/num/random/random,effects-and-types/score> (), s : double, x : double, x' : double, xs : list<double>, ys : list<double>, wild_ : ()) -> <std/num/random/random,effects-and-types/score,effects-and-types/sample> list<double> */ 
  kk_std_core__list xss0_3145;
  kk_std_core__list xs0_3389;
  kk_std_core__list _b_4209_4207 = kk_std_core__new_Cons(kk_reuse_null, kk_double_box(x, _ctx), kk_std_core__new_Nil(_ctx), _ctx); /*list<double>*/;
  xs0_3389 = kk_std_core__new_Cons(kk_reuse_null, kk_double_box(x_sq_, _ctx), _b_4209_4207, _ctx); /*list<double>*/
  xss0_3145 = kk_std_core_append(xs0_3389, xs, _ctx); /*list<double>*/
  return kk_model_dash_resources__lift3144_random__walk(obs, s, xss0_3145, ys, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_model_dash_resources__mlift3189_op_fun4894__t {
  struct kk_function_s _base;
  kk_function_t obs0;
};
static kk_box_t kk_model_dash_resources__mlift3189_op_fun4894(kk_function_t _fself, kk_box_t _b_4220, kk_box_t _b_4221, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources__new_mlift3189_op_fun4894(kk_function_t obs0, kk_context_t* _ctx) {
  struct kk_model_dash_resources__mlift3189_op_fun4894__t* _self = kk_function_alloc_as(struct kk_model_dash_resources__mlift3189_op_fun4894__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_model_dash_resources__mlift3189_op_fun4894, kk_context());
  _self->obs0 = obs0;
  return &_self->_base;
}

static kk_box_t kk_model_dash_resources__mlift3189_op_fun4894(kk_function_t _fself, kk_box_t _b_4220, kk_box_t _b_4221, kk_context_t* _ctx) {
  struct kk_model_dash_resources__mlift3189_op_fun4894__t* _self = kk_function_as(struct kk_model_dash_resources__mlift3189_op_fun4894__t*, _fself);
  kk_function_t obs0 = _self->obs0; /* (x : double, y : double) -> <std/num/random/random,effects-and-types/score> () */
  kk_drop_match(_self, {kk_function_dup(obs0);}, {}, _ctx)
  kk_function_drop(obs0, _ctx);
  kk_unit_t _x4895 = kk_Unit;
  double _x4896 = kk_double_unbox(_b_4220, _ctx); /*double*/
  double _x4897 = kk_double_unbox(_b_4221, _ctx); /*double*/
  kk_function_call(kk_unit_t, (kk_function_t, double, double, kk_context_t*), obs0, (obs0, _x4896, _x4897, _ctx));
  return kk_unit_box(_x4895);
}


// lift anonymous function
struct kk_model_dash_resources__mlift3189_op_fun4899__t {
  struct kk_function_s _base;
  kk_function_t obs0;
  kk_std_core__list xs0;
  kk_std_core__list ys0;
  double s0;
  double x0;
  double x0_sq_;
};
static kk_box_t kk_model_dash_resources__mlift3189_op_fun4899(kk_function_t _fself, kk_box_t _b_4231, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources__new_mlift3189_op_fun4899(kk_function_t obs0, kk_std_core__list xs0, kk_std_core__list ys0, double s0, double x0, double x0_sq_, kk_context_t* _ctx) {
  struct kk_model_dash_resources__mlift3189_op_fun4899__t* _self = kk_function_alloc_as(struct kk_model_dash_resources__mlift3189_op_fun4899__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_model_dash_resources__mlift3189_op_fun4899, kk_context());
  _self->obs0 = obs0;
  _self->xs0 = xs0;
  _self->ys0 = ys0;
  _self->s0 = s0;
  _self->x0 = x0;
  _self->x0_sq_ = x0_sq_;
  return &_self->_base;
}

static kk_box_t kk_model_dash_resources__mlift3189_op_fun4899(kk_function_t _fself, kk_box_t _b_4231, kk_context_t* _ctx) {
  struct kk_model_dash_resources__mlift3189_op_fun4899__t* _self = kk_function_as(struct kk_model_dash_resources__mlift3189_op_fun4899__t*, _fself);
  kk_function_t obs0 = _self->obs0; /* (x : double, y : double) -> <std/num/random/random,effects-and-types/score> () */
  kk_std_core__list xs0 = _self->xs0; /* list<double> */
  kk_std_core__list ys0 = _self->ys0; /* list<double> */
  double s0 = _self->s0; /* double */
  double x0 = _self->x0; /* double */
  double x0_sq_ = _self->x0_sq_; /* double */
  kk_drop_match(_self, {kk_function_dup(obs0);kk_std_core__list_dup(xs0);kk_std_core__list_dup(ys0);;;;}, {}, _ctx)
  kk_std_core__list _x4900;
  kk_unit_t _x4901 = kk_Unit;
  kk_unit_unbox(_b_4231);
  _x4900 = kk_model_dash_resources__mlift3188_op(obs0, s0, x0, x0_sq_, xs0, ys0, _x4901, _ctx); /*list<double>*/
  return kk_std_core__list_box(_x4900, _ctx);
}

kk_std_core__list kk_model_dash_resources__mlift3189_op(kk_function_t obs0, double s0, double x0, kk_std_core__list xs0, double y, kk_std_core__list ys0, double x0_sq_, kk_context_t* _ctx) { /* (obs : (x : double, y : double) -> <std/num/random/random,effects-and-types/score> (), s : double, x : double, xs : list<double>, y : double, ys : list<double>, x' : double) -> <effects-and-types/sample,std/num/random/random,effects-and-types/score> list<double> */ 
  kk_unit_t x0_3391 = kk_Unit;
  kk_vector_t _b_4222_4216;
  kk_std_core__list _x4891;
  size_t _b_4226_4214 = ((size_t)0); /*std/core/hnd/ev-index*/;
  kk_std_core__list _b_4227_4215;
  size_t _b_4228_4212 = ((size_t)2); /*std/core/hnd/ev-index*/;
  _b_4227_4215 = kk_std_core__new_Cons(kk_reuse_null, kk_size_box(_b_4228_4212, _ctx), kk_std_core__new_Nil(_ctx), _ctx); /*list<std/core/hnd/ev-index>*/
  _x4891 = kk_std_core__new_Cons(kk_reuse_null, kk_size_box(_b_4226_4214, _ctx), _b_4227_4215, _ctx); /*list<0>*/
  _b_4222_4216 = kk_std_core_unvlist(_x4891, _ctx); /*vector<std/core/hnd/ev-index>*/
  kk_box_t _x4892;
  kk_function_t _x4893;
  kk_function_dup(obs0);
  _x4893 = kk_model_dash_resources__new_mlift3189_op_fun4894(obs0, _ctx); /*(1, 2) -> 4 3*/
  _x4892 = kk_std_core_hnd__open2(_b_4222_4216, _x4893, kk_double_box(x0_sq_, _ctx), kk_double_box(y, _ctx), _ctx); /*3*/
  kk_unit_unbox(_x4892);
  if (kk_yielding(kk_context())) {
    kk_box_t _x4898 = kk_std_core_hnd_yield_extend(kk_model_dash_resources__new_mlift3189_op_fun4899(obs0, xs0, ys0, s0, x0, x0_sq_, _ctx), _ctx); /*2*/
    return kk_std_core__list_unbox(_x4898, _ctx);
  }
  return kk_model_dash_resources__mlift3188_op(obs0, s0, x0, x0_sq_, xs0, ys0, x0_3391, _ctx);
}
 
// lift


// lift anonymous function
struct kk_model_dash_resources__lift3144_random__walk_fun4907__t {
  struct kk_function_s _base;
  size_t i_3396;
};
static kk_box_t kk_model_dash_resources__lift3144_random__walk_fun4907(kk_function_t _fself, kk_function_t _b_4241, kk_box_t _b_4242, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources__new_lift3144_random__walk_fun4907(size_t i_3396, kk_context_t* _ctx) {
  struct kk_model_dash_resources__lift3144_random__walk_fun4907__t* _self = kk_function_alloc_as(struct kk_model_dash_resources__lift3144_random__walk_fun4907__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_model_dash_resources__lift3144_random__walk_fun4907, kk_context());
  _self->i_3396 = i_3396;
  return &_self->_base;
}

static kk_box_t kk_model_dash_resources__lift3144_random__walk_fun4907(kk_function_t _fself, kk_function_t _b_4241, kk_box_t _b_4242, kk_context_t* _ctx) {
  struct kk_model_dash_resources__lift3144_random__walk_fun4907__t* _self = kk_function_as(struct kk_model_dash_resources__lift3144_random__walk_fun4907__t*, _fself);
  size_t i_3396 = _self->i_3396; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_3396, _b_4241, _b_4242, _ctx);
}


// lift anonymous function
struct kk_model_dash_resources__lift3144_random__walk_fun4909__t {
  struct kk_function_s _base;
  kk_function_t obs1;
  kk_std_core__list xs1;
  kk_std_core__list ys1;
  double s1;
  double x1;
  double y0;
};
static kk_box_t kk_model_dash_resources__lift3144_random__walk_fun4909(kk_function_t _fself, kk_box_t _b_4252, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources__new_lift3144_random__walk_fun4909(kk_function_t obs1, kk_std_core__list xs1, kk_std_core__list ys1, double s1, double x1, double y0, kk_context_t* _ctx) {
  struct kk_model_dash_resources__lift3144_random__walk_fun4909__t* _self = kk_function_alloc_as(struct kk_model_dash_resources__lift3144_random__walk_fun4909__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_model_dash_resources__lift3144_random__walk_fun4909, kk_context());
  _self->obs1 = obs1;
  _self->xs1 = xs1;
  _self->ys1 = ys1;
  _self->s1 = s1;
  _self->x1 = x1;
  _self->y0 = y0;
  return &_self->_base;
}

static kk_box_t kk_model_dash_resources__lift3144_random__walk_fun4909(kk_function_t _fself, kk_box_t _b_4252, kk_context_t* _ctx) {
  struct kk_model_dash_resources__lift3144_random__walk_fun4909__t* _self = kk_function_as(struct kk_model_dash_resources__lift3144_random__walk_fun4909__t*, _fself);
  kk_function_t obs1 = _self->obs1; /* (x : double, y : double) -> <std/num/random/random,effects-and-types/score> () */
  kk_std_core__list xs1 = _self->xs1; /* list<double> */
  kk_std_core__list ys1 = _self->ys1; /* list<double> */
  double s1 = _self->s1; /* double */
  double x1 = _self->x1; /* double */
  double y0 = _self->y0; /* double */
  kk_drop_match(_self, {kk_function_dup(obs1);kk_std_core__list_dup(xs1);kk_std_core__list_dup(ys1);;;;}, {}, _ctx)
  kk_std_core__list _x4910;
  double _x4911 = kk_double_unbox(_b_4252, _ctx); /*double*/
  _x4910 = kk_model_dash_resources__mlift3189_op(obs1, s1, x1, xs1, y0, ys1, _x4911, _ctx); /*list<double>*/
  return kk_std_core__list_box(_x4910, _ctx);
}


// lift anonymous function
struct kk_model_dash_resources__lift3144_random__walk_fun4915__t {
  struct kk_function_s _base;
  kk_function_t obs1;
};
static kk_box_t kk_model_dash_resources__lift3144_random__walk_fun4915(kk_function_t _fself, kk_box_t _b_4261, kk_box_t _b_4262, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources__new_lift3144_random__walk_fun4915(kk_function_t obs1, kk_context_t* _ctx) {
  struct kk_model_dash_resources__lift3144_random__walk_fun4915__t* _self = kk_function_alloc_as(struct kk_model_dash_resources__lift3144_random__walk_fun4915__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_model_dash_resources__lift3144_random__walk_fun4915, kk_context());
  _self->obs1 = obs1;
  return &_self->_base;
}

static kk_box_t kk_model_dash_resources__lift3144_random__walk_fun4915(kk_function_t _fself, kk_box_t _b_4261, kk_box_t _b_4262, kk_context_t* _ctx) {
  struct kk_model_dash_resources__lift3144_random__walk_fun4915__t* _self = kk_function_as(struct kk_model_dash_resources__lift3144_random__walk_fun4915__t*, _fself);
  kk_function_t obs1 = _self->obs1; /* (x : double, y : double) -> <std/num/random/random,effects-and-types/score> () */
  kk_drop_match(_self, {kk_function_dup(obs1);}, {}, _ctx)
  kk_function_drop(obs1, _ctx);
  kk_unit_t _x4916 = kk_Unit;
  double _x4917 = kk_double_unbox(_b_4261, _ctx); /*double*/
  double _x4918 = kk_double_unbox(_b_4262, _ctx); /*double*/
  kk_function_call(kk_unit_t, (kk_function_t, double, double, kk_context_t*), obs1, (obs1, _x4917, _x4918, _ctx));
  return kk_unit_box(_x4916);
}


// lift anonymous function
struct kk_model_dash_resources__lift3144_random__walk_fun4920__t {
  struct kk_function_s _base;
  kk_function_t obs1;
  kk_std_core__list xs1;
  kk_std_core__list ys1;
  double s1;
  double x0_3393;
  double x1;
};
static kk_box_t kk_model_dash_resources__lift3144_random__walk_fun4920(kk_function_t _fself, kk_box_t _b_4272, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources__new_lift3144_random__walk_fun4920(kk_function_t obs1, kk_std_core__list xs1, kk_std_core__list ys1, double s1, double x0_3393, double x1, kk_context_t* _ctx) {
  struct kk_model_dash_resources__lift3144_random__walk_fun4920__t* _self = kk_function_alloc_as(struct kk_model_dash_resources__lift3144_random__walk_fun4920__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_model_dash_resources__lift3144_random__walk_fun4920, kk_context());
  _self->obs1 = obs1;
  _self->xs1 = xs1;
  _self->ys1 = ys1;
  _self->s1 = s1;
  _self->x0_3393 = x0_3393;
  _self->x1 = x1;
  return &_self->_base;
}

static kk_box_t kk_model_dash_resources__lift3144_random__walk_fun4920(kk_function_t _fself, kk_box_t _b_4272, kk_context_t* _ctx) {
  struct kk_model_dash_resources__lift3144_random__walk_fun4920__t* _self = kk_function_as(struct kk_model_dash_resources__lift3144_random__walk_fun4920__t*, _fself);
  kk_function_t obs1 = _self->obs1; /* (x : double, y : double) -> <std/num/random/random,effects-and-types/score> () */
  kk_std_core__list xs1 = _self->xs1; /* list<double> */
  kk_std_core__list ys1 = _self->ys1; /* list<double> */
  double s1 = _self->s1; /* double */
  double x0_3393 = _self->x0_3393; /* double */
  double x1 = _self->x1; /* double */
  kk_drop_match(_self, {kk_function_dup(obs1);kk_std_core__list_dup(xs1);kk_std_core__list_dup(ys1);;;;}, {}, _ctx)
  kk_std_core__list _x4921;
  kk_unit_t _x4922 = kk_Unit;
  kk_unit_unbox(_b_4272);
  _x4921 = kk_model_dash_resources__mlift3188_op(obs1, s1, x1, x0_3393, xs1, ys1, _x4922, _ctx); /*list<double>*/
  return kk_std_core__list_box(_x4921, _ctx);
}

kk_std_core__list kk_model_dash_resources__lift3144_random__walk(kk_function_t obs1, double s1, kk_std_core__list xss, kk_std_core__list yss, kk_context_t* _ctx) { /* (obs : (x : double, y : double) -> <std/num/random/random,effects-and-types/score> (), s : double, xss : list<double>, yss : list<double>) -> <std/num/random/random,effects-and-types/score,effects-and-types/sample> list<double> */ 
  kk__tailcall: ;
  if (kk_std_core__is_Nil(yss)) {
    kk_function_drop(obs1, _ctx);
    return xss;
  }
  struct kk_std_core_Cons* _con4902 = kk_std_core__as_Cons(yss);
  kk_box_t _box_x4234 = _con4902->head;
  kk_std_core__list ys1 = _con4902->tail;
  double y0 = kk_double_unbox(_box_x4234, NULL);
  kk_reuse_t _ru_4417 = kk_reuse_null; /*reuse*/;
  if (kk_std_core__list_is_unique(yss)) {
    kk_box_drop(_box_x4234, _ctx);
    _ru_4417 = (kk_std_core__list_reuse(yss));
  }
  else {
    kk_std_core__list_dup(ys1);
    kk_std_core__list_decref(yss, _ctx);
    _ru_4417 = kk_reuse_null;
  }
  if (kk_std_core__is_Nil(xss)) {
    kk_reuse_drop(_ru_4417, _ctx);
    kk_function_drop(obs1, _ctx);
    kk_std_core__list_drop(ys1, _ctx);
    return kk_std_core__new_Nil(_ctx);
  }
  struct kk_std_core_Cons* _con4904 = kk_std_core__as_Cons(xss);
  kk_box_t _box_x4235 = _con4904->head;
  kk_std_core__list xs1 = _con4904->tail;
  double x1 = kk_double_unbox(_box_x4235, NULL);
  kk_reuse_t _ru_4418 = kk_reuse_null; /*reuse*/;
  if (kk_std_core__list_is_unique(xss)) {
    kk_box_drop(_box_x4235, _ctx);
    _ru_4418 = (kk_std_core__list_reuse(xss));
  }
  else {
    kk_std_core__list_dup(xs1);
    kk_std_core__list_decref(xss, _ctx);
    _ru_4418 = kk_reuse_null;
  }
  double x0_3393;
  size_t i_3396 = ((size_t)1); /*std/core/hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_3396,kk_context()); /*std/core/hnd/evv<<effects-and-types/sample,std/num/random/random,effects-and-types/score>>*/;
  double y00 = kk_model_dash_resources_normal(x1, s1, _ctx); /*double*/;
  kk_unit_t __w_l717_c9 = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x4906 = kk_std_core_hnd_yield_cont(kk_model_dash_resources__new_lift3144_random__walk_fun4907(i_3396, _ctx), _ctx); /*3*/
    x0_3393 = kk_double_unbox(_x4906, _ctx); /*double*/
  }
  else {
    x0_3393 = y00; /*double*/
  }
  if (kk_yielding(kk_context())) {
    kk_reuse_drop(_ru_4417, _ctx);
    kk_reuse_drop(_ru_4418, _ctx);
    kk_box_t _x4908 = kk_std_core_hnd_yield_extend(kk_model_dash_resources__new_lift3144_random__walk_fun4909(obs1, xs1, ys1, s1, x1, y0, _ctx), _ctx); /*2*/
    return kk_std_core__list_unbox(_x4908, _ctx);
  }
  kk_unit_t x3_3401 = kk_Unit;
  kk_vector_t _b_4263_4257;
  kk_std_core__list _x4912;
  size_t _b_4267_4255 = ((size_t)0); /*std/core/hnd/ev-index*/;
  kk_std_core__list _b_4268_4256;
  size_t _b_4269_4253 = ((size_t)2); /*std/core/hnd/ev-index*/;
  _b_4268_4256 = kk_std_core__new_Cons(_ru_4418, kk_size_box(_b_4269_4253, _ctx), kk_std_core__new_Nil(_ctx), _ctx); /*list<std/core/hnd/ev-index>*/
  _x4912 = kk_std_core__new_Cons(_ru_4417, kk_size_box(_b_4267_4255, _ctx), _b_4268_4256, _ctx); /*list<0>*/
  _b_4263_4257 = kk_std_core_unvlist(_x4912, _ctx); /*vector<std/core/hnd/ev-index>*/
  kk_box_t _x4913;
  kk_function_t _x4914;
  kk_function_dup(obs1);
  _x4914 = kk_model_dash_resources__new_lift3144_random__walk_fun4915(obs1, _ctx); /*(1, 2) -> 4 3*/
  _x4913 = kk_std_core_hnd__open2(_b_4263_4257, _x4914, kk_double_box(x0_3393, _ctx), kk_double_box(y0, _ctx), _ctx); /*3*/
  kk_unit_unbox(_x4913);
  if (kk_yielding(kk_context())) {
    kk_box_t _x4919 = kk_std_core_hnd_yield_extend(kk_model_dash_resources__new_lift3144_random__walk_fun4920(obs1, xs1, ys1, s1, x0_3393, x1, _ctx), _ctx); /*2*/
    return kk_std_core__list_unbox(_x4919, _ctx);
  }
  kk_std_core__list xss0_31450;
  kk_std_core__list xs0_3405;
  kk_std_core__list _b_4278_4276 = kk_std_core__new_Cons(kk_reuse_null, kk_double_box(x1, _ctx), kk_std_core__new_Nil(_ctx), _ctx); /*list<double>*/;
  xs0_3405 = kk_std_core__new_Cons(kk_reuse_null, kk_double_box(x0_3393, _ctx), _b_4278_4276, _ctx); /*list<double>*/
  xss0_31450 = kk_std_core_append(xs0_3405, xs1, _ctx); /*list<double>*/
  { // tailcall
    xss = xss0_31450;
    yss = ys1;
    goto kk__tailcall;
  }
}
 
// monadic lift


// lift anonymous function
struct kk_model_dash_resources__mlift3190_random__walk_fun4938__t {
  struct kk_function_s _base;
  size_t _y_42;
};
static kk_box_t kk_model_dash_resources__mlift3190_random__walk_fun4938(kk_function_t _fself, kk_function_t _b_4302, kk_box_t _b_4303, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources__new_mlift3190_random__walk_fun4938(size_t _y_42, kk_context_t* _ctx) {
  struct kk_model_dash_resources__mlift3190_random__walk_fun4938__t* _self = kk_function_alloc_as(struct kk_model_dash_resources__mlift3190_random__walk_fun4938__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_model_dash_resources__mlift3190_random__walk_fun4938, kk_context());
  _self->_y_42 = _y_42;
  return &_self->_base;
}

static kk_box_t kk_model_dash_resources__mlift3190_random__walk_fun4938(kk_function_t _fself, kk_function_t _b_4302, kk_box_t _b_4303, kk_context_t* _ctx) {
  struct kk_model_dash_resources__mlift3190_random__walk_fun4938__t* _self = kk_function_as(struct kk_model_dash_resources__mlift3190_random__walk_fun4938__t*, _fself);
  size_t _y_42 = _self->_y_42; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_mask_at1(_y_42, false, _b_4302, _b_4303, _ctx);
}

kk_unit_t kk_model_dash_resources__mlift3190_random__walk(double x, double y, size_t _y_42, kk_context_t* _ctx) { /* (x : double, y : double, std/core/hnd/ev-index) -> <std/num/random/random,effects-and-types/score> () */ 
  kk_evv_t w0 = kk_std_core_hnd_evv_swap_delete(_y_42, false, _ctx); /*std/core/hnd/evv<std/core/hnd/_e2>*/;
  kk_unit_t x00 = kk_Unit;
  kk_effects_dash_and_dash_types__exp s_3410;
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*std/core/hnd/evv<(<>)>*/;
  kk_effects_dash_and_dash_types__exp x4;
  kk_effects_dash_and_dash_types__exp _pat__30__13_3202;
  double _x4923;
  double _x4924;
  double _x4925;
  double x0_3204 = (y - x); /*double*/;
  _x4925 = (x0_3204 * x0_3204); /*double*/
  double _x4926;
  double _x4927 = kk_model_dash_resources_square(0x1p0, _ctx); /*double*/
  _x4926 = (0x1p1 * _x4927); /*double*/
  _x4924 = (_x4925 / _x4926); /*double*/
  _x4923 = ((0x0p+0) - _x4924); /*double*/
  _pat__30__13_3202 = kk_effects_dash_and_dash_types__new_Exp(_x4923, _ctx); /*effects-and-types/exp*/
  kk_effects_dash_and_dash_types__exp _pat__30__28_3203;
  double x1_3205;
  double _x4928;
  double _x4929;
  double _x4930 = (0x1p1 * (0x1.921fb54442d18p1)); /*double*/
  _x4929 = sqrt(_x4930); /*double*/
  _x4928 = (0x1p0 * _x4929); /*double*/
  x1_3205 = log(_x4928); /*double*/
  _pat__30__28_3203 = kk_effects_dash_and_dash_types__new_Exp(x1_3205, _ctx); /*effects-and-types/exp*/
  double xe = _pat__30__13_3202.i;
  double ye = _pat__30__28_3203.i;
  double _x4931 = (xe - ye); /*double*/
  x4 = kk_effects_dash_and_dash_types__new_Exp(_x4931, _ctx); /*effects-and-types/exp*/
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  s_3410 = x4; /*effects-and-types/exp*/
  kk_std_core_hnd__ev ev_406;
  size_t _x4932 = ((size_t)0); /*size_t*/
  ev_406 = kk_evv_at(_x4932,kk_context()); /*std/core/hnd/ev<effects-and-types/.hnd-score>*/
  kk_box_t _x4933;
  struct kk_std_core_hnd_Ev* _con4934 = kk_std_core_hnd__as_Ev(ev_406);
  kk_std_core_hnd__marker m = _con4934->marker;
  kk_box_t _box_x4285 = _con4934->hnd;
  kk_effects_dash_and_dash_types__hnd_score h = kk_effects_dash_and_dash_types__hnd_score_unbox(_box_x4285, NULL);
  kk_effects_dash_and_dash_types__hnd_score_dup(h);
  kk_std_core_hnd__clause1 _match_4434;
  struct kk_effects_dash_and_dash_types__Hnd_score* _con4936 = kk_effects_dash_and_dash_types__as_Hnd_score(h);
  kk_std_core_hnd__clause1 fun_score = _con4936->fun_score;
  if (kk_effects_dash_and_dash_types__hnd_score_is_unique(h)) {
    kk_effects_dash_and_dash_types__hnd_score_free(h);
  }
  else {
    kk_std_core_hnd__clause1_dup(fun_score);
    kk_effects_dash_and_dash_types__hnd_score_decref(h, _ctx);
  }
  _match_4434 = fun_score; /*std/core/hnd/clause1<effects-and-types/exp,(),effects-and-types/.hnd-score,2,3>*/
  kk_function_t _fun_unbox_x4289 = _match_4434.clause;
  _x4933 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x4289, (_fun_unbox_x4289, m, ev_406, kk_effects_dash_and_dash_types__exp_box(s_3410, _ctx), _ctx)); /*11*/
  kk_unit_unbox(_x4933);
  kk_unit_t __w_l645_c9 = kk_Unit;
  kk_evv_set(w0,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x4937 = kk_std_core_hnd_yield_cont(kk_model_dash_resources__new_mlift3190_random__walk_fun4938(_y_42, _ctx), _ctx); /*3*/
    kk_unit_unbox(_x4937); return kk_Unit;
  }
  x00; return kk_Unit;
}
 
// monadic lift

kk_std_core__list kk_model_dash_resources__mlift3191_random__walk(kk_std_core__list _x14939, kk_context_t* _ctx) { /* (list<double>) -> <std/num/random/random,effects-and-types/score,effects-and-types/sample> list<double> */ 
  return kk_std_core_reverse(_x14939, _ctx);
}


// lift anonymous function
struct kk_model_dash_resources_random__walk_fun4940__t {
  struct kk_function_s _base;
  kk_std_core__list zs;
};
static kk_function_t kk_model_dash_resources_random__walk_fun4940(kk_function_t _fself, double s, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources_new_random__walk_fun4940(kk_std_core__list zs, kk_context_t* _ctx) {
  struct kk_model_dash_resources_random__walk_fun4940__t* _self = kk_function_alloc_as(struct kk_model_dash_resources_random__walk_fun4940__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_model_dash_resources_random__walk_fun4940, kk_context());
  _self->zs = zs;
  return &_self->_base;
}



// lift anonymous function
struct kk_model_dash_resources_random__walk_fun4941__t {
  struct kk_function_s _base;
  kk_std_core__list zs;
  double s;
};
static kk_std_core__list kk_model_dash_resources_random__walk_fun4941(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources_new_random__walk_fun4941(kk_std_core__list zs, double s, kk_context_t* _ctx) {
  struct kk_model_dash_resources_random__walk_fun4941__t* _self = kk_function_alloc_as(struct kk_model_dash_resources_random__walk_fun4941__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_model_dash_resources_random__walk_fun4941, kk_context());
  _self->zs = zs;
  _self->s = s;
  return &_self->_base;
}



// lift anonymous function
struct kk_model_dash_resources_random__walk_fun4942__t {
  struct kk_function_s _base;
};
static kk_unit_t kk_model_dash_resources_random__walk_fun4942(kk_function_t _fself, double x0, double y, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources_new_random__walk_fun4942(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_model_dash_resources_random__walk_fun4942, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_model_dash_resources_random__walk_fun4945__t {
  struct kk_function_s _base;
  double x0;
  double y;
};
static kk_box_t kk_model_dash_resources_random__walk_fun4945(kk_function_t _fself, kk_box_t _b_4318, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources_new_random__walk_fun4945(double x0, double y, kk_context_t* _ctx) {
  struct kk_model_dash_resources_random__walk_fun4945__t* _self = kk_function_alloc_as(struct kk_model_dash_resources_random__walk_fun4945__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_model_dash_resources_random__walk_fun4945, kk_context());
  _self->x0 = x0;
  _self->y = y;
  return &_self->_base;
}

static kk_box_t kk_model_dash_resources_random__walk_fun4945(kk_function_t _fself, kk_box_t _b_4318, kk_context_t* _ctx) {
  struct kk_model_dash_resources_random__walk_fun4945__t* _self = kk_function_as(struct kk_model_dash_resources_random__walk_fun4945__t*, _fself);
  double x0 = _self->x0; /* double */
  double y = _self->y; /* double */
  kk_drop_match(_self, {;;}, {}, _ctx)
  kk_unit_t _x4946 = kk_Unit;
  size_t _x4947 = kk_size_unbox(_b_4318, _ctx); /*std/core/hnd/ev-index*/
  kk_model_dash_resources__mlift3190_random__walk(x0, y, _x4947, _ctx);
  return kk_unit_box(_x4946);
}
static kk_unit_t kk_model_dash_resources_random__walk_fun4942(kk_function_t _fself, double x0, double y, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  size_t x1_3418;
  kk_std_core_hnd__htag _x4943 = kk_std_core_hnd__htag_dup(kk_std_num_random__tag_random); /*std/core/hnd/htag<std/num/random/.hnd-random>*/
  x1_3418 = kk_std_core_hnd__evv_index(_x4943, _ctx); /*std/core/hnd/ev-index*/
  if (kk_yielding(kk_context())) {
    kk_box_t _x4944 = kk_std_core_hnd_yield_extend(kk_model_dash_resources_new_random__walk_fun4945(x0, y, _ctx), _ctx); /*2*/
    return kk_unit_unbox(_x4944);
  }
  return kk_model_dash_resources__mlift3190_random__walk(x0, y, x1_3418, _ctx);
}


// lift anonymous function
struct kk_model_dash_resources_random__walk_fun4949__t {
  struct kk_function_s _base;
};
static kk_box_t kk_model_dash_resources_random__walk_fun4949(kk_function_t _fself, kk_box_t _b_4322, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources_new_random__walk_fun4949(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_model_dash_resources_random__walk_fun4949, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_model_dash_resources_random__walk_fun4949(kk_function_t _fself, kk_box_t _b_4322, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core__list _x4950;
  kk_std_core__list _x4951 = kk_std_core__list_unbox(_b_4322, _ctx); /*list<double>*/
  _x4950 = kk_model_dash_resources__mlift3191_random__walk(_x4951, _ctx); /*list<double>*/
  return kk_std_core__list_box(_x4950, _ctx);
}
static kk_std_core__list kk_model_dash_resources_random__walk_fun4941(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_model_dash_resources_random__walk_fun4941__t* _self = kk_function_as(struct kk_model_dash_resources_random__walk_fun4941__t*, _fself);
  kk_std_core__list zs = _self->zs; /* list<double> */
  double s = _self->s; /* double */
  kk_drop_match(_self, {kk_std_core__list_dup(zs);;}, {}, _ctx)
  kk_std_core__list xss = kk_std_core__new_Cons(kk_reuse_null, kk_double_box(0x0p+0, _ctx), kk_std_core__new_Nil(_ctx), _ctx); /*list<double>*/;
  kk_std_core__list x_3415 = kk_model_dash_resources__lift3144_random__walk(kk_model_dash_resources_new_random__walk_fun4942(_ctx), s, xss, zs, _ctx); /*list<double>*/;
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_3415, _ctx);
    kk_box_t _x4948 = kk_std_core_hnd_yield_extend(kk_model_dash_resources_new_random__walk_fun4949(_ctx), _ctx); /*2*/
    return kk_std_core__list_unbox(_x4948, _ctx);
  }
  return kk_std_core_reverse(x_3415, _ctx);
}
static kk_function_t kk_model_dash_resources_random__walk_fun4940(kk_function_t _fself, double s, kk_context_t* _ctx) {
  struct kk_model_dash_resources_random__walk_fun4940__t* _self = kk_function_as(struct kk_model_dash_resources_random__walk_fun4940__t*, _fself);
  kk_std_core__list zs = _self->zs; /* list<double> */
  kk_drop_match(_self, {kk_std_core__list_dup(zs);}, {}, _ctx)
  return kk_model_dash_resources_new_random__walk_fun4941(zs, s, _ctx);
}

kk_function_t kk_model_dash_resources_random__walk(kk_std_core__list zs, kk_context_t* _ctx) { /* (zs : list<double>) -> ((s : double) -> effects-and-types/nmodel<list<double>>) */ 
  return kk_model_dash_resources_new_random__walk_fun4940(zs, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_model_dash_resources__mlift3192_sequential__gaussian_fun4954__t {
  struct kk_function_s _base;
  size_t _y_52;
};
static kk_box_t kk_model_dash_resources__mlift3192_sequential__gaussian_fun4954(kk_function_t _fself, kk_function_t _b_4332, kk_box_t _b_4333, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources__new_mlift3192_sequential__gaussian_fun4954(size_t _y_52, kk_context_t* _ctx) {
  struct kk_model_dash_resources__mlift3192_sequential__gaussian_fun4954__t* _self = kk_function_alloc_as(struct kk_model_dash_resources__mlift3192_sequential__gaussian_fun4954__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_model_dash_resources__mlift3192_sequential__gaussian_fun4954, kk_context());
  _self->_y_52 = _y_52;
  return &_self->_base;
}

static kk_box_t kk_model_dash_resources__mlift3192_sequential__gaussian_fun4954(kk_function_t _fself, kk_function_t _b_4332, kk_box_t _b_4333, kk_context_t* _ctx) {
  struct kk_model_dash_resources__mlift3192_sequential__gaussian_fun4954__t* _self = kk_function_as(struct kk_model_dash_resources__mlift3192_sequential__gaussian_fun4954__t*, _fself);
  size_t _y_52 = _self->_y_52; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_mask_at1(_y_52, false, _b_4332, _b_4333, _ctx);
}

double kk_model_dash_resources__mlift3192_sequential__gaussian(kk_ref_t x, size_t _y_52, kk_context_t* _ctx) { /* forall<h> (x : local-var<h,double>, std/core/hnd/ev-index) -> <std/num/random/random,local<h>,effects-and-types/sample,effects-and-types/score> double */ 
  kk_evv_t w0 = kk_std_core_hnd_evv_swap_delete(_y_52, false, _ctx); /*std/core/hnd/evv<std/core/hnd/_e2>*/;
  double x0;
  kk_box_t _x4952 = (kk_ref_get(x,kk_context())); /*0*/
  x0 = kk_double_unbox(_x4952, _ctx); /*double*/
  kk_unit_t __w_l645_c9 = kk_Unit;
  kk_evv_set(w0,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x4953 = kk_std_core_hnd_yield_cont(kk_model_dash_resources__new_mlift3192_sequential__gaussian_fun4954(_y_52, _ctx), _ctx); /*3*/
    return kk_double_unbox(_x4953, _ctx);
  }
  return x0;
}
 
// monadic lift


// lift anonymous function
struct kk_model_dash_resources__mlift3193_sequential__gaussian_fun4965__t {
  struct kk_function_s _base;
  size_t i_3428;
};
static kk_box_t kk_model_dash_resources__mlift3193_sequential__gaussian_fun4965(kk_function_t _fself, kk_function_t _b_4348, kk_box_t _b_4349, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources__new_mlift3193_sequential__gaussian_fun4965(size_t i_3428, kk_context_t* _ctx) {
  struct kk_model_dash_resources__mlift3193_sequential__gaussian_fun4965__t* _self = kk_function_alloc_as(struct kk_model_dash_resources__mlift3193_sequential__gaussian_fun4965__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_model_dash_resources__mlift3193_sequential__gaussian_fun4965, kk_context());
  _self->i_3428 = i_3428;
  return &_self->_base;
}

static kk_box_t kk_model_dash_resources__mlift3193_sequential__gaussian_fun4965(kk_function_t _fself, kk_function_t _b_4348, kk_box_t _b_4349, kk_context_t* _ctx) {
  struct kk_model_dash_resources__mlift3193_sequential__gaussian_fun4965__t* _self = kk_function_as(struct kk_model_dash_resources__mlift3193_sequential__gaussian_fun4965__t*, _fself);
  size_t i_3428 = _self->i_3428; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_3428, _b_4348, _b_4349, _ctx);
}

kk_unit_t kk_model_dash_resources__mlift3193_sequential__gaussian(double data__point, double _y_49, kk_context_t* _ctx) { /* forall<h> (data_point : double, double) -> <local<h>,effects-and-types/score,effects-and-types/sample,std/num/random/random> () */ 
  kk_effects_dash_and_dash_types__exp _x10;
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*std/core/hnd/evv<(<>)>*/;
  kk_effects_dash_and_dash_types__exp x0;
  kk_effects_dash_and_dash_types__exp _pat__30__13_3202;
  double _x4955;
  double _x4956;
  double _x4957;
  double x0_3204 = (data__point - _y_49); /*double*/;
  _x4957 = (x0_3204 * x0_3204); /*double*/
  double _x4958;
  double _x4959 = kk_model_dash_resources_square(0x1.999999999999ap-3, _ctx); /*double*/
  _x4958 = (0x1p1 * _x4959); /*double*/
  _x4956 = (_x4957 / _x4958); /*double*/
  _x4955 = ((0x0p+0) - _x4956); /*double*/
  _pat__30__13_3202 = kk_effects_dash_and_dash_types__new_Exp(_x4955, _ctx); /*effects-and-types/exp*/
  kk_effects_dash_and_dash_types__exp _pat__30__28_3203;
  double x1_3205;
  double _x4960;
  double _x4961;
  double _x4962 = (0x1p1 * (0x1.921fb54442d18p1)); /*double*/
  _x4961 = sqrt(_x4962); /*double*/
  _x4960 = ((0x1.999999999999ap-3) * _x4961); /*double*/
  x1_3205 = log(_x4960); /*double*/
  _pat__30__28_3203 = kk_effects_dash_and_dash_types__new_Exp(x1_3205, _ctx); /*effects-and-types/exp*/
  double xe = _pat__30__13_3202.i;
  double ye = _pat__30__28_3203.i;
  double _x4963 = (xe - ye); /*double*/
  x0 = kk_effects_dash_and_dash_types__new_Exp(_x4963, _ctx); /*effects-and-types/exp*/
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  _x10 = x0; /*effects-and-types/exp*/
  size_t i_3428 = ((size_t)2); /*std/core/hnd/ev-index*/;
  kk_evv_t w0 = kk_evv_swap_create1(i_3428,kk_context()); /*std/core/hnd/evv<<effects-and-types/score,local<3137>,effects-and-types/sample,std/num/random/random>>*/;
  kk_unit_t y = kk_Unit;
  kk_effects_dash_and_dash_types_score(_x10, _ctx);
  kk_unit_t __w_l700_c9 = kk_Unit;
  kk_evv_set(w0,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x4964 = kk_std_core_hnd_yield_cont(kk_model_dash_resources__new_mlift3193_sequential__gaussian_fun4965(i_3428, _ctx), _ctx); /*3*/
    kk_unit_unbox(_x4964); return kk_Unit;
  }
  y; return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_model_dash_resources__mlift3194_sequential__gaussian_fun4968__t {
  struct kk_function_s _base;
  double data__point;
};
static kk_box_t kk_model_dash_resources__mlift3194_sequential__gaussian_fun4968(kk_function_t _fself, kk_box_t _b_4361, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources__new_mlift3194_sequential__gaussian_fun4968(double data__point, kk_context_t* _ctx) {
  struct kk_model_dash_resources__mlift3194_sequential__gaussian_fun4968__t* _self = kk_function_alloc_as(struct kk_model_dash_resources__mlift3194_sequential__gaussian_fun4968__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_model_dash_resources__mlift3194_sequential__gaussian_fun4968, kk_context());
  _self->data__point = data__point;
  return &_self->_base;
}

static kk_box_t kk_model_dash_resources__mlift3194_sequential__gaussian_fun4968(kk_function_t _fself, kk_box_t _b_4361, kk_context_t* _ctx) {
  struct kk_model_dash_resources__mlift3194_sequential__gaussian_fun4968__t* _self = kk_function_as(struct kk_model_dash_resources__mlift3194_sequential__gaussian_fun4968__t*, _fself);
  double data__point = _self->data__point; /* double */
  kk_drop_match(_self, {;}, {}, _ctx)
  kk_unit_t _x4969 = kk_Unit;
  double _x4970 = kk_double_unbox(_b_4361, _ctx); /*double*/
  kk_model_dash_resources__mlift3193_sequential__gaussian(data__point, _x4970, _ctx);
  return kk_unit_box(_x4969);
}

kk_unit_t kk_model_dash_resources__mlift3194_sequential__gaussian(double data__point, kk_ref_t x, kk_unit_t wild__, kk_context_t* _ctx) { /* forall<h> (data_point : double, x : local-var<h,double>, wild_ : ()) -> <local<h>,effects-and-types/sample,effects-and-types/score,std/num/random/random> () */ 
  double x0_3431;
  kk_box_t _x4966 = (kk_ref_get(x,kk_context())); /*0*/
  x0_3431 = kk_double_unbox(_x4966, _ctx); /*double*/
  if (kk_yielding(kk_context())) {
    kk_box_t _x4967 = kk_std_core_hnd_yield_extend(kk_model_dash_resources__new_mlift3194_sequential__gaussian_fun4968(data__point, _ctx), _ctx); /*2*/
    kk_unit_unbox(_x4967); return kk_Unit;
  }
  kk_model_dash_resources__mlift3193_sequential__gaussian(data__point, x0_3431, _ctx); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_model_dash_resources__mlift3195_sequential__gaussian_fun4973__t {
  struct kk_function_s _base;
  kk_ref_t x;
  double data__point;
};
static kk_box_t kk_model_dash_resources__mlift3195_sequential__gaussian_fun4973(kk_function_t _fself, kk_box_t _b_4369, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources__new_mlift3195_sequential__gaussian_fun4973(kk_ref_t x, double data__point, kk_context_t* _ctx) {
  struct kk_model_dash_resources__mlift3195_sequential__gaussian_fun4973__t* _self = kk_function_alloc_as(struct kk_model_dash_resources__mlift3195_sequential__gaussian_fun4973__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_model_dash_resources__mlift3195_sequential__gaussian_fun4973, kk_context());
  _self->x = x;
  _self->data__point = data__point;
  return &_self->_base;
}

static kk_box_t kk_model_dash_resources__mlift3195_sequential__gaussian_fun4973(kk_function_t _fself, kk_box_t _b_4369, kk_context_t* _ctx) {
  struct kk_model_dash_resources__mlift3195_sequential__gaussian_fun4973__t* _self = kk_function_as(struct kk_model_dash_resources__mlift3195_sequential__gaussian_fun4973__t*, _fself);
  kk_ref_t x = _self->x; /* local-var<3137,double> */
  double data__point = _self->data__point; /* double */
  kk_drop_match(_self, {kk_ref_dup(x);;}, {}, _ctx)
  kk_unit_t _x4974 = kk_Unit;
  kk_unit_t _x4975 = kk_Unit;
  kk_unit_unbox(_b_4369);
  kk_model_dash_resources__mlift3194_sequential__gaussian(data__point, x, _x4975, _ctx);
  return kk_unit_box(_x4974);
}

kk_unit_t kk_model_dash_resources__mlift3195_sequential__gaussian(double data__point, kk_ref_t x, double _y_47, kk_context_t* _ctx) { /* forall<h> (data_point : double, x : local-var<h,double>, double) -> <effects-and-types/sample,local<h>,effects-and-types/score,std/num/random/random> () */ 
  kk_unit_t x0_3433 = kk_Unit;
  kk_ref_t _x4971 = kk_ref_dup(x); /*local-var<3137,double>*/
  (kk_ref_set(_x4971,(kk_double_box(_y_47, _ctx)),kk_context()));
  if (kk_yielding(kk_context())) {
    kk_box_t _x4972 = kk_std_core_hnd_yield_extend(kk_model_dash_resources__new_mlift3195_sequential__gaussian_fun4973(x, data__point, _ctx), _ctx); /*2*/
    kk_unit_unbox(_x4972); return kk_Unit;
  }
  kk_model_dash_resources__mlift3194_sequential__gaussian(data__point, x, x0_3433, _ctx); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_model_dash_resources__mlift3196_sequential__gaussian_fun4977__t {
  struct kk_function_s _base;
  double _y_46;
};
static kk_box_t kk_model_dash_resources__mlift3196_sequential__gaussian_fun4977(kk_function_t _fself, kk_box_t _b_4373, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources__new_mlift3196_sequential__gaussian_fun4977(double _y_46, kk_context_t* _ctx) {
  struct kk_model_dash_resources__mlift3196_sequential__gaussian_fun4977__t* _self = kk_function_alloc_as(struct kk_model_dash_resources__mlift3196_sequential__gaussian_fun4977__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_model_dash_resources__mlift3196_sequential__gaussian_fun4977, kk_context());
  _self->_y_46 = _y_46;
  return &_self->_base;
}

static kk_box_t kk_model_dash_resources__mlift3196_sequential__gaussian_fun4977(kk_function_t _fself, kk_box_t _b_4373, kk_context_t* _ctx) {
  struct kk_model_dash_resources__mlift3196_sequential__gaussian_fun4977__t* _self = kk_function_as(struct kk_model_dash_resources__mlift3196_sequential__gaussian_fun4977__t*, _fself);
  double _y_46 = _self->_y_46; /* double */
  kk_drop_match(_self, {;}, {}, _ctx)
  double _x4978;
  double _x4979 = kk_double_unbox(_b_4373, _ctx); /*double*/
  _x4978 = kk_model_dash_resources__mlift3175_normal(_y_46, 0x1p0, _x4979, _ctx); /*double*/
  return kk_double_box(_x4978, _ctx);
}


// lift anonymous function
struct kk_model_dash_resources__mlift3196_sequential__gaussian_fun4982__t {
  struct kk_function_s _base;
  size_t i_3437;
};
static kk_box_t kk_model_dash_resources__mlift3196_sequential__gaussian_fun4982(kk_function_t _fself, kk_function_t _b_4381, kk_box_t _b_4382, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources__new_mlift3196_sequential__gaussian_fun4982(size_t i_3437, kk_context_t* _ctx) {
  struct kk_model_dash_resources__mlift3196_sequential__gaussian_fun4982__t* _self = kk_function_alloc_as(struct kk_model_dash_resources__mlift3196_sequential__gaussian_fun4982__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_model_dash_resources__mlift3196_sequential__gaussian_fun4982, kk_context());
  _self->i_3437 = i_3437;
  return &_self->_base;
}

static kk_box_t kk_model_dash_resources__mlift3196_sequential__gaussian_fun4982(kk_function_t _fself, kk_function_t _b_4381, kk_box_t _b_4382, kk_context_t* _ctx) {
  struct kk_model_dash_resources__mlift3196_sequential__gaussian_fun4982__t* _self = kk_function_as(struct kk_model_dash_resources__mlift3196_sequential__gaussian_fun4982__t*, _fself);
  size_t i_3437 = _self->i_3437; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_3437, _b_4381, _b_4382, _ctx);
}


// lift anonymous function
struct kk_model_dash_resources__mlift3196_sequential__gaussian_fun4984__t {
  struct kk_function_s _base;
  kk_ref_t x;
  double data__point;
};
static kk_box_t kk_model_dash_resources__mlift3196_sequential__gaussian_fun4984(kk_function_t _fself, kk_box_t _b_4392, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources__new_mlift3196_sequential__gaussian_fun4984(kk_ref_t x, double data__point, kk_context_t* _ctx) {
  struct kk_model_dash_resources__mlift3196_sequential__gaussian_fun4984__t* _self = kk_function_alloc_as(struct kk_model_dash_resources__mlift3196_sequential__gaussian_fun4984__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_model_dash_resources__mlift3196_sequential__gaussian_fun4984, kk_context());
  _self->x = x;
  _self->data__point = data__point;
  return &_self->_base;
}

static kk_box_t kk_model_dash_resources__mlift3196_sequential__gaussian_fun4984(kk_function_t _fself, kk_box_t _b_4392, kk_context_t* _ctx) {
  struct kk_model_dash_resources__mlift3196_sequential__gaussian_fun4984__t* _self = kk_function_as(struct kk_model_dash_resources__mlift3196_sequential__gaussian_fun4984__t*, _fself);
  kk_ref_t x = _self->x; /* local-var<3137,double> */
  double data__point = _self->data__point; /* double */
  kk_drop_match(_self, {kk_ref_dup(x);;}, {}, _ctx)
  kk_unit_t _x4985 = kk_Unit;
  double _x4986 = kk_double_unbox(_b_4392, _ctx); /*double*/
  kk_model_dash_resources__mlift3195_sequential__gaussian(data__point, x, _x4986, _ctx);
  return kk_unit_box(_x4985);
}

kk_unit_t kk_model_dash_resources__mlift3196_sequential__gaussian(double data__point, kk_ref_t x, double _y_46, kk_context_t* _ctx) { /* forall<h> (data_point : double, x : local-var<h,double>, double) -> <local<h>,effects-and-types/sample,effects-and-types/score,std/num/random/random> () */ 
  double x0_3435;
  size_t i_3437 = ((size_t)1); /*std/core/hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_3437,kk_context()); /*std/core/hnd/evv<<effects-and-types/sample,local<3137>,effects-and-types/score,std/num/random/random>>*/;
  double y;
  double x_3267 = kk_model_dash_resources_standard_normal(_ctx); /*double*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x4976 = kk_std_core_hnd_yield_extend(kk_model_dash_resources__new_mlift3196_sequential__gaussian_fun4977(_y_46, _ctx), _ctx); /*2*/
    y = kk_double_unbox(_x4976, _ctx); /*double*/
  }
  else {
    double _x4980 = (x_3267 * 0x1p0); /*double*/
    y = (_y_46 + _x4980); /*double*/
  }
  kk_unit_t __w_l717_c9 = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x4981 = kk_std_core_hnd_yield_cont(kk_model_dash_resources__new_mlift3196_sequential__gaussian_fun4982(i_3437, _ctx), _ctx); /*3*/
    x0_3435 = kk_double_unbox(_x4981, _ctx); /*double*/
  }
  else {
    x0_3435 = y; /*double*/
  }
  if (kk_yielding(kk_context())) {
    kk_box_t _x4983 = kk_std_core_hnd_yield_extend(kk_model_dash_resources__new_mlift3196_sequential__gaussian_fun4984(x, data__point, _ctx), _ctx); /*2*/
    kk_unit_unbox(_x4983); return kk_Unit;
  }
  kk_model_dash_resources__mlift3195_sequential__gaussian(data__point, x, x0_3435, _ctx); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_model_dash_resources__mlift3197_sequential__gaussian_fun4989__t {
  struct kk_function_s _base;
  kk_ref_t x;
};
static kk_box_t kk_model_dash_resources__mlift3197_sequential__gaussian_fun4989(kk_function_t _fself, kk_box_t _b_4396, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources__new_mlift3197_sequential__gaussian_fun4989(kk_ref_t x, kk_context_t* _ctx) {
  struct kk_model_dash_resources__mlift3197_sequential__gaussian_fun4989__t* _self = kk_function_alloc_as(struct kk_model_dash_resources__mlift3197_sequential__gaussian_fun4989__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_model_dash_resources__mlift3197_sequential__gaussian_fun4989, kk_context());
  _self->x = x;
  return &_self->_base;
}

static kk_box_t kk_model_dash_resources__mlift3197_sequential__gaussian_fun4989(kk_function_t _fself, kk_box_t _b_4396, kk_context_t* _ctx) {
  struct kk_model_dash_resources__mlift3197_sequential__gaussian_fun4989__t* _self = kk_function_as(struct kk_model_dash_resources__mlift3197_sequential__gaussian_fun4989__t*, _fself);
  kk_ref_t x = _self->x; /* local-var<3137,double> */
  kk_drop_match(_self, {kk_ref_dup(x);}, {}, _ctx)
  double _x4990;
  size_t _x4991 = kk_size_unbox(_b_4396, _ctx); /*std/core/hnd/ev-index*/
  _x4990 = kk_model_dash_resources__mlift3192_sequential__gaussian(x, _x4991, _ctx); /*double*/
  return kk_double_box(_x4990, _ctx);
}

double kk_model_dash_resources__mlift3197_sequential__gaussian(kk_ref_t x, kk_unit_t wild__0, kk_context_t* _ctx) { /* forall<h> (x : local-var<h,double>, wild_0 : ()) -> <local<h>,effects-and-types/sample,effects-and-types/score,std/num/random/random> double */ 
  size_t x0_3441;
  kk_std_core_hnd__htag _x4987 = kk_std_core_hnd__htag_dup(kk_std_num_random__tag_random); /*std/core/hnd/htag<std/num/random/.hnd-random>*/
  x0_3441 = kk_std_core_hnd__evv_index(_x4987, _ctx); /*std/core/hnd/ev-index*/
  if (kk_yielding(kk_context())) {
    kk_box_t _x4988 = kk_std_core_hnd_yield_extend(kk_model_dash_resources__new_mlift3197_sequential__gaussian_fun4989(x, _ctx), _ctx); /*2*/
    return kk_double_unbox(_x4988, _ctx);
  }
  return kk_model_dash_resources__mlift3192_sequential__gaussian(x, x0_3441, _ctx);
}


// lift anonymous function
struct kk_model_dash_resources_sequential__gaussian_fun4992__t {
  struct kk_function_s _base;
  double data__point;
};
static double kk_model_dash_resources_sequential__gaussian_fun4992(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources_new_sequential__gaussian_fun4992(double data__point, kk_context_t* _ctx) {
  struct kk_model_dash_resources_sequential__gaussian_fun4992__t* _self = kk_function_alloc_as(struct kk_model_dash_resources_sequential__gaussian_fun4992__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_model_dash_resources_sequential__gaussian_fun4992, kk_context());
  _self->data__point = data__point;
  return &_self->_base;
}



// lift anonymous function
struct kk_model_dash_resources_sequential__gaussian_fun4994__t {
  struct kk_function_s _base;
  kk_ref_t loc;
  double data__point;
};
static kk_unit_t kk_model_dash_resources_sequential__gaussian_fun4994(kk_function_t _fself, kk_integer_t i, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources_new_sequential__gaussian_fun4994(kk_ref_t loc, double data__point, kk_context_t* _ctx) {
  struct kk_model_dash_resources_sequential__gaussian_fun4994__t* _self = kk_function_alloc_as(struct kk_model_dash_resources_sequential__gaussian_fun4994__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_model_dash_resources_sequential__gaussian_fun4994, kk_context());
  _self->loc = loc;
  _self->data__point = data__point;
  return &_self->_base;
}



// lift anonymous function
struct kk_model_dash_resources_sequential__gaussian_fun4998__t {
  struct kk_function_s _base;
  kk_ref_t loc;
  double data__point;
};
static kk_box_t kk_model_dash_resources_sequential__gaussian_fun4998(kk_function_t _fself, kk_box_t _b_4404, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources_new_sequential__gaussian_fun4998(kk_ref_t loc, double data__point, kk_context_t* _ctx) {
  struct kk_model_dash_resources_sequential__gaussian_fun4998__t* _self = kk_function_alloc_as(struct kk_model_dash_resources_sequential__gaussian_fun4998__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_model_dash_resources_sequential__gaussian_fun4998, kk_context());
  _self->loc = loc;
  _self->data__point = data__point;
  return &_self->_base;
}

static kk_box_t kk_model_dash_resources_sequential__gaussian_fun4998(kk_function_t _fself, kk_box_t _b_4404, kk_context_t* _ctx) {
  struct kk_model_dash_resources_sequential__gaussian_fun4998__t* _self = kk_function_as(struct kk_model_dash_resources_sequential__gaussian_fun4998__t*, _fself);
  kk_ref_t loc = _self->loc; /* local-var<global,double> */
  double data__point = _self->data__point; /* double */
  kk_drop_match(_self, {kk_ref_dup(loc);;}, {}, _ctx)
  kk_unit_t _x4999 = kk_Unit;
  double _x5000 = kk_double_unbox(_b_4404, _ctx); /*double*/
  kk_model_dash_resources__mlift3196_sequential__gaussian(data__point, loc, _x5000, _ctx);
  return kk_unit_box(_x4999);
}
static kk_unit_t kk_model_dash_resources_sequential__gaussian_fun4994(kk_function_t _fself, kk_integer_t i, kk_context_t* _ctx) {
  struct kk_model_dash_resources_sequential__gaussian_fun4994__t* _self = kk_function_as(struct kk_model_dash_resources_sequential__gaussian_fun4994__t*, _fself);
  kk_ref_t loc = _self->loc; /* local-var<global,double> */
  double data__point = _self->data__point; /* double */
  kk_drop_match(_self, {kk_ref_dup(loc);;}, {}, _ctx)
  kk_integer_drop(i, _ctx);
  double x1_3452;
  kk_box_t _x4995;
  kk_ref_t _x4996 = kk_ref_dup(loc); /*local-var<global,double>*/
  _x4995 = (kk_ref_get(_x4996,kk_context())); /*0*/
  x1_3452 = kk_double_unbox(_x4995, _ctx); /*double*/
  if (kk_yielding(kk_context())) {
    kk_box_t _x4997 = kk_std_core_hnd_yield_extend(kk_model_dash_resources_new_sequential__gaussian_fun4998(loc, data__point, _ctx), _ctx); /*2*/
    return kk_unit_unbox(_x4997);
  }
  return kk_model_dash_resources__mlift3196_sequential__gaussian(data__point, loc, x1_3452, _ctx);
}


// lift anonymous function
struct kk_model_dash_resources_sequential__gaussian_fun5003__t {
  struct kk_function_s _base;
  kk_ref_t loc;
};
static kk_box_t kk_model_dash_resources_sequential__gaussian_fun5003(kk_function_t _fself, kk_box_t _b_4408, kk_context_t* _ctx);
static kk_function_t kk_model_dash_resources_new_sequential__gaussian_fun5003(kk_ref_t loc, kk_context_t* _ctx) {
  struct kk_model_dash_resources_sequential__gaussian_fun5003__t* _self = kk_function_alloc_as(struct kk_model_dash_resources_sequential__gaussian_fun5003__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_model_dash_resources_sequential__gaussian_fun5003, kk_context());
  _self->loc = loc;
  return &_self->_base;
}

static kk_box_t kk_model_dash_resources_sequential__gaussian_fun5003(kk_function_t _fself, kk_box_t _b_4408, kk_context_t* _ctx) {
  struct kk_model_dash_resources_sequential__gaussian_fun5003__t* _self = kk_function_as(struct kk_model_dash_resources_sequential__gaussian_fun5003__t*, _fself);
  kk_ref_t loc = _self->loc; /* local-var<global,double> */
  kk_drop_match(_self, {kk_ref_dup(loc);}, {}, _ctx)
  double _x5004;
  kk_unit_t _x5005 = kk_Unit;
  kk_unit_unbox(_b_4408);
  _x5004 = kk_model_dash_resources__mlift3197_sequential__gaussian(loc, _x5005, _ctx); /*double*/
  return kk_double_box(_x5004, _ctx);
}
static double kk_model_dash_resources_sequential__gaussian_fun4992(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_model_dash_resources_sequential__gaussian_fun4992__t* _self = kk_function_as(struct kk_model_dash_resources_sequential__gaussian_fun4992__t*, _fself);
  double data__point = _self->data__point; /* double */
  kk_drop_match(_self, {;}, {}, _ctx)
  kk_ref_t loc = kk_ref_alloc((kk_double_box(0x0p+0, _ctx)),kk_context()); /*local-var<global,double>*/;
  double res;
  kk_unit_t x0_3447 = kk_Unit;
  kk_function_t _x4993;
  kk_ref_dup(loc);
  _x4993 = kk_model_dash_resources_new_sequential__gaussian_fun4994(loc, data__point, _ctx); /*(i : int) -> <local<global>,effects-and-types/sample,effects-and-types/score,std/num/random/random> ()*/
  kk_std_core__lift21056_for(_x4993, kk_integer_from_small(5), kk_integer_from_small(0), _ctx);
  if (kk_yielding(kk_context())) {
    kk_box_t _x5001;
    kk_function_t _x5002;
    kk_ref_dup(loc);
    _x5002 = kk_model_dash_resources_new_sequential__gaussian_fun5003(loc, _ctx); /*(1) -> 3 2*/
    _x5001 = kk_std_core_hnd_yield_extend(_x5002, _ctx); /*2*/
    res = kk_double_unbox(_x5001, _ctx); /*double*/
  }
  else {
    kk_ref_t _x5006 = kk_ref_dup(loc); /*local-var<global,double>*/
    res = kk_model_dash_resources__mlift3197_sequential__gaussian(_x5006, x0_3447, _ctx); /*double*/
  }
  kk_box_t _x5007 = kk_std_core_hnd_prompt_local_var(loc, kk_double_box(res, _ctx), _ctx); /*2*/
  return kk_double_unbox(_x5007, _ctx);
}

kk_function_t kk_model_dash_resources_sequential__gaussian(double data__point, kk_context_t* _ctx) { /* (data_point : double) -> effects-and-types/nmodel<double> */ 
  return kk_model_dash_resources_new_sequential__gaussian_fun4992(data__point, _ctx);
}

// initialization
void kk_model_dash_resources__init(kk_context_t* _ctx){
  static bool _initialized = false;
  if (_initialized) return;
  _initialized = true;
  kk_std_core_types__init(_ctx);
  kk_std_core_hnd__init(_ctx);
  kk_std_core__init(_ctx);
  kk_std_num_double__init(_ctx);
  kk_std_num_random__init(_ctx);
  kk_effects_dash_and_dash_types__init(_ctx);
  kk_handlers__init(_ctx);
  {
    kk_std_core_types__tuple2_ _b_3530_3528 = kk_std_core_types__new_dash__lp__comma__rp_(kk_double_box(0x1p0, _ctx), kk_double_box(0x1p1, _ctx), _ctx); /*(double, double)*/;
    kk_std_core__list _b_3531_3529;
    kk_std_core_types__tuple2_ _b_3534_3526 = kk_std_core_types__new_dash__lp__comma__rp_(kk_double_box(0x1p1, _ctx), kk_double_box(0x1.8p1, _ctx), _ctx); /*(double, double)*/;
    kk_std_core__list _b_3535_3527;
    kk_std_core_types__tuple2_ _b_3538_3524 = kk_std_core_types__new_dash__lp__comma__rp_(kk_double_box(0x1p0, _ctx), kk_double_box(0x1p1, _ctx), _ctx); /*(double, double)*/;
    kk_std_core__list _b_3539_3525;
    kk_std_core_types__tuple2_ _b_3542_3522 = kk_std_core_types__new_dash__lp__comma__rp_(kk_double_box(0x1p1, _ctx), kk_double_box(0x1.8p1, _ctx), _ctx); /*(double, double)*/;
    kk_std_core__list _b_3543_3523;
    kk_std_core_types__tuple2_ _b_3546_3520 = kk_std_core_types__new_dash__lp__comma__rp_(kk_double_box(0x1p0, _ctx), kk_double_box(0x1p1, _ctx), _ctx); /*(double, double)*/;
    kk_std_core__list _b_3547_3521;
    kk_std_core_types__tuple2_ _b_3550_3518 = kk_std_core_types__new_dash__lp__comma__rp_(kk_double_box(0x1p1, _ctx), kk_double_box(0x1.8p1, _ctx), _ctx); /*(double, double)*/;
    _b_3547_3521 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core_types__tuple2__box(_b_3550_3518, _ctx), kk_std_core__new_Nil(_ctx), _ctx); /*list<(double, double)>*/
    _b_3543_3523 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core_types__tuple2__box(_b_3546_3520, _ctx), _b_3547_3521, _ctx); /*list<(double, double)>*/
    _b_3539_3525 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core_types__tuple2__box(_b_3542_3522, _ctx), _b_3543_3523, _ctx); /*list<(double, double)>*/
    _b_3535_3527 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core_types__tuple2__box(_b_3538_3524, _ctx), _b_3539_3525, _ctx); /*list<(double, double)>*/
    _b_3531_3529 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core_types__tuple2__box(_b_3534_3526, _ctx), _b_3535_3527, _ctx); /*list<(double, double)>*/
    kk_model_dash_resources_dataset = kk_std_core__new_Cons(kk_reuse_null, kk_std_core_types__tuple2__box(_b_3530_3528, _ctx), _b_3531_3529, _ctx); /*effects-and-types/two_d_data*/
  }
  {
    kk_std_core__list _b_3571_3569;
    kk_std_core__list _b_3573_3567;
    kk_std_core__list _b_3575_3565;
    kk_std_core__list _b_3577_3563;
    kk_std_core__list _b_3579_3561;
    kk_std_core__list _b_3581_3559;
    kk_std_core__list _b_3583_3557 = kk_std_core__new_Cons(kk_reuse_null, kk_double_box(0x1.999999999999ap-3, _ctx), kk_std_core__new_Nil(_ctx), _ctx); /*list<double>*/;
    _b_3581_3559 = kk_std_core__new_Cons(kk_reuse_null, kk_double_box(0x0p+0, _ctx), _b_3583_3557, _ctx); /*list<double>*/
    _b_3579_3561 = kk_std_core__new_Cons(kk_reuse_null, kk_double_box(0x1.999999999999ap-4, _ctx), _b_3581_3559, _ctx); /*list<double>*/
    _b_3577_3563 = kk_std_core__new_Cons(kk_reuse_null, kk_double_box(0x1.999999999999ap-3, _ctx), _b_3579_3561, _ctx); /*list<double>*/
    _b_3575_3565 = kk_std_core__new_Cons(kk_reuse_null, kk_double_box(0x0p+0, _ctx), _b_3577_3563, _ctx); /*list<double>*/
    _b_3573_3567 = kk_std_core__new_Cons(kk_reuse_null, kk_double_box(0x1.999999999999ap-4, _ctx), _b_3575_3565, _ctx); /*list<double>*/
    _b_3571_3569 = kk_std_core__new_Cons(kk_reuse_null, kk_double_box(0x1.999999999999ap-4, _ctx), _b_3573_3567, _ctx); /*list<double>*/
    kk_model_dash_resources_gaussian__dataset = kk_std_core__new_Cons(kk_reuse_null, kk_double_box(0x0p+0, _ctx), _b_3571_3569, _ctx); /*effects-and-types/data_1d*/
  }
  {
    kk_std_core__list _b_3617_3615;
    kk_std_core__list _b_3619_3613;
    kk_std_core__list _b_3621_3611;
    kk_std_core__list _b_3623_3609;
    kk_std_core__list _b_3625_3607;
    kk_std_core__list _b_3627_3605;
    kk_std_core__list _b_3629_3603;
    kk_std_core__list _b_3631_3601;
    kk_std_core__list _b_3633_3599;
    kk_std_core__list _b_3635_3597;
    kk_std_core__list _b_3637_3595;
    kk_std_core__list _b_3639_3593;
    kk_std_core__list _b_3641_3591;
    kk_std_core__list _b_3643_3589 = kk_std_core__new_Cons(kk_reuse_null, kk_double_box(0x1.4666666666666p2, _ctx), kk_std_core__new_Nil(_ctx), _ctx); /*list<double>*/;
    _b_3641_3591 = kk_std_core__new_Cons(kk_reuse_null, kk_double_box(0x1.4p2, _ctx), _b_3643_3589, _ctx); /*list<double>*/
    _b_3639_3593 = kk_std_core__new_Cons(kk_reuse_null, kk_double_box(0x1.4p2, _ctx), _b_3641_3591, _ctx); /*list<double>*/
    _b_3637_3595 = kk_std_core__new_Cons(kk_reuse_null, kk_double_box(0x1.4p2, _ctx), _b_3639_3593, _ctx); /*list<double>*/
    _b_3635_3597 = kk_std_core__new_Cons(kk_reuse_null, kk_double_box(0x1.4p2, _ctx), _b_3637_3595, _ctx); /*list<double>*/
    _b_3633_3599 = kk_std_core__new_Cons(kk_reuse_null, kk_double_box(0x1.4666666666666p2, _ctx), _b_3635_3597, _ctx); /*list<double>*/
    _b_3631_3601 = kk_std_core__new_Cons(kk_reuse_null, kk_double_box(0x1.4p2, _ctx), _b_3633_3599, _ctx); /*list<double>*/
    _b_3629_3603 = kk_std_core__new_Cons(kk_reuse_null, kk_double_box(0x1.4p2, _ctx), _b_3631_3601, _ctx); /*list<double>*/
    _b_3627_3605 = kk_std_core__new_Cons(kk_reuse_null, kk_double_box(0x1.4p2, _ctx), _b_3629_3603, _ctx); /*list<double>*/
    _b_3625_3607 = kk_std_core__new_Cons(kk_reuse_null, kk_double_box(0x1.4p2, _ctx), _b_3627_3605, _ctx); /*list<double>*/
    _b_3623_3609 = kk_std_core__new_Cons(kk_reuse_null, kk_double_box(0x1.4666666666666p2, _ctx), _b_3625_3607, _ctx); /*list<double>*/
    _b_3621_3611 = kk_std_core__new_Cons(kk_reuse_null, kk_double_box(0x1.4p2, _ctx), _b_3623_3609, _ctx); /*list<double>*/
    _b_3619_3613 = kk_std_core__new_Cons(kk_reuse_null, kk_double_box(0x1.4p2, _ctx), _b_3621_3611, _ctx); /*list<double>*/
    _b_3617_3615 = kk_std_core__new_Cons(kk_reuse_null, kk_double_box(0x1.4p2, _ctx), _b_3619_3613, _ctx); /*list<double>*/
    kk_model_dash_resources_gaussian__five = kk_std_core__new_Cons(kk_reuse_null, kk_double_box(0x1.4p2, _ctx), _b_3617_3615, _ctx); /*effects-and-types/data_1d*/
  }
}
