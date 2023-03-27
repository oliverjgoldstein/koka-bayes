#pragma once
#ifndef kk_model_dash_resources_H
#define kk_model_dash_resources_H
// Koka generated module: "model-resources", koka version: 2.1.3
#include <kklib.h>
#include "std_core_types.h"
#include "std_core_hnd.h"
#include "std_core.h"
#include "std_num_double.h"
#include "std_num_random.h"
#include "effects_dash_and_dash_types.h"
#include "handlers.h"

// type declarations

// value declarations

bool kk_model_dash_resources__mlift3168_bernoulli(double p, double g, kk_context_t* _ctx); /* (p : double, g : double) -> effects-and-types/sample bool */ 

bool kk_model_dash_resources_bernoulli(double p, kk_context_t* _ctx); /* (p : double) -> effects-and-types/sample bool */ 

double kk_model_dash_resources_box_muller(double u1, double u2, kk_context_t* _ctx); /* (u1 : double, u2 : double) -> double */ 

extern kk_std_core__list kk_model_dash_resources_dataset;

static inline double kk_model_dash_resources_square(double x, kk_context_t* _ctx) { /* (x : double) -> double */ 
  return (x * x);
}

extern kk_std_core__list kk_model_dash_resources_gaussian__dataset;

extern kk_std_core__list kk_model_dash_resources_gaussian__five;

kk_effects_dash_and_dash_types__exp kk_model_dash_resources_normal__pdf(double mean, double sdv, double x, kk_context_t* _ctx); /* (mean : double, sdv : double, x : double) -> effects-and-types/exp */ 

kk_function_t kk_model_dash_resources__mlift3169_fit(kk_function_t f, kk_std_core__list wild__, kk_context_t* _ctx); /* (f : (double) -> double, wild_ : list<()>) -> <effects-and-types/score,std/num/random/random,effects-and-types/sample> ((double) -> double) */ 

kk_function_t kk_model_dash_resources__mlift3170_fit(kk_std_core__list dataset0, kk_function_t f, kk_context_t* _ctx); /* (dataset : effects-and-types/two_d_data, f : (double) -> double) -> <effects-and-types/sample,effects-and-types/score,std/num/random/random> ((double) -> double) */ 

kk_function_t kk_model_dash_resources_fit(kk_function_t model, kk_std_core__list dataset0, kk_context_t* _ctx); /* (model : effects-and-types/regression, dataset : effects-and-types/two_d_data) -> effects-and-types/regression */ 

double kk_model_dash_resources__mlift3171_fit__1d__gaussian(double f, kk_std_core__list wild__, kk_context_t* _ctx); /* (f : double, wild_ : list<()>) -> <effects-and-types/score,std/num/random/random,effects-and-types/sample> double */ 

double kk_model_dash_resources__mlift3172_fit__1d__gaussian(kk_std_core__list dataset0, double f, kk_context_t* _ctx); /* (dataset : effects-and-types/data_1d, f : double) -> <effects-and-types/sample,effects-and-types/score,std/num/random/random> double */ 

kk_function_t kk_model_dash_resources_fit__1d__gaussian(kk_function_t model, kk_std_core__list dataset0, kk_context_t* _ctx); /* (model : effects-and-types/nmodel<double>, dataset : effects-and-types/data_1d) -> effects-and-types/nmodel<double> */ 

double kk_model_dash_resources_gamma(double x, kk_context_t* _ctx); /* forall<h> (double) -> <st<h>,div> double */ 

double kk_model_dash_resources__mlift3173_standard_normal(double _y_8, double _y_9, kk_context_t* _ctx); /* (double, double) -> effects-and-types/sample double */ 

double kk_model_dash_resources__mlift3174_standard_normal(double _y_8, kk_context_t* _ctx); /* (double) -> effects-and-types/sample double */ 

double kk_model_dash_resources_standard_normal(kk_context_t* _ctx); /* () -> effects-and-types/sample double */ 

double kk_model_dash_resources__mlift3175_normal(double mean, double sdv, double _y_10, kk_context_t* _ctx); /* (mean : double, sdv : double, double) -> effects-and-types/sample double */ 

double kk_model_dash_resources_normal(double mean, double sdv, kk_context_t* _ctx); /* (mean : double, sdv : double) -> effects-and-types/sample double */ 

kk_function_t kk_model_dash_resources_gaussian__model(kk_context_t* _ctx); /* () -> effects-and-types/nmodel<double> */ 

kk_std_core_types__tuple2_ kk_model_dash_resources__mlift3176_generate__synthetic__lr__data(double _y_12, bool _y_13, kk_context_t* _ctx); /* (double, bool) -> <effects-and-types/sample,std/num/random/random> (double, bool) */ 

kk_std_core_types__tuple2_ kk_model_dash_resources__mlift3177_generate__synthetic__lr__data(double _y_12, kk_context_t* _ctx); /* (double) -> <effects-and-types/sample,std/num/random/random> (double, bool) */ 

kk_std_core__list kk_model_dash_resources_generate__synthetic__lr__data(kk_integer_t num, kk_context_t* _ctx); /* (num : int) -> std/num/random/random list<(double, bool)> */ 

double kk_model_dash_resources__mlift3178_grandx(double c, double d, double w, double z, double _y_17, kk_context_t* _ctx); /* (c : double, d : double, w : double, z : double, double) -> effects-and-types/sample double */ 

double kk_model_dash_resources__mlift3179_grandx(double c0, double d0, double z0, kk_context_t* _ctx); /* (c : double, d : double, z : double) -> effects-and-types/sample double */ 

double kk_model_dash_resources_grandx(double d1, double c1, double v, kk_context_t* _ctx); /* (d : double, c : double, v : double) -> <div,effects-and-types/sample> double */ 

double kk_model_dash_resources__mlift3180_grand(double alpha, double x, double _y_23, kk_context_t* _ctx); /* (alpha : double, x : double, double) -> effects-and-types/sample double */ 

double kk_model_dash_resources__mlift3181_grand(double alpha0, double x0, kk_context_t* _ctx); /* (alpha : double, x : double) -> <effects-and-types/sample,div> double */ 

double kk_model_dash_resources__mlift3182_grand(double beta, double d, double v, kk_context_t* _ctx); /* (beta : double, d : double, v : double) -> <div,effects-and-types/sample> double */ 

double kk_model_dash_resources_grand(double alpha1, double beta0, kk_context_t* _ctx); /* (alpha : double, beta : double) -> <div,effects-and-types/sample> double */ 

kk_unit_t kk_model_dash_resources__mlift3183_logistic__regression(bool label, double p, kk_context_t* _ctx); /* (label : bool, p : double) -> <effects-and-types/sample,effects-and-types/score> () */ 

kk_std_core_types__tuple2_ kk_model_dash_resources__mlift3184_logistic__regression(double b, double m, kk_std_core__list wild__, kk_context_t* _ctx); /* (b : double, m : double, wild_ : list<()>) -> <effects-and-types/sample,effects-and-types/score,div> (double, double) */ 

kk_std_core_types__tuple2_ kk_model_dash_resources__mlift3185_logistic__regression(double b, kk_std_core__list dat, double m, double sigma, kk_context_t* _ctx); /* (b : double, dat : list<(double, bool)>, m : double, sigma : double) -> <div,effects-and-types/sample,effects-and-types/score> (double, double) */ 

kk_std_core_types__tuple2_ kk_model_dash_resources__mlift3186_logistic__regression(kk_std_core__list dat, double m, double b, kk_context_t* _ctx); /* (dat : list<(double, bool)>, m : double, b : double) -> <effects-and-types/sample,div,effects-and-types/score> (double, double) */ 

kk_std_core_types__tuple2_ kk_model_dash_resources__mlift3187_logistic__regression(kk_std_core__list dat, double m, kk_context_t* _ctx); /* (dat : list<(double, bool)>, m : double) -> <effects-and-types/sample,div,effects-and-types/score> (double, double) */ 

kk_function_t kk_model_dash_resources_logistic__regression(kk_std_core__list dat, kk_context_t* _ctx); /* (dat : list<(double, bool)>) -> effects-and-types/model<(double, double),div> */ 


// lift anonymous function
struct kk_model_dash_resources_params_fun4890__t {
  struct kk_function_s _base;
};
extern double kk_model_dash_resources_params_fun4890(kk_function_t _fself, kk_context_t* _ctx);
static inline kk_function_t kk_model_dash_resources_new_params_fun4890(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_model_dash_resources_params_fun4890, _ctx)
  return kk_function_dup(_fself);
}


static inline kk_function_t kk_model_dash_resources_params(kk_context_t* _ctx) { /* () -> (() -> <div,effects-and-types/sample> double) */ 
  return kk_model_dash_resources_new_params_fun4890(_ctx);
}

kk_std_core__list kk_model_dash_resources__mlift3188_op(kk_function_t obs, double s, double x, double x_sq_, kk_std_core__list xs, kk_std_core__list ys, kk_unit_t wild__, kk_context_t* _ctx); /* (obs : (x : double, y : double) -> <std/num/random/random,effects-and-types/score> (), s : double, x : double, x' : double, xs : list<double>, ys : list<double>, wild_ : ()) -> <std/num/random/random,effects-and-types/score,effects-and-types/sample> list<double> */ 

kk_std_core__list kk_model_dash_resources__mlift3189_op(kk_function_t obs0, double s0, double x0, kk_std_core__list xs0, double y, kk_std_core__list ys0, double x0_sq_, kk_context_t* _ctx); /* (obs : (x : double, y : double) -> <std/num/random/random,effects-and-types/score> (), s : double, x : double, xs : list<double>, y : double, ys : list<double>, x' : double) -> <effects-and-types/sample,std/num/random/random,effects-and-types/score> list<double> */ 

kk_std_core__list kk_model_dash_resources__lift3144_random__walk(kk_function_t obs1, double s1, kk_std_core__list xss, kk_std_core__list yss, kk_context_t* _ctx); /* (obs : (x : double, y : double) -> <std/num/random/random,effects-and-types/score> (), s : double, xss : list<double>, yss : list<double>) -> <std/num/random/random,effects-and-types/score,effects-and-types/sample> list<double> */ 

kk_unit_t kk_model_dash_resources__mlift3190_random__walk(double x, double y, size_t _y_42, kk_context_t* _ctx); /* (x : double, y : double, std/core/hnd/ev-index) -> <std/num/random/random,effects-and-types/score> () */ 

kk_std_core__list kk_model_dash_resources__mlift3191_random__walk(kk_std_core__list _x14939, kk_context_t* _ctx); /* (list<double>) -> <std/num/random/random,effects-and-types/score,effects-and-types/sample> list<double> */ 

kk_function_t kk_model_dash_resources_random__walk(kk_std_core__list zs, kk_context_t* _ctx); /* (zs : list<double>) -> ((s : double) -> effects-and-types/nmodel<list<double>>) */ 

double kk_model_dash_resources__mlift3192_sequential__gaussian(kk_ref_t x, size_t _y_52, kk_context_t* _ctx); /* forall<h> (x : local-var<h,double>, std/core/hnd/ev-index) -> <std/num/random/random,local<h>,effects-and-types/sample,effects-and-types/score> double */ 

kk_unit_t kk_model_dash_resources__mlift3193_sequential__gaussian(double data__point, double _y_49, kk_context_t* _ctx); /* forall<h> (data_point : double, double) -> <local<h>,effects-and-types/score,effects-and-types/sample,std/num/random/random> () */ 

kk_unit_t kk_model_dash_resources__mlift3194_sequential__gaussian(double data__point, kk_ref_t x, kk_unit_t wild__, kk_context_t* _ctx); /* forall<h> (data_point : double, x : local-var<h,double>, wild_ : ()) -> <local<h>,effects-and-types/sample,effects-and-types/score,std/num/random/random> () */ 

kk_unit_t kk_model_dash_resources__mlift3195_sequential__gaussian(double data__point, kk_ref_t x, double _y_47, kk_context_t* _ctx); /* forall<h> (data_point : double, x : local-var<h,double>, double) -> <effects-and-types/sample,local<h>,effects-and-types/score,std/num/random/random> () */ 

kk_unit_t kk_model_dash_resources__mlift3196_sequential__gaussian(double data__point, kk_ref_t x, double _y_46, kk_context_t* _ctx); /* forall<h> (data_point : double, x : local-var<h,double>, double) -> <local<h>,effects-and-types/sample,effects-and-types/score,std/num/random/random> () */ 

double kk_model_dash_resources__mlift3197_sequential__gaussian(kk_ref_t x, kk_unit_t wild__0, kk_context_t* _ctx); /* forall<h> (x : local-var<h,double>, wild_0 : ()) -> <local<h>,effects-and-types/sample,effects-and-types/score,std/num/random/random> double */ 

kk_function_t kk_model_dash_resources_sequential__gaussian(double data__point, kk_context_t* _ctx); /* (data_point : double) -> effects-and-types/nmodel<double> */ 

void kk_model_dash_resources__init(kk_context_t* _ctx);

#endif // header
