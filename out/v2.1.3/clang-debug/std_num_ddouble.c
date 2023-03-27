// Koka generated module: "std/num/ddouble", koka version: 2.1.3
#include "std_num_ddouble.h"

kk_integer_t kk_std_num_ddouble_maxprecise;

kk_integer_t kk_std_num_ddouble_dd_default_prec;

kk_integer_t kk_std_num_ddouble_dd_max_prec;
 
// Compare two `:ddouble` values.

kk_std_core_types__order kk_std_num_ddouble_compare(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_context_t* _ctx) { /* (x : ddouble, y : ddouble) -> order */ 
  kk_std_core_types__order _match_22009;
  bool _match_22012;
  double _x22030;
  double _x = x.hi;
  _x22030 = _x; /*double*/
  double _x22031;
  double _x0 = y.hi;
  _x22031 = _x0; /*double*/
  _match_22012 = (_x22030 < _x22031); /*bool*/
  if (_match_22012) {
    _match_22009 = kk_std_core_types__new_Lt(_ctx); /*order*/
  }
  else {
    bool _match_22013;
    double _x22032;
    double _x1 = x.hi;
    _x22032 = _x1; /*double*/
    double _x22033;
    double _x00 = y.hi;
    _x22033 = _x00; /*double*/
    _match_22013 = (_x22032 > _x22033); /*bool*/
    if (_match_22013) {
      _match_22009 = kk_std_core_types__new_Gt(_ctx); /*order*/
    }
    else {
      _match_22009 = kk_std_core_types__new_Eq(_ctx); /*order*/
    }
  }
  if (kk_std_core_types__is_Eq(_match_22009)) {
    bool _match_22010;
    double _x22034;
    double _x10 = x.lo;
    _x22034 = _x10; /*double*/
    double _x22035;
    double _x2 = y.lo;
    _x22035 = _x2; /*double*/
    _match_22010 = (_x22034 < _x22035); /*bool*/
    if (_match_22010) {
      return kk_std_core_types__new_Lt(_ctx);
    }
    bool _match_22011;
    double _x22036;
    double _x11 = x.lo;
    _x22036 = _x11; /*double*/
    double _x22037;
    double _x20 = y.lo;
    _x22037 = _x20; /*double*/
    _match_22011 = (_x22036 > _x22037); /*bool*/
    if (_match_22011) {
      return kk_std_core_types__new_Gt(_ctx);
    }
    return kk_std_core_types__new_Eq(_ctx);
  }
  return _match_22009;
}

bool kk_std_num_ddouble__lp__excl__eq__rp_(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_context_t* _ctx) { /* (x : ddouble, y : ddouble) -> bool */ 
  kk_std_core_types__order x0_20593 = kk_std_num_ddouble_compare(x, y, _ctx); /*order*/;
  kk_integer_t _x22038 = kk_std_core_int_5(x0_20593, _ctx); /*int*/
  kk_integer_t _x22039;
  kk_std_core_types__order _x22040 = kk_std_core_types__new_Eq(_ctx); /*order*/
  if (kk_std_core_types__is_Lt(_x22040)) {
    _x22039 = kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context()); /*int*/
    goto _match22041;
  }
  if (kk_std_core_types__is_Eq(_x22040)) {
    _x22039 = kk_integer_from_small(0); /*int*/
    goto _match22041;
  }
  _x22039 = kk_integer_from_small(1); /*int*/
  _match22041: ;
  return kk_integer_neq(_x22038,_x22039,kk_context());
}

bool kk_std_num_ddouble__lp__lt__eq__rp_(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_context_t* _ctx) { /* (x : ddouble, y : ddouble) -> bool */ 
  kk_std_core_types__order x0_20595 = kk_std_num_ddouble_compare(x, y, _ctx); /*order*/;
  kk_integer_t _x22042 = kk_std_core_int_5(x0_20595, _ctx); /*int*/
  kk_integer_t _x22043;
  kk_std_core_types__order _x22044 = kk_std_core_types__new_Gt(_ctx); /*order*/
  if (kk_std_core_types__is_Lt(_x22044)) {
    _x22043 = kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context()); /*int*/
    goto _match22045;
  }
  if (kk_std_core_types__is_Eq(_x22044)) {
    _x22043 = kk_integer_from_small(0); /*int*/
    goto _match22045;
  }
  _x22043 = kk_integer_from_small(1); /*int*/
  _match22045: ;
  return kk_integer_neq(_x22042,_x22043,kk_context());
}

bool kk_std_num_ddouble__lp__gt__eq__rp_(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_context_t* _ctx) { /* (x : ddouble, y : ddouble) -> bool */ 
  kk_std_core_types__order x0_20597 = kk_std_num_ddouble_compare(x, y, _ctx); /*order*/;
  kk_integer_t _x22046 = kk_std_core_int_5(x0_20597, _ctx); /*int*/
  kk_integer_t _x22047;
  kk_std_core_types__order _x22048 = kk_std_core_types__new_Lt(_ctx); /*order*/
  if (kk_std_core_types__is_Lt(_x22048)) {
    _x22047 = kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context()); /*int*/
    goto _match22049;
  }
  if (kk_std_core_types__is_Eq(_x22048)) {
    _x22047 = kk_integer_from_small(0); /*int*/
    goto _match22049;
  }
  _x22047 = kk_integer_from_small(1); /*int*/
  _match22049: ;
  return kk_integer_neq(_x22046,_x22047,kk_context());
}

bool kk_std_num_ddouble__lp__eq__eq__rp_(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_context_t* _ctx) { /* (x : ddouble, y : ddouble) -> bool */ 
  kk_std_core_types__order x0_20605 = kk_std_num_ddouble_compare(x, y, _ctx); /*order*/;
  kk_integer_t _x22054 = kk_std_core_int_5(x0_20605, _ctx); /*int*/
  kk_integer_t _x22055;
  kk_std_core_types__order _x22056 = kk_std_core_types__new_Eq(_ctx); /*order*/
  if (kk_std_core_types__is_Lt(_x22056)) {
    _x22055 = kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context()); /*int*/
    goto _match22057;
  }
  if (kk_std_core_types__is_Eq(_x22056)) {
    _x22055 = kk_integer_from_small(0); /*int*/
    goto _match22057;
  }
  _x22055 = kk_integer_from_small(1); /*int*/
  _match22057: ;
  return kk_integer_eq(_x22054,_x22055,kk_context());
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble_dquicksum(double x, double y, kk_context_t* _ctx) { /* (x : double, y : double) -> ddouble */ 
  bool _match_22002;
  bool _x22058 = isfinite(x); /*bool*/
  _match_22002 = !(_x22058); /*bool*/
  if (_match_22002) {
    return kk_std_num_ddouble_ddouble(x, _ctx);
  }
  double z = (x + y); /*double*/;
  double err0;
  double _x22059 = (z - x); /*double*/
  err0 = (y - _x22059); /*double*/
  double _x22060;
  bool _match_22003 = isfinite(z); /*bool*/;
  if (_match_22003) {
    _x22060 = err0; /*double*/
  }
  else {
    _x22060 = z; /*double*/
  }
  return kk_std_num_ddouble__new_Ddouble(z, _x22060, _ctx);
}
 
// Multiply two `:ddouble`s

kk_std_num_ddouble__ddouble kk_std_num_ddouble__lp__star__rp_(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_context_t* _ctx) { /* (x : ddouble, y : ddouble) -> ddouble */ 
  kk_std_num_ddouble__edouble z0;
  double z;
  double _x22062;
  double _x = x.hi;
  _x22062 = _x; /*double*/
  double _x22063;
  double _x0 = y.hi;
  _x22063 = _x0; /*double*/
  z = (_x22062 * _x22063); /*double*/
  double err0;
  double _x22064;
  double _x1 = x.hi;
  _x22064 = _x1; /*double*/
  double _x22065;
  double _x00 = y.hi;
  _x22065 = _x00; /*double*/
  double _x22066 = (-z); /*double*/
  err0 = kk_std_num_double_fmadd(_x22064, _x22065, _x22066, _ctx); /*double*/
  z0 = kk_std_num_ddouble__new_Edouble(z, err0, _ctx); /*std/num/ddouble/edouble*/
  double e;
  double _x22067;
  double _x10 = z0.err;
  _x22067 = _x10; /*double*/
  double _x22068;
  double _x22069;
  double _x22070;
  double _x2 = x.hi;
  _x22070 = _x2; /*double*/
  double _x22071;
  double _x3 = y.lo;
  _x22071 = _x3; /*double*/
  _x22069 = (_x22070 * _x22071); /*double*/
  double _x22072;
  double _x22073;
  double _x4 = x.lo;
  _x22073 = _x4; /*double*/
  double _x22074;
  double _x5 = y.hi;
  _x22074 = _x5; /*double*/
  _x22072 = (_x22073 * _x22074); /*double*/
  _x22068 = (_x22069 + _x22072); /*double*/
  e = (_x22067 + _x22068); /*double*/
  bool _match_22000;
  bool _x22075;
  double _x22076;
  double _x6 = z0.num;
  _x22076 = _x6; /*double*/
  _x22075 = isfinite(_x22076); /*bool*/
  _match_22000 = !(_x22075); /*bool*/
  if (_match_22000) {
    double _x22077;
    double _x60 = z0.num;
    _x22077 = _x60; /*double*/
    return kk_std_num_ddouble_ddouble(_x22077, _ctx);
  }
  double z1;
  double _x22078;
  double _x61 = z0.num;
  _x22078 = _x61; /*double*/
  z1 = (_x22078 + e); /*double*/
  double err00;
  double _x22079;
  double _x22080;
  double _x62 = z0.num;
  _x22080 = _x62; /*double*/
  _x22079 = (z1 - _x22080); /*double*/
  err00 = (e - _x22079); /*double*/
  double _x22081;
  bool _match_22001 = isfinite(z1); /*bool*/;
  if (_match_22001) {
    _x22081 = err00; /*double*/
  }
  else {
    _x22081 = z1; /*double*/
  }
  return kk_std_num_ddouble__new_Ddouble(z1, _x22081, _ctx);
}
 
// As `sum` but with `x.abs >= y.abs`

kk_std_num_ddouble__edouble kk_std_num_ddouble_quicksum(double x, double y, kk_context_t* _ctx) { /* (x : double, y : double) -> edouble */ 
  double z = (x + y); /*double*/;
  double err0;
  double _x22082 = (z - x); /*double*/
  err0 = (y - _x22082); /*double*/
  double _x22083;
  bool _match_21999 = isfinite(z); /*bool*/;
  if (_match_21999) {
    _x22083 = err0; /*double*/
  }
  else {
    _x22083 = z; /*double*/
  }
  return kk_std_num_ddouble__new_Edouble(z, _x22083, _ctx);
}
 
// often called `twosum` in literature (see [@shewchuk])

kk_std_num_ddouble__edouble kk_std_num_ddouble_sum(double x, double y, kk_context_t* _ctx) { /* (x : double, y : double) -> edouble */ 
  double z = (x + y); /*double*/;
  double diff = (z - x); /*double*/;
  double err0;
  double _x22084;
  double _x22085 = (z - diff); /*double*/
  _x22084 = (x - _x22085); /*double*/
  double _x22086 = (y - diff); /*double*/
  err0 = (_x22084 + _x22086); /*double*/
  double _x22087;
  bool _match_21998 = isfinite(z); /*bool*/;
  if (_match_21998) {
    _x22087 = err0; /*double*/
  }
  else {
    _x22087 = z; /*double*/
  }
  return kk_std_num_ddouble__new_Edouble(z, _x22087, _ctx);
}
 
// Add two `:ddouble`s

kk_std_num_ddouble__ddouble kk_std_num_ddouble__lp__plus__rp_(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_context_t* _ctx) { /* (x : ddouble, y : ddouble) -> ddouble */ 
  kk_std_num_ddouble__edouble z1;
  double z;
  double _x22088;
  double _x = x.hi;
  _x22088 = _x; /*double*/
  double _x22089;
  double _x0 = y.hi;
  _x22089 = _x0; /*double*/
  z = (_x22088 + _x22089); /*double*/
  double diff;
  double _x22090;
  double _x1 = x.hi;
  _x22090 = _x1; /*double*/
  diff = (z - _x22090); /*double*/
  double err0;
  double _x22091;
  double _x22092;
  double _x2 = x.hi;
  _x22092 = _x2; /*double*/
  double _x22093 = (z - diff); /*double*/
  _x22091 = (_x22092 - _x22093); /*double*/
  double _x22094;
  double _x22095;
  double _x00 = y.hi;
  _x22095 = _x00; /*double*/
  _x22094 = (_x22095 - diff); /*double*/
  err0 = (_x22091 + _x22094); /*double*/
  double _x22096;
  bool _match_21997 = isfinite(z); /*bool*/;
  if (_match_21997) {
    _x22096 = err0; /*double*/
  }
  else {
    _x22096 = z; /*double*/
  }
  z1 = kk_std_num_ddouble__new_Edouble(z, _x22096, _ctx); /*std/num/ddouble/edouble*/
  kk_std_num_ddouble__edouble lo0;
  double z0;
  double _x22097;
  double _x10 = x.lo;
  _x22097 = _x10; /*double*/
  double _x22098;
  double _x20 = y.lo;
  _x22098 = _x20; /*double*/
  z0 = (_x22097 + _x22098); /*double*/
  double diff0;
  double _x22099;
  double _x11 = x.lo;
  _x22099 = _x11; /*double*/
  diff0 = (z0 - _x22099); /*double*/
  double err00;
  double _x22100;
  double _x22101;
  double _x12 = x.lo;
  _x22101 = _x12; /*double*/
  double _x22102 = (z0 - diff0); /*double*/
  _x22100 = (_x22101 - _x22102); /*double*/
  double _x22103;
  double _x22104;
  double _x21 = y.lo;
  _x22104 = _x21; /*double*/
  _x22103 = (_x22104 - diff0); /*double*/
  err00 = (_x22100 + _x22103); /*double*/
  double _x22105;
  bool _match_21996 = isfinite(z0); /*bool*/;
  if (_match_21996) {
    _x22105 = err00; /*double*/
  }
  else {
    _x22105 = z0; /*double*/
  }
  lo0 = kk_std_num_ddouble__new_Edouble(z0, _x22105, _ctx); /*std/num/ddouble/edouble*/
  double e1;
  double _x22106;
  double _x3 = z1.err;
  _x22106 = _x3; /*double*/
  double _x22107;
  double _x4 = lo0.num;
  _x22107 = _x4; /*double*/
  e1 = (_x22106 + _x22107); /*double*/
  kk_std_num_ddouble__edouble z20;
  double z2;
  double _x22108;
  double _x5 = z1.num;
  _x22108 = _x5; /*double*/
  z2 = (_x22108 + e1); /*double*/
  double err1;
  double _x22109;
  double _x22110;
  double _x50 = z1.num;
  _x22110 = _x50; /*double*/
  _x22109 = (z2 - _x22110); /*double*/
  err1 = (e1 - _x22109); /*double*/
  double _x22111;
  bool _match_21995 = isfinite(z2); /*bool*/;
  if (_match_21995) {
    _x22111 = err1; /*double*/
  }
  else {
    _x22111 = z2; /*double*/
  }
  z20 = kk_std_num_ddouble__new_Edouble(z2, _x22111, _ctx); /*std/num/ddouble/edouble*/
  double e2;
  double _x22112;
  double _x6 = z20.err;
  _x22112 = _x6; /*double*/
  double _x22113;
  double _x7 = lo0.err;
  _x22113 = _x7; /*double*/
  e2 = (_x22112 + _x22113); /*double*/
  bool _match_21993;
  bool _x22114;
  double _x22115;
  double _x8 = z20.num;
  _x22115 = _x8; /*double*/
  _x22114 = isfinite(_x22115); /*bool*/
  _match_21993 = !(_x22114); /*bool*/
  if (_match_21993) {
    double _x22116;
    double _x80 = z20.num;
    _x22116 = _x80; /*double*/
    return kk_std_num_ddouble_ddouble(_x22116, _ctx);
  }
  double z3;
  double _x22117;
  double _x81 = z20.num;
  _x22117 = _x81; /*double*/
  z3 = (_x22117 + e2); /*double*/
  double err2;
  double _x22118;
  double _x22119;
  double _x82 = z20.num;
  _x22119 = _x82; /*double*/
  _x22118 = (z3 - _x22119); /*double*/
  err2 = (e2 - _x22118); /*double*/
  double _x22120;
  bool _match_21994 = isfinite(z3); /*bool*/;
  if (_match_21994) {
    _x22120 = err2; /*double*/
  }
  else {
    _x22120 = z3; /*double*/
  }
  return kk_std_num_ddouble__new_Ddouble(z3, _x22120, _ctx);
}
 
// Divide two `:ddouble`s

kk_std_num_ddouble__ddouble kk_std_num_ddouble__lp__fs__rp_(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_context_t* _ctx) { /* (x : ddouble, y : ddouble) -> ddouble */ 
  kk_std_num_ddouble__ddouble q1;
  double d_20639;
  double _x22126;
  double _x = x.hi;
  _x22126 = _x; /*double*/
  double _x22127;
  double _x0 = y.hi;
  _x22127 = _x0; /*double*/
  d_20639 = (_x22126 / _x22127); /*double*/
  q1 = kk_std_num_ddouble__new_Ddouble(d_20639, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  bool _match_21989;
  bool _match_21992;
  bool _x22128 = kk_std_num_ddouble_is_finite(q1, _ctx); /*bool*/
  _match_21992 = !(_x22128); /*bool*/
  if (_match_21992) {
    _match_21989 = true; /*bool*/
  }
  else {
    bool _x22129;
    double _x22130;
    double _x1 = y.hi;
    _x22130 = _x1; /*double*/
    _x22129 = isfinite(_x22130); /*bool*/
    _match_21989 = !(_x22129); /*bool*/
  }
  if (_match_21989) {
    return q1;
  }
  kk_std_num_ddouble__ddouble r1;
  kk_std_num_ddouble__ddouble y0_20644 = kk_std_num_ddouble__lp__star__rp_(y, q1, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__ddouble _x22131 = kk_std_num_ddouble__lp__tilde__rp_(y0_20644, _ctx); /*std/num/ddouble/ddouble*/
  r1 = kk_std_num_ddouble__lp__plus__rp_(x, _x22131, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble q2;
  double d0_20645;
  double _x22132;
  double _x2 = r1.hi;
  _x22132 = _x2; /*double*/
  double _x22133;
  double _x3 = y.hi;
  _x22133 = _x3; /*double*/
  d0_20645 = (_x22132 / _x22133); /*double*/
  q2 = kk_std_num_ddouble__new_Ddouble(d0_20645, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble r2;
  kk_std_num_ddouble__ddouble y1_20649 = kk_std_num_ddouble__lp__star__rp_(y, q2, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__ddouble _x22134 = kk_std_num_ddouble__lp__tilde__rp_(y1_20649, _ctx); /*std/num/ddouble/ddouble*/
  r2 = kk_std_num_ddouble__lp__plus__rp_(r1, _x22134, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble q3;
  double d1_20650;
  double _x22135;
  double _x4 = r2.hi;
  _x22135 = _x4; /*double*/
  double _x22136;
  double _x5 = y.hi;
  _x22136 = _x5; /*double*/
  d1_20650 = (_x22135 / _x22136); /*double*/
  q3 = kk_std_num_ddouble__new_Ddouble(d1_20650, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble q;
  bool _match_21990;
  bool _x22137;
  double _x22138;
  double _x6 = q1.hi;
  _x22138 = _x6; /*double*/
  _x22137 = isfinite(_x22138); /*bool*/
  _match_21990 = !(_x22137); /*bool*/
  if (_match_21990) {
    double _x22139;
    double _x60 = q1.hi;
    _x22139 = _x60; /*double*/
    q = kk_std_num_ddouble_ddouble(_x22139, _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    double z;
    double _x22140;
    double _x61 = q1.hi;
    _x22140 = _x61; /*double*/
    double _x22141;
    double _x7 = q2.hi;
    _x22141 = _x7; /*double*/
    z = (_x22140 + _x22141); /*double*/
    double err0;
    double _x22142;
    double _x70 = q2.hi;
    _x22142 = _x70; /*double*/
    double _x22143;
    double _x22144;
    double _x62 = q1.hi;
    _x22144 = _x62; /*double*/
    _x22143 = (z - _x22144); /*double*/
    err0 = (_x22142 - _x22143); /*double*/
    double _x22145;
    bool _match_21991 = isfinite(z); /*bool*/;
    if (_match_21991) {
      _x22145 = err0; /*double*/
    }
    else {
      _x22145 = z; /*double*/
    }
    q = kk_std_num_ddouble__new_Ddouble(z, _x22145, _ctx); /*std/num/ddouble/ddouble*/
  }
  return kk_std_num_ddouble__lp__plus__rp_(q, q3, _ctx);
}
 
// Not-A-Number

kk_std_num_ddouble__ddouble kk_std_num_ddouble_dd_nan;

kk_integer_t kk_std_num_ddouble_minprecise;

bool kk_std_num_ddouble_is_precise(kk_integer_t i, kk_context_t* _ctx) { /* (i : int) -> bool */ 
  bool _match_21987;
  kk_integer_t _x22147 = kk_integer_dup(i); /*int*/
  kk_integer_t _x22148 = kk_integer_neg((kk_integer_from_str("9007199254740991", _ctx)),kk_context()); /*int*/
  _match_21987 = kk_integer_gte(_x22147,_x22148,kk_context()); /*bool*/
  if (_match_21987) {
    return kk_integer_lte(i,(kk_integer_from_str("9007199254740991", _ctx)),kk_context());
  }
  kk_integer_drop(i, _ctx);
  return false;
}
 
// Multiply `x` with itself.

kk_std_num_ddouble__ddouble kk_std_num_ddouble_sqr(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> ddouble */ 
  kk_std_num_ddouble__edouble z0;
  double z;
  double _x22150;
  double _x = x.hi;
  _x22150 = _x; /*double*/
  double _x22151;
  double _x0 = x.hi;
  _x22151 = _x0; /*double*/
  z = (_x22150 * _x22151); /*double*/
  double err0;
  double _x22152;
  double _x1 = x.hi;
  _x22152 = _x1; /*double*/
  double _x22153;
  double _x2 = x.hi;
  _x22153 = _x2; /*double*/
  double _x22154 = (-z); /*double*/
  err0 = kk_std_num_double_fmadd(_x22152, _x22153, _x22154, _ctx); /*double*/
  z0 = kk_std_num_ddouble__new_Edouble(z, err0, _ctx); /*std/num/ddouble/edouble*/
  double e;
  double _x22155;
  double _x22156;
  double _x00 = z0.err;
  _x22156 = _x00; /*double*/
  double _x22157;
  double _x22158;
  double _x22159;
  double _x10 = x.hi;
  _x22159 = _x10; /*double*/
  _x22158 = (0x1p1 * _x22159); /*double*/
  double _x22160;
  double _x20 = x.lo;
  _x22160 = _x20; /*double*/
  _x22157 = (_x22158 * _x22160); /*double*/
  _x22155 = (_x22156 + _x22157); /*double*/
  double _x22161;
  double _x22162;
  double _x3 = x.lo;
  _x22162 = _x3; /*double*/
  double _x22163;
  double _x4 = x.lo;
  _x22163 = _x4; /*double*/
  _x22161 = (_x22162 * _x22163); /*double*/
  e = (_x22155 + _x22161); /*double*/
  bool _match_21985;
  bool _x22164;
  double _x22165;
  double _x5 = z0.num;
  _x22165 = _x5; /*double*/
  _x22164 = isfinite(_x22165); /*bool*/
  _match_21985 = !(_x22164); /*bool*/
  if (_match_21985) {
    double _x22166;
    double _x50 = z0.num;
    _x22166 = _x50; /*double*/
    return kk_std_num_ddouble_ddouble(_x22166, _ctx);
  }
  double z1;
  double _x22167;
  double _x51 = z0.num;
  _x22167 = _x51; /*double*/
  z1 = (_x22167 + e); /*double*/
  double err00;
  double _x22168;
  double _x22169;
  double _x52 = z0.num;
  _x22169 = _x52; /*double*/
  _x22168 = (z1 - _x22169); /*double*/
  err00 = (e - _x22168); /*double*/
  double _x22170;
  bool _match_21986 = isfinite(z1); /*bool*/;
  if (_match_21986) {
    _x22170 = err00; /*double*/
  }
  else {
    _x22170 = z1; /*double*/
  }
  return kk_std_num_ddouble__new_Ddouble(z1, _x22170, _ctx);
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble_npwr_acc(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble acc, kk_integer_t n, kk_context_t* _ctx) { /* (x : ddouble, acc : ddouble, n : int) -> ddouble */ 
  kk__tailcall: ;
  bool _match_21983;
  kk_integer_t _x22171 = kk_integer_dup(n); /*int*/
  _match_21983 = kk_integer_lte(_x22171,(kk_integer_from_small(0)),kk_context()); /*bool*/
  if (_match_21983) {
    kk_integer_drop(n, _ctx);
    return acc;
  }
  bool _match_21984;
  kk_integer_t _x22172 = kk_integer_dup(n); /*int*/
  _match_21984 = kk_std_core_is_even(_x22172, _ctx); /*bool*/
  if (_match_21984) {
    { // tailcall
      kk_std_num_ddouble__ddouble _x22173 = kk_std_num_ddouble_sqr(x, _ctx); /*std/num/ddouble/ddouble*/
      kk_integer_t _x22174 = kk_integer_div(n,(kk_integer_from_small(2)),kk_context()); /*int*/
      x = _x22173;
      n = _x22174;
      goto kk__tailcall;
    }
  }
  { // tailcall
    kk_std_num_ddouble__ddouble _x22175 = kk_std_num_ddouble__lp__star__rp_(x, acc, _ctx); /*std/num/ddouble/ddouble*/
    kk_integer_t _x22176 = kk_std_core_dec(n, _ctx); /*int*/
    acc = _x22175;
    n = _x22176;
    goto kk__tailcall;
  }
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble_one;

kk_std_num_ddouble__ddouble kk_std_num_ddouble_npwr(kk_std_num_ddouble__ddouble x, kk_integer_t n, kk_context_t* _ctx) { /* (x : ddouble, n : int) -> ddouble */ 
  bool _match_21980;
  kk_integer_t _x22177 = kk_integer_dup(n); /*int*/
  _match_21980 = kk_integer_eq(_x22177,(kk_integer_from_small(0)),kk_context()); /*bool*/
  if (_match_21980) {
    kk_integer_drop(n, _ctx);
    bool _match_21982 = kk_std_num_ddouble_is_zero(x, _ctx); /*bool*/;
    if (_match_21982) {
      return kk_std_num_ddouble_dd_nan;
    }
    return kk_std_num_ddouble__new_Ddouble(0x1p0, 0x0p+0, _ctx);
  }
  bool _match_21981;
  kk_integer_t _x22178 = kk_integer_dup(n); /*int*/
  _match_21981 = kk_integer_eq(_x22178,(kk_integer_from_small(1)),kk_context()); /*bool*/
  if (_match_21981) {
    kk_integer_drop(n, _ctx);
    return x;
  }
  kk_std_num_ddouble__ddouble _x22179 = kk_std_num_ddouble__new_Ddouble(0x1p0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble_npwr_acc(x, _x22179, n, _ctx);
}
 
// Return `x` to the power of `n`.

kk_std_num_ddouble__ddouble kk_std_num_ddouble_powi(kk_std_num_ddouble__ddouble x, kk_integer_t n, kk_context_t* _ctx) { /* (x : ddouble, n : int) -> ddouble */ 
  kk_std_num_ddouble__ddouble p;
  kk_integer_t n0_20669;
  kk_integer_t _x22180 = kk_integer_dup(n); /*int*/
  n0_20669 = kk_integer_abs(_x22180,kk_context()); /*int*/
  bool _match_21977;
  kk_integer_t _x22181 = kk_integer_dup(n0_20669); /*int*/
  _match_21977 = kk_integer_eq(_x22181,(kk_integer_from_small(0)),kk_context()); /*bool*/
  if (_match_21977) {
    kk_integer_drop(n0_20669, _ctx);
    bool _match_21979 = kk_std_num_ddouble_is_zero(x, _ctx); /*bool*/;
    if (_match_21979) {
      p = kk_std_num_ddouble_dd_nan; /*std/num/ddouble/ddouble*/
    }
    else {
      p = kk_std_num_ddouble__new_Ddouble(0x1p0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    }
  }
  else {
    bool _match_21978;
    kk_integer_t _x22182 = kk_integer_dup(n0_20669); /*int*/
    _match_21978 = kk_integer_eq(_x22182,(kk_integer_from_small(1)),kk_context()); /*bool*/
    if (_match_21978) {
      kk_integer_drop(n0_20669, _ctx);
      p = x; /*std/num/ddouble/ddouble*/
    }
    else {
      kk_std_num_ddouble__ddouble _x22183 = kk_std_num_ddouble__new_Ddouble(0x1p0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
      p = kk_std_num_ddouble_npwr_acc(x, _x22183, n0_20669, _ctx); /*std/num/ddouble/ddouble*/
    }
  }
  bool _match_21976 = kk_std_core_is_neg_2(n, _ctx); /*bool*/;
  if (_match_21976) {
    kk_std_num_ddouble__ddouble _x22184 = kk_std_num_ddouble__new_Ddouble(0x1p0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    return kk_std_num_ddouble__lp__fs__rp_(_x22184, p, _ctx);
  }
  return p;
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble_ten;

kk_std_num_ddouble__ddouble kk_std_num_ddouble_mul_exp10(kk_std_num_ddouble__ddouble x, kk_integer_t exp0, kk_context_t* _ctx) { /* (x : ddouble, exp : int) -> ddouble */ 
  bool _match_21973;
  kk_integer_t _x22186 = kk_integer_dup(exp0); /*int*/
  _match_21973 = kk_integer_is_zero(_x22186,kk_context()); /*bool*/
  if (_match_21973) {
    kk_integer_drop(exp0, _ctx);
    return x;
  }
  kk_std_num_ddouble__ddouble y_21098 = kk_std_num_ddouble_powi10(exp0, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__edouble z0;
  double z;
  double _x22187;
  double _x = x.hi;
  _x22187 = _x; /*double*/
  double _x22188;
  double _x0 = y_21098.hi;
  _x22188 = _x0; /*double*/
  z = (_x22187 * _x22188); /*double*/
  double err0;
  double _x22189;
  double _x1 = x.hi;
  _x22189 = _x1; /*double*/
  double _x22190;
  double _x00 = y_21098.hi;
  _x22190 = _x00; /*double*/
  double _x22191 = (-z); /*double*/
  err0 = kk_std_num_double_fmadd(_x22189, _x22190, _x22191, _ctx); /*double*/
  z0 = kk_std_num_ddouble__new_Edouble(z, err0, _ctx); /*std/num/ddouble/edouble*/
  double e;
  double _x22192;
  double _x10 = z0.err;
  _x22192 = _x10; /*double*/
  double _x22193;
  double _x22194;
  double _x22195;
  double _x2 = x.hi;
  _x22195 = _x2; /*double*/
  double _x22196;
  double _x3 = y_21098.lo;
  _x22196 = _x3; /*double*/
  _x22194 = (_x22195 * _x22196); /*double*/
  double _x22197;
  double _x22198;
  double _x4 = x.lo;
  _x22198 = _x4; /*double*/
  double _x22199;
  double _x5 = y_21098.hi;
  _x22199 = _x5; /*double*/
  _x22197 = (_x22198 * _x22199); /*double*/
  _x22193 = (_x22194 + _x22197); /*double*/
  e = (_x22192 + _x22193); /*double*/
  bool _match_21974;
  bool _x22200;
  double _x22201;
  double _x6 = z0.num;
  _x22201 = _x6; /*double*/
  _x22200 = isfinite(_x22201); /*bool*/
  _match_21974 = !(_x22200); /*bool*/
  if (_match_21974) {
    double _x22202;
    double _x60 = z0.num;
    _x22202 = _x60; /*double*/
    return kk_std_num_ddouble_ddouble(_x22202, _ctx);
  }
  double z1;
  double _x22203;
  double _x61 = z0.num;
  _x22203 = _x61; /*double*/
  z1 = (_x22203 + e); /*double*/
  double err00;
  double _x22204;
  double _x22205;
  double _x62 = z0.num;
  _x22205 = _x62; /*double*/
  _x22204 = (z1 - _x22205); /*double*/
  err00 = (e - _x22204); /*double*/
  double _x22206;
  bool _match_21975 = isfinite(z1); /*bool*/;
  if (_match_21975) {
    _x22206 = err00; /*double*/
  }
  else {
    _x22206 = z1; /*double*/
  }
  return kk_std_num_ddouble__new_Ddouble(z1, _x22206, _ctx);
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble_small_exp(kk_integer_t i, kk_integer_t e, kk_context_t* _ctx) { /* (i : int, e : int) -> ddouble */ 
  kk_std_num_ddouble__ddouble dd;
  double d_20671 = kk_integer_as_double(i,kk_context()); /*double*/;
  dd = kk_std_num_ddouble__new_Ddouble(d_20671, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  bool _match_21972;
  kk_integer_t _x22207 = kk_integer_dup(e); /*int*/
  _match_21972 = kk_integer_is_zero(_x22207,kk_context()); /*bool*/
  if (_match_21972) {
    kk_integer_drop(e, _ctx);
    return dd;
  }
  return kk_std_num_ddouble_mul_exp10(dd, e, _ctx);
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble_ddouble_int_exp(kk_integer_t i, kk_integer_t e, kk_context_t* _ctx) { /* (i : int, e : int) -> ddouble */ 
  bool _match_21962;
  kk_integer_t _x22208 = kk_integer_dup(i); /*int*/
  _match_21962 = kk_std_num_ddouble_is_precise(_x22208, _ctx); /*bool*/
  if (_match_21962) {
    return kk_std_num_ddouble_small_exp(i, e, _ctx);
  }
  kk_integer_t p;
  kk_integer_t _x22209 = kk_integer_dup(i); /*int*/
  p = kk_std_core_count_digits(_x22209, _ctx); /*int*/
  kk_integer_t px = kk_integer_sub(p,(kk_integer_from_small(14)),kk_context()); /*int*/;
  kk_std_core_types__tuple2_ _match_21963;
  kk_integer_t _x22210 = kk_integer_dup(px); /*int*/
  _match_21963 = kk_std_core_cdivmod_exp10(i, _x22210, _ctx); /*(int, int)*/
  kk_box_t _box_x21215 = _match_21963.fst;
  kk_box_t _box_x21216 = _match_21963.snd;
  kk_integer_t hi0 = kk_integer_unbox(_box_x21215);
  kk_integer_t y = kk_integer_unbox(_box_x21216);
  kk_integer_dup(hi0);
  kk_integer_dup(y);
  kk_std_core_types__tuple2__drop(_match_21963, _ctx);
  kk_integer_t py;
  kk_integer_t _x22213 = kk_integer_dup(px); /*int*/
  py = kk_integer_sub(_x22213,(kk_integer_from_small(14)),kk_context()); /*int*/
  bool _match_21964;
  kk_integer_t _x22214 = kk_integer_dup(py); /*int*/
  _match_21964 = kk_integer_lte(_x22214,(kk_integer_from_small(0)),kk_context()); /*bool*/
  if (_match_21964) {
    kk_integer_drop(py, _ctx);
    kk_std_num_ddouble__ddouble _x22215;
    kk_integer_t e0_20673;
    kk_integer_t _x22216 = kk_integer_dup(e); /*int*/
    e0_20673 = kk_integer_add(px,_x22216,kk_context()); /*int*/
    kk_std_num_ddouble__ddouble dd;
    double d_20674 = kk_integer_as_double(hi0,kk_context()); /*double*/;
    dd = kk_std_num_ddouble__new_Ddouble(d_20674, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    bool _match_21971;
    kk_integer_t _x22217 = kk_integer_dup(e0_20673); /*int*/
    _match_21971 = kk_integer_is_zero(_x22217,kk_context()); /*bool*/
    if (_match_21971) {
      kk_integer_drop(e0_20673, _ctx);
      _x22215 = dd; /*std/num/ddouble/ddouble*/
    }
    else {
      _x22215 = kk_std_num_ddouble_mul_exp10(dd, e0_20673, _ctx); /*std/num/ddouble/ddouble*/
    }
    kk_std_num_ddouble__ddouble _x22218 = kk_std_num_ddouble_small_exp(y, e, _ctx); /*std/num/ddouble/ddouble*/
    return kk_std_num_ddouble__lp__plus__rp_(_x22215, _x22218, _ctx);
  }
  kk_std_core_types__tuple2_ _match_21965;
  kk_integer_t _x22219 = kk_integer_dup(py); /*int*/
  _match_21965 = kk_std_core_cdivmod_exp10(y, _x22219, _ctx); /*(int, int)*/
  kk_box_t _box_x21217 = _match_21965.fst;
  kk_box_t _box_x21218 = _match_21965.snd;
  kk_integer_t mid = kk_integer_unbox(_box_x21217);
  kk_integer_t z = kk_integer_unbox(_box_x21218);
  kk_integer_dup(mid);
  kk_integer_dup(z);
  kk_std_core_types__tuple2__drop(_match_21965, _ctx);
  kk_integer_t pz;
  kk_integer_t _x22222 = kk_integer_dup(py); /*int*/
  pz = kk_integer_sub(_x22222,(kk_integer_from_small(14)),kk_context()); /*int*/
  kk_std_core_types__tuple2_ _match_21966;
  bool _match_21970;
  kk_integer_t _x22223 = kk_integer_dup(pz); /*int*/
  _match_21970 = kk_integer_lte(_x22223,(kk_integer_from_small(0)),kk_context()); /*bool*/
  if (_match_21970) {
    kk_integer_drop(pz, _ctx);
    _match_21966 = kk_std_core_types__new_dash__lp__comma__rp_(kk_integer_box(z), kk_integer_box(kk_integer_from_small(0)), _ctx); /*(4, 5)*/
  }
  else {
    kk_integer_t _b_21227_21221;
    kk_integer_t _x22224 = kk_integer_dup(pz); /*int*/
    _b_21227_21221 = kk_std_core_cdiv_exp10(z, _x22224, _ctx); /*int*/
    _match_21966 = kk_std_core_types__new_dash__lp__comma__rp_(kk_integer_box(_b_21227_21221), kk_integer_box(pz), _ctx); /*(4, 5)*/
  }
  kk_box_t _box_x21223 = _match_21966.fst;
  kk_box_t _box_x21224 = _match_21966.snd;
  kk_integer_t lo0 = kk_integer_unbox(_box_x21223);
  kk_integer_t plo = kk_integer_unbox(_box_x21224);
  kk_integer_dup(lo0);
  kk_integer_dup(plo);
  kk_std_core_types__tuple2__drop(_match_21966, _ctx);
  kk_std_num_ddouble__ddouble _x22227;
  kk_integer_t e1_20676;
  kk_integer_t _x22228 = kk_integer_dup(e); /*int*/
  e1_20676 = kk_integer_add(px,_x22228,kk_context()); /*int*/
  kk_std_num_ddouble__ddouble dd0;
  double d0_20677 = kk_integer_as_double(hi0,kk_context()); /*double*/;
  dd0 = kk_std_num_ddouble__new_Ddouble(d0_20677, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  bool _match_21969;
  kk_integer_t _x22229 = kk_integer_dup(e1_20676); /*int*/
  _match_21969 = kk_integer_is_zero(_x22229,kk_context()); /*bool*/
  if (_match_21969) {
    kk_integer_drop(e1_20676, _ctx);
    _x22227 = dd0; /*std/num/ddouble/ddouble*/
  }
  else {
    _x22227 = kk_std_num_ddouble_mul_exp10(dd0, e1_20676, _ctx); /*std/num/ddouble/ddouble*/
  }
  kk_std_num_ddouble__ddouble _x22230;
  kk_std_num_ddouble__ddouble _x22231;
  kk_integer_t e2_20679;
  kk_integer_t _x22232 = kk_integer_dup(e); /*int*/
  e2_20679 = kk_integer_add(py,_x22232,kk_context()); /*int*/
  kk_std_num_ddouble__ddouble dd1;
  double d1_20680 = kk_integer_as_double(mid,kk_context()); /*double*/;
  dd1 = kk_std_num_ddouble__new_Ddouble(d1_20680, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  bool _match_21968;
  kk_integer_t _x22233 = kk_integer_dup(e2_20679); /*int*/
  _match_21968 = kk_integer_is_zero(_x22233,kk_context()); /*bool*/
  if (_match_21968) {
    kk_integer_drop(e2_20679, _ctx);
    _x22231 = dd1; /*std/num/ddouble/ddouble*/
  }
  else {
    _x22231 = kk_std_num_ddouble_mul_exp10(dd1, e2_20679, _ctx); /*std/num/ddouble/ddouble*/
  }
  kk_std_num_ddouble__ddouble _x22234;
  kk_integer_t e3_20682 = kk_integer_add(plo,e,kk_context()); /*int*/;
  kk_std_num_ddouble__ddouble dd2;
  double d2_20683 = kk_integer_as_double(lo0,kk_context()); /*double*/;
  dd2 = kk_std_num_ddouble__new_Ddouble(d2_20683, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  bool _match_21967;
  kk_integer_t _x22235 = kk_integer_dup(e3_20682); /*int*/
  _match_21967 = kk_integer_is_zero(_x22235,kk_context()); /*bool*/
  if (_match_21967) {
    kk_integer_drop(e3_20682, _ctx);
    _x22234 = dd2; /*std/num/ddouble/ddouble*/
  }
  else {
    _x22234 = kk_std_num_ddouble_mul_exp10(dd2, e3_20682, _ctx); /*std/num/ddouble/ddouble*/
  }
  _x22230 = kk_std_num_ddouble__lp__plus__rp_(_x22231, _x22234, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__lp__plus__rp_(_x22227, _x22230, _ctx);
}
 
// monadic lift

kk_integer_t kk_std_num_ddouble__mlift20569_pddouble_normal(kk_char_t wild__0, kk_context_t* _ctx) { /* (wild_0 : char) -> std/text/parse/parse int */ 
  return kk_std_text_parse_pint(_ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_num_ddouble__mlift20570_pddouble_normal_fun22248__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_ddouble__mlift20570_pddouble_normal_fun22248(kk_function_t _fself, kk_box_t _b_21234, kk_box_t _b_21235, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble__new_mlift20570_pddouble_normal_fun22248(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_ddouble__mlift20570_pddouble_normal_fun22248, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_ddouble__mlift20570_pddouble_normal_fun22248(kk_function_t _fself, kk_box_t _b_21234, kk_box_t _b_21235, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_num_ddouble__ddouble _x22249;
  kk_integer_t _x22250 = kk_integer_unbox(_b_21234); /*int*/
  kk_integer_t _x22251 = kk_integer_unbox(_b_21235); /*int*/
  _x22249 = kk_std_num_ddouble_ddouble_int_exp(_x22250, _x22251, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x22249, _ctx);
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble__mlift20570_pddouble_normal(kk_string_t frac, bool neg, kk_string_t whole, kk_integer_t exp0, kk_context_t* _ctx) { /* (frac : string, neg : bool, whole : string, exp : int) -> std/text/parse/parse ddouble */ 
  kk_integer_t w;
  kk_std_core_types__maybe m_20684;
  kk_string_t s_20686;
  kk_string_t _x22236;
  if (neg) {
    kk_define_string_literal(, _s22237, 1, "-")
    _x22236 = kk_string_dup(_s22237); /*string*/
  }
  else {
    _x22236 = kk_string_empty(); /*string*/
  }
  kk_string_t _x22239;
  kk_string_t _x22240 = kk_string_dup(frac); /*string*/
  _x22239 = kk_std_core__lp__plus__plus__1_rp_(whole, _x22240, _ctx); /*string*/
  s_20686 = kk_std_core__lp__plus__plus__1_rp_(_x22236, _x22239, _ctx); /*string*/
  kk_string_t _x22241 = kk_std_core_trim(s_20686, _ctx); /*string*/
  bool _x22242;
  kk_std_core_types__optional _match_21961 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
  if (kk_std_core_types__is_Optional(_match_21961)) {
    kk_box_t _box_x21229 = _match_21961._cons.Optional.value;
    bool _hex_19366 = kk_bool_unbox(_box_x21229);
    kk_std_core_types__optional_drop(_match_21961, _ctx);
    _x22242 = _hex_19366; /*bool*/
    goto _match22243;
  }
  _x22242 = false; /*bool*/
  _match22243: ;
  m_20684 = kk_std_core_xparse_int(_x22241, _x22242, _ctx); /*maybe<int>*/
  if (kk_std_core_types__is_Nothing(m_20684)) {
    w = kk_integer_from_small(0); /*int*/
  }
  else {
    kk_box_t _box_x21230 = m_20684._cons.Just.value;
    kk_integer_t x = kk_integer_unbox(_box_x21230);
    kk_integer_dup(x);
    kk_std_core_types__maybe_drop(m_20684, _ctx);
    w = x; /*int*/
  }
  kk_integer_t e;
  kk_integer_t _x22246 = kk_std_core_count_1(frac, _ctx); /*int*/
  e = kk_integer_sub(exp0,_x22246,kk_context()); /*int*/
  kk_box_t _x22247 = kk_std_core_hnd__open_none2(kk_std_num_ddouble__new_mlift20570_pddouble_normal_fun22248(_ctx), kk_integer_box(w), kk_integer_box(e), _ctx); /*3*/
  return kk_std_num_ddouble__ddouble_unbox(_x22247, _ctx);
}
 
// monadic lift

kk_string_t kk_std_num_ddouble__mlift20571_pddouble_normal(kk_char_t wild__, kk_context_t* _ctx) { /* (wild_ : char) -> std/text/parse/parse string */ 
  return kk_std_text_parse_digits(_ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_num_ddouble__mlift20572_pddouble_normal_fun22255__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_ddouble__mlift20572_pddouble_normal_fun22255(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble__new_mlift20572_pddouble_normal_fun22255(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_ddouble__mlift20572_pddouble_normal_fun22255, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_std_num_ddouble__mlift20572_pddouble_normal_fun22258__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_ddouble__mlift20572_pddouble_normal_fun22258(kk_function_t _fself, kk_box_t _b_21240, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble__new_mlift20572_pddouble_normal_fun22258(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_ddouble__mlift20572_pddouble_normal_fun22258, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_ddouble__mlift20572_pddouble_normal_fun22258(kk_function_t _fself, kk_box_t _b_21240, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_integer_t _x22259;
  kk_char_t _x22260 = kk_char_unbox(_b_21240, _ctx); /*char*/
  _x22259 = kk_std_num_ddouble__mlift20569_pddouble_normal(_x22260, _ctx); /*int*/
  return kk_integer_box(_x22259);
}
static kk_box_t kk_std_num_ddouble__mlift20572_pddouble_normal_fun22255(kk_function_t _fself, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_integer_t _x22256;
  kk_char_t x0_20690 = kk_std_text_parse_char('e', _ctx); /*char*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x22257 = kk_std_core_hnd_yield_extend(kk_std_num_ddouble__new_mlift20572_pddouble_normal_fun22258(_ctx), _ctx); /*2*/
    _x22256 = kk_integer_unbox(_x22257); /*int*/
  }
  else {
    _x22256 = kk_std_num_ddouble__mlift20569_pddouble_normal(x0_20690, _ctx); /*int*/
  }
  return kk_integer_box(_x22256);
}


// lift anonymous function
struct kk_std_num_ddouble__mlift20572_pddouble_normal_fun22262__t {
  struct kk_function_s _base;
  kk_string_t frac;
  kk_string_t whole;
  bool neg;
};
static kk_box_t kk_std_num_ddouble__mlift20572_pddouble_normal_fun22262(kk_function_t _fself, kk_box_t _b_21247, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble__new_mlift20572_pddouble_normal_fun22262(kk_string_t frac, kk_string_t whole, bool neg, kk_context_t* _ctx) {
  struct kk_std_num_ddouble__mlift20572_pddouble_normal_fun22262__t* _self = kk_function_alloc_as(struct kk_std_num_ddouble__mlift20572_pddouble_normal_fun22262__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_num_ddouble__mlift20572_pddouble_normal_fun22262, kk_context());
  _self->frac = frac;
  _self->whole = whole;
  _self->neg = neg;
  return &_self->_base;
}

static kk_box_t kk_std_num_ddouble__mlift20572_pddouble_normal_fun22262(kk_function_t _fself, kk_box_t _b_21247, kk_context_t* _ctx) {
  struct kk_std_num_ddouble__mlift20572_pddouble_normal_fun22262__t* _self = kk_function_as(struct kk_std_num_ddouble__mlift20572_pddouble_normal_fun22262__t*, _fself);
  kk_string_t frac = _self->frac; /* string */
  kk_string_t whole = _self->whole; /* string */
  bool neg = _self->neg; /* bool */
  kk_drop_match(_self, {kk_string_dup(frac);kk_string_dup(whole);;}, {}, _ctx)
  kk_std_num_ddouble__ddouble _x22263;
  kk_integer_t _x22264 = kk_integer_unbox(_b_21247); /*int*/
  _x22263 = kk_std_num_ddouble__mlift20570_pddouble_normal(frac, neg, whole, _x22264, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x22263, _ctx);
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble__mlift20572_pddouble_normal(bool neg, kk_string_t whole, kk_string_t _y_4, kk_context_t* _ctx) { /* (neg : bool, whole : string, string) -> std/text/parse/parse ddouble */ 
  kk_string_t frac;
  kk_string_t _x22252;
  kk_define_string_literal(, _s22253, 1, "0")
  _x22252 = kk_string_dup(_s22253); /*string*/
  frac = kk_std_core_trim_right_1(_y_4, _x22252, _ctx); /*string*/
  kk_integer_t x_20688;
  kk_box_t _x22254 = kk_std_text_parse_optional(kk_integer_box(kk_integer_from_small(0)), kk_std_num_ddouble__new_mlift20572_pddouble_normal_fun22255(_ctx), _ctx); /*0*/
  x_20688 = kk_integer_unbox(_x22254); /*int*/
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_20688, _ctx);
    kk_box_t _x22261 = kk_std_core_hnd_yield_extend(kk_std_num_ddouble__new_mlift20572_pddouble_normal_fun22262(frac, whole, neg, _ctx), _ctx); /*2*/
    return kk_std_num_ddouble__ddouble_unbox(_x22261, _ctx);
  }
  return kk_std_num_ddouble__mlift20570_pddouble_normal(frac, neg, whole, x_20688, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_num_ddouble__mlift20573_pddouble_normal_fun22269__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_ddouble__mlift20573_pddouble_normal_fun22269(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble__new_mlift20573_pddouble_normal_fun22269(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_ddouble__mlift20573_pddouble_normal_fun22269, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_std_num_ddouble__mlift20573_pddouble_normal_fun22272__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_ddouble__mlift20573_pddouble_normal_fun22272(kk_function_t _fself, kk_box_t _b_21251, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble__new_mlift20573_pddouble_normal_fun22272(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_ddouble__mlift20573_pddouble_normal_fun22272, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_ddouble__mlift20573_pddouble_normal_fun22272(kk_function_t _fself, kk_box_t _b_21251, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x22273;
  kk_char_t _x22274 = kk_char_unbox(_b_21251, _ctx); /*char*/
  _x22273 = kk_std_num_ddouble__mlift20571_pddouble_normal(_x22274, _ctx); /*string*/
  return kk_string_box(_x22273);
}
static kk_box_t kk_std_num_ddouble__mlift20573_pddouble_normal_fun22269(kk_function_t _fself, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x22270;
  kk_char_t x0_20694 = kk_std_text_parse_char('.', _ctx); /*char*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x22271 = kk_std_core_hnd_yield_extend(kk_std_num_ddouble__new_mlift20573_pddouble_normal_fun22272(_ctx), _ctx); /*2*/
    _x22270 = kk_string_unbox(_x22271); /*string*/
  }
  else {
    _x22270 = kk_std_num_ddouble__mlift20571_pddouble_normal(x0_20694, _ctx); /*string*/
  }
  return kk_string_box(_x22270);
}


// lift anonymous function
struct kk_std_num_ddouble__mlift20573_pddouble_normal_fun22276__t {
  struct kk_function_s _base;
  kk_string_t whole;
  bool neg;
};
static kk_box_t kk_std_num_ddouble__mlift20573_pddouble_normal_fun22276(kk_function_t _fself, kk_box_t _b_21258, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble__new_mlift20573_pddouble_normal_fun22276(kk_string_t whole, bool neg, kk_context_t* _ctx) {
  struct kk_std_num_ddouble__mlift20573_pddouble_normal_fun22276__t* _self = kk_function_alloc_as(struct kk_std_num_ddouble__mlift20573_pddouble_normal_fun22276__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_num_ddouble__mlift20573_pddouble_normal_fun22276, kk_context());
  _self->whole = whole;
  _self->neg = neg;
  return &_self->_base;
}

static kk_box_t kk_std_num_ddouble__mlift20573_pddouble_normal_fun22276(kk_function_t _fself, kk_box_t _b_21258, kk_context_t* _ctx) {
  struct kk_std_num_ddouble__mlift20573_pddouble_normal_fun22276__t* _self = kk_function_as(struct kk_std_num_ddouble__mlift20573_pddouble_normal_fun22276__t*, _fself);
  kk_string_t whole = _self->whole; /* string */
  bool neg = _self->neg; /* bool */
  kk_drop_match(_self, {kk_string_dup(whole);;}, {}, _ctx)
  kk_std_num_ddouble__ddouble _x22277;
  kk_string_t _x22278 = kk_string_unbox(_b_21258); /*string*/
  _x22277 = kk_std_num_ddouble__mlift20572_pddouble_normal(neg, whole, _x22278, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x22277, _ctx);
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble__mlift20573_pddouble_normal(bool neg, kk_string_t whole, kk_context_t* _ctx) { /* (neg : bool, whole : string) -> std/text/parse/parse ddouble */ 
  kk_string_t x_20692;
  kk_box_t _x22265;
  kk_box_t _x22266;
  kk_string_t _x22267 = kk_string_empty(); /*string*/
  _x22266 = kk_string_box(_x22267); /*0*/
  _x22265 = kk_std_text_parse_optional(_x22266, kk_std_num_ddouble__new_mlift20573_pddouble_normal_fun22269(_ctx), _ctx); /*0*/
  x_20692 = kk_string_unbox(_x22265); /*string*/
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_20692, _ctx);
    kk_box_t _x22275 = kk_std_core_hnd_yield_extend(kk_std_num_ddouble__new_mlift20573_pddouble_normal_fun22276(whole, neg, _ctx), _ctx); /*2*/
    return kk_std_num_ddouble__ddouble_unbox(_x22275, _ctx);
  }
  return kk_std_num_ddouble__mlift20572_pddouble_normal(neg, whole, x_20692, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_num_ddouble__mlift20574_pddouble_normal_fun22280__t {
  struct kk_function_s _base;
  bool neg;
};
static kk_box_t kk_std_num_ddouble__mlift20574_pddouble_normal_fun22280(kk_function_t _fself, kk_box_t _b_21262, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble__new_mlift20574_pddouble_normal_fun22280(bool neg, kk_context_t* _ctx) {
  struct kk_std_num_ddouble__mlift20574_pddouble_normal_fun22280__t* _self = kk_function_alloc_as(struct kk_std_num_ddouble__mlift20574_pddouble_normal_fun22280__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_num_ddouble__mlift20574_pddouble_normal_fun22280, kk_context());
  _self->neg = neg;
  return &_self->_base;
}

static kk_box_t kk_std_num_ddouble__mlift20574_pddouble_normal_fun22280(kk_function_t _fself, kk_box_t _b_21262, kk_context_t* _ctx) {
  struct kk_std_num_ddouble__mlift20574_pddouble_normal_fun22280__t* _self = kk_function_as(struct kk_std_num_ddouble__mlift20574_pddouble_normal_fun22280__t*, _fself);
  bool neg = _self->neg; /* bool */
  kk_drop_match(_self, {;}, {}, _ctx)
  kk_std_num_ddouble__ddouble _x22281;
  kk_string_t _x22282 = kk_string_unbox(_b_21262); /*string*/
  _x22281 = kk_std_num_ddouble__mlift20573_pddouble_normal(neg, _x22282, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x22281, _ctx);
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble__mlift20574_pddouble_normal(bool neg, kk_context_t* _ctx) { /* (neg : bool) -> std/text/parse/parse ddouble */ 
  kk_string_t x_20696 = kk_std_text_parse_digits(_ctx); /*string*/;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_20696, _ctx);
    kk_box_t _x22279 = kk_std_core_hnd_yield_extend(kk_std_num_ddouble__new_mlift20574_pddouble_normal_fun22280(neg, _ctx), _ctx); /*2*/
    return kk_std_num_ddouble__ddouble_unbox(_x22279, _ctx);
  }
  return kk_std_num_ddouble__mlift20573_pddouble_normal(neg, x_20696, _ctx);
}


// lift anonymous function
struct kk_std_num_ddouble_pddouble_normal_fun22284__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_ddouble_pddouble_normal_fun22284(kk_function_t _fself, kk_box_t _b_21266, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble_new_pddouble_normal_fun22284(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_ddouble_pddouble_normal_fun22284, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_ddouble_pddouble_normal_fun22284(kk_function_t _fself, kk_box_t _b_21266, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_num_ddouble__ddouble _x22285;
  bool _x22286 = kk_bool_unbox(_b_21266); /*bool*/
  _x22285 = kk_std_num_ddouble__mlift20574_pddouble_normal(_x22286, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x22285, _ctx);
}


// lift anonymous function
struct kk_std_num_ddouble_pddouble_normal_fun22288__t {
  struct kk_function_s _base;
  bool x_20698;
};
static kk_box_t kk_std_num_ddouble_pddouble_normal_fun22288(kk_function_t _fself, kk_box_t _b_21268, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble_new_pddouble_normal_fun22288(bool x_20698, kk_context_t* _ctx) {
  struct kk_std_num_ddouble_pddouble_normal_fun22288__t* _self = kk_function_alloc_as(struct kk_std_num_ddouble_pddouble_normal_fun22288__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_num_ddouble_pddouble_normal_fun22288, kk_context());
  _self->x_20698 = x_20698;
  return &_self->_base;
}

static kk_box_t kk_std_num_ddouble_pddouble_normal_fun22288(kk_function_t _fself, kk_box_t _b_21268, kk_context_t* _ctx) {
  struct kk_std_num_ddouble_pddouble_normal_fun22288__t* _self = kk_function_as(struct kk_std_num_ddouble_pddouble_normal_fun22288__t*, _fself);
  bool x_20698 = _self->x_20698; /* bool */
  kk_drop_match(_self, {;}, {}, _ctx)
  kk_std_num_ddouble__ddouble _x22289;
  kk_string_t _x22290 = kk_string_unbox(_b_21268); /*string*/
  _x22289 = kk_std_num_ddouble__mlift20573_pddouble_normal(x_20698, _x22290, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x22289, _ctx);
}


// lift anonymous function
struct kk_std_num_ddouble_pddouble_normal_fun22295__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_ddouble_pddouble_normal_fun22295(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble_new_pddouble_normal_fun22295(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_ddouble_pddouble_normal_fun22295, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_std_num_ddouble_pddouble_normal_fun22298__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_ddouble_pddouble_normal_fun22298(kk_function_t _fself, kk_box_t _b_21270, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble_new_pddouble_normal_fun22298(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_ddouble_pddouble_normal_fun22298, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_ddouble_pddouble_normal_fun22298(kk_function_t _fself, kk_box_t _b_21270, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x22299;
  kk_char_t _x22300 = kk_char_unbox(_b_21270, _ctx); /*char*/
  _x22299 = kk_std_num_ddouble__mlift20571_pddouble_normal(_x22300, _ctx); /*string*/
  return kk_string_box(_x22299);
}
static kk_box_t kk_std_num_ddouble_pddouble_normal_fun22295(kk_function_t _fself, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_string_t _x22296;
  kk_char_t x2_20709 = kk_std_text_parse_char('.', _ctx); /*char*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x22297 = kk_std_core_hnd_yield_extend(kk_std_num_ddouble_new_pddouble_normal_fun22298(_ctx), _ctx); /*2*/
    _x22296 = kk_string_unbox(_x22297); /*string*/
  }
  else {
    _x22296 = kk_std_num_ddouble__mlift20571_pddouble_normal(x2_20709, _ctx); /*string*/
  }
  return kk_string_box(_x22296);
}


// lift anonymous function
struct kk_std_num_ddouble_pddouble_normal_fun22302__t {
  struct kk_function_s _base;
  kk_string_t x0_20702;
  bool x_20698;
};
static kk_box_t kk_std_num_ddouble_pddouble_normal_fun22302(kk_function_t _fself, kk_box_t _b_21277, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble_new_pddouble_normal_fun22302(kk_string_t x0_20702, bool x_20698, kk_context_t* _ctx) {
  struct kk_std_num_ddouble_pddouble_normal_fun22302__t* _self = kk_function_alloc_as(struct kk_std_num_ddouble_pddouble_normal_fun22302__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_num_ddouble_pddouble_normal_fun22302, kk_context());
  _self->x0_20702 = x0_20702;
  _self->x_20698 = x_20698;
  return &_self->_base;
}

static kk_box_t kk_std_num_ddouble_pddouble_normal_fun22302(kk_function_t _fself, kk_box_t _b_21277, kk_context_t* _ctx) {
  struct kk_std_num_ddouble_pddouble_normal_fun22302__t* _self = kk_function_as(struct kk_std_num_ddouble_pddouble_normal_fun22302__t*, _fself);
  kk_string_t x0_20702 = _self->x0_20702; /* string */
  bool x_20698 = _self->x_20698; /* bool */
  kk_drop_match(_self, {kk_string_dup(x0_20702);;}, {}, _ctx)
  kk_std_num_ddouble__ddouble _x22303;
  kk_string_t _x22304 = kk_string_unbox(_b_21277); /*string*/
  _x22303 = kk_std_num_ddouble__mlift20572_pddouble_normal(x_20698, x0_20702, _x22304, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x22303, _ctx);
}


// lift anonymous function
struct kk_std_num_ddouble_pddouble_normal_fun22308__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_ddouble_pddouble_normal_fun22308(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble_new_pddouble_normal_fun22308(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_ddouble_pddouble_normal_fun22308, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_std_num_ddouble_pddouble_normal_fun22311__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_ddouble_pddouble_normal_fun22311(kk_function_t _fself, kk_box_t _b_21279, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble_new_pddouble_normal_fun22311(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_ddouble_pddouble_normal_fun22311, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_ddouble_pddouble_normal_fun22311(kk_function_t _fself, kk_box_t _b_21279, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_integer_t _x22312;
  kk_char_t _x22313 = kk_char_unbox(_b_21279, _ctx); /*char*/
  _x22312 = kk_std_num_ddouble__mlift20569_pddouble_normal(_x22313, _ctx); /*int*/
  return kk_integer_box(_x22312);
}
static kk_box_t kk_std_num_ddouble_pddouble_normal_fun22308(kk_function_t _fself, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_integer_t _x22309;
  kk_char_t x4_20715 = kk_std_text_parse_char('e', _ctx); /*char*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x22310 = kk_std_core_hnd_yield_extend(kk_std_num_ddouble_new_pddouble_normal_fun22311(_ctx), _ctx); /*2*/
    _x22309 = kk_integer_unbox(_x22310); /*int*/
  }
  else {
    _x22309 = kk_std_num_ddouble__mlift20569_pddouble_normal(x4_20715, _ctx); /*int*/
  }
  return kk_integer_box(_x22309);
}


// lift anonymous function
struct kk_std_num_ddouble_pddouble_normal_fun22315__t {
  struct kk_function_s _base;
  kk_string_t frac;
  kk_string_t x0_20702;
  bool x_20698;
};
static kk_box_t kk_std_num_ddouble_pddouble_normal_fun22315(kk_function_t _fself, kk_box_t _b_21286, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble_new_pddouble_normal_fun22315(kk_string_t frac, kk_string_t x0_20702, bool x_20698, kk_context_t* _ctx) {
  struct kk_std_num_ddouble_pddouble_normal_fun22315__t* _self = kk_function_alloc_as(struct kk_std_num_ddouble_pddouble_normal_fun22315__t, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_num_ddouble_pddouble_normal_fun22315, kk_context());
  _self->frac = frac;
  _self->x0_20702 = x0_20702;
  _self->x_20698 = x_20698;
  return &_self->_base;
}

static kk_box_t kk_std_num_ddouble_pddouble_normal_fun22315(kk_function_t _fself, kk_box_t _b_21286, kk_context_t* _ctx) {
  struct kk_std_num_ddouble_pddouble_normal_fun22315__t* _self = kk_function_as(struct kk_std_num_ddouble_pddouble_normal_fun22315__t*, _fself);
  kk_string_t frac = _self->frac; /* string */
  kk_string_t x0_20702 = _self->x0_20702; /* string */
  bool x_20698 = _self->x_20698; /* bool */
  kk_drop_match(_self, {kk_string_dup(frac);kk_string_dup(x0_20702);;}, {}, _ctx)
  kk_std_num_ddouble__ddouble _x22316;
  kk_integer_t _x22317 = kk_integer_unbox(_b_21286); /*int*/
  _x22316 = kk_std_num_ddouble__mlift20570_pddouble_normal(frac, x_20698, x0_20702, _x22317, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x22316, _ctx);
}


// lift anonymous function
struct kk_std_num_ddouble_pddouble_normal_fun22330__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_ddouble_pddouble_normal_fun22330(kk_function_t _fself, kk_box_t _b_21292, kk_box_t _b_21293, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble_new_pddouble_normal_fun22330(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_ddouble_pddouble_normal_fun22330, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_ddouble_pddouble_normal_fun22330(kk_function_t _fself, kk_box_t _b_21292, kk_box_t _b_21293, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_num_ddouble__ddouble _x22331;
  kk_integer_t _x22332 = kk_integer_unbox(_b_21292); /*int*/
  kk_integer_t _x22333 = kk_integer_unbox(_b_21293); /*int*/
  _x22331 = kk_std_num_ddouble_ddouble_int_exp(_x22332, _x22333, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x22331, _ctx);
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble_pddouble_normal(kk_context_t* _ctx) { /* () -> std/text/parse/parse ddouble */ 
  bool x_20698 = kk_std_text_parse_sign(_ctx); /*bool*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x22283 = kk_std_core_hnd_yield_extend(kk_std_num_ddouble_new_pddouble_normal_fun22284(_ctx), _ctx); /*2*/
    return kk_std_num_ddouble__ddouble_unbox(_x22283, _ctx);
  }
  kk_string_t x0_20702 = kk_std_text_parse_digits(_ctx); /*string*/;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x0_20702, _ctx);
    kk_box_t _x22287 = kk_std_core_hnd_yield_extend(kk_std_num_ddouble_new_pddouble_normal_fun22288(x_20698, _ctx), _ctx); /*2*/
    return kk_std_num_ddouble__ddouble_unbox(_x22287, _ctx);
  }
  kk_string_t x1_20706;
  kk_box_t _x22291;
  kk_box_t _x22292;
  kk_string_t _x22293 = kk_string_empty(); /*string*/
  _x22292 = kk_string_box(_x22293); /*0*/
  _x22291 = kk_std_text_parse_optional(_x22292, kk_std_num_ddouble_new_pddouble_normal_fun22295(_ctx), _ctx); /*0*/
  x1_20706 = kk_string_unbox(_x22291); /*string*/
  if (kk_yielding(kk_context())) {
    kk_string_drop(x1_20706, _ctx);
    kk_box_t _x22301 = kk_std_core_hnd_yield_extend(kk_std_num_ddouble_new_pddouble_normal_fun22302(x0_20702, x_20698, _ctx), _ctx); /*2*/
    return kk_std_num_ddouble__ddouble_unbox(_x22301, _ctx);
  }
  kk_string_t frac;
  kk_string_t _x22305;
  kk_define_string_literal(, _s22306, 1, "0")
  _x22305 = kk_string_dup(_s22306); /*string*/
  frac = kk_std_core_trim_right_1(x1_20706, _x22305, _ctx); /*string*/
  kk_integer_t x3_20712;
  kk_box_t _x22307 = kk_std_text_parse_optional(kk_integer_box(kk_integer_from_small(0)), kk_std_num_ddouble_new_pddouble_normal_fun22308(_ctx), _ctx); /*0*/
  x3_20712 = kk_integer_unbox(_x22307); /*int*/
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x3_20712, _ctx);
    kk_box_t _x22314 = kk_std_core_hnd_yield_extend(kk_std_num_ddouble_new_pddouble_normal_fun22315(frac, x0_20702, x_20698, _ctx), _ctx); /*2*/
    return kk_std_num_ddouble__ddouble_unbox(_x22314, _ctx);
  }
  kk_integer_t w;
  kk_std_core_types__maybe m_20718;
  kk_string_t s_20720;
  kk_string_t _x22318;
  if (x_20698) {
    kk_define_string_literal(, _s22319, 1, "-")
    _x22318 = kk_string_dup(_s22319); /*string*/
  }
  else {
    _x22318 = kk_string_empty(); /*string*/
  }
  kk_string_t _x22321;
  kk_string_t _x22322 = kk_string_dup(frac); /*string*/
  _x22321 = kk_std_core__lp__plus__plus__1_rp_(x0_20702, _x22322, _ctx); /*string*/
  s_20720 = kk_std_core__lp__plus__plus__1_rp_(_x22318, _x22321, _ctx); /*string*/
  kk_string_t _x22323 = kk_std_core_trim(s_20720, _ctx); /*string*/
  bool _x22324;
  kk_std_core_types__optional _match_21953 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
  if (kk_std_core_types__is_Optional(_match_21953)) {
    kk_box_t _box_x21287 = _match_21953._cons.Optional.value;
    bool _hex_19366 = kk_bool_unbox(_box_x21287);
    kk_std_core_types__optional_drop(_match_21953, _ctx);
    _x22324 = _hex_19366; /*bool*/
    goto _match22325;
  }
  _x22324 = false; /*bool*/
  _match22325: ;
  m_20718 = kk_std_core_xparse_int(_x22323, _x22324, _ctx); /*maybe<int>*/
  if (kk_std_core_types__is_Nothing(m_20718)) {
    w = kk_integer_from_small(0); /*int*/
  }
  else {
    kk_box_t _box_x21288 = m_20718._cons.Just.value;
    kk_integer_t x5 = kk_integer_unbox(_box_x21288);
    kk_integer_dup(x5);
    kk_std_core_types__maybe_drop(m_20718, _ctx);
    w = x5; /*int*/
  }
  kk_integer_t e;
  kk_integer_t _x22328 = kk_std_core_count_1(frac, _ctx); /*int*/
  e = kk_integer_sub(x3_20712,_x22328,kk_context()); /*int*/
  kk_box_t _x22329 = kk_std_core_hnd__open_none2(kk_std_num_ddouble_new_pddouble_normal_fun22330(_ctx), kk_integer_box(w), kk_integer_box(e), _ctx); /*3*/
  return kk_std_num_ddouble__ddouble_unbox(_x22329, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_num_ddouble__mlift20575_pddouble_sum_fun22335__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_ddouble__mlift20575_pddouble_sum_fun22335(kk_function_t _fself, kk_box_t _b_21306, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble__new_mlift20575_pddouble_sum_fun22335(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_ddouble__mlift20575_pddouble_sum_fun22335, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_ddouble__mlift20575_pddouble_sum_fun22335(kk_function_t _fself, kk_box_t _b_21306, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_num_ddouble__ddouble _x22336;
  double _x22337 = kk_double_unbox(_b_21306, _ctx); /*double*/
  _x22336 = kk_std_num_ddouble_ddouble(_x22337, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x22336, _ctx);
}


// lift anonymous function
struct kk_std_num_ddouble__mlift20575_pddouble_sum_fun22339__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_ddouble__mlift20575_pddouble_sum_fun22339(kk_function_t _fself, kk_box_t _b_21311, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble__new_mlift20575_pddouble_sum_fun22339(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_ddouble__mlift20575_pddouble_sum_fun22339, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_ddouble__mlift20575_pddouble_sum_fun22339(kk_function_t _fself, kk_box_t _b_21311, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_num_ddouble__ddouble _x22340;
  double _x22341 = kk_double_unbox(_b_21311, _ctx); /*double*/
  _x22340 = kk_std_num_ddouble_ddouble(_x22341, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x22340, _ctx);
}


// lift anonymous function
struct kk_std_num_ddouble__mlift20575_pddouble_sum_fun22343__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_ddouble__mlift20575_pddouble_sum_fun22343(kk_function_t _fself, kk_box_t _b_21317, kk_box_t _b_21318, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble__new_mlift20575_pddouble_sum_fun22343(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_ddouble__mlift20575_pddouble_sum_fun22343, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_ddouble__mlift20575_pddouble_sum_fun22343(kk_function_t _fself, kk_box_t _b_21317, kk_box_t _b_21318, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_num_ddouble__ddouble _x22344;
  kk_std_num_ddouble__ddouble _x22345 = kk_std_num_ddouble__ddouble_unbox(_b_21317, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x22346 = kk_std_num_ddouble__ddouble_unbox(_b_21318, _ctx); /*std/num/ddouble/ddouble*/
  _x22344 = kk_std_num_ddouble__lp__plus__rp_(_x22345, _x22346, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x22344, _ctx);
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble__mlift20575_pddouble_sum(double hi0, double lo0, kk_context_t* _ctx) { /* (hi : double, lo : double) -> std/text/parse/parse ddouble */ 
  kk_std_num_ddouble__ddouble _x10;
  kk_box_t _x22334 = kk_std_core_hnd__open_none1(kk_std_num_ddouble__new_mlift20575_pddouble_sum_fun22335(_ctx), kk_double_box(hi0, _ctx), _ctx); /*2*/
  _x10 = kk_std_num_ddouble__ddouble_unbox(_x22334, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x2;
  kk_box_t _x22338 = kk_std_core_hnd__open_none1(kk_std_num_ddouble__new_mlift20575_pddouble_sum_fun22339(_ctx), kk_double_box(lo0, _ctx), _ctx); /*2*/
  _x2 = kk_std_num_ddouble__ddouble_unbox(_x22338, _ctx); /*std/num/ddouble/ddouble*/
  kk_box_t _x22342 = kk_std_core_hnd__open_none2(kk_std_num_ddouble__new_mlift20575_pddouble_sum_fun22343(_ctx), kk_std_num_ddouble__ddouble_box(_x10, _ctx), kk_std_num_ddouble__ddouble_box(_x2, _ctx), _ctx); /*3*/
  return kk_std_num_ddouble__ddouble_unbox(_x22342, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_num_ddouble__mlift20576_pddouble_sum_fun22348__t {
  struct kk_function_s _base;
  double hi0;
};
static kk_box_t kk_std_num_ddouble__mlift20576_pddouble_sum_fun22348(kk_function_t _fself, kk_box_t _b_21323, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble__new_mlift20576_pddouble_sum_fun22348(double hi0, kk_context_t* _ctx) {
  struct kk_std_num_ddouble__mlift20576_pddouble_sum_fun22348__t* _self = kk_function_alloc_as(struct kk_std_num_ddouble__mlift20576_pddouble_sum_fun22348__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_num_ddouble__mlift20576_pddouble_sum_fun22348, kk_context());
  _self->hi0 = hi0;
  return &_self->_base;
}

static kk_box_t kk_std_num_ddouble__mlift20576_pddouble_sum_fun22348(kk_function_t _fself, kk_box_t _b_21323, kk_context_t* _ctx) {
  struct kk_std_num_ddouble__mlift20576_pddouble_sum_fun22348__t* _self = kk_function_as(struct kk_std_num_ddouble__mlift20576_pddouble_sum_fun22348__t*, _fself);
  double hi0 = _self->hi0; /* double */
  kk_drop_match(_self, {;}, {}, _ctx)
  kk_std_num_ddouble__ddouble _x22349;
  double _x22350 = kk_double_unbox(_b_21323, _ctx); /*double*/
  _x22349 = kk_std_num_ddouble__mlift20575_pddouble_sum(hi0, _x22350, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x22349, _ctx);
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble__mlift20576_pddouble_sum(double hi0, kk_string_t wild__0, kk_context_t* _ctx) { /* (hi : double, wild_0 : string) -> std/text/parse/parse ddouble */ 
  kk_string_drop(wild__0, _ctx);
  double x_20722 = kk_std_num_double_pdouble(_ctx); /*double*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x22347 = kk_std_core_hnd_yield_extend(kk_std_num_ddouble__new_mlift20576_pddouble_sum_fun22348(hi0, _ctx), _ctx); /*2*/
    return kk_std_num_ddouble__ddouble_unbox(_x22347, _ctx);
  }
  return kk_std_num_ddouble__mlift20575_pddouble_sum(hi0, x_20722, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_num_ddouble__mlift20577_pddouble_sum_fun22353__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_ddouble__mlift20577_pddouble_sum_fun22353(kk_function_t _fself, kk_box_t _b_21328, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble__new_mlift20577_pddouble_sum_fun22353(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_ddouble__mlift20577_pddouble_sum_fun22353, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_ddouble__mlift20577_pddouble_sum_fun22353(kk_function_t _fself, kk_box_t _b_21328, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_num_ddouble__ddouble _x22354;
  double _x22355 = kk_double_unbox(_b_21328, _ctx); /*double*/
  _x22354 = kk_std_num_ddouble_ddouble(_x22355, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x22354, _ctx);
}


// lift anonymous function
struct kk_std_num_ddouble__mlift20577_pddouble_sum_fun22359__t {
  struct kk_function_s _base;
  double hi0;
};
static kk_box_t kk_std_num_ddouble__mlift20577_pddouble_sum_fun22359(kk_function_t _fself, kk_box_t _b_21330, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble__new_mlift20577_pddouble_sum_fun22359(double hi0, kk_context_t* _ctx) {
  struct kk_std_num_ddouble__mlift20577_pddouble_sum_fun22359__t* _self = kk_function_alloc_as(struct kk_std_num_ddouble__mlift20577_pddouble_sum_fun22359__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_num_ddouble__mlift20577_pddouble_sum_fun22359, kk_context());
  _self->hi0 = hi0;
  return &_self->_base;
}

static kk_box_t kk_std_num_ddouble__mlift20577_pddouble_sum_fun22359(kk_function_t _fself, kk_box_t _b_21330, kk_context_t* _ctx) {
  struct kk_std_num_ddouble__mlift20577_pddouble_sum_fun22359__t* _self = kk_function_as(struct kk_std_num_ddouble__mlift20577_pddouble_sum_fun22359__t*, _fself);
  double hi0 = _self->hi0; /* double */
  kk_drop_match(_self, {;}, {}, _ctx)
  kk_std_num_ddouble__ddouble _x22360;
  kk_string_t _x22361 = kk_string_unbox(_b_21330); /*string*/
  _x22360 = kk_std_num_ddouble__mlift20576_pddouble_sum(hi0, _x22361, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x22360, _ctx);
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble__mlift20577_pddouble_sum(double hi0, kk_context_t* _ctx) { /* (hi : double) -> std/text/parse/parse ddouble */ 
  bool _match_21946;
  bool _x22351 = isfinite(hi0); /*bool*/
  _match_21946 = !(_x22351); /*bool*/
  if (_match_21946) {
    kk_box_t _x22352 = kk_std_core_hnd__open_none1(kk_std_num_ddouble__new_mlift20577_pddouble_sum_fun22353(_ctx), kk_double_box(hi0, _ctx), _ctx); /*2*/
    return kk_std_num_ddouble__ddouble_unbox(_x22352, _ctx);
  }
  kk_string_t x_20724;
  kk_string_t _x22356;
  kk_define_string_literal(, _s22357, 3, " + ")
  _x22356 = kk_string_dup(_s22357); /*string*/
  x_20724 = kk_std_text_parse_pstring(_x22356, _ctx); /*string*/
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_20724, _ctx);
    kk_box_t _x22358 = kk_std_core_hnd_yield_extend(kk_std_num_ddouble__new_mlift20577_pddouble_sum_fun22359(hi0, _ctx), _ctx); /*2*/
    return kk_std_num_ddouble__ddouble_unbox(_x22358, _ctx);
  }
  return kk_std_num_ddouble__mlift20576_pddouble_sum(hi0, x_20724, _ctx);
}


// lift anonymous function
struct kk_std_num_ddouble_pddouble_sum_fun22363__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_ddouble_pddouble_sum_fun22363(kk_function_t _fself, kk_box_t _b_21336, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble_new_pddouble_sum_fun22363(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_ddouble_pddouble_sum_fun22363, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_ddouble_pddouble_sum_fun22363(kk_function_t _fself, kk_box_t _b_21336, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_num_ddouble__ddouble _x22364;
  double _x22365 = kk_double_unbox(_b_21336, _ctx); /*double*/
  _x22364 = kk_std_num_ddouble__mlift20577_pddouble_sum(_x22365, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x22364, _ctx);
}


// lift anonymous function
struct kk_std_num_ddouble_pddouble_sum_fun22368__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_ddouble_pddouble_sum_fun22368(kk_function_t _fself, kk_box_t _b_21339, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble_new_pddouble_sum_fun22368(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_ddouble_pddouble_sum_fun22368, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_ddouble_pddouble_sum_fun22368(kk_function_t _fself, kk_box_t _b_21339, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_num_ddouble__ddouble _x22369;
  double _x22370 = kk_double_unbox(_b_21339, _ctx); /*double*/
  _x22369 = kk_std_num_ddouble_ddouble(_x22370, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x22369, _ctx);
}


// lift anonymous function
struct kk_std_num_ddouble_pddouble_sum_fun22374__t {
  struct kk_function_s _base;
  double x_20726;
};
static kk_box_t kk_std_num_ddouble_pddouble_sum_fun22374(kk_function_t _fself, kk_box_t _b_21341, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble_new_pddouble_sum_fun22374(double x_20726, kk_context_t* _ctx) {
  struct kk_std_num_ddouble_pddouble_sum_fun22374__t* _self = kk_function_alloc_as(struct kk_std_num_ddouble_pddouble_sum_fun22374__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_num_ddouble_pddouble_sum_fun22374, kk_context());
  _self->x_20726 = x_20726;
  return &_self->_base;
}

static kk_box_t kk_std_num_ddouble_pddouble_sum_fun22374(kk_function_t _fself, kk_box_t _b_21341, kk_context_t* _ctx) {
  struct kk_std_num_ddouble_pddouble_sum_fun22374__t* _self = kk_function_as(struct kk_std_num_ddouble_pddouble_sum_fun22374__t*, _fself);
  double x_20726 = _self->x_20726; /* double */
  kk_drop_match(_self, {;}, {}, _ctx)
  kk_std_num_ddouble__ddouble _x22375;
  kk_string_t _x22376 = kk_string_unbox(_b_21341); /*string*/
  _x22375 = kk_std_num_ddouble__mlift20576_pddouble_sum(x_20726, _x22376, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x22375, _ctx);
}


// lift anonymous function
struct kk_std_num_ddouble_pddouble_sum_fun22378__t {
  struct kk_function_s _base;
  double x_20726;
};
static kk_box_t kk_std_num_ddouble_pddouble_sum_fun22378(kk_function_t _fself, kk_box_t _b_21343, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble_new_pddouble_sum_fun22378(double x_20726, kk_context_t* _ctx) {
  struct kk_std_num_ddouble_pddouble_sum_fun22378__t* _self = kk_function_alloc_as(struct kk_std_num_ddouble_pddouble_sum_fun22378__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_num_ddouble_pddouble_sum_fun22378, kk_context());
  _self->x_20726 = x_20726;
  return &_self->_base;
}

static kk_box_t kk_std_num_ddouble_pddouble_sum_fun22378(kk_function_t _fself, kk_box_t _b_21343, kk_context_t* _ctx) {
  struct kk_std_num_ddouble_pddouble_sum_fun22378__t* _self = kk_function_as(struct kk_std_num_ddouble_pddouble_sum_fun22378__t*, _fself);
  double x_20726 = _self->x_20726; /* double */
  kk_drop_match(_self, {;}, {}, _ctx)
  kk_std_num_ddouble__ddouble _x22379;
  double _x22380 = kk_double_unbox(_b_21343, _ctx); /*double*/
  _x22379 = kk_std_num_ddouble__mlift20575_pddouble_sum(x_20726, _x22380, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x22379, _ctx);
}


// lift anonymous function
struct kk_std_num_ddouble_pddouble_sum_fun22382__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_ddouble_pddouble_sum_fun22382(kk_function_t _fself, kk_box_t _b_21346, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble_new_pddouble_sum_fun22382(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_ddouble_pddouble_sum_fun22382, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_ddouble_pddouble_sum_fun22382(kk_function_t _fself, kk_box_t _b_21346, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_num_ddouble__ddouble _x22383;
  double _x22384 = kk_double_unbox(_b_21346, _ctx); /*double*/
  _x22383 = kk_std_num_ddouble_ddouble(_x22384, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x22383, _ctx);
}


// lift anonymous function
struct kk_std_num_ddouble_pddouble_sum_fun22386__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_ddouble_pddouble_sum_fun22386(kk_function_t _fself, kk_box_t _b_21351, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble_new_pddouble_sum_fun22386(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_ddouble_pddouble_sum_fun22386, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_ddouble_pddouble_sum_fun22386(kk_function_t _fself, kk_box_t _b_21351, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_num_ddouble__ddouble _x22387;
  double _x22388 = kk_double_unbox(_b_21351, _ctx); /*double*/
  _x22387 = kk_std_num_ddouble_ddouble(_x22388, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x22387, _ctx);
}


// lift anonymous function
struct kk_std_num_ddouble_pddouble_sum_fun22390__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_ddouble_pddouble_sum_fun22390(kk_function_t _fself, kk_box_t _b_21357, kk_box_t _b_21358, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble_new_pddouble_sum_fun22390(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_ddouble_pddouble_sum_fun22390, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_ddouble_pddouble_sum_fun22390(kk_function_t _fself, kk_box_t _b_21357, kk_box_t _b_21358, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_num_ddouble__ddouble _x22391;
  kk_std_num_ddouble__ddouble _x22392 = kk_std_num_ddouble__ddouble_unbox(_b_21357, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x22393 = kk_std_num_ddouble__ddouble_unbox(_b_21358, _ctx); /*std/num/ddouble/ddouble*/
  _x22391 = kk_std_num_ddouble__lp__plus__rp_(_x22392, _x22393, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x22391, _ctx);
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble_pddouble_sum(kk_context_t* _ctx) { /* () -> std/text/parse/parse ddouble */ 
  double x_20726 = kk_std_num_double_pdouble(_ctx); /*double*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x22362 = kk_std_core_hnd_yield_extend(kk_std_num_ddouble_new_pddouble_sum_fun22363(_ctx), _ctx); /*2*/
    return kk_std_num_ddouble__ddouble_unbox(_x22362, _ctx);
  }
  bool _match_21943;
  bool _x22366 = isfinite(x_20726); /*bool*/
  _match_21943 = !(_x22366); /*bool*/
  if (_match_21943) {
    kk_box_t _x22367 = kk_std_core_hnd__open_none1(kk_std_num_ddouble_new_pddouble_sum_fun22368(_ctx), kk_double_box(x_20726, _ctx), _ctx); /*2*/
    return kk_std_num_ddouble__ddouble_unbox(_x22367, _ctx);
  }
  kk_string_t x0_20730;
  kk_string_t _x22371;
  kk_define_string_literal(, _s22372, 3, " + ")
  _x22371 = kk_string_dup(_s22372); /*string*/
  x0_20730 = kk_std_text_parse_pstring(_x22371, _ctx); /*string*/
  kk_string_drop(x0_20730, _ctx);
  if (kk_yielding(kk_context())) {
    kk_box_t _x22373 = kk_std_core_hnd_yield_extend(kk_std_num_ddouble_new_pddouble_sum_fun22374(x_20726, _ctx), _ctx); /*2*/
    return kk_std_num_ddouble__ddouble_unbox(_x22373, _ctx);
  }
  double x1_20734 = kk_std_num_double_pdouble(_ctx); /*double*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x22377 = kk_std_core_hnd_yield_extend(kk_std_num_ddouble_new_pddouble_sum_fun22378(x_20726, _ctx), _ctx); /*2*/
    return kk_std_num_ddouble__ddouble_unbox(_x22377, _ctx);
  }
  kk_std_num_ddouble__ddouble _x10;
  kk_box_t _x22381 = kk_std_core_hnd__open_none1(kk_std_num_ddouble_new_pddouble_sum_fun22382(_ctx), kk_double_box(x_20726, _ctx), _ctx); /*2*/
  _x10 = kk_std_num_ddouble__ddouble_unbox(_x22381, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x2;
  kk_box_t _x22385 = kk_std_core_hnd__open_none1(kk_std_num_ddouble_new_pddouble_sum_fun22386(_ctx), kk_double_box(x1_20734, _ctx), _ctx); /*2*/
  _x2 = kk_std_num_ddouble__ddouble_unbox(_x22385, _ctx); /*std/num/ddouble/ddouble*/
  kk_box_t _x22389 = kk_std_core_hnd__open_none2(kk_std_num_ddouble_new_pddouble_sum_fun22390(_ctx), kk_std_num_ddouble__ddouble_box(_x10, _ctx), kk_std_num_ddouble__ddouble_box(_x2, _ctx), _ctx); /*3*/
  return kk_std_num_ddouble__ddouble_unbox(_x22389, _ctx);
}


// lift anonymous function
struct kk_std_num_ddouble_pddouble_fun22395__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_ddouble_pddouble_fun22395(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble_new_pddouble_fun22395(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_ddouble_pddouble_fun22395, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_ddouble_pddouble_fun22395(kk_function_t _fself, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_num_ddouble__ddouble _x22396 = kk_std_num_ddouble_pddouble_sum(_ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x22396, _ctx);
}


// lift anonymous function
struct kk_std_num_ddouble_pddouble_fun22397__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_ddouble_pddouble_fun22397(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble_new_pddouble_fun22397(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_ddouble_pddouble_fun22397, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_ddouble_pddouble_fun22397(kk_function_t _fself, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_num_ddouble__ddouble _x22398 = kk_std_num_ddouble_pddouble_normal(_ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x22398, _ctx);
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble_pddouble(kk_context_t* _ctx) { /* () -> std/text/parse/parse ddouble */ 
  kk_box_t _x22394 = kk_std_text_parse__lp__bar__bar__rp_(kk_std_num_ddouble_new_pddouble_fun22395(_ctx), kk_std_num_ddouble_new_pddouble_fun22397(_ctx), _ctx); /*0*/
  return kk_std_num_ddouble__ddouble_unbox(_x22394, _ctx);
}


// lift anonymous function
struct kk_std_num_ddouble_parse_ddouble_fun22403__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_ddouble_parse_ddouble_fun22403(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble_new_parse_ddouble_fun22403(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_ddouble_parse_ddouble_fun22403, _ctx)
  return kk_function_dup(_fself);
}



// lift anonymous function
struct kk_std_num_ddouble_parse_ddouble_fun22406__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_ddouble_parse_ddouble_fun22406(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble_new_parse_ddouble_fun22406(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_ddouble_parse_ddouble_fun22406, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_ddouble_parse_ddouble_fun22406(kk_function_t _fself, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_num_ddouble__ddouble _x22407 = kk_std_num_ddouble_pddouble_sum(_ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x22407, _ctx);
}


// lift anonymous function
struct kk_std_num_ddouble_parse_ddouble_fun22408__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_ddouble_parse_ddouble_fun22408(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble_new_parse_ddouble_fun22408(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_ddouble_parse_ddouble_fun22408, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_ddouble_parse_ddouble_fun22408(kk_function_t _fself, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_num_ddouble__ddouble _x22409 = kk_std_num_ddouble_pddouble_normal(_ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x22409, _ctx);
}


// lift anonymous function
struct kk_std_num_ddouble_parse_ddouble_fun22412__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_ddouble_parse_ddouble_fun22412(kk_function_t _fself, kk_box_t _x122411, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble_new_parse_ddouble_fun22412(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_ddouble_parse_ddouble_fun22412, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_ddouble_parse_ddouble_fun22412(kk_function_t _fself, kk_box_t _x122411, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  return kk_std_text_parse__mlift2565_parse_eof(_x122411, _ctx);
}
static kk_box_t kk_std_num_ddouble_parse_ddouble_fun22403(kk_function_t _fself, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_num_ddouble__ddouble _x22404;
  kk_std_num_ddouble__ddouble x_2790;
  kk_box_t _x22405 = kk_std_text_parse__lp__bar__bar__rp_(kk_std_num_ddouble_new_parse_ddouble_fun22406(_ctx), kk_std_num_ddouble_new_parse_ddouble_fun22408(_ctx), _ctx); /*0*/
  x_2790 = kk_std_num_ddouble__ddouble_unbox(_x22405, _ctx); /*std/num/ddouble/ddouble*/
  kk_box_t _x22410;
  if (kk_yielding(kk_context())) {
    _x22410 = kk_std_core_hnd_yield_extend(kk_std_num_ddouble_new_parse_ddouble_fun22412(_ctx), _ctx); /*2*/
  }
  else {
    _x22410 = kk_std_text_parse__mlift2565_parse_eof(kk_std_num_ddouble__ddouble_box(x_2790, _ctx), _ctx); /*2*/
  }
  _x22404 = kk_std_num_ddouble__ddouble_unbox(_x22410, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x22404, _ctx);
}

kk_std_core_types__maybe kk_std_num_ddouble_parse_ddouble(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> maybe<ddouble> */ 
  kk_std_text_parse__parse_error perr_20738;
  kk_std_core__sslice input_20739;
  kk_string_t s0_20741;
  kk_string_t _x22399 = kk_std_core_trim(s, _ctx); /*string*/
  s0_20741 = kk_std_core_to_lower(_x22399, _ctx); /*string*/
  kk_string_t _x22400 = kk_string_dup(s0_20741); /*string*/
  size_t _x22401 = ((size_t)0); /*size_t*/
  size_t _x22402 = kk_string_len(s0_20741,kk_context()); /*size_t*/
  input_20739 = kk_std_core__new_Sslice(_x22400, _x22401, _x22402, _ctx); /*sslice*/
  perr_20738 = kk_std_text_parse_parse(input_20739, kk_std_num_ddouble_new_parse_ddouble_fun22403(_ctx), _ctx); /*std/text/parse/parse-error<std/num/ddouble/ddouble>*/
  kk_std_core_types__either e_2721 = kk_std_text_parse_either(perr_20738, _ctx); /*either<string,std/num/ddouble/ddouble>*/;
  if (kk_std_core_types__is_Left(e_2721)) {
    kk_box_t _box_x21389 = e_2721._cons.Left.left;
    kk_std_core_types__either_drop(e_2721, _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
  kk_box_t _box_x21390 = e_2721._cons.Right.right;
  kk_std_num_ddouble__ddouble x = kk_std_num_ddouble__ddouble_unbox(_box_x21390, NULL);
  kk_std_core_types__either_drop(e_2721, _ctx);
  return kk_std_core_types__new_Just(kk_std_num_ddouble__ddouble_box(x, _ctx), _ctx);
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble_zero;
 
// Return the sum of a list of doubles.
// Uses [Kahan-Babu&scaron;kan-Neumaier summation](https://en.wikipedia.org/wiki/Kahan_summation_algorithm#Further_enhancements)
// to minimize rounding errors. This
// is more precise as Kahan summation and about as fast.
// `[1.0e3,1.0e97,1.0e3,-1.0e97].sum == 2000.0`
// A. Neumaier, _Rundungsfehleranalyse einiger Verfahren zur Summation endlicher Summen_.
// Math. Mechanik, 54:39--51, 1974.


// lift anonymous function
struct kk_std_num_ddouble_sum_fun22418__t_1 {
  struct kk_function_s _base;
  kk_ref_t loc;
  kk_ref_t loc0;
};
static kk_unit_t kk_std_num_ddouble_sum_fun22418_1(kk_function_t _fself, kk_box_t _b_21416, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble_new_sum_fun22418_1(kk_ref_t loc, kk_ref_t loc0, kk_context_t* _ctx) {
  struct kk_std_num_ddouble_sum_fun22418__t_1* _self = kk_function_alloc_as(struct kk_std_num_ddouble_sum_fun22418__t_1, 3, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_num_ddouble_sum_fun22418_1, kk_context());
  _self->loc = loc;
  _self->loc0 = loc0;
  return &_self->_base;
}

static kk_unit_t kk_std_num_ddouble_sum_fun22418_1(kk_function_t _fself, kk_box_t _b_21416, kk_context_t* _ctx) {
  struct kk_std_num_ddouble_sum_fun22418__t_1* _self = kk_function_as(struct kk_std_num_ddouble_sum_fun22418__t_1*, _fself);
  kk_ref_t loc = _self->loc; /* local-var<global,std/num/ddouble/ddouble> */
  kk_ref_t loc0 = _self->loc0; /* local-var<global,std/num/ddouble/ddouble> */
  kk_drop_match(_self, {kk_ref_dup(loc);kk_ref_dup(loc0);}, {}, _ctx)
  kk_std_num_ddouble__ddouble t;
  kk_std_num_ddouble__ddouble _x22419;
  kk_box_t _x22420;
  kk_ref_t _x22421 = kk_ref_dup(loc); /*local-var<global,std/num/ddouble/ddouble>*/
  _x22420 = (kk_ref_get(_x22421,kk_context())); /*0*/
  _x22419 = kk_std_num_ddouble__ddouble_unbox(_x22420, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x22422;
  kk_box_t _x22423 = kk_box_dup(_b_21416); /*1*/
  _x22422 = kk_std_num_ddouble__ddouble_unbox(_x22423, _ctx); /*std/num/ddouble/ddouble*/
  t = kk_std_num_ddouble__lp__plus__rp_(_x22419, _x22422, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble c;
  bool _match_21938;
  kk_std_num_ddouble__ddouble x0_20752;
  kk_std_num_ddouble__ddouble x2_20754;
  kk_box_t _x22424;
  kk_ref_t _x22425 = kk_ref_dup(loc); /*local-var<global,std/num/ddouble/ddouble>*/
  _x22424 = (kk_ref_get(_x22425,kk_context())); /*0*/
  x2_20754 = kk_std_num_ddouble__ddouble_unbox(_x22424, _ctx); /*std/num/ddouble/ddouble*/
  bool _match_21940 = kk_std_num_ddouble_is_neg(x2_20754, _ctx); /*bool*/;
  if (_match_21940) {
    x0_20752 = kk_std_num_ddouble__lp__tilde__rp_(x2_20754, _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    x0_20752 = x2_20754; /*std/num/ddouble/ddouble*/
  }
  kk_std_num_ddouble__ddouble y_20753;
  kk_std_num_ddouble__ddouble _x22426;
  kk_box_t _x22427 = kk_box_dup(_b_21416); /*1*/
  _x22426 = kk_std_num_ddouble__ddouble_unbox(_x22427, _ctx); /*std/num/ddouble/ddouble*/
  y_20753 = kk_std_num_ddouble_abs(_x22426, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_core_types__order x1_20755 = kk_std_num_ddouble_compare(x0_20752, y_20753, _ctx); /*order*/;
  kk_integer_t _x22428 = kk_std_core_int_5(x1_20755, _ctx); /*int*/
  kk_integer_t _x22429;
  kk_std_core_types__order _x22430 = kk_std_core_types__new_Lt(_ctx); /*order*/
  if (kk_std_core_types__is_Lt(_x22430)) {
    _x22429 = kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context()); /*int*/
    goto _match22431;
  }
  if (kk_std_core_types__is_Eq(_x22430)) {
    _x22429 = kk_integer_from_small(0); /*int*/
    goto _match22431;
  }
  _x22429 = kk_integer_from_small(1); /*int*/
  _match22431: ;
  _match_21938 = kk_integer_neq(_x22428,_x22429,kk_context()); /*bool*/
  if (_match_21938) {
    kk_std_num_ddouble__ddouble _x22432;
    kk_std_num_ddouble__ddouble x3_20757;
    kk_box_t _x22433;
    kk_ref_t _x22434 = kk_ref_dup(loc); /*local-var<global,std/num/ddouble/ddouble>*/
    _x22433 = (kk_ref_get(_x22434,kk_context())); /*0*/
    x3_20757 = kk_std_num_ddouble__ddouble_unbox(_x22433, _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble _x22435 = kk_std_num_ddouble__lp__tilde__rp_(t, _ctx); /*std/num/ddouble/ddouble*/
    _x22432 = kk_std_num_ddouble__lp__plus__rp_(x3_20757, _x22435, _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble _x22436 = kk_std_num_ddouble__ddouble_unbox(_b_21416, _ctx); /*std/num/ddouble/ddouble*/
    c = kk_std_num_ddouble__lp__plus__rp_(_x22432, _x22436, _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    kk_std_num_ddouble__ddouble _x22437;
    kk_std_num_ddouble__ddouble _x22438 = kk_std_num_ddouble__ddouble_unbox(_b_21416, _ctx); /*std/num/ddouble/ddouble*/
    _x22437 = kk_std_num_ddouble__lp__dash__rp_(_x22438, t, _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble _x22439;
    kk_box_t _x22440;
    kk_ref_t _x22441 = kk_ref_dup(loc); /*local-var<global,std/num/ddouble/ddouble>*/
    _x22440 = (kk_ref_get(_x22441,kk_context())); /*0*/
    _x22439 = kk_std_num_ddouble__ddouble_unbox(_x22440, _ctx); /*std/num/ddouble/ddouble*/
    c = kk_std_num_ddouble__lp__plus__rp_(_x22437, _x22439, _ctx); /*std/num/ddouble/ddouble*/
  }
  kk_unit_t __ = kk_Unit;
  kk_std_num_ddouble__ddouble _b_21410_21408;
  kk_std_num_ddouble__ddouble _x22442;
  kk_box_t _x22443;
  kk_ref_t _x22444 = kk_ref_dup(loc0); /*local-var<global,std/num/ddouble/ddouble>*/
  _x22443 = (kk_ref_get(_x22444,kk_context())); /*0*/
  _x22442 = kk_std_num_ddouble__ddouble_unbox(_x22443, _ctx); /*std/num/ddouble/ddouble*/
  _b_21410_21408 = kk_std_num_ddouble__lp__plus__rp_(_x22442, c, _ctx); /*std/num/ddouble/ddouble*/
  (kk_ref_set(loc0,(kk_std_num_ddouble__ddouble_box(_b_21410_21408, _ctx)),kk_context()));
  return (kk_ref_set(loc,(kk_std_num_ddouble__ddouble_box(t, _ctx)),kk_context()));
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble_sum_1(kk_std_core__list xs, kk_context_t* _ctx) { /* (xs : list<ddouble>) -> ddouble */ 
  kk_ref_t loc;
  kk_std_num_ddouble__ddouble _b_21395_21394 = kk_std_num_ddouble__new_Ddouble(0x0p+0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/;
  loc = kk_ref_alloc((kk_std_num_ddouble__ddouble_box(_b_21395_21394, _ctx)),kk_context()); /*local-var<global,std/num/ddouble/ddouble>*/
  kk_std_num_ddouble__ddouble res;
  kk_ref_t loc0;
  kk_std_num_ddouble__ddouble _b_21397_21396 = kk_std_num_ddouble__new_Ddouble(0x0p+0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/;
  loc0 = kk_ref_alloc((kk_std_num_ddouble__ddouble_box(_b_21397_21396, _ctx)),kk_context()); /*local-var<global,std/num/ddouble/ddouble>*/
  kk_std_num_ddouble__ddouble res0;
  kk_unit_t __0 = kk_Unit;
  kk_function_t _x22417;
  kk_ref_dup(loc);
  kk_ref_dup(loc0);
  _x22417 = kk_std_num_ddouble_new_sum_fun22418_1(loc, loc0, _ctx); /*(1) -> 2 ()*/
  kk_std_core_foreach(xs, _x22417, _ctx);
  kk_std_num_ddouble__ddouble _x22445;
  kk_box_t _x22446;
  kk_ref_t _x22447 = kk_ref_dup(loc); /*local-var<global,std/num/ddouble/ddouble>*/
  _x22446 = (kk_ref_get(_x22447,kk_context())); /*0*/
  _x22445 = kk_std_num_ddouble__ddouble_unbox(_x22446, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x22448;
  kk_box_t _x22449;
  kk_ref_t _x22450 = kk_ref_dup(loc0); /*local-var<global,std/num/ddouble/ddouble>*/
  _x22449 = (kk_ref_get(_x22450,kk_context())); /*0*/
  _x22448 = kk_std_num_ddouble__ddouble_unbox(_x22449, _ctx); /*std/num/ddouble/ddouble*/
  res0 = kk_std_num_ddouble__lp__plus__rp_(_x22445, _x22448, _ctx); /*std/num/ddouble/ddouble*/
  kk_box_t _x22451 = kk_std_core_hnd_prompt_local_var(loc0, kk_std_num_ddouble__ddouble_box(res0, _ctx), _ctx); /*2*/
  res = kk_std_num_ddouble__ddouble_unbox(_x22451, _ctx); /*std/num/ddouble/ddouble*/
  kk_box_t _x22452 = kk_std_core_hnd_prompt_local_var(loc, kk_std_num_ddouble__ddouble_box(res, _ctx), _ctx); /*2*/
  return kk_std_num_ddouble__ddouble_unbox(_x22452, _ctx);
}
 
// Round a `:ddouble` to the nearest integer, rounding to the nearest even number in case of a tie.

kk_std_num_ddouble__ddouble kk_std_num_ddouble_round(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> ddouble */ 
  double r;
  double _x22454;
  double _x = x.hi;
  _x22454 = _x; /*double*/
  r = round(_x22454); /*double*/
  double diff;
  double _x22455;
  double _x0 = x.hi;
  _x22455 = _x0; /*double*/
  diff = (r - _x22455); /*double*/
  bool _match_21931 = (diff == (0x0p+0)); /*bool*/;
  if (_match_21931) {
    double y_20764;
    double _x22456;
    double _x1 = x.lo;
    _x22456 = _x1; /*double*/
    y_20764 = round(_x22456); /*double*/
    bool _match_21936;
    bool _x22457 = isfinite(r); /*bool*/
    _match_21936 = !(_x22457); /*bool*/
    if (_match_21936) {
      return kk_std_num_ddouble_ddouble(r, _ctx);
    }
    double z = (r + y_20764); /*double*/;
    double err0;
    double _x22458 = (z - r); /*double*/
    err0 = (y_20764 - _x22458); /*double*/
    double _x22459;
    bool _match_21937 = isfinite(z); /*bool*/;
    if (_match_21937) {
      _x22459 = err0; /*double*/
    }
    else {
      _x22459 = z; /*double*/
    }
    return kk_std_num_ddouble__new_Ddouble(z, _x22459, _ctx);
  }
  double d_20766;
  bool _match_21932;
  bool _match_21935 = (diff == (0x1p-1)); /*bool*/;
  if (_match_21935) {
    double _x22460;
    double _x2 = x.lo;
    _x22460 = _x2; /*double*/
    _match_21932 = (_x22460 < (0x0p+0)); /*bool*/
  }
  else {
    _match_21932 = false; /*bool*/
  }
  if (_match_21932) {
    d_20766 = (r - 0x1p0); /*double*/
  }
  else {
    bool _match_21933;
    bool _match_21934 = (diff == (-0x1p-1)); /*bool*/;
    if (_match_21934) {
      double _x22461;
      double _x3 = x.lo;
      _x22461 = _x3; /*double*/
      _match_21933 = (_x22461 > (0x0p+0)); /*bool*/
    }
    else {
      _match_21933 = false; /*bool*/
    }
    if (_match_21933) {
      d_20766 = (r + 0x1p0); /*double*/
    }
    else {
      d_20766 = r; /*double*/
    }
  }
  return kk_std_num_ddouble__new_Ddouble(d_20766, 0x0p+0, _ctx);
}

bool kk_std_num_ddouble__lp__lt__rp_(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_context_t* _ctx) { /* (x : ddouble, y : ddouble) -> bool */ 
  kk_std_core_types__order x0_20773 = kk_std_num_ddouble_compare(x, y, _ctx); /*order*/;
  kk_integer_t _x22464 = kk_std_core_int_5(x0_20773, _ctx); /*int*/
  kk_integer_t _x22465;
  kk_std_core_types__order _x22466 = kk_std_core_types__new_Lt(_ctx); /*order*/
  if (kk_std_core_types__is_Lt(_x22466)) {
    _x22465 = kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context()); /*int*/
    goto _match22467;
  }
  if (kk_std_core_types__is_Eq(_x22466)) {
    _x22465 = kk_integer_from_small(0); /*int*/
    goto _match22467;
  }
  _x22465 = kk_integer_from_small(1); /*int*/
  _match22467: ;
  return kk_integer_eq(_x22464,_x22465,kk_context());
}

bool kk_std_num_ddouble__lp__gt__rp_(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_context_t* _ctx) { /* (x : ddouble, y : ddouble) -> bool */ 
  kk_std_core_types__order x0_20775 = kk_std_num_ddouble_compare(x, y, _ctx); /*order*/;
  kk_integer_t _x22468 = kk_std_core_int_5(x0_20775, _ctx); /*int*/
  kk_integer_t _x22469;
  kk_std_core_types__order _x22470 = kk_std_core_types__new_Gt(_ctx); /*order*/
  if (kk_std_core_types__is_Lt(_x22470)) {
    _x22469 = kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context()); /*int*/
    goto _match22471;
  }
  if (kk_std_core_types__is_Eq(_x22470)) {
    _x22469 = kk_integer_from_small(0); /*int*/
    goto _match22471;
  }
  _x22469 = kk_integer_from_small(1); /*int*/
  _match22471: ;
  return kk_integer_eq(_x22468,_x22469,kk_context());
}
 
// The maximum of a list of absolute values.


// lift anonymous function
struct kk_std_num_ddouble_abs_max_fun22473__t_1 {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_ddouble_abs_max_fun22473_1(kk_function_t _fself, kk_box_t _b_21437, kk_box_t _b_21438, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble_new_abs_max_fun22473_1(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_ddouble_abs_max_fun22473_1, _ctx)
  return kk_function_dup(_fself);
}

static kk_box_t kk_std_num_ddouble_abs_max_fun22473_1(kk_function_t _fself, kk_box_t _b_21437, kk_box_t _b_21438, kk_context_t* _ctx) {
  KK_UNUSED(_fself);
  kk_std_num_ddouble__ddouble _x22474;
  kk_std_num_ddouble__ddouble x1_20784;
  kk_std_num_ddouble__ddouble _x22475 = kk_std_num_ddouble__ddouble_unbox(_b_21438, _ctx); /*std/num/ddouble/ddouble*/
  x1_20784 = kk_std_num_ddouble_abs(_x22475, _ctx); /*std/num/ddouble/ddouble*/
  bool _match_21926;
  kk_std_num_ddouble__ddouble _x22476;
  kk_box_t _x22477 = kk_box_dup(_b_21437); /*2*/
  _x22476 = kk_std_num_ddouble__ddouble_unbox(_x22477, _ctx); /*std/num/ddouble/ddouble*/
  _match_21926 = kk_std_num_ddouble__lp__gt__eq__rp_(x1_20784, _x22476, _ctx); /*bool*/
  if (_match_21926) {
    kk_box_drop(_b_21437, _ctx);
    _x22474 = x1_20784; /*std/num/ddouble/ddouble*/
  }
  else {
    _x22474 = kk_std_num_ddouble__ddouble_unbox(_b_21437, _ctx); /*std/num/ddouble/ddouble*/
  }
  return kk_std_num_ddouble__ddouble_box(_x22474, _ctx);
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble_abs_max_1(kk_std_core__list xs, kk_context_t* _ctx) { /* (xs : list<ddouble>) -> ddouble */ 
  kk_std_core__list _b_21439_21434 = kk_std_core_reverse(xs, _ctx); /*list<std/num/ddouble/ddouble>*/;
  kk_std_num_ddouble__ddouble _b_21440_21435 = kk_std_num_ddouble__new_Ddouble(0x0p+0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/;
  kk_box_t _x22472 = kk_std_core_foldl(_b_21439_21434, kk_std_num_ddouble__ddouble_box(_b_21440_21435, _ctx), kk_std_num_ddouble_new_abs_max_fun22473_1(_ctx), _ctx); /*2*/
  return kk_std_num_ddouble__ddouble_unbox(_x22472, _ctx);
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble_dd_pi;

kk_std_num_ddouble__ddouble kk_std_num_ddouble_dd_pi2;

kk_std_num_ddouble__ddouble kk_std_num_ddouble_dd_pi34;

kk_std_num_ddouble__ddouble kk_std_num_ddouble_dd_pi4;

kk_std_core__list kk_std_num_ddouble_ch_factors;

kk_std_num_ddouble__ddouble kk_std_num_ddouble_dd_twopi;
 
// Convert a `:ddouble` to a `:decimal` up to a given precision `prec` (= `-1`).
// A negative precision converts precisely. Returns 0 for non-finite `:ddouble`'s.

kk_std_num_decimal__decimal kk_std_num_ddouble_decimal(kk_std_num_ddouble__ddouble x, kk_std_core_types__optional prec, kk_context_t* _ctx) { /* (x : ddouble, prec : optional<int>) -> std/num/decimal/decimal */ 
  bool _match_21924;
  bool _x22478 = kk_std_num_ddouble_is_finite(x, _ctx); /*bool*/
  _match_21924 = !(_x22478); /*bool*/
  if (_match_21924) {
    kk_std_core_types__optional_drop(prec, _ctx);
    return kk_std_num_decimal_decimal(kk_integer_from_small(0), kk_std_core_types__new_None(_ctx), _ctx);
  }
  kk_std_num_decimal__decimal x0_20786;
  double _x22479;
  double _x3 = x.hi;
  _x22479 = _x3; /*double*/
  kk_std_core_types__optional _x22480;
  kk_box_t _x22481;
  kk_integer_t _x22482;
  if (kk_std_core_types__is_Optional(prec)) {
    kk_box_t _box_x21472 = prec._cons.Optional.value;
    kk_integer_t _prec_5395 = kk_integer_unbox(_box_x21472);
    kk_integer_dup(_prec_5395);
    _x22482 = _prec_5395; /*int*/
    goto _match22483;
  }
  _x22482 = kk_integer_from_small(-1); /*int*/
  _match22483: ;
  _x22481 = kk_integer_box(_x22482); /*35*/
  _x22480 = kk_std_core_types__new_Optional(_x22481, _ctx); /*optional<35>*/
  x0_20786 = kk_std_num_decimal_decimal_1(_x22479, _x22480, _ctx); /*std/num/decimal/decimal*/
  kk_std_num_decimal__decimal y_20787;
  double _x22485;
  double _x4 = x.lo;
  _x22485 = _x4; /*double*/
  kk_std_core_types__optional _x22486;
  kk_box_t _x22487;
  kk_integer_t _x22488;
  if (kk_std_core_types__is_Optional(prec)) {
    kk_box_t _box_x21475 = prec._cons.Optional.value;
    kk_integer_t _prec_53950 = kk_integer_unbox(_box_x21475);
    kk_integer_dup(_prec_53950);
    kk_std_core_types__optional_drop(prec, _ctx);
    _x22488 = _prec_53950; /*int*/
    goto _match22489;
  }
  _x22488 = kk_integer_from_small(-1); /*int*/
  _match22489: ;
  _x22487 = kk_integer_box(_x22488); /*35*/
  _x22486 = kk_std_core_types__new_Optional(_x22487, _ctx); /*optional<35>*/
  y_20787 = kk_std_num_decimal_decimal_1(_x22485, _x22486, _ctx); /*std/num/decimal/decimal*/
  kk_integer_t e;
  bool _match_21925;
  kk_integer_t _x22491;
  kk_integer_t _x = x0_20786.exp;
  kk_integer_dup(_x);
  _x22491 = _x; /*int*/
  kk_integer_t _x22492;
  kk_integer_t _x0 = y_20787.exp;
  kk_integer_dup(_x0);
  _x22492 = _x0; /*int*/
  _match_21925 = kk_integer_lte(_x22491,_x22492,kk_context()); /*bool*/
  if (_match_21925) {
    kk_integer_t _x1 = x0_20786.exp;
    kk_integer_dup(_x1);
    e = _x1; /*int*/
  }
  else {
    kk_integer_t _x00 = y_20787.exp;
    kk_integer_dup(_x00);
    e = _x00; /*int*/
  }
  kk_std_num_decimal__decimal xx;
  kk_integer_t _x22493 = kk_integer_dup(e); /*int*/
  xx = kk_std_num_decimal_expand(x0_20786, _x22493, _ctx); /*std/num/decimal/decimal*/
  kk_std_num_decimal__decimal yy;
  kk_integer_t _x22494 = kk_integer_dup(e); /*int*/
  yy = kk_std_num_decimal_expand(y_20787, _x22494, _ctx); /*std/num/decimal/decimal*/
  kk_integer_t _x22495;
  kk_integer_t _x22496;
  kk_integer_t _x10 = xx.num;
  kk_integer_dup(_x10);
  kk_std_num_decimal__decimal_drop(xx, _ctx);
  _x22496 = _x10; /*int*/
  kk_integer_t _x22497;
  kk_integer_t _x2 = yy.num;
  kk_integer_dup(_x2);
  kk_std_num_decimal__decimal_drop(yy, _ctx);
  _x22497 = _x2; /*int*/
  _x22495 = kk_integer_add(_x22496,_x22497,kk_context()); /*int*/
  return kk_std_num_decimal__new_Decimal(_x22495, e, _ctx);
}
 
// Convert a `:ddouble` to the nearest integer (rounding to the nearest even number in case of a tie)

kk_integer_t kk_std_num_ddouble_int(kk_std_num_ddouble__ddouble x, kk_std_core_types__optional nonfin, kk_context_t* _ctx) { /* (x : ddouble, nonfin : optional<int>) -> int */ 
  bool _match_21919;
  bool _x22498 = kk_std_num_ddouble_is_finite(x, _ctx); /*bool*/
  _match_21919 = !(_x22498); /*bool*/
  if (_match_21919) {
    if (kk_std_core_types__is_Optional(nonfin)) {
      kk_box_t _box_x21478 = nonfin._cons.Optional.value;
      kk_integer_t _nonfin_5551 = kk_integer_unbox(_box_x21478);
      kk_integer_dup(_nonfin_5551);
      kk_std_core_types__optional_drop(nonfin, _ctx);
      return _nonfin_5551;
    }
    return kk_integer_from_small(0);
  }
  kk_std_core_types__optional_drop(nonfin, _ctx);
  kk_std_num_decimal__decimal _x22500;
  kk_std_num_ddouble__ddouble x0_20790 = kk_std_num_ddouble_round(x, _ctx); /*std/num/ddouble/ddouble*/;
  bool _match_21920;
  bool _x22501 = kk_std_num_ddouble_is_finite(x0_20790, _ctx); /*bool*/
  _match_21920 = !(_x22501); /*bool*/
  if (_match_21920) {
    _x22500 = kk_std_num_decimal_decimal(kk_integer_from_small(0), kk_std_core_types__new_None(_ctx), _ctx); /*std/num/decimal/decimal*/
  }
  else {
    kk_std_num_decimal__decimal x1_20792;
    double _x22502;
    double _x3 = x0_20790.hi;
    _x22502 = _x3; /*double*/
    kk_std_core_types__optional _x22503;
    kk_box_t _x22504;
    kk_integer_t _x22505;
    kk_std_core_types__optional _match_21923 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
    if (kk_std_core_types__is_Optional(_match_21923)) {
      kk_box_t _box_x21479 = _match_21923._cons.Optional.value;
      kk_integer_t _prec_5395 = kk_integer_unbox(_box_x21479);
      kk_integer_dup(_prec_5395);
      kk_std_core_types__optional_drop(_match_21923, _ctx);
      _x22505 = _prec_5395; /*int*/
      goto _match22506;
    }
    _x22505 = kk_integer_from_small(-1); /*int*/
    _match22506: ;
    _x22504 = kk_integer_box(_x22505); /*35*/
    _x22503 = kk_std_core_types__new_Optional(_x22504, _ctx); /*optional<35>*/
    x1_20792 = kk_std_num_decimal_decimal_1(_x22502, _x22503, _ctx); /*std/num/decimal/decimal*/
    kk_std_num_decimal__decimal y_20793;
    double _x22508;
    double _x4 = x0_20790.lo;
    _x22508 = _x4; /*double*/
    kk_std_core_types__optional _x22509;
    kk_box_t _x22510;
    kk_integer_t _x22511;
    kk_std_core_types__optional _match_21922 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
    if (kk_std_core_types__is_Optional(_match_21922)) {
      kk_box_t _box_x21482 = _match_21922._cons.Optional.value;
      kk_integer_t _prec_53950 = kk_integer_unbox(_box_x21482);
      kk_integer_dup(_prec_53950);
      kk_std_core_types__optional_drop(_match_21922, _ctx);
      _x22511 = _prec_53950; /*int*/
      goto _match22512;
    }
    _x22511 = kk_integer_from_small(-1); /*int*/
    _match22512: ;
    _x22510 = kk_integer_box(_x22511); /*35*/
    _x22509 = kk_std_core_types__new_Optional(_x22510, _ctx); /*optional<35>*/
    y_20793 = kk_std_num_decimal_decimal_1(_x22508, _x22509, _ctx); /*std/num/decimal/decimal*/
    kk_integer_t e;
    bool _match_21921;
    kk_integer_t _x22514;
    kk_integer_t _x = x1_20792.exp;
    kk_integer_dup(_x);
    _x22514 = _x; /*int*/
    kk_integer_t _x22515;
    kk_integer_t _x0 = y_20793.exp;
    kk_integer_dup(_x0);
    _x22515 = _x0; /*int*/
    _match_21921 = kk_integer_lte(_x22514,_x22515,kk_context()); /*bool*/
    if (_match_21921) {
      kk_integer_t _x1 = x1_20792.exp;
      kk_integer_dup(_x1);
      e = _x1; /*int*/
    }
    else {
      kk_integer_t _x00 = y_20793.exp;
      kk_integer_dup(_x00);
      e = _x00; /*int*/
    }
    kk_std_num_decimal__decimal xx;
    kk_integer_t _x22516 = kk_integer_dup(e); /*int*/
    xx = kk_std_num_decimal_expand(x1_20792, _x22516, _ctx); /*std/num/decimal/decimal*/
    kk_std_num_decimal__decimal yy;
    kk_integer_t _x22517 = kk_integer_dup(e); /*int*/
    yy = kk_std_num_decimal_expand(y_20793, _x22517, _ctx); /*std/num/decimal/decimal*/
    kk_integer_t _x22518;
    kk_integer_t _x22519;
    kk_integer_t _x10 = xx.num;
    kk_integer_dup(_x10);
    kk_std_num_decimal__decimal_drop(xx, _ctx);
    _x22519 = _x10; /*int*/
    kk_integer_t _x22520;
    kk_integer_t _x2 = yy.num;
    kk_integer_dup(_x2);
    kk_std_num_decimal__decimal_drop(yy, _ctx);
    _x22520 = _x2; /*int*/
    _x22518 = kk_integer_add(_x22519,_x22520,kk_context()); /*int*/
    _x22500 = kk_std_num_decimal__new_Decimal(_x22518, e, _ctx); /*std/num/decimal/decimal*/
  }
  return kk_std_num_decimal_int(_x22500, kk_std_core_types__new_None(_ctx), _ctx);
}

kk_vector_t kk_std_num_ddouble_sin16_table;

kk_std_num_ddouble__ddouble kk_std_num_ddouble_dsum(double x, double y, kk_context_t* _ctx) { /* (x : double, y : double) -> ddouble */ 
  double z = (x + y); /*double*/;
  double diff = (z - x); /*double*/;
  double err0;
  double _x22523;
  double _x22524 = (z - diff); /*double*/
  _x22523 = (x - _x22524); /*double*/
  double _x22525 = (y - diff); /*double*/
  err0 = (_x22523 + _x22525); /*double*/
  double _x22526;
  bool _match_21918 = isfinite(z); /*bool*/;
  if (_match_21918) {
    _x22526 = err0; /*double*/
  }
  else {
    _x22526 = z; /*double*/
  }
  return kk_std_num_ddouble__new_Ddouble(z, _x22526, _ctx);
}
 
// The square root of a non-negative `:ddouble` `x`.
// For negative `x`, `dd-nan` is returned.

kk_std_num_ddouble__ddouble kk_std_num_ddouble_sqrt(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> ddouble */ 
  bool _match_21914 = kk_std_num_ddouble_is_zero(x, _ctx); /*bool*/;
  if (_match_21914) {
    return kk_std_num_ddouble__new_Ddouble(0x0p+0, 0x0p+0, _ctx);
  }
  bool _match_21915 = kk_std_num_ddouble_is_neg(x, _ctx); /*bool*/;
  if (_match_21915) {
    return kk_std_num_ddouble_dd_nan;
  }
  double a;
  double _x22527;
  double _x22528;
  double _x = x.hi;
  _x22528 = _x; /*double*/
  _x22527 = sqrt(_x22528); /*double*/
  a = (0x1p0 / _x22527); /*double*/
  double t1;
  double _x22529;
  double _x0 = x.hi;
  _x22529 = _x0; /*double*/
  t1 = (_x22529 * a); /*double*/
  double t2;
  double _x22530;
  double _x22531;
  kk_std_num_ddouble__ddouble ddouble1_20801;
  kk_std_num_ddouble__ddouble y_20803;
  kk_std_num_ddouble__ddouble x0_21107 = kk_std_num_ddouble_ddouble(t1, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__edouble z0;
  double z;
  double _x22532;
  double _x1 = x0_21107.hi;
  _x22532 = _x1; /*double*/
  double _x22533;
  double _x10 = x0_21107.hi;
  _x22533 = _x10; /*double*/
  z = (_x22532 * _x22533); /*double*/
  double err0;
  double _x22534;
  double _x11 = x0_21107.hi;
  _x22534 = _x11; /*double*/
  double _x22535;
  double _x12 = x0_21107.hi;
  _x22535 = _x12; /*double*/
  double _x22536 = (-z); /*double*/
  err0 = kk_std_num_double_fmadd(_x22534, _x22535, _x22536, _ctx); /*double*/
  z0 = kk_std_num_ddouble__new_Edouble(z, err0, _ctx); /*std/num/ddouble/edouble*/
  double e;
  double _x22537;
  double _x22538;
  double _x00 = z0.err;
  _x22538 = _x00; /*double*/
  double _x22539;
  double _x22540;
  double _x22541;
  double _x100 = x0_21107.hi;
  _x22541 = _x100; /*double*/
  _x22540 = (0x1p1 * _x22541); /*double*/
  double _x22542;
  double _x2 = x0_21107.lo;
  _x22542 = _x2; /*double*/
  _x22539 = (_x22540 * _x22542); /*double*/
  _x22537 = (_x22538 + _x22539); /*double*/
  double _x22543;
  double _x22544;
  double _x3 = x0_21107.lo;
  _x22544 = _x3; /*double*/
  double _x22545;
  double _x4 = x0_21107.lo;
  _x22545 = _x4; /*double*/
  _x22543 = (_x22544 * _x22545); /*double*/
  e = (_x22537 + _x22543); /*double*/
  bool _match_21916;
  bool _x22546;
  double _x22547;
  double _x5 = z0.num;
  _x22547 = _x5; /*double*/
  _x22546 = isfinite(_x22547); /*bool*/
  _match_21916 = !(_x22546); /*bool*/
  if (_match_21916) {
    double _x22548;
    double _x50 = z0.num;
    _x22548 = _x50; /*double*/
    y_20803 = kk_std_num_ddouble_ddouble(_x22548, _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    double z1;
    double _x22549;
    double _x51 = z0.num;
    _x22549 = _x51; /*double*/
    z1 = (_x22549 + e); /*double*/
    double err00;
    double _x22550;
    double _x22551;
    double _x52 = z0.num;
    _x22551 = _x52; /*double*/
    _x22550 = (z1 - _x22551); /*double*/
    err00 = (e - _x22550); /*double*/
    double _x22552;
    bool _match_21917 = isfinite(z1); /*bool*/;
    if (_match_21917) {
      _x22552 = err00; /*double*/
    }
    else {
      _x22552 = z1; /*double*/
    }
    y_20803 = kk_std_num_ddouble__new_Ddouble(z1, _x22552, _ctx); /*std/num/ddouble/ddouble*/
  }
  kk_std_num_ddouble__ddouble _x22553 = kk_std_num_ddouble__lp__tilde__rp_(y_20803, _ctx); /*std/num/ddouble/ddouble*/
  ddouble1_20801 = kk_std_num_ddouble__lp__plus__rp_(x, _x22553, _ctx); /*std/num/ddouble/ddouble*/
  double _x110 = ddouble1_20801.hi;
  _x22531 = _x110; /*double*/
  _x22530 = (_x22531 * a); /*double*/
  t2 = (_x22530 * (0x1p-1)); /*double*/
  return kk_std_num_ddouble_dsum(t1, t2, _ctx);
}
 
// Calculate sine and cosine on an angle in radians.


// lift anonymous function
struct kk_std_num_ddouble_sincos_fun22662__t {
  struct kk_function_s _base;
  kk_std_num_ddouble__ddouble s2;
};
static kk_box_t kk_std_num_ddouble_sincos_fun22662(kk_function_t _fself, kk_box_t _b_21527, kk_box_t _b_21528, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble_new_sincos_fun22662(kk_std_num_ddouble__ddouble s2, kk_context_t* _ctx) {
  struct kk_std_num_ddouble_sincos_fun22662__t* _self = kk_function_alloc_as(struct kk_std_num_ddouble_sincos_fun22662__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_num_ddouble_sincos_fun22662, kk_context());
  _self->s2 = s2;
  return &_self->_base;
}

static kk_box_t kk_std_num_ddouble_sincos_fun22662(kk_function_t _fself, kk_box_t _b_21527, kk_box_t _b_21528, kk_context_t* _ctx) {
  struct kk_std_num_ddouble_sincos_fun22662__t* _self = kk_function_as(struct kk_std_num_ddouble_sincos_fun22662__t*, _fself);
  kk_std_num_ddouble__ddouble s2 = _self->s2; /* std/num/ddouble/ddouble */
  kk_drop_match(_self, {kk_std_num_ddouble__ddouble_dup(s2);}, {}, _ctx)
  kk_std_num_ddouble__ddouble _x22663;
  kk_std_num_ddouble__ddouble _x22664 = kk_std_num_ddouble__ddouble_unbox(_b_21528, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x22665;
  kk_std_num_ddouble__ddouble _x22666 = kk_std_num_ddouble__ddouble_unbox(_b_21527, _ctx); /*std/num/ddouble/ddouble*/
  _x22665 = kk_std_num_ddouble__lp__star__rp_(_x22666, s2, _ctx); /*std/num/ddouble/ddouble*/
  _x22663 = kk_std_num_ddouble__lp__plus__rp_(_x22664, _x22665, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x22663, _ctx);
}

kk_std_core_types__tuple2_ kk_std_num_ddouble_sincos(kk_std_num_ddouble__ddouble rad, kk_context_t* _ctx) { /* (rad : ddouble) -> (ddouble, ddouble) */ 
  bool _match_21889;
  double _x22554;
  double _x22555;
  double _x = rad.hi;
  _x22555 = _x; /*double*/
  _x22554 = kk_double_abs(_x22555); /*double*/
  _match_21889 = (_x22554 < (0x1.5fd7fe1796495p-37)); /*bool*/
  if (_match_21889) {
    kk_std_num_ddouble__ddouble s;
    kk_std_num_ddouble__ddouble y_21109;
    kk_std_num_ddouble__ddouble y_20806;
    kk_std_num_ddouble__ddouble _x22556 = kk_std_num_ddouble_sqr(rad, _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble _x22557 = kk_std_num_ddouble_ddouble_int_exp(kk_integer_from_small(3), kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
    y_20806 = kk_std_num_ddouble__lp__fs__rp_(_x22556, _x22557, _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble _x22558 = kk_std_num_ddouble__new_Ddouble(0x1p0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble _x22559 = kk_std_num_ddouble__lp__tilde__rp_(y_20806, _ctx); /*std/num/ddouble/ddouble*/
    y_21109 = kk_std_num_ddouble__lp__plus__rp_(_x22558, _x22559, _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__edouble z0;
    double z;
    double _x22560;
    double _x0 = rad.hi;
    _x22560 = _x0; /*double*/
    double _x22561;
    double _x00 = y_21109.hi;
    _x22561 = _x00; /*double*/
    z = (_x22560 * _x22561); /*double*/
    double err0;
    double _x22562;
    double _x01 = rad.hi;
    _x22562 = _x01; /*double*/
    double _x22563;
    double _x000 = y_21109.hi;
    _x22563 = _x000; /*double*/
    double _x22564 = (-z); /*double*/
    err0 = kk_std_num_double_fmadd(_x22562, _x22563, _x22564, _ctx); /*double*/
    z0 = kk_std_num_ddouble__new_Edouble(z, err0, _ctx); /*std/num/ddouble/edouble*/
    double e;
    double _x22565;
    double _x1 = z0.err;
    _x22565 = _x1; /*double*/
    double _x22566;
    double _x22567;
    double _x22568;
    double _x2 = rad.hi;
    _x22568 = _x2; /*double*/
    double _x22569;
    double _x3 = y_21109.lo;
    _x22569 = _x3; /*double*/
    _x22567 = (_x22568 * _x22569); /*double*/
    double _x22570;
    double _x22571;
    double _x4 = rad.lo;
    _x22571 = _x4; /*double*/
    double _x22572;
    double _x5 = y_21109.hi;
    _x22572 = _x5; /*double*/
    _x22570 = (_x22571 * _x22572); /*double*/
    _x22566 = (_x22567 + _x22570); /*double*/
    e = (_x22565 + _x22566); /*double*/
    bool _match_21912;
    bool _x22573;
    double _x22574;
    double _x6 = z0.num;
    _x22574 = _x6; /*double*/
    _x22573 = isfinite(_x22574); /*bool*/
    _match_21912 = !(_x22573); /*bool*/
    if (_match_21912) {
      double _x22575;
      double _x60 = z0.num;
      _x22575 = _x60; /*double*/
      s = kk_std_num_ddouble_ddouble(_x22575, _ctx); /*std/num/ddouble/ddouble*/
    }
    else {
      double z1;
      double _x22576;
      double _x61 = z0.num;
      _x22576 = _x61; /*double*/
      z1 = (_x22576 + e); /*double*/
      double err00;
      double _x22577;
      double _x22578;
      double _x62 = z0.num;
      _x22578 = _x62; /*double*/
      _x22577 = (z1 - _x22578); /*double*/
      err00 = (e - _x22577); /*double*/
      double _x22579;
      bool _match_21913 = isfinite(z1); /*bool*/;
      if (_match_21913) {
        _x22579 = err00; /*double*/
      }
      else {
        _x22579 = z1; /*double*/
      }
      s = kk_std_num_ddouble__new_Ddouble(z1, _x22579, _ctx); /*std/num/ddouble/ddouble*/
    }
    kk_std_num_ddouble__ddouble c;
    kk_std_num_ddouble__ddouble x0_20808;
    kk_std_num_ddouble__ddouble y1_20810 = kk_std_num_ddouble_sqr(s, _ctx); /*std/num/ddouble/ddouble*/;
    kk_std_num_ddouble__ddouble _x22580 = kk_std_num_ddouble__new_Ddouble(0x1p0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble _x22581 = kk_std_num_ddouble__lp__tilde__rp_(y1_20810, _ctx); /*std/num/ddouble/ddouble*/
    x0_20808 = kk_std_num_ddouble__lp__plus__rp_(_x22580, _x22581, _ctx); /*std/num/ddouble/ddouble*/
    bool _match_21908 = kk_std_num_ddouble_is_zero(x0_20808, _ctx); /*bool*/;
    if (_match_21908) {
      c = kk_std_num_ddouble__new_Ddouble(0x0p+0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    }
    else {
      bool _match_21909 = kk_std_num_ddouble_is_neg(x0_20808, _ctx); /*bool*/;
      if (_match_21909) {
        c = kk_std_num_ddouble_dd_nan; /*std/num/ddouble/ddouble*/
      }
      else {
        double a;
        double _x22582;
        double _x22583;
        double _x010 = x0_20808.hi;
        _x22583 = _x010; /*double*/
        _x22582 = sqrt(_x22583); /*double*/
        a = (0x1p0 / _x22582); /*double*/
        double t1;
        double _x22584;
        double _x10 = x0_20808.hi;
        _x22584 = _x10; /*double*/
        t1 = (_x22584 * a); /*double*/
        double t2;
        double _x22585;
        double _x22586;
        kk_std_num_ddouble__ddouble ddouble2_20813;
        kk_std_num_ddouble__ddouble y0_20815;
        kk_std_num_ddouble__ddouble x0_21110 = kk_std_num_ddouble_ddouble(t1, _ctx); /*std/num/ddouble/ddouble*/;
        kk_std_num_ddouble__edouble z00;
        double z2;
        double _x22587;
        double _x7 = x0_21110.hi;
        _x22587 = _x7; /*double*/
        double _x22588;
        double _x70 = x0_21110.hi;
        _x22588 = _x70; /*double*/
        z2 = (_x22587 * _x22588); /*double*/
        double err1;
        double _x22589;
        double _x71 = x0_21110.hi;
        _x22589 = _x71; /*double*/
        double _x22590;
        double _x72 = x0_21110.hi;
        _x22590 = _x72; /*double*/
        double _x22591 = (-z2); /*double*/
        err1 = kk_std_num_double_fmadd(_x22589, _x22590, _x22591, _ctx); /*double*/
        z00 = kk_std_num_ddouble__new_Edouble(z2, err1, _ctx); /*std/num/ddouble/edouble*/
        double e0;
        double _x22592;
        double _x22593;
        double _x02 = z00.err;
        _x22593 = _x02; /*double*/
        double _x22594;
        double _x22595;
        double _x22596;
        double _x11 = x0_21110.hi;
        _x22596 = _x11; /*double*/
        _x22595 = (0x1p1 * _x22596); /*double*/
        double _x22597;
        double _x20 = x0_21110.lo;
        _x22597 = _x20; /*double*/
        _x22594 = (_x22595 * _x22597); /*double*/
        _x22592 = (_x22593 + _x22594); /*double*/
        double _x22598;
        double _x22599;
        double _x30 = x0_21110.lo;
        _x22599 = _x30; /*double*/
        double _x22600;
        double _x40 = x0_21110.lo;
        _x22600 = _x40; /*double*/
        _x22598 = (_x22599 * _x22600); /*double*/
        e0 = (_x22592 + _x22598); /*double*/
        bool _match_21910;
        bool _x22601;
        double _x22602;
        double _x50 = z00.num;
        _x22602 = _x50; /*double*/
        _x22601 = isfinite(_x22602); /*bool*/
        _match_21910 = !(_x22601); /*bool*/
        if (_match_21910) {
          double _x22603;
          double _x500 = z00.num;
          _x22603 = _x500; /*double*/
          y0_20815 = kk_std_num_ddouble_ddouble(_x22603, _ctx); /*std/num/ddouble/ddouble*/
        }
        else {
          double z10;
          double _x22604;
          double _x501 = z00.num;
          _x22604 = _x501; /*double*/
          z10 = (_x22604 + e0); /*double*/
          double err000;
          double _x22605;
          double _x22606;
          double _x502 = z00.num;
          _x22606 = _x502; /*double*/
          _x22605 = (z10 - _x22606); /*double*/
          err000 = (e0 - _x22605); /*double*/
          double _x22607;
          bool _match_21911 = isfinite(z10); /*bool*/;
          if (_match_21911) {
            _x22607 = err000; /*double*/
          }
          else {
            _x22607 = z10; /*double*/
          }
          y0_20815 = kk_std_num_ddouble__new_Ddouble(z10, _x22607, _ctx); /*std/num/ddouble/ddouble*/
        }
        kk_std_num_ddouble__ddouble _x22608 = kk_std_num_ddouble__lp__tilde__rp_(y0_20815, _ctx); /*std/num/ddouble/ddouble*/
        ddouble2_20813 = kk_std_num_ddouble__lp__plus__rp_(x0_20808, _x22608, _ctx); /*std/num/ddouble/ddouble*/
        double _x21 = ddouble2_20813.hi;
        _x22586 = _x21; /*double*/
        _x22585 = (_x22586 * a); /*double*/
        t2 = (_x22585 * (0x1p-1)); /*double*/
        c = kk_std_num_ddouble_dsum(t1, t2, _ctx); /*std/num/ddouble/ddouble*/
      }
    }
    return kk_std_core_types__new_dash__lp__comma__rp_(kk_std_num_ddouble__ddouble_box(s, _ctx), kk_std_num_ddouble__ddouble_box(c, _ctx), _ctx);
  }
  kk_std_num_ddouble__ddouble x10;
  kk_std_num_ddouble__ddouble _x22609 = kk_std_num_ddouble__new_Ddouble(0x1.921fb54442d18p2, 0x1.1a62633145c07p-52, _ctx); /*std/num/ddouble/ddouble*/
  x10 = kk_std_num_ddouble__lp__fs__rp_(rad, _x22609, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble x30;
  kk_std_num_ddouble__ddouble y2_20817 = kk_std_num_ddouble_round(x10, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__ddouble _x22610 = kk_std_num_ddouble__lp__tilde__rp_(y2_20817, _ctx); /*std/num/ddouble/ddouble*/
  x30 = kk_std_num_ddouble__lp__plus__rp_(x10, _x22610, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble x32 = kk_std_num_ddouble__lp__plus__rp_(x30, x30, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__ddouble x34 = kk_std_num_ddouble__lp__plus__rp_(x32, x32, _ctx); /*std/num/ddouble/ddouble*/;
  kk_integer_t a0 = kk_std_num_ddouble_int(x34, kk_std_core_types__new_None(_ctx), _ctx); /*int*/;
  kk_integer_t b;
  kk_std_num_ddouble__ddouble _x22611;
  kk_std_num_ddouble__ddouble x1_21111 = kk_std_num_ddouble_ddouble_int_exp(kk_integer_from_small(8), kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__ddouble y0_21112;
  kk_std_num_ddouble__ddouble y3_20820;
  kk_integer_t _x22612 = kk_integer_dup(a0); /*int*/
  y3_20820 = kk_std_num_ddouble_ddouble_1(_x22612, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x22613 = kk_std_num_ddouble__lp__tilde__rp_(y3_20820, _ctx); /*std/num/ddouble/ddouble*/
  y0_21112 = kk_std_num_ddouble__lp__plus__rp_(x34, _x22613, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__edouble z01;
  double z3;
  double _x22614;
  double _x8 = x1_21111.hi;
  _x22614 = _x8; /*double*/
  double _x22615;
  double _x03 = y0_21112.hi;
  _x22615 = _x03; /*double*/
  z3 = (_x22614 * _x22615); /*double*/
  double err2;
  double _x22616;
  double _x80 = x1_21111.hi;
  _x22616 = _x80; /*double*/
  double _x22617;
  double _x030 = y0_21112.hi;
  _x22617 = _x030; /*double*/
  double _x22618 = (-z3); /*double*/
  err2 = kk_std_num_double_fmadd(_x22616, _x22617, _x22618, _ctx); /*double*/
  z01 = kk_std_num_ddouble__new_Edouble(z3, err2, _ctx); /*std/num/ddouble/edouble*/
  double e1;
  double _x22619;
  double _x12 = z01.err;
  _x22619 = _x12; /*double*/
  double _x22620;
  double _x22621;
  double _x22622;
  double _x22 = x1_21111.hi;
  _x22622 = _x22; /*double*/
  double _x22623;
  double _x31 = y0_21112.lo;
  _x22623 = _x31; /*double*/
  _x22621 = (_x22622 * _x22623); /*double*/
  double _x22624;
  double _x22625;
  double _x41 = x1_21111.lo;
  _x22625 = _x41; /*double*/
  double _x22626;
  double _x51 = y0_21112.hi;
  _x22626 = _x51; /*double*/
  _x22624 = (_x22625 * _x22626); /*double*/
  _x22620 = (_x22621 + _x22624); /*double*/
  e1 = (_x22619 + _x22620); /*double*/
  bool _match_21906;
  bool _x22627;
  double _x22628;
  double _x600 = z01.num;
  _x22628 = _x600; /*double*/
  _x22627 = isfinite(_x22628); /*bool*/
  _match_21906 = !(_x22627); /*bool*/
  if (_match_21906) {
    double _x22629;
    double _x601 = z01.num;
    _x22629 = _x601; /*double*/
    _x22611 = kk_std_num_ddouble_ddouble(_x22629, _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    double z11;
    double _x22630;
    double _x602 = z01.num;
    _x22630 = _x602; /*double*/
    z11 = (_x22630 + e1); /*double*/
    double err01;
    double _x22631;
    double _x22632;
    double _x603 = z01.num;
    _x22632 = _x603; /*double*/
    _x22631 = (z11 - _x22632); /*double*/
    err01 = (e1 - _x22631); /*double*/
    double _x22633;
    bool _match_21907 = isfinite(z11); /*bool*/;
    if (_match_21907) {
      _x22633 = err01; /*double*/
    }
    else {
      _x22633 = z11; /*double*/
    }
    _x22611 = kk_std_num_ddouble__new_Ddouble(z11, _x22633, _ctx); /*std/num/ddouble/ddouble*/
  }
  b = kk_std_num_ddouble_int(_x22611, kk_std_core_types__new_None(_ctx), _ctx); /*int*/
  kk_std_num_ddouble__ddouble s0;
  kk_std_num_ddouble__ddouble x2_21113 = kk_std_num_ddouble__new_Ddouble(0x1.921fb54442d18p1, 0x1.1a62633145c07p-53, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__ddouble y1_21114;
  kk_std_num_ddouble__ddouble y4_20822;
  kk_std_num_ddouble__ddouble _x22634;
  kk_integer_t i1_20823;
  kk_integer_t _x22635;
  kk_integer_t _x22636 = kk_integer_dup(a0); /*int*/
  _x22635 = kk_integer_mul((kk_integer_from_small(8)),_x22636,kk_context()); /*int*/
  kk_integer_t _x22637 = kk_integer_dup(b); /*int*/
  i1_20823 = kk_integer_add(_x22635,_x22637,kk_context()); /*int*/
  _x22634 = kk_std_num_ddouble_ddouble_int_exp(i1_20823, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x22638 = kk_std_num_ddouble_ddouble_int_exp(kk_integer_from_small(16), kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
  y4_20822 = kk_std_num_ddouble__lp__fs__rp_(_x22634, _x22638, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x22639 = kk_std_num_ddouble__lp__tilde__rp_(y4_20822, _ctx); /*std/num/ddouble/ddouble*/
  y1_21114 = kk_std_num_ddouble__lp__plus__rp_(x32, _x22639, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__edouble z02;
  double z4;
  double _x22640;
  double _x9 = x2_21113.hi;
  _x22640 = _x9; /*double*/
  double _x22641;
  double _x04 = y1_21114.hi;
  _x22641 = _x04; /*double*/
  z4 = (_x22640 * _x22641); /*double*/
  double err3;
  double _x22642;
  double _x90 = x2_21113.hi;
  _x22642 = _x90; /*double*/
  double _x22643;
  double _x040 = y1_21114.hi;
  _x22643 = _x040; /*double*/
  double _x22644 = (-z4); /*double*/
  err3 = kk_std_num_double_fmadd(_x22642, _x22643, _x22644, _ctx); /*double*/
  z02 = kk_std_num_ddouble__new_Edouble(z4, err3, _ctx); /*std/num/ddouble/edouble*/
  double e2;
  double _x22645;
  double _x13 = z02.err;
  _x22645 = _x13; /*double*/
  double _x22646;
  double _x22647;
  double _x22648;
  double _x23 = x2_21113.hi;
  _x22648 = _x23; /*double*/
  double _x22649;
  double _x32 = y1_21114.lo;
  _x22649 = _x32; /*double*/
  _x22647 = (_x22648 * _x22649); /*double*/
  double _x22650;
  double _x22651;
  double _x42 = x2_21113.lo;
  _x22651 = _x42; /*double*/
  double _x22652;
  double _x52 = y1_21114.hi;
  _x22652 = _x52; /*double*/
  _x22650 = (_x22651 * _x22652); /*double*/
  _x22646 = (_x22647 + _x22650); /*double*/
  e2 = (_x22645 + _x22646); /*double*/
  bool _match_21904;
  bool _x22653;
  double _x22654;
  double _x610 = z02.num;
  _x22654 = _x610; /*double*/
  _x22653 = isfinite(_x22654); /*bool*/
  _match_21904 = !(_x22653); /*bool*/
  if (_match_21904) {
    double _x22655;
    double _x611 = z02.num;
    _x22655 = _x611; /*double*/
    s0 = kk_std_num_ddouble_ddouble(_x22655, _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    double z12;
    double _x22656;
    double _x612 = z02.num;
    _x22656 = _x612; /*double*/
    z12 = (_x22656 + e2); /*double*/
    double err02;
    double _x22657;
    double _x22658;
    double _x613 = z02.num;
    _x22658 = _x613; /*double*/
    _x22657 = (z12 - _x22658); /*double*/
    err02 = (e2 - _x22657); /*double*/
    double _x22659;
    bool _match_21905 = isfinite(z12); /*bool*/;
    if (_match_21905) {
      _x22659 = err02; /*double*/
    }
    else {
      _x22659 = z12; /*double*/
    }
    s0 = kk_std_num_ddouble__new_Ddouble(z12, _x22659, _ctx); /*std/num/ddouble/ddouble*/
  }
  kk_std_num_ddouble__ddouble s2 = kk_std_num_ddouble_sqr(s0, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__ddouble sins;
  kk_std_num_ddouble__ddouble y2_21116;
  kk_std_num_ddouble__ddouble _b_21530_21525 = kk_std_num_ddouble__new_Ddouble(0x0p+0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/;
  kk_box_t _x22660;
  kk_std_core__list _x22661 = kk_std_core__list_dup(kk_std_num_ddouble_ch_factors); /*list<std/num/ddouble/ddouble>*/
  _x22660 = kk_std_core_foldl(_x22661, kk_std_num_ddouble__ddouble_box(_b_21530_21525, _ctx), kk_std_num_ddouble_new_sincos_fun22662(s2, _ctx), _ctx); /*2*/
  y2_21116 = kk_std_num_ddouble__ddouble_unbox(_x22660, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__edouble z03;
  double z5;
  double _x22667;
  double _x14 = s0.hi;
  _x22667 = _x14; /*double*/
  double _x22668;
  double _x05 = y2_21116.hi;
  _x22668 = _x05; /*double*/
  z5 = (_x22667 * _x22668); /*double*/
  double err4;
  double _x22669;
  double _x140 = s0.hi;
  _x22669 = _x140; /*double*/
  double _x22670;
  double _x050 = y2_21116.hi;
  _x22670 = _x050; /*double*/
  double _x22671 = (-z5); /*double*/
  err4 = kk_std_num_double_fmadd(_x22669, _x22670, _x22671, _ctx); /*double*/
  z03 = kk_std_num_ddouble__new_Edouble(z5, err4, _ctx); /*std/num/ddouble/edouble*/
  double e3;
  double _x22672;
  double _x15 = z03.err;
  _x22672 = _x15; /*double*/
  double _x22673;
  double _x22674;
  double _x22675;
  double _x24 = s0.hi;
  _x22675 = _x24; /*double*/
  double _x22676;
  double _x33 = y2_21116.lo;
  _x22676 = _x33; /*double*/
  _x22674 = (_x22675 * _x22676); /*double*/
  double _x22677;
  double _x22678;
  double _x43 = s0.lo;
  _x22678 = _x43; /*double*/
  double _x22679;
  double _x53 = y2_21116.hi;
  _x22679 = _x53; /*double*/
  _x22677 = (_x22678 * _x22679); /*double*/
  _x22673 = (_x22674 + _x22677); /*double*/
  e3 = (_x22672 + _x22673); /*double*/
  bool _match_21902;
  bool _x22680;
  double _x22681;
  double _x620 = z03.num;
  _x22681 = _x620; /*double*/
  _x22680 = isfinite(_x22681); /*bool*/
  _match_21902 = !(_x22680); /*bool*/
  if (_match_21902) {
    double _x22682;
    double _x621 = z03.num;
    _x22682 = _x621; /*double*/
    sins = kk_std_num_ddouble_ddouble(_x22682, _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    double z13;
    double _x22683;
    double _x622 = z03.num;
    _x22683 = _x622; /*double*/
    z13 = (_x22683 + e3); /*double*/
    double err03;
    double _x22684;
    double _x22685;
    double _x623 = z03.num;
    _x22685 = _x623; /*double*/
    _x22684 = (z13 - _x22685); /*double*/
    err03 = (e3 - _x22684); /*double*/
    double _x22686;
    bool _match_21903 = isfinite(z13); /*bool*/;
    if (_match_21903) {
      _x22686 = err03; /*double*/
    }
    else {
      _x22686 = z13; /*double*/
    }
    sins = kk_std_num_ddouble__new_Ddouble(z13, _x22686, _ctx); /*std/num/ddouble/ddouble*/
  }
  kk_std_num_ddouble__ddouble coss;
  kk_std_num_ddouble__ddouble x6_20825;
  kk_std_num_ddouble__ddouble y6_20827 = kk_std_num_ddouble_sqr(sins, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__ddouble _x22687 = kk_std_num_ddouble__new_Ddouble(0x1p0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x22688 = kk_std_num_ddouble__lp__tilde__rp_(y6_20827, _ctx); /*std/num/ddouble/ddouble*/
  x6_20825 = kk_std_num_ddouble__lp__plus__rp_(_x22687, _x22688, _ctx); /*std/num/ddouble/ddouble*/
  bool _match_21898 = kk_std_num_ddouble_is_zero(x6_20825, _ctx); /*bool*/;
  if (_match_21898) {
    coss = kk_std_num_ddouble__new_Ddouble(0x0p+0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    bool _match_21899 = kk_std_num_ddouble_is_neg(x6_20825, _ctx); /*bool*/;
    if (_match_21899) {
      coss = kk_std_num_ddouble_dd_nan; /*std/num/ddouble/ddouble*/
    }
    else {
      double a1;
      double _x22689;
      double _x22690;
      double _x34 = x6_20825.hi;
      _x22690 = _x34; /*double*/
      _x22689 = sqrt(_x22690); /*double*/
      a1 = (0x1p0 / _x22689); /*double*/
      double t10;
      double _x22691;
      double _x44 = x6_20825.hi;
      _x22691 = _x44; /*double*/
      t10 = (_x22691 * a1); /*double*/
      double t20;
      double _x22692;
      double _x22693;
      kk_std_num_ddouble__ddouble ddouble5_20830;
      kk_std_num_ddouble__ddouble y5_20832;
      kk_std_num_ddouble__ddouble x4_21117 = kk_std_num_ddouble_ddouble(t10, _ctx); /*std/num/ddouble/ddouble*/;
      kk_std_num_ddouble__edouble z04;
      double z6;
      double _x22694;
      double _x16 = x4_21117.hi;
      _x22694 = _x16; /*double*/
      double _x22695;
      double _x160 = x4_21117.hi;
      _x22695 = _x160; /*double*/
      z6 = (_x22694 * _x22695); /*double*/
      double err5;
      double _x22696;
      double _x161 = x4_21117.hi;
      _x22696 = _x161; /*double*/
      double _x22697;
      double _x162 = x4_21117.hi;
      _x22697 = _x162; /*double*/
      double _x22698 = (-z6); /*double*/
      err5 = kk_std_num_double_fmadd(_x22696, _x22697, _x22698, _ctx); /*double*/
      z04 = kk_std_num_ddouble__new_Edouble(z6, err5, _ctx); /*std/num/ddouble/edouble*/
      double e4;
      double _x22699;
      double _x22700;
      double _x06 = z04.err;
      _x22700 = _x06; /*double*/
      double _x22701;
      double _x22702;
      double _x22703;
      double _x17 = x4_21117.hi;
      _x22703 = _x17; /*double*/
      _x22702 = (0x1p1 * _x22703); /*double*/
      double _x22704;
      double _x25 = x4_21117.lo;
      _x22704 = _x25; /*double*/
      _x22701 = (_x22702 * _x22704); /*double*/
      _x22699 = (_x22700 + _x22701); /*double*/
      double _x22705;
      double _x22706;
      double _x35 = x4_21117.lo;
      _x22706 = _x35; /*double*/
      double _x22707;
      double _x45 = x4_21117.lo;
      _x22707 = _x45; /*double*/
      _x22705 = (_x22706 * _x22707); /*double*/
      e4 = (_x22699 + _x22705); /*double*/
      bool _match_21900;
      bool _x22708;
      double _x22709;
      double _x54 = z04.num;
      _x22709 = _x54; /*double*/
      _x22708 = isfinite(_x22709); /*bool*/
      _match_21900 = !(_x22708); /*bool*/
      if (_match_21900) {
        double _x22710;
        double _x540 = z04.num;
        _x22710 = _x540; /*double*/
        y5_20832 = kk_std_num_ddouble_ddouble(_x22710, _ctx); /*std/num/ddouble/ddouble*/
      }
      else {
        double z14;
        double _x22711;
        double _x541 = z04.num;
        _x22711 = _x541; /*double*/
        z14 = (_x22711 + e4); /*double*/
        double err04;
        double _x22712;
        double _x22713;
        double _x542 = z04.num;
        _x22713 = _x542; /*double*/
        _x22712 = (z14 - _x22713); /*double*/
        err04 = (e4 - _x22712); /*double*/
        double _x22714;
        bool _match_21901 = isfinite(z14); /*bool*/;
        if (_match_21901) {
          _x22714 = err04; /*double*/
        }
        else {
          _x22714 = z14; /*double*/
        }
        y5_20832 = kk_std_num_ddouble__new_Ddouble(z14, _x22714, _ctx); /*std/num/ddouble/ddouble*/
      }
      kk_std_num_ddouble__ddouble _x22715 = kk_std_num_ddouble__lp__tilde__rp_(y5_20832, _ctx); /*std/num/ddouble/ddouble*/
      ddouble5_20830 = kk_std_num_ddouble__lp__plus__rp_(x6_20825, _x22715, _ctx); /*std/num/ddouble/ddouble*/
      double _x55 = ddouble5_20830.hi;
      _x22693 = _x55; /*double*/
      _x22692 = (_x22693 * a1); /*double*/
      t20 = (_x22692 * (0x1p-1)); /*double*/
      coss = kk_std_num_ddouble_dsum(t10, t20, _ctx); /*std/num/ddouble/ddouble*/
    }
  }
  kk_std_num_ddouble__ddouble sinb;
  bool _match_21897;
  kk_integer_t _x22716 = kk_integer_dup(b); /*int*/
  _match_21897 = kk_integer_gte(_x22716,(kk_integer_from_small(0)),kk_context()); /*bool*/
  if (_match_21897) {
    kk_integer_t _x22717 = kk_integer_dup(b); /*int*/
    sinb = kk_std_num_ddouble_sin16(_x22717, _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    kk_std_num_ddouble__ddouble x9_20833;
    kk_integer_t i3_20834;
    kk_integer_t _x22718 = kk_integer_dup(b); /*int*/
    i3_20834 = kk_integer_neg(_x22718,kk_context()); /*int*/
    kk_std_core_types__maybe m_20835;
    kk_vector_t _x22719 = kk_vector_dup(kk_std_num_ddouble_sin16_table); /*vector<std/num/ddouble/ddouble>*/
    m_20835 = kk_std_core_at(_x22719, i3_20834, _ctx); /*maybe<std/num/ddouble/ddouble>*/
    if (kk_std_core_types__is_Nothing(m_20835)) {
      x9_20833 = kk_std_num_ddouble_dd_nan; /*std/num/ddouble/ddouble*/
    }
    else {
      kk_box_t _box_x21534 = m_20835._cons.Just.value;
      kk_std_num_ddouble__ddouble x11 = kk_std_num_ddouble__ddouble_unbox(_box_x21534, NULL);
      kk_std_core_types__maybe_drop(m_20835, _ctx);
      x9_20833 = x11; /*std/num/ddouble/ddouble*/
    }
    double _x22721;
    double _x22722;
    double _x63 = x9_20833.hi;
    _x22722 = _x63; /*double*/
    _x22721 = (-_x22722); /*double*/
    double _x22723;
    double _x22724;
    double _x700 = x9_20833.lo;
    _x22724 = _x700; /*double*/
    _x22723 = (-_x22724); /*double*/
    sinb = kk_std_num_ddouble__new_Ddouble(_x22721, _x22723, _ctx); /*std/num/ddouble/ddouble*/
  }
  kk_std_num_ddouble__ddouble cosb;
  kk_integer_t i4_20839;
  kk_integer_t _x22725 = kk_integer_abs(b,kk_context()); /*int*/
  i4_20839 = kk_integer_sub((kk_integer_from_small(8)),_x22725,kk_context()); /*int*/
  kk_std_core_types__maybe m0_20840;
  kk_vector_t _x22726 = kk_vector_dup(kk_std_num_ddouble_sin16_table); /*vector<std/num/ddouble/ddouble>*/
  m0_20840 = kk_std_core_at(_x22726, i4_20839, _ctx); /*maybe<std/num/ddouble/ddouble>*/
  if (kk_std_core_types__is_Nothing(m0_20840)) {
    cosb = kk_std_num_ddouble_dd_nan; /*std/num/ddouble/ddouble*/
  }
  else {
    kk_box_t _box_x21535 = m0_20840._cons.Just.value;
    kk_std_num_ddouble__ddouble x12 = kk_std_num_ddouble__ddouble_unbox(_box_x21535, NULL);
    kk_std_core_types__maybe_drop(m0_20840, _ctx);
    cosb = x12; /*std/num/ddouble/ddouble*/
  }
  bool _match_21890;
  kk_integer_t _x22728 = kk_integer_dup(a0); /*int*/
  _match_21890 = kk_integer_eq(_x22728,(kk_integer_from_small(0)),kk_context()); /*bool*/
  if (_match_21890) {
    kk_integer_drop(a0, _ctx);
    kk_std_num_ddouble__ddouble _b_21546_21536;
    kk_std_num_ddouble__ddouble _x22729 = kk_std_num_ddouble__lp__star__rp_(sins, cosb, _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble _x22730 = kk_std_num_ddouble__lp__star__rp_(coss, sinb, _ctx); /*std/num/ddouble/ddouble*/
    _b_21546_21536 = kk_std_num_ddouble__lp__plus__rp_(_x22729, _x22730, _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble _b_21547_21537;
    kk_std_num_ddouble__ddouble x13_20842 = kk_std_num_ddouble__lp__star__rp_(coss, cosb, _ctx); /*std/num/ddouble/ddouble*/;
    kk_std_num_ddouble__ddouble y7_20843 = kk_std_num_ddouble__lp__star__rp_(sins, sinb, _ctx); /*std/num/ddouble/ddouble*/;
    kk_std_num_ddouble__ddouble _x22731 = kk_std_num_ddouble__lp__tilde__rp_(y7_20843, _ctx); /*std/num/ddouble/ddouble*/
    _b_21547_21537 = kk_std_num_ddouble__lp__plus__rp_(x13_20842, _x22731, _ctx); /*std/num/ddouble/ddouble*/
    return kk_std_core_types__new_dash__lp__comma__rp_(kk_std_num_ddouble__ddouble_box(_b_21546_21536, _ctx), kk_std_num_ddouble__ddouble_box(_b_21547_21537, _ctx), _ctx);
  }
  bool _match_21891;
  kk_integer_t _x22732 = kk_integer_dup(a0); /*int*/
  _match_21891 = kk_integer_eq(_x22732,(kk_integer_from_small(1)),kk_context()); /*bool*/
  if (_match_21891) {
    kk_integer_drop(a0, _ctx);
    kk_std_num_ddouble__ddouble _b_21548_21538;
    kk_std_num_ddouble__ddouble x14_20844 = kk_std_num_ddouble__lp__star__rp_(coss, cosb, _ctx); /*std/num/ddouble/ddouble*/;
    kk_std_num_ddouble__ddouble y8_20845 = kk_std_num_ddouble__lp__star__rp_(sins, sinb, _ctx); /*std/num/ddouble/ddouble*/;
    kk_std_num_ddouble__ddouble _x22733 = kk_std_num_ddouble__lp__tilde__rp_(y8_20845, _ctx); /*std/num/ddouble/ddouble*/
    _b_21548_21538 = kk_std_num_ddouble__lp__plus__rp_(x14_20844, _x22733, _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble _b_21549_21539;
    kk_std_num_ddouble__ddouble x15_20846;
    kk_std_num_ddouble__ddouble x5_21118 = kk_std_num_ddouble__lp__tilde__rp_(coss, _ctx); /*std/num/ddouble/ddouble*/;
    kk_std_num_ddouble__edouble z05;
    double z7;
    double _x22734;
    double _x18 = x5_21118.hi;
    _x22734 = _x18; /*double*/
    double _x22735;
    double _x07 = sinb.hi;
    _x22735 = _x07; /*double*/
    z7 = (_x22734 * _x22735); /*double*/
    double err6;
    double _x22736;
    double _x180 = x5_21118.hi;
    _x22736 = _x180; /*double*/
    double _x22737;
    double _x070 = sinb.hi;
    _x22737 = _x070; /*double*/
    double _x22738 = (-z7); /*double*/
    err6 = kk_std_num_double_fmadd(_x22736, _x22737, _x22738, _ctx); /*double*/
    z05 = kk_std_num_ddouble__new_Edouble(z7, err6, _ctx); /*std/num/ddouble/edouble*/
    double e5;
    double _x22739;
    double _x19 = z05.err;
    _x22739 = _x19; /*double*/
    double _x22740;
    double _x22741;
    double _x22742;
    double _x26 = x5_21118.hi;
    _x22742 = _x26; /*double*/
    double _x22743;
    double _x36 = sinb.lo;
    _x22743 = _x36; /*double*/
    _x22741 = (_x22742 * _x22743); /*double*/
    double _x22744;
    double _x22745;
    double _x46 = x5_21118.lo;
    _x22745 = _x46; /*double*/
    double _x22746;
    double _x56 = sinb.hi;
    _x22746 = _x56; /*double*/
    _x22744 = (_x22745 * _x22746); /*double*/
    _x22740 = (_x22741 + _x22744); /*double*/
    e5 = (_x22739 + _x22740); /*double*/
    bool _match_21895;
    bool _x22747;
    double _x22748;
    double _x64 = z05.num;
    _x22748 = _x64; /*double*/
    _x22747 = isfinite(_x22748); /*bool*/
    _match_21895 = !(_x22747); /*bool*/
    if (_match_21895) {
      double _x22749;
      double _x640 = z05.num;
      _x22749 = _x640; /*double*/
      x15_20846 = kk_std_num_ddouble_ddouble(_x22749, _ctx); /*std/num/ddouble/ddouble*/
    }
    else {
      double z15;
      double _x22750;
      double _x641 = z05.num;
      _x22750 = _x641; /*double*/
      z15 = (_x22750 + e5); /*double*/
      double err05;
      double _x22751;
      double _x22752;
      double _x642 = z05.num;
      _x22752 = _x642; /*double*/
      _x22751 = (z15 - _x22752); /*double*/
      err05 = (e5 - _x22751); /*double*/
      double _x22753;
      bool _match_21896 = isfinite(z15); /*bool*/;
      if (_match_21896) {
        _x22753 = err05; /*double*/
      }
      else {
        _x22753 = z15; /*double*/
      }
      x15_20846 = kk_std_num_ddouble__new_Ddouble(z15, _x22753, _ctx); /*std/num/ddouble/ddouble*/
    }
    kk_std_num_ddouble__ddouble y9_20847 = kk_std_num_ddouble__lp__star__rp_(sins, cosb, _ctx); /*std/num/ddouble/ddouble*/;
    kk_std_num_ddouble__ddouble _x22754 = kk_std_num_ddouble__lp__tilde__rp_(y9_20847, _ctx); /*std/num/ddouble/ddouble*/
    _b_21549_21539 = kk_std_num_ddouble__lp__plus__rp_(x15_20846, _x22754, _ctx); /*std/num/ddouble/ddouble*/
    return kk_std_core_types__new_dash__lp__comma__rp_(kk_std_num_ddouble__ddouble_box(_b_21548_21538, _ctx), kk_std_num_ddouble__ddouble_box(_b_21549_21539, _ctx), _ctx);
  }
  bool _match_21892 = kk_integer_eq(a0,(kk_integer_from_small(-1)),kk_context()); /*bool*/;
  if (_match_21892) {
    kk_std_num_ddouble__ddouble _b_21550_21540;
    kk_std_num_ddouble__ddouble x16_20848 = kk_std_num_ddouble__lp__star__rp_(sins, sinb, _ctx); /*std/num/ddouble/ddouble*/;
    kk_std_num_ddouble__ddouble y10_20849 = kk_std_num_ddouble__lp__star__rp_(coss, cosb, _ctx); /*std/num/ddouble/ddouble*/;
    kk_std_num_ddouble__ddouble _x22755 = kk_std_num_ddouble__lp__tilde__rp_(y10_20849, _ctx); /*std/num/ddouble/ddouble*/
    _b_21550_21540 = kk_std_num_ddouble__lp__plus__rp_(x16_20848, _x22755, _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble _b_21551_21541;
    kk_std_num_ddouble__ddouble _x22756 = kk_std_num_ddouble__lp__star__rp_(coss, sinb, _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble _x22757 = kk_std_num_ddouble__lp__star__rp_(sins, cosb, _ctx); /*std/num/ddouble/ddouble*/
    _b_21551_21541 = kk_std_num_ddouble__lp__plus__rp_(_x22756, _x22757, _ctx); /*std/num/ddouble/ddouble*/
    return kk_std_core_types__new_dash__lp__comma__rp_(kk_std_num_ddouble__ddouble_box(_b_21550_21540, _ctx), kk_std_num_ddouble__ddouble_box(_b_21551_21541, _ctx), _ctx);
  }
  kk_std_num_ddouble__ddouble _b_21552_21542;
  kk_std_num_ddouble__ddouble x17_20850;
  kk_std_num_ddouble__ddouble x6_21120 = kk_std_num_ddouble__lp__tilde__rp_(sins, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__edouble z06;
  double z8;
  double _x22758;
  double _x27 = x6_21120.hi;
  _x22758 = _x27; /*double*/
  double _x22759;
  double _x08 = cosb.hi;
  _x22759 = _x08; /*double*/
  z8 = (_x22758 * _x22759); /*double*/
  double err7;
  double _x22760;
  double _x270 = x6_21120.hi;
  _x22760 = _x270; /*double*/
  double _x22761;
  double _x080 = cosb.hi;
  _x22761 = _x080; /*double*/
  double _x22762 = (-z8); /*double*/
  err7 = kk_std_num_double_fmadd(_x22760, _x22761, _x22762, _ctx); /*double*/
  z06 = kk_std_num_ddouble__new_Edouble(z8, err7, _ctx); /*std/num/ddouble/edouble*/
  double e6;
  double _x22763;
  double _x110 = z06.err;
  _x22763 = _x110; /*double*/
  double _x22764;
  double _x22765;
  double _x22766;
  double _x28 = x6_21120.hi;
  _x22766 = _x28; /*double*/
  double _x22767;
  double _x37 = cosb.lo;
  _x22767 = _x37; /*double*/
  _x22765 = (_x22766 * _x22767); /*double*/
  double _x22768;
  double _x22769;
  double _x47 = x6_21120.lo;
  _x22769 = _x47; /*double*/
  double _x22770;
  double _x57 = cosb.hi;
  _x22770 = _x57; /*double*/
  _x22768 = (_x22769 * _x22770); /*double*/
  _x22764 = (_x22765 + _x22768); /*double*/
  e6 = (_x22763 + _x22764); /*double*/
  bool _match_21893;
  bool _x22771;
  double _x22772;
  double _x65 = z06.num;
  _x22772 = _x65; /*double*/
  _x22771 = isfinite(_x22772); /*bool*/
  _match_21893 = !(_x22771); /*bool*/
  if (_match_21893) {
    double _x22773;
    double _x650 = z06.num;
    _x22773 = _x650; /*double*/
    x17_20850 = kk_std_num_ddouble_ddouble(_x22773, _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    double z16;
    double _x22774;
    double _x651 = z06.num;
    _x22774 = _x651; /*double*/
    z16 = (_x22774 + e6); /*double*/
    double err06;
    double _x22775;
    double _x22776;
    double _x652 = z06.num;
    _x22776 = _x652; /*double*/
    _x22775 = (z16 - _x22776); /*double*/
    err06 = (e6 - _x22775); /*double*/
    double _x22777;
    bool _match_21894 = isfinite(z16); /*bool*/;
    if (_match_21894) {
      _x22777 = err06; /*double*/
    }
    else {
      _x22777 = z16; /*double*/
    }
    x17_20850 = kk_std_num_ddouble__new_Ddouble(z16, _x22777, _ctx); /*std/num/ddouble/ddouble*/
  }
  kk_std_num_ddouble__ddouble y11_20851 = kk_std_num_ddouble__lp__star__rp_(coss, sinb, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__ddouble _x22778 = kk_std_num_ddouble__lp__tilde__rp_(y11_20851, _ctx); /*std/num/ddouble/ddouble*/
  _b_21552_21542 = kk_std_num_ddouble__lp__plus__rp_(x17_20850, _x22778, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _b_21553_21543;
  kk_std_num_ddouble__ddouble x18_20852 = kk_std_num_ddouble__lp__star__rp_(sins, sinb, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__ddouble y12_20853 = kk_std_num_ddouble__lp__star__rp_(coss, cosb, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__ddouble _x22779 = kk_std_num_ddouble__lp__tilde__rp_(y12_20853, _ctx); /*std/num/ddouble/ddouble*/
  _b_21553_21543 = kk_std_num_ddouble__lp__plus__rp_(x18_20852, _x22779, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_core_types__new_dash__lp__comma__rp_(kk_std_num_ddouble__ddouble_box(_b_21552_21542, _ctx), kk_std_num_ddouble__ddouble_box(_b_21553_21543, _ctx), _ctx);
}
 
// Return `x` with the sign of `y`.

kk_std_num_ddouble__ddouble kk_std_num_ddouble_with_sign_of(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_context_t* _ctx) { /* (x : ddouble, y : ddouble) -> ddouble */ 
  bool _match_21888 = kk_std_num_ddouble_is_neg(y, _ctx); /*bool*/;
  if (_match_21888) {
    kk_std_num_ddouble__ddouble x0_20854 = kk_std_num_ddouble_abs(x, _ctx); /*std/num/ddouble/ddouble*/;
    double _x22780;
    double _x22781;
    double _x = x0_20854.hi;
    _x22781 = _x; /*double*/
    _x22780 = (-_x22781); /*double*/
    double _x22782;
    double _x22783;
    double _x0 = x0_20854.lo;
    _x22783 = _x0; /*double*/
    _x22782 = (-_x22783); /*double*/
    return kk_std_num_ddouble__new_Ddouble(_x22780, _x22782, _ctx);
  }
  return kk_std_num_ddouble_abs(x, _ctx);
}
 
// The arc-tangent of a point (`x`,`y`). Returns the angle with respect to the x-axis in radians between -&pi; and &pi;.

kk_std_num_ddouble__ddouble kk_std_num_ddouble_atan2(kk_std_num_ddouble__ddouble y, kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (y : ddouble, x : ddouble) -> ddouble */ 
  bool _match_21872 = kk_std_num_ddouble_is_zero(x, _ctx); /*bool*/;
  if (_match_21872) {
    bool _match_21886 = kk_std_num_ddouble_is_zero(y, _ctx); /*bool*/;
    if (_match_21886) {
      return kk_std_num_ddouble__new_Ddouble(0x0p+0, 0x0p+0, _ctx);
    }
    kk_std_num_ddouble__ddouble x0_21122 = kk_std_num_ddouble__new_Ddouble(0x1.921fb54442d18p0, 0x1.1a62633145c07p-54, _ctx); /*std/num/ddouble/ddouble*/;
    bool _match_21887 = kk_std_num_ddouble_is_neg(y, _ctx); /*bool*/;
    if (_match_21887) {
      kk_std_num_ddouble__ddouble x0_20854 = kk_std_num_ddouble_abs(x0_21122, _ctx); /*std/num/ddouble/ddouble*/;
      double _x22784;
      double _x22785;
      double _x = x0_20854.hi;
      _x22785 = _x; /*double*/
      _x22784 = (-_x22785); /*double*/
      double _x22786;
      double _x22787;
      double _x0 = x0_20854.lo;
      _x22787 = _x0; /*double*/
      _x22786 = (-_x22787); /*double*/
      return kk_std_num_ddouble__new_Ddouble(_x22784, _x22786, _ctx);
    }
    return kk_std_num_ddouble_abs(x0_21122, _ctx);
  }
  bool _match_21873 = kk_std_num_ddouble_is_zero(y, _ctx); /*bool*/;
  if (_match_21873) {
    bool _match_21885 = kk_std_num_ddouble_is_pos(x, _ctx); /*bool*/;
    if (_match_21885) {
      return kk_std_num_ddouble__new_Ddouble(0x0p+0, 0x0p+0, _ctx);
    }
    return kk_std_num_ddouble__new_Ddouble(0x1.921fb54442d18p1, 0x1.1a62633145c07p-53, _ctx);
  }
  bool _match_21874 = kk_std_num_ddouble__lp__eq__eq__rp_(x, y, _ctx); /*bool*/;
  if (_match_21874) {
    bool _match_21884 = kk_std_num_ddouble_is_pos(y, _ctx); /*bool*/;
    if (_match_21884) {
      return kk_std_num_ddouble__new_Ddouble(0x1.921fb54442d18p-1, 0x1.1a62633145c07p-55, _ctx);
    }
    kk_std_num_ddouble__ddouble x1_21124 = kk_std_num_ddouble__new_Ddouble(0x1.2d97c7f3321d2p1, 0x1.a79394c9e8a0bp-54, _ctx); /*std/num/ddouble/ddouble*/;
    double _x22788;
    double _x22789;
    double _x1 = x1_21124.hi;
    _x22789 = _x1; /*double*/
    _x22788 = (-_x22789); /*double*/
    double _x22790;
    double _x22791;
    double _x00 = x1_21124.lo;
    _x22791 = _x00; /*double*/
    _x22790 = (-_x22791); /*double*/
    return kk_std_num_ddouble__new_Ddouble(_x22788, _x22790, _ctx);
  }
  bool _match_21875;
  kk_std_num_ddouble__ddouble y0_20858 = kk_std_num_ddouble__lp__tilde__rp_(y, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_core_types__order x1_20859 = kk_std_num_ddouble_compare(x, y0_20858, _ctx); /*order*/;
  kk_integer_t _x22792 = kk_std_core_int_5(x1_20859, _ctx); /*int*/
  kk_integer_t _x22793;
  kk_std_core_types__order _x22794 = kk_std_core_types__new_Eq(_ctx); /*order*/
  if (kk_std_core_types__is_Lt(_x22794)) {
    _x22793 = kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context()); /*int*/
    goto _match22795;
  }
  if (kk_std_core_types__is_Eq(_x22794)) {
    _x22793 = kk_integer_from_small(0); /*int*/
    goto _match22795;
  }
  _x22793 = kk_integer_from_small(1); /*int*/
  _match22795: ;
  _match_21875 = kk_integer_eq(_x22792,_x22793,kk_context()); /*bool*/
  if (_match_21875) {
    bool _match_21882 = kk_std_num_ddouble_is_pos(y, _ctx); /*bool*/;
    if (_match_21882) {
      return kk_std_num_ddouble__new_Ddouble(0x1.2d97c7f3321d2p1, 0x1.a79394c9e8a0bp-54, _ctx);
    }
    kk_std_num_ddouble__ddouble x3_21126 = kk_std_num_ddouble__new_Ddouble(0x1.921fb54442d18p-1, 0x1.1a62633145c07p-55, _ctx); /*std/num/ddouble/ddouble*/;
    double _x22796;
    double _x22797;
    double _x2 = x3_21126.hi;
    _x22797 = _x2; /*double*/
    _x22796 = (-_x22797); /*double*/
    double _x22798;
    double _x22799;
    double _x01 = x3_21126.lo;
    _x22799 = _x01; /*double*/
    _x22798 = (-_x22799); /*double*/
    return kk_std_num_ddouble__new_Ddouble(_x22796, _x22798, _ctx);
  }
  kk_std_num_ddouble__ddouble r;
  kk_std_num_ddouble__ddouble x2_20861;
  kk_std_num_ddouble__ddouble _x22800 = kk_std_num_ddouble_sqr(x, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x22801 = kk_std_num_ddouble_sqr(y, _ctx); /*std/num/ddouble/ddouble*/
  x2_20861 = kk_std_num_ddouble__lp__plus__rp_(_x22800, _x22801, _ctx); /*std/num/ddouble/ddouble*/
  bool _match_21878 = kk_std_num_ddouble_is_zero(x2_20861, _ctx); /*bool*/;
  if (_match_21878) {
    r = kk_std_num_ddouble__new_Ddouble(0x0p+0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    bool _match_21879 = kk_std_num_ddouble_is_neg(x2_20861, _ctx); /*bool*/;
    if (_match_21879) {
      r = kk_std_num_ddouble_dd_nan; /*std/num/ddouble/ddouble*/
    }
    else {
      double a;
      double _x22802;
      double _x22803;
      double _x3 = x2_20861.hi;
      _x22803 = _x3; /*double*/
      _x22802 = sqrt(_x22803); /*double*/
      a = (0x1p0 / _x22802); /*double*/
      double t1;
      double _x22804;
      double _x02 = x2_20861.hi;
      _x22804 = _x02; /*double*/
      t1 = (_x22804 * a); /*double*/
      double t2;
      double _x22805;
      double _x22806;
      kk_std_num_ddouble__ddouble ddouble1_20864;
      kk_std_num_ddouble__ddouble y2_20866;
      kk_std_num_ddouble__ddouble x4_21127 = kk_std_num_ddouble_ddouble(t1, _ctx); /*std/num/ddouble/ddouble*/;
      kk_std_num_ddouble__edouble z0;
      double z;
      double _x22807;
      double _x4 = x4_21127.hi;
      _x22807 = _x4; /*double*/
      double _x22808;
      double _x40 = x4_21127.hi;
      _x22808 = _x40; /*double*/
      z = (_x22807 * _x22808); /*double*/
      double err0;
      double _x22809;
      double _x41 = x4_21127.hi;
      _x22809 = _x41; /*double*/
      double _x22810;
      double _x42 = x4_21127.hi;
      _x22810 = _x42; /*double*/
      double _x22811 = (-z); /*double*/
      err0 = kk_std_num_double_fmadd(_x22809, _x22810, _x22811, _ctx); /*double*/
      z0 = kk_std_num_ddouble__new_Edouble(z, err0, _ctx); /*std/num/ddouble/edouble*/
      double e;
      double _x22812;
      double _x22813;
      double _x03 = z0.err;
      _x22813 = _x03; /*double*/
      double _x22814;
      double _x22815;
      double _x22816;
      double _x10 = x4_21127.hi;
      _x22816 = _x10; /*double*/
      _x22815 = (0x1p1 * _x22816); /*double*/
      double _x22817;
      double _x20 = x4_21127.lo;
      _x22817 = _x20; /*double*/
      _x22814 = (_x22815 * _x22817); /*double*/
      _x22812 = (_x22813 + _x22814); /*double*/
      double _x22818;
      double _x22819;
      double _x30 = x4_21127.lo;
      _x22819 = _x30; /*double*/
      double _x22820;
      double _x400 = x4_21127.lo;
      _x22820 = _x400; /*double*/
      _x22818 = (_x22819 * _x22820); /*double*/
      e = (_x22812 + _x22818); /*double*/
      bool _match_21880;
      bool _x22821;
      double _x22822;
      double _x5 = z0.num;
      _x22822 = _x5; /*double*/
      _x22821 = isfinite(_x22822); /*bool*/
      _match_21880 = !(_x22821); /*bool*/
      if (_match_21880) {
        double _x22823;
        double _x50 = z0.num;
        _x22823 = _x50; /*double*/
        y2_20866 = kk_std_num_ddouble_ddouble(_x22823, _ctx); /*std/num/ddouble/ddouble*/
      }
      else {
        double z1;
        double _x22824;
        double _x51 = z0.num;
        _x22824 = _x51; /*double*/
        z1 = (_x22824 + e); /*double*/
        double err00;
        double _x22825;
        double _x22826;
        double _x52 = z0.num;
        _x22826 = _x52; /*double*/
        _x22825 = (z1 - _x22826); /*double*/
        err00 = (e - _x22825); /*double*/
        double _x22827;
        bool _match_21881 = isfinite(z1); /*bool*/;
        if (_match_21881) {
          _x22827 = err00; /*double*/
        }
        else {
          _x22827 = z1; /*double*/
        }
        y2_20866 = kk_std_num_ddouble__new_Ddouble(z1, _x22827, _ctx); /*std/num/ddouble/ddouble*/
      }
      kk_std_num_ddouble__ddouble _x22828 = kk_std_num_ddouble__lp__tilde__rp_(y2_20866, _ctx); /*std/num/ddouble/ddouble*/
      ddouble1_20864 = kk_std_num_ddouble__lp__plus__rp_(x2_20861, _x22828, _ctx); /*std/num/ddouble/ddouble*/
      double _x11 = ddouble1_20864.hi;
      _x22806 = _x11; /*double*/
      _x22805 = (_x22806 * a); /*double*/
      t2 = (_x22805 * (0x1p-1)); /*double*/
      r = kk_std_num_ddouble_dsum(t1, t2, _ctx); /*std/num/ddouble/ddouble*/
    }
  }
  kk_std_num_ddouble__ddouble xr = kk_std_num_ddouble__lp__fs__rp_(x, r, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__ddouble yr = kk_std_num_ddouble__lp__fs__rp_(y, r, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__ddouble z2;
  double d_20867;
  double _x22829;
  double _x6 = y.hi;
  _x22829 = _x6; /*double*/
  double _x22830;
  double _x7 = x.hi;
  _x22830 = _x7; /*double*/
  d_20867 = atan2(_x22829,_x22830); /*double*/
  z2 = kk_std_num_ddouble__new_Ddouble(d_20867, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_core_types__tuple2_ _match_21876 = kk_std_num_ddouble_sincos(z2, _ctx); /*(std/num/ddouble/ddouble, std/num/ddouble/ddouble)*/;
  kk_box_t _box_x21554 = _match_21876.fst;
  kk_box_t _box_x21555 = _match_21876.snd;
  kk_std_num_ddouble__ddouble sinz = kk_std_num_ddouble__ddouble_unbox(_box_x21554, NULL);
  kk_std_num_ddouble__ddouble cosz = kk_std_num_ddouble__ddouble_unbox(_box_x21555, NULL);
  kk_std_core_types__tuple2__drop(_match_21876, _ctx);
  bool _match_21877;
  double _x22833;
  double _x22834;
  double _x21 = xr.hi;
  _x22834 = _x21; /*double*/
  _x22833 = kk_double_abs(_x22834); /*double*/
  double _x22835;
  kk_std_num_ddouble__ddouble ddouble3_20869 = kk_std_num_ddouble_abs(yr, _ctx); /*std/num/ddouble/ddouble*/;
  double _x31 = ddouble3_20869.hi;
  _x22835 = _x31; /*double*/
  _match_21877 = (_x22833 > _x22835); /*bool*/
  if (_match_21877) {
    kk_std_num_ddouble__ddouble _x22836;
    kk_std_num_ddouble__ddouble _x22837 = kk_std_num_ddouble__lp__dash__rp_(yr, sinz, _ctx); /*std/num/ddouble/ddouble*/
    _x22836 = kk_std_num_ddouble__lp__fs__rp_(_x22837, cosz, _ctx); /*std/num/ddouble/ddouble*/
    return kk_std_num_ddouble__lp__plus__rp_(z2, _x22836, _ctx);
  }
  kk_std_num_ddouble__ddouble y3_20871;
  kk_std_num_ddouble__ddouble _x22838 = kk_std_num_ddouble__lp__dash__rp_(xr, cosz, _ctx); /*std/num/ddouble/ddouble*/
  y3_20871 = kk_std_num_ddouble__lp__fs__rp_(_x22838, sinz, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x22839 = kk_std_num_ddouble__lp__tilde__rp_(y3_20871, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__lp__plus__rp_(z2, _x22839, _ctx);
}
 
// The arc-cosine of `x`. Returns the angle in radians.

kk_std_num_ddouble__ddouble kk_std_num_ddouble_acos(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> ddouble */ 
  kk_std_num_ddouble__ddouble a = kk_std_num_ddouble_abs(x, _ctx); /*std/num/ddouble/ddouble*/;
  bool _match_21865;
  kk_std_num_ddouble__ddouble _x22840 = kk_std_num_ddouble__new_Ddouble(0x1p0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  _match_21865 = kk_std_num_ddouble__lp__gt__rp_(a, _x22840, _ctx); /*bool*/
  if (_match_21865) {
    return kk_std_num_ddouble_dd_nan;
  }
  bool _match_21866;
  kk_std_num_ddouble__ddouble _x22841 = kk_std_num_ddouble__new_Ddouble(0x1p0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  _match_21866 = kk_std_num_ddouble__lp__eq__eq__rp_(a, _x22841, _ctx); /*bool*/
  if (_match_21866) {
    bool _match_21871 = kk_std_num_ddouble_is_pos(x, _ctx); /*bool*/;
    if (_match_21871) {
      return kk_std_num_ddouble__new_Ddouble(0x0p+0, 0x0p+0, _ctx);
    }
    return kk_std_num_ddouble__new_Ddouble(0x1.921fb54442d18p1, 0x1.1a62633145c07p-53, _ctx);
  }
  kk_std_num_ddouble__ddouble _x22842;
  kk_std_num_ddouble__ddouble x0_20872;
  kk_std_num_ddouble__ddouble y0_20874 = kk_std_num_ddouble_sqr(x, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__ddouble _x22843 = kk_std_num_ddouble__new_Ddouble(0x1p0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x22844 = kk_std_num_ddouble__lp__tilde__rp_(y0_20874, _ctx); /*std/num/ddouble/ddouble*/
  x0_20872 = kk_std_num_ddouble__lp__plus__rp_(_x22843, _x22844, _ctx); /*std/num/ddouble/ddouble*/
  bool _match_21867 = kk_std_num_ddouble_is_zero(x0_20872, _ctx); /*bool*/;
  if (_match_21867) {
    _x22842 = kk_std_num_ddouble__new_Ddouble(0x0p+0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    bool _match_21868 = kk_std_num_ddouble_is_neg(x0_20872, _ctx); /*bool*/;
    if (_match_21868) {
      _x22842 = kk_std_num_ddouble_dd_nan; /*std/num/ddouble/ddouble*/
    }
    else {
      double a0;
      double _x22845;
      double _x22846;
      double _x = x0_20872.hi;
      _x22846 = _x; /*double*/
      _x22845 = sqrt(_x22846); /*double*/
      a0 = (0x1p0 / _x22845); /*double*/
      double t1;
      double _x22847;
      double _x0 = x0_20872.hi;
      _x22847 = _x0; /*double*/
      t1 = (_x22847 * a0); /*double*/
      double t2;
      double _x22848;
      double _x22849;
      kk_std_num_ddouble__ddouble ddouble1_20877;
      kk_std_num_ddouble__ddouble y_20879;
      kk_std_num_ddouble__ddouble x0_21130 = kk_std_num_ddouble_ddouble(t1, _ctx); /*std/num/ddouble/ddouble*/;
      kk_std_num_ddouble__edouble z0;
      double z;
      double _x22850;
      double _x1 = x0_21130.hi;
      _x22850 = _x1; /*double*/
      double _x22851;
      double _x10 = x0_21130.hi;
      _x22851 = _x10; /*double*/
      z = (_x22850 * _x22851); /*double*/
      double err0;
      double _x22852;
      double _x11 = x0_21130.hi;
      _x22852 = _x11; /*double*/
      double _x22853;
      double _x12 = x0_21130.hi;
      _x22853 = _x12; /*double*/
      double _x22854 = (-z); /*double*/
      err0 = kk_std_num_double_fmadd(_x22852, _x22853, _x22854, _ctx); /*double*/
      z0 = kk_std_num_ddouble__new_Edouble(z, err0, _ctx); /*std/num/ddouble/edouble*/
      double e;
      double _x22855;
      double _x22856;
      double _x00 = z0.err;
      _x22856 = _x00; /*double*/
      double _x22857;
      double _x22858;
      double _x22859;
      double _x100 = x0_21130.hi;
      _x22859 = _x100; /*double*/
      _x22858 = (0x1p1 * _x22859); /*double*/
      double _x22860;
      double _x2 = x0_21130.lo;
      _x22860 = _x2; /*double*/
      _x22857 = (_x22858 * _x22860); /*double*/
      _x22855 = (_x22856 + _x22857); /*double*/
      double _x22861;
      double _x22862;
      double _x3 = x0_21130.lo;
      _x22862 = _x3; /*double*/
      double _x22863;
      double _x4 = x0_21130.lo;
      _x22863 = _x4; /*double*/
      _x22861 = (_x22862 * _x22863); /*double*/
      e = (_x22855 + _x22861); /*double*/
      bool _match_21869;
      bool _x22864;
      double _x22865;
      double _x5 = z0.num;
      _x22865 = _x5; /*double*/
      _x22864 = isfinite(_x22865); /*bool*/
      _match_21869 = !(_x22864); /*bool*/
      if (_match_21869) {
        double _x22866;
        double _x50 = z0.num;
        _x22866 = _x50; /*double*/
        y_20879 = kk_std_num_ddouble_ddouble(_x22866, _ctx); /*std/num/ddouble/ddouble*/
      }
      else {
        double z1;
        double _x22867;
        double _x51 = z0.num;
        _x22867 = _x51; /*double*/
        z1 = (_x22867 + e); /*double*/
        double err00;
        double _x22868;
        double _x22869;
        double _x52 = z0.num;
        _x22869 = _x52; /*double*/
        _x22868 = (z1 - _x22869); /*double*/
        err00 = (e - _x22868); /*double*/
        double _x22870;
        bool _match_21870 = isfinite(z1); /*bool*/;
        if (_match_21870) {
          _x22870 = err00; /*double*/
        }
        else {
          _x22870 = z1; /*double*/
        }
        y_20879 = kk_std_num_ddouble__new_Ddouble(z1, _x22870, _ctx); /*std/num/ddouble/ddouble*/
      }
      kk_std_num_ddouble__ddouble _x22871 = kk_std_num_ddouble__lp__tilde__rp_(y_20879, _ctx); /*std/num/ddouble/ddouble*/
      ddouble1_20877 = kk_std_num_ddouble__lp__plus__rp_(x0_20872, _x22871, _ctx); /*std/num/ddouble/ddouble*/
      double _x110 = ddouble1_20877.hi;
      _x22849 = _x110; /*double*/
      _x22848 = (_x22849 * a0); /*double*/
      t2 = (_x22848 * (0x1p-1)); /*double*/
      _x22842 = kk_std_num_ddouble_dsum(t1, t2, _ctx); /*std/num/ddouble/ddouble*/
    }
  }
  return kk_std_num_ddouble_atan2(_x22842, x, _ctx);
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble_dd_e;
 
// Negative infinity

kk_std_num_ddouble__ddouble kk_std_num_ddouble_dd_neginf;

kk_std_num_ddouble__ddouble kk_std_num_ddouble_dd_epsilon;

kk_std_num_ddouble__ddouble kk_std_num_ddouble_dd_log2;
 
// Positive infinity

kk_std_num_ddouble__ddouble kk_std_num_ddouble_dd_posinf;

kk_std_num_ddouble__ddouble kk_std_num_ddouble_exp_approx(kk_std_num_ddouble__ddouble p, kk_std_num_ddouble__ddouble t, kk_std_num_ddouble__ddouble r, double eps, kk_std_core__list fs, kk_std_core_types__optional s, kk_context_t* _ctx) { /* (p : ddouble, t : ddouble, r : ddouble, eps : double, fs : list<ddouble>, s : optional<ddouble>) -> ddouble */ 
  kk__tailcall: ;
  if (kk_std_core__is_Nil(fs)) {
    kk_std_num_ddouble__ddouble _x22874;
    if (kk_std_core_types__is_Optional(s)) {
      kk_box_t _box_x21556 = s._cons.Optional.value;
      kk_std_num_ddouble__ddouble _s_9774 = kk_std_num_ddouble__ddouble_unbox(_box_x21556, NULL);
      kk_std_core_types__optional_drop(s, _ctx);
      _x22874 = _s_9774; /*std/num/ddouble/ddouble*/
      goto _match22875;
    }
    _x22874 = kk_std_num_ddouble__new_Ddouble(0x0p+0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    _match22875: ;
    return kk_std_num_ddouble__lp__plus__rp_(_x22874, t, _ctx);
  }
  struct kk_std_core_Cons* _con22877 = kk_std_core__as_Cons(fs);
  kk_box_t _box_x21557 = _con22877->head;
  kk_std_core__list fs1 = _con22877->tail;
  kk_std_num_ddouble__ddouble f = kk_std_num_ddouble__ddouble_unbox(_box_x21557, NULL);
  if (kk_std_core__list_is_unique(fs)) {
    kk_box_drop(_box_x21557, _ctx);
    kk_std_core__list_free(fs);
  }
  else {
    kk_std_core__list_dup(fs1);
    kk_std_core__list_decref(fs, _ctx);
  }
  kk_std_num_ddouble__ddouble s1;
  kk_std_num_ddouble__ddouble _x22879;
  if (kk_std_core_types__is_Optional(s)) {
    kk_box_t _box_x21558 = s._cons.Optional.value;
    kk_std_num_ddouble__ddouble _s_97740 = kk_std_num_ddouble__ddouble_unbox(_box_x21558, NULL);
    _x22879 = _s_97740; /*std/num/ddouble/ddouble*/
    goto _match22880;
  }
  _x22879 = kk_std_num_ddouble__new_Ddouble(0x0p+0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  _match22880: ;
  s1 = kk_std_num_ddouble__lp__plus__rp_(_x22879, t, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble p1 = kk_std_num_ddouble__lp__star__rp_(p, r, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__ddouble t1 = kk_std_num_ddouble__lp__star__rp_(p1, f, _ctx); /*std/num/ddouble/ddouble*/;
  bool _match_21864;
  double _x22882;
  double _x22883;
  double _x = t1.hi;
  _x22883 = _x; /*double*/
  _x22882 = kk_double_abs(_x22883); /*double*/
  _match_21864 = (_x22882 <= eps); /*bool*/
  if (_match_21864) {
    kk_std_core__list_drop(fs1, _ctx);
    kk_std_num_ddouble__ddouble _x22884;
    if (kk_std_core_types__is_Optional(s)) {
      kk_box_t _box_x21559 = s._cons.Optional.value;
      kk_std_num_ddouble__ddouble _s_97741 = kk_std_num_ddouble__ddouble_unbox(_box_x21559, NULL);
      kk_std_core_types__optional_drop(s, _ctx);
      _x22884 = _s_97741; /*std/num/ddouble/ddouble*/
      goto _match22885;
    }
    _x22884 = kk_std_num_ddouble__new_Ddouble(0x0p+0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    _match22885: ;
    return kk_std_num_ddouble__lp__plus__rp_(_x22884, t, _ctx);
  }
  kk_std_core_types__optional_drop(s, _ctx);
  { // tailcall
    kk_std_core_types__optional _x22887 = kk_std_core_types__new_Optional(kk_std_num_ddouble__ddouble_box(s1, _ctx), _ctx); /*optional<35>*/
    p = p1;
    t = t1;
    fs = fs1;
    s = _x22887;
    goto kk__tailcall;
  }
}

kk_std_core__list kk_std_num_ddouble_exp_factors;
 
// Round to negative infinity.

kk_std_num_ddouble__ddouble kk_std_num_ddouble_floor(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> ddouble */ 
  double r;
  double _x22888;
  double _x = x.hi;
  _x22888 = _x; /*double*/
  r = floor(_x22888); /*double*/
  bool _match_21861;
  double _x22889;
  double _x0 = x.hi;
  _x22889 = _x0; /*double*/
  _match_21861 = (r == _x22889); /*bool*/
  if (_match_21861) {
    double y_20883;
    double _x22890;
    double _x1 = x.lo;
    _x22890 = _x1; /*double*/
    y_20883 = floor(_x22890); /*double*/
    bool _match_21862;
    bool _x22891 = isfinite(r); /*bool*/
    _match_21862 = !(_x22891); /*bool*/
    if (_match_21862) {
      return kk_std_num_ddouble_ddouble(r, _ctx);
    }
    double z = (r + y_20883); /*double*/;
    double err0;
    double _x22892 = (z - r); /*double*/
    err0 = (y_20883 - _x22892); /*double*/
    double _x22893;
    bool _match_21863 = isfinite(z); /*bool*/;
    if (_match_21863) {
      _x22893 = err0; /*double*/
    }
    else {
      _x22893 = z; /*double*/
    }
    return kk_std_num_ddouble__new_Ddouble(z, _x22893, _ctx);
  }
  return kk_std_num_ddouble__new_Ddouble(r, 0x0p+0, _ctx);
}
 
// Return _e_ (`dd-e`) to the power of `x`.


// lift anonymous function
struct kk_std_num_ddouble_exp_fun22950__t {
  struct kk_function_s _base;
  kk_ref_t loc;
};
static kk_unit_t kk_std_num_ddouble_exp_fun22950(kk_function_t _fself, kk_integer_t i, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble_new_exp_fun22950(kk_ref_t loc, kk_context_t* _ctx) {
  struct kk_std_num_ddouble_exp_fun22950__t* _self = kk_function_alloc_as(struct kk_std_num_ddouble_exp_fun22950__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_num_ddouble_exp_fun22950, kk_context());
  _self->loc = loc;
  return &_self->_base;
}

static kk_unit_t kk_std_num_ddouble_exp_fun22950(kk_function_t _fself, kk_integer_t i, kk_context_t* _ctx) {
  struct kk_std_num_ddouble_exp_fun22950__t* _self = kk_function_as(struct kk_std_num_ddouble_exp_fun22950__t*, _fself);
  kk_ref_t loc = _self->loc; /* local-var<global,std/num/ddouble/ddouble> */
  kk_drop_match(_self, {kk_ref_dup(loc);}, {}, _ctx)
  kk_integer_drop(i, _ctx);
  kk_std_num_ddouble__ddouble _b_21595_21593;
  kk_std_num_ddouble__ddouble _x22951;
  kk_std_num_ddouble__ddouble x2_20914;
  kk_box_t _x22952;
  kk_ref_t _x22953 = kk_ref_dup(loc); /*local-var<global,std/num/ddouble/ddouble>*/
  _x22952 = (kk_ref_get(_x22953,kk_context())); /*0*/
  x2_20914 = kk_std_num_ddouble__ddouble_unbox(_x22952, _ctx); /*std/num/ddouble/ddouble*/
  double _x22954;
  double _x22955;
  double _x600 = x2_20914.hi;
  _x22955 = _x600; /*double*/
  _x22954 = (_x22955 * 0x1p1); /*double*/
  double _x22956;
  double _x22957;
  double _x7 = x2_20914.lo;
  _x22957 = _x7; /*double*/
  _x22956 = (_x22957 * 0x1p1); /*double*/
  _x22951 = kk_std_num_ddouble__new_Ddouble(_x22954, _x22956, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x22958;
  kk_std_num_ddouble__ddouble x1_21134;
  kk_box_t _x22959;
  kk_ref_t _x22960 = kk_ref_dup(loc); /*local-var<global,std/num/ddouble/ddouble>*/
  _x22959 = (kk_ref_get(_x22960,kk_context())); /*0*/
  x1_21134 = kk_std_num_ddouble__ddouble_unbox(_x22959, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__edouble z00;
  double z2;
  double _x22961;
  double _x8 = x1_21134.hi;
  _x22961 = _x8; /*double*/
  double _x22962;
  double _x80 = x1_21134.hi;
  _x22962 = _x80; /*double*/
  z2 = (_x22961 * _x22962); /*double*/
  double err1;
  double _x22963;
  double _x81 = x1_21134.hi;
  _x22963 = _x81; /*double*/
  double _x22964;
  double _x82 = x1_21134.hi;
  _x22964 = _x82; /*double*/
  double _x22965 = (-z2); /*double*/
  err1 = kk_std_num_double_fmadd(_x22963, _x22964, _x22965, _ctx); /*double*/
  z00 = kk_std_num_ddouble__new_Edouble(z2, err1, _ctx); /*std/num/ddouble/edouble*/
  double e0;
  double _x22966;
  double _x22967;
  double _x01 = z00.err;
  _x22967 = _x01; /*double*/
  double _x22968;
  double _x22969;
  double _x22970;
  double _x11 = x1_21134.hi;
  _x22970 = _x11; /*double*/
  _x22969 = (0x1p1 * _x22970); /*double*/
  double _x22971;
  double _x21 = x1_21134.lo;
  _x22971 = _x21; /*double*/
  _x22968 = (_x22969 * _x22971); /*double*/
  _x22966 = (_x22967 + _x22968); /*double*/
  double _x22972;
  double _x22973;
  double _x32 = x1_21134.lo;
  _x22973 = _x32; /*double*/
  double _x22974;
  double _x41 = x1_21134.lo;
  _x22974 = _x41; /*double*/
  _x22972 = (_x22973 * _x22974); /*double*/
  e0 = (_x22966 + _x22972); /*double*/
  bool _match_21857;
  bool _x22975;
  double _x22976;
  double _x51 = z00.num;
  _x22976 = _x51; /*double*/
  _x22975 = isfinite(_x22976); /*bool*/
  _match_21857 = !(_x22975); /*bool*/
  if (_match_21857) {
    double _x22977;
    double _x510 = z00.num;
    _x22977 = _x510; /*double*/
    _x22958 = kk_std_num_ddouble_ddouble(_x22977, _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    double z10;
    double _x22978;
    double _x511 = z00.num;
    _x22978 = _x511; /*double*/
    z10 = (_x22978 + e0); /*double*/
    double err000;
    double _x22979;
    double _x22980;
    double _x512 = z00.num;
    _x22980 = _x512; /*double*/
    _x22979 = (z10 - _x22980); /*double*/
    err000 = (e0 - _x22979); /*double*/
    double _x22981;
    bool _match_21858 = isfinite(z10); /*bool*/;
    if (_match_21858) {
      _x22981 = err000; /*double*/
    }
    else {
      _x22981 = z10; /*double*/
    }
    _x22958 = kk_std_num_ddouble__new_Ddouble(z10, _x22981, _ctx); /*std/num/ddouble/ddouble*/
  }
  _b_21595_21593 = kk_std_num_ddouble__lp__plus__rp_(_x22951, _x22958, _ctx); /*std/num/ddouble/ddouble*/
  return (kk_ref_set(loc,(kk_std_num_ddouble__ddouble_box(_b_21595_21593, _ctx)),kk_context()));
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble_exp(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> ddouble */ 
  double inv_k = (0x1p0 / 0x1p9); /*double*/;
  bool _match_21853;
  double _x22911;
  double _x = x.hi;
  _x22911 = _x; /*double*/
  _match_21853 = (_x22911 <= (-0x1.628p9)); /*bool*/
  if (_match_21853) {
    return kk_std_num_ddouble__new_Ddouble(0x0p+0, 0x0p+0, _ctx);
  }
  bool _match_21854;
  double _x22912;
  double _x0 = x.hi;
  _x22912 = _x0; /*double*/
  _match_21854 = (_x22912 >= (0x1.628p9)); /*bool*/
  if (_match_21854) {
    return kk_std_num_ddouble_dd_posinf;
  }
  bool _match_21855 = kk_std_num_ddouble_is_zero(x, _ctx); /*bool*/;
  if (_match_21855) {
    return kk_std_num_ddouble__new_Ddouble(0x1p0, 0x0p+0, _ctx);
  }
  bool _match_21856;
  kk_std_num_ddouble__ddouble _x22913 = kk_std_num_ddouble__new_Ddouble(0x1p0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  _match_21856 = kk_std_num_ddouble__lp__eq__eq__rp_(x, _x22913, _ctx); /*bool*/
  if (_match_21856) {
    return kk_std_num_ddouble__new_Ddouble(0x1.5bf0a8b145769p1, 0x1.4d57ee2b1013ap-53, _ctx);
  }
  kk_integer_t m;
  double _x22914;
  double _x22915;
  double _x22916;
  double _x22917;
  double _x1 = x.hi;
  _x22917 = _x1; /*double*/
  double _x22918;
  kk_std_num_ddouble__ddouble ddouble2_20901 = kk_std_num_ddouble__new_Ddouble(0x1.62e42fefa39efp-1, 0x1.abc9e3b39803fp-56, _ctx); /*std/num/ddouble/ddouble*/;
  double _x2 = ddouble2_20901.hi;
  _x22918 = _x2; /*double*/
  _x22916 = (_x22917 / _x22918); /*double*/
  _x22915 = (_x22916 + (0x1p-1)); /*double*/
  _x22914 = floor(_x22915); /*double*/
  m = kk_integer_from_double(_x22914,kk_context()); /*int*/
  kk_std_num_ddouble__ddouble r;
  kk_std_num_ddouble__ddouble x0_20902;
  kk_std_num_ddouble__ddouble y_20905;
  kk_std_num_ddouble__ddouble x0_21132;
  kk_integer_t _x22919 = kk_integer_dup(m); /*int*/
  x0_21132 = kk_std_num_ddouble_ddouble_1(_x22919, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble y_21133 = kk_std_num_ddouble__new_Ddouble(0x1.62e42fefa39efp-1, 0x1.abc9e3b39803fp-56, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__edouble z0;
  double z;
  double _x22920;
  double _x3 = x0_21132.hi;
  _x22920 = _x3; /*double*/
  double _x22921;
  double _x00 = y_21133.hi;
  _x22921 = _x00; /*double*/
  z = (_x22920 * _x22921); /*double*/
  double err0;
  double _x22922;
  double _x30 = x0_21132.hi;
  _x22922 = _x30; /*double*/
  double _x22923;
  double _x000 = y_21133.hi;
  _x22923 = _x000; /*double*/
  double _x22924 = (-z); /*double*/
  err0 = kk_std_num_double_fmadd(_x22922, _x22923, _x22924, _ctx); /*double*/
  z0 = kk_std_num_ddouble__new_Edouble(z, err0, _ctx); /*std/num/ddouble/edouble*/
  double e;
  double _x22925;
  double _x10 = z0.err;
  _x22925 = _x10; /*double*/
  double _x22926;
  double _x22927;
  double _x22928;
  double _x20 = x0_21132.hi;
  _x22928 = _x20; /*double*/
  double _x22929;
  double _x300 = y_21133.lo;
  _x22929 = _x300; /*double*/
  _x22927 = (_x22928 * _x22929); /*double*/
  double _x22930;
  double _x22931;
  double _x4 = x0_21132.lo;
  _x22931 = _x4; /*double*/
  double _x22932;
  double _x5 = y_21133.hi;
  _x22932 = _x5; /*double*/
  _x22930 = (_x22931 * _x22932); /*double*/
  _x22926 = (_x22927 + _x22930); /*double*/
  e = (_x22925 + _x22926); /*double*/
  bool _match_21859;
  bool _x22933;
  double _x22934;
  double _x6 = z0.num;
  _x22934 = _x6; /*double*/
  _x22933 = isfinite(_x22934); /*bool*/
  _match_21859 = !(_x22933); /*bool*/
  if (_match_21859) {
    double _x22935;
    double _x60 = z0.num;
    _x22935 = _x60; /*double*/
    y_20905 = kk_std_num_ddouble_ddouble(_x22935, _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    double z1;
    double _x22936;
    double _x61 = z0.num;
    _x22936 = _x61; /*double*/
    z1 = (_x22936 + e); /*double*/
    double err00;
    double _x22937;
    double _x22938;
    double _x62 = z0.num;
    _x22938 = _x62; /*double*/
    _x22937 = (z1 - _x22938); /*double*/
    err00 = (e - _x22937); /*double*/
    double _x22939;
    bool _match_21860 = isfinite(z1); /*bool*/;
    if (_match_21860) {
      _x22939 = err00; /*double*/
    }
    else {
      _x22939 = z1; /*double*/
    }
    y_20905 = kk_std_num_ddouble__new_Ddouble(z1, _x22939, _ctx); /*std/num/ddouble/ddouble*/
  }
  kk_std_num_ddouble__ddouble _x22940 = kk_std_num_ddouble__lp__tilde__rp_(y_20905, _ctx); /*std/num/ddouble/ddouble*/
  x0_20902 = kk_std_num_ddouble__lp__plus__rp_(x, _x22940, _ctx); /*std/num/ddouble/ddouble*/
  double _x22941;
  double _x22942;
  double _x31 = x0_20902.hi;
  _x22942 = _x31; /*double*/
  _x22941 = (_x22942 * inv_k); /*double*/
  double _x22943;
  double _x22944;
  double _x40 = x0_20902.lo;
  _x22944 = _x40; /*double*/
  _x22943 = (_x22944 * inv_k); /*double*/
  r = kk_std_num_ddouble__new_Ddouble(_x22941, _x22943, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble p0 = kk_std_num_ddouble_sqr(r, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__ddouble t;
  kk_std_num_ddouble__ddouble _x22945 = kk_std_num_ddouble_half(p0, _ctx); /*std/num/ddouble/ddouble*/
  t = kk_std_num_ddouble__lp__plus__rp_(r, _x22945, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble init_20908;
  double _x22946;
  double _x22947;
  kk_std_num_ddouble__ddouble ddouble5_20910 = kk_std_num_ddouble__new_Ddouble(0x1p-104, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/;
  double _x50 = ddouble5_20910.hi;
  _x22947 = _x50; /*double*/
  _x22946 = (inv_k * _x22947); /*double*/
  kk_std_core__list _x22948 = kk_std_core__list_dup(kk_std_num_ddouble_exp_factors); /*list<std/num/ddouble/ddouble>*/
  init_20908 = kk_std_num_ddouble_exp_approx(p0, t, r, _x22946, _x22948, kk_std_core_types__new_None(_ctx), _ctx); /*std/num/ddouble/ddouble*/
  kk_ref_t loc = kk_ref_alloc((kk_std_num_ddouble__ddouble_box(init_20908, _ctx)),kk_context()); /*local-var<global,std/num/ddouble/ddouble>*/;
  kk_std_num_ddouble__ddouble res;
  kk_unit_t __ = kk_Unit;
  kk_function_t _x22949;
  kk_ref_dup(loc);
  _x22949 = kk_std_num_ddouble_new_exp_fun22950(loc, _ctx); /*(i : int) -> (local<global>) ()*/
  kk_std_core__lift21056_for(_x22949, kk_integer_from_small(9), kk_integer_from_small(1), _ctx);
  kk_unit_t __0 = kk_Unit;
  kk_std_num_ddouble__ddouble _b_21600_21598;
  kk_std_num_ddouble__ddouble _x22982;
  kk_box_t _x22983;
  kk_ref_t _x22984 = kk_ref_dup(loc); /*local-var<global,std/num/ddouble/ddouble>*/
  _x22983 = (kk_ref_get(_x22984,kk_context())); /*0*/
  _x22982 = kk_std_num_ddouble__ddouble_unbox(_x22983, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x22985 = kk_std_num_ddouble__new_Ddouble(0x1p0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  _b_21600_21598 = kk_std_num_ddouble__lp__plus__rp_(_x22982, _x22985, _ctx); /*std/num/ddouble/ddouble*/
  kk_ref_t _x22986 = kk_ref_dup(loc); /*local-var<global,std/num/ddouble/ddouble>*/
  (kk_ref_set(_x22986,(kk_std_num_ddouble__ddouble_box(_b_21600_21598, _ctx)),kk_context()));
  kk_std_num_ddouble__ddouble x4_20919;
  kk_box_t _x22987;
  kk_ref_t _x22988 = kk_ref_dup(loc); /*local-var<global,std/num/ddouble/ddouble>*/
  _x22987 = (kk_ref_get(_x22988,kk_context())); /*0*/
  x4_20919 = kk_std_num_ddouble__ddouble_unbox(_x22987, _ctx); /*std/num/ddouble/ddouble*/
  double _x22989;
  double _x22990;
  double _x800 = x4_20919.hi;
  _x22990 = _x800; /*double*/
  kk_integer_t _x22991 = kk_integer_dup(m); /*int*/
  _x22989 = kk_std_num_double_ldexp(_x22990, _x22991, _ctx); /*double*/
  double _x22992;
  double _x22993;
  double _x9 = x4_20919.lo;
  _x22993 = _x9; /*double*/
  _x22992 = kk_std_num_double_ldexp(_x22993, m, _ctx); /*double*/
  res = kk_std_num_ddouble__new_Ddouble(_x22989, _x22992, _ctx); /*std/num/ddouble/ddouble*/
  kk_box_t _x22994 = kk_std_core_hnd_prompt_local_var(loc, kk_std_num_ddouble__ddouble_box(res, _ctx), _ctx); /*2*/
  return kk_std_num_ddouble__ddouble_unbox(_x22994, _ctx);
}
 
// The natural logarithm (in base _e_) of `x`.

kk_std_num_ddouble__ddouble kk_std_num_ddouble_log(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> ddouble */ 
  bool _match_21845;
  kk_std_num_ddouble__ddouble _x22996 = kk_std_num_ddouble__new_Ddouble(0x0p+0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  _match_21845 = kk_std_num_ddouble__lp__lt__eq__rp_(x, _x22996, _ctx); /*bool*/
  if (_match_21845) {
    bool _match_21852;
    kk_std_num_ddouble__ddouble _x22997 = kk_std_num_ddouble__new_Ddouble(0x0p+0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    _match_21852 = kk_std_num_ddouble__lp__eq__eq__rp_(x, _x22997, _ctx); /*bool*/
    if (_match_21852) {
      return kk_std_num_ddouble_dd_neginf;
    }
    return kk_std_num_ddouble_dd_nan;
  }
  bool _match_21846;
  kk_std_num_ddouble__ddouble _x22998 = kk_std_num_ddouble__new_Ddouble(0x1p0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  _match_21846 = kk_std_num_ddouble__lp__eq__eq__rp_(x, _x22998, _ctx); /*bool*/
  if (_match_21846) {
    return kk_std_num_ddouble__new_Ddouble(0x0p+0, 0x0p+0, _ctx);
  }
  bool _match_21847;
  kk_std_num_ddouble__ddouble y_21136 = kk_std_num_ddouble__new_Ddouble(0x1.5bf0a8b145769p1, 0x1.4d57ee2b1013ap-53, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_core_types__order x0_20605 = kk_std_num_ddouble_compare(x, y_21136, _ctx); /*order*/;
  kk_integer_t _x22999 = kk_std_core_int_5(x0_20605, _ctx); /*int*/
  kk_integer_t _x23000;
  kk_std_core_types__order _x23001 = kk_std_core_types__new_Eq(_ctx); /*order*/
  if (kk_std_core_types__is_Lt(_x23001)) {
    _x23000 = kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context()); /*int*/
    goto _match23002;
  }
  if (kk_std_core_types__is_Eq(_x23001)) {
    _x23000 = kk_integer_from_small(0); /*int*/
    goto _match23002;
  }
  _x23000 = kk_integer_from_small(1); /*int*/
  _match23002: ;
  _match_21847 = kk_integer_eq(_x22999,_x23000,kk_context()); /*bool*/
  if (_match_21847) {
    return kk_std_num_ddouble__new_Ddouble(0x1p0, 0x0p+0, _ctx);
  }
  bool _match_21848 = kk_std_num_ddouble_is_posinf(x, _ctx); /*bool*/;
  if (_match_21848) {
    return x;
  }
  kk_std_num_ddouble__ddouble a0;
  double d_20924;
  double _x23003;
  double _x = x.hi;
  _x23003 = _x; /*double*/
  d_20924 = log(_x23003); /*double*/
  a0 = kk_std_num_ddouble__new_Ddouble(d_20924, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x23004;
  kk_std_num_ddouble__ddouble x0_20926;
  kk_std_num_ddouble__ddouble y0_21139;
  kk_std_num_ddouble__ddouble _x23005 = kk_std_num_ddouble__lp__tilde__rp_(a0, _ctx); /*std/num/ddouble/ddouble*/
  y0_21139 = kk_std_num_ddouble_exp(_x23005, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__edouble z0;
  double z;
  double _x23006;
  double _x0 = x.hi;
  _x23006 = _x0; /*double*/
  double _x23007;
  double _x00 = y0_21139.hi;
  _x23007 = _x00; /*double*/
  z = (_x23006 * _x23007); /*double*/
  double err0;
  double _x23008;
  double _x01 = x.hi;
  _x23008 = _x01; /*double*/
  double _x23009;
  double _x000 = y0_21139.hi;
  _x23009 = _x000; /*double*/
  double _x23010 = (-z); /*double*/
  err0 = kk_std_num_double_fmadd(_x23008, _x23009, _x23010, _ctx); /*double*/
  z0 = kk_std_num_ddouble__new_Edouble(z, err0, _ctx); /*std/num/ddouble/edouble*/
  double e;
  double _x23011;
  double _x1 = z0.err;
  _x23011 = _x1; /*double*/
  double _x23012;
  double _x23013;
  double _x23014;
  double _x2 = x.hi;
  _x23014 = _x2; /*double*/
  double _x23015;
  double _x3 = y0_21139.lo;
  _x23015 = _x3; /*double*/
  _x23013 = (_x23014 * _x23015); /*double*/
  double _x23016;
  double _x23017;
  double _x4 = x.lo;
  _x23017 = _x4; /*double*/
  double _x23018;
  double _x5 = y0_21139.hi;
  _x23018 = _x5; /*double*/
  _x23016 = (_x23017 * _x23018); /*double*/
  _x23012 = (_x23013 + _x23016); /*double*/
  e = (_x23011 + _x23012); /*double*/
  bool _match_21849;
  bool _x23019;
  double _x23020;
  double _x6 = z0.num;
  _x23020 = _x6; /*double*/
  _x23019 = isfinite(_x23020); /*bool*/
  _match_21849 = !(_x23019); /*bool*/
  if (_match_21849) {
    double _x23021;
    double _x60 = z0.num;
    _x23021 = _x60; /*double*/
    x0_20926 = kk_std_num_ddouble_ddouble(_x23021, _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    double z1;
    double _x23022;
    double _x61 = z0.num;
    _x23022 = _x61; /*double*/
    z1 = (_x23022 + e); /*double*/
    double err00;
    double _x23023;
    double _x23024;
    double _x62 = z0.num;
    _x23024 = _x62; /*double*/
    _x23023 = (z1 - _x23024); /*double*/
    err00 = (e - _x23023); /*double*/
    double _x23025;
    bool _match_21850 = isfinite(z1); /*bool*/;
    if (_match_21850) {
      _x23025 = err00; /*double*/
    }
    else {
      _x23025 = z1; /*double*/
    }
    x0_20926 = kk_std_num_ddouble__new_Ddouble(z1, _x23025, _ctx); /*std/num/ddouble/ddouble*/
  }
  kk_std_num_ddouble__ddouble _x23026;
  kk_std_num_ddouble__ddouble _x23027 = kk_std_num_ddouble__new_Ddouble(0x1p0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  _x23026 = kk_std_num_ddouble__lp__tilde__rp_(_x23027, _ctx); /*std/num/ddouble/ddouble*/
  _x23004 = kk_std_num_ddouble__lp__plus__rp_(x0_20926, _x23026, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__lp__plus__rp_(a0, _x23004, _ctx);
}
 
// The area hyperbolic cosine of `x`.

kk_std_num_ddouble__ddouble kk_std_num_ddouble_acosh(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> ddouble */ 
  bool _match_21840;
  kk_std_num_ddouble__ddouble _x23028 = kk_std_num_ddouble__new_Ddouble(0x1p0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  _match_21840 = kk_std_num_ddouble__lp__lt__rp_(x, _x23028, _ctx); /*bool*/
  if (_match_21840) {
    return kk_std_num_ddouble_dd_nan;
  }
  kk_std_num_ddouble__ddouble _x23029;
  kk_std_num_ddouble__ddouble _x23030;
  kk_std_num_ddouble__ddouble x0_20928;
  kk_std_num_ddouble__ddouble x2_20929 = kk_std_num_ddouble_sqr(x, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__ddouble _x23031;
  kk_std_num_ddouble__ddouble _x23032 = kk_std_num_ddouble__new_Ddouble(0x1p0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  _x23031 = kk_std_num_ddouble__lp__tilde__rp_(_x23032, _ctx); /*std/num/ddouble/ddouble*/
  x0_20928 = kk_std_num_ddouble__lp__plus__rp_(x2_20929, _x23031, _ctx); /*std/num/ddouble/ddouble*/
  bool _match_21841 = kk_std_num_ddouble_is_zero(x0_20928, _ctx); /*bool*/;
  if (_match_21841) {
    _x23030 = kk_std_num_ddouble__new_Ddouble(0x0p+0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    bool _match_21842 = kk_std_num_ddouble_is_neg(x0_20928, _ctx); /*bool*/;
    if (_match_21842) {
      _x23030 = kk_std_num_ddouble_dd_nan; /*std/num/ddouble/ddouble*/
    }
    else {
      double a;
      double _x23033;
      double _x23034;
      double _x = x0_20928.hi;
      _x23034 = _x; /*double*/
      _x23033 = sqrt(_x23034); /*double*/
      a = (0x1p0 / _x23033); /*double*/
      double t1;
      double _x23035;
      double _x0 = x0_20928.hi;
      _x23035 = _x0; /*double*/
      t1 = (_x23035 * a); /*double*/
      double t2;
      double _x23036;
      double _x23037;
      kk_std_num_ddouble__ddouble ddouble1_20933;
      kk_std_num_ddouble__ddouble y_20935;
      kk_std_num_ddouble__ddouble x0_21140 = kk_std_num_ddouble_ddouble(t1, _ctx); /*std/num/ddouble/ddouble*/;
      kk_std_num_ddouble__edouble z0;
      double z;
      double _x23038;
      double _x1 = x0_21140.hi;
      _x23038 = _x1; /*double*/
      double _x23039;
      double _x10 = x0_21140.hi;
      _x23039 = _x10; /*double*/
      z = (_x23038 * _x23039); /*double*/
      double err0;
      double _x23040;
      double _x11 = x0_21140.hi;
      _x23040 = _x11; /*double*/
      double _x23041;
      double _x12 = x0_21140.hi;
      _x23041 = _x12; /*double*/
      double _x23042 = (-z); /*double*/
      err0 = kk_std_num_double_fmadd(_x23040, _x23041, _x23042, _ctx); /*double*/
      z0 = kk_std_num_ddouble__new_Edouble(z, err0, _ctx); /*std/num/ddouble/edouble*/
      double e;
      double _x23043;
      double _x23044;
      double _x00 = z0.err;
      _x23044 = _x00; /*double*/
      double _x23045;
      double _x23046;
      double _x23047;
      double _x100 = x0_21140.hi;
      _x23047 = _x100; /*double*/
      _x23046 = (0x1p1 * _x23047); /*double*/
      double _x23048;
      double _x2 = x0_21140.lo;
      _x23048 = _x2; /*double*/
      _x23045 = (_x23046 * _x23048); /*double*/
      _x23043 = (_x23044 + _x23045); /*double*/
      double _x23049;
      double _x23050;
      double _x3 = x0_21140.lo;
      _x23050 = _x3; /*double*/
      double _x23051;
      double _x4 = x0_21140.lo;
      _x23051 = _x4; /*double*/
      _x23049 = (_x23050 * _x23051); /*double*/
      e = (_x23043 + _x23049); /*double*/
      bool _match_21843;
      bool _x23052;
      double _x23053;
      double _x5 = z0.num;
      _x23053 = _x5; /*double*/
      _x23052 = isfinite(_x23053); /*bool*/
      _match_21843 = !(_x23052); /*bool*/
      if (_match_21843) {
        double _x23054;
        double _x50 = z0.num;
        _x23054 = _x50; /*double*/
        y_20935 = kk_std_num_ddouble_ddouble(_x23054, _ctx); /*std/num/ddouble/ddouble*/
      }
      else {
        double z1;
        double _x23055;
        double _x51 = z0.num;
        _x23055 = _x51; /*double*/
        z1 = (_x23055 + e); /*double*/
        double err00;
        double _x23056;
        double _x23057;
        double _x52 = z0.num;
        _x23057 = _x52; /*double*/
        _x23056 = (z1 - _x23057); /*double*/
        err00 = (e - _x23056); /*double*/
        double _x23058;
        bool _match_21844 = isfinite(z1); /*bool*/;
        if (_match_21844) {
          _x23058 = err00; /*double*/
        }
        else {
          _x23058 = z1; /*double*/
        }
        y_20935 = kk_std_num_ddouble__new_Ddouble(z1, _x23058, _ctx); /*std/num/ddouble/ddouble*/
      }
      kk_std_num_ddouble__ddouble _x23059 = kk_std_num_ddouble__lp__tilde__rp_(y_20935, _ctx); /*std/num/ddouble/ddouble*/
      ddouble1_20933 = kk_std_num_ddouble__lp__plus__rp_(x0_20928, _x23059, _ctx); /*std/num/ddouble/ddouble*/
      double _x110 = ddouble1_20933.hi;
      _x23037 = _x110; /*double*/
      _x23036 = (_x23037 * a); /*double*/
      t2 = (_x23036 * (0x1p-1)); /*double*/
      _x23030 = kk_std_num_ddouble_dsum(t1, t2, _ctx); /*std/num/ddouble/ddouble*/
    }
  }
  _x23029 = kk_std_num_ddouble__lp__plus__rp_(x, _x23030, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble_log(_x23029, _ctx);
}
 
// The arc-sine of `x`. Returns the angle in radians.

kk_std_num_ddouble__ddouble kk_std_num_ddouble_asin(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> ddouble */ 
  kk_std_num_ddouble__ddouble a = kk_std_num_ddouble_abs(x, _ctx); /*std/num/ddouble/ddouble*/;
  bool _match_21833;
  kk_std_num_ddouble__ddouble _x23060 = kk_std_num_ddouble__new_Ddouble(0x1p0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  _match_21833 = kk_std_num_ddouble__lp__gt__rp_(a, _x23060, _ctx); /*bool*/
  if (_match_21833) {
    return kk_std_num_ddouble_dd_nan;
  }
  bool _match_21834;
  kk_std_num_ddouble__ddouble _x23061 = kk_std_num_ddouble__new_Ddouble(0x1p0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  _match_21834 = kk_std_num_ddouble__lp__eq__eq__rp_(a, _x23061, _ctx); /*bool*/
  if (_match_21834) {
    kk_std_num_ddouble__ddouble x0_21141 = kk_std_num_ddouble__new_Ddouble(0x1.921fb54442d18p0, 0x1.1a62633145c07p-54, _ctx); /*std/num/ddouble/ddouble*/;
    bool _match_21839 = kk_std_num_ddouble_is_neg(x, _ctx); /*bool*/;
    if (_match_21839) {
      kk_std_num_ddouble__ddouble x0_20854 = kk_std_num_ddouble_abs(x0_21141, _ctx); /*std/num/ddouble/ddouble*/;
      double _x23062;
      double _x23063;
      double _x = x0_20854.hi;
      _x23063 = _x; /*double*/
      _x23062 = (-_x23063); /*double*/
      double _x23064;
      double _x23065;
      double _x0 = x0_20854.lo;
      _x23065 = _x0; /*double*/
      _x23064 = (-_x23065); /*double*/
      return kk_std_num_ddouble__new_Ddouble(_x23062, _x23064, _ctx);
    }
    return kk_std_num_ddouble_abs(x0_21141, _ctx);
  }
  kk_std_num_ddouble__ddouble _x23066;
  kk_std_num_ddouble__ddouble x0_20936;
  kk_std_num_ddouble__ddouble y0_20938 = kk_std_num_ddouble_sqr(x, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__ddouble _x23067 = kk_std_num_ddouble__new_Ddouble(0x1p0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x23068 = kk_std_num_ddouble__lp__tilde__rp_(y0_20938, _ctx); /*std/num/ddouble/ddouble*/
  x0_20936 = kk_std_num_ddouble__lp__plus__rp_(_x23067, _x23068, _ctx); /*std/num/ddouble/ddouble*/
  bool _match_21835 = kk_std_num_ddouble_is_zero(x0_20936, _ctx); /*bool*/;
  if (_match_21835) {
    _x23066 = kk_std_num_ddouble__new_Ddouble(0x0p+0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    bool _match_21836 = kk_std_num_ddouble_is_neg(x0_20936, _ctx); /*bool*/;
    if (_match_21836) {
      _x23066 = kk_std_num_ddouble_dd_nan; /*std/num/ddouble/ddouble*/
    }
    else {
      double a0;
      double _x23069;
      double _x23070;
      double _x1 = x0_20936.hi;
      _x23070 = _x1; /*double*/
      _x23069 = sqrt(_x23070); /*double*/
      a0 = (0x1p0 / _x23069); /*double*/
      double t1;
      double _x23071;
      double _x00 = x0_20936.hi;
      _x23071 = _x00; /*double*/
      t1 = (_x23071 * a0); /*double*/
      double t2;
      double _x23072;
      double _x23073;
      kk_std_num_ddouble__ddouble ddouble1_20941;
      kk_std_num_ddouble__ddouble y_20943;
      kk_std_num_ddouble__ddouble x1_21143 = kk_std_num_ddouble_ddouble(t1, _ctx); /*std/num/ddouble/ddouble*/;
      kk_std_num_ddouble__edouble z0;
      double z;
      double _x23074;
      double _x2 = x1_21143.hi;
      _x23074 = _x2; /*double*/
      double _x23075;
      double _x20 = x1_21143.hi;
      _x23075 = _x20; /*double*/
      z = (_x23074 * _x23075); /*double*/
      double err0;
      double _x23076;
      double _x21 = x1_21143.hi;
      _x23076 = _x21; /*double*/
      double _x23077;
      double _x22 = x1_21143.hi;
      _x23077 = _x22; /*double*/
      double _x23078 = (-z); /*double*/
      err0 = kk_std_num_double_fmadd(_x23076, _x23077, _x23078, _ctx); /*double*/
      z0 = kk_std_num_ddouble__new_Edouble(z, err0, _ctx); /*std/num/ddouble/edouble*/
      double e;
      double _x23079;
      double _x23080;
      double _x01 = z0.err;
      _x23080 = _x01; /*double*/
      double _x23081;
      double _x23082;
      double _x23083;
      double _x10 = x1_21143.hi;
      _x23083 = _x10; /*double*/
      _x23082 = (0x1p1 * _x23083); /*double*/
      double _x23084;
      double _x200 = x1_21143.lo;
      _x23084 = _x200; /*double*/
      _x23081 = (_x23082 * _x23084); /*double*/
      _x23079 = (_x23080 + _x23081); /*double*/
      double _x23085;
      double _x23086;
      double _x3 = x1_21143.lo;
      _x23086 = _x3; /*double*/
      double _x23087;
      double _x4 = x1_21143.lo;
      _x23087 = _x4; /*double*/
      _x23085 = (_x23086 * _x23087); /*double*/
      e = (_x23079 + _x23085); /*double*/
      bool _match_21837;
      bool _x23088;
      double _x23089;
      double _x5 = z0.num;
      _x23089 = _x5; /*double*/
      _x23088 = isfinite(_x23089); /*bool*/
      _match_21837 = !(_x23088); /*bool*/
      if (_match_21837) {
        double _x23090;
        double _x50 = z0.num;
        _x23090 = _x50; /*double*/
        y_20943 = kk_std_num_ddouble_ddouble(_x23090, _ctx); /*std/num/ddouble/ddouble*/
      }
      else {
        double z1;
        double _x23091;
        double _x51 = z0.num;
        _x23091 = _x51; /*double*/
        z1 = (_x23091 + e); /*double*/
        double err00;
        double _x23092;
        double _x23093;
        double _x52 = z0.num;
        _x23093 = _x52; /*double*/
        _x23092 = (z1 - _x23093); /*double*/
        err00 = (e - _x23092); /*double*/
        double _x23094;
        bool _match_21838 = isfinite(z1); /*bool*/;
        if (_match_21838) {
          _x23094 = err00; /*double*/
        }
        else {
          _x23094 = z1; /*double*/
        }
        y_20943 = kk_std_num_ddouble__new_Ddouble(z1, _x23094, _ctx); /*std/num/ddouble/ddouble*/
      }
      kk_std_num_ddouble__ddouble _x23095 = kk_std_num_ddouble__lp__tilde__rp_(y_20943, _ctx); /*std/num/ddouble/ddouble*/
      ddouble1_20941 = kk_std_num_ddouble__lp__plus__rp_(x0_20936, _x23095, _ctx); /*std/num/ddouble/ddouble*/
      double _x11 = ddouble1_20941.hi;
      _x23073 = _x11; /*double*/
      _x23072 = (_x23073 * a0); /*double*/
      t2 = (_x23072 * (0x1p-1)); /*double*/
      _x23066 = kk_std_num_ddouble_dsum(t1, t2, _ctx); /*std/num/ddouble/ddouble*/
    }
  }
  return kk_std_num_ddouble_atan2(x, _x23066, _ctx);
}
 
// The area hyperbolic sine of `x`.

kk_std_num_ddouble__ddouble kk_std_num_ddouble_asinh(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> ddouble */ 
  kk_std_num_ddouble__ddouble _x23096;
  kk_std_num_ddouble__ddouble _x23097;
  kk_std_num_ddouble__ddouble x0_20944;
  kk_std_num_ddouble__ddouble _x23098 = kk_std_num_ddouble_sqr(x, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x23099 = kk_std_num_ddouble__new_Ddouble(0x1p0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  x0_20944 = kk_std_num_ddouble__lp__plus__rp_(_x23098, _x23099, _ctx); /*std/num/ddouble/ddouble*/
  bool _match_21829 = kk_std_num_ddouble_is_zero(x0_20944, _ctx); /*bool*/;
  if (_match_21829) {
    _x23097 = kk_std_num_ddouble__new_Ddouble(0x0p+0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    bool _match_21830 = kk_std_num_ddouble_is_neg(x0_20944, _ctx); /*bool*/;
    if (_match_21830) {
      _x23097 = kk_std_num_ddouble_dd_nan; /*std/num/ddouble/ddouble*/
    }
    else {
      double a;
      double _x23100;
      double _x23101;
      double _x = x0_20944.hi;
      _x23101 = _x; /*double*/
      _x23100 = sqrt(_x23101); /*double*/
      a = (0x1p0 / _x23100); /*double*/
      double t1;
      double _x23102;
      double _x0 = x0_20944.hi;
      _x23102 = _x0; /*double*/
      t1 = (_x23102 * a); /*double*/
      double t2;
      double _x23103;
      double _x23104;
      kk_std_num_ddouble__ddouble ddouble1_20947;
      kk_std_num_ddouble__ddouble y_20949;
      kk_std_num_ddouble__ddouble x0_21144 = kk_std_num_ddouble_ddouble(t1, _ctx); /*std/num/ddouble/ddouble*/;
      kk_std_num_ddouble__edouble z0;
      double z;
      double _x23105;
      double _x1 = x0_21144.hi;
      _x23105 = _x1; /*double*/
      double _x23106;
      double _x10 = x0_21144.hi;
      _x23106 = _x10; /*double*/
      z = (_x23105 * _x23106); /*double*/
      double err0;
      double _x23107;
      double _x11 = x0_21144.hi;
      _x23107 = _x11; /*double*/
      double _x23108;
      double _x12 = x0_21144.hi;
      _x23108 = _x12; /*double*/
      double _x23109 = (-z); /*double*/
      err0 = kk_std_num_double_fmadd(_x23107, _x23108, _x23109, _ctx); /*double*/
      z0 = kk_std_num_ddouble__new_Edouble(z, err0, _ctx); /*std/num/ddouble/edouble*/
      double e;
      double _x23110;
      double _x23111;
      double _x00 = z0.err;
      _x23111 = _x00; /*double*/
      double _x23112;
      double _x23113;
      double _x23114;
      double _x100 = x0_21144.hi;
      _x23114 = _x100; /*double*/
      _x23113 = (0x1p1 * _x23114); /*double*/
      double _x23115;
      double _x2 = x0_21144.lo;
      _x23115 = _x2; /*double*/
      _x23112 = (_x23113 * _x23115); /*double*/
      _x23110 = (_x23111 + _x23112); /*double*/
      double _x23116;
      double _x23117;
      double _x3 = x0_21144.lo;
      _x23117 = _x3; /*double*/
      double _x23118;
      double _x4 = x0_21144.lo;
      _x23118 = _x4; /*double*/
      _x23116 = (_x23117 * _x23118); /*double*/
      e = (_x23110 + _x23116); /*double*/
      bool _match_21831;
      bool _x23119;
      double _x23120;
      double _x5 = z0.num;
      _x23120 = _x5; /*double*/
      _x23119 = isfinite(_x23120); /*bool*/
      _match_21831 = !(_x23119); /*bool*/
      if (_match_21831) {
        double _x23121;
        double _x50 = z0.num;
        _x23121 = _x50; /*double*/
        y_20949 = kk_std_num_ddouble_ddouble(_x23121, _ctx); /*std/num/ddouble/ddouble*/
      }
      else {
        double z1;
        double _x23122;
        double _x51 = z0.num;
        _x23122 = _x51; /*double*/
        z1 = (_x23122 + e); /*double*/
        double err00;
        double _x23123;
        double _x23124;
        double _x52 = z0.num;
        _x23124 = _x52; /*double*/
        _x23123 = (z1 - _x23124); /*double*/
        err00 = (e - _x23123); /*double*/
        double _x23125;
        bool _match_21832 = isfinite(z1); /*bool*/;
        if (_match_21832) {
          _x23125 = err00; /*double*/
        }
        else {
          _x23125 = z1; /*double*/
        }
        y_20949 = kk_std_num_ddouble__new_Ddouble(z1, _x23125, _ctx); /*std/num/ddouble/ddouble*/
      }
      kk_std_num_ddouble__ddouble _x23126 = kk_std_num_ddouble__lp__tilde__rp_(y_20949, _ctx); /*std/num/ddouble/ddouble*/
      ddouble1_20947 = kk_std_num_ddouble__lp__plus__rp_(x0_20944, _x23126, _ctx); /*std/num/ddouble/ddouble*/
      double _x110 = ddouble1_20947.hi;
      _x23104 = _x110; /*double*/
      _x23103 = (_x23104 * a); /*double*/
      t2 = (_x23103 * (0x1p-1)); /*double*/
      _x23097 = kk_std_num_ddouble_dsum(t1, t2, _ctx); /*std/num/ddouble/ddouble*/
    }
  }
  _x23096 = kk_std_num_ddouble__lp__plus__rp_(x, _x23097, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble_log(_x23096, _ctx);
}
 
// The area hyperbolic tangent of `x`.

kk_std_num_ddouble__ddouble kk_std_num_ddouble_atanh(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> ddouble */ 
  bool _match_21827;
  kk_std_num_ddouble__ddouble x0_20950 = kk_std_num_ddouble_abs(x, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_core_types__order x1_20952;
  kk_std_num_ddouble__ddouble _x23128 = kk_std_num_ddouble__new_Ddouble(0x1p0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  x1_20952 = kk_std_num_ddouble_compare(x0_20950, _x23128, _ctx); /*order*/
  kk_integer_t _x23129 = kk_std_core_int_5(x1_20952, _ctx); /*int*/
  kk_integer_t _x23130;
  kk_std_core_types__order _x23131 = kk_std_core_types__new_Gt(_ctx); /*order*/
  if (kk_std_core_types__is_Lt(_x23131)) {
    _x23130 = kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context()); /*int*/
    goto _match23132;
  }
  if (kk_std_core_types__is_Eq(_x23131)) {
    _x23130 = kk_integer_from_small(0); /*int*/
    goto _match23132;
  }
  _x23130 = kk_integer_from_small(1); /*int*/
  _match23132: ;
  _match_21827 = kk_integer_eq(_x23129,_x23130,kk_context()); /*bool*/
  if (_match_21827) {
    return kk_std_num_ddouble_dd_nan;
  }
  kk_std_num_ddouble__ddouble x2_20954;
  kk_std_num_ddouble__ddouble _x23133;
  kk_std_num_ddouble__ddouble _x23134;
  kk_std_num_ddouble__ddouble _x23135 = kk_std_num_ddouble__new_Ddouble(0x1p0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  _x23134 = kk_std_num_ddouble__lp__plus__rp_(_x23135, x, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x23136;
  kk_std_num_ddouble__ddouble _x23137 = kk_std_num_ddouble__new_Ddouble(0x1p0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  _x23136 = kk_std_num_ddouble__lp__dash__rp_(_x23137, x, _ctx); /*std/num/ddouble/ddouble*/
  _x23133 = kk_std_num_ddouble__lp__fs__rp_(_x23134, _x23136, _ctx); /*std/num/ddouble/ddouble*/
  x2_20954 = kk_std_num_ddouble_log(_x23133, _ctx); /*std/num/ddouble/ddouble*/
  double _x23138;
  double _x23139;
  double _x = x2_20954.hi;
  _x23139 = _x; /*double*/
  _x23138 = (_x23139 * (0x1p-1)); /*double*/
  double _x23140;
  double _x23141;
  double _x0 = x2_20954.lo;
  _x23141 = _x0; /*double*/
  _x23140 = (_x23141 * (0x1p-1)); /*double*/
  return kk_std_num_ddouble__new_Ddouble(_x23138, _x23140, _ctx);
}
 
// Round to positive infinity.

kk_std_num_ddouble__ddouble kk_std_num_ddouble_ceiling(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> ddouble */ 
  double r;
  double _x23142;
  double _x = x.hi;
  _x23142 = _x; /*double*/
  r = ceil(_x23142); /*double*/
  bool _match_21824;
  double _x23143;
  double _x0 = x.hi;
  _x23143 = _x0; /*double*/
  _match_21824 = (r == _x23143); /*bool*/
  if (_match_21824) {
    double y_20962;
    double _x23144;
    double _x1 = x.lo;
    _x23144 = _x1; /*double*/
    y_20962 = ceil(_x23144); /*double*/
    bool _match_21825;
    bool _x23145 = isfinite(r); /*bool*/
    _match_21825 = !(_x23145); /*bool*/
    if (_match_21825) {
      return kk_std_num_ddouble_ddouble(r, _ctx);
    }
    double z = (r + y_20962); /*double*/;
    double err0;
    double _x23146 = (z - r); /*double*/
    err0 = (y_20962 - _x23146); /*double*/
    double _x23147;
    bool _match_21826 = isfinite(z); /*bool*/;
    if (_match_21826) {
      _x23147 = err0; /*double*/
    }
    else {
      _x23147 = z; /*double*/
    }
    return kk_std_num_ddouble__new_Ddouble(z, _x23147, _ctx);
  }
  return kk_std_num_ddouble__new_Ddouble(r, 0x0p+0, _ctx);
}
 
// The hyperbolic sine of `x`.

kk_std_num_ddouble__ddouble kk_std_num_ddouble_sinh(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> ddouble */ 
  bool _match_21815 = kk_std_num_ddouble_is_zero(x, _ctx); /*bool*/;
  if (_match_21815) {
    return kk_std_num_ddouble__new_Ddouble(0x0p+0, 0x0p+0, _ctx);
  }
  bool _match_21816;
  double _x23150;
  kk_std_num_ddouble__ddouble x0_20965 = kk_std_num_ddouble_abs(x, _ctx); /*std/num/ddouble/ddouble*/;
  double _x = x0_20965.hi;
  _x23150 = _x; /*double*/
  _match_21816 = (_x23150 > (0x1.999999999999ap-5)); /*bool*/
  if (_match_21816) {
    kk_std_num_ddouble__ddouble ex = kk_std_num_ddouble_exp(x, _ctx); /*std/num/ddouble/ddouble*/;
    bool _match_21823;
    bool _x23151 = kk_std_num_ddouble_is_finite(ex, _ctx); /*bool*/
    _match_21823 = !(_x23151); /*bool*/
    if (_match_21823) {
      return ex;
    }
    kk_std_num_ddouble__ddouble x1_20967;
    kk_std_num_ddouble__ddouble y_20969;
    kk_std_num_ddouble__ddouble _x23152 = kk_std_num_ddouble__new_Ddouble(0x1p0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    y_20969 = kk_std_num_ddouble__lp__fs__rp_(_x23152, ex, _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble _x23153 = kk_std_num_ddouble__lp__tilde__rp_(y_20969, _ctx); /*std/num/ddouble/ddouble*/
    x1_20967 = kk_std_num_ddouble__lp__plus__rp_(ex, _x23153, _ctx); /*std/num/ddouble/ddouble*/
    double _x23154;
    double _x23155;
    double _x0 = x1_20967.hi;
    _x23155 = _x0; /*double*/
    _x23154 = (_x23155 * (0x1p-1)); /*double*/
    double _x23156;
    double _x23157;
    double _x1 = x1_20967.lo;
    _x23157 = _x1; /*double*/
    _x23156 = (_x23157 * (0x1p-1)); /*double*/
    return kk_std_num_ddouble__new_Ddouble(_x23154, _x23156, _ctx);
  }
  kk_std_num_ddouble__ddouble x20 = kk_std_num_ddouble_sqr(x, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__ddouble y_21147;
  kk_std_num_ddouble__ddouble _x23158 = kk_std_num_ddouble__new_Ddouble(0x1p0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x23159;
  kk_std_num_ddouble__ddouble x1_21148;
  kk_std_num_ddouble__ddouble _x23160 = kk_std_num_ddouble_ddouble_int_exp(kk_integer_from_small(6), kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
  x1_21148 = kk_std_num_ddouble__lp__fs__rp_(x20, _x23160, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble y0_21149;
  kk_std_num_ddouble__ddouble _x23161 = kk_std_num_ddouble__new_Ddouble(0x1p0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x23162;
  kk_std_num_ddouble__ddouble x2_21150;
  kk_std_num_ddouble__ddouble _x23163 = kk_std_num_ddouble_ddouble_int_exp(kk_integer_from_small(20), kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
  x2_21150 = kk_std_num_ddouble__lp__fs__rp_(x20, _x23163, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble y1_21151;
  kk_std_num_ddouble__ddouble _x23164 = kk_std_num_ddouble__new_Ddouble(0x1p0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x23165;
  kk_std_num_ddouble__ddouble _x23166 = kk_std_num_ddouble_ddouble_int_exp(kk_integer_from_small(42), kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
  _x23165 = kk_std_num_ddouble__lp__fs__rp_(x20, _x23166, _ctx); /*std/num/ddouble/ddouble*/
  y1_21151 = kk_std_num_ddouble__lp__plus__rp_(_x23164, _x23165, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__edouble z01;
  double z3;
  double _x23167;
  double _x8 = x2_21150.hi;
  _x23167 = _x8; /*double*/
  double _x23168;
  double _x02 = y1_21151.hi;
  _x23168 = _x02; /*double*/
  z3 = (_x23167 * _x23168); /*double*/
  double err2;
  double _x23169;
  double _x80 = x2_21150.hi;
  _x23169 = _x80; /*double*/
  double _x23170;
  double _x020 = y1_21151.hi;
  _x23170 = _x020; /*double*/
  double _x23171 = (-z3); /*double*/
  err2 = kk_std_num_double_fmadd(_x23169, _x23170, _x23171, _ctx); /*double*/
  z01 = kk_std_num_ddouble__new_Edouble(z3, err2, _ctx); /*std/num/ddouble/edouble*/
  double e1;
  double _x23172;
  double _x12 = z01.err;
  _x23172 = _x12; /*double*/
  double _x23173;
  double _x23174;
  double _x23175;
  double _x22 = x2_21150.hi;
  _x23175 = _x22; /*double*/
  double _x23176;
  double _x31 = y1_21151.lo;
  _x23176 = _x31; /*double*/
  _x23174 = (_x23175 * _x23176); /*double*/
  double _x23177;
  double _x23178;
  double _x41 = x2_21150.lo;
  _x23178 = _x41; /*double*/
  double _x23179;
  double _x51 = y1_21151.hi;
  _x23179 = _x51; /*double*/
  _x23177 = (_x23178 * _x23179); /*double*/
  _x23173 = (_x23174 + _x23177); /*double*/
  e1 = (_x23172 + _x23173); /*double*/
  bool _match_21821;
  bool _x23180;
  double _x23181;
  double _x61 = z01.num;
  _x23181 = _x61; /*double*/
  _x23180 = isfinite(_x23181); /*bool*/
  _match_21821 = !(_x23180); /*bool*/
  if (_match_21821) {
    double _x23182;
    double _x610 = z01.num;
    _x23182 = _x610; /*double*/
    _x23162 = kk_std_num_ddouble_ddouble(_x23182, _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    double z11;
    double _x23183;
    double _x611 = z01.num;
    _x23183 = _x611; /*double*/
    z11 = (_x23183 + e1); /*double*/
    double err01;
    double _x23184;
    double _x23185;
    double _x612 = z01.num;
    _x23185 = _x612; /*double*/
    _x23184 = (z11 - _x23185); /*double*/
    err01 = (e1 - _x23184); /*double*/
    double _x23186;
    bool _match_21822 = isfinite(z11); /*bool*/;
    if (_match_21822) {
      _x23186 = err01; /*double*/
    }
    else {
      _x23186 = z11; /*double*/
    }
    _x23162 = kk_std_num_ddouble__new_Ddouble(z11, _x23186, _ctx); /*std/num/ddouble/ddouble*/
  }
  y0_21149 = kk_std_num_ddouble__lp__plus__rp_(_x23161, _x23162, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__edouble z00;
  double z2;
  double _x23187;
  double _x7 = x1_21148.hi;
  _x23187 = _x7; /*double*/
  double _x23188;
  double _x01 = y0_21149.hi;
  _x23188 = _x01; /*double*/
  z2 = (_x23187 * _x23188); /*double*/
  double err1;
  double _x23189;
  double _x70 = x1_21148.hi;
  _x23189 = _x70; /*double*/
  double _x23190;
  double _x010 = y0_21149.hi;
  _x23190 = _x010; /*double*/
  double _x23191 = (-z2); /*double*/
  err1 = kk_std_num_double_fmadd(_x23189, _x23190, _x23191, _ctx); /*double*/
  z00 = kk_std_num_ddouble__new_Edouble(z2, err1, _ctx); /*std/num/ddouble/edouble*/
  double e0;
  double _x23192;
  double _x11 = z00.err;
  _x23192 = _x11; /*double*/
  double _x23193;
  double _x23194;
  double _x23195;
  double _x21 = x1_21148.hi;
  _x23195 = _x21; /*double*/
  double _x23196;
  double _x30 = y0_21149.lo;
  _x23196 = _x30; /*double*/
  _x23194 = (_x23195 * _x23196); /*double*/
  double _x23197;
  double _x23198;
  double _x40 = x1_21148.lo;
  _x23198 = _x40; /*double*/
  double _x23199;
  double _x50 = y0_21149.hi;
  _x23199 = _x50; /*double*/
  _x23197 = (_x23198 * _x23199); /*double*/
  _x23193 = (_x23194 + _x23197); /*double*/
  e0 = (_x23192 + _x23193); /*double*/
  bool _match_21819;
  bool _x23200;
  double _x23201;
  double _x60 = z00.num;
  _x23201 = _x60; /*double*/
  _x23200 = isfinite(_x23201); /*bool*/
  _match_21819 = !(_x23200); /*bool*/
  if (_match_21819) {
    double _x23202;
    double _x600 = z00.num;
    _x23202 = _x600; /*double*/
    _x23159 = kk_std_num_ddouble_ddouble(_x23202, _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    double z10;
    double _x23203;
    double _x601 = z00.num;
    _x23203 = _x601; /*double*/
    z10 = (_x23203 + e0); /*double*/
    double err00;
    double _x23204;
    double _x23205;
    double _x602 = z00.num;
    _x23205 = _x602; /*double*/
    _x23204 = (z10 - _x23205); /*double*/
    err00 = (e0 - _x23204); /*double*/
    double _x23206;
    bool _match_21820 = isfinite(z10); /*bool*/;
    if (_match_21820) {
      _x23206 = err00; /*double*/
    }
    else {
      _x23206 = z10; /*double*/
    }
    _x23159 = kk_std_num_ddouble__new_Ddouble(z10, _x23206, _ctx); /*std/num/ddouble/ddouble*/
  }
  y_21147 = kk_std_num_ddouble__lp__plus__rp_(_x23158, _x23159, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__edouble z0;
  double z;
  double _x23207;
  double _x2 = x.hi;
  _x23207 = _x2; /*double*/
  double _x23208;
  double _x00 = y_21147.hi;
  _x23208 = _x00; /*double*/
  z = (_x23207 * _x23208); /*double*/
  double err0;
  double _x23209;
  double _x20 = x.hi;
  _x23209 = _x20; /*double*/
  double _x23210;
  double _x000 = y_21147.hi;
  _x23210 = _x000; /*double*/
  double _x23211 = (-z); /*double*/
  err0 = kk_std_num_double_fmadd(_x23209, _x23210, _x23211, _ctx); /*double*/
  z0 = kk_std_num_ddouble__new_Edouble(z, err0, _ctx); /*std/num/ddouble/edouble*/
  double e;
  double _x23212;
  double _x10 = z0.err;
  _x23212 = _x10; /*double*/
  double _x23213;
  double _x23214;
  double _x23215;
  double _x200 = x.hi;
  _x23215 = _x200; /*double*/
  double _x23216;
  double _x3 = y_21147.lo;
  _x23216 = _x3; /*double*/
  _x23214 = (_x23215 * _x23216); /*double*/
  double _x23217;
  double _x23218;
  double _x4 = x.lo;
  _x23218 = _x4; /*double*/
  double _x23219;
  double _x5 = y_21147.hi;
  _x23219 = _x5; /*double*/
  _x23217 = (_x23218 * _x23219); /*double*/
  _x23213 = (_x23214 + _x23217); /*double*/
  e = (_x23212 + _x23213); /*double*/
  bool _match_21817;
  bool _x23220;
  double _x23221;
  double _x6 = z0.num;
  _x23221 = _x6; /*double*/
  _x23220 = isfinite(_x23221); /*bool*/
  _match_21817 = !(_x23220); /*bool*/
  if (_match_21817) {
    double _x23222;
    double _x62 = z0.num;
    _x23222 = _x62; /*double*/
    return kk_std_num_ddouble_ddouble(_x23222, _ctx);
  }
  double z1;
  double _x23223;
  double _x63 = z0.num;
  _x23223 = _x63; /*double*/
  z1 = (_x23223 + e); /*double*/
  double err02;
  double _x23224;
  double _x23225;
  double _x64 = z0.num;
  _x23225 = _x64; /*double*/
  _x23224 = (z1 - _x23225); /*double*/
  err02 = (e - _x23224); /*double*/
  double _x23226;
  bool _match_21818 = isfinite(z1); /*bool*/;
  if (_match_21818) {
    _x23226 = err02; /*double*/
  }
  else {
    _x23226 = z1; /*double*/
  }
  return kk_std_num_ddouble__new_Ddouble(z1, _x23226, _ctx);
}
 
// The hyperbolic cosine of `x`.

kk_std_num_ddouble__ddouble kk_std_num_ddouble_cosh(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> ddouble */ 
  bool _match_21808 = kk_std_num_ddouble_is_zero(x, _ctx); /*bool*/;
  if (_match_21808) {
    return kk_std_num_ddouble__new_Ddouble(0x1p0, 0x0p+0, _ctx);
  }
  bool _match_21809;
  double _x23227;
  kk_std_num_ddouble__ddouble x0_20977 = kk_std_num_ddouble_abs(x, _ctx); /*std/num/ddouble/ddouble*/;
  double _x = x0_20977.hi;
  _x23227 = _x; /*double*/
  _match_21809 = (_x23227 > (0x1.999999999999ap-5)); /*bool*/
  if (_match_21809) {
    kk_std_num_ddouble__ddouble ex = kk_std_num_ddouble_exp(x, _ctx); /*std/num/ddouble/ddouble*/;
    bool _match_21814;
    bool _x23228 = kk_std_num_ddouble_is_finite(ex, _ctx); /*bool*/
    _match_21814 = !(_x23228); /*bool*/
    if (_match_21814) {
      return ex;
    }
    kk_std_num_ddouble__ddouble x1_20979;
    kk_std_num_ddouble__ddouble _x23229;
    kk_std_num_ddouble__ddouble _x23230 = kk_std_num_ddouble__new_Ddouble(0x1p0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    _x23229 = kk_std_num_ddouble__lp__fs__rp_(_x23230, ex, _ctx); /*std/num/ddouble/ddouble*/
    x1_20979 = kk_std_num_ddouble__lp__plus__rp_(ex, _x23229, _ctx); /*std/num/ddouble/ddouble*/
    double _x23231;
    double _x23232;
    double _x0 = x1_20979.hi;
    _x23232 = _x0; /*double*/
    _x23231 = (_x23232 * (0x1p-1)); /*double*/
    double _x23233;
    double _x23234;
    double _x1 = x1_20979.lo;
    _x23234 = _x1; /*double*/
    _x23233 = (_x23234 * (0x1p-1)); /*double*/
    return kk_std_num_ddouble__new_Ddouble(_x23231, _x23233, _ctx);
  }
  kk_std_num_ddouble__ddouble s = kk_std_num_ddouble_sinh(x, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__ddouble x3_20984;
  kk_std_num_ddouble__ddouble _x23235 = kk_std_num_ddouble__new_Ddouble(0x1p0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x23236 = kk_std_num_ddouble_sqr(s, _ctx); /*std/num/ddouble/ddouble*/
  x3_20984 = kk_std_num_ddouble__lp__plus__rp_(_x23235, _x23236, _ctx); /*std/num/ddouble/ddouble*/
  bool _match_21810 = kk_std_num_ddouble_is_zero(x3_20984, _ctx); /*bool*/;
  if (_match_21810) {
    return kk_std_num_ddouble__new_Ddouble(0x0p+0, 0x0p+0, _ctx);
  }
  bool _match_21811 = kk_std_num_ddouble_is_neg(x3_20984, _ctx); /*bool*/;
  if (_match_21811) {
    return kk_std_num_ddouble_dd_nan;
  }
  double a;
  double _x23237;
  double _x23238;
  double _x2 = x3_20984.hi;
  _x23238 = _x2; /*double*/
  _x23237 = sqrt(_x23238); /*double*/
  a = (0x1p0 / _x23237); /*double*/
  double t1;
  double _x23239;
  double _x3 = x3_20984.hi;
  _x23239 = _x3; /*double*/
  t1 = (_x23239 * a); /*double*/
  double t2;
  double _x23240;
  double _x23241;
  kk_std_num_ddouble__ddouble ddouble4_20987;
  kk_std_num_ddouble__ddouble y_20989;
  kk_std_num_ddouble__ddouble x0_21152 = kk_std_num_ddouble_ddouble(t1, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__edouble z0;
  double z;
  double _x23242;
  double _x4 = x0_21152.hi;
  _x23242 = _x4; /*double*/
  double _x23243;
  double _x40 = x0_21152.hi;
  _x23243 = _x40; /*double*/
  z = (_x23242 * _x23243); /*double*/
  double err0;
  double _x23244;
  double _x41 = x0_21152.hi;
  _x23244 = _x41; /*double*/
  double _x23245;
  double _x42 = x0_21152.hi;
  _x23245 = _x42; /*double*/
  double _x23246 = (-z); /*double*/
  err0 = kk_std_num_double_fmadd(_x23244, _x23245, _x23246, _ctx); /*double*/
  z0 = kk_std_num_ddouble__new_Edouble(z, err0, _ctx); /*std/num/ddouble/edouble*/
  double e;
  double _x23247;
  double _x23248;
  double _x00 = z0.err;
  _x23248 = _x00; /*double*/
  double _x23249;
  double _x23250;
  double _x23251;
  double _x10 = x0_21152.hi;
  _x23251 = _x10; /*double*/
  _x23250 = (0x1p1 * _x23251); /*double*/
  double _x23252;
  double _x20 = x0_21152.lo;
  _x23252 = _x20; /*double*/
  _x23249 = (_x23250 * _x23252); /*double*/
  _x23247 = (_x23248 + _x23249); /*double*/
  double _x23253;
  double _x23254;
  double _x30 = x0_21152.lo;
  _x23254 = _x30; /*double*/
  double _x23255;
  double _x400 = x0_21152.lo;
  _x23255 = _x400; /*double*/
  _x23253 = (_x23254 * _x23255); /*double*/
  e = (_x23247 + _x23253); /*double*/
  bool _match_21812;
  bool _x23256;
  double _x23257;
  double _x5 = z0.num;
  _x23257 = _x5; /*double*/
  _x23256 = isfinite(_x23257); /*bool*/
  _match_21812 = !(_x23256); /*bool*/
  if (_match_21812) {
    double _x23258;
    double _x50 = z0.num;
    _x23258 = _x50; /*double*/
    y_20989 = kk_std_num_ddouble_ddouble(_x23258, _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    double z1;
    double _x23259;
    double _x51 = z0.num;
    _x23259 = _x51; /*double*/
    z1 = (_x23259 + e); /*double*/
    double err00;
    double _x23260;
    double _x23261;
    double _x52 = z0.num;
    _x23261 = _x52; /*double*/
    _x23260 = (z1 - _x23261); /*double*/
    err00 = (e - _x23260); /*double*/
    double _x23262;
    bool _match_21813 = isfinite(z1); /*bool*/;
    if (_match_21813) {
      _x23262 = err00; /*double*/
    }
    else {
      _x23262 = z1; /*double*/
    }
    y_20989 = kk_std_num_ddouble__new_Ddouble(z1, _x23262, _ctx); /*std/num/ddouble/ddouble*/
  }
  kk_std_num_ddouble__ddouble _x23263 = kk_std_num_ddouble__lp__tilde__rp_(y_20989, _ctx); /*std/num/ddouble/ddouble*/
  ddouble4_20987 = kk_std_num_ddouble__lp__plus__rp_(x3_20984, _x23263, _ctx); /*std/num/ddouble/ddouble*/
  double _x410 = ddouble4_20987.hi;
  _x23241 = _x410; /*double*/
  _x23240 = (_x23241 * a); /*double*/
  t2 = (_x23240 * (0x1p-1)); /*double*/
  return kk_std_num_ddouble_dsum(t1, t2, _ctx);
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble_dd_epsilon8;

kk_std_num_ddouble__ddouble kk_std_num_ddouble_dd_euler;

kk_std_num_ddouble__ddouble kk_std_num_ddouble_dd_log10;

kk_std_num_ddouble__ddouble kk_std_num_ddouble_dd_log10e;

kk_std_num_ddouble__ddouble kk_std_num_ddouble_dd_log2e;

kk_std_num_ddouble__ddouble kk_std_num_ddouble_dd_max;

kk_std_num_ddouble__ddouble kk_std_num_ddouble_dd_min;

kk_std_num_ddouble__ddouble kk_std_num_ddouble_dd_pi16;

kk_std_num_ddouble__ddouble kk_std_num_ddouble_dd_sqrt12;

kk_std_num_ddouble__ddouble kk_std_num_ddouble_dd_sqrt2;

kk_std_num_ddouble__ddouble kk_std_num_ddouble_dd_true_min;
 
// Create a `:ddouble` `x` such that `x` equals `d`&middot;10^`e`^.

kk_std_num_ddouble__ddouble kk_std_num_ddouble_ddouble_exp(double d, kk_integer_t e, kk_context_t* _ctx) { /* (d : double, e : int) -> ddouble */ 
  kk_std_num_ddouble__ddouble x_20990 = kk_std_num_ddouble_ddouble(d, _ctx); /*std/num/ddouble/ddouble*/;
  bool _match_21805;
  kk_integer_t _x23264 = kk_integer_dup(e); /*int*/
  _match_21805 = kk_integer_is_zero(_x23264,kk_context()); /*bool*/
  if (_match_21805) {
    kk_integer_drop(e, _ctx);
    return x_20990;
  }
  kk_std_num_ddouble__ddouble y_21154 = kk_std_num_ddouble_powi10(e, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__edouble z0;
  double z;
  double _x23265;
  double _x = x_20990.hi;
  _x23265 = _x; /*double*/
  double _x23266;
  double _x0 = y_21154.hi;
  _x23266 = _x0; /*double*/
  z = (_x23265 * _x23266); /*double*/
  double err0;
  double _x23267;
  double _x1 = x_20990.hi;
  _x23267 = _x1; /*double*/
  double _x23268;
  double _x00 = y_21154.hi;
  _x23268 = _x00; /*double*/
  double _x23269 = (-z); /*double*/
  err0 = kk_std_num_double_fmadd(_x23267, _x23268, _x23269, _ctx); /*double*/
  z0 = kk_std_num_ddouble__new_Edouble(z, err0, _ctx); /*std/num/ddouble/edouble*/
  double e0;
  double _x23270;
  double _x10 = z0.err;
  _x23270 = _x10; /*double*/
  double _x23271;
  double _x23272;
  double _x23273;
  double _x2 = x_20990.hi;
  _x23273 = _x2; /*double*/
  double _x23274;
  double _x3 = y_21154.lo;
  _x23274 = _x3; /*double*/
  _x23272 = (_x23273 * _x23274); /*double*/
  double _x23275;
  double _x23276;
  double _x4 = x_20990.lo;
  _x23276 = _x4; /*double*/
  double _x23277;
  double _x5 = y_21154.hi;
  _x23277 = _x5; /*double*/
  _x23275 = (_x23276 * _x23277); /*double*/
  _x23271 = (_x23272 + _x23275); /*double*/
  e0 = (_x23270 + _x23271); /*double*/
  bool _match_21806;
  bool _x23278;
  double _x23279;
  double _x6 = z0.num;
  _x23279 = _x6; /*double*/
  _x23278 = isfinite(_x23279); /*bool*/
  _match_21806 = !(_x23278); /*bool*/
  if (_match_21806) {
    double _x23280;
    double _x60 = z0.num;
    _x23280 = _x60; /*double*/
    return kk_std_num_ddouble_ddouble(_x23280, _ctx);
  }
  double z1;
  double _x23281;
  double _x61 = z0.num;
  _x23281 = _x61; /*double*/
  z1 = (_x23281 + e0); /*double*/
  double err00;
  double _x23282;
  double _x23283;
  double _x62 = z0.num;
  _x23283 = _x62; /*double*/
  _x23282 = (z1 - _x23283); /*double*/
  err00 = (e0 - _x23282); /*double*/
  double _x23284;
  bool _match_21807 = isfinite(z1); /*bool*/;
  if (_match_21807) {
    _x23284 = err00; /*double*/
  }
  else {
    _x23284 = z1; /*double*/
  }
  return kk_std_num_ddouble__new_Ddouble(z1, _x23284, _ctx);
}
 
// Create a `:ddouble` `x` such that `x` equals `i`&middot;10^`e`^.

kk_std_num_ddouble__ddouble kk_std_num_ddouble_ddouble_exp_1(kk_integer_t i, kk_integer_t exp0, kk_context_t* _ctx) { /* (i : int, exp : int) -> ddouble */ 
  kk_std_num_ddouble__ddouble x_20992 = kk_std_num_ddouble_ddouble_1(i, _ctx); /*std/num/ddouble/ddouble*/;
  bool _match_21802;
  kk_integer_t _x23285 = kk_integer_dup(exp0); /*int*/
  _match_21802 = kk_integer_is_zero(_x23285,kk_context()); /*bool*/
  if (_match_21802) {
    kk_integer_drop(exp0, _ctx);
    return x_20992;
  }
  kk_std_num_ddouble__ddouble y_21156 = kk_std_num_ddouble_powi10(exp0, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__edouble z0;
  double z;
  double _x23286;
  double _x = x_20992.hi;
  _x23286 = _x; /*double*/
  double _x23287;
  double _x0 = y_21156.hi;
  _x23287 = _x0; /*double*/
  z = (_x23286 * _x23287); /*double*/
  double err0;
  double _x23288;
  double _x1 = x_20992.hi;
  _x23288 = _x1; /*double*/
  double _x23289;
  double _x00 = y_21156.hi;
  _x23289 = _x00; /*double*/
  double _x23290 = (-z); /*double*/
  err0 = kk_std_num_double_fmadd(_x23288, _x23289, _x23290, _ctx); /*double*/
  z0 = kk_std_num_ddouble__new_Edouble(z, err0, _ctx); /*std/num/ddouble/edouble*/
  double e;
  double _x23291;
  double _x10 = z0.err;
  _x23291 = _x10; /*double*/
  double _x23292;
  double _x23293;
  double _x23294;
  double _x2 = x_20992.hi;
  _x23294 = _x2; /*double*/
  double _x23295;
  double _x3 = y_21156.lo;
  _x23295 = _x3; /*double*/
  _x23293 = (_x23294 * _x23295); /*double*/
  double _x23296;
  double _x23297;
  double _x4 = x_20992.lo;
  _x23297 = _x4; /*double*/
  double _x23298;
  double _x5 = y_21156.hi;
  _x23298 = _x5; /*double*/
  _x23296 = (_x23297 * _x23298); /*double*/
  _x23292 = (_x23293 + _x23296); /*double*/
  e = (_x23291 + _x23292); /*double*/
  bool _match_21803;
  bool _x23299;
  double _x23300;
  double _x6 = z0.num;
  _x23300 = _x6; /*double*/
  _x23299 = isfinite(_x23300); /*bool*/
  _match_21803 = !(_x23299); /*bool*/
  if (_match_21803) {
    double _x23301;
    double _x60 = z0.num;
    _x23301 = _x60; /*double*/
    return kk_std_num_ddouble_ddouble(_x23301, _ctx);
  }
  double z1;
  double _x23302;
  double _x61 = z0.num;
  _x23302 = _x61; /*double*/
  z1 = (_x23302 + e); /*double*/
  double err00;
  double _x23303;
  double _x23304;
  double _x62 = z0.num;
  _x23304 = _x62; /*double*/
  _x23303 = (z1 - _x23304); /*double*/
  err00 = (e - _x23303); /*double*/
  double _x23305;
  bool _match_21804 = isfinite(z1); /*bool*/;
  if (_match_21804) {
    _x23305 = err00; /*double*/
  }
  else {
    _x23305 = z1; /*double*/
  }
  return kk_std_num_ddouble__new_Ddouble(z1, _x23305, _ctx);
}
 
// Division and remainder of two `:ddouble`s

kk_std_core_types__tuple2_ kk_std_num_ddouble_divrem(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_context_t* _ctx) { /* (x : ddouble, y : ddouble) -> (ddouble, ddouble) */ 
  kk_std_num_ddouble__ddouble n;
  kk_std_num_ddouble__ddouble _x23306 = kk_std_num_ddouble__lp__fs__rp_(x, y, _ctx); /*std/num/ddouble/ddouble*/
  n = kk_std_num_ddouble_round(_x23306, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _b_21613_21611;
  kk_std_num_ddouble__ddouble y0_20995 = kk_std_num_ddouble__lp__star__rp_(n, y, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__ddouble _x23307 = kk_std_num_ddouble__lp__tilde__rp_(y0_20995, _ctx); /*std/num/ddouble/ddouble*/
  _b_21613_21611 = kk_std_num_ddouble__lp__plus__rp_(x, _x23307, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_core_types__new_dash__lp__comma__rp_(kk_std_num_ddouble__ddouble_box(n, _ctx), kk_std_num_ddouble__ddouble_box(_b_21613_21611, _ctx), _ctx);
}
 
// `x` to the power of `y` both as `:ddouble`

kk_std_num_ddouble__ddouble kk_std_num_ddouble_pow(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_context_t* _ctx) { /* (x : ddouble, y : ddouble) -> ddouble */ 
  kk_std_num_ddouble__ddouble _x23310;
  kk_std_num_ddouble__ddouble y0_21158 = kk_std_num_ddouble_log(x, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__edouble z0;
  double z;
  double _x23311;
  double _x = y.hi;
  _x23311 = _x; /*double*/
  double _x23312;
  double _x0 = y0_21158.hi;
  _x23312 = _x0; /*double*/
  z = (_x23311 * _x23312); /*double*/
  double err0;
  double _x23313;
  double _x1 = y.hi;
  _x23313 = _x1; /*double*/
  double _x23314;
  double _x00 = y0_21158.hi;
  _x23314 = _x00; /*double*/
  double _x23315 = (-z); /*double*/
  err0 = kk_std_num_double_fmadd(_x23313, _x23314, _x23315, _ctx); /*double*/
  z0 = kk_std_num_ddouble__new_Edouble(z, err0, _ctx); /*std/num/ddouble/edouble*/
  double e;
  double _x23316;
  double _x10 = z0.err;
  _x23316 = _x10; /*double*/
  double _x23317;
  double _x23318;
  double _x23319;
  double _x2 = y.hi;
  _x23319 = _x2; /*double*/
  double _x23320;
  double _x3 = y0_21158.lo;
  _x23320 = _x3; /*double*/
  _x23318 = (_x23319 * _x23320); /*double*/
  double _x23321;
  double _x23322;
  double _x4 = y.lo;
  _x23322 = _x4; /*double*/
  double _x23323;
  double _x5 = y0_21158.hi;
  _x23323 = _x5; /*double*/
  _x23321 = (_x23322 * _x23323); /*double*/
  _x23317 = (_x23318 + _x23321); /*double*/
  e = (_x23316 + _x23317); /*double*/
  bool _match_21800;
  bool _x23324;
  double _x23325;
  double _x6 = z0.num;
  _x23325 = _x6; /*double*/
  _x23324 = isfinite(_x23325); /*bool*/
  _match_21800 = !(_x23324); /*bool*/
  if (_match_21800) {
    double _x23326;
    double _x60 = z0.num;
    _x23326 = _x60; /*double*/
    _x23310 = kk_std_num_ddouble_ddouble(_x23326, _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    double z1;
    double _x23327;
    double _x61 = z0.num;
    _x23327 = _x61; /*double*/
    z1 = (_x23327 + e); /*double*/
    double err00;
    double _x23328;
    double _x23329;
    double _x62 = z0.num;
    _x23329 = _x62; /*double*/
    _x23328 = (z1 - _x23329); /*double*/
    err00 = (e - _x23328); /*double*/
    double _x23330;
    bool _match_21801 = isfinite(z1); /*bool*/;
    if (_match_21801) {
      _x23330 = err00; /*double*/
    }
    else {
      _x23330 = z1; /*double*/
    }
    _x23310 = kk_std_num_ddouble__new_Ddouble(z1, _x23330, _ctx); /*std/num/ddouble/ddouble*/
  }
  return kk_std_num_ddouble_exp(_x23310, _ctx);
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble_two;
 
// Return `exp(x - 1.0)`.
// Avoids rounding errors for values of `x` very close to `1.0`.

kk_std_num_ddouble__ddouble kk_std_num_ddouble_expm1(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> ddouble */ 
  bool _match_21794 = kk_std_num_ddouble_is_posinf(x, _ctx); /*bool*/;
  if (_match_21794) {
    return x;
  }
  kk_std_num_ddouble__ddouble y = kk_std_num_ddouble_exp(x, _ctx); /*std/num/ddouble/ddouble*/;
  bool _match_21795;
  kk_std_num_ddouble__ddouble _x23333 = kk_std_num_ddouble__new_Ddouble(0x1p0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  _match_21795 = kk_std_num_ddouble__lp__eq__eq__rp_(y, _x23333, _ctx); /*bool*/
  if (_match_21795) {
    return x;
  }
  kk_std_num_ddouble__ddouble ym;
  kk_std_num_ddouble__ddouble _x23334 = kk_std_num_ddouble__new_Ddouble(0x1p0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  ym = kk_std_num_ddouble__lp__dash__rp_(y, _x23334, _ctx); /*std/num/ddouble/ddouble*/
  bool _match_21796;
  kk_std_num_ddouble__ddouble y0_20998;
  kk_std_num_ddouble__ddouble _x23335 = kk_std_num_ddouble__new_Ddouble(0x1p0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  y0_20998 = kk_std_num_ddouble__lp__tilde__rp_(_x23335, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_core_types__order x1_20999 = kk_std_num_ddouble_compare(ym, y0_20998, _ctx); /*order*/;
  kk_integer_t _x23336 = kk_std_core_int_5(x1_20999, _ctx); /*int*/
  kk_integer_t _x23337;
  kk_std_core_types__order _x23338 = kk_std_core_types__new_Eq(_ctx); /*order*/
  if (kk_std_core_types__is_Lt(_x23338)) {
    _x23337 = kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context()); /*int*/
    goto _match23339;
  }
  if (kk_std_core_types__is_Eq(_x23338)) {
    _x23337 = kk_integer_from_small(0); /*int*/
    goto _match23339;
  }
  _x23337 = kk_integer_from_small(1); /*int*/
  _match23339: ;
  _match_21796 = kk_integer_eq(_x23336,_x23337,kk_context()); /*bool*/
  if (_match_21796) {
    kk_std_num_ddouble__ddouble _x23340 = kk_std_num_ddouble__new_Ddouble(0x1p0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    return kk_std_num_ddouble__lp__tilde__rp_(_x23340, _ctx);
  }
  kk_std_num_ddouble__ddouble y0_21161;
  kk_std_num_ddouble__ddouble _x23341 = kk_std_num_ddouble_log(y, _ctx); /*std/num/ddouble/ddouble*/
  y0_21161 = kk_std_num_ddouble__lp__fs__rp_(x, _x23341, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__edouble z0;
  double z;
  double _x23342;
  double _x = ym.hi;
  _x23342 = _x; /*double*/
  double _x23343;
  double _x0 = y0_21161.hi;
  _x23343 = _x0; /*double*/
  z = (_x23342 * _x23343); /*double*/
  double err0;
  double _x23344;
  double _x1 = ym.hi;
  _x23344 = _x1; /*double*/
  double _x23345;
  double _x00 = y0_21161.hi;
  _x23345 = _x00; /*double*/
  double _x23346 = (-z); /*double*/
  err0 = kk_std_num_double_fmadd(_x23344, _x23345, _x23346, _ctx); /*double*/
  z0 = kk_std_num_ddouble__new_Edouble(z, err0, _ctx); /*std/num/ddouble/edouble*/
  double e;
  double _x23347;
  double _x10 = z0.err;
  _x23347 = _x10; /*double*/
  double _x23348;
  double _x23349;
  double _x23350;
  double _x2 = ym.hi;
  _x23350 = _x2; /*double*/
  double _x23351;
  double _x3 = y0_21161.lo;
  _x23351 = _x3; /*double*/
  _x23349 = (_x23350 * _x23351); /*double*/
  double _x23352;
  double _x23353;
  double _x4 = ym.lo;
  _x23353 = _x4; /*double*/
  double _x23354;
  double _x5 = y0_21161.hi;
  _x23354 = _x5; /*double*/
  _x23352 = (_x23353 * _x23354); /*double*/
  _x23348 = (_x23349 + _x23352); /*double*/
  e = (_x23347 + _x23348); /*double*/
  bool _match_21797;
  bool _x23355;
  double _x23356;
  double _x6 = z0.num;
  _x23356 = _x6; /*double*/
  _x23355 = isfinite(_x23356); /*bool*/
  _match_21797 = !(_x23355); /*bool*/
  if (_match_21797) {
    double _x23357;
    double _x60 = z0.num;
    _x23357 = _x60; /*double*/
    return kk_std_num_ddouble_ddouble(_x23357, _ctx);
  }
  double z1;
  double _x23358;
  double _x61 = z0.num;
  _x23358 = _x61; /*double*/
  z1 = (_x23358 + e); /*double*/
  double err00;
  double _x23359;
  double _x23360;
  double _x62 = z0.num;
  _x23360 = _x62; /*double*/
  _x23359 = (z1 - _x23360); /*double*/
  err00 = (e - _x23359); /*double*/
  double _x23361;
  bool _match_21798 = isfinite(z1); /*bool*/;
  if (_match_21798) {
    _x23361 = err00; /*double*/
  }
  else {
    _x23361 = z1; /*double*/
  }
  return kk_std_num_ddouble__new_Ddouble(z1, _x23361, _ctx);
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble_exp2m1(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> ddouble */ 
  kk_std_num_ddouble__ddouble x0_21001;
  kk_std_num_ddouble__ddouble x0_21162 = kk_std_num_ddouble__new_Ddouble(0x1.62e42fefa39efp-1, 0x1.abc9e3b39803fp-56, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__edouble z0;
  double z;
  double _x23362;
  double _x = x0_21162.hi;
  _x23362 = _x; /*double*/
  double _x23363;
  double _x0 = x.hi;
  _x23363 = _x0; /*double*/
  z = (_x23362 * _x23363); /*double*/
  double err0;
  double _x23364;
  double _x1 = x0_21162.hi;
  _x23364 = _x1; /*double*/
  double _x23365;
  double _x00 = x.hi;
  _x23365 = _x00; /*double*/
  double _x23366 = (-z); /*double*/
  err0 = kk_std_num_double_fmadd(_x23364, _x23365, _x23366, _ctx); /*double*/
  z0 = kk_std_num_ddouble__new_Edouble(z, err0, _ctx); /*std/num/ddouble/edouble*/
  double e;
  double _x23367;
  double _x10 = z0.err;
  _x23367 = _x10; /*double*/
  double _x23368;
  double _x23369;
  double _x23370;
  double _x2 = x0_21162.hi;
  _x23370 = _x2; /*double*/
  double _x23371;
  double _x3 = x.lo;
  _x23371 = _x3; /*double*/
  _x23369 = (_x23370 * _x23371); /*double*/
  double _x23372;
  double _x23373;
  double _x4 = x0_21162.lo;
  _x23373 = _x4; /*double*/
  double _x23374;
  double _x5 = x.hi;
  _x23374 = _x5; /*double*/
  _x23372 = (_x23373 * _x23374); /*double*/
  _x23368 = (_x23369 + _x23372); /*double*/
  e = (_x23367 + _x23368); /*double*/
  bool _match_21792;
  bool _x23375;
  double _x23376;
  double _x6 = z0.num;
  _x23376 = _x6; /*double*/
  _x23375 = isfinite(_x23376); /*bool*/
  _match_21792 = !(_x23375); /*bool*/
  if (_match_21792) {
    double _x23377;
    double _x60 = z0.num;
    _x23377 = _x60; /*double*/
    x0_21001 = kk_std_num_ddouble_ddouble(_x23377, _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    double z1;
    double _x23378;
    double _x61 = z0.num;
    _x23378 = _x61; /*double*/
    z1 = (_x23378 + e); /*double*/
    double err00;
    double _x23379;
    double _x23380;
    double _x62 = z0.num;
    _x23380 = _x62; /*double*/
    _x23379 = (z1 - _x23380); /*double*/
    err00 = (e - _x23379); /*double*/
    double _x23381;
    bool _match_21793 = isfinite(z1); /*bool*/;
    if (_match_21793) {
      _x23381 = err00; /*double*/
    }
    else {
      _x23381 = z1; /*double*/
    }
    x0_21001 = kk_std_num_ddouble__new_Ddouble(z1, _x23381, _ctx); /*std/num/ddouble/ddouble*/
  }
  bool _match_21786 = kk_std_num_ddouble_is_posinf(x0_21001, _ctx); /*bool*/;
  if (_match_21786) {
    return x0_21001;
  }
  kk_std_num_ddouble__ddouble y0 = kk_std_num_ddouble_exp(x0_21001, _ctx); /*std/num/ddouble/ddouble*/;
  bool _match_21787;
  kk_std_num_ddouble__ddouble _x23382 = kk_std_num_ddouble__new_Ddouble(0x1p0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  _match_21787 = kk_std_num_ddouble__lp__eq__eq__rp_(y0, _x23382, _ctx); /*bool*/
  if (_match_21787) {
    return x0_21001;
  }
  kk_std_num_ddouble__ddouble ym;
  kk_std_num_ddouble__ddouble _x23383 = kk_std_num_ddouble__new_Ddouble(0x1p0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  ym = kk_std_num_ddouble__lp__dash__rp_(y0, _x23383, _ctx); /*std/num/ddouble/ddouble*/
  bool _match_21788;
  kk_std_num_ddouble__ddouble y0_21003;
  kk_std_num_ddouble__ddouble _x23384 = kk_std_num_ddouble__new_Ddouble(0x1p0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  y0_21003 = kk_std_num_ddouble__lp__tilde__rp_(_x23384, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_core_types__order x2_21004 = kk_std_num_ddouble_compare(ym, y0_21003, _ctx); /*order*/;
  kk_integer_t _x23385 = kk_std_core_int_5(x2_21004, _ctx); /*int*/
  kk_integer_t _x23386;
  kk_std_core_types__order _x23387 = kk_std_core_types__new_Eq(_ctx); /*order*/
  if (kk_std_core_types__is_Lt(_x23387)) {
    _x23386 = kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context()); /*int*/
    goto _match23388;
  }
  if (kk_std_core_types__is_Eq(_x23387)) {
    _x23386 = kk_integer_from_small(0); /*int*/
    goto _match23388;
  }
  _x23386 = kk_integer_from_small(1); /*int*/
  _match23388: ;
  _match_21788 = kk_integer_eq(_x23385,_x23386,kk_context()); /*bool*/
  if (_match_21788) {
    kk_std_num_ddouble__ddouble _x23389 = kk_std_num_ddouble__new_Ddouble(0x1p0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    return kk_std_num_ddouble__lp__tilde__rp_(_x23389, _ctx);
  }
  kk_std_num_ddouble__ddouble y1_21166;
  kk_std_num_ddouble__ddouble _x23390 = kk_std_num_ddouble_log(y0, _ctx); /*std/num/ddouble/ddouble*/
  y1_21166 = kk_std_num_ddouble__lp__fs__rp_(x0_21001, _x23390, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__edouble z00;
  double z2;
  double _x23391;
  double _x7 = ym.hi;
  _x23391 = _x7; /*double*/
  double _x23392;
  double _x000 = y1_21166.hi;
  _x23392 = _x000; /*double*/
  z2 = (_x23391 * _x23392); /*double*/
  double err1;
  double _x23393;
  double _x70 = ym.hi;
  _x23393 = _x70; /*double*/
  double _x23394;
  double _x001 = y1_21166.hi;
  _x23394 = _x001; /*double*/
  double _x23395 = (-z2); /*double*/
  err1 = kk_std_num_double_fmadd(_x23393, _x23394, _x23395, _ctx); /*double*/
  z00 = kk_std_num_ddouble__new_Edouble(z2, err1, _ctx); /*std/num/ddouble/edouble*/
  double e0;
  double _x23396;
  double _x100 = z00.err;
  _x23396 = _x100; /*double*/
  double _x23397;
  double _x23398;
  double _x23399;
  double _x20 = ym.hi;
  _x23399 = _x20; /*double*/
  double _x23400;
  double _x30 = y1_21166.lo;
  _x23400 = _x30; /*double*/
  _x23398 = (_x23399 * _x23400); /*double*/
  double _x23401;
  double _x23402;
  double _x40 = ym.lo;
  _x23402 = _x40; /*double*/
  double _x23403;
  double _x50 = y1_21166.hi;
  _x23403 = _x50; /*double*/
  _x23401 = (_x23402 * _x23403); /*double*/
  _x23397 = (_x23398 + _x23401); /*double*/
  e0 = (_x23396 + _x23397); /*double*/
  bool _match_21789;
  bool _x23404;
  double _x23405;
  double _x600 = z00.num;
  _x23405 = _x600; /*double*/
  _x23404 = isfinite(_x23405); /*bool*/
  _match_21789 = !(_x23404); /*bool*/
  if (_match_21789) {
    double _x23406;
    double _x601 = z00.num;
    _x23406 = _x601; /*double*/
    return kk_std_num_ddouble_ddouble(_x23406, _ctx);
  }
  double z10;
  double _x23407;
  double _x602 = z00.num;
  _x23407 = _x602; /*double*/
  z10 = (_x23407 + e0); /*double*/
  double err000;
  double _x23408;
  double _x23409;
  double _x603 = z00.num;
  _x23409 = _x603; /*double*/
  _x23408 = (z10 - _x23409); /*double*/
  err000 = (e0 - _x23408); /*double*/
  double _x23410;
  bool _match_21790 = isfinite(z10); /*bool*/;
  if (_match_21790) {
    _x23410 = err000; /*double*/
  }
  else {
    _x23410 = z10; /*double*/
  }
  return kk_std_num_ddouble__new_Ddouble(z10, _x23410, _ctx);
}
 
// The hypotenuse of `x` and `y`: `sqrt(x*x + y*y)`.
// Prevents overflow for large numbers.

kk_std_num_ddouble__ddouble kk_std_num_ddouble_hypot(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_context_t* _ctx) { /* (x : ddouble, y : ddouble) -> ddouble */ 
  kk_std_num_ddouble__ddouble xx = kk_std_num_ddouble_abs(x, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__ddouble yy = kk_std_num_ddouble_abs(y, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__ddouble lo0 = kk_std_num_ddouble_min(xx, yy, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__ddouble hi0 = kk_std_num_ddouble_max(xx, yy, _ctx); /*std/num/ddouble/ddouble*/;
  bool _match_21777 = kk_std_num_ddouble_is_zero(hi0, _ctx); /*bool*/;
  if (_match_21777) {
    return kk_std_num_ddouble__new_Ddouble(0x0p+0, 0x0p+0, _ctx);
  }
  kk_std_num_ddouble__ddouble z = kk_std_num_ddouble__lp__fs__rp_(lo0, hi0, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__ddouble y0_21168;
  kk_std_num_ddouble__ddouble x0_21010;
  kk_std_num_ddouble__ddouble _x23413 = kk_std_num_ddouble__new_Ddouble(0x1p0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x23414 = kk_std_num_ddouble__lp__star__rp_(z, z, _ctx); /*std/num/ddouble/ddouble*/
  x0_21010 = kk_std_num_ddouble__lp__plus__rp_(_x23413, _x23414, _ctx); /*std/num/ddouble/ddouble*/
  bool _match_21780 = kk_std_num_ddouble_is_zero(x0_21010, _ctx); /*bool*/;
  if (_match_21780) {
    y0_21168 = kk_std_num_ddouble__new_Ddouble(0x0p+0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    bool _match_21781 = kk_std_num_ddouble_is_neg(x0_21010, _ctx); /*bool*/;
    if (_match_21781) {
      y0_21168 = kk_std_num_ddouble_dd_nan; /*std/num/ddouble/ddouble*/
    }
    else {
      double a;
      double _x23415;
      double _x23416;
      double _x7 = x0_21010.hi;
      _x23416 = _x7; /*double*/
      _x23415 = sqrt(_x23416); /*double*/
      a = (0x1p0 / _x23415); /*double*/
      double t1;
      double _x23417;
      double _x00 = x0_21010.hi;
      _x23417 = _x00; /*double*/
      t1 = (_x23417 * a); /*double*/
      double t2;
      double _x23418;
      double _x23419;
      kk_std_num_ddouble__ddouble ddouble1_21013;
      kk_std_num_ddouble__ddouble y0_21015;
      kk_std_num_ddouble__ddouble x1_21169 = kk_std_num_ddouble_ddouble(t1, _ctx); /*std/num/ddouble/ddouble*/;
      kk_std_num_ddouble__edouble z01;
      double z2;
      double _x23420;
      double _x8 = x1_21169.hi;
      _x23420 = _x8; /*double*/
      double _x23421;
      double _x80 = x1_21169.hi;
      _x23421 = _x80; /*double*/
      z2 = (_x23420 * _x23421); /*double*/
      double err1;
      double _x23422;
      double _x81 = x1_21169.hi;
      _x23422 = _x81; /*double*/
      double _x23423;
      double _x82 = x1_21169.hi;
      _x23423 = _x82; /*double*/
      double _x23424 = (-z2); /*double*/
      err1 = kk_std_num_double_fmadd(_x23422, _x23423, _x23424, _ctx); /*double*/
      z01 = kk_std_num_ddouble__new_Edouble(z2, err1, _ctx); /*std/num/ddouble/edouble*/
      double e0;
      double _x23425;
      double _x23426;
      double _x01 = z01.err;
      _x23426 = _x01; /*double*/
      double _x23427;
      double _x23428;
      double _x23429;
      double _x10 = x1_21169.hi;
      _x23429 = _x10; /*double*/
      _x23428 = (0x1p1 * _x23429); /*double*/
      double _x23430;
      double _x20 = x1_21169.lo;
      _x23430 = _x20; /*double*/
      _x23427 = (_x23428 * _x23430); /*double*/
      _x23425 = (_x23426 + _x23427); /*double*/
      double _x23431;
      double _x23432;
      double _x30 = x1_21169.lo;
      _x23432 = _x30; /*double*/
      double _x23433;
      double _x40 = x1_21169.lo;
      _x23433 = _x40; /*double*/
      _x23431 = (_x23432 * _x23433); /*double*/
      e0 = (_x23425 + _x23431); /*double*/
      bool _match_21782;
      bool _x23434;
      double _x23435;
      double _x50 = z01.num;
      _x23435 = _x50; /*double*/
      _x23434 = isfinite(_x23435); /*bool*/
      _match_21782 = !(_x23434); /*bool*/
      if (_match_21782) {
        double _x23436;
        double _x500 = z01.num;
        _x23436 = _x500; /*double*/
        y0_21015 = kk_std_num_ddouble_ddouble(_x23436, _ctx); /*std/num/ddouble/ddouble*/
      }
      else {
        double z10;
        double _x23437;
        double _x501 = z01.num;
        _x23437 = _x501; /*double*/
        z10 = (_x23437 + e0); /*double*/
        double err00;
        double _x23438;
        double _x23439;
        double _x502 = z01.num;
        _x23439 = _x502; /*double*/
        _x23438 = (z10 - _x23439); /*double*/
        err00 = (e0 - _x23438); /*double*/
        double _x23440;
        bool _match_21783 = isfinite(z10); /*bool*/;
        if (_match_21783) {
          _x23440 = err00; /*double*/
        }
        else {
          _x23440 = z10; /*double*/
        }
        y0_21015 = kk_std_num_ddouble__new_Ddouble(z10, _x23440, _ctx); /*std/num/ddouble/ddouble*/
      }
      kk_std_num_ddouble__ddouble _x23441 = kk_std_num_ddouble__lp__tilde__rp_(y0_21015, _ctx); /*std/num/ddouble/ddouble*/
      ddouble1_21013 = kk_std_num_ddouble__lp__plus__rp_(x0_21010, _x23441, _ctx); /*std/num/ddouble/ddouble*/
      double _x11 = ddouble1_21013.hi;
      _x23419 = _x11; /*double*/
      _x23418 = (_x23419 * a); /*double*/
      t2 = (_x23418 * (0x1p-1)); /*double*/
      y0_21168 = kk_std_num_ddouble_dsum(t1, t2, _ctx); /*std/num/ddouble/ddouble*/
    }
  }
  kk_std_num_ddouble__edouble z00;
  double z0;
  double _x23442;
  double _x = hi0.hi;
  _x23442 = _x; /*double*/
  double _x23443;
  double _x0 = y0_21168.hi;
  _x23443 = _x0; /*double*/
  z0 = (_x23442 * _x23443); /*double*/
  double err0;
  double _x23444;
  double _x1 = hi0.hi;
  _x23444 = _x1; /*double*/
  double _x23445;
  double _x02 = y0_21168.hi;
  _x23445 = _x02; /*double*/
  double _x23446 = (-z0); /*double*/
  err0 = kk_std_num_double_fmadd(_x23444, _x23445, _x23446, _ctx); /*double*/
  z00 = kk_std_num_ddouble__new_Edouble(z0, err0, _ctx); /*std/num/ddouble/edouble*/
  double e;
  double _x23447;
  double _x12 = z00.err;
  _x23447 = _x12; /*double*/
  double _x23448;
  double _x23449;
  double _x23450;
  double _x2 = hi0.hi;
  _x23450 = _x2; /*double*/
  double _x23451;
  double _x3 = y0_21168.lo;
  _x23451 = _x3; /*double*/
  _x23449 = (_x23450 * _x23451); /*double*/
  double _x23452;
  double _x23453;
  double _x4 = hi0.lo;
  _x23453 = _x4; /*double*/
  double _x23454;
  double _x5 = y0_21168.hi;
  _x23454 = _x5; /*double*/
  _x23452 = (_x23453 * _x23454); /*double*/
  _x23448 = (_x23449 + _x23452); /*double*/
  e = (_x23447 + _x23448); /*double*/
  bool _match_21778;
  bool _x23455;
  double _x23456;
  double _x6 = z00.num;
  _x23456 = _x6; /*double*/
  _x23455 = isfinite(_x23456); /*bool*/
  _match_21778 = !(_x23455); /*bool*/
  if (_match_21778) {
    double _x23457;
    double _x60 = z00.num;
    _x23457 = _x60; /*double*/
    return kk_std_num_ddouble_ddouble(_x23457, _ctx);
  }
  double z1;
  double _x23458;
  double _x61 = z00.num;
  _x23458 = _x61; /*double*/
  z1 = (_x23458 + e); /*double*/
  double err01;
  double _x23459;
  double _x23460;
  double _x62 = z00.num;
  _x23460 = _x62; /*double*/
  _x23459 = (z1 - _x23460); /*double*/
  err01 = (e - _x23459); /*double*/
  double _x23461;
  bool _match_21779 = isfinite(z1); /*bool*/;
  if (_match_21779) {
    _x23461 = err01; /*double*/
  }
  else {
    _x23461 = z1; /*double*/
  }
  return kk_std_num_ddouble__new_Ddouble(z1, _x23461, _ctx);
}
 
// The square root of the sum of the squares of three doubles.
// Prevents overflow for large numbers.

kk_std_num_ddouble__ddouble kk_std_num_ddouble_hypot_1(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_std_num_ddouble__ddouble z, kk_context_t* _ctx) { /* (x : ddouble, y : ddouble, z : ddouble) -> ddouble */ 
  kk_std_num_ddouble__ddouble xx = kk_std_num_ddouble_abs(x, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__ddouble yy = kk_std_num_ddouble_abs(y, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__ddouble zz = kk_std_num_ddouble_abs(z, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__ddouble hi0;
  kk_std_num_ddouble__ddouble x0_21016 = kk_std_num_ddouble_max(xx, yy, _ctx); /*std/num/ddouble/ddouble*/;
  bool _match_21776 = kk_std_num_ddouble__lp__gt__eq__rp_(x0_21016, zz, _ctx); /*bool*/;
  if (_match_21776) {
    hi0 = x0_21016; /*std/num/ddouble/ddouble*/
  }
  else {
    hi0 = zz; /*std/num/ddouble/ddouble*/
  }
  bool _match_21763 = kk_std_num_ddouble_is_zero(hi0, _ctx); /*bool*/;
  if (_match_21763) {
    return kk_std_num_ddouble__new_Ddouble(0x0p+0, 0x0p+0, _ctx);
  }
  kk_std_num_ddouble__ddouble y0_21171;
  kk_std_num_ddouble__ddouble x1_21018;
  kk_std_num_ddouble__ddouble _x23462;
  kk_std_num_ddouble__ddouble _x23463;
  kk_std_num_ddouble__ddouble x1_21172 = kk_std_num_ddouble__lp__fs__rp_(xx, hi0, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__edouble z01;
  double z2;
  double _x23464;
  double _x7 = x1_21172.hi;
  _x23464 = _x7; /*double*/
  double _x23465;
  double _x70 = x1_21172.hi;
  _x23465 = _x70; /*double*/
  z2 = (_x23464 * _x23465); /*double*/
  double err1;
  double _x23466;
  double _x71 = x1_21172.hi;
  _x23466 = _x71; /*double*/
  double _x23467;
  double _x72 = x1_21172.hi;
  _x23467 = _x72; /*double*/
  double _x23468 = (-z2); /*double*/
  err1 = kk_std_num_double_fmadd(_x23466, _x23467, _x23468, _ctx); /*double*/
  z01 = kk_std_num_ddouble__new_Edouble(z2, err1, _ctx); /*std/num/ddouble/edouble*/
  double e0;
  double _x23469;
  double _x23470;
  double _x00 = z01.err;
  _x23470 = _x00; /*double*/
  double _x23471;
  double _x23472;
  double _x23473;
  double _x10 = x1_21172.hi;
  _x23473 = _x10; /*double*/
  _x23472 = (0x1p1 * _x23473); /*double*/
  double _x23474;
  double _x20 = x1_21172.lo;
  _x23474 = _x20; /*double*/
  _x23471 = (_x23472 * _x23474); /*double*/
  _x23469 = (_x23470 + _x23471); /*double*/
  double _x23475;
  double _x23476;
  double _x30 = x1_21172.lo;
  _x23476 = _x30; /*double*/
  double _x23477;
  double _x40 = x1_21172.lo;
  _x23477 = _x40; /*double*/
  _x23475 = (_x23476 * _x23477); /*double*/
  e0 = (_x23469 + _x23475); /*double*/
  bool _match_21774;
  bool _x23478;
  double _x23479;
  double _x50 = z01.num;
  _x23479 = _x50; /*double*/
  _x23478 = isfinite(_x23479); /*bool*/
  _match_21774 = !(_x23478); /*bool*/
  if (_match_21774) {
    double _x23480;
    double _x500 = z01.num;
    _x23480 = _x500; /*double*/
    _x23463 = kk_std_num_ddouble_ddouble(_x23480, _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    double z10;
    double _x23481;
    double _x501 = z01.num;
    _x23481 = _x501; /*double*/
    z10 = (_x23481 + e0); /*double*/
    double err00;
    double _x23482;
    double _x23483;
    double _x502 = z01.num;
    _x23483 = _x502; /*double*/
    _x23482 = (z10 - _x23483); /*double*/
    err00 = (e0 - _x23482); /*double*/
    double _x23484;
    bool _match_21775 = isfinite(z10); /*bool*/;
    if (_match_21775) {
      _x23484 = err00; /*double*/
    }
    else {
      _x23484 = z10; /*double*/
    }
    _x23463 = kk_std_num_ddouble__new_Ddouble(z10, _x23484, _ctx); /*std/num/ddouble/ddouble*/
  }
  kk_std_num_ddouble__ddouble _x23485;
  kk_std_num_ddouble__ddouble x2_21173 = kk_std_num_ddouble__lp__fs__rp_(yy, hi0, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__edouble z02;
  double z3;
  double _x23486;
  double _x8 = x2_21173.hi;
  _x23486 = _x8; /*double*/
  double _x23487;
  double _x80 = x2_21173.hi;
  _x23487 = _x80; /*double*/
  z3 = (_x23486 * _x23487); /*double*/
  double err2;
  double _x23488;
  double _x81 = x2_21173.hi;
  _x23488 = _x81; /*double*/
  double _x23489;
  double _x82 = x2_21173.hi;
  _x23489 = _x82; /*double*/
  double _x23490 = (-z3); /*double*/
  err2 = kk_std_num_double_fmadd(_x23488, _x23489, _x23490, _ctx); /*double*/
  z02 = kk_std_num_ddouble__new_Edouble(z3, err2, _ctx); /*std/num/ddouble/edouble*/
  double e1;
  double _x23491;
  double _x23492;
  double _x01 = z02.err;
  _x23492 = _x01; /*double*/
  double _x23493;
  double _x23494;
  double _x23495;
  double _x11 = x2_21173.hi;
  _x23495 = _x11; /*double*/
  _x23494 = (0x1p1 * _x23495); /*double*/
  double _x23496;
  double _x21 = x2_21173.lo;
  _x23496 = _x21; /*double*/
  _x23493 = (_x23494 * _x23496); /*double*/
  _x23491 = (_x23492 + _x23493); /*double*/
  double _x23497;
  double _x23498;
  double _x31 = x2_21173.lo;
  _x23498 = _x31; /*double*/
  double _x23499;
  double _x41 = x2_21173.lo;
  _x23499 = _x41; /*double*/
  _x23497 = (_x23498 * _x23499); /*double*/
  e1 = (_x23491 + _x23497); /*double*/
  bool _match_21772;
  bool _x23500;
  double _x23501;
  double _x51 = z02.num;
  _x23501 = _x51; /*double*/
  _x23500 = isfinite(_x23501); /*bool*/
  _match_21772 = !(_x23500); /*bool*/
  if (_match_21772) {
    double _x23502;
    double _x510 = z02.num;
    _x23502 = _x510; /*double*/
    _x23485 = kk_std_num_ddouble_ddouble(_x23502, _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    double z11;
    double _x23503;
    double _x511 = z02.num;
    _x23503 = _x511; /*double*/
    z11 = (_x23503 + e1); /*double*/
    double err01;
    double _x23504;
    double _x23505;
    double _x512 = z02.num;
    _x23505 = _x512; /*double*/
    _x23504 = (z11 - _x23505); /*double*/
    err01 = (e1 - _x23504); /*double*/
    double _x23506;
    bool _match_21773 = isfinite(z11); /*bool*/;
    if (_match_21773) {
      _x23506 = err01; /*double*/
    }
    else {
      _x23506 = z11; /*double*/
    }
    _x23485 = kk_std_num_ddouble__new_Ddouble(z11, _x23506, _ctx); /*std/num/ddouble/ddouble*/
  }
  _x23462 = kk_std_num_ddouble__lp__plus__rp_(_x23463, _x23485, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x23507;
  kk_std_num_ddouble__ddouble x3_21174 = kk_std_num_ddouble__lp__fs__rp_(zz, hi0, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__edouble z03;
  double z4;
  double _x23508;
  double _x9 = x3_21174.hi;
  _x23508 = _x9; /*double*/
  double _x23509;
  double _x90 = x3_21174.hi;
  _x23509 = _x90; /*double*/
  z4 = (_x23508 * _x23509); /*double*/
  double err3;
  double _x23510;
  double _x91 = x3_21174.hi;
  _x23510 = _x91; /*double*/
  double _x23511;
  double _x92 = x3_21174.hi;
  _x23511 = _x92; /*double*/
  double _x23512 = (-z4); /*double*/
  err3 = kk_std_num_double_fmadd(_x23510, _x23511, _x23512, _ctx); /*double*/
  z03 = kk_std_num_ddouble__new_Edouble(z4, err3, _ctx); /*std/num/ddouble/edouble*/
  double e2;
  double _x23513;
  double _x23514;
  double _x02 = z03.err;
  _x23514 = _x02; /*double*/
  double _x23515;
  double _x23516;
  double _x23517;
  double _x12 = x3_21174.hi;
  _x23517 = _x12; /*double*/
  _x23516 = (0x1p1 * _x23517); /*double*/
  double _x23518;
  double _x22 = x3_21174.lo;
  _x23518 = _x22; /*double*/
  _x23515 = (_x23516 * _x23518); /*double*/
  _x23513 = (_x23514 + _x23515); /*double*/
  double _x23519;
  double _x23520;
  double _x32 = x3_21174.lo;
  _x23520 = _x32; /*double*/
  double _x23521;
  double _x42 = x3_21174.lo;
  _x23521 = _x42; /*double*/
  _x23519 = (_x23520 * _x23521); /*double*/
  e2 = (_x23513 + _x23519); /*double*/
  bool _match_21770;
  bool _x23522;
  double _x23523;
  double _x52 = z03.num;
  _x23523 = _x52; /*double*/
  _x23522 = isfinite(_x23523); /*bool*/
  _match_21770 = !(_x23522); /*bool*/
  if (_match_21770) {
    double _x23524;
    double _x520 = z03.num;
    _x23524 = _x520; /*double*/
    _x23507 = kk_std_num_ddouble_ddouble(_x23524, _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    double z12;
    double _x23525;
    double _x521 = z03.num;
    _x23525 = _x521; /*double*/
    z12 = (_x23525 + e2); /*double*/
    double err02;
    double _x23526;
    double _x23527;
    double _x522 = z03.num;
    _x23527 = _x522; /*double*/
    _x23526 = (z12 - _x23527); /*double*/
    err02 = (e2 - _x23526); /*double*/
    double _x23528;
    bool _match_21771 = isfinite(z12); /*bool*/;
    if (_match_21771) {
      _x23528 = err02; /*double*/
    }
    else {
      _x23528 = z12; /*double*/
    }
    _x23507 = kk_std_num_ddouble__new_Ddouble(z12, _x23528, _ctx); /*std/num/ddouble/ddouble*/
  }
  x1_21018 = kk_std_num_ddouble__lp__plus__rp_(_x23462, _x23507, _ctx); /*std/num/ddouble/ddouble*/
  bool _match_21766 = kk_std_num_ddouble_is_zero(x1_21018, _ctx); /*bool*/;
  if (_match_21766) {
    y0_21171 = kk_std_num_ddouble__new_Ddouble(0x0p+0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    bool _match_21767 = kk_std_num_ddouble_is_neg(x1_21018, _ctx); /*bool*/;
    if (_match_21767) {
      y0_21171 = kk_std_num_ddouble_dd_nan; /*std/num/ddouble/ddouble*/
    }
    else {
      double a;
      double _x23529;
      double _x23530;
      double _x13 = x1_21018.hi;
      _x23530 = _x13; /*double*/
      _x23529 = sqrt(_x23530); /*double*/
      a = (0x1p0 / _x23529); /*double*/
      double t1;
      double _x23531;
      double _x03 = x1_21018.hi;
      _x23531 = _x03; /*double*/
      t1 = (_x23531 * a); /*double*/
      double t2;
      double _x23532;
      double _x23533;
      kk_std_num_ddouble__ddouble ddouble1_21021;
      kk_std_num_ddouble__ddouble y1_21023;
      kk_std_num_ddouble__ddouble x4_21175 = kk_std_num_ddouble_ddouble(t1, _ctx); /*std/num/ddouble/ddouble*/;
      kk_std_num_ddouble__edouble z04;
      double z5;
      double _x23534;
      double _x14 = x4_21175.hi;
      _x23534 = _x14; /*double*/
      double _x23535;
      double _x140 = x4_21175.hi;
      _x23535 = _x140; /*double*/
      z5 = (_x23534 * _x23535); /*double*/
      double err4;
      double _x23536;
      double _x141 = x4_21175.hi;
      _x23536 = _x141; /*double*/
      double _x23537;
      double _x142 = x4_21175.hi;
      _x23537 = _x142; /*double*/
      double _x23538 = (-z5); /*double*/
      err4 = kk_std_num_double_fmadd(_x23536, _x23537, _x23538, _ctx); /*double*/
      z04 = kk_std_num_ddouble__new_Edouble(z5, err4, _ctx); /*std/num/ddouble/edouble*/
      double e3;
      double _x23539;
      double _x23540;
      double _x04 = z04.err;
      _x23540 = _x04; /*double*/
      double _x23541;
      double _x23542;
      double _x23543;
      double _x15 = x4_21175.hi;
      _x23543 = _x15; /*double*/
      _x23542 = (0x1p1 * _x23543); /*double*/
      double _x23544;
      double _x23 = x4_21175.lo;
      _x23544 = _x23; /*double*/
      _x23541 = (_x23542 * _x23544); /*double*/
      _x23539 = (_x23540 + _x23541); /*double*/
      double _x23545;
      double _x23546;
      double _x33 = x4_21175.lo;
      _x23546 = _x33; /*double*/
      double _x23547;
      double _x43 = x4_21175.lo;
      _x23547 = _x43; /*double*/
      _x23545 = (_x23546 * _x23547); /*double*/
      e3 = (_x23539 + _x23545); /*double*/
      bool _match_21768;
      bool _x23548;
      double _x23549;
      double _x53 = z04.num;
      _x23549 = _x53; /*double*/
      _x23548 = isfinite(_x23549); /*bool*/
      _match_21768 = !(_x23548); /*bool*/
      if (_match_21768) {
        double _x23550;
        double _x530 = z04.num;
        _x23550 = _x530; /*double*/
        y1_21023 = kk_std_num_ddouble_ddouble(_x23550, _ctx); /*std/num/ddouble/ddouble*/
      }
      else {
        double z13;
        double _x23551;
        double _x531 = z04.num;
        _x23551 = _x531; /*double*/
        z13 = (_x23551 + e3); /*double*/
        double err03;
        double _x23552;
        double _x23553;
        double _x532 = z04.num;
        _x23553 = _x532; /*double*/
        _x23552 = (z13 - _x23553); /*double*/
        err03 = (e3 - _x23552); /*double*/
        double _x23554;
        bool _match_21769 = isfinite(z13); /*bool*/;
        if (_match_21769) {
          _x23554 = err03; /*double*/
        }
        else {
          _x23554 = z13; /*double*/
        }
        y1_21023 = kk_std_num_ddouble__new_Ddouble(z13, _x23554, _ctx); /*std/num/ddouble/ddouble*/
      }
      kk_std_num_ddouble__ddouble _x23555 = kk_std_num_ddouble__lp__tilde__rp_(y1_21023, _ctx); /*std/num/ddouble/ddouble*/
      ddouble1_21021 = kk_std_num_ddouble__lp__plus__rp_(x1_21018, _x23555, _ctx); /*std/num/ddouble/ddouble*/
      double _x16 = ddouble1_21021.hi;
      _x23533 = _x16; /*double*/
      _x23532 = (_x23533 * a); /*double*/
      t2 = (_x23532 * (0x1p-1)); /*double*/
      y0_21171 = kk_std_num_ddouble_dsum(t1, t2, _ctx); /*std/num/ddouble/ddouble*/
    }
  }
  kk_std_num_ddouble__edouble z00;
  double z0;
  double _x23556;
  double _x = hi0.hi;
  _x23556 = _x; /*double*/
  double _x23557;
  double _x0 = y0_21171.hi;
  _x23557 = _x0; /*double*/
  z0 = (_x23556 * _x23557); /*double*/
  double err0;
  double _x23558;
  double _x1 = hi0.hi;
  _x23558 = _x1; /*double*/
  double _x23559;
  double _x05 = y0_21171.hi;
  _x23559 = _x05; /*double*/
  double _x23560 = (-z0); /*double*/
  err0 = kk_std_num_double_fmadd(_x23558, _x23559, _x23560, _ctx); /*double*/
  z00 = kk_std_num_ddouble__new_Edouble(z0, err0, _ctx); /*std/num/ddouble/edouble*/
  double e;
  double _x23561;
  double _x17 = z00.err;
  _x23561 = _x17; /*double*/
  double _x23562;
  double _x23563;
  double _x23564;
  double _x2 = hi0.hi;
  _x23564 = _x2; /*double*/
  double _x23565;
  double _x3 = y0_21171.lo;
  _x23565 = _x3; /*double*/
  _x23563 = (_x23564 * _x23565); /*double*/
  double _x23566;
  double _x23567;
  double _x4 = hi0.lo;
  _x23567 = _x4; /*double*/
  double _x23568;
  double _x5 = y0_21171.hi;
  _x23568 = _x5; /*double*/
  _x23566 = (_x23567 * _x23568); /*double*/
  _x23562 = (_x23563 + _x23566); /*double*/
  e = (_x23561 + _x23562); /*double*/
  bool _match_21764;
  bool _x23569;
  double _x23570;
  double _x6 = z00.num;
  _x23570 = _x6; /*double*/
  _x23569 = isfinite(_x23570); /*bool*/
  _match_21764 = !(_x23569); /*bool*/
  if (_match_21764) {
    double _x23571;
    double _x60 = z00.num;
    _x23571 = _x60; /*double*/
    return kk_std_num_ddouble_ddouble(_x23571, _ctx);
  }
  double z1;
  double _x23572;
  double _x61 = z00.num;
  _x23572 = _x61; /*double*/
  z1 = (_x23572 + e); /*double*/
  double err04;
  double _x23573;
  double _x23574;
  double _x62 = z00.num;
  _x23574 = _x62; /*double*/
  _x23573 = (z1 - _x23574); /*double*/
  err04 = (e - _x23573); /*double*/
  double _x23575;
  bool _match_21765 = isfinite(z1); /*bool*/;
  if (_match_21765) {
    _x23575 = err04; /*double*/
  }
  else {
    _x23575 = z1; /*double*/
  }
  return kk_std_num_ddouble__new_Ddouble(z1, _x23575, _ctx);
}
 
// The square root of the sum of squares of a list of doubles.
// Prevents overflow for large numbers and uses Kahan-Babu&scaron;kan-Neumaier summation
// for precision.


// lift anonymous function
struct kk_std_num_ddouble_hypot_fun23578__t_2 {
  struct kk_function_s _base;
  kk_std_num_ddouble__ddouble hi0;
};
static kk_box_t kk_std_num_ddouble_hypot_fun23578_2(kk_function_t _fself, kk_box_t _b_21616, kk_context_t* _ctx);
static kk_function_t kk_std_num_ddouble_new_hypot_fun23578_2(kk_std_num_ddouble__ddouble hi0, kk_context_t* _ctx) {
  struct kk_std_num_ddouble_hypot_fun23578__t_2* _self = kk_function_alloc_as(struct kk_std_num_ddouble_hypot_fun23578__t_2, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_num_ddouble_hypot_fun23578_2, kk_context());
  _self->hi0 = hi0;
  return &_self->_base;
}

static kk_box_t kk_std_num_ddouble_hypot_fun23578_2(kk_function_t _fself, kk_box_t _b_21616, kk_context_t* _ctx) {
  struct kk_std_num_ddouble_hypot_fun23578__t_2* _self = kk_function_as(struct kk_std_num_ddouble_hypot_fun23578__t_2*, _fself);
  kk_std_num_ddouble__ddouble hi0 = _self->hi0; /* std/num/ddouble/ddouble */
  kk_drop_match(_self, {kk_std_num_ddouble__ddouble_dup(hi0);}, {}, _ctx)
  kk_std_num_ddouble__ddouble _x23579;
  kk_std_num_ddouble__ddouble x0_21178;
  kk_std_num_ddouble__ddouble _x23580 = kk_std_num_ddouble__ddouble_unbox(_b_21616, _ctx); /*std/num/ddouble/ddouble*/
  x0_21178 = kk_std_num_ddouble__lp__fs__rp_(_x23580, hi0, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__edouble z00;
  double z2;
  double _x23581;
  double _x7 = x0_21178.hi;
  _x23581 = _x7; /*double*/
  double _x23582;
  double _x70 = x0_21178.hi;
  _x23582 = _x70; /*double*/
  z2 = (_x23581 * _x23582); /*double*/
  double err1;
  double _x23583;
  double _x71 = x0_21178.hi;
  _x23583 = _x71; /*double*/
  double _x23584;
  double _x72 = x0_21178.hi;
  _x23584 = _x72; /*double*/
  double _x23585 = (-z2); /*double*/
  err1 = kk_std_num_double_fmadd(_x23583, _x23584, _x23585, _ctx); /*double*/
  z00 = kk_std_num_ddouble__new_Edouble(z2, err1, _ctx); /*std/num/ddouble/edouble*/
  double e0;
  double _x23586;
  double _x23587;
  double _x00 = z00.err;
  _x23587 = _x00; /*double*/
  double _x23588;
  double _x23589;
  double _x23590;
  double _x10 = x0_21178.hi;
  _x23590 = _x10; /*double*/
  _x23589 = (0x1p1 * _x23590); /*double*/
  double _x23591;
  double _x20 = x0_21178.lo;
  _x23591 = _x20; /*double*/
  _x23588 = (_x23589 * _x23591); /*double*/
  _x23586 = (_x23587 + _x23588); /*double*/
  double _x23592;
  double _x23593;
  double _x30 = x0_21178.lo;
  _x23593 = _x30; /*double*/
  double _x23594;
  double _x40 = x0_21178.lo;
  _x23594 = _x40; /*double*/
  _x23592 = (_x23593 * _x23594); /*double*/
  e0 = (_x23586 + _x23592); /*double*/
  bool _match_21761;
  bool _x23595;
  double _x23596;
  double _x50 = z00.num;
  _x23596 = _x50; /*double*/
  _x23595 = isfinite(_x23596); /*bool*/
  _match_21761 = !(_x23595); /*bool*/
  if (_match_21761) {
    double _x23597;
    double _x500 = z00.num;
    _x23597 = _x500; /*double*/
    _x23579 = kk_std_num_ddouble_ddouble(_x23597, _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    double z10;
    double _x23598;
    double _x501 = z00.num;
    _x23598 = _x501; /*double*/
    z10 = (_x23598 + e0); /*double*/
    double err00;
    double _x23599;
    double _x23600;
    double _x502 = z00.num;
    _x23600 = _x502; /*double*/
    _x23599 = (z10 - _x23600); /*double*/
    err00 = (e0 - _x23599); /*double*/
    double _x23601;
    bool _match_21762 = isfinite(z10); /*bool*/;
    if (_match_21762) {
      _x23601 = err00; /*double*/
    }
    else {
      _x23601 = z10; /*double*/
    }
    _x23579 = kk_std_num_ddouble__new_Ddouble(z10, _x23601, _ctx); /*std/num/ddouble/ddouble*/
  }
  return kk_std_num_ddouble__ddouble_box(_x23579, _ctx);
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble_hypot_2(kk_std_core__list xs, kk_context_t* _ctx) { /* (xs : list<ddouble>) -> ddouble */ 
  kk_std_num_ddouble__ddouble hi0;
  kk_std_core__list _x23576 = kk_std_core__list_dup(xs); /*list<std/num/ddouble/ddouble>*/
  hi0 = kk_std_num_ddouble_abs_max_1(_x23576, _ctx); /*std/num/ddouble/ddouble*/
  bool _match_21754 = kk_std_num_ddouble_is_zero(hi0, _ctx); /*bool*/;
  if (_match_21754) {
    kk_std_core__list_drop(xs, _ctx);
    return kk_std_num_ddouble__new_Ddouble(0x0p+0, 0x0p+0, _ctx);
  }
  kk_std_num_ddouble__ddouble y_21177;
  kk_std_num_ddouble__ddouble x_21024;
  kk_std_core__list _x23577 = kk_std_core_map_5(xs, kk_std_num_ddouble_new_hypot_fun23578_2(hi0, _ctx), _ctx); /*list<2>*/
  x_21024 = kk_std_num_ddouble_sum_1(_x23577, _ctx); /*std/num/ddouble/ddouble*/
  bool _match_21757 = kk_std_num_ddouble_is_zero(x_21024, _ctx); /*bool*/;
  if (_match_21757) {
    y_21177 = kk_std_num_ddouble__new_Ddouble(0x0p+0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    bool _match_21758 = kk_std_num_ddouble_is_neg(x_21024, _ctx); /*bool*/;
    if (_match_21758) {
      y_21177 = kk_std_num_ddouble_dd_nan; /*std/num/ddouble/ddouble*/
    }
    else {
      double a;
      double _x23602;
      double _x23603;
      double _x8 = x_21024.hi;
      _x23603 = _x8; /*double*/
      _x23602 = sqrt(_x23603); /*double*/
      a = (0x1p0 / _x23602); /*double*/
      double t1;
      double _x23604;
      double _x01 = x_21024.hi;
      _x23604 = _x01; /*double*/
      t1 = (_x23604 * a); /*double*/
      double t2;
      double _x23605;
      double _x23606;
      kk_std_num_ddouble__ddouble ddouble1_21027;
      kk_std_num_ddouble__ddouble y_21029;
      kk_std_num_ddouble__ddouble x2_21179 = kk_std_num_ddouble_ddouble(t1, _ctx); /*std/num/ddouble/ddouble*/;
      kk_std_num_ddouble__edouble z01;
      double z3;
      double _x23607;
      double _x9 = x2_21179.hi;
      _x23607 = _x9; /*double*/
      double _x23608;
      double _x90 = x2_21179.hi;
      _x23608 = _x90; /*double*/
      z3 = (_x23607 * _x23608); /*double*/
      double err2;
      double _x23609;
      double _x91 = x2_21179.hi;
      _x23609 = _x91; /*double*/
      double _x23610;
      double _x92 = x2_21179.hi;
      _x23610 = _x92; /*double*/
      double _x23611 = (-z3); /*double*/
      err2 = kk_std_num_double_fmadd(_x23609, _x23610, _x23611, _ctx); /*double*/
      z01 = kk_std_num_ddouble__new_Edouble(z3, err2, _ctx); /*std/num/ddouble/edouble*/
      double e1;
      double _x23612;
      double _x23613;
      double _x02 = z01.err;
      _x23613 = _x02; /*double*/
      double _x23614;
      double _x23615;
      double _x23616;
      double _x11 = x2_21179.hi;
      _x23616 = _x11; /*double*/
      _x23615 = (0x1p1 * _x23616); /*double*/
      double _x23617;
      double _x21 = x2_21179.lo;
      _x23617 = _x21; /*double*/
      _x23614 = (_x23615 * _x23617); /*double*/
      _x23612 = (_x23613 + _x23614); /*double*/
      double _x23618;
      double _x23619;
      double _x31 = x2_21179.lo;
      _x23619 = _x31; /*double*/
      double _x23620;
      double _x41 = x2_21179.lo;
      _x23620 = _x41; /*double*/
      _x23618 = (_x23619 * _x23620); /*double*/
      e1 = (_x23612 + _x23618); /*double*/
      bool _match_21759;
      bool _x23621;
      double _x23622;
      double _x51 = z01.num;
      _x23622 = _x51; /*double*/
      _x23621 = isfinite(_x23622); /*bool*/
      _match_21759 = !(_x23621); /*bool*/
      if (_match_21759) {
        double _x23623;
        double _x510 = z01.num;
        _x23623 = _x510; /*double*/
        y_21029 = kk_std_num_ddouble_ddouble(_x23623, _ctx); /*std/num/ddouble/ddouble*/
      }
      else {
        double z11;
        double _x23624;
        double _x511 = z01.num;
        _x23624 = _x511; /*double*/
        z11 = (_x23624 + e1); /*double*/
        double err01;
        double _x23625;
        double _x23626;
        double _x512 = z01.num;
        _x23626 = _x512; /*double*/
        _x23625 = (z11 - _x23626); /*double*/
        err01 = (e1 - _x23625); /*double*/
        double _x23627;
        bool _match_21760 = isfinite(z11); /*bool*/;
        if (_match_21760) {
          _x23627 = err01; /*double*/
        }
        else {
          _x23627 = z11; /*double*/
        }
        y_21029 = kk_std_num_ddouble__new_Ddouble(z11, _x23627, _ctx); /*std/num/ddouble/ddouble*/
      }
      kk_std_num_ddouble__ddouble _x23628 = kk_std_num_ddouble__lp__tilde__rp_(y_21029, _ctx); /*std/num/ddouble/ddouble*/
      ddouble1_21027 = kk_std_num_ddouble__lp__plus__rp_(x_21024, _x23628, _ctx); /*std/num/ddouble/ddouble*/
      double _x12 = ddouble1_21027.hi;
      _x23606 = _x12; /*double*/
      _x23605 = (_x23606 * a); /*double*/
      t2 = (_x23605 * (0x1p-1)); /*double*/
      y_21177 = kk_std_num_ddouble_dsum(t1, t2, _ctx); /*std/num/ddouble/ddouble*/
    }
  }
  kk_std_num_ddouble__edouble z0;
  double z;
  double _x23629;
  double _x = hi0.hi;
  _x23629 = _x; /*double*/
  double _x23630;
  double _x0 = y_21177.hi;
  _x23630 = _x0; /*double*/
  z = (_x23629 * _x23630); /*double*/
  double err0;
  double _x23631;
  double _x1 = hi0.hi;
  _x23631 = _x1; /*double*/
  double _x23632;
  double _x03 = y_21177.hi;
  _x23632 = _x03; /*double*/
  double _x23633 = (-z); /*double*/
  err0 = kk_std_num_double_fmadd(_x23631, _x23632, _x23633, _ctx); /*double*/
  z0 = kk_std_num_ddouble__new_Edouble(z, err0, _ctx); /*std/num/ddouble/edouble*/
  double e;
  double _x23634;
  double _x13 = z0.err;
  _x23634 = _x13; /*double*/
  double _x23635;
  double _x23636;
  double _x23637;
  double _x2 = hi0.hi;
  _x23637 = _x2; /*double*/
  double _x23638;
  double _x3 = y_21177.lo;
  _x23638 = _x3; /*double*/
  _x23636 = (_x23637 * _x23638); /*double*/
  double _x23639;
  double _x23640;
  double _x4 = hi0.lo;
  _x23640 = _x4; /*double*/
  double _x23641;
  double _x5 = y_21177.hi;
  _x23641 = _x5; /*double*/
  _x23639 = (_x23640 * _x23641); /*double*/
  _x23635 = (_x23636 + _x23639); /*double*/
  e = (_x23634 + _x23635); /*double*/
  bool _match_21755;
  bool _x23642;
  double _x23643;
  double _x6 = z0.num;
  _x23643 = _x6; /*double*/
  _x23642 = isfinite(_x23643); /*bool*/
  _match_21755 = !(_x23642); /*bool*/
  if (_match_21755) {
    double _x23644;
    double _x60 = z0.num;
    _x23644 = _x60; /*double*/
    return kk_std_num_ddouble_ddouble(_x23644, _ctx);
  }
  double z1;
  double _x23645;
  double _x61 = z0.num;
  _x23645 = _x61; /*double*/
  z1 = (_x23645 + e); /*double*/
  double err02;
  double _x23646;
  double _x23647;
  double _x62 = z0.num;
  _x23647 = _x62; /*double*/
  _x23646 = (z1 - _x23647); /*double*/
  err02 = (e - _x23646); /*double*/
  double _x23648;
  bool _match_21756 = isfinite(z1); /*bool*/;
  if (_match_21756) {
    _x23648 = err02; /*double*/
  }
  else {
    _x23648 = z1; /*double*/
  }
  return kk_std_num_ddouble__new_Ddouble(z1, _x23648, _ctx);
}
 
// Return `log(1.0 + x)`.
// Avoids potential imprecision for small `x` where adding `1.0` explicitly
// may lead to rounding errors.

kk_std_num_ddouble__ddouble kk_std_num_ddouble_log1p(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> ddouble */ 
  bool _match_21747 = kk_std_num_ddouble_is_posinf(x, _ctx); /*bool*/;
  if (_match_21747) {
    return x;
  }
  kk_std_num_ddouble__ddouble y;
  kk_std_num_ddouble__ddouble _x23658 = kk_std_num_ddouble__new_Ddouble(0x1p0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  y = kk_std_num_ddouble__lp__plus__rp_(_x23658, x, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble z;
  kk_std_num_ddouble__ddouble _x23659 = kk_std_num_ddouble__new_Ddouble(0x1p0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  z = kk_std_num_ddouble__lp__dash__rp_(y, _x23659, _ctx); /*std/num/ddouble/ddouble*/
  bool _match_21748 = kk_std_num_ddouble_is_zero(z, _ctx); /*bool*/;
  if (_match_21748) {
    return x;
  }
  kk_std_num_ddouble__ddouble x0_21180 = kk_std_num_ddouble_log(y, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__ddouble y0_21181 = kk_std_num_ddouble__lp__fs__rp_(x, z, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__edouble z00;
  double z0;
  double _x23660;
  double _x = x0_21180.hi;
  _x23660 = _x; /*double*/
  double _x23661;
  double _x0 = y0_21181.hi;
  _x23661 = _x0; /*double*/
  z0 = (_x23660 * _x23661); /*double*/
  double err0;
  double _x23662;
  double _x1 = x0_21180.hi;
  _x23662 = _x1; /*double*/
  double _x23663;
  double _x00 = y0_21181.hi;
  _x23663 = _x00; /*double*/
  double _x23664 = (-z0); /*double*/
  err0 = kk_std_num_double_fmadd(_x23662, _x23663, _x23664, _ctx); /*double*/
  z00 = kk_std_num_ddouble__new_Edouble(z0, err0, _ctx); /*std/num/ddouble/edouble*/
  double e;
  double _x23665;
  double _x10 = z00.err;
  _x23665 = _x10; /*double*/
  double _x23666;
  double _x23667;
  double _x23668;
  double _x2 = x0_21180.hi;
  _x23668 = _x2; /*double*/
  double _x23669;
  double _x3 = y0_21181.lo;
  _x23669 = _x3; /*double*/
  _x23667 = (_x23668 * _x23669); /*double*/
  double _x23670;
  double _x23671;
  double _x4 = x0_21180.lo;
  _x23671 = _x4; /*double*/
  double _x23672;
  double _x5 = y0_21181.hi;
  _x23672 = _x5; /*double*/
  _x23670 = (_x23671 * _x23672); /*double*/
  _x23666 = (_x23667 + _x23670); /*double*/
  e = (_x23665 + _x23666); /*double*/
  bool _match_21749;
  bool _x23673;
  double _x23674;
  double _x6 = z00.num;
  _x23674 = _x6; /*double*/
  _x23673 = isfinite(_x23674); /*bool*/
  _match_21749 = !(_x23673); /*bool*/
  if (_match_21749) {
    double _x23675;
    double _x60 = z00.num;
    _x23675 = _x60; /*double*/
    return kk_std_num_ddouble_ddouble(_x23675, _ctx);
  }
  double z1;
  double _x23676;
  double _x61 = z00.num;
  _x23676 = _x61; /*double*/
  z1 = (_x23676 + e); /*double*/
  double err00;
  double _x23677;
  double _x23678;
  double _x62 = z00.num;
  _x23678 = _x62; /*double*/
  _x23677 = (z1 - _x23678); /*double*/
  err00 = (e - _x23677); /*double*/
  double _x23679;
  bool _match_21750 = isfinite(z1); /*bool*/;
  if (_match_21750) {
    _x23679 = err00; /*double*/
  }
  else {
    _x23679 = z1; /*double*/
  }
  return kk_std_num_ddouble__new_Ddouble(z1, _x23679, _ctx);
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble_log2p1(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> ddouble */ 
  kk_std_num_ddouble__ddouble x0_21182 = kk_std_num_ddouble__new_Ddouble(0x1.62e42fefa39efp-1, 0x1.abc9e3b39803fp-56, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__ddouble y_21183 = kk_std_num_ddouble_log1p(x, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__edouble z0;
  double z;
  double _x23682;
  double _x = x0_21182.hi;
  _x23682 = _x; /*double*/
  double _x23683;
  double _x0 = y_21183.hi;
  _x23683 = _x0; /*double*/
  z = (_x23682 * _x23683); /*double*/
  double err0;
  double _x23684;
  double _x1 = x0_21182.hi;
  _x23684 = _x1; /*double*/
  double _x23685;
  double _x00 = y_21183.hi;
  _x23685 = _x00; /*double*/
  double _x23686 = (-z); /*double*/
  err0 = kk_std_num_double_fmadd(_x23684, _x23685, _x23686, _ctx); /*double*/
  z0 = kk_std_num_ddouble__new_Edouble(z, err0, _ctx); /*std/num/ddouble/edouble*/
  double e;
  double _x23687;
  double _x10 = z0.err;
  _x23687 = _x10; /*double*/
  double _x23688;
  double _x23689;
  double _x23690;
  double _x2 = x0_21182.hi;
  _x23690 = _x2; /*double*/
  double _x23691;
  double _x3 = y_21183.lo;
  _x23691 = _x3; /*double*/
  _x23689 = (_x23690 * _x23691); /*double*/
  double _x23692;
  double _x23693;
  double _x4 = x0_21182.lo;
  _x23693 = _x4; /*double*/
  double _x23694;
  double _x5 = y_21183.hi;
  _x23694 = _x5; /*double*/
  _x23692 = (_x23693 * _x23694); /*double*/
  _x23688 = (_x23689 + _x23692); /*double*/
  e = (_x23687 + _x23688); /*double*/
  bool _match_21745;
  bool _x23695;
  double _x23696;
  double _x6 = z0.num;
  _x23696 = _x6; /*double*/
  _x23695 = isfinite(_x23696); /*bool*/
  _match_21745 = !(_x23695); /*bool*/
  if (_match_21745) {
    double _x23697;
    double _x60 = z0.num;
    _x23697 = _x60; /*double*/
    return kk_std_num_ddouble_ddouble(_x23697, _ctx);
  }
  double z1;
  double _x23698;
  double _x61 = z0.num;
  _x23698 = _x61; /*double*/
  z1 = (_x23698 + e); /*double*/
  double err00;
  double _x23699;
  double _x23700;
  double _x62 = z0.num;
  _x23700 = _x62; /*double*/
  _x23699 = (z1 - _x23700); /*double*/
  err00 = (e - _x23699); /*double*/
  double _x23701;
  bool _match_21746 = isfinite(z1); /*bool*/;
  if (_match_21746) {
    _x23701 = err00; /*double*/
  }
  else {
    _x23701 = z1; /*double*/
  }
  return kk_std_num_ddouble__new_Ddouble(z1, _x23701, _ctx);
}
 
// Returns `log(exp(x) + exp(y))`.
// Avoids overlow/underflow errors.

kk_std_num_ddouble__ddouble kk_std_num_ddouble_logaddexp(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_context_t* _ctx) { /* (x : ddouble, y : ddouble) -> ddouble */ 
  bool _match_21735 = kk_std_num_ddouble__lp__eq__eq__rp_(x, y, _ctx); /*bool*/;
  if (_match_21735) {
    kk_std_num_ddouble__ddouble _x23702 = kk_std_num_ddouble__new_Ddouble(0x1.62e42fefa39efp-1, 0x1.abc9e3b39803fp-56, _ctx); /*std/num/ddouble/ddouble*/
    return kk_std_num_ddouble__lp__plus__rp_(x, _x23702, _ctx);
  }
  kk_std_num_ddouble__ddouble z = kk_std_num_ddouble__lp__dash__rp_(x, y, _ctx); /*std/num/ddouble/ddouble*/;
  bool _match_21736 = kk_std_num_ddouble_is_pos(z, _ctx); /*bool*/;
  if (_match_21736) {
    kk_std_num_ddouble__ddouble _x23703;
    kk_std_num_ddouble__ddouble x0_21036;
    kk_std_num_ddouble__ddouble _x23704 = kk_std_num_ddouble__lp__tilde__rp_(z, _ctx); /*std/num/ddouble/ddouble*/
    x0_21036 = kk_std_num_ddouble_exp(_x23704, _ctx); /*std/num/ddouble/ddouble*/
    bool _match_21741 = kk_std_num_ddouble_is_posinf(x0_21036, _ctx); /*bool*/;
    if (_match_21741) {
      _x23703 = x0_21036; /*std/num/ddouble/ddouble*/
    }
    else {
      kk_std_num_ddouble__ddouble y0;
      kk_std_num_ddouble__ddouble _x23705 = kk_std_num_ddouble__new_Ddouble(0x1p0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
      y0 = kk_std_num_ddouble__lp__plus__rp_(_x23705, x0_21036, _ctx); /*std/num/ddouble/ddouble*/
      kk_std_num_ddouble__ddouble z0;
      kk_std_num_ddouble__ddouble _x23706 = kk_std_num_ddouble__new_Ddouble(0x1p0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
      z0 = kk_std_num_ddouble__lp__dash__rp_(y0, _x23706, _ctx); /*std/num/ddouble/ddouble*/
      bool _match_21742 = kk_std_num_ddouble_is_zero(z0, _ctx); /*bool*/;
      if (_match_21742) {
        _x23703 = x0_21036; /*std/num/ddouble/ddouble*/
      }
      else {
        kk_std_num_ddouble__ddouble x0_21184 = kk_std_num_ddouble_log(y0, _ctx); /*std/num/ddouble/ddouble*/;
        kk_std_num_ddouble__ddouble y1_21185 = kk_std_num_ddouble__lp__fs__rp_(x0_21036, z0, _ctx); /*std/num/ddouble/ddouble*/;
        kk_std_num_ddouble__edouble z00;
        double z1;
        double _x23707;
        double _x = x0_21184.hi;
        _x23707 = _x; /*double*/
        double _x23708;
        double _x0 = y1_21185.hi;
        _x23708 = _x0; /*double*/
        z1 = (_x23707 * _x23708); /*double*/
        double err0;
        double _x23709;
        double _x1 = x0_21184.hi;
        _x23709 = _x1; /*double*/
        double _x23710;
        double _x00 = y1_21185.hi;
        _x23710 = _x00; /*double*/
        double _x23711 = (-z1); /*double*/
        err0 = kk_std_num_double_fmadd(_x23709, _x23710, _x23711, _ctx); /*double*/
        z00 = kk_std_num_ddouble__new_Edouble(z1, err0, _ctx); /*std/num/ddouble/edouble*/
        double e;
        double _x23712;
        double _x10 = z00.err;
        _x23712 = _x10; /*double*/
        double _x23713;
        double _x23714;
        double _x23715;
        double _x2 = x0_21184.hi;
        _x23715 = _x2; /*double*/
        double _x23716;
        double _x3 = y1_21185.lo;
        _x23716 = _x3; /*double*/
        _x23714 = (_x23715 * _x23716); /*double*/
        double _x23717;
        double _x23718;
        double _x4 = x0_21184.lo;
        _x23718 = _x4; /*double*/
        double _x23719;
        double _x5 = y1_21185.hi;
        _x23719 = _x5; /*double*/
        _x23717 = (_x23718 * _x23719); /*double*/
        _x23713 = (_x23714 + _x23717); /*double*/
        e = (_x23712 + _x23713); /*double*/
        bool _match_21743;
        bool _x23720;
        double _x23721;
        double _x6 = z00.num;
        _x23721 = _x6; /*double*/
        _x23720 = isfinite(_x23721); /*bool*/
        _match_21743 = !(_x23720); /*bool*/
        if (_match_21743) {
          double _x23722;
          double _x60 = z00.num;
          _x23722 = _x60; /*double*/
          _x23703 = kk_std_num_ddouble_ddouble(_x23722, _ctx); /*std/num/ddouble/ddouble*/
        }
        else {
          double z10;
          double _x23723;
          double _x61 = z00.num;
          _x23723 = _x61; /*double*/
          z10 = (_x23723 + e); /*double*/
          double err00;
          double _x23724;
          double _x23725;
          double _x62 = z00.num;
          _x23725 = _x62; /*double*/
          _x23724 = (z10 - _x23725); /*double*/
          err00 = (e - _x23724); /*double*/
          double _x23726;
          bool _match_21744 = isfinite(z10); /*bool*/;
          if (_match_21744) {
            _x23726 = err00; /*double*/
          }
          else {
            _x23726 = z10; /*double*/
          }
          _x23703 = kk_std_num_ddouble__new_Ddouble(z10, _x23726, _ctx); /*std/num/ddouble/ddouble*/
        }
      }
    }
    return kk_std_num_ddouble__lp__plus__rp_(x, _x23703, _ctx);
  }
  kk_std_num_ddouble__ddouble _x23727;
  kk_std_num_ddouble__ddouble x1_21037 = kk_std_num_ddouble_exp(z, _ctx); /*std/num/ddouble/ddouble*/;
  bool _match_21737 = kk_std_num_ddouble_is_posinf(x1_21037, _ctx); /*bool*/;
  if (_match_21737) {
    _x23727 = x1_21037; /*std/num/ddouble/ddouble*/
  }
  else {
    kk_std_num_ddouble__ddouble y10;
    kk_std_num_ddouble__ddouble _x23728 = kk_std_num_ddouble__new_Ddouble(0x1p0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    y10 = kk_std_num_ddouble__lp__plus__rp_(_x23728, x1_21037, _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble z11;
    kk_std_num_ddouble__ddouble _x23729 = kk_std_num_ddouble__new_Ddouble(0x1p0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    z11 = kk_std_num_ddouble__lp__dash__rp_(y10, _x23729, _ctx); /*std/num/ddouble/ddouble*/
    bool _match_21738 = kk_std_num_ddouble_is_zero(z11, _ctx); /*bool*/;
    if (_match_21738) {
      _x23727 = x1_21037; /*std/num/ddouble/ddouble*/
    }
    else {
      kk_std_num_ddouble__ddouble x1_21186 = kk_std_num_ddouble_log(y10, _ctx); /*std/num/ddouble/ddouble*/;
      kk_std_num_ddouble__ddouble y2_21187 = kk_std_num_ddouble__lp__fs__rp_(x1_21037, z11, _ctx); /*std/num/ddouble/ddouble*/;
      kk_std_num_ddouble__edouble z01;
      double z2;
      double _x23730;
      double _x7 = x1_21186.hi;
      _x23730 = _x7; /*double*/
      double _x23731;
      double _x000 = y2_21187.hi;
      _x23731 = _x000; /*double*/
      z2 = (_x23730 * _x23731); /*double*/
      double err1;
      double _x23732;
      double _x70 = x1_21186.hi;
      _x23732 = _x70; /*double*/
      double _x23733;
      double _x001 = y2_21187.hi;
      _x23733 = _x001; /*double*/
      double _x23734 = (-z2); /*double*/
      err1 = kk_std_num_double_fmadd(_x23732, _x23733, _x23734, _ctx); /*double*/
      z01 = kk_std_num_ddouble__new_Edouble(z2, err1, _ctx); /*std/num/ddouble/edouble*/
      double e0;
      double _x23735;
      double _x100 = z01.err;
      _x23735 = _x100; /*double*/
      double _x23736;
      double _x23737;
      double _x23738;
      double _x20 = x1_21186.hi;
      _x23738 = _x20; /*double*/
      double _x23739;
      double _x30 = y2_21187.lo;
      _x23739 = _x30; /*double*/
      _x23737 = (_x23738 * _x23739); /*double*/
      double _x23740;
      double _x23741;
      double _x40 = x1_21186.lo;
      _x23741 = _x40; /*double*/
      double _x23742;
      double _x50 = y2_21187.hi;
      _x23742 = _x50; /*double*/
      _x23740 = (_x23741 * _x23742); /*double*/
      _x23736 = (_x23737 + _x23740); /*double*/
      e0 = (_x23735 + _x23736); /*double*/
      bool _match_21739;
      bool _x23743;
      double _x23744;
      double _x600 = z01.num;
      _x23744 = _x600; /*double*/
      _x23743 = isfinite(_x23744); /*bool*/
      _match_21739 = !(_x23743); /*bool*/
      if (_match_21739) {
        double _x23745;
        double _x601 = z01.num;
        _x23745 = _x601; /*double*/
        _x23727 = kk_std_num_ddouble_ddouble(_x23745, _ctx); /*std/num/ddouble/ddouble*/
      }
      else {
        double z12;
        double _x23746;
        double _x602 = z01.num;
        _x23746 = _x602; /*double*/
        z12 = (_x23746 + e0); /*double*/
        double err000;
        double _x23747;
        double _x23748;
        double _x603 = z01.num;
        _x23748 = _x603; /*double*/
        _x23747 = (z12 - _x23748); /*double*/
        err000 = (e0 - _x23747); /*double*/
        double _x23749;
        bool _match_21740 = isfinite(z12); /*bool*/;
        if (_match_21740) {
          _x23749 = err000; /*double*/
        }
        else {
          _x23749 = z12; /*double*/
        }
        _x23727 = kk_std_num_ddouble__new_Ddouble(z12, _x23749, _ctx); /*std/num/ddouble/ddouble*/
      }
    }
  }
  return kk_std_num_ddouble__lp__plus__rp_(y, _x23727, _ctx);
}
 
// Returns `log2( exp2(x) + exp2(y) )`.
// Avoids overlow/underflow errors.

kk_std_num_ddouble__ddouble kk_std_num_ddouble_logaddexp2(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_context_t* _ctx) { /* (x : ddouble, y : ddouble) -> ddouble */ 
  bool _match_21729 = kk_std_num_ddouble__lp__eq__eq__rp_(x, y, _ctx); /*bool*/;
  if (_match_21729) {
    kk_std_num_ddouble__ddouble _x23750 = kk_std_num_ddouble__new_Ddouble(0x1p0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    return kk_std_num_ddouble__lp__plus__rp_(x, _x23750, _ctx);
  }
  kk_std_num_ddouble__ddouble z = kk_std_num_ddouble__lp__dash__rp_(x, y, _ctx); /*std/num/ddouble/ddouble*/;
  bool _match_21730 = kk_std_num_ddouble_is_pos(z, _ctx); /*bool*/;
  if (_match_21730) {
    kk_std_num_ddouble__ddouble _x23751;
    kk_std_num_ddouble__ddouble x0_21038;
    kk_std_num_ddouble__ddouble exp_21039 = kk_std_num_ddouble__lp__tilde__rp_(z, _ctx); /*std/num/ddouble/ddouble*/;
    kk_std_num_ddouble__ddouble _x23752 = kk_std_num_ddouble__new_Ddouble(0x1p1, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    x0_21038 = kk_std_num_ddouble_pow(_x23752, exp_21039, _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble x0_21188 = kk_std_num_ddouble__new_Ddouble(0x1.62e42fefa39efp-1, 0x1.abc9e3b39803fp-56, _ctx); /*std/num/ddouble/ddouble*/;
    kk_std_num_ddouble__ddouble y0_21189 = kk_std_num_ddouble_log1p(x0_21038, _ctx); /*std/num/ddouble/ddouble*/;
    kk_std_num_ddouble__edouble z00;
    double z0;
    double _x23753;
    double _x = x0_21188.hi;
    _x23753 = _x; /*double*/
    double _x23754;
    double _x0 = y0_21189.hi;
    _x23754 = _x0; /*double*/
    z0 = (_x23753 * _x23754); /*double*/
    double err0;
    double _x23755;
    double _x1 = x0_21188.hi;
    _x23755 = _x1; /*double*/
    double _x23756;
    double _x00 = y0_21189.hi;
    _x23756 = _x00; /*double*/
    double _x23757 = (-z0); /*double*/
    err0 = kk_std_num_double_fmadd(_x23755, _x23756, _x23757, _ctx); /*double*/
    z00 = kk_std_num_ddouble__new_Edouble(z0, err0, _ctx); /*std/num/ddouble/edouble*/
    double e;
    double _x23758;
    double _x10 = z00.err;
    _x23758 = _x10; /*double*/
    double _x23759;
    double _x23760;
    double _x23761;
    double _x2 = x0_21188.hi;
    _x23761 = _x2; /*double*/
    double _x23762;
    double _x3 = y0_21189.lo;
    _x23762 = _x3; /*double*/
    _x23760 = (_x23761 * _x23762); /*double*/
    double _x23763;
    double _x23764;
    double _x4 = x0_21188.lo;
    _x23764 = _x4; /*double*/
    double _x23765;
    double _x5 = y0_21189.hi;
    _x23765 = _x5; /*double*/
    _x23763 = (_x23764 * _x23765); /*double*/
    _x23759 = (_x23760 + _x23763); /*double*/
    e = (_x23758 + _x23759); /*double*/
    bool _match_21733;
    bool _x23766;
    double _x23767;
    double _x6 = z00.num;
    _x23767 = _x6; /*double*/
    _x23766 = isfinite(_x23767); /*bool*/
    _match_21733 = !(_x23766); /*bool*/
    if (_match_21733) {
      double _x23768;
      double _x60 = z00.num;
      _x23768 = _x60; /*double*/
      _x23751 = kk_std_num_ddouble_ddouble(_x23768, _ctx); /*std/num/ddouble/ddouble*/
    }
    else {
      double z1;
      double _x23769;
      double _x61 = z00.num;
      _x23769 = _x61; /*double*/
      z1 = (_x23769 + e); /*double*/
      double err00;
      double _x23770;
      double _x23771;
      double _x62 = z00.num;
      _x23771 = _x62; /*double*/
      _x23770 = (z1 - _x23771); /*double*/
      err00 = (e - _x23770); /*double*/
      double _x23772;
      bool _match_21734 = isfinite(z1); /*bool*/;
      if (_match_21734) {
        _x23772 = err00; /*double*/
      }
      else {
        _x23772 = z1; /*double*/
      }
      _x23751 = kk_std_num_ddouble__new_Ddouble(z1, _x23772, _ctx); /*std/num/ddouble/ddouble*/
    }
    return kk_std_num_ddouble__lp__plus__rp_(x, _x23751, _ctx);
  }
  kk_std_num_ddouble__ddouble _x23773;
  kk_std_num_ddouble__ddouble x1_21040 = kk_std_num_ddouble_exp2(z, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__ddouble x1_21190 = kk_std_num_ddouble__new_Ddouble(0x1.62e42fefa39efp-1, 0x1.abc9e3b39803fp-56, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__ddouble y1_21191 = kk_std_num_ddouble_log1p(x1_21040, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__edouble z01;
  double z2;
  double _x23774;
  double _x7 = x1_21190.hi;
  _x23774 = _x7; /*double*/
  double _x23775;
  double _x000 = y1_21191.hi;
  _x23775 = _x000; /*double*/
  z2 = (_x23774 * _x23775); /*double*/
  double err1;
  double _x23776;
  double _x70 = x1_21190.hi;
  _x23776 = _x70; /*double*/
  double _x23777;
  double _x001 = y1_21191.hi;
  _x23777 = _x001; /*double*/
  double _x23778 = (-z2); /*double*/
  err1 = kk_std_num_double_fmadd(_x23776, _x23777, _x23778, _ctx); /*double*/
  z01 = kk_std_num_ddouble__new_Edouble(z2, err1, _ctx); /*std/num/ddouble/edouble*/
  double e0;
  double _x23779;
  double _x100 = z01.err;
  _x23779 = _x100; /*double*/
  double _x23780;
  double _x23781;
  double _x23782;
  double _x20 = x1_21190.hi;
  _x23782 = _x20; /*double*/
  double _x23783;
  double _x30 = y1_21191.lo;
  _x23783 = _x30; /*double*/
  _x23781 = (_x23782 * _x23783); /*double*/
  double _x23784;
  double _x23785;
  double _x40 = x1_21190.lo;
  _x23785 = _x40; /*double*/
  double _x23786;
  double _x50 = y1_21191.hi;
  _x23786 = _x50; /*double*/
  _x23784 = (_x23785 * _x23786); /*double*/
  _x23780 = (_x23781 + _x23784); /*double*/
  e0 = (_x23779 + _x23780); /*double*/
  bool _match_21731;
  bool _x23787;
  double _x23788;
  double _x600 = z01.num;
  _x23788 = _x600; /*double*/
  _x23787 = isfinite(_x23788); /*bool*/
  _match_21731 = !(_x23787); /*bool*/
  if (_match_21731) {
    double _x23789;
    double _x601 = z01.num;
    _x23789 = _x601; /*double*/
    _x23773 = kk_std_num_ddouble_ddouble(_x23789, _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    double z10;
    double _x23790;
    double _x602 = z01.num;
    _x23790 = _x602; /*double*/
    z10 = (_x23790 + e0); /*double*/
    double err000;
    double _x23791;
    double _x23792;
    double _x603 = z01.num;
    _x23792 = _x603; /*double*/
    _x23791 = (z10 - _x23792); /*double*/
    err000 = (e0 - _x23791); /*double*/
    double _x23793;
    bool _match_21732 = isfinite(z10); /*bool*/;
    if (_match_21732) {
      _x23793 = err000; /*double*/
    }
    else {
      _x23793 = z10; /*double*/
    }
    _x23773 = kk_std_num_ddouble__new_Ddouble(z10, _x23793, _ctx); /*std/num/ddouble/ddouble*/
  }
  return kk_std_num_ddouble__lp__plus__rp_(y, _x23773, _ctx);
}
 
// Return if two `:ddouble`s are nearly equal with respect to some `epsilon` (=`8*dd-epsilon`).
// The epsilon is the nearest difference for numbers around 1.0. The routine automatically
// scales the epsilon for larger and smaller numbers, and for numbers close to zero.

bool kk_std_num_ddouble_nearly_eq(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_std_core_types__optional epsilon, kk_context_t* _ctx) { /* (x : ddouble, y : ddouble, epsilon : optional<ddouble>) -> bool */ 
  bool _match_21717 = kk_std_num_ddouble__lp__eq__eq__rp_(x, y, _ctx); /*bool*/;
  if (_match_21717) {
    kk_std_core_types__optional_drop(epsilon, _ctx);
    return true;
  }
  kk_std_num_ddouble__ddouble diff;
  kk_std_num_ddouble__ddouble x0_21041 = kk_std_num_ddouble__lp__dash__rp_(x, y, _ctx); /*std/num/ddouble/ddouble*/;
  bool _match_21728 = kk_std_num_ddouble_is_neg(x0_21041, _ctx); /*bool*/;
  if (_match_21728) {
    diff = kk_std_num_ddouble__lp__tilde__rp_(x0_21041, _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    diff = x0_21041; /*std/num/ddouble/ddouble*/
  }
  bool _match_21718;
  bool _match_21725 = kk_std_num_ddouble_is_zero(x, _ctx); /*bool*/;
  if (_match_21725) {
    _match_21718 = true; /*bool*/
  }
  else {
    bool _match_21726 = kk_std_num_ddouble_is_zero(y, _ctx); /*bool*/;
    if (_match_21726) {
      _match_21718 = true; /*bool*/
    }
    else {
      kk_std_num_ddouble__ddouble y0_21193 = kk_std_num_ddouble__new_Ddouble(0x1p-1022, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/;
      kk_std_core_types__order x0_20773 = kk_std_num_ddouble_compare(diff, y0_21193, _ctx); /*order*/;
      kk_integer_t _x23794 = kk_std_core_int_5(x0_20773, _ctx); /*int*/
      kk_integer_t _x23795;
      kk_std_core_types__order _x23796 = kk_std_core_types__new_Lt(_ctx); /*order*/
      if (kk_std_core_types__is_Lt(_x23796)) {
        _x23795 = kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context()); /*int*/
        goto _match23797;
      }
      if (kk_std_core_types__is_Eq(_x23796)) {
        _x23795 = kk_integer_from_small(0); /*int*/
        goto _match23797;
      }
      _x23795 = kk_integer_from_small(1); /*int*/
      _match23797: ;
      _match_21718 = kk_integer_eq(_x23794,_x23795,kk_context()); /*bool*/
    }
  }
  if (_match_21718) {
    kk_std_num_ddouble__ddouble x1_21042;
    kk_std_num_ddouble__ddouble _x23798 = kk_std_num_ddouble__new_Ddouble(0x1p1, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    x1_21042 = kk_std_num_ddouble__lp__star__rp_(_x23798, diff, _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble y0_21043;
    kk_std_num_ddouble__ddouble x2_21195;
    if (kk_std_core_types__is_Optional(epsilon)) {
      kk_box_t _box_x21620 = epsilon._cons.Optional.value;
      kk_std_num_ddouble__ddouble _epsilon_17155 = kk_std_num_ddouble__ddouble_unbox(_box_x21620, NULL);
      kk_std_core_types__optional_drop(epsilon, _ctx);
      x2_21195 = _epsilon_17155; /*std/num/ddouble/ddouble*/
      goto _match23799;
    }
    x2_21195 = kk_std_num_ddouble__new_Ddouble(0x1p-101, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    _match23799: ;
    kk_std_num_ddouble__ddouble y1_21196 = kk_std_num_ddouble__new_Ddouble(0x1p-1022, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/;
    kk_std_num_ddouble__edouble z0;
    double z;
    double _x23801;
    double _x = x2_21195.hi;
    _x23801 = _x; /*double*/
    double _x23802;
    double _x0 = y1_21196.hi;
    _x23802 = _x0; /*double*/
    z = (_x23801 * _x23802); /*double*/
    double err0;
    double _x23803;
    double _x1 = x2_21195.hi;
    _x23803 = _x1; /*double*/
    double _x23804;
    double _x00 = y1_21196.hi;
    _x23804 = _x00; /*double*/
    double _x23805 = (-z); /*double*/
    err0 = kk_std_num_double_fmadd(_x23803, _x23804, _x23805, _ctx); /*double*/
    z0 = kk_std_num_ddouble__new_Edouble(z, err0, _ctx); /*std/num/ddouble/edouble*/
    double e;
    double _x23806;
    double _x10 = z0.err;
    _x23806 = _x10; /*double*/
    double _x23807;
    double _x23808;
    double _x23809;
    double _x2 = x2_21195.hi;
    _x23809 = _x2; /*double*/
    double _x23810;
    double _x3 = y1_21196.lo;
    _x23810 = _x3; /*double*/
    _x23808 = (_x23809 * _x23810); /*double*/
    double _x23811;
    double _x23812;
    double _x4 = x2_21195.lo;
    _x23812 = _x4; /*double*/
    double _x23813;
    double _x5 = y1_21196.hi;
    _x23813 = _x5; /*double*/
    _x23811 = (_x23812 * _x23813); /*double*/
    _x23807 = (_x23808 + _x23811); /*double*/
    e = (_x23806 + _x23807); /*double*/
    bool _match_21723;
    bool _x23814;
    double _x23815;
    double _x6 = z0.num;
    _x23815 = _x6; /*double*/
    _x23814 = isfinite(_x23815); /*bool*/
    _match_21723 = !(_x23814); /*bool*/
    if (_match_21723) {
      double _x23816;
      double _x60 = z0.num;
      _x23816 = _x60; /*double*/
      y0_21043 = kk_std_num_ddouble_ddouble(_x23816, _ctx); /*std/num/ddouble/ddouble*/
    }
    else {
      double z1;
      double _x23817;
      double _x61 = z0.num;
      _x23817 = _x61; /*double*/
      z1 = (_x23817 + e); /*double*/
      double err00;
      double _x23818;
      double _x23819;
      double _x62 = z0.num;
      _x23819 = _x62; /*double*/
      _x23818 = (z1 - _x23819); /*double*/
      err00 = (e - _x23818); /*double*/
      double _x23820;
      bool _match_21724 = isfinite(z1); /*bool*/;
      if (_match_21724) {
        _x23820 = err00; /*double*/
      }
      else {
        _x23820 = z1; /*double*/
      }
      y0_21043 = kk_std_num_ddouble__new_Ddouble(z1, _x23820, _ctx); /*std/num/ddouble/ddouble*/
    }
    kk_std_core_types__order x2_21044 = kk_std_num_ddouble_compare(x1_21042, y0_21043, _ctx); /*order*/;
    kk_integer_t _x23821 = kk_std_core_int_5(x2_21044, _ctx); /*int*/
    kk_integer_t _x23822;
    kk_std_core_types__order _x23823 = kk_std_core_types__new_Lt(_ctx); /*order*/
    if (kk_std_core_types__is_Lt(_x23823)) {
      _x23822 = kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context()); /*int*/
      goto _match23824;
    }
    if (kk_std_core_types__is_Eq(_x23823)) {
      _x23822 = kk_integer_from_small(0); /*int*/
      goto _match23824;
    }
    _x23822 = kk_integer_from_small(1); /*int*/
    _match23824: ;
    return kk_integer_eq(_x23821,_x23822,kk_context());
  }
  kk_std_num_ddouble__ddouble sum0;
  kk_std_num_ddouble__ddouble _x23825 = kk_std_num_ddouble_abs(x, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x23826 = kk_std_num_ddouble_abs(y, _ctx); /*std/num/ddouble/ddouble*/
  sum0 = kk_std_num_ddouble__lp__plus__rp_(_x23825, _x23826, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble x3_21046;
  kk_std_num_ddouble__ddouble _x23827;
  kk_std_num_ddouble__ddouble _x23828 = kk_std_num_ddouble__new_Ddouble(0x1p1, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  _x23827 = kk_std_num_ddouble__lp__star__rp_(_x23828, diff, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x23829;
  bool _match_21720;
  kk_std_num_ddouble__ddouble y2_21199 = kk_std_num_ddouble__new_Ddouble(0x1.fffffffffffffp1023, 0x1.fffffffffffffp969, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_core_types__order x0_20775 = kk_std_num_ddouble_compare(sum0, y2_21199, _ctx); /*order*/;
  kk_integer_t _x23830 = kk_std_core_int_5(x0_20775, _ctx); /*int*/
  kk_integer_t _x23831;
  kk_std_core_types__order _x23832 = kk_std_core_types__new_Gt(_ctx); /*order*/
  if (kk_std_core_types__is_Lt(_x23832)) {
    _x23831 = kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context()); /*int*/
    goto _match23833;
  }
  if (kk_std_core_types__is_Eq(_x23832)) {
    _x23831 = kk_integer_from_small(0); /*int*/
    goto _match23833;
  }
  _x23831 = kk_integer_from_small(1); /*int*/
  _match23833: ;
  _match_21720 = kk_integer_eq(_x23830,_x23831,kk_context()); /*bool*/
  if (_match_21720) {
    _x23829 = kk_std_num_ddouble__new_Ddouble(0x1.fffffffffffffp1023, 0x1.fffffffffffffp969, _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    _x23829 = sum0; /*std/num/ddouble/ddouble*/
  }
  x3_21046 = kk_std_num_ddouble__lp__fs__rp_(_x23827, _x23829, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble y2_21047;
  if (kk_std_core_types__is_Optional(epsilon)) {
    kk_box_t _box_x21621 = epsilon._cons.Optional.value;
    kk_std_num_ddouble__ddouble _epsilon_171550 = kk_std_num_ddouble__ddouble_unbox(_box_x21621, NULL);
    kk_std_core_types__optional_drop(epsilon, _ctx);
    y2_21047 = _epsilon_171550; /*std/num/ddouble/ddouble*/
    goto _match23834;
  }
  y2_21047 = kk_std_num_ddouble__new_Ddouble(0x1p-101, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  _match23834: ;
  kk_std_core_types__order x4_21048 = kk_std_num_ddouble_compare(x3_21046, y2_21047, _ctx); /*order*/;
  kk_integer_t _x23836 = kk_std_core_int_5(x4_21048, _ctx); /*int*/
  kk_integer_t _x23837;
  kk_std_core_types__order _x23838 = kk_std_core_types__new_Lt(_ctx); /*order*/
  if (kk_std_core_types__is_Lt(_x23838)) {
    _x23837 = kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context()); /*int*/
    goto _match23839;
  }
  if (kk_std_core_types__is_Eq(_x23838)) {
    _x23837 = kk_integer_from_small(0); /*int*/
    goto _match23839;
  }
  _x23837 = kk_integer_from_small(1); /*int*/
  _match23839: ;
  return kk_integer_eq(_x23836,_x23837,kk_context());
}
 
// The `n`-th root of a `:ddouble` number `x`.
// `n` must be positive, and if `n` is even, then
// `x` must not be negative.

kk_std_num_ddouble__ddouble kk_std_num_ddouble_nroot(kk_std_num_ddouble__ddouble x, kk_integer_t n, kk_context_t* _ctx) { /* (x : ddouble, n : int) -> ddouble */ 
  bool _match_21706;
  kk_integer_t _x23840 = kk_integer_dup(n); /*int*/
  _match_21706 = kk_integer_eq(_x23840,(kk_integer_from_small(2)),kk_context()); /*bool*/
  if (_match_21706) {
    kk_integer_drop(n, _ctx);
    return kk_std_num_ddouble_sqrt(x, _ctx);
  }
  bool _match_21707;
  kk_integer_t _x23841 = kk_integer_dup(n); /*int*/
  _match_21707 = kk_integer_eq(_x23841,(kk_integer_from_small(1)),kk_context()); /*bool*/
  if (_match_21707) {
    kk_integer_drop(n, _ctx);
    return x;
  }
  bool _match_21708;
  bool _match_21715;
  kk_integer_t _x23842 = kk_integer_dup(n); /*int*/
  _match_21715 = kk_integer_lte(_x23842,(kk_integer_from_small(0)),kk_context()); /*bool*/
  if (_match_21715) {
    _match_21708 = true; /*bool*/
  }
  else {
    bool _match_21716;
    kk_integer_t _x23843 = kk_integer_dup(n); /*int*/
    _match_21716 = kk_std_core_is_even(_x23843, _ctx); /*bool*/
    if (_match_21716) {
      _match_21708 = kk_std_num_ddouble_is_neg(x, _ctx); /*bool*/
    }
    else {
      _match_21708 = false; /*bool*/
    }
  }
  if (_match_21708) {
    kk_integer_drop(n, _ctx);
    return kk_std_num_ddouble_dd_nan;
  }
  bool _match_21709 = kk_std_num_ddouble_is_zero(x, _ctx); /*bool*/;
  if (_match_21709) {
    kk_integer_drop(n, _ctx);
    return kk_std_num_ddouble__new_Ddouble(0x0p+0, 0x0p+0, _ctx);
  }
  kk_std_num_ddouble__ddouble r = kk_std_num_ddouble_abs(x, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__ddouble a0;
  double d_21050;
  double _x23844;
  double _x23845;
  double _x23846;
  double _x23847;
  double _x = r.hi;
  _x23847 = _x; /*double*/
  _x23846 = log(_x23847); /*double*/
  _x23845 = (-_x23846); /*double*/
  double _x23848;
  kk_integer_t _x23849 = kk_integer_dup(n); /*int*/
  _x23848 = kk_integer_as_double(_x23849,kk_context()); /*double*/
  _x23844 = (_x23845 / _x23848); /*double*/
  d_21050 = exp(_x23844); /*double*/
  a0 = kk_std_num_ddouble__new_Ddouble(d_21050, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble a1;
  kk_std_num_ddouble__ddouble _x23850;
  kk_std_num_ddouble__ddouble _x23851;
  kk_std_num_ddouble__ddouble y_21203;
  kk_std_num_ddouble__ddouble y_21053;
  kk_std_num_ddouble__ddouble y0_21205;
  kk_integer_t _x23852 = kk_integer_dup(n); /*int*/
  y0_21205 = kk_std_num_ddouble_powi(a0, _x23852, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__edouble z00;
  double z2;
  double _x23853;
  double _x7 = r.hi;
  _x23853 = _x7; /*double*/
  double _x23854;
  double _x01 = y0_21205.hi;
  _x23854 = _x01; /*double*/
  z2 = (_x23853 * _x23854); /*double*/
  double err1;
  double _x23855;
  double _x70 = r.hi;
  _x23855 = _x70; /*double*/
  double _x23856;
  double _x010 = y0_21205.hi;
  _x23856 = _x010; /*double*/
  double _x23857 = (-z2); /*double*/
  err1 = kk_std_num_double_fmadd(_x23855, _x23856, _x23857, _ctx); /*double*/
  z00 = kk_std_num_ddouble__new_Edouble(z2, err1, _ctx); /*std/num/ddouble/edouble*/
  double e0;
  double _x23858;
  double _x10 = z00.err;
  _x23858 = _x10; /*double*/
  double _x23859;
  double _x23860;
  double _x23861;
  double _x20 = r.hi;
  _x23861 = _x20; /*double*/
  double _x23862;
  double _x30 = y0_21205.lo;
  _x23862 = _x30; /*double*/
  _x23860 = (_x23861 * _x23862); /*double*/
  double _x23863;
  double _x23864;
  double _x40 = r.lo;
  _x23864 = _x40; /*double*/
  double _x23865;
  double _x50 = y0_21205.hi;
  _x23865 = _x50; /*double*/
  _x23863 = (_x23864 * _x23865); /*double*/
  _x23859 = (_x23860 + _x23863); /*double*/
  e0 = (_x23858 + _x23859); /*double*/
  bool _match_21713;
  bool _x23866;
  double _x23867;
  double _x60 = z00.num;
  _x23867 = _x60; /*double*/
  _x23866 = isfinite(_x23867); /*bool*/
  _match_21713 = !(_x23866); /*bool*/
  if (_match_21713) {
    double _x23868;
    double _x600 = z00.num;
    _x23868 = _x600; /*double*/
    y_21053 = kk_std_num_ddouble_ddouble(_x23868, _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    double z10;
    double _x23869;
    double _x601 = z00.num;
    _x23869 = _x601; /*double*/
    z10 = (_x23869 + e0); /*double*/
    double err00;
    double _x23870;
    double _x23871;
    double _x602 = z00.num;
    _x23871 = _x602; /*double*/
    _x23870 = (z10 - _x23871); /*double*/
    err00 = (e0 - _x23870); /*double*/
    double _x23872;
    bool _match_21714 = isfinite(z10); /*bool*/;
    if (_match_21714) {
      _x23872 = err00; /*double*/
    }
    else {
      _x23872 = z10; /*double*/
    }
    y_21053 = kk_std_num_ddouble__new_Ddouble(z10, _x23872, _ctx); /*std/num/ddouble/ddouble*/
  }
  kk_std_num_ddouble__ddouble _x23873 = kk_std_num_ddouble__new_Ddouble(0x1p0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x23874 = kk_std_num_ddouble__lp__tilde__rp_(y_21053, _ctx); /*std/num/ddouble/ddouble*/
  y_21203 = kk_std_num_ddouble__lp__plus__rp_(_x23873, _x23874, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__edouble z0;
  double z;
  double _x23875;
  double _x0 = a0.hi;
  _x23875 = _x0; /*double*/
  double _x23876;
  double _x00 = y_21203.hi;
  _x23876 = _x00; /*double*/
  z = (_x23875 * _x23876); /*double*/
  double err0;
  double _x23877;
  double _x02 = a0.hi;
  _x23877 = _x02; /*double*/
  double _x23878;
  double _x000 = y_21203.hi;
  _x23878 = _x000; /*double*/
  double _x23879 = (-z); /*double*/
  err0 = kk_std_num_double_fmadd(_x23877, _x23878, _x23879, _ctx); /*double*/
  z0 = kk_std_num_ddouble__new_Edouble(z, err0, _ctx); /*std/num/ddouble/edouble*/
  double e;
  double _x23880;
  double _x1 = z0.err;
  _x23880 = _x1; /*double*/
  double _x23881;
  double _x23882;
  double _x23883;
  double _x2 = a0.hi;
  _x23883 = _x2; /*double*/
  double _x23884;
  double _x3 = y_21203.lo;
  _x23884 = _x3; /*double*/
  _x23882 = (_x23883 * _x23884); /*double*/
  double _x23885;
  double _x23886;
  double _x4 = a0.lo;
  _x23886 = _x4; /*double*/
  double _x23887;
  double _x5 = y_21203.hi;
  _x23887 = _x5; /*double*/
  _x23885 = (_x23886 * _x23887); /*double*/
  _x23881 = (_x23882 + _x23885); /*double*/
  e = (_x23880 + _x23881); /*double*/
  bool _match_21711;
  bool _x23888;
  double _x23889;
  double _x6 = z0.num;
  _x23889 = _x6; /*double*/
  _x23888 = isfinite(_x23889); /*bool*/
  _match_21711 = !(_x23888); /*bool*/
  if (_match_21711) {
    double _x23890;
    double _x61 = z0.num;
    _x23890 = _x61; /*double*/
    _x23851 = kk_std_num_ddouble_ddouble(_x23890, _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    double z1;
    double _x23891;
    double _x62 = z0.num;
    _x23891 = _x62; /*double*/
    z1 = (_x23891 + e); /*double*/
    double err01;
    double _x23892;
    double _x23893;
    double _x63 = z0.num;
    _x23893 = _x63; /*double*/
    _x23892 = (z1 - _x23893); /*double*/
    err01 = (e - _x23892); /*double*/
    double _x23894;
    bool _match_21712 = isfinite(z1); /*bool*/;
    if (_match_21712) {
      _x23894 = err01; /*double*/
    }
    else {
      _x23894 = z1; /*double*/
    }
    _x23851 = kk_std_num_ddouble__new_Ddouble(z1, _x23894, _ctx); /*std/num/ddouble/ddouble*/
  }
  kk_std_num_ddouble__ddouble _x23895 = kk_std_num_ddouble_ddouble_1(n, _ctx); /*std/num/ddouble/ddouble*/
  _x23850 = kk_std_num_ddouble__lp__fs__rp_(_x23851, _x23895, _ctx); /*std/num/ddouble/ddouble*/
  a1 = kk_std_num_ddouble__lp__plus__rp_(a0, _x23850, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x23896;
  bool _match_21710;
  double _x23897;
  double _x020 = x.hi;
  _x23897 = _x020; /*double*/
  _match_21710 = (_x23897 < (0x0p+0)); /*bool*/
  if (_match_21710) {
    kk_std_num_ddouble__ddouble _x23898 = kk_std_num_ddouble__new_Ddouble(0x1p0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    _x23896 = kk_std_num_ddouble__lp__tilde__rp_(_x23898, _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    _x23896 = kk_std_num_ddouble__new_Ddouble(0x1p0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  }
  return kk_std_num_ddouble__lp__fs__rp_(_x23896, a1, _ctx);
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble_one_half;
 
// Round a `:ddouble` to a specified precision.
// Uses `round` if the precision is smaller or equal to zero.

kk_std_num_ddouble__ddouble kk_std_num_ddouble_round_to_prec(kk_std_num_ddouble__ddouble x, kk_integer_t prec, kk_context_t* _ctx) { /* (x : ddouble, prec : int) -> ddouble */ 
  bool _match_21704;
  kk_integer_t _x23899 = kk_integer_dup(prec); /*int*/
  _match_21704 = kk_integer_lte(_x23899,(kk_integer_from_small(0)),kk_context()); /*bool*/
  if (_match_21704) {
    kk_integer_drop(prec, _ctx);
    return kk_std_num_ddouble_round(x, _ctx);
  }
  bool _match_21705;
  kk_integer_t _x23900 = kk_integer_dup(prec); /*int*/
  _match_21705 = kk_integer_gt(_x23900,(kk_integer_from_small(31)),kk_context()); /*bool*/
  if (_match_21705) {
    kk_integer_drop(prec, _ctx);
    return x;
  }
  kk_std_num_ddouble__ddouble p = kk_std_num_ddouble_powi10(prec, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__ddouble _x23901;
  kk_std_num_ddouble__ddouble _x23902 = kk_std_num_ddouble__lp__star__rp_(x, p, _ctx); /*std/num/ddouble/ddouble*/
  _x23901 = kk_std_num_ddouble_round(_x23902, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__lp__fs__rp_(_x23901, p, _ctx);
}
 
// Show a `:ddouble` `x` with a given precision `prec` (=`-31`).
// The precision specifies the  number of digits after the dot (in either scientific of fixed-point notation).
// If the precision is negative, _at most_ `prec` digits are displayed, while for a positive
// precision, exactly `prec` digits behind the dot are displayed.
// This uses `show-fixed` when the exponent of `x` in scientific notation is larger than -5
// and smaller than the precision (or 15 in case of a negative precision), otherwise it uses `show-exp`.

kk_string_t kk_std_num_ddouble_show(kk_std_num_ddouble__ddouble x, kk_std_core_types__optional prec, kk_context_t* _ctx) { /* (x : ddouble, prec : optional<int>) -> string */ 
  bool _match_21699;
  bool _x23903 = kk_std_num_ddouble_is_finite(x, _ctx); /*bool*/
  _match_21699 = !(_x23903); /*bool*/
  if (_match_21699) {
    kk_std_core_types__optional_drop(prec, _ctx);
    double _x23904;
    double _x = x.hi;
    _x23904 = _x; /*double*/
    return kk_std_core_show_1(_x23904, kk_std_core_types__new_None(_ctx), _ctx);
  }
  kk_std_num_decimal__decimal _x23905;
  bool _match_21700;
  bool _x23906 = kk_std_num_ddouble_is_finite(x, _ctx); /*bool*/
  _match_21700 = !(_x23906); /*bool*/
  if (_match_21700) {
    _x23905 = kk_std_num_decimal_decimal(kk_integer_from_small(0), kk_std_core_types__new_None(_ctx), _ctx); /*std/num/decimal/decimal*/
  }
  else {
    kk_std_num_decimal__decimal x1_21060;
    double _x23907;
    double _x3 = x.hi;
    _x23907 = _x3; /*double*/
    kk_std_core_types__optional _x23908;
    kk_box_t _x23909;
    kk_integer_t _x23910;
    kk_std_core_types__optional _match_21703 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
    if (kk_std_core_types__is_Optional(_match_21703)) {
      kk_box_t _box_x21622 = _match_21703._cons.Optional.value;
      kk_integer_t _prec_5395 = kk_integer_unbox(_box_x21622);
      kk_integer_dup(_prec_5395);
      kk_std_core_types__optional_drop(_match_21703, _ctx);
      _x23910 = _prec_5395; /*int*/
      goto _match23911;
    }
    _x23910 = kk_integer_from_small(-1); /*int*/
    _match23911: ;
    _x23909 = kk_integer_box(_x23910); /*35*/
    _x23908 = kk_std_core_types__new_Optional(_x23909, _ctx); /*optional<35>*/
    x1_21060 = kk_std_num_decimal_decimal_1(_x23907, _x23908, _ctx); /*std/num/decimal/decimal*/
    kk_std_num_decimal__decimal y_21061;
    double _x23913;
    double _x4 = x.lo;
    _x23913 = _x4; /*double*/
    kk_std_core_types__optional _x23914;
    kk_box_t _x23915;
    kk_integer_t _x23916;
    kk_std_core_types__optional _match_21702 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
    if (kk_std_core_types__is_Optional(_match_21702)) {
      kk_box_t _box_x21625 = _match_21702._cons.Optional.value;
      kk_integer_t _prec_53950 = kk_integer_unbox(_box_x21625);
      kk_integer_dup(_prec_53950);
      kk_std_core_types__optional_drop(_match_21702, _ctx);
      _x23916 = _prec_53950; /*int*/
      goto _match23917;
    }
    _x23916 = kk_integer_from_small(-1); /*int*/
    _match23917: ;
    _x23915 = kk_integer_box(_x23916); /*35*/
    _x23914 = kk_std_core_types__new_Optional(_x23915, _ctx); /*optional<35>*/
    y_21061 = kk_std_num_decimal_decimal_1(_x23913, _x23914, _ctx); /*std/num/decimal/decimal*/
    kk_integer_t e;
    bool _match_21701;
    kk_integer_t _x23919;
    kk_integer_t _x0 = x1_21060.exp;
    kk_integer_dup(_x0);
    _x23919 = _x0; /*int*/
    kk_integer_t _x23920;
    kk_integer_t _x00 = y_21061.exp;
    kk_integer_dup(_x00);
    _x23920 = _x00; /*int*/
    _match_21701 = kk_integer_lte(_x23919,_x23920,kk_context()); /*bool*/
    if (_match_21701) {
      kk_integer_t _x1 = x1_21060.exp;
      kk_integer_dup(_x1);
      e = _x1; /*int*/
    }
    else {
      kk_integer_t _x01 = y_21061.exp;
      kk_integer_dup(_x01);
      e = _x01; /*int*/
    }
    kk_std_num_decimal__decimal xx;
    kk_integer_t _x23921 = kk_integer_dup(e); /*int*/
    xx = kk_std_num_decimal_expand(x1_21060, _x23921, _ctx); /*std/num/decimal/decimal*/
    kk_std_num_decimal__decimal yy;
    kk_integer_t _x23922 = kk_integer_dup(e); /*int*/
    yy = kk_std_num_decimal_expand(y_21061, _x23922, _ctx); /*std/num/decimal/decimal*/
    kk_integer_t _x23923;
    kk_integer_t _x23924;
    kk_integer_t _x10 = xx.num;
    kk_integer_dup(_x10);
    kk_std_num_decimal__decimal_drop(xx, _ctx);
    _x23924 = _x10; /*int*/
    kk_integer_t _x23925;
    kk_integer_t _x2 = yy.num;
    kk_integer_dup(_x2);
    kk_std_num_decimal__decimal_drop(yy, _ctx);
    _x23925 = _x2; /*int*/
    _x23923 = kk_integer_add(_x23924,_x23925,kk_context()); /*int*/
    _x23905 = kk_std_num_decimal__new_Decimal(_x23923, e, _ctx); /*std/num/decimal/decimal*/
  }
  kk_std_core_types__optional _x23926;
  kk_box_t _x23927;
  kk_integer_t _x23928;
  if (kk_std_core_types__is_Optional(prec)) {
    kk_box_t _box_x21628 = prec._cons.Optional.value;
    kk_integer_t _prec_19011 = kk_integer_unbox(_box_x21628);
    kk_integer_dup(_prec_19011);
    kk_std_core_types__optional_drop(prec, _ctx);
    _x23928 = _prec_19011; /*int*/
    goto _match23929;
  }
  _x23928 = kk_integer_from_small(-31); /*int*/
  _match23929: ;
  _x23927 = kk_integer_box(_x23928); /*35*/
  _x23926 = kk_std_core_types__new_Optional(_x23927, _ctx); /*optional<35>*/
  return kk_std_num_decimal_show(_x23905, _x23926, _ctx);
}
 
/* Show a ddouble `x` with a given precision `prec` (=`-31`) in scientific notation.
The precision specifies the  number of digits after the dot, i.e.
the number of significant digits is `prec+1`.
If the precision is negative, _at most_ `prec` digits are displayed, and if
it is positive exactly `prec` digits are used.
```
> 1.1.ddouble.show-exp
"1.1000000000000000888178419700125"
> 1.1.ddouble.show-exp(-100)
"1.100000000000000088817841970012523233890533447265625"
> 1.1.ddouble.show-exp(5)
"1.10000"
> 1.1.ddouble.show-exp(-5)
"1.1"
```
.
*/

kk_string_t kk_std_num_ddouble_show_exp(kk_std_num_ddouble__ddouble x, kk_std_core_types__optional prec, kk_context_t* _ctx) { /* (x : ddouble, prec : optional<int>) -> string */ 
  bool _match_21694;
  bool _x23931 = kk_std_num_ddouble_is_finite(x, _ctx); /*bool*/
  _match_21694 = !(_x23931); /*bool*/
  if (_match_21694) {
    kk_std_core_types__optional_drop(prec, _ctx);
    double _x23932;
    double _x = x.hi;
    _x23932 = _x; /*double*/
    return kk_std_core_show_1(_x23932, kk_std_core_types__new_None(_ctx), _ctx);
  }
  kk_std_num_decimal__decimal _x23933;
  bool _match_21695;
  bool _x23934 = kk_std_num_ddouble_is_finite(x, _ctx); /*bool*/
  _match_21695 = !(_x23934); /*bool*/
  if (_match_21695) {
    _x23933 = kk_std_num_decimal_decimal(kk_integer_from_small(0), kk_std_core_types__new_None(_ctx), _ctx); /*std/num/decimal/decimal*/
  }
  else {
    kk_std_num_decimal__decimal x1_21067;
    double _x23935;
    double _x3 = x.hi;
    _x23935 = _x3; /*double*/
    kk_std_core_types__optional _x23936;
    kk_box_t _x23937;
    kk_integer_t _x23938;
    kk_std_core_types__optional _match_21698 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
    if (kk_std_core_types__is_Optional(_match_21698)) {
      kk_box_t _box_x21631 = _match_21698._cons.Optional.value;
      kk_integer_t _prec_5395 = kk_integer_unbox(_box_x21631);
      kk_integer_dup(_prec_5395);
      kk_std_core_types__optional_drop(_match_21698, _ctx);
      _x23938 = _prec_5395; /*int*/
      goto _match23939;
    }
    _x23938 = kk_integer_from_small(-1); /*int*/
    _match23939: ;
    _x23937 = kk_integer_box(_x23938); /*35*/
    _x23936 = kk_std_core_types__new_Optional(_x23937, _ctx); /*optional<35>*/
    x1_21067 = kk_std_num_decimal_decimal_1(_x23935, _x23936, _ctx); /*std/num/decimal/decimal*/
    kk_std_num_decimal__decimal y_21068;
    double _x23941;
    double _x4 = x.lo;
    _x23941 = _x4; /*double*/
    kk_std_core_types__optional _x23942;
    kk_box_t _x23943;
    kk_integer_t _x23944;
    kk_std_core_types__optional _match_21697 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
    if (kk_std_core_types__is_Optional(_match_21697)) {
      kk_box_t _box_x21634 = _match_21697._cons.Optional.value;
      kk_integer_t _prec_53950 = kk_integer_unbox(_box_x21634);
      kk_integer_dup(_prec_53950);
      kk_std_core_types__optional_drop(_match_21697, _ctx);
      _x23944 = _prec_53950; /*int*/
      goto _match23945;
    }
    _x23944 = kk_integer_from_small(-1); /*int*/
    _match23945: ;
    _x23943 = kk_integer_box(_x23944); /*35*/
    _x23942 = kk_std_core_types__new_Optional(_x23943, _ctx); /*optional<35>*/
    y_21068 = kk_std_num_decimal_decimal_1(_x23941, _x23942, _ctx); /*std/num/decimal/decimal*/
    kk_integer_t e;
    bool _match_21696;
    kk_integer_t _x23947;
    kk_integer_t _x0 = x1_21067.exp;
    kk_integer_dup(_x0);
    _x23947 = _x0; /*int*/
    kk_integer_t _x23948;
    kk_integer_t _x00 = y_21068.exp;
    kk_integer_dup(_x00);
    _x23948 = _x00; /*int*/
    _match_21696 = kk_integer_lte(_x23947,_x23948,kk_context()); /*bool*/
    if (_match_21696) {
      kk_integer_t _x1 = x1_21067.exp;
      kk_integer_dup(_x1);
      e = _x1; /*int*/
    }
    else {
      kk_integer_t _x01 = y_21068.exp;
      kk_integer_dup(_x01);
      e = _x01; /*int*/
    }
    kk_std_num_decimal__decimal xx;
    kk_integer_t _x23949 = kk_integer_dup(e); /*int*/
    xx = kk_std_num_decimal_expand(x1_21067, _x23949, _ctx); /*std/num/decimal/decimal*/
    kk_std_num_decimal__decimal yy;
    kk_integer_t _x23950 = kk_integer_dup(e); /*int*/
    yy = kk_std_num_decimal_expand(y_21068, _x23950, _ctx); /*std/num/decimal/decimal*/
    kk_integer_t _x23951;
    kk_integer_t _x23952;
    kk_integer_t _x10 = xx.num;
    kk_integer_dup(_x10);
    kk_std_num_decimal__decimal_drop(xx, _ctx);
    _x23952 = _x10; /*int*/
    kk_integer_t _x23953;
    kk_integer_t _x2 = yy.num;
    kk_integer_dup(_x2);
    kk_std_num_decimal__decimal_drop(yy, _ctx);
    _x23953 = _x2; /*int*/
    _x23951 = kk_integer_add(_x23952,_x23953,kk_context()); /*int*/
    _x23933 = kk_std_num_decimal__new_Decimal(_x23951, e, _ctx); /*std/num/decimal/decimal*/
  }
  kk_std_core_types__optional _x23954;
  kk_box_t _x23955;
  kk_integer_t _x23956;
  if (kk_std_core_types__is_Optional(prec)) {
    kk_box_t _box_x21637 = prec._cons.Optional.value;
    kk_integer_t _prec_19202 = kk_integer_unbox(_box_x21637);
    kk_integer_dup(_prec_19202);
    kk_std_core_types__optional_drop(prec, _ctx);
    _x23956 = _prec_19202; /*int*/
    goto _match23957;
  }
  _x23956 = kk_integer_from_small(-31); /*int*/
  _match23957: ;
  _x23955 = kk_integer_box(_x23956); /*35*/
  _x23954 = kk_std_core_types__new_Optional(_x23955, _ctx); /*optional<35>*/
  return kk_std_num_decimal_show_exp(_x23933, _x23954, _ctx);
}
 
/* Show a ddouble `x` with a given precision `prec` (=`-31`) in fixed-point notation.
The precision specifies the  number of digits after the dot.
If the precision is negative, _at most_  `prec` digits after the dot are displayed,
while for a positive precision, exactly `prec` digits are used.
```
> 0.1.ddouble.show-fixed
"0.1000000000000000055511151231258"
> 0.1.ddouble.show-fixed(-100)
"0.1000000000000000055511151231257827021181583404541015625"
> 0.1.ddouble.show-fixed(5)
"0.10000"
> 0.1.ddouble.show-fixed(-5)
"0.1"
```
.
*/

kk_string_t kk_std_num_ddouble_show_fixed(kk_std_num_ddouble__ddouble x, kk_std_core_types__optional prec, kk_context_t* _ctx) { /* (x : ddouble, prec : optional<int>) -> string */ 
  bool _match_21689;
  bool _x23959 = kk_std_num_ddouble_is_finite(x, _ctx); /*bool*/
  _match_21689 = !(_x23959); /*bool*/
  if (_match_21689) {
    kk_std_core_types__optional_drop(prec, _ctx);
    double _x23960;
    double _x = x.hi;
    _x23960 = _x; /*double*/
    return kk_std_core_show_1(_x23960, kk_std_core_types__new_None(_ctx), _ctx);
  }
  kk_std_num_decimal__decimal _x23961;
  bool _match_21690;
  bool _x23962 = kk_std_num_ddouble_is_finite(x, _ctx); /*bool*/
  _match_21690 = !(_x23962); /*bool*/
  if (_match_21690) {
    _x23961 = kk_std_num_decimal_decimal(kk_integer_from_small(0), kk_std_core_types__new_None(_ctx), _ctx); /*std/num/decimal/decimal*/
  }
  else {
    kk_std_num_decimal__decimal x1_21074;
    double _x23963;
    double _x3 = x.hi;
    _x23963 = _x3; /*double*/
    kk_std_core_types__optional _x23964;
    kk_box_t _x23965;
    kk_integer_t _x23966;
    kk_std_core_types__optional _match_21693 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
    if (kk_std_core_types__is_Optional(_match_21693)) {
      kk_box_t _box_x21640 = _match_21693._cons.Optional.value;
      kk_integer_t _prec_5395 = kk_integer_unbox(_box_x21640);
      kk_integer_dup(_prec_5395);
      kk_std_core_types__optional_drop(_match_21693, _ctx);
      _x23966 = _prec_5395; /*int*/
      goto _match23967;
    }
    _x23966 = kk_integer_from_small(-1); /*int*/
    _match23967: ;
    _x23965 = kk_integer_box(_x23966); /*35*/
    _x23964 = kk_std_core_types__new_Optional(_x23965, _ctx); /*optional<35>*/
    x1_21074 = kk_std_num_decimal_decimal_1(_x23963, _x23964, _ctx); /*std/num/decimal/decimal*/
    kk_std_num_decimal__decimal y_21075;
    double _x23969;
    double _x4 = x.lo;
    _x23969 = _x4; /*double*/
    kk_std_core_types__optional _x23970;
    kk_box_t _x23971;
    kk_integer_t _x23972;
    kk_std_core_types__optional _match_21692 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
    if (kk_std_core_types__is_Optional(_match_21692)) {
      kk_box_t _box_x21643 = _match_21692._cons.Optional.value;
      kk_integer_t _prec_53950 = kk_integer_unbox(_box_x21643);
      kk_integer_dup(_prec_53950);
      kk_std_core_types__optional_drop(_match_21692, _ctx);
      _x23972 = _prec_53950; /*int*/
      goto _match23973;
    }
    _x23972 = kk_integer_from_small(-1); /*int*/
    _match23973: ;
    _x23971 = kk_integer_box(_x23972); /*35*/
    _x23970 = kk_std_core_types__new_Optional(_x23971, _ctx); /*optional<35>*/
    y_21075 = kk_std_num_decimal_decimal_1(_x23969, _x23970, _ctx); /*std/num/decimal/decimal*/
    kk_integer_t e;
    bool _match_21691;
    kk_integer_t _x23975;
    kk_integer_t _x0 = x1_21074.exp;
    kk_integer_dup(_x0);
    _x23975 = _x0; /*int*/
    kk_integer_t _x23976;
    kk_integer_t _x00 = y_21075.exp;
    kk_integer_dup(_x00);
    _x23976 = _x00; /*int*/
    _match_21691 = kk_integer_lte(_x23975,_x23976,kk_context()); /*bool*/
    if (_match_21691) {
      kk_integer_t _x1 = x1_21074.exp;
      kk_integer_dup(_x1);
      e = _x1; /*int*/
    }
    else {
      kk_integer_t _x01 = y_21075.exp;
      kk_integer_dup(_x01);
      e = _x01; /*int*/
    }
    kk_std_num_decimal__decimal xx;
    kk_integer_t _x23977 = kk_integer_dup(e); /*int*/
    xx = kk_std_num_decimal_expand(x1_21074, _x23977, _ctx); /*std/num/decimal/decimal*/
    kk_std_num_decimal__decimal yy;
    kk_integer_t _x23978 = kk_integer_dup(e); /*int*/
    yy = kk_std_num_decimal_expand(y_21075, _x23978, _ctx); /*std/num/decimal/decimal*/
    kk_integer_t _x23979;
    kk_integer_t _x23980;
    kk_integer_t _x10 = xx.num;
    kk_integer_dup(_x10);
    kk_std_num_decimal__decimal_drop(xx, _ctx);
    _x23980 = _x10; /*int*/
    kk_integer_t _x23981;
    kk_integer_t _x2 = yy.num;
    kk_integer_dup(_x2);
    kk_std_num_decimal__decimal_drop(yy, _ctx);
    _x23981 = _x2; /*int*/
    _x23979 = kk_integer_add(_x23980,_x23981,kk_context()); /*int*/
    _x23961 = kk_std_num_decimal__new_Decimal(_x23979, e, _ctx); /*std/num/decimal/decimal*/
  }
  kk_std_core_types__optional _x23982;
  kk_box_t _x23983;
  kk_integer_t _x23984;
  if (kk_std_core_types__is_Optional(prec)) {
    kk_box_t _box_x21646 = prec._cons.Optional.value;
    kk_integer_t _prec_19353 = kk_integer_unbox(_box_x21646);
    kk_integer_dup(_prec_19353);
    kk_std_core_types__optional_drop(prec, _ctx);
    _x23984 = _prec_19353; /*int*/
    goto _match23985;
  }
  _x23984 = kk_integer_from_small(-31); /*int*/
  _match23985: ;
  _x23983 = kk_integer_box(_x23984); /*35*/
  _x23982 = kk_std_core_types__new_Optional(_x23983, _ctx); /*optional<35>*/
  return kk_std_num_decimal_show_fixed(_x23961, _x23982, _ctx);
}
 
/* Show a `:ddouble` `x` precisely as the sum of two `:double`s
in [hexadecimal notation](https://books.google.com/books?id=FgMsCwAAQBAJ&pg=PA41).
Use this if you need to guarantee that you can parse back `:ddouble`s exactly,
i.e. `x == x.show-hex.ddouble`.
```
> 0.1.ddouble.show-hex
"0x1.999999999999Ap-4 + 0x0.0p+0"
> "0.1".ddouble.show-hex
"0x1.999999999999Ap-4 + -0x1.999999999999Ap-58"
> dd-pi.show-hex
"0x1.921FB54442D18p+1 + 0x1.1A62633145C07p-53"
> dd-max.show-hex
"0x1.FFFFFFFFFFFFFp+1023 + 0x1.FFFFFFFFFFFFFp+969"
```
.
*/

kk_string_t kk_std_num_ddouble_show_hex(kk_std_num_ddouble__ddouble x, kk_std_core_types__optional width, kk_std_core_types__optional use_capitals, kk_std_core_types__optional pre, kk_context_t* _ctx) { /* (x : ddouble, width : optional<int>, use-capitals : optional<bool>, pre : optional<string>) -> string */ 
  bool _match_21688;
  bool _x23987 = kk_std_num_ddouble_is_finite(x, _ctx); /*bool*/
  _match_21688 = !(_x23987); /*bool*/
  if (_match_21688) {
    kk_std_core_types__optional_drop(pre, _ctx);
    kk_std_core_types__optional_drop(use_capitals, _ctx);
    kk_std_core_types__optional_drop(width, _ctx);
    double _x23988;
    double _x = x.hi;
    _x23988 = _x; /*double*/
    return kk_std_core_show_1(_x23988, kk_std_core_types__new_None(_ctx), _ctx);
  }
  kk_string_t _x23989;
  double _x23990;
  double _x0 = x.hi;
  _x23990 = _x0; /*double*/
  kk_std_core_types__optional _x23991;
  kk_box_t _x23992;
  kk_integer_t _x23993;
  if (kk_std_core_types__is_Optional(width)) {
    kk_box_t _box_x21649 = width._cons.Optional.value;
    kk_integer_t _width_19504 = kk_integer_unbox(_box_x21649);
    kk_integer_dup(_width_19504);
    _x23993 = _width_19504; /*int*/
    goto _match23994;
  }
  _x23993 = kk_integer_from_small(1); /*int*/
  _match23994: ;
  _x23992 = kk_integer_box(_x23993); /*35*/
  _x23991 = kk_std_core_types__new_Optional(_x23992, _ctx); /*optional<35>*/
  kk_std_core_types__optional _x23996;
  kk_box_t _x23997;
  bool _x23998;
  if (kk_std_core_types__is_Optional(use_capitals)) {
    kk_box_t _box_x21651 = use_capitals._cons.Optional.value;
    bool _use_capitals_19508 = kk_bool_unbox(_box_x21651);
    _x23998 = _use_capitals_19508; /*bool*/
    goto _match23999;
  }
  _x23998 = true; /*bool*/
  _match23999: ;
  _x23997 = kk_bool_box(_x23998); /*35*/
  _x23996 = kk_std_core_types__new_Optional(_x23997, _ctx); /*optional<35>*/
  kk_std_core_types__optional _x24001;
  kk_box_t _x24002;
  kk_string_t _x24003;
  if (kk_std_core_types__is_Optional(pre)) {
    kk_box_t _box_x21653 = pre._cons.Optional.value;
    kk_string_t _pre_19512 = kk_string_unbox(_box_x21653);
    kk_string_dup(_pre_19512);
    _x24003 = _pre_19512; /*string*/
    goto _match24004;
  }
  kk_define_string_literal(, _s24006, 2, "0x")
  _x24003 = kk_string_dup(_s24006); /*string*/
  _match24004: ;
  _x24002 = kk_string_box(_x24003); /*35*/
  _x24001 = kk_std_core_types__new_Optional(_x24002, _ctx); /*optional<35>*/
  _x23989 = kk_std_num_double_show_hex(_x23990, _x23991, _x23996, _x24001, _ctx); /*string*/
  kk_string_t _x24007;
  kk_string_t _x24008;
  kk_define_string_literal(, _s24009, 3, " + ")
  _x24008 = kk_string_dup(_s24009); /*string*/
  kk_string_t _x24010;
  double _x24011;
  double _x1 = x.lo;
  _x24011 = _x1; /*double*/
  kk_std_core_types__optional _x24012;
  kk_box_t _x24013;
  kk_integer_t _x24014;
  if (kk_std_core_types__is_Optional(width)) {
    kk_box_t _box_x21655 = width._cons.Optional.value;
    kk_integer_t _width_195040 = kk_integer_unbox(_box_x21655);
    kk_integer_dup(_width_195040);
    kk_std_core_types__optional_drop(width, _ctx);
    _x24014 = _width_195040; /*int*/
    goto _match24015;
  }
  _x24014 = kk_integer_from_small(1); /*int*/
  _match24015: ;
  _x24013 = kk_integer_box(_x24014); /*35*/
  _x24012 = kk_std_core_types__new_Optional(_x24013, _ctx); /*optional<35>*/
  kk_std_core_types__optional _x24017;
  kk_box_t _x24018;
  bool _x24019;
  if (kk_std_core_types__is_Optional(use_capitals)) {
    kk_box_t _box_x21657 = use_capitals._cons.Optional.value;
    bool _use_capitals_195080 = kk_bool_unbox(_box_x21657);
    kk_std_core_types__optional_drop(use_capitals, _ctx);
    _x24019 = _use_capitals_195080; /*bool*/
    goto _match24020;
  }
  _x24019 = true; /*bool*/
  _match24020: ;
  _x24018 = kk_bool_box(_x24019); /*35*/
  _x24017 = kk_std_core_types__new_Optional(_x24018, _ctx); /*optional<35>*/
  kk_std_core_types__optional _x24022;
  kk_box_t _x24023;
  kk_string_t _x24024;
  if (kk_std_core_types__is_Optional(pre)) {
    kk_box_t _box_x21659 = pre._cons.Optional.value;
    kk_string_t _pre_195120 = kk_string_unbox(_box_x21659);
    kk_string_dup(_pre_195120);
    kk_std_core_types__optional_drop(pre, _ctx);
    _x24024 = _pre_195120; /*string*/
    goto _match24025;
  }
  kk_define_string_literal(, _s24027, 2, "0x")
  _x24024 = kk_string_dup(_s24027); /*string*/
  _match24025: ;
  _x24023 = kk_string_box(_x24024); /*35*/
  _x24022 = kk_std_core_types__new_Optional(_x24023, _ctx); /*optional<35>*/
  _x24010 = kk_std_num_double_show_hex(_x24011, _x24012, _x24017, _x24022, _ctx); /*string*/
  _x24007 = kk_std_core__lp__plus__plus__1_rp_(_x24008, _x24010, _ctx); /*string*/
  return kk_std_core__lp__plus__plus__1_rp_(_x23989, _x24007, _ctx);
}
 
// Show a `:ddouble` as the sum of  `:double`s with an optional precision.
// Note: use `show-hex` for reliable round-trip parsing.

kk_string_t kk_std_num_ddouble_show_sum(kk_std_num_ddouble__ddouble x, kk_std_core_types__optional prec, kk_context_t* _ctx) { /* (x : ddouble, prec : optional<int>) -> string */ 
  bool _match_21687;
  bool _x24028 = kk_std_num_ddouble_is_finite(x, _ctx); /*bool*/
  _match_21687 = !(_x24028); /*bool*/
  if (_match_21687) {
    kk_std_core_types__optional_drop(prec, _ctx);
    double _x24029;
    double _x = x.hi;
    _x24029 = _x; /*double*/
    return kk_std_core_show_1(_x24029, kk_std_core_types__new_None(_ctx), _ctx);
  }
  kk_string_t _x24030;
  double _x24031;
  double _x0 = x.hi;
  _x24031 = _x0; /*double*/
  kk_std_core_types__optional _x24032;
  kk_box_t _x24033;
  kk_integer_t _x24034;
  if (kk_std_core_types__is_Optional(prec)) {
    kk_box_t _box_x21667 = prec._cons.Optional.value;
    kk_integer_t _prec_19741 = kk_integer_unbox(_box_x21667);
    kk_integer_dup(_prec_19741);
    _x24034 = _prec_19741; /*int*/
    goto _match24035;
  }
  _x24034 = kk_integer_from_small(-17); /*int*/
  _match24035: ;
  _x24033 = kk_integer_box(_x24034); /*35*/
  _x24032 = kk_std_core_types__new_Optional(_x24033, _ctx); /*optional<35>*/
  _x24030 = kk_std_core_show_1(_x24031, _x24032, _ctx); /*string*/
  kk_string_t _x24037;
  kk_string_t _x24038;
  kk_define_string_literal(, _s24039, 3, " + ")
  _x24038 = kk_string_dup(_s24039); /*string*/
  kk_string_t _x24040;
  double _x24041;
  double _x1 = x.lo;
  _x24041 = _x1; /*double*/
  kk_std_core_types__optional _x24042;
  kk_box_t _x24043;
  kk_integer_t _x24044;
  if (kk_std_core_types__is_Optional(prec)) {
    kk_box_t _box_x21669 = prec._cons.Optional.value;
    kk_integer_t _prec_197410 = kk_integer_unbox(_box_x21669);
    kk_integer_dup(_prec_197410);
    kk_std_core_types__optional_drop(prec, _ctx);
    _x24044 = _prec_197410; /*int*/
    goto _match24045;
  }
  _x24044 = kk_integer_from_small(-17); /*int*/
  _match24045: ;
  _x24043 = kk_integer_box(_x24044); /*35*/
  _x24042 = kk_std_core_types__new_Optional(_x24043, _ctx); /*optional<35>*/
  _x24040 = kk_std_core_show_1(_x24041, _x24042, _ctx); /*string*/
  _x24037 = kk_std_core__lp__plus__plus__1_rp_(_x24038, _x24040, _ctx); /*string*/
  return kk_std_core__lp__plus__plus__1_rp_(_x24030, _x24037, _ctx);
}
 
// The hyperbolic tangent of `x`.

kk_std_num_ddouble__ddouble kk_std_num_ddouble_tanh(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> ddouble */ 
  bool _match_21678 = kk_std_num_ddouble_is_zero(x, _ctx); /*bool*/;
  if (_match_21678) {
    return kk_std_num_ddouble__new_Ddouble(0x0p+0, 0x0p+0, _ctx);
  }
  bool _match_21679;
  double _x24051;
  kk_std_num_ddouble__ddouble x0_21085 = kk_std_num_ddouble_abs(x, _ctx); /*std/num/ddouble/ddouble*/;
  double _x = x0_21085.hi;
  _x24051 = _x; /*double*/
  _match_21679 = (_x24051 > (0x1.999999999999ap-5)); /*bool*/
  if (_match_21679) {
    kk_std_num_ddouble__ddouble ex = kk_std_num_ddouble_exp(x, _ctx); /*std/num/ddouble/ddouble*/;
    kk_std_num_ddouble__ddouble iex;
    kk_std_num_ddouble__ddouble _x24052 = kk_std_num_ddouble__new_Ddouble(0x1p0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    iex = kk_std_num_ddouble__lp__fs__rp_(_x24052, ex, _ctx); /*std/num/ddouble/ddouble*/
    bool _match_21684 = kk_std_num_ddouble_is_zero(ex, _ctx); /*bool*/;
    if (_match_21684) {
      kk_std_num_ddouble__ddouble _x24053 = kk_std_num_ddouble__new_Ddouble(0x1p0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
      return kk_std_num_ddouble__lp__tilde__rp_(_x24053, _ctx);
    }
    bool _match_21685 = kk_std_num_ddouble_is_posinf(ex, _ctx); /*bool*/;
    if (_match_21685) {
      return kk_std_num_ddouble__new_Ddouble(0x1p0, 0x0p+0, _ctx);
    }
    kk_std_num_ddouble__ddouble _x24054 = kk_std_num_ddouble__lp__dash__rp_(ex, iex, _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble _x24055 = kk_std_num_ddouble__lp__plus__rp_(ex, iex, _ctx); /*std/num/ddouble/ddouble*/
    return kk_std_num_ddouble__lp__fs__rp_(_x24054, _x24055, _ctx);
  }
  kk_std_num_ddouble__ddouble s = kk_std_num_ddouble_sinh(x, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__ddouble c;
  kk_std_num_ddouble__ddouble x1_21087;
  kk_std_num_ddouble__ddouble _x24056 = kk_std_num_ddouble__new_Ddouble(0x1p0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x24057 = kk_std_num_ddouble_sqr(s, _ctx); /*std/num/ddouble/ddouble*/
  x1_21087 = kk_std_num_ddouble__lp__plus__rp_(_x24056, _x24057, _ctx); /*std/num/ddouble/ddouble*/
  bool _match_21680 = kk_std_num_ddouble_is_zero(x1_21087, _ctx); /*bool*/;
  if (_match_21680) {
    c = kk_std_num_ddouble__new_Ddouble(0x0p+0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    bool _match_21681 = kk_std_num_ddouble_is_neg(x1_21087, _ctx); /*bool*/;
    if (_match_21681) {
      c = kk_std_num_ddouble_dd_nan; /*std/num/ddouble/ddouble*/
    }
    else {
      double a;
      double _x24058;
      double _x24059;
      double _x0 = x1_21087.hi;
      _x24059 = _x0; /*double*/
      _x24058 = sqrt(_x24059); /*double*/
      a = (0x1p0 / _x24058); /*double*/
      double t1;
      double _x24060;
      double _x1 = x1_21087.hi;
      _x24060 = _x1; /*double*/
      t1 = (_x24060 * a); /*double*/
      double t2;
      double _x24061;
      double _x24062;
      kk_std_num_ddouble__ddouble ddouble2_21090;
      kk_std_num_ddouble__ddouble y_21092;
      kk_std_num_ddouble__ddouble x0_21206 = kk_std_num_ddouble_ddouble(t1, _ctx); /*std/num/ddouble/ddouble*/;
      kk_std_num_ddouble__edouble z0;
      double z;
      double _x24063;
      double _x2 = x0_21206.hi;
      _x24063 = _x2; /*double*/
      double _x24064;
      double _x20 = x0_21206.hi;
      _x24064 = _x20; /*double*/
      z = (_x24063 * _x24064); /*double*/
      double err0;
      double _x24065;
      double _x21 = x0_21206.hi;
      _x24065 = _x21; /*double*/
      double _x24066;
      double _x22 = x0_21206.hi;
      _x24066 = _x22; /*double*/
      double _x24067 = (-z); /*double*/
      err0 = kk_std_num_double_fmadd(_x24065, _x24066, _x24067, _ctx); /*double*/
      z0 = kk_std_num_ddouble__new_Edouble(z, err0, _ctx); /*std/num/ddouble/edouble*/
      double e;
      double _x24068;
      double _x24069;
      double _x00 = z0.err;
      _x24069 = _x00; /*double*/
      double _x24070;
      double _x24071;
      double _x24072;
      double _x10 = x0_21206.hi;
      _x24072 = _x10; /*double*/
      _x24071 = (0x1p1 * _x24072); /*double*/
      double _x24073;
      double _x200 = x0_21206.lo;
      _x24073 = _x200; /*double*/
      _x24070 = (_x24071 * _x24073); /*double*/
      _x24068 = (_x24069 + _x24070); /*double*/
      double _x24074;
      double _x24075;
      double _x3 = x0_21206.lo;
      _x24075 = _x3; /*double*/
      double _x24076;
      double _x4 = x0_21206.lo;
      _x24076 = _x4; /*double*/
      _x24074 = (_x24075 * _x24076); /*double*/
      e = (_x24068 + _x24074); /*double*/
      bool _match_21682;
      bool _x24077;
      double _x24078;
      double _x5 = z0.num;
      _x24078 = _x5; /*double*/
      _x24077 = isfinite(_x24078); /*bool*/
      _match_21682 = !(_x24077); /*bool*/
      if (_match_21682) {
        double _x24079;
        double _x50 = z0.num;
        _x24079 = _x50; /*double*/
        y_21092 = kk_std_num_ddouble_ddouble(_x24079, _ctx); /*std/num/ddouble/ddouble*/
      }
      else {
        double z1;
        double _x24080;
        double _x51 = z0.num;
        _x24080 = _x51; /*double*/
        z1 = (_x24080 + e); /*double*/
        double err00;
        double _x24081;
        double _x24082;
        double _x52 = z0.num;
        _x24082 = _x52; /*double*/
        _x24081 = (z1 - _x24082); /*double*/
        err00 = (e - _x24081); /*double*/
        double _x24083;
        bool _match_21683 = isfinite(z1); /*bool*/;
        if (_match_21683) {
          _x24083 = err00; /*double*/
        }
        else {
          _x24083 = z1; /*double*/
        }
        y_21092 = kk_std_num_ddouble__new_Ddouble(z1, _x24083, _ctx); /*std/num/ddouble/ddouble*/
      }
      kk_std_num_ddouble__ddouble _x24084 = kk_std_num_ddouble__lp__tilde__rp_(y_21092, _ctx); /*std/num/ddouble/ddouble*/
      ddouble2_21090 = kk_std_num_ddouble__lp__plus__rp_(x1_21087, _x24084, _ctx); /*std/num/ddouble/ddouble*/
      double _x210 = ddouble2_21090.hi;
      _x24062 = _x210; /*double*/
      _x24061 = (_x24062 * a); /*double*/
      t2 = (_x24061 * (0x1p-1)); /*double*/
      c = kk_std_num_ddouble_dsum(t1, t2, _ctx); /*std/num/ddouble/ddouble*/
    }
  }
  return kk_std_num_ddouble__lp__fs__rp_(s, c, _ctx);
}

// initialization
void kk_std_num_ddouble__init(kk_context_t* _ctx){
  static bool _initialized = false;
  if (_initialized) return;
  _initialized = true;
  kk_std_core_types__init(_ctx);
  kk_std_core_hnd__init(_ctx);
  kk_std_core__init(_ctx);
  kk_std_text_parse__init(_ctx);
  kk_std_num_double__init(_ctx);
  kk_std_num_decimal__init(_ctx);
  {
    kk_std_num_ddouble_maxprecise = kk_integer_from_str("9007199254740991", _ctx); /*int*/
  }
  {
    kk_std_num_ddouble_dd_default_prec = kk_integer_from_small(-31); /*int*/
  }
  {
    kk_std_num_ddouble_dd_max_prec = kk_integer_from_small(31); /*int*/
  }
  {
    double _x22146 = kk_std_num_double_make_nan(_ctx); /*double*/
    kk_std_num_ddouble_dd_nan = kk_std_num_ddouble__new_Ddouble(_x22146, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  }
  {
    kk_std_num_ddouble_minprecise = kk_integer_neg((kk_integer_from_str("9007199254740991", _ctx)),kk_context()); /*int*/
  }
  {
    kk_std_num_ddouble_one = kk_std_num_ddouble__new_Ddouble(0x1p0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  }
  {
    kk_std_num_ddouble_ten = kk_std_num_ddouble__new_Ddouble(0x1.4p3, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  }
  {
    kk_std_num_ddouble_zero = kk_std_num_ddouble__new_Ddouble(0x0p+0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  }
  {
    kk_std_num_ddouble_dd_pi = kk_std_num_ddouble__new_Ddouble(0x1.921fb54442d18p1, 0x1.1a62633145c07p-53, _ctx); /*std/num/ddouble/ddouble*/
  }
  {
    kk_std_num_ddouble_dd_pi2 = kk_std_num_ddouble__new_Ddouble(0x1.921fb54442d18p0, 0x1.1a62633145c07p-54, _ctx); /*std/num/ddouble/ddouble*/
  }
  {
    kk_std_num_ddouble_dd_pi34 = kk_std_num_ddouble__new_Ddouble(0x1.2d97c7f3321d2p1, 0x1.a79394c9e8a0bp-54, _ctx); /*std/num/ddouble/ddouble*/
  }
  {
    kk_std_num_ddouble_dd_pi4 = kk_std_num_ddouble__new_Ddouble(0x1.921fb54442d18p-1, 0x1.1a62633145c07p-55, _ctx); /*std/num/ddouble/ddouble*/
  }
  {
    kk_std_num_ddouble__ddouble _b_21458_21456 = kk_std_num_ddouble__new_Ddouble(0x1.6116039167de1p-33, 0x1.ea9f4c1702653p-88, _ctx); /*std/num/ddouble/ddouble*/;
    kk_std_core__list _b_21459_21457;
    kk_std_num_ddouble__ddouble _b_21460_21454 = kk_std_num_ddouble__new_Ddouble(-0x1.ae64561f4804fp-26, -0x1.c5104f49cf934p-82, _ctx); /*std/num/ddouble/ddouble*/;
    kk_std_core__list _b_21461_21455;
    kk_std_num_ddouble__ddouble _b_21462_21452 = kk_std_num_ddouble__new_Ddouble(0x1.71de3a556b36bp-19, -0x1.eb33da7509008p-73, _ctx); /*std/num/ddouble/ddouble*/;
    kk_std_core__list _b_21463_21453;
    kk_std_num_ddouble__ddouble _b_21464_21450 = kk_std_num_ddouble__new_Ddouble(-0x1.a01a01a01a01ap-13, 0x1.0313e2634850bp-67, _ctx); /*std/num/ddouble/ddouble*/;
    kk_std_core__list _b_21465_21451;
    kk_std_num_ddouble__ddouble _b_21466_21448 = kk_std_num_ddouble__new_Ddouble(0x1.1111111111111p-7, 0x1.110a7e6657814p-63, _ctx); /*std/num/ddouble/ddouble*/;
    kk_std_core__list _b_21467_21449;
    kk_std_num_ddouble__ddouble _b_21468_21446 = kk_std_num_ddouble__new_Ddouble(-0x1.5555555555555p-3, -0x1.5555555162e8fp-57, _ctx); /*std/num/ddouble/ddouble*/;
    kk_std_core__list _b_21469_21447;
    kk_std_num_ddouble__ddouble _b_21470_21444 = kk_std_num_ddouble__new_Ddouble(0x1p0, -0x1.86fa265ab5ed7p-101, _ctx); /*std/num/ddouble/ddouble*/;
    _b_21469_21447 = kk_std_core__new_Cons(kk_reuse_null, kk_std_num_ddouble__ddouble_box(_b_21470_21444, _ctx), kk_std_core__new_Nil(_ctx), _ctx); /*list<std/num/ddouble/ddouble>*/
    _b_21467_21449 = kk_std_core__new_Cons(kk_reuse_null, kk_std_num_ddouble__ddouble_box(_b_21468_21446, _ctx), _b_21469_21447, _ctx); /*list<std/num/ddouble/ddouble>*/
    _b_21465_21451 = kk_std_core__new_Cons(kk_reuse_null, kk_std_num_ddouble__ddouble_box(_b_21466_21448, _ctx), _b_21467_21449, _ctx); /*list<std/num/ddouble/ddouble>*/
    _b_21463_21453 = kk_std_core__new_Cons(kk_reuse_null, kk_std_num_ddouble__ddouble_box(_b_21464_21450, _ctx), _b_21465_21451, _ctx); /*list<std/num/ddouble/ddouble>*/
    _b_21461_21455 = kk_std_core__new_Cons(kk_reuse_null, kk_std_num_ddouble__ddouble_box(_b_21462_21452, _ctx), _b_21463_21453, _ctx); /*list<std/num/ddouble/ddouble>*/
    _b_21459_21457 = kk_std_core__new_Cons(kk_reuse_null, kk_std_num_ddouble__ddouble_box(_b_21460_21454, _ctx), _b_21461_21455, _ctx); /*list<std/num/ddouble/ddouble>*/
    kk_std_num_ddouble_ch_factors = kk_std_core__new_Cons(kk_reuse_null, kk_std_num_ddouble__ddouble_box(_b_21458_21456, _ctx), _b_21459_21457, _ctx); /*list<std/num/ddouble/ddouble>*/
  }
  {
    kk_std_num_ddouble_dd_twopi = kk_std_num_ddouble__new_Ddouble(0x1.921fb54442d18p2, 0x1.1a62633145c07p-52, _ctx); /*std/num/ddouble/ddouble*/
  }
  {
    kk_std_core__list xs_20796;
    kk_std_num_ddouble__ddouble _b_21503_21501 = kk_std_num_ddouble__new_Ddouble(0x0p+0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/;
    kk_std_core__list _b_21504_21502;
    kk_std_num_ddouble__ddouble _b_21505_21499 = kk_std_num_ddouble__new_Ddouble(0x1.8f8b83c69a60bp-3, -0x1.26d19b9ff8d82p-57, _ctx); /*std/num/ddouble/ddouble*/;
    kk_std_core__list _b_21506_21500;
    kk_std_num_ddouble__ddouble _b_21507_21497 = kk_std_num_ddouble__new_Ddouble(0x1.87de2a6aea963p-2, -0x1.72cedd3d5a61p-57, _ctx); /*std/num/ddouble/ddouble*/;
    kk_std_core__list _b_21508_21498;
    kk_std_num_ddouble__ddouble _b_21509_21495 = kk_std_num_ddouble__new_Ddouble(0x1.1c73b39ae68c8p-1, 0x1.b25dd267f66p-55, _ctx); /*std/num/ddouble/ddouble*/;
    kk_std_core__list _b_21510_21496;
    kk_std_num_ddouble__ddouble _b_21511_21493 = kk_std_num_ddouble__new_Ddouble(0x1.6a09e667f3bcdp-1, -0x1.bdd3413b26455p-55, _ctx); /*std/num/ddouble/ddouble*/;
    kk_std_core__list _b_21512_21494;
    kk_std_num_ddouble__ddouble _b_21513_21491 = kk_std_num_ddouble__new_Ddouble(0x1.a9b66290ea1a3p-1, 0x1.9f630e8b6dafp-60, _ctx); /*std/num/ddouble/ddouble*/;
    kk_std_core__list _b_21514_21492;
    kk_std_num_ddouble__ddouble _b_21515_21489 = kk_std_num_ddouble__new_Ddouble(0x1.d906bcf328d46p-1, 0x1.457e610231ac4p-56, _ctx); /*std/num/ddouble/ddouble*/;
    kk_std_core__list _b_21516_21490;
    kk_std_num_ddouble__ddouble _b_21517_21487 = kk_std_num_ddouble__new_Ddouble(0x1.f6297cff75cbp-1, 0x1.562172a361fd6p-56, _ctx); /*std/num/ddouble/ddouble*/;
    kk_std_core__list _b_21518_21488;
    kk_std_num_ddouble__ddouble _b_21519_21485 = kk_std_num_ddouble__new_Ddouble(0x1p0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/;
    _b_21518_21488 = kk_std_core__new_Cons(kk_reuse_null, kk_std_num_ddouble__ddouble_box(_b_21519_21485, _ctx), kk_std_core__new_Nil(_ctx), _ctx); /*list<std/num/ddouble/ddouble>*/
    _b_21516_21490 = kk_std_core__new_Cons(kk_reuse_null, kk_std_num_ddouble__ddouble_box(_b_21517_21487, _ctx), _b_21518_21488, _ctx); /*list<std/num/ddouble/ddouble>*/
    _b_21514_21492 = kk_std_core__new_Cons(kk_reuse_null, kk_std_num_ddouble__ddouble_box(_b_21515_21489, _ctx), _b_21516_21490, _ctx); /*list<std/num/ddouble/ddouble>*/
    _b_21512_21494 = kk_std_core__new_Cons(kk_reuse_null, kk_std_num_ddouble__ddouble_box(_b_21513_21491, _ctx), _b_21514_21492, _ctx); /*list<std/num/ddouble/ddouble>*/
    _b_21510_21496 = kk_std_core__new_Cons(kk_reuse_null, kk_std_num_ddouble__ddouble_box(_b_21511_21493, _ctx), _b_21512_21494, _ctx); /*list<std/num/ddouble/ddouble>*/
    _b_21508_21498 = kk_std_core__new_Cons(kk_reuse_null, kk_std_num_ddouble__ddouble_box(_b_21509_21495, _ctx), _b_21510_21496, _ctx); /*list<std/num/ddouble/ddouble>*/
    _b_21506_21500 = kk_std_core__new_Cons(kk_reuse_null, kk_std_num_ddouble__ddouble_box(_b_21507_21497, _ctx), _b_21508_21498, _ctx); /*list<std/num/ddouble/ddouble>*/
    _b_21504_21502 = kk_std_core__new_Cons(kk_reuse_null, kk_std_num_ddouble__ddouble_box(_b_21505_21499, _ctx), _b_21506_21500, _ctx); /*list<std/num/ddouble/ddouble>*/
    xs_20796 = kk_std_core__new_Cons(kk_reuse_null, kk_std_num_ddouble__ddouble_box(_b_21503_21501, _ctx), _b_21504_21502, _ctx); /*list<std/num/ddouble/ddouble>*/
    kk_std_num_ddouble_sin16_table = kk_std_core_unvlist(xs_20796, _ctx); /*vector<std/num/ddouble/ddouble>*/
  }
  {
    kk_std_num_ddouble_dd_e = kk_std_num_ddouble__new_Ddouble(0x1.5bf0a8b145769p1, 0x1.4d57ee2b1013ap-53, _ctx); /*std/num/ddouble/ddouble*/
  }
  {
    double _x22872 = kk_std_num_double_make_neginf(_ctx); /*double*/
    kk_std_num_ddouble_dd_neginf = kk_std_num_ddouble__new_Ddouble(_x22872, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  }
  {
    kk_std_num_ddouble_dd_epsilon = kk_std_num_ddouble__new_Ddouble(0x1p-104, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  }
  {
    kk_std_num_ddouble_dd_log2 = kk_std_num_ddouble__new_Ddouble(0x1.62e42fefa39efp-1, 0x1.abc9e3b39803fp-56, _ctx); /*std/num/ddouble/ddouble*/
  }
  {
    double _x22873 = kk_std_num_double_make_posinf(_ctx); /*double*/
    kk_std_num_ddouble_dd_posinf = kk_std_num_ddouble__new_Ddouble(_x22873, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  }
  {
    kk_std_num_ddouble__ddouble _b_21574_21572 = kk_std_num_ddouble__new_Ddouble(0x1.5555555555555p-3, 0x1.5555555555555p-57, _ctx); /*std/num/ddouble/ddouble*/;
    kk_std_core__list _b_21575_21573;
    kk_std_num_ddouble__ddouble _b_21576_21570 = kk_std_num_ddouble__new_Ddouble(0x1.5555555555555p-5, 0x1.5555555555555p-59, _ctx); /*std/num/ddouble/ddouble*/;
    kk_std_core__list _b_21577_21571;
    kk_std_num_ddouble__ddouble _b_21578_21568 = kk_std_num_ddouble__new_Ddouble(0x1.1111111111111p-7, 0x1.1111111111111p-63, _ctx); /*std/num/ddouble/ddouble*/;
    kk_std_core__list _b_21579_21569;
    kk_std_num_ddouble__ddouble _b_21580_21566 = kk_std_num_ddouble__new_Ddouble(0x1.6c16c16c16c17p-10, -0x1.f49f49f49f49fp-65, _ctx); /*std/num/ddouble/ddouble*/;
    kk_std_core__list _b_21581_21567;
    kk_std_num_ddouble__ddouble _b_21582_21564 = kk_std_num_ddouble__new_Ddouble(0x1.a01a01a01a01ap-13, 0x1.a01a01a01a01ap-73, _ctx); /*std/num/ddouble/ddouble*/;
    kk_std_core__list _b_21583_21565;
    kk_std_num_ddouble__ddouble _b_21584_21562 = kk_std_num_ddouble__new_Ddouble(0x1.a01a01a01a01ap-16, 0x1.a01a01a01a01ap-76, _ctx); /*std/num/ddouble/ddouble*/;
    _b_21583_21565 = kk_std_core__new_Cons(kk_reuse_null, kk_std_num_ddouble__ddouble_box(_b_21584_21562, _ctx), kk_std_core__new_Nil(_ctx), _ctx); /*list<std/num/ddouble/ddouble>*/
    _b_21581_21567 = kk_std_core__new_Cons(kk_reuse_null, kk_std_num_ddouble__ddouble_box(_b_21582_21564, _ctx), _b_21583_21565, _ctx); /*list<std/num/ddouble/ddouble>*/
    _b_21579_21569 = kk_std_core__new_Cons(kk_reuse_null, kk_std_num_ddouble__ddouble_box(_b_21580_21566, _ctx), _b_21581_21567, _ctx); /*list<std/num/ddouble/ddouble>*/
    _b_21577_21571 = kk_std_core__new_Cons(kk_reuse_null, kk_std_num_ddouble__ddouble_box(_b_21578_21568, _ctx), _b_21579_21569, _ctx); /*list<std/num/ddouble/ddouble>*/
    _b_21575_21573 = kk_std_core__new_Cons(kk_reuse_null, kk_std_num_ddouble__ddouble_box(_b_21576_21570, _ctx), _b_21577_21571, _ctx); /*list<std/num/ddouble/ddouble>*/
    kk_std_num_ddouble_exp_factors = kk_std_core__new_Cons(kk_reuse_null, kk_std_num_ddouble__ddouble_box(_b_21574_21572, _ctx), _b_21575_21573, _ctx); /*list<std/num/ddouble/ddouble>*/
  }
  {
    kk_std_num_ddouble_dd_epsilon8 = kk_std_num_ddouble__new_Ddouble(0x1p-101, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  }
  {
    kk_std_num_ddouble_dd_euler = kk_std_num_ddouble__new_Ddouble(0x1.2788cfc6fb619p-1, -0x1.6cb90701fbfabp-58, _ctx); /*std/num/ddouble/ddouble*/
  }
  {
    kk_std_num_ddouble_dd_log10 = kk_std_num_ddouble__new_Ddouble(0x1.26bb1bbb55516p1, -0x1.f48ad494ea3e9p-53, _ctx); /*std/num/ddouble/ddouble*/
  }
  {
    kk_std_num_ddouble_dd_log10e = kk_std_num_ddouble__new_Ddouble(0x1.bcb7b1526e50ep-2, 0x1.95355baaafad3p-57, _ctx); /*std/num/ddouble/ddouble*/
  }
  {
    kk_std_num_ddouble_dd_log2e = kk_std_num_ddouble__new_Ddouble(0x1.71547652b82fep0, 0x1.777d0ffda0d23p-56, _ctx); /*std/num/ddouble/ddouble*/
  }
  {
    kk_std_num_ddouble_dd_max = kk_std_num_ddouble__new_Ddouble(0x1.fffffffffffffp1023, 0x1.fffffffffffffp969, _ctx); /*std/num/ddouble/ddouble*/
  }
  {
    kk_std_num_ddouble_dd_min = kk_std_num_ddouble__new_Ddouble(0x1p-1022, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  }
  {
    kk_std_num_ddouble_dd_pi16 = kk_std_num_ddouble__new_Ddouble(0x1.921fb54442d18p1, 0x1.1a62633145c07p-53, _ctx); /*std/num/ddouble/ddouble*/
  }
  {
    kk_std_num_ddouble_dd_sqrt12 = kk_std_num_ddouble__new_Ddouble(0x1.6a09e667f3bcdp-1, -0x1.bdd3413b26456p-55, _ctx); /*std/num/ddouble/ddouble*/
  }
  {
    kk_std_num_ddouble_dd_sqrt2 = kk_std_num_ddouble__new_Ddouble(0x1.6a09e667f3bcdp0, -0x1.bdd3413b26456p-54, _ctx); /*std/num/ddouble/ddouble*/
  }
  {
    kk_std_num_ddouble_dd_true_min = kk_std_num_ddouble__new_Ddouble(0x1p-1074, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  }
  {
    kk_std_num_ddouble_two = kk_std_num_ddouble__new_Ddouble(0x1p1, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  }
  {
    kk_std_num_ddouble_one_half = kk_std_num_ddouble__new_Ddouble(0x1p-1, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  }
}
