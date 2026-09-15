# Architecture Mapping

Start with [model.kk](../../model.kk). This table is an optional guide to the
library implementation beneath that entrypoint. Paths are relative to the project root.

| Architecture concept | Target Koka module | Status | Notes / deviations |
| --- | --- | --- | --- |
| Editable model and inference | `model.kk` | Implemented | Model, data, method selection, and result printing in one file. |
| Public model API | `lib/bayes.kk` | Implemented | One `import bayes`; seeded inference helpers and weighted posterior summaries. |
| Observable variables (`#x`-style role) | `lib/core/obsvar.kk` | Implemented | Uses explicit typed constructors instead of overloaded labels. |
| Model environments | `lib/core/env.kk` | Implemented | Uses typed wrappers plus runtime codecs rather than type-level records. |
| Multimodal model type | `lib/core/model.kk` | Implemented | Native Koka effect rows drive the modeling layer. |
| Primitive distributions | `lib/core/dist.kk` | Implemented | Includes observable and primed/sample-only variants. |
| Sequential model layer | `lib/core/sequential.kk` | Implemented | Provides reusable step-wise models for particle algorithms. |
| Observation reader effect | `lib/handlers/read.kk` | Implemented | Ordered consumption of repeated observations. |
| Distribution interpretation effect | `lib/handlers/dist.kk` | Implemented | Defers sample-vs-observe interpretation. |
| Specialization pipeline | `lib/handlers/core.kk` | Implemented | Composes environment reads with distribution interpretation. |
| Sample trace | `lib/core/trace.kk` | Implemented | Uses deterministic linear execution addresses. |
| Log-probability trace | `lib/core/trace.kk`, `lib/alg/lw.kk`, `lib/alg/mh.kk` | Implemented | Stored alongside runtime events for LW and MH. |
| Generic MCMC wrappers | `lib/alg/mcmc.kk` | Implemented | Shared MH chain used by particle MCMC layers. |
| Simulation | `lib/alg/simulate.kk` | Implemented | Returns model output, trace, and reified output environment. |
| Likelihood weighting | `lib/alg/lw.kk` | Implemented | Iterative weighted samples over the same model. |
| Likelihood weighting with resampling | `lib/alg/lwis.kk` | Implemented | Resamples the empirical posterior induced by `lw`. |
| Metropolis Hastings | `lib/alg/mh.kk` | Implemented | Single-site replay MH with trace-prefix reuse and suffix regeneration. |
| Sequential Monte Carlo | `lib/alg/smc.kk` | Implemented | Step-wise particle filtering over `sequential-model`. |
| Particle marginal Metropolis-Hastings | `lib/alg/pmmh.kk` | Implemented | Independent-prior PMMH over parameter particles with inner SMC estimates. |
| Resample-move SMC | `lib/alg/rmsmc.kk` | Implemented | Resampled particles are rejuvenated by prefix-model MH moves. |
| SMC2 | `lib/alg/smc2.kk` | Implemented | Outer parameter particles retain and extend inner SMC filters; rejuvenation proposes a fresh prefix filter. |
| Linear regression example | `examples/linear_regression.kk` | Implemented | Simulation and LW use the same model body. |
| HMM example | `examples/hmm.kk` | Implemented | Repeated observation consumption demonstrated explicitly. |
| Modular HMM composition | `examples/hmm.kk` | Implemented | Transition and observation submodels are first-class values. |
| Higher-order HMM | `examples/hmm.kk` | Implemented | Parameterized by transition/observation priors and reusable transition/observation submodels. |
| SIR model | `examples/sir.kk` | Implemented | Transition/observation modular HMM with simulation, MH, SMC, PMMH, SMC2, and bootstrap demo. |
| Additional effects / instrumentation | `lib/core/model.kk`, `lib/core/trace.kk`, examples | Implemented | Trace reification and output environments provide the instrumentation surface. |

## Current Assessment

The supported Koka v3 implementation is under `lib/`, with complete runnable models under `examples/` and independent checks under `tests/`. The thesis-era implementation remains available only as archived historical context under `archive/2019/`.
