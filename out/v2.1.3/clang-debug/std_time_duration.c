// Koka generated module: "std/time/duration", koka version: 2.1.3
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
    kk_std_core_types__optional_drop(frac, _ctx);
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
      kk_std_core_types__optional_drop(frac0_2265, _ctx);
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
  kk_std_core_types__optional _match_2426 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
  if (kk_std_core_types__is_Optional(_match_2426)) {
    kk_box_t _box_x2347 = _match_2426._cons.Optional.value;
    double _frac_240 = kk_double_unbox(_box_x2347, NULL);
    kk_std_core_types__optional_drop(_match_2426, _ctx);
    _x2473 = _frac_240; /*double*/
    goto _match2474;
  }
  _x2473 = 0x0p+0; /*double*/
  _match2474: ;
  _x2472 = kk_double_box(_x2473, _ctx); /*35*/
  frac0_2270 = kk_std_core_types__new_Optional(_x2472, _ctx); /*optional<double>*/
  bool _match_2425;
  double _x2476;
  if (kk_std_core_types__is_Optional(frac0_2270)) {
    kk_box_t _box_x2350 = frac0_2270._cons.Optional.value;
    double _frac_1424 = kk_double_unbox(_box_x2350, NULL);
    _x2476 = _frac_1424; /*double*/
    goto _match2477;
  }
  _x2476 = 0x0p+0; /*double*/
  _match2477: ;
  _match_2425 = (_x2476 == (0x0p+0)); /*bool*/
  if (_match_2425) {
    kk_std_core_types__optional_drop(frac0_2270, _ctx);
    _x2471 = kk_std_num_ddouble_ddouble_1(n, _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    kk_std_num_ddouble__ddouble _x2479 = kk_std_num_ddouble_ddouble_1(n, _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble _x2480;
    double _x2481;
    if (kk_std_core_types__is_Optional(frac0_2270)) {
      kk_box_t _box_x2351 = frac0_2270._cons.Optional.value;
      double _frac_14240 = kk_double_unbox(_box_x2351, NULL);
      kk_std_core_types__optional_drop(frac0_2270, _ctx);
      _x2481 = _frac_14240; /*double*/
      goto _match2482;
    }
    _x2481 = 0x0p+0; /*double*/
    _match2482: ;
    _x2480 = kk_std_num_ddouble__new_Ddouble(_x2481, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    _x2471 = kk_std_num_ddouble__lp__plus__rp_(_x2479, _x2480, _ctx); /*std/num/ddouble/ddouble*/
  }
  return kk_std_time_duration__new_Duration(_x2471, _ctx);
}

bool kk_std_time_duration__lp__eq__eq__rp_(kk_std_time_duration__duration i, kk_std_time_duration__duration j, kk_context_t* _ctx) { /* (i : duration, j : duration) -> bool */ 
  kk_std_core_types__order x_2279 = kk_std_time_duration_compare(i, j, _ctx); /*order*/;
  kk_integer_t _x2495 = kk_std_core_int_5(x_2279, _ctx); /*int*/
  kk_integer_t _x2496;
  kk_std_core_types__order _x2497 = kk_std_core_types__new_Eq(_ctx); /*order*/
  if (kk_std_core_types__is_Lt(_x2497)) {
    _x2496 = kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context()); /*int*/
    goto _match2498;
  }
  if (kk_std_core_types__is_Eq(_x2497)) {
    _x2496 = kk_integer_from_small(0); /*int*/
    goto _match2498;
  }
  _x2496 = kk_integer_from_small(1); /*int*/
  _match2498: ;
  return kk_integer_eq(_x2495,_x2496,kk_context());
}

bool kk_std_time_duration__lp__lt__rp_(kk_std_time_duration__duration i, kk_std_time_duration__duration j, kk_context_t* _ctx) { /* (i : duration, j : duration) -> bool */ 
  kk_std_core_types__order x_2281 = kk_std_time_duration_compare(i, j, _ctx); /*order*/;
  kk_integer_t _x2499 = kk_std_core_int_5(x_2281, _ctx); /*int*/
  kk_integer_t _x2500;
  kk_std_core_types__order _x2501 = kk_std_core_types__new_Lt(_ctx); /*order*/
  if (kk_std_core_types__is_Lt(_x2501)) {
    _x2500 = kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context()); /*int*/
    goto _match2502;
  }
  if (kk_std_core_types__is_Eq(_x2501)) {
    _x2500 = kk_integer_from_small(0); /*int*/
    goto _match2502;
  }
  _x2500 = kk_integer_from_small(1); /*int*/
  _match2502: ;
  return kk_integer_eq(_x2499,_x2500,kk_context());
}

bool kk_std_time_duration__lp__lt__eq__rp_(kk_std_time_duration__duration i, kk_std_time_duration__duration j, kk_context_t* _ctx) { /* (i : duration, j : duration) -> bool */ 
  kk_std_core_types__order x_2283 = kk_std_time_duration_compare(i, j, _ctx); /*order*/;
  kk_integer_t _x2503 = kk_std_core_int_5(x_2283, _ctx); /*int*/
  kk_integer_t _x2504;
  kk_std_core_types__order _x2505 = kk_std_core_types__new_Gt(_ctx); /*order*/
  if (kk_std_core_types__is_Lt(_x2505)) {
    _x2504 = kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context()); /*int*/
    goto _match2506;
  }
  if (kk_std_core_types__is_Eq(_x2505)) {
    _x2504 = kk_integer_from_small(0); /*int*/
    goto _match2506;
  }
  _x2504 = kk_integer_from_small(1); /*int*/
  _match2506: ;
  return kk_integer_neq(_x2503,_x2504,kk_context());
}

bool kk_std_time_duration__lp__gt__rp_(kk_std_time_duration__duration i, kk_std_time_duration__duration j, kk_context_t* _ctx) { /* (i : duration, j : duration) -> bool */ 
  kk_std_core_types__order x_2285 = kk_std_time_duration_compare(i, j, _ctx); /*order*/;
  kk_integer_t _x2507 = kk_std_core_int_5(x_2285, _ctx); /*int*/
  kk_integer_t _x2508;
  kk_std_core_types__order _x2509 = kk_std_core_types__new_Gt(_ctx); /*order*/
  if (kk_std_core_types__is_Lt(_x2509)) {
    _x2508 = kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context()); /*int*/
    goto _match2510;
  }
  if (kk_std_core_types__is_Eq(_x2509)) {
    _x2508 = kk_integer_from_small(0); /*int*/
    goto _match2510;
  }
  _x2508 = kk_integer_from_small(1); /*int*/
  _match2510: ;
  return kk_integer_eq(_x2507,_x2508,kk_context());
}

bool kk_std_time_duration__lp__gt__eq__rp_(kk_std_time_duration__duration i, kk_std_time_duration__duration j, kk_context_t* _ctx) { /* (i : duration, j : duration) -> bool */ 
  kk_std_core_types__order x_2287 = kk_std_time_duration_compare(i, j, _ctx); /*order*/;
  kk_integer_t _x2511 = kk_std_core_int_5(x_2287, _ctx); /*int*/
  kk_integer_t _x2512;
  kk_std_core_types__order _x2513 = kk_std_core_types__new_Lt(_ctx); /*order*/
  if (kk_std_core_types__is_Lt(_x2513)) {
    _x2512 = kk_integer_sub((kk_integer_from_small(0)),(kk_integer_from_small(1)),kk_context()); /*int*/
    goto _match2514;
  }
  if (kk_std_core_types__is_Eq(_x2513)) {
    _x2512 = kk_integer_from_small(0); /*int*/
    goto _match2514;
  }
  _x2512 = kk_integer_from_small(1); /*int*/
  _match2514: ;
  return kk_integer_neq(_x2511,_x2512,kk_context());
}
 
// Create a `:duration` of `n` "days" (assuming 86400s in a day).

kk_std_time_duration__duration kk_std_time_duration_days(kk_integer_t n, kk_context_t* _ctx) { /* (n : int) -> duration */ 
  kk_integer_t secs_2289 = kk_integer_mul(n,(kk_integer_from_int(86400, _ctx)),kk_context()); /*int*/;
  kk_std_num_ddouble__ddouble _x2515;
  kk_std_core_types__optional frac0_2292;
  kk_box_t _x2516;
  double _x2517;
  kk_std_core_types__optional _match_2417 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
  if (kk_std_core_types__is_Optional(_match_2417)) {
    kk_box_t _box_x2352 = _match_2417._cons.Optional.value;
    double _frac_240 = kk_double_unbox(_box_x2352, NULL);
    kk_std_core_types__optional_drop(_match_2417, _ctx);
    _x2517 = _frac_240; /*double*/
    goto _match2518;
  }
  _x2517 = 0x0p+0; /*double*/
  _match2518: ;
  _x2516 = kk_double_box(_x2517, _ctx); /*35*/
  frac0_2292 = kk_std_core_types__new_Optional(_x2516, _ctx); /*optional<double>*/
  bool _match_2416;
  double _x2520;
  if (kk_std_core_types__is_Optional(frac0_2292)) {
    kk_box_t _box_x2355 = frac0_2292._cons.Optional.value;
    double _frac_1424 = kk_double_unbox(_box_x2355, NULL);
    _x2520 = _frac_1424; /*double*/
    goto _match2521;
  }
  _x2520 = 0x0p+0; /*double*/
  _match2521: ;
  _match_2416 = (_x2520 == (0x0p+0)); /*bool*/
  if (_match_2416) {
    kk_std_core_types__optional_drop(frac0_2292, _ctx);
    _x2515 = kk_std_num_ddouble_ddouble_1(secs_2289, _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    kk_std_num_ddouble__ddouble _x2523 = kk_std_num_ddouble_ddouble_1(secs_2289, _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble _x2524;
    double _x2525;
    if (kk_std_core_types__is_Optional(frac0_2292)) {
      kk_box_t _box_x2356 = frac0_2292._cons.Optional.value;
      double _frac_14240 = kk_double_unbox(_box_x2356, NULL);
      kk_std_core_types__optional_drop(frac0_2292, _ctx);
      _x2525 = _frac_14240; /*double*/
      goto _match2526;
    }
    _x2525 = 0x0p+0; /*double*/
    _match2526: ;
    _x2524 = kk_std_num_ddouble__new_Ddouble(_x2525, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    _x2515 = kk_std_num_ddouble__lp__plus__rp_(_x2523, _x2524, _ctx); /*std/num/ddouble/ddouble*/
  }
  return kk_std_time_duration__new_Duration(_x2515, _ctx);
}

kk_std_time_duration__duration kk_std_time_duration_duration0;
 
// Create a `:duration` of `n` hours.

kk_std_time_duration__duration kk_std_time_duration_hours(kk_integer_t n, kk_context_t* _ctx) { /* (n : int) -> duration */ 
  kk_integer_t secs_2296 = kk_integer_mul(n,(kk_integer_from_int(3600, _ctx)),kk_context()); /*int*/;
  kk_std_num_ddouble__ddouble _x2532;
  kk_std_core_types__optional frac0_2299;
  kk_box_t _x2533;
  double _x2534;
  kk_std_core_types__optional _match_2415 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
  if (kk_std_core_types__is_Optional(_match_2415)) {
    kk_box_t _box_x2357 = _match_2415._cons.Optional.value;
    double _frac_240 = kk_double_unbox(_box_x2357, NULL);
    kk_std_core_types__optional_drop(_match_2415, _ctx);
    _x2534 = _frac_240; /*double*/
    goto _match2535;
  }
  _x2534 = 0x0p+0; /*double*/
  _match2535: ;
  _x2533 = kk_double_box(_x2534, _ctx); /*35*/
  frac0_2299 = kk_std_core_types__new_Optional(_x2533, _ctx); /*optional<double>*/
  bool _match_2414;
  double _x2537;
  if (kk_std_core_types__is_Optional(frac0_2299)) {
    kk_box_t _box_x2360 = frac0_2299._cons.Optional.value;
    double _frac_1424 = kk_double_unbox(_box_x2360, NULL);
    _x2537 = _frac_1424; /*double*/
    goto _match2538;
  }
  _x2537 = 0x0p+0; /*double*/
  _match2538: ;
  _match_2414 = (_x2537 == (0x0p+0)); /*bool*/
  if (_match_2414) {
    kk_std_core_types__optional_drop(frac0_2299, _ctx);
    _x2532 = kk_std_num_ddouble_ddouble_1(secs_2296, _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    kk_std_num_ddouble__ddouble _x2540 = kk_std_num_ddouble_ddouble_1(secs_2296, _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble _x2541;
    double _x2542;
    if (kk_std_core_types__is_Optional(frac0_2299)) {
      kk_box_t _box_x2361 = frac0_2299._cons.Optional.value;
      double _frac_14240 = kk_double_unbox(_box_x2361, NULL);
      kk_std_core_types__optional_drop(frac0_2299, _ctx);
      _x2542 = _frac_14240; /*double*/
      goto _match2543;
    }
    _x2542 = 0x0p+0; /*double*/
    _match2543: ;
    _x2541 = kk_std_num_ddouble__new_Ddouble(_x2542, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    _x2532 = kk_std_num_ddouble__lp__plus__rp_(_x2540, _x2541, _ctx); /*std/num/ddouble/ddouble*/
  }
  return kk_std_time_duration__new_Duration(_x2532, _ctx);
}
 
// Return the duration in rounded SI milli-seconds.

kk_integer_t kk_std_time_duration_milli_seconds(kk_std_time_duration__duration d, kk_context_t* _ctx) { /* (d : duration) -> int */ 
  kk_std_num_ddouble__ddouble _x2548;
  kk_std_num_ddouble__ddouble _x2549;
  kk_std_num_ddouble__ddouble _x = d.secs;
  _x2549 = _x; /*std/time/timestamp/timespan*/
  kk_std_num_ddouble__ddouble _x2550;
  bool _match_2407;
  double _x2551;
  kk_std_core_types__optional _match_2409 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
  if (kk_std_core_types__is_Optional(_match_2409)) {
    kk_box_t _box_x2362 = _match_2409._cons.Optional.value;
    double _frac_1424 = kk_double_unbox(_box_x2362, NULL);
    kk_std_core_types__optional_drop(_match_2409, _ctx);
    _x2551 = _frac_1424; /*double*/
    goto _match2552;
  }
  _x2551 = 0x0p+0; /*double*/
  _match2552: ;
  _match_2407 = (_x2551 == (0x0p+0)); /*bool*/
  if (_match_2407) {
    _x2550 = kk_std_num_ddouble_ddouble_1(kk_integer_from_small(1000), _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    kk_std_num_ddouble__ddouble _x2554 = kk_std_num_ddouble_ddouble_1(kk_integer_from_small(1000), _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble _x2555;
    double _x2556;
    kk_std_core_types__optional _match_2408 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
    if (kk_std_core_types__is_Optional(_match_2408)) {
      kk_box_t _box_x2363 = _match_2408._cons.Optional.value;
      double _frac_14240 = kk_double_unbox(_box_x2363, NULL);
      kk_std_core_types__optional_drop(_match_2408, _ctx);
      _x2556 = _frac_14240; /*double*/
      goto _match2557;
    }
    _x2556 = 0x0p+0; /*double*/
    _match2557: ;
    _x2555 = kk_std_num_ddouble__new_Ddouble(_x2556, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    _x2550 = kk_std_num_ddouble__lp__plus__rp_(_x2554, _x2555, _ctx); /*std/num/ddouble/ddouble*/
  }
  _x2548 = kk_std_num_ddouble__lp__star__rp_(_x2549, _x2550, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble_int(_x2548, kk_std_core_types__new_None(_ctx), _ctx);
}
 
// Create a `:duration` of `n` milli-seconds.

kk_std_time_duration__duration kk_std_time_duration_milli_seconds_1(kk_integer_t n, kk_context_t* _ctx) { /* (n : int) -> duration */ 
  kk_std_num_ddouble__ddouble _x2559;
  kk_std_num_ddouble__ddouble _x2560;
  bool _match_2404;
  double _x2561;
  kk_std_core_types__optional _match_2406 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
  if (kk_std_core_types__is_Optional(_match_2406)) {
    kk_box_t _box_x2364 = _match_2406._cons.Optional.value;
    double _frac_1424 = kk_double_unbox(_box_x2364, NULL);
    kk_std_core_types__optional_drop(_match_2406, _ctx);
    _x2561 = _frac_1424; /*double*/
    goto _match2562;
  }
  _x2561 = 0x0p+0; /*double*/
  _match2562: ;
  _match_2404 = (_x2561 == (0x0p+0)); /*bool*/
  if (_match_2404) {
    _x2560 = kk_std_num_ddouble_ddouble_1(n, _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    kk_std_num_ddouble__ddouble _x2564 = kk_std_num_ddouble_ddouble_1(n, _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble _x2565;
    double _x2566;
    kk_std_core_types__optional _match_2405 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
    if (kk_std_core_types__is_Optional(_match_2405)) {
      kk_box_t _box_x2365 = _match_2405._cons.Optional.value;
      double _frac_14240 = kk_double_unbox(_box_x2365, NULL);
      kk_std_core_types__optional_drop(_match_2405, _ctx);
      _x2566 = _frac_14240; /*double*/
      goto _match2567;
    }
    _x2566 = 0x0p+0; /*double*/
    _match2567: ;
    _x2565 = kk_std_num_ddouble__new_Ddouble(_x2566, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    _x2560 = kk_std_num_ddouble__lp__plus__rp_(_x2564, _x2565, _ctx); /*std/num/ddouble/ddouble*/
  }
  kk_std_num_ddouble__ddouble _x2569;
  bool _match_2401;
  double _x2570;
  kk_std_core_types__optional _match_2403 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
  if (kk_std_core_types__is_Optional(_match_2403)) {
    kk_box_t _box_x2366 = _match_2403._cons.Optional.value;
    double _frac_14241 = kk_double_unbox(_box_x2366, NULL);
    kk_std_core_types__optional_drop(_match_2403, _ctx);
    _x2570 = _frac_14241; /*double*/
    goto _match2571;
  }
  _x2570 = 0x0p+0; /*double*/
  _match2571: ;
  _match_2401 = (_x2570 == (0x0p+0)); /*bool*/
  if (_match_2401) {
    _x2569 = kk_std_num_ddouble_ddouble_1(kk_integer_from_small(1000), _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    kk_std_num_ddouble__ddouble _x2573 = kk_std_num_ddouble_ddouble_1(kk_integer_from_small(1000), _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble _x2574;
    double _x2575;
    kk_std_core_types__optional _match_2402 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
    if (kk_std_core_types__is_Optional(_match_2402)) {
      kk_box_t _box_x2367 = _match_2402._cons.Optional.value;
      double _frac_142400 = kk_double_unbox(_box_x2367, NULL);
      kk_std_core_types__optional_drop(_match_2402, _ctx);
      _x2575 = _frac_142400; /*double*/
      goto _match2576;
    }
    _x2575 = 0x0p+0; /*double*/
    _match2576: ;
    _x2574 = kk_std_num_ddouble__new_Ddouble(_x2575, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    _x2569 = kk_std_num_ddouble__lp__plus__rp_(_x2573, _x2574, _ctx); /*std/num/ddouble/ddouble*/
  }
  _x2559 = kk_std_num_ddouble__lp__fs__rp_(_x2560, _x2569, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_time_duration__new_Duration(_x2559, _ctx);
}
 
// Create a `:duration` of `n` minutes.

kk_std_time_duration__duration kk_std_time_duration_minutes(kk_integer_t n, kk_context_t* _ctx) { /* (n : int) -> duration */ 
  kk_integer_t secs_2313 = kk_integer_mul(n,(kk_integer_from_small(60)),kk_context()); /*int*/;
  kk_std_num_ddouble__ddouble _x2578;
  kk_std_core_types__optional frac0_2316;
  kk_box_t _x2579;
  double _x2580;
  kk_std_core_types__optional _match_2399 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
  if (kk_std_core_types__is_Optional(_match_2399)) {
    kk_box_t _box_x2368 = _match_2399._cons.Optional.value;
    double _frac_240 = kk_double_unbox(_box_x2368, NULL);
    kk_std_core_types__optional_drop(_match_2399, _ctx);
    _x2580 = _frac_240; /*double*/
    goto _match2581;
  }
  _x2580 = 0x0p+0; /*double*/
  _match2581: ;
  _x2579 = kk_double_box(_x2580, _ctx); /*35*/
  frac0_2316 = kk_std_core_types__new_Optional(_x2579, _ctx); /*optional<double>*/
  bool _match_2398;
  double _x2583;
  if (kk_std_core_types__is_Optional(frac0_2316)) {
    kk_box_t _box_x2371 = frac0_2316._cons.Optional.value;
    double _frac_1424 = kk_double_unbox(_box_x2371, NULL);
    _x2583 = _frac_1424; /*double*/
    goto _match2584;
  }
  _x2583 = 0x0p+0; /*double*/
  _match2584: ;
  _match_2398 = (_x2583 == (0x0p+0)); /*bool*/
  if (_match_2398) {
    kk_std_core_types__optional_drop(frac0_2316, _ctx);
    _x2578 = kk_std_num_ddouble_ddouble_1(secs_2313, _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    kk_std_num_ddouble__ddouble _x2586 = kk_std_num_ddouble_ddouble_1(secs_2313, _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble _x2587;
    double _x2588;
    if (kk_std_core_types__is_Optional(frac0_2316)) {
      kk_box_t _box_x2372 = frac0_2316._cons.Optional.value;
      double _frac_14240 = kk_double_unbox(_box_x2372, NULL);
      kk_std_core_types__optional_drop(frac0_2316, _ctx);
      _x2588 = _frac_14240; /*double*/
      goto _match2589;
    }
    _x2588 = 0x0p+0; /*double*/
    _match2589: ;
    _x2587 = kk_std_num_ddouble__new_Ddouble(_x2588, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    _x2578 = kk_std_num_ddouble__lp__plus__rp_(_x2586, _x2587, _ctx); /*std/num/ddouble/ddouble*/
  }
  return kk_std_time_duration__new_Duration(_x2578, _ctx);
}
 
// Return the duration in rounded SI nano-seconds.

kk_integer_t kk_std_time_duration_nano_seconds(kk_std_time_duration__duration d, kk_context_t* _ctx) { /* (d : duration) -> int */ 
  kk_std_num_ddouble__ddouble _x2591;
  kk_std_num_ddouble__ddouble _x2592;
  kk_std_num_ddouble__ddouble _x = d.secs;
  _x2592 = _x; /*std/time/timestamp/timespan*/
  kk_std_num_ddouble__ddouble _x2593;
  bool _match_2395;
  double _x2594;
  kk_std_core_types__optional _match_2397 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
  if (kk_std_core_types__is_Optional(_match_2397)) {
    kk_box_t _box_x2373 = _match_2397._cons.Optional.value;
    double _frac_1424 = kk_double_unbox(_box_x2373, NULL);
    kk_std_core_types__optional_drop(_match_2397, _ctx);
    _x2594 = _frac_1424; /*double*/
    goto _match2595;
  }
  _x2594 = 0x0p+0; /*double*/
  _match2595: ;
  _match_2395 = (_x2594 == (0x0p+0)); /*bool*/
  if (_match_2395) {
    _x2593 = kk_std_num_ddouble_ddouble_1(kk_integer_from_int(1000000000, _ctx), _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    kk_std_num_ddouble__ddouble _x2597 = kk_std_num_ddouble_ddouble_1(kk_integer_from_int(1000000000, _ctx), _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble _x2598;
    double _x2599;
    kk_std_core_types__optional _match_2396 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
    if (kk_std_core_types__is_Optional(_match_2396)) {
      kk_box_t _box_x2374 = _match_2396._cons.Optional.value;
      double _frac_14240 = kk_double_unbox(_box_x2374, NULL);
      kk_std_core_types__optional_drop(_match_2396, _ctx);
      _x2599 = _frac_14240; /*double*/
      goto _match2600;
    }
    _x2599 = 0x0p+0; /*double*/
    _match2600: ;
    _x2598 = kk_std_num_ddouble__new_Ddouble(_x2599, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    _x2593 = kk_std_num_ddouble__lp__plus__rp_(_x2597, _x2598, _ctx); /*std/num/ddouble/ddouble*/
  }
  _x2591 = kk_std_num_ddouble__lp__star__rp_(_x2592, _x2593, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble_int(_x2591, kk_std_core_types__new_None(_ctx), _ctx);
}
 
// Show a duration in SI seconds.

kk_string_t kk_std_time_duration_show(kk_std_time_duration__duration d, kk_std_core_types__optional max_prec, kk_context_t* _ctx) { /* (d : duration, max-prec : optional<int>) -> string */ 
  kk_string_t _x2602;
  kk_std_num_ddouble__ddouble _x2603;
  kk_std_num_ddouble__ddouble _x = d.secs;
  _x2603 = _x; /*std/time/timestamp/timespan*/
  kk_std_core_types__optional _x2604;
  kk_integer_t _b_2377_2376;
  kk_integer_t _x2605;
  kk_integer_t _x2606;
  if (kk_std_core_types__is_Optional(max_prec)) {
    kk_box_t _box_x2375 = max_prec._cons.Optional.value;
    kk_integer_t _max_prec_1769 = kk_integer_unbox(_box_x2375);
    kk_integer_dup(_max_prec_1769);
    kk_std_core_types__optional_drop(max_prec, _ctx);
    _x2606 = _max_prec_1769; /*int*/
    goto _match2607;
  }
  _x2606 = kk_integer_from_small(9); /*int*/
  _match2607: ;
  _x2605 = kk_integer_abs(_x2606,kk_context()); /*int*/
  _b_2377_2376 = kk_integer_neg(_x2605,kk_context()); /*int*/
  _x2604 = kk_std_core_types__new_Optional(kk_integer_box(_b_2377_2376), _ctx); /*optional<35>*/
  _x2602 = kk_std_num_ddouble_show_fixed(_x2603, _x2604, _ctx); /*string*/
  kk_string_t _x2609;
  kk_define_string_literal(, _s2610, 1, "s")
  _x2609 = kk_string_dup(_s2610); /*string*/
  return kk_std_core__lp__plus__plus__1_rp_(_x2602, _x2609, _ctx);
}
 
// Create a `:duration` of `n` "weeks" (assuming 7 days of 86400s).

kk_std_time_duration__duration kk_std_time_duration_weeks(kk_integer_t n, kk_context_t* _ctx) { /* (n : int) -> duration */ 
  kk_integer_t secs_2325;
  kk_integer_t _x2621 = kk_integer_mul(n,(kk_integer_from_small(7)),kk_context()); /*int*/
  secs_2325 = kk_integer_mul(_x2621,(kk_integer_from_int(86400, _ctx)),kk_context()); /*int*/
  kk_std_num_ddouble__ddouble _x2622;
  kk_std_core_types__optional frac0_2328;
  kk_box_t _x2623;
  double _x2624;
  kk_std_core_types__optional _match_2392 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
  if (kk_std_core_types__is_Optional(_match_2392)) {
    kk_box_t _box_x2379 = _match_2392._cons.Optional.value;
    double _frac_240 = kk_double_unbox(_box_x2379, NULL);
    kk_std_core_types__optional_drop(_match_2392, _ctx);
    _x2624 = _frac_240; /*double*/
    goto _match2625;
  }
  _x2624 = 0x0p+0; /*double*/
  _match2625: ;
  _x2623 = kk_double_box(_x2624, _ctx); /*35*/
  frac0_2328 = kk_std_core_types__new_Optional(_x2623, _ctx); /*optional<double>*/
  bool _match_2391;
  double _x2627;
  if (kk_std_core_types__is_Optional(frac0_2328)) {
    kk_box_t _box_x2382 = frac0_2328._cons.Optional.value;
    double _frac_1424 = kk_double_unbox(_box_x2382, NULL);
    _x2627 = _frac_1424; /*double*/
    goto _match2628;
  }
  _x2627 = 0x0p+0; /*double*/
  _match2628: ;
  _match_2391 = (_x2627 == (0x0p+0)); /*bool*/
  if (_match_2391) {
    kk_std_core_types__optional_drop(frac0_2328, _ctx);
    _x2622 = kk_std_num_ddouble_ddouble_1(secs_2325, _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    kk_std_num_ddouble__ddouble _x2630 = kk_std_num_ddouble_ddouble_1(secs_2325, _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble _x2631;
    double _x2632;
    if (kk_std_core_types__is_Optional(frac0_2328)) {
      kk_box_t _box_x2383 = frac0_2328._cons.Optional.value;
      double _frac_14240 = kk_double_unbox(_box_x2383, NULL);
      kk_std_core_types__optional_drop(frac0_2328, _ctx);
      _x2632 = _frac_14240; /*double*/
      goto _match2633;
    }
    _x2632 = 0x0p+0; /*double*/
    _match2633: ;
    _x2631 = kk_std_num_ddouble__new_Ddouble(_x2632, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    _x2622 = kk_std_num_ddouble__lp__plus__rp_(_x2630, _x2631, _ctx); /*std/num/ddouble/ddouble*/
  }
  return kk_std_time_duration__new_Duration(_x2622, _ctx);
}
 
// Create a `:duration` of `n` "years" (assuming 365 days of 86400s).

kk_std_time_duration__duration kk_std_time_duration_years(kk_integer_t n, kk_context_t* _ctx) { /* (n : int) -> duration */ 
  kk_integer_t secs_2329;
  kk_integer_t _x2635 = kk_integer_mul(n,(kk_integer_from_small(365)),kk_context()); /*int*/
  secs_2329 = kk_integer_mul(_x2635,(kk_integer_from_int(86400, _ctx)),kk_context()); /*int*/
  kk_std_num_ddouble__ddouble _x2636;
  kk_std_core_types__optional frac0_2332;
  kk_box_t _x2637;
  double _x2638;
  kk_std_core_types__optional _match_2390 = kk_std_core_types__new_None(_ctx); /*forall<a> optional<a>*/;
  if (kk_std_core_types__is_Optional(_match_2390)) {
    kk_box_t _box_x2384 = _match_2390._cons.Optional.value;
    double _frac_240 = kk_double_unbox(_box_x2384, NULL);
    kk_std_core_types__optional_drop(_match_2390, _ctx);
    _x2638 = _frac_240; /*double*/
    goto _match2639;
  }
  _x2638 = 0x0p+0; /*double*/
  _match2639: ;
  _x2637 = kk_double_box(_x2638, _ctx); /*35*/
  frac0_2332 = kk_std_core_types__new_Optional(_x2637, _ctx); /*optional<double>*/
  bool _match_2389;
  double _x2641;
  if (kk_std_core_types__is_Optional(frac0_2332)) {
    kk_box_t _box_x2387 = frac0_2332._cons.Optional.value;
    double _frac_1424 = kk_double_unbox(_box_x2387, NULL);
    _x2641 = _frac_1424; /*double*/
    goto _match2642;
  }
  _x2641 = 0x0p+0; /*double*/
  _match2642: ;
  _match_2389 = (_x2641 == (0x0p+0)); /*bool*/
  if (_match_2389) {
    kk_std_core_types__optional_drop(frac0_2332, _ctx);
    _x2636 = kk_std_num_ddouble_ddouble_1(secs_2329, _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    kk_std_num_ddouble__ddouble _x2644 = kk_std_num_ddouble_ddouble_1(secs_2329, _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble _x2645;
    double _x2646;
    if (kk_std_core_types__is_Optional(frac0_2332)) {
      kk_box_t _box_x2388 = frac0_2332._cons.Optional.value;
      double _frac_14240 = kk_double_unbox(_box_x2388, NULL);
      kk_std_core_types__optional_drop(frac0_2332, _ctx);
      _x2646 = _frac_14240; /*double*/
      goto _match2647;
    }
    _x2646 = 0x0p+0; /*double*/
    _match2647: ;
    _x2645 = kk_std_num_ddouble__new_Ddouble(_x2646, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    _x2636 = kk_std_num_ddouble__lp__plus__rp_(_x2644, _x2645, _ctx); /*std/num/ddouble/ddouble*/
  }
  return kk_std_time_duration__new_Duration(_x2636, _ctx);
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
    kk_std_num_ddouble__ddouble _x2528 = kk_std_num_ddouble__new_Ddouble(0x0p+0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    kk_std_time_duration_duration0 = kk_std_time_duration__new_Duration(_x2528, _ctx); /*std/time/duration/duration*/
  }
  {
    kk_std_num_ddouble__ddouble _x2649 = kk_std_num_ddouble__new_Ddouble(0x0p+0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    kk_std_time_duration_zero = kk_std_time_duration__new_Duration(_x2649, _ctx); /*std/time/duration/duration*/
  }
}
