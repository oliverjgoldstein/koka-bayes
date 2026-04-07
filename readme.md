# koka-bayes

> Probabilistic programming in Koka 3.

`koka-bayes` is a Koka v3 library for multimodal, handler-based probabilistic models. Observable sites can either sample or observe depending on the environment supplied at runtime. The model stays the same. The environment changes.

The active implementation lives under `src/`. The older 2019 thesis-era `sample`/`score` prototype is preserved under `legacy/2019/` as historical reference material, not as the current API.

## At A Glance

- Koka `3.x` modeling library for simulation and inference
- typed observable variables and typed model environments
- ordered consumption of repeated observations
- reusable HMM-style and sequential model composition
- current algorithms: `simulate`, `lw`, `lwis`, `mh`, `smc`, `pmmh`, `rmsmc`, `smc2`
- verified with Koka `3.2.2` on the `jsnode` backend

## Quick Start

Requirements:

- a recent `node` runtime for the `jsnode` backend
- Koka `3.x`

`make setup` checks the runtime toolchain, installs the current official Koka 3 release if `koka` is missing, and validates that the installed `node` can execute Koka's generated JavaScript.

```sh
make setup
make compile
make smoke
make run
```

If you want a user-local Koka install instead of the installer default:

```sh
make KOKA_INSTALL_PREFIX=$HOME/.local setup
```

On macOS, if Koka was previously installed with Homebrew, run `brew uninstall koka` before using the official installer.

## Run Something

```sh
make linear-regression
make hmm
make sir-simulate
make sir-infer
make sir-bootstrap
make sir-report
```

`make sir-report` writes:

- `sir-diagnostics-dashboard.svg`
- `sir-diagnostics-summary.csv`
- `sir-diagnostics-samples.csv`

## The Core Idea

One model body can serve both simulation and inference:

```koka
val xs = [-2.0, -1.0, 0.0, 1.0, 2.0]
val model0 = linear-regression-model(xs)

val sim = simulate(empty(), model0)
val observed = set(y-var, sim.value.ys, empty())
val weighted = lw(200, observed, model0)
```

When the environment is empty, observable sites sample. When the environment provides values, those same sites observe. Repeated occurrences consume observations in runtime order.

## Examples

- [Linear regression](./src/examples/linear_regression.kk): one model body used for simulation, likelihood weighting, and likelihood weighting with resampling
- [Hidden Markov model](./src/examples/hmm.kk): simple, modular, and higher-order HMM construction plus `smc` and `rmsmc`
- [SIR model](./src/examples/sir.kk): modular epidemiology model with simulation, `mh`, `smc`, `pmmh`, `rmsmc`, `smc2`, and bootstrap workflows

## Project Map

- `src/core/`: observable values, observable variables, environments, distributions, model API, traces, sequential layer
- `src/handlers/`: environment reading and sample-vs-observe specialization
- `src/alg/`: simulation, weighted inference, MCMC, and particle methods
- `src/examples/`: compact reference models
- `src/run/`: runnable entrypoints
- `src/diagnostics/`: report generation
- `test/`: smoke and invariant checks
- `legacy/2019/`: archived thesis-era implementation

For a full module-by-module mapping, see [ARCHITECTURE_MAPPING.md](./ARCHITECTURE_MAPPING.md).

## Read More

- [Usage guide](./docs/USAGE_GUIDE.md): commands, execution APIs, and environment patterns
- [Architecture mapping](./ARCHITECTURE_MAPPING.md): where each architectural concept lives in the codebase
- [Algorithm coverage](./ALGORITHM_COVERAGE.md): audited algorithm surface and status
- [Design notes](./DESIGN_NOTES.md): Koka-specific tradeoffs, current deviations, and implementation choices
- [Legacy notes](./LEGACY_NOTES.md): what was archived from the 2019 codebase
- [Migration plan](./MIGRATION_PLAN.md): transition notes from the earlier repository shape

## Background

The 2024 arXiv release of the earlier MSc thesis, "Modular probabilistic programming with algebraic effects (MSc Thesis 2019)" (`arXiv:2412.19826`), is useful historical context for the ideas behind the project. The authoritative description of the current implementation is the code in `src/` together with the repository documents linked above.
