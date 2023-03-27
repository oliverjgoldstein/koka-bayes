#pragma once
#ifndef kk_climate_dash_change_H
#define kk_climate_dash_change_H
// Koka generated module: "climate-change", koka version: 2.1.2
#include <kklib.h>
#include "std_core_types.h"
#include "std_core_hnd.h"
#include "std_core.h"
#include "effects_dash_and_dash_types.h"
#include "exn_dash_get.h"
#include "model_dash_resources.h"

// type declarations

// value declarations

double kk_climate_dash_change__mlift2750_convert__uncertainty__to__rand(double uncertainty, kk_context_t* _ctx); /* (uncertainty : double) -> <exn,effects-and-types/sample> double */ 

kk_std_core__list kk_climate_dash_change_convert__uncertainty__to__rand(kk_std_core__list vs, kk_context_t* _ctx); /* (vs : effects-and-types/row_vector) -> <exn,effects-and-types/sample> effects-and-types/row_vector */ 


// lift anonymous function
struct kk_climate_dash_change_mult__thunk_fun3483__t {
  struct kk_function_s _base;
  double x;
};
extern double kk_climate_dash_change_mult__thunk_fun3483(kk_function_t _fself, double v, kk_context_t* _ctx);
static inline kk_function_t kk_climate_dash_change_new_mult__thunk_fun3483(double x, kk_context_t* _ctx) {
  struct kk_climate_dash_change_mult__thunk_fun3483__t* _self = kk_function_alloc_as(struct kk_climate_dash_change_mult__thunk_fun3483__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_change_mult__thunk_fun3483, kk_context());
  _self->x = x;
  return &_self->_base;
}


static inline kk_function_t kk_climate_dash_change_mult__thunk(double x, kk_context_t* _ctx) { /* forall<e> (x : double) -> ((v : double) -> e double) */ 
  return kk_climate_dash_change_new_mult__thunk_fun3483(x, _ctx);
}


// lift anonymous function
struct kk_climate_dash_change_multivariate__gaussian_fun3484__t {
  struct kk_function_s _base;
  double mean;
  double std__dev;
};
extern kk_box_t kk_climate_dash_change_multivariate__gaussian_fun3484(kk_function_t _fself, kk_integer_t _b_2969, kk_context_t* _ctx);
static inline kk_function_t kk_climate_dash_change_new_multivariate__gaussian_fun3484(double mean, double std__dev, kk_context_t* _ctx) {
  struct kk_climate_dash_change_multivariate__gaussian_fun3484__t* _self = kk_function_alloc_as(struct kk_climate_dash_change_multivariate__gaussian_fun3484__t, 1, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_change_multivariate__gaussian_fun3484, kk_context());
  _self->mean = mean;
  _self->std__dev = std__dev;
  return &_self->_base;
}


static inline kk_std_core__list kk_climate_dash_change_multivariate__gaussian(kk_integer_t dimension, double mean, double std__dev, kk_context_t* _ctx) { /* (dimension : int, mean : double, std_dev : double) -> effects-and-types/sample list<double> */ 
  return kk_std_core__lift21054_list_1(kk_climate_dash_change_new_multivariate__gaussian_fun3484(mean, std__dev, _ctx), kk_integer_from_small(1), dimension, kk_std_core__new_Nil(_ctx), _ctx);
}

kk_std_core__list kk_climate_dash_change_plus(kk_std_core__list xs, kk_std_core__list ys, kk_context_t* _ctx); /* (xs : effects-and-types/row_vector, ys : effects-and-types/row_vector) -> exn effects-and-types/row_vector */ 

kk_function_t kk_climate_dash_change_score__thunk(double score__std__dev, kk_context_t* _ctx); /* forall<e> (score_std_dev : double) -> ((true_val : double, pred_val : double) -> <effects-and-types/score|e> ()) */ 


// lift anonymous function
struct kk_climate_dash_change_mult_fun3523__t {
  struct kk_function_s _base;
  kk_function_t _b_3025_3022;
};
extern kk_box_t kk_climate_dash_change_mult_fun3523(kk_function_t _fself, kk_box_t _b_3023, kk_context_t* _ctx);
static inline kk_function_t kk_climate_dash_change_new_mult_fun3523(kk_function_t _b_3025_3022, kk_context_t* _ctx) {
  struct kk_climate_dash_change_mult_fun3523__t* _self = kk_function_alloc_as(struct kk_climate_dash_change_mult_fun3523__t, 2, _ctx);
  _self->_base.fun = kk_cfun_ptr_box(&kk_climate_dash_change_mult_fun3523, kk_context());
  _self->_b_3025_3022 = _b_3025_3022;
  return &_self->_base;
}


static inline kk_std_core__list kk_climate_dash_change_mult(double x, kk_std_core__list ys, kk_context_t* _ctx) { /* (x : double, ys : effects-and-types/row_vector) -> effects-and-types/row_vector */ 
  kk_function_t _b_3025_3022 = kk_climate_dash_change_mult__thunk(x, _ctx); /*(v : double) -> double*/;
  return kk_std_core_map_5(ys, kk_climate_dash_change_new_mult_fun3523(_b_3025_3022, _ctx), _ctx);
}

kk_std_core__list kk_climate_dash_change_score__predictions(kk_std_core__list true__values, kk_std_core__list predicted__values, double score__std__dev, kk_context_t* _ctx); /* (true_values : effects-and-types/row_vector, predicted_values : effects-and-types/row_vector, score_std_dev : double) -> <exn,effects-and-types/score> list<()> */ 

double kk_climate_dash_change__mlift2751_linear__gaussian__climate__data(kk_integer_t i0, kk_std_core__list _y_31, kk_context_t* _ctx); /* forall<h> (i0 : int, list<double>) -> <local<h>,exn,effects-and-types/sample,effects-and-types/score> double */ 

kk_unit_t kk_climate_dash_change__mlift2752_linear__gaussian__climate__data(kk_std_core__list wild__0, kk_context_t* _ctx); /* forall<h> (wild_0 : list<()>) -> <exn,effects-and-types/score,local<h>,effects-and-types/sample> () */ 

kk_unit_t kk_climate_dash_change__mlift2753_linear__gaussian__climate__data(kk_std_core__list month__ys, double score__var, kk_std_core__list predictions, kk_context_t* _ctx); /* forall<h> (month_ys : effects-and-types/row_vector, score_var : double, predictions : effects-and-types/row_vector) -> <exn,local<h>,effects-and-types/score,effects-and-types/sample> () */ 

kk_unit_t kk_climate_dash_change__mlift2754_linear__gaussian__climate__data(kk_std_core__list c__row, kk_std_core__list month__ys, double score__var, kk_std_core__list v__row, double _y_27, kk_context_t* _ctx); /* forall<h> (c_row : list<double>, month_ys : effects-and-types/row_vector, score_var : double, v_row : effects-and-types/row_vector, double) -> <exn,local<h>,effects-and-types/score,effects-and-types/sample> () */ 

kk_unit_t kk_climate_dash_change__mlift2755_linear__gaussian__climate__data(kk_std_core__list c__row, kk_integer_t i, kk_std_core__list month__ys, double score__var, kk_std_core__list v__row, kk_std_core__list _y_26, kk_context_t* _ctx); /* forall<h> (c_row : list<double>, i : int, month_ys : effects-and-types/row_vector, score_var : double, v_row : effects-and-types/row_vector, list<double>) -> <local<h>,exn,effects-and-types/score,effects-and-types/sample> () */ 

kk_unit_t kk_climate_dash_change__mlift2756_linear__gaussian__climate__data(kk_std_core__list c__row, kk_integer_t i, kk_std_core__list month__ys, double score__var, kk_ref_t x, kk_std_core__list v__row, kk_context_t* _ctx); /* forall<h> (c_row : list<double>, i : int, month_ys : effects-and-types/row_vector, score_var : double, x : local-var<h,list<double>>, v_row : effects-and-types/row_vector) -> <exn,effects-and-types/sample,local<h>,effects-and-types/score> () */ 

kk_unit_t kk_climate_dash_change__mlift2757_linear__gaussian__climate__data(kk_integer_t i, kk_std_core__list month__vs, kk_std_core__list month__ys, double score__var, kk_ref_t x, kk_std_core__list c__row, kk_context_t* _ctx); /* forall<h> (i : int, month_vs : effects-and-types/row_vector, month_ys : effects-and-types/row_vector, score_var : double, x : local-var<h,list<double>>, c_row : list<double>) -> <effects-and-types/sample,exn,local<h>,effects-and-types/score> () */ 

kk_unit_t kk_climate_dash_change__mlift2758_linear__gaussian__climate__data(kk_integer_t i, kk_std_core__list month__ys, double score__var, kk_ref_t x, kk_std_core__list month__vs, kk_context_t* _ctx); /* forall<h> (i : int, month_ys : effects-and-types/row_vector, score_var : double, x : local-var<h,list<double>>, month_vs : effects-and-types/row_vector) -> <exn,local<h>,effects-and-types/sample,effects-and-types/score> () */ 

kk_unit_t kk_climate_dash_change__mlift2759_linear__gaussian__climate__data(kk_integer_t i, double score__var, kk_std_core__list vs, kk_ref_t x, kk_std_core__list month__ys, kk_context_t* _ctx); /* forall<h> (i : int, score_var : double, vs : list<effects-and-types/row_vector>, x : local-var<h,list<double>>, month_ys : effects-and-types/row_vector) -> <exn,local<h>,effects-and-types/sample,effects-and-types/score> () */ 

kk_unit_t kk_climate_dash_change__mlift2760_linear__gaussian__climate__data(kk_std_core__list _y_12, double diff, double subtract, kk_ref_t x, double _y_13, kk_context_t* _ctx); /* forall<h> (list<double>, diff : double, subtract : double, x : local-var<h,list<double>>, double) -> <effects-and-types/sample,local<h>,exn,effects-and-types/score> () */ 

kk_unit_t kk_climate_dash_change__mlift2761_linear__gaussian__climate__data(double diff, double subtract, kk_ref_t x, kk_std_core__list _y_12, kk_context_t* _ctx); /* forall<h> (diff : double, subtract : double, x : local-var<h,list<double>>, list<double>) -> <local<h>,effects-and-types/sample,exn,effects-and-types/score> () */ 

kk_unit_t kk_climate_dash_change__mlift2762_linear__gaussian__climate__data(kk_std_core__list _y_17, double a__val, double w__val, kk_ref_t x, double _y_19, kk_context_t* _ctx); /* forall<h> (list<double>, a_val : double, w_val : double, x : local-var<h,list<double>>, double) -> <exn,local<h>,effects-and-types/sample,effects-and-types/score> () */ 

kk_unit_t kk_climate_dash_change__mlift2763_linear__gaussian__climate__data(kk_std_core__list _y_17, double a__val, kk_integer_t i, double w__val, kk_ref_t x, kk_std_core__list _y_18, kk_context_t* _ctx); /* forall<h> (list<double>, a_val : double, i : int, w_val : double, x : local-var<h,list<double>>, list<double>) -> <local<h>,exn,effects-and-types/sample,effects-and-types/score> () */ 

kk_unit_t kk_climate_dash_change__mlift2764_linear__gaussian__climate__data(double a__val, kk_integer_t i, double w__val, kk_ref_t x, kk_std_core__list _y_17, kk_context_t* _ctx); /* forall<h> (a_val : double, i : int, w_val : double, x : local-var<h,list<double>>, list<double>) -> <local<h>,exn,effects-and-types/sample,effects-and-types/score> () */ 

kk_unit_t kk_climate_dash_change__mlift2765_linear__gaussian__climate__data(double a__val, kk_integer_t i, kk_ref_t x, double w__val, kk_context_t* _ctx); /* forall<h> (a_val : double, i : int, x : local-var<h,list<double>>, w_val : double) -> <effects-and-types/sample,exn,local<h>,effects-and-types/score> () */ 

kk_unit_t kk_climate_dash_change__mlift2766_linear__gaussian__climate__data(kk_integer_t i, kk_ref_t x, double a__val, kk_context_t* _ctx); /* forall<h> (i : int, x : local-var<h,list<double>>, a_val : double) -> <effects-and-types/sample,exn,local<h>,effects-and-types/score> () */ 

kk_unit_t kk_climate_dash_change__mlift2767_linear__gaussian__climate__data(kk_integer_t i, double score__var, kk_std_core__list vs, kk_ref_t x, kk_std_core__list ys, kk_unit_t _c_21, kk_context_t* _ctx); /* forall<h> (i : int, score_var : double, vs : list<effects-and-types/row_vector>, x : local-var<h,list<double>>, ys : list<effects-and-types/row_vector>, ()) -> () */ 

kk_std_core__list kk_climate_dash_change__mlift2768_linear__gaussian__climate__data(kk_ref_t x, kk_unit_t wild__1, kk_context_t* _ctx); /* forall<h> (x : local-var<h,list<double>>, wild_1 : ()) -> <exn,local<h>,effects-and-types/sample,effects-and-types/score> list<double> */ 

kk_function_t kk_climate_dash_change_linear__gaussian__climate__data(kk_std_core__list ys, kk_std_core__list vs, bool print, double diff, double subtract, double score__var, kk_context_t* _ctx); /* (ys : list<effects-and-types/row_vector>, vs : list<effects-and-types/row_vector>, print : bool, diff : double, subtract : double, score_var : double) -> effects-and-types/model<list<double>,exn> */ 

void kk_climate_dash_change__init(kk_context_t* _ctx);

#endif // header
