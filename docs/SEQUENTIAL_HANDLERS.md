[Docs](README.md) · [Effects and handlers](EFFECTS_AND_HANDLERS.md) · [Composition guide](HANDLER_COMPOSITION.md)

# Sequential handlers and particle inference

This reference explains the implementation in
[`handlers/sequential`](../lib/handlers/sequential.kk),
[`handlers/population`](../lib/handlers/population.kk) and the sequential
algorithms. The [effects reference](EFFECTS_AND_HANDLERS.md) describes model
operations, observation reading, tracing and weighting; the
[composition guide](HANDLER_COMPOSITION.md) gives a short runnable introduction.

Only `checkpoint` introduces an effect in these two handler modules.
`suspend` interprets that effect. Population resampling is an ordinary function
using `random`; `sample-population` composes suspension and weight handlers.
SMC, RMSMC, PMMH and SMC² are dedicated algorithm loops built from these and
other components. Calling them handlers does not make their correctness follow
from arbitrary handler composition.

The equations below describe the implemented calculations and their contracts.
They are not a formal denotational semantics or a proof of the implementation.
Particle results are finite Monte Carlo approximations. The
[inference audit](INFERENCE_AUDIT.md) records independent reference targets and
the [status page](STATUS.md) distinguishes supported behavior from limitations.

## The checkpoint effect

The declarations in [`handlers/sequential`](../lib/handlers/sequential.kk) are:

```koka
pub effect checkpoint
  ctl checkpoint() : ()

pub type suspension<e,a>
  Completed(value : a)
  Suspended(next : () -> e suspension<e,a>)

pub fun suspend<a,e>(action : () -> <checkpoint|e> a) : e suspension<e,a>
  handle(action)
    return(value) Completed(value)
    ctl checkpoint() Suspended(fn(){ resume(()) })
```

`suspend(action)` runs the action until its first checkpoint or normal return.
At a checkpoint it returns a saved continuation without evaluating the rest of
the action. Calling `next()` resumes after that checkpoint with result `()`.
The checkpoint handler is reinstated, so another checkpoint produces another
`Suspended` value. Other effects in `e` keep the interpretation supplied by their
enclosing handlers; suspension does not turn them into pure data.

| Operation | Type after handling checkpoints | Behavior |
| --- | --- | --- |
| `suspend(action)` | `e suspension<e,a>` | Runs to the first boundary or completion. |
| `advance(state)` | `e suspension<e,a>` | Calls a suspended continuation once; returns a completed state unchanged. |
| `complete(state)` | `<div\|e> a`, for `state : suspension<<div\|e>,a>` | Repeatedly resumes until completion. It has no step limit. |
| `run-sequential(action)` | `<div\|e> a`, for `action : () -> <checkpoint,div\|e> a` | Exactly `complete(suspend(action))`; checkpoints cause no resampling. |

For example, suspending `fn(){ checkpoint(); checkpoint(); 7 }` gives a
`Suspended`; advancing it gives another `Suspended`; advancing again gives
`Completed(7)`. Resuming the same saved continuation again is supported, which
is what permits resampling to duplicate a particle's future computation.

Scoped reader, trace and local variable state must be positioned so each
resumption restores its own state. This does not clone external mutable
references, files or a caller's random generator. Subsequent random operations
are handled by the surrounding `random` interpretation. Arbitrary effects in
`e` need suitable resumption semantics of their own.

## Populations and their normalizers

The public result type in [`handlers/population`](../lib/handlers/population.kk)
is `population<a>`, with fields `values : list<a>` and
`log-evidence : float64`. Its public operations are:

```koka
resample-population(count : int, values : list<a>,
                    log-weight : a -> float64) : <div,random> population<a>

push-population(result : population<a>) : accumulate-weight list<a>

add-evidence(current : float64, increment : float64) : float64
evidence-increment(previous : float64, current : float64) : float64
```

For input particles `v₁,…,vₙ` with incremental log weights `ℓ₁,…,ℓₙ`,
`resample-population(m, ...)` computes

```text
Wᵢ = exp(ℓᵢ) / Σⱼ exp(ℓⱼ)
log z = log(Σᵢ exp(ℓᵢ)) − log n
```

and draws `m` offspring independently with replacement using probabilities
`Wᵢ`. The implementation uses a maximum shift for normalization; it does not
exponentiate large log weights directly. Offspring are interpreted as equally
weighted; the function returns selected values unchanged and does not reset
any weight fields inside them. The
denominator for the normalizer is the **input population size `n`**, regardless
of the requested offspring count `m`. For weights `0.2` and `0.6`, the normalizer
is `0.4`, even if twelve offspring are requested. The concrete multinomial draw
and normalization code is in [`core/weights`](../lib/core/weights.kk).

`push-population(result)` invokes `push-evidence(result.log-evidence)` once and
returns `result.values`. It neither resamples again nor tracks whether the
caller previously pushed that result. Calling it twice counts the same
normalizer twice. Ordinary nesting does not push inner evidence implicitly.

For finite operands, `add-evidence(L, d) = L + d` and
`evidence-increment(Lold, Lnew) = Lnew − Lold`. If either operand is nonfinite,
each helper returns `-inf`. In particular, a dead filter cannot be revived by
subtracting `-inf` from `-inf`. These checks inspect the operands; they are not
general arbitrary-precision or overflow guarantees.

Boundary behavior follows the implementation:

| Input | Result |
| --- | --- |
| Empty input or all log weights `-inf` | No offspring; log normalizer `-inf`. |
| Any NaN or `+inf` log weight | Normalization fails; no offspring and log normalizer `-inf`. Invalid weights are not converted into a uniform posterior. |
| Some finite log weights and some `-inf` | Zero-weight entries cannot be selected; the mean still divides by the full input count. |
| `count <= 0` with otherwise valid nonempty input | No offspring, but `resample-population` still reports the input's computed normalizer. |

`add-evidence` and `evidence-increment` are pure helpers. `push-population` emits
a weight effect. `resample-population` draws from `random` but installs no
handler itself.

## SMC over saved continuations

The lower-level interface is:

```koka
sample-population<a,e>(count : int,
  action : () -> <checkpoint,accumulate-weight,div,random|e> a)
  : <div,random|e> population<a>
```

It performs the following sequence:

1. Run `count` copies of `action` to their first checkpoint or completion.
   Each starts under `handle-weight(fn(){ suspend(action) })`, with weight zero.
2. Resample those suspensions using the accumulated weights and record the
   first log mean weight.
3. Unless all surviving computations are complete, advance each once under a
   **fresh** `handle-weight(fn(){ advance(state) })`, resample, and add this
   interval's log mean weight to the accumulated evidence.
4. Repeat until all surviving computations complete. Return their values and
   the accumulated log evidence.

An already completed computation is absorbing: `advance` returns it unchanged
and its fresh incremental log weight is `0`, corresponding to weight `1`.
Particles may therefore have different checkpoint counts. A trailing interval
after the final checkpoint still runs and scores before returning the result.
There is no adaptive effective-sample-size threshold: every active round
resamples. A model that suspends forever can make the loop run forever.

If `z₀` is the initial population normalizer and `zᵣ` is each later interval's
normalizer, the returned value is

```text
log Z-hat = log z₀ + Σᵣ log zᵣ .
```

Weights from previous intervals must not be reused in a later mean. For
instance, every particle in the following lower-level action receives total
weight `0.5 × 0.25 = 0.125`:

```koka
fn(){
  accumulate-weight(ln(0.5))
  checkpoint()
  accumulate-weight(ln(0.25))
  checkpoint()
  7
}
```

The successive incremental normalizers are `0.5`, `0.25`, and `1`; the last is
the completed return interval. `sample-population(8, action)` returns eight
copies of `7` and `log-evidence = ln(0.125)`. This exact calculation is checked
in [`tests/inference_transformations.kk`](../tests/inference_transformations.kk).
For `count <= 0`, `sample-population` does not run the action and returns an empty
population with `-inf` evidence. A later zero-mass population also terminates
with no values and `-inf` evidence.

## The `smc-model` handler stack

[`alg/handler_smc`](../lib/alg/handler_smc.kk) connects an ordinary checkpointed
model to this population interpreter:

```koka
smc-model<a,e>(particle-count : int, environment : env,
  action : () -> <checkpoint,obs-reader,model-dist,div|e> a)
  : <div,random|e> smc-result<a>
```

For the initial interval, its scopes have this order, from outer to inner
(the source also contains effect masks to preserve the intended scopes):

```text
fresh handle-weight
  suspend / checkpoint handler
    handle-sampling
      handle-trace
        handle-core-state(environment, action)
          observation reader + distribution interpretation
            model action
```

The model reader, trace, addresses and model-local scoped state live **inside**
the captured computation. Duplicating a suspension duplicates their continuation
state. Weight accumulation lives **outside** each interval, so each advancement
starts at zero. In contrast, placing `run-lw` inside a suspension deliberately
retains a whole-run weight with the continuation; that is useful for completing
and cloning one weighted run, but is not the interval structure used here.

`smc-model` converts each completed `(value, remaining environment, trace)` into
an `smc-sample`. Its `log-likelihood` is the sum of observed and explicit-factor
trace scores for that particular path. The result's `log-evidence` is the
product-of-population-means estimate described above. These are different
quantities. `posterior-env` concatenates the named outputs from all surviving
particle traces; it is not a normalized density object.

Without checkpoints, the algorithm runs a population of complete weighted
executions and performs one weighted resampling. Seeded equality with that
construction is tested in
[`tests/handler_smc_checks.kk`](../tests/handler_smc_checks.kk).

## Explicit sequential models and retained SMC state

[`core/sequential`](../lib/core/sequential.kk) defines:

```koka
pub struct sequential-model<e,p,s,o,a>
  prior   : model<e,p>
  initial : p -> <obs-reader,model-dist,div|e> s
  step    : (p, int, s) -> <obs-reader,model-dist,div|e> step-output<s,o>
  finish  : prefix-output<p,s,o> -> a
```

Here `p` is the parameter, `s` the state, `o` an arbitrary value returned by each
step, and `a` the final result. Returning a value in `step-output.observation`
does not itself score anything: scoring comes from the model operations.
`finish` is pure. `prefix-output` contains the parameter, current state, list of
post-step states and list of step outputs; its `states` list excludes the
initial state.

| Adapter | Behavior |
| --- | --- |
| `prefix-model(steps, spec)` | Runs `prior`, then initialization and the requested steps; returns `prefix-output`. |
| `prefix-model-given(steps, parameter, spec)` | Same, without running the parameter prior. |
| `as-model` / `as-model-given` | Apply `finish` to the corresponding prefix. |
| `checkpointed-prefix(steps, parameter, spec)` | Initializes the supplied parameter, checkpoints once, then checkpoints after each step. Steps are indexed from zero; negative step counts become zero. |
| `prefix-run(steps, parameter, spec)` | Runs `checkpointed-prefix` through `run-sequential`, without resampling. |

The staged bootstrap implementation in [`alg/smc`](../lib/alg/smc.kk) uses
`run-lw-state` for each stage. It does not use saved continuations internally.
Its `smc-state<p,s,o>` holds the particle list, next `step-index`, and cumulative
`log-evidence`. Each internal particle retains its parameter, current state,
state/output history, trace, output environment, cumulative path likelihood,
and remaining observation environment.

| Public operation | State transition |
| --- | --- |
| `smc(count, steps, environment, spec)` | Runs prior and initialization for every particle; scores both stages once; resamples; advances the requested number of steps; finishes. |
| `smc-given(count, steps, environment, parameter, spec)` | Same calculation with a fixed parameter, excluding the prior stage. |
| `start-smc-given(count, environment, parameter, spec)` | Runs and resamples initialization only; returns `step-index = 0`. |
| `advance-smc-state(spec, state)` | Runs one step at the retained index for each particle, scores only that step, resamples, increments the index, adds its log mean weight. |
| `extend-smc-state(steps, spec, state)` | Repeats advancement at most `steps` times; stops immediately for nonpositive counts or an empty population. The count is additional steps, not an absolute horizon. |
| `append-smc-observations(additional, state)` | Purely appends each new observation stream after each particle's unconsumed suffix. It changes neither evidence nor step index. |
| `finish-smc(spec, state)` | Purely applies `finish` and constructs `smc-result`; performs no sampling or scoring. |
| `advance-smc(environment, spec, state)` / `extend-smc(steps, environment, spec, state)` | Compatibility wrappers; their `environment` argument is ignored. They use the cursor retained in `state`. |

The sampling operations have effect row `<div,random|e>`; the append and finish
operations are pure. There is no public `start-smc` for an unfixed parameter;
`smc` performs that initialization internally.

All model stages consume the same named occurrence streams. The prior consumes
a prefix, initialization continues from its suffix, and each step continues
from its own retained suffix. A singleton observation is consumed once; later
requests after exhaustion sample instead. A step may consume a name zero,
one or several times. Occurrence number is therefore not a model time index.
Resampling must copy the cursor with the particle, and `smc-given` must receive
the environment **after** any parameter-prior observations have been consumed.
Online callers append only newly arrived occurrences, not the whole history.

## RMSMC: resample, then move the complete prefix

[`rmsmc(count, steps, mh-steps, environment, spec)`](../lib/alg/rmsmc.kk)
returns `smc-result<a>` with effects `<div,random|e>`. Initialization matches the
prior-plus-initial-stage weighting above. For each step it propagates, resamples
on that step's weights, then runs `mh-steps` independent-prior MH proposals over
the complete prefix.

A proposal reruns `prefix-model(prefix-steps, spec)` from the original full
observation environment using `simulate-state`. It generates a fresh parameter
and trajectory; it is not a local perturbation of the current trajectory.
Although simulation does not return an accumulated weight, its trace retains
observations and factors. The move uses

```text
log acceptance ratio = observed-and-factor-score(proposed prefix)
                     − observed-and-factor-score(current prefix).
```

The sampled prior/transition density cancels against this independent proposal.
The contract is that these are the actual proposal choices for the same prefix
target: untracked external randomness affecting that target is not covered.
Rejection retains the complete prefix, trace, outputs and cursor; acceptance
replaces all of them. Later filtering uses the accepted prefix's remaining
stream. The move contributes no additional evidence factor. Nonpositive
`mh-steps` skip moves; no rejuvenation occurs immediately after initialization
when `steps <= 0`.

## PMMH: retain each proposed likelihood estimate

[`alg/pmmh`](../lib/alg/pmmh.kk) exposes `pmmh`, `pmmh-with`, and
`pmmh-with-state`, all returning `pmmh-result<p,a>` under `<div,random|e>`.
Their common inputs are inner particle count, step count, `mcmc-config`,
environment and sequential model. Each proposed parameter is evaluated with
a fresh `smc-given` run. A retained sample contains the parameter, parameter
outputs, the entire `smc-result`, and its log evidence estimate.

Default `pmmh` proposes independently by running `spec.prior`. Define `B(θ)` as
the observed-and-factor trace score from that prior execution and `Z-hat(θ)` as
the inner filter's evidence for initialization and steps. Its acceptance score
is `B(θ) + log Z-hat(θ)`: sampled parameter-prior densities have already canceled
against the independent proposal, but observations and explicit factors in the
prior remain. The initial default state is one such proposal.

Custom variants instead use a full parameter-level target score `A(θ)`:

```text
log acceptance ratio = A(θ′) + log Z-hat(θ′)
                     − A(θ)  − log Z-hat(θ)
                     + log q(θ | θ′) − log q(θ′ | θ).
```

`A` must include parameter-prior density and every parameter-level observation
or factor, but exclude the sites already scored by the inner filter. It must
be deterministic at a fixed parameter, despite its permissive effect row.
The kernel supplies the reverse-minus-forward log proposal correction.

Custom initialization draws between four and twelve candidates from the prior
(`max(4, min(12, particle-count / 8))`) and chooses the candidate with the largest
computed target score including its filter estimate. This is an initialization
heuristic, not a posterior sample or a mixing guarantee. Burn-in and adequate
mixing still matter. On rejection, both default and custom chains retain the
old likelihood estimate **and the old particle population**; they do not rerun
the current state's filter.

`pmmh-sample.log-evidence` is a conditional inner estimate associated with a
retained parameter. Averaging these retained estimates is not a model-evidence
estimator. `pmmh-result` deliberately has no aggregate evidence field.

## SMC²: an outer population carrying inner filters

[`alg/smc2`](../lib/alg/smc2.kk) exposes `smc2`, `smc2-with` and
`smc2-with-state`, returning `smc2-result<p,a>` under `<div,random|e>`.
Inputs include outer and inner particle counts, step count and the number of
rejuvenation moves per step. Each internal outer particle carries

```text
(parameter, parameter outputs, retained smc-state,
 parameter score, post-prior observation environment).
```

Initialization starts an inner filter at every proposed parameter. Default
outer initialization weight is

```text
observed-and-factor-score(parameter prior) + inner initial log evidence.
```

Custom initialization samples the prior and instead uses

```text
A(θ) − sampled-trace-score(prior execution) + inner initial log evidence.
```

The subtraction divides by the initialization proposal density. Consequently,
**custom SMC² requires the prior to return its sampled latent coordinates as
the parameter**: the sampled trace density must be the proposal density for
the same coordinates scored by `A`. Returning a many-to-one summary, or a
transformation with an unaccounted density/Jacobian change, does not satisfy
that contract. The implementation does not derive a pushforward density or
check this condition at runtime.

For each later step, the algorithm:

1. Advances each **existing** inner filter once.
2. Weights its outer particle by the evidence increment
   `dₜ = log Z-hatₜ − log Z-hatₜ₋₁`, using `evidence-increment` for nonfinite cases.
3. Resamples complete outer particles using those increments.
4. Performs the requested PMMH moves on each resampled particle. A proposal
   builds a fresh inner filter over the entire current prefix; rejection keeps
   the old extended state intact.

The outer log evidence is the sum of the initial and subsequent **outer** log
mean weights, pushed once per resampling boundary into a local weight handler.
Scoring cumulative `log Z-hatₜ` at every step would count old data repeatedly.
Restarting the old parameter's inner filter before calculating its increment
would replace the retained auxiliary state. Neither is the implemented update.
Inner updates and rejuvenation are masked from the outer accumulator; only
explicit `push-population` operations contribute to it.

Default rejuvenation uses the prior-cancelled score described for default PMMH;
custom rejuvenation uses `A(θ)` and the caller's proposal correction. Moves do
not add evidence factors. Nonpositive move counts disable rejuvenation, and
nonpositive step counts still perform initialization and its resampling.
Nonpositive outer or inner particle counts return no particles, `-inf` evidence
and an empty output environment.

The final outer `smc2-result.log-evidence` is distinct from each
`smc2-particle.log-evidence`, which belongs to that particle's inner filter.
SMC² remains an explicit nested filtering algorithm here; it is not implemented
as a single generic RMSMC transformation.

## Custom parameter proposals and the shared MH loop

[`parameter-proposal<p>`](../lib/alg/parameter.kk) contains:

```koka
parameter      : p
parameter-env  : env
remaining-env  : env
log-correction : float64
```

`parameter-env` records generated parameter outputs. `remaining-env` is the
input stream after the **proposed** parameter-level computation has consumed
its observations. They serve different purposes.

The `-with` compatibility kernels have type
`p -> <div,random|e> (p,env,float64)` and reuse the retained post-prior cursor.
They therefore require a fixed prior observation-consumption pattern.
The `-with-state` kernels instead have type
`p -> <div,random|e> parameter-proposal<p>` and supply the proposed cursor.
They receive the current parameter, not an environment argument; the caller
must capture or reconstruct the data needed to compute that suffix. The
[usage guide](USAGE_GUIDE.md#sequential-models-and-custom-kernels) gives the public
contract and examples.

All three move algorithms use [`mh-chain`](../lib/alg/mcmc.kk). Its state is
`Scored(value, log-target)` and a proposal is
`Mh-candidate(proposed-state, log-correction)`. It accepts immediately if the
log ratio is nonnegative; otherwise it compares `ln(U)` to that ratio.
Rejection retains the entire old `Scored` value. A rejected state appears
again in the output after burn-in, preserving sample multiplicity.

`iterations` counts proposals; the initial state is not emitted before the
first proposal. `burnin` suppresses that many initial output positions.
`accepted` includes accepted burn-in proposals. Nonfinite retained scores are
not emitted, so output length may be smaller than `iterations − burnin` even
when that difference is positive. The routine is not a validation layer for
NaN or arbitrary infinite custom target/proposal scores. A finite proposal can
escape a `-inf` current state; `-inf − -inf` produces a nonaccepting NaN ratio.

## What the checks establish

The following source tests exercise these particular implementations and
contracts. Passing them is evidence for those cases, not a proof for arbitrary
models, handler orders or effects.

| Test file | Checks relevant to this reference |
| --- | --- |
| [Inference transformations](../tests/inference_transformations.kk) | Suspension and repeated resumption; population normalizers; variable checkpoint counts; reader cloning; proposed cursors; explicit nested evidence transfer. |
| [Checkpoint SMC](../tests/handler_smc_checks.kk) | No-checkpoint equivalence to weighted resampling; a finite joint posterior and evidence; retained scoped state; zero mass. |
| [Sequential observations](../tests/sequential_observations.kk) | Shared names across all stages; singleton exhaustion; conditional reads; retained cursors; online append versus batch execution. |
| [Incremental SMC](../tests/smc_incremental.kk) | Retained filters; initialization weights; persistent latent support under SMC². |
| [RMSMC composition](../tests/handler_composition_rmsmc.kk) | Prefix target consistency; nested isolation; rejection preserves the prefix. |
| [PMMH composition](../tests/handler_composition_pmmh.kk) | Rejection retains the cached noisy filter and draw multiplicity; nested LW/PMMH isolation. |
| [SMC² composition](../tests/handler_composition_smc2.kk) | Initial prior and state scores; unequal-prior proposal cancellation; impossible evidence; rejected filter retention; nested isolation. |
| [Joint posterior audit](../tests/inference_audit.kk) | Independent finite reference distributions for complete parameter/state paths and evidence. |
| [Small SIR posterior](../tests/sir_inference.kk) | SMC and custom PMMH/SMC² against exhaustive enumeration for a small discrete-parameter SIR target. |

Use `make test-handlers` for the composition checks and `make check` for the
complete registered suite. `make test-sir` runs the separate SIR checks.

The larger recorded SIR report still misses report-rate parameter-recovery
thresholds for PMMH and SMC² at its original budgets. Recovery distance from a
generating parameter is different from error against an exact posterior; those
misses do not alone prove an algorithm bug, and the small exact-posterior checks
do not establish adequate mixing on the larger model. See the unchanged
[recorded limitations](INFERENCE_AUDIT.md#known-empirical-limitation).
