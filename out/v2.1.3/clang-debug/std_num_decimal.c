// Koka generated module: "std/num/decimal", koka version: 2.1.3
#include "std_num_decimal.h"

kk_std_num_decimal__decimal kk_std_num_decimal__copy(kk_std_num_decimal__decimal _this, kk_std_core_types__optional num0, kk_std_core_types__optional exp0, kk_context_t* _ctx) { /* (decimal, num : optional<int>, exp : optional<int>) -> decimal */ 
  kk_integer_t _x6742;
  if (kk_std_core_types__is_Optional(num0)) {
    kk_box_t _box_x6289 = num0._cons.Optional.value;
    kk_integer_t _num_105 = kk_integer_unbox(_box_x6289);
    kk_integer_dup(_num_105);
    kk_std_core_types__optional_drop(num0, _ctx);
    _x6742 = _num_105; /*int*/
    goto _match6743;
  }
  kk_integer_t _x = _this.num;
  kk_integer_dup(_x);
  _x6742 = _x; /*int*/
  _match6743: ;
  kk_integer_t _x6745;
  if (kk_std_core_types__is_Optional(exp0)) {
    kk_box_t _box_x6290 = exp0._cons.Optional.value;
    kk_integer_t _exp_119 = kk_integer_unbox(_box_x6290);
    kk_integer_dup(_exp_119);
    kk_std_core_types__optional_drop(exp0, _ctx);
    kk_std_num_decimal__decimal_drop(_this, _ctx);
    _x6745 = _exp_119; /*int*/
    goto _match6746;
  }
  kk_integer_t _x0 = _this.exp;
  kk_integer_dup(_x0);
  kk_std_num_decimal__decimal_drop(_this, _ctx);
  _x6745 = _x0; /*int*/
  _match6746: ;
  return kk_std_num_decimal__new_Decimal(_x6742, _x6745, _ctx);
}

kk_integer_t kk_std_num_decimal_maxexp;
 
// Is the decimal negative?

bool kk_std_num_decimal_is_neg(kk_std_num_decimal__decimal x, kk_context_t* _ctx) { /* (x : decimal) -> bool */ 
  kk_std_core_types__order x_21555;
  kk_integer_t _x6748;
  kk_integer_t _x = x.num;
  kk_integer_dup(_x);
  kk_std_num_decimal__decimal_drop(x, _ctx);
  _x6748 = _x; /*int*/
  x_21555 = kk_int_as_order(kk_integer_signum(_x6748,kk_context()),kk_context()); /*order*/
  kk_integer_t _x6749 = kk_std_core_int_5(x_21555, _ctx); /*int*/
  kk_integer_t _x6750;
  kk_std_core_types__order _x6751 = kk_std_core_types__new_Lt(_ctx); /*order*/
  if (kk_std_core_types__is_Lt(_x6751)) {
    _x6750 = kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context()); /*int*/
    goto _match6752;
  }
  if (kk_std_core_types__is_Eq(_x6751)) {
    _x6750 = kk_integer_from_small(0); /*int*/
    goto _match6752;
  }
  _x6750 = kk_integer_from_small(1); /*int*/
  _match6752: ;
  return kk_integer_eq(_x6749,_x6750,kk_context());
}
 
// Is the decimal positive?

bool kk_std_num_decimal_is_pos(kk_std_num_decimal__decimal x, kk_context_t* _ctx) { /* (x : decimal) -> bool */ 
  kk_std_core_types__order x_21426;
  kk_integer_t _x6754;
  kk_integer_t _x = x.num;
  kk_integer_dup(_x);
  kk_std_num_decimal__decimal_drop(x, _ctx);
  _x6754 = _x; /*int*/
  x_21426 = kk_int_as_order(kk_integer_signum(_x6754,kk_context()),kk_context()); /*order*/
  kk_integer_t _x6755 = kk_std_core_int_5(x_21426, _ctx); /*int*/
  kk_integer_t _x6756;
  kk_std_core_types__order _x6757 = kk_std_core_types__new_Gt(_ctx); /*order*/
  if (kk_std_core_types__is_Lt(_x6757)) {
    _x6756 = kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context()); /*int*/
    goto _match6758;
  }
  if (kk_std_core_types__is_Eq(_x6757)) {
    _x6756 = kk_integer_from_small(0); /*int*/
    goto _match6758;
  }
  _x6756 = kk_integer_from_small(1); /*int*/
  _match6758: ;
  return kk_integer_eq(_x6755,_x6756,kk_context());
}
 
// round exponents to specific intervals (7) to avoid too much rescaling

kk_integer_t kk_std_num_decimal_round_exp(kk_integer_t exp0, kk_context_t* _ctx) { /* (exp : int) -> int */ 
  bool _match_6739;
  kk_integer_t _x6759 = kk_integer_dup(exp0); /*int*/
  _match_6739 = kk_integer_is_zero(_x6759,kk_context()); /*bool*/
  if (_match_6739) {
    kk_integer_drop(exp0, _ctx);
    return kk_integer_from_small(0);
  }
  kk_integer_t _x6760 = kk_integer_div(exp0,(kk_integer_from_small(7)),kk_context()); /*int*/
  return kk_integer_mul((kk_integer_from_small(7)),_x6760,kk_context());
}
 
// Create a decimal from an integer `i` with an optional
// exponent `exp` (=`0`) such that the result equals `i`&times;10^`exp`^.

kk_std_num_decimal__decimal kk_std_num_decimal_decimal_exp(kk_integer_t i, kk_std_core_types__optional exp0, kk_context_t* _ctx) { /* (i : int, exp : optional<int>) -> decimal */ 
  kk_integer_t x;
  bool _match_6738;
  kk_integer_t _x6761;
  if (kk_std_core_types__is_Optional(exp0)) {
    kk_box_t _box_x6291 = exp0._cons.Optional.value;
    kk_integer_t _exp_1060 = kk_integer_unbox(_box_x6291);
    kk_integer_dup(_exp_1060);
    _x6761 = _exp_1060; /*int*/
    goto _match6762;
  }
  _x6761 = kk_integer_from_small(0); /*int*/
  _match6762: ;
  _match_6738 = kk_integer_is_zero(_x6761,kk_context()); /*bool*/
  if (_match_6738) {
    x = kk_integer_from_small(0); /*int*/
  }
  else {
    kk_integer_t _x6764;
    kk_integer_t _x6765;
    if (kk_std_core_types__is_Optional(exp0)) {
      kk_box_t _box_x6292 = exp0._cons.Optional.value;
      kk_integer_t _exp_10600 = kk_integer_unbox(_box_x6292);
      kk_integer_dup(_exp_10600);
      _x6765 = _exp_10600; /*int*/
      goto _match6766;
    }
    _x6765 = kk_integer_from_small(0); /*int*/
    _match6766: ;
    _x6764 = kk_integer_div(_x6765,(kk_integer_from_small(7)),kk_context()); /*int*/
    x = kk_integer_mul((kk_integer_from_small(7)),_x6764,kk_context()); /*int*/
  }
  kk_integer_t diff;
  kk_integer_t _x6768;
  if (kk_std_core_types__is_Optional(exp0)) {
    kk_box_t _box_x6293 = exp0._cons.Optional.value;
    kk_integer_t _exp_106000 = kk_integer_unbox(_box_x6293);
    kk_integer_dup(_exp_106000);
    _x6768 = _exp_106000; /*int*/
    goto _match6769;
  }
  _x6768 = kk_integer_from_small(0); /*int*/
  _match6769: ;
  kk_integer_t _x6771 = kk_integer_dup(x); /*int*/
  diff = kk_integer_sub(_x6768,_x6771,kk_context()); /*int*/
  bool _match_6737;
  kk_integer_t _x6772 = kk_integer_dup(diff); /*int*/
  _match_6737 = kk_integer_is_zero(_x6772,kk_context()); /*bool*/
  if (_match_6737) {
    kk_integer_drop(diff, _ctx);
    kk_integer_drop(x, _ctx);
    kk_integer_t _x6773;
    if (kk_std_core_types__is_Optional(exp0)) {
      kk_box_t _box_x6294 = exp0._cons.Optional.value;
      kk_integer_t _exp_10601 = kk_integer_unbox(_box_x6294);
      kk_integer_dup(_exp_10601);
      kk_std_core_types__optional_drop(exp0, _ctx);
      _x6773 = _exp_10601; /*int*/
      goto _match6774;
    }
    _x6773 = kk_integer_from_small(0); /*int*/
    _match6774: ;
    return kk_std_num_decimal__new_Decimal(i, _x6773, _ctx);
  }
  kk_std_core_types__optional_drop(exp0, _ctx);
  kk_integer_t _x6776;
  kk_integer_t _x6777 = kk_integer_abs(diff,kk_context()); /*int*/
  _x6776 = kk_std_core_mul_exp10(i, _x6777, _ctx); /*int*/
  return kk_std_num_decimal__new_Decimal(_x6776, x, _ctx);
}
 
// Ensure a decimal `x` has an exponent such that `x.exp <= e`.

kk_std_num_decimal__decimal kk_std_num_decimal_expand(kk_std_num_decimal__decimal x, kk_integer_t e, kk_context_t* _ctx) { /* (x : decimal, e : int) -> decimal */ 
  bool _match_6734;
  kk_integer_t _x6778;
  kk_integer_t _x = x.exp;
  kk_integer_dup(_x);
  _x6778 = _x; /*int*/
  kk_integer_t _x6779 = kk_integer_dup(e); /*int*/
  _match_6734 = kk_integer_lte(_x6778,_x6779,kk_context()); /*bool*/
  if (_match_6734) {
    kk_integer_drop(e, _ctx);
    return x;
  }
  kk_integer_t i_6031;
  kk_integer_t _x6780;
  kk_integer_t _x0 = x.num;
  kk_integer_dup(_x0);
  _x6780 = _x0; /*int*/
  kk_integer_t _x6781;
  kk_integer_t _x6782;
  kk_integer_t _x1 = x.exp;
  kk_integer_dup(_x1);
  kk_std_num_decimal__decimal_drop(x, _ctx);
  _x6782 = _x1; /*int*/
  kk_integer_t _x6783 = kk_integer_dup(e); /*int*/
  _x6781 = kk_integer_sub(_x6782,_x6783,kk_context()); /*int*/
  i_6031 = kk_std_core_mul_exp10(_x6780, _x6781, _ctx); /*int*/
  kk_std_core_types__optional exp_6032 = kk_std_core_types__new_Optional(kk_integer_box(e), _ctx); /*optional<int>*/;
  kk_integer_t x0;
  bool _match_6736;
  kk_integer_t _x6784;
  if (kk_std_core_types__is_Optional(exp_6032)) {
    kk_box_t _box_x6297 = exp_6032._cons.Optional.value;
    kk_integer_t _exp_1060 = kk_integer_unbox(_box_x6297);
    kk_integer_dup(_exp_1060);
    _x6784 = _exp_1060; /*int*/
    goto _match6785;
  }
  _x6784 = kk_integer_from_small(0); /*int*/
  _match6785: ;
  _match_6736 = kk_integer_is_zero(_x6784,kk_context()); /*bool*/
  if (_match_6736) {
    x0 = kk_integer_from_small(0); /*int*/
  }
  else {
    kk_integer_t _x6787;
    kk_integer_t _x6788;
    if (kk_std_core_types__is_Optional(exp_6032)) {
      kk_box_t _box_x6298 = exp_6032._cons.Optional.value;
      kk_integer_t _exp_10600 = kk_integer_unbox(_box_x6298);
      kk_integer_dup(_exp_10600);
      _x6788 = _exp_10600; /*int*/
      goto _match6789;
    }
    _x6788 = kk_integer_from_small(0); /*int*/
    _match6789: ;
    _x6787 = kk_integer_div(_x6788,(kk_integer_from_small(7)),kk_context()); /*int*/
    x0 = kk_integer_mul((kk_integer_from_small(7)),_x6787,kk_context()); /*int*/
  }
  kk_integer_t diff;
  kk_integer_t _x6791;
  if (kk_std_core_types__is_Optional(exp_6032)) {
    kk_box_t _box_x6299 = exp_6032._cons.Optional.value;
    kk_integer_t _exp_106000 = kk_integer_unbox(_box_x6299);
    kk_integer_dup(_exp_106000);
    _x6791 = _exp_106000; /*int*/
    goto _match6792;
  }
  _x6791 = kk_integer_from_small(0); /*int*/
  _match6792: ;
  kk_integer_t _x6794 = kk_integer_dup(x0); /*int*/
  diff = kk_integer_sub(_x6791,_x6794,kk_context()); /*int*/
  bool _match_6735;
  kk_integer_t _x6795 = kk_integer_dup(diff); /*int*/
  _match_6735 = kk_integer_is_zero(_x6795,kk_context()); /*bool*/
  if (_match_6735) {
    kk_integer_drop(diff, _ctx);
    kk_integer_drop(x0, _ctx);
    kk_integer_t _x6796;
    if (kk_std_core_types__is_Optional(exp_6032)) {
      kk_box_t _box_x6300 = exp_6032._cons.Optional.value;
      kk_integer_t _exp_10601 = kk_integer_unbox(_box_x6300);
      kk_integer_dup(_exp_10601);
      kk_std_core_types__optional_drop(exp_6032, _ctx);
      _x6796 = _exp_10601; /*int*/
      goto _match6797;
    }
    _x6796 = kk_integer_from_small(0); /*int*/
    _match6797: ;
    return kk_std_num_decimal__new_Decimal(i_6031, _x6796, _ctx);
  }
  kk_std_core_types__optional_drop(exp_6032, _ctx);
  kk_integer_t _x6799;
  kk_integer_t _x6800 = kk_integer_abs(diff,kk_context()); /*int*/
  _x6799 = kk_std_core_mul_exp10(i_6031, _x6800, _ctx); /*int*/
  return kk_std_num_decimal__new_Decimal(_x6799, x0, _ctx);
}
 
// Compare decimals.

kk_std_core_types__order kk_std_num_decimal_compare(kk_std_num_decimal__decimal x, kk_std_num_decimal__decimal y, kk_context_t* _ctx) { /* (x : decimal, y : decimal) -> order */ 
  kk_integer_t e;
  bool _match_6733;
  kk_integer_t _x6801;
  kk_integer_t _x = x.exp;
  kk_integer_dup(_x);
  _x6801 = _x; /*int*/
  kk_integer_t _x6802;
  kk_integer_t _x0 = y.exp;
  kk_integer_dup(_x0);
  _x6802 = _x0; /*int*/
  _match_6733 = kk_integer_lte(_x6801,_x6802,kk_context()); /*bool*/
  if (_match_6733) {
    kk_integer_t _x1 = x.exp;
    kk_integer_dup(_x1);
    e = _x1; /*int*/
  }
  else {
    kk_integer_t _x00 = y.exp;
    kk_integer_dup(_x00);
    e = _x00; /*int*/
  }
  kk_std_num_decimal__decimal xx;
  kk_integer_t _x6803 = kk_integer_dup(e); /*int*/
  xx = kk_std_num_decimal_expand(x, _x6803, _ctx); /*std/num/decimal/decimal*/
  kk_std_num_decimal__decimal yy = kk_std_num_decimal_expand(y, e, _ctx); /*std/num/decimal/decimal*/;
  kk_integer_t _x6804;
  kk_integer_t _x10 = xx.num;
  kk_integer_dup(_x10);
  kk_std_num_decimal__decimal_drop(xx, _ctx);
  _x6804 = _x10; /*int*/
  kk_integer_t _x6805;
  kk_integer_t _x2 = yy.num;
  kk_integer_dup(_x2);
  kk_std_num_decimal__decimal_drop(yy, _ctx);
  _x6805 = _x2; /*int*/
  return kk_int_as_order(kk_integer_cmp(_x6804,_x6805,kk_context()),kk_context());
}

bool kk_std_num_decimal__lp__excl__eq__rp_(kk_std_num_decimal__decimal x, kk_std_num_decimal__decimal y, kk_context_t* _ctx) { /* (x : decimal, y : decimal) -> bool */ 
  kk_std_core_types__order x0_6042 = kk_std_num_decimal_compare(x, y, _ctx); /*order*/;
  kk_integer_t _x6806 = kk_std_core_int_5(x0_6042, _ctx); /*int*/
  kk_integer_t _x6807;
  kk_std_core_types__order _x6808 = kk_std_core_types__new_Eq(_ctx); /*order*/
  if (kk_std_core_types__is_Lt(_x6808)) {
    _x6807 = kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context()); /*int*/
    goto _match6809;
  }
  if (kk_std_core_types__is_Eq(_x6808)) {
    _x6807 = kk_integer_from_small(0); /*int*/
    goto _match6809;
  }
  _x6807 = kk_integer_from_small(1); /*int*/
  _match6809: ;
  return kk_integer_neq(_x6806,_x6807,kk_context());
}
 
// Choose an exponent that minimizes memory usage.

kk_std_num_decimal__decimal kk_std_num_decimal_reduce(kk_std_num_decimal__decimal x, kk_context_t* _ctx) { /* (x : decimal) -> decimal */ 
  kk_integer_t p;
  kk_integer_t _x6810;
  kk_integer_t _x = x.num;
  kk_integer_dup(_x);
  _x6810 = _x; /*int*/
  p = kk_std_core_is_exp10(_x6810, _ctx); /*int*/
  bool _match_6728;
  bool _x6811;
  kk_integer_t _x6812 = kk_integer_dup(p); /*int*/
  _x6811 = kk_std_core_is_pos_2(_x6812, _ctx); /*bool*/
  _match_6728 = !(_x6811); /*bool*/
  if (_match_6728) {
    kk_integer_drop(p, _ctx);
    return x;
  }
  kk_integer_t expp;
  kk_integer_t _x6813;
  kk_integer_t _x0 = x.exp;
  kk_integer_dup(_x0);
  _x6813 = _x0; /*int*/
  kk_integer_t _x6814 = kk_integer_dup(p); /*int*/
  expp = kk_integer_add(_x6813,_x6814,kk_context()); /*int*/
  bool _match_6729;
  kk_integer_t _x6815;
  kk_integer_t _x6816 = kk_integer_dup(expp); /*int*/
  _x6815 = kk_std_num_decimal_round_exp(_x6816, _ctx); /*int*/
  kk_integer_t _x6817;
  kk_integer_t _x1 = x.exp;
  kk_integer_dup(_x1);
  _x6817 = _x1; /*int*/
  _match_6729 = kk_integer_eq(_x6815,_x6817,kk_context()); /*bool*/
  if (_match_6729) {
    kk_integer_drop(expp, _ctx);
    kk_integer_drop(p, _ctx);
    return x;
  }
  kk_integer_t i_6047;
  kk_integer_t _x6818;
  kk_integer_t _x2 = x.num;
  kk_integer_dup(_x2);
  kk_std_num_decimal__decimal_drop(x, _ctx);
  _x6818 = _x2; /*int*/
  i_6047 = kk_std_core_cdiv_exp10(_x6818, p, _ctx); /*int*/
  kk_std_core_types__optional exp_6048 = kk_std_core_types__new_Optional(kk_integer_box(expp), _ctx); /*optional<int>*/;
  kk_integer_t x0;
  bool _match_6731;
  kk_integer_t _x6819;
  if (kk_std_core_types__is_Optional(exp_6048)) {
    kk_box_t _box_x6303 = exp_6048._cons.Optional.value;
    kk_integer_t _exp_1060 = kk_integer_unbox(_box_x6303);
    kk_integer_dup(_exp_1060);
    _x6819 = _exp_1060; /*int*/
    goto _match6820;
  }
  _x6819 = kk_integer_from_small(0); /*int*/
  _match6820: ;
  _match_6731 = kk_integer_is_zero(_x6819,kk_context()); /*bool*/
  if (_match_6731) {
    x0 = kk_integer_from_small(0); /*int*/
  }
  else {
    kk_integer_t _x6822;
    kk_integer_t _x6823;
    if (kk_std_core_types__is_Optional(exp_6048)) {
      kk_box_t _box_x6304 = exp_6048._cons.Optional.value;
      kk_integer_t _exp_10600 = kk_integer_unbox(_box_x6304);
      kk_integer_dup(_exp_10600);
      _x6823 = _exp_10600; /*int*/
      goto _match6824;
    }
    _x6823 = kk_integer_from_small(0); /*int*/
    _match6824: ;
    _x6822 = kk_integer_div(_x6823,(kk_integer_from_small(7)),kk_context()); /*int*/
    x0 = kk_integer_mul((kk_integer_from_small(7)),_x6822,kk_context()); /*int*/
  }
  kk_integer_t diff;
  kk_integer_t _x6826;
  if (kk_std_core_types__is_Optional(exp_6048)) {
    kk_box_t _box_x6305 = exp_6048._cons.Optional.value;
    kk_integer_t _exp_106000 = kk_integer_unbox(_box_x6305);
    kk_integer_dup(_exp_106000);
    _x6826 = _exp_106000; /*int*/
    goto _match6827;
  }
  _x6826 = kk_integer_from_small(0); /*int*/
  _match6827: ;
  kk_integer_t _x6829 = kk_integer_dup(x0); /*int*/
  diff = kk_integer_sub(_x6826,_x6829,kk_context()); /*int*/
  bool _match_6730;
  kk_integer_t _x6830 = kk_integer_dup(diff); /*int*/
  _match_6730 = kk_integer_is_zero(_x6830,kk_context()); /*bool*/
  if (_match_6730) {
    kk_integer_drop(diff, _ctx);
    kk_integer_drop(x0, _ctx);
    kk_integer_t _x6831;
    if (kk_std_core_types__is_Optional(exp_6048)) {
      kk_box_t _box_x6306 = exp_6048._cons.Optional.value;
      kk_integer_t _exp_10601 = kk_integer_unbox(_box_x6306);
      kk_integer_dup(_exp_10601);
      kk_std_core_types__optional_drop(exp_6048, _ctx);
      _x6831 = _exp_10601; /*int*/
      goto _match6832;
    }
    _x6831 = kk_integer_from_small(0); /*int*/
    _match6832: ;
    return kk_std_num_decimal__new_Decimal(i_6047, _x6831, _ctx);
  }
  kk_std_core_types__optional_drop(exp_6048, _ctx);
  kk_integer_t _x6834;
  kk_integer_t _x6835 = kk_integer_abs(diff,kk_context()); /*int*/
  _x6834 = kk_std_core_mul_exp10(i_6047, _x6835, _ctx); /*int*/
  return kk_std_num_decimal__new_Decimal(_x6834, x0, _ctx);
}
 
// Multiply two decimals with full precision.

kk_std_num_decimal__decimal kk_std_num_decimal__lp__star__rp_(kk_std_num_decimal__decimal x, kk_std_num_decimal__decimal y, kk_context_t* _ctx) { /* (x : decimal, y : decimal) -> decimal */ 
  kk_std_num_decimal__decimal z;
  kk_integer_t i_6051;
  kk_integer_t _x6836;
  kk_integer_t _x = x.num;
  kk_integer_dup(_x);
  _x6836 = _x; /*int*/
  kk_integer_t _x6837;
  kk_integer_t _x0 = y.num;
  kk_integer_dup(_x0);
  _x6837 = _x0; /*int*/
  i_6051 = kk_integer_mul(_x6836,_x6837,kk_context()); /*int*/
  kk_std_core_types__optional exp_6052;
  kk_integer_t _b_6308_6307;
  kk_integer_t _x6838;
  kk_integer_t _x1 = x.exp;
  kk_integer_dup(_x1);
  kk_std_num_decimal__decimal_drop(x, _ctx);
  _x6838 = _x1; /*int*/
  kk_integer_t _x6839;
  kk_integer_t _x2 = y.exp;
  kk_integer_dup(_x2);
  kk_std_num_decimal__decimal_drop(y, _ctx);
  _x6839 = _x2; /*int*/
  _b_6308_6307 = kk_integer_add(_x6838,_x6839,kk_context()); /*int*/
  exp_6052 = kk_std_core_types__new_Optional(kk_integer_box(_b_6308_6307), _ctx); /*optional<int>*/
  kk_integer_t x0;
  bool _match_6727;
  kk_integer_t _x6840;
  if (kk_std_core_types__is_Optional(exp_6052)) {
    kk_box_t _box_x6309 = exp_6052._cons.Optional.value;
    kk_integer_t _exp_1060 = kk_integer_unbox(_box_x6309);
    kk_integer_dup(_exp_1060);
    _x6840 = _exp_1060; /*int*/
    goto _match6841;
  }
  _x6840 = kk_integer_from_small(0); /*int*/
  _match6841: ;
  _match_6727 = kk_integer_is_zero(_x6840,kk_context()); /*bool*/
  if (_match_6727) {
    x0 = kk_integer_from_small(0); /*int*/
  }
  else {
    kk_integer_t _x6843;
    kk_integer_t _x6844;
    if (kk_std_core_types__is_Optional(exp_6052)) {
      kk_box_t _box_x6310 = exp_6052._cons.Optional.value;
      kk_integer_t _exp_10600 = kk_integer_unbox(_box_x6310);
      kk_integer_dup(_exp_10600);
      _x6844 = _exp_10600; /*int*/
      goto _match6845;
    }
    _x6844 = kk_integer_from_small(0); /*int*/
    _match6845: ;
    _x6843 = kk_integer_div(_x6844,(kk_integer_from_small(7)),kk_context()); /*int*/
    x0 = kk_integer_mul((kk_integer_from_small(7)),_x6843,kk_context()); /*int*/
  }
  kk_integer_t diff;
  kk_integer_t _x6847;
  if (kk_std_core_types__is_Optional(exp_6052)) {
    kk_box_t _box_x6311 = exp_6052._cons.Optional.value;
    kk_integer_t _exp_106000 = kk_integer_unbox(_box_x6311);
    kk_integer_dup(_exp_106000);
    _x6847 = _exp_106000; /*int*/
    goto _match6848;
  }
  _x6847 = kk_integer_from_small(0); /*int*/
  _match6848: ;
  kk_integer_t _x6850 = kk_integer_dup(x0); /*int*/
  diff = kk_integer_sub(_x6847,_x6850,kk_context()); /*int*/
  bool _match_6726;
  kk_integer_t _x6851 = kk_integer_dup(diff); /*int*/
  _match_6726 = kk_integer_is_zero(_x6851,kk_context()); /*bool*/
  if (_match_6726) {
    kk_integer_drop(diff, _ctx);
    kk_integer_drop(x0, _ctx);
    kk_integer_t _x6852;
    if (kk_std_core_types__is_Optional(exp_6052)) {
      kk_box_t _box_x6312 = exp_6052._cons.Optional.value;
      kk_integer_t _exp_10601 = kk_integer_unbox(_box_x6312);
      kk_integer_dup(_exp_10601);
      kk_std_core_types__optional_drop(exp_6052, _ctx);
      _x6852 = _exp_10601; /*int*/
      goto _match6853;
    }
    _x6852 = kk_integer_from_small(0); /*int*/
    _match6853: ;
    z = kk_std_num_decimal__new_Decimal(i_6051, _x6852, _ctx); /*std/num/decimal/decimal*/
  }
  else {
    kk_std_core_types__optional_drop(exp_6052, _ctx);
    kk_integer_t _x6855;
    kk_integer_t _x6856 = kk_integer_abs(diff,kk_context()); /*int*/
    _x6855 = kk_std_core_mul_exp10(i_6051, _x6856, _ctx); /*int*/
    z = kk_std_num_decimal__new_Decimal(_x6855, x0, _ctx); /*std/num/decimal/decimal*/
  }
  bool _match_6724;
  kk_std_core_types__order x_21555;
  kk_integer_t _x6857;
  kk_integer_t _x3 = z.exp;
  kk_integer_dup(_x3);
  _x6857 = _x3; /*int*/
  x_21555 = kk_int_as_order(kk_integer_signum(_x6857,kk_context()),kk_context()); /*order*/
  kk_integer_t _x6858 = kk_std_core_int_5(x_21555, _ctx); /*int*/
  kk_integer_t _x6859;
  kk_std_core_types__order _x6860 = kk_std_core_types__new_Lt(_ctx); /*order*/
  if (kk_std_core_types__is_Lt(_x6860)) {
    _x6859 = kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context()); /*int*/
    goto _match6861;
  }
  if (kk_std_core_types__is_Eq(_x6860)) {
    _x6859 = kk_integer_from_small(0); /*int*/
    goto _match6861;
  }
  _x6859 = kk_integer_from_small(1); /*int*/
  _match6861: ;
  _match_6724 = kk_integer_eq(_x6858,_x6859,kk_context()); /*bool*/
  if (_match_6724) {
    return kk_std_num_decimal_reduce(z, _ctx);
  }
  return z;
}
 
// Add two decimals.

kk_std_num_decimal__decimal kk_std_num_decimal__lp__plus__rp_(kk_std_num_decimal__decimal x, kk_std_num_decimal__decimal y, kk_context_t* _ctx) { /* (x : decimal, y : decimal) -> decimal */ 
  kk_integer_t e;
  bool _match_6723;
  kk_integer_t _x6862;
  kk_integer_t _x = x.exp;
  kk_integer_dup(_x);
  _x6862 = _x; /*int*/
  kk_integer_t _x6863;
  kk_integer_t _x0 = y.exp;
  kk_integer_dup(_x0);
  _x6863 = _x0; /*int*/
  _match_6723 = kk_integer_lte(_x6862,_x6863,kk_context()); /*bool*/
  if (_match_6723) {
    kk_integer_t _x1 = x.exp;
    kk_integer_dup(_x1);
    e = _x1; /*int*/
  }
  else {
    kk_integer_t _x00 = y.exp;
    kk_integer_dup(_x00);
    e = _x00; /*int*/
  }
  kk_std_num_decimal__decimal xx;
  kk_integer_t _x6864 = kk_integer_dup(e); /*int*/
  xx = kk_std_num_decimal_expand(x, _x6864, _ctx); /*std/num/decimal/decimal*/
  kk_std_num_decimal__decimal yy;
  kk_integer_t _x6865 = kk_integer_dup(e); /*int*/
  yy = kk_std_num_decimal_expand(y, _x6865, _ctx); /*std/num/decimal/decimal*/
  kk_integer_t _x6866;
  kk_integer_t _x6867;
  kk_integer_t _x10 = xx.num;
  kk_integer_dup(_x10);
  kk_std_num_decimal__decimal_drop(xx, _ctx);
  _x6867 = _x10; /*int*/
  kk_integer_t _x6868;
  kk_integer_t _x2 = yy.num;
  kk_integer_dup(_x2);
  kk_std_num_decimal__decimal_drop(yy, _ctx);
  _x6868 = _x2; /*int*/
  _x6866 = kk_integer_add(_x6867,_x6868,kk_context()); /*int*/
  return kk_std_num_decimal__new_Decimal(_x6866, e, _ctx);
}
 
// Subtract two decimals.

kk_std_num_decimal__decimal kk_std_num_decimal__lp__dash__rp_(kk_std_num_decimal__decimal x, kk_std_num_decimal__decimal y, kk_context_t* _ctx) { /* (x : decimal, y : decimal) -> decimal */ 
  kk_std_num_decimal__decimal y0_6069 = kk_std_num_decimal__lp__tilde__rp_(y, _ctx); /*std/num/decimal/decimal*/;
  kk_integer_t e;
  bool _match_6722;
  kk_integer_t _x6872;
  kk_integer_t _x = x.exp;
  kk_integer_dup(_x);
  _x6872 = _x; /*int*/
  kk_integer_t _x6873;
  kk_integer_t _x0 = y0_6069.exp;
  kk_integer_dup(_x0);
  _x6873 = _x0; /*int*/
  _match_6722 = kk_integer_lte(_x6872,_x6873,kk_context()); /*bool*/
  if (_match_6722) {
    kk_integer_t _x1 = x.exp;
    kk_integer_dup(_x1);
    e = _x1; /*int*/
  }
  else {
    kk_integer_t _x00 = y0_6069.exp;
    kk_integer_dup(_x00);
    e = _x00; /*int*/
  }
  kk_std_num_decimal__decimal xx;
  kk_integer_t _x6874 = kk_integer_dup(e); /*int*/
  xx = kk_std_num_decimal_expand(x, _x6874, _ctx); /*std/num/decimal/decimal*/
  kk_std_num_decimal__decimal yy;
  kk_integer_t _x6875 = kk_integer_dup(e); /*int*/
  yy = kk_std_num_decimal_expand(y0_6069, _x6875, _ctx); /*std/num/decimal/decimal*/
  kk_integer_t _x6876;
  kk_integer_t _x6877;
  kk_integer_t _x10 = xx.num;
  kk_integer_dup(_x10);
  kk_std_num_decimal__decimal_drop(xx, _ctx);
  _x6877 = _x10; /*int*/
  kk_integer_t _x6878;
  kk_integer_t _x2 = yy.num;
  kk_integer_dup(_x2);
  kk_std_num_decimal__decimal_drop(yy, _ctx);
  _x6878 = _x2; /*int*/
  _x6876 = kk_integer_add(_x6877,_x6878,kk_context()); /*int*/
  return kk_std_num_decimal__new_Decimal(_x6876, e, _ctx);
}

kk_std_num_decimal__decimal kk_std_num_decimal_zero;
 
/* Divide two decimals with a given extra precision `min-prec` (=`15`).
The `min-prec` is the number of extra digits used to calculate inexact
divisions.
Note: the division uses up to `min-prec` precision using `Floor` rounding
for the last digit if the result is  inexact. To round differently, you can
for example divide with larger precision and use `round-to-prec`.
```
> div( decimal(2), decimal(3), 0 )
0
> div( decimal(2), decimal(3), 1 )
0.6
> div( decimal(2), decimal(3) )  // default precision is 15
0.6666666666666666
> div( decimal(2), decimal(3) ).round-to-prec(6)
0.666667
```
.
*/

kk_std_num_decimal__decimal kk_std_num_decimal_div(kk_std_num_decimal__decimal x, kk_std_num_decimal__decimal y, kk_std_core_types__optional min_prec, kk_context_t* _ctx) { /* (x : decimal, y : decimal, min-prec : optional<int>) -> decimal */ 
  bool _match_6714;
  bool _match_6721;
  kk_std_num_decimal__decimal _x6879 = kk_std_num_decimal__decimal_dup(x); /*std/num/decimal/decimal*/
  _match_6721 = kk_std_num_decimal_is_zero(_x6879, _ctx); /*bool*/
  if (_match_6721) {
    _match_6714 = true; /*bool*/
  }
  else {
    kk_std_num_decimal__decimal _x6880 = kk_std_num_decimal__decimal_dup(y); /*std/num/decimal/decimal*/
    _match_6714 = kk_std_num_decimal_is_zero(_x6880, _ctx); /*bool*/
  }
  if (_match_6714) {
    kk_std_core_types__optional_drop(min_prec, _ctx);
    kk_std_num_decimal__decimal_drop(x, _ctx);
    kk_std_num_decimal__decimal_drop(y, _ctx);
    return kk_std_num_decimal__new_Decimal(kk_integer_from_small(0), kk_integer_from_small(0), _ctx);
  }
  kk_integer_t e;
  kk_integer_t _x6881;
  kk_integer_t _x = x.exp;
  kk_integer_dup(_x);
  _x6881 = _x; /*int*/
  kk_integer_t _x6882;
  kk_integer_t _x0 = y.exp;
  kk_integer_dup(_x0);
  _x6882 = _x0; /*int*/
  e = kk_integer_sub(_x6881,_x6882,kk_context()); /*int*/
  kk_integer_t xdigits;
  kk_integer_t _x6883;
  kk_integer_t _x1 = x.num;
  kk_integer_dup(_x1);
  _x6883 = _x1; /*int*/
  xdigits = kk_std_core_count_digits(_x6883, _ctx); /*int*/
  kk_integer_t ydigits;
  kk_integer_t _x6884;
  kk_integer_t _x2 = y.num;
  kk_integer_dup(_x2);
  _x6884 = _x2; /*int*/
  ydigits = kk_std_core_count_digits(_x6884, _ctx); /*int*/
  kk_integer_t extra;
  kk_integer_t _x6885;
  kk_integer_t j_6081 = kk_integer_sub(ydigits,xdigits,kk_context()); /*int*/;
  bool _match_6720;
  kk_integer_t _x6886 = kk_integer_dup(j_6081); /*int*/
  _match_6720 = kk_integer_gte((kk_integer_from_small(0)),_x6886,kk_context()); /*bool*/
  if (_match_6720) {
    kk_integer_drop(j_6081, _ctx);
    _x6885 = kk_integer_from_small(0); /*int*/
  }
  else {
    _x6885 = j_6081; /*int*/
  }
  kk_integer_t _x6887;
  if (kk_std_core_types__is_Optional(min_prec)) {
    kk_box_t _box_x6313 = min_prec._cons.Optional.value;
    kk_integer_t _min_prec_1157 = kk_integer_unbox(_box_x6313);
    kk_integer_dup(_min_prec_1157);
    kk_std_core_types__optional_drop(min_prec, _ctx);
    _x6887 = _min_prec_1157; /*int*/
    goto _match6888;
  }
  _x6887 = kk_integer_from_small(15); /*int*/
  _match6888: ;
  extra = kk_integer_add(_x6885,_x6887,kk_context()); /*int*/
  kk_std_num_decimal__decimal _x6890;
  bool _match_6715;
  kk_integer_t _x6891 = kk_integer_dup(extra); /*int*/
  _match_6715 = kk_integer_gt(_x6891,(kk_integer_from_small(0)),kk_context()); /*bool*/
  if (_match_6715) {
    kk_integer_t i0_6082;
    kk_integer_t _x6892;
    kk_integer_t _x6893;
    kk_integer_t _x3 = x.num;
    kk_integer_dup(_x3);
    kk_std_num_decimal__decimal_drop(x, _ctx);
    _x6893 = _x3; /*int*/
    kk_integer_t _x6894 = kk_integer_dup(extra); /*int*/
    _x6892 = kk_std_core_mul_exp10(_x6893, _x6894, _ctx); /*int*/
    kk_integer_t _x6895;
    kk_integer_t _x4 = y.num;
    kk_integer_dup(_x4);
    kk_std_num_decimal__decimal_drop(y, _ctx);
    _x6895 = _x4; /*int*/
    i0_6082 = kk_integer_div(_x6892,_x6895,kk_context()); /*int*/
    kk_std_core_types__optional exp_6083;
    kk_integer_t _b_6315_6314 = kk_integer_sub(e,extra,kk_context()); /*int*/;
    exp_6083 = kk_std_core_types__new_Optional(kk_integer_box(_b_6315_6314), _ctx); /*optional<int>*/
    kk_integer_t x0;
    bool _match_6719;
    kk_integer_t _x6896;
    if (kk_std_core_types__is_Optional(exp_6083)) {
      kk_box_t _box_x6316 = exp_6083._cons.Optional.value;
      kk_integer_t _exp_1060 = kk_integer_unbox(_box_x6316);
      kk_integer_dup(_exp_1060);
      _x6896 = _exp_1060; /*int*/
      goto _match6897;
    }
    _x6896 = kk_integer_from_small(0); /*int*/
    _match6897: ;
    _match_6719 = kk_integer_is_zero(_x6896,kk_context()); /*bool*/
    if (_match_6719) {
      x0 = kk_integer_from_small(0); /*int*/
    }
    else {
      kk_integer_t _x6899;
      kk_integer_t _x6900;
      if (kk_std_core_types__is_Optional(exp_6083)) {
        kk_box_t _box_x6317 = exp_6083._cons.Optional.value;
        kk_integer_t _exp_10600 = kk_integer_unbox(_box_x6317);
        kk_integer_dup(_exp_10600);
        _x6900 = _exp_10600; /*int*/
        goto _match6901;
      }
      _x6900 = kk_integer_from_small(0); /*int*/
      _match6901: ;
      _x6899 = kk_integer_div(_x6900,(kk_integer_from_small(7)),kk_context()); /*int*/
      x0 = kk_integer_mul((kk_integer_from_small(7)),_x6899,kk_context()); /*int*/
    }
    kk_integer_t diff;
    kk_integer_t _x6903;
    if (kk_std_core_types__is_Optional(exp_6083)) {
      kk_box_t _box_x6318 = exp_6083._cons.Optional.value;
      kk_integer_t _exp_106000 = kk_integer_unbox(_box_x6318);
      kk_integer_dup(_exp_106000);
      _x6903 = _exp_106000; /*int*/
      goto _match6904;
    }
    _x6903 = kk_integer_from_small(0); /*int*/
    _match6904: ;
    kk_integer_t _x6906 = kk_integer_dup(x0); /*int*/
    diff = kk_integer_sub(_x6903,_x6906,kk_context()); /*int*/
    bool _match_6718;
    kk_integer_t _x6907 = kk_integer_dup(diff); /*int*/
    _match_6718 = kk_integer_is_zero(_x6907,kk_context()); /*bool*/
    if (_match_6718) {
      kk_integer_drop(diff, _ctx);
      kk_integer_drop(x0, _ctx);
      kk_integer_t _x6908;
      if (kk_std_core_types__is_Optional(exp_6083)) {
        kk_box_t _box_x6319 = exp_6083._cons.Optional.value;
        kk_integer_t _exp_10601 = kk_integer_unbox(_box_x6319);
        kk_integer_dup(_exp_10601);
        kk_std_core_types__optional_drop(exp_6083, _ctx);
        _x6908 = _exp_10601; /*int*/
        goto _match6909;
      }
      _x6908 = kk_integer_from_small(0); /*int*/
      _match6909: ;
      _x6890 = kk_std_num_decimal__new_Decimal(i0_6082, _x6908, _ctx); /*std/num/decimal/decimal*/
    }
    else {
      kk_std_core_types__optional_drop(exp_6083, _ctx);
      kk_integer_t _x6911;
      kk_integer_t _x6912 = kk_integer_abs(diff,kk_context()); /*int*/
      _x6911 = kk_std_core_mul_exp10(i0_6082, _x6912, _ctx); /*int*/
      _x6890 = kk_std_num_decimal__new_Decimal(_x6911, x0, _ctx); /*std/num/decimal/decimal*/
    }
  }
  else {
    kk_integer_t i1_6087;
    kk_integer_t _x6913;
    kk_integer_t _x5 = x.num;
    kk_integer_dup(_x5);
    kk_std_num_decimal__decimal_drop(x, _ctx);
    _x6913 = _x5; /*int*/
    kk_integer_t _x6914;
    kk_integer_t _x6 = y.num;
    kk_integer_dup(_x6);
    kk_std_num_decimal__decimal_drop(y, _ctx);
    _x6914 = _x6; /*int*/
    i1_6087 = kk_integer_div(_x6913,_x6914,kk_context()); /*int*/
    kk_std_core_types__optional exp1_6088;
    kk_integer_t _b_6321_6320 = kk_integer_sub(e,extra,kk_context()); /*int*/;
    exp1_6088 = kk_std_core_types__new_Optional(kk_integer_box(_b_6321_6320), _ctx); /*optional<int>*/
    kk_integer_t x1;
    bool _match_6717;
    kk_integer_t _x6915;
    if (kk_std_core_types__is_Optional(exp1_6088)) {
      kk_box_t _box_x6322 = exp1_6088._cons.Optional.value;
      kk_integer_t _exp_10602 = kk_integer_unbox(_box_x6322);
      kk_integer_dup(_exp_10602);
      _x6915 = _exp_10602; /*int*/
      goto _match6916;
    }
    _x6915 = kk_integer_from_small(0); /*int*/
    _match6916: ;
    _match_6717 = kk_integer_is_zero(_x6915,kk_context()); /*bool*/
    if (_match_6717) {
      x1 = kk_integer_from_small(0); /*int*/
    }
    else {
      kk_integer_t _x6918;
      kk_integer_t _x6919;
      if (kk_std_core_types__is_Optional(exp1_6088)) {
        kk_box_t _box_x6323 = exp1_6088._cons.Optional.value;
        kk_integer_t _exp_106020 = kk_integer_unbox(_box_x6323);
        kk_integer_dup(_exp_106020);
        _x6919 = _exp_106020; /*int*/
        goto _match6920;
      }
      _x6919 = kk_integer_from_small(0); /*int*/
      _match6920: ;
      _x6918 = kk_integer_div(_x6919,(kk_integer_from_small(7)),kk_context()); /*int*/
      x1 = kk_integer_mul((kk_integer_from_small(7)),_x6918,kk_context()); /*int*/
    }
    kk_integer_t diff0;
    kk_integer_t _x6922;
    if (kk_std_core_types__is_Optional(exp1_6088)) {
      kk_box_t _box_x6324 = exp1_6088._cons.Optional.value;
      kk_integer_t _exp_10603 = kk_integer_unbox(_box_x6324);
      kk_integer_dup(_exp_10603);
      _x6922 = _exp_10603; /*int*/
      goto _match6923;
    }
    _x6922 = kk_integer_from_small(0); /*int*/
    _match6923: ;
    kk_integer_t _x6925 = kk_integer_dup(x1); /*int*/
    diff0 = kk_integer_sub(_x6922,_x6925,kk_context()); /*int*/
    bool _match_6716;
    kk_integer_t _x6926 = kk_integer_dup(diff0); /*int*/
    _match_6716 = kk_integer_is_zero(_x6926,kk_context()); /*bool*/
    if (_match_6716) {
      kk_integer_drop(diff0, _ctx);
      kk_integer_drop(x1, _ctx);
      kk_integer_t _x6927;
      if (kk_std_core_types__is_Optional(exp1_6088)) {
        kk_box_t _box_x6325 = exp1_6088._cons.Optional.value;
        kk_integer_t _exp_10604 = kk_integer_unbox(_box_x6325);
        kk_integer_dup(_exp_10604);
        kk_std_core_types__optional_drop(exp1_6088, _ctx);
        _x6927 = _exp_10604; /*int*/
        goto _match6928;
      }
      _x6927 = kk_integer_from_small(0); /*int*/
      _match6928: ;
      _x6890 = kk_std_num_decimal__new_Decimal(i1_6087, _x6927, _ctx); /*std/num/decimal/decimal*/
    }
    else {
      kk_std_core_types__optional_drop(exp1_6088, _ctx);
      kk_integer_t _x6930;
      kk_integer_t _x6931 = kk_integer_abs(diff0,kk_context()); /*int*/
      _x6930 = kk_std_core_mul_exp10(i1_6087, _x6931, _ctx); /*int*/
      _x6890 = kk_std_num_decimal__new_Decimal(_x6930, x1, _ctx); /*std/num/decimal/decimal*/
    }
  }
  return kk_std_num_decimal_reduce(_x6890, _ctx);
}

bool kk_std_num_decimal__lp__lt__rp_(kk_std_num_decimal__decimal x, kk_std_num_decimal__decimal y, kk_context_t* _ctx) { /* (x : decimal, y : decimal) -> bool */ 
  kk_std_core_types__order x0_6092 = kk_std_num_decimal_compare(x, y, _ctx); /*order*/;
  kk_integer_t _x6932 = kk_std_core_int_5(x0_6092, _ctx); /*int*/
  kk_integer_t _x6933;
  kk_std_core_types__order _x6934 = kk_std_core_types__new_Lt(_ctx); /*order*/
  if (kk_std_core_types__is_Lt(_x6934)) {
    _x6933 = kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context()); /*int*/
    goto _match6935;
  }
  if (kk_std_core_types__is_Eq(_x6934)) {
    _x6933 = kk_integer_from_small(0); /*int*/
    goto _match6935;
  }
  _x6933 = kk_integer_from_small(1); /*int*/
  _match6935: ;
  return kk_integer_eq(_x6932,_x6933,kk_context());
}

bool kk_std_num_decimal__lp__lt__eq__rp_(kk_std_num_decimal__decimal x, kk_std_num_decimal__decimal y, kk_context_t* _ctx) { /* (x : decimal, y : decimal) -> bool */ 
  kk_std_core_types__order x0_6094 = kk_std_num_decimal_compare(x, y, _ctx); /*order*/;
  kk_integer_t _x6936 = kk_std_core_int_5(x0_6094, _ctx); /*int*/
  kk_integer_t _x6937;
  kk_std_core_types__order _x6938 = kk_std_core_types__new_Gt(_ctx); /*order*/
  if (kk_std_core_types__is_Lt(_x6938)) {
    _x6937 = kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context()); /*int*/
    goto _match6939;
  }
  if (kk_std_core_types__is_Eq(_x6938)) {
    _x6937 = kk_integer_from_small(0); /*int*/
    goto _match6939;
  }
  _x6937 = kk_integer_from_small(1); /*int*/
  _match6939: ;
  return kk_integer_neq(_x6936,_x6937,kk_context());
}

bool kk_std_num_decimal__lp__eq__eq__rp_(kk_std_num_decimal__decimal x, kk_std_num_decimal__decimal y, kk_context_t* _ctx) { /* (x : decimal, y : decimal) -> bool */ 
  kk_std_core_types__order x0_6096 = kk_std_num_decimal_compare(x, y, _ctx); /*order*/;
  kk_integer_t _x6940 = kk_std_core_int_5(x0_6096, _ctx); /*int*/
  kk_integer_t _x6941;
  kk_std_core_types__order _x6942 = kk_std_core_types__new_Eq(_ctx); /*order*/
  if (kk_std_core_types__is_Lt(_x6942)) {
    _x6941 = kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context()); /*int*/
    goto _match6943;
  }
  if (kk_std_core_types__is_Eq(_x6942)) {
    _x6941 = kk_integer_from_small(0); /*int*/
    goto _match6943;
  }
  _x6941 = kk_integer_from_small(1); /*int*/
  _match6943: ;
  return kk_integer_eq(_x6940,_x6941,kk_context());
}

bool kk_std_num_decimal__lp__gt__rp_(kk_std_num_decimal__decimal x, kk_std_num_decimal__decimal y, kk_context_t* _ctx) { /* (x : decimal, y : decimal) -> bool */ 
  kk_std_core_types__order x0_6098 = kk_std_num_decimal_compare(x, y, _ctx); /*order*/;
  kk_integer_t _x6944 = kk_std_core_int_5(x0_6098, _ctx); /*int*/
  kk_integer_t _x6945;
  kk_std_core_types__order _x6946 = kk_std_core_types__new_Gt(_ctx); /*order*/
  if (kk_std_core_types__is_Lt(_x6946)) {
    _x6945 = kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context()); /*int*/
    goto _match6947;
  }
  if (kk_std_core_types__is_Eq(_x6946)) {
    _x6945 = kk_integer_from_small(0); /*int*/
    goto _match6947;
  }
  _x6945 = kk_integer_from_small(1); /*int*/
  _match6947: ;
  return kk_integer_eq(_x6944,_x6945,kk_context());
}

bool kk_std_num_decimal__lp__gt__eq__rp_(kk_std_num_decimal__decimal x, kk_std_num_decimal__decimal y, kk_context_t* _ctx) { /* (x : decimal, y : decimal) -> bool */ 
  kk_std_core_types__order x0_6100 = kk_std_num_decimal_compare(x, y, _ctx); /*order*/;
  kk_integer_t _x6948 = kk_std_core_int_5(x0_6100, _ctx); /*int*/
  kk_integer_t _x6949;
  kk_std_core_types__order _x6950 = kk_std_core_types__new_Lt(_ctx); /*order*/
  if (kk_std_core_types__is_Lt(_x6950)) {
    _x6949 = kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context()); /*int*/
    goto _match6951;
  }
  if (kk_std_core_types__is_Eq(_x6950)) {
    _x6949 = kk_integer_from_small(0); /*int*/
    goto _match6951;
  }
  _x6949 = kk_integer_from_small(1); /*int*/
  _match6951: ;
  return kk_integer_neq(_x6948,_x6949,kk_context());
}
 
// Create a decimal from an integer `i` with an optional
// exponent `exp` (=`0`) such that the result equals `i`&times;10^`exp`^.

kk_std_num_decimal__decimal kk_std_num_decimal_decimal(kk_integer_t i, kk_std_core_types__optional exp0, kk_context_t* _ctx) { /* (i : int, exp : optional<int>) -> decimal */ 
  kk_std_core_types__optional exp0_6103;
  kk_box_t _x6953;
  kk_integer_t _x6954;
  if (kk_std_core_types__is_Optional(exp0)) {
    kk_box_t _box_x6326 = exp0._cons.Optional.value;
    kk_integer_t _exp_785 = kk_integer_unbox(_box_x6326);
    kk_integer_dup(_exp_785);
    kk_std_core_types__optional_drop(exp0, _ctx);
    _x6954 = _exp_785; /*int*/
    goto _match6955;
  }
  _x6954 = kk_integer_from_small(0); /*int*/
  _match6955: ;
  _x6953 = kk_integer_box(_x6954); /*35*/
  exp0_6103 = kk_std_core_types__new_Optional(_x6953, _ctx); /*optional<int>*/
  kk_integer_t x;
  bool _match_6707;
  kk_integer_t _x6957;
  if (kk_std_core_types__is_Optional(exp0_6103)) {
    kk_box_t _box_x6329 = exp0_6103._cons.Optional.value;
    kk_integer_t _exp_1060 = kk_integer_unbox(_box_x6329);
    kk_integer_dup(_exp_1060);
    _x6957 = _exp_1060; /*int*/
    goto _match6958;
  }
  _x6957 = kk_integer_from_small(0); /*int*/
  _match6958: ;
  _match_6707 = kk_integer_is_zero(_x6957,kk_context()); /*bool*/
  if (_match_6707) {
    x = kk_integer_from_small(0); /*int*/
  }
  else {
    kk_integer_t _x6960;
    kk_integer_t _x6961;
    if (kk_std_core_types__is_Optional(exp0_6103)) {
      kk_box_t _box_x6330 = exp0_6103._cons.Optional.value;
      kk_integer_t _exp_10600 = kk_integer_unbox(_box_x6330);
      kk_integer_dup(_exp_10600);
      _x6961 = _exp_10600; /*int*/
      goto _match6962;
    }
    _x6961 = kk_integer_from_small(0); /*int*/
    _match6962: ;
    _x6960 = kk_integer_div(_x6961,(kk_integer_from_small(7)),kk_context()); /*int*/
    x = kk_integer_mul((kk_integer_from_small(7)),_x6960,kk_context()); /*int*/
  }
  kk_integer_t diff;
  kk_integer_t _x6964;
  if (kk_std_core_types__is_Optional(exp0_6103)) {
    kk_box_t _box_x6331 = exp0_6103._cons.Optional.value;
    kk_integer_t _exp_106000 = kk_integer_unbox(_box_x6331);
    kk_integer_dup(_exp_106000);
    _x6964 = _exp_106000; /*int*/
    goto _match6965;
  }
  _x6964 = kk_integer_from_small(0); /*int*/
  _match6965: ;
  kk_integer_t _x6967 = kk_integer_dup(x); /*int*/
  diff = kk_integer_sub(_x6964,_x6967,kk_context()); /*int*/
  bool _match_6706;
  kk_integer_t _x6968 = kk_integer_dup(diff); /*int*/
  _match_6706 = kk_integer_is_zero(_x6968,kk_context()); /*bool*/
  if (_match_6706) {
    kk_integer_drop(diff, _ctx);
    kk_integer_drop(x, _ctx);
    kk_integer_t _x6969;
    if (kk_std_core_types__is_Optional(exp0_6103)) {
      kk_box_t _box_x6332 = exp0_6103._cons.Optional.value;
      kk_integer_t _exp_10601 = kk_integer_unbox(_box_x6332);
      kk_integer_dup(_exp_10601);
      kk_std_core_types__optional_drop(exp0_6103, _ctx);
      _x6969 = _exp_10601; /*int*/
      goto _match6970;
    }
    _x6969 = kk_integer_from_small(0); /*int*/
    _match6970: ;
    return kk_std_num_decimal__new_Decimal(i, _x6969, _ctx);
  }
  kk_std_core_types__optional_drop(exp0_6103, _ctx);
  kk_integer_t _x6972;
  kk_integer_t _x6973 = kk_integer_abs(diff,kk_context()); /*int*/
  _x6972 = kk_std_core_mul_exp10(i, _x6973, _ctx); /*int*/
  return kk_std_num_decimal__new_Decimal(_x6972, x, _ctx);
}
 
// Decimal to the power of `n`

kk_std_num_decimal__decimal kk_std_num_decimal_pow(kk_std_num_decimal__decimal x, kk_integer_t n, kk_context_t* _ctx) { /* (x : decimal, n : int) -> decimal */ 
  kk_integer_t m;
  kk_integer_t _x6974 = kk_integer_dup(n); /*int*/
  m = kk_integer_abs(_x6974,kk_context()); /*int*/
  kk_std_num_decimal__decimal y;
  kk_integer_t i_6105;
  kk_integer_t _x6975;
  kk_integer_t _x = x.num;
  kk_integer_dup(_x);
  _x6975 = _x; /*int*/
  kk_integer_t _x6976 = kk_integer_dup(m); /*int*/
  i_6105 = kk_std_core_pow(_x6975, _x6976, _ctx); /*int*/
  kk_std_core_types__optional exp_6106;
  kk_integer_t _b_6334_6333;
  kk_integer_t _x6977;
  kk_integer_t _x0 = x.exp;
  kk_integer_dup(_x0);
  kk_std_num_decimal__decimal_drop(x, _ctx);
  _x6977 = _x0; /*int*/
  kk_integer_t _x6978 = kk_integer_dup(m); /*int*/
  _b_6334_6333 = kk_integer_mul(_x6977,_x6978,kk_context()); /*int*/
  exp_6106 = kk_std_core_types__new_Optional(kk_integer_box(_b_6334_6333), _ctx); /*optional<int>*/
  kk_integer_t x0;
  bool _match_6705;
  kk_integer_t _x6979;
  if (kk_std_core_types__is_Optional(exp_6106)) {
    kk_box_t _box_x6335 = exp_6106._cons.Optional.value;
    kk_integer_t _exp_1060 = kk_integer_unbox(_box_x6335);
    kk_integer_dup(_exp_1060);
    _x6979 = _exp_1060; /*int*/
    goto _match6980;
  }
  _x6979 = kk_integer_from_small(0); /*int*/
  _match6980: ;
  _match_6705 = kk_integer_is_zero(_x6979,kk_context()); /*bool*/
  if (_match_6705) {
    x0 = kk_integer_from_small(0); /*int*/
  }
  else {
    kk_integer_t _x6982;
    kk_integer_t _x6983;
    if (kk_std_core_types__is_Optional(exp_6106)) {
      kk_box_t _box_x6336 = exp_6106._cons.Optional.value;
      kk_integer_t _exp_10600 = kk_integer_unbox(_box_x6336);
      kk_integer_dup(_exp_10600);
      _x6983 = _exp_10600; /*int*/
      goto _match6984;
    }
    _x6983 = kk_integer_from_small(0); /*int*/
    _match6984: ;
    _x6982 = kk_integer_div(_x6983,(kk_integer_from_small(7)),kk_context()); /*int*/
    x0 = kk_integer_mul((kk_integer_from_small(7)),_x6982,kk_context()); /*int*/
  }
  kk_integer_t diff;
  kk_integer_t _x6986;
  if (kk_std_core_types__is_Optional(exp_6106)) {
    kk_box_t _box_x6337 = exp_6106._cons.Optional.value;
    kk_integer_t _exp_106000 = kk_integer_unbox(_box_x6337);
    kk_integer_dup(_exp_106000);
    _x6986 = _exp_106000; /*int*/
    goto _match6987;
  }
  _x6986 = kk_integer_from_small(0); /*int*/
  _match6987: ;
  kk_integer_t _x6989 = kk_integer_dup(x0); /*int*/
  diff = kk_integer_sub(_x6986,_x6989,kk_context()); /*int*/
  bool _match_6704;
  kk_integer_t _x6990 = kk_integer_dup(diff); /*int*/
  _match_6704 = kk_integer_is_zero(_x6990,kk_context()); /*bool*/
  if (_match_6704) {
    kk_integer_drop(diff, _ctx);
    kk_integer_drop(x0, _ctx);
    kk_integer_t _x6991;
    if (kk_std_core_types__is_Optional(exp_6106)) {
      kk_box_t _box_x6338 = exp_6106._cons.Optional.value;
      kk_integer_t _exp_10601 = kk_integer_unbox(_box_x6338);
      kk_integer_dup(_exp_10601);
      kk_std_core_types__optional_drop(exp_6106, _ctx);
      _x6991 = _exp_10601; /*int*/
      goto _match6992;
    }
    _x6991 = kk_integer_from_small(0); /*int*/
    _match6992: ;
    y = kk_std_num_decimal__new_Decimal(i_6105, _x6991, _ctx); /*std/num/decimal/decimal*/
  }
  else {
    kk_std_core_types__optional_drop(exp_6106, _ctx);
    kk_integer_t _x6994;
    kk_integer_t _x6995 = kk_integer_abs(diff,kk_context()); /*int*/
    _x6994 = kk_std_core_mul_exp10(i_6105, _x6995, _ctx); /*int*/
    y = kk_std_num_decimal__new_Decimal(_x6994, x0, _ctx); /*std/num/decimal/decimal*/
  }
  bool _match_6700 = kk_std_core_is_neg_2(n, _ctx); /*bool*/;
  if (_match_6700) {
    kk_std_num_decimal__decimal _x6996;
    kk_std_core_types__optional exp3_6115;
    kk_box_t _x6997;
    kk_integer_t _x6998;
    kk_std_core_types__optional _match_6703 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
    if (kk_std_core_types__is_Optional(_match_6703)) {
      kk_box_t _box_x6339 = _match_6703._cons.Optional.value;
      kk_integer_t _exp_785 = kk_integer_unbox(_box_x6339);
      kk_integer_dup(_exp_785);
      kk_std_core_types__optional_drop(_match_6703, _ctx);
      _x6998 = _exp_785; /*int*/
      goto _match6999;
    }
    _x6998 = kk_integer_from_small(0); /*int*/
    _match6999: ;
    _x6997 = kk_integer_box(_x6998); /*35*/
    exp3_6115 = kk_std_core_types__new_Optional(_x6997, _ctx); /*optional<int>*/
    kk_integer_t x1;
    bool _match_6702;
    kk_integer_t _x7001;
    if (kk_std_core_types__is_Optional(exp3_6115)) {
      kk_box_t _box_x6342 = exp3_6115._cons.Optional.value;
      kk_integer_t _exp_10602 = kk_integer_unbox(_box_x6342);
      kk_integer_dup(_exp_10602);
      _x7001 = _exp_10602; /*int*/
      goto _match7002;
    }
    _x7001 = kk_integer_from_small(0); /*int*/
    _match7002: ;
    _match_6702 = kk_integer_is_zero(_x7001,kk_context()); /*bool*/
    if (_match_6702) {
      x1 = kk_integer_from_small(0); /*int*/
    }
    else {
      kk_integer_t _x7004;
      kk_integer_t _x7005;
      if (kk_std_core_types__is_Optional(exp3_6115)) {
        kk_box_t _box_x6343 = exp3_6115._cons.Optional.value;
        kk_integer_t _exp_106020 = kk_integer_unbox(_box_x6343);
        kk_integer_dup(_exp_106020);
        _x7005 = _exp_106020; /*int*/
        goto _match7006;
      }
      _x7005 = kk_integer_from_small(0); /*int*/
      _match7006: ;
      _x7004 = kk_integer_div(_x7005,(kk_integer_from_small(7)),kk_context()); /*int*/
      x1 = kk_integer_mul((kk_integer_from_small(7)),_x7004,kk_context()); /*int*/
    }
    kk_integer_t diff0;
    kk_integer_t _x7008;
    if (kk_std_core_types__is_Optional(exp3_6115)) {
      kk_box_t _box_x6344 = exp3_6115._cons.Optional.value;
      kk_integer_t _exp_10603 = kk_integer_unbox(_box_x6344);
      kk_integer_dup(_exp_10603);
      _x7008 = _exp_10603; /*int*/
      goto _match7009;
    }
    _x7008 = kk_integer_from_small(0); /*int*/
    _match7009: ;
    kk_integer_t _x7011 = kk_integer_dup(x1); /*int*/
    diff0 = kk_integer_sub(_x7008,_x7011,kk_context()); /*int*/
    bool _match_6701;
    kk_integer_t _x7012 = kk_integer_dup(diff0); /*int*/
    _match_6701 = kk_integer_is_zero(_x7012,kk_context()); /*bool*/
    if (_match_6701) {
      kk_integer_drop(diff0, _ctx);
      kk_integer_drop(x1, _ctx);
      kk_integer_t _x7013;
      if (kk_std_core_types__is_Optional(exp3_6115)) {
        kk_box_t _box_x6345 = exp3_6115._cons.Optional.value;
        kk_integer_t _exp_10604 = kk_integer_unbox(_box_x6345);
        kk_integer_dup(_exp_10604);
        kk_std_core_types__optional_drop(exp3_6115, _ctx);
        _x7013 = _exp_10604; /*int*/
        goto _match7014;
      }
      _x7013 = kk_integer_from_small(0); /*int*/
      _match7014: ;
      _x6996 = kk_std_num_decimal__new_Decimal(kk_integer_from_small(1), _x7013, _ctx); /*std/num/decimal/decimal*/
    }
    else {
      kk_std_core_types__optional_drop(exp3_6115, _ctx);
      kk_integer_t _x7016;
      kk_integer_t _x7017 = kk_integer_abs(diff0,kk_context()); /*int*/
      _x7016 = kk_std_core_mul_exp10(kk_integer_from_small(1), _x7017, _ctx); /*int*/
      _x6996 = kk_std_num_decimal__new_Decimal(_x7016, x1, _ctx); /*std/num/decimal/decimal*/
    }
    kk_std_core_types__optional _x7018;
    kk_integer_t _b_6347_6346 = kk_integer_add((kk_integer_from_small(3)),m,kk_context()); /*int*/;
    _x7018 = kk_std_core_types__new_Optional(kk_integer_box(_b_6347_6346), _ctx); /*optional<35>*/
    return kk_std_num_decimal_div(_x6996, y, _x7018, _ctx);
  }
  kk_integer_drop(m, _ctx);
  return y;
}
 
/* Create a decimal from a `:double` with a specified maximal precision (=`-1`).
Use a negative maximal precision to create a decimal that precisely represents the `:double`.
Note: creating a `:decimal` from a `:double` may lose precision and give surprising results as many decimal
fractions cannot be represented precisely by a `:double`.
Also, `decimal(i,exp)` is more efficient and better when when exact representations
are required. For example:
```
> decimal(1.1)
1.100000000000000088817841970012523233890533447265625
> decimal(1.1,17)
1.10000000000000008
> decimal(11,-1)
1.1
```
.
*/

kk_std_num_decimal__decimal kk_std_num_decimal_decimal_1(double d, kk_std_core_types__optional max_prec, kk_context_t* _ctx) { /* (d : double, max-prec : optional<int>) -> decimal */ 
  kk_std_core_types__tuple2_ _match_6687 = kk_std_num_double_decode(d, _ctx); /*(int, int)*/;
  kk_box_t _box_x6348 = _match_6687.fst;
  kk_box_t _box_x6349 = _match_6687.snd;
  kk_integer_t man = kk_integer_unbox(_box_x6348);
  kk_integer_t exp0 = kk_integer_unbox(_box_x6349);
  kk_integer_dup(exp0);
  kk_integer_dup(man);
  kk_std_core_types__tuple2__drop(_match_6687, _ctx);
  bool _match_6688;
  kk_integer_t _x7021 = kk_integer_dup(exp0); /*int*/
  _match_6688 = kk_integer_gte(_x7021,(kk_integer_from_small(0)),kk_context()); /*bool*/
  if (_match_6688) {
    kk_std_core_types__optional_drop(max_prec, _ctx);
    kk_integer_t i_6117;
    kk_integer_t _x7022 = kk_std_core_pow(kk_integer_from_small(2), exp0, _ctx); /*int*/
    i_6117 = kk_integer_mul(man,_x7022,kk_context()); /*int*/
    kk_std_core_types__optional exp1_6122;
    kk_box_t _x7023;
    kk_integer_t _x7024;
    kk_std_core_types__optional _match_6699 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
    if (kk_std_core_types__is_Optional(_match_6699)) {
      kk_box_t _box_x6350 = _match_6699._cons.Optional.value;
      kk_integer_t _exp_785 = kk_integer_unbox(_box_x6350);
      kk_integer_dup(_exp_785);
      kk_std_core_types__optional_drop(_match_6699, _ctx);
      _x7024 = _exp_785; /*int*/
      goto _match7025;
    }
    _x7024 = kk_integer_from_small(0); /*int*/
    _match7025: ;
    _x7023 = kk_integer_box(_x7024); /*35*/
    exp1_6122 = kk_std_core_types__new_Optional(_x7023, _ctx); /*optional<int>*/
    kk_integer_t x;
    bool _match_6698;
    kk_integer_t _x7027;
    if (kk_std_core_types__is_Optional(exp1_6122)) {
      kk_box_t _box_x6353 = exp1_6122._cons.Optional.value;
      kk_integer_t _exp_1060 = kk_integer_unbox(_box_x6353);
      kk_integer_dup(_exp_1060);
      _x7027 = _exp_1060; /*int*/
      goto _match7028;
    }
    _x7027 = kk_integer_from_small(0); /*int*/
    _match7028: ;
    _match_6698 = kk_integer_is_zero(_x7027,kk_context()); /*bool*/
    if (_match_6698) {
      x = kk_integer_from_small(0); /*int*/
    }
    else {
      kk_integer_t _x7030;
      kk_integer_t _x7031;
      if (kk_std_core_types__is_Optional(exp1_6122)) {
        kk_box_t _box_x6354 = exp1_6122._cons.Optional.value;
        kk_integer_t _exp_10600 = kk_integer_unbox(_box_x6354);
        kk_integer_dup(_exp_10600);
        _x7031 = _exp_10600; /*int*/
        goto _match7032;
      }
      _x7031 = kk_integer_from_small(0); /*int*/
      _match7032: ;
      _x7030 = kk_integer_div(_x7031,(kk_integer_from_small(7)),kk_context()); /*int*/
      x = kk_integer_mul((kk_integer_from_small(7)),_x7030,kk_context()); /*int*/
    }
    kk_integer_t diff;
    kk_integer_t _x7034;
    if (kk_std_core_types__is_Optional(exp1_6122)) {
      kk_box_t _box_x6355 = exp1_6122._cons.Optional.value;
      kk_integer_t _exp_106000 = kk_integer_unbox(_box_x6355);
      kk_integer_dup(_exp_106000);
      _x7034 = _exp_106000; /*int*/
      goto _match7035;
    }
    _x7034 = kk_integer_from_small(0); /*int*/
    _match7035: ;
    kk_integer_t _x7037 = kk_integer_dup(x); /*int*/
    diff = kk_integer_sub(_x7034,_x7037,kk_context()); /*int*/
    bool _match_6697;
    kk_integer_t _x7038 = kk_integer_dup(diff); /*int*/
    _match_6697 = kk_integer_is_zero(_x7038,kk_context()); /*bool*/
    if (_match_6697) {
      kk_integer_drop(diff, _ctx);
      kk_integer_drop(x, _ctx);
      kk_integer_t _x7039;
      if (kk_std_core_types__is_Optional(exp1_6122)) {
        kk_box_t _box_x6356 = exp1_6122._cons.Optional.value;
        kk_integer_t _exp_10601 = kk_integer_unbox(_box_x6356);
        kk_integer_dup(_exp_10601);
        kk_std_core_types__optional_drop(exp1_6122, _ctx);
        _x7039 = _exp_10601; /*int*/
        goto _match7040;
      }
      _x7039 = kk_integer_from_small(0); /*int*/
      _match7040: ;
      return kk_std_num_decimal__new_Decimal(i_6117, _x7039, _ctx);
    }
    kk_std_core_types__optional_drop(exp1_6122, _ctx);
    kk_integer_t _x7042;
    kk_integer_t _x7043 = kk_integer_abs(diff,kk_context()); /*int*/
    _x7042 = kk_std_core_mul_exp10(i_6117, _x7043, _ctx); /*int*/
    return kk_std_num_decimal__new_Decimal(_x7042, x, _ctx);
  }
  kk_integer_t prec;
  bool _match_6695;
  kk_integer_t _x7044;
  if (kk_std_core_types__is_Optional(max_prec)) {
    kk_box_t _box_x6357 = max_prec._cons.Optional.value;
    kk_integer_t _max_prec_798 = kk_integer_unbox(_box_x6357);
    kk_integer_dup(_max_prec_798);
    _x7044 = _max_prec_798; /*int*/
    goto _match7045;
  }
  _x7044 = kk_integer_from_small(-1); /*int*/
  _match7045: ;
  _match_6695 = kk_integer_lt(_x7044,(kk_integer_from_small(0)),kk_context()); /*bool*/
  if (_match_6695) {
    kk_std_core_types__optional_drop(max_prec, _ctx);
    kk_integer_t _x7047 = kk_integer_dup(exp0); /*int*/
    prec = kk_integer_neg(_x7047,kk_context()); /*int*/
  }
  else {
    kk_integer_t j_6125;
    kk_integer_t _x7048 = kk_integer_dup(exp0); /*int*/
    j_6125 = kk_integer_neg(_x7048,kk_context()); /*int*/
    bool _match_6696;
    kk_integer_t _x7049;
    if (kk_std_core_types__is_Optional(max_prec)) {
      kk_box_t _box_x6358 = max_prec._cons.Optional.value;
      kk_integer_t _max_prec_7980 = kk_integer_unbox(_box_x6358);
      kk_integer_dup(_max_prec_7980);
      _x7049 = _max_prec_7980; /*int*/
      goto _match7050;
    }
    _x7049 = kk_integer_from_small(-1); /*int*/
    _match7050: ;
    kk_integer_t _x7052 = kk_integer_dup(j_6125); /*int*/
    _match_6696 = kk_integer_lte(_x7049,_x7052,kk_context()); /*bool*/
    if (_match_6696) {
      kk_integer_drop(j_6125, _ctx);
      if (kk_std_core_types__is_Optional(max_prec)) {
        kk_box_t _box_x6359 = max_prec._cons.Optional.value;
        kk_integer_t _max_prec_79800 = kk_integer_unbox(_box_x6359);
        kk_integer_dup(_max_prec_79800);
        kk_std_core_types__optional_drop(max_prec, _ctx);
        prec = _max_prec_79800; /*int*/
        goto _match7053;
      }
      prec = kk_integer_from_small(-1); /*int*/
      _match7053: ;
    }
    else {
      kk_std_core_types__optional_drop(max_prec, _ctx);
      prec = j_6125; /*int*/
    }
  }
  kk_std_num_decimal__decimal _x7055;
  kk_std_core_types__optional exp5_6129;
  kk_box_t _x7056;
  kk_integer_t _x7057;
  kk_std_core_types__optional _match_6694 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
  if (kk_std_core_types__is_Optional(_match_6694)) {
    kk_box_t _box_x6360 = _match_6694._cons.Optional.value;
    kk_integer_t _exp_7850 = kk_integer_unbox(_box_x6360);
    kk_integer_dup(_exp_7850);
    kk_std_core_types__optional_drop(_match_6694, _ctx);
    _x7057 = _exp_7850; /*int*/
    goto _match7058;
  }
  _x7057 = kk_integer_from_small(0); /*int*/
  _match7058: ;
  _x7056 = kk_integer_box(_x7057); /*35*/
  exp5_6129 = kk_std_core_types__new_Optional(_x7056, _ctx); /*optional<int>*/
  kk_integer_t x0;
  bool _match_6693;
  kk_integer_t _x7060;
  if (kk_std_core_types__is_Optional(exp5_6129)) {
    kk_box_t _box_x6363 = exp5_6129._cons.Optional.value;
    kk_integer_t _exp_10602 = kk_integer_unbox(_box_x6363);
    kk_integer_dup(_exp_10602);
    _x7060 = _exp_10602; /*int*/
    goto _match7061;
  }
  _x7060 = kk_integer_from_small(0); /*int*/
  _match7061: ;
  _match_6693 = kk_integer_is_zero(_x7060,kk_context()); /*bool*/
  if (_match_6693) {
    x0 = kk_integer_from_small(0); /*int*/
  }
  else {
    kk_integer_t _x7063;
    kk_integer_t _x7064;
    if (kk_std_core_types__is_Optional(exp5_6129)) {
      kk_box_t _box_x6364 = exp5_6129._cons.Optional.value;
      kk_integer_t _exp_106020 = kk_integer_unbox(_box_x6364);
      kk_integer_dup(_exp_106020);
      _x7064 = _exp_106020; /*int*/
      goto _match7065;
    }
    _x7064 = kk_integer_from_small(0); /*int*/
    _match7065: ;
    _x7063 = kk_integer_div(_x7064,(kk_integer_from_small(7)),kk_context()); /*int*/
    x0 = kk_integer_mul((kk_integer_from_small(7)),_x7063,kk_context()); /*int*/
  }
  kk_integer_t diff0;
  kk_integer_t _x7067;
  if (kk_std_core_types__is_Optional(exp5_6129)) {
    kk_box_t _box_x6365 = exp5_6129._cons.Optional.value;
    kk_integer_t _exp_10603 = kk_integer_unbox(_box_x6365);
    kk_integer_dup(_exp_10603);
    _x7067 = _exp_10603; /*int*/
    goto _match7068;
  }
  _x7067 = kk_integer_from_small(0); /*int*/
  _match7068: ;
  kk_integer_t _x7070 = kk_integer_dup(x0); /*int*/
  diff0 = kk_integer_sub(_x7067,_x7070,kk_context()); /*int*/
  bool _match_6692;
  kk_integer_t _x7071 = kk_integer_dup(diff0); /*int*/
  _match_6692 = kk_integer_is_zero(_x7071,kk_context()); /*bool*/
  if (_match_6692) {
    kk_integer_drop(diff0, _ctx);
    kk_integer_drop(x0, _ctx);
    kk_integer_t _x7072;
    if (kk_std_core_types__is_Optional(exp5_6129)) {
      kk_box_t _box_x6366 = exp5_6129._cons.Optional.value;
      kk_integer_t _exp_10604 = kk_integer_unbox(_box_x6366);
      kk_integer_dup(_exp_10604);
      kk_std_core_types__optional_drop(exp5_6129, _ctx);
      _x7072 = _exp_10604; /*int*/
      goto _match7073;
    }
    _x7072 = kk_integer_from_small(0); /*int*/
    _match7073: ;
    _x7055 = kk_std_num_decimal__new_Decimal(man, _x7072, _ctx); /*std/num/decimal/decimal*/
  }
  else {
    kk_std_core_types__optional_drop(exp5_6129, _ctx);
    kk_integer_t _x7075;
    kk_integer_t _x7076 = kk_integer_abs(diff0,kk_context()); /*int*/
    _x7075 = kk_std_core_mul_exp10(man, _x7076, _ctx); /*int*/
    _x7055 = kk_std_num_decimal__new_Decimal(_x7075, x0, _ctx); /*std/num/decimal/decimal*/
  }
  kk_std_num_decimal__decimal _x7077;
  kk_std_num_decimal__decimal _x7078;
  kk_std_core_types__optional exp8_6134;
  kk_box_t _x7079;
  kk_integer_t _x7080;
  kk_std_core_types__optional _match_6691 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
  if (kk_std_core_types__is_Optional(_match_6691)) {
    kk_box_t _box_x6367 = _match_6691._cons.Optional.value;
    kk_integer_t _exp_7851 = kk_integer_unbox(_box_x6367);
    kk_integer_dup(_exp_7851);
    kk_std_core_types__optional_drop(_match_6691, _ctx);
    _x7080 = _exp_7851; /*int*/
    goto _match7081;
  }
  _x7080 = kk_integer_from_small(0); /*int*/
  _match7081: ;
  _x7079 = kk_integer_box(_x7080); /*35*/
  exp8_6134 = kk_std_core_types__new_Optional(_x7079, _ctx); /*optional<int>*/
  kk_integer_t x1;
  bool _match_6690;
  kk_integer_t _x7083;
  if (kk_std_core_types__is_Optional(exp8_6134)) {
    kk_box_t _box_x6370 = exp8_6134._cons.Optional.value;
    kk_integer_t _exp_10605 = kk_integer_unbox(_box_x6370);
    kk_integer_dup(_exp_10605);
    _x7083 = _exp_10605; /*int*/
    goto _match7084;
  }
  _x7083 = kk_integer_from_small(0); /*int*/
  _match7084: ;
  _match_6690 = kk_integer_is_zero(_x7083,kk_context()); /*bool*/
  if (_match_6690) {
    x1 = kk_integer_from_small(0); /*int*/
  }
  else {
    kk_integer_t _x7086;
    kk_integer_t _x7087;
    if (kk_std_core_types__is_Optional(exp8_6134)) {
      kk_box_t _box_x6371 = exp8_6134._cons.Optional.value;
      kk_integer_t _exp_106050 = kk_integer_unbox(_box_x6371);
      kk_integer_dup(_exp_106050);
      _x7087 = _exp_106050; /*int*/
      goto _match7088;
    }
    _x7087 = kk_integer_from_small(0); /*int*/
    _match7088: ;
    _x7086 = kk_integer_div(_x7087,(kk_integer_from_small(7)),kk_context()); /*int*/
    x1 = kk_integer_mul((kk_integer_from_small(7)),_x7086,kk_context()); /*int*/
  }
  kk_integer_t diff1;
  kk_integer_t _x7090;
  if (kk_std_core_types__is_Optional(exp8_6134)) {
    kk_box_t _box_x6372 = exp8_6134._cons.Optional.value;
    kk_integer_t _exp_10606 = kk_integer_unbox(_box_x6372);
    kk_integer_dup(_exp_10606);
    _x7090 = _exp_10606; /*int*/
    goto _match7091;
  }
  _x7090 = kk_integer_from_small(0); /*int*/
  _match7091: ;
  kk_integer_t _x7093 = kk_integer_dup(x1); /*int*/
  diff1 = kk_integer_sub(_x7090,_x7093,kk_context()); /*int*/
  bool _match_6689;
  kk_integer_t _x7094 = kk_integer_dup(diff1); /*int*/
  _match_6689 = kk_integer_is_zero(_x7094,kk_context()); /*bool*/
  if (_match_6689) {
    kk_integer_drop(diff1, _ctx);
    kk_integer_drop(x1, _ctx);
    kk_integer_t _x7095;
    if (kk_std_core_types__is_Optional(exp8_6134)) {
      kk_box_t _box_x6373 = exp8_6134._cons.Optional.value;
      kk_integer_t _exp_10607 = kk_integer_unbox(_box_x6373);
      kk_integer_dup(_exp_10607);
      kk_std_core_types__optional_drop(exp8_6134, _ctx);
      _x7095 = _exp_10607; /*int*/
      goto _match7096;
    }
    _x7095 = kk_integer_from_small(0); /*int*/
    _match7096: ;
    _x7078 = kk_std_num_decimal__new_Decimal(kk_integer_from_small(2), _x7095, _ctx); /*std/num/decimal/decimal*/
  }
  else {
    kk_std_core_types__optional_drop(exp8_6134, _ctx);
    kk_integer_t _x7098;
    kk_integer_t _x7099 = kk_integer_abs(diff1,kk_context()); /*int*/
    _x7098 = kk_std_core_mul_exp10(kk_integer_from_small(2), _x7099, _ctx); /*int*/
    _x7078 = kk_std_num_decimal__new_Decimal(_x7098, x1, _ctx); /*std/num/decimal/decimal*/
  }
  kk_integer_t _x7100 = kk_integer_neg(exp0,kk_context()); /*int*/
  _x7077 = kk_std_num_decimal_pow(_x7078, _x7100, _ctx); /*std/num/decimal/decimal*/
  kk_std_core_types__optional _x7101 = kk_std_core_types__new_Optional(kk_integer_box(prec), _ctx); /*optional<35>*/
  return kk_std_num_decimal_div(_x7055, _x7077, _x7101, _ctx);
}
 
// The maximum of `x` and `y`

kk_std_num_decimal__decimal kk_std_num_decimal_max(kk_std_num_decimal__decimal x, kk_std_num_decimal__decimal y, kk_context_t* _ctx) { /* (x : decimal, y : decimal) -> decimal */ 
  bool _match_6686;
  kk_std_num_decimal__decimal _x7102 = kk_std_num_decimal__decimal_dup(x); /*std/num/decimal/decimal*/
  kk_std_num_decimal__decimal _x7103 = kk_std_num_decimal__decimal_dup(y); /*std/num/decimal/decimal*/
  _match_6686 = kk_std_num_decimal__lp__gt__eq__rp_(_x7102, _x7103, _ctx); /*bool*/
  if (_match_6686) {
    kk_std_num_decimal__decimal_drop(y, _ctx);
    return x;
  }
  kk_std_num_decimal__decimal_drop(x, _ctx);
  return y;
}
 
// The minimum of `x` and `y`.

kk_std_num_decimal__decimal kk_std_num_decimal_min(kk_std_num_decimal__decimal x, kk_std_num_decimal__decimal y, kk_context_t* _ctx) { /* (x : decimal, y : decimal) -> decimal */ 
  bool _match_6685;
  kk_std_num_decimal__decimal _x7104 = kk_std_num_decimal__decimal_dup(x); /*std/num/decimal/decimal*/
  kk_std_num_decimal__decimal _x7105 = kk_std_num_decimal__decimal_dup(y); /*std/num/decimal/decimal*/
  _match_6685 = kk_std_num_decimal__lp__lt__eq__rp_(_x7104, _x7105, _ctx); /*bool*/
  if (_match_6685) {
    kk_std_num_decimal__decimal_drop(y, _ctx);
    return x;
  }
  kk_std_num_decimal__decimal_drop(x, _ctx);
  return y;
}
 
// Round the decimal-point number `x` to
// to a specified number of digits behind the dot `prec` (=`0`) with an optional
// rounding mode `rnd` (=`Half-even`). The precision can be negative.
// `decimal(1,485).round-to-prec(2).show == "1.48"`
// `decimal(112,49).round-to-prec(-1).show == "110"`


// lift anonymous function
struct kk_std_num_decimal_round_to_prec_fun7140__t {
  struct kk_function_s _base;
  kk_integer_t p;
  kk_integer_t q;
  kk_integer_t r;
};
static kk_integer_t kk_std_num_decimal_round_to_prec_fun7140(kk_function_t _fself, bool keep_on_eq, kk_context_t* _ctx);
static kk_function_t kk_std_num_decimal_new_round_to_prec_fun7140(kk_integer_t p, kk_integer_t q, kk_integer_t r, kk_context_t* _ctx) {
  struct kk_std_num_decimal_round_to_prec_fun7140__t* _self = kk_function_alloc_as(struct kk_std_num_decimal_round_to_prec_fun7140__t, 4, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_num_decimal_round_to_prec_fun7140, kk_context());
  _self->p = p;
  _self->q = q;
  _self->r = r;
  return &_self->_base;
}

static kk_integer_t kk_std_num_decimal_round_to_prec_fun7140(kk_function_t _fself, bool keep_on_eq, kk_context_t* _ctx) {
  struct kk_std_num_decimal_round_to_prec_fun7140__t* _self = kk_function_as(struct kk_std_num_decimal_round_to_prec_fun7140__t*, _fself);
  kk_integer_t p = _self->p; /* int */
  kk_integer_t q = _self->q; /* int */
  kk_integer_t r = _self->r; /* int */
  kk_drop_match(_self, {kk_integer_dup(p);kk_integer_dup(q);kk_integer_dup(r);}, {}, _ctx)
  kk_integer_t half;
  kk_integer_t _x7141 = kk_std_core_exp10(p, _ctx); /*int*/
  half = kk_integer_div(_x7141,(kk_integer_from_small(2)),kk_context()); /*int*/
  kk_std_core_types__order _match_6681 = kk_int_as_order(kk_integer_cmp(r,half,kk_context()),kk_context()); /*order*/;
  if (kk_std_core_types__is_Eq(_match_6681)) {
    if (keep_on_eq) {
      return q;
    }
    return kk_std_core_inc(q, _ctx);
  }
  if (kk_std_core_types__is_Gt(_match_6681)) {
    return kk_std_core_inc(q, _ctx);
  }
  return q;
}

kk_std_num_decimal__decimal kk_std_num_decimal_round_to_prec(kk_std_num_decimal__decimal x, kk_std_core_types__optional prec, kk_std_core_types__optional rnd, kk_context_t* _ctx) { /* (x : decimal, prec : optional<int>, rnd : optional<round>) -> total decimal */ 
  bool _match_6672;
  kk_integer_t _x7111;
  kk_integer_t _x = x.exp;
  kk_integer_dup(_x);
  _x7111 = _x; /*int*/
  kk_integer_t _x7112;
  kk_integer_t _x7113;
  if (kk_std_core_types__is_Optional(prec)) {
    kk_box_t _box_x6376 = prec._cons.Optional.value;
    kk_integer_t _prec_2613 = kk_integer_unbox(_box_x6376);
    kk_integer_dup(_prec_2613);
    _x7113 = _prec_2613; /*int*/
    goto _match7114;
  }
  _x7113 = kk_integer_from_small(0); /*int*/
  _match7114: ;
  _x7112 = kk_integer_neg(_x7113,kk_context()); /*int*/
  _match_6672 = kk_integer_gte(_x7111,_x7112,kk_context()); /*bool*/
  if (_match_6672) {
    kk_std_core_types__optional_drop(prec, _ctx);
    kk_std_core_types__optional_drop(rnd, _ctx);
    return x;
  }
  kk_std_num_decimal__decimal cx = kk_std_num_decimal_reduce(x, _ctx); /*std/num/decimal/decimal*/;
  kk_integer_t p;
  kk_integer_t _x7116;
  kk_integer_t _x7117;
  kk_integer_t _x0 = cx.exp;
  kk_integer_dup(_x0);
  _x7117 = _x0; /*int*/
  _x7116 = kk_integer_neg(_x7117,kk_context()); /*int*/
  kk_integer_t _x7118;
  if (kk_std_core_types__is_Optional(prec)) {
    kk_box_t _box_x6377 = prec._cons.Optional.value;
    kk_integer_t _prec_26130 = kk_integer_unbox(_box_x6377);
    kk_integer_dup(_prec_26130);
    _x7118 = _prec_26130; /*int*/
    goto _match7119;
  }
  _x7118 = kk_integer_from_small(0); /*int*/
  _match7119: ;
  p = kk_integer_sub(_x7116,_x7118,kk_context()); /*int*/
  bool _match_6673;
  bool _x7121;
  kk_integer_t _x7122 = kk_integer_dup(p); /*int*/
  _x7121 = kk_std_core_is_pos_2(_x7122, _ctx); /*bool*/
  _match_6673 = !(_x7121); /*bool*/
  if (_match_6673) {
    kk_integer_drop(p, _ctx);
    kk_std_core_types__optional_drop(prec, _ctx);
    kk_std_core_types__optional_drop(rnd, _ctx);
    return cx;
  }
  kk_std_core_types__tuple2_ _match_6674;
  kk_std_core_types__tuple2_ _match_6682;
  bool _match_6684;
  kk_integer_t _x7123 = kk_integer_dup(p); /*int*/
  _match_6684 = kk_integer_lte(_x7123,(kk_integer_from_small(0)),kk_context()); /*bool*/
  if (_match_6684) {
    kk_box_t _x7124;
    kk_integer_t _x7125;
    kk_integer_t _x1 = cx.num;
    kk_integer_dup(_x1);
    kk_std_num_decimal__decimal_drop(cx, _ctx);
    _x7125 = _x1; /*int*/
    _x7124 = kk_integer_box(_x7125); /*4*/
    _match_6682 = kk_std_core_types__new_dash__lp__comma__rp_(_x7124, kk_integer_box(kk_integer_from_small(0)), _ctx); /*(4, 5)*/
  }
  else {
    kk_integer_t cq;
    kk_integer_t _x7126;
    kk_integer_t _x10 = cx.num;
    kk_integer_dup(_x10);
    _x7126 = _x10; /*int*/
    kk_integer_t _x7127 = kk_integer_dup(p); /*int*/
    cq = kk_std_core_cdiv_exp10(_x7126, _x7127, _ctx); /*int*/
    kk_integer_t cr;
    kk_integer_t _x7128;
    kk_integer_t _x11 = cx.num;
    kk_integer_dup(_x11);
    kk_std_num_decimal__decimal_drop(cx, _ctx);
    _x7128 = _x11; /*int*/
    kk_integer_t _x7129;
    kk_integer_t _x7130 = kk_integer_dup(cq); /*int*/
    kk_integer_t _x7131 = kk_integer_dup(p); /*int*/
    _x7129 = kk_std_core_mul_exp10(_x7130, _x7131, _ctx); /*int*/
    cr = kk_integer_sub(_x7128,_x7129,kk_context()); /*int*/
    _match_6682 = kk_std_core_types__new_dash__lp__comma__rp_(kk_integer_box(cq), kk_integer_box(cr), _ctx); /*(4, 5)*/
  }
  kk_box_t _box_x6382 = _match_6682.fst;
  kk_box_t _box_x6383 = _match_6682.snd;
  kk_integer_t cq0 = kk_integer_unbox(_box_x6382);
  kk_integer_t cr0 = kk_integer_unbox(_box_x6383);
  kk_integer_dup(cq0);
  kk_integer_dup(cr0);
  kk_std_core_types__tuple2__drop(_match_6682, _ctx);
  bool _match_6683;
  bool _x7134;
  kk_integer_t _x7135 = kk_integer_dup(cr0); /*int*/
  _x7134 = kk_std_core_is_neg_2(_x7135, _ctx); /*bool*/
  _match_6683 = !(_x7134); /*bool*/
  if (_match_6683) {
    _match_6674 = kk_std_core_types__new_dash__lp__comma__rp_(kk_integer_box(cq0), kk_integer_box(cr0), _ctx); /*(4, 5)*/
  }
  else {
    kk_integer_t _b_6404_6386 = kk_std_core_dec(cq0, _ctx); /*int*/;
    kk_integer_t _b_6405_6387;
    kk_integer_t _x7136;
    kk_integer_t _x7137 = kk_integer_dup(p); /*int*/
    _x7136 = kk_std_core_exp10(_x7137, _ctx); /*int*/
    _b_6405_6387 = kk_integer_add(cr0,_x7136,kk_context()); /*int*/
    _match_6674 = kk_std_core_types__new_dash__lp__comma__rp_(kk_integer_box(_b_6404_6386), kk_integer_box(_b_6405_6387), _ctx); /*(4, 5)*/
  }
  kk_box_t _box_x6388 = _match_6674.fst;
  kk_box_t _box_x6389 = _match_6674.snd;
  kk_integer_t q = kk_integer_unbox(_box_x6388);
  kk_integer_t r = kk_integer_unbox(_box_x6389);
  kk_integer_dup(q);
  kk_integer_dup(r);
  kk_std_core_types__tuple2__drop(_match_6674, _ctx);
  kk_function_t round_half;
  kk_integer_dup(q);
  kk_integer_dup(r);
  round_half = kk_std_num_decimal_new_round_to_prec_fun7140(p, q, r, _ctx); /*(keep-on-eq : bool) -> int*/
  kk_integer_t q1;
  bool _match_6677 = kk_integer_is_zero(r,kk_context()); /*bool*/;
  if (_match_6677) {
    kk_std_core_types__optional_drop(rnd, _ctx);
    kk_function_drop(round_half, _ctx);
    q1 = q; /*int*/
  }
  else {
    kk_std_num_decimal__round _match_6678;
    if (kk_std_core_types__is_Optional(rnd)) {
      kk_box_t _box_x6390 = rnd._cons.Optional.value;
      kk_std_num_decimal__round _rnd_2617 = kk_std_num_decimal__round_unbox(_box_x6390, NULL);
      kk_std_core_types__optional_drop(rnd, _ctx);
      _match_6678 = _rnd_2617; /*std/num/decimal/round*/
      goto _match7142;
    }
    _match_6678 = kk_std_num_decimal__new_Half_even(_ctx); /*std/num/decimal/round*/
    _match7142: ;
    if (kk_std_num_decimal__is_Half_even(_match_6678)) {
      bool _x7145 = kk_std_core_is_even(q, _ctx); /*bool*/
      q1 = kk_function_call(kk_integer_t, (kk_function_t, bool, kk_context_t*), round_half, (round_half, _x7145, _ctx)); /*int*/
      goto _match7144;
    }
    if (kk_std_num_decimal__is_Half_floor(_match_6678)) {
      kk_integer_drop(q, _ctx);
      q1 = kk_function_call(kk_integer_t, (kk_function_t, bool, kk_context_t*), round_half, (round_half, true, _ctx)); /*int*/
      goto _match7144;
    }
    if (kk_std_num_decimal__is_Half_ceiling(_match_6678)) {
      kk_integer_drop(q, _ctx);
      q1 = kk_function_call(kk_integer_t, (kk_function_t, bool, kk_context_t*), round_half, (round_half, false, _ctx)); /*int*/
      goto _match7144;
    }
    if (kk_std_num_decimal__is_Half_truncate(_match_6678)) {
      bool _x7146 = kk_std_core_is_pos_2(q, _ctx); /*bool*/
      q1 = kk_function_call(kk_integer_t, (kk_function_t, bool, kk_context_t*), round_half, (round_half, _x7146, _ctx)); /*int*/
      goto _match7144;
    }
    if (kk_std_num_decimal__is_Half_away_from_zero(_match_6678)) {
      bool _x7147 = kk_std_core_is_neg_2(q, _ctx); /*bool*/
      q1 = kk_function_call(kk_integer_t, (kk_function_t, bool, kk_context_t*), round_half, (round_half, _x7147, _ctx)); /*int*/
      goto _match7144;
    }
    if (kk_std_num_decimal__is_Floor(_match_6678)) {
      kk_function_drop(round_half, _ctx);
      q1 = q; /*int*/
      goto _match7144;
    }
    if (kk_std_num_decimal__is_Ceiling(_match_6678)) {
      kk_function_drop(round_half, _ctx);
      q1 = kk_std_core_inc(q, _ctx); /*int*/
      goto _match7144;
    }
    if (kk_std_num_decimal__is_Truncate(_match_6678)) {
      kk_function_drop(round_half, _ctx);
      bool _match_6680;
      bool _x7148;
      kk_integer_t _x7149 = kk_integer_dup(q); /*int*/
      _x7148 = kk_std_core_is_neg_2(_x7149, _ctx); /*bool*/
      _match_6680 = !(_x7148); /*bool*/
      if (_match_6680) {
        q1 = q; /*int*/
        goto _match7144;
      }
      q1 = kk_std_core_inc(q, _ctx); /*int*/
      goto _match7144;
    }
    kk_function_drop(round_half, _ctx);
    bool _match_6679;
    bool _x7150;
    kk_integer_t _x7151 = kk_integer_dup(q); /*int*/
    _x7150 = kk_std_core_is_pos_2(_x7151, _ctx); /*bool*/
    _match_6679 = !(_x7150); /*bool*/
    if (_match_6679) {
      q1 = q; /*int*/
    }
    else {
      q1 = kk_std_core_inc(q, _ctx); /*int*/
    }
    _match7144: ;
  }
  kk_std_core_types__optional exp_6147;
  kk_integer_t _b_6393_6392;
  kk_integer_t _x7152;
  if (kk_std_core_types__is_Optional(prec)) {
    kk_box_t _box_x6391 = prec._cons.Optional.value;
    kk_integer_t _prec_26131 = kk_integer_unbox(_box_x6391);
    kk_integer_dup(_prec_26131);
    kk_std_core_types__optional_drop(prec, _ctx);
    _x7152 = _prec_26131; /*int*/
    goto _match7153;
  }
  _x7152 = kk_integer_from_small(0); /*int*/
  _match7153: ;
  _b_6393_6392 = kk_integer_neg(_x7152,kk_context()); /*int*/
  exp_6147 = kk_std_core_types__new_Optional(kk_integer_box(_b_6393_6392), _ctx); /*optional<int>*/
  kk_integer_t x0;
  bool _match_6676;
  kk_integer_t _x7155;
  if (kk_std_core_types__is_Optional(exp_6147)) {
    kk_box_t _box_x6394 = exp_6147._cons.Optional.value;
    kk_integer_t _exp_1060 = kk_integer_unbox(_box_x6394);
    kk_integer_dup(_exp_1060);
    _x7155 = _exp_1060; /*int*/
    goto _match7156;
  }
  _x7155 = kk_integer_from_small(0); /*int*/
  _match7156: ;
  _match_6676 = kk_integer_is_zero(_x7155,kk_context()); /*bool*/
  if (_match_6676) {
    x0 = kk_integer_from_small(0); /*int*/
  }
  else {
    kk_integer_t _x7158;
    kk_integer_t _x7159;
    if (kk_std_core_types__is_Optional(exp_6147)) {
      kk_box_t _box_x6395 = exp_6147._cons.Optional.value;
      kk_integer_t _exp_10600 = kk_integer_unbox(_box_x6395);
      kk_integer_dup(_exp_10600);
      _x7159 = _exp_10600; /*int*/
      goto _match7160;
    }
    _x7159 = kk_integer_from_small(0); /*int*/
    _match7160: ;
    _x7158 = kk_integer_div(_x7159,(kk_integer_from_small(7)),kk_context()); /*int*/
    x0 = kk_integer_mul((kk_integer_from_small(7)),_x7158,kk_context()); /*int*/
  }
  kk_integer_t diff;
  kk_integer_t _x7162;
  if (kk_std_core_types__is_Optional(exp_6147)) {
    kk_box_t _box_x6396 = exp_6147._cons.Optional.value;
    kk_integer_t _exp_106000 = kk_integer_unbox(_box_x6396);
    kk_integer_dup(_exp_106000);
    _x7162 = _exp_106000; /*int*/
    goto _match7163;
  }
  _x7162 = kk_integer_from_small(0); /*int*/
  _match7163: ;
  kk_integer_t _x7165 = kk_integer_dup(x0); /*int*/
  diff = kk_integer_sub(_x7162,_x7165,kk_context()); /*int*/
  bool _match_6675;
  kk_integer_t _x7166 = kk_integer_dup(diff); /*int*/
  _match_6675 = kk_integer_is_zero(_x7166,kk_context()); /*bool*/
  if (_match_6675) {
    kk_integer_drop(diff, _ctx);
    kk_integer_drop(x0, _ctx);
    kk_integer_t _x7167;
    if (kk_std_core_types__is_Optional(exp_6147)) {
      kk_box_t _box_x6397 = exp_6147._cons.Optional.value;
      kk_integer_t _exp_10601 = kk_integer_unbox(_box_x6397);
      kk_integer_dup(_exp_10601);
      kk_std_core_types__optional_drop(exp_6147, _ctx);
      _x7167 = _exp_10601; /*int*/
      goto _match7168;
    }
    _x7167 = kk_integer_from_small(0); /*int*/
    _match7168: ;
    return kk_std_num_decimal__new_Decimal(q1, _x7167, _ctx);
  }
  kk_std_core_types__optional_drop(exp_6147, _ctx);
  kk_integer_t _x7170;
  kk_integer_t _x7171 = kk_integer_abs(diff,kk_context()); /*int*/
  _x7170 = kk_std_core_mul_exp10(q1, _x7171, _ctx); /*int*/
  return kk_std_num_decimal__new_Decimal(_x7170, x0, _ctx);
}
 
// Round a `:decimal` number to a whole number with an optional rounding mode (=`Half-even`).

kk_std_num_decimal__decimal kk_std_num_decimal_round(kk_std_num_decimal__decimal x, kk_std_core_types__optional rnd, kk_context_t* _ctx) { /* (x : decimal, rnd : optional<round>) -> decimal */ 
  kk_std_core_types__optional _x7172 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(0)), _ctx); /*optional<35>*/
  kk_std_core_types__optional _x7173;
  kk_box_t _x7174;
  kk_std_num_decimal__round _x7175;
  if (kk_std_core_types__is_Optional(rnd)) {
    kk_box_t _box_x6407 = rnd._cons.Optional.value;
    kk_std_num_decimal__round _rnd_3169 = kk_std_num_decimal__round_unbox(_box_x6407, NULL);
    kk_std_core_types__optional_drop(rnd, _ctx);
    _x7175 = _rnd_3169; /*std/num/decimal/round*/
    goto _match7176;
  }
  _x7175 = kk_std_num_decimal__new_Half_even(_ctx); /*std/num/decimal/round*/
  _match7176: ;
  _x7174 = kk_std_num_decimal__round_box(_x7175, _ctx); /*35*/
  _x7173 = kk_std_core_types__new_Optional(_x7174, _ctx); /*optional<35>*/
  return kk_std_num_decimal_round_to_prec(x, _x7172, _x7173, _ctx);
}
 
// Round a `:decimal` to the smallest integer that is not less than `x`.

kk_std_num_decimal__decimal kk_std_num_decimal_ceiling(kk_std_num_decimal__decimal x, kk_context_t* _ctx) { /* (x : decimal) -> decimal */ 
  kk_std_core_types__optional rnd_6150 = kk_std_core_types__new_Optional(kk_std_num_decimal__round_box(kk_std_num_decimal__new_Ceiling(_ctx), _ctx), _ctx); /*optional<std/num/decimal/round>*/;
  kk_std_core_types__optional _x7178 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(0)), _ctx); /*optional<35>*/
  kk_std_core_types__optional _x7179;
  kk_box_t _x7180;
  kk_std_num_decimal__round _x7181;
  if (kk_std_core_types__is_Optional(rnd_6150)) {
    kk_box_t _box_x6414 = rnd_6150._cons.Optional.value;
    kk_std_num_decimal__round _rnd_3169 = kk_std_num_decimal__round_unbox(_box_x6414, NULL);
    kk_std_core_types__optional_drop(rnd_6150, _ctx);
    _x7181 = _rnd_3169; /*std/num/decimal/round*/
    goto _match7182;
  }
  _x7181 = kk_std_num_decimal__new_Half_even(_ctx); /*std/num/decimal/round*/
  _match7182: ;
  _x7180 = kk_std_num_decimal__round_box(_x7181, _ctx); /*35*/
  _x7179 = kk_std_core_types__new_Optional(_x7180, _ctx); /*optional<35>*/
  return kk_std_num_decimal_round_to_prec(x, _x7178, _x7179, _ctx);
}
 
// Convert a decimal to a `:double`. This may lose precision.

double kk_std_num_decimal_double(kk_std_num_decimal__decimal x, kk_context_t* _ctx) { /* (x : decimal) -> double */ 
  bool _match_6666;
  bool _x7187;
  kk_std_core_types__order x_21555;
  kk_integer_t _x7188;
  kk_integer_t _x = x.exp;
  kk_integer_dup(_x);
  _x7188 = _x; /*int*/
  x_21555 = kk_int_as_order(kk_integer_signum(_x7188,kk_context()),kk_context()); /*order*/
  kk_integer_t _x7189 = kk_std_core_int_5(x_21555, _ctx); /*int*/
  kk_integer_t _x7190;
  kk_std_core_types__order _x7191 = kk_std_core_types__new_Lt(_ctx); /*order*/
  if (kk_std_core_types__is_Lt(_x7191)) {
    _x7190 = kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context()); /*int*/
    goto _match7192;
  }
  if (kk_std_core_types__is_Eq(_x7191)) {
    _x7190 = kk_integer_from_small(0); /*int*/
    goto _match7192;
  }
  _x7190 = kk_integer_from_small(1); /*int*/
  _match7192: ;
  _x7187 = kk_integer_eq(_x7189,_x7190,kk_context()); /*bool*/
  _match_6666 = !(_x7187); /*bool*/
  if (_match_6666) {
    double _x7193;
    kk_integer_t _x7194;
    kk_integer_t _x0 = x.num;
    kk_integer_dup(_x0);
    _x7194 = _x0; /*int*/
    _x7193 = kk_integer_as_double(_x7194,kk_context()); /*double*/
    double _x7195;
    double _x7196;
    kk_integer_t _x7197;
    kk_integer_t _x1 = x.exp;
    kk_integer_dup(_x1);
    kk_std_num_decimal__decimal_drop(x, _ctx);
    _x7197 = _x1; /*int*/
    _x7196 = kk_integer_as_double(_x7197,kk_context()); /*double*/
    _x7195 = pow((0x1.4p3),_x7196); /*double*/
    return (_x7193 * _x7195);
  }
  kk_std_core_types__tuple2_ _match_6667;
  kk_integer_t n_6159;
  kk_integer_t _x7198;
  kk_integer_t _x3 = x.exp;
  kk_integer_dup(_x3);
  _x7198 = _x3; /*int*/
  n_6159 = kk_integer_neg(_x7198,kk_context()); /*int*/
  kk_std_core_types__tuple2_ _match_6668;
  bool _match_6670;
  kk_integer_t _x7199 = kk_integer_dup(n_6159); /*int*/
  _match_6670 = kk_integer_lte(_x7199,(kk_integer_from_small(0)),kk_context()); /*bool*/
  if (_match_6670) {
    kk_box_t _x7200;
    kk_integer_t _x7201;
    kk_integer_t _x2 = x.num;
    kk_integer_dup(_x2);
    _x7201 = _x2; /*int*/
    _x7200 = kk_integer_box(_x7201); /*4*/
    _match_6668 = kk_std_core_types__new_dash__lp__comma__rp_(_x7200, kk_integer_box(kk_integer_from_small(0)), _ctx); /*(4, 5)*/
  }
  else {
    kk_integer_t cq;
    kk_integer_t _x7202;
    kk_integer_t _x20 = x.num;
    kk_integer_dup(_x20);
    _x7202 = _x20; /*int*/
    kk_integer_t _x7203 = kk_integer_dup(n_6159); /*int*/
    cq = kk_std_core_cdiv_exp10(_x7202, _x7203, _ctx); /*int*/
    kk_integer_t cr;
    kk_integer_t _x7204;
    kk_integer_t _x21 = x.num;
    kk_integer_dup(_x21);
    _x7204 = _x21; /*int*/
    kk_integer_t _x7205;
    kk_integer_t _x7206 = kk_integer_dup(cq); /*int*/
    kk_integer_t _x7207 = kk_integer_dup(n_6159); /*int*/
    _x7205 = kk_std_core_mul_exp10(_x7206, _x7207, _ctx); /*int*/
    cr = kk_integer_sub(_x7204,_x7205,kk_context()); /*int*/
    _match_6668 = kk_std_core_types__new_dash__lp__comma__rp_(kk_integer_box(cq), kk_integer_box(cr), _ctx); /*(4, 5)*/
  }
  kk_box_t _box_x6422 = _match_6668.fst;
  kk_box_t _box_x6423 = _match_6668.snd;
  kk_integer_t cq0 = kk_integer_unbox(_box_x6422);
  kk_integer_t cr0 = kk_integer_unbox(_box_x6423);
  kk_integer_dup(cq0);
  kk_integer_dup(cr0);
  kk_std_core_types__tuple2__drop(_match_6668, _ctx);
  bool _match_6669;
  bool _x7210;
  kk_integer_t _x7211 = kk_integer_dup(cr0); /*int*/
  _x7210 = kk_std_core_is_neg_2(_x7211, _ctx); /*bool*/
  _match_6669 = !(_x7210); /*bool*/
  if (_match_6669) {
    kk_integer_drop(n_6159, _ctx);
    _match_6667 = kk_std_core_types__new_dash__lp__comma__rp_(kk_integer_box(cq0), kk_integer_box(cr0), _ctx); /*(4, 5)*/
  }
  else {
    kk_integer_t _b_6436_6426 = kk_std_core_dec(cq0, _ctx); /*int*/;
    kk_integer_t _b_6437_6427;
    kk_integer_t _x7212 = kk_std_core_exp10(n_6159, _ctx); /*int*/
    _b_6437_6427 = kk_integer_add(cr0,_x7212,kk_context()); /*int*/
    _match_6667 = kk_std_core_types__new_dash__lp__comma__rp_(kk_integer_box(_b_6436_6426), kk_integer_box(_b_6437_6427), _ctx); /*(4, 5)*/
  }
  kk_box_t _box_x6428 = _match_6667.fst;
  kk_box_t _box_x6429 = _match_6667.snd;
  kk_integer_t q = kk_integer_unbox(_box_x6428);
  kk_integer_t r = kk_integer_unbox(_box_x6429);
  kk_integer_dup(q);
  kk_integer_dup(r);
  kk_std_core_types__tuple2__drop(_match_6667, _ctx);
  double _x7215 = kk_integer_as_double(q,kk_context()); /*double*/
  double _x7216;
  double _x7217 = kk_integer_as_double(r,kk_context()); /*double*/
  double _x7218;
  double p_6162;
  kk_integer_t _x7219;
  kk_integer_t _x4 = x.exp;
  kk_integer_dup(_x4);
  kk_std_num_decimal__decimal_drop(x, _ctx);
  _x7219 = _x4; /*int*/
  p_6162 = kk_integer_as_double(_x7219,kk_context()); /*double*/
  _x7218 = pow((0x1.4p3),p_6162); /*double*/
  _x7216 = (_x7217 * _x7218); /*double*/
  return (_x7215 + _x7216);
}
 
// The exponent of a decimal if displayed in scientific notation.
// `11.2e-1.decimal.exponent == 0`

kk_integer_t kk_std_num_decimal_exponent(kk_std_num_decimal__decimal d, kk_context_t* _ctx) { /* (d : decimal) -> int */ 
  kk_integer_t _x7220;
  kk_integer_t _x7221;
  kk_integer_t _x7222;
  kk_integer_t _x = d.num;
  kk_integer_dup(_x);
  _x7222 = _x; /*int*/
  _x7221 = kk_std_core_count_digits(_x7222, _ctx); /*int*/
  kk_integer_t _x7223;
  kk_integer_t _x0 = d.exp;
  kk_integer_dup(_x0);
  kk_std_num_decimal__decimal_drop(d, _ctx);
  _x7223 = _x0; /*int*/
  _x7220 = kk_integer_add(_x7221,_x7223,kk_context()); /*int*/
  return kk_integer_sub(_x7220,(kk_integer_from_small(1)),kk_context());
}
 
// Round a `:decimal` using to the largest integer that is not larger than `x`.

kk_std_num_decimal__decimal kk_std_num_decimal_floor(kk_std_num_decimal__decimal x, kk_context_t* _ctx) { /* (x : decimal) -> decimal */ 
  kk_std_core_types__optional rnd_6167 = kk_std_core_types__new_Optional(kk_std_num_decimal__round_box(kk_std_num_decimal__new_Floor(_ctx), _ctx), _ctx); /*optional<std/num/decimal/round>*/;
  kk_std_core_types__optional _x7224 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(0)), _ctx); /*optional<35>*/
  kk_std_core_types__optional _x7225;
  kk_box_t _x7226;
  kk_std_num_decimal__round _x7227;
  if (kk_std_core_types__is_Optional(rnd_6167)) {
    kk_box_t _box_x6441 = rnd_6167._cons.Optional.value;
    kk_std_num_decimal__round _rnd_3169 = kk_std_num_decimal__round_unbox(_box_x6441, NULL);
    kk_std_core_types__optional_drop(rnd_6167, _ctx);
    _x7227 = _rnd_3169; /*std/num/decimal/round*/
    goto _match7228;
  }
  _x7227 = kk_std_num_decimal__new_Half_even(_ctx); /*std/num/decimal/round*/
  _match7228: ;
  _x7226 = kk_std_num_decimal__round_box(_x7227, _ctx); /*35*/
  _x7225 = kk_std_core_types__new_Optional(_x7226, _ctx); /*optional<35>*/
  return kk_std_num_decimal_round_to_prec(x, _x7224, _x7225, _ctx);
}
 
// Return the 'floored' fraction, always in the range [`0`,`1.0`).
// `x.floor + x.ffraction == x`

kk_std_num_decimal__decimal kk_std_num_decimal_ffraction(kk_std_num_decimal__decimal x, kk_context_t* _ctx) { /* (x : decimal) -> decimal */ 
  bool _match_6663;
  bool _x7230;
  kk_std_core_types__order x_21555;
  kk_integer_t _x7231;
  kk_integer_t _x = x.exp;
  kk_integer_dup(_x);
  _x7231 = _x; /*int*/
  x_21555 = kk_int_as_order(kk_integer_signum(_x7231,kk_context()),kk_context()); /*order*/
  kk_integer_t _x7232 = kk_std_core_int_5(x_21555, _ctx); /*int*/
  kk_integer_t _x7233;
  kk_std_core_types__order _x7234 = kk_std_core_types__new_Lt(_ctx); /*order*/
  if (kk_std_core_types__is_Lt(_x7234)) {
    _x7233 = kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context()); /*int*/
    goto _match7235;
  }
  if (kk_std_core_types__is_Eq(_x7234)) {
    _x7233 = kk_integer_from_small(0); /*int*/
    goto _match7235;
  }
  _x7233 = kk_integer_from_small(1); /*int*/
  _match7235: ;
  _x7230 = kk_integer_eq(_x7232,_x7233,kk_context()); /*bool*/
  _match_6663 = !(_x7230); /*bool*/
  if (_match_6663) {
    kk_std_num_decimal__decimal_drop(x, _ctx);
    return kk_std_num_decimal__new_Decimal(kk_integer_from_small(0), kk_integer_from_small(0), _ctx);
  }
  kk_std_num_decimal__decimal y_6171;
  kk_std_num_decimal__decimal _x7236 = kk_std_num_decimal__decimal_dup(x); /*std/num/decimal/decimal*/
  y_6171 = kk_std_num_decimal_floor(_x7236, _ctx); /*std/num/decimal/decimal*/
  kk_std_num_decimal__decimal y0_6173 = kk_std_num_decimal__lp__tilde__rp_(y_6171, _ctx); /*std/num/decimal/decimal*/;
  kk_integer_t e;
  bool _match_6664;
  kk_integer_t _x7237;
  kk_integer_t _x0 = x.exp;
  kk_integer_dup(_x0);
  _x7237 = _x0; /*int*/
  kk_integer_t _x7238;
  kk_integer_t _x1 = y0_6173.exp;
  kk_integer_dup(_x1);
  _x7238 = _x1; /*int*/
  _match_6664 = kk_integer_lte(_x7237,_x7238,kk_context()); /*bool*/
  if (_match_6664) {
    kk_integer_t _x00 = x.exp;
    kk_integer_dup(_x00);
    e = _x00; /*int*/
  }
  else {
    kk_integer_t _x10 = y0_6173.exp;
    kk_integer_dup(_x10);
    e = _x10; /*int*/
  }
  kk_std_num_decimal__decimal xx;
  kk_integer_t _x7239 = kk_integer_dup(e); /*int*/
  xx = kk_std_num_decimal_expand(x, _x7239, _ctx); /*std/num/decimal/decimal*/
  kk_std_num_decimal__decimal yy;
  kk_integer_t _x7240 = kk_integer_dup(e); /*int*/
  yy = kk_std_num_decimal_expand(y0_6173, _x7240, _ctx); /*std/num/decimal/decimal*/
  kk_integer_t _x7241;
  kk_integer_t _x7242;
  kk_integer_t _x2 = xx.num;
  kk_integer_dup(_x2);
  kk_std_num_decimal__decimal_drop(xx, _ctx);
  _x7242 = _x2; /*int*/
  kk_integer_t _x7243;
  kk_integer_t _x3 = yy.num;
  kk_integer_dup(_x3);
  kk_std_num_decimal__decimal_drop(yy, _ctx);
  _x7243 = _x3; /*int*/
  _x7241 = kk_integer_add(_x7242,_x7243,kk_context()); /*int*/
  return kk_std_num_decimal__new_Decimal(_x7241, e, _ctx);
}
 
// Truncate a `:decimal` to an integer by rounding towards zero.

kk_std_num_decimal__decimal kk_std_num_decimal_truncate(kk_std_num_decimal__decimal x, kk_context_t* _ctx) { /* (x : decimal) -> decimal */ 
  kk_std_core_types__optional rnd_6181 = kk_std_core_types__new_Optional(kk_std_num_decimal__round_box(kk_std_num_decimal__new_Truncate(_ctx), _ctx), _ctx); /*optional<std/num/decimal/round>*/;
  kk_std_core_types__optional _x7244 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(0)), _ctx); /*optional<35>*/
  kk_std_core_types__optional _x7245;
  kk_box_t _x7246;
  kk_std_num_decimal__round _x7247;
  if (kk_std_core_types__is_Optional(rnd_6181)) {
    kk_box_t _box_x6448 = rnd_6181._cons.Optional.value;
    kk_std_num_decimal__round _rnd_3169 = kk_std_num_decimal__round_unbox(_box_x6448, NULL);
    kk_std_core_types__optional_drop(rnd_6181, _ctx);
    _x7247 = _rnd_3169; /*std/num/decimal/round*/
    goto _match7248;
  }
  _x7247 = kk_std_num_decimal__new_Half_even(_ctx); /*std/num/decimal/round*/
  _match7248: ;
  _x7246 = kk_std_num_decimal__round_box(_x7247, _ctx); /*35*/
  _x7245 = kk_std_core_types__new_Optional(_x7246, _ctx); /*optional<35>*/
  return kk_std_num_decimal_round_to_prec(x, _x7244, _x7245, _ctx);
}
 
// Return the 'truncated' fraction, always in the range (`-1.0`,`1.0`).
// `x.truncate + x.fraction == x`

kk_std_num_decimal__decimal kk_std_num_decimal_fraction(kk_std_num_decimal__decimal x, kk_context_t* _ctx) { /* (x : decimal) -> decimal */ 
  bool _match_6660;
  bool _x7250;
  kk_std_core_types__order x_21555;
  kk_integer_t _x7251;
  kk_integer_t _x = x.exp;
  kk_integer_dup(_x);
  _x7251 = _x; /*int*/
  x_21555 = kk_int_as_order(kk_integer_signum(_x7251,kk_context()),kk_context()); /*order*/
  kk_integer_t _x7252 = kk_std_core_int_5(x_21555, _ctx); /*int*/
  kk_integer_t _x7253;
  kk_std_core_types__order _x7254 = kk_std_core_types__new_Lt(_ctx); /*order*/
  if (kk_std_core_types__is_Lt(_x7254)) {
    _x7253 = kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context()); /*int*/
    goto _match7255;
  }
  if (kk_std_core_types__is_Eq(_x7254)) {
    _x7253 = kk_integer_from_small(0); /*int*/
    goto _match7255;
  }
  _x7253 = kk_integer_from_small(1); /*int*/
  _match7255: ;
  _x7250 = kk_integer_eq(_x7252,_x7253,kk_context()); /*bool*/
  _match_6660 = !(_x7250); /*bool*/
  if (_match_6660) {
    kk_std_num_decimal__decimal_drop(x, _ctx);
    return kk_std_num_decimal__new_Decimal(kk_integer_from_small(0), kk_integer_from_small(0), _ctx);
  }
  kk_std_num_decimal__decimal y_6185;
  kk_std_num_decimal__decimal _x7256 = kk_std_num_decimal__decimal_dup(x); /*std/num/decimal/decimal*/
  y_6185 = kk_std_num_decimal_truncate(_x7256, _ctx); /*std/num/decimal/decimal*/
  kk_std_num_decimal__decimal y0_6187 = kk_std_num_decimal__lp__tilde__rp_(y_6185, _ctx); /*std/num/decimal/decimal*/;
  kk_integer_t e;
  bool _match_6661;
  kk_integer_t _x7257;
  kk_integer_t _x0 = x.exp;
  kk_integer_dup(_x0);
  _x7257 = _x0; /*int*/
  kk_integer_t _x7258;
  kk_integer_t _x1 = y0_6187.exp;
  kk_integer_dup(_x1);
  _x7258 = _x1; /*int*/
  _match_6661 = kk_integer_lte(_x7257,_x7258,kk_context()); /*bool*/
  if (_match_6661) {
    kk_integer_t _x00 = x.exp;
    kk_integer_dup(_x00);
    e = _x00; /*int*/
  }
  else {
    kk_integer_t _x10 = y0_6187.exp;
    kk_integer_dup(_x10);
    e = _x10; /*int*/
  }
  kk_std_num_decimal__decimal xx;
  kk_integer_t _x7259 = kk_integer_dup(e); /*int*/
  xx = kk_std_num_decimal_expand(x, _x7259, _ctx); /*std/num/decimal/decimal*/
  kk_std_num_decimal__decimal yy;
  kk_integer_t _x7260 = kk_integer_dup(e); /*int*/
  yy = kk_std_num_decimal_expand(y0_6187, _x7260, _ctx); /*std/num/decimal/decimal*/
  kk_integer_t _x7261;
  kk_integer_t _x7262;
  kk_integer_t _x2 = xx.num;
  kk_integer_dup(_x2);
  kk_std_num_decimal__decimal_drop(xx, _ctx);
  _x7262 = _x2; /*int*/
  kk_integer_t _x7263;
  kk_integer_t _x3 = yy.num;
  kk_integer_dup(_x3);
  kk_std_num_decimal__decimal_drop(yy, _ctx);
  _x7263 = _x3; /*int*/
  _x7261 = kk_integer_add(_x7262,_x7263,kk_context()); /*int*/
  return kk_std_num_decimal__new_Decimal(_x7261, e, _ctx);
}
 
// Round a `:decimal` number to an integer an optional rounding mode `rnd` (=`Half-even`).

kk_integer_t kk_std_num_decimal_int(kk_std_num_decimal__decimal x, kk_std_core_types__optional rnd, kk_context_t* _ctx) { /* (x : decimal, rnd : optional<round>) -> int */ 
  kk_std_num_decimal__decimal y;
  kk_std_core_types__optional rnd0_6195;
  kk_box_t _x7264;
  kk_std_num_decimal__round _x7265;
  if (kk_std_core_types__is_Optional(rnd)) {
    kk_box_t _box_x6452 = rnd._cons.Optional.value;
    kk_std_num_decimal__round _rnd_4003 = kk_std_num_decimal__round_unbox(_box_x6452, NULL);
    kk_std_core_types__optional_drop(rnd, _ctx);
    _x7265 = _rnd_4003; /*std/num/decimal/round*/
    goto _match7266;
  }
  _x7265 = kk_std_num_decimal__new_Half_even(_ctx); /*std/num/decimal/round*/
  _match7266: ;
  _x7264 = kk_std_num_decimal__round_box(_x7265, _ctx); /*35*/
  rnd0_6195 = kk_std_core_types__new_Optional(_x7264, _ctx); /*optional<std/num/decimal/round>*/
  kk_std_core_types__optional _x7268 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(0)), _ctx); /*optional<35>*/
  kk_std_core_types__optional _x7269;
  kk_box_t _x7270;
  kk_std_num_decimal__round _x7271;
  if (kk_std_core_types__is_Optional(rnd0_6195)) {
    kk_box_t _box_x6456 = rnd0_6195._cons.Optional.value;
    kk_std_num_decimal__round _rnd_3169 = kk_std_num_decimal__round_unbox(_box_x6456, NULL);
    kk_std_core_types__optional_drop(rnd0_6195, _ctx);
    _x7271 = _rnd_3169; /*std/num/decimal/round*/
    goto _match7272;
  }
  _x7271 = kk_std_num_decimal__new_Half_even(_ctx); /*std/num/decimal/round*/
  _match7272: ;
  _x7270 = kk_std_num_decimal__round_box(_x7271, _ctx); /*35*/
  _x7269 = kk_std_core_types__new_Optional(_x7270, _ctx); /*optional<35>*/
  y = kk_std_num_decimal_round_to_prec(x, _x7268, _x7269, _ctx); /*std/num/decimal/decimal*/
  bool _match_6658;
  kk_std_core_types__order x_21426;
  kk_integer_t _x7274;
  kk_integer_t _x = y.exp;
  kk_integer_dup(_x);
  _x7274 = _x; /*int*/
  x_21426 = kk_int_as_order(kk_integer_signum(_x7274,kk_context()),kk_context()); /*order*/
  kk_integer_t _x7275 = kk_std_core_int_5(x_21426, _ctx); /*int*/
  kk_integer_t _x7276;
  kk_std_core_types__order _x7277 = kk_std_core_types__new_Gt(_ctx); /*order*/
  if (kk_std_core_types__is_Lt(_x7277)) {
    _x7276 = kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context()); /*int*/
    goto _match7278;
  }
  if (kk_std_core_types__is_Eq(_x7277)) {
    _x7276 = kk_integer_from_small(0); /*int*/
    goto _match7278;
  }
  _x7276 = kk_integer_from_small(1); /*int*/
  _match7278: ;
  _match_6658 = kk_integer_eq(_x7275,_x7276,kk_context()); /*bool*/
  if (_match_6658) {
    kk_integer_t _x7279;
    kk_integer_t _x0 = y.num;
    kk_integer_dup(_x0);
    _x7279 = _x0; /*int*/
    kk_integer_t _x7280;
    kk_integer_t _x1 = y.exp;
    kk_integer_dup(_x1);
    kk_std_num_decimal__decimal_drop(y, _ctx);
    _x7280 = _x1; /*int*/
    return kk_std_core_mul_exp10(_x7279, _x7280, _ctx);
  }
  kk_integer_t _x2 = y.num;
  kk_integer_dup(_x2);
  kk_std_num_decimal__decimal_drop(y, _ctx);
  return _x2;
}

kk_integer_t kk_std_num_decimal_maxprecise;

kk_integer_t kk_std_num_decimal_minprecise;

bool kk_std_num_decimal_is_precise(kk_integer_t i, kk_context_t* _ctx) { /* (i : int) -> bool */ 
  bool _match_6657;
  kk_integer_t _x7283 = kk_integer_dup(i); /*int*/
  kk_integer_t _x7284 = kk_integer_dup(kk_std_num_decimal_minprecise); /*int*/
  _match_6657 = kk_integer_gt(_x7283,_x7284,kk_context()); /*bool*/
  if (_match_6657) {
    kk_integer_t _x7285 = kk_integer_from_double((0x1.c6bf52634p49),kk_context()); /*int*/
    return kk_integer_lt(i,_x7285,kk_context());
  }
  kk_integer_drop(i, _ctx);
  return false;
}
 
// monadic lift

kk_integer_t kk_std_num_decimal__mlift6016_pdecimal(kk_char_t wild__0, kk_context_t* _ctx) { /* (wild_0 : char) -> std/text/parse/parse int */ 
  return kk_std_text_parse_pint(_ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_num_decimal__mlift6017_pdecimal_fun7304__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_decimal__mlift6017_pdecimal_fun7304(kk_function_t _fself, kk_box_t _b_6474, kk_box_t _b_6475, kk_context_t* _ctx);
static kk_function_t kk_std_num_decimal__new_mlift6017_pdecimal_fun7304(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_decimal__mlift6017_pdecimal_fun7304, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_decimal__mlift6017_pdecimal_fun7304(kk_function_t _fself, kk_box_t _b_6474, kk_box_t _b_6475, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_num_decimal__decimal _x7305;
  kk_integer_t _x7306 = kk_integer_unbox(_b_6474); /*int*/
  kk_std_core_types__optional _x7307 = kk_std_core_types__optional_unbox(_b_6475, _ctx); /*optional<int>*/
  _x7305 = kk_std_num_decimal_decimal_exp(_x7306, _x7307, _ctx); /*std/num/decimal/decimal*/
  return kk_std_num_decimal__decimal_box(_x7305, _ctx);
}


// lift anonymous function
struct kk_std_num_decimal__mlift6017_pdecimal_fun7309__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_decimal__mlift6017_pdecimal_fun7309(kk_function_t _fself, kk_box_t _b_6481, kk_context_t* _ctx);
static kk_function_t kk_std_num_decimal__new_mlift6017_pdecimal_fun7309(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_decimal__mlift6017_pdecimal_fun7309, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_decimal__mlift6017_pdecimal_fun7309(kk_function_t _fself, kk_box_t _b_6481, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_num_decimal__decimal _x7310;
  kk_std_num_decimal__decimal _x7311 = kk_std_num_decimal__decimal_unbox(_b_6481, _ctx); /*std/num/decimal/decimal*/
  _x7310 = kk_std_num_decimal__lp__tilde__rp_(_x7311, _ctx); /*std/num/decimal/decimal*/
  return kk_std_num_decimal__decimal_box(_x7310, _ctx);
}

kk_std_num_decimal__decimal kk_std_num_decimal__mlift6017_pdecimal(kk_string_t frac, bool neg, kk_string_t whole, kk_integer_t exp0, kk_context_t* _ctx) { /* (frac : string, neg : bool, whole : string, exp : int) -> std/text/parse/parse decimal */ 
  kk_std_num_decimal__decimal i;
  kk_integer_t _x1;
  kk_string_t s_6203;
  kk_string_t _x7287 = kk_string_dup(frac); /*string*/
  s_6203 = kk_std_core__lp__plus__plus__1_rp_(whole, _x7287, _ctx); /*string*/
  kk_std_core_types__optional default_6204 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(0)), _ctx); /*optional<int>*/;
  bool _match_6655;
  kk_string_t _x7288 = kk_string_dup(s_6203); /*string*/
  _match_6655 = kk_std_core_is_empty_2(_x7288, _ctx); /*bool*/
  if (_match_6655) {
    kk_string_drop(s_6203, _ctx);
    if (kk_std_core_types__is_Optional(default_6204)) {
      kk_box_t _box_x6462 = default_6204._cons.Optional.value;
      kk_integer_t _default_19378 = kk_integer_unbox(_box_x6462);
      kk_integer_dup(_default_19378);
      kk_std_core_types__optional_drop(default_6204, _ctx);
      _x1 = _default_19378; /*int*/
      goto _match7289;
    }
    _x1 = kk_integer_from_small(0); /*int*/
    _match7289: ;
  }
  else {
    kk_std_core_types__maybe m_21736;
    kk_std_core_types__optional hex0_21739;
    kk_box_t _x7291;
    bool _x7292;
    kk_std_core_types__optional _match_6656 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
    if (kk_std_core_types__is_Optional(_match_6656)) {
      kk_box_t _box_x6463 = _match_6656._cons.Optional.value;
      bool _hex_19382 = kk_bool_unbox(_box_x6463);
      kk_std_core_types__optional_drop(_match_6656, _ctx);
      _x7292 = _hex_19382; /*bool*/
      goto _match7293;
    }
    _x7292 = false; /*bool*/
    _match7293: ;
    _x7291 = kk_bool_box(_x7292); /*35*/
    hex0_21739 = kk_std_core_types__new_Optional(_x7291, _ctx); /*optional<bool>*/
    kk_string_t _x7295 = kk_std_core_trim(s_6203, _ctx); /*string*/
    bool _x7296;
    if (kk_std_core_types__is_Optional(hex0_21739)) {
      kk_box_t _box_x6466 = hex0_21739._cons.Optional.value;
      bool _hex_19366 = kk_bool_unbox(_box_x6466);
      kk_std_core_types__optional_drop(hex0_21739, _ctx);
      _x7296 = _hex_19366; /*bool*/
      goto _match7297;
    }
    _x7296 = false; /*bool*/
    _match7297: ;
    m_21736 = kk_std_core_xparse_int(_x7295, _x7296, _ctx); /*maybe<int>*/
    if (kk_std_core_types__is_Nothing(m_21736)) {
      if (kk_std_core_types__is_Optional(default_6204)) {
        kk_box_t _box_x6467 = default_6204._cons.Optional.value;
        kk_integer_t _default_193780 = kk_integer_unbox(_box_x6467);
        kk_integer_dup(_default_193780);
        kk_std_core_types__optional_drop(default_6204, _ctx);
        _x1 = _default_193780; /*int*/
        goto _match7299;
      }
      _x1 = kk_integer_from_small(0); /*int*/
      _match7299: ;
    }
    else {
      kk_box_t _box_x6468 = m_21736._cons.Just.value;
      kk_integer_t x = kk_integer_unbox(_box_x6468);
      kk_integer_dup(x);
      kk_std_core_types__maybe_drop(m_21736, _ctx);
      kk_std_core_types__optional_drop(default_6204, _ctx);
      _x1 = x; /*int*/
    }
  }
  kk_std_core_types__optional _x2;
  kk_integer_t _b_6470_6469;
  kk_integer_t _x7302 = kk_std_core_count_1(frac, _ctx); /*int*/
  _b_6470_6469 = kk_integer_sub(exp0,_x7302,kk_context()); /*int*/
  _x2 = kk_std_core_types__new_Optional(kk_integer_box(_b_6470_6469), _ctx); /*optional<int>*/
  kk_box_t _x7303 = kk_std_core_hnd__open_none2(kk_std_num_decimal__new_mlift6017_pdecimal_fun7304(_ctx), kk_integer_box(_x1), kk_std_core_types__optional_box(_x2, _ctx), _ctx); /*3*/
  i = kk_std_num_decimal__decimal_unbox(_x7303, _ctx); /*std/num/decimal/decimal*/
  if (neg) {
    kk_box_t _x7308 = kk_std_core_hnd__open_none1(kk_std_num_decimal__new_mlift6017_pdecimal_fun7309(_ctx), kk_std_num_decimal__decimal_box(i, _ctx), _ctx); /*2*/
    return kk_std_num_decimal__decimal_unbox(_x7308, _ctx);
  }
  return i;
}
 
// monadic lift

kk_string_t kk_std_num_decimal__mlift6018_pdecimal(kk_char_t wild__, kk_context_t* _ctx) { /* (wild_ : char) -> std/text/parse/parse string */ 
  return kk_std_text_parse_digits(_ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_num_decimal__mlift6019_pdecimal_fun7313__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_decimal__mlift6019_pdecimal_fun7313(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_decimal__new_mlift6019_pdecimal_fun7313(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_decimal__mlift6019_pdecimal_fun7313, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_std_num_decimal__mlift6019_pdecimal_fun7318__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_decimal__mlift6019_pdecimal_fun7318(kk_function_t _fself, kk_box_t _b_6485, kk_context_t* _ctx);
static kk_function_t kk_std_num_decimal__new_mlift6019_pdecimal_fun7318(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_decimal__mlift6019_pdecimal_fun7318, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_decimal__mlift6019_pdecimal_fun7318(kk_function_t _fself, kk_box_t _b_6485, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_integer_t _x7319;
  kk_char_t _x7320 = kk_char_unbox(_b_6485, _ctx); /*char*/
  _x7319 = kk_std_num_decimal__mlift6016_pdecimal(_x7320, _ctx); /*int*/
  return kk_integer_box(_x7319);
}
static kk_box_t kk_std_num_decimal__mlift6019_pdecimal_fun7313(kk_function_t _fself, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_integer_t _x7314;
  kk_char_t x0_6208;
  kk_string_t _x7315;
  kk_define_string_literal(, _s7316, 2, "eE")
  _x7315 = kk_string_dup(_s7316); /*string*/
  x0_6208 = kk_std_text_parse_one_of(_x7315, _ctx); /*char*/
  if (kk_yielding(kk_context())) {
    kk_box_t _x7317 = kk_std_core_hnd_yield_extend(kk_std_num_decimal__new_mlift6019_pdecimal_fun7318(_ctx), _ctx); /*2*/
    _x7314 = kk_integer_unbox(_x7317); /*int*/
  }
  else {
    _x7314 = kk_std_num_decimal__mlift6016_pdecimal(x0_6208, _ctx); /*int*/
  }
  return kk_integer_box(_x7314);
}


// lift anonymous function
struct kk_std_num_decimal__mlift6019_pdecimal_fun7322__t {
  struct kk_function_s _base;
  kk_string_t frac;
  kk_string_t whole;
  bool neg;
};
static kk_box_t kk_std_num_decimal__mlift6019_pdecimal_fun7322(kk_function_t _fself, kk_box_t _b_6492, kk_context_t* _ctx);
static kk_function_t kk_std_num_decimal__new_mlift6019_pdecimal_fun7322(kk_string_t frac, kk_string_t whole, bool neg, kk_context_t* _ctx) {
  struct kk_std_num_decimal__mlift6019_pdecimal_fun7322__t* _self = kk_function_alloc_as(struct kk_std_num_decimal__mlift6019_pdecimal_fun7322__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_num_decimal__mlift6019_pdecimal_fun7322, kk_context());
  _self->frac = frac;
  _self->whole = whole;
  _self->neg = neg;
  return &_self->_base;
}

static kk_box_t kk_std_num_decimal__mlift6019_pdecimal_fun7322(kk_function_t _fself, kk_box_t _b_6492, kk_context_t* _ctx) {
  struct kk_std_num_decimal__mlift6019_pdecimal_fun7322__t* _self = kk_function_as(struct kk_std_num_decimal__mlift6019_pdecimal_fun7322__t*, _fself);
  kk_string_t frac = _self->frac; /* string */
  kk_string_t whole = _self->whole; /* string */
  bool neg = _self->neg; /* bool */
  kk_drop_match(_self, {kk_string_dup(frac);kk_string_dup(whole);;}, {}, _ctx)
  kk_std_num_decimal__decimal _x7323;
  kk_integer_t _x7324 = kk_integer_unbox(_b_6492); /*int*/
  _x7323 = kk_std_num_decimal__mlift6017_pdecimal(frac, neg, whole, _x7324, _ctx); /*std/num/decimal/decimal*/
  return kk_std_num_decimal__decimal_box(_x7323, _ctx);
}

kk_std_num_decimal__decimal kk_std_num_decimal__mlift6019_pdecimal(bool neg, kk_string_t whole, kk_string_t frac, kk_context_t* _ctx) { /* (neg : bool, whole : string, frac : string) -> std/text/parse/parse decimal */ 
  kk_integer_t x_6206;
  kk_box_t _x7312 = kk_std_text_parse_optional(kk_integer_box(kk_integer_from_small(0)), kk_std_num_decimal__new_mlift6019_pdecimal_fun7313(_ctx), _ctx); /*0*/
  x_6206 = kk_integer_unbox(_x7312); /*int*/
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_6206, _ctx);
    kk_box_t _x7321 = kk_std_core_hnd_yield_extend(kk_std_num_decimal__new_mlift6019_pdecimal_fun7322(frac, whole, neg, _ctx), _ctx); /*2*/
    return kk_std_num_decimal__decimal_unbox(_x7321, _ctx);
  }
  return kk_std_num_decimal__mlift6017_pdecimal(frac, neg, whole, x_6206, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_num_decimal__mlift6020_pdecimal_fun7329__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_decimal__mlift6020_pdecimal_fun7329(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_decimal__new_mlift6020_pdecimal_fun7329(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_decimal__mlift6020_pdecimal_fun7329, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_std_num_decimal__mlift6020_pdecimal_fun7332__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_decimal__mlift6020_pdecimal_fun7332(kk_function_t _fself, kk_box_t _b_6496, kk_context_t* _ctx);
static kk_function_t kk_std_num_decimal__new_mlift6020_pdecimal_fun7332(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_decimal__mlift6020_pdecimal_fun7332, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_decimal__mlift6020_pdecimal_fun7332(kk_function_t _fself, kk_box_t _b_6496, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x7333;
  kk_char_t _x7334 = kk_char_unbox(_b_6496, _ctx); /*char*/
  _x7333 = kk_std_num_decimal__mlift6018_pdecimal(_x7334, _ctx); /*string*/
  return kk_string_box(_x7333);
}
static kk_box_t kk_std_num_decimal__mlift6020_pdecimal_fun7329(kk_function_t _fself, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x7330;
  kk_char_t x0_6212 = kk_std_text_parse_char('.', _ctx); /*char*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x7331 = kk_std_core_hnd_yield_extend(kk_std_num_decimal__new_mlift6020_pdecimal_fun7332(_ctx), _ctx); /*2*/
    _x7330 = kk_string_unbox(_x7331); /*string*/
  }
  else {
    _x7330 = kk_std_num_decimal__mlift6018_pdecimal(x0_6212, _ctx); /*string*/
  }
  return kk_string_box(_x7330);
}


// lift anonymous function
struct kk_std_num_decimal__mlift6020_pdecimal_fun7336__t {
  struct kk_function_s _base;
  kk_string_t whole;
  bool neg;
};
static kk_box_t kk_std_num_decimal__mlift6020_pdecimal_fun7336(kk_function_t _fself, kk_box_t _b_6503, kk_context_t* _ctx);
static kk_function_t kk_std_num_decimal__new_mlift6020_pdecimal_fun7336(kk_string_t whole, bool neg, kk_context_t* _ctx) {
  struct kk_std_num_decimal__mlift6020_pdecimal_fun7336__t* _self = kk_function_alloc_as(struct kk_std_num_decimal__mlift6020_pdecimal_fun7336__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_num_decimal__mlift6020_pdecimal_fun7336, kk_context());
  _self->whole = whole;
  _self->neg = neg;
  return &_self->_base;
}

static kk_box_t kk_std_num_decimal__mlift6020_pdecimal_fun7336(kk_function_t _fself, kk_box_t _b_6503, kk_context_t* _ctx) {
  struct kk_std_num_decimal__mlift6020_pdecimal_fun7336__t* _self = kk_function_as(struct kk_std_num_decimal__mlift6020_pdecimal_fun7336__t*, _fself);
  kk_string_t whole = _self->whole; /* string */
  bool neg = _self->neg; /* bool */
  kk_drop_match(_self, {kk_string_dup(whole);;}, {}, _ctx)
  kk_std_num_decimal__decimal _x7337;
  kk_string_t _x7338 = kk_string_unbox(_b_6503); /*string*/
  _x7337 = kk_std_num_decimal__mlift6019_pdecimal(neg, whole, _x7338, _ctx); /*std/num/decimal/decimal*/
  return kk_std_num_decimal__decimal_box(_x7337, _ctx);
}

kk_std_num_decimal__decimal kk_std_num_decimal__mlift6020_pdecimal(bool neg, kk_string_t whole, kk_context_t* _ctx) { /* (neg : bool, whole : string) -> std/text/parse/parse decimal */ 
  kk_string_t x_6210;
  kk_box_t _x7325;
  kk_box_t _x7326;
  kk_string_t _x7327 = kk_string_empty(); /*string*/
  _x7326 = kk_string_box(_x7327); /*0*/
  _x7325 = kk_std_text_parse_optional(_x7326, kk_std_num_decimal__new_mlift6020_pdecimal_fun7329(_ctx), _ctx); /*0*/
  x_6210 = kk_string_unbox(_x7325); /*string*/
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_6210, _ctx);
    kk_box_t _x7335 = kk_std_core_hnd_yield_extend(kk_std_num_decimal__new_mlift6020_pdecimal_fun7336(whole, neg, _ctx), _ctx); /*2*/
    return kk_std_num_decimal__decimal_unbox(_x7335, _ctx);
  }
  return kk_std_num_decimal__mlift6019_pdecimal(neg, whole, x_6210, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_num_decimal__mlift6021_pdecimal_fun7340__t {
  struct kk_function_s _base;
  bool neg;
};
static kk_box_t kk_std_num_decimal__mlift6021_pdecimal_fun7340(kk_function_t _fself, kk_box_t _b_6507, kk_context_t* _ctx);
static kk_function_t kk_std_num_decimal__new_mlift6021_pdecimal_fun7340(bool neg, kk_context_t* _ctx) {
  struct kk_std_num_decimal__mlift6021_pdecimal_fun7340__t* _self = kk_function_alloc_as(struct kk_std_num_decimal__mlift6021_pdecimal_fun7340__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_num_decimal__mlift6021_pdecimal_fun7340, kk_context());
  _self->neg = neg;
  return &_self->_base;
}

static kk_box_t kk_std_num_decimal__mlift6021_pdecimal_fun7340(kk_function_t _fself, kk_box_t _b_6507, kk_context_t* _ctx) {
  struct kk_std_num_decimal__mlift6021_pdecimal_fun7340__t* _self = kk_function_as(struct kk_std_num_decimal__mlift6021_pdecimal_fun7340__t*, _fself);
  bool neg = _self->neg; /* bool */
  kk_drop_match(_self, {;}, {}, _ctx)
  kk_std_num_decimal__decimal _x7341;
  kk_string_t _x7342 = kk_string_unbox(_b_6507); /*string*/
  _x7341 = kk_std_num_decimal__mlift6020_pdecimal(neg, _x7342, _ctx); /*std/num/decimal/decimal*/
  return kk_std_num_decimal__decimal_box(_x7341, _ctx);
}

kk_std_num_decimal__decimal kk_std_num_decimal__mlift6021_pdecimal(bool neg, kk_context_t* _ctx) { /* (neg : bool) -> std/text/parse/parse decimal */ 
  kk_string_t x_6214 = kk_std_text_parse_digits(_ctx); /*string*/;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_6214, _ctx);
    kk_box_t _x7339 = kk_std_core_hnd_yield_extend(kk_std_num_decimal__new_mlift6021_pdecimal_fun7340(neg, _ctx), _ctx); /*2*/
    return kk_std_num_decimal__decimal_unbox(_x7339, _ctx);
  }
  return kk_std_num_decimal__mlift6020_pdecimal(neg, x_6214, _ctx);
}


// lift anonymous function
struct kk_std_num_decimal_pdecimal_fun7344__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_decimal_pdecimal_fun7344(kk_function_t _fself, kk_box_t _b_6511, kk_context_t* _ctx);
static kk_function_t kk_std_num_decimal_new_pdecimal_fun7344(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_decimal_pdecimal_fun7344, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_decimal_pdecimal_fun7344(kk_function_t _fself, kk_box_t _b_6511, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_num_decimal__decimal _x7345;
  bool _x7346 = kk_bool_unbox(_b_6511); /*bool*/
  _x7345 = kk_std_num_decimal__mlift6021_pdecimal(_x7346, _ctx); /*std/num/decimal/decimal*/
  return kk_std_num_decimal__decimal_box(_x7345, _ctx);
}


// lift anonymous function
struct kk_std_num_decimal_pdecimal_fun7348__t {
  struct kk_function_s _base;
  bool x_6216;
};
static kk_box_t kk_std_num_decimal_pdecimal_fun7348(kk_function_t _fself, kk_box_t _b_6513, kk_context_t* _ctx);
static kk_function_t kk_std_num_decimal_new_pdecimal_fun7348(bool x_6216, kk_context_t* _ctx) {
  struct kk_std_num_decimal_pdecimal_fun7348__t* _self = kk_function_alloc_as(struct kk_std_num_decimal_pdecimal_fun7348__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_num_decimal_pdecimal_fun7348, kk_context());
  _self->x_6216 = x_6216;
  return &_self->_base;
}

static kk_box_t kk_std_num_decimal_pdecimal_fun7348(kk_function_t _fself, kk_box_t _b_6513, kk_context_t* _ctx) {
  struct kk_std_num_decimal_pdecimal_fun7348__t* _self = kk_function_as(struct kk_std_num_decimal_pdecimal_fun7348__t*, _fself);
  bool x_6216 = _self->x_6216; /* bool */
  kk_drop_match(_self, {;}, {}, _ctx)
  kk_std_num_decimal__decimal _x7349;
  kk_string_t _x7350 = kk_string_unbox(_b_6513); /*string*/
  _x7349 = kk_std_num_decimal__mlift6020_pdecimal(x_6216, _x7350, _ctx); /*std/num/decimal/decimal*/
  return kk_std_num_decimal__decimal_box(_x7349, _ctx);
}


// lift anonymous function
struct kk_std_num_decimal_pdecimal_fun7355__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_decimal_pdecimal_fun7355(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_decimal_new_pdecimal_fun7355(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_decimal_pdecimal_fun7355, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_std_num_decimal_pdecimal_fun7358__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_decimal_pdecimal_fun7358(kk_function_t _fself, kk_box_t _b_6515, kk_context_t* _ctx);
static kk_function_t kk_std_num_decimal_new_pdecimal_fun7358(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_decimal_pdecimal_fun7358, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_decimal_pdecimal_fun7358(kk_function_t _fself, kk_box_t _b_6515, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x7359;
  kk_char_t _x7360 = kk_char_unbox(_b_6515, _ctx); /*char*/
  _x7359 = kk_std_num_decimal__mlift6018_pdecimal(_x7360, _ctx); /*string*/
  return kk_string_box(_x7359);
}
static kk_box_t kk_std_num_decimal_pdecimal_fun7355(kk_function_t _fself, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x7356;
  kk_char_t x2_6227 = kk_std_text_parse_char('.', _ctx); /*char*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x7357 = kk_std_core_hnd_yield_extend(kk_std_num_decimal_new_pdecimal_fun7358(_ctx), _ctx); /*2*/
    _x7356 = kk_string_unbox(_x7357); /*string*/
  }
  else {
    _x7356 = kk_std_num_decimal__mlift6018_pdecimal(x2_6227, _ctx); /*string*/
  }
  return kk_string_box(_x7356);
}


// lift anonymous function
struct kk_std_num_decimal_pdecimal_fun7362__t {
  struct kk_function_s _base;
  kk_string_t x0_6220;
  bool x_6216;
};
static kk_box_t kk_std_num_decimal_pdecimal_fun7362(kk_function_t _fself, kk_box_t _b_6522, kk_context_t* _ctx);
static kk_function_t kk_std_num_decimal_new_pdecimal_fun7362(kk_string_t x0_6220, bool x_6216, kk_context_t* _ctx) {
  struct kk_std_num_decimal_pdecimal_fun7362__t* _self = kk_function_alloc_as(struct kk_std_num_decimal_pdecimal_fun7362__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_num_decimal_pdecimal_fun7362, kk_context());
  _self->x0_6220 = x0_6220;
  _self->x_6216 = x_6216;
  return &_self->_base;
}

static kk_box_t kk_std_num_decimal_pdecimal_fun7362(kk_function_t _fself, kk_box_t _b_6522, kk_context_t* _ctx) {
  struct kk_std_num_decimal_pdecimal_fun7362__t* _self = kk_function_as(struct kk_std_num_decimal_pdecimal_fun7362__t*, _fself);
  kk_string_t x0_6220 = _self->x0_6220; /* string */
  bool x_6216 = _self->x_6216; /* bool */
  kk_drop_match(_self, {kk_string_dup(x0_6220);;}, {}, _ctx)
  kk_std_num_decimal__decimal _x7363;
  kk_string_t _x7364 = kk_string_unbox(_b_6522); /*string*/
  _x7363 = kk_std_num_decimal__mlift6019_pdecimal(x_6216, x0_6220, _x7364, _ctx); /*std/num/decimal/decimal*/
  return kk_std_num_decimal__decimal_box(_x7363, _ctx);
}


// lift anonymous function
struct kk_std_num_decimal_pdecimal_fun7366__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_decimal_pdecimal_fun7366(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_decimal_new_pdecimal_fun7366(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_decimal_pdecimal_fun7366, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_std_num_decimal_pdecimal_fun7371__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_decimal_pdecimal_fun7371(kk_function_t _fself, kk_box_t _b_6524, kk_context_t* _ctx);
static kk_function_t kk_std_num_decimal_new_pdecimal_fun7371(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_decimal_pdecimal_fun7371, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_decimal_pdecimal_fun7371(kk_function_t _fself, kk_box_t _b_6524, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_integer_t _x7372;
  kk_char_t _x7373 = kk_char_unbox(_b_6524, _ctx); /*char*/
  _x7372 = kk_std_num_decimal__mlift6016_pdecimal(_x7373, _ctx); /*int*/
  return kk_integer_box(_x7372);
}
static kk_box_t kk_std_num_decimal_pdecimal_fun7366(kk_function_t _fself, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_integer_t _x7367;
  kk_char_t x4_6233;
  kk_string_t _x7368;
  kk_define_string_literal(, _s7369, 2, "eE")
  _x7368 = kk_string_dup(_s7369); /*string*/
  x4_6233 = kk_std_text_parse_one_of(_x7368, _ctx); /*char*/
  if (kk_yielding(kk_context())) {
    kk_box_t _x7370 = kk_std_core_hnd_yield_extend(kk_std_num_decimal_new_pdecimal_fun7371(_ctx), _ctx); /*2*/
    _x7367 = kk_integer_unbox(_x7370); /*int*/
  }
  else {
    _x7367 = kk_std_num_decimal__mlift6016_pdecimal(x4_6233, _ctx); /*int*/
  }
  return kk_integer_box(_x7367);
}


// lift anonymous function
struct kk_std_num_decimal_pdecimal_fun7375__t {
  struct kk_function_s _base;
  kk_string_t x0_6220;
  kk_string_t x1_6224;
  bool x_6216;
};
static kk_box_t kk_std_num_decimal_pdecimal_fun7375(kk_function_t _fself, kk_box_t _b_6531, kk_context_t* _ctx);
static kk_function_t kk_std_num_decimal_new_pdecimal_fun7375(kk_string_t x0_6220, kk_string_t x1_6224, bool x_6216, kk_context_t* _ctx) {
  struct kk_std_num_decimal_pdecimal_fun7375__t* _self = kk_function_alloc_as(struct kk_std_num_decimal_pdecimal_fun7375__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_num_decimal_pdecimal_fun7375, kk_context());
  _self->x0_6220 = x0_6220;
  _self->x1_6224 = x1_6224;
  _self->x_6216 = x_6216;
  return &_self->_base;
}

static kk_box_t kk_std_num_decimal_pdecimal_fun7375(kk_function_t _fself, kk_box_t _b_6531, kk_context_t* _ctx) {
  struct kk_std_num_decimal_pdecimal_fun7375__t* _self = kk_function_as(struct kk_std_num_decimal_pdecimal_fun7375__t*, _fself);
  kk_string_t x0_6220 = _self->x0_6220; /* string */
  kk_string_t x1_6224 = _self->x1_6224; /* string */
  bool x_6216 = _self->x_6216; /* bool */
  kk_drop_match(_self, {kk_string_dup(x0_6220);kk_string_dup(x1_6224);;}, {}, _ctx)
  kk_std_num_decimal__decimal _x7376;
  kk_integer_t _x7377 = kk_integer_unbox(_b_6531); /*int*/
  _x7376 = kk_std_num_decimal__mlift6017_pdecimal(x1_6224, x_6216, x0_6220, _x7377, _ctx); /*std/num/decimal/decimal*/
  return kk_std_num_decimal__decimal_box(_x7376, _ctx);
}


// lift anonymous function
struct kk_std_num_decimal_pdecimal_fun7395__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_decimal_pdecimal_fun7395(kk_function_t _fself, kk_box_t _b_6546, kk_box_t _b_6547, kk_context_t* _ctx);
static kk_function_t kk_std_num_decimal_new_pdecimal_fun7395(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_decimal_pdecimal_fun7395, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_decimal_pdecimal_fun7395(kk_function_t _fself, kk_box_t _b_6546, kk_box_t _b_6547, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_num_decimal__decimal _x7396;
  kk_integer_t _x7397 = kk_integer_unbox(_b_6546); /*int*/
  kk_std_core_types__optional _x7398 = kk_std_core_types__optional_unbox(_b_6547, _ctx); /*optional<int>*/
  _x7396 = kk_std_num_decimal_decimal_exp(_x7397, _x7398, _ctx); /*std/num/decimal/decimal*/
  return kk_std_num_decimal__decimal_box(_x7396, _ctx);
}


// lift anonymous function
struct kk_std_num_decimal_pdecimal_fun7400__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_decimal_pdecimal_fun7400(kk_function_t _fself, kk_box_t _b_6553, kk_context_t* _ctx);
static kk_function_t kk_std_num_decimal_new_pdecimal_fun7400(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_decimal_pdecimal_fun7400, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_decimal_pdecimal_fun7400(kk_function_t _fself, kk_box_t _b_6553, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_num_decimal__decimal _x7401;
  kk_std_num_decimal__decimal _x7402 = kk_std_num_decimal__decimal_unbox(_b_6553, _ctx); /*std/num/decimal/decimal*/
  _x7401 = kk_std_num_decimal__lp__tilde__rp_(_x7402, _ctx); /*std/num/decimal/decimal*/
  return kk_std_num_decimal__decimal_box(_x7401, _ctx);
}

kk_std_num_decimal__decimal kk_std_num_decimal_pdecimal(kk_context_t* _ctx) { /* () -> std/text/parse/parse decimal */ 
  bool x_6216 = kk_std_text_parse_sign(_ctx); /*bool*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x7343 = kk_std_core_hnd_yield_extend(kk_std_num_decimal_new_pdecimal_fun7344(_ctx), _ctx); /*2*/
    return kk_std_num_decimal__decimal_unbox(_x7343, _ctx);
  }
  kk_string_t x0_6220 = kk_std_text_parse_digits(_ctx); /*string*/;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x0_6220, _ctx);
    kk_box_t _x7347 = kk_std_core_hnd_yield_extend(kk_std_num_decimal_new_pdecimal_fun7348(x_6216, _ctx), _ctx); /*2*/
    return kk_std_num_decimal__decimal_unbox(_x7347, _ctx);
  }
  kk_string_t x1_6224;
  kk_box_t _x7351;
  kk_box_t _x7352;
  kk_string_t _x7353 = kk_string_empty(); /*string*/
  _x7352 = kk_string_box(_x7353); /*0*/
  _x7351 = kk_std_text_parse_optional(_x7352, kk_std_num_decimal_new_pdecimal_fun7355(_ctx), _ctx); /*0*/
  x1_6224 = kk_string_unbox(_x7351); /*string*/
  if (kk_yielding(kk_context())) {
    kk_string_drop(x1_6224, _ctx);
    kk_box_t _x7361 = kk_std_core_hnd_yield_extend(kk_std_num_decimal_new_pdecimal_fun7362(x0_6220, x_6216, _ctx), _ctx); /*2*/
    return kk_std_num_decimal__decimal_unbox(_x7361, _ctx);
  }
  kk_integer_t x3_6230;
  kk_box_t _x7365 = kk_std_text_parse_optional(kk_integer_box(kk_integer_from_small(0)), kk_std_num_decimal_new_pdecimal_fun7366(_ctx), _ctx); /*0*/
  x3_6230 = kk_integer_unbox(_x7365); /*int*/
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x3_6230, _ctx);
    kk_box_t _x7374 = kk_std_core_hnd_yield_extend(kk_std_num_decimal_new_pdecimal_fun7375(x0_6220, x1_6224, x_6216, _ctx), _ctx); /*2*/
    return kk_std_num_decimal__decimal_unbox(_x7374, _ctx);
  }
  kk_std_num_decimal__decimal i;
  kk_integer_t _x1;
  kk_string_t s_6236;
  kk_string_t _x7378 = kk_string_dup(x1_6224); /*string*/
  s_6236 = kk_std_core__lp__plus__plus__1_rp_(x0_6220, _x7378, _ctx); /*string*/
  kk_std_core_types__optional default_6237 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(0)), _ctx); /*optional<int>*/;
  bool _match_6646;
  kk_string_t _x7379 = kk_string_dup(s_6236); /*string*/
  _match_6646 = kk_std_core_is_empty_2(_x7379, _ctx); /*bool*/
  if (_match_6646) {
    kk_string_drop(s_6236, _ctx);
    if (kk_std_core_types__is_Optional(default_6237)) {
      kk_box_t _box_x6534 = default_6237._cons.Optional.value;
      kk_integer_t _default_19378 = kk_integer_unbox(_box_x6534);
      kk_integer_dup(_default_19378);
      kk_std_core_types__optional_drop(default_6237, _ctx);
      _x1 = _default_19378; /*int*/
      goto _match7380;
    }
    _x1 = kk_integer_from_small(0); /*int*/
    _match7380: ;
  }
  else {
    kk_std_core_types__maybe m_21736;
    kk_std_core_types__optional hex0_21739;
    kk_box_t _x7382;
    bool _x7383;
    kk_std_core_types__optional _match_6647 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
    if (kk_std_core_types__is_Optional(_match_6647)) {
      kk_box_t _box_x6535 = _match_6647._cons.Optional.value;
      bool _hex_19382 = kk_bool_unbox(_box_x6535);
      kk_std_core_types__optional_drop(_match_6647, _ctx);
      _x7383 = _hex_19382; /*bool*/
      goto _match7384;
    }
    _x7383 = false; /*bool*/
    _match7384: ;
    _x7382 = kk_bool_box(_x7383); /*35*/
    hex0_21739 = kk_std_core_types__new_Optional(_x7382, _ctx); /*optional<bool>*/
    kk_string_t _x7386 = kk_std_core_trim(s_6236, _ctx); /*string*/
    bool _x7387;
    if (kk_std_core_types__is_Optional(hex0_21739)) {
      kk_box_t _box_x6538 = hex0_21739._cons.Optional.value;
      bool _hex_19366 = kk_bool_unbox(_box_x6538);
      kk_std_core_types__optional_drop(hex0_21739, _ctx);
      _x7387 = _hex_19366; /*bool*/
      goto _match7388;
    }
    _x7387 = false; /*bool*/
    _match7388: ;
    m_21736 = kk_std_core_xparse_int(_x7386, _x7387, _ctx); /*maybe<int>*/
    if (kk_std_core_types__is_Nothing(m_21736)) {
      if (kk_std_core_types__is_Optional(default_6237)) {
        kk_box_t _box_x6539 = default_6237._cons.Optional.value;
        kk_integer_t _default_193780 = kk_integer_unbox(_box_x6539);
        kk_integer_dup(_default_193780);
        kk_std_core_types__optional_drop(default_6237, _ctx);
        _x1 = _default_193780; /*int*/
        goto _match7390;
      }
      _x1 = kk_integer_from_small(0); /*int*/
      _match7390: ;
    }
    else {
      kk_box_t _box_x6540 = m_21736._cons.Just.value;
      kk_integer_t x5 = kk_integer_unbox(_box_x6540);
      kk_integer_dup(x5);
      kk_std_core_types__maybe_drop(m_21736, _ctx);
      kk_std_core_types__optional_drop(default_6237, _ctx);
      _x1 = x5; /*int*/
    }
  }
  kk_std_core_types__optional _x2;
  kk_integer_t _b_6542_6541;
  kk_integer_t _x7393 = kk_std_core_count_1(x1_6224, _ctx); /*int*/
  _b_6542_6541 = kk_integer_sub(x3_6230,_x7393,kk_context()); /*int*/
  _x2 = kk_std_core_types__new_Optional(kk_integer_box(_b_6542_6541), _ctx); /*optional<int>*/
  kk_box_t _x7394 = kk_std_core_hnd__open_none2(kk_std_num_decimal_new_pdecimal_fun7395(_ctx), kk_integer_box(_x1), kk_std_core_types__optional_box(_x2, _ctx), _ctx); /*3*/
  i = kk_std_num_decimal__decimal_unbox(_x7394, _ctx); /*std/num/decimal/decimal*/
  if (x_6216) {
    kk_box_t _x7399 = kk_std_core_hnd__open_none1(kk_std_num_decimal_new_pdecimal_fun7400(_ctx), kk_std_num_decimal__decimal_box(i, _ctx), _ctx); /*2*/
    return kk_std_num_decimal__decimal_unbox(_x7399, _ctx);
  }
  return i;
}
 
// Parse a `:decimal` number.


// lift anonymous function
struct kk_std_num_decimal_parse_decimal_fun7406__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_decimal_parse_decimal_fun7406(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_decimal_new_parse_decimal_fun7406(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_decimal_parse_decimal_fun7406, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_std_num_decimal_parse_decimal_fun7410__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_decimal_parse_decimal_fun7410(kk_function_t _fself, kk_box_t _x17409, kk_context_t* _ctx);
static kk_function_t kk_std_num_decimal_new_parse_decimal_fun7410(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_decimal_parse_decimal_fun7410, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_decimal_parse_decimal_fun7410(kk_function_t _fself, kk_box_t _x17409, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return kk_std_text_parse__mlift2565_parse_eof(_x17409, _ctx);
}
static kk_box_t kk_std_num_decimal_parse_decimal_fun7406(kk_function_t _fself, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_num_decimal__decimal _x7407;
  kk_std_num_decimal__decimal x_2790 = kk_std_num_decimal_pdecimal(_ctx); /*std/num/decimal/decimal*/;
  kk_box_t _x7408;
  if (kk_yielding(kk_context())) {
    kk_std_num_decimal__decimal_drop(x_2790, _ctx);
    _x7408 = kk_std_core_hnd_yield_extend(kk_std_num_decimal_new_parse_decimal_fun7410(_ctx), _ctx); /*2*/
  }
  else {
    _x7408 = kk_std_text_parse__mlift2565_parse_eof(kk_std_num_decimal__decimal_box(x_2790, _ctx), _ctx); /*2*/
  }
  _x7407 = kk_std_num_decimal__decimal_unbox(_x7408, _ctx); /*std/num/decimal/decimal*/
  return kk_std_num_decimal__decimal_box(_x7407, _ctx);
}

kk_std_core_types__maybe kk_std_num_decimal_parse_decimal(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> maybe<decimal> */ 
  kk_std_text_parse__parse_error perr_6239;
  kk_std_core__sslice input_6240;
  kk_string_t s0_6242 = kk_std_core_trim(s, _ctx); /*string*/;
  kk_string_t _x7403 = kk_string_dup(s0_6242); /*string*/
  size_t _x7404 = ((size_t)0); /*size_t*/
  size_t _x7405 = kk_string_len(s0_6242,kk_context()); /*size_t*/
  input_6240 = kk_std_core__new_Sslice(_x7403, _x7404, _x7405, _ctx); /*sslice*/
  perr_6239 = kk_std_text_parse_parse(input_6240, kk_std_num_decimal_new_parse_decimal_fun7406(_ctx), _ctx); /*std/text/parse/parse-error<std/num/decimal/decimal>*/
  kk_std_core_types__either e_2721 = kk_std_text_parse_either(perr_6239, _ctx); /*either<string,std/num/decimal/decimal>*/;
  if (kk_std_core_types__is_Left(e_2721)) {
    kk_box_t _box_x6575 = e_2721._cons.Left.left;
    kk_std_core_types__either_drop(e_2721, _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
  kk_box_t _box_x6576 = e_2721._cons.Right.right;
  kk_std_num_decimal__decimal x = kk_std_num_decimal__decimal_unbox(_box_x6576, NULL);
  kk_std_num_decimal__decimal_dup(x);
  kk_std_core_types__either_drop(e_2721, _ctx);
  return kk_std_core_types__new_Just(kk_std_num_decimal__decimal_box(x, _ctx), _ctx);
}

kk_string_t kk_std_num_decimal_show_frac(kk_string_t frac, kk_integer_t prec, kk_context_t* _ctx) { /* (frac : string, prec : int) -> string */ 
  kk_string_t frac_trim;
  kk_string_t _x7413;
  kk_define_string_literal(, _s7414, 1, "0")
  _x7413 = kk_string_dup(_s7414); /*string*/
  frac_trim = kk_std_core_trim_right_1(frac, _x7413, _ctx); /*string*/
  kk_string_t frac_full;
  bool _match_6639;
  kk_integer_t _x7415 = kk_integer_dup(prec); /*int*/
  _match_6639 = kk_integer_gte(_x7415,(kk_integer_from_small(0)),kk_context()); /*bool*/
  if (_match_6639) {
    kk_std_core_types__optional fill_6245 = kk_std_core_types__new_Optional(kk_char_box('0', _ctx), _ctx); /*optional<char>*/;
    size_t w = kk_std_core_size__t(prec, _ctx); /*size_t*/;
    size_t n;
    kk_string_t _x7416 = kk_string_dup(frac_trim); /*string*/
    n = kk_string_len(_x7416,kk_context()); /*size_t*/
    bool _match_6640 = (w <= n); /*bool*/;
    if (_match_6640) {
      kk_std_core_types__optional_drop(fill_6245, _ctx);
      frac_full = frac_trim; /*string*/
    }
    else {
      kk_string_t _x7417;
      kk_string_t _x7418;
      kk_char_t _x7419;
      if (kk_std_core_types__is_Optional(fill_6245)) {
        kk_box_t _box_x6581 = fill_6245._cons.Optional.value;
        kk_char_t _fill_18968 = kk_char_unbox(_box_x6581, NULL);
        kk_std_core_types__optional_drop(fill_6245, _ctx);
        _x7419 = _fill_18968; /*char*/
        goto _match7420;
      }
      _x7419 = ' '; /*char*/
      _match7420: ;
      _x7418 = kk_std_core_string(_x7419, _ctx); /*string*/
      size_t _x7422 = (w - n); /*size_t*/
      _x7417 = kk_std_core_repeatz(_x7418, _x7422, _ctx); /*string*/
      frac_full = kk_std_core__lp__plus__plus__1_rp_(frac_trim, _x7417, _ctx); /*string*/
    }
  }
  else {
    kk_integer_drop(prec, _ctx);
    frac_full = frac_trim; /*string*/
  }
  bool _match_6638;
  kk_string_t _x7423 = kk_string_dup(frac_full); /*string*/
  _match_6638 = kk_std_core_is_empty_2(_x7423, _ctx); /*bool*/
  if (_match_6638) {
    kk_string_drop(frac_full, _ctx);
    return kk_string_empty();
  }
  kk_string_t _x7425;
  kk_define_string_literal(, _s7426, 1, ".")
  _x7425 = kk_string_dup(_s7426); /*string*/
  return kk_std_core__lp__plus__plus__1_rp_(_x7425, frac_full, _ctx);
}
 
/* Show a decimal `d` with a given precision `prec` (=`-1000`) in scientific notation.
The precision specifies the  number of digits after the dot, i.e.
the number of significant digits is `prec+1`.
If the precision is negative, _at most_ `prec` digits are displayed, and if
it is positive exactly `prec` digits are used.
```
> decimal(1,-1).show-exp
"1e-1"
> 1.1.decimal.show-exp
"1.100000000000000088817841970012523233890533447265625"
> 1.1.decimal.show-exp(-20)
"1.10000000000000008882"
> 0.125.decimal.show-exp(-20)
"1.25e-1"
> 0.125.decimal.show-exp(20)
"1.25000000000000000000e-1"
```
.
*/

kk_string_t kk_std_num_decimal_show_exp(kk_std_num_decimal__decimal d, kk_std_core_types__optional prec, kk_context_t* _ctx) { /* (d : decimal, prec : optional<int>) -> string */ 
  kk_std_num_decimal__decimal x;
  kk_std_num_decimal__decimal _x7427 = kk_std_num_decimal__decimal_dup(d); /*std/num/decimal/decimal*/
  kk_std_core_types__optional _x7428;
  kk_integer_t _b_6584_6583;
  kk_integer_t _x7429;
  kk_integer_t _x7430;
  if (kk_std_core_types__is_Optional(prec)) {
    kk_box_t _box_x6582 = prec._cons.Optional.value;
    kk_integer_t _prec_4668 = kk_integer_unbox(_box_x6582);
    kk_integer_dup(_prec_4668);
    _x7430 = _prec_4668; /*int*/
    goto _match7431;
  }
  _x7430 = kk_integer_from_small(-1000); /*int*/
  _match7431: ;
  _x7429 = kk_integer_abs(_x7430,kk_context()); /*int*/
  kk_integer_t _x7433 = kk_std_num_decimal_exponent(d, _ctx); /*int*/
  _b_6584_6583 = kk_integer_sub(_x7429,_x7433,kk_context()); /*int*/
  _x7428 = kk_std_core_types__new_Optional(kk_integer_box(_b_6584_6583), _ctx); /*optional<35>*/
  x = kk_std_num_decimal_round_to_prec(_x7427, _x7428, kk_std_core_types__new_None(_ctx), _ctx); /*std/num/decimal/decimal*/
  kk_string_t s;
  kk_integer_t _x7434;
  kk_integer_t _x7435;
  kk_integer_t _x = x.num;
  kk_integer_dup(_x);
  _x7435 = _x; /*int*/
  _x7434 = kk_integer_abs(_x7435,kk_context()); /*int*/
  s = kk_std_core_show(_x7434, _ctx); /*string*/
  kk_integer_t digits;
  kk_string_t _x7436 = kk_string_dup(s); /*string*/
  digits = kk_std_core_count_1(_x7436, _ctx); /*int*/
  kk_integer_t exp0;
  kk_integer_t _x7437;
  kk_integer_t _x7438;
  kk_integer_t _x0 = x.exp;
  kk_integer_dup(_x0);
  _x7438 = _x0; /*int*/
  _x7437 = kk_integer_add(_x7438,digits,kk_context()); /*int*/
  exp0 = kk_integer_sub(_x7437,(kk_integer_from_small(1)),kk_context()); /*int*/
  kk_string_t sign0;
  bool _match_6637 = kk_std_num_decimal_is_neg(x, _ctx); /*bool*/;
  if (_match_6637) {
    kk_define_string_literal(, _s7439, 1, "-")
    sign0 = kk_string_dup(_s7439); /*string*/
  }
  else {
    sign0 = kk_string_empty(); /*string*/
  }
  kk_string_t exponent0;
  bool _match_6635;
  kk_integer_t _x7441 = kk_integer_dup(exp0); /*int*/
  _match_6635 = kk_integer_eq(_x7441,(kk_integer_from_small(0)),kk_context()); /*bool*/
  if (_match_6635) {
    kk_integer_drop(exp0, _ctx);
    exponent0 = kk_string_empty(); /*string*/
  }
  else {
    kk_string_t _x7443;
    kk_define_string_literal(, _s7444, 1, "e")
    _x7443 = kk_string_dup(_s7444); /*string*/
    kk_string_t _x7445;
    kk_string_t _x7446;
    bool _match_6636;
    kk_integer_t _x7447 = kk_integer_dup(exp0); /*int*/
    _match_6636 = kk_std_core_is_pos_2(_x7447, _ctx); /*bool*/
    if (_match_6636) {
      kk_define_string_literal(, _s7448, 1, "+")
      _x7446 = kk_string_dup(_s7448); /*string*/
    }
    else {
      _x7446 = kk_string_empty(); /*string*/
    }
    kk_string_t _x7450 = kk_std_core_show(exp0, _ctx); /*string*/
    _x7445 = kk_std_core__lp__plus__plus__1_rp_(_x7446, _x7450, _ctx); /*string*/
    exponent0 = kk_std_core__lp__plus__plus__1_rp_(_x7443, _x7445, _ctx); /*string*/
  }
  kk_string_t _x7451;
  kk_string_t _x7452;
  kk_string_t _x7453 = kk_string_dup(s); /*string*/
  _x7452 = kk_std_core_head_3(_x7453, _ctx); /*string*/
  kk_string_t _x7454;
  kk_string_t _x7455;
  kk_string_t frac_6248 = kk_std_core_tail_2(s, _ctx); /*string*/;
  kk_string_t frac_trim;
  kk_string_t _x7456;
  kk_define_string_literal(, _s7457, 1, "0")
  _x7456 = kk_string_dup(_s7457); /*string*/
  frac_trim = kk_std_core_trim_right_1(frac_6248, _x7456, _ctx); /*string*/
  kk_string_t frac_full;
  bool _match_6633;
  kk_integer_t _x7458;
  if (kk_std_core_types__is_Optional(prec)) {
    kk_box_t _box_x6585 = prec._cons.Optional.value;
    kk_integer_t _prec_46680 = kk_integer_unbox(_box_x6585);
    kk_integer_dup(_prec_46680);
    _x7458 = _prec_46680; /*int*/
    goto _match7459;
  }
  _x7458 = kk_integer_from_small(-1000); /*int*/
  _match7459: ;
  _match_6633 = kk_integer_gte(_x7458,(kk_integer_from_small(0)),kk_context()); /*bool*/
  if (_match_6633) {
    kk_std_core_types__optional fill_6252 = kk_std_core_types__new_Optional(kk_char_box('0', _ctx), _ctx); /*optional<char>*/;
    size_t w;
    kk_integer_t _x7461;
    if (kk_std_core_types__is_Optional(prec)) {
      kk_box_t _box_x6588 = prec._cons.Optional.value;
      kk_integer_t _prec_466800 = kk_integer_unbox(_box_x6588);
      kk_integer_dup(_prec_466800);
      kk_std_core_types__optional_drop(prec, _ctx);
      _x7461 = _prec_466800; /*int*/
      goto _match7462;
    }
    _x7461 = kk_integer_from_small(-1000); /*int*/
    _match7462: ;
    w = kk_std_core_size__t(_x7461, _ctx); /*size_t*/
    size_t n;
    kk_string_t _x7464 = kk_string_dup(frac_trim); /*string*/
    n = kk_string_len(_x7464,kk_context()); /*size_t*/
    bool _match_6634 = (w <= n); /*bool*/;
    if (_match_6634) {
      kk_std_core_types__optional_drop(fill_6252, _ctx);
      frac_full = frac_trim; /*string*/
    }
    else {
      kk_string_t _x7465;
      kk_string_t _x7466;
      kk_char_t _x7467;
      if (kk_std_core_types__is_Optional(fill_6252)) {
        kk_box_t _box_x6589 = fill_6252._cons.Optional.value;
        kk_char_t _fill_18968 = kk_char_unbox(_box_x6589, NULL);
        kk_std_core_types__optional_drop(fill_6252, _ctx);
        _x7467 = _fill_18968; /*char*/
        goto _match7468;
      }
      _x7467 = ' '; /*char*/
      _match7468: ;
      _x7466 = kk_std_core_string(_x7467, _ctx); /*string*/
      size_t _x7470 = (w - n); /*size_t*/
      _x7465 = kk_std_core_repeatz(_x7466, _x7470, _ctx); /*string*/
      frac_full = kk_std_core__lp__plus__plus__1_rp_(frac_trim, _x7465, _ctx); /*string*/
    }
  }
  else {
    kk_std_core_types__optional_drop(prec, _ctx);
    frac_full = frac_trim; /*string*/
  }
  bool _match_6632;
  kk_string_t _x7471 = kk_string_dup(frac_full); /*string*/
  _match_6632 = kk_std_core_is_empty_2(_x7471, _ctx); /*bool*/
  if (_match_6632) {
    kk_string_drop(frac_full, _ctx);
    _x7455 = kk_string_empty(); /*string*/
  }
  else {
    kk_string_t _x7473;
    kk_define_string_literal(, _s7474, 1, ".")
    _x7473 = kk_string_dup(_s7474); /*string*/
    _x7455 = kk_std_core__lp__plus__plus__1_rp_(_x7473, frac_full, _ctx); /*string*/
  }
  _x7454 = kk_std_core__lp__plus__plus__1_rp_(_x7455, exponent0, _ctx); /*string*/
  _x7451 = kk_std_core__lp__plus__plus__1_rp_(_x7452, _x7454, _ctx); /*string*/
  return kk_std_core__lp__plus__plus__1_rp_(sign0, _x7451, _ctx);
}
 
/* Show a decimal `d` with a given precision `prec` (=`-1000`) in fixed-point notation.
The precision specifies the  number of digits after the dot.
If the precision is negative, _at most_  `prec` digits after the dot are displayed,
while for a positive precision, exactly `prec` digits are used.
```
> decimal(1,-1).show-fixed
"0.1"
> 0.1.decimal.show-fixed
"0.1000000000000000055511151231257827021181583404541015625"
> 0.1.decimal.show-fixed(20)
"0.1000000000000000555"
> 0.1.decimal.show-fixed(-20)
"0.1000000000000000555"
> decimal(1,-1).show-fixed(20)
"0.1000000000000000000"
```
.
*/

kk_string_t kk_std_num_decimal_show_fixed(kk_std_num_decimal__decimal d, kk_std_core_types__optional prec, kk_context_t* _ctx) { /* (d : decimal, prec : optional<int>) -> string */ 
  kk_std_num_decimal__decimal x;
  kk_std_core_types__optional _x7475;
  kk_integer_t _b_6592_6591;
  kk_integer_t _x7476;
  if (kk_std_core_types__is_Optional(prec)) {
    kk_box_t _box_x6590 = prec._cons.Optional.value;
    kk_integer_t _prec_5230 = kk_integer_unbox(_box_x6590);
    kk_integer_dup(_prec_5230);
    _x7476 = _prec_5230; /*int*/
    goto _match7477;
  }
  _x7476 = kk_integer_from_small(-1000); /*int*/
  _match7477: ;
  _b_6592_6591 = kk_integer_abs(_x7476,kk_context()); /*int*/
  _x7475 = kk_std_core_types__new_Optional(kk_integer_box(_b_6592_6591), _ctx); /*optional<35>*/
  x = kk_std_num_decimal_round_to_prec(d, _x7475, kk_std_core_types__new_None(_ctx), _ctx); /*std/num/decimal/decimal*/
  bool _match_6625;
  kk_integer_t _x7479;
  kk_integer_t _x = x.exp;
  kk_integer_dup(_x);
  _x7479 = _x; /*int*/
  _match_6625 = kk_integer_gte(_x7479,(kk_integer_from_small(0)),kk_context()); /*bool*/
  if (_match_6625) {
    kk_string_t frac;
    bool _match_6631;
    kk_integer_t _x7480;
    if (kk_std_core_types__is_Optional(prec)) {
      kk_box_t _box_x6593 = prec._cons.Optional.value;
      kk_integer_t _prec_52300 = kk_integer_unbox(_box_x6593);
      kk_integer_dup(_prec_52300);
      _x7480 = _prec_52300; /*int*/
      goto _match7481;
    }
    _x7480 = kk_integer_from_small(-1000); /*int*/
    _match7481: ;
    _match_6631 = kk_integer_lte(_x7480,(kk_integer_from_small(0)),kk_context()); /*bool*/
    if (_match_6631) {
      kk_std_core_types__optional_drop(prec, _ctx);
      frac = kk_string_empty(); /*string*/
    }
    else {
      kk_string_t _x7484;
      kk_define_string_literal(, _s7485, 1, ".")
      _x7484 = kk_string_dup(_s7485); /*string*/
      kk_string_t _x7486;
      kk_string_t _x7487;
      kk_define_string_literal(, _s7488, 1, "0")
      _x7487 = kk_string_dup(_s7488); /*string*/
      size_t _x7489;
      kk_integer_t _x7490;
      if (kk_std_core_types__is_Optional(prec)) {
        kk_box_t _box_x6594 = prec._cons.Optional.value;
        kk_integer_t _prec_52301 = kk_integer_unbox(_box_x6594);
        kk_integer_dup(_prec_52301);
        kk_std_core_types__optional_drop(prec, _ctx);
        _x7490 = _prec_52301; /*int*/
        goto _match7491;
      }
      _x7490 = kk_integer_from_small(-1000); /*int*/
      _match7491: ;
      _x7489 = kk_std_core_size__t(_x7490, _ctx); /*size_t*/
      _x7486 = kk_std_core_repeatz(_x7487, _x7489, _ctx); /*string*/
      frac = kk_std_core__lp__plus__plus__1_rp_(_x7484, _x7486, _ctx); /*string*/
    }
    kk_string_t _x7493;
    kk_integer_t _x7494;
    kk_integer_t _x0 = x.num;
    kk_integer_dup(_x0);
    _x7494 = _x0; /*int*/
    _x7493 = kk_std_core_show(_x7494, _ctx); /*string*/
    kk_string_t _x7495;
    kk_string_t _x7496;
    kk_string_t _x7497;
    kk_define_string_literal(, _s7498, 1, "0")
    _x7497 = kk_string_dup(_s7498); /*string*/
    size_t _x7499;
    kk_integer_t _x7500;
    kk_integer_t _x1 = x.exp;
    kk_integer_dup(_x1);
    kk_std_num_decimal__decimal_drop(x, _ctx);
    _x7500 = _x1; /*int*/
    _x7499 = kk_std_core_size__t(_x7500, _ctx); /*size_t*/
    _x7496 = kk_std_core_repeatz(_x7497, _x7499, _ctx); /*string*/
    _x7495 = kk_std_core__lp__plus__plus__1_rp_(_x7496, frac, _ctx); /*string*/
    return kk_std_core__lp__plus__plus__1_rp_(_x7493, _x7495, _ctx);
  }
  kk_integer_t digits;
  kk_integer_t _x7501;
  kk_integer_t _x2 = x.exp;
  kk_integer_dup(_x2);
  _x7501 = _x2; /*int*/
  digits = kk_integer_neg(_x7501,kk_context()); /*int*/
  kk_string_t sign0;
  bool _match_6630;
  kk_std_num_decimal__decimal _x7502 = kk_std_num_decimal__decimal_dup(x); /*std/num/decimal/decimal*/
  _match_6630 = kk_std_num_decimal_is_neg(_x7502, _ctx); /*bool*/
  if (_match_6630) {
    kk_define_string_literal(, _s7503, 1, "-")
    sign0 = kk_string_dup(_s7503); /*string*/
  }
  else {
    sign0 = kk_string_empty(); /*string*/
  }
  kk_integer_t i;
  kk_integer_t _x7505;
  kk_integer_t _x3 = x.num;
  kk_integer_dup(_x3);
  kk_std_num_decimal__decimal_drop(x, _ctx);
  _x7505 = _x3; /*int*/
  i = kk_integer_abs(_x7505,kk_context()); /*int*/
  kk_integer_t man;
  kk_integer_t _x7506 = kk_integer_dup(i); /*int*/
  kk_integer_t _x7507 = kk_integer_dup(digits); /*int*/
  man = kk_std_core_cdiv_exp10(_x7506, _x7507, _ctx); /*int*/
  kk_integer_t frac0;
  kk_integer_t _x7508;
  kk_integer_t _x7509 = kk_integer_dup(man); /*int*/
  kk_integer_t _x7510 = kk_integer_dup(digits); /*int*/
  _x7508 = kk_std_core_mul_exp10(_x7509, _x7510, _ctx); /*int*/
  frac0 = kk_integer_sub(i,_x7508,kk_context()); /*int*/
  kk_string_t _x7511;
  kk_string_t _x7512 = kk_std_core_show(man, _ctx); /*string*/
  kk_string_t _x7513;
  kk_string_t frac1_6262;
  kk_string_t s2_6264 = kk_std_core_show(frac0, _ctx); /*string*/;
  kk_std_core_types__optional fill0_6266 = kk_std_core_types__new_Optional(kk_char_box('0', _ctx), _ctx); /*optional<char>*/;
  size_t w0 = kk_std_core_size__t(digits, _ctx); /*size_t*/;
  size_t n2;
  kk_string_t _x7514 = kk_string_dup(s2_6264); /*string*/
  n2 = kk_string_len(_x7514,kk_context()); /*size_t*/
  bool _match_6629 = (w0 <= n2); /*bool*/;
  if (_match_6629) {
    kk_std_core_types__optional_drop(fill0_6266, _ctx);
    frac1_6262 = s2_6264; /*string*/
  }
  else {
    kk_string_t _x7515;
    kk_string_t _x7516;
    kk_char_t _x7517;
    if (kk_std_core_types__is_Optional(fill0_6266)) {
      kk_box_t _box_x6597 = fill0_6266._cons.Optional.value;
      kk_char_t _fill_8417 = kk_char_unbox(_box_x6597, NULL);
      kk_std_core_types__optional_drop(fill0_6266, _ctx);
      _x7517 = _fill_8417; /*char*/
      goto _match7518;
    }
    _x7517 = ' '; /*char*/
    _match7518: ;
    _x7516 = kk_std_core_string(_x7517, _ctx); /*string*/
    size_t _x7520 = (w0 - n2); /*size_t*/
    _x7515 = kk_std_core_repeatz(_x7516, _x7520, _ctx); /*string*/
    frac1_6262 = kk_std_core__lp__plus__plus__1_rp_(_x7515, s2_6264, _ctx); /*string*/
  }
  kk_string_t frac_trim;
  kk_string_t _x7521;
  kk_define_string_literal(, _s7522, 1, "0")
  _x7521 = kk_string_dup(_s7522); /*string*/
  frac_trim = kk_std_core_trim_right_1(frac1_6262, _x7521, _ctx); /*string*/
  kk_string_t frac_full;
  bool _match_6627;
  kk_integer_t _x7523;
  if (kk_std_core_types__is_Optional(prec)) {
    kk_box_t _box_x6598 = prec._cons.Optional.value;
    kk_integer_t _prec_52302 = kk_integer_unbox(_box_x6598);
    kk_integer_dup(_prec_52302);
    _x7523 = _prec_52302; /*int*/
    goto _match7524;
  }
  _x7523 = kk_integer_from_small(-1000); /*int*/
  _match7524: ;
  _match_6627 = kk_integer_gte(_x7523,(kk_integer_from_small(0)),kk_context()); /*bool*/
  if (_match_6627) {
    kk_std_core_types__optional fill_6269 = kk_std_core_types__new_Optional(kk_char_box('0', _ctx), _ctx); /*optional<char>*/;
    size_t w;
    kk_integer_t _x7526;
    if (kk_std_core_types__is_Optional(prec)) {
      kk_box_t _box_x6601 = prec._cons.Optional.value;
      kk_integer_t _prec_523020 = kk_integer_unbox(_box_x6601);
      kk_integer_dup(_prec_523020);
      kk_std_core_types__optional_drop(prec, _ctx);
      _x7526 = _prec_523020; /*int*/
      goto _match7527;
    }
    _x7526 = kk_integer_from_small(-1000); /*int*/
    _match7527: ;
    w = kk_std_core_size__t(_x7526, _ctx); /*size_t*/
    size_t n1;
    kk_string_t _x7529 = kk_string_dup(frac_trim); /*string*/
    n1 = kk_string_len(_x7529,kk_context()); /*size_t*/
    bool _match_6628 = (w <= n1); /*bool*/;
    if (_match_6628) {
      kk_std_core_types__optional_drop(fill_6269, _ctx);
      frac_full = frac_trim; /*string*/
    }
    else {
      kk_string_t _x7530;
      kk_string_t _x7531;
      kk_char_t _x7532;
      if (kk_std_core_types__is_Optional(fill_6269)) {
        kk_box_t _box_x6602 = fill_6269._cons.Optional.value;
        kk_char_t _fill_18968 = kk_char_unbox(_box_x6602, NULL);
        kk_std_core_types__optional_drop(fill_6269, _ctx);
        _x7532 = _fill_18968; /*char*/
        goto _match7533;
      }
      _x7532 = ' '; /*char*/
      _match7533: ;
      _x7531 = kk_std_core_string(_x7532, _ctx); /*string*/
      size_t _x7535 = (w - n1); /*size_t*/
      _x7530 = kk_std_core_repeatz(_x7531, _x7535, _ctx); /*string*/
      frac_full = kk_std_core__lp__plus__plus__1_rp_(frac_trim, _x7530, _ctx); /*string*/
    }
  }
  else {
    kk_std_core_types__optional_drop(prec, _ctx);
    frac_full = frac_trim; /*string*/
  }
  bool _match_6626;
  kk_string_t _x7536 = kk_string_dup(frac_full); /*string*/
  _match_6626 = kk_std_core_is_empty_2(_x7536, _ctx); /*bool*/
  if (_match_6626) {
    kk_string_drop(frac_full, _ctx);
    _x7513 = kk_string_empty(); /*string*/
  }
  else {
    kk_string_t _x7538;
    kk_define_string_literal(, _s7539, 1, ".")
    _x7538 = kk_string_dup(_s7539); /*string*/
    _x7513 = kk_std_core__lp__plus__plus__1_rp_(_x7538, frac_full, _ctx); /*string*/
  }
  _x7511 = kk_std_core__lp__plus__plus__1_rp_(_x7512, _x7513, _ctx); /*string*/
  return kk_std_core__lp__plus__plus__1_rp_(sign0, _x7511, _ctx);
}
 
// Show a decimal `d` with a given precision `prec` (=`-1000`).
// The precision specifies the  number of digits after the dot (in either scientific of fixed-point notation).
// If the precision is negative, _at most_ `prec` digits are displayed, while for a positive
// precision, exactly `prec` digits behind the dot are displayed.
// This uses `show-fixed` when the exponent of `d` in scientific notation is larger than -5
// and smaller than the precision (or 15 in case of a negative precision), otherwise it uses `show-exp`.

kk_string_t kk_std_num_decimal_show(kk_std_num_decimal__decimal d, kk_std_core_types__optional prec, kk_context_t* _ctx) { /* (d : decimal, prec : optional<int>) -> string */ 
  kk_integer_t exp0;
  kk_std_num_decimal__decimal _x7540 = kk_std_num_decimal__decimal_dup(d); /*std/num/decimal/decimal*/
  exp0 = kk_std_num_decimal_exponent(_x7540, _ctx); /*int*/
  bool _match_6621;
  bool _match_6622;
  kk_integer_t _x7541 = kk_integer_dup(exp0); /*int*/
  _match_6622 = kk_integer_gt(_x7541,(kk_integer_from_small(-5)),kk_context()); /*bool*/
  if (_match_6622) {
    kk_integer_t _x7542;
    bool _match_6623;
    kk_std_core_types__order x_21555;
    kk_integer_t _x7543;
    if (kk_std_core_types__is_Optional(prec)) {
      kk_box_t _box_x6603 = prec._cons.Optional.value;
      kk_integer_t _prec_4548 = kk_integer_unbox(_box_x6603);
      kk_integer_dup(_prec_4548);
      _x7543 = _prec_4548; /*int*/
      goto _match7544;
    }
    _x7543 = kk_integer_from_small(-1000); /*int*/
    _match7544: ;
    x_21555 = kk_int_as_order(kk_integer_signum(_x7543,kk_context()),kk_context()); /*order*/
    kk_integer_t _x7546 = kk_std_core_int_5(x_21555, _ctx); /*int*/
    kk_integer_t _x7547;
    kk_std_core_types__order _x7548 = kk_std_core_types__new_Lt(_ctx); /*order*/
    if (kk_std_core_types__is_Lt(_x7548)) {
      _x7547 = kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context()); /*int*/
      goto _match7549;
    }
    if (kk_std_core_types__is_Eq(_x7548)) {
      _x7547 = kk_integer_from_small(0); /*int*/
      goto _match7549;
    }
    _x7547 = kk_integer_from_small(1); /*int*/
    _match7549: ;
    _match_6623 = kk_integer_eq(_x7546,_x7547,kk_context()); /*bool*/
    if (_match_6623) {
      _x7542 = kk_integer_from_small(15); /*int*/
    }
    else {
      if (kk_std_core_types__is_Optional(prec)) {
        kk_box_t _box_x6604 = prec._cons.Optional.value;
        kk_integer_t _prec_45480 = kk_integer_unbox(_box_x6604);
        kk_integer_dup(_prec_45480);
        _x7542 = _prec_45480; /*int*/
        goto _match7550;
      }
      _x7542 = kk_integer_from_small(-1000); /*int*/
      _match7550: ;
    }
    _match_6621 = kk_integer_lt(exp0,_x7542,kk_context()); /*bool*/
  }
  else {
    kk_integer_drop(exp0, _ctx);
    _match_6621 = false; /*bool*/
  }
  if (_match_6621) {
    kk_std_core_types__optional _x7552;
    kk_box_t _x7553;
    kk_integer_t _x7554;
    if (kk_std_core_types__is_Optional(prec)) {
      kk_box_t _box_x6605 = prec._cons.Optional.value;
      kk_integer_t _prec_45481 = kk_integer_unbox(_box_x6605);
      kk_integer_dup(_prec_45481);
      kk_std_core_types__optional_drop(prec, _ctx);
      _x7554 = _prec_45481; /*int*/
      goto _match7555;
    }
    _x7554 = kk_integer_from_small(-1000); /*int*/
    _match7555: ;
    _x7553 = kk_integer_box(_x7554); /*35*/
    _x7552 = kk_std_core_types__new_Optional(_x7553, _ctx); /*optional<35>*/
    return kk_std_num_decimal_show_fixed(d, _x7552, _ctx);
  }
  kk_std_core_types__optional _x7557;
  kk_box_t _x7558;
  kk_integer_t _x7559;
  if (kk_std_core_types__is_Optional(prec)) {
    kk_box_t _box_x6607 = prec._cons.Optional.value;
    kk_integer_t _prec_45482 = kk_integer_unbox(_box_x6607);
    kk_integer_dup(_prec_45482);
    kk_std_core_types__optional_drop(prec, _ctx);
    _x7559 = _prec_45482; /*int*/
    goto _match7560;
  }
  _x7559 = kk_integer_from_small(-1000); /*int*/
  _match7560: ;
  _x7558 = kk_integer_box(_x7559); /*35*/
  _x7557 = kk_std_core_types__new_Optional(_x7558, _ctx); /*optional<35>*/
  return kk_std_num_decimal_show_exp(d, _x7557, _ctx);
}
 
// Show a decimal `d` using its internal representation.

kk_string_t kk_std_num_decimal_show_raw(kk_std_num_decimal__decimal d, kk_context_t* _ctx) { /* (d : decimal) -> string */ 
  kk_string_t _x7562;
  kk_integer_t _x7563;
  kk_integer_t _x = d.num;
  kk_integer_dup(_x);
  _x7563 = _x; /*int*/
  _x7562 = kk_std_core_show(_x7563, _ctx); /*string*/
  kk_string_t _x7564;
  kk_string_t _x7565;
  kk_define_string_literal(, _s7566, 1, "e")
  _x7565 = kk_string_dup(_s7566); /*string*/
  kk_string_t _x7567;
  kk_integer_t _x7568;
  kk_integer_t _x0 = d.exp;
  kk_integer_dup(_x0);
  kk_std_num_decimal__decimal_drop(d, _ctx);
  _x7568 = _x0; /*int*/
  _x7567 = kk_std_core_show(_x7568, _ctx); /*string*/
  _x7564 = kk_std_core__lp__plus__plus__1_rp_(_x7565, _x7567, _ctx); /*string*/
  return kk_std_core__lp__plus__plus__1_rp_(_x7562, _x7564, _ctx);
}
 
// Take the sum of a list of decimal numbers (0 for the empty list).


// lift anonymous function
struct kk_std_num_decimal_sum_fun7570__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_decimal_sum_fun7570(kk_function_t _fself, kk_box_t _b_6614, kk_box_t _b_6615, kk_context_t* _ctx);
static kk_function_t kk_std_num_decimal_new_sum_fun7570(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_decimal_sum_fun7570, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_decimal_sum_fun7570(kk_function_t _fself, kk_box_t _b_6614, kk_box_t _b_6615, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_num_decimal__decimal _x7571;
  kk_std_num_decimal__decimal _x7572 = kk_std_num_decimal__decimal_unbox(_b_6615, _ctx); /*std/num/decimal/decimal*/
  kk_std_num_decimal__decimal _x7573 = kk_std_num_decimal__decimal_unbox(_b_6614, _ctx); /*std/num/decimal/decimal*/
  _x7571 = kk_std_num_decimal__lp__plus__rp_(_x7572, _x7573, _ctx); /*std/num/decimal/decimal*/
  return kk_std_num_decimal__decimal_box(_x7571, _ctx);
}

kk_std_num_decimal__decimal kk_std_num_decimal_sum(kk_std_core__list ds, kk_context_t* _ctx) { /* (ds : list<decimal>) -> decimal */ 
  kk_std_num_decimal__decimal z_6287 = kk_std_num_decimal__new_Decimal(kk_integer_from_small(0), kk_integer_from_small(0), _ctx); /*std/num/decimal/decimal*/;
  kk_std_core__list _b_6616_6611 = kk_std_core_reverse(ds, _ctx); /*list<std/num/decimal/decimal>*/;
  kk_box_t _x7569 = kk_std_core_foldl(_b_6616_6611, kk_std_num_decimal__decimal_box(z_6287, _ctx), kk_std_num_decimal_new_sum_fun7570(_ctx), _ctx); /*2*/
  return kk_std_num_decimal__decimal_unbox(_x7569, _ctx);
}

// initialization
void kk_std_num_decimal__init(kk_context_t* _ctx){
  static bool _initialized = false;
  if (_initialized) return;
  _initialized = true;
  kk_std_core_types__init(_ctx);
  kk_std_core_hnd__init(_ctx);
  kk_std_core__init(_ctx);
  kk_std_text_parse__init(_ctx);
  kk_std_num_double__init(_ctx);
  {
    kk_std_num_decimal_maxexp = kk_integer_from_small(308); /*int*/
  }
  {
    kk_std_num_decimal_zero = kk_std_num_decimal__new_Decimal(kk_integer_from_small(0), kk_integer_from_small(0), _ctx); /*std/num/decimal/decimal*/
  }
  {
    kk_std_num_decimal_maxprecise = kk_integer_from_double((0x1.c6bf52634p49),kk_context()); /*int*/
  }
  {
    kk_integer_t _x7282 = kk_integer_from_double((0x1.c6bf52634p49),kk_context()); /*int*/
    kk_std_num_decimal_minprecise = kk_integer_neg(_x7282,kk_context()); /*int*/
  }
}
