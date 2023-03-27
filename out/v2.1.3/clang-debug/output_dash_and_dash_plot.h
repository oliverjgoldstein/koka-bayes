#pragma once
#ifndef kk_output_dash_and_dash_plot_H
#define kk_output_dash_and_dash_plot_H
// Koka generated module: "output-and-plot", koka version: 2.1.3
#include <kklib.h>
#include "std_core_types.h"
#include "std_core_hnd.h"
#include "std_core.h"
#include "effects_dash_and_dash_types.h"
#include "std_num_ddouble.h"
#include "std_os_path.h"
#include "std_os_file.h"

// type declarations

// value declarations

kk_string_t kk_output_dash_and_dash_plot__mlift5053_list_join(kk_std_core__list xs, kk_context_t* _ctx); /* forall<e> (xs : list<string>) -> e string */ 

kk_string_t kk_output_dash_and_dash_plot_list_join(kk_integer_t len, kk_function_t elem, kk_context_t* _ctx); /* forall<e> (len : int, elem : (int) -> e string) -> e string */ 

kk_string_t kk_output_dash_and_dash_plot_list__to__csv(kk_std_core__list xs, kk_context_t* _ctx); /* (xs : list<double>) -> string */ 

kk_string_t kk_output_dash_and_dash_plot_show__head(kk_std_core__list tmcmc__result, kk_context_t* _ctx); /* (tmcmc_result : list<(list<double>, double)>) -> string */ 

kk_string_t kk_output_dash_and_dash_plot_show__trace__single(kk_std_core__list tmcmc__result, kk_context_t* _ctx); /* (tmcmc_result : list<(list<double>, double)>) -> string */ 

kk_string_t kk_output_dash_and_dash_plot_show(kk_std_core__list hist, kk_context_t* _ctx); /* (hist : effects-and-types/histogram<double>) -> string */ 

kk_string_t kk_output_dash_and_dash_plot_show_1(kk_std_core__list hist, kk_context_t* _ctx); /* (hist : effects-and-types/histogram<(double, double)>) -> string */ 

kk_string_t kk_output_dash_and_dash_plot_show_2(kk_std_core__list hist, kk_context_t* _ctx); /* (hist : effects-and-types/histogram<list<double>>) -> string */ 

kk_string_t kk_output_dash_and_dash_plot_show_3(kk_std_core_types__tuple2_ ls, kk_context_t* _ctx); /* (ls : (list<int>, list<int>)) -> string */ 

kk_string_t kk_output_dash_and_dash_plot_show_4(kk_std_core__list xs, kk_context_t* _ctx); /* (xs : list<double>) -> string */ 

kk_string_t kk_output_dash_and_dash_plot_show_5(kk_std_core__list x, kk_context_t* _ctx); /* (x : list<list<double>>) -> string */ 

kk_string_t kk_output_dash_and_dash_plot_show_6(kk_std_core__list x, kk_context_t* _ctx); /* (x : list<list<list<double>>>) -> string */ 

kk_integer_t kk_output_dash_and_dash_plot_show_7(kk_std_core__list hist, kk_context_t* _ctx); /* (hist : effects-and-types/histogram<(double) -> double>) -> console int */ 

kk_string_t kk_output_dash_and_dash_plot_plot(kk_function_t f, kk_context_t* _ctx); /* (f : (double) -> double) -> string */ 


// lift anonymous function
struct kk_output_dash_and_dash_plot_example_plot_fun5770__t {
  struct kk_function_s _base;
};
extern double kk_output_dash_and_dash_plot_example_plot_fun5770(kk_function_t _fself, double x, kk_context_t* _ctx);
static inline kk_function_t kk_output_dash_and_dash_plot_new_example_plot_fun5770(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_output_dash_and_dash_plot_example_plot_fun5770, _ctx)
  return kk_function_dup(_fself);
}


static inline kk_string_t kk_output_dash_and_dash_plot_example_plot(kk_context_t* _ctx) { /* () -> string */ 
  return kk_output_dash_and_dash_plot_plot(kk_output_dash_and_dash_plot_new_example_plot_fun5770(_ctx), _ctx);
}

kk_string_t kk_output_dash_and_dash_plot_show__trace(kk_std_core__list tmcmc__result, kk_context_t* _ctx); /* (tmcmc_result : list<(list<double>, list<double>)>) -> string */ 

kk_unit_t kk_output_dash_and_dash_plot_write(kk_std_core__list trace, kk_string_t filename, kk_context_t* _ctx); /* (trace : list<(list<double>, double)>, filename : string) -> <exn,fsys> () */ 

kk_unit_t kk_output_dash_and_dash_plot_write_1(kk_std_core__list trace, kk_string_t filename, kk_context_t* _ctx); /* (trace : list<(list<double>, list<double>)>, filename : string) -> <exn,fsys> () */ 

kk_unit_t kk_output_dash_and_dash_plot_write_2(kk_std_core__list hist, kk_string_t filename, kk_context_t* _ctx); /* (hist : effects-and-types/histogram<double>, filename : string) -> <exn,fsys> () */ 

kk_unit_t kk_output_dash_and_dash_plot_write_3(kk_std_core__list hist, kk_string_t filename, kk_context_t* _ctx); /* (hist : effects-and-types/histogram<(double, double)>, filename : string) -> <exn,fsys> () */ 

kk_unit_t kk_output_dash_and_dash_plot_write_4(kk_std_core__list hist, kk_string_t filename, kk_context_t* _ctx); /* (hist : effects-and-types/histogram<list<double>>, filename : string) -> <exn,fsys> () */ 

void kk_output_dash_and_dash_plot__init(kk_context_t* _ctx);

#endif // header
