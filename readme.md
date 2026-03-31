# koka-bayes

`koka-bayes` is now a Koka v3 probabilistic programming library for multimodal, handler-based probabilistic models, rather than the 2019 thesis-era `sample`/`score` prototype that originally lived in this repository.

The 2024 arXiv release of the earlier MSc thesis, “Modular probabilistic programming with algebraic effects (MSc Thesis 2019)” (`arXiv:2412.19826`), is treated here as a Bristol reference for extra algorithmic detail and historical implementation context. The authoritative description of the active implementation is the current `src/` tree plus the repository documentation.

One concrete thesis-derived refinement in the current code is the Metropolis-Hastings replay strategy: proposals now reuse the trace prefix up to the proposal address and regenerate the suffix afterwards, following the old replay/perturb-trace intuition without changing the public model API.

The implementation targets Koka `3.2.2` and uses the `jsnode` backend for the documented commands below.

## What Changed From 2019

The old repository centered on explicit `sample` and `score` effects plus thesis-era algorithms such as SMC, TMCMC, RMSMC, and PMMH. The new implementation replaces that design with:

- multimodal models whose observable sites can either sample or observe
- typed observable variables and typed model environments
- a handler pipeline that specializes models by environment
- first-class model composition for HMM-style reuse
- a sequential model layer for population algorithms
- current execution modes: `simulate`, `lw`, `lwis`, `mh`, `smc`, `pmmh`, `rmsmc`, and `smc2`

The thesis-era code has been archived under `legacy/2019/` and is no longer the current API surface.

## Core Ideas

- Observable variables are explicit typed values such as `obs-float64("sir/beta")`.
- Model environments map observable variables to ordered lists of observations.
- Repeated occurrences consume observations in runtime order; missing values fall back to sampling and extra values are ignored.
- Model definitions stay unchanged across simulation and inference. Only the environment changes.
- Specialization is factored into handlers:
  - `handle-read` reads ordered observations from the environment
  - `handle-dist` interprets an observable distribution site as either sample or observe
  - `handle-core` composes both passes

## Architecture

- `src/core/obsvalue.kk`: runtime observable values plus codecs
- `src/core/obsvar.kk`: typed observable variable identifiers
- `src/core/env.kk`: typed model environments with ordered consumption
- `src/core/dist.kk`: primitive distributions and log-density logic
- `src/core/model.kk`: multimodal model API and probabilistic operations
- `src/core/trace.kk`: sample and observation traces, output environments
- `src/core/sequential.kk`: sequential model layer for step-wise latent-state models
- `src/handlers/read.kk`: environment reader handler
- `src/handlers/dist.kk`: deferred sample/observe interpretation
- `src/handlers/core.kk`: specialization pipeline
- `src/alg/mcmc.kk`: generic Metropolis-Hastings wrappers
- `src/alg/simulate.kk`: simulation
- `src/alg/lw.kk`: likelihood weighting
- `src/alg/lwis.kk`: likelihood weighting with resampling
- `src/alg/mh.kk`: trace-based Metropolis Hastings
- `src/alg/smc.kk`: sequential Monte Carlo over reusable sequential models
- `src/alg/pmmh.kk`: particle marginal Metropolis-Hastings
- `src/alg/rmsmc.kk`: resample-move sequential Monte Carlo
- `src/alg/smc2.kk`: nested SMC over parameter particles with inner filters
- `src/examples/linear_regression.kk`: simulation, LW, and LWIS
- `src/examples/hmm.kk`: simple, modular, higher-order, SMC, and RMSMC HMM demos
- `src/examples/sir.kk`: modular SIR model with simulation, MH, SMC, PMMH, SMC2, and bootstrap demos
- `src/diagnostics/sir_report.kk`: synthetic SIR recovery benchmark with SVG and CSV output
- `src/run/*.kk`: runnable entrypoints
- `test/smoke.kk`: smoke and invariant checks

## Build And Run

Requirements:

- `koka` `3.2.x`
- Node.js for the `jsnode` backend

Convenience targets:

```sh
make compile
make smoke
make run
make linear-regression
make hmm
make sir-simulate
make sir-infer
make sir-bootstrap
make sir-report
```

Equivalent direct Koka commands:

```sh
koka --target=jsnode --library --include=src -c src/main.kk
koka --target=jsnode -e --include=src --include=test test/smoke.kk
koka --target=jsnode -e --include=src src/main.kk
koka --target=jsnode -e --include=src src/run/linear_regression.kk
koka --target=jsnode -e --include=src src/run/hmm.kk
koka --target=jsnode -e --include=src src/run/sir_simulate.kk
koka --target=jsnode -e --include=src src/run/sir_infer.kk
koka --target=jsnode -e --include=src src/run/sir_bootstrap.kk
koka --target=jsnode -e --include=src src/run/sir_report.kk
```

## Example Walkthroughs

### Linear Regression

`src/examples/linear_regression.kk` defines the current linear regression example with priors `Normal(0,3)`, `Normal(0,2)`, `Uniform(1,3)` over slope, intercept, and `sigma`. The same `linear-regression-model(xs)` is used for:

- pure simulation with `simulate(empty(), ...)`
- likelihood weighting by supplying `y-var` observations through an environment
- likelihood weighting with resampling through `lwis(...)`

### Hidden Markov Model

`src/examples/hmm.kk` contains:

- a simple HMM
- a `node` combinator
- reusable transition and observation prior models
- reusable transition and observation submodels
- a higher-order `higher-order-hmm` builder that first samples submodel parameters and then runs the chain

The observed-mode and higher-order demos show that repeated occurrences of `emission-var` consume supplied values in order while the same HMM definition can also fix higher-level parameters through the environment.

The same sequential HMM specification also drives:

- `smc-demo()` for particle filtering
- `rmsmc-demo()` for resample-move particle filtering

### SIR Model

`src/examples/sir.kk` implements the modular SIR hidden Markov model with gamma priors for `beta` and `gamma`, a beta prior for the reporting rate, and a higher-order HMM composition over transition and observation submodels. The demo surface includes:

- `simulate-demo()` for forward simulation
- `inference-demo()` for Metropolis Hastings
- `smc-demo()` for sequential Monte Carlo
- `pmmh-demo()` for particle marginal Metropolis-Hastings
- `smc2-demo()` for nested parameter-particle inference
- `bootstrap-demo()` for synthetic-data bootstrap inference

`make sir-report` runs a fixed synthetic-data recovery benchmark for `SMC`, `RMSMC`, `PMMH`, and `SMC2` and writes:

- `sir-diagnostics-dashboard.svg`
- `sir-diagnostics-summary.csv`
- `sir-diagnostics-samples.csv`

The SVG dashboard shows posterior histograms with the synthetic truth overlaid and marks each algorithm `PASS` or `FAIL` against the configured recovery tolerances.

## Coverage

This repository implements the main programming model and execution story across:

- modular multimodal examples
- effect-based multimodal embedding
- specialization by model environment
- simulation, likelihood weighting, likelihood weighting with resampling, Metropolis Hastings, sequential Monte Carlo, particle marginal Metropolis-Hastings, resample-move SMC, and SMC2

See [ARCHITECTURE_MAPPING.md](./ARCHITECTURE_MAPPING.md) for the module-by-module correspondence and [ALGORITHM_COVERAGE.md](./ALGORITHM_COVERAGE.md) for the audited algorithm set.

## Known Deviations

- Koka does not provide overloaded `#x`-style labels, so observable variables use explicit typed constructors.
- Model environments use runtime codecs rather than Haskell type-level records.
- The runtime specialization layer uses Koka effect values (`sample-hook`, `observe-hook`) to bridge from the specialization handlers into the concrete algorithms.
- The current MH implementation uses deterministic linear site addresses and a lightweight single-site replay proposal with suffix regeneration.
- `SMC2` currently recomputes inner prefix filters when extending parameter particles instead of maintaining a mutable nested filter state.
- The verified build target in this repository is `jsnode`; the C backend was not used for the documented workflow in this environment.

These choices preserve the current modeling semantics and document the Koka-specific tradeoffs explicitly in [DESIGN_NOTES.md](./DESIGN_NOTES.md).

## Legacy

All thesis-era code, datasets, and climate artifacts were moved to `legacy/2019/`. The archive is documented in [LEGACY_NOTES.md](./LEGACY_NOTES.md).
