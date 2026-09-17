[Docs](README.md) · [Get started](USAGE_GUIDE.md)

<a id="monad-bayes-and-the-koka-effect-handler-implementation"></a>

# Monad-bayes and effect handlers

Both libraries separate the model from the way inference runs. Monad-bayes
uses monad transformers to combine sampling, scoring and particle operations.
This project uses effect handlers for those jobs.

For example, the same Koka `room` model can run with either SMC or likelihood
weighting:

```koka
smc-model(2500, data, room)
likelihood-weighting(2500, data, fn(){ run-sequential(room) }, seed=2027)
```

SMC resamples at the model's checkpoints. `run-sequential` continues through
those checkpoints for likelihood weighting. The [complete example](../examples/compositional_inference.kk)
supplies the model, data and imports:

```sh
make demo-handlers
```

Read [how the handlers compose](HANDLER_COMPOSITION.md) to follow that example.
The comparison below explains the corresponding parts of monad-bayes and the
remaining differences. It is a source comparison, not a proof that the two
libraries are equivalent.

<details>
<summary>Corresponding components and source references</summary>

## Corresponding components

This comparison uses the official `tweag/monad-bayes` source at
[`c8b3d0a425698a976e799afeb835ff50d52f0c04`](https://github.com/tweag/monad-bayes/tree/c8b3d0a425698a976e799afeb835ff50d52f0c04)
(package version 1.3.0.5), inspected on 17 September 2026. It compares source
structure and mathematical responsibilities; it is not a runtime benchmark
or an execution-based equivalence test of the two libraries.

| Responsibility | Monad-bayes | Current Koka implementation |
| --- | --- | --- |
| Request random draws | `MonadDistribution` operations | `model-dist` interpreted by `handle-dist` and `sample-hook` |
| Record a factor | `MonadFactor.score` | Public `score` / `log-score`, interpreted through `factor-hook`; observed distributions also score |
| Accumulate a weight | `WeightedT`, implemented with `StateT` | Scoped `handle-weight`, independent for nested calls and multi-shot branches |
| Represent particles and resample | `PopulationT` transformations | `resample-population` returns offspring and a normalizer; `sample-population` drives suspended particles |
| Pause inference | `SequentialT` suspends after a score | Explicit `checkpoint`, `suspend` and `advance`; `smc-model` accepts ordinary checkpointed model code |
| Trace and rejuvenate | `TracedT` and `mhStep` | Scoped `handle-trace`, separate sampling/replay handlers and `mh-chain`; RMSMC proposes a fresh full prefix |
| Pass inner evidence outward | `pushEvidence` | Explicit `push-evidence` / `push-population`; SMC² pushes incremental normalizers once |

See the pinned [model classes](https://github.com/tweag/monad-bayes/blob/c8b3d0a425698a976e799afeb835ff50d52f0c04/src/Control/Monad/Bayes/Class.hs),
[weight representation](https://github.com/tweag/monad-bayes/blob/c8b3d0a425698a976e799afeb835ff50d52f0c04/src/Control/Monad/Bayes/Weighted.hs),
[population operations](https://github.com/tweag/monad-bayes/blob/c8b3d0a425698a976e799afeb835ff50d52f0c04/src/Control/Monad/Bayes/Population.hs)
and [sequential representation](https://github.com/tweag/monad-bayes/blob/c8b3d0a425698a976e799afeb835ff50d52f0c04/src/Control/Monad/Bayes/Sequential/Coroutine.hs).

Monad-bayes carries evidence in particle weights: spawning divides initial
mass between particles, and resampling preserves total mass. `pushEvidence`
passes that mass to the enclosing score interpretation and normalizes the inner
population. Koka keeps equally weighted resampled particles and separately
accumulates products of mean incremental weights in log form. These are
compatible accounting choices when the initialization and observation contracts
hold; matching stored numbers field-for-field is not the relevant test. Koka's
checkpoints are explicit and independent of scores: several factors can be
accumulated before resampling. `run-sequential` completes the same checkpoints
for a direct model interpretation such as likelihood weighting.

</details>

<details>
<summary>How RMSMC, PMMH and SMC² are assembled</summary>

## The three composed algorithms

| Method | Monad-bayes construction | Koka construction and difference |
| --- | --- | --- |
| RMSMC | Sequential traversal of a traced population, resampling and applying `mhStep` at boundaries | Per-step LW, resampling, then independent-prior MH over a regenerated prefix. Same target requirement, a different proposal and explicit step representation. |
| PMMH | Run inner SMC, push its evidence into parameter tracing, then apply MCMC | Propose a parameter, run `smc-given`, and pass the stored likelihood estimate to `mh-chain`. The whole estimate survives rejection. |
| SMC² | Apply RMSMC to a preprocessed inner SMC computation that pushes evidence incrementally | Maintain explicit outer particles containing retained `smc-state` values; extend, reweight, resample and rejuvenate them. The implementation has a separate outer loop instead of reusing RMSMC as a transformation. |

Sources: [RMSMC](https://github.com/tweag/monad-bayes/blob/c8b3d0a425698a976e799afeb835ff50d52f0c04/src/Control/Monad/Bayes/Inference/RMSMC.hs),
[PMMH](https://github.com/tweag/monad-bayes/blob/c8b3d0a425698a976e799afeb835ff50d52f0c04/src/Control/Monad/Bayes/Inference/PMMH.hs),
[SMC²](https://github.com/tweag/monad-bayes/blob/c8b3d0a425698a976e799afeb835ff50d52f0c04/src/Control/Monad/Bayes/Inference/SMC2.hs).

SMC² makes operation routing especially clear. Its helper transformer lifts
inner-filter random draws past the outer tracing layer, while evidence scoring
reaches the outer weighting and suspension layers. In a handler implementation,
the corresponding requirement is to handle inner sampling in its own scope and
send only the appropriate evidence increment to the outer inference machinery.
The inner filter's auxiliary state must still be retained on rejection and copied
with an outer particle. The current Koka implementation does this explicitly.

</details>

<details>
<summary>What has been checked, and what remains</summary>

## What the comparison establishes

The Koka code implements the three statistical constructions under its stated
contracts. It now has reusable weighting, tracing, sampling, suspension and
population components, and a general checkpoint-based SMC driver. The existing
RMSMC, PMMH and SMC² implementations reuse these components but still have
dedicated loops. In particular, SMC² is not yet defined solely by composing
RMSMC with an inner inference transformation. The [2018 paper](https://www.cs.ox.ac.uk/people/ohad.kammar/publications/scibior-kammar-ghahramani-funcitonal-programming-for-modular-bayesian-inference.pdf)
is the relevant reference for that architectural goal; its use of Haskell is
not a requirement for expressing the same inference structure.

Two concrete Koka counterexamples have been repaired, with runnable regressions
in the [handler guide](HANDLER_COMPOSITION.md): multi-shot branches now have
independent trace/weight state, and filtering and whole-prefix replay consume
each supplied observation once. Exact finite models test the resulting joint
posteriors and evidence, including varying checkpoint counts. These tests give
bounded implementation evidence, rather than a general semantic proof.

Monad transformers do not provide unrestricted correctness automatically either.
For example, the inspected `Population.hs` explicitly marks its internal `ListT`
monad instance as unlawful and relies on carefully chosen uses. The upstream
library is a reference for specific constructions, not a proof for every possible
transformer stack or for the Koka port.

## Implemented steps and remaining scope

The handler refactor implements branch-local state, occurrence-based observation
streams, general factors, explicit evidence transfer, suspension and population
transformations. The [thermometer example](../examples/compositional_inference.kk)
uses these components to run one model with SMC or likelihood weighting.

The tests check score identity and multiplication, isolated multi-shot branches,
mass accounting, cloned observation cursors, state-aware parameter proposals,
and complete auxiliary-state retention on rejected moves. They are included in
the full project check and CI.

Further work would express RMSMC/PMMH/SMC² entirely through reusable inference
transformations and provide a semantic correctness argument for the chosen
handler orders. Effect rows describe available operations; they do not certify
arbitrary operation routing, external mutable state or untraced randomness.
The [custom-kernel contracts](USAGE_GUIDE.md#sequential-models-and-custom-kernels),
including SMC²'s initial proposal-density requirement, continue to apply.

Run the composition checks with `make test-handlers`.

</details>
