[Docs](../README.md) · [Get started](../USAGE_GUIDE.md)

# Algorithm Coverage

Start with [model.kk](../../model.kk) and `import bayes`. This optional reference
records the underlying algorithms and the evidence for them. Paths below are
relative to the project root.

## Implemented Algorithms and Verification Scope

The repository implements these public inference algorithms. Execution tests and analytic benchmarks establish different, bounded kinds of evidence; neither proves arbitrary-model correctness.

- `simulate` in `lib/alg/simulate.kk`
- `enumerate` in `lib/alg/enumerate.kk`: finite execution-tree enumeration using continuation handlers
- `lw` in `lib/alg/lw.kk`
- `lwis` in `lib/alg/lwis.kk`
- `mh` in `lib/alg/mh.kk`
- `smc` in `lib/alg/smc.kk`
- `smc-model` in `lib/alg/handler_smc.kk`: checkpoint-based SMC over ordinary model code
- `pmmh` in `lib/alg/pmmh.kk`
- `rmsmc` in `lib/alg/rmsmc.kk`
- `smc2` in `lib/alg/smc2.kk`
- `hmc` in `lib/alg/hmc.kk`
- `mala` in `lib/alg/mala.kk`
- generic `mh-chain` wrappers in `lib/alg/mcmc.kk`

These are exercised by:

- `./bayes smoke`
- `make inference MODEL=examples/linear_regression.kk`
- `make inference MODEL=examples/hmm.kk`
- `make inference MODEL=examples/sir.kk`
- `make tests`: regression, analytic inference, and differentiation checks
- `make test-inference-audit`: exact joint posteriors, asymmetric kernels, rejection and particle evidence
- `make test-inference`: the original 30 runs plus six correlated Gaussian gradient-sampler runs
- `make test-lw`, `test-lwis`, `test-mh`, `test-smc`, `test-rmsmc`, `test-pmmh`, `test-smc2`, `test-hmc`, `test-mala`: individual algorithm checks
- `make examples`: thermometer demonstrations for the sampling algorithms and three finite enumeration examples
- `make test-enumerate`: finite-support distributions, exact posteriors and evidence, continuous observations, branch isolation, nested inference and budget/error behavior
- `./bayes differentiable-model`: analytic joint densities and gradients, observation handling, and seeded equivalence of model interpretations
- `make test-handlers`: multi-shot isolation, scoring laws, observation streams, checkpoint populations, exact joint posteriors and rejected-state retention
- `make demo-handlers`: one checkpointed thermometer model interpreted by SMC or LW
- `make test-examples`: three models per method and three seeds per model, with 90 posterior checks and nine prior-simulation checks

The [benchmark protocol](../BENCHMARKS.md) defines exact targets, tolerances, and measured results. The [assessment](../ASSESSMENT.md) records the correctness defects found and repaired. Scalar AD has its own [scope and tests](../AUTODIFF.md).

The [multi-model matrix](../MULTI_MODEL_VALIDATION.md) adds continuous,
categorical, sequential and non-Gaussian examples for every sampling method,
including checkpoint SMC, using analytic, enumerated or quadrature references.

[Finite enumeration](../EXACT_INFERENCE.md) has separate deterministic checks
against independent arithmetic and density formulas. It handles finite latent
choices with observed likelihoods and factors; it does not integrate continuous
latent variables or perform symbolic simplification.

[Gradient inference](../GRADIENT_INFERENCE.md) documents fixed-step, unit-mass
HMC and MALA, including proposal corrections, continuous-target assumptions,
and the Normal-model adapter. They do not implement NUTS or adaptive tuning.

The [handler guide](../HANDLER_COMPOSITION.md) describes reusable inference
handlers, the repaired multi-shot and singleton-reader failures, and the
composition laws and exact finite models used to check the refactor.

The smoke suite checks:

- ordered observation consumption
- missing-observation fallback to sampling
- extra-observation ignore semantics
- deterministic addressing under fixed execution structure
- finite likelihood-weighting output
- replay-style MH suffix regeneration
- HMM SMC particle execution
- HMM resample-move SMC execution
- SIR PMMH execution
- SIR SMC2 execution

## External Audit Against `monad-bayes`

The [source-level comparison](../MONAD_BAYES_COMPARISON.md) is pinned to an
upstream revision and compares handler responsibilities and algorithm
composition, beyond the list of supported methods below.

The current `monad-bayes` inference surface includes at least:

- lazy `MH`
- lazy `WIS`
- `MCMC`
- `PMMH`
- `RMSMC`
- `SMC`
- `SMC2`

Reference:

- Hackage package index: <https://hackage.haskell.org/package/monad-bayes>

Current status in this repository:

- `MH`: implemented as `lib/alg/mh.kk`
- `WIS`: implemented in resampling form as `lib/alg/lwis.kk`
- `SMC`: implemented as `lib/alg/smc.kk`
- `PMMH`: implemented as `lib/alg/pmmh.kk`
- `RMSMC`: implemented as `lib/alg/rmsmc.kk`
- `SMC2`: implemented as `lib/alg/smc2.kk`
- generic `MCMC` wrappers: implemented in `lib/alg/mcmc.kk`

## Sequential Layer And Coverage Notes

The particle family now sits on top of an explicit sequential model layer:

- a step-wise model boundary
- resampling over populations
- trace/state propagation across sequential time
- a reusable sequential API independent of any one example

Ordinary model code can alternatively use explicit `checkpoint()` operations
with `smc-model`. The `handlers/sequential` and `handlers/population` modules
provide suspension, continuation resampling and incremental evidence accounting;
`examples/compositional_inference.kk` demonstrates this route.

That layer is implemented in `lib/core/sequential.kk` and used directly by:

- `examples/hmm.kk`
- `examples/sir.kk`

## Deliberate Simplifications

- `SMC` has both an explicit sequential-model driver and a checkpointed-model driver; both use shared weight and population operations with multinomial resampling.
- `PMMH` uses an independent-prior proposal over parameter particles with an inner `SMC` likelihood estimate.
- `RMSMC` rejuvenates resampled particles with independent-prior MH over prefix models instead of a deeper traced-transformer port.
- `SMC2` maintains outer parameter particles and retained inner `SMC` populations. Rejuvenation proposals recompute a candidate prefix filter; rejected proposals preserve the existing filter.

## Recommended Next Step

If the goal is to move closer to the broader optimized `monad-bayes` implementation style, the next implementation step should be:

1. replace the current multinomial-only resampling with configurable resamplers
2. add ESS-based resampling and inner-particle adaptation in `SMC2`
3. add more proposal kernels beyond the current independent-prior and single-site replay moves
