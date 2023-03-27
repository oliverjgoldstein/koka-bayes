#pragma once
#ifndef kk_climate_dash_experiments_H
#define kk_climate_dash_experiments_H
// Koka generated module: "climate-experiments", koka version: 2.1.3
#include <kklib.h>
#include "std_core_types.h"
#include "std_core_hnd.h"
#include "std_core.h"
#include "std_num_random.h"
#include "std_time_timer.h"
#include "effects_dash_and_dash_types.h"
#include "std_os_path.h"
#include "std_os_file.h"
#include "output_dash_and_dash_plot.h"
#include "handlers.h"
#include "sampling.h"
#include "smc.h"
#include "model_dash_resources.h"
#include "tmcmc.h"
#include "climate_dash_change.h"
#include "data_preprocessing.h"

// type declarations

// value declarations

kk_unit_t kk_climate_dash_experiments__mlift5628_run__climate__model(kk_string_t name1, kk_integer_t repeat__ind, kk_std_core__list _y_21, kk_context_t* _ctx); /* (name1 : string, repeat_ind : int, effects-and-types/histogram<list<double>>) -> <pure,std/num/random/random,fsys,console,ndet> () */ 

kk_unit_t kk_climate_dash_experiments__mlift5629_run__climate__model(kk_std_core_types__tuple2_ data, double diff1, kk_integer_t ind1, kk_string_t name1, kk_integer_t pt, kk_integer_t repeat__ind, kk_integer_t rs, kk_integer_t sbrs, double subtract1, kk_std_core__list _y_20, kk_context_t* _ctx); /* (data : (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>), diff1 : double, ind1 : int, name1 : string, pt : int, repeat_ind : int, rs : int, sbrs : int, subtract1 : double, list<effects-and-types/row_vector>) -> <exn,div,std/num/random/random,fsys,console,ndet> () */ 

kk_unit_t kk_climate_dash_experiments__mlift5630_run__climate__model(kk_std_core_types__tuple2_ data, double diff1, kk_integer_t ind1, kk_string_t name1, kk_integer_t pt, kk_integer_t repeat__ind, kk_integer_t rs, kk_integer_t sbrs, double subtract1, kk_std_core__list _y_19, kk_context_t* _ctx); /* (data : (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>), diff1 : double, ind1 : int, name1 : string, pt : int, repeat_ind : int, rs : int, sbrs : int, subtract1 : double, list<effects-and-types/row_vector>) -> <exn,div,std/num/random/random,fsys,console,ndet> () */ 

kk_unit_t kk_climate_dash_experiments__mlift5631_run__climate__model(kk_std_core__list wild__5, kk_context_t* _ctx); /* (wild_5 : list<()>) -> <console,div,exn,fsys,ndet,std/num/random/random> () */ 

kk_unit_t kk_climate_dash_experiments__mlift5632_run__climate__model(kk_string_t name0, kk_std_core_types__tuple2_ _y_12, kk_context_t* _ctx); /* (name0 : string, (list<(list<double>, list<double>)>, tmcmc/trace<list<double>,<effects-and-types/sample,effects-and-types/score,div,exn,fsys,console,ndet,std/num/random/random>>)) -> <effects-and-types/sample,div,exn,fsys,console,ndet,std/num/random/random> () */ 

kk_unit_t kk_climate_dash_experiments__mlift5633_run__climate__model(kk_integer_t burnin, kk_std_core_types__tuple2_ data, double diff0, kk_integer_t ind0, kk_string_t name0, double subtract0, kk_integer_t t__steps, kk_std_core__list _y_11, kk_context_t* _ctx); /* (burnin : int, data : (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>), diff0 : double, ind0 : int, name0 : string, subtract0 : double, t_steps : int, list<effects-and-types/row_vector>) -> <exn,div,effects-and-types/sample,fsys,console,ndet,std/num/random/random> () */ 

kk_unit_t kk_climate_dash_experiments__mlift5634_run__climate__model(kk_integer_t burnin, kk_std_core_types__tuple2_ data, double diff0, kk_integer_t ind0, kk_string_t name0, double subtract0, kk_integer_t t__steps, kk_std_core__list _y_10, kk_context_t* _ctx); /* (burnin : int, data : (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>), diff0 : double, ind0 : int, name0 : string, subtract0 : double, t_steps : int, list<effects-and-types/row_vector>) -> <exn,div,effects-and-types/sample,fsys,console,ndet,std/num/random/random> () */ 

kk_unit_t kk_climate_dash_experiments__mlift5635_run__climate__model(kk_std_core_types__tuple2_ data, kk_std_core__list pre__data, kk_integer_t pt, kk_std_core_types__optional repeat__num, kk_integer_t rs, kk_integer_t sbrs, kk_std_core__list wild__3, kk_context_t* _ctx); /* (data : (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>), pre_data : list<(double, double, string)>, pt : int, repeat_num : optional<int>, rs : int, sbrs : int, wild_3 : list<()>) -> <ndet,console,div,exn,fsys,std/num/random/random> () */ 

kk_unit_t kk_climate_dash_experiments__mlift5636_run__climate__model(kk_string_t name, kk_std_core_types__tuple2_ _y_3, kk_context_t* _ctx); /* (name : string, (list<(list<double>, list<double>)>, tmcmc/trace<list<double>,<effects-and-types/sample,effects-and-types/score,div,exn,fsys,console,ndet,std/num/random/random>>)) -> <effects-and-types/sample,div,exn,fsys,console,ndet,std/num/random/random> () */ 

kk_unit_t kk_climate_dash_experiments__mlift5637_run__climate__model(kk_integer_t burnin, kk_std_core_types__tuple2_ data, double diff, kk_integer_t ind, kk_string_t name, double subtract, kk_integer_t t__steps, kk_std_core__list _y_2, kk_context_t* _ctx); /* (burnin : int, data : (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>), diff : double, ind : int, name : string, subtract : double, t_steps : int, list<effects-and-types/row_vector>) -> <exn,div,effects-and-types/sample,fsys,console,ndet,std/num/random/random> () */ 

kk_unit_t kk_climate_dash_experiments__mlift5638_run__climate__model(kk_integer_t burnin, kk_std_core_types__tuple2_ data, double diff, kk_integer_t ind, kk_string_t name, double subtract, kk_integer_t t__steps, kk_std_core__list _y_1, kk_context_t* _ctx); /* (burnin : int, data : (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>), diff : double, ind : int, name : string, subtract : double, t_steps : int, list<effects-and-types/row_vector>) -> <exn,div,effects-and-types/sample,fsys,console,ndet,std/num/random/random> () */ 

kk_unit_t kk_climate_dash_experiments__mlift5639_run__climate__model(kk_integer_t burnin, kk_std_core_types__tuple2_ data, kk_std_core__list pre__data, kk_integer_t pt, kk_std_core_types__optional repeat__num, kk_integer_t rs, kk_integer_t sbrs, kk_integer_t t__steps, kk_std_core__list wild__1, kk_context_t* _ctx); /* (burnin : int, data : (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>), pre_data : list<(double, double, string)>, pt : int, repeat_num : optional<int>, rs : int, sbrs : int, t_steps : int, wild_1 : list<()>) -> <ndet,console,div,exn,fsys,std/num/random/random> () */ 

kk_unit_t kk_climate_dash_experiments__mlift5640_run__climate__model(kk_integer_t burnin, kk_integer_t pt, kk_std_core_types__optional repeat__num, kk_integer_t rs, kk_integer_t sbrs, kk_integer_t t__steps, kk_std_core_types__tuple2_ data, kk_context_t* _ctx); /* (burnin : int, pt : int, repeat_num : optional<int>, rs : int, sbrs : int, t_steps : int, data : (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>)) -> <div,exn,fsys,console,ndet,std/num/random/random> () */ 

kk_unit_t kk_climate_dash_experiments_run__climate__model(kk_integer_t pt, kk_integer_t rs, kk_integer_t sbrs, kk_integer_t t__steps, kk_integer_t burnin, kk_std_core_types__optional repeat__num, kk_context_t* _ctx); /* (pt : int, rs : int, sbrs : int, t_steps : int, burnin : int, repeat_num : optional<int>) -> <pure,console,fsys,ndet,std/num/random/random> () */ 

kk_unit_t kk_climate_dash_experiments__mlift5641_run__experiments(kk_integer_t i1, kk_std_core__list wild__10, kk_context_t* _ctx); /* (i1 : int, wild_10 : list<(list<(list<double>, (double, double))>, tmcmc/trace<(double, double),<effects-and-types/sample,effects-and-types/score,div,console,ndet,exn,std/num/random/random>>)>) -> <console,div,ndet,effects-and-types/sample,exn,std/num/random/random> () */ 

kk_unit_t kk_climate_dash_experiments__mlift5642_run__experiments(kk_std_core__list data__50, kk_std_core__list data__points, kk_integer_t i1, kk_std_core__list wild__7, kk_context_t* _ctx); /* (data_50 : list<(double, bool)>, data_points : list<(int, list<(double, bool)>)>, i1 : int, wild_7 : list<(list<(list<double>, (double, double))>, tmcmc/trace<(double, double),<effects-and-types/sample,effects-and-types/score,div,console,ndet,exn,std/num/random/random>>)>) -> <console,div,ndet,effects-and-types/sample,exn,std/num/random/random> () */ 

kk_unit_t kk_climate_dash_experiments__mlift5643_run__experiments(kk_std_core__list data__50, kk_std_core__list data__points, kk_integer_t i1, kk_std_core__list wild__4, kk_context_t* _ctx); /* (data_50 : list<(double, bool)>, data_points : list<(int, list<(double, bool)>)>, i1 : int, wild_4 : list<effects-and-types/histogram<(double, double)>>) -> <console,div,exn,ndet,std/num/random/random,effects-and-types/sample> () */ 

kk_unit_t kk_climate_dash_experiments__mlift5644_run__experiments(kk_std_core__list data__50, kk_std_core__list data__points, kk_integer_t i1, kk_std_core__list wild__1, kk_context_t* _ctx); /* (data_50 : list<(double, bool)>, data_points : list<(int, list<(double, bool)>)>, i1 : int, wild_1 : list<effects-and-types/histogram<(double, double)>>) -> <console,div,exn,ndet,std/num/random/random,effects-and-types/sample> () */ 

kk_unit_t kk_climate_dash_experiments__mlift5645_run__experiments(kk_std_core__list data__points, kk_std_core_types__optional number__of__repeats, kk_std_core__list data__50, kk_context_t* _ctx); /* (data_points : list<(int, list<(double, bool)>)>, number_of_repeats : optional<int>, data_50 : list<(double, bool)>) -> <std/num/random/random,console,div,exn,ndet,effects-and-types/sample> () */ 

kk_std_core_types__tuple2_ kk_climate_dash_experiments__mlift5646_run__experiments(kk_integer_t i0, kk_std_core__list _y_29, kk_context_t* _ctx); /* (i0 : int, list<(double, bool)>) -> <std/num/random/random,console,div,exn,ndet,effects-and-types/sample> (int, list<(double, bool)>) */ 

kk_unit_t kk_climate_dash_experiments__mlift5647_run__experiments(kk_std_core_types__optional number__of__repeats, kk_std_core__list data__points, kk_context_t* _ctx); /* (number_of_repeats : optional<int>, data_points : list<(int, list<(double, bool)>)>) -> <std/num/random/random,console,div,exn,ndet,effects-and-types/sample> () */ 

kk_unit_t kk_climate_dash_experiments__mlift5648_run__experiments(kk_std_core_types__optional number__of__repeats, kk_std_core__list _y_28, kk_context_t* _ctx); /* (number_of_repeats : optional<int>, list<int>) -> <std/num/random/random,console,div,exn,ndet,effects-and-types/sample> () */ 

kk_unit_t kk_climate_dash_experiments_run__experiments(kk_std_core_types__optional number__of__repeats, kk_std_core_types__optional max__number__of__data__points, kk_context_t* _ctx); /* (number_of_repeats : optional<int>, max_number_of_data_points : optional<int>) -> <pure,console,ndet,std/num/random/random,effects-and-types/sample> () */ 

kk_unit_t kk_climate_dash_experiments__mlift5649_main(kk_unit_t wild__3, kk_context_t* _ctx); /* (wild_3 : ()) -> <pure,console,fsys,ndet,std/num/random/random> () */ 

kk_unit_t kk_climate_dash_experiments__mlift5650_main(kk_unit_t wild__0, kk_context_t* _ctx); /* (wild_0 : ()) -> <std/num/random/random,console,div,exn,fsys,ndet> () */ 

kk_unit_t kk_climate_dash_experiments_main(kk_context_t* _ctx); /* () -> <pure,console,fsys,ndet,std/num/random/random> () */ 

void kk_climate_dash_experiments__init(kk_context_t* _ctx);

#endif // header
