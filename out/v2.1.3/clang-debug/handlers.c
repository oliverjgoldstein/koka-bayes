// Koka generated module: "handlers", koka version: 2.1.3
#include "handlers.h"
 
// monadic lift

kk_box_t kk_handlers__mlift2014_advance(kk_integer_t a, kk_function_t _y_2, kk_context_t* _ctx) { /* forall<a,e> (a : int, (int) -> <effects-and-types/yield|e> a) -> <effects-and-types/yield|e> a */ 
  kk_integer_t _x2823 = kk_integer_sub(a,(kk_integer_from_small(1)),kk_context()); /*int*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_context_t*), _y_2, (_y_2, _x2823, _ctx));
}
 
// monadic lift


// lift anonymous function
struct kk_handlers__mlift2015_advance_fun2825__t {
  struct kk_function_s _base;
  size_t _y_0;
};
static kk_box_t kk_handlers__mlift2015_advance_fun2825(kk_function_t _fself, kk_function_t _b_2188, kk_box_t _b_2189, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2015_advance_fun2825(size_t _y_0, kk_context_t* _ctx) {
  struct kk_handlers__mlift2015_advance_fun2825__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2015_advance_fun2825__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2015_advance_fun2825, kk_context());
  _self->_y_0 = _y_0;
  return &_self->_base;
}



// lift anonymous function
struct kk_handlers__mlift2015_advance_fun2828__t {
  struct kk_function_s _base;
  kk_function_t _b_2188;
};
static kk_box_t kk_handlers__mlift2015_advance_fun2828(kk_function_t _fself, kk_box_t _b_2172, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2015_advance_fun2828(kk_function_t _b_2188, kk_context_t* _ctx) {
  struct kk_handlers__mlift2015_advance_fun2828__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2015_advance_fun2828__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2015_advance_fun2828, kk_context());
  _self->_b_2188 = _b_2188;
  return &_self->_base;
}



// lift anonymous function
struct kk_handlers__mlift2015_advance_fun2831__t {
  struct kk_function_s _base;
  kk_box_t _b_2172;
};
static kk_box_t kk_handlers__mlift2015_advance_fun2831(kk_function_t _fself, kk_box_t _b_2193, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2015_advance_fun2831(kk_box_t _b_2172, kk_context_t* _ctx) {
  struct kk_handlers__mlift2015_advance_fun2831__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2015_advance_fun2831__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2015_advance_fun2831, kk_context());
  _self->_b_2172 = _b_2172;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift2015_advance_fun2831(kk_function_t _fself, kk_box_t _b_2193, kk_context_t* _ctx) {
  struct kk_handlers__mlift2015_advance_fun2831__t* _self = kk_function_as(struct kk_handlers__mlift2015_advance_fun2831__t*, _fself);
  kk_box_t _b_2172 = _self->_b_2172; /* 1 */
  kk_drop_match(_self, {kk_box_dup(_b_2172);}, {}, _ctx)
  kk_function_t _x2832 = kk_function_unbox(_b_2172); /*(2173) -> <effects-and-types/yield|231> 2174*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x2832, (_x2832, _b_2193, _ctx));
}


// lift anonymous function
struct kk_handlers__mlift2015_advance_fun2833__t {
  struct kk_function_s _base;
  kk_function_t _bv_2196;
};
static kk_box_t kk_handlers__mlift2015_advance_fun2833(kk_function_t _fself, kk_integer_t _b_2197, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2015_advance_fun2833(kk_function_t _bv_2196, kk_context_t* _ctx) {
  struct kk_handlers__mlift2015_advance_fun2833__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2015_advance_fun2833__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2015_advance_fun2833, kk_context());
  _self->_bv_2196 = _bv_2196;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift2015_advance_fun2833(kk_function_t _fself, kk_integer_t _b_2197, kk_context_t* _ctx) {
  struct kk_handlers__mlift2015_advance_fun2833__t* _self = kk_function_as(struct kk_handlers__mlift2015_advance_fun2833__t*, _fself);
  kk_function_t _bv_2196 = _self->_bv_2196; /* (2194) -> <effects-and-types/yield|231> 2195 */
  kk_drop_match(_self, {kk_function_dup(_bv_2196);}, {}, _ctx)
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _bv_2196, (_bv_2196, kk_integer_box(_b_2197), _ctx));
}


// lift anonymous function
struct kk_handlers__mlift2015_advance_fun2834__t {
  struct kk_function_s _base;
  kk_function_t _bv_2178;
};
static kk_box_t kk_handlers__mlift2015_advance_fun2834(kk_function_t _fself, kk_box_t _b_2179, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2015_advance_fun2834(kk_function_t _bv_2178, kk_context_t* _ctx) {
  struct kk_handlers__mlift2015_advance_fun2834__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2015_advance_fun2834__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2015_advance_fun2834, kk_context());
  _self->_bv_2178 = _bv_2178;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift2015_advance_fun2834(kk_function_t _fself, kk_box_t _b_2179, kk_context_t* _ctx) {
  struct kk_handlers__mlift2015_advance_fun2834__t* _self = kk_function_as(struct kk_handlers__mlift2015_advance_fun2834__t*, _fself);
  kk_function_t _bv_2178 = _self->_bv_2178; /* (int) -> <effects-and-types/yield|231> 230 */
  kk_drop_match(_self, {kk_function_dup(_bv_2178);}, {}, _ctx)
  kk_integer_t _x2835 = kk_integer_unbox(_b_2179); /*int*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_context_t*), _bv_2178, (_bv_2178, _x2835, _ctx));
}
static kk_box_t kk_handlers__mlift2015_advance_fun2828(kk_function_t _fself, kk_box_t _b_2172, kk_context_t* _ctx) {
  struct kk_handlers__mlift2015_advance_fun2828__t* _self = kk_function_as(struct kk_handlers__mlift2015_advance_fun2828__t*, _fself);
  kk_function_t _b_2188 = _self->_b_2188; /* (1) -> 2 1 */
  kk_drop_match(_self, {kk_function_dup(_b_2188);}, {}, _ctx)
  kk_function_t _x2829;
  kk_function_t _bv_2178;
  kk_function_t _bv_2196;
  kk_box_t _x2830 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _b_2188, (_b_2188, kk_function_box(kk_handlers__new_mlift2015_advance_fun2831(_b_2172, _ctx)), _ctx)); /*1*/
  _bv_2196 = kk_function_unbox(_x2830); /*(2194) -> <effects-and-types/yield|231> 2195*/
  _bv_2178 = kk_handlers__new_mlift2015_advance_fun2833(_bv_2196, _ctx); /*(int) -> <effects-and-types/yield|231> 230*/
  _x2829 = kk_handlers__new_mlift2015_advance_fun2834(_bv_2178, _ctx); /*(2176) -> <effects-and-types/yield|231> 230*/
  return kk_function_box(_x2829);
}


// lift anonymous function
struct kk_handlers__mlift2015_advance_fun2836__t {
  struct kk_function_s _base;
  kk_box_t _b_2189;
};
static kk_box_t kk_handlers__mlift2015_advance_fun2836(kk_function_t _fself, kk_box_t _b_2182, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2015_advance_fun2836(kk_box_t _b_2189, kk_context_t* _ctx) {
  struct kk_handlers__mlift2015_advance_fun2836__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2015_advance_fun2836__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2015_advance_fun2836, kk_context());
  _self->_b_2189 = _b_2189;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift2015_advance_fun2836(kk_function_t _fself, kk_box_t _b_2182, kk_context_t* _ctx) {
  struct kk_handlers__mlift2015_advance_fun2836__t* _self = kk_function_as(struct kk_handlers__mlift2015_advance_fun2836__t*, _fself);
  kk_box_t _b_2189 = _self->_b_2189; /* 1 */
  kk_drop_match(_self, {kk_box_dup(_b_2189);}, {}, _ctx)
  kk_function_t _x2837 = kk_function_unbox(_b_2189); /*(2198) -> <effects-and-types/yield|231> 2199*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x2837, (_x2837, _b_2182, _ctx));
}


// lift anonymous function
struct kk_handlers__mlift2015_advance_fun2838__t {
  struct kk_function_s _base;
  kk_function_t _bv_2185;
};
static kk_box_t kk_handlers__mlift2015_advance_fun2838(kk_function_t _fself, kk_integer_t _b_2186, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2015_advance_fun2838(kk_function_t _bv_2185, kk_context_t* _ctx) {
  struct kk_handlers__mlift2015_advance_fun2838__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2015_advance_fun2838__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2015_advance_fun2838, kk_context());
  _self->_bv_2185 = _bv_2185;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift2015_advance_fun2838(kk_function_t _fself, kk_integer_t _b_2186, kk_context_t* _ctx) {
  struct kk_handlers__mlift2015_advance_fun2838__t* _self = kk_function_as(struct kk_handlers__mlift2015_advance_fun2838__t*, _fself);
  kk_function_t _bv_2185 = _self->_bv_2185; /* (2183) -> <effects-and-types/yield|231> 2184 */
  kk_drop_match(_self, {kk_function_dup(_bv_2185);}, {}, _ctx)
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _bv_2185, (_bv_2185, kk_integer_box(_b_2186), _ctx));
}


// lift anonymous function
struct kk_handlers__mlift2015_advance_fun2839__t {
  struct kk_function_s _base;
  kk_function_t _bv_2203;
};
static kk_box_t kk_handlers__mlift2015_advance_fun2839(kk_function_t _fself, kk_box_t _b_2204, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2015_advance_fun2839(kk_function_t _bv_2203, kk_context_t* _ctx) {
  struct kk_handlers__mlift2015_advance_fun2839__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2015_advance_fun2839__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2015_advance_fun2839, kk_context());
  _self->_bv_2203 = _bv_2203;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift2015_advance_fun2839(kk_function_t _fself, kk_box_t _b_2204, kk_context_t* _ctx) {
  struct kk_handlers__mlift2015_advance_fun2839__t* _self = kk_function_as(struct kk_handlers__mlift2015_advance_fun2839__t*, _fself);
  kk_function_t _bv_2203 = _self->_bv_2203; /* (int) -> <effects-and-types/yield|231> 230 */
  kk_drop_match(_self, {kk_function_dup(_bv_2203);}, {}, _ctx)
  kk_integer_t _x2840 = kk_integer_unbox(_b_2204); /*int*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_context_t*), _bv_2203, (_bv_2203, _x2840, _ctx));
}
static kk_box_t kk_handlers__mlift2015_advance_fun2825(kk_function_t _fself, kk_function_t _b_2188, kk_box_t _b_2189, kk_context_t* _ctx) {
  struct kk_handlers__mlift2015_advance_fun2825__t* _self = kk_function_as(struct kk_handlers__mlift2015_advance_fun2825__t*, _fself);
  size_t _y_0 = _self->_y_0; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  kk_function_t _x2826;
  kk_function_t _bv_2203;
  kk_function_t _bv_2185;
  kk_box_t _x2827 = kk_std_core_hnd_mask_at1(_y_0, false, kk_handlers__new_mlift2015_advance_fun2828(_b_2188, _ctx), kk_function_box(kk_handlers__new_mlift2015_advance_fun2836(_b_2189, _ctx)), _ctx); /*2*/
  _bv_2185 = kk_function_unbox(_x2827); /*(2183) -> <effects-and-types/yield|231> 2184*/
  _bv_2203 = kk_handlers__new_mlift2015_advance_fun2838(_bv_2185, _ctx); /*(int) -> <effects-and-types/yield|231> 230*/
  _x2826 = kk_handlers__new_mlift2015_advance_fun2839(_bv_2203, _ctx); /*(2201) -> <effects-and-types/yield|231> 230*/
  return kk_function_box(_x2826);
}


// lift anonymous function
struct kk_handlers__mlift2015_advance_fun2841__t {
  struct kk_function_s _base;
  kk_function_t _bv_2207;
};
static kk_box_t kk_handlers__mlift2015_advance_fun2841(kk_function_t _fself, kk_integer_t _b_2208, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2015_advance_fun2841(kk_function_t _bv_2207, kk_context_t* _ctx) {
  struct kk_handlers__mlift2015_advance_fun2841__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2015_advance_fun2841__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2015_advance_fun2841, kk_context());
  _self->_bv_2207 = _bv_2207;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift2015_advance_fun2841(kk_function_t _fself, kk_integer_t _b_2208, kk_context_t* _ctx) {
  struct kk_handlers__mlift2015_advance_fun2841__t* _self = kk_function_as(struct kk_handlers__mlift2015_advance_fun2841__t*, _fself);
  kk_function_t _bv_2207 = _self->_bv_2207; /* (2205) -> <.Box|.Box> 2206 */
  kk_drop_match(_self, {kk_function_dup(_bv_2207);}, {}, _ctx)
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _bv_2207, (_bv_2207, kk_integer_box(_b_2208), _ctx));
}


// lift anonymous function
struct kk_handlers__mlift2015_advance_fun2842__t {
  struct kk_function_s _base;
  kk_integer_t a;
};
static kk_box_t kk_handlers__mlift2015_advance_fun2842(kk_function_t _fself, kk_box_t _b_2220, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2015_advance_fun2842(kk_integer_t a, kk_context_t* _ctx) {
  struct kk_handlers__mlift2015_advance_fun2842__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2015_advance_fun2842__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2015_advance_fun2842, kk_context());
  _self->a = a;
  return &_self->_base;
}



// lift anonymous function
struct kk_handlers__mlift2015_advance_fun2843__t {
  struct kk_function_s _base;
  kk_box_t _b_2220;
};
static kk_box_t kk_handlers__mlift2015_advance_fun2843(kk_function_t _fself, kk_integer_t _b_2223, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2015_advance_fun2843(kk_box_t _b_2220, kk_context_t* _ctx) {
  struct kk_handlers__mlift2015_advance_fun2843__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2015_advance_fun2843__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2015_advance_fun2843, kk_context());
  _self->_b_2220 = _b_2220;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift2015_advance_fun2843(kk_function_t _fself, kk_integer_t _b_2223, kk_context_t* _ctx) {
  struct kk_handlers__mlift2015_advance_fun2843__t* _self = kk_function_as(struct kk_handlers__mlift2015_advance_fun2843__t*, _fself);
  kk_box_t _b_2220 = _self->_b_2220; /* 1 */
  kk_drop_match(_self, {kk_box_dup(_b_2220);}, {}, _ctx)
  kk_function_t _x2844 = kk_function_unbox(_b_2220); /*(2221) -> <effects-and-types/yield|231> 2222*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x2844, (_x2844, kk_integer_box(_b_2223), _ctx));
}
static kk_box_t kk_handlers__mlift2015_advance_fun2842(kk_function_t _fself, kk_box_t _b_2220, kk_context_t* _ctx) {
  struct kk_handlers__mlift2015_advance_fun2842__t* _self = kk_function_as(struct kk_handlers__mlift2015_advance_fun2842__t*, _fself);
  kk_integer_t a = _self->a; /* int */
  kk_drop_match(_self, {kk_integer_dup(a);}, {}, _ctx)
  return kk_handlers__mlift2014_advance(a, kk_handlers__new_mlift2015_advance_fun2843(_b_2220, _ctx), _ctx);
}

kk_box_t kk_handlers__mlift2015_advance(kk_integer_t a, kk_function_t resume, size_t _y_0, kk_context_t* _ctx) { /* forall<a,e> (a : int, resume : (()) -> e ((int) -> <effects-and-types/yield|e> a), std/core/hnd/ev-index) -> <effects-and-types/yield|e> a */ 
  kk_function_t x_2037;
  kk_evv_t w0 = kk_std_core_hnd_evv_swap_delete(_y_0, false, _ctx); /*std/core/hnd/evv<std/core/hnd/_e2>*/;
  kk_function_t x0 = kk_function_call(kk_function_t, (kk_function_t, kk_unit_t, kk_context_t*), resume, (resume, kk_Unit, _ctx)); /*(int) -> <effects-and-types/yield|231> 230*/;
  kk_unit_t __w_l645_c9 = kk_Unit;
  kk_evv_set(w0,kk_context());
  if (kk_yielding(kk_context())) {
    kk_function_drop(x0, _ctx);
    kk_function_t _bv_2207;
    kk_box_t _x2824 = kk_std_core_hnd_yield_cont(kk_handlers__new_mlift2015_advance_fun2825(_y_0, _ctx), _ctx); /*3*/
    _bv_2207 = kk_function_unbox(_x2824); /*(2205) -> <.Box|.Box> 2206*/
    x_2037 = kk_handlers__new_mlift2015_advance_fun2841(_bv_2207, _ctx); /*(int) -> <effects-and-types/yield|231> 230*/
  }
  else {
    x_2037 = x0; /*(int) -> <effects-and-types/yield|231> 230*/
  }
  if (kk_yielding(kk_context())) {
    kk_function_drop(x_2037, _ctx);
    return kk_std_core_hnd_yield_extend(kk_handlers__new_mlift2015_advance_fun2842(a, _ctx), _ctx);
  }
  return kk_handlers__mlift2014_advance(a, x_2037, _ctx);
}
 
// monadic lift

kk_box_t kk_handlers__mlift2016_advance(kk_function_t _y_7, kk_context_t* _ctx) { /* forall<a,e> ((int) -> <effects-and-types/yield|e> a) -> <effects-and-types/yield|e> a */ 
  return kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_context_t*), _y_7, (_y_7, kk_integer_from_small(0), _ctx));
}
 
// monadic lift


// lift anonymous function
struct kk_handlers__mlift2017_advance_fun2846__t {
  struct kk_function_s _base;
  size_t _y_5;
};
static kk_box_t kk_handlers__mlift2017_advance_fun2846(kk_function_t _fself, kk_function_t _b_2246, kk_box_t _b_2247, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2017_advance_fun2846(size_t _y_5, kk_context_t* _ctx) {
  struct kk_handlers__mlift2017_advance_fun2846__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2017_advance_fun2846__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2017_advance_fun2846, kk_context());
  _self->_y_5 = _y_5;
  return &_self->_base;
}



// lift anonymous function
struct kk_handlers__mlift2017_advance_fun2849__t {
  struct kk_function_s _base;
  kk_function_t _b_2246;
};
static kk_box_t kk_handlers__mlift2017_advance_fun2849(kk_function_t _fself, kk_box_t _b_2230, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2017_advance_fun2849(kk_function_t _b_2246, kk_context_t* _ctx) {
  struct kk_handlers__mlift2017_advance_fun2849__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2017_advance_fun2849__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2017_advance_fun2849, kk_context());
  _self->_b_2246 = _b_2246;
  return &_self->_base;
}



// lift anonymous function
struct kk_handlers__mlift2017_advance_fun2852__t {
  struct kk_function_s _base;
  kk_box_t _b_2230;
};
static kk_box_t kk_handlers__mlift2017_advance_fun2852(kk_function_t _fself, kk_box_t _b_2251, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2017_advance_fun2852(kk_box_t _b_2230, kk_context_t* _ctx) {
  struct kk_handlers__mlift2017_advance_fun2852__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2017_advance_fun2852__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2017_advance_fun2852, kk_context());
  _self->_b_2230 = _b_2230;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift2017_advance_fun2852(kk_function_t _fself, kk_box_t _b_2251, kk_context_t* _ctx) {
  struct kk_handlers__mlift2017_advance_fun2852__t* _self = kk_function_as(struct kk_handlers__mlift2017_advance_fun2852__t*, _fself);
  kk_box_t _b_2230 = _self->_b_2230; /* 1 */
  kk_drop_match(_self, {kk_box_dup(_b_2230);}, {}, _ctx)
  kk_function_t _x2853 = kk_function_unbox(_b_2230); /*(2231) -> <effects-and-types/yield|231> 2232*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x2853, (_x2853, _b_2251, _ctx));
}


// lift anonymous function
struct kk_handlers__mlift2017_advance_fun2854__t {
  struct kk_function_s _base;
  kk_function_t _bv_2254;
};
static kk_box_t kk_handlers__mlift2017_advance_fun2854(kk_function_t _fself, kk_integer_t _b_2255, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2017_advance_fun2854(kk_function_t _bv_2254, kk_context_t* _ctx) {
  struct kk_handlers__mlift2017_advance_fun2854__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2017_advance_fun2854__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2017_advance_fun2854, kk_context());
  _self->_bv_2254 = _bv_2254;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift2017_advance_fun2854(kk_function_t _fself, kk_integer_t _b_2255, kk_context_t* _ctx) {
  struct kk_handlers__mlift2017_advance_fun2854__t* _self = kk_function_as(struct kk_handlers__mlift2017_advance_fun2854__t*, _fself);
  kk_function_t _bv_2254 = _self->_bv_2254; /* (2252) -> <effects-and-types/yield|231> 2253 */
  kk_drop_match(_self, {kk_function_dup(_bv_2254);}, {}, _ctx)
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _bv_2254, (_bv_2254, kk_integer_box(_b_2255), _ctx));
}


// lift anonymous function
struct kk_handlers__mlift2017_advance_fun2855__t {
  struct kk_function_s _base;
  kk_function_t _bv_2236;
};
static kk_box_t kk_handlers__mlift2017_advance_fun2855(kk_function_t _fself, kk_box_t _b_2237, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2017_advance_fun2855(kk_function_t _bv_2236, kk_context_t* _ctx) {
  struct kk_handlers__mlift2017_advance_fun2855__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2017_advance_fun2855__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2017_advance_fun2855, kk_context());
  _self->_bv_2236 = _bv_2236;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift2017_advance_fun2855(kk_function_t _fself, kk_box_t _b_2237, kk_context_t* _ctx) {
  struct kk_handlers__mlift2017_advance_fun2855__t* _self = kk_function_as(struct kk_handlers__mlift2017_advance_fun2855__t*, _fself);
  kk_function_t _bv_2236 = _self->_bv_2236; /* (int) -> <effects-and-types/yield|231> 230 */
  kk_drop_match(_self, {kk_function_dup(_bv_2236);}, {}, _ctx)
  kk_integer_t _x2856 = kk_integer_unbox(_b_2237); /*int*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_context_t*), _bv_2236, (_bv_2236, _x2856, _ctx));
}
static kk_box_t kk_handlers__mlift2017_advance_fun2849(kk_function_t _fself, kk_box_t _b_2230, kk_context_t* _ctx) {
  struct kk_handlers__mlift2017_advance_fun2849__t* _self = kk_function_as(struct kk_handlers__mlift2017_advance_fun2849__t*, _fself);
  kk_function_t _b_2246 = _self->_b_2246; /* (1) -> 2 1 */
  kk_drop_match(_self, {kk_function_dup(_b_2246);}, {}, _ctx)
  kk_function_t _x2850;
  kk_function_t _bv_2236;
  kk_function_t _bv_2254;
  kk_box_t _x2851 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _b_2246, (_b_2246, kk_function_box(kk_handlers__new_mlift2017_advance_fun2852(_b_2230, _ctx)), _ctx)); /*1*/
  _bv_2254 = kk_function_unbox(_x2851); /*(2252) -> <effects-and-types/yield|231> 2253*/
  _bv_2236 = kk_handlers__new_mlift2017_advance_fun2854(_bv_2254, _ctx); /*(int) -> <effects-and-types/yield|231> 230*/
  _x2850 = kk_handlers__new_mlift2017_advance_fun2855(_bv_2236, _ctx); /*(2234) -> <effects-and-types/yield|231> 230*/
  return kk_function_box(_x2850);
}


// lift anonymous function
struct kk_handlers__mlift2017_advance_fun2857__t {
  struct kk_function_s _base;
  kk_box_t _b_2247;
};
static kk_box_t kk_handlers__mlift2017_advance_fun2857(kk_function_t _fself, kk_box_t _b_2240, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2017_advance_fun2857(kk_box_t _b_2247, kk_context_t* _ctx) {
  struct kk_handlers__mlift2017_advance_fun2857__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2017_advance_fun2857__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2017_advance_fun2857, kk_context());
  _self->_b_2247 = _b_2247;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift2017_advance_fun2857(kk_function_t _fself, kk_box_t _b_2240, kk_context_t* _ctx) {
  struct kk_handlers__mlift2017_advance_fun2857__t* _self = kk_function_as(struct kk_handlers__mlift2017_advance_fun2857__t*, _fself);
  kk_box_t _b_2247 = _self->_b_2247; /* 1 */
  kk_drop_match(_self, {kk_box_dup(_b_2247);}, {}, _ctx)
  kk_function_t _x2858 = kk_function_unbox(_b_2247); /*(2256) -> <effects-and-types/yield|231> 2257*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x2858, (_x2858, _b_2240, _ctx));
}


// lift anonymous function
struct kk_handlers__mlift2017_advance_fun2859__t {
  struct kk_function_s _base;
  kk_function_t _bv_2243;
};
static kk_box_t kk_handlers__mlift2017_advance_fun2859(kk_function_t _fself, kk_integer_t _b_2244, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2017_advance_fun2859(kk_function_t _bv_2243, kk_context_t* _ctx) {
  struct kk_handlers__mlift2017_advance_fun2859__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2017_advance_fun2859__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2017_advance_fun2859, kk_context());
  _self->_bv_2243 = _bv_2243;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift2017_advance_fun2859(kk_function_t _fself, kk_integer_t _b_2244, kk_context_t* _ctx) {
  struct kk_handlers__mlift2017_advance_fun2859__t* _self = kk_function_as(struct kk_handlers__mlift2017_advance_fun2859__t*, _fself);
  kk_function_t _bv_2243 = _self->_bv_2243; /* (2241) -> <effects-and-types/yield|231> 2242 */
  kk_drop_match(_self, {kk_function_dup(_bv_2243);}, {}, _ctx)
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _bv_2243, (_bv_2243, kk_integer_box(_b_2244), _ctx));
}


// lift anonymous function
struct kk_handlers__mlift2017_advance_fun2860__t {
  struct kk_function_s _base;
  kk_function_t _bv_2261;
};
static kk_box_t kk_handlers__mlift2017_advance_fun2860(kk_function_t _fself, kk_box_t _b_2262, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2017_advance_fun2860(kk_function_t _bv_2261, kk_context_t* _ctx) {
  struct kk_handlers__mlift2017_advance_fun2860__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2017_advance_fun2860__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2017_advance_fun2860, kk_context());
  _self->_bv_2261 = _bv_2261;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift2017_advance_fun2860(kk_function_t _fself, kk_box_t _b_2262, kk_context_t* _ctx) {
  struct kk_handlers__mlift2017_advance_fun2860__t* _self = kk_function_as(struct kk_handlers__mlift2017_advance_fun2860__t*, _fself);
  kk_function_t _bv_2261 = _self->_bv_2261; /* (int) -> <effects-and-types/yield|231> 230 */
  kk_drop_match(_self, {kk_function_dup(_bv_2261);}, {}, _ctx)
  kk_integer_t _x2861 = kk_integer_unbox(_b_2262); /*int*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_context_t*), _bv_2261, (_bv_2261, _x2861, _ctx));
}
static kk_box_t kk_handlers__mlift2017_advance_fun2846(kk_function_t _fself, kk_function_t _b_2246, kk_box_t _b_2247, kk_context_t* _ctx) {
  struct kk_handlers__mlift2017_advance_fun2846__t* _self = kk_function_as(struct kk_handlers__mlift2017_advance_fun2846__t*, _fself);
  size_t _y_5 = _self->_y_5; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  kk_function_t _x2847;
  kk_function_t _bv_2261;
  kk_function_t _bv_2243;
  kk_box_t _x2848 = kk_std_core_hnd_mask_at1(_y_5, false, kk_handlers__new_mlift2017_advance_fun2849(_b_2246, _ctx), kk_function_box(kk_handlers__new_mlift2017_advance_fun2857(_b_2247, _ctx)), _ctx); /*2*/
  _bv_2243 = kk_function_unbox(_x2848); /*(2241) -> <effects-and-types/yield|231> 2242*/
  _bv_2261 = kk_handlers__new_mlift2017_advance_fun2859(_bv_2243, _ctx); /*(int) -> <effects-and-types/yield|231> 230*/
  _x2847 = kk_handlers__new_mlift2017_advance_fun2860(_bv_2261, _ctx); /*(2259) -> <effects-and-types/yield|231> 230*/
  return kk_function_box(_x2847);
}


// lift anonymous function
struct kk_handlers__mlift2017_advance_fun2862__t {
  struct kk_function_s _base;
  kk_function_t _bv_2265;
};
static kk_box_t kk_handlers__mlift2017_advance_fun2862(kk_function_t _fself, kk_integer_t _b_2266, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2017_advance_fun2862(kk_function_t _bv_2265, kk_context_t* _ctx) {
  struct kk_handlers__mlift2017_advance_fun2862__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2017_advance_fun2862__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2017_advance_fun2862, kk_context());
  _self->_bv_2265 = _bv_2265;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift2017_advance_fun2862(kk_function_t _fself, kk_integer_t _b_2266, kk_context_t* _ctx) {
  struct kk_handlers__mlift2017_advance_fun2862__t* _self = kk_function_as(struct kk_handlers__mlift2017_advance_fun2862__t*, _fself);
  kk_function_t _bv_2265 = _self->_bv_2265; /* (2263) -> <.Box|.Box> 2264 */
  kk_drop_match(_self, {kk_function_dup(_bv_2265);}, {}, _ctx)
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _bv_2265, (_bv_2265, kk_integer_box(_b_2266), _ctx));
}


// lift anonymous function
struct kk_handlers__mlift2017_advance_fun2863__t {
  struct kk_function_s _base;
};
static kk_box_t kk_handlers__mlift2017_advance_fun2863(kk_function_t _fself, kk_box_t _b_2278, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2017_advance_fun2863(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_handlers__mlift2017_advance_fun2863, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_handlers__mlift2017_advance_fun2864__t {
  struct kk_function_s _base;
  kk_box_t _b_2278;
};
static kk_box_t kk_handlers__mlift2017_advance_fun2864(kk_function_t _fself, kk_integer_t _b_2281, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2017_advance_fun2864(kk_box_t _b_2278, kk_context_t* _ctx) {
  struct kk_handlers__mlift2017_advance_fun2864__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2017_advance_fun2864__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2017_advance_fun2864, kk_context());
  _self->_b_2278 = _b_2278;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift2017_advance_fun2864(kk_function_t _fself, kk_integer_t _b_2281, kk_context_t* _ctx) {
  struct kk_handlers__mlift2017_advance_fun2864__t* _self = kk_function_as(struct kk_handlers__mlift2017_advance_fun2864__t*, _fself);
  kk_box_t _b_2278 = _self->_b_2278; /* 1 */
  kk_drop_match(_self, {kk_box_dup(_b_2278);}, {}, _ctx)
  kk_function_t _x2865 = kk_function_unbox(_b_2278); /*(2279) -> <effects-and-types/yield|231> 2280*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x2865, (_x2865, kk_integer_box(_b_2281), _ctx));
}
static kk_box_t kk_handlers__mlift2017_advance_fun2863(kk_function_t _fself, kk_box_t _b_2278, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return kk_handlers__mlift2016_advance(kk_handlers__new_mlift2017_advance_fun2864(_b_2278, _ctx), _ctx);
}

kk_box_t kk_handlers__mlift2017_advance(kk_function_t resume, size_t _y_5, kk_context_t* _ctx) { /* forall<a,e> (resume : (()) -> e ((int) -> <effects-and-types/yield|e> a), std/core/hnd/ev-index) -> <effects-and-types/yield|e> a */ 
  kk_function_t x_2042;
  kk_evv_t w0 = kk_std_core_hnd_evv_swap_delete(_y_5, false, _ctx); /*std/core/hnd/evv<std/core/hnd/_e2>*/;
  kk_function_t x0 = kk_function_call(kk_function_t, (kk_function_t, kk_unit_t, kk_context_t*), resume, (resume, kk_Unit, _ctx)); /*(int) -> <effects-and-types/yield|231> 230*/;
  kk_unit_t __w_l645_c9 = kk_Unit;
  kk_evv_set(w0,kk_context());
  if (kk_yielding(kk_context())) {
    kk_function_drop(x0, _ctx);
    kk_function_t _bv_2265;
    kk_box_t _x2845 = kk_std_core_hnd_yield_cont(kk_handlers__new_mlift2017_advance_fun2846(_y_5, _ctx), _ctx); /*3*/
    _bv_2265 = kk_function_unbox(_x2845); /*(2263) -> <.Box|.Box> 2264*/
    x_2042 = kk_handlers__new_mlift2017_advance_fun2862(_bv_2265, _ctx); /*(int) -> <effects-and-types/yield|231> 230*/
  }
  else {
    x_2042 = x0; /*(int) -> <effects-and-types/yield|231> 230*/
  }
  if (kk_yielding(kk_context())) {
    kk_function_drop(x_2042, _ctx);
    return kk_std_core_hnd_yield_extend(kk_handlers__new_mlift2017_advance_fun2863(_ctx), _ctx);
  }
  return kk_handlers__mlift2016_advance(x_2042, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_handlers__mlift2018_advance_fun2867__t {
  struct kk_function_s _base;
  kk_function_t resume;
};
static kk_box_t kk_handlers__mlift2018_advance_fun2867(kk_function_t _fself, kk_box_t _b_2285, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2018_advance_fun2867(kk_function_t resume, kk_context_t* _ctx) {
  struct kk_handlers__mlift2018_advance_fun2867__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2018_advance_fun2867__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2018_advance_fun2867, kk_context());
  _self->resume = resume;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift2018_advance_fun2867(kk_function_t _fself, kk_box_t _b_2285, kk_context_t* _ctx) {
  struct kk_handlers__mlift2018_advance_fun2867__t* _self = kk_function_as(struct kk_handlers__mlift2018_advance_fun2867__t*, _fself);
  kk_function_t resume = _self->resume; /* (()) -> 231 ((int) -> <effects-and-types/yield|231> 230) */
  kk_drop_match(_self, {kk_function_dup(resume);}, {}, _ctx)
  size_t _x2868 = kk_size_unbox(_b_2285, _ctx); /*std/core/hnd/ev-index*/
  return kk_handlers__mlift2017_advance(resume, _x2868, _ctx);
}

kk_box_t kk_handlers__mlift2018_advance(kk_function_t resume, kk_unit_t wild__, kk_context_t* _ctx) { /* forall<a,e> (resume : (()) -> e ((int) -> <effects-and-types/yield|e> a), wild_ : ()) -> <effects-and-types/yield|e> a */ 
  size_t x_2047;
  kk_std_core_hnd__htag _x2866 = kk_std_core_hnd__htag_dup(kk_effects_dash_and_dash_types__tag_yield); /*std/core/hnd/htag<effects-and-types/.hnd-yield>*/
  x_2047 = kk_std_core_hnd__evv_index(_x2866, _ctx); /*std/core/hnd/ev-index*/
  if (kk_yielding(kk_context())) {
    return kk_std_core_hnd_yield_extend(kk_handlers__new_mlift2018_advance_fun2867(resume, _ctx), _ctx);
  }
  return kk_handlers__mlift2017_advance(resume, x_2047, _ctx);
}


// lift anonymous function
struct kk_handlers_advance_fun2870__t {
  struct kk_function_s _base;
};
static kk_box_t kk_handlers_advance_fun2870(kk_function_t _fself, kk_function_t _b_2316, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_advance_fun2870(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_handlers_advance_fun2870, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_handlers_advance_fun2872__t {
  struct kk_function_s _base;
  kk_function_t _b_2316;
};
static kk_function_t kk_handlers_advance_fun2872(kk_function_t _fself, kk_unit_t _b_2317, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_advance_fun2872(kk_function_t _b_2316, kk_context_t* _ctx) {
  struct kk_handlers_advance_fun2872__t* _self = kk_function_alloc_as(struct kk_handlers_advance_fun2872__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_advance_fun2872, kk_context());
  _self->_b_2316 = _b_2316;
  return &_self->_base;
}



// lift anonymous function
struct kk_handlers_advance_fun2874__t {
  struct kk_function_s _base;
  kk_function_t _bv_2320;
};
static kk_box_t kk_handlers_advance_fun2874(kk_function_t _fself, kk_integer_t _b_2321, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_advance_fun2874(kk_function_t _bv_2320, kk_context_t* _ctx) {
  struct kk_handlers_advance_fun2874__t* _self = kk_function_alloc_as(struct kk_handlers_advance_fun2874__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_advance_fun2874, kk_context());
  _self->_bv_2320 = _bv_2320;
  return &_self->_base;
}

static kk_box_t kk_handlers_advance_fun2874(kk_function_t _fself, kk_integer_t _b_2321, kk_context_t* _ctx) {
  struct kk_handlers_advance_fun2874__t* _self = kk_function_as(struct kk_handlers_advance_fun2874__t*, _fself);
  kk_function_t _bv_2320 = _self->_bv_2320; /* (2318) -> <effects-and-types/yield|231> 2319 */
  kk_drop_match(_self, {kk_function_dup(_bv_2320);}, {}, _ctx)
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _bv_2320, (_bv_2320, kk_integer_box(_b_2321), _ctx));
}
static kk_function_t kk_handlers_advance_fun2872(kk_function_t _fself, kk_unit_t _b_2317, kk_context_t* _ctx) {
  struct kk_handlers_advance_fun2872__t* _self = kk_function_as(struct kk_handlers_advance_fun2872__t*, _fself);
  kk_function_t _b_2316 = _self->_b_2316; /* (1) -> 2 4 */
  kk_drop_match(_self, {kk_function_dup(_b_2316);}, {}, _ctx)
  kk_function_t _bv_2320;
  kk_box_t _x2873 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _b_2316, (_b_2316, kk_unit_box(_b_2317), _ctx)); /*4*/
  _bv_2320 = kk_function_unbox(_x2873); /*(2318) -> <effects-and-types/yield|231> 2319*/
  return kk_handlers_new_advance_fun2874(_bv_2320, _ctx);
}


// lift anonymous function
struct kk_handlers_advance_fun2875__t {
  struct kk_function_s _base;
  kk_function_t resume_2344;
};
static kk_box_t kk_handlers_advance_fun2875(kk_function_t _fself, kk_integer_t a, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_advance_fun2875(kk_function_t resume_2344, kk_context_t* _ctx) {
  struct kk_handlers_advance_fun2875__t* _self = kk_function_alloc_as(struct kk_handlers_advance_fun2875__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_advance_fun2875, kk_context());
  _self->resume_2344 = resume_2344;
  return &_self->_base;
}



// lift anonymous function
struct kk_handlers_advance_fun2878__t {
  struct kk_function_s _base;
  kk_integer_t a;
  kk_function_t resume_2344;
};
static kk_box_t kk_handlers_advance_fun2878(kk_function_t _fself, kk_box_t _b_2289, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_advance_fun2878(kk_integer_t a, kk_function_t resume_2344, kk_context_t* _ctx) {
  struct kk_handlers_advance_fun2878__t* _self = kk_function_alloc_as(struct kk_handlers_advance_fun2878__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_advance_fun2878, kk_context());
  _self->a = a;
  _self->resume_2344 = resume_2344;
  return &_self->_base;
}

static kk_box_t kk_handlers_advance_fun2878(kk_function_t _fself, kk_box_t _b_2289, kk_context_t* _ctx) {
  struct kk_handlers_advance_fun2878__t* _self = kk_function_as(struct kk_handlers_advance_fun2878__t*, _fself);
  kk_integer_t a = _self->a; /* int */
  kk_function_t resume_2344 = _self->resume_2344; /* (()) -> 231 ((int) -> <effects-and-types/yield|231> 230) */
  kk_drop_match(_self, {kk_integer_dup(a);kk_function_dup(resume_2344);}, {}, _ctx)
  size_t _x2879 = kk_size_unbox(_b_2289, _ctx); /*std/core/hnd/ev-index*/
  return kk_handlers__mlift2015_advance(a, resume_2344, _x2879, _ctx);
}


// lift anonymous function
struct kk_handlers_advance_fun2887__t {
  struct kk_function_s _base;
  size_t i_2053;
};
static kk_box_t kk_handlers_advance_fun2887(kk_function_t _fself, kk_function_t _b_2303, kk_box_t _b_2304, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_advance_fun2887(size_t i_2053, kk_context_t* _ctx) {
  struct kk_handlers_advance_fun2887__t* _self = kk_function_alloc_as(struct kk_handlers_advance_fun2887__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_advance_fun2887, kk_context());
  _self->i_2053 = i_2053;
  return &_self->_base;
}

static kk_box_t kk_handlers_advance_fun2887(kk_function_t _fself, kk_function_t _b_2303, kk_box_t _b_2304, kk_context_t* _ctx) {
  struct kk_handlers_advance_fun2887__t* _self = kk_function_as(struct kk_handlers_advance_fun2887__t*, _fself);
  size_t i_2053 = _self->i_2053; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_2053, _b_2303, _b_2304, _ctx);
}


// lift anonymous function
struct kk_handlers_advance_fun2888__t {
  struct kk_function_s _base;
  kk_function_t resume_2344;
};
static kk_box_t kk_handlers_advance_fun2888(kk_function_t _fself, kk_box_t _b_2314, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_advance_fun2888(kk_function_t resume_2344, kk_context_t* _ctx) {
  struct kk_handlers_advance_fun2888__t* _self = kk_function_alloc_as(struct kk_handlers_advance_fun2888__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_advance_fun2888, kk_context());
  _self->resume_2344 = resume_2344;
  return &_self->_base;
}

static kk_box_t kk_handlers_advance_fun2888(kk_function_t _fself, kk_box_t _b_2314, kk_context_t* _ctx) {
  struct kk_handlers_advance_fun2888__t* _self = kk_function_as(struct kk_handlers_advance_fun2888__t*, _fself);
  kk_function_t resume_2344 = _self->resume_2344; /* (()) -> 231 ((int) -> <effects-and-types/yield|231> 230) */
  kk_drop_match(_self, {kk_function_dup(resume_2344);}, {}, _ctx)
  kk_unit_t _x2889 = kk_Unit;
  kk_unit_unbox(_b_2314);
  return kk_handlers__mlift2018_advance(resume_2344, _x2889, _ctx);
}
static kk_box_t kk_handlers_advance_fun2875(kk_function_t _fself, kk_integer_t a, kk_context_t* _ctx) {
  struct kk_handlers_advance_fun2875__t* _self = kk_function_as(struct kk_handlers_advance_fun2875__t*, _fself);
  kk_function_t resume_2344 = _self->resume_2344; /* (()) -> 231 ((int) -> <effects-and-types/yield|231> 230) */
  kk_drop_match(_self, {kk_function_dup(resume_2344);}, {}, _ctx)
  bool _match_2813;
  kk_integer_t _x2876 = kk_integer_dup(a); /*int*/
  _match_2813 = kk_integer_gt(_x2876,(kk_integer_from_small(0)),kk_context()); /*bool*/
  if (_match_2813) {
    size_t x_2049;
    kk_std_core_hnd__htag _x2877 = kk_std_core_hnd__htag_dup(kk_effects_dash_and_dash_types__tag_yield); /*std/core/hnd/htag<effects-and-types/.hnd-yield>*/
    x_2049 = kk_std_core_hnd__evv_index(_x2877, _ctx); /*std/core/hnd/ev-index*/
    if (kk_yielding(kk_context())) {
      return kk_std_core_hnd_yield_extend(kk_handlers_new_advance_fun2878(a, resume_2344, _ctx), _ctx);
    }
    return kk_handlers__mlift2015_advance(a, resume_2344, x_2049, _ctx);
  }
  kk_integer_drop(a, _ctx);
  kk_unit_t x0_2051 = kk_Unit;
  size_t i_2053;
  kk_std_core_hnd__htag _x2880 = kk_std_core_hnd__htag_dup(kk_effects_dash_and_dash_types__tag_yield); /*std/core/hnd/htag<effects-and-types/.hnd-yield>*/
  i_2053 = kk_std_core_hnd__evv_index(_x2880, _ctx); /*std/core/hnd/ev-index*/
  kk_evv_t w = kk_evv_swap_create1(i_2053,kk_context()); /*std/core/hnd/evv<<effects-and-types/yield|231>>*/;
  kk_unit_t y = kk_Unit;
  kk_std_core_hnd__ev ev_409;
  size_t _x2881 = ((size_t)0); /*size_t*/
  ev_409 = kk_evv_at(_x2881,kk_context()); /*std/core/hnd/ev<effects-and-types/.hnd-yield>*/
  kk_box_t _x2882;
  struct kk_std_core_hnd_Ev* _con2883 = kk_std_core_hnd__as_Ev(ev_409);
  kk_std_core_hnd__marker m = _con2883->marker;
  kk_box_t _box_x2290 = _con2883->hnd;
  kk_effects_dash_and_dash_types__hnd_yield h = kk_effects_dash_and_dash_types__hnd_yield_unbox(_box_x2290, NULL);
  kk_effects_dash_and_dash_types__hnd_yield_dup(h);
  kk_std_core_hnd__clause0 _match_2816;
  struct kk_effects_dash_and_dash_types__Hnd_yield* _con2885 = kk_effects_dash_and_dash_types__as_Hnd_yield(h);
  kk_std_core_hnd__clause0 control_yield = _con2885->control_yield;
  if (kk_effects_dash_and_dash_types__hnd_yield_is_unique(h)) {
    kk_effects_dash_and_dash_types__hnd_yield_free(h);
  }
  else {
    kk_std_core_hnd__clause0_dup(control_yield);
    kk_effects_dash_and_dash_types__hnd_yield_decref(h, _ctx);
  }
  _match_2816 = control_yield; /*std/core/hnd/clause0<(),effects-and-types/.hnd-yield,6,7>*/
  kk_function_t _fun_unbox_x2293 = _match_2816.clause;
  _x2882 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x2293, (_fun_unbox_x2293, m, ev_409, _ctx)); /*6*/
  kk_unit_unbox(_x2882);
  kk_unit_t __w_l683_c9 = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x2886 = kk_std_core_hnd_yield_cont(kk_handlers_new_advance_fun2887(i_2053, _ctx), _ctx); /*3*/
    kk_unit_unbox(_x2886);
  }
  else {
    y;
  }
  if (kk_yielding(kk_context())) {
    return kk_std_core_hnd_yield_extend(kk_handlers_new_advance_fun2888(resume_2344, _ctx), _ctx);
  }
  return kk_handlers__mlift2018_advance(resume_2344, x0_2051, _ctx);
}


// lift anonymous function
struct kk_handlers_advance_fun2890__t {
  struct kk_function_s _base;
  kk_function_t _bv_2324;
};
static kk_box_t kk_handlers_advance_fun2890(kk_function_t _fself, kk_box_t _b_2325, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_advance_fun2890(kk_function_t _bv_2324, kk_context_t* _ctx) {
  struct kk_handlers_advance_fun2890__t* _self = kk_function_alloc_as(struct kk_handlers_advance_fun2890__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_advance_fun2890, kk_context());
  _self->_bv_2324 = _bv_2324;
  return &_self->_base;
}

static kk_box_t kk_handlers_advance_fun2890(kk_function_t _fself, kk_box_t _b_2325, kk_context_t* _ctx) {
  struct kk_handlers_advance_fun2890__t* _self = kk_function_as(struct kk_handlers_advance_fun2890__t*, _fself);
  kk_function_t _bv_2324 = _self->_bv_2324; /* (a : int) -> <effects-and-types/yield|231> 230 */
  kk_drop_match(_self, {kk_function_dup(_bv_2324);}, {}, _ctx)
  kk_integer_t _x2891 = kk_integer_unbox(_b_2325); /*int*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_context_t*), _bv_2324, (_bv_2324, _x2891, _ctx));
}
static kk_box_t kk_handlers_advance_fun2870(kk_function_t _fself, kk_function_t _b_2316, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_function_t _x2871;
  kk_function_t _bv_2324;
  kk_function_t resume_2344 = kk_handlers_new_advance_fun2872(_b_2316, _ctx); /*(()) -> 231 ((int) -> <effects-and-types/yield|231> 230)*/;
  _bv_2324 = kk_handlers_new_advance_fun2875(resume_2344, _ctx); /*(a : int) -> <effects-and-types/yield|231> 230*/
  _x2871 = kk_handlers_new_advance_fun2890(_bv_2324, _ctx); /*(2322) -> <effects-and-types/yield|231> 230*/
  return kk_function_box(_x2871);
}


// lift anonymous function
struct kk_handlers_advance_fun2893__t {
  struct kk_function_s _base;
};
static kk_box_t kk_handlers_advance_fun2893(kk_function_t _fself, kk_box_t _b_2330, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_advance_fun2893(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_handlers_advance_fun2893, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_handlers_advance_fun2895__t {
  struct kk_function_s _base;
  kk_box_t _b_2330;
};
static kk_box_t kk_handlers_advance_fun2895(kk_function_t _fself, kk_integer_t ___wildcard__87__21, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_advance_fun2895(kk_box_t _b_2330, kk_context_t* _ctx) {
  struct kk_handlers_advance_fun2895__t* _self = kk_function_alloc_as(struct kk_handlers_advance_fun2895__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_advance_fun2895, kk_context());
  _self->_b_2330 = _b_2330;
  return &_self->_base;
}

static kk_box_t kk_handlers_advance_fun2895(kk_function_t _fself, kk_integer_t ___wildcard__87__21, kk_context_t* _ctx) {
  struct kk_handlers_advance_fun2895__t* _self = kk_function_as(struct kk_handlers_advance_fun2895__t*, _fself);
  kk_box_t _b_2330 = _self->_b_2330; /* 281 */
  kk_drop_match(_self, {kk_box_dup(_b_2330);}, {}, _ctx)
  kk_integer_drop(___wildcard__87__21, _ctx);
  return _b_2330;
}


// lift anonymous function
struct kk_handlers_advance_fun2896__t {
  struct kk_function_s _base;
  kk_function_t _bv_2333;
};
static kk_box_t kk_handlers_advance_fun2896(kk_function_t _fself, kk_box_t _b_2334, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_advance_fun2896(kk_function_t _bv_2333, kk_context_t* _ctx) {
  struct kk_handlers_advance_fun2896__t* _self = kk_function_alloc_as(struct kk_handlers_advance_fun2896__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_advance_fun2896, kk_context());
  _self->_bv_2333 = _bv_2333;
  return &_self->_base;
}

static kk_box_t kk_handlers_advance_fun2896(kk_function_t _fself, kk_box_t _b_2334, kk_context_t* _ctx) {
  struct kk_handlers_advance_fun2896__t* _self = kk_function_as(struct kk_handlers_advance_fun2896__t*, _fself);
  kk_function_t _bv_2333 = _self->_bv_2333; /* (int) -> <effects-and-types/yield|231> 230 */
  kk_drop_match(_self, {kk_function_dup(_bv_2333);}, {}, _ctx)
  kk_integer_t _x2897 = kk_integer_unbox(_b_2334); /*int*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_context_t*), _bv_2333, (_bv_2333, _x2897, _ctx));
}
static kk_box_t kk_handlers_advance_fun2893(kk_function_t _fself, kk_box_t _b_2330, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_function_t _x2894;
  kk_function_t _bv_2333 = kk_handlers_new_advance_fun2895(_b_2330, _ctx); /*(int) -> <effects-and-types/yield|231> 230*/;
  _x2894 = kk_handlers_new_advance_fun2896(_bv_2333, _ctx); /*(2331) -> <effects-and-types/yield|231> 230*/
  return kk_function_box(_x2894);
}


// lift anonymous function
struct kk_handlers_advance_fun2898__t {
  struct kk_function_s _base;
  kk_function_t _bv_2337;
};
static kk_box_t kk_handlers_advance_fun2898(kk_function_t _fself, kk_integer_t _b_2338, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_advance_fun2898(kk_function_t _bv_2337, kk_context_t* _ctx) {
  struct kk_handlers_advance_fun2898__t* _self = kk_function_alloc_as(struct kk_handlers_advance_fun2898__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_advance_fun2898, kk_context());
  _self->_bv_2337 = _bv_2337;
  return &_self->_base;
}

static kk_box_t kk_handlers_advance_fun2898(kk_function_t _fself, kk_integer_t _b_2338, kk_context_t* _ctx) {
  struct kk_handlers_advance_fun2898__t* _self = kk_function_as(struct kk_handlers_advance_fun2898__t*, _fself);
  kk_function_t _bv_2337 = _self->_bv_2337; /* (a : 2335) -> <effects-and-types/yield|231> 2336 */
  kk_drop_match(_self, {kk_function_dup(_bv_2337);}, {}, _ctx)
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _bv_2337, (_bv_2337, kk_integer_box(_b_2338), _ctx));
}

kk_function_t kk_handlers_advance(kk_function_t action, kk_context_t* _ctx) { /* forall<a,e> (action : () -> <effects-and-types/yield|e> a) -> e ((a : int) -> <effects-and-types/yield|e> a) */ 
  int32_t _b_2339_2326 = ((int32_t)3); /*int32*/;
  kk_effects_dash_and_dash_types__hnd_yield _b_2340_2327;
  kk_std_core_hnd__clause0 _x2869 = kk_std_core_hnd_clause_control0(kk_handlers_new_advance_fun2870(_ctx), _ctx); /*std/core/hnd/clause0<1,3,2,4>*/
  _b_2340_2327 = kk_effects_dash_and_dash_types__new_Hnd_yield(kk_reuse_null, _x2869, _ctx); /*effects-and-types/.hnd-yield<231,(a : int) -> <effects-and-types/yield|231> 230>*/
  kk_function_t _bv_2337;
  kk_box_t _x2892 = kk_effects_dash_and_dash_types__handle_yield(_b_2339_2326, _b_2340_2327, kk_handlers_new_advance_fun2893(_ctx), action, _ctx); /*283*/
  _bv_2337 = kk_function_unbox(_x2892); /*(a : 2335) -> <effects-and-types/yield|231> 2336*/
  return kk_handlers_new_advance_fun2898(_bv_2337, _ctx);
}


// lift anonymous function
struct kk_handlers_finalize_fun2901__t {
  struct kk_function_s _base;
};
static kk_box_t kk_handlers_finalize_fun2901(kk_function_t _fself, kk_std_core_hnd__marker _b_2351, kk_std_core_hnd__ev _b_2352, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_finalize_fun2901(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_handlers_finalize_fun2901, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_handlers_finalize_fun2901(kk_function_t _fself, kk_std_core_hnd__marker _b_2351, kk_std_core_hnd__ev _b_2352, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core_hnd__ev_dropn(_b_2352, ((int32_t)3), _ctx);
  return kk_unit_box(kk_Unit);
}


// lift anonymous function
struct kk_handlers_finalize_fun2902__t {
  struct kk_function_s _base;
};
static kk_box_t kk_handlers_finalize_fun2902(kk_function_t _fself, kk_box_t _x, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_finalize_fun2902(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_handlers_finalize_fun2902, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_handlers_finalize_fun2902(kk_function_t _fself, kk_box_t _x, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return _x;
}

kk_box_t kk_handlers_finalize(kk_function_t action, kk_context_t* _ctx) { /* forall<a,e> (action : () -> <effects-and-types/yield|e> a) -> e a */ 
  kk_effects_dash_and_dash_types__hnd_yield _x2899;
  kk_std_core_hnd__clause0 _x2900 = kk_std_core_hnd__new_Clause0(kk_handlers_new_finalize_fun2901(_ctx), _ctx); /*std/core/hnd/clause0<11,12,13,14>*/
  _x2899 = kk_effects_dash_and_dash_types__new_Hnd_yield(kk_reuse_null, _x2900, _ctx); /*effects-and-types/.hnd-yield<25,26>*/
  return kk_effects_dash_and_dash_types__handle_yield(((int32_t)1), _x2899, kk_handlers_new_finalize_fun2902(_ctx), action, _ctx);
}


// lift anonymous function
struct kk_handlers_random__sampler_fun2905__t {
  struct kk_function_s _base;
};
static kk_box_t kk_handlers_random__sampler_fun2905(kk_function_t _fself, kk_std_core_hnd__marker _b_2380, kk_std_core_hnd__ev _b_2381, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_random__sampler_fun2905(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_handlers_random__sampler_fun2905, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_handlers_random__sampler_fun2910__t {
  struct kk_function_s _base;
  size_t i_2057;
};
static kk_box_t kk_handlers_random__sampler_fun2910(kk_function_t _fself, kk_function_t _b_2361, kk_box_t _b_2362, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_random__sampler_fun2910(size_t i_2057, kk_context_t* _ctx) {
  struct kk_handlers_random__sampler_fun2910__t* _self = kk_function_alloc_as(struct kk_handlers_random__sampler_fun2910__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_random__sampler_fun2910, kk_context());
  _self->i_2057 = i_2057;
  return &_self->_base;
}

static kk_box_t kk_handlers_random__sampler_fun2910(kk_function_t _fself, kk_function_t _b_2361, kk_box_t _b_2362, kk_context_t* _ctx) {
  struct kk_handlers_random__sampler_fun2910__t* _self = kk_function_as(struct kk_handlers_random__sampler_fun2910__t*, _fself);
  size_t i_2057 = _self->i_2057; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_2057, _b_2361, _b_2362, _ctx);
}


// lift anonymous function
struct kk_handlers_random__sampler_fun2912__t {
  struct kk_function_s _base;
  kk_std_core_hnd__ev _b_2381;
};
static kk_box_t kk_handlers_random__sampler_fun2912(kk_function_t _fself, kk_function_t _b_2376, kk_box_t _b_2377, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_random__sampler_fun2912(kk_std_core_hnd__ev _b_2381, kk_context_t* _ctx) {
  struct kk_handlers_random__sampler_fun2912__t* _self = kk_function_alloc_as(struct kk_handlers_random__sampler_fun2912__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_random__sampler_fun2912, kk_context());
  _self->_b_2381 = _b_2381;
  return &_self->_base;
}

static kk_box_t kk_handlers_random__sampler_fun2912(kk_function_t _fself, kk_function_t _b_2376, kk_box_t _b_2377, kk_context_t* _ctx) {
  struct kk_handlers_random__sampler_fun2912__t* _self = kk_function_as(struct kk_handlers_random__sampler_fun2912__t*, _fself);
  kk_std_core_hnd__ev _b_2381 = _self->_b_2381; /* std/core/hnd/ev<12> */
  kk_drop_match(_self, {kk_std_core_hnd__ev_dup(_b_2381);}, {}, _ctx)
  return kk_std_core_hnd_under1(_b_2381, _b_2376, _b_2377, _ctx);
}
static kk_box_t kk_handlers_random__sampler_fun2905(kk_function_t _fself, kk_std_core_hnd__marker _b_2380, kk_std_core_hnd__ev _b_2381, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x2906;
  kk_evv_t w0;
  kk_std_core_hnd__ev _x2907 = kk_std_core_hnd__ev_dup(_b_2381); /*std/core/hnd/ev<12>*/
  w0 = kk_std_core_hnd_evv_swap_with(_x2907, _ctx); /*std/core/hnd/evv<std/core/hnd/_e1>*/
  double y;
  size_t i_2057;
  kk_std_core_hnd__htag _x2908 = kk_std_core_hnd__htag_dup(kk_std_num_random__tag_random); /*std/core/hnd/htag<std/num/random/.hnd-random>*/
  i_2057 = kk_std_core_hnd__evv_index(_x2908, _ctx); /*std/core/hnd/ev-index*/
  kk_evv_t w = kk_evv_swap_create1(i_2057,kk_context()); /*std/core/hnd/evv<<std/num/random/random|329>>*/;
  double y0 = kk_std_num_random_random_double(_ctx); /*double*/;
  kk_unit_t __w_l683_c9 = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x2909 = kk_std_core_hnd_yield_cont(kk_handlers_new_random__sampler_fun2910(i_2057, _ctx), _ctx); /*3*/
    y = kk_double_unbox(_x2909, _ctx); /*double*/
  }
  else {
    y = y0; /*double*/
  }
  kk_unit_t __w_l1003_c9 = kk_Unit;
  kk_evv_set(w0,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x2911 = kk_std_core_hnd_yield_cont(kk_handlers_new_random__sampler_fun2912(_b_2381, _ctx), _ctx); /*3*/
    _x2906 = kk_double_unbox(_x2911, _ctx); /*double*/
  }
  else {
    kk_std_core_hnd__ev_dropn(_b_2381, ((int32_t)3), _ctx);
    _x2906 = y; /*double*/
  }
  return kk_double_box(_x2906, _ctx);
}


// lift anonymous function
struct kk_handlers_random__sampler_fun2913__t {
  struct kk_function_s _base;
};
static kk_box_t kk_handlers_random__sampler_fun2913(kk_function_t _fself, kk_box_t _x, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_random__sampler_fun2913(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_handlers_random__sampler_fun2913, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_handlers_random__sampler_fun2913(kk_function_t _fself, kk_box_t _x, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return _x;
}

kk_box_t kk_handlers_random__sampler(kk_function_t action, kk_context_t* _ctx) { /* forall<a,e> (action : () -> <effects-and-types/sample,std/num/random/random|e> a) -> <std/num/random/random|e> a */ 
  kk_effects_dash_and_dash_types__hnd_sample _x2903;
  kk_std_core_hnd__clause0 _x2904 = kk_std_core_hnd__new_Clause0(kk_handlers_new_random__sampler_fun2905(_ctx), _ctx); /*std/core/hnd/clause0<11,12,13,14>*/
  _x2903 = kk_effects_dash_and_dash_types__new_Hnd_sample(kk_reuse_null, _x2904, _ctx); /*effects-and-types/.hnd-sample<6,7>*/
  return kk_effects_dash_and_dash_types__handle_sample(((int32_t)1), _x2903, kk_handlers_new_random__sampler_fun2913(_ctx), action, _ctx);
}
 
// monadic lift

double kk_handlers__mlift2019_recorder(double rand__choice, kk_unit_t wild__, kk_context_t* _ctx) { /* forall<h,e> (rand_choice : double, wild_ : ()) -> <local<h>,effects-and-types/sample|e> double */ 
  return rand__choice;
}
 
// monadic lift


// lift anonymous function
struct kk_handlers__mlift2020_recorder_fun2915__t {
  struct kk_function_s _base;
  double rand__choice;
};
static kk_box_t kk_handlers__mlift2020_recorder_fun2915(kk_function_t _fself, kk_box_t _b_2401, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2020_recorder_fun2915(double rand__choice, kk_context_t* _ctx) {
  struct kk_handlers__mlift2020_recorder_fun2915__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2020_recorder_fun2915__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2020_recorder_fun2915, kk_context());
  _self->rand__choice = rand__choice;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift2020_recorder_fun2915(kk_function_t _fself, kk_box_t _b_2401, kk_context_t* _ctx) {
  struct kk_handlers__mlift2020_recorder_fun2915__t* _self = kk_function_as(struct kk_handlers__mlift2020_recorder_fun2915__t*, _fself);
  double rand__choice = _self->rand__choice; /* double */
  kk_drop_match(_self, {;}, {}, _ctx)
  double _x2916;
  kk_unit_t _x2917 = kk_Unit;
  kk_unit_unbox(_b_2401);
  _x2916 = kk_handlers__mlift2019_recorder(rand__choice, _x2917, _ctx); /*double*/
  return kk_double_box(_x2916, _ctx);
}

double kk_handlers__mlift2020_recorder(double rand__choice, kk_ref_t trace, kk_std_core__list _y_15, kk_context_t* _ctx) { /* forall<h,e> (rand_choice : double, trace : local-var<h,effects-and-types/trace_values>, effects-and-types/trace_values) -> <local<h>,effects-and-types/sample|e> double */ 
  kk_unit_t x_2059 = kk_Unit;
  kk_std_core__list _b_2399_2397;
  kk_std_core__list ys_2062 = kk_std_core__new_Cons(kk_reuse_null, kk_double_box(rand__choice, _ctx), kk_std_core__new_Nil(_ctx), _ctx); /*list<double>*/;
  _b_2399_2397 = kk_std_core_append(_y_15, ys_2062, _ctx); /*list<double>*/
  (kk_ref_set(trace,(kk_std_core__list_box(_b_2399_2397, _ctx)),kk_context()));
  if (kk_yielding(kk_context())) {
    kk_box_t _x2914 = kk_std_core_hnd_yield_extend(kk_handlers__new_mlift2020_recorder_fun2915(rand__choice, _ctx), _ctx); /*2*/
    return kk_double_unbox(_x2914, _ctx);
  }
  return kk_handlers__mlift2019_recorder(rand__choice, x_2059, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_handlers__mlift2021_recorder_fun2921__t {
  struct kk_function_s _base;
  kk_ref_t trace;
  double rand__choice;
};
static kk_box_t kk_handlers__mlift2021_recorder_fun2921(kk_function_t _fself, kk_box_t _b_2407, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2021_recorder_fun2921(kk_ref_t trace, double rand__choice, kk_context_t* _ctx) {
  struct kk_handlers__mlift2021_recorder_fun2921__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2021_recorder_fun2921__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2021_recorder_fun2921, kk_context());
  _self->trace = trace;
  _self->rand__choice = rand__choice;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift2021_recorder_fun2921(kk_function_t _fself, kk_box_t _b_2407, kk_context_t* _ctx) {
  struct kk_handlers__mlift2021_recorder_fun2921__t* _self = kk_function_as(struct kk_handlers__mlift2021_recorder_fun2921__t*, _fself);
  kk_ref_t trace = _self->trace; /* local-var<618,effects-and-types/trace_values> */
  double rand__choice = _self->rand__choice; /* double */
  kk_drop_match(_self, {kk_ref_dup(trace);;}, {}, _ctx)
  double _x2922;
  kk_std_core__list _x2923 = kk_std_core__list_unbox(_b_2407, _ctx); /*effects-and-types/trace_values*/
  _x2922 = kk_handlers__mlift2020_recorder(rand__choice, trace, _x2923, _ctx); /*double*/
  return kk_double_box(_x2922, _ctx);
}

double kk_handlers__mlift2021_recorder(kk_ref_t trace, double rand__choice, kk_context_t* _ctx) { /* forall<h,e> (trace : local-var<h,effects-and-types/trace_values>, rand_choice : double) -> <effects-and-types/sample,local<h>|e> double */ 
  kk_std_core__list x_2063;
  kk_box_t _x2918;
  kk_ref_t _x2919 = kk_ref_dup(trace); /*local-var<618,effects-and-types/trace_values>*/
  _x2918 = (kk_ref_get(_x2919,kk_context())); /*0*/
  x_2063 = kk_std_core__list_unbox(_x2918, _ctx); /*effects-and-types/trace_values*/
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_2063, _ctx);
    kk_box_t _x2920 = kk_std_core_hnd_yield_extend(kk_handlers__new_mlift2021_recorder_fun2921(trace, rand__choice, _ctx), _ctx); /*2*/
    return kk_double_unbox(_x2920, _ctx);
  }
  return kk_handlers__mlift2020_recorder(rand__choice, trace, x_2063, _ctx);
}
 
// monadic lift

kk_std_core_types__tuple3_ kk_handlers__mlift2022_recorder(kk_box_t a, kk_box_t b, kk_std_core__list _y_17, kk_context_t* _ctx) { /* forall<h,a,b,e> (a : a, b : b, effects-and-types/trace_values) -> <local<h>,effects-and-types/sample|e> (effects-and-types/trace_values, a, b) */ 
  return kk_std_core_types__new_dash__lp__comma__comma__rp_(kk_std_core__list_box(_y_17, _ctx), a, b, _ctx);
}


// lift anonymous function
struct kk_handlers_recorder_fun2926__t {
  struct kk_function_s _base;
  kk_ref_t loc;
};
static kk_box_t kk_handlers_recorder_fun2926(kk_function_t _fself, kk_std_core_hnd__marker _b_2454, kk_std_core_hnd__ev _b_2455, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_recorder_fun2926(kk_ref_t loc, kk_context_t* _ctx) {
  struct kk_handlers_recorder_fun2926__t* _self = kk_function_alloc_as(struct kk_handlers_recorder_fun2926__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_recorder_fun2926, kk_context());
  _self->loc = loc;
  return &_self->_base;
}



// lift anonymous function
struct kk_handlers_recorder_fun2936__t {
  struct kk_function_s _base;
  size_t i_2072;
};
static kk_box_t kk_handlers_recorder_fun2936(kk_function_t _fself, kk_function_t _b_2431, kk_box_t _b_2432, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_recorder_fun2936(size_t i_2072, kk_context_t* _ctx) {
  struct kk_handlers_recorder_fun2936__t* _self = kk_function_alloc_as(struct kk_handlers_recorder_fun2936__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_recorder_fun2936, kk_context());
  _self->i_2072 = i_2072;
  return &_self->_base;
}

static kk_box_t kk_handlers_recorder_fun2936(kk_function_t _fself, kk_function_t _b_2431, kk_box_t _b_2432, kk_context_t* _ctx) {
  struct kk_handlers_recorder_fun2936__t* _self = kk_function_as(struct kk_handlers_recorder_fun2936__t*, _fself);
  size_t i_2072 = _self->i_2072; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_2072, _b_2431, _b_2432, _ctx);
}


// lift anonymous function
struct kk_handlers_recorder_fun2938__t {
  struct kk_function_s _base;
  kk_ref_t loc;
};
static kk_box_t kk_handlers_recorder_fun2938(kk_function_t _fself, kk_box_t _b_2442, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_recorder_fun2938(kk_ref_t loc, kk_context_t* _ctx) {
  struct kk_handlers_recorder_fun2938__t* _self = kk_function_alloc_as(struct kk_handlers_recorder_fun2938__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_recorder_fun2938, kk_context());
  _self->loc = loc;
  return &_self->_base;
}

static kk_box_t kk_handlers_recorder_fun2938(kk_function_t _fself, kk_box_t _b_2442, kk_context_t* _ctx) {
  struct kk_handlers_recorder_fun2938__t* _self = kk_function_as(struct kk_handlers_recorder_fun2938__t*, _fself);
  kk_ref_t loc = _self->loc; /* local-var<global,effects-and-types/trace_values> */
  kk_drop_match(_self, {kk_ref_dup(loc);}, {}, _ctx)
  double _x2939;
  double _x2940 = kk_double_unbox(_b_2442, _ctx); /*double*/
  _x2939 = kk_handlers__mlift2021_recorder(loc, _x2940, _ctx); /*double*/
  return kk_double_box(_x2939, _ctx);
}


// lift anonymous function
struct kk_handlers_recorder_fun2942__t {
  struct kk_function_s _base;
  kk_std_core_hnd__ev _b_2455;
};
static kk_box_t kk_handlers_recorder_fun2942(kk_function_t _fself, kk_function_t _b_2450, kk_box_t _b_2451, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_recorder_fun2942(kk_std_core_hnd__ev _b_2455, kk_context_t* _ctx) {
  struct kk_handlers_recorder_fun2942__t* _self = kk_function_alloc_as(struct kk_handlers_recorder_fun2942__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_recorder_fun2942, kk_context());
  _self->_b_2455 = _b_2455;
  return &_self->_base;
}

static kk_box_t kk_handlers_recorder_fun2942(kk_function_t _fself, kk_function_t _b_2450, kk_box_t _b_2451, kk_context_t* _ctx) {
  struct kk_handlers_recorder_fun2942__t* _self = kk_function_as(struct kk_handlers_recorder_fun2942__t*, _fself);
  kk_std_core_hnd__ev _b_2455 = _self->_b_2455; /* std/core/hnd/ev<12> */
  kk_drop_match(_self, {kk_std_core_hnd__ev_dup(_b_2455);}, {}, _ctx)
  return kk_std_core_hnd_under1(_b_2455, _b_2450, _b_2451, _ctx);
}
static kk_box_t kk_handlers_recorder_fun2926(kk_function_t _fself, kk_std_core_hnd__marker _b_2454, kk_std_core_hnd__ev _b_2455, kk_context_t* _ctx) {
  struct kk_handlers_recorder_fun2926__t* _self = kk_function_as(struct kk_handlers_recorder_fun2926__t*, _fself);
  kk_ref_t loc = _self->loc; /* local-var<global,effects-and-types/trace_values> */
  kk_drop_match(_self, {kk_ref_dup(loc);}, {}, _ctx)
  double _x2927;
  kk_evv_t w0;
  kk_std_core_hnd__ev _x2928 = kk_std_core_hnd__ev_dup(_b_2455); /*std/core/hnd/ev<12>*/
  w0 = kk_std_core_hnd_evv_swap_with(_x2928, _ctx); /*std/core/hnd/evv<std/core/hnd/_e1>*/
  double y;
  double x_2070;
  size_t i_2072;
  kk_std_core_hnd__htag _x2929 = kk_std_core_hnd__htag_dup(kk_effects_dash_and_dash_types__tag_sample); /*std/core/hnd/htag<effects-and-types/.hnd-sample>*/
  i_2072 = kk_std_core_hnd__evv_index(_x2929, _ctx); /*std/core/hnd/ev-index*/
  kk_evv_t w = kk_evv_swap_create1(i_2072,kk_context()); /*std/core/hnd/evv<<effects-and-types/sample,local<global>|629>>*/;
  double y0;
  kk_std_core_hnd__ev ev_404;
  size_t _x2930 = ((size_t)0); /*size_t*/
  ev_404 = kk_evv_at(_x2930,kk_context()); /*std/core/hnd/ev<effects-and-types/.hnd-sample>*/
  kk_box_t _x2931;
  struct kk_std_core_hnd_Ev* _con2932 = kk_std_core_hnd__as_Ev(ev_404);
  kk_std_core_hnd__marker m = _con2932->marker;
  kk_box_t _box_x2418 = _con2932->hnd;
  kk_effects_dash_and_dash_types__hnd_sample h = kk_effects_dash_and_dash_types__hnd_sample_unbox(_box_x2418, NULL);
  kk_effects_dash_and_dash_types__hnd_sample_dup(h);
  kk_std_core_hnd__clause0 _match_2808;
  struct kk_effects_dash_and_dash_types__Hnd_sample* _con2934 = kk_effects_dash_and_dash_types__as_Hnd_sample(h);
  kk_std_core_hnd__clause0 fun_sample = _con2934->fun_sample;
  if (kk_effects_dash_and_dash_types__hnd_sample_is_unique(h)) {
    kk_effects_dash_and_dash_types__hnd_sample_free(h);
  }
  else {
    kk_std_core_hnd__clause0_dup(fun_sample);
    kk_effects_dash_and_dash_types__hnd_sample_decref(h, _ctx);
  }
  _match_2808 = fun_sample; /*std/core/hnd/clause0<double,effects-and-types/.hnd-sample,6,7>*/
  kk_function_t _fun_unbox_x2421 = _match_2808.clause;
  _x2931 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x2421, (_fun_unbox_x2421, m, ev_404, _ctx)); /*6*/
  y0 = kk_double_unbox(_x2931, _ctx); /*double*/
  kk_unit_t __w_l683_c9 = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x2935 = kk_std_core_hnd_yield_cont(kk_handlers_new_recorder_fun2936(i_2072, _ctx), _ctx); /*3*/
    x_2070 = kk_double_unbox(_x2935, _ctx); /*double*/
  }
  else {
    x_2070 = y0; /*double*/
  }
  if (kk_yielding(kk_context())) {
    kk_box_t _x2937 = kk_std_core_hnd_yield_extend(kk_handlers_new_recorder_fun2938(loc, _ctx), _ctx); /*2*/
    y = kk_double_unbox(_x2937, _ctx); /*double*/
  }
  else {
    y = kk_handlers__mlift2021_recorder(loc, x_2070, _ctx); /*double*/
  }
  kk_unit_t __w_l1003_c9 = kk_Unit;
  kk_evv_set(w0,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x2941 = kk_std_core_hnd_yield_cont(kk_handlers_new_recorder_fun2942(_b_2455, _ctx), _ctx); /*3*/
    _x2927 = kk_double_unbox(_x2941, _ctx); /*double*/
  }
  else {
    kk_std_core_hnd__ev_dropn(_b_2455, ((int32_t)3), _ctx);
    _x2927 = y; /*double*/
  }
  return kk_double_box(_x2927, _ctx);
}


// lift anonymous function
struct kk_handlers_recorder_fun2945__t {
  struct kk_function_s _base;
  kk_ref_t loc;
};
static kk_box_t kk_handlers_recorder_fun2945(kk_function_t _fself, kk_box_t _b_2465, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_recorder_fun2945(kk_ref_t loc, kk_context_t* _ctx) {
  struct kk_handlers_recorder_fun2945__t* _self = kk_function_alloc_as(struct kk_handlers_recorder_fun2945__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_recorder_fun2945, kk_context());
  _self->loc = loc;
  return &_self->_base;
}



// lift anonymous function
struct kk_handlers_recorder_fun2949__t {
  struct kk_function_s _base;
  kk_box_t a;
  kk_box_t b;
};
static kk_box_t kk_handlers_recorder_fun2949(kk_function_t _fself, kk_box_t _b_2459, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_recorder_fun2949(kk_box_t a, kk_box_t b, kk_context_t* _ctx) {
  struct kk_handlers_recorder_fun2949__t* _self = kk_function_alloc_as(struct kk_handlers_recorder_fun2949__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_recorder_fun2949, kk_context());
  _self->a = a;
  _self->b = b;
  return &_self->_base;
}

static kk_box_t kk_handlers_recorder_fun2949(kk_function_t _fself, kk_box_t _b_2459, kk_context_t* _ctx) {
  struct kk_handlers_recorder_fun2949__t* _self = kk_function_as(struct kk_handlers_recorder_fun2949__t*, _fself);
  kk_box_t a = _self->a; /* 627 */
  kk_box_t b = _self->b; /* 628 */
  kk_drop_match(_self, {kk_box_dup(a);kk_box_dup(b);}, {}, _ctx)
  kk_std_core_types__tuple3_ _x2950;
  kk_std_core__list _x2951 = kk_std_core__list_unbox(_b_2459, _ctx); /*effects-and-types/trace_values*/
  _x2950 = kk_handlers__mlift2022_recorder(a, b, _x2951, _ctx); /*(effects-and-types/trace_values, 627, 628)*/
  return kk_std_core_types__tuple3__box(_x2950, _ctx);
}
static kk_box_t kk_handlers_recorder_fun2945(kk_function_t _fself, kk_box_t _b_2465, kk_context_t* _ctx) {
  struct kk_handlers_recorder_fun2945__t* _self = kk_function_as(struct kk_handlers_recorder_fun2945__t*, _fself);
  kk_ref_t loc = _self->loc; /* local-var<global,effects-and-types/trace_values> */
  kk_drop_match(_self, {kk_ref_dup(loc);}, {}, _ctx)
  kk_std_core_types__tuple3_ _x2946;
  kk_std_core_types__tuple2_ _match_2803 = kk_std_core_types__tuple2__unbox(_b_2465, _ctx); /*(627, 628)*/;
  kk_box_t a = _match_2803.fst;
  kk_box_t b = _match_2803.snd;
  kk_box_dup(a);
  kk_box_dup(b);
  kk_std_core_types__tuple2__drop(_match_2803, _ctx);
  kk_std_core__list x1_2074;
  kk_box_t _x2947 = (kk_ref_get(loc,kk_context())); /*0*/
  x1_2074 = kk_std_core__list_unbox(_x2947, _ctx); /*effects-and-types/trace_values*/
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x1_2074, _ctx);
    kk_box_t _x2948 = kk_std_core_hnd_yield_extend(kk_handlers_new_recorder_fun2949(a, b, _ctx), _ctx); /*2*/
    _x2946 = kk_std_core_types__tuple3__unbox(_x2948, _ctx); /*(effects-and-types/trace_values, 627, 628)*/
  }
  else {
    _x2946 = kk_handlers__mlift2022_recorder(a, b, x1_2074, _ctx); /*(effects-and-types/trace_values, 627, 628)*/
  }
  return kk_std_core_types__tuple3__box(_x2946, _ctx);
}


// lift anonymous function
struct kk_handlers_recorder_fun2952__t {
  struct kk_function_s _base;
  kk_function_t action;
};
static kk_box_t kk_handlers_recorder_fun2952(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_recorder_fun2952(kk_function_t action, kk_context_t* _ctx) {
  struct kk_handlers_recorder_fun2952__t* _self = kk_function_alloc_as(struct kk_handlers_recorder_fun2952__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_recorder_fun2952, kk_context());
  _self->action = action;
  return &_self->_base;
}



// lift anonymous function
struct kk_handlers_recorder_fun2953__t {
  struct kk_function_s _base;
  kk_function_t action;
};
static kk_box_t kk_handlers_recorder_fun2953(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_recorder_fun2953(kk_function_t action, kk_context_t* _ctx) {
  struct kk_handlers_recorder_fun2953__t* _self = kk_function_alloc_as(struct kk_handlers_recorder_fun2953__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_recorder_fun2953, kk_context());
  _self->action = action;
  return &_self->_base;
}

static kk_box_t kk_handlers_recorder_fun2953(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_handlers_recorder_fun2953__t* _self = kk_function_as(struct kk_handlers_recorder_fun2953__t*, _fself);
  kk_function_t action = _self->action; /* () -> <effects-and-types/sample,effects-and-types/sample|629> (627, 628) */
  kk_drop_match(_self, {kk_function_dup(action);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x2954 = kk_function_call(kk_std_core_types__tuple2_, (kk_function_t, kk_context_t*), action, (action, _ctx)); /*(627, 628)*/
  return kk_std_core_types__tuple2__box(_x2954, _ctx);
}
static kk_box_t kk_handlers_recorder_fun2952(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_handlers_recorder_fun2952__t* _self = kk_function_as(struct kk_handlers_recorder_fun2952__t*, _fself);
  kk_function_t action = _self->action; /* () -> <effects-and-types/sample,effects-and-types/sample|629> (627, 628) */
  kk_drop_match(_self, {kk_function_dup(action);}, {}, _ctx)
  return kk_std_core_hnd__mask_builtin(kk_handlers_new_recorder_fun2953(action, _ctx), _ctx);
}

kk_std_core_types__tuple3_ kk_handlers_recorder(kk_std_core__list model__trace, kk_function_t action, kk_context_t* _ctx) { /* forall<a,b,e> (model_trace : effects-and-types/trace_values, action : () -> <effects-and-types/sample,effects-and-types/sample|e> (a, b)) -> <effects-and-types/sample|e> (effects-and-types/trace_values, a, b) */ 
  kk_ref_t loc = kk_ref_alloc((kk_std_core__list_box(model__trace, _ctx)),kk_context()); /*local-var<global,effects-and-types/trace_values>*/;
  kk_std_core_types__tuple3_ res1;
  int32_t _b_2466_2461 = ((int32_t)1); /*int32*/;
  kk_effects_dash_and_dash_types__hnd_sample _b_2467_2462;
  kk_std_core_hnd__clause0 _x2924;
  kk_function_t _x2925;
  kk_ref_dup(loc);
  _x2925 = kk_handlers_new_recorder_fun2926(loc, _ctx); /*(std/core/hnd/marker<13,14>, std/core/hnd/ev<12>) -> 13 11*/
  _x2924 = kk_std_core_hnd__new_Clause0(_x2925, _ctx); /*std/core/hnd/clause0<11,12,13,14>*/
  _b_2467_2462 = kk_effects_dash_and_dash_types__new_Hnd_sample(kk_reuse_null, _x2924, _ctx); /*effects-and-types/.hnd-sample<<local<global>,effects-and-types/sample|629>,(effects-and-types/trace_values, 627, 628)>*/
  kk_box_t _x2943;
  kk_function_t _x2944;
  kk_ref_dup(loc);
  _x2944 = kk_handlers_new_recorder_fun2945(loc, _ctx); /*(223) -> 224 225*/
  _x2943 = kk_effects_dash_and_dash_types__handle_sample(_b_2466_2461, _b_2467_2462, _x2944, kk_handlers_new_recorder_fun2952(action, _ctx), _ctx); /*225*/
  res1 = kk_std_core_types__tuple3__unbox(_x2943, _ctx); /*(effects-and-types/trace_values, 627, 628)*/
  kk_box_t _x2955 = kk_std_core_hnd_prompt_local_var(loc, kk_std_core_types__tuple3__box(res1, _ctx), _ctx); /*2*/
  return kk_std_core_types__tuple3__unbox(_x2955, _ctx);
}
 
// monadic lift

double kk_handlers__mlift2023_replayx(double rand__choice, kk_unit_t wild__0, kk_context_t* _ctx) { /* forall<h,e> (rand_choice : double, wild_0 : ()) -> <local<h>,effects-and-types/sample|e> double */ 
  return rand__choice;
}
 
// monadic lift


// lift anonymous function
struct kk_handlers__mlift2024_replayx_fun2957__t {
  struct kk_function_s _base;
  double rand__choice;
};
static kk_box_t kk_handlers__mlift2024_replayx_fun2957(kk_function_t _fself, kk_box_t _b_2497, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2024_replayx_fun2957(double rand__choice, kk_context_t* _ctx) {
  struct kk_handlers__mlift2024_replayx_fun2957__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2024_replayx_fun2957__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2024_replayx_fun2957, kk_context());
  _self->rand__choice = rand__choice;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift2024_replayx_fun2957(kk_function_t _fself, kk_box_t _b_2497, kk_context_t* _ctx) {
  struct kk_handlers__mlift2024_replayx_fun2957__t* _self = kk_function_as(struct kk_handlers__mlift2024_replayx_fun2957__t*, _fself);
  double rand__choice = _self->rand__choice; /* double */
  kk_drop_match(_self, {;}, {}, _ctx)
  double _x2958;
  kk_unit_t _x2959 = kk_Unit;
  kk_unit_unbox(_b_2497);
  _x2958 = kk_handlers__mlift2023_replayx(rand__choice, _x2959, _ctx); /*double*/
  return kk_double_box(_x2958, _ctx);
}

double kk_handlers__mlift2024_replayx(kk_ref_t extended__trace, double rand__choice, kk_std_core__list _y_28, kk_context_t* _ctx) { /* forall<h,e> (extended_trace : local-var<h,list<double>>, rand_choice : double, list<double>) -> <local<h>,effects-and-types/sample|e> double */ 
  kk_unit_t x_2076 = kk_Unit;
  kk_std_core__list _b_2495_2493;
  kk_std_core__list ys_2079 = kk_std_core__new_Cons(kk_reuse_null, kk_double_box(rand__choice, _ctx), kk_std_core__new_Nil(_ctx), _ctx); /*list<double>*/;
  _b_2495_2493 = kk_std_core_append(_y_28, ys_2079, _ctx); /*list<double>*/
  (kk_ref_set(extended__trace,(kk_std_core__list_box(_b_2495_2493, _ctx)),kk_context()));
  if (kk_yielding(kk_context())) {
    kk_box_t _x2956 = kk_std_core_hnd_yield_extend(kk_handlers__new_mlift2024_replayx_fun2957(rand__choice, _ctx), _ctx); /*2*/
    return kk_double_unbox(_x2956, _ctx);
  }
  return kk_handlers__mlift2023_replayx(rand__choice, x_2076, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_handlers__mlift2025_replayx_fun2963__t {
  struct kk_function_s _base;
  kk_ref_t extended__trace;
  double rand__choice;
};
static kk_box_t kk_handlers__mlift2025_replayx_fun2963(kk_function_t _fself, kk_box_t _b_2503, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2025_replayx_fun2963(kk_ref_t extended__trace, double rand__choice, kk_context_t* _ctx) {
  struct kk_handlers__mlift2025_replayx_fun2963__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2025_replayx_fun2963__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2025_replayx_fun2963, kk_context());
  _self->extended__trace = extended__trace;
  _self->rand__choice = rand__choice;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift2025_replayx_fun2963(kk_function_t _fself, kk_box_t _b_2503, kk_context_t* _ctx) {
  struct kk_handlers__mlift2025_replayx_fun2963__t* _self = kk_function_as(struct kk_handlers__mlift2025_replayx_fun2963__t*, _fself);
  kk_ref_t extended__trace = _self->extended__trace; /* local-var<1703,list<double>> */
  double rand__choice = _self->rand__choice; /* double */
  kk_drop_match(_self, {kk_ref_dup(extended__trace);;}, {}, _ctx)
  double _x2964;
  kk_std_core__list _x2965 = kk_std_core__list_unbox(_b_2503, _ctx); /*list<double>*/
  _x2964 = kk_handlers__mlift2024_replayx(extended__trace, rand__choice, _x2965, _ctx); /*double*/
  return kk_double_box(_x2964, _ctx);
}

double kk_handlers__mlift2025_replayx(kk_ref_t extended__trace, double rand__choice, kk_context_t* _ctx) { /* forall<h,e> (extended_trace : local-var<h,list<double>>, rand_choice : double) -> <effects-and-types/sample,local<h>|e> double */ 
  kk_std_core__list x_2080;
  kk_box_t _x2960;
  kk_ref_t _x2961 = kk_ref_dup(extended__trace); /*local-var<1703,list<double>>*/
  _x2960 = (kk_ref_get(_x2961,kk_context())); /*0*/
  x_2080 = kk_std_core__list_unbox(_x2960, _ctx); /*list<double>*/
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_2080, _ctx);
    kk_box_t _x2962 = kk_std_core_hnd_yield_extend(kk_handlers__new_mlift2025_replayx_fun2963(extended__trace, rand__choice, _ctx), _ctx); /*2*/
    return kk_double_unbox(_x2962, _ctx);
  }
  return kk_handlers__mlift2024_replayx(extended__trace, rand__choice, x_2080, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_handlers__mlift2026_replayx_fun2973__t {
  struct kk_function_s _base;
  size_t i_2084;
};
static kk_box_t kk_handlers__mlift2026_replayx_fun2973(kk_function_t _fself, kk_function_t _b_2519, kk_box_t _b_2520, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2026_replayx_fun2973(size_t i_2084, kk_context_t* _ctx) {
  struct kk_handlers__mlift2026_replayx_fun2973__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2026_replayx_fun2973__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2026_replayx_fun2973, kk_context());
  _self->i_2084 = i_2084;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift2026_replayx_fun2973(kk_function_t _fself, kk_function_t _b_2519, kk_box_t _b_2520, kk_context_t* _ctx) {
  struct kk_handlers__mlift2026_replayx_fun2973__t* _self = kk_function_as(struct kk_handlers__mlift2026_replayx_fun2973__t*, _fself);
  size_t i_2084 = _self->i_2084; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_2084, _b_2519, _b_2520, _ctx);
}


// lift anonymous function
struct kk_handlers__mlift2026_replayx_fun2975__t {
  struct kk_function_s _base;
  kk_ref_t extended__trace;
};
static kk_box_t kk_handlers__mlift2026_replayx_fun2975(kk_function_t _fself, kk_box_t _b_2530, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2026_replayx_fun2975(kk_ref_t extended__trace, kk_context_t* _ctx) {
  struct kk_handlers__mlift2026_replayx_fun2975__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2026_replayx_fun2975__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2026_replayx_fun2975, kk_context());
  _self->extended__trace = extended__trace;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift2026_replayx_fun2975(kk_function_t _fself, kk_box_t _b_2530, kk_context_t* _ctx) {
  struct kk_handlers__mlift2026_replayx_fun2975__t* _self = kk_function_as(struct kk_handlers__mlift2026_replayx_fun2975__t*, _fself);
  kk_ref_t extended__trace = _self->extended__trace; /* local-var<1703,list<double>> */
  kk_drop_match(_self, {kk_ref_dup(extended__trace);}, {}, _ctx)
  double _x2976;
  double _x2977 = kk_double_unbox(_b_2530, _ctx); /*double*/
  _x2976 = kk_handlers__mlift2025_replayx(extended__trace, _x2977, _ctx); /*double*/
  return kk_double_box(_x2976, _ctx);
}

double kk_handlers__mlift2026_replayx(kk_std_core__list _y_25, kk_ref_t extended__trace, kk_integer_t _y_26, kk_context_t* _ctx) { /* forall<h,e> (list<double>, extended_trace : local-var<h,list<double>>, int) -> <local<h>,effects-and-types/sample|e> double */ 
  kk_std_core_types__maybe _match_2797 = kk_std_core__lp__lb__rb__2_rp_(_y_25, _y_26, _ctx); /*maybe<1>*/;
  if (kk_std_core_types__is_Nothing(_match_2797)) {
    double x_2082;
    size_t i_2084;
    kk_std_core_hnd__htag _x2966 = kk_std_core_hnd__htag_dup(kk_effects_dash_and_dash_types__tag_sample); /*std/core/hnd/htag<effects-and-types/.hnd-sample>*/
    i_2084 = kk_std_core_hnd__evv_index(_x2966, _ctx); /*std/core/hnd/ev-index*/
    kk_evv_t w = kk_evv_swap_create1(i_2084,kk_context()); /*std/core/hnd/evv<<effects-and-types/sample,local<1703>|1711>>*/;
    double y;
    kk_std_core_hnd__ev ev_404;
    size_t _x2967 = ((size_t)0); /*size_t*/
    ev_404 = kk_evv_at(_x2967,kk_context()); /*std/core/hnd/ev<effects-and-types/.hnd-sample>*/
    kk_box_t _x2968;
    struct kk_std_core_hnd_Ev* _con2969 = kk_std_core_hnd__as_Ev(ev_404);
    kk_std_core_hnd__marker m = _con2969->marker;
    kk_box_t _box_x2506 = _con2969->hnd;
    kk_effects_dash_and_dash_types__hnd_sample h = kk_effects_dash_and_dash_types__hnd_sample_unbox(_box_x2506, NULL);
    kk_effects_dash_and_dash_types__hnd_sample_dup(h);
    kk_std_core_hnd__clause0 _match_2800;
    struct kk_effects_dash_and_dash_types__Hnd_sample* _con2971 = kk_effects_dash_and_dash_types__as_Hnd_sample(h);
    kk_std_core_hnd__clause0 fun_sample = _con2971->fun_sample;
    if (kk_effects_dash_and_dash_types__hnd_sample_is_unique(h)) {
      kk_effects_dash_and_dash_types__hnd_sample_free(h);
    }
    else {
      kk_std_core_hnd__clause0_dup(fun_sample);
      kk_effects_dash_and_dash_types__hnd_sample_decref(h, _ctx);
    }
    _match_2800 = fun_sample; /*std/core/hnd/clause0<double,effects-and-types/.hnd-sample,6,7>*/
    kk_function_t _fun_unbox_x2509 = _match_2800.clause;
    _x2968 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x2509, (_fun_unbox_x2509, m, ev_404, _ctx)); /*6*/
    y = kk_double_unbox(_x2968, _ctx); /*double*/
    kk_unit_t __w_l683_c9 = kk_Unit;
    kk_evv_set(w,kk_context());
    if (kk_yielding(kk_context())) {
      kk_box_t _x2972 = kk_std_core_hnd_yield_cont(kk_handlers__new_mlift2026_replayx_fun2973(i_2084, _ctx), _ctx); /*3*/
      x_2082 = kk_double_unbox(_x2972, _ctx); /*double*/
    }
    else {
      x_2082 = y; /*double*/
    }
    if (kk_yielding(kk_context())) {
      kk_box_t _x2974 = kk_std_core_hnd_yield_extend(kk_handlers__new_mlift2026_replayx_fun2975(extended__trace, _ctx), _ctx); /*2*/
      return kk_double_unbox(_x2974, _ctx);
    }
    return kk_handlers__mlift2025_replayx(extended__trace, x_2082, _ctx);
  }
  kk_box_t _box_x2531 = _match_2797._cons.Just.value;
  double random__value = kk_double_unbox(_box_x2531, NULL);
  kk_ref_drop(extended__trace, _ctx);
  kk_std_core_types__maybe_drop(_match_2797, _ctx);
  return random__value;
}
 
// monadic lift


// lift anonymous function
struct kk_handlers__mlift2027_replayx_fun2981__t {
  struct kk_function_s _base;
  kk_std_core__list _y_25;
  kk_ref_t extended__trace;
};
static kk_box_t kk_handlers__mlift2027_replayx_fun2981(kk_function_t _fself, kk_box_t _b_2537, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2027_replayx_fun2981(kk_std_core__list _y_25, kk_ref_t extended__trace, kk_context_t* _ctx) {
  struct kk_handlers__mlift2027_replayx_fun2981__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2027_replayx_fun2981__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2027_replayx_fun2981, kk_context());
  _self->_y_25 = _y_25;
  _self->extended__trace = extended__trace;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift2027_replayx_fun2981(kk_function_t _fself, kk_box_t _b_2537, kk_context_t* _ctx) {
  struct kk_handlers__mlift2027_replayx_fun2981__t* _self = kk_function_as(struct kk_handlers__mlift2027_replayx_fun2981__t*, _fself);
  kk_std_core__list _y_25 = _self->_y_25; /* list<double> */
  kk_ref_t extended__trace = _self->extended__trace; /* local-var<1703,list<double>> */
  kk_drop_match(_self, {kk_std_core__list_dup(_y_25);kk_ref_dup(extended__trace);}, {}, _ctx)
  double _x2982;
  kk_integer_t _x2983 = kk_integer_unbox(_b_2537); /*int*/
  _x2982 = kk_handlers__mlift2026_replayx(_y_25, extended__trace, _x2983, _ctx); /*double*/
  return kk_double_box(_x2982, _ctx);
}

double kk_handlers__mlift2027_replayx(kk_ref_t extended__trace, kk_ref_t index, kk_std_core__list _y_25, kk_context_t* _ctx) { /* forall<h,e> (extended_trace : local-var<h,list<double>>, index : local-var<h,int>, list<double>) -> <local<h>,effects-and-types/sample|e> double */ 
  kk_integer_t x_2086;
  kk_box_t _x2979 = (kk_ref_get(index,kk_context())); /*0*/
  x_2086 = kk_integer_unbox(_x2979); /*int*/
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_2086, _ctx);
    kk_box_t _x2980 = kk_std_core_hnd_yield_extend(kk_handlers__new_mlift2027_replayx_fun2981(_y_25, extended__trace, _ctx), _ctx); /*2*/
    return kk_double_unbox(_x2980, _ctx);
  }
  return kk_handlers__mlift2026_replayx(_y_25, extended__trace, x_2086, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_handlers__mlift2028_replayx_fun2987__t {
  struct kk_function_s _base;
  kk_ref_t extended__trace;
  kk_ref_t index;
};
static kk_box_t kk_handlers__mlift2028_replayx_fun2987(kk_function_t _fself, kk_box_t _b_2543, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2028_replayx_fun2987(kk_ref_t extended__trace, kk_ref_t index, kk_context_t* _ctx) {
  struct kk_handlers__mlift2028_replayx_fun2987__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2028_replayx_fun2987__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2028_replayx_fun2987, kk_context());
  _self->extended__trace = extended__trace;
  _self->index = index;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift2028_replayx_fun2987(kk_function_t _fself, kk_box_t _b_2543, kk_context_t* _ctx) {
  struct kk_handlers__mlift2028_replayx_fun2987__t* _self = kk_function_as(struct kk_handlers__mlift2028_replayx_fun2987__t*, _fself);
  kk_ref_t extended__trace = _self->extended__trace; /* local-var<1703,list<double>> */
  kk_ref_t index = _self->index; /* local-var<1703,int> */
  kk_drop_match(_self, {kk_ref_dup(extended__trace);kk_ref_dup(index);}, {}, _ctx)
  double _x2988;
  kk_std_core__list _x2989 = kk_std_core__list_unbox(_b_2543, _ctx); /*list<double>*/
  _x2988 = kk_handlers__mlift2027_replayx(extended__trace, index, _x2989, _ctx); /*double*/
  return kk_double_box(_x2988, _ctx);
}

double kk_handlers__mlift2028_replayx(kk_ref_t extended__trace, kk_ref_t index, kk_unit_t wild__, kk_context_t* _ctx) { /* forall<h,e> (extended_trace : local-var<h,list<double>>, index : local-var<h,int>, wild_ : ()) -> <local<h>,effects-and-types/sample|e> double */ 
  kk_std_core__list x_2088;
  kk_box_t _x2984;
  kk_ref_t _x2985 = kk_ref_dup(extended__trace); /*local-var<1703,list<double>>*/
  _x2984 = (kk_ref_get(_x2985,kk_context())); /*0*/
  x_2088 = kk_std_core__list_unbox(_x2984, _ctx); /*list<double>*/
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_2088, _ctx);
    kk_box_t _x2986 = kk_std_core_hnd_yield_extend(kk_handlers__new_mlift2028_replayx_fun2987(extended__trace, index, _ctx), _ctx); /*2*/
    return kk_double_unbox(_x2986, _ctx);
  }
  return kk_handlers__mlift2027_replayx(extended__trace, index, x_2088, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_handlers__mlift2029_replayx_fun2992__t {
  struct kk_function_s _base;
  kk_ref_t extended__trace;
  kk_ref_t index;
};
static kk_box_t kk_handlers__mlift2029_replayx_fun2992(kk_function_t _fself, kk_box_t _b_2551, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2029_replayx_fun2992(kk_ref_t extended__trace, kk_ref_t index, kk_context_t* _ctx) {
  struct kk_handlers__mlift2029_replayx_fun2992__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2029_replayx_fun2992__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2029_replayx_fun2992, kk_context());
  _self->extended__trace = extended__trace;
  _self->index = index;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift2029_replayx_fun2992(kk_function_t _fself, kk_box_t _b_2551, kk_context_t* _ctx) {
  struct kk_handlers__mlift2029_replayx_fun2992__t* _self = kk_function_as(struct kk_handlers__mlift2029_replayx_fun2992__t*, _fself);
  kk_ref_t extended__trace = _self->extended__trace; /* local-var<1703,list<double>> */
  kk_ref_t index = _self->index; /* local-var<1703,int> */
  kk_drop_match(_self, {kk_ref_dup(extended__trace);kk_ref_dup(index);}, {}, _ctx)
  double _x2993;
  kk_unit_t _x2994 = kk_Unit;
  kk_unit_unbox(_b_2551);
  _x2993 = kk_handlers__mlift2028_replayx(extended__trace, index, _x2994, _ctx); /*double*/
  return kk_double_box(_x2993, _ctx);
}

double kk_handlers__mlift2029_replayx(kk_ref_t extended__trace, kk_ref_t index, kk_integer_t _y_23, kk_context_t* _ctx) { /* forall<h,e> (extended_trace : local-var<h,list<double>>, index : local-var<h,int>, int) -> <local<h>,effects-and-types/sample|e> double */ 
  kk_unit_t x_2090 = kk_Unit;
  kk_integer_t _b_2549_2547 = kk_integer_add(_y_23,(kk_integer_from_small(1)),kk_context()); /*int*/;
  kk_ref_t _x2990 = kk_ref_dup(index); /*local-var<1703,int>*/
  (kk_ref_set(_x2990,(kk_integer_box(_b_2549_2547)),kk_context()));
  if (kk_yielding(kk_context())) {
    kk_box_t _x2991 = kk_std_core_hnd_yield_extend(kk_handlers__new_mlift2029_replayx_fun2992(extended__trace, index, _ctx), _ctx); /*2*/
    return kk_double_unbox(_x2991, _ctx);
  }
  return kk_handlers__mlift2028_replayx(extended__trace, index, x_2090, _ctx);
}
 
// monadic lift

kk_std_core_types__tuple2_ kk_handlers__mlift2030_replayx(kk_std_core__list _y_31, kk_box_t x, kk_integer_t _y_32, kk_context_t* _ctx) { /* forall<h,a,e> (list<double>, x : a, int) -> <local<h>,effects-and-types/sample|e> (list<double>, a) */ 
  kk_std_core__list _b_2562_2560;
  kk_std_core_types__tuple2_ _this_2092;
  kk_integer_t n_2094 = kk_integer_add(_y_32,(kk_integer_from_small(1)),kk_context()); /*int*/;
  kk_std_core__list _b_2556_2554;
  kk_std_core__list _x2995 = kk_std_core__list_dup(_y_31); /*list<double>*/
  kk_integer_t _x2996 = kk_integer_dup(n_2094); /*int*/
  _b_2556_2554 = kk_std_core_take(_x2995, _x2996, _ctx); /*list<double>*/
  kk_std_core__list _b_2557_2555 = kk_std_core_drop(_y_31, n_2094, _ctx); /*list<double>*/;
  _this_2092 = kk_std_core_types__new_dash__lp__comma__rp_(kk_std_core__list_box(_b_2556_2554, _ctx), kk_std_core__list_box(_b_2557_2555, _ctx), _ctx); /*(list<double>, list<double>)*/
  kk_box_t _box_x2558 = _this_2092.fst;
  kk_box_t _box_x2559 = _this_2092.snd;
  kk_std_core__list _x = kk_std_core__list_unbox(_box_x2558, NULL);
  kk_std_core__list_dup(_x);
  kk_std_core_types__tuple2__drop(_this_2092, _ctx);
  _b_2562_2560 = _x; /*list<double>*/
  return kk_std_core_types__new_dash__lp__comma__rp_(kk_std_core__list_box(_b_2562_2560, _ctx), x, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_handlers__mlift2031_replayx_fun3001__t {
  struct kk_function_s _base;
  kk_std_core__list _y_31;
  kk_box_t x;
};
static kk_box_t kk_handlers__mlift2031_replayx_fun3001(kk_function_t _fself, kk_box_t _b_2567, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2031_replayx_fun3001(kk_std_core__list _y_31, kk_box_t x, kk_context_t* _ctx) {
  struct kk_handlers__mlift2031_replayx_fun3001__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2031_replayx_fun3001__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2031_replayx_fun3001, kk_context());
  _self->_y_31 = _y_31;
  _self->x = x;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift2031_replayx_fun3001(kk_function_t _fself, kk_box_t _b_2567, kk_context_t* _ctx) {
  struct kk_handlers__mlift2031_replayx_fun3001__t* _self = kk_function_as(struct kk_handlers__mlift2031_replayx_fun3001__t*, _fself);
  kk_std_core__list _y_31 = _self->_y_31; /* list<double> */
  kk_box_t x = _self->x; /* 1710 */
  kk_drop_match(_self, {kk_std_core__list_dup(_y_31);kk_box_dup(x);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x3002;
  kk_integer_t _x3003 = kk_integer_unbox(_b_2567); /*int*/
  _x3002 = kk_handlers__mlift2030_replayx(_y_31, x, _x3003, _ctx); /*(list<double>, 1710)*/
  return kk_std_core_types__tuple2__box(_x3002, _ctx);
}

kk_std_core_types__tuple2_ kk_handlers__mlift2031_replayx(kk_ref_t index, kk_box_t x, kk_std_core__list _y_31, kk_context_t* _ctx) { /* forall<h,a,e> (index : local-var<h,int>, x : a, list<double>) -> <local<h>,effects-and-types/sample|e> (list<double>, a) */ 
  kk_integer_t x0_2095;
  kk_box_t _x2999 = (kk_ref_get(index,kk_context())); /*0*/
  x0_2095 = kk_integer_unbox(_x2999); /*int*/
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x0_2095, _ctx);
    kk_box_t _x3000 = kk_std_core_hnd_yield_extend(kk_handlers__new_mlift2031_replayx_fun3001(_y_31, x, _ctx), _ctx); /*2*/
    return kk_std_core_types__tuple2__unbox(_x3000, _ctx);
  }
  return kk_handlers__mlift2030_replayx(_y_31, x, x0_2095, _ctx);
}


// lift anonymous function
struct kk_handlers_replayx_fun3006__t {
  struct kk_function_s _base;
  kk_ref_t loc;
  kk_ref_t loc0;
};
static kk_box_t kk_handlers_replayx_fun3006(kk_function_t _fself, kk_std_core_hnd__marker _b_2589, kk_std_core_hnd__ev _b_2590, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_replayx_fun3006(kk_ref_t loc, kk_ref_t loc0, kk_context_t* _ctx) {
  struct kk_handlers_replayx_fun3006__t* _self = kk_function_alloc_as(struct kk_handlers_replayx_fun3006__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_replayx_fun3006, kk_context());
  _self->loc = loc;
  _self->loc0 = loc0;
  return &_self->_base;
}



// lift anonymous function
struct kk_handlers_replayx_fun3012__t {
  struct kk_function_s _base;
  kk_ref_t loc;
  kk_ref_t loc0;
};
static kk_box_t kk_handlers_replayx_fun3012(kk_function_t _fself, kk_box_t _b_2577, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_replayx_fun3012(kk_ref_t loc, kk_ref_t loc0, kk_context_t* _ctx) {
  struct kk_handlers_replayx_fun3012__t* _self = kk_function_alloc_as(struct kk_handlers_replayx_fun3012__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_replayx_fun3012, kk_context());
  _self->loc = loc;
  _self->loc0 = loc0;
  return &_self->_base;
}

static kk_box_t kk_handlers_replayx_fun3012(kk_function_t _fself, kk_box_t _b_2577, kk_context_t* _ctx) {
  struct kk_handlers_replayx_fun3012__t* _self = kk_function_as(struct kk_handlers_replayx_fun3012__t*, _fself);
  kk_ref_t loc = _self->loc; /* local-var<global,list<double>> */
  kk_ref_t loc0 = _self->loc0; /* local-var<global,int> */
  kk_drop_match(_self, {kk_ref_dup(loc);kk_ref_dup(loc0);}, {}, _ctx)
  double _x3013;
  kk_integer_t _x3014 = kk_integer_unbox(_b_2577); /*int*/
  _x3013 = kk_handlers__mlift2029_replayx(loc, loc0, _x3014, _ctx); /*double*/
  return kk_double_box(_x3013, _ctx);
}


// lift anonymous function
struct kk_handlers_replayx_fun3016__t {
  struct kk_function_s _base;
  kk_std_core_hnd__ev _b_2590;
};
static kk_box_t kk_handlers_replayx_fun3016(kk_function_t _fself, kk_function_t _b_2585, kk_box_t _b_2586, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_replayx_fun3016(kk_std_core_hnd__ev _b_2590, kk_context_t* _ctx) {
  struct kk_handlers_replayx_fun3016__t* _self = kk_function_alloc_as(struct kk_handlers_replayx_fun3016__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_replayx_fun3016, kk_context());
  _self->_b_2590 = _b_2590;
  return &_self->_base;
}

static kk_box_t kk_handlers_replayx_fun3016(kk_function_t _fself, kk_function_t _b_2585, kk_box_t _b_2586, kk_context_t* _ctx) {
  struct kk_handlers_replayx_fun3016__t* _self = kk_function_as(struct kk_handlers_replayx_fun3016__t*, _fself);
  kk_std_core_hnd__ev _b_2590 = _self->_b_2590; /* std/core/hnd/ev<12> */
  kk_drop_match(_self, {kk_std_core_hnd__ev_dup(_b_2590);}, {}, _ctx)
  return kk_std_core_hnd_under1(_b_2590, _b_2585, _b_2586, _ctx);
}
static kk_box_t kk_handlers_replayx_fun3006(kk_function_t _fself, kk_std_core_hnd__marker _b_2589, kk_std_core_hnd__ev _b_2590, kk_context_t* _ctx) {
  struct kk_handlers_replayx_fun3006__t* _self = kk_function_as(struct kk_handlers_replayx_fun3006__t*, _fself);
  kk_ref_t loc = _self->loc; /* local-var<global,list<double>> */
  kk_ref_t loc0 = _self->loc0; /* local-var<global,int> */
  kk_drop_match(_self, {kk_ref_dup(loc);kk_ref_dup(loc0);}, {}, _ctx)
  double _x3007;
  kk_evv_t w0;
  kk_std_core_hnd__ev _x3008 = kk_std_core_hnd__ev_dup(_b_2590); /*std/core/hnd/ev<12>*/
  w0 = kk_std_core_hnd_evv_swap_with(_x3008, _ctx); /*std/core/hnd/evv<std/core/hnd/_e1>*/
  double y;
  kk_integer_t x_2105;
  kk_box_t _x3009;
  kk_ref_t _x3010 = kk_ref_dup(loc0); /*local-var<global,int>*/
  _x3009 = (kk_ref_get(_x3010,kk_context())); /*0*/
  x_2105 = kk_integer_unbox(_x3009); /*int*/
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_2105, _ctx);
    kk_box_t _x3011 = kk_std_core_hnd_yield_extend(kk_handlers_new_replayx_fun3012(loc, loc0, _ctx), _ctx); /*2*/
    y = kk_double_unbox(_x3011, _ctx); /*double*/
  }
  else {
    y = kk_handlers__mlift2029_replayx(loc, loc0, x_2105, _ctx); /*double*/
  }
  kk_unit_t __w_l1003_c9 = kk_Unit;
  kk_evv_set(w0,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x3015 = kk_std_core_hnd_yield_cont(kk_handlers_new_replayx_fun3016(_b_2590, _ctx), _ctx); /*3*/
    _x3007 = kk_double_unbox(_x3015, _ctx); /*double*/
  }
  else {
    kk_std_core_hnd__ev_dropn(_b_2590, ((int32_t)3), _ctx);
    _x3007 = y; /*double*/
  }
  return kk_double_box(_x3007, _ctx);
}


// lift anonymous function
struct kk_handlers_replayx_fun3019__t {
  struct kk_function_s _base;
  kk_ref_t loc;
  kk_ref_t loc0;
};
static kk_box_t kk_handlers_replayx_fun3019(kk_function_t _fself, kk_box_t _b_2599, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_replayx_fun3019(kk_ref_t loc, kk_ref_t loc0, kk_context_t* _ctx) {
  struct kk_handlers_replayx_fun3019__t* _self = kk_function_alloc_as(struct kk_handlers_replayx_fun3019__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_replayx_fun3019, kk_context());
  _self->loc = loc;
  _self->loc0 = loc0;
  return &_self->_base;
}



// lift anonymous function
struct kk_handlers_replayx_fun3023__t {
  struct kk_function_s _base;
  kk_box_t _b_2599;
  kk_ref_t loc0;
};
static kk_box_t kk_handlers_replayx_fun3023(kk_function_t _fself, kk_box_t _b_2594, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_replayx_fun3023(kk_box_t _b_2599, kk_ref_t loc0, kk_context_t* _ctx) {
  struct kk_handlers_replayx_fun3023__t* _self = kk_function_alloc_as(struct kk_handlers_replayx_fun3023__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_replayx_fun3023, kk_context());
  _self->_b_2599 = _b_2599;
  _self->loc0 = loc0;
  return &_self->_base;
}

static kk_box_t kk_handlers_replayx_fun3023(kk_function_t _fself, kk_box_t _b_2594, kk_context_t* _ctx) {
  struct kk_handlers_replayx_fun3023__t* _self = kk_function_as(struct kk_handlers_replayx_fun3023__t*, _fself);
  kk_box_t _b_2599 = _self->_b_2599; /* 223 */
  kk_ref_t loc0 = _self->loc0; /* local-var<global,int> */
  kk_drop_match(_self, {kk_box_dup(_b_2599);kk_ref_dup(loc0);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x3024;
  kk_std_core__list _x3025 = kk_std_core__list_unbox(_b_2594, _ctx); /*list<double>*/
  _x3024 = kk_handlers__mlift2031_replayx(loc0, _b_2599, _x3025, _ctx); /*(list<double>, 1710)*/
  return kk_std_core_types__tuple2__box(_x3024, _ctx);
}
static kk_box_t kk_handlers_replayx_fun3019(kk_function_t _fself, kk_box_t _b_2599, kk_context_t* _ctx) {
  struct kk_handlers_replayx_fun3019__t* _self = kk_function_as(struct kk_handlers_replayx_fun3019__t*, _fself);
  kk_ref_t loc = _self->loc; /* local-var<global,list<double>> */
  kk_ref_t loc0 = _self->loc0; /* local-var<global,int> */
  kk_drop_match(_self, {kk_ref_dup(loc);kk_ref_dup(loc0);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x3020;
  kk_std_core__list x1_2107;
  kk_box_t _x3021 = (kk_ref_get(loc,kk_context())); /*0*/
  x1_2107 = kk_std_core__list_unbox(_x3021, _ctx); /*list<double>*/
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x1_2107, _ctx);
    kk_box_t _x3022 = kk_std_core_hnd_yield_extend(kk_handlers_new_replayx_fun3023(_b_2599, loc0, _ctx), _ctx); /*2*/
    _x3020 = kk_std_core_types__tuple2__unbox(_x3022, _ctx); /*(list<double>, 1710)*/
  }
  else {
    _x3020 = kk_handlers__mlift2031_replayx(loc0, _b_2599, x1_2107, _ctx); /*(list<double>, 1710)*/
  }
  return kk_std_core_types__tuple2__box(_x3020, _ctx);
}


// lift anonymous function
struct kk_handlers_replayx_fun3026__t {
  struct kk_function_s _base;
  kk_function_t action;
};
static kk_box_t kk_handlers_replayx_fun3026(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_replayx_fun3026(kk_function_t action, kk_context_t* _ctx) {
  struct kk_handlers_replayx_fun3026__t* _self = kk_function_alloc_as(struct kk_handlers_replayx_fun3026__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_replayx_fun3026, kk_context());
  _self->action = action;
  return &_self->_base;
}

static kk_box_t kk_handlers_replayx_fun3026(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_handlers_replayx_fun3026__t* _self = kk_function_as(struct kk_handlers_replayx_fun3026__t*, _fself);
  kk_function_t action = _self->action; /* () -> <effects-and-types/sample,effects-and-types/sample|1711> 1710 */
  kk_drop_match(_self, {kk_function_dup(action);}, {}, _ctx)
  return kk_std_core_hnd__mask_builtin(action, _ctx);
}

kk_std_core_types__tuple2_ kk_handlers_replayx(kk_std_core__list trace, kk_function_t action, kk_context_t* _ctx) { /* forall<a,e> (trace : effects-and-types/trace_values, action : () -> <effects-and-types/sample,effects-and-types/sample|e> a) -> <effects-and-types/sample|e> (list<double>, a) */ 
  kk_ref_t loc = kk_ref_alloc((kk_std_core__list_box(trace, _ctx)),kk_context()); /*local-var<global,list<double>>*/;
  kk_std_core_types__tuple2_ res1;
  kk_ref_t loc0 = kk_ref_alloc((kk_integer_box(kk_integer_from_small(-1))),kk_context()); /*local-var<global,int>*/;
  kk_std_core_types__tuple2_ res0;
  int32_t _b_2600_2595 = ((int32_t)1); /*int32*/;
  kk_effects_dash_and_dash_types__hnd_sample _b_2601_2596;
  kk_std_core_hnd__clause0 _x3004;
  kk_function_t _x3005;
  kk_ref_dup(loc);
  kk_ref_dup(loc0);
  _x3005 = kk_handlers_new_replayx_fun3006(loc, loc0, _ctx); /*(std/core/hnd/marker<13,14>, std/core/hnd/ev<12>) -> 13 11*/
  _x3004 = kk_std_core_hnd__new_Clause0(_x3005, _ctx); /*std/core/hnd/clause0<11,12,13,14>*/
  _b_2601_2596 = kk_effects_dash_and_dash_types__new_Hnd_sample(kk_reuse_null, _x3004, _ctx); /*effects-and-types/.hnd-sample<<local<global>,effects-and-types/sample|1711>,(list<double>, 1710)>*/
  kk_box_t _x3017;
  kk_function_t _x3018;
  kk_ref_dup(loc);
  kk_ref_dup(loc0);
  _x3018 = kk_handlers_new_replayx_fun3019(loc, loc0, _ctx); /*(223) -> 224 225*/
  _x3017 = kk_effects_dash_and_dash_types__handle_sample(_b_2600_2595, _b_2601_2596, _x3018, kk_handlers_new_replayx_fun3026(action, _ctx), _ctx); /*225*/
  res0 = kk_std_core_types__tuple2__unbox(_x3017, _ctx); /*(list<double>, 1710)*/
  kk_box_t _x3027 = kk_std_core_hnd_prompt_local_var(loc0, kk_std_core_types__tuple2__box(res0, _ctx), _ctx); /*2*/
  res1 = kk_std_core_types__tuple2__unbox(_x3027, _ctx); /*(list<double>, 1710)*/
  kk_box_t _x3028 = kk_std_core_hnd_prompt_local_var(loc, kk_std_core_types__tuple2__box(res1, _ctx), _ctx); /*2*/
  return kk_std_core_types__tuple2__unbox(_x3028, _ctx);
}
 
// monadic lift

kk_unit_t kk_handlers__mlift2032_weighted(kk_effects_dash_and_dash_types__exp s, kk_ref_t wps, kk_effects_dash_and_dash_types__exp _y_38, kk_context_t* _ctx) { /* forall<h,e> (s : effects-and-types/exp, wps : local-var<h,effects-and-types/exp>, effects-and-types/exp) -> <local<h>|e> () */ 
  kk_effects_dash_and_dash_types__exp _b_2628_2626 = kk_exponents_mult__exp(_y_38, s, _ctx); /*effects-and-types/exp*/;
  (kk_ref_set(wps,(kk_effects_dash_and_dash_types__exp_box(_b_2628_2626, _ctx)),kk_context())); return kk_Unit;
}
 
// monadic lift

kk_std_core_types__tuple2_ kk_handlers__mlift2033_weighted(kk_box_t x, kk_effects_dash_and_dash_types__exp _y_40, kk_context_t* _ctx) { /* forall<h,a,e> (x : a, effects-and-types/exp) -> <local<h>|e> (effects-and-types/exp, a) */ 
  return kk_std_core_types__new_dash__lp__comma__rp_(kk_effects_dash_and_dash_types__exp_box(_y_40, _ctx), x, _ctx);
}


// lift anonymous function
struct kk_handlers_weighted_fun3031__t {
  struct kk_function_s _base;
  kk_ref_t loc;
};
static kk_box_t kk_handlers_weighted_fun3031(kk_function_t _fself, kk_std_core_hnd__marker _b_2640, kk_std_core_hnd__ev _b_2641, kk_box_t _b_2642, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_weighted_fun3031(kk_ref_t loc, kk_context_t* _ctx) {
  struct kk_handlers_weighted_fun3031__t* _self = kk_function_alloc_as(struct kk_handlers_weighted_fun3031__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_weighted_fun3031, kk_context());
  _self->loc = loc;
  return &_self->_base;
}



// lift anonymous function
struct kk_handlers_weighted_fun3036__t {
  struct kk_function_s _base;
  kk_box_t _b_2642;
  kk_ref_t loc;
};
static kk_box_t kk_handlers_weighted_fun3036(kk_function_t _fself, kk_box_t _b_2638, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_weighted_fun3036(kk_box_t _b_2642, kk_ref_t loc, kk_context_t* _ctx) {
  struct kk_handlers_weighted_fun3036__t* _self = kk_function_alloc_as(struct kk_handlers_weighted_fun3036__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_weighted_fun3036, kk_context());
  _self->_b_2642 = _b_2642;
  _self->loc = loc;
  return &_self->_base;
}

static kk_box_t kk_handlers_weighted_fun3036(kk_function_t _fself, kk_box_t _b_2638, kk_context_t* _ctx) {
  struct kk_handlers_weighted_fun3036__t* _self = kk_function_as(struct kk_handlers_weighted_fun3036__t*, _fself);
  kk_box_t _b_2642 = _self->_b_2642; /* 16 */
  kk_ref_t loc = _self->loc; /* local-var<global,effects-and-types/exp> */
  kk_drop_match(_self, {kk_box_dup(_b_2642);kk_ref_dup(loc);}, {}, _ctx)
  kk_unit_t _x3037 = kk_Unit;
  kk_effects_dash_and_dash_types__exp _x3038 = kk_effects_dash_and_dash_types__exp_unbox(_b_2642, _ctx); /*effects-and-types/exp*/
  kk_effects_dash_and_dash_types__exp _x3039 = kk_effects_dash_and_dash_types__exp_unbox(_b_2638, _ctx); /*effects-and-types/exp*/
  kk_handlers__mlift2032_weighted(_x3038, loc, _x3039, _ctx);
  return kk_unit_box(_x3037);
}
static kk_box_t kk_handlers_weighted_fun3031(kk_function_t _fself, kk_std_core_hnd__marker _b_2640, kk_std_core_hnd__ev _b_2641, kk_box_t _b_2642, kk_context_t* _ctx) {
  struct kk_handlers_weighted_fun3031__t* _self = kk_function_as(struct kk_handlers_weighted_fun3031__t*, _fself);
  kk_ref_t loc = _self->loc; /* local-var<global,effects-and-types/exp> */
  kk_drop_match(_self, {kk_ref_dup(loc);}, {}, _ctx)
  kk_std_core_hnd__ev_dropn(_b_2641, ((int32_t)3), _ctx);
  kk_unit_t _x3032 = kk_Unit;
  kk_effects_dash_and_dash_types__exp x0_2115;
  kk_box_t _x3033;
  kk_ref_t _x3034 = kk_ref_dup(loc); /*local-var<global,effects-and-types/exp>*/
  _x3033 = (kk_ref_get(_x3034,kk_context())); /*0*/
  x0_2115 = kk_effects_dash_and_dash_types__exp_unbox(_x3033, _ctx); /*effects-and-types/exp*/
  if (kk_yielding(kk_context())) {
    kk_box_t _x3035 = kk_std_core_hnd_yield_extend(kk_handlers_new_weighted_fun3036(_b_2642, loc, _ctx), _ctx); /*2*/
    kk_unit_unbox(_x3035);
  }
  else {
    kk_effects_dash_and_dash_types__exp _x3040 = kk_effects_dash_and_dash_types__exp_unbox(_b_2642, _ctx); /*effects-and-types/exp*/
    kk_handlers__mlift2032_weighted(_x3040, loc, x0_2115, _ctx);
  }
  return kk_unit_box(_x3032);
}


// lift anonymous function
struct kk_handlers_weighted_fun3043__t {
  struct kk_function_s _base;
  kk_ref_t loc;
};
static kk_box_t kk_handlers_weighted_fun3043(kk_function_t _fself, kk_box_t _b_2651, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_weighted_fun3043(kk_ref_t loc, kk_context_t* _ctx) {
  struct kk_handlers_weighted_fun3043__t* _self = kk_function_alloc_as(struct kk_handlers_weighted_fun3043__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_weighted_fun3043, kk_context());
  _self->loc = loc;
  return &_self->_base;
}



// lift anonymous function
struct kk_handlers_weighted_fun3047__t {
  struct kk_function_s _base;
  kk_box_t _b_2651;
};
static kk_box_t kk_handlers_weighted_fun3047(kk_function_t _fself, kk_box_t _b_2646, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_weighted_fun3047(kk_box_t _b_2651, kk_context_t* _ctx) {
  struct kk_handlers_weighted_fun3047__t* _self = kk_function_alloc_as(struct kk_handlers_weighted_fun3047__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_weighted_fun3047, kk_context());
  _self->_b_2651 = _b_2651;
  return &_self->_base;
}

static kk_box_t kk_handlers_weighted_fun3047(kk_function_t _fself, kk_box_t _b_2646, kk_context_t* _ctx) {
  struct kk_handlers_weighted_fun3047__t* _self = kk_function_as(struct kk_handlers_weighted_fun3047__t*, _fself);
  kk_box_t _b_2651 = _self->_b_2651; /* 252 */
  kk_drop_match(_self, {kk_box_dup(_b_2651);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x3048;
  kk_effects_dash_and_dash_types__exp _x3049 = kk_effects_dash_and_dash_types__exp_unbox(_b_2646, _ctx); /*effects-and-types/exp*/
  _x3048 = kk_handlers__mlift2033_weighted(_b_2651, _x3049, _ctx); /*(effects-and-types/exp, 1897)*/
  return kk_std_core_types__tuple2__box(_x3048, _ctx);
}
static kk_box_t kk_handlers_weighted_fun3043(kk_function_t _fself, kk_box_t _b_2651, kk_context_t* _ctx) {
  struct kk_handlers_weighted_fun3043__t* _self = kk_function_as(struct kk_handlers_weighted_fun3043__t*, _fself);
  kk_ref_t loc = _self->loc; /* local-var<global,effects-and-types/exp> */
  kk_drop_match(_self, {kk_ref_dup(loc);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x3044;
  kk_effects_dash_and_dash_types__exp x2_2117;
  kk_box_t _x3045 = (kk_ref_get(loc,kk_context())); /*0*/
  x2_2117 = kk_effects_dash_and_dash_types__exp_unbox(_x3045, _ctx); /*effects-and-types/exp*/
  if (kk_yielding(kk_context())) {
    kk_box_t _x3046 = kk_std_core_hnd_yield_extend(kk_handlers_new_weighted_fun3047(_b_2651, _ctx), _ctx); /*2*/
    _x3044 = kk_std_core_types__tuple2__unbox(_x3046, _ctx); /*(effects-and-types/exp, 1897)*/
  }
  else {
    _x3044 = kk_handlers__mlift2033_weighted(_b_2651, x2_2117, _ctx); /*(effects-and-types/exp, 1897)*/
  }
  return kk_std_core_types__tuple2__box(_x3044, _ctx);
}


// lift anonymous function
struct kk_handlers_weighted_fun3050__t {
  struct kk_function_s _base;
  kk_function_t action;
};
static kk_box_t kk_handlers_weighted_fun3050(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_weighted_fun3050(kk_function_t action, kk_context_t* _ctx) {
  struct kk_handlers_weighted_fun3050__t* _self = kk_function_alloc_as(struct kk_handlers_weighted_fun3050__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_weighted_fun3050, kk_context());
  _self->action = action;
  return &_self->_base;
}

static kk_box_t kk_handlers_weighted_fun3050(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_handlers_weighted_fun3050__t* _self = kk_function_as(struct kk_handlers_weighted_fun3050__t*, _fself);
  kk_function_t action = _self->action; /* () -> <effects-and-types/score|1898> 1897 */
  kk_drop_match(_self, {kk_function_dup(action);}, {}, _ctx)
  return kk_std_core_hnd__mask_builtin(action, _ctx);
}

kk_std_core_types__tuple2_ kk_handlers_weighted(kk_effects_dash_and_dash_types__exp wp, kk_function_t action, kk_context_t* _ctx) { /* forall<a,e> (wp : effects-and-types/exp, action : () -> <effects-and-types/score|e> a) -> e (effects-and-types/exp, a) */ 
  kk_ref_t loc = kk_ref_alloc((kk_effects_dash_and_dash_types__exp_box(wp, _ctx)),kk_context()); /*local-var<global,effects-and-types/exp>*/;
  kk_std_core_types__tuple2_ res;
  int32_t _b_2652_2647 = ((int32_t)1); /*int32*/;
  kk_effects_dash_and_dash_types__hnd_score _b_2653_2648;
  kk_std_core_hnd__clause1 _x3029;
  kk_function_t _x3030;
  kk_ref_dup(loc);
  _x3030 = kk_handlers_new_weighted_fun3031(loc, _ctx); /*(std/core/hnd/marker<19,20>, std/core/hnd/ev<18>, 16) -> 19 17*/
  _x3029 = kk_std_core_hnd__new_Clause1(_x3030, _ctx); /*std/core/hnd/clause1<16,17,18,19,20>*/
  _b_2653_2648 = kk_effects_dash_and_dash_types__new_Hnd_score(kk_reuse_null, _x3029, _ctx); /*effects-and-types/.hnd-score<<local<global>|1898>,(effects-and-types/exp, 1897)>*/
  kk_box_t _x3041;
  kk_function_t _x3042;
  kk_ref_dup(loc);
  _x3042 = kk_handlers_new_weighted_fun3043(loc, _ctx); /*(252) -> 253 254*/
  _x3041 = kk_effects_dash_and_dash_types__handle_score(_b_2652_2647, _b_2653_2648, _x3042, kk_handlers_new_weighted_fun3050(action, _ctx), _ctx); /*254*/
  res = kk_std_core_types__tuple2__unbox(_x3041, _ctx); /*(effects-and-types/exp, 1897)*/
  kk_box_t _x3051 = kk_std_core_hnd_prompt_local_var(loc, kk_std_core_types__tuple2__box(res, _ctx), _ctx); /*2*/
  return kk_std_core_types__tuple2__unbox(_x3051, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_handlers__mlift2034_yield__on__scorex_fun3059__t {
  struct kk_function_s _base;
  size_t i_2119;
};
static kk_box_t kk_handlers__mlift2034_yield__on__scorex_fun3059(kk_function_t _fself, kk_function_t _b_2682, kk_box_t _b_2683, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2034_yield__on__scorex_fun3059(size_t i_2119, kk_context_t* _ctx) {
  struct kk_handlers__mlift2034_yield__on__scorex_fun3059__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2034_yield__on__scorex_fun3059__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2034_yield__on__scorex_fun3059, kk_context());
  _self->i_2119 = i_2119;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift2034_yield__on__scorex_fun3059(kk_function_t _fself, kk_function_t _b_2682, kk_box_t _b_2683, kk_context_t* _ctx) {
  struct kk_handlers__mlift2034_yield__on__scorex_fun3059__t* _self = kk_function_as(struct kk_handlers__mlift2034_yield__on__scorex_fun3059__t*, _fself);
  size_t i_2119 = _self->i_2119; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_2119, _b_2682, _b_2683, _ctx);
}

kk_unit_t kk_handlers__mlift2034_yield__on__scorex(kk_unit_t wild__, kk_context_t* _ctx) { /* forall<e> (wild_ : ()) -> <effects-and-types/score,effects-and-types/yield|e> () */ 
  size_t i_2119;
  kk_std_core_hnd__htag _x3052 = kk_std_core_hnd__htag_dup(kk_effects_dash_and_dash_types__tag_yield); /*std/core/hnd/htag<effects-and-types/.hnd-yield>*/
  i_2119 = kk_std_core_hnd__evv_index(_x3052, _ctx); /*std/core/hnd/ev-index*/
  kk_evv_t w = kk_evv_swap_create1(i_2119,kk_context()); /*std/core/hnd/evv<<effects-and-types/yield,effects-and-types/score|1963>>*/;
  kk_unit_t y = kk_Unit;
  kk_std_core_hnd__ev ev_409;
  size_t _x3053 = ((size_t)0); /*size_t*/
  ev_409 = kk_evv_at(_x3053,kk_context()); /*std/core/hnd/ev<effects-and-types/.hnd-yield>*/
  kk_box_t _x3054;
  struct kk_std_core_hnd_Ev* _con3055 = kk_std_core_hnd__as_Ev(ev_409);
  kk_std_core_hnd__marker m = _con3055->marker;
  kk_box_t _box_x2669 = _con3055->hnd;
  kk_effects_dash_and_dash_types__hnd_yield h = kk_effects_dash_and_dash_types__hnd_yield_unbox(_box_x2669, NULL);
  kk_effects_dash_and_dash_types__hnd_yield_dup(h);
  kk_std_core_hnd__clause0 _match_2787;
  struct kk_effects_dash_and_dash_types__Hnd_yield* _con3057 = kk_effects_dash_and_dash_types__as_Hnd_yield(h);
  kk_std_core_hnd__clause0 control_yield = _con3057->control_yield;
  if (kk_effects_dash_and_dash_types__hnd_yield_is_unique(h)) {
    kk_effects_dash_and_dash_types__hnd_yield_free(h);
  }
  else {
    kk_std_core_hnd__clause0_dup(control_yield);
    kk_effects_dash_and_dash_types__hnd_yield_decref(h, _ctx);
  }
  _match_2787 = control_yield; /*std/core/hnd/clause0<(),effects-and-types/.hnd-yield,6,7>*/
  kk_function_t _fun_unbox_x2672 = _match_2787.clause;
  _x3054 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x2672, (_fun_unbox_x2672, m, ev_409, _ctx)); /*6*/
  kk_unit_unbox(_x3054);
  kk_unit_t __w_l683_c9 = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x3058 = kk_std_core_hnd_yield_cont(kk_handlers__new_mlift2034_yield__on__scorex_fun3059(i_2119, _ctx), _ctx); /*3*/
    kk_unit_unbox(_x3058); return kk_Unit;
  }
  y; return kk_Unit;
}


// lift anonymous function
struct kk_handlers_yield__on__scorex_fun3062__t {
  struct kk_function_s _base;
};
static kk_box_t kk_handlers_yield__on__scorex_fun3062(kk_function_t _fself, kk_std_core_hnd__marker _b_2714, kk_std_core_hnd__ev _b_2715, kk_box_t _b_2716, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_yield__on__scorex_fun3062(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_handlers_yield__on__scorex_fun3062, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_handlers_yield__on__scorex_fun3063__t {
  struct kk_function_s _base;
};
static kk_box_t kk_handlers_yield__on__scorex_fun3063(kk_function_t _fself, kk_box_t _b_2712, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_yield__on__scorex_fun3063(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_handlers_yield__on__scorex_fun3063, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_handlers_yield__on__scorex_fun3068__t {
  struct kk_function_s _base;
  size_t i_2124;
};
static kk_box_t kk_handlers_yield__on__scorex_fun3068(kk_function_t _fself, kk_function_t _b_2697, kk_box_t _b_2698, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_yield__on__scorex_fun3068(size_t i_2124, kk_context_t* _ctx) {
  struct kk_handlers_yield__on__scorex_fun3068__t* _self = kk_function_alloc_as(struct kk_handlers_yield__on__scorex_fun3068__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_yield__on__scorex_fun3068, kk_context());
  _self->i_2124 = i_2124;
  return &_self->_base;
}

static kk_box_t kk_handlers_yield__on__scorex_fun3068(kk_function_t _fself, kk_function_t _b_2697, kk_box_t _b_2698, kk_context_t* _ctx) {
  struct kk_handlers_yield__on__scorex_fun3068__t* _self = kk_function_as(struct kk_handlers_yield__on__scorex_fun3068__t*, _fself);
  size_t i_2124 = _self->i_2124; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_2124, _b_2697, _b_2698, _ctx);
}


// lift anonymous function
struct kk_handlers_yield__on__scorex_fun3070__t {
  struct kk_function_s _base;
};
static kk_box_t kk_handlers_yield__on__scorex_fun3070(kk_function_t _fself, kk_box_t _b_2708, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_yield__on__scorex_fun3070(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_handlers_yield__on__scorex_fun3070, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_handlers_yield__on__scorex_fun3070(kk_function_t _fself, kk_box_t _b_2708, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_unit_t _x3071 = kk_Unit;
  kk_unit_t _x3072 = kk_Unit;
  kk_unit_unbox(_b_2708);
  kk_handlers__mlift2034_yield__on__scorex(_x3072, _ctx);
  return kk_unit_box(_x3071);
}
static kk_box_t kk_handlers_yield__on__scorex_fun3063(kk_function_t _fself, kk_box_t _b_2712, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_unit_t _x3064 = kk_Unit;
  kk_unit_t x0_2122 = kk_Unit;
  size_t i_2124;
  kk_std_core_hnd__htag _x3065 = kk_std_core_hnd__htag_dup(kk_effects_dash_and_dash_types__tag_score); /*std/core/hnd/htag<effects-and-types/.hnd-score>*/
  i_2124 = kk_std_core_hnd__evv_index(_x3065, _ctx); /*std/core/hnd/ev-index*/
  kk_evv_t w0 = kk_evv_swap_create1(i_2124,kk_context()); /*std/core/hnd/evv<<effects-and-types/score,effects-and-types/yield|1963>>*/;
  kk_unit_t y = kk_Unit;
  kk_effects_dash_and_dash_types__exp _x3066 = kk_effects_dash_and_dash_types__exp_unbox(_b_2712, _ctx); /*effects-and-types/exp*/
  kk_effects_dash_and_dash_types_score(_x3066, _ctx);
  kk_unit_t __w_l700_c9 = kk_Unit;
  kk_evv_set(w0,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x3067 = kk_std_core_hnd_yield_cont(kk_handlers_new_yield__on__scorex_fun3068(i_2124, _ctx), _ctx); /*3*/
    kk_unit_unbox(_x3067);
  }
  else {
    y;
  }
  if (kk_yielding(kk_context())) {
    kk_box_t _x3069 = kk_std_core_hnd_yield_extend(kk_handlers_new_yield__on__scorex_fun3070(_ctx), _ctx); /*2*/
    kk_unit_unbox(_x3069);
  }
  else {
    kk_handlers__mlift2034_yield__on__scorex(x0_2122, _ctx);
  }
  return kk_unit_box(_x3064);
}
static kk_box_t kk_handlers_yield__on__scorex_fun3062(kk_function_t _fself, kk_std_core_hnd__marker _b_2714, kk_std_core_hnd__ev _b_2715, kk_box_t _b_2716, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return kk_std_core_hnd_under1(_b_2715, kk_handlers_new_yield__on__scorex_fun3063(_ctx), _b_2716, _ctx);
}


// lift anonymous function
struct kk_handlers_yield__on__scorex_fun3073__t {
  struct kk_function_s _base;
};
static kk_box_t kk_handlers_yield__on__scorex_fun3073(kk_function_t _fself, kk_box_t _x, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_yield__on__scorex_fun3073(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_handlers_yield__on__scorex_fun3073, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_handlers_yield__on__scorex_fun3073(kk_function_t _fself, kk_box_t _x, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return _x;
}

kk_box_t kk_handlers_yield__on__scorex(kk_function_t action, kk_context_t* _ctx) { /* forall<a,e> (action : () -> <effects-and-types/score,effects-and-types/score,effects-and-types/yield|e> a) -> <effects-and-types/score,effects-and-types/yield|e> a */ 
  kk_effects_dash_and_dash_types__hnd_score _x3060;
  kk_std_core_hnd__clause1 _x3061 = kk_std_core_hnd__new_Clause1(kk_handlers_new_yield__on__scorex_fun3062(_ctx), _ctx); /*std/core/hnd/clause1<16,17,18,19,20>*/
  _x3060 = kk_effects_dash_and_dash_types__new_Hnd_score(kk_reuse_null, _x3061, _ctx); /*effects-and-types/.hnd-score<17,18>*/
  return kk_effects_dash_and_dash_types__handle_score(((int32_t)1), _x3060, kk_handlers_new_yield__on__scorex_fun3073(_ctx), action, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_handlers__mlift2035_replay_fun3074__t {
  struct kk_function_s _base;
  size_t _y_48;
};
static kk_box_t kk_handlers__mlift2035_replay_fun3074(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2035_replay_fun3074(size_t _y_48, kk_context_t* _ctx) {
  struct kk_handlers__mlift2035_replay_fun3074__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2035_replay_fun3074__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2035_replay_fun3074, kk_context());
  _self->_y_48 = _y_48;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift2035_replay_fun3074(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_handlers__mlift2035_replay_fun3074__t* _self = kk_function_as(struct kk_handlers__mlift2035_replay_fun3074__t*, _fself);
  size_t _y_48 = _self->_y_48; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_mask_at1(_y_48, true, cont, res, _ctx);
}

kk_box_t kk_handlers__mlift2035_replay(kk_function_t action, size_t _y_48, kk_context_t* _ctx) { /* forall<a,e> (action : () -> <effects-and-types/sample|e> a, std/core/hnd/ev-index) -> <effects-and-types/sample,effects-and-types/sample|e> a */ 
  kk_evv_t w0 = kk_std_core_hnd_evv_swap_delete(_y_48, true, _ctx); /*std/core/hnd/evv<std/core/hnd/_e2>*/;
  kk_box_t x = kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), action, (action, _ctx)); /*1980*/;
  kk_unit_t __w_l645_c9 = kk_Unit;
  kk_evv_set(w0,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_drop(x, _ctx);
    return kk_std_core_hnd_yield_cont(kk_handlers__new_mlift2035_replay_fun3074(_y_48, _ctx), _ctx);
  }
  return x;
}


// lift anonymous function
struct kk_handlers_replay_fun3075__t {
  struct kk_function_s _base;
  kk_function_t action;
};
static kk_box_t kk_handlers_replay_fun3075(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_replay_fun3075(kk_function_t action, kk_context_t* _ctx) {
  struct kk_handlers_replay_fun3075__t* _self = kk_function_alloc_as(struct kk_handlers_replay_fun3075__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_replay_fun3075, kk_context());
  _self->action = action;
  return &_self->_base;
}



// lift anonymous function
struct kk_handlers_replay_fun3077__t {
  struct kk_function_s _base;
  kk_function_t action;
};
static kk_box_t kk_handlers_replay_fun3077(kk_function_t _fself, kk_box_t _b_2728, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_replay_fun3077(kk_function_t action, kk_context_t* _ctx) {
  struct kk_handlers_replay_fun3077__t* _self = kk_function_alloc_as(struct kk_handlers_replay_fun3077__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_replay_fun3077, kk_context());
  _self->action = action;
  return &_self->_base;
}

static kk_box_t kk_handlers_replay_fun3077(kk_function_t _fself, kk_box_t _b_2728, kk_context_t* _ctx) {
  struct kk_handlers_replay_fun3077__t* _self = kk_function_as(struct kk_handlers_replay_fun3077__t*, _fself);
  kk_function_t action = _self->action; /* () -> <effects-and-types/sample|1981> 1980 */
  kk_drop_match(_self, {kk_function_dup(action);}, {}, _ctx)
  size_t _x3078 = kk_size_unbox(_b_2728, _ctx); /*std/core/hnd/ev-index*/
  return kk_handlers__mlift2035_replay(action, _x3078, _ctx);
}
static kk_box_t kk_handlers_replay_fun3075(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_handlers_replay_fun3075__t* _self = kk_function_as(struct kk_handlers_replay_fun3075__t*, _fself);
  kk_function_t action = _self->action; /* () -> <effects-and-types/sample|1981> 1980 */
  kk_drop_match(_self, {kk_function_dup(action);}, {}, _ctx)
  size_t x_2130;
  kk_std_core_hnd__htag _x3076 = kk_std_core_hnd__htag_dup(kk_effects_dash_and_dash_types__tag_sample); /*std/core/hnd/htag<effects-and-types/.hnd-sample>*/
  x_2130 = kk_std_core_hnd__evv_index(_x3076, _ctx); /*std/core/hnd/ev-index*/
  if (kk_yielding(kk_context())) {
    return kk_std_core_hnd_yield_extend(kk_handlers_new_replay_fun3077(action, _ctx), _ctx);
  }
  return kk_handlers__mlift2035_replay(action, x_2130, _ctx);
}

kk_std_core_types__tuple2_ kk_handlers_replay(kk_std_core__list trace, kk_function_t action, kk_context_t* _ctx) { /* forall<a,e> (trace : effects-and-types/trace_values, action : () -> <effects-and-types/sample|e> a) -> <effects-and-types/sample|e> (list<double>, a) */ 
  return kk_handlers_replayx(trace, kk_handlers_new_replay_fun3075(action, _ctx), _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_handlers__mlift2036_yield__on__score_fun3079__t {
  struct kk_function_s _base;
  size_t _y_51;
};
static kk_box_t kk_handlers__mlift2036_yield__on__score_fun3079(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2036_yield__on__score_fun3079(size_t _y_51, kk_context_t* _ctx) {
  struct kk_handlers__mlift2036_yield__on__score_fun3079__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2036_yield__on__score_fun3079__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2036_yield__on__score_fun3079, kk_context());
  _self->_y_51 = _y_51;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift2036_yield__on__score_fun3079(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_handlers__mlift2036_yield__on__score_fun3079__t* _self = kk_function_as(struct kk_handlers__mlift2036_yield__on__score_fun3079__t*, _fself);
  size_t _y_51 = _self->_y_51; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_mask_at1(_y_51, true, cont, res, _ctx);
}

kk_box_t kk_handlers__mlift2036_yield__on__score(kk_function_t action, size_t _y_51, kk_context_t* _ctx) { /* forall<a,e> (action : () -> <effects-and-types/score,effects-and-types/yield|e> a, std/core/hnd/ev-index) -> <effects-and-types/score,effects-and-types/score,effects-and-types/yield|e> a */ 
  kk_evv_t w0 = kk_std_core_hnd_evv_swap_delete(_y_51, true, _ctx); /*std/core/hnd/evv<std/core/hnd/_e2>*/;
  kk_box_t x = kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), action, (action, _ctx)); /*1999*/;
  kk_unit_t __w_l645_c9 = kk_Unit;
  kk_evv_set(w0,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_drop(x, _ctx);
    return kk_std_core_hnd_yield_cont(kk_handlers__new_mlift2036_yield__on__score_fun3079(_y_51, _ctx), _ctx);
  }
  return x;
}


// lift anonymous function
struct kk_handlers_yield__on__score_fun3082__t {
  struct kk_function_s _base;
};
static kk_box_t kk_handlers_yield__on__score_fun3082(kk_function_t _fself, kk_std_core_hnd__marker _b_2753, kk_std_core_hnd__ev _b_2754, kk_box_t _b_2755, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_yield__on__score_fun3082(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_handlers_yield__on__score_fun3082, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_handlers_yield__on__score_fun3083__t {
  struct kk_function_s _base;
};
static kk_box_t kk_handlers_yield__on__score_fun3083(kk_function_t _fself, kk_box_t _b_2751, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_yield__on__score_fun3083(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_handlers_yield__on__score_fun3083, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_handlers_yield__on__score_fun3088__t {
  struct kk_function_s _base;
  size_t i_2124;
};
static kk_box_t kk_handlers_yield__on__score_fun3088(kk_function_t _fself, kk_function_t _b_2736, kk_box_t _b_2737, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_yield__on__score_fun3088(size_t i_2124, kk_context_t* _ctx) {
  struct kk_handlers_yield__on__score_fun3088__t* _self = kk_function_alloc_as(struct kk_handlers_yield__on__score_fun3088__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_yield__on__score_fun3088, kk_context());
  _self->i_2124 = i_2124;
  return &_self->_base;
}

static kk_box_t kk_handlers_yield__on__score_fun3088(kk_function_t _fself, kk_function_t _b_2736, kk_box_t _b_2737, kk_context_t* _ctx) {
  struct kk_handlers_yield__on__score_fun3088__t* _self = kk_function_as(struct kk_handlers_yield__on__score_fun3088__t*, _fself);
  size_t i_2124 = _self->i_2124; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_2124, _b_2736, _b_2737, _ctx);
}


// lift anonymous function
struct kk_handlers_yield__on__score_fun3090__t {
  struct kk_function_s _base;
};
static kk_box_t kk_handlers_yield__on__score_fun3090(kk_function_t _fself, kk_box_t _b_2747, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_yield__on__score_fun3090(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_handlers_yield__on__score_fun3090, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_handlers_yield__on__score_fun3090(kk_function_t _fself, kk_box_t _b_2747, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_unit_t _x3091 = kk_Unit;
  kk_unit_t _x3092 = kk_Unit;
  kk_unit_unbox(_b_2747);
  kk_handlers__mlift2034_yield__on__scorex(_x3092, _ctx);
  return kk_unit_box(_x3091);
}
static kk_box_t kk_handlers_yield__on__score_fun3083(kk_function_t _fself, kk_box_t _b_2751, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_unit_t _x3084 = kk_Unit;
  kk_unit_t x0_2122 = kk_Unit;
  size_t i_2124;
  kk_std_core_hnd__htag _x3085 = kk_std_core_hnd__htag_dup(kk_effects_dash_and_dash_types__tag_score); /*std/core/hnd/htag<effects-and-types/.hnd-score>*/
  i_2124 = kk_std_core_hnd__evv_index(_x3085, _ctx); /*std/core/hnd/ev-index*/
  kk_evv_t w0 = kk_evv_swap_create1(i_2124,kk_context()); /*std/core/hnd/evv<<effects-and-types/score,effects-and-types/yield|2000>>*/;
  kk_unit_t y = kk_Unit;
  kk_effects_dash_and_dash_types__exp _x3086 = kk_effects_dash_and_dash_types__exp_unbox(_b_2751, _ctx); /*effects-and-types/exp*/
  kk_effects_dash_and_dash_types_score(_x3086, _ctx);
  kk_unit_t __w_l700_c9 = kk_Unit;
  kk_evv_set(w0,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x3087 = kk_std_core_hnd_yield_cont(kk_handlers_new_yield__on__score_fun3088(i_2124, _ctx), _ctx); /*3*/
    kk_unit_unbox(_x3087);
  }
  else {
    y;
  }
  if (kk_yielding(kk_context())) {
    kk_box_t _x3089 = kk_std_core_hnd_yield_extend(kk_handlers_new_yield__on__score_fun3090(_ctx), _ctx); /*2*/
    kk_unit_unbox(_x3089);
  }
  else {
    kk_handlers__mlift2034_yield__on__scorex(x0_2122, _ctx);
  }
  return kk_unit_box(_x3084);
}
static kk_box_t kk_handlers_yield__on__score_fun3082(kk_function_t _fself, kk_std_core_hnd__marker _b_2753, kk_std_core_hnd__ev _b_2754, kk_box_t _b_2755, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return kk_std_core_hnd_under1(_b_2754, kk_handlers_new_yield__on__score_fun3083(_ctx), _b_2755, _ctx);
}


// lift anonymous function
struct kk_handlers_yield__on__score_fun3093__t {
  struct kk_function_s _base;
};
static kk_box_t kk_handlers_yield__on__score_fun3093(kk_function_t _fself, kk_box_t _x, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_yield__on__score_fun3093(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_handlers_yield__on__score_fun3093, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_handlers_yield__on__score_fun3093(kk_function_t _fself, kk_box_t _x, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return _x;
}


// lift anonymous function
struct kk_handlers_yield__on__score_fun3094__t {
  struct kk_function_s _base;
  kk_function_t action;
};
static kk_box_t kk_handlers_yield__on__score_fun3094(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_yield__on__score_fun3094(kk_function_t action, kk_context_t* _ctx) {
  struct kk_handlers_yield__on__score_fun3094__t* _self = kk_function_alloc_as(struct kk_handlers_yield__on__score_fun3094__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_yield__on__score_fun3094, kk_context());
  _self->action = action;
  return &_self->_base;
}



// lift anonymous function
struct kk_handlers_yield__on__score_fun3096__t {
  struct kk_function_s _base;
  kk_function_t action;
};
static kk_box_t kk_handlers_yield__on__score_fun3096(kk_function_t _fself, kk_box_t _b_2757, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_yield__on__score_fun3096(kk_function_t action, kk_context_t* _ctx) {
  struct kk_handlers_yield__on__score_fun3096__t* _self = kk_function_alloc_as(struct kk_handlers_yield__on__score_fun3096__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_yield__on__score_fun3096, kk_context());
  _self->action = action;
  return &_self->_base;
}

static kk_box_t kk_handlers_yield__on__score_fun3096(kk_function_t _fself, kk_box_t _b_2757, kk_context_t* _ctx) {
  struct kk_handlers_yield__on__score_fun3096__t* _self = kk_function_as(struct kk_handlers_yield__on__score_fun3096__t*, _fself);
  kk_function_t action = _self->action; /* () -> <effects-and-types/score,effects-and-types/yield|2000> 1999 */
  kk_drop_match(_self, {kk_function_dup(action);}, {}, _ctx)
  size_t _x3097 = kk_size_unbox(_b_2757, _ctx); /*std/core/hnd/ev-index*/
  return kk_handlers__mlift2036_yield__on__score(action, _x3097, _ctx);
}
static kk_box_t kk_handlers_yield__on__score_fun3094(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_handlers_yield__on__score_fun3094__t* _self = kk_function_as(struct kk_handlers_yield__on__score_fun3094__t*, _fself);
  kk_function_t action = _self->action; /* () -> <effects-and-types/score,effects-and-types/yield|2000> 1999 */
  kk_drop_match(_self, {kk_function_dup(action);}, {}, _ctx)
  size_t x_2135;
  kk_std_core_hnd__htag _x3095 = kk_std_core_hnd__htag_dup(kk_effects_dash_and_dash_types__tag_score); /*std/core/hnd/htag<effects-and-types/.hnd-score>*/
  x_2135 = kk_std_core_hnd__evv_index(_x3095, _ctx); /*std/core/hnd/ev-index*/
  if (kk_yielding(kk_context())) {
    return kk_std_core_hnd_yield_extend(kk_handlers_new_yield__on__score_fun3096(action, _ctx), _ctx);
  }
  return kk_handlers__mlift2036_yield__on__score(action, x_2135, _ctx);
}

kk_box_t kk_handlers_yield__on__score(kk_function_t action, kk_context_t* _ctx) { /* forall<a,e> (action : () -> <effects-and-types/score,effects-and-types/yield|e> a) -> <effects-and-types/score,effects-and-types/yield|e> a */ 
  kk_effects_dash_and_dash_types__hnd_score _x3080;
  kk_std_core_hnd__clause1 _x3081 = kk_std_core_hnd__new_Clause1(kk_handlers_new_yield__on__score_fun3082(_ctx), _ctx); /*std/core/hnd/clause1<16,17,18,19,20>*/
  _x3080 = kk_effects_dash_and_dash_types__new_Hnd_score(kk_reuse_null, _x3081, _ctx); /*effects-and-types/.hnd-score<17,18>*/
  return kk_effects_dash_and_dash_types__handle_score(((int32_t)1), _x3080, kk_handlers_new_yield__on__score_fun3093(_ctx), kk_handlers_new_yield__on__score_fun3094(action, _ctx), _ctx);
}

// initialization
void kk_handlers__init(kk_context_t* _ctx){
  static bool _initialized = false;
  if (_initialized) return;
  _initialized = true;
  kk_std_core_types__init(_ctx);
  kk_std_core_hnd__init(_ctx);
  kk_std_core__init(_ctx);
  kk_std_num_random__init(_ctx);
  kk_effects_dash_and_dash_types__init(_ctx);
  kk_exponents__init(_ctx);
}
