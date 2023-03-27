// Koka generated module: "handlers", koka version: 2.1.2
#include "handlers.h"
 
// monadic lift

kk_box_t kk_handlers__mlift1696_advance(kk_integer_t a, kk_function_t _y_2, kk_context_t* _ctx) { /* forall<a,e> (a : int, (int) -> <effects-and-types/yield|e> a) -> <effects-and-types/yield|e> a */ 
  kk_integer_t _x2372 = kk_integer_sub(a,(kk_integer_from_small(1)),kk_context()); /*int*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_context_t*), _y_2, (_y_2, _x2372, _ctx));
}
 
// monadic lift


// lift anonymous function
struct kk_handlers__mlift1697_advance_fun2374__t {
  struct kk_function_s _base;
  size_t _y_0;
};
static kk_box_t kk_handlers__mlift1697_advance_fun2374(kk_function_t _fself, kk_function_t _b_1843, kk_box_t _b_1844, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift1697_advance_fun2374(size_t _y_0, kk_context_t* _ctx) {
  struct kk_handlers__mlift1697_advance_fun2374__t* _self = kk_function_alloc_as(struct kk_handlers__mlift1697_advance_fun2374__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift1697_advance_fun2374, kk_context());
  _self->_y_0 = _y_0;
  return &_self->_base;
}



// lift anonymous function
struct kk_handlers__mlift1697_advance_fun2377__t {
  struct kk_function_s _base;
  kk_function_t _b_1843;
};
static kk_box_t kk_handlers__mlift1697_advance_fun2377(kk_function_t _fself, kk_box_t _b_1827, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift1697_advance_fun2377(kk_function_t _b_1843, kk_context_t* _ctx) {
  struct kk_handlers__mlift1697_advance_fun2377__t* _self = kk_function_alloc_as(struct kk_handlers__mlift1697_advance_fun2377__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift1697_advance_fun2377, kk_context());
  _self->_b_1843 = _b_1843;
  return &_self->_base;
}



// lift anonymous function
struct kk_handlers__mlift1697_advance_fun2380__t {
  struct kk_function_s _base;
  kk_box_t _b_1827;
};
static kk_box_t kk_handlers__mlift1697_advance_fun2380(kk_function_t _fself, kk_box_t _b_1848, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift1697_advance_fun2380(kk_box_t _b_1827, kk_context_t* _ctx) {
  struct kk_handlers__mlift1697_advance_fun2380__t* _self = kk_function_alloc_as(struct kk_handlers__mlift1697_advance_fun2380__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift1697_advance_fun2380, kk_context());
  _self->_b_1827 = _b_1827;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift1697_advance_fun2380(kk_function_t _fself, kk_box_t _b_1848, kk_context_t* _ctx) {
  struct kk_handlers__mlift1697_advance_fun2380__t* _self = kk_function_as(struct kk_handlers__mlift1697_advance_fun2380__t*, _fself);
  kk_box_t _b_1827 = _self->_b_1827; /* 1 */
  kk_drop_match(_self, {kk_box_dup(_b_1827);}, {}, _ctx)
  kk_function_t _x2381 = kk_function_unbox(_b_1827); /*(1828) -> <effects-and-types/yield|215> 1829*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x2381, (_x2381, _b_1848, _ctx));
}


// lift anonymous function
struct kk_handlers__mlift1697_advance_fun2382__t {
  struct kk_function_s _base;
  kk_function_t _bv_1851;
};
static kk_box_t kk_handlers__mlift1697_advance_fun2382(kk_function_t _fself, kk_integer_t _b_1852, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift1697_advance_fun2382(kk_function_t _bv_1851, kk_context_t* _ctx) {
  struct kk_handlers__mlift1697_advance_fun2382__t* _self = kk_function_alloc_as(struct kk_handlers__mlift1697_advance_fun2382__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift1697_advance_fun2382, kk_context());
  _self->_bv_1851 = _bv_1851;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift1697_advance_fun2382(kk_function_t _fself, kk_integer_t _b_1852, kk_context_t* _ctx) {
  struct kk_handlers__mlift1697_advance_fun2382__t* _self = kk_function_as(struct kk_handlers__mlift1697_advance_fun2382__t*, _fself);
  kk_function_t _bv_1851 = _self->_bv_1851; /* (1849) -> <effects-and-types/yield|215> 1850 */
  kk_drop_match(_self, {kk_function_dup(_bv_1851);}, {}, _ctx)
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _bv_1851, (_bv_1851, kk_integer_box(_b_1852), _ctx));
}


// lift anonymous function
struct kk_handlers__mlift1697_advance_fun2383__t {
  struct kk_function_s _base;
  kk_function_t _bv_1833;
};
static kk_box_t kk_handlers__mlift1697_advance_fun2383(kk_function_t _fself, kk_box_t _b_1834, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift1697_advance_fun2383(kk_function_t _bv_1833, kk_context_t* _ctx) {
  struct kk_handlers__mlift1697_advance_fun2383__t* _self = kk_function_alloc_as(struct kk_handlers__mlift1697_advance_fun2383__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift1697_advance_fun2383, kk_context());
  _self->_bv_1833 = _bv_1833;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift1697_advance_fun2383(kk_function_t _fself, kk_box_t _b_1834, kk_context_t* _ctx) {
  struct kk_handlers__mlift1697_advance_fun2383__t* _self = kk_function_as(struct kk_handlers__mlift1697_advance_fun2383__t*, _fself);
  kk_function_t _bv_1833 = _self->_bv_1833; /* (int) -> <effects-and-types/yield|215> 214 */
  kk_drop_match(_self, {kk_function_dup(_bv_1833);}, {}, _ctx)
  kk_integer_t _x2384 = kk_integer_unbox(_b_1834); /*int*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_context_t*), _bv_1833, (_bv_1833, _x2384, _ctx));
}
static kk_box_t kk_handlers__mlift1697_advance_fun2377(kk_function_t _fself, kk_box_t _b_1827, kk_context_t* _ctx) {
  struct kk_handlers__mlift1697_advance_fun2377__t* _self = kk_function_as(struct kk_handlers__mlift1697_advance_fun2377__t*, _fself);
  kk_function_t _b_1843 = _self->_b_1843; /* (1) -> 2 1 */
  kk_drop_match(_self, {kk_function_dup(_b_1843);}, {}, _ctx)
  kk_function_t _x2378;
  kk_function_t _bv_1833;
  kk_function_t _bv_1851;
  kk_box_t _x2379 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _b_1843, (_b_1843, kk_function_box(kk_handlers__new_mlift1697_advance_fun2380(_b_1827, _ctx)), _ctx)); /*1*/
  _bv_1851 = kk_function_unbox(_x2379); /*(1849) -> <effects-and-types/yield|215> 1850*/
  _bv_1833 = kk_handlers__new_mlift1697_advance_fun2382(_bv_1851, _ctx); /*(int) -> <effects-and-types/yield|215> 214*/
  _x2378 = kk_handlers__new_mlift1697_advance_fun2383(_bv_1833, _ctx); /*(1831) -> <effects-and-types/yield|215> 214*/
  return kk_function_box(_x2378);
}


// lift anonymous function
struct kk_handlers__mlift1697_advance_fun2385__t {
  struct kk_function_s _base;
  kk_box_t _b_1844;
};
static kk_box_t kk_handlers__mlift1697_advance_fun2385(kk_function_t _fself, kk_box_t _b_1837, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift1697_advance_fun2385(kk_box_t _b_1844, kk_context_t* _ctx) {
  struct kk_handlers__mlift1697_advance_fun2385__t* _self = kk_function_alloc_as(struct kk_handlers__mlift1697_advance_fun2385__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift1697_advance_fun2385, kk_context());
  _self->_b_1844 = _b_1844;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift1697_advance_fun2385(kk_function_t _fself, kk_box_t _b_1837, kk_context_t* _ctx) {
  struct kk_handlers__mlift1697_advance_fun2385__t* _self = kk_function_as(struct kk_handlers__mlift1697_advance_fun2385__t*, _fself);
  kk_box_t _b_1844 = _self->_b_1844; /* 1 */
  kk_drop_match(_self, {kk_box_dup(_b_1844);}, {}, _ctx)
  kk_function_t _x2386 = kk_function_unbox(_b_1844); /*(1853) -> <effects-and-types/yield|215> 1854*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x2386, (_x2386, _b_1837, _ctx));
}


// lift anonymous function
struct kk_handlers__mlift1697_advance_fun2387__t {
  struct kk_function_s _base;
  kk_function_t _bv_1840;
};
static kk_box_t kk_handlers__mlift1697_advance_fun2387(kk_function_t _fself, kk_integer_t _b_1841, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift1697_advance_fun2387(kk_function_t _bv_1840, kk_context_t* _ctx) {
  struct kk_handlers__mlift1697_advance_fun2387__t* _self = kk_function_alloc_as(struct kk_handlers__mlift1697_advance_fun2387__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift1697_advance_fun2387, kk_context());
  _self->_bv_1840 = _bv_1840;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift1697_advance_fun2387(kk_function_t _fself, kk_integer_t _b_1841, kk_context_t* _ctx) {
  struct kk_handlers__mlift1697_advance_fun2387__t* _self = kk_function_as(struct kk_handlers__mlift1697_advance_fun2387__t*, _fself);
  kk_function_t _bv_1840 = _self->_bv_1840; /* (1838) -> <effects-and-types/yield|215> 1839 */
  kk_drop_match(_self, {kk_function_dup(_bv_1840);}, {}, _ctx)
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _bv_1840, (_bv_1840, kk_integer_box(_b_1841), _ctx));
}


// lift anonymous function
struct kk_handlers__mlift1697_advance_fun2388__t {
  struct kk_function_s _base;
  kk_function_t _bv_1858;
};
static kk_box_t kk_handlers__mlift1697_advance_fun2388(kk_function_t _fself, kk_box_t _b_1859, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift1697_advance_fun2388(kk_function_t _bv_1858, kk_context_t* _ctx) {
  struct kk_handlers__mlift1697_advance_fun2388__t* _self = kk_function_alloc_as(struct kk_handlers__mlift1697_advance_fun2388__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift1697_advance_fun2388, kk_context());
  _self->_bv_1858 = _bv_1858;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift1697_advance_fun2388(kk_function_t _fself, kk_box_t _b_1859, kk_context_t* _ctx) {
  struct kk_handlers__mlift1697_advance_fun2388__t* _self = kk_function_as(struct kk_handlers__mlift1697_advance_fun2388__t*, _fself);
  kk_function_t _bv_1858 = _self->_bv_1858; /* (int) -> <effects-and-types/yield|215> 214 */
  kk_drop_match(_self, {kk_function_dup(_bv_1858);}, {}, _ctx)
  kk_integer_t _x2389 = kk_integer_unbox(_b_1859); /*int*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_context_t*), _bv_1858, (_bv_1858, _x2389, _ctx));
}
static kk_box_t kk_handlers__mlift1697_advance_fun2374(kk_function_t _fself, kk_function_t _b_1843, kk_box_t _b_1844, kk_context_t* _ctx) {
  struct kk_handlers__mlift1697_advance_fun2374__t* _self = kk_function_as(struct kk_handlers__mlift1697_advance_fun2374__t*, _fself);
  size_t _y_0 = _self->_y_0; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  kk_function_t _x2375;
  kk_function_t _bv_1858;
  kk_function_t _bv_1840;
  kk_box_t _x2376 = kk_std_core_hnd_mask_at1(_y_0, false, kk_handlers__new_mlift1697_advance_fun2377(_b_1843, _ctx), kk_function_box(kk_handlers__new_mlift1697_advance_fun2385(_b_1844, _ctx)), _ctx); /*2*/
  _bv_1840 = kk_function_unbox(_x2376); /*(1838) -> <effects-and-types/yield|215> 1839*/
  _bv_1858 = kk_handlers__new_mlift1697_advance_fun2387(_bv_1840, _ctx); /*(int) -> <effects-and-types/yield|215> 214*/
  _x2375 = kk_handlers__new_mlift1697_advance_fun2388(_bv_1858, _ctx); /*(1856) -> <effects-and-types/yield|215> 214*/
  return kk_function_box(_x2375);
}


// lift anonymous function
struct kk_handlers__mlift1697_advance_fun2390__t {
  struct kk_function_s _base;
  kk_function_t _bv_1862;
};
static kk_box_t kk_handlers__mlift1697_advance_fun2390(kk_function_t _fself, kk_integer_t _b_1863, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift1697_advance_fun2390(kk_function_t _bv_1862, kk_context_t* _ctx) {
  struct kk_handlers__mlift1697_advance_fun2390__t* _self = kk_function_alloc_as(struct kk_handlers__mlift1697_advance_fun2390__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift1697_advance_fun2390, kk_context());
  _self->_bv_1862 = _bv_1862;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift1697_advance_fun2390(kk_function_t _fself, kk_integer_t _b_1863, kk_context_t* _ctx) {
  struct kk_handlers__mlift1697_advance_fun2390__t* _self = kk_function_as(struct kk_handlers__mlift1697_advance_fun2390__t*, _fself);
  kk_function_t _bv_1862 = _self->_bv_1862; /* (1860) -> <.Box|.Box> 1861 */
  kk_drop_match(_self, {kk_function_dup(_bv_1862);}, {}, _ctx)
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _bv_1862, (_bv_1862, kk_integer_box(_b_1863), _ctx));
}


// lift anonymous function
struct kk_handlers__mlift1697_advance_fun2391__t {
  struct kk_function_s _base;
  kk_integer_t a;
};
static kk_box_t kk_handlers__mlift1697_advance_fun2391(kk_function_t _fself, kk_box_t _b_1875, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift1697_advance_fun2391(kk_integer_t a, kk_context_t* _ctx) {
  struct kk_handlers__mlift1697_advance_fun2391__t* _self = kk_function_alloc_as(struct kk_handlers__mlift1697_advance_fun2391__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift1697_advance_fun2391, kk_context());
  _self->a = a;
  return &_self->_base;
}



// lift anonymous function
struct kk_handlers__mlift1697_advance_fun2392__t {
  struct kk_function_s _base;
  kk_box_t _b_1875;
};
static kk_box_t kk_handlers__mlift1697_advance_fun2392(kk_function_t _fself, kk_integer_t _b_1878, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift1697_advance_fun2392(kk_box_t _b_1875, kk_context_t* _ctx) {
  struct kk_handlers__mlift1697_advance_fun2392__t* _self = kk_function_alloc_as(struct kk_handlers__mlift1697_advance_fun2392__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift1697_advance_fun2392, kk_context());
  _self->_b_1875 = _b_1875;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift1697_advance_fun2392(kk_function_t _fself, kk_integer_t _b_1878, kk_context_t* _ctx) {
  struct kk_handlers__mlift1697_advance_fun2392__t* _self = kk_function_as(struct kk_handlers__mlift1697_advance_fun2392__t*, _fself);
  kk_box_t _b_1875 = _self->_b_1875; /* 1 */
  kk_drop_match(_self, {kk_box_dup(_b_1875);}, {}, _ctx)
  kk_function_t _x2393 = kk_function_unbox(_b_1875); /*(1876) -> <effects-and-types/yield|215> 1877*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x2393, (_x2393, kk_integer_box(_b_1878), _ctx));
}
static kk_box_t kk_handlers__mlift1697_advance_fun2391(kk_function_t _fself, kk_box_t _b_1875, kk_context_t* _ctx) {
  struct kk_handlers__mlift1697_advance_fun2391__t* _self = kk_function_as(struct kk_handlers__mlift1697_advance_fun2391__t*, _fself);
  kk_integer_t a = _self->a; /* int */
  kk_drop_match(_self, {kk_integer_dup(a);}, {}, _ctx)
  return kk_handlers__mlift1696_advance(a, kk_handlers__new_mlift1697_advance_fun2392(_b_1875, _ctx), _ctx);
}

kk_box_t kk_handlers__mlift1697_advance(kk_integer_t a, kk_function_t resume, size_t _y_0, kk_context_t* _ctx) { /* forall<a,e> (a : int, resume : (()) -> e ((int) -> <effects-and-types/yield|e> a), std/core/hnd/ev-index) -> <effects-and-types/yield|e> a */ 
  kk_function_t x_1715;
  kk_evv_t w0 = kk_std_core_hnd_evv_swap_delete(_y_0, false, _ctx); /*std/core/hnd/evv<std/core/hnd/_e2>*/;
  kk_function_t x0 = kk_function_call(kk_function_t, (kk_function_t, kk_unit_t, kk_context_t*), resume, (resume, kk_Unit, _ctx)); /*(int) -> <effects-and-types/yield|215> 214*/;
  kk_unit_t __w_l641_c9 = kk_Unit;
  kk_evv_set(w0,kk_context());
  if (kk_yielding(kk_context())) {
    kk_function_drop(x0, _ctx);
    kk_function_t _bv_1862;
    kk_box_t _x2373 = kk_std_core_hnd_yield_cont(kk_handlers__new_mlift1697_advance_fun2374(_y_0, _ctx), _ctx); /*3*/
    _bv_1862 = kk_function_unbox(_x2373); /*(1860) -> <.Box|.Box> 1861*/
    x_1715 = kk_handlers__new_mlift1697_advance_fun2390(_bv_1862, _ctx); /*(int) -> <effects-and-types/yield|215> 214*/
  }
  else {
    x_1715 = x0; /*(int) -> <effects-and-types/yield|215> 214*/
  }
  if (kk_yielding(kk_context())) {
    kk_function_drop(x_1715, _ctx);
    return kk_std_core_hnd_yield_extend(kk_handlers__new_mlift1697_advance_fun2391(a, _ctx), _ctx);
  }
  return kk_handlers__mlift1696_advance(a, x_1715, _ctx);
}
 
// monadic lift

kk_box_t kk_handlers__mlift1698_advance(kk_function_t _y_7, kk_context_t* _ctx) { /* forall<a,e> ((int) -> <effects-and-types/yield|e> a) -> <effects-and-types/yield|e> a */ 
  return kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_context_t*), _y_7, (_y_7, kk_integer_from_small(0), _ctx));
}
 
// monadic lift


// lift anonymous function
struct kk_handlers__mlift1699_advance_fun2395__t {
  struct kk_function_s _base;
  size_t _y_5;
};
static kk_box_t kk_handlers__mlift1699_advance_fun2395(kk_function_t _fself, kk_function_t _b_1901, kk_box_t _b_1902, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift1699_advance_fun2395(size_t _y_5, kk_context_t* _ctx) {
  struct kk_handlers__mlift1699_advance_fun2395__t* _self = kk_function_alloc_as(struct kk_handlers__mlift1699_advance_fun2395__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift1699_advance_fun2395, kk_context());
  _self->_y_5 = _y_5;
  return &_self->_base;
}



// lift anonymous function
struct kk_handlers__mlift1699_advance_fun2398__t {
  struct kk_function_s _base;
  kk_function_t _b_1901;
};
static kk_box_t kk_handlers__mlift1699_advance_fun2398(kk_function_t _fself, kk_box_t _b_1885, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift1699_advance_fun2398(kk_function_t _b_1901, kk_context_t* _ctx) {
  struct kk_handlers__mlift1699_advance_fun2398__t* _self = kk_function_alloc_as(struct kk_handlers__mlift1699_advance_fun2398__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift1699_advance_fun2398, kk_context());
  _self->_b_1901 = _b_1901;
  return &_self->_base;
}



// lift anonymous function
struct kk_handlers__mlift1699_advance_fun2401__t {
  struct kk_function_s _base;
  kk_box_t _b_1885;
};
static kk_box_t kk_handlers__mlift1699_advance_fun2401(kk_function_t _fself, kk_box_t _b_1906, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift1699_advance_fun2401(kk_box_t _b_1885, kk_context_t* _ctx) {
  struct kk_handlers__mlift1699_advance_fun2401__t* _self = kk_function_alloc_as(struct kk_handlers__mlift1699_advance_fun2401__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift1699_advance_fun2401, kk_context());
  _self->_b_1885 = _b_1885;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift1699_advance_fun2401(kk_function_t _fself, kk_box_t _b_1906, kk_context_t* _ctx) {
  struct kk_handlers__mlift1699_advance_fun2401__t* _self = kk_function_as(struct kk_handlers__mlift1699_advance_fun2401__t*, _fself);
  kk_box_t _b_1885 = _self->_b_1885; /* 1 */
  kk_drop_match(_self, {kk_box_dup(_b_1885);}, {}, _ctx)
  kk_function_t _x2402 = kk_function_unbox(_b_1885); /*(1886) -> <effects-and-types/yield|215> 1887*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x2402, (_x2402, _b_1906, _ctx));
}


// lift anonymous function
struct kk_handlers__mlift1699_advance_fun2403__t {
  struct kk_function_s _base;
  kk_function_t _bv_1909;
};
static kk_box_t kk_handlers__mlift1699_advance_fun2403(kk_function_t _fself, kk_integer_t _b_1910, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift1699_advance_fun2403(kk_function_t _bv_1909, kk_context_t* _ctx) {
  struct kk_handlers__mlift1699_advance_fun2403__t* _self = kk_function_alloc_as(struct kk_handlers__mlift1699_advance_fun2403__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift1699_advance_fun2403, kk_context());
  _self->_bv_1909 = _bv_1909;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift1699_advance_fun2403(kk_function_t _fself, kk_integer_t _b_1910, kk_context_t* _ctx) {
  struct kk_handlers__mlift1699_advance_fun2403__t* _self = kk_function_as(struct kk_handlers__mlift1699_advance_fun2403__t*, _fself);
  kk_function_t _bv_1909 = _self->_bv_1909; /* (1907) -> <effects-and-types/yield|215> 1908 */
  kk_drop_match(_self, {kk_function_dup(_bv_1909);}, {}, _ctx)
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _bv_1909, (_bv_1909, kk_integer_box(_b_1910), _ctx));
}


// lift anonymous function
struct kk_handlers__mlift1699_advance_fun2404__t {
  struct kk_function_s _base;
  kk_function_t _bv_1891;
};
static kk_box_t kk_handlers__mlift1699_advance_fun2404(kk_function_t _fself, kk_box_t _b_1892, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift1699_advance_fun2404(kk_function_t _bv_1891, kk_context_t* _ctx) {
  struct kk_handlers__mlift1699_advance_fun2404__t* _self = kk_function_alloc_as(struct kk_handlers__mlift1699_advance_fun2404__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift1699_advance_fun2404, kk_context());
  _self->_bv_1891 = _bv_1891;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift1699_advance_fun2404(kk_function_t _fself, kk_box_t _b_1892, kk_context_t* _ctx) {
  struct kk_handlers__mlift1699_advance_fun2404__t* _self = kk_function_as(struct kk_handlers__mlift1699_advance_fun2404__t*, _fself);
  kk_function_t _bv_1891 = _self->_bv_1891; /* (int) -> <effects-and-types/yield|215> 214 */
  kk_drop_match(_self, {kk_function_dup(_bv_1891);}, {}, _ctx)
  kk_integer_t _x2405 = kk_integer_unbox(_b_1892); /*int*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_context_t*), _bv_1891, (_bv_1891, _x2405, _ctx));
}
static kk_box_t kk_handlers__mlift1699_advance_fun2398(kk_function_t _fself, kk_box_t _b_1885, kk_context_t* _ctx) {
  struct kk_handlers__mlift1699_advance_fun2398__t* _self = kk_function_as(struct kk_handlers__mlift1699_advance_fun2398__t*, _fself);
  kk_function_t _b_1901 = _self->_b_1901; /* (1) -> 2 1 */
  kk_drop_match(_self, {kk_function_dup(_b_1901);}, {}, _ctx)
  kk_function_t _x2399;
  kk_function_t _bv_1891;
  kk_function_t _bv_1909;
  kk_box_t _x2400 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _b_1901, (_b_1901, kk_function_box(kk_handlers__new_mlift1699_advance_fun2401(_b_1885, _ctx)), _ctx)); /*1*/
  _bv_1909 = kk_function_unbox(_x2400); /*(1907) -> <effects-and-types/yield|215> 1908*/
  _bv_1891 = kk_handlers__new_mlift1699_advance_fun2403(_bv_1909, _ctx); /*(int) -> <effects-and-types/yield|215> 214*/
  _x2399 = kk_handlers__new_mlift1699_advance_fun2404(_bv_1891, _ctx); /*(1889) -> <effects-and-types/yield|215> 214*/
  return kk_function_box(_x2399);
}


// lift anonymous function
struct kk_handlers__mlift1699_advance_fun2406__t {
  struct kk_function_s _base;
  kk_box_t _b_1902;
};
static kk_box_t kk_handlers__mlift1699_advance_fun2406(kk_function_t _fself, kk_box_t _b_1895, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift1699_advance_fun2406(kk_box_t _b_1902, kk_context_t* _ctx) {
  struct kk_handlers__mlift1699_advance_fun2406__t* _self = kk_function_alloc_as(struct kk_handlers__mlift1699_advance_fun2406__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift1699_advance_fun2406, kk_context());
  _self->_b_1902 = _b_1902;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift1699_advance_fun2406(kk_function_t _fself, kk_box_t _b_1895, kk_context_t* _ctx) {
  struct kk_handlers__mlift1699_advance_fun2406__t* _self = kk_function_as(struct kk_handlers__mlift1699_advance_fun2406__t*, _fself);
  kk_box_t _b_1902 = _self->_b_1902; /* 1 */
  kk_drop_match(_self, {kk_box_dup(_b_1902);}, {}, _ctx)
  kk_function_t _x2407 = kk_function_unbox(_b_1902); /*(1911) -> <effects-and-types/yield|215> 1912*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x2407, (_x2407, _b_1895, _ctx));
}


// lift anonymous function
struct kk_handlers__mlift1699_advance_fun2408__t {
  struct kk_function_s _base;
  kk_function_t _bv_1898;
};
static kk_box_t kk_handlers__mlift1699_advance_fun2408(kk_function_t _fself, kk_integer_t _b_1899, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift1699_advance_fun2408(kk_function_t _bv_1898, kk_context_t* _ctx) {
  struct kk_handlers__mlift1699_advance_fun2408__t* _self = kk_function_alloc_as(struct kk_handlers__mlift1699_advance_fun2408__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift1699_advance_fun2408, kk_context());
  _self->_bv_1898 = _bv_1898;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift1699_advance_fun2408(kk_function_t _fself, kk_integer_t _b_1899, kk_context_t* _ctx) {
  struct kk_handlers__mlift1699_advance_fun2408__t* _self = kk_function_as(struct kk_handlers__mlift1699_advance_fun2408__t*, _fself);
  kk_function_t _bv_1898 = _self->_bv_1898; /* (1896) -> <effects-and-types/yield|215> 1897 */
  kk_drop_match(_self, {kk_function_dup(_bv_1898);}, {}, _ctx)
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _bv_1898, (_bv_1898, kk_integer_box(_b_1899), _ctx));
}


// lift anonymous function
struct kk_handlers__mlift1699_advance_fun2409__t {
  struct kk_function_s _base;
  kk_function_t _bv_1916;
};
static kk_box_t kk_handlers__mlift1699_advance_fun2409(kk_function_t _fself, kk_box_t _b_1917, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift1699_advance_fun2409(kk_function_t _bv_1916, kk_context_t* _ctx) {
  struct kk_handlers__mlift1699_advance_fun2409__t* _self = kk_function_alloc_as(struct kk_handlers__mlift1699_advance_fun2409__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift1699_advance_fun2409, kk_context());
  _self->_bv_1916 = _bv_1916;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift1699_advance_fun2409(kk_function_t _fself, kk_box_t _b_1917, kk_context_t* _ctx) {
  struct kk_handlers__mlift1699_advance_fun2409__t* _self = kk_function_as(struct kk_handlers__mlift1699_advance_fun2409__t*, _fself);
  kk_function_t _bv_1916 = _self->_bv_1916; /* (int) -> <effects-and-types/yield|215> 214 */
  kk_drop_match(_self, {kk_function_dup(_bv_1916);}, {}, _ctx)
  kk_integer_t _x2410 = kk_integer_unbox(_b_1917); /*int*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_context_t*), _bv_1916, (_bv_1916, _x2410, _ctx));
}
static kk_box_t kk_handlers__mlift1699_advance_fun2395(kk_function_t _fself, kk_function_t _b_1901, kk_box_t _b_1902, kk_context_t* _ctx) {
  struct kk_handlers__mlift1699_advance_fun2395__t* _self = kk_function_as(struct kk_handlers__mlift1699_advance_fun2395__t*, _fself);
  size_t _y_5 = _self->_y_5; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  kk_function_t _x2396;
  kk_function_t _bv_1916;
  kk_function_t _bv_1898;
  kk_box_t _x2397 = kk_std_core_hnd_mask_at1(_y_5, false, kk_handlers__new_mlift1699_advance_fun2398(_b_1901, _ctx), kk_function_box(kk_handlers__new_mlift1699_advance_fun2406(_b_1902, _ctx)), _ctx); /*2*/
  _bv_1898 = kk_function_unbox(_x2397); /*(1896) -> <effects-and-types/yield|215> 1897*/
  _bv_1916 = kk_handlers__new_mlift1699_advance_fun2408(_bv_1898, _ctx); /*(int) -> <effects-and-types/yield|215> 214*/
  _x2396 = kk_handlers__new_mlift1699_advance_fun2409(_bv_1916, _ctx); /*(1914) -> <effects-and-types/yield|215> 214*/
  return kk_function_box(_x2396);
}


// lift anonymous function
struct kk_handlers__mlift1699_advance_fun2411__t {
  struct kk_function_s _base;
  kk_function_t _bv_1920;
};
static kk_box_t kk_handlers__mlift1699_advance_fun2411(kk_function_t _fself, kk_integer_t _b_1921, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift1699_advance_fun2411(kk_function_t _bv_1920, kk_context_t* _ctx) {
  struct kk_handlers__mlift1699_advance_fun2411__t* _self = kk_function_alloc_as(struct kk_handlers__mlift1699_advance_fun2411__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift1699_advance_fun2411, kk_context());
  _self->_bv_1920 = _bv_1920;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift1699_advance_fun2411(kk_function_t _fself, kk_integer_t _b_1921, kk_context_t* _ctx) {
  struct kk_handlers__mlift1699_advance_fun2411__t* _self = kk_function_as(struct kk_handlers__mlift1699_advance_fun2411__t*, _fself);
  kk_function_t _bv_1920 = _self->_bv_1920; /* (1918) -> <.Box|.Box> 1919 */
  kk_drop_match(_self, {kk_function_dup(_bv_1920);}, {}, _ctx)
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _bv_1920, (_bv_1920, kk_integer_box(_b_1921), _ctx));
}


// lift anonymous function
struct kk_handlers__mlift1699_advance_fun2412__t {
  struct kk_function_s _base;
};
static kk_box_t kk_handlers__mlift1699_advance_fun2412(kk_function_t _fself, kk_box_t _b_1933, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift1699_advance_fun2412(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_handlers__mlift1699_advance_fun2412, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_handlers__mlift1699_advance_fun2413__t {
  struct kk_function_s _base;
  kk_box_t _b_1933;
};
static kk_box_t kk_handlers__mlift1699_advance_fun2413(kk_function_t _fself, kk_integer_t _b_1936, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift1699_advance_fun2413(kk_box_t _b_1933, kk_context_t* _ctx) {
  struct kk_handlers__mlift1699_advance_fun2413__t* _self = kk_function_alloc_as(struct kk_handlers__mlift1699_advance_fun2413__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift1699_advance_fun2413, kk_context());
  _self->_b_1933 = _b_1933;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift1699_advance_fun2413(kk_function_t _fself, kk_integer_t _b_1936, kk_context_t* _ctx) {
  struct kk_handlers__mlift1699_advance_fun2413__t* _self = kk_function_as(struct kk_handlers__mlift1699_advance_fun2413__t*, _fself);
  kk_box_t _b_1933 = _self->_b_1933; /* 1 */
  kk_drop_match(_self, {kk_box_dup(_b_1933);}, {}, _ctx)
  kk_function_t _x2414 = kk_function_unbox(_b_1933); /*(1934) -> <effects-and-types/yield|215> 1935*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x2414, (_x2414, kk_integer_box(_b_1936), _ctx));
}
static kk_box_t kk_handlers__mlift1699_advance_fun2412(kk_function_t _fself, kk_box_t _b_1933, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return kk_handlers__mlift1698_advance(kk_handlers__new_mlift1699_advance_fun2413(_b_1933, _ctx), _ctx);
}

kk_box_t kk_handlers__mlift1699_advance(kk_function_t resume, size_t _y_5, kk_context_t* _ctx) { /* forall<a,e> (resume : (()) -> e ((int) -> <effects-and-types/yield|e> a), std/core/hnd/ev-index) -> <effects-and-types/yield|e> a */ 
  kk_function_t x_1720;
  kk_evv_t w0 = kk_std_core_hnd_evv_swap_delete(_y_5, false, _ctx); /*std/core/hnd/evv<std/core/hnd/_e2>*/;
  kk_function_t x0 = kk_function_call(kk_function_t, (kk_function_t, kk_unit_t, kk_context_t*), resume, (resume, kk_Unit, _ctx)); /*(int) -> <effects-and-types/yield|215> 214*/;
  kk_unit_t __w_l641_c9 = kk_Unit;
  kk_evv_set(w0,kk_context());
  if (kk_yielding(kk_context())) {
    kk_function_drop(x0, _ctx);
    kk_function_t _bv_1920;
    kk_box_t _x2394 = kk_std_core_hnd_yield_cont(kk_handlers__new_mlift1699_advance_fun2395(_y_5, _ctx), _ctx); /*3*/
    _bv_1920 = kk_function_unbox(_x2394); /*(1918) -> <.Box|.Box> 1919*/
    x_1720 = kk_handlers__new_mlift1699_advance_fun2411(_bv_1920, _ctx); /*(int) -> <effects-and-types/yield|215> 214*/
  }
  else {
    x_1720 = x0; /*(int) -> <effects-and-types/yield|215> 214*/
  }
  if (kk_yielding(kk_context())) {
    kk_function_drop(x_1720, _ctx);
    return kk_std_core_hnd_yield_extend(kk_handlers__new_mlift1699_advance_fun2412(_ctx), _ctx);
  }
  return kk_handlers__mlift1698_advance(x_1720, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_handlers__mlift1700_advance_fun2416__t {
  struct kk_function_s _base;
  kk_function_t resume;
};
static kk_box_t kk_handlers__mlift1700_advance_fun2416(kk_function_t _fself, kk_box_t _b_1940, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift1700_advance_fun2416(kk_function_t resume, kk_context_t* _ctx) {
  struct kk_handlers__mlift1700_advance_fun2416__t* _self = kk_function_alloc_as(struct kk_handlers__mlift1700_advance_fun2416__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift1700_advance_fun2416, kk_context());
  _self->resume = resume;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift1700_advance_fun2416(kk_function_t _fself, kk_box_t _b_1940, kk_context_t* _ctx) {
  struct kk_handlers__mlift1700_advance_fun2416__t* _self = kk_function_as(struct kk_handlers__mlift1700_advance_fun2416__t*, _fself);
  kk_function_t resume = _self->resume; /* (()) -> 215 ((int) -> <effects-and-types/yield|215> 214) */
  kk_drop_match(_self, {kk_function_dup(resume);}, {}, _ctx)
  size_t _x2417 = kk_size_unbox(_b_1940, _ctx); /*std/core/hnd/ev-index*/
  return kk_handlers__mlift1699_advance(resume, _x2417, _ctx);
}

kk_box_t kk_handlers__mlift1700_advance(kk_function_t resume, kk_unit_t wild__, kk_context_t* _ctx) { /* forall<a,e> (resume : (()) -> e ((int) -> <effects-and-types/yield|e> a), wild_ : ()) -> <effects-and-types/yield|e> a */ 
  size_t x_1725;
  kk_std_core_hnd__htag _x2415 = kk_std_core_hnd__htag_dup(kk_effects_dash_and_dash_types__tag_yield); /*std/core/hnd/htag<effects-and-types/.hnd-yield>*/
  x_1725 = kk_std_core_hnd__evv_index(_x2415, _ctx); /*std/core/hnd/ev-index*/
  if (kk_yielding(kk_context())) {
    return kk_std_core_hnd_yield_extend(kk_handlers__new_mlift1700_advance_fun2416(resume, _ctx), _ctx);
  }
  return kk_handlers__mlift1699_advance(resume, x_1725, _ctx);
}


// lift anonymous function
struct kk_handlers_advance_fun2419__t {
  struct kk_function_s _base;
};
static kk_box_t kk_handlers_advance_fun2419(kk_function_t _fself, kk_function_t _b_1971, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_advance_fun2419(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_handlers_advance_fun2419, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_handlers_advance_fun2421__t {
  struct kk_function_s _base;
  kk_function_t _b_1971;
};
static kk_function_t kk_handlers_advance_fun2421(kk_function_t _fself, kk_unit_t _b_1972, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_advance_fun2421(kk_function_t _b_1971, kk_context_t* _ctx) {
  struct kk_handlers_advance_fun2421__t* _self = kk_function_alloc_as(struct kk_handlers_advance_fun2421__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_advance_fun2421, kk_context());
  _self->_b_1971 = _b_1971;
  return &_self->_base;
}



// lift anonymous function
struct kk_handlers_advance_fun2423__t {
  struct kk_function_s _base;
  kk_function_t _bv_1975;
};
static kk_box_t kk_handlers_advance_fun2423(kk_function_t _fself, kk_integer_t _b_1976, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_advance_fun2423(kk_function_t _bv_1975, kk_context_t* _ctx) {
  struct kk_handlers_advance_fun2423__t* _self = kk_function_alloc_as(struct kk_handlers_advance_fun2423__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_advance_fun2423, kk_context());
  _self->_bv_1975 = _bv_1975;
  return &_self->_base;
}

static kk_box_t kk_handlers_advance_fun2423(kk_function_t _fself, kk_integer_t _b_1976, kk_context_t* _ctx) {
  struct kk_handlers_advance_fun2423__t* _self = kk_function_as(struct kk_handlers_advance_fun2423__t*, _fself);
  kk_function_t _bv_1975 = _self->_bv_1975; /* (1973) -> <effects-and-types/yield|215> 1974 */
  kk_drop_match(_self, {kk_function_dup(_bv_1975);}, {}, _ctx)
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _bv_1975, (_bv_1975, kk_integer_box(_b_1976), _ctx));
}
static kk_function_t kk_handlers_advance_fun2421(kk_function_t _fself, kk_unit_t _b_1972, kk_context_t* _ctx) {
  struct kk_handlers_advance_fun2421__t* _self = kk_function_as(struct kk_handlers_advance_fun2421__t*, _fself);
  kk_function_t _b_1971 = _self->_b_1971; /* (1) -> 2 4 */
  kk_drop_match(_self, {kk_function_dup(_b_1971);}, {}, _ctx)
  kk_function_t _bv_1975;
  kk_box_t _x2422 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _b_1971, (_b_1971, kk_unit_box(_b_1972), _ctx)); /*4*/
  _bv_1975 = kk_function_unbox(_x2422); /*(1973) -> <effects-and-types/yield|215> 1974*/
  return kk_handlers_new_advance_fun2423(_bv_1975, _ctx);
}


// lift anonymous function
struct kk_handlers_advance_fun2424__t {
  struct kk_function_s _base;
  kk_function_t resume_1999;
};
static kk_box_t kk_handlers_advance_fun2424(kk_function_t _fself, kk_integer_t a, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_advance_fun2424(kk_function_t resume_1999, kk_context_t* _ctx) {
  struct kk_handlers_advance_fun2424__t* _self = kk_function_alloc_as(struct kk_handlers_advance_fun2424__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_advance_fun2424, kk_context());
  _self->resume_1999 = resume_1999;
  return &_self->_base;
}



// lift anonymous function
struct kk_handlers_advance_fun2427__t {
  struct kk_function_s _base;
  kk_integer_t a;
  kk_function_t resume_1999;
};
static kk_box_t kk_handlers_advance_fun2427(kk_function_t _fself, kk_box_t _b_1944, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_advance_fun2427(kk_integer_t a, kk_function_t resume_1999, kk_context_t* _ctx) {
  struct kk_handlers_advance_fun2427__t* _self = kk_function_alloc_as(struct kk_handlers_advance_fun2427__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_advance_fun2427, kk_context());
  _self->a = a;
  _self->resume_1999 = resume_1999;
  return &_self->_base;
}

static kk_box_t kk_handlers_advance_fun2427(kk_function_t _fself, kk_box_t _b_1944, kk_context_t* _ctx) {
  struct kk_handlers_advance_fun2427__t* _self = kk_function_as(struct kk_handlers_advance_fun2427__t*, _fself);
  kk_integer_t a = _self->a; /* int */
  kk_function_t resume_1999 = _self->resume_1999; /* (()) -> 215 ((int) -> <effects-and-types/yield|215> 214) */
  kk_drop_match(_self, {kk_integer_dup(a);kk_function_dup(resume_1999);}, {}, _ctx)
  size_t _x2428 = kk_size_unbox(_b_1944, _ctx); /*std/core/hnd/ev-index*/
  return kk_handlers__mlift1697_advance(a, resume_1999, _x2428, _ctx);
}


// lift anonymous function
struct kk_handlers_advance_fun2436__t {
  struct kk_function_s _base;
  size_t i_1731;
};
static kk_box_t kk_handlers_advance_fun2436(kk_function_t _fself, kk_function_t _b_1958, kk_box_t _b_1959, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_advance_fun2436(size_t i_1731, kk_context_t* _ctx) {
  struct kk_handlers_advance_fun2436__t* _self = kk_function_alloc_as(struct kk_handlers_advance_fun2436__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_advance_fun2436, kk_context());
  _self->i_1731 = i_1731;
  return &_self->_base;
}

static kk_box_t kk_handlers_advance_fun2436(kk_function_t _fself, kk_function_t _b_1958, kk_box_t _b_1959, kk_context_t* _ctx) {
  struct kk_handlers_advance_fun2436__t* _self = kk_function_as(struct kk_handlers_advance_fun2436__t*, _fself);
  size_t i_1731 = _self->i_1731; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_1731, _b_1958, _b_1959, _ctx);
}


// lift anonymous function
struct kk_handlers_advance_fun2437__t {
  struct kk_function_s _base;
  kk_function_t resume_1999;
};
static kk_box_t kk_handlers_advance_fun2437(kk_function_t _fself, kk_box_t _b_1969, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_advance_fun2437(kk_function_t resume_1999, kk_context_t* _ctx) {
  struct kk_handlers_advance_fun2437__t* _self = kk_function_alloc_as(struct kk_handlers_advance_fun2437__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_advance_fun2437, kk_context());
  _self->resume_1999 = resume_1999;
  return &_self->_base;
}

static kk_box_t kk_handlers_advance_fun2437(kk_function_t _fself, kk_box_t _b_1969, kk_context_t* _ctx) {
  struct kk_handlers_advance_fun2437__t* _self = kk_function_as(struct kk_handlers_advance_fun2437__t*, _fself);
  kk_function_t resume_1999 = _self->resume_1999; /* (()) -> 215 ((int) -> <effects-and-types/yield|215> 214) */
  kk_drop_match(_self, {kk_function_dup(resume_1999);}, {}, _ctx)
  kk_unit_t _x2438 = kk_Unit;
  kk_unit_unbox(_b_1969);
  return kk_handlers__mlift1700_advance(resume_1999, _x2438, _ctx);
}
static kk_box_t kk_handlers_advance_fun2424(kk_function_t _fself, kk_integer_t a, kk_context_t* _ctx) {
  struct kk_handlers_advance_fun2424__t* _self = kk_function_as(struct kk_handlers_advance_fun2424__t*, _fself);
  kk_function_t resume_1999 = _self->resume_1999; /* (()) -> 215 ((int) -> <effects-and-types/yield|215> 214) */
  kk_drop_match(_self, {kk_function_dup(resume_1999);}, {}, _ctx)
  bool _match_2362;
  kk_integer_t _x2425 = kk_integer_dup(a); /*int*/
  _match_2362 = kk_integer_gt(_x2425,(kk_integer_from_small(0)),kk_context()); /*bool*/
  if (_match_2362) {
    size_t x_1727;
    kk_std_core_hnd__htag _x2426 = kk_std_core_hnd__htag_dup(kk_effects_dash_and_dash_types__tag_yield); /*std/core/hnd/htag<effects-and-types/.hnd-yield>*/
    x_1727 = kk_std_core_hnd__evv_index(_x2426, _ctx); /*std/core/hnd/ev-index*/
    if (kk_yielding(kk_context())) {
      return kk_std_core_hnd_yield_extend(kk_handlers_new_advance_fun2427(a, resume_1999, _ctx), _ctx);
    }
    return kk_handlers__mlift1697_advance(a, resume_1999, x_1727, _ctx);
  }
  kk_integer_drop(a, _ctx);
  kk_unit_t x0_1729 = kk_Unit;
  size_t i_1731;
  kk_std_core_hnd__htag _x2429 = kk_std_core_hnd__htag_dup(kk_effects_dash_and_dash_types__tag_yield); /*std/core/hnd/htag<effects-and-types/.hnd-yield>*/
  i_1731 = kk_std_core_hnd__evv_index(_x2429, _ctx); /*std/core/hnd/ev-index*/
  kk_evv_t w = kk_evv_swap_create1(i_1731,kk_context()); /*std/core/hnd/evv<<effects-and-types/yield|215>>*/;
  kk_unit_t y = kk_Unit;
  kk_std_core_hnd__ev ev_394;
  size_t _x2430 = ((size_t)0); /*size_t*/
  ev_394 = kk_evv_at(_x2430,kk_context()); /*std/core/hnd/ev<effects-and-types/.hnd-yield>*/
  kk_box_t _x2431;
  struct kk_std_core_hnd_Ev* _con2432 = kk_std_core_hnd__as_Ev(ev_394);
  kk_std_core_hnd__marker m = _con2432->marker;
  kk_box_t _box_x1945 = _con2432->hnd;
  kk_effects_dash_and_dash_types__hnd_yield h = kk_effects_dash_and_dash_types__hnd_yield_unbox(_box_x1945, NULL);
  kk_effects_dash_and_dash_types__hnd_yield_dup(h);
  kk_std_core_hnd__clause0 _match_2365;
  struct kk_effects_dash_and_dash_types__Hnd_yield* _con2434 = kk_effects_dash_and_dash_types__as_Hnd_yield(h);
  kk_std_core_hnd__clause0 control_yield = _con2434->control_yield;
  if (kk_effects_dash_and_dash_types__hnd_yield_is_unique(h)) {
    kk_effects_dash_and_dash_types__hnd_yield_free(h);
  }
  else {
    kk_std_core_hnd__clause0_dup(control_yield);
    kk_effects_dash_and_dash_types__hnd_yield_decref(h, _ctx);
  }
  _match_2365 = control_yield; /*std/core/hnd/clause0<(),effects-and-types/.hnd-yield,6,7>*/
  kk_function_t _fun_unbox_x1948 = _match_2365.clause;
  _x2431 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x1948, (_fun_unbox_x1948, m, ev_394, _ctx)); /*6*/
  kk_unit_unbox(_x2431);
  kk_unit_t __w_l679_c9 = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x2435 = kk_std_core_hnd_yield_cont(kk_handlers_new_advance_fun2436(i_1731, _ctx), _ctx); /*3*/
    kk_unit_unbox(_x2435);
  }
  else {
    y;
  }
  if (kk_yielding(kk_context())) {
    return kk_std_core_hnd_yield_extend(kk_handlers_new_advance_fun2437(resume_1999, _ctx), _ctx);
  }
  return kk_handlers__mlift1700_advance(resume_1999, x0_1729, _ctx);
}


// lift anonymous function
struct kk_handlers_advance_fun2439__t {
  struct kk_function_s _base;
  kk_function_t _bv_1979;
};
static kk_box_t kk_handlers_advance_fun2439(kk_function_t _fself, kk_box_t _b_1980, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_advance_fun2439(kk_function_t _bv_1979, kk_context_t* _ctx) {
  struct kk_handlers_advance_fun2439__t* _self = kk_function_alloc_as(struct kk_handlers_advance_fun2439__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_advance_fun2439, kk_context());
  _self->_bv_1979 = _bv_1979;
  return &_self->_base;
}

static kk_box_t kk_handlers_advance_fun2439(kk_function_t _fself, kk_box_t _b_1980, kk_context_t* _ctx) {
  struct kk_handlers_advance_fun2439__t* _self = kk_function_as(struct kk_handlers_advance_fun2439__t*, _fself);
  kk_function_t _bv_1979 = _self->_bv_1979; /* (a : int) -> <effects-and-types/yield|215> 214 */
  kk_drop_match(_self, {kk_function_dup(_bv_1979);}, {}, _ctx)
  kk_integer_t _x2440 = kk_integer_unbox(_b_1980); /*int*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_context_t*), _bv_1979, (_bv_1979, _x2440, _ctx));
}
static kk_box_t kk_handlers_advance_fun2419(kk_function_t _fself, kk_function_t _b_1971, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_function_t _x2420;
  kk_function_t _bv_1979;
  kk_function_t resume_1999 = kk_handlers_new_advance_fun2421(_b_1971, _ctx); /*(()) -> 215 ((int) -> <effects-and-types/yield|215> 214)*/;
  _bv_1979 = kk_handlers_new_advance_fun2424(resume_1999, _ctx); /*(a : int) -> <effects-and-types/yield|215> 214*/
  _x2420 = kk_handlers_new_advance_fun2439(_bv_1979, _ctx); /*(1977) -> <effects-and-types/yield|215> 214*/
  return kk_function_box(_x2420);
}


// lift anonymous function
struct kk_handlers_advance_fun2442__t {
  struct kk_function_s _base;
};
static kk_box_t kk_handlers_advance_fun2442(kk_function_t _fself, kk_box_t _b_1985, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_advance_fun2442(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_handlers_advance_fun2442, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_handlers_advance_fun2444__t {
  struct kk_function_s _base;
  kk_box_t _b_1985;
};
static kk_box_t kk_handlers_advance_fun2444(kk_function_t _fself, kk_integer_t ___wildcard__67__21, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_advance_fun2444(kk_box_t _b_1985, kk_context_t* _ctx) {
  struct kk_handlers_advance_fun2444__t* _self = kk_function_alloc_as(struct kk_handlers_advance_fun2444__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_advance_fun2444, kk_context());
  _self->_b_1985 = _b_1985;
  return &_self->_base;
}

static kk_box_t kk_handlers_advance_fun2444(kk_function_t _fself, kk_integer_t ___wildcard__67__21, kk_context_t* _ctx) {
  struct kk_handlers_advance_fun2444__t* _self = kk_function_as(struct kk_handlers_advance_fun2444__t*, _fself);
  kk_box_t _b_1985 = _self->_b_1985; /* 266 */
  kk_drop_match(_self, {kk_box_dup(_b_1985);}, {}, _ctx)
  kk_integer_drop(___wildcard__67__21, _ctx);
  return _b_1985;
}


// lift anonymous function
struct kk_handlers_advance_fun2445__t {
  struct kk_function_s _base;
  kk_function_t _bv_1988;
};
static kk_box_t kk_handlers_advance_fun2445(kk_function_t _fself, kk_box_t _b_1989, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_advance_fun2445(kk_function_t _bv_1988, kk_context_t* _ctx) {
  struct kk_handlers_advance_fun2445__t* _self = kk_function_alloc_as(struct kk_handlers_advance_fun2445__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_advance_fun2445, kk_context());
  _self->_bv_1988 = _bv_1988;
  return &_self->_base;
}

static kk_box_t kk_handlers_advance_fun2445(kk_function_t _fself, kk_box_t _b_1989, kk_context_t* _ctx) {
  struct kk_handlers_advance_fun2445__t* _self = kk_function_as(struct kk_handlers_advance_fun2445__t*, _fself);
  kk_function_t _bv_1988 = _self->_bv_1988; /* (int) -> <effects-and-types/yield|215> 214 */
  kk_drop_match(_self, {kk_function_dup(_bv_1988);}, {}, _ctx)
  kk_integer_t _x2446 = kk_integer_unbox(_b_1989); /*int*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_context_t*), _bv_1988, (_bv_1988, _x2446, _ctx));
}
static kk_box_t kk_handlers_advance_fun2442(kk_function_t _fself, kk_box_t _b_1985, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_function_t _x2443;
  kk_function_t _bv_1988 = kk_handlers_new_advance_fun2444(_b_1985, _ctx); /*(int) -> <effects-and-types/yield|215> 214*/;
  _x2443 = kk_handlers_new_advance_fun2445(_bv_1988, _ctx); /*(1986) -> <effects-and-types/yield|215> 214*/
  return kk_function_box(_x2443);
}


// lift anonymous function
struct kk_handlers_advance_fun2447__t {
  struct kk_function_s _base;
  kk_function_t _bv_1992;
};
static kk_box_t kk_handlers_advance_fun2447(kk_function_t _fself, kk_integer_t _b_1993, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_advance_fun2447(kk_function_t _bv_1992, kk_context_t* _ctx) {
  struct kk_handlers_advance_fun2447__t* _self = kk_function_alloc_as(struct kk_handlers_advance_fun2447__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_advance_fun2447, kk_context());
  _self->_bv_1992 = _bv_1992;
  return &_self->_base;
}

static kk_box_t kk_handlers_advance_fun2447(kk_function_t _fself, kk_integer_t _b_1993, kk_context_t* _ctx) {
  struct kk_handlers_advance_fun2447__t* _self = kk_function_as(struct kk_handlers_advance_fun2447__t*, _fself);
  kk_function_t _bv_1992 = _self->_bv_1992; /* (a : 1990) -> <effects-and-types/yield|215> 1991 */
  kk_drop_match(_self, {kk_function_dup(_bv_1992);}, {}, _ctx)
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _bv_1992, (_bv_1992, kk_integer_box(_b_1993), _ctx));
}

kk_function_t kk_handlers_advance(kk_function_t action, kk_context_t* _ctx) { /* forall<a,e> (action : () -> <effects-and-types/yield|e> a) -> e ((a : int) -> <effects-and-types/yield|e> a) */ 
  int32_t _b_1994_1981 = ((int32_t)3); /*int32*/;
  kk_effects_dash_and_dash_types__hnd_yield _b_1995_1982;
  kk_std_core_hnd__clause0 _x2418 = kk_std_core_hnd_clause_control0(kk_handlers_new_advance_fun2419(_ctx), _ctx); /*std/core/hnd/clause0<1,3,2,4>*/
  _b_1995_1982 = kk_effects_dash_and_dash_types__new_Hnd_yield(kk_reuse_null, _x2418, _ctx); /*effects-and-types/.hnd-yield<215,(a : int) -> <effects-and-types/yield|215> 214>*/
  kk_function_t _bv_1992;
  kk_box_t _x2441 = kk_effects_dash_and_dash_types__handle_yield(_b_1994_1981, _b_1995_1982, kk_handlers_new_advance_fun2442(_ctx), action, _ctx); /*268*/
  _bv_1992 = kk_function_unbox(_x2441); /*(a : 1990) -> <effects-and-types/yield|215> 1991*/
  return kk_handlers_new_advance_fun2447(_bv_1992, _ctx);
}


// lift anonymous function
struct kk_handlers_finalize_fun2450__t {
  struct kk_function_s _base;
};
static kk_box_t kk_handlers_finalize_fun2450(kk_function_t _fself, kk_std_core_hnd__marker _b_2006, kk_std_core_hnd__ev _b_2007, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_finalize_fun2450(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_handlers_finalize_fun2450, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_handlers_finalize_fun2450(kk_function_t _fself, kk_std_core_hnd__marker _b_2006, kk_std_core_hnd__ev _b_2007, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core_hnd__ev_dropn(_b_2007, ((int32_t)3), _ctx);
  return kk_unit_box(kk_Unit);
}


// lift anonymous function
struct kk_handlers_finalize_fun2451__t {
  struct kk_function_s _base;
};
static kk_box_t kk_handlers_finalize_fun2451(kk_function_t _fself, kk_box_t _x, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_finalize_fun2451(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_handlers_finalize_fun2451, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_handlers_finalize_fun2451(kk_function_t _fself, kk_box_t _x, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return _x;
}

kk_box_t kk_handlers_finalize(kk_function_t action, kk_context_t* _ctx) { /* forall<a,e> (action : () -> <effects-and-types/yield|e> a) -> e a */ 
  kk_effects_dash_and_dash_types__hnd_yield _x2448;
  kk_std_core_hnd__clause0 _x2449 = kk_std_core_hnd__new_Clause0(kk_handlers_new_finalize_fun2450(_ctx), _ctx); /*std/core/hnd/clause0<11,12,13,14>*/
  _x2448 = kk_effects_dash_and_dash_types__new_Hnd_yield(kk_reuse_null, _x2449, _ctx); /*effects-and-types/.hnd-yield<25,26>*/
  return kk_effects_dash_and_dash_types__handle_yield(((int32_t)1), _x2448, kk_handlers_new_finalize_fun2451(_ctx), action, _ctx);
}


// lift anonymous function
struct kk_handlers_random__sampler_fun2454__t {
  struct kk_function_s _base;
};
static kk_box_t kk_handlers_random__sampler_fun2454(kk_function_t _fself, kk_std_core_hnd__marker _b_2035, kk_std_core_hnd__ev _b_2036, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_random__sampler_fun2454(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_handlers_random__sampler_fun2454, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_handlers_random__sampler_fun2459__t {
  struct kk_function_s _base;
  size_t i_1735;
};
static kk_box_t kk_handlers_random__sampler_fun2459(kk_function_t _fself, kk_function_t _b_2016, kk_box_t _b_2017, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_random__sampler_fun2459(size_t i_1735, kk_context_t* _ctx) {
  struct kk_handlers_random__sampler_fun2459__t* _self = kk_function_alloc_as(struct kk_handlers_random__sampler_fun2459__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_random__sampler_fun2459, kk_context());
  _self->i_1735 = i_1735;
  return &_self->_base;
}

static kk_box_t kk_handlers_random__sampler_fun2459(kk_function_t _fself, kk_function_t _b_2016, kk_box_t _b_2017, kk_context_t* _ctx) {
  struct kk_handlers_random__sampler_fun2459__t* _self = kk_function_as(struct kk_handlers_random__sampler_fun2459__t*, _fself);
  size_t i_1735 = _self->i_1735; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_1735, _b_2016, _b_2017, _ctx);
}


// lift anonymous function
struct kk_handlers_random__sampler_fun2461__t {
  struct kk_function_s _base;
  kk_std_core_hnd__ev _b_2036;
};
static kk_box_t kk_handlers_random__sampler_fun2461(kk_function_t _fself, kk_function_t _b_2031, kk_box_t _b_2032, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_random__sampler_fun2461(kk_std_core_hnd__ev _b_2036, kk_context_t* _ctx) {
  struct kk_handlers_random__sampler_fun2461__t* _self = kk_function_alloc_as(struct kk_handlers_random__sampler_fun2461__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_random__sampler_fun2461, kk_context());
  _self->_b_2036 = _b_2036;
  return &_self->_base;
}

static kk_box_t kk_handlers_random__sampler_fun2461(kk_function_t _fself, kk_function_t _b_2031, kk_box_t _b_2032, kk_context_t* _ctx) {
  struct kk_handlers_random__sampler_fun2461__t* _self = kk_function_as(struct kk_handlers_random__sampler_fun2461__t*, _fself);
  kk_std_core_hnd__ev _b_2036 = _self->_b_2036; /* std/core/hnd/ev<12> */
  kk_drop_match(_self, {kk_std_core_hnd__ev_dup(_b_2036);}, {}, _ctx)
  return kk_std_core_hnd_under1(_b_2036, _b_2031, _b_2032, _ctx);
}
static kk_box_t kk_handlers_random__sampler_fun2454(kk_function_t _fself, kk_std_core_hnd__marker _b_2035, kk_std_core_hnd__ev _b_2036, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x2455;
  kk_evv_t w0;
  kk_std_core_hnd__ev _x2456 = kk_std_core_hnd__ev_dup(_b_2036); /*std/core/hnd/ev<12>*/
  w0 = kk_std_core_hnd_evv_swap_with(_x2456, _ctx); /*std/core/hnd/evv<std/core/hnd/_e1>*/
  double y;
  size_t i_1735;
  kk_std_core_hnd__htag _x2457 = kk_std_core_hnd__htag_dup(kk_std_num_random__tag_random); /*std/core/hnd/htag<std/num/random/.hnd-random>*/
  i_1735 = kk_std_core_hnd__evv_index(_x2457, _ctx); /*std/core/hnd/ev-index*/
  kk_evv_t w = kk_evv_swap_create1(i_1735,kk_context()); /*std/core/hnd/evv<<std/num/random/random|313>>*/;
  double y0 = kk_std_num_random_random_double(_ctx); /*double*/;
  kk_unit_t __w_l679_c9 = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x2458 = kk_std_core_hnd_yield_cont(kk_handlers_new_random__sampler_fun2459(i_1735, _ctx), _ctx); /*3*/
    y = kk_double_unbox(_x2458, _ctx); /*double*/
  }
  else {
    y = y0; /*double*/
  }
  kk_unit_t __w_l999_c9 = kk_Unit;
  kk_evv_set(w0,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x2460 = kk_std_core_hnd_yield_cont(kk_handlers_new_random__sampler_fun2461(_b_2036, _ctx), _ctx); /*3*/
    _x2455 = kk_double_unbox(_x2460, _ctx); /*double*/
  }
  else {
    kk_std_core_hnd__ev_dropn(_b_2036, ((int32_t)3), _ctx);
    _x2455 = y; /*double*/
  }
  return kk_double_box(_x2455, _ctx);
}


// lift anonymous function
struct kk_handlers_random__sampler_fun2462__t {
  struct kk_function_s _base;
};
static kk_box_t kk_handlers_random__sampler_fun2462(kk_function_t _fself, kk_box_t _x, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_random__sampler_fun2462(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_handlers_random__sampler_fun2462, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_handlers_random__sampler_fun2462(kk_function_t _fself, kk_box_t _x, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return _x;
}

kk_box_t kk_handlers_random__sampler(kk_function_t action, kk_context_t* _ctx) { /* forall<a,e> (action : () -> <effects-and-types/sample,std/num/random/random|e> a) -> <std/num/random/random|e> a */ 
  kk_effects_dash_and_dash_types__hnd_sample _x2452;
  kk_std_core_hnd__clause0 _x2453 = kk_std_core_hnd__new_Clause0(kk_handlers_new_random__sampler_fun2454(_ctx), _ctx); /*std/core/hnd/clause0<11,12,13,14>*/
  _x2452 = kk_effects_dash_and_dash_types__new_Hnd_sample(kk_reuse_null, _x2453, _ctx); /*effects-and-types/.hnd-sample<6,7>*/
  return kk_effects_dash_and_dash_types__handle_sample(((int32_t)1), _x2452, kk_handlers_new_random__sampler_fun2462(_ctx), action, _ctx);
}
 
// monadic lift

double kk_handlers__mlift1701_replayx(double rand__choice, kk_unit_t wild__0, kk_context_t* _ctx) { /* forall<h,e> (rand_choice : double, wild_0 : ()) -> <local<h>,effects-and-types/sample|e> double */ 
  return rand__choice;
}
 
// monadic lift


// lift anonymous function
struct kk_handlers__mlift1702_replayx_fun2464__t {
  struct kk_function_s _base;
  double rand__choice;
};
static kk_box_t kk_handlers__mlift1702_replayx_fun2464(kk_function_t _fself, kk_box_t _b_2056, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift1702_replayx_fun2464(double rand__choice, kk_context_t* _ctx) {
  struct kk_handlers__mlift1702_replayx_fun2464__t* _self = kk_function_alloc_as(struct kk_handlers__mlift1702_replayx_fun2464__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift1702_replayx_fun2464, kk_context());
  _self->rand__choice = rand__choice;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift1702_replayx_fun2464(kk_function_t _fself, kk_box_t _b_2056, kk_context_t* _ctx) {
  struct kk_handlers__mlift1702_replayx_fun2464__t* _self = kk_function_as(struct kk_handlers__mlift1702_replayx_fun2464__t*, _fself);
  double rand__choice = _self->rand__choice; /* double */
  kk_drop_match(_self, {;}, {}, _ctx)
  double _x2465;
  kk_unit_t _x2466 = kk_Unit;
  kk_unit_unbox(_b_2056);
  _x2465 = kk_handlers__mlift1701_replayx(rand__choice, _x2466, _ctx); /*double*/
  return kk_double_box(_x2465, _ctx);
}

double kk_handlers__mlift1702_replayx(kk_ref_t extended__trace, double rand__choice, kk_std_core__list _y_19, kk_context_t* _ctx) { /* forall<h,e> (extended_trace : local-var<h,list<double>>, rand_choice : double, list<double>) -> <local<h>,effects-and-types/sample|e> double */ 
  kk_unit_t x_1737 = kk_Unit;
  kk_std_core__list _b_2054_2052;
  kk_std_core__list ys_1740 = kk_std_core__new_Cons(kk_reuse_null, kk_double_box(rand__choice, _ctx), kk_std_core__new_Nil(_ctx), _ctx); /*list<double>*/;
  _b_2054_2052 = kk_std_core_append(_y_19, ys_1740, _ctx); /*list<double>*/
  (kk_ref_set(extended__trace,(kk_std_core__list_box(_b_2054_2052, _ctx)),kk_context()));
  if (kk_yielding(kk_context())) {
    kk_box_t _x2463 = kk_std_core_hnd_yield_extend(kk_handlers__new_mlift1702_replayx_fun2464(rand__choice, _ctx), _ctx); /*2*/
    return kk_double_unbox(_x2463, _ctx);
  }
  return kk_handlers__mlift1701_replayx(rand__choice, x_1737, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_handlers__mlift1703_replayx_fun2470__t {
  struct kk_function_s _base;
  kk_ref_t extended__trace;
  double rand__choice;
};
static kk_box_t kk_handlers__mlift1703_replayx_fun2470(kk_function_t _fself, kk_box_t _b_2062, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift1703_replayx_fun2470(kk_ref_t extended__trace, double rand__choice, kk_context_t* _ctx) {
  struct kk_handlers__mlift1703_replayx_fun2470__t* _self = kk_function_alloc_as(struct kk_handlers__mlift1703_replayx_fun2470__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift1703_replayx_fun2470, kk_context());
  _self->extended__trace = extended__trace;
  _self->rand__choice = rand__choice;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift1703_replayx_fun2470(kk_function_t _fself, kk_box_t _b_2062, kk_context_t* _ctx) {
  struct kk_handlers__mlift1703_replayx_fun2470__t* _self = kk_function_as(struct kk_handlers__mlift1703_replayx_fun2470__t*, _fself);
  kk_ref_t extended__trace = _self->extended__trace; /* local-var<1387,list<double>> */
  double rand__choice = _self->rand__choice; /* double */
  kk_drop_match(_self, {kk_ref_dup(extended__trace);;}, {}, _ctx)
  double _x2471;
  kk_std_core__list _x2472 = kk_std_core__list_unbox(_b_2062, _ctx); /*list<double>*/
  _x2471 = kk_handlers__mlift1702_replayx(extended__trace, rand__choice, _x2472, _ctx); /*double*/
  return kk_double_box(_x2471, _ctx);
}

double kk_handlers__mlift1703_replayx(kk_ref_t extended__trace, double rand__choice, kk_context_t* _ctx) { /* forall<h,e> (extended_trace : local-var<h,list<double>>, rand_choice : double) -> <effects-and-types/sample,local<h>|e> double */ 
  kk_std_core__list x_1741;
  kk_box_t _x2467;
  kk_ref_t _x2468 = kk_ref_dup(extended__trace); /*local-var<1387,list<double>>*/
  _x2467 = (kk_ref_get(_x2468,kk_context())); /*0*/
  x_1741 = kk_std_core__list_unbox(_x2467, _ctx); /*list<double>*/
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_1741, _ctx);
    kk_box_t _x2469 = kk_std_core_hnd_yield_extend(kk_handlers__new_mlift1703_replayx_fun2470(extended__trace, rand__choice, _ctx), _ctx); /*2*/
    return kk_double_unbox(_x2469, _ctx);
  }
  return kk_handlers__mlift1702_replayx(extended__trace, rand__choice, x_1741, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_handlers__mlift1704_replayx_fun2480__t {
  struct kk_function_s _base;
  size_t i_1745;
};
static kk_box_t kk_handlers__mlift1704_replayx_fun2480(kk_function_t _fself, kk_function_t _b_2078, kk_box_t _b_2079, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift1704_replayx_fun2480(size_t i_1745, kk_context_t* _ctx) {
  struct kk_handlers__mlift1704_replayx_fun2480__t* _self = kk_function_alloc_as(struct kk_handlers__mlift1704_replayx_fun2480__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift1704_replayx_fun2480, kk_context());
  _self->i_1745 = i_1745;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift1704_replayx_fun2480(kk_function_t _fself, kk_function_t _b_2078, kk_box_t _b_2079, kk_context_t* _ctx) {
  struct kk_handlers__mlift1704_replayx_fun2480__t* _self = kk_function_as(struct kk_handlers__mlift1704_replayx_fun2480__t*, _fself);
  size_t i_1745 = _self->i_1745; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_1745, _b_2078, _b_2079, _ctx);
}


// lift anonymous function
struct kk_handlers__mlift1704_replayx_fun2482__t {
  struct kk_function_s _base;
  kk_ref_t extended__trace;
};
static kk_box_t kk_handlers__mlift1704_replayx_fun2482(kk_function_t _fself, kk_box_t _b_2089, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift1704_replayx_fun2482(kk_ref_t extended__trace, kk_context_t* _ctx) {
  struct kk_handlers__mlift1704_replayx_fun2482__t* _self = kk_function_alloc_as(struct kk_handlers__mlift1704_replayx_fun2482__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift1704_replayx_fun2482, kk_context());
  _self->extended__trace = extended__trace;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift1704_replayx_fun2482(kk_function_t _fself, kk_box_t _b_2089, kk_context_t* _ctx) {
  struct kk_handlers__mlift1704_replayx_fun2482__t* _self = kk_function_as(struct kk_handlers__mlift1704_replayx_fun2482__t*, _fself);
  kk_ref_t extended__trace = _self->extended__trace; /* local-var<1387,list<double>> */
  kk_drop_match(_self, {kk_ref_dup(extended__trace);}, {}, _ctx)
  double _x2483;
  double _x2484 = kk_double_unbox(_b_2089, _ctx); /*double*/
  _x2483 = kk_handlers__mlift1703_replayx(extended__trace, _x2484, _ctx); /*double*/
  return kk_double_box(_x2483, _ctx);
}

double kk_handlers__mlift1704_replayx(kk_std_core__list _y_16, kk_ref_t extended__trace, kk_integer_t _y_17, kk_context_t* _ctx) { /* forall<h,e> (list<double>, extended_trace : local-var<h,list<double>>, int) -> <local<h>,effects-and-types/sample|e> double */ 
  kk_std_core_types__maybe _match_2354 = kk_std_core__lp__lb__rb__2_rp_(_y_16, _y_17, _ctx); /*maybe<1>*/;
  if (kk_std_core_types__is_Nothing(_match_2354)) {
    double x_1743;
    size_t i_1745;
    kk_std_core_hnd__htag _x2473 = kk_std_core_hnd__htag_dup(kk_effects_dash_and_dash_types__tag_sample); /*std/core/hnd/htag<effects-and-types/.hnd-sample>*/
    i_1745 = kk_std_core_hnd__evv_index(_x2473, _ctx); /*std/core/hnd/ev-index*/
    kk_evv_t w = kk_evv_swap_create1(i_1745,kk_context()); /*std/core/hnd/evv<<effects-and-types/sample,local<1387>|1395>>*/;
    double y;
    kk_std_core_hnd__ev ev_389;
    size_t _x2474 = ((size_t)0); /*size_t*/
    ev_389 = kk_evv_at(_x2474,kk_context()); /*std/core/hnd/ev<effects-and-types/.hnd-sample>*/
    kk_box_t _x2475;
    struct kk_std_core_hnd_Ev* _con2476 = kk_std_core_hnd__as_Ev(ev_389);
    kk_std_core_hnd__marker m = _con2476->marker;
    kk_box_t _box_x2065 = _con2476->hnd;
    kk_effects_dash_and_dash_types__hnd_sample h = kk_effects_dash_and_dash_types__hnd_sample_unbox(_box_x2065, NULL);
    kk_effects_dash_and_dash_types__hnd_sample_dup(h);
    kk_std_core_hnd__clause0 _match_2357;
    struct kk_effects_dash_and_dash_types__Hnd_sample* _con2478 = kk_effects_dash_and_dash_types__as_Hnd_sample(h);
    kk_std_core_hnd__clause0 fun_sample = _con2478->fun_sample;
    if (kk_effects_dash_and_dash_types__hnd_sample_is_unique(h)) {
      kk_effects_dash_and_dash_types__hnd_sample_free(h);
    }
    else {
      kk_std_core_hnd__clause0_dup(fun_sample);
      kk_effects_dash_and_dash_types__hnd_sample_decref(h, _ctx);
    }
    _match_2357 = fun_sample; /*std/core/hnd/clause0<double,effects-and-types/.hnd-sample,6,7>*/
    kk_function_t _fun_unbox_x2068 = _match_2357.clause;
    _x2475 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x2068, (_fun_unbox_x2068, m, ev_389, _ctx)); /*6*/
    y = kk_double_unbox(_x2475, _ctx); /*double*/
    kk_unit_t __w_l679_c9 = kk_Unit;
    kk_evv_set(w,kk_context());
    if (kk_yielding(kk_context())) {
      kk_box_t _x2479 = kk_std_core_hnd_yield_cont(kk_handlers__new_mlift1704_replayx_fun2480(i_1745, _ctx), _ctx); /*3*/
      x_1743 = kk_double_unbox(_x2479, _ctx); /*double*/
    }
    else {
      x_1743 = y; /*double*/
    }
    if (kk_yielding(kk_context())) {
      kk_box_t _x2481 = kk_std_core_hnd_yield_extend(kk_handlers__new_mlift1704_replayx_fun2482(extended__trace, _ctx), _ctx); /*2*/
      return kk_double_unbox(_x2481, _ctx);
    }
    return kk_handlers__mlift1703_replayx(extended__trace, x_1743, _ctx);
  }
  kk_box_t _box_x2090 = _match_2354._cons.Just.value;
  double random__value = kk_double_unbox(_box_x2090, NULL);
  kk_ref_drop(extended__trace, _ctx);
  return random__value;
}
 
// monadic lift


// lift anonymous function
struct kk_handlers__mlift1705_replayx_fun2488__t {
  struct kk_function_s _base;
  kk_std_core__list _y_16;
  kk_ref_t extended__trace;
};
static kk_box_t kk_handlers__mlift1705_replayx_fun2488(kk_function_t _fself, kk_box_t _b_2096, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift1705_replayx_fun2488(kk_std_core__list _y_16, kk_ref_t extended__trace, kk_context_t* _ctx) {
  struct kk_handlers__mlift1705_replayx_fun2488__t* _self = kk_function_alloc_as(struct kk_handlers__mlift1705_replayx_fun2488__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift1705_replayx_fun2488, kk_context());
  _self->_y_16 = _y_16;
  _self->extended__trace = extended__trace;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift1705_replayx_fun2488(kk_function_t _fself, kk_box_t _b_2096, kk_context_t* _ctx) {
  struct kk_handlers__mlift1705_replayx_fun2488__t* _self = kk_function_as(struct kk_handlers__mlift1705_replayx_fun2488__t*, _fself);
  kk_std_core__list _y_16 = _self->_y_16; /* list<double> */
  kk_ref_t extended__trace = _self->extended__trace; /* local-var<1387,list<double>> */
  kk_drop_match(_self, {kk_std_core__list_dup(_y_16);kk_ref_dup(extended__trace);}, {}, _ctx)
  double _x2489;
  kk_integer_t _x2490 = kk_integer_unbox(_b_2096); /*int*/
  _x2489 = kk_handlers__mlift1704_replayx(_y_16, extended__trace, _x2490, _ctx); /*double*/
  return kk_double_box(_x2489, _ctx);
}

double kk_handlers__mlift1705_replayx(kk_ref_t extended__trace, kk_ref_t index, kk_std_core__list _y_16, kk_context_t* _ctx) { /* forall<h,e> (extended_trace : local-var<h,list<double>>, index : local-var<h,int>, list<double>) -> <local<h>,effects-and-types/sample|e> double */ 
  kk_integer_t x_1747;
  kk_box_t _x2486 = (kk_ref_get(index,kk_context())); /*0*/
  x_1747 = kk_integer_unbox(_x2486); /*int*/
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_1747, _ctx);
    kk_box_t _x2487 = kk_std_core_hnd_yield_extend(kk_handlers__new_mlift1705_replayx_fun2488(_y_16, extended__trace, _ctx), _ctx); /*2*/
    return kk_double_unbox(_x2487, _ctx);
  }
  return kk_handlers__mlift1704_replayx(_y_16, extended__trace, x_1747, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_handlers__mlift1706_replayx_fun2494__t {
  struct kk_function_s _base;
  kk_ref_t extended__trace;
  kk_ref_t index;
};
static kk_box_t kk_handlers__mlift1706_replayx_fun2494(kk_function_t _fself, kk_box_t _b_2102, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift1706_replayx_fun2494(kk_ref_t extended__trace, kk_ref_t index, kk_context_t* _ctx) {
  struct kk_handlers__mlift1706_replayx_fun2494__t* _self = kk_function_alloc_as(struct kk_handlers__mlift1706_replayx_fun2494__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift1706_replayx_fun2494, kk_context());
  _self->extended__trace = extended__trace;
  _self->index = index;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift1706_replayx_fun2494(kk_function_t _fself, kk_box_t _b_2102, kk_context_t* _ctx) {
  struct kk_handlers__mlift1706_replayx_fun2494__t* _self = kk_function_as(struct kk_handlers__mlift1706_replayx_fun2494__t*, _fself);
  kk_ref_t extended__trace = _self->extended__trace; /* local-var<1387,list<double>> */
  kk_ref_t index = _self->index; /* local-var<1387,int> */
  kk_drop_match(_self, {kk_ref_dup(extended__trace);kk_ref_dup(index);}, {}, _ctx)
  double _x2495;
  kk_std_core__list _x2496 = kk_std_core__list_unbox(_b_2102, _ctx); /*list<double>*/
  _x2495 = kk_handlers__mlift1705_replayx(extended__trace, index, _x2496, _ctx); /*double*/
  return kk_double_box(_x2495, _ctx);
}

double kk_handlers__mlift1706_replayx(kk_ref_t extended__trace, kk_ref_t index, kk_unit_t wild__, kk_context_t* _ctx) { /* forall<h,e> (extended_trace : local-var<h,list<double>>, index : local-var<h,int>, wild_ : ()) -> <local<h>,effects-and-types/sample|e> double */ 
  kk_std_core__list x_1749;
  kk_box_t _x2491;
  kk_ref_t _x2492 = kk_ref_dup(extended__trace); /*local-var<1387,list<double>>*/
  _x2491 = (kk_ref_get(_x2492,kk_context())); /*0*/
  x_1749 = kk_std_core__list_unbox(_x2491, _ctx); /*list<double>*/
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_1749, _ctx);
    kk_box_t _x2493 = kk_std_core_hnd_yield_extend(kk_handlers__new_mlift1706_replayx_fun2494(extended__trace, index, _ctx), _ctx); /*2*/
    return kk_double_unbox(_x2493, _ctx);
  }
  return kk_handlers__mlift1705_replayx(extended__trace, index, x_1749, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_handlers__mlift1707_replayx_fun2499__t {
  struct kk_function_s _base;
  kk_ref_t extended__trace;
  kk_ref_t index;
};
static kk_box_t kk_handlers__mlift1707_replayx_fun2499(kk_function_t _fself, kk_box_t _b_2110, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift1707_replayx_fun2499(kk_ref_t extended__trace, kk_ref_t index, kk_context_t* _ctx) {
  struct kk_handlers__mlift1707_replayx_fun2499__t* _self = kk_function_alloc_as(struct kk_handlers__mlift1707_replayx_fun2499__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift1707_replayx_fun2499, kk_context());
  _self->extended__trace = extended__trace;
  _self->index = index;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift1707_replayx_fun2499(kk_function_t _fself, kk_box_t _b_2110, kk_context_t* _ctx) {
  struct kk_handlers__mlift1707_replayx_fun2499__t* _self = kk_function_as(struct kk_handlers__mlift1707_replayx_fun2499__t*, _fself);
  kk_ref_t extended__trace = _self->extended__trace; /* local-var<1387,list<double>> */
  kk_ref_t index = _self->index; /* local-var<1387,int> */
  kk_drop_match(_self, {kk_ref_dup(extended__trace);kk_ref_dup(index);}, {}, _ctx)
  double _x2500;
  kk_unit_t _x2501 = kk_Unit;
  kk_unit_unbox(_b_2110);
  _x2500 = kk_handlers__mlift1706_replayx(extended__trace, index, _x2501, _ctx); /*double*/
  return kk_double_box(_x2500, _ctx);
}

double kk_handlers__mlift1707_replayx(kk_ref_t extended__trace, kk_ref_t index, kk_integer_t _y_14, kk_context_t* _ctx) { /* forall<h,e> (extended_trace : local-var<h,list<double>>, index : local-var<h,int>, int) -> <local<h>,effects-and-types/sample|e> double */ 
  kk_unit_t x_1751 = kk_Unit;
  kk_integer_t _b_2108_2106 = kk_integer_add(_y_14,(kk_integer_from_small(1)),kk_context()); /*int*/;
  kk_ref_t _x2497 = kk_ref_dup(index); /*local-var<1387,int>*/
  (kk_ref_set(_x2497,(kk_integer_box(_b_2108_2106)),kk_context()));
  if (kk_yielding(kk_context())) {
    kk_box_t _x2498 = kk_std_core_hnd_yield_extend(kk_handlers__new_mlift1707_replayx_fun2499(extended__trace, index, _ctx), _ctx); /*2*/
    return kk_double_unbox(_x2498, _ctx);
  }
  return kk_handlers__mlift1706_replayx(extended__trace, index, x_1751, _ctx);
}
 
// monadic lift

kk_std_core_types__tuple2_ kk_handlers__mlift1708_replayx(kk_std_core__list _y_22, kk_box_t x, kk_integer_t _y_23, kk_context_t* _ctx) { /* forall<h,a,e> (list<double>, x : a, int) -> <local<h>,effects-and-types/sample|e> (list<double>, a) */ 
  kk_std_core__list _b_2121_2119;
  kk_std_core_types__tuple2_ _this_1753;
  kk_integer_t n_1755 = kk_integer_add(_y_23,(kk_integer_from_small(1)),kk_context()); /*int*/;
  kk_std_core__list _b_2115_2113;
  kk_std_core__list _x2502 = kk_std_core__list_dup(_y_22); /*list<double>*/
  kk_integer_t _x2503 = kk_integer_dup(n_1755); /*int*/
  _b_2115_2113 = kk_std_core_take(_x2502, _x2503, _ctx); /*list<double>*/
  kk_std_core__list _b_2116_2114 = kk_std_core_drop(_y_22, n_1755, _ctx); /*list<double>*/;
  _this_1753 = kk_std_core_types__new_dash__lp__comma__rp_(kk_std_core__list_box(_b_2115_2113, _ctx), kk_std_core__list_box(_b_2116_2114, _ctx), _ctx); /*(list<double>, list<double>)*/
  kk_box_t _box_x2117 = _this_1753.fst;
  kk_box_t _box_x2118 = _this_1753.snd;
  kk_std_core__list _x = kk_std_core__list_unbox(_box_x2117, NULL);
  kk_std_core__list_dup(_x);
  kk_std_core_types__tuple2__drop(_this_1753, _ctx);
  _b_2121_2119 = _x; /*list<double>*/
  return kk_std_core_types__new_dash__lp__comma__rp_(kk_std_core__list_box(_b_2121_2119, _ctx), x, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_handlers__mlift1709_replayx_fun2508__t {
  struct kk_function_s _base;
  kk_std_core__list _y_22;
  kk_box_t x;
};
static kk_box_t kk_handlers__mlift1709_replayx_fun2508(kk_function_t _fself, kk_box_t _b_2126, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift1709_replayx_fun2508(kk_std_core__list _y_22, kk_box_t x, kk_context_t* _ctx) {
  struct kk_handlers__mlift1709_replayx_fun2508__t* _self = kk_function_alloc_as(struct kk_handlers__mlift1709_replayx_fun2508__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift1709_replayx_fun2508, kk_context());
  _self->_y_22 = _y_22;
  _self->x = x;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift1709_replayx_fun2508(kk_function_t _fself, kk_box_t _b_2126, kk_context_t* _ctx) {
  struct kk_handlers__mlift1709_replayx_fun2508__t* _self = kk_function_as(struct kk_handlers__mlift1709_replayx_fun2508__t*, _fself);
  kk_std_core__list _y_22 = _self->_y_22; /* list<double> */
  kk_box_t x = _self->x; /* 1394 */
  kk_drop_match(_self, {kk_std_core__list_dup(_y_22);kk_box_dup(x);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x2509;
  kk_integer_t _x2510 = kk_integer_unbox(_b_2126); /*int*/
  _x2509 = kk_handlers__mlift1708_replayx(_y_22, x, _x2510, _ctx); /*(list<double>, 1394)*/
  return kk_std_core_types__tuple2__box(_x2509, _ctx);
}

kk_std_core_types__tuple2_ kk_handlers__mlift1709_replayx(kk_ref_t index, kk_box_t x, kk_std_core__list _y_22, kk_context_t* _ctx) { /* forall<h,a,e> (index : local-var<h,int>, x : a, list<double>) -> <local<h>,effects-and-types/sample|e> (list<double>, a) */ 
  kk_integer_t x0_1756;
  kk_box_t _x2506 = (kk_ref_get(index,kk_context())); /*0*/
  x0_1756 = kk_integer_unbox(_x2506); /*int*/
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x0_1756, _ctx);
    kk_box_t _x2507 = kk_std_core_hnd_yield_extend(kk_handlers__new_mlift1709_replayx_fun2508(_y_22, x, _ctx), _ctx); /*2*/
    return kk_std_core_types__tuple2__unbox(_x2507, _ctx);
  }
  return kk_handlers__mlift1708_replayx(_y_22, x, x0_1756, _ctx);
}


// lift anonymous function
struct kk_handlers_replayx_fun2513__t {
  struct kk_function_s _base;
  kk_ref_t loc;
  kk_ref_t loc0;
};
static kk_box_t kk_handlers_replayx_fun2513(kk_function_t _fself, kk_std_core_hnd__marker _b_2148, kk_std_core_hnd__ev _b_2149, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_replayx_fun2513(kk_ref_t loc, kk_ref_t loc0, kk_context_t* _ctx) {
  struct kk_handlers_replayx_fun2513__t* _self = kk_function_alloc_as(struct kk_handlers_replayx_fun2513__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_replayx_fun2513, kk_context());
  _self->loc = loc;
  _self->loc0 = loc0;
  return &_self->_base;
}



// lift anonymous function
struct kk_handlers_replayx_fun2519__t {
  struct kk_function_s _base;
  kk_ref_t loc;
  kk_ref_t loc0;
};
static kk_box_t kk_handlers_replayx_fun2519(kk_function_t _fself, kk_box_t _b_2136, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_replayx_fun2519(kk_ref_t loc, kk_ref_t loc0, kk_context_t* _ctx) {
  struct kk_handlers_replayx_fun2519__t* _self = kk_function_alloc_as(struct kk_handlers_replayx_fun2519__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_replayx_fun2519, kk_context());
  _self->loc = loc;
  _self->loc0 = loc0;
  return &_self->_base;
}

static kk_box_t kk_handlers_replayx_fun2519(kk_function_t _fself, kk_box_t _b_2136, kk_context_t* _ctx) {
  struct kk_handlers_replayx_fun2519__t* _self = kk_function_as(struct kk_handlers_replayx_fun2519__t*, _fself);
  kk_ref_t loc = _self->loc; /* local-var<global,list<double>> */
  kk_ref_t loc0 = _self->loc0; /* local-var<global,int> */
  kk_drop_match(_self, {kk_ref_dup(loc);kk_ref_dup(loc0);}, {}, _ctx)
  double _x2520;
  kk_integer_t _x2521 = kk_integer_unbox(_b_2136); /*int*/
  _x2520 = kk_handlers__mlift1707_replayx(loc, loc0, _x2521, _ctx); /*double*/
  return kk_double_box(_x2520, _ctx);
}


// lift anonymous function
struct kk_handlers_replayx_fun2523__t {
  struct kk_function_s _base;
  kk_std_core_hnd__ev _b_2149;
};
static kk_box_t kk_handlers_replayx_fun2523(kk_function_t _fself, kk_function_t _b_2144, kk_box_t _b_2145, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_replayx_fun2523(kk_std_core_hnd__ev _b_2149, kk_context_t* _ctx) {
  struct kk_handlers_replayx_fun2523__t* _self = kk_function_alloc_as(struct kk_handlers_replayx_fun2523__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_replayx_fun2523, kk_context());
  _self->_b_2149 = _b_2149;
  return &_self->_base;
}

static kk_box_t kk_handlers_replayx_fun2523(kk_function_t _fself, kk_function_t _b_2144, kk_box_t _b_2145, kk_context_t* _ctx) {
  struct kk_handlers_replayx_fun2523__t* _self = kk_function_as(struct kk_handlers_replayx_fun2523__t*, _fself);
  kk_std_core_hnd__ev _b_2149 = _self->_b_2149; /* std/core/hnd/ev<12> */
  kk_drop_match(_self, {kk_std_core_hnd__ev_dup(_b_2149);}, {}, _ctx)
  return kk_std_core_hnd_under1(_b_2149, _b_2144, _b_2145, _ctx);
}
static kk_box_t kk_handlers_replayx_fun2513(kk_function_t _fself, kk_std_core_hnd__marker _b_2148, kk_std_core_hnd__ev _b_2149, kk_context_t* _ctx) {
  struct kk_handlers_replayx_fun2513__t* _self = kk_function_as(struct kk_handlers_replayx_fun2513__t*, _fself);
  kk_ref_t loc = _self->loc; /* local-var<global,list<double>> */
  kk_ref_t loc0 = _self->loc0; /* local-var<global,int> */
  kk_drop_match(_self, {kk_ref_dup(loc);kk_ref_dup(loc0);}, {}, _ctx)
  double _x2514;
  kk_evv_t w0;
  kk_std_core_hnd__ev _x2515 = kk_std_core_hnd__ev_dup(_b_2149); /*std/core/hnd/ev<12>*/
  w0 = kk_std_core_hnd_evv_swap_with(_x2515, _ctx); /*std/core/hnd/evv<std/core/hnd/_e1>*/
  double y;
  kk_integer_t x_1766;
  kk_box_t _x2516;
  kk_ref_t _x2517 = kk_ref_dup(loc0); /*local-var<global,int>*/
  _x2516 = (kk_ref_get(_x2517,kk_context())); /*0*/
  x_1766 = kk_integer_unbox(_x2516); /*int*/
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_1766, _ctx);
    kk_box_t _x2518 = kk_std_core_hnd_yield_extend(kk_handlers_new_replayx_fun2519(loc, loc0, _ctx), _ctx); /*2*/
    y = kk_double_unbox(_x2518, _ctx); /*double*/
  }
  else {
    y = kk_handlers__mlift1707_replayx(loc, loc0, x_1766, _ctx); /*double*/
  }
  kk_unit_t __w_l999_c9 = kk_Unit;
  kk_evv_set(w0,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x2522 = kk_std_core_hnd_yield_cont(kk_handlers_new_replayx_fun2523(_b_2149, _ctx), _ctx); /*3*/
    _x2514 = kk_double_unbox(_x2522, _ctx); /*double*/
  }
  else {
    kk_std_core_hnd__ev_dropn(_b_2149, ((int32_t)3), _ctx);
    _x2514 = y; /*double*/
  }
  return kk_double_box(_x2514, _ctx);
}


// lift anonymous function
struct kk_handlers_replayx_fun2526__t {
  struct kk_function_s _base;
  kk_ref_t loc;
  kk_ref_t loc0;
};
static kk_box_t kk_handlers_replayx_fun2526(kk_function_t _fself, kk_box_t _b_2158, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_replayx_fun2526(kk_ref_t loc, kk_ref_t loc0, kk_context_t* _ctx) {
  struct kk_handlers_replayx_fun2526__t* _self = kk_function_alloc_as(struct kk_handlers_replayx_fun2526__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_replayx_fun2526, kk_context());
  _self->loc = loc;
  _self->loc0 = loc0;
  return &_self->_base;
}



// lift anonymous function
struct kk_handlers_replayx_fun2530__t {
  struct kk_function_s _base;
  kk_box_t _b_2158;
  kk_ref_t loc0;
};
static kk_box_t kk_handlers_replayx_fun2530(kk_function_t _fself, kk_box_t _b_2153, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_replayx_fun2530(kk_box_t _b_2158, kk_ref_t loc0, kk_context_t* _ctx) {
  struct kk_handlers_replayx_fun2530__t* _self = kk_function_alloc_as(struct kk_handlers_replayx_fun2530__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_replayx_fun2530, kk_context());
  _self->_b_2158 = _b_2158;
  _self->loc0 = loc0;
  return &_self->_base;
}

static kk_box_t kk_handlers_replayx_fun2530(kk_function_t _fself, kk_box_t _b_2153, kk_context_t* _ctx) {
  struct kk_handlers_replayx_fun2530__t* _self = kk_function_as(struct kk_handlers_replayx_fun2530__t*, _fself);
  kk_box_t _b_2158 = _self->_b_2158; /* 208 */
  kk_ref_t loc0 = _self->loc0; /* local-var<global,int> */
  kk_drop_match(_self, {kk_box_dup(_b_2158);kk_ref_dup(loc0);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x2531;
  kk_std_core__list _x2532 = kk_std_core__list_unbox(_b_2153, _ctx); /*list<double>*/
  _x2531 = kk_handlers__mlift1709_replayx(loc0, _b_2158, _x2532, _ctx); /*(list<double>, 1394)*/
  return kk_std_core_types__tuple2__box(_x2531, _ctx);
}
static kk_box_t kk_handlers_replayx_fun2526(kk_function_t _fself, kk_box_t _b_2158, kk_context_t* _ctx) {
  struct kk_handlers_replayx_fun2526__t* _self = kk_function_as(struct kk_handlers_replayx_fun2526__t*, _fself);
  kk_ref_t loc = _self->loc; /* local-var<global,list<double>> */
  kk_ref_t loc0 = _self->loc0; /* local-var<global,int> */
  kk_drop_match(_self, {kk_ref_dup(loc);kk_ref_dup(loc0);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x2527;
  kk_std_core__list x1_1768;
  kk_box_t _x2528 = (kk_ref_get(loc,kk_context())); /*0*/
  x1_1768 = kk_std_core__list_unbox(_x2528, _ctx); /*list<double>*/
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x1_1768, _ctx);
    kk_box_t _x2529 = kk_std_core_hnd_yield_extend(kk_handlers_new_replayx_fun2530(_b_2158, loc0, _ctx), _ctx); /*2*/
    _x2527 = kk_std_core_types__tuple2__unbox(_x2529, _ctx); /*(list<double>, 1394)*/
  }
  else {
    _x2527 = kk_handlers__mlift1709_replayx(loc0, _b_2158, x1_1768, _ctx); /*(list<double>, 1394)*/
  }
  return kk_std_core_types__tuple2__box(_x2527, _ctx);
}


// lift anonymous function
struct kk_handlers_replayx_fun2533__t {
  struct kk_function_s _base;
  kk_function_t action;
};
static kk_box_t kk_handlers_replayx_fun2533(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_replayx_fun2533(kk_function_t action, kk_context_t* _ctx) {
  struct kk_handlers_replayx_fun2533__t* _self = kk_function_alloc_as(struct kk_handlers_replayx_fun2533__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_replayx_fun2533, kk_context());
  _self->action = action;
  return &_self->_base;
}

static kk_box_t kk_handlers_replayx_fun2533(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_handlers_replayx_fun2533__t* _self = kk_function_as(struct kk_handlers_replayx_fun2533__t*, _fself);
  kk_function_t action = _self->action; /* () -> <effects-and-types/sample,effects-and-types/sample|1395> 1394 */
  kk_drop_match(_self, {kk_function_dup(action);}, {}, _ctx)
  return kk_std_core_hnd__mask_builtin(action, _ctx);
}

kk_std_core_types__tuple2_ kk_handlers_replayx(kk_std_core__list trace, kk_function_t action, kk_context_t* _ctx) { /* forall<a,e> (trace : effects-and-types/trace_values, action : () -> <effects-and-types/sample,effects-and-types/sample|e> a) -> <effects-and-types/sample|e> (list<double>, a) */ 
  kk_ref_t loc = kk_ref_alloc((kk_std_core__list_box(trace, _ctx)),kk_context()); /*local-var<global,list<double>>*/;
  kk_std_core_types__tuple2_ res1;
  kk_ref_t loc0 = kk_ref_alloc((kk_integer_box(kk_integer_from_small(-1))),kk_context()); /*local-var<global,int>*/;
  kk_std_core_types__tuple2_ res0;
  int32_t _b_2159_2154 = ((int32_t)1); /*int32*/;
  kk_effects_dash_and_dash_types__hnd_sample _b_2160_2155;
  kk_std_core_hnd__clause0 _x2511;
  kk_function_t _x2512;
  kk_ref_dup(loc);
  kk_ref_dup(loc0);
  _x2512 = kk_handlers_new_replayx_fun2513(loc, loc0, _ctx); /*(std/core/hnd/marker<13,14>, std/core/hnd/ev<12>) -> 13 11*/
  _x2511 = kk_std_core_hnd__new_Clause0(_x2512, _ctx); /*std/core/hnd/clause0<11,12,13,14>*/
  _b_2160_2155 = kk_effects_dash_and_dash_types__new_Hnd_sample(kk_reuse_null, _x2511, _ctx); /*effects-and-types/.hnd-sample<<local<global>,effects-and-types/sample|1395>,(list<double>, 1394)>*/
  kk_box_t _x2524;
  kk_function_t _x2525;
  kk_ref_dup(loc);
  kk_ref_dup(loc0);
  _x2525 = kk_handlers_new_replayx_fun2526(loc, loc0, _ctx); /*(208) -> 209 210*/
  _x2524 = kk_effects_dash_and_dash_types__handle_sample(_b_2159_2154, _b_2160_2155, _x2525, kk_handlers_new_replayx_fun2533(action, _ctx), _ctx); /*210*/
  res0 = kk_std_core_types__tuple2__unbox(_x2524, _ctx); /*(list<double>, 1394)*/
  kk_box_t _x2534 = kk_std_core_hnd_prompt_local_var(loc0, kk_std_core_types__tuple2__box(res0, _ctx), _ctx); /*2*/
  res1 = kk_std_core_types__tuple2__unbox(_x2534, _ctx); /*(list<double>, 1394)*/
  kk_box_t _x2535 = kk_std_core_hnd_prompt_local_var(loc, kk_std_core_types__tuple2__box(res1, _ctx), _ctx); /*2*/
  return kk_std_core_types__tuple2__unbox(_x2535, _ctx);
}
 
// monadic lift

kk_unit_t kk_handlers__mlift1710_weighted(kk_effects_dash_and_dash_types__exp s, kk_ref_t wps, kk_effects_dash_and_dash_types__exp _y_29, kk_context_t* _ctx) { /* forall<h,e> (s : effects-and-types/exp, wps : local-var<h,effects-and-types/exp>, effects-and-types/exp) -> <local<h>|e> () */ 
  kk_effects_dash_and_dash_types__exp _b_2187_2185 = kk_exponents_mult__exp(_y_29, s, _ctx); /*effects-and-types/exp*/;
  (kk_ref_set(wps,(kk_effects_dash_and_dash_types__exp_box(_b_2187_2185, _ctx)),kk_context())); return kk_Unit;
}
 
// monadic lift

kk_std_core_types__tuple2_ kk_handlers__mlift1711_weighted(kk_box_t x, kk_effects_dash_and_dash_types__exp _y_31, kk_context_t* _ctx) { /* forall<h,a,e> (x : a, effects-and-types/exp) -> <local<h>|e> (effects-and-types/exp, a) */ 
  return kk_std_core_types__new_dash__lp__comma__rp_(kk_effects_dash_and_dash_types__exp_box(_y_31, _ctx), x, _ctx);
}


// lift anonymous function
struct kk_handlers_weighted_fun2538__t {
  struct kk_function_s _base;
  kk_ref_t loc;
};
static kk_box_t kk_handlers_weighted_fun2538(kk_function_t _fself, kk_std_core_hnd__marker _b_2199, kk_std_core_hnd__ev _b_2200, kk_box_t _b_2201, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_weighted_fun2538(kk_ref_t loc, kk_context_t* _ctx) {
  struct kk_handlers_weighted_fun2538__t* _self = kk_function_alloc_as(struct kk_handlers_weighted_fun2538__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_weighted_fun2538, kk_context());
  _self->loc = loc;
  return &_self->_base;
}



// lift anonymous function
struct kk_handlers_weighted_fun2543__t {
  struct kk_function_s _base;
  kk_box_t _b_2201;
  kk_ref_t loc;
};
static kk_box_t kk_handlers_weighted_fun2543(kk_function_t _fself, kk_box_t _b_2197, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_weighted_fun2543(kk_box_t _b_2201, kk_ref_t loc, kk_context_t* _ctx) {
  struct kk_handlers_weighted_fun2543__t* _self = kk_function_alloc_as(struct kk_handlers_weighted_fun2543__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_weighted_fun2543, kk_context());
  _self->_b_2201 = _b_2201;
  _self->loc = loc;
  return &_self->_base;
}

static kk_box_t kk_handlers_weighted_fun2543(kk_function_t _fself, kk_box_t _b_2197, kk_context_t* _ctx) {
  struct kk_handlers_weighted_fun2543__t* _self = kk_function_as(struct kk_handlers_weighted_fun2543__t*, _fself);
  kk_box_t _b_2201 = _self->_b_2201; /* 16 */
  kk_ref_t loc = _self->loc; /* local-var<global,effects-and-types/exp> */
  kk_drop_match(_self, {kk_box_dup(_b_2201);kk_ref_dup(loc);}, {}, _ctx)
  kk_unit_t _x2544 = kk_Unit;
  kk_effects_dash_and_dash_types__exp _x2545 = kk_effects_dash_and_dash_types__exp_unbox(_b_2201, _ctx); /*effects-and-types/exp*/
  kk_effects_dash_and_dash_types__exp _x2546 = kk_effects_dash_and_dash_types__exp_unbox(_b_2197, _ctx); /*effects-and-types/exp*/
  kk_handlers__mlift1710_weighted(_x2545, loc, _x2546, _ctx);
  return kk_unit_box(_x2544);
}
static kk_box_t kk_handlers_weighted_fun2538(kk_function_t _fself, kk_std_core_hnd__marker _b_2199, kk_std_core_hnd__ev _b_2200, kk_box_t _b_2201, kk_context_t* _ctx) {
  struct kk_handlers_weighted_fun2538__t* _self = kk_function_as(struct kk_handlers_weighted_fun2538__t*, _fself);
  kk_ref_t loc = _self->loc; /* local-var<global,effects-and-types/exp> */
  kk_drop_match(_self, {kk_ref_dup(loc);}, {}, _ctx)
  kk_std_core_hnd__ev_dropn(_b_2200, ((int32_t)3), _ctx);
  kk_unit_t _x2539 = kk_Unit;
  kk_effects_dash_and_dash_types__exp x0_1776;
  kk_box_t _x2540;
  kk_ref_t _x2541 = kk_ref_dup(loc); /*local-var<global,effects-and-types/exp>*/
  _x2540 = (kk_ref_get(_x2541,kk_context())); /*0*/
  x0_1776 = kk_effects_dash_and_dash_types__exp_unbox(_x2540, _ctx); /*effects-and-types/exp*/
  if (kk_yielding(kk_context())) {
    kk_box_t _x2542 = kk_std_core_hnd_yield_extend(kk_handlers_new_weighted_fun2543(_b_2201, loc, _ctx), _ctx); /*2*/
    kk_unit_unbox(_x2542);
  }
  else {
    kk_effects_dash_and_dash_types__exp _x2547 = kk_effects_dash_and_dash_types__exp_unbox(_b_2201, _ctx); /*effects-and-types/exp*/
    kk_handlers__mlift1710_weighted(_x2547, loc, x0_1776, _ctx);
  }
  return kk_unit_box(_x2539);
}


// lift anonymous function
struct kk_handlers_weighted_fun2550__t {
  struct kk_function_s _base;
  kk_ref_t loc;
};
static kk_box_t kk_handlers_weighted_fun2550(kk_function_t _fself, kk_box_t _b_2210, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_weighted_fun2550(kk_ref_t loc, kk_context_t* _ctx) {
  struct kk_handlers_weighted_fun2550__t* _self = kk_function_alloc_as(struct kk_handlers_weighted_fun2550__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_weighted_fun2550, kk_context());
  _self->loc = loc;
  return &_self->_base;
}



// lift anonymous function
struct kk_handlers_weighted_fun2554__t {
  struct kk_function_s _base;
  kk_box_t _b_2210;
};
static kk_box_t kk_handlers_weighted_fun2554(kk_function_t _fself, kk_box_t _b_2205, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_weighted_fun2554(kk_box_t _b_2210, kk_context_t* _ctx) {
  struct kk_handlers_weighted_fun2554__t* _self = kk_function_alloc_as(struct kk_handlers_weighted_fun2554__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_weighted_fun2554, kk_context());
  _self->_b_2210 = _b_2210;
  return &_self->_base;
}

static kk_box_t kk_handlers_weighted_fun2554(kk_function_t _fself, kk_box_t _b_2205, kk_context_t* _ctx) {
  struct kk_handlers_weighted_fun2554__t* _self = kk_function_as(struct kk_handlers_weighted_fun2554__t*, _fself);
  kk_box_t _b_2210 = _self->_b_2210; /* 237 */
  kk_drop_match(_self, {kk_box_dup(_b_2210);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x2555;
  kk_effects_dash_and_dash_types__exp _x2556 = kk_effects_dash_and_dash_types__exp_unbox(_b_2205, _ctx); /*effects-and-types/exp*/
  _x2555 = kk_handlers__mlift1711_weighted(_b_2210, _x2556, _ctx); /*(effects-and-types/exp, 1581)*/
  return kk_std_core_types__tuple2__box(_x2555, _ctx);
}
static kk_box_t kk_handlers_weighted_fun2550(kk_function_t _fself, kk_box_t _b_2210, kk_context_t* _ctx) {
  struct kk_handlers_weighted_fun2550__t* _self = kk_function_as(struct kk_handlers_weighted_fun2550__t*, _fself);
  kk_ref_t loc = _self->loc; /* local-var<global,effects-and-types/exp> */
  kk_drop_match(_self, {kk_ref_dup(loc);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x2551;
  kk_effects_dash_and_dash_types__exp x2_1778;
  kk_box_t _x2552 = (kk_ref_get(loc,kk_context())); /*0*/
  x2_1778 = kk_effects_dash_and_dash_types__exp_unbox(_x2552, _ctx); /*effects-and-types/exp*/
  if (kk_yielding(kk_context())) {
    kk_box_t _x2553 = kk_std_core_hnd_yield_extend(kk_handlers_new_weighted_fun2554(_b_2210, _ctx), _ctx); /*2*/
    _x2551 = kk_std_core_types__tuple2__unbox(_x2553, _ctx); /*(effects-and-types/exp, 1581)*/
  }
  else {
    _x2551 = kk_handlers__mlift1711_weighted(_b_2210, x2_1778, _ctx); /*(effects-and-types/exp, 1581)*/
  }
  return kk_std_core_types__tuple2__box(_x2551, _ctx);
}


// lift anonymous function
struct kk_handlers_weighted_fun2557__t {
  struct kk_function_s _base;
  kk_function_t action;
};
static kk_box_t kk_handlers_weighted_fun2557(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_weighted_fun2557(kk_function_t action, kk_context_t* _ctx) {
  struct kk_handlers_weighted_fun2557__t* _self = kk_function_alloc_as(struct kk_handlers_weighted_fun2557__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_weighted_fun2557, kk_context());
  _self->action = action;
  return &_self->_base;
}

static kk_box_t kk_handlers_weighted_fun2557(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_handlers_weighted_fun2557__t* _self = kk_function_as(struct kk_handlers_weighted_fun2557__t*, _fself);
  kk_function_t action = _self->action; /* () -> <effects-and-types/score|1582> 1581 */
  kk_drop_match(_self, {kk_function_dup(action);}, {}, _ctx)
  return kk_std_core_hnd__mask_builtin(action, _ctx);
}

kk_std_core_types__tuple2_ kk_handlers_weighted(kk_effects_dash_and_dash_types__exp wp, kk_function_t action, kk_context_t* _ctx) { /* forall<a,e> (wp : effects-and-types/exp, action : () -> <effects-and-types/score|e> a) -> e (effects-and-types/exp, a) */ 
  kk_ref_t loc = kk_ref_alloc((kk_effects_dash_and_dash_types__exp_box(wp, _ctx)),kk_context()); /*local-var<global,effects-and-types/exp>*/;
  kk_std_core_types__tuple2_ res;
  int32_t _b_2211_2206 = ((int32_t)1); /*int32*/;
  kk_effects_dash_and_dash_types__hnd_score _b_2212_2207;
  kk_std_core_hnd__clause1 _x2536;
  kk_function_t _x2537;
  kk_ref_dup(loc);
  _x2537 = kk_handlers_new_weighted_fun2538(loc, _ctx); /*(std/core/hnd/marker<19,20>, std/core/hnd/ev<18>, 16) -> 19 17*/
  _x2536 = kk_std_core_hnd__new_Clause1(_x2537, _ctx); /*std/core/hnd/clause1<16,17,18,19,20>*/
  _b_2212_2207 = kk_effects_dash_and_dash_types__new_Hnd_score(kk_reuse_null, _x2536, _ctx); /*effects-and-types/.hnd-score<<local<global>|1582>,(effects-and-types/exp, 1581)>*/
  kk_box_t _x2548;
  kk_function_t _x2549;
  kk_ref_dup(loc);
  _x2549 = kk_handlers_new_weighted_fun2550(loc, _ctx); /*(237) -> 238 239*/
  _x2548 = kk_effects_dash_and_dash_types__handle_score(_b_2211_2206, _b_2212_2207, _x2549, kk_handlers_new_weighted_fun2557(action, _ctx), _ctx); /*239*/
  res = kk_std_core_types__tuple2__unbox(_x2548, _ctx); /*(effects-and-types/exp, 1581)*/
  kk_box_t _x2558 = kk_std_core_hnd_prompt_local_var(loc, kk_std_core_types__tuple2__box(res, _ctx), _ctx); /*2*/
  return kk_std_core_types__tuple2__unbox(_x2558, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_handlers__mlift1712_yield__on__scorex_fun2566__t {
  struct kk_function_s _base;
  size_t i_1780;
};
static kk_box_t kk_handlers__mlift1712_yield__on__scorex_fun2566(kk_function_t _fself, kk_function_t _b_2241, kk_box_t _b_2242, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift1712_yield__on__scorex_fun2566(size_t i_1780, kk_context_t* _ctx) {
  struct kk_handlers__mlift1712_yield__on__scorex_fun2566__t* _self = kk_function_alloc_as(struct kk_handlers__mlift1712_yield__on__scorex_fun2566__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift1712_yield__on__scorex_fun2566, kk_context());
  _self->i_1780 = i_1780;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift1712_yield__on__scorex_fun2566(kk_function_t _fself, kk_function_t _b_2241, kk_box_t _b_2242, kk_context_t* _ctx) {
  struct kk_handlers__mlift1712_yield__on__scorex_fun2566__t* _self = kk_function_as(struct kk_handlers__mlift1712_yield__on__scorex_fun2566__t*, _fself);
  size_t i_1780 = _self->i_1780; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_1780, _b_2241, _b_2242, _ctx);
}

kk_unit_t kk_handlers__mlift1712_yield__on__scorex(kk_unit_t wild__, kk_context_t* _ctx) { /* forall<e> (wild_ : ()) -> <effects-and-types/score,effects-and-types/yield|e> () */ 
  size_t i_1780;
  kk_std_core_hnd__htag _x2559 = kk_std_core_hnd__htag_dup(kk_effects_dash_and_dash_types__tag_yield); /*std/core/hnd/htag<effects-and-types/.hnd-yield>*/
  i_1780 = kk_std_core_hnd__evv_index(_x2559, _ctx); /*std/core/hnd/ev-index*/
  kk_evv_t w = kk_evv_swap_create1(i_1780,kk_context()); /*std/core/hnd/evv<<effects-and-types/yield,effects-and-types/score|1647>>*/;
  kk_unit_t y = kk_Unit;
  kk_std_core_hnd__ev ev_394;
  size_t _x2560 = ((size_t)0); /*size_t*/
  ev_394 = kk_evv_at(_x2560,kk_context()); /*std/core/hnd/ev<effects-and-types/.hnd-yield>*/
  kk_box_t _x2561;
  struct kk_std_core_hnd_Ev* _con2562 = kk_std_core_hnd__as_Ev(ev_394);
  kk_std_core_hnd__marker m = _con2562->marker;
  kk_box_t _box_x2228 = _con2562->hnd;
  kk_effects_dash_and_dash_types__hnd_yield h = kk_effects_dash_and_dash_types__hnd_yield_unbox(_box_x2228, NULL);
  kk_effects_dash_and_dash_types__hnd_yield_dup(h);
  kk_std_core_hnd__clause0 _match_2344;
  struct kk_effects_dash_and_dash_types__Hnd_yield* _con2564 = kk_effects_dash_and_dash_types__as_Hnd_yield(h);
  kk_std_core_hnd__clause0 control_yield = _con2564->control_yield;
  if (kk_effects_dash_and_dash_types__hnd_yield_is_unique(h)) {
    kk_effects_dash_and_dash_types__hnd_yield_free(h);
  }
  else {
    kk_std_core_hnd__clause0_dup(control_yield);
    kk_effects_dash_and_dash_types__hnd_yield_decref(h, _ctx);
  }
  _match_2344 = control_yield; /*std/core/hnd/clause0<(),effects-and-types/.hnd-yield,6,7>*/
  kk_function_t _fun_unbox_x2231 = _match_2344.clause;
  _x2561 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x2231, (_fun_unbox_x2231, m, ev_394, _ctx)); /*6*/
  kk_unit_unbox(_x2561);
  kk_unit_t __w_l679_c9 = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x2565 = kk_std_core_hnd_yield_cont(kk_handlers__new_mlift1712_yield__on__scorex_fun2566(i_1780, _ctx), _ctx); /*3*/
    kk_unit_unbox(_x2565); return kk_Unit;
  }
  y; return kk_Unit;
}


// lift anonymous function
struct kk_handlers_yield__on__scorex_fun2569__t {
  struct kk_function_s _base;
};
static kk_box_t kk_handlers_yield__on__scorex_fun2569(kk_function_t _fself, kk_std_core_hnd__marker _b_2273, kk_std_core_hnd__ev _b_2274, kk_box_t _b_2275, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_yield__on__scorex_fun2569(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_handlers_yield__on__scorex_fun2569, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_handlers_yield__on__scorex_fun2570__t {
  struct kk_function_s _base;
};
static kk_box_t kk_handlers_yield__on__scorex_fun2570(kk_function_t _fself, kk_box_t _b_2271, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_yield__on__scorex_fun2570(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_handlers_yield__on__scorex_fun2570, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_handlers_yield__on__scorex_fun2575__t {
  struct kk_function_s _base;
  size_t i_1785;
};
static kk_box_t kk_handlers_yield__on__scorex_fun2575(kk_function_t _fself, kk_function_t _b_2256, kk_box_t _b_2257, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_yield__on__scorex_fun2575(size_t i_1785, kk_context_t* _ctx) {
  struct kk_handlers_yield__on__scorex_fun2575__t* _self = kk_function_alloc_as(struct kk_handlers_yield__on__scorex_fun2575__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_yield__on__scorex_fun2575, kk_context());
  _self->i_1785 = i_1785;
  return &_self->_base;
}

static kk_box_t kk_handlers_yield__on__scorex_fun2575(kk_function_t _fself, kk_function_t _b_2256, kk_box_t _b_2257, kk_context_t* _ctx) {
  struct kk_handlers_yield__on__scorex_fun2575__t* _self = kk_function_as(struct kk_handlers_yield__on__scorex_fun2575__t*, _fself);
  size_t i_1785 = _self->i_1785; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_1785, _b_2256, _b_2257, _ctx);
}


// lift anonymous function
struct kk_handlers_yield__on__scorex_fun2577__t {
  struct kk_function_s _base;
};
static kk_box_t kk_handlers_yield__on__scorex_fun2577(kk_function_t _fself, kk_box_t _b_2267, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_yield__on__scorex_fun2577(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_handlers_yield__on__scorex_fun2577, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_handlers_yield__on__scorex_fun2577(kk_function_t _fself, kk_box_t _b_2267, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_unit_t _x2578 = kk_Unit;
  kk_unit_t _x2579 = kk_Unit;
  kk_unit_unbox(_b_2267);
  kk_handlers__mlift1712_yield__on__scorex(_x2579, _ctx);
  return kk_unit_box(_x2578);
}
static kk_box_t kk_handlers_yield__on__scorex_fun2570(kk_function_t _fself, kk_box_t _b_2271, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_unit_t _x2571 = kk_Unit;
  kk_unit_t x0_1783 = kk_Unit;
  size_t i_1785;
  kk_std_core_hnd__htag _x2572 = kk_std_core_hnd__htag_dup(kk_effects_dash_and_dash_types__tag_score); /*std/core/hnd/htag<effects-and-types/.hnd-score>*/
  i_1785 = kk_std_core_hnd__evv_index(_x2572, _ctx); /*std/core/hnd/ev-index*/
  kk_evv_t w0 = kk_evv_swap_create1(i_1785,kk_context()); /*std/core/hnd/evv<<effects-and-types/score,effects-and-types/yield|1647>>*/;
  kk_unit_t y = kk_Unit;
  kk_effects_dash_and_dash_types__exp _x2573 = kk_effects_dash_and_dash_types__exp_unbox(_b_2271, _ctx); /*effects-and-types/exp*/
  kk_effects_dash_and_dash_types_score(_x2573, _ctx);
  kk_unit_t __w_l696_c9 = kk_Unit;
  kk_evv_set(w0,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x2574 = kk_std_core_hnd_yield_cont(kk_handlers_new_yield__on__scorex_fun2575(i_1785, _ctx), _ctx); /*3*/
    kk_unit_unbox(_x2574);
  }
  else {
    y;
  }
  if (kk_yielding(kk_context())) {
    kk_box_t _x2576 = kk_std_core_hnd_yield_extend(kk_handlers_new_yield__on__scorex_fun2577(_ctx), _ctx); /*2*/
    kk_unit_unbox(_x2576);
  }
  else {
    kk_handlers__mlift1712_yield__on__scorex(x0_1783, _ctx);
  }
  return kk_unit_box(_x2571);
}
static kk_box_t kk_handlers_yield__on__scorex_fun2569(kk_function_t _fself, kk_std_core_hnd__marker _b_2273, kk_std_core_hnd__ev _b_2274, kk_box_t _b_2275, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return kk_std_core_hnd_under1(_b_2274, kk_handlers_new_yield__on__scorex_fun2570(_ctx), _b_2275, _ctx);
}


// lift anonymous function
struct kk_handlers_yield__on__scorex_fun2580__t {
  struct kk_function_s _base;
};
static kk_box_t kk_handlers_yield__on__scorex_fun2580(kk_function_t _fself, kk_box_t _x, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_yield__on__scorex_fun2580(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_handlers_yield__on__scorex_fun2580, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_handlers_yield__on__scorex_fun2580(kk_function_t _fself, kk_box_t _x, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return _x;
}

kk_box_t kk_handlers_yield__on__scorex(kk_function_t action, kk_context_t* _ctx) { /* forall<a,e> (action : () -> <effects-and-types/score,effects-and-types/score,effects-and-types/yield|e> a) -> <effects-and-types/score,effects-and-types/yield|e> a */ 
  kk_effects_dash_and_dash_types__hnd_score _x2567;
  kk_std_core_hnd__clause1 _x2568 = kk_std_core_hnd__new_Clause1(kk_handlers_new_yield__on__scorex_fun2569(_ctx), _ctx); /*std/core/hnd/clause1<16,17,18,19,20>*/
  _x2567 = kk_effects_dash_and_dash_types__new_Hnd_score(kk_reuse_null, _x2568, _ctx); /*effects-and-types/.hnd-score<17,18>*/
  return kk_effects_dash_and_dash_types__handle_score(((int32_t)1), _x2567, kk_handlers_new_yield__on__scorex_fun2580(_ctx), action, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_handlers__mlift1713_replay_fun2581__t {
  struct kk_function_s _base;
  size_t _y_39;
};
static kk_box_t kk_handlers__mlift1713_replay_fun2581(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift1713_replay_fun2581(size_t _y_39, kk_context_t* _ctx) {
  struct kk_handlers__mlift1713_replay_fun2581__t* _self = kk_function_alloc_as(struct kk_handlers__mlift1713_replay_fun2581__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift1713_replay_fun2581, kk_context());
  _self->_y_39 = _y_39;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift1713_replay_fun2581(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_handlers__mlift1713_replay_fun2581__t* _self = kk_function_as(struct kk_handlers__mlift1713_replay_fun2581__t*, _fself);
  size_t _y_39 = _self->_y_39; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_mask_at1(_y_39, true, cont, res, _ctx);
}

kk_box_t kk_handlers__mlift1713_replay(kk_function_t action, size_t _y_39, kk_context_t* _ctx) { /* forall<a,e> (action : () -> <effects-and-types/sample|e> a, std/core/hnd/ev-index) -> <effects-and-types/sample,effects-and-types/sample|e> a */ 
  kk_evv_t w0 = kk_std_core_hnd_evv_swap_delete(_y_39, true, _ctx); /*std/core/hnd/evv<std/core/hnd/_e2>*/;
  kk_box_t x = kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), action, (action, _ctx)); /*1664*/;
  kk_unit_t __w_l641_c9 = kk_Unit;
  kk_evv_set(w0,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_drop(x, _ctx);
    return kk_std_core_hnd_yield_cont(kk_handlers__new_mlift1713_replay_fun2581(_y_39, _ctx), _ctx);
  }
  return x;
}


// lift anonymous function
struct kk_handlers_replay_fun2582__t {
  struct kk_function_s _base;
  kk_function_t action;
};
static kk_box_t kk_handlers_replay_fun2582(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_replay_fun2582(kk_function_t action, kk_context_t* _ctx) {
  struct kk_handlers_replay_fun2582__t* _self = kk_function_alloc_as(struct kk_handlers_replay_fun2582__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_replay_fun2582, kk_context());
  _self->action = action;
  return &_self->_base;
}



// lift anonymous function
struct kk_handlers_replay_fun2584__t {
  struct kk_function_s _base;
  kk_function_t action;
};
static kk_box_t kk_handlers_replay_fun2584(kk_function_t _fself, kk_box_t _b_2287, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_replay_fun2584(kk_function_t action, kk_context_t* _ctx) {
  struct kk_handlers_replay_fun2584__t* _self = kk_function_alloc_as(struct kk_handlers_replay_fun2584__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_replay_fun2584, kk_context());
  _self->action = action;
  return &_self->_base;
}

static kk_box_t kk_handlers_replay_fun2584(kk_function_t _fself, kk_box_t _b_2287, kk_context_t* _ctx) {
  struct kk_handlers_replay_fun2584__t* _self = kk_function_as(struct kk_handlers_replay_fun2584__t*, _fself);
  kk_function_t action = _self->action; /* () -> <effects-and-types/sample|1665> 1664 */
  kk_drop_match(_self, {kk_function_dup(action);}, {}, _ctx)
  size_t _x2585 = kk_size_unbox(_b_2287, _ctx); /*std/core/hnd/ev-index*/
  return kk_handlers__mlift1713_replay(action, _x2585, _ctx);
}
static kk_box_t kk_handlers_replay_fun2582(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_handlers_replay_fun2582__t* _self = kk_function_as(struct kk_handlers_replay_fun2582__t*, _fself);
  kk_function_t action = _self->action; /* () -> <effects-and-types/sample|1665> 1664 */
  kk_drop_match(_self, {kk_function_dup(action);}, {}, _ctx)
  size_t x_1791;
  kk_std_core_hnd__htag _x2583 = kk_std_core_hnd__htag_dup(kk_effects_dash_and_dash_types__tag_sample); /*std/core/hnd/htag<effects-and-types/.hnd-sample>*/
  x_1791 = kk_std_core_hnd__evv_index(_x2583, _ctx); /*std/core/hnd/ev-index*/
  if (kk_yielding(kk_context())) {
    return kk_std_core_hnd_yield_extend(kk_handlers_new_replay_fun2584(action, _ctx), _ctx);
  }
  return kk_handlers__mlift1713_replay(action, x_1791, _ctx);
}

kk_std_core_types__tuple2_ kk_handlers_replay(kk_std_core__list trace, kk_function_t action, kk_context_t* _ctx) { /* forall<a,e> (trace : effects-and-types/trace_values, action : () -> <effects-and-types/sample|e> a) -> <effects-and-types/sample|e> (list<double>, a) */ 
  return kk_handlers_replayx(trace, kk_handlers_new_replay_fun2582(action, _ctx), _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_handlers__mlift1714_yield__on__score_fun2586__t {
  struct kk_function_s _base;
  size_t _y_42;
};
static kk_box_t kk_handlers__mlift1714_yield__on__score_fun2586(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift1714_yield__on__score_fun2586(size_t _y_42, kk_context_t* _ctx) {
  struct kk_handlers__mlift1714_yield__on__score_fun2586__t* _self = kk_function_alloc_as(struct kk_handlers__mlift1714_yield__on__score_fun2586__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift1714_yield__on__score_fun2586, kk_context());
  _self->_y_42 = _y_42;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift1714_yield__on__score_fun2586(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_handlers__mlift1714_yield__on__score_fun2586__t* _self = kk_function_as(struct kk_handlers__mlift1714_yield__on__score_fun2586__t*, _fself);
  size_t _y_42 = _self->_y_42; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_mask_at1(_y_42, true, cont, res, _ctx);
}

kk_box_t kk_handlers__mlift1714_yield__on__score(kk_function_t action, size_t _y_42, kk_context_t* _ctx) { /* forall<a,e> (action : () -> <effects-and-types/score,effects-and-types/yield|e> a, std/core/hnd/ev-index) -> <effects-and-types/score,effects-and-types/score,effects-and-types/yield|e> a */ 
  kk_evv_t w0 = kk_std_core_hnd_evv_swap_delete(_y_42, true, _ctx); /*std/core/hnd/evv<std/core/hnd/_e2>*/;
  kk_box_t x = kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), action, (action, _ctx)); /*1683*/;
  kk_unit_t __w_l641_c9 = kk_Unit;
  kk_evv_set(w0,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_drop(x, _ctx);
    return kk_std_core_hnd_yield_cont(kk_handlers__new_mlift1714_yield__on__score_fun2586(_y_42, _ctx), _ctx);
  }
  return x;
}


// lift anonymous function
struct kk_handlers_yield__on__score_fun2589__t {
  struct kk_function_s _base;
};
static kk_box_t kk_handlers_yield__on__score_fun2589(kk_function_t _fself, kk_std_core_hnd__marker _b_2312, kk_std_core_hnd__ev _b_2313, kk_box_t _b_2314, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_yield__on__score_fun2589(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_handlers_yield__on__score_fun2589, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_handlers_yield__on__score_fun2590__t {
  struct kk_function_s _base;
};
static kk_box_t kk_handlers_yield__on__score_fun2590(kk_function_t _fself, kk_box_t _b_2310, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_yield__on__score_fun2590(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_handlers_yield__on__score_fun2590, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_handlers_yield__on__score_fun2595__t {
  struct kk_function_s _base;
  size_t i_1785;
};
static kk_box_t kk_handlers_yield__on__score_fun2595(kk_function_t _fself, kk_function_t _b_2295, kk_box_t _b_2296, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_yield__on__score_fun2595(size_t i_1785, kk_context_t* _ctx) {
  struct kk_handlers_yield__on__score_fun2595__t* _self = kk_function_alloc_as(struct kk_handlers_yield__on__score_fun2595__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_yield__on__score_fun2595, kk_context());
  _self->i_1785 = i_1785;
  return &_self->_base;
}

static kk_box_t kk_handlers_yield__on__score_fun2595(kk_function_t _fself, kk_function_t _b_2295, kk_box_t _b_2296, kk_context_t* _ctx) {
  struct kk_handlers_yield__on__score_fun2595__t* _self = kk_function_as(struct kk_handlers_yield__on__score_fun2595__t*, _fself);
  size_t i_1785 = _self->i_1785; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_1785, _b_2295, _b_2296, _ctx);
}


// lift anonymous function
struct kk_handlers_yield__on__score_fun2597__t {
  struct kk_function_s _base;
};
static kk_box_t kk_handlers_yield__on__score_fun2597(kk_function_t _fself, kk_box_t _b_2306, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_yield__on__score_fun2597(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_handlers_yield__on__score_fun2597, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_handlers_yield__on__score_fun2597(kk_function_t _fself, kk_box_t _b_2306, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_unit_t _x2598 = kk_Unit;
  kk_unit_t _x2599 = kk_Unit;
  kk_unit_unbox(_b_2306);
  kk_handlers__mlift1712_yield__on__scorex(_x2599, _ctx);
  return kk_unit_box(_x2598);
}
static kk_box_t kk_handlers_yield__on__score_fun2590(kk_function_t _fself, kk_box_t _b_2310, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_unit_t _x2591 = kk_Unit;
  kk_unit_t x0_1783 = kk_Unit;
  size_t i_1785;
  kk_std_core_hnd__htag _x2592 = kk_std_core_hnd__htag_dup(kk_effects_dash_and_dash_types__tag_score); /*std/core/hnd/htag<effects-and-types/.hnd-score>*/
  i_1785 = kk_std_core_hnd__evv_index(_x2592, _ctx); /*std/core/hnd/ev-index*/
  kk_evv_t w0 = kk_evv_swap_create1(i_1785,kk_context()); /*std/core/hnd/evv<<effects-and-types/score,effects-and-types/yield|1684>>*/;
  kk_unit_t y = kk_Unit;
  kk_effects_dash_and_dash_types__exp _x2593 = kk_effects_dash_and_dash_types__exp_unbox(_b_2310, _ctx); /*effects-and-types/exp*/
  kk_effects_dash_and_dash_types_score(_x2593, _ctx);
  kk_unit_t __w_l696_c9 = kk_Unit;
  kk_evv_set(w0,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x2594 = kk_std_core_hnd_yield_cont(kk_handlers_new_yield__on__score_fun2595(i_1785, _ctx), _ctx); /*3*/
    kk_unit_unbox(_x2594);
  }
  else {
    y;
  }
  if (kk_yielding(kk_context())) {
    kk_box_t _x2596 = kk_std_core_hnd_yield_extend(kk_handlers_new_yield__on__score_fun2597(_ctx), _ctx); /*2*/
    kk_unit_unbox(_x2596);
  }
  else {
    kk_handlers__mlift1712_yield__on__scorex(x0_1783, _ctx);
  }
  return kk_unit_box(_x2591);
}
static kk_box_t kk_handlers_yield__on__score_fun2589(kk_function_t _fself, kk_std_core_hnd__marker _b_2312, kk_std_core_hnd__ev _b_2313, kk_box_t _b_2314, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return kk_std_core_hnd_under1(_b_2313, kk_handlers_new_yield__on__score_fun2590(_ctx), _b_2314, _ctx);
}


// lift anonymous function
struct kk_handlers_yield__on__score_fun2600__t {
  struct kk_function_s _base;
};
static kk_box_t kk_handlers_yield__on__score_fun2600(kk_function_t _fself, kk_box_t _x, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_yield__on__score_fun2600(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_handlers_yield__on__score_fun2600, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_handlers_yield__on__score_fun2600(kk_function_t _fself, kk_box_t _x, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return _x;
}


// lift anonymous function
struct kk_handlers_yield__on__score_fun2601__t {
  struct kk_function_s _base;
  kk_function_t action;
};
static kk_box_t kk_handlers_yield__on__score_fun2601(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_yield__on__score_fun2601(kk_function_t action, kk_context_t* _ctx) {
  struct kk_handlers_yield__on__score_fun2601__t* _self = kk_function_alloc_as(struct kk_handlers_yield__on__score_fun2601__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_yield__on__score_fun2601, kk_context());
  _self->action = action;
  return &_self->_base;
}



// lift anonymous function
struct kk_handlers_yield__on__score_fun2603__t {
  struct kk_function_s _base;
  kk_function_t action;
};
static kk_box_t kk_handlers_yield__on__score_fun2603(kk_function_t _fself, kk_box_t _b_2316, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_yield__on__score_fun2603(kk_function_t action, kk_context_t* _ctx) {
  struct kk_handlers_yield__on__score_fun2603__t* _self = kk_function_alloc_as(struct kk_handlers_yield__on__score_fun2603__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_yield__on__score_fun2603, kk_context());
  _self->action = action;
  return &_self->_base;
}

static kk_box_t kk_handlers_yield__on__score_fun2603(kk_function_t _fself, kk_box_t _b_2316, kk_context_t* _ctx) {
  struct kk_handlers_yield__on__score_fun2603__t* _self = kk_function_as(struct kk_handlers_yield__on__score_fun2603__t*, _fself);
  kk_function_t action = _self->action; /* () -> <effects-and-types/score,effects-and-types/yield|1684> 1683 */
  kk_drop_match(_self, {kk_function_dup(action);}, {}, _ctx)
  size_t _x2604 = kk_size_unbox(_b_2316, _ctx); /*std/core/hnd/ev-index*/
  return kk_handlers__mlift1714_yield__on__score(action, _x2604, _ctx);
}
static kk_box_t kk_handlers_yield__on__score_fun2601(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_handlers_yield__on__score_fun2601__t* _self = kk_function_as(struct kk_handlers_yield__on__score_fun2601__t*, _fself);
  kk_function_t action = _self->action; /* () -> <effects-and-types/score,effects-and-types/yield|1684> 1683 */
  kk_drop_match(_self, {kk_function_dup(action);}, {}, _ctx)
  size_t x_1796;
  kk_std_core_hnd__htag _x2602 = kk_std_core_hnd__htag_dup(kk_effects_dash_and_dash_types__tag_score); /*std/core/hnd/htag<effects-and-types/.hnd-score>*/
  x_1796 = kk_std_core_hnd__evv_index(_x2602, _ctx); /*std/core/hnd/ev-index*/
  if (kk_yielding(kk_context())) {
    return kk_std_core_hnd_yield_extend(kk_handlers_new_yield__on__score_fun2603(action, _ctx), _ctx);
  }
  return kk_handlers__mlift1714_yield__on__score(action, x_1796, _ctx);
}

kk_box_t kk_handlers_yield__on__score(kk_function_t action, kk_context_t* _ctx) { /* forall<a,e> (action : () -> <effects-and-types/score,effects-and-types/yield|e> a) -> <effects-and-types/score,effects-and-types/yield|e> a */ 
  kk_effects_dash_and_dash_types__hnd_score _x2587;
  kk_std_core_hnd__clause1 _x2588 = kk_std_core_hnd__new_Clause1(kk_handlers_new_yield__on__score_fun2589(_ctx), _ctx); /*std/core/hnd/clause1<16,17,18,19,20>*/
  _x2587 = kk_effects_dash_and_dash_types__new_Hnd_score(kk_reuse_null, _x2588, _ctx); /*effects-and-types/.hnd-score<17,18>*/
  return kk_effects_dash_and_dash_types__handle_score(((int32_t)1), _x2587, kk_handlers_new_yield__on__score_fun2600(_ctx), kk_handlers_new_yield__on__score_fun2601(action, _ctx), _ctx);
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
