// Koka generated module: "sequential", koka version: 2.1.2
#include "sequential.h"
 
// monadic lift

kk_std_core__list kk_sequential__mlift739_smc__loop(kk_integer_t i, bool normalize, kk_integer_t step__num, kk_integer_t step__size, kk_std_core__list _y_5, kk_context_t* _ctx) { /* forall<a,e> (i : int, normalize : bool, step_num : int, step_size : int, list<(effects-and-types/exp, (a : int) -> <effects-and-types/yield,effects-and-types/score,exn,effects-and-types/sample,div|e> a)>) -> <exn,effects-and-types/sample,div|e> effects-and-types/histogram<a> */ 
  kk_integer_t _x920 = kk_integer_add(i,(kk_integer_from_small(1)),kk_context()); /*int*/
  kk_std_core__list _x921;
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*std/core/hnd/evv<(<>)>*/;
  kk_std_core__list x = kk_sampling_normalise(_y_5, _ctx); /*effects-and-types/histogram<(a : int) -> <effects-and-types/yield,effects-and-types/score,exn,effects-and-types/sample,div|661> 658>*/;
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  _x921 = x; /*effects-and-types/histogram<(a : int) -> <effects-and-types/yield,effects-and-types/score,exn,effects-and-types/sample,div|661> 658>*/
  return kk_sequential_smc__loop(_x920, _x921, step__num, step__size, normalize, _ctx);
}
 
// monadic lift

kk_std_core__list kk_sequential__mlift740_smc__loop(kk_integer_t i0, bool normalize0, kk_integer_t step__num0, kk_integer_t step__size0, kk_std_core__list _y_7, kk_context_t* _ctx) { /* forall<a,e> (i : int, normalize : bool, step_num : int, step_size : int, list<(effects-and-types/exp, (a : int) -> <effects-and-types/yield,effects-and-types/score,exn,effects-and-types/sample,div|e> a)>) -> <exn,effects-and-types/sample,div|e> effects-and-types/histogram<a> */ 
  kk_integer_t _x922 = kk_integer_add(i0,(kk_integer_from_small(1)),kk_context()); /*int*/
  return kk_sequential_smc__loop(_x922, _y_7, step__num0, step__size0, normalize0, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_sequential__mlift741_smc__loop_fun923__t {
  struct kk_function_s _base;
  kk_integer_t step__size1;
};
static kk_std_core_types__tuple2_ kk_sequential__mlift741_smc__loop_fun923(kk_function_t _fself, kk_std_core_types__tuple2_ wm, kk_context_t* _ctx);
static kk_function_t kk_sequential__new_mlift741_smc__loop_fun923(kk_integer_t step__size1, kk_context_t* _ctx) {
  struct kk_sequential__mlift741_smc__loop_fun923__t* _self = kk_function_alloc_as(struct kk_sequential__mlift741_smc__loop_fun923__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_sequential__mlift741_smc__loop_fun923, kk_context());
  _self->step__size1 = step__size1;
  return &_self->_base;
}



// lift anonymous function
struct kk_sequential__mlift741_smc__loop_fun925__t {
  struct kk_function_s _base;
  kk_box_t _fun_unbox_x784;
  kk_integer_t step__size1;
};
static kk_box_t kk_sequential__mlift741_smc__loop_fun925(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_sequential__new_mlift741_smc__loop_fun925(kk_box_t _fun_unbox_x784, kk_integer_t step__size1, kk_context_t* _ctx) {
  struct kk_sequential__mlift741_smc__loop_fun925__t* _self = kk_function_alloc_as(struct kk_sequential__mlift741_smc__loop_fun925__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_sequential__mlift741_smc__loop_fun925, kk_context());
  _self->_fun_unbox_x784 = _fun_unbox_x784;
  _self->step__size1 = step__size1;
  return &_self->_base;
}



// lift anonymous function
struct kk_sequential__mlift741_smc__loop_fun927__t {
  struct kk_function_s _base;
  kk_box_t _fun_unbox_x784;
  kk_integer_t step__size1;
};
static kk_box_t kk_sequential__mlift741_smc__loop_fun927(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_sequential__new_mlift741_smc__loop_fun927(kk_box_t _fun_unbox_x784, kk_integer_t step__size1, kk_context_t* _ctx) {
  struct kk_sequential__mlift741_smc__loop_fun927__t* _self = kk_function_alloc_as(struct kk_sequential__mlift741_smc__loop_fun927__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_sequential__mlift741_smc__loop_fun927, kk_context());
  _self->_fun_unbox_x784 = _fun_unbox_x784;
  _self->step__size1 = step__size1;
  return &_self->_base;
}

static kk_box_t kk_sequential__mlift741_smc__loop_fun927(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_sequential__mlift741_smc__loop_fun927__t* _self = kk_function_as(struct kk_sequential__mlift741_smc__loop_fun927__t*, _fself);
  kk_box_t _fun_unbox_x784 = _self->_fun_unbox_x784; /* 1 */
  kk_integer_t step__size1 = _self->step__size1; /* int */
  kk_drop_match(_self, {kk_box_dup(_fun_unbox_x784);kk_integer_dup(step__size1);}, {}, _ctx)
  kk_function_t _x928 = kk_function_unbox(_fun_unbox_x784); /*(785) -> <effects-and-types/yield,effects-and-types/score|70> 786*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x928, (_x928, kk_integer_box(step__size1), _ctx));
}


// lift anonymous function
struct kk_sequential__mlift741_smc__loop_fun929__t {
  struct kk_function_s _base;
  kk_function_t _bv_792;
};
static kk_box_t kk_sequential__mlift741_smc__loop_fun929(kk_function_t _fself, kk_box_t _b_793, kk_context_t* _ctx);
static kk_function_t kk_sequential__new_mlift741_smc__loop_fun929(kk_function_t _bv_792, kk_context_t* _ctx) {
  struct kk_sequential__mlift741_smc__loop_fun929__t* _self = kk_function_alloc_as(struct kk_sequential__mlift741_smc__loop_fun929__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_sequential__mlift741_smc__loop_fun929, kk_context());
  _self->_bv_792 = _bv_792;
  return &_self->_base;
}

static kk_box_t kk_sequential__mlift741_smc__loop_fun929(kk_function_t _fself, kk_box_t _b_793, kk_context_t* _ctx) {
  struct kk_sequential__mlift741_smc__loop_fun929__t* _self = kk_function_as(struct kk_sequential__mlift741_smc__loop_fun929__t*, _fself);
  kk_function_t _bv_792 = _self->_bv_792; /* (a : int) -> <effects-and-types/yield,effects-and-types/score|70> 93 */
  kk_drop_match(_self, {kk_function_dup(_bv_792);}, {}, _ctx)
  kk_integer_t _x930 = kk_integer_unbox(_b_793); /*int*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_context_t*), _bv_792, (_bv_792, _x930, _ctx));
}
static kk_box_t kk_sequential__mlift741_smc__loop_fun925(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_sequential__mlift741_smc__loop_fun925__t* _self = kk_function_as(struct kk_sequential__mlift741_smc__loop_fun925__t*, _fself);
  kk_box_t _fun_unbox_x784 = _self->_fun_unbox_x784; /* 1 */
  kk_integer_t step__size1 = _self->step__size1; /* int */
  kk_drop_match(_self, {kk_box_dup(_fun_unbox_x784);kk_integer_dup(step__size1);}, {}, _ctx)
  kk_function_t _x926;
  kk_function_t _bv_792 = kk_handlers_advance(kk_sequential__new_mlift741_smc__loop_fun927(_fun_unbox_x784, step__size1, _ctx), _ctx); /*(a : int) -> <effects-and-types/yield,effects-and-types/score|70> 93*/;
  _x926 = kk_sequential__new_mlift741_smc__loop_fun929(_bv_792, _ctx); /*(790) -> <effects-and-types/yield,effects-and-types/score|70> 93*/
  return kk_function_box(_x926);
}
static kk_std_core_types__tuple2_ kk_sequential__mlift741_smc__loop_fun923(kk_function_t _fself, kk_std_core_types__tuple2_ wm, kk_context_t* _ctx) {
  struct kk_sequential__mlift741_smc__loop_fun923__t* _self = kk_function_as(struct kk_sequential__mlift741_smc__loop_fun923__t*, _fself);
  kk_integer_t step__size1 = _self->step__size1; /* int */
  kk_drop_match(_self, {kk_integer_dup(step__size1);}, {}, _ctx)
  kk_box_t _box_x780 = wm.fst;
  kk_box_t _fun_unbox_x784 = wm.snd;
  kk_effects_dash_and_dash_types__exp w0 = kk_effects_dash_and_dash_types__exp_unbox(_box_x780, NULL);
  return kk_handlers_weighted(w0, kk_sequential__new_mlift741_smc__loop_fun925(_fun_unbox_x784, step__size1, _ctx), _ctx);
}


// lift anonymous function
struct kk_sequential__mlift741_smc__loop_fun931__t {
  struct kk_function_s _base;
  kk_function_t advance__func;
};
static kk_box_t kk_sequential__mlift741_smc__loop_fun931(kk_function_t _fself, kk_box_t _b_799, kk_context_t* _ctx);
static kk_function_t kk_sequential__new_mlift741_smc__loop_fun931(kk_function_t advance__func, kk_context_t* _ctx) {
  struct kk_sequential__mlift741_smc__loop_fun931__t* _self = kk_function_alloc_as(struct kk_sequential__mlift741_smc__loop_fun931__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_sequential__mlift741_smc__loop_fun931, kk_context());
  _self->advance__func = advance__func;
  return &_self->_base;
}

static kk_box_t kk_sequential__mlift741_smc__loop_fun931(kk_function_t _fself, kk_box_t _b_799, kk_context_t* _ctx) {
  struct kk_sequential__mlift741_smc__loop_fun931__t* _self = kk_function_as(struct kk_sequential__mlift741_smc__loop_fun931__t*, _fself);
  kk_function_t advance__func = _self->advance__func; /* forall<a,e> (wm : (effects-and-types/exp, (int) -> <effects-and-types/yield,effects-and-types/score|e> a)) -> e (effects-and-types/exp, (a : int) -> <effects-and-types/yield,effects-and-types/score|e> a) */
  kk_drop_match(_self, {kk_function_dup(advance__func);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x932;
  kk_std_core_types__tuple2_ _x933 = kk_std_core_types__tuple2__unbox(_b_799, _ctx); /*(effects-and-types/exp, (int) -> <effects-and-types/yield,effects-and-types/score,exn,effects-and-types/sample,div|661> 658)*/
  _x932 = kk_function_call(kk_std_core_types__tuple2_, (kk_function_t, kk_std_core_types__tuple2_, kk_context_t*), advance__func, (advance__func, _x933, _ctx)); /*(effects-and-types/exp, (a : int) -> <effects-and-types/yield,effects-and-types/score|70> 93)*/
  return kk_std_core_types__tuple2__box(_x932, _ctx);
}


// lift anonymous function
struct kk_sequential__mlift741_smc__loop_fun935__t {
  struct kk_function_s _base;
  kk_integer_t i1;
  kk_integer_t step__num1;
  kk_integer_t step__size1;
  bool normalize1;
};
static kk_box_t kk_sequential__mlift741_smc__loop_fun935(kk_function_t _fself, kk_box_t _b_803, kk_context_t* _ctx);
static kk_function_t kk_sequential__new_mlift741_smc__loop_fun935(kk_integer_t i1, kk_integer_t step__num1, kk_integer_t step__size1, bool normalize1, kk_context_t* _ctx) {
  struct kk_sequential__mlift741_smc__loop_fun935__t* _self = kk_function_alloc_as(struct kk_sequential__mlift741_smc__loop_fun935__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_sequential__mlift741_smc__loop_fun935, kk_context());
  _self->i1 = i1;
  _self->step__num1 = step__num1;
  _self->step__size1 = step__size1;
  _self->normalize1 = normalize1;
  return &_self->_base;
}

static kk_box_t kk_sequential__mlift741_smc__loop_fun935(kk_function_t _fself, kk_box_t _b_803, kk_context_t* _ctx) {
  struct kk_sequential__mlift741_smc__loop_fun935__t* _self = kk_function_as(struct kk_sequential__mlift741_smc__loop_fun935__t*, _fself);
  kk_integer_t i1 = _self->i1; /* int */
  kk_integer_t step__num1 = _self->step__num1; /* int */
  kk_integer_t step__size1 = _self->step__size1; /* int */
  bool normalize1 = _self->normalize1; /* bool */
  kk_drop_match(_self, {kk_integer_dup(i1);kk_integer_dup(step__num1);kk_integer_dup(step__size1);;}, {}, _ctx)
  kk_std_core__list _x936;
  kk_std_core__list _x937 = kk_std_core__list_unbox(_b_803, _ctx); /*list<(effects-and-types/exp, (a : int) -> <effects-and-types/yield,effects-and-types/score,exn,effects-and-types/sample,div|661> 658)>*/
  _x936 = kk_sequential__mlift739_smc__loop(i1, normalize1, step__num1, step__size1, _x937, _ctx); /*effects-and-types/histogram<658>*/
  return kk_std_core__list_box(_x936, _ctx);
}


// lift anonymous function
struct kk_sequential__mlift741_smc__loop_fun938__t {
  struct kk_function_s _base;
  kk_function_t advance__func;
};
static kk_box_t kk_sequential__mlift741_smc__loop_fun938(kk_function_t _fself, kk_box_t _b_806, kk_context_t* _ctx);
static kk_function_t kk_sequential__new_mlift741_smc__loop_fun938(kk_function_t advance__func, kk_context_t* _ctx) {
  struct kk_sequential__mlift741_smc__loop_fun938__t* _self = kk_function_alloc_as(struct kk_sequential__mlift741_smc__loop_fun938__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_sequential__mlift741_smc__loop_fun938, kk_context());
  _self->advance__func = advance__func;
  return &_self->_base;
}

static kk_box_t kk_sequential__mlift741_smc__loop_fun938(kk_function_t _fself, kk_box_t _b_806, kk_context_t* _ctx) {
  struct kk_sequential__mlift741_smc__loop_fun938__t* _self = kk_function_as(struct kk_sequential__mlift741_smc__loop_fun938__t*, _fself);
  kk_function_t advance__func = _self->advance__func; /* forall<a,e> (wm : (effects-and-types/exp, (int) -> <effects-and-types/yield,effects-and-types/score|e> a)) -> e (effects-and-types/exp, (a : int) -> <effects-and-types/yield,effects-and-types/score|e> a) */
  kk_drop_match(_self, {kk_function_dup(advance__func);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x939;
  kk_std_core_types__tuple2_ _x940 = kk_std_core_types__tuple2__unbox(_b_806, _ctx); /*(effects-and-types/exp, (int) -> <effects-and-types/yield,effects-and-types/score,exn,effects-and-types/sample,div|661> 658)*/
  _x939 = kk_function_call(kk_std_core_types__tuple2_, (kk_function_t, kk_std_core_types__tuple2_, kk_context_t*), advance__func, (advance__func, _x940, _ctx)); /*(effects-and-types/exp, (a : int) -> <effects-and-types/yield,effects-and-types/score|70> 93)*/
  return kk_std_core_types__tuple2__box(_x939, _ctx);
}


// lift anonymous function
struct kk_sequential__mlift741_smc__loop_fun942__t {
  struct kk_function_s _base;
  kk_integer_t i1;
  kk_integer_t step__num1;
  kk_integer_t step__size1;
  bool normalize1;
};
static kk_box_t kk_sequential__mlift741_smc__loop_fun942(kk_function_t _fself, kk_box_t _b_810, kk_context_t* _ctx);
static kk_function_t kk_sequential__new_mlift741_smc__loop_fun942(kk_integer_t i1, kk_integer_t step__num1, kk_integer_t step__size1, bool normalize1, kk_context_t* _ctx) {
  struct kk_sequential__mlift741_smc__loop_fun942__t* _self = kk_function_alloc_as(struct kk_sequential__mlift741_smc__loop_fun942__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_sequential__mlift741_smc__loop_fun942, kk_context());
  _self->i1 = i1;
  _self->step__num1 = step__num1;
  _self->step__size1 = step__size1;
  _self->normalize1 = normalize1;
  return &_self->_base;
}

static kk_box_t kk_sequential__mlift741_smc__loop_fun942(kk_function_t _fself, kk_box_t _b_810, kk_context_t* _ctx) {
  struct kk_sequential__mlift741_smc__loop_fun942__t* _self = kk_function_as(struct kk_sequential__mlift741_smc__loop_fun942__t*, _fself);
  kk_integer_t i1 = _self->i1; /* int */
  kk_integer_t step__num1 = _self->step__num1; /* int */
  kk_integer_t step__size1 = _self->step__size1; /* int */
  bool normalize1 = _self->normalize1; /* bool */
  kk_drop_match(_self, {kk_integer_dup(i1);kk_integer_dup(step__num1);kk_integer_dup(step__size1);;}, {}, _ctx)
  kk_std_core__list _x943;
  kk_std_core__list _x944 = kk_std_core__list_unbox(_b_810, _ctx); /*list<(effects-and-types/exp, (a : int) -> <effects-and-types/yield,effects-and-types/score,exn,effects-and-types/sample,div|661> 658)>*/
  _x943 = kk_sequential__mlift740_smc__loop(i1, normalize1, step__num1, step__size1, _x944, _ctx); /*effects-and-types/histogram<658>*/
  return kk_std_core__list_box(_x943, _ctx);
}

kk_std_core__list kk_sequential__mlift741_smc__loop(kk_integer_t i1, bool normalize1, kk_integer_t step__num1, kk_integer_t step__size1, kk_std_core__list resampled__histogram, kk_context_t* _ctx) { /* forall<a,e> (i : int, normalize : bool, step_num : int, step_size : int, resampled_histogram : effects-and-types/histogram<(int) -> <exn,effects-and-types/yield,effects-and-types/score,effects-and-types/sample,div|e> a>) -> <exn,effects-and-types/sample,div|e> effects-and-types/histogram<a> */ 
  kk_function_t advance__func;
  kk_integer_dup(step__size1);
  advance__func = kk_sequential__new_mlift741_smc__loop_fun923(step__size1, _ctx); /*forall<a,e> (wm : (effects-and-types/exp, (int) -> <effects-and-types/yield,effects-and-types/score|e> a)) -> e (effects-and-types/exp, (a : int) -> <effects-and-types/yield,effects-and-types/score|e> a)*/
  if (normalize1) {
    kk_std_core__list x_746 = kk_std_core_map_5(resampled__histogram, kk_sequential__new_mlift741_smc__loop_fun931(advance__func, _ctx), _ctx); /*list<(effects-and-types/exp, (a : int) -> <effects-and-types/yield,effects-and-types/score,exn,effects-and-types/sample,div|661> 658)>*/;
    if (kk_yielding(kk_context())) {
      kk_std_core__list_drop(x_746, _ctx);
      kk_box_t _x934 = kk_std_core_hnd_yield_extend(kk_sequential__new_mlift741_smc__loop_fun935(i1, step__num1, step__size1, normalize1, _ctx), _ctx); /*2*/
      return kk_std_core__list_unbox(_x934, _ctx);
    }
    return kk_sequential__mlift739_smc__loop(i1, normalize1, step__num1, step__size1, x_746, _ctx);
  }
  kk_std_core__list x0_748 = kk_std_core_map_5(resampled__histogram, kk_sequential__new_mlift741_smc__loop_fun938(advance__func, _ctx), _ctx); /*list<(effects-and-types/exp, (a : int) -> <effects-and-types/yield,effects-and-types/score,exn,effects-and-types/sample,div|661> 658)>*/;
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x0_748, _ctx);
    kk_box_t _x941 = kk_std_core_hnd_yield_extend(kk_sequential__new_mlift741_smc__loop_fun942(i1, step__num1, step__size1, normalize1, _ctx), _ctx); /*2*/
    return kk_std_core__list_unbox(_x941, _ctx);
  }
  return kk_sequential__mlift740_smc__loop(i1, normalize1, step__num1, step__size1, x0_748, _ctx);
}
 
// monadic lift

kk_std_core__list kk_sequential__mlift742_smc__loop(kk_std_core__list _y_14, kk_context_t* _ctx) { /* forall<a,e> (list<(effects-and-types/exp, a)>) -> <exn,effects-and-types/sample,div|e> effects-and-types/histogram<a> */ 
  kk_evv_t w1 = kk_evv_swap_create0(kk_context()); /*std/core/hnd/evv<(<>)>*/;
  kk_std_core__list x0 = kk_sampling_normalise(_y_14, _ctx); /*effects-and-types/histogram<658>*/;
  kk_unit_t keep0 = kk_Unit;
  kk_evv_set(w1,kk_context());
  return x0;
}


// lift anonymous function
struct kk_sequential_smc__loop_fun951__t {
  struct kk_function_s _base;
};
static kk_box_t kk_sequential_smc__loop_fun951(kk_function_t _fself, kk_box_t _b_822, kk_context_t* _ctx);
static kk_function_t kk_sequential_new_smc__loop_fun951(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_sequential_smc__loop_fun951, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_sequential_smc__loop_fun951(kk_function_t _fself, kk_box_t _b_822, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core__list _x952;
  kk_std_core__list _x953 = kk_std_core__list_unbox(_b_822, _ctx); /*effects-and-types/histogram<(int) -> <exn,effects-and-types/yield,effects-and-types/score,effects-and-types/sample,div|661> 658>*/
  _x952 = kk_sampling_resample(_x953, _ctx); /*effects-and-types/histogram<736>*/
  return kk_std_core__list_box(_x952, _ctx);
}


// lift anonymous function
struct kk_sequential_smc__loop_fun955__t {
  struct kk_function_s _base;
  kk_integer_t i2;
  kk_integer_t step__num2;
  kk_integer_t step__size2;
  bool normalize2;
};
static kk_box_t kk_sequential_smc__loop_fun955(kk_function_t _fself, kk_box_t _b_831, kk_context_t* _ctx);
static kk_function_t kk_sequential_new_smc__loop_fun955(kk_integer_t i2, kk_integer_t step__num2, kk_integer_t step__size2, bool normalize2, kk_context_t* _ctx) {
  struct kk_sequential_smc__loop_fun955__t* _self = kk_function_alloc_as(struct kk_sequential_smc__loop_fun955__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_sequential_smc__loop_fun955, kk_context());
  _self->i2 = i2;
  _self->step__num2 = step__num2;
  _self->step__size2 = step__size2;
  _self->normalize2 = normalize2;
  return &_self->_base;
}

static kk_box_t kk_sequential_smc__loop_fun955(kk_function_t _fself, kk_box_t _b_831, kk_context_t* _ctx) {
  struct kk_sequential_smc__loop_fun955__t* _self = kk_function_as(struct kk_sequential_smc__loop_fun955__t*, _fself);
  kk_integer_t i2 = _self->i2; /* int */
  kk_integer_t step__num2 = _self->step__num2; /* int */
  kk_integer_t step__size2 = _self->step__size2; /* int */
  bool normalize2 = _self->normalize2; /* bool */
  kk_drop_match(_self, {kk_integer_dup(i2);kk_integer_dup(step__num2);kk_integer_dup(step__size2);;}, {}, _ctx)
  kk_std_core__list _x956;
  kk_std_core__list _x957 = kk_std_core__list_unbox(_b_831, _ctx); /*effects-and-types/histogram<(int) -> <exn,effects-and-types/yield,effects-and-types/score,effects-and-types/sample,div|661> 658>*/
  _x956 = kk_sequential__mlift741_smc__loop(i2, normalize2, step__num2, step__size2, _x957, _ctx); /*effects-and-types/histogram<658>*/
  return kk_std_core__list_box(_x956, _ctx);
}


// lift anonymous function
struct kk_sequential_smc__loop_fun958__t {
  struct kk_function_s _base;
  kk_integer_t step__size2;
};
static kk_std_core_types__tuple2_ kk_sequential_smc__loop_fun958(kk_function_t _fself, kk_std_core_types__tuple2_ wm0, kk_context_t* _ctx);
static kk_function_t kk_sequential_new_smc__loop_fun958(kk_integer_t step__size2, kk_context_t* _ctx) {
  struct kk_sequential_smc__loop_fun958__t* _self = kk_function_alloc_as(struct kk_sequential_smc__loop_fun958__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_sequential_smc__loop_fun958, kk_context());
  _self->step__size2 = step__size2;
  return &_self->_base;
}



// lift anonymous function
struct kk_sequential_smc__loop_fun960__t {
  struct kk_function_s _base;
  kk_box_t _fun_unbox_x836;
  kk_integer_t step__size2;
};
static kk_box_t kk_sequential_smc__loop_fun960(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_sequential_new_smc__loop_fun960(kk_box_t _fun_unbox_x836, kk_integer_t step__size2, kk_context_t* _ctx) {
  struct kk_sequential_smc__loop_fun960__t* _self = kk_function_alloc_as(struct kk_sequential_smc__loop_fun960__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_sequential_smc__loop_fun960, kk_context());
  _self->_fun_unbox_x836 = _fun_unbox_x836;
  _self->step__size2 = step__size2;
  return &_self->_base;
}



// lift anonymous function
struct kk_sequential_smc__loop_fun962__t {
  struct kk_function_s _base;
  kk_box_t _fun_unbox_x836;
  kk_integer_t step__size2;
};
static kk_box_t kk_sequential_smc__loop_fun962(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_sequential_new_smc__loop_fun962(kk_box_t _fun_unbox_x836, kk_integer_t step__size2, kk_context_t* _ctx) {
  struct kk_sequential_smc__loop_fun962__t* _self = kk_function_alloc_as(struct kk_sequential_smc__loop_fun962__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_sequential_smc__loop_fun962, kk_context());
  _self->_fun_unbox_x836 = _fun_unbox_x836;
  _self->step__size2 = step__size2;
  return &_self->_base;
}

static kk_box_t kk_sequential_smc__loop_fun962(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_sequential_smc__loop_fun962__t* _self = kk_function_as(struct kk_sequential_smc__loop_fun962__t*, _fself);
  kk_box_t _fun_unbox_x836 = _self->_fun_unbox_x836; /* 1 */
  kk_integer_t step__size2 = _self->step__size2; /* int */
  kk_drop_match(_self, {kk_box_dup(_fun_unbox_x836);kk_integer_dup(step__size2);}, {}, _ctx)
  kk_function_t _x963 = kk_function_unbox(_fun_unbox_x836); /*(837) -> <effects-and-types/yield,effects-and-types/score|70> 838*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x963, (_x963, kk_integer_box(step__size2), _ctx));
}


// lift anonymous function
struct kk_sequential_smc__loop_fun964__t {
  struct kk_function_s _base;
  kk_function_t _bv_844;
};
static kk_box_t kk_sequential_smc__loop_fun964(kk_function_t _fself, kk_box_t _b_845, kk_context_t* _ctx);
static kk_function_t kk_sequential_new_smc__loop_fun964(kk_function_t _bv_844, kk_context_t* _ctx) {
  struct kk_sequential_smc__loop_fun964__t* _self = kk_function_alloc_as(struct kk_sequential_smc__loop_fun964__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_sequential_smc__loop_fun964, kk_context());
  _self->_bv_844 = _bv_844;
  return &_self->_base;
}

static kk_box_t kk_sequential_smc__loop_fun964(kk_function_t _fself, kk_box_t _b_845, kk_context_t* _ctx) {
  struct kk_sequential_smc__loop_fun964__t* _self = kk_function_as(struct kk_sequential_smc__loop_fun964__t*, _fself);
  kk_function_t _bv_844 = _self->_bv_844; /* (a : int) -> <effects-and-types/yield,effects-and-types/score|70> 93 */
  kk_drop_match(_self, {kk_function_dup(_bv_844);}, {}, _ctx)
  kk_integer_t _x965 = kk_integer_unbox(_b_845); /*int*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_context_t*), _bv_844, (_bv_844, _x965, _ctx));
}
static kk_box_t kk_sequential_smc__loop_fun960(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_sequential_smc__loop_fun960__t* _self = kk_function_as(struct kk_sequential_smc__loop_fun960__t*, _fself);
  kk_box_t _fun_unbox_x836 = _self->_fun_unbox_x836; /* 1 */
  kk_integer_t step__size2 = _self->step__size2; /* int */
  kk_drop_match(_self, {kk_box_dup(_fun_unbox_x836);kk_integer_dup(step__size2);}, {}, _ctx)
  kk_function_t _x961;
  kk_function_t _bv_844 = kk_handlers_advance(kk_sequential_new_smc__loop_fun962(_fun_unbox_x836, step__size2, _ctx), _ctx); /*(a : int) -> <effects-and-types/yield,effects-and-types/score|70> 93*/;
  _x961 = kk_sequential_new_smc__loop_fun964(_bv_844, _ctx); /*(842) -> <effects-and-types/yield,effects-and-types/score|70> 93*/
  return kk_function_box(_x961);
}
static kk_std_core_types__tuple2_ kk_sequential_smc__loop_fun958(kk_function_t _fself, kk_std_core_types__tuple2_ wm0, kk_context_t* _ctx) {
  struct kk_sequential_smc__loop_fun958__t* _self = kk_function_as(struct kk_sequential_smc__loop_fun958__t*, _fself);
  kk_integer_t step__size2 = _self->step__size2; /* int */
  kk_drop_match(_self, {kk_integer_dup(step__size2);}, {}, _ctx)
  kk_box_t _box_x832 = wm0.fst;
  kk_box_t _fun_unbox_x836 = wm0.snd;
  kk_effects_dash_and_dash_types__exp w2 = kk_effects_dash_and_dash_types__exp_unbox(_box_x832, NULL);
  return kk_handlers_weighted(w2, kk_sequential_new_smc__loop_fun960(_fun_unbox_x836, step__size2, _ctx), _ctx);
}


// lift anonymous function
struct kk_sequential_smc__loop_fun966__t {
  struct kk_function_s _base;
  kk_function_t advance__func0;
};
static kk_box_t kk_sequential_smc__loop_fun966(kk_function_t _fself, kk_box_t _b_851, kk_context_t* _ctx);
static kk_function_t kk_sequential_new_smc__loop_fun966(kk_function_t advance__func0, kk_context_t* _ctx) {
  struct kk_sequential_smc__loop_fun966__t* _self = kk_function_alloc_as(struct kk_sequential_smc__loop_fun966__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_sequential_smc__loop_fun966, kk_context());
  _self->advance__func0 = advance__func0;
  return &_self->_base;
}

static kk_box_t kk_sequential_smc__loop_fun966(kk_function_t _fself, kk_box_t _b_851, kk_context_t* _ctx) {
  struct kk_sequential_smc__loop_fun966__t* _self = kk_function_as(struct kk_sequential_smc__loop_fun966__t*, _fself);
  kk_function_t advance__func0 = _self->advance__func0; /* forall<a,e> (wm : (effects-and-types/exp, (int) -> <effects-and-types/yield,effects-and-types/score|e> a)) -> e (effects-and-types/exp, (a : int) -> <effects-and-types/yield,effects-and-types/score|e> a) */
  kk_drop_match(_self, {kk_function_dup(advance__func0);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x967;
  kk_std_core_types__tuple2_ _x968 = kk_std_core_types__tuple2__unbox(_b_851, _ctx); /*(effects-and-types/exp, (int) -> <effects-and-types/yield,effects-and-types/score,exn,effects-and-types/sample,div|661> 658)*/
  _x967 = kk_function_call(kk_std_core_types__tuple2_, (kk_function_t, kk_std_core_types__tuple2_, kk_context_t*), advance__func0, (advance__func0, _x968, _ctx)); /*(effects-and-types/exp, (a : int) -> <effects-and-types/yield,effects-and-types/score|70> 93)*/
  return kk_std_core_types__tuple2__box(_x967, _ctx);
}


// lift anonymous function
struct kk_sequential_smc__loop_fun970__t {
  struct kk_function_s _base;
  kk_integer_t i2;
  kk_integer_t step__num2;
  kk_integer_t step__size2;
  bool normalize2;
};
static kk_box_t kk_sequential_smc__loop_fun970(kk_function_t _fself, kk_box_t _b_855, kk_context_t* _ctx);
static kk_function_t kk_sequential_new_smc__loop_fun970(kk_integer_t i2, kk_integer_t step__num2, kk_integer_t step__size2, bool normalize2, kk_context_t* _ctx) {
  struct kk_sequential_smc__loop_fun970__t* _self = kk_function_alloc_as(struct kk_sequential_smc__loop_fun970__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_sequential_smc__loop_fun970, kk_context());
  _self->i2 = i2;
  _self->step__num2 = step__num2;
  _self->step__size2 = step__size2;
  _self->normalize2 = normalize2;
  return &_self->_base;
}

static kk_box_t kk_sequential_smc__loop_fun970(kk_function_t _fself, kk_box_t _b_855, kk_context_t* _ctx) {
  struct kk_sequential_smc__loop_fun970__t* _self = kk_function_as(struct kk_sequential_smc__loop_fun970__t*, _fself);
  kk_integer_t i2 = _self->i2; /* int */
  kk_integer_t step__num2 = _self->step__num2; /* int */
  kk_integer_t step__size2 = _self->step__size2; /* int */
  bool normalize2 = _self->normalize2; /* bool */
  kk_drop_match(_self, {kk_integer_dup(i2);kk_integer_dup(step__num2);kk_integer_dup(step__size2);;}, {}, _ctx)
  kk_std_core__list _x971;
  kk_std_core__list _x972 = kk_std_core__list_unbox(_b_855, _ctx); /*list<(effects-and-types/exp, (a : int) -> <effects-and-types/yield,effects-and-types/score,exn,effects-and-types/sample,div|661> 658)>*/
  _x971 = kk_sequential__mlift739_smc__loop(i2, normalize2, step__num2, step__size2, _x972, _ctx); /*effects-and-types/histogram<658>*/
  return kk_std_core__list_box(_x971, _ctx);
}


// lift anonymous function
struct kk_sequential_smc__loop_fun975__t {
  struct kk_function_s _base;
  kk_function_t advance__func0;
};
static kk_box_t kk_sequential_smc__loop_fun975(kk_function_t _fself, kk_box_t _b_858, kk_context_t* _ctx);
static kk_function_t kk_sequential_new_smc__loop_fun975(kk_function_t advance__func0, kk_context_t* _ctx) {
  struct kk_sequential_smc__loop_fun975__t* _self = kk_function_alloc_as(struct kk_sequential_smc__loop_fun975__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_sequential_smc__loop_fun975, kk_context());
  _self->advance__func0 = advance__func0;
  return &_self->_base;
}

static kk_box_t kk_sequential_smc__loop_fun975(kk_function_t _fself, kk_box_t _b_858, kk_context_t* _ctx) {
  struct kk_sequential_smc__loop_fun975__t* _self = kk_function_as(struct kk_sequential_smc__loop_fun975__t*, _fself);
  kk_function_t advance__func0 = _self->advance__func0; /* forall<a,e> (wm : (effects-and-types/exp, (int) -> <effects-and-types/yield,effects-and-types/score|e> a)) -> e (effects-and-types/exp, (a : int) -> <effects-and-types/yield,effects-and-types/score|e> a) */
  kk_drop_match(_self, {kk_function_dup(advance__func0);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x976;
  kk_std_core_types__tuple2_ _x977 = kk_std_core_types__tuple2__unbox(_b_858, _ctx); /*(effects-and-types/exp, (int) -> <effects-and-types/yield,effects-and-types/score,exn,effects-and-types/sample,div|661> 658)*/
  _x976 = kk_function_call(kk_std_core_types__tuple2_, (kk_function_t, kk_std_core_types__tuple2_, kk_context_t*), advance__func0, (advance__func0, _x977, _ctx)); /*(effects-and-types/exp, (a : int) -> <effects-and-types/yield,effects-and-types/score|70> 93)*/
  return kk_std_core_types__tuple2__box(_x976, _ctx);
}


// lift anonymous function
struct kk_sequential_smc__loop_fun979__t {
  struct kk_function_s _base;
  kk_integer_t i2;
  kk_integer_t step__num2;
  kk_integer_t step__size2;
  bool normalize2;
};
static kk_box_t kk_sequential_smc__loop_fun979(kk_function_t _fself, kk_box_t _b_862, kk_context_t* _ctx);
static kk_function_t kk_sequential_new_smc__loop_fun979(kk_integer_t i2, kk_integer_t step__num2, kk_integer_t step__size2, bool normalize2, kk_context_t* _ctx) {
  struct kk_sequential_smc__loop_fun979__t* _self = kk_function_alloc_as(struct kk_sequential_smc__loop_fun979__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_sequential_smc__loop_fun979, kk_context());
  _self->i2 = i2;
  _self->step__num2 = step__num2;
  _self->step__size2 = step__size2;
  _self->normalize2 = normalize2;
  return &_self->_base;
}

static kk_box_t kk_sequential_smc__loop_fun979(kk_function_t _fself, kk_box_t _b_862, kk_context_t* _ctx) {
  struct kk_sequential_smc__loop_fun979__t* _self = kk_function_as(struct kk_sequential_smc__loop_fun979__t*, _fself);
  kk_integer_t i2 = _self->i2; /* int */
  kk_integer_t step__num2 = _self->step__num2; /* int */
  kk_integer_t step__size2 = _self->step__size2; /* int */
  bool normalize2 = _self->normalize2; /* bool */
  kk_drop_match(_self, {kk_integer_dup(i2);kk_integer_dup(step__num2);kk_integer_dup(step__size2);;}, {}, _ctx)
  kk_std_core__list _x980;
  kk_std_core__list _x981 = kk_std_core__list_unbox(_b_862, _ctx); /*list<(effects-and-types/exp, (a : int) -> <effects-and-types/yield,effects-and-types/score,exn,effects-and-types/sample,div|661> 658)>*/
  _x980 = kk_sequential__mlift740_smc__loop(i2, normalize2, step__num2, step__size2, _x981, _ctx); /*effects-and-types/histogram<658>*/
  return kk_std_core__list_box(_x980, _ctx);
}


// lift anonymous function
struct kk_sequential_smc__loop_fun983__t {
  struct kk_function_s _base;
};
static kk_std_core_types__tuple2_ kk_sequential_smc__loop_fun983(kk_function_t _fself, kk_std_core_types__tuple2_ wm00, kk_context_t* _ctx);
static kk_function_t kk_sequential_new_smc__loop_fun983(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_sequential_smc__loop_fun983, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_sequential_smc__loop_fun985__t {
  struct kk_function_s _base;
  kk_box_t _fun_unbox_x867;
};
static kk_box_t kk_sequential_smc__loop_fun985(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_sequential_new_smc__loop_fun985(kk_box_t _fun_unbox_x867, kk_context_t* _ctx) {
  struct kk_sequential_smc__loop_fun985__t* _self = kk_function_alloc_as(struct kk_sequential_smc__loop_fun985__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_sequential_smc__loop_fun985, kk_context());
  _self->_fun_unbox_x867 = _fun_unbox_x867;
  return &_self->_base;
}



// lift anonymous function
struct kk_sequential_smc__loop_fun988__t {
  struct kk_function_s _base;
};
static kk_box_t kk_sequential_smc__loop_fun988(kk_function_t _fself, kk_std_core_hnd__marker _b_872, kk_std_core_hnd__ev _b_873, kk_context_t* _ctx);
static kk_function_t kk_sequential_new_smc__loop_fun988(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_sequential_smc__loop_fun988, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_sequential_smc__loop_fun988(kk_function_t _fself, kk_std_core_hnd__marker _b_872, kk_std_core_hnd__ev _b_873, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core_hnd__ev_dropn(_b_873, ((int32_t)3), _ctx);
  return kk_unit_box(kk_Unit);
}


// lift anonymous function
struct kk_sequential_smc__loop_fun989__t {
  struct kk_function_s _base;
};
static kk_box_t kk_sequential_smc__loop_fun989(kk_function_t _fself, kk_box_t _x, kk_context_t* _ctx);
static kk_function_t kk_sequential_new_smc__loop_fun989(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_sequential_smc__loop_fun989, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_sequential_smc__loop_fun989(kk_function_t _fself, kk_box_t _x, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return _x;
}


// lift anonymous function
struct kk_sequential_smc__loop_fun990__t {
  struct kk_function_s _base;
  kk_box_t _fun_unbox_x867;
};
static kk_box_t kk_sequential_smc__loop_fun990(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_sequential_new_smc__loop_fun990(kk_box_t _fun_unbox_x867, kk_context_t* _ctx) {
  struct kk_sequential_smc__loop_fun990__t* _self = kk_function_alloc_as(struct kk_sequential_smc__loop_fun990__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_sequential_smc__loop_fun990, kk_context());
  _self->_fun_unbox_x867 = _fun_unbox_x867;
  return &_self->_base;
}

static kk_box_t kk_sequential_smc__loop_fun990(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_sequential_smc__loop_fun990__t* _self = kk_function_as(struct kk_sequential_smc__loop_fun990__t*, _fself);
  kk_box_t _fun_unbox_x867 = _self->_fun_unbox_x867; /* 1 */
  kk_drop_match(_self, {kk_box_dup(_fun_unbox_x867);}, {}, _ctx)
  kk_function_t _x991 = kk_function_unbox(_fun_unbox_x867); /*(868) -> <effects-and-types/yield,effects-and-types/score,exn,effects-and-types/sample,div|661> 869*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x991, (_x991, kk_integer_box(kk_integer_from_small(0)), _ctx));
}
static kk_box_t kk_sequential_smc__loop_fun985(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_sequential_smc__loop_fun985__t* _self = kk_function_as(struct kk_sequential_smc__loop_fun985__t*, _fself);
  kk_box_t _fun_unbox_x867 = _self->_fun_unbox_x867; /* 1 */
  kk_drop_match(_self, {kk_box_dup(_fun_unbox_x867);}, {}, _ctx)
  kk_effects_dash_and_dash_types__hnd_yield _x986;
  kk_std_core_hnd__clause0 _x987 = kk_std_core_hnd__new_Clause0(kk_sequential_new_smc__loop_fun988(_ctx), _ctx); /*std/core/hnd/clause0<11,12,13,14>*/
  _x986 = kk_effects_dash_and_dash_types__new_Hnd_yield(kk_reuse_null, _x987, _ctx); /*effects-and-types/.hnd-yield<25,26>*/
  return kk_effects_dash_and_dash_types__handle_yield(((int32_t)1), _x986, kk_sequential_new_smc__loop_fun989(_ctx), kk_sequential_new_smc__loop_fun990(_fun_unbox_x867, _ctx), _ctx);
}
static kk_std_core_types__tuple2_ kk_sequential_smc__loop_fun983(kk_function_t _fself, kk_std_core_types__tuple2_ wm00, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_box_t _box_x863 = wm00.fst;
  kk_box_t _fun_unbox_x867 = wm00.snd;
  kk_effects_dash_and_dash_types__exp w000 = kk_effects_dash_and_dash_types__exp_unbox(_box_x863, NULL);
  return kk_handlers_weighted(w000, kk_sequential_new_smc__loop_fun985(_fun_unbox_x867, _ctx), _ctx);
}


// lift anonymous function
struct kk_sequential_smc__loop_fun992__t {
  struct kk_function_s _base;
  kk_function_t finalize__func;
};
static kk_box_t kk_sequential_smc__loop_fun992(kk_function_t _fself, kk_box_t _b_880, kk_context_t* _ctx);
static kk_function_t kk_sequential_new_smc__loop_fun992(kk_function_t finalize__func, kk_context_t* _ctx) {
  struct kk_sequential_smc__loop_fun992__t* _self = kk_function_alloc_as(struct kk_sequential_smc__loop_fun992__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_sequential_smc__loop_fun992, kk_context());
  _self->finalize__func = finalize__func;
  return &_self->_base;
}

static kk_box_t kk_sequential_smc__loop_fun992(kk_function_t _fself, kk_box_t _b_880, kk_context_t* _ctx) {
  struct kk_sequential_smc__loop_fun992__t* _self = kk_function_as(struct kk_sequential_smc__loop_fun992__t*, _fself);
  kk_function_t finalize__func = _self->finalize__func; /* (wm : (effects-and-types/exp, (int) -> <effects-and-types/yield,effects-and-types/score,exn,effects-and-types/sample,div|661> 658)) -> <exn,effects-and-types/sample,div|661> (effects-and-types/exp, 658) */
  kk_drop_match(_self, {kk_function_dup(finalize__func);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x993;
  kk_std_core_types__tuple2_ _x994 = kk_std_core_types__tuple2__unbox(_b_880, _ctx); /*(effects-and-types/exp, (int) -> <effects-and-types/yield,effects-and-types/score,exn,effects-and-types/sample,div|661> 658)*/
  _x993 = kk_function_call(kk_std_core_types__tuple2_, (kk_function_t, kk_std_core_types__tuple2_, kk_context_t*), finalize__func, (finalize__func, _x994, _ctx)); /*(effects-and-types/exp, 658)*/
  return kk_std_core_types__tuple2__box(_x993, _ctx);
}


// lift anonymous function
struct kk_sequential_smc__loop_fun996__t {
  struct kk_function_s _base;
};
static kk_box_t kk_sequential_smc__loop_fun996(kk_function_t _fself, kk_box_t _b_884, kk_context_t* _ctx);
static kk_function_t kk_sequential_new_smc__loop_fun996(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_sequential_smc__loop_fun996, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_sequential_smc__loop_fun996(kk_function_t _fself, kk_box_t _b_884, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core__list _x997;
  kk_std_core__list _x998 = kk_std_core__list_unbox(_b_884, _ctx); /*list<(effects-and-types/exp, 658)>*/
  _x997 = kk_sequential__mlift742_smc__loop(_x998, _ctx); /*effects-and-types/histogram<658>*/
  return kk_std_core__list_box(_x997, _ctx);
}


// lift anonymous function
struct kk_sequential_smc__loop_fun999__t {
  struct kk_function_s _base;
  kk_function_t finalize__func;
};
static kk_box_t kk_sequential_smc__loop_fun999(kk_function_t _fself, kk_box_t _b_887, kk_context_t* _ctx);
static kk_function_t kk_sequential_new_smc__loop_fun999(kk_function_t finalize__func, kk_context_t* _ctx) {
  struct kk_sequential_smc__loop_fun999__t* _self = kk_function_alloc_as(struct kk_sequential_smc__loop_fun999__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_sequential_smc__loop_fun999, kk_context());
  _self->finalize__func = finalize__func;
  return &_self->_base;
}

static kk_box_t kk_sequential_smc__loop_fun999(kk_function_t _fself, kk_box_t _b_887, kk_context_t* _ctx) {
  struct kk_sequential_smc__loop_fun999__t* _self = kk_function_as(struct kk_sequential_smc__loop_fun999__t*, _fself);
  kk_function_t finalize__func = _self->finalize__func; /* (wm : (effects-and-types/exp, (int) -> <effects-and-types/yield,effects-and-types/score,exn,effects-and-types/sample,div|661> 658)) -> <exn,effects-and-types/sample,div|661> (effects-and-types/exp, 658) */
  kk_drop_match(_self, {kk_function_dup(finalize__func);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x1000;
  kk_std_core_types__tuple2_ _x1001 = kk_std_core_types__tuple2__unbox(_b_887, _ctx); /*(effects-and-types/exp, (int) -> <effects-and-types/yield,effects-and-types/score,exn,effects-and-types/sample,div|661> 658)*/
  _x1000 = kk_function_call(kk_std_core_types__tuple2_, (kk_function_t, kk_std_core_types__tuple2_, kk_context_t*), finalize__func, (finalize__func, _x1001, _ctx)); /*(effects-and-types/exp, 658)*/
  return kk_std_core_types__tuple2__box(_x1000, _ctx);
}

kk_std_core__list kk_sequential_smc__loop(kk_integer_t i2, kk_std_core__list populated__hist, kk_integer_t step__num2, kk_integer_t step__size2, bool normalize2, kk_context_t* _ctx) { /* forall<a,e> (i : int, populated_hist : effects-and-types/histogram<(int) -> <exn,effects-and-types/yield,effects-and-types/score,effects-and-types/sample,div|e> a>, step_num : int, step_size : int, normalize : bool) -> <pure,effects-and-types/sample|e> effects-and-types/histogram<a> */ 
  kk__tailcall: ;
  bool _match_913;
  kk_integer_t _x945 = kk_integer_dup(i2); /*int*/
  kk_integer_t _x946 = kk_integer_dup(step__num2); /*int*/
  _match_913 = kk_integer_lt(_x945,_x946,kk_context()); /*bool*/
  if (_match_913) {
    kk_std_core__list x_752;
    kk_vector_t _b_823_819;
    kk_std_core__list _x947;
    size_t _b_826_817;
    kk_std_core_hnd__htag _x948 = kk_std_core_hnd__htag_dup(kk_std_core__tag_exn); /*std/core/hnd/htag<.hnd-exn>*/
    _b_826_817 = kk_std_core_hnd__evv_index(_x948, _ctx); /*std/core/hnd/ev-index*/
    kk_std_core__list _b_827_818;
    size_t _b_828_815;
    kk_std_core_hnd__htag _x949 = kk_std_core_hnd__htag_dup(kk_effects_dash_and_dash_types__tag_sample); /*std/core/hnd/htag<effects-and-types/.hnd-sample>*/
    _b_828_815 = kk_std_core_hnd__evv_index(_x949, _ctx); /*std/core/hnd/ev-index*/
    _b_827_818 = kk_std_core__new_Cons(kk_reuse_null, kk_size_box(_b_828_815, _ctx), kk_std_core__new_Nil(_ctx), _ctx); /*list<std/core/hnd/ev-index>*/
    _x947 = kk_std_core__new_Cons(kk_reuse_null, kk_size_box(_b_826_817, _ctx), _b_827_818, _ctx); /*list<0>*/
    _b_823_819 = kk_std_core_unvlist(_x947, _ctx); /*vector<std/core/hnd/ev-index>*/
    kk_box_t _x950 = kk_std_core_hnd__open1(_b_823_819, kk_sequential_new_smc__loop_fun951(_ctx), kk_std_core__list_box(populated__hist, _ctx), _ctx); /*2*/
    x_752 = kk_std_core__list_unbox(_x950, _ctx); /*effects-and-types/histogram<(int) -> <exn,effects-and-types/yield,effects-and-types/score,effects-and-types/sample,div|661> 658>*/
    if (kk_yielding(kk_context())) {
      kk_std_core__list_drop(x_752, _ctx);
      kk_box_t _x954 = kk_std_core_hnd_yield_extend(kk_sequential_new_smc__loop_fun955(i2, step__num2, step__size2, normalize2, _ctx), _ctx); /*2*/
      return kk_std_core__list_unbox(_x954, _ctx);
    }
    kk_function_t advance__func0;
    kk_integer_dup(step__size2);
    advance__func0 = kk_sequential_new_smc__loop_fun958(step__size2, _ctx); /*forall<a,e> (wm : (effects-and-types/exp, (int) -> <effects-and-types/yield,effects-and-types/score|e> a)) -> e (effects-and-types/exp, (a : int) -> <effects-and-types/yield,effects-and-types/score|e> a)*/
    if (normalize2) {
      kk_std_core__list x0_756 = kk_std_core_map_5(x_752, kk_sequential_new_smc__loop_fun966(advance__func0, _ctx), _ctx); /*list<(effects-and-types/exp, (a : int) -> <effects-and-types/yield,effects-and-types/score,exn,effects-and-types/sample,div|661> 658)>*/;
      if (kk_yielding(kk_context())) {
        kk_std_core__list_drop(x0_756, _ctx);
        kk_box_t _x969 = kk_std_core_hnd_yield_extend(kk_sequential_new_smc__loop_fun970(i2, step__num2, step__size2, normalize2, _ctx), _ctx); /*2*/
        return kk_std_core__list_unbox(_x969, _ctx);
      }
      { // tailcall
        kk_integer_t _x973 = kk_integer_add(i2,(kk_integer_from_small(1)),kk_context()); /*int*/
        kk_std_core__list _x974;
        kk_evv_t w00 = kk_evv_swap_create0(kk_context()); /*std/core/hnd/evv<(<>)>*/;
        kk_std_core__list x2 = kk_sampling_normalise(x0_756, _ctx); /*effects-and-types/histogram<(a : int) -> <effects-and-types/yield,effects-and-types/score,exn,effects-and-types/sample,div|661> 658>*/;
        kk_unit_t keep1 = kk_Unit;
        kk_evv_set(w00,kk_context());
        _x974 = x2; /*effects-and-types/histogram<(a : int) -> <effects-and-types/yield,effects-and-types/score,exn,effects-and-types/sample,div|661> 658>*/
        i2 = _x973;
        populated__hist = _x974;
        goto kk__tailcall;
      }
    }
    kk_std_core__list x3_762 = kk_std_core_map_5(x_752, kk_sequential_new_smc__loop_fun975(advance__func0, _ctx), _ctx); /*list<(effects-and-types/exp, (a : int) -> <effects-and-types/yield,effects-and-types/score,exn,effects-and-types/sample,div|661> 658)>*/;
    if (kk_yielding(kk_context())) {
      kk_std_core__list_drop(x3_762, _ctx);
      kk_box_t _x978 = kk_std_core_hnd_yield_extend(kk_sequential_new_smc__loop_fun979(i2, step__num2, step__size2, normalize2, _ctx), _ctx); /*2*/
      return kk_std_core__list_unbox(_x978, _ctx);
    }
    { // tailcall
      kk_integer_t _x982 = kk_integer_add(i2,(kk_integer_from_small(1)),kk_context()); /*int*/
      i2 = _x982;
      populated__hist = x3_762;
      goto kk__tailcall;
    }
  }
  kk_integer_drop(i2, _ctx);
  kk_integer_drop(step__num2, _ctx);
  kk_integer_drop(step__size2, _ctx);
  kk_function_t finalize__func = kk_sequential_new_smc__loop_fun983(_ctx); /*(wm : (effects-and-types/exp, (int) -> <effects-and-types/yield,effects-and-types/score,exn,effects-and-types/sample,div|661> 658)) -> <exn,effects-and-types/sample,div|661> (effects-and-types/exp, 658)*/;
  if (normalize2) {
    kk_std_core__list x4_767 = kk_std_core_map_5(populated__hist, kk_sequential_new_smc__loop_fun992(finalize__func, _ctx), _ctx); /*list<(effects-and-types/exp, 658)>*/;
    if (kk_yielding(kk_context())) {
      kk_std_core__list_drop(x4_767, _ctx);
      kk_box_t _x995 = kk_std_core_hnd_yield_extend(kk_sequential_new_smc__loop_fun996(_ctx), _ctx); /*2*/
      return kk_std_core__list_unbox(_x995, _ctx);
    }
    kk_evv_t w10 = kk_evv_swap_create0(kk_context()); /*std/core/hnd/evv<(<>)>*/;
    kk_std_core__list x5 = kk_sampling_normalise(x4_767, _ctx); /*effects-and-types/histogram<658>*/;
    kk_unit_t keep00 = kk_Unit;
    kk_evv_set(w10,kk_context());
    return x5;
  }
  return kk_std_core_map_5(populated__hist, kk_sequential_new_smc__loop_fun999(finalize__func, _ctx), _ctx);
}
 
// monadic lift

kk_std_core__list kk_sequential__mlift743_smc(bool normalize, kk_integer_t step__num, kk_integer_t step__size, kk_std_core__list _y_20, kk_context_t* _ctx) { /* forall<a,e> (normalize : bool, step_num : int, step_size : int, effects-and-types/histogram<(a : int) -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random|e> a>) -> <effects-and-types/sample,div,exn,std/num/random/random|e> effects-and-types/histogram<a> */ 
  kk_std_core__list pop;
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*std/core/hnd/evv<(<>)>*/;
  kk_std_core__list x = kk_sampling_normalise(_y_20, _ctx); /*effects-and-types/histogram<(a : int) -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random|727> 24>*/;
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  pop = x; /*effects-and-types/histogram<(a : int) -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random|727> 24>*/
  return kk_sequential_smc__loop(kk_integer_from_small(0), pop, step__num, step__size, normalize, _ctx);
}


// lift anonymous function
struct kk_sequential_smc_fun1003__t {
  struct kk_function_s _base;
  kk_function_t model;
  kk_integer_t particle__num;
  kk_integer_t step__num;
  kk_integer_t step__size;
  bool normalize;
};
static kk_box_t kk_sequential_smc_fun1003(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_sequential_new_smc_fun1003(kk_function_t model, kk_integer_t particle__num, kk_integer_t step__num, kk_integer_t step__size, bool normalize, kk_context_t* _ctx) {
  struct kk_sequential_smc_fun1003__t* _self = kk_function_alloc_as(struct kk_sequential_smc_fun1003__t, 5, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_sequential_smc_fun1003, kk_context());
  _self->model = model;
  _self->particle__num = particle__num;
  _self->step__num = step__num;
  _self->step__size = step__size;
  _self->normalize = normalize;
  return &_self->_base;
}



// lift anonymous function
struct kk_sequential_smc_fun1005__t {
  struct kk_function_s _base;
  kk_function_t model;
};
static kk_box_t kk_sequential_smc_fun1005(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_sequential_new_smc_fun1005(kk_function_t model, kk_context_t* _ctx) {
  struct kk_sequential_smc_fun1005__t* _self = kk_function_alloc_as(struct kk_sequential_smc_fun1005__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_sequential_smc_fun1005, kk_context());
  _self->model = model;
  return &_self->_base;
}



// lift anonymous function
struct kk_sequential_smc_fun1007__t {
  struct kk_function_s _base;
  kk_function_t model;
};
static kk_box_t kk_sequential_smc_fun1007(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_sequential_new_smc_fun1007(kk_function_t model, kk_context_t* _ctx) {
  struct kk_sequential_smc_fun1007__t* _self = kk_function_alloc_as(struct kk_sequential_smc_fun1007__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_sequential_smc_fun1007, kk_context());
  _self->model = model;
  return &_self->_base;
}

static kk_box_t kk_sequential_smc_fun1007(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_sequential_smc_fun1007__t* _self = kk_function_as(struct kk_sequential_smc_fun1007__t*, _fself);
  kk_function_t model = _self->model; /* () -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random|727> 24 */
  kk_drop_match(_self, {kk_function_dup(model);}, {}, _ctx)
  return kk_handlers_yield__on__score(model, _ctx);
}


// lift anonymous function
struct kk_sequential_smc_fun1008__t {
  struct kk_function_s _base;
  kk_function_t _bv_902;
};
static kk_box_t kk_sequential_smc_fun1008(kk_function_t _fself, kk_box_t _b_903, kk_context_t* _ctx);
static kk_function_t kk_sequential_new_smc_fun1008(kk_function_t _bv_902, kk_context_t* _ctx) {
  struct kk_sequential_smc_fun1008__t* _self = kk_function_alloc_as(struct kk_sequential_smc_fun1008__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_sequential_smc_fun1008, kk_context());
  _self->_bv_902 = _bv_902;
  return &_self->_base;
}

static kk_box_t kk_sequential_smc_fun1008(kk_function_t _fself, kk_box_t _b_903, kk_context_t* _ctx) {
  struct kk_sequential_smc_fun1008__t* _self = kk_function_as(struct kk_sequential_smc_fun1008__t*, _fself);
  kk_function_t _bv_902 = _self->_bv_902; /* (a : int) -> <effects-and-types/yield,effects-and-types/sample,effects-and-types/score,div,exn,std/num/random/random|727> 24 */
  kk_drop_match(_self, {kk_function_dup(_bv_902);}, {}, _ctx)
  kk_integer_t _x1009 = kk_integer_unbox(_b_903); /*int*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_context_t*), _bv_902, (_bv_902, _x1009, _ctx));
}
static kk_box_t kk_sequential_smc_fun1005(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_sequential_smc_fun1005__t* _self = kk_function_as(struct kk_sequential_smc_fun1005__t*, _fself);
  kk_function_t model = _self->model; /* () -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random|727> 24 */
  kk_drop_match(_self, {kk_function_dup(model);}, {}, _ctx)
  kk_function_t _x1006;
  kk_function_t _bv_902 = kk_handlers_advance(kk_sequential_new_smc_fun1007(model, _ctx), _ctx); /*(a : int) -> <effects-and-types/yield,effects-and-types/sample,effects-and-types/score,div,exn,std/num/random/random|727> 24*/;
  _x1006 = kk_sequential_new_smc_fun1008(_bv_902, _ctx); /*(900) -> <effects-and-types/yield,effects-and-types/sample,effects-and-types/score,div,exn,std/num/random/random|727> 24*/
  return kk_function_box(_x1006);
}


// lift anonymous function
struct kk_sequential_smc_fun1011__t {
  struct kk_function_s _base;
  kk_integer_t step__num;
  kk_integer_t step__size;
  bool normalize;
};
static kk_box_t kk_sequential_smc_fun1011(kk_function_t _fself, kk_box_t _b_907, kk_context_t* _ctx);
static kk_function_t kk_sequential_new_smc_fun1011(kk_integer_t step__num, kk_integer_t step__size, bool normalize, kk_context_t* _ctx) {
  struct kk_sequential_smc_fun1011__t* _self = kk_function_alloc_as(struct kk_sequential_smc_fun1011__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_sequential_smc_fun1011, kk_context());
  _self->step__num = step__num;
  _self->step__size = step__size;
  _self->normalize = normalize;
  return &_self->_base;
}

static kk_box_t kk_sequential_smc_fun1011(kk_function_t _fself, kk_box_t _b_907, kk_context_t* _ctx) {
  struct kk_sequential_smc_fun1011__t* _self = kk_function_as(struct kk_sequential_smc_fun1011__t*, _fself);
  kk_integer_t step__num = _self->step__num; /* int */
  kk_integer_t step__size = _self->step__size; /* int */
  bool normalize = _self->normalize; /* bool */
  kk_drop_match(_self, {kk_integer_dup(step__num);kk_integer_dup(step__size);;}, {}, _ctx)
  kk_std_core__list _x1012;
  kk_std_core__list _x1013 = kk_std_core__list_unbox(_b_907, _ctx); /*effects-and-types/histogram<(a : int) -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random|727> 24>*/
  _x1012 = kk_sequential__mlift743_smc(normalize, step__num, step__size, _x1013, _ctx); /*effects-and-types/histogram<24>*/
  return kk_std_core__list_box(_x1012, _ctx);
}
static kk_box_t kk_sequential_smc_fun1003(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_sequential_smc_fun1003__t* _self = kk_function_as(struct kk_sequential_smc_fun1003__t*, _fself);
  kk_function_t model = _self->model; /* () -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random|727> 24 */
  kk_integer_t particle__num = _self->particle__num; /* int */
  kk_integer_t step__num = _self->step__num; /* int */
  kk_integer_t step__size = _self->step__size; /* int */
  bool normalize = _self->normalize; /* bool */
  kk_drop_match(_self, {kk_function_dup(model);kk_integer_dup(particle__num);kk_integer_dup(step__num);kk_integer_dup(step__size);;}, {}, _ctx)
  kk_std_core__list _x1004;
  kk_std_core__list x_775 = kk_sampling_populate(particle__num, kk_sequential_new_smc_fun1005(model, _ctx), _ctx); /*effects-and-types/histogram<(a : int) -> <effects-and-types/sample,effects-and-types/score,effects-and-types/yield,div,exn,std/num/random/random|727> 24>*/;
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_775, _ctx);
    kk_box_t _x1010 = kk_std_core_hnd_yield_extend(kk_sequential_new_smc_fun1011(step__num, step__size, normalize, _ctx), _ctx); /*2*/
    _x1004 = kk_std_core__list_unbox(_x1010, _ctx); /*effects-and-types/histogram<24>*/
  }
  else {
    _x1004 = kk_sequential__mlift743_smc(normalize, step__num, step__size, x_775, _ctx); /*effects-and-types/histogram<24>*/
  }
  return kk_std_core__list_box(_x1004, _ctx);
}

kk_std_core__list kk_sequential_smc(kk_integer_t particle__num, kk_integer_t step__num, kk_integer_t step__size, kk_function_t model, bool normalize, kk_context_t* _ctx) { /* forall<a,e> (particle_num : int, step_num : int, step_size : int, model : () -> <pure,std/num/random/random,effects-and-types/sample,effects-and-types/score,effects-and-types/yield|e> a, normalize : bool) -> <pure,std/num/random/random|e> effects-and-types/histogram<a> */ 
  kk_box_t _x1002 = kk_handlers_random__sampler(kk_sequential_new_smc_fun1003(model, particle__num, step__num, step__size, normalize, _ctx), _ctx); /*312*/
  return kk_std_core__list_unbox(_x1002, _ctx);
}

// initialization
void kk_sequential__init(kk_context_t* _ctx){
  static bool _initialized = false;
  if (_initialized) return;
  _initialized = true;
  kk_std_core_types__init(_ctx);
  kk_std_core_hnd__init(_ctx);
  kk_std_core__init(_ctx);
  kk_std_num_random__init(_ctx);
  kk_effects_dash_and_dash_types__init(_ctx);
  kk_handlers__init(_ctx);
  kk_sampling__init(_ctx);
}
