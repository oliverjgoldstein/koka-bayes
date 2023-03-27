// Koka generated module: "std/time/date", koka version: 2.1.3
#include "std_time_date.h"

kk_std_time_date__clock kk_std_time_date__copy(kk_std_time_date__clock _this, kk_std_core_types__optional hours0, kk_std_core_types__optional minutes0, kk_std_core_types__optional seconds0, kk_context_t* _ctx) { /* (clock, hours : optional<int>, minutes : optional<int>, seconds : optional<std/num/ddouble/ddouble>) -> clock */ 
  kk_integer_t _x10072;
  if (kk_std_core_types__is_Optional(hours0)) {
    kk_box_t _box_x9852 = hours0._cons.Optional.value;
    kk_integer_t _hours_97 = kk_integer_unbox(_box_x9852);
    kk_integer_dup(_hours_97);
    kk_std_core_types__optional_drop(hours0, _ctx);
    _x10072 = _hours_97; /*int*/
    goto _match10073;
  }
  struct kk_std_time_date_Clock* _con10075 = kk_std_time_date__as_Clock(_this);
  kk_integer_t _x = _con10075->hours;
  kk_std_num_ddouble__ddouble _pat10 = _con10075->seconds;
  kk_integer_dup(_x);
  _x10072 = _x; /*int*/
  _match10073: ;
  kk_integer_t _x10076;
  if (kk_std_core_types__is_Optional(minutes0)) {
    kk_box_t _box_x9853 = minutes0._cons.Optional.value;
    kk_integer_t _minutes_103 = kk_integer_unbox(_box_x9853);
    kk_integer_dup(_minutes_103);
    kk_std_core_types__optional_drop(minutes0, _ctx);
    _x10076 = _minutes_103; /*int*/
    goto _match10077;
  }
  struct kk_std_time_date_Clock* _con10079 = kk_std_time_date__as_Clock(_this);
  kk_integer_t _x0 = _con10079->minutes;
  kk_std_num_ddouble__ddouble _pat12 = _con10079->seconds;
  kk_integer_dup(_x0);
  _x10076 = _x0; /*int*/
  _match10077: ;
  kk_std_num_ddouble__ddouble _x10080;
  if (kk_std_core_types__is_Optional(seconds0)) {
    kk_box_t _box_x9854 = seconds0._cons.Optional.value;
    kk_std_num_ddouble__ddouble _seconds_109 = kk_std_num_ddouble__ddouble_unbox(_box_x9854, NULL);
    kk_std_core_types__optional_drop(seconds0, _ctx);
    kk_std_time_date__clock_dropn(_this, ((int32_t)2), _ctx);
    _x10080 = _seconds_109; /*std/num/ddouble/ddouble*/
    goto _match10081;
  }
  struct kk_std_time_date_Clock* _con10083 = kk_std_time_date__as_Clock(_this);
  kk_integer_t _pat02 = _con10083->hours;
  kk_integer_t _pat13 = _con10083->minutes;
  kk_std_num_ddouble__ddouble _x1 = _con10083->seconds;
  if (kk_std_time_date__clock_is_unique(_this)) {
    kk_integer_drop(_pat13, _ctx);
    kk_integer_drop(_pat02, _ctx);
    kk_std_time_date__clock_free(_this);
  }
  else {
    kk_std_time_date__clock_decref(_this, _ctx);
  }
  _x10080 = _x1; /*std/num/ddouble/ddouble*/
  _match10081: ;
  return kk_std_time_date__new_Clock(kk_reuse_null, _x10072, _x10076, _x10080, _ctx);
}

kk_std_time_date__date kk_std_time_date__copy_1(kk_std_time_date__date _this, kk_std_core_types__optional year0, kk_std_core_types__optional month0, kk_std_core_types__optional day0, kk_context_t* _ctx) { /* (date, year : optional<int>, month : optional<int>, day : optional<int>) -> date */ 
  kk_integer_t _x10084;
  if (kk_std_core_types__is_Optional(year0)) {
    kk_box_t _box_x9855 = year0._cons.Optional.value;
    kk_integer_t _year_143 = kk_integer_unbox(_box_x9855);
    kk_integer_dup(_year_143);
    kk_std_core_types__optional_drop(year0, _ctx);
    _x10084 = _year_143; /*int*/
    goto _match10085;
  }
  kk_integer_t _x = _this.year;
  kk_integer_dup(_x);
  _x10084 = _x; /*int*/
  _match10085: ;
  kk_integer_t _x10087;
  if (kk_std_core_types__is_Optional(month0)) {
    kk_box_t _box_x9856 = month0._cons.Optional.value;
    kk_integer_t _month_149 = kk_integer_unbox(_box_x9856);
    kk_integer_dup(_month_149);
    kk_std_core_types__optional_drop(month0, _ctx);
    _x10087 = _month_149; /*int*/
    goto _match10088;
  }
  kk_integer_t _x0 = _this.month;
  kk_integer_dup(_x0);
  _x10087 = _x0; /*int*/
  _match10088: ;
  kk_integer_t _x10090;
  if (kk_std_core_types__is_Optional(day0)) {
    kk_box_t _box_x9857 = day0._cons.Optional.value;
    kk_integer_t _day_155 = kk_integer_unbox(_box_x9857);
    kk_integer_dup(_day_155);
    kk_std_core_types__optional_drop(day0, _ctx);
    kk_std_time_date__date_drop(_this, _ctx);
    _x10090 = _day_155; /*int*/
    goto _match10091;
  }
  kk_integer_t _x1 = _this.day;
  kk_integer_dup(_x1);
  kk_std_time_date__date_drop(_this, _ctx);
  _x10090 = _x1; /*int*/
  _match10091: ;
  return kk_std_time_date__new_Date(_x10084, _x10087, _x10090, _ctx);
}
 
// Convert a `:weekday` to an `:int` using the ISO definition which starts at Monday as 1,
// up to Sunday as 7.

kk_integer_t kk_std_time_date_int(kk_std_time_date__weekday wd, kk_context_t* _ctx) { /* (wd : weekday) -> int */ 
  if (kk_std_time_date__is_Mon(wd)) {
    return kk_integer_from_small(1);
  }
  if (kk_std_time_date__is_Tue(wd)) {
    return kk_integer_from_small(2);
  }
  if (kk_std_time_date__is_Wed(wd)) {
    return kk_integer_from_small(3);
  }
  if (kk_std_time_date__is_Thu(wd)) {
    return kk_integer_from_small(4);
  }
  if (kk_std_time_date__is_Fri(wd)) {
    return kk_integer_from_small(5);
  }
  if (kk_std_time_date__is_Sat(wd)) {
    return kk_integer_from_small(6);
  }
  return kk_integer_from_small(7);
}
 
// Add two dates field-wise together.

kk_std_time_date__date kk_std_time_date__lp__plus__rp_(kk_std_time_date__date d1, kk_std_time_date__date d2, kk_context_t* _ctx) { /* (d1 : date, d2 : date) -> date */ 
  kk_integer_t _x10093;
  kk_integer_t _x10094;
  kk_integer_t _x = d1.year;
  kk_integer_dup(_x);
  _x10094 = _x; /*int*/
  kk_integer_t _x10095;
  kk_integer_t _x0 = d2.year;
  kk_integer_dup(_x0);
  _x10095 = _x0; /*int*/
  _x10093 = kk_integer_add(_x10094,_x10095,kk_context()); /*int*/
  kk_integer_t _x10096;
  kk_integer_t _x10097;
  kk_integer_t _x1 = d1.month;
  kk_integer_dup(_x1);
  _x10097 = _x1; /*int*/
  kk_integer_t _x10098;
  kk_integer_t _x2 = d2.month;
  kk_integer_dup(_x2);
  _x10098 = _x2; /*int*/
  _x10096 = kk_integer_add(_x10097,_x10098,kk_context()); /*int*/
  kk_integer_t _x10099;
  kk_integer_t _x10100;
  kk_integer_t _x3 = d1.day;
  kk_integer_dup(_x3);
  kk_std_time_date__date_drop(d1, _ctx);
  _x10100 = _x3; /*int*/
  kk_integer_t _x10101;
  kk_integer_t _x4 = d2.day;
  kk_integer_dup(_x4);
  kk_std_time_date__date_drop(d2, _ctx);
  _x10101 = _x4; /*int*/
  _x10099 = kk_integer_add(_x10100,_x10101,kk_context()); /*int*/
  return kk_std_time_date__new_Date(_x10093, _x10096, _x10099, _ctx);
}
 
// Add two clock together.

kk_std_time_date__clock kk_std_time_date__lp__plus__1_rp_(kk_std_time_date__clock c, kk_std_time_date__clock d, kk_context_t* _ctx) { /* (c : clock, d : clock) -> clock */ 
  kk_integer_t _x10102;
  kk_integer_t _x10103;
  struct kk_std_time_date_Clock* _con10104 = kk_std_time_date__as_Clock(c);
  kk_integer_t _x = _con10104->hours;
  kk_std_num_ddouble__ddouble _pat1 = _con10104->seconds;
  kk_integer_dup(_x);
  _x10103 = _x; /*int*/
  kk_integer_t _x10105;
  struct kk_std_time_date_Clock* _con10106 = kk_std_time_date__as_Clock(d);
  kk_integer_t _x0 = _con10106->hours;
  kk_std_num_ddouble__ddouble _pat10 = _con10106->seconds;
  kk_integer_dup(_x0);
  _x10105 = _x0; /*int*/
  _x10102 = kk_integer_add(_x10103,_x10105,kk_context()); /*int*/
  kk_integer_t _x10107;
  kk_integer_t _x10108;
  struct kk_std_time_date_Clock* _con10109 = kk_std_time_date__as_Clock(c);
  kk_integer_t _x1 = _con10109->minutes;
  kk_std_num_ddouble__ddouble _pat11 = _con10109->seconds;
  kk_integer_dup(_x1);
  _x10108 = _x1; /*int*/
  kk_integer_t _x10110;
  struct kk_std_time_date_Clock* _con10111 = kk_std_time_date__as_Clock(d);
  kk_integer_t _x2 = _con10111->minutes;
  kk_std_num_ddouble__ddouble _pat12 = _con10111->seconds;
  kk_integer_dup(_x2);
  _x10110 = _x2; /*int*/
  _x10107 = kk_integer_add(_x10108,_x10110,kk_context()); /*int*/
  kk_std_num_ddouble__ddouble _x10112;
  kk_std_num_ddouble__ddouble _x10113;
  struct kk_std_time_date_Clock* _con10114 = kk_std_time_date__as_Clock(c);
  kk_integer_t _pat03 = _con10114->hours;
  kk_integer_t _pat13 = _con10114->minutes;
  kk_std_num_ddouble__ddouble _x3 = _con10114->seconds;
  if (kk_std_time_date__clock_is_unique(c)) {
    kk_integer_drop(_pat13, _ctx);
    kk_integer_drop(_pat03, _ctx);
    kk_std_time_date__clock_free(c);
  }
  else {
    kk_std_time_date__clock_decref(c, _ctx);
  }
  _x10113 = _x3; /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x10115;
  struct kk_std_time_date_Clock* _con10116 = kk_std_time_date__as_Clock(d);
  kk_integer_t _pat04 = _con10116->hours;
  kk_integer_t _pat14 = _con10116->minutes;
  kk_std_num_ddouble__ddouble _x4 = _con10116->seconds;
  if (kk_std_time_date__clock_is_unique(d)) {
    kk_integer_drop(_pat14, _ctx);
    kk_integer_drop(_pat04, _ctx);
    kk_std_time_date__clock_free(d);
  }
  else {
    kk_std_time_date__clock_decref(d, _ctx);
  }
  _x10115 = _x4; /*std/num/ddouble/ddouble*/
  _x10112 = kk_std_num_ddouble__lp__plus__rp_(_x10113, _x10115, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_time_date__new_Clock(kk_reuse_null, _x10102, _x10107, _x10112, _ctx);
}
 
// Convert a weekday number to a `:weekday`(starting at Monday (=1) up to Sunday (=7)).
// Takes the integer `i - 1` modulo 7, so `0` or `14` also become Sunday etc.

kk_std_time_date__weekday kk_std_time_date_weekday(kk_integer_t i, kk_context_t* _ctx) { /* (i : int) -> weekday */ 
  kk_integer_t d;
  kk_integer_t _x10117 = kk_integer_sub(i,(kk_integer_from_small(1)),kk_context()); /*int*/
  d = kk_integer_mod(_x10117,(kk_integer_from_small(7)),kk_context()); /*int*/
  bool _match_10063;
  kk_integer_t _x10118 = kk_integer_dup(d); /*int*/
  _match_10063 = kk_integer_eq(_x10118,(kk_integer_from_small(0)),kk_context()); /*bool*/
  if (_match_10063) {
    kk_integer_drop(d, _ctx);
    return kk_std_time_date__new_Mon(_ctx);
  }
  bool _match_10064;
  kk_integer_t _x10119 = kk_integer_dup(d); /*int*/
  _match_10064 = kk_integer_eq(_x10119,(kk_integer_from_small(1)),kk_context()); /*bool*/
  if (_match_10064) {
    kk_integer_drop(d, _ctx);
    return kk_std_time_date__new_Tue(_ctx);
  }
  bool _match_10065;
  kk_integer_t _x10120 = kk_integer_dup(d); /*int*/
  _match_10065 = kk_integer_eq(_x10120,(kk_integer_from_small(2)),kk_context()); /*bool*/
  if (_match_10065) {
    kk_integer_drop(d, _ctx);
    return kk_std_time_date__new_Wed(_ctx);
  }
  bool _match_10066;
  kk_integer_t _x10121 = kk_integer_dup(d); /*int*/
  _match_10066 = kk_integer_eq(_x10121,(kk_integer_from_small(3)),kk_context()); /*bool*/
  if (_match_10066) {
    kk_integer_drop(d, _ctx);
    return kk_std_time_date__new_Thu(_ctx);
  }
  bool _match_10067;
  kk_integer_t _x10122 = kk_integer_dup(d); /*int*/
  _match_10067 = kk_integer_eq(_x10122,(kk_integer_from_small(4)),kk_context()); /*bool*/
  if (_match_10067) {
    kk_integer_drop(d, _ctx);
    return kk_std_time_date__new_Fri(_ctx);
  }
  bool _match_10068 = kk_integer_eq(d,(kk_integer_from_small(5)),kk_context()); /*bool*/;
  if (_match_10068) {
    return kk_std_time_date__new_Sat(_ctx);
  }
  return kk_std_time_date__new_Sun(_ctx);
}
 
// Return the `:weekday` that comes `n` days after week day `wd`.

kk_std_time_date__weekday kk_std_time_date__lp__plus__2_rp_(kk_std_time_date__weekday wd, kk_integer_t n, kk_context_t* _ctx) { /* (wd : weekday, n : int) -> weekday */ 
  kk_integer_t i_9712;
  kk_integer_t _x10123 = kk_std_time_date_int(wd, _ctx); /*int*/
  i_9712 = kk_integer_add(_x10123,n,kk_context()); /*int*/
  kk_integer_t d;
  kk_integer_t _x10124 = kk_integer_sub(i_9712,(kk_integer_from_small(1)),kk_context()); /*int*/
  d = kk_integer_mod(_x10124,(kk_integer_from_small(7)),kk_context()); /*int*/
  bool _match_10057;
  kk_integer_t _x10125 = kk_integer_dup(d); /*int*/
  _match_10057 = kk_integer_eq(_x10125,(kk_integer_from_small(0)),kk_context()); /*bool*/
  if (_match_10057) {
    kk_integer_drop(d, _ctx);
    return kk_std_time_date__new_Mon(_ctx);
  }
  bool _match_10058;
  kk_integer_t _x10126 = kk_integer_dup(d); /*int*/
  _match_10058 = kk_integer_eq(_x10126,(kk_integer_from_small(1)),kk_context()); /*bool*/
  if (_match_10058) {
    kk_integer_drop(d, _ctx);
    return kk_std_time_date__new_Tue(_ctx);
  }
  bool _match_10059;
  kk_integer_t _x10127 = kk_integer_dup(d); /*int*/
  _match_10059 = kk_integer_eq(_x10127,(kk_integer_from_small(2)),kk_context()); /*bool*/
  if (_match_10059) {
    kk_integer_drop(d, _ctx);
    return kk_std_time_date__new_Wed(_ctx);
  }
  bool _match_10060;
  kk_integer_t _x10128 = kk_integer_dup(d); /*int*/
  _match_10060 = kk_integer_eq(_x10128,(kk_integer_from_small(3)),kk_context()); /*bool*/
  if (_match_10060) {
    kk_integer_drop(d, _ctx);
    return kk_std_time_date__new_Thu(_ctx);
  }
  bool _match_10061;
  kk_integer_t _x10129 = kk_integer_dup(d); /*int*/
  _match_10061 = kk_integer_eq(_x10129,(kk_integer_from_small(4)),kk_context()); /*bool*/
  if (_match_10061) {
    kk_integer_drop(d, _ctx);
    return kk_std_time_date__new_Fri(_ctx);
  }
  bool _match_10062 = kk_integer_eq(d,(kk_integer_from_small(5)),kk_context()); /*bool*/;
  if (_match_10062) {
    return kk_std_time_date__new_Sat(_ctx);
  }
  return kk_std_time_date__new_Sun(_ctx);
}
 
// Return the `:weekday` that comes `n` days before week day `wd`.

kk_std_time_date__weekday kk_std_time_date__lp__dash__rp_(kk_std_time_date__weekday wd, kk_integer_t n, kk_context_t* _ctx) { /* (wd : weekday, n : int) -> weekday */ 
  kk_integer_t i_9713;
  kk_integer_t _x10130 = kk_std_time_date_int(wd, _ctx); /*int*/
  i_9713 = kk_integer_sub(_x10130,n,kk_context()); /*int*/
  kk_integer_t d;
  kk_integer_t _x10131 = kk_integer_sub(i_9713,(kk_integer_from_small(1)),kk_context()); /*int*/
  d = kk_integer_mod(_x10131,(kk_integer_from_small(7)),kk_context()); /*int*/
  bool _match_10051;
  kk_integer_t _x10132 = kk_integer_dup(d); /*int*/
  _match_10051 = kk_integer_eq(_x10132,(kk_integer_from_small(0)),kk_context()); /*bool*/
  if (_match_10051) {
    kk_integer_drop(d, _ctx);
    return kk_std_time_date__new_Mon(_ctx);
  }
  bool _match_10052;
  kk_integer_t _x10133 = kk_integer_dup(d); /*int*/
  _match_10052 = kk_integer_eq(_x10133,(kk_integer_from_small(1)),kk_context()); /*bool*/
  if (_match_10052) {
    kk_integer_drop(d, _ctx);
    return kk_std_time_date__new_Tue(_ctx);
  }
  bool _match_10053;
  kk_integer_t _x10134 = kk_integer_dup(d); /*int*/
  _match_10053 = kk_integer_eq(_x10134,(kk_integer_from_small(2)),kk_context()); /*bool*/
  if (_match_10053) {
    kk_integer_drop(d, _ctx);
    return kk_std_time_date__new_Wed(_ctx);
  }
  bool _match_10054;
  kk_integer_t _x10135 = kk_integer_dup(d); /*int*/
  _match_10054 = kk_integer_eq(_x10135,(kk_integer_from_small(3)),kk_context()); /*bool*/
  if (_match_10054) {
    kk_integer_drop(d, _ctx);
    return kk_std_time_date__new_Thu(_ctx);
  }
  bool _match_10055;
  kk_integer_t _x10136 = kk_integer_dup(d); /*int*/
  _match_10055 = kk_integer_eq(_x10136,(kk_integer_from_small(4)),kk_context()); /*bool*/
  if (_match_10055) {
    kk_integer_drop(d, _ctx);
    return kk_std_time_date__new_Fri(_ctx);
  }
  bool _match_10056 = kk_integer_eq(d,(kk_integer_from_small(5)),kk_context()); /*bool*/;
  if (_match_10056) {
    return kk_std_time_date__new_Sat(_ctx);
  }
  return kk_std_time_date__new_Sun(_ctx);
}
 
// Compare two dates by fields.

kk_std_core_types__order kk_std_time_date_compare(kk_std_time_date__date d, kk_std_time_date__date e, kk_context_t* _ctx) { /* (d : date, e : date) -> order */ 
  kk_std_core_types__order _match_10049;
  kk_integer_t _x10140;
  kk_integer_t _x = d.year;
  kk_integer_dup(_x);
  _x10140 = _x; /*int*/
  kk_integer_t _x10141;
  kk_integer_t _x0 = e.year;
  kk_integer_dup(_x0);
  _x10141 = _x0; /*int*/
  _match_10049 = kk_int_as_order(kk_integer_cmp(_x10140,_x10141,kk_context()),kk_context()); /*order*/
  if (kk_std_core_types__is_Eq(_match_10049)) {
    kk_std_core_types__order _match_10050;
    kk_integer_t _x10142;
    kk_integer_t _x1 = d.month;
    kk_integer_dup(_x1);
    _x10142 = _x1; /*int*/
    kk_integer_t _x10143;
    kk_integer_t _x2 = e.month;
    kk_integer_dup(_x2);
    _x10143 = _x2; /*int*/
    _match_10050 = kk_int_as_order(kk_integer_cmp(_x10142,_x10143,kk_context()),kk_context()); /*order*/
    if (kk_std_core_types__is_Eq(_match_10050)) {
      kk_integer_t _x10144;
      kk_integer_t _x3 = d.day;
      kk_integer_dup(_x3);
      kk_std_time_date__date_drop(d, _ctx);
      _x10144 = _x3; /*int*/
      kk_integer_t _x10145;
      kk_integer_t _x4 = e.day;
      kk_integer_dup(_x4);
      kk_std_time_date__date_drop(e, _ctx);
      _x10145 = _x4; /*int*/
      return kk_int_as_order(kk_integer_cmp(_x10144,_x10145,kk_context()),kk_context());
    }
    kk_std_time_date__date_drop(d, _ctx);
    kk_std_time_date__date_drop(e, _ctx);
    return _match_10050;
  }
  kk_std_time_date__date_drop(d, _ctx);
  kk_std_time_date__date_drop(e, _ctx);
  return _match_10049;
}

bool kk_std_time_date__lp__eq__eq__rp_(kk_std_time_date__date i, kk_std_time_date__date j, kk_context_t* _ctx) { /* (i : date, j : date) -> bool */ 
  kk_std_core_types__order x_9720 = kk_std_time_date_compare(i, j, _ctx); /*order*/;
  kk_integer_t _x10146 = kk_std_core_int_5(x_9720, _ctx); /*int*/
  kk_integer_t _x10147;
  kk_std_core_types__order _x10148 = kk_std_core_types__new_Eq(_ctx); /*order*/
  if (kk_std_core_types__is_Lt(_x10148)) {
    _x10147 = kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context()); /*int*/
    goto _match10149;
  }
  if (kk_std_core_types__is_Eq(_x10148)) {
    _x10147 = kk_integer_from_small(0); /*int*/
    goto _match10149;
  }
  _x10147 = kk_integer_from_small(1); /*int*/
  _match10149: ;
  return kk_integer_eq(_x10146,_x10147,kk_context());
}
 
// Return the total seconds of a `:clock` assuming 60 seconds per
// minute and 60 minutes per hour.

kk_std_num_ddouble__ddouble kk_std_time_date_total_seconds(kk_std_time_date__clock c, kk_context_t* _ctx) { /* (c : clock) -> std/num/ddouble/ddouble */ 
  kk_std_num_ddouble__ddouble _x10150;
  kk_integer_t i_9722;
  kk_integer_t _x10151;
  kk_integer_t _x10152;
  kk_integer_t _x10153;
  struct kk_std_time_date_Clock* _con10154 = kk_std_time_date__as_Clock(c);
  kk_integer_t _x = _con10154->hours;
  kk_std_num_ddouble__ddouble _pat1 = _con10154->seconds;
  kk_integer_dup(_x);
  _x10153 = _x; /*int*/
  _x10152 = kk_integer_mul(_x10153,(kk_integer_from_small(60)),kk_context()); /*int*/
  kk_integer_t _x10155;
  struct kk_std_time_date_Clock* _con10156 = kk_std_time_date__as_Clock(c);
  kk_integer_t _x0 = _con10156->minutes;
  kk_std_num_ddouble__ddouble _pat10 = _con10156->seconds;
  kk_integer_dup(_x0);
  _x10155 = _x0; /*int*/
  _x10151 = kk_integer_add(_x10152,_x10155,kk_context()); /*int*/
  i_9722 = kk_integer_mul(_x10151,(kk_integer_from_small(60)),kk_context()); /*int*/
  _x10150 = kk_std_num_ddouble_ddouble_int_exp(i_9722, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x10157;
  struct kk_std_time_date_Clock* _con10158 = kk_std_time_date__as_Clock(c);
  kk_integer_t _pat01 = _con10158->hours;
  kk_integer_t _pat11 = _con10158->minutes;
  kk_std_num_ddouble__ddouble _x1 = _con10158->seconds;
  if (kk_std_time_date__clock_is_unique(c)) {
    kk_integer_drop(_pat11, _ctx);
    kk_integer_drop(_pat01, _ctx);
    kk_std_time_date__clock_free(c);
  }
  else {
    kk_std_time_date__clock_decref(c, _ctx);
  }
  _x10157 = _x1; /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__lp__plus__rp_(_x10150, _x10157, _ctx);
}
 
// Compare two clocks as by their total seconds.

kk_std_core_types__order kk_std_time_date_compare_1(kk_std_time_date__clock c, kk_std_time_date__clock d, kk_context_t* _ctx) { /* (c : clock, d : clock) -> order */ 
  kk_std_num_ddouble__ddouble x_9726 = kk_std_time_date_total_seconds(c, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__ddouble y_9727 = kk_std_time_date_total_seconds(d, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_core_types__order _match_10043;
  bool _match_10046;
  double _x10159;
  double _x = x_9726.hi;
  _x10159 = _x; /*double*/
  double _x10160;
  double _x0 = y_9727.hi;
  _x10160 = _x0; /*double*/
  _match_10046 = (_x10159 < _x10160); /*bool*/
  if (_match_10046) {
    _match_10043 = kk_std_core_types__new_Lt(_ctx); /*order*/
  }
  else {
    bool _match_10047;
    double _x10161;
    double _x1 = x_9726.hi;
    _x10161 = _x1; /*double*/
    double _x10162;
    double _x00 = y_9727.hi;
    _x10162 = _x00; /*double*/
    _match_10047 = (_x10161 > _x10162); /*bool*/
    if (_match_10047) {
      _match_10043 = kk_std_core_types__new_Gt(_ctx); /*order*/
    }
    else {
      _match_10043 = kk_std_core_types__new_Eq(_ctx); /*order*/
    }
  }
  if (kk_std_core_types__is_Eq(_match_10043)) {
    bool _match_10044;
    double _x10163;
    double _x10 = x_9726.lo;
    _x10163 = _x10; /*double*/
    double _x10164;
    double _x2 = y_9727.lo;
    _x10164 = _x2; /*double*/
    _match_10044 = (_x10163 < _x10164); /*bool*/
    if (_match_10044) {
      return kk_std_core_types__new_Lt(_ctx);
    }
    bool _match_10045;
    double _x10165;
    double _x11 = x_9726.lo;
    _x10165 = _x11; /*double*/
    double _x10166;
    double _x20 = y_9727.lo;
    _x10166 = _x20; /*double*/
    _match_10045 = (_x10165 > _x10166); /*bool*/
    if (_match_10045) {
      return kk_std_core_types__new_Gt(_ctx);
    }
    return kk_std_core_types__new_Eq(_ctx);
  }
  return _match_10043;
}

bool kk_std_time_date__lp__eq__eq__1_rp_(kk_std_time_date__clock i, kk_std_time_date__clock j, kk_context_t* _ctx) { /* (i : clock, j : clock) -> bool */ 
  kk_std_core_types__order x_9728 = kk_std_time_date_compare_1(i, j, _ctx); /*order*/;
  kk_integer_t _x10167 = kk_std_core_int_5(x_9728, _ctx); /*int*/
  kk_integer_t _x10168;
  kk_std_core_types__order _x10169 = kk_std_core_types__new_Eq(_ctx); /*order*/
  if (kk_std_core_types__is_Lt(_x10169)) {
    _x10168 = kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context()); /*int*/
    goto _match10170;
  }
  if (kk_std_core_types__is_Eq(_x10169)) {
    _x10168 = kk_integer_from_small(0); /*int*/
    goto _match10170;
  }
  _x10168 = kk_integer_from_small(1); /*int*/
  _match10170: ;
  return kk_integer_eq(_x10167,_x10168,kk_context());
}

bool kk_std_time_date__lp__eq__eq__2_rp_(kk_std_time_date__weekday i, kk_std_time_date__weekday j, kk_context_t* _ctx) { /* (i : weekday, j : weekday) -> bool */ 
  kk_std_core_types__order x_9730 = kk_std_time_date_compare_2(i, j, _ctx); /*order*/;
  kk_integer_t _x10173 = kk_std_core_int_5(x_9730, _ctx); /*int*/
  kk_integer_t _x10174;
  kk_std_core_types__order _x10175 = kk_std_core_types__new_Eq(_ctx); /*order*/
  if (kk_std_core_types__is_Lt(_x10175)) {
    _x10174 = kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context()); /*int*/
    goto _match10176;
  }
  if (kk_std_core_types__is_Eq(_x10175)) {
    _x10174 = kk_integer_from_small(0); /*int*/
    goto _match10176;
  }
  _x10174 = kk_integer_from_small(1); /*int*/
  _match10176: ;
  return kk_integer_eq(_x10173,_x10174,kk_context());
}
 
// Create a clock from a seconds as an `:int` with an optional fraction.
// Normalizes the clock with seconds and minutes under 60 but
// adds the fraction as is to the final seconds, so that might
// be `>= 60` if the fraction `>= 1.0`;

kk_std_time_date__clock kk_std_time_date_clock_2(kk_integer_t seconds0, kk_std_core_types__optional frac, kk_context_t* _ctx) { /* (seconds : int, frac : optional<std/num/ddouble/ddouble>) -> clock */ 
  kk_std_core_types__tuple2_ _match_10039 = kk_integer_div_mod_tuple(seconds0,(kk_integer_from_small(60)),kk_context()); /*(int, int)*/;
  kk_box_t _box_x9858 = _match_10039.fst;
  kk_box_t _box_x9859 = _match_10039.snd;
  kk_integer_t hm = kk_integer_unbox(_box_x9858);
  kk_integer_t s = kk_integer_unbox(_box_x9859);
  kk_integer_dup(hm);
  kk_integer_dup(s);
  kk_std_core_types__tuple2__drop(_match_10039, _ctx);
  kk_std_core_types__tuple2_ _match_10040 = kk_integer_div_mod_tuple(hm,(kk_integer_from_small(60)),kk_context()); /*(int, int)*/;
  kk_box_t _box_x9860 = _match_10040.fst;
  kk_box_t _box_x9861 = _match_10040.snd;
  kk_integer_t h = kk_integer_unbox(_box_x9860);
  kk_integer_t m = kk_integer_unbox(_box_x9861);
  kk_integer_dup(h);
  kk_integer_dup(m);
  kk_std_core_types__tuple2__drop(_match_10040, _ctx);
  kk_std_num_ddouble__ddouble _x10181;
  kk_std_num_ddouble__ddouble _x10182 = kk_std_num_ddouble_ddouble_1(s, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x10183;
  if (kk_std_core_types__is_Optional(frac)) {
    kk_box_t _box_x9862 = frac._cons.Optional.value;
    kk_std_num_ddouble__ddouble _frac_1700 = kk_std_num_ddouble__ddouble_unbox(_box_x9862, NULL);
    kk_std_core_types__optional_drop(frac, _ctx);
    _x10183 = _frac_1700; /*std/num/ddouble/ddouble*/
    goto _match10184;
  }
  _x10183 = kk_std_num_ddouble__new_Ddouble(0x0p+0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  _match10184: ;
  _x10181 = kk_std_num_ddouble__lp__plus__rp_(_x10182, _x10183, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_time_date__new_Clock(kk_reuse_null, h, m, _x10181, _ctx);
}
 
// Create a clock from seconds; normalizes the clock with seconds and minutes under 60.

kk_std_time_date__clock kk_std_time_date_clock(kk_std_num_ddouble__ddouble seconds0, kk_context_t* _ctx) { /* (seconds : std/num/ddouble/ddouble) -> clock */ 
  kk_integer_t seconds0_9732;
  kk_std_num_ddouble__ddouble _x10186 = kk_std_num_ddouble_floor(seconds0, _ctx); /*std/num/ddouble/ddouble*/
  seconds0_9732 = kk_std_num_ddouble_int(_x10186, kk_std_core_types__new_None(_ctx), _ctx); /*int*/
  kk_std_core_types__optional frac_9733;
  kk_std_num_ddouble__ddouble _b_9864_9863 = kk_std_num_ddouble_ffraction(seconds0, _ctx); /*std/num/ddouble/ddouble*/;
  frac_9733 = kk_std_core_types__new_Optional(kk_std_num_ddouble__ddouble_box(_b_9864_9863, _ctx), _ctx); /*optional<std/num/ddouble/ddouble>*/
  kk_std_core_types__tuple2_ _match_10037 = kk_integer_div_mod_tuple(seconds0_9732,(kk_integer_from_small(60)),kk_context()); /*(int, int)*/;
  kk_box_t _box_x9865 = _match_10037.fst;
  kk_box_t _box_x9866 = _match_10037.snd;
  kk_integer_t hm = kk_integer_unbox(_box_x9865);
  kk_integer_t s = kk_integer_unbox(_box_x9866);
  kk_integer_dup(hm);
  kk_integer_dup(s);
  kk_std_core_types__tuple2__drop(_match_10037, _ctx);
  kk_std_core_types__tuple2_ _match_10038 = kk_integer_div_mod_tuple(hm,(kk_integer_from_small(60)),kk_context()); /*(int, int)*/;
  kk_box_t _box_x9867 = _match_10038.fst;
  kk_box_t _box_x9868 = _match_10038.snd;
  kk_integer_t h = kk_integer_unbox(_box_x9867);
  kk_integer_t m = kk_integer_unbox(_box_x9868);
  kk_integer_dup(h);
  kk_integer_dup(m);
  kk_std_core_types__tuple2__drop(_match_10038, _ctx);
  kk_std_num_ddouble__ddouble _x10191;
  kk_std_num_ddouble__ddouble _x10192 = kk_std_num_ddouble_ddouble_1(s, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x10193;
  if (kk_std_core_types__is_Optional(frac_9733)) {
    kk_box_t _box_x9869 = frac_9733._cons.Optional.value;
    kk_std_num_ddouble__ddouble _frac_1700 = kk_std_num_ddouble__ddouble_unbox(_box_x9869, NULL);
    kk_std_core_types__optional_drop(frac_9733, _ctx);
    _x10193 = _frac_1700; /*std/num/ddouble/ddouble*/
    goto _match10194;
  }
  _x10193 = kk_std_num_ddouble__new_Ddouble(0x0p+0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  _match10194: ;
  _x10191 = kk_std_num_ddouble__lp__plus__rp_(_x10192, _x10193, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_time_date__new_Clock(kk_reuse_null, h, m, _x10191, _ctx);
}
 
// Create a clock from a seconds as an `:int` with an optional fraction.
// Normalizes the clock with seconds and minutes under 60 but
// adds the fraction as is to the final seconds, so that might
// be `>= 60` if the fraction `>= 1.0`;

kk_std_time_date__clock kk_std_time_date_clock_1(kk_integer_t seconds0, double frac, kk_context_t* _ctx) { /* (seconds : int, frac : double) -> clock */ 
  kk_std_core_types__optional frac0_9735;
  kk_std_num_ddouble__ddouble _b_9871_9870 = kk_std_num_ddouble_ddouble(frac, _ctx); /*std/num/ddouble/ddouble*/;
  frac0_9735 = kk_std_core_types__new_Optional(kk_std_num_ddouble__ddouble_box(_b_9871_9870, _ctx), _ctx); /*optional<std/num/ddouble/ddouble>*/
  kk_std_core_types__tuple2_ _match_10035 = kk_integer_div_mod_tuple(seconds0,(kk_integer_from_small(60)),kk_context()); /*(int, int)*/;
  kk_box_t _box_x9872 = _match_10035.fst;
  kk_box_t _box_x9873 = _match_10035.snd;
  kk_integer_t hm = kk_integer_unbox(_box_x9872);
  kk_integer_t s = kk_integer_unbox(_box_x9873);
  kk_integer_dup(hm);
  kk_integer_dup(s);
  kk_std_core_types__tuple2__drop(_match_10035, _ctx);
  kk_std_core_types__tuple2_ _match_10036 = kk_integer_div_mod_tuple(hm,(kk_integer_from_small(60)),kk_context()); /*(int, int)*/;
  kk_box_t _box_x9874 = _match_10036.fst;
  kk_box_t _box_x9875 = _match_10036.snd;
  kk_integer_t h = kk_integer_unbox(_box_x9874);
  kk_integer_t m = kk_integer_unbox(_box_x9875);
  kk_integer_dup(h);
  kk_integer_dup(m);
  kk_std_core_types__tuple2__drop(_match_10036, _ctx);
  kk_std_num_ddouble__ddouble _x10200;
  kk_std_num_ddouble__ddouble _x10201 = kk_std_num_ddouble_ddouble_1(s, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x10202;
  if (kk_std_core_types__is_Optional(frac0_9735)) {
    kk_box_t _box_x9876 = frac0_9735._cons.Optional.value;
    kk_std_num_ddouble__ddouble _frac_1700 = kk_std_num_ddouble__ddouble_unbox(_box_x9876, NULL);
    kk_std_core_types__optional_drop(frac0_9735, _ctx);
    _x10202 = _frac_1700; /*std/num/ddouble/ddouble*/
    goto _match10203;
  }
  _x10202 = kk_std_num_ddouble__new_Ddouble(0x0p+0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  _match10203: ;
  _x10200 = kk_std_num_ddouble__lp__plus__rp_(_x10201, _x10202, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_time_date__new_Clock(kk_reuse_null, h, m, _x10200, _ctx);
}

kk_std_time_date__clock kk_std_time_date_clock_3(kk_std_num_ddouble__ddouble seconds0, kk_integer_t leap, kk_context_t* _ctx) { /* (seconds : std/num/ddouble/ddouble, leap : int) -> clock */ 
  kk_integer_t seconds0_9736;
  kk_std_num_ddouble__ddouble _x10205 = kk_std_num_ddouble_floor(seconds0, _ctx); /*std/num/ddouble/ddouble*/
  seconds0_9736 = kk_std_num_ddouble_int(_x10205, kk_std_core_types__new_None(_ctx), _ctx); /*int*/
  kk_std_core_types__optional frac_9737;
  kk_std_num_ddouble__ddouble _b_9878_9877;
  kk_std_num_ddouble__ddouble _x10206 = kk_std_num_ddouble_ffraction(seconds0, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x10207 = kk_std_num_ddouble_ddouble_1(leap, _ctx); /*std/num/ddouble/ddouble*/
  _b_9878_9877 = kk_std_num_ddouble__lp__plus__rp_(_x10206, _x10207, _ctx); /*std/num/ddouble/ddouble*/
  frac_9737 = kk_std_core_types__new_Optional(kk_std_num_ddouble__ddouble_box(_b_9878_9877, _ctx), _ctx); /*optional<std/num/ddouble/ddouble>*/
  kk_std_core_types__tuple2_ _match_10033 = kk_integer_div_mod_tuple(seconds0_9736,(kk_integer_from_small(60)),kk_context()); /*(int, int)*/;
  kk_box_t _box_x9879 = _match_10033.fst;
  kk_box_t _box_x9880 = _match_10033.snd;
  kk_integer_t hm = kk_integer_unbox(_box_x9879);
  kk_integer_t s = kk_integer_unbox(_box_x9880);
  kk_integer_dup(hm);
  kk_integer_dup(s);
  kk_std_core_types__tuple2__drop(_match_10033, _ctx);
  kk_std_core_types__tuple2_ _match_10034 = kk_integer_div_mod_tuple(hm,(kk_integer_from_small(60)),kk_context()); /*(int, int)*/;
  kk_box_t _box_x9881 = _match_10034.fst;
  kk_box_t _box_x9882 = _match_10034.snd;
  kk_integer_t h = kk_integer_unbox(_box_x9881);
  kk_integer_t m = kk_integer_unbox(_box_x9882);
  kk_integer_dup(h);
  kk_integer_dup(m);
  kk_std_core_types__tuple2__drop(_match_10034, _ctx);
  kk_std_num_ddouble__ddouble _x10212;
  kk_std_num_ddouble__ddouble _x10213 = kk_std_num_ddouble_ddouble_1(s, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x10214;
  if (kk_std_core_types__is_Optional(frac_9737)) {
    kk_box_t _box_x9883 = frac_9737._cons.Optional.value;
    kk_std_num_ddouble__ddouble _frac_1700 = kk_std_num_ddouble__ddouble_unbox(_box_x9883, NULL);
    kk_std_core_types__optional_drop(frac_9737, _ctx);
    _x10214 = _frac_1700; /*std/num/ddouble/ddouble*/
    goto _match10215;
  }
  _x10214 = kk_std_num_ddouble__new_Ddouble(0x0p+0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  _match10215: ;
  _x10212 = kk_std_num_ddouble__lp__plus__rp_(_x10213, _x10214, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_time_date__new_Clock(kk_reuse_null, h, m, _x10212, _ctx);
}

bool kk_std_time_date__lp__excl__eq__rp_(kk_std_time_date__date i, kk_std_time_date__date j, kk_context_t* _ctx) { /* (i : date, j : date) -> bool */ 
  kk_std_core_types__order x_9738 = kk_std_time_date_compare(i, j, _ctx); /*order*/;
  kk_integer_t _x10217 = kk_std_core_int_5(x_9738, _ctx); /*int*/
  kk_integer_t _x10218;
  kk_std_core_types__order _x10219 = kk_std_core_types__new_Eq(_ctx); /*order*/
  if (kk_std_core_types__is_Lt(_x10219)) {
    _x10218 = kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context()); /*int*/
    goto _match10220;
  }
  if (kk_std_core_types__is_Eq(_x10219)) {
    _x10218 = kk_integer_from_small(0); /*int*/
    goto _match10220;
  }
  _x10218 = kk_integer_from_small(1); /*int*/
  _match10220: ;
  return kk_integer_neq(_x10217,_x10218,kk_context());
}

bool kk_std_time_date__lp__excl__eq__1_rp_(kk_std_time_date__clock i, kk_std_time_date__clock j, kk_context_t* _ctx) { /* (i : clock, j : clock) -> bool */ 
  kk_std_core_types__order x_9740 = kk_std_time_date_compare_1(i, j, _ctx); /*order*/;
  kk_integer_t _x10221 = kk_std_core_int_5(x_9740, _ctx); /*int*/
  kk_integer_t _x10222;
  kk_std_core_types__order _x10223 = kk_std_core_types__new_Eq(_ctx); /*order*/
  if (kk_std_core_types__is_Lt(_x10223)) {
    _x10222 = kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context()); /*int*/
    goto _match10224;
  }
  if (kk_std_core_types__is_Eq(_x10223)) {
    _x10222 = kk_integer_from_small(0); /*int*/
    goto _match10224;
  }
  _x10222 = kk_integer_from_small(1); /*int*/
  _match10224: ;
  return kk_integer_neq(_x10221,_x10222,kk_context());
}

bool kk_std_time_date__lp__excl__eq__2_rp_(kk_std_time_date__weekday i, kk_std_time_date__weekday j, kk_context_t* _ctx) { /* (i : weekday, j : weekday) -> bool */ 
  kk_std_core_types__order x_9742 = kk_std_time_date_compare_2(i, j, _ctx); /*order*/;
  kk_integer_t _x10225 = kk_std_core_int_5(x_9742, _ctx); /*int*/
  kk_integer_t _x10226;
  kk_std_core_types__order _x10227 = kk_std_core_types__new_Eq(_ctx); /*order*/
  if (kk_std_core_types__is_Lt(_x10227)) {
    _x10226 = kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context()); /*int*/
    goto _match10228;
  }
  if (kk_std_core_types__is_Eq(_x10227)) {
    _x10226 = kk_integer_from_small(0); /*int*/
    goto _match10228;
  }
  _x10226 = kk_integer_from_small(1); /*int*/
  _match10228: ;
  return kk_integer_neq(_x10225,_x10226,kk_context());
}

bool kk_std_time_date__lp__lt__rp_(kk_std_time_date__date i, kk_std_time_date__date j, kk_context_t* _ctx) { /* (i : date, j : date) -> bool */ 
  kk_std_core_types__order x_9744 = kk_std_time_date_compare(i, j, _ctx); /*order*/;
  kk_integer_t _x10229 = kk_std_core_int_5(x_9744, _ctx); /*int*/
  kk_integer_t _x10230;
  kk_std_core_types__order _x10231 = kk_std_core_types__new_Lt(_ctx); /*order*/
  if (kk_std_core_types__is_Lt(_x10231)) {
    _x10230 = kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context()); /*int*/
    goto _match10232;
  }
  if (kk_std_core_types__is_Eq(_x10231)) {
    _x10230 = kk_integer_from_small(0); /*int*/
    goto _match10232;
  }
  _x10230 = kk_integer_from_small(1); /*int*/
  _match10232: ;
  return kk_integer_eq(_x10229,_x10230,kk_context());
}

bool kk_std_time_date__lp__lt__1_rp_(kk_std_time_date__clock i, kk_std_time_date__clock j, kk_context_t* _ctx) { /* (i : clock, j : clock) -> bool */ 
  kk_std_core_types__order x_9746 = kk_std_time_date_compare_1(i, j, _ctx); /*order*/;
  kk_integer_t _x10233 = kk_std_core_int_5(x_9746, _ctx); /*int*/
  kk_integer_t _x10234;
  kk_std_core_types__order _x10235 = kk_std_core_types__new_Lt(_ctx); /*order*/
  if (kk_std_core_types__is_Lt(_x10235)) {
    _x10234 = kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context()); /*int*/
    goto _match10236;
  }
  if (kk_std_core_types__is_Eq(_x10235)) {
    _x10234 = kk_integer_from_small(0); /*int*/
    goto _match10236;
  }
  _x10234 = kk_integer_from_small(1); /*int*/
  _match10236: ;
  return kk_integer_eq(_x10233,_x10234,kk_context());
}

bool kk_std_time_date__lp__lt__2_rp_(kk_std_time_date__weekday i, kk_std_time_date__weekday j, kk_context_t* _ctx) { /* (i : weekday, j : weekday) -> bool */ 
  kk_std_core_types__order x_9748 = kk_std_time_date_compare_2(i, j, _ctx); /*order*/;
  kk_integer_t _x10237 = kk_std_core_int_5(x_9748, _ctx); /*int*/
  kk_integer_t _x10238;
  kk_std_core_types__order _x10239 = kk_std_core_types__new_Lt(_ctx); /*order*/
  if (kk_std_core_types__is_Lt(_x10239)) {
    _x10238 = kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context()); /*int*/
    goto _match10240;
  }
  if (kk_std_core_types__is_Eq(_x10239)) {
    _x10238 = kk_integer_from_small(0); /*int*/
    goto _match10240;
  }
  _x10238 = kk_integer_from_small(1); /*int*/
  _match10240: ;
  return kk_integer_eq(_x10237,_x10238,kk_context());
}

bool kk_std_time_date__lp__lt__eq__rp_(kk_std_time_date__date i, kk_std_time_date__date j, kk_context_t* _ctx) { /* (i : date, j : date) -> bool */ 
  kk_std_core_types__order x_9750 = kk_std_time_date_compare(i, j, _ctx); /*order*/;
  kk_integer_t _x10241 = kk_std_core_int_5(x_9750, _ctx); /*int*/
  kk_integer_t _x10242;
  kk_std_core_types__order _x10243 = kk_std_core_types__new_Gt(_ctx); /*order*/
  if (kk_std_core_types__is_Lt(_x10243)) {
    _x10242 = kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context()); /*int*/
    goto _match10244;
  }
  if (kk_std_core_types__is_Eq(_x10243)) {
    _x10242 = kk_integer_from_small(0); /*int*/
    goto _match10244;
  }
  _x10242 = kk_integer_from_small(1); /*int*/
  _match10244: ;
  return kk_integer_neq(_x10241,_x10242,kk_context());
}

bool kk_std_time_date__lp__lt__eq__1_rp_(kk_std_time_date__clock i, kk_std_time_date__clock j, kk_context_t* _ctx) { /* (i : clock, j : clock) -> bool */ 
  kk_std_core_types__order x_9752 = kk_std_time_date_compare_1(i, j, _ctx); /*order*/;
  kk_integer_t _x10245 = kk_std_core_int_5(x_9752, _ctx); /*int*/
  kk_integer_t _x10246;
  kk_std_core_types__order _x10247 = kk_std_core_types__new_Gt(_ctx); /*order*/
  if (kk_std_core_types__is_Lt(_x10247)) {
    _x10246 = kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context()); /*int*/
    goto _match10248;
  }
  if (kk_std_core_types__is_Eq(_x10247)) {
    _x10246 = kk_integer_from_small(0); /*int*/
    goto _match10248;
  }
  _x10246 = kk_integer_from_small(1); /*int*/
  _match10248: ;
  return kk_integer_neq(_x10245,_x10246,kk_context());
}

bool kk_std_time_date__lp__lt__eq__2_rp_(kk_std_time_date__weekday i, kk_std_time_date__weekday j, kk_context_t* _ctx) { /* (i : weekday, j : weekday) -> bool */ 
  kk_std_core_types__order x_9754 = kk_std_time_date_compare_2(i, j, _ctx); /*order*/;
  kk_integer_t _x10249 = kk_std_core_int_5(x_9754, _ctx); /*int*/
  kk_integer_t _x10250;
  kk_std_core_types__order _x10251 = kk_std_core_types__new_Gt(_ctx); /*order*/
  if (kk_std_core_types__is_Lt(_x10251)) {
    _x10250 = kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context()); /*int*/
    goto _match10252;
  }
  if (kk_std_core_types__is_Eq(_x10251)) {
    _x10250 = kk_integer_from_small(0); /*int*/
    goto _match10252;
  }
  _x10250 = kk_integer_from_small(1); /*int*/
  _match10252: ;
  return kk_integer_neq(_x10249,_x10250,kk_context());
}

bool kk_std_time_date__lp__gt__rp_(kk_std_time_date__date i, kk_std_time_date__date j, kk_context_t* _ctx) { /* (i : date, j : date) -> bool */ 
  kk_std_core_types__order x_9756 = kk_std_time_date_compare(i, j, _ctx); /*order*/;
  kk_integer_t _x10253 = kk_std_core_int_5(x_9756, _ctx); /*int*/
  kk_integer_t _x10254;
  kk_std_core_types__order _x10255 = kk_std_core_types__new_Gt(_ctx); /*order*/
  if (kk_std_core_types__is_Lt(_x10255)) {
    _x10254 = kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context()); /*int*/
    goto _match10256;
  }
  if (kk_std_core_types__is_Eq(_x10255)) {
    _x10254 = kk_integer_from_small(0); /*int*/
    goto _match10256;
  }
  _x10254 = kk_integer_from_small(1); /*int*/
  _match10256: ;
  return kk_integer_eq(_x10253,_x10254,kk_context());
}

bool kk_std_time_date__lp__gt__1_rp_(kk_std_time_date__clock i, kk_std_time_date__clock j, kk_context_t* _ctx) { /* (i : clock, j : clock) -> bool */ 
  kk_std_core_types__order x_9758 = kk_std_time_date_compare_1(i, j, _ctx); /*order*/;
  kk_integer_t _x10257 = kk_std_core_int_5(x_9758, _ctx); /*int*/
  kk_integer_t _x10258;
  kk_std_core_types__order _x10259 = kk_std_core_types__new_Gt(_ctx); /*order*/
  if (kk_std_core_types__is_Lt(_x10259)) {
    _x10258 = kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context()); /*int*/
    goto _match10260;
  }
  if (kk_std_core_types__is_Eq(_x10259)) {
    _x10258 = kk_integer_from_small(0); /*int*/
    goto _match10260;
  }
  _x10258 = kk_integer_from_small(1); /*int*/
  _match10260: ;
  return kk_integer_eq(_x10257,_x10258,kk_context());
}

bool kk_std_time_date__lp__gt__2_rp_(kk_std_time_date__weekday i, kk_std_time_date__weekday j, kk_context_t* _ctx) { /* (i : weekday, j : weekday) -> bool */ 
  kk_std_core_types__order x_9760 = kk_std_time_date_compare_2(i, j, _ctx); /*order*/;
  kk_integer_t _x10261 = kk_std_core_int_5(x_9760, _ctx); /*int*/
  kk_integer_t _x10262;
  kk_std_core_types__order _x10263 = kk_std_core_types__new_Gt(_ctx); /*order*/
  if (kk_std_core_types__is_Lt(_x10263)) {
    _x10262 = kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context()); /*int*/
    goto _match10264;
  }
  if (kk_std_core_types__is_Eq(_x10263)) {
    _x10262 = kk_integer_from_small(0); /*int*/
    goto _match10264;
  }
  _x10262 = kk_integer_from_small(1); /*int*/
  _match10264: ;
  return kk_integer_eq(_x10261,_x10262,kk_context());
}

bool kk_std_time_date__lp__gt__eq__rp_(kk_std_time_date__date i, kk_std_time_date__date j, kk_context_t* _ctx) { /* (i : date, j : date) -> bool */ 
  kk_std_core_types__order x_9762 = kk_std_time_date_compare(i, j, _ctx); /*order*/;
  kk_integer_t _x10265 = kk_std_core_int_5(x_9762, _ctx); /*int*/
  kk_integer_t _x10266;
  kk_std_core_types__order _x10267 = kk_std_core_types__new_Lt(_ctx); /*order*/
  if (kk_std_core_types__is_Lt(_x10267)) {
    _x10266 = kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context()); /*int*/
    goto _match10268;
  }
  if (kk_std_core_types__is_Eq(_x10267)) {
    _x10266 = kk_integer_from_small(0); /*int*/
    goto _match10268;
  }
  _x10266 = kk_integer_from_small(1); /*int*/
  _match10268: ;
  return kk_integer_neq(_x10265,_x10266,kk_context());
}

bool kk_std_time_date__lp__gt__eq__1_rp_(kk_std_time_date__clock i, kk_std_time_date__clock j, kk_context_t* _ctx) { /* (i : clock, j : clock) -> bool */ 
  kk_std_core_types__order x_9764 = kk_std_time_date_compare_1(i, j, _ctx); /*order*/;
  kk_integer_t _x10269 = kk_std_core_int_5(x_9764, _ctx); /*int*/
  kk_integer_t _x10270;
  kk_std_core_types__order _x10271 = kk_std_core_types__new_Lt(_ctx); /*order*/
  if (kk_std_core_types__is_Lt(_x10271)) {
    _x10270 = kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context()); /*int*/
    goto _match10272;
  }
  if (kk_std_core_types__is_Eq(_x10271)) {
    _x10270 = kk_integer_from_small(0); /*int*/
    goto _match10272;
  }
  _x10270 = kk_integer_from_small(1); /*int*/
  _match10272: ;
  return kk_integer_neq(_x10269,_x10270,kk_context());
}

bool kk_std_time_date__lp__gt__eq__2_rp_(kk_std_time_date__weekday i, kk_std_time_date__weekday j, kk_context_t* _ctx) { /* (i : weekday, j : weekday) -> bool */ 
  kk_std_core_types__order x_9766 = kk_std_time_date_compare_2(i, j, _ctx); /*order*/;
  kk_integer_t _x10273 = kk_std_core_int_5(x_9766, _ctx); /*int*/
  kk_integer_t _x10274;
  kk_std_core_types__order _x10275 = kk_std_core_types__new_Lt(_ctx); /*order*/
  if (kk_std_core_types__is_Lt(_x10275)) {
    _x10274 = kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context()); /*int*/
    goto _match10276;
  }
  if (kk_std_core_types__is_Eq(_x10275)) {
    _x10274 = kk_integer_from_small(0); /*int*/
    goto _match10276;
  }
  _x10274 = kk_integer_from_small(1); /*int*/
  _match10276: ;
  return kk_integer_neq(_x10273,_x10274,kk_context());
}
 
// The zero clock

kk_std_time_date__clock kk_std_time_date_clock0;
 
// Return the ISO calendar date of Easter in a given year (Algorithm by [J.M. Oudin](http://aa.usno.navy.mil/faq/docs/easter.php)).

kk_std_time_date__date kk_std_time_date_easter(kk_integer_t year0, kk_context_t* _ctx) { /* (year : int) -> date */ 
  kk_integer_t c;
  kk_integer_t _x10278 = kk_integer_dup(year0); /*int*/
  c = kk_integer_div(_x10278,(kk_integer_from_small(100)),kk_context()); /*int*/
  kk_integer_t n;
  kk_integer_t _x10279 = kk_integer_dup(year0); /*int*/
  kk_integer_t _x10280;
  kk_integer_t _x10281;
  kk_integer_t _x10282 = kk_integer_dup(year0); /*int*/
  _x10281 = kk_integer_div(_x10282,(kk_integer_from_small(19)),kk_context()); /*int*/
  _x10280 = kk_integer_mul((kk_integer_from_small(19)),_x10281,kk_context()); /*int*/
  n = kk_integer_sub(_x10279,_x10280,kk_context()); /*int*/
  kk_integer_t k;
  kk_integer_t _x10283;
  kk_integer_t _x10284 = kk_integer_dup(c); /*int*/
  _x10283 = kk_integer_sub(_x10284,(kk_integer_from_small(17)),kk_context()); /*int*/
  k = kk_integer_div(_x10283,(kk_integer_from_small(25)),kk_context()); /*int*/
  kk_integer_t i0;
  kk_integer_t _x10285;
  kk_integer_t _x10286;
  kk_integer_t _x10287;
  kk_integer_t _x10288 = kk_integer_dup(c); /*int*/
  kk_integer_t _x10289;
  kk_integer_t _x10290 = kk_integer_dup(c); /*int*/
  _x10289 = kk_integer_div(_x10290,(kk_integer_from_small(4)),kk_context()); /*int*/
  _x10287 = kk_integer_sub(_x10288,_x10289,kk_context()); /*int*/
  kk_integer_t _x10291;
  kk_integer_t _x10292;
  kk_integer_t _x10293 = kk_integer_dup(c); /*int*/
  _x10292 = kk_integer_sub(_x10293,k,kk_context()); /*int*/
  _x10291 = kk_integer_div(_x10292,(kk_integer_from_small(3)),kk_context()); /*int*/
  _x10286 = kk_integer_sub(_x10287,_x10291,kk_context()); /*int*/
  kk_integer_t _x10294;
  kk_integer_t _x10295 = kk_integer_dup(n); /*int*/
  _x10294 = kk_integer_mul((kk_integer_from_small(19)),_x10295,kk_context()); /*int*/
  _x10285 = kk_integer_add(_x10286,_x10294,kk_context()); /*int*/
  i0 = kk_integer_add(_x10285,(kk_integer_from_small(15)),kk_context()); /*int*/
  kk_integer_t i1;
  kk_integer_t _x10296 = kk_integer_dup(i0); /*int*/
  kk_integer_t _x10297;
  kk_integer_t _x10298 = kk_integer_div(i0,(kk_integer_from_small(30)),kk_context()); /*int*/
  _x10297 = kk_integer_mul((kk_integer_from_small(30)),_x10298,kk_context()); /*int*/
  i1 = kk_integer_sub(_x10296,_x10297,kk_context()); /*int*/
  kk_integer_t i;
  kk_integer_t _x10299 = kk_integer_dup(i1); /*int*/
  kk_integer_t _x10300;
  kk_integer_t _x10301;
  kk_integer_t _x10302 = kk_integer_dup(i1); /*int*/
  _x10301 = kk_integer_div(_x10302,(kk_integer_from_small(28)),kk_context()); /*int*/
  kk_integer_t _x10303;
  kk_integer_t _x10304;
  kk_integer_t _x10305;
  kk_integer_t _x10306;
  kk_integer_t _x10307 = kk_integer_dup(i1); /*int*/
  _x10306 = kk_integer_div(_x10307,(kk_integer_from_small(28)),kk_context()); /*int*/
  kk_integer_t _x10308;
  kk_integer_t _x10309 = kk_integer_add(i1,(kk_integer_from_small(1)),kk_context()); /*int*/
  _x10308 = kk_integer_div((kk_integer_from_small(29)),_x10309,kk_context()); /*int*/
  _x10305 = kk_integer_mul(_x10306,_x10308,kk_context()); /*int*/
  kk_integer_t _x10310;
  kk_integer_t _x10311 = kk_integer_sub((kk_integer_from_small(21)),n,kk_context()); /*int*/
  _x10310 = kk_integer_div(_x10311,(kk_integer_from_small(11)),kk_context()); /*int*/
  _x10304 = kk_integer_mul(_x10305,_x10310,kk_context()); /*int*/
  _x10303 = kk_integer_sub((kk_integer_from_small(1)),_x10304,kk_context()); /*int*/
  _x10300 = kk_integer_mul(_x10301,_x10303,kk_context()); /*int*/
  i = kk_integer_sub(_x10299,_x10300,kk_context()); /*int*/
  kk_integer_t j0;
  kk_integer_t _x10312;
  kk_integer_t _x10313;
  kk_integer_t _x10314;
  kk_integer_t _x10315;
  kk_integer_t _x10316 = kk_integer_dup(year0); /*int*/
  kk_integer_t _x10317;
  kk_integer_t _x10318 = kk_integer_dup(year0); /*int*/
  _x10317 = kk_integer_div(_x10318,(kk_integer_from_small(4)),kk_context()); /*int*/
  _x10315 = kk_integer_add(_x10316,_x10317,kk_context()); /*int*/
  kk_integer_t _x10319 = kk_integer_dup(i); /*int*/
  _x10314 = kk_integer_add(_x10315,_x10319,kk_context()); /*int*/
  _x10313 = kk_integer_add(_x10314,(kk_integer_from_small(2)),kk_context()); /*int*/
  kk_integer_t _x10320 = kk_integer_dup(c); /*int*/
  _x10312 = kk_integer_sub(_x10313,_x10320,kk_context()); /*int*/
  kk_integer_t _x10321 = kk_integer_div(c,(kk_integer_from_small(4)),kk_context()); /*int*/
  j0 = kk_integer_add(_x10312,_x10321,kk_context()); /*int*/
  kk_integer_t j;
  kk_integer_t _x10322 = kk_integer_dup(j0); /*int*/
  kk_integer_t _x10323;
  kk_integer_t _x10324 = kk_integer_div(j0,(kk_integer_from_small(7)),kk_context()); /*int*/
  _x10323 = kk_integer_mul((kk_integer_from_small(7)),_x10324,kk_context()); /*int*/
  j = kk_integer_sub(_x10322,_x10323,kk_context()); /*int*/
  kk_integer_t l = kk_integer_sub(i,j,kk_context()); /*int*/;
  kk_integer_t m;
  kk_integer_t _x10325;
  kk_integer_t _x10326;
  kk_integer_t _x10327 = kk_integer_dup(l); /*int*/
  _x10326 = kk_integer_add(_x10327,(kk_integer_from_small(40)),kk_context()); /*int*/
  _x10325 = kk_integer_div(_x10326,(kk_integer_from_small(44)),kk_context()); /*int*/
  m = kk_integer_add((kk_integer_from_small(3)),_x10325,kk_context()); /*int*/
  kk_integer_t d;
  kk_integer_t _x10328 = kk_integer_add(l,(kk_integer_from_small(28)),kk_context()); /*int*/
  kk_integer_t _x10329;
  kk_integer_t _x10330;
  kk_integer_t _x10331 = kk_integer_dup(m); /*int*/
  _x10330 = kk_integer_div(_x10331,(kk_integer_from_small(4)),kk_context()); /*int*/
  _x10329 = kk_integer_mul((kk_integer_from_small(31)),_x10330,kk_context()); /*int*/
  d = kk_integer_sub(_x10328,_x10329,kk_context()); /*int*/
  return kk_std_time_date__new_Date(year0, m, d, _ctx);
}
 
// Is this a zero clock?

bool kk_std_time_date_is_zero(kk_std_time_date__clock c, kk_context_t* _ctx) { /* (c : clock) -> bool */ 
  bool _match_10015;
  kk_integer_t _x10332;
  struct kk_std_time_date_Clock* _con10333 = kk_std_time_date__as_Clock(c);
  kk_integer_t _x = _con10333->hours;
  kk_std_num_ddouble__ddouble _pat1 = _con10333->seconds;
  kk_integer_dup(_x);
  _x10332 = _x; /*int*/
  _match_10015 = kk_integer_is_zero(_x10332,kk_context()); /*bool*/
  if (_match_10015) {
    bool _match_10016;
    kk_integer_t _x10334;
    struct kk_std_time_date_Clock* _con10335 = kk_std_time_date__as_Clock(c);
    kk_integer_t _x0 = _con10335->minutes;
    kk_std_num_ddouble__ddouble _pat10 = _con10335->seconds;
    kk_integer_dup(_x0);
    _x10334 = _x0; /*int*/
    _match_10016 = kk_integer_is_zero(_x10334,kk_context()); /*bool*/
    if (_match_10016) {
      double _x10336;
      kk_std_num_ddouble__ddouble _match_10017;
      struct kk_std_time_date_Clock* _con10337 = kk_std_time_date__as_Clock(c);
      kk_integer_t _pat03 = _con10337->hours;
      kk_integer_t _pat11 = _con10337->minutes;
      kk_std_num_ddouble__ddouble _x2 = _con10337->seconds;
      if (kk_std_time_date__clock_is_unique(c)) {
        kk_integer_drop(_pat11, _ctx);
        kk_integer_drop(_pat03, _ctx);
        kk_std_time_date__clock_free(c);
      }
      else {
        kk_std_time_date__clock_decref(c, _ctx);
      }
      _match_10017 = _x2; /*std/num/ddouble/ddouble*/
      double _x1 = _match_10017.hi;
      _x10336 = _x1; /*double*/
      return (_x10336 == (0x0p+0));
    }
    kk_std_time_date__clock_dropn(c, ((int32_t)2), _ctx);
    return false;
  }
  kk_std_time_date__clock_dropn(c, ((int32_t)2), _ctx);
  return false;
}
 
// Return the fraction of the seconds as milli-seconds (10^-3^).

kk_integer_t kk_std_time_date_milli_seconds(kk_std_time_date__clock c, kk_context_t* _ctx) { /* (c : clock) -> int */ 
  double _x10338;
  double d_9772;
  double _x10339;
  kk_std_num_ddouble__ddouble x_9773;
  kk_std_num_ddouble__ddouble y_21009;
  kk_std_num_ddouble__ddouble _x10340;
  struct kk_std_time_date_Clock* _con10341 = kk_std_time_date__as_Clock(c);
  kk_std_num_ddouble__ddouble _x0 = _con10341->seconds;
  _x10340 = _x0; /*std/num/ddouble/ddouble*/
  y_21009 = kk_std_num_ddouble_truncate(_x10340, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x10342;
  struct kk_std_time_date_Clock* _con10343 = kk_std_time_date__as_Clock(c);
  kk_integer_t _pat010 = _con10343->hours;
  kk_integer_t _pat100 = _con10343->minutes;
  kk_std_num_ddouble__ddouble _x00 = _con10343->seconds;
  if (kk_std_time_date__clock_is_unique(c)) {
    kk_integer_drop(_pat100, _ctx);
    kk_integer_drop(_pat010, _ctx);
    kk_std_time_date__clock_free(c);
  }
  else {
    kk_std_time_date__clock_decref(c, _ctx);
  }
  _x10342 = _x00; /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x10344 = kk_std_num_ddouble__lp__tilde__rp_(y_21009, _ctx); /*std/num/ddouble/ddouble*/
  x_9773 = kk_std_num_ddouble__lp__plus__rp_(_x10342, _x10344, _ctx); /*std/num/ddouble/ddouble*/
  double _x = x_9773.hi;
  _x10339 = _x; /*double*/
  d_9772 = (_x10339 * (0x1.f4p9)); /*double*/
  bool _match_10014 = (d_9772 >= (0x0p+0)); /*bool*/;
  if (_match_10014) {
    _x10338 = floor(d_9772); /*double*/
  }
  else {
    _x10338 = ceil(d_9772); /*double*/
  }
  return kk_integer_from_double(_x10338,kk_context());
}
 
// Return the fraction of seconds as nano-seconds ((10^-9^).

kk_integer_t kk_std_time_date_nano_seconds(kk_std_time_date__clock c, kk_context_t* _ctx) { /* (c : clock) -> int */ 
  double _x10345;
  double d_9776;
  double _x10346;
  kk_std_num_ddouble__ddouble x_9777;
  kk_std_num_ddouble__ddouble y_21009;
  kk_std_num_ddouble__ddouble _x10347;
  struct kk_std_time_date_Clock* _con10348 = kk_std_time_date__as_Clock(c);
  kk_std_num_ddouble__ddouble _x0 = _con10348->seconds;
  _x10347 = _x0; /*std/num/ddouble/ddouble*/
  y_21009 = kk_std_num_ddouble_truncate(_x10347, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x10349;
  struct kk_std_time_date_Clock* _con10350 = kk_std_time_date__as_Clock(c);
  kk_integer_t _pat010 = _con10350->hours;
  kk_integer_t _pat100 = _con10350->minutes;
  kk_std_num_ddouble__ddouble _x00 = _con10350->seconds;
  if (kk_std_time_date__clock_is_unique(c)) {
    kk_integer_drop(_pat100, _ctx);
    kk_integer_drop(_pat010, _ctx);
    kk_std_time_date__clock_free(c);
  }
  else {
    kk_std_time_date__clock_decref(c, _ctx);
  }
  _x10349 = _x00; /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x10351 = kk_std_num_ddouble__lp__tilde__rp_(y_21009, _ctx); /*std/num/ddouble/ddouble*/
  x_9777 = kk_std_num_ddouble__lp__plus__rp_(_x10349, _x10351, _ctx); /*std/num/ddouble/ddouble*/
  double _x = x_9777.hi;
  _x10346 = _x; /*double*/
  d_9776 = (_x10346 * (0x1.dcd65p29)); /*double*/
  bool _match_10013 = (d_9776 >= (0x0p+0)); /*bool*/;
  if (_match_10013) {
    _x10345 = floor(d_9776); /*double*/
  }
  else {
    _x10345 = ceil(d_9776); /*double*/
  }
  return kk_integer_from_double(_x10345,kk_context());
}
 
// Round a clock time to a certain number of digits precision (of the fraction of seconds) (default `9`, nano seconds).

kk_std_time_date__clock kk_std_time_date_round_to_prec(kk_std_time_date__clock c, kk_std_core_types__optional prec, kk_context_t* _ctx) { /* (c : clock, prec : optional<int>) -> clock */ 
  kk_integer_t _x10352;
  struct kk_std_time_date_Clock* _con10353 = kk_std_time_date__as_Clock(c);
  kk_integer_t _x = _con10353->hours;
  kk_std_num_ddouble__ddouble _pat1 = _con10353->seconds;
  kk_integer_dup(_x);
  _x10352 = _x; /*int*/
  kk_integer_t _x10354;
  struct kk_std_time_date_Clock* _con10355 = kk_std_time_date__as_Clock(c);
  kk_integer_t _x0 = _con10355->minutes;
  kk_std_num_ddouble__ddouble _pat10 = _con10355->seconds;
  kk_integer_dup(_x0);
  _x10354 = _x0; /*int*/
  kk_std_num_ddouble__ddouble _x10356;
  bool _match_10011;
  kk_integer_t _x10357;
  if (kk_std_core_types__is_Optional(prec)) {
    kk_box_t _box_x9884 = prec._cons.Optional.value;
    kk_integer_t _prec_8386 = kk_integer_unbox(_box_x9884);
    kk_integer_dup(_prec_8386);
    _x10357 = _prec_8386; /*int*/
    goto _match10358;
  }
  _x10357 = kk_integer_from_small(9); /*int*/
  _match10358: ;
  _match_10011 = kk_integer_lte(_x10357,(kk_integer_from_small(0)),kk_context()); /*bool*/
  if (_match_10011) {
    kk_std_core_types__optional_drop(prec, _ctx);
    kk_std_num_ddouble__ddouble _x10360;
    struct kk_std_time_date_Clock* _con10361 = kk_std_time_date__as_Clock(c);
    kk_integer_t _pat02 = _con10361->hours;
    kk_integer_t _pat12 = _con10361->minutes;
    kk_std_num_ddouble__ddouble _x1 = _con10361->seconds;
    if (kk_std_time_date__clock_is_unique(c)) {
      kk_integer_drop(_pat12, _ctx);
      kk_integer_drop(_pat02, _ctx);
      kk_std_time_date__clock_free(c);
    }
    else {
      kk_std_time_date__clock_decref(c, _ctx);
    }
    _x10360 = _x1; /*std/num/ddouble/ddouble*/
    _x10356 = kk_std_num_ddouble_round(_x10360, _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    bool _match_10012;
    kk_integer_t _x10362;
    if (kk_std_core_types__is_Optional(prec)) {
      kk_box_t _box_x9885 = prec._cons.Optional.value;
      kk_integer_t _prec_83860 = kk_integer_unbox(_box_x9885);
      kk_integer_dup(_prec_83860);
      _x10362 = _prec_83860; /*int*/
      goto _match10363;
    }
    _x10362 = kk_integer_from_small(9); /*int*/
    _match10363: ;
    _match_10012 = kk_integer_gt(_x10362,(kk_integer_from_small(31)),kk_context()); /*bool*/
    if (_match_10012) {
      kk_std_core_types__optional_drop(prec, _ctx);
      struct kk_std_time_date_Clock* _con10365 = kk_std_time_date__as_Clock(c);
      kk_integer_t _pat020 = _con10365->hours;
      kk_integer_t _pat120 = _con10365->minutes;
      kk_std_num_ddouble__ddouble _x10 = _con10365->seconds;
      if (kk_std_time_date__clock_is_unique(c)) {
        kk_integer_drop(_pat120, _ctx);
        kk_integer_drop(_pat020, _ctx);
        kk_std_time_date__clock_free(c);
      }
      else {
        kk_std_time_date__clock_decref(c, _ctx);
      }
      _x10356 = _x10; /*std/num/ddouble/ddouble*/
    }
    else {
      kk_std_num_ddouble__ddouble p;
      kk_integer_t _x10366;
      if (kk_std_core_types__is_Optional(prec)) {
        kk_box_t _box_x9886 = prec._cons.Optional.value;
        kk_integer_t _prec_83861 = kk_integer_unbox(_box_x9886);
        kk_integer_dup(_prec_83861);
        kk_std_core_types__optional_drop(prec, _ctx);
        _x10366 = _prec_83861; /*int*/
        goto _match10367;
      }
      _x10366 = kk_integer_from_small(9); /*int*/
      _match10367: ;
      p = kk_std_num_ddouble_powi10(_x10366, _ctx); /*std/num/ddouble/ddouble*/
      kk_std_num_ddouble__ddouble _x10369;
      kk_std_num_ddouble__ddouble _x10370;
      kk_std_num_ddouble__ddouble _x10371;
      struct kk_std_time_date_Clock* _con10372 = kk_std_time_date__as_Clock(c);
      kk_integer_t _pat021 = _con10372->hours;
      kk_integer_t _pat121 = _con10372->minutes;
      kk_std_num_ddouble__ddouble _x11 = _con10372->seconds;
      if (kk_std_time_date__clock_is_unique(c)) {
        kk_integer_drop(_pat121, _ctx);
        kk_integer_drop(_pat021, _ctx);
        kk_std_time_date__clock_free(c);
      }
      else {
        kk_std_time_date__clock_decref(c, _ctx);
      }
      _x10371 = _x11; /*std/num/ddouble/ddouble*/
      _x10370 = kk_std_num_ddouble__lp__star__rp_(_x10371, p, _ctx); /*std/num/ddouble/ddouble*/
      _x10369 = kk_std_num_ddouble_round(_x10370, _ctx); /*std/num/ddouble/ddouble*/
      _x10356 = kk_std_num_ddouble__lp__fs__rp_(_x10369, p, _ctx); /*std/num/ddouble/ddouble*/
    }
  }
  return kk_std_time_date__new_Clock(kk_reuse_null, _x10352, _x10354, _x10356, _ctx);
}
 
// Show seconds

kk_string_t kk_std_time_date_show_seconds(kk_std_num_ddouble__ddouble secs, kk_std_core_types__optional max_prec, kk_std_core_types__optional secs_width, kk_std_core_types__optional unit, kk_context_t* _ctx) { /* (secs : std/num/ddouble/ddouble, max-prec : optional<int>, secs-width : optional<int>, unit : optional<string>) -> string */ 
  kk_string_t s;
  kk_std_core_types__optional _x10373;
  kk_integer_t _b_9889_9888;
  kk_integer_t _x10374;
  kk_integer_t _x10375;
  if (kk_std_core_types__is_Optional(max_prec)) {
    kk_box_t _box_x9887 = max_prec._cons.Optional.value;
    kk_integer_t _max_prec_8428 = kk_integer_unbox(_box_x9887);
    kk_integer_dup(_max_prec_8428);
    kk_std_core_types__optional_drop(max_prec, _ctx);
    _x10375 = _max_prec_8428; /*int*/
    goto _match10376;
  }
  _x10375 = kk_integer_from_small(9); /*int*/
  _match10376: ;
  _x10374 = kk_integer_abs(_x10375,kk_context()); /*int*/
  _b_9889_9888 = kk_integer_neg(_x10374,kk_context()); /*int*/
  _x10373 = kk_std_core_types__new_Optional(kk_integer_box(_b_9889_9888), _ctx); /*optional<35>*/
  s = kk_std_num_ddouble_show_fixed(secs, _x10373, _ctx); /*string*/
  kk_std_core_types__maybe _match_10006;
  size_t i;
  kk_string_t _x10378 = kk_string_dup(s); /*string*/
  kk_string_t _x10379;
  kk_define_string_literal(, _s10380, 1, ".")
  _x10379 = kk_string_dup(_s10380); /*string*/
  i = kk_string_index_of1(_x10378,_x10379,kk_context()); /*size_t*/
  bool _match_10010 = kk_std_core_is_zero_1(i, _ctx); /*bool*/;
  if (_match_10010) {
    _match_10006 = kk_std_core_types__new_Nothing(_ctx); /*forall<a> maybe<a>*/
  }
  else {
    kk_std_core__sslice _b_9904_9890;
    kk_string_t _x10381 = kk_string_dup(s); /*string*/
    size_t _x10382 = kk_std_core_decr_1(i, _ctx); /*size_t*/
    size_t _x10383;
    kk_string_t _x10384;
    kk_define_string_literal(, _s10385, 1, ".")
    _x10384 = kk_string_dup(_s10385); /*string*/
    _x10383 = kk_string_len(_x10384,kk_context()); /*size_t*/
    _b_9904_9890 = kk_std_core__new_Sslice(_x10381, _x10382, _x10383, _ctx); /*sslice*/
    _match_10006 = kk_std_core_types__new_Just(kk_std_core__sslice_box(_b_9904_9890, _ctx), _ctx); /*forall<a> maybe<a>*/
  }
  if (kk_std_core_types__is_Nothing(_match_10006)) {
    kk_std_core_types__optional_drop(unit, _ctx);
    kk_std_core_types__optional fill_9789 = kk_std_core_types__new_Optional(kk_char_box('0', _ctx), _ctx); /*optional<char>*/;
    size_t w;
    kk_integer_t _x10386;
    if (kk_std_core_types__is_Optional(secs_width)) {
      kk_box_t _box_x9893 = secs_width._cons.Optional.value;
      kk_integer_t _secs_width_8432 = kk_integer_unbox(_box_x9893);
      kk_integer_dup(_secs_width_8432);
      kk_std_core_types__optional_drop(secs_width, _ctx);
      _x10386 = _secs_width_8432; /*int*/
      goto _match10387;
    }
    _x10386 = kk_integer_from_small(1); /*int*/
    _match10387: ;
    w = kk_std_core_size__t(_x10386, _ctx); /*size_t*/
    size_t n;
    kk_string_t _x10389 = kk_string_dup(s); /*string*/
    n = kk_string_len(_x10389,kk_context()); /*size_t*/
    bool _match_10009 = (w <= n); /*bool*/;
    if (_match_10009) {
      kk_std_core_types__optional_drop(fill_9789, _ctx);
      return s;
    }
    kk_string_t _x10390;
    kk_string_t _x10391;
    kk_char_t _x10392;
    if (kk_std_core_types__is_Optional(fill_9789)) {
      kk_box_t _box_x9894 = fill_9789._cons.Optional.value;
      kk_char_t _fill_8417 = kk_char_unbox(_box_x9894, NULL);
      kk_std_core_types__optional_drop(fill_9789, _ctx);
      _x10392 = _fill_8417; /*char*/
      goto _match10393;
    }
    _x10392 = ' '; /*char*/
    _match10393: ;
    _x10391 = kk_std_core_string(_x10392, _ctx); /*string*/
    size_t _x10395 = (w - n); /*size_t*/
    _x10390 = kk_std_core_repeatz(_x10391, _x10395, _ctx); /*string*/
    return kk_std_core__lp__plus__plus__1_rp_(_x10390, s, _ctx);
  }
  kk_box_t _box_x9895 = _match_10006._cons.Just.value;
  kk_std_core__sslice dot = kk_std_core__sslice_unbox(_box_x9895, NULL);
  kk_string_drop(s, _ctx);
  kk_std_core__sslice_dup(dot);
  kk_std_core_types__maybe_drop(_match_10006, _ctx);
  kk_string_t f;
  kk_std_core__sslice _x10397;
  kk_std_core__sslice _x10398 = kk_std_core__sslice_dup(dot); /*sslice*/
  _x10397 = kk_std_core_after(_x10398, _ctx); /*sslice*/
  f = kk_std_core_string_3(_x10397, _ctx); /*string*/
  kk_integer_t len3;
  kk_integer_t _x10399;
  kk_integer_t _x10400;
  kk_integer_t _x10401;
  kk_string_t _x10402 = kk_string_dup(f); /*string*/
  _x10401 = kk_std_core_count_1(_x10402, _ctx); /*int*/
  _x10400 = kk_integer_add(_x10401,(kk_integer_from_small(2)),kk_context()); /*int*/
  _x10399 = kk_integer_div(_x10400,(kk_integer_from_small(3)),kk_context()); /*int*/
  len3 = kk_integer_mul(_x10399,(kk_integer_from_small(3)),kk_context()); /*int*/
  kk_string_t _x10403;
  kk_string_t s2_9790;
  kk_std_core__sslice _x10404 = kk_std_core_before(dot, _ctx); /*sslice*/
  s2_9790 = kk_std_core_string_3(_x10404, _ctx); /*string*/
  kk_std_core_types__optional fill0_9792 = kk_std_core_types__new_Optional(kk_char_box('0', _ctx), _ctx); /*optional<char>*/;
  size_t w0;
  kk_integer_t _x10405;
  if (kk_std_core_types__is_Optional(secs_width)) {
    kk_box_t _box_x9898 = secs_width._cons.Optional.value;
    kk_integer_t _secs_width_84320 = kk_integer_unbox(_box_x9898);
    kk_integer_dup(_secs_width_84320);
    kk_std_core_types__optional_drop(secs_width, _ctx);
    _x10405 = _secs_width_84320; /*int*/
    goto _match10406;
  }
  _x10405 = kk_integer_from_small(1); /*int*/
  _match10406: ;
  w0 = kk_std_core_size__t(_x10405, _ctx); /*size_t*/
  size_t n0;
  kk_string_t _x10408 = kk_string_dup(s2_9790); /*string*/
  n0 = kk_string_len(_x10408,kk_context()); /*size_t*/
  bool _match_10008 = (w0 <= n0); /*bool*/;
  if (_match_10008) {
    kk_std_core_types__optional_drop(fill0_9792, _ctx);
    _x10403 = s2_9790; /*string*/
  }
  else {
    kk_string_t _x10409;
    kk_string_t _x10410;
    kk_char_t _x10411;
    if (kk_std_core_types__is_Optional(fill0_9792)) {
      kk_box_t _box_x9899 = fill0_9792._cons.Optional.value;
      kk_char_t _fill_84170 = kk_char_unbox(_box_x9899, NULL);
      kk_std_core_types__optional_drop(fill0_9792, _ctx);
      _x10411 = _fill_84170; /*char*/
      goto _match10412;
    }
    _x10411 = ' '; /*char*/
    _match10412: ;
    _x10410 = kk_std_core_string(_x10411, _ctx); /*string*/
    size_t _x10414 = (w0 - n0); /*size_t*/
    _x10409 = kk_std_core_repeatz(_x10410, _x10414, _ctx); /*string*/
    _x10403 = kk_std_core__lp__plus__plus__1_rp_(_x10409, s2_9790, _ctx); /*string*/
  }
  kk_string_t _x10415;
  kk_string_t _x10416;
  kk_define_string_literal(, _s10417, 1, ".")
  _x10416 = kk_string_dup(_s10417); /*string*/
  kk_string_t _x10418;
  kk_string_t _x10419;
  kk_std_core_types__optional fill1_9795 = kk_std_core_types__new_Optional(kk_char_box('0', _ctx), _ctx); /*optional<char>*/;
  size_t w1 = kk_std_core_size__t(len3, _ctx); /*size_t*/;
  size_t n1;
  kk_string_t _x10420 = kk_string_dup(f); /*string*/
  n1 = kk_string_len(_x10420,kk_context()); /*size_t*/
  bool _match_10007 = (w1 <= n1); /*bool*/;
  if (_match_10007) {
    kk_std_core_types__optional_drop(fill1_9795, _ctx);
    _x10419 = f; /*string*/
  }
  else {
    kk_string_t _x10421;
    kk_string_t _x10422;
    kk_char_t _x10423;
    if (kk_std_core_types__is_Optional(fill1_9795)) {
      kk_box_t _box_x9902 = fill1_9795._cons.Optional.value;
      kk_char_t _fill_18968 = kk_char_unbox(_box_x9902, NULL);
      kk_std_core_types__optional_drop(fill1_9795, _ctx);
      _x10423 = _fill_18968; /*char*/
      goto _match10424;
    }
    _x10423 = ' '; /*char*/
    _match10424: ;
    _x10422 = kk_std_core_string(_x10423, _ctx); /*string*/
    size_t _x10426 = (w1 - n1); /*size_t*/
    _x10421 = kk_std_core_repeatz(_x10422, _x10426, _ctx); /*string*/
    _x10419 = kk_std_core__lp__plus__plus__1_rp_(f, _x10421, _ctx); /*string*/
  }
  kk_string_t _x10427;
  if (kk_std_core_types__is_Optional(unit)) {
    kk_box_t _box_x9903 = unit._cons.Optional.value;
    kk_string_t _unit_8436 = kk_string_unbox(_box_x9903);
    kk_string_dup(_unit_8436);
    kk_std_core_types__optional_drop(unit, _ctx);
    _x10427 = _unit_8436; /*string*/
    goto _match10428;
  }
  _x10427 = kk_string_empty(); /*string*/
  _match10428: ;
  _x10418 = kk_std_core__lp__plus__plus__1_rp_(_x10419, _x10427, _ctx); /*string*/
  _x10415 = kk_std_core__lp__plus__plus__1_rp_(_x10416, _x10418, _ctx); /*string*/
  return kk_std_core__lp__plus__plus__1_rp_(_x10403, _x10415, _ctx);
}
 
// pad with zeros

kk_string_t kk_std_time_date_show0(kk_integer_t i, kk_std_core_types__optional width, kk_context_t* _ctx) { /* (i : int, width : optional<int>) -> string */ 
  kk_string_t s_9796 = kk_std_core_show(i, _ctx); /*string*/;
  kk_std_core_types__optional fill_9798 = kk_std_core_types__new_Optional(kk_char_box('0', _ctx), _ctx); /*optional<char>*/;
  size_t w;
  kk_integer_t _x10431;
  if (kk_std_core_types__is_Optional(width)) {
    kk_box_t _box_x9907 = width._cons.Optional.value;
    kk_integer_t _width_9238 = kk_integer_unbox(_box_x9907);
    kk_integer_dup(_width_9238);
    kk_std_core_types__optional_drop(width, _ctx);
    _x10431 = _width_9238; /*int*/
    goto _match10432;
  }
  _x10431 = kk_integer_from_small(2); /*int*/
  _match10432: ;
  w = kk_std_core_size__t(_x10431, _ctx); /*size_t*/
  size_t n;
  kk_string_t _x10434 = kk_string_dup(s_9796); /*string*/
  n = kk_string_len(_x10434,kk_context()); /*size_t*/
  bool _match_10005 = (w <= n); /*bool*/;
  if (_match_10005) {
    kk_std_core_types__optional_drop(fill_9798, _ctx);
    return s_9796;
  }
  kk_string_t _x10435;
  kk_string_t _x10436;
  kk_char_t _x10437;
  if (kk_std_core_types__is_Optional(fill_9798)) {
    kk_box_t _box_x9908 = fill_9798._cons.Optional.value;
    kk_char_t _fill_8417 = kk_char_unbox(_box_x9908, NULL);
    kk_std_core_types__optional_drop(fill_9798, _ctx);
    _x10437 = _fill_8417; /*char*/
    goto _match10438;
  }
  _x10437 = ' '; /*char*/
  _match10438: ;
  _x10436 = kk_std_core_string(_x10437, _ctx); /*string*/
  size_t _x10440 = (w - n); /*size_t*/
  _x10435 = kk_std_core_repeatz(_x10436, _x10440, _ctx); /*string*/
  return kk_std_core__lp__plus__plus__1_rp_(_x10435, s_9796, _ctx);
}
 
// Show a year in ISO format (using 5+ digits and explicit sign for years < 0 or years > 9999)).

kk_string_t kk_std_time_date_show_year(kk_integer_t year0, kk_context_t* _ctx) { /* (year : int) -> string */ 
  kk_std_core_types__tuple2_ _match_10001;
  bool _match_10003;
  kk_integer_t _x10441 = kk_integer_dup(year0); /*int*/
  _match_10003 = kk_integer_gt(_x10441,(kk_integer_from_int(9999, _ctx)),kk_context()); /*bool*/
  if (_match_10003) {
    kk_box_t _x10442;
    kk_string_t _x10443;
    kk_define_string_literal(, _s10444, 1, "+")
    _x10443 = kk_string_dup(_s10444); /*string*/
    _x10442 = kk_string_box(_x10443); /*4*/
    _match_10001 = kk_std_core_types__new_dash__lp__comma__rp_(_x10442, kk_integer_box(kk_integer_from_small(5)), _ctx); /*(4, 5)*/
  }
  else {
    bool _match_10004;
    kk_integer_t _x10445 = kk_integer_dup(year0); /*int*/
    _match_10004 = kk_std_core_is_neg_2(_x10445, _ctx); /*bool*/
    if (_match_10004) {
      kk_box_t _x10446;
      kk_string_t _x10447;
      kk_define_string_literal(, _s10448, 1, "-")
      _x10447 = kk_string_dup(_s10448); /*string*/
      _x10446 = kk_string_box(_x10447); /*4*/
      _match_10001 = kk_std_core_types__new_dash__lp__comma__rp_(_x10446, kk_integer_box(kk_integer_from_small(5)), _ctx); /*(4, 5)*/
    }
    else {
      kk_box_t _x10449;
      kk_string_t _x10450 = kk_string_empty(); /*string*/
      _x10449 = kk_string_box(_x10450); /*4*/
      _match_10001 = kk_std_core_types__new_dash__lp__comma__rp_(_x10449, kk_integer_box(kk_integer_from_small(4)), _ctx); /*(4, 5)*/
    }
  }
  kk_box_t _box_x9915 = _match_10001.fst;
  kk_box_t _box_x9916 = _match_10001.snd;
  kk_string_t ysign = kk_string_unbox(_box_x9915);
  kk_integer_t ywidth = kk_integer_unbox(_box_x9916);
  kk_string_dup(ysign);
  kk_integer_dup(ywidth);
  kk_std_core_types__tuple2__drop(_match_10001, _ctx);
  kk_string_t _x10454;
  kk_integer_t i_9799 = kk_integer_abs(year0,kk_context()); /*int*/;
  kk_std_core_types__optional width_9800 = kk_std_core_types__new_Optional(kk_integer_box(ywidth), _ctx); /*optional<int>*/;
  kk_string_t s_9801 = kk_std_core_show(i_9799, _ctx); /*string*/;
  kk_std_core_types__optional fill_9803 = kk_std_core_types__new_Optional(kk_char_box('0', _ctx), _ctx); /*optional<char>*/;
  size_t w;
  kk_integer_t _x10455;
  if (kk_std_core_types__is_Optional(width_9800)) {
    kk_box_t _box_x9921 = width_9800._cons.Optional.value;
    kk_integer_t _width_9238 = kk_integer_unbox(_box_x9921);
    kk_integer_dup(_width_9238);
    kk_std_core_types__optional_drop(width_9800, _ctx);
    _x10455 = _width_9238; /*int*/
    goto _match10456;
  }
  _x10455 = kk_integer_from_small(2); /*int*/
  _match10456: ;
  w = kk_std_core_size__t(_x10455, _ctx); /*size_t*/
  size_t n;
  kk_string_t _x10458 = kk_string_dup(s_9801); /*string*/
  n = kk_string_len(_x10458,kk_context()); /*size_t*/
  bool _match_10002 = (w <= n); /*bool*/;
  if (_match_10002) {
    kk_std_core_types__optional_drop(fill_9803, _ctx);
    _x10454 = s_9801; /*string*/
  }
  else {
    kk_string_t _x10459;
    kk_string_t _x10460;
    kk_char_t _x10461;
    if (kk_std_core_types__is_Optional(fill_9803)) {
      kk_box_t _box_x9922 = fill_9803._cons.Optional.value;
      kk_char_t _fill_8417 = kk_char_unbox(_box_x9922, NULL);
      kk_std_core_types__optional_drop(fill_9803, _ctx);
      _x10461 = _fill_8417; /*char*/
      goto _match10462;
    }
    _x10461 = ' '; /*char*/
    _match10462: ;
    _x10460 = kk_std_core_string(_x10461, _ctx); /*string*/
    size_t _x10464 = (w - n); /*size_t*/
    _x10459 = kk_std_core_repeatz(_x10460, _x10464, _ctx); /*string*/
    _x10454 = kk_std_core__lp__plus__plus__1_rp_(_x10459, s_9801, _ctx); /*string*/
  }
  return kk_std_core__lp__plus__plus__1_rp_(ysign, _x10454, _ctx);
}
 
// Show a date in ISO format. `Date(2000,1,1).show == "2000-01-01"`.
// Takes an optional `month-prefix` (=`""`) that is used by the ISO week
// and month calendar to add a `"W"` or `"M"` prefix respectively.

kk_string_t kk_std_time_date_show(kk_std_time_date__date d, kk_std_core_types__optional month_prefix, kk_context_t* _ctx) { /* (d : date, month-prefix : optional<string>) -> string */ 
  kk_integer_t day_width;
  bool _match_10000;
  kk_string_t _x10465;
  if (kk_std_core_types__is_Optional(month_prefix)) {
    kk_box_t _box_x9929 = month_prefix._cons.Optional.value;
    kk_string_t _month_prefix_8963 = kk_string_unbox(_box_x9929);
    kk_string_dup(_month_prefix_8963);
    _x10465 = _month_prefix_8963; /*string*/
    goto _match10466;
  }
  _x10465 = kk_string_empty(); /*string*/
  _match10466: ;
  kk_string_t _x10469;
  kk_define_string_literal(, _s10470, 1, "W")
  _x10469 = kk_string_dup(_s10470); /*string*/
  _match_10000 = kk_string_is_eq(_x10465,_x10469,kk_context()); /*bool*/
  if (_match_10000) {
    day_width = kk_integer_from_small(1); /*int*/
  }
  else {
    day_width = kk_integer_from_small(2); /*int*/
  }
  kk_string_t _x10471;
  kk_integer_t _x10472;
  kk_integer_t _x = d.year;
  kk_integer_dup(_x);
  _x10472 = _x; /*int*/
  _x10471 = kk_std_time_date_show_year(_x10472, _ctx); /*string*/
  kk_string_t _x10473;
  kk_string_t _x10474;
  kk_define_string_literal(, _s10475, 1, "-")
  _x10474 = kk_string_dup(_s10475); /*string*/
  kk_string_t _x10476;
  kk_string_t _x10477;
  if (kk_std_core_types__is_Optional(month_prefix)) {
    kk_box_t _box_x9930 = month_prefix._cons.Optional.value;
    kk_string_t _month_prefix_89630 = kk_string_unbox(_box_x9930);
    kk_string_dup(_month_prefix_89630);
    kk_std_core_types__optional_drop(month_prefix, _ctx);
    _x10477 = _month_prefix_89630; /*string*/
    goto _match10478;
  }
  _x10477 = kk_string_empty(); /*string*/
  _match10478: ;
  kk_string_t _x10481;
  kk_string_t _x10482;
  kk_string_t s_9808;
  kk_integer_t _x10483;
  kk_integer_t _x0 = d.month;
  kk_integer_dup(_x0);
  _x10483 = _x0; /*int*/
  s_9808 = kk_std_core_show(_x10483, _ctx); /*string*/
  kk_std_core_types__optional fill_9810 = kk_std_core_types__new_Optional(kk_char_box('0', _ctx), _ctx); /*optional<char>*/;
  size_t w;
  kk_integer_t _x10484;
  kk_std_core_types__optional _match_9999 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
  if (kk_std_core_types__is_Optional(_match_9999)) {
    kk_box_t _box_x9933 = _match_9999._cons.Optional.value;
    kk_integer_t _width_9238 = kk_integer_unbox(_box_x9933);
    kk_integer_dup(_width_9238);
    kk_std_core_types__optional_drop(_match_9999, _ctx);
    _x10484 = _width_9238; /*int*/
    goto _match10485;
  }
  _x10484 = kk_integer_from_small(2); /*int*/
  _match10485: ;
  w = kk_std_core_size__t(_x10484, _ctx); /*size_t*/
  size_t n;
  kk_string_t _x10487 = kk_string_dup(s_9808); /*string*/
  n = kk_string_len(_x10487,kk_context()); /*size_t*/
  bool _match_9998 = (w <= n); /*bool*/;
  if (_match_9998) {
    kk_std_core_types__optional_drop(fill_9810, _ctx);
    _x10482 = s_9808; /*string*/
  }
  else {
    kk_string_t _x10488;
    kk_string_t _x10489;
    kk_char_t _x10490;
    if (kk_std_core_types__is_Optional(fill_9810)) {
      kk_box_t _box_x9934 = fill_9810._cons.Optional.value;
      kk_char_t _fill_8417 = kk_char_unbox(_box_x9934, NULL);
      kk_std_core_types__optional_drop(fill_9810, _ctx);
      _x10490 = _fill_8417; /*char*/
      goto _match10491;
    }
    _x10490 = ' '; /*char*/
    _match10491: ;
    _x10489 = kk_std_core_string(_x10490, _ctx); /*string*/
    size_t _x10493 = (w - n); /*size_t*/
    _x10488 = kk_std_core_repeatz(_x10489, _x10493, _ctx); /*string*/
    _x10482 = kk_std_core__lp__plus__plus__1_rp_(_x10488, s_9808, _ctx); /*string*/
  }
  kk_string_t _x10494;
  kk_string_t _x10495;
  kk_define_string_literal(, _s10496, 1, "-")
  _x10495 = kk_string_dup(_s10496); /*string*/
  kk_string_t _x10497;
  kk_std_core_types__optional width1_9812 = kk_std_core_types__new_Optional(kk_integer_box(day_width), _ctx); /*optional<int>*/;
  kk_string_t s0_9814;
  kk_integer_t _x10498;
  kk_integer_t _x1 = d.day;
  kk_integer_dup(_x1);
  kk_std_time_date__date_drop(d, _ctx);
  _x10498 = _x1; /*int*/
  s0_9814 = kk_std_core_show(_x10498, _ctx); /*string*/
  kk_std_core_types__optional fill0_9816 = kk_std_core_types__new_Optional(kk_char_box('0', _ctx), _ctx); /*optional<char>*/;
  size_t w0;
  kk_integer_t _x10499;
  if (kk_std_core_types__is_Optional(width1_9812)) {
    kk_box_t _box_x9939 = width1_9812._cons.Optional.value;
    kk_integer_t _width_92380 = kk_integer_unbox(_box_x9939);
    kk_integer_dup(_width_92380);
    kk_std_core_types__optional_drop(width1_9812, _ctx);
    _x10499 = _width_92380; /*int*/
    goto _match10500;
  }
  _x10499 = kk_integer_from_small(2); /*int*/
  _match10500: ;
  w0 = kk_std_core_size__t(_x10499, _ctx); /*size_t*/
  size_t n0;
  kk_string_t _x10502 = kk_string_dup(s0_9814); /*string*/
  n0 = kk_string_len(_x10502,kk_context()); /*size_t*/
  bool _match_9997 = (w0 <= n0); /*bool*/;
  if (_match_9997) {
    kk_std_core_types__optional_drop(fill0_9816, _ctx);
    _x10497 = s0_9814; /*string*/
  }
  else {
    kk_string_t _x10503;
    kk_string_t _x10504;
    kk_char_t _x10505;
    if (kk_std_core_types__is_Optional(fill0_9816)) {
      kk_box_t _box_x9940 = fill0_9816._cons.Optional.value;
      kk_char_t _fill_84170 = kk_char_unbox(_box_x9940, NULL);
      kk_std_core_types__optional_drop(fill0_9816, _ctx);
      _x10505 = _fill_84170; /*char*/
      goto _match10506;
    }
    _x10505 = ' '; /*char*/
    _match10506: ;
    _x10504 = kk_std_core_string(_x10505, _ctx); /*string*/
    size_t _x10508 = (w0 - n0); /*size_t*/
    _x10503 = kk_std_core_repeatz(_x10504, _x10508, _ctx); /*string*/
    _x10497 = kk_std_core__lp__plus__plus__1_rp_(_x10503, s0_9814, _ctx); /*string*/
  }
  _x10494 = kk_std_core__lp__plus__plus__1_rp_(_x10495, _x10497, _ctx); /*string*/
  _x10481 = kk_std_core__lp__plus__plus__1_rp_(_x10482, _x10494, _ctx); /*string*/
  _x10476 = kk_std_core__lp__plus__plus__1_rp_(_x10477, _x10481, _ctx); /*string*/
  _x10473 = kk_std_core__lp__plus__plus__1_rp_(_x10474, _x10476, _ctx); /*string*/
  return kk_std_core__lp__plus__plus__1_rp_(_x10471, _x10473, _ctx);
}
 
// Show a clock in ISO format up to an optional maximum precision (=`9`).
// `Clock(23,30,fixed(1.123)).show == "23:30:01.123"`
// `Clock(23,30,fixed(1.123)).show(0) == "23:30:01"`

kk_string_t kk_std_time_date_show_1(kk_std_time_date__clock c, kk_std_core_types__optional prec, kk_context_t* _ctx) { /* (c : clock, prec : optional<int>) -> string */ 
  kk_string_t _x10509;
  kk_string_t s_9820;
  kk_integer_t _x10510;
  struct kk_std_time_date_Clock* _con10511 = kk_std_time_date__as_Clock(c);
  kk_integer_t _x = _con10511->hours;
  kk_std_num_ddouble__ddouble _pat10 = _con10511->seconds;
  kk_integer_dup(_x);
  _x10510 = _x; /*int*/
  s_9820 = kk_std_core_show(_x10510, _ctx); /*string*/
  kk_std_core_types__optional fill_9822 = kk_std_core_types__new_Optional(kk_char_box('0', _ctx), _ctx); /*optional<char>*/;
  size_t w;
  kk_integer_t _x10512;
  kk_std_core_types__optional _match_9996 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
  if (kk_std_core_types__is_Optional(_match_9996)) {
    kk_box_t _box_x9943 = _match_9996._cons.Optional.value;
    kk_integer_t _width_9238 = kk_integer_unbox(_box_x9943);
    kk_integer_dup(_width_9238);
    kk_std_core_types__optional_drop(_match_9996, _ctx);
    _x10512 = _width_9238; /*int*/
    goto _match10513;
  }
  _x10512 = kk_integer_from_small(2); /*int*/
  _match10513: ;
  w = kk_std_core_size__t(_x10512, _ctx); /*size_t*/
  size_t n;
  kk_string_t _x10515 = kk_string_dup(s_9820); /*string*/
  n = kk_string_len(_x10515,kk_context()); /*size_t*/
  bool _match_9995 = (w <= n); /*bool*/;
  if (_match_9995) {
    kk_std_core_types__optional_drop(fill_9822, _ctx);
    _x10509 = s_9820; /*string*/
  }
  else {
    kk_string_t _x10516;
    kk_string_t _x10517;
    kk_char_t _x10518;
    if (kk_std_core_types__is_Optional(fill_9822)) {
      kk_box_t _box_x9944 = fill_9822._cons.Optional.value;
      kk_char_t _fill_8417 = kk_char_unbox(_box_x9944, NULL);
      kk_std_core_types__optional_drop(fill_9822, _ctx);
      _x10518 = _fill_8417; /*char*/
      goto _match10519;
    }
    _x10518 = ' '; /*char*/
    _match10519: ;
    _x10517 = kk_std_core_string(_x10518, _ctx); /*string*/
    size_t _x10521 = (w - n); /*size_t*/
    _x10516 = kk_std_core_repeatz(_x10517, _x10521, _ctx); /*string*/
    _x10509 = kk_std_core__lp__plus__plus__1_rp_(_x10516, s_9820, _ctx); /*string*/
  }
  kk_string_t _x10522;
  kk_string_t _x10523;
  kk_define_string_literal(, _s10524, 1, ":")
  _x10523 = kk_string_dup(_s10524); /*string*/
  kk_string_t _x10525;
  kk_string_t _x10526;
  kk_string_t s0_9826;
  kk_integer_t _x10527;
  struct kk_std_time_date_Clock* _con10528 = kk_std_time_date__as_Clock(c);
  kk_integer_t _x0 = _con10528->minutes;
  kk_std_num_ddouble__ddouble _pat12 = _con10528->seconds;
  kk_integer_dup(_x0);
  _x10527 = _x0; /*int*/
  s0_9826 = kk_std_core_show(_x10527, _ctx); /*string*/
  kk_std_core_types__optional fill0_9828 = kk_std_core_types__new_Optional(kk_char_box('0', _ctx), _ctx); /*optional<char>*/;
  size_t w0;
  kk_integer_t _x10529;
  kk_std_core_types__optional _match_9994 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
  if (kk_std_core_types__is_Optional(_match_9994)) {
    kk_box_t _box_x9947 = _match_9994._cons.Optional.value;
    kk_integer_t _width_92380 = kk_integer_unbox(_box_x9947);
    kk_integer_dup(_width_92380);
    kk_std_core_types__optional_drop(_match_9994, _ctx);
    _x10529 = _width_92380; /*int*/
    goto _match10530;
  }
  _x10529 = kk_integer_from_small(2); /*int*/
  _match10530: ;
  w0 = kk_std_core_size__t(_x10529, _ctx); /*size_t*/
  size_t n0;
  kk_string_t _x10532 = kk_string_dup(s0_9826); /*string*/
  n0 = kk_string_len(_x10532,kk_context()); /*size_t*/
  bool _match_9993 = (w0 <= n0); /*bool*/;
  if (_match_9993) {
    kk_std_core_types__optional_drop(fill0_9828, _ctx);
    _x10526 = s0_9826; /*string*/
  }
  else {
    kk_string_t _x10533;
    kk_string_t _x10534;
    kk_char_t _x10535;
    if (kk_std_core_types__is_Optional(fill0_9828)) {
      kk_box_t _box_x9948 = fill0_9828._cons.Optional.value;
      kk_char_t _fill_84170 = kk_char_unbox(_box_x9948, NULL);
      kk_std_core_types__optional_drop(fill0_9828, _ctx);
      _x10535 = _fill_84170; /*char*/
      goto _match10536;
    }
    _x10535 = ' '; /*char*/
    _match10536: ;
    _x10534 = kk_std_core_string(_x10535, _ctx); /*string*/
    size_t _x10538 = (w0 - n0); /*size_t*/
    _x10533 = kk_std_core_repeatz(_x10534, _x10538, _ctx); /*string*/
    _x10526 = kk_std_core__lp__plus__plus__1_rp_(_x10533, s0_9826, _ctx); /*string*/
  }
  kk_string_t _x10539;
  kk_string_t _x10540;
  kk_define_string_literal(, _s10541, 1, ":")
  _x10540 = kk_string_dup(_s10541); /*string*/
  kk_string_t _x10542;
  kk_std_num_ddouble__ddouble _x10543;
  struct kk_std_time_date_Clock* _con10544 = kk_std_time_date__as_Clock(c);
  kk_integer_t _pat05 = _con10544->hours;
  kk_integer_t _pat13 = _con10544->minutes;
  kk_std_num_ddouble__ddouble _x1 = _con10544->seconds;
  if (kk_std_time_date__clock_is_unique(c)) {
    kk_integer_drop(_pat13, _ctx);
    kk_integer_drop(_pat05, _ctx);
    kk_std_time_date__clock_free(c);
  }
  else {
    kk_std_time_date__clock_decref(c, _ctx);
  }
  _x10543 = _x1; /*std/num/ddouble/ddouble*/
  kk_std_core_types__optional _x10545;
  kk_box_t _x10546;
  kk_integer_t _x10547;
  if (kk_std_core_types__is_Optional(prec)) {
    kk_box_t _box_x9949 = prec._cons.Optional.value;
    kk_integer_t _prec_9115 = kk_integer_unbox(_box_x9949);
    kk_integer_dup(_prec_9115);
    kk_std_core_types__optional_drop(prec, _ctx);
    _x10547 = _prec_9115; /*int*/
    goto _match10548;
  }
  _x10547 = kk_integer_from_small(9); /*int*/
  _match10548: ;
  _x10546 = kk_integer_box(_x10547); /*35*/
  _x10545 = kk_std_core_types__new_Optional(_x10546, _ctx); /*optional<35>*/
  kk_std_core_types__optional _x10550 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(2)), _ctx); /*optional<35>*/
  _x10542 = kk_std_time_date_show_seconds(_x10543, _x10545, _x10550, kk_std_core_types__new_None(_ctx), _ctx); /*string*/
  _x10539 = kk_std_core__lp__plus__plus__1_rp_(_x10540, _x10542, _ctx); /*string*/
  _x10525 = kk_std_core__lp__plus__plus__1_rp_(_x10526, _x10539, _ctx); /*string*/
  _x10522 = kk_std_core__lp__plus__plus__1_rp_(_x10523, _x10525, _ctx); /*string*/
  return kk_std_core__lp__plus__plus__1_rp_(_x10509, _x10522, _ctx);
}
 
// Show a `:weekday` as an English string (`Sun.show == "Sunday"`).

kk_string_t kk_std_time_date_show_2(kk_std_time_date__weekday wd, kk_context_t* _ctx) { /* (wd : weekday) -> string */ 
  if (kk_std_time_date__is_Mon(wd)) {
    kk_define_string_literal(, _s10551, 6, "Monday")
    return kk_string_dup(_s10551);
  }
  if (kk_std_time_date__is_Tue(wd)) {
    kk_define_string_literal(, _s10552, 7, "Tuesday")
    return kk_string_dup(_s10552);
  }
  if (kk_std_time_date__is_Wed(wd)) {
    kk_define_string_literal(, _s10553, 9, "Wednesday")
    return kk_string_dup(_s10553);
  }
  if (kk_std_time_date__is_Thu(wd)) {
    kk_define_string_literal(, _s10554, 8, "Thursday")
    return kk_string_dup(_s10554);
  }
  if (kk_std_time_date__is_Fri(wd)) {
    kk_define_string_literal(, _s10555, 6, "Friday")
    return kk_string_dup(_s10555);
  }
  if (kk_std_time_date__is_Sat(wd)) {
    kk_define_string_literal(, _s10556, 8, "Saturday")
    return kk_string_dup(_s10556);
  }
  kk_define_string_literal(, _s10557, 6, "Sunday")
  return kk_string_dup(_s10557);
}
 
// Show a `:weekday` as a 3 letter English string (`Sun.show-short == "Sun"`)

kk_string_t kk_std_time_date_show_short(kk_std_time_date__weekday wd, kk_context_t* _ctx) { /* (wd : weekday) -> string */ 
  kk_std_core__sslice _x10558;
  kk_string_t s_9830 = kk_std_time_date_show_2(wd, _ctx); /*string*/;
  kk_std_core_types__optional n_9831 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(3)), _ctx); /*optional<int>*/;
  kk_std_core__sslice slice = kk_std_core_first1(s_9830, _ctx); /*sslice*/;
  bool _match_9992;
  kk_integer_t _x10559;
  if (kk_std_core_types__is_Optional(n_9831)) {
    kk_box_t _box_x9956 = n_9831._cons.Optional.value;
    kk_integer_t _n_12425 = kk_integer_unbox(_box_x9956);
    kk_integer_dup(_n_12425);
    _x10559 = _n_12425; /*int*/
    goto _match10560;
  }
  _x10559 = kk_integer_from_small(1); /*int*/
  _match10560: ;
  _match_9992 = kk_integer_eq(_x10559,(kk_integer_from_small(1)),kk_context()); /*bool*/
  if (_match_9992) {
    kk_std_core_types__optional_drop(n_9831, _ctx);
    _x10558 = slice; /*sslice*/
  }
  else {
    kk_integer_t _x10562;
    kk_integer_t _x10563;
    if (kk_std_core_types__is_Optional(n_9831)) {
      kk_box_t _box_x9957 = n_9831._cons.Optional.value;
      kk_integer_t _n_124250 = kk_integer_unbox(_box_x9957);
      kk_integer_dup(_n_124250);
      kk_std_core_types__optional_drop(n_9831, _ctx);
      _x10563 = _n_124250; /*int*/
      goto _match10564;
    }
    _x10563 = kk_integer_from_small(1); /*int*/
    _match10564: ;
    _x10562 = kk_integer_sub(_x10563,(kk_integer_from_small(1)),kk_context()); /*int*/
    _x10558 = kk_std_core_extend(slice, _x10562, _ctx); /*sslice*/
  }
  return kk_std_core_string_3(_x10558, _ctx);
}
 
// Return the whole seconds part of a `:clock`.

kk_integer_t kk_std_time_date_whole_seconds(kk_std_time_date__clock c, kk_context_t* _ctx) { /* (c : clock) -> int */ 
  kk_std_num_ddouble__ddouble _x10567;
  bool _match_9991;
  kk_std_num_ddouble__ddouble _x10568;
  struct kk_std_time_date_Clock* _con10569 = kk_std_time_date__as_Clock(c);
  kk_std_num_ddouble__ddouble _x = _con10569->seconds;
  _x10568 = _x; /*std/num/ddouble/ddouble*/
  _match_9991 = kk_std_num_ddouble_is_neg(_x10568, _ctx); /*bool*/
  if (_match_9991) {
    kk_std_num_ddouble__ddouble _x10570;
    struct kk_std_time_date_Clock* _con10571 = kk_std_time_date__as_Clock(c);
    kk_integer_t _pat000 = _con10571->hours;
    kk_integer_t _pat100 = _con10571->minutes;
    kk_std_num_ddouble__ddouble _x0 = _con10571->seconds;
    if (kk_std_time_date__clock_is_unique(c)) {
      kk_integer_drop(_pat100, _ctx);
      kk_integer_drop(_pat000, _ctx);
      kk_std_time_date__clock_free(c);
    }
    else {
      kk_std_time_date__clock_decref(c, _ctx);
    }
    _x10570 = _x0; /*std/num/ddouble/ddouble*/
    _x10567 = kk_std_num_ddouble_ceiling(_x10570, _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    kk_std_num_ddouble__ddouble _x10572;
    struct kk_std_time_date_Clock* _con10573 = kk_std_time_date__as_Clock(c);
    kk_integer_t _pat001 = _con10573->hours;
    kk_integer_t _pat101 = _con10573->minutes;
    kk_std_num_ddouble__ddouble _x1 = _con10573->seconds;
    if (kk_std_time_date__clock_is_unique(c)) {
      kk_integer_drop(_pat101, _ctx);
      kk_integer_drop(_pat001, _ctx);
      kk_std_time_date__clock_free(c);
    }
    else {
      kk_std_time_date__clock_decref(c, _ctx);
    }
    _x10572 = _x1; /*std/num/ddouble/ddouble*/
    _x10567 = kk_std_num_ddouble_floor(_x10572, _ctx); /*std/num/ddouble/ddouble*/
  }
  return kk_std_num_ddouble_int(_x10567, kk_std_core_types__new_None(_ctx), _ctx);
}

// initialization
void kk_std_time_date__init(kk_context_t* _ctx){
  static bool _initialized = false;
  if (_initialized) return;
  _initialized = true;
  kk_std_core_types__init(_ctx);
  kk_std_core__init(_ctx);
  kk_std_num_double__init(_ctx);
  kk_std_num_ddouble__init(_ctx);
  {
    kk_std_num_ddouble__ddouble _x10277 = kk_std_num_ddouble__new_Ddouble(0x0p+0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    kk_std_time_date_clock0 = kk_std_time_date__new_Clock(kk_reuse_null, kk_integer_from_small(0), kk_integer_from_small(0), _x10277, _ctx); /*std/time/date/clock*/
  }
}
