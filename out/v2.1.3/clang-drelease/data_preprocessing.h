#pragma once
#ifndef kk_data_preprocessing_H
#define kk_data_preprocessing_H
// Koka generated module: "data/preprocessing", koka version: 2.1.3
#include <kklib.h>
#include "std_core_types.h"
#include "std_core_hnd.h"
#include "std_core.h"
#include "std_num_double.h"
#include "std_os_path.h"
#include "std_os_file.h"
#include "exn_dash_get.h"

// type declarations

// value declarations

kk_unit_t kk_data_preprocessing__mlift1945_all__elements__equal(kk_ref_t bool__val, kk_integer_t first__length, kk_integer_t _y_1, kk_context_t* _ctx); /* forall<h> (bool_val : local-var<h,bool>, first_length : int, int) -> exn () */ 

bool kk_data_preprocessing__mlift1946_all__elements__equal(kk_ref_t bool__val, kk_unit_t wild__0, kk_context_t* _ctx); /* forall<h> (bool_val : local-var<h,bool>, wild_0 : ()) -> <exn,local<h>> bool */ 

bool kk_data_preprocessing__mlift1947_all__elements__equal(kk_std_core__list list, kk_integer_t first__length, kk_context_t* _ctx); /* forall<h> (list : list<int>, first_length : int) -> exn bool */ 

bool kk_data_preprocessing_all__elements__equal(kk_std_core__list list, kk_context_t* _ctx); /* (list : list<int>) -> exn bool */ 


// lift anonymous function
struct kk_data_preprocessing_get__thunk_fun2888__t {
  struct kk_function_s _base;
  kk_integer_t index;
};
extern kk_std_core_types__maybe kk_data_preprocessing_get__thunk_fun2888(kk_function_t _fself, kk_std_core__list list, kk_context_t* _ctx);
static inline kk_function_t kk_data_preprocessing_new_get__thunk_fun2888(kk_integer_t index, kk_context_t* _ctx) {
  struct kk_data_preprocessing_get__thunk_fun2888__t* _self = kk_function_alloc_as(struct kk_data_preprocessing_get__thunk_fun2888__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_data_preprocessing_get__thunk_fun2888, kk_context());
  _self->index = index;
  return &_self->_base;
}


static inline kk_function_t kk_data_preprocessing_get__thunk(kk_integer_t index, kk_context_t* _ctx) { /* (index : int) -> ((list : list<double>) -> maybe<double>) */ 
  return kk_data_preprocessing_new_get__thunk_fun2888(index, _ctx);
}

kk_std_core__list kk_data_preprocessing_remove__maybes(kk_std_core__list list, kk_std_core__list return__list, kk_context_t* _ctx); /* (list : list<maybe<double>>, return_list : list<double>) -> exn list<double> */ 

kk_std_core__list kk_data_preprocessing__mlift1948_by__month(kk_std_core__list _y_12, kk_context_t* _ctx); /* (list<maybe<double>>) -> exn list<double> */ 

kk_std_core__list kk_data_preprocessing_by__month(kk_std_core__list months0, kk_integer_t index, kk_context_t* _ctx); /* (months : list<list<double>>, index : int) -> exn list<double> */ 

kk_std_core__list kk_data_preprocessing_list__of__lists(kk_std_core__list list, kk_integer_t length, kk_context_t* _ctx); /* (list : list<double>, length : int) -> div list<list<double>> */ 


// lift anonymous function
struct kk_data_preprocessing_list__of__lists__thunk_fun2936__t {
  struct kk_function_s _base;
  kk_integer_t length;
};
extern kk_std_core__list kk_data_preprocessing_list__of__lists__thunk_fun2936(kk_function_t _fself, kk_std_core__list list, kk_context_t* _ctx);
static inline kk_function_t kk_data_preprocessing_new_list__of__lists__thunk_fun2936(kk_integer_t length, kk_context_t* _ctx) {
  struct kk_data_preprocessing_list__of__lists__thunk_fun2936__t* _self = kk_function_alloc_as(struct kk_data_preprocessing_list__of__lists__thunk_fun2936__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_data_preprocessing_list__of__lists__thunk_fun2936, kk_context());
  _self->length = length;
  return &_self->_base;
}


static inline kk_function_t kk_data_preprocessing_list__of__lists__thunk(kk_integer_t length, kk_context_t* _ctx) { /* forall<e> (length : int) -> ((list : list<double>) -> <div|e> list<list<double>>) */ 
  return kk_data_preprocessing_new_list__of__lists__thunk_fun2936(length, _ctx);
}


// lift anonymous function
struct kk_data_preprocessing_convert__to__groups_fun2937__t {
  struct kk_function_s _base;
  kk_function_t _b_2288_2285;
};
extern kk_box_t kk_data_preprocessing_convert__to__groups_fun2937(kk_function_t _fself, kk_box_t _b_2286, kk_context_t* _ctx);
static inline kk_function_t kk_data_preprocessing_new_convert__to__groups_fun2937(kk_function_t _b_2288_2285, kk_context_t* _ctx) {
  struct kk_data_preprocessing_convert__to__groups_fun2937__t* _self = kk_function_alloc_as(struct kk_data_preprocessing_convert__to__groups_fun2937__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_data_preprocessing_convert__to__groups_fun2937, kk_context());
  _self->_b_2288_2285 = _b_2288_2285;
  return &_self->_base;
}


static inline kk_std_core__list kk_data_preprocessing_convert__to__groups(kk_std_core__list months0, kk_integer_t group__size, kk_context_t* _ctx) { /* (months : list<list<double>>, group_size : int) -> div list<list<list<double>>> */ 
  kk_function_t _b_2288_2285 = kk_data_preprocessing_list__of__lists__thunk(group__size, _ctx); /*(list : list<double>) -> div list<list<double>>*/;
  return kk_std_core_map_5(months0, kk_data_preprocessing_new_convert__to__groups_fun2937(_b_2288_2285, _ctx), _ctx);
}

kk_std_core__list kk_data_preprocessing_length__months(kk_std_core__list months0, kk_context_t* _ctx); /* (months : list<list<double>>) -> list<int> */ 

kk_std_core__list kk_data_preprocessing__mlift1949_months(kk_ref_t list__of__months, kk_unit_t wild__1, kk_context_t* _ctx); /* forall<h> (list_of_months : local-var<h,list<list<double>>>, wild_1 : ()) -> <local<h>,exn> list<list<double>> */ 

kk_std_core__list kk_data_preprocessing__mlift1950_months(kk_ref_t list__of__months, kk_std_core__list _y_19, kk_context_t* _ctx); /* forall<h> (list_of_months : local-var<h,list<list<double>>>, list<list<double>>) -> <local<h>,exn> list<list<double>> */ 

kk_unit_t kk_data_preprocessing__mlift1951_months(kk_std_core__list _y_15, kk_ref_t list__of__months, kk_std_core__list _y_16, kk_context_t* _ctx); /* forall<h> (list<list<double>>, list_of_months : local-var<h,list<list<double>>>, list<double>) -> exn () */ 

kk_unit_t kk_data_preprocessing__mlift1952_months(kk_integer_t i, kk_ref_t list__of__months, kk_std_core__list months0, kk_std_core__list _y_15, kk_context_t* _ctx); /* forall<h> (i : int, list_of_months : local-var<h,list<list<double>>>, months : list<list<double>>, list<list<double>>) -> <local<h>,exn> () */ 

kk_std_core__list kk_data_preprocessing__mlift1953_months(kk_ref_t list__of__months, kk_unit_t wild__0, kk_context_t* _ctx); /* forall<h> (list_of_months : local-var<h,list<list<double>>>, wild_0 : ()) -> <exn,local<h>> list<list<double>> */ 

kk_std_core__list kk_data_preprocessing__mlift1954_months(kk_std_core__list months0, bool _y_14, kk_context_t* _ctx); /* forall<h> (months : list<list<double>>, bool) -> exn list<list<double>> */ 

kk_std_core__list kk_data_preprocessing_months(kk_std_core__list months0, kk_context_t* _ctx); /* (months : list<list<double>>) -> exn list<list<double>> */ 

kk_std_core_types__tuple2_ kk_data_preprocessing__mlift1955_pre__process__data(kk_std_core__list uncertainties__by__month, kk_std_core__list temperatures__by__month, kk_context_t* _ctx); /* (uncertainties_by_month : list<list<double>>, temperatures_by_month : list<list<double>>) -> exn (list<list<list<double>>>, list<list<list<double>>>) */ 

kk_std_core_types__tuple2_ kk_data_preprocessing__mlift1956_pre__process__data(kk_std_core__list temperatures__by__year, kk_std_core__list uncertainties__by__month, kk_context_t* _ctx); /* (temperatures_by_year : list<list<double>>, uncertainties_by_month : list<list<double>>) -> exn (list<list<list<double>>>, list<list<list<double>>>) */ 

kk_std_core_types__tuple2_ kk_data_preprocessing__mlift1957_pre__process__data(kk_std_core__list uncertainties, kk_std_core__list temperatures, kk_context_t* _ctx); /* (uncertainties : list<double>, temperatures : list<double>) -> exn (list<list<list<double>>>, list<list<list<double>>>) */ 

kk_std_core_types__tuple2_ kk_data_preprocessing__mlift1958_pre__process__data(kk_std_core__list maybe__temperatures, kk_std_core__list uncertainties, kk_context_t* _ctx); /* (maybe_temperatures : list<maybe<double>>, uncertainties : list<double>) -> exn (list<list<list<double>>>, list<list<list<double>>>) */ 

kk_std_core_types__tuple2_ kk_data_preprocessing__mlift1959_pre__process__data(kk_std_core__list temperatures1, kk_std_core__list uncertainties1, kk_std_core__list uncertainties2, kk_std_core__list temperatures2, kk_context_t* _ctx); /* (temperatures1 : list<maybe<double>>, uncertainties1 : list<maybe<double>>, uncertainties2 : list<maybe<double>>, temperatures2 : list<maybe<double>>) -> <exn,fsys,div> (list<list<list<double>>>, list<list<list<double>>>) */ 

kk_std_core_types__tuple2_ kk_data_preprocessing__mlift1960_pre__process__data(kk_std_core__list temperatures1, kk_std_core__list uncertainties1, kk_std_core__list uncertainties2, kk_string_t _y_30, kk_context_t* _ctx); /* (temperatures1 : list<maybe<double>>, uncertainties1 : list<maybe<double>>, uncertainties2 : list<maybe<double>>, string) -> <exn,fsys> (list<list<list<double>>>, list<list<list<double>>>) */ 

kk_std_core_types__tuple2_ kk_data_preprocessing__mlift1961_pre__process__data(kk_std_core__list uncertainties1, kk_std_core__list uncertainties2, kk_std_core__list temperatures1, kk_context_t* _ctx); /* (uncertainties1 : list<maybe<double>>, uncertainties2 : list<maybe<double>>, temperatures1 : list<maybe<double>>) -> <exn,fsys,div> (list<list<list<double>>>, list<list<list<double>>>) */ 

kk_std_core_types__tuple2_ kk_data_preprocessing__mlift1962_pre__process__data(kk_std_core__list uncertainties1, kk_std_core__list uncertainties2, kk_string_t _y_28, kk_context_t* _ctx); /* (uncertainties1 : list<maybe<double>>, uncertainties2 : list<maybe<double>>, string) -> <exn,fsys> (list<list<list<double>>>, list<list<list<double>>>) */ 

kk_std_core_types__tuple2_ kk_data_preprocessing__mlift1963_pre__process__data(kk_std_core__list uncertainties1, kk_std_core__list uncertainties2, kk_context_t* _ctx); /* (uncertainties1 : list<maybe<double>>, uncertainties2 : list<maybe<double>>) -> <exn,fsys,div> (list<list<list<double>>>, list<list<list<double>>>) */ 

kk_std_core_types__tuple2_ kk_data_preprocessing__mlift1964_pre__process__data(kk_std_core__list uncertainties1, kk_string_t _y_26, kk_context_t* _ctx); /* (uncertainties1 : list<maybe<double>>, string) -> <exn,fsys> (list<list<list<double>>>, list<list<list<double>>>) */ 

kk_std_core_types__tuple2_ kk_data_preprocessing__mlift1965_pre__process__data(kk_std_core__list uncertainties1, kk_context_t* _ctx); /* (uncertainties1 : list<maybe<double>>) -> <exn,fsys,div> (list<list<list<double>>>, list<list<list<double>>>) */ 

kk_std_core_types__tuple2_ kk_data_preprocessing__mlift1966_pre__process__data(kk_string_t _y_24, kk_context_t* _ctx); /* (string) -> <exn,fsys> (list<list<list<double>>>, list<list<list<double>>>) */ 

kk_std_core_types__tuple2_ kk_data_preprocessing_pre__process__data(kk_context_t* _ctx); /* () -> <pure,fsys> (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>) */ 

void kk_data_preprocessing__init(kk_context_t* _ctx);

#endif // header
