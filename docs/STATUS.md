[Docs](README.md) · [Get started](USAGE_GUIDE.md)

# What works today

**You can use gradients to perform inference. Automatic differentiation of
inference results is not implemented.**

This page describes the current implementation. “Implemented and tested” means
checked on the documented examples and budgets, not proved correct or convergent
for every program.

## Available

| Capability | Supported scope |
| --- | --- |
| [LW, LWIS, MH, SMC, RMSMC, PMMH and SMC²](INFERENCE_EXAMPLES.md) | Implemented and tested on multiple models. Sampling error, tuning and each algorithm's contracts still apply. |
| [Finite enumeration](EXACT_INFERENCE.md) | Explore supported finite execution trees within a node budget. Posterior probabilities and evidence are exact up to floating-point rounding. Continuous latent variables are unsupported. |
| [Forward and reverse AD](AUTODIFF.md) | First derivatives of scalar arithmetic written with `ad-*`; reverse mode accepts a list of scalar inputs and a scalar output. |
| [HMC and MALA](GRADIENT_INFERENCE.md) | Use AD on a smooth log density with a fixed number of continuous coordinates. Step sizes and other settings are manual. |
| [One model with probabilistic and differentiable interpretations](GRADIENT_INFERENCE.md#one-model-probabilistic-and-differentiable-interpretations) | The scalar Normal-site interface, with a fixed number and order of latent sites. It does not automatically convert arbitrary `core/model` programs. |
| [Specific handler combinations](HANDLER_COMPOSITION.md) | Weighting, tracing, checkpoints, populations and explicit nested evidence transfer have implementation tests. RMSMC, PMMH and SMC² still retain dedicated algorithm loops. |

## Not implemented

| Capability | What is missing |
| --- | --- |
| Gradients of enumerated probabilities, expectations or evidence | Enumeration uses `float64` weights; its branch weights and normalization are not connected to AD. |
| Gradients through sampling or resampling | No automatic gradient rules for random draws, particle selection or the outputs of LW, MH, SMC, RMSMC, PMMH or SMC². HMC/MALA also do not expose derivatives of their sampler outputs. |
| Automatic gradients of probabilistic expectations | No general gradient-estimator interface for expectations under parameter-dependent distributions. |
| General mixed discrete/continuous gradient inference | No automatic discrete marginalization within the differentiable model interface. |
| More advanced AD and samplers | No higher derivatives, nested AD, tensors, automatic constraint transforms, sampler adaptation, NUTS or variational inference. |

For example, inferring a room temperature with HMC works. Enumerating possible
faults and reporting their posterior probabilities also works. Automatically
differentiating those probabilities with respect to an alarm's sensitivity is
not implemented. Neither is automatically differentiating a particle filter's
evidence estimate.

## What has not been proved

**This implementation has no general denotational correctness proof.** Tests
support particular models, handler orders and state-isolation properties.
They do not establish that arbitrary handlers can be stacked or reordered
correctly, or that every finite sampling run is accurate.

The AD handlers are not an implementation of the CHAD source transformations
and do not inherit their correctness guarantees. Research foundations and
implemented features are separate: see the [AD research basis](AUTODIFF.md#research-basis)
and [comparison with monad-bayes](MONAD_BAYES_COMPARISON.md).

## Known empirical limitation

**Recorded SIR runs miss parameter-recovery thresholds for PMMH and SMC².**
The reported errors for the report-rate parameter are about **0.148 and 0.151**,
respectively, against a threshold of **0.12**.

These checks compare estimates with the parameter that generated the data,
not with an exact posterior mean. The failures do not by themselves distinguish
Monte Carlo error, posterior uncertainty or prior influence, and do not establish
an algorithm bug. They do prevent a claim of reliable performance on every model.

The [audit](INFERENCE_AUDIT.md#known-empirical-limitation) and
[recorded results](sir-audit-results.csv) retain these failures. Passing the
[multiple-model checks](MULTI_MODEL_VALIDATION.md) does not erase them.

The report now shows separate recovery status for each parameter, draw counts,
distinct values and empirical 90% intervals, and preserves full CSV precision.
These intervals describe retained draws, not Monte Carlo error or convergence.
`make test-sir` separately checks a [small SIR posterior against exhaustive
arithmetic](INFERENCE_AUDIT.md#small-sir-posterior-check); it does not resolve
the larger model's recovery failures.
