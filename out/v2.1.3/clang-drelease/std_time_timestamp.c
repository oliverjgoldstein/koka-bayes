// Koka generated module: "std/time/timestamp", koka version: 2.1.3
#include "std_time_timestamp.h"

kk_integer_t kk_std_time_timestamp_isolar_secs_per_day;

kk_std_num_ddouble__ddouble kk_std_time_timestamp_timespan0;
 
// Compare two `:timestamp`s.

kk_std_core_types__order kk_std_time_timestamp_compare(kk_std_time_timestamp__timestamp i, kk_std_time_timestamp__timestamp j, kk_context_t* _ctx) { /* (i : timestamp, j : timestamp) -> order */ 
  kk_std_core_types__order _match_3952;
  kk_std_core_types__order _match_3953;
  bool _match_3960;
  double _x3973;
  kk_std_num_ddouble__ddouble _match_3965;
  kk_std_num_ddouble__ddouble _x3 = i.since;
  _match_3965 = _x3; /*std/time/timestamp/timespan*/
  double _x = _match_3965.hi;
  _x3973 = _x; /*double*/
  double _x3974;
  kk_std_num_ddouble__ddouble _match_3964;
  kk_std_num_ddouble__ddouble _x4 = j.since;
  _match_3964 = _x4; /*std/time/timestamp/timespan*/
  double _x0 = _match_3964.hi;
  _x3974 = _x0; /*double*/
  _match_3960 = (_x3973 < _x3974); /*bool*/
  if (_match_3960) {
    _match_3953 = kk_std_core_types__new_Lt(_ctx); /*order*/
  }
  else {
    bool _match_3961;
    double _x3975;
    kk_std_num_ddouble__ddouble _match_3963;
    kk_std_num_ddouble__ddouble _x30 = i.since;
    _match_3963 = _x30; /*std/time/timestamp/timespan*/
    double _x1 = _match_3963.hi;
    _x3975 = _x1; /*double*/
    double _x3976;
    kk_std_num_ddouble__ddouble _match_3962;
    kk_std_num_ddouble__ddouble _x40 = j.since;
    _match_3962 = _x40; /*std/time/timestamp/timespan*/
    double _x00 = _match_3962.hi;
    _x3976 = _x00; /*double*/
    _match_3961 = (_x3975 > _x3976); /*bool*/
    if (_match_3961) {
      _match_3953 = kk_std_core_types__new_Gt(_ctx); /*order*/
    }
    else {
      _match_3953 = kk_std_core_types__new_Eq(_ctx); /*order*/
    }
  }
  if (kk_std_core_types__is_Eq(_match_3953)) {
    bool _match_3954;
    double _x3977;
    kk_std_num_ddouble__ddouble _match_3959;
    kk_std_num_ddouble__ddouble _x31 = i.since;
    _match_3959 = _x31; /*std/time/timestamp/timespan*/
    double _x10 = _match_3959.lo;
    _x3977 = _x10; /*double*/
    double _x3978;
    kk_std_num_ddouble__ddouble _match_3958;
    kk_std_num_ddouble__ddouble _x41 = j.since;
    _match_3958 = _x41; /*std/time/timestamp/timespan*/
    double _x2 = _match_3958.lo;
    _x3978 = _x2; /*double*/
    _match_3954 = (_x3977 < _x3978); /*bool*/
    if (_match_3954) {
      _match_3952 = kk_std_core_types__new_Lt(_ctx); /*order*/
    }
    else {
      bool _match_3955;
      double _x3979;
      kk_std_num_ddouble__ddouble _match_3957;
      kk_std_num_ddouble__ddouble _x32 = i.since;
      _match_3957 = _x32; /*std/time/timestamp/timespan*/
      double _x11 = _match_3957.lo;
      _x3979 = _x11; /*double*/
      double _x3980;
      kk_std_num_ddouble__ddouble _match_3956;
      kk_std_num_ddouble__ddouble _x42 = j.since;
      _match_3956 = _x42; /*std/time/timestamp/timespan*/
      double _x20 = _match_3956.lo;
      _x3980 = _x20; /*double*/
      _match_3955 = (_x3979 > _x3980); /*bool*/
      if (_match_3955) {
        _match_3952 = kk_std_core_types__new_Gt(_ctx); /*order*/
      }
      else {
        _match_3952 = kk_std_core_types__new_Eq(_ctx); /*order*/
      }
    }
  }
  else {
    _match_3952 = _match_3953; /*order*/
  }
  if (kk_std_core_types__is_Eq(_match_3952)) {
    kk_integer_t _x3981 = kk_std_time_timestamp_leap(i, _ctx); /*int*/
    kk_integer_t _x3982 = kk_std_time_timestamp_leap(j, _ctx); /*int*/
    return kk_int_as_order(kk_integer_cmp(_x3981,_x3982,kk_context()),kk_context());
  }
  return _match_3952;
}

bool kk_std_time_timestamp__lp__excl__eq__rp_(kk_std_time_timestamp__timestamp i, kk_std_time_timestamp__timestamp j, kk_context_t* _ctx) { /* (i : timestamp, j : timestamp) -> bool */ 
  kk_std_core_types__order x_3756 = kk_std_time_timestamp_compare(i, j, _ctx); /*order*/;
  kk_integer_t _x3983 = kk_std_core_int_5(x_3756, _ctx); /*int*/
  kk_integer_t _x3984;
  kk_std_core_types__order _x3985 = kk_std_core_types__new_Eq(_ctx); /*order*/
  if (kk_std_core_types__is_Lt(_x3985)) {
    _x3984 = kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context()); /*int*/
    goto _match3986;
  }
  if (kk_std_core_types__is_Eq(_x3985)) {
    _x3984 = kk_integer_from_small(0); /*int*/
    goto _match3986;
  }
  _x3984 = kk_integer_from_small(1); /*int*/
  _match3986: ;
  return kk_integer_neq(_x3983,_x3984,kk_context());
}
 
// Create a time stamp from an integer timespan since 2000-01-01 and possible leap seconds.

kk_std_time_timestamp__timestamp kk_std_time_timestamp_timestamp_1(kk_integer_t t, kk_std_core_types__optional frac, kk_std_core_types__optional leap0, kk_context_t* _ctx) { /* (t : int, frac : optional<double>, leap : optional<int>) -> timestamp */ 
  kk_std_num_ddouble__ddouble t0_3760;
  kk_std_num_ddouble__ddouble _x3994 = kk_std_num_ddouble_ddouble_1(t, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x3995;
  double _x3996;
  if (kk_std_core_types__is_Optional(frac)) {
    kk_box_t _box_x3845 = frac._cons.Optional.value;
    double _frac_521 = kk_double_unbox(_box_x3845, NULL);
    kk_std_core_types__optional_drop(frac, _ctx);
    _x3996 = _frac_521; /*double*/
    goto _match3997;
  }
  _x3996 = 0x0p+0; /*double*/
  _match3997: ;
  _x3995 = kk_std_num_ddouble__new_Ddouble(_x3996, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  t0_3760 = kk_std_num_ddouble__lp__plus__rp_(_x3994, _x3995, _ctx); /*std/time/timestamp/timespan*/
  kk_std_core_types__optional leap0_3761;
  kk_box_t _x3999;
  kk_integer_t _x4000;
  if (kk_std_core_types__is_Optional(leap0)) {
    kk_box_t _box_x3846 = leap0._cons.Optional.value;
    kk_integer_t _leap_525 = kk_integer_unbox(_box_x3846);
    kk_integer_dup(_leap_525);
    kk_std_core_types__optional_drop(leap0, _ctx);
    _x4000 = _leap_525; /*int*/
    goto _match4001;
  }
  _x4000 = kk_integer_from_small(0); /*int*/
  _match4001: ;
  _x3999 = kk_integer_box(_x4000); /*108*/
  leap0_3761 = kk_std_core_types__new_Optional(_x3999, _ctx); /*optional<int>*/
  int32_t _x4003;
  kk_integer_t _x4004;
  if (kk_std_core_types__is_Optional(leap0_3761)) {
    kk_box_t _box_x3849 = leap0_3761._cons.Optional.value;
    kk_integer_t _leap_492 = kk_integer_unbox(_box_x3849);
    kk_integer_dup(_leap_492);
    kk_std_core_types__optional_drop(leap0_3761, _ctx);
    _x4004 = _leap_492; /*int*/
    goto _match4005;
  }
  _x4004 = kk_integer_from_small(0); /*int*/
  _match4005: ;
  _x4003 = kk_std_core_int32(_x4004, _ctx); /*int32*/
  return kk_std_time_timestamp__new_Timestamp(t0_3760, _x4003, _ctx);
}

bool kk_std_time_timestamp__lp__eq__eq__rp_(kk_std_time_timestamp__timestamp i, kk_std_time_timestamp__timestamp j, kk_context_t* _ctx) { /* (i : timestamp, j : timestamp) -> bool */ 
  kk_std_core_types__order x_3767 = kk_std_time_timestamp_compare(i, j, _ctx); /*order*/;
  kk_integer_t _x4011 = kk_std_core_int_5(x_3767, _ctx); /*int*/
  kk_integer_t _x4012;
  kk_std_core_types__order _x4013 = kk_std_core_types__new_Eq(_ctx); /*order*/
  if (kk_std_core_types__is_Lt(_x4013)) {
    _x4012 = kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context()); /*int*/
    goto _match4014;
  }
  if (kk_std_core_types__is_Eq(_x4013)) {
    _x4012 = kk_integer_from_small(0); /*int*/
    goto _match4014;
  }
  _x4012 = kk_integer_from_small(1); /*int*/
  _match4014: ;
  return kk_integer_eq(_x4011,_x4012,kk_context());
}

bool kk_std_time_timestamp__lp__lt__rp_(kk_std_time_timestamp__timestamp i, kk_std_time_timestamp__timestamp j, kk_context_t* _ctx) { /* (i : timestamp, j : timestamp) -> bool */ 
  kk_std_core_types__order x_3769 = kk_std_time_timestamp_compare(i, j, _ctx); /*order*/;
  kk_integer_t _x4015 = kk_std_core_int_5(x_3769, _ctx); /*int*/
  kk_integer_t _x4016;
  kk_std_core_types__order _x4017 = kk_std_core_types__new_Lt(_ctx); /*order*/
  if (kk_std_core_types__is_Lt(_x4017)) {
    _x4016 = kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context()); /*int*/
    goto _match4018;
  }
  if (kk_std_core_types__is_Eq(_x4017)) {
    _x4016 = kk_integer_from_small(0); /*int*/
    goto _match4018;
  }
  _x4016 = kk_integer_from_small(1); /*int*/
  _match4018: ;
  return kk_integer_eq(_x4015,_x4016,kk_context());
}

bool kk_std_time_timestamp__lp__lt__eq__rp_(kk_std_time_timestamp__timestamp i, kk_std_time_timestamp__timestamp j, kk_context_t* _ctx) { /* (i : timestamp, j : timestamp) -> bool */ 
  kk_std_core_types__order x_3771 = kk_std_time_timestamp_compare(i, j, _ctx); /*order*/;
  kk_integer_t _x4019 = kk_std_core_int_5(x_3771, _ctx); /*int*/
  kk_integer_t _x4020;
  kk_std_core_types__order _x4021 = kk_std_core_types__new_Gt(_ctx); /*order*/
  if (kk_std_core_types__is_Lt(_x4021)) {
    _x4020 = kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context()); /*int*/
    goto _match4022;
  }
  if (kk_std_core_types__is_Eq(_x4021)) {
    _x4020 = kk_integer_from_small(0); /*int*/
    goto _match4022;
  }
  _x4020 = kk_integer_from_small(1); /*int*/
  _match4022: ;
  return kk_integer_neq(_x4019,_x4020,kk_context());
}

bool kk_std_time_timestamp__lp__gt__rp_(kk_std_time_timestamp__timestamp i, kk_std_time_timestamp__timestamp j, kk_context_t* _ctx) { /* (i : timestamp, j : timestamp) -> bool */ 
  kk_std_core_types__order x_3773 = kk_std_time_timestamp_compare(i, j, _ctx); /*order*/;
  kk_integer_t _x4023 = kk_std_core_int_5(x_3773, _ctx); /*int*/
  kk_integer_t _x4024;
  kk_std_core_types__order _x4025 = kk_std_core_types__new_Gt(_ctx); /*order*/
  if (kk_std_core_types__is_Lt(_x4025)) {
    _x4024 = kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context()); /*int*/
    goto _match4026;
  }
  if (kk_std_core_types__is_Eq(_x4025)) {
    _x4024 = kk_integer_from_small(0); /*int*/
    goto _match4026;
  }
  _x4024 = kk_integer_from_small(1); /*int*/
  _match4026: ;
  return kk_integer_eq(_x4023,_x4024,kk_context());
}

bool kk_std_time_timestamp__lp__gt__eq__rp_(kk_std_time_timestamp__timestamp i, kk_std_time_timestamp__timestamp j, kk_context_t* _ctx) { /* (i : timestamp, j : timestamp) -> bool */ 
  kk_std_core_types__order x_3775 = kk_std_time_timestamp_compare(i, j, _ctx); /*order*/;
  kk_integer_t _x4027 = kk_std_core_int_5(x_3775, _ctx); /*int*/
  kk_integer_t _x4028;
  kk_std_core_types__order _x4029 = kk_std_core_types__new_Lt(_ctx); /*order*/
  if (kk_std_core_types__is_Lt(_x4029)) {
    _x4028 = kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context()); /*int*/
    goto _match4030;
  }
  if (kk_std_core_types__is_Eq(_x4029)) {
    _x4028 = kk_integer_from_small(0); /*int*/
    goto _match4030;
  }
  _x4028 = kk_integer_from_small(1); /*int*/
  _match4030: ;
  return kk_integer_neq(_x4027,_x4028,kk_context());
}

kk_std_num_ddouble__ddouble kk_std_time_timestamp_timespan(kk_integer_t seconds, kk_std_core_types__optional frac, kk_context_t* _ctx) { /* (seconds : int, frac : optional<double>) -> timespan */ 
  bool _match_3945;
  double _x4031;
  if (kk_std_core_types__is_Optional(frac)) {
    kk_box_t _box_x3850 = frac._cons.Optional.value;
    double _frac_1424 = kk_double_unbox(_box_x3850, NULL);
    _x4031 = _frac_1424; /*double*/
    goto _match4032;
  }
  _x4031 = 0x0p+0; /*double*/
  _match4032: ;
  _match_3945 = (_x4031 == (0x0p+0)); /*bool*/
  if (_match_3945) {
    kk_std_core_types__optional_drop(frac, _ctx);
    return kk_std_num_ddouble_ddouble_1(seconds, _ctx);
  }
  kk_std_num_ddouble__ddouble _x4034 = kk_std_num_ddouble_ddouble_1(seconds, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x4035;
  double _x4036;
  if (kk_std_core_types__is_Optional(frac)) {
    kk_box_t _box_x3851 = frac._cons.Optional.value;
    double _frac_14240 = kk_double_unbox(_box_x3851, NULL);
    kk_std_core_types__optional_drop(frac, _ctx);
    _x4036 = _frac_14240; /*double*/
    goto _match4037;
  }
  _x4036 = 0x0p+0; /*double*/
  _match4037: ;
  _x4035 = kk_std_num_ddouble__new_Ddouble(_x4036, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__lp__plus__rp_(_x4034, _x4035, _ctx);
}
 
// Add `days` days to a timestamp

kk_std_time_timestamp__timestamp kk_std_time_timestamp_add_days(kk_std_time_timestamp__timestamp ts, kk_integer_t days0, kk_context_t* _ctx) { /* (ts : timestamp, days : int) -> timestamp */ 
  kk_std_num_ddouble__ddouble t_3780;
  kk_integer_t seconds_3781 = kk_integer_mul(days0,(kk_integer_from_int(86400, _ctx)),kk_context()); /*int*/;
  bool _match_3942;
  double _x4040;
  kk_std_core_types__optional _match_3944 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
  if (kk_std_core_types__is_Optional(_match_3944)) {
    kk_box_t _box_x3852 = _match_3944._cons.Optional.value;
    double _frac_1424 = kk_double_unbox(_box_x3852, NULL);
    kk_std_core_types__optional_drop(_match_3944, _ctx);
    _x4040 = _frac_1424; /*double*/
    goto _match4041;
  }
  _x4040 = 0x0p+0; /*double*/
  _match4041: ;
  _match_3942 = (_x4040 == (0x0p+0)); /*bool*/
  if (_match_3942) {
    t_3780 = kk_std_num_ddouble_ddouble_1(seconds_3781, _ctx); /*std/time/timestamp/timespan*/
  }
  else {
    kk_std_num_ddouble__ddouble _x4043 = kk_std_num_ddouble_ddouble_1(seconds_3781, _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble _x4044;
    double _x4045;
    kk_std_core_types__optional _match_3943 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
    if (kk_std_core_types__is_Optional(_match_3943)) {
      kk_box_t _box_x3853 = _match_3943._cons.Optional.value;
      double _frac_14240 = kk_double_unbox(_box_x3853, NULL);
      kk_std_core_types__optional_drop(_match_3943, _ctx);
      _x4045 = _frac_14240; /*double*/
      goto _match4046;
    }
    _x4045 = 0x0p+0; /*double*/
    _match4046: ;
    _x4044 = kk_std_num_ddouble__new_Ddouble(_x4045, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    t_3780 = kk_std_num_ddouble__lp__plus__rp_(_x4043, _x4044, _ctx); /*std/time/timestamp/timespan*/
  }
  kk_std_num_ddouble__ddouble _x4048;
  kk_std_num_ddouble__ddouble _x4049;
  kk_std_num_ddouble__ddouble _x = ts.since;
  _x4049 = _x; /*std/time/timestamp/timespan*/
  _x4048 = kk_std_num_ddouble__lp__plus__rp_(_x4049, t_3780, _ctx); /*std/num/ddouble/ddouble*/
  int32_t _x4050;
  kk_std_num_ddouble__ddouble _pat00 = ts.since;
  int32_t _x0 = ts.leap32;
  _x4050 = _x0; /*int32*/
  return kk_std_time_timestamp__new_Timestamp(_x4048, _x4050, _ctx);
}
 
// Add `leaps` leap seconds to the timestamp.

kk_std_time_timestamp__timestamp kk_std_time_timestamp_add_leap_seconds(kk_std_time_timestamp__timestamp ts, kk_std_num_ddouble__ddouble leaps, kk_context_t* _ctx) { /* (ts : timestamp, leaps : timespan) -> timestamp */ 
  bool _match_3932;
  bool _x4051 = kk_std_num_ddouble_is_pos(leaps, _ctx); /*bool*/
  _match_3932 = !(_x4051); /*bool*/
  if (_match_3932) {
    return ts;
  }
  bool _match_3933;
  bool _match_3937;
  kk_std_num_ddouble__ddouble y_3788;
  bool _match_3939;
  double _x4052;
  kk_std_core_types__optional _match_3941 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
  if (kk_std_core_types__is_Optional(_match_3941)) {
    kk_box_t _box_x3854 = _match_3941._cons.Optional.value;
    double _frac_1424 = kk_double_unbox(_box_x3854, NULL);
    kk_std_core_types__optional_drop(_match_3941, _ctx);
    _x4052 = _frac_1424; /*double*/
    goto _match4053;
  }
  _x4052 = 0x0p+0; /*double*/
  _match4053: ;
  _match_3939 = (_x4052 == (0x0p+0)); /*bool*/
  if (_match_3939) {
    y_3788 = kk_std_num_ddouble_ddouble_1(kk_integer_from_small(1), _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    kk_std_num_ddouble__ddouble _x4055 = kk_std_num_ddouble_ddouble_1(kk_integer_from_small(1), _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble _x4056;
    double _x4057;
    kk_std_core_types__optional _match_3940 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
    if (kk_std_core_types__is_Optional(_match_3940)) {
      kk_box_t _box_x3855 = _match_3940._cons.Optional.value;
      double _frac_14240 = kk_double_unbox(_box_x3855, NULL);
      kk_std_core_types__optional_drop(_match_3940, _ctx);
      _x4057 = _frac_14240; /*double*/
      goto _match4058;
    }
    _x4057 = 0x0p+0; /*double*/
    _match4058: ;
    _x4056 = kk_std_num_ddouble__new_Ddouble(_x4057, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    y_3788 = kk_std_num_ddouble__lp__plus__rp_(_x4055, _x4056, _ctx); /*std/num/ddouble/ddouble*/
  }
  kk_std_core_types__order x0_20773 = kk_std_num_ddouble_compare(leaps, y_3788, _ctx); /*order*/;
  kk_integer_t _x4060 = kk_std_core_int_5(x0_20773, _ctx); /*int*/
  kk_integer_t _x4061;
  kk_std_core_types__order _x4062 = kk_std_core_types__new_Lt(_ctx); /*order*/
  if (kk_std_core_types__is_Lt(_x4062)) {
    _x4061 = kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context()); /*int*/
    goto _match4063;
  }
  if (kk_std_core_types__is_Eq(_x4062)) {
    _x4061 = kk_integer_from_small(0); /*int*/
    goto _match4063;
  }
  _x4061 = kk_integer_from_small(1); /*int*/
  _match4063: ;
  _match_3937 = kk_integer_eq(_x4060,_x4061,kk_context()); /*bool*/
  if (_match_3937) {
    kk_integer_t _x4064 = kk_std_time_timestamp_leap(ts, _ctx); /*int*/
    _match_3933 = kk_integer_is_zero(_x4064,kk_context()); /*bool*/
  }
  else {
    _match_3933 = false; /*bool*/
  }
  if (_match_3933) {
    kk_std_num_ddouble__ddouble _x4065;
    kk_std_num_ddouble__ddouble _x4066;
    kk_std_num_ddouble__ddouble y0_3794;
    bool _match_3934;
    double _x4067;
    kk_std_core_types__optional _match_3936 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
    if (kk_std_core_types__is_Optional(_match_3936)) {
      kk_box_t _box_x3856 = _match_3936._cons.Optional.value;
      double _frac_14241 = kk_double_unbox(_box_x3856, NULL);
      kk_std_core_types__optional_drop(_match_3936, _ctx);
      _x4067 = _frac_14241; /*double*/
      goto _match4068;
    }
    _x4067 = 0x0p+0; /*double*/
    _match4068: ;
    _match_3934 = (_x4067 == (0x0p+0)); /*bool*/
    if (_match_3934) {
      y0_3794 = kk_std_num_ddouble_ddouble_1(kk_integer_from_small(1), _ctx); /*std/num/ddouble/ddouble*/
    }
    else {
      kk_std_num_ddouble__ddouble _x4070 = kk_std_num_ddouble_ddouble_1(kk_integer_from_small(1), _ctx); /*std/num/ddouble/ddouble*/
      kk_std_num_ddouble__ddouble _x4071;
      double _x4072;
      kk_std_core_types__optional _match_3935 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
      if (kk_std_core_types__is_Optional(_match_3935)) {
        kk_box_t _box_x3857 = _match_3935._cons.Optional.value;
        double _frac_14242 = kk_double_unbox(_box_x3857, NULL);
        kk_std_core_types__optional_drop(_match_3935, _ctx);
        _x4072 = _frac_14242; /*double*/
        goto _match4073;
      }
      _x4072 = 0x0p+0; /*double*/
      _match4073: ;
      _x4071 = kk_std_num_ddouble__new_Ddouble(_x4072, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
      y0_3794 = kk_std_num_ddouble__lp__plus__rp_(_x4070, _x4071, _ctx); /*std/num/ddouble/ddouble*/
    }
    kk_std_num_ddouble__ddouble _x4075;
    kk_std_num_ddouble__ddouble _x = ts.since;
    _x4075 = _x; /*std/time/timestamp/timespan*/
    kk_std_num_ddouble__ddouble _x4076 = kk_std_num_ddouble__lp__tilde__rp_(y0_3794, _ctx); /*std/num/ddouble/ddouble*/
    _x4066 = kk_std_num_ddouble__lp__plus__rp_(_x4075, _x4076, _ctx); /*std/num/ddouble/ddouble*/
    _x4065 = kk_std_num_ddouble__lp__plus__rp_(_x4066, leaps, _ctx); /*std/num/ddouble/ddouble*/
    return kk_std_time_timestamp__new_Timestamp(_x4065, ((int32_t)1), _ctx);
  }
  kk_std_num_ddouble__ddouble _x4077;
  kk_std_num_ddouble__ddouble _x4078;
  kk_std_num_ddouble__ddouble _x0 = ts.since;
  _x4078 = _x0; /*std/time/timestamp/timespan*/
  kk_std_num_ddouble__ddouble _x4079 = kk_std_num_ddouble_fraction(leaps, _ctx); /*std/num/ddouble/ddouble*/
  _x4077 = kk_std_num_ddouble__lp__plus__rp_(_x4078, _x4079, _ctx); /*std/num/ddouble/ddouble*/
  int32_t _x4080;
  int32_t _x4081;
  kk_std_num_ddouble__ddouble _pat07 = ts.since;
  int32_t _x1 = ts.leap32;
  _x4081 = _x1; /*int32*/
  int32_t _x4082;
  kk_integer_t _x4083;
  kk_std_num_ddouble__ddouble _x4084 = kk_std_num_ddouble_truncate(leaps, _ctx); /*std/num/ddouble/ddouble*/
  _x4083 = kk_std_num_ddouble_int(_x4084, kk_std_core_types__new_None(_ctx), _ctx); /*int*/
  _x4082 = kk_std_core_int32(_x4083, _ctx); /*int32*/
  _x4080 = (_x4081 + _x4082); /*int32*/
  return kk_std_time_timestamp__new_Timestamp(_x4077, _x4080, _ctx);
}
 
// Return days and seconds into the day, disregarding leap seconds.

kk_std_core_types__tuple2_ kk_std_time_timestamp_days_seconds(kk_std_time_timestamp__timestamp ts, kk_context_t* _ctx) { /* (ts : timestamp) -> (int, std/num/ddouble/ddouble) */ 
  kk_std_num_ddouble__ddouble secs;
  kk_std_num_ddouble__ddouble _x4085;
  kk_std_num_ddouble__ddouble _x = ts.since;
  _x4085 = _x; /*std/time/timestamp/timespan*/
  secs = kk_std_num_ddouble_floor(_x4085, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble frac;
  kk_std_num_ddouble__ddouble _x4086;
  kk_std_num_ddouble__ddouble _x0 = ts.since;
  _x4086 = _x0; /*std/time/timestamp/timespan*/
  kk_std_num_ddouble__ddouble _x4087 = kk_std_num_ddouble__lp__tilde__rp_(secs, _ctx); /*std/num/ddouble/ddouble*/
  frac = kk_std_num_ddouble__lp__plus__rp_(_x4086, _x4087, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_core_types__tuple2_ _match_3931;
  kk_integer_t _x4088 = kk_std_num_ddouble_int(secs, kk_std_core_types__new_None(_ctx), _ctx); /*int*/
  _match_3931 = kk_integer_div_mod_tuple(_x4088,(kk_integer_from_int(86400, _ctx)),kk_context()); /*(int, int)*/
  kk_box_t _box_x3858 = _match_3931.fst;
  kk_box_t _box_x3859 = _match_3931.snd;
  kk_integer_t days0 = kk_integer_unbox(_box_x3858);
  kk_integer_t dsecs = kk_integer_unbox(_box_x3859);
  kk_integer_dup(days0);
  kk_integer_dup(dsecs);
  kk_std_core_types__tuple2__drop(_match_3931, _ctx);
  kk_std_num_ddouble__ddouble _b_3863_3861;
  kk_std_num_ddouble__ddouble _x4091 = kk_std_num_ddouble_ddouble_1(dsecs, _ctx); /*std/num/ddouble/ddouble*/
  _b_3863_3861 = kk_std_num_ddouble__lp__plus__rp_(_x4091, frac, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_core_types__new_dash__lp__comma__rp_(kk_integer_box(days0), kk_std_num_ddouble__ddouble_box(_b_3863_3861, _ctx), _ctx);
}
 
// Return days and clock into the day, handling possible leap seconds.

kk_std_core_types__tuple2_ kk_std_time_timestamp_days_clock(kk_std_time_timestamp__timestamp ts, kk_context_t* _ctx) { /* (ts : timestamp) -> (int, std/time/date/clock) */ 
  kk_std_core_types__tuple2_ _match_3930 = kk_std_time_timestamp_days_seconds(ts, _ctx); /*(int, std/num/ddouble/ddouble)*/;
  kk_box_t _box_x3866 = _match_3930.fst;
  kk_box_t _box_x3867 = _match_3930.snd;
  kk_integer_t days0 = kk_integer_unbox(_box_x3866);
  kk_std_num_ddouble__ddouble secs = kk_std_num_ddouble__ddouble_unbox(_box_x3867, NULL);
  kk_integer_dup(days0);
  kk_std_core_types__tuple2__drop(_match_3930, _ctx);
  kk_std_time_date__clock _b_3871_3869;
  kk_integer_t _x4096 = kk_std_time_timestamp_leap(ts, _ctx); /*int*/
  _b_3871_3869 = kk_std_time_date_clock_3(secs, _x4096, _ctx); /*std/time/date/clock*/
  return kk_std_core_types__new_dash__lp__comma__rp_(kk_integer_box(days0), kk_std_time_date__clock_box(_b_3871_3869, _ctx), _ctx);
}
 
// Round a time stamp to a certain precision (`prec` is number of digits of the fraction of the second).

kk_std_time_timestamp__timestamp kk_std_time_timestamp_round_to_prec(kk_std_time_timestamp__timestamp t, kk_integer_t prec, kk_context_t* _ctx) { /* (t : timestamp, prec : int) -> timestamp */ 
  kk_std_num_ddouble__ddouble _x4097;
  bool _match_3926;
  kk_integer_t _x4098 = kk_integer_dup(prec); /*int*/
  _match_3926 = kk_integer_lte(_x4098,(kk_integer_from_small(0)),kk_context()); /*bool*/
  if (_match_3926) {
    kk_integer_drop(prec, _ctx);
    kk_std_num_ddouble__ddouble _x4099;
    kk_std_num_ddouble__ddouble _x = t.since;
    _x4099 = _x; /*std/time/timestamp/timespan*/
    _x4097 = kk_std_num_ddouble_round(_x4099, _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    bool _match_3927;
    kk_integer_t _x4100 = kk_integer_dup(prec); /*int*/
    _match_3927 = kk_integer_gt(_x4100,(kk_integer_from_small(31)),kk_context()); /*bool*/
    if (_match_3927) {
      kk_integer_drop(prec, _ctx);
      kk_std_num_ddouble__ddouble _x0 = t.since;
      _x4097 = _x0; /*std/num/ddouble/ddouble*/
    }
    else {
      kk_std_num_ddouble__ddouble p = kk_std_num_ddouble_powi10(prec, _ctx); /*std/num/ddouble/ddouble*/;
      kk_std_num_ddouble__ddouble _x4101;
      kk_std_num_ddouble__ddouble _x4102;
      kk_std_num_ddouble__ddouble _x4103;
      kk_std_num_ddouble__ddouble _x1 = t.since;
      _x4103 = _x1; /*std/time/timestamp/timespan*/
      _x4102 = kk_std_num_ddouble__lp__star__rp_(_x4103, p, _ctx); /*std/num/ddouble/ddouble*/
      _x4101 = kk_std_num_ddouble_round(_x4102, _ctx); /*std/num/ddouble/ddouble*/
      _x4097 = kk_std_num_ddouble__lp__fs__rp_(_x4101, p, _ctx); /*std/num/ddouble/ddouble*/
    }
  }
  int32_t _x4104;
  kk_std_num_ddouble__ddouble _pat01 = t.since;
  int32_t _x00 = t.leap32;
  _x4104 = _x00; /*int32*/
  return kk_std_time_timestamp__new_Timestamp(_x4097, _x4104, _ctx);
}

kk_std_num_ddouble__ddouble kk_std_time_timestamp_solar_secs_per_day;
 
// Timestamp from days, seconds into the day and possible leap second.

kk_std_time_timestamp__timestamp kk_std_time_timestamp_timestamp_days(kk_integer_t days0, kk_std_core_types__optional secs, kk_std_core_types__optional leap0, kk_context_t* _ctx) { /* (days : int, secs : optional<timespan>, leap : optional<int>) -> timestamp */ 
  kk_std_num_ddouble__ddouble t_3817;
  kk_std_num_ddouble__ddouble _x4117;
  kk_integer_t seconds_3819 = kk_integer_mul(days0,(kk_integer_from_int(86400, _ctx)),kk_context()); /*int*/;
  bool _match_3920;
  double _x4118;
  kk_std_core_types__optional _match_3922 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
  if (kk_std_core_types__is_Optional(_match_3922)) {
    kk_box_t _box_x3876 = _match_3922._cons.Optional.value;
    double _frac_1424 = kk_double_unbox(_box_x3876, NULL);
    kk_std_core_types__optional_drop(_match_3922, _ctx);
    _x4118 = _frac_1424; /*double*/
    goto _match4119;
  }
  _x4118 = 0x0p+0; /*double*/
  _match4119: ;
  _match_3920 = (_x4118 == (0x0p+0)); /*bool*/
  if (_match_3920) {
    _x4117 = kk_std_num_ddouble_ddouble_1(seconds_3819, _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    kk_std_num_ddouble__ddouble _x4121 = kk_std_num_ddouble_ddouble_1(seconds_3819, _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble _x4122;
    double _x4123;
    kk_std_core_types__optional _match_3921 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
    if (kk_std_core_types__is_Optional(_match_3921)) {
      kk_box_t _box_x3877 = _match_3921._cons.Optional.value;
      double _frac_14240 = kk_double_unbox(_box_x3877, NULL);
      kk_std_core_types__optional_drop(_match_3921, _ctx);
      _x4123 = _frac_14240; /*double*/
      goto _match4124;
    }
    _x4123 = 0x0p+0; /*double*/
    _match4124: ;
    _x4122 = kk_std_num_ddouble__new_Ddouble(_x4123, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    _x4117 = kk_std_num_ddouble__lp__plus__rp_(_x4121, _x4122, _ctx); /*std/num/ddouble/ddouble*/
  }
  kk_std_num_ddouble__ddouble _x4126;
  if (kk_std_core_types__is_Optional(secs)) {
    kk_box_t _box_x3878 = secs._cons.Optional.value;
    kk_std_num_ddouble__ddouble _secs_2968 = kk_std_num_ddouble__ddouble_unbox(_box_x3878, NULL);
    kk_std_core_types__optional_drop(secs, _ctx);
    _x4126 = _secs_2968; /*std/time/timestamp/timespan*/
    goto _match4127;
  }
  _x4126 = kk_std_num_ddouble__new_Ddouble(0x0p+0, 0x0p+0, _ctx); /*std/time/timestamp/timespan*/
  _match4127: ;
  t_3817 = kk_std_num_ddouble__lp__plus__rp_(_x4117, _x4126, _ctx); /*std/time/timestamp/timespan*/
  kk_std_core_types__optional leap0_3818;
  kk_box_t _x4129;
  kk_integer_t _x4130;
  if (kk_std_core_types__is_Optional(leap0)) {
    kk_box_t _box_x3879 = leap0._cons.Optional.value;
    kk_integer_t _leap_2972 = kk_integer_unbox(_box_x3879);
    kk_integer_dup(_leap_2972);
    kk_std_core_types__optional_drop(leap0, _ctx);
    _x4130 = _leap_2972; /*int*/
    goto _match4131;
  }
  _x4130 = kk_integer_from_small(0); /*int*/
  _match4131: ;
  _x4129 = kk_integer_box(_x4130); /*108*/
  leap0_3818 = kk_std_core_types__new_Optional(_x4129, _ctx); /*optional<int>*/
  int32_t _x4133;
  kk_integer_t _x4134;
  if (kk_std_core_types__is_Optional(leap0_3818)) {
    kk_box_t _box_x3882 = leap0_3818._cons.Optional.value;
    kk_integer_t _leap_492 = kk_integer_unbox(_box_x3882);
    kk_integer_dup(_leap_492);
    kk_std_core_types__optional_drop(leap0_3818, _ctx);
    _x4134 = _leap_492; /*int*/
    goto _match4135;
  }
  _x4134 = kk_integer_from_small(0); /*int*/
  _match4135: ;
  _x4133 = kk_std_core_int32(_x4134, _ctx); /*int32*/
  return kk_std_time_timestamp__new_Timestamp(t_3817, _x4133, _ctx);
}
 
// The time stamp at 2000-01-01

kk_std_time_timestamp__timestamp kk_std_time_timestamp_timestamp0;
 
// Show a time stamp.

kk_string_t kk_std_time_timestamp_ts_show(kk_std_time_timestamp__timestamp ts, kk_std_core_types__optional max_prec, kk_std_core_types__optional secs_width, kk_std_core_types__optional unit, kk_context_t* _ctx) { /* (ts : timestamp, max-prec : optional<int>, secs-width : optional<int>, unit : optional<string>) -> string */ 
  kk_string_t l;
  bool _match_3919;
  kk_integer_t _x4138 = kk_std_time_timestamp_leap(ts, _ctx); /*int*/
  _match_3919 = kk_integer_is_zero(_x4138,kk_context()); /*bool*/
  if (_match_3919) {
    l = kk_string_empty(); /*string*/
  }
  else {
    kk_string_t _x4140;
    kk_define_string_literal(, _s4141, 3, " (+")
    _x4140 = kk_string_dup(_s4141); /*string*/
    kk_string_t _x4142;
    kk_string_t _x4143;
    kk_integer_t _x4144 = kk_std_time_timestamp_leap(ts, _ctx); /*int*/
    _x4143 = kk_std_core_show(_x4144, _ctx); /*string*/
    kk_string_t _x4145;
    kk_define_string_literal(, _s4146, 6, " leap)")
    _x4145 = kk_string_dup(_s4146); /*string*/
    _x4142 = kk_std_core__lp__plus__plus__1_rp_(_x4143, _x4145, _ctx); /*string*/
    l = kk_std_core__lp__plus__plus__1_rp_(_x4140, _x4142, _ctx); /*string*/
  }
  kk_string_t _x4147;
  kk_std_num_ddouble__ddouble _x4148;
  kk_std_num_ddouble__ddouble _x = ts.since;
  _x4148 = _x; /*std/time/timestamp/timespan*/
  kk_std_core_types__optional _x4149;
  kk_box_t _x4150;
  kk_integer_t _x4151;
  if (kk_std_core_types__is_Optional(max_prec)) {
    kk_box_t _box_x3883 = max_prec._cons.Optional.value;
    kk_integer_t _max_prec_3275 = kk_integer_unbox(_box_x3883);
    kk_integer_dup(_max_prec_3275);
    kk_std_core_types__optional_drop(max_prec, _ctx);
    _x4151 = _max_prec_3275; /*int*/
    goto _match4152;
  }
  _x4151 = kk_integer_from_small(9); /*int*/
  _match4152: ;
  _x4150 = kk_integer_box(_x4151); /*108*/
  _x4149 = kk_std_core_types__new_Optional(_x4150, _ctx); /*optional<108>*/
  kk_std_core_types__optional _x4154;
  kk_box_t _x4155;
  kk_integer_t _x4156;
  if (kk_std_core_types__is_Optional(secs_width)) {
    kk_box_t _box_x3885 = secs_width._cons.Optional.value;
    kk_integer_t _secs_width_3279 = kk_integer_unbox(_box_x3885);
    kk_integer_dup(_secs_width_3279);
    kk_std_core_types__optional_drop(secs_width, _ctx);
    _x4156 = _secs_width_3279; /*int*/
    goto _match4157;
  }
  _x4156 = kk_integer_from_small(1); /*int*/
  _match4157: ;
  _x4155 = kk_integer_box(_x4156); /*108*/
  _x4154 = kk_std_core_types__new_Optional(_x4155, _ctx); /*optional<108>*/
  kk_std_core_types__optional _x4159;
  kk_box_t _x4160;
  kk_string_t _x4161;
  if (kk_std_core_types__is_Optional(unit)) {
    kk_box_t _box_x3887 = unit._cons.Optional.value;
    kk_string_t _unit_3283 = kk_string_unbox(_box_x3887);
    kk_string_dup(_unit_3283);
    kk_std_core_types__optional_drop(unit, _ctx);
    _x4161 = _unit_3283; /*string*/
    goto _match4162;
  }
  _x4161 = kk_string_empty(); /*string*/
  _match4162: ;
  _x4160 = kk_string_box(_x4161); /*108*/
  _x4159 = kk_std_core_types__new_Optional(_x4160, _ctx); /*optional<108>*/
  _x4147 = kk_std_time_date_show_seconds(_x4148, _x4149, _x4154, _x4159, _ctx); /*string*/
  return kk_std_core__lp__plus__plus__1_rp_(_x4147, l, _ctx);
}
 
// Show a day stamp

kk_string_t kk_std_time_timestamp_ts_show_days(kk_std_time_timestamp__timestamp ts, kk_std_core_types__optional prec, kk_context_t* _ctx) { /* (ts : timestamp, prec : optional<int>) -> string */ 
  kk_std_core_types__tuple2_ _match_3916 = kk_std_time_timestamp_days_seconds(ts, _ctx); /*(int, std/num/ddouble/ddouble)*/;
  kk_box_t _box_x3892 = _match_3916.fst;
  kk_box_t _box_x3893 = _match_3916.snd;
  kk_integer_t days0 = kk_integer_unbox(_box_x3892);
  kk_std_num_ddouble__ddouble secs = kk_std_num_ddouble__ddouble_unbox(_box_x3893, NULL);
  kk_integer_dup(days0);
  kk_std_core_types__tuple2__drop(_match_3916, _ctx);
  kk_string_t _x4167 = kk_std_core_show(days0, _ctx); /*string*/
  kk_string_t _x4168;
  kk_string_t _x4169;
  kk_define_string_literal(, _s4170, 2, "d ")
  _x4169 = kk_string_dup(_s4170); /*string*/
  kk_string_t _x4171;
  kk_std_time_timestamp__timestamp _arg_3681;
  kk_std_core_types__optional leap_3825;
  kk_integer_t _b_3895_3894 = kk_std_time_timestamp_leap(ts, _ctx); /*int*/;
  leap_3825 = kk_std_core_types__new_Optional(kk_integer_box(_b_3895_3894), _ctx); /*optional<int>*/
  int32_t _x4172;
  kk_integer_t _x4173;
  if (kk_std_core_types__is_Optional(leap_3825)) {
    kk_box_t _box_x3896 = leap_3825._cons.Optional.value;
    kk_integer_t _leap_492 = kk_integer_unbox(_box_x3896);
    kk_integer_dup(_leap_492);
    kk_std_core_types__optional_drop(leap_3825, _ctx);
    _x4173 = _leap_492; /*int*/
    goto _match4174;
  }
  _x4173 = kk_integer_from_small(0); /*int*/
  _match4174: ;
  _x4172 = kk_std_core_int32(_x4173, _ctx); /*int32*/
  _arg_3681 = kk_std_time_timestamp__new_Timestamp(secs, _x4172, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_core_types__optional _arg_3682;
  kk_box_t _x4176;
  kk_integer_t _x4177;
  if (kk_std_core_types__is_Optional(prec)) {
    kk_box_t _box_x3897 = prec._cons.Optional.value;
    kk_integer_t _prec_3508 = kk_integer_unbox(_box_x3897);
    kk_integer_dup(_prec_3508);
    kk_std_core_types__optional_drop(prec, _ctx);
    _x4177 = _prec_3508; /*int*/
    goto _match4178;
  }
  _x4177 = kk_integer_from_small(9); /*int*/
  _match4178: ;
  _x4176 = kk_integer_box(_x4177); /*108*/
  _arg_3682 = kk_std_core_types__new_Optional(_x4176, _ctx); /*optional<int>*/
  kk_std_core_types__optional _arg_3684;
  kk_box_t _x4180;
  kk_string_t _x4181;
  kk_define_string_literal(, _s4182, 1, "s")
  _x4181 = kk_string_dup(_s4182); /*string*/
  _x4180 = kk_string_box(_x4181); /*108*/
  _arg_3684 = kk_std_core_types__new_Optional(_x4180, _ctx); /*optional<string>*/
  kk_string_t l;
  bool _match_3918;
  kk_integer_t _x4183 = kk_std_time_timestamp_leap(_arg_3681, _ctx); /*int*/
  _match_3918 = kk_integer_is_zero(_x4183,kk_context()); /*bool*/
  if (_match_3918) {
    l = kk_string_empty(); /*string*/
  }
  else {
    kk_string_t _x4185;
    kk_define_string_literal(, _s4186, 3, " (+")
    _x4185 = kk_string_dup(_s4186); /*string*/
    kk_string_t _x4187;
    kk_string_t _x4188;
    kk_integer_t _x4189 = kk_std_time_timestamp_leap(_arg_3681, _ctx); /*int*/
    _x4188 = kk_std_core_show(_x4189, _ctx); /*string*/
    kk_string_t _x4190;
    kk_define_string_literal(, _s4191, 6, " leap)")
    _x4190 = kk_string_dup(_s4191); /*string*/
    _x4187 = kk_std_core__lp__plus__plus__1_rp_(_x4188, _x4190, _ctx); /*string*/
    l = kk_std_core__lp__plus__plus__1_rp_(_x4185, _x4187, _ctx); /*string*/
  }
  kk_string_t _x4192;
  kk_std_num_ddouble__ddouble _x4193;
  kk_std_num_ddouble__ddouble _x = _arg_3681.since;
  _x4193 = _x; /*std/time/timestamp/timespan*/
  kk_std_core_types__optional _x4194;
  kk_box_t _x4195;
  kk_integer_t _x4196;
  if (kk_std_core_types__is_Optional(_arg_3682)) {
    kk_box_t _box_x3902 = _arg_3682._cons.Optional.value;
    kk_integer_t _max_prec_3275 = kk_integer_unbox(_box_x3902);
    kk_integer_dup(_max_prec_3275);
    kk_std_core_types__optional_drop(_arg_3682, _ctx);
    _x4196 = _max_prec_3275; /*int*/
    goto _match4197;
  }
  _x4196 = kk_integer_from_small(9); /*int*/
  _match4197: ;
  _x4195 = kk_integer_box(_x4196); /*108*/
  _x4194 = kk_std_core_types__new_Optional(_x4195, _ctx); /*optional<108>*/
  kk_std_core_types__optional _x4199;
  kk_box_t _x4200;
  kk_integer_t _x4201;
  kk_std_core_types__optional _match_3917 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
  if (kk_std_core_types__is_Optional(_match_3917)) {
    kk_box_t _box_x3904 = _match_3917._cons.Optional.value;
    kk_integer_t _secs_width_3279 = kk_integer_unbox(_box_x3904);
    kk_integer_dup(_secs_width_3279);
    kk_std_core_types__optional_drop(_match_3917, _ctx);
    _x4201 = _secs_width_3279; /*int*/
    goto _match4202;
  }
  _x4201 = kk_integer_from_small(1); /*int*/
  _match4202: ;
  _x4200 = kk_integer_box(_x4201); /*108*/
  _x4199 = kk_std_core_types__new_Optional(_x4200, _ctx); /*optional<108>*/
  kk_std_core_types__optional _x4204;
  kk_box_t _x4205;
  kk_string_t _x4206;
  if (kk_std_core_types__is_Optional(_arg_3684)) {
    kk_box_t _box_x3906 = _arg_3684._cons.Optional.value;
    kk_string_t _unit_3283 = kk_string_unbox(_box_x3906);
    kk_string_dup(_unit_3283);
    kk_std_core_types__optional_drop(_arg_3684, _ctx);
    _x4206 = _unit_3283; /*string*/
    goto _match4207;
  }
  _x4206 = kk_string_empty(); /*string*/
  _match4207: ;
  _x4205 = kk_string_box(_x4206); /*108*/
  _x4204 = kk_std_core_types__new_Optional(_x4205, _ctx); /*optional<108>*/
  _x4192 = kk_std_time_date_show_seconds(_x4193, _x4194, _x4199, _x4204, _ctx); /*string*/
  _x4171 = kk_std_core__lp__plus__plus__1_rp_(_x4192, l, _ctx); /*string*/
  _x4168 = kk_std_core__lp__plus__plus__1_rp_(_x4169, _x4171, _ctx); /*string*/
  return kk_std_core__lp__plus__plus__1_rp_(_x4167, _x4168, _ctx);
}
 
// The time span since 2000-01-01 including time inside a possible leap second.

kk_std_num_ddouble__ddouble kk_std_time_timestamp_unsafe_timespan_withleap(kk_std_time_timestamp__timestamp ts, kk_context_t* _ctx) { /* (ts : timestamp) -> timespan */ 
  kk_std_num_ddouble__ddouble _x4210;
  kk_std_num_ddouble__ddouble _x = ts.since;
  _x4210 = _x; /*std/time/timestamp/timespan*/
  kk_std_num_ddouble__ddouble _x4211;
  kk_integer_t seconds_3832 = kk_std_time_timestamp_leap(ts, _ctx); /*int*/;
  bool _match_3913;
  double _x4212;
  kk_std_core_types__optional _match_3915 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
  if (kk_std_core_types__is_Optional(_match_3915)) {
    kk_box_t _box_x3911 = _match_3915._cons.Optional.value;
    double _frac_1424 = kk_double_unbox(_box_x3911, NULL);
    kk_std_core_types__optional_drop(_match_3915, _ctx);
    _x4212 = _frac_1424; /*double*/
    goto _match4213;
  }
  _x4212 = 0x0p+0; /*double*/
  _match4213: ;
  _match_3913 = (_x4212 == (0x0p+0)); /*bool*/
  if (_match_3913) {
    _x4211 = kk_std_num_ddouble_ddouble_1(seconds_3832, _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    kk_std_num_ddouble__ddouble _x4215 = kk_std_num_ddouble_ddouble_1(seconds_3832, _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble _x4216;
    double _x4217;
    kk_std_core_types__optional _match_3914 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
    if (kk_std_core_types__is_Optional(_match_3914)) {
      kk_box_t _box_x3912 = _match_3914._cons.Optional.value;
      double _frac_14240 = kk_double_unbox(_box_x3912, NULL);
      kk_std_core_types__optional_drop(_match_3914, _ctx);
      _x4217 = _frac_14240; /*double*/
      goto _match4218;
    }
    _x4217 = 0x0p+0; /*double*/
    _match4218: ;
    _x4216 = kk_std_num_ddouble__new_Ddouble(_x4217, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    _x4211 = kk_std_num_ddouble__lp__plus__rp_(_x4215, _x4216, _ctx); /*std/num/ddouble/ddouble*/
  }
  return kk_std_num_ddouble__lp__plus__rp_(_x4210, _x4211, _ctx);
}

// initialization
void kk_std_time_timestamp__init(kk_context_t* _ctx){
  static bool _initialized = false;
  if (_initialized) return;
  _initialized = true;
  kk_std_core_types__init(_ctx);
  kk_std_core__init(_ctx);
  kk_std_num_int32__init(_ctx);
  kk_std_num_ddouble__init(_ctx);
  kk_std_time_date__init(_ctx);
  {
    kk_std_time_timestamp_isolar_secs_per_day = kk_integer_from_int(86400, _ctx); /*int*/
  }
  {
    kk_std_time_timestamp_timespan0 = kk_std_num_ddouble__new_Ddouble(0x0p+0, 0x0p+0, _ctx); /*std/time/timestamp/timespan*/
  }
  {
    bool _match_3923;
    double _x4109;
    kk_std_core_types__optional _match_3925 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
    if (kk_std_core_types__is_Optional(_match_3925)) {
      kk_box_t _box_x3874 = _match_3925._cons.Optional.value;
      double _frac_1424 = kk_double_unbox(_box_x3874, NULL);
      kk_std_core_types__optional_drop(_match_3925, _ctx);
      _x4109 = _frac_1424; /*double*/
      goto _match4110;
    }
    _x4109 = 0x0p+0; /*double*/
    _match4110: ;
    _match_3923 = (_x4109 == (0x0p+0)); /*bool*/
    if (_match_3923) {
      kk_std_time_timestamp_solar_secs_per_day = kk_std_num_ddouble_ddouble_1(kk_integer_from_int(86400, _ctx), _ctx); /*std/time/timestamp/timespan*/
    }
    else {
      kk_std_num_ddouble__ddouble _x4112 = kk_std_num_ddouble_ddouble_1(kk_integer_from_int(86400, _ctx), _ctx); /*std/num/ddouble/ddouble*/
      kk_std_num_ddouble__ddouble _x4113;
      double _x4114;
      kk_std_core_types__optional _match_3924 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
      if (kk_std_core_types__is_Optional(_match_3924)) {
        kk_box_t _box_x3875 = _match_3924._cons.Optional.value;
        double _frac_14240 = kk_double_unbox(_box_x3875, NULL);
        kk_std_core_types__optional_drop(_match_3924, _ctx);
        _x4114 = _frac_14240; /*double*/
        goto _match4115;
      }
      _x4114 = 0x0p+0; /*double*/
      _match4115: ;
      _x4113 = kk_std_num_ddouble__new_Ddouble(_x4114, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
      kk_std_time_timestamp_solar_secs_per_day = kk_std_num_ddouble__lp__plus__rp_(_x4112, _x4113, _ctx); /*std/time/timestamp/timespan*/
    }
  }
  {
    kk_std_num_ddouble__ddouble _x4137 = kk_std_num_ddouble__new_Ddouble(0x0p+0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    kk_std_time_timestamp_timestamp0 = kk_std_time_timestamp__new_Timestamp(_x4137, ((int32_t)0), _ctx); /*std/time/timestamp/timestamp*/
  }
}
