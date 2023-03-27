// Koka generated module: "std/time/instant", koka version: 2.1.3
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
    kk_string_dup(_name_180);
    kk_std_core_types__optional_drop(name0, _ctx);
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
    kk_string_dup(_unit_186);
    kk_std_core_types__optional_drop(unit0, _ctx);
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
    kk_std_core_types__maybe_dup(_mb_seconds_in_day_206);
    kk_std_core_types__optional_drop(mb_seconds_in_day0, _ctx);
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
    kk_std_core_types__maybe_dup(_mb_to_mjd2000_212);
    kk_std_core_types__optional_drop(mb_to_mjd20000, _ctx);
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
    kk_std_core_types__maybe_dup(_mb_from_mjd2000_218);
    kk_std_core_types__optional_drop(mb_from_mjd20000, _ctx);
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
    kk_std_core_types__optional_drop(since0, _ctx);
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
    kk_std_time_instant__timescale_dup(_ts_257);
    kk_std_core_types__optional_drop(ts0, _ctx);
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
  struct kk_std_time_instant_Instant* _con5397 = kk_std_time_instant__as_Instant(i);
  kk_std_time_timestamp__timestamp _pat00 = _con5397->since;
  kk_std_time_instant__timescale _x0 = _con5397->ts;
  struct kk_std_time_instant_Timescale* _con5398 = kk_std_time_instant__as_Timescale(_x0);
  kk_std_time_instant__timescale_dup(_x0);
  _match_5330 = _x0; /*std/time/instant/timescale*/
  struct kk_std_time_instant_Timescale* _con5399 = kk_std_time_instant__as_Timescale(_match_5330);
  kk_string_t _pat0 = _con5399->name;
  kk_string_t _pat1 = _con5399->unit;
  kk_function_t _pat2 = _con5399->from_tai;
  kk_function_t _pat3 = _con5399->to_tai;
  kk_std_core_types__maybe _x = _con5399->mb_seconds_in_day;
  kk_std_core_types__maybe _pat4 = _con5399->mb_to_mjd2000;
  kk_std_core_types__maybe _pat5 = _con5399->mb_from_mjd2000;
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
  kk_box_t _x5400;
  kk_function_t _x5405 = kk_function_unbox(_fun_unbox_x4776); /*(t : 4777) -> 4778*/
  kk_box_t _x5401;
  kk_std_time_timestamp__timestamp _x5402;
  struct kk_std_time_instant_Instant* _con5403 = kk_std_time_instant__as_Instant(i);
  kk_std_time_timestamp__timestamp _x1 = _con5403->since;
  kk_std_time_instant__timescale _pat21 = _con5403->ts;
  struct kk_std_time_instant_Timescale* _con5404 = kk_std_time_instant__as_Timescale(_pat21);
  kk_string_t _pat31 = _con5404->name;
  kk_string_t _pat41 = _con5404->unit;
  kk_function_t _pat51 = _con5404->from_tai;
  kk_function_t _pat61 = _con5404->to_tai;
  kk_std_core_types__maybe _pat70 = _con5404->mb_seconds_in_day;
  kk_std_core_types__maybe _pat80 = _con5404->mb_to_mjd2000;
  kk_std_core_types__maybe _pat90 = _con5404->mb_from_mjd2000;
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
  _x5402 = _x1; /*std/time/timestamp/timestamp*/
  _x5401 = kk_std_time_timestamp__timestamp_box(_x5402, _ctx); /*4777*/
  _x5400 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x5405, (_x5405, _x5401, _ctx)); /*4778*/
  return kk_std_num_ddouble__ddouble_unbox(_x5400, _ctx);
}
 
// Create a new time scale given `name`, two inverse function `from-tai` and `to-tai`,
// and an optional function that returns the seconds in the day of the instant.
// The time unit defaults to `name`.

kk_std_time_instant__timescale kk_std_time_instant_timescale_1(kk_string_t name0, kk_function_t from_tai0, kk_function_t to_tai0, kk_std_core_types__optional unit0, kk_std_core_types__optional seconds_in_day0, kk_std_core_types__optional to_mjd2000, kk_std_core_types__optional from_mjd2000, kk_context_t* _ctx) { /* (name : string, from-tai : (std/time/duration/duration) -> std/time/timestamp/timestamp, to-tai : (std/time/timestamp/timestamp) -> std/time/duration/duration, unit : optional<string>, seconds-in-day : optional<maybe<(std/time/timestamp/timestamp) -> std/time/timestamp/timespan>>, to-mjd2000 : optional<maybe<(t : std/time/timestamp/timestamp, tzdelta : std/time/timestamp/timespan) -> std/num/ddouble/ddouble>>, from-mjd2000 : optional<maybe<(days : int, frac : std/num/ddouble/ddouble) -> std/time/timestamp/timestamp>>) -> timescale */ 
  kk_string_t _x5417 = kk_string_dup(name0); /*string*/
  kk_string_t _x5418;
  if (kk_std_core_types__is_Optional(unit0)) {
    kk_box_t _box_x4784 = unit0._cons.Optional.value;
    kk_string_t _unit_366 = kk_string_unbox(_box_x4784);
    kk_string_dup(_unit_366);
    kk_std_core_types__optional_drop(unit0, _ctx);
    kk_string_drop(name0, _ctx);
    _x5418 = _unit_366; /*string*/
    goto _match5419;
  }
  _x5418 = name0; /*string*/
  _match5419: ;
  kk_std_core_types__maybe _x5421;
  if (kk_std_core_types__is_Optional(seconds_in_day0)) {
    kk_box_t _box_x4785 = seconds_in_day0._cons.Optional.value;
    kk_std_core_types__maybe _seconds_in_day_371 = kk_std_core_types__maybe_unbox(_box_x4785, NULL);
    kk_std_core_types__maybe_dup(_seconds_in_day_371);
    kk_std_core_types__optional_drop(seconds_in_day0, _ctx);
    _x5421 = _seconds_in_day_371; /*maybe<(std/time/timestamp/timestamp) -> std/time/timestamp/timespan>*/
    goto _match5422;
  }
  _x5421 = kk_std_core_types__new_Nothing(_ctx); /*maybe<(std/time/timestamp/timestamp) -> std/time/timestamp/timespan>*/
  _match5422: ;
  kk_std_core_types__maybe _x5424;
  if (kk_std_core_types__is_Optional(to_mjd2000)) {
    kk_box_t _box_x4786 = to_mjd2000._cons.Optional.value;
    kk_std_core_types__maybe _to_mjd2000_376 = kk_std_core_types__maybe_unbox(_box_x4786, NULL);
    kk_std_core_types__maybe_dup(_to_mjd2000_376);
    kk_std_core_types__optional_drop(to_mjd2000, _ctx);
    _x5424 = _to_mjd2000_376; /*maybe<(t : std/time/timestamp/timestamp, tzdelta : std/time/timestamp/timespan) -> std/num/ddouble/ddouble>*/
    goto _match5425;
  }
  _x5424 = kk_std_core_types__new_Nothing(_ctx); /*maybe<(t : std/time/timestamp/timestamp, tzdelta : std/time/timestamp/timespan) -> std/num/ddouble/ddouble>*/
  _match5425: ;
  kk_std_core_types__maybe _x5427;
  if (kk_std_core_types__is_Optional(from_mjd2000)) {
    kk_box_t _box_x4787 = from_mjd2000._cons.Optional.value;
    kk_std_core_types__maybe _from_mjd2000_381 = kk_std_core_types__maybe_unbox(_box_x4787, NULL);
    kk_std_core_types__maybe_dup(_from_mjd2000_381);
    kk_std_core_types__optional_drop(from_mjd2000, _ctx);
    _x5427 = _from_mjd2000_381; /*maybe<(days : int, frac : std/num/ddouble/ddouble) -> std/time/timestamp/timestamp>*/
    goto _match5428;
  }
  _x5427 = kk_std_core_types__new_Nothing(_ctx); /*maybe<(days : int, frac : std/num/ddouble/ddouble) -> std/time/timestamp/timestamp>*/
  _match5428: ;
  return kk_std_time_instant__new_Timescale(kk_reuse_null, _x5417, _x5418, from_tai0, to_tai0, _x5421, _x5424, _x5427, _ctx);
}
 
// Create a new time scale based on SI seconds (as measured on the Earth's geoid) with a given
//  `name`, a fixed `offset` (=`duration0`) from TAI (e.g. GPS = TAI - 19), and
// a `epoch-y2k` (= `timestamp0`) which is the timestamp of the 2000-01-01 date in that timescale
// e.g. for a timescale `ts`:
// `epoch-y2k = instant(2000,1,1,cal=iso-calendar(ts)).since-in(ts)`


// lift anonymous function
struct kk_std_time_instant_tai_timescale_fun5439__t {
  struct kk_function_s _base;
  kk_std_time_duration__duration _offset_990;
};
static kk_std_time_timestamp__timestamp kk_std_time_instant_tai_timescale_fun5439(kk_function_t _fself, kk_std_time_duration__duration tai, kk_context_t* _ctx);
static kk_function_t kk_std_time_instant_new_tai_timescale_fun5439(kk_std_time_duration__duration _offset_990, kk_context_t* _ctx) {
  struct kk_std_time_instant_tai_timescale_fun5439__t* _self = kk_function_alloc_as(struct kk_std_time_instant_tai_timescale_fun5439__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_time_instant_tai_timescale_fun5439, kk_context());
  _self->_offset_990 = _offset_990;
  return &_self->_base;
}

static kk_std_time_timestamp__timestamp kk_std_time_instant_tai_timescale_fun5439(kk_function_t _fself, kk_std_time_duration__duration tai, kk_context_t* _ctx) {
  struct kk_std_time_instant_tai_timescale_fun5439__t* _self = kk_function_as(struct kk_std_time_instant_tai_timescale_fun5439__t*, _fself);
  kk_std_time_duration__duration _offset_990 = _self->_offset_990; /* std/time/duration/duration */
  kk_drop_match(_self, {kk_std_time_duration__duration_dup(_offset_990);}, {}, _ctx)
  kk_std_num_ddouble__ddouble t_4479;
  kk_std_num_ddouble__ddouble _x5440;
  kk_std_num_ddouble__ddouble _x0 = tai.secs;
  _x5440 = _x0; /*std/time/timestamp/timespan*/
  kk_std_num_ddouble__ddouble _x5441;
  kk_std_num_ddouble__ddouble _x = _offset_990.secs;
  _x5441 = _x; /*std/time/timestamp/timespan*/
  t_4479 = kk_std_num_ddouble__lp__plus__rp_(_x5440, _x5441, _ctx); /*std/time/timestamp/timespan*/
  int32_t _x5442;
  kk_integer_t _x5443;
  kk_std_core_types__optional _match_5328 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
  if (kk_std_core_types__is_Optional(_match_5328)) {
    kk_box_t _box_x4792 = _match_5328._cons.Optional.value;
    kk_integer_t _leap_492 = kk_integer_unbox(_box_x4792);
    kk_integer_dup(_leap_492);
    kk_std_core_types__optional_drop(_match_5328, _ctx);
    _x5443 = _leap_492; /*int*/
    goto _match5444;
  }
  _x5443 = kk_integer_from_small(0); /*int*/
  _match5444: ;
  _x5442 = kk_std_core_int32(_x5443, _ctx); /*int32*/
  return kk_std_time_timestamp__new_Timestamp(t_4479, _x5442, _ctx);
}


// lift anonymous function
struct kk_std_time_instant_tai_timescale_fun5446__t {
  struct kk_function_s _base;
  kk_std_time_duration__duration _offset_990;
};
static kk_std_time_duration__duration kk_std_time_instant_tai_timescale_fun5446(kk_function_t _fself, kk_std_time_timestamp__timestamp t0, kk_context_t* _ctx);
static kk_function_t kk_std_time_instant_new_tai_timescale_fun5446(kk_std_time_duration__duration _offset_990, kk_context_t* _ctx) {
  struct kk_std_time_instant_tai_timescale_fun5446__t* _self = kk_function_alloc_as(struct kk_std_time_instant_tai_timescale_fun5446__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_time_instant_tai_timescale_fun5446, kk_context());
  _self->_offset_990 = _offset_990;
  return &_self->_base;
}

static kk_std_time_duration__duration kk_std_time_instant_tai_timescale_fun5446(kk_function_t _fself, kk_std_time_timestamp__timestamp t0, kk_context_t* _ctx) {
  struct kk_std_time_instant_tai_timescale_fun5446__t* _self = kk_function_as(struct kk_std_time_instant_tai_timescale_fun5446__t*, _fself);
  kk_std_time_duration__duration _offset_990 = _self->_offset_990; /* std/time/duration/duration */
  kk_drop_match(_self, {kk_std_time_duration__duration_dup(_offset_990);}, {}, _ctx)
  kk_std_time_timestamp__timestamp t1_4482;
  kk_std_num_ddouble__ddouble _x5447;
  kk_std_num_ddouble__ddouble _x1 = _offset_990.secs;
  _x5447 = _x1; /*std/time/timestamp/timespan*/
  t1_4482 = kk_std_time_timestamp__lp__dash__rp_(t0, _x5447, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_num_ddouble__ddouble _x5448 = kk_std_time_timestamp_unsafe_timespan_withleap(t1_4482, _ctx); /*std/time/timestamp/timespan*/
  return kk_std_time_duration__new_Duration(_x5448, _ctx);
}

kk_std_time_instant__timescale kk_std_time_instant_tai_timescale(kk_string_t name0, kk_std_core_types__optional offset, kk_context_t* _ctx) { /* (name : string, offset : optional<std/time/duration/duration>) -> timescale */ 
  kk_std_time_duration__duration _offset_990;
  if (kk_std_core_types__is_Optional(offset)) {
    kk_box_t _box_x4788 = offset._cons.Optional.value;
    kk_std_time_duration__duration _offset_991 = kk_std_time_duration__duration_unbox(_box_x4788, NULL);
    kk_std_core_types__optional_drop(offset, _ctx);
    _offset_990 = _offset_991; /*std/time/duration/duration*/
    goto _match5430;
  }
  _offset_990 = kk_std_time_duration_duration_1(kk_integer_from_small(0), kk_std_core_types__new_None(_ctx), _ctx); /*std/time/duration/duration*/
  _match5430: ;
  kk_std_core_types__optional unit_4475;
  kk_box_t _x5432;
  kk_string_t _x5433;
  kk_define_string_literal(, _s5434, 3, "TAI")
  _x5433 = kk_string_dup(_s5434); /*string*/
  _x5432 = kk_string_box(_x5433); /*35*/
  unit_4475 = kk_std_core_types__new_Optional(_x5432, _ctx); /*optional<string>*/
  kk_string_t _x5435 = kk_string_dup(name0); /*string*/
  kk_string_t _x5436;
  if (kk_std_core_types__is_Optional(unit_4475)) {
    kk_box_t _box_x4791 = unit_4475._cons.Optional.value;
    kk_string_t _unit_366 = kk_string_unbox(_box_x4791);
    kk_string_dup(_unit_366);
    kk_std_core_types__optional_drop(unit_4475, _ctx);
    kk_string_drop(name0, _ctx);
    _x5436 = _unit_366; /*string*/
    goto _match5437;
  }
  _x5436 = name0; /*string*/
  _match5437: ;
  kk_std_core_types__maybe _x5449;
  kk_std_core_types__optional _match_5327 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
  if (kk_std_core_types__is_Optional(_match_5327)) {
    kk_box_t _box_x4793 = _match_5327._cons.Optional.value;
    kk_std_core_types__maybe _seconds_in_day_371 = kk_std_core_types__maybe_unbox(_box_x4793, NULL);
    kk_std_core_types__maybe_dup(_seconds_in_day_371);
    kk_std_core_types__optional_drop(_match_5327, _ctx);
    _x5449 = _seconds_in_day_371; /*maybe<(std/time/timestamp/timestamp) -> std/time/timestamp/timespan>*/
    goto _match5450;
  }
  _x5449 = kk_std_core_types__new_Nothing(_ctx); /*maybe<(std/time/timestamp/timestamp) -> std/time/timestamp/timespan>*/
  _match5450: ;
  kk_std_core_types__maybe _x5452;
  kk_std_core_types__optional _match_5326 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
  if (kk_std_core_types__is_Optional(_match_5326)) {
    kk_box_t _box_x4794 = _match_5326._cons.Optional.value;
    kk_std_core_types__maybe _to_mjd2000_376 = kk_std_core_types__maybe_unbox(_box_x4794, NULL);
    kk_std_core_types__maybe_dup(_to_mjd2000_376);
    kk_std_core_types__optional_drop(_match_5326, _ctx);
    _x5452 = _to_mjd2000_376; /*maybe<(t : std/time/timestamp/timestamp, tzdelta : std/time/timestamp/timespan) -> std/num/ddouble/ddouble>*/
    goto _match5453;
  }
  _x5452 = kk_std_core_types__new_Nothing(_ctx); /*maybe<(t : std/time/timestamp/timestamp, tzdelta : std/time/timestamp/timespan) -> std/num/ddouble/ddouble>*/
  _match5453: ;
  kk_std_core_types__maybe _x5455;
  kk_std_core_types__optional _match_5325 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
  if (kk_std_core_types__is_Optional(_match_5325)) {
    kk_box_t _box_x4795 = _match_5325._cons.Optional.value;
    kk_std_core_types__maybe _from_mjd2000_381 = kk_std_core_types__maybe_unbox(_box_x4795, NULL);
    kk_std_core_types__maybe_dup(_from_mjd2000_381);
    kk_std_core_types__optional_drop(_match_5325, _ctx);
    _x5455 = _from_mjd2000_381; /*maybe<(days : int, frac : std/num/ddouble/ddouble) -> std/time/timestamp/timestamp>*/
    goto _match5456;
  }
  _x5455 = kk_std_core_types__new_Nothing(_ctx); /*maybe<(days : int, frac : std/num/ddouble/ddouble) -> std/time/timestamp/timestamp>*/
  _match5456: ;
  return kk_std_time_instant__new_Timescale(kk_reuse_null, _x5435, _x5436, kk_std_time_instant_new_tai_timescale_fun5439(_offset_990, _ctx), kk_std_time_instant_new_tai_timescale_fun5446(_offset_990, _ctx), _x5449, _x5452, _x5455, _ctx);
}
 
// The [TAI](https://en.wikipedia.org/wiki/International_Atomic_Time) (International atomic time)
// time scale is based on SI seconds measured on the Earth's geoid, with a 2000-01-01 TAI `epoch`.


// lift anonymous function
struct kk_std_time_instant_ts_tai_fun5469__t {
  struct kk_function_s _base;
  kk_std_time_duration__duration _offset_990;
};
static kk_std_time_timestamp__timestamp kk_std_time_instant_ts_tai_fun5469(kk_function_t _fself, kk_std_time_duration__duration tai, kk_context_t* _ctx);
static kk_function_t kk_std_time_instant_new_ts_tai_fun5469(kk_std_time_duration__duration _offset_990, kk_context_t* _ctx) {
  struct kk_std_time_instant_ts_tai_fun5469__t* _self = kk_function_alloc_as(struct kk_std_time_instant_ts_tai_fun5469__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_time_instant_ts_tai_fun5469, kk_context());
  _self->_offset_990 = _offset_990;
  return &_self->_base;
}

static kk_std_time_timestamp__timestamp kk_std_time_instant_ts_tai_fun5469(kk_function_t _fself, kk_std_time_duration__duration tai, kk_context_t* _ctx) {
  struct kk_std_time_instant_ts_tai_fun5469__t* _self = kk_function_as(struct kk_std_time_instant_ts_tai_fun5469__t*, _fself);
  kk_std_time_duration__duration _offset_990 = _self->_offset_990; /* std/time/duration/duration */
  kk_drop_match(_self, {kk_std_time_duration__duration_dup(_offset_990);}, {}, _ctx)
  kk_std_num_ddouble__ddouble t_4493;
  kk_std_num_ddouble__ddouble _x5470;
  kk_std_num_ddouble__ddouble _x0 = tai.secs;
  _x5470 = _x0; /*std/time/timestamp/timespan*/
  kk_std_num_ddouble__ddouble _x5471;
  kk_std_num_ddouble__ddouble _x = _offset_990.secs;
  _x5471 = _x; /*std/time/timestamp/timespan*/
  t_4493 = kk_std_num_ddouble__lp__plus__rp_(_x5470, _x5471, _ctx); /*std/time/timestamp/timespan*/
  int32_t _x5472;
  kk_integer_t _x5473;
  kk_std_core_types__optional _match_5323 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
  if (kk_std_core_types__is_Optional(_match_5323)) {
    kk_box_t _box_x4800 = _match_5323._cons.Optional.value;
    kk_integer_t _leap_492 = kk_integer_unbox(_box_x4800);
    kk_integer_dup(_leap_492);
    kk_std_core_types__optional_drop(_match_5323, _ctx);
    _x5473 = _leap_492; /*int*/
    goto _match5474;
  }
  _x5473 = kk_integer_from_small(0); /*int*/
  _match5474: ;
  _x5472 = kk_std_core_int32(_x5473, _ctx); /*int32*/
  return kk_std_time_timestamp__new_Timestamp(t_4493, _x5472, _ctx);
}


// lift anonymous function
struct kk_std_time_instant_ts_tai_fun5476__t {
  struct kk_function_s _base;
  kk_std_time_duration__duration _offset_990;
};
static kk_std_time_duration__duration kk_std_time_instant_ts_tai_fun5476(kk_function_t _fself, kk_std_time_timestamp__timestamp t0, kk_context_t* _ctx);
static kk_function_t kk_std_time_instant_new_ts_tai_fun5476(kk_std_time_duration__duration _offset_990, kk_context_t* _ctx) {
  struct kk_std_time_instant_ts_tai_fun5476__t* _self = kk_function_alloc_as(struct kk_std_time_instant_ts_tai_fun5476__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_time_instant_ts_tai_fun5476, kk_context());
  _self->_offset_990 = _offset_990;
  return &_self->_base;
}

static kk_std_time_duration__duration kk_std_time_instant_ts_tai_fun5476(kk_function_t _fself, kk_std_time_timestamp__timestamp t0, kk_context_t* _ctx) {
  struct kk_std_time_instant_ts_tai_fun5476__t* _self = kk_function_as(struct kk_std_time_instant_ts_tai_fun5476__t*, _fself);
  kk_std_time_duration__duration _offset_990 = _self->_offset_990; /* std/time/duration/duration */
  kk_drop_match(_self, {kk_std_time_duration__duration_dup(_offset_990);}, {}, _ctx)
  kk_std_time_timestamp__timestamp t1_4496;
  kk_std_num_ddouble__ddouble _x5477;
  kk_std_num_ddouble__ddouble _x1 = _offset_990.secs;
  _x5477 = _x1; /*std/time/timestamp/timespan*/
  t1_4496 = kk_std_time_timestamp__lp__dash__rp_(t0, _x5477, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_num_ddouble__ddouble _x5478 = kk_std_time_timestamp_unsafe_timespan_withleap(t1_4496, _ctx); /*std/time/timestamp/timespan*/
  return kk_std_time_duration__new_Duration(_x5478, _ctx);
}

kk_std_time_instant__timescale kk_std_time_instant_ts_tai;
 
// Add a time span to an instant in time.
// This is only safe if the time unit of the timespan is the
// same as that of the instant.

kk_std_time_instant__instant kk_std_time_instant_unsafe_add(kk_std_time_instant__instant i, kk_std_num_ddouble__ddouble tspan, kk_context_t* _ctx) { /* (i : instant, tspan : std/time/timestamp/timespan) -> instant */ 
  kk_std_time_timestamp__timestamp _x5488;
  kk_std_num_ddouble__ddouble _x5489;
  kk_std_num_ddouble__ddouble _x5490;
  kk_std_time_timestamp__timestamp _match_5319;
  struct kk_std_time_instant_Instant* _con5491 = kk_std_time_instant__as_Instant(i);
  kk_std_time_timestamp__timestamp _x1 = _con5491->since;
  kk_std_time_instant__timescale _pat21 = _con5491->ts;
  struct kk_std_time_instant_Timescale* _con5492 = kk_std_time_instant__as_Timescale(_pat21);
  _match_5319 = _x1; /*std/time/timestamp/timestamp*/
  kk_std_num_ddouble__ddouble _x = _match_5319.since;
  _x5490 = _x; /*std/time/timestamp/timespan*/
  _x5489 = kk_std_num_ddouble__lp__plus__rp_(_x5490, tspan, _ctx); /*std/num/ddouble/ddouble*/
  int32_t _x5493;
  kk_std_time_timestamp__timestamp _match_5318;
  struct kk_std_time_instant_Instant* _con5494 = kk_std_time_instant__as_Instant(i);
  kk_std_time_timestamp__timestamp _x10 = _con5494->since;
  kk_std_time_instant__timescale _pat210 = _con5494->ts;
  struct kk_std_time_instant_Timescale* _con5495 = kk_std_time_instant__as_Timescale(_pat210);
  _match_5318 = _x10; /*std/time/timestamp/timestamp*/
  kk_std_num_ddouble__ddouble _pat00 = _match_5318.since;
  int32_t _x0 = _match_5318.leap32;
  _x5493 = _x0; /*int32*/
  _x5488 = kk_std_time_timestamp__new_Timestamp(_x5489, _x5493, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_time_instant__timescale _x5496;
  struct kk_std_time_instant_Instant* _con5497 = kk_std_time_instant__as_Instant(i);
  kk_std_time_timestamp__timestamp _pat02 = _con5497->since;
  kk_std_time_instant__timescale _x2 = _con5497->ts;
  struct kk_std_time_instant_Timescale* _con5498 = kk_std_time_instant__as_Timescale(_x2);
  if (kk_std_time_instant__instant_is_unique(i)) {
    kk_std_time_instant__instant_free(i);
  }
  else {
    kk_std_time_instant__timescale_dup(_x2);
    kk_std_time_instant__instant_decref(i, _ctx);
  }
  _x5496 = _x2; /*std/time/instant/timescale*/
  return kk_std_time_instant__new_Instant(kk_reuse_null, _x5488, _x5496, _ctx);
}
 
// Convert a timespan between time scales

kk_std_time_timestamp__timestamp kk_std_time_instant_convert(kk_std_time_timestamp__timestamp t, kk_std_time_instant__timescale from, kk_std_time_instant__timescale to, kk_context_t* _ctx) { /* (t : std/time/timestamp/timestamp, from : timescale, to : timescale) -> std/time/timestamp/timestamp */ 
  bool _match_5315;
  kk_string_t _x5499;
  struct kk_std_time_instant_Timescale* _con5500 = kk_std_time_instant__as_Timescale(from);
  kk_string_t _x = _con5500->name;
  kk_string_dup(_x);
  _x5499 = _x; /*string*/
  kk_string_t _x5501;
  struct kk_std_time_instant_Timescale* _con5502 = kk_std_time_instant__as_Timescale(to);
  kk_string_t _x0 = _con5502->name;
  kk_string_dup(_x0);
  _x5501 = _x0; /*string*/
  _match_5315 = kk_string_is_eq(_x5499,_x5501,kk_context()); /*bool*/
  if (_match_5315) {
    kk_std_time_instant__timescale_dropn(from, ((int32_t)10), _ctx);
    kk_std_time_instant__timescale_dropn(to, ((int32_t)10), _ctx);
    return t;
  }
  bool _match_5316;
  bool _match_5317;
  kk_string_t _x5503;
  struct kk_std_time_instant_Timescale* _con5504 = kk_std_time_instant__as_Timescale(from);
  kk_string_t _x1 = _con5504->unit;
  kk_string_dup(_x1);
  _x5503 = _x1; /*string*/
  kk_string_t _x5505;
  struct kk_std_time_instant_Timescale* _con5506 = kk_std_time_instant__as_Timescale(to);
  kk_string_t _x2 = _con5506->unit;
  kk_string_dup(_x2);
  _x5505 = _x2; /*string*/
  _match_5317 = kk_string_is_eq(_x5503,_x5505,kk_context()); /*bool*/
  if (_match_5317) {
    kk_string_t _x5507;
    struct kk_std_time_instant_Timescale* _con5508 = kk_std_time_instant__as_Timescale(from);
    kk_string_t _x3 = _con5508->unit;
    kk_string_dup(_x3);
    _x5507 = _x3; /*string*/
    kk_string_t _x5509;
    kk_define_string_literal(, _s5510, 3, "UTC")
    _x5509 = kk_string_dup(_s5510); /*string*/
    _match_5316 = kk_string_is_eq(_x5507,_x5509,kk_context()); /*bool*/
  }
  else {
    _match_5316 = false; /*bool*/
  }
  if (_match_5316) {
    kk_std_time_instant__timescale_dropn(from, ((int32_t)10), _ctx);
    kk_std_time_instant__timescale_dropn(to, ((int32_t)10), _ctx);
    return t;
  }
  kk_function_t _x5513 = kk_std_time_instant_from_tai(to, _ctx); /*(std/time/duration/duration) -> std/time/timestamp/timestamp*/
  kk_std_time_duration__duration _x5511;
  kk_function_t _x5512 = kk_std_time_instant_to_tai(from, _ctx); /*(std/time/timestamp/timestamp) -> std/time/duration/duration*/
  _x5511 = kk_function_call(kk_std_time_duration__duration, (kk_function_t, kk_std_time_timestamp__timestamp, kk_context_t*), _x5512, (_x5512, t, _ctx)); /*std/time/duration/duration*/
  return kk_function_call(kk_std_time_timestamp__timestamp, (kk_function_t, kk_std_time_duration__duration, kk_context_t*), _x5513, (_x5513, _x5511, _ctx));
}
 
// Return a `:timestamp` for instant `i` in a certain time scale `tscale`.

kk_std_time_timestamp__timestamp kk_std_time_instant_timestamp_in(kk_std_time_instant__instant i, kk_std_time_instant__timescale tscale, kk_context_t* _ctx) { /* (i : instant, tscale : timescale) -> std/time/timestamp/timestamp */ 
  bool _match_5309;
  kk_string_t _x5514;
  kk_std_time_instant__timescale _match_5314;
  struct kk_std_time_instant_Instant* _con5515 = kk_std_time_instant__as_Instant(i);
  kk_std_time_timestamp__timestamp _pat06 = _con5515->since;
  kk_std_time_instant__timescale _x5 = _con5515->ts;
  struct kk_std_time_instant_Timescale* _con5516 = kk_std_time_instant__as_Timescale(_x5);
  kk_std_time_instant__timescale_dup(_x5);
  _match_5314 = _x5; /*std/time/instant/timescale*/
  struct kk_std_time_instant_Timescale* _con5517 = kk_std_time_instant__as_Timescale(_match_5314);
  kk_string_t _x = _con5517->name;
  kk_string_t _pat0 = _con5517->unit;
  kk_function_t _pat1 = _con5517->from_tai;
  kk_function_t _pat2 = _con5517->to_tai;
  kk_std_core_types__maybe _pat3 = _con5517->mb_seconds_in_day;
  kk_std_core_types__maybe _pat4 = _con5517->mb_to_mjd2000;
  kk_std_core_types__maybe _pat5 = _con5517->mb_from_mjd2000;
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
  _x5514 = _x; /*string*/
  kk_string_t _x5518;
  struct kk_std_time_instant_Timescale* _con5519 = kk_std_time_instant__as_Timescale(tscale);
  kk_string_t _x0 = _con5519->name;
  kk_string_dup(_x0);
  _x5518 = _x0; /*string*/
  _match_5309 = kk_string_is_eq(_x5514,_x5518,kk_context()); /*bool*/
  if (_match_5309) {
    kk_std_time_instant__timescale_dropn(tscale, ((int32_t)10), _ctx);
    struct kk_std_time_instant_Instant* _con5520 = kk_std_time_instant__as_Instant(i);
    kk_std_time_timestamp__timestamp _x4 = _con5520->since;
    kk_std_time_instant__timescale _pat25 = _con5520->ts;
    struct kk_std_time_instant_Timescale* _con5521 = kk_std_time_instant__as_Timescale(_pat25);
    kk_string_t _pat35 = _con5521->name;
    kk_string_t _pat45 = _con5521->unit;
    kk_function_t _pat54 = _con5521->from_tai;
    kk_function_t _pat60 = _con5521->to_tai;
    kk_std_core_types__maybe _pat70 = _con5521->mb_seconds_in_day;
    kk_std_core_types__maybe _pat80 = _con5521->mb_to_mjd2000;
    kk_std_core_types__maybe _pat90 = _con5521->mb_from_mjd2000;
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
  kk_string_t _x5522;
  kk_std_time_instant__timescale _match_5313;
  struct kk_std_time_instant_Instant* _con5523 = kk_std_time_instant__as_Instant(i);
  kk_std_time_timestamp__timestamp _pat060 = _con5523->since;
  kk_std_time_instant__timescale _x50 = _con5523->ts;
  struct kk_std_time_instant_Timescale* _con5524 = kk_std_time_instant__as_Timescale(_x50);
  kk_std_time_instant__timescale_dup(_x50);
  _match_5313 = _x50; /*std/time/instant/timescale*/
  struct kk_std_time_instant_Timescale* _con5525 = kk_std_time_instant__as_Timescale(_match_5313);
  kk_string_t _pat02 = _con5525->name;
  kk_string_t _x1 = _con5525->unit;
  kk_function_t _pat11 = _con5525->from_tai;
  kk_function_t _pat21 = _con5525->to_tai;
  kk_std_core_types__maybe _pat31 = _con5525->mb_seconds_in_day;
  kk_std_core_types__maybe _pat41 = _con5525->mb_to_mjd2000;
  kk_std_core_types__maybe _pat51 = _con5525->mb_from_mjd2000;
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
  _x5522 = _x1; /*string*/
  kk_string_t _x5526;
  struct kk_std_time_instant_Timescale* _con5527 = kk_std_time_instant__as_Timescale(tscale);
  kk_string_t _x2 = _con5527->unit;
  kk_string_dup(_x2);
  _x5526 = _x2; /*string*/
  _match_5311 = kk_string_is_eq(_x5522,_x5526,kk_context()); /*bool*/
  if (_match_5311) {
    kk_string_t _x5528;
    kk_std_time_instant__timescale _match_5312;
    struct kk_std_time_instant_Instant* _con5529 = kk_std_time_instant__as_Instant(i);
    kk_std_time_timestamp__timestamp _pat061 = _con5529->since;
    kk_std_time_instant__timescale _x51 = _con5529->ts;
    struct kk_std_time_instant_Timescale* _con5530 = kk_std_time_instant__as_Timescale(_x51);
    kk_std_time_instant__timescale_dup(_x51);
    _match_5312 = _x51; /*std/time/instant/timescale*/
    struct kk_std_time_instant_Timescale* _con5531 = kk_std_time_instant__as_Timescale(_match_5312);
    kk_string_t _pat04 = _con5531->name;
    kk_string_t _x3 = _con5531->unit;
    kk_function_t _pat15 = _con5531->from_tai;
    kk_function_t _pat23 = _con5531->to_tai;
    kk_std_core_types__maybe _pat33 = _con5531->mb_seconds_in_day;
    kk_std_core_types__maybe _pat43 = _con5531->mb_to_mjd2000;
    kk_std_core_types__maybe _pat53 = _con5531->mb_from_mjd2000;
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
    _x5528 = _x3; /*string*/
    kk_string_t _x5532;
    kk_define_string_literal(, _s5533, 3, "UTC")
    _x5532 = kk_string_dup(_s5533); /*string*/
    _match_5310 = kk_string_is_eq(_x5528,_x5532,kk_context()); /*bool*/
  }
  else {
    _match_5310 = false; /*bool*/
  }
  if (_match_5310) {
    kk_std_time_instant__timescale_dropn(tscale, ((int32_t)10), _ctx);
    struct kk_std_time_instant_Instant* _con5534 = kk_std_time_instant__as_Instant(i);
    kk_std_time_timestamp__timestamp _x40 = _con5534->since;
    kk_std_time_instant__timescale _pat250 = _con5534->ts;
    struct kk_std_time_instant_Timescale* _con5535 = kk_std_time_instant__as_Timescale(_pat250);
    kk_string_t _pat350 = _con5535->name;
    kk_string_t _pat450 = _con5535->unit;
    kk_function_t _pat540 = _con5535->from_tai;
    kk_function_t _pat600 = _con5535->to_tai;
    kk_std_core_types__maybe _pat700 = _con5535->mb_seconds_in_day;
    kk_std_core_types__maybe _pat800 = _con5535->mb_to_mjd2000;
    kk_std_core_types__maybe _pat900 = _con5535->mb_from_mjd2000;
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
  kk_function_t _x5544 = kk_std_time_instant_from_tai(tscale, _ctx); /*(std/time/duration/duration) -> std/time/timestamp/timestamp*/
  kk_std_time_duration__duration _x5536;
  kk_function_t _x5540;
  kk_std_time_instant__timescale _x5541;
  struct kk_std_time_instant_Instant* _con5542 = kk_std_time_instant__as_Instant(i);
  kk_std_time_timestamp__timestamp _pat062 = _con5542->since;
  kk_std_time_instant__timescale _x52 = _con5542->ts;
  struct kk_std_time_instant_Timescale* _con5543 = kk_std_time_instant__as_Timescale(_x52);
  kk_std_time_instant__timescale_dup(_x52);
  _x5541 = _x52; /*std/time/instant/timescale*/
  _x5540 = kk_std_time_instant_to_tai(_x5541, _ctx); /*(std/time/timestamp/timestamp) -> std/time/duration/duration*/
  kk_std_time_timestamp__timestamp _x5537;
  struct kk_std_time_instant_Instant* _con5538 = kk_std_time_instant__as_Instant(i);
  kk_std_time_timestamp__timestamp _x41 = _con5538->since;
  kk_std_time_instant__timescale _pat251 = _con5538->ts;
  struct kk_std_time_instant_Timescale* _con5539 = kk_std_time_instant__as_Timescale(_pat251);
  kk_string_t _pat351 = _con5539->name;
  kk_string_t _pat451 = _con5539->unit;
  kk_function_t _pat541 = _con5539->from_tai;
  kk_function_t _pat601 = _con5539->to_tai;
  kk_std_core_types__maybe _pat701 = _con5539->mb_seconds_in_day;
  kk_std_core_types__maybe _pat801 = _con5539->mb_to_mjd2000;
  kk_std_core_types__maybe _pat901 = _con5539->mb_from_mjd2000;
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
  _x5537 = _x41; /*std/time/timestamp/timestamp*/
  _x5536 = kk_function_call(kk_std_time_duration__duration, (kk_function_t, kk_std_time_timestamp__timestamp, kk_context_t*), _x5540, (_x5540, _x5537, _ctx)); /*std/time/duration/duration*/
  return kk_function_call(kk_std_time_timestamp__timestamp, (kk_function_t, kk_std_time_duration__duration, kk_context_t*), _x5544, (_x5544, _x5536, _ctx));
}
 
// Change the internal representation of an instant to use another timescale.
// Only used in special cases for efficiency. For example, when comparing an
// instant in TAI time to thousands of UTC times, it is more efficient to convert
// the TAI time to UTC first to avoid converting at each comparision.

kk_std_time_instant__instant kk_std_time_instant_use_timescale(kk_std_time_instant__instant i, kk_std_time_instant__timescale tscale, kk_context_t* _ctx) { /* (i : instant, tscale : timescale) -> instant */ 
  bool _match_5307;
  kk_string_t _x5545;
  kk_std_time_instant__timescale _match_5308;
  struct kk_std_time_instant_Instant* _con5546 = kk_std_time_instant__as_Instant(i);
  kk_std_time_timestamp__timestamp _pat00 = _con5546->since;
  kk_std_time_instant__timescale _x0 = _con5546->ts;
  struct kk_std_time_instant_Timescale* _con5547 = kk_std_time_instant__as_Timescale(_x0);
  kk_std_time_instant__timescale_dup(_x0);
  _match_5308 = _x0; /*std/time/instant/timescale*/
  struct kk_std_time_instant_Timescale* _con5548 = kk_std_time_instant__as_Timescale(_match_5308);
  kk_string_t _x = _con5548->name;
  kk_string_t _pat0 = _con5548->unit;
  kk_function_t _pat1 = _con5548->from_tai;
  kk_function_t _pat2 = _con5548->to_tai;
  kk_std_core_types__maybe _pat3 = _con5548->mb_seconds_in_day;
  kk_std_core_types__maybe _pat4 = _con5548->mb_to_mjd2000;
  kk_std_core_types__maybe _pat5 = _con5548->mb_from_mjd2000;
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
  _x5545 = _x; /*string*/
  kk_string_t _x5549;
  struct kk_std_time_instant_Timescale* _con5550 = kk_std_time_instant__as_Timescale(tscale);
  kk_string_t _x1 = _con5550->name;
  kk_string_dup(_x1);
  _x5549 = _x1; /*string*/
  _match_5307 = kk_string_is_eq(_x5545,_x5549,kk_context()); /*bool*/
  if (_match_5307) {
    kk_std_time_instant__timescale_dropn(tscale, ((int32_t)10), _ctx);
    return i;
  }
  kk_std_time_timestamp__timestamp _x5551;
  kk_std_time_instant__timescale _x5552 = kk_std_time_instant__timescale_dup(tscale); /*std/time/instant/timescale*/
  _x5551 = kk_std_time_instant_timestamp_in(i, _x5552, _ctx); /*std/time/timestamp/timestamp*/
  return kk_std_time_instant__new_Instant(kk_reuse_null, _x5551, tscale, _ctx);
}
 
// Add a duration to an instant in time.
// Note: this generally entails conversion to TAI time (`ts-tai`).
// See also `add-duration-in` and `add-days` to add
// in direct time scale units.

kk_std_time_instant__instant kk_std_time_instant__lp__plus__rp_(kk_std_time_instant__instant i, kk_std_time_duration__duration d, kk_context_t* _ctx) { /* (i : instant, d : std/time/duration/duration) -> instant */ 
  bool _match_5298;
  kk_string_t _x5553;
  kk_std_time_instant__timescale _match_5306;
  struct kk_std_time_instant_Instant* _con5554 = kk_std_time_instant__as_Instant(i);
  kk_std_time_timestamp__timestamp _pat00 = _con5554->since;
  kk_std_time_instant__timescale _x0 = _con5554->ts;
  struct kk_std_time_instant_Timescale* _con5555 = kk_std_time_instant__as_Timescale(_x0);
  kk_std_time_instant__timescale_dup(_x0);
  _match_5306 = _x0; /*std/time/instant/timescale*/
  struct kk_std_time_instant_Timescale* _con5556 = kk_std_time_instant__as_Timescale(_match_5306);
  kk_string_t _pat0 = _con5556->name;
  kk_string_t _x = _con5556->unit;
  kk_function_t _pat1 = _con5556->from_tai;
  kk_function_t _pat2 = _con5556->to_tai;
  kk_std_core_types__maybe _pat3 = _con5556->mb_seconds_in_day;
  kk_std_core_types__maybe _pat4 = _con5556->mb_to_mjd2000;
  kk_std_core_types__maybe _pat5 = _con5556->mb_from_mjd2000;
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
  _x5553 = _x; /*string*/
  kk_string_t _x5557;
  kk_define_string_literal(, _s5558, 3, "TAI")
  _x5557 = kk_string_dup(_s5558); /*string*/
  _match_5298 = kk_string_is_eq(_x5553,_x5557,kk_context()); /*bool*/
  if (_match_5298) {
    kk_std_time_timestamp__timestamp _x5559;
    kk_std_num_ddouble__ddouble _x5560;
    kk_std_num_ddouble__ddouble _x5561;
    kk_std_time_timestamp__timestamp _match_5305;
    struct kk_std_time_instant_Instant* _con5562 = kk_std_time_instant__as_Instant(i);
    kk_std_time_timestamp__timestamp _x2 = _con5562->since;
    kk_std_time_instant__timescale _pat22 = _con5562->ts;
    struct kk_std_time_instant_Timescale* _con5563 = kk_std_time_instant__as_Timescale(_pat22);
    _match_5305 = _x2; /*std/time/timestamp/timestamp*/
    kk_std_num_ddouble__ddouble _x1 = _match_5305.since;
    _x5561 = _x1; /*std/time/timestamp/timespan*/
    kk_std_num_ddouble__ddouble _x5564;
    kk_std_num_ddouble__ddouble _x4 = d.secs;
    _x5564 = _x4; /*std/time/timestamp/timespan*/
    _x5560 = kk_std_num_ddouble__lp__plus__rp_(_x5561, _x5564, _ctx); /*std/num/ddouble/ddouble*/
    int32_t _x5565;
    kk_std_time_timestamp__timestamp _match_5304;
    struct kk_std_time_instant_Instant* _con5566 = kk_std_time_instant__as_Instant(i);
    kk_std_time_timestamp__timestamp _x20 = _con5566->since;
    kk_std_time_instant__timescale _pat220 = _con5566->ts;
    struct kk_std_time_instant_Timescale* _con5567 = kk_std_time_instant__as_Timescale(_pat220);
    _match_5304 = _x20; /*std/time/timestamp/timestamp*/
    kk_std_num_ddouble__ddouble _pat000 = _match_5304.since;
    int32_t _x00 = _match_5304.leap32;
    _x5565 = _x00; /*int32*/
    _x5559 = kk_std_time_timestamp__new_Timestamp(_x5560, _x5565, _ctx); /*std/time/timestamp/timestamp*/
    kk_std_time_instant__timescale _x5568;
    struct kk_std_time_instant_Instant* _con5569 = kk_std_time_instant__as_Instant(i);
    kk_std_time_timestamp__timestamp _pat03 = _con5569->since;
    kk_std_time_instant__timescale _x3 = _con5569->ts;
    struct kk_std_time_instant_Timescale* _con5570 = kk_std_time_instant__as_Timescale(_x3);
    if (kk_std_time_instant__instant_is_unique(i)) {
      kk_std_time_instant__instant_free(i);
    }
    else {
      kk_std_time_instant__timescale_dup(_x3);
      kk_std_time_instant__instant_decref(i, _ctx);
    }
    _x5568 = _x3; /*std/time/instant/timescale*/
    return kk_std_time_instant__new_Instant(kk_reuse_null, _x5559, _x5568, _ctx);
  }
  kk_std_time_instant__instant i1_4528;
  kk_std_time_instant__instant i2_4530;
  kk_std_time_instant__instant _x5571 = kk_std_time_instant__instant_dup(i); /*std/time/instant/instant*/
  kk_std_time_instant__timescale _x5572 = kk_std_time_instant__timescale_dup(kk_std_time_instant_ts_tai); /*std/time/instant/timescale*/
  i2_4530 = kk_std_time_instant_use_timescale(_x5571, _x5572, _ctx); /*std/time/instant/instant*/
  kk_std_time_timestamp__timestamp _x5573;
  kk_std_num_ddouble__ddouble _x5574;
  kk_std_num_ddouble__ddouble _x5575;
  kk_std_time_timestamp__timestamp _match_5303;
  struct kk_std_time_instant_Instant* _con5576 = kk_std_time_instant__as_Instant(i2_4530);
  kk_std_time_timestamp__timestamp _x9 = _con5576->since;
  kk_std_time_instant__timescale _pat211 = _con5576->ts;
  struct kk_std_time_instant_Timescale* _con5577 = kk_std_time_instant__as_Timescale(_pat211);
  _match_5303 = _x9; /*std/time/timestamp/timestamp*/
  kk_std_num_ddouble__ddouble _x8 = _match_5303.since;
  _x5575 = _x8; /*std/time/timestamp/timespan*/
  kk_std_num_ddouble__ddouble _x5578;
  kk_std_num_ddouble__ddouble _x11 = d.secs;
  _x5578 = _x11; /*std/time/timestamp/timespan*/
  _x5574 = kk_std_num_ddouble__lp__plus__rp_(_x5575, _x5578, _ctx); /*std/num/ddouble/ddouble*/
  int32_t _x5579;
  kk_std_time_timestamp__timestamp _match_5302;
  struct kk_std_time_instant_Instant* _con5580 = kk_std_time_instant__as_Instant(i2_4530);
  kk_std_time_timestamp__timestamp _x90 = _con5580->since;
  kk_std_time_instant__timescale _pat2110 = _con5580->ts;
  struct kk_std_time_instant_Timescale* _con5581 = kk_std_time_instant__as_Timescale(_pat2110);
  _match_5302 = _x90; /*std/time/timestamp/timestamp*/
  kk_std_num_ddouble__ddouble _pat001 = _match_5302.since;
  int32_t _x01 = _match_5302.leap32;
  _x5579 = _x01; /*int32*/
  _x5573 = kk_std_time_timestamp__new_Timestamp(_x5574, _x5579, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_time_instant__timescale _x5582;
  struct kk_std_time_instant_Instant* _con5583 = kk_std_time_instant__as_Instant(i2_4530);
  kk_std_time_timestamp__timestamp _pat012 = _con5583->since;
  kk_std_time_instant__timescale _x10 = _con5583->ts;
  struct kk_std_time_instant_Timescale* _con5584 = kk_std_time_instant__as_Timescale(_x10);
  if (kk_std_time_instant__instant_is_unique(i2_4530)) {
    kk_std_time_instant__instant_free(i2_4530);
  }
  else {
    kk_std_time_instant__timescale_dup(_x10);
    kk_std_time_instant__instant_decref(i2_4530, _ctx);
  }
  _x5582 = _x10; /*std/time/instant/timescale*/
  i1_4528 = kk_std_time_instant__new_Instant(kk_reuse_null, _x5573, _x5582, _ctx); /*std/time/instant/instant*/
  bool _match_5299;
  kk_string_t _x5585;
  kk_std_time_instant__timescale _match_5301;
  struct kk_std_time_instant_Instant* _con5586 = kk_std_time_instant__as_Instant(i1_4528);
  kk_std_time_timestamp__timestamp _pat07 = _con5586->since;
  kk_std_time_instant__timescale _x6 = _con5586->ts;
  struct kk_std_time_instant_Timescale* _con5587 = kk_std_time_instant__as_Timescale(_x6);
  kk_std_time_instant__timescale_dup(_x6);
  _match_5301 = _x6; /*std/time/instant/timescale*/
  struct kk_std_time_instant_Timescale* _con5588 = kk_std_time_instant__as_Timescale(_match_5301);
  kk_string_t _x50 = _con5588->name;
  kk_string_t _pat060 = _con5588->unit;
  kk_function_t _pat1100 = _con5588->from_tai;
  kk_function_t _pat250 = _con5588->to_tai;
  kk_std_core_types__maybe _pat340 = _con5588->mb_seconds_in_day;
  kk_std_core_types__maybe _pat430 = _con5588->mb_to_mjd2000;
  kk_std_core_types__maybe _pat530 = _con5588->mb_from_mjd2000;
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
  _x5585 = _x50; /*string*/
  kk_string_t _x5589;
  kk_std_time_instant__timescale _match_5300;
  struct kk_std_time_instant_Instant* _con5590 = kk_std_time_instant__as_Instant(i);
  kk_std_time_timestamp__timestamp _pat06 = _con5590->since;
  kk_std_time_instant__timescale _x5 = _con5590->ts;
  struct kk_std_time_instant_Timescale* _con5591 = kk_std_time_instant__as_Timescale(_x5);
  kk_std_time_instant__timescale_dup(_x5);
  _match_5300 = _x5; /*std/time/instant/timescale*/
  struct kk_std_time_instant_Timescale* _con5592 = kk_std_time_instant__as_Timescale(_match_5300);
  kk_string_t _x7 = _con5592->name;
  kk_string_t _pat08 = _con5592->unit;
  kk_function_t _pat112 = _con5592->from_tai;
  kk_function_t _pat29 = _con5592->to_tai;
  kk_std_core_types__maybe _pat36 = _con5592->mb_seconds_in_day;
  kk_std_core_types__maybe _pat45 = _con5592->mb_to_mjd2000;
  kk_std_core_types__maybe _pat55 = _con5592->mb_from_mjd2000;
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
  _x5589 = _x7; /*string*/
  _match_5299 = kk_string_is_eq(_x5585,_x5589,kk_context()); /*bool*/
  if (_match_5299) {
    kk_std_time_instant__instant_dropn(i, ((int32_t)1), _ctx);
    return i1_4528;
  }
  kk_std_time_timestamp__timestamp _x5593;
  kk_std_time_instant__timescale _x5594;
  struct kk_std_time_instant_Instant* _con5595 = kk_std_time_instant__as_Instant(i);
  kk_std_time_timestamp__timestamp _pat061 = _con5595->since;
  kk_std_time_instant__timescale _x51 = _con5595->ts;
  struct kk_std_time_instant_Timescale* _con5596 = kk_std_time_instant__as_Timescale(_x51);
  kk_std_time_instant__timescale_dup(_x51);
  _x5594 = _x51; /*std/time/instant/timescale*/
  _x5593 = kk_std_time_instant_timestamp_in(i1_4528, _x5594, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_time_instant__timescale _x5597;
  struct kk_std_time_instant_Instant* _con5598 = kk_std_time_instant__as_Instant(i);
  kk_std_time_timestamp__timestamp _pat062 = _con5598->since;
  kk_std_time_instant__timescale _x52 = _con5598->ts;
  struct kk_std_time_instant_Timescale* _con5599 = kk_std_time_instant__as_Timescale(_x52);
  if (kk_std_time_instant__instant_is_unique(i)) {
    kk_std_time_instant__instant_free(i);
  }
  else {
    kk_std_time_instant__timescale_dup(_x52);
    kk_std_time_instant__instant_decref(i, _ctx);
  }
  _x5597 = _x52; /*std/time/instant/timescale*/
  return kk_std_time_instant__new_Instant(kk_reuse_null, _x5593, _x5597, _ctx);
}
 
// Subtract a duration from an instant in time.

kk_std_time_instant__instant kk_std_time_instant__lp__dash__rp_(kk_std_time_instant__instant i, kk_std_time_duration__duration d, kk_context_t* _ctx) { /* (i : instant, d : std/time/duration/duration) -> instant */ 
  kk_std_time_duration__duration d0_4727 = kk_std_time_duration__lp__tilde__rp_(d, _ctx); /*std/time/duration/duration*/;
  bool _match_5289;
  kk_string_t _x5600;
  kk_std_time_instant__timescale _match_5297;
  struct kk_std_time_instant_Instant* _con5601 = kk_std_time_instant__as_Instant(i);
  kk_std_time_timestamp__timestamp _pat00 = _con5601->since;
  kk_std_time_instant__timescale _x0 = _con5601->ts;
  struct kk_std_time_instant_Timescale* _con5602 = kk_std_time_instant__as_Timescale(_x0);
  kk_std_time_instant__timescale_dup(_x0);
  _match_5297 = _x0; /*std/time/instant/timescale*/
  struct kk_std_time_instant_Timescale* _con5603 = kk_std_time_instant__as_Timescale(_match_5297);
  kk_string_t _pat0 = _con5603->name;
  kk_string_t _x = _con5603->unit;
  kk_function_t _pat1 = _con5603->from_tai;
  kk_function_t _pat2 = _con5603->to_tai;
  kk_std_core_types__maybe _pat3 = _con5603->mb_seconds_in_day;
  kk_std_core_types__maybe _pat4 = _con5603->mb_to_mjd2000;
  kk_std_core_types__maybe _pat5 = _con5603->mb_from_mjd2000;
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
  _x5600 = _x; /*string*/
  kk_string_t _x5604;
  kk_define_string_literal(, _s5605, 3, "TAI")
  _x5604 = kk_string_dup(_s5605); /*string*/
  _match_5289 = kk_string_is_eq(_x5600,_x5604,kk_context()); /*bool*/
  if (_match_5289) {
    kk_std_time_timestamp__timestamp _x5606;
    kk_std_num_ddouble__ddouble _x5607;
    kk_std_num_ddouble__ddouble _x5608;
    kk_std_time_timestamp__timestamp _match_5296;
    struct kk_std_time_instant_Instant* _con5609 = kk_std_time_instant__as_Instant(i);
    kk_std_time_timestamp__timestamp _x2 = _con5609->since;
    kk_std_time_instant__timescale _pat22 = _con5609->ts;
    struct kk_std_time_instant_Timescale* _con5610 = kk_std_time_instant__as_Timescale(_pat22);
    _match_5296 = _x2; /*std/time/timestamp/timestamp*/
    kk_std_num_ddouble__ddouble _x1 = _match_5296.since;
    _x5608 = _x1; /*std/time/timestamp/timespan*/
    kk_std_num_ddouble__ddouble _x5611;
    kk_std_num_ddouble__ddouble _x4 = d0_4727.secs;
    _x5611 = _x4; /*std/time/timestamp/timespan*/
    _x5607 = kk_std_num_ddouble__lp__plus__rp_(_x5608, _x5611, _ctx); /*std/num/ddouble/ddouble*/
    int32_t _x5612;
    kk_std_time_timestamp__timestamp _match_5295;
    struct kk_std_time_instant_Instant* _con5613 = kk_std_time_instant__as_Instant(i);
    kk_std_time_timestamp__timestamp _x20 = _con5613->since;
    kk_std_time_instant__timescale _pat220 = _con5613->ts;
    struct kk_std_time_instant_Timescale* _con5614 = kk_std_time_instant__as_Timescale(_pat220);
    _match_5295 = _x20; /*std/time/timestamp/timestamp*/
    kk_std_num_ddouble__ddouble _pat000 = _match_5295.since;
    int32_t _x00 = _match_5295.leap32;
    _x5612 = _x00; /*int32*/
    _x5606 = kk_std_time_timestamp__new_Timestamp(_x5607, _x5612, _ctx); /*std/time/timestamp/timestamp*/
    kk_std_time_instant__timescale _x5615;
    struct kk_std_time_instant_Instant* _con5616 = kk_std_time_instant__as_Instant(i);
    kk_std_time_timestamp__timestamp _pat03 = _con5616->since;
    kk_std_time_instant__timescale _x3 = _con5616->ts;
    struct kk_std_time_instant_Timescale* _con5617 = kk_std_time_instant__as_Timescale(_x3);
    if (kk_std_time_instant__instant_is_unique(i)) {
      kk_std_time_instant__instant_free(i);
    }
    else {
      kk_std_time_instant__timescale_dup(_x3);
      kk_std_time_instant__instant_decref(i, _ctx);
    }
    _x5615 = _x3; /*std/time/instant/timescale*/
    return kk_std_time_instant__new_Instant(kk_reuse_null, _x5606, _x5615, _ctx);
  }
  kk_std_time_instant__instant i1_4528;
  kk_std_time_instant__instant i2_4530;
  kk_std_time_instant__instant _x5618 = kk_std_time_instant__instant_dup(i); /*std/time/instant/instant*/
  kk_std_time_instant__timescale _x5619 = kk_std_time_instant__timescale_dup(kk_std_time_instant_ts_tai); /*std/time/instant/timescale*/
  i2_4530 = kk_std_time_instant_use_timescale(_x5618, _x5619, _ctx); /*std/time/instant/instant*/
  kk_std_time_timestamp__timestamp _x5620;
  kk_std_num_ddouble__ddouble _x5621;
  kk_std_num_ddouble__ddouble _x5622;
  kk_std_time_timestamp__timestamp _match_5294;
  struct kk_std_time_instant_Instant* _con5623 = kk_std_time_instant__as_Instant(i2_4530);
  kk_std_time_timestamp__timestamp _x9 = _con5623->since;
  kk_std_time_instant__timescale _pat211 = _con5623->ts;
  struct kk_std_time_instant_Timescale* _con5624 = kk_std_time_instant__as_Timescale(_pat211);
  _match_5294 = _x9; /*std/time/timestamp/timestamp*/
  kk_std_num_ddouble__ddouble _x8 = _match_5294.since;
  _x5622 = _x8; /*std/time/timestamp/timespan*/
  kk_std_num_ddouble__ddouble _x5625;
  kk_std_num_ddouble__ddouble _x11 = d0_4727.secs;
  _x5625 = _x11; /*std/time/timestamp/timespan*/
  _x5621 = kk_std_num_ddouble__lp__plus__rp_(_x5622, _x5625, _ctx); /*std/num/ddouble/ddouble*/
  int32_t _x5626;
  kk_std_time_timestamp__timestamp _match_5293;
  struct kk_std_time_instant_Instant* _con5627 = kk_std_time_instant__as_Instant(i2_4530);
  kk_std_time_timestamp__timestamp _x90 = _con5627->since;
  kk_std_time_instant__timescale _pat2110 = _con5627->ts;
  struct kk_std_time_instant_Timescale* _con5628 = kk_std_time_instant__as_Timescale(_pat2110);
  _match_5293 = _x90; /*std/time/timestamp/timestamp*/
  kk_std_num_ddouble__ddouble _pat001 = _match_5293.since;
  int32_t _x01 = _match_5293.leap32;
  _x5626 = _x01; /*int32*/
  _x5620 = kk_std_time_timestamp__new_Timestamp(_x5621, _x5626, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_time_instant__timescale _x5629;
  struct kk_std_time_instant_Instant* _con5630 = kk_std_time_instant__as_Instant(i2_4530);
  kk_std_time_timestamp__timestamp _pat012 = _con5630->since;
  kk_std_time_instant__timescale _x10 = _con5630->ts;
  struct kk_std_time_instant_Timescale* _con5631 = kk_std_time_instant__as_Timescale(_x10);
  if (kk_std_time_instant__instant_is_unique(i2_4530)) {
    kk_std_time_instant__instant_free(i2_4530);
  }
  else {
    kk_std_time_instant__timescale_dup(_x10);
    kk_std_time_instant__instant_decref(i2_4530, _ctx);
  }
  _x5629 = _x10; /*std/time/instant/timescale*/
  i1_4528 = kk_std_time_instant__new_Instant(kk_reuse_null, _x5620, _x5629, _ctx); /*std/time/instant/instant*/
  bool _match_5290;
  kk_string_t _x5632;
  kk_std_time_instant__timescale _match_5292;
  struct kk_std_time_instant_Instant* _con5633 = kk_std_time_instant__as_Instant(i1_4528);
  kk_std_time_timestamp__timestamp _pat07 = _con5633->since;
  kk_std_time_instant__timescale _x6 = _con5633->ts;
  struct kk_std_time_instant_Timescale* _con5634 = kk_std_time_instant__as_Timescale(_x6);
  kk_std_time_instant__timescale_dup(_x6);
  _match_5292 = _x6; /*std/time/instant/timescale*/
  struct kk_std_time_instant_Timescale* _con5635 = kk_std_time_instant__as_Timescale(_match_5292);
  kk_string_t _x50 = _con5635->name;
  kk_string_t _pat060 = _con5635->unit;
  kk_function_t _pat1100 = _con5635->from_tai;
  kk_function_t _pat250 = _con5635->to_tai;
  kk_std_core_types__maybe _pat340 = _con5635->mb_seconds_in_day;
  kk_std_core_types__maybe _pat430 = _con5635->mb_to_mjd2000;
  kk_std_core_types__maybe _pat530 = _con5635->mb_from_mjd2000;
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
  _x5632 = _x50; /*string*/
  kk_string_t _x5636;
  kk_std_time_instant__timescale _match_5291;
  struct kk_std_time_instant_Instant* _con5637 = kk_std_time_instant__as_Instant(i);
  kk_std_time_timestamp__timestamp _pat06 = _con5637->since;
  kk_std_time_instant__timescale _x5 = _con5637->ts;
  struct kk_std_time_instant_Timescale* _con5638 = kk_std_time_instant__as_Timescale(_x5);
  kk_std_time_instant__timescale_dup(_x5);
  _match_5291 = _x5; /*std/time/instant/timescale*/
  struct kk_std_time_instant_Timescale* _con5639 = kk_std_time_instant__as_Timescale(_match_5291);
  kk_string_t _x7 = _con5639->name;
  kk_string_t _pat08 = _con5639->unit;
  kk_function_t _pat112 = _con5639->from_tai;
  kk_function_t _pat29 = _con5639->to_tai;
  kk_std_core_types__maybe _pat36 = _con5639->mb_seconds_in_day;
  kk_std_core_types__maybe _pat45 = _con5639->mb_to_mjd2000;
  kk_std_core_types__maybe _pat55 = _con5639->mb_from_mjd2000;
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
  _x5636 = _x7; /*string*/
  _match_5290 = kk_string_is_eq(_x5632,_x5636,kk_context()); /*bool*/
  if (_match_5290) {
    kk_std_time_instant__instant_dropn(i, ((int32_t)1), _ctx);
    return i1_4528;
  }
  kk_std_time_timestamp__timestamp _x5640;
  kk_std_time_instant__timescale _x5641;
  struct kk_std_time_instant_Instant* _con5642 = kk_std_time_instant__as_Instant(i);
  kk_std_time_timestamp__timestamp _pat061 = _con5642->since;
  kk_std_time_instant__timescale _x51 = _con5642->ts;
  struct kk_std_time_instant_Timescale* _con5643 = kk_std_time_instant__as_Timescale(_x51);
  kk_std_time_instant__timescale_dup(_x51);
  _x5641 = _x51; /*std/time/instant/timescale*/
  _x5640 = kk_std_time_instant_timestamp_in(i1_4528, _x5641, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_time_instant__timescale _x5644;
  struct kk_std_time_instant_Instant* _con5645 = kk_std_time_instant__as_Instant(i);
  kk_std_time_timestamp__timestamp _pat062 = _con5645->since;
  kk_std_time_instant__timescale _x52 = _con5645->ts;
  struct kk_std_time_instant_Timescale* _con5646 = kk_std_time_instant__as_Timescale(_x52);
  if (kk_std_time_instant__instant_is_unique(i)) {
    kk_std_time_instant__instant_free(i);
  }
  else {
    kk_std_time_instant__timescale_dup(_x52);
    kk_std_time_instant__instant_decref(i, _ctx);
  }
  _x5644 = _x52; /*std/time/instant/timescale*/
  return kk_std_time_instant__new_Instant(kk_reuse_null, _x5640, _x5644, _ctx);
}
 
// Are two timescales the same?

bool kk_std_time_instant__lp__eq__eq__rp_(kk_std_time_instant__timescale t1, kk_std_time_instant__timescale t2, kk_context_t* _ctx) { /* (t1 : timescale, t2 : timescale) -> bool */ 
  kk_string_t _x5652;
  struct kk_std_time_instant_Timescale* _con5653 = kk_std_time_instant__as_Timescale(t1);
  kk_string_t _x = _con5653->name;
  kk_string_t _pat0 = _con5653->unit;
  kk_function_t _pat1 = _con5653->from_tai;
  kk_function_t _pat2 = _con5653->to_tai;
  kk_std_core_types__maybe _pat3 = _con5653->mb_seconds_in_day;
  kk_std_core_types__maybe _pat4 = _con5653->mb_to_mjd2000;
  kk_std_core_types__maybe _pat5 = _con5653->mb_from_mjd2000;
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
  _x5652 = _x; /*string*/
  kk_string_t _x5654;
  struct kk_std_time_instant_Timescale* _con5655 = kk_std_time_instant__as_Timescale(t2);
  kk_string_t _x0 = _con5655->name;
  kk_string_t _pat00 = _con5655->unit;
  kk_function_t _pat10 = _con5655->from_tai;
  kk_function_t _pat20 = _con5655->to_tai;
  kk_std_core_types__maybe _pat30 = _con5655->mb_seconds_in_day;
  kk_std_core_types__maybe _pat40 = _con5655->mb_to_mjd2000;
  kk_std_core_types__maybe _pat50 = _con5655->mb_from_mjd2000;
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
  _x5654 = _x0; /*string*/
  return kk_string_is_eq(_x5652,_x5654,kk_context());
}
 
// Compare two `:instant`s in time.

kk_std_core_types__order kk_std_time_instant_compare(kk_std_time_instant__instant i, kk_std_time_instant__instant j, kk_context_t* _ctx) { /* (i : instant, j : instant) -> order */ 
  kk_std_time_timestamp__timestamp _x5656;
  struct kk_std_time_instant_Instant* _con5657 = kk_std_time_instant__as_Instant(i);
  kk_std_time_timestamp__timestamp _x = _con5657->since;
  kk_std_time_instant__timescale _pat2 = _con5657->ts;
  struct kk_std_time_instant_Timescale* _con5658 = kk_std_time_instant__as_Timescale(_pat2);
  _x5656 = _x; /*std/time/timestamp/timestamp*/
  kk_std_time_timestamp__timestamp _x5659;
  kk_std_time_instant__instant instant0_4546;
  bool _match_5286;
  kk_string_t _x5660;
  kk_std_time_instant__timescale _match_5288;
  struct kk_std_time_instant_Instant* _con5661 = kk_std_time_instant__as_Instant(j);
  kk_std_time_timestamp__timestamp _pat02 = _con5661->since;
  kk_std_time_instant__timescale _x2 = _con5661->ts;
  struct kk_std_time_instant_Timescale* _con5662 = kk_std_time_instant__as_Timescale(_x2);
  kk_std_time_instant__timescale_dup(_x2);
  _match_5288 = _x2; /*std/time/instant/timescale*/
  struct kk_std_time_instant_Timescale* _con5663 = kk_std_time_instant__as_Timescale(_match_5288);
  kk_string_t _x1 = _con5663->name;
  kk_string_t _pat01 = _con5663->unit;
  kk_function_t _pat13 = _con5663->from_tai;
  kk_function_t _pat21 = _con5663->to_tai;
  kk_std_core_types__maybe _pat31 = _con5663->mb_seconds_in_day;
  kk_std_core_types__maybe _pat41 = _con5663->mb_to_mjd2000;
  kk_std_core_types__maybe _pat51 = _con5663->mb_from_mjd2000;
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
  _x5660 = _x1; /*string*/
  kk_string_t _x5664;
  kk_std_time_instant__timescale _match_5287;
  struct kk_std_time_instant_Instant* _con5665 = kk_std_time_instant__as_Instant(i);
  kk_std_time_timestamp__timestamp _pat05 = _con5665->since;
  kk_std_time_instant__timescale _x4 = _con5665->ts;
  struct kk_std_time_instant_Timescale* _con5666 = kk_std_time_instant__as_Timescale(_x4);
  kk_std_time_instant__timescale_dup(_x4);
  _match_5287 = _x4; /*std/time/instant/timescale*/
  struct kk_std_time_instant_Timescale* _con5667 = kk_std_time_instant__as_Timescale(_match_5287);
  kk_string_t _x3 = _con5667->name;
  kk_string_t _pat03 = _con5667->unit;
  kk_function_t _pat17 = _con5667->from_tai;
  kk_function_t _pat23 = _con5667->to_tai;
  kk_std_core_types__maybe _pat33 = _con5667->mb_seconds_in_day;
  kk_std_core_types__maybe _pat43 = _con5667->mb_to_mjd2000;
  kk_std_core_types__maybe _pat53 = _con5667->mb_from_mjd2000;
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
  _x5664 = _x3; /*string*/
  _match_5286 = kk_string_is_eq(_x5660,_x5664,kk_context()); /*bool*/
  if (_match_5286) {
    kk_std_time_instant__instant_dropn(i, ((int32_t)1), _ctx);
    instant0_4546 = j; /*std/time/instant/instant*/
  }
  else {
    kk_std_time_timestamp__timestamp _x5668;
    kk_std_time_instant__timescale _x5669;
    struct kk_std_time_instant_Instant* _con5670 = kk_std_time_instant__as_Instant(i);
    kk_std_time_timestamp__timestamp _pat050 = _con5670->since;
    kk_std_time_instant__timescale _x40 = _con5670->ts;
    struct kk_std_time_instant_Timescale* _con5671 = kk_std_time_instant__as_Timescale(_x40);
    kk_std_time_instant__timescale_dup(_x40);
    _x5669 = _x40; /*std/time/instant/timescale*/
    _x5668 = kk_std_time_instant_timestamp_in(j, _x5669, _ctx); /*std/time/timestamp/timestamp*/
    kk_std_time_instant__timescale _x5672;
    struct kk_std_time_instant_Instant* _con5673 = kk_std_time_instant__as_Instant(i);
    kk_std_time_timestamp__timestamp _pat051 = _con5673->since;
    kk_std_time_instant__timescale _x41 = _con5673->ts;
    struct kk_std_time_instant_Timescale* _con5674 = kk_std_time_instant__as_Timescale(_x41);
    if (kk_std_time_instant__instant_is_unique(i)) {
      kk_std_time_instant__instant_free(i);
    }
    else {
      kk_std_time_instant__timescale_dup(_x41);
      kk_std_time_instant__instant_decref(i, _ctx);
    }
    _x5672 = _x41; /*std/time/instant/timescale*/
    instant0_4546 = kk_std_time_instant__new_Instant(kk_reuse_null, _x5668, _x5672, _ctx); /*std/time/instant/instant*/
  }
  struct kk_std_time_instant_Instant* _con5675 = kk_std_time_instant__as_Instant(instant0_4546);
  kk_std_time_timestamp__timestamp _x0 = _con5675->since;
  kk_std_time_instant__timescale _pat20 = _con5675->ts;
  struct kk_std_time_instant_Timescale* _con5676 = kk_std_time_instant__as_Timescale(_pat20);
  kk_string_t _pat30 = _con5676->name;
  kk_string_t _pat40 = _con5676->unit;
  kk_function_t _pat50 = _con5676->from_tai;
  kk_function_t _pat60 = _con5676->to_tai;
  kk_std_core_types__maybe _pat70 = _con5676->mb_seconds_in_day;
  kk_std_core_types__maybe _pat80 = _con5676->mb_to_mjd2000;
  kk_std_core_types__maybe _pat90 = _con5676->mb_from_mjd2000;
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
  _x5659 = _x0; /*std/time/timestamp/timestamp*/
  return kk_std_time_timestamp_compare(_x5656, _x5659, _ctx);
}

bool kk_std_time_instant__lp__eq__eq__1_rp_(kk_std_time_instant__instant i, kk_std_time_instant__instant j, kk_context_t* _ctx) { /* (i : instant, j : instant) -> bool */ 
  kk_std_core_types__order x_4553 = kk_std_time_instant_compare(i, j, _ctx); /*order*/;
  kk_integer_t _x5677 = kk_std_core_int_5(x_4553, _ctx); /*int*/
  kk_integer_t _x5678;
  kk_std_core_types__order _x5679 = kk_std_core_types__new_Eq(_ctx); /*order*/
  if (kk_std_core_types__is_Lt(_x5679)) {
    _x5678 = kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context()); /*int*/
    goto _match5680;
  }
  if (kk_std_core_types__is_Eq(_x5679)) {
    _x5678 = kk_integer_from_small(0); /*int*/
    goto _match5680;
  }
  _x5678 = kk_integer_from_small(1); /*int*/
  _match5680: ;
  return kk_integer_eq(_x5677,_x5678,kk_context());
}
 
// Given a `:duration` since the `epoch`, return a `:timespan` for that instant in time scale `ts`.

kk_std_time_timestamp__timestamp kk_std_time_instant_from_tai_1(kk_std_time_instant__timescale ts0, kk_std_time_duration__duration d, kk_context_t* _ctx) { /* (ts : timescale, d : std/time/duration/duration) -> std/time/timestamp/timestamp */ 
  kk_std_time_timestamp__timestamp t_4555 = kk_std_time_duration_timestamp(d, _ctx); /*std/time/timestamp/timestamp*/;
  bool _match_5282;
  kk_string_t _x5681;
  kk_std_time_instant__timescale _x5682 = kk_std_time_instant_ts_tai; /*std/time/instant/timescale*/
  struct kk_std_time_instant_Timescale* _con5683 = kk_std_time_instant__as_Timescale(_x5682);
  kk_string_t _x = _con5683->name;
  kk_string_dup(_x);
  _x5681 = _x; /*string*/
  kk_string_t _x5684;
  struct kk_std_time_instant_Timescale* _con5685 = kk_std_time_instant__as_Timescale(ts0);
  kk_string_t _x0 = _con5685->name;
  kk_string_dup(_x0);
  _x5684 = _x0; /*string*/
  _match_5282 = kk_string_is_eq(_x5681,_x5684,kk_context()); /*bool*/
  if (_match_5282) {
    kk_std_time_instant__timescale_dropn(ts0, ((int32_t)10), _ctx);
    return t_4555;
  }
  bool _match_5283;
  bool _match_5284;
  kk_string_t _x5686;
  kk_std_time_instant__timescale _x5687 = kk_std_time_instant_ts_tai; /*std/time/instant/timescale*/
  struct kk_std_time_instant_Timescale* _con5688 = kk_std_time_instant__as_Timescale(_x5687);
  kk_string_t _x1 = _con5688->unit;
  kk_string_dup(_x1);
  _x5686 = _x1; /*string*/
  kk_string_t _x5689;
  struct kk_std_time_instant_Timescale* _con5690 = kk_std_time_instant__as_Timescale(ts0);
  kk_string_t _x2 = _con5690->unit;
  kk_string_dup(_x2);
  _x5689 = _x2; /*string*/
  _match_5284 = kk_string_is_eq(_x5686,_x5689,kk_context()); /*bool*/
  if (_match_5284) {
    kk_string_t _x5691;
    kk_std_time_instant__timescale _x5692 = kk_std_time_instant_ts_tai; /*std/time/instant/timescale*/
    struct kk_std_time_instant_Timescale* _con5693 = kk_std_time_instant__as_Timescale(_x5692);
    kk_string_t _x3 = _con5693->unit;
    kk_string_dup(_x3);
    _x5691 = _x3; /*string*/
    kk_string_t _x5694;
    kk_define_string_literal(, _s5695, 3, "UTC")
    _x5694 = kk_string_dup(_s5695); /*string*/
    _match_5283 = kk_string_is_eq(_x5691,_x5694,kk_context()); /*bool*/
  }
  else {
    _match_5283 = false; /*bool*/
  }
  if (_match_5283) {
    kk_std_time_instant__timescale_dropn(ts0, ((int32_t)10), _ctx);
    return t_4555;
  }
  kk_function_t _x5699 = kk_std_time_instant_from_tai(ts0, _ctx); /*(std/time/duration/duration) -> std/time/timestamp/timestamp*/
  kk_std_time_duration__duration _x5696;
  kk_function_t _x5697;
  kk_std_time_instant__timescale _x5698 = kk_std_time_instant__timescale_dup(kk_std_time_instant_ts_tai); /*std/time/instant/timescale*/
  _x5697 = kk_std_time_instant_to_tai(_x5698, _ctx); /*(std/time/timestamp/timestamp) -> std/time/duration/duration*/
  _x5696 = kk_function_call(kk_std_time_duration__duration, (kk_function_t, kk_std_time_timestamp__timestamp, kk_context_t*), _x5697, (_x5697, t_4555, _ctx)); /*std/time/duration/duration*/
  return kk_function_call(kk_std_time_timestamp__timestamp, (kk_function_t, kk_std_time_duration__duration, kk_context_t*), _x5699, (_x5699, _x5696, _ctx));
}
 
// Return the instant in time scale `ts`, `days` and `secs` after 2000-01-01 in that timescale.

kk_std_time_instant__instant kk_std_time_instant_instant_2(kk_std_time_instant__timescale ts0, kk_integer_t days0, kk_std_num_ddouble__ddouble secs, kk_std_core_types__optional leap, kk_context_t* _ctx) { /* (ts : timescale, days : int, secs : std/time/timestamp/timespan, leap : optional<int>) -> instant */ 
  kk_std_time_timestamp__timestamp t_4566;
  kk_std_core_types__optional _x5701 = kk_std_core_types__new_Optional(kk_std_num_ddouble__ddouble_box(secs, _ctx), _ctx); /*optional<35>*/
  kk_std_core_types__optional _x5702;
  kk_box_t _x5703;
  kk_integer_t _x5704;
  if (kk_std_core_types__is_Optional(leap)) {
    kk_box_t _box_x4805 = leap._cons.Optional.value;
    kk_integer_t _leap_1630 = kk_integer_unbox(_box_x4805);
    kk_integer_dup(_leap_1630);
    kk_std_core_types__optional_drop(leap, _ctx);
    _x5704 = _leap_1630; /*int*/
    goto _match5705;
  }
  _x5704 = kk_integer_from_small(0); /*int*/
  _match5705: ;
  _x5703 = kk_integer_box(_x5704); /*35*/
  _x5702 = kk_std_core_types__new_Optional(_x5703, _ctx); /*optional<35>*/
  t_4566 = kk_std_time_timestamp_timestamp_days(days0, _x5701, _x5702, _ctx); /*std/time/timestamp/timestamp*/
  return kk_std_time_instant__new_Instant(kk_reuse_null, t_4566, ts0, _ctx);
}

bool kk_std_time_instant__lp__excl__eq__rp_(kk_std_time_instant__instant i, kk_std_time_instant__instant j, kk_context_t* _ctx) { /* (i : instant, j : instant) -> bool */ 
  kk_std_core_types__order x_4568 = kk_std_time_instant_compare(i, j, _ctx); /*order*/;
  kk_integer_t _x5709 = kk_std_core_int_5(x_4568, _ctx); /*int*/
  kk_integer_t _x5710;
  kk_std_core_types__order _x5711 = kk_std_core_types__new_Eq(_ctx); /*order*/
  if (kk_std_core_types__is_Lt(_x5711)) {
    _x5710 = kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context()); /*int*/
    goto _match5712;
  }
  if (kk_std_core_types__is_Eq(_x5711)) {
    _x5710 = kk_integer_from_small(0); /*int*/
    goto _match5712;
  }
  _x5710 = kk_integer_from_small(1); /*int*/
  _match5712: ;
  return kk_integer_neq(_x5709,_x5710,kk_context());
}

bool kk_std_time_instant__lp__lt__rp_(kk_std_time_instant__instant i, kk_std_time_instant__instant j, kk_context_t* _ctx) { /* (i : instant, j : instant) -> bool */ 
  kk_std_core_types__order x_4570 = kk_std_time_instant_compare(i, j, _ctx); /*order*/;
  kk_integer_t _x5713 = kk_std_core_int_5(x_4570, _ctx); /*int*/
  kk_integer_t _x5714;
  kk_std_core_types__order _x5715 = kk_std_core_types__new_Lt(_ctx); /*order*/
  if (kk_std_core_types__is_Lt(_x5715)) {
    _x5714 = kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context()); /*int*/
    goto _match5716;
  }
  if (kk_std_core_types__is_Eq(_x5715)) {
    _x5714 = kk_integer_from_small(0); /*int*/
    goto _match5716;
  }
  _x5714 = kk_integer_from_small(1); /*int*/
  _match5716: ;
  return kk_integer_eq(_x5713,_x5714,kk_context());
}

bool kk_std_time_instant__lp__lt__eq__rp_(kk_std_time_instant__instant i, kk_std_time_instant__instant j, kk_context_t* _ctx) { /* (i : instant, j : instant) -> bool */ 
  kk_std_core_types__order x_4572 = kk_std_time_instant_compare(i, j, _ctx); /*order*/;
  kk_integer_t _x5717 = kk_std_core_int_5(x_4572, _ctx); /*int*/
  kk_integer_t _x5718;
  kk_std_core_types__order _x5719 = kk_std_core_types__new_Gt(_ctx); /*order*/
  if (kk_std_core_types__is_Lt(_x5719)) {
    _x5718 = kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context()); /*int*/
    goto _match5720;
  }
  if (kk_std_core_types__is_Eq(_x5719)) {
    _x5718 = kk_integer_from_small(0); /*int*/
    goto _match5720;
  }
  _x5718 = kk_integer_from_small(1); /*int*/
  _match5720: ;
  return kk_integer_neq(_x5717,_x5718,kk_context());
}

bool kk_std_time_instant__lp__gt__rp_(kk_std_time_instant__instant i, kk_std_time_instant__instant j, kk_context_t* _ctx) { /* (i : instant, j : instant) -> bool */ 
  kk_std_core_types__order x_4574 = kk_std_time_instant_compare(i, j, _ctx); /*order*/;
  kk_integer_t _x5721 = kk_std_core_int_5(x_4574, _ctx); /*int*/
  kk_integer_t _x5722;
  kk_std_core_types__order _x5723 = kk_std_core_types__new_Gt(_ctx); /*order*/
  if (kk_std_core_types__is_Lt(_x5723)) {
    _x5722 = kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context()); /*int*/
    goto _match5724;
  }
  if (kk_std_core_types__is_Eq(_x5723)) {
    _x5722 = kk_integer_from_small(0); /*int*/
    goto _match5724;
  }
  _x5722 = kk_integer_from_small(1); /*int*/
  _match5724: ;
  return kk_integer_eq(_x5721,_x5722,kk_context());
}

bool kk_std_time_instant__lp__gt__eq__rp_(kk_std_time_instant__instant i, kk_std_time_instant__instant j, kk_context_t* _ctx) { /* (i : instant, j : instant) -> bool */ 
  kk_std_core_types__order x_4576 = kk_std_time_instant_compare(i, j, _ctx); /*order*/;
  kk_integer_t _x5725 = kk_std_core_int_5(x_4576, _ctx); /*int*/
  kk_integer_t _x5726;
  kk_std_core_types__order _x5727 = kk_std_core_types__new_Lt(_ctx); /*order*/
  if (kk_std_core_types__is_Lt(_x5727)) {
    _x5726 = kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context()); /*int*/
    goto _match5728;
  }
  if (kk_std_core_types__is_Eq(_x5727)) {
    _x5726 = kk_integer_from_small(0); /*int*/
    goto _match5728;
  }
  _x5726 = kk_integer_from_small(1); /*int*/
  _match5728: ;
  return kk_integer_neq(_x5725,_x5726,kk_context());
}
 
// Add `days` days to the instant.

kk_std_time_instant__instant kk_std_time_instant_add_days(kk_std_time_instant__instant i, kk_integer_t days0, kk_context_t* _ctx) { /* (i : instant, days : int) -> instant */ 
  kk_std_time_timestamp__timestamp _x5729;
  kk_std_time_timestamp__timestamp _x5730;
  struct kk_std_time_instant_Instant* _con5731 = kk_std_time_instant__as_Instant(i);
  kk_std_time_timestamp__timestamp _x = _con5731->since;
  kk_std_time_instant__timescale _pat2 = _con5731->ts;
  struct kk_std_time_instant_Timescale* _con5732 = kk_std_time_instant__as_Timescale(_pat2);
  _x5730 = _x; /*std/time/timestamp/timestamp*/
  _x5729 = kk_std_time_timestamp_add_days(_x5730, days0, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_time_instant__timescale _x5733;
  struct kk_std_time_instant_Instant* _con5734 = kk_std_time_instant__as_Instant(i);
  kk_std_time_timestamp__timestamp _pat00 = _con5734->since;
  kk_std_time_instant__timescale _x0 = _con5734->ts;
  struct kk_std_time_instant_Timescale* _con5735 = kk_std_time_instant__as_Timescale(_x0);
  if (kk_std_time_instant__instant_is_unique(i)) {
    kk_std_time_instant__instant_free(i);
  }
  else {
    kk_std_time_instant__timescale_dup(_x0);
    kk_std_time_instant__instant_decref(i, _ctx);
  }
  _x5733 = _x0; /*std/time/instant/timescale*/
  return kk_std_time_instant__new_Instant(kk_reuse_null, _x5729, _x5733, _ctx);
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
  kk_std_time_timestamp__timestamp _x5736;
  kk_std_num_ddouble__ddouble _x5737;
  kk_std_num_ddouble__ddouble _x5738;
  kk_std_time_timestamp__timestamp _match_5276;
  struct kk_std_time_instant_Instant* _con5739 = kk_std_time_instant__as_Instant(i0_4580);
  kk_std_time_timestamp__timestamp _x1 = _con5739->since;
  kk_std_time_instant__timescale _pat21 = _con5739->ts;
  struct kk_std_time_instant_Timescale* _con5740 = kk_std_time_instant__as_Timescale(_pat21);
  _match_5276 = _x1; /*std/time/timestamp/timestamp*/
  kk_std_num_ddouble__ddouble _x = _match_5276.since;
  _x5738 = _x; /*std/time/timestamp/timespan*/
  _x5737 = kk_std_num_ddouble__lp__plus__rp_(_x5738, t, _ctx); /*std/num/ddouble/ddouble*/
  int32_t _x5741;
  kk_std_time_timestamp__timestamp _match_5275;
  struct kk_std_time_instant_Instant* _con5742 = kk_std_time_instant__as_Instant(i0_4580);
  kk_std_time_timestamp__timestamp _x10 = _con5742->since;
  kk_std_time_instant__timescale _pat210 = _con5742->ts;
  struct kk_std_time_instant_Timescale* _con5743 = kk_std_time_instant__as_Timescale(_pat210);
  _match_5275 = _x10; /*std/time/timestamp/timestamp*/
  kk_std_num_ddouble__ddouble _pat00 = _match_5275.since;
  int32_t _x0 = _match_5275.leap32;
  _x5741 = _x0; /*int32*/
  _x5736 = kk_std_time_timestamp__new_Timestamp(_x5737, _x5741, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_time_instant__timescale _x5744;
  struct kk_std_time_instant_Instant* _con5745 = kk_std_time_instant__as_Instant(i0_4580);
  kk_std_time_timestamp__timestamp _pat02 = _con5745->since;
  kk_std_time_instant__timescale _x2 = _con5745->ts;
  struct kk_std_time_instant_Timescale* _con5746 = kk_std_time_instant__as_Timescale(_x2);
  if (kk_std_time_instant__instant_is_unique(i0_4580)) {
    kk_std_time_instant__instant_free(i0_4580);
  }
  else {
    kk_std_time_instant__timescale_dup(_x2);
    kk_std_time_instant__instant_decref(i0_4580, _ctx);
  }
  _x5744 = _x2; /*std/time/instant/timescale*/
  return kk_std_time_instant__new_Instant(kk_reuse_null, _x5736, _x5744, _ctx);
}
 
// Return days since 2000-01-01 in the time scale of the instant

kk_integer_t kk_std_time_instant_days(kk_std_time_instant__instant i, kk_context_t* _ctx) { /* (i : instant) -> int */ 
  kk_std_core_types__tuple2_ _this_3806;
  kk_std_num_ddouble__ddouble secs;
  kk_std_num_ddouble__ddouble _x5747;
  kk_std_time_timestamp__timestamp _match_5274;
  struct kk_std_time_instant_Instant* _con5748 = kk_std_time_instant__as_Instant(i);
  kk_std_time_timestamp__timestamp _x00 = _con5748->since;
  kk_std_time_instant__timescale _pat21 = _con5748->ts;
  struct kk_std_time_instant_Timescale* _con5749 = kk_std_time_instant__as_Timescale(_pat21);
  _match_5274 = _x00; /*std/time/timestamp/timestamp*/
  kk_std_num_ddouble__ddouble _x = _match_5274.since;
  _x5747 = _x; /*std/time/timestamp/timespan*/
  secs = kk_std_num_ddouble_floor(_x5747, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble frac;
  kk_std_num_ddouble__ddouble _x5750;
  kk_std_time_timestamp__timestamp _match_5273;
  struct kk_std_time_instant_Instant* _con5751 = kk_std_time_instant__as_Instant(i);
  kk_std_time_timestamp__timestamp _x000 = _con5751->since;
  kk_std_time_instant__timescale _pat210 = _con5751->ts;
  struct kk_std_time_instant_Timescale* _con5752 = kk_std_time_instant__as_Timescale(_pat210);
  kk_string_t _pat300 = _con5752->name;
  kk_string_t _pat400 = _con5752->unit;
  kk_function_t _pat50 = _con5752->from_tai;
  kk_function_t _pat60 = _con5752->to_tai;
  kk_std_core_types__maybe _pat70 = _con5752->mb_seconds_in_day;
  kk_std_core_types__maybe _pat80 = _con5752->mb_to_mjd2000;
  kk_std_core_types__maybe _pat90 = _con5752->mb_from_mjd2000;
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
  _x5750 = _x0; /*std/time/timestamp/timespan*/
  kk_std_num_ddouble__ddouble _x5753 = kk_std_num_ddouble__lp__tilde__rp_(secs, _ctx); /*std/num/ddouble/ddouble*/
  frac = kk_std_num_ddouble__lp__plus__rp_(_x5750, _x5753, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_core_types__tuple2_ _match_5272;
  kk_integer_t _x5754 = kk_std_num_ddouble_int(secs, kk_std_core_types__new_None(_ctx), _ctx); /*int*/
  _match_5272 = kk_integer_div_mod_tuple(_x5754,(kk_integer_from_int(86400, _ctx)),kk_context()); /*(int, int)*/
  kk_box_t _box_x4809 = _match_5272.fst;
  kk_box_t _box_x4810 = _match_5272.snd;
  kk_integer_t days0 = kk_integer_unbox(_box_x4809);
  kk_integer_t dsecs = kk_integer_unbox(_box_x4810);
  kk_integer_dup(days0);
  kk_integer_dup(dsecs);
  kk_std_core_types__tuple2__drop(_match_5272, _ctx);
  kk_std_num_ddouble__ddouble _b_4814_4812;
  kk_std_num_ddouble__ddouble _x5757 = kk_std_num_ddouble_ddouble_1(dsecs, _ctx); /*std/num/ddouble/ddouble*/
  _b_4814_4812 = kk_std_num_ddouble__lp__plus__rp_(_x5757, frac, _ctx); /*std/num/ddouble/ddouble*/
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
  kk_std_time_timestamp__timestamp _x5760;
  struct kk_std_time_instant_Instant* _con5761 = kk_std_time_instant__as_Instant(i);
  kk_std_time_timestamp__timestamp _x = _con5761->since;
  kk_std_time_instant__timescale _pat20 = _con5761->ts;
  struct kk_std_time_instant_Timescale* _con5762 = kk_std_time_instant__as_Timescale(_pat20);
  _x5760 = _x; /*std/time/timestamp/timestamp*/
  _match_5271 = kk_std_time_timestamp_days_seconds(_x5760, _ctx); /*(int, std/num/ddouble/ddouble)*/
  kk_box_t _box_x4817 = _match_5271.fst;
  kk_box_t _box_x4818 = _match_5271.snd;
  kk_integer_t days0 = kk_integer_unbox(_box_x4817);
  kk_std_num_ddouble__ddouble secs = kk_std_num_ddouble__ddouble_unbox(_box_x4818, NULL);
  kk_integer_dup(days0);
  kk_std_core_types__tuple2__drop(_match_5271, _ctx);
  kk_std_time_date__clock _b_4822_4820;
  kk_integer_t _x5765;
  kk_std_time_timestamp__timestamp _x5766;
  struct kk_std_time_instant_Instant* _con5767 = kk_std_time_instant__as_Instant(i);
  kk_std_time_timestamp__timestamp _x0 = _con5767->since;
  kk_std_time_instant__timescale _pat200 = _con5767->ts;
  struct kk_std_time_instant_Timescale* _con5768 = kk_std_time_instant__as_Timescale(_pat200);
  kk_string_t _pat30 = _con5768->name;
  kk_string_t _pat40 = _con5768->unit;
  kk_function_t _pat50 = _con5768->from_tai;
  kk_function_t _pat60 = _con5768->to_tai;
  kk_std_core_types__maybe _pat70 = _con5768->mb_seconds_in_day;
  kk_std_core_types__maybe _pat80 = _con5768->mb_to_mjd2000;
  kk_std_core_types__maybe _pat90 = _con5768->mb_from_mjd2000;
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
  _x5766 = _x0; /*std/time/timestamp/timestamp*/
  _x5765 = kk_std_time_timestamp_leap(_x5766, _ctx); /*int*/
  _b_4822_4820 = kk_std_time_date_clock_3(secs, _x5765, _ctx); /*std/time/date/clock*/
  return kk_std_core_types__new_dash__lp__comma__rp_(kk_integer_box(days0), kk_std_time_date__clock_box(_b_4822_4820, _ctx), _ctx);
}

kk_std_time_instant__instant kk_std_time_instant_epoch;

kk_std_time_duration__duration kk_std_time_instant_gps2000;
 
// Create an instant from a raw GPS time since the GPS epoch (1980-01-06Z)

kk_std_time_instant__instant kk_std_time_instant_gps_instant(kk_std_time_duration__duration gps, kk_context_t* _ctx) { /* (gps : std/time/duration/duration) -> instant */ 
  kk_std_time_duration__duration d_4590;
  kk_std_time_duration__duration e_4737 = kk_std_time_duration_duration_1(kk_integer_from_int(630720000, _ctx), kk_std_core_types__new_None(_ctx), _ctx); /*std/time/duration/duration*/;
  kk_std_time_duration__duration e0_2276 = kk_std_time_duration__lp__tilde__rp_(e_4737, _ctx); /*std/time/duration/duration*/;
  kk_std_num_ddouble__ddouble _x5769;
  kk_std_num_ddouble__ddouble _x5770;
  kk_std_num_ddouble__ddouble _x = gps.secs;
  _x5770 = _x; /*std/time/timestamp/timespan*/
  kk_std_num_ddouble__ddouble _x5771;
  kk_std_num_ddouble__ddouble _x0 = e0_2276.secs;
  _x5771 = _x0; /*std/time/timestamp/timespan*/
  _x5769 = kk_std_num_ddouble__lp__plus__rp_(_x5770, _x5771, _ctx); /*std/num/ddouble/ddouble*/
  d_4590 = kk_std_time_duration__new_Duration(_x5769, _ctx); /*std/time/duration/duration*/
  kk_std_time_timestamp__timestamp t_4592 = kk_std_time_duration_timestamp(d_4590, _ctx); /*std/time/timestamp/timestamp*/;
  kk_std_time_instant__timescale _x5772 = kk_std_time_instant__timescale_dup(kk_std_time_instant_ts_tai); /*std/time/instant/timescale*/
  return kk_std_time_instant__new_Instant(kk_reuse_null, t_4592, _x5772, _ctx);
}
 
// Create an instant from a GPS time in weeks and SI seconds since the GPS epoch (1980-01-06Z)

kk_std_time_instant__instant kk_std_time_instant_gps_instant_1(kk_integer_t weeks, kk_std_time_duration__duration secs, kk_context_t* _ctx) { /* (weeks : int, secs : std/time/duration/duration) -> instant */ 
  kk_std_time_duration__duration gps_4593;
  kk_std_time_duration__duration d0_4594;
  kk_integer_t _x5773 = kk_integer_mul(weeks,(kk_integer_from_int(25200, _ctx)),kk_context()); /*int*/
  d0_4594 = kk_std_time_duration_duration_1(_x5773, kk_std_core_types__new_None(_ctx), _ctx); /*std/time/duration/duration*/
  kk_std_num_ddouble__ddouble _x5774;
  kk_std_num_ddouble__ddouble _x5775;
  kk_std_num_ddouble__ddouble _x = d0_4594.secs;
  _x5775 = _x; /*std/time/timestamp/timespan*/
  kk_std_num_ddouble__ddouble _x5776;
  kk_std_num_ddouble__ddouble _x0 = secs.secs;
  _x5776 = _x0; /*std/time/timestamp/timespan*/
  _x5774 = kk_std_num_ddouble__lp__plus__rp_(_x5775, _x5776, _ctx); /*std/num/ddouble/ddouble*/
  gps_4593 = kk_std_time_duration__new_Duration(_x5774, _ctx); /*std/time/duration/duration*/
  kk_std_time_duration__duration d_4596;
  kk_std_time_duration__duration e_4739 = kk_std_time_duration_duration_1(kk_integer_from_int(630720000, _ctx), kk_std_core_types__new_None(_ctx), _ctx); /*std/time/duration/duration*/;
  kk_std_time_duration__duration e0_2276 = kk_std_time_duration__lp__tilde__rp_(e_4739, _ctx); /*std/time/duration/duration*/;
  kk_std_num_ddouble__ddouble _x5777;
  kk_std_num_ddouble__ddouble _x5778;
  kk_std_num_ddouble__ddouble _x1 = gps_4593.secs;
  _x5778 = _x1; /*std/time/timestamp/timespan*/
  kk_std_num_ddouble__ddouble _x5779;
  kk_std_num_ddouble__ddouble _x00 = e0_2276.secs;
  _x5779 = _x00; /*std/time/timestamp/timespan*/
  _x5777 = kk_std_num_ddouble__lp__plus__rp_(_x5778, _x5779, _ctx); /*std/num/ddouble/ddouble*/
  d_4596 = kk_std_time_duration__new_Duration(_x5777, _ctx); /*std/time/duration/duration*/
  kk_std_time_timestamp__timestamp t_4598 = kk_std_time_duration_timestamp(d_4596, _ctx); /*std/time/timestamp/timestamp*/;
  kk_std_time_instant__timescale _x5780 = kk_std_time_instant__timescale_dup(kk_std_time_instant_ts_tai); /*std/time/instant/timescale*/
  return kk_std_time_instant__new_Instant(kk_reuse_null, t_4598, _x5780, _ctx);
}
 
// The [GPS](https://en.wikipedia.org/wiki/Global_Positioning_System#Timekeeping) time scale based
// on SI seconds with a 1980-01-06 GPS epoch.
// GPS = TAI - 19s.


// lift anonymous function
struct kk_std_time_instant_ts_gps_fun5792__t {
  struct kk_function_s _base;
  kk_std_time_duration__duration _offset_990;
};
static kk_std_time_timestamp__timestamp kk_std_time_instant_ts_gps_fun5792(kk_function_t _fself, kk_std_time_duration__duration tai, kk_context_t* _ctx);
static kk_function_t kk_std_time_instant_new_ts_gps_fun5792(kk_std_time_duration__duration _offset_990, kk_context_t* _ctx) {
  struct kk_std_time_instant_ts_gps_fun5792__t* _self = kk_function_alloc_as(struct kk_std_time_instant_ts_gps_fun5792__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_time_instant_ts_gps_fun5792, kk_context());
  _self->_offset_990 = _offset_990;
  return &_self->_base;
}

static kk_std_time_timestamp__timestamp kk_std_time_instant_ts_gps_fun5792(kk_function_t _fself, kk_std_time_duration__duration tai, kk_context_t* _ctx) {
  struct kk_std_time_instant_ts_gps_fun5792__t* _self = kk_function_as(struct kk_std_time_instant_ts_gps_fun5792__t*, _fself);
  kk_std_time_duration__duration _offset_990 = _self->_offset_990; /* std/time/duration/duration */
  kk_drop_match(_self, {kk_std_time_duration__duration_dup(_offset_990);}, {}, _ctx)
  kk_std_num_ddouble__ddouble t_4609;
  kk_std_num_ddouble__ddouble _x5793;
  kk_std_num_ddouble__ddouble _x0 = tai.secs;
  _x5793 = _x0; /*std/time/timestamp/timespan*/
  kk_std_num_ddouble__ddouble _x5794;
  kk_std_num_ddouble__ddouble _x = _offset_990.secs;
  _x5794 = _x; /*std/time/timestamp/timespan*/
  t_4609 = kk_std_num_ddouble__lp__plus__rp_(_x5793, _x5794, _ctx); /*std/time/timestamp/timespan*/
  int32_t _x5795;
  kk_integer_t _x5796;
  kk_std_core_types__optional _match_5270 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
  if (kk_std_core_types__is_Optional(_match_5270)) {
    kk_box_t _box_x4829 = _match_5270._cons.Optional.value;
    kk_integer_t _leap_492 = kk_integer_unbox(_box_x4829);
    kk_integer_dup(_leap_492);
    kk_std_core_types__optional_drop(_match_5270, _ctx);
    _x5796 = _leap_492; /*int*/
    goto _match5797;
  }
  _x5796 = kk_integer_from_small(0); /*int*/
  _match5797: ;
  _x5795 = kk_std_core_int32(_x5796, _ctx); /*int32*/
  return kk_std_time_timestamp__new_Timestamp(t_4609, _x5795, _ctx);
}


// lift anonymous function
struct kk_std_time_instant_ts_gps_fun5799__t {
  struct kk_function_s _base;
  kk_std_time_duration__duration _offset_990;
};
static kk_std_time_duration__duration kk_std_time_instant_ts_gps_fun5799(kk_function_t _fself, kk_std_time_timestamp__timestamp t0, kk_context_t* _ctx);
static kk_function_t kk_std_time_instant_new_ts_gps_fun5799(kk_std_time_duration__duration _offset_990, kk_context_t* _ctx) {
  struct kk_std_time_instant_ts_gps_fun5799__t* _self = kk_function_alloc_as(struct kk_std_time_instant_ts_gps_fun5799__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_time_instant_ts_gps_fun5799, kk_context());
  _self->_offset_990 = _offset_990;
  return &_self->_base;
}

static kk_std_time_duration__duration kk_std_time_instant_ts_gps_fun5799(kk_function_t _fself, kk_std_time_timestamp__timestamp t0, kk_context_t* _ctx) {
  struct kk_std_time_instant_ts_gps_fun5799__t* _self = kk_function_as(struct kk_std_time_instant_ts_gps_fun5799__t*, _fself);
  kk_std_time_duration__duration _offset_990 = _self->_offset_990; /* std/time/duration/duration */
  kk_drop_match(_self, {kk_std_time_duration__duration_dup(_offset_990);}, {}, _ctx)
  kk_std_time_timestamp__timestamp t1_4612;
  kk_std_num_ddouble__ddouble _x5800;
  kk_std_num_ddouble__ddouble _x1 = _offset_990.secs;
  _x5800 = _x1; /*std/time/timestamp/timespan*/
  t1_4612 = kk_std_time_timestamp__lp__dash__rp_(t0, _x5800, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_num_ddouble__ddouble _x5801 = kk_std_time_timestamp_unsafe_timespan_withleap(t1_4612, _ctx); /*std/time/timestamp/timespan*/
  return kk_std_time_duration__new_Duration(_x5801, _ctx);
}

kk_std_time_instant__timescale kk_std_time_instant_ts_gps;
 
// Get the GPS time in SI seconds since the GPS epoch (1980-01-06Z)

kk_std_time_duration__duration kk_std_time_instant_gps_timestamp(kk_std_time_instant__instant i, kk_context_t* _ctx) { /* (i : instant) -> std/time/duration/duration */ 
  kk_std_time_duration__duration d_4613;
  kk_std_time_timestamp__timestamp t_4615;
  kk_std_time_instant__timescale _x5811 = kk_std_time_instant__timescale_dup(kk_std_time_instant_ts_gps); /*std/time/instant/timescale*/
  t_4615 = kk_std_time_instant_timestamp_in(i, _x5811, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_num_ddouble__ddouble _x5812 = kk_std_time_timestamp_unsafe_timespan_withleap(t_4615, _ctx); /*std/time/timestamp/timespan*/
  d_4613 = kk_std_time_duration__new_Duration(_x5812, _ctx); /*std/time/duration/duration*/
  kk_std_time_duration__duration e_4614 = kk_std_time_duration_duration_1(kk_integer_from_int(630720000, _ctx), kk_std_core_types__new_None(_ctx), _ctx); /*std/time/duration/duration*/;
  kk_std_num_ddouble__ddouble _x5813;
  kk_std_num_ddouble__ddouble _x5814;
  kk_std_num_ddouble__ddouble _x = d_4613.secs;
  _x5814 = _x; /*std/time/timestamp/timespan*/
  kk_std_num_ddouble__ddouble _x5815;
  kk_std_num_ddouble__ddouble _x0 = e_4614.secs;
  _x5815 = _x0; /*std/time/timestamp/timespan*/
  _x5813 = kk_std_num_ddouble__lp__plus__rp_(_x5814, _x5815, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_time_duration__new_Duration(_x5813, _ctx);
}
 
// Get the GPS time as weeks and SI seconds in the week since the GPS epoch (1980-01-06Z)

kk_std_core_types__tuple2_ kk_std_time_instant_gps_week_timestamp(kk_std_time_instant__instant i, kk_context_t* _ctx) { /* (i : instant) -> (int, std/time/duration/duration) */ 
  kk_std_time_duration__duration t = kk_std_time_instant_gps_timestamp(i, _ctx); /*std/time/duration/duration*/;
  kk_integer_t w;
  kk_std_num_ddouble__ddouble _x5816;
  kk_std_num_ddouble__ddouble _x5817;
  kk_std_num_ddouble__ddouble _x5818;
  kk_std_num_ddouble__ddouble _x = t.secs;
  _x5818 = _x; /*std/time/timestamp/timespan*/
  kk_std_num_ddouble__ddouble _x5819 = kk_std_num_ddouble_ddouble_int_exp(kk_integer_from_int(25200, _ctx), kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
  _x5817 = kk_std_num_ddouble__lp__fs__rp_(_x5818, _x5819, _ctx); /*std/num/ddouble/ddouble*/
  _x5816 = kk_std_num_ddouble_floor(_x5817, _ctx); /*std/num/ddouble/ddouble*/
  w = kk_std_num_ddouble_int(_x5816, kk_std_core_types__new_None(_ctx), _ctx); /*int*/
  kk_std_time_duration__duration s;
  kk_std_time_duration__duration e_4619;
  kk_integer_t _x5820;
  kk_integer_t _x5821 = kk_integer_dup(w); /*int*/
  _x5820 = kk_integer_mul(_x5821,(kk_integer_from_int(25200, _ctx)),kk_context()); /*int*/
  e_4619 = kk_std_time_duration_duration_1(_x5820, kk_std_core_types__new_None(_ctx), _ctx); /*std/time/duration/duration*/
  kk_std_time_duration__duration e0_2276 = kk_std_time_duration__lp__tilde__rp_(e_4619, _ctx); /*std/time/duration/duration*/;
  kk_std_num_ddouble__ddouble _x5822;
  kk_std_num_ddouble__ddouble _x5823;
  kk_std_num_ddouble__ddouble _x0 = t.secs;
  _x5823 = _x0; /*std/time/timestamp/timespan*/
  kk_std_num_ddouble__ddouble _x5824;
  kk_std_num_ddouble__ddouble _x00 = e0_2276.secs;
  _x5824 = _x00; /*std/time/timestamp/timespan*/
  _x5822 = kk_std_num_ddouble__lp__plus__rp_(_x5823, _x5824, _ctx); /*std/num/ddouble/ddouble*/
  s = kk_std_time_duration__new_Duration(_x5822, _ctx); /*std/time/duration/duration*/
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
  struct kk_std_time_instant_Timescale* _con5825 = kk_std_time_instant__as_Timescale(ts0);
  kk_std_core_types__maybe _x = _con5825->mb_from_mjd2000;
  kk_std_core_types__maybe_dup(_x);
  _match_5265 = _x; /*maybe<(days : int, frac : std/num/ddouble/ddouble) -> std/time/timestamp/timestamp>*/
  if (kk_std_core_types__is_Nothing(_match_5265)) {
    kk_std_num_ddouble__ddouble secs_4623 = kk_std_num_ddouble__lp__star__rp_(frac, kk_std_time_timestamp_solar_secs_per_day, _ctx); /*std/time/timestamp/timespan*/;
    kk_std_time_timestamp__timestamp t_4626;
    kk_std_core_types__optional _x5826 = kk_std_core_types__new_Optional(kk_std_num_ddouble__ddouble_box(secs_4623, _ctx), _ctx); /*optional<35>*/
    kk_std_core_types__optional _x5827;
    kk_box_t _x5828;
    kk_integer_t _x5829;
    kk_std_core_types__optional _match_5266 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
    if (kk_std_core_types__is_Optional(_match_5266)) {
      kk_box_t _box_x4838 = _match_5266._cons.Optional.value;
      kk_integer_t _leap_1630 = kk_integer_unbox(_box_x4838);
      kk_integer_dup(_leap_1630);
      kk_std_core_types__optional_drop(_match_5266, _ctx);
      _x5829 = _leap_1630; /*int*/
      goto _match5830;
    }
    _x5829 = kk_integer_from_small(0); /*int*/
    _match5830: ;
    _x5828 = kk_integer_box(_x5829); /*35*/
    _x5827 = kk_std_core_types__new_Optional(_x5828, _ctx); /*optional<35>*/
    t_4626 = kk_std_time_timestamp_timestamp_days(idays, _x5826, _x5827, _ctx); /*std/time/timestamp/timestamp*/
    return kk_std_time_instant__new_Instant(kk_reuse_null, t_4626, ts0, _ctx);
  }
  kk_box_t _fun_unbox_x4847 = _match_5265._cons.Just.value;
  kk_std_time_timestamp__timestamp t0_4628;
  kk_box_t _x5832;
  kk_function_t _x5833 = kk_function_unbox(_fun_unbox_x4847); /*(days : 4848, frac : 4849) -> 4850*/
  _x5832 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _x5833, (_x5833, kk_integer_box(idays), kk_std_num_ddouble__ddouble_box(frac, _ctx), _ctx)); /*4850*/
  t0_4628 = kk_std_time_timestamp__timestamp_unbox(_x5832, _ctx); /*std/time/timestamp/timestamp*/
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
  struct kk_std_time_instant_Timescale* _con5834 = kk_std_time_instant__as_Timescale(ts0);
  kk_std_core_types__maybe _x = _con5834->mb_from_mjd2000;
  kk_std_core_types__maybe_dup(_x);
  _match_5263 = _x; /*maybe<(days : int, frac : std/num/ddouble/ddouble) -> std/time/timestamp/timestamp>*/
  if (kk_std_core_types__is_Nothing(_match_5263)) {
    kk_std_num_ddouble__ddouble secs_4634 = kk_std_num_ddouble__lp__star__rp_(frac, kk_std_time_timestamp_solar_secs_per_day, _ctx); /*std/time/timestamp/timespan*/;
    kk_std_time_timestamp__timestamp t_4637;
    kk_std_core_types__optional _x5835 = kk_std_core_types__new_Optional(kk_std_num_ddouble__ddouble_box(secs_4634, _ctx), _ctx); /*optional<35>*/
    kk_std_core_types__optional _x5836;
    kk_box_t _x5837;
    kk_integer_t _x5838;
    kk_std_core_types__optional _match_5264 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
    if (kk_std_core_types__is_Optional(_match_5264)) {
      kk_box_t _box_x4856 = _match_5264._cons.Optional.value;
      kk_integer_t _leap_1630 = kk_integer_unbox(_box_x4856);
      kk_integer_dup(_leap_1630);
      kk_std_core_types__optional_drop(_match_5264, _ctx);
      _x5838 = _leap_1630; /*int*/
      goto _match5839;
    }
    _x5838 = kk_integer_from_small(0); /*int*/
    _match5839: ;
    _x5837 = kk_integer_box(_x5838); /*35*/
    _x5836 = kk_std_core_types__new_Optional(_x5837, _ctx); /*optional<35>*/
    t_4637 = kk_std_time_timestamp_timestamp_days(idays, _x5835, _x5836, _ctx); /*std/time/timestamp/timestamp*/
    return kk_std_time_instant__new_Instant(kk_reuse_null, t_4637, ts0, _ctx);
  }
  kk_box_t _fun_unbox_x4865 = _match_5263._cons.Just.value;
  kk_std_time_timestamp__timestamp t0_4639;
  kk_box_t _x5841;
  kk_function_t _x5842 = kk_function_unbox(_fun_unbox_x4865); /*(days : 4866, frac : 4867) -> 4868*/
  _x5841 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _x5842, (_x5842, kk_integer_box(idays), kk_std_num_ddouble__ddouble_box(frac, _ctx), _ctx)); /*4868*/
  t0_4639 = kk_std_time_timestamp__timestamp_unbox(_x5841, _ctx); /*std/time/timestamp/timestamp*/
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
  struct kk_std_time_instant_Timescale* _con5843 = kk_std_time_instant__as_Timescale(ts0);
  kk_std_core_types__maybe _x = _con5843->mb_from_mjd2000;
  kk_std_core_types__maybe_dup(_x);
  _match_5261 = _x; /*maybe<(days : int, frac : std/num/ddouble/ddouble) -> std/time/timestamp/timestamp>*/
  if (kk_std_core_types__is_Nothing(_match_5261)) {
    kk_std_num_ddouble__ddouble secs_4645 = kk_std_num_ddouble__lp__star__rp_(frac, kk_std_time_timestamp_solar_secs_per_day, _ctx); /*std/time/timestamp/timespan*/;
    kk_std_time_timestamp__timestamp t_4648;
    kk_std_core_types__optional _x5844 = kk_std_core_types__new_Optional(kk_std_num_ddouble__ddouble_box(secs_4645, _ctx), _ctx); /*optional<35>*/
    kk_std_core_types__optional _x5845;
    kk_box_t _x5846;
    kk_integer_t _x5847;
    kk_std_core_types__optional _match_5262 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
    if (kk_std_core_types__is_Optional(_match_5262)) {
      kk_box_t _box_x4874 = _match_5262._cons.Optional.value;
      kk_integer_t _leap_1630 = kk_integer_unbox(_box_x4874);
      kk_integer_dup(_leap_1630);
      kk_std_core_types__optional_drop(_match_5262, _ctx);
      _x5847 = _leap_1630; /*int*/
      goto _match5848;
    }
    _x5847 = kk_integer_from_small(0); /*int*/
    _match5848: ;
    _x5846 = kk_integer_box(_x5847); /*35*/
    _x5845 = kk_std_core_types__new_Optional(_x5846, _ctx); /*optional<35>*/
    t_4648 = kk_std_time_timestamp_timestamp_days(idays, _x5844, _x5845, _ctx); /*std/time/timestamp/timestamp*/
    return kk_std_time_instant__new_Instant(kk_reuse_null, t_4648, ts0, _ctx);
  }
  kk_box_t _fun_unbox_x4883 = _match_5261._cons.Just.value;
  kk_std_time_timestamp__timestamp t0_4650;
  kk_box_t _x5850;
  kk_function_t _x5851 = kk_function_unbox(_fun_unbox_x4883); /*(days : 4884, frac : 4885) -> 4886*/
  _x5850 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _x5851, (_x5851, kk_integer_box(idays), kk_std_num_ddouble__ddouble_box(frac, _ctx), _ctx)); /*4886*/
  t0_4650 = kk_std_time_timestamp__timestamp_unbox(_x5850, _ctx); /*std/time/timestamp/timestamp*/
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
  struct kk_std_time_instant_Timescale* _con5852 = kk_std_time_instant__as_Timescale(ts0);
  kk_std_core_types__maybe _x = _con5852->mb_from_mjd2000;
  kk_std_core_types__maybe_dup(_x);
  _match_5259 = _x; /*maybe<(days : int, frac : std/num/ddouble/ddouble) -> std/time/timestamp/timestamp>*/
  if (kk_std_core_types__is_Nothing(_match_5259)) {
    kk_std_num_ddouble__ddouble secs_4658 = kk_std_num_ddouble__lp__star__rp_(frac, kk_std_time_timestamp_solar_secs_per_day, _ctx); /*std/time/timestamp/timespan*/;
    kk_std_time_timestamp__timestamp t_4661;
    kk_std_core_types__optional _x5853 = kk_std_core_types__new_Optional(kk_std_num_ddouble__ddouble_box(secs_4658, _ctx), _ctx); /*optional<35>*/
    kk_std_core_types__optional _x5854;
    kk_box_t _x5855;
    kk_integer_t _x5856;
    kk_std_core_types__optional _match_5260 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
    if (kk_std_core_types__is_Optional(_match_5260)) {
      kk_box_t _box_x4892 = _match_5260._cons.Optional.value;
      kk_integer_t _leap_1630 = kk_integer_unbox(_box_x4892);
      kk_integer_dup(_leap_1630);
      kk_std_core_types__optional_drop(_match_5260, _ctx);
      _x5856 = _leap_1630; /*int*/
      goto _match5857;
    }
    _x5856 = kk_integer_from_small(0); /*int*/
    _match5857: ;
    _x5855 = kk_integer_box(_x5856); /*35*/
    _x5854 = kk_std_core_types__new_Optional(_x5855, _ctx); /*optional<35>*/
    t_4661 = kk_std_time_timestamp_timestamp_days(idays, _x5853, _x5854, _ctx); /*std/time/timestamp/timestamp*/
    return kk_std_time_instant__new_Instant(kk_reuse_null, t_4661, ts0, _ctx);
  }
  kk_box_t _fun_unbox_x4901 = _match_5259._cons.Just.value;
  kk_std_time_timestamp__timestamp t0_4663;
  kk_box_t _x5859;
  kk_function_t _x5860 = kk_function_unbox(_fun_unbox_x4901); /*(days : 4902, frac : 4903) -> 4904*/
  _x5859 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _x5860, (_x5860, kk_integer_box(idays), kk_std_num_ddouble__ddouble_box(frac, _ctx), _ctx)); /*4904*/
  t0_4663 = kk_std_time_timestamp__timestamp_unbox(_x5859, _ctx); /*std/time/timestamp/timestamp*/
  return kk_std_time_instant__new_Instant(kk_reuse_null, t0_4663, ts0, _ctx);
}
 
// Return the modified julian day in a given time scale `ts` for an instant `i`.
// Can also pass an optional `delta` (=`timespan0`) that is added to the raw timestamp of `i`
// before conversion (used in `std/time/time` to take timezones into account)

kk_std_num_ddouble__ddouble kk_std_time_instant_mjd(kk_std_time_instant__instant i, kk_std_time_instant__timescale tscale, kk_std_core_types__optional tzdelta, kk_context_t* _ctx) { /* (i : instant, tscale : timescale, tzdelta : optional<std/time/timestamp/timespan>) -> std/num/ddouble/ddouble */ 
  kk_std_time_instant__instant i0;
  kk_std_time_instant__timescale _x5861 = kk_std_time_instant__timescale_dup(tscale); /*std/time/instant/timescale*/
  i0 = kk_std_time_instant_use_timescale(i, _x5861, _ctx); /*std/time/instant/instant*/
  kk_std_num_ddouble__ddouble mjd0;
  kk_std_core_types__maybe _match_5256;
  struct kk_std_time_instant_Timescale* _con5862 = kk_std_time_instant__as_Timescale(tscale);
  kk_std_core_types__maybe _x = _con5862->mb_to_mjd2000;
  kk_std_core_types__maybe_dup(_x);
  _match_5256 = _x; /*maybe<(t : std/time/timestamp/timestamp, tzdelta : std/time/timestamp/timespan) -> std/num/ddouble/ddouble>*/
  if (kk_std_core_types__is_Nothing(_match_5256)) {
    kk_std_time_instant__instant i10;
    kk_std_num_ddouble__ddouble t_4667;
    if (kk_std_core_types__is_Optional(tzdelta)) {
      kk_box_t _box_x4909 = tzdelta._cons.Optional.value;
      kk_std_num_ddouble__ddouble _tzdelta_3557 = kk_std_num_ddouble__ddouble_unbox(_box_x4909, NULL);
      kk_std_core_types__optional_drop(tzdelta, _ctx);
      t_4667 = _tzdelta_3557; /*std/time/timestamp/timespan*/
      goto _match5863;
    }
    t_4667 = kk_std_num_ddouble__new_Ddouble(0x0p+0, 0x0p+0, _ctx); /*std/time/timestamp/timespan*/
    _match5863: ;
    kk_std_time_instant__instant i2_4668 = kk_std_time_instant_use_timescale(i0, tscale, _ctx); /*std/time/instant/instant*/;
    kk_std_time_timestamp__timestamp _x5865;
    kk_std_num_ddouble__ddouble _x5866;
    kk_std_num_ddouble__ddouble _x5867;
    kk_std_time_timestamp__timestamp _match_5258;
    struct kk_std_time_instant_Instant* _con5868 = kk_std_time_instant__as_Instant(i2_4668);
    kk_std_time_timestamp__timestamp _x1 = _con5868->since;
    kk_std_time_instant__timescale _pat21 = _con5868->ts;
    struct kk_std_time_instant_Timescale* _con5869 = kk_std_time_instant__as_Timescale(_pat21);
    _match_5258 = _x1; /*std/time/timestamp/timestamp*/
    kk_std_num_ddouble__ddouble _x0 = _match_5258.since;
    _x5867 = _x0; /*std/time/timestamp/timespan*/
    _x5866 = kk_std_num_ddouble__lp__plus__rp_(_x5867, t_4667, _ctx); /*std/num/ddouble/ddouble*/
    int32_t _x5870;
    kk_std_time_timestamp__timestamp _match_5257;
    struct kk_std_time_instant_Instant* _con5871 = kk_std_time_instant__as_Instant(i2_4668);
    kk_std_time_timestamp__timestamp _x10 = _con5871->since;
    kk_std_time_instant__timescale _pat210 = _con5871->ts;
    struct kk_std_time_instant_Timescale* _con5872 = kk_std_time_instant__as_Timescale(_pat210);
    _match_5257 = _x10; /*std/time/timestamp/timestamp*/
    kk_std_num_ddouble__ddouble _pat000 = _match_5257.since;
    int32_t _x00 = _match_5257.leap32;
    _x5870 = _x00; /*int32*/
    _x5865 = kk_std_time_timestamp__new_Timestamp(_x5866, _x5870, _ctx); /*std/time/timestamp/timestamp*/
    kk_std_time_instant__timescale _x5873;
    struct kk_std_time_instant_Instant* _con5874 = kk_std_time_instant__as_Instant(i2_4668);
    kk_std_time_timestamp__timestamp _pat02 = _con5874->since;
    kk_std_time_instant__timescale _x2 = _con5874->ts;
    struct kk_std_time_instant_Timescale* _con5875 = kk_std_time_instant__as_Timescale(_x2);
    if (kk_std_time_instant__instant_is_unique(i2_4668)) {
      kk_std_time_instant__instant_free(i2_4668);
    }
    else {
      kk_std_time_instant__timescale_dup(_x2);
      kk_std_time_instant__instant_decref(i2_4668, _ctx);
    }
    _x5873 = _x2; /*std/time/instant/timescale*/
    i10 = kk_std_time_instant__new_Instant(kk_reuse_null, _x5865, _x5873, _ctx); /*std/time/instant/instant*/
    kk_std_num_ddouble__ddouble days0;
    kk_integer_t i3_4674;
    kk_std_time_instant__instant _x5876 = kk_std_time_instant__instant_dup(i10); /*std/time/instant/instant*/
    i3_4674 = kk_std_time_instant_days(_x5876, _ctx); /*int*/
    days0 = kk_std_num_ddouble_ddouble_int_exp(i3_4674, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble frac;
    kk_std_num_ddouble__ddouble _x5877;
    kk_std_num_ddouble__ddouble _x5878;
    kk_std_core_types__tuple2_ _this_3811;
    kk_std_time_timestamp__timestamp _x5879;
    struct kk_std_time_instant_Instant* _con5880 = kk_std_time_instant__as_Instant(i10);
    kk_std_time_timestamp__timestamp _x4 = _con5880->since;
    kk_std_time_instant__timescale _pat23 = _con5880->ts;
    struct kk_std_time_instant_Timescale* _con5881 = kk_std_time_instant__as_Timescale(_pat23);
    _x5879 = _x4; /*std/time/timestamp/timestamp*/
    _this_3811 = kk_std_time_timestamp_days_seconds(_x5879, _ctx); /*(int, std/num/ddouble/ddouble)*/
    kk_box_t _box_x4910 = _this_3811.fst;
    kk_box_t _box_x4911 = _this_3811.snd;
    kk_std_num_ddouble__ddouble _x3 = kk_std_num_ddouble__ddouble_unbox(_box_x4911, NULL);
    kk_std_core_types__tuple2__drop(_this_3811, _ctx);
    _x5878 = _x3; /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble _x5884;
    kk_integer_t i_3812;
    kk_std_time_timestamp__timestamp _x5885;
    struct kk_std_time_instant_Instant* _con5886 = kk_std_time_instant__as_Instant(i10);
    kk_std_time_timestamp__timestamp _x40 = _con5886->since;
    kk_std_time_instant__timescale _pat230 = _con5886->ts;
    struct kk_std_time_instant_Timescale* _con5887 = kk_std_time_instant__as_Timescale(_pat230);
    kk_string_t _pat330 = _con5887->name;
    kk_string_t _pat420 = _con5887->unit;
    kk_function_t _pat520 = _con5887->from_tai;
    kk_function_t _pat620 = _con5887->to_tai;
    kk_std_core_types__maybe _pat720 = _con5887->mb_seconds_in_day;
    kk_std_core_types__maybe _pat810 = _con5887->mb_to_mjd2000;
    kk_std_core_types__maybe _pat910 = _con5887->mb_from_mjd2000;
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
    _x5885 = _x40; /*std/time/timestamp/timestamp*/
    i_3812 = kk_std_time_timestamp_leap(_x5885, _ctx); /*int*/
    _x5884 = kk_std_num_ddouble_ddouble_int_exp(i_3812, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
    _x5877 = kk_std_num_ddouble__lp__plus__rp_(_x5878, _x5884, _ctx); /*std/num/ddouble/ddouble*/
    frac = kk_std_num_ddouble__lp__fs__rp_(_x5877, kk_std_time_timestamp_solar_secs_per_day, _ctx); /*std/num/ddouble/ddouble*/
    mjd0 = kk_std_num_ddouble__lp__plus__rp_(days0, frac, _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    kk_box_t _fun_unbox_x4917 = _match_5256._cons.Just.value;
    kk_std_time_instant__timescale_dropn(tscale, ((int32_t)10), _ctx);
    kk_std_num_ddouble__ddouble _b_4925_4922;
    if (kk_std_core_types__is_Optional(tzdelta)) {
      kk_box_t _box_x4923 = tzdelta._cons.Optional.value;
      kk_std_num_ddouble__ddouble _tzdelta_35570 = kk_std_num_ddouble__ddouble_unbox(_box_x4923, NULL);
      kk_std_core_types__optional_drop(tzdelta, _ctx);
      _b_4925_4922 = _tzdelta_35570; /*std/time/timestamp/timespan*/
      goto _match5888;
    }
    _b_4925_4922 = kk_std_num_ddouble__new_Ddouble(0x0p+0, 0x0p+0, _ctx); /*std/time/timestamp/timespan*/
    _match5888: ;
    kk_box_t _x5890;
    kk_function_t _x5895 = kk_function_unbox(_fun_unbox_x4917); /*(t : 4918, tzdelta : 4919) -> 4920*/
    kk_box_t _x5891;
    kk_std_time_timestamp__timestamp _x5892;
    struct kk_std_time_instant_Instant* _con5893 = kk_std_time_instant__as_Instant(i0);
    kk_std_time_timestamp__timestamp _x5 = _con5893->since;
    kk_std_time_instant__timescale _pat25 = _con5893->ts;
    struct kk_std_time_instant_Timescale* _con5894 = kk_std_time_instant__as_Timescale(_pat25);
    kk_string_t _pat34 = _con5894->name;
    kk_string_t _pat43 = _con5894->unit;
    kk_function_t _pat53 = _con5894->from_tai;
    kk_function_t _pat63 = _con5894->to_tai;
    kk_std_core_types__maybe _pat73 = _con5894->mb_seconds_in_day;
    kk_std_core_types__maybe _pat82 = _con5894->mb_to_mjd2000;
    kk_std_core_types__maybe _pat92 = _con5894->mb_from_mjd2000;
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
    _x5892 = _x5; /*std/time/timestamp/timestamp*/
    _x5891 = kk_std_time_timestamp__timestamp_box(_x5892, _ctx); /*4918*/
    _x5890 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _x5895, (_x5895, _x5891, kk_std_num_ddouble__ddouble_box(_b_4925_4922, _ctx), _ctx)); /*4920*/
    mjd0 = kk_std_num_ddouble__ddouble_unbox(_x5890, _ctx); /*std/num/ddouble/ddouble*/
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
  kk_std_num_ddouble__ddouble _x5896;
  kk_std_time_instant__instant i00;
  kk_std_time_instant__timescale _x5897 = kk_std_time_instant__timescale_dup(ts0); /*std/time/instant/timescale*/
  i00 = kk_std_time_instant_use_timescale(i, _x5897, _ctx); /*std/time/instant/instant*/
  kk_std_num_ddouble__ddouble mjd0;
  kk_std_core_types__maybe _match_5251;
  struct kk_std_time_instant_Timescale* _con5898 = kk_std_time_instant__as_Timescale(ts0);
  kk_std_core_types__maybe _x = _con5898->mb_to_mjd2000;
  kk_std_core_types__maybe_dup(_x);
  _match_5251 = _x; /*maybe<(t : std/time/timestamp/timestamp, tzdelta : std/time/timestamp/timespan) -> std/num/ddouble/ddouble>*/
  if (kk_std_core_types__is_Nothing(_match_5251)) {
    kk_std_time_instant__instant i10;
    kk_std_num_ddouble__ddouble t_4667;
    kk_std_core_types__optional _match_5255 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
    if (kk_std_core_types__is_Optional(_match_5255)) {
      kk_box_t _box_x4926 = _match_5255._cons.Optional.value;
      kk_std_num_ddouble__ddouble _tzdelta_3557 = kk_std_num_ddouble__ddouble_unbox(_box_x4926, NULL);
      kk_std_core_types__optional_drop(_match_5255, _ctx);
      t_4667 = _tzdelta_3557; /*std/time/timestamp/timespan*/
      goto _match5899;
    }
    t_4667 = kk_std_num_ddouble__new_Ddouble(0x0p+0, 0x0p+0, _ctx); /*std/time/timestamp/timespan*/
    _match5899: ;
    kk_std_time_instant__instant i2_4668 = kk_std_time_instant_use_timescale(i00, ts0, _ctx); /*std/time/instant/instant*/;
    kk_std_time_timestamp__timestamp _x5901;
    kk_std_num_ddouble__ddouble _x5902;
    kk_std_num_ddouble__ddouble _x5903;
    kk_std_time_timestamp__timestamp _match_5254;
    struct kk_std_time_instant_Instant* _con5904 = kk_std_time_instant__as_Instant(i2_4668);
    kk_std_time_timestamp__timestamp _x1 = _con5904->since;
    kk_std_time_instant__timescale _pat21 = _con5904->ts;
    struct kk_std_time_instant_Timescale* _con5905 = kk_std_time_instant__as_Timescale(_pat21);
    _match_5254 = _x1; /*std/time/timestamp/timestamp*/
    kk_std_num_ddouble__ddouble _x0 = _match_5254.since;
    _x5903 = _x0; /*std/time/timestamp/timespan*/
    _x5902 = kk_std_num_ddouble__lp__plus__rp_(_x5903, t_4667, _ctx); /*std/num/ddouble/ddouble*/
    int32_t _x5906;
    kk_std_time_timestamp__timestamp _match_5253;
    struct kk_std_time_instant_Instant* _con5907 = kk_std_time_instant__as_Instant(i2_4668);
    kk_std_time_timestamp__timestamp _x10 = _con5907->since;
    kk_std_time_instant__timescale _pat210 = _con5907->ts;
    struct kk_std_time_instant_Timescale* _con5908 = kk_std_time_instant__as_Timescale(_pat210);
    _match_5253 = _x10; /*std/time/timestamp/timestamp*/
    kk_std_num_ddouble__ddouble _pat000 = _match_5253.since;
    int32_t _x00 = _match_5253.leap32;
    _x5906 = _x00; /*int32*/
    _x5901 = kk_std_time_timestamp__new_Timestamp(_x5902, _x5906, _ctx); /*std/time/timestamp/timestamp*/
    kk_std_time_instant__timescale _x5909;
    struct kk_std_time_instant_Instant* _con5910 = kk_std_time_instant__as_Instant(i2_4668);
    kk_std_time_timestamp__timestamp _pat02 = _con5910->since;
    kk_std_time_instant__timescale _x2 = _con5910->ts;
    struct kk_std_time_instant_Timescale* _con5911 = kk_std_time_instant__as_Timescale(_x2);
    if (kk_std_time_instant__instant_is_unique(i2_4668)) {
      kk_std_time_instant__instant_free(i2_4668);
    }
    else {
      kk_std_time_instant__timescale_dup(_x2);
      kk_std_time_instant__instant_decref(i2_4668, _ctx);
    }
    _x5909 = _x2; /*std/time/instant/timescale*/
    i10 = kk_std_time_instant__new_Instant(kk_reuse_null, _x5901, _x5909, _ctx); /*std/time/instant/instant*/
    kk_std_num_ddouble__ddouble days0;
    kk_integer_t i3_4674;
    kk_std_time_instant__instant _x5912 = kk_std_time_instant__instant_dup(i10); /*std/time/instant/instant*/
    i3_4674 = kk_std_time_instant_days(_x5912, _ctx); /*int*/
    days0 = kk_std_num_ddouble_ddouble_int_exp(i3_4674, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble frac;
    kk_std_num_ddouble__ddouble _x5913;
    kk_std_num_ddouble__ddouble _x5914;
    kk_std_core_types__tuple2_ _this_3811;
    kk_std_time_timestamp__timestamp _x5915;
    struct kk_std_time_instant_Instant* _con5916 = kk_std_time_instant__as_Instant(i10);
    kk_std_time_timestamp__timestamp _x4 = _con5916->since;
    kk_std_time_instant__timescale _pat23 = _con5916->ts;
    struct kk_std_time_instant_Timescale* _con5917 = kk_std_time_instant__as_Timescale(_pat23);
    _x5915 = _x4; /*std/time/timestamp/timestamp*/
    _this_3811 = kk_std_time_timestamp_days_seconds(_x5915, _ctx); /*(int, std/num/ddouble/ddouble)*/
    kk_box_t _box_x4927 = _this_3811.fst;
    kk_box_t _box_x4928 = _this_3811.snd;
    kk_std_num_ddouble__ddouble _x3 = kk_std_num_ddouble__ddouble_unbox(_box_x4928, NULL);
    kk_std_core_types__tuple2__drop(_this_3811, _ctx);
    _x5914 = _x3; /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble _x5920;
    kk_integer_t i_3812;
    kk_std_time_timestamp__timestamp _x5921;
    struct kk_std_time_instant_Instant* _con5922 = kk_std_time_instant__as_Instant(i10);
    kk_std_time_timestamp__timestamp _x40 = _con5922->since;
    kk_std_time_instant__timescale _pat230 = _con5922->ts;
    struct kk_std_time_instant_Timescale* _con5923 = kk_std_time_instant__as_Timescale(_pat230);
    kk_string_t _pat330 = _con5923->name;
    kk_string_t _pat420 = _con5923->unit;
    kk_function_t _pat520 = _con5923->from_tai;
    kk_function_t _pat620 = _con5923->to_tai;
    kk_std_core_types__maybe _pat720 = _con5923->mb_seconds_in_day;
    kk_std_core_types__maybe _pat810 = _con5923->mb_to_mjd2000;
    kk_std_core_types__maybe _pat910 = _con5923->mb_from_mjd2000;
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
    _x5921 = _x40; /*std/time/timestamp/timestamp*/
    i_3812 = kk_std_time_timestamp_leap(_x5921, _ctx); /*int*/
    _x5920 = kk_std_num_ddouble_ddouble_int_exp(i_3812, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
    _x5913 = kk_std_num_ddouble__lp__plus__rp_(_x5914, _x5920, _ctx); /*std/num/ddouble/ddouble*/
    frac = kk_std_num_ddouble__lp__fs__rp_(_x5913, kk_std_time_timestamp_solar_secs_per_day, _ctx); /*std/num/ddouble/ddouble*/
    mjd0 = kk_std_num_ddouble__lp__plus__rp_(days0, frac, _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    kk_box_t _fun_unbox_x4934 = _match_5251._cons.Just.value;
    kk_std_time_instant__timescale_dropn(ts0, ((int32_t)10), _ctx);
    kk_std_num_ddouble__ddouble _b_4942_4939;
    kk_std_core_types__optional _match_5252 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
    if (kk_std_core_types__is_Optional(_match_5252)) {
      kk_box_t _box_x4940 = _match_5252._cons.Optional.value;
      kk_std_num_ddouble__ddouble _tzdelta_35570 = kk_std_num_ddouble__ddouble_unbox(_box_x4940, NULL);
      kk_std_core_types__optional_drop(_match_5252, _ctx);
      _b_4942_4939 = _tzdelta_35570; /*std/time/timestamp/timespan*/
      goto _match5924;
    }
    _b_4942_4939 = kk_std_num_ddouble__new_Ddouble(0x0p+0, 0x0p+0, _ctx); /*std/time/timestamp/timespan*/
    _match5924: ;
    kk_box_t _x5926;
    kk_function_t _x5931 = kk_function_unbox(_fun_unbox_x4934); /*(t : 4935, tzdelta : 4936) -> 4937*/
    kk_box_t _x5927;
    kk_std_time_timestamp__timestamp _x5928;
    struct kk_std_time_instant_Instant* _con5929 = kk_std_time_instant__as_Instant(i00);
    kk_std_time_timestamp__timestamp _x5 = _con5929->since;
    kk_std_time_instant__timescale _pat25 = _con5929->ts;
    struct kk_std_time_instant_Timescale* _con5930 = kk_std_time_instant__as_Timescale(_pat25);
    kk_string_t _pat34 = _con5930->name;
    kk_string_t _pat43 = _con5930->unit;
    kk_function_t _pat53 = _con5930->from_tai;
    kk_function_t _pat63 = _con5930->to_tai;
    kk_std_core_types__maybe _pat73 = _con5930->mb_seconds_in_day;
    kk_std_core_types__maybe _pat82 = _con5930->mb_to_mjd2000;
    kk_std_core_types__maybe _pat92 = _con5930->mb_from_mjd2000;
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
    _x5928 = _x5; /*std/time/timestamp/timestamp*/
    _x5927 = kk_std_time_timestamp__timestamp_box(_x5928, _ctx); /*4935*/
    _x5926 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _x5931, (_x5931, _x5927, kk_std_num_ddouble__ddouble_box(_b_4942_4939, _ctx), _ctx)); /*4937*/
    mjd0 = kk_std_num_ddouble__ddouble_unbox(_x5926, _ctx); /*std/num/ddouble/ddouble*/
  }
  _x5896 = kk_std_num_ddouble__lp__plus__rp_(mjd0, kk_std_time_instant_mjd_epoch_delta, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__lp__plus__rp_(_x5896, kk_std_time_instant_jd_epoch_delta, _ctx);
}
 
// The maximum of two instants.

kk_std_time_instant__instant kk_std_time_instant_max(kk_std_time_instant__instant i, kk_std_time_instant__instant j, kk_context_t* _ctx) { /* (i : instant, j : instant) -> instant */ 
  bool _match_5250;
  kk_std_time_instant__instant _x5932 = kk_std_time_instant__instant_dup(i); /*std/time/instant/instant*/
  kk_std_time_instant__instant _x5933 = kk_std_time_instant__instant_dup(j); /*std/time/instant/instant*/
  _match_5250 = kk_std_time_instant__lp__gt__eq__rp_(_x5932, _x5933, _ctx); /*bool*/
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
  kk_std_time_instant__instant _x5934 = kk_std_time_instant__instant_dup(i); /*std/time/instant/instant*/
  kk_std_time_instant__instant _x5935 = kk_std_time_instant__instant_dup(j); /*std/time/instant/instant*/
  _match_5249 = kk_std_time_instant__lp__lt__eq__rp_(_x5934, _x5935, _ctx); /*bool*/
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
  kk_integer_t _x5936 = kk_integer_dup(prec); /*int*/
  _match_5234 = kk_std_core_is_neg_2(_x5936, _ctx); /*bool*/
  if (_match_5234) {
    kk_integer_drop(prec, _ctx);
    return i;
  }
  bool _match_5235;
  kk_std_core_types__maybe _match_5247;
  kk_std_time_instant__timescale _match_5248;
  struct kk_std_time_instant_Instant* _con5937 = kk_std_time_instant__as_Instant(i);
  kk_std_time_timestamp__timestamp _pat02 = _con5937->since;
  kk_std_time_instant__timescale _x0 = _con5937->ts;
  struct kk_std_time_instant_Timescale* _con5938 = kk_std_time_instant__as_Timescale(_x0);
  kk_std_time_instant__timescale_dup(_x0);
  _match_5248 = _x0; /*std/time/instant/timescale*/
  struct kk_std_time_instant_Timescale* _con5939 = kk_std_time_instant__as_Timescale(_match_5248);
  kk_string_t _pat01 = _con5939->name;
  kk_string_t _pat10 = _con5939->unit;
  kk_function_t _pat20 = _con5939->from_tai;
  kk_function_t _pat3 = _con5939->to_tai;
  kk_std_core_types__maybe _x = _con5939->mb_seconds_in_day;
  kk_std_core_types__maybe _pat4 = _con5939->mb_to_mjd2000;
  kk_std_core_types__maybe _pat5 = _con5939->mb_from_mjd2000;
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
    kk_std_time_timestamp__timestamp _x5940;
    kk_std_time_timestamp__timestamp t_4684;
    kk_std_time_instant__instant instant1_4686;
    kk_std_time_instant__instant _x5941 = kk_std_time_instant__instant_dup(i); /*std/time/instant/instant*/
    kk_std_time_instant__timescale _x5942 = kk_std_time_instant__timescale_dup(kk_std_time_instant_ts_tai); /*std/time/instant/timescale*/
    instant1_4686 = kk_std_time_instant_use_timescale(_x5941, _x5942, _ctx); /*std/time/instant/instant*/
    struct kk_std_time_instant_Instant* _con5943 = kk_std_time_instant__as_Instant(instant1_4686);
    kk_std_time_timestamp__timestamp _x7 = _con5943->since;
    kk_std_time_instant__timescale _pat28 = _con5943->ts;
    struct kk_std_time_instant_Timescale* _con5944 = kk_std_time_instant__as_Timescale(_pat28);
    kk_string_t _pat37 = _con5944->name;
    kk_string_t _pat45 = _con5944->unit;
    kk_function_t _pat54 = _con5944->from_tai;
    kk_function_t _pat62 = _con5944->to_tai;
    kk_std_core_types__maybe _pat71 = _con5944->mb_seconds_in_day;
    kk_std_core_types__maybe _pat81 = _con5944->mb_to_mjd2000;
    kk_std_core_types__maybe _pat91 = _con5944->mb_from_mjd2000;
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
    kk_std_num_ddouble__ddouble _x5945;
    bool _match_5245;
    kk_integer_t _x5946 = kk_integer_dup(prec); /*int*/
    _match_5245 = kk_integer_lte(_x5946,(kk_integer_from_small(0)),kk_context()); /*bool*/
    if (_match_5245) {
      kk_integer_drop(prec, _ctx);
      kk_std_num_ddouble__ddouble _x5947;
      kk_std_num_ddouble__ddouble _x4 = t_4684.since;
      _x5947 = _x4; /*std/time/timestamp/timespan*/
      _x5945 = kk_std_num_ddouble_round(_x5947, _ctx); /*std/num/ddouble/ddouble*/
    }
    else {
      bool _match_5246;
      kk_integer_t _x5948 = kk_integer_dup(prec); /*int*/
      _match_5246 = kk_integer_gt(_x5948,(kk_integer_from_small(31)),kk_context()); /*bool*/
      if (_match_5246) {
        kk_integer_drop(prec, _ctx);
        kk_std_num_ddouble__ddouble _x5 = t_4684.since;
        _x5945 = _x5; /*std/num/ddouble/ddouble*/
      }
      else {
        kk_std_num_ddouble__ddouble p = kk_std_num_ddouble_powi10(prec, _ctx); /*std/num/ddouble/ddouble*/;
        kk_std_num_ddouble__ddouble _x5949;
        kk_std_num_ddouble__ddouble _x5950;
        kk_std_num_ddouble__ddouble _x5951;
        kk_std_num_ddouble__ddouble _x6 = t_4684.since;
        _x5951 = _x6; /*std/time/timestamp/timespan*/
        _x5950 = kk_std_num_ddouble__lp__star__rp_(_x5951, p, _ctx); /*std/num/ddouble/ddouble*/
        _x5949 = kk_std_num_ddouble_round(_x5950, _ctx); /*std/num/ddouble/ddouble*/
        _x5945 = kk_std_num_ddouble__lp__fs__rp_(_x5949, p, _ctx); /*std/num/ddouble/ddouble*/
      }
    }
    int32_t _x5952;
    kk_std_num_ddouble__ddouble _pat010 = t_4684.since;
    int32_t _x00 = t_4684.leap32;
    _x5952 = _x00; /*int32*/
    _x5940 = kk_std_time_timestamp__new_Timestamp(_x5945, _x5952, _ctx); /*std/time/timestamp/timestamp*/
    kk_std_time_instant__timescale _x5953 = kk_std_time_instant__timescale_dup(kk_std_time_instant_ts_tai); /*std/time/instant/timescale*/
    i0_4682 = kk_std_time_instant__new_Instant(kk_reuse_null, _x5940, _x5953, _ctx); /*std/time/instant/instant*/
    bool _match_5242;
    kk_string_t _x5954;
    kk_std_time_instant__timescale _match_5244;
    struct kk_std_time_instant_Instant* _con5955 = kk_std_time_instant__as_Instant(i0_4682);
    kk_std_time_timestamp__timestamp _pat04 = _con5955->since;
    kk_std_time_instant__timescale _x2 = _con5955->ts;
    struct kk_std_time_instant_Timescale* _con5956 = kk_std_time_instant__as_Timescale(_x2);
    kk_std_time_instant__timescale_dup(_x2);
    _match_5244 = _x2; /*std/time/instant/timescale*/
    struct kk_std_time_instant_Timescale* _con5957 = kk_std_time_instant__as_Timescale(_match_5244);
    kk_string_t _x1 = _con5957->name;
    kk_string_t _pat03 = _con5957->unit;
    kk_function_t _pat14 = _con5957->from_tai;
    kk_function_t _pat22 = _con5957->to_tai;
    kk_std_core_types__maybe _pat31 = _con5957->mb_seconds_in_day;
    kk_std_core_types__maybe _pat41 = _con5957->mb_to_mjd2000;
    kk_std_core_types__maybe _pat51 = _con5957->mb_from_mjd2000;
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
    _x5954 = _x1; /*string*/
    kk_string_t _x5958;
    kk_std_time_instant__timescale _match_5243;
    struct kk_std_time_instant_Instant* _con5959 = kk_std_time_instant__as_Instant(i);
    kk_std_time_timestamp__timestamp _pat09 = _con5959->since;
    kk_std_time_instant__timescale _x8 = _con5959->ts;
    struct kk_std_time_instant_Timescale* _con5960 = kk_std_time_instant__as_Timescale(_x8);
    kk_std_time_instant__timescale_dup(_x8);
    _match_5243 = _x8; /*std/time/instant/timescale*/
    struct kk_std_time_instant_Timescale* _con5961 = kk_std_time_instant__as_Timescale(_match_5243);
    kk_string_t _x3 = _con5961->name;
    kk_string_t _pat05 = _con5961->unit;
    kk_function_t _pat18 = _con5961->from_tai;
    kk_function_t _pat24 = _con5961->to_tai;
    kk_std_core_types__maybe _pat33 = _con5961->mb_seconds_in_day;
    kk_std_core_types__maybe _pat43 = _con5961->mb_to_mjd2000;
    kk_std_core_types__maybe _pat53 = _con5961->mb_from_mjd2000;
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
    _x5958 = _x3; /*string*/
    _match_5242 = kk_string_is_eq(_x5954,_x5958,kk_context()); /*bool*/
    if (_match_5242) {
      kk_std_time_instant__instant_dropn(i, ((int32_t)1), _ctx);
      return i0_4682;
    }
    kk_std_time_timestamp__timestamp _x5962;
    kk_std_time_instant__timescale _x5963;
    struct kk_std_time_instant_Instant* _con5964 = kk_std_time_instant__as_Instant(i);
    kk_std_time_timestamp__timestamp _pat090 = _con5964->since;
    kk_std_time_instant__timescale _x80 = _con5964->ts;
    struct kk_std_time_instant_Timescale* _con5965 = kk_std_time_instant__as_Timescale(_x80);
    kk_std_time_instant__timescale_dup(_x80);
    _x5963 = _x80; /*std/time/instant/timescale*/
    _x5962 = kk_std_time_instant_timestamp_in(i0_4682, _x5963, _ctx); /*std/time/timestamp/timestamp*/
    kk_std_time_instant__timescale _x5966;
    struct kk_std_time_instant_Instant* _con5967 = kk_std_time_instant__as_Instant(i);
    kk_std_time_timestamp__timestamp _pat091 = _con5967->since;
    kk_std_time_instant__timescale _x81 = _con5967->ts;
    struct kk_std_time_instant_Timescale* _con5968 = kk_std_time_instant__as_Timescale(_x81);
    if (kk_std_time_instant__instant_is_unique(i)) {
      kk_std_time_instant__instant_free(i);
    }
    else {
      kk_std_time_instant__timescale_dup(_x81);
      kk_std_time_instant__instant_decref(i, _ctx);
    }
    _x5966 = _x81; /*std/time/instant/timescale*/
    return kk_std_time_instant__new_Instant(kk_reuse_null, _x5962, _x5966, _ctx);
  }
  kk_std_time_timestamp__timestamp _x5969;
  kk_std_num_ddouble__ddouble _x5970;
  bool _match_5237;
  kk_integer_t _x5971 = kk_integer_dup(prec); /*int*/
  _match_5237 = kk_integer_lte(_x5971,(kk_integer_from_small(0)),kk_context()); /*bool*/
  if (_match_5237) {
    kk_integer_drop(prec, _ctx);
    kk_std_num_ddouble__ddouble _x5972;
    kk_std_time_timestamp__timestamp _match_5241;
    struct kk_std_time_instant_Instant* _con5973 = kk_std_time_instant__as_Instant(i);
    kk_std_time_timestamp__timestamp _x12 = _con5973->since;
    kk_std_time_instant__timescale _pat215 = _con5973->ts;
    struct kk_std_time_instant_Timescale* _con5974 = kk_std_time_instant__as_Timescale(_pat215);
    _match_5241 = _x12; /*std/time/timestamp/timestamp*/
    kk_std_num_ddouble__ddouble _x9 = _match_5241.since;
    _x5972 = _x9; /*std/time/timestamp/timespan*/
    _x5970 = kk_std_num_ddouble_round(_x5972, _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    bool _match_5238;
    kk_integer_t _x5975 = kk_integer_dup(prec); /*int*/
    _match_5238 = kk_integer_gt(_x5975,(kk_integer_from_small(31)),kk_context()); /*bool*/
    if (_match_5238) {
      kk_integer_drop(prec, _ctx);
      kk_std_time_timestamp__timestamp _match_5240;
      struct kk_std_time_instant_Instant* _con5976 = kk_std_time_instant__as_Instant(i);
      kk_std_time_timestamp__timestamp _x120 = _con5976->since;
      kk_std_time_instant__timescale _pat2150 = _con5976->ts;
      struct kk_std_time_instant_Timescale* _con5977 = kk_std_time_instant__as_Timescale(_pat2150);
      _match_5240 = _x120; /*std/time/timestamp/timestamp*/
      kk_std_num_ddouble__ddouble _x10 = _match_5240.since;
      _x5970 = _x10; /*std/num/ddouble/ddouble*/
    }
    else {
      kk_std_num_ddouble__ddouble p0 = kk_std_num_ddouble_powi10(prec, _ctx); /*std/num/ddouble/ddouble*/;
      kk_std_num_ddouble__ddouble _x5978;
      kk_std_num_ddouble__ddouble _x5979;
      kk_std_num_ddouble__ddouble _x5980;
      kk_std_time_timestamp__timestamp _match_5239;
      struct kk_std_time_instant_Instant* _con5981 = kk_std_time_instant__as_Instant(i);
      kk_std_time_timestamp__timestamp _x121 = _con5981->since;
      kk_std_time_instant__timescale _pat2151 = _con5981->ts;
      struct kk_std_time_instant_Timescale* _con5982 = kk_std_time_instant__as_Timescale(_pat2151);
      _match_5239 = _x121; /*std/time/timestamp/timestamp*/
      kk_std_num_ddouble__ddouble _x11 = _match_5239.since;
      _x5980 = _x11; /*std/time/timestamp/timespan*/
      _x5979 = kk_std_num_ddouble__lp__star__rp_(_x5980, p0, _ctx); /*std/num/ddouble/ddouble*/
      _x5978 = kk_std_num_ddouble_round(_x5979, _ctx); /*std/num/ddouble/ddouble*/
      _x5970 = kk_std_num_ddouble__lp__fs__rp_(_x5978, p0, _ctx); /*std/num/ddouble/ddouble*/
    }
  }
  int32_t _x5983;
  kk_std_time_timestamp__timestamp _match_5236;
  struct kk_std_time_instant_Instant* _con5984 = kk_std_time_instant__as_Instant(i);
  kk_std_time_timestamp__timestamp _x122 = _con5984->since;
  kk_std_time_instant__timescale _pat2152 = _con5984->ts;
  struct kk_std_time_instant_Timescale* _con5985 = kk_std_time_instant__as_Timescale(_pat2152);
  _match_5236 = _x122; /*std/time/timestamp/timestamp*/
  kk_std_num_ddouble__ddouble _pat012 = _match_5236.since;
  int32_t _x01 = _match_5236.leap32;
  _x5983 = _x01; /*int32*/
  _x5969 = kk_std_time_timestamp__new_Timestamp(_x5970, _x5983, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_time_instant__timescale _x5986;
  struct kk_std_time_instant_Instant* _con5987 = kk_std_time_instant__as_Instant(i);
  kk_std_time_timestamp__timestamp _pat014 = _con5987->since;
  kk_std_time_instant__timescale _x13 = _con5987->ts;
  struct kk_std_time_instant_Timescale* _con5988 = kk_std_time_instant__as_Timescale(_x13);
  if (kk_std_time_instant__instant_is_unique(i)) {
    kk_std_time_instant__instant_free(i);
  }
  else {
    kk_std_time_instant__timescale_dup(_x13);
    kk_std_time_instant__instant_decref(i, _ctx);
  }
  _x5986 = _x13; /*std/time/instant/timescale*/
  return kk_std_time_instant__new_Instant(kk_reuse_null, _x5969, _x5986, _ctx);
}
 
// Internal: show an instant as a raw timestamp in a given precision, postfixed with the time scale name.

kk_string_t kk_std_time_instant_show_raw(kk_std_time_instant__instant i, kk_std_core_types__optional max_prec, kk_std_core_types__optional secs_width, kk_std_core_types__optional unit0, kk_context_t* _ctx) { /* (i : instant, max-prec : optional<int>, secs-width : optional<int>, unit : optional<string>) -> string */ 
  kk_string_t _x5989;
  kk_std_time_timestamp__timestamp _x5990;
  struct kk_std_time_instant_Instant* _con5991 = kk_std_time_instant__as_Instant(i);
  kk_std_time_timestamp__timestamp _x = _con5991->since;
  kk_std_time_instant__timescale _pat2 = _con5991->ts;
  struct kk_std_time_instant_Timescale* _con5992 = kk_std_time_instant__as_Timescale(_pat2);
  _x5990 = _x; /*std/time/timestamp/timestamp*/
  kk_std_core_types__optional _x5993;
  kk_box_t _x5994;
  kk_integer_t _x5995;
  if (kk_std_core_types__is_Optional(max_prec)) {
    kk_box_t _box_x4943 = max_prec._cons.Optional.value;
    kk_integer_t _max_prec_4044 = kk_integer_unbox(_box_x4943);
    kk_integer_dup(_max_prec_4044);
    kk_std_core_types__optional_drop(max_prec, _ctx);
    _x5995 = _max_prec_4044; /*int*/
    goto _match5996;
  }
  _x5995 = kk_integer_from_small(9); /*int*/
  _match5996: ;
  _x5994 = kk_integer_box(_x5995); /*35*/
  _x5993 = kk_std_core_types__new_Optional(_x5994, _ctx); /*optional<35>*/
  kk_std_core_types__optional _x5998;
  kk_box_t _x5999;
  kk_integer_t _x6000;
  if (kk_std_core_types__is_Optional(secs_width)) {
    kk_box_t _box_x4945 = secs_width._cons.Optional.value;
    kk_integer_t _secs_width_4048 = kk_integer_unbox(_box_x4945);
    kk_integer_dup(_secs_width_4048);
    kk_std_core_types__optional_drop(secs_width, _ctx);
    _x6000 = _secs_width_4048; /*int*/
    goto _match6001;
  }
  _x6000 = kk_integer_from_small(1); /*int*/
  _match6001: ;
  _x5999 = kk_integer_box(_x6000); /*35*/
  _x5998 = kk_std_core_types__new_Optional(_x5999, _ctx); /*optional<35>*/
  kk_std_core_types__optional _x6003;
  kk_box_t _x6004;
  kk_string_t _x6005;
  if (kk_std_core_types__is_Optional(unit0)) {
    kk_box_t _box_x4947 = unit0._cons.Optional.value;
    kk_string_t _unit_4052 = kk_string_unbox(_box_x4947);
    kk_string_dup(_unit_4052);
    kk_std_core_types__optional_drop(unit0, _ctx);
    _x6005 = _unit_4052; /*string*/
    goto _match6006;
  }
  _x6005 = kk_string_empty(); /*string*/
  _match6006: ;
  _x6004 = kk_string_box(_x6005); /*35*/
  _x6003 = kk_std_core_types__new_Optional(_x6004, _ctx); /*optional<35>*/
  _x5989 = kk_std_time_timestamp_ts_show(_x5990, _x5993, _x5998, _x6003, _ctx); /*string*/
  kk_string_t _x6009;
  bool _match_5229;
  bool _match_5231;
  kk_string_t _x6010;
  kk_std_time_instant__timescale _match_5233;
  struct kk_std_time_instant_Instant* _con6011 = kk_std_time_instant__as_Instant(i);
  kk_std_time_timestamp__timestamp _pat02 = _con6011->since;
  kk_std_time_instant__timescale _x1 = _con6011->ts;
  struct kk_std_time_instant_Timescale* _con6012 = kk_std_time_instant__as_Timescale(_x1);
  kk_std_time_instant__timescale_dup(_x1);
  _match_5233 = _x1; /*std/time/instant/timescale*/
  struct kk_std_time_instant_Timescale* _con6013 = kk_std_time_instant__as_Timescale(_match_5233);
  kk_string_t _x0 = _con6013->name;
  kk_string_t _pat01 = _con6013->unit;
  kk_function_t _pat13 = _con6013->from_tai;
  kk_function_t _pat21 = _con6013->to_tai;
  kk_std_core_types__maybe _pat31 = _con6013->mb_seconds_in_day;
  kk_std_core_types__maybe _pat41 = _con6013->mb_to_mjd2000;
  kk_std_core_types__maybe _pat50 = _con6013->mb_from_mjd2000;
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
  _x6010 = _x0; /*string*/
  kk_string_t _x6014 = kk_string_empty(); /*string*/
  _match_5231 = kk_string_is_eq(_x6010,_x6014,kk_context()); /*bool*/
  if (_match_5231) {
    _match_5229 = true; /*bool*/
  }
  else {
    kk_string_t _x6016;
    kk_std_time_instant__timescale _match_5232;
    struct kk_std_time_instant_Instant* _con6017 = kk_std_time_instant__as_Instant(i);
    kk_std_time_timestamp__timestamp _pat04 = _con6017->since;
    kk_std_time_instant__timescale _x3 = _con6017->ts;
    struct kk_std_time_instant_Timescale* _con6018 = kk_std_time_instant__as_Timescale(_x3);
    kk_std_time_instant__timescale_dup(_x3);
    _match_5232 = _x3; /*std/time/instant/timescale*/
    struct kk_std_time_instant_Timescale* _con6019 = kk_std_time_instant__as_Timescale(_match_5232);
    kk_string_t _x2 = _con6019->name;
    kk_string_t _pat03 = _con6019->unit;
    kk_function_t _pat17 = _con6019->from_tai;
    kk_function_t _pat23 = _con6019->to_tai;
    kk_std_core_types__maybe _pat33 = _con6019->mb_seconds_in_day;
    kk_std_core_types__maybe _pat43 = _con6019->mb_to_mjd2000;
    kk_std_core_types__maybe _pat53 = _con6019->mb_from_mjd2000;
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
    _x6016 = _x2; /*string*/
    kk_string_t _x6020;
    kk_define_string_literal(, _s6021, 3, "TAI")
    _x6020 = kk_string_dup(_s6021); /*string*/
    _match_5229 = kk_string_is_eq(_x6016,_x6020,kk_context()); /*bool*/
  }
  if (_match_5229) {
    kk_std_time_instant__instant_dropn(i, ((int32_t)1), _ctx);
    _x6009 = kk_string_empty(); /*string*/
  }
  else {
    kk_string_t _x6023;
    kk_define_string_literal(, _s6024, 1, " ")
    _x6023 = kk_string_dup(_s6024); /*string*/
    kk_string_t _x6025;
    kk_std_time_instant__timescale _match_5230;
    struct kk_std_time_instant_Instant* _con6026 = kk_std_time_instant__as_Instant(i);
    kk_std_time_timestamp__timestamp _pat06 = _con6026->since;
    kk_std_time_instant__timescale _x5 = _con6026->ts;
    struct kk_std_time_instant_Timescale* _con6027 = kk_std_time_instant__as_Timescale(_x5);
    if (kk_std_time_instant__instant_is_unique(i)) {
      kk_std_time_instant__instant_free(i);
    }
    else {
      kk_std_time_instant__timescale_dup(_x5);
      kk_std_time_instant__instant_decref(i, _ctx);
    }
    _match_5230 = _x5; /*std/time/instant/timescale*/
    struct kk_std_time_instant_Timescale* _con6028 = kk_std_time_instant__as_Timescale(_match_5230);
    kk_string_t _x4 = _con6028->name;
    kk_string_t _pat05 = _con6028->unit;
    kk_function_t _pat110 = _con6028->from_tai;
    kk_function_t _pat26 = _con6028->to_tai;
    kk_std_core_types__maybe _pat35 = _con6028->mb_seconds_in_day;
    kk_std_core_types__maybe _pat45 = _con6028->mb_to_mjd2000;
    kk_std_core_types__maybe _pat55 = _con6028->mb_from_mjd2000;
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
    _x6025 = _x4; /*string*/
    _x6009 = kk_std_core__lp__plus__plus__1_rp_(_x6023, _x6025, _ctx); /*string*/
  }
  return kk_std_core__lp__plus__plus__1_rp_(_x5989, _x6009, _ctx);
}
 
// Show an instant as a number of (TAI) SI seconds since the `epoch` in a given precision.
// This can be used as an unambigious time stamp.

kk_string_t kk_std_time_instant_show(kk_std_time_instant__instant i, kk_std_core_types__optional max_prec, kk_std_core_types__optional secs_width, kk_context_t* _ctx) { /* (i : instant, max-prec : optional<int>, secs-width : optional<int>) -> string */ 
  kk_std_time_instant__instant i0_4743;
  kk_std_time_instant__timescale _x6029 = kk_std_time_instant__timescale_dup(kk_std_time_instant_ts_tai); /*std/time/instant/timescale*/
  i0_4743 = kk_std_time_instant_use_timescale(i, _x6029, _ctx); /*std/time/instant/instant*/
  kk_std_core_types__optional max_prec0_4744;
  kk_box_t _x6030;
  kk_integer_t _x6031;
  if (kk_std_core_types__is_Optional(max_prec)) {
    kk_box_t _box_x4952 = max_prec._cons.Optional.value;
    kk_integer_t _max_prec_4252 = kk_integer_unbox(_box_x4952);
    kk_integer_dup(_max_prec_4252);
    kk_std_core_types__optional_drop(max_prec, _ctx);
    _x6031 = _max_prec_4252; /*int*/
    goto _match6032;
  }
  _x6031 = kk_integer_from_small(9); /*int*/
  _match6032: ;
  _x6030 = kk_integer_box(_x6031); /*35*/
  max_prec0_4744 = kk_std_core_types__new_Optional(_x6030, _ctx); /*optional<int>*/
  kk_std_core_types__optional secs_width0_4745;
  kk_box_t _x6034;
  kk_integer_t _x6035;
  if (kk_std_core_types__is_Optional(secs_width)) {
    kk_box_t _box_x4955 = secs_width._cons.Optional.value;
    kk_integer_t _secs_width_4256 = kk_integer_unbox(_box_x4955);
    kk_integer_dup(_secs_width_4256);
    kk_std_core_types__optional_drop(secs_width, _ctx);
    _x6035 = _secs_width_4256; /*int*/
    goto _match6036;
  }
  _x6035 = kk_integer_from_small(1); /*int*/
  _match6036: ;
  _x6034 = kk_integer_box(_x6035); /*35*/
  secs_width0_4745 = kk_std_core_types__new_Optional(_x6034, _ctx); /*optional<int>*/
  kk_std_core_types__optional unit_4746;
  kk_box_t _x6038;
  kk_string_t _x6039;
  kk_define_string_literal(, _s6040, 1, "s")
  _x6039 = kk_string_dup(_s6040); /*string*/
  _x6038 = kk_string_box(_x6039); /*35*/
  unit_4746 = kk_std_core_types__new_Optional(_x6038, _ctx); /*optional<string>*/
  kk_string_t _x6041;
  kk_std_time_timestamp__timestamp _x6042;
  struct kk_std_time_instant_Instant* _con6043 = kk_std_time_instant__as_Instant(i0_4743);
  kk_std_time_timestamp__timestamp _x = _con6043->since;
  kk_std_time_instant__timescale _pat2 = _con6043->ts;
  struct kk_std_time_instant_Timescale* _con6044 = kk_std_time_instant__as_Timescale(_pat2);
  _x6042 = _x; /*std/time/timestamp/timestamp*/
  kk_std_core_types__optional _x6045;
  kk_box_t _x6046;
  kk_integer_t _x6047;
  if (kk_std_core_types__is_Optional(max_prec0_4744)) {
    kk_box_t _box_x4960 = max_prec0_4744._cons.Optional.value;
    kk_integer_t _max_prec_4044 = kk_integer_unbox(_box_x4960);
    kk_integer_dup(_max_prec_4044);
    kk_std_core_types__optional_drop(max_prec0_4744, _ctx);
    _x6047 = _max_prec_4044; /*int*/
    goto _match6048;
  }
  _x6047 = kk_integer_from_small(9); /*int*/
  _match6048: ;
  _x6046 = kk_integer_box(_x6047); /*35*/
  _x6045 = kk_std_core_types__new_Optional(_x6046, _ctx); /*optional<35>*/
  kk_std_core_types__optional _x6050;
  kk_box_t _x6051;
  kk_integer_t _x6052;
  if (kk_std_core_types__is_Optional(secs_width0_4745)) {
    kk_box_t _box_x4962 = secs_width0_4745._cons.Optional.value;
    kk_integer_t _secs_width_4048 = kk_integer_unbox(_box_x4962);
    kk_integer_dup(_secs_width_4048);
    kk_std_core_types__optional_drop(secs_width0_4745, _ctx);
    _x6052 = _secs_width_4048; /*int*/
    goto _match6053;
  }
  _x6052 = kk_integer_from_small(1); /*int*/
  _match6053: ;
  _x6051 = kk_integer_box(_x6052); /*35*/
  _x6050 = kk_std_core_types__new_Optional(_x6051, _ctx); /*optional<35>*/
  kk_std_core_types__optional _x6055;
  kk_box_t _x6056;
  kk_string_t _x6057;
  if (kk_std_core_types__is_Optional(unit_4746)) {
    kk_box_t _box_x4964 = unit_4746._cons.Optional.value;
    kk_string_t _unit_4052 = kk_string_unbox(_box_x4964);
    kk_string_dup(_unit_4052);
    kk_std_core_types__optional_drop(unit_4746, _ctx);
    _x6057 = _unit_4052; /*string*/
    goto _match6058;
  }
  _x6057 = kk_string_empty(); /*string*/
  _match6058: ;
  _x6056 = kk_string_box(_x6057); /*35*/
  _x6055 = kk_std_core_types__new_Optional(_x6056, _ctx); /*optional<35>*/
  _x6041 = kk_std_time_timestamp_ts_show(_x6042, _x6045, _x6050, _x6055, _ctx); /*string*/
  kk_string_t _x6061;
  bool _match_5224;
  bool _match_5226;
  kk_string_t _x6062;
  kk_std_time_instant__timescale _match_5228;
  struct kk_std_time_instant_Instant* _con6063 = kk_std_time_instant__as_Instant(i0_4743);
  kk_std_time_timestamp__timestamp _pat02 = _con6063->since;
  kk_std_time_instant__timescale _x1 = _con6063->ts;
  struct kk_std_time_instant_Timescale* _con6064 = kk_std_time_instant__as_Timescale(_x1);
  kk_std_time_instant__timescale_dup(_x1);
  _match_5228 = _x1; /*std/time/instant/timescale*/
  struct kk_std_time_instant_Timescale* _con6065 = kk_std_time_instant__as_Timescale(_match_5228);
  kk_string_t _x0 = _con6065->name;
  kk_string_t _pat01 = _con6065->unit;
  kk_function_t _pat13 = _con6065->from_tai;
  kk_function_t _pat21 = _con6065->to_tai;
  kk_std_core_types__maybe _pat31 = _con6065->mb_seconds_in_day;
  kk_std_core_types__maybe _pat41 = _con6065->mb_to_mjd2000;
  kk_std_core_types__maybe _pat50 = _con6065->mb_from_mjd2000;
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
  _x6062 = _x0; /*string*/
  kk_string_t _x6066 = kk_string_empty(); /*string*/
  _match_5226 = kk_string_is_eq(_x6062,_x6066,kk_context()); /*bool*/
  if (_match_5226) {
    _match_5224 = true; /*bool*/
  }
  else {
    kk_string_t _x6068;
    kk_std_time_instant__timescale _match_5227;
    struct kk_std_time_instant_Instant* _con6069 = kk_std_time_instant__as_Instant(i0_4743);
    kk_std_time_timestamp__timestamp _pat04 = _con6069->since;
    kk_std_time_instant__timescale _x3 = _con6069->ts;
    struct kk_std_time_instant_Timescale* _con6070 = kk_std_time_instant__as_Timescale(_x3);
    kk_std_time_instant__timescale_dup(_x3);
    _match_5227 = _x3; /*std/time/instant/timescale*/
    struct kk_std_time_instant_Timescale* _con6071 = kk_std_time_instant__as_Timescale(_match_5227);
    kk_string_t _x2 = _con6071->name;
    kk_string_t _pat03 = _con6071->unit;
    kk_function_t _pat17 = _con6071->from_tai;
    kk_function_t _pat23 = _con6071->to_tai;
    kk_std_core_types__maybe _pat33 = _con6071->mb_seconds_in_day;
    kk_std_core_types__maybe _pat43 = _con6071->mb_to_mjd2000;
    kk_std_core_types__maybe _pat53 = _con6071->mb_from_mjd2000;
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
    _x6068 = _x2; /*string*/
    kk_string_t _x6072;
    kk_define_string_literal(, _s6073, 3, "TAI")
    _x6072 = kk_string_dup(_s6073); /*string*/
    _match_5224 = kk_string_is_eq(_x6068,_x6072,kk_context()); /*bool*/
  }
  if (_match_5224) {
    kk_std_time_instant__instant_dropn(i0_4743, ((int32_t)1), _ctx);
    _x6061 = kk_string_empty(); /*string*/
  }
  else {
    kk_string_t _x6075;
    kk_define_string_literal(, _s6076, 1, " ")
    _x6075 = kk_string_dup(_s6076); /*string*/
    kk_string_t _x6077;
    kk_std_time_instant__timescale _match_5225;
    struct kk_std_time_instant_Instant* _con6078 = kk_std_time_instant__as_Instant(i0_4743);
    kk_std_time_timestamp__timestamp _pat06 = _con6078->since;
    kk_std_time_instant__timescale _x5 = _con6078->ts;
    struct kk_std_time_instant_Timescale* _con6079 = kk_std_time_instant__as_Timescale(_x5);
    if (kk_std_time_instant__instant_is_unique(i0_4743)) {
      kk_std_time_instant__instant_free(i0_4743);
    }
    else {
      kk_std_time_instant__timescale_dup(_x5);
      kk_std_time_instant__instant_decref(i0_4743, _ctx);
    }
    _match_5225 = _x5; /*std/time/instant/timescale*/
    struct kk_std_time_instant_Timescale* _con6080 = kk_std_time_instant__as_Timescale(_match_5225);
    kk_string_t _x4 = _con6080->name;
    kk_string_t _pat05 = _con6080->unit;
    kk_function_t _pat110 = _con6080->from_tai;
    kk_function_t _pat26 = _con6080->to_tai;
    kk_std_core_types__maybe _pat35 = _con6080->mb_seconds_in_day;
    kk_std_core_types__maybe _pat45 = _con6080->mb_to_mjd2000;
    kk_std_core_types__maybe _pat55 = _con6080->mb_from_mjd2000;
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
    _x6077 = _x4; /*string*/
    _x6061 = kk_std_core__lp__plus__plus__1_rp_(_x6075, _x6077, _ctx); /*string*/
  }
  return kk_std_core__lp__plus__plus__1_rp_(_x6041, _x6061, _ctx);
}
 
// Show a timestamp with an optional maximum precision (`max-prec` (=`9`)) and
// minimum width for the seconds (=`1`).

kk_string_t kk_std_time_instant_show_1(kk_std_time_timestamp__timestamp t, kk_std_core_types__optional max_prec, kk_std_core_types__optional secs_width, kk_std_core_types__optional unit0, kk_context_t* _ctx) { /* (t : std/time/timestamp/timestamp, max-prec : optional<int>, secs-width : optional<int>, unit : optional<string>) -> string */ 
  kk_std_core_types__optional _x6081;
  kk_box_t _x6082;
  kk_integer_t _x6083;
  if (kk_std_core_types__is_Optional(max_prec)) {
    kk_box_t _box_x4969 = max_prec._cons.Optional.value;
    kk_integer_t _max_prec_4280 = kk_integer_unbox(_box_x4969);
    kk_integer_dup(_max_prec_4280);
    kk_std_core_types__optional_drop(max_prec, _ctx);
    _x6083 = _max_prec_4280; /*int*/
    goto _match6084;
  }
  _x6083 = kk_integer_from_small(9); /*int*/
  _match6084: ;
  _x6082 = kk_integer_box(_x6083); /*35*/
  _x6081 = kk_std_core_types__new_Optional(_x6082, _ctx); /*optional<35>*/
  kk_std_core_types__optional _x6086;
  kk_box_t _x6087;
  kk_integer_t _x6088;
  if (kk_std_core_types__is_Optional(secs_width)) {
    kk_box_t _box_x4971 = secs_width._cons.Optional.value;
    kk_integer_t _secs_width_4284 = kk_integer_unbox(_box_x4971);
    kk_integer_dup(_secs_width_4284);
    kk_std_core_types__optional_drop(secs_width, _ctx);
    _x6088 = _secs_width_4284; /*int*/
    goto _match6089;
  }
  _x6088 = kk_integer_from_small(1); /*int*/
  _match6089: ;
  _x6087 = kk_integer_box(_x6088); /*35*/
  _x6086 = kk_std_core_types__new_Optional(_x6087, _ctx); /*optional<35>*/
  kk_std_core_types__optional _x6091;
  kk_box_t _x6092;
  kk_string_t _x6093;
  if (kk_std_core_types__is_Optional(unit0)) {
    kk_box_t _box_x4973 = unit0._cons.Optional.value;
    kk_string_t _unit_4288 = kk_string_unbox(_box_x4973);
    kk_string_dup(_unit_4288);
    kk_std_core_types__optional_drop(unit0, _ctx);
    _x6093 = _unit_4288; /*string*/
    goto _match6094;
  }
  _x6093 = kk_string_empty(); /*string*/
  _match6094: ;
  _x6092 = kk_string_box(_x6093); /*35*/
  _x6091 = kk_std_core_types__new_Optional(_x6092, _ctx); /*optional<35>*/
  return kk_std_time_timestamp_ts_show(t, _x6081, _x6086, _x6091, _ctx);
}
 
// The [TT](https://en.wikipedia.org/wiki/Terrestrial_Time) (Terrestrial time)
// time scale is based on SI seconds with a 1977-01-01 TAI `epoch`. It is the
// continuation of TDT (Terrestrial dynamic time) and ET (Ephemeris time). TT
// is defined as: TT = TAI + 32.184s.


// lift anonymous function
struct kk_std_time_instant_ts_tt_fun6109__t {
  struct kk_function_s _base;
  kk_std_time_duration__duration _offset_990;
};
static kk_std_time_timestamp__timestamp kk_std_time_instant_ts_tt_fun6109(kk_function_t _fself, kk_std_time_duration__duration tai, kk_context_t* _ctx);
static kk_function_t kk_std_time_instant_new_ts_tt_fun6109(kk_std_time_duration__duration _offset_990, kk_context_t* _ctx) {
  struct kk_std_time_instant_ts_tt_fun6109__t* _self = kk_function_alloc_as(struct kk_std_time_instant_ts_tt_fun6109__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_time_instant_ts_tt_fun6109, kk_context());
  _self->_offset_990 = _offset_990;
  return &_self->_base;
}

static kk_std_time_timestamp__timestamp kk_std_time_instant_ts_tt_fun6109(kk_function_t _fself, kk_std_time_duration__duration tai, kk_context_t* _ctx) {
  struct kk_std_time_instant_ts_tt_fun6109__t* _self = kk_function_as(struct kk_std_time_instant_ts_tt_fun6109__t*, _fself);
  kk_std_time_duration__duration _offset_990 = _self->_offset_990; /* std/time/duration/duration */
  kk_drop_match(_self, {kk_std_time_duration__duration_dup(_offset_990);}, {}, _ctx)
  kk_std_num_ddouble__ddouble t_4714;
  kk_std_num_ddouble__ddouble _x6110;
  kk_std_num_ddouble__ddouble _x0 = tai.secs;
  _x6110 = _x0; /*std/time/timestamp/timespan*/
  kk_std_num_ddouble__ddouble _x6111;
  kk_std_num_ddouble__ddouble _x = _offset_990.secs;
  _x6111 = _x; /*std/time/timestamp/timespan*/
  t_4714 = kk_std_num_ddouble__lp__plus__rp_(_x6110, _x6111, _ctx); /*std/time/timestamp/timespan*/
  int32_t _x6112;
  kk_integer_t _x6113;
  kk_std_core_types__optional _match_5223 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
  if (kk_std_core_types__is_Optional(_match_5223)) {
    kk_box_t _box_x4984 = _match_5223._cons.Optional.value;
    kk_integer_t _leap_492 = kk_integer_unbox(_box_x4984);
    kk_integer_dup(_leap_492);
    kk_std_core_types__optional_drop(_match_5223, _ctx);
    _x6113 = _leap_492; /*int*/
    goto _match6114;
  }
  _x6113 = kk_integer_from_small(0); /*int*/
  _match6114: ;
  _x6112 = kk_std_core_int32(_x6113, _ctx); /*int32*/
  return kk_std_time_timestamp__new_Timestamp(t_4714, _x6112, _ctx);
}


// lift anonymous function
struct kk_std_time_instant_ts_tt_fun6116__t {
  struct kk_function_s _base;
  kk_std_time_duration__duration _offset_990;
};
static kk_std_time_duration__duration kk_std_time_instant_ts_tt_fun6116(kk_function_t _fself, kk_std_time_timestamp__timestamp t0, kk_context_t* _ctx);
static kk_function_t kk_std_time_instant_new_ts_tt_fun6116(kk_std_time_duration__duration _offset_990, kk_context_t* _ctx) {
  struct kk_std_time_instant_ts_tt_fun6116__t* _self = kk_function_alloc_as(struct kk_std_time_instant_ts_tt_fun6116__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_std_time_instant_ts_tt_fun6116, kk_context());
  _self->_offset_990 = _offset_990;
  return &_self->_base;
}

static kk_std_time_duration__duration kk_std_time_instant_ts_tt_fun6116(kk_function_t _fself, kk_std_time_timestamp__timestamp t0, kk_context_t* _ctx) {
  struct kk_std_time_instant_ts_tt_fun6116__t* _self = kk_function_as(struct kk_std_time_instant_ts_tt_fun6116__t*, _fself);
  kk_std_time_duration__duration _offset_990 = _self->_offset_990; /* std/time/duration/duration */
  kk_drop_match(_self, {kk_std_time_duration__duration_dup(_offset_990);}, {}, _ctx)
  kk_std_time_timestamp__timestamp t1_4717;
  kk_std_num_ddouble__ddouble _x6117;
  kk_std_num_ddouble__ddouble _x1 = _offset_990.secs;
  _x6117 = _x1; /*std/time/timestamp/timespan*/
  t1_4717 = kk_std_time_timestamp__lp__dash__rp_(t0, _x6117, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_num_ddouble__ddouble _x6118 = kk_std_time_timestamp_unsafe_timespan_withleap(t1_4717, _ctx); /*std/time/timestamp/timespan*/
  return kk_std_time_duration__new_Duration(_x6118, _ctx);
}

kk_std_time_instant__timescale kk_std_time_instant_ts_tt;

kk_std_time_duration__duration kk_std_time_instant_tt2000;
 
// Get the TT time in SI seconds since the TT epoch (1977-01-01 TAI)

kk_std_time_duration__duration kk_std_time_instant_tt_instant(kk_std_time_instant__instant i, kk_context_t* _ctx) { /* (i : instant) -> std/time/duration/duration */ 
  kk_std_time_duration__duration d_4718;
  kk_std_time_timestamp__timestamp t_4720;
  kk_std_time_instant__timescale _x6128 = kk_std_time_instant__timescale_dup(kk_std_time_instant_ts_tt); /*std/time/instant/timescale*/
  t_4720 = kk_std_time_instant_timestamp_in(i, _x6128, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_num_ddouble__ddouble _x6129 = kk_std_time_timestamp_unsafe_timespan_withleap(t_4720, _ctx); /*std/time/timestamp/timespan*/
  d_4718 = kk_std_time_duration__new_Duration(_x6129, _ctx); /*std/time/duration/duration*/
  kk_std_time_duration__duration e_4719 = kk_std_time_duration_duration_1(kk_integer_from_int(630720000, _ctx), kk_std_core_types__new_None(_ctx), _ctx); /*std/time/duration/duration*/;
  kk_std_num_ddouble__ddouble _x6130;
  kk_std_num_ddouble__ddouble _x6131;
  kk_std_num_ddouble__ddouble _x = d_4718.secs;
  _x6131 = _x; /*std/time/timestamp/timespan*/
  kk_std_num_ddouble__ddouble _x6132;
  kk_std_num_ddouble__ddouble _x0 = e_4719.secs;
  _x6132 = _x0; /*std/time/timestamp/timespan*/
  _x6130 = kk_std_num_ddouble__lp__plus__rp_(_x6131, _x6132, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_time_duration__new_Duration(_x6130, _ctx);
}
 
// Create an instant from a raw TT time since the TT epoch (1977-01-01 TAI)

kk_std_time_instant__instant kk_std_time_instant_tt_instant_1(kk_std_time_duration__duration tt, kk_context_t* _ctx) { /* (tt : std/time/duration/duration) -> instant */ 
  kk_std_time_duration__duration d_4721;
  kk_std_time_duration__duration e_4749 = kk_std_time_duration_duration_1(kk_integer_from_int(630720000, _ctx), kk_std_core_types__new_None(_ctx), _ctx); /*std/time/duration/duration*/;
  kk_std_time_duration__duration e0_2276 = kk_std_time_duration__lp__tilde__rp_(e_4749, _ctx); /*std/time/duration/duration*/;
  kk_std_num_ddouble__ddouble _x6133;
  kk_std_num_ddouble__ddouble _x6134;
  kk_std_num_ddouble__ddouble _x = tt.secs;
  _x6134 = _x; /*std/time/timestamp/timespan*/
  kk_std_num_ddouble__ddouble _x6135;
  kk_std_num_ddouble__ddouble _x0 = e0_2276.secs;
  _x6135 = _x0; /*std/time/timestamp/timespan*/
  _x6133 = kk_std_num_ddouble__lp__plus__rp_(_x6134, _x6135, _ctx); /*std/num/ddouble/ddouble*/
  d_4721 = kk_std_time_duration__new_Duration(_x6133, _ctx); /*std/time/duration/duration*/
  kk_std_time_timestamp__timestamp t_4723 = kk_std_time_duration_timestamp(d_4721, _ctx); /*std/time/timestamp/timestamp*/;
  kk_std_time_instant__timescale _x6136 = kk_std_time_instant__timescale_dup(kk_std_time_instant_ts_tai); /*std/time/instant/timescale*/
  return kk_std_time_instant__new_Instant(kk_reuse_null, t_4723, _x6136, _ctx);
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
    kk_std_core_types__optional _match_5333 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
    if (kk_std_core_types__is_Optional(_match_5333)) {
      kk_box_t _box_x4771 = _match_5333._cons.Optional.value;
      double _frac_1424 = kk_double_unbox(_box_x4771, NULL);
      kk_std_core_types__optional_drop(_match_5333, _ctx);
      _x5389 = _frac_1424; /*double*/
      goto _match5390;
    }
    _x5389 = 0x0p+0; /*double*/
    _match5390: ;
    _match_5331 = (_x5389 == (0x0p+0)); /*bool*/
    if (_match_5331) {
      kk_std_time_instant_mjd_epoch_delta = kk_std_num_ddouble_ddouble_1(kk_integer_from_int(51544, _ctx), _ctx); /*std/time/timestamp/timespan*/
    }
    else {
      kk_std_num_ddouble__ddouble _x5392 = kk_std_num_ddouble_ddouble_1(kk_integer_from_int(51544, _ctx), _ctx); /*std/num/ddouble/ddouble*/
      kk_std_num_ddouble__ddouble _x5393;
      double _x5394;
      kk_std_core_types__optional _match_5332 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
      if (kk_std_core_types__is_Optional(_match_5332)) {
        kk_box_t _box_x4772 = _match_5332._cons.Optional.value;
        double _frac_14240 = kk_double_unbox(_box_x4772, NULL);
        kk_std_core_types__optional_drop(_match_5332, _ctx);
        _x5394 = _frac_14240; /*double*/
        goto _match5395;
      }
      _x5394 = 0x0p+0; /*double*/
      _match5395: ;
      _x5393 = kk_std_num_ddouble__new_Ddouble(_x5394, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
      kk_std_time_instant_mjd_epoch_delta = kk_std_num_ddouble__lp__plus__rp_(_x5392, _x5393, _ctx); /*std/time/timestamp/timespan*/
    }
  }
  {
    kk_std_time_instant_jd_epoch_delta = kk_std_num_ddouble__new_Ddouble(0x1.24f804p21, 0x0p+0, _ctx); /*std/time/timestamp/timespan*/
  }
  {
    kk_std_time_duration__duration _offset_990;
    kk_std_core_types__optional _match_5324 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
    if (kk_std_core_types__is_Optional(_match_5324)) {
      kk_box_t _box_x4796 = _match_5324._cons.Optional.value;
      kk_std_time_duration__duration _offset_991 = kk_std_time_duration__duration_unbox(_box_x4796, NULL);
      kk_std_core_types__optional_drop(_match_5324, _ctx);
      _offset_990 = _offset_991; /*std/time/duration/duration*/
      goto _match5458;
    }
    _offset_990 = kk_std_time_duration_duration_1(kk_integer_from_small(0), kk_std_core_types__new_None(_ctx), _ctx); /*std/time/duration/duration*/
    _match5458: ;
    kk_std_core_types__optional unit_4489;
    kk_box_t _x5460;
    kk_string_t _x5461;
    kk_define_string_literal(, _s5462, 3, "TAI")
    _x5461 = kk_string_dup(_s5462); /*string*/
    _x5460 = kk_string_box(_x5461); /*35*/
    unit_4489 = kk_std_core_types__new_Optional(_x5460, _ctx); /*optional<string>*/
    kk_string_t _x5463;
    kk_define_string_literal(, _s5464, 3, "TAI")
    _x5463 = kk_string_dup(_s5464); /*string*/
    kk_string_t _x5465;
    if (kk_std_core_types__is_Optional(unit_4489)) {
      kk_box_t _box_x4799 = unit_4489._cons.Optional.value;
      kk_string_t _unit_366 = kk_string_unbox(_box_x4799);
      kk_string_dup(_unit_366);
      kk_std_core_types__optional_drop(unit_4489, _ctx);
      _x5465 = _unit_366; /*string*/
      goto _match5466;
    }
    kk_define_string_literal(, _s5468, 3, "TAI")
    _x5465 = kk_string_dup(_s5468); /*string*/
    _match5466: ;
    kk_std_core_types__maybe _x5479;
    kk_std_core_types__optional _match_5322 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
    if (kk_std_core_types__is_Optional(_match_5322)) {
      kk_box_t _box_x4801 = _match_5322._cons.Optional.value;
      kk_std_core_types__maybe _seconds_in_day_371 = kk_std_core_types__maybe_unbox(_box_x4801, NULL);
      kk_std_core_types__maybe_dup(_seconds_in_day_371);
      kk_std_core_types__optional_drop(_match_5322, _ctx);
      _x5479 = _seconds_in_day_371; /*maybe<(std/time/timestamp/timestamp) -> std/time/timestamp/timespan>*/
      goto _match5480;
    }
    _x5479 = kk_std_core_types__new_Nothing(_ctx); /*maybe<(std/time/timestamp/timestamp) -> std/time/timestamp/timespan>*/
    _match5480: ;
    kk_std_core_types__maybe _x5482;
    kk_std_core_types__optional _match_5321 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
    if (kk_std_core_types__is_Optional(_match_5321)) {
      kk_box_t _box_x4802 = _match_5321._cons.Optional.value;
      kk_std_core_types__maybe _to_mjd2000_376 = kk_std_core_types__maybe_unbox(_box_x4802, NULL);
      kk_std_core_types__maybe_dup(_to_mjd2000_376);
      kk_std_core_types__optional_drop(_match_5321, _ctx);
      _x5482 = _to_mjd2000_376; /*maybe<(t : std/time/timestamp/timestamp, tzdelta : std/time/timestamp/timespan) -> std/num/ddouble/ddouble>*/
      goto _match5483;
    }
    _x5482 = kk_std_core_types__new_Nothing(_ctx); /*maybe<(t : std/time/timestamp/timestamp, tzdelta : std/time/timestamp/timespan) -> std/num/ddouble/ddouble>*/
    _match5483: ;
    kk_std_core_types__maybe _x5485;
    kk_std_core_types__optional _match_5320 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
    if (kk_std_core_types__is_Optional(_match_5320)) {
      kk_box_t _box_x4803 = _match_5320._cons.Optional.value;
      kk_std_core_types__maybe _from_mjd2000_381 = kk_std_core_types__maybe_unbox(_box_x4803, NULL);
      kk_std_core_types__maybe_dup(_from_mjd2000_381);
      kk_std_core_types__optional_drop(_match_5320, _ctx);
      _x5485 = _from_mjd2000_381; /*maybe<(days : int, frac : std/num/ddouble/ddouble) -> std/time/timestamp/timestamp>*/
      goto _match5486;
    }
    _x5485 = kk_std_core_types__new_Nothing(_ctx); /*maybe<(days : int, frac : std/num/ddouble/ddouble) -> std/time/timestamp/timestamp>*/
    _match5486: ;
    kk_std_time_instant_ts_tai = kk_std_time_instant__new_Timescale(kk_reuse_null, _x5463, _x5465, kk_std_time_instant_new_ts_tai_fun5469(_offset_990, _ctx), kk_std_time_instant_new_ts_tai_fun5476(_offset_990, _ctx), _x5479, _x5482, _x5485, _ctx); /*std/time/instant/timescale*/
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
      kk_std_core_types__optional_drop(offset_4600, _ctx);
      _offset_990 = _offset_991; /*std/time/duration/duration*/
      goto _match5781;
    }
    _offset_990 = kk_std_time_duration_duration_1(kk_integer_from_small(0), kk_std_core_types__new_None(_ctx), _ctx); /*std/time/duration/duration*/
    _match5781: ;
    kk_std_core_types__optional unit_4605;
    kk_box_t _x5783;
    kk_string_t _x5784;
    kk_define_string_literal(, _s5785, 3, "TAI")
    _x5784 = kk_string_dup(_s5785); /*string*/
    _x5783 = kk_string_box(_x5784); /*35*/
    unit_4605 = kk_std_core_types__new_Optional(_x5783, _ctx); /*optional<string>*/
    kk_string_t _x5786;
    kk_define_string_literal(, _s5787, 3, "GPS")
    _x5786 = kk_string_dup(_s5787); /*string*/
    kk_string_t _x5788;
    if (kk_std_core_types__is_Optional(unit_4605)) {
      kk_box_t _box_x4828 = unit_4605._cons.Optional.value;
      kk_string_t _unit_366 = kk_string_unbox(_box_x4828);
      kk_string_dup(_unit_366);
      kk_std_core_types__optional_drop(unit_4605, _ctx);
      _x5788 = _unit_366; /*string*/
      goto _match5789;
    }
    kk_define_string_literal(, _s5791, 3, "GPS")
    _x5788 = kk_string_dup(_s5791); /*string*/
    _match5789: ;
    kk_std_core_types__maybe _x5802;
    kk_std_core_types__optional _match_5269 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
    if (kk_std_core_types__is_Optional(_match_5269)) {
      kk_box_t _box_x4830 = _match_5269._cons.Optional.value;
      kk_std_core_types__maybe _seconds_in_day_371 = kk_std_core_types__maybe_unbox(_box_x4830, NULL);
      kk_std_core_types__maybe_dup(_seconds_in_day_371);
      kk_std_core_types__optional_drop(_match_5269, _ctx);
      _x5802 = _seconds_in_day_371; /*maybe<(std/time/timestamp/timestamp) -> std/time/timestamp/timespan>*/
      goto _match5803;
    }
    _x5802 = kk_std_core_types__new_Nothing(_ctx); /*maybe<(std/time/timestamp/timestamp) -> std/time/timestamp/timespan>*/
    _match5803: ;
    kk_std_core_types__maybe _x5805;
    kk_std_core_types__optional _match_5268 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
    if (kk_std_core_types__is_Optional(_match_5268)) {
      kk_box_t _box_x4831 = _match_5268._cons.Optional.value;
      kk_std_core_types__maybe _to_mjd2000_376 = kk_std_core_types__maybe_unbox(_box_x4831, NULL);
      kk_std_core_types__maybe_dup(_to_mjd2000_376);
      kk_std_core_types__optional_drop(_match_5268, _ctx);
      _x5805 = _to_mjd2000_376; /*maybe<(t : std/time/timestamp/timestamp, tzdelta : std/time/timestamp/timespan) -> std/num/ddouble/ddouble>*/
      goto _match5806;
    }
    _x5805 = kk_std_core_types__new_Nothing(_ctx); /*maybe<(t : std/time/timestamp/timestamp, tzdelta : std/time/timestamp/timespan) -> std/num/ddouble/ddouble>*/
    _match5806: ;
    kk_std_core_types__maybe _x5808;
    kk_std_core_types__optional _match_5267 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
    if (kk_std_core_types__is_Optional(_match_5267)) {
      kk_box_t _box_x4832 = _match_5267._cons.Optional.value;
      kk_std_core_types__maybe _from_mjd2000_381 = kk_std_core_types__maybe_unbox(_box_x4832, NULL);
      kk_std_core_types__maybe_dup(_from_mjd2000_381);
      kk_std_core_types__optional_drop(_match_5267, _ctx);
      _x5808 = _from_mjd2000_381; /*maybe<(days : int, frac : std/num/ddouble/ddouble) -> std/time/timestamp/timestamp>*/
      goto _match5809;
    }
    _x5808 = kk_std_core_types__new_Nothing(_ctx); /*maybe<(days : int, frac : std/num/ddouble/ddouble) -> std/time/timestamp/timestamp>*/
    _match5809: ;
    kk_std_time_instant_ts_gps = kk_std_time_instant__new_Timescale(kk_reuse_null, _x5786, _x5788, kk_std_time_instant_new_ts_gps_fun5792(_offset_990, _ctx), kk_std_time_instant_new_ts_gps_fun5799(_offset_990, _ctx), _x5802, _x5805, _x5808, _ctx); /*std/time/instant/timescale*/
  }
  {
    kk_std_core_types__optional offset_4704;
    kk_std_time_duration__duration _b_4979_4978;
    kk_std_num_ddouble__ddouble _x6097 = kk_std_num_ddouble_ddouble(0x1.0178d4fdf3b64p5, _ctx); /*std/num/ddouble/ddouble*/
    _b_4979_4978 = kk_std_time_duration__new_Duration(_x6097, _ctx); /*std/time/duration/duration*/
    offset_4704 = kk_std_core_types__new_Optional(kk_std_time_duration__duration_box(_b_4979_4978, _ctx), _ctx); /*optional<std/time/duration/duration>*/
    kk_std_time_duration__duration _offset_990;
    if (kk_std_core_types__is_Optional(offset_4704)) {
      kk_box_t _box_x4980 = offset_4704._cons.Optional.value;
      kk_std_time_duration__duration _offset_991 = kk_std_time_duration__duration_unbox(_box_x4980, NULL);
      kk_std_core_types__optional_drop(offset_4704, _ctx);
      _offset_990 = _offset_991; /*std/time/duration/duration*/
      goto _match6098;
    }
    _offset_990 = kk_std_time_duration_duration_1(kk_integer_from_small(0), kk_std_core_types__new_None(_ctx), _ctx); /*std/time/duration/duration*/
    _match6098: ;
    kk_std_core_types__optional unit_4710;
    kk_box_t _x6100;
    kk_string_t _x6101;
    kk_define_string_literal(, _s6102, 3, "TAI")
    _x6101 = kk_string_dup(_s6102); /*string*/
    _x6100 = kk_string_box(_x6101); /*35*/
    unit_4710 = kk_std_core_types__new_Optional(_x6100, _ctx); /*optional<string>*/
    kk_string_t _x6103;
    kk_define_string_literal(, _s6104, 2, "TT")
    _x6103 = kk_string_dup(_s6104); /*string*/
    kk_string_t _x6105;
    if (kk_std_core_types__is_Optional(unit_4710)) {
      kk_box_t _box_x4983 = unit_4710._cons.Optional.value;
      kk_string_t _unit_366 = kk_string_unbox(_box_x4983);
      kk_string_dup(_unit_366);
      kk_std_core_types__optional_drop(unit_4710, _ctx);
      _x6105 = _unit_366; /*string*/
      goto _match6106;
    }
    kk_define_string_literal(, _s6108, 2, "TT")
    _x6105 = kk_string_dup(_s6108); /*string*/
    _match6106: ;
    kk_std_core_types__maybe _x6119;
    kk_std_core_types__optional _match_5222 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
    if (kk_std_core_types__is_Optional(_match_5222)) {
      kk_box_t _box_x4985 = _match_5222._cons.Optional.value;
      kk_std_core_types__maybe _seconds_in_day_371 = kk_std_core_types__maybe_unbox(_box_x4985, NULL);
      kk_std_core_types__maybe_dup(_seconds_in_day_371);
      kk_std_core_types__optional_drop(_match_5222, _ctx);
      _x6119 = _seconds_in_day_371; /*maybe<(std/time/timestamp/timestamp) -> std/time/timestamp/timespan>*/
      goto _match6120;
    }
    _x6119 = kk_std_core_types__new_Nothing(_ctx); /*maybe<(std/time/timestamp/timestamp) -> std/time/timestamp/timespan>*/
    _match6120: ;
    kk_std_core_types__maybe _x6122;
    kk_std_core_types__optional _match_5221 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
    if (kk_std_core_types__is_Optional(_match_5221)) {
      kk_box_t _box_x4986 = _match_5221._cons.Optional.value;
      kk_std_core_types__maybe _to_mjd2000_376 = kk_std_core_types__maybe_unbox(_box_x4986, NULL);
      kk_std_core_types__maybe_dup(_to_mjd2000_376);
      kk_std_core_types__optional_drop(_match_5221, _ctx);
      _x6122 = _to_mjd2000_376; /*maybe<(t : std/time/timestamp/timestamp, tzdelta : std/time/timestamp/timespan) -> std/num/ddouble/ddouble>*/
      goto _match6123;
    }
    _x6122 = kk_std_core_types__new_Nothing(_ctx); /*maybe<(t : std/time/timestamp/timestamp, tzdelta : std/time/timestamp/timespan) -> std/num/ddouble/ddouble>*/
    _match6123: ;
    kk_std_core_types__maybe _x6125;
    kk_std_core_types__optional _match_5220 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
    if (kk_std_core_types__is_Optional(_match_5220)) {
      kk_box_t _box_x4987 = _match_5220._cons.Optional.value;
      kk_std_core_types__maybe _from_mjd2000_381 = kk_std_core_types__maybe_unbox(_box_x4987, NULL);
      kk_std_core_types__maybe_dup(_from_mjd2000_381);
      kk_std_core_types__optional_drop(_match_5220, _ctx);
      _x6125 = _from_mjd2000_381; /*maybe<(days : int, frac : std/num/ddouble/ddouble) -> std/time/timestamp/timestamp>*/
      goto _match6126;
    }
    _x6125 = kk_std_core_types__new_Nothing(_ctx); /*maybe<(days : int, frac : std/num/ddouble/ddouble) -> std/time/timestamp/timestamp>*/
    _match6126: ;
    kk_std_time_instant_ts_tt = kk_std_time_instant__new_Timescale(kk_reuse_null, _x6103, _x6105, kk_std_time_instant_new_ts_tt_fun6109(_offset_990, _ctx), kk_std_time_instant_new_ts_tt_fun6116(_offset_990, _ctx), _x6119, _x6122, _x6125, _ctx); /*std/time/instant/timescale*/
  }
  {
    kk_std_time_instant_tt2000 = kk_std_time_duration_duration_1(kk_integer_from_int(630720000, _ctx), kk_std_core_types__new_None(_ctx), _ctx); /*std/time/duration/duration*/
  }
}
