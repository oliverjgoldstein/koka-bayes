# Design Notes

User programs start with [model.kk](../../model.kk): one file for the model, data,
inference method, and result printing, with a single `import bayes`. The public
facade is `lib/bayes.kk`; examples are complete programs under `examples/`.
The launcher supplies the library search paths. Paths below are relative to the
project root and describe optional implementation details.

## 1. Native Koka Effects Instead Of A Freer Encoding

Earlier Haskell-style effect encodings use `Prog`, effect sums, and membership proofs because Haskell needs an explicit representation of effectful programs. Koka already has algebraic effects and row polymorphism, so the current design uses native Koka effects directly:

- `obs-reader` for looking up optional observations
- `model-dist` for deferred probabilistic requests
- effect values `sample-hook` and `observe-hook` for algorithm-specific execution

This keeps the semantics of deferred interpretation without importing that extra encoding machinery into Koka.

## 2. Observable Variables And Environments

Some prior descriptions use overloaded labels such as `#x`. Koka v3 does not offer that ergonomic path directly, so observable variables are explicit typed values defined in `lib/core/obsvar.kk`.

Each observable variable carries a codec into the closed runtime `obsvalue` type from `lib/core/obsvalue.kk`. This lets `lib/core/env.kk` store heterogeneous observation lists while keeping typed APIs:

- `empty`
- `set`
- `append`
- `get`
- `maybe-consume`

The environment semantics are:

- repeated occurrences consume values in order
- missing values fall back to sampling
- extra observations are ignored

For sequential algorithms, `lib/core/env.kk` also exposes:

- `focus-step` to project an environment onto one time step
- `take-prefix` to project an environment onto a sequential prefix while preserving singleton global bindings

## 3. The Handler Pipeline

The specialization pipeline is implemented as three Koka modules:

- `lib/handlers/read.kk`
- `lib/handlers/dist.kk`
- `lib/handlers/core.kk`

`handle-read` turns a typed environment into an ordered observation source. `handle-dist` interprets each observable distribution site as either:

- `observe-hook(name, dist, value)` when the environment supplies a value
- `sample-hook(Just(name), dist)` when the environment is exhausted

`handle-core` composes those passes so user models remain reusable across execution modes.

## 4. Distribution Representation

`lib/core/dist.kk` uses a closed runtime representation of primitive distributions with:

- a printable summary
- an output kind
- sampling logic
- log-probability logic

The current primitive layer covers the implementation requirements:

- normal
- uniform
- bernoulli
- discrete
- binomial
- poisson
- gamma
- beta

The public API in `lib/core/model.kk` provides both observable and primed/sample-only forms.

## 5. Tracing And Addressing

The trace layer in `lib/core/trace.kk` records:

- runtime address
- optional observable name
- distribution summary
- sampled or observed value
- log-probability contribution
- sample vs observe mode

The addressing strategy is deliberately simple: addresses are deterministic linear integers assigned in execution order. This is weaker than a richer tree or stack address scheme, but it is stable for deterministic execution structure and easy to reason about in the current Koka implementation.

## 6. Algorithm Runtime Design

The public algorithms are:

- `simulate` in `lib/alg/simulate.kk`
- `lw` in `lib/alg/lw.kk`
- `lwis` in `lib/alg/lwis.kk`
- `mh` in `lib/alg/mh.kk`
- `smc` in `lib/alg/smc.kk`
- `pmmh` in `lib/alg/pmmh.kk`
- `rmsmc` in `lib/alg/rmsmc.kk`
- `smc2` in `lib/alg/smc2.kk`

The particle family is organized around two extra layers:

- `lib/core/sequential.kk` for step-wise models
- `lib/alg/mcmc.kk` for shared MH-chain logic

The intended design was to thread all runtime state through local handlers, but Koka v3’s current interaction between local mutable state, closures, and the algorithm-specific effect rows made that route fragile for this repository. The current implementation therefore uses:

- effect values to connect the specialization pipeline to the active algorithm
- references allocated separately for each execution's runtime trace state

The hooks still encapsulate mutation with `unsafe-total`, but executions no longer share module-level trace counters or weights. Nested LW and simulation are covered by regression tests.

The current MH proposal kernel also incorporates a thesis-derived replay refinement from the archived Bristol implementation: once a proposal address is selected, the run reuses only the trace prefix before that address and regenerates the suffix. This avoids stale downstream reuse when later distributions depend on the proposed value.

The particle algorithms follow the same modular intent:

- `SMC` uses `run-lw` at each sequential step plus multinomial resampling.
- `PMMH` wraps an inner `SMC` likelihood estimate with an independent-prior MH chain over parameters.
- `RMSMC` extends `SMC` by rejuvenating resampled particles with prefix-model MH moves.
- `SMC2` maintains outer parameter particles and retained inner `SMC` states. Each observation extends the same inner population; a PMMH move replaces that population only on acceptance.

## 7. Example Design

The examples emphasize the main library claims:

- `examples/linear_regression.kk` shows one model reused for simulation and LW
- `examples/hmm.kk` shows ordered repeated observations, reusable submodels, a higher-order HMM builder, and sequential particle algorithms
- `examples/sir.kk` shows a modular epidemic HMM with simulation, MH inference, PMMH, and SMC2

The synthetic recovery path simulates SIR data and feeds the resulting reports back as observations for PMMH. The historical bootstrap-named helper does synthetic recovery; it does not implement Rubin's Bayesian bootstrap with Dirichlet-reweighted observations.

## 8. Deliberate Deviations

- No overloaded observable labels: explicit typed observable constructors are used instead.
- No type-level record environment encoding: runtime codecs provide the heterogeneity boundary.
- Linear address generation instead of structured site addresses.
- Lightweight single-site MH replay proposal instead of a richer trace-database design.
- `SMC2` uses immutable retained inner filters, with fresh full-prefix filters only for rejuvenation proposals.
- `jsnode` is the documented backend for this repository.

These deviations were chosen to preserve semantics, type clarity, and Koka v3 ergonomics in that order.

## 9. Source Priority

This repository uses the following source priority:

1. the current `lib/`, `examples/`, and `tests/` trees and repository documentation for the active implementation
2. the 2024 arXiv release of the 2019 MSc thesis (`arXiv:2412.19826`) for supplementary implementation ideas
3. the archived 2019 repository only as archaeological context

The thesis is useful when it adds detail about modular inference components or historical algorithm structure, but it must not pull the current codebase back toward the earlier explicit `sample`/`score`-centric design when that conflicts with the active multimodal model architecture.
