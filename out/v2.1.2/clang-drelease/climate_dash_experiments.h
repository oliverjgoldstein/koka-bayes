#pragma once
#ifndef kk_climate_dash_experiments_H
#define kk_climate_dash_experiments_H
// Koka generated module: "climate-experiments", koka version: 2.1.2
#include <kklib.h>
#include "std_core_types.h"
#include "std_core_hnd.h"
#include "std_core.h"
#include "std_text_parse.h"
#include "std_num_int32.h"
#include "std_num_double.h"
#include "std_num_decimal.h"
#include "std_num_ddouble.h"
#include "std_num_random.h"
#include "std_time_date.h"
#include "std_time_timestamp.h"
#include "std_time_duration.h"
#include "std_time_instant.h"
#include "std_time_timer.h"
#include "std_os_path.h"
#include "std_os_dir.h"
#include "std_os_file.h"
#include "effects_dash_and_dash_types.h"
#include "exponents.h"
#include "output_dash_and_dash_plot.h"
#include "handlers.h"
#include "sampling.h"
#include "sequential.h"
#include "exn_dash_get.h"
#include "model_dash_resources.h"
#include "trace.h"
#include "pmmh.h"
#include "climate_dash_change.h"
#include "data_preprocessing.h"

// type declarations

// value declarations

kk_unit_t kk_climate_dash_experiments__mlift2581_run__climate__model(kk_string_t name, kk_integer_t repeat__ind, kk_std_core__list _y_3, kk_context_t* _ctx); /* (name : string, repeat_ind : int, effects-and-types/histogram<list<double>>) -> <pure,std/num/random/random,fsys,console,ndet> () */ 

kk_unit_t kk_climate_dash_experiments__mlift2582_run__climate__model(kk_std_core_types__tuple2_ data, double diff, kk_integer_t ind, kk_string_t name, kk_integer_t pt, kk_integer_t repeat__ind, kk_integer_t rs, kk_integer_t sbrs, double subtract, kk_std_core__list _y_2, kk_context_t* _ctx); /* (data : (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>), diff : double, ind : int, name : string, pt : int, repeat_ind : int, rs : int, sbrs : int, subtract : double, list<effects-and-types/row_vector>) -> <exn,div,std/num/random/random,fsys,console,ndet> () */ 

kk_unit_t kk_climate_dash_experiments__mlift2583_run__climate__model(kk_std_core_types__tuple2_ data, double diff, kk_integer_t ind, kk_string_t name, kk_integer_t pt, kk_integer_t repeat__ind, kk_integer_t rs, kk_integer_t sbrs, double subtract, kk_std_core__list _y_1, kk_context_t* _ctx); /* (data : (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>), diff : double, ind : int, name : string, pt : int, repeat_ind : int, rs : int, sbrs : int, subtract : double, list<effects-and-types/row_vector>) -> <exn,div,std/num/random/random,fsys,console,ndet> () */ 

kk_unit_t kk_climate_dash_experiments__mlift2584_run__climate__model(kk_std_core__list wild__0, kk_context_t* _ctx); /* (wild_0 : list<()>) -> <console,div,exn,fsys,ndet,std/num/random/random> () */ 

kk_unit_t kk_climate_dash_experiments__mlift2585_run__climate__model(kk_integer_t pt, kk_std_core_types__optional repeat__num, kk_integer_t rs, kk_integer_t sbrs, kk_std_core_types__tuple2_ data, kk_context_t* _ctx); /* (pt : int, repeat_num : optional<int>, rs : int, sbrs : int, data : (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>)) -> <div,exn,fsys,console,ndet,std/num/random/random> () */ 

kk_unit_t kk_climate_dash_experiments_run__climate__model(kk_integer_t pt, kk_integer_t rs, kk_integer_t sbrs, kk_integer_t t__steps, kk_integer_t burnin, kk_std_core_types__optional repeat__num, kk_context_t* _ctx); /* (pt : int, rs : int, sbrs : int, t_steps : int, burnin : int, repeat_num : optional<int>) -> <pure,console,fsys,ndet,std/num/random/random> () */ 

kk_unit_t kk_climate_dash_experiments__mlift2586_run__experiments(kk_std_core__list wild__7, kk_context_t* _ctx); /* (wild_7 : list<(list<(list<double>, (double, double))>, trace/trace<(double, double),<effects-and-types/sample,effects-and-types/score,div,console,ndet,exn,std/num/random/random>>)>) -> <ndet,console,div,effects-and-types/sample,exn,std/num/random/random> () */ 

kk_unit_t kk_climate_dash_experiments__mlift2587_run__experiments(kk_std_core__list data__50, kk_std_core__list data__points, kk_std_core__list wild__5, kk_context_t* _ctx); /* (data_50 : list<(double, bool)>, data_points : list<(int, list<(double, bool)>)>, wild_5 : list<(list<(list<double>, (double, double))>, trace/trace<(double, double),<effects-and-types/sample,effects-and-types/score,div,console,ndet,exn,std/num/random/random>>)>) -> <ndet,console,div,effects-and-types/sample,exn,std/num/random/random> () */ 

kk_std_core__list kk_climate_dash_experiments__mlift2588_run__experiments(kk_std_core__list data__50, kk_std_core__list data__points, kk_std_core__list wild__0, kk_context_t* _ctx); /* (data_50 : list<(double, bool)>, data_points : list<(int, list<(double, bool)>)>, wild_0 : list<effects-and-types/histogram<(double, double)>>) -> <console,div,exn,ndet,std/num/random/random,effects-and-types/sample> list<effects-and-types/histogram<(double, double)>> */ 

kk_unit_t kk_climate_dash_experiments__mlift2589_run__experiments(kk_std_core__list data__50, kk_std_core__list data__points, kk_std_core__list wild__2, kk_context_t* _ctx); /* (data_50 : list<(double, bool)>, data_points : list<(int, list<(double, bool)>)>, wild_2 : list<effects-and-types/histogram<(double, double)>>) -> <ndet,console,div,exn,std/num/random/random,effects-and-types/sample> () */ 

kk_unit_t kk_climate_dash_experiments__mlift2590_run__experiments(kk_std_core__list data__points, kk_std_core_types__optional number__of__repeats, kk_std_core__list data__50, kk_context_t* _ctx); /* (data_points : list<(int, list<(double, bool)>)>, number_of_repeats : optional<int>, data_50 : list<(double, bool)>) -> <std/num/random/random,console,div,exn,ndet,effects-and-types/sample> () */ 

kk_std_core_types__tuple2_ kk_climate_dash_experiments__mlift2591_run__experiments(kk_integer_t i0, kk_std_core__list _y_11, kk_context_t* _ctx); /* (i0 : int, list<(double, bool)>) -> <std/num/random/random,console,div,exn,ndet,effects-and-types/sample> (int, list<(double, bool)>) */ 

kk_unit_t kk_climate_dash_experiments__mlift2592_run__experiments(kk_std_core_types__optional number__of__repeats, kk_std_core__list data__points, kk_context_t* _ctx); /* (number_of_repeats : optional<int>, data_points : list<(int, list<(double, bool)>)>) -> <std/num/random/random,console,div,exn,ndet,effects-and-types/sample> () */ 

kk_unit_t kk_climate_dash_experiments__mlift2593_run__experiments(kk_std_core_types__optional number__of__repeats, kk_std_core__list _y_10, kk_context_t* _ctx); /* (number_of_repeats : optional<int>, list<int>) -> <std/num/random/random,console,div,exn,ndet,effects-and-types/sample> () */ 

kk_unit_t kk_climate_dash_experiments_run__experiments(kk_std_core_types__optional number__of__repeats, kk_std_core_types__optional max__number__of__data__points, kk_context_t* _ctx); /* (number_of_repeats : optional<int>, max_number_of_data_points : optional<int>) -> <pure,console,ndet,std/num/random/random,effects-and-types/sample> () */ 

kk_unit_t kk_climate_dash_experiments__mlift2594_main(kk_unit_t wild__3, kk_context_t* _ctx); /* (wild_3 : ()) -> <pure,console,fsys,ndet,std/num/random/random> () */ 

kk_unit_t kk_climate_dash_experiments__mlift2595_main(kk_unit_t wild__0, kk_context_t* _ctx); /* (wild_0 : ()) -> <std/num/random/random,console,div,exn,fsys,ndet> () */ 

kk_unit_t kk_climate_dash_experiments_main(kk_context_t* _ctx); /* () -> <pure,console,fsys,ndet,std/num/random/random> () */ 

kk_unit_t kk_climate_dash_experiments__hmain(kk_context_t* _ctx); /* () -> <console,div,fsys,ndet> () */ 

void kk_climate_dash_experiments__init(kk_context_t* _ctx);

#endif // header
