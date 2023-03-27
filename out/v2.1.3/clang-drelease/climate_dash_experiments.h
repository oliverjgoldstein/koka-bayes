#pragma once
#ifndef kk_climate_dash_experiments_H
#define kk_climate_dash_experiments_H
// Koka generated module: "climate-experiments", koka version: 2.1.3
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
#include "std_time_timer.h"
#include "std_os_path.h"
#include "std_os_dir.h"
#include "std_os_file.h"
#include "effects_dash_and_dash_types.h"
#include "output_dash_and_dash_plot.h"
#include "exponents.h"
#include "handlers.h"
#include "sampling.h"
#include "smc.h"
#include "model_dash_resources.h"
#include "tmcmc.h"
#include "pmmh.h"
#include "exn_dash_get.h"
#include "climate_dash_change.h"
#include "data_preprocessing.h"

// type declarations

// value declarations

kk_unit_t kk_climate_dash_experiments__mlift4683_run__climate__model(kk_string_t name0, kk_std_core_types__tuple2_ _y_12, kk_context_t* _ctx); /* (name0 : string, (list<(list<double>, list<double>)>, tmcmc/trace<list<double>,<effects-and-types/sample,effects-and-types/score,div,exn,fsys,console,ndet,std/num/random/random>>)) -> <effects-and-types/sample,div,exn,fsys,console,ndet,std/num/random/random> () */ 

kk_unit_t kk_climate_dash_experiments__mlift4684_run__climate__model(kk_integer_t burnin, kk_std_core_types__tuple2_ data, double diff0, kk_integer_t ind0, kk_string_t name0, double subtract0, kk_integer_t t__steps, kk_std_core__list _y_11, kk_context_t* _ctx); /* (burnin : int, data : (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>), diff0 : double, ind0 : int, name0 : string, subtract0 : double, t_steps : int, list<effects-and-types/row_vector>) -> <exn,div,effects-and-types/sample,fsys,console,ndet,std/num/random/random> () */ 

kk_unit_t kk_climate_dash_experiments__mlift4685_run__climate__model(kk_integer_t burnin, kk_std_core_types__tuple2_ data, double diff0, kk_integer_t ind0, kk_string_t name0, double subtract0, kk_integer_t t__steps, kk_std_core__list _y_10, kk_context_t* _ctx); /* (burnin : int, data : (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>), diff0 : double, ind0 : int, name0 : string, subtract0 : double, t_steps : int, list<effects-and-types/row_vector>) -> <exn,div,effects-and-types/sample,fsys,console,ndet,std/num/random/random> () */ 

kk_unit_t kk_climate_dash_experiments__mlift4686_run__climate__model(kk_string_t name, kk_std_core_types__tuple2_ _y_3, kk_context_t* _ctx); /* (name : string, (list<(list<double>, list<double>)>, tmcmc/trace<list<double>,<effects-and-types/sample,effects-and-types/score,div,exn,fsys,console,ndet,std/num/random/random>>)) -> <effects-and-types/sample,div,exn,fsys,console,ndet,std/num/random/random> () */ 

kk_unit_t kk_climate_dash_experiments__mlift4687_run__climate__model(kk_integer_t burnin, kk_std_core_types__tuple2_ data, double diff, kk_integer_t ind, kk_string_t name, double subtract, kk_integer_t t__steps, kk_std_core__list _y_2, kk_context_t* _ctx); /* (burnin : int, data : (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>), diff : double, ind : int, name : string, subtract : double, t_steps : int, list<effects-and-types/row_vector>) -> <exn,div,effects-and-types/sample,fsys,console,ndet,std/num/random/random> () */ 

kk_unit_t kk_climate_dash_experiments__mlift4688_run__climate__model(kk_integer_t burnin, kk_std_core_types__tuple2_ data, double diff, kk_integer_t ind, kk_string_t name, double subtract, kk_integer_t t__steps, kk_std_core__list _y_1, kk_context_t* _ctx); /* (burnin : int, data : (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>), diff : double, ind : int, name : string, subtract : double, t_steps : int, list<effects-and-types/row_vector>) -> <exn,div,effects-and-types/sample,fsys,console,ndet,std/num/random/random> () */ 

kk_std_core__list kk_climate_dash_experiments__mlift4689_run__climate__model(kk_integer_t burnin, kk_std_core_types__tuple2_ data, kk_std_core__list pre__data, kk_integer_t t__steps, kk_std_core__list wild__1, kk_context_t* _ctx); /* (burnin : int, data : (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>), pre_data : list<(double, double, string)>, t_steps : int, wild_1 : list<()>) -> <ndet,console,div,exn,fsys,std/num/random/random> list<()> */ 

kk_std_core__list kk_climate_dash_experiments__mlift4690_run__climate__model(kk_integer_t burnin, kk_integer_t t__steps, kk_std_core_types__tuple2_ data, kk_context_t* _ctx); /* (burnin : int, t_steps : int, data : (list<list<effects-and-types/row_vector>>, list<list<effects-and-types/row_vector>>)) -> <div,exn,fsys,console,ndet,std/num/random/random> list<()> */ 

kk_std_core__list kk_climate_dash_experiments_run__climate__model(kk_integer_t pt, kk_integer_t rs, kk_integer_t sbrs, kk_integer_t t__steps, kk_integer_t burnin, kk_std_core_types__optional repeat__num, kk_context_t* _ctx); /* (pt : int, rs : int, sbrs : int, t_steps : int, burnin : int, repeat_num : optional<int>) -> <pure,console,fsys,ndet,std/num/random/random> list<()> */ 

kk_unit_t kk_climate_dash_experiments__mlift4691_run__experiments(kk_integer_t i1, kk_std_core__list wild__10, kk_context_t* _ctx); /* (i1 : int, wild_10 : list<(list<(list<double>, (double, double))>, tmcmc/trace<(double, double),<effects-and-types/sample,effects-and-types/score,div,console,ndet,exn,std/num/random/random>>)>) -> <console,div,ndet,effects-and-types/sample,exn,std/num/random/random> () */ 

kk_unit_t kk_climate_dash_experiments__mlift4692_run__experiments(kk_std_core__list data__50, kk_std_core__list data__points, kk_integer_t i1, kk_std_core__list wild__7, kk_context_t* _ctx); /* (data_50 : list<(double, bool)>, data_points : list<(int, list<(double, bool)>)>, i1 : int, wild_7 : list<(list<(list<double>, (double, double))>, tmcmc/trace<(double, double),<effects-and-types/sample,effects-and-types/score,div,console,ndet,exn,std/num/random/random>>)>) -> <console,div,ndet,effects-and-types/sample,exn,std/num/random/random> () */ 

kk_unit_t kk_climate_dash_experiments__mlift4693_run__experiments(kk_std_core__list data__50, kk_std_core__list data__points, kk_integer_t i1, kk_std_core__list wild__4, kk_context_t* _ctx); /* (data_50 : list<(double, bool)>, data_points : list<(int, list<(double, bool)>)>, i1 : int, wild_4 : list<effects-and-types/histogram<(double, double)>>) -> <console,div,exn,ndet,std/num/random/random,effects-and-types/sample> () */ 

kk_unit_t kk_climate_dash_experiments__mlift4694_run__experiments(kk_std_core__list data__50, kk_std_core__list data__points, kk_integer_t i1, kk_std_core__list wild__1, kk_context_t* _ctx); /* (data_50 : list<(double, bool)>, data_points : list<(int, list<(double, bool)>)>, i1 : int, wild_1 : list<effects-and-types/histogram<(double, double)>>) -> <console,div,exn,ndet,std/num/random/random,effects-and-types/sample> () */ 

kk_unit_t kk_climate_dash_experiments__mlift4695_run__experiments(kk_std_core__list data__points, kk_std_core_types__optional number__of__repeats, kk_std_core__list data__50, kk_context_t* _ctx); /* (data_points : list<(int, list<(double, bool)>)>, number_of_repeats : optional<int>, data_50 : list<(double, bool)>) -> <std/num/random/random,console,div,exn,ndet,effects-and-types/sample> () */ 

kk_std_core_types__tuple2_ kk_climate_dash_experiments__mlift4696_run__experiments(kk_integer_t i0, kk_std_core__list _y_20, kk_context_t* _ctx); /* (i0 : int, list<(double, bool)>) -> <std/num/random/random,console,div,exn,ndet,effects-and-types/sample> (int, list<(double, bool)>) */ 

kk_unit_t kk_climate_dash_experiments__mlift4697_run__experiments(kk_std_core_types__optional number__of__repeats, kk_std_core__list data__points, kk_context_t* _ctx); /* (number_of_repeats : optional<int>, data_points : list<(int, list<(double, bool)>)>) -> <std/num/random/random,console,div,exn,ndet,effects-and-types/sample> () */ 

kk_unit_t kk_climate_dash_experiments__mlift4698_run__experiments(kk_std_core_types__optional number__of__repeats, kk_std_core__list _y_19, kk_context_t* _ctx); /* (number_of_repeats : optional<int>, list<int>) -> <std/num/random/random,console,div,exn,ndet,effects-and-types/sample> () */ 

kk_unit_t kk_climate_dash_experiments_run__experiments(kk_std_core_types__optional number__of__repeats, kk_std_core_types__optional max__number__of__data__points, kk_context_t* _ctx); /* (number_of_repeats : optional<int>, max_number_of_data_points : optional<int>) -> <pure,console,ndet,std/num/random/random,effects-and-types/sample> () */ 

kk_unit_t kk_climate_dash_experiments__mlift4699_main(kk_std_core__list wild__0, kk_context_t* _ctx); /* (wild_0 : list<()>) -> <pure,console,fsys,ndet,std/num/random/random> () */ 

kk_unit_t kk_climate_dash_experiments_main(kk_context_t* _ctx); /* () -> <pure,console,fsys,ndet,std/num/random/random> () */ 

kk_unit_t kk_climate_dash_experiments__hmain(kk_context_t* _ctx); /* () -> <console,div,fsys,ndet> () */ 

void kk_climate_dash_experiments__init(kk_context_t* _ctx);

#endif // header
