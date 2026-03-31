module diagnostics/sir_report

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
  beta-mean     : float64
  report-mean   : float64
  beta-error    : float64
  report-error  : float64
  success       : bool
  note          : string

pub fun write-sir-report(output-prefix : string = "sir-diagnostics") : <console,fsys,exn,div,random> ()
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
  write-text-file(dashboard-path, render-dashboard(problem, reports), False)
  write-text-file(summary-path, render-summary-csv(problem, reports), False)
  write-text-file(samples-path, render-samples-csv(reports), False)
  println("SIR particle diagnostics")
  println("  reports = [" ++ problem.observed-reports.map(fn(x){ x.show }).join(", ") ++ "]")
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

fun run-smc-report(problem : sir-problem) : <div,random> algorithm-report
  val result = pseudo-random(223, fn(){ smc(96, problem.days, problem.inference-env, sir-sequential()) })
  make-report("SMC",
              get(beta-var, result.posterior-env),
              get(report-rate-var, result.posterior-env),
              problem.truth,
              "particles=" ++ result.particles.length.show ++ ", logZ=" ++ short-float64(result.log-evidence))

fun run-rmsmc-report(problem : sir-problem) : <div,random> algorithm-report
  val result = pseudo-random(227, fn(){ rmsmc(64, problem.days, 2, problem.inference-env, sir-sequential()) })
  make-report("RMSMC",
              get(beta-var, result.posterior-env),
              get(report-rate-var, result.posterior-env),
              problem.truth,
              "particles=" ++ result.particles.length.show ++ ", logZ=" ++ short-float64(result.log-evidence))

fun run-pmmh-report(problem : sir-problem) : <div,random> algorithm-report
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

fun run-smc2-report(problem : sir-problem) : <div,random> algorithm-report
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
                note : string) : algorithm-report
  val beta-mean = mean(beta-samples)
  val report-mean = mean(report-samples)
  val beta-error = abs(beta-mean - truth.beta)
  val report-error = abs(report-mean - truth.report-rate)
  val success = beta-error <= 0.18 && report-error <= 0.12
  Algorithm-report(name,
                   beta-samples,
                   report-samples,
                   beta-mean,
                   report-mean,
                   beta-error,
                   report-error,
                   success,
                   note)

fun render-dashboard(problem : sir-problem, reports : list<algorithm-report>) : <div> string
  val beta-range = sample-range(reports.flatmap(fn(report){ report.beta-samples }), problem.truth.beta)
  val rate-range = sample-range(reports.flatmap(fn(report){ report.report-samples }), problem.truth.report-rate)
  val width = 1320
  val height = 860
  val header =
    "<text x='40' y='46' font-family='Menlo, monospace' font-size='28' font-weight='700' fill='#18222c'>SIR Inference Diagnostics</text>" ++
    "<text x='40' y='76' font-family='Menlo, monospace' font-size='14' fill='#405060'>Synthetic truth: beta=" ++ short-float64(problem.truth.beta) ++
    ", gamma=" ++ short-float64(problem.truth.gamma-rate) ++
    ", report-rate=" ++ short-float64(problem.truth.report-rate) ++
    " | days=" ++ problem.days.show ++ "</text>" ++
    "<text x='40' y='102' font-family='Menlo, monospace' font-size='12' fill='#5f6b76'>Observed reports: [" ++ problem.observed-reports.map(fn(x){ x.show }).join(", ") ++ "]</text>"
  val beta-panels = render-panels(reports, "beta", problem.truth.beta, beta-range, 40, 140, "#0f766e", fn(report){ report.beta-samples }, fn(report){ report.beta-mean }, fn(report){ report.beta-error })
  val rate-panels = render-panels(reports, "report-rate", problem.truth.report-rate, rate-range, 40, 460, "#9a3412", fn(report){ report.report-samples }, fn(report){ report.report-mean }, fn(report){ report.report-error })
  val legend =
    "<text x='40' y='820' font-family='Menlo, monospace' font-size='12' fill='#5f6b76'>Red line = truth, black line = posterior mean, green panel = within tolerance, red panel = outside tolerance.</text>"
  svg(width, height, header ++ beta-panels ++ rate-panels ++ legend)

fun render-panels(reports : list<algorithm-report>,
                  parameter : string,
                  truth : float64,
                  range : (float64,float64),
                  x0 : int,
                  y0 : int,
                  color : string,
                  select-samples : algorithm-report -> list<float64>,
                  select-mean : algorithm-report -> float64,
                  select-error : algorithm-report -> float64) : <div> string
  render-panels-at(reports, parameter, truth, range, x0, y0, color, select-samples, select-mean, select-error, 0)

fun render-panels-at(reports : list<algorithm-report>,
                     parameter : string,
                     truth : float64,
                     range : (float64,float64),
                     x0 : int,
                     y0 : int,
                     color : string,
                     select-samples : algorithm-report -> list<float64>,
                     select-mean : algorithm-report -> float64,
                     select-error : algorithm-report -> float64,
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
                             260,
                             color,
                             select-samples(report),
                             select-mean(report),
                             select-error(report)) ++
      render-panels-at(rest, parameter, truth, range, x0, y0, color, select-samples, select-mean, select-error, index + 1)

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
                           sample-mean : float64,
                           sample-error : float64) : <div> string
  val background = if report.success then "#ecfdf5" else "#fef2f2"
  val border = if report.success then "#16a34a" else "#dc2626"
  val plot-x = x + 18
  val plot-y = y + 70
  val plot-width = width - 36
  val plot-height = height - 110
  val bins = histogram(samples, 14, fst(range), snd(range))
  val max-bin = max-int(bins, 1)
  val bars = render-bars(bins, plot-x, plot-y, plot-width, plot-height, max-bin, color, bins.length, 0)
  val truth-line = render-marker(truth, fst(range), snd(range), plot-x, plot-y, plot-width, plot-height, "#dc2626", "4,4")
  val mean-line = render-marker(sample-mean, fst(range), snd(range), plot-x, plot-y, plot-width, plot-height, "#111827", "none")
  rect(x, y, width, height, background, border, 2) ++
  text(x + 14, y + 26, report.name ++ " · " ++ parameter, 18, "#18222c", True) ++
  text(x + 14, y + 48, report.note, 12, "#4b5563") ++
  text(x + 14, y + height - 26, "mean=" ++ short-float64(sample-mean) ++ ", err=" ++ short-float64(sample-error), 12, "#374151") ++
  text(x + width - 84, y + height - 26, if report.success then "PASS" else "FAIL", 12, border, True) ++
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
  "algorithm,beta_truth,beta_mean,beta_error,report_truth,report_mean,report_error,success,note\n" ++
  reports.map(fn(report){
    report.name ++ "," ++
    short-float64(problem.truth.beta) ++ "," ++
    short-float64(report.beta-mean) ++ "," ++
    short-float64(report.beta-error) ++ "," ++
    short-float64(problem.truth.report-rate) ++ "," ++
    short-float64(report.report-mean) ++ "," ++
    short-float64(report.report-error) ++ "," ++
    (if report.success then "true" else "false") ++ "," ++
    quote-csv(report.note)
  }).join("\n") ++ "\n"

fun render-samples-csv(reports : list<algorithm-report>) : string
  "algorithm,parameter,value\n" ++ reports.flatmap(render-sample-lines).join("\n") ++ "\n"

fun render-sample-lines(report : algorithm-report) : list<string>
  report.beta-samples.map(fn(value){ report.name ++ ",beta," ++ short-float64(value) }) ++
  report.report-samples.map(fn(value){ report.name ++ ",report-rate," ++ short-float64(value) })

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

fun mean(values : list<float64>) : float64
  match values
    Nil -> 0.0
    _   -> values.sum / float64(values.length)

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

fun print-reports(reports : list<algorithm-report>) : console ()
  match reports
    Nil -> ()
    Cons(report, rest) ->
      println("  " ++ report.name ++
              ": beta mean=" ++ short-float64(report.beta-mean) ++
              " (err " ++ short-float64(report.beta-error) ++ ")" ++
              ", report mean=" ++ short-float64(report.report-mean) ++
              " (err " ++ short-float64(report.report-error) ++ ")" ++
              ", " ++ (if report.success then "PASS" else "FAIL"))
      print-reports(rest)
