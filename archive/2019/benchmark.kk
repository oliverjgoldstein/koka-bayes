public module benchmark
/*
    File for running different benchmarks
*/
import std/num/random
import std/num/double
import std/num/ddouble
import std/time/timer
import std/time/duration
import effects-and-types
import output-and-plot
import smc
import model-resources
import handlers
import tmcmc


import std/time/timer

val target-mean = 3.0
val seeded_value_smc = 2.99790643160498327
val seeded_value_tmcmc = 2.97557683274418983
val initial-seed = 2020

val tolerance = 0.01
val high-tolerance = 1e-12

fun mean(nums: list<double>): double{
    nums.sum / nums.length.double
}

// Benchmarking functions
fun smc-sampling-benchmark(particle_num: int = 2000, step_num: int=10, step_size: int = 1){

    val (dur, result) = elapsed({
        smc(particle_num, step_num, step_size, sequential_gaussian(target-mean), True)
    })
    val calculated = result.map(snd).mean
    val difference = abs(target-mean - calculated)
    (dur, calculated, difference, difference < tolerance, abs(seeded_value_smc - calculated))
}



fun tmcmc-sampling-benchmark(step_num: int = 4000, init_weight: exp = Exp(0.0), burnin: int = 0){
    val (dur, result) = elapsed({
        random_sampler {
            tmcmc(sequential_gaussian(3.0), step_num, init_weight, burnin).fst
        }
    })
    val calculated = result.map(snd).mean
    val difference = abs(target-mean - calculated)
    (dur, calculated, difference, difference < tolerance, abs(seeded_value_tmcmc - calculated))
}

fun print_benchmark(msg: string, result: (duration, double, double, bool, double)){
    val (duration, calculated, difference, tol1, tol2) = result
    println("Benchmark: " ++ msg ++ ":" ++ [duration.show, calculated.show, difference.show, tol1.show, tol2.show].join(","))
}

// End of benchmarking functions


fun main(){
    pseudo-random(initial-seed,
        {
            print_benchmark("smc", smc-sampling-benchmark())
        }
    )
    pseudo-random(initial-seed,
        {print_benchmark("tcmc", tmcmc-sampling-benchmark())}
    )
}
