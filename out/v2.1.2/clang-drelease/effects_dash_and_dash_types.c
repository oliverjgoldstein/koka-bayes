// Koka generated module: "effects-and-types", koka version: 2.1.2
#include "effects_dash_and_dash_types.h"
 
// runtime tag for the `:sample` effect

kk_std_core_hnd__htag kk_effects_dash_and_dash_types__tag_sample;
 
// handler for the `:sample` effect

kk_box_t kk_effects_dash_and_dash_types__handle_sample(int32_t cfc, kk_effects_dash_and_dash_types__hnd_sample hnd, kk_function_t ret, kk_function_t action, kk_context_t* _ctx) { /* forall<a,e,b> (cfc : int32, hnd : .hnd-sample<e,b>, ret : (res : a) -> e b, action : () -> <sample|e> a) -> e b */ 
  kk_std_core_hnd__htag _x474 = kk_std_core_hnd__htag_dup(kk_effects_dash_and_dash_types__tag_sample); /*std/core/hnd/htag<effects-and-types/.hnd-sample>*/
  return kk_std_core_hnd__hhandle(_x474, cfc, kk_effects_dash_and_dash_types__hnd_sample_box(hnd, _ctx), ret, action, _ctx);
}
 
// runtime tag for the `:score` effect

kk_std_core_hnd__htag kk_effects_dash_and_dash_types__tag_score;
 
// handler for the `:score` effect

kk_box_t kk_effects_dash_and_dash_types__handle_score(int32_t cfc, kk_effects_dash_and_dash_types__hnd_score hnd, kk_function_t ret, kk_function_t action, kk_context_t* _ctx) { /* forall<a,e,b> (cfc : int32, hnd : .hnd-score<e,b>, ret : (res : a) -> e b, action : () -> <score|e> a) -> e b */ 
  kk_std_core_hnd__htag _x477 = kk_std_core_hnd__htag_dup(kk_effects_dash_and_dash_types__tag_score); /*std/core/hnd/htag<effects-and-types/.hnd-score>*/
  return kk_std_core_hnd__hhandle(_x477, cfc, kk_effects_dash_and_dash_types__hnd_score_box(hnd, _ctx), ret, action, _ctx);
}
 
// runtime tag for the `:yield` effect

kk_std_core_hnd__htag kk_effects_dash_and_dash_types__tag_yield;
 
// handler for the `:yield` effect

kk_box_t kk_effects_dash_and_dash_types__handle_yield(int32_t cfc, kk_effects_dash_and_dash_types__hnd_yield hnd, kk_function_t ret, kk_function_t action, kk_context_t* _ctx) { /* forall<a,e,b> (cfc : int32, hnd : .hnd-yield<e,b>, ret : (res : a) -> e b, action : () -> <yield|e> a) -> e b */ 
  kk_std_core_hnd__htag _x480 = kk_std_core_hnd__htag_dup(kk_effects_dash_and_dash_types__tag_yield); /*std/core/hnd/htag<effects-and-types/.hnd-yield>*/
  return kk_std_core_hnd__hhandle(_x480, cfc, kk_effects_dash_and_dash_types__hnd_yield_box(hnd, _ctx), ret, action, _ctx);
}

// initialization
void kk_effects_dash_and_dash_types__init(kk_context_t* _ctx){
  static bool _initialized = false;
  if (_initialized) return;
  _initialized = true;
  kk_std_core_types__init(_ctx);
  kk_std_core_hnd__init(_ctx);
  kk_std_core__init(_ctx);
  kk_std_num_random__init(_ctx);
  {
    kk_string_t _x472;
    kk_define_string_literal(, _s473, 24, "sample.effects-and-types")
    _x472 = kk_string_dup(_s473); /*string*/
    kk_effects_dash_and_dash_types__tag_sample = kk_std_core_hnd__new_Htag(_x472, _ctx); /*std/core/hnd/htag<effects-and-types/.hnd-sample>*/
  }
  {
    kk_string_t _x475;
    kk_define_string_literal(, _s476, 23, "score.effects-and-types")
    _x475 = kk_string_dup(_s476); /*string*/
    kk_effects_dash_and_dash_types__tag_score = kk_std_core_hnd__new_Htag(_x475, _ctx); /*std/core/hnd/htag<effects-and-types/.hnd-score>*/
  }
  {
    kk_string_t _x478;
    kk_define_string_literal(, _s479, 23, "yield.effects-and-types")
    _x478 = kk_string_dup(_s479); /*string*/
    kk_effects_dash_and_dash_types__tag_yield = kk_std_core_hnd__new_Htag(_x478, _ctx); /*std/core/hnd/htag<effects-and-types/.hnd-yield>*/
  }
}
