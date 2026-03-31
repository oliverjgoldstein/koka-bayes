# Algorithm Coverage

## Verified Current Algorithms

The current repository implements and verifies these public inference algorithms:

- `simulate` in `src/alg/simulate.kk`
- `lw` in `src/alg/lw.kk`
- `lwis` in `src/alg/lwis.kk`
- `mh` in `src/alg/mh.kk`
- `smc` in `src/alg/smc.kk`
- `pmmh` in `src/alg/pmmh.kk`
- `rmsmc` in `src/alg/rmsmc.kk`
- `smc2` in `src/alg/smc2.kk`
- generic `mh-chain` wrappers in `src/alg/mcmc.kk`

These are exercised by:

- `make smoke`
- `make linear-regression`
- `make hmm`
- `make sir-infer`

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

- `MH`: implemented as `src/alg/mh.kk`
- `WIS`: implemented in resampling form as `src/alg/lwis.kk`
- `SMC`: implemented as `src/alg/smc.kk`
- `PMMH`: implemented as `src/alg/pmmh.kk`
- `RMSMC`: implemented as `src/alg/rmsmc.kk`
- `SMC2`: implemented as `src/alg/smc2.kk`
- generic `MCMC` wrappers: implemented in `src/alg/mcmc.kk`

## Sequential Layer And Coverage Notes

The particle family now sits on top of an explicit sequential model layer:

- a step-wise model boundary
- resampling over populations
- trace/state propagation across sequential time
- a reusable sequential API independent of any one example

That layer is implemented in `src/core/sequential.kk` and used directly by:

- `src/examples/hmm.kk`
- `src/examples/sir.kk`

## Deliberate Simplifications

- `SMC` is implemented directly over sequential models using `lw` at each step and multinomial resampling.
- `PMMH` uses an independent-prior proposal over parameter particles with an inner `SMC` likelihood estimate.
- `RMSMC` rejuvenates resampled particles with independent-prior MH over prefix models instead of a deeper traced-transformer port.
- `SMC2` maintains outer parameter particles and uses inner prefix `SMC` estimates, but it recomputes inner prefix filters rather than preserving an optimized mutable nested filter state.

## Recommended Next Step

If the goal is to move closer to the broader optimized `monad-bayes` implementation style, the next implementation step should be:

1. replace the current multinomial-only resampling with configurable resamplers
2. maintain incremental nested filter state in `SMC2`
3. add more proposal kernels beyond the current independent-prior and single-site replay moves
