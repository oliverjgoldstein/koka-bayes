#pragma once
#ifndef kk_exn_dash_get_H
#define kk_exn_dash_get_H
// Koka generated module: "exn-get", koka version: 2.1.2
#include <kklib.h>
#include "std_core_types.h"
#include "std_core_hnd.h"
#include "std_core.h"

// type declarations

// value declarations

kk_box_t kk_exn_dash_get_exn_get(kk_std_core__list xs, kk_integer_t index, kk_context_t* _ctx); /* forall<a> (xs : list<a>, index : int) -> exn a */ 

static inline bool kk_exn_dash_get_non__empty(kk_std_core__list l, kk_context_t* _ctx) { /* forall<a> (l : list<a>) -> bool */ 
  if (kk_std_core__is_Nil(l)) {
    return false;
  }
  struct kk_std_core_Cons* _con237 = kk_std_core__as_Cons(l);
  kk_std_core__list_dropn(l, ((int32_t)2), _ctx);
  return true;
}

void kk_exn_dash_get__init(kk_context_t* _ctx);

#endif // header
