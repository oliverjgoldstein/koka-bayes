# Usage Guide

## Quick Start

```sh
make setup
make compile
make smoke
make run
```

`make setup` ensures `koka` is available, installing the current official Koka 3 release when it is missing, and validates that the installed `node` can run the generated `jsnode` output. To install into a user-local prefix instead of the installer default, run `make KOKA_INSTALL_PREFIX=$HOME/.local setup`.

Run individual demos:

```sh
make linear-regression
make hmm
make sir-simulate
make sir-infer
make sir-bootstrap
make sir-report
```

## Core Execution APIs

- `simulate(env, model)` returns `simulate-result` with:
  - `value`
  - `trace`
  - `output-env`
- `lw(iterations, env, model)` returns `list<weighted-sample<a>>`
- `lwis(iterations, env, model)` returns `list<a>` by resampling the `lw` output empirically
- `mh(iterations, burnin, env, model)` returns `mh-result` with:
  - `samples`
  - `accepted`
  - `posterior-env`
- `smc(particles, steps, env, sequential-model)` returns `smc-result` with:
  - `particles`
  - `log-evidence`
  - `posterior-env`
- `pmmh(particles, steps, config, env, sequential-model)` returns `pmmh-result`
- `pmmh-with(...)` additionally accepts a parameter prior-score function and a custom parameter proposal kernel
- `rmsmc(particles, steps, mh-steps, env, sequential-model)` returns `smc-result`
- `smc2(outer, inner, steps, rejuvenation-steps, env, sequential-model)` returns `smc2-result`
- `smc2-with(...)` additionally accepts a parameter prior-score function and a custom rejuvenation kernel

## Model Environment Pattern

Use the same model body for simulation and inference:

```koka
val xs = [-2.0, -1.0, 0.0, 1.0, 2.0]
val model0 = linear-regression-model(xs)
val sim = simulate(empty(), model0)
val observed = set(y-var, sim.value.ys, empty())
val weighted = lw(200, observed, model0)
```

The environment controls when an observable site becomes an observation instead of a sample.

## Ordered Observation Consumption

Repeated occurrences of the same observable variable consume supplied values in runtime order. This is demonstrated in `src/examples/hmm.kk` and verified in `test/smoke.kk`.

## Higher-Order Model Reuse

`src/examples/hmm.kk` exposes a generic `higher-order-hmm` builder and a `higher-order-sequential` builder that first run parameter priors and then reuse transition and observation submodels. `src/examples/sir.kk` builds the SIR model through that same sequential higher-order pattern.

## Sequential Models

Particle algorithms operate on `src/core/sequential.kk`:

- `as-model(steps, spec)` turns a sequential model back into a regular multimodal model
- `focus-step` projects an environment onto one sequential step
- `take-prefix` projects an environment onto a sequential prefix while preserving singleton global bindings

## Diagnostics And Graphs

`make sir-report` runs a synthetic SIR recovery benchmark across `SMC`, `RMSMC`, `PMMH`, and `SMC2`.

It writes:

- `sir-diagnostics-dashboard.svg`
- `sir-diagnostics-summary.csv`
- `sir-diagnostics-samples.csv`

The SVG dashboard is generated directly from Koka and overlays the synthetic truth against the recovered posterior histograms. Each panel is marked `PASS` or `FAIL` using the benchmark tolerances in `src/diagnostics/sir_report.kk`.
