// Koka generated module: "trace", koka version: 2.1.3
#include "trace.h"
 
// monadic lift

kk_trace__trace kk_trace__mlift1391_op(kk_function_t _c_1, kk_effects_dash_and_dash_types__exp _c_2, kk_std_core__list _c_3, kk_box_t _c_4, kk_context_t* _ctx) { /* forall<a,e> (() -> e a, effects-and-types/exp, effects-and-types/trace_values, a) -> trace<a,e> */ 
  return kk_trace__new_Trace(kk_reuse_null, _c_1, _c_2, _c_3, _c_4, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_trace__mlift1392_op_fun1843__t {
  struct kk_function_s _base;
  kk_function_t _c_1;
  kk_std_core__list _c_3;
  kk_effects_dash_and_dash_types__exp _c_2;
};
static kk_box_t kk_trace__mlift1392_op_fun1843(kk_function_t _fself, kk_box_t _b_1533, kk_context_t* _ctx);
static kk_function_t kk_trace__new_mlift1392_op_fun1843(kk_function_t _c_1, kk_std_core__list _c_3, kk_effects_dash_and_dash_types__exp _c_2, kk_context_t* _ctx) {
  struct kk_trace__mlift1392_op_fun1843__t* _self = kk_function_alloc_as(struct kk_trace__mlift1392_op_fun1843__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_trace__mlift1392_op_fun1843, kk_context());
  _self->_c_1 = _c_1;
  _self->_c_3 = _c_3;
  _self->_c_2 = _c_2;
  return &_self->_base;
}

static kk_box_t kk_trace__mlift1392_op_fun1843(kk_function_t _fself, kk_box_t _b_1533, kk_context_t* _ctx) {
  struct kk_trace__mlift1392_op_fun1843__t* _self = kk_function_as(struct kk_trace__mlift1392_op_fun1843__t*, _fself);
  kk_function_t _c_1 = _self->_c_1; /* () -> 240 239 */
  kk_std_core__list _c_3 = _self->_c_3; /* effects-and-types/trace_values */
  kk_effects_dash_and_dash_types__exp _c_2 = _self->_c_2; /* effects-and-types/exp */
  kk_drop_match(_self, {kk_function_dup(_c_1);kk_std_core__list_dup(_c_3);kk_effects_dash_and_dash_types__exp_dup(_c_2);}, {}, _ctx)
  kk_trace__trace _x1844 = kk_trace__mlift1391_op(_c_1, _c_2, _c_3, _b_1533, _ctx); /*trace/trace<239,240>*/
  return kk_trace__trace_box(_x1844, _ctx);
}

kk_trace__trace kk_trace__mlift1392_op(kk_function_t _c_1, kk_effects_dash_and_dash_types__exp _c_2, kk_trace__trace _this, kk_std_core_types__optional a0, kk_std_core__list _c_3, kk_context_t* _ctx) { /* forall<a,e> (() -> e a, effects-and-types/exp, trace<a,e>, a : optional<a>, effects-and-types/trace_values) -> trace<a,e> */ 
  if (kk_yielding(kk_context())) {
    kk_trace__trace_dropn(_this, ((int32_t)3), _ctx);
    kk_std_core_types__optional_drop(a0, _ctx);
    kk_box_t _x1842 = kk_std_core_hnd_yield_extend(kk_trace__new_mlift1392_op_fun1843(_c_1, _c_3, _c_2, _ctx), _ctx); /*2*/
    return kk_trace__trace_unbox(_x1842, _ctx);
  }
  kk_box_t _x1845;
  if (kk_std_core_types__is_Optional(a0)) {
    kk_box_t _a_224 = a0._cons.Optional.value;
    kk_trace__trace_dropn(_this, ((int32_t)3), _ctx);
    _x1845 = _a_224; /*239*/
  }
  else {
    struct kk_trace_Trace* _con1846 = kk_trace__as_Trace(_this);
    kk_function_t _pat00 = _con1846->m;
    kk_effects_dash_and_dash_types__exp _pat10 = _con1846->p;
    kk_std_core__list _pat3 = _con1846->l;
    kk_box_t _x = _con1846->a;
    if (kk_trace__trace_is_unique(_this)) {
      kk_std_core__list_drop(_pat3, _ctx);
      kk_function_drop(_pat00, _ctx);
      kk_trace__trace_free(_this);
    }
    else {
      kk_box_dup(_x);
      kk_trace__trace_decref(_this, _ctx);
    }
    _x1845 = _x; /*239*/
  }
  return kk_trace__mlift1391_op(_c_1, _c_2, _c_3, _x1845, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_trace__mlift1393_op_fun1848__t {
  struct kk_function_s _base;
  kk_function_t _c_1;
  kk_trace__trace _this;
  kk_std_core_types__optional a0;
  kk_effects_dash_and_dash_types__exp _c_2;
};
static kk_box_t kk_trace__mlift1393_op_fun1848(kk_function_t _fself, kk_box_t _b_1537, kk_context_t* _ctx);
static kk_function_t kk_trace__new_mlift1393_op_fun1848(kk_function_t _c_1, kk_trace__trace _this, kk_std_core_types__optional a0, kk_effects_dash_and_dash_types__exp _c_2, kk_context_t* _ctx) {
  struct kk_trace__mlift1393_op_fun1848__t* _self = kk_function_alloc_as(struct kk_trace__mlift1393_op_fun1848__t, 5, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_trace__mlift1393_op_fun1848, kk_context());
  _self->_c_1 = _c_1;
  _self->_this = _this;
  _self->a0 = a0;
  _self->_c_2 = _c_2;
  return &_self->_base;
}

static kk_box_t kk_trace__mlift1393_op_fun1848(kk_function_t _fself, kk_box_t _b_1537, kk_context_t* _ctx) {
  struct kk_trace__mlift1393_op_fun1848__t* _self = kk_function_as(struct kk_trace__mlift1393_op_fun1848__t*, _fself);
  kk_function_t _c_1 = _self->_c_1; /* () -> 240 239 */
  kk_trace__trace _this = _self->_this; /* trace/trace<239,240> */
  kk_std_core_types__optional a0 = _self->a0; /* optional<239> */
  kk_effects_dash_and_dash_types__exp _c_2 = _self->_c_2; /* effects-and-types/exp */
  kk_drop_match(_self, {kk_function_dup(_c_1);kk_trace__trace_dup(_this);kk_std_core_types__optional_dup(a0);kk_effects_dash_and_dash_types__exp_dup(_c_2);}, {}, _ctx)
  kk_trace__trace _x1849;
  kk_std_core__list _x1850 = kk_std_core__list_unbox(_b_1537, _ctx); /*effects-and-types/trace_values*/
  _x1849 = kk_trace__mlift1392_op(_c_1, _c_2, _this, a0, _x1850, _ctx); /*trace/trace<239,240>*/
  return kk_trace__trace_box(_x1849, _ctx);
}

kk_trace__trace kk_trace__mlift1393_op(kk_function_t _c_1, kk_trace__trace _this, kk_std_core_types__optional a0, kk_std_core_types__optional l0, kk_effects_dash_and_dash_types__exp _c_2, kk_context_t* _ctx) { /* forall<a,e> (() -> e a, trace<a,e>, a : optional<a>, l : optional<effects-and-types/trace_values>, effects-and-types/exp) -> trace<a,e> */ 
  if (kk_yielding(kk_context())) {
    kk_std_core_types__optional_drop(l0, _ctx);
    kk_box_t _x1847 = kk_std_core_hnd_yield_extend(kk_trace__new_mlift1393_op_fun1848(_c_1, _this, a0, _c_2, _ctx), _ctx); /*2*/
    return kk_trace__trace_unbox(_x1847, _ctx);
  }
  kk_trace__trace _x1851 = kk_trace__trace_dup(_this); /*trace/trace<239,240>*/
  kk_std_core__list _x1852;
  if (kk_std_core_types__is_Optional(l0)) {
    kk_box_t _box_x1538 = l0._cons.Optional.value;
    kk_std_core__list _l_216 = kk_std_core__list_unbox(_box_x1538, NULL);
    kk_std_core__list_dup(_l_216);
    kk_std_core_types__optional_drop(l0, _ctx);
    kk_trace__trace_dropn(_this, ((int32_t)3), _ctx);
    _x1852 = _l_216; /*effects-and-types/trace_values*/
    goto _match1853;
  }
  struct kk_trace_Trace* _con1855 = kk_trace__as_Trace(_this);
  kk_function_t _pat00 = _con1855->m;
  kk_effects_dash_and_dash_types__exp _pat10 = _con1855->p;
  kk_std_core__list _x = _con1855->l;
  kk_box_t _pat30 = _con1855->a;
  if (kk_trace__trace_is_unique(_this)) {
    kk_box_drop(_pat30, _ctx);
    kk_function_drop(_pat00, _ctx);
    kk_trace__trace_free(_this);
  }
  else {
    kk_std_core__list_dup(_x);
    kk_trace__trace_decref(_this, _ctx);
  }
  _x1852 = _x; /*effects-and-types/trace_values*/
  _match1853: ;
  return kk_trace__mlift1392_op(_c_1, _c_2, _x1851, a0, _x1852, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_trace__mlift1394_op_fun1857__t {
  struct kk_function_s _base;
  kk_function_t _c_1;
  kk_trace__trace _this;
  kk_std_core_types__optional a0;
  kk_std_core_types__optional l0;
};
static kk_box_t kk_trace__mlift1394_op_fun1857(kk_function_t _fself, kk_box_t _b_1542, kk_context_t* _ctx);
static kk_function_t kk_trace__new_mlift1394_op_fun1857(kk_function_t _c_1, kk_trace__trace _this, kk_std_core_types__optional a0, kk_std_core_types__optional l0, kk_context_t* _ctx) {
  struct kk_trace__mlift1394_op_fun1857__t* _self = kk_function_alloc_as(struct kk_trace__mlift1394_op_fun1857__t, 7, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_trace__mlift1394_op_fun1857, kk_context());
  _self->_c_1 = _c_1;
  _self->_this = _this;
  _self->a0 = a0;
  _self->l0 = l0;
  return &_self->_base;
}

static kk_box_t kk_trace__mlift1394_op_fun1857(kk_function_t _fself, kk_box_t _b_1542, kk_context_t* _ctx) {
  struct kk_trace__mlift1394_op_fun1857__t* _self = kk_function_as(struct kk_trace__mlift1394_op_fun1857__t*, _fself);
  kk_function_t _c_1 = _self->_c_1; /* () -> 240 239 */
  kk_trace__trace _this = _self->_this; /* trace/trace<239,240> */
  kk_std_core_types__optional a0 = _self->a0; /* optional<239> */
  kk_std_core_types__optional l0 = _self->l0; /* optional<effects-and-types/trace_values> */
  kk_drop_match(_self, {kk_function_dup(_c_1);kk_trace__trace_dup(_this);kk_std_core_types__optional_dup(a0);kk_std_core_types__optional_dup(l0);}, {}, _ctx)
  kk_trace__trace _x1858;
  kk_effects_dash_and_dash_types__exp _x1859 = kk_effects_dash_and_dash_types__exp_unbox(_b_1542, _ctx); /*effects-and-types/exp*/
  _x1858 = kk_trace__mlift1393_op(_c_1, _this, a0, l0, _x1859, _ctx); /*trace/trace<239,240>*/
  return kk_trace__trace_box(_x1858, _ctx);
}

kk_trace__trace kk_trace__mlift1394_op(kk_trace__trace _this, kk_std_core_types__optional a0, kk_std_core_types__optional l0, kk_std_core_types__optional p0, kk_function_t _c_1, kk_context_t* _ctx) { /* forall<a,e> (trace<a,e>, a : optional<a>, l : optional<effects-and-types/trace_values>, p : optional<effects-and-types/exp>, () -> e a) -> trace<a,e> */ 
  if (kk_yielding(kk_context())) {
    kk_std_core_types__optional_drop(p0, _ctx);
    kk_box_t _x1856 = kk_std_core_hnd_yield_extend(kk_trace__new_mlift1394_op_fun1857(_c_1, _this, a0, l0, _ctx), _ctx); /*2*/
    return kk_trace__trace_unbox(_x1856, _ctx);
  }
  kk_trace__trace _x1860 = kk_trace__trace_dup(_this); /*trace/trace<239,240>*/
  kk_effects_dash_and_dash_types__exp _x1861;
  if (kk_std_core_types__is_Optional(p0)) {
    kk_box_t _box_x1543 = p0._cons.Optional.value;
    kk_effects_dash_and_dash_types__exp _p_208 = kk_effects_dash_and_dash_types__exp_unbox(_box_x1543, NULL);
    kk_std_core_types__optional_drop(p0, _ctx);
    kk_trace__trace_dropn(_this, ((int32_t)3), _ctx);
    _x1861 = _p_208; /*effects-and-types/exp*/
    goto _match1862;
  }
  struct kk_trace_Trace* _con1864 = kk_trace__as_Trace(_this);
  kk_function_t _pat00 = _con1864->m;
  kk_effects_dash_and_dash_types__exp _x = _con1864->p;
  kk_std_core__list _pat20 = _con1864->l;
  kk_box_t _pat30 = _con1864->a;
  if (kk_trace__trace_is_unique(_this)) {
    kk_box_drop(_pat30, _ctx);
    kk_std_core__list_drop(_pat20, _ctx);
    kk_function_drop(_pat00, _ctx);
    kk_trace__trace_free(_this);
  }
  else {
    kk_trace__trace_decref(_this, _ctx);
  }
  _x1861 = _x; /*effects-and-types/exp*/
  _match1862: ;
  return kk_trace__mlift1393_op(_c_1, _x1860, a0, l0, _x1861, _ctx);
}


// lift anonymous function
struct kk_trace__copy_fun1866__t {
  struct kk_function_s _base;
  kk_trace__trace _this;
  kk_std_core_types__optional a0;
  kk_std_core_types__optional l0;
  kk_std_core_types__optional p0;
};
static kk_box_t kk_trace__copy_fun1866(kk_function_t _fself, kk_box_t _b_1547, kk_context_t* _ctx);
static kk_function_t kk_trace__new_copy_fun1866(kk_trace__trace _this, kk_std_core_types__optional a0, kk_std_core_types__optional l0, kk_std_core_types__optional p0, kk_context_t* _ctx) {
  struct kk_trace__copy_fun1866__t* _self = kk_function_alloc_as(struct kk_trace__copy_fun1866__t, 8, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_trace__copy_fun1866, kk_context());
  _self->_this = _this;
  _self->a0 = a0;
  _self->l0 = l0;
  _self->p0 = p0;
  return &_self->_base;
}

static kk_box_t kk_trace__copy_fun1866(kk_function_t _fself, kk_box_t _b_1547, kk_context_t* _ctx) {
  struct kk_trace__copy_fun1866__t* _self = kk_function_as(struct kk_trace__copy_fun1866__t*, _fself);
  kk_trace__trace _this = _self->_this; /* trace/trace<239,240> */
  kk_std_core_types__optional a0 = _self->a0; /* optional<239> */
  kk_std_core_types__optional l0 = _self->l0; /* optional<effects-and-types/trace_values> */
  kk_std_core_types__optional p0 = _self->p0; /* optional<effects-and-types/exp> */
  kk_drop_match(_self, {kk_trace__trace_dup(_this);kk_std_core_types__optional_dup(a0);kk_std_core_types__optional_dup(l0);kk_std_core_types__optional_dup(p0);}, {}, _ctx)
  kk_trace__trace _x1867;
  kk_function_t _x1868 = kk_function_unbox(_b_1547); /*() -> 240 1548*/
  _x1867 = kk_trace__mlift1394_op(_this, a0, l0, p0, _x1868, _ctx); /*trace/trace<239,240>*/
  return kk_trace__trace_box(_x1867, _ctx);
}


// lift anonymous function
struct kk_trace__copy_fun1870__t {
  struct kk_function_s _base;
  kk_trace__trace _this;
  kk_std_core_types__optional a0;
  kk_std_core_types__optional l0;
  kk_std_core_types__optional m0;
};
static kk_box_t kk_trace__copy_fun1870(kk_function_t _fself, kk_box_t _b_1553, kk_context_t* _ctx);
static kk_function_t kk_trace__new_copy_fun1870(kk_trace__trace _this, kk_std_core_types__optional a0, kk_std_core_types__optional l0, kk_std_core_types__optional m0, kk_context_t* _ctx) {
  struct kk_trace__copy_fun1870__t* _self = kk_function_alloc_as(struct kk_trace__copy_fun1870__t, 8, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_trace__copy_fun1870, kk_context());
  _self->_this = _this;
  _self->a0 = a0;
  _self->l0 = l0;
  _self->m0 = m0;
  return &_self->_base;
}

static kk_box_t kk_trace__copy_fun1870(kk_function_t _fself, kk_box_t _b_1553, kk_context_t* _ctx) {
  struct kk_trace__copy_fun1870__t* _self = kk_function_as(struct kk_trace__copy_fun1870__t*, _fself);
  kk_trace__trace _this = _self->_this; /* trace/trace<239,240> */
  kk_std_core_types__optional a0 = _self->a0; /* optional<239> */
  kk_std_core_types__optional l0 = _self->l0; /* optional<effects-and-types/trace_values> */
  kk_std_core_types__optional m0 = _self->m0; /* optional<() -> 240 239> */
  kk_drop_match(_self, {kk_trace__trace_dup(_this);kk_std_core_types__optional_dup(a0);kk_std_core_types__optional_dup(l0);kk_std_core_types__optional_dup(m0);}, {}, _ctx)
  kk_trace__trace _x1871;
  kk_function_t _x1872;
  if (kk_std_core_types__is_Optional(m0)) {
    kk_box_t _fun_unbox_x1550 = m0._cons.Optional.value;
    _x1872 = kk_function_unbox(_fun_unbox_x1550); /*() -> 240 1551*/
  }
  else {
    struct kk_trace_Trace* _con1873 = kk_trace__as_Trace(_this);
    kk_function_t _x = _con1873->m;
    kk_effects_dash_and_dash_types__exp _pat01 = _con1873->p;
    kk_function_dup(_x);
    _x1872 = _x; /*() -> 240 1551*/
  }
  kk_effects_dash_and_dash_types__exp _x1874 = kk_effects_dash_and_dash_types__exp_unbox(_b_1553, _ctx); /*effects-and-types/exp*/
  _x1871 = kk_trace__mlift1393_op(_x1872, _this, a0, l0, _x1874, _ctx); /*trace/trace<239,240>*/
  return kk_trace__trace_box(_x1871, _ctx);
}


// lift anonymous function
struct kk_trace__copy_fun1876__t {
  struct kk_function_s _base;
  kk_trace__trace _this;
  kk_std_core_types__optional a0;
  kk_std_core_types__optional m0;
  kk_std_core_types__optional p0;
};
static kk_box_t kk_trace__copy_fun1876(kk_function_t _fself, kk_box_t _b_1559, kk_context_t* _ctx);
static kk_function_t kk_trace__new_copy_fun1876(kk_trace__trace _this, kk_std_core_types__optional a0, kk_std_core_types__optional m0, kk_std_core_types__optional p0, kk_context_t* _ctx) {
  struct kk_trace__copy_fun1876__t* _self = kk_function_alloc_as(struct kk_trace__copy_fun1876__t, 8, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_trace__copy_fun1876, kk_context());
  _self->_this = _this;
  _self->a0 = a0;
  _self->m0 = m0;
  _self->p0 = p0;
  return &_self->_base;
}

static kk_box_t kk_trace__copy_fun1876(kk_function_t _fself, kk_box_t _b_1559, kk_context_t* _ctx) {
  struct kk_trace__copy_fun1876__t* _self = kk_function_as(struct kk_trace__copy_fun1876__t*, _fself);
  kk_trace__trace _this = _self->_this; /* trace/trace<239,240> */
  kk_std_core_types__optional a0 = _self->a0; /* optional<239> */
  kk_std_core_types__optional m0 = _self->m0; /* optional<() -> 240 239> */
  kk_std_core_types__optional p0 = _self->p0; /* optional<effects-and-types/exp> */
  kk_drop_match(_self, {kk_trace__trace_dup(_this);kk_std_core_types__optional_dup(a0);kk_std_core_types__optional_dup(m0);kk_std_core_types__optional_dup(p0);}, {}, _ctx)
  kk_trace__trace _x1877;
  kk_function_t _x1878;
  if (kk_std_core_types__is_Optional(m0)) {
    kk_box_t _fun_unbox_x1555 = m0._cons.Optional.value;
    _x1878 = kk_function_unbox(_fun_unbox_x1555); /*() -> 240 1556*/
  }
  else {
    struct kk_trace_Trace* _con1879 = kk_trace__as_Trace(_this);
    kk_function_t _x0 = _con1879->m;
    kk_effects_dash_and_dash_types__exp _pat010 = _con1879->p;
    kk_function_dup(_x0);
    _x1878 = _x0; /*() -> 240 1556*/
  }
  kk_effects_dash_and_dash_types__exp _x1880;
  if (kk_std_core_types__is_Optional(p0)) {
    kk_box_t _box_x1557 = p0._cons.Optional.value;
    kk_effects_dash_and_dash_types__exp _p_208 = kk_effects_dash_and_dash_types__exp_unbox(_box_x1557, NULL);
    kk_std_core_types__optional_drop(p0, _ctx);
    _x1880 = _p_208; /*effects-and-types/exp*/
    goto _match1881;
  }
  struct kk_trace_Trace* _con1883 = kk_trace__as_Trace(_this);
  kk_effects_dash_and_dash_types__exp _x00 = _con1883->p;
  _x1880 = _x00; /*effects-and-types/exp*/
  _match1881: ;
  kk_std_core__list _x1884 = kk_std_core__list_unbox(_b_1559, _ctx); /*effects-and-types/trace_values*/
  _x1877 = kk_trace__mlift1392_op(_x1878, _x1880, _this, a0, _x1884, _ctx); /*trace/trace<239,240>*/
  return kk_trace__trace_box(_x1877, _ctx);
}


// lift anonymous function
struct kk_trace__copy_fun1886__t {
  struct kk_function_s _base;
  kk_trace__trace _this;
  kk_std_core_types__optional l0;
  kk_std_core_types__optional m0;
  kk_std_core_types__optional p0;
};
static kk_box_t kk_trace__copy_fun1886(kk_function_t _fself, kk_box_t _b_1566, kk_context_t* _ctx);
static kk_function_t kk_trace__new_copy_fun1886(kk_trace__trace _this, kk_std_core_types__optional l0, kk_std_core_types__optional m0, kk_std_core_types__optional p0, kk_context_t* _ctx) {
  struct kk_trace__copy_fun1886__t* _self = kk_function_alloc_as(struct kk_trace__copy_fun1886__t, 8, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_trace__copy_fun1886, kk_context());
  _self->_this = _this;
  _self->l0 = l0;
  _self->m0 = m0;
  _self->p0 = p0;
  return &_self->_base;
}

static kk_box_t kk_trace__copy_fun1886(kk_function_t _fself, kk_box_t _b_1566, kk_context_t* _ctx) {
  struct kk_trace__copy_fun1886__t* _self = kk_function_as(struct kk_trace__copy_fun1886__t*, _fself);
  kk_trace__trace _this = _self->_this; /* trace/trace<239,240> */
  kk_std_core_types__optional l0 = _self->l0; /* optional<effects-and-types/trace_values> */
  kk_std_core_types__optional m0 = _self->m0; /* optional<() -> 240 239> */
  kk_std_core_types__optional p0 = _self->p0; /* optional<effects-and-types/exp> */
  kk_drop_match(_self, {kk_trace__trace_dup(_this);kk_std_core_types__optional_dup(l0);kk_std_core_types__optional_dup(m0);kk_std_core_types__optional_dup(p0);}, {}, _ctx)
  kk_trace__trace _x1887;
  kk_function_t _x1888;
  if (kk_std_core_types__is_Optional(m0)) {
    kk_box_t _fun_unbox_x1561 = m0._cons.Optional.value;
    _x1888 = kk_function_unbox(_fun_unbox_x1561); /*() -> 240 1562*/
  }
  else {
    struct kk_trace_Trace* _con1889 = kk_trace__as_Trace(_this);
    kk_function_t _x1 = _con1889->m;
    kk_effects_dash_and_dash_types__exp _pat011 = _con1889->p;
    kk_function_dup(_x1);
    _x1888 = _x1; /*() -> 240 1562*/
  }
  kk_effects_dash_and_dash_types__exp _x1890;
  if (kk_std_core_types__is_Optional(p0)) {
    kk_box_t _box_x1563 = p0._cons.Optional.value;
    kk_effects_dash_and_dash_types__exp _p_2080 = kk_effects_dash_and_dash_types__exp_unbox(_box_x1563, NULL);
    kk_std_core_types__optional_drop(p0, _ctx);
    _x1890 = _p_2080; /*effects-and-types/exp*/
    goto _match1891;
  }
  struct kk_trace_Trace* _con1893 = kk_trace__as_Trace(_this);
  kk_effects_dash_and_dash_types__exp _x01 = _con1893->p;
  _x1890 = _x01; /*effects-and-types/exp*/
  _match1891: ;
  kk_std_core__list _x1894;
  if (kk_std_core_types__is_Optional(l0)) {
    kk_box_t _box_x1564 = l0._cons.Optional.value;
    kk_std_core__list _l_216 = kk_std_core__list_unbox(_box_x1564, NULL);
    kk_std_core__list_dup(_l_216);
    kk_std_core_types__optional_drop(l0, _ctx);
    kk_trace__trace_dropn(_this, ((int32_t)3), _ctx);
    _x1894 = _l_216; /*effects-and-types/trace_values*/
    goto _match1895;
  }
  struct kk_trace_Trace* _con1897 = kk_trace__as_Trace(_this);
  kk_function_t _pat05 = _con1897->m;
  kk_effects_dash_and_dash_types__exp _pat130 = _con1897->p;
  kk_std_core__list _x10 = _con1897->l;
  kk_box_t _pat32 = _con1897->a;
  if (kk_trace__trace_is_unique(_this)) {
    kk_box_drop(_pat32, _ctx);
    kk_function_drop(_pat05, _ctx);
    kk_trace__trace_free(_this);
  }
  else {
    kk_std_core__list_dup(_x10);
    kk_trace__trace_decref(_this, _ctx);
  }
  _x1894 = _x10; /*effects-and-types/trace_values*/
  _match1895: ;
  _x1887 = kk_trace__mlift1391_op(_x1888, _x1890, _x1894, _b_1566, _ctx); /*trace/trace<239,240>*/
  return kk_trace__trace_box(_x1887, _ctx);
}

kk_trace__trace kk_trace__copy(kk_trace__trace _this, kk_std_core_types__optional m0, kk_std_core_types__optional p0, kk_std_core_types__optional l0, kk_std_core_types__optional a0, kk_context_t* _ctx) { /* forall<a,e> (trace<a,e>, m : optional<() -> e a>, p : optional<effects-and-types/exp>, l : optional<effects-and-types/trace_values>, a : optional<a>) -> trace<a,e> */ 
  if (kk_yielding(kk_context())) {
    kk_std_core_types__optional_drop(m0, _ctx);
    kk_box_t _x1865 = kk_std_core_hnd_yield_extend(kk_trace__new_copy_fun1866(_this, a0, l0, p0, _ctx), _ctx); /*2*/
    return kk_trace__trace_unbox(_x1865, _ctx);
  }
  if (kk_yielding(kk_context())) {
    kk_std_core_types__optional_drop(p0, _ctx);
    kk_box_t _x1869 = kk_std_core_hnd_yield_extend(kk_trace__new_copy_fun1870(_this, a0, l0, m0, _ctx), _ctx); /*2*/
    return kk_trace__trace_unbox(_x1869, _ctx);
  }
  if (kk_yielding(kk_context())) {
    kk_std_core_types__optional_drop(l0, _ctx);
    kk_box_t _x1875 = kk_std_core_hnd_yield_extend(kk_trace__new_copy_fun1876(_this, a0, m0, p0, _ctx), _ctx); /*2*/
    return kk_trace__trace_unbox(_x1875, _ctx);
  }
  if (kk_yielding(kk_context())) {
    kk_std_core_types__optional_drop(a0, _ctx);
    kk_box_t _x1885 = kk_std_core_hnd_yield_extend(kk_trace__new_copy_fun1886(_this, l0, m0, p0, _ctx), _ctx); /*2*/
    return kk_trace__trace_unbox(_x1885, _ctx);
  }
  kk_function_t _x1898;
  if (kk_std_core_types__is_Optional(m0)) {
    kk_box_t _fun_unbox_x1568 = m0._cons.Optional.value;
    _x1898 = kk_function_unbox(_fun_unbox_x1568); /*() -> 240 1569*/
  }
  else {
    struct kk_trace_Trace* _con1899 = kk_trace__as_Trace(_this);
    kk_function_t _x2 = _con1899->m;
    kk_effects_dash_and_dash_types__exp _pat012 = _con1899->p;
    kk_function_dup(_x2);
    _x1898 = _x2; /*() -> 240 1569*/
  }
  kk_effects_dash_and_dash_types__exp _x1900;
  if (kk_std_core_types__is_Optional(p0)) {
    kk_box_t _box_x1570 = p0._cons.Optional.value;
    kk_effects_dash_and_dash_types__exp _p_2081 = kk_effects_dash_and_dash_types__exp_unbox(_box_x1570, NULL);
    kk_std_core_types__optional_drop(p0, _ctx);
    _x1900 = _p_2081; /*effects-and-types/exp*/
    goto _match1901;
  }
  struct kk_trace_Trace* _con1903 = kk_trace__as_Trace(_this);
  kk_effects_dash_and_dash_types__exp _x02 = _con1903->p;
  _x1900 = _x02; /*effects-and-types/exp*/
  _match1901: ;
  kk_std_core__list _x1904;
  if (kk_std_core_types__is_Optional(l0)) {
    kk_box_t _box_x1571 = l0._cons.Optional.value;
    kk_std_core__list _l_2160 = kk_std_core__list_unbox(_box_x1571, NULL);
    kk_std_core__list_dup(_l_2160);
    kk_std_core_types__optional_drop(l0, _ctx);
    _x1904 = _l_2160; /*effects-and-types/trace_values*/
    goto _match1905;
  }
  struct kk_trace_Trace* _con1907 = kk_trace__as_Trace(_this);
  kk_effects_dash_and_dash_types__exp _pat131 = _con1907->p;
  kk_std_core__list _x11 = _con1907->l;
  kk_std_core__list_dup(_x11);
  _x1904 = _x11; /*effects-and-types/trace_values*/
  _match1905: ;
  kk_box_t _x1908;
  if (kk_std_core_types__is_Optional(a0)) {
    kk_box_t _a_224 = a0._cons.Optional.value;
    kk_trace__trace_dropn(_this, ((int32_t)3), _ctx);
    _x1908 = _a_224; /*239*/
  }
  else {
    struct kk_trace_Trace* _con1909 = kk_trace__as_Trace(_this);
    kk_function_t _pat07 = _con1909->m;
    kk_effects_dash_and_dash_types__exp _pat140 = _con1909->p;
    kk_std_core__list _pat330 = _con1909->l;
    kk_box_t _x20 = _con1909->a;
    if (kk_trace__trace_is_unique(_this)) {
      kk_std_core__list_drop(_pat330, _ctx);
      kk_function_drop(_pat07, _ctx);
      kk_trace__trace_free(_this);
    }
    else {
      kk_box_dup(_x20);
      kk_trace__trace_decref(_this, _ctx);
    }
    _x1908 = _x20; /*239*/
  }
  return kk_trace__new_Trace(kk_reuse_null, _x1898, _x1900, _x1904, _x1908, _ctx);
}
 
// monadic lift

kk_integer_t kk_trace__mlift1395_random__range(kk_integer_t upper__bound, double _y_5, kk_context_t* _ctx) { /* (upper_bound : int, double) -> effects-and-types/sample int */ 
  kk_integer_t _x1910;
  double _x1911;
  double _x1912;
  double _x1913;
  kk_integer_t _x1914 = kk_integer_dup(upper__bound); /*int*/
  _x1913 = kk_integer_as_double(_x1914,kk_context()); /*double*/
  _x1912 = (0x1p0 / _x1913); /*double*/
  _x1911 = (_y_5 / _x1912); /*double*/
  _x1910 = kk_integer_from_double(_x1911,kk_context()); /*int*/
  return kk_integer_mod(_x1910,upper__bound,kk_context());
}


// lift anonymous function
struct kk_trace_random__range_fun1916__t {
  struct kk_function_s _base;
  kk_integer_t upper__bound;
};
static kk_box_t kk_trace_random__range_fun1916(kk_function_t _fself, kk_box_t _b_1581, kk_context_t* _ctx);
static kk_function_t kk_trace_new_random__range_fun1916(kk_integer_t upper__bound, kk_context_t* _ctx) {
  struct kk_trace_random__range_fun1916__t* _self = kk_function_alloc_as(struct kk_trace_random__range_fun1916__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_trace_random__range_fun1916, kk_context());
  _self->upper__bound = upper__bound;
  return &_self->_base;
}

static kk_box_t kk_trace_random__range_fun1916(kk_function_t _fself, kk_box_t _b_1581, kk_context_t* _ctx) {
  struct kk_trace_random__range_fun1916__t* _self = kk_function_as(struct kk_trace_random__range_fun1916__t*, _fself);
  kk_integer_t upper__bound = _self->upper__bound; /* int */
  kk_drop_match(_self, {kk_integer_dup(upper__bound);}, {}, _ctx)
  kk_integer_t _x1917;
  double _x1918 = kk_double_unbox(_b_1581, _ctx); /*double*/
  _x1917 = kk_trace__mlift1395_random__range(upper__bound, _x1918, _ctx); /*int*/
  return kk_integer_box(_x1917);
}

kk_integer_t kk_trace_random__range(kk_integer_t upper__bound, kk_context_t* _ctx) { /* (upper_bound : int) -> effects-and-types/sample int */ 
  double x_1432 = kk_effects_dash_and_dash_types_sample(_ctx); /*double*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x1915 = kk_std_core_hnd_yield_extend(kk_trace_new_random__range_fun1916(upper__bound, _ctx), _ctx); /*2*/
    return kk_integer_unbox(_x1915);
  }
  kk_integer_t _x1919;
  double _x1920;
  double _x1921;
  double _x1922;
  kk_integer_t _x1923 = kk_integer_dup(upper__bound); /*int*/
  _x1922 = kk_integer_as_double(_x1923,kk_context()); /*double*/
  _x1921 = (0x1p0 / _x1922); /*double*/
  _x1920 = (x_1432 / _x1921); /*double*/
  _x1919 = kk_integer_from_double(_x1920,kk_context()); /*int*/
  return kk_integer_mod(_x1919,upper__bound,kk_context());
}


// lift anonymous function
struct kk_trace_with__randomness_fun1924__t {
  struct kk_function_s _base;
  kk_function_t model;
};
static kk_box_t kk_trace_with__randomness_fun1924(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_trace_new_with__randomness_fun1924(kk_function_t model, kk_context_t* _ctx) {
  struct kk_trace_with__randomness_fun1924__t* _self = kk_function_alloc_as(struct kk_trace_with__randomness_fun1924__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_trace_with__randomness_fun1924, kk_context());
  _self->model = model;
  return &_self->_base;
}



// lift anonymous function
struct kk_trace_with__randomness_fun1928__t {
  struct kk_function_s _base;
  kk_function_t model;
};
static kk_box_t kk_trace_with__randomness_fun1928(kk_function_t _fself, kk_box_t _b_1587, kk_context_t* _ctx);
static kk_function_t kk_trace_new_with__randomness_fun1928(kk_function_t model, kk_context_t* _ctx) {
  struct kk_trace_with__randomness_fun1928__t* _self = kk_function_alloc_as(struct kk_trace_with__randomness_fun1928__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_trace_with__randomness_fun1928, kk_context());
  _self->model = model;
  return &_self->_base;
}



// lift anonymous function
struct kk_trace_with__randomness_fun1929__t {
  struct kk_function_s _base;
  kk_function_t model;
};
static kk_box_t kk_trace_with__randomness_fun1929(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_trace_new_with__randomness_fun1929(kk_function_t model, kk_context_t* _ctx) {
  struct kk_trace_with__randomness_fun1929__t* _self = kk_function_alloc_as(struct kk_trace_with__randomness_fun1929__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_trace_with__randomness_fun1929, kk_context());
  _self->model = model;
  return &_self->_base;
}

static kk_box_t kk_trace_with__randomness_fun1929(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_trace_with__randomness_fun1929__t* _self = kk_function_as(struct kk_trace_with__randomness_fun1929__t*, _fself);
  kk_function_t model = _self->model; /* () -> <effects-and-types/sample,effects-and-types/score|466> 465 */
  kk_drop_match(_self, {kk_function_dup(model);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x1930;
  kk_effects_dash_and_dash_types__exp _x1931 = kk_effects_dash_and_dash_types__new_Exp(0x0p+0, _ctx); /*effects-and-types/exp*/
  _x1930 = kk_handlers_weighted(_x1931, model, _ctx); /*(effects-and-types/exp, 0)*/
  return kk_std_core_types__tuple2__box(_x1930, _ctx);
}
static kk_box_t kk_trace_with__randomness_fun1928(kk_function_t _fself, kk_box_t _b_1587, kk_context_t* _ctx) {
  struct kk_trace_with__randomness_fun1928__t* _self = kk_function_as(struct kk_trace_with__randomness_fun1928__t*, _fself);
  kk_function_t model = _self->model; /* () -> <effects-and-types/sample,effects-and-types/score|466> 465 */
  kk_drop_match(_self, {kk_function_dup(model);}, {}, _ctx)
  size_t _x1932 = kk_size_unbox(_b_1587, _ctx); /*std/core/hnd/ev-index*/
  return kk_handlers__mlift1713_replay(kk_trace_new_with__randomness_fun1929(model, _ctx), _x1932, _ctx);
}


// lift anonymous function
struct kk_trace_with__randomness_fun1933__t {
  struct kk_function_s _base;
  kk_function_t model;
};
static kk_box_t kk_trace_with__randomness_fun1933(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_trace_new_with__randomness_fun1933(kk_function_t model, kk_context_t* _ctx) {
  struct kk_trace_with__randomness_fun1933__t* _self = kk_function_alloc_as(struct kk_trace_with__randomness_fun1933__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_trace_with__randomness_fun1933, kk_context());
  _self->model = model;
  return &_self->_base;
}

static kk_box_t kk_trace_with__randomness_fun1933(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_trace_with__randomness_fun1933__t* _self = kk_function_as(struct kk_trace_with__randomness_fun1933__t*, _fself);
  kk_function_t model = _self->model; /* () -> <effects-and-types/sample,effects-and-types/score|466> 465 */
  kk_drop_match(_self, {kk_function_dup(model);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x1934;
  kk_effects_dash_and_dash_types__exp _x1935 = kk_effects_dash_and_dash_types__new_Exp(0x0p+0, _ctx); /*effects-and-types/exp*/
  _x1934 = kk_handlers_weighted(_x1935, model, _ctx); /*(effects-and-types/exp, 0)*/
  return kk_std_core_types__tuple2__box(_x1934, _ctx);
}
static kk_box_t kk_trace_with__randomness_fun1924(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_trace_with__randomness_fun1924__t* _self = kk_function_as(struct kk_trace_with__randomness_fun1924__t*, _fself);
  kk_function_t model = _self->model; /* () -> <effects-and-types/sample,effects-and-types/score|466> 465 */
  kk_drop_match(_self, {kk_function_dup(model);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x1925;
  size_t x_1791;
  kk_std_core_hnd__htag _x1926 = kk_std_core_hnd__htag_dup(kk_effects_dash_and_dash_types__tag_sample); /*std/core/hnd/htag<effects-and-types/.hnd-sample>*/
  x_1791 = kk_std_core_hnd__evv_index(_x1926, _ctx); /*std/core/hnd/ev-index*/
  kk_box_t _x1927;
  if (kk_yielding(kk_context())) {
    _x1927 = kk_std_core_hnd_yield_extend(kk_trace_new_with__randomness_fun1928(model, _ctx), _ctx); /*2*/
  }
  else {
    _x1927 = kk_handlers__mlift1713_replay(kk_trace_new_with__randomness_fun1933(model, _ctx), x_1791, _ctx); /*2*/
  }
  _x1925 = kk_std_core_types__tuple2__unbox(_x1927, _ctx); /*(effects-and-types/exp, 465)*/
  return kk_std_core_types__tuple2__box(_x1925, _ctx);
}

kk_std_core_types__tuple2_ kk_trace_with__randomness(kk_function_t model, kk_std_core__list trace__values, kk_context_t* _ctx) { /* forall<a,e> (model : () -> <effects-and-types/sample,effects-and-types/score|e> a, trace_values : effects-and-types/trace_values) -> <effects-and-types/sample|e> (effects-and-types/trace_values, (effects-and-types/exp, a)) */ 
  return kk_handlers_replayx(trace__values, kk_trace_new_with__randomness_fun1924(model, _ctx), _ctx);
}
 
// monadic lift

kk_std_core__list kk_trace__mlift1396_perturb__trace(kk_std_core__list l1, kk_std_core__list l2, double _y_9, kk_context_t* _ctx) { /* (l1 : list<double>, l2 : list<double>, double) -> effects-and-types/sample list<double> */ 
  kk_std_core__list ys_1439;
  kk_std_core__list xs0_1440 = kk_std_core__new_Cons(kk_reuse_null, kk_double_box(_y_9, _ctx), kk_std_core__new_Nil(_ctx), _ctx); /*list<double>*/;
  ys_1439 = kk_std_core_append(xs0_1440, l2, _ctx); /*list<double>*/
  return kk_std_core_append(l1, ys_1439, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_trace__mlift1397_perturb__trace_fun1941__t {
  struct kk_function_s _base;
  kk_std_core__list l1;
  kk_std_core__list l2;
};
static kk_box_t kk_trace__mlift1397_perturb__trace_fun1941(kk_function_t _fself, kk_box_t _b_1608, kk_context_t* _ctx);
static kk_function_t kk_trace__new_mlift1397_perturb__trace_fun1941(kk_std_core__list l1, kk_std_core__list l2, kk_context_t* _ctx) {
  struct kk_trace__mlift1397_perturb__trace_fun1941__t* _self = kk_function_alloc_as(struct kk_trace__mlift1397_perturb__trace_fun1941__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_trace__mlift1397_perturb__trace_fun1941, kk_context());
  _self->l1 = l1;
  _self->l2 = l2;
  return &_self->_base;
}

static kk_box_t kk_trace__mlift1397_perturb__trace_fun1941(kk_function_t _fself, kk_box_t _b_1608, kk_context_t* _ctx) {
  struct kk_trace__mlift1397_perturb__trace_fun1941__t* _self = kk_function_as(struct kk_trace__mlift1397_perturb__trace_fun1941__t*, _fself);
  kk_std_core__list l1 = _self->l1; /* list<double> */
  kk_std_core__list l2 = _self->l2; /* list<double> */
  kk_drop_match(_self, {kk_std_core__list_dup(l1);kk_std_core__list_dup(l2);}, {}, _ctx)
  kk_std_core__list _x1942;
  double _x1943 = kk_double_unbox(_b_1608, _ctx); /*double*/
  _x1942 = kk_trace__mlift1396_perturb__trace(l1, l2, _x1943, _ctx); /*list<double>*/
  return kk_std_core__list_box(_x1942, _ctx);
}

kk_std_core__list kk_trace__mlift1397_perturb__trace(kk_std_core__list trace__values, kk_integer_t perturb__index, kk_context_t* _ctx) { /* (trace_values : effects-and-types/trace_values, perturb_index : int) -> effects-and-types/sample list<double> */ 
  kk_std_core_types__tuple2_ div__trace = kk_std_core_split(trace__values, perturb__index, _ctx); /*(list<double>, list<double>)*/;
  kk_box_t _box_x1604 = div__trace.fst;
  kk_box_t _box_x1605 = div__trace.snd;
  kk_std_core__list l1 = kk_std_core__list_unbox(_box_x1604, NULL);
  kk_std_core__list _pat0 = kk_std_core__list_unbox(_box_x1605, NULL);
  if (kk_std_core__is_Cons(_pat0)) {
    struct kk_std_core_Cons* _con1938 = kk_std_core__as_Cons(_pat0);
    kk_box_t _box_x1606 = _con1938->head;
    kk_std_core__list l2 = _con1938->tail;
    kk_std_core__list_dup(l1);
    kk_std_core__list_dup(l2);
    kk_std_core_types__tuple2__drop(div__trace, _ctx);
    double x_1442 = kk_effects_dash_and_dash_types_sample(_ctx); /*double*/;
    if (kk_yielding(kk_context())) {
      kk_box_t _x1940 = kk_std_core_hnd_yield_extend(kk_trace__new_mlift1397_perturb__trace_fun1941(l1, l2, _ctx), _ctx); /*2*/
      return kk_std_core__list_unbox(_x1940, _ctx);
    }
    return kk_trace__mlift1396_perturb__trace(l1, l2, x_1442, _ctx);
  }
  kk_box_t _box_x1609 = div__trace.fst;
  kk_box_t _box_x1610 = div__trace.snd;
  kk_std_core__list l10 = kk_std_core__list_unbox(_box_x1609, NULL);
  kk_std_core__list l20 = kk_std_core__list_unbox(_box_x1610, NULL);
  kk_std_core__list_dup(l10);
  kk_std_core__list_dup(l20);
  kk_std_core_types__tuple2__drop(div__trace, _ctx);
  return kk_std_core__lp__plus__plus__rp_(l10, l20, _ctx);
}


// lift anonymous function
struct kk_trace_perturb__trace_fun1949__t {
  struct kk_function_s _base;
  kk_integer_t upper__bound_1449;
};
static kk_box_t kk_trace_perturb__trace_fun1949(kk_function_t _fself, kk_box_t _b_1614, kk_context_t* _ctx);
static kk_function_t kk_trace_new_perturb__trace_fun1949(kk_integer_t upper__bound_1449, kk_context_t* _ctx) {
  struct kk_trace_perturb__trace_fun1949__t* _self = kk_function_alloc_as(struct kk_trace_perturb__trace_fun1949__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_trace_perturb__trace_fun1949, kk_context());
  _self->upper__bound_1449 = upper__bound_1449;
  return &_self->_base;
}

static kk_box_t kk_trace_perturb__trace_fun1949(kk_function_t _fself, kk_box_t _b_1614, kk_context_t* _ctx) {
  struct kk_trace_perturb__trace_fun1949__t* _self = kk_function_as(struct kk_trace_perturb__trace_fun1949__t*, _fself);
  kk_integer_t upper__bound_1449 = _self->upper__bound_1449; /* int */
  kk_drop_match(_self, {kk_integer_dup(upper__bound_1449);}, {}, _ctx)
  kk_integer_t _x1950;
  double _x1951 = kk_double_unbox(_b_1614, _ctx); /*double*/
  _x1950 = kk_trace__mlift1395_random__range(upper__bound_1449, _x1951, _ctx); /*int*/
  return kk_integer_box(_x1950);
}


// lift anonymous function
struct kk_trace_perturb__trace_fun1958__t {
  struct kk_function_s _base;
  kk_std_core__list trace__values;
};
static kk_box_t kk_trace_perturb__trace_fun1958(kk_function_t _fself, kk_box_t _b_1618, kk_context_t* _ctx);
static kk_function_t kk_trace_new_perturb__trace_fun1958(kk_std_core__list trace__values, kk_context_t* _ctx) {
  struct kk_trace_perturb__trace_fun1958__t* _self = kk_function_alloc_as(struct kk_trace_perturb__trace_fun1958__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_trace_perturb__trace_fun1958, kk_context());
  _self->trace__values = trace__values;
  return &_self->_base;
}

static kk_box_t kk_trace_perturb__trace_fun1958(kk_function_t _fself, kk_box_t _b_1618, kk_context_t* _ctx) {
  struct kk_trace_perturb__trace_fun1958__t* _self = kk_function_as(struct kk_trace_perturb__trace_fun1958__t*, _fself);
  kk_std_core__list trace__values = _self->trace__values; /* effects-and-types/trace_values */
  kk_drop_match(_self, {kk_std_core__list_dup(trace__values);}, {}, _ctx)
  kk_std_core__list _x1959;
  kk_integer_t _x1960 = kk_integer_unbox(_b_1618); /*int*/
  _x1959 = kk_trace__mlift1397_perturb__trace(trace__values, _x1960, _ctx); /*list<double>*/
  return kk_std_core__list_box(_x1959, _ctx);
}


// lift anonymous function
struct kk_trace_perturb__trace_fun1966__t {
  struct kk_function_s _base;
  kk_std_core__list l1;
  kk_std_core__list l2;
};
static kk_box_t kk_trace_perturb__trace_fun1966(kk_function_t _fself, kk_box_t _b_1623, kk_context_t* _ctx);
static kk_function_t kk_trace_new_perturb__trace_fun1966(kk_std_core__list l1, kk_std_core__list l2, kk_context_t* _ctx) {
  struct kk_trace_perturb__trace_fun1966__t* _self = kk_function_alloc_as(struct kk_trace_perturb__trace_fun1966__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_trace_perturb__trace_fun1966, kk_context());
  _self->l1 = l1;
  _self->l2 = l2;
  return &_self->_base;
}

static kk_box_t kk_trace_perturb__trace_fun1966(kk_function_t _fself, kk_box_t _b_1623, kk_context_t* _ctx) {
  struct kk_trace_perturb__trace_fun1966__t* _self = kk_function_as(struct kk_trace_perturb__trace_fun1966__t*, _fself);
  kk_std_core__list l1 = _self->l1; /* list<double> */
  kk_std_core__list l2 = _self->l2; /* list<double> */
  kk_drop_match(_self, {kk_std_core__list_dup(l1);kk_std_core__list_dup(l2);}, {}, _ctx)
  kk_std_core__list _x1967;
  double _x1968 = kk_double_unbox(_b_1623, _ctx); /*double*/
  _x1967 = kk_trace__mlift1396_perturb__trace(l1, l2, _x1968, _ctx); /*list<double>*/
  return kk_std_core__list_box(_x1967, _ctx);
}

kk_std_core__list kk_trace_perturb__trace(kk_trace__trace trace, kk_context_t* _ctx) { /* forall<a,e> (trace : trace<a,e>) -> effects-and-types/sample effects-and-types/trace_values */ 
  kk_std_core__list trace__values;
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*std/core/hnd/evv<(<>)>*/;
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  struct kk_trace_Trace* _con1946 = kk_trace__as_Trace(trace);
  kk_function_t _pat0 = _con1946->m;
  kk_effects_dash_and_dash_types__exp _pat1 = _con1946->p;
  kk_std_core__list _x = _con1946->l;
  kk_box_t _pat3 = _con1946->a;
  if (kk_trace__trace_is_unique(trace)) {
    kk_box_drop(_pat3, _ctx);
    kk_function_drop(_pat0, _ctx);
    kk_trace__trace_free(trace);
  }
  else {
    kk_std_core__list_dup(_x);
    kk_trace__trace_decref(trace, _ctx);
  }
  trace__values = _x; /*effects-and-types/trace_values*/
  kk_integer_t x0_1446;
  kk_integer_t upper__bound_1449;
  kk_std_core__list _x1947 = kk_std_core__list_dup(trace__values); /*effects-and-types/trace_values*/
  upper__bound_1449 = kk_std_core_length_1(_x1947, _ctx); /*int*/
  double x2_1450 = kk_effects_dash_and_dash_types_sample(_ctx); /*double*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x1948 = kk_std_core_hnd_yield_extend(kk_trace_new_perturb__trace_fun1949(upper__bound_1449, _ctx), _ctx); /*2*/
    x0_1446 = kk_integer_unbox(_x1948); /*int*/
  }
  else {
    kk_integer_t _x1952;
    double _x1953;
    double _x1954;
    double _x1955;
    kk_integer_t _x1956 = kk_integer_dup(upper__bound_1449); /*int*/
    _x1955 = kk_integer_as_double(_x1956,kk_context()); /*double*/
    _x1954 = (0x1p0 / _x1955); /*double*/
    _x1953 = (x2_1450 / _x1954); /*double*/
    _x1952 = kk_integer_from_double(_x1953,kk_context()); /*int*/
    x0_1446 = kk_integer_mod(_x1952,upper__bound_1449,kk_context()); /*int*/
  }
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x0_1446, _ctx);
    kk_box_t _x1957 = kk_std_core_hnd_yield_extend(kk_trace_new_perturb__trace_fun1958(trace__values, _ctx), _ctx); /*2*/
    return kk_std_core__list_unbox(_x1957, _ctx);
  }
  kk_std_core_types__tuple2_ div__trace = kk_std_core_split(trace__values, x0_1446, _ctx); /*(list<double>, list<double>)*/;
  kk_box_t _box_x1619 = div__trace.fst;
  kk_box_t _box_x1620 = div__trace.snd;
  kk_std_core__list l1 = kk_std_core__list_unbox(_box_x1619, NULL);
  kk_std_core__list _pat010 = kk_std_core__list_unbox(_box_x1620, NULL);
  if (kk_std_core__is_Cons(_pat010)) {
    struct kk_std_core_Cons* _con1963 = kk_std_core__as_Cons(_pat010);
    kk_box_t _box_x1621 = _con1963->head;
    kk_std_core__list l2 = _con1963->tail;
    kk_reuse_t _ru_1800 = kk_reuse_null; /*reuse*/;
    kk_std_core__list_dup(l1);
    kk_std_core__list_dup(l2);
    _ru_1800 = kk_reuse_null;
    kk_std_core_types__tuple2__drop(div__trace, _ctx);
    double x3_1455 = kk_effects_dash_and_dash_types_sample(_ctx); /*double*/;
    if (kk_yielding(kk_context())) {
      kk_reuse_drop(_ru_1800, _ctx);
      kk_box_t _x1965 = kk_std_core_hnd_yield_extend(kk_trace_new_perturb__trace_fun1966(l1, l2, _ctx), _ctx); /*2*/
      return kk_std_core__list_unbox(_x1965, _ctx);
    }
    kk_std_core__list ys_1460;
    kk_std_core__list xs0_1461 = kk_std_core__new_Cons(_ru_1800, kk_double_box(x3_1455, _ctx), kk_std_core__new_Nil(_ctx), _ctx); /*list<double>*/;
    ys_1460 = kk_std_core_append(xs0_1461, l2, _ctx); /*list<double>*/
    return kk_std_core_append(l1, ys_1460, _ctx);
  }
  kk_box_t _box_x1628 = div__trace.fst;
  kk_box_t _box_x1629 = div__trace.snd;
  kk_std_core__list l10 = kk_std_core__list_unbox(_box_x1628, NULL);
  kk_std_core__list l20 = kk_std_core__list_unbox(_box_x1629, NULL);
  kk_std_core__list_dup(l10);
  kk_std_core__list_dup(l20);
  kk_std_core_types__tuple2__drop(div__trace, _ctx);
  return kk_std_core__lp__plus__plus__rp_(l10, l20, _ctx);
}
 
// monadic lift

kk_trace__trace kk_trace__mlift1398_mh__step(kk_box_t b, kk_function_t model, kk_std_core__list new__trace, kk_effects_dash_and_dash_types__exp p2, kk_trace__trace trace, bool accept, kk_context_t* _ctx) { /* forall<a,e> (b : a, model : () -> <effects-and-types/sample,effects-and-types/score|e> a, new_trace : effects-and-types/trace_values, p2 : effects-and-types/exp, trace : trace<a,<effects-and-types/sample,effects-and-types/score|e>>, accept : bool) -> <effects-and-types/sample|e> trace<a,<effects-and-types/sample,effects-and-types/score|e>> */ 
  if (accept) {
    kk_trace__trace_dropn(trace, ((int32_t)3), _ctx);
    return kk_trace__new_Trace(kk_reuse_null, model, p2, new__trace, b, _ctx);
  }
  kk_box_drop(b, _ctx);
  kk_function_drop(model, _ctx);
  kk_std_core__list_drop(new__trace, _ctx);
  return trace;
}
 
// monadic lift


// lift anonymous function
struct kk_trace__mlift1399_mh__step_fun1977__t {
  struct kk_function_s _base;
};
static kk_box_t kk_trace__mlift1399_mh__step_fun1977(kk_function_t _fself, kk_box_t _b_1639, kk_context_t* _ctx);
static kk_function_t kk_trace__new_mlift1399_mh__step_fun1977(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_trace__mlift1399_mh__step_fun1977, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_trace__mlift1399_mh__step_fun1977(kk_function_t _fself, kk_box_t _b_1639, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x1978;
  kk_effects_dash_and_dash_types__exp _x1979 = kk_effects_dash_and_dash_types__exp_unbox(_b_1639, _ctx); /*effects-and-types/exp*/
  _x1978 = kk_exponents_exp__to__double(_x1979, _ctx); /*double*/
  return kk_double_box(_x1978, _ctx);
}


// lift anonymous function
struct kk_trace__mlift1399_mh__step_fun1985__t {
  struct kk_function_s _base;
};
static kk_box_t kk_trace__mlift1399_mh__step_fun1985(kk_function_t _fself, kk_box_t _b_1642, kk_context_t* _ctx);
static kk_function_t kk_trace__new_mlift1399_mh__step_fun1985(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_trace__mlift1399_mh__step_fun1985, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_trace__mlift1399_mh__step_fun1985(kk_function_t _fself, kk_box_t _b_1642, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x1986;
  kk_effects_dash_and_dash_types__exp _x1987 = kk_effects_dash_and_dash_types__exp_unbox(_b_1642, _ctx); /*effects-and-types/exp*/
  _x1986 = kk_exponents_exp__to__double(_x1987, _ctx); /*double*/
  return kk_double_box(_x1986, _ctx);
}


// lift anonymous function
struct kk_trace__mlift1399_mh__step_fun1993__t {
  struct kk_function_s _base;
  size_t i_1467;
};
static kk_box_t kk_trace__mlift1399_mh__step_fun1993(kk_function_t _fself, kk_function_t _b_1652, kk_box_t _b_1653, kk_context_t* _ctx);
static kk_function_t kk_trace__new_mlift1399_mh__step_fun1993(size_t i_1467, kk_context_t* _ctx) {
  struct kk_trace__mlift1399_mh__step_fun1993__t* _self = kk_function_alloc_as(struct kk_trace__mlift1399_mh__step_fun1993__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_trace__mlift1399_mh__step_fun1993, kk_context());
  _self->i_1467 = i_1467;
  return &_self->_base;
}

static kk_box_t kk_trace__mlift1399_mh__step_fun1993(kk_function_t _fself, kk_function_t _b_1652, kk_box_t _b_1653, kk_context_t* _ctx) {
  struct kk_trace__mlift1399_mh__step_fun1993__t* _self = kk_function_as(struct kk_trace__mlift1399_mh__step_fun1993__t*, _fself);
  size_t i_1467 = _self->i_1467; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_1467, _b_1652, _b_1653, _ctx);
}


// lift anonymous function
struct kk_trace__mlift1399_mh__step_fun1995__t {
  struct kk_function_s _base;
  kk_box_t b;
  kk_function_t model;
  kk_std_core__list new__trace;
  kk_trace__trace trace;
  kk_effects_dash_and_dash_types__exp p2;
};
static kk_box_t kk_trace__mlift1399_mh__step_fun1995(kk_function_t _fself, kk_box_t _b_1663, kk_context_t* _ctx);
static kk_function_t kk_trace__new_mlift1399_mh__step_fun1995(kk_box_t b, kk_function_t model, kk_std_core__list new__trace, kk_trace__trace trace, kk_effects_dash_and_dash_types__exp p2, kk_context_t* _ctx) {
  struct kk_trace__mlift1399_mh__step_fun1995__t* _self = kk_function_alloc_as(struct kk_trace__mlift1399_mh__step_fun1995__t, 5, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_trace__mlift1399_mh__step_fun1995, kk_context());
  _self->b = b;
  _self->model = model;
  _self->new__trace = new__trace;
  _self->trace = trace;
  _self->p2 = p2;
  return &_self->_base;
}

static kk_box_t kk_trace__mlift1399_mh__step_fun1995(kk_function_t _fself, kk_box_t _b_1663, kk_context_t* _ctx) {
  struct kk_trace__mlift1399_mh__step_fun1995__t* _self = kk_function_as(struct kk_trace__mlift1399_mh__step_fun1995__t*, _fself);
  kk_box_t b = _self->b; /* 829 */
  kk_function_t model = _self->model; /* () -> <effects-and-types/sample,effects-and-types/score|830> 829 */
  kk_std_core__list new__trace = _self->new__trace; /* effects-and-types/trace_values */
  kk_trace__trace trace = _self->trace; /* trace/trace<829,<effects-and-types/sample,effects-and-types/score|830>> */
  kk_effects_dash_and_dash_types__exp p2 = _self->p2; /* effects-and-types/exp */
  kk_drop_match(_self, {kk_box_dup(b);kk_function_dup(model);kk_std_core__list_dup(new__trace);kk_trace__trace_dup(trace);kk_effects_dash_and_dash_types__exp_dup(p2);}, {}, _ctx)
  kk_trace__trace _x1996;
  bool _x1997 = kk_bool_unbox(_b_1663); /*bool*/
  _x1996 = kk_trace__mlift1398_mh__step(b, model, new__trace, p2, trace, _x1997, _ctx); /*trace/trace<829,<effects-and-types/sample,effects-and-types/score|830>>*/
  return kk_trace__trace_box(_x1996, _ctx);
}

kk_trace__trace kk_trace__mlift1399_mh__step(kk_function_t model, kk_std_core__list old__trace, kk_effects_dash_and_dash_types__exp p1, kk_trace__trace trace, kk_std_core_types__tuple2_ p2b, kk_context_t* _ctx) { /* forall<a,e> (model : () -> <effects-and-types/sample,effects-and-types/score|e> a, old_trace : effects-and-types/trace_values, p1 : effects-and-types/exp, trace : trace<a,<effects-and-types/sample,effects-and-types/score|e>>, p2b : (effects-and-types/trace_values, (effects-and-types/exp, a))) -> <effects-and-types/sample|e> trace<a,<effects-and-types/sample,effects-and-types/score|e>> */ 
  kk_box_t _box_x1634 = p2b.fst;
  kk_box_t _box_x1635 = p2b.snd;
  kk_std_core__list new__trace = kk_std_core__list_unbox(_box_x1634, NULL);
  kk_std_core_types__tuple2_ _pat3 = kk_std_core_types__tuple2__unbox(_box_x1635, NULL);
  kk_box_t _box_x1636 = _pat3.fst;
  kk_box_t b = _pat3.snd;
  kk_effects_dash_and_dash_types__exp p2 = kk_effects_dash_and_dash_types__exp_unbox(_box_x1636, NULL);
  kk_box_dup(b);
  kk_std_core__list_dup(new__trace);
  kk_std_core_types__tuple2__drop(p2b, _ctx);
  double ratio;
  double y_1464;
  double _x1974;
  double _x1975;
  kk_box_t _x1976 = kk_std_core_hnd__open_none1(kk_trace__new_mlift1399_mh__step_fun1977(_ctx), kk_effects_dash_and_dash_types__exp_box(p2, _ctx), _ctx); /*2*/
  _x1975 = kk_double_unbox(_x1976, _ctx); /*double*/
  double _x1980;
  kk_integer_t _x1981 = kk_std_core_length_1(old__trace, _ctx); /*int*/
  _x1980 = kk_integer_as_double(_x1981,kk_context()); /*double*/
  _x1974 = (_x1975 * _x1980); /*double*/
  double _x1982;
  double _x1983;
  kk_box_t _x1984 = kk_std_core_hnd__open_none1(kk_trace__new_mlift1399_mh__step_fun1985(_ctx), kk_effects_dash_and_dash_types__exp_box(p1, _ctx), _ctx); /*2*/
  _x1983 = kk_double_unbox(_x1984, _ctx); /*double*/
  double _x1988;
  kk_integer_t _x1989;
  kk_std_core__list _x1990 = kk_std_core__list_dup(new__trace); /*effects-and-types/trace_values*/
  _x1989 = kk_std_core_length_1(_x1990, _ctx); /*int*/
  _x1988 = kk_integer_as_double(_x1989,kk_context()); /*double*/
  _x1982 = (_x1983 * _x1988); /*double*/
  y_1464 = (_x1974 / _x1982); /*double*/
  bool _match_1824 = (0x1p0 <= y_1464); /*bool*/;
  if (_match_1824) {
    ratio = 0x1p0; /*double*/
  }
  else {
    ratio = y_1464; /*double*/
  }
  bool x0_1465;
  size_t i_1467;
  kk_std_core_hnd__htag _x1991 = kk_std_core_hnd__htag_dup(kk_effects_dash_and_dash_types__tag_sample); /*std/core/hnd/htag<effects-and-types/.hnd-sample>*/
  i_1467 = kk_std_core_hnd__evv_index(_x1991, _ctx); /*std/core/hnd/ev-index*/
  kk_evv_t w = kk_evv_swap_create1(i_1467,kk_context()); /*std/core/hnd/evv<<effects-and-types/sample|830>>*/;
  bool y0 = kk_model_dash_resources_bernoulli(ratio, _ctx); /*bool*/;
  kk_unit_t __w_l700_c9 = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x1992 = kk_std_core_hnd_yield_cont(kk_trace__new_mlift1399_mh__step_fun1993(i_1467, _ctx), _ctx); /*3*/
    x0_1465 = kk_bool_unbox(_x1992); /*bool*/
  }
  else {
    x0_1465 = y0; /*bool*/
  }
  if (kk_yielding(kk_context())) {
    kk_box_t _x1994 = kk_std_core_hnd_yield_extend(kk_trace__new_mlift1399_mh__step_fun1995(b, model, new__trace, trace, p2, _ctx), _ctx); /*2*/
    return kk_trace__trace_unbox(_x1994, _ctx);
  }
  return kk_trace__mlift1398_mh__step(b, model, new__trace, p2, trace, x0_1465, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_trace__mlift1400_mh__step_fun2001__t {
  struct kk_function_s _base;
  kk_function_t model;
  kk_std_core__list old__trace;
  kk_trace__trace trace;
  kk_effects_dash_and_dash_types__exp p1;
};
static kk_box_t kk_trace__mlift1400_mh__step_fun2001(kk_function_t _fself, kk_box_t _b_1667, kk_context_t* _ctx);
static kk_function_t kk_trace__new_mlift1400_mh__step_fun2001(kk_function_t model, kk_std_core__list old__trace, kk_trace__trace trace, kk_effects_dash_and_dash_types__exp p1, kk_context_t* _ctx) {
  struct kk_trace__mlift1400_mh__step_fun2001__t* _self = kk_function_alloc_as(struct kk_trace__mlift1400_mh__step_fun2001__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_trace__mlift1400_mh__step_fun2001, kk_context());
  _self->model = model;
  _self->old__trace = old__trace;
  _self->trace = trace;
  _self->p1 = p1;
  return &_self->_base;
}

static kk_box_t kk_trace__mlift1400_mh__step_fun2001(kk_function_t _fself, kk_box_t _b_1667, kk_context_t* _ctx) {
  struct kk_trace__mlift1400_mh__step_fun2001__t* _self = kk_function_as(struct kk_trace__mlift1400_mh__step_fun2001__t*, _fself);
  kk_function_t model = _self->model; /* () -> <effects-and-types/sample,effects-and-types/score|830> 829 */
  kk_std_core__list old__trace = _self->old__trace; /* effects-and-types/trace_values */
  kk_trace__trace trace = _self->trace; /* trace/trace<829,<effects-and-types/sample,effects-and-types/score|830>> */
  kk_effects_dash_and_dash_types__exp p1 = _self->p1; /* effects-and-types/exp */
  kk_drop_match(_self, {kk_function_dup(model);kk_std_core__list_dup(old__trace);kk_trace__trace_dup(trace);kk_effects_dash_and_dash_types__exp_dup(p1);}, {}, _ctx)
  kk_trace__trace _x2002;
  kk_std_core_types__tuple2_ _x2003 = kk_std_core_types__tuple2__unbox(_b_1667, _ctx); /*(effects-and-types/trace_values, (effects-and-types/exp, 829))*/
  _x2002 = kk_trace__mlift1399_mh__step(model, old__trace, p1, trace, _x2003, _ctx); /*trace/trace<829,<effects-and-types/sample,effects-and-types/score|830>>*/
  return kk_trace__trace_box(_x2002, _ctx);
}

kk_trace__trace kk_trace__mlift1400_mh__step(kk_trace__trace trace, kk_std_core__list modified__trace, kk_context_t* _ctx) { /* forall<a,e> (trace : trace<a,<effects-and-types/sample,effects-and-types/score|e>>, modified_trace : effects-and-types/trace_values) -> <effects-and-types/sample|e> trace<a,<effects-and-types/sample,effects-and-types/score|e>> */ 
  struct kk_trace_Trace* _con1998 = kk_trace__as_Trace(trace);
  kk_function_t model = _con1998->m;
  kk_effects_dash_and_dash_types__exp p1 = _con1998->p;
  kk_std_core__list old__trace = _con1998->l;
  kk_function_dup(model);
  kk_std_core__list_dup(old__trace);
  kk_std_core_types__tuple2_ x_1470;
  kk_function_t _x1999 = kk_function_dup(model); /*() -> <effects-and-types/sample,effects-and-types/score|830> 829*/
  x_1470 = kk_trace_with__randomness(_x1999, modified__trace, _ctx); /*(effects-and-types/trace_values, (effects-and-types/exp, 829))*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__tuple2__drop(x_1470, _ctx);
    kk_box_t _x2000 = kk_std_core_hnd_yield_extend(kk_trace__new_mlift1400_mh__step_fun2001(model, old__trace, trace, p1, _ctx), _ctx); /*2*/
    return kk_trace__trace_unbox(_x2000, _ctx);
  }
  return kk_trace__mlift1399_mh__step(model, old__trace, p1, trace, x_1470, _ctx);
}


// lift anonymous function
struct kk_trace_mh__step_fun2007__t {
  struct kk_function_s _base;
  size_t i_1475;
};
static kk_box_t kk_trace_mh__step_fun2007(kk_function_t _fself, kk_function_t _b_1675, kk_box_t _b_1676, kk_context_t* _ctx);
static kk_function_t kk_trace_new_mh__step_fun2007(size_t i_1475, kk_context_t* _ctx) {
  struct kk_trace_mh__step_fun2007__t* _self = kk_function_alloc_as(struct kk_trace_mh__step_fun2007__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_trace_mh__step_fun2007, kk_context());
  _self->i_1475 = i_1475;
  return &_self->_base;
}

static kk_box_t kk_trace_mh__step_fun2007(kk_function_t _fself, kk_function_t _b_1675, kk_box_t _b_1676, kk_context_t* _ctx) {
  struct kk_trace_mh__step_fun2007__t* _self = kk_function_as(struct kk_trace_mh__step_fun2007__t*, _fself);
  size_t i_1475 = _self->i_1475; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_1475, _b_1675, _b_1676, _ctx);
}


// lift anonymous function
struct kk_trace_mh__step_fun2009__t {
  struct kk_function_s _base;
  kk_trace__trace trace;
};
static kk_box_t kk_trace_mh__step_fun2009(kk_function_t _fself, kk_box_t _b_1686, kk_context_t* _ctx);
static kk_function_t kk_trace_new_mh__step_fun2009(kk_trace__trace trace, kk_context_t* _ctx) {
  struct kk_trace_mh__step_fun2009__t* _self = kk_function_alloc_as(struct kk_trace_mh__step_fun2009__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_trace_mh__step_fun2009, kk_context());
  _self->trace = trace;
  return &_self->_base;
}

static kk_box_t kk_trace_mh__step_fun2009(kk_function_t _fself, kk_box_t _b_1686, kk_context_t* _ctx) {
  struct kk_trace_mh__step_fun2009__t* _self = kk_function_as(struct kk_trace_mh__step_fun2009__t*, _fself);
  kk_trace__trace trace = _self->trace; /* trace/trace<829,<effects-and-types/sample,effects-and-types/score|830>> */
  kk_drop_match(_self, {kk_trace__trace_dup(trace);}, {}, _ctx)
  kk_trace__trace _x2010;
  kk_std_core__list _x2011 = kk_std_core__list_unbox(_b_1686, _ctx); /*effects-and-types/trace_values*/
  _x2010 = kk_trace__mlift1400_mh__step(trace, _x2011, _ctx); /*trace/trace<829,<effects-and-types/sample,effects-and-types/score|830>>*/
  return kk_trace__trace_box(_x2010, _ctx);
}


// lift anonymous function
struct kk_trace_mh__step_fun2016__t {
  struct kk_function_s _base;
  kk_function_t model;
  kk_std_core__list old__trace;
  kk_trace__trace trace;
  kk_effects_dash_and_dash_types__exp p1;
};
static kk_box_t kk_trace_mh__step_fun2016(kk_function_t _fself, kk_box_t _b_1688, kk_context_t* _ctx);
static kk_function_t kk_trace_new_mh__step_fun2016(kk_function_t model, kk_std_core__list old__trace, kk_trace__trace trace, kk_effects_dash_and_dash_types__exp p1, kk_context_t* _ctx) {
  struct kk_trace_mh__step_fun2016__t* _self = kk_function_alloc_as(struct kk_trace_mh__step_fun2016__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_trace_mh__step_fun2016, kk_context());
  _self->model = model;
  _self->old__trace = old__trace;
  _self->trace = trace;
  _self->p1 = p1;
  return &_self->_base;
}

static kk_box_t kk_trace_mh__step_fun2016(kk_function_t _fself, kk_box_t _b_1688, kk_context_t* _ctx) {
  struct kk_trace_mh__step_fun2016__t* _self = kk_function_as(struct kk_trace_mh__step_fun2016__t*, _fself);
  kk_function_t model = _self->model; /* () -> <effects-and-types/sample,effects-and-types/score|830> 829 */
  kk_std_core__list old__trace = _self->old__trace; /* effects-and-types/trace_values */
  kk_trace__trace trace = _self->trace; /* trace/trace<829,<effects-and-types/sample,effects-and-types/score|830>> */
  kk_effects_dash_and_dash_types__exp p1 = _self->p1; /* effects-and-types/exp */
  kk_drop_match(_self, {kk_function_dup(model);kk_std_core__list_dup(old__trace);kk_trace__trace_dup(trace);kk_effects_dash_and_dash_types__exp_dup(p1);}, {}, _ctx)
  kk_trace__trace _x2017;
  kk_std_core_types__tuple2_ _x2018 = kk_std_core_types__tuple2__unbox(_b_1688, _ctx); /*(effects-and-types/trace_values, (effects-and-types/exp, 829))*/
  _x2017 = kk_trace__mlift1399_mh__step(model, old__trace, p1, trace, _x2018, _ctx); /*trace/trace<829,<effects-and-types/sample,effects-and-types/score|830>>*/
  return kk_trace__trace_box(_x2017, _ctx);
}


// lift anonymous function
struct kk_trace_mh__step_fun2025__t {
  struct kk_function_s _base;
};
static kk_box_t kk_trace_mh__step_fun2025(kk_function_t _fself, kk_box_t _b_1694, kk_context_t* _ctx);
static kk_function_t kk_trace_new_mh__step_fun2025(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_trace_mh__step_fun2025, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_trace_mh__step_fun2025(kk_function_t _fself, kk_box_t _b_1694, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x2026;
  kk_effects_dash_and_dash_types__exp _x2027 = kk_effects_dash_and_dash_types__exp_unbox(_b_1694, _ctx); /*effects-and-types/exp*/
  _x2026 = kk_exponents_exp__to__double(_x2027, _ctx); /*double*/
  return kk_double_box(_x2026, _ctx);
}


// lift anonymous function
struct kk_trace_mh__step_fun2033__t {
  struct kk_function_s _base;
};
static kk_box_t kk_trace_mh__step_fun2033(kk_function_t _fself, kk_box_t _b_1697, kk_context_t* _ctx);
static kk_function_t kk_trace_new_mh__step_fun2033(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_trace_mh__step_fun2033, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_trace_mh__step_fun2033(kk_function_t _fself, kk_box_t _b_1697, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x2034;
  kk_effects_dash_and_dash_types__exp _x2035 = kk_effects_dash_and_dash_types__exp_unbox(_b_1697, _ctx); /*effects-and-types/exp*/
  _x2034 = kk_exponents_exp__to__double(_x2035, _ctx); /*double*/
  return kk_double_box(_x2034, _ctx);
}


// lift anonymous function
struct kk_trace_mh__step_fun2041__t {
  struct kk_function_s _base;
  size_t i0_1488;
};
static kk_box_t kk_trace_mh__step_fun2041(kk_function_t _fself, kk_function_t _b_1707, kk_box_t _b_1708, kk_context_t* _ctx);
static kk_function_t kk_trace_new_mh__step_fun2041(size_t i0_1488, kk_context_t* _ctx) {
  struct kk_trace_mh__step_fun2041__t* _self = kk_function_alloc_as(struct kk_trace_mh__step_fun2041__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_trace_mh__step_fun2041, kk_context());
  _self->i0_1488 = i0_1488;
  return &_self->_base;
}

static kk_box_t kk_trace_mh__step_fun2041(kk_function_t _fself, kk_function_t _b_1707, kk_box_t _b_1708, kk_context_t* _ctx) {
  struct kk_trace_mh__step_fun2041__t* _self = kk_function_as(struct kk_trace_mh__step_fun2041__t*, _fself);
  size_t i0_1488 = _self->i0_1488; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i0_1488, _b_1707, _b_1708, _ctx);
}


// lift anonymous function
struct kk_trace_mh__step_fun2043__t {
  struct kk_function_s _base;
  kk_box_t b;
  kk_function_t model;
  kk_std_core__list new__trace;
  kk_trace__trace trace;
  kk_effects_dash_and_dash_types__exp p2;
};
static kk_box_t kk_trace_mh__step_fun2043(kk_function_t _fself, kk_box_t _b_1718, kk_context_t* _ctx);
static kk_function_t kk_trace_new_mh__step_fun2043(kk_box_t b, kk_function_t model, kk_std_core__list new__trace, kk_trace__trace trace, kk_effects_dash_and_dash_types__exp p2, kk_context_t* _ctx) {
  struct kk_trace_mh__step_fun2043__t* _self = kk_function_alloc_as(struct kk_trace_mh__step_fun2043__t, 5, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_trace_mh__step_fun2043, kk_context());
  _self->b = b;
  _self->model = model;
  _self->new__trace = new__trace;
  _self->trace = trace;
  _self->p2 = p2;
  return &_self->_base;
}

static kk_box_t kk_trace_mh__step_fun2043(kk_function_t _fself, kk_box_t _b_1718, kk_context_t* _ctx) {
  struct kk_trace_mh__step_fun2043__t* _self = kk_function_as(struct kk_trace_mh__step_fun2043__t*, _fself);
  kk_box_t b = _self->b; /* 829 */
  kk_function_t model = _self->model; /* () -> <effects-and-types/sample,effects-and-types/score|830> 829 */
  kk_std_core__list new__trace = _self->new__trace; /* effects-and-types/trace_values */
  kk_trace__trace trace = _self->trace; /* trace/trace<829,<effects-and-types/sample,effects-and-types/score|830>> */
  kk_effects_dash_and_dash_types__exp p2 = _self->p2; /* effects-and-types/exp */
  kk_drop_match(_self, {kk_box_dup(b);kk_function_dup(model);kk_std_core__list_dup(new__trace);kk_trace__trace_dup(trace);kk_effects_dash_and_dash_types__exp_dup(p2);}, {}, _ctx)
  kk_trace__trace _x2044;
  bool _x2045 = kk_bool_unbox(_b_1718); /*bool*/
  _x2044 = kk_trace__mlift1398_mh__step(b, model, new__trace, p2, trace, _x2045, _ctx); /*trace/trace<829,<effects-and-types/sample,effects-and-types/score|830>>*/
  return kk_trace__trace_box(_x2044, _ctx);
}

kk_trace__trace kk_trace_mh__step(kk_trace__trace trace, kk_context_t* _ctx) { /* forall<a,e> (trace : trace<a,<effects-and-types/sample,effects-and-types/score|e>>) -> <effects-and-types/sample|e> trace<a,<effects-and-types/sample,effects-and-types/score|e>> */ 
  kk_std_core__list x_1472;
  size_t i_1475;
  kk_std_core_hnd__htag _x2004 = kk_std_core_hnd__htag_dup(kk_effects_dash_and_dash_types__tag_sample); /*std/core/hnd/htag<effects-and-types/.hnd-sample>*/
  i_1475 = kk_std_core_hnd__evv_index(_x2004, _ctx); /*std/core/hnd/ev-index*/
  kk_evv_t w = kk_evv_swap_create1(i_1475,kk_context()); /*std/core/hnd/evv<<effects-and-types/sample|830>>*/;
  kk_std_core__list y;
  kk_trace__trace _x2005 = kk_trace__trace_dup(trace); /*trace/trace<829,<effects-and-types/sample,effects-and-types/score|830>>*/
  y = kk_trace_perturb__trace(_x2005, _ctx); /*effects-and-types/trace_values*/
  kk_unit_t __w_l700_c9 = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(y, _ctx);
    kk_box_t _x2006 = kk_std_core_hnd_yield_cont(kk_trace_new_mh__step_fun2007(i_1475, _ctx), _ctx); /*3*/
    x_1472 = kk_std_core__list_unbox(_x2006, _ctx); /*effects-and-types/trace_values*/
  }
  else {
    x_1472 = y; /*effects-and-types/trace_values*/
  }
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_1472, _ctx);
    kk_box_t _x2008 = kk_std_core_hnd_yield_extend(kk_trace_new_mh__step_fun2009(trace, _ctx), _ctx); /*2*/
    return kk_trace__trace_unbox(_x2008, _ctx);
  }
  struct kk_trace_Trace* _con2012 = kk_trace__as_Trace(trace);
  kk_function_t model = _con2012->m;
  kk_effects_dash_and_dash_types__exp p1 = _con2012->p;
  kk_std_core__list old__trace = _con2012->l;
  kk_function_dup(model);
  kk_std_core__list_dup(old__trace);
  kk_reuse_t _ru_1802;
  kk_trace__trace _x2013 = kk_trace__trace_dup(trace); /*trace/trace<829,<effects-and-types/sample,effects-and-types/score|830>>*/
  _ru_1802 = kk_trace__trace_dropn_reuse(_x2013, ((int32_t)3), _ctx); /*reuse*/
  kk_std_core_types__tuple2_ x1_1479;
  kk_function_t _x2014 = kk_function_dup(model); /*() -> <effects-and-types/sample,effects-and-types/score|830> 829*/
  x1_1479 = kk_trace_with__randomness(_x2014, x_1472, _ctx); /*(effects-and-types/trace_values, (effects-and-types/exp, 829))*/
  if (kk_yielding(kk_context())) {
    kk_reuse_drop(_ru_1802, _ctx);
    kk_std_core_types__tuple2__drop(x1_1479, _ctx);
    kk_box_t _x2015 = kk_std_core_hnd_yield_extend(kk_trace_new_mh__step_fun2016(model, old__trace, trace, p1, _ctx), _ctx); /*2*/
    return kk_trace__trace_unbox(_x2015, _ctx);
  }
  kk_box_t _box_x1689 = x1_1479.fst;
  kk_box_t _box_x1690 = x1_1479.snd;
  kk_std_core__list new__trace = kk_std_core__list_unbox(_box_x1689, NULL);
  kk_std_core_types__tuple2_ _pat30 = kk_std_core_types__tuple2__unbox(_box_x1690, NULL);
  kk_box_t _box_x1691 = _pat30.fst;
  kk_box_t b = _pat30.snd;
  kk_effects_dash_and_dash_types__exp p2 = kk_effects_dash_and_dash_types__exp_unbox(_box_x1691, NULL);
  kk_box_dup(b);
  kk_std_core__list_dup(new__trace);
  kk_std_core_types__tuple2__drop(x1_1479, _ctx);
  double ratio;
  double y0_1484;
  double _x2022;
  double _x2023;
  kk_box_t _x2024 = kk_std_core_hnd__open_none1(kk_trace_new_mh__step_fun2025(_ctx), kk_effects_dash_and_dash_types__exp_box(p2, _ctx), _ctx); /*2*/
  _x2023 = kk_double_unbox(_x2024, _ctx); /*double*/
  double _x2028;
  kk_integer_t _x2029 = kk_std_core_length_1(old__trace, _ctx); /*int*/
  _x2028 = kk_integer_as_double(_x2029,kk_context()); /*double*/
  _x2022 = (_x2023 * _x2028); /*double*/
  double _x2030;
  double _x2031;
  kk_box_t _x2032 = kk_std_core_hnd__open_none1(kk_trace_new_mh__step_fun2033(_ctx), kk_effects_dash_and_dash_types__exp_box(p1, _ctx), _ctx); /*2*/
  _x2031 = kk_double_unbox(_x2032, _ctx); /*double*/
  double _x2036;
  kk_integer_t _x2037;
  kk_std_core__list _x2038 = kk_std_core__list_dup(new__trace); /*effects-and-types/trace_values*/
  _x2037 = kk_std_core_length_1(_x2038, _ctx); /*int*/
  _x2036 = kk_integer_as_double(_x2037,kk_context()); /*double*/
  _x2030 = (_x2031 * _x2036); /*double*/
  y0_1484 = (_x2022 / _x2030); /*double*/
  bool _match_1819 = (0x1p0 <= y0_1484); /*bool*/;
  if (_match_1819) {
    ratio = 0x1p0; /*double*/
  }
  else {
    ratio = y0_1484; /*double*/
  }
  bool x3_1485;
  size_t i0_1488;
  kk_std_core_hnd__htag _x2039 = kk_std_core_hnd__htag_dup(kk_effects_dash_and_dash_types__tag_sample); /*std/core/hnd/htag<effects-and-types/.hnd-sample>*/
  i0_1488 = kk_std_core_hnd__evv_index(_x2039, _ctx); /*std/core/hnd/ev-index*/
  kk_evv_t w0 = kk_evv_swap_create1(i0_1488,kk_context()); /*std/core/hnd/evv<<effects-and-types/sample|830>>*/;
  bool y1 = kk_model_dash_resources_bernoulli(ratio, _ctx); /*bool*/;
  kk_unit_t __w_l700_c90 = kk_Unit;
  kk_evv_set(w0,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x2040 = kk_std_core_hnd_yield_cont(kk_trace_new_mh__step_fun2041(i0_1488, _ctx), _ctx); /*3*/
    x3_1485 = kk_bool_unbox(_x2040); /*bool*/
  }
  else {
    x3_1485 = y1; /*bool*/
  }
  if (kk_yielding(kk_context())) {
    kk_reuse_drop(_ru_1802, _ctx);
    kk_box_t _x2042 = kk_std_core_hnd_yield_extend(kk_trace_new_mh__step_fun2043(b, model, new__trace, trace, p2, _ctx), _ctx); /*2*/
    return kk_trace__trace_unbox(_x2042, _ctx);
  }
  if (x3_1485) {
    kk_trace__trace_dropn(trace, ((int32_t)3), _ctx);
    return kk_trace__new_Trace(_ru_1802, model, p2, new__trace, b, _ctx);
  }
  kk_reuse_drop(_ru_1802, _ctx);
  kk_box_drop(b, _ctx);
  kk_function_drop(model, _ctx);
  kk_std_core__list_drop(new__trace, _ctx);
  return trace;
}
 
// monadic lift

kk_std_core_types__tuple2_ kk_trace__mlift1401_model__stepper__recursive(kk_integer_t burnin, kk_std_core__list posterior, kk_integer_t steps, kk_trace__trace new__trace, kk_context_t* _ctx) { /* forall<a,e> (burnin : int, posterior : list<(list<double>, a)>, steps : int, new_trace : trace<a,<effects-and-types/sample,effects-and-types/score,div|e>>) -> <effects-and-types/sample,div|e> (list<(list<double>, a)>, trace<a,<effects-and-types/sample,effects-and-types/score,div|e>>) */ 
  bool _match_1814;
  kk_integer_t _x2046 = kk_integer_dup(burnin); /*int*/
  _match_1814 = kk_integer_gt(_x2046,(kk_integer_from_small(0)),kk_context()); /*bool*/
  if (_match_1814) {
    kk_integer_t _x2047 = kk_integer_sub(steps,(kk_integer_from_small(1)),kk_context()); /*int*/
    kk_integer_t _x2048 = kk_integer_sub(burnin,(kk_integer_from_small(1)),kk_context()); /*int*/
    return kk_trace_model__stepper__recursive(_x2047, new__trace, posterior, _x2048, _ctx);
  }
  kk_integer_t _x2049 = kk_integer_sub(steps,(kk_integer_from_small(1)),kk_context()); /*int*/
  kk_trace__trace _x2050 = kk_trace__trace_dup(new__trace); /*trace/trace<1027,<effects-and-types/sample,effects-and-types/score,div|1028>>*/
  kk_std_core__list _x2051;
  kk_std_core__list ys_1493;
  kk_std_core_types__tuple2_ _b_1729_1727;
  kk_std_core__list _b_1731_1725;
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*std/core/hnd/evv<(<>)>*/;
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  struct kk_trace_Trace* _con2052 = kk_trace__as_Trace(new__trace);
  kk_effects_dash_and_dash_types__exp _pat10 = _con2052->p;
  kk_std_core__list _x = _con2052->l;
  kk_std_core__list_dup(_x);
  _b_1731_1725 = _x; /*effects-and-types/trace_values*/
  kk_box_t _b_1732_1726;
  kk_evv_t w0 = kk_evv_swap_create0(kk_context()); /*std/core/hnd/evv<(<>)>*/;
  kk_unit_t keep0 = kk_Unit;
  kk_evv_set(w0,kk_context());
  struct kk_trace_Trace* _con2053 = kk_trace__as_Trace(new__trace);
  kk_function_t _pat00 = _con2053->m;
  kk_effects_dash_and_dash_types__exp _pat11 = _con2053->p;
  kk_std_core__list _pat30 = _con2053->l;
  kk_box_t _x0 = _con2053->a;
  if (kk_trace__trace_is_unique(new__trace)) {
    kk_std_core__list_drop(_pat30, _ctx);
    kk_function_drop(_pat00, _ctx);
    kk_trace__trace_free(new__trace);
  }
  else {
    kk_box_dup(_x0);
    kk_trace__trace_decref(new__trace, _ctx);
  }
  _b_1732_1726 = _x0; /*1027*/
  _b_1729_1727 = kk_std_core_types__new_dash__lp__comma__rp_(kk_std_core__list_box(_b_1731_1725, _ctx), _b_1732_1726, _ctx); /*(effects-and-types/trace_values, 1027)*/
  ys_1493 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core_types__tuple2__box(_b_1729_1727, _ctx), kk_std_core__new_Nil(_ctx), _ctx); /*list<(list<double>, 1027)>*/
  _x2051 = kk_std_core_append(posterior, ys_1493, _ctx); /*list<1>*/
  return kk_trace_model__stepper__recursive(_x2049, _x2050, _x2051, burnin, _ctx);
}


// lift anonymous function
struct kk_trace_model__stepper__recursive_fun2056__t {
  struct kk_function_s _base;
  kk_integer_t burnin0;
  kk_std_core__list posterior0;
  kk_integer_t steps0;
};
static kk_box_t kk_trace_model__stepper__recursive_fun2056(kk_function_t _fself, kk_box_t _b_1736, kk_context_t* _ctx);
static kk_function_t kk_trace_new_model__stepper__recursive_fun2056(kk_integer_t burnin0, kk_std_core__list posterior0, kk_integer_t steps0, kk_context_t* _ctx) {
  struct kk_trace_model__stepper__recursive_fun2056__t* _self = kk_function_alloc_as(struct kk_trace_model__stepper__recursive_fun2056__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_trace_model__stepper__recursive_fun2056, kk_context());
  _self->burnin0 = burnin0;
  _self->posterior0 = posterior0;
  _self->steps0 = steps0;
  return &_self->_base;
}

static kk_box_t kk_trace_model__stepper__recursive_fun2056(kk_function_t _fself, kk_box_t _b_1736, kk_context_t* _ctx) {
  struct kk_trace_model__stepper__recursive_fun2056__t* _self = kk_function_as(struct kk_trace_model__stepper__recursive_fun2056__t*, _fself);
  kk_integer_t burnin0 = _self->burnin0; /* int */
  kk_std_core__list posterior0 = _self->posterior0; /* list<(list<double>, 1027)> */
  kk_integer_t steps0 = _self->steps0; /* int */
  kk_drop_match(_self, {kk_integer_dup(burnin0);kk_std_core__list_dup(posterior0);kk_integer_dup(steps0);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x2057;
  kk_trace__trace _x2058 = kk_trace__trace_unbox(_b_1736, _ctx); /*trace/trace<1027,<effects-and-types/sample,effects-and-types/score,div|1028>>*/
  _x2057 = kk_trace__mlift1401_model__stepper__recursive(burnin0, posterior0, steps0, _x2058, _ctx); /*(list<(list<double>, 1027)>, trace/trace<1027,<effects-and-types/sample,effects-and-types/score,div|1028>>)*/
  return kk_std_core_types__tuple2__box(_x2057, _ctx);
}

kk_std_core_types__tuple2_ kk_trace_model__stepper__recursive(kk_integer_t steps0, kk_trace__trace trace, kk_std_core__list posterior0, kk_integer_t burnin0, kk_context_t* _ctx) { /* forall<a,e> (steps : int, trace : trace<a,<effects-and-types/sample,effects-and-types/score,div|e>>, posterior : list<(list<double>, a)>, burnin : int) -> <effects-and-types/sample,div|e> (list<(list<double>, a)>, trace<a,<effects-and-types/sample,effects-and-types/score,div|e>>) */ 
  kk__tailcall: ;
  bool _match_1811;
  kk_integer_t _x2054 = kk_integer_dup(steps0); /*int*/
  _match_1811 = kk_integer_lt(_x2054,(kk_integer_from_small(1)),kk_context()); /*bool*/
  if (_match_1811) {
    kk_integer_drop(burnin0, _ctx);
    kk_integer_drop(steps0, _ctx);
    return kk_std_core_types__new_dash__lp__comma__rp_(kk_std_core__list_box(posterior0, _ctx), kk_trace__trace_box(trace, _ctx), _ctx);
  }
  kk_trace__trace x_1498 = kk_trace_mh__step(trace, _ctx); /*trace/trace<1027,<effects-and-types/sample,effects-and-types/score,div|1028>>*/;
  if (kk_yielding(kk_context())) {
    kk_trace__trace_dropn(x_1498, ((int32_t)3), _ctx);
    kk_box_t _x2055 = kk_std_core_hnd_yield_extend(kk_trace_new_model__stepper__recursive_fun2056(burnin0, posterior0, steps0, _ctx), _ctx); /*2*/
    return kk_std_core_types__tuple2__unbox(_x2055, _ctx);
  }
  bool _match_1813;
  kk_integer_t _x2059 = kk_integer_dup(burnin0); /*int*/
  _match_1813 = kk_integer_gt(_x2059,(kk_integer_from_small(0)),kk_context()); /*bool*/
  if (_match_1813) {
    { // tailcall
      kk_integer_t _x2060 = kk_integer_sub(steps0,(kk_integer_from_small(1)),kk_context()); /*int*/
      kk_integer_t _x2061 = kk_integer_sub(burnin0,(kk_integer_from_small(1)),kk_context()); /*int*/
      steps0 = _x2060;
      trace = x_1498;
      burnin0 = _x2061;
      goto kk__tailcall;
    }
  }
  { // tailcall
    kk_integer_t _x2062 = kk_integer_sub(steps0,(kk_integer_from_small(1)),kk_context()); /*int*/
    kk_trace__trace _x2063 = kk_trace__trace_dup(x_1498); /*trace/trace<1027,<effects-and-types/sample,effects-and-types/score,div|1028>>*/
    kk_std_core__list _x2064;
    kk_std_core__list ys_1503;
    kk_std_core_types__tuple2_ _b_1741_1739;
    kk_std_core__list _b_1743_1737;
    kk_evv_t w1 = kk_evv_swap_create0(kk_context()); /*std/core/hnd/evv<(<>)>*/;
    kk_unit_t keep1 = kk_Unit;
    kk_evv_set(w1,kk_context());
    struct kk_trace_Trace* _con2065 = kk_trace__as_Trace(x_1498);
    kk_effects_dash_and_dash_types__exp _pat110 = _con2065->p;
    kk_std_core__list _x1 = _con2065->l;
    kk_std_core__list_dup(_x1);
    _b_1743_1737 = _x1; /*effects-and-types/trace_values*/
    kk_box_t _b_1744_1738;
    kk_evv_t w00 = kk_evv_swap_create0(kk_context()); /*std/core/hnd/evv<(<>)>*/;
    kk_unit_t keep00 = kk_Unit;
    kk_evv_set(w00,kk_context());
    struct kk_trace_Trace* _con2066 = kk_trace__as_Trace(x_1498);
    kk_function_t _pat02 = _con2066->m;
    kk_effects_dash_and_dash_types__exp _pat120 = _con2066->p;
    kk_std_core__list _pat310 = _con2066->l;
    kk_box_t _x00 = _con2066->a;
    if (kk_trace__trace_is_unique(x_1498)) {
      kk_std_core__list_drop(_pat310, _ctx);
      kk_function_drop(_pat02, _ctx);
      kk_trace__trace_free(x_1498);
    }
    else {
      kk_box_dup(_x00);
      kk_trace__trace_decref(x_1498, _ctx);
    }
    _b_1744_1738 = _x00; /*1027*/
    _b_1741_1739 = kk_std_core_types__new_dash__lp__comma__rp_(kk_std_core__list_box(_b_1743_1737, _ctx), _b_1744_1738, _ctx); /*(effects-and-types/trace_values, 1027)*/
    ys_1503 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core_types__tuple2__box(_b_1741_1739, _ctx), kk_std_core__new_Nil(_ctx), _ctx); /*list<(list<double>, 1027)>*/
    _x2064 = kk_std_core_append(posterior0, ys_1503, _ctx); /*list<1>*/
    steps0 = _x2062;
    trace = _x2063;
    posterior0 = _x2064;
    goto kk__tailcall;
  }
}

kk_std_core__list kk_trace_splitter(kk_std_core__list lst__as, kk_std_core__list build, kk_context_t* _ctx) { /* forall<a> (lst_as : list<a>, build : list<list<a>>) -> div list<list<a>> */ 
  kk__tailcall: ;
  kk_std_core_types__tuple2_ split__v;
  kk_std_core__list _b_1751_1749;
  kk_std_core__list _x2067 = kk_std_core__list_dup(lst__as); /*list<1309>*/
  _b_1751_1749 = kk_std_core_take(_x2067, kk_integer_from_int(4000, _ctx), _ctx); /*list<1309>*/
  kk_std_core__list _b_1752_1750 = kk_std_core_drop(lst__as, kk_integer_from_int(4000, _ctx), _ctx); /*list<1309>*/;
  split__v = kk_std_core_types__new_dash__lp__comma__rp_(kk_std_core__list_box(_b_1751_1749, _ctx), kk_std_core__list_box(_b_1752_1750, _ctx), _ctx); /*(list<1309>, list<1309>)*/
  kk_std_core__list _match_1810;
  kk_box_t _box_x1753 = split__v.fst;
  kk_box_t _box_x1754 = split__v.snd;
  kk_std_core__list _x = kk_std_core__list_unbox(_box_x1753, NULL);
  kk_std_core__list_dup(_x);
  _match_1810 = _x; /*list<1309>*/
  if (kk_std_core__is_Nil(_match_1810)) {
    kk_std_core_types__tuple2__drop(split__v, _ctx);
    return build;
  }
  struct kk_std_core_Cons* _con2070 = kk_std_core__as_Cons(_match_1810);
  kk_reuse_t _ru_1807 = kk_reuse_null; /*reuse*/;
  kk_reuse_t _x2071 = kk_std_core__list_dropn_reuse(_match_1810, ((int32_t)2), _ctx); /*reuse*/
  _ru_1807 = _x2071;
  { // tailcall
    kk_std_core__list _x2072;
    kk_box_t _box_x1755 = split__v.fst;
    kk_box_t _box_x1756 = split__v.snd;
    kk_std_core__list _x0 = kk_std_core__list_unbox(_box_x1756, NULL);
    kk_std_core__list_dup(_x0);
    _x2072 = _x0; /*list<1309>*/
    kk_std_core__list _x2075;
    kk_std_core__list ys_1513;
    kk_box_t _x2076;
    kk_std_core__list _x2077;
    kk_box_t _box_x1757 = split__v.fst;
    kk_box_t _box_x1758 = split__v.snd;
    kk_std_core__list _x1 = kk_std_core__list_unbox(_box_x1757, NULL);
    kk_std_core__list_dup(_x1);
    kk_std_core_types__tuple2__drop(split__v, _ctx);
    _x2077 = _x1; /*list<1309>*/
    _x2076 = kk_std_core__list_box(_x2077, _ctx); /*9*/
    ys_1513 = kk_std_core__new_Cons(_ru_1807, _x2076, kk_std_core__new_Nil(_ctx), _ctx); /*list<list<1309>>*/
    _x2075 = kk_std_core_append(build, ys_1513, _ctx); /*list<1>*/
    lst__as = _x2072;
    build = _x2075;
    goto kk__tailcall;
  }
}
 
// monadic lift

kk_std_core_types__tuple2_ kk_trace__mlift1402_tmcmc(kk_integer_t burnin, kk_function_t model, kk_integer_t steps, kk_std_core_types__tuple2_ model__results, kk_context_t* _ctx) { /* forall<a,e> (burnin : int, model : () -> <effects-and-types/sample,effects-and-types/score,div|e> a, steps : int, model_results : (effects-and-types/exp, (list<double>, a))) -> <div,effects-and-types/sample|e> (list<(list<double>, a)>, trace<a,<effects-and-types/sample,effects-and-types/score,div|e>>) */ 
  kk_box_t _box_x1763 = model__results.fst;
  kk_box_t _box_x1764 = model__results.snd;
  kk_effects_dash_and_dash_types__exp p0 = kk_effects_dash_and_dash_types__exp_unbox(_box_x1763, NULL);
  kk_std_core_types__tuple2_ _pat1 = kk_std_core_types__tuple2__unbox(_box_x1764, NULL);
  kk_box_t _box_x1765 = _pat1.fst;
  kk_box_t a0 = _pat1.snd;
  kk_std_core__list d = kk_std_core__list_unbox(_box_x1765, NULL);
  kk_box_dup(a0);
  kk_std_core__list_dup(d);
  kk_std_core_types__tuple2__drop(model__results, _ctx);
  kk_trace__trace _x2083 = kk_trace__new_Trace(kk_reuse_null, model, p0, d, a0, _ctx); /*trace/trace<5,6>*/
  return kk_trace_model__stepper__recursive(steps, _x2083, kk_std_core__new_Nil(_ctx), burnin, _ctx);
}


// lift anonymous function
struct kk_trace_tmcmc_fun2085__t {
  struct kk_function_s _base;
  kk_function_t model;
};
static kk_box_t kk_trace_tmcmc_fun2085(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_trace_new_tmcmc_fun2085(kk_function_t model, kk_context_t* _ctx) {
  struct kk_trace_tmcmc_fun2085__t* _self = kk_function_alloc_as(struct kk_trace_tmcmc_fun2085__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_trace_tmcmc_fun2085, kk_context());
  _self->model = model;
  return &_self->_base;
}



// lift anonymous function
struct kk_trace_tmcmc_fun2087__t {
  struct kk_function_s _base;
  kk_function_t model;
};
static kk_box_t kk_trace_tmcmc_fun2087(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_trace_new_tmcmc_fun2087(kk_function_t model, kk_context_t* _ctx) {
  struct kk_trace_tmcmc_fun2087__t* _self = kk_function_alloc_as(struct kk_trace_tmcmc_fun2087__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_trace_tmcmc_fun2087, kk_context());
  _self->model = model;
  return &_self->_base;
}



// lift anonymous function
struct kk_trace_tmcmc_fun2089__t {
  struct kk_function_s _base;
  kk_function_t model;
};
static kk_box_t kk_trace_tmcmc_fun2089(kk_function_t _fself, kk_box_t _b_1767, kk_context_t* _ctx);
static kk_function_t kk_trace_new_tmcmc_fun2089(kk_function_t model, kk_context_t* _ctx) {
  struct kk_trace_tmcmc_fun2089__t* _self = kk_function_alloc_as(struct kk_trace_tmcmc_fun2089__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_trace_tmcmc_fun2089, kk_context());
  _self->model = model;
  return &_self->_base;
}

static kk_box_t kk_trace_tmcmc_fun2089(kk_function_t _fself, kk_box_t _b_1767, kk_context_t* _ctx) {
  struct kk_trace_tmcmc_fun2089__t* _self = kk_function_as(struct kk_trace_tmcmc_fun2089__t*, _fself);
  kk_function_t model = _self->model; /* () -> <effects-and-types/sample,effects-and-types/score,div|1383> 1382 */
  kk_drop_match(_self, {kk_function_dup(model);}, {}, _ctx)
  size_t _x2090 = kk_size_unbox(_b_1767, _ctx); /*std/core/hnd/ev-index*/
  return kk_handlers__mlift1713_replay(model, _x2090, _ctx);
}
static kk_box_t kk_trace_tmcmc_fun2087(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_trace_tmcmc_fun2087__t* _self = kk_function_as(struct kk_trace_tmcmc_fun2087__t*, _fself);
  kk_function_t model = _self->model; /* () -> <effects-and-types/sample,effects-and-types/score,div|1383> 1382 */
  kk_drop_match(_self, {kk_function_dup(model);}, {}, _ctx)
  size_t x_1791;
  kk_std_core_hnd__htag _x2088 = kk_std_core_hnd__htag_dup(kk_effects_dash_and_dash_types__tag_sample); /*std/core/hnd/htag<effects-and-types/.hnd-sample>*/
  x_1791 = kk_std_core_hnd__evv_index(_x2088, _ctx); /*std/core/hnd/ev-index*/
  if (kk_yielding(kk_context())) {
    return kk_std_core_hnd_yield_extend(kk_trace_new_tmcmc_fun2089(model, _ctx), _ctx);
  }
  return kk_handlers__mlift1713_replay(model, x_1791, _ctx);
}
static kk_box_t kk_trace_tmcmc_fun2085(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_trace_tmcmc_fun2085__t* _self = kk_function_as(struct kk_trace_tmcmc_fun2085__t*, _fself);
  kk_function_t model = _self->model; /* () -> <effects-and-types/sample,effects-and-types/score,div|1383> 1382 */
  kk_drop_match(_self, {kk_function_dup(model);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x2086 = kk_handlers_replayx(kk_std_core__new_Nil(_ctx), kk_trace_new_tmcmc_fun2087(model, _ctx), _ctx); /*(list<double>, 0)*/
  return kk_std_core_types__tuple2__box(_x2086, _ctx);
}


// lift anonymous function
struct kk_trace_tmcmc_fun2092__t {
  struct kk_function_s _base;
  kk_integer_t burnin;
  kk_function_t model;
  kk_integer_t steps;
};
static kk_box_t kk_trace_tmcmc_fun2092(kk_function_t _fself, kk_box_t _b_1775, kk_context_t* _ctx);
static kk_function_t kk_trace_new_tmcmc_fun2092(kk_integer_t burnin, kk_function_t model, kk_integer_t steps, kk_context_t* _ctx) {
  struct kk_trace_tmcmc_fun2092__t* _self = kk_function_alloc_as(struct kk_trace_tmcmc_fun2092__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_trace_tmcmc_fun2092, kk_context());
  _self->burnin = burnin;
  _self->model = model;
  _self->steps = steps;
  return &_self->_base;
}

static kk_box_t kk_trace_tmcmc_fun2092(kk_function_t _fself, kk_box_t _b_1775, kk_context_t* _ctx) {
  struct kk_trace_tmcmc_fun2092__t* _self = kk_function_as(struct kk_trace_tmcmc_fun2092__t*, _fself);
  kk_integer_t burnin = _self->burnin; /* int */
  kk_function_t model = _self->model; /* () -> <effects-and-types/sample,effects-and-types/score,div|1383> 1382 */
  kk_integer_t steps = _self->steps; /* int */
  kk_drop_match(_self, {kk_integer_dup(burnin);kk_function_dup(model);kk_integer_dup(steps);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x2093;
  kk_std_core_types__tuple2_ _x2094 = kk_std_core_types__tuple2__unbox(_b_1775, _ctx); /*(effects-and-types/exp, (list<double>, 1382))*/
  _x2093 = kk_trace__mlift1402_tmcmc(burnin, model, steps, _x2094, _ctx); /*(list<(list<double>, 1382)>, trace/trace<1382,<effects-and-types/sample,effects-and-types/score,div|1383>>)*/
  return kk_std_core_types__tuple2__box(_x2093, _ctx);
}

kk_std_core_types__tuple2_ kk_trace_tmcmc(kk_function_t model, kk_integer_t steps, kk_effects_dash_and_dash_types__exp init__weight, kk_integer_t burnin, kk_context_t* _ctx) { /* forall<a,e> (model : () -> <effects-and-types/sample,effects-and-types/score,div|e> a, steps : int, init_weight : effects-and-types/exp, burnin : int) -> <effects-and-types/sample,div|e> (list<(list<double>, a)>, trace<a,<effects-and-types/sample,effects-and-types/score,div|e>>) */ 
  kk_std_core_types__tuple2_ x_1515;
  kk_function_t _x2084;
  kk_function_dup(model);
  _x2084 = kk_trace_new_tmcmc_fun2085(model, _ctx); /*() -> <effects-and-types/score|1> 0*/
  x_1515 = kk_handlers_weighted(init__weight, _x2084, _ctx); /*(effects-and-types/exp, (list<double>, 1382))*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__tuple2__drop(x_1515, _ctx);
    kk_box_t _x2091 = kk_std_core_hnd_yield_extend(kk_trace_new_tmcmc_fun2092(burnin, model, steps, _ctx), _ctx); /*2*/
    return kk_std_core_types__tuple2__unbox(_x2091, _ctx);
  }
  kk_box_t _box_x1776 = x_1515.fst;
  kk_box_t _box_x1777 = x_1515.snd;
  kk_effects_dash_and_dash_types__exp p0 = kk_effects_dash_and_dash_types__exp_unbox(_box_x1776, NULL);
  kk_std_core_types__tuple2_ _pat10 = kk_std_core_types__tuple2__unbox(_box_x1777, NULL);
  kk_box_t _box_x1778 = _pat10.fst;
  kk_box_t a0 = _pat10.snd;
  kk_std_core__list d = kk_std_core__list_unbox(_box_x1778, NULL);
  kk_box_dup(a0);
  kk_std_core__list_dup(d);
  kk_std_core_types__tuple2__drop(x_1515, _ctx);
  kk_trace__trace _x2098 = kk_trace__new_Trace(kk_reuse_null, model, p0, d, a0, _ctx); /*trace/trace<5,6>*/
  return kk_trace_model__stepper__recursive(steps, _x2098, kk_std_core__new_Nil(_ctx), burnin, _ctx);
}

// initialization
void kk_trace__init(kk_context_t* _ctx){
  static bool _initialized = false;
  if (_initialized) return;
  _initialized = true;
  kk_std_core_types__init(_ctx);
  kk_std_core_hnd__init(_ctx);
  kk_std_core__init(_ctx);
  kk_effects_dash_and_dash_types__init(_ctx);
  kk_exponents__init(_ctx);
  kk_handlers__init(_ctx);
  kk_model_dash_resources__init(_ctx);
}
