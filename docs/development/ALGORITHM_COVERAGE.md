# Algorithm Coverage

Start with [model.kk](../../model.kk) and `import bayes`. This optional reference
records the underlying algorithms and the evidence for them. Paths below are
relative to the project root.

## Implemented Algorithms and Verification Scope

The repository implements these public inference algorithms. Execution tests and analytic benchmarks establish different, bounded kinds of evidence; neither proves arbitrary-model correctness.

- `simulate` in `lib/alg/simulate.kk`
- `lw` in `lib/alg/lw.kk`
- `lwis` in `lib/alg/lwis.kk`
- `mh` in `lib/alg/mh.kk`
- `smc` in `lib/alg/smc.kk`
- `pmmh` in `lib/alg/pmmh.kk`
- `rmsmc` in `lib/alg/rmsmc.kk`
- `smc2` in `lib/alg/smc2.kk`
- generic `mh-chain` wrappers in `lib/alg/mcmc.kk`

These are exercised by:

- `./bayes smoke`
- `make inference MODEL=examples/linear_regression.kk`
- `make inference MODEL=examples/hmm.kk`
- `make inference MODEL=examples/sir.kk`
- `make tests`: regression, analytic inference, and differentiation checks
- `make test-inference-audit`: exact joint posteriors, asymmetric kernels, rejection and particle evidence
- `make test-inference`: four elementary models assigned to suitable algorithms, 30 runs across three seeds
- `make test-lw`, `test-lwis`, `test-mh`, `test-smc`, `test-rmsmc`, `test-pmmh`, `test-smc2`: individual algorithm checks

The [benchmark protocol](../BENCHMARKS.md) defines exact targets, tolerances, and measured results. The [assessment](../ASSESSMENT.md) records the correctness defects found and repaired. Scalar AD has its own [scope and tests](../AUTODIFF.md).

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

That layer is implemented in `lib/core/sequential.kk` and used directly by:

- `examples/hmm.kk`
- `examples/sir.kk`

## Deliberate Simplifications

- `SMC` is implemented directly over sequential models using `lw` at each step and multinomial resampling.
- `PMMH` uses an independent-prior proposal over parameter particles with an inner `SMC` likelihood estimate.
- `RMSMC` rejuvenates resampled particles with independent-prior MH over prefix models instead of a deeper traced-transformer port.
- `SMC2` maintains outer parameter particles and retained inner `SMC` populations. Rejuvenation proposals recompute a candidate prefix filter; rejected proposals preserve the existing filter.

## Recommended Next Step

If the goal is to move closer to the broader optimized `monad-bayes` implementation style, the next implementation step should be:

1. replace the current multinomial-only resampling with configurable resamplers
2. add ESS-based resampling and inner-particle adaptation in `SMC2`
3. add more proposal kernels beyond the current independent-prior and single-site replay moves
