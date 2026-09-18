module examples/sir_report

import std/num/float64
import std/num/random
import std/os/file
import std/os/path

import alg/mcmc
import alg/pmmh
import alg/rmsmc
import alg/simulate
import alg/smc
import alg/smc2
import core/env
import examples/sir

// Koka 3.2.3's std/os/dir.ensure-dir has no JavaScript implementation.
// The pinned Node runtime supplies recursive directory creation directly.
extern ensure-report-directory(directory : string) : <fsys,exn> ()
  js inline "(process.getBuiltinModule('node:fs').mkdirSync(#1 || '.', { recursive: true }), undefined)"

pub struct sir-truth
  beta        : float64
  gamma-rate  : float64
  report-rate : float64

struct sir-problem
  truth            : sir-truth
  observed-reports : list<int>
  inference-env    : env
  days             : int

pub struct algorithm-report
  name          : string
  beta-samples  : list<float64>
  report-samples: list<float64>
  beta-summary  : sample-summary
  report-summary: sample-summary
  note          : string

pub struct sample-summary
  count                     : int
  distinct-count            : int
  sample-mean               : float64
  lower90                   : float64
  upper90                   : float64
  truth-error               : float64
  recovery-within-tolerance : bool

// Describes the actual retained draws, including repeated rejected states.
// The interval is the inverse empirical CDF at 5% and 95%, not a confidence
// interval for the mean. Counts and distinct values do not establish convergence.
pub fun summarize-samples(samples : list<float64>, truth : float64,
                          tolerance : float64) : exn sample-summary
  if samples.is-empty || not(samples.all(is-finite))
    then throw("SIR diagnostics require nonempty finite posterior samples")
  if not(is-finite(truth)) || not(is-finite(tolerance)) || tolerance < 0.0
    then throw("SIR diagnostics require finite truth and a nonnegative finite tolerance")
  val count = samples.length
  val sorted = samples.foldl([], fn(acc, value){ insert-sample(value, acc) })
  // Divide before adding so ordinary finite large samples do not overflow a sum.
  val sample-mean = samples.foldl(0.0, fn(acc, value){ acc + value / float64(count) })
  val truth-error = abs(sample-mean - truth)
  if not(is-finite(sample-mean)) || not(is-finite(truth-error))
    then throw("SIR diagnostic summary exceeded finite floating-point range")
  Sample-summary(count, distinct-samples(sorted), sample-mean,
    sample-at(sorted, max(0, (count * 5 + 99) / 100 - 1)),
    sample-at(sorted, max(0, (count * 95 + 99) / 100 - 1)),
    truth-error, truth-error <= tolerance)

fun insert-sample(value : float64, sorted : list<float64>) : list<float64>
  match sorted
    Nil -> [value]
    Cons(first, rest) ->
      if value <= first then Cons(value, sorted)
        else Cons(first, insert-sample(value, rest))

fun distinct-samples(sorted : list<float64>) : int
  match sorted
    Nil -> 0
    Cons(first, rest) ->
      match rest
        Cons(next, _) -> (if first == next then 0 else 1) + distinct-samples(rest)
        Nil -> 1

fun sample-at(sorted : list<float64>, index : int) : float64
  match sorted
    Cons(value, rest) -> if index <= 0 then value else sample-at(rest, index - 1)
    Nil -> impossible("empirical quantile index exceeds sample count")

pub fun write-sir-report(output-prefix : string = "results/sir-diagnostics") : <console,fsys,exn,div,random> ()
  val problem = synthetic-problem()
  println("running SMC")
  val smc-report = run-smc-report(problem)
  println("running RMSMC")
  val rmsmc-report = run-rmsmc-report(problem)
  println("running PMMH")
  val pmmh-report = run-pmmh-report(problem)
  println("running SMC2")
  val smc2-report = run-smc2-report(problem)
  val reports = [smc-report, rmsmc-report, pmmh-report, smc2-report]
  val dashboard-path = path(output-prefix ++ "-dashboard.svg")
  val summary-path = path(output-prefix ++ "-summary.csv")
  val samples-path = path(output-prefix ++ "-samples.csv")
  ensure-report-directory(dashboard-path.nobase.string)
  write-text-file(dashboard-path, render-dashboard(problem, reports), False)
  write-text-file(summary-path, render-summary-csv(problem, reports), False)
  write-text-file(samples-path, render-samples-csv(reports), False)
  println("SIR particle diagnostics")
  println("  reports = [" ++ problem.observed-reports.map(fn(x){ x.show }).join(", ") ++ "]")
  println("  Recovery compares sample means with generating parameters; it is not an inference correctness test.")
  println("  Empirical 90% intervals and distinct counts describe these draws; they do not establish convergence or Monte Carlo error.")
  print-reports(reports)
  println("  wrote " ++ dashboard-path.string)
  println("  wrote " ++ summary-path.string)
  println("  wrote " ++ samples-path.string)

fun synthetic-problem(days : int = 12) : <div,random> sir-problem
  val truth = Sir-truth(0.7, 0.009, 0.3)
  val known : env =
    set(report-rate-var, [truth.report-rate],
    set(gamma-var, [truth.gamma-rate],
    set(beta-var, [truth.beta], empty())))
  val synthetic = pseudo-random(211, fn(){ simulate(known, sir-model(days)) })
  val inference-env : env =
    set(reported-var, synthetic.value.reports,
    set(gamma-var, [truth.gamma-rate], empty()))
  Sir-problem(truth, synthetic.value.reports, inference-env, days)

fun run-smc-report(problem : sir-problem) : <div,random,exn> algorithm-report
  val result = pseudo-random(223, fn(){ smc(96, problem.days, problem.inference-env, sir-sequential()) })
  make-report("SMC",
              get(beta-var, result.posterior-env),
              get(report-rate-var, result.posterior-env),
              problem.truth,
              "particles=" ++ result.particles.length.show ++ ", logZ=" ++ short-float64(result.log-evidence))

fun run-rmsmc-report(problem : sir-problem) : <div,random,exn> algorithm-report
  val result = pseudo-random(227, fn(){ rmsmc(64, problem.days, 2, problem.inference-env, sir-sequential()) })
  make-report("RMSMC",
              get(beta-var, result.posterior-env),
              get(report-rate-var, result.posterior-env),
              problem.truth,
              "particles=" ++ result.particles.length.show ++ ", logZ=" ++ short-float64(result.log-evidence))

fun run-pmmh-report(problem : sir-problem) : <div,random,exn> algorithm-report
  val config = default-config(90, 30)
  val result =
    pseudo-random(229, fn(){
      pmmh-with(48,
                problem.days,
                config,
                problem.inference-env,
                sir-sequential(),
                sir-parameter-log-prior,
                sir-parameter-kernel)
    })
  make-report("PMMH",
              get(beta-var, result.posterior-env),
              get(report-rate-var, result.posterior-env),
              problem.truth,
              "samples=" ++ result.samples.length.show ++ ", accepted=" ++ result.accepted.show)

fun run-smc2-report(problem : sir-problem) : <div,random,exn> algorithm-report
  val result =
    pseudo-random(233, fn(){
      smc2-with(32,
                32,
                problem.days,
                2,
                problem.inference-env,
                sir-sequential(),
                sir-parameter-log-prior,
                sir-parameter-kernel)
    })
  make-report("SMC2",
              get(beta-var, result.posterior-env),
              get(report-rate-var, result.posterior-env),
              problem.truth,
              "outer=" ++ result.particles.length.show ++ ", logZ=" ++ short-float64(result.log-evidence))

fun make-report(name : string,
                beta-samples : list<float64>,
                report-samples : list<float64>,
                truth : sir-truth,
                note : string) : exn algorithm-report
  Algorithm-report(name,
                   beta-samples,
                   report-samples,
                   summarize-samples(beta-samples, truth.beta, 0.18),
                   summarize-samples(report-samples, truth.report-rate, 0.12),
                   note)

fun render-dashboard(problem : sir-problem, reports : list<algorithm-report>) : <div> string
  val beta-range = sample-range(reports.flatmap(fn(report){ report.beta-samples }), problem.truth.beta)
  val rate-range = sample-range(reports.flatmap(fn(report){ report.report-samples }), problem.truth.report-rate)
  val width = 1320
  val height = 920
  val header =
    "<text x='40' y='46' font-family='Menlo, monospace' font-size='28' font-weight='700' fill='#18222c'>SIR Inference Diagnostics</text>" ++
    "<text x='40' y='76' font-family='Menlo, monospace' font-size='14' fill='#405060'>Synthetic truth: beta=" ++ short-float64(problem.truth.beta) ++
    ", gamma=" ++ short-float64(problem.truth.gamma-rate) ++
    ", report-rate=" ++ short-float64(problem.truth.report-rate) ++
    " | days=" ++ problem.days.show ++ "</text>" ++
    "<text x='40' y='102' font-family='Menlo, monospace' font-size='12' fill='#5f6b76'>Observed reports: [" ++ problem.observed-reports.map(fn(x){ x.show }).join(", ") ++ "]</text>"
  val beta-panels = render-panels(reports, "beta", problem.truth.beta, beta-range, 40, 140, "#0f766e", fn(report){ report.beta-samples }, fn(report){ report.beta-summary })
  val rate-panels = render-panels(reports, "report-rate", problem.truth.report-rate, rate-range, 40, 500, "#9a3412", fn(report){ report.report-samples }, fn(report){ report.report-summary })
  val legend =
    text(40, 850, "Red line = generating parameter; black line = sample mean. Recovery tolerances: beta 0.18, report-rate 0.12.", 12, "#5f6b76") ++
    text(40, 874, "Recovery within tolerance is not an inference correctness or convergence test.", 12, "#5f6b76") ++
    text(40, 898, "Empirical 90% intervals and distinct counts describe retained draws; they do not measure Monte Carlo error.", 12, "#5f6b76")
  svg(width, height, header ++ beta-panels ++ rate-panels ++ legend)

fun render-panels(reports : list<algorithm-report>,
                  parameter : string,
                  truth : float64,
                  range : (float64,float64),
                  x0 : int,
                  y0 : int,
                  color : string,
                  select-samples : algorithm-report -> list<float64>,
                  select-summary : algorithm-report -> sample-summary) : <div> string
  render-panels-at(reports, parameter, truth, range, x0, y0, color, select-samples, select-summary, 0)

fun render-panels-at(reports : list<algorithm-report>,
                     parameter : string,
                     truth : float64,
                     range : (float64,float64),
                     x0 : int,
                     y0 : int,
                     color : string,
                     select-samples : algorithm-report -> list<float64>,
                     select-summary : algorithm-report -> sample-summary,
                     index : int) : <div> string
  match reports
    Nil -> ""
    Cons(report, rest) ->
      val panel-x = x0 + (index * 310)
      render-histogram-panel(report,
                             parameter,
                             truth,
                             range,
                             panel-x,
                             y0,
                             290,
                             320,
                             color,
                             select-samples(report),
                             select-summary(report)) ++
      render-panels-at(rest, parameter, truth, range, x0, y0, color, select-samples, select-summary, index + 1)

fun render-histogram-panel(report : algorithm-report,
                           parameter : string,
                           truth : float64,
                           range : (float64,float64),
                           x : int,
                           y : int,
                           width : int,
                           height : int,
                           color : string,
                           samples : list<float64>,
                           summary : sample-summary) : <div> string
  val background = if summary.recovery-within-tolerance then "#ecfdf5" else "#fff7ed"
  val border = if summary.recovery-within-tolerance then "#0f766e" else "#c2410c"
  val plot-x = x + 18
  val plot-y = y + 110
  val plot-width = width - 36
  val plot-height = height - 180
  val bins = histogram(samples, 14, fst(range), snd(range))
  val max-bin = max-int(bins, 1)
  val bars = render-bars(bins, plot-x, plot-y, plot-width, plot-height, max-bin, color, bins.length, 0)
  val truth-line = render-marker(truth, fst(range), snd(range), plot-x, plot-y, plot-width, plot-height, "#dc2626", "4,4")
  val mean-line = render-marker(summary.sample-mean, fst(range), snd(range), plot-x, plot-y, plot-width, plot-height, "#111827", "none")
  rect(x, y, width, height, background, border, 2) ++
  text(x + 14, y + 26, report.name ++ " · " ++ parameter, 18, "#18222c", True) ++
  text(x + 14, y + 48, report.note, 12, "#4b5563") ++
  text(x + 14, y + 68, "draws=" ++ summary.count.show ++ ", distinct=" ++ summary.distinct-count.show, 12, "#4b5563") ++
  text(x + 14, y + 88, "empirical 90%=[" ++ short-float64(summary.lower90) ++ ", " ++ short-float64(summary.upper90) ++ "]", 12, "#4b5563") ++
  text(x + 14, y + height - 28, "mean=" ++ short-float64(summary.sample-mean) ++ ", truth error=" ++ short-float64(summary.truth-error), 12, "#374151") ++
  text(x + 14, y + height - 8, "Recovery: " ++ recovery-status(summary), 12, border, True) ++
  rect(plot-x, plot-y, plot-width, plot-height, "#ffffff", "#d1d5db", 1) ++
  bars ++ truth-line ++ mean-line ++
  text(plot-x, plot-y + plot-height + 18, short-float64(fst(range)), 11, "#6b7280") ++
  text(plot-x + plot-width - 44, plot-y + plot-height + 18, short-float64(snd(range)), 11, "#6b7280")

fun render-bars(counts : list<int>,
                x : int,
                y : int,
                width : int,
                height : int,
                max-count : int,
                fill : string,
                bin-count : int,
                index : int) : <div> string
  match counts
    Nil -> ""
    Cons(count, rest) ->
      val countf = float64(count)
      val maxf = float64(max(1, max-count))
      val bar-width = float64(width) / float64(max(1, bin-count))
      val h = int((countf / maxf) * float64(height))
      val bar-x = x + int(float64(index) * bar-width) + 1
      val bar-y = y + height - h
      rect(bar-x, bar-y, max(1, int(bar-width) - 2), h, fill, fill, 0) ++
      render-bars(rest, x, y, width, height, max-count, fill, bin-count, index + 1)

fun render-marker(value : float64,
                  lo : float64,
                  hi : float64,
                  x : int,
                  y : int,
                  width : int,
                  height : int,
                  stroke : string,
                  dash : string) : string
  val px = x + int(position(value, lo, hi) * float64(width))
  if dash == "none"
    then line(px, y, px, y + height, stroke, 2.5, "")
    else line(px, y, px, y + height, stroke, 2.5, dash)

fun render-summary-csv(problem : sir-problem, reports : list<algorithm-report>) : string
  "algorithm,beta_truth,beta_mean,beta_error,beta_count,beta_distinct,beta_lower90,beta_upper90,beta_recovery_within_tolerance," ++
  "report_truth,report_mean,report_error,report_count,report_distinct,report_lower90,report_upper90,report_recovery_within_tolerance,note\n" ++
  reports.map(fn(report){
    report.name ++ "," ++
    csv-float(problem.truth.beta) ++ "," ++ summary-fields(report.beta-summary) ++ "," ++
    csv-float(problem.truth.report-rate) ++ "," ++ summary-fields(report.report-summary) ++ "," ++
    quote-csv(report.note)
  }).join("\n") ++ "\n"

fun summary-fields(summary : sample-summary) : string
  csv-float(summary.sample-mean) ++ "," ++ csv-float(summary.truth-error) ++ "," ++
  summary.count.show ++ "," ++ summary.distinct-count.show ++ "," ++
  csv-float(summary.lower90) ++ "," ++ csv-float(summary.upper90) ++ "," ++
  (if summary.recovery-within-tolerance then "true" else "false")

fun render-samples-csv(reports : list<algorithm-report>) : string
  "algorithm,parameter,value\n" ++ reports.flatmap(render-sample-lines).join("\n") ++ "\n"

fun render-sample-lines(report : algorithm-report) : list<string>
  report.beta-samples.map(fn(value){ report.name ++ ",beta," ++ csv-float(value) }) ++
  report.report-samples.map(fn(value){ report.name ++ ",report-rate," ++ csv-float(value) })

// Default fixed formatting uses 17 decimal places and can lose significant
// digits for small values. Exponential formatting preserves float64 precision.
pub fun csv-float(value : float64) : string
  show-exp(value)

fun svg(width : int, height : int, content : string) : string
  "<svg xmlns='http://www.w3.org/2000/svg' width='" ++ width.show ++ "' height='" ++ height.show ++ "' viewBox='0 0 " ++ width.show ++ " " ++ height.show ++ "'>" ++
  "<rect width='100%' height='100%' fill='#f8fafc'/>" ++
  content ++
  "</svg>"

fun rect(x : int, y : int, width : int, height : int, fill : string, stroke : string, stroke-width : int) : string
  "<rect x='" ++ x.show ++ "' y='" ++ y.show ++ "' width='" ++ max(0, width).show ++ "' height='" ++ max(0, height).show ++
  "' fill='" ++ fill ++ "' stroke='" ++ stroke ++ "' stroke-width='" ++ stroke-width.show ++ "' rx='10' ry='10'/>"

fun line(x1 : int, y1 : int, x2 : int, y2 : int, stroke : string, stroke-width : float64, dash : string) : string
  val dash-attr = if dash.is-empty then "" else " stroke-dasharray='" ++ dash ++ "'"
  "<line x1='" ++ x1.show ++ "' y1='" ++ y1.show ++ "' x2='" ++ x2.show ++ "' y2='" ++ y2.show ++
  "' stroke='" ++ stroke ++ "' stroke-width='" ++ show-fixed(stroke-width, 1) ++ "'" ++ dash-attr ++ "/>"

fun text(x : int, y : int, content : string, size : int, fill : string, bold : bool = False) : string
  val weight = if bold then "700" else "400"
  "<text x='" ++ x.show ++ "' y='" ++ y.show ++ "' font-family='Menlo, monospace' font-size='" ++ size.show ++
  "' font-weight='" ++ weight ++ "' fill='" ++ fill ++ "'>" ++ content ++ "</text>"

fun sample-range(samples : list<float64>, truth : float64) : <div> (float64,float64)
  val lo = min(min-sample(samples, truth), truth)
  val hi = max(max-sample(samples, truth), truth)
  val spread = max(0.05, hi - lo)
  (lo - (0.08 * spread), hi + (0.08 * spread))

fun histogram(samples : list<float64>, bins : int, lo : float64, hi : float64) : <div> list<int>
  fill-histogram(samples, bins, lo, hi, zeros(bins))

fun fill-histogram(samples : list<float64>, bins : int, lo : float64, hi : float64, counts : list<int>) : <div> list<int>
  match samples
    Nil -> counts
    Cons(sample, rest) ->
      val ix = bucket(sample, bins, lo, hi)
      fill-histogram(rest, bins, lo, hi, add-count(ix, counts))

fun bucket(value : float64, bins : int, lo : float64, hi : float64) : int
  if bins <= 1 || hi <= lo
    then 0
    else {
      val normalized = (value - lo) / (hi - lo)
      val ix0 = int(normalized * float64(bins))
      clamp-int(0, bins - 1, ix0)
    }

fun add-count(target : int, counts : list<int>) : list<int>
  match counts
    Nil -> []
    Cons(count, rest) ->
      if target <= 0
        then Cons(count + 1, rest)
        else Cons(count, add-count(target - 1, rest))

fun zeros(count : int) : <div> list<int>
  if count <= 0
    then []
    else Cons(0, zeros(count - 1))

fun max-int(values : list<int>, current : int) : int
  match values
    Nil -> current
    Cons(value, rest) -> max-int(rest, max(current, value))

fun min-sample(values : list<float64>, current : float64) : <div> float64
  match values
    Nil -> current
    Cons(value, rest) -> min-sample(rest, min(current, value))

fun max-sample(values : list<float64>, current : float64) : <div> float64
  match values
    Nil -> current
    Cons(value, rest) -> max-sample(rest, max(current, value))

fun position(value : float64, lo : float64, hi : float64) : float64
  if hi <= lo
    then 0.5
    else clamp-float64(0.0, 1.0, (value - lo) / (hi - lo))

fun clamp-int(lo : int, hi : int, value : int) : int
  if value < lo then lo
  elif value > hi then hi
  else value

fun clamp-float64(lo : float64, hi : float64, value : float64) : float64
  if value < lo then lo
  elif value > hi then hi
  else value

fun quote-csv(text : string) : string
  "\"" ++ text.replace-all("\"", "\"\"") ++ "\""

fun short-float64(value : float64) : string
  show-fixed(value, 3)

fun recovery-status(summary : sample-summary) : string
  if summary.recovery-within-tolerance then "within tolerance" else "outside tolerance"

fun print-summary(parameter : string, summary : sample-summary) : console ()
  println("    " ++ parameter ++ ": mean=" ++ short-float64(summary.sample-mean) ++
    ", truth error=" ++ short-float64(summary.truth-error) ++
    ", recovery " ++ recovery-status(summary) ++
    ", draws=" ++ summary.count.show ++ ", distinct=" ++ summary.distinct-count.show ++
    ", empirical 90%=[" ++ short-float64(summary.lower90) ++ ", " ++ short-float64(summary.upper90) ++ "]")

fun print-reports(reports : list<algorithm-report>) : console ()
  match reports
    Nil -> ()
    Cons(report, rest) ->
      println("  " ++ report.name ++ " (" ++ report.note ++ ")")
      print-summary("beta", report.beta-summary)
      print-summary("report-rate", report.report-summary)
      print-reports(rest)

// Run with: ./bayes run examples/sir_report.kk
pub fun main() : <console,fsys,exn,div,random> ()
  write-sir-report()
  println("Example completed.")
