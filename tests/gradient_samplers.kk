module gradient_samplers

import std/num/float64
import autodiff/smooth
import alg/gradient
import alg/hmc
import alg/mala
import alg/mcmc

fun ensure(label : string, condition : bool) : exn ()
  if condition then () else throw(label)

fun close(label : string, actual : float64, expected : float64) : exn ()
  ensure(label ++ ": expected " ++ expected.show ++ ", got " ++ actual.show,
    is-finite(actual) && abs(actual - expected) <= 1.0e-10 * max(1.0, abs(expected)))

fun close-vector(label : string, actual : list<float64>, expected : list<float64>) : <div,exn> ()
  match (actual, expected)
    (Nil, Nil) -> ()
    (Cons(x, xs), Cons(y, ys)) ->
      close(label, x, y)
      close-vector(label, xs, ys)
    _ -> throw(label ++ ": vector shape differs")

fun fails(action : () -> <exn|e> a) : e bool
  try(fn(){ val result = action(); False }, fn(_exception){ True })

fun missing(value : maybe<a>) : bool
  match value
    Nothing -> True
    Just(_) -> False

fun standard-gaussian(xs : list<a>) : smooth<a> a
  match xs
    Cons(x, Nil) -> ad-mul(ad-constant(~0.5), ad-square(x))
    _ -> ad-constant(nan)

// Gamma(2,1), up to its normalizer, has support x > 0.
fun positive-target(xs : list<a>) : smooth<a> a
  match xs
    Cons(x, Nil) -> ad-sub(ad-log(x), x)
    _ -> ad-constant(nan)

fun invalid-target(_xs : list<a>) : smooth<a> a
  ad-constant(posinf)

fun singular-derivative(xs : list<a>) : smooth<a> a
  match xs
    Cons(x, Nil) -> ad-div(x, x)
    _ -> ad-constant(nan)

// Independent analytic oracle: mean (1,-2), covariance ((1,1/2),(1/2,1)).
// Its inverse covariance is ((4/3,-2/3),(-2/3,4/3)).
fun correlated-gaussian(xs : list<a>) : smooth<a> a
  match xs
    Cons(x, Cons(y, Nil)) ->
      val dx = ad-sub(x, ad-constant(1.0))
      val dy = ad-add(y, ad-constant(2.0))
      ad-mul(ad-constant(~2.0 / 3.0),
        ad-sub(ad-add(ad-square(dx), ad-square(dy)), ad-mul(dx, dy)))
    _ -> ad-constant(nan)

fun trajectory(start : gradient-state, momentum : list<float64>, eps : float64,
                 steps : int) : <div,exn> (gradient-state,list<float64>)
  match leapfrog(standard-gaussian, start, momentum, eps, steps)
    Nothing -> throw("expected a finite Gaussian leapfrog trajectory")
    Just(result) -> result

fun test-target-validation() : <div,exn> ()
  ensure("empty initial coordinates rejected", fails(fn(){ initial-target(standard-gaussian, []) }))
  [nan, posinf, neginf].foreach fn(x){
    ensure("nonfinite initial coordinate rejected", fails(fn(){ initial-target(standard-gaussian, [x]) }))
  }
  ensure("nonfinite initial target rejected", fails(fn(){ initial-target(invalid-target, [1.0]) }))
  ensure("nonfinite initial derivative rejected",
    fails(fn(){ initial-target(singular-derivative, [1.0e-320]) }))
  ensure("outside initial support rejected", fails(fn(){ initial-target(positive-target, [~1.0]) }))
  ensure("malformed cached gradient rejected",
    not(valid-gradient-state(Gradient-state([1.0, 2.0], ~1.0, [~1.0]))))
  ensure("nonfinite cached gradient rejected",
    not(valid-gradient-state(Gradient-state([1.0], ~1.0, [nan]))))
  val state = initial-target(standard-gaussian, [1.0])
  ensure("mismatched momentum rejected", missing(leapfrog(standard-gaussian, state, [1.0, 2.0], 0.1, 2)))
  ensure("malformed trajectory state rejected",
    missing(leapfrog(standard-gaussian, Gradient-state([1.0], ~0.5, []), [1.0], 0.1, 2)))
  ensure("nonfinite momentum rejected", missing(leapfrog(standard-gaussian, state, [nan], 0.1, 2)))
  ensure("zero trajectory steps rejected", missing(leapfrog(standard-gaussian, state, [1.0], 0.1, 0)))
  [0.0, nan, posinf].foreach fn(eps){
    ensure("invalid trajectory step rejected", missing(leapfrog(standard-gaussian, state, [1.0], eps, 2)))
  }
  val positive = initial-target(positive-target, [1.0])
  ensure("trajectory crossing support rejected", missing(leapfrog(positive-target, positive, [~2.0], 1.0, 1)))
  ensure("nonfinite proposal target rejected", missing(evaluate-target(invalid-target, [1.0])))
  ensure("nonfinite proposal derivative rejected", missing(evaluate-target(singular-derivative, [1.0e-320])))

fun test-leapfrog() : <div,exn> ()
  close("finite large kinetic energy", kinetic-energy([1.5e154]) / 1.125e308, 1.0)
  val initial = initial-target(standard-gaussian, [1.0])
  val (single, single-momentum) = trajectory(initial, [0.3], 0.1, 1)
  close-vector("one-step position", single.position, [1.025])
  close-vector("one-step momentum", single-momentum, [0.19875])
  close("one-step energy correction",
    ~single.log-density + kinetic-energy(single-momentum)
      - (~initial.log-density + kinetic-energy([0.3])), 0.00006328125)
  val (forward-state, forward-momentum) = trajectory(initial, [0.3], 0.17, 13)
  val (backward-state, backward-momentum) = trajectory(forward-state, forward-momentum, ~0.17, 13)
  close-vector("reverse-time position", backward-state.position, initial.position)
  close-vector("reverse-time momentum", backward-momentum, [0.3])
  val (flipped-state, flipped-momentum) = trajectory(forward-state,
    forward-momentum.map(fn(p){ ~p }), 0.17, 13)
  close-vector("momentum-flip position", flipped-state.position, initial.position)
  close-vector("momentum-flip momentum", flipped-momentum, [~0.3])
  val (coarse, coarse-p) = trajectory(initial, [0.0], 0.2, 5)
  val (fine, fine-p) = trajectory(initial, [0.0], 0.1, 10)
  val coarse-error = abs(~coarse.log-density + kinetic-energy(coarse-p) - 0.5)
  val fine-error = abs(~fine.log-density + kinetic-energy(fine-p) - 0.5)
  ensure("leapfrog energy error decreases quadratically", coarse-error > 0.0 && fine-error < 0.3 * coarse-error)

fun test-mala-correction() : <div,exn> ()
  close("finite large Gaussian transition exponent",
    mala-log-transition(Gradient-state([0.0], 0.0, [0.0]),
      Gradient-state([1.5e154], 0.0, [0.0]), 1.0) / (~1.125e308), 1.0)
  val x = initial-target(standard-gaussian, [1.0])
  val y = initial-target(standard-gaussian, [2.0])
  close-vector("MALA drift includes half variance", mala-mean(x, 1.0), [0.5])
  val forward = mala-log-transition(x, y, 1.0)
  val backward = mala-log-transition(y, x, 1.0)
  close("MALA forward Gaussian exponent", forward, ~1.125)
  close("MALA reverse Gaussian exponent", backward, 0.0)
  val ratio = y.log-density - x.log-density + backward - forward
  val reverse-ratio = x.log-density - y.log-density + forward - backward
  close("MALA asymmetric acceptance", ratio, ~0.375)
  close("MALA reverse acceptance", reverse-ratio, 0.375)
  close("MALA detailed balance log flow",
    x.log-density + forward + min(0.0, ratio),
    y.log-density + backward + min(0.0, reverse-ratio))
  close-vector("MALA step size is noise standard deviation", mala-mean(x, 0.5), [0.875])

fun check-rejection(label : string, chain : mcmc-result<list<float64>>) : exn ()
  ensure(label ++ " rejects invalid trajectories", chain.accepted == 0)
  ensure(label ++ " retains the full post-burn-in chain", chain.samples.length == 10)
  ensure(label ++ " retains repeated states", chain.samples.all(fn(x){ x == [1.0] }))

fun check-reproducible(label : string, a : mcmc-result<list<float64>>,
                       b : mcmc-result<list<float64>>) : exn ()
  ensure(label ++ " reproduces seeded samples", a.samples == b.samples && a.accepted == b.accepted)

fun check-posterior(label : string, seed : int, result : mcmc-result<list<float64>>) : <console,div,exn> ()
  val name = label ++ " seed " ++ seed.show
  ensure(name ++ " retains exactly 4000 draws", result.samples.length == 4000)
  ensure(name ++ " accepts and rejects proposals", result.accepted > 0 && result.accepted < 4500)
  val centered = result.samples.map fn(position){
    match position
      Cons(x, Cons(y, Nil)) ->
        ensure(name ++ " has finite coordinates", is-finite(x) && is-finite(y))
        (x - 1.0, y + 2.0)
      _ -> throw(name ++ ": wrong coordinate dimension")
  }
  val n = float64(centered.length)
  val mx = centered.foldl(0.0, fn(acc, xy){ acc + fst(xy) }) / n
  val my = centered.foldl(0.0, fn(acc, xy){ acc + snd(xy) }) / n
  val xx = centered.foldl(0.0, fn(acc, xy){ acc + fst(xy) * fst(xy) }) / n
  val yy = centered.foldl(0.0, fn(acc, xy){ acc + snd(xy) * snd(xy) }) / n
  val xy = centered.foldl(0.0, fn(acc, point){ acc + fst(point) * snd(point) }) / n
  // Declared before sampling: three fixed seeds, 4500 transitions / 500 burnin;
  // mean errors <= .16, centered second-moment errors <= .20, cross error <= .15.
  // Center around the analytic mean, never the empirical mean under test.
  ensure(name ++ " x mean agrees with exact posterior", abs(mx) <= 0.16)
  ensure(name ++ " y mean agrees with exact posterior", abs(my) <= 0.16)
  ensure(name ++ " x second moment agrees with exact posterior", abs(xx - 1.0) <= 0.20)
  ensure(name ++ " y second moment agrees with exact posterior", abs(yy - 1.0) <= 0.20)
  ensure(name ++ " cross moment agrees with exact posterior", abs(xy - 0.5) <= 0.15)
  println(name ++ ": mean errors [" ++ mx.show ++ ", " ++ my.show
    ++ "], second moments [" ++ xx.show ++ ", " ++ yy.show ++ "], cross moment " ++ xy.show)

pub fun test-hmc() : <console,div,exn> ()
  test-target-validation()
  test-leapfrog()
  [Mcmc-config(0, 0), Mcmc-config(10, 10), Mcmc-config(10, ~1)].foreach fn(config){
    ensure("HMC invalid budget rejected", fails(fn(){ hmc(config, standard-gaussian, [0.0], 0.1, 2) }))
  }
  [0.0, ~0.1, nan, posinf].foreach fn(eps){
    ensure("HMC invalid step size rejected", fails(fn(){ hmc(default-config(2), standard-gaussian, [0.0], eps, 2) }))
  }
  [0, ~1].foreach fn(steps){
    ensure("HMC invalid trajectory length rejected", fails(fn(){ hmc(default-config(2), standard-gaussian, [0.0], 0.1, steps) }))
  }
  ensure("HMC empty initial position rejected", fails(fn(){ hmc(default-config(2), standard-gaussian, [], 0.1, 2) }))
  ensure("HMC nonfinite initial position rejected", fails(fn(){ hmc(default-config(2), standard-gaussian, [posinf], 0.1, 2) }))
  check-rejection("HMC", hmc(default-config(15, 5), standard-gaussian, [1.0], 1.0e200, 2))
  check-reproducible("HMC", hmc(default-config(25, 5), standard-gaussian, [1.0], 0.3, 5, 881),
    hmc(default-config(25, 5), standard-gaussian, [1.0], 0.3, 5, 881))
  [719, 727, 733].foreach fn(seed){
    check-posterior("HMC", seed, hmc(default-config(4500, 500), correlated-gaussian, [0.0, 0.0], 0.2, 7, seed))
  }
  println("HMC gradient inference checks passed (3 posterior runs).")

pub fun test-mala() : <console,div,exn> ()
  test-target-validation()
  test-mala-correction()
  [Mcmc-config(0, 0), Mcmc-config(10, 10), Mcmc-config(10, ~1)].foreach fn(config){
    ensure("MALA invalid budget rejected", fails(fn(){ mala(config, standard-gaussian, [0.0], 0.1) }))
  }
  [0.0, ~0.1, nan, posinf].foreach fn(eps){
    ensure("MALA invalid step size rejected", fails(fn(){ mala(default-config(2), standard-gaussian, [0.0], eps) }))
  }
  ensure("MALA empty initial position rejected", fails(fn(){ mala(default-config(2), standard-gaussian, [], 0.1) }))
  ensure("MALA nonfinite initial position rejected", fails(fn(){ mala(default-config(2), standard-gaussian, [posinf], 0.1) }))
  check-rejection("MALA", mala(default-config(15, 5), standard-gaussian, [1.0], 1.0e200))
  check-reproducible("MALA", mala(default-config(25, 5), standard-gaussian, [1.0], 0.7, 881),
    mala(default-config(25, 5), standard-gaussian, [1.0], 0.7, 881))
  [719, 727, 733].foreach fn(seed){
    check-posterior("MALA", seed, mala(default-config(4500, 500), correlated-gaussian, [0.0, 0.0], 0.9, seed))
  }
  println("MALA gradient inference checks passed (3 posterior runs).")

pub fun main() : <console,div,exn> ()
  test-hmc()
  test-mala()
  println("Gradient inference checks passed.")
