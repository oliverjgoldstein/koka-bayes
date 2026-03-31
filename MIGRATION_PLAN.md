# Koka Bayes Migration Plan

## Status

The migration plan is now implemented for the Koka v3 `jsnode` workflow in this repository.

Completed:

- Koka v3 baseline and module reorganization under `src/`
- multimodal model core for the current Koka v3 architecture
- ordered typed model environments
- specialization handlers
- `simulate`, `lw`, and `mh`
- linear regression, HMM, higher-order modular HMM structure, and SIR examples
- smoke verification
- archival move of thesis-era code into `legacy/2019/`

Remaining follow-up work is incremental rather than architectural:

- richer MH proposal mechanisms
- more statistical summaries in demos
- possible future cleanup of algorithm runtime state if Koka handler ergonomics improve

## Audit Summary

The repository currently contains a 2019 thesis-era prototype built around explicit `sample` and `score` effects, plus older inference algorithms (`smc`, `tmcmc`, `pmmh`, `rmsmc`). The code is flat at the repository root, uses pre-v3 Koka syntax such as `public module`, imports deprecated numeric modules like `std/num/double`, and does not compile on Koka `3.2.2`.

The present source tree is dominated by:

- thesis-era core modules: `effects-and-types.kk`, `handlers.kk`, `sampling.kk`
- older algorithms: `smc.kk`, `tmcmc.kk`, `pmmh.kk`, `rmsmc.kk`, `sampling-rmsmc.kk`
- old examples: `climate-change.kk`, `climate-experiments.kk`, `benchmark.kk`
- historical utilities/artifacts: `output-and-plot.kk`, `plot_figures.py`, `output-climate/`, `data/`
- incomplete documentation: `readme.md`

## Keep, Rewrite, Archive

### Keep and adapt

- old distribution math snippets where still correct in spirit:
  - gamma/log-gamma style utilities from `model-resources.kk`
- general repository metadata and basic shell entrypoints where useful:
  - `Makefile` will be rewritten, not preserved verbatim

### Rewrite completely

- all current modeling abstractions based on `() -> <sample,score|e> a`
- all effect declarations and handlers
- the top-level entrypoint
- all current examples as first-class multimodal models
- README and project docs

### Archive to `legacy/2019/`

- `effects-and-types.kk`
- `handlers.kk`
- `sampling.kk`
- `smc.kk`
- `tmcmc.kk`
- `pmmh.kk`
- `rmsmc.kk`
- `sampling-rmsmc.kk`
- `climate-change.kk`
- `climate-experiments.kk`
- `benchmark.kk`
- `old-monad-bayes-timing-experiments.kk`
- `output-and-plot.kk`
- `model-resources.kk`
- `exn-get.kk`
- `exponents.kk`
- `main.kk`
- thesis-era datasets and output artifacts under `data/`, `output-climate/`, and related images
- `sent_bugs/` historical notes

## Target Module Structure

The new implementation is organized under `src/`:

- `src/core/obsvalue.kk`
- `src/core/obsvar.kk`
- `src/core/env.kk`
- `src/core/dist.kk`
- `src/core/model.kk`
- `src/core/trace.kk`
- `src/handlers/read.kk`
- `src/handlers/dist.kk`
- `src/handlers/core.kk`
- `src/alg/simulate.kk`
- `src/alg/lw.kk`
- `src/alg/mh.kk`
- `src/examples/linear_regression.kk`
- `src/examples/hmm.kk`
- `src/examples/sir.kk`
- `src/run/linear_regression.kk`
- `src/run/hmm.kk`
- `src/run/sir_simulate.kk`
- `src/run/sir_infer.kk`
- `src/main.kk`

Documentation targets:

- `README.md`
- `ARCHITECTURE_MAPPING.md`
- `DESIGN_NOTES.md`
- `LEGACY_NOTES.md`
- `docs/USAGE_GUIDE.md`

Verification targets:

- `test/smoke.kk`

## Design Direction

The source of truth is the current repository architecture, not the old thesis code. The Koka port therefore uses native Koka v3 effects and handlers instead of transliterating older encoding strategies.

The core design is:

1. model code emits multimodal distribution requests plus observable-variable reads
2. `handle-read` consumes ordered observations from model environments
3. `handle-dist` turns multimodal requests into explicit `sample` or `observe`
4. execution algorithms interpret those core operations compositionally

Typed model environments will be implemented with typed observable identifiers carrying codecs into a closed runtime observable-value representation. This is a deliberate Koka-native substitute for heavier type-level environment encodings.

## Koka v3 Risks and Unknowns

- current Koka v3 supports modern handler syntax, but the exact ergonomics around polymorphic effect operations need compiler-driven validation during implementation
- Koka does not offer Haskell-style overloaded labels, so observable variables will use explicit typed constructors instead of `#x`
- heterogeneous typed environments will be represented with typed wrappers plus runtime codecs rather than promoted type-level records
- current stdlib map support is minimal, so the implementation will prefer lists/vectors where practical
- MH address stability will use deterministic linear execution addresses rather than a richer stack-address scheme unless Koka ergonomics justify extra machinery

## Implementation Order

1. establish Koka v3 buildable baseline and real docs
2. implement runtime observable values and typed observable variables
3. implement model environments with ordered observation consumption
4. implement primitive distributions and log-probability math
5. implement model-level effects and the `handle-read` / `handle-dist` / `handle-core` pipeline
6. implement trace structures and compositional runtime helpers
7. implement `simulate`
8. implement `lw`
9. implement `mh`
10. port required examples:
   - linear regression
   - HMM
   - modular and higher-order HMM
   - SIR
   - Bayesian bootstrapping demo
11. archive thesis-era code into `legacy/2019/`
12. add smoke verification and final documentation

## Success Criteria

- compiles on Koka `3.2.2`
- multimodal models reusable across simulation and inference
- typed observable variables and ordered environment consumption
- first-class model composition
- `simulate`, `lw`, and `mh` available as public APIs
- required examples runnable via documented commands
