[Docs](README.md) · [Composition guide](HANDLER_COMPOSITION.md) · [Supported scope](STATUS.md)

# Effects and handlers: implementation reference

An effect declares requests a computation can make. A handler gives those
requests an interpretation. In this library, requesting a Normal value does
not itself specify whether to sample it, read an observation, replay a trace,
or evaluate a density at a supplied coordinate.

This reference describes the implementation under `lib/`. Its equations state
the mathematical targets and the accounting performed by the code. They are
not a denotational correctness proof of the library. The linked tests check
particular laws, compositions and posterior targets; the
[support limits](STATUS.md) still apply.

The [comparison with the original Koka-Bayes thesis](PAPER_COMPARISON.md)
maps the earlier handlers to these interfaces and separates inherited design
ideas from later additions and unproved equivalence claims.

| Reference | Covers |
| --- | --- |
| This page | All effect declarations; observation, distribution, trace, sampling, replay and weight handlers |
| [Sequential handlers](SEQUENTIAL_HANDLERS.md) | Checkpoints, suspended continuations, populations, SMC, RMSMC, PMMH and SMC² |
| [Enumeration handlers](ENUMERATION_HANDLERS.md) | Finite branching, pruning, shared budgets and exact path weights |
| [Differentiation handlers](AD_HANDLERS.md) | Arithmetic primitives, forward/reverse AD and Normal-model interpretations |

## Reading the types

`(x : t) -> <effect-a,effect-b|e> r` is a function returning `r` that can
perform the listed effects and the residual row `e`. A handler usually removes
one effect and may introduce others. The row describes possible effects, not
their order of execution or a probability distribution.

On normal completion, a `fun` clause tail-resumes with its result. Its body
can perform other effects, including effects that branch or abort. A `ctl`
clause receives `resume`, which can be called, saved or omitted; some
handlers here call it multiple times. `return(x)` interprets normal completion
of the handled computation. `mask<F>` skips one enclosing handler for `F`
within its body; it does not suppress the operation. See the official
[Koka handler and masking documentation](https://koka-lang.github.io/koka/doc/book.html#sec-mask).

For example, the exact model alias in [core/model](../lib/core/model.kk) is:

```koka
pub alias model<e,a> = () -> <obs-reader,model-dist,div|e> a
```

It is a suspended computation returning `a`, with observation reads,
distribution requests and possible divergence. The alias is not a handler.
`dist`, `env`, `run-trace` and `sequential-model` are data types, not effects.

## Complete library effect inventory

There are eleven effect declarations in `lib/`, including the private
enumeration control effect. Test-only branching effects are not library APIs.

| Effect | Operations and results | Interpreter |
| --- | --- | --- |
| `obs-reader` | `fun read-observation(name : string) : maybe<observable>` | `handle-read-state` consumes the next datum for that name. |
| `model-dist` | `fun draw(dist : dist) : observable`; `fun draw-observable(name : string, dist : dist) : observable`; `fun factor(log-weight : float64) : ()` | `handle-dist` routes requests to hooks; enumeration uses a validating `exact-core`. |
| `sample-hook` | `fun sample-hook(name : maybe<string>, distribution : dist) : observable` | `handle-trace` assigns an address and requests a value. |
| `observe-hook` | `fun observe-hook(name : string, distribution : dist, value : observable) : observable` | `handle-trace` records and scores the supplied value. |
| `factor-hook` | `fun factor-hook(log-weight : float64) : ()` | `handle-trace` records an explicit factor and forwards its weight. |
| `sample-value` | `fun sample-value(address : int, distribution : dist) : observable` | `handle-sampling`, `handle-replay`, or enumeration's `finite-sampling`. |
| `accumulate-weight` | `fun accumulate-weight(log-weight : float64) : ()` | `handle-weight`, or enumeration's validating `exact-weight`. |
| `checkpoint` | `ctl checkpoint() : ()` | `suspend` captures the remaining computation; see [sequential handlers](SEQUENTIAL_HANDLERS.md). |
| `enumeration-control` — private | `ctl choose-finite(distribution : dist) : observable`; `ctl discard-branch() : ()`; `fun count-operation() : ()` | `explore` branches, prunes and charges work; see [enumeration handlers](ENUMERATION_HANDLERS.md). |
| `smooth<a>` | `fun constant(value : float64) : a`; `ctl apply-unary(op : unary-op, x : a) : a`; `ctl apply-binary(op : binary-op, x : a, y : a) : a` | `evaluate`, `forward`, or the private reverse handler; see [AD handlers](AD_HANDLERS.md). |
| `continuous<a>` | `fun normal-latent(mean : a, stddev : a) : a`; `fun normal-observed(name : string, mean : a, stddev : a) : a` | `probabilistic` or `log-joint`; see [AD model interpretations](AD_HANDLERS.md). |

Declarations are in [core/model](../lib/core/model.kk),
[handlers/trace](../lib/handlers/trace.kk), [handlers/weight](../lib/handlers/weight.kk),
[handlers/sequential](../lib/handlers/sequential.kk),
[handlers/enumerate](../lib/handlers/enumerate.kk),
[autodiff/smooth](../lib/autodiff/smooth.kk) and
[autodiff/model](../lib/autodiff/model.kk).

The library also uses Koka's `random`, `exn`, `div` and local state effects.
`pseudo-random(seed, action)` supplies seeded randomness in the public sampling
helpers. Enumeration instead installs a `random-int32` handler that throws
if the model requests untraced randomness. Reverse AD uses scoped references
under `run`. Those are standard-library facilities, not additional effects
declared by Koka Bayes. Arbitrary effects left in `e` need their own handlers;
type compatibility alone does not give them a valid inference interpretation.

## Mathematical target and the meaning of weight

Fix an observation environment and a terminating model with valid distribution
parameters. Let `Q` be the law of its latent execution when every unobserved
site draws from its declared distribution. A path `x` returns `r(x)` and
receives the likelihood/factor weight

$$
L(x)=\prod_{j\in\mathrm{observed}(x)}p_j(y_j\mid x)
      \prod_{k\in\mathrm{factors}(x)}\exp(\ell_k).
$$

Observation consumption and subsequent distributions may depend on the path.
The intended unnormalized result measure is

$$
\mu(A)=\int \mathbf{1}_{\{r(x)\in A\}} L(x)\,Q(dx),
\qquad Z=\int L(x)\,Q(dx).
$$

A posterior `μ(A)/Z` exists only when `0 < Z < ∞`. Continuous observations
contribute densities, so `Z` need not be a probability or lie below one.
These formulas assume the indicated products and integrals are defined;
arbitrary nontermination, side effects and nonfinite arithmetic are not covered.

There are three different quantities in the implementation:

| Quantity | Contains | Use |
| --- | --- | --- |
| `observed-log-prob(trace)` / ordinary `run-traced.log-weight` | Observed log densities plus explicit log factors | Likelihood weighting; the latent law `Q` is already represented by the sampling procedure. |
| `total-log-prob(trace)` | The above plus every sampled site's log mass/density | Joint trace accounting; it is not the ordinary importance weight. |
| `log-evidence` | Exact or estimated log normalizer, depending on the algorithm | Evidence reporting and explicit transfer into an enclosing inference layer. |

Finite enumeration sums `Q(x)L(x)` over discrete latent paths. It must include
latent masses explicitly because it visits each alternative instead of drawing
from `Q`. See the [enumeration equations](ENUMERATION_HANDLERS.md).

## Observation reading

Source: [handlers/read](../lib/handlers/read.kk), backed by
[core/env](../lib/core/env.kk).

```koka
pub fun handle-read-state(environment : env,
                         action : () -> <obs-reader|e> a) : e (a,env)
pub fun handle-read(environment : env,
                   action : () -> <obs-reader|e> a) : e a
```

`handle-read-state` initializes a scoped `current` environment. Each
`read-observation(name)` removes at most one element from that name's stream:

| Stream before the request | Result | Stream afterwards |
| --- | --- | --- |
| `[v] ++ rest` | `Just(v)` | `rest` |
| Empty or absent | `Nothing` | Empty or absent |

Other streams are unchanged. On normal completion it returns the model value
and the unconsumed environment. `handle-read` discards that second component.
Neither handler samples, records a trace or adds a score.

A singleton observation is consumed once; it is not a constant reused at
every occurrence. Streams count occurrences, not model time steps. Extra data
is left unread. Data names are strings: two `obsvar` values with the same name
refer to the same stream, even if constructed with different codecs. Use one
consistent observable type per name; the reader itself does no type checking.
See [observable codecs](../lib/core/obsvalue.kk).

The cursor is a scoped Koka `var` inside the computation being branched or
suspended. Tests check that separate continuation resumptions restore their
own cursor. This does not copy arbitrary caller-owned mutable references.

Checks: [nested and multi-shot observation reads](../tests/handler_multishot.kk),
[cross-stage consumption and online observations](../tests/sequential_observations.kk).

## Distribution routing and core composition

Source: [handlers/dist](../lib/handlers/dist.kk),
[handlers/core](../lib/handlers/core.kk), [model constructors](../lib/core/model.kk).

`handle-dist` removes `model-dist`. It requires `obs-reader` and leaves the
three hook effects, `div`, `random` and `e` available to enclosing handlers.
Its complete operation clauses are characterized by these rules:

| Request | Interpretation |
| --- | --- |
| `draw(d)` | Return `sample-hook(Nothing, d)`. |
| `draw-observable(name, d)` with next datum `v` | Consume it and return `observe-hook(name, d, v)`. |
| `draw-observable(name, d)` with no next datum | Return `sample-hook(Just(name), d)`. |
| `factor(l)` | Call `factor-hook(l)` and return unit. |
| Normal completion with `a` | Return `a` unchanged. |

The named distribution wrappers (`normal`, `bernoulli`, etc.) use
`draw-observable`; their primed variants (`normal'`, `bernoulli'`, etc.) use
`draw` and never consult the environment. Wrappers decode the returned
`observable` into the expected Koka type.

`handle-dist` itself does not sample or calculate a density. A missing named
datum becomes a latent site under ordinary inference. That can change the
model being inferred; it is not an automatic missing-data error.

`handle-core-state(environment, action)` composes an outer reader with an
inner distribution handler, returning `(a, remaining-env)`:

```text
handle-read-state(environment,
  handle-dist(action))
```

This is a nesting diagram, not executable Koka. The source includes the
necessary closures and masks. `handle-core` returns only `a`. Both eliminate
the model's reader/distribution interface and expose
`<sample-hook,observe-hook,factor-hook,div,random|e>`.
Their masks keep action-originating residual effects separate from the
internal interpretation; they are part of the composition, not optional
decoration when reproducing it.

## Factors and weight accumulation

Source: [core/model](../lib/core/model.kk) and
[handlers/weight](../lib/handlers/weight.kk).

`log-score(l)` calls `factor(l)`. `score(w)` checks that `w` is finite and
nonnegative, then uses `l = log(w)`, with zero mapped to negative infinity.
Weights above one are valid. `log-score` does not validate its argument on
entry: its supported domain is finite log weights or negative infinity.

```koka
pub fun handle-weight(action : () -> <accumulate-weight|e> a) : e (a,float64)
pub fun push-evidence(log-evidence : float64) : accumulate-weight ()
```

`handle-weight` starts a scoped accumulator at zero. Every
`accumulate-weight(l)` updates `W := W + l`; completion returns `(a, W)`.
The handler adds numbers without validating, normalizing or pruning. In
particular, a zero factor in ordinary LW sets the weight to `-inf` but does
not stop the rest of the model executing. Enumeration supplies a different,
pruning interpretation of this same effect.

`push-evidence(l)` is a forwarding helper that calls `accumulate-weight(l)`;
it does not calculate evidence or inspect an inner result. Nested weight
handlers retain separate totals. To use an inner estimate as an outer factor,
explicitly call `log-score(inner.log-evidence)` in the model interface, or
`push-evidence` in the lower-level weight interface. Its statistical validity
depends on the enclosing algorithm's contract.

For finite scores, the tested identities are:

$$
W(\mathrm{return}\ a)=0,\qquad
\exp(W(\mathrm{score}(u);\mathrm{score}(v)))=uv.
$$

For example, an outer factor `0.4` and an inner factor `0.25` leave outer
weight `0.4` and inner weight `0.25`. Explicitly passing the inner evidence
outward changes the outer weight to `0.1`. It must be passed once, not once
per inner particle. Floating-point regrouping need not preserve exact bits.

Checks: [weight identity, multiplication, nesting and evidence transfer](../tests/handler_laws.kk).

## Trace construction

Source: [handlers/trace](../lib/handlers/trace.kk) and
[core/trace](../lib/core/trace.kk).

`handle-trace` handles `sample-hook`, `observe-hook` and `factor-hook`,
returning `(a, run-trace)`. It leaves `sample-value`, `accumulate-weight`,
`div` and `e`. Its scoped state is an integer address initially zero and an
initially empty list of entries.

| Hook | Value and trace action | Weight action |
| --- | --- | --- |
| Sample `(name, d)` | Request `sample-value(address, d)`; append a `TraceSampled` entry with that value and `log-prob(d, value)`; increment address; return value. | None. |
| Observe `(name, d, value)` | Append a `TraceObserved` entry, increment address and return the supplied value. | Add `log-prob(d, value)`. |
| Factor `l` | Append a `TraceFactor` entry, increment address and return unit. | Add `l`. |

Addresses count **all** distribution and factor occurrences in execution
order, starting at zero. They are not names or stable source locations. A
factor at address zero makes the next sample's address one. A different
control-flow path can have different addresses and trace length.

`trace-entry` stores `address`, a distribution-summary `site` string,
an optional observation name, the tagged `value`, `log-prob`, and `mode`.
The summary string is diagnostic information, not a replay compatibility key.
Factors store their log weight as the value, have site `"factor"` and no name.

`sampled-addresses` and `sample-count` include only `TraceSampled` entries.
`to-output-env` collects named sampled and observed entries in order. It
excludes anonymous samples and factors. This output is distinct from the
reader's unconsumed input environment.

Checks: [factor addressing and sample selection](../tests/handler_laws.kk),
[trace isolation under repeated resumptions](../tests/handler_multishot.kk).

## Sampling and replay

Both handlers in [handlers/trace](../lib/handlers/trace.kk) remove
`sample-value` and return the action's value, leaving `<div,random|e>`.

`handle-sampling` ignores the address and calls `sample(distribution)` at
each request. Sampling uses [core/dist](../lib/core/dist.kk) and the enclosing
random handler.

`handle-replay(previous, proposal, action)` maintains a scoped Boolean
`diverged`, initially false:

| Condition at `sample-value(address, d)` | Action |
| --- | --- |
| Already diverged | Draw from the current `d`. |
| `proposal = Just(j)` and `address >= j` | Set diverged and draw from `d`. |
| `proposal = Just(j)`, `address < j`, and previous sampled value exists there | Reuse that value. |
| `proposal = Just(j)`, `address < j`, but no previous sampled value exists | Set diverged and draw from `d`. |
| `proposal = Nothing` and previous sampled value exists there | Reuse that value. |
| `proposal = Nothing` but no previous sampled value exists | Draw from `d`; this case does not set diverged. |

Every reused value is scored in the newly constructed trace under the current
distribution. Replay does not compare distribution-summary strings, validate
source-site identity, reuse old observation values, or copy old factors.
Observation requests and factors execute again against the supplied environment.
With an empty previous trace and no proposal, replay performs fresh sampling.

The internal MH caller selects an actual sampled address. Its intended
proposal keeps the deterministic prefix and regenerates the selected latent
site and all subsequent latent sites. Raw randomness or externally changing
state that affects the prefix violates this replay contract.

For that prior-regeneration proposal, the implementation uses

$$
\log\alpha=\min\left(0,\log L(x')-\log L(x)
                         +\log n(x)-\log n(x')\right),
$$

where `n` counts latent sites. Sampled prior densities cancel against the
forward/reverse proposal densities; inserting `total-log-prob` in place of
`log L` would count them twice. The implementation guards zero counts with
`max(1, n)` and handles observation/factor-only executions without choosing
a site. This equation explains the implemented proposal, not arbitrary replay
kernels. See [alg/mh](../lib/alg/mh.kk) and its
[prior-cancellation and variable-length regressions](../tests/inference_regressions.kk).

## The complete ordinary execution stack

`run-traced` is the assembly point:

```koka
pub fun run-traced(environment : env, action : model<e,a>,
                   previous : run-trace = [], proposal : maybe<int> = Nothing)
                   : <div,random|e> traced-result<a>
```

The actual nesting, outermost first, is:

```text
handle-weight
  handle-replay(previous, proposal)
    handle-trace
      handle-core-state(environment)
        handle-read-state(environment)
          handle-dist
            action
```

`handle-core-state` is the composite wrapper around the next two handlers;
it does not install a second reader. The diagram omits closures and masks.
The returned record contains `value`, `trace`, `log-weight` and `remaining-env`.
All ordinary internal model effects have been handled; random draws and any
residual effects still belong to enclosing handlers.

| Entry point | How it uses this stack |
| --- | --- |
| `simulate` / `simulate-state` | Return the value, trace and named output environment; the state form also returns unread input. Simulation alone does not normalize or condition its draws. |
| `run-lw` / `run-lw-state` | Also return the accumulated likelihood/factor weight. |
| `lw` | Repeat fresh executions from the same original input environment. |
| `lwis` | Normalize LW weights and resample equally weighted values. |
| `mh` | Re-run the stack with a selected replay address, then accept or retain a complete trace. |

These are algorithms or wrappers built from handlers, not additional effect
declarations. Sources: [simulate](../lib/alg/simulate.kk),
[LW](../lib/alg/lw.kk), [LWIS](../lib/alg/lwis.kk), [MH](../lib/alg/mh.kk).

### A complete execution, numerically

In the [alarm example](../examples/exact_inference.kk), let `faulty` be a
Bernoulli(0.3) latent, and observe an alarm with probabilities 0.8 when faulty
and 0.2 otherwise. Supply the environment containing `alarm = [True]`.

| Step | Faulty path | Healthy path |
| --- | --- | --- |
| `bernoulli'(0.3)` | Address 0, sampled `True`, log prior `log(0.3)` | Address 0, sampled `False`, log prior `log(0.7)` |
| Named alarm request | Reader consumes `True`; address 1 observes it | Reader consumes `True`; address 1 observes it |
| Ordinary LW weight | `0.8` | `0.2` |
| Joint path mass for enumeration | `0.3 × 0.8 = 0.24` | `0.7 × 0.2 = 0.14` |

Both paths consume the input exactly once. Enumeration obtains evidence
`0.38` and posterior fault probability `0.24 / 0.38 = 12/19`. LW draws the
faulty path with prior probability `0.3` and weights it by `0.8`; multiplying
by `0.3` again in its importance weight would change the target.

## Failure behavior and caller obligations

Validation differs by layer; not every handler throws on invalid data.

| Input or condition | Current behavior |
| --- | --- |
| Negative, NaN or infinite ordinary `score` | `score` throws. |
| NaN or positive-infinite `log-score` | Forwarded by ordinary handlers; invalid for supported inference. Enumeration throws. |
| Invalid distribution requested for sampling | `sample` calls `impossible`; this is not a recoverable validation result. Enumeration validates and throws first. |
| Invalid distribution or nonfinite numeric observation scored by `log-prob` | Returns `-inf`. Ordinary observed routing does not separately validate distribution parameters. |
| Mismatched observable type | `log-prob` gives zero mass, but a typed model wrapper may then call `impossible` while decoding it. Keep names and codecs consistent. |
| Valid density with a singular endpoint giving `+inf` | Outside the finite-weight normalization contract; enumeration rejects the contribution. |
| Empty, all-`-inf`, NaN-containing or `+inf`-containing weight list | `normalized-log-weights` returns `Nothing`; resampling returns no particles. It does not invent uniform mass. |
| Invalid mass supplied to `weighted/posterior-mean` | Throws; `draws/posterior-mean` only sees values and instead rejects empty lists or a nonfinite mean. |
| Enumeration query on an empty outcome set | Throws: there is no posterior to normalize. Low-level inference results can contain empty lists or `-inf` evidence. |
| Untraced random calls | Ordinary execution can perform them, but replay/exactness contracts do not account for them; enumeration rejects calls reaching its random guard. |
| External I/O or shared references in a multi-shot computation | Effects retain their enclosing interpretation; repetition/isolation is the caller's responsibility. |

Sources: [distributions](../lib/core/dist.kk), [weight normalization](../lib/core/weights.kk),
[public summaries](../lib/bayes.kk), [enumeration](../lib/handlers/enumerate.kk).

## Which compositions are established here?

The implementation tests observation, trace and weight isolation under
multi-shot handlers; explicit nested evidence transfer; checkpoint SMC;
finite enumeration; and continuous-model interpretation followed by AD.
The specific stacks and state placement are part of these contracts.

For example, moving a weight handler outside a branching handler can share
an accumulator across alternatives instead of yielding a separate weight
for each path. Moving an observation cursor out of the captured computation
can make one branch consume another's data. Effect rows do not certify that
such changes preserve the intended posterior.

RMSMC, PMMH and SMC² retain dedicated algorithm loops and further target,
proposal and retained-state obligations; see [sequential handlers](SEQUENTIAL_HANDLERS.md).
The AD adapter differentiates a deterministic log density; it does not
differentiate posterior estimates or the sampler; see [AD handlers](AD_HANDLERS.md).

## Verification map

| Contract | Existing checks |
| --- | --- |
| Factor identity, multiplication, isolation and transfer | [handler_laws.kk](../tests/handler_laws.kk) |
| Branch-local cursors, traces and weights in both resumption orders | [handler_multishot.kk](../tests/handler_multishot.kk) |
| Consumption across prior, initial state and steps | [sequential_observations.kk](../tests/sequential_observations.kk) |
| Nested inference and MH prior/site-count accounting | [inference_regressions.kk](../tests/inference_regressions.kk) |
| Independently computed joint posteriors and custom kernels | [inference_audit.kk](../tests/inference_audit.kk) |
| Suspension, population and explicit evidence transfer | [inference_transformations.kk](../tests/inference_transformations.kk) |
| Finite path weights and enumeration failure cases | [enumeration_checks.kk](../tests/enumeration_checks.kk) |
| Primitive derivatives and model-to-density interpretation | [autodiff_checks.kk](../tests/autodiff_checks.kk), [differentiable_model.kk](../tests/differentiable_model.kk) |

```sh
make test-handlers
make test-enumerate
make test-autodiff
make check
```

The first three target specific layers. `make check` includes them and the
inference benchmarks, model matrices, SIR checks and examples. A passing run
is evidence for those checks, not a proof of arbitrary handler composition
or reliable recovery on every model. The [recorded SIR limitations](INFERENCE_AUDIT.md#known-empirical-limitation)
remain visible independently of this reference.
