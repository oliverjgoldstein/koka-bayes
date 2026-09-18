module sir_report_checks

import std/num/float64
import examples/sir_report

fun ensure(label : string, condition : bool) : exn ()
  if not(condition) then throw(label)

fun near(actual : float64, expected : float64) : bool
  is-finite(actual) && abs(actual - expected) <= 1.0e-12 * max(1.0, abs(expected))

fun fails(action : () -> <exn|e> a) : e bool
  try(fn(){ val result = action(); False }, fn(_exception){ True })

fun test-descriptive-summary() : exn ()
  // Rejected MCMC states and resampled particle duplicates retain multiplicity.
  val result = summarize-samples([8.0, 2.0, 4.0, 2.0], 4.0, 0.0)
  ensure("sample count preserves duplicates", result.count == 4)
  ensure("distinct count exposes duplicated particles", result.distinct-count == 3)
  ensure("mean weights every retained sample", near(result.sample-mean, 4.0))
  ensure("empirical interval contains the observed endpoint quantiles",
    near(result.lower90, 2.0) && near(result.upper90, 8.0))
  ensure("an exact recovery meets a zero tolerance", result.recovery-within-tolerance)
  val singleton = summarize-samples([0.25], 0.25, 0.0)
  ensure("a singleton has one distinct draw and a degenerate empirical interval",
    singleton.count == 1 && singleton.distinct-count == 1 &&
    near(singleton.lower90, 0.25) && near(singleton.upper90, 0.25))
  val close-values = summarize-samples([0.1000001, 0.1000002], 0.1, 0.01)
  ensure("distinct count must not use display-rounded values", close-values.distinct-count == 2)

fun test-empirical-quantiles() : exn ()
  // The inverse empirical CDF at .05 and .95 for 20 distinct draws is 1 and 19.
  val result = summarize-samples(
    [20.0, 19.0, 18.0, 17.0, 16.0, 15.0, 14.0, 13.0, 12.0, 11.0,
     10.0, 9.0, 8.0, 7.0, 6.0, 5.0, 4.0, 3.0, 2.0, 1.0], 10.5, 0.0)
  ensure("quantiles use ranks after sorting", near(result.lower90, 1.0) && near(result.upper90, 19.0))
  ensure("sorting preserves the mean", near(result.sample-mean, 10.5))

fun test-independent-recovery() : exn ()
  // The historical PMMH result recovered beta but missed the report-rate threshold.
  val beta = summarize-samples([0.775], 0.7, 0.18)
  val rate = summarize-samples([0.152], 0.3, 0.12)
  ensure("one parameter's miss cannot mark another's recovery as outside",
    beta.recovery-within-tolerance && not(rate.recovery-within-tolerance))
  ensure("recovery reports distance from generating truth", near(rate.truth-error, 0.148))
  val boundary = summarize-samples([0.25], 0.5, 0.25)
  ensure("the stated recovery threshold is inclusive", boundary.recovery-within-tolerance)

fun test-invalid-data() : exn ()
  ensure("an empty posterior is not a zero-valued estimate",
    fails(fn(){ summarize-samples([], 0.0, 1.0) }))
  [nan, posinf, neginf].foreach fn(value){
    ensure("nonfinite samples cannot produce a recovery summary",
      fails(fn(){ summarize-samples([0.3, value], 0.3, 0.12) }))
    ensure("nonfinite truth is rejected",
      fails(fn(){ summarize-samples([0.3], value, 0.12) }))
    ensure("nonfinite tolerance is rejected",
      fails(fn(){ summarize-samples([0.3], 0.3, value) }))
  }
  ensure("negative tolerance is rejected",
    fails(fn(){ summarize-samples([0.3], 0.3, ~0.1) }))

fun test-csv-precision() : exn ()
  // Default float formatting loses significant digits for some small magnitudes.
  [0.010000000000000002, 0.000012345678901234568, 1.0e-200, 1.0e200].foreach fn(value){
    val roundtrip = match parse-float64(csv-float(value))
      Just(parsed) -> parsed == value
      Nothing -> False
    ensure("CSV values round-trip without losing significant digits", roundtrip)
  }

pub fun main() : <console,exn> ()
  test-descriptive-summary()
  test-empirical-quantiles()
  test-independent-recovery()
  test-invalid-data()
  test-csv-precision()
  println("SIR report checks passed.")
