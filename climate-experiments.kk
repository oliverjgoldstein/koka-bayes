public module climate-experiments

import std/num/double
import std/num/ddouble
import std/num/random
import std/time/timer
import output-and-plot
import exponents
import effects-and-types
import smc
import tmcmc
import pmmh
import handlers
import model-resources
import climate-change
import data/preprocessing
import exn-get
import sampling


fun main() {
  val data_point               = 3.0
  val resample_steps           = 131
  val scores_before_resampling = 2
  val particles                = 2000 // Too many particles slows koka down.
  val t_steps                  = 100000
  val burnin                   = 80000

  // These parameters are from my MSc project:
  // val particles                = 2000
  // val t_steps                  = 100000
  // val burnin                   = 80000



  // println("Running Timing Experiments...")
  // random_sampler {
  //     run_experiments(1,10)
  // }
  // println("Completed Timing Experiments!")

  println("Running Climate Model...")
  run_climate_model(particles, resample_steps, scores_before_resampling, t_steps, burnin, 8)
  println("Completed Climate Model!")
  println("Finished running...")
}



// Original code has 10 as the max_number_of_data_points, but this reaches max_memory (heap size of 4 GB on my computer) nad cca 10GB of core data
fun run_experiments(number_of_repeats = 4, max_number_of_data_points=3) {
  val data_points = (list(0,max_number_of_data_points).map(fn(i){i * 100})).map(fn(i){(i, generate_synthetic_lr_data(i))})
  val data_50 = generate_synthetic_lr_data(50)
  for(1, number_of_repeats) fn(i) {

    println("Round #" ++ show(i))
    // increasing data set size:
    println("Running SMC with increasing data size:")
    data_points.map(fn(arg){
      val (sz, data_vals) = arg
      print-elapsed {smc(100, sz, 1, logistic_regression(data_vals), True)}
    })

    println("Mid-way with SMC")
    println("Running SMC with increasing number of particles:")
    data_points.map(fn(arg){
      val (sz, _) = arg
      print-elapsed {smc(sz,50, 1, logistic_regression(data_50), True)}
    })

    println("Completed SMC!")

    println("Running TMCMC with increasing data size:")
    // increasing data set size:
    data_points.map(fn(arg){
      val (_, data_vals) = arg
      print-elapsed {tmcmc(logistic_regression(data_vals),100, Exp(0.0), 0)}
    })

    println("Mid-way with TMCMC")
    println("Running TMCMC with increasing number of steps:")

    // increasing number of steps:
    data_points.map(fn(arg){
      val (sz, _) = arg
      print-elapsed {tmcmc(logistic_regression(data_50), sz, Exp(0.0), 0)}
    })

    println("Completed Trace MCMC!")
    println("")
    println(".....................................")
    println("Completed Round #" ++ show(i))
    println(".....................................")
    println("")
    println("")
    println("")
    println("")
  }
}

fun run_climate_model(pt : int, rs : int, sbrs : int, t_steps : int, burnin : int, repeat_num=8) {
  val data = pre_process_data()

  val pre_data = [
    (10.0, -3.0, "jan"),
    (8.0 , -1.0, "feb"),
    (7.0 ,  1.0, "mar"),
    (6.0 ,  5.0, "apr"),
    (8.0 ,  9.0, "may"),
    (8.0 , 10.0, "jun"),
    (9.0 , 11.0, "jul"),
    (6.0 , 11.0, "aug"),
    (5.0 , 10.0, "sep"),
    (9.0 ,  1.0, "oct"),
    (7.0, 2.0, "nov"),
    (6.0, -1.0, "dec")
  ]

  println("Starting to run the climate model! Run with -O2 --showelapsed flag to improve execution time.")
  println("Beginning to start TMCMC experiment #1:")

  print-elapsed {
    random_sampler {
      zip(list(0, 11), pre_data).map(
        fn(d){
          val (ind, (diff, subtract, name)) = d
          print-elapsed{
            write(tmcmc(linear_gaussian_climate_data(
                                           exn-get(data.snd, ind),
                                           exn-get(data.fst, ind), False, diff, subtract, 4.7),
                                           t_steps, Exp(0.0), burnin).fst,
                                           "./output-climate/" ++ name ++ "/" ++ "tmcmc_results.csv")
          }
        }
      )
    }
  }
  println("Beginning to start TMCMC experiment #2:")
  print-elapsed {
    random_sampler {
      zip(list(0, 11), pre_data).map(
        fn(d){
          val (ind, (diff, subtract, name)) = d
          print-elapsed{
            write(tmcmc(linear_gaussian_climate_data(
                                           exn-get(data.snd, ind),
                                           exn-get(data.fst, ind), False, diff, subtract, 4.7),
                                           t_steps, Exp(0.0), burnin).fst,
                                           "./output-climate/" ++ name ++ "/" ++ "tmcmc_exp_two_results.csv")
          }
        }
      )
    }
  }

  // print-elapsed {
  //   println("Beginning to start SMC:")
  //   zip(list(0, 11), pre_data).map(
  //     fn(d){
  //       for(1, repeat_num) fn(repeat_ind){
  //         val (ind, (diff, subtract, name)) = d
  //         print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, ind), exn-get(data.fst, ind), False, diff, subtract, 4.7), True),
  //                             "./output-climate/" ++ name ++ "/" ++ name ++ "_smc_" ++ repeat_ind.show ++ ".csv")}
  //       }
  //     }
  //   )
  //   println("End of SMC!")
  // }
}
