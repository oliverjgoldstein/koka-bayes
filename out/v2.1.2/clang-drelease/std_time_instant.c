// Koka generated module: "std/time/instant", koka version: 2.1.2
#include "std_time_instant.h"


// lift anonymous function
struct kk_std_time_instant__copy_fun5351__t {
  struct kk_function_s _base;
  kk_box_t _fun_unbox_x4755;
};
static kk_std_time_timestamp__timestamp kk_std_time_instant__copy_fun5351(kk_function_t _fself, kk_std_time_duration__duration _b_4758, kk_context_t* _ctx);
static kk_function_t kk_std_time_instant__new_copy_fun5351(kk_box_t _fun_unbox_x4755, kk_context_t* _ctx) {
  struct kk_std_time_instant__copy_fun5351__t* _self = kk_function_alloc_as(struct kk_std_time_instant__copy_fun5351__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_time_instant__copy_fun5351, kk_context());
  _self->_fun_unbox_x4755 = _fun_unbox_x4755;
  return &_self->_base;
}

static kk_std_time_timestamp__timestamp kk_std_time_instant__copy_fun5351(kk_function_t _fself, kk_std_time_duration__duration _b_4758, kk_context_t* _ctx) {
  struct kk_std_time_instant__copy_fun5351__t* _self = kk_function_as(struct kk_std_time_instant__copy_fun5351__t*, _fself);
  kk_box_t _fun_unbox_x4755 = _self->_fun_unbox_x4755; /* 33 */
  kk_drop_match(_self, {kk_box_dup(_fun_unbox_x4755);}, {}, _ctx)
  kk_box_t _x5352;
  kk_function_t _x5353 = kk_function_unbox(_fun_unbox_x4755); /*(4756) -> 4757*/
  _x5352 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x5353, (_x5353, kk_std_time_duration__duration_box(_b_4758, _ctx), _ctx)); /*4757*/
  return kk_std_time_timestamp__timestamp_unbox(_x5352, _ctx);
}


// lift anonymous function
struct kk_std_time_instant__copy_fun5356__t {
  struct kk_function_s _base;
  kk_box_t _fun_unbox_x4762;
};
static kk_std_time_duration__duration kk_std_time_instant__copy_fun5356(kk_function_t _fself, kk_std_time_timestamp__timestamp _b_4765, kk_context_t* _ctx);
static kk_function_t kk_std_time_instant__new_copy_fun5356(kk_box_t _fun_unbox_x4762, kk_context_t* _ctx) {
  struct kk_std_time_instant__copy_fun5356__t* _self = kk_function_alloc_as(struct kk_std_time_instant__copy_fun5356__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_time_instant__copy_fun5356, kk_context());
  _self->_fun_unbox_x4762 = _fun_unbox_x4762;
  return &_self->_base;
}

static kk_std_time_duration__duration kk_std_time_instant__copy_fun5356(kk_function_t _fself, kk_std_time_timestamp__timestamp _b_4765, kk_context_t* _ctx) {
  struct kk_std_time_instant__copy_fun5356__t* _self = kk_function_as(struct kk_std_time_instant__copy_fun5356__t*, _fself);
  kk_box_t _fun_unbox_x4762 = _self->_fun_unbox_x4762; /* 33 */
  kk_drop_match(_self, {kk_box_dup(_fun_unbox_x4762);}, {}, _ctx)
  kk_box_t _x5357;
  kk_function_t _x5358 = kk_function_unbox(_fun_unbox_x4762); /*(4763) -> 4764*/
  _x5357 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x5358, (_x5358, kk_std_time_timestamp__timestamp_box(_b_4765, _ctx), _ctx)); /*4764*/
  return kk_std_time_duration__duration_unbox(_x5357, _ctx);
}

kk_std_time_instant__timescale kk_std_time_instant__copy(kk_std_time_instant__timescale _this, kk_std_core_types__optional name0, kk_std_core_types__optional unit0, kk_std_core_types__optional from_tai0, kk_std_core_types__optional to_tai0, kk_std_core_types__optional mb_seconds_in_day0, kk_std_core_types__optional mb_to_mjd20000, kk_std_core_types__optional mb_from_mjd20000, kk_context_t* _ctx) { /* (timescale, name : optional<string>, unit : optional<string>, from-tai : optional<(std/time/duration/duration) -> std/time/timestamp/timestamp>, to-tai : optional<(std/time/timestamp/timestamp) -> std/time/duration/duration>, mb-seconds-in-day : optional<maybe<(t : std/time/timestamp/timestamp) -> std/time/timestamp/timespan>>, mb-to-mjd2000 : optional<maybe<(t : std/time/timestamp/timestamp, tzdelta : std/time/timestamp/timespan) -> std/num/ddouble/ddouble>>, mb-from-mjd2000 : optional<maybe<(days : int, frac : std/num/ddouble/ddouble) -> std/time/timestamp/timestamp>>) -> timescale */ 
  kk_string_t _x5342;
  if (kk_std_core_types__is_Optional(name0)) {
    kk_box_t _box_x4750 = name0._cons.Optional.value;
    kk_string_t _name_180 = kk_string_unbox(_box_x4750);
    _x5342 = _name_180; /*string*/
    goto _match5343;
  }
  struct kk_std_time_instant_Timescale* _con5345 = kk_std_time_instant__as_Timescale(_this);
  kk_string_t _x = _con5345->name;
  kk_string_dup(_x);
  _x5342 = _x; /*string*/
  _match5343: ;
  kk_string_t _x5346;
  if (kk_std_core_types__is_Optional(unit0)) {
    kk_box_t _box_x4751 = unit0._cons.Optional.value;
    kk_string_t _unit_186 = kk_string_unbox(_box_x4751);
    _x5346 = _unit_186; /*string*/
    goto _match5347;
  }
  struct kk_std_time_instant_Timescale* _con5349 = kk_std_time_instant__as_Timescale(_this);
  kk_string_t _x0 = _con5349->unit;
  kk_string_dup(_x0);
  _x5346 = _x0; /*string*/
  _match5347: ;
  kk_function_t _x5350;
  if (kk_std_core_types__is_Optional(from_tai0)) {
    kk_box_t _fun_unbox_x4755 = from_tai0._cons.Optional.value;
    _x5350 = kk_std_time_instant__new_copy_fun5351(_fun_unbox_x4755, _ctx); /*(std/time/duration/duration) -> std/time/timestamp/timestamp*/
  }
  else {
    struct kk_std_time_instant_Timescale* _con5354 = kk_std_time_instant__as_Timescale(_this);
    kk_function_t _x1 = _con5354->from_tai;
    kk_function_dup(_x1);
    _x5350 = _x1; /*(std/time/duration/duration) -> std/time/timestamp/timestamp*/
  }
  kk_function_t _x5355;
  if (kk_std_core_types__is_Optional(to_tai0)) {
    kk_box_t _fun_unbox_x4762 = to_tai0._cons.Optional.value;
    _x5355 = kk_std_time_instant__new_copy_fun5356(_fun_unbox_x4762, _ctx); /*(std/time/timestamp/timestamp) -> std/time/duration/duration*/
  }
  else {
    struct kk_std_time_instant_Timescale* _con5359 = kk_std_time_instant__as_Timescale(_this);
    kk_function_t _x2 = _con5359->to_tai;
    kk_function_dup(_x2);
    _x5355 = _x2; /*(std/time/timestamp/timestamp) -> std/time/duration/duration*/
  }
  kk_std_core_types__maybe _x5360;
  if (kk_std_core_types__is_Optional(mb_seconds_in_day0)) {
    kk_box_t _box_x4766 = mb_seconds_in_day0._cons.Optional.value;
    kk_std_core_types__maybe _mb_seconds_in_day_206 = kk_std_core_types__maybe_unbox(_box_x4766, NULL);
    _x5360 = _mb_seconds_in_day_206; /*maybe<(t : std/time/timestamp/timestamp) -> std/time/timestamp/timespan>*/
    goto _match5361;
  }
  struct kk_std_time_instant_Timescale* _con5363 = kk_std_time_instant__as_Timescale(_this);
  kk_std_core_types__maybe _x3 = _con5363->mb_seconds_in_day;
  kk_std_core_types__maybe_dup(_x3);
  _x5360 = _x3; /*maybe<(t : std/time/timestamp/timestamp) -> std/time/timestamp/timespan>*/
  _match5361: ;
  kk_std_core_types__maybe _x5364;
  if (kk_std_core_types__is_Optional(mb_to_mjd20000)) {
    kk_box_t _box_x4767 = mb_to_mjd20000._cons.Optional.value;
    kk_std_core_types__maybe _mb_to_mjd2000_212 = kk_std_core_types__maybe_unbox(_box_x4767, NULL);
    _x5364 = _mb_to_mjd2000_212; /*maybe<(t : std/time/timestamp/timestamp, tzdelta : std/time/timestamp/timespan) -> std/num/ddouble/ddouble>*/
    goto _match5365;
  }
  struct kk_std_time_instant_Timescale* _con5367 = kk_std_time_instant__as_Timescale(_this);
  kk_std_core_types__maybe _x4 = _con5367->mb_to_mjd2000;
  kk_std_core_types__maybe_dup(_x4);
  _x5364 = _x4; /*maybe<(t : std/time/timestamp/timestamp, tzdelta : std/time/timestamp/timespan) -> std/num/ddouble/ddouble>*/
  _match5365: ;
  kk_std_core_types__maybe _x5368;
  if (kk_std_core_types__is_Optional(mb_from_mjd20000)) {
    kk_box_t _box_x4768 = mb_from_mjd20000._cons.Optional.value;
    kk_std_core_types__maybe _mb_from_mjd2000_218 = kk_std_core_types__maybe_unbox(_box_x4768, NULL);
    kk_std_time_instant__timescale_dropn(_this, ((int32_t)10), _ctx);
    _x5368 = _mb_from_mjd2000_218; /*maybe<(days : int, frac : std/num/ddouble/ddouble) -> std/time/timestamp/timestamp>*/
    goto _match5369;
  }
  struct kk_std_time_instant_Timescale* _con5371 = kk_std_time_instant__as_Timescale(_this);
  kk_string_t _pat06 = _con5371->name;
  kk_string_t _pat19 = _con5371->unit;
  kk_function_t _pat26 = _con5371->from_tai;
  kk_function_t _pat36 = _con5371->to_tai;
  kk_std_core_types__maybe _pat46 = _con5371->mb_seconds_in_day;
  kk_std_core_types__maybe _pat56 = _con5371->mb_to_mjd2000;
  kk_std_core_types__maybe _x5 = _con5371->mb_from_mjd2000;
  if (kk_std_time_instant__timescale_is_unique(_this)) {
    kk_std_core_types__maybe_drop(_pat56, _ctx);
    kk_std_core_types__maybe_drop(_pat46, _ctx);
    kk_function_drop(_pat36, _ctx);
    kk_function_drop(_pat26, _ctx);
    kk_string_drop(_pat19, _ctx);
    kk_string_drop(_pat06, _ctx);
    kk_std_time_instant__timescale_free(_this);
  }
  else {
    kk_std_core_types__maybe_dup(_x5);
    kk_std_time_instant__timescale_decref(_this, _ctx);
  }
  _x5368 = _x5; /*maybe<(days : int, frac : std/num/ddouble/ddouble) -> std/time/timestamp/timestamp>*/
  _match5369: ;
  return kk_std_time_instant__new_Timescale(kk_reuse_null, _x5342, _x5346, _x5350, _x5355, _x5360, _x5364, _x5368, _ctx);
}

kk_std_time_instant__instant kk_std_time_instant__copy_1(kk_std_time_instant__instant _this, kk_std_core_types__optional since0, kk_std_core_types__optional ts0, kk_context_t* _ctx) { /* (instant, since : optional<std/time/timestamp/timestamp>, ts : optional<timescale>) -> instant */ 
  kk_std_time_timestamp__timestamp _x5376;
  if (kk_std_core_types__is_Optional(since0)) {
    kk_box_t _box_x4769 = since0._cons.Optional.value;
    kk_std_time_timestamp__timestamp _since_251 = kk_std_time_timestamp__timestamp_unbox(_box_x4769, NULL);
    _x5376 = _since_251; /*std/time/timestamp/timestamp*/
    goto _match5377;
  }
  struct kk_std_time_instant_Instant* _con5379 = kk_std_time_instant__as_Instant(_this);
  kk_std_time_timestamp__timestamp _x = _con5379->since;
  kk_std_time_instant__timescale _pat2 = _con5379->ts;
  struct kk_std_time_instant_Timescale* _con5380 = kk_std_time_instant__as_Timescale(_pat2);
  _x5376 = _x; /*std/time/timestamp/timestamp*/
  _match5377: ;
  kk_std_time_instant__timescale _x5381;
  if (kk_std_core_types__is_Optional(ts0)) {
    kk_box_t _box_x4770 = ts0._cons.Optional.value;
    kk_std_time_instant__timescale _ts_257 = kk_std_time_instant__timescale_unbox(_box_x4770, NULL);
    kk_std_time_instant__instant_dropn(_this, ((int32_t)1), _ctx);
    _x5381 = _ts_257; /*std/time/instant/timescale*/
    goto _match5382;
  }
  struct kk_std_time_instant_Instant* _con5384 = kk_std_time_instant__as_Instant(_this);
  kk_std_time_timestamp__timestamp _pat01 = _con5384->since;
  kk_std_time_instant__timescale _x0 = _con5384->ts;
  struct kk_std_time_instant_Timescale* _con5385 = kk_std_time_instant__as_Timescale(_x0);
  if (kk_std_time_instant__instant_is_unique(_this)) {
    kk_std_time_instant__instant_free(_this);
  }
  else {
    kk_std_time_instant__timescale_dup(_x0);
    kk_std_time_instant__instant_decref(_this, _ctx);
  }
  _x5381 = _x0; /*std/time/instant/timescale*/
  _match5382: ;
  return kk_std_time_instant__new_Instant(kk_reuse_null, _x5376, _x5381, _ctx);
}
 
// Return `:timestamp` since 2000-01-01 in the time scale of the instant

kk_std_time_timestamp__timestamp kk_std_time_instant_timestamp(kk_std_time_instant__instant i, kk_context_t* _ctx) { /* (i : instant) -> std/time/timestamp/timestamp */ 
  struct kk_std_time_instant_Instant* _con5386 = kk_std_time_instant__as_Instant(i);
  kk_std_time_timestamp__timestamp _x = _con5386->since;
  kk_std_time_instant__timescale _pat2 = _con5386->ts;
  struct kk_std_time_instant_Timescale* _con5387 = kk_std_time_instant__as_Timescale(_pat2);
  kk_string_t _pat3 = _con5387->name;
  kk_string_t _pat4 = _con5387->unit;
  kk_function_t _pat5 = _con5387->from_tai;
  kk_function_t _pat6 = _con5387->to_tai;
  kk_std_core_types__maybe _pat7 = _con5387->mb_seconds_in_day;
  kk_std_core_types__maybe _pat8 = _con5387->mb_to_mjd2000;
  kk_std_core_types__maybe _pat9 = _con5387->mb_from_mjd2000;
  if (kk_std_time_instant__instant_is_unique(i)) {
    if (kk_std_time_instant__timescale_is_unique(_pat2)) {
      kk_string_drop(_pat3, _ctx);
      kk_string_drop(_pat4, _ctx);
      kk_function_drop(_pat5, _ctx);
      kk_function_drop(_pat6, _ctx);
      kk_std_core_types__maybe_drop(_pat7, _ctx);
      kk_std_core_types__maybe_drop(_pat8, _ctx);
      kk_std_core_types__maybe_drop(_pat9, _ctx);
      kk_std_time_instant__timescale_free(_pat2);
    }
    else {
      kk_std_time_instant__timescale_decref(_pat2, _ctx);
    }
    kk_std_time_instant__instant_free(i);
  }
  else {
    kk_std_time_instant__instant_decref(i, _ctx);
  }
  return _x;
}
 
// Does this timescale have leap seconds?

bool kk_std_time_instant_has_leap_seconds(kk_std_time_instant__timescale ts0, kk_context_t* _ctx) { /* (ts : timescale) -> bool */ 
  kk_std_core_types__maybe _match_5334;
  struct kk_std_time_instant_Timescale* _con5388 = kk_std_time_instant__as_Timescale(ts0);
  kk_string_t _pat00 = _con5388->name;
  kk_string_t _pat10 = _con5388->unit;
  kk_function_t _pat2 = _con5388->from_tai;
  kk_function_t _pat3 = _con5388->to_tai;
  kk_std_core_types__maybe _x = _con5388->mb_seconds_in_day;
  kk_std_core_types__maybe _pat4 = _con5388->mb_to_mjd2000;
  kk_std_core_types__maybe _pat5 = _con5388->mb_from_mjd2000;
  if (kk_std_time_instant__timescale_is_unique(ts0)) {
    kk_std_core_types__maybe_drop(_pat5, _ctx);
    kk_std_core_types__maybe_drop(_pat4, _ctx);
    kk_function_drop(_pat3, _ctx);
    kk_function_drop(_pat2, _ctx);
    kk_string_drop(_pat10, _ctx);
    kk_string_drop(_pat00, _ctx);
    kk_std_time_instant__timescale_free(ts0);
  }
  else {
    kk_std_core_types__maybe_dup(_x);
    kk_std_time_instant__timescale_decref(ts0, _ctx);
  }
  _match_5334 = _x; /*maybe<(t : std/time/timestamp/timestamp) -> std/time/timestamp/timespan>*/
  if (kk_std_core_types__is_Nothing(_match_5334)) {
    return false;
  }
  kk_std_core_types__maybe_drop(_match_5334, _ctx);
  return true;
}
 
// relative to the MJD epoch

kk_std_num_ddouble__ddouble kk_std_time_instant_mjd_epoch_delta;

kk_std_num_ddouble__ddouble kk_std_time_instant_jd_epoch_delta;
 
// The seconds in the day of instant `i` (in its time scale).

kk_std_num_ddouble__ddouble kk_std_time_instant_seconds_in_day(kk_std_time_instant__instant i, kk_context_t* _ctx) { /* (i : instant) -> std/time/timestamp/timespan */ 
  kk_std_core_types__maybe _match_5329;
  kk_std_time_instant__timescale _match_5330;
  struct kk_std_time_instant_Instant* _con5399 = kk_std_time_instant__as_Instant(i);
  kk_std_time_timestamp__timestamp _pat00 = _con5399->since;
  kk_std_time_instant__timescale _x0 = _con5399->ts;
  struct kk_std_time_instant_Timescale* _con5400 = kk_std_time_instant__as_Timescale(_x0);
  kk_std_time_instant__timescale_dup(_x0);
  _match_5330 = _x0; /*std/time/instant/timescale*/
  struct kk_std_time_instant_Timescale* _con5401 = kk_std_time_instant__as_Timescale(_match_5330);
  kk_string_t _pat0 = _con5401->name;
  kk_string_t _pat1 = _con5401->unit;
  kk_function_t _pat2 = _con5401->from_tai;
  kk_function_t _pat3 = _con5401->to_tai;
  kk_std_core_types__maybe _x = _con5401->mb_seconds_in_day;
  kk_std_core_types__maybe _pat4 = _con5401->mb_to_mjd2000;
  kk_std_core_types__maybe _pat5 = _con5401->mb_from_mjd2000;
  if (kk_std_time_instant__timescale_is_unique(_match_5330)) {
    kk_std_core_types__maybe_drop(_pat5, _ctx);
    kk_std_core_types__maybe_drop(_pat4, _ctx);
    kk_function_drop(_pat3, _ctx);
    kk_function_drop(_pat2, _ctx);
    kk_string_drop(_pat1, _ctx);
    kk_string_drop(_pat0, _ctx);
    kk_std_time_instant__timescale_free(_match_5330);
  }
  else {
    kk_std_core_types__maybe_dup(_x);
    kk_std_time_instant__timescale_decref(_match_5330, _ctx);
  }
  _match_5329 = _x; /*maybe<(t : std/time/timestamp/timestamp) -> std/time/timestamp/timespan>*/
  if (kk_std_core_types__is_Nothing(_match_5329)) {
    kk_std_time_instant__instant_dropn(i, ((int32_t)1), _ctx);
    return kk_std_time_timestamp_solar_secs_per_day;
  }
  kk_box_t _fun_unbox_x4776 = _match_5329._cons.Just.value;
  kk_box_t _x5402;
  kk_function_t _x5407 = kk_function_unbox(_fun_unbox_x4776); /*(t : 4777) -> 4778*/
  kk_box_t _x5403;
  kk_std_time_timestamp__timestamp _x5404;
  struct kk_std_time_instant_Instant* _con5405 = kk_std_time_instant__as_Instant(i);
  kk_std_time_timestamp__timestamp _x1 = _con5405->since;
  kk_std_time_instant__timescale _pat21 = _con5405->ts;
  struct kk_std_time_instant_Timescale* _con5406 = kk_std_time_instant__as_Timescale(_pat21);
  kk_string_t _pat31 = _con5406->name;
  kk_string_t _pat41 = _con5406->unit;
  kk_function_t _pat51 = _con5406->from_tai;
  kk_function_t _pat61 = _con5406->to_tai;
  kk_std_core_types__maybe _pat70 = _con5406->mb_seconds_in_day;
  kk_std_core_types__maybe _pat80 = _con5406->mb_to_mjd2000;
  kk_std_core_types__maybe _pat90 = _con5406->mb_from_mjd2000;
  if (kk_std_time_instant__instant_is_unique(i)) {
    if (kk_std_time_instant__timescale_is_unique(_pat21)) {
      kk_string_drop(_pat31, _ctx);
      kk_string_drop(_pat41, _ctx);
      kk_function_drop(_pat51, _ctx);
      kk_function_drop(_pat61, _ctx);
      kk_std_core_types__maybe_drop(_pat70, _ctx);
      kk_std_core_types__maybe_drop(_pat80, _ctx);
      kk_std_core_types__maybe_drop(_pat90, _ctx);
      kk_std_time_instant__timescale_free(_pat21);
    }
    else {
      kk_std_time_instant__timescale_decref(_pat21, _ctx);
    }
    kk_std_time_instant__instant_free(i);
  }
  else {
    kk_std_time_instant__instant_decref(i, _ctx);
  }
  _x5404 = _x1; /*std/time/timestamp/timestamp*/
  _x5403 = kk_std_time_timestamp__timestamp_box(_x5404, _ctx); /*4777*/
  _x5402 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x5407, (_x5407, _x5403, _ctx)); /*4778*/
  return kk_std_num_ddouble__ddouble_unbox(_x5402, _ctx);
}
 
// Create a new time scale given `name`, two inverse function `from-tai` and `to-tai`,
// and an optional function that returns the seconds in the day of the instant.
// The time unit defaults to `name`.

kk_std_time_instant__timescale kk_std_time_instant_timescale_1(kk_string_t name0, kk_function_t from_tai0, kk_function_t to_tai0, kk_std_core_types__optional unit0, kk_std_core_types__optional seconds_in_day0, kk_std_core_types__optional to_mjd2000, kk_std_core_types__optional from_mjd2000, kk_context_t* _ctx) { /* (name : string, from-tai : (std/time/duration/duration) -> std/time/timestamp/timestamp, to-tai : (std/time/timestamp/timestamp) -> std/time/duration/duration, unit : optional<string>, seconds-in-day : optional<maybe<(std/time/timestamp/timestamp) -> std/time/timestamp/timespan>>, to-mjd2000 : optional<maybe<(t : std/time/timestamp/timestamp, tzdelta : std/time/timestamp/timespan) -> std/num/ddouble/ddouble>>, from-mjd2000 : optional<maybe<(days : int, frac : std/num/ddouble/ddouble) -> std/time/timestamp/timestamp>>) -> timescale */ 
  kk_string_t _x5419 = kk_string_dup(name0); /*string*/
  kk_string_t _x5420;
  if (kk_std_core_types__is_Optional(unit0)) {
    kk_box_t _box_x4784 = unit0._cons.Optional.value;
    kk_string_t _unit_366 = kk_string_unbox(_box_x4784);
    kk_string_drop(name0, _ctx);
    _x5420 = _unit_366; /*string*/
    goto _match5421;
  }
  _x5420 = name0; /*string*/
  _match5421: ;
  kk_std_core_types__maybe _x5423;
  if (kk_std_core_types__is_Optional(seconds_in_day0)) {
    kk_box_t _box_x4785 = seconds_in_day0._cons.Optional.value;
    kk_std_core_types__maybe _seconds_in_day_371 = kk_std_core_types__maybe_unbox(_box_x4785, NULL);
    _x5423 = _seconds_in_day_371; /*maybe<(std/time/timestamp/timestamp) -> std/time/timestamp/timespan>*/
    goto _match5424;
  }
  _x5423 = kk_std_core_types__new_Nothing(_ctx); /*maybe<(std/time/timestamp/timestamp) -> std/time/timestamp/timespan>*/
  _match5424: ;
  kk_std_core_types__maybe _x5426;
  if (kk_std_core_types__is_Optional(to_mjd2000)) {
    kk_box_t _box_x4786 = to_mjd2000._cons.Optional.value;
    kk_std_core_types__maybe _to_mjd2000_376 = kk_std_core_types__maybe_unbox(_box_x4786, NULL);
    _x5426 = _to_mjd2000_376; /*maybe<(t : std/time/timestamp/timestamp, tzdelta : std/time/timestamp/timespan) -> std/num/ddouble/ddouble>*/
    goto _match5427;
  }
  _x5426 = kk_std_core_types__new_Nothing(_ctx); /*maybe<(t : std/time/timestamp/timestamp, tzdelta : std/time/timestamp/timespan) -> std/num/ddouble/ddouble>*/
  _match5427: ;
  kk_std_core_types__maybe _x5429;
  if (kk_std_core_types__is_Optional(from_mjd2000)) {
    kk_box_t _box_x4787 = from_mjd2000._cons.Optional.value;
    kk_std_core_types__maybe _from_mjd2000_381 = kk_std_core_types__maybe_unbox(_box_x4787, NULL);
    _x5429 = _from_mjd2000_381; /*maybe<(days : int, frac : std/num/ddouble/ddouble) -> std/time/timestamp/timestamp>*/
    goto _match5430;
  }
  _x5429 = kk_std_core_types__new_Nothing(_ctx); /*maybe<(days : int, frac : std/num/ddouble/ddouble) -> std/time/timestamp/timestamp>*/
  _match5430: ;
  return kk_std_time_instant__new_Timescale(kk_reuse_null, _x5419, _x5420, from_tai0, to_tai0, _x5423, _x5426, _x5429, _ctx);
}
 
// Create a new time scale based on SI seconds (as measured on the Earth's geoid) with a given
//  `name`, a fixed `offset` (=`duration0`) from TAI (e.g. GPS = TAI - 19), and
// a `epoch-y2k` (= `timestamp0`) which is the timestamp of the 2000-01-01 date in that timescale
// e.g. for a timescale `ts`:
// `epoch-y2k = instant(2000,1,1,cal=iso-calendar(ts)).since-in(ts)`


// lift anonymous function
struct kk_std_time_instant_tai_timescale_fun5441__t {
  struct kk_function_s _base;
  kk_std_time_duration__duration _offset_990;
};
static kk_std_time_timestamp__timestamp kk_std_time_instant_tai_timescale_fun5441(kk_function_t _fself, kk_std_time_duration__duration tai, kk_context_t* _ctx);
static kk_function_t kk_std_time_instant_new_tai_timescale_fun5441(kk_std_time_duration__duration _offset_990, kk_context_t* _ctx) {
  struct kk_std_time_instant_tai_timescale_fun5441__t* _self = kk_function_alloc_as(struct kk_std_time_instant_tai_timescale_fun5441__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_time_instant_tai_timescale_fun5441, kk_context());
  _self->_offset_990 = _offset_990;
  return &_self->_base;
}

static kk_std_time_timestamp__timestamp kk_std_time_instant_tai_timescale_fun5441(kk_function_t _fself, kk_std_time_duration__duration tai, kk_context_t* _ctx) {
  struct kk_std_time_instant_tai_timescale_fun5441__t* _self = kk_function_as(struct kk_std_time_instant_tai_timescale_fun5441__t*, _fself);
  kk_std_time_duration__duration _offset_990 = _self->_offset_990; /* std/time/duration/duration */
  kk_drop_match(_self, {kk_std_time_duration__duration_dup(_offset_990);}, {}, _ctx)
  kk_std_num_ddouble__ddouble t_4479;
  kk_std_num_ddouble__ddouble _x5442;
  kk_std_num_ddouble__ddouble _x0 = tai.secs;
  _x5442 = _x0; /*std/time/timestamp/timespan*/
  kk_std_num_ddouble__ddouble _x5443;
  kk_std_num_ddouble__ddouble _x = _offset_990.secs;
  _x5443 = _x; /*std/time/timestamp/timespan*/
  t_4479 = kk_std_num_ddouble__lp__plus__rp_(_x5442, _x5443, _ctx); /*std/time/timestamp/timespan*/
  int32_t _x5444;
  kk_integer_t _x5445;
  kk_std_core_types__optional _x5446 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/
  if (kk_std_core_types__is_Optional(_x5446)) {
    kk_box_t _box_x4792 = _x5446._cons.Optional.value;
    kk_integer_t _leap_492 = kk_integer_unbox(_box_x4792);
    _x5445 = _leap_492; /*int*/
    goto _match5447;
  }
  _x5445 = kk_integer_from_small(0); /*int*/
  _match5447: ;
  _x5444 = kk_std_core_int32(_x5445, _ctx); /*int32*/
  return kk_std_time_timestamp__new_Timestamp(t_4479, _x5444, _ctx);
}


// lift anonymous function
struct kk_std_time_instant_tai_timescale_fun5449__t {
  struct kk_function_s _base;
  kk_std_time_duration__duration _offset_990;
};
static kk_std_time_duration__duration kk_std_time_instant_tai_timescale_fun5449(kk_function_t _fself, kk_std_time_timestamp__timestamp t0, kk_context_t* _ctx);
static kk_function_t kk_std_time_instant_new_tai_timescale_fun5449(kk_std_time_duration__duration _offset_990, kk_context_t* _ctx) {
  struct kk_std_time_instant_tai_timescale_fun5449__t* _self = kk_function_alloc_as(struct kk_std_time_instant_tai_timescale_fun5449__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_time_instant_tai_timescale_fun5449, kk_context());
  _self->_offset_990 = _offset_990;
  return &_self->_base;
}

static kk_std_time_duration__duration kk_std_time_instant_tai_timescale_fun5449(kk_function_t _fself, kk_std_time_timestamp__timestamp t0, kk_context_t* _ctx) {
  struct kk_std_time_instant_tai_timescale_fun5449__t* _self = kk_function_as(struct kk_std_time_instant_tai_timescale_fun5449__t*, _fself);
  kk_std_time_duration__duration _offset_990 = _self->_offset_990; /* std/time/duration/duration */
  kk_drop_match(_self, {kk_std_time_duration__duration_dup(_offset_990);}, {}, _ctx)
  kk_std_time_timestamp__timestamp t1_4482;
  kk_std_num_ddouble__ddouble _x5450;
  kk_std_num_ddouble__ddouble _x1 = _offset_990.secs;
  _x5450 = _x1; /*std/time/timestamp/timespan*/
  t1_4482 = kk_std_time_timestamp__lp__dash__rp_(t0, _x5450, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_num_ddouble__ddouble _x5451 = kk_std_time_timestamp_unsafe_timespan_withleap(t1_4482, _ctx); /*std/time/timestamp/timespan*/
  return kk_std_time_duration__new_Duration(_x5451, _ctx);
}

kk_std_time_instant__timescale kk_std_time_instant_tai_timescale(kk_string_t name0, kk_std_core_types__optional offset, kk_context_t* _ctx) { /* (name : string, offset : optional<std/time/duration/duration>) -> timescale */ 
  kk_std_time_duration__duration _offset_990;
  if (kk_std_core_types__is_Optional(offset)) {
    kk_box_t _box_x4788 = offset._cons.Optional.value;
    kk_std_time_duration__duration _offset_991 = kk_std_time_duration__duration_unbox(_box_x4788, NULL);
    _offset_990 = _offset_991; /*std/time/duration/duration*/
    goto _match5432;
  }
  _offset_990 = kk_std_time_duration_duration_1(kk_integer_from_small(0), kk_std_core_types__new_None(_ctx), _ctx); /*std/time/duration/duration*/
  _match5432: ;
  kk_std_core_types__optional unit_4475;
  kk_box_t _x5434;
  kk_string_t _x5435;
  kk_define_string_literal(, _s5436, 3, "TAI")
  _x5435 = kk_string_dup(_s5436); /*string*/
  _x5434 = kk_string_box(_x5435); /*35*/
  unit_4475 = kk_std_core_types__new_Optional(_x5434, _ctx); /*optional<string>*/
  kk_string_t _x5437 = kk_string_dup(name0); /*string*/
  kk_string_t _x5438;
  if (kk_std_core_types__is_Optional(unit_4475)) {
    kk_box_t _box_x4791 = unit_4475._cons.Optional.value;
    kk_string_t _unit_366 = kk_string_unbox(_box_x4791);
    kk_string_drop(name0, _ctx);
    _x5438 = _unit_366; /*string*/
    goto _match5439;
  }
  _x5438 = name0; /*string*/
  _match5439: ;
  kk_std_core_types__maybe _x5452;
  kk_std_core_types__optional _x5453 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/
  if (kk_std_core_types__is_Optional(_x5453)) {
    kk_box_t _box_x4793 = _x5453._cons.Optional.value;
    kk_std_core_types__maybe _seconds_in_day_371 = kk_std_core_types__maybe_unbox(_box_x4793, NULL);
    _x5452 = _seconds_in_day_371; /*maybe<(std/time/timestamp/timestamp) -> std/time/timestamp/timespan>*/
    goto _match5454;
  }
  _x5452 = kk_std_core_types__new_Nothing(_ctx); /*maybe<(std/time/timestamp/timestamp) -> std/time/timestamp/timespan>*/
  _match5454: ;
  kk_std_core_types__maybe _x5456;
  kk_std_core_types__optional _x5457 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/
  if (kk_std_core_types__is_Optional(_x5457)) {
    kk_box_t _box_x4794 = _x5457._cons.Optional.value;
    kk_std_core_types__maybe _to_mjd2000_376 = kk_std_core_types__maybe_unbox(_box_x4794, NULL);
    _x5456 = _to_mjd2000_376; /*maybe<(t : std/time/timestamp/timestamp, tzdelta : std/time/timestamp/timespan) -> std/num/ddouble/ddouble>*/
    goto _match5458;
  }
  _x5456 = kk_std_core_types__new_Nothing(_ctx); /*maybe<(t : std/time/timestamp/timestamp, tzdelta : std/time/timestamp/timespan) -> std/num/ddouble/ddouble>*/
  _match5458: ;
  kk_std_core_types__maybe _x5460;
  kk_std_core_types__optional _x5461 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/
  if (kk_std_core_types__is_Optional(_x5461)) {
    kk_box_t _box_x4795 = _x5461._cons.Optional.value;
    kk_std_core_types__maybe _from_mjd2000_381 = kk_std_core_types__maybe_unbox(_box_x4795, NULL);
    _x5460 = _from_mjd2000_381; /*maybe<(days : int, frac : std/num/ddouble/ddouble) -> std/time/timestamp/timestamp>*/
    goto _match5462;
  }
  _x5460 = kk_std_core_types__new_Nothing(_ctx); /*maybe<(days : int, frac : std/num/ddouble/ddouble) -> std/time/timestamp/timestamp>*/
  _match5462: ;
  return kk_std_time_instant__new_Timescale(kk_reuse_null, _x5437, _x5438, kk_std_time_instant_new_tai_timescale_fun5441(_offset_990, _ctx), kk_std_time_instant_new_tai_timescale_fun5449(_offset_990, _ctx), _x5452, _x5456, _x5460, _ctx);
}
 
// The [TAI](https://en.wikipedia.org/wiki/International_Atomic_Time) (International atomic time)
// time scale is based on SI seconds measured on the Earth's geoid, with a 2000-01-01 TAI `epoch`.


// lift anonymous function
struct kk_std_time_instant_ts_tai_fun5476__t {
  struct kk_function_s _base;
  kk_std_time_duration__duration _offset_990;
};
static kk_std_time_timestamp__timestamp kk_std_time_instant_ts_tai_fun5476(kk_function_t _fself, kk_std_time_duration__duration tai, kk_context_t* _ctx);
static kk_function_t kk_std_time_instant_new_ts_tai_fun5476(kk_std_time_duration__duration _offset_990, kk_context_t* _ctx) {
  struct kk_std_time_instant_ts_tai_fun5476__t* _self = kk_function_alloc_as(struct kk_std_time_instant_ts_tai_fun5476__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_time_instant_ts_tai_fun5476, kk_context());
  _self->_offset_990 = _offset_990;
  return &_self->_base;
}

static kk_std_time_timestamp__timestamp kk_std_time_instant_ts_tai_fun5476(kk_function_t _fself, kk_std_time_duration__duration tai, kk_context_t* _ctx) {
  struct kk_std_time_instant_ts_tai_fun5476__t* _self = kk_function_as(struct kk_std_time_instant_ts_tai_fun5476__t*, _fself);
  kk_std_time_duration__duration _offset_990 = _self->_offset_990; /* std/time/duration/duration */
  kk_drop_match(_self, {kk_std_time_duration__duration_dup(_offset_990);}, {}, _ctx)
  kk_std_num_ddouble__ddouble t_4493;
  kk_std_num_ddouble__ddouble _x5477;
  kk_std_num_ddouble__ddouble _x0 = tai.secs;
  _x5477 = _x0; /*std/time/timestamp/timespan*/
  kk_std_num_ddouble__ddouble _x5478;
  kk_std_num_ddouble__ddouble _x = _offset_990.secs;
  _x5478 = _x; /*std/time/timestamp/timespan*/
  t_4493 = kk_std_num_ddouble__lp__plus__rp_(_x5477, _x5478, _ctx); /*std/time/timestamp/timespan*/
  int32_t _x5479;
  kk_integer_t _x5480;
  kk_std_core_types__optional _x5481 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/
  if (kk_std_core_types__is_Optional(_x5481)) {
    kk_box_t _box_x4800 = _x5481._cons.Optional.value;
    kk_integer_t _leap_492 = kk_integer_unbox(_box_x4800);
    _x5480 = _leap_492; /*int*/
    goto _match5482;
  }
  _x5480 = kk_integer_from_small(0); /*int*/
  _match5482: ;
  _x5479 = kk_std_core_int32(_x5480, _ctx); /*int32*/
  return kk_std_time_timestamp__new_Timestamp(t_4493, _x5479, _ctx);
}


// lift anonymous function
struct kk_std_time_instant_ts_tai_fun5484__t {
  struct kk_function_s _base;
  kk_std_time_duration__duration _offset_990;
};
static kk_std_time_duration__duration kk_std_time_instant_ts_tai_fun5484(kk_function_t _fself, kk_std_time_timestamp__timestamp t0, kk_context_t* _ctx);
static kk_function_t kk_std_time_instant_new_ts_tai_fun5484(kk_std_time_duration__duration _offset_990, kk_context_t* _ctx) {
  struct kk_std_time_instant_ts_tai_fun5484__t* _self = kk_function_alloc_as(struct kk_std_time_instant_ts_tai_fun5484__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_time_instant_ts_tai_fun5484, kk_context());
  _self->_offset_990 = _offset_990;
  return &_self->_base;
}

static kk_std_time_duration__duration kk_std_time_instant_ts_tai_fun5484(kk_function_t _fself, kk_std_time_timestamp__timestamp t0, kk_context_t* _ctx) {
  struct kk_std_time_instant_ts_tai_fun5484__t* _self = kk_function_as(struct kk_std_time_instant_ts_tai_fun5484__t*, _fself);
  kk_std_time_duration__duration _offset_990 = _self->_offset_990; /* std/time/duration/duration */
  kk_drop_match(_self, {kk_std_time_duration__duration_dup(_offset_990);}, {}, _ctx)
  kk_std_time_timestamp__timestamp t1_4496;
  kk_std_num_ddouble__ddouble _x5485;
  kk_std_num_ddouble__ddouble _x1 = _offset_990.secs;
  _x5485 = _x1; /*std/time/timestamp/timespan*/
  t1_4496 = kk_std_time_timestamp__lp__dash__rp_(t0, _x5485, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_num_ddouble__ddouble _x5486 = kk_std_time_timestamp_unsafe_timespan_withleap(t1_4496, _ctx); /*std/time/timestamp/timespan*/
  return kk_std_time_duration__new_Duration(_x5486, _ctx);
}

kk_std_time_instant__timescale kk_std_time_instant_ts_tai;
 
// Add a time span to an instant in time.
// This is only safe if the time unit of the timespan is the
// same as that of the instant.

kk_std_time_instant__instant kk_std_time_instant_unsafe_add(kk_std_time_instant__instant i, kk_std_num_ddouble__ddouble tspan, kk_context_t* _ctx) { /* (i : instant, tspan : std/time/timestamp/timespan) -> instant */ 
  kk_std_time_timestamp__timestamp _x5499;
  kk_std_num_ddouble__ddouble _x5500;
  kk_std_num_ddouble__ddouble _x5501;
  kk_std_time_timestamp__timestamp _match_5319;
  struct kk_std_time_instant_Instant* _con5502 = kk_std_time_instant__as_Instant(i);
  kk_std_time_timestamp__timestamp _x1 = _con5502->since;
  kk_std_time_instant__timescale _pat21 = _con5502->ts;
  struct kk_std_time_instant_Timescale* _con5503 = kk_std_time_instant__as_Timescale(_pat21);
  _match_5319 = _x1; /*std/time/timestamp/timestamp*/
  kk_std_num_ddouble__ddouble _x = _match_5319.since;
  _x5501 = _x; /*std/time/timestamp/timespan*/
  _x5500 = kk_std_num_ddouble__lp__plus__rp_(_x5501, tspan, _ctx); /*std/num/ddouble/ddouble*/
  int32_t _x5504;
  kk_std_time_timestamp__timestamp _match_5318;
  struct kk_std_time_instant_Instant* _con5505 = kk_std_time_instant__as_Instant(i);
  kk_std_time_timestamp__timestamp _x10 = _con5505->since;
  kk_std_time_instant__timescale _pat210 = _con5505->ts;
  struct kk_std_time_instant_Timescale* _con5506 = kk_std_time_instant__as_Timescale(_pat210);
  _match_5318 = _x10; /*std/time/timestamp/timestamp*/
  kk_std_num_ddouble__ddouble _pat00 = _match_5318.since;
  int32_t _x0 = _match_5318.leap32;
  _x5504 = _x0; /*int32*/
  _x5499 = kk_std_time_timestamp__new_Timestamp(_x5500, _x5504, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_time_instant__timescale _x5507;
  struct kk_std_time_instant_Instant* _con5508 = kk_std_time_instant__as_Instant(i);
  kk_std_time_timestamp__timestamp _pat02 = _con5508->since;
  kk_std_time_instant__timescale _x2 = _con5508->ts;
  struct kk_std_time_instant_Timescale* _con5509 = kk_std_time_instant__as_Timescale(_x2);
  if (kk_std_time_instant__instant_is_unique(i)) {
    kk_std_time_instant__instant_free(i);
  }
  else {
    kk_std_time_instant__timescale_dup(_x2);
    kk_std_time_instant__instant_decref(i, _ctx);
  }
  _x5507 = _x2; /*std/time/instant/timescale*/
  return kk_std_time_instant__new_Instant(kk_reuse_null, _x5499, _x5507, _ctx);
}
 
// Convert a timespan between time scales

kk_std_time_timestamp__timestamp kk_std_time_instant_convert(kk_std_time_timestamp__timestamp t, kk_std_time_instant__timescale from, kk_std_time_instant__timescale to, kk_context_t* _ctx) { /* (t : std/time/timestamp/timestamp, from : timescale, to : timescale) -> std/time/timestamp/timestamp */ 
  bool _match_5315;
  kk_string_t _x5510;
  struct kk_std_time_instant_Timescale* _con5511 = kk_std_time_instant__as_Timescale(from);
  kk_string_t _x = _con5511->name;
  kk_string_dup(_x);
  _x5510 = _x; /*string*/
  kk_string_t _x5512;
  struct kk_std_time_instant_Timescale* _con5513 = kk_std_time_instant__as_Timescale(to);
  kk_string_t _x0 = _con5513->name;
  kk_string_dup(_x0);
  _x5512 = _x0; /*string*/
  _match_5315 = kk_string_is_eq(_x5510,_x5512,kk_context()); /*bool*/
  if (_match_5315) {
    kk_std_time_instant__timescale_dropn(from, ((int32_t)10), _ctx);
    kk_std_time_instant__timescale_dropn(to, ((int32_t)10), _ctx);
    return t;
  }
  bool _match_5316;
  bool _match_5317;
  kk_string_t _x5514;
  struct kk_std_time_instant_Timescale* _con5515 = kk_std_time_instant__as_Timescale(from);
  kk_string_t _x1 = _con5515->unit;
  kk_string_dup(_x1);
  _x5514 = _x1; /*string*/
  kk_string_t _x5516;
  struct kk_std_time_instant_Timescale* _con5517 = kk_std_time_instant__as_Timescale(to);
  kk_string_t _x2 = _con5517->unit;
  kk_string_dup(_x2);
  _x5516 = _x2; /*string*/
  _match_5317 = kk_string_is_eq(_x5514,_x5516,kk_context()); /*bool*/
  if (_match_5317) {
    kk_string_t _x5518;
    struct kk_std_time_instant_Timescale* _con5519 = kk_std_time_instant__as_Timescale(from);
    kk_string_t _x3 = _con5519->unit;
    kk_string_dup(_x3);
    _x5518 = _x3; /*string*/
    kk_string_t _x5520;
    kk_define_string_literal(, _s5521, 3, "UTC")
    _x5520 = kk_string_dup(_s5521); /*string*/
    _match_5316 = kk_string_is_eq(_x5518,_x5520,kk_context()); /*bool*/
  }
  else {
    _match_5316 = false; /*bool*/
  }
  if (_match_5316) {
    kk_std_time_instant__timescale_dropn(from, ((int32_t)10), _ctx);
    kk_std_time_instant__timescale_dropn(to, ((int32_t)10), _ctx);
    return t;
  }
  kk_function_t _x5524 = kk_std_time_instant_from_tai(to, _ctx); /*(std/time/duration/duration) -> std/time/timestamp/timestamp*/
  kk_std_time_duration__duration _x5522;
  kk_function_t _x5523 = kk_std_time_instant_to_tai(from, _ctx); /*(std/time/timestamp/timestamp) -> std/time/duration/duration*/
  _x5522 = kk_function_call(kk_std_time_duration__duration, (kk_function_t, kk_std_time_timestamp__timestamp, kk_context_t*), _x5523, (_x5523, t, _ctx)); /*std/time/duration/duration*/
  return kk_function_call(kk_std_time_timestamp__timestamp, (kk_function_t, kk_std_time_duration__duration, kk_context_t*), _x5524, (_x5524, _x5522, _ctx));
}
 
// Return a `:timestamp` for instant `i` in a certain time scale `tscale`.

kk_std_time_timestamp__timestamp kk_std_time_instant_timestamp_in(kk_std_time_instant__instant i, kk_std_time_instant__timescale tscale, kk_context_t* _ctx) { /* (i : instant, tscale : timescale) -> std/time/timestamp/timestamp */ 
  bool _match_5309;
  kk_string_t _x5525;
  kk_std_time_instant__timescale _match_5314;
  struct kk_std_time_instant_Instant* _con5526 = kk_std_time_instant__as_Instant(i);
  kk_std_time_timestamp__timestamp _pat06 = _con5526->since;
  kk_std_time_instant__timescale _x5 = _con5526->ts;
  struct kk_std_time_instant_Timescale* _con5527 = kk_std_time_instant__as_Timescale(_x5);
  kk_std_time_instant__timescale_dup(_x5);
  _match_5314 = _x5; /*std/time/instant/timescale*/
  struct kk_std_time_instant_Timescale* _con5528 = kk_std_time_instant__as_Timescale(_match_5314);
  kk_string_t _x = _con5528->name;
  kk_string_t _pat0 = _con5528->unit;
  kk_function_t _pat1 = _con5528->from_tai;
  kk_function_t _pat2 = _con5528->to_tai;
  kk_std_core_types__maybe _pat3 = _con5528->mb_seconds_in_day;
  kk_std_core_types__maybe _pat4 = _con5528->mb_to_mjd2000;
  kk_std_core_types__maybe _pat5 = _con5528->mb_from_mjd2000;
  if (kk_std_time_instant__timescale_is_unique(_match_5314)) {
    kk_std_core_types__maybe_drop(_pat5, _ctx);
    kk_std_core_types__maybe_drop(_pat4, _ctx);
    kk_std_core_types__maybe_drop(_pat3, _ctx);
    kk_function_drop(_pat2, _ctx);
    kk_function_drop(_pat1, _ctx);
    kk_string_drop(_pat0, _ctx);
    kk_std_time_instant__timescale_free(_match_5314);
  }
  else {
    kk_string_dup(_x);
    kk_std_time_instant__timescale_decref(_match_5314, _ctx);
  }
  _x5525 = _x; /*string*/
  kk_string_t _x5529;
  struct kk_std_time_instant_Timescale* _con5530 = kk_std_time_instant__as_Timescale(tscale);
  kk_string_t _x0 = _con5530->name;
  kk_string_dup(_x0);
  _x5529 = _x0; /*string*/
  _match_5309 = kk_string_is_eq(_x5525,_x5529,kk_context()); /*bool*/
  if (_match_5309) {
    kk_std_time_instant__timescale_dropn(tscale, ((int32_t)10), _ctx);
    struct kk_std_time_instant_Instant* _con5531 = kk_std_time_instant__as_Instant(i);
    kk_std_time_timestamp__timestamp _x4 = _con5531->since;
    kk_std_time_instant__timescale _pat25 = _con5531->ts;
    struct kk_std_time_instant_Timescale* _con5532 = kk_std_time_instant__as_Timescale(_pat25);
    kk_string_t _pat35 = _con5532->name;
    kk_string_t _pat45 = _con5532->unit;
    kk_function_t _pat54 = _con5532->from_tai;
    kk_function_t _pat60 = _con5532->to_tai;
    kk_std_core_types__maybe _pat70 = _con5532->mb_seconds_in_day;
    kk_std_core_types__maybe _pat80 = _con5532->mb_to_mjd2000;
    kk_std_core_types__maybe _pat90 = _con5532->mb_from_mjd2000;
    if (kk_std_time_instant__instant_is_unique(i)) {
      if (kk_std_time_instant__timescale_is_unique(_pat25)) {
        kk_string_drop(_pat35, _ctx);
        kk_string_drop(_pat45, _ctx);
        kk_function_drop(_pat54, _ctx);
        kk_function_drop(_pat60, _ctx);
        kk_std_core_types__maybe_drop(_pat70, _ctx);
        kk_std_core_types__maybe_drop(_pat80, _ctx);
        kk_std_core_types__maybe_drop(_pat90, _ctx);
        kk_std_time_instant__timescale_free(_pat25);
      }
      else {
        kk_std_time_instant__timescale_decref(_pat25, _ctx);
      }
      kk_std_time_instant__instant_free(i);
    }
    else {
      kk_std_time_instant__instant_decref(i, _ctx);
    }
    return _x4;
  }
  bool _match_5310;
  bool _match_5311;
  kk_string_t _x5533;
  kk_std_time_instant__timescale _match_5313;
  struct kk_std_time_instant_Instant* _con5534 = kk_std_time_instant__as_Instant(i);
  kk_std_time_timestamp__timestamp _pat060 = _con5534->since;
  kk_std_time_instant__timescale _x50 = _con5534->ts;
  struct kk_std_time_instant_Timescale* _con5535 = kk_std_time_instant__as_Timescale(_x50);
  kk_std_time_instant__timescale_dup(_x50);
  _match_5313 = _x50; /*std/time/instant/timescale*/
  struct kk_std_time_instant_Timescale* _con5536 = kk_std_time_instant__as_Timescale(_match_5313);
  kk_string_t _pat02 = _con5536->name;
  kk_string_t _x1 = _con5536->unit;
  kk_function_t _pat11 = _con5536->from_tai;
  kk_function_t _pat21 = _con5536->to_tai;
  kk_std_core_types__maybe _pat31 = _con5536->mb_seconds_in_day;
  kk_std_core_types__maybe _pat41 = _con5536->mb_to_mjd2000;
  kk_std_core_types__maybe _pat51 = _con5536->mb_from_mjd2000;
  if (kk_std_time_instant__timescale_is_unique(_match_5313)) {
    kk_std_core_types__maybe_drop(_pat51, _ctx);
    kk_std_core_types__maybe_drop(_pat41, _ctx);
    kk_std_core_types__maybe_drop(_pat31, _ctx);
    kk_function_drop(_pat21, _ctx);
    kk_function_drop(_pat11, _ctx);
    kk_string_drop(_pat02, _ctx);
    kk_std_time_instant__timescale_free(_match_5313);
  }
  else {
    kk_string_dup(_x1);
    kk_std_time_instant__timescale_decref(_match_5313, _ctx);
  }
  _x5533 = _x1; /*string*/
  kk_string_t _x5537;
  struct kk_std_time_instant_Timescale* _con5538 = kk_std_time_instant__as_Timescale(tscale);
  kk_string_t _x2 = _con5538->unit;
  kk_string_dup(_x2);
  _x5537 = _x2; /*string*/
  _match_5311 = kk_string_is_eq(_x5533,_x5537,kk_context()); /*bool*/
  if (_match_5311) {
    kk_string_t _x5539;
    kk_std_time_instant__timescale _match_5312;
    struct kk_std_time_instant_Instant* _con5540 = kk_std_time_instant__as_Instant(i);
    kk_std_time_timestamp__timestamp _pat061 = _con5540->since;
    kk_std_time_instant__timescale _x51 = _con5540->ts;
    struct kk_std_time_instant_Timescale* _con5541 = kk_std_time_instant__as_Timescale(_x51);
    kk_std_time_instant__timescale_dup(_x51);
    _match_5312 = _x51; /*std/time/instant/timescale*/
    struct kk_std_time_instant_Timescale* _con5542 = kk_std_time_instant__as_Timescale(_match_5312);
    kk_string_t _pat04 = _con5542->name;
    kk_string_t _x3 = _con5542->unit;
    kk_function_t _pat15 = _con5542->from_tai;
    kk_function_t _pat23 = _con5542->to_tai;
    kk_std_core_types__maybe _pat33 = _con5542->mb_seconds_in_day;
    kk_std_core_types__maybe _pat43 = _con5542->mb_to_mjd2000;
    kk_std_core_types__maybe _pat53 = _con5542->mb_from_mjd2000;
    if (kk_std_time_instant__timescale_is_unique(_match_5312)) {
      kk_std_core_types__maybe_drop(_pat53, _ctx);
      kk_std_core_types__maybe_drop(_pat43, _ctx);
      kk_std_core_types__maybe_drop(_pat33, _ctx);
      kk_function_drop(_pat23, _ctx);
      kk_function_drop(_pat15, _ctx);
      kk_string_drop(_pat04, _ctx);
      kk_std_time_instant__timescale_free(_match_5312);
    }
    else {
      kk_string_dup(_x3);
      kk_std_time_instant__timescale_decref(_match_5312, _ctx);
    }
    _x5539 = _x3; /*string*/
    kk_string_t _x5543;
    kk_define_string_literal(, _s5544, 3, "UTC")
    _x5543 = kk_string_dup(_s5544); /*string*/
    _match_5310 = kk_string_is_eq(_x5539,_x5543,kk_context()); /*bool*/
  }
  else {
    _match_5310 = false; /*bool*/
  }
  if (_match_5310) {
    kk_std_time_instant__timescale_dropn(tscale, ((int32_t)10), _ctx);
    struct kk_std_time_instant_Instant* _con5545 = kk_std_time_instant__as_Instant(i);
    kk_std_time_timestamp__timestamp _x40 = _con5545->since;
    kk_std_time_instant__timescale _pat250 = _con5545->ts;
    struct kk_std_time_instant_Timescale* _con5546 = kk_std_time_instant__as_Timescale(_pat250);
    kk_string_t _pat350 = _con5546->name;
    kk_string_t _pat450 = _con5546->unit;
    kk_function_t _pat540 = _con5546->from_tai;
    kk_function_t _pat600 = _con5546->to_tai;
    kk_std_core_types__maybe _pat700 = _con5546->mb_seconds_in_day;
    kk_std_core_types__maybe _pat800 = _con5546->mb_to_mjd2000;
    kk_std_core_types__maybe _pat900 = _con5546->mb_from_mjd2000;
    if (kk_std_time_instant__instant_is_unique(i)) {
      if (kk_std_time_instant__timescale_is_unique(_pat250)) {
        kk_string_drop(_pat350, _ctx);
        kk_string_drop(_pat450, _ctx);
        kk_function_drop(_pat540, _ctx);
        kk_function_drop(_pat600, _ctx);
        kk_std_core_types__maybe_drop(_pat700, _ctx);
        kk_std_core_types__maybe_drop(_pat800, _ctx);
        kk_std_core_types__maybe_drop(_pat900, _ctx);
        kk_std_time_instant__timescale_free(_pat250);
      }
      else {
        kk_std_time_instant__timescale_decref(_pat250, _ctx);
      }
      kk_std_time_instant__instant_free(i);
    }
    else {
      kk_std_time_instant__instant_decref(i, _ctx);
    }
    return _x40;
  }
  kk_function_t _x5555 = kk_std_time_instant_from_tai(tscale, _ctx); /*(std/time/duration/duration) -> std/time/timestamp/timestamp*/
  kk_std_time_duration__duration _x5547;
  kk_function_t _x5551;
  kk_std_time_instant__timescale _x5552;
  struct kk_std_time_instant_Instant* _con5553 = kk_std_time_instant__as_Instant(i);
  kk_std_time_timestamp__timestamp _pat062 = _con5553->since;
  kk_std_time_instant__timescale _x52 = _con5553->ts;
  struct kk_std_time_instant_Timescale* _con5554 = kk_std_time_instant__as_Timescale(_x52);
  kk_std_time_instant__timescale_dup(_x52);
  _x5552 = _x52; /*std/time/instant/timescale*/
  _x5551 = kk_std_time_instant_to_tai(_x5552, _ctx); /*(std/time/timestamp/timestamp) -> std/time/duration/duration*/
  kk_std_time_timestamp__timestamp _x5548;
  struct kk_std_time_instant_Instant* _con5549 = kk_std_time_instant__as_Instant(i);
  kk_std_time_timestamp__timestamp _x41 = _con5549->since;
  kk_std_time_instant__timescale _pat251 = _con5549->ts;
  struct kk_std_time_instant_Timescale* _con5550 = kk_std_time_instant__as_Timescale(_pat251);
  kk_string_t _pat351 = _con5550->name;
  kk_string_t _pat451 = _con5550->unit;
  kk_function_t _pat541 = _con5550->from_tai;
  kk_function_t _pat601 = _con5550->to_tai;
  kk_std_core_types__maybe _pat701 = _con5550->mb_seconds_in_day;
  kk_std_core_types__maybe _pat801 = _con5550->mb_to_mjd2000;
  kk_std_core_types__maybe _pat901 = _con5550->mb_from_mjd2000;
  if (kk_std_time_instant__instant_is_unique(i)) {
    if (kk_std_time_instant__timescale_is_unique(_pat251)) {
      kk_string_drop(_pat351, _ctx);
      kk_string_drop(_pat451, _ctx);
      kk_function_drop(_pat541, _ctx);
      kk_function_drop(_pat601, _ctx);
      kk_std_core_types__maybe_drop(_pat701, _ctx);
      kk_std_core_types__maybe_drop(_pat801, _ctx);
      kk_std_core_types__maybe_drop(_pat901, _ctx);
      kk_std_time_instant__timescale_free(_pat251);
    }
    else {
      kk_std_time_instant__timescale_decref(_pat251, _ctx);
    }
    kk_std_time_instant__instant_free(i);
  }
  else {
    kk_std_time_instant__instant_decref(i, _ctx);
  }
  _x5548 = _x41; /*std/time/timestamp/timestamp*/
  _x5547 = kk_function_call(kk_std_time_duration__duration, (kk_function_t, kk_std_time_timestamp__timestamp, kk_context_t*), _x5551, (_x5551, _x5548, _ctx)); /*std/time/duration/duration*/
  return kk_function_call(kk_std_time_timestamp__timestamp, (kk_function_t, kk_std_time_duration__duration, kk_context_t*), _x5555, (_x5555, _x5547, _ctx));
}
 
// Change the internal representation of an instant to use another timescale.
// Only used in special cases for efficiency. For example, when comparing an
// instant in TAI time to thousands of UTC times, it is more efficient to convert
// the TAI time to UTC first to avoid converting at each comparision.

kk_std_time_instant__instant kk_std_time_instant_use_timescale(kk_std_time_instant__instant i, kk_std_time_instant__timescale tscale, kk_context_t* _ctx) { /* (i : instant, tscale : timescale) -> instant */ 
  bool _match_5307;
  kk_string_t _x5556;
  kk_std_time_instant__timescale _match_5308;
  struct kk_std_time_instant_Instant* _con5557 = kk_std_time_instant__as_Instant(i);
  kk_std_time_timestamp__timestamp _pat00 = _con5557->since;
  kk_std_time_instant__timescale _x0 = _con5557->ts;
  struct kk_std_time_instant_Timescale* _con5558 = kk_std_time_instant__as_Timescale(_x0);
  kk_std_time_instant__timescale_dup(_x0);
  _match_5308 = _x0; /*std/time/instant/timescale*/
  struct kk_std_time_instant_Timescale* _con5559 = kk_std_time_instant__as_Timescale(_match_5308);
  kk_string_t _x = _con5559->name;
  kk_string_t _pat0 = _con5559->unit;
  kk_function_t _pat1 = _con5559->from_tai;
  kk_function_t _pat2 = _con5559->to_tai;
  kk_std_core_types__maybe _pat3 = _con5559->mb_seconds_in_day;
  kk_std_core_types__maybe _pat4 = _con5559->mb_to_mjd2000;
  kk_std_core_types__maybe _pat5 = _con5559->mb_from_mjd2000;
  if (kk_std_time_instant__timescale_is_unique(_match_5308)) {
    kk_std_core_types__maybe_drop(_pat5, _ctx);
    kk_std_core_types__maybe_drop(_pat4, _ctx);
    kk_std_core_types__maybe_drop(_pat3, _ctx);
    kk_function_drop(_pat2, _ctx);
    kk_function_drop(_pat1, _ctx);
    kk_string_drop(_pat0, _ctx);
    kk_std_time_instant__timescale_free(_match_5308);
  }
  else {
    kk_string_dup(_x);
    kk_std_time_instant__timescale_decref(_match_5308, _ctx);
  }
  _x5556 = _x; /*string*/
  kk_string_t _x5560;
  struct kk_std_time_instant_Timescale* _con5561 = kk_std_time_instant__as_Timescale(tscale);
  kk_string_t _x1 = _con5561->name;
  kk_string_dup(_x1);
  _x5560 = _x1; /*string*/
  _match_5307 = kk_string_is_eq(_x5556,_x5560,kk_context()); /*bool*/
  if (_match_5307) {
    kk_std_time_instant__timescale_dropn(tscale, ((int32_t)10), _ctx);
    return i;
  }
  kk_std_time_timestamp__timestamp _x5562;
  kk_std_time_instant__timescale _x5563 = kk_std_time_instant__timescale_dup(tscale); /*std/time/instant/timescale*/
  _x5562 = kk_std_time_instant_timestamp_in(i, _x5563, _ctx); /*std/time/timestamp/timestamp*/
  return kk_std_time_instant__new_Instant(kk_reuse_null, _x5562, tscale, _ctx);
}
 
// Add a duration to an instant in time.
// Note: this generally entails conversion to TAI time (`ts-tai`).
// See also `add-duration-in` and `add-days` to add
// in direct time scale units.

kk_std_time_instant__instant kk_std_time_instant__lp__plus__rp_(kk_std_time_instant__instant i, kk_std_time_duration__duration d, kk_context_t* _ctx) { /* (i : instant, d : std/time/duration/duration) -> instant */ 
  bool _match_5298;
  kk_string_t _x5564;
  kk_std_time_instant__timescale _match_5306;
  struct kk_std_time_instant_Instant* _con5565 = kk_std_time_instant__as_Instant(i);
  kk_std_time_timestamp__timestamp _pat00 = _con5565->since;
  kk_std_time_instant__timescale _x0 = _con5565->ts;
  struct kk_std_time_instant_Timescale* _con5566 = kk_std_time_instant__as_Timescale(_x0);
  kk_std_time_instant__timescale_dup(_x0);
  _match_5306 = _x0; /*std/time/instant/timescale*/
  struct kk_std_time_instant_Timescale* _con5567 = kk_std_time_instant__as_Timescale(_match_5306);
  kk_string_t _pat0 = _con5567->name;
  kk_string_t _x = _con5567->unit;
  kk_function_t _pat1 = _con5567->from_tai;
  kk_function_t _pat2 = _con5567->to_tai;
  kk_std_core_types__maybe _pat3 = _con5567->mb_seconds_in_day;
  kk_std_core_types__maybe _pat4 = _con5567->mb_to_mjd2000;
  kk_std_core_types__maybe _pat5 = _con5567->mb_from_mjd2000;
  if (kk_std_time_instant__timescale_is_unique(_match_5306)) {
    kk_std_core_types__maybe_drop(_pat5, _ctx);
    kk_std_core_types__maybe_drop(_pat4, _ctx);
    kk_std_core_types__maybe_drop(_pat3, _ctx);
    kk_function_drop(_pat2, _ctx);
    kk_function_drop(_pat1, _ctx);
    kk_string_drop(_pat0, _ctx);
    kk_std_time_instant__timescale_free(_match_5306);
  }
  else {
    kk_string_dup(_x);
    kk_std_time_instant__timescale_decref(_match_5306, _ctx);
  }
  _x5564 = _x; /*string*/
  kk_string_t _x5568;
  kk_define_string_literal(, _s5569, 3, "TAI")
  _x5568 = kk_string_dup(_s5569); /*string*/
  _match_5298 = kk_string_is_eq(_x5564,_x5568,kk_context()); /*bool*/
  if (_match_5298) {
    kk_std_time_timestamp__timestamp _x5570;
    kk_std_num_ddouble__ddouble _x5571;
    kk_std_num_ddouble__ddouble _x5572;
    kk_std_time_timestamp__timestamp _match_5305;
    struct kk_std_time_instant_Instant* _con5573 = kk_std_time_instant__as_Instant(i);
    kk_std_time_timestamp__timestamp _x2 = _con5573->since;
    kk_std_time_instant__timescale _pat22 = _con5573->ts;
    struct kk_std_time_instant_Timescale* _con5574 = kk_std_time_instant__as_Timescale(_pat22);
    _match_5305 = _x2; /*std/time/timestamp/timestamp*/
    kk_std_num_ddouble__ddouble _x1 = _match_5305.since;
    _x5572 = _x1; /*std/time/timestamp/timespan*/
    kk_std_num_ddouble__ddouble _x5575;
    kk_std_num_ddouble__ddouble _x4 = d.secs;
    _x5575 = _x4; /*std/time/timestamp/timespan*/
    _x5571 = kk_std_num_ddouble__lp__plus__rp_(_x5572, _x5575, _ctx); /*std/num/ddouble/ddouble*/
    int32_t _x5576;
    kk_std_time_timestamp__timestamp _match_5304;
    struct kk_std_time_instant_Instant* _con5577 = kk_std_time_instant__as_Instant(i);
    kk_std_time_timestamp__timestamp _x20 = _con5577->since;
    kk_std_time_instant__timescale _pat220 = _con5577->ts;
    struct kk_std_time_instant_Timescale* _con5578 = kk_std_time_instant__as_Timescale(_pat220);
    _match_5304 = _x20; /*std/time/timestamp/timestamp*/
    kk_std_num_ddouble__ddouble _pat000 = _match_5304.since;
    int32_t _x00 = _match_5304.leap32;
    _x5576 = _x00; /*int32*/
    _x5570 = kk_std_time_timestamp__new_Timestamp(_x5571, _x5576, _ctx); /*std/time/timestamp/timestamp*/
    kk_std_time_instant__timescale _x5579;
    struct kk_std_time_instant_Instant* _con5580 = kk_std_time_instant__as_Instant(i);
    kk_std_time_timestamp__timestamp _pat03 = _con5580->since;
    kk_std_time_instant__timescale _x3 = _con5580->ts;
    struct kk_std_time_instant_Timescale* _con5581 = kk_std_time_instant__as_Timescale(_x3);
    if (kk_std_time_instant__instant_is_unique(i)) {
      kk_std_time_instant__instant_free(i);
    }
    else {
      kk_std_time_instant__timescale_dup(_x3);
      kk_std_time_instant__instant_decref(i, _ctx);
    }
    _x5579 = _x3; /*std/time/instant/timescale*/
    return kk_std_time_instant__new_Instant(kk_reuse_null, _x5570, _x5579, _ctx);
  }
  kk_std_time_instant__instant i1_4528;
  kk_std_time_instant__instant i2_4530;
  kk_std_time_instant__instant _x5582 = kk_std_time_instant__instant_dup(i); /*std/time/instant/instant*/
  kk_std_time_instant__timescale _x5583 = kk_std_time_instant__timescale_dup(kk_std_time_instant_ts_tai); /*std/time/instant/timescale*/
  i2_4530 = kk_std_time_instant_use_timescale(_x5582, _x5583, _ctx); /*std/time/instant/instant*/
  kk_std_time_timestamp__timestamp _x5584;
  kk_std_num_ddouble__ddouble _x5585;
  kk_std_num_ddouble__ddouble _x5586;
  kk_std_time_timestamp__timestamp _match_5303;
  struct kk_std_time_instant_Instant* _con5587 = kk_std_time_instant__as_Instant(i2_4530);
  kk_std_time_timestamp__timestamp _x9 = _con5587->since;
  kk_std_time_instant__timescale _pat211 = _con5587->ts;
  struct kk_std_time_instant_Timescale* _con5588 = kk_std_time_instant__as_Timescale(_pat211);
  _match_5303 = _x9; /*std/time/timestamp/timestamp*/
  kk_std_num_ddouble__ddouble _x8 = _match_5303.since;
  _x5586 = _x8; /*std/time/timestamp/timespan*/
  kk_std_num_ddouble__ddouble _x5589;
  kk_std_num_ddouble__ddouble _x11 = d.secs;
  _x5589 = _x11; /*std/time/timestamp/timespan*/
  _x5585 = kk_std_num_ddouble__lp__plus__rp_(_x5586, _x5589, _ctx); /*std/num/ddouble/ddouble*/
  int32_t _x5590;
  kk_std_time_timestamp__timestamp _match_5302;
  struct kk_std_time_instant_Instant* _con5591 = kk_std_time_instant__as_Instant(i2_4530);
  kk_std_time_timestamp__timestamp _x90 = _con5591->since;
  kk_std_time_instant__timescale _pat2110 = _con5591->ts;
  struct kk_std_time_instant_Timescale* _con5592 = kk_std_time_instant__as_Timescale(_pat2110);
  _match_5302 = _x90; /*std/time/timestamp/timestamp*/
  kk_std_num_ddouble__ddouble _pat001 = _match_5302.since;
  int32_t _x01 = _match_5302.leap32;
  _x5590 = _x01; /*int32*/
  _x5584 = kk_std_time_timestamp__new_Timestamp(_x5585, _x5590, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_time_instant__timescale _x5593;
  struct kk_std_time_instant_Instant* _con5594 = kk_std_time_instant__as_Instant(i2_4530);
  kk_std_time_timestamp__timestamp _pat012 = _con5594->since;
  kk_std_time_instant__timescale _x10 = _con5594->ts;
  struct kk_std_time_instant_Timescale* _con5595 = kk_std_time_instant__as_Timescale(_x10);
  if (kk_std_time_instant__instant_is_unique(i2_4530)) {
    kk_std_time_instant__instant_free(i2_4530);
  }
  else {
    kk_std_time_instant__timescale_dup(_x10);
    kk_std_time_instant__instant_decref(i2_4530, _ctx);
  }
  _x5593 = _x10; /*std/time/instant/timescale*/
  i1_4528 = kk_std_time_instant__new_Instant(kk_reuse_null, _x5584, _x5593, _ctx); /*std/time/instant/instant*/
  bool _match_5299;
  kk_string_t _x5596;
  kk_std_time_instant__timescale _match_5301;
  struct kk_std_time_instant_Instant* _con5597 = kk_std_time_instant__as_Instant(i1_4528);
  kk_std_time_timestamp__timestamp _pat07 = _con5597->since;
  kk_std_time_instant__timescale _x6 = _con5597->ts;
  struct kk_std_time_instant_Timescale* _con5598 = kk_std_time_instant__as_Timescale(_x6);
  kk_std_time_instant__timescale_dup(_x6);
  _match_5301 = _x6; /*std/time/instant/timescale*/
  struct kk_std_time_instant_Timescale* _con5599 = kk_std_time_instant__as_Timescale(_match_5301);
  kk_string_t _x50 = _con5599->name;
  kk_string_t _pat060 = _con5599->unit;
  kk_function_t _pat1100 = _con5599->from_tai;
  kk_function_t _pat250 = _con5599->to_tai;
  kk_std_core_types__maybe _pat340 = _con5599->mb_seconds_in_day;
  kk_std_core_types__maybe _pat430 = _con5599->mb_to_mjd2000;
  kk_std_core_types__maybe _pat530 = _con5599->mb_from_mjd2000;
  if (kk_std_time_instant__timescale_is_unique(_match_5301)) {
    kk_std_core_types__maybe_drop(_pat530, _ctx);
    kk_std_core_types__maybe_drop(_pat430, _ctx);
    kk_std_core_types__maybe_drop(_pat340, _ctx);
    kk_function_drop(_pat250, _ctx);
    kk_function_drop(_pat1100, _ctx);
    kk_string_drop(_pat060, _ctx);
    kk_std_time_instant__timescale_free(_match_5301);
  }
  else {
    kk_string_dup(_x50);
    kk_std_time_instant__timescale_decref(_match_5301, _ctx);
  }
  _x5596 = _x50; /*string*/
  kk_string_t _x5600;
  kk_std_time_instant__timescale _match_5300;
  struct kk_std_time_instant_Instant* _con5601 = kk_std_time_instant__as_Instant(i);
  kk_std_time_timestamp__timestamp _pat06 = _con5601->since;
  kk_std_time_instant__timescale _x5 = _con5601->ts;
  struct kk_std_time_instant_Timescale* _con5602 = kk_std_time_instant__as_Timescale(_x5);
  kk_std_time_instant__timescale_dup(_x5);
  _match_5300 = _x5; /*std/time/instant/timescale*/
  struct kk_std_time_instant_Timescale* _con5603 = kk_std_time_instant__as_Timescale(_match_5300);
  kk_string_t _x7 = _con5603->name;
  kk_string_t _pat08 = _con5603->unit;
  kk_function_t _pat112 = _con5603->from_tai;
  kk_function_t _pat29 = _con5603->to_tai;
  kk_std_core_types__maybe _pat36 = _con5603->mb_seconds_in_day;
  kk_std_core_types__maybe _pat45 = _con5603->mb_to_mjd2000;
  kk_std_core_types__maybe _pat55 = _con5603->mb_from_mjd2000;
  if (kk_std_time_instant__timescale_is_unique(_match_5300)) {
    kk_std_core_types__maybe_drop(_pat55, _ctx);
    kk_std_core_types__maybe_drop(_pat45, _ctx);
    kk_std_core_types__maybe_drop(_pat36, _ctx);
    kk_function_drop(_pat29, _ctx);
    kk_function_drop(_pat112, _ctx);
    kk_string_drop(_pat08, _ctx);
    kk_std_time_instant__timescale_free(_match_5300);
  }
  else {
    kk_string_dup(_x7);
    kk_std_time_instant__timescale_decref(_match_5300, _ctx);
  }
  _x5600 = _x7; /*string*/
  _match_5299 = kk_string_is_eq(_x5596,_x5600,kk_context()); /*bool*/
  if (_match_5299) {
    kk_std_time_instant__instant_dropn(i, ((int32_t)1), _ctx);
    return i1_4528;
  }
  kk_std_time_timestamp__timestamp _x5604;
  kk_std_time_instant__timescale _x5605;
  struct kk_std_time_instant_Instant* _con5606 = kk_std_time_instant__as_Instant(i);
  kk_std_time_timestamp__timestamp _pat061 = _con5606->since;
  kk_std_time_instant__timescale _x51 = _con5606->ts;
  struct kk_std_time_instant_Timescale* _con5607 = kk_std_time_instant__as_Timescale(_x51);
  kk_std_time_instant__timescale_dup(_x51);
  _x5605 = _x51; /*std/time/instant/timescale*/
  _x5604 = kk_std_time_instant_timestamp_in(i1_4528, _x5605, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_time_instant__timescale _x5608;
  struct kk_std_time_instant_Instant* _con5609 = kk_std_time_instant__as_Instant(i);
  kk_std_time_timestamp__timestamp _pat062 = _con5609->since;
  kk_std_time_instant__timescale _x52 = _con5609->ts;
  struct kk_std_time_instant_Timescale* _con5610 = kk_std_time_instant__as_Timescale(_x52);
  if (kk_std_time_instant__instant_is_unique(i)) {
    kk_std_time_instant__instant_free(i);
  }
  else {
    kk_std_time_instant__timescale_dup(_x52);
    kk_std_time_instant__instant_decref(i, _ctx);
  }
  _x5608 = _x52; /*std/time/instant/timescale*/
  return kk_std_time_instant__new_Instant(kk_reuse_null, _x5604, _x5608, _ctx);
}
 
// Subtract a duration from an instant in time.

kk_std_time_instant__instant kk_std_time_instant__lp__dash__rp_(kk_std_time_instant__instant i, kk_std_time_duration__duration d, kk_context_t* _ctx) { /* (i : instant, d : std/time/duration/duration) -> instant */ 
  kk_std_time_duration__duration d0_4727 = kk_std_time_duration__lp__tilde__rp_(d, _ctx); /*std/time/duration/duration*/;
  bool _match_5289;
  kk_string_t _x5611;
  kk_std_time_instant__timescale _match_5297;
  struct kk_std_time_instant_Instant* _con5612 = kk_std_time_instant__as_Instant(i);
  kk_std_time_timestamp__timestamp _pat00 = _con5612->since;
  kk_std_time_instant__timescale _x0 = _con5612->ts;
  struct kk_std_time_instant_Timescale* _con5613 = kk_std_time_instant__as_Timescale(_x0);
  kk_std_time_instant__timescale_dup(_x0);
  _match_5297 = _x0; /*std/time/instant/timescale*/
  struct kk_std_time_instant_Timescale* _con5614 = kk_std_time_instant__as_Timescale(_match_5297);
  kk_string_t _pat0 = _con5614->name;
  kk_string_t _x = _con5614->unit;
  kk_function_t _pat1 = _con5614->from_tai;
  kk_function_t _pat2 = _con5614->to_tai;
  kk_std_core_types__maybe _pat3 = _con5614->mb_seconds_in_day;
  kk_std_core_types__maybe _pat4 = _con5614->mb_to_mjd2000;
  kk_std_core_types__maybe _pat5 = _con5614->mb_from_mjd2000;
  if (kk_std_time_instant__timescale_is_unique(_match_5297)) {
    kk_std_core_types__maybe_drop(_pat5, _ctx);
    kk_std_core_types__maybe_drop(_pat4, _ctx);
    kk_std_core_types__maybe_drop(_pat3, _ctx);
    kk_function_drop(_pat2, _ctx);
    kk_function_drop(_pat1, _ctx);
    kk_string_drop(_pat0, _ctx);
    kk_std_time_instant__timescale_free(_match_5297);
  }
  else {
    kk_string_dup(_x);
    kk_std_time_instant__timescale_decref(_match_5297, _ctx);
  }
  _x5611 = _x; /*string*/
  kk_string_t _x5615;
  kk_define_string_literal(, _s5616, 3, "TAI")
  _x5615 = kk_string_dup(_s5616); /*string*/
  _match_5289 = kk_string_is_eq(_x5611,_x5615,kk_context()); /*bool*/
  if (_match_5289) {
    kk_std_time_timestamp__timestamp _x5617;
    kk_std_num_ddouble__ddouble _x5618;
    kk_std_num_ddouble__ddouble _x5619;
    kk_std_time_timestamp__timestamp _match_5296;
    struct kk_std_time_instant_Instant* _con5620 = kk_std_time_instant__as_Instant(i);
    kk_std_time_timestamp__timestamp _x2 = _con5620->since;
    kk_std_time_instant__timescale _pat22 = _con5620->ts;
    struct kk_std_time_instant_Timescale* _con5621 = kk_std_time_instant__as_Timescale(_pat22);
    _match_5296 = _x2; /*std/time/timestamp/timestamp*/
    kk_std_num_ddouble__ddouble _x1 = _match_5296.since;
    _x5619 = _x1; /*std/time/timestamp/timespan*/
    kk_std_num_ddouble__ddouble _x5622;
    kk_std_num_ddouble__ddouble _x4 = d0_4727.secs;
    _x5622 = _x4; /*std/time/timestamp/timespan*/
    _x5618 = kk_std_num_ddouble__lp__plus__rp_(_x5619, _x5622, _ctx); /*std/num/ddouble/ddouble*/
    int32_t _x5623;
    kk_std_time_timestamp__timestamp _match_5295;
    struct kk_std_time_instant_Instant* _con5624 = kk_std_time_instant__as_Instant(i);
    kk_std_time_timestamp__timestamp _x20 = _con5624->since;
    kk_std_time_instant__timescale _pat220 = _con5624->ts;
    struct kk_std_time_instant_Timescale* _con5625 = kk_std_time_instant__as_Timescale(_pat220);
    _match_5295 = _x20; /*std/time/timestamp/timestamp*/
    kk_std_num_ddouble__ddouble _pat000 = _match_5295.since;
    int32_t _x00 = _match_5295.leap32;
    _x5623 = _x00; /*int32*/
    _x5617 = kk_std_time_timestamp__new_Timestamp(_x5618, _x5623, _ctx); /*std/time/timestamp/timestamp*/
    kk_std_time_instant__timescale _x5626;
    struct kk_std_time_instant_Instant* _con5627 = kk_std_time_instant__as_Instant(i);
    kk_std_time_timestamp__timestamp _pat03 = _con5627->since;
    kk_std_time_instant__timescale _x3 = _con5627->ts;
    struct kk_std_time_instant_Timescale* _con5628 = kk_std_time_instant__as_Timescale(_x3);
    if (kk_std_time_instant__instant_is_unique(i)) {
      kk_std_time_instant__instant_free(i);
    }
    else {
      kk_std_time_instant__timescale_dup(_x3);
      kk_std_time_instant__instant_decref(i, _ctx);
    }
    _x5626 = _x3; /*std/time/instant/timescale*/
    return kk_std_time_instant__new_Instant(kk_reuse_null, _x5617, _x5626, _ctx);
  }
  kk_std_time_instant__instant i1_4528;
  kk_std_time_instant__instant i2_4530;
  kk_std_time_instant__instant _x5629 = kk_std_time_instant__instant_dup(i); /*std/time/instant/instant*/
  kk_std_time_instant__timescale _x5630 = kk_std_time_instant__timescale_dup(kk_std_time_instant_ts_tai); /*std/time/instant/timescale*/
  i2_4530 = kk_std_time_instant_use_timescale(_x5629, _x5630, _ctx); /*std/time/instant/instant*/
  kk_std_time_timestamp__timestamp _x5631;
  kk_std_num_ddouble__ddouble _x5632;
  kk_std_num_ddouble__ddouble _x5633;
  kk_std_time_timestamp__timestamp _match_5294;
  struct kk_std_time_instant_Instant* _con5634 = kk_std_time_instant__as_Instant(i2_4530);
  kk_std_time_timestamp__timestamp _x9 = _con5634->since;
  kk_std_time_instant__timescale _pat211 = _con5634->ts;
  struct kk_std_time_instant_Timescale* _con5635 = kk_std_time_instant__as_Timescale(_pat211);
  _match_5294 = _x9; /*std/time/timestamp/timestamp*/
  kk_std_num_ddouble__ddouble _x8 = _match_5294.since;
  _x5633 = _x8; /*std/time/timestamp/timespan*/
  kk_std_num_ddouble__ddouble _x5636;
  kk_std_num_ddouble__ddouble _x11 = d0_4727.secs;
  _x5636 = _x11; /*std/time/timestamp/timespan*/
  _x5632 = kk_std_num_ddouble__lp__plus__rp_(_x5633, _x5636, _ctx); /*std/num/ddouble/ddouble*/
  int32_t _x5637;
  kk_std_time_timestamp__timestamp _match_5293;
  struct kk_std_time_instant_Instant* _con5638 = kk_std_time_instant__as_Instant(i2_4530);
  kk_std_time_timestamp__timestamp _x90 = _con5638->since;
  kk_std_time_instant__timescale _pat2110 = _con5638->ts;
  struct kk_std_time_instant_Timescale* _con5639 = kk_std_time_instant__as_Timescale(_pat2110);
  _match_5293 = _x90; /*std/time/timestamp/timestamp*/
  kk_std_num_ddouble__ddouble _pat001 = _match_5293.since;
  int32_t _x01 = _match_5293.leap32;
  _x5637 = _x01; /*int32*/
  _x5631 = kk_std_time_timestamp__new_Timestamp(_x5632, _x5637, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_time_instant__timescale _x5640;
  struct kk_std_time_instant_Instant* _con5641 = kk_std_time_instant__as_Instant(i2_4530);
  kk_std_time_timestamp__timestamp _pat012 = _con5641->since;
  kk_std_time_instant__timescale _x10 = _con5641->ts;
  struct kk_std_time_instant_Timescale* _con5642 = kk_std_time_instant__as_Timescale(_x10);
  if (kk_std_time_instant__instant_is_unique(i2_4530)) {
    kk_std_time_instant__instant_free(i2_4530);
  }
  else {
    kk_std_time_instant__timescale_dup(_x10);
    kk_std_time_instant__instant_decref(i2_4530, _ctx);
  }
  _x5640 = _x10; /*std/time/instant/timescale*/
  i1_4528 = kk_std_time_instant__new_Instant(kk_reuse_null, _x5631, _x5640, _ctx); /*std/time/instant/instant*/
  bool _match_5290;
  kk_string_t _x5643;
  kk_std_time_instant__timescale _match_5292;
  struct kk_std_time_instant_Instant* _con5644 = kk_std_time_instant__as_Instant(i1_4528);
  kk_std_time_timestamp__timestamp _pat07 = _con5644->since;
  kk_std_time_instant__timescale _x6 = _con5644->ts;
  struct kk_std_time_instant_Timescale* _con5645 = kk_std_time_instant__as_Timescale(_x6);
  kk_std_time_instant__timescale_dup(_x6);
  _match_5292 = _x6; /*std/time/instant/timescale*/
  struct kk_std_time_instant_Timescale* _con5646 = kk_std_time_instant__as_Timescale(_match_5292);
  kk_string_t _x50 = _con5646->name;
  kk_string_t _pat060 = _con5646->unit;
  kk_function_t _pat1100 = _con5646->from_tai;
  kk_function_t _pat250 = _con5646->to_tai;
  kk_std_core_types__maybe _pat340 = _con5646->mb_seconds_in_day;
  kk_std_core_types__maybe _pat430 = _con5646->mb_to_mjd2000;
  kk_std_core_types__maybe _pat530 = _con5646->mb_from_mjd2000;
  if (kk_std_time_instant__timescale_is_unique(_match_5292)) {
    kk_std_core_types__maybe_drop(_pat530, _ctx);
    kk_std_core_types__maybe_drop(_pat430, _ctx);
    kk_std_core_types__maybe_drop(_pat340, _ctx);
    kk_function_drop(_pat250, _ctx);
    kk_function_drop(_pat1100, _ctx);
    kk_string_drop(_pat060, _ctx);
    kk_std_time_instant__timescale_free(_match_5292);
  }
  else {
    kk_string_dup(_x50);
    kk_std_time_instant__timescale_decref(_match_5292, _ctx);
  }
  _x5643 = _x50; /*string*/
  kk_string_t _x5647;
  kk_std_time_instant__timescale _match_5291;
  struct kk_std_time_instant_Instant* _con5648 = kk_std_time_instant__as_Instant(i);
  kk_std_time_timestamp__timestamp _pat06 = _con5648->since;
  kk_std_time_instant__timescale _x5 = _con5648->ts;
  struct kk_std_time_instant_Timescale* _con5649 = kk_std_time_instant__as_Timescale(_x5);
  kk_std_time_instant__timescale_dup(_x5);
  _match_5291 = _x5; /*std/time/instant/timescale*/
  struct kk_std_time_instant_Timescale* _con5650 = kk_std_time_instant__as_Timescale(_match_5291);
  kk_string_t _x7 = _con5650->name;
  kk_string_t _pat08 = _con5650->unit;
  kk_function_t _pat112 = _con5650->from_tai;
  kk_function_t _pat29 = _con5650->to_tai;
  kk_std_core_types__maybe _pat36 = _con5650->mb_seconds_in_day;
  kk_std_core_types__maybe _pat45 = _con5650->mb_to_mjd2000;
  kk_std_core_types__maybe _pat55 = _con5650->mb_from_mjd2000;
  if (kk_std_time_instant__timescale_is_unique(_match_5291)) {
    kk_std_core_types__maybe_drop(_pat55, _ctx);
    kk_std_core_types__maybe_drop(_pat45, _ctx);
    kk_std_core_types__maybe_drop(_pat36, _ctx);
    kk_function_drop(_pat29, _ctx);
    kk_function_drop(_pat112, _ctx);
    kk_string_drop(_pat08, _ctx);
    kk_std_time_instant__timescale_free(_match_5291);
  }
  else {
    kk_string_dup(_x7);
    kk_std_time_instant__timescale_decref(_match_5291, _ctx);
  }
  _x5647 = _x7; /*string*/
  _match_5290 = kk_string_is_eq(_x5643,_x5647,kk_context()); /*bool*/
  if (_match_5290) {
    kk_std_time_instant__instant_dropn(i, ((int32_t)1), _ctx);
    return i1_4528;
  }
  kk_std_time_timestamp__timestamp _x5651;
  kk_std_time_instant__timescale _x5652;
  struct kk_std_time_instant_Instant* _con5653 = kk_std_time_instant__as_Instant(i);
  kk_std_time_timestamp__timestamp _pat061 = _con5653->since;
  kk_std_time_instant__timescale _x51 = _con5653->ts;
  struct kk_std_time_instant_Timescale* _con5654 = kk_std_time_instant__as_Timescale(_x51);
  kk_std_time_instant__timescale_dup(_x51);
  _x5652 = _x51; /*std/time/instant/timescale*/
  _x5651 = kk_std_time_instant_timestamp_in(i1_4528, _x5652, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_time_instant__timescale _x5655;
  struct kk_std_time_instant_Instant* _con5656 = kk_std_time_instant__as_Instant(i);
  kk_std_time_timestamp__timestamp _pat062 = _con5656->since;
  kk_std_time_instant__timescale _x52 = _con5656->ts;
  struct kk_std_time_instant_Timescale* _con5657 = kk_std_time_instant__as_Timescale(_x52);
  if (kk_std_time_instant__instant_is_unique(i)) {
    kk_std_time_instant__instant_free(i);
  }
  else {
    kk_std_time_instant__timescale_dup(_x52);
    kk_std_time_instant__instant_decref(i, _ctx);
  }
  _x5655 = _x52; /*std/time/instant/timescale*/
  return kk_std_time_instant__new_Instant(kk_reuse_null, _x5651, _x5655, _ctx);
}
 
// Are two timescales the same?

bool kk_std_time_instant__lp__eq__eq__rp_(kk_std_time_instant__timescale t1, kk_std_time_instant__timescale t2, kk_context_t* _ctx) { /* (t1 : timescale, t2 : timescale) -> bool */ 
  kk_string_t _x5663;
  struct kk_std_time_instant_Timescale* _con5664 = kk_std_time_instant__as_Timescale(t1);
  kk_string_t _x = _con5664->name;
  kk_string_t _pat0 = _con5664->unit;
  kk_function_t _pat1 = _con5664->from_tai;
  kk_function_t _pat2 = _con5664->to_tai;
  kk_std_core_types__maybe _pat3 = _con5664->mb_seconds_in_day;
  kk_std_core_types__maybe _pat4 = _con5664->mb_to_mjd2000;
  kk_std_core_types__maybe _pat5 = _con5664->mb_from_mjd2000;
  if (kk_std_time_instant__timescale_is_unique(t1)) {
    kk_std_core_types__maybe_drop(_pat5, _ctx);
    kk_std_core_types__maybe_drop(_pat4, _ctx);
    kk_std_core_types__maybe_drop(_pat3, _ctx);
    kk_function_drop(_pat2, _ctx);
    kk_function_drop(_pat1, _ctx);
    kk_string_drop(_pat0, _ctx);
    kk_std_time_instant__timescale_free(t1);
  }
  else {
    kk_string_dup(_x);
    kk_std_time_instant__timescale_decref(t1, _ctx);
  }
  _x5663 = _x; /*string*/
  kk_string_t _x5665;
  struct kk_std_time_instant_Timescale* _con5666 = kk_std_time_instant__as_Timescale(t2);
  kk_string_t _x0 = _con5666->name;
  kk_string_t _pat00 = _con5666->unit;
  kk_function_t _pat10 = _con5666->from_tai;
  kk_function_t _pat20 = _con5666->to_tai;
  kk_std_core_types__maybe _pat30 = _con5666->mb_seconds_in_day;
  kk_std_core_types__maybe _pat40 = _con5666->mb_to_mjd2000;
  kk_std_core_types__maybe _pat50 = _con5666->mb_from_mjd2000;
  if (kk_std_time_instant__timescale_is_unique(t2)) {
    kk_std_core_types__maybe_drop(_pat50, _ctx);
    kk_std_core_types__maybe_drop(_pat40, _ctx);
    kk_std_core_types__maybe_drop(_pat30, _ctx);
    kk_function_drop(_pat20, _ctx);
    kk_function_drop(_pat10, _ctx);
    kk_string_drop(_pat00, _ctx);
    kk_std_time_instant__timescale_free(t2);
  }
  else {
    kk_string_dup(_x0);
    kk_std_time_instant__timescale_decref(t2, _ctx);
  }
  _x5665 = _x0; /*string*/
  return kk_string_is_eq(_x5663,_x5665,kk_context());
}
 
// Compare two `:instant`s in time.

kk_std_core_types__order kk_std_time_instant_compare(kk_std_time_instant__instant i, kk_std_time_instant__instant j, kk_context_t* _ctx) { /* (i : instant, j : instant) -> order */ 
  kk_std_time_timestamp__timestamp _x5667;
  struct kk_std_time_instant_Instant* _con5668 = kk_std_time_instant__as_Instant(i);
  kk_std_time_timestamp__timestamp _x = _con5668->since;
  kk_std_time_instant__timescale _pat2 = _con5668->ts;
  struct kk_std_time_instant_Timescale* _con5669 = kk_std_time_instant__as_Timescale(_pat2);
  _x5667 = _x; /*std/time/timestamp/timestamp*/
  kk_std_time_timestamp__timestamp _x5670;
  kk_std_time_instant__instant instant0_4546;
  bool _match_5286;
  kk_string_t _x5671;
  kk_std_time_instant__timescale _match_5288;
  struct kk_std_time_instant_Instant* _con5672 = kk_std_time_instant__as_Instant(j);
  kk_std_time_timestamp__timestamp _pat02 = _con5672->since;
  kk_std_time_instant__timescale _x2 = _con5672->ts;
  struct kk_std_time_instant_Timescale* _con5673 = kk_std_time_instant__as_Timescale(_x2);
  kk_std_time_instant__timescale_dup(_x2);
  _match_5288 = _x2; /*std/time/instant/timescale*/
  struct kk_std_time_instant_Timescale* _con5674 = kk_std_time_instant__as_Timescale(_match_5288);
  kk_string_t _x1 = _con5674->name;
  kk_string_t _pat01 = _con5674->unit;
  kk_function_t _pat13 = _con5674->from_tai;
  kk_function_t _pat21 = _con5674->to_tai;
  kk_std_core_types__maybe _pat31 = _con5674->mb_seconds_in_day;
  kk_std_core_types__maybe _pat41 = _con5674->mb_to_mjd2000;
  kk_std_core_types__maybe _pat51 = _con5674->mb_from_mjd2000;
  if (kk_std_time_instant__timescale_is_unique(_match_5288)) {
    kk_std_core_types__maybe_drop(_pat51, _ctx);
    kk_std_core_types__maybe_drop(_pat41, _ctx);
    kk_std_core_types__maybe_drop(_pat31, _ctx);
    kk_function_drop(_pat21, _ctx);
    kk_function_drop(_pat13, _ctx);
    kk_string_drop(_pat01, _ctx);
    kk_std_time_instant__timescale_free(_match_5288);
  }
  else {
    kk_string_dup(_x1);
    kk_std_time_instant__timescale_decref(_match_5288, _ctx);
  }
  _x5671 = _x1; /*string*/
  kk_string_t _x5675;
  kk_std_time_instant__timescale _match_5287;
  struct kk_std_time_instant_Instant* _con5676 = kk_std_time_instant__as_Instant(i);
  kk_std_time_timestamp__timestamp _pat05 = _con5676->since;
  kk_std_time_instant__timescale _x4 = _con5676->ts;
  struct kk_std_time_instant_Timescale* _con5677 = kk_std_time_instant__as_Timescale(_x4);
  kk_std_time_instant__timescale_dup(_x4);
  _match_5287 = _x4; /*std/time/instant/timescale*/
  struct kk_std_time_instant_Timescale* _con5678 = kk_std_time_instant__as_Timescale(_match_5287);
  kk_string_t _x3 = _con5678->name;
  kk_string_t _pat03 = _con5678->unit;
  kk_function_t _pat17 = _con5678->from_tai;
  kk_function_t _pat23 = _con5678->to_tai;
  kk_std_core_types__maybe _pat33 = _con5678->mb_seconds_in_day;
  kk_std_core_types__maybe _pat43 = _con5678->mb_to_mjd2000;
  kk_std_core_types__maybe _pat53 = _con5678->mb_from_mjd2000;
  if (kk_std_time_instant__timescale_is_unique(_match_5287)) {
    kk_std_core_types__maybe_drop(_pat53, _ctx);
    kk_std_core_types__maybe_drop(_pat43, _ctx);
    kk_std_core_types__maybe_drop(_pat33, _ctx);
    kk_function_drop(_pat23, _ctx);
    kk_function_drop(_pat17, _ctx);
    kk_string_drop(_pat03, _ctx);
    kk_std_time_instant__timescale_free(_match_5287);
  }
  else {
    kk_string_dup(_x3);
    kk_std_time_instant__timescale_decref(_match_5287, _ctx);
  }
  _x5675 = _x3; /*string*/
  _match_5286 = kk_string_is_eq(_x5671,_x5675,kk_context()); /*bool*/
  if (_match_5286) {
    kk_std_time_instant__instant_dropn(i, ((int32_t)1), _ctx);
    instant0_4546 = j; /*std/time/instant/instant*/
  }
  else {
    kk_std_time_timestamp__timestamp _x5679;
    kk_std_time_instant__timescale _x5680;
    struct kk_std_time_instant_Instant* _con5681 = kk_std_time_instant__as_Instant(i);
    kk_std_time_timestamp__timestamp _pat050 = _con5681->since;
    kk_std_time_instant__timescale _x40 = _con5681->ts;
    struct kk_std_time_instant_Timescale* _con5682 = kk_std_time_instant__as_Timescale(_x40);
    kk_std_time_instant__timescale_dup(_x40);
    _x5680 = _x40; /*std/time/instant/timescale*/
    _x5679 = kk_std_time_instant_timestamp_in(j, _x5680, _ctx); /*std/time/timestamp/timestamp*/
    kk_std_time_instant__timescale _x5683;
    struct kk_std_time_instant_Instant* _con5684 = kk_std_time_instant__as_Instant(i);
    kk_std_time_timestamp__timestamp _pat051 = _con5684->since;
    kk_std_time_instant__timescale _x41 = _con5684->ts;
    struct kk_std_time_instant_Timescale* _con5685 = kk_std_time_instant__as_Timescale(_x41);
    if (kk_std_time_instant__instant_is_unique(i)) {
      kk_std_time_instant__instant_free(i);
    }
    else {
      kk_std_time_instant__timescale_dup(_x41);
      kk_std_time_instant__instant_decref(i, _ctx);
    }
    _x5683 = _x41; /*std/time/instant/timescale*/
    instant0_4546 = kk_std_time_instant__new_Instant(kk_reuse_null, _x5679, _x5683, _ctx); /*std/time/instant/instant*/
  }
  struct kk_std_time_instant_Instant* _con5686 = kk_std_time_instant__as_Instant(instant0_4546);
  kk_std_time_timestamp__timestamp _x0 = _con5686->since;
  kk_std_time_instant__timescale _pat20 = _con5686->ts;
  struct kk_std_time_instant_Timescale* _con5687 = kk_std_time_instant__as_Timescale(_pat20);
  kk_string_t _pat30 = _con5687->name;
  kk_string_t _pat40 = _con5687->unit;
  kk_function_t _pat50 = _con5687->from_tai;
  kk_function_t _pat60 = _con5687->to_tai;
  kk_std_core_types__maybe _pat70 = _con5687->mb_seconds_in_day;
  kk_std_core_types__maybe _pat80 = _con5687->mb_to_mjd2000;
  kk_std_core_types__maybe _pat90 = _con5687->mb_from_mjd2000;
  if (kk_std_time_instant__instant_is_unique(instant0_4546)) {
    if (kk_std_time_instant__timescale_is_unique(_pat20)) {
      kk_string_drop(_pat30, _ctx);
      kk_string_drop(_pat40, _ctx);
      kk_function_drop(_pat50, _ctx);
      kk_function_drop(_pat60, _ctx);
      kk_std_core_types__maybe_drop(_pat70, _ctx);
      kk_std_core_types__maybe_drop(_pat80, _ctx);
      kk_std_core_types__maybe_drop(_pat90, _ctx);
      kk_std_time_instant__timescale_free(_pat20);
    }
    else {
      kk_std_time_instant__timescale_decref(_pat20, _ctx);
    }
    kk_std_time_instant__instant_free(instant0_4546);
  }
  else {
    kk_std_time_instant__instant_decref(instant0_4546, _ctx);
  }
  _x5670 = _x0; /*std/time/timestamp/timestamp*/
  return kk_std_time_timestamp_compare(_x5667, _x5670, _ctx);
}

bool kk_std_time_instant__lp__eq__eq__1_rp_(kk_std_time_instant__instant i, kk_std_time_instant__instant j, kk_context_t* _ctx) { /* (i : instant, j : instant) -> bool */ 
  kk_std_core_types__order x_4553 = kk_std_time_instant_compare(i, j, _ctx); /*order*/;
  kk_integer_t _x5688 = kk_std_core_int_5(x_4553, _ctx); /*int*/
  kk_integer_t _x5689;
  kk_std_core_types__order _x5690 = kk_std_core_types__new_Eq(_ctx); /*order*/
  if (kk_std_core_types__is_Lt(_x5690)) {
    _x5689 = kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context()); /*int*/
    goto _match5691;
  }
  if (kk_std_core_types__is_Eq(_x5690)) {
    _x5689 = kk_integer_from_small(0); /*int*/
    goto _match5691;
  }
  _x5689 = kk_integer_from_small(1); /*int*/
  _match5691: ;
  return kk_integer_eq(_x5688,_x5689,kk_context());
}
 
// Given a `:duration` since the `epoch`, return a `:timespan` for that instant in time scale `ts`.

kk_std_time_timestamp__timestamp kk_std_time_instant_from_tai_1(kk_std_time_instant__timescale ts0, kk_std_time_duration__duration d, kk_context_t* _ctx) { /* (ts : timescale, d : std/time/duration/duration) -> std/time/timestamp/timestamp */ 
  kk_std_time_timestamp__timestamp t_4555 = kk_std_time_duration_timestamp(d, _ctx); /*std/time/timestamp/timestamp*/;
  bool _match_5282;
  kk_string_t _x5692;
  kk_std_time_instant__timescale _x5693 = kk_std_time_instant_ts_tai; /*std/time/instant/timescale*/
  struct kk_std_time_instant_Timescale* _con5694 = kk_std_time_instant__as_Timescale(_x5693);
  kk_string_t _x = _con5694->name;
  kk_string_dup(_x);
  _x5692 = _x; /*string*/
  kk_string_t _x5695;
  struct kk_std_time_instant_Timescale* _con5696 = kk_std_time_instant__as_Timescale(ts0);
  kk_string_t _x0 = _con5696->name;
  kk_string_dup(_x0);
  _x5695 = _x0; /*string*/
  _match_5282 = kk_string_is_eq(_x5692,_x5695,kk_context()); /*bool*/
  if (_match_5282) {
    kk_std_time_instant__timescale_dropn(ts0, ((int32_t)10), _ctx);
    return t_4555;
  }
  bool _match_5283;
  bool _match_5284;
  kk_string_t _x5697;
  kk_std_time_instant__timescale _x5698 = kk_std_time_instant_ts_tai; /*std/time/instant/timescale*/
  struct kk_std_time_instant_Timescale* _con5699 = kk_std_time_instant__as_Timescale(_x5698);
  kk_string_t _x1 = _con5699->unit;
  kk_string_dup(_x1);
  _x5697 = _x1; /*string*/
  kk_string_t _x5700;
  struct kk_std_time_instant_Timescale* _con5701 = kk_std_time_instant__as_Timescale(ts0);
  kk_string_t _x2 = _con5701->unit;
  kk_string_dup(_x2);
  _x5700 = _x2; /*string*/
  _match_5284 = kk_string_is_eq(_x5697,_x5700,kk_context()); /*bool*/
  if (_match_5284) {
    kk_string_t _x5702;
    kk_std_time_instant__timescale _x5703 = kk_std_time_instant_ts_tai; /*std/time/instant/timescale*/
    struct kk_std_time_instant_Timescale* _con5704 = kk_std_time_instant__as_Timescale(_x5703);
    kk_string_t _x3 = _con5704->unit;
    kk_string_dup(_x3);
    _x5702 = _x3; /*string*/
    kk_string_t _x5705;
    kk_define_string_literal(, _s5706, 3, "UTC")
    _x5705 = kk_string_dup(_s5706); /*string*/
    _match_5283 = kk_string_is_eq(_x5702,_x5705,kk_context()); /*bool*/
  }
  else {
    _match_5283 = false; /*bool*/
  }
  if (_match_5283) {
    kk_std_time_instant__timescale_dropn(ts0, ((int32_t)10), _ctx);
    return t_4555;
  }
  kk_function_t _x5710 = kk_std_time_instant_from_tai(ts0, _ctx); /*(std/time/duration/duration) -> std/time/timestamp/timestamp*/
  kk_std_time_duration__duration _x5707;
  kk_function_t _x5708;
  kk_std_time_instant__timescale _x5709 = kk_std_time_instant__timescale_dup(kk_std_time_instant_ts_tai); /*std/time/instant/timescale*/
  _x5708 = kk_std_time_instant_to_tai(_x5709, _ctx); /*(std/time/timestamp/timestamp) -> std/time/duration/duration*/
  _x5707 = kk_function_call(kk_std_time_duration__duration, (kk_function_t, kk_std_time_timestamp__timestamp, kk_context_t*), _x5708, (_x5708, t_4555, _ctx)); /*std/time/duration/duration*/
  return kk_function_call(kk_std_time_timestamp__timestamp, (kk_function_t, kk_std_time_duration__duration, kk_context_t*), _x5710, (_x5710, _x5707, _ctx));
}
 
// Return the instant in time scale `ts`, `days` and `secs` after 2000-01-01 in that timescale.

kk_std_time_instant__instant kk_std_time_instant_instant_2(kk_std_time_instant__timescale ts0, kk_integer_t days0, kk_std_num_ddouble__ddouble secs, kk_std_core_types__optional leap, kk_context_t* _ctx) { /* (ts : timescale, days : int, secs : std/time/timestamp/timespan, leap : optional<int>) -> instant */ 
  kk_std_time_timestamp__timestamp t_4566;
  kk_std_core_types__optional _x5712 = kk_std_core_types__new_Optional(kk_std_num_ddouble__ddouble_box(secs, _ctx), _ctx); /*optional<35>*/
  kk_std_core_types__optional _x5713;
  kk_box_t _x5714;
  kk_integer_t _x5715;
  if (kk_std_core_types__is_Optional(leap)) {
    kk_box_t _box_x4805 = leap._cons.Optional.value;
    kk_integer_t _leap_1630 = kk_integer_unbox(_box_x4805);
    _x5715 = _leap_1630; /*int*/
    goto _match5716;
  }
  _x5715 = kk_integer_from_small(0); /*int*/
  _match5716: ;
  _x5714 = kk_integer_box(_x5715); /*35*/
  _x5713 = kk_std_core_types__new_Optional(_x5714, _ctx); /*optional<35>*/
  t_4566 = kk_std_time_timestamp_timestamp_days(days0, _x5712, _x5713, _ctx); /*std/time/timestamp/timestamp*/
  return kk_std_time_instant__new_Instant(kk_reuse_null, t_4566, ts0, _ctx);
}

bool kk_std_time_instant__lp__excl__eq__rp_(kk_std_time_instant__instant i, kk_std_time_instant__instant j, kk_context_t* _ctx) { /* (i : instant, j : instant) -> bool */ 
  kk_std_core_types__order x_4568 = kk_std_time_instant_compare(i, j, _ctx); /*order*/;
  kk_integer_t _x5720 = kk_std_core_int_5(x_4568, _ctx); /*int*/
  kk_integer_t _x5721;
  kk_std_core_types__order _x5722 = kk_std_core_types__new_Eq(_ctx); /*order*/
  if (kk_std_core_types__is_Lt(_x5722)) {
    _x5721 = kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context()); /*int*/
    goto _match5723;
  }
  if (kk_std_core_types__is_Eq(_x5722)) {
    _x5721 = kk_integer_from_small(0); /*int*/
    goto _match5723;
  }
  _x5721 = kk_integer_from_small(1); /*int*/
  _match5723: ;
  return kk_integer_neq(_x5720,_x5721,kk_context());
}

bool kk_std_time_instant__lp__lt__rp_(kk_std_time_instant__instant i, kk_std_time_instant__instant j, kk_context_t* _ctx) { /* (i : instant, j : instant) -> bool */ 
  kk_std_core_types__order x_4570 = kk_std_time_instant_compare(i, j, _ctx); /*order*/;
  kk_integer_t _x5724 = kk_std_core_int_5(x_4570, _ctx); /*int*/
  kk_integer_t _x5725;
  kk_std_core_types__order _x5726 = kk_std_core_types__new_Lt(_ctx); /*order*/
  if (kk_std_core_types__is_Lt(_x5726)) {
    _x5725 = kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context()); /*int*/
    goto _match5727;
  }
  if (kk_std_core_types__is_Eq(_x5726)) {
    _x5725 = kk_integer_from_small(0); /*int*/
    goto _match5727;
  }
  _x5725 = kk_integer_from_small(1); /*int*/
  _match5727: ;
  return kk_integer_eq(_x5724,_x5725,kk_context());
}

bool kk_std_time_instant__lp__lt__eq__rp_(kk_std_time_instant__instant i, kk_std_time_instant__instant j, kk_context_t* _ctx) { /* (i : instant, j : instant) -> bool */ 
  kk_std_core_types__order x_4572 = kk_std_time_instant_compare(i, j, _ctx); /*order*/;
  kk_integer_t _x5728 = kk_std_core_int_5(x_4572, _ctx); /*int*/
  kk_integer_t _x5729;
  kk_std_core_types__order _x5730 = kk_std_core_types__new_Gt(_ctx); /*order*/
  if (kk_std_core_types__is_Lt(_x5730)) {
    _x5729 = kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context()); /*int*/
    goto _match5731;
  }
  if (kk_std_core_types__is_Eq(_x5730)) {
    _x5729 = kk_integer_from_small(0); /*int*/
    goto _match5731;
  }
  _x5729 = kk_integer_from_small(1); /*int*/
  _match5731: ;
  return kk_integer_neq(_x5728,_x5729,kk_context());
}

bool kk_std_time_instant__lp__gt__rp_(kk_std_time_instant__instant i, kk_std_time_instant__instant j, kk_context_t* _ctx) { /* (i : instant, j : instant) -> bool */ 
  kk_std_core_types__order x_4574 = kk_std_time_instant_compare(i, j, _ctx); /*order*/;
  kk_integer_t _x5732 = kk_std_core_int_5(x_4574, _ctx); /*int*/
  kk_integer_t _x5733;
  kk_std_core_types__order _x5734 = kk_std_core_types__new_Gt(_ctx); /*order*/
  if (kk_std_core_types__is_Lt(_x5734)) {
    _x5733 = kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context()); /*int*/
    goto _match5735;
  }
  if (kk_std_core_types__is_Eq(_x5734)) {
    _x5733 = kk_integer_from_small(0); /*int*/
    goto _match5735;
  }
  _x5733 = kk_integer_from_small(1); /*int*/
  _match5735: ;
  return kk_integer_eq(_x5732,_x5733,kk_context());
}

bool kk_std_time_instant__lp__gt__eq__rp_(kk_std_time_instant__instant i, kk_std_time_instant__instant j, kk_context_t* _ctx) { /* (i : instant, j : instant) -> bool */ 
  kk_std_core_types__order x_4576 = kk_std_time_instant_compare(i, j, _ctx); /*order*/;
  kk_integer_t _x5736 = kk_std_core_int_5(x_4576, _ctx); /*int*/
  kk_integer_t _x5737;
  kk_std_core_types__order _x5738 = kk_std_core_types__new_Lt(_ctx); /*order*/
  if (kk_std_core_types__is_Lt(_x5738)) {
    _x5737 = kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context()); /*int*/
    goto _match5739;
  }
  if (kk_std_core_types__is_Eq(_x5738)) {
    _x5737 = kk_integer_from_small(0); /*int*/
    goto _match5739;
  }
  _x5737 = kk_integer_from_small(1); /*int*/
  _match5739: ;
  return kk_integer_neq(_x5736,_x5737,kk_context());
}
 
// Add `days` days to the instant.

kk_std_time_instant__instant kk_std_time_instant_add_days(kk_std_time_instant__instant i, kk_integer_t days0, kk_context_t* _ctx) { /* (i : instant, days : int) -> instant */ 
  kk_std_time_timestamp__timestamp _x5740;
  kk_std_time_timestamp__timestamp _x5741;
  struct kk_std_time_instant_Instant* _con5742 = kk_std_time_instant__as_Instant(i);
  kk_std_time_timestamp__timestamp _x = _con5742->since;
  kk_std_time_instant__timescale _pat2 = _con5742->ts;
  struct kk_std_time_instant_Timescale* _con5743 = kk_std_time_instant__as_Timescale(_pat2);
  _x5741 = _x; /*std/time/timestamp/timestamp*/
  _x5740 = kk_std_time_timestamp_add_days(_x5741, days0, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_time_instant__timescale _x5744;
  struct kk_std_time_instant_Instant* _con5745 = kk_std_time_instant__as_Instant(i);
  kk_std_time_timestamp__timestamp _pat00 = _con5745->since;
  kk_std_time_instant__timescale _x0 = _con5745->ts;
  struct kk_std_time_instant_Timescale* _con5746 = kk_std_time_instant__as_Timescale(_x0);
  if (kk_std_time_instant__instant_is_unique(i)) {
    kk_std_time_instant__instant_free(i);
  }
  else {
    kk_std_time_instant__timescale_dup(_x0);
    kk_std_time_instant__instant_decref(i, _ctx);
  }
  _x5744 = _x0; /*std/time/instant/timescale*/
  return kk_std_time_instant__new_Instant(kk_reuse_null, _x5740, _x5744, _ctx);
}
 
/* Add a duration of `t` seconds of time scale `tscale`.
This can for example be used to add Unix or NTP seconds where leap seconds
are ignored (allthough it is recommended in that case to use
`:time` and add logical days etc).
```
> instant(2005,12,31).add-duration-in( ts-unix, (24*3600).timespan ).time
2006-01-01T00:00:00Z
> (instant(2005,12,31) + 24.hours).time
2005-12-31T23:59:60Z
```
*/

kk_std_time_instant__instant kk_std_time_instant_add_duration_in(kk_std_time_instant__instant i, kk_std_time_instant__timescale tscale, kk_std_num_ddouble__ddouble t, kk_context_t* _ctx) { /* (i : instant, tscale : timescale, t : std/time/timestamp/timespan) -> instant */ 
  kk_std_time_instant__instant i0_4580 = kk_std_time_instant_use_timescale(i, tscale, _ctx); /*std/time/instant/instant*/;
  kk_std_time_timestamp__timestamp _x5747;
  kk_std_num_ddouble__ddouble _x5748;
  kk_std_num_ddouble__ddouble _x5749;
  kk_std_time_timestamp__timestamp _match_5276;
  struct kk_std_time_instant_Instant* _con5750 = kk_std_time_instant__as_Instant(i0_4580);
  kk_std_time_timestamp__timestamp _x1 = _con5750->since;
  kk_std_time_instant__timescale _pat21 = _con5750->ts;
  struct kk_std_time_instant_Timescale* _con5751 = kk_std_time_instant__as_Timescale(_pat21);
  _match_5276 = _x1; /*std/time/timestamp/timestamp*/
  kk_std_num_ddouble__ddouble _x = _match_5276.since;
  _x5749 = _x; /*std/time/timestamp/timespan*/
  _x5748 = kk_std_num_ddouble__lp__plus__rp_(_x5749, t, _ctx); /*std/num/ddouble/ddouble*/
  int32_t _x5752;
  kk_std_time_timestamp__timestamp _match_5275;
  struct kk_std_time_instant_Instant* _con5753 = kk_std_time_instant__as_Instant(i0_4580);
  kk_std_time_timestamp__timestamp _x10 = _con5753->since;
  kk_std_time_instant__timescale _pat210 = _con5753->ts;
  struct kk_std_time_instant_Timescale* _con5754 = kk_std_time_instant__as_Timescale(_pat210);
  _match_5275 = _x10; /*std/time/timestamp/timestamp*/
  kk_std_num_ddouble__ddouble _pat00 = _match_5275.since;
  int32_t _x0 = _match_5275.leap32;
  _x5752 = _x0; /*int32*/
  _x5747 = kk_std_time_timestamp__new_Timestamp(_x5748, _x5752, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_time_instant__timescale _x5755;
  struct kk_std_time_instant_Instant* _con5756 = kk_std_time_instant__as_Instant(i0_4580);
  kk_std_time_timestamp__timestamp _pat02 = _con5756->since;
  kk_std_time_instant__timescale _x2 = _con5756->ts;
  struct kk_std_time_instant_Timescale* _con5757 = kk_std_time_instant__as_Timescale(_x2);
  if (kk_std_time_instant__instant_is_unique(i0_4580)) {
    kk_std_time_instant__instant_free(i0_4580);
  }
  else {
    kk_std_time_instant__timescale_dup(_x2);
    kk_std_time_instant__instant_decref(i0_4580, _ctx);
  }
  _x5755 = _x2; /*std/time/instant/timescale*/
  return kk_std_time_instant__new_Instant(kk_reuse_null, _x5747, _x5755, _ctx);
}
 
// Return days since 2000-01-01 in the time scale of the instant

kk_integer_t kk_std_time_instant_days(kk_std_time_instant__instant i, kk_context_t* _ctx) { /* (i : instant) -> int */ 
  kk_std_core_types__tuple2_ _this_3806;
  kk_std_num_ddouble__ddouble secs;
  kk_std_num_ddouble__ddouble _x5758;
  kk_std_time_timestamp__timestamp _match_5274;
  struct kk_std_time_instant_Instant* _con5759 = kk_std_time_instant__as_Instant(i);
  kk_std_time_timestamp__timestamp _x00 = _con5759->since;
  kk_std_time_instant__timescale _pat21 = _con5759->ts;
  struct kk_std_time_instant_Timescale* _con5760 = kk_std_time_instant__as_Timescale(_pat21);
  _match_5274 = _x00; /*std/time/timestamp/timestamp*/
  kk_std_num_ddouble__ddouble _x = _match_5274.since;
  _x5758 = _x; /*std/time/timestamp/timespan*/
  secs = kk_std_num_ddouble_floor(_x5758, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble frac;
  kk_std_num_ddouble__ddouble _x5761;
  kk_std_time_timestamp__timestamp _match_5273;
  struct kk_std_time_instant_Instant* _con5762 = kk_std_time_instant__as_Instant(i);
  kk_std_time_timestamp__timestamp _x000 = _con5762->since;
  kk_std_time_instant__timescale _pat210 = _con5762->ts;
  struct kk_std_time_instant_Timescale* _con5763 = kk_std_time_instant__as_Timescale(_pat210);
  kk_string_t _pat300 = _con5763->name;
  kk_string_t _pat400 = _con5763->unit;
  kk_function_t _pat50 = _con5763->from_tai;
  kk_function_t _pat60 = _con5763->to_tai;
  kk_std_core_types__maybe _pat70 = _con5763->mb_seconds_in_day;
  kk_std_core_types__maybe _pat80 = _con5763->mb_to_mjd2000;
  kk_std_core_types__maybe _pat90 = _con5763->mb_from_mjd2000;
  if (kk_std_time_instant__instant_is_unique(i)) {
    if (kk_std_time_instant__timescale_is_unique(_pat210)) {
      kk_string_drop(_pat300, _ctx);
      kk_string_drop(_pat400, _ctx);
      kk_function_drop(_pat50, _ctx);
      kk_function_drop(_pat60, _ctx);
      kk_std_core_types__maybe_drop(_pat70, _ctx);
      kk_std_core_types__maybe_drop(_pat80, _ctx);
      kk_std_core_types__maybe_drop(_pat90, _ctx);
      kk_std_time_instant__timescale_free(_pat210);
    }
    else {
      kk_std_time_instant__timescale_decref(_pat210, _ctx);
    }
    kk_std_time_instant__instant_free(i);
  }
  else {
    kk_std_time_instant__instant_decref(i, _ctx);
  }
  _match_5273 = _x000; /*std/time/timestamp/timestamp*/
  kk_std_num_ddouble__ddouble _x0 = _match_5273.since;
  _x5761 = _x0; /*std/time/timestamp/timespan*/
  kk_std_num_ddouble__ddouble _x5764 = kk_std_num_ddouble__lp__tilde__rp_(secs, _ctx); /*std/num/ddouble/ddouble*/
  frac = kk_std_num_ddouble__lp__plus__rp_(_x5761, _x5764, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_core_types__tuple2_ _match_5272;
  kk_integer_t _x5765 = kk_std_num_ddouble_int(secs, kk_std_core_types__new_None(_ctx), _ctx); /*int*/
  _match_5272 = kk_integer_div_mod_tuple(_x5765,(kk_integer_from_int(86400, _ctx)),kk_context()); /*(int, int)*/
  kk_box_t _box_x4809 = _match_5272.fst;
  kk_box_t _box_x4810 = _match_5272.snd;
  kk_integer_t days0 = kk_integer_unbox(_box_x4809);
  kk_integer_t dsecs = kk_integer_unbox(_box_x4810);
  kk_std_num_ddouble__ddouble _b_4814_4812;
  kk_std_num_ddouble__ddouble _x5768 = kk_std_num_ddouble_ddouble_1(dsecs, _ctx); /*std/num/ddouble/ddouble*/
  _b_4814_4812 = kk_std_num_ddouble__lp__plus__rp_(_x5768, frac, _ctx); /*std/num/ddouble/ddouble*/
  _this_3806 = kk_std_core_types__new_dash__lp__comma__rp_(kk_integer_box(days0), kk_std_num_ddouble__ddouble_box(_b_4814_4812, _ctx), _ctx); /*(int, std/num/ddouble/ddouble)*/
  kk_box_t _box_x4815 = _this_3806.fst;
  kk_box_t _box_x4816 = _this_3806.snd;
  kk_integer_t _x1 = kk_integer_unbox(_box_x4815);
  kk_integer_dup(_x1);
  kk_std_core_types__tuple2__drop(_this_3806, _ctx);
  return _x1;
}
 
// Return days since 2000-01-01 in the time scale of the instant,
// together with the clock on that day.

kk_std_core_types__tuple2_ kk_std_time_instant_days_clock(kk_std_time_instant__instant i, kk_context_t* _ctx) { /* (i : instant) -> (int, std/time/date/clock) */ 
  kk_std_core_types__tuple2_ _match_5271;
  kk_std_time_timestamp__timestamp _x5771;
  struct kk_std_time_instant_Instant* _con5772 = kk_std_time_instant__as_Instant(i);
  kk_std_time_timestamp__timestamp _x = _con5772->since;
  kk_std_time_instant__timescale _pat20 = _con5772->ts;
  struct kk_std_time_instant_Timescale* _con5773 = kk_std_time_instant__as_Timescale(_pat20);
  _x5771 = _x; /*std/time/timestamp/timestamp*/
  _match_5271 = kk_std_time_timestamp_days_seconds(_x5771, _ctx); /*(int, std/num/ddouble/ddouble)*/
  kk_box_t _box_x4817 = _match_5271.fst;
  kk_box_t _box_x4818 = _match_5271.snd;
  kk_integer_t days0 = kk_integer_unbox(_box_x4817);
  kk_std_num_ddouble__ddouble secs = kk_std_num_ddouble__ddouble_unbox(_box_x4818, NULL);
  kk_std_time_date__clock _b_4822_4820;
  kk_integer_t _x5776;
  kk_std_time_timestamp__timestamp _x5777;
  struct kk_std_time_instant_Instant* _con5778 = kk_std_time_instant__as_Instant(i);
  kk_std_time_timestamp__timestamp _x0 = _con5778->since;
  kk_std_time_instant__timescale _pat200 = _con5778->ts;
  struct kk_std_time_instant_Timescale* _con5779 = kk_std_time_instant__as_Timescale(_pat200);
  kk_string_t _pat30 = _con5779->name;
  kk_string_t _pat40 = _con5779->unit;
  kk_function_t _pat50 = _con5779->from_tai;
  kk_function_t _pat60 = _con5779->to_tai;
  kk_std_core_types__maybe _pat70 = _con5779->mb_seconds_in_day;
  kk_std_core_types__maybe _pat80 = _con5779->mb_to_mjd2000;
  kk_std_core_types__maybe _pat90 = _con5779->mb_from_mjd2000;
  if (kk_std_time_instant__instant_is_unique(i)) {
    if (kk_std_time_instant__timescale_is_unique(_pat200)) {
      kk_string_drop(_pat30, _ctx);
      kk_string_drop(_pat40, _ctx);
      kk_function_drop(_pat50, _ctx);
      kk_function_drop(_pat60, _ctx);
      kk_std_core_types__maybe_drop(_pat70, _ctx);
      kk_std_core_types__maybe_drop(_pat80, _ctx);
      kk_std_core_types__maybe_drop(_pat90, _ctx);
      kk_std_time_instant__timescale_free(_pat200);
    }
    else {
      kk_std_time_instant__timescale_decref(_pat200, _ctx);
    }
    kk_std_time_instant__instant_free(i);
  }
  else {
    kk_std_time_instant__instant_decref(i, _ctx);
  }
  _x5777 = _x0; /*std/time/timestamp/timestamp*/
  _x5776 = kk_std_time_timestamp_leap(_x5777, _ctx); /*int*/
  _b_4822_4820 = kk_std_time_date_clock_3(secs, _x5776, _ctx); /*std/time/date/clock*/
  return kk_std_core_types__new_dash__lp__comma__rp_(kk_integer_box(days0), kk_std_time_date__clock_box(_b_4822_4820, _ctx), _ctx);
}

kk_std_time_instant__instant kk_std_time_instant_epoch;

kk_std_time_duration__duration kk_std_time_instant_gps2000;
 
// Create an instant from a raw GPS time since the GPS epoch (1980-01-06Z)

kk_std_time_instant__instant kk_std_time_instant_gps_instant(kk_std_time_duration__duration gps, kk_context_t* _ctx) { /* (gps : std/time/duration/duration) -> instant */ 
  kk_std_time_duration__duration d_4590;
  kk_std_time_duration__duration e_4737 = kk_std_time_duration_duration_1(kk_integer_from_int(630720000, _ctx), kk_std_core_types__new_None(_ctx), _ctx); /*std/time/duration/duration*/;
  kk_std_time_duration__duration e0_2276 = kk_std_time_duration__lp__tilde__rp_(e_4737, _ctx); /*std/time/duration/duration*/;
  kk_std_num_ddouble__ddouble _x5780;
  kk_std_num_ddouble__ddouble _x5781;
  kk_std_num_ddouble__ddouble _x = gps.secs;
  _x5781 = _x; /*std/time/timestamp/timespan*/
  kk_std_num_ddouble__ddouble _x5782;
  kk_std_num_ddouble__ddouble _x0 = e0_2276.secs;
  _x5782 = _x0; /*std/time/timestamp/timespan*/
  _x5780 = kk_std_num_ddouble__lp__plus__rp_(_x5781, _x5782, _ctx); /*std/num/ddouble/ddouble*/
  d_4590 = kk_std_time_duration__new_Duration(_x5780, _ctx); /*std/time/duration/duration*/
  kk_std_time_timestamp__timestamp t_4592 = kk_std_time_duration_timestamp(d_4590, _ctx); /*std/time/timestamp/timestamp*/;
  kk_std_time_instant__timescale _x5783 = kk_std_time_instant__timescale_dup(kk_std_time_instant_ts_tai); /*std/time/instant/timescale*/
  return kk_std_time_instant__new_Instant(kk_reuse_null, t_4592, _x5783, _ctx);
}
 
// Create an instant from a GPS time in weeks and SI seconds since the GPS epoch (1980-01-06Z)

kk_std_time_instant__instant kk_std_time_instant_gps_instant_1(kk_integer_t weeks, kk_std_time_duration__duration secs, kk_context_t* _ctx) { /* (weeks : int, secs : std/time/duration/duration) -> instant */ 
  kk_std_time_duration__duration gps_4593;
  kk_std_time_duration__duration d0_4594;
  kk_integer_t _x5784 = kk_integer_mul(weeks,(kk_integer_from_int(25200, _ctx)),kk_context()); /*int*/
  d0_4594 = kk_std_time_duration_duration_1(_x5784, kk_std_core_types__new_None(_ctx), _ctx); /*std/time/duration/duration*/
  kk_std_num_ddouble__ddouble _x5785;
  kk_std_num_ddouble__ddouble _x5786;
  kk_std_num_ddouble__ddouble _x = d0_4594.secs;
  _x5786 = _x; /*std/time/timestamp/timespan*/
  kk_std_num_ddouble__ddouble _x5787;
  kk_std_num_ddouble__ddouble _x0 = secs.secs;
  _x5787 = _x0; /*std/time/timestamp/timespan*/
  _x5785 = kk_std_num_ddouble__lp__plus__rp_(_x5786, _x5787, _ctx); /*std/num/ddouble/ddouble*/
  gps_4593 = kk_std_time_duration__new_Duration(_x5785, _ctx); /*std/time/duration/duration*/
  kk_std_time_duration__duration d_4596;
  kk_std_time_duration__duration e_4739 = kk_std_time_duration_duration_1(kk_integer_from_int(630720000, _ctx), kk_std_core_types__new_None(_ctx), _ctx); /*std/time/duration/duration*/;
  kk_std_time_duration__duration e0_2276 = kk_std_time_duration__lp__tilde__rp_(e_4739, _ctx); /*std/time/duration/duration*/;
  kk_std_num_ddouble__ddouble _x5788;
  kk_std_num_ddouble__ddouble _x5789;
  kk_std_num_ddouble__ddouble _x1 = gps_4593.secs;
  _x5789 = _x1; /*std/time/timestamp/timespan*/
  kk_std_num_ddouble__ddouble _x5790;
  kk_std_num_ddouble__ddouble _x00 = e0_2276.secs;
  _x5790 = _x00; /*std/time/timestamp/timespan*/
  _x5788 = kk_std_num_ddouble__lp__plus__rp_(_x5789, _x5790, _ctx); /*std/num/ddouble/ddouble*/
  d_4596 = kk_std_time_duration__new_Duration(_x5788, _ctx); /*std/time/duration/duration*/
  kk_std_time_timestamp__timestamp t_4598 = kk_std_time_duration_timestamp(d_4596, _ctx); /*std/time/timestamp/timestamp*/;
  kk_std_time_instant__timescale _x5791 = kk_std_time_instant__timescale_dup(kk_std_time_instant_ts_tai); /*std/time/instant/timescale*/
  return kk_std_time_instant__new_Instant(kk_reuse_null, t_4598, _x5791, _ctx);
}
 
// The [GPS](https://en.wikipedia.org/wiki/Global_Positioning_System#Timekeeping) time scale based
// on SI seconds with a 1980-01-06 GPS epoch.
// GPS = TAI - 19s.


// lift anonymous function
struct kk_std_time_instant_ts_gps_fun5803__t {
  struct kk_function_s _base;
  kk_std_time_duration__duration _offset_990;
};
static kk_std_time_timestamp__timestamp kk_std_time_instant_ts_gps_fun5803(kk_function_t _fself, kk_std_time_duration__duration tai, kk_context_t* _ctx);
static kk_function_t kk_std_time_instant_new_ts_gps_fun5803(kk_std_time_duration__duration _offset_990, kk_context_t* _ctx) {
  struct kk_std_time_instant_ts_gps_fun5803__t* _self = kk_function_alloc_as(struct kk_std_time_instant_ts_gps_fun5803__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_time_instant_ts_gps_fun5803, kk_context());
  _self->_offset_990 = _offset_990;
  return &_self->_base;
}

static kk_std_time_timestamp__timestamp kk_std_time_instant_ts_gps_fun5803(kk_function_t _fself, kk_std_time_duration__duration tai, kk_context_t* _ctx) {
  struct kk_std_time_instant_ts_gps_fun5803__t* _self = kk_function_as(struct kk_std_time_instant_ts_gps_fun5803__t*, _fself);
  kk_std_time_duration__duration _offset_990 = _self->_offset_990; /* std/time/duration/duration */
  kk_drop_match(_self, {kk_std_time_duration__duration_dup(_offset_990);}, {}, _ctx)
  kk_std_num_ddouble__ddouble t_4609;
  kk_std_num_ddouble__ddouble _x5804;
  kk_std_num_ddouble__ddouble _x0 = tai.secs;
  _x5804 = _x0; /*std/time/timestamp/timespan*/
  kk_std_num_ddouble__ddouble _x5805;
  kk_std_num_ddouble__ddouble _x = _offset_990.secs;
  _x5805 = _x; /*std/time/timestamp/timespan*/
  t_4609 = kk_std_num_ddouble__lp__plus__rp_(_x5804, _x5805, _ctx); /*std/time/timestamp/timespan*/
  int32_t _x5806;
  kk_integer_t _x5807;
  kk_std_core_types__optional _x5808 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/
  if (kk_std_core_types__is_Optional(_x5808)) {
    kk_box_t _box_x4829 = _x5808._cons.Optional.value;
    kk_integer_t _leap_492 = kk_integer_unbox(_box_x4829);
    _x5807 = _leap_492; /*int*/
    goto _match5809;
  }
  _x5807 = kk_integer_from_small(0); /*int*/
  _match5809: ;
  _x5806 = kk_std_core_int32(_x5807, _ctx); /*int32*/
  return kk_std_time_timestamp__new_Timestamp(t_4609, _x5806, _ctx);
}


// lift anonymous function
struct kk_std_time_instant_ts_gps_fun5811__t {
  struct kk_function_s _base;
  kk_std_time_duration__duration _offset_990;
};
static kk_std_time_duration__duration kk_std_time_instant_ts_gps_fun5811(kk_function_t _fself, kk_std_time_timestamp__timestamp t0, kk_context_t* _ctx);
static kk_function_t kk_std_time_instant_new_ts_gps_fun5811(kk_std_time_duration__duration _offset_990, kk_context_t* _ctx) {
  struct kk_std_time_instant_ts_gps_fun5811__t* _self = kk_function_alloc_as(struct kk_std_time_instant_ts_gps_fun5811__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_time_instant_ts_gps_fun5811, kk_context());
  _self->_offset_990 = _offset_990;
  return &_self->_base;
}

static kk_std_time_duration__duration kk_std_time_instant_ts_gps_fun5811(kk_function_t _fself, kk_std_time_timestamp__timestamp t0, kk_context_t* _ctx) {
  struct kk_std_time_instant_ts_gps_fun5811__t* _self = kk_function_as(struct kk_std_time_instant_ts_gps_fun5811__t*, _fself);
  kk_std_time_duration__duration _offset_990 = _self->_offset_990; /* std/time/duration/duration */
  kk_drop_match(_self, {kk_std_time_duration__duration_dup(_offset_990);}, {}, _ctx)
  kk_std_time_timestamp__timestamp t1_4612;
  kk_std_num_ddouble__ddouble _x5812;
  kk_std_num_ddouble__ddouble _x1 = _offset_990.secs;
  _x5812 = _x1; /*std/time/timestamp/timespan*/
  t1_4612 = kk_std_time_timestamp__lp__dash__rp_(t0, _x5812, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_num_ddouble__ddouble _x5813 = kk_std_time_timestamp_unsafe_timespan_withleap(t1_4612, _ctx); /*std/time/timestamp/timespan*/
  return kk_std_time_duration__new_Duration(_x5813, _ctx);
}

kk_std_time_instant__timescale kk_std_time_instant_ts_gps;
 
// Get the GPS time in SI seconds since the GPS epoch (1980-01-06Z)

kk_std_time_duration__duration kk_std_time_instant_gps_timestamp(kk_std_time_instant__instant i, kk_context_t* _ctx) { /* (i : instant) -> std/time/duration/duration */ 
  kk_std_time_duration__duration d_4613;
  kk_std_time_timestamp__timestamp t_4615;
  kk_std_time_instant__timescale _x5826 = kk_std_time_instant__timescale_dup(kk_std_time_instant_ts_gps); /*std/time/instant/timescale*/
  t_4615 = kk_std_time_instant_timestamp_in(i, _x5826, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_num_ddouble__ddouble _x5827 = kk_std_time_timestamp_unsafe_timespan_withleap(t_4615, _ctx); /*std/time/timestamp/timespan*/
  d_4613 = kk_std_time_duration__new_Duration(_x5827, _ctx); /*std/time/duration/duration*/
  kk_std_time_duration__duration e_4614 = kk_std_time_duration_duration_1(kk_integer_from_int(630720000, _ctx), kk_std_core_types__new_None(_ctx), _ctx); /*std/time/duration/duration*/;
  kk_std_num_ddouble__ddouble _x5828;
  kk_std_num_ddouble__ddouble _x5829;
  kk_std_num_ddouble__ddouble _x = d_4613.secs;
  _x5829 = _x; /*std/time/timestamp/timespan*/
  kk_std_num_ddouble__ddouble _x5830;
  kk_std_num_ddouble__ddouble _x0 = e_4614.secs;
  _x5830 = _x0; /*std/time/timestamp/timespan*/
  _x5828 = kk_std_num_ddouble__lp__plus__rp_(_x5829, _x5830, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_time_duration__new_Duration(_x5828, _ctx);
}
 
// Get the GPS time as weeks and SI seconds in the week since the GPS epoch (1980-01-06Z)

kk_std_core_types__tuple2_ kk_std_time_instant_gps_week_timestamp(kk_std_time_instant__instant i, kk_context_t* _ctx) { /* (i : instant) -> (int, std/time/duration/duration) */ 
  kk_std_time_duration__duration t = kk_std_time_instant_gps_timestamp(i, _ctx); /*std/time/duration/duration*/;
  kk_integer_t w;
  kk_std_num_ddouble__ddouble _x5831;
  kk_std_num_ddouble__ddouble _x5832;
  kk_std_num_ddouble__ddouble _x5833;
  kk_std_num_ddouble__ddouble _x = t.secs;
  _x5833 = _x; /*std/time/timestamp/timespan*/
  kk_std_num_ddouble__ddouble _x5834 = kk_std_num_ddouble_ddouble_int_exp(kk_integer_from_int(25200, _ctx), kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
  _x5832 = kk_std_num_ddouble__lp__fs__rp_(_x5833, _x5834, _ctx); /*std/num/ddouble/ddouble*/
  _x5831 = kk_std_num_ddouble_floor(_x5832, _ctx); /*std/num/ddouble/ddouble*/
  w = kk_std_num_ddouble_int(_x5831, kk_std_core_types__new_None(_ctx), _ctx); /*int*/
  kk_std_time_duration__duration s;
  kk_std_time_duration__duration e_4619;
  kk_integer_t _x5835;
  kk_integer_t _x5836 = kk_integer_dup(w); /*int*/
  _x5835 = kk_integer_mul(_x5836,(kk_integer_from_int(25200, _ctx)),kk_context()); /*int*/
  e_4619 = kk_std_time_duration_duration_1(_x5835, kk_std_core_types__new_None(_ctx), _ctx); /*std/time/duration/duration*/
  kk_std_time_duration__duration e0_2276 = kk_std_time_duration__lp__tilde__rp_(e_4619, _ctx); /*std/time/duration/duration*/;
  kk_std_num_ddouble__ddouble _x5837;
  kk_std_num_ddouble__ddouble _x5838;
  kk_std_num_ddouble__ddouble _x0 = t.secs;
  _x5838 = _x0; /*std/time/timestamp/timespan*/
  kk_std_num_ddouble__ddouble _x5839;
  kk_std_num_ddouble__ddouble _x00 = e0_2276.secs;
  _x5839 = _x00; /*std/time/timestamp/timespan*/
  _x5837 = kk_std_num_ddouble__lp__plus__rp_(_x5838, _x5839, _ctx); /*std/num/ddouble/ddouble*/
  s = kk_std_time_duration__new_Duration(_x5837, _ctx); /*std/time/duration/duration*/
  return kk_std_core_types__new_dash__lp__comma__rp_(kk_integer_box(w), kk_std_time_duration__duration_box(s, _ctx), _ctx);
}
 
// Create an instant given a [modified julian day](https://en.wikipedia.org/wiki/Julian_day).
// and time scale `ts`.
// `modified-julian-day = julian-day - 2400000.5`

kk_std_time_instant__instant kk_std_time_instant_instant_at_mjd_1(kk_std_num_ddouble__ddouble mjd0, kk_std_time_instant__timescale ts0, kk_context_t* _ctx) { /* (mjd : std/num/ddouble/ddouble, ts : timescale) -> instant */ 
  kk_std_num_ddouble__ddouble d = kk_std_num_ddouble__lp__dash__rp_(mjd0, kk_std_time_instant_mjd_epoch_delta, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__ddouble days0 = kk_std_num_ddouble_floor(d, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__ddouble frac = kk_std_num_ddouble__lp__dash__rp_(d, days0, _ctx); /*std/num/ddouble/ddouble*/;
  kk_integer_t idays = kk_std_num_ddouble_int(days0, kk_std_core_types__new_None(_ctx), _ctx); /*int*/;
  kk_std_core_types__maybe _match_5265;
  struct kk_std_time_instant_Timescale* _con5840 = kk_std_time_instant__as_Timescale(ts0);
  kk_std_core_types__maybe _x = _con5840->mb_from_mjd2000;
  kk_std_core_types__maybe_dup(_x);
  _match_5265 = _x; /*maybe<(days : int, frac : std/num/ddouble/ddouble) -> std/time/timestamp/timestamp>*/
  if (kk_std_core_types__is_Nothing(_match_5265)) {
    kk_std_num_ddouble__ddouble secs_4623 = kk_std_num_ddouble__lp__star__rp_(frac, kk_std_time_timestamp_solar_secs_per_day, _ctx); /*std/time/timestamp/timespan*/;
    kk_std_time_timestamp__timestamp t_4626;
    kk_std_core_types__optional _x5841 = kk_std_core_types__new_Optional(kk_std_num_ddouble__ddouble_box(secs_4623, _ctx), _ctx); /*optional<35>*/
    kk_std_core_types__optional _x5842;
    kk_box_t _x5843;
    kk_integer_t _x5844;
    kk_std_core_types__optional _x5845 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/
    if (kk_std_core_types__is_Optional(_x5845)) {
      kk_box_t _box_x4838 = _x5845._cons.Optional.value;
      kk_integer_t _leap_1630 = kk_integer_unbox(_box_x4838);
      _x5844 = _leap_1630; /*int*/
      goto _match5846;
    }
    _x5844 = kk_integer_from_small(0); /*int*/
    _match5846: ;
    _x5843 = kk_integer_box(_x5844); /*35*/
    _x5842 = kk_std_core_types__new_Optional(_x5843, _ctx); /*optional<35>*/
    t_4626 = kk_std_time_timestamp_timestamp_days(idays, _x5841, _x5842, _ctx); /*std/time/timestamp/timestamp*/
    return kk_std_time_instant__new_Instant(kk_reuse_null, t_4626, ts0, _ctx);
  }
  kk_box_t _fun_unbox_x4847 = _match_5265._cons.Just.value;
  kk_std_time_timestamp__timestamp t0_4628;
  kk_box_t _x5848;
  kk_function_t _x5849 = kk_function_unbox(_fun_unbox_x4847); /*(days : 4848, frac : 4849) -> 4850*/
  _x5848 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _x5849, (_x5849, kk_integer_box(idays), kk_std_num_ddouble__ddouble_box(frac, _ctx), _ctx)); /*4850*/
  t0_4628 = kk_std_time_timestamp__timestamp_unbox(_x5848, _ctx); /*std/time/timestamp/timestamp*/
  return kk_std_time_instant__new_Instant(kk_reuse_null, t0_4628, ts0, _ctx);
}
 
// Create an instant given a [modified julian day](https://en.wikipedia.org/wiki/Julian_day).
// and time scale `ts`.
// `modified-julian-day = julian-day - 2400000.5`

kk_std_time_instant__instant kk_std_time_instant_instant_at_mjd(double mjd0, kk_std_time_instant__timescale ts0, kk_context_t* _ctx) { /* (mjd : double, ts : timescale) -> instant */ 
  kk_std_num_ddouble__ddouble mjd0_4629 = kk_std_num_ddouble_ddouble(mjd0, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__ddouble d = kk_std_num_ddouble__lp__dash__rp_(mjd0_4629, kk_std_time_instant_mjd_epoch_delta, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__ddouble days0 = kk_std_num_ddouble_floor(d, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__ddouble frac = kk_std_num_ddouble__lp__dash__rp_(d, days0, _ctx); /*std/num/ddouble/ddouble*/;
  kk_integer_t idays = kk_std_num_ddouble_int(days0, kk_std_core_types__new_None(_ctx), _ctx); /*int*/;
  kk_std_core_types__maybe _match_5263;
  struct kk_std_time_instant_Timescale* _con5850 = kk_std_time_instant__as_Timescale(ts0);
  kk_std_core_types__maybe _x = _con5850->mb_from_mjd2000;
  kk_std_core_types__maybe_dup(_x);
  _match_5263 = _x; /*maybe<(days : int, frac : std/num/ddouble/ddouble) -> std/time/timestamp/timestamp>*/
  if (kk_std_core_types__is_Nothing(_match_5263)) {
    kk_std_num_ddouble__ddouble secs_4634 = kk_std_num_ddouble__lp__star__rp_(frac, kk_std_time_timestamp_solar_secs_per_day, _ctx); /*std/time/timestamp/timespan*/;
    kk_std_time_timestamp__timestamp t_4637;
    kk_std_core_types__optional _x5851 = kk_std_core_types__new_Optional(kk_std_num_ddouble__ddouble_box(secs_4634, _ctx), _ctx); /*optional<35>*/
    kk_std_core_types__optional _x5852;
    kk_box_t _x5853;
    kk_integer_t _x5854;
    kk_std_core_types__optional _x5855 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/
    if (kk_std_core_types__is_Optional(_x5855)) {
      kk_box_t _box_x4856 = _x5855._cons.Optional.value;
      kk_integer_t _leap_1630 = kk_integer_unbox(_box_x4856);
      _x5854 = _leap_1630; /*int*/
      goto _match5856;
    }
    _x5854 = kk_integer_from_small(0); /*int*/
    _match5856: ;
    _x5853 = kk_integer_box(_x5854); /*35*/
    _x5852 = kk_std_core_types__new_Optional(_x5853, _ctx); /*optional<35>*/
    t_4637 = kk_std_time_timestamp_timestamp_days(idays, _x5851, _x5852, _ctx); /*std/time/timestamp/timestamp*/
    return kk_std_time_instant__new_Instant(kk_reuse_null, t_4637, ts0, _ctx);
  }
  kk_box_t _fun_unbox_x4865 = _match_5263._cons.Just.value;
  kk_std_time_timestamp__timestamp t0_4639;
  kk_box_t _x5858;
  kk_function_t _x5859 = kk_function_unbox(_fun_unbox_x4865); /*(days : 4866, frac : 4867) -> 4868*/
  _x5858 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _x5859, (_x5859, kk_integer_box(idays), kk_std_num_ddouble__ddouble_box(frac, _ctx), _ctx)); /*4868*/
  t0_4639 = kk_std_time_timestamp__timestamp_unbox(_x5858, _ctx); /*std/time/timestamp/timestamp*/
  return kk_std_time_instant__new_Instant(kk_reuse_null, t0_4639, ts0, _ctx);
}
 
// Create an instant given a [julian day](https://en.wikipedia.org/wiki/Julian_day)
// and time scale `ts` .

kk_std_time_instant__instant kk_std_time_instant_instant_at_jd_1(kk_std_num_ddouble__ddouble jd0, kk_std_time_instant__timescale ts0, kk_context_t* _ctx) { /* (jd : std/num/ddouble/ddouble, ts : timescale) -> instant */ 
  kk_std_num_ddouble__ddouble mjd_4640 = kk_std_num_ddouble__lp__dash__rp_(jd0, kk_std_time_instant_jd_epoch_delta, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__ddouble d = kk_std_num_ddouble__lp__dash__rp_(mjd_4640, kk_std_time_instant_mjd_epoch_delta, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__ddouble days0 = kk_std_num_ddouble_floor(d, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__ddouble frac = kk_std_num_ddouble__lp__dash__rp_(d, days0, _ctx); /*std/num/ddouble/ddouble*/;
  kk_integer_t idays = kk_std_num_ddouble_int(days0, kk_std_core_types__new_None(_ctx), _ctx); /*int*/;
  kk_std_core_types__maybe _match_5261;
  struct kk_std_time_instant_Timescale* _con5860 = kk_std_time_instant__as_Timescale(ts0);
  kk_std_core_types__maybe _x = _con5860->mb_from_mjd2000;
  kk_std_core_types__maybe_dup(_x);
  _match_5261 = _x; /*maybe<(days : int, frac : std/num/ddouble/ddouble) -> std/time/timestamp/timestamp>*/
  if (kk_std_core_types__is_Nothing(_match_5261)) {
    kk_std_num_ddouble__ddouble secs_4645 = kk_std_num_ddouble__lp__star__rp_(frac, kk_std_time_timestamp_solar_secs_per_day, _ctx); /*std/time/timestamp/timespan*/;
    kk_std_time_timestamp__timestamp t_4648;
    kk_std_core_types__optional _x5861 = kk_std_core_types__new_Optional(kk_std_num_ddouble__ddouble_box(secs_4645, _ctx), _ctx); /*optional<35>*/
    kk_std_core_types__optional _x5862;
    kk_box_t _x5863;
    kk_integer_t _x5864;
    kk_std_core_types__optional _x5865 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/
    if (kk_std_core_types__is_Optional(_x5865)) {
      kk_box_t _box_x4874 = _x5865._cons.Optional.value;
      kk_integer_t _leap_1630 = kk_integer_unbox(_box_x4874);
      _x5864 = _leap_1630; /*int*/
      goto _match5866;
    }
    _x5864 = kk_integer_from_small(0); /*int*/
    _match5866: ;
    _x5863 = kk_integer_box(_x5864); /*35*/
    _x5862 = kk_std_core_types__new_Optional(_x5863, _ctx); /*optional<35>*/
    t_4648 = kk_std_time_timestamp_timestamp_days(idays, _x5861, _x5862, _ctx); /*std/time/timestamp/timestamp*/
    return kk_std_time_instant__new_Instant(kk_reuse_null, t_4648, ts0, _ctx);
  }
  kk_box_t _fun_unbox_x4883 = _match_5261._cons.Just.value;
  kk_std_time_timestamp__timestamp t0_4650;
  kk_box_t _x5868;
  kk_function_t _x5869 = kk_function_unbox(_fun_unbox_x4883); /*(days : 4884, frac : 4885) -> 4886*/
  _x5868 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _x5869, (_x5869, kk_integer_box(idays), kk_std_num_ddouble__ddouble_box(frac, _ctx), _ctx)); /*4886*/
  t0_4650 = kk_std_time_timestamp__timestamp_unbox(_x5868, _ctx); /*std/time/timestamp/timestamp*/
  return kk_std_time_instant__new_Instant(kk_reuse_null, t0_4650, ts0, _ctx);
}
 
// Create an instant given a [julian day](https://en.wikipedia.org/wiki/Julian_day).

kk_std_time_instant__instant kk_std_time_instant_instant_at_jd(double jd0, kk_std_time_instant__timescale ts0, kk_context_t* _ctx) { /* (jd : double, ts : timescale) -> instant */ 
  kk_std_num_ddouble__ddouble jd0_4651 = kk_std_num_ddouble_ddouble(jd0, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__ddouble mjd_4653 = kk_std_num_ddouble__lp__dash__rp_(jd0_4651, kk_std_time_instant_jd_epoch_delta, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__ddouble d = kk_std_num_ddouble__lp__dash__rp_(mjd_4653, kk_std_time_instant_mjd_epoch_delta, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__ddouble days0 = kk_std_num_ddouble_floor(d, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__ddouble frac = kk_std_num_ddouble__lp__dash__rp_(d, days0, _ctx); /*std/num/ddouble/ddouble*/;
  kk_integer_t idays = kk_std_num_ddouble_int(days0, kk_std_core_types__new_None(_ctx), _ctx); /*int*/;
  kk_std_core_types__maybe _match_5259;
  struct kk_std_time_instant_Timescale* _con5870 = kk_std_time_instant__as_Timescale(ts0);
  kk_std_core_types__maybe _x = _con5870->mb_from_mjd2000;
  kk_std_core_types__maybe_dup(_x);
  _match_5259 = _x; /*maybe<(days : int, frac : std/num/ddouble/ddouble) -> std/time/timestamp/timestamp>*/
  if (kk_std_core_types__is_Nothing(_match_5259)) {
    kk_std_num_ddouble__ddouble secs_4658 = kk_std_num_ddouble__lp__star__rp_(frac, kk_std_time_timestamp_solar_secs_per_day, _ctx); /*std/time/timestamp/timespan*/;
    kk_std_time_timestamp__timestamp t_4661;
    kk_std_core_types__optional _x5871 = kk_std_core_types__new_Optional(kk_std_num_ddouble__ddouble_box(secs_4658, _ctx), _ctx); /*optional<35>*/
    kk_std_core_types__optional _x5872;
    kk_box_t _x5873;
    kk_integer_t _x5874;
    kk_std_core_types__optional _x5875 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/
    if (kk_std_core_types__is_Optional(_x5875)) {
      kk_box_t _box_x4892 = _x5875._cons.Optional.value;
      kk_integer_t _leap_1630 = kk_integer_unbox(_box_x4892);
      _x5874 = _leap_1630; /*int*/
      goto _match5876;
    }
    _x5874 = kk_integer_from_small(0); /*int*/
    _match5876: ;
    _x5873 = kk_integer_box(_x5874); /*35*/
    _x5872 = kk_std_core_types__new_Optional(_x5873, _ctx); /*optional<35>*/
    t_4661 = kk_std_time_timestamp_timestamp_days(idays, _x5871, _x5872, _ctx); /*std/time/timestamp/timestamp*/
    return kk_std_time_instant__new_Instant(kk_reuse_null, t_4661, ts0, _ctx);
  }
  kk_box_t _fun_unbox_x4901 = _match_5259._cons.Just.value;
  kk_std_time_timestamp__timestamp t0_4663;
  kk_box_t _x5878;
  kk_function_t _x5879 = kk_function_unbox(_fun_unbox_x4901); /*(days : 4902, frac : 4903) -> 4904*/
  _x5878 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _x5879, (_x5879, kk_integer_box(idays), kk_std_num_ddouble__ddouble_box(frac, _ctx), _ctx)); /*4904*/
  t0_4663 = kk_std_time_timestamp__timestamp_unbox(_x5878, _ctx); /*std/time/timestamp/timestamp*/
  return kk_std_time_instant__new_Instant(kk_reuse_null, t0_4663, ts0, _ctx);
}
 
// Return the modified julian day in a given time scale `ts` for an instant `i`.
// Can also pass an optional `delta` (=`timespan0`) that is added to the raw timestamp of `i`
// before conversion (used in `std/time/time` to take timezones into account)

kk_std_num_ddouble__ddouble kk_std_time_instant_mjd(kk_std_time_instant__instant i, kk_std_time_instant__timescale tscale, kk_std_core_types__optional tzdelta, kk_context_t* _ctx) { /* (i : instant, tscale : timescale, tzdelta : optional<std/time/timestamp/timespan>) -> std/num/ddouble/ddouble */ 
  kk_std_time_instant__instant i0;
  kk_std_time_instant__timescale _x5880 = kk_std_time_instant__timescale_dup(tscale); /*std/time/instant/timescale*/
  i0 = kk_std_time_instant_use_timescale(i, _x5880, _ctx); /*std/time/instant/instant*/
  kk_std_num_ddouble__ddouble mjd0;
  kk_std_core_types__maybe _match_5256;
  struct kk_std_time_instant_Timescale* _con5881 = kk_std_time_instant__as_Timescale(tscale);
  kk_std_core_types__maybe _x = _con5881->mb_to_mjd2000;
  kk_std_core_types__maybe_dup(_x);
  _match_5256 = _x; /*maybe<(t : std/time/timestamp/timestamp, tzdelta : std/time/timestamp/timespan) -> std/num/ddouble/ddouble>*/
  if (kk_std_core_types__is_Nothing(_match_5256)) {
    kk_std_time_instant__instant i10;
    kk_std_num_ddouble__ddouble t_4667;
    if (kk_std_core_types__is_Optional(tzdelta)) {
      kk_box_t _box_x4909 = tzdelta._cons.Optional.value;
      kk_std_num_ddouble__ddouble _tzdelta_3557 = kk_std_num_ddouble__ddouble_unbox(_box_x4909, NULL);
      t_4667 = _tzdelta_3557; /*std/time/timestamp/timespan*/
      goto _match5882;
    }
    t_4667 = kk_std_num_ddouble__new_Ddouble(0x0p+0, 0x0p+0, _ctx); /*std/time/timestamp/timespan*/
    _match5882: ;
    kk_std_time_instant__instant i2_4668 = kk_std_time_instant_use_timescale(i0, tscale, _ctx); /*std/time/instant/instant*/;
    kk_std_time_timestamp__timestamp _x5884;
    kk_std_num_ddouble__ddouble _x5885;
    kk_std_num_ddouble__ddouble _x5886;
    kk_std_time_timestamp__timestamp _match_5258;
    struct kk_std_time_instant_Instant* _con5887 = kk_std_time_instant__as_Instant(i2_4668);
    kk_std_time_timestamp__timestamp _x1 = _con5887->since;
    kk_std_time_instant__timescale _pat21 = _con5887->ts;
    struct kk_std_time_instant_Timescale* _con5888 = kk_std_time_instant__as_Timescale(_pat21);
    _match_5258 = _x1; /*std/time/timestamp/timestamp*/
    kk_std_num_ddouble__ddouble _x0 = _match_5258.since;
    _x5886 = _x0; /*std/time/timestamp/timespan*/
    _x5885 = kk_std_num_ddouble__lp__plus__rp_(_x5886, t_4667, _ctx); /*std/num/ddouble/ddouble*/
    int32_t _x5889;
    kk_std_time_timestamp__timestamp _match_5257;
    struct kk_std_time_instant_Instant* _con5890 = kk_std_time_instant__as_Instant(i2_4668);
    kk_std_time_timestamp__timestamp _x10 = _con5890->since;
    kk_std_time_instant__timescale _pat210 = _con5890->ts;
    struct kk_std_time_instant_Timescale* _con5891 = kk_std_time_instant__as_Timescale(_pat210);
    _match_5257 = _x10; /*std/time/timestamp/timestamp*/
    kk_std_num_ddouble__ddouble _pat000 = _match_5257.since;
    int32_t _x00 = _match_5257.leap32;
    _x5889 = _x00; /*int32*/
    _x5884 = kk_std_time_timestamp__new_Timestamp(_x5885, _x5889, _ctx); /*std/time/timestamp/timestamp*/
    kk_std_time_instant__timescale _x5892;
    struct kk_std_time_instant_Instant* _con5893 = kk_std_time_instant__as_Instant(i2_4668);
    kk_std_time_timestamp__timestamp _pat02 = _con5893->since;
    kk_std_time_instant__timescale _x2 = _con5893->ts;
    struct kk_std_time_instant_Timescale* _con5894 = kk_std_time_instant__as_Timescale(_x2);
    if (kk_std_time_instant__instant_is_unique(i2_4668)) {
      kk_std_time_instant__instant_free(i2_4668);
    }
    else {
      kk_std_time_instant__timescale_dup(_x2);
      kk_std_time_instant__instant_decref(i2_4668, _ctx);
    }
    _x5892 = _x2; /*std/time/instant/timescale*/
    i10 = kk_std_time_instant__new_Instant(kk_reuse_null, _x5884, _x5892, _ctx); /*std/time/instant/instant*/
    kk_std_num_ddouble__ddouble days0;
    kk_integer_t i3_4674;
    kk_std_time_instant__instant _x5895 = kk_std_time_instant__instant_dup(i10); /*std/time/instant/instant*/
    i3_4674 = kk_std_time_instant_days(_x5895, _ctx); /*int*/
    days0 = kk_std_num_ddouble_ddouble_int_exp(i3_4674, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble frac;
    kk_std_num_ddouble__ddouble _x5896;
    kk_std_num_ddouble__ddouble _x5897;
    kk_std_core_types__tuple2_ _this_3811;
    kk_std_time_timestamp__timestamp _x5898;
    struct kk_std_time_instant_Instant* _con5899 = kk_std_time_instant__as_Instant(i10);
    kk_std_time_timestamp__timestamp _x4 = _con5899->since;
    kk_std_time_instant__timescale _pat23 = _con5899->ts;
    struct kk_std_time_instant_Timescale* _con5900 = kk_std_time_instant__as_Timescale(_pat23);
    _x5898 = _x4; /*std/time/timestamp/timestamp*/
    _this_3811 = kk_std_time_timestamp_days_seconds(_x5898, _ctx); /*(int, std/num/ddouble/ddouble)*/
    kk_box_t _box_x4910 = _this_3811.fst;
    kk_box_t _box_x4911 = _this_3811.snd;
    kk_std_num_ddouble__ddouble _x3 = kk_std_num_ddouble__ddouble_unbox(_box_x4911, NULL);
    kk_std_core_types__tuple2__drop(_this_3811, _ctx);
    _x5897 = _x3; /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble _x5903;
    kk_integer_t i_3812;
    kk_std_time_timestamp__timestamp _x5904;
    struct kk_std_time_instant_Instant* _con5905 = kk_std_time_instant__as_Instant(i10);
    kk_std_time_timestamp__timestamp _x40 = _con5905->since;
    kk_std_time_instant__timescale _pat230 = _con5905->ts;
    struct kk_std_time_instant_Timescale* _con5906 = kk_std_time_instant__as_Timescale(_pat230);
    kk_string_t _pat330 = _con5906->name;
    kk_string_t _pat420 = _con5906->unit;
    kk_function_t _pat520 = _con5906->from_tai;
    kk_function_t _pat620 = _con5906->to_tai;
    kk_std_core_types__maybe _pat720 = _con5906->mb_seconds_in_day;
    kk_std_core_types__maybe _pat810 = _con5906->mb_to_mjd2000;
    kk_std_core_types__maybe _pat910 = _con5906->mb_from_mjd2000;
    if (kk_std_time_instant__instant_is_unique(i10)) {
      if (kk_std_time_instant__timescale_is_unique(_pat230)) {
        kk_string_drop(_pat330, _ctx);
        kk_string_drop(_pat420, _ctx);
        kk_function_drop(_pat520, _ctx);
        kk_function_drop(_pat620, _ctx);
        kk_std_core_types__maybe_drop(_pat720, _ctx);
        kk_std_core_types__maybe_drop(_pat810, _ctx);
        kk_std_core_types__maybe_drop(_pat910, _ctx);
        kk_std_time_instant__timescale_free(_pat230);
      }
      else {
        kk_std_time_instant__timescale_decref(_pat230, _ctx);
      }
      kk_std_time_instant__instant_free(i10);
    }
    else {
      kk_std_time_instant__instant_decref(i10, _ctx);
    }
    _x5904 = _x40; /*std/time/timestamp/timestamp*/
    i_3812 = kk_std_time_timestamp_leap(_x5904, _ctx); /*int*/
    _x5903 = kk_std_num_ddouble_ddouble_int_exp(i_3812, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
    _x5896 = kk_std_num_ddouble__lp__plus__rp_(_x5897, _x5903, _ctx); /*std/num/ddouble/ddouble*/
    frac = kk_std_num_ddouble__lp__fs__rp_(_x5896, kk_std_time_timestamp_solar_secs_per_day, _ctx); /*std/num/ddouble/ddouble*/
    mjd0 = kk_std_num_ddouble__lp__plus__rp_(days0, frac, _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    kk_box_t _fun_unbox_x4917 = _match_5256._cons.Just.value;
    kk_std_time_instant__timescale_dropn(tscale, ((int32_t)10), _ctx);
    kk_std_num_ddouble__ddouble _b_4925_4922;
    if (kk_std_core_types__is_Optional(tzdelta)) {
      kk_box_t _box_x4923 = tzdelta._cons.Optional.value;
      kk_std_num_ddouble__ddouble _tzdelta_35570 = kk_std_num_ddouble__ddouble_unbox(_box_x4923, NULL);
      _b_4925_4922 = _tzdelta_35570; /*std/time/timestamp/timespan*/
      goto _match5907;
    }
    _b_4925_4922 = kk_std_num_ddouble__new_Ddouble(0x0p+0, 0x0p+0, _ctx); /*std/time/timestamp/timespan*/
    _match5907: ;
    kk_box_t _x5909;
    kk_function_t _x5914 = kk_function_unbox(_fun_unbox_x4917); /*(t : 4918, tzdelta : 4919) -> 4920*/
    kk_box_t _x5910;
    kk_std_time_timestamp__timestamp _x5911;
    struct kk_std_time_instant_Instant* _con5912 = kk_std_time_instant__as_Instant(i0);
    kk_std_time_timestamp__timestamp _x5 = _con5912->since;
    kk_std_time_instant__timescale _pat25 = _con5912->ts;
    struct kk_std_time_instant_Timescale* _con5913 = kk_std_time_instant__as_Timescale(_pat25);
    kk_string_t _pat34 = _con5913->name;
    kk_string_t _pat43 = _con5913->unit;
    kk_function_t _pat53 = _con5913->from_tai;
    kk_function_t _pat63 = _con5913->to_tai;
    kk_std_core_types__maybe _pat73 = _con5913->mb_seconds_in_day;
    kk_std_core_types__maybe _pat82 = _con5913->mb_to_mjd2000;
    kk_std_core_types__maybe _pat92 = _con5913->mb_from_mjd2000;
    if (kk_std_time_instant__instant_is_unique(i0)) {
      if (kk_std_time_instant__timescale_is_unique(_pat25)) {
        kk_string_drop(_pat34, _ctx);
        kk_string_drop(_pat43, _ctx);
        kk_function_drop(_pat53, _ctx);
        kk_function_drop(_pat63, _ctx);
        kk_std_core_types__maybe_drop(_pat73, _ctx);
        kk_std_core_types__maybe_drop(_pat82, _ctx);
        kk_std_core_types__maybe_drop(_pat92, _ctx);
        kk_std_time_instant__timescale_free(_pat25);
      }
      else {
        kk_std_time_instant__timescale_decref(_pat25, _ctx);
      }
      kk_std_time_instant__instant_free(i0);
    }
    else {
      kk_std_time_instant__instant_decref(i0, _ctx);
    }
    _x5911 = _x5; /*std/time/timestamp/timestamp*/
    _x5910 = kk_std_time_timestamp__timestamp_box(_x5911, _ctx); /*4918*/
    _x5909 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _x5914, (_x5914, _x5910, kk_std_num_ddouble__ddouble_box(_b_4925_4922, _ctx), _ctx)); /*4920*/
    mjd0 = kk_std_num_ddouble__ddouble_unbox(_x5909, _ctx); /*std/num/ddouble/ddouble*/
  }
  return kk_std_num_ddouble__lp__plus__rp_(mjd0, kk_std_time_instant_mjd_epoch_delta, _ctx);
}
 
/* Return the julian day in a given time scale `ts` for an instant `i`.
Properly takes leap seconds into account when calculating the fraction of the day
in a UTC calendar. For example:
````
> time(2014,12,31,23,59,59).jd
2457023.499988425925926
> time(2015,12,31,23,59,59).jd
2457388.499988425925926
> time(2016,12,31,23,59,59).jd
2457754.499976852119767
> time(2016,12,31,23,59,60).jd
2457754.499988426059884
````
.
*/

kk_std_num_ddouble__ddouble kk_std_time_instant_jd(kk_std_time_instant__instant i, kk_std_time_instant__timescale ts0, kk_context_t* _ctx) { /* (i : instant, ts : timescale) -> std/num/ddouble/ddouble */ 
  kk_std_num_ddouble__ddouble _x5915;
  kk_std_time_instant__instant i00;
  kk_std_time_instant__timescale _x5916 = kk_std_time_instant__timescale_dup(ts0); /*std/time/instant/timescale*/
  i00 = kk_std_time_instant_use_timescale(i, _x5916, _ctx); /*std/time/instant/instant*/
  kk_std_num_ddouble__ddouble mjd0;
  kk_std_core_types__maybe _match_5251;
  struct kk_std_time_instant_Timescale* _con5917 = kk_std_time_instant__as_Timescale(ts0);
  kk_std_core_types__maybe _x = _con5917->mb_to_mjd2000;
  kk_std_core_types__maybe_dup(_x);
  _match_5251 = _x; /*maybe<(t : std/time/timestamp/timestamp, tzdelta : std/time/timestamp/timespan) -> std/num/ddouble/ddouble>*/
  if (kk_std_core_types__is_Nothing(_match_5251)) {
    kk_std_time_instant__instant i10;
    kk_std_num_ddouble__ddouble t_4667;
    kk_std_core_types__optional _x5918 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/
    if (kk_std_core_types__is_Optional(_x5918)) {
      kk_box_t _box_x4926 = _x5918._cons.Optional.value;
      kk_std_num_ddouble__ddouble _tzdelta_3557 = kk_std_num_ddouble__ddouble_unbox(_box_x4926, NULL);
      t_4667 = _tzdelta_3557; /*std/time/timestamp/timespan*/
      goto _match5919;
    }
    t_4667 = kk_std_num_ddouble__new_Ddouble(0x0p+0, 0x0p+0, _ctx); /*std/time/timestamp/timespan*/
    _match5919: ;
    kk_std_time_instant__instant i2_4668 = kk_std_time_instant_use_timescale(i00, ts0, _ctx); /*std/time/instant/instant*/;
    kk_std_time_timestamp__timestamp _x5921;
    kk_std_num_ddouble__ddouble _x5922;
    kk_std_num_ddouble__ddouble _x5923;
    kk_std_time_timestamp__timestamp _match_5254;
    struct kk_std_time_instant_Instant* _con5924 = kk_std_time_instant__as_Instant(i2_4668);
    kk_std_time_timestamp__timestamp _x1 = _con5924->since;
    kk_std_time_instant__timescale _pat21 = _con5924->ts;
    struct kk_std_time_instant_Timescale* _con5925 = kk_std_time_instant__as_Timescale(_pat21);
    _match_5254 = _x1; /*std/time/timestamp/timestamp*/
    kk_std_num_ddouble__ddouble _x0 = _match_5254.since;
    _x5923 = _x0; /*std/time/timestamp/timespan*/
    _x5922 = kk_std_num_ddouble__lp__plus__rp_(_x5923, t_4667, _ctx); /*std/num/ddouble/ddouble*/
    int32_t _x5926;
    kk_std_time_timestamp__timestamp _match_5253;
    struct kk_std_time_instant_Instant* _con5927 = kk_std_time_instant__as_Instant(i2_4668);
    kk_std_time_timestamp__timestamp _x10 = _con5927->since;
    kk_std_time_instant__timescale _pat210 = _con5927->ts;
    struct kk_std_time_instant_Timescale* _con5928 = kk_std_time_instant__as_Timescale(_pat210);
    _match_5253 = _x10; /*std/time/timestamp/timestamp*/
    kk_std_num_ddouble__ddouble _pat000 = _match_5253.since;
    int32_t _x00 = _match_5253.leap32;
    _x5926 = _x00; /*int32*/
    _x5921 = kk_std_time_timestamp__new_Timestamp(_x5922, _x5926, _ctx); /*std/time/timestamp/timestamp*/
    kk_std_time_instant__timescale _x5929;
    struct kk_std_time_instant_Instant* _con5930 = kk_std_time_instant__as_Instant(i2_4668);
    kk_std_time_timestamp__timestamp _pat02 = _con5930->since;
    kk_std_time_instant__timescale _x2 = _con5930->ts;
    struct kk_std_time_instant_Timescale* _con5931 = kk_std_time_instant__as_Timescale(_x2);
    if (kk_std_time_instant__instant_is_unique(i2_4668)) {
      kk_std_time_instant__instant_free(i2_4668);
    }
    else {
      kk_std_time_instant__timescale_dup(_x2);
      kk_std_time_instant__instant_decref(i2_4668, _ctx);
    }
    _x5929 = _x2; /*std/time/instant/timescale*/
    i10 = kk_std_time_instant__new_Instant(kk_reuse_null, _x5921, _x5929, _ctx); /*std/time/instant/instant*/
    kk_std_num_ddouble__ddouble days0;
    kk_integer_t i3_4674;
    kk_std_time_instant__instant _x5932 = kk_std_time_instant__instant_dup(i10); /*std/time/instant/instant*/
    i3_4674 = kk_std_time_instant_days(_x5932, _ctx); /*int*/
    days0 = kk_std_num_ddouble_ddouble_int_exp(i3_4674, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble frac;
    kk_std_num_ddouble__ddouble _x5933;
    kk_std_num_ddouble__ddouble _x5934;
    kk_std_core_types__tuple2_ _this_3811;
    kk_std_time_timestamp__timestamp _x5935;
    struct kk_std_time_instant_Instant* _con5936 = kk_std_time_instant__as_Instant(i10);
    kk_std_time_timestamp__timestamp _x4 = _con5936->since;
    kk_std_time_instant__timescale _pat23 = _con5936->ts;
    struct kk_std_time_instant_Timescale* _con5937 = kk_std_time_instant__as_Timescale(_pat23);
    _x5935 = _x4; /*std/time/timestamp/timestamp*/
    _this_3811 = kk_std_time_timestamp_days_seconds(_x5935, _ctx); /*(int, std/num/ddouble/ddouble)*/
    kk_box_t _box_x4927 = _this_3811.fst;
    kk_box_t _box_x4928 = _this_3811.snd;
    kk_std_num_ddouble__ddouble _x3 = kk_std_num_ddouble__ddouble_unbox(_box_x4928, NULL);
    kk_std_core_types__tuple2__drop(_this_3811, _ctx);
    _x5934 = _x3; /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble _x5940;
    kk_integer_t i_3812;
    kk_std_time_timestamp__timestamp _x5941;
    struct kk_std_time_instant_Instant* _con5942 = kk_std_time_instant__as_Instant(i10);
    kk_std_time_timestamp__timestamp _x40 = _con5942->since;
    kk_std_time_instant__timescale _pat230 = _con5942->ts;
    struct kk_std_time_instant_Timescale* _con5943 = kk_std_time_instant__as_Timescale(_pat230);
    kk_string_t _pat330 = _con5943->name;
    kk_string_t _pat420 = _con5943->unit;
    kk_function_t _pat520 = _con5943->from_tai;
    kk_function_t _pat620 = _con5943->to_tai;
    kk_std_core_types__maybe _pat720 = _con5943->mb_seconds_in_day;
    kk_std_core_types__maybe _pat810 = _con5943->mb_to_mjd2000;
    kk_std_core_types__maybe _pat910 = _con5943->mb_from_mjd2000;
    if (kk_std_time_instant__instant_is_unique(i10)) {
      if (kk_std_time_instant__timescale_is_unique(_pat230)) {
        kk_string_drop(_pat330, _ctx);
        kk_string_drop(_pat420, _ctx);
        kk_function_drop(_pat520, _ctx);
        kk_function_drop(_pat620, _ctx);
        kk_std_core_types__maybe_drop(_pat720, _ctx);
        kk_std_core_types__maybe_drop(_pat810, _ctx);
        kk_std_core_types__maybe_drop(_pat910, _ctx);
        kk_std_time_instant__timescale_free(_pat230);
      }
      else {
        kk_std_time_instant__timescale_decref(_pat230, _ctx);
      }
      kk_std_time_instant__instant_free(i10);
    }
    else {
      kk_std_time_instant__instant_decref(i10, _ctx);
    }
    _x5941 = _x40; /*std/time/timestamp/timestamp*/
    i_3812 = kk_std_time_timestamp_leap(_x5941, _ctx); /*int*/
    _x5940 = kk_std_num_ddouble_ddouble_int_exp(i_3812, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
    _x5933 = kk_std_num_ddouble__lp__plus__rp_(_x5934, _x5940, _ctx); /*std/num/ddouble/ddouble*/
    frac = kk_std_num_ddouble__lp__fs__rp_(_x5933, kk_std_time_timestamp_solar_secs_per_day, _ctx); /*std/num/ddouble/ddouble*/
    mjd0 = kk_std_num_ddouble__lp__plus__rp_(days0, frac, _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    kk_box_t _fun_unbox_x4934 = _match_5251._cons.Just.value;
    kk_std_time_instant__timescale_dropn(ts0, ((int32_t)10), _ctx);
    kk_std_num_ddouble__ddouble _b_4942_4939;
    kk_std_core_types__optional _x5944 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/
    if (kk_std_core_types__is_Optional(_x5944)) {
      kk_box_t _box_x4940 = _x5944._cons.Optional.value;
      kk_std_num_ddouble__ddouble _tzdelta_35570 = kk_std_num_ddouble__ddouble_unbox(_box_x4940, NULL);
      _b_4942_4939 = _tzdelta_35570; /*std/time/timestamp/timespan*/
      goto _match5945;
    }
    _b_4942_4939 = kk_std_num_ddouble__new_Ddouble(0x0p+0, 0x0p+0, _ctx); /*std/time/timestamp/timespan*/
    _match5945: ;
    kk_box_t _x5947;
    kk_function_t _x5952 = kk_function_unbox(_fun_unbox_x4934); /*(t : 4935, tzdelta : 4936) -> 4937*/
    kk_box_t _x5948;
    kk_std_time_timestamp__timestamp _x5949;
    struct kk_std_time_instant_Instant* _con5950 = kk_std_time_instant__as_Instant(i00);
    kk_std_time_timestamp__timestamp _x5 = _con5950->since;
    kk_std_time_instant__timescale _pat25 = _con5950->ts;
    struct kk_std_time_instant_Timescale* _con5951 = kk_std_time_instant__as_Timescale(_pat25);
    kk_string_t _pat34 = _con5951->name;
    kk_string_t _pat43 = _con5951->unit;
    kk_function_t _pat53 = _con5951->from_tai;
    kk_function_t _pat63 = _con5951->to_tai;
    kk_std_core_types__maybe _pat73 = _con5951->mb_seconds_in_day;
    kk_std_core_types__maybe _pat82 = _con5951->mb_to_mjd2000;
    kk_std_core_types__maybe _pat92 = _con5951->mb_from_mjd2000;
    if (kk_std_time_instant__instant_is_unique(i00)) {
      if (kk_std_time_instant__timescale_is_unique(_pat25)) {
        kk_string_drop(_pat34, _ctx);
        kk_string_drop(_pat43, _ctx);
        kk_function_drop(_pat53, _ctx);
        kk_function_drop(_pat63, _ctx);
        kk_std_core_types__maybe_drop(_pat73, _ctx);
        kk_std_core_types__maybe_drop(_pat82, _ctx);
        kk_std_core_types__maybe_drop(_pat92, _ctx);
        kk_std_time_instant__timescale_free(_pat25);
      }
      else {
        kk_std_time_instant__timescale_decref(_pat25, _ctx);
      }
      kk_std_time_instant__instant_free(i00);
    }
    else {
      kk_std_time_instant__instant_decref(i00, _ctx);
    }
    _x5949 = _x5; /*std/time/timestamp/timestamp*/
    _x5948 = kk_std_time_timestamp__timestamp_box(_x5949, _ctx); /*4935*/
    _x5947 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _x5952, (_x5952, _x5948, kk_std_num_ddouble__ddouble_box(_b_4942_4939, _ctx), _ctx)); /*4937*/
    mjd0 = kk_std_num_ddouble__ddouble_unbox(_x5947, _ctx); /*std/num/ddouble/ddouble*/
  }
  _x5915 = kk_std_num_ddouble__lp__plus__rp_(mjd0, kk_std_time_instant_mjd_epoch_delta, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__lp__plus__rp_(_x5915, kk_std_time_instant_jd_epoch_delta, _ctx);
}
 
// The maximum of two instants.

kk_std_time_instant__instant kk_std_time_instant_max(kk_std_time_instant__instant i, kk_std_time_instant__instant j, kk_context_t* _ctx) { /* (i : instant, j : instant) -> instant */ 
  bool _match_5250;
  kk_std_time_instant__instant _x5953 = kk_std_time_instant__instant_dup(i); /*std/time/instant/instant*/
  kk_std_time_instant__instant _x5954 = kk_std_time_instant__instant_dup(j); /*std/time/instant/instant*/
  _match_5250 = kk_std_time_instant__lp__gt__eq__rp_(_x5953, _x5954, _ctx); /*bool*/
  if (_match_5250) {
    kk_std_time_instant__instant_dropn(j, ((int32_t)1), _ctx);
    return i;
  }
  kk_std_time_instant__instant_dropn(i, ((int32_t)1), _ctx);
  return j;
}
 
// The minimum of two instants.

kk_std_time_instant__instant kk_std_time_instant_min(kk_std_time_instant__instant i, kk_std_time_instant__instant j, kk_context_t* _ctx) { /* (i : instant, j : instant) -> instant */ 
  bool _match_5249;
  kk_std_time_instant__instant _x5955 = kk_std_time_instant__instant_dup(i); /*std/time/instant/instant*/
  kk_std_time_instant__instant _x5956 = kk_std_time_instant__instant_dup(j); /*std/time/instant/instant*/
  _match_5249 = kk_std_time_instant__lp__lt__eq__rp_(_x5955, _x5956, _ctx); /*bool*/
  if (_match_5249) {
    kk_std_time_instant__instant_dropn(j, ((int32_t)1), _ctx);
    return i;
  }
  kk_std_time_instant__instant_dropn(i, ((int32_t)1), _ctx);
  return j;
}
 
// Round an instant to a certain precision (`prec` is number of digits of the fraction of the second).
// Takes special care for instants that use a UTC timescale to round into leap seconds if appropriate.

kk_std_time_instant__instant kk_std_time_instant_round_to_prec(kk_std_time_instant__instant i, kk_integer_t prec, kk_context_t* _ctx) { /* (i : instant, prec : int) -> instant */ 
  bool _match_5234;
  kk_integer_t _x5957 = kk_integer_dup(prec); /*int*/
  _match_5234 = kk_std_core_is_neg_2(_x5957, _ctx); /*bool*/
  if (_match_5234) {
    kk_integer_drop(prec, _ctx);
    return i;
  }
  bool _match_5235;
  kk_std_core_types__maybe _match_5247;
  kk_std_time_instant__timescale _match_5248;
  struct kk_std_time_instant_Instant* _con5958 = kk_std_time_instant__as_Instant(i);
  kk_std_time_timestamp__timestamp _pat02 = _con5958->since;
  kk_std_time_instant__timescale _x0 = _con5958->ts;
  struct kk_std_time_instant_Timescale* _con5959 = kk_std_time_instant__as_Timescale(_x0);
  kk_std_time_instant__timescale_dup(_x0);
  _match_5248 = _x0; /*std/time/instant/timescale*/
  struct kk_std_time_instant_Timescale* _con5960 = kk_std_time_instant__as_Timescale(_match_5248);
  kk_string_t _pat01 = _con5960->name;
  kk_string_t _pat10 = _con5960->unit;
  kk_function_t _pat20 = _con5960->from_tai;
  kk_function_t _pat3 = _con5960->to_tai;
  kk_std_core_types__maybe _x = _con5960->mb_seconds_in_day;
  kk_std_core_types__maybe _pat4 = _con5960->mb_to_mjd2000;
  kk_std_core_types__maybe _pat5 = _con5960->mb_from_mjd2000;
  if (kk_std_time_instant__timescale_is_unique(_match_5248)) {
    kk_std_core_types__maybe_drop(_pat5, _ctx);
    kk_std_core_types__maybe_drop(_pat4, _ctx);
    kk_function_drop(_pat3, _ctx);
    kk_function_drop(_pat20, _ctx);
    kk_string_drop(_pat10, _ctx);
    kk_string_drop(_pat01, _ctx);
    kk_std_time_instant__timescale_free(_match_5248);
  }
  else {
    kk_std_core_types__maybe_dup(_x);
    kk_std_time_instant__timescale_decref(_match_5248, _ctx);
  }
  _match_5247 = _x; /*maybe<(t : std/time/timestamp/timestamp) -> std/time/timestamp/timespan>*/
  if (kk_std_core_types__is_Nothing(_match_5247)) {
    _match_5235 = false; /*bool*/
  }
  else {
    kk_std_core_types__maybe_drop(_match_5247, _ctx);
    _match_5235 = true; /*bool*/
  }
  if (_match_5235) {
    kk_std_time_instant__instant i0_4682;
    kk_std_time_timestamp__timestamp _x5961;
    kk_std_time_timestamp__timestamp t_4684;
    kk_std_time_instant__instant instant1_4686;
    kk_std_time_instant__instant _x5962 = kk_std_time_instant__instant_dup(i); /*std/time/instant/instant*/
    kk_std_time_instant__timescale _x5963 = kk_std_time_instant__timescale_dup(kk_std_time_instant_ts_tai); /*std/time/instant/timescale*/
    instant1_4686 = kk_std_time_instant_use_timescale(_x5962, _x5963, _ctx); /*std/time/instant/instant*/
    struct kk_std_time_instant_Instant* _con5964 = kk_std_time_instant__as_Instant(instant1_4686);
    kk_std_time_timestamp__timestamp _x7 = _con5964->since;
    kk_std_time_instant__timescale _pat28 = _con5964->ts;
    struct kk_std_time_instant_Timescale* _con5965 = kk_std_time_instant__as_Timescale(_pat28);
    kk_string_t _pat37 = _con5965->name;
    kk_string_t _pat45 = _con5965->unit;
    kk_function_t _pat54 = _con5965->from_tai;
    kk_function_t _pat62 = _con5965->to_tai;
    kk_std_core_types__maybe _pat71 = _con5965->mb_seconds_in_day;
    kk_std_core_types__maybe _pat81 = _con5965->mb_to_mjd2000;
    kk_std_core_types__maybe _pat91 = _con5965->mb_from_mjd2000;
    if (kk_std_time_instant__instant_is_unique(instant1_4686)) {
      if (kk_std_time_instant__timescale_is_unique(_pat28)) {
        kk_string_drop(_pat37, _ctx);
        kk_string_drop(_pat45, _ctx);
        kk_function_drop(_pat54, _ctx);
        kk_function_drop(_pat62, _ctx);
        kk_std_core_types__maybe_drop(_pat71, _ctx);
        kk_std_core_types__maybe_drop(_pat81, _ctx);
        kk_std_core_types__maybe_drop(_pat91, _ctx);
        kk_std_time_instant__timescale_free(_pat28);
      }
      else {
        kk_std_time_instant__timescale_decref(_pat28, _ctx);
      }
      kk_std_time_instant__instant_free(instant1_4686);
    }
    else {
      kk_std_time_instant__instant_decref(instant1_4686, _ctx);
    }
    t_4684 = _x7; /*std/time/timestamp/timestamp*/
    kk_std_num_ddouble__ddouble _x5966;
    bool _match_5245;
    kk_integer_t _x5967 = kk_integer_dup(prec); /*int*/
    _match_5245 = kk_integer_lte(_x5967,(kk_integer_from_small(0)),kk_context()); /*bool*/
    if (_match_5245) {
      kk_integer_drop(prec, _ctx);
      kk_std_num_ddouble__ddouble _x5968;
      kk_std_num_ddouble__ddouble _x4 = t_4684.since;
      _x5968 = _x4; /*std/time/timestamp/timespan*/
      _x5966 = kk_std_num_ddouble_round(_x5968, _ctx); /*std/num/ddouble/ddouble*/
    }
    else {
      bool _match_5246;
      kk_integer_t _x5969 = kk_integer_dup(prec); /*int*/
      _match_5246 = kk_integer_gt(_x5969,(kk_integer_from_small(31)),kk_context()); /*bool*/
      if (_match_5246) {
        kk_integer_drop(prec, _ctx);
        kk_std_num_ddouble__ddouble _x5 = t_4684.since;
        _x5966 = _x5; /*std/num/ddouble/ddouble*/
      }
      else {
        kk_std_num_ddouble__ddouble p = kk_std_num_ddouble_powi10(prec, _ctx); /*std/num/ddouble/ddouble*/;
        kk_std_num_ddouble__ddouble _x5970;
        kk_std_num_ddouble__ddouble _x5971;
        kk_std_num_ddouble__ddouble _x5972;
        kk_std_num_ddouble__ddouble _x6 = t_4684.since;
        _x5972 = _x6; /*std/time/timestamp/timespan*/
        _x5971 = kk_std_num_ddouble__lp__star__rp_(_x5972, p, _ctx); /*std/num/ddouble/ddouble*/
        _x5970 = kk_std_num_ddouble_round(_x5971, _ctx); /*std/num/ddouble/ddouble*/
        _x5966 = kk_std_num_ddouble__lp__fs__rp_(_x5970, p, _ctx); /*std/num/ddouble/ddouble*/
      }
    }
    int32_t _x5973;
    kk_std_num_ddouble__ddouble _pat010 = t_4684.since;
    int32_t _x00 = t_4684.leap32;
    _x5973 = _x00; /*int32*/
    _x5961 = kk_std_time_timestamp__new_Timestamp(_x5966, _x5973, _ctx); /*std/time/timestamp/timestamp*/
    kk_std_time_instant__timescale _x5974 = kk_std_time_instant__timescale_dup(kk_std_time_instant_ts_tai); /*std/time/instant/timescale*/
    i0_4682 = kk_std_time_instant__new_Instant(kk_reuse_null, _x5961, _x5974, _ctx); /*std/time/instant/instant*/
    bool _match_5242;
    kk_string_t _x5975;
    kk_std_time_instant__timescale _match_5244;
    struct kk_std_time_instant_Instant* _con5976 = kk_std_time_instant__as_Instant(i0_4682);
    kk_std_time_timestamp__timestamp _pat04 = _con5976->since;
    kk_std_time_instant__timescale _x2 = _con5976->ts;
    struct kk_std_time_instant_Timescale* _con5977 = kk_std_time_instant__as_Timescale(_x2);
    kk_std_time_instant__timescale_dup(_x2);
    _match_5244 = _x2; /*std/time/instant/timescale*/
    struct kk_std_time_instant_Timescale* _con5978 = kk_std_time_instant__as_Timescale(_match_5244);
    kk_string_t _x1 = _con5978->name;
    kk_string_t _pat03 = _con5978->unit;
    kk_function_t _pat14 = _con5978->from_tai;
    kk_function_t _pat22 = _con5978->to_tai;
    kk_std_core_types__maybe _pat31 = _con5978->mb_seconds_in_day;
    kk_std_core_types__maybe _pat41 = _con5978->mb_to_mjd2000;
    kk_std_core_types__maybe _pat51 = _con5978->mb_from_mjd2000;
    if (kk_std_time_instant__timescale_is_unique(_match_5244)) {
      kk_std_core_types__maybe_drop(_pat51, _ctx);
      kk_std_core_types__maybe_drop(_pat41, _ctx);
      kk_std_core_types__maybe_drop(_pat31, _ctx);
      kk_function_drop(_pat22, _ctx);
      kk_function_drop(_pat14, _ctx);
      kk_string_drop(_pat03, _ctx);
      kk_std_time_instant__timescale_free(_match_5244);
    }
    else {
      kk_string_dup(_x1);
      kk_std_time_instant__timescale_decref(_match_5244, _ctx);
    }
    _x5975 = _x1; /*string*/
    kk_string_t _x5979;
    kk_std_time_instant__timescale _match_5243;
    struct kk_std_time_instant_Instant* _con5980 = kk_std_time_instant__as_Instant(i);
    kk_std_time_timestamp__timestamp _pat09 = _con5980->since;
    kk_std_time_instant__timescale _x8 = _con5980->ts;
    struct kk_std_time_instant_Timescale* _con5981 = kk_std_time_instant__as_Timescale(_x8);
    kk_std_time_instant__timescale_dup(_x8);
    _match_5243 = _x8; /*std/time/instant/timescale*/
    struct kk_std_time_instant_Timescale* _con5982 = kk_std_time_instant__as_Timescale(_match_5243);
    kk_string_t _x3 = _con5982->name;
    kk_string_t _pat05 = _con5982->unit;
    kk_function_t _pat18 = _con5982->from_tai;
    kk_function_t _pat24 = _con5982->to_tai;
    kk_std_core_types__maybe _pat33 = _con5982->mb_seconds_in_day;
    kk_std_core_types__maybe _pat43 = _con5982->mb_to_mjd2000;
    kk_std_core_types__maybe _pat53 = _con5982->mb_from_mjd2000;
    if (kk_std_time_instant__timescale_is_unique(_match_5243)) {
      kk_std_core_types__maybe_drop(_pat53, _ctx);
      kk_std_core_types__maybe_drop(_pat43, _ctx);
      kk_std_core_types__maybe_drop(_pat33, _ctx);
      kk_function_drop(_pat24, _ctx);
      kk_function_drop(_pat18, _ctx);
      kk_string_drop(_pat05, _ctx);
      kk_std_time_instant__timescale_free(_match_5243);
    }
    else {
      kk_string_dup(_x3);
      kk_std_time_instant__timescale_decref(_match_5243, _ctx);
    }
    _x5979 = _x3; /*string*/
    _match_5242 = kk_string_is_eq(_x5975,_x5979,kk_context()); /*bool*/
    if (_match_5242) {
      kk_std_time_instant__instant_dropn(i, ((int32_t)1), _ctx);
      return i0_4682;
    }
    kk_std_time_timestamp__timestamp _x5983;
    kk_std_time_instant__timescale _x5984;
    struct kk_std_time_instant_Instant* _con5985 = kk_std_time_instant__as_Instant(i);
    kk_std_time_timestamp__timestamp _pat090 = _con5985->since;
    kk_std_time_instant__timescale _x80 = _con5985->ts;
    struct kk_std_time_instant_Timescale* _con5986 = kk_std_time_instant__as_Timescale(_x80);
    kk_std_time_instant__timescale_dup(_x80);
    _x5984 = _x80; /*std/time/instant/timescale*/
    _x5983 = kk_std_time_instant_timestamp_in(i0_4682, _x5984, _ctx); /*std/time/timestamp/timestamp*/
    kk_std_time_instant__timescale _x5987;
    struct kk_std_time_instant_Instant* _con5988 = kk_std_time_instant__as_Instant(i);
    kk_std_time_timestamp__timestamp _pat091 = _con5988->since;
    kk_std_time_instant__timescale _x81 = _con5988->ts;
    struct kk_std_time_instant_Timescale* _con5989 = kk_std_time_instant__as_Timescale(_x81);
    if (kk_std_time_instant__instant_is_unique(i)) {
      kk_std_time_instant__instant_free(i);
    }
    else {
      kk_std_time_instant__timescale_dup(_x81);
      kk_std_time_instant__instant_decref(i, _ctx);
    }
    _x5987 = _x81; /*std/time/instant/timescale*/
    return kk_std_time_instant__new_Instant(kk_reuse_null, _x5983, _x5987, _ctx);
  }
  kk_std_time_timestamp__timestamp _x5990;
  kk_std_num_ddouble__ddouble _x5991;
  bool _match_5237;
  kk_integer_t _x5992 = kk_integer_dup(prec); /*int*/
  _match_5237 = kk_integer_lte(_x5992,(kk_integer_from_small(0)),kk_context()); /*bool*/
  if (_match_5237) {
    kk_integer_drop(prec, _ctx);
    kk_std_num_ddouble__ddouble _x5993;
    kk_std_time_timestamp__timestamp _match_5241;
    struct kk_std_time_instant_Instant* _con5994 = kk_std_time_instant__as_Instant(i);
    kk_std_time_timestamp__timestamp _x12 = _con5994->since;
    kk_std_time_instant__timescale _pat215 = _con5994->ts;
    struct kk_std_time_instant_Timescale* _con5995 = kk_std_time_instant__as_Timescale(_pat215);
    _match_5241 = _x12; /*std/time/timestamp/timestamp*/
    kk_std_num_ddouble__ddouble _x9 = _match_5241.since;
    _x5993 = _x9; /*std/time/timestamp/timespan*/
    _x5991 = kk_std_num_ddouble_round(_x5993, _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    bool _match_5238;
    kk_integer_t _x5996 = kk_integer_dup(prec); /*int*/
    _match_5238 = kk_integer_gt(_x5996,(kk_integer_from_small(31)),kk_context()); /*bool*/
    if (_match_5238) {
      kk_integer_drop(prec, _ctx);
      kk_std_time_timestamp__timestamp _match_5240;
      struct kk_std_time_instant_Instant* _con5997 = kk_std_time_instant__as_Instant(i);
      kk_std_time_timestamp__timestamp _x120 = _con5997->since;
      kk_std_time_instant__timescale _pat2150 = _con5997->ts;
      struct kk_std_time_instant_Timescale* _con5998 = kk_std_time_instant__as_Timescale(_pat2150);
      _match_5240 = _x120; /*std/time/timestamp/timestamp*/
      kk_std_num_ddouble__ddouble _x10 = _match_5240.since;
      _x5991 = _x10; /*std/num/ddouble/ddouble*/
    }
    else {
      kk_std_num_ddouble__ddouble p0 = kk_std_num_ddouble_powi10(prec, _ctx); /*std/num/ddouble/ddouble*/;
      kk_std_num_ddouble__ddouble _x5999;
      kk_std_num_ddouble__ddouble _x6000;
      kk_std_num_ddouble__ddouble _x6001;
      kk_std_time_timestamp__timestamp _match_5239;
      struct kk_std_time_instant_Instant* _con6002 = kk_std_time_instant__as_Instant(i);
      kk_std_time_timestamp__timestamp _x121 = _con6002->since;
      kk_std_time_instant__timescale _pat2151 = _con6002->ts;
      struct kk_std_time_instant_Timescale* _con6003 = kk_std_time_instant__as_Timescale(_pat2151);
      _match_5239 = _x121; /*std/time/timestamp/timestamp*/
      kk_std_num_ddouble__ddouble _x11 = _match_5239.since;
      _x6001 = _x11; /*std/time/timestamp/timespan*/
      _x6000 = kk_std_num_ddouble__lp__star__rp_(_x6001, p0, _ctx); /*std/num/ddouble/ddouble*/
      _x5999 = kk_std_num_ddouble_round(_x6000, _ctx); /*std/num/ddouble/ddouble*/
      _x5991 = kk_std_num_ddouble__lp__fs__rp_(_x5999, p0, _ctx); /*std/num/ddouble/ddouble*/
    }
  }
  int32_t _x6004;
  kk_std_time_timestamp__timestamp _match_5236;
  struct kk_std_time_instant_Instant* _con6005 = kk_std_time_instant__as_Instant(i);
  kk_std_time_timestamp__timestamp _x122 = _con6005->since;
  kk_std_time_instant__timescale _pat2152 = _con6005->ts;
  struct kk_std_time_instant_Timescale* _con6006 = kk_std_time_instant__as_Timescale(_pat2152);
  _match_5236 = _x122; /*std/time/timestamp/timestamp*/
  kk_std_num_ddouble__ddouble _pat012 = _match_5236.since;
  int32_t _x01 = _match_5236.leap32;
  _x6004 = _x01; /*int32*/
  _x5990 = kk_std_time_timestamp__new_Timestamp(_x5991, _x6004, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_time_instant__timescale _x6007;
  struct kk_std_time_instant_Instant* _con6008 = kk_std_time_instant__as_Instant(i);
  kk_std_time_timestamp__timestamp _pat014 = _con6008->since;
  kk_std_time_instant__timescale _x13 = _con6008->ts;
  struct kk_std_time_instant_Timescale* _con6009 = kk_std_time_instant__as_Timescale(_x13);
  if (kk_std_time_instant__instant_is_unique(i)) {
    kk_std_time_instant__instant_free(i);
  }
  else {
    kk_std_time_instant__timescale_dup(_x13);
    kk_std_time_instant__instant_decref(i, _ctx);
  }
  _x6007 = _x13; /*std/time/instant/timescale*/
  return kk_std_time_instant__new_Instant(kk_reuse_null, _x5990, _x6007, _ctx);
}
 
// Internal: show an instant as a raw timestamp in a given precision, postfixed with the time scale name.

kk_string_t kk_std_time_instant_show_raw(kk_std_time_instant__instant i, kk_std_core_types__optional max_prec, kk_std_core_types__optional secs_width, kk_std_core_types__optional unit0, kk_context_t* _ctx) { /* (i : instant, max-prec : optional<int>, secs-width : optional<int>, unit : optional<string>) -> string */ 
  kk_string_t _x6010;
  kk_std_time_timestamp__timestamp _x6011;
  struct kk_std_time_instant_Instant* _con6012 = kk_std_time_instant__as_Instant(i);
  kk_std_time_timestamp__timestamp _x = _con6012->since;
  kk_std_time_instant__timescale _pat2 = _con6012->ts;
  struct kk_std_time_instant_Timescale* _con6013 = kk_std_time_instant__as_Timescale(_pat2);
  _x6011 = _x; /*std/time/timestamp/timestamp*/
  kk_std_core_types__optional _x6014;
  kk_box_t _x6015;
  kk_integer_t _x6016;
  if (kk_std_core_types__is_Optional(max_prec)) {
    kk_box_t _box_x4943 = max_prec._cons.Optional.value;
    kk_integer_t _max_prec_4044 = kk_integer_unbox(_box_x4943);
    _x6016 = _max_prec_4044; /*int*/
    goto _match6017;
  }
  _x6016 = kk_integer_from_small(9); /*int*/
  _match6017: ;
  _x6015 = kk_integer_box(_x6016); /*35*/
  _x6014 = kk_std_core_types__new_Optional(_x6015, _ctx); /*optional<35>*/
  kk_std_core_types__optional _x6019;
  kk_box_t _x6020;
  kk_integer_t _x6021;
  if (kk_std_core_types__is_Optional(secs_width)) {
    kk_box_t _box_x4945 = secs_width._cons.Optional.value;
    kk_integer_t _secs_width_4048 = kk_integer_unbox(_box_x4945);
    _x6021 = _secs_width_4048; /*int*/
    goto _match6022;
  }
  _x6021 = kk_integer_from_small(1); /*int*/
  _match6022: ;
  _x6020 = kk_integer_box(_x6021); /*35*/
  _x6019 = kk_std_core_types__new_Optional(_x6020, _ctx); /*optional<35>*/
  kk_std_core_types__optional _x6024;
  kk_box_t _x6025;
  kk_string_t _x6026;
  if (kk_std_core_types__is_Optional(unit0)) {
    kk_box_t _box_x4947 = unit0._cons.Optional.value;
    kk_string_t _unit_4052 = kk_string_unbox(_box_x4947);
    _x6026 = _unit_4052; /*string*/
    goto _match6027;
  }
  _x6026 = kk_string_empty(); /*string*/
  _match6027: ;
  _x6025 = kk_string_box(_x6026); /*35*/
  _x6024 = kk_std_core_types__new_Optional(_x6025, _ctx); /*optional<35>*/
  _x6010 = kk_std_time_timestamp_ts_show(_x6011, _x6014, _x6019, _x6024, _ctx); /*string*/
  kk_string_t _x6030;
  bool _match_5229;
  bool _match_5231;
  kk_string_t _x6031;
  kk_std_time_instant__timescale _match_5233;
  struct kk_std_time_instant_Instant* _con6032 = kk_std_time_instant__as_Instant(i);
  kk_std_time_timestamp__timestamp _pat02 = _con6032->since;
  kk_std_time_instant__timescale _x1 = _con6032->ts;
  struct kk_std_time_instant_Timescale* _con6033 = kk_std_time_instant__as_Timescale(_x1);
  kk_std_time_instant__timescale_dup(_x1);
  _match_5233 = _x1; /*std/time/instant/timescale*/
  struct kk_std_time_instant_Timescale* _con6034 = kk_std_time_instant__as_Timescale(_match_5233);
  kk_string_t _x0 = _con6034->name;
  kk_string_t _pat01 = _con6034->unit;
  kk_function_t _pat13 = _con6034->from_tai;
  kk_function_t _pat21 = _con6034->to_tai;
  kk_std_core_types__maybe _pat31 = _con6034->mb_seconds_in_day;
  kk_std_core_types__maybe _pat41 = _con6034->mb_to_mjd2000;
  kk_std_core_types__maybe _pat50 = _con6034->mb_from_mjd2000;
  if (kk_std_time_instant__timescale_is_unique(_match_5233)) {
    kk_std_core_types__maybe_drop(_pat50, _ctx);
    kk_std_core_types__maybe_drop(_pat41, _ctx);
    kk_std_core_types__maybe_drop(_pat31, _ctx);
    kk_function_drop(_pat21, _ctx);
    kk_function_drop(_pat13, _ctx);
    kk_string_drop(_pat01, _ctx);
    kk_std_time_instant__timescale_free(_match_5233);
  }
  else {
    kk_string_dup(_x0);
    kk_std_time_instant__timescale_decref(_match_5233, _ctx);
  }
  _x6031 = _x0; /*string*/
  kk_string_t _x6035 = kk_string_empty(); /*string*/
  _match_5231 = kk_string_is_eq(_x6031,_x6035,kk_context()); /*bool*/
  if (_match_5231) {
    _match_5229 = true; /*bool*/
  }
  else {
    kk_string_t _x6037;
    kk_std_time_instant__timescale _match_5232;
    struct kk_std_time_instant_Instant* _con6038 = kk_std_time_instant__as_Instant(i);
    kk_std_time_timestamp__timestamp _pat04 = _con6038->since;
    kk_std_time_instant__timescale _x3 = _con6038->ts;
    struct kk_std_time_instant_Timescale* _con6039 = kk_std_time_instant__as_Timescale(_x3);
    kk_std_time_instant__timescale_dup(_x3);
    _match_5232 = _x3; /*std/time/instant/timescale*/
    struct kk_std_time_instant_Timescale* _con6040 = kk_std_time_instant__as_Timescale(_match_5232);
    kk_string_t _x2 = _con6040->name;
    kk_string_t _pat03 = _con6040->unit;
    kk_function_t _pat17 = _con6040->from_tai;
    kk_function_t _pat23 = _con6040->to_tai;
    kk_std_core_types__maybe _pat33 = _con6040->mb_seconds_in_day;
    kk_std_core_types__maybe _pat43 = _con6040->mb_to_mjd2000;
    kk_std_core_types__maybe _pat53 = _con6040->mb_from_mjd2000;
    if (kk_std_time_instant__timescale_is_unique(_match_5232)) {
      kk_std_core_types__maybe_drop(_pat53, _ctx);
      kk_std_core_types__maybe_drop(_pat43, _ctx);
      kk_std_core_types__maybe_drop(_pat33, _ctx);
      kk_function_drop(_pat23, _ctx);
      kk_function_drop(_pat17, _ctx);
      kk_string_drop(_pat03, _ctx);
      kk_std_time_instant__timescale_free(_match_5232);
    }
    else {
      kk_string_dup(_x2);
      kk_std_time_instant__timescale_decref(_match_5232, _ctx);
    }
    _x6037 = _x2; /*string*/
    kk_string_t _x6041;
    kk_define_string_literal(, _s6042, 3, "TAI")
    _x6041 = kk_string_dup(_s6042); /*string*/
    _match_5229 = kk_string_is_eq(_x6037,_x6041,kk_context()); /*bool*/
  }
  if (_match_5229) {
    kk_std_time_instant__instant_dropn(i, ((int32_t)1), _ctx);
    _x6030 = kk_string_empty(); /*string*/
  }
  else {
    kk_string_t _x6044;
    kk_define_string_literal(, _s6045, 1, " ")
    _x6044 = kk_string_dup(_s6045); /*string*/
    kk_string_t _x6046;
    kk_std_time_instant__timescale _match_5230;
    struct kk_std_time_instant_Instant* _con6047 = kk_std_time_instant__as_Instant(i);
    kk_std_time_timestamp__timestamp _pat06 = _con6047->since;
    kk_std_time_instant__timescale _x5 = _con6047->ts;
    struct kk_std_time_instant_Timescale* _con6048 = kk_std_time_instant__as_Timescale(_x5);
    if (kk_std_time_instant__instant_is_unique(i)) {
      kk_std_time_instant__instant_free(i);
    }
    else {
      kk_std_time_instant__timescale_dup(_x5);
      kk_std_time_instant__instant_decref(i, _ctx);
    }
    _match_5230 = _x5; /*std/time/instant/timescale*/
    struct kk_std_time_instant_Timescale* _con6049 = kk_std_time_instant__as_Timescale(_match_5230);
    kk_string_t _x4 = _con6049->name;
    kk_string_t _pat05 = _con6049->unit;
    kk_function_t _pat110 = _con6049->from_tai;
    kk_function_t _pat26 = _con6049->to_tai;
    kk_std_core_types__maybe _pat35 = _con6049->mb_seconds_in_day;
    kk_std_core_types__maybe _pat45 = _con6049->mb_to_mjd2000;
    kk_std_core_types__maybe _pat55 = _con6049->mb_from_mjd2000;
    if (kk_std_time_instant__timescale_is_unique(_match_5230)) {
      kk_std_core_types__maybe_drop(_pat55, _ctx);
      kk_std_core_types__maybe_drop(_pat45, _ctx);
      kk_std_core_types__maybe_drop(_pat35, _ctx);
      kk_function_drop(_pat26, _ctx);
      kk_function_drop(_pat110, _ctx);
      kk_string_drop(_pat05, _ctx);
      kk_std_time_instant__timescale_free(_match_5230);
    }
    else {
      kk_string_dup(_x4);
      kk_std_time_instant__timescale_decref(_match_5230, _ctx);
    }
    _x6046 = _x4; /*string*/
    _x6030 = kk_std_core__lp__plus__plus__1_rp_(_x6044, _x6046, _ctx); /*string*/
  }
  return kk_std_core__lp__plus__plus__1_rp_(_x6010, _x6030, _ctx);
}
 
// Show an instant as a number of (TAI) SI seconds since the `epoch` in a given precision.
// This can be used as an unambigious time stamp.

kk_string_t kk_std_time_instant_show(kk_std_time_instant__instant i, kk_std_core_types__optional max_prec, kk_std_core_types__optional secs_width, kk_context_t* _ctx) { /* (i : instant, max-prec : optional<int>, secs-width : optional<int>) -> string */ 
  kk_std_time_instant__instant i0_4743;
  kk_std_time_instant__timescale _x6050 = kk_std_time_instant__timescale_dup(kk_std_time_instant_ts_tai); /*std/time/instant/timescale*/
  i0_4743 = kk_std_time_instant_use_timescale(i, _x6050, _ctx); /*std/time/instant/instant*/
  kk_std_core_types__optional max_prec0_4744;
  kk_box_t _x6051;
  kk_integer_t _x6052;
  if (kk_std_core_types__is_Optional(max_prec)) {
    kk_box_t _box_x4952 = max_prec._cons.Optional.value;
    kk_integer_t _max_prec_4252 = kk_integer_unbox(_box_x4952);
    _x6052 = _max_prec_4252; /*int*/
    goto _match6053;
  }
  _x6052 = kk_integer_from_small(9); /*int*/
  _match6053: ;
  _x6051 = kk_integer_box(_x6052); /*35*/
  max_prec0_4744 = kk_std_core_types__new_Optional(_x6051, _ctx); /*optional<int>*/
  kk_std_core_types__optional secs_width0_4745;
  kk_box_t _x6055;
  kk_integer_t _x6056;
  if (kk_std_core_types__is_Optional(secs_width)) {
    kk_box_t _box_x4955 = secs_width._cons.Optional.value;
    kk_integer_t _secs_width_4256 = kk_integer_unbox(_box_x4955);
    _x6056 = _secs_width_4256; /*int*/
    goto _match6057;
  }
  _x6056 = kk_integer_from_small(1); /*int*/
  _match6057: ;
  _x6055 = kk_integer_box(_x6056); /*35*/
  secs_width0_4745 = kk_std_core_types__new_Optional(_x6055, _ctx); /*optional<int>*/
  kk_std_core_types__optional unit_4746;
  kk_box_t _x6059;
  kk_string_t _x6060;
  kk_define_string_literal(, _s6061, 1, "s")
  _x6060 = kk_string_dup(_s6061); /*string*/
  _x6059 = kk_string_box(_x6060); /*35*/
  unit_4746 = kk_std_core_types__new_Optional(_x6059, _ctx); /*optional<string>*/
  kk_string_t _x6062;
  kk_std_time_timestamp__timestamp _x6063;
  struct kk_std_time_instant_Instant* _con6064 = kk_std_time_instant__as_Instant(i0_4743);
  kk_std_time_timestamp__timestamp _x = _con6064->since;
  kk_std_time_instant__timescale _pat2 = _con6064->ts;
  struct kk_std_time_instant_Timescale* _con6065 = kk_std_time_instant__as_Timescale(_pat2);
  _x6063 = _x; /*std/time/timestamp/timestamp*/
  kk_std_core_types__optional _x6066;
  kk_box_t _x6067;
  kk_integer_t _x6068;
  if (kk_std_core_types__is_Optional(max_prec0_4744)) {
    kk_box_t _box_x4960 = max_prec0_4744._cons.Optional.value;
    kk_integer_t _max_prec_4044 = kk_integer_unbox(_box_x4960);
    _x6068 = _max_prec_4044; /*int*/
    goto _match6069;
  }
  _x6068 = kk_integer_from_small(9); /*int*/
  _match6069: ;
  _x6067 = kk_integer_box(_x6068); /*35*/
  _x6066 = kk_std_core_types__new_Optional(_x6067, _ctx); /*optional<35>*/
  kk_std_core_types__optional _x6071;
  kk_box_t _x6072;
  kk_integer_t _x6073;
  if (kk_std_core_types__is_Optional(secs_width0_4745)) {
    kk_box_t _box_x4962 = secs_width0_4745._cons.Optional.value;
    kk_integer_t _secs_width_4048 = kk_integer_unbox(_box_x4962);
    _x6073 = _secs_width_4048; /*int*/
    goto _match6074;
  }
  _x6073 = kk_integer_from_small(1); /*int*/
  _match6074: ;
  _x6072 = kk_integer_box(_x6073); /*35*/
  _x6071 = kk_std_core_types__new_Optional(_x6072, _ctx); /*optional<35>*/
  kk_std_core_types__optional _x6076;
  kk_box_t _x6077;
  kk_string_t _x6078;
  if (kk_std_core_types__is_Optional(unit_4746)) {
    kk_box_t _box_x4964 = unit_4746._cons.Optional.value;
    kk_string_t _unit_4052 = kk_string_unbox(_box_x4964);
    _x6078 = _unit_4052; /*string*/
    goto _match6079;
  }
  _x6078 = kk_string_empty(); /*string*/
  _match6079: ;
  _x6077 = kk_string_box(_x6078); /*35*/
  _x6076 = kk_std_core_types__new_Optional(_x6077, _ctx); /*optional<35>*/
  _x6062 = kk_std_time_timestamp_ts_show(_x6063, _x6066, _x6071, _x6076, _ctx); /*string*/
  kk_string_t _x6082;
  bool _match_5224;
  bool _match_5226;
  kk_string_t _x6083;
  kk_std_time_instant__timescale _match_5228;
  struct kk_std_time_instant_Instant* _con6084 = kk_std_time_instant__as_Instant(i0_4743);
  kk_std_time_timestamp__timestamp _pat02 = _con6084->since;
  kk_std_time_instant__timescale _x1 = _con6084->ts;
  struct kk_std_time_instant_Timescale* _con6085 = kk_std_time_instant__as_Timescale(_x1);
  kk_std_time_instant__timescale_dup(_x1);
  _match_5228 = _x1; /*std/time/instant/timescale*/
  struct kk_std_time_instant_Timescale* _con6086 = kk_std_time_instant__as_Timescale(_match_5228);
  kk_string_t _x0 = _con6086->name;
  kk_string_t _pat01 = _con6086->unit;
  kk_function_t _pat13 = _con6086->from_tai;
  kk_function_t _pat21 = _con6086->to_tai;
  kk_std_core_types__maybe _pat31 = _con6086->mb_seconds_in_day;
  kk_std_core_types__maybe _pat41 = _con6086->mb_to_mjd2000;
  kk_std_core_types__maybe _pat50 = _con6086->mb_from_mjd2000;
  if (kk_std_time_instant__timescale_is_unique(_match_5228)) {
    kk_std_core_types__maybe_drop(_pat50, _ctx);
    kk_std_core_types__maybe_drop(_pat41, _ctx);
    kk_std_core_types__maybe_drop(_pat31, _ctx);
    kk_function_drop(_pat21, _ctx);
    kk_function_drop(_pat13, _ctx);
    kk_string_drop(_pat01, _ctx);
    kk_std_time_instant__timescale_free(_match_5228);
  }
  else {
    kk_string_dup(_x0);
    kk_std_time_instant__timescale_decref(_match_5228, _ctx);
  }
  _x6083 = _x0; /*string*/
  kk_string_t _x6087 = kk_string_empty(); /*string*/
  _match_5226 = kk_string_is_eq(_x6083,_x6087,kk_context()); /*bool*/
  if (_match_5226) {
    _match_5224 = true; /*bool*/
  }
  else {
    kk_string_t _x6089;
    kk_std_time_instant__timescale _match_5227;
    struct kk_std_time_instant_Instant* _con6090 = kk_std_time_instant__as_Instant(i0_4743);
    kk_std_time_timestamp__timestamp _pat04 = _con6090->since;
    kk_std_time_instant__timescale _x3 = _con6090->ts;
    struct kk_std_time_instant_Timescale* _con6091 = kk_std_time_instant__as_Timescale(_x3);
    kk_std_time_instant__timescale_dup(_x3);
    _match_5227 = _x3; /*std/time/instant/timescale*/
    struct kk_std_time_instant_Timescale* _con6092 = kk_std_time_instant__as_Timescale(_match_5227);
    kk_string_t _x2 = _con6092->name;
    kk_string_t _pat03 = _con6092->unit;
    kk_function_t _pat17 = _con6092->from_tai;
    kk_function_t _pat23 = _con6092->to_tai;
    kk_std_core_types__maybe _pat33 = _con6092->mb_seconds_in_day;
    kk_std_core_types__maybe _pat43 = _con6092->mb_to_mjd2000;
    kk_std_core_types__maybe _pat53 = _con6092->mb_from_mjd2000;
    if (kk_std_time_instant__timescale_is_unique(_match_5227)) {
      kk_std_core_types__maybe_drop(_pat53, _ctx);
      kk_std_core_types__maybe_drop(_pat43, _ctx);
      kk_std_core_types__maybe_drop(_pat33, _ctx);
      kk_function_drop(_pat23, _ctx);
      kk_function_drop(_pat17, _ctx);
      kk_string_drop(_pat03, _ctx);
      kk_std_time_instant__timescale_free(_match_5227);
    }
    else {
      kk_string_dup(_x2);
      kk_std_time_instant__timescale_decref(_match_5227, _ctx);
    }
    _x6089 = _x2; /*string*/
    kk_string_t _x6093;
    kk_define_string_literal(, _s6094, 3, "TAI")
    _x6093 = kk_string_dup(_s6094); /*string*/
    _match_5224 = kk_string_is_eq(_x6089,_x6093,kk_context()); /*bool*/
  }
  if (_match_5224) {
    kk_std_time_instant__instant_dropn(i0_4743, ((int32_t)1), _ctx);
    _x6082 = kk_string_empty(); /*string*/
  }
  else {
    kk_string_t _x6096;
    kk_define_string_literal(, _s6097, 1, " ")
    _x6096 = kk_string_dup(_s6097); /*string*/
    kk_string_t _x6098;
    kk_std_time_instant__timescale _match_5225;
    struct kk_std_time_instant_Instant* _con6099 = kk_std_time_instant__as_Instant(i0_4743);
    kk_std_time_timestamp__timestamp _pat06 = _con6099->since;
    kk_std_time_instant__timescale _x5 = _con6099->ts;
    struct kk_std_time_instant_Timescale* _con6100 = kk_std_time_instant__as_Timescale(_x5);
    if (kk_std_time_instant__instant_is_unique(i0_4743)) {
      kk_std_time_instant__instant_free(i0_4743);
    }
    else {
      kk_std_time_instant__timescale_dup(_x5);
      kk_std_time_instant__instant_decref(i0_4743, _ctx);
    }
    _match_5225 = _x5; /*std/time/instant/timescale*/
    struct kk_std_time_instant_Timescale* _con6101 = kk_std_time_instant__as_Timescale(_match_5225);
    kk_string_t _x4 = _con6101->name;
    kk_string_t _pat05 = _con6101->unit;
    kk_function_t _pat110 = _con6101->from_tai;
    kk_function_t _pat26 = _con6101->to_tai;
    kk_std_core_types__maybe _pat35 = _con6101->mb_seconds_in_day;
    kk_std_core_types__maybe _pat45 = _con6101->mb_to_mjd2000;
    kk_std_core_types__maybe _pat55 = _con6101->mb_from_mjd2000;
    if (kk_std_time_instant__timescale_is_unique(_match_5225)) {
      kk_std_core_types__maybe_drop(_pat55, _ctx);
      kk_std_core_types__maybe_drop(_pat45, _ctx);
      kk_std_core_types__maybe_drop(_pat35, _ctx);
      kk_function_drop(_pat26, _ctx);
      kk_function_drop(_pat110, _ctx);
      kk_string_drop(_pat05, _ctx);
      kk_std_time_instant__timescale_free(_match_5225);
    }
    else {
      kk_string_dup(_x4);
      kk_std_time_instant__timescale_decref(_match_5225, _ctx);
    }
    _x6098 = _x4; /*string*/
    _x6082 = kk_std_core__lp__plus__plus__1_rp_(_x6096, _x6098, _ctx); /*string*/
  }
  return kk_std_core__lp__plus__plus__1_rp_(_x6062, _x6082, _ctx);
}
 
// Show a timestamp with an optional maximum precision (`max-prec` (=`9`)) and
// minimum width for the seconds (=`1`).

kk_string_t kk_std_time_instant_show_1(kk_std_time_timestamp__timestamp t, kk_std_core_types__optional max_prec, kk_std_core_types__optional secs_width, kk_std_core_types__optional unit0, kk_context_t* _ctx) { /* (t : std/time/timestamp/timestamp, max-prec : optional<int>, secs-width : optional<int>, unit : optional<string>) -> string */ 
  kk_std_core_types__optional _x6102;
  kk_box_t _x6103;
  kk_integer_t _x6104;
  if (kk_std_core_types__is_Optional(max_prec)) {
    kk_box_t _box_x4969 = max_prec._cons.Optional.value;
    kk_integer_t _max_prec_4280 = kk_integer_unbox(_box_x4969);
    _x6104 = _max_prec_4280; /*int*/
    goto _match6105;
  }
  _x6104 = kk_integer_from_small(9); /*int*/
  _match6105: ;
  _x6103 = kk_integer_box(_x6104); /*35*/
  _x6102 = kk_std_core_types__new_Optional(_x6103, _ctx); /*optional<35>*/
  kk_std_core_types__optional _x6107;
  kk_box_t _x6108;
  kk_integer_t _x6109;
  if (kk_std_core_types__is_Optional(secs_width)) {
    kk_box_t _box_x4971 = secs_width._cons.Optional.value;
    kk_integer_t _secs_width_4284 = kk_integer_unbox(_box_x4971);
    _x6109 = _secs_width_4284; /*int*/
    goto _match6110;
  }
  _x6109 = kk_integer_from_small(1); /*int*/
  _match6110: ;
  _x6108 = kk_integer_box(_x6109); /*35*/
  _x6107 = kk_std_core_types__new_Optional(_x6108, _ctx); /*optional<35>*/
  kk_std_core_types__optional _x6112;
  kk_box_t _x6113;
  kk_string_t _x6114;
  if (kk_std_core_types__is_Optional(unit0)) {
    kk_box_t _box_x4973 = unit0._cons.Optional.value;
    kk_string_t _unit_4288 = kk_string_unbox(_box_x4973);
    _x6114 = _unit_4288; /*string*/
    goto _match6115;
  }
  _x6114 = kk_string_empty(); /*string*/
  _match6115: ;
  _x6113 = kk_string_box(_x6114); /*35*/
  _x6112 = kk_std_core_types__new_Optional(_x6113, _ctx); /*optional<35>*/
  return kk_std_time_timestamp_ts_show(t, _x6102, _x6107, _x6112, _ctx);
}
 
// The [TT](https://en.wikipedia.org/wiki/Terrestrial_Time) (Terrestrial time)
// time scale is based on SI seconds with a 1977-01-01 TAI `epoch`. It is the
// continuation of TDT (Terrestrial dynamic time) and ET (Ephemeris time). TT
// is defined as: TT = TAI + 32.184s.


// lift anonymous function
struct kk_std_time_instant_ts_tt_fun6130__t {
  struct kk_function_s _base;
  kk_std_time_duration__duration _offset_990;
};
static kk_std_time_timestamp__timestamp kk_std_time_instant_ts_tt_fun6130(kk_function_t _fself, kk_std_time_duration__duration tai, kk_context_t* _ctx);
static kk_function_t kk_std_time_instant_new_ts_tt_fun6130(kk_std_time_duration__duration _offset_990, kk_context_t* _ctx) {
  struct kk_std_time_instant_ts_tt_fun6130__t* _self = kk_function_alloc_as(struct kk_std_time_instant_ts_tt_fun6130__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_time_instant_ts_tt_fun6130, kk_context());
  _self->_offset_990 = _offset_990;
  return &_self->_base;
}

static kk_std_time_timestamp__timestamp kk_std_time_instant_ts_tt_fun6130(kk_function_t _fself, kk_std_time_duration__duration tai, kk_context_t* _ctx) {
  struct kk_std_time_instant_ts_tt_fun6130__t* _self = kk_function_as(struct kk_std_time_instant_ts_tt_fun6130__t*, _fself);
  kk_std_time_duration__duration _offset_990 = _self->_offset_990; /* std/time/duration/duration */
  kk_drop_match(_self, {kk_std_time_duration__duration_dup(_offset_990);}, {}, _ctx)
  kk_std_num_ddouble__ddouble t_4714;
  kk_std_num_ddouble__ddouble _x6131;
  kk_std_num_ddouble__ddouble _x0 = tai.secs;
  _x6131 = _x0; /*std/time/timestamp/timespan*/
  kk_std_num_ddouble__ddouble _x6132;
  kk_std_num_ddouble__ddouble _x = _offset_990.secs;
  _x6132 = _x; /*std/time/timestamp/timespan*/
  t_4714 = kk_std_num_ddouble__lp__plus__rp_(_x6131, _x6132, _ctx); /*std/time/timestamp/timespan*/
  int32_t _x6133;
  kk_integer_t _x6134;
  kk_std_core_types__optional _x6135 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/
  if (kk_std_core_types__is_Optional(_x6135)) {
    kk_box_t _box_x4984 = _x6135._cons.Optional.value;
    kk_integer_t _leap_492 = kk_integer_unbox(_box_x4984);
    _x6134 = _leap_492; /*int*/
    goto _match6136;
  }
  _x6134 = kk_integer_from_small(0); /*int*/
  _match6136: ;
  _x6133 = kk_std_core_int32(_x6134, _ctx); /*int32*/
  return kk_std_time_timestamp__new_Timestamp(t_4714, _x6133, _ctx);
}


// lift anonymous function
struct kk_std_time_instant_ts_tt_fun6138__t {
  struct kk_function_s _base;
  kk_std_time_duration__duration _offset_990;
};
static kk_std_time_duration__duration kk_std_time_instant_ts_tt_fun6138(kk_function_t _fself, kk_std_time_timestamp__timestamp t0, kk_context_t* _ctx);
static kk_function_t kk_std_time_instant_new_ts_tt_fun6138(kk_std_time_duration__duration _offset_990, kk_context_t* _ctx) {
  struct kk_std_time_instant_ts_tt_fun6138__t* _self = kk_function_alloc_as(struct kk_std_time_instant_ts_tt_fun6138__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_time_instant_ts_tt_fun6138, kk_context());
  _self->_offset_990 = _offset_990;
  return &_self->_base;
}

static kk_std_time_duration__duration kk_std_time_instant_ts_tt_fun6138(kk_function_t _fself, kk_std_time_timestamp__timestamp t0, kk_context_t* _ctx) {
  struct kk_std_time_instant_ts_tt_fun6138__t* _self = kk_function_as(struct kk_std_time_instant_ts_tt_fun6138__t*, _fself);
  kk_std_time_duration__duration _offset_990 = _self->_offset_990; /* std/time/duration/duration */
  kk_drop_match(_self, {kk_std_time_duration__duration_dup(_offset_990);}, {}, _ctx)
  kk_std_time_timestamp__timestamp t1_4717;
  kk_std_num_ddouble__ddouble _x6139;
  kk_std_num_ddouble__ddouble _x1 = _offset_990.secs;
  _x6139 = _x1; /*std/time/timestamp/timespan*/
  t1_4717 = kk_std_time_timestamp__lp__dash__rp_(t0, _x6139, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_num_ddouble__ddouble _x6140 = kk_std_time_timestamp_unsafe_timespan_withleap(t1_4717, _ctx); /*std/time/timestamp/timespan*/
  return kk_std_time_duration__new_Duration(_x6140, _ctx);
}

kk_std_time_instant__timescale kk_std_time_instant_ts_tt;

kk_std_time_duration__duration kk_std_time_instant_tt2000;
 
// Get the TT time in SI seconds since the TT epoch (1977-01-01 TAI)

kk_std_time_duration__duration kk_std_time_instant_tt_instant(kk_std_time_instant__instant i, kk_context_t* _ctx) { /* (i : instant) -> std/time/duration/duration */ 
  kk_std_time_duration__duration d_4718;
  kk_std_time_timestamp__timestamp t_4720;
  kk_std_time_instant__timescale _x6153 = kk_std_time_instant__timescale_dup(kk_std_time_instant_ts_tt); /*std/time/instant/timescale*/
  t_4720 = kk_std_time_instant_timestamp_in(i, _x6153, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_num_ddouble__ddouble _x6154 = kk_std_time_timestamp_unsafe_timespan_withleap(t_4720, _ctx); /*std/time/timestamp/timespan*/
  d_4718 = kk_std_time_duration__new_Duration(_x6154, _ctx); /*std/time/duration/duration*/
  kk_std_time_duration__duration e_4719 = kk_std_time_duration_duration_1(kk_integer_from_int(630720000, _ctx), kk_std_core_types__new_None(_ctx), _ctx); /*std/time/duration/duration*/;
  kk_std_num_ddouble__ddouble _x6155;
  kk_std_num_ddouble__ddouble _x6156;
  kk_std_num_ddouble__ddouble _x = d_4718.secs;
  _x6156 = _x; /*std/time/timestamp/timespan*/
  kk_std_num_ddouble__ddouble _x6157;
  kk_std_num_ddouble__ddouble _x0 = e_4719.secs;
  _x6157 = _x0; /*std/time/timestamp/timespan*/
  _x6155 = kk_std_num_ddouble__lp__plus__rp_(_x6156, _x6157, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_time_duration__new_Duration(_x6155, _ctx);
}
 
// Create an instant from a raw TT time since the TT epoch (1977-01-01 TAI)

kk_std_time_instant__instant kk_std_time_instant_tt_instant_1(kk_std_time_duration__duration tt, kk_context_t* _ctx) { /* (tt : std/time/duration/duration) -> instant */ 
  kk_std_time_duration__duration d_4721;
  kk_std_time_duration__duration e_4749 = kk_std_time_duration_duration_1(kk_integer_from_int(630720000, _ctx), kk_std_core_types__new_None(_ctx), _ctx); /*std/time/duration/duration*/;
  kk_std_time_duration__duration e0_2276 = kk_std_time_duration__lp__tilde__rp_(e_4749, _ctx); /*std/time/duration/duration*/;
  kk_std_num_ddouble__ddouble _x6158;
  kk_std_num_ddouble__ddouble _x6159;
  kk_std_num_ddouble__ddouble _x = tt.secs;
  _x6159 = _x; /*std/time/timestamp/timespan*/
  kk_std_num_ddouble__ddouble _x6160;
  kk_std_num_ddouble__ddouble _x0 = e0_2276.secs;
  _x6160 = _x0; /*std/time/timestamp/timespan*/
  _x6158 = kk_std_num_ddouble__lp__plus__rp_(_x6159, _x6160, _ctx); /*std/num/ddouble/ddouble*/
  d_4721 = kk_std_time_duration__new_Duration(_x6158, _ctx); /*std/time/duration/duration*/
  kk_std_time_timestamp__timestamp t_4723 = kk_std_time_duration_timestamp(d_4721, _ctx); /*std/time/timestamp/timestamp*/;
  kk_std_time_instant__timescale _x6161 = kk_std_time_instant__timescale_dup(kk_std_time_instant_ts_tai); /*std/time/instant/timescale*/
  return kk_std_time_instant__new_Instant(kk_reuse_null, t_4723, _x6161, _ctx);
}

// initialization
void kk_std_time_instant__init(kk_context_t* _ctx){
  static bool _initialized = false;
  if (_initialized) return;
  _initialized = true;
  kk_std_core_types__init(_ctx);
  kk_std_core__init(_ctx);
  kk_std_num_ddouble__init(_ctx);
  kk_std_time_date__init(_ctx);
  kk_std_time_timestamp__init(_ctx);
  kk_std_time_duration__init(_ctx);
  {
    bool _match_5331;
    double _x5389;
    kk_std_core_types__optional _x5390 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/
    if (kk_std_core_types__is_Optional(_x5390)) {
      kk_box_t _box_x4771 = _x5390._cons.Optional.value;
      double _frac_1424 = kk_double_unbox(_box_x4771, NULL);
      _x5389 = _frac_1424; /*double*/
      goto _match5391;
    }
    _x5389 = 0x0p+0; /*double*/
    _match5391: ;
    _match_5331 = (_x5389 == (0x0p+0)); /*bool*/
    if (_match_5331) {
      kk_std_time_instant_mjd_epoch_delta = kk_std_num_ddouble_ddouble_1(kk_integer_from_int(51544, _ctx), _ctx); /*std/time/timestamp/timespan*/
    }
    else {
      kk_std_num_ddouble__ddouble _x5393 = kk_std_num_ddouble_ddouble_1(kk_integer_from_int(51544, _ctx), _ctx); /*std/num/ddouble/ddouble*/
      kk_std_num_ddouble__ddouble _x5394;
      double _x5395;
      kk_std_core_types__optional _x5396 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/
      if (kk_std_core_types__is_Optional(_x5396)) {
        kk_box_t _box_x4772 = _x5396._cons.Optional.value;
        double _frac_14240 = kk_double_unbox(_box_x4772, NULL);
        _x5395 = _frac_14240; /*double*/
        goto _match5397;
      }
      _x5395 = 0x0p+0; /*double*/
      _match5397: ;
      _x5394 = kk_std_num_ddouble__new_Ddouble(_x5395, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
      kk_std_time_instant_mjd_epoch_delta = kk_std_num_ddouble__lp__plus__rp_(_x5393, _x5394, _ctx); /*std/time/timestamp/timespan*/
    }
  }
  {
    kk_std_time_instant_jd_epoch_delta = kk_std_num_ddouble__new_Ddouble(0x1.24f804p21, 0x0p+0, _ctx); /*std/time/timestamp/timespan*/
  }
  {
    kk_std_time_duration__duration _offset_990;
    kk_std_core_types__optional _x5464 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/
    if (kk_std_core_types__is_Optional(_x5464)) {
      kk_box_t _box_x4796 = _x5464._cons.Optional.value;
      kk_std_time_duration__duration _offset_991 = kk_std_time_duration__duration_unbox(_box_x4796, NULL);
      _offset_990 = _offset_991; /*std/time/duration/duration*/
      goto _match5465;
    }
    _offset_990 = kk_std_time_duration_duration_1(kk_integer_from_small(0), kk_std_core_types__new_None(_ctx), _ctx); /*std/time/duration/duration*/
    _match5465: ;
    kk_std_core_types__optional unit_4489;
    kk_box_t _x5467;
    kk_string_t _x5468;
    kk_define_string_literal(, _s5469, 3, "TAI")
    _x5468 = kk_string_dup(_s5469); /*string*/
    _x5467 = kk_string_box(_x5468); /*35*/
    unit_4489 = kk_std_core_types__new_Optional(_x5467, _ctx); /*optional<string>*/
    kk_string_t _x5470;
    kk_define_string_literal(, _s5471, 3, "TAI")
    _x5470 = kk_string_dup(_s5471); /*string*/
    kk_string_t _x5472;
    if (kk_std_core_types__is_Optional(unit_4489)) {
      kk_box_t _box_x4799 = unit_4489._cons.Optional.value;
      kk_string_t _unit_366 = kk_string_unbox(_box_x4799);
      _x5472 = _unit_366; /*string*/
      goto _match5473;
    }
    kk_define_string_literal(, _s5475, 3, "TAI")
    _x5472 = kk_string_dup(_s5475); /*string*/
    _match5473: ;
    kk_std_core_types__maybe _x5487;
    kk_std_core_types__optional _x5488 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/
    if (kk_std_core_types__is_Optional(_x5488)) {
      kk_box_t _box_x4801 = _x5488._cons.Optional.value;
      kk_std_core_types__maybe _seconds_in_day_371 = kk_std_core_types__maybe_unbox(_box_x4801, NULL);
      _x5487 = _seconds_in_day_371; /*maybe<(std/time/timestamp/timestamp) -> std/time/timestamp/timespan>*/
      goto _match5489;
    }
    _x5487 = kk_std_core_types__new_Nothing(_ctx); /*maybe<(std/time/timestamp/timestamp) -> std/time/timestamp/timespan>*/
    _match5489: ;
    kk_std_core_types__maybe _x5491;
    kk_std_core_types__optional _x5492 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/
    if (kk_std_core_types__is_Optional(_x5492)) {
      kk_box_t _box_x4802 = _x5492._cons.Optional.value;
      kk_std_core_types__maybe _to_mjd2000_376 = kk_std_core_types__maybe_unbox(_box_x4802, NULL);
      _x5491 = _to_mjd2000_376; /*maybe<(t : std/time/timestamp/timestamp, tzdelta : std/time/timestamp/timespan) -> std/num/ddouble/ddouble>*/
      goto _match5493;
    }
    _x5491 = kk_std_core_types__new_Nothing(_ctx); /*maybe<(t : std/time/timestamp/timestamp, tzdelta : std/time/timestamp/timespan) -> std/num/ddouble/ddouble>*/
    _match5493: ;
    kk_std_core_types__maybe _x5495;
    kk_std_core_types__optional _x5496 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/
    if (kk_std_core_types__is_Optional(_x5496)) {
      kk_box_t _box_x4803 = _x5496._cons.Optional.value;
      kk_std_core_types__maybe _from_mjd2000_381 = kk_std_core_types__maybe_unbox(_box_x4803, NULL);
      _x5495 = _from_mjd2000_381; /*maybe<(days : int, frac : std/num/ddouble/ddouble) -> std/time/timestamp/timestamp>*/
      goto _match5497;
    }
    _x5495 = kk_std_core_types__new_Nothing(_ctx); /*maybe<(days : int, frac : std/num/ddouble/ddouble) -> std/time/timestamp/timestamp>*/
    _match5497: ;
    kk_std_time_instant_ts_tai = kk_std_time_instant__new_Timescale(kk_reuse_null, _x5470, _x5472, kk_std_time_instant_new_ts_tai_fun5476(_offset_990, _ctx), kk_std_time_instant_new_ts_tai_fun5484(_offset_990, _ctx), _x5487, _x5491, _x5495, _ctx); /*std/time/instant/timescale*/
  }
  {
    kk_std_time_instant_epoch = kk_std_time_instant_instant_1(kk_std_time_duration_duration0, _ctx); /*std/time/instant/instant*/
  }
  {
    kk_std_time_instant_gps2000 = kk_std_time_duration_duration_1(kk_integer_from_int(630720000, _ctx), kk_std_core_types__new_None(_ctx), _ctx); /*std/time/duration/duration*/
  }
  {
    kk_std_core_types__optional offset_4600;
    kk_std_time_duration__duration _b_4824_4823 = kk_std_time_duration_duration_1(kk_integer_from_small(-19), kk_std_core_types__new_None(_ctx), _ctx); /*std/time/duration/duration*/;
    offset_4600 = kk_std_core_types__new_Optional(kk_std_time_duration__duration_box(_b_4824_4823, _ctx), _ctx); /*optional<std/time/duration/duration>*/
    kk_std_time_duration__duration _offset_990;
    if (kk_std_core_types__is_Optional(offset_4600)) {
      kk_box_t _box_x4825 = offset_4600._cons.Optional.value;
      kk_std_time_duration__duration _offset_991 = kk_std_time_duration__duration_unbox(_box_x4825, NULL);
      _offset_990 = _offset_991; /*std/time/duration/duration*/
      goto _match5792;
    }
    _offset_990 = kk_std_time_duration_duration_1(kk_integer_from_small(0), kk_std_core_types__new_None(_ctx), _ctx); /*std/time/duration/duration*/
    _match5792: ;
    kk_std_core_types__optional unit_4605;
    kk_box_t _x5794;
    kk_string_t _x5795;
    kk_define_string_literal(, _s5796, 3, "TAI")
    _x5795 = kk_string_dup(_s5796); /*string*/
    _x5794 = kk_string_box(_x5795); /*35*/
    unit_4605 = kk_std_core_types__new_Optional(_x5794, _ctx); /*optional<string>*/
    kk_string_t _x5797;
    kk_define_string_literal(, _s5798, 3, "GPS")
    _x5797 = kk_string_dup(_s5798); /*string*/
    kk_string_t _x5799;
    if (kk_std_core_types__is_Optional(unit_4605)) {
      kk_box_t _box_x4828 = unit_4605._cons.Optional.value;
      kk_string_t _unit_366 = kk_string_unbox(_box_x4828);
      _x5799 = _unit_366; /*string*/
      goto _match5800;
    }
    kk_define_string_literal(, _s5802, 3, "GPS")
    _x5799 = kk_string_dup(_s5802); /*string*/
    _match5800: ;
    kk_std_core_types__maybe _x5814;
    kk_std_core_types__optional _x5815 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/
    if (kk_std_core_types__is_Optional(_x5815)) {
      kk_box_t _box_x4830 = _x5815._cons.Optional.value;
      kk_std_core_types__maybe _seconds_in_day_371 = kk_std_core_types__maybe_unbox(_box_x4830, NULL);
      _x5814 = _seconds_in_day_371; /*maybe<(std/time/timestamp/timestamp) -> std/time/timestamp/timespan>*/
      goto _match5816;
    }
    _x5814 = kk_std_core_types__new_Nothing(_ctx); /*maybe<(std/time/timestamp/timestamp) -> std/time/timestamp/timespan>*/
    _match5816: ;
    kk_std_core_types__maybe _x5818;
    kk_std_core_types__optional _x5819 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/
    if (kk_std_core_types__is_Optional(_x5819)) {
      kk_box_t _box_x4831 = _x5819._cons.Optional.value;
      kk_std_core_types__maybe _to_mjd2000_376 = kk_std_core_types__maybe_unbox(_box_x4831, NULL);
      _x5818 = _to_mjd2000_376; /*maybe<(t : std/time/timestamp/timestamp, tzdelta : std/time/timestamp/timespan) -> std/num/ddouble/ddouble>*/
      goto _match5820;
    }
    _x5818 = kk_std_core_types__new_Nothing(_ctx); /*maybe<(t : std/time/timestamp/timestamp, tzdelta : std/time/timestamp/timespan) -> std/num/ddouble/ddouble>*/
    _match5820: ;
    kk_std_core_types__maybe _x5822;
    kk_std_core_types__optional _x5823 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/
    if (kk_std_core_types__is_Optional(_x5823)) {
      kk_box_t _box_x4832 = _x5823._cons.Optional.value;
      kk_std_core_types__maybe _from_mjd2000_381 = kk_std_core_types__maybe_unbox(_box_x4832, NULL);
      _x5822 = _from_mjd2000_381; /*maybe<(days : int, frac : std/num/ddouble/ddouble) -> std/time/timestamp/timestamp>*/
      goto _match5824;
    }
    _x5822 = kk_std_core_types__new_Nothing(_ctx); /*maybe<(days : int, frac : std/num/ddouble/ddouble) -> std/time/timestamp/timestamp>*/
    _match5824: ;
    kk_std_time_instant_ts_gps = kk_std_time_instant__new_Timescale(kk_reuse_null, _x5797, _x5799, kk_std_time_instant_new_ts_gps_fun5803(_offset_990, _ctx), kk_std_time_instant_new_ts_gps_fun5811(_offset_990, _ctx), _x5814, _x5818, _x5822, _ctx); /*std/time/instant/timescale*/
  }
  {
    kk_std_core_types__optional offset_4704;
    kk_std_time_duration__duration _b_4979_4978;
    kk_std_num_ddouble__ddouble _x6118 = kk_std_num_ddouble_ddouble(0x1.0178d4fdf3b64p5, _ctx); /*std/num/ddouble/ddouble*/
    _b_4979_4978 = kk_std_time_duration__new_Duration(_x6118, _ctx); /*std/time/duration/duration*/
    offset_4704 = kk_std_core_types__new_Optional(kk_std_time_duration__duration_box(_b_4979_4978, _ctx), _ctx); /*optional<std/time/duration/duration>*/
    kk_std_time_duration__duration _offset_990;
    if (kk_std_core_types__is_Optional(offset_4704)) {
      kk_box_t _box_x4980 = offset_4704._cons.Optional.value;
      kk_std_time_duration__duration _offset_991 = kk_std_time_duration__duration_unbox(_box_x4980, NULL);
      _offset_990 = _offset_991; /*std/time/duration/duration*/
      goto _match6119;
    }
    _offset_990 = kk_std_time_duration_duration_1(kk_integer_from_small(0), kk_std_core_types__new_None(_ctx), _ctx); /*std/time/duration/duration*/
    _match6119: ;
    kk_std_core_types__optional unit_4710;
    kk_box_t _x6121;
    kk_string_t _x6122;
    kk_define_string_literal(, _s6123, 3, "TAI")
    _x6122 = kk_string_dup(_s6123); /*string*/
    _x6121 = kk_string_box(_x6122); /*35*/
    unit_4710 = kk_std_core_types__new_Optional(_x6121, _ctx); /*optional<string>*/
    kk_string_t _x6124;
    kk_define_string_literal(, _s6125, 2, "TT")
    _x6124 = kk_string_dup(_s6125); /*string*/
    kk_string_t _x6126;
    if (kk_std_core_types__is_Optional(unit_4710)) {
      kk_box_t _box_x4983 = unit_4710._cons.Optional.value;
      kk_string_t _unit_366 = kk_string_unbox(_box_x4983);
      _x6126 = _unit_366; /*string*/
      goto _match6127;
    }
    kk_define_string_literal(, _s6129, 2, "TT")
    _x6126 = kk_string_dup(_s6129); /*string*/
    _match6127: ;
    kk_std_core_types__maybe _x6141;
    kk_std_core_types__optional _x6142 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/
    if (kk_std_core_types__is_Optional(_x6142)) {
      kk_box_t _box_x4985 = _x6142._cons.Optional.value;
      kk_std_core_types__maybe _seconds_in_day_371 = kk_std_core_types__maybe_unbox(_box_x4985, NULL);
      _x6141 = _seconds_in_day_371; /*maybe<(std/time/timestamp/timestamp) -> std/time/timestamp/timespan>*/
      goto _match6143;
    }
    _x6141 = kk_std_core_types__new_Nothing(_ctx); /*maybe<(std/time/timestamp/timestamp) -> std/time/timestamp/timespan>*/
    _match6143: ;
    kk_std_core_types__maybe _x6145;
    kk_std_core_types__optional _x6146 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/
    if (kk_std_core_types__is_Optional(_x6146)) {
      kk_box_t _box_x4986 = _x6146._cons.Optional.value;
      kk_std_core_types__maybe _to_mjd2000_376 = kk_std_core_types__maybe_unbox(_box_x4986, NULL);
      _x6145 = _to_mjd2000_376; /*maybe<(t : std/time/timestamp/timestamp, tzdelta : std/time/timestamp/timespan) -> std/num/ddouble/ddouble>*/
      goto _match6147;
    }
    _x6145 = kk_std_core_types__new_Nothing(_ctx); /*maybe<(t : std/time/timestamp/timestamp, tzdelta : std/time/timestamp/timespan) -> std/num/ddouble/ddouble>*/
    _match6147: ;
    kk_std_core_types__maybe _x6149;
    kk_std_core_types__optional _x6150 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/
    if (kk_std_core_types__is_Optional(_x6150)) {
      kk_box_t _box_x4987 = _x6150._cons.Optional.value;
      kk_std_core_types__maybe _from_mjd2000_381 = kk_std_core_types__maybe_unbox(_box_x4987, NULL);
      _x6149 = _from_mjd2000_381; /*maybe<(days : int, frac : std/num/ddouble/ddouble) -> std/time/timestamp/timestamp>*/
      goto _match6151;
    }
    _x6149 = kk_std_core_types__new_Nothing(_ctx); /*maybe<(days : int, frac : std/num/ddouble/ddouble) -> std/time/timestamp/timestamp>*/
    _match6151: ;
    kk_std_time_instant_ts_tt = kk_std_time_instant__new_Timescale(kk_reuse_null, _x6124, _x6126, kk_std_time_instant_new_ts_tt_fun6130(_offset_990, _ctx), kk_std_time_instant_new_ts_tt_fun6138(_offset_990, _ctx), _x6141, _x6145, _x6149, _ctx); /*std/time/instant/timescale*/
  }
  {
    kk_std_time_instant_tt2000 = kk_std_time_duration_duration_1(kk_integer_from_int(630720000, _ctx), kk_std_core_types__new_None(_ctx), _ctx); /*std/time/duration/duration*/
  }
}
