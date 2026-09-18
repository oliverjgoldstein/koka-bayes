[Docs](README.md) · [Get started](USAGE_GUIDE.md)

# Composing inference with effect handlers

A model describes unknown values and the data you observed. Handlers decide
how to run it: draw weighted samples, resample particles, or enumerate finite
choices. You can use the same model with different inference methods.

For operation signatures, handler clauses, state scopes and weight equations,
read the [effects and handlers reference](EFFECTS_AND_HANDLERS.md). The
[sequential reference](SEQUENTIAL_HANDLERS.md) specifies the particle algorithms'
transitions, evidence accounting and custom proposal contracts.

The [original-thesis comparison](PAPER_COMPARISON.md) explains which handler
roles carry over and how the current algorithm compositions differ.

**Specific handler combinations are implemented and tested; arbitrary handler
composition has no general correctness proof here.** RMSMC, PMMH and SMC²
share components but still have dedicated algorithm loops. Composing inference
handlers does not supply automatic gradients through sampling or resampling.
See [what works today](STATUS.md) for the supported combinations and limits.

Start with the example below. `checkpoint()` marks a place where SMC can
resample. Another handler can simply continue past that checkpoint.

## One ordinary model, two interpretations

The complete runnable [thermometer example](../examples/compositional_inference.kk)
uses this model:

```koka
fun room() : <checkpoint,obs-reader,model-dist,div> float64
  val temperature = normal'(20.0, 2.0)
  readings.foreach fn(_){
    val observed = normal(thermometer, temperature, 1.0)
    checkpoint()
  }
  temperature
```

`smc-model(2500, data, room)` resamples at those boundaries.
`likelihood-weighting(2500, data, fn(){ run-sequential(room) }, seed=2027)`
completes the same checkpoints without population resampling. The example
supplies readings `[19, 21, 22]` and compares both estimates with the analytic
posterior mean, approximately 20.615°C.

```sh
make demo-handlers
make test-handlers
```

Choose another method in the [inference examples](INFERENCE_EXAMPLES.md), or
try [finite enumeration](EXACT_INFERENCE.md) for a small model with finite
latent choices. Open the sections below when you need the handler APIs or the
correctness checks.

<details>
<summary>Handler APIs and how state is kept separate</summary>

## Reusable components

| Responsibility | API and module | State or rule |
| --- | --- | --- |
| Read observations | `handle-read-state`, `handlers/read` | Each name has an occurrence stream, consumed once; returns the remaining stream. |
| Score a model | `score`, `log-score`, `core/model` | Adds a factor independently of an observed distribution. |
| Accumulate log weight | `handle-weight`, `handlers/weight` | Scoped state, separate for resumed branches and nested handlers. |
| Pass evidence outward | `push-evidence`, `push-population` | Explicitly contributes one log normalizer to the enclosing weight handler. |
| Construct a trace | `handle-trace`, `handlers/trace` | Scoped addresses and entries; factors have their own trace mode. |
| Interpret sample requests | `handle-sampling`, `handle-replay` | Fresh draws or prefix reuse followed by suffix regeneration. |
| Enumerate finite alternatives | `enumerate`, `handlers/enumerate`, `core/finite` | Resume every positive finite choice; reader, trace and score state remain branch-local while the tree budget is shared. |
| Suspend and resume | `checkpoint`, `suspend`, `advance`, `run-sequential`, `handlers/sequential` | Captures a continuation; completion can also interpret checkpoints as ordinary execution. |
| Resample a population | `resample-population`, `handlers/population` | Equally weighted offspring plus the log mean input weight. |
| Run suspended particles | `sample-population`, `handlers/population` | Advances and resamples continuations with fresh incremental weight at each boundary. |
| Run checkpointed models | `smc-model`, `alg/handler_smc` | Composes the components above into SMC over ordinary model code. |

`score(w)` accepts a finite, nonnegative weight, including weights above one;
zero means zero mass. `log-score(l)` supplies a log weight directly; its supported
domain is finite values or negative infinity. It does not validate on entry;
NaN and positive infinity are invalid inputs. Factors affect likelihood and
acceptance, but do not become latent proposal sites or named output observations.

Nested inference keeps its weights local. Passing an inner likelihood estimate
to an outer model requires an explicit `log-score(inner.log-evidence)`; inside
the lower-level weight interface, use `push-evidence`. This avoids silently
counting both individual inner observations and their aggregate evidence.

For small models with finite latent choices, [finite enumeration](EXACT_INFERENCE.md)
uses the same observation and trace handlers to calculate posterior probabilities
and evidence. Its separate `make test-enumerate` checks include nested enumeration,
explicit evidence transfer and enclosing multi-shot handlers.

The observation reader, trace and model-local scoped variables remain inside
the suspended computation. Resampling can therefore resume a saved computation
multiple times with independent copies of that state. Weight accumulation sits
outside each suspension interval, so old likelihood factors are not scored
again. Completed computations are absorbing with unit incremental weight;
tests also cover paths with different numbers of checkpoints. An all-zero-mass
population returns no particles and log evidence `-inf`.

</details>

<details>
<summary>RMSMC, PMMH and SMC²: composition and API contracts</summary>

## RMSMC, PMMH and SMC²

These algorithms share the handlers and population operations while retaining
their explicit algorithm loops. SMC² is not defined as a single application of
RMSMC to a transformed model.

| Method | Composition | Required invariant |
| --- | --- | --- |
| RMSMC | Per-step weighting, resampling, then independent-prior MH over a complete prefix | Filtering and replay target the same observations; a move retains or replaces the complete prefix. |
| PMMH | Parameter proposal, an inner SMC likelihood estimate, then MH | Rejection retains the parameter, observation cursor, estimate and inner particle population. |
| SMC² | Outer parameter particles carrying retained inner filters, with PMMH rejuvenation | Extend the existing filter; score each incremental normalizer once; copy or retain the complete extended state. |

For RMSMC the independent prior proposal cancels the prefix prior density,
leaving the likelihood ratio. Default PMMH and SMC² likewise cancel sampled
parameter-prior factors while retaining observed prior likelihoods and explicit
factors. Custom proposals need the complete parameter target and the
reverse-minus-forward proposal correction.

All stages consume the same observation streams. A singleton is consumed once,
including when its name is reused across prior, initial and step stages. Each
particle carries its own remaining stream. For online data, call
`append-smc-observations(new-data, state)` before `advance-smc-state`; append
only the newly arrived occurrences. State-aware custom parameter kernels return
their own remaining stream through `Parameter-proposal`. See the
[API contracts](USAGE_GUIDE.md#sequential-models-and-custom-kernels).

These invariants follow the resample-move construction in
[Doucet's lectures](https://www.cs.ubc.ca/~arnaud/samsi/samsi_lec4.pdf) and the
extended-space construction in
[SMC², sections 3.1–3.5](https://arxiv.org/html/1101.1528v3).

</details>

<details>
<summary>Correctness checks and repaired bugs</summary>

## Repaired counterexamples and verification

Previously, an outer multi-shot handler that resumed `run-lw` twice could return
weights 0.8 and 0.16 with trace lengths one and two. Both branches now retain
one trace entry and weights 0.8 and 0.2. The checks cover either resumption
order, branching after an existing observation, and particle/MH compositions.

Previously, a two-step RMSMC model given `[True]` observed it twice without
rejuvenation, but once during full-prefix replay. Both paths now consume it once
and sample the subsequent missing occurrence. The historical probes remain
runnable under `tests/probes/` and show the repaired behavior.

`make test-handlers` runs:

- [Multi-shot checks](../tests/handler_multishot.kk): independent trace, weight,
  address and observation state, including accepted and rejected moves.
- [Scoring laws](../tests/handler_laws.kk): identity, multiplication, nesting,
  explicit evidence transfer, factor traces, zero mass and invalid weights.
- [Observation streams](../tests/sequential_observations.kk): shared names,
  multiple or conditional occurrences per step, online append and batch equality.
- [Inference transformations](../tests/inference_transformations.kk): cloned
  suspensions, normalizers, variable checkpoint counts, exact finite targets,
  state-aware parameter kernels and explicit nested evidence.
- [Checkpoint SMC](../tests/handler_smc_checks.kk): equality to weighted resampling
  without checkpoints, an independently enumerated joint posterior and evidence
  across three seeds, retained local state, and zero-mass termination.
- The existing [RMSMC](../tests/handler_composition_rmsmc.kk),
  [PMMH](../tests/handler_composition_pmmh.kk) and
  [SMC²](../tests/handler_composition_smc2.kk) checks for nested isolation,
  target accounting and retained state after rejection.

These tests also run in `make check` and CI, alongside the
[exact joint-posterior audit](INFERENCE_AUDIT.md).

An earlier local validation snapshot on 17 September 2026 passed `./bayes check` using Koka 3.2.3,
Node 24.21.0 and the JavaScript backend on macOS arm64: 46 library/model files
compiled, all handler checks passed, 36 inference benchmark runs and 27 joint
posterior comparisons passed, and all examples completed. This records local
validation; it is not a hosted CI result for these changes.

The remaining contracts matter: replay must trace every random choice affecting
its target; custom parameter scores must be deterministic target densities;
custom SMC² initialization must expose the prior's sampled coordinates.
Caller-provided I/O and mutable references need suitable semantics of their own.
Handler order determines which scope interprets an operation, so arbitrary
reordering is not a correctness guarantee. A general semantic proof and a fully
transformation-defined SMC² remain further work.

</details>
