// Koka generated module: "trace", koka version: 2.1.3
#include "trace.h"
 
// monadic lift

kk_trace__trace kk_trace__mlift1075_op(kk_function_t _c_1, kk_effects_dash_and_dash_types__exp _c_2, kk_std_core__list _c_3, kk_box_t _c_4, kk_context_t* _ctx) { /* forall<a,e> (() -> e a, effects-and-types/exp, effects-and-types/trace_values, a) -> trace<a,e> */ 
  return kk_trace__new_Trace(kk_reuse_null, _c_1, _c_2, _c_3, _c_4, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_trace__mlift1076_op_fun1504__t {
  struct kk_function_s _base;
  kk_function_t _c_1;
  kk_std_core__list _c_3;
  kk_effects_dash_and_dash_types__exp _c_2;
};
static kk_box_t kk_trace__mlift1076_op_fun1504(kk_function_t _fself, kk_box_t _b_1210, kk_context_t* _ctx);
static kk_function_t kk_trace__new_mlift1076_op_fun1504(kk_function_t _c_1, kk_std_core__list _c_3, kk_effects_dash_and_dash_types__exp _c_2, kk_context_t* _ctx) {
  struct kk_trace__mlift1076_op_fun1504__t* _self = kk_function_alloc_as(struct kk_trace__mlift1076_op_fun1504__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_trace__mlift1076_op_fun1504, kk_context());
  _self->_c_1 = _c_1;
  _self->_c_3 = _c_3;
  _self->_c_2 = _c_2;
  return &_self->_base;
}

static kk_box_t kk_trace__mlift1076_op_fun1504(kk_function_t _fself, kk_box_t _b_1210, kk_context_t* _ctx) {
  struct kk_trace__mlift1076_op_fun1504__t* _self = kk_function_as(struct kk_trace__mlift1076_op_fun1504__t*, _fself);
  kk_function_t _c_1 = _self->_c_1; /* () -> 220 219 */
  kk_std_core__list _c_3 = _self->_c_3; /* effects-and-types/trace_values */
  kk_effects_dash_and_dash_types__exp _c_2 = _self->_c_2; /* effects-and-types/exp */
  kk_drop_match(_self, {kk_function_dup(_c_1);kk_std_core__list_dup(_c_3);kk_effects_dash_and_dash_types__exp_dup(_c_2);}, {}, _ctx)
  kk_trace__trace _x1505 = kk_trace__mlift1075_op(_c_1, _c_2, _c_3, _b_1210, _ctx); /*trace/trace<219,220>*/
  return kk_trace__trace_box(_x1505, _ctx);
}

kk_trace__trace kk_trace__mlift1076_op(kk_function_t _c_1, kk_effects_dash_and_dash_types__exp _c_2, kk_trace__trace _this, kk_std_core_types__optional a0, kk_std_core__list _c_3, kk_context_t* _ctx) { /* forall<a,e> (() -> e a, effects-and-types/exp, trace<a,e>, a : optional<a>, effects-and-types/trace_values) -> trace<a,e> */ 
  if (kk_yielding(kk_context())) {
    kk_trace__trace_dropn(_this, ((int32_t)3), _ctx);
    kk_std_core_types__optional_drop(a0, _ctx);
    kk_box_t _x1503 = kk_std_core_hnd_yield_extend(kk_trace__new_mlift1076_op_fun1504(_c_1, _c_3, _c_2, _ctx), _ctx); /*3991*/
    return kk_trace__trace_unbox(_x1503, _ctx);
  }
  kk_box_t _x1506;
  if (kk_std_core_types__is_Optional(a0)) {
    kk_box_t _a_204 = a0._cons.Optional.value;
    kk_trace__trace_dropn(_this, ((int32_t)3), _ctx);
    _x1506 = _a_204; /*219*/
  }
  else {
    struct kk_trace_Trace* _con1507 = kk_trace__as_Trace(_this);
    kk_function_t _pat00 = _con1507->m;
    kk_effects_dash_and_dash_types__exp _pat10 = _con1507->p;
    kk_std_core__list _pat3 = _con1507->l;
    kk_box_t _x = _con1507->a;
    if (kk_trace__trace_is_unique(_this)) {
      kk_std_core__list_drop(_pat3, _ctx);
      kk_function_drop(_pat00, _ctx);
      kk_trace__trace_free(_this);
    }
    else {
      kk_box_dup(_x);
      kk_trace__trace_decref(_this, _ctx);
    }
    _x1506 = _x; /*219*/
  }
  return kk_trace__mlift1075_op(_c_1, _c_2, _c_3, _x1506, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_trace__mlift1077_op_fun1509__t {
  struct kk_function_s _base;
  kk_function_t _c_1;
  kk_trace__trace _this;
  kk_std_core_types__optional a0;
  kk_effects_dash_and_dash_types__exp _c_2;
};
static kk_box_t kk_trace__mlift1077_op_fun1509(kk_function_t _fself, kk_box_t _b_1214, kk_context_t* _ctx);
static kk_function_t kk_trace__new_mlift1077_op_fun1509(kk_function_t _c_1, kk_trace__trace _this, kk_std_core_types__optional a0, kk_effects_dash_and_dash_types__exp _c_2, kk_context_t* _ctx) {
  struct kk_trace__mlift1077_op_fun1509__t* _self = kk_function_alloc_as(struct kk_trace__mlift1077_op_fun1509__t, 5, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_trace__mlift1077_op_fun1509, kk_context());
  _self->_c_1 = _c_1;
  _self->_this = _this;
  _self->a0 = a0;
  _self->_c_2 = _c_2;
  return &_self->_base;
}

static kk_box_t kk_trace__mlift1077_op_fun1509(kk_function_t _fself, kk_box_t _b_1214, kk_context_t* _ctx) {
  struct kk_trace__mlift1077_op_fun1509__t* _self = kk_function_as(struct kk_trace__mlift1077_op_fun1509__t*, _fself);
  kk_function_t _c_1 = _self->_c_1; /* () -> 220 219 */
  kk_trace__trace _this = _self->_this; /* trace/trace<219,220> */
  kk_std_core_types__optional a0 = _self->a0; /* optional<219> */
  kk_effects_dash_and_dash_types__exp _c_2 = _self->_c_2; /* effects-and-types/exp */
  kk_drop_match(_self, {kk_function_dup(_c_1);kk_trace__trace_dup(_this);kk_std_core_types__optional_dup(a0);kk_effects_dash_and_dash_types__exp_dup(_c_2);}, {}, _ctx)
  kk_trace__trace _x1510;
  kk_std_core__list _x1511 = kk_std_core__list_unbox(_b_1214, _ctx); /*effects-and-types/trace_values*/
  _x1510 = kk_trace__mlift1076_op(_c_1, _c_2, _this, a0, _x1511, _ctx); /*trace/trace<219,220>*/
  return kk_trace__trace_box(_x1510, _ctx);
}

kk_trace__trace kk_trace__mlift1077_op(kk_function_t _c_1, kk_trace__trace _this, kk_std_core_types__optional a0, kk_std_core_types__optional l0, kk_effects_dash_and_dash_types__exp _c_2, kk_context_t* _ctx) { /* forall<a,e> (() -> e a, trace<a,e>, a : optional<a>, l : optional<effects-and-types/trace_values>, effects-and-types/exp) -> trace<a,e> */ 
  if (kk_yielding(kk_context())) {
    kk_std_core_types__optional_drop(l0, _ctx);
    kk_box_t _x1508 = kk_std_core_hnd_yield_extend(kk_trace__new_mlift1077_op_fun1509(_c_1, _this, a0, _c_2, _ctx), _ctx); /*3991*/
    return kk_trace__trace_unbox(_x1508, _ctx);
  }
  kk_trace__trace _x1512 = kk_trace__trace_dup(_this); /*trace/trace<219,220>*/
  kk_std_core__list _x1513;
  if (kk_std_core_types__is_Optional(l0)) {
    kk_box_t _box_x1215 = l0._cons.Optional.value;
    kk_std_core__list _l_196 = kk_std_core__list_unbox(_box_x1215, NULL);
    kk_std_core__list_dup(_l_196);
    kk_std_core_types__optional_drop(l0, _ctx);
    kk_trace__trace_dropn(_this, ((int32_t)3), _ctx);
    _x1513 = _l_196; /*effects-and-types/trace_values*/
    goto _match1514;
  }
  struct kk_trace_Trace* _con1516 = kk_trace__as_Trace(_this);
  kk_function_t _pat00 = _con1516->m;
  kk_effects_dash_and_dash_types__exp _pat10 = _con1516->p;
  kk_std_core__list _x = _con1516->l;
  kk_box_t _pat30 = _con1516->a;
  if (kk_trace__trace_is_unique(_this)) {
    kk_box_drop(_pat30, _ctx);
    kk_function_drop(_pat00, _ctx);
    kk_trace__trace_free(_this);
  }
  else {
    kk_std_core__list_dup(_x);
    kk_trace__trace_decref(_this, _ctx);
  }
  _x1513 = _x; /*effects-and-types/trace_values*/
  _match1514: ;
  return kk_trace__mlift1076_op(_c_1, _c_2, _x1512, a0, _x1513, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_trace__mlift1078_op_fun1518__t {
  struct kk_function_s _base;
  kk_function_t _c_1;
  kk_trace__trace _this;
  kk_std_core_types__optional a0;
  kk_std_core_types__optional l0;
};
static kk_box_t kk_trace__mlift1078_op_fun1518(kk_function_t _fself, kk_box_t _b_1219, kk_context_t* _ctx);
static kk_function_t kk_trace__new_mlift1078_op_fun1518(kk_function_t _c_1, kk_trace__trace _this, kk_std_core_types__optional a0, kk_std_core_types__optional l0, kk_context_t* _ctx) {
  struct kk_trace__mlift1078_op_fun1518__t* _self = kk_function_alloc_as(struct kk_trace__mlift1078_op_fun1518__t, 7, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_trace__mlift1078_op_fun1518, kk_context());
  _self->_c_1 = _c_1;
  _self->_this = _this;
  _self->a0 = a0;
  _self->l0 = l0;
  return &_self->_base;
}

static kk_box_t kk_trace__mlift1078_op_fun1518(kk_function_t _fself, kk_box_t _b_1219, kk_context_t* _ctx) {
  struct kk_trace__mlift1078_op_fun1518__t* _self = kk_function_as(struct kk_trace__mlift1078_op_fun1518__t*, _fself);
  kk_function_t _c_1 = _self->_c_1; /* () -> 220 219 */
  kk_trace__trace _this = _self->_this; /* trace/trace<219,220> */
  kk_std_core_types__optional a0 = _self->a0; /* optional<219> */
  kk_std_core_types__optional l0 = _self->l0; /* optional<effects-and-types/trace_values> */
  kk_drop_match(_self, {kk_function_dup(_c_1);kk_trace__trace_dup(_this);kk_std_core_types__optional_dup(a0);kk_std_core_types__optional_dup(l0);}, {}, _ctx)
  kk_trace__trace _x1519;
  kk_effects_dash_and_dash_types__exp _x1520 = kk_effects_dash_and_dash_types__exp_unbox(_b_1219, _ctx); /*effects-and-types/exp*/
  _x1519 = kk_trace__mlift1077_op(_c_1, _this, a0, l0, _x1520, _ctx); /*trace/trace<219,220>*/
  return kk_trace__trace_box(_x1519, _ctx);
}

kk_trace__trace kk_trace__mlift1078_op(kk_trace__trace _this, kk_std_core_types__optional a0, kk_std_core_types__optional l0, kk_std_core_types__optional p0, kk_function_t _c_1, kk_context_t* _ctx) { /* forall<a,e> (trace<a,e>, a : optional<a>, l : optional<effects-and-types/trace_values>, p : optional<effects-and-types/exp>, () -> e a) -> trace<a,e> */ 
  if (kk_yielding(kk_context())) {
    kk_std_core_types__optional_drop(p0, _ctx);
    kk_box_t _x1517 = kk_std_core_hnd_yield_extend(kk_trace__new_mlift1078_op_fun1518(_c_1, _this, a0, l0, _ctx), _ctx); /*3991*/
    return kk_trace__trace_unbox(_x1517, _ctx);
  }
  kk_trace__trace _x1521 = kk_trace__trace_dup(_this); /*trace/trace<219,220>*/
  kk_effects_dash_and_dash_types__exp _x1522;
  if (kk_std_core_types__is_Optional(p0)) {
    kk_box_t _box_x1220 = p0._cons.Optional.value;
    kk_effects_dash_and_dash_types__exp _p_188 = kk_effects_dash_and_dash_types__exp_unbox(_box_x1220, NULL);
    kk_std_core_types__optional_drop(p0, _ctx);
    kk_trace__trace_dropn(_this, ((int32_t)3), _ctx);
    _x1522 = _p_188; /*effects-and-types/exp*/
    goto _match1523;
  }
  struct kk_trace_Trace* _con1525 = kk_trace__as_Trace(_this);
  kk_function_t _pat00 = _con1525->m;
  kk_effects_dash_and_dash_types__exp _x = _con1525->p;
  kk_std_core__list _pat20 = _con1525->l;
  kk_box_t _pat30 = _con1525->a;
  if (kk_trace__trace_is_unique(_this)) {
    kk_box_drop(_pat30, _ctx);
    kk_std_core__list_drop(_pat20, _ctx);
    kk_function_drop(_pat00, _ctx);
    kk_trace__trace_free(_this);
  }
  else {
    kk_trace__trace_decref(_this, _ctx);
  }
  _x1522 = _x; /*effects-and-types/exp*/
  _match1523: ;
  return kk_trace__mlift1077_op(_c_1, _x1521, a0, l0, _x1522, _ctx);
}


// lift anonymous function
struct kk_trace__copy_fun1527__t {
  struct kk_function_s _base;
  kk_trace__trace _this;
  kk_std_core_types__optional a0;
  kk_std_core_types__optional l0;
  kk_std_core_types__optional p0;
};
static kk_box_t kk_trace__copy_fun1527(kk_function_t _fself, kk_box_t _b_1224, kk_context_t* _ctx);
static kk_function_t kk_trace__new_copy_fun1527(kk_trace__trace _this, kk_std_core_types__optional a0, kk_std_core_types__optional l0, kk_std_core_types__optional p0, kk_context_t* _ctx) {
  struct kk_trace__copy_fun1527__t* _self = kk_function_alloc_as(struct kk_trace__copy_fun1527__t, 8, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_trace__copy_fun1527, kk_context());
  _self->_this = _this;
  _self->a0 = a0;
  _self->l0 = l0;
  _self->p0 = p0;
  return &_self->_base;
}

static kk_box_t kk_trace__copy_fun1527(kk_function_t _fself, kk_box_t _b_1224, kk_context_t* _ctx) {
  struct kk_trace__copy_fun1527__t* _self = kk_function_as(struct kk_trace__copy_fun1527__t*, _fself);
  kk_trace__trace _this = _self->_this; /* trace/trace<219,220> */
  kk_std_core_types__optional a0 = _self->a0; /* optional<219> */
  kk_std_core_types__optional l0 = _self->l0; /* optional<effects-and-types/trace_values> */
  kk_std_core_types__optional p0 = _self->p0; /* optional<effects-and-types/exp> */
  kk_drop_match(_self, {kk_trace__trace_dup(_this);kk_std_core_types__optional_dup(a0);kk_std_core_types__optional_dup(l0);kk_std_core_types__optional_dup(p0);}, {}, _ctx)
  kk_trace__trace _x1528;
  kk_function_t _x1529 = kk_function_unbox(_b_1224); /*() -> 220 1225*/
  _x1528 = kk_trace__mlift1078_op(_this, a0, l0, p0, _x1529, _ctx); /*trace/trace<219,220>*/
  return kk_trace__trace_box(_x1528, _ctx);
}


// lift anonymous function
struct kk_trace__copy_fun1531__t {
  struct kk_function_s _base;
  kk_trace__trace _this;
  kk_std_core_types__optional a0;
  kk_std_core_types__optional l0;
  kk_std_core_types__optional m0;
};
static kk_box_t kk_trace__copy_fun1531(kk_function_t _fself, kk_box_t _b_1230, kk_context_t* _ctx);
static kk_function_t kk_trace__new_copy_fun1531(kk_trace__trace _this, kk_std_core_types__optional a0, kk_std_core_types__optional l0, kk_std_core_types__optional m0, kk_context_t* _ctx) {
  struct kk_trace__copy_fun1531__t* _self = kk_function_alloc_as(struct kk_trace__copy_fun1531__t, 8, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_trace__copy_fun1531, kk_context());
  _self->_this = _this;
  _self->a0 = a0;
  _self->l0 = l0;
  _self->m0 = m0;
  return &_self->_base;
}

static kk_box_t kk_trace__copy_fun1531(kk_function_t _fself, kk_box_t _b_1230, kk_context_t* _ctx) {
  struct kk_trace__copy_fun1531__t* _self = kk_function_as(struct kk_trace__copy_fun1531__t*, _fself);
  kk_trace__trace _this = _self->_this; /* trace/trace<219,220> */
  kk_std_core_types__optional a0 = _self->a0; /* optional<219> */
  kk_std_core_types__optional l0 = _self->l0; /* optional<effects-and-types/trace_values> */
  kk_std_core_types__optional m0 = _self->m0; /* optional<() -> 220 219> */
  kk_drop_match(_self, {kk_trace__trace_dup(_this);kk_std_core_types__optional_dup(a0);kk_std_core_types__optional_dup(l0);kk_std_core_types__optional_dup(m0);}, {}, _ctx)
  kk_trace__trace _x1532;
  kk_function_t _x1533;
  if (kk_std_core_types__is_Optional(m0)) {
    kk_box_t _fun_unbox_x1227 = m0._cons.Optional.value;
    _x1533 = kk_function_unbox(_fun_unbox_x1227); /*() -> 220 1228*/
  }
  else {
    struct kk_trace_Trace* _con1534 = kk_trace__as_Trace(_this);
    kk_function_t _x = _con1534->m;
    kk_effects_dash_and_dash_types__exp _pat01 = _con1534->p;
    kk_function_dup(_x);
    _x1533 = _x; /*() -> 220 1228*/
  }
  kk_effects_dash_and_dash_types__exp _x1535 = kk_effects_dash_and_dash_types__exp_unbox(_b_1230, _ctx); /*effects-and-types/exp*/
  _x1532 = kk_trace__mlift1077_op(_x1533, _this, a0, l0, _x1535, _ctx); /*trace/trace<219,220>*/
  return kk_trace__trace_box(_x1532, _ctx);
}


// lift anonymous function
struct kk_trace__copy_fun1537__t {
  struct kk_function_s _base;
  kk_trace__trace _this;
  kk_std_core_types__optional a0;
  kk_std_core_types__optional m0;
  kk_std_core_types__optional p0;
};
static kk_box_t kk_trace__copy_fun1537(kk_function_t _fself, kk_box_t _b_1236, kk_context_t* _ctx);
static kk_function_t kk_trace__new_copy_fun1537(kk_trace__trace _this, kk_std_core_types__optional a0, kk_std_core_types__optional m0, kk_std_core_types__optional p0, kk_context_t* _ctx) {
  struct kk_trace__copy_fun1537__t* _self = kk_function_alloc_as(struct kk_trace__copy_fun1537__t, 8, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_trace__copy_fun1537, kk_context());
  _self->_this = _this;
  _self->a0 = a0;
  _self->m0 = m0;
  _self->p0 = p0;
  return &_self->_base;
}

static kk_box_t kk_trace__copy_fun1537(kk_function_t _fself, kk_box_t _b_1236, kk_context_t* _ctx) {
  struct kk_trace__copy_fun1537__t* _self = kk_function_as(struct kk_trace__copy_fun1537__t*, _fself);
  kk_trace__trace _this = _self->_this; /* trace/trace<219,220> */
  kk_std_core_types__optional a0 = _self->a0; /* optional<219> */
  kk_std_core_types__optional m0 = _self->m0; /* optional<() -> 220 219> */
  kk_std_core_types__optional p0 = _self->p0; /* optional<effects-and-types/exp> */
  kk_drop_match(_self, {kk_trace__trace_dup(_this);kk_std_core_types__optional_dup(a0);kk_std_core_types__optional_dup(m0);kk_std_core_types__optional_dup(p0);}, {}, _ctx)
  kk_trace__trace _x1538;
  kk_function_t _x1539;
  if (kk_std_core_types__is_Optional(m0)) {
    kk_box_t _fun_unbox_x1232 = m0._cons.Optional.value;
    _x1539 = kk_function_unbox(_fun_unbox_x1232); /*() -> 220 1233*/
  }
  else {
    struct kk_trace_Trace* _con1540 = kk_trace__as_Trace(_this);
    kk_function_t _x0 = _con1540->m;
    kk_effects_dash_and_dash_types__exp _pat010 = _con1540->p;
    kk_function_dup(_x0);
    _x1539 = _x0; /*() -> 220 1233*/
  }
  kk_effects_dash_and_dash_types__exp _x1541;
  if (kk_std_core_types__is_Optional(p0)) {
    kk_box_t _box_x1234 = p0._cons.Optional.value;
    kk_effects_dash_and_dash_types__exp _p_188 = kk_effects_dash_and_dash_types__exp_unbox(_box_x1234, NULL);
    kk_std_core_types__optional_drop(p0, _ctx);
    _x1541 = _p_188; /*effects-and-types/exp*/
    goto _match1542;
  }
  struct kk_trace_Trace* _con1544 = kk_trace__as_Trace(_this);
  kk_effects_dash_and_dash_types__exp _x00 = _con1544->p;
  _x1541 = _x00; /*effects-and-types/exp*/
  _match1542: ;
  kk_std_core__list _x1545 = kk_std_core__list_unbox(_b_1236, _ctx); /*effects-and-types/trace_values*/
  _x1538 = kk_trace__mlift1076_op(_x1539, _x1541, _this, a0, _x1545, _ctx); /*trace/trace<219,220>*/
  return kk_trace__trace_box(_x1538, _ctx);
}


// lift anonymous function
struct kk_trace__copy_fun1547__t {
  struct kk_function_s _base;
  kk_trace__trace _this;
  kk_std_core_types__optional l0;
  kk_std_core_types__optional m0;
  kk_std_core_types__optional p0;
};
static kk_box_t kk_trace__copy_fun1547(kk_function_t _fself, kk_box_t _b_1243, kk_context_t* _ctx);
static kk_function_t kk_trace__new_copy_fun1547(kk_trace__trace _this, kk_std_core_types__optional l0, kk_std_core_types__optional m0, kk_std_core_types__optional p0, kk_context_t* _ctx) {
  struct kk_trace__copy_fun1547__t* _self = kk_function_alloc_as(struct kk_trace__copy_fun1547__t, 8, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_trace__copy_fun1547, kk_context());
  _self->_this = _this;
  _self->l0 = l0;
  _self->m0 = m0;
  _self->p0 = p0;
  return &_self->_base;
}

static kk_box_t kk_trace__copy_fun1547(kk_function_t _fself, kk_box_t _b_1243, kk_context_t* _ctx) {
  struct kk_trace__copy_fun1547__t* _self = kk_function_as(struct kk_trace__copy_fun1547__t*, _fself);
  kk_trace__trace _this = _self->_this; /* trace/trace<219,220> */
  kk_std_core_types__optional l0 = _self->l0; /* optional<effects-and-types/trace_values> */
  kk_std_core_types__optional m0 = _self->m0; /* optional<() -> 220 219> */
  kk_std_core_types__optional p0 = _self->p0; /* optional<effects-and-types/exp> */
  kk_drop_match(_self, {kk_trace__trace_dup(_this);kk_std_core_types__optional_dup(l0);kk_std_core_types__optional_dup(m0);kk_std_core_types__optional_dup(p0);}, {}, _ctx)
  kk_trace__trace _x1548;
  kk_function_t _x1549;
  if (kk_std_core_types__is_Optional(m0)) {
    kk_box_t _fun_unbox_x1238 = m0._cons.Optional.value;
    _x1549 = kk_function_unbox(_fun_unbox_x1238); /*() -> 220 1239*/
  }
  else {
    struct kk_trace_Trace* _con1550 = kk_trace__as_Trace(_this);
    kk_function_t _x1 = _con1550->m;
    kk_effects_dash_and_dash_types__exp _pat011 = _con1550->p;
    kk_function_dup(_x1);
    _x1549 = _x1; /*() -> 220 1239*/
  }
  kk_effects_dash_and_dash_types__exp _x1551;
  if (kk_std_core_types__is_Optional(p0)) {
    kk_box_t _box_x1240 = p0._cons.Optional.value;
    kk_effects_dash_and_dash_types__exp _p_1880 = kk_effects_dash_and_dash_types__exp_unbox(_box_x1240, NULL);
    kk_std_core_types__optional_drop(p0, _ctx);
    _x1551 = _p_1880; /*effects-and-types/exp*/
    goto _match1552;
  }
  struct kk_trace_Trace* _con1554 = kk_trace__as_Trace(_this);
  kk_effects_dash_and_dash_types__exp _x01 = _con1554->p;
  _x1551 = _x01; /*effects-and-types/exp*/
  _match1552: ;
  kk_std_core__list _x1555;
  if (kk_std_core_types__is_Optional(l0)) {
    kk_box_t _box_x1241 = l0._cons.Optional.value;
    kk_std_core__list _l_196 = kk_std_core__list_unbox(_box_x1241, NULL);
    kk_std_core__list_dup(_l_196);
    kk_std_core_types__optional_drop(l0, _ctx);
    kk_trace__trace_dropn(_this, ((int32_t)3), _ctx);
    _x1555 = _l_196; /*effects-and-types/trace_values*/
    goto _match1556;
  }
  struct kk_trace_Trace* _con1558 = kk_trace__as_Trace(_this);
  kk_function_t _pat05 = _con1558->m;
  kk_effects_dash_and_dash_types__exp _pat130 = _con1558->p;
  kk_std_core__list _x10 = _con1558->l;
  kk_box_t _pat32 = _con1558->a;
  if (kk_trace__trace_is_unique(_this)) {
    kk_box_drop(_pat32, _ctx);
    kk_function_drop(_pat05, _ctx);
    kk_trace__trace_free(_this);
  }
  else {
    kk_std_core__list_dup(_x10);
    kk_trace__trace_decref(_this, _ctx);
  }
  _x1555 = _x10; /*effects-and-types/trace_values*/
  _match1556: ;
  _x1548 = kk_trace__mlift1075_op(_x1549, _x1551, _x1555, _b_1243, _ctx); /*trace/trace<219,220>*/
  return kk_trace__trace_box(_x1548, _ctx);
}

kk_trace__trace kk_trace__copy(kk_trace__trace _this, kk_std_core_types__optional m0, kk_std_core_types__optional p0, kk_std_core_types__optional l0, kk_std_core_types__optional a0, kk_context_t* _ctx) { /* forall<a,e> (trace<a,e>, m : optional<() -> e a>, p : optional<effects-and-types/exp>, l : optional<effects-and-types/trace_values>, a : optional<a>) -> trace<a,e> */ 
  if (kk_yielding(kk_context())) {
    kk_std_core_types__optional_drop(m0, _ctx);
    kk_box_t _x1526 = kk_std_core_hnd_yield_extend(kk_trace__new_copy_fun1527(_this, a0, l0, p0, _ctx), _ctx); /*3991*/
    return kk_trace__trace_unbox(_x1526, _ctx);
  }
  if (kk_yielding(kk_context())) {
    kk_std_core_types__optional_drop(p0, _ctx);
    kk_box_t _x1530 = kk_std_core_hnd_yield_extend(kk_trace__new_copy_fun1531(_this, a0, l0, m0, _ctx), _ctx); /*3991*/
    return kk_trace__trace_unbox(_x1530, _ctx);
  }
  if (kk_yielding(kk_context())) {
    kk_std_core_types__optional_drop(l0, _ctx);
    kk_box_t _x1536 = kk_std_core_hnd_yield_extend(kk_trace__new_copy_fun1537(_this, a0, m0, p0, _ctx), _ctx); /*3991*/
    return kk_trace__trace_unbox(_x1536, _ctx);
  }
  if (kk_yielding(kk_context())) {
    kk_std_core_types__optional_drop(a0, _ctx);
    kk_box_t _x1546 = kk_std_core_hnd_yield_extend(kk_trace__new_copy_fun1547(_this, l0, m0, p0, _ctx), _ctx); /*3991*/
    return kk_trace__trace_unbox(_x1546, _ctx);
  }
  kk_function_t _x1559;
  if (kk_std_core_types__is_Optional(m0)) {
    kk_box_t _fun_unbox_x1245 = m0._cons.Optional.value;
    _x1559 = kk_function_unbox(_fun_unbox_x1245); /*() -> 220 1246*/
  }
  else {
    struct kk_trace_Trace* _con1560 = kk_trace__as_Trace(_this);
    kk_function_t _x2 = _con1560->m;
    kk_effects_dash_and_dash_types__exp _pat012 = _con1560->p;
    kk_function_dup(_x2);
    _x1559 = _x2; /*() -> 220 1246*/
  }
  kk_effects_dash_and_dash_types__exp _x1561;
  if (kk_std_core_types__is_Optional(p0)) {
    kk_box_t _box_x1247 = p0._cons.Optional.value;
    kk_effects_dash_and_dash_types__exp _p_1881 = kk_effects_dash_and_dash_types__exp_unbox(_box_x1247, NULL);
    kk_std_core_types__optional_drop(p0, _ctx);
    _x1561 = _p_1881; /*effects-and-types/exp*/
    goto _match1562;
  }
  struct kk_trace_Trace* _con1564 = kk_trace__as_Trace(_this);
  kk_effects_dash_and_dash_types__exp _x02 = _con1564->p;
  _x1561 = _x02; /*effects-and-types/exp*/
  _match1562: ;
  kk_std_core__list _x1565;
  if (kk_std_core_types__is_Optional(l0)) {
    kk_box_t _box_x1248 = l0._cons.Optional.value;
    kk_std_core__list _l_1960 = kk_std_core__list_unbox(_box_x1248, NULL);
    kk_std_core__list_dup(_l_1960);
    kk_std_core_types__optional_drop(l0, _ctx);
    _x1565 = _l_1960; /*effects-and-types/trace_values*/
    goto _match1566;
  }
  struct kk_trace_Trace* _con1568 = kk_trace__as_Trace(_this);
  kk_effects_dash_and_dash_types__exp _pat131 = _con1568->p;
  kk_std_core__list _x11 = _con1568->l;
  kk_std_core__list_dup(_x11);
  _x1565 = _x11; /*effects-and-types/trace_values*/
  _match1566: ;
  kk_box_t _x1569;
  if (kk_std_core_types__is_Optional(a0)) {
    kk_box_t _a_204 = a0._cons.Optional.value;
    kk_trace__trace_dropn(_this, ((int32_t)3), _ctx);
    _x1569 = _a_204; /*219*/
  }
  else {
    struct kk_trace_Trace* _con1570 = kk_trace__as_Trace(_this);
    kk_function_t _pat07 = _con1570->m;
    kk_effects_dash_and_dash_types__exp _pat140 = _con1570->p;
    kk_std_core__list _pat330 = _con1570->l;
    kk_box_t _x20 = _con1570->a;
    if (kk_trace__trace_is_unique(_this)) {
      kk_std_core__list_drop(_pat330, _ctx);
      kk_function_drop(_pat07, _ctx);
      kk_trace__trace_free(_this);
    }
    else {
      kk_box_dup(_x20);
      kk_trace__trace_decref(_this, _ctx);
    }
    _x1569 = _x20; /*219*/
  }
  return kk_trace__new_Trace(kk_reuse_null, _x1559, _x1561, _x1565, _x1569, _ctx);
}
 
// monadic lift

kk_integer_t kk_trace__mlift1079_random__range(kk_integer_t upper__bound, double _y_5, kk_context_t* _ctx) { /* (upper_bound : int, double) -> effects-and-types/sample int */ 
  kk_integer_t _x1571;
  double _x1572;
  double _x1573;
  double _x1574;
  kk_integer_t _x1575 = kk_integer_dup(upper__bound); /*int*/
  _x1574 = kk_integer_as_double(_x1575,kk_context()); /*double*/
  _x1573 = (0x1p0 / _x1574); /*double*/
  _x1572 = (_y_5 / _x1573); /*double*/
  _x1571 = kk_integer_from_double(_x1572,kk_context()); /*int*/
  return kk_integer_mod(_x1571,upper__bound,kk_context());
}


// lift anonymous function
struct kk_trace_random__range_fun1577__t {
  struct kk_function_s _base;
  kk_integer_t upper__bound;
};
static kk_box_t kk_trace_random__range_fun1577(kk_function_t _fself, kk_box_t _b_1258, kk_context_t* _ctx);
static kk_function_t kk_trace_new_random__range_fun1577(kk_integer_t upper__bound, kk_context_t* _ctx) {
  struct kk_trace_random__range_fun1577__t* _self = kk_function_alloc_as(struct kk_trace_random__range_fun1577__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_trace_random__range_fun1577, kk_context());
  _self->upper__bound = upper__bound;
  return &_self->_base;
}

static kk_box_t kk_trace_random__range_fun1577(kk_function_t _fself, kk_box_t _b_1258, kk_context_t* _ctx) {
  struct kk_trace_random__range_fun1577__t* _self = kk_function_as(struct kk_trace_random__range_fun1577__t*, _fself);
  kk_integer_t upper__bound = _self->upper__bound; /* int */
  kk_drop_match(_self, {kk_integer_dup(upper__bound);}, {}, _ctx)
  kk_integer_t _x1578;
  double _x1579 = kk_double_unbox(_b_1258, _ctx); /*double*/
  _x1578 = kk_trace__mlift1079_random__range(upper__bound, _x1579, _ctx); /*int*/
  return kk_integer_box(_x1578);
}

kk_integer_t kk_trace_random__range(kk_integer_t upper__bound, kk_context_t* _ctx) { /* (upper_bound : int) -> effects-and-types/sample int */ 
  double x_1116 = kk_effects_dash_and_dash_types_sample(_ctx); /*double*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x1576 = kk_std_core_hnd_yield_extend(kk_trace_new_random__range_fun1577(upper__bound, _ctx), _ctx); /*3991*/
    return kk_integer_unbox(_x1576);
  }
  kk_integer_t _x1580;
  double _x1581;
  double _x1582;
  double _x1583;
  kk_integer_t _x1584 = kk_integer_dup(upper__bound); /*int*/
  _x1583 = kk_integer_as_double(_x1584,kk_context()); /*double*/
  _x1582 = (0x1p0 / _x1583); /*double*/
  _x1581 = (x_1116 / _x1582); /*double*/
  _x1580 = kk_integer_from_double(_x1581,kk_context()); /*int*/
  return kk_integer_mod(_x1580,upper__bound,kk_context());
}


// lift anonymous function
struct kk_trace_with__randomness_fun1585__t {
  struct kk_function_s _base;
  kk_function_t model;
};
static kk_box_t kk_trace_with__randomness_fun1585(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_trace_new_with__randomness_fun1585(kk_function_t model, kk_context_t* _ctx) {
  struct kk_trace_with__randomness_fun1585__t* _self = kk_function_alloc_as(struct kk_trace_with__randomness_fun1585__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_trace_with__randomness_fun1585, kk_context());
  _self->model = model;
  return &_self->_base;
}



// lift anonymous function
struct kk_trace_with__randomness_fun1589__t {
  struct kk_function_s _base;
  kk_function_t model;
};
static kk_box_t kk_trace_with__randomness_fun1589(kk_function_t _fself, kk_box_t _b_1264, kk_context_t* _ctx);
static kk_function_t kk_trace_new_with__randomness_fun1589(kk_function_t model, kk_context_t* _ctx) {
  struct kk_trace_with__randomness_fun1589__t* _self = kk_function_alloc_as(struct kk_trace_with__randomness_fun1589__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_trace_with__randomness_fun1589, kk_context());
  _self->model = model;
  return &_self->_base;
}



// lift anonymous function
struct kk_trace_with__randomness_fun1590__t {
  struct kk_function_s _base;
  kk_function_t model;
};
static kk_box_t kk_trace_with__randomness_fun1590(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_trace_new_with__randomness_fun1590(kk_function_t model, kk_context_t* _ctx) {
  struct kk_trace_with__randomness_fun1590__t* _self = kk_function_alloc_as(struct kk_trace_with__randomness_fun1590__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_trace_with__randomness_fun1590, kk_context());
  _self->model = model;
  return &_self->_base;
}

static kk_box_t kk_trace_with__randomness_fun1590(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_trace_with__randomness_fun1590__t* _self = kk_function_as(struct kk_trace_with__randomness_fun1590__t*, _fself);
  kk_function_t model = _self->model; /* () -> <effects-and-types/sample,effects-and-types/score|446> 445 */
  kk_drop_match(_self, {kk_function_dup(model);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x1591;
  kk_effects_dash_and_dash_types__exp _x1592 = kk_effects_dash_and_dash_types__new_Exp(0x0p+0, _ctx); /*effects-and-types/exp*/
  _x1591 = kk_handlers_weighted(_x1592, model, _ctx); /*(effects-and-types/exp, 1581)*/
  return kk_std_core_types__tuple2__box(_x1591, _ctx);
}
static kk_box_t kk_trace_with__randomness_fun1589(kk_function_t _fself, kk_box_t _b_1264, kk_context_t* _ctx) {
  struct kk_trace_with__randomness_fun1589__t* _self = kk_function_as(struct kk_trace_with__randomness_fun1589__t*, _fself);
  kk_function_t model = _self->model; /* () -> <effects-and-types/sample,effects-and-types/score|446> 445 */
  kk_drop_match(_self, {kk_function_dup(model);}, {}, _ctx)
  size_t _x1593 = kk_size_unbox(_b_1264, _ctx); /*std/core/hnd/ev-index*/
  return kk_handlers__mlift1713_replay(kk_trace_new_with__randomness_fun1590(model, _ctx), _x1593, _ctx);
}


// lift anonymous function
struct kk_trace_with__randomness_fun1594__t {
  struct kk_function_s _base;
  kk_function_t model;
};
static kk_box_t kk_trace_with__randomness_fun1594(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_trace_new_with__randomness_fun1594(kk_function_t model, kk_context_t* _ctx) {
  struct kk_trace_with__randomness_fun1594__t* _self = kk_function_alloc_as(struct kk_trace_with__randomness_fun1594__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_trace_with__randomness_fun1594, kk_context());
  _self->model = model;
  return &_self->_base;
}

static kk_box_t kk_trace_with__randomness_fun1594(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_trace_with__randomness_fun1594__t* _self = kk_function_as(struct kk_trace_with__randomness_fun1594__t*, _fself);
  kk_function_t model = _self->model; /* () -> <effects-and-types/sample,effects-and-types/score|446> 445 */
  kk_drop_match(_self, {kk_function_dup(model);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x1595;
  kk_effects_dash_and_dash_types__exp _x1596 = kk_effects_dash_and_dash_types__new_Exp(0x0p+0, _ctx); /*effects-and-types/exp*/
  _x1595 = kk_handlers_weighted(_x1596, model, _ctx); /*(effects-and-types/exp, 1581)*/
  return kk_std_core_types__tuple2__box(_x1595, _ctx);
}
static kk_box_t kk_trace_with__randomness_fun1585(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_trace_with__randomness_fun1585__t* _self = kk_function_as(struct kk_trace_with__randomness_fun1585__t*, _fself);
  kk_function_t model = _self->model; /* () -> <effects-and-types/sample,effects-and-types/score|446> 445 */
  kk_drop_match(_self, {kk_function_dup(model);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x1586;
  size_t x_1791;
  kk_std_core_hnd__htag _x1587 = kk_std_core_hnd__htag_dup(kk_effects_dash_and_dash_types__tag_sample); /*std/core/hnd/htag<effects-and-types/.hnd-sample>*/
  x_1791 = kk_std_core_hnd__evv_index(_x1587, _ctx); /*std/core/hnd/ev-index*/
  kk_box_t _x1588;
  if (kk_yielding(kk_context())) {
    _x1588 = kk_std_core_hnd_yield_extend(kk_trace_new_with__randomness_fun1589(model, _ctx), _ctx); /*3991*/
  }
  else {
    _x1588 = kk_handlers__mlift1713_replay(kk_trace_new_with__randomness_fun1594(model, _ctx), x_1791, _ctx); /*3991*/
  }
  _x1586 = kk_std_core_types__tuple2__unbox(_x1588, _ctx); /*(effects-and-types/exp, 445)*/
  return kk_std_core_types__tuple2__box(_x1586, _ctx);
}

kk_std_core_types__tuple2_ kk_trace_with__randomness(kk_function_t model, kk_std_core__list trace__values, kk_context_t* _ctx) { /* forall<a,e> (model : () -> <effects-and-types/sample,effects-and-types/score|e> a, trace_values : effects-and-types/trace_values) -> <effects-and-types/sample|e> (effects-and-types/trace_values, (effects-and-types/exp, a)) */ 
  return kk_handlers_replayx(trace__values, kk_trace_new_with__randomness_fun1585(model, _ctx), _ctx);
}
 
// monadic lift

kk_std_core__list kk_trace__mlift1080_perturb__trace(kk_std_core__list l1, kk_std_core__list l2, double _y_9, kk_context_t* _ctx) { /* (l1 : list<double>, l2 : list<double>, double) -> effects-and-types/sample list<double> */ 
  kk_std_core__list ys_1123;
  kk_std_core__list xs0_1124 = kk_std_core__new_Cons(kk_reuse_null, kk_double_box(_y_9, _ctx), kk_std_core__new_Nil(_ctx), _ctx); /*list<double>*/;
  ys_1123 = kk_std_core_append(xs0_1124, l2, _ctx); /*list<double>*/
  return kk_std_core_append(l1, ys_1123, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_trace__mlift1081_perturb__trace_fun1602__t {
  struct kk_function_s _base;
  kk_std_core__list l1;
  kk_std_core__list l2;
};
static kk_box_t kk_trace__mlift1081_perturb__trace_fun1602(kk_function_t _fself, kk_box_t _b_1285, kk_context_t* _ctx);
static kk_function_t kk_trace__new_mlift1081_perturb__trace_fun1602(kk_std_core__list l1, kk_std_core__list l2, kk_context_t* _ctx) {
  struct kk_trace__mlift1081_perturb__trace_fun1602__t* _self = kk_function_alloc_as(struct kk_trace__mlift1081_perturb__trace_fun1602__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_trace__mlift1081_perturb__trace_fun1602, kk_context());
  _self->l1 = l1;
  _self->l2 = l2;
  return &_self->_base;
}

static kk_box_t kk_trace__mlift1081_perturb__trace_fun1602(kk_function_t _fself, kk_box_t _b_1285, kk_context_t* _ctx) {
  struct kk_trace__mlift1081_perturb__trace_fun1602__t* _self = kk_function_as(struct kk_trace__mlift1081_perturb__trace_fun1602__t*, _fself);
  kk_std_core__list l1 = _self->l1; /* list<double> */
  kk_std_core__list l2 = _self->l2; /* list<double> */
  kk_drop_match(_self, {kk_std_core__list_dup(l1);kk_std_core__list_dup(l2);}, {}, _ctx)
  kk_std_core__list _x1603;
  double _x1604 = kk_double_unbox(_b_1285, _ctx); /*double*/
  _x1603 = kk_trace__mlift1080_perturb__trace(l1, l2, _x1604, _ctx); /*list<double>*/
  return kk_std_core__list_box(_x1603, _ctx);
}

kk_std_core__list kk_trace__mlift1081_perturb__trace(kk_std_core__list trace__values, kk_integer_t perturb__index, kk_context_t* _ctx) { /* (trace_values : effects-and-types/trace_values, perturb_index : int) -> effects-and-types/sample list<double> */ 
  kk_std_core_types__tuple2_ div__trace = kk_std_core_split(trace__values, perturb__index, _ctx); /*(list<double>, list<double>)*/;
  kk_box_t _box_x1281 = div__trace.fst;
  kk_box_t _box_x1282 = div__trace.snd;
  kk_std_core__list l1 = kk_std_core__list_unbox(_box_x1281, NULL);
  kk_std_core__list _pat0 = kk_std_core__list_unbox(_box_x1282, NULL);
  if (kk_std_core__is_Cons(_pat0)) {
    struct kk_std_core_Cons* _con1599 = kk_std_core__as_Cons(_pat0);
    kk_box_t _box_x1283 = _con1599->head;
    kk_std_core__list l2 = _con1599->tail;
    kk_std_core__list_dup(l1);
    kk_std_core__list_dup(l2);
    kk_std_core_types__tuple2__drop(div__trace, _ctx);
    double x_1126 = kk_effects_dash_and_dash_types_sample(_ctx); /*double*/;
    if (kk_yielding(kk_context())) {
      kk_box_t _x1601 = kk_std_core_hnd_yield_extend(kk_trace__new_mlift1081_perturb__trace_fun1602(l1, l2, _ctx), _ctx); /*3991*/
      return kk_std_core__list_unbox(_x1601, _ctx);
    }
    return kk_trace__mlift1080_perturb__trace(l1, l2, x_1126, _ctx);
  }
  kk_box_t _box_x1286 = div__trace.fst;
  kk_box_t _box_x1287 = div__trace.snd;
  kk_std_core__list l10 = kk_std_core__list_unbox(_box_x1286, NULL);
  kk_std_core__list l20 = kk_std_core__list_unbox(_box_x1287, NULL);
  kk_std_core__list_dup(l10);
  kk_std_core__list_dup(l20);
  kk_std_core_types__tuple2__drop(div__trace, _ctx);
  return kk_std_core__lp__plus__plus__rp_(l10, l20, _ctx);
}


// lift anonymous function
struct kk_trace_perturb__trace_fun1610__t {
  struct kk_function_s _base;
  kk_integer_t upper__bound_1133;
};
static kk_box_t kk_trace_perturb__trace_fun1610(kk_function_t _fself, kk_box_t _b_1291, kk_context_t* _ctx);
static kk_function_t kk_trace_new_perturb__trace_fun1610(kk_integer_t upper__bound_1133, kk_context_t* _ctx) {
  struct kk_trace_perturb__trace_fun1610__t* _self = kk_function_alloc_as(struct kk_trace_perturb__trace_fun1610__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_trace_perturb__trace_fun1610, kk_context());
  _self->upper__bound_1133 = upper__bound_1133;
  return &_self->_base;
}

static kk_box_t kk_trace_perturb__trace_fun1610(kk_function_t _fself, kk_box_t _b_1291, kk_context_t* _ctx) {
  struct kk_trace_perturb__trace_fun1610__t* _self = kk_function_as(struct kk_trace_perturb__trace_fun1610__t*, _fself);
  kk_integer_t upper__bound_1133 = _self->upper__bound_1133; /* int */
  kk_drop_match(_self, {kk_integer_dup(upper__bound_1133);}, {}, _ctx)
  kk_integer_t _x1611;
  double _x1612 = kk_double_unbox(_b_1291, _ctx); /*double*/
  _x1611 = kk_trace__mlift1079_random__range(upper__bound_1133, _x1612, _ctx); /*int*/
  return kk_integer_box(_x1611);
}


// lift anonymous function
struct kk_trace_perturb__trace_fun1619__t {
  struct kk_function_s _base;
  kk_std_core__list trace__values;
};
static kk_box_t kk_trace_perturb__trace_fun1619(kk_function_t _fself, kk_box_t _b_1295, kk_context_t* _ctx);
static kk_function_t kk_trace_new_perturb__trace_fun1619(kk_std_core__list trace__values, kk_context_t* _ctx) {
  struct kk_trace_perturb__trace_fun1619__t* _self = kk_function_alloc_as(struct kk_trace_perturb__trace_fun1619__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_trace_perturb__trace_fun1619, kk_context());
  _self->trace__values = trace__values;
  return &_self->_base;
}

static kk_box_t kk_trace_perturb__trace_fun1619(kk_function_t _fself, kk_box_t _b_1295, kk_context_t* _ctx) {
  struct kk_trace_perturb__trace_fun1619__t* _self = kk_function_as(struct kk_trace_perturb__trace_fun1619__t*, _fself);
  kk_std_core__list trace__values = _self->trace__values; /* effects-and-types/trace_values */
  kk_drop_match(_self, {kk_std_core__list_dup(trace__values);}, {}, _ctx)
  kk_std_core__list _x1620;
  kk_integer_t _x1621 = kk_integer_unbox(_b_1295); /*int*/
  _x1620 = kk_trace__mlift1081_perturb__trace(trace__values, _x1621, _ctx); /*list<double>*/
  return kk_std_core__list_box(_x1620, _ctx);
}


// lift anonymous function
struct kk_trace_perturb__trace_fun1627__t {
  struct kk_function_s _base;
  kk_std_core__list l1;
  kk_std_core__list l2;
};
static kk_box_t kk_trace_perturb__trace_fun1627(kk_function_t _fself, kk_box_t _b_1300, kk_context_t* _ctx);
static kk_function_t kk_trace_new_perturb__trace_fun1627(kk_std_core__list l1, kk_std_core__list l2, kk_context_t* _ctx) {
  struct kk_trace_perturb__trace_fun1627__t* _self = kk_function_alloc_as(struct kk_trace_perturb__trace_fun1627__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_trace_perturb__trace_fun1627, kk_context());
  _self->l1 = l1;
  _self->l2 = l2;
  return &_self->_base;
}

static kk_box_t kk_trace_perturb__trace_fun1627(kk_function_t _fself, kk_box_t _b_1300, kk_context_t* _ctx) {
  struct kk_trace_perturb__trace_fun1627__t* _self = kk_function_as(struct kk_trace_perturb__trace_fun1627__t*, _fself);
  kk_std_core__list l1 = _self->l1; /* list<double> */
  kk_std_core__list l2 = _self->l2; /* list<double> */
  kk_drop_match(_self, {kk_std_core__list_dup(l1);kk_std_core__list_dup(l2);}, {}, _ctx)
  kk_std_core__list _x1628;
  double _x1629 = kk_double_unbox(_b_1300, _ctx); /*double*/
  _x1628 = kk_trace__mlift1080_perturb__trace(l1, l2, _x1629, _ctx); /*list<double>*/
  return kk_std_core__list_box(_x1628, _ctx);
}

kk_std_core__list kk_trace_perturb__trace(kk_trace__trace trace, kk_context_t* _ctx) { /* forall<a,e> (trace : trace<a,e>) -> effects-and-types/sample effects-and-types/trace_values */ 
  kk_std_core__list trace__values;
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*std/core/hnd/evv<(<>)>*/;
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  struct kk_trace_Trace* _con1607 = kk_trace__as_Trace(trace);
  kk_function_t _pat0 = _con1607->m;
  kk_effects_dash_and_dash_types__exp _pat1 = _con1607->p;
  kk_std_core__list _x = _con1607->l;
  kk_box_t _pat3 = _con1607->a;
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
  kk_integer_t x0_1130;
  kk_integer_t upper__bound_1133;
  kk_std_core__list _x1608 = kk_std_core__list_dup(trace__values); /*effects-and-types/trace_values*/
  upper__bound_1133 = kk_std_core_length_1(_x1608, _ctx); /*int*/
  double x2_1134 = kk_effects_dash_and_dash_types_sample(_ctx); /*double*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x1609 = kk_std_core_hnd_yield_extend(kk_trace_new_perturb__trace_fun1610(upper__bound_1133, _ctx), _ctx); /*3991*/
    x0_1130 = kk_integer_unbox(_x1609); /*int*/
  }
  else {
    kk_integer_t _x1613;
    double _x1614;
    double _x1615;
    double _x1616;
    kk_integer_t _x1617 = kk_integer_dup(upper__bound_1133); /*int*/
    _x1616 = kk_integer_as_double(_x1617,kk_context()); /*double*/
    _x1615 = (0x1p0 / _x1616); /*double*/
    _x1614 = (x2_1134 / _x1615); /*double*/
    _x1613 = kk_integer_from_double(_x1614,kk_context()); /*int*/
    x0_1130 = kk_integer_mod(_x1613,upper__bound_1133,kk_context()); /*int*/
  }
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x0_1130, _ctx);
    kk_box_t _x1618 = kk_std_core_hnd_yield_extend(kk_trace_new_perturb__trace_fun1619(trace__values, _ctx), _ctx); /*3991*/
    return kk_std_core__list_unbox(_x1618, _ctx);
  }
  kk_std_core_types__tuple2_ div__trace = kk_std_core_split(trace__values, x0_1130, _ctx); /*(list<double>, list<double>)*/;
  kk_box_t _box_x1296 = div__trace.fst;
  kk_box_t _box_x1297 = div__trace.snd;
  kk_std_core__list l1 = kk_std_core__list_unbox(_box_x1296, NULL);
  kk_std_core__list _pat010 = kk_std_core__list_unbox(_box_x1297, NULL);
  if (kk_std_core__is_Cons(_pat010)) {
    struct kk_std_core_Cons* _con1624 = kk_std_core__as_Cons(_pat010);
    kk_box_t _box_x1298 = _con1624->head;
    kk_std_core__list l2 = _con1624->tail;
    kk_reuse_t _ru_1463 = kk_reuse_null; /*reuse*/;
    kk_std_core__list_dup(l1);
    kk_std_core__list_dup(l2);
    _ru_1463 = kk_reuse_null;
    kk_std_core_types__tuple2__drop(div__trace, _ctx);
    double x3_1139 = kk_effects_dash_and_dash_types_sample(_ctx); /*double*/;
    if (kk_yielding(kk_context())) {
      kk_reuse_drop(_ru_1463, _ctx);
      kk_box_t _x1626 = kk_std_core_hnd_yield_extend(kk_trace_new_perturb__trace_fun1627(l1, l2, _ctx), _ctx); /*3991*/
      return kk_std_core__list_unbox(_x1626, _ctx);
    }
    kk_std_core__list ys_1144;
    kk_std_core__list xs0_1145 = kk_std_core__new_Cons(_ru_1463, kk_double_box(x3_1139, _ctx), kk_std_core__new_Nil(_ctx), _ctx); /*list<double>*/;
    ys_1144 = kk_std_core_append(xs0_1145, l2, _ctx); /*list<double>*/
    return kk_std_core_append(l1, ys_1144, _ctx);
  }
  kk_box_t _box_x1305 = div__trace.fst;
  kk_box_t _box_x1306 = div__trace.snd;
  kk_std_core__list l10 = kk_std_core__list_unbox(_box_x1305, NULL);
  kk_std_core__list l20 = kk_std_core__list_unbox(_box_x1306, NULL);
  kk_std_core__list_dup(l10);
  kk_std_core__list_dup(l20);
  kk_std_core_types__tuple2__drop(div__trace, _ctx);
  return kk_std_core__lp__plus__plus__rp_(l10, l20, _ctx);
}
 
// monadic lift

kk_trace__trace kk_trace__mlift1082_mh__step(kk_box_t b, kk_function_t model, kk_std_core__list new__trace, kk_effects_dash_and_dash_types__exp p2, kk_trace__trace trace, bool accept, kk_context_t* _ctx) { /* forall<a,e> (b : a, model : () -> <effects-and-types/sample,effects-and-types/score|e> a, new_trace : effects-and-types/trace_values, p2 : effects-and-types/exp, trace : trace<a,<effects-and-types/sample,effects-and-types/score|e>>, accept : bool) -> <effects-and-types/sample|e> trace<a,<effects-and-types/sample,effects-and-types/score|e>> */ 
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
struct kk_trace__mlift1083_mh__step_fun1638__t {
  struct kk_function_s _base;
};
static kk_box_t kk_trace__mlift1083_mh__step_fun1638(kk_function_t _fself, kk_box_t _b_1316, kk_context_t* _ctx);
static kk_function_t kk_trace__new_mlift1083_mh__step_fun1638(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_trace__mlift1083_mh__step_fun1638, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_trace__mlift1083_mh__step_fun1638(kk_function_t _fself, kk_box_t _b_1316, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x1639;
  kk_effects_dash_and_dash_types__exp _x1640 = kk_effects_dash_and_dash_types__exp_unbox(_b_1316, _ctx); /*effects-and-types/exp*/
  _x1639 = kk_exponents_exp__to__double(_x1640, _ctx); /*double*/
  return kk_double_box(_x1639, _ctx);
}


// lift anonymous function
struct kk_trace__mlift1083_mh__step_fun1646__t {
  struct kk_function_s _base;
};
static kk_box_t kk_trace__mlift1083_mh__step_fun1646(kk_function_t _fself, kk_box_t _b_1319, kk_context_t* _ctx);
static kk_function_t kk_trace__new_mlift1083_mh__step_fun1646(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_trace__mlift1083_mh__step_fun1646, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_trace__mlift1083_mh__step_fun1646(kk_function_t _fself, kk_box_t _b_1319, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x1647;
  kk_effects_dash_and_dash_types__exp _x1648 = kk_effects_dash_and_dash_types__exp_unbox(_b_1319, _ctx); /*effects-and-types/exp*/
  _x1647 = kk_exponents_exp__to__double(_x1648, _ctx); /*double*/
  return kk_double_box(_x1647, _ctx);
}


// lift anonymous function
struct kk_trace__mlift1083_mh__step_fun1654__t {
  struct kk_function_s _base;
  size_t i_1151;
};
static kk_box_t kk_trace__mlift1083_mh__step_fun1654(kk_function_t _fself, kk_function_t _b_1329, kk_box_t _b_1330, kk_context_t* _ctx);
static kk_function_t kk_trace__new_mlift1083_mh__step_fun1654(size_t i_1151, kk_context_t* _ctx) {
  struct kk_trace__mlift1083_mh__step_fun1654__t* _self = kk_function_alloc_as(struct kk_trace__mlift1083_mh__step_fun1654__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_trace__mlift1083_mh__step_fun1654, kk_context());
  _self->i_1151 = i_1151;
  return &_self->_base;
}

static kk_box_t kk_trace__mlift1083_mh__step_fun1654(kk_function_t _fself, kk_function_t _b_1329, kk_box_t _b_1330, kk_context_t* _ctx) {
  struct kk_trace__mlift1083_mh__step_fun1654__t* _self = kk_function_as(struct kk_trace__mlift1083_mh__step_fun1654__t*, _fself);
  size_t i_1151 = _self->i_1151; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_1151, _b_1329, _b_1330, _ctx);
}


// lift anonymous function
struct kk_trace__mlift1083_mh__step_fun1656__t {
  struct kk_function_s _base;
  kk_box_t b;
  kk_function_t model;
  kk_std_core__list new__trace;
  kk_trace__trace trace;
  kk_effects_dash_and_dash_types__exp p2;
};
static kk_box_t kk_trace__mlift1083_mh__step_fun1656(kk_function_t _fself, kk_box_t _b_1340, kk_context_t* _ctx);
static kk_function_t kk_trace__new_mlift1083_mh__step_fun1656(kk_box_t b, kk_function_t model, kk_std_core__list new__trace, kk_trace__trace trace, kk_effects_dash_and_dash_types__exp p2, kk_context_t* _ctx) {
  struct kk_trace__mlift1083_mh__step_fun1656__t* _self = kk_function_alloc_as(struct kk_trace__mlift1083_mh__step_fun1656__t, 5, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_trace__mlift1083_mh__step_fun1656, kk_context());
  _self->b = b;
  _self->model = model;
  _self->new__trace = new__trace;
  _self->trace = trace;
  _self->p2 = p2;
  return &_self->_base;
}

static kk_box_t kk_trace__mlift1083_mh__step_fun1656(kk_function_t _fself, kk_box_t _b_1340, kk_context_t* _ctx) {
  struct kk_trace__mlift1083_mh__step_fun1656__t* _self = kk_function_as(struct kk_trace__mlift1083_mh__step_fun1656__t*, _fself);
  kk_box_t b = _self->b; /* 809 */
  kk_function_t model = _self->model; /* () -> <effects-and-types/sample,effects-and-types/score|810> 809 */
  kk_std_core__list new__trace = _self->new__trace; /* effects-and-types/trace_values */
  kk_trace__trace trace = _self->trace; /* trace/trace<809,<effects-and-types/sample,effects-and-types/score|810>> */
  kk_effects_dash_and_dash_types__exp p2 = _self->p2; /* effects-and-types/exp */
  kk_drop_match(_self, {kk_box_dup(b);kk_function_dup(model);kk_std_core__list_dup(new__trace);kk_trace__trace_dup(trace);kk_effects_dash_and_dash_types__exp_dup(p2);}, {}, _ctx)
  kk_trace__trace _x1657;
  bool _x1658 = kk_bool_unbox(_b_1340); /*bool*/
  _x1657 = kk_trace__mlift1082_mh__step(b, model, new__trace, p2, trace, _x1658, _ctx); /*trace/trace<809,<effects-and-types/sample,effects-and-types/score|810>>*/
  return kk_trace__trace_box(_x1657, _ctx);
}

kk_trace__trace kk_trace__mlift1083_mh__step(kk_function_t model, kk_std_core__list old__trace, kk_effects_dash_and_dash_types__exp p1, kk_trace__trace trace, kk_std_core_types__tuple2_ p2b, kk_context_t* _ctx) { /* forall<a,e> (model : () -> <effects-and-types/sample,effects-and-types/score|e> a, old_trace : effects-and-types/trace_values, p1 : effects-and-types/exp, trace : trace<a,<effects-and-types/sample,effects-and-types/score|e>>, p2b : (effects-and-types/trace_values, (effects-and-types/exp, a))) -> <effects-and-types/sample|e> trace<a,<effects-and-types/sample,effects-and-types/score|e>> */ 
  kk_box_t _box_x1311 = p2b.fst;
  kk_box_t _box_x1312 = p2b.snd;
  kk_std_core__list new__trace = kk_std_core__list_unbox(_box_x1311, NULL);
  kk_std_core_types__tuple2_ _pat3 = kk_std_core_types__tuple2__unbox(_box_x1312, NULL);
  kk_box_t _box_x1313 = _pat3.fst;
  kk_box_t b = _pat3.snd;
  kk_effects_dash_and_dash_types__exp p2 = kk_effects_dash_and_dash_types__exp_unbox(_box_x1313, NULL);
  kk_box_dup(b);
  kk_std_core__list_dup(new__trace);
  kk_std_core_types__tuple2__drop(p2b, _ctx);
  double ratio;
  double y_1148;
  double _x1635;
  double _x1636;
  kk_box_t _x1637 = kk_std_core_hnd__open_none1(kk_trace__new_mlift1083_mh__step_fun1638(_ctx), kk_effects_dash_and_dash_types__exp_box(p2, _ctx), _ctx); /*3239*/
  _x1636 = kk_double_unbox(_x1637, _ctx); /*double*/
  double _x1641;
  kk_integer_t _x1642 = kk_std_core_length_1(old__trace, _ctx); /*int*/
  _x1641 = kk_integer_as_double(_x1642,kk_context()); /*double*/
  _x1635 = (_x1636 * _x1641); /*double*/
  double _x1643;
  double _x1644;
  kk_box_t _x1645 = kk_std_core_hnd__open_none1(kk_trace__new_mlift1083_mh__step_fun1646(_ctx), kk_effects_dash_and_dash_types__exp_box(p1, _ctx), _ctx); /*3239*/
  _x1644 = kk_double_unbox(_x1645, _ctx); /*double*/
  double _x1649;
  kk_integer_t _x1650;
  kk_std_core__list _x1651 = kk_std_core__list_dup(new__trace); /*effects-and-types/trace_values*/
  _x1650 = kk_std_core_length_1(_x1651, _ctx); /*int*/
  _x1649 = kk_integer_as_double(_x1650,kk_context()); /*double*/
  _x1643 = (_x1644 * _x1649); /*double*/
  y_1148 = (_x1635 / _x1643); /*double*/
  bool _match_1485 = (0x1p0 <= y_1148); /*bool*/;
  if (_match_1485) {
    ratio = 0x1p0; /*double*/
  }
  else {
    ratio = y_1148; /*double*/
  }
  bool x0_1149;
  size_t i_1151;
  kk_std_core_hnd__htag _x1652 = kk_std_core_hnd__htag_dup(kk_effects_dash_and_dash_types__tag_sample); /*std/core/hnd/htag<effects-and-types/.hnd-sample>*/
  i_1151 = kk_std_core_hnd__evv_index(_x1652, _ctx); /*std/core/hnd/ev-index*/
  kk_evv_t w = kk_evv_swap_create1(i_1151,kk_context()); /*std/core/hnd/evv<<effects-and-types/sample|810>>*/;
  bool y0 = kk_model_dash_resources_bernoulli(ratio, _ctx); /*bool*/;
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x1653 = kk_std_core_hnd_yield_cont(kk_trace__new_mlift1083_mh__step_fun1654(i_1151, _ctx), _ctx); /*3820*/
    x0_1149 = kk_bool_unbox(_x1653); /*bool*/
  }
  else {
    x0_1149 = y0; /*bool*/
  }
  if (kk_yielding(kk_context())) {
    kk_box_t _x1655 = kk_std_core_hnd_yield_extend(kk_trace__new_mlift1083_mh__step_fun1656(b, model, new__trace, trace, p2, _ctx), _ctx); /*3991*/
    return kk_trace__trace_unbox(_x1655, _ctx);
  }
  return kk_trace__mlift1082_mh__step(b, model, new__trace, p2, trace, x0_1149, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_trace__mlift1084_mh__step_fun1662__t {
  struct kk_function_s _base;
  kk_function_t model;
  kk_std_core__list old__trace;
  kk_trace__trace trace;
  kk_effects_dash_and_dash_types__exp p1;
};
static kk_box_t kk_trace__mlift1084_mh__step_fun1662(kk_function_t _fself, kk_box_t _b_1344, kk_context_t* _ctx);
static kk_function_t kk_trace__new_mlift1084_mh__step_fun1662(kk_function_t model, kk_std_core__list old__trace, kk_trace__trace trace, kk_effects_dash_and_dash_types__exp p1, kk_context_t* _ctx) {
  struct kk_trace__mlift1084_mh__step_fun1662__t* _self = kk_function_alloc_as(struct kk_trace__mlift1084_mh__step_fun1662__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_trace__mlift1084_mh__step_fun1662, kk_context());
  _self->model = model;
  _self->old__trace = old__trace;
  _self->trace = trace;
  _self->p1 = p1;
  return &_self->_base;
}

static kk_box_t kk_trace__mlift1084_mh__step_fun1662(kk_function_t _fself, kk_box_t _b_1344, kk_context_t* _ctx) {
  struct kk_trace__mlift1084_mh__step_fun1662__t* _self = kk_function_as(struct kk_trace__mlift1084_mh__step_fun1662__t*, _fself);
  kk_function_t model = _self->model; /* () -> <effects-and-types/sample,effects-and-types/score|810> 809 */
  kk_std_core__list old__trace = _self->old__trace; /* effects-and-types/trace_values */
  kk_trace__trace trace = _self->trace; /* trace/trace<809,<effects-and-types/sample,effects-and-types/score|810>> */
  kk_effects_dash_and_dash_types__exp p1 = _self->p1; /* effects-and-types/exp */
  kk_drop_match(_self, {kk_function_dup(model);kk_std_core__list_dup(old__trace);kk_trace__trace_dup(trace);kk_effects_dash_and_dash_types__exp_dup(p1);}, {}, _ctx)
  kk_trace__trace _x1663;
  kk_std_core_types__tuple2_ _x1664 = kk_std_core_types__tuple2__unbox(_b_1344, _ctx); /*(effects-and-types/trace_values, (effects-and-types/exp, 809))*/
  _x1663 = kk_trace__mlift1083_mh__step(model, old__trace, p1, trace, _x1664, _ctx); /*trace/trace<809,<effects-and-types/sample,effects-and-types/score|810>>*/
  return kk_trace__trace_box(_x1663, _ctx);
}

kk_trace__trace kk_trace__mlift1084_mh__step(kk_trace__trace trace, kk_std_core__list modified__trace, kk_context_t* _ctx) { /* forall<a,e> (trace : trace<a,<effects-and-types/sample,effects-and-types/score|e>>, modified_trace : effects-and-types/trace_values) -> <effects-and-types/sample|e> trace<a,<effects-and-types/sample,effects-and-types/score|e>> */ 
  struct kk_trace_Trace* _con1659 = kk_trace__as_Trace(trace);
  kk_function_t model = _con1659->m;
  kk_effects_dash_and_dash_types__exp p1 = _con1659->p;
  kk_std_core__list old__trace = _con1659->l;
  kk_function_dup(model);
  kk_std_core__list_dup(old__trace);
  kk_std_core_types__tuple2_ x_1154;
  kk_function_t _x1660 = kk_function_dup(model); /*() -> <effects-and-types/sample,effects-and-types/score|810> 809*/
  x_1154 = kk_trace_with__randomness(_x1660, modified__trace, _ctx); /*(effects-and-types/trace_values, (effects-and-types/exp, 809))*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__tuple2__drop(x_1154, _ctx);
    kk_box_t _x1661 = kk_std_core_hnd_yield_extend(kk_trace__new_mlift1084_mh__step_fun1662(model, old__trace, trace, p1, _ctx), _ctx); /*3991*/
    return kk_trace__trace_unbox(_x1661, _ctx);
  }
  return kk_trace__mlift1083_mh__step(model, old__trace, p1, trace, x_1154, _ctx);
}


// lift anonymous function
struct kk_trace_mh__step_fun1668__t {
  struct kk_function_s _base;
  size_t i_1159;
};
static kk_box_t kk_trace_mh__step_fun1668(kk_function_t _fself, kk_function_t _b_1352, kk_box_t _b_1353, kk_context_t* _ctx);
static kk_function_t kk_trace_new_mh__step_fun1668(size_t i_1159, kk_context_t* _ctx) {
  struct kk_trace_mh__step_fun1668__t* _self = kk_function_alloc_as(struct kk_trace_mh__step_fun1668__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_trace_mh__step_fun1668, kk_context());
  _self->i_1159 = i_1159;
  return &_self->_base;
}

static kk_box_t kk_trace_mh__step_fun1668(kk_function_t _fself, kk_function_t _b_1352, kk_box_t _b_1353, kk_context_t* _ctx) {
  struct kk_trace_mh__step_fun1668__t* _self = kk_function_as(struct kk_trace_mh__step_fun1668__t*, _fself);
  size_t i_1159 = _self->i_1159; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_1159, _b_1352, _b_1353, _ctx);
}


// lift anonymous function
struct kk_trace_mh__step_fun1670__t {
  struct kk_function_s _base;
  kk_trace__trace trace;
};
static kk_box_t kk_trace_mh__step_fun1670(kk_function_t _fself, kk_box_t _b_1363, kk_context_t* _ctx);
static kk_function_t kk_trace_new_mh__step_fun1670(kk_trace__trace trace, kk_context_t* _ctx) {
  struct kk_trace_mh__step_fun1670__t* _self = kk_function_alloc_as(struct kk_trace_mh__step_fun1670__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_trace_mh__step_fun1670, kk_context());
  _self->trace = trace;
  return &_self->_base;
}

static kk_box_t kk_trace_mh__step_fun1670(kk_function_t _fself, kk_box_t _b_1363, kk_context_t* _ctx) {
  struct kk_trace_mh__step_fun1670__t* _self = kk_function_as(struct kk_trace_mh__step_fun1670__t*, _fself);
  kk_trace__trace trace = _self->trace; /* trace/trace<809,<effects-and-types/sample,effects-and-types/score|810>> */
  kk_drop_match(_self, {kk_trace__trace_dup(trace);}, {}, _ctx)
  kk_trace__trace _x1671;
  kk_std_core__list _x1672 = kk_std_core__list_unbox(_b_1363, _ctx); /*effects-and-types/trace_values*/
  _x1671 = kk_trace__mlift1084_mh__step(trace, _x1672, _ctx); /*trace/trace<809,<effects-and-types/sample,effects-and-types/score|810>>*/
  return kk_trace__trace_box(_x1671, _ctx);
}


// lift anonymous function
struct kk_trace_mh__step_fun1677__t {
  struct kk_function_s _base;
  kk_function_t model;
  kk_std_core__list old__trace;
  kk_trace__trace trace;
  kk_effects_dash_and_dash_types__exp p1;
};
static kk_box_t kk_trace_mh__step_fun1677(kk_function_t _fself, kk_box_t _b_1365, kk_context_t* _ctx);
static kk_function_t kk_trace_new_mh__step_fun1677(kk_function_t model, kk_std_core__list old__trace, kk_trace__trace trace, kk_effects_dash_and_dash_types__exp p1, kk_context_t* _ctx) {
  struct kk_trace_mh__step_fun1677__t* _self = kk_function_alloc_as(struct kk_trace_mh__step_fun1677__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_trace_mh__step_fun1677, kk_context());
  _self->model = model;
  _self->old__trace = old__trace;
  _self->trace = trace;
  _self->p1 = p1;
  return &_self->_base;
}

static kk_box_t kk_trace_mh__step_fun1677(kk_function_t _fself, kk_box_t _b_1365, kk_context_t* _ctx) {
  struct kk_trace_mh__step_fun1677__t* _self = kk_function_as(struct kk_trace_mh__step_fun1677__t*, _fself);
  kk_function_t model = _self->model; /* () -> <effects-and-types/sample,effects-and-types/score|810> 809 */
  kk_std_core__list old__trace = _self->old__trace; /* effects-and-types/trace_values */
  kk_trace__trace trace = _self->trace; /* trace/trace<809,<effects-and-types/sample,effects-and-types/score|810>> */
  kk_effects_dash_and_dash_types__exp p1 = _self->p1; /* effects-and-types/exp */
  kk_drop_match(_self, {kk_function_dup(model);kk_std_core__list_dup(old__trace);kk_trace__trace_dup(trace);kk_effects_dash_and_dash_types__exp_dup(p1);}, {}, _ctx)
  kk_trace__trace _x1678;
  kk_std_core_types__tuple2_ _x1679 = kk_std_core_types__tuple2__unbox(_b_1365, _ctx); /*(effects-and-types/trace_values, (effects-and-types/exp, 809))*/
  _x1678 = kk_trace__mlift1083_mh__step(model, old__trace, p1, trace, _x1679, _ctx); /*trace/trace<809,<effects-and-types/sample,effects-and-types/score|810>>*/
  return kk_trace__trace_box(_x1678, _ctx);
}


// lift anonymous function
struct kk_trace_mh__step_fun1686__t {
  struct kk_function_s _base;
};
static kk_box_t kk_trace_mh__step_fun1686(kk_function_t _fself, kk_box_t _b_1371, kk_context_t* _ctx);
static kk_function_t kk_trace_new_mh__step_fun1686(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_trace_mh__step_fun1686, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_trace_mh__step_fun1686(kk_function_t _fself, kk_box_t _b_1371, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x1687;
  kk_effects_dash_and_dash_types__exp _x1688 = kk_effects_dash_and_dash_types__exp_unbox(_b_1371, _ctx); /*effects-and-types/exp*/
  _x1687 = kk_exponents_exp__to__double(_x1688, _ctx); /*double*/
  return kk_double_box(_x1687, _ctx);
}


// lift anonymous function
struct kk_trace_mh__step_fun1694__t {
  struct kk_function_s _base;
};
static kk_box_t kk_trace_mh__step_fun1694(kk_function_t _fself, kk_box_t _b_1374, kk_context_t* _ctx);
static kk_function_t kk_trace_new_mh__step_fun1694(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_trace_mh__step_fun1694, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_trace_mh__step_fun1694(kk_function_t _fself, kk_box_t _b_1374, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  double _x1695;
  kk_effects_dash_and_dash_types__exp _x1696 = kk_effects_dash_and_dash_types__exp_unbox(_b_1374, _ctx); /*effects-and-types/exp*/
  _x1695 = kk_exponents_exp__to__double(_x1696, _ctx); /*double*/
  return kk_double_box(_x1695, _ctx);
}


// lift anonymous function
struct kk_trace_mh__step_fun1702__t {
  struct kk_function_s _base;
  size_t i0_1172;
};
static kk_box_t kk_trace_mh__step_fun1702(kk_function_t _fself, kk_function_t _b_1384, kk_box_t _b_1385, kk_context_t* _ctx);
static kk_function_t kk_trace_new_mh__step_fun1702(size_t i0_1172, kk_context_t* _ctx) {
  struct kk_trace_mh__step_fun1702__t* _self = kk_function_alloc_as(struct kk_trace_mh__step_fun1702__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_trace_mh__step_fun1702, kk_context());
  _self->i0_1172 = i0_1172;
  return &_self->_base;
}

static kk_box_t kk_trace_mh__step_fun1702(kk_function_t _fself, kk_function_t _b_1384, kk_box_t _b_1385, kk_context_t* _ctx) {
  struct kk_trace_mh__step_fun1702__t* _self = kk_function_as(struct kk_trace_mh__step_fun1702__t*, _fself);
  size_t i0_1172 = _self->i0_1172; /* std/core/hnd/ev-index */
  kk_drop_match(_self, {;}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i0_1172, _b_1384, _b_1385, _ctx);
}


// lift anonymous function
struct kk_trace_mh__step_fun1704__t {
  struct kk_function_s _base;
  kk_box_t b;
  kk_function_t model;
  kk_std_core__list new__trace;
  kk_trace__trace trace;
  kk_effects_dash_and_dash_types__exp p2;
};
static kk_box_t kk_trace_mh__step_fun1704(kk_function_t _fself, kk_box_t _b_1395, kk_context_t* _ctx);
static kk_function_t kk_trace_new_mh__step_fun1704(kk_box_t b, kk_function_t model, kk_std_core__list new__trace, kk_trace__trace trace, kk_effects_dash_and_dash_types__exp p2, kk_context_t* _ctx) {
  struct kk_trace_mh__step_fun1704__t* _self = kk_function_alloc_as(struct kk_trace_mh__step_fun1704__t, 5, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_trace_mh__step_fun1704, kk_context());
  _self->b = b;
  _self->model = model;
  _self->new__trace = new__trace;
  _self->trace = trace;
  _self->p2 = p2;
  return &_self->_base;
}

static kk_box_t kk_trace_mh__step_fun1704(kk_function_t _fself, kk_box_t _b_1395, kk_context_t* _ctx) {
  struct kk_trace_mh__step_fun1704__t* _self = kk_function_as(struct kk_trace_mh__step_fun1704__t*, _fself);
  kk_box_t b = _self->b; /* 809 */
  kk_function_t model = _self->model; /* () -> <effects-and-types/sample,effects-and-types/score|810> 809 */
  kk_std_core__list new__trace = _self->new__trace; /* effects-and-types/trace_values */
  kk_trace__trace trace = _self->trace; /* trace/trace<809,<effects-and-types/sample,effects-and-types/score|810>> */
  kk_effects_dash_and_dash_types__exp p2 = _self->p2; /* effects-and-types/exp */
  kk_drop_match(_self, {kk_box_dup(b);kk_function_dup(model);kk_std_core__list_dup(new__trace);kk_trace__trace_dup(trace);kk_effects_dash_and_dash_types__exp_dup(p2);}, {}, _ctx)
  kk_trace__trace _x1705;
  bool _x1706 = kk_bool_unbox(_b_1395); /*bool*/
  _x1705 = kk_trace__mlift1082_mh__step(b, model, new__trace, p2, trace, _x1706, _ctx); /*trace/trace<809,<effects-and-types/sample,effects-and-types/score|810>>*/
  return kk_trace__trace_box(_x1705, _ctx);
}

kk_trace__trace kk_trace_mh__step(kk_trace__trace trace, kk_context_t* _ctx) { /* forall<a,e> (trace : trace<a,<effects-and-types/sample,effects-and-types/score|e>>) -> <effects-and-types/sample|e> trace<a,<effects-and-types/sample,effects-and-types/score|e>> */ 
  kk_std_core__list x_1156;
  size_t i_1159;
  kk_std_core_hnd__htag _x1665 = kk_std_core_hnd__htag_dup(kk_effects_dash_and_dash_types__tag_sample); /*std/core/hnd/htag<effects-and-types/.hnd-sample>*/
  i_1159 = kk_std_core_hnd__evv_index(_x1665, _ctx); /*std/core/hnd/ev-index*/
  kk_evv_t w = kk_evv_swap_create1(i_1159,kk_context()); /*std/core/hnd/evv<<effects-and-types/sample|810>>*/;
  kk_std_core__list y;
  kk_trace__trace _x1666 = kk_trace__trace_dup(trace); /*trace/trace<809,<effects-and-types/sample,effects-and-types/score|810>>*/
  y = kk_trace_perturb__trace(_x1666, _ctx); /*effects-and-types/trace_values*/
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(y, _ctx);
    kk_box_t _x1667 = kk_std_core_hnd_yield_cont(kk_trace_new_mh__step_fun1668(i_1159, _ctx), _ctx); /*3820*/
    x_1156 = kk_std_core__list_unbox(_x1667, _ctx); /*effects-and-types/trace_values*/
  }
  else {
    x_1156 = y; /*effects-and-types/trace_values*/
  }
  if (kk_yielding(kk_context())) {
    kk_std_core__list_drop(x_1156, _ctx);
    kk_box_t _x1669 = kk_std_core_hnd_yield_extend(kk_trace_new_mh__step_fun1670(trace, _ctx), _ctx); /*3991*/
    return kk_trace__trace_unbox(_x1669, _ctx);
  }
  struct kk_trace_Trace* _con1673 = kk_trace__as_Trace(trace);
  kk_function_t model = _con1673->m;
  kk_effects_dash_and_dash_types__exp p1 = _con1673->p;
  kk_std_core__list old__trace = _con1673->l;
  kk_function_dup(model);
  kk_std_core__list_dup(old__trace);
  kk_reuse_t _ru_1465;
  kk_trace__trace _x1674 = kk_trace__trace_dup(trace); /*trace/trace<809,<effects-and-types/sample,effects-and-types/score|810>>*/
  _ru_1465 = kk_trace__trace_dropn_reuse(_x1674, ((int32_t)3), _ctx); /*reuse*/
  kk_std_core_types__tuple2_ x1_1163;
  kk_function_t _x1675 = kk_function_dup(model); /*() -> <effects-and-types/sample,effects-and-types/score|810> 809*/
  x1_1163 = kk_trace_with__randomness(_x1675, x_1156, _ctx); /*(effects-and-types/trace_values, (effects-and-types/exp, 809))*/
  if (kk_yielding(kk_context())) {
    kk_reuse_drop(_ru_1465, _ctx);
    kk_std_core_types__tuple2__drop(x1_1163, _ctx);
    kk_box_t _x1676 = kk_std_core_hnd_yield_extend(kk_trace_new_mh__step_fun1677(model, old__trace, trace, p1, _ctx), _ctx); /*3991*/
    return kk_trace__trace_unbox(_x1676, _ctx);
  }
  kk_box_t _box_x1366 = x1_1163.fst;
  kk_box_t _box_x1367 = x1_1163.snd;
  kk_std_core__list new__trace = kk_std_core__list_unbox(_box_x1366, NULL);
  kk_std_core_types__tuple2_ _pat30 = kk_std_core_types__tuple2__unbox(_box_x1367, NULL);
  kk_box_t _box_x1368 = _pat30.fst;
  kk_box_t b = _pat30.snd;
  kk_effects_dash_and_dash_types__exp p2 = kk_effects_dash_and_dash_types__exp_unbox(_box_x1368, NULL);
  kk_box_dup(b);
  kk_std_core__list_dup(new__trace);
  kk_std_core_types__tuple2__drop(x1_1163, _ctx);
  double ratio;
  double y0_1168;
  double _x1683;
  double _x1684;
  kk_box_t _x1685 = kk_std_core_hnd__open_none1(kk_trace_new_mh__step_fun1686(_ctx), kk_effects_dash_and_dash_types__exp_box(p2, _ctx), _ctx); /*3239*/
  _x1684 = kk_double_unbox(_x1685, _ctx); /*double*/
  double _x1689;
  kk_integer_t _x1690 = kk_std_core_length_1(old__trace, _ctx); /*int*/
  _x1689 = kk_integer_as_double(_x1690,kk_context()); /*double*/
  _x1683 = (_x1684 * _x1689); /*double*/
  double _x1691;
  double _x1692;
  kk_box_t _x1693 = kk_std_core_hnd__open_none1(kk_trace_new_mh__step_fun1694(_ctx), kk_effects_dash_and_dash_types__exp_box(p1, _ctx), _ctx); /*3239*/
  _x1692 = kk_double_unbox(_x1693, _ctx); /*double*/
  double _x1697;
  kk_integer_t _x1698;
  kk_std_core__list _x1699 = kk_std_core__list_dup(new__trace); /*effects-and-types/trace_values*/
  _x1698 = kk_std_core_length_1(_x1699, _ctx); /*int*/
  _x1697 = kk_integer_as_double(_x1698,kk_context()); /*double*/
  _x1691 = (_x1692 * _x1697); /*double*/
  y0_1168 = (_x1683 / _x1691); /*double*/
  bool _match_1480 = (0x1p0 <= y0_1168); /*bool*/;
  if (_match_1480) {
    ratio = 0x1p0; /*double*/
  }
  else {
    ratio = y0_1168; /*double*/
  }
  bool x3_1169;
  size_t i0_1172;
  kk_std_core_hnd__htag _x1700 = kk_std_core_hnd__htag_dup(kk_effects_dash_and_dash_types__tag_sample); /*std/core/hnd/htag<effects-and-types/.hnd-sample>*/
  i0_1172 = kk_std_core_hnd__evv_index(_x1700, _ctx); /*std/core/hnd/ev-index*/
  kk_evv_t w0 = kk_evv_swap_create1(i0_1172,kk_context()); /*std/core/hnd/evv<<effects-and-types/sample|810>>*/;
  bool y1 = kk_model_dash_resources_bernoulli(ratio, _ctx); /*bool*/;
  kk_unit_t __0 = kk_Unit;
  kk_evv_set(w0,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x1701 = kk_std_core_hnd_yield_cont(kk_trace_new_mh__step_fun1702(i0_1172, _ctx), _ctx); /*3820*/
    x3_1169 = kk_bool_unbox(_x1701); /*bool*/
  }
  else {
    x3_1169 = y1; /*bool*/
  }
  if (kk_yielding(kk_context())) {
    kk_reuse_drop(_ru_1465, _ctx);
    kk_box_t _x1703 = kk_std_core_hnd_yield_extend(kk_trace_new_mh__step_fun1704(b, model, new__trace, trace, p2, _ctx), _ctx); /*3991*/
    return kk_trace__trace_unbox(_x1703, _ctx);
  }
  if (x3_1169) {
    kk_trace__trace_dropn(trace, ((int32_t)3), _ctx);
    return kk_trace__new_Trace(_ru_1465, model, p2, new__trace, b, _ctx);
  }
  kk_reuse_drop(_ru_1465, _ctx);
  kk_box_drop(b, _ctx);
  kk_function_drop(model, _ctx);
  kk_std_core__list_drop(new__trace, _ctx);
  return trace;
}
 
// monadic lift

kk_std_core_types__tuple2_ kk_trace__mlift1085_model__stepper__recursive(kk_integer_t burnin, kk_std_core__list posterior, kk_integer_t steps, kk_trace__trace new__trace, kk_context_t* _ctx) { /* forall<a,e> (burnin : int, posterior : list<(list<double>, a)>, steps : int, new_trace : trace<a,<effects-and-types/sample,effects-and-types/score,div|e>>) -> <effects-and-types/sample,div|e> (list<(list<double>, a)>, trace<a,<effects-and-types/sample,effects-and-types/score,div|e>>) */ 
  bool _match_1475;
  kk_integer_t _x1707 = kk_integer_dup(burnin); /*int*/
  _match_1475 = kk_integer_gt(_x1707,(kk_integer_from_small(0)),kk_context()); /*bool*/
  if (_match_1475) {
    kk_integer_t _x1708 = kk_integer_sub(steps,(kk_integer_from_small(1)),kk_context()); /*int*/
    kk_integer_t _x1709 = kk_integer_sub(burnin,(kk_integer_from_small(1)),kk_context()); /*int*/
    return kk_trace_model__stepper__recursive(_x1708, new__trace, posterior, _x1709, _ctx);
  }
  kk_integer_t _x1710 = kk_integer_sub(steps,(kk_integer_from_small(1)),kk_context()); /*int*/
  kk_trace__trace _x1711 = kk_trace__trace_dup(new__trace); /*trace/trace<1007,<effects-and-types/sample,effects-and-types/score,div|1008>>*/
  kk_std_core__list _x1712;
  kk_std_core__list ys_1177;
  kk_std_core_types__tuple2_ _b_1406_1404;
  kk_std_core__list _b_1408_1402;
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*std/core/hnd/evv<(<>)>*/;
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  struct kk_trace_Trace* _con1713 = kk_trace__as_Trace(new__trace);
  kk_effects_dash_and_dash_types__exp _pat10 = _con1713->p;
  kk_std_core__list _x = _con1713->l;
  kk_std_core__list_dup(_x);
  _b_1408_1402 = _x; /*effects-and-types/trace_values*/
  kk_box_t _b_1409_1403;
  kk_evv_t w0 = kk_evv_swap_create0(kk_context()); /*std/core/hnd/evv<(<>)>*/;
  kk_unit_t keep0 = kk_Unit;
  kk_evv_set(w0,kk_context());
  struct kk_trace_Trace* _con1714 = kk_trace__as_Trace(new__trace);
  kk_function_t _pat00 = _con1714->m;
  kk_effects_dash_and_dash_types__exp _pat11 = _con1714->p;
  kk_std_core__list _pat30 = _con1714->l;
  kk_box_t _x0 = _con1714->a;
  if (kk_trace__trace_is_unique(new__trace)) {
    kk_std_core__list_drop(_pat30, _ctx);
    kk_function_drop(_pat00, _ctx);
    kk_trace__trace_free(new__trace);
  }
  else {
    kk_box_dup(_x0);
    kk_trace__trace_decref(new__trace, _ctx);
  }
  _b_1409_1403 = _x0; /*1007*/
  _b_1406_1404 = kk_std_core_types__new_dash__lp__comma__rp_(kk_std_core__list_box(_b_1408_1402, _ctx), _b_1409_1403, _ctx); /*(effects-and-types/trace_values, 1007)*/
  ys_1177 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core_types__tuple2__box(_b_1406_1404, _ctx), kk_std_core__new_Nil(_ctx), _ctx); /*list<(list<double>, 1007)>*/
  _x1712 = kk_std_core_append(posterior, ys_1177, _ctx); /*list<3560>*/
  return kk_trace_model__stepper__recursive(_x1710, _x1711, _x1712, burnin, _ctx);
}


// lift anonymous function
struct kk_trace_model__stepper__recursive_fun1717__t {
  struct kk_function_s _base;
  kk_integer_t burnin0;
  kk_std_core__list posterior0;
  kk_integer_t steps0;
};
static kk_box_t kk_trace_model__stepper__recursive_fun1717(kk_function_t _fself, kk_box_t _b_1413, kk_context_t* _ctx);
static kk_function_t kk_trace_new_model__stepper__recursive_fun1717(kk_integer_t burnin0, kk_std_core__list posterior0, kk_integer_t steps0, kk_context_t* _ctx) {
  struct kk_trace_model__stepper__recursive_fun1717__t* _self = kk_function_alloc_as(struct kk_trace_model__stepper__recursive_fun1717__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_trace_model__stepper__recursive_fun1717, kk_context());
  _self->burnin0 = burnin0;
  _self->posterior0 = posterior0;
  _self->steps0 = steps0;
  return &_self->_base;
}

static kk_box_t kk_trace_model__stepper__recursive_fun1717(kk_function_t _fself, kk_box_t _b_1413, kk_context_t* _ctx) {
  struct kk_trace_model__stepper__recursive_fun1717__t* _self = kk_function_as(struct kk_trace_model__stepper__recursive_fun1717__t*, _fself);
  kk_integer_t burnin0 = _self->burnin0; /* int */
  kk_std_core__list posterior0 = _self->posterior0; /* list<(list<double>, 1007)> */
  kk_integer_t steps0 = _self->steps0; /* int */
  kk_drop_match(_self, {kk_integer_dup(burnin0);kk_std_core__list_dup(posterior0);kk_integer_dup(steps0);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x1718;
  kk_trace__trace _x1719 = kk_trace__trace_unbox(_b_1413, _ctx); /*trace/trace<1007,<effects-and-types/sample,effects-and-types/score,div|1008>>*/
  _x1718 = kk_trace__mlift1085_model__stepper__recursive(burnin0, posterior0, steps0, _x1719, _ctx); /*(list<(list<double>, 1007)>, trace/trace<1007,<effects-and-types/sample,effects-and-types/score,div|1008>>)*/
  return kk_std_core_types__tuple2__box(_x1718, _ctx);
}

kk_std_core_types__tuple2_ kk_trace_model__stepper__recursive(kk_integer_t steps0, kk_trace__trace trace, kk_std_core__list posterior0, kk_integer_t burnin0, kk_context_t* _ctx) { /* forall<a,e> (steps : int, trace : trace<a,<effects-and-types/sample,effects-and-types/score,div|e>>, posterior : list<(list<double>, a)>, burnin : int) -> <effects-and-types/sample,div|e> (list<(list<double>, a)>, trace<a,<effects-and-types/sample,effects-and-types/score,div|e>>) */ 
  kk__tailcall: ;
  bool _match_1472;
  kk_integer_t _x1715 = kk_integer_dup(steps0); /*int*/
  _match_1472 = kk_integer_lt(_x1715,(kk_integer_from_small(1)),kk_context()); /*bool*/
  if (_match_1472) {
    kk_integer_drop(burnin0, _ctx);
    kk_integer_drop(steps0, _ctx);
    return kk_std_core_types__new_dash__lp__comma__rp_(kk_std_core__list_box(posterior0, _ctx), kk_trace__trace_box(trace, _ctx), _ctx);
  }
  kk_trace__trace x_1182 = kk_trace_mh__step(trace, _ctx); /*trace/trace<1007,<effects-and-types/sample,effects-and-types/score,div|1008>>*/;
  if (kk_yielding(kk_context())) {
    kk_trace__trace_dropn(x_1182, ((int32_t)3), _ctx);
    kk_box_t _x1716 = kk_std_core_hnd_yield_extend(kk_trace_new_model__stepper__recursive_fun1717(burnin0, posterior0, steps0, _ctx), _ctx); /*3991*/
    return kk_std_core_types__tuple2__unbox(_x1716, _ctx);
  }
  bool _match_1474;
  kk_integer_t _x1720 = kk_integer_dup(burnin0); /*int*/
  _match_1474 = kk_integer_gt(_x1720,(kk_integer_from_small(0)),kk_context()); /*bool*/
  if (_match_1474) {
    { // tailcall
      kk_integer_t _x1721 = kk_integer_sub(steps0,(kk_integer_from_small(1)),kk_context()); /*int*/
      kk_integer_t _x1722 = kk_integer_sub(burnin0,(kk_integer_from_small(1)),kk_context()); /*int*/
      steps0 = _x1721;
      trace = x_1182;
      burnin0 = _x1722;
      goto kk__tailcall;
    }
  }
  { // tailcall
    kk_integer_t _x1723 = kk_integer_sub(steps0,(kk_integer_from_small(1)),kk_context()); /*int*/
    kk_trace__trace _x1724 = kk_trace__trace_dup(x_1182); /*trace/trace<1007,<effects-and-types/sample,effects-and-types/score,div|1008>>*/
    kk_std_core__list _x1725;
    kk_std_core__list ys_1187;
    kk_std_core_types__tuple2_ _b_1418_1416;
    kk_std_core__list _b_1420_1414;
    kk_evv_t w1 = kk_evv_swap_create0(kk_context()); /*std/core/hnd/evv<(<>)>*/;
    kk_unit_t keep1 = kk_Unit;
    kk_evv_set(w1,kk_context());
    struct kk_trace_Trace* _con1726 = kk_trace__as_Trace(x_1182);
    kk_effects_dash_and_dash_types__exp _pat110 = _con1726->p;
    kk_std_core__list _x1 = _con1726->l;
    kk_std_core__list_dup(_x1);
    _b_1420_1414 = _x1; /*effects-and-types/trace_values*/
    kk_box_t _b_1421_1415;
    kk_evv_t w00 = kk_evv_swap_create0(kk_context()); /*std/core/hnd/evv<(<>)>*/;
    kk_unit_t keep00 = kk_Unit;
    kk_evv_set(w00,kk_context());
    struct kk_trace_Trace* _con1727 = kk_trace__as_Trace(x_1182);
    kk_function_t _pat02 = _con1727->m;
    kk_effects_dash_and_dash_types__exp _pat120 = _con1727->p;
    kk_std_core__list _pat310 = _con1727->l;
    kk_box_t _x00 = _con1727->a;
    if (kk_trace__trace_is_unique(x_1182)) {
      kk_std_core__list_drop(_pat310, _ctx);
      kk_function_drop(_pat02, _ctx);
      kk_trace__trace_free(x_1182);
    }
    else {
      kk_box_dup(_x00);
      kk_trace__trace_decref(x_1182, _ctx);
    }
    _b_1421_1415 = _x00; /*1007*/
    _b_1418_1416 = kk_std_core_types__new_dash__lp__comma__rp_(kk_std_core__list_box(_b_1420_1414, _ctx), _b_1421_1415, _ctx); /*(effects-and-types/trace_values, 1007)*/
    ys_1187 = kk_std_core__new_Cons(kk_reuse_null, kk_std_core_types__tuple2__box(_b_1418_1416, _ctx), kk_std_core__new_Nil(_ctx), _ctx); /*list<(list<double>, 1007)>*/
    _x1725 = kk_std_core_append(posterior0, ys_1187, _ctx); /*list<3560>*/
    steps0 = _x1723;
    trace = _x1724;
    posterior0 = _x1725;
    goto kk__tailcall;
  }
}
 
// monadic lift

kk_std_core_types__tuple2_ kk_trace__mlift1086_tmcmc(kk_integer_t burnin, kk_function_t model, kk_integer_t steps, kk_std_core_types__tuple2_ model__results, kk_context_t* _ctx) { /* forall<a,e> (burnin : int, model : () -> <effects-and-types/sample,effects-and-types/score,div|e> a, steps : int, model_results : (effects-and-types/exp, (list<double>, a))) -> <div,effects-and-types/sample|e> (list<(list<double>, a)>, trace<a,<effects-and-types/sample,effects-and-types/score,div|e>>) */ 
  kk_box_t _box_x1426 = model__results.fst;
  kk_box_t _box_x1427 = model__results.snd;
  kk_effects_dash_and_dash_types__exp p0 = kk_effects_dash_and_dash_types__exp_unbox(_box_x1426, NULL);
  kk_std_core_types__tuple2_ _pat1 = kk_std_core_types__tuple2__unbox(_box_x1427, NULL);
  kk_box_t _box_x1428 = _pat1.fst;
  kk_box_t a0 = _pat1.snd;
  kk_std_core__list d = kk_std_core__list_unbox(_box_x1428, NULL);
  kk_box_dup(a0);
  kk_std_core__list_dup(d);
  kk_std_core_types__tuple2__drop(model__results, _ctx);
  kk_trace__trace _x1731 = kk_trace__new_Trace(kk_reuse_null, model, p0, d, a0, _ctx); /*trace/trace<5,6>*/
  return kk_trace_model__stepper__recursive(steps, _x1731, kk_std_core__new_Nil(_ctx), burnin, _ctx);
}


// lift anonymous function
struct kk_trace_tmcmc_fun1733__t {
  struct kk_function_s _base;
  kk_function_t model;
};
static kk_box_t kk_trace_tmcmc_fun1733(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_trace_new_tmcmc_fun1733(kk_function_t model, kk_context_t* _ctx) {
  struct kk_trace_tmcmc_fun1733__t* _self = kk_function_alloc_as(struct kk_trace_tmcmc_fun1733__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_trace_tmcmc_fun1733, kk_context());
  _self->model = model;
  return &_self->_base;
}



// lift anonymous function
struct kk_trace_tmcmc_fun1735__t {
  struct kk_function_s _base;
  kk_function_t model;
};
static kk_box_t kk_trace_tmcmc_fun1735(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_trace_new_tmcmc_fun1735(kk_function_t model, kk_context_t* _ctx) {
  struct kk_trace_tmcmc_fun1735__t* _self = kk_function_alloc_as(struct kk_trace_tmcmc_fun1735__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_trace_tmcmc_fun1735, kk_context());
  _self->model = model;
  return &_self->_base;
}



// lift anonymous function
struct kk_trace_tmcmc_fun1737__t {
  struct kk_function_s _base;
  kk_function_t model;
};
static kk_box_t kk_trace_tmcmc_fun1737(kk_function_t _fself, kk_box_t _b_1430, kk_context_t* _ctx);
static kk_function_t kk_trace_new_tmcmc_fun1737(kk_function_t model, kk_context_t* _ctx) {
  struct kk_trace_tmcmc_fun1737__t* _self = kk_function_alloc_as(struct kk_trace_tmcmc_fun1737__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_trace_tmcmc_fun1737, kk_context());
  _self->model = model;
  return &_self->_base;
}

static kk_box_t kk_trace_tmcmc_fun1737(kk_function_t _fself, kk_box_t _b_1430, kk_context_t* _ctx) {
  struct kk_trace_tmcmc_fun1737__t* _self = kk_function_as(struct kk_trace_tmcmc_fun1737__t*, _fself);
  kk_function_t model = _self->model; /* () -> <effects-and-types/sample,effects-and-types/score,div|1067> 1066 */
  kk_drop_match(_self, {kk_function_dup(model);}, {}, _ctx)
  size_t _x1738 = kk_size_unbox(_b_1430, _ctx); /*std/core/hnd/ev-index*/
  return kk_handlers__mlift1713_replay(model, _x1738, _ctx);
}
static kk_box_t kk_trace_tmcmc_fun1735(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_trace_tmcmc_fun1735__t* _self = kk_function_as(struct kk_trace_tmcmc_fun1735__t*, _fself);
  kk_function_t model = _self->model; /* () -> <effects-and-types/sample,effects-and-types/score,div|1067> 1066 */
  kk_drop_match(_self, {kk_function_dup(model);}, {}, _ctx)
  size_t x_1791;
  kk_std_core_hnd__htag _x1736 = kk_std_core_hnd__htag_dup(kk_effects_dash_and_dash_types__tag_sample); /*std/core/hnd/htag<effects-and-types/.hnd-sample>*/
  x_1791 = kk_std_core_hnd__evv_index(_x1736, _ctx); /*std/core/hnd/ev-index*/
  if (kk_yielding(kk_context())) {
    return kk_std_core_hnd_yield_extend(kk_trace_new_tmcmc_fun1737(model, _ctx), _ctx);
  }
  return kk_handlers__mlift1713_replay(model, x_1791, _ctx);
}
static kk_box_t kk_trace_tmcmc_fun1733(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_trace_tmcmc_fun1733__t* _self = kk_function_as(struct kk_trace_tmcmc_fun1733__t*, _fself);
  kk_function_t model = _self->model; /* () -> <effects-and-types/sample,effects-and-types/score,div|1067> 1066 */
  kk_drop_match(_self, {kk_function_dup(model);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x1734 = kk_handlers_replayx(kk_std_core__new_Nil(_ctx), kk_trace_new_tmcmc_fun1735(model, _ctx), _ctx); /*(list<double>, 1394)*/
  return kk_std_core_types__tuple2__box(_x1734, _ctx);
}


// lift anonymous function
struct kk_trace_tmcmc_fun1740__t {
  struct kk_function_s _base;
  kk_integer_t burnin;
  kk_function_t model;
  kk_integer_t steps;
};
static kk_box_t kk_trace_tmcmc_fun1740(kk_function_t _fself, kk_box_t _b_1438, kk_context_t* _ctx);
static kk_function_t kk_trace_new_tmcmc_fun1740(kk_integer_t burnin, kk_function_t model, kk_integer_t steps, kk_context_t* _ctx) {
  struct kk_trace_tmcmc_fun1740__t* _self = kk_function_alloc_as(struct kk_trace_tmcmc_fun1740__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_trace_tmcmc_fun1740, kk_context());
  _self->burnin = burnin;
  _self->model = model;
  _self->steps = steps;
  return &_self->_base;
}

static kk_box_t kk_trace_tmcmc_fun1740(kk_function_t _fself, kk_box_t _b_1438, kk_context_t* _ctx) {
  struct kk_trace_tmcmc_fun1740__t* _self = kk_function_as(struct kk_trace_tmcmc_fun1740__t*, _fself);
  kk_integer_t burnin = _self->burnin; /* int */
  kk_function_t model = _self->model; /* () -> <effects-and-types/sample,effects-and-types/score,div|1067> 1066 */
  kk_integer_t steps = _self->steps; /* int */
  kk_drop_match(_self, {kk_integer_dup(burnin);kk_function_dup(model);kk_integer_dup(steps);}, {}, _ctx)
  kk_std_core_types__tuple2_ _x1741;
  kk_std_core_types__tuple2_ _x1742 = kk_std_core_types__tuple2__unbox(_b_1438, _ctx); /*(effects-and-types/exp, (list<double>, 1066))*/
  _x1741 = kk_trace__mlift1086_tmcmc(burnin, model, steps, _x1742, _ctx); /*(list<(list<double>, 1066)>, trace/trace<1066,<effects-and-types/sample,effects-and-types/score,div|1067>>)*/
  return kk_std_core_types__tuple2__box(_x1741, _ctx);
}

kk_std_core_types__tuple2_ kk_trace_tmcmc(kk_function_t model, kk_integer_t steps, kk_effects_dash_and_dash_types__exp init__weight, kk_integer_t burnin, kk_context_t* _ctx) { /* forall<a,e> (model : () -> <effects-and-types/sample,effects-and-types/score,div|e> a, steps : int, init_weight : effects-and-types/exp, burnin : int) -> <effects-and-types/sample,div|e> (list<(list<double>, a)>, trace<a,<effects-and-types/sample,effects-and-types/score,div|e>>) */ 
  kk_std_core_types__tuple2_ x_1192;
  kk_function_t _x1732;
  kk_function_dup(model);
  _x1732 = kk_trace_new_tmcmc_fun1733(model, _ctx); /*() -> <effects-and-types/score|1582> 1581*/
  x_1192 = kk_handlers_weighted(init__weight, _x1732, _ctx); /*(effects-and-types/exp, (list<double>, 1066))*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__tuple2__drop(x_1192, _ctx);
    kk_box_t _x1739 = kk_std_core_hnd_yield_extend(kk_trace_new_tmcmc_fun1740(burnin, model, steps, _ctx), _ctx); /*3991*/
    return kk_std_core_types__tuple2__unbox(_x1739, _ctx);
  }
  kk_box_t _box_x1439 = x_1192.fst;
  kk_box_t _box_x1440 = x_1192.snd;
  kk_effects_dash_and_dash_types__exp p0 = kk_effects_dash_and_dash_types__exp_unbox(_box_x1439, NULL);
  kk_std_core_types__tuple2_ _pat10 = kk_std_core_types__tuple2__unbox(_box_x1440, NULL);
  kk_box_t _box_x1441 = _pat10.fst;
  kk_box_t a0 = _pat10.snd;
  kk_std_core__list d = kk_std_core__list_unbox(_box_x1441, NULL);
  kk_box_dup(a0);
  kk_std_core__list_dup(d);
  kk_std_core_types__tuple2__drop(x_1192, _ctx);
  kk_trace__trace _x1746 = kk_trace__new_Trace(kk_reuse_null, model, p0, d, a0, _ctx); /*trace/trace<5,6>*/
  return kk_trace_model__stepper__recursive(steps, _x1746, kk_std_core__new_Nil(_ctx), burnin, _ctx);
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
