public module old-monad-bayes-timing-experiments

import std/num/double
import std/num/ddouble
import std/num/random
//import std/async
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

fun run_monad_bayes_experiments() {
    val data_1000 = generate_synthetic_lr_data(1000)
    val data_900  = generate_synthetic_lr_data(900)
    val data_800  = generate_synthetic_lr_data(800)
    val data_700  = generate_synthetic_lr_data(700)
    val data_600  = generate_synthetic_lr_data(600)
    val data_500  = generate_synthetic_lr_data(500)
    val data_400  = generate_synthetic_lr_data(400)
    val data_300  = generate_synthetic_lr_data(300)
    val data_200  = generate_synthetic_lr_data(200)
    val data_100  = generate_synthetic_lr_data(100)
    val data_50   = generate_synthetic_lr_data(50)
    val data_0    = generate_synthetic_lr_data(0)

    for(1, 1) fn(i) {

        println("Running Sequential Monte Carlo Timing Experiments!")
        print-elapsed {
            // increasing data set size:
            print-elapsed {smc(100, 1000, 4, logistic_regression(data_1000), True)}
            print-elapsed {smc(100, 900 , 4, logistic_regression(data_900), True)}
            print-elapsed {smc(100, 800 , 4, logistic_regression(data_800), True)}
            print-elapsed {smc(100, 700 , 4, logistic_regression(data_700), True)}
            print-elapsed {smc(100, 600 , 4, logistic_regression(data_600), True)}
            print-elapsed {smc(100, 500 , 4, logistic_regression(data_500), True)}
            print-elapsed {smc(100, 400 , 4, logistic_regression(data_400), True)}
            print-elapsed {smc(100, 300 , 4, logistic_regression(data_300), True)}
            print-elapsed {smc(100, 200 , 4, logistic_regression(data_200), True)}
            print-elapsed {smc(100, 100 , 4, logistic_regression(data_100), True)}
            print-elapsed {smc(100, 0   , 4, logistic_regression(data_0), True)}

            println("Mid-way SMC")
            // increasing number of steps:
            print-elapsed {smc(1000,50, 1, logistic_regression(data_50), True)}
            print-elapsed {smc(900, 50, 1,  logistic_regression(data_50), True)}
            print-elapsed {smc(800, 50, 1,  logistic_regression(data_50), True)}
            print-elapsed {smc(700, 50, 1,  logistic_regression(data_50), True)}
            print-elapsed {smc(600, 50, 1,  logistic_regression(data_50), True)}
            print-elapsed {smc(500, 50, 1,  logistic_regression(data_50), True)}
            print-elapsed {smc(400, 50, 1,  logistic_regression(data_50), True)}
            print-elapsed {smc(300, 50, 1,  logistic_regression(data_50), True)}
            print-elapsed {smc(200, 50, 1,  logistic_regression(data_50), True)}
            print-elapsed {smc(100, 50, 1,  logistic_regression(data_50), True)}
        }

        println("Completed Sequential Monte Carlo Timing Experiments!")
        println("Running Trace MCMC Timing Experiments!")

        print-elapsed {
            // increasing data set size:
            print-elapsed {tmcmc(logistic_regression(data_1000),100, Exp(0.0), 0)}
            print-elapsed {tmcmc(logistic_regression(data_900), 100, Exp(0.0), 0)}
            print-elapsed {tmcmc(logistic_regression(data_800), 100, Exp(0.0), 0)}
            print-elapsed {tmcmc(logistic_regression(data_700), 100, Exp(0.0), 0)}
            print-elapsed {tmcmc(logistic_regression(data_600), 100, Exp(0.0), 0)}
            print-elapsed {tmcmc(logistic_regression(data_500), 100, Exp(0.0), 0)}
            print-elapsed {tmcmc(logistic_regression(data_400), 100, Exp(0.0), 0)}
            print-elapsed {tmcmc(logistic_regression(data_300), 100, Exp(0.0), 0)}
            print-elapsed {tmcmc(logistic_regression(data_200), 100, Exp(0.0), 0)}
            print-elapsed {tmcmc(logistic_regression(data_100), 100, Exp(0.0), 0)}
            print-elapsed {tmcmc(logistic_regression(data_0),   100, Exp(0.0), 0)}
        }

        println("Mid-way TMCMC")

        print-elapsed {
            // increasing number of steps:
            print-elapsed {tmcmc(logistic_regression(data_50), 1000, Exp(0.0), 0)}
            print-elapsed {tmcmc(logistic_regression(data_50), 900,  Exp(0.0), 0)}
            print-elapsed {tmcmc(logistic_regression(data_50), 800,  Exp(0.0), 0)}
            print-elapsed {tmcmc(logistic_regression(data_50), 700,  Exp(0.0), 0)}
            print-elapsed {tmcmc(logistic_regression(data_50), 600,  Exp(0.0), 0)}
            print-elapsed {tmcmc(logistic_regression(data_50), 500,  Exp(0.0), 0)}
            print-elapsed {tmcmc(logistic_regression(data_50), 400,  Exp(0.0), 0)}
            print-elapsed {tmcmc(logistic_regression(data_50), 300,  Exp(0.0), 0)}
            print-elapsed {tmcmc(logistic_regression(data_50), 200,  Exp(0.0), 0)}
            print-elapsed {tmcmc(logistic_regression(data_50), 100,  Exp(0.0), 0)}
        }
        println("Completed Trace MCMC Timing Experiments!")
    }


      // print-elapsed {
      //     println("Begin SMC:")
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 0), exn-get(data.fst, 0), False, 10.0, -3.0, 4.7), True), "./months/jan/jan_smc_1.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 0), exn-get(data.fst, 0), False, 10.0, -3.0, 4.7), True), "./months/jan/jan_smc_2.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 1), exn-get(data.fst, 1), False, 8.0 , -1.0, 4.7), True), "./months/feb/feb_smc_1.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 1), exn-get(data.fst, 1), False, 8.0 , -1.0, 4.7), True), "./months/feb/feb_smc_2.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 2), exn-get(data.fst, 2), False, 7.0 ,  1.0, 4.7), True), "./months/mar/mar_smc_1.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 2), exn-get(data.fst, 2), False, 7.0 ,  1.0, 4.7), True), "./months/mar/mar_smc_2.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 3), exn-get(data.fst, 3), False, 6.0 ,  5.0, 4.7), True), "./months/apr/apr_smc_1.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 3), exn-get(data.fst, 3), False, 6.0 ,  5.0, 4.7), True), "./months/apr/apr_smc_2.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 4), exn-get(data.fst, 4), False, 8.0 ,  9.0, 4.7), True), "./months/may/may_smc_1.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 4), exn-get(data.fst, 4), False, 8.0 ,  9.0, 4.7), True), "./months/may/may_smc_2.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 5), exn-get(data.fst, 5), False, 8.0 , 10.0, 4.7), True), "./months/jun/jun_smc_1.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 5), exn-get(data.fst, 5), False, 8.0 , 10.0, 4.7), True), "./months/jun/jun_smc_2.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 6), exn-get(data.fst, 6), False, 9.0 , 11.0, 4.7), True), "./months/jul/jul_smc_1.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 6), exn-get(data.fst, 6), False, 9.0 , 11.0, 4.7), True), "./months/jul/jul_smc_2.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 7), exn-get(data.fst, 7), False, 6.0 , 11.0, 4.7), True), "./months/aug/aug_smc_1.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 7), exn-get(data.fst, 7), False, 6.0 , 11.0, 4.7), True), "./months/aug/aug_smc_2.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 8), exn-get(data.fst, 8), False, 5.0 , 10.0, 4.7), True), "./months/sep/sep_smc_1.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 8), exn-get(data.fst, 8), False, 5.0 , 10.0, 4.7), True), "./months/sep/sep_smc_2.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 9), exn-get(data.fst, 9), False, 9.0 ,  1.0, 4.7), True), "./months/oct/oct_smc_1.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 9), exn-get(data.fst, 9), False, 9.0 ,  1.0, 4.7), True), "./months/oct/oct_smc_2.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 10), exn-get(data.fst, 10), False, 7.0, 2.0, 4.7), True), "./months/nov/nov_smc_1.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 10), exn-get(data.fst, 10), False, 7.0, 2.0, 4.7), True), "./months/nov/nov_smc_2.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 11), exn-get(data.fst, 11), False, 6.0, -1.0,4.7), True), "./months/dec/dec_smc_1.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 11), exn-get(data.fst, 11), False, 6.0, -1.0,4.7), True), "./months/dec/dec_smc_2.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 0), exn-get(data.fst, 0), False , 10.0, -3.0, 4.7), True), "./months/jan/jan_smc_3.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 0), exn-get(data.fst, 0), False , 10.0, -3.0, 4.7), True), "./months/jan/jan_smc_4.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 1), exn-get(data.fst, 1), False , 8.0 , -1.0, 4.7), True), "./months/feb/feb_smc_3.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 1), exn-get(data.fst, 1), False , 8.0 , -1.0, 4.7), True), "./months/feb/feb_smc_4.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 2), exn-get(data.fst, 2), False , 7.0 ,  1.0, 4.7), True), "./months/mar/mar_smc_3.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 2), exn-get(data.fst, 2), False , 7.0 ,  1.0, 4.7), True), "./months/mar/mar_smc_4.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 3), exn-get(data.fst, 3), False , 6.0 ,  5.0, 4.7), True), "./months/apr/apr_smc_3.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 3), exn-get(data.fst, 3), False , 6.0 ,  5.0, 4.7), True), "./months/apr/apr_smc_4.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 4), exn-get(data.fst, 4), False , 8.0 ,  9.0, 4.7), True), "./months/may/may_smc_3.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 4), exn-get(data.fst, 4), False , 8.0 ,  9.0, 4.7), True), "./months/may/may_smc_4.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 5), exn-get(data.fst, 5), False , 8.0 , 10.0, 4.7), True), "./months/jun/jun_smc_3.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 5), exn-get(data.fst, 5), False , 8.0 , 10.0, 4.7), True), "./months/jun/jun_smc_4.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 6), exn-get(data.fst, 6), False , 9.0 , 11.0, 4.7), True), "./months/jul/jul_smc_3.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 6), exn-get(data.fst, 6), False , 9.0 , 11.0, 4.7), True), "./months/jul/jul_smc_4.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 7), exn-get(data.fst, 7), False , 6.0 , 11.0, 4.7), True), "./months/aug/aug_smc_3.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 7), exn-get(data.fst, 7), False , 6.0 , 11.0, 4.7), True), "./months/aug/aug_smc_4.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 8), exn-get(data.fst, 8), False , 5.0 , 10.0, 4.7), True), "./months/sep/sep_smc_3.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 8), exn-get(data.fst, 8), False , 5.0 , 10.0, 4.7), True), "./months/sep/sep_smc_4.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 9), exn-get(data.fst, 9), False , 9.0 ,  1.0, 4.7), True), "./months/oct/oct_smc_3.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 9), exn-get(data.fst, 9), False , 9.0 ,  1.0, 4.7), True), "./months/oct/oct_smc_4.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 10), exn-get(data.fst, 10), False , 7.0, 2.0, 4.7), True), "./months/nov/nov_smc_3.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 10), exn-get(data.fst, 10), False , 7.0, 2.0, 4.7), True), "./months/nov/nov_smc_4.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 11), exn-get(data.fst, 11), False , 6.0, -1.0,4.7), True), "./months/dec/dec_smc_3.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 11), exn-get(data.fst, 11), False , 6.0, -1.0,4.7), True), "./months/dec/dec_smc_4.csv")}
      //     println("Mid way!")
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 0), exn-get(data.fst, 0), False, 10.0, -3.0, 4.7), True), "./months/jan/jan_smc_5.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 0), exn-get(data.fst, 0), False, 10.0, -3.0, 4.7), True), "./months/jan/jan_smc_6.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 1), exn-get(data.fst, 1), False, 8.0 , -1.0, 4.7), True), "./months/feb/feb_smc_5.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 1), exn-get(data.fst, 1), False, 8.0 , -1.0, 4.7), True), "./months/feb/feb_smc_6.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 2), exn-get(data.fst, 2), False, 7.0 ,  1.0, 4.7), True), "./months/mar/mar_smc_5.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 2), exn-get(data.fst, 2), False, 7.0 ,  1.0, 4.7), True), "./months/mar/mar_smc_6.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 3), exn-get(data.fst, 3), False, 6.0 ,  5.0, 4.7), True), "./months/apr/apr_smc_5.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 3), exn-get(data.fst, 3), False, 6.0 ,  5.0, 4.7), True), "./months/apr/apr_smc_6.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 4), exn-get(data.fst, 4), False, 8.0 ,  9.0, 4.7), True), "./months/may/may_smc_5.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 4), exn-get(data.fst, 4), False, 8.0 ,  9.0, 4.7), True), "./months/may/may_smc_6.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 5), exn-get(data.fst, 5), False, 8.0 , 10.0, 4.7), True), "./months/jun/jun_smc_5.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 5), exn-get(data.fst, 5), False, 8.0 , 10.0, 4.7), True), "./months/jun/jun_smc_6.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 6), exn-get(data.fst, 6), False, 9.0 , 11.0, 4.7), True), "./months/jul/jul_smc_5.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 6), exn-get(data.fst, 6), False, 9.0 , 11.0, 4.7), True), "./months/jul/jul_smc_6.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 7), exn-get(data.fst, 7), False, 6.0 , 11.0, 4.7), True), "./months/aug/aug_smc_5.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 7), exn-get(data.fst, 7), False, 6.0 , 11.0, 4.7), True), "./months/aug/aug_smc_6.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 8), exn-get(data.fst, 8), False, 5.0 , 10.0, 4.7), True), "./months/sep/sep_smc_5.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 8), exn-get(data.fst, 8), False, 5.0 , 10.0, 4.7), True), "./months/sep/sep_smc_6.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 9), exn-get(data.fst, 9), False, 9.0 ,  1.0, 4.7), True), "./months/oct/oct_smc_5.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 9), exn-get(data.fst, 9), False, 9.0 ,  1.0, 4.7), True), "./months/oct/oct_smc_6.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 10), exn-get(data.fst, 10), False, 7.0, 2.0, 4.7), True), "./months/nov/nov_smc_5.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 10), exn-get(data.fst, 10), False, 7.0, 2.0, 4.7), True), "./months/nov/nov_smc_6.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 11), exn-get(data.fst, 11), False, 6.0, -1.0,4.7), True), "./months/dec/dec_smc_5.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 11), exn-get(data.fst, 11), False, 6.0, -1.0,4.7), True), "./months/dec/dec_smc_6.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 0), exn-get(data.fst, 0), False , 10.0, -3.0, 4.7), True), "./months/jan/jan_smc_7.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 0), exn-get(data.fst, 0), False , 10.0, -3.0, 4.7), True), "./months/jan/jan_smc_8.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 1), exn-get(data.fst, 1), False , 8.0 , -1.0, 4.7), True), "./months/feb/feb_smc_7.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 1), exn-get(data.fst, 1), False , 8.0 , -1.0, 4.7), True), "./months/feb/feb_smc_8.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 2), exn-get(data.fst, 2), False , 7.0 ,  1.0, 4.7), True), "./months/mar/mar_smc_7.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 2), exn-get(data.fst, 2), False , 7.0 ,  1.0, 4.7), True), "./months/mar/mar_smc_8.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 3), exn-get(data.fst, 3), False , 6.0 ,  5.0, 4.7), True), "./months/apr/apr_smc_7.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 3), exn-get(data.fst, 3), False , 6.0 ,  5.0, 4.7), True), "./months/apr/apr_smc_8.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 4), exn-get(data.fst, 4), False , 8.0 ,  9.0, 4.7), True), "./months/may/may_smc_7.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 4), exn-get(data.fst, 4), False , 8.0 ,  9.0, 4.7), True), "./months/may/may_smc_8.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 5), exn-get(data.fst, 5), False , 8.0 , 10.0, 4.7), True), "./months/jun/jun_smc_7.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 5), exn-get(data.fst, 5), False , 8.0 , 10.0, 4.7), True), "./months/jun/jun_smc_8.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 6), exn-get(data.fst, 6), False , 9.0 , 11.0, 4.7), True), "./months/jul/jul_smc_7.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 6), exn-get(data.fst, 6), False , 9.0 , 11.0, 4.7), True), "./months/jul/jul_smc_8.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 7), exn-get(data.fst, 7), False , 6.0 , 11.0, 4.7), True), "./months/aug/aug_smc_7.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 7), exn-get(data.fst, 7), False , 6.0 , 11.0, 4.7), True), "./months/aug/aug_smc_8.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 8), exn-get(data.fst, 8), False , 5.0 , 10.0, 4.7), True), "./months/sep/sep_smc_7.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 8), exn-get(data.fst, 8), False , 5.0 , 10.0, 4.7), True), "./months/sep/sep_smc_8.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 9), exn-get(data.fst, 9), False , 9.0 ,  1.0, 4.7), True), "./months/oct/oct_smc_7.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 9), exn-get(data.fst, 9), False , 9.0 ,  1.0, 4.7), True), "./months/oct/oct_smc_8.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 10), exn-get(data.fst, 10), False , 7.0, 2.0, 4.7), True), "./months/nov/nov_smc_7.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 10), exn-get(data.fst, 10), False , 7.0, 2.0, 4.7), True), "./months/nov/nov_smc_8.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 11), exn-get(data.fst, 11), False , 6.0, -1.0,4.7), True), "./months/dec/dec_smc_7.csv")}
      //     print-elapsed{write(smc(pt, rs, sbrs, linear_gaussian_climate_data(exn-get(data.snd, 11), exn-get(data.fst, 11), False , 6.0, -1.0,4.7), True), "./months/dec/dec_smc_8.csv")}
      //
      //     println("End of SMC.")
      //   }

}
