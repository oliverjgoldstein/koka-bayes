# Architecture Mapping

| Architecture concept | Target Koka module | Status | Notes / deviations |
| --- | --- | --- | --- |
| Observable variables (`#x`-style role) | `src/core/obsvar.kk` | Implemented | Uses explicit typed constructors instead of overloaded labels. |
| Model environments | `src/core/env.kk` | Implemented | Uses typed wrappers plus runtime codecs rather than type-level records. |
| Multimodal model type | `src/core/model.kk` | Implemented | Native Koka effect rows drive the modeling layer. |
| Primitive distributions | `src/core/dist.kk` | Implemented | Includes observable and primed/sample-only variants. |
| Sequential model layer | `src/core/sequential.kk` | Implemented | Provides reusable step-wise models for particle algorithms. |
| Observation reader effect | `src/handlers/read.kk` | Implemented | Ordered consumption of repeated observations. |
| Distribution interpretation effect | `src/handlers/dist.kk` | Implemented | Defers sample-vs-observe interpretation. |
| Specialization pipeline | `src/handlers/core.kk` | Implemented | Composes environment reads with distribution interpretation. |
| Sample trace | `src/core/trace.kk` | Implemented | Uses deterministic linear execution addresses. |
| Log-probability trace | `src/core/trace.kk`, `src/alg/lw.kk`, `src/alg/mh.kk` | Implemented | Stored alongside runtime events for LW and MH. |
| Generic MCMC wrappers | `src/alg/mcmc.kk` | Implemented | Shared MH chain used by particle MCMC layers. |
| Simulation | `src/alg/simulate.kk` | Implemented | Returns model output, trace, and reified output environment. |
| Likelihood weighting | `src/alg/lw.kk` | Implemented | Iterative weighted samples over the same model. |
| Likelihood weighting with resampling | `src/alg/lwis.kk` | Implemented | Resamples the empirical posterior induced by `lw`. |
| Metropolis Hastings | `src/alg/mh.kk` | Implemented | Single-site replay MH with trace-prefix reuse and suffix regeneration. |
| Sequential Monte Carlo | `src/alg/smc.kk` | Implemented | Step-wise particle filtering over `sequential-model`. |
| Particle marginal Metropolis-Hastings | `src/alg/pmmh.kk` | Implemented | Independent-prior PMMH over parameter particles with inner SMC estimates. |
| Resample-move SMC | `src/alg/rmsmc.kk` | Implemented | Resampled particles are rejuvenated by prefix-model MH moves. |
| SMC2 | `src/alg/smc2.kk` | Implemented | Outer parameter particles with inner prefix SMC estimates; inner filters are recomputed on prefixes. |
| Linear regression example | `src/examples/linear_regression.kk` | Implemented | Simulation and LW use the same model body. |
| HMM example | `src/examples/hmm.kk` | Implemented | Repeated observation consumption demonstrated explicitly. |
| Modular HMM composition | `src/examples/hmm.kk` | Implemented | Transition and observation submodels are first-class values. |
| Higher-order HMM | `src/examples/hmm.kk` | Implemented | Parameterized by transition/observation priors and reusable transition/observation submodels. |
| SIR model | `src/examples/sir.kk` | Implemented | Transition/observation modular HMM with simulation, MH, SMC, PMMH, SMC2, and bootstrap demo. |
| Additional effects / instrumentation | `src/core/model.kk`, `src/core/trace.kk`, examples | Implemented | Trace reification and output environments provide the instrumentation surface. |

## Current Assessment

The repository now implements the current Koka v3 architecture as the primary code path under `src/`. The thesis-era implementation remains available only as archived historical context under `legacy/2019/`.
