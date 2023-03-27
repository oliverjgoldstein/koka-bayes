// Koka generated module: "std/time/duration", koka version: 2.1.2
#include "std_time_duration.h"
 
// Compare two `:duration`s.

kk_std_core_types__order kk_std_time_duration_compare(kk_std_time_duration__duration i, kk_std_time_duration__duration j, kk_context_t* _ctx) { /* (i : duration, j : duration) -> order */ 
  kk_std_core_types__order _match_2429;
  bool _match_2436;
  double _x2445;
  kk_std_num_ddouble__ddouble _match_2441;
  kk_std_num_ddouble__ddouble _x3 = i.secs;
  _match_2441 = _x3; /*std/time/timestamp/timespan*/
  double _x = _match_2441.hi;
  _x2445 = _x; /*double*/
  double _x2446;
  kk_std_num_ddouble__ddouble _match_2440;
  kk_std_num_ddouble__ddouble _x4 = j.secs;
  _match_2440 = _x4; /*std/time/timestamp/timespan*/
  double _x0 = _match_2440.hi;
  _x2446 = _x0; /*double*/
  _match_2436 = (_x2445 < _x2446); /*bool*/
  if (_match_2436) {
    _match_2429 = kk_std_core_types__new_Lt(_ctx); /*order*/
  }
  else {
    bool _match_2437;
    double _x2447;
    kk_std_num_ddouble__ddouble _match_2439;
    kk_std_num_ddouble__ddouble _x30 = i.secs;
    _match_2439 = _x30; /*std/time/timestamp/timespan*/
    double _x1 = _match_2439.hi;
    _x2447 = _x1; /*double*/
    double _x2448;
    kk_std_num_ddouble__ddouble _match_2438;
    kk_std_num_ddouble__ddouble _x40 = j.secs;
    _match_2438 = _x40; /*std/time/timestamp/timespan*/
    double _x00 = _match_2438.hi;
    _x2448 = _x00; /*double*/
    _match_2437 = (_x2447 > _x2448); /*bool*/
    if (_match_2437) {
      _match_2429 = kk_std_core_types__new_Gt(_ctx); /*order*/
    }
    else {
      _match_2429 = kk_std_core_types__new_Eq(_ctx); /*order*/
    }
  }
  if (kk_std_core_types__is_Eq(_match_2429)) {
    bool _match_2430;
    double _x2449;
    kk_std_num_ddouble__ddouble _match_2435;
    kk_std_num_ddouble__ddouble _x31 = i.secs;
    _match_2435 = _x31; /*std/time/timestamp/timespan*/
    double _x10 = _match_2435.lo;
    _x2449 = _x10; /*double*/
    double _x2450;
    kk_std_num_ddouble__ddouble _match_2434;
    kk_std_num_ddouble__ddouble _x41 = j.secs;
    _match_2434 = _x41; /*std/time/timestamp/timespan*/
    double _x2 = _match_2434.lo;
    _x2450 = _x2; /*double*/
    _match_2430 = (_x2449 < _x2450); /*bool*/
    if (_match_2430) {
      return kk_std_core_types__new_Lt(_ctx);
    }
    bool _match_2431;
    double _x2451;
    kk_std_num_ddouble__ddouble _match_2433;
    kk_std_num_ddouble__ddouble _x32 = i.secs;
    _match_2433 = _x32; /*std/time/timestamp/timespan*/
    double _x11 = _match_2433.lo;
    _x2451 = _x11; /*double*/
    double _x2452;
    kk_std_num_ddouble__ddouble _match_2432;
    kk_std_num_ddouble__ddouble _x42 = j.secs;
    _match_2432 = _x42; /*std/time/timestamp/timespan*/
    double _x20 = _match_2432.lo;
    _x2452 = _x20; /*double*/
    _match_2431 = (_x2451 > _x2452); /*bool*/
    if (_match_2431) {
      return kk_std_core_types__new_Gt(_ctx);
    }
    return kk_std_core_types__new_Eq(_ctx);
  }
  return _match_2429;
}

bool kk_std_time_duration__lp__excl__eq__rp_(kk_std_time_duration__duration i, kk_std_time_duration__duration j, kk_context_t* _ctx) { /* (i : duration, j : duration) -> bool */ 
  kk_std_core_types__order x_2262 = kk_std_time_duration_compare(i, j, _ctx); /*order*/;
  kk_integer_t _x2453 = kk_std_core_int_5(x_2262, _ctx); /*int*/
  kk_integer_t _x2454;
  kk_std_core_types__order _x2455 = kk_std_core_types__new_Eq(_ctx); /*order*/
  if (kk_std_core_types__is_Lt(_x2455)) {
    _x2454 = kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context()); /*int*/
    goto _match2456;
  }
  if (kk_std_core_types__is_Eq(_x2455)) {
    _x2454 = kk_integer_from_small(0); /*int*/
    goto _match2456;
  }
  _x2454 = kk_integer_from_small(1); /*int*/
  _match2456: ;
  return kk_integer_neq(_x2453,_x2454,kk_context());
}
 
// Create a duration from whole seconds `secs` and a fraction of seconds `frac`.

kk_std_time_duration__duration kk_std_time_duration_duration_1(kk_integer_t secs0, kk_std_core_types__optional frac, kk_context_t* _ctx) { /* (secs : int, frac : optional<double>) -> duration */ 
  kk_std_num_ddouble__ddouble _x2457;
  kk_std_core_types__optional frac0_2265;
  kk_box_t _x2458;
  double _x2459;
  if (kk_std_core_types__is_Optional(frac)) {
    kk_box_t _box_x2342 = frac._cons.Optional.value;
    double _frac_240 = kk_double_unbox(_box_x2342, NULL);
    _x2459 = _frac_240; /*double*/
    goto _match2460;
  }
  _x2459 = 0x0p+0; /*double*/
  _match2460: ;
  _x2458 = kk_double_box(_x2459, _ctx); /*35*/
  frac0_2265 = kk_std_core_types__new_Optional(_x2458, _ctx); /*optional<double>*/
  bool _match_2427;
  double _x2462;
  if (kk_std_core_types__is_Optional(frac0_2265)) {
    kk_box_t _box_x2345 = frac0_2265._cons.Optional.value;
    double _frac_1424 = kk_double_unbox(_box_x2345, NULL);
    _x2462 = _frac_1424; /*double*/
    goto _match2463;
  }
  _x2462 = 0x0p+0; /*double*/
  _match2463: ;
  _match_2427 = (_x2462 == (0x0p+0)); /*bool*/
  if (_match_2427) {
    kk_std_core_types__optional_drop(frac0_2265, _ctx);
    _x2457 = kk_std_num_ddouble_ddouble_1(secs0, _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    kk_std_num_ddouble__ddouble _x2465 = kk_std_num_ddouble_ddouble_1(secs0, _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble _x2466;
    double _x2467;
    if (kk_std_core_types__is_Optional(frac0_2265)) {
      kk_box_t _box_x2346 = frac0_2265._cons.Optional.value;
      double _frac_14240 = kk_double_unbox(_box_x2346, NULL);
      _x2467 = _frac_14240; /*double*/
      goto _match2468;
    }
    _x2467 = 0x0p+0; /*double*/
    _match2468: ;
    _x2466 = kk_std_num_ddouble__new_Ddouble(_x2467, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    _x2457 = kk_std_num_ddouble__lp__plus__rp_(_x2465, _x2466, _ctx); /*std/num/ddouble/ddouble*/
  }
  return kk_std_time_duration__new_Duration(_x2457, _ctx);
}
 
// Create a `:duration` of `n` seconds.

kk_std_time_duration__duration kk_std_time_duration_seconds_1(kk_integer_t n, kk_context_t* _ctx) { /* (n : int) -> duration */ 
  kk_std_num_ddouble__ddouble _x2471;
  kk_std_core_types__optional frac0_2270;
  kk_box_t _x2472;
  double _x2473;
  kk_std_core_types__optional _x2474 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/
  if (kk_std_core_types__is_Optional(_x2474)) {
    kk_box_t _box_x2347 = _x2474._cons.Optional.value;
    double _frac_240 = kk_double_unbox(_box_x2347, NULL);
    _x2473 = _frac_240; /*double*/
    goto _match2475;
  }
  _x2473 = 0x0p+0; /*double*/
  _match2475: ;
  _x2472 = kk_double_box(_x2473, _ctx); /*35*/
  frac0_2270 = kk_std_core_types__new_Optional(_x2472, _ctx); /*optional<double>*/
  bool _match_2425;
  double _x2477;
  if (kk_std_core_types__is_Optional(frac0_2270)) {
    kk_box_t _box_x2350 = frac0_2270._cons.Optional.value;
    double _frac_1424 = kk_double_unbox(_box_x2350, NULL);
    _x2477 = _frac_1424; /*double*/
    goto _match2478;
  }
  _x2477 = 0x0p+0; /*double*/
  _match2478: ;
  _match_2425 = (_x2477 == (0x0p+0)); /*bool*/
  if (_match_2425) {
    kk_std_core_types__optional_drop(frac0_2270, _ctx);
    _x2471 = kk_std_num_ddouble_ddouble_1(n, _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    kk_std_num_ddouble__ddouble _x2480 = kk_std_num_ddouble_ddouble_1(n, _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble _x2481;
    double _x2482;
    if (kk_std_core_types__is_Optional(frac0_2270)) {
      kk_box_t _box_x2351 = frac0_2270._cons.Optional.value;
      double _frac_14240 = kk_double_unbox(_box_x2351, NULL);
      _x2482 = _frac_14240; /*double*/
      goto _match2483;
    }
    _x2482 = 0x0p+0; /*double*/
    _match2483: ;
    _x2481 = kk_std_num_ddouble__new_Ddouble(_x2482, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    _x2471 = kk_std_num_ddouble__lp__plus__rp_(_x2480, _x2481, _ctx); /*std/num/ddouble/ddouble*/
  }
  return kk_std_time_duration__new_Duration(_x2471, _ctx);
}

bool kk_std_time_duration__lp__eq__eq__rp_(kk_std_time_duration__duration i, kk_std_time_duration__duration j, kk_context_t* _ctx) { /* (i : duration, j : duration) -> bool */ 
  kk_std_core_types__order x_2279 = kk_std_time_duration_compare(i, j, _ctx); /*order*/;
  kk_integer_t _x2496 = kk_std_core_int_5(x_2279, _ctx); /*int*/
  kk_integer_t _x2497;
  kk_std_core_types__order _x2498 = kk_std_core_types__new_Eq(_ctx); /*order*/
  if (kk_std_core_types__is_Lt(_x2498)) {
    _x2497 = kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context()); /*int*/
    goto _match2499;
  }
  if (kk_std_core_types__is_Eq(_x2498)) {
    _x2497 = kk_integer_from_small(0); /*int*/
    goto _match2499;
  }
  _x2497 = kk_integer_from_small(1); /*int*/
  _match2499: ;
  return kk_integer_eq(_x2496,_x2497,kk_context());
}

bool kk_std_time_duration__lp__lt__rp_(kk_std_time_duration__duration i, kk_std_time_duration__duration j, kk_context_t* _ctx) { /* (i : duration, j : duration) -> bool */ 
  kk_std_core_types__order x_2281 = kk_std_time_duration_compare(i, j, _ctx); /*order*/;
  kk_integer_t _x2500 = kk_std_core_int_5(x_2281, _ctx); /*int*/
  kk_integer_t _x2501;
  kk_std_core_types__order _x2502 = kk_std_core_types__new_Lt(_ctx); /*order*/
  if (kk_std_core_types__is_Lt(_x2502)) {
    _x2501 = kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context()); /*int*/
    goto _match2503;
  }
  if (kk_std_core_types__is_Eq(_x2502)) {
    _x2501 = kk_integer_from_small(0); /*int*/
    goto _match2503;
  }
  _x2501 = kk_integer_from_small(1); /*int*/
  _match2503: ;
  return kk_integer_eq(_x2500,_x2501,kk_context());
}

bool kk_std_time_duration__lp__lt__eq__rp_(kk_std_time_duration__duration i, kk_std_time_duration__duration j, kk_context_t* _ctx) { /* (i : duration, j : duration) -> bool */ 
  kk_std_core_types__order x_2283 = kk_std_time_duration_compare(i, j, _ctx); /*order*/;
  kk_integer_t _x2504 = kk_std_core_int_5(x_2283, _ctx); /*int*/
  kk_integer_t _x2505;
  kk_std_core_types__order _x2506 = kk_std_core_types__new_Gt(_ctx); /*order*/
  if (kk_std_core_types__is_Lt(_x2506)) {
    _x2505 = kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context()); /*int*/
    goto _match2507;
  }
  if (kk_std_core_types__is_Eq(_x2506)) {
    _x2505 = kk_integer_from_small(0); /*int*/
    goto _match2507;
  }
  _x2505 = kk_integer_from_small(1); /*int*/
  _match2507: ;
  return kk_integer_neq(_x2504,_x2505,kk_context());
}

bool kk_std_time_duration__lp__gt__rp_(kk_std_time_duration__duration i, kk_std_time_duration__duration j, kk_context_t* _ctx) { /* (i : duration, j : duration) -> bool */ 
  kk_std_core_types__order x_2285 = kk_std_time_duration_compare(i, j, _ctx); /*order*/;
  kk_integer_t _x2508 = kk_std_core_int_5(x_2285, _ctx); /*int*/
  kk_integer_t _x2509;
  kk_std_core_types__order _x2510 = kk_std_core_types__new_Gt(_ctx); /*order*/
  if (kk_std_core_types__is_Lt(_x2510)) {
    _x2509 = kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context()); /*int*/
    goto _match2511;
  }
  if (kk_std_core_types__is_Eq(_x2510)) {
    _x2509 = kk_integer_from_small(0); /*int*/
    goto _match2511;
  }
  _x2509 = kk_integer_from_small(1); /*int*/
  _match2511: ;
  return kk_integer_eq(_x2508,_x2509,kk_context());
}

bool kk_std_time_duration__lp__gt__eq__rp_(kk_std_time_duration__duration i, kk_std_time_duration__duration j, kk_context_t* _ctx) { /* (i : duration, j : duration) -> bool */ 
  kk_std_core_types__order x_2287 = kk_std_time_duration_compare(i, j, _ctx); /*order*/;
  kk_integer_t _x2512 = kk_std_core_int_5(x_2287, _ctx); /*int*/
  kk_integer_t _x2513;
  kk_std_core_types__order _x2514 = kk_std_core_types__new_Lt(_ctx); /*order*/
  if (kk_std_core_types__is_Lt(_x2514)) {
    _x2513 = kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context()); /*int*/
    goto _match2515;
  }
  if (kk_std_core_types__is_Eq(_x2514)) {
    _x2513 = kk_integer_from_small(0); /*int*/
    goto _match2515;
  }
  _x2513 = kk_integer_from_small(1); /*int*/
  _match2515: ;
  return kk_integer_neq(_x2512,_x2513,kk_context());
}
 
// Create a `:duration` of `n` "days" (assuming 86400s in a day).

kk_std_time_duration__duration kk_std_time_duration_days(kk_integer_t n, kk_context_t* _ctx) { /* (n : int) -> duration */ 
  kk_integer_t secs_2289 = kk_integer_mul(n,(kk_integer_from_int(86400, _ctx)),kk_context()); /*int*/;
  kk_std_num_ddouble__ddouble _x2516;
  kk_std_core_types__optional frac0_2292;
  kk_box_t _x2517;
  double _x2518;
  kk_std_core_types__optional _x2519 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/
  if (kk_std_core_types__is_Optional(_x2519)) {
    kk_box_t _box_x2352 = _x2519._cons.Optional.value;
    double _frac_240 = kk_double_unbox(_box_x2352, NULL);
    _x2518 = _frac_240; /*double*/
    goto _match2520;
  }
  _x2518 = 0x0p+0; /*double*/
  _match2520: ;
  _x2517 = kk_double_box(_x2518, _ctx); /*35*/
  frac0_2292 = kk_std_core_types__new_Optional(_x2517, _ctx); /*optional<double>*/
  bool _match_2416;
  double _x2522;
  if (kk_std_core_types__is_Optional(frac0_2292)) {
    kk_box_t _box_x2355 = frac0_2292._cons.Optional.value;
    double _frac_1424 = kk_double_unbox(_box_x2355, NULL);
    _x2522 = _frac_1424; /*double*/
    goto _match2523;
  }
  _x2522 = 0x0p+0; /*double*/
  _match2523: ;
  _match_2416 = (_x2522 == (0x0p+0)); /*bool*/
  if (_match_2416) {
    kk_std_core_types__optional_drop(frac0_2292, _ctx);
    _x2516 = kk_std_num_ddouble_ddouble_1(secs_2289, _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    kk_std_num_ddouble__ddouble _x2525 = kk_std_num_ddouble_ddouble_1(secs_2289, _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble _x2526;
    double _x2527;
    if (kk_std_core_types__is_Optional(frac0_2292)) {
      kk_box_t _box_x2356 = frac0_2292._cons.Optional.value;
      double _frac_14240 = kk_double_unbox(_box_x2356, NULL);
      _x2527 = _frac_14240; /*double*/
      goto _match2528;
    }
    _x2527 = 0x0p+0; /*double*/
    _match2528: ;
    _x2526 = kk_std_num_ddouble__new_Ddouble(_x2527, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    _x2516 = kk_std_num_ddouble__lp__plus__rp_(_x2525, _x2526, _ctx); /*std/num/ddouble/ddouble*/
  }
  return kk_std_time_duration__new_Duration(_x2516, _ctx);
}

kk_std_time_duration__duration kk_std_time_duration_duration0;
 
// Create a `:duration` of `n` hours.

kk_std_time_duration__duration kk_std_time_duration_hours(kk_integer_t n, kk_context_t* _ctx) { /* (n : int) -> duration */ 
  kk_integer_t secs_2296 = kk_integer_mul(n,(kk_integer_from_int(3600, _ctx)),kk_context()); /*int*/;
  kk_std_num_ddouble__ddouble _x2534;
  kk_std_core_types__optional frac0_2299;
  kk_box_t _x2535;
  double _x2536;
  kk_std_core_types__optional _x2537 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/
  if (kk_std_core_types__is_Optional(_x2537)) {
    kk_box_t _box_x2357 = _x2537._cons.Optional.value;
    double _frac_240 = kk_double_unbox(_box_x2357, NULL);
    _x2536 = _frac_240; /*double*/
    goto _match2538;
  }
  _x2536 = 0x0p+0; /*double*/
  _match2538: ;
  _x2535 = kk_double_box(_x2536, _ctx); /*35*/
  frac0_2299 = kk_std_core_types__new_Optional(_x2535, _ctx); /*optional<double>*/
  bool _match_2414;
  double _x2540;
  if (kk_std_core_types__is_Optional(frac0_2299)) {
    kk_box_t _box_x2360 = frac0_2299._cons.Optional.value;
    double _frac_1424 = kk_double_unbox(_box_x2360, NULL);
    _x2540 = _frac_1424; /*double*/
    goto _match2541;
  }
  _x2540 = 0x0p+0; /*double*/
  _match2541: ;
  _match_2414 = (_x2540 == (0x0p+0)); /*bool*/
  if (_match_2414) {
    kk_std_core_types__optional_drop(frac0_2299, _ctx);
    _x2534 = kk_std_num_ddouble_ddouble_1(secs_2296, _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    kk_std_num_ddouble__ddouble _x2543 = kk_std_num_ddouble_ddouble_1(secs_2296, _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble _x2544;
    double _x2545;
    if (kk_std_core_types__is_Optional(frac0_2299)) {
      kk_box_t _box_x2361 = frac0_2299._cons.Optional.value;
      double _frac_14240 = kk_double_unbox(_box_x2361, NULL);
      _x2545 = _frac_14240; /*double*/
      goto _match2546;
    }
    _x2545 = 0x0p+0; /*double*/
    _match2546: ;
    _x2544 = kk_std_num_ddouble__new_Ddouble(_x2545, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    _x2534 = kk_std_num_ddouble__lp__plus__rp_(_x2543, _x2544, _ctx); /*std/num/ddouble/ddouble*/
  }
  return kk_std_time_duration__new_Duration(_x2534, _ctx);
}
 
// Return the duration in rounded SI milli-seconds.

kk_integer_t kk_std_time_duration_milli_seconds(kk_std_time_duration__duration d, kk_context_t* _ctx) { /* (d : duration) -> int */ 
  kk_std_num_ddouble__ddouble _x2551;
  kk_std_num_ddouble__ddouble _x2552;
  kk_std_num_ddouble__ddouble _x = d.secs;
  _x2552 = _x; /*std/time/timestamp/timespan*/
  kk_std_num_ddouble__ddouble _x2553;
  bool _match_2407;
  double _x2554;
  kk_std_core_types__optional _x2555 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/
  if (kk_std_core_types__is_Optional(_x2555)) {
    kk_box_t _box_x2362 = _x2555._cons.Optional.value;
    double _frac_1424 = kk_double_unbox(_box_x2362, NULL);
    _x2554 = _frac_1424; /*double*/
    goto _match2556;
  }
  _x2554 = 0x0p+0; /*double*/
  _match2556: ;
  _match_2407 = (_x2554 == (0x0p+0)); /*bool*/
  if (_match_2407) {
    _x2553 = kk_std_num_ddouble_ddouble_1(kk_integer_from_small(1000), _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    kk_std_num_ddouble__ddouble _x2558 = kk_std_num_ddouble_ddouble_1(kk_integer_from_small(1000), _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble _x2559;
    double _x2560;
    kk_std_core_types__optional _x2561 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/
    if (kk_std_core_types__is_Optional(_x2561)) {
      kk_box_t _box_x2363 = _x2561._cons.Optional.value;
      double _frac_14240 = kk_double_unbox(_box_x2363, NULL);
      _x2560 = _frac_14240; /*double*/
      goto _match2562;
    }
    _x2560 = 0x0p+0; /*double*/
    _match2562: ;
    _x2559 = kk_std_num_ddouble__new_Ddouble(_x2560, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    _x2553 = kk_std_num_ddouble__lp__plus__rp_(_x2558, _x2559, _ctx); /*std/num/ddouble/ddouble*/
  }
  _x2551 = kk_std_num_ddouble__lp__star__rp_(_x2552, _x2553, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble_int(_x2551, kk_std_core_types__new_None(_ctx), _ctx);
}
 
// Create a `:duration` of `n` milli-seconds.

kk_std_time_duration__duration kk_std_time_duration_milli_seconds_1(kk_integer_t n, kk_context_t* _ctx) { /* (n : int) -> duration */ 
  kk_std_num_ddouble__ddouble _x2564;
  kk_std_num_ddouble__ddouble _x2565;
  bool _match_2404;
  double _x2566;
  kk_std_core_types__optional _x2567 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/
  if (kk_std_core_types__is_Optional(_x2567)) {
    kk_box_t _box_x2364 = _x2567._cons.Optional.value;
    double _frac_1424 = kk_double_unbox(_box_x2364, NULL);
    _x2566 = _frac_1424; /*double*/
    goto _match2568;
  }
  _x2566 = 0x0p+0; /*double*/
  _match2568: ;
  _match_2404 = (_x2566 == (0x0p+0)); /*bool*/
  if (_match_2404) {
    _x2565 = kk_std_num_ddouble_ddouble_1(n, _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    kk_std_num_ddouble__ddouble _x2570 = kk_std_num_ddouble_ddouble_1(n, _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble _x2571;
    double _x2572;
    kk_std_core_types__optional _x2573 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/
    if (kk_std_core_types__is_Optional(_x2573)) {
      kk_box_t _box_x2365 = _x2573._cons.Optional.value;
      double _frac_14240 = kk_double_unbox(_box_x2365, NULL);
      _x2572 = _frac_14240; /*double*/
      goto _match2574;
    }
    _x2572 = 0x0p+0; /*double*/
    _match2574: ;
    _x2571 = kk_std_num_ddouble__new_Ddouble(_x2572, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    _x2565 = kk_std_num_ddouble__lp__plus__rp_(_x2570, _x2571, _ctx); /*std/num/ddouble/ddouble*/
  }
  kk_std_num_ddouble__ddouble _x2576;
  bool _match_2401;
  double _x2577;
  kk_std_core_types__optional _x2578 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/
  if (kk_std_core_types__is_Optional(_x2578)) {
    kk_box_t _box_x2366 = _x2578._cons.Optional.value;
    double _frac_14241 = kk_double_unbox(_box_x2366, NULL);
    _x2577 = _frac_14241; /*double*/
    goto _match2579;
  }
  _x2577 = 0x0p+0; /*double*/
  _match2579: ;
  _match_2401 = (_x2577 == (0x0p+0)); /*bool*/
  if (_match_2401) {
    _x2576 = kk_std_num_ddouble_ddouble_1(kk_integer_from_small(1000), _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    kk_std_num_ddouble__ddouble _x2581 = kk_std_num_ddouble_ddouble_1(kk_integer_from_small(1000), _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble _x2582;
    double _x2583;
    kk_std_core_types__optional _x2584 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/
    if (kk_std_core_types__is_Optional(_x2584)) {
      kk_box_t _box_x2367 = _x2584._cons.Optional.value;
      double _frac_142400 = kk_double_unbox(_box_x2367, NULL);
      _x2583 = _frac_142400; /*double*/
      goto _match2585;
    }
    _x2583 = 0x0p+0; /*double*/
    _match2585: ;
    _x2582 = kk_std_num_ddouble__new_Ddouble(_x2583, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    _x2576 = kk_std_num_ddouble__lp__plus__rp_(_x2581, _x2582, _ctx); /*std/num/ddouble/ddouble*/
  }
  _x2564 = kk_std_num_ddouble__lp__fs__rp_(_x2565, _x2576, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_time_duration__new_Duration(_x2564, _ctx);
}
 
// Create a `:duration` of `n` minutes.

kk_std_time_duration__duration kk_std_time_duration_minutes(kk_integer_t n, kk_context_t* _ctx) { /* (n : int) -> duration */ 
  kk_integer_t secs_2313 = kk_integer_mul(n,(kk_integer_from_small(60)),kk_context()); /*int*/;
  kk_std_num_ddouble__ddouble _x2587;
  kk_std_core_types__optional frac0_2316;
  kk_box_t _x2588;
  double _x2589;
  kk_std_core_types__optional _x2590 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/
  if (kk_std_core_types__is_Optional(_x2590)) {
    kk_box_t _box_x2368 = _x2590._cons.Optional.value;
    double _frac_240 = kk_double_unbox(_box_x2368, NULL);
    _x2589 = _frac_240; /*double*/
    goto _match2591;
  }
  _x2589 = 0x0p+0; /*double*/
  _match2591: ;
  _x2588 = kk_double_box(_x2589, _ctx); /*35*/
  frac0_2316 = kk_std_core_types__new_Optional(_x2588, _ctx); /*optional<double>*/
  bool _match_2398;
  double _x2593;
  if (kk_std_core_types__is_Optional(frac0_2316)) {
    kk_box_t _box_x2371 = frac0_2316._cons.Optional.value;
    double _frac_1424 = kk_double_unbox(_box_x2371, NULL);
    _x2593 = _frac_1424; /*double*/
    goto _match2594;
  }
  _x2593 = 0x0p+0; /*double*/
  _match2594: ;
  _match_2398 = (_x2593 == (0x0p+0)); /*bool*/
  if (_match_2398) {
    kk_std_core_types__optional_drop(frac0_2316, _ctx);
    _x2587 = kk_std_num_ddouble_ddouble_1(secs_2313, _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    kk_std_num_ddouble__ddouble _x2596 = kk_std_num_ddouble_ddouble_1(secs_2313, _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble _x2597;
    double _x2598;
    if (kk_std_core_types__is_Optional(frac0_2316)) {
      kk_box_t _box_x2372 = frac0_2316._cons.Optional.value;
      double _frac_14240 = kk_double_unbox(_box_x2372, NULL);
      _x2598 = _frac_14240; /*double*/
      goto _match2599;
    }
    _x2598 = 0x0p+0; /*double*/
    _match2599: ;
    _x2597 = kk_std_num_ddouble__new_Ddouble(_x2598, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    _x2587 = kk_std_num_ddouble__lp__plus__rp_(_x2596, _x2597, _ctx); /*std/num/ddouble/ddouble*/
  }
  return kk_std_time_duration__new_Duration(_x2587, _ctx);
}
 
// Return the duration in rounded SI nano-seconds.

kk_integer_t kk_std_time_duration_nano_seconds(kk_std_time_duration__duration d, kk_context_t* _ctx) { /* (d : duration) -> int */ 
  kk_std_num_ddouble__ddouble _x2601;
  kk_std_num_ddouble__ddouble _x2602;
  kk_std_num_ddouble__ddouble _x = d.secs;
  _x2602 = _x; /*std/time/timestamp/timespan*/
  kk_std_num_ddouble__ddouble _x2603;
  bool _match_2395;
  double _x2604;
  kk_std_core_types__optional _x2605 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/
  if (kk_std_core_types__is_Optional(_x2605)) {
    kk_box_t _box_x2373 = _x2605._cons.Optional.value;
    double _frac_1424 = kk_double_unbox(_box_x2373, NULL);
    _x2604 = _frac_1424; /*double*/
    goto _match2606;
  }
  _x2604 = 0x0p+0; /*double*/
  _match2606: ;
  _match_2395 = (_x2604 == (0x0p+0)); /*bool*/
  if (_match_2395) {
    _x2603 = kk_std_num_ddouble_ddouble_1(kk_integer_from_int(1000000000, _ctx), _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    kk_std_num_ddouble__ddouble _x2608 = kk_std_num_ddouble_ddouble_1(kk_integer_from_int(1000000000, _ctx), _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble _x2609;
    double _x2610;
    kk_std_core_types__optional _x2611 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/
    if (kk_std_core_types__is_Optional(_x2611)) {
      kk_box_t _box_x2374 = _x2611._cons.Optional.value;
      double _frac_14240 = kk_double_unbox(_box_x2374, NULL);
      _x2610 = _frac_14240; /*double*/
      goto _match2612;
    }
    _x2610 = 0x0p+0; /*double*/
    _match2612: ;
    _x2609 = kk_std_num_ddouble__new_Ddouble(_x2610, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    _x2603 = kk_std_num_ddouble__lp__plus__rp_(_x2608, _x2609, _ctx); /*std/num/ddouble/ddouble*/
  }
  _x2601 = kk_std_num_ddouble__lp__star__rp_(_x2602, _x2603, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble_int(_x2601, kk_std_core_types__new_None(_ctx), _ctx);
}
 
// Show a duration in SI seconds.

kk_string_t kk_std_time_duration_show(kk_std_time_duration__duration d, kk_std_core_types__optional max_prec, kk_context_t* _ctx) { /* (d : duration, max-prec : optional<int>) -> string */ 
  kk_string_t _x2614;
  kk_std_num_ddouble__ddouble _x2615;
  kk_std_num_ddouble__ddouble _x = d.secs;
  _x2615 = _x; /*std/time/timestamp/timespan*/
  kk_std_core_types__optional _x2616;
  kk_integer_t _b_2377_2376;
  kk_integer_t _x2617;
  kk_integer_t _x2618;
  if (kk_std_core_types__is_Optional(max_prec)) {
    kk_box_t _box_x2375 = max_prec._cons.Optional.value;
    kk_integer_t _max_prec_1769 = kk_integer_unbox(_box_x2375);
    _x2618 = _max_prec_1769; /*int*/
    goto _match2619;
  }
  _x2618 = kk_integer_from_small(9); /*int*/
  _match2619: ;
  _x2617 = kk_integer_abs(_x2618,kk_context()); /*int*/
  _b_2377_2376 = kk_integer_neg(_x2617,kk_context()); /*int*/
  _x2616 = kk_std_core_types__new_Optional(kk_integer_box(_b_2377_2376), _ctx); /*optional<35>*/
  _x2614 = kk_std_num_ddouble_show_fixed(_x2615, _x2616, _ctx); /*string*/
  kk_string_t _x2621;
  kk_define_string_literal(, _s2622, 1, "s")
  _x2621 = kk_string_dup(_s2622); /*string*/
  return kk_std_core__lp__plus__plus__1_rp_(_x2614, _x2621, _ctx);
}
 
// Create a `:duration` of `n` "weeks" (assuming 7 days of 86400s).

kk_std_time_duration__duration kk_std_time_duration_weeks(kk_integer_t n, kk_context_t* _ctx) { /* (n : int) -> duration */ 
  kk_integer_t secs_2325;
  kk_integer_t _x2634 = kk_integer_mul(n,(kk_integer_from_small(7)),kk_context()); /*int*/
  secs_2325 = kk_integer_mul(_x2634,(kk_integer_from_int(86400, _ctx)),kk_context()); /*int*/
  kk_std_num_ddouble__ddouble _x2635;
  kk_std_core_types__optional frac0_2328;
  kk_box_t _x2636;
  double _x2637;
  kk_std_core_types__optional _x2638 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/
  if (kk_std_core_types__is_Optional(_x2638)) {
    kk_box_t _box_x2379 = _x2638._cons.Optional.value;
    double _frac_240 = kk_double_unbox(_box_x2379, NULL);
    _x2637 = _frac_240; /*double*/
    goto _match2639;
  }
  _x2637 = 0x0p+0; /*double*/
  _match2639: ;
  _x2636 = kk_double_box(_x2637, _ctx); /*35*/
  frac0_2328 = kk_std_core_types__new_Optional(_x2636, _ctx); /*optional<double>*/
  bool _match_2391;
  double _x2641;
  if (kk_std_core_types__is_Optional(frac0_2328)) {
    kk_box_t _box_x2382 = frac0_2328._cons.Optional.value;
    double _frac_1424 = kk_double_unbox(_box_x2382, NULL);
    _x2641 = _frac_1424; /*double*/
    goto _match2642;
  }
  _x2641 = 0x0p+0; /*double*/
  _match2642: ;
  _match_2391 = (_x2641 == (0x0p+0)); /*bool*/
  if (_match_2391) {
    kk_std_core_types__optional_drop(frac0_2328, _ctx);
    _x2635 = kk_std_num_ddouble_ddouble_1(secs_2325, _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    kk_std_num_ddouble__ddouble _x2644 = kk_std_num_ddouble_ddouble_1(secs_2325, _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble _x2645;
    double _x2646;
    if (kk_std_core_types__is_Optional(frac0_2328)) {
      kk_box_t _box_x2383 = frac0_2328._cons.Optional.value;
      double _frac_14240 = kk_double_unbox(_box_x2383, NULL);
      _x2646 = _frac_14240; /*double*/
      goto _match2647;
    }
    _x2646 = 0x0p+0; /*double*/
    _match2647: ;
    _x2645 = kk_std_num_ddouble__new_Ddouble(_x2646, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    _x2635 = kk_std_num_ddouble__lp__plus__rp_(_x2644, _x2645, _ctx); /*std/num/ddouble/ddouble*/
  }
  return kk_std_time_duration__new_Duration(_x2635, _ctx);
}
 
// Create a `:duration` of `n` "years" (assuming 365 days of 86400s).

kk_std_time_duration__duration kk_std_time_duration_years(kk_integer_t n, kk_context_t* _ctx) { /* (n : int) -> duration */ 
  kk_integer_t secs_2329;
  kk_integer_t _x2649 = kk_integer_mul(n,(kk_integer_from_small(365)),kk_context()); /*int*/
  secs_2329 = kk_integer_mul(_x2649,(kk_integer_from_int(86400, _ctx)),kk_context()); /*int*/
  kk_std_num_ddouble__ddouble _x2650;
  kk_std_core_types__optional frac0_2332;
  kk_box_t _x2651;
  double _x2652;
  kk_std_core_types__optional _x2653 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/
  if (kk_std_core_types__is_Optional(_x2653)) {
    kk_box_t _box_x2384 = _x2653._cons.Optional.value;
    double _frac_240 = kk_double_unbox(_box_x2384, NULL);
    _x2652 = _frac_240; /*double*/
    goto _match2654;
  }
  _x2652 = 0x0p+0; /*double*/
  _match2654: ;
  _x2651 = kk_double_box(_x2652, _ctx); /*35*/
  frac0_2332 = kk_std_core_types__new_Optional(_x2651, _ctx); /*optional<double>*/
  bool _match_2389;
  double _x2656;
  if (kk_std_core_types__is_Optional(frac0_2332)) {
    kk_box_t _box_x2387 = frac0_2332._cons.Optional.value;
    double _frac_1424 = kk_double_unbox(_box_x2387, NULL);
    _x2656 = _frac_1424; /*double*/
    goto _match2657;
  }
  _x2656 = 0x0p+0; /*double*/
  _match2657: ;
  _match_2389 = (_x2656 == (0x0p+0)); /*bool*/
  if (_match_2389) {
    kk_std_core_types__optional_drop(frac0_2332, _ctx);
    _x2650 = kk_std_num_ddouble_ddouble_1(secs_2329, _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    kk_std_num_ddouble__ddouble _x2659 = kk_std_num_ddouble_ddouble_1(secs_2329, _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble _x2660;
    double _x2661;
    if (kk_std_core_types__is_Optional(frac0_2332)) {
      kk_box_t _box_x2388 = frac0_2332._cons.Optional.value;
      double _frac_14240 = kk_double_unbox(_box_x2388, NULL);
      _x2661 = _frac_14240; /*double*/
      goto _match2662;
    }
    _x2661 = 0x0p+0; /*double*/
    _match2662: ;
    _x2660 = kk_std_num_ddouble__new_Ddouble(_x2661, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    _x2650 = kk_std_num_ddouble__lp__plus__rp_(_x2659, _x2660, _ctx); /*std/num/ddouble/ddouble*/
  }
  return kk_std_time_duration__new_Duration(_x2650, _ctx);
}
 
// A zero duration.

kk_std_time_duration__duration kk_std_time_duration_zero;

// initialization
void kk_std_time_duration__init(kk_context_t* _ctx){
  static bool _initialized = false;
  if (_initialized) return;
  _initialized = true;
  kk_std_core_types__init(_ctx);
  kk_std_core__init(_ctx);
  kk_std_num_ddouble__init(_ctx);
  kk_std_time_timestamp__init(_ctx);
  {
    kk_std_num_ddouble__ddouble _x2530 = kk_std_num_ddouble__new_Ddouble(0x0p+0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    kk_std_time_duration_duration0 = kk_std_time_duration__new_Duration(_x2530, _ctx); /*std/time/duration/duration*/
  }
  {
    kk_std_num_ddouble__ddouble _x2664 = kk_std_num_ddouble__new_Ddouble(0x0p+0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    kk_std_time_duration_zero = kk_std_time_duration__new_Duration(_x2664, _ctx); /*std/time/duration/duration*/
  }
}
