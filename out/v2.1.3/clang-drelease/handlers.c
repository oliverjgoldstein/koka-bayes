// Koka generated module: "handlers", koka version: 2.1.3
#include "handlers.h"
 
// monadic lift

kk_box_t kk_handlers__mlift2510_advance(kk_integer_t steps, kk_function_t _y_2, kk_context_t* _ctx) { /* forall<a,e> (steps : int, (int) -> <effects-and-types/yield|e> a) -> <effects-and-types/yield|e> a */ 
  kk_integer_t _x3732 = kk_integer_sub(steps,(kk_integer_from_small(1)),kk_context()); /*int*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_context_t*), _y_2, (_y_2, _x3732, _ctx));
}
 
// monadic lift


// lift anonymous function
struct kk_handlers__mlift2511_advance_fun3733__t {
  struct kk_function_s _base;
};
static kk_unit_t kk_handlers__mlift2511_advance_fun3733(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2511_advance_fun3733(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_handlers__mlift2511_advance_fun3733, _ctx)
  return kk_function_dup(_fself);
}

static kk_unit_t kk_handlers__mlift2511_advance_fun3733(kk_function_t _fself, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return kk_Unit;
}


// lift anonymous function
struct kk_handlers__mlift2511_advance_fun3735__t {
  struct kk_function_s _base;
  kk_function_t _bv_2737;
};
static kk_function_t kk_handlers__mlift2511_advance_fun3735(kk_function_t _fself, kk_function_t _b_2738, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2511_advance_fun3735(kk_function_t _bv_2737, kk_context_t* _ctx) {
  struct kk_handlers__mlift2511_advance_fun3735__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2511_advance_fun3735__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2511_advance_fun3735, kk_context());
  _self->_bv_2737 = _bv_2737;
  return &_self->_base;
}



// lift anonymous function
struct kk_handlers__mlift2511_advance_fun3737__t {
  struct kk_function_s _base;
  kk_function_t _b_2738;
};
static kk_box_t kk_handlers__mlift2511_advance_fun3737(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2511_advance_fun3737(kk_function_t _b_2738, kk_context_t* _ctx) {
  struct kk_handlers__mlift2511_advance_fun3737__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2511_advance_fun3737__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2511_advance_fun3737, kk_context());
  _self->_b_2738 = _b_2738;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift2511_advance_fun3737(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_handlers__mlift2511_advance_fun3737__t* _self = kk_function_as(struct kk_handlers__mlift2511_advance_fun3737__t*, _fself);
  kk_function_t _b_2738 = _self->_b_2738; /* () -> () */
  kk_drop_match(_self, {kk_function_dup(_b_2738);}, {}, _ctx)
  kk_unit_t _x3738 = kk_Unit;
  kk_function_call(kk_unit_t, (kk_function_t, kk_context_t*), _b_2738, (_b_2738, _ctx));
  return kk_unit_box(_x3738);
}


// lift anonymous function
struct kk_handlers__mlift2511_advance_fun3739__t {
  struct kk_function_s _base;
  kk_function_t _bv_2741;
};
static kk_box_t kk_handlers__mlift2511_advance_fun3739(kk_function_t _fself, kk_integer_t _b_2742, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2511_advance_fun3739(kk_function_t _bv_2741, kk_context_t* _ctx) {
  struct kk_handlers__mlift2511_advance_fun3739__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2511_advance_fun3739__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2511_advance_fun3739, kk_context());
  _self->_bv_2741 = _bv_2741;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift2511_advance_fun3739(kk_function_t _fself, kk_integer_t _b_2742, kk_context_t* _ctx) {
  struct kk_handlers__mlift2511_advance_fun3739__t* _self = kk_function_as(struct kk_handlers__mlift2511_advance_fun3739__t*, _fself);
  kk_function_t _bv_2741 = _self->_bv_2741; /* (2739) -> <.Box|.Box> 2740 */
  kk_drop_match(_self, {kk_function_dup(_bv_2741);}, {}, _ctx)
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _bv_2741, (_bv_2741, kk_integer_box(_b_2742), _ctx));
}
static kk_function_t kk_handlers__mlift2511_advance_fun3735(kk_function_t _fself, kk_function_t _b_2738, kk_context_t* _ctx) {
  struct kk_handlers__mlift2511_advance_fun3735__t* _self = kk_function_as(struct kk_handlers__mlift2511_advance_fun3735__t*, _fself);
  kk_function_t _bv_2737 = _self->_bv_2737; /* (() -> 2806) -> 2807 2808 */
  kk_drop_match(_self, {kk_function_dup(_bv_2737);}, {}, _ctx)
  kk_function_t _bv_2741;
  kk_box_t _x3736 = kk_function_call(kk_box_t, (kk_function_t, kk_function_t, kk_context_t*), _bv_2737, (_bv_2737, kk_handlers__new_mlift2511_advance_fun3737(_b_2738, _ctx), _ctx)); /*2808*/
  _bv_2741 = kk_function_unbox(_x3736); /*(2739) -> <.Box|.Box> 2740*/
  return kk_handlers__new_mlift2511_advance_fun3739(_bv_2741, _ctx);
}


// lift anonymous function
struct kk_handlers__mlift2511_advance_fun3741__t {
  struct kk_function_s _base;
  size_t _y_0;
};
static kk_box_t kk_handlers__mlift2511_advance_fun3741(kk_function_t _fself, kk_function_t _b_2764, kk_box_t _b_2765, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2511_advance_fun3741(size_t _y_0, kk_context_t* _ctx) {
  struct kk_handlers__mlift2511_advance_fun3741__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2511_advance_fun3741__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2511_advance_fun3741, kk_context());
  _self->_y_0 = _y_0;
  return &_self->_base;
}



// lift anonymous function
struct kk_handlers__mlift2511_advance_fun3744__t {
  struct kk_function_s _base;
  kk_function_t _b_2764;
};
static kk_box_t kk_handlers__mlift2511_advance_fun3744(kk_function_t _fself, kk_box_t _b_2748, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2511_advance_fun3744(kk_function_t _b_2764, kk_context_t* _ctx) {
  struct kk_handlers__mlift2511_advance_fun3744__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2511_advance_fun3744__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2511_advance_fun3744, kk_context());
  _self->_b_2764 = _b_2764;
  return &_self->_base;
}



// lift anonymous function
struct kk_handlers__mlift2511_advance_fun3747__t {
  struct kk_function_s _base;
  kk_box_t _b_2748;
};
static kk_box_t kk_handlers__mlift2511_advance_fun3747(kk_function_t _fself, kk_box_t _b_2769, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2511_advance_fun3747(kk_box_t _b_2748, kk_context_t* _ctx) {
  struct kk_handlers__mlift2511_advance_fun3747__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2511_advance_fun3747__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2511_advance_fun3747, kk_context());
  _self->_b_2748 = _b_2748;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift2511_advance_fun3747(kk_function_t _fself, kk_box_t _b_2769, kk_context_t* _ctx) {
  struct kk_handlers__mlift2511_advance_fun3747__t* _self = kk_function_as(struct kk_handlers__mlift2511_advance_fun3747__t*, _fself);
  kk_box_t _b_2748 = _self->_b_2748; /* 4674 */
  kk_drop_match(_self, {kk_box_dup(_b_2748);}, {}, _ctx)
  kk_function_t _x3748 = kk_function_unbox(_b_2748); /*(2749) -> <effects-and-types/yield|270> 2750*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x3748, (_x3748, _b_2769, _ctx));
}


// lift anonymous function
struct kk_handlers__mlift2511_advance_fun3749__t {
  struct kk_function_s _base;
  kk_function_t _bv_2772;
};
static kk_box_t kk_handlers__mlift2511_advance_fun3749(kk_function_t _fself, kk_integer_t _b_2773, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2511_advance_fun3749(kk_function_t _bv_2772, kk_context_t* _ctx) {
  struct kk_handlers__mlift2511_advance_fun3749__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2511_advance_fun3749__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2511_advance_fun3749, kk_context());
  _self->_bv_2772 = _bv_2772;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift2511_advance_fun3749(kk_function_t _fself, kk_integer_t _b_2773, kk_context_t* _ctx) {
  struct kk_handlers__mlift2511_advance_fun3749__t* _self = kk_function_as(struct kk_handlers__mlift2511_advance_fun3749__t*, _fself);
  kk_function_t _bv_2772 = _self->_bv_2772; /* (2770) -> <effects-and-types/yield|270> 2771 */
  kk_drop_match(_self, {kk_function_dup(_bv_2772);}, {}, _ctx)
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _bv_2772, (_bv_2772, kk_integer_box(_b_2773), _ctx));
}


// lift anonymous function
struct kk_handlers__mlift2511_advance_fun3750__t {
  struct kk_function_s _base;
  kk_function_t _bv_2754;
};
static kk_box_t kk_handlers__mlift2511_advance_fun3750(kk_function_t _fself, kk_box_t _b_2755, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2511_advance_fun3750(kk_function_t _bv_2754, kk_context_t* _ctx) {
  struct kk_handlers__mlift2511_advance_fun3750__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2511_advance_fun3750__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2511_advance_fun3750, kk_context());
  _self->_bv_2754 = _bv_2754;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift2511_advance_fun3750(kk_function_t _fself, kk_box_t _b_2755, kk_context_t* _ctx) {
  struct kk_handlers__mlift2511_advance_fun3750__t* _self = kk_function_as(struct kk_handlers__mlift2511_advance_fun3750__t*, _fself);
  kk_function_t _bv_2754 = _self->_bv_2754; /* (int) -> <effects-and-types/yield|270> 269 */
  kk_drop_match(_self, {kk_function_dup(_bv_2754);}, {}, _ctx)
  kk_integer_t _x3751 = kk_integer_unbox(_b_2755); /*int*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_context_t*), _bv_2754, (_bv_2754, _x3751, _ctx));
}
static kk_box_t kk_handlers__mlift2511_advance_fun3744(kk_function_t _fself, kk_box_t _b_2748, kk_context_t* _ctx) {
  struct kk_handlers__mlift2511_advance_fun3744__t* _self = kk_function_as(struct kk_handlers__mlift2511_advance_fun3744__t*, _fself);
  kk_function_t _b_2764 = _self->_b_2764; /* (3818) -> 3819 3818 */
  kk_drop_match(_self, {kk_function_dup(_b_2764);}, {}, _ctx)
  kk_function_t _x3745;
  kk_function_t _bv_2754;
  kk_function_t _bv_2772;
  kk_box_t _x3746 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _b_2764, (_b_2764, kk_function_box(kk_handlers__new_mlift2511_advance_fun3747(_b_2748, _ctx)), _ctx)); /*3818*/
  _bv_2772 = kk_function_unbox(_x3746); /*(2770) -> <effects-and-types/yield|270> 2771*/
  _bv_2754 = kk_handlers__new_mlift2511_advance_fun3749(_bv_2772, _ctx); /*(int) -> <effects-and-types/yield|270> 269*/
  _x3745 = kk_handlers__new_mlift2511_advance_fun3750(_bv_2754, _ctx); /*(2752) -> <effects-and-types/yield|270> 269*/
  return kk_function_box(_x3745);
}


// lift anonymous function
struct kk_handlers__mlift2511_advance_fun3752__t {
  struct kk_function_s _base;
  kk_box_t _b_2765;
};
static kk_box_t kk_handlers__mlift2511_advance_fun3752(kk_function_t _fself, kk_box_t _b_2758, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2511_advance_fun3752(kk_box_t _b_2765, kk_context_t* _ctx) {
  struct kk_handlers__mlift2511_advance_fun3752__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2511_advance_fun3752__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2511_advance_fun3752, kk_context());
  _self->_b_2765 = _b_2765;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift2511_advance_fun3752(kk_function_t _fself, kk_box_t _b_2758, kk_context_t* _ctx) {
  struct kk_handlers__mlift2511_advance_fun3752__t* _self = kk_function_as(struct kk_handlers__mlift2511_advance_fun3752__t*, _fself);
  kk_box_t _b_2765 = _self->_b_2765; /* 3818 */
  kk_drop_match(_self, {kk_box_dup(_b_2765);}, {}, _ctx)
  kk_function_t _x3753 = kk_function_unbox(_b_2765); /*(2774) -> <effects-and-types/yield|270> 2775*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x3753, (_x3753, _b_2758, _ctx));
}


// lift anonymous function
struct kk_handlers__mlift2511_advance_fun3754__t {
  struct kk_function_s _base;
  kk_function_t _bv_2761;
};
static kk_box_t kk_handlers__mlift2511_advance_fun3754(kk_function_t _fself, kk_integer_t _b_2762, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2511_advance_fun3754(kk_function_t _bv_2761, kk_context_t* _ctx) {
  struct kk_handlers__mlift2511_advance_fun3754__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2511_advance_fun3754__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2511_advance_fun3754, kk_context());
  _self->_bv_2761 = _bv_2761;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift2511_advance_fun3754(kk_function_t _fself, kk_integer_t _b_2762, kk_context_t* _ctx) {
  struct kk_handlers__mlift2511_advance_fun3754__t* _self = kk_function_as(struct kk_handlers__mlift2511_advance_fun3754__t*, _fself);
  kk_function_t _bv_2761 = _self->_bv_2761; /* (2759) -> <effects-and-types/yield|270> 2760 */
  kk_drop_match(_self, {kk_function_dup(_bv_2761);}, {}, _ctx)
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _bv_2761, (_bv_2761, kk_integer_box(_b_2762), _ctx));
}


// lift anonymous function
struct kk_handlers__mlift2511_advance_fun3755__t {
  struct kk_function_s _base;
  kk_function_t _bv_2779;
};
static kk_box_t kk_handlers__mlift2511_advance_fun3755(kk_function_t _fself, kk_box_t _b_2780, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2511_advance_fun3755(kk_function_t _bv_2779, kk_context_t* _ctx) {
  struct kk_handlers__mlift2511_advance_fun3755__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2511_advance_fun3755__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2511_advance_fun3755, kk_context());
  _self->_bv_2779 = _bv_2779;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift2511_advance_fun3755(kk_function_t _fself, kk_box_t _b_2780, kk_context_t* _ctx) {
  struct kk_handlers__mlift2511_advance_fun3755__t* _self = kk_function_as(struct kk_handlers__mlift2511_advance_fun3755__t*, _fself);
  kk_function_t _bv_2779 = _self->_bv_2779; /* (int) -> <effects-and-types/yield|270> 269 */
  kk_drop_match(_self, {kk_function_dup(_bv_2779);}, {}, _ctx)
  kk_integer_t _x3756 = kk_integer_unbox(_b_2780); /*int*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_context_t*), _bv_2779, (_bv_2779, _x3756, _ctx));
}
static kk_box_t kk_handlers__mlift2511_advance_fun3741(kk_function_t _fself, kk_function_t _b_2764, kk_box_t _b_2765, kk_context_t* _ctx) {
  struct kk_handlers__mlift2511_advance_fun3741__t* _self = kk_function_as(struct kk_handlers__mlift2511_advance_fun3741__t*, _fself);
  size_t _y_0 = _self->_y_0; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  kk_function_t _x3742;
  kk_function_t _bv_2779;
  kk_function_t _bv_2761;
  kk_box_t _x3743 = kk_std_core_hnd_mask_at1(_y_0, false, kk_handlers__new_mlift2511_advance_fun3744(_b_2764, _ctx), kk_function_box(kk_handlers__new_mlift2511_advance_fun3752(_b_2765, _ctx)), _ctx); /*4675*/
  _bv_2761 = kk_function_unbox(_x3743); /*(2759) -> <effects-and-types/yield|270> 2760*/
  _bv_2779 = kk_handlers__new_mlift2511_advance_fun3754(_bv_2761, _ctx); /*(int) -> <effects-and-types/yield|270> 269*/
  _x3742 = kk_handlers__new_mlift2511_advance_fun3755(_bv_2779, _ctx); /*(2777) -> <effects-and-types/yield|270> 269*/
  return kk_function_box(_x3742);
}


// lift anonymous function
struct kk_handlers__mlift2511_advance_fun3757__t {
  struct kk_function_s _base;
  kk_function_t _bv_2783;
};
static kk_box_t kk_handlers__mlift2511_advance_fun3757(kk_function_t _fself, kk_integer_t _b_2784, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2511_advance_fun3757(kk_function_t _bv_2783, kk_context_t* _ctx) {
  struct kk_handlers__mlift2511_advance_fun3757__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2511_advance_fun3757__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2511_advance_fun3757, kk_context());
  _self->_bv_2783 = _bv_2783;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift2511_advance_fun3757(kk_function_t _fself, kk_integer_t _b_2784, kk_context_t* _ctx) {
  struct kk_handlers__mlift2511_advance_fun3757__t* _self = kk_function_as(struct kk_handlers__mlift2511_advance_fun3757__t*, _fself);
  kk_function_t _bv_2783 = _self->_bv_2783; /* (2781) -> <.Box|.Box> 2782 */
  kk_drop_match(_self, {kk_function_dup(_bv_2783);}, {}, _ctx)
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _bv_2783, (_bv_2783, kk_integer_box(_b_2784), _ctx));
}


// lift anonymous function
struct kk_handlers__mlift2511_advance_fun3758__t {
  struct kk_function_s _base;
  kk_integer_t steps;
};
static kk_box_t kk_handlers__mlift2511_advance_fun3758(kk_function_t _fself, kk_box_t _b_2796, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2511_advance_fun3758(kk_integer_t steps, kk_context_t* _ctx) {
  struct kk_handlers__mlift2511_advance_fun3758__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2511_advance_fun3758__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2511_advance_fun3758, kk_context());
  _self->steps = steps;
  return &_self->_base;
}



// lift anonymous function
struct kk_handlers__mlift2511_advance_fun3759__t {
  struct kk_function_s _base;
  kk_box_t _b_2796;
};
static kk_box_t kk_handlers__mlift2511_advance_fun3759(kk_function_t _fself, kk_integer_t _b_2799, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2511_advance_fun3759(kk_box_t _b_2796, kk_context_t* _ctx) {
  struct kk_handlers__mlift2511_advance_fun3759__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2511_advance_fun3759__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2511_advance_fun3759, kk_context());
  _self->_b_2796 = _b_2796;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift2511_advance_fun3759(kk_function_t _fself, kk_integer_t _b_2799, kk_context_t* _ctx) {
  struct kk_handlers__mlift2511_advance_fun3759__t* _self = kk_function_as(struct kk_handlers__mlift2511_advance_fun3759__t*, _fself);
  kk_box_t _b_2796 = _self->_b_2796; /* 3990 */
  kk_drop_match(_self, {kk_box_dup(_b_2796);}, {}, _ctx)
  kk_function_t _x3760 = kk_function_unbox(_b_2796); /*(2797) -> <effects-and-types/yield|270> 2798*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x3760, (_x3760, kk_integer_box(_b_2799), _ctx));
}
static kk_box_t kk_handlers__mlift2511_advance_fun3758(kk_function_t _fself, kk_box_t _b_2796, kk_context_t* _ctx) {
  struct kk_handlers__mlift2511_advance_fun3758__t* _self = kk_function_as(struct kk_handlers__mlift2511_advance_fun3758__t*, _fself);
  kk_integer_t steps = _self->steps; /* int */
  kk_drop_match(_self, {kk_integer_dup(steps);}, {}, _ctx)
  return kk_handlers__mlift2510_advance(steps, kk_handlers__new_mlift2511_advance_fun3759(_b_2796, _ctx), _ctx);
}

kk_box_t kk_handlers__mlift2511_advance(kk_std_core_hnd__resume_context rcontext, kk_integer_t steps, size_t _y_0, kk_context_t* _ctx) { /* forall<a,e> (rcontext : std/core/hnd/resume-context<(),e,(int) -> <effects-and-types/yield|e> a>, steps : int, std/core/hnd/ev-index) -> <effects-and-types/yield|e> a */ 
  kk_function_t x_2543;
  kk_evv_t w0 = kk_std_core_hnd_evv_swap_delete(_y_0, false, _ctx); /*std/core/hnd/evv<_4681>*/;
  kk_function_t x0;
  kk_function_t _x3734;
  kk_function_t _bv_2737 = kk_std_core_hnd_k(rcontext, _ctx); /*(() -> 2806) -> 2807 2808*/;
  _x3734 = kk_handlers__new_mlift2511_advance_fun3735(_bv_2737, _ctx); /*(() -> ()) -> ((int) -> <.Box|.Box> 2740)*/
  x0 = kk_function_call(kk_function_t, (kk_function_t, kk_function_t, kk_context_t*), _x3734, (_x3734, kk_handlers__new_mlift2511_advance_fun3733(_ctx), _ctx)); /*(int) -> <effects-and-types/yield|270> 269*/
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w0,kk_context());
  if (kk_yielding(kk_context())) {
    kk_function_drop(x0, _ctx);
    kk_function_t _bv_2783;
    kk_box_t _x3740 = kk_std_core_hnd_yield_cont(kk_handlers__new_mlift2511_advance_fun3741(_y_0, _ctx), _ctx); /*3820*/
    _bv_2783 = kk_function_unbox(_x3740); /*(2781) -> <.Box|.Box> 2782*/
    x_2543 = kk_handlers__new_mlift2511_advance_fun3757(_bv_2783, _ctx); /*(int) -> <effects-and-types/yield|270> 269*/
  }
  else {
    x_2543 = x0; /*(int) -> <effects-and-types/yield|270> 269*/
  }
  if (kk_yielding(kk_context())) {
    kk_function_drop(x_2543, _ctx);
    return kk_std_core_hnd_yield_extend(kk_handlers__new_mlift2511_advance_fun3758(steps, _ctx), _ctx);
  }
  return kk_handlers__mlift2510_advance(steps, x_2543, _ctx);
}
 
// monadic lift

kk_box_t kk_handlers__mlift2512_advance(kk_function_t _y_7, kk_context_t* _ctx) { /* forall<a,e> ((int) -> <effects-and-types/yield|e> a) -> <effects-and-types/yield|e> a */ 
  return kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_context_t*), _y_7, (_y_7, kk_integer_from_small(0), _ctx));
}
 
// monadic lift


// lift anonymous function
struct kk_handlers__mlift2513_advance_fun3761__t {
  struct kk_function_s _base;
};
static kk_unit_t kk_handlers__mlift2513_advance_fun3761(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2513_advance_fun3761(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_handlers__mlift2513_advance_fun3761, _ctx)
  return kk_function_dup(_fself);
}

static kk_unit_t kk_handlers__mlift2513_advance_fun3761(kk_function_t _fself, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return kk_Unit;
}


// lift anonymous function
struct kk_handlers__mlift2513_advance_fun3763__t {
  struct kk_function_s _base;
  kk_function_t _bv_2803;
};
static kk_function_t kk_handlers__mlift2513_advance_fun3763(kk_function_t _fself, kk_function_t _b_2804, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2513_advance_fun3763(kk_function_t _bv_2803, kk_context_t* _ctx) {
  struct kk_handlers__mlift2513_advance_fun3763__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2513_advance_fun3763__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2513_advance_fun3763, kk_context());
  _self->_bv_2803 = _bv_2803;
  return &_self->_base;
}



// lift anonymous function
struct kk_handlers__mlift2513_advance_fun3765__t {
  struct kk_function_s _base;
  kk_function_t _b_2804;
};
static kk_box_t kk_handlers__mlift2513_advance_fun3765(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2513_advance_fun3765(kk_function_t _b_2804, kk_context_t* _ctx) {
  struct kk_handlers__mlift2513_advance_fun3765__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2513_advance_fun3765__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2513_advance_fun3765, kk_context());
  _self->_b_2804 = _b_2804;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift2513_advance_fun3765(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_handlers__mlift2513_advance_fun3765__t* _self = kk_function_as(struct kk_handlers__mlift2513_advance_fun3765__t*, _fself);
  kk_function_t _b_2804 = _self->_b_2804; /* () -> () */
  kk_drop_match(_self, {kk_function_dup(_b_2804);}, {}, _ctx)
  kk_unit_t _x3766 = kk_Unit;
  kk_function_call(kk_unit_t, (kk_function_t, kk_context_t*), _b_2804, (_b_2804, _ctx));
  return kk_unit_box(_x3766);
}


// lift anonymous function
struct kk_handlers__mlift2513_advance_fun3767__t {
  struct kk_function_s _base;
  kk_function_t _bv_2807;
};
static kk_box_t kk_handlers__mlift2513_advance_fun3767(kk_function_t _fself, kk_integer_t _b_2808, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2513_advance_fun3767(kk_function_t _bv_2807, kk_context_t* _ctx) {
  struct kk_handlers__mlift2513_advance_fun3767__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2513_advance_fun3767__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2513_advance_fun3767, kk_context());
  _self->_bv_2807 = _bv_2807;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift2513_advance_fun3767(kk_function_t _fself, kk_integer_t _b_2808, kk_context_t* _ctx) {
  struct kk_handlers__mlift2513_advance_fun3767__t* _self = kk_function_as(struct kk_handlers__mlift2513_advance_fun3767__t*, _fself);
  kk_function_t _bv_2807 = _self->_bv_2807; /* (2805) -> <.Box|.Box> 2806 */
  kk_drop_match(_self, {kk_function_dup(_bv_2807);}, {}, _ctx)
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _bv_2807, (_bv_2807, kk_integer_box(_b_2808), _ctx));
}
static kk_function_t kk_handlers__mlift2513_advance_fun3763(kk_function_t _fself, kk_function_t _b_2804, kk_context_t* _ctx) {
  struct kk_handlers__mlift2513_advance_fun3763__t* _self = kk_function_as(struct kk_handlers__mlift2513_advance_fun3763__t*, _fself);
  kk_function_t _bv_2803 = _self->_bv_2803; /* (() -> 2806) -> 2807 2808 */
  kk_drop_match(_self, {kk_function_dup(_bv_2803);}, {}, _ctx)
  kk_function_t _bv_2807;
  kk_box_t _x3764 = kk_function_call(kk_box_t, (kk_function_t, kk_function_t, kk_context_t*), _bv_2803, (_bv_2803, kk_handlers__new_mlift2513_advance_fun3765(_b_2804, _ctx), _ctx)); /*2808*/
  _bv_2807 = kk_function_unbox(_x3764); /*(2805) -> <.Box|.Box> 2806*/
  return kk_handlers__new_mlift2513_advance_fun3767(_bv_2807, _ctx);
}


// lift anonymous function
struct kk_handlers__mlift2513_advance_fun3769__t {
  struct kk_function_s _base;
  size_t _y_5;
};
static kk_box_t kk_handlers__mlift2513_advance_fun3769(kk_function_t _fself, kk_function_t _b_2830, kk_box_t _b_2831, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2513_advance_fun3769(size_t _y_5, kk_context_t* _ctx) {
  struct kk_handlers__mlift2513_advance_fun3769__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2513_advance_fun3769__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2513_advance_fun3769, kk_context());
  _self->_y_5 = _y_5;
  return &_self->_base;
}



// lift anonymous function
struct kk_handlers__mlift2513_advance_fun3772__t {
  struct kk_function_s _base;
  kk_function_t _b_2830;
};
static kk_box_t kk_handlers__mlift2513_advance_fun3772(kk_function_t _fself, kk_box_t _b_2814, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2513_advance_fun3772(kk_function_t _b_2830, kk_context_t* _ctx) {
  struct kk_handlers__mlift2513_advance_fun3772__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2513_advance_fun3772__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2513_advance_fun3772, kk_context());
  _self->_b_2830 = _b_2830;
  return &_self->_base;
}



// lift anonymous function
struct kk_handlers__mlift2513_advance_fun3775__t {
  struct kk_function_s _base;
  kk_box_t _b_2814;
};
static kk_box_t kk_handlers__mlift2513_advance_fun3775(kk_function_t _fself, kk_box_t _b_2835, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2513_advance_fun3775(kk_box_t _b_2814, kk_context_t* _ctx) {
  struct kk_handlers__mlift2513_advance_fun3775__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2513_advance_fun3775__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2513_advance_fun3775, kk_context());
  _self->_b_2814 = _b_2814;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift2513_advance_fun3775(kk_function_t _fself, kk_box_t _b_2835, kk_context_t* _ctx) {
  struct kk_handlers__mlift2513_advance_fun3775__t* _self = kk_function_as(struct kk_handlers__mlift2513_advance_fun3775__t*, _fself);
  kk_box_t _b_2814 = _self->_b_2814; /* 4674 */
  kk_drop_match(_self, {kk_box_dup(_b_2814);}, {}, _ctx)
  kk_function_t _x3776 = kk_function_unbox(_b_2814); /*(2815) -> <effects-and-types/yield|270> 2816*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x3776, (_x3776, _b_2835, _ctx));
}


// lift anonymous function
struct kk_handlers__mlift2513_advance_fun3777__t {
  struct kk_function_s _base;
  kk_function_t _bv_2838;
};
static kk_box_t kk_handlers__mlift2513_advance_fun3777(kk_function_t _fself, kk_integer_t _b_2839, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2513_advance_fun3777(kk_function_t _bv_2838, kk_context_t* _ctx) {
  struct kk_handlers__mlift2513_advance_fun3777__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2513_advance_fun3777__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2513_advance_fun3777, kk_context());
  _self->_bv_2838 = _bv_2838;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift2513_advance_fun3777(kk_function_t _fself, kk_integer_t _b_2839, kk_context_t* _ctx) {
  struct kk_handlers__mlift2513_advance_fun3777__t* _self = kk_function_as(struct kk_handlers__mlift2513_advance_fun3777__t*, _fself);
  kk_function_t _bv_2838 = _self->_bv_2838; /* (2836) -> <effects-and-types/yield|270> 2837 */
  kk_drop_match(_self, {kk_function_dup(_bv_2838);}, {}, _ctx)
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _bv_2838, (_bv_2838, kk_integer_box(_b_2839), _ctx));
}


// lift anonymous function
struct kk_handlers__mlift2513_advance_fun3778__t {
  struct kk_function_s _base;
  kk_function_t _bv_2820;
};
static kk_box_t kk_handlers__mlift2513_advance_fun3778(kk_function_t _fself, kk_box_t _b_2821, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2513_advance_fun3778(kk_function_t _bv_2820, kk_context_t* _ctx) {
  struct kk_handlers__mlift2513_advance_fun3778__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2513_advance_fun3778__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2513_advance_fun3778, kk_context());
  _self->_bv_2820 = _bv_2820;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift2513_advance_fun3778(kk_function_t _fself, kk_box_t _b_2821, kk_context_t* _ctx) {
  struct kk_handlers__mlift2513_advance_fun3778__t* _self = kk_function_as(struct kk_handlers__mlift2513_advance_fun3778__t*, _fself);
  kk_function_t _bv_2820 = _self->_bv_2820; /* (int) -> <effects-and-types/yield|270> 269 */
  kk_drop_match(_self, {kk_function_dup(_bv_2820);}, {}, _ctx)
  kk_integer_t _x3779 = kk_integer_unbox(_b_2821); /*int*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_context_t*), _bv_2820, (_bv_2820, _x3779, _ctx));
}
static kk_box_t kk_handlers__mlift2513_advance_fun3772(kk_function_t _fself, kk_box_t _b_2814, kk_context_t* _ctx) {
  struct kk_handlers__mlift2513_advance_fun3772__t* _self = kk_function_as(struct kk_handlers__mlift2513_advance_fun3772__t*, _fself);
  kk_function_t _b_2830 = _self->_b_2830; /* (3818) -> 3819 3818 */
  kk_drop_match(_self, {kk_function_dup(_b_2830);}, {}, _ctx)
  kk_function_t _x3773;
  kk_function_t _bv_2820;
  kk_function_t _bv_2838;
  kk_box_t _x3774 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _b_2830, (_b_2830, kk_function_box(kk_handlers__new_mlift2513_advance_fun3775(_b_2814, _ctx)), _ctx)); /*3818*/
  _bv_2838 = kk_function_unbox(_x3774); /*(2836) -> <effects-and-types/yield|270> 2837*/
  _bv_2820 = kk_handlers__new_mlift2513_advance_fun3777(_bv_2838, _ctx); /*(int) -> <effects-and-types/yield|270> 269*/
  _x3773 = kk_handlers__new_mlift2513_advance_fun3778(_bv_2820, _ctx); /*(2818) -> <effects-and-types/yield|270> 269*/
  return kk_function_box(_x3773);
}


// lift anonymous function
struct kk_handlers__mlift2513_advance_fun3780__t {
  struct kk_function_s _base;
  kk_box_t _b_2831;
};
static kk_box_t kk_handlers__mlift2513_advance_fun3780(kk_function_t _fself, kk_box_t _b_2824, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2513_advance_fun3780(kk_box_t _b_2831, kk_context_t* _ctx) {
  struct kk_handlers__mlift2513_advance_fun3780__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2513_advance_fun3780__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2513_advance_fun3780, kk_context());
  _self->_b_2831 = _b_2831;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift2513_advance_fun3780(kk_function_t _fself, kk_box_t _b_2824, kk_context_t* _ctx) {
  struct kk_handlers__mlift2513_advance_fun3780__t* _self = kk_function_as(struct kk_handlers__mlift2513_advance_fun3780__t*, _fself);
  kk_box_t _b_2831 = _self->_b_2831; /* 3818 */
  kk_drop_match(_self, {kk_box_dup(_b_2831);}, {}, _ctx)
  kk_function_t _x3781 = kk_function_unbox(_b_2831); /*(2840) -> <effects-and-types/yield|270> 2841*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x3781, (_x3781, _b_2824, _ctx));
}


// lift anonymous function
struct kk_handlers__mlift2513_advance_fun3782__t {
  struct kk_function_s _base;
  kk_function_t _bv_2827;
};
static kk_box_t kk_handlers__mlift2513_advance_fun3782(kk_function_t _fself, kk_integer_t _b_2828, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2513_advance_fun3782(kk_function_t _bv_2827, kk_context_t* _ctx) {
  struct kk_handlers__mlift2513_advance_fun3782__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2513_advance_fun3782__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2513_advance_fun3782, kk_context());
  _self->_bv_2827 = _bv_2827;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift2513_advance_fun3782(kk_function_t _fself, kk_integer_t _b_2828, kk_context_t* _ctx) {
  struct kk_handlers__mlift2513_advance_fun3782__t* _self = kk_function_as(struct kk_handlers__mlift2513_advance_fun3782__t*, _fself);
  kk_function_t _bv_2827 = _self->_bv_2827; /* (2825) -> <effects-and-types/yield|270> 2826 */
  kk_drop_match(_self, {kk_function_dup(_bv_2827);}, {}, _ctx)
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _bv_2827, (_bv_2827, kk_integer_box(_b_2828), _ctx));
}


// lift anonymous function
struct kk_handlers__mlift2513_advance_fun3783__t {
  struct kk_function_s _base;
  kk_function_t _bv_2845;
};
static kk_box_t kk_handlers__mlift2513_advance_fun3783(kk_function_t _fself, kk_box_t _b_2846, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2513_advance_fun3783(kk_function_t _bv_2845, kk_context_t* _ctx) {
  struct kk_handlers__mlift2513_advance_fun3783__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2513_advance_fun3783__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2513_advance_fun3783, kk_context());
  _self->_bv_2845 = _bv_2845;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift2513_advance_fun3783(kk_function_t _fself, kk_box_t _b_2846, kk_context_t* _ctx) {
  struct kk_handlers__mlift2513_advance_fun3783__t* _self = kk_function_as(struct kk_handlers__mlift2513_advance_fun3783__t*, _fself);
  kk_function_t _bv_2845 = _self->_bv_2845; /* (int) -> <effects-and-types/yield|270> 269 */
  kk_drop_match(_self, {kk_function_dup(_bv_2845);}, {}, _ctx)
  kk_integer_t _x3784 = kk_integer_unbox(_b_2846); /*int*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_context_t*), _bv_2845, (_bv_2845, _x3784, _ctx));
}
static kk_box_t kk_handlers__mlift2513_advance_fun3769(kk_function_t _fself, kk_function_t _b_2830, kk_box_t _b_2831, kk_context_t* _ctx) {
  struct kk_handlers__mlift2513_advance_fun3769__t* _self = kk_function_as(struct kk_handlers__mlift2513_advance_fun3769__t*, _fself);
  size_t _y_5 = _self->_y_5; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  kk_function_t _x3770;
  kk_function_t _bv_2845;
  kk_function_t _bv_2827;
  kk_box_t _x3771 = kk_std_core_hnd_mask_at1(_y_5, false, kk_handlers__new_mlift2513_advance_fun3772(_b_2830, _ctx), kk_function_box(kk_handlers__new_mlift2513_advance_fun3780(_b_2831, _ctx)), _ctx); /*4675*/
  _bv_2827 = kk_function_unbox(_x3771); /*(2825) -> <effects-and-types/yield|270> 2826*/
  _bv_2845 = kk_handlers__new_mlift2513_advance_fun3782(_bv_2827, _ctx); /*(int) -> <effects-and-types/yield|270> 269*/
  _x3770 = kk_handlers__new_mlift2513_advance_fun3783(_bv_2845, _ctx); /*(2843) -> <effects-and-types/yield|270> 269*/
  return kk_function_box(_x3770);
}


// lift anonymous function
struct kk_handlers__mlift2513_advance_fun3785__t {
  struct kk_function_s _base;
  kk_function_t _bv_2849;
};
static kk_box_t kk_handlers__mlift2513_advance_fun3785(kk_function_t _fself, kk_integer_t _b_2850, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2513_advance_fun3785(kk_function_t _bv_2849, kk_context_t* _ctx) {
  struct kk_handlers__mlift2513_advance_fun3785__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2513_advance_fun3785__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2513_advance_fun3785, kk_context());
  _self->_bv_2849 = _bv_2849;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift2513_advance_fun3785(kk_function_t _fself, kk_integer_t _b_2850, kk_context_t* _ctx) {
  struct kk_handlers__mlift2513_advance_fun3785__t* _self = kk_function_as(struct kk_handlers__mlift2513_advance_fun3785__t*, _fself);
  kk_function_t _bv_2849 = _self->_bv_2849; /* (2847) -> <.Box|.Box> 2848 */
  kk_drop_match(_self, {kk_function_dup(_bv_2849);}, {}, _ctx)
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _bv_2849, (_bv_2849, kk_integer_box(_b_2850), _ctx));
}


// lift anonymous function
struct kk_handlers__mlift2513_advance_fun3786__t {
  struct kk_function_s _base;
};
static kk_box_t kk_handlers__mlift2513_advance_fun3786(kk_function_t _fself, kk_box_t _b_2862, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2513_advance_fun3786(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_handlers__mlift2513_advance_fun3786, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_handlers__mlift2513_advance_fun3787__t {
  struct kk_function_s _base;
  kk_box_t _b_2862;
};
static kk_box_t kk_handlers__mlift2513_advance_fun3787(kk_function_t _fself, kk_integer_t _b_2865, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2513_advance_fun3787(kk_box_t _b_2862, kk_context_t* _ctx) {
  struct kk_handlers__mlift2513_advance_fun3787__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2513_advance_fun3787__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2513_advance_fun3787, kk_context());
  _self->_b_2862 = _b_2862;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift2513_advance_fun3787(kk_function_t _fself, kk_integer_t _b_2865, kk_context_t* _ctx) {
  struct kk_handlers__mlift2513_advance_fun3787__t* _self = kk_function_as(struct kk_handlers__mlift2513_advance_fun3787__t*, _fself);
  kk_box_t _b_2862 = _self->_b_2862; /* 3990 */
  kk_drop_match(_self, {kk_box_dup(_b_2862);}, {}, _ctx)
  kk_function_t _x3788 = kk_function_unbox(_b_2862); /*(2863) -> <effects-and-types/yield|270> 2864*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x3788, (_x3788, kk_integer_box(_b_2865), _ctx));
}
static kk_box_t kk_handlers__mlift2513_advance_fun3786(kk_function_t _fself, kk_box_t _b_2862, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return kk_handlers__mlift2512_advance(kk_handlers__new_mlift2513_advance_fun3787(_b_2862, _ctx), _ctx);
}

kk_box_t kk_handlers__mlift2513_advance(kk_std_core_hnd__resume_context rcontext, size_t _y_5, kk_context_t* _ctx) { /* forall<a,e> (rcontext : std/core/hnd/resume-context<(),e,(int) -> <effects-and-types/yield|e> a>, std/core/hnd/ev-index) -> <effects-and-types/yield|e> a */ 
  kk_function_t x_2550;
  kk_evv_t w0 = kk_std_core_hnd_evv_swap_delete(_y_5, false, _ctx); /*std/core/hnd/evv<_4681>*/;
  kk_function_t x0;
  kk_function_t _x3762;
  kk_function_t _bv_2803 = kk_std_core_hnd_k(rcontext, _ctx); /*(() -> 2806) -> 2807 2808*/;
  _x3762 = kk_handlers__new_mlift2513_advance_fun3763(_bv_2803, _ctx); /*(() -> ()) -> ((int) -> <.Box|.Box> 2806)*/
  x0 = kk_function_call(kk_function_t, (kk_function_t, kk_function_t, kk_context_t*), _x3762, (_x3762, kk_handlers__new_mlift2513_advance_fun3761(_ctx), _ctx)); /*(int) -> <effects-and-types/yield|270> 269*/
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w0,kk_context());
  if (kk_yielding(kk_context())) {
    kk_function_drop(x0, _ctx);
    kk_function_t _bv_2849;
    kk_box_t _x3768 = kk_std_core_hnd_yield_cont(kk_handlers__new_mlift2513_advance_fun3769(_y_5, _ctx), _ctx); /*3820*/
    _bv_2849 = kk_function_unbox(_x3768); /*(2847) -> <.Box|.Box> 2848*/
    x_2550 = kk_handlers__new_mlift2513_advance_fun3785(_bv_2849, _ctx); /*(int) -> <effects-and-types/yield|270> 269*/
  }
  else {
    x_2550 = x0; /*(int) -> <effects-and-types/yield|270> 269*/
  }
  if (kk_yielding(kk_context())) {
    kk_function_drop(x_2550, _ctx);
    return kk_std_core_hnd_yield_extend(kk_handlers__new_mlift2513_advance_fun3786(_ctx), _ctx);
  }
  return kk_handlers__mlift2512_advance(x_2550, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_handlers__mlift2514_advance_fun3790__t {
  struct kk_function_s _base;
  kk_std_core_hnd__resume_context rcontext;
};
static kk_box_t kk_handlers__mlift2514_advance_fun3790(kk_function_t _fself, kk_box_t _b_2869, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2514_advance_fun3790(kk_std_core_hnd__resume_context rcontext, kk_context_t* _ctx) {
  struct kk_handlers__mlift2514_advance_fun3790__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2514_advance_fun3790__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2514_advance_fun3790, kk_context());
  _self->rcontext = rcontext;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift2514_advance_fun3790(kk_function_t _fself, kk_box_t _b_2869, kk_context_t* _ctx) {
  struct kk_handlers__mlift2514_advance_fun3790__t* _self = kk_function_as(struct kk_handlers__mlift2514_advance_fun3790__t*, _fself);
  kk_std_core_hnd__resume_context rcontext = _self->rcontext; /* std/core/hnd/resume-context<(),270,(int) -> <effects-and-types/yield|270> 269> */
  kk_drop_match(_self, {kk_std_core_hnd__resume_context_dup(rcontext);}, {}, _ctx)
  size_t _x3791 = kk_size_unbox(_b_2869, _ctx); /*std/core/hnd/ev-index*/
  return kk_handlers__mlift2513_advance(rcontext, _x3791, _ctx);
}

kk_box_t kk_handlers__mlift2514_advance(kk_std_core_hnd__resume_context rcontext, kk_unit_t wild__, kk_context_t* _ctx) { /* forall<a,e> (rcontext : std/core/hnd/resume-context<(),e,(int) -> <effects-and-types/yield|e> a>, wild_ : ()) -> <effects-and-types/yield|e> a */ 
  size_t x_2557;
  kk_std_core_hnd__htag _x3789 = kk_std_core_hnd__htag_dup(kk_effects_dash_and_dash_types__tag_yield); /*std/core/hnd/htag<effects-and-types/.hnd-yield>*/
  x_2557 = kk_std_core_hnd__evv_index(_x3789, _ctx); /*std/core/hnd/ev-index*/
  if (kk_yielding(kk_context())) {
    return kk_std_core_hnd_yield_extend(kk_handlers__new_mlift2514_advance_fun3790(rcontext, _ctx), _ctx);
  }
  return kk_handlers__mlift2513_advance(rcontext, x_2557, _ctx);
}


// lift anonymous function
struct kk_handlers_advance_fun3793__t {
  struct kk_function_s _base;
};
static kk_box_t kk_handlers_advance_fun3793(kk_function_t _fself, kk_std_core_hnd__marker _b_2919, kk_std_core_hnd__ev _b_2920, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_advance_fun3793(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_handlers_advance_fun3793, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_handlers_advance_fun3794__t {
  struct kk_function_s _base;
};
static kk_box_t kk_handlers_advance_fun3794(kk_function_t _fself, kk_function_t _b_2908, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_advance_fun3794(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_handlers_advance_fun3794, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_handlers_advance_fun3796__t {
  struct kk_function_s _base;
  kk_function_t _b_2908;
};
static kk_box_t kk_handlers_advance_fun3796(kk_function_t _fself, kk_function_t _b_2873, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_advance_fun3796(kk_function_t _b_2908, kk_context_t* _ctx) {
  struct kk_handlers_advance_fun3796__t* _self = kk_function_alloc_as(struct kk_handlers_advance_fun3796__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_advance_fun3796, kk_context());
  _self->_b_2908 = _b_2908;
  return &_self->_base;
}



// lift anonymous function
struct kk_handlers_advance_fun3799__t {
  struct kk_function_s _base;
  kk_function_t _bv_2912;
};
static kk_box_t kk_handlers_advance_fun3799(kk_function_t _fself, kk_integer_t _b_2913, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_advance_fun3799(kk_function_t _bv_2912, kk_context_t* _ctx) {
  struct kk_handlers_advance_fun3799__t* _self = kk_function_alloc_as(struct kk_handlers_advance_fun3799__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_advance_fun3799, kk_context());
  _self->_bv_2912 = _bv_2912;
  return &_self->_base;
}

static kk_box_t kk_handlers_advance_fun3799(kk_function_t _fself, kk_integer_t _b_2913, kk_context_t* _ctx) {
  struct kk_handlers_advance_fun3799__t* _self = kk_function_as(struct kk_handlers_advance_fun3799__t*, _fself);
  kk_function_t _bv_2912 = _self->_bv_2912; /* (2910) -> <effects-and-types/yield|270> 2911 */
  kk_drop_match(_self, {kk_function_dup(_bv_2912);}, {}, _ctx)
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _bv_2912, (_bv_2912, kk_integer_box(_b_2913), _ctx));
}


// lift anonymous function
struct kk_handlers_advance_fun3800__t {
  struct kk_function_s _base;
  kk_function_t _bv_2876;
};
static kk_box_t kk_handlers_advance_fun3800(kk_function_t _fself, kk_box_t _b_2877, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_advance_fun3800(kk_function_t _bv_2876, kk_context_t* _ctx) {
  struct kk_handlers_advance_fun3800__t* _self = kk_function_alloc_as(struct kk_handlers_advance_fun3800__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_advance_fun3800, kk_context());
  _self->_bv_2876 = _bv_2876;
  return &_self->_base;
}

static kk_box_t kk_handlers_advance_fun3800(kk_function_t _fself, kk_box_t _b_2877, kk_context_t* _ctx) {
  struct kk_handlers_advance_fun3800__t* _self = kk_function_as(struct kk_handlers_advance_fun3800__t*, _fself);
  kk_function_t _bv_2876 = _self->_bv_2876; /* (int) -> <effects-and-types/yield|270> 269 */
  kk_drop_match(_self, {kk_function_dup(_bv_2876);}, {}, _ctx)
  kk_integer_t _x3801 = kk_integer_unbox(_b_2877); /*int*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_context_t*), _bv_2876, (_bv_2876, _x3801, _ctx));
}
static kk_box_t kk_handlers_advance_fun3796(kk_function_t _fself, kk_function_t _b_2873, kk_context_t* _ctx) {
  struct kk_handlers_advance_fun3796__t* _self = kk_function_as(struct kk_handlers_advance_fun3796__t*, _fself);
  kk_function_t _b_2908 = _self->_b_2908; /* (() -> 6146) -> 6147 6148 */
  kk_drop_match(_self, {kk_function_dup(_b_2908);}, {}, _ctx)
  kk_function_t _x3797;
  kk_function_t _bv_2876;
  kk_function_t _bv_2912;
  kk_box_t _x3798 = kk_function_call(kk_box_t, (kk_function_t, kk_function_t, kk_context_t*), _b_2908, (_b_2908, _b_2873, _ctx)); /*6148*/
  _bv_2912 = kk_function_unbox(_x3798); /*(2910) -> <effects-and-types/yield|270> 2911*/
  _bv_2876 = kk_handlers_new_advance_fun3799(_bv_2912, _ctx); /*(int) -> <effects-and-types/yield|270> 269*/
  _x3797 = kk_handlers_new_advance_fun3800(_bv_2876, _ctx); /*(2874) -> <effects-and-types/yield|270> 269*/
  return kk_function_box(_x3797);
}


// lift anonymous function
struct kk_handlers_advance_fun3802__t {
  struct kk_function_s _base;
  kk_std_core_hnd__resume_context rcontext_2560;
};
static kk_box_t kk_handlers_advance_fun3802(kk_function_t _fself, kk_integer_t steps, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_advance_fun3802(kk_std_core_hnd__resume_context rcontext_2560, kk_context_t* _ctx) {
  struct kk_handlers_advance_fun3802__t* _self = kk_function_alloc_as(struct kk_handlers_advance_fun3802__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_advance_fun3802, kk_context());
  _self->rcontext_2560 = rcontext_2560;
  return &_self->_base;
}



// lift anonymous function
struct kk_handlers_advance_fun3805__t {
  struct kk_function_s _base;
  kk_std_core_hnd__resume_context rcontext_2560;
  kk_integer_t steps;
};
static kk_box_t kk_handlers_advance_fun3805(kk_function_t _fself, kk_box_t _b_2880, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_advance_fun3805(kk_std_core_hnd__resume_context rcontext_2560, kk_integer_t steps, kk_context_t* _ctx) {
  struct kk_handlers_advance_fun3805__t* _self = kk_function_alloc_as(struct kk_handlers_advance_fun3805__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_advance_fun3805, kk_context());
  _self->rcontext_2560 = rcontext_2560;
  _self->steps = steps;
  return &_self->_base;
}

static kk_box_t kk_handlers_advance_fun3805(kk_function_t _fself, kk_box_t _b_2880, kk_context_t* _ctx) {
  struct kk_handlers_advance_fun3805__t* _self = kk_function_as(struct kk_handlers_advance_fun3805__t*, _fself);
  kk_std_core_hnd__resume_context rcontext_2560 = _self->rcontext_2560; /* std/core/hnd/resume-context<(),270,(int) -> <effects-and-types/yield|270> 269> */
  kk_integer_t steps = _self->steps; /* int */
  kk_drop_match(_self, {kk_std_core_hnd__resume_context_dup(rcontext_2560);kk_integer_dup(steps);}, {}, _ctx)
  size_t _x3806 = kk_size_unbox(_b_2880, _ctx); /*std/core/hnd/ev-index*/
  return kk_handlers__mlift2511_advance(rcontext_2560, steps, _x3806, _ctx);
}


// lift anonymous function
struct kk_handlers_advance_fun3814__t {
  struct kk_function_s _base;
  size_t i_2565;
};
static kk_box_t kk_handlers_advance_fun3814(kk_function_t _fself, kk_function_t _b_2894, kk_box_t _b_2895, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_advance_fun3814(size_t i_2565, kk_context_t* _ctx) {
  struct kk_handlers_advance_fun3814__t* _self = kk_function_alloc_as(struct kk_handlers_advance_fun3814__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_advance_fun3814, kk_context());
  _self->i_2565 = i_2565;
  return &_self->_base;
}

static kk_box_t kk_handlers_advance_fun3814(kk_function_t _fself, kk_function_t _b_2894, kk_box_t _b_2895, kk_context_t* _ctx) {
  struct kk_handlers_advance_fun3814__t* _self = kk_function_as(struct kk_handlers_advance_fun3814__t*, _fself);
  size_t i_2565 = _self->i_2565; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_2565, _b_2894, _b_2895, _ctx);
}


// lift anonymous function
struct kk_handlers_advance_fun3815__t {
  struct kk_function_s _base;
  kk_std_core_hnd__resume_context rcontext_2560;
};
static kk_box_t kk_handlers_advance_fun3815(kk_function_t _fself, kk_box_t _b_2905, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_advance_fun3815(kk_std_core_hnd__resume_context rcontext_2560, kk_context_t* _ctx) {
  struct kk_handlers_advance_fun3815__t* _self = kk_function_alloc_as(struct kk_handlers_advance_fun3815__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_advance_fun3815, kk_context());
  _self->rcontext_2560 = rcontext_2560;
  return &_self->_base;
}

static kk_box_t kk_handlers_advance_fun3815(kk_function_t _fself, kk_box_t _b_2905, kk_context_t* _ctx) {
  struct kk_handlers_advance_fun3815__t* _self = kk_function_as(struct kk_handlers_advance_fun3815__t*, _fself);
  kk_std_core_hnd__resume_context rcontext_2560 = _self->rcontext_2560; /* std/core/hnd/resume-context<(),270,(int) -> <effects-and-types/yield|270> 269> */
  kk_drop_match(_self, {kk_std_core_hnd__resume_context_dup(rcontext_2560);}, {}, _ctx)
  kk_unit_t _x3816 = kk_Unit;
  kk_unit_unbox(_b_2905);
  return kk_handlers__mlift2514_advance(rcontext_2560, _x3816, _ctx);
}
static kk_box_t kk_handlers_advance_fun3802(kk_function_t _fself, kk_integer_t steps, kk_context_t* _ctx) {
  struct kk_handlers_advance_fun3802__t* _self = kk_function_as(struct kk_handlers_advance_fun3802__t*, _fself);
  kk_std_core_hnd__resume_context rcontext_2560 = _self->rcontext_2560; /* std/core/hnd/resume-context<(),270,(int) -> <effects-and-types/yield|270> 269> */
  kk_drop_match(_self, {kk_std_core_hnd__resume_context_dup(rcontext_2560);}, {}, _ctx)
  bool _match_3722;
  kk_integer_t _x3803 = kk_integer_dup(steps); /*int*/
  _match_3722 = kk_integer_gt(_x3803,(kk_integer_from_small(0)),kk_context()); /*bool*/
  if (_match_3722) {
    size_t x_2561;
    kk_std_core_hnd__htag _x3804 = kk_std_core_hnd__htag_dup(kk_effects_dash_and_dash_types__tag_yield); /*std/core/hnd/htag<effects-and-types/.hnd-yield>*/
    x_2561 = kk_std_core_hnd__evv_index(_x3804, _ctx); /*std/core/hnd/ev-index*/
    if (kk_yielding(kk_context())) {
      return kk_std_core_hnd_yield_extend(kk_handlers_new_advance_fun3805(rcontext_2560, steps, _ctx), _ctx);
    }
    return kk_handlers__mlift2511_advance(rcontext_2560, steps, x_2561, _ctx);
  }
  kk_integer_drop(steps, _ctx);
  kk_unit_t x0_2563 = kk_Unit;
  size_t i_2565;
  kk_std_core_hnd__htag _x3807 = kk_std_core_hnd__htag_dup(kk_effects_dash_and_dash_types__tag_yield); /*std/core/hnd/htag<effects-and-types/.hnd-yield>*/
  i_2565 = kk_std_core_hnd__evv_index(_x3807, _ctx); /*std/core/hnd/ev-index*/
  kk_evv_t w = kk_evv_swap_create1(i_2565,kk_context()); /*std/core/hnd/evv<<effects-and-types/yield|270>>*/;
  kk_unit_t y = kk_Unit;
  kk_std_core_hnd__ev ev_409;
  size_t _x3808 = ((size_t)0); /*size_t*/
  ev_409 = kk_evv_at(_x3808,kk_context()); /*std/core/hnd/ev<effects-and-types/.hnd-yield>*/
  kk_box_t _x3809;
  struct kk_std_core_hnd_Ev* _con3810 = kk_std_core_hnd__as_Ev(ev_409);
  kk_std_core_hnd__marker m0 = _con3810->marker;
  kk_box_t _box_x2881 = _con3810->hnd;
  kk_effects_dash_and_dash_types__hnd_yield h = kk_effects_dash_and_dash_types__hnd_yield_unbox(_box_x2881, NULL);
  kk_effects_dash_and_dash_types__hnd_yield_dup(h);
  kk_std_core_hnd__clause0 _match_3725;
  struct kk_effects_dash_and_dash_types__Hnd_yield* _con3812 = kk_effects_dash_and_dash_types__as_Hnd_yield(h);
  kk_std_core_hnd__clause0 control_yield = _con3812->control_yield;
  if (kk_effects_dash_and_dash_types__hnd_yield_is_unique(h)) {
    kk_effects_dash_and_dash_types__hnd_yield_free(h);
  }
  else {
    kk_std_core_hnd__clause0_dup(control_yield);
    kk_effects_dash_and_dash_types__hnd_yield_decref(h, _ctx);
  }
  _match_3725 = control_yield; /*std/core/hnd/clause0<(),effects-and-types/.hnd-yield,3435,3436>*/
  kk_function_t _fun_unbox_x2884 = _match_3725.clause;
  _x3809 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x2884, (_fun_unbox_x2884, m0, ev_409, _ctx)); /*37*/
  kk_unit_unbox(_x3809);
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x3813 = kk_std_core_hnd_yield_cont(kk_handlers_new_advance_fun3814(i_2565, _ctx), _ctx); /*3820*/
    kk_unit_unbox(_x3813);
  }
  else {
    y;
  }
  if (kk_yielding(kk_context())) {
    return kk_std_core_hnd_yield_extend(kk_handlers_new_advance_fun3815(rcontext_2560, _ctx), _ctx);
  }
  return kk_handlers__mlift2514_advance(rcontext_2560, x0_2563, _ctx);
}


// lift anonymous function
struct kk_handlers_advance_fun3817__t {
  struct kk_function_s _base;
  kk_function_t _bv_2916;
};
static kk_box_t kk_handlers_advance_fun3817(kk_function_t _fself, kk_box_t _b_2917, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_advance_fun3817(kk_function_t _bv_2916, kk_context_t* _ctx) {
  struct kk_handlers_advance_fun3817__t* _self = kk_function_alloc_as(struct kk_handlers_advance_fun3817__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_advance_fun3817, kk_context());
  _self->_bv_2916 = _bv_2916;
  return &_self->_base;
}

static kk_box_t kk_handlers_advance_fun3817(kk_function_t _fself, kk_box_t _b_2917, kk_context_t* _ctx) {
  struct kk_handlers_advance_fun3817__t* _self = kk_function_as(struct kk_handlers_advance_fun3817__t*, _fself);
  kk_function_t _bv_2916 = _self->_bv_2916; /* (steps : int) -> <effects-and-types/yield|270> 269 */
  kk_drop_match(_self, {kk_function_dup(_bv_2916);}, {}, _ctx)
  kk_integer_t _x3818 = kk_integer_unbox(_b_2917); /*int*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_context_t*), _bv_2916, (_bv_2916, _x3818, _ctx));
}
static kk_box_t kk_handlers_advance_fun3794(kk_function_t _fself, kk_function_t _b_2908, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_function_t _x3795;
  kk_function_t _bv_2916;
  kk_std_core_hnd__resume_context rcontext_2560 = kk_std_core_hnd__new_Resume_context(kk_handlers_new_advance_fun3796(_b_2908, _ctx), _ctx); /*std/core/hnd/resume-context<(),270,(int) -> <effects-and-types/yield|270> 269>*/;
  _bv_2916 = kk_handlers_new_advance_fun3802(rcontext_2560, _ctx); /*(steps : int) -> <effects-and-types/yield|270> 269*/
  _x3795 = kk_handlers_new_advance_fun3817(_bv_2916, _ctx); /*(2914) -> <effects-and-types/yield|270> 269*/
  return kk_function_box(_x3795);
}
static kk_box_t kk_handlers_advance_fun3793(kk_function_t _fself, kk_std_core_hnd__marker _b_2919, kk_std_core_hnd__ev _b_2920, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core_hnd__ev_dropn(_b_2920, ((int32_t)3), _ctx);
  return kk_std_core_hnd_yield_to(_b_2919, kk_handlers_new_advance_fun3794(_ctx), _ctx);
}


// lift anonymous function
struct kk_handlers_advance_fun3820__t {
  struct kk_function_s _base;
};
static kk_box_t kk_handlers_advance_fun3820(kk_function_t _fself, kk_box_t _b_2925, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_advance_fun3820(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_handlers_advance_fun3820, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_handlers_advance_fun3822__t {
  struct kk_function_s _base;
  kk_box_t _b_2925;
};
static kk_box_t kk_handlers_advance_fun3822(kk_function_t _fself, kk_integer_t ___wildcard__101__21, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_advance_fun3822(kk_box_t _b_2925, kk_context_t* _ctx) {
  struct kk_handlers_advance_fun3822__t* _self = kk_function_alloc_as(struct kk_handlers_advance_fun3822__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_advance_fun3822, kk_context());
  _self->_b_2925 = _b_2925;
  return &_self->_base;
}

static kk_box_t kk_handlers_advance_fun3822(kk_function_t _fself, kk_integer_t ___wildcard__101__21, kk_context_t* _ctx) {
  struct kk_handlers_advance_fun3822__t* _self = kk_function_as(struct kk_handlers_advance_fun3822__t*, _fself);
  kk_box_t _b_2925 = _self->_b_2925; /* 281 */
  kk_drop_match(_self, {kk_box_dup(_b_2925);}, {}, _ctx)
  kk_integer_drop(___wildcard__101__21, _ctx);
  return _b_2925;
}


// lift anonymous function
struct kk_handlers_advance_fun3823__t {
  struct kk_function_s _base;
  kk_function_t _bv_2928;
};
static kk_box_t kk_handlers_advance_fun3823(kk_function_t _fself, kk_box_t _b_2929, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_advance_fun3823(kk_function_t _bv_2928, kk_context_t* _ctx) {
  struct kk_handlers_advance_fun3823__t* _self = kk_function_alloc_as(struct kk_handlers_advance_fun3823__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_advance_fun3823, kk_context());
  _self->_bv_2928 = _bv_2928;
  return &_self->_base;
}

static kk_box_t kk_handlers_advance_fun3823(kk_function_t _fself, kk_box_t _b_2929, kk_context_t* _ctx) {
  struct kk_handlers_advance_fun3823__t* _self = kk_function_as(struct kk_handlers_advance_fun3823__t*, _fself);
  kk_function_t _bv_2928 = _self->_bv_2928; /* (int) -> <effects-and-types/yield|270> 269 */
  kk_drop_match(_self, {kk_function_dup(_bv_2928);}, {}, _ctx)
  kk_integer_t _x3824 = kk_integer_unbox(_b_2929); /*int*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_context_t*), _bv_2928, (_bv_2928, _x3824, _ctx));
}
static kk_box_t kk_handlers_advance_fun3820(kk_function_t _fself, kk_box_t _b_2925, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_function_t _x3821;
  kk_function_t _bv_2928 = kk_handlers_new_advance_fun3822(_b_2925, _ctx); /*(int) -> <effects-and-types/yield|270> 269*/;
  _x3821 = kk_handlers_new_advance_fun3823(_bv_2928, _ctx); /*(2926) -> <effects-and-types/yield|270> 269*/
  return kk_function_box(_x3821);
}


// lift anonymous function
struct kk_handlers_advance_fun3825__t {
  struct kk_function_s _base;
  kk_function_t _bv_2932;
};
static kk_box_t kk_handlers_advance_fun3825(kk_function_t _fself, kk_integer_t _b_2933, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_advance_fun3825(kk_function_t _bv_2932, kk_context_t* _ctx) {
  struct kk_handlers_advance_fun3825__t* _self = kk_function_alloc_as(struct kk_handlers_advance_fun3825__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_advance_fun3825, kk_context());
  _self->_bv_2932 = _bv_2932;
  return &_self->_base;
}

static kk_box_t kk_handlers_advance_fun3825(kk_function_t _fself, kk_integer_t _b_2933, kk_context_t* _ctx) {
  struct kk_handlers_advance_fun3825__t* _self = kk_function_as(struct kk_handlers_advance_fun3825__t*, _fself);
  kk_function_t _bv_2932 = _self->_bv_2932; /* (2930) -> <effects-and-types/yield|270> 2931 */
  kk_drop_match(_self, {kk_function_dup(_bv_2932);}, {}, _ctx)
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _bv_2932, (_bv_2932, kk_integer_box(_b_2933), _ctx));
}

kk_function_t kk_handlers_advance(kk_function_t action, kk_context_t* _ctx) { /* forall<a,e> (action : () -> <effects-and-types/yield|e> a) -> e ((steps : int) -> <effects-and-types/yield|e> a) */ 
  int32_t _b_2934_2921 = ((int32_t)3); /*int32*/;
  kk_effects_dash_and_dash_types__hnd_yield _b_2935_2922;
  kk_std_core_hnd__clause0 _x3792 = kk_std_core_hnd__new_Clause0(kk_handlers_new_advance_fun3793(_ctx), _ctx); /*std/core/hnd/clause0<37,38,39,40>*/
  _b_2935_2922 = kk_effects_dash_and_dash_types__new_Hnd_yield(kk_reuse_null, _x3792, _ctx); /*effects-and-types/.hnd-yield<270,(int) -> <effects-and-types/yield|270> 269>*/
  kk_function_t _bv_2932;
  kk_box_t _x3819 = kk_effects_dash_and_dash_types__handle_yield(_b_2934_2921, _b_2935_2922, kk_handlers_new_advance_fun3820(_ctx), action, _ctx); /*283*/
  _bv_2932 = kk_function_unbox(_x3819); /*(2930) -> <effects-and-types/yield|270> 2931*/
  return kk_handlers_new_advance_fun3825(_bv_2932, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_handlers__mlift2515_advance_fun_fun3826__t {
  struct kk_function_s _base;
};
static kk_unit_t kk_handlers__mlift2515_advance_fun_fun3826(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2515_advance_fun_fun3826(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_handlers__mlift2515_advance_fun_fun3826, _ctx)
  return kk_function_dup(_fself);
}

static kk_unit_t kk_handlers__mlift2515_advance_fun_fun3826(kk_function_t _fself, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return kk_Unit;
}


// lift anonymous function
struct kk_handlers__mlift2515_advance_fun_fun3828__t {
  struct kk_function_s _base;
  kk_function_t _bv_2951;
};
static kk_box_t kk_handlers__mlift2515_advance_fun_fun3828(kk_function_t _fself, kk_function_t _b_2952, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2515_advance_fun_fun3828(kk_function_t _bv_2951, kk_context_t* _ctx) {
  struct kk_handlers__mlift2515_advance_fun_fun3828__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2515_advance_fun_fun3828__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2515_advance_fun_fun3828, kk_context());
  _self->_bv_2951 = _bv_2951;
  return &_self->_base;
}



// lift anonymous function
struct kk_handlers__mlift2515_advance_fun_fun3829__t {
  struct kk_function_s _base;
  kk_function_t _b_2952;
};
static kk_box_t kk_handlers__mlift2515_advance_fun_fun3829(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2515_advance_fun_fun3829(kk_function_t _b_2952, kk_context_t* _ctx) {
  struct kk_handlers__mlift2515_advance_fun_fun3829__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2515_advance_fun_fun3829__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2515_advance_fun_fun3829, kk_context());
  _self->_b_2952 = _b_2952;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift2515_advance_fun_fun3829(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_handlers__mlift2515_advance_fun_fun3829__t* _self = kk_function_as(struct kk_handlers__mlift2515_advance_fun_fun3829__t*, _fself);
  kk_function_t _b_2952 = _self->_b_2952; /* () -> () */
  kk_drop_match(_self, {kk_function_dup(_b_2952);}, {}, _ctx)
  kk_unit_t _x3830 = kk_Unit;
  kk_function_call(kk_unit_t, (kk_function_t, kk_context_t*), _b_2952, (_b_2952, _ctx));
  return kk_unit_box(_x3830);
}
static kk_box_t kk_handlers__mlift2515_advance_fun_fun3828(kk_function_t _fself, kk_function_t _b_2952, kk_context_t* _ctx) {
  struct kk_handlers__mlift2515_advance_fun_fun3828__t* _self = kk_function_as(struct kk_handlers__mlift2515_advance_fun_fun3828__t*, _fself);
  kk_function_t _bv_2951 = _self->_bv_2951; /* (() -> 2806) -> 2807 2808 */
  kk_drop_match(_self, {kk_function_dup(_bv_2951);}, {}, _ctx)
  return kk_function_call(kk_box_t, (kk_function_t, kk_function_t, kk_context_t*), _bv_2951, (_bv_2951, kk_handlers__new_mlift2515_advance_fun_fun3829(_b_2952, _ctx), _ctx));
}

kk_box_t kk_handlers__mlift2515_advance_fun(kk_std_core_hnd__resume_context rcontext, kk_unit_t wild__0, kk_context_t* _ctx) { /* forall<a,e,h> (rcontext : std/core/hnd/resume-context<(),<effects-and-types/yield,local<h>|e>,a>, wild_0 : ()) -> <effects-and-types/yield,local<h>|e> a */ 
  kk_function_t _x3827;
  kk_function_t _bv_2951 = kk_std_core_hnd_k(rcontext, _ctx); /*(() -> 2806) -> 2807 2808*/;
  _x3827 = kk_handlers__new_mlift2515_advance_fun_fun3828(_bv_2951, _ctx); /*(() -> ()) -> 2808*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_function_t, kk_context_t*), _x3827, (_x3827, kk_handlers__new_mlift2515_advance_fun_fun3826(_ctx), _ctx));
}
 
// monadic lift


// lift anonymous function
struct kk_handlers__mlift2516_advance_fun_fun3831__t {
  struct kk_function_s _base;
};
static kk_unit_t kk_handlers__mlift2516_advance_fun_fun3831(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2516_advance_fun_fun3831(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_handlers__mlift2516_advance_fun_fun3831, _ctx)
  return kk_function_dup(_fself);
}

static kk_unit_t kk_handlers__mlift2516_advance_fun_fun3831(kk_function_t _fself, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return kk_Unit;
}


// lift anonymous function
struct kk_handlers__mlift2516_advance_fun_fun3833__t {
  struct kk_function_s _base;
  kk_function_t _bv_2955;
};
static kk_box_t kk_handlers__mlift2516_advance_fun_fun3833(kk_function_t _fself, kk_function_t _b_2956, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2516_advance_fun_fun3833(kk_function_t _bv_2955, kk_context_t* _ctx) {
  struct kk_handlers__mlift2516_advance_fun_fun3833__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2516_advance_fun_fun3833__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2516_advance_fun_fun3833, kk_context());
  _self->_bv_2955 = _bv_2955;
  return &_self->_base;
}



// lift anonymous function
struct kk_handlers__mlift2516_advance_fun_fun3834__t {
  struct kk_function_s _base;
  kk_function_t _b_2956;
};
static kk_box_t kk_handlers__mlift2516_advance_fun_fun3834(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2516_advance_fun_fun3834(kk_function_t _b_2956, kk_context_t* _ctx) {
  struct kk_handlers__mlift2516_advance_fun_fun3834__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2516_advance_fun_fun3834__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2516_advance_fun_fun3834, kk_context());
  _self->_b_2956 = _b_2956;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift2516_advance_fun_fun3834(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_handlers__mlift2516_advance_fun_fun3834__t* _self = kk_function_as(struct kk_handlers__mlift2516_advance_fun_fun3834__t*, _fself);
  kk_function_t _b_2956 = _self->_b_2956; /* () -> () */
  kk_drop_match(_self, {kk_function_dup(_b_2956);}, {}, _ctx)
  kk_unit_t _x3835 = kk_Unit;
  kk_function_call(kk_unit_t, (kk_function_t, kk_context_t*), _b_2956, (_b_2956, _ctx));
  return kk_unit_box(_x3835);
}
static kk_box_t kk_handlers__mlift2516_advance_fun_fun3833(kk_function_t _fself, kk_function_t _b_2956, kk_context_t* _ctx) {
  struct kk_handlers__mlift2516_advance_fun_fun3833__t* _self = kk_function_as(struct kk_handlers__mlift2516_advance_fun_fun3833__t*, _fself);
  kk_function_t _bv_2955 = _self->_bv_2955; /* (() -> 2806) -> 2807 2808 */
  kk_drop_match(_self, {kk_function_dup(_bv_2955);}, {}, _ctx)
  return kk_function_call(kk_box_t, (kk_function_t, kk_function_t, kk_context_t*), _bv_2955, (_bv_2955, kk_handlers__new_mlift2516_advance_fun_fun3834(_b_2956, _ctx), _ctx));
}


// lift anonymous function
struct kk_handlers__mlift2516_advance_fun_fun3843__t {
  struct kk_function_s _base;
  size_t i_2573;
};
static kk_box_t kk_handlers__mlift2516_advance_fun_fun3843(kk_function_t _fself, kk_function_t _b_2970, kk_box_t _b_2971, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2516_advance_fun_fun3843(size_t i_2573, kk_context_t* _ctx) {
  struct kk_handlers__mlift2516_advance_fun_fun3843__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2516_advance_fun_fun3843__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2516_advance_fun_fun3843, kk_context());
  _self->i_2573 = i_2573;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift2516_advance_fun_fun3843(kk_function_t _fself, kk_function_t _b_2970, kk_box_t _b_2971, kk_context_t* _ctx) {
  struct kk_handlers__mlift2516_advance_fun_fun3843__t* _self = kk_function_as(struct kk_handlers__mlift2516_advance_fun_fun3843__t*, _fself);
  size_t i_2573 = _self->i_2573; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_2573, _b_2970, _b_2971, _ctx);
}


// lift anonymous function
struct kk_handlers__mlift2516_advance_fun_fun3844__t {
  struct kk_function_s _base;
  kk_std_core_hnd__resume_context rcontext;
};
static kk_box_t kk_handlers__mlift2516_advance_fun_fun3844(kk_function_t _fself, kk_box_t _b_2981, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2516_advance_fun_fun3844(kk_std_core_hnd__resume_context rcontext, kk_context_t* _ctx) {
  struct kk_handlers__mlift2516_advance_fun_fun3844__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2516_advance_fun_fun3844__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2516_advance_fun_fun3844, kk_context());
  _self->rcontext = rcontext;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift2516_advance_fun_fun3844(kk_function_t _fself, kk_box_t _b_2981, kk_context_t* _ctx) {
  struct kk_handlers__mlift2516_advance_fun_fun3844__t* _self = kk_function_as(struct kk_handlers__mlift2516_advance_fun_fun3844__t*, _fself);
  kk_std_core_hnd__resume_context rcontext = _self->rcontext; /* std/core/hnd/resume-context<(),<effects-and-types/yield,local<571>|405>,17> */
  kk_drop_match(_self, {kk_std_core_hnd__resume_context_dup(rcontext);}, {}, _ctx)
  kk_unit_t _x3845 = kk_Unit;
  kk_unit_unbox(_b_2981);
  return kk_handlers__mlift2515_advance_fun(rcontext, _x3845, _ctx);
}

kk_box_t kk_handlers__mlift2516_advance_fun(kk_std_core_hnd__resume_context rcontext, kk_integer_t _y_13, kk_context_t* _ctx) { /* forall<a,e,h> (rcontext : std/core/hnd/resume-context<(),<effects-and-types/yield,local<h>|e>,a>, int) -> <local<h>,effects-and-types/yield|e> a */ 
  bool _match_3718 = kk_integer_gt(_y_13,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  if (_match_3718) {
    kk_function_t _x3832;
    kk_function_t _bv_2955 = kk_std_core_hnd_k(rcontext, _ctx); /*(() -> 2806) -> 2807 2808*/;
    _x3832 = kk_handlers__new_mlift2516_advance_fun_fun3833(_bv_2955, _ctx); /*(() -> ()) -> 2808*/
    return kk_function_call(kk_box_t, (kk_function_t, kk_function_t, kk_context_t*), _x3832, (_x3832, kk_handlers__new_mlift2516_advance_fun_fun3831(_ctx), _ctx));
  }
  kk_unit_t x0_2571 = kk_Unit;
  size_t i_2573;
  kk_std_core_hnd__htag _x3836 = kk_std_core_hnd__htag_dup(kk_effects_dash_and_dash_types__tag_yield); /*std/core/hnd/htag<effects-and-types/.hnd-yield>*/
  i_2573 = kk_std_core_hnd__evv_index(_x3836, _ctx); /*std/core/hnd/ev-index*/
  kk_evv_t w = kk_evv_swap_create1(i_2573,kk_context()); /*std/core/hnd/evv<<effects-and-types/yield,local<571>|405>>*/;
  kk_unit_t y = kk_Unit;
  kk_std_core_hnd__ev ev_409;
  size_t _x3837 = ((size_t)0); /*size_t*/
  ev_409 = kk_evv_at(_x3837,kk_context()); /*std/core/hnd/ev<effects-and-types/.hnd-yield>*/
  kk_box_t _x3838;
  struct kk_std_core_hnd_Ev* _con3839 = kk_std_core_hnd__as_Ev(ev_409);
  kk_std_core_hnd__marker m = _con3839->marker;
  kk_box_t _box_x2957 = _con3839->hnd;
  kk_effects_dash_and_dash_types__hnd_yield h = kk_effects_dash_and_dash_types__hnd_yield_unbox(_box_x2957, NULL);
  kk_effects_dash_and_dash_types__hnd_yield_dup(h);
  kk_std_core_hnd__clause0 _match_3721;
  struct kk_effects_dash_and_dash_types__Hnd_yield* _con3841 = kk_effects_dash_and_dash_types__as_Hnd_yield(h);
  kk_std_core_hnd__clause0 control_yield = _con3841->control_yield;
  if (kk_effects_dash_and_dash_types__hnd_yield_is_unique(h)) {
    kk_effects_dash_and_dash_types__hnd_yield_free(h);
  }
  else {
    kk_std_core_hnd__clause0_dup(control_yield);
    kk_effects_dash_and_dash_types__hnd_yield_decref(h, _ctx);
  }
  _match_3721 = control_yield; /*std/core/hnd/clause0<(),effects-and-types/.hnd-yield,3435,3436>*/
  kk_function_t _fun_unbox_x2960 = _match_3721.clause;
  _x3838 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x2960, (_fun_unbox_x2960, m, ev_409, _ctx)); /*37*/
  kk_unit_unbox(_x3838);
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x3842 = kk_std_core_hnd_yield_cont(kk_handlers__new_mlift2516_advance_fun_fun3843(i_2573, _ctx), _ctx); /*3820*/
    kk_unit_unbox(_x3842);
  }
  else {
    y;
  }
  if (kk_yielding(kk_context())) {
    return kk_std_core_hnd_yield_extend(kk_handlers__new_mlift2516_advance_fun_fun3844(rcontext, _ctx), _ctx);
  }
  return kk_handlers__mlift2515_advance_fun(rcontext, x0_2571, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_handlers__mlift2517_advance_fun_fun3847__t {
  struct kk_function_s _base;
  kk_std_core_hnd__resume_context rcontext;
};
static kk_box_t kk_handlers__mlift2517_advance_fun_fun3847(kk_function_t _fself, kk_box_t _b_2988, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2517_advance_fun_fun3847(kk_std_core_hnd__resume_context rcontext, kk_context_t* _ctx) {
  struct kk_handlers__mlift2517_advance_fun_fun3847__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2517_advance_fun_fun3847__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2517_advance_fun_fun3847, kk_context());
  _self->rcontext = rcontext;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift2517_advance_fun_fun3847(kk_function_t _fself, kk_box_t _b_2988, kk_context_t* _ctx) {
  struct kk_handlers__mlift2517_advance_fun_fun3847__t* _self = kk_function_as(struct kk_handlers__mlift2517_advance_fun_fun3847__t*, _fself);
  kk_std_core_hnd__resume_context rcontext = _self->rcontext; /* std/core/hnd/resume-context<(),<effects-and-types/yield,local<571>|405>,17> */
  kk_drop_match(_self, {kk_std_core_hnd__resume_context_dup(rcontext);}, {}, _ctx)
  kk_integer_t _x3848 = kk_integer_unbox(_b_2988); /*int*/
  return kk_handlers__mlift2516_advance_fun(rcontext, _x3848, _ctx);
}

kk_box_t kk_handlers__mlift2517_advance_fun(kk_ref_t count, kk_std_core_hnd__resume_context rcontext, kk_unit_t wild__, kk_context_t* _ctx) { /* forall<a,e,h> (count : local-var<h,int>, rcontext : std/core/hnd/resume-context<(),<effects-and-types/yield,local<h>|e>,a>, wild_ : ()) -> <local<h>,effects-and-types/yield|e> a */ 
  kk_integer_t x_2575;
  kk_box_t _x3846 = (kk_ref_get(count,kk_context())); /*228*/
  x_2575 = kk_integer_unbox(_x3846); /*int*/
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_2575, _ctx);
    return kk_std_core_hnd_yield_extend(kk_handlers__new_mlift2517_advance_fun_fun3847(rcontext, _ctx), _ctx);
  }
  return kk_handlers__mlift2516_advance_fun(rcontext, x_2575, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_handlers__mlift2518_advance_fun_fun3850__t {
  struct kk_function_s _base;
  kk_ref_t count;
  kk_std_core_hnd__resume_context rcontext;
};
static kk_box_t kk_handlers__mlift2518_advance_fun_fun3850(kk_function_t _fself, kk_box_t _b_2996, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2518_advance_fun_fun3850(kk_ref_t count, kk_std_core_hnd__resume_context rcontext, kk_context_t* _ctx) {
  struct kk_handlers__mlift2518_advance_fun_fun3850__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2518_advance_fun_fun3850__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2518_advance_fun_fun3850, kk_context());
  _self->count = count;
  _self->rcontext = rcontext;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift2518_advance_fun_fun3850(kk_function_t _fself, kk_box_t _b_2996, kk_context_t* _ctx) {
  struct kk_handlers__mlift2518_advance_fun_fun3850__t* _self = kk_function_as(struct kk_handlers__mlift2518_advance_fun_fun3850__t*, _fself);
  kk_ref_t count = _self->count; /* local-var<571,int> */
  kk_std_core_hnd__resume_context rcontext = _self->rcontext; /* std/core/hnd/resume-context<(),<effects-and-types/yield,local<571>|405>,17> */
  kk_drop_match(_self, {kk_ref_dup(count);kk_std_core_hnd__resume_context_dup(rcontext);}, {}, _ctx)
  kk_unit_t _x3851 = kk_Unit;
  kk_unit_unbox(_b_2996);
  return kk_handlers__mlift2517_advance_fun(count, rcontext, _x3851, _ctx);
}

kk_box_t kk_handlers__mlift2518_advance_fun(kk_ref_t count, kk_std_core_hnd__resume_context rcontext, kk_integer_t _y_11, kk_context_t* _ctx) { /* forall<a,e,h> (count : local-var<h,int>, rcontext : std/core/hnd/resume-context<(),<effects-and-types/yield,local<h>|e>,a>, int) -> <local<h>,effects-and-types/yield|e> a */ 
  kk_unit_t x_2577 = kk_Unit;
  kk_integer_t _b_2994_2992 = kk_integer_sub(_y_11,(kk_integer_from_small(1)),kk_context()); /*int*/;
  kk_ref_t _x3849 = kk_ref_dup(count); /*local-var<571,int>*/
  (kk_ref_set(_x3849,(kk_integer_box(_b_2994_2992)),kk_context()));
  if (kk_yielding(kk_context())) {
    return kk_std_core_hnd_yield_extend(kk_handlers__new_mlift2518_advance_fun_fun3850(count, rcontext, _ctx), _ctx);
  }
  return kk_handlers__mlift2517_advance_fun(count, rcontext, x_2577, _ctx);
}


// lift anonymous function
struct kk_handlers_advance_fun_fun3855__t {
  struct kk_function_s _base;
  kk_ref_t loc;
};
static kk_box_t kk_handlers_advance_fun_fun3855(kk_function_t _fself, kk_std_core_hnd__marker _b_3013, kk_std_core_hnd__ev _b_3014, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_advance_fun_fun3855(kk_ref_t loc, kk_context_t* _ctx) {
  struct kk_handlers_advance_fun_fun3855__t* _self = kk_function_alloc_as(struct kk_handlers_advance_fun_fun3855__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_advance_fun_fun3855, kk_context());
  _self->loc = loc;
  return &_self->_base;
}



// lift anonymous function
struct kk_handlers_advance_fun_fun3856__t {
  struct kk_function_s _base;
  kk_ref_t loc;
};
static kk_box_t kk_handlers_advance_fun_fun3856(kk_function_t _fself, kk_function_t _b_3010, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_advance_fun_fun3856(kk_ref_t loc, kk_context_t* _ctx) {
  struct kk_handlers_advance_fun_fun3856__t* _self = kk_function_alloc_as(struct kk_handlers_advance_fun_fun3856__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_advance_fun_fun3856, kk_context());
  _self->loc = loc;
  return &_self->_base;
}



// lift anonymous function
struct kk_handlers_advance_fun_fun3859__t {
  struct kk_function_s _base;
  kk_ref_t loc;
  kk_std_core_hnd__resume_context rcontext_2584;
};
static kk_box_t kk_handlers_advance_fun_fun3859(kk_function_t _fself, kk_box_t _b_3007, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_advance_fun_fun3859(kk_ref_t loc, kk_std_core_hnd__resume_context rcontext_2584, kk_context_t* _ctx) {
  struct kk_handlers_advance_fun_fun3859__t* _self = kk_function_alloc_as(struct kk_handlers_advance_fun_fun3859__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_advance_fun_fun3859, kk_context());
  _self->loc = loc;
  _self->rcontext_2584 = rcontext_2584;
  return &_self->_base;
}

static kk_box_t kk_handlers_advance_fun_fun3859(kk_function_t _fself, kk_box_t _b_3007, kk_context_t* _ctx) {
  struct kk_handlers_advance_fun_fun3859__t* _self = kk_function_as(struct kk_handlers_advance_fun_fun3859__t*, _fself);
  kk_ref_t loc = _self->loc; /* local-var<global,int> */
  kk_std_core_hnd__resume_context rcontext_2584 = _self->rcontext_2584; /* std/core/hnd/resume-context<(),<effects-and-types/yield,local<global>|405>,17> */
  kk_drop_match(_self, {kk_ref_dup(loc);kk_std_core_hnd__resume_context_dup(rcontext_2584);}, {}, _ctx)
  kk_integer_t _x3860 = kk_integer_unbox(_b_3007); /*int*/
  return kk_handlers__mlift2518_advance_fun(loc, rcontext_2584, _x3860, _ctx);
}
static kk_box_t kk_handlers_advance_fun_fun3856(kk_function_t _fself, kk_function_t _b_3010, kk_context_t* _ctx) {
  struct kk_handlers_advance_fun_fun3856__t* _self = kk_function_as(struct kk_handlers_advance_fun_fun3856__t*, _fself);
  kk_ref_t loc = _self->loc; /* local-var<global,int> */
  kk_drop_match(_self, {kk_ref_dup(loc);}, {}, _ctx)
  kk_std_core_hnd__resume_context rcontext_2584 = kk_std_core_hnd__new_Resume_context(_b_3010, _ctx); /*std/core/hnd/resume-context<(),<effects-and-types/yield,local<global>|405>,17>*/;
  kk_integer_t x_2585;
  kk_box_t _x3857;
  kk_ref_t _x3858 = kk_ref_dup(loc); /*local-var<global,int>*/
  _x3857 = (kk_ref_get(_x3858,kk_context())); /*228*/
  x_2585 = kk_integer_unbox(_x3857); /*int*/
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_2585, _ctx);
    return kk_std_core_hnd_yield_extend(kk_handlers_new_advance_fun_fun3859(loc, rcontext_2584, _ctx), _ctx);
  }
  return kk_handlers__mlift2518_advance_fun(loc, rcontext_2584, x_2585, _ctx);
}
static kk_box_t kk_handlers_advance_fun_fun3855(kk_function_t _fself, kk_std_core_hnd__marker _b_3013, kk_std_core_hnd__ev _b_3014, kk_context_t* _ctx) {
  struct kk_handlers_advance_fun_fun3855__t* _self = kk_function_as(struct kk_handlers_advance_fun_fun3855__t*, _fself);
  kk_ref_t loc = _self->loc; /* local-var<global,int> */
  kk_drop_match(_self, {kk_ref_dup(loc);}, {}, _ctx)
  kk_std_core_hnd__ev_dropn(_b_3014, ((int32_t)3), _ctx);
  return kk_std_core_hnd_yield_to(_b_3013, kk_handlers_new_advance_fun_fun3856(loc, _ctx), _ctx);
}


// lift anonymous function
struct kk_handlers_advance_fun_fun3861__t {
  struct kk_function_s _base;
};
static kk_box_t kk_handlers_advance_fun_fun3861(kk_function_t _fself, kk_box_t _x, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_advance_fun_fun3861(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_handlers_advance_fun_fun3861, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_handlers_advance_fun_fun3861(kk_function_t _fself, kk_box_t _x, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return _x;
}


// lift anonymous function
struct kk_handlers_advance_fun_fun3862__t {
  struct kk_function_s _base;
  kk_function_t action;
};
static kk_box_t kk_handlers_advance_fun_fun3862(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_advance_fun_fun3862(kk_function_t action, kk_context_t* _ctx) {
  struct kk_handlers_advance_fun_fun3862__t* _self = kk_function_alloc_as(struct kk_handlers_advance_fun_fun3862__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_advance_fun_fun3862, kk_context());
  _self->action = action;
  return &_self->_base;
}

static kk_box_t kk_handlers_advance_fun_fun3862(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_handlers_advance_fun_fun3862__t* _self = kk_function_as(struct kk_handlers_advance_fun_fun3862__t*, _fself);
  kk_function_t action = _self->action; /* () -> <effects-and-types/yield,effects-and-types/yield|405> 17 */
  kk_drop_match(_self, {kk_function_dup(action);}, {}, _ctx)
  return kk_std_core_hnd__mask_builtin(action, _ctx);
}

kk_box_t kk_handlers_advance_fun(kk_function_t action, kk_integer_t init, kk_context_t* _ctx) { /* forall<a,e> (action : () -> <effects-and-types/yield,effects-and-types/yield|e> a, init : int) -> <effects-and-types/yield|e> a */ 
  kk_ref_t loc = kk_ref_alloc((kk_integer_box(init)),kk_context()); /*local-var<global,int>*/;
  kk_box_t res;
  kk_effects_dash_and_dash_types__hnd_yield _x3852;
  kk_std_core_hnd__clause0 _x3853;
  kk_function_t _x3854;
  kk_ref_dup(loc);
  _x3854 = kk_handlers_new_advance_fun_fun3855(loc, _ctx); /*(std/core/hnd/marker<39,40>, std/core/hnd/ev<38>) -> 39 6146*/
  _x3853 = kk_std_core_hnd__new_Clause0(_x3854, _ctx); /*std/core/hnd/clause0<37,38,39,40>*/
  _x3852 = kk_effects_dash_and_dash_types__new_Hnd_yield(kk_reuse_null, _x3853, _ctx); /*effects-and-types/.hnd-yield<25,26>*/
  res = kk_effects_dash_and_dash_types__handle_yield(((int32_t)3), _x3852, kk_handlers_new_advance_fun_fun3861(_ctx), kk_handlers_new_advance_fun_fun3862(action, _ctx), _ctx); /*17*/
  return kk_std_core_hnd_prompt_local_var(loc, res, _ctx);
}
 
// monadic lift

kk_box_t kk_handlers__mlift2519_advance_deep(kk_integer_t steps, kk_function_t _y_24, kk_context_t* _ctx) { /* forall<a,e> (steps : int, (int) -> <effects-and-types/yield|e> a) -> <effects-and-types/yield|e> a */ 
  kk_integer_t _x3863 = kk_integer_sub(steps,(kk_integer_from_small(1)),kk_context()); /*int*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_context_t*), _y_24, (_y_24, _x3863, _ctx));
}
 
// monadic lift


// lift anonymous function
struct kk_handlers__mlift2520_advance_deep_fun3865__t {
  struct kk_function_s _base;
  size_t _y_22;
};
static kk_box_t kk_handlers__mlift2520_advance_deep_fun3865(kk_function_t _fself, kk_function_t _b_3044, kk_box_t _b_3045, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2520_advance_deep_fun3865(size_t _y_22, kk_context_t* _ctx) {
  struct kk_handlers__mlift2520_advance_deep_fun3865__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2520_advance_deep_fun3865__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2520_advance_deep_fun3865, kk_context());
  _self->_y_22 = _y_22;
  return &_self->_base;
}



// lift anonymous function
struct kk_handlers__mlift2520_advance_deep_fun3868__t {
  struct kk_function_s _base;
  kk_function_t _b_3044;
};
static kk_box_t kk_handlers__mlift2520_advance_deep_fun3868(kk_function_t _fself, kk_box_t _b_3028, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2520_advance_deep_fun3868(kk_function_t _b_3044, kk_context_t* _ctx) {
  struct kk_handlers__mlift2520_advance_deep_fun3868__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2520_advance_deep_fun3868__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2520_advance_deep_fun3868, kk_context());
  _self->_b_3044 = _b_3044;
  return &_self->_base;
}



// lift anonymous function
struct kk_handlers__mlift2520_advance_deep_fun3871__t {
  struct kk_function_s _base;
  kk_box_t _b_3028;
};
static kk_box_t kk_handlers__mlift2520_advance_deep_fun3871(kk_function_t _fself, kk_box_t _b_3049, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2520_advance_deep_fun3871(kk_box_t _b_3028, kk_context_t* _ctx) {
  struct kk_handlers__mlift2520_advance_deep_fun3871__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2520_advance_deep_fun3871__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2520_advance_deep_fun3871, kk_context());
  _self->_b_3028 = _b_3028;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift2520_advance_deep_fun3871(kk_function_t _fself, kk_box_t _b_3049, kk_context_t* _ctx) {
  struct kk_handlers__mlift2520_advance_deep_fun3871__t* _self = kk_function_as(struct kk_handlers__mlift2520_advance_deep_fun3871__t*, _fself);
  kk_box_t _b_3028 = _self->_b_3028; /* 4674 */
  kk_drop_match(_self, {kk_box_dup(_b_3028);}, {}, _ctx)
  kk_function_t _x3872 = kk_function_unbox(_b_3028); /*(3029) -> <effects-and-types/yield|704> 3030*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x3872, (_x3872, _b_3049, _ctx));
}


// lift anonymous function
struct kk_handlers__mlift2520_advance_deep_fun3873__t {
  struct kk_function_s _base;
  kk_function_t _bv_3052;
};
static kk_box_t kk_handlers__mlift2520_advance_deep_fun3873(kk_function_t _fself, kk_integer_t _b_3053, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2520_advance_deep_fun3873(kk_function_t _bv_3052, kk_context_t* _ctx) {
  struct kk_handlers__mlift2520_advance_deep_fun3873__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2520_advance_deep_fun3873__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2520_advance_deep_fun3873, kk_context());
  _self->_bv_3052 = _bv_3052;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift2520_advance_deep_fun3873(kk_function_t _fself, kk_integer_t _b_3053, kk_context_t* _ctx) {
  struct kk_handlers__mlift2520_advance_deep_fun3873__t* _self = kk_function_as(struct kk_handlers__mlift2520_advance_deep_fun3873__t*, _fself);
  kk_function_t _bv_3052 = _self->_bv_3052; /* (3050) -> <effects-and-types/yield|704> 3051 */
  kk_drop_match(_self, {kk_function_dup(_bv_3052);}, {}, _ctx)
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _bv_3052, (_bv_3052, kk_integer_box(_b_3053), _ctx));
}


// lift anonymous function
struct kk_handlers__mlift2520_advance_deep_fun3874__t {
  struct kk_function_s _base;
  kk_function_t _bv_3034;
};
static kk_box_t kk_handlers__mlift2520_advance_deep_fun3874(kk_function_t _fself, kk_box_t _b_3035, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2520_advance_deep_fun3874(kk_function_t _bv_3034, kk_context_t* _ctx) {
  struct kk_handlers__mlift2520_advance_deep_fun3874__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2520_advance_deep_fun3874__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2520_advance_deep_fun3874, kk_context());
  _self->_bv_3034 = _bv_3034;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift2520_advance_deep_fun3874(kk_function_t _fself, kk_box_t _b_3035, kk_context_t* _ctx) {
  struct kk_handlers__mlift2520_advance_deep_fun3874__t* _self = kk_function_as(struct kk_handlers__mlift2520_advance_deep_fun3874__t*, _fself);
  kk_function_t _bv_3034 = _self->_bv_3034; /* (int) -> <effects-and-types/yield|704> 703 */
  kk_drop_match(_self, {kk_function_dup(_bv_3034);}, {}, _ctx)
  kk_integer_t _x3875 = kk_integer_unbox(_b_3035); /*int*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_context_t*), _bv_3034, (_bv_3034, _x3875, _ctx));
}
static kk_box_t kk_handlers__mlift2520_advance_deep_fun3868(kk_function_t _fself, kk_box_t _b_3028, kk_context_t* _ctx) {
  struct kk_handlers__mlift2520_advance_deep_fun3868__t* _self = kk_function_as(struct kk_handlers__mlift2520_advance_deep_fun3868__t*, _fself);
  kk_function_t _b_3044 = _self->_b_3044; /* (3818) -> 3819 3818 */
  kk_drop_match(_self, {kk_function_dup(_b_3044);}, {}, _ctx)
  kk_function_t _x3869;
  kk_function_t _bv_3034;
  kk_function_t _bv_3052;
  kk_box_t _x3870 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _b_3044, (_b_3044, kk_function_box(kk_handlers__new_mlift2520_advance_deep_fun3871(_b_3028, _ctx)), _ctx)); /*3818*/
  _bv_3052 = kk_function_unbox(_x3870); /*(3050) -> <effects-and-types/yield|704> 3051*/
  _bv_3034 = kk_handlers__new_mlift2520_advance_deep_fun3873(_bv_3052, _ctx); /*(int) -> <effects-and-types/yield|704> 703*/
  _x3869 = kk_handlers__new_mlift2520_advance_deep_fun3874(_bv_3034, _ctx); /*(3032) -> <effects-and-types/yield|704> 703*/
  return kk_function_box(_x3869);
}


// lift anonymous function
struct kk_handlers__mlift2520_advance_deep_fun3876__t {
  struct kk_function_s _base;
  kk_box_t _b_3045;
};
static kk_box_t kk_handlers__mlift2520_advance_deep_fun3876(kk_function_t _fself, kk_box_t _b_3038, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2520_advance_deep_fun3876(kk_box_t _b_3045, kk_context_t* _ctx) {
  struct kk_handlers__mlift2520_advance_deep_fun3876__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2520_advance_deep_fun3876__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2520_advance_deep_fun3876, kk_context());
  _self->_b_3045 = _b_3045;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift2520_advance_deep_fun3876(kk_function_t _fself, kk_box_t _b_3038, kk_context_t* _ctx) {
  struct kk_handlers__mlift2520_advance_deep_fun3876__t* _self = kk_function_as(struct kk_handlers__mlift2520_advance_deep_fun3876__t*, _fself);
  kk_box_t _b_3045 = _self->_b_3045; /* 3818 */
  kk_drop_match(_self, {kk_box_dup(_b_3045);}, {}, _ctx)
  kk_function_t _x3877 = kk_function_unbox(_b_3045); /*(3054) -> <effects-and-types/yield|704> 3055*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x3877, (_x3877, _b_3038, _ctx));
}


// lift anonymous function
struct kk_handlers__mlift2520_advance_deep_fun3878__t {
  struct kk_function_s _base;
  kk_function_t _bv_3041;
};
static kk_box_t kk_handlers__mlift2520_advance_deep_fun3878(kk_function_t _fself, kk_integer_t _b_3042, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2520_advance_deep_fun3878(kk_function_t _bv_3041, kk_context_t* _ctx) {
  struct kk_handlers__mlift2520_advance_deep_fun3878__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2520_advance_deep_fun3878__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2520_advance_deep_fun3878, kk_context());
  _self->_bv_3041 = _bv_3041;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift2520_advance_deep_fun3878(kk_function_t _fself, kk_integer_t _b_3042, kk_context_t* _ctx) {
  struct kk_handlers__mlift2520_advance_deep_fun3878__t* _self = kk_function_as(struct kk_handlers__mlift2520_advance_deep_fun3878__t*, _fself);
  kk_function_t _bv_3041 = _self->_bv_3041; /* (3039) -> <effects-and-types/yield|704> 3040 */
  kk_drop_match(_self, {kk_function_dup(_bv_3041);}, {}, _ctx)
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _bv_3041, (_bv_3041, kk_integer_box(_b_3042), _ctx));
}


// lift anonymous function
struct kk_handlers__mlift2520_advance_deep_fun3879__t {
  struct kk_function_s _base;
  kk_function_t _bv_3059;
};
static kk_box_t kk_handlers__mlift2520_advance_deep_fun3879(kk_function_t _fself, kk_box_t _b_3060, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2520_advance_deep_fun3879(kk_function_t _bv_3059, kk_context_t* _ctx) {
  struct kk_handlers__mlift2520_advance_deep_fun3879__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2520_advance_deep_fun3879__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2520_advance_deep_fun3879, kk_context());
  _self->_bv_3059 = _bv_3059;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift2520_advance_deep_fun3879(kk_function_t _fself, kk_box_t _b_3060, kk_context_t* _ctx) {
  struct kk_handlers__mlift2520_advance_deep_fun3879__t* _self = kk_function_as(struct kk_handlers__mlift2520_advance_deep_fun3879__t*, _fself);
  kk_function_t _bv_3059 = _self->_bv_3059; /* (int) -> <effects-and-types/yield|704> 703 */
  kk_drop_match(_self, {kk_function_dup(_bv_3059);}, {}, _ctx)
  kk_integer_t _x3880 = kk_integer_unbox(_b_3060); /*int*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_context_t*), _bv_3059, (_bv_3059, _x3880, _ctx));
}
static kk_box_t kk_handlers__mlift2520_advance_deep_fun3865(kk_function_t _fself, kk_function_t _b_3044, kk_box_t _b_3045, kk_context_t* _ctx) {
  struct kk_handlers__mlift2520_advance_deep_fun3865__t* _self = kk_function_as(struct kk_handlers__mlift2520_advance_deep_fun3865__t*, _fself);
  size_t _y_22 = _self->_y_22; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  kk_function_t _x3866;
  kk_function_t _bv_3059;
  kk_function_t _bv_3041;
  kk_box_t _x3867 = kk_std_core_hnd_mask_at1(_y_22, false, kk_handlers__new_mlift2520_advance_deep_fun3868(_b_3044, _ctx), kk_function_box(kk_handlers__new_mlift2520_advance_deep_fun3876(_b_3045, _ctx)), _ctx); /*4675*/
  _bv_3041 = kk_function_unbox(_x3867); /*(3039) -> <effects-and-types/yield|704> 3040*/
  _bv_3059 = kk_handlers__new_mlift2520_advance_deep_fun3878(_bv_3041, _ctx); /*(int) -> <effects-and-types/yield|704> 703*/
  _x3866 = kk_handlers__new_mlift2520_advance_deep_fun3879(_bv_3059, _ctx); /*(3057) -> <effects-and-types/yield|704> 703*/
  return kk_function_box(_x3866);
}


// lift anonymous function
struct kk_handlers__mlift2520_advance_deep_fun3881__t {
  struct kk_function_s _base;
  kk_function_t _bv_3063;
};
static kk_box_t kk_handlers__mlift2520_advance_deep_fun3881(kk_function_t _fself, kk_integer_t _b_3064, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2520_advance_deep_fun3881(kk_function_t _bv_3063, kk_context_t* _ctx) {
  struct kk_handlers__mlift2520_advance_deep_fun3881__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2520_advance_deep_fun3881__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2520_advance_deep_fun3881, kk_context());
  _self->_bv_3063 = _bv_3063;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift2520_advance_deep_fun3881(kk_function_t _fself, kk_integer_t _b_3064, kk_context_t* _ctx) {
  struct kk_handlers__mlift2520_advance_deep_fun3881__t* _self = kk_function_as(struct kk_handlers__mlift2520_advance_deep_fun3881__t*, _fself);
  kk_function_t _bv_3063 = _self->_bv_3063; /* (3061) -> <.Box|.Box> 3062 */
  kk_drop_match(_self, {kk_function_dup(_bv_3063);}, {}, _ctx)
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _bv_3063, (_bv_3063, kk_integer_box(_b_3064), _ctx));
}


// lift anonymous function
struct kk_handlers__mlift2520_advance_deep_fun3882__t {
  struct kk_function_s _base;
  kk_integer_t steps;
};
static kk_box_t kk_handlers__mlift2520_advance_deep_fun3882(kk_function_t _fself, kk_box_t _b_3076, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2520_advance_deep_fun3882(kk_integer_t steps, kk_context_t* _ctx) {
  struct kk_handlers__mlift2520_advance_deep_fun3882__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2520_advance_deep_fun3882__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2520_advance_deep_fun3882, kk_context());
  _self->steps = steps;
  return &_self->_base;
}



// lift anonymous function
struct kk_handlers__mlift2520_advance_deep_fun3883__t {
  struct kk_function_s _base;
  kk_box_t _b_3076;
};
static kk_box_t kk_handlers__mlift2520_advance_deep_fun3883(kk_function_t _fself, kk_integer_t _b_3079, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2520_advance_deep_fun3883(kk_box_t _b_3076, kk_context_t* _ctx) {
  struct kk_handlers__mlift2520_advance_deep_fun3883__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2520_advance_deep_fun3883__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2520_advance_deep_fun3883, kk_context());
  _self->_b_3076 = _b_3076;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift2520_advance_deep_fun3883(kk_function_t _fself, kk_integer_t _b_3079, kk_context_t* _ctx) {
  struct kk_handlers__mlift2520_advance_deep_fun3883__t* _self = kk_function_as(struct kk_handlers__mlift2520_advance_deep_fun3883__t*, _fself);
  kk_box_t _b_3076 = _self->_b_3076; /* 3990 */
  kk_drop_match(_self, {kk_box_dup(_b_3076);}, {}, _ctx)
  kk_function_t _x3884 = kk_function_unbox(_b_3076); /*(3077) -> <effects-and-types/yield|704> 3078*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x3884, (_x3884, kk_integer_box(_b_3079), _ctx));
}
static kk_box_t kk_handlers__mlift2520_advance_deep_fun3882(kk_function_t _fself, kk_box_t _b_3076, kk_context_t* _ctx) {
  struct kk_handlers__mlift2520_advance_deep_fun3882__t* _self = kk_function_as(struct kk_handlers__mlift2520_advance_deep_fun3882__t*, _fself);
  kk_integer_t steps = _self->steps; /* int */
  kk_drop_match(_self, {kk_integer_dup(steps);}, {}, _ctx)
  return kk_handlers__mlift2519_advance_deep(steps, kk_handlers__new_mlift2520_advance_deep_fun3883(_b_3076, _ctx), _ctx);
}

kk_box_t kk_handlers__mlift2520_advance_deep(kk_function_t resume, kk_integer_t steps, size_t _y_22, kk_context_t* _ctx) { /* forall<a,e> (resume : (()) -> e ((int) -> <effects-and-types/yield|e> a), steps : int, std/core/hnd/ev-index) -> <effects-and-types/yield|e> a */ 
  kk_function_t x_2587;
  kk_evv_t w0 = kk_std_core_hnd_evv_swap_delete(_y_22, false, _ctx); /*std/core/hnd/evv<_4681>*/;
  kk_function_t x0 = kk_function_call(kk_function_t, (kk_function_t, kk_unit_t, kk_context_t*), resume, (resume, kk_Unit, _ctx)); /*(int) -> <effects-and-types/yield|704> 703*/;
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w0,kk_context());
  if (kk_yielding(kk_context())) {
    kk_function_drop(x0, _ctx);
    kk_function_t _bv_3063;
    kk_box_t _x3864 = kk_std_core_hnd_yield_cont(kk_handlers__new_mlift2520_advance_deep_fun3865(_y_22, _ctx), _ctx); /*3820*/
    _bv_3063 = kk_function_unbox(_x3864); /*(3061) -> <.Box|.Box> 3062*/
    x_2587 = kk_handlers__new_mlift2520_advance_deep_fun3881(_bv_3063, _ctx); /*(int) -> <effects-and-types/yield|704> 703*/
  }
  else {
    x_2587 = x0; /*(int) -> <effects-and-types/yield|704> 703*/
  }
  if (kk_yielding(kk_context())) {
    kk_function_drop(x_2587, _ctx);
    return kk_std_core_hnd_yield_extend(kk_handlers__new_mlift2520_advance_deep_fun3882(steps, _ctx), _ctx);
  }
  return kk_handlers__mlift2519_advance_deep(steps, x_2587, _ctx);
}
 
// monadic lift

kk_box_t kk_handlers__mlift2521_advance_deep(kk_function_t _y_29, kk_context_t* _ctx) { /* forall<a,e> ((int) -> <effects-and-types/yield|e> a) -> <effects-and-types/yield|e> a */ 
  return kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_context_t*), _y_29, (_y_29, kk_integer_from_small(0), _ctx));
}
 
// monadic lift


// lift anonymous function
struct kk_handlers__mlift2522_advance_deep_fun3886__t {
  struct kk_function_s _base;
  size_t _y_27;
};
static kk_box_t kk_handlers__mlift2522_advance_deep_fun3886(kk_function_t _fself, kk_function_t _b_3102, kk_box_t _b_3103, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2522_advance_deep_fun3886(size_t _y_27, kk_context_t* _ctx) {
  struct kk_handlers__mlift2522_advance_deep_fun3886__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2522_advance_deep_fun3886__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2522_advance_deep_fun3886, kk_context());
  _self->_y_27 = _y_27;
  return &_self->_base;
}



// lift anonymous function
struct kk_handlers__mlift2522_advance_deep_fun3889__t {
  struct kk_function_s _base;
  kk_function_t _b_3102;
};
static kk_box_t kk_handlers__mlift2522_advance_deep_fun3889(kk_function_t _fself, kk_box_t _b_3086, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2522_advance_deep_fun3889(kk_function_t _b_3102, kk_context_t* _ctx) {
  struct kk_handlers__mlift2522_advance_deep_fun3889__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2522_advance_deep_fun3889__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2522_advance_deep_fun3889, kk_context());
  _self->_b_3102 = _b_3102;
  return &_self->_base;
}



// lift anonymous function
struct kk_handlers__mlift2522_advance_deep_fun3892__t {
  struct kk_function_s _base;
  kk_box_t _b_3086;
};
static kk_box_t kk_handlers__mlift2522_advance_deep_fun3892(kk_function_t _fself, kk_box_t _b_3107, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2522_advance_deep_fun3892(kk_box_t _b_3086, kk_context_t* _ctx) {
  struct kk_handlers__mlift2522_advance_deep_fun3892__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2522_advance_deep_fun3892__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2522_advance_deep_fun3892, kk_context());
  _self->_b_3086 = _b_3086;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift2522_advance_deep_fun3892(kk_function_t _fself, kk_box_t _b_3107, kk_context_t* _ctx) {
  struct kk_handlers__mlift2522_advance_deep_fun3892__t* _self = kk_function_as(struct kk_handlers__mlift2522_advance_deep_fun3892__t*, _fself);
  kk_box_t _b_3086 = _self->_b_3086; /* 4674 */
  kk_drop_match(_self, {kk_box_dup(_b_3086);}, {}, _ctx)
  kk_function_t _x3893 = kk_function_unbox(_b_3086); /*(3087) -> <effects-and-types/yield|704> 3088*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x3893, (_x3893, _b_3107, _ctx));
}


// lift anonymous function
struct kk_handlers__mlift2522_advance_deep_fun3894__t {
  struct kk_function_s _base;
  kk_function_t _bv_3110;
};
static kk_box_t kk_handlers__mlift2522_advance_deep_fun3894(kk_function_t _fself, kk_integer_t _b_3111, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2522_advance_deep_fun3894(kk_function_t _bv_3110, kk_context_t* _ctx) {
  struct kk_handlers__mlift2522_advance_deep_fun3894__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2522_advance_deep_fun3894__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2522_advance_deep_fun3894, kk_context());
  _self->_bv_3110 = _bv_3110;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift2522_advance_deep_fun3894(kk_function_t _fself, kk_integer_t _b_3111, kk_context_t* _ctx) {
  struct kk_handlers__mlift2522_advance_deep_fun3894__t* _self = kk_function_as(struct kk_handlers__mlift2522_advance_deep_fun3894__t*, _fself);
  kk_function_t _bv_3110 = _self->_bv_3110; /* (3108) -> <effects-and-types/yield|704> 3109 */
  kk_drop_match(_self, {kk_function_dup(_bv_3110);}, {}, _ctx)
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _bv_3110, (_bv_3110, kk_integer_box(_b_3111), _ctx));
}


// lift anonymous function
struct kk_handlers__mlift2522_advance_deep_fun3895__t {
  struct kk_function_s _base;
  kk_function_t _bv_3092;
};
static kk_box_t kk_handlers__mlift2522_advance_deep_fun3895(kk_function_t _fself, kk_box_t _b_3093, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2522_advance_deep_fun3895(kk_function_t _bv_3092, kk_context_t* _ctx) {
  struct kk_handlers__mlift2522_advance_deep_fun3895__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2522_advance_deep_fun3895__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2522_advance_deep_fun3895, kk_context());
  _self->_bv_3092 = _bv_3092;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift2522_advance_deep_fun3895(kk_function_t _fself, kk_box_t _b_3093, kk_context_t* _ctx) {
  struct kk_handlers__mlift2522_advance_deep_fun3895__t* _self = kk_function_as(struct kk_handlers__mlift2522_advance_deep_fun3895__t*, _fself);
  kk_function_t _bv_3092 = _self->_bv_3092; /* (int) -> <effects-and-types/yield|704> 703 */
  kk_drop_match(_self, {kk_function_dup(_bv_3092);}, {}, _ctx)
  kk_integer_t _x3896 = kk_integer_unbox(_b_3093); /*int*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_context_t*), _bv_3092, (_bv_3092, _x3896, _ctx));
}
static kk_box_t kk_handlers__mlift2522_advance_deep_fun3889(kk_function_t _fself, kk_box_t _b_3086, kk_context_t* _ctx) {
  struct kk_handlers__mlift2522_advance_deep_fun3889__t* _self = kk_function_as(struct kk_handlers__mlift2522_advance_deep_fun3889__t*, _fself);
  kk_function_t _b_3102 = _self->_b_3102; /* (3818) -> 3819 3818 */
  kk_drop_match(_self, {kk_function_dup(_b_3102);}, {}, _ctx)
  kk_function_t _x3890;
  kk_function_t _bv_3092;
  kk_function_t _bv_3110;
  kk_box_t _x3891 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _b_3102, (_b_3102, kk_function_box(kk_handlers__new_mlift2522_advance_deep_fun3892(_b_3086, _ctx)), _ctx)); /*3818*/
  _bv_3110 = kk_function_unbox(_x3891); /*(3108) -> <effects-and-types/yield|704> 3109*/
  _bv_3092 = kk_handlers__new_mlift2522_advance_deep_fun3894(_bv_3110, _ctx); /*(int) -> <effects-and-types/yield|704> 703*/
  _x3890 = kk_handlers__new_mlift2522_advance_deep_fun3895(_bv_3092, _ctx); /*(3090) -> <effects-and-types/yield|704> 703*/
  return kk_function_box(_x3890);
}


// lift anonymous function
struct kk_handlers__mlift2522_advance_deep_fun3897__t {
  struct kk_function_s _base;
  kk_box_t _b_3103;
};
static kk_box_t kk_handlers__mlift2522_advance_deep_fun3897(kk_function_t _fself, kk_box_t _b_3096, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2522_advance_deep_fun3897(kk_box_t _b_3103, kk_context_t* _ctx) {
  struct kk_handlers__mlift2522_advance_deep_fun3897__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2522_advance_deep_fun3897__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2522_advance_deep_fun3897, kk_context());
  _self->_b_3103 = _b_3103;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift2522_advance_deep_fun3897(kk_function_t _fself, kk_box_t _b_3096, kk_context_t* _ctx) {
  struct kk_handlers__mlift2522_advance_deep_fun3897__t* _self = kk_function_as(struct kk_handlers__mlift2522_advance_deep_fun3897__t*, _fself);
  kk_box_t _b_3103 = _self->_b_3103; /* 3818 */
  kk_drop_match(_self, {kk_box_dup(_b_3103);}, {}, _ctx)
  kk_function_t _x3898 = kk_function_unbox(_b_3103); /*(3112) -> <effects-and-types/yield|704> 3113*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x3898, (_x3898, _b_3096, _ctx));
}


// lift anonymous function
struct kk_handlers__mlift2522_advance_deep_fun3899__t {
  struct kk_function_s _base;
  kk_function_t _bv_3099;
};
static kk_box_t kk_handlers__mlift2522_advance_deep_fun3899(kk_function_t _fself, kk_integer_t _b_3100, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2522_advance_deep_fun3899(kk_function_t _bv_3099, kk_context_t* _ctx) {
  struct kk_handlers__mlift2522_advance_deep_fun3899__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2522_advance_deep_fun3899__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2522_advance_deep_fun3899, kk_context());
  _self->_bv_3099 = _bv_3099;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift2522_advance_deep_fun3899(kk_function_t _fself, kk_integer_t _b_3100, kk_context_t* _ctx) {
  struct kk_handlers__mlift2522_advance_deep_fun3899__t* _self = kk_function_as(struct kk_handlers__mlift2522_advance_deep_fun3899__t*, _fself);
  kk_function_t _bv_3099 = _self->_bv_3099; /* (3097) -> <effects-and-types/yield|704> 3098 */
  kk_drop_match(_self, {kk_function_dup(_bv_3099);}, {}, _ctx)
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _bv_3099, (_bv_3099, kk_integer_box(_b_3100), _ctx));
}


// lift anonymous function
struct kk_handlers__mlift2522_advance_deep_fun3900__t {
  struct kk_function_s _base;
  kk_function_t _bv_3117;
};
static kk_box_t kk_handlers__mlift2522_advance_deep_fun3900(kk_function_t _fself, kk_box_t _b_3118, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2522_advance_deep_fun3900(kk_function_t _bv_3117, kk_context_t* _ctx) {
  struct kk_handlers__mlift2522_advance_deep_fun3900__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2522_advance_deep_fun3900__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2522_advance_deep_fun3900, kk_context());
  _self->_bv_3117 = _bv_3117;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift2522_advance_deep_fun3900(kk_function_t _fself, kk_box_t _b_3118, kk_context_t* _ctx) {
  struct kk_handlers__mlift2522_advance_deep_fun3900__t* _self = kk_function_as(struct kk_handlers__mlift2522_advance_deep_fun3900__t*, _fself);
  kk_function_t _bv_3117 = _self->_bv_3117; /* (int) -> <effects-and-types/yield|704> 703 */
  kk_drop_match(_self, {kk_function_dup(_bv_3117);}, {}, _ctx)
  kk_integer_t _x3901 = kk_integer_unbox(_b_3118); /*int*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_context_t*), _bv_3117, (_bv_3117, _x3901, _ctx));
}
static kk_box_t kk_handlers__mlift2522_advance_deep_fun3886(kk_function_t _fself, kk_function_t _b_3102, kk_box_t _b_3103, kk_context_t* _ctx) {
  struct kk_handlers__mlift2522_advance_deep_fun3886__t* _self = kk_function_as(struct kk_handlers__mlift2522_advance_deep_fun3886__t*, _fself);
  size_t _y_27 = _self->_y_27; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  kk_function_t _x3887;
  kk_function_t _bv_3117;
  kk_function_t _bv_3099;
  kk_box_t _x3888 = kk_std_core_hnd_mask_at1(_y_27, false, kk_handlers__new_mlift2522_advance_deep_fun3889(_b_3102, _ctx), kk_function_box(kk_handlers__new_mlift2522_advance_deep_fun3897(_b_3103, _ctx)), _ctx); /*4675*/
  _bv_3099 = kk_function_unbox(_x3888); /*(3097) -> <effects-and-types/yield|704> 3098*/
  _bv_3117 = kk_handlers__new_mlift2522_advance_deep_fun3899(_bv_3099, _ctx); /*(int) -> <effects-and-types/yield|704> 703*/
  _x3887 = kk_handlers__new_mlift2522_advance_deep_fun3900(_bv_3117, _ctx); /*(3115) -> <effects-and-types/yield|704> 703*/
  return kk_function_box(_x3887);
}


// lift anonymous function
struct kk_handlers__mlift2522_advance_deep_fun3902__t {
  struct kk_function_s _base;
  kk_function_t _bv_3121;
};
static kk_box_t kk_handlers__mlift2522_advance_deep_fun3902(kk_function_t _fself, kk_integer_t _b_3122, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2522_advance_deep_fun3902(kk_function_t _bv_3121, kk_context_t* _ctx) {
  struct kk_handlers__mlift2522_advance_deep_fun3902__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2522_advance_deep_fun3902__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2522_advance_deep_fun3902, kk_context());
  _self->_bv_3121 = _bv_3121;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift2522_advance_deep_fun3902(kk_function_t _fself, kk_integer_t _b_3122, kk_context_t* _ctx) {
  struct kk_handlers__mlift2522_advance_deep_fun3902__t* _self = kk_function_as(struct kk_handlers__mlift2522_advance_deep_fun3902__t*, _fself);
  kk_function_t _bv_3121 = _self->_bv_3121; /* (3119) -> <.Box|.Box> 3120 */
  kk_drop_match(_self, {kk_function_dup(_bv_3121);}, {}, _ctx)
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _bv_3121, (_bv_3121, kk_integer_box(_b_3122), _ctx));
}


// lift anonymous function
struct kk_handlers__mlift2522_advance_deep_fun3903__t {
  struct kk_function_s _base;
};
static kk_box_t kk_handlers__mlift2522_advance_deep_fun3903(kk_function_t _fself, kk_box_t _b_3134, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2522_advance_deep_fun3903(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_handlers__mlift2522_advance_deep_fun3903, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_handlers__mlift2522_advance_deep_fun3904__t {
  struct kk_function_s _base;
  kk_box_t _b_3134;
};
static kk_box_t kk_handlers__mlift2522_advance_deep_fun3904(kk_function_t _fself, kk_integer_t _b_3137, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2522_advance_deep_fun3904(kk_box_t _b_3134, kk_context_t* _ctx) {
  struct kk_handlers__mlift2522_advance_deep_fun3904__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2522_advance_deep_fun3904__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2522_advance_deep_fun3904, kk_context());
  _self->_b_3134 = _b_3134;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift2522_advance_deep_fun3904(kk_function_t _fself, kk_integer_t _b_3137, kk_context_t* _ctx) {
  struct kk_handlers__mlift2522_advance_deep_fun3904__t* _self = kk_function_as(struct kk_handlers__mlift2522_advance_deep_fun3904__t*, _fself);
  kk_box_t _b_3134 = _self->_b_3134; /* 3990 */
  kk_drop_match(_self, {kk_box_dup(_b_3134);}, {}, _ctx)
  kk_function_t _x3905 = kk_function_unbox(_b_3134); /*(3135) -> <effects-and-types/yield|704> 3136*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x3905, (_x3905, kk_integer_box(_b_3137), _ctx));
}
static kk_box_t kk_handlers__mlift2522_advance_deep_fun3903(kk_function_t _fself, kk_box_t _b_3134, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return kk_handlers__mlift2521_advance_deep(kk_handlers__new_mlift2522_advance_deep_fun3904(_b_3134, _ctx), _ctx);
}

kk_box_t kk_handlers__mlift2522_advance_deep(kk_function_t resume, size_t _y_27, kk_context_t* _ctx) { /* forall<a,e> (resume : (()) -> e ((int) -> <effects-and-types/yield|e> a), std/core/hnd/ev-index) -> <effects-and-types/yield|e> a */ 
  kk_function_t x_2592;
  kk_evv_t w0 = kk_std_core_hnd_evv_swap_delete(_y_27, false, _ctx); /*std/core/hnd/evv<_4681>*/;
  kk_function_t x0 = kk_function_call(kk_function_t, (kk_function_t, kk_unit_t, kk_context_t*), resume, (resume, kk_Unit, _ctx)); /*(int) -> <effects-and-types/yield|704> 703*/;
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w0,kk_context());
  if (kk_yielding(kk_context())) {
    kk_function_drop(x0, _ctx);
    kk_function_t _bv_3121;
    kk_box_t _x3885 = kk_std_core_hnd_yield_cont(kk_handlers__new_mlift2522_advance_deep_fun3886(_y_27, _ctx), _ctx); /*3820*/
    _bv_3121 = kk_function_unbox(_x3885); /*(3119) -> <.Box|.Box> 3120*/
    x_2592 = kk_handlers__new_mlift2522_advance_deep_fun3902(_bv_3121, _ctx); /*(int) -> <effects-and-types/yield|704> 703*/
  }
  else {
    x_2592 = x0; /*(int) -> <effects-and-types/yield|704> 703*/
  }
  if (kk_yielding(kk_context())) {
    kk_function_drop(x_2592, _ctx);
    return kk_std_core_hnd_yield_extend(kk_handlers__new_mlift2522_advance_deep_fun3903(_ctx), _ctx);
  }
  return kk_handlers__mlift2521_advance_deep(x_2592, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_handlers__mlift2523_advance_deep_fun3907__t {
  struct kk_function_s _base;
  kk_function_t resume;
};
static kk_box_t kk_handlers__mlift2523_advance_deep_fun3907(kk_function_t _fself, kk_box_t _b_3141, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2523_advance_deep_fun3907(kk_function_t resume, kk_context_t* _ctx) {
  struct kk_handlers__mlift2523_advance_deep_fun3907__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2523_advance_deep_fun3907__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2523_advance_deep_fun3907, kk_context());
  _self->resume = resume;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift2523_advance_deep_fun3907(kk_function_t _fself, kk_box_t _b_3141, kk_context_t* _ctx) {
  struct kk_handlers__mlift2523_advance_deep_fun3907__t* _self = kk_function_as(struct kk_handlers__mlift2523_advance_deep_fun3907__t*, _fself);
  kk_function_t resume = _self->resume; /* (()) -> 704 ((int) -> <effects-and-types/yield|704> 703) */
  kk_drop_match(_self, {kk_function_dup(resume);}, {}, _ctx)
  size_t _x3908 = kk_size_unbox(_b_3141, _ctx); /*std/core/hnd/ev-index*/
  return kk_handlers__mlift2522_advance_deep(resume, _x3908, _ctx);
}

kk_box_t kk_handlers__mlift2523_advance_deep(kk_function_t resume, kk_unit_t wild__, kk_context_t* _ctx) { /* forall<a,e> (resume : (()) -> e ((int) -> <effects-and-types/yield|e> a), wild_ : ()) -> <effects-and-types/yield|e> a */ 
  size_t x_2597;
  kk_std_core_hnd__htag _x3906 = kk_std_core_hnd__htag_dup(kk_effects_dash_and_dash_types__tag_yield); /*std/core/hnd/htag<effects-and-types/.hnd-yield>*/
  x_2597 = kk_std_core_hnd__evv_index(_x3906, _ctx); /*std/core/hnd/ev-index*/
  if (kk_yielding(kk_context())) {
    return kk_std_core_hnd_yield_extend(kk_handlers__new_mlift2523_advance_deep_fun3907(resume, _ctx), _ctx);
  }
  return kk_handlers__mlift2522_advance_deep(resume, x_2597, _ctx);
}


// lift anonymous function
struct kk_handlers_advance_deep_fun3910__t {
  struct kk_function_s _base;
};
static kk_box_t kk_handlers_advance_deep_fun3910(kk_function_t _fself, kk_function_t _b_3172, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_advance_deep_fun3910(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_handlers_advance_deep_fun3910, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_handlers_advance_deep_fun3912__t {
  struct kk_function_s _base;
  kk_function_t _b_3172;
};
static kk_function_t kk_handlers_advance_deep_fun3912(kk_function_t _fself, kk_unit_t _b_3173, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_advance_deep_fun3912(kk_function_t _b_3172, kk_context_t* _ctx) {
  struct kk_handlers_advance_deep_fun3912__t* _self = kk_function_alloc_as(struct kk_handlers_advance_deep_fun3912__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_advance_deep_fun3912, kk_context());
  _self->_b_3172 = _b_3172;
  return &_self->_base;
}



// lift anonymous function
struct kk_handlers_advance_deep_fun3914__t {
  struct kk_function_s _base;
  kk_function_t _bv_3176;
};
static kk_box_t kk_handlers_advance_deep_fun3914(kk_function_t _fself, kk_integer_t _b_3177, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_advance_deep_fun3914(kk_function_t _bv_3176, kk_context_t* _ctx) {
  struct kk_handlers_advance_deep_fun3914__t* _self = kk_function_alloc_as(struct kk_handlers_advance_deep_fun3914__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_advance_deep_fun3914, kk_context());
  _self->_bv_3176 = _bv_3176;
  return &_self->_base;
}

static kk_box_t kk_handlers_advance_deep_fun3914(kk_function_t _fself, kk_integer_t _b_3177, kk_context_t* _ctx) {
  struct kk_handlers_advance_deep_fun3914__t* _self = kk_function_as(struct kk_handlers_advance_deep_fun3914__t*, _fself);
  kk_function_t _bv_3176 = _self->_bv_3176; /* (3174) -> <effects-and-types/yield|704> 3175 */
  kk_drop_match(_self, {kk_function_dup(_bv_3176);}, {}, _ctx)
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _bv_3176, (_bv_3176, kk_integer_box(_b_3177), _ctx));
}
static kk_function_t kk_handlers_advance_deep_fun3912(kk_function_t _fself, kk_unit_t _b_3173, kk_context_t* _ctx) {
  struct kk_handlers_advance_deep_fun3912__t* _self = kk_function_as(struct kk_handlers_advance_deep_fun3912__t*, _fself);
  kk_function_t _b_3172 = _self->_b_3172; /* (7164) -> 7165 7167 */
  kk_drop_match(_self, {kk_function_dup(_b_3172);}, {}, _ctx)
  kk_function_t _bv_3176;
  kk_box_t _x3913 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _b_3172, (_b_3172, kk_unit_box(_b_3173), _ctx)); /*7167*/
  _bv_3176 = kk_function_unbox(_x3913); /*(3174) -> <effects-and-types/yield|704> 3175*/
  return kk_handlers_new_advance_deep_fun3914(_bv_3176, _ctx);
}


// lift anonymous function
struct kk_handlers_advance_deep_fun3915__t {
  struct kk_function_s _base;
  kk_function_t resume_3200;
};
static kk_box_t kk_handlers_advance_deep_fun3915(kk_function_t _fself, kk_integer_t steps, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_advance_deep_fun3915(kk_function_t resume_3200, kk_context_t* _ctx) {
  struct kk_handlers_advance_deep_fun3915__t* _self = kk_function_alloc_as(struct kk_handlers_advance_deep_fun3915__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_advance_deep_fun3915, kk_context());
  _self->resume_3200 = resume_3200;
  return &_self->_base;
}



// lift anonymous function
struct kk_handlers_advance_deep_fun3918__t {
  struct kk_function_s _base;
  kk_function_t resume_3200;
  kk_integer_t steps;
};
static kk_box_t kk_handlers_advance_deep_fun3918(kk_function_t _fself, kk_box_t _b_3145, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_advance_deep_fun3918(kk_function_t resume_3200, kk_integer_t steps, kk_context_t* _ctx) {
  struct kk_handlers_advance_deep_fun3918__t* _self = kk_function_alloc_as(struct kk_handlers_advance_deep_fun3918__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_advance_deep_fun3918, kk_context());
  _self->resume_3200 = resume_3200;
  _self->steps = steps;
  return &_self->_base;
}

static kk_box_t kk_handlers_advance_deep_fun3918(kk_function_t _fself, kk_box_t _b_3145, kk_context_t* _ctx) {
  struct kk_handlers_advance_deep_fun3918__t* _self = kk_function_as(struct kk_handlers_advance_deep_fun3918__t*, _fself);
  kk_function_t resume_3200 = _self->resume_3200; /* (()) -> 704 ((int) -> <effects-and-types/yield|704> 703) */
  kk_integer_t steps = _self->steps; /* int */
  kk_drop_match(_self, {kk_function_dup(resume_3200);kk_integer_dup(steps);}, {}, _ctx)
  size_t _x3919 = kk_size_unbox(_b_3145, _ctx); /*std/core/hnd/ev-index*/
  return kk_handlers__mlift2520_advance_deep(resume_3200, steps, _x3919, _ctx);
}


// lift anonymous function
struct kk_handlers_advance_deep_fun3927__t {
  struct kk_function_s _base;
  size_t i_2603;
};
static kk_box_t kk_handlers_advance_deep_fun3927(kk_function_t _fself, kk_function_t _b_3159, kk_box_t _b_3160, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_advance_deep_fun3927(size_t i_2603, kk_context_t* _ctx) {
  struct kk_handlers_advance_deep_fun3927__t* _self = kk_function_alloc_as(struct kk_handlers_advance_deep_fun3927__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_advance_deep_fun3927, kk_context());
  _self->i_2603 = i_2603;
  return &_self->_base;
}

static kk_box_t kk_handlers_advance_deep_fun3927(kk_function_t _fself, kk_function_t _b_3159, kk_box_t _b_3160, kk_context_t* _ctx) {
  struct kk_handlers_advance_deep_fun3927__t* _self = kk_function_as(struct kk_handlers_advance_deep_fun3927__t*, _fself);
  size_t i_2603 = _self->i_2603; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_2603, _b_3159, _b_3160, _ctx);
}


// lift anonymous function
struct kk_handlers_advance_deep_fun3928__t {
  struct kk_function_s _base;
  kk_function_t resume_3200;
};
static kk_box_t kk_handlers_advance_deep_fun3928(kk_function_t _fself, kk_box_t _b_3170, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_advance_deep_fun3928(kk_function_t resume_3200, kk_context_t* _ctx) {
  struct kk_handlers_advance_deep_fun3928__t* _self = kk_function_alloc_as(struct kk_handlers_advance_deep_fun3928__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_advance_deep_fun3928, kk_context());
  _self->resume_3200 = resume_3200;
  return &_self->_base;
}

static kk_box_t kk_handlers_advance_deep_fun3928(kk_function_t _fself, kk_box_t _b_3170, kk_context_t* _ctx) {
  struct kk_handlers_advance_deep_fun3928__t* _self = kk_function_as(struct kk_handlers_advance_deep_fun3928__t*, _fself);
  kk_function_t resume_3200 = _self->resume_3200; /* (()) -> 704 ((int) -> <effects-and-types/yield|704> 703) */
  kk_drop_match(_self, {kk_function_dup(resume_3200);}, {}, _ctx)
  kk_unit_t _x3929 = kk_Unit;
  kk_unit_unbox(_b_3170);
  return kk_handlers__mlift2523_advance_deep(resume_3200, _x3929, _ctx);
}
static kk_box_t kk_handlers_advance_deep_fun3915(kk_function_t _fself, kk_integer_t steps, kk_context_t* _ctx) {
  struct kk_handlers_advance_deep_fun3915__t* _self = kk_function_as(struct kk_handlers_advance_deep_fun3915__t*, _fself);
  kk_function_t resume_3200 = _self->resume_3200; /* (()) -> 704 ((int) -> <effects-and-types/yield|704> 703) */
  kk_drop_match(_self, {kk_function_dup(resume_3200);}, {}, _ctx)
  bool _match_3705;
  kk_integer_t _x3916 = kk_integer_dup(steps); /*int*/
  _match_3705 = kk_integer_gt(_x3916,(kk_integer_from_small(0)),kk_context()); /*bool*/
  if (_match_3705) {
    size_t x_2599;
    kk_std_core_hnd__htag _x3917 = kk_std_core_hnd__htag_dup(kk_effects_dash_and_dash_types__tag_yield); /*std/core/hnd/htag<effects-and-types/.hnd-yield>*/
    x_2599 = kk_std_core_hnd__evv_index(_x3917, _ctx); /*std/core/hnd/ev-index*/
    if (kk_yielding(kk_context())) {
      return kk_std_core_hnd_yield_extend(kk_handlers_new_advance_deep_fun3918(resume_3200, steps, _ctx), _ctx);
    }
    return kk_handlers__mlift2520_advance_deep(resume_3200, steps, x_2599, _ctx);
  }
  kk_integer_drop(steps, _ctx);
  kk_unit_t x0_2601 = kk_Unit;
  size_t i_2603;
  kk_std_core_hnd__htag _x3920 = kk_std_core_hnd__htag_dup(kk_effects_dash_and_dash_types__tag_yield); /*std/core/hnd/htag<effects-and-types/.hnd-yield>*/
  i_2603 = kk_std_core_hnd__evv_index(_x3920, _ctx); /*std/core/hnd/ev-index*/
  kk_evv_t w = kk_evv_swap_create1(i_2603,kk_context()); /*std/core/hnd/evv<<effects-and-types/yield|704>>*/;
  kk_unit_t y = kk_Unit;
  kk_std_core_hnd__ev ev_409;
  size_t _x3921 = ((size_t)0); /*size_t*/
  ev_409 = kk_evv_at(_x3921,kk_context()); /*std/core/hnd/ev<effects-and-types/.hnd-yield>*/
  kk_box_t _x3922;
  struct kk_std_core_hnd_Ev* _con3923 = kk_std_core_hnd__as_Ev(ev_409);
  kk_std_core_hnd__marker m = _con3923->marker;
  kk_box_t _box_x3146 = _con3923->hnd;
  kk_effects_dash_and_dash_types__hnd_yield h = kk_effects_dash_and_dash_types__hnd_yield_unbox(_box_x3146, NULL);
  kk_effects_dash_and_dash_types__hnd_yield_dup(h);
  kk_std_core_hnd__clause0 _match_3708;
  struct kk_effects_dash_and_dash_types__Hnd_yield* _con3925 = kk_effects_dash_and_dash_types__as_Hnd_yield(h);
  kk_std_core_hnd__clause0 control_yield = _con3925->control_yield;
  if (kk_effects_dash_and_dash_types__hnd_yield_is_unique(h)) {
    kk_effects_dash_and_dash_types__hnd_yield_free(h);
  }
  else {
    kk_std_core_hnd__clause0_dup(control_yield);
    kk_effects_dash_and_dash_types__hnd_yield_decref(h, _ctx);
  }
  _match_3708 = control_yield; /*std/core/hnd/clause0<(),effects-and-types/.hnd-yield,3435,3436>*/
  kk_function_t _fun_unbox_x3149 = _match_3708.clause;
  _x3922 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x3149, (_fun_unbox_x3149, m, ev_409, _ctx)); /*37*/
  kk_unit_unbox(_x3922);
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x3926 = kk_std_core_hnd_yield_cont(kk_handlers_new_advance_deep_fun3927(i_2603, _ctx), _ctx); /*3820*/
    kk_unit_unbox(_x3926);
  }
  else {
    y;
  }
  if (kk_yielding(kk_context())) {
    return kk_std_core_hnd_yield_extend(kk_handlers_new_advance_deep_fun3928(resume_3200, _ctx), _ctx);
  }
  return kk_handlers__mlift2523_advance_deep(resume_3200, x0_2601, _ctx);
}


// lift anonymous function
struct kk_handlers_advance_deep_fun3930__t {
  struct kk_function_s _base;
  kk_function_t _bv_3180;
};
static kk_box_t kk_handlers_advance_deep_fun3930(kk_function_t _fself, kk_box_t _b_3181, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_advance_deep_fun3930(kk_function_t _bv_3180, kk_context_t* _ctx) {
  struct kk_handlers_advance_deep_fun3930__t* _self = kk_function_alloc_as(struct kk_handlers_advance_deep_fun3930__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_advance_deep_fun3930, kk_context());
  _self->_bv_3180 = _bv_3180;
  return &_self->_base;
}

static kk_box_t kk_handlers_advance_deep_fun3930(kk_function_t _fself, kk_box_t _b_3181, kk_context_t* _ctx) {
  struct kk_handlers_advance_deep_fun3930__t* _self = kk_function_as(struct kk_handlers_advance_deep_fun3930__t*, _fself);
  kk_function_t _bv_3180 = _self->_bv_3180; /* (steps : int) -> <effects-and-types/yield|704> 703 */
  kk_drop_match(_self, {kk_function_dup(_bv_3180);}, {}, _ctx)
  kk_integer_t _x3931 = kk_integer_unbox(_b_3181); /*int*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_context_t*), _bv_3180, (_bv_3180, _x3931, _ctx));
}
static kk_box_t kk_handlers_advance_deep_fun3910(kk_function_t _fself, kk_function_t _b_3172, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_function_t _x3911;
  kk_function_t _bv_3180;
  kk_function_t resume_3200 = kk_handlers_new_advance_deep_fun3912(_b_3172, _ctx); /*(()) -> 704 ((int) -> <effects-and-types/yield|704> 703)*/;
  _bv_3180 = kk_handlers_new_advance_deep_fun3915(resume_3200, _ctx); /*(steps : int) -> <effects-and-types/yield|704> 703*/
  _x3911 = kk_handlers_new_advance_deep_fun3930(_bv_3180, _ctx); /*(3178) -> <effects-and-types/yield|704> 703*/
  return kk_function_box(_x3911);
}


// lift anonymous function
struct kk_handlers_advance_deep_fun3933__t {
  struct kk_function_s _base;
};
static kk_box_t kk_handlers_advance_deep_fun3933(kk_function_t _fself, kk_box_t _b_3186, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_advance_deep_fun3933(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_handlers_advance_deep_fun3933, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_handlers_advance_deep_fun3935__t {
  struct kk_function_s _base;
  kk_box_t _b_3186;
};
static kk_box_t kk_handlers_advance_deep_fun3935(kk_function_t _fself, kk_integer_t ___wildcard__87__21, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_advance_deep_fun3935(kk_box_t _b_3186, kk_context_t* _ctx) {
  struct kk_handlers_advance_deep_fun3935__t* _self = kk_function_alloc_as(struct kk_handlers_advance_deep_fun3935__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_advance_deep_fun3935, kk_context());
  _self->_b_3186 = _b_3186;
  return &_self->_base;
}

static kk_box_t kk_handlers_advance_deep_fun3935(kk_function_t _fself, kk_integer_t ___wildcard__87__21, kk_context_t* _ctx) {
  struct kk_handlers_advance_deep_fun3935__t* _self = kk_function_as(struct kk_handlers_advance_deep_fun3935__t*, _fself);
  kk_box_t _b_3186 = _self->_b_3186; /* 281 */
  kk_drop_match(_self, {kk_box_dup(_b_3186);}, {}, _ctx)
  kk_integer_drop(___wildcard__87__21, _ctx);
  return _b_3186;
}


// lift anonymous function
struct kk_handlers_advance_deep_fun3936__t {
  struct kk_function_s _base;
  kk_function_t _bv_3189;
};
static kk_box_t kk_handlers_advance_deep_fun3936(kk_function_t _fself, kk_box_t _b_3190, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_advance_deep_fun3936(kk_function_t _bv_3189, kk_context_t* _ctx) {
  struct kk_handlers_advance_deep_fun3936__t* _self = kk_function_alloc_as(struct kk_handlers_advance_deep_fun3936__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_advance_deep_fun3936, kk_context());
  _self->_bv_3189 = _bv_3189;
  return &_self->_base;
}

static kk_box_t kk_handlers_advance_deep_fun3936(kk_function_t _fself, kk_box_t _b_3190, kk_context_t* _ctx) {
  struct kk_handlers_advance_deep_fun3936__t* _self = kk_function_as(struct kk_handlers_advance_deep_fun3936__t*, _fself);
  kk_function_t _bv_3189 = _self->_bv_3189; /* (int) -> <effects-and-types/yield|704> 703 */
  kk_drop_match(_self, {kk_function_dup(_bv_3189);}, {}, _ctx)
  kk_integer_t _x3937 = kk_integer_unbox(_b_3190); /*int*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_context_t*), _bv_3189, (_bv_3189, _x3937, _ctx));
}
static kk_box_t kk_handlers_advance_deep_fun3933(kk_function_t _fself, kk_box_t _b_3186, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_function_t _x3934;
  kk_function_t _bv_3189 = kk_handlers_new_advance_deep_fun3935(_b_3186, _ctx); /*(int) -> <effects-and-types/yield|704> 703*/;
  _x3934 = kk_handlers_new_advance_deep_fun3936(_bv_3189, _ctx); /*(3187) -> <effects-and-types/yield|704> 703*/
  return kk_function_box(_x3934);
}


// lift anonymous function
struct kk_handlers_advance_deep_fun3938__t {
  struct kk_function_s _base;
  kk_function_t _bv_3193;
};
static kk_box_t kk_handlers_advance_deep_fun3938(kk_function_t _fself, kk_integer_t _b_3194, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_advance_deep_fun3938(kk_function_t _bv_3193, kk_context_t* _ctx) {
  struct kk_handlers_advance_deep_fun3938__t* _self = kk_function_alloc_as(struct kk_handlers_advance_deep_fun3938__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_advance_deep_fun3938, kk_context());
  _self->_bv_3193 = _bv_3193;
  return &_self->_base;
}

static kk_box_t kk_handlers_advance_deep_fun3938(kk_function_t _fself, kk_integer_t _b_3194, kk_context_t* _ctx) {
  struct kk_handlers_advance_deep_fun3938__t* _self = kk_function_as(struct kk_handlers_advance_deep_fun3938__t*, _fself);
  kk_function_t _bv_3193 = _self->_bv_3193; /* (steps : 3191) -> <effects-and-types/yield|704> 3192 */
  kk_drop_match(_self, {kk_function_dup(_bv_3193);}, {}, _ctx)
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _bv_3193, (_bv_3193, kk_integer_box(_b_3194), _ctx));
}

kk_function_t kk_handlers_advance_deep(kk_function_t action, kk_context_t* _ctx) { /* forall<a,e> (action : () -> <effects-and-types/yield|e> a) -> e ((steps : int) -> <effects-and-types/yield|e> a) */ 
  int32_t _b_3195_3182 = ((int32_t)3); /*int32*/;
  kk_effects_dash_and_dash_types__hnd_yield _b_3196_3183;
  kk_std_core_hnd__clause0 _x3909 = kk_std_core_hnd_clause_control0(kk_handlers_new_advance_deep_fun3910(_ctx), _ctx); /*std/core/hnd/clause0<7164,7166,7165,7167>*/
  _b_3196_3183 = kk_effects_dash_and_dash_types__new_Hnd_yield(kk_reuse_null, _x3909, _ctx); /*effects-and-types/.hnd-yield<704,(steps : int) -> <effects-and-types/yield|704> 703>*/
  kk_function_t _bv_3193;
  kk_box_t _x3932 = kk_effects_dash_and_dash_types__handle_yield(_b_3195_3182, _b_3196_3183, kk_handlers_new_advance_deep_fun3933(_ctx), action, _ctx); /*283*/
  _bv_3193 = kk_function_unbox(_x3932); /*(steps : 3191) -> <effects-and-types/yield|704> 3192*/
  return kk_handlers_new_advance_deep_fun3938(_bv_3193, _ctx);
}


// lift anonymous function
struct kk_handlers_finalize_fun3941__t {
  struct kk_function_s _base;
};
static kk_box_t kk_handlers_finalize_fun3941(kk_function_t _fself, kk_std_core_hnd__marker _b_3207, kk_std_core_hnd__ev _b_3208, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_finalize_fun3941(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_handlers_finalize_fun3941, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_handlers_finalize_fun3941(kk_function_t _fself, kk_std_core_hnd__marker _b_3207, kk_std_core_hnd__ev _b_3208, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_core_hnd__ev_dropn(_b_3208, ((int32_t)3), _ctx);
  return kk_unit_box(kk_Unit);
}


// lift anonymous function
struct kk_handlers_finalize_fun3942__t {
  struct kk_function_s _base;
};
static kk_box_t kk_handlers_finalize_fun3942(kk_function_t _fself, kk_box_t _x, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_finalize_fun3942(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_handlers_finalize_fun3942, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_handlers_finalize_fun3942(kk_function_t _fself, kk_box_t _x, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return _x;
}

kk_box_t kk_handlers_finalize(kk_function_t action, kk_context_t* _ctx) { /* forall<a,e> (action : () -> <effects-and-types/yield|e> a) -> e a */ 
  kk_effects_dash_and_dash_types__hnd_yield _x3939;
  kk_std_core_hnd__clause0 _x3940 = kk_std_core_hnd__new_Clause0(kk_handlers_new_finalize_fun3941(_ctx), _ctx); /*std/core/hnd/clause0<37,38,39,40>*/
  _x3939 = kk_effects_dash_and_dash_types__new_Hnd_yield(kk_reuse_null, _x3940, _ctx); /*effects-and-types/.hnd-yield<25,26>*/
  return kk_effects_dash_and_dash_types__handle_yield(((int32_t)1), _x3939, kk_handlers_new_finalize_fun3942(_ctx), action, _ctx);
}


// lift anonymous function
struct kk_handlers_random__sampler_fun3945__t {
  struct kk_function_s _base;
};
static kk_box_t kk_handlers_random__sampler_fun3945(kk_function_t _fself, kk_std_core_hnd__marker _b_3236, kk_std_core_hnd__ev _b_3237, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_random__sampler_fun3945(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_handlers_random__sampler_fun3945, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_handlers_random__sampler_fun3950__t {
  struct kk_function_s _base;
  size_t i_2607;
};
static kk_box_t kk_handlers_random__sampler_fun3950(kk_function_t _fself, kk_function_t _b_3217, kk_box_t _b_3218, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_random__sampler_fun3950(size_t i_2607, kk_context_t* _ctx) {
  struct kk_handlers_random__sampler_fun3950__t* _self = kk_function_alloc_as(struct kk_handlers_random__sampler_fun3950__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_random__sampler_fun3950, kk_context());
  _self->i_2607 = i_2607;
  return &_self->_base;
}

static kk_box_t kk_handlers_random__sampler_fun3950(kk_function_t _fself, kk_function_t _b_3217, kk_box_t _b_3218, kk_context_t* _ctx) {
  struct kk_handlers_random__sampler_fun3950__t* _self = kk_function_as(struct kk_handlers_random__sampler_fun3950__t*, _fself);
  size_t i_2607 = _self->i_2607; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_2607, _b_3217, _b_3218, _ctx);
}


// lift anonymous function
struct kk_handlers_random__sampler_fun3952__t {
  struct kk_function_s _base;
  kk_std_core_hnd__ev _b_3237;
};
static kk_box_t kk_handlers_random__sampler_fun3952(kk_function_t _fself, kk_function_t _b_3232, kk_box_t _b_3233, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_random__sampler_fun3952(kk_std_core_hnd__ev _b_3237, kk_context_t* _ctx) {
  struct kk_handlers_random__sampler_fun3952__t* _self = kk_function_alloc_as(struct kk_handlers_random__sampler_fun3952__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_random__sampler_fun3952, kk_context());
  _self->_b_3237 = _b_3237;
  return &_self->_base;
}

static kk_box_t kk_handlers_random__sampler_fun3952(kk_function_t _fself, kk_function_t _b_3232, kk_box_t _b_3233, kk_context_t* _ctx) {
  struct kk_handlers_random__sampler_fun3952__t* _self = kk_function_as(struct kk_handlers_random__sampler_fun3952__t*, _fself);
  kk_std_core_hnd__ev _b_3237 = _self->_b_3237; /* std/core/hnd/ev<38> */
  kk_drop_match(_self, {kk_std_core_hnd__ev_dup(_b_3237);}, {}, _ctx)
  return kk_std_core_hnd_under1(_b_3237, _b_3232, _b_3233, _ctx);
}
static kk_box_t kk_handlers_random__sampler_fun3945(kk_function_t _fself, kk_std_core_hnd__marker _b_3236, kk_std_core_hnd__ev _b_3237, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x3946;
  kk_evv_t w0;
  kk_std_core_hnd__ev _x3947 = kk_std_core_hnd__ev_dup(_b_3237); /*std/core/hnd/ev<38>*/
  w0 = kk_std_core_hnd_evv_swap_with(_x3947, _ctx); /*std/core/hnd/evv<_8612>*/
  double y;
  size_t i_2607;
  kk_std_core_hnd__htag _x3948 = kk_std_core_hnd__htag_dup(kk_std_num_random__tag_random); /*std/core/hnd/htag<std/num/random/.hnd-random>*/
  i_2607 = kk_std_core_hnd__evv_index(_x3948, _ctx); /*std/core/hnd/ev-index*/
  kk_evv_t w = kk_evv_swap_create1(i_2607,kk_context()); /*std/core/hnd/evv<<std/num/random/random|802>>*/;
  double y0 = kk_std_num_random_random_double(_ctx); /*double*/;
  kk_unit_t __0 = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x3949 = kk_std_core_hnd_yield_cont(kk_handlers_new_random__sampler_fun3950(i_2607, _ctx), _ctx); /*3820*/
    y = kk_double_unbox(_x3949, _ctx); /*double*/
  }
  else {
    y = y0; /*double*/
  }
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w0,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x3951 = kk_std_core_hnd_yield_cont(kk_handlers_new_random__sampler_fun3952(_b_3237, _ctx), _ctx); /*3820*/
    _x3946 = kk_double_unbox(_x3951, _ctx); /*double*/
  }
  else {
    kk_std_core_hnd__ev_dropn(_b_3237, ((int32_t)3), _ctx);
    _x3946 = y; /*double*/
  }
  return kk_double_box(_x3946, _ctx);
}


// lift anonymous function
struct kk_handlers_random__sampler_fun3953__t {
  struct kk_function_s _base;
};
static kk_box_t kk_handlers_random__sampler_fun3953(kk_function_t _fself, kk_box_t _x, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_random__sampler_fun3953(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_handlers_random__sampler_fun3953, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_handlers_random__sampler_fun3953(kk_function_t _fself, kk_box_t _x, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return _x;
}

kk_box_t kk_handlers_random__sampler(kk_function_t action, kk_context_t* _ctx) { /* forall<a,e> (action : () -> <effects-and-types/sample,std/num/random/random|e> a) -> <std/num/random/random|e> a */ 
  kk_effects_dash_and_dash_types__hnd_sample _x3943;
  kk_std_core_hnd__clause0 _x3944 = kk_std_core_hnd__new_Clause0(kk_handlers_new_random__sampler_fun3945(_ctx), _ctx); /*std/core/hnd/clause0<37,38,39,40>*/
  _x3943 = kk_effects_dash_and_dash_types__new_Hnd_sample(kk_reuse_null, _x3944, _ctx); /*effects-and-types/.hnd-sample<6,7>*/
  return kk_effects_dash_and_dash_types__handle_sample(((int32_t)1), _x3943, kk_handlers_new_random__sampler_fun3953(_ctx), action, _ctx);
}
 
// monadic lift

double kk_handlers__mlift2524_recorder(double rand__choice, kk_unit_t wild__, kk_context_t* _ctx) { /* forall<h,e> (rand_choice : double, wild_ : ()) -> <local<h>,effects-and-types/sample|e> double */ 
  return rand__choice;
}
 
// monadic lift


// lift anonymous function
struct kk_handlers__mlift2525_recorder_fun3955__t {
  struct kk_function_s _base;
  double rand__choice;
};
static kk_box_t kk_handlers__mlift2525_recorder_fun3955(kk_function_t _fself, kk_box_t _b_3257, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2525_recorder_fun3955(double rand__choice, kk_context_t* _ctx) {
  struct kk_handlers__mlift2525_recorder_fun3955__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2525_recorder_fun3955__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2525_recorder_fun3955, kk_context());
  _self->rand__choice = rand__choice;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift2525_recorder_fun3955(kk_function_t _fself, kk_box_t _b_3257, kk_context_t* _ctx) {
  struct kk_handlers__mlift2525_recorder_fun3955__t* _self = kk_function_as(struct kk_handlers__mlift2525_recorder_fun3955__t*, _fself);
  double rand__choice = _self->rand__choice; /* double */
  kk_drop_match(_self, {;}, {}, _ctx)
  double _x3956;
  kk_unit_t _x3957 = kk_Unit;
  kk_unit_unbox(_b_3257);
  _x3956 = kk_handlers__mlift2524_recorder(rand__choice, _x3957, _ctx); /*double*/
  return kk_double_box(_x3956, _ctx);
}

double kk_handlers__mlift2525_recorder(double rand__choice, kk_ref_t trace, kk_std_core__list _y_37, kk_context_t* _ctx) { /* forall<h,e> (rand_choice : double, trace : local-var<h,effects-and-types/trace_values>, effects-and-types/trace_values) -> <local<h>,effects-and-types/sample|e> double */ 
  kk_unit_t x_2609 = kk_Unit;
  kk_std_core__list _b_3255_3253;
  kk_std_core__list ys_2612 = kk_std_core__new_Cons(kk_reuse_null, kk_double_box(rand__choice, _ctx), kk_std_core__new_Nil(_ctx), _ctx); /*list<double>*/;
  _b_3255_3253 = kk_std_core_append(_y_37, ys_2612, _ctx); /*list<double>*/
  (kk_ref_set(trace,(kk_std_core__list_box(_b_3255_3253, _ctx)),kk_context()));
  if (kk_yielding(kk_context())) {
    kk_box_t _x3954 = kk_std_core_hnd_yield_extend(kk_handlers__new_mlift2525_recorder_fun3955(rand__choice, _ctx), _ctx); /*3991*/
    return kk_double_unbox(_x3954, _ctx);
  }
  return kk_handlers__mlift2524_recorder(rand__choice, x_2609, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_handlers__mlift2526_recorder_fun3961__t {
  struct kk_function_s _base;
  kk_ref_t trace;
  double rand__choice;
};
static kk_box_t kk_handlers__mlift2526_recorder_fun3961(kk_function_t _fself, kk_box_t _b_3263, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2526_recorder_fun3961(kk_ref_t trace, double rand__choice, kk_context_t* _ctx) {
  struct kk_handlers__mlift2526_recorder_fun3961__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2526_recorder_fun3961__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2526_recorder_fun3961, kk_context());
  _self->trace = trace;
  _self->rand__choice = rand__choice;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift2526_recorder_fun3961(kk_function_t _fself, kk_box_t _b_3263, kk_context_t* _ctx) {
  struct kk_handlers__mlift2526_recorder_fun3961__t* _self = kk_function_as(struct kk_handlers__mlift2526_recorder_fun3961__t*, _fself);
  kk_ref_t trace = _self->trace; /* local-var<1091,effects-and-types/trace_values> */
  double rand__choice = _self->rand__choice; /* double */
  kk_drop_match(_self, {kk_ref_dup(trace);;}, {}, _ctx)
  double _x3962;
  kk_std_core__list _x3963 = kk_std_core__list_unbox(_b_3263, _ctx); /*effects-and-types/trace_values*/
  _x3962 = kk_handlers__mlift2525_recorder(rand__choice, trace, _x3963, _ctx); /*double*/
  return kk_double_box(_x3962, _ctx);
}

double kk_handlers__mlift2526_recorder(kk_ref_t trace, double rand__choice, kk_context_t* _ctx) { /* forall<h,e> (trace : local-var<h,effects-and-types/trace_values>, rand_choice : double) -> <effects-and-types/sample,local<h>|e> double */ 
  kk_std_core__list x_2613;
  kk_box_t _x3958;
  kk_ref_t _x3959 = kk_ref_dup(trace); /*local-var<1091,effects-and-types/trace_values>*/
  _x3958 = (kk_ref_get(_x3959,kk_context())); /*228*/
  x_2613 = kk_std_core__list_unbox(_x3958, _ctx); /*effects-and-types/trace_values*/
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_2613, _ctx);
    kk_box_t _x3960 = kk_std_core_hnd_yield_extend(kk_handlers__new_mlift2526_recorder_fun3961(trace, rand__choice, _ctx), _ctx); /*3991*/
    return kk_double_unbox(_x3960, _ctx);
  }
  return kk_handlers__mlift2525_recorder(rand__choice, trace, x_2613, _ctx);
}
 
// monadic lift

kk_std_core_types__tuple3_ kk_handlers__mlift2527_recorder(kk_box_t a, kk_box_t b, kk_std_core__list _y_39, kk_context_t* _ctx) { /* forall<h,a,b,e> (a : a, b : b, effects-and-types/trace_values) -> <local<h>,effects-and-types/sample|e> (effects-and-types/trace_values, a, b) */ 
  return kk_std_core_types__new_dash__lp__comma__comma__rp_(kk_std_core__list_box(_y_39, _ctx), a, b, _ctx);
}


// lift anonymous function
struct kk_handlers_recorder_fun3966__t {
  struct kk_function_s _base;
  kk_ref_t loc;
};
static kk_box_t kk_handlers_recorder_fun3966(kk_function_t _fself, kk_std_core_hnd__marker _b_3310, kk_std_core_hnd__ev _b_3311, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_recorder_fun3966(kk_ref_t loc, kk_context_t* _ctx) {
  struct kk_handlers_recorder_fun3966__t* _self = kk_function_alloc_as(struct kk_handlers_recorder_fun3966__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_recorder_fun3966, kk_context());
  _self->loc = loc;
  return &_self->_base;
}



// lift anonymous function
struct kk_handlers_recorder_fun3976__t {
  struct kk_function_s _base;
  size_t i_2622;
};
static kk_box_t kk_handlers_recorder_fun3976(kk_function_t _fself, kk_function_t _b_3287, kk_box_t _b_3288, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_recorder_fun3976(size_t i_2622, kk_context_t* _ctx) {
  struct kk_handlers_recorder_fun3976__t* _self = kk_function_alloc_as(struct kk_handlers_recorder_fun3976__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_recorder_fun3976, kk_context());
  _self->i_2622 = i_2622;
  return &_self->_base;
}

static kk_box_t kk_handlers_recorder_fun3976(kk_function_t _fself, kk_function_t _b_3287, kk_box_t _b_3288, kk_context_t* _ctx) {
  struct kk_handlers_recorder_fun3976__t* _self = kk_function_as(struct kk_handlers_recorder_fun3976__t*, _fself);
  size_t i_2622 = _self->i_2622; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_2622, _b_3287, _b_3288, _ctx);
}


// lift anonymous function
struct kk_handlers_recorder_fun3978__t {
  struct kk_function_s _base;
  kk_ref_t loc;
};
static kk_box_t kk_handlers_recorder_fun3978(kk_function_t _fself, kk_box_t _b_3298, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_recorder_fun3978(kk_ref_t loc, kk_context_t* _ctx) {
  struct kk_handlers_recorder_fun3978__t* _self = kk_function_alloc_as(struct kk_handlers_recorder_fun3978__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_recorder_fun3978, kk_context());
  _self->loc = loc;
  return &_self->_base;
}

static kk_box_t kk_handlers_recorder_fun3978(kk_function_t _fself, kk_box_t _b_3298, kk_context_t* _ctx) {
  struct kk_handlers_recorder_fun3978__t* _self = kk_function_as(struct kk_handlers_recorder_fun3978__t*, _fself);
  kk_ref_t loc = _self->loc; /* local-var<global,effects-and-types/trace_values> */
  kk_drop_match(_self, {kk_ref_dup(loc);}, {}, _ctx)
  double _x3979;
  double _x3980 = kk_double_unbox(_b_3298, _ctx); /*double*/
  _x3979 = kk_handlers__mlift2526_recorder(loc, _x3980, _ctx); /*double*/
  return kk_double_box(_x3979, _ctx);
}


// lift anonymous function
struct kk_handlers_recorder_fun3982__t {
  struct kk_function_s _base;
  kk_std_core_hnd__ev _b_3311;
};
static kk_box_t kk_handlers_recorder_fun3982(kk_function_t _fself, kk_function_t _b_3306, kk_box_t _b_3307, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_recorder_fun3982(kk_std_core_hnd__ev _b_3311, kk_context_t* _ctx) {
  struct kk_handlers_recorder_fun3982__t* _self = kk_function_alloc_as(struct kk_handlers_recorder_fun3982__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_recorder_fun3982, kk_context());
  _self->_b_3311 = _b_3311;
  return &_self->_base;
}

static kk_box_t kk_handlers_recorder_fun3982(kk_function_t _fself, kk_function_t _b_3306, kk_box_t _b_3307, kk_context_t* _ctx) {
  struct kk_handlers_recorder_fun3982__t* _self = kk_function_as(struct kk_handlers_recorder_fun3982__t*, _fself);
  kk_std_core_hnd__ev _b_3311 = _self->_b_3311; /* std/core/hnd/ev<38> */
  kk_drop_match(_self, {kk_std_core_hnd__ev_dup(_b_3311);}, {}, _ctx)
  return kk_std_core_hnd_under1(_b_3311, _b_3306, _b_3307, _ctx);
}
static kk_box_t kk_handlers_recorder_fun3966(kk_function_t _fself, kk_std_core_hnd__marker _b_3310, kk_std_core_hnd__ev _b_3311, kk_context_t* _ctx) {
  struct kk_handlers_recorder_fun3966__t* _self = kk_function_as(struct kk_handlers_recorder_fun3966__t*, _fself);
  kk_ref_t loc = _self->loc; /* local-var<global,effects-and-types/trace_values> */
  kk_drop_match(_self, {kk_ref_dup(loc);}, {}, _ctx)
  double _x3967;
  kk_evv_t w0;
  kk_std_core_hnd__ev _x3968 = kk_std_core_hnd__ev_dup(_b_3311); /*std/core/hnd/ev<38>*/
  w0 = kk_std_core_hnd_evv_swap_with(_x3968, _ctx); /*std/core/hnd/evv<_8612>*/
  double y;
  double x_2620;
  size_t i_2622;
  kk_std_core_hnd__htag _x3969 = kk_std_core_hnd__htag_dup(kk_effects_dash_and_dash_types__tag_sample); /*std/core/hnd/htag<effects-and-types/.hnd-sample>*/
  i_2622 = kk_std_core_hnd__evv_index(_x3969, _ctx); /*std/core/hnd/ev-index*/
  kk_evv_t w = kk_evv_swap_create1(i_2622,kk_context()); /*std/core/hnd/evv<<effects-and-types/sample,local<global>|1102>>*/;
  double y0;
  kk_std_core_hnd__ev ev_404;
  size_t _x3970 = ((size_t)0); /*size_t*/
  ev_404 = kk_evv_at(_x3970,kk_context()); /*std/core/hnd/ev<effects-and-types/.hnd-sample>*/
  kk_box_t _x3971;
  struct kk_std_core_hnd_Ev* _con3972 = kk_std_core_hnd__as_Ev(ev_404);
  kk_std_core_hnd__marker m = _con3972->marker;
  kk_box_t _box_x3274 = _con3972->hnd;
  kk_effects_dash_and_dash_types__hnd_sample h = kk_effects_dash_and_dash_types__hnd_sample_unbox(_box_x3274, NULL);
  kk_effects_dash_and_dash_types__hnd_sample_dup(h);
  kk_std_core_hnd__clause0 _match_3700;
  struct kk_effects_dash_and_dash_types__Hnd_sample* _con3974 = kk_effects_dash_and_dash_types__as_Hnd_sample(h);
  kk_std_core_hnd__clause0 fun_sample = _con3974->fun_sample;
  if (kk_effects_dash_and_dash_types__hnd_sample_is_unique(h)) {
    kk_effects_dash_and_dash_types__hnd_sample_free(h);
  }
  else {
    kk_std_core_hnd__clause0_dup(fun_sample);
    kk_effects_dash_and_dash_types__hnd_sample_decref(h, _ctx);
  }
  _match_3700 = fun_sample; /*std/core/hnd/clause0<double,effects-and-types/.hnd-sample,3435,3436>*/
  kk_function_t _fun_unbox_x3277 = _match_3700.clause;
  _x3971 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x3277, (_fun_unbox_x3277, m, ev_404, _ctx)); /*37*/
  y0 = kk_double_unbox(_x3971, _ctx); /*double*/
  kk_unit_t __0 = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x3975 = kk_std_core_hnd_yield_cont(kk_handlers_new_recorder_fun3976(i_2622, _ctx), _ctx); /*3820*/
    x_2620 = kk_double_unbox(_x3975, _ctx); /*double*/
  }
  else {
    x_2620 = y0; /*double*/
  }
  if (kk_yielding(kk_context())) {
    kk_box_t _x3977 = kk_std_core_hnd_yield_extend(kk_handlers_new_recorder_fun3978(loc, _ctx), _ctx); /*3991*/
    y = kk_double_unbox(_x3977, _ctx); /*double*/
  }
  else {
    y = kk_handlers__mlift2526_recorder(loc, x_2620, _ctx); /*double*/
  }
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w0,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x3981 = kk_std_core_hnd_yield_cont(kk_handlers_new_recorder_fun3982(_b_3311, _ctx), _ctx); /*3820*/
    _x3967 = kk_double_unbox(_x3981, _ctx); /*double*/
  }
  else {
    kk_std_core_hnd__ev_dropn(_b_3311, ((int32_t)3), _ctx);
    _x3967 = y; /*double*/
  }
  return kk_double_box(_x3967, _ctx);
}


// lift anonymous function
struct kk_handlers_recorder_fun3985__t {
  struct kk_function_s _base;
  kk_ref_t loc;
};
static kk_box_t kk_handlers_recorder_fun3985(kk_function_t _fself, kk_box_t _b_3321, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_recorder_fun3985(kk_ref_t loc, kk_context_t* _ctx) {
  struct kk_handlers_recorder_fun3985__t* _self = kk_function_alloc_as(struct kk_handlers_recorder_fun3985__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_recorder_fun3985, kk_context());
  _self->loc = loc;
  return &_self->_base;
}



// lift anonymous function
struct kk_handlers_recorder_fun3989__t {
  struct kk_function_s _base;
  kk_box_t a;
  kk_box_t b;
};
static kk_box_t kk_handlers_recorder_fun3989(kk_function_t _fself, kk_box_t _b_3315, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_recorder_fun3989(kk_box_t a, kk_box_t b, kk_context_t* _ctx) {
  struct kk_handlers_recorder_fun3989__t* _self = kk_function_alloc_as(struct kk_handlers_recorder_fun3989__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_recorder_fun3989, kk_context());
  _self->a = a;
  _self->b = b;
  return &_self->_base;
}

static kk_box_t kk_handlers_recorder_fun3989(kk_function_t _fself, kk_box_t _b_3315, kk_context_t* _ctx) {
  struct kk_handlers_recorder_fun3989__t* _self = kk_function_as(struct kk_handlers_recorder_fun3989__t*, _fself);
  kk_box_t a = _self->a; /* 1100 */
  kk_box_t b = _self->b; /* 1101 */
  kk_drop_match(_self, {kk_box_dup(a);kk_box_dup(b);}, {}, _ctx)
  kk_std_core_types__tuple3_ _x3990;
  kk_std_core__list _x3991 = kk_std_core__list_unbox(_b_3315, _ctx); /*effects-and-types/trace_values*/
  _x3990 = kk_handlers__mlift2527_recorder(a, b, _x3991, _ctx); /*(effects-and-types/trace_values, 1100, 1101)*/
  return kk_std_core_types__tuple3__box(_x3990, _ctx);
}
static kk_box_t kk_handlers_recorder_fun3985(kk_function_t _fself, kk_box_t _b_3321, kk_context_t* _ctx) {
  struct kk_handlers_recorder_fun3985__t* _self = kk_function_as(struct kk_handlers_recorder_fun3985__t*, _fself);
  kk_ref_t loc = _self->loc; /* local-var<global,effects-and-types/trace_values> */
  kk_drop_match(_self, {kk_ref_dup(loc);}, {}, _ctx)
  kk_std_core_types__tuple3_ _x3986;
  kk_std_core_types__tuple2_ _match_3695 = kk_std_core_types__tuple2__unbox(_b_3321, _ctx); /*(1100, 1101)*/;
  kk_box_t a = _match_3695.fst;
  kk_box_t b = _match_3695.snd;
  kk_box_dup(a);
  kk_box_dup(b);
  kk_std_core_types__tuple2__drop(_match_3695, _ctx);
  kk_std_core__list x1_2624;
  kk_box_t _x3987 = (kk_ref_get(loc,kk_context())); /*228*/
  x1_2624 = kk_std_core__list_unbox(_x3987, _ctx); /*effects-and-types/trace_values*/
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x1_2624, _ctx);
    kk_box_t _x3988 = kk_std_core_hnd_yield_extend(kk_handlers_new_recorder_fun3989(a, b, _ctx), _ctx); /*3991*/
    _x3986 = kk_std_core_types__tuple3__unbox(_x3988, _ctx); /*(effects-and-types/trace_values, 1100, 1101)*/
  }
  else {
    _x3986 = kk_handlers__mlift2527_recorder(a, b, x1_2624, _ctx); /*(effects-and-types/trace_values, 1100, 1101)*/
  }
  return kk_std_core_types__tuple3__box(_x3986, _ctx);
}


// lift anonymous function
struct kk_handlers_recorder_fun3992__t {
  struct kk_function_s _base;
  kk_function_t action;
};
static kk_box_t kk_handlers_recorder_fun3992(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_recorder_fun3992(kk_function_t action, kk_context_t* _ctx) {
  struct kk_handlers_recorder_fun3992__t* _self = kk_function_alloc_as(struct kk_handlers_recorder_fun3992__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_recorder_fun3992, kk_context());
  _self->action = action;
  return &_self->_base;
}



// lift anonymous function
struct kk_handlers_recorder_fun3993__t {
  struct kk_function_s _base;
  kk_function_t action;
};
static kk_box_t kk_handlers_recorder_fun3993(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_recorder_fun3993(kk_function_t action, kk_context_t* _ctx) {
  struct kk_handlers_recorder_fun3993__t* _self = kk_function_alloc_as(struct kk_handlers_recorder_fun3993__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_recorder_fun3993, kk_context());
  _self->action = action;
  return &_self->_base;
}

static kk_box_t kk_handlers_recorder_fun3993(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_handlers_recorder_fun3993__t* _self = kk_function_as(struct kk_handlers_recorder_fun3993__t*, _fself);
  kk_function_t action = _self->action; /* () -> <effects-and-types/sample,effects-and-types/sample|1102> (1100, 1101) */
  kk_drop_match(_self, {kk_function_dup(action);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x3994 = kk_function_call(kk_std_core_types__tuple2_, (kk_function_t, kk_context_t*), action, (action, _ctx)); /*(1100, 1101)*/
  return kk_std_core_types__tuple2__box(_x3994, _ctx);
}
static kk_box_t kk_handlers_recorder_fun3992(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_handlers_recorder_fun3992__t* _self = kk_function_as(struct kk_handlers_recorder_fun3992__t*, _fself);
  kk_function_t action = _self->action; /* () -> <effects-and-types/sample,effects-and-types/sample|1102> (1100, 1101) */
  kk_drop_match(_self, {kk_function_dup(action);}, {}, _ctx)
  return kk_std_core_hnd__mask_builtin(kk_handlers_new_recorder_fun3993(action, _ctx), _ctx);
}

kk_std_core_types__tuple3_ kk_handlers_recorder(kk_std_core__list model__trace, kk_function_t action, kk_context_t* _ctx) { /* forall<a,b,e> (model_trace : effects-and-types/trace_values, action : () -> <effects-and-types/sample,effects-and-types/sample|e> (a, b)) -> <effects-and-types/sample|e> (effects-and-types/trace_values, a, b) */ 
  kk_ref_t loc = kk_ref_alloc((kk_std_core__list_box(model__trace, _ctx)),kk_context()); /*local-var<global,effects-and-types/trace_values>*/;
  kk_std_core_types__tuple3_ res1;
  int32_t _b_3322_3317 = ((int32_t)1); /*int32*/;
  kk_effects_dash_and_dash_types__hnd_sample _b_3323_3318;
  kk_std_core_hnd__clause0 _x3964;
  kk_function_t _x3965;
  kk_ref_dup(loc);
  _x3965 = kk_handlers_new_recorder_fun3966(loc, _ctx); /*(std/core/hnd/marker<39,40>, std/core/hnd/ev<38>) -> 39 37*/
  _x3964 = kk_std_core_hnd__new_Clause0(_x3965, _ctx); /*std/core/hnd/clause0<37,38,39,40>*/
  _b_3323_3318 = kk_effects_dash_and_dash_types__new_Hnd_sample(kk_reuse_null, _x3964, _ctx); /*effects-and-types/.hnd-sample<<local<global>,effects-and-types/sample|1102>,(effects-and-types/trace_values, 1100, 1101)>*/
  kk_box_t _x3983;
  kk_function_t _x3984;
  kk_ref_dup(loc);
  _x3984 = kk_handlers_new_recorder_fun3985(loc, _ctx); /*(223) -> 224 225*/
  _x3983 = kk_effects_dash_and_dash_types__handle_sample(_b_3322_3317, _b_3323_3318, _x3984, kk_handlers_new_recorder_fun3992(action, _ctx), _ctx); /*225*/
  res1 = kk_std_core_types__tuple3__unbox(_x3983, _ctx); /*(effects-and-types/trace_values, 1100, 1101)*/
  kk_box_t _x3995 = kk_std_core_hnd_prompt_local_var(loc, kk_std_core_types__tuple3__box(res1, _ctx), _ctx); /*9788*/
  return kk_std_core_types__tuple3__unbox(_x3995, _ctx);
}
 
// monadic lift

double kk_handlers__mlift2528_replayx(double rand__choice, kk_unit_t wild__0, kk_context_t* _ctx) { /* forall<h,e> (rand_choice : double, wild_0 : ()) -> <local<h>,effects-and-types/sample|e> double */ 
  return rand__choice;
}
 
// monadic lift


// lift anonymous function
struct kk_handlers__mlift2529_replayx_fun3997__t {
  struct kk_function_s _base;
  double rand__choice;
};
static kk_box_t kk_handlers__mlift2529_replayx_fun3997(kk_function_t _fself, kk_box_t _b_3353, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2529_replayx_fun3997(double rand__choice, kk_context_t* _ctx) {
  struct kk_handlers__mlift2529_replayx_fun3997__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2529_replayx_fun3997__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2529_replayx_fun3997, kk_context());
  _self->rand__choice = rand__choice;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift2529_replayx_fun3997(kk_function_t _fself, kk_box_t _b_3353, kk_context_t* _ctx) {
  struct kk_handlers__mlift2529_replayx_fun3997__t* _self = kk_function_as(struct kk_handlers__mlift2529_replayx_fun3997__t*, _fself);
  double rand__choice = _self->rand__choice; /* double */
  kk_drop_match(_self, {;}, {}, _ctx)
  double _x3998;
  kk_unit_t _x3999 = kk_Unit;
  kk_unit_unbox(_b_3353);
  _x3998 = kk_handlers__mlift2528_replayx(rand__choice, _x3999, _ctx); /*double*/
  return kk_double_box(_x3998, _ctx);
}

double kk_handlers__mlift2529_replayx(kk_ref_t extended__trace, double rand__choice, kk_std_core__list _y_50, kk_context_t* _ctx) { /* forall<h,e> (extended_trace : local-var<h,list<double>>, rand_choice : double, list<double>) -> <local<h>,effects-and-types/sample|e> double */ 
  kk_unit_t x_2626 = kk_Unit;
  kk_std_core__list _b_3351_3349;
  kk_std_core__list ys_2629 = kk_std_core__new_Cons(kk_reuse_null, kk_double_box(rand__choice, _ctx), kk_std_core__new_Nil(_ctx), _ctx); /*list<double>*/;
  _b_3351_3349 = kk_std_core_append(_y_50, ys_2629, _ctx); /*list<double>*/
  (kk_ref_set(extended__trace,(kk_std_core__list_box(_b_3351_3349, _ctx)),kk_context()));
  if (kk_yielding(kk_context())) {
    kk_box_t _x3996 = kk_std_core_hnd_yield_extend(kk_handlers__new_mlift2529_replayx_fun3997(rand__choice, _ctx), _ctx); /*3991*/
    return kk_double_unbox(_x3996, _ctx);
  }
  return kk_handlers__mlift2528_replayx(rand__choice, x_2626, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_handlers__mlift2530_replayx_fun4003__t {
  struct kk_function_s _base;
  kk_ref_t extended__trace;
  double rand__choice;
};
static kk_box_t kk_handlers__mlift2530_replayx_fun4003(kk_function_t _fself, kk_box_t _b_3359, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2530_replayx_fun4003(kk_ref_t extended__trace, double rand__choice, kk_context_t* _ctx) {
  struct kk_handlers__mlift2530_replayx_fun4003__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2530_replayx_fun4003__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2530_replayx_fun4003, kk_context());
  _self->extended__trace = extended__trace;
  _self->rand__choice = rand__choice;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift2530_replayx_fun4003(kk_function_t _fself, kk_box_t _b_3359, kk_context_t* _ctx) {
  struct kk_handlers__mlift2530_replayx_fun4003__t* _self = kk_function_as(struct kk_handlers__mlift2530_replayx_fun4003__t*, _fself);
  kk_ref_t extended__trace = _self->extended__trace; /* local-var<2176,list<double>> */
  double rand__choice = _self->rand__choice; /* double */
  kk_drop_match(_self, {kk_ref_dup(extended__trace);;}, {}, _ctx)
  double _x4004;
  kk_std_core__list _x4005 = kk_std_core__list_unbox(_b_3359, _ctx); /*list<double>*/
  _x4004 = kk_handlers__mlift2529_replayx(extended__trace, rand__choice, _x4005, _ctx); /*double*/
  return kk_double_box(_x4004, _ctx);
}

double kk_handlers__mlift2530_replayx(kk_ref_t extended__trace, double rand__choice, kk_context_t* _ctx) { /* forall<h,e> (extended_trace : local-var<h,list<double>>, rand_choice : double) -> <effects-and-types/sample,local<h>|e> double */ 
  kk_std_core__list x_2630;
  kk_box_t _x4000;
  kk_ref_t _x4001 = kk_ref_dup(extended__trace); /*local-var<2176,list<double>>*/
  _x4000 = (kk_ref_get(_x4001,kk_context())); /*228*/
  x_2630 = kk_std_core__list_unbox(_x4000, _ctx); /*list<double>*/
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_2630, _ctx);
    kk_box_t _x4002 = kk_std_core_hnd_yield_extend(kk_handlers__new_mlift2530_replayx_fun4003(extended__trace, rand__choice, _ctx), _ctx); /*3991*/
    return kk_double_unbox(_x4002, _ctx);
  }
  return kk_handlers__mlift2529_replayx(extended__trace, rand__choice, x_2630, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_handlers__mlift2531_replayx_fun4013__t {
  struct kk_function_s _base;
  size_t i_2634;
};
static kk_box_t kk_handlers__mlift2531_replayx_fun4013(kk_function_t _fself, kk_function_t _b_3375, kk_box_t _b_3376, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2531_replayx_fun4013(size_t i_2634, kk_context_t* _ctx) {
  struct kk_handlers__mlift2531_replayx_fun4013__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2531_replayx_fun4013__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2531_replayx_fun4013, kk_context());
  _self->i_2634 = i_2634;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift2531_replayx_fun4013(kk_function_t _fself, kk_function_t _b_3375, kk_box_t _b_3376, kk_context_t* _ctx) {
  struct kk_handlers__mlift2531_replayx_fun4013__t* _self = kk_function_as(struct kk_handlers__mlift2531_replayx_fun4013__t*, _fself);
  size_t i_2634 = _self->i_2634; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_2634, _b_3375, _b_3376, _ctx);
}


// lift anonymous function
struct kk_handlers__mlift2531_replayx_fun4015__t {
  struct kk_function_s _base;
  kk_ref_t extended__trace;
};
static kk_box_t kk_handlers__mlift2531_replayx_fun4015(kk_function_t _fself, kk_box_t _b_3386, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2531_replayx_fun4015(kk_ref_t extended__trace, kk_context_t* _ctx) {
  struct kk_handlers__mlift2531_replayx_fun4015__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2531_replayx_fun4015__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2531_replayx_fun4015, kk_context());
  _self->extended__trace = extended__trace;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift2531_replayx_fun4015(kk_function_t _fself, kk_box_t _b_3386, kk_context_t* _ctx) {
  struct kk_handlers__mlift2531_replayx_fun4015__t* _self = kk_function_as(struct kk_handlers__mlift2531_replayx_fun4015__t*, _fself);
  kk_ref_t extended__trace = _self->extended__trace; /* local-var<2176,list<double>> */
  kk_drop_match(_self, {kk_ref_dup(extended__trace);}, {}, _ctx)
  double _x4016;
  double _x4017 = kk_double_unbox(_b_3386, _ctx); /*double*/
  _x4016 = kk_handlers__mlift2530_replayx(extended__trace, _x4017, _ctx); /*double*/
  return kk_double_box(_x4016, _ctx);
}

double kk_handlers__mlift2531_replayx(kk_std_core__list _y_47, kk_ref_t extended__trace, kk_integer_t _y_48, kk_context_t* _ctx) { /* forall<h,e> (list<double>, extended_trace : local-var<h,list<double>>, int) -> <local<h>,effects-and-types/sample|e> double */ 
  kk_std_core_types__maybe _match_3689 = kk_std_core__lp__lb__rb__2_rp_(_y_47, _y_48, _ctx); /*maybe<12037>*/;
  if (kk_std_core_types__is_Nothing(_match_3689)) {
    double x_2632;
    size_t i_2634;
    kk_std_core_hnd__htag _x4006 = kk_std_core_hnd__htag_dup(kk_effects_dash_and_dash_types__tag_sample); /*std/core/hnd/htag<effects-and-types/.hnd-sample>*/
    i_2634 = kk_std_core_hnd__evv_index(_x4006, _ctx); /*std/core/hnd/ev-index*/
    kk_evv_t w = kk_evv_swap_create1(i_2634,kk_context()); /*std/core/hnd/evv<<effects-and-types/sample,local<2176>|2184>>*/;
    double y;
    kk_std_core_hnd__ev ev_404;
    size_t _x4007 = ((size_t)0); /*size_t*/
    ev_404 = kk_evv_at(_x4007,kk_context()); /*std/core/hnd/ev<effects-and-types/.hnd-sample>*/
    kk_box_t _x4008;
    struct kk_std_core_hnd_Ev* _con4009 = kk_std_core_hnd__as_Ev(ev_404);
    kk_std_core_hnd__marker m = _con4009->marker;
    kk_box_t _box_x3362 = _con4009->hnd;
    kk_effects_dash_and_dash_types__hnd_sample h = kk_effects_dash_and_dash_types__hnd_sample_unbox(_box_x3362, NULL);
    kk_effects_dash_and_dash_types__hnd_sample_dup(h);
    kk_std_core_hnd__clause0 _match_3692;
    struct kk_effects_dash_and_dash_types__Hnd_sample* _con4011 = kk_effects_dash_and_dash_types__as_Hnd_sample(h);
    kk_std_core_hnd__clause0 fun_sample = _con4011->fun_sample;
    if (kk_effects_dash_and_dash_types__hnd_sample_is_unique(h)) {
      kk_effects_dash_and_dash_types__hnd_sample_free(h);
    }
    else {
      kk_std_core_hnd__clause0_dup(fun_sample);
      kk_effects_dash_and_dash_types__hnd_sample_decref(h, _ctx);
    }
    _match_3692 = fun_sample; /*std/core/hnd/clause0<double,effects-and-types/.hnd-sample,3435,3436>*/
    kk_function_t _fun_unbox_x3365 = _match_3692.clause;
    _x4008 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x3365, (_fun_unbox_x3365, m, ev_404, _ctx)); /*37*/
    y = kk_double_unbox(_x4008, _ctx); /*double*/
    kk_unit_t __ = kk_Unit;
    kk_evv_set(w,kk_context());
    if (kk_yielding(kk_context())) {
      kk_box_t _x4012 = kk_std_core_hnd_yield_cont(kk_handlers__new_mlift2531_replayx_fun4013(i_2634, _ctx), _ctx); /*3820*/
      x_2632 = kk_double_unbox(_x4012, _ctx); /*double*/
    }
    else {
      x_2632 = y; /*double*/
    }
    if (kk_yielding(kk_context())) {
      kk_box_t _x4014 = kk_std_core_hnd_yield_extend(kk_handlers__new_mlift2531_replayx_fun4015(extended__trace, _ctx), _ctx); /*3991*/
      return kk_double_unbox(_x4014, _ctx);
    }
    return kk_handlers__mlift2530_replayx(extended__trace, x_2632, _ctx);
  }
  kk_box_t _box_x3387 = _match_3689._cons.Just.value;
  double random__value = kk_double_unbox(_box_x3387, NULL);
  kk_ref_drop(extended__trace, _ctx);
  kk_std_core_types__maybe_drop(_match_3689, _ctx);
  return random__value;
}
 
// monadic lift


// lift anonymous function
struct kk_handlers__mlift2532_replayx_fun4021__t {
  struct kk_function_s _base;
  kk_std_core__list _y_47;
  kk_ref_t extended__trace;
};
static kk_box_t kk_handlers__mlift2532_replayx_fun4021(kk_function_t _fself, kk_box_t _b_3393, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2532_replayx_fun4021(kk_std_core__list _y_47, kk_ref_t extended__trace, kk_context_t* _ctx) {
  struct kk_handlers__mlift2532_replayx_fun4021__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2532_replayx_fun4021__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2532_replayx_fun4021, kk_context());
  _self->_y_47 = _y_47;
  _self->extended__trace = extended__trace;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift2532_replayx_fun4021(kk_function_t _fself, kk_box_t _b_3393, kk_context_t* _ctx) {
  struct kk_handlers__mlift2532_replayx_fun4021__t* _self = kk_function_as(struct kk_handlers__mlift2532_replayx_fun4021__t*, _fself);
  kk_std_core__list _y_47 = _self->_y_47; /* list<double> */
  kk_ref_t extended__trace = _self->extended__trace; /* local-var<2176,list<double>> */
  kk_drop_match(_self, {kk_std_core__list_dup(_y_47);kk_ref_dup(extended__trace);}, {}, _ctx)
  double _x4022;
  kk_integer_t _x4023 = kk_integer_unbox(_b_3393); /*int*/
  _x4022 = kk_handlers__mlift2531_replayx(_y_47, extended__trace, _x4023, _ctx); /*double*/
  return kk_double_box(_x4022, _ctx);
}

double kk_handlers__mlift2532_replayx(kk_ref_t extended__trace, kk_ref_t index, kk_std_core__list _y_47, kk_context_t* _ctx) { /* forall<h,e> (extended_trace : local-var<h,list<double>>, index : local-var<h,int>, list<double>) -> <local<h>,effects-and-types/sample|e> double */ 
  kk_integer_t x_2636;
  kk_box_t _x4019 = (kk_ref_get(index,kk_context())); /*228*/
  x_2636 = kk_integer_unbox(_x4019); /*int*/
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_2636, _ctx);
    kk_box_t _x4020 = kk_std_core_hnd_yield_extend(kk_handlers__new_mlift2532_replayx_fun4021(_y_47, extended__trace, _ctx), _ctx); /*3991*/
    return kk_double_unbox(_x4020, _ctx);
  }
  return kk_handlers__mlift2531_replayx(_y_47, extended__trace, x_2636, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_handlers__mlift2533_replayx_fun4027__t {
  struct kk_function_s _base;
  kk_ref_t extended__trace;
  kk_ref_t index;
};
static kk_box_t kk_handlers__mlift2533_replayx_fun4027(kk_function_t _fself, kk_box_t _b_3399, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2533_replayx_fun4027(kk_ref_t extended__trace, kk_ref_t index, kk_context_t* _ctx) {
  struct kk_handlers__mlift2533_replayx_fun4027__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2533_replayx_fun4027__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2533_replayx_fun4027, kk_context());
  _self->extended__trace = extended__trace;
  _self->index = index;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift2533_replayx_fun4027(kk_function_t _fself, kk_box_t _b_3399, kk_context_t* _ctx) {
  struct kk_handlers__mlift2533_replayx_fun4027__t* _self = kk_function_as(struct kk_handlers__mlift2533_replayx_fun4027__t*, _fself);
  kk_ref_t extended__trace = _self->extended__trace; /* local-var<2176,list<double>> */
  kk_ref_t index = _self->index; /* local-var<2176,int> */
  kk_drop_match(_self, {kk_ref_dup(extended__trace);kk_ref_dup(index);}, {}, _ctx)
  double _x4028;
  kk_std_core__list _x4029 = kk_std_core__list_unbox(_b_3399, _ctx); /*list<double>*/
  _x4028 = kk_handlers__mlift2532_replayx(extended__trace, index, _x4029, _ctx); /*double*/
  return kk_double_box(_x4028, _ctx);
}

double kk_handlers__mlift2533_replayx(kk_ref_t extended__trace, kk_ref_t index, kk_unit_t wild__, kk_context_t* _ctx) { /* forall<h,e> (extended_trace : local-var<h,list<double>>, index : local-var<h,int>, wild_ : ()) -> <local<h>,effects-and-types/sample|e> double */ 
  kk_std_core__list x_2638;
  kk_box_t _x4024;
  kk_ref_t _x4025 = kk_ref_dup(extended__trace); /*local-var<2176,list<double>>*/
  _x4024 = (kk_ref_get(_x4025,kk_context())); /*228*/
  x_2638 = kk_std_core__list_unbox(_x4024, _ctx); /*list<double>*/
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_2638, _ctx);
    kk_box_t _x4026 = kk_std_core_hnd_yield_extend(kk_handlers__new_mlift2533_replayx_fun4027(extended__trace, index, _ctx), _ctx); /*3991*/
    return kk_double_unbox(_x4026, _ctx);
  }
  return kk_handlers__mlift2532_replayx(extended__trace, index, x_2638, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_handlers__mlift2534_replayx_fun4032__t {
  struct kk_function_s _base;
  kk_ref_t extended__trace;
  kk_ref_t index;
};
static kk_box_t kk_handlers__mlift2534_replayx_fun4032(kk_function_t _fself, kk_box_t _b_3407, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2534_replayx_fun4032(kk_ref_t extended__trace, kk_ref_t index, kk_context_t* _ctx) {
  struct kk_handlers__mlift2534_replayx_fun4032__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2534_replayx_fun4032__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2534_replayx_fun4032, kk_context());
  _self->extended__trace = extended__trace;
  _self->index = index;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift2534_replayx_fun4032(kk_function_t _fself, kk_box_t _b_3407, kk_context_t* _ctx) {
  struct kk_handlers__mlift2534_replayx_fun4032__t* _self = kk_function_as(struct kk_handlers__mlift2534_replayx_fun4032__t*, _fself);
  kk_ref_t extended__trace = _self->extended__trace; /* local-var<2176,list<double>> */
  kk_ref_t index = _self->index; /* local-var<2176,int> */
  kk_drop_match(_self, {kk_ref_dup(extended__trace);kk_ref_dup(index);}, {}, _ctx)
  double _x4033;
  kk_unit_t _x4034 = kk_Unit;
  kk_unit_unbox(_b_3407);
  _x4033 = kk_handlers__mlift2533_replayx(extended__trace, index, _x4034, _ctx); /*double*/
  return kk_double_box(_x4033, _ctx);
}

double kk_handlers__mlift2534_replayx(kk_ref_t extended__trace, kk_ref_t index, kk_integer_t _y_45, kk_context_t* _ctx) { /* forall<h,e> (extended_trace : local-var<h,list<double>>, index : local-var<h,int>, int) -> <local<h>,effects-and-types/sample|e> double */ 
  kk_unit_t x_2640 = kk_Unit;
  kk_integer_t _b_3405_3403 = kk_integer_add(_y_45,(kk_integer_from_small(1)),kk_context()); /*int*/;
  kk_ref_t _x4030 = kk_ref_dup(index); /*local-var<2176,int>*/
  (kk_ref_set(_x4030,(kk_integer_box(_b_3405_3403)),kk_context()));
  if (kk_yielding(kk_context())) {
    kk_box_t _x4031 = kk_std_core_hnd_yield_extend(kk_handlers__new_mlift2534_replayx_fun4032(extended__trace, index, _ctx), _ctx); /*3991*/
    return kk_double_unbox(_x4031, _ctx);
  }
  return kk_handlers__mlift2533_replayx(extended__trace, index, x_2640, _ctx);
}
 
// monadic lift

kk_std_core_types__tuple2_ kk_handlers__mlift2535_replayx(kk_std_core__list _y_53, kk_box_t x, kk_integer_t _y_54, kk_context_t* _ctx) { /* forall<h,a,e> (list<double>, x : a, int) -> <local<h>,effects-and-types/sample|e> (list<double>, a) */ 
  kk_std_core__list _b_3418_3416;
  kk_std_core_types__tuple2_ _this_2642;
  kk_integer_t n_2644 = kk_integer_add(_y_54,(kk_integer_from_small(1)),kk_context()); /*int*/;
  kk_std_core__list _b_3412_3410;
  kk_std_core__list _x4035 = kk_std_core__list_dup(_y_53); /*list<double>*/
  kk_integer_t _x4036 = kk_integer_dup(n_2644); /*int*/
  _b_3412_3410 = kk_std_core_take(_x4035, _x4036, _ctx); /*list<double>*/
  kk_std_core__list _b_3413_3411 = kk_std_core_drop(_y_53, n_2644, _ctx); /*list<double>*/;
  _this_2642 = kk_std_core_types__new_dash__lp__comma__rp_(kk_std_core__list_box(_b_3412_3410, _ctx), kk_std_core__list_box(_b_3413_3411, _ctx), _ctx); /*(list<double>, list<double>)*/
  kk_box_t _box_x3414 = _this_2642.fst;
  kk_box_t _box_x3415 = _this_2642.snd;
  kk_std_core__list _x = kk_std_core__list_unbox(_box_x3414, NULL);
  kk_std_core__list_dup(_x);
  kk_std_core_types__tuple2__drop(_this_2642, _ctx);
  _b_3418_3416 = _x; /*list<double>*/
  return kk_std_core_types__new_dash__lp__comma__rp_(kk_std_core__list_box(_b_3418_3416, _ctx), x, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_handlers__mlift2536_replayx_fun4041__t {
  struct kk_function_s _base;
  kk_std_core__list _y_53;
  kk_box_t x;
};
static kk_box_t kk_handlers__mlift2536_replayx_fun4041(kk_function_t _fself, kk_box_t _b_3423, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2536_replayx_fun4041(kk_std_core__list _y_53, kk_box_t x, kk_context_t* _ctx) {
  struct kk_handlers__mlift2536_replayx_fun4041__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2536_replayx_fun4041__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2536_replayx_fun4041, kk_context());
  _self->_y_53 = _y_53;
  _self->x = x;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift2536_replayx_fun4041(kk_function_t _fself, kk_box_t _b_3423, kk_context_t* _ctx) {
  struct kk_handlers__mlift2536_replayx_fun4041__t* _self = kk_function_as(struct kk_handlers__mlift2536_replayx_fun4041__t*, _fself);
  kk_std_core__list _y_53 = _self->_y_53; /* list<double> */
  kk_box_t x = _self->x; /* 2183 */
  kk_drop_match(_self, {kk_std_core__list_dup(_y_53);kk_box_dup(x);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x4042;
  kk_integer_t _x4043 = kk_integer_unbox(_b_3423); /*int*/
  _x4042 = kk_handlers__mlift2535_replayx(_y_53, x, _x4043, _ctx); /*(list<double>, 2183)*/
  return kk_std_core_types__tuple2__box(_x4042, _ctx);
}

kk_std_core_types__tuple2_ kk_handlers__mlift2536_replayx(kk_ref_t index, kk_box_t x, kk_std_core__list _y_53, kk_context_t* _ctx) { /* forall<h,a,e> (index : local-var<h,int>, x : a, list<double>) -> <local<h>,effects-and-types/sample|e> (list<double>, a) */ 
  kk_integer_t x0_2645;
  kk_box_t _x4039 = (kk_ref_get(index,kk_context())); /*228*/
  x0_2645 = kk_integer_unbox(_x4039); /*int*/
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x0_2645, _ctx);
    kk_box_t _x4040 = kk_std_core_hnd_yield_extend(kk_handlers__new_mlift2536_replayx_fun4041(_y_53, x, _ctx), _ctx); /*3991*/
    return kk_std_core_types__tuple2__unbox(_x4040, _ctx);
  }
  return kk_handlers__mlift2535_replayx(_y_53, x, x0_2645, _ctx);
}


// lift anonymous function
struct kk_handlers_replayx_fun4046__t {
  struct kk_function_s _base;
  kk_ref_t loc;
  kk_ref_t loc0;
};
static kk_box_t kk_handlers_replayx_fun4046(kk_function_t _fself, kk_std_core_hnd__marker _b_3445, kk_std_core_hnd__ev _b_3446, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_replayx_fun4046(kk_ref_t loc, kk_ref_t loc0, kk_context_t* _ctx) {
  struct kk_handlers_replayx_fun4046__t* _self = kk_function_alloc_as(struct kk_handlers_replayx_fun4046__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_replayx_fun4046, kk_context());
  _self->loc = loc;
  _self->loc0 = loc0;
  return &_self->_base;
}



// lift anonymous function
struct kk_handlers_replayx_fun4052__t {
  struct kk_function_s _base;
  kk_ref_t loc;
  kk_ref_t loc0;
};
static kk_box_t kk_handlers_replayx_fun4052(kk_function_t _fself, kk_box_t _b_3433, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_replayx_fun4052(kk_ref_t loc, kk_ref_t loc0, kk_context_t* _ctx) {
  struct kk_handlers_replayx_fun4052__t* _self = kk_function_alloc_as(struct kk_handlers_replayx_fun4052__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_replayx_fun4052, kk_context());
  _self->loc = loc;
  _self->loc0 = loc0;
  return &_self->_base;
}

static kk_box_t kk_handlers_replayx_fun4052(kk_function_t _fself, kk_box_t _b_3433, kk_context_t* _ctx) {
  struct kk_handlers_replayx_fun4052__t* _self = kk_function_as(struct kk_handlers_replayx_fun4052__t*, _fself);
  kk_ref_t loc = _self->loc; /* local-var<global,list<double>> */
  kk_ref_t loc0 = _self->loc0; /* local-var<global,int> */
  kk_drop_match(_self, {kk_ref_dup(loc);kk_ref_dup(loc0);}, {}, _ctx)
  double _x4053;
  kk_integer_t _x4054 = kk_integer_unbox(_b_3433); /*int*/
  _x4053 = kk_handlers__mlift2534_replayx(loc, loc0, _x4054, _ctx); /*double*/
  return kk_double_box(_x4053, _ctx);
}


// lift anonymous function
struct kk_handlers_replayx_fun4056__t {
  struct kk_function_s _base;
  kk_std_core_hnd__ev _b_3446;
};
static kk_box_t kk_handlers_replayx_fun4056(kk_function_t _fself, kk_function_t _b_3441, kk_box_t _b_3442, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_replayx_fun4056(kk_std_core_hnd__ev _b_3446, kk_context_t* _ctx) {
  struct kk_handlers_replayx_fun4056__t* _self = kk_function_alloc_as(struct kk_handlers_replayx_fun4056__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_replayx_fun4056, kk_context());
  _self->_b_3446 = _b_3446;
  return &_self->_base;
}

static kk_box_t kk_handlers_replayx_fun4056(kk_function_t _fself, kk_function_t _b_3441, kk_box_t _b_3442, kk_context_t* _ctx) {
  struct kk_handlers_replayx_fun4056__t* _self = kk_function_as(struct kk_handlers_replayx_fun4056__t*, _fself);
  kk_std_core_hnd__ev _b_3446 = _self->_b_3446; /* std/core/hnd/ev<38> */
  kk_drop_match(_self, {kk_std_core_hnd__ev_dup(_b_3446);}, {}, _ctx)
  return kk_std_core_hnd_under1(_b_3446, _b_3441, _b_3442, _ctx);
}
static kk_box_t kk_handlers_replayx_fun4046(kk_function_t _fself, kk_std_core_hnd__marker _b_3445, kk_std_core_hnd__ev _b_3446, kk_context_t* _ctx) {
  struct kk_handlers_replayx_fun4046__t* _self = kk_function_as(struct kk_handlers_replayx_fun4046__t*, _fself);
  kk_ref_t loc = _self->loc; /* local-var<global,list<double>> */
  kk_ref_t loc0 = _self->loc0; /* local-var<global,int> */
  kk_drop_match(_self, {kk_ref_dup(loc);kk_ref_dup(loc0);}, {}, _ctx)
  double _x4047;
  kk_evv_t w0;
  kk_std_core_hnd__ev _x4048 = kk_std_core_hnd__ev_dup(_b_3446); /*std/core/hnd/ev<38>*/
  w0 = kk_std_core_hnd_evv_swap_with(_x4048, _ctx); /*std/core/hnd/evv<_8612>*/
  double y;
  kk_integer_t x_2655;
  kk_box_t _x4049;
  kk_ref_t _x4050 = kk_ref_dup(loc0); /*local-var<global,int>*/
  _x4049 = (kk_ref_get(_x4050,kk_context())); /*228*/
  x_2655 = kk_integer_unbox(_x4049); /*int*/
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_2655, _ctx);
    kk_box_t _x4051 = kk_std_core_hnd_yield_extend(kk_handlers_new_replayx_fun4052(loc, loc0, _ctx), _ctx); /*3991*/
    y = kk_double_unbox(_x4051, _ctx); /*double*/
  }
  else {
    y = kk_handlers__mlift2534_replayx(loc, loc0, x_2655, _ctx); /*double*/
  }
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w0,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x4055 = kk_std_core_hnd_yield_cont(kk_handlers_new_replayx_fun4056(_b_3446, _ctx), _ctx); /*3820*/
    _x4047 = kk_double_unbox(_x4055, _ctx); /*double*/
  }
  else {
    kk_std_core_hnd__ev_dropn(_b_3446, ((int32_t)3), _ctx);
    _x4047 = y; /*double*/
  }
  return kk_double_box(_x4047, _ctx);
}


// lift anonymous function
struct kk_handlers_replayx_fun4059__t {
  struct kk_function_s _base;
  kk_ref_t loc;
  kk_ref_t loc0;
};
static kk_box_t kk_handlers_replayx_fun4059(kk_function_t _fself, kk_box_t _b_3455, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_replayx_fun4059(kk_ref_t loc, kk_ref_t loc0, kk_context_t* _ctx) {
  struct kk_handlers_replayx_fun4059__t* _self = kk_function_alloc_as(struct kk_handlers_replayx_fun4059__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_replayx_fun4059, kk_context());
  _self->loc = loc;
  _self->loc0 = loc0;
  return &_self->_base;
}



// lift anonymous function
struct kk_handlers_replayx_fun4063__t {
  struct kk_function_s _base;
  kk_box_t _b_3455;
  kk_ref_t loc0;
};
static kk_box_t kk_handlers_replayx_fun4063(kk_function_t _fself, kk_box_t _b_3450, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_replayx_fun4063(kk_box_t _b_3455, kk_ref_t loc0, kk_context_t* _ctx) {
  struct kk_handlers_replayx_fun4063__t* _self = kk_function_alloc_as(struct kk_handlers_replayx_fun4063__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_replayx_fun4063, kk_context());
  _self->_b_3455 = _b_3455;
  _self->loc0 = loc0;
  return &_self->_base;
}

static kk_box_t kk_handlers_replayx_fun4063(kk_function_t _fself, kk_box_t _b_3450, kk_context_t* _ctx) {
  struct kk_handlers_replayx_fun4063__t* _self = kk_function_as(struct kk_handlers_replayx_fun4063__t*, _fself);
  kk_box_t _b_3455 = _self->_b_3455; /* 223 */
  kk_ref_t loc0 = _self->loc0; /* local-var<global,int> */
  kk_drop_match(_self, {kk_box_dup(_b_3455);kk_ref_dup(loc0);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x4064;
  kk_std_core__list _x4065 = kk_std_core__list_unbox(_b_3450, _ctx); /*list<double>*/
  _x4064 = kk_handlers__mlift2536_replayx(loc0, _b_3455, _x4065, _ctx); /*(list<double>, 2183)*/
  return kk_std_core_types__tuple2__box(_x4064, _ctx);
}
static kk_box_t kk_handlers_replayx_fun4059(kk_function_t _fself, kk_box_t _b_3455, kk_context_t* _ctx) {
  struct kk_handlers_replayx_fun4059__t* _self = kk_function_as(struct kk_handlers_replayx_fun4059__t*, _fself);
  kk_ref_t loc = _self->loc; /* local-var<global,list<double>> */
  kk_ref_t loc0 = _self->loc0; /* local-var<global,int> */
  kk_drop_match(_self, {kk_ref_dup(loc);kk_ref_dup(loc0);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x4060;
  kk_std_core__list x1_2657;
  kk_box_t _x4061 = (kk_ref_get(loc,kk_context())); /*228*/
  x1_2657 = kk_std_core__list_unbox(_x4061, _ctx); /*list<double>*/
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x1_2657, _ctx);
    kk_box_t _x4062 = kk_std_core_hnd_yield_extend(kk_handlers_new_replayx_fun4063(_b_3455, loc0, _ctx), _ctx); /*3991*/
    _x4060 = kk_std_core_types__tuple2__unbox(_x4062, _ctx); /*(list<double>, 2183)*/
  }
  else {
    _x4060 = kk_handlers__mlift2536_replayx(loc0, _b_3455, x1_2657, _ctx); /*(list<double>, 2183)*/
  }
  return kk_std_core_types__tuple2__box(_x4060, _ctx);
}


// lift anonymous function
struct kk_handlers_replayx_fun4066__t {
  struct kk_function_s _base;
  kk_function_t action;
};
static kk_box_t kk_handlers_replayx_fun4066(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_replayx_fun4066(kk_function_t action, kk_context_t* _ctx) {
  struct kk_handlers_replayx_fun4066__t* _self = kk_function_alloc_as(struct kk_handlers_replayx_fun4066__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_replayx_fun4066, kk_context());
  _self->action = action;
  return &_self->_base;
}

static kk_box_t kk_handlers_replayx_fun4066(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_handlers_replayx_fun4066__t* _self = kk_function_as(struct kk_handlers_replayx_fun4066__t*, _fself);
  kk_function_t action = _self->action; /* () -> <effects-and-types/sample,effects-and-types/sample|2184> 2183 */
  kk_drop_match(_self, {kk_function_dup(action);}, {}, _ctx)
  return kk_std_core_hnd__mask_builtin(action, _ctx);
}

kk_std_core_types__tuple2_ kk_handlers_replayx(kk_std_core__list trace, kk_function_t action, kk_context_t* _ctx) { /* forall<a,e> (trace : effects-and-types/trace_values, action : () -> <effects-and-types/sample,effects-and-types/sample|e> a) -> <effects-and-types/sample|e> (list<double>, a) */ 
  kk_ref_t loc = kk_ref_alloc((kk_std_core__list_box(trace, _ctx)),kk_context()); /*local-var<global,list<double>>*/;
  kk_std_core_types__tuple2_ res1;
  kk_ref_t loc0 = kk_ref_alloc((kk_integer_box(kk_integer_from_small(-1))),kk_context()); /*local-var<global,int>*/;
  kk_std_core_types__tuple2_ res0;
  int32_t _b_3456_3451 = ((int32_t)1); /*int32*/;
  kk_effects_dash_and_dash_types__hnd_sample _b_3457_3452;
  kk_std_core_hnd__clause0 _x4044;
  kk_function_t _x4045;
  kk_ref_dup(loc);
  kk_ref_dup(loc0);
  _x4045 = kk_handlers_new_replayx_fun4046(loc, loc0, _ctx); /*(std/core/hnd/marker<39,40>, std/core/hnd/ev<38>) -> 39 37*/
  _x4044 = kk_std_core_hnd__new_Clause0(_x4045, _ctx); /*std/core/hnd/clause0<37,38,39,40>*/
  _b_3457_3452 = kk_effects_dash_and_dash_types__new_Hnd_sample(kk_reuse_null, _x4044, _ctx); /*effects-and-types/.hnd-sample<<local<global>,effects-and-types/sample|2184>,(list<double>, 2183)>*/
  kk_box_t _x4057;
  kk_function_t _x4058;
  kk_ref_dup(loc);
  kk_ref_dup(loc0);
  _x4058 = kk_handlers_new_replayx_fun4059(loc, loc0, _ctx); /*(223) -> 224 225*/
  _x4057 = kk_effects_dash_and_dash_types__handle_sample(_b_3456_3451, _b_3457_3452, _x4058, kk_handlers_new_replayx_fun4066(action, _ctx), _ctx); /*225*/
  res0 = kk_std_core_types__tuple2__unbox(_x4057, _ctx); /*(list<double>, 2183)*/
  kk_box_t _x4067 = kk_std_core_hnd_prompt_local_var(loc0, kk_std_core_types__tuple2__box(res0, _ctx), _ctx); /*9788*/
  res1 = kk_std_core_types__tuple2__unbox(_x4067, _ctx); /*(list<double>, 2183)*/
  kk_box_t _x4068 = kk_std_core_hnd_prompt_local_var(loc, kk_std_core_types__tuple2__box(res1, _ctx), _ctx); /*9788*/
  return kk_std_core_types__tuple2__unbox(_x4068, _ctx);
}
 
// monadic lift

kk_unit_t kk_handlers__mlift2537_weighted(kk_effects_dash_and_dash_types__exp s, kk_ref_t wps, kk_effects_dash_and_dash_types__exp _y_60, kk_context_t* _ctx) { /* forall<h,e> (s : effects-and-types/exp, wps : local-var<h,effects-and-types/exp>, effects-and-types/exp) -> <local<h>|e> () */ 
  kk_effects_dash_and_dash_types__exp _b_3484_3482 = kk_exponents_mult__exp(_y_60, s, _ctx); /*effects-and-types/exp*/;
  (kk_ref_set(wps,(kk_effects_dash_and_dash_types__exp_box(_b_3484_3482, _ctx)),kk_context())); return kk_Unit;
}
 
// monadic lift

kk_std_core_types__tuple2_ kk_handlers__mlift2538_weighted(kk_box_t x, kk_effects_dash_and_dash_types__exp _y_62, kk_context_t* _ctx) { /* forall<h,a,e> (x : a, effects-and-types/exp) -> <local<h>|e> (effects-and-types/exp, a) */ 
  return kk_std_core_types__new_dash__lp__comma__rp_(kk_effects_dash_and_dash_types__exp_box(_y_62, _ctx), x, _ctx);
}


// lift anonymous function
struct kk_handlers_weighted_fun4071__t {
  struct kk_function_s _base;
  kk_ref_t loc;
};
static kk_box_t kk_handlers_weighted_fun4071(kk_function_t _fself, kk_std_core_hnd__marker _b_3496, kk_std_core_hnd__ev _b_3497, kk_box_t _b_3498, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_weighted_fun4071(kk_ref_t loc, kk_context_t* _ctx) {
  struct kk_handlers_weighted_fun4071__t* _self = kk_function_alloc_as(struct kk_handlers_weighted_fun4071__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_weighted_fun4071, kk_context());
  _self->loc = loc;
  return &_self->_base;
}



// lift anonymous function
struct kk_handlers_weighted_fun4076__t {
  struct kk_function_s _base;
  kk_box_t _b_3498;
  kk_ref_t loc;
};
static kk_box_t kk_handlers_weighted_fun4076(kk_function_t _fself, kk_box_t _b_3494, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_weighted_fun4076(kk_box_t _b_3498, kk_ref_t loc, kk_context_t* _ctx) {
  struct kk_handlers_weighted_fun4076__t* _self = kk_function_alloc_as(struct kk_handlers_weighted_fun4076__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_weighted_fun4076, kk_context());
  _self->_b_3498 = _b_3498;
  _self->loc = loc;
  return &_self->_base;
}

static kk_box_t kk_handlers_weighted_fun4076(kk_function_t _fself, kk_box_t _b_3494, kk_context_t* _ctx) {
  struct kk_handlers_weighted_fun4076__t* _self = kk_function_as(struct kk_handlers_weighted_fun4076__t*, _fself);
  kk_box_t _b_3498 = _self->_b_3498; /* 52 */
  kk_ref_t loc = _self->loc; /* local-var<global,effects-and-types/exp> */
  kk_drop_match(_self, {kk_box_dup(_b_3498);kk_ref_dup(loc);}, {}, _ctx)
  kk_unit_t _x4077 = kk_Unit;
  kk_effects_dash_and_dash_types__exp _x4078 = kk_effects_dash_and_dash_types__exp_unbox(_b_3498, _ctx); /*effects-and-types/exp*/
  kk_effects_dash_and_dash_types__exp _x4079 = kk_effects_dash_and_dash_types__exp_unbox(_b_3494, _ctx); /*effects-and-types/exp*/
  kk_handlers__mlift2537_weighted(_x4078, loc, _x4079, _ctx);
  return kk_unit_box(_x4077);
}
static kk_box_t kk_handlers_weighted_fun4071(kk_function_t _fself, kk_std_core_hnd__marker _b_3496, kk_std_core_hnd__ev _b_3497, kk_box_t _b_3498, kk_context_t* _ctx) {
  struct kk_handlers_weighted_fun4071__t* _self = kk_function_as(struct kk_handlers_weighted_fun4071__t*, _fself);
  kk_ref_t loc = _self->loc; /* local-var<global,effects-and-types/exp> */
  kk_drop_match(_self, {kk_ref_dup(loc);}, {}, _ctx)
  kk_std_core_hnd__ev_dropn(_b_3497, ((int32_t)3), _ctx);
  kk_unit_t _x4072 = kk_Unit;
  kk_effects_dash_and_dash_types__exp x0_2665;
  kk_box_t _x4073;
  kk_ref_t _x4074 = kk_ref_dup(loc); /*local-var<global,effects-and-types/exp>*/
  _x4073 = (kk_ref_get(_x4074,kk_context())); /*228*/
  x0_2665 = kk_effects_dash_and_dash_types__exp_unbox(_x4073, _ctx); /*effects-and-types/exp*/
  if (kk_yielding(kk_context())) {
    kk_box_t _x4075 = kk_std_core_hnd_yield_extend(kk_handlers_new_weighted_fun4076(_b_3498, loc, _ctx), _ctx); /*3991*/
    kk_unit_unbox(_x4075);
  }
  else {
    kk_effects_dash_and_dash_types__exp _x4080 = kk_effects_dash_and_dash_types__exp_unbox(_b_3498, _ctx); /*effects-and-types/exp*/
    kk_handlers__mlift2537_weighted(_x4080, loc, x0_2665, _ctx);
  }
  return kk_unit_box(_x4072);
}


// lift anonymous function
struct kk_handlers_weighted_fun4083__t {
  struct kk_function_s _base;
  kk_ref_t loc;
};
static kk_box_t kk_handlers_weighted_fun4083(kk_function_t _fself, kk_box_t _b_3507, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_weighted_fun4083(kk_ref_t loc, kk_context_t* _ctx) {
  struct kk_handlers_weighted_fun4083__t* _self = kk_function_alloc_as(struct kk_handlers_weighted_fun4083__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_weighted_fun4083, kk_context());
  _self->loc = loc;
  return &_self->_base;
}



// lift anonymous function
struct kk_handlers_weighted_fun4087__t {
  struct kk_function_s _base;
  kk_box_t _b_3507;
};
static kk_box_t kk_handlers_weighted_fun4087(kk_function_t _fself, kk_box_t _b_3502, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_weighted_fun4087(kk_box_t _b_3507, kk_context_t* _ctx) {
  struct kk_handlers_weighted_fun4087__t* _self = kk_function_alloc_as(struct kk_handlers_weighted_fun4087__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_weighted_fun4087, kk_context());
  _self->_b_3507 = _b_3507;
  return &_self->_base;
}

static kk_box_t kk_handlers_weighted_fun4087(kk_function_t _fself, kk_box_t _b_3502, kk_context_t* _ctx) {
  struct kk_handlers_weighted_fun4087__t* _self = kk_function_as(struct kk_handlers_weighted_fun4087__t*, _fself);
  kk_box_t _b_3507 = _self->_b_3507; /* 252 */
  kk_drop_match(_self, {kk_box_dup(_b_3507);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x4088;
  kk_effects_dash_and_dash_types__exp _x4089 = kk_effects_dash_and_dash_types__exp_unbox(_b_3502, _ctx); /*effects-and-types/exp*/
  _x4088 = kk_handlers__mlift2538_weighted(_b_3507, _x4089, _ctx); /*(effects-and-types/exp, 2370)*/
  return kk_std_core_types__tuple2__box(_x4088, _ctx);
}
static kk_box_t kk_handlers_weighted_fun4083(kk_function_t _fself, kk_box_t _b_3507, kk_context_t* _ctx) {
  struct kk_handlers_weighted_fun4083__t* _self = kk_function_as(struct kk_handlers_weighted_fun4083__t*, _fself);
  kk_ref_t loc = _self->loc; /* local-var<global,effects-and-types/exp> */
  kk_drop_match(_self, {kk_ref_dup(loc);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x4084;
  kk_effects_dash_and_dash_types__exp x2_2667;
  kk_box_t _x4085 = (kk_ref_get(loc,kk_context())); /*228*/
  x2_2667 = kk_effects_dash_and_dash_types__exp_unbox(_x4085, _ctx); /*effects-and-types/exp*/
  if (kk_yielding(kk_context())) {
    kk_box_t _x4086 = kk_std_core_hnd_yield_extend(kk_handlers_new_weighted_fun4087(_b_3507, _ctx), _ctx); /*3991*/
    _x4084 = kk_std_core_types__tuple2__unbox(_x4086, _ctx); /*(effects-and-types/exp, 2370)*/
  }
  else {
    _x4084 = kk_handlers__mlift2538_weighted(_b_3507, x2_2667, _ctx); /*(effects-and-types/exp, 2370)*/
  }
  return kk_std_core_types__tuple2__box(_x4084, _ctx);
}


// lift anonymous function
struct kk_handlers_weighted_fun4090__t {
  struct kk_function_s _base;
  kk_function_t action;
};
static kk_box_t kk_handlers_weighted_fun4090(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_weighted_fun4090(kk_function_t action, kk_context_t* _ctx) {
  struct kk_handlers_weighted_fun4090__t* _self = kk_function_alloc_as(struct kk_handlers_weighted_fun4090__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_weighted_fun4090, kk_context());
  _self->action = action;
  return &_self->_base;
}

static kk_box_t kk_handlers_weighted_fun4090(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_handlers_weighted_fun4090__t* _self = kk_function_as(struct kk_handlers_weighted_fun4090__t*, _fself);
  kk_function_t action = _self->action; /* () -> <effects-and-types/score|2371> 2370 */
  kk_drop_match(_self, {kk_function_dup(action);}, {}, _ctx)
  return kk_std_core_hnd__mask_builtin(action, _ctx);
}

kk_std_core_types__tuple2_ kk_handlers_weighted(kk_effects_dash_and_dash_types__exp wp, kk_function_t action, kk_context_t* _ctx) { /* forall<a,e> (wp : effects-and-types/exp, action : () -> <effects-and-types/score|e> a) -> e (effects-and-types/exp, a) */ 
  kk_ref_t loc = kk_ref_alloc((kk_effects_dash_and_dash_types__exp_box(wp, _ctx)),kk_context()); /*local-var<global,effects-and-types/exp>*/;
  kk_std_core_types__tuple2_ res;
  int32_t _b_3508_3503 = ((int32_t)1); /*int32*/;
  kk_effects_dash_and_dash_types__hnd_score _b_3509_3504;
  kk_std_core_hnd__clause1 _x4069;
  kk_function_t _x4070;
  kk_ref_dup(loc);
  _x4070 = kk_handlers_new_weighted_fun4071(loc, _ctx); /*(std/core/hnd/marker<55,56>, std/core/hnd/ev<54>, 52) -> 55 53*/
  _x4069 = kk_std_core_hnd__new_Clause1(_x4070, _ctx); /*std/core/hnd/clause1<52,53,54,55,56>*/
  _b_3509_3504 = kk_effects_dash_and_dash_types__new_Hnd_score(kk_reuse_null, _x4069, _ctx); /*effects-and-types/.hnd-score<<local<global>|2371>,(effects-and-types/exp, 2370)>*/
  kk_box_t _x4081;
  kk_function_t _x4082;
  kk_ref_dup(loc);
  _x4082 = kk_handlers_new_weighted_fun4083(loc, _ctx); /*(252) -> 253 254*/
  _x4081 = kk_effects_dash_and_dash_types__handle_score(_b_3508_3503, _b_3509_3504, _x4082, kk_handlers_new_weighted_fun4090(action, _ctx), _ctx); /*254*/
  res = kk_std_core_types__tuple2__unbox(_x4081, _ctx); /*(effects-and-types/exp, 2370)*/
  kk_box_t _x4091 = kk_std_core_hnd_prompt_local_var(loc, kk_std_core_types__tuple2__box(res, _ctx), _ctx); /*9788*/
  return kk_std_core_types__tuple2__unbox(_x4091, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_handlers__mlift2539_yield__on__scorex_fun4099__t {
  struct kk_function_s _base;
  size_t i_2669;
};
static kk_box_t kk_handlers__mlift2539_yield__on__scorex_fun4099(kk_function_t _fself, kk_function_t _b_3538, kk_box_t _b_3539, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2539_yield__on__scorex_fun4099(size_t i_2669, kk_context_t* _ctx) {
  struct kk_handlers__mlift2539_yield__on__scorex_fun4099__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2539_yield__on__scorex_fun4099__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2539_yield__on__scorex_fun4099, kk_context());
  _self->i_2669 = i_2669;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift2539_yield__on__scorex_fun4099(kk_function_t _fself, kk_function_t _b_3538, kk_box_t _b_3539, kk_context_t* _ctx) {
  struct kk_handlers__mlift2539_yield__on__scorex_fun4099__t* _self = kk_function_as(struct kk_handlers__mlift2539_yield__on__scorex_fun4099__t*, _fself);
  size_t i_2669 = _self->i_2669; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_2669, _b_3538, _b_3539, _ctx);
}

kk_unit_t kk_handlers__mlift2539_yield__on__scorex(kk_unit_t wild__, kk_context_t* _ctx) { /* forall<e> (wild_ : ()) -> <effects-and-types/score,effects-and-types/yield|e> () */ 
  size_t i_2669;
  kk_std_core_hnd__htag _x4092 = kk_std_core_hnd__htag_dup(kk_effects_dash_and_dash_types__tag_yield); /*std/core/hnd/htag<effects-and-types/.hnd-yield>*/
  i_2669 = kk_std_core_hnd__evv_index(_x4092, _ctx); /*std/core/hnd/ev-index*/
  kk_evv_t w = kk_evv_swap_create1(i_2669,kk_context()); /*std/core/hnd/evv<<effects-and-types/yield,effects-and-types/score|2436>>*/;
  kk_unit_t y = kk_Unit;
  kk_std_core_hnd__ev ev_409;
  size_t _x4093 = ((size_t)0); /*size_t*/
  ev_409 = kk_evv_at(_x4093,kk_context()); /*std/core/hnd/ev<effects-and-types/.hnd-yield>*/
  kk_box_t _x4094;
  struct kk_std_core_hnd_Ev* _con4095 = kk_std_core_hnd__as_Ev(ev_409);
  kk_std_core_hnd__marker m = _con4095->marker;
  kk_box_t _box_x3525 = _con4095->hnd;
  kk_effects_dash_and_dash_types__hnd_yield h = kk_effects_dash_and_dash_types__hnd_yield_unbox(_box_x3525, NULL);
  kk_effects_dash_and_dash_types__hnd_yield_dup(h);
  kk_std_core_hnd__clause0 _match_3679;
  struct kk_effects_dash_and_dash_types__Hnd_yield* _con4097 = kk_effects_dash_and_dash_types__as_Hnd_yield(h);
  kk_std_core_hnd__clause0 control_yield = _con4097->control_yield;
  if (kk_effects_dash_and_dash_types__hnd_yield_is_unique(h)) {
    kk_effects_dash_and_dash_types__hnd_yield_free(h);
  }
  else {
    kk_std_core_hnd__clause0_dup(control_yield);
    kk_effects_dash_and_dash_types__hnd_yield_decref(h, _ctx);
  }
  _match_3679 = control_yield; /*std/core/hnd/clause0<(),effects-and-types/.hnd-yield,3435,3436>*/
  kk_function_t _fun_unbox_x3528 = _match_3679.clause;
  _x4094 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__marker, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x3528, (_fun_unbox_x3528, m, ev_409, _ctx)); /*37*/
  kk_unit_unbox(_x4094);
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x4098 = kk_std_core_hnd_yield_cont(kk_handlers__new_mlift2539_yield__on__scorex_fun4099(i_2669, _ctx), _ctx); /*3820*/
    kk_unit_unbox(_x4098); return kk_Unit;
  }
  y; return kk_Unit;
}


// lift anonymous function
struct kk_handlers_yield__on__scorex_fun4102__t {
  struct kk_function_s _base;
};
static kk_box_t kk_handlers_yield__on__scorex_fun4102(kk_function_t _fself, kk_std_core_hnd__marker _b_3570, kk_std_core_hnd__ev _b_3571, kk_box_t _b_3572, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_yield__on__scorex_fun4102(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_handlers_yield__on__scorex_fun4102, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_handlers_yield__on__scorex_fun4103__t {
  struct kk_function_s _base;
};
static kk_box_t kk_handlers_yield__on__scorex_fun4103(kk_function_t _fself, kk_box_t _b_3568, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_yield__on__scorex_fun4103(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_handlers_yield__on__scorex_fun4103, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_handlers_yield__on__scorex_fun4108__t {
  struct kk_function_s _base;
  size_t i_2674;
};
static kk_box_t kk_handlers_yield__on__scorex_fun4108(kk_function_t _fself, kk_function_t _b_3553, kk_box_t _b_3554, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_yield__on__scorex_fun4108(size_t i_2674, kk_context_t* _ctx) {
  struct kk_handlers_yield__on__scorex_fun4108__t* _self = kk_function_alloc_as(struct kk_handlers_yield__on__scorex_fun4108__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_yield__on__scorex_fun4108, kk_context());
  _self->i_2674 = i_2674;
  return &_self->_base;
}

static kk_box_t kk_handlers_yield__on__scorex_fun4108(kk_function_t _fself, kk_function_t _b_3553, kk_box_t _b_3554, kk_context_t* _ctx) {
  struct kk_handlers_yield__on__scorex_fun4108__t* _self = kk_function_as(struct kk_handlers_yield__on__scorex_fun4108__t*, _fself);
  size_t i_2674 = _self->i_2674; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_2674, _b_3553, _b_3554, _ctx);
}


// lift anonymous function
struct kk_handlers_yield__on__scorex_fun4110__t {
  struct kk_function_s _base;
};
static kk_box_t kk_handlers_yield__on__scorex_fun4110(kk_function_t _fself, kk_box_t _b_3564, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_yield__on__scorex_fun4110(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_handlers_yield__on__scorex_fun4110, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_handlers_yield__on__scorex_fun4110(kk_function_t _fself, kk_box_t _b_3564, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_unit_t _x4111 = kk_Unit;
  kk_unit_t _x4112 = kk_Unit;
  kk_unit_unbox(_b_3564);
  kk_handlers__mlift2539_yield__on__scorex(_x4112, _ctx);
  return kk_unit_box(_x4111);
}
static kk_box_t kk_handlers_yield__on__scorex_fun4103(kk_function_t _fself, kk_box_t _b_3568, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_unit_t _x4104 = kk_Unit;
  kk_unit_t x0_2672 = kk_Unit;
  size_t i_2674;
  kk_std_core_hnd__htag _x4105 = kk_std_core_hnd__htag_dup(kk_effects_dash_and_dash_types__tag_score); /*std/core/hnd/htag<effects-and-types/.hnd-score>*/
  i_2674 = kk_std_core_hnd__evv_index(_x4105, _ctx); /*std/core/hnd/ev-index*/
  kk_evv_t w0 = kk_evv_swap_create1(i_2674,kk_context()); /*std/core/hnd/evv<<effects-and-types/score,effects-and-types/yield|2436>>*/;
  kk_unit_t y = kk_Unit;
  kk_effects_dash_and_dash_types__exp _x4106 = kk_effects_dash_and_dash_types__exp_unbox(_b_3568, _ctx); /*effects-and-types/exp*/
  kk_effects_dash_and_dash_types_score(_x4106, _ctx);
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w0,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x4107 = kk_std_core_hnd_yield_cont(kk_handlers_new_yield__on__scorex_fun4108(i_2674, _ctx), _ctx); /*3820*/
    kk_unit_unbox(_x4107);
  }
  else {
    y;
  }
  if (kk_yielding(kk_context())) {
    kk_box_t _x4109 = kk_std_core_hnd_yield_extend(kk_handlers_new_yield__on__scorex_fun4110(_ctx), _ctx); /*3991*/
    kk_unit_unbox(_x4109);
  }
  else {
    kk_handlers__mlift2539_yield__on__scorex(x0_2672, _ctx);
  }
  return kk_unit_box(_x4104);
}
static kk_box_t kk_handlers_yield__on__scorex_fun4102(kk_function_t _fself, kk_std_core_hnd__marker _b_3570, kk_std_core_hnd__ev _b_3571, kk_box_t _b_3572, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return kk_std_core_hnd_under1(_b_3571, kk_handlers_new_yield__on__scorex_fun4103(_ctx), _b_3572, _ctx);
}


// lift anonymous function
struct kk_handlers_yield__on__scorex_fun4113__t {
  struct kk_function_s _base;
};
static kk_box_t kk_handlers_yield__on__scorex_fun4113(kk_function_t _fself, kk_box_t _x, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_yield__on__scorex_fun4113(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_handlers_yield__on__scorex_fun4113, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_handlers_yield__on__scorex_fun4113(kk_function_t _fself, kk_box_t _x, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return _x;
}

kk_box_t kk_handlers_yield__on__scorex(kk_function_t action, kk_context_t* _ctx) { /* forall<a,e> (action : () -> <effects-and-types/score,effects-and-types/score,effects-and-types/yield|e> a) -> <effects-and-types/score,effects-and-types/yield|e> a */ 
  kk_effects_dash_and_dash_types__hnd_score _x4100;
  kk_std_core_hnd__clause1 _x4101 = kk_std_core_hnd__new_Clause1(kk_handlers_new_yield__on__scorex_fun4102(_ctx), _ctx); /*std/core/hnd/clause1<52,53,54,55,56>*/
  _x4100 = kk_effects_dash_and_dash_types__new_Hnd_score(kk_reuse_null, _x4101, _ctx); /*effects-and-types/.hnd-score<17,18>*/
  return kk_effects_dash_and_dash_types__handle_score(((int32_t)1), _x4100, kk_handlers_new_yield__on__scorex_fun4113(_ctx), action, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_handlers__mlift2540_advance_alt1_fun4114__t {
  struct kk_function_s _base;
  size_t _y_70;
};
static kk_box_t kk_handlers__mlift2540_advance_alt1_fun4114(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2540_advance_alt1_fun4114(size_t _y_70, kk_context_t* _ctx) {
  struct kk_handlers__mlift2540_advance_alt1_fun4114__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2540_advance_alt1_fun4114__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2540_advance_alt1_fun4114, kk_context());
  _self->_y_70 = _y_70;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift2540_advance_alt1_fun4114(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_handlers__mlift2540_advance_alt1_fun4114__t* _self = kk_function_as(struct kk_handlers__mlift2540_advance_alt1_fun4114__t*, _fself);
  size_t _y_70 = _self->_y_70; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_mask_at1(_y_70, true, cont, res, _ctx);
}

kk_box_t kk_handlers__mlift2540_advance_alt1(kk_function_t action, size_t _y_70, kk_context_t* _ctx) { /* forall<a,e> (action : () -> <effects-and-types/yield|e> a, std/core/hnd/ev-index) -> <effects-and-types/yield,effects-and-types/yield|e> a */ 
  kk_evv_t w0 = kk_std_core_hnd_evv_swap_delete(_y_70, true, _ctx); /*std/core/hnd/evv<_4681>*/;
  kk_box_t x = kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), action, (action, _ctx)); /*2454*/;
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w0,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_drop(x, _ctx);
    return kk_std_core_hnd_yield_cont(kk_handlers__new_mlift2540_advance_alt1_fun4114(_y_70, _ctx), _ctx);
  }
  return x;
}


// lift anonymous function
struct kk_handlers_advance_alt1_fun4115__t {
  struct kk_function_s _base;
  kk_function_t action;
};
static kk_box_t kk_handlers_advance_alt1_fun4115(kk_function_t _fself, kk_integer_t init, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_advance_alt1_fun4115(kk_function_t action, kk_context_t* _ctx) {
  struct kk_handlers_advance_alt1_fun4115__t* _self = kk_function_alloc_as(struct kk_handlers_advance_alt1_fun4115__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_advance_alt1_fun4115, kk_context());
  _self->action = action;
  return &_self->_base;
}



// lift anonymous function
struct kk_handlers_advance_alt1_fun4119__t {
  struct kk_function_s _base;
  kk_ref_t loc;
};
static kk_box_t kk_handlers_advance_alt1_fun4119(kk_function_t _fself, kk_std_core_hnd__marker _b_3597, kk_std_core_hnd__ev _b_3598, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_advance_alt1_fun4119(kk_ref_t loc, kk_context_t* _ctx) {
  struct kk_handlers_advance_alt1_fun4119__t* _self = kk_function_alloc_as(struct kk_handlers_advance_alt1_fun4119__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_advance_alt1_fun4119, kk_context());
  _self->loc = loc;
  return &_self->_base;
}



// lift anonymous function
struct kk_handlers_advance_alt1_fun4120__t {
  struct kk_function_s _base;
  kk_ref_t loc;
};
static kk_box_t kk_handlers_advance_alt1_fun4120(kk_function_t _fself, kk_function_t _b_3594, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_advance_alt1_fun4120(kk_ref_t loc, kk_context_t* _ctx) {
  struct kk_handlers_advance_alt1_fun4120__t* _self = kk_function_alloc_as(struct kk_handlers_advance_alt1_fun4120__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_advance_alt1_fun4120, kk_context());
  _self->loc = loc;
  return &_self->_base;
}



// lift anonymous function
struct kk_handlers_advance_alt1_fun4123__t {
  struct kk_function_s _base;
  kk_ref_t loc;
  kk_std_core_hnd__resume_context rcontext_2584;
};
static kk_box_t kk_handlers_advance_alt1_fun4123(kk_function_t _fself, kk_box_t _b_3591, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_advance_alt1_fun4123(kk_ref_t loc, kk_std_core_hnd__resume_context rcontext_2584, kk_context_t* _ctx) {
  struct kk_handlers_advance_alt1_fun4123__t* _self = kk_function_alloc_as(struct kk_handlers_advance_alt1_fun4123__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_advance_alt1_fun4123, kk_context());
  _self->loc = loc;
  _self->rcontext_2584 = rcontext_2584;
  return &_self->_base;
}

static kk_box_t kk_handlers_advance_alt1_fun4123(kk_function_t _fself, kk_box_t _b_3591, kk_context_t* _ctx) {
  struct kk_handlers_advance_alt1_fun4123__t* _self = kk_function_as(struct kk_handlers_advance_alt1_fun4123__t*, _fself);
  kk_ref_t loc = _self->loc; /* local-var<global,int> */
  kk_std_core_hnd__resume_context rcontext_2584 = _self->rcontext_2584; /* std/core/hnd/resume-context<(),<effects-and-types/yield,local<global>|2455>,2454> */
  kk_drop_match(_self, {kk_ref_dup(loc);kk_std_core_hnd__resume_context_dup(rcontext_2584);}, {}, _ctx)
  kk_integer_t _x4124 = kk_integer_unbox(_b_3591); /*int*/
  return kk_handlers__mlift2518_advance_fun(loc, rcontext_2584, _x4124, _ctx);
}
static kk_box_t kk_handlers_advance_alt1_fun4120(kk_function_t _fself, kk_function_t _b_3594, kk_context_t* _ctx) {
  struct kk_handlers_advance_alt1_fun4120__t* _self = kk_function_as(struct kk_handlers_advance_alt1_fun4120__t*, _fself);
  kk_ref_t loc = _self->loc; /* local-var<global,int> */
  kk_drop_match(_self, {kk_ref_dup(loc);}, {}, _ctx)
  kk_std_core_hnd__resume_context rcontext_2584 = kk_std_core_hnd__new_Resume_context(_b_3594, _ctx); /*std/core/hnd/resume-context<(),<effects-and-types/yield,local<global>|2455>,2454>*/;
  kk_integer_t x_2585;
  kk_box_t _x4121;
  kk_ref_t _x4122 = kk_ref_dup(loc); /*local-var<global,int>*/
  _x4121 = (kk_ref_get(_x4122,kk_context())); /*228*/
  x_2585 = kk_integer_unbox(_x4121); /*int*/
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_2585, _ctx);
    return kk_std_core_hnd_yield_extend(kk_handlers_new_advance_alt1_fun4123(loc, rcontext_2584, _ctx), _ctx);
  }
  return kk_handlers__mlift2518_advance_fun(loc, rcontext_2584, x_2585, _ctx);
}
static kk_box_t kk_handlers_advance_alt1_fun4119(kk_function_t _fself, kk_std_core_hnd__marker _b_3597, kk_std_core_hnd__ev _b_3598, kk_context_t* _ctx) {
  struct kk_handlers_advance_alt1_fun4119__t* _self = kk_function_as(struct kk_handlers_advance_alt1_fun4119__t*, _fself);
  kk_ref_t loc = _self->loc; /* local-var<global,int> */
  kk_drop_match(_self, {kk_ref_dup(loc);}, {}, _ctx)
  kk_std_core_hnd__ev_dropn(_b_3598, ((int32_t)3), _ctx);
  return kk_std_core_hnd_yield_to(_b_3597, kk_handlers_new_advance_alt1_fun4120(loc, _ctx), _ctx);
}


// lift anonymous function
struct kk_handlers_advance_alt1_fun4125__t {
  struct kk_function_s _base;
};
static kk_box_t kk_handlers_advance_alt1_fun4125(kk_function_t _fself, kk_box_t _x, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_advance_alt1_fun4125(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_handlers_advance_alt1_fun4125, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_handlers_advance_alt1_fun4125(kk_function_t _fself, kk_box_t _x, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return _x;
}


// lift anonymous function
struct kk_handlers_advance_alt1_fun4126__t {
  struct kk_function_s _base;
  kk_function_t action;
};
static kk_box_t kk_handlers_advance_alt1_fun4126(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_advance_alt1_fun4126(kk_function_t action, kk_context_t* _ctx) {
  struct kk_handlers_advance_alt1_fun4126__t* _self = kk_function_alloc_as(struct kk_handlers_advance_alt1_fun4126__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_advance_alt1_fun4126, kk_context());
  _self->action = action;
  return &_self->_base;
}



// lift anonymous function
struct kk_handlers_advance_alt1_fun4127__t {
  struct kk_function_s _base;
  kk_function_t action;
};
static kk_box_t kk_handlers_advance_alt1_fun4127(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_advance_alt1_fun4127(kk_function_t action, kk_context_t* _ctx) {
  struct kk_handlers_advance_alt1_fun4127__t* _self = kk_function_alloc_as(struct kk_handlers_advance_alt1_fun4127__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_advance_alt1_fun4127, kk_context());
  _self->action = action;
  return &_self->_base;
}



// lift anonymous function
struct kk_handlers_advance_alt1_fun4129__t {
  struct kk_function_s _base;
  kk_function_t action;
};
static kk_box_t kk_handlers_advance_alt1_fun4129(kk_function_t _fself, kk_box_t _b_3600, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_advance_alt1_fun4129(kk_function_t action, kk_context_t* _ctx) {
  struct kk_handlers_advance_alt1_fun4129__t* _self = kk_function_alloc_as(struct kk_handlers_advance_alt1_fun4129__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_advance_alt1_fun4129, kk_context());
  _self->action = action;
  return &_self->_base;
}

static kk_box_t kk_handlers_advance_alt1_fun4129(kk_function_t _fself, kk_box_t _b_3600, kk_context_t* _ctx) {
  struct kk_handlers_advance_alt1_fun4129__t* _self = kk_function_as(struct kk_handlers_advance_alt1_fun4129__t*, _fself);
  kk_function_t action = _self->action; /* () -> <effects-and-types/yield|2455> 2454 */
  kk_drop_match(_self, {kk_function_dup(action);}, {}, _ctx)
  size_t _x4130 = kk_size_unbox(_b_3600, _ctx); /*std/core/hnd/ev-index*/
  return kk_handlers__mlift2540_advance_alt1(action, _x4130, _ctx);
}
static kk_box_t kk_handlers_advance_alt1_fun4127(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_handlers_advance_alt1_fun4127__t* _self = kk_function_as(struct kk_handlers_advance_alt1_fun4127__t*, _fself);
  kk_function_t action = _self->action; /* () -> <effects-and-types/yield|2455> 2454 */
  kk_drop_match(_self, {kk_function_dup(action);}, {}, _ctx)
  size_t x_2680;
  kk_std_core_hnd__htag _x4128 = kk_std_core_hnd__htag_dup(kk_effects_dash_and_dash_types__tag_yield); /*std/core/hnd/htag<effects-and-types/.hnd-yield>*/
  x_2680 = kk_std_core_hnd__evv_index(_x4128, _ctx); /*std/core/hnd/ev-index*/
  if (kk_yielding(kk_context())) {
    return kk_std_core_hnd_yield_extend(kk_handlers_new_advance_alt1_fun4129(action, _ctx), _ctx);
  }
  return kk_handlers__mlift2540_advance_alt1(action, x_2680, _ctx);
}
static kk_box_t kk_handlers_advance_alt1_fun4126(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_handlers_advance_alt1_fun4126__t* _self = kk_function_as(struct kk_handlers_advance_alt1_fun4126__t*, _fself);
  kk_function_t action = _self->action; /* () -> <effects-and-types/yield|2455> 2454 */
  kk_drop_match(_self, {kk_function_dup(action);}, {}, _ctx)
  return kk_std_core_hnd__mask_builtin(kk_handlers_new_advance_alt1_fun4127(action, _ctx), _ctx);
}
static kk_box_t kk_handlers_advance_alt1_fun4115(kk_function_t _fself, kk_integer_t init, kk_context_t* _ctx) {
  struct kk_handlers_advance_alt1_fun4115__t* _self = kk_function_as(struct kk_handlers_advance_alt1_fun4115__t*, _fself);
  kk_function_t action = _self->action; /* () -> <effects-and-types/yield|2455> 2454 */
  kk_drop_match(_self, {kk_function_dup(action);}, {}, _ctx)
  kk_ref_t loc = kk_ref_alloc((kk_integer_box(init)),kk_context()); /*local-var<global,int>*/;
  kk_box_t res;
  kk_effects_dash_and_dash_types__hnd_yield _x4116;
  kk_std_core_hnd__clause0 _x4117;
  kk_function_t _x4118;
  kk_ref_dup(loc);
  _x4118 = kk_handlers_new_advance_alt1_fun4119(loc, _ctx); /*(std/core/hnd/marker<39,40>, std/core/hnd/ev<38>) -> 39 6146*/
  _x4117 = kk_std_core_hnd__new_Clause0(_x4118, _ctx); /*std/core/hnd/clause0<37,38,39,40>*/
  _x4116 = kk_effects_dash_and_dash_types__new_Hnd_yield(kk_reuse_null, _x4117, _ctx); /*effects-and-types/.hnd-yield<25,26>*/
  res = kk_effects_dash_and_dash_types__handle_yield(((int32_t)3), _x4116, kk_handlers_new_advance_alt1_fun4125(_ctx), kk_handlers_new_advance_alt1_fun4126(action, _ctx), _ctx); /*2454*/
  return kk_std_core_hnd_prompt_local_var(loc, res, _ctx);
}

kk_function_t kk_handlers_advance_alt1(kk_function_t action, kk_context_t* _ctx) { /* forall<a,e> (action : () -> <effects-and-types/yield|e> a) -> e ((a : int) -> <effects-and-types/yield|e> a) */ 
  return kk_handlers_new_advance_alt1_fun4115(action, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_handlers__mlift2541_replay_fun4131__t {
  struct kk_function_s _base;
  size_t _y_73;
};
static kk_box_t kk_handlers__mlift2541_replay_fun4131(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2541_replay_fun4131(size_t _y_73, kk_context_t* _ctx) {
  struct kk_handlers__mlift2541_replay_fun4131__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2541_replay_fun4131__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2541_replay_fun4131, kk_context());
  _self->_y_73 = _y_73;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift2541_replay_fun4131(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_handlers__mlift2541_replay_fun4131__t* _self = kk_function_as(struct kk_handlers__mlift2541_replay_fun4131__t*, _fself);
  size_t _y_73 = _self->_y_73; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_mask_at1(_y_73, true, cont, res, _ctx);
}

kk_box_t kk_handlers__mlift2541_replay(kk_function_t action, size_t _y_73, kk_context_t* _ctx) { /* forall<a,e> (action : () -> <effects-and-types/sample|e> a, std/core/hnd/ev-index) -> <effects-and-types/sample,effects-and-types/sample|e> a */ 
  kk_evv_t w0 = kk_std_core_hnd_evv_swap_delete(_y_73, true, _ctx); /*std/core/hnd/evv<_4681>*/;
  kk_box_t x = kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), action, (action, _ctx)); /*2472*/;
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w0,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_drop(x, _ctx);
    return kk_std_core_hnd_yield_cont(kk_handlers__new_mlift2541_replay_fun4131(_y_73, _ctx), _ctx);
  }
  return x;
}


// lift anonymous function
struct kk_handlers_replay_fun4132__t {
  struct kk_function_s _base;
  kk_function_t action;
};
static kk_box_t kk_handlers_replay_fun4132(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_replay_fun4132(kk_function_t action, kk_context_t* _ctx) {
  struct kk_handlers_replay_fun4132__t* _self = kk_function_alloc_as(struct kk_handlers_replay_fun4132__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_replay_fun4132, kk_context());
  _self->action = action;
  return &_self->_base;
}



// lift anonymous function
struct kk_handlers_replay_fun4134__t {
  struct kk_function_s _base;
  kk_function_t action;
};
static kk_box_t kk_handlers_replay_fun4134(kk_function_t _fself, kk_box_t _b_3613, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_replay_fun4134(kk_function_t action, kk_context_t* _ctx) {
  struct kk_handlers_replay_fun4134__t* _self = kk_function_alloc_as(struct kk_handlers_replay_fun4134__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_replay_fun4134, kk_context());
  _self->action = action;
  return &_self->_base;
}

static kk_box_t kk_handlers_replay_fun4134(kk_function_t _fself, kk_box_t _b_3613, kk_context_t* _ctx) {
  struct kk_handlers_replay_fun4134__t* _self = kk_function_as(struct kk_handlers_replay_fun4134__t*, _fself);
  kk_function_t action = _self->action; /* () -> <effects-and-types/sample|2473> 2472 */
  kk_drop_match(_self, {kk_function_dup(action);}, {}, _ctx)
  size_t _x4135 = kk_size_unbox(_b_3613, _ctx); /*std/core/hnd/ev-index*/
  return kk_handlers__mlift2541_replay(action, _x4135, _ctx);
}
static kk_box_t kk_handlers_replay_fun4132(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_handlers_replay_fun4132__t* _self = kk_function_as(struct kk_handlers_replay_fun4132__t*, _fself);
  kk_function_t action = _self->action; /* () -> <effects-and-types/sample|2473> 2472 */
  kk_drop_match(_self, {kk_function_dup(action);}, {}, _ctx)
  size_t x_2685;
  kk_std_core_hnd__htag _x4133 = kk_std_core_hnd__htag_dup(kk_effects_dash_and_dash_types__tag_sample); /*std/core/hnd/htag<effects-and-types/.hnd-sample>*/
  x_2685 = kk_std_core_hnd__evv_index(_x4133, _ctx); /*std/core/hnd/ev-index*/
  if (kk_yielding(kk_context())) {
    return kk_std_core_hnd_yield_extend(kk_handlers_new_replay_fun4134(action, _ctx), _ctx);
  }
  return kk_handlers__mlift2541_replay(action, x_2685, _ctx);
}

kk_std_core_types__tuple2_ kk_handlers_replay(kk_std_core__list trace, kk_function_t action, kk_context_t* _ctx) { /* forall<a,e> (trace : effects-and-types/trace_values, action : () -> <effects-and-types/sample|e> a) -> <effects-and-types/sample|e> (list<double>, a) */ 
  return kk_handlers_replayx(trace, kk_handlers_new_replay_fun4132(action, _ctx), _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_handlers__mlift2542_yield__on__score_fun4136__t {
  struct kk_function_s _base;
  size_t _y_76;
};
static kk_box_t kk_handlers__mlift2542_yield__on__score_fun4136(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx);
static kk_function_t kk_handlers__new_mlift2542_yield__on__score_fun4136(size_t _y_76, kk_context_t* _ctx) {
  struct kk_handlers__mlift2542_yield__on__score_fun4136__t* _self = kk_function_alloc_as(struct kk_handlers__mlift2542_yield__on__score_fun4136__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers__mlift2542_yield__on__score_fun4136, kk_context());
  _self->_y_76 = _y_76;
  return &_self->_base;
}

static kk_box_t kk_handlers__mlift2542_yield__on__score_fun4136(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_handlers__mlift2542_yield__on__score_fun4136__t* _self = kk_function_as(struct kk_handlers__mlift2542_yield__on__score_fun4136__t*, _fself);
  size_t _y_76 = _self->_y_76; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_mask_at1(_y_76, true, cont, res, _ctx);
}

kk_box_t kk_handlers__mlift2542_yield__on__score(kk_function_t action, size_t _y_76, kk_context_t* _ctx) { /* forall<a,e> (action : () -> <effects-and-types/score,effects-and-types/yield|e> a, std/core/hnd/ev-index) -> <effects-and-types/score,effects-and-types/score,effects-and-types/yield|e> a */ 
  kk_evv_t w0 = kk_std_core_hnd_evv_swap_delete(_y_76, true, _ctx); /*std/core/hnd/evv<_4681>*/;
  kk_box_t x = kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), action, (action, _ctx)); /*2491*/;
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w0,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_drop(x, _ctx);
    return kk_std_core_hnd_yield_cont(kk_handlers__new_mlift2542_yield__on__score_fun4136(_y_76, _ctx), _ctx);
  }
  return x;
}


// lift anonymous function
struct kk_handlers_yield__on__score_fun4139__t {
  struct kk_function_s _base;
};
static kk_box_t kk_handlers_yield__on__score_fun4139(kk_function_t _fself, kk_std_core_hnd__marker _b_3638, kk_std_core_hnd__ev _b_3639, kk_box_t _b_3640, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_yield__on__score_fun4139(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_handlers_yield__on__score_fun4139, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_handlers_yield__on__score_fun4140__t {
  struct kk_function_s _base;
};
static kk_box_t kk_handlers_yield__on__score_fun4140(kk_function_t _fself, kk_box_t _b_3636, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_yield__on__score_fun4140(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_handlers_yield__on__score_fun4140, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_handlers_yield__on__score_fun4145__t {
  struct kk_function_s _base;
  size_t i_2674;
};
static kk_box_t kk_handlers_yield__on__score_fun4145(kk_function_t _fself, kk_function_t _b_3621, kk_box_t _b_3622, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_yield__on__score_fun4145(size_t i_2674, kk_context_t* _ctx) {
  struct kk_handlers_yield__on__score_fun4145__t* _self = kk_function_alloc_as(struct kk_handlers_yield__on__score_fun4145__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_yield__on__score_fun4145, kk_context());
  _self->i_2674 = i_2674;
  return &_self->_base;
}

static kk_box_t kk_handlers_yield__on__score_fun4145(kk_function_t _fself, kk_function_t _b_3621, kk_box_t _b_3622, kk_context_t* _ctx) {
  struct kk_handlers_yield__on__score_fun4145__t* _self = kk_function_as(struct kk_handlers_yield__on__score_fun4145__t*, _fself);
  size_t i_2674 = _self->i_2674; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_2674, _b_3621, _b_3622, _ctx);
}


// lift anonymous function
struct kk_handlers_yield__on__score_fun4147__t {
  struct kk_function_s _base;
};
static kk_box_t kk_handlers_yield__on__score_fun4147(kk_function_t _fself, kk_box_t _b_3632, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_yield__on__score_fun4147(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_handlers_yield__on__score_fun4147, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_handlers_yield__on__score_fun4147(kk_function_t _fself, kk_box_t _b_3632, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_unit_t _x4148 = kk_Unit;
  kk_unit_t _x4149 = kk_Unit;
  kk_unit_unbox(_b_3632);
  kk_handlers__mlift2539_yield__on__scorex(_x4149, _ctx);
  return kk_unit_box(_x4148);
}
static kk_box_t kk_handlers_yield__on__score_fun4140(kk_function_t _fself, kk_box_t _b_3636, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_unit_t _x4141 = kk_Unit;
  kk_unit_t x0_2672 = kk_Unit;
  size_t i_2674;
  kk_std_core_hnd__htag _x4142 = kk_std_core_hnd__htag_dup(kk_effects_dash_and_dash_types__tag_score); /*std/core/hnd/htag<effects-and-types/.hnd-score>*/
  i_2674 = kk_std_core_hnd__evv_index(_x4142, _ctx); /*std/core/hnd/ev-index*/
  kk_evv_t w0 = kk_evv_swap_create1(i_2674,kk_context()); /*std/core/hnd/evv<<effects-and-types/score,effects-and-types/yield|2492>>*/;
  kk_unit_t y = kk_Unit;
  kk_effects_dash_and_dash_types__exp _x4143 = kk_effects_dash_and_dash_types__exp_unbox(_b_3636, _ctx); /*effects-and-types/exp*/
  kk_effects_dash_and_dash_types_score(_x4143, _ctx);
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w0,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x4144 = kk_std_core_hnd_yield_cont(kk_handlers_new_yield__on__score_fun4145(i_2674, _ctx), _ctx); /*3820*/
    kk_unit_unbox(_x4144);
  }
  else {
    y;
  }
  if (kk_yielding(kk_context())) {
    kk_box_t _x4146 = kk_std_core_hnd_yield_extend(kk_handlers_new_yield__on__score_fun4147(_ctx), _ctx); /*3991*/
    kk_unit_unbox(_x4146);
  }
  else {
    kk_handlers__mlift2539_yield__on__scorex(x0_2672, _ctx);
  }
  return kk_unit_box(_x4141);
}
static kk_box_t kk_handlers_yield__on__score_fun4139(kk_function_t _fself, kk_std_core_hnd__marker _b_3638, kk_std_core_hnd__ev _b_3639, kk_box_t _b_3640, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return kk_std_core_hnd_under1(_b_3639, kk_handlers_new_yield__on__score_fun4140(_ctx), _b_3640, _ctx);
}


// lift anonymous function
struct kk_handlers_yield__on__score_fun4150__t {
  struct kk_function_s _base;
};
static kk_box_t kk_handlers_yield__on__score_fun4150(kk_function_t _fself, kk_box_t _x, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_yield__on__score_fun4150(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_handlers_yield__on__score_fun4150, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_handlers_yield__on__score_fun4150(kk_function_t _fself, kk_box_t _x, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return _x;
}


// lift anonymous function
struct kk_handlers_yield__on__score_fun4151__t {
  struct kk_function_s _base;
  kk_function_t action;
};
static kk_box_t kk_handlers_yield__on__score_fun4151(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_yield__on__score_fun4151(kk_function_t action, kk_context_t* _ctx) {
  struct kk_handlers_yield__on__score_fun4151__t* _self = kk_function_alloc_as(struct kk_handlers_yield__on__score_fun4151__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_yield__on__score_fun4151, kk_context());
  _self->action = action;
  return &_self->_base;
}



// lift anonymous function
struct kk_handlers_yield__on__score_fun4153__t {
  struct kk_function_s _base;
  kk_function_t action;
};
static kk_box_t kk_handlers_yield__on__score_fun4153(kk_function_t _fself, kk_box_t _b_3642, kk_context_t* _ctx);
static kk_function_t kk_handlers_new_yield__on__score_fun4153(kk_function_t action, kk_context_t* _ctx) {
  struct kk_handlers_yield__on__score_fun4153__t* _self = kk_function_alloc_as(struct kk_handlers_yield__on__score_fun4153__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_handlers_yield__on__score_fun4153, kk_context());
  _self->action = action;
  return &_self->_base;
}

static kk_box_t kk_handlers_yield__on__score_fun4153(kk_function_t _fself, kk_box_t _b_3642, kk_context_t* _ctx) {
  struct kk_handlers_yield__on__score_fun4153__t* _self = kk_function_as(struct kk_handlers_yield__on__score_fun4153__t*, _fself);
  kk_function_t action = _self->action; /* () -> <effects-and-types/score,effects-and-types/yield|2492> 2491 */
  kk_drop_match(_self, {kk_function_dup(action);}, {}, _ctx)
  size_t _x4154 = kk_size_unbox(_b_3642, _ctx); /*std/core/hnd/ev-index*/
  return kk_handlers__mlift2542_yield__on__score(action, _x4154, _ctx);
}
static kk_box_t kk_handlers_yield__on__score_fun4151(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_handlers_yield__on__score_fun4151__t* _self = kk_function_as(struct kk_handlers_yield__on__score_fun4151__t*, _fself);
  kk_function_t action = _self->action; /* () -> <effects-and-types/score,effects-and-types/yield|2492> 2491 */
  kk_drop_match(_self, {kk_function_dup(action);}, {}, _ctx)
  size_t x_2690;
  kk_std_core_hnd__htag _x4152 = kk_std_core_hnd__htag_dup(kk_effects_dash_and_dash_types__tag_score); /*std/core/hnd/htag<effects-and-types/.hnd-score>*/
  x_2690 = kk_std_core_hnd__evv_index(_x4152, _ctx); /*std/core/hnd/ev-index*/
  if (kk_yielding(kk_context())) {
    return kk_std_core_hnd_yield_extend(kk_handlers_new_yield__on__score_fun4153(action, _ctx), _ctx);
  }
  return kk_handlers__mlift2542_yield__on__score(action, x_2690, _ctx);
}

kk_box_t kk_handlers_yield__on__score(kk_function_t action, kk_context_t* _ctx) { /* forall<a,e> (action : () -> <effects-and-types/score,effects-and-types/yield|e> a) -> <effects-and-types/score,effects-and-types/yield|e> a */ 
  kk_effects_dash_and_dash_types__hnd_score _x4137;
  kk_std_core_hnd__clause1 _x4138 = kk_std_core_hnd__new_Clause1(kk_handlers_new_yield__on__score_fun4139(_ctx), _ctx); /*std/core/hnd/clause1<52,53,54,55,56>*/
  _x4137 = kk_effects_dash_and_dash_types__new_Hnd_score(kk_reuse_null, _x4138, _ctx); /*effects-and-types/.hnd-score<17,18>*/
  return kk_effects_dash_and_dash_types__handle_score(((int32_t)1), _x4137, kk_handlers_new_yield__on__score_fun4150(_ctx), kk_handlers_new_yield__on__score_fun4151(action, _ctx), _ctx);
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
