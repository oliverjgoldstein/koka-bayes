[Docs](README.md) · [Effects and handlers](EFFECTS_AND_HANDLERS.md) · [AD tutorial](AUTODIFF.md) · [Gradient inference](GRADIENT_INFERENCE.md)

# Differentiation effects and handlers

The AD interface separates an arithmetic program from its interpretation. A
program requests `smooth<a>` operations; an interpreter chooses whether `a`
means an ordinary number, a number with a tangent, or a number with an adjoint
cell. A second effect, `continuous<a>`, describes Normal model sites. Its
`log-joint` handler translates those sites into arithmetic that AD can interpret.

This reference specifies the implementation in `lib/autodiff`. Equations give
the intended real-number semantics on differentiable domains. The code uses
`float64`, and its tests establish particular values, derivatives and integration
behaviors. There is no formal correctness theorem for this implementation,
arbitrary effects, or the whole Koka language; it does not inherit CHAD's proofs.
The [status page](STATUS.md) describes the wider limits.

## Reading the signatures

In `() -> <smooth<a>|e> r`, the computation returns `r`, can perform
`smooth<a>`, and can have residual effects `e`. Handling `smooth<a>` removes
that effect; it does not automatically interpret `e`. An effect variable `e`
is different from the result type `a` of an arithmetic operation.

An operation declared `fun` supplies a value directly through an ordinary
handler clause. The `ctl` arithmetic operations allow a handler to capture the
continuation. Evaluation and forward mode implement them with `fun` clauses;
reverse mode uses `ctl` clauses and explicitly calls `resume` once. There is no
branching or continuation duplication in the AD handlers.

| Interpreter | Input action or objective | Result and remaining effects |
| --- | --- | --- |
| `evaluate` | `() -> <smooth<float64>\|e> r` | `e r` |
| `forward` | `() -> <smooth<dual>\|e> r` | `e r` |
| `value-and-derivative` | `dual -> smooth<dual> dual`, and one `float64` input | Pure `dual` |
| Private `reverse-handler` | `() -> <smooth<reverse-value<h>>,st<h>> reverse-value<h>` | `st<h> float64` |
| `value-and-grad` | `forall<a> list<a> -> smooth<a> a`, and `list<float64>` inputs | Pure `gradient` |
| `probabilistic` | `() -> <continuous<float64>,smooth<float64>\|e> r` | `model<e,r>`: a suspended `() -> <obs-reader,model-dist,div\|e> r` |
| `log-joint` | `() -> <continuous<a>,smooth<a>> r`, coordinates and observations | `smooth<a> a` |

These signatures are from [smooth](../lib/autodiff/smooth.kk#L88),
[forward](../lib/autodiff/forward.kk#L11),
[reverse](../lib/autodiff/reverse.kk#L16), and
[model](../lib/autodiff/model.kk#L17). `probabilistic` returns an action, so
constructing it alone does not draw a sample.

## `smooth<a>`: operations and local rules

The entire effect declaration is:

```koka
pub effect smooth<a>
  fun constant(value : float64) : a
  ctl apply-unary(op : unary-op, x : a) : a
  ctl apply-binary(op : binary-op, x : a, y : a) : a
```

`ad-constant`, the unary `ad-*` functions and the binary `ad-*` functions are
thin wrappers over these three operations. An objective must use them for
arithmetic that participates in AD; ordinary `float64` arithmetic is not
intercepted. Lift fixed numbers into `a` with `ad-constant`.

For a primitive output `z`, the handlers use these shared primal and local
derivative rules:

| Wrapper / operation | Primal `z` | Local derivative(s) | Real domain |
| --- | --- | --- | --- |
| `ad-constant(c)` / `constant` | `c` | Zero with respect to objective inputs | Finite `c` for ordinary smooth targets |
| `ad-negate(x)` / `Negate` | `−x` | `∂z/∂x = −1` | All real `x` |
| `ad-exp(x)` / `Exponential` | `exp(x)` | `∂z/∂x = exp(x)` | All real `x` |
| `ad-log(x)` / `Logarithm` | `ln(x)` | `∂z/∂x = 1/x` | `x > 0` |
| `ad-sin(x)` / `Sine` | `sin(x)` | `∂z/∂x = cos(x)` | All real `x` |
| `ad-cos(x)` / `Cosine` | `cos(x)` | `∂z/∂x = −sin(x)` | All real `x` |
| `ad-add(x,y)` / `Add` | `x+y` | `(∂z/∂x, ∂z/∂y) = (1,1)` | All real `x,y` |
| `ad-sub(x,y)` / `Subtract` | `x−y` | `(1,−1)` | All real `x,y` |
| `ad-mul(x,y)` / `Multiply` | `xy` | `(y,x)` | All real `x,y` |
| `ad-div(x,y)` / `Divide` | `x/y` | `(1/y, −(x/y)/y)` | `y ≠ 0` |

The division partial is evaluated as `−(x/y)/y`, rather than forming `y*y`:
squaring a very large or small `y` can overflow or underflow even when the
partial itself is representable. This is one numerical improvement, not a
general stability guarantee. The rule definitions are in
[smooth.kk](../lib/autodiff/smooth.kk#L57).

Two public helpers are compositions, with no extra effect operation or handler
clause:

| Helper | Definition and derivative contract |
| --- | --- |
| `ad-square(x)` | Calls `ad-mul(x,x)`; derivative `2x`. Both operand contributions must accumulate into the same input. |
| `ad-normal-log-density(x,mean,stddev)` | Returns the normalized Normal log density below; all three arguments can be differentiated. Requires `stddev > 0`. |

Writing `μ = mean`, `σ = stddev`, the Normal helper implements

```text
L(x, μ, σ) = −½ log(2π) − log(σ) − ½ ((x−μ)/σ)²
∂L/∂x = −(x−μ)/σ²
∂L/∂μ =  (x−μ)/σ²
∂L/∂σ = −1/σ + (x−μ)²/σ³
```

These derivatives follow from the primitive rules, rather than being registered
separately. See [the helper](../lib/autodiff/smooth.kk#L95) and
[three-argument derivative checks](../tests/autodiff_checks.kk#L98).

## `evaluate`: ordinary arithmetic

`evaluate` handles `constant` by returning its argument, and unary/binary
operations by calling `unary-value`/`binary-value`. Its return clause passes
through the action's result unchanged. It introduces no AD state and computes
no derivatives.

It can return any result type `r`, not only a number, and preserves residual
effects `e`. Being accepted by this interpreter does not imply that the same
action fits the more restrictive `value-and-grad` interface.

Source: [evaluate](../lib/autodiff/smooth.kk#L88).

## `forward`: values and directional derivatives

A `dual` contains two `float64` fields, `primal` and `tangent`. The caller seeds
each input with a direction: `Dual(xᵢ,vᵢ)`. For a scalar objective `f`, the
output is intended to be `(f(x), ∇f(x)·v)`.

Each handler clause returns a new pair immediately:

```text
constant(c)       ↦ (c, 0)
unary u(x, ẋ)    ↦ (u(x), u′(x) ẋ)
binary b(x, y)   ↦ (b(x,y), ∂₁b(x,y) ẋ + ∂₂b(x,y) ẏ)
```

There is no mutable derivative state or backward traversal. `forward`'s return
clause preserves the result, which may contain several dual values if the
action returns them. A single execution carries one tangent direction;
`value-and-derivative(f,x)` specializes it to one input and seeds tangent `1`.

Source: [forward.kk](../lib/autodiff/forward.kk). Checks include a non-coordinate
direction `(2,−1)` in [the shared-expression test](../tests/autodiff_checks.kk#L79).

## Reverse mode: continuations and scoped adjoints

A `reverse-value<h>` consists of a `float64` primal and a mutable
`ref<h,float64>` adjoint. An adjoint is the accumulated contribution to the
derivative of the final scalar output with respect to that value.
`reverse-handler` is private; callers use `value-and-grad`.

For each unary or binary operation, the handler:

1. Computes the primal and allocates an output adjoint initialized to zero.
2. Calls `resume(output)` to run the rest of the objective under the handler.
3. After the continuation returns, reads the accumulated output adjoint.
4. Adds a local derivative times that adjoint into each operand's cell.

For an operation `z = b(x,y)`, the updates are

```text
x̄ ← x̄ + ∂₁b(x,y) z̄
ȳ ← ȳ + ∂₂b(x,y) z̄
```

The return clause seeds the final output's adjoint with `1` and returns its
primal. The suspended operation clauses then unwind in reverse execution
order. Thus continuations hold the work needed for the reverse pass; there is
no separate list of tape instructions.

Both binary updates reread their destination cell. This matters for `x*x`,
where `x` and `y` are the same reference: the second contribution must add to
the first. Shared intermediate values similarly collect contributions from
all their later uses. Constants receive a zero-initialized cell but have no
parents to which they propagate.

`value-and-grad` wraps the whole computation in `run`. It allocates a fresh
input cell for every list element, calls the private handler, then reads the
input cells **after** reverse propagation has completed. It returns
`Gradient(value, partials)` in the original input order. Only ordinary numbers
escape; the references are scoped to that invocation. Unused inputs keep zero
adjoints, an identity objective returns derivative one, and a constant
objective can accept an empty input list.

The actual objective type is deliberately restricted:

```koka
forall<a> list<a> -> smooth<a> a
```

It returns one scalar and has no residual effect row. In particular, the public
wrapper does not accept a random sampler, arbitrary mutable state or another
unhandled model effect. Functions and structural traversals may compose inside
that objective while their arithmetic remains in `smooth<a>`.

Source: [reverse.kk](../lib/autodiff/reverse.kk). The aliasing and isolation
checks are [shared expressions](../tests/autodiff_checks.kk#L79) and
[constants, identity and repeated calls](../tests/autodiff_checks.kk#L147).
Continuations and cells grow with executed arithmetic; large-program storage
and stack behavior have not been benchmarked.

## Worked arithmetic example

This is the objective used in [the AD checks](../tests/autodiff_checks.kk#L14):

```koka
fun polynomial(xs : list<a>) : smooth<a> a
  match xs
    Cons(x, Cons(y, _)) ->
      ad-add(ad-constant(1.0),
        ad-sub(ad-mul(ad-square(x), x), ad-square(y)))
    _ -> ad-constant(0.0)
```

It represents `f(x,y)=1+x³−y²`. At `(2,4)`, evaluation gives `−7`;
forward seeds `[Dual(2,1),Dual(4,0)]` give tangent `12`; reverse mode returns
`Gradient(−7,[12,−8])`.

To see the reverse accumulation, write `u=x*x`, `v=u*x`, `w=y*y` and
`f=1+v−w`. The seed gives `v̄=1` and `w̄=−1`. Unwinding `w=y*y` adds
`y*w̄=−4` twice to `ȳ`, making `−8`. The product `v=u*x` then contributes
`ū=x=2` and `x̄=u=4`. Finally, unwinding `u=x*x` adds `x*ū=4` twice to
`x̄`, making `12`.

Run the complete [three-interpreter example](../examples/differentiation.kk):

```sh
make inference MODEL=examples/differentiation.kk
```

## `continuous<a>`: Normal model operations

The model effect has exactly two operations:

```koka
pub effect continuous<a>
  fun normal-latent(mean : a, stddev : a) : a
  fun normal-observed(name : string, mean : a, stddev : a) : a
```

The interface records a model site and its parameters; it does not itself
choose sampling or density evaluation. `normal-latent` has no address/name:
the density interpretation identifies latents by execution order.
`normal-observed` names an observation stream, and repeated names use successive
entries. Both require a positive standard deviation for their mathematical
Normal interpretation. See [model.kk](../lib/autodiff/model.kk#L10).

### `probabilistic`: translate into the ordinary model API

This adapter specializes `a` to `float64`. Inside the returned action,
`evaluate` interprets arithmetic and a `continuous` handler translates sites:

| Continuous operation | Ordinary model operation |
| --- | --- |
| `normal-latent(mean,stddev)` | `normal'(mean,stddev)`, an unnamed latent draw |
| `normal-observed(name,mean,stddev)` | `normal(obs-float64(name),mean,stddev)`, a named observable draw |
| Returning `r` | Return the same `r` |

The adapter uses `mask<obs-reader>`, `mask<div>` and `mask<model-dist>` around
its nested action as shown in [the source](../lib/autodiff/model.kk#L17). These
are effect scoping operations; they are not sampling or scoring handlers.
Ordinary model execution and the chosen inference handlers still supply those
interpretations. See the [general effect reference](EFFECTS_AND_HANDLERS.md).

With ordinary likelihood weighting, supplied observations contribute likelihood
weights and unavailable observations are sampled. This is the existing model
API's behavior; the adapter does not require complete observation data. The
resulting model is checked against a hand-written ordinary model for identical
seeded draws and weights in
[differentiable_model.kk](../tests/differentiable_model.kk#L65).

### `log-joint`: translate into differentiable arithmetic

`log-joint` accepts coordinates of type `list<a>` and an observation `env`.
Every call creates its own remaining-coordinate list, observation cursor,
validity flag, and accumulated score initialized to `ad-constant(0)`.
Its handler behaves as follows:

| Operation or return | Coordinate/data update | Score and operation result |
| --- | --- | --- |
| `normal-latent(μ,σ)` with a coordinate | Consume the next coordinate `x` | Add `L(x,μ,σ)`; return `x` |
| `normal-latent(μ,σ)` without a coordinate | Mark invalid; use placeholder `ad-constant(0)` | Continue the model with the placeholder |
| `normal-observed(name,μ,σ)` with a float observation | Consume the next item from that name's stream; lift it with `ad-constant` | Add `L(y,μ,σ)`; return the lifted observation |
| Missing, exhausted, or non-float observation | Mark invalid; use placeholder `ad-constant(0)` | Continue the model with the placeholder |
| Model return | The model's own result is discarded | Return the accumulated score only if valid and all coordinates were consumed; otherwise return `ad-constant(neginf)` |

Even an invalid site's placeholder participates in the intermediate density
calculation; invalidity is checked at the end. The intended observable failure
is the final `−∞` score, not a useful gradient. Callers must check the score
instead of interpreting returned partials from an invalid evaluation.

Coordinate count must match exactly. **Unused observations are allowed**:
there is no end-of-call check that every supplied observation was consumed.
Observations are consumed by name and occurrence, using
[maybe-consume-name](../lib/core/env.kk#L62). A fresh invocation starts from the
original supplied environment, so repeated AD evaluations do not share a
consumption cursor.

This produces the full unnormalized posterior log density in latent
coordinates: every latent Normal density plus every observed Normal density.
For fixed data `y`, its intended target is

```text
ℓ(z; y) = Σ latent sites log Normal(zᵢ; μᵢ(z,y), σᵢ(z,y))
        + Σ observed sites log Normal(yⱼ; μⱼ(z,y), σⱼ(z,y)).
```

Normal normalization terms are retained. There is no posterior normalizing
constant computation. Observations are constants under this handler, although
the standalone `ad-normal-log-density` helper can differentiate an observation
argument when explicitly supplied as an AD input.

Source: [log-joint](../lib/autodiff/model.kk#L31). Exact scores, observation
consumption, missing/wrong data and coordinate mismatch tests are in
[test-log-joint](../tests/differentiable_model.kk#L44).

## Composition with probabilistic inference

The supported handler order is model interpretation **inside** arithmetic
interpretation:

```text
continuous<a> + smooth<a> program
  ├─ probabilistic: translate sites to core/model and evaluate arithmetic
  │    └─ ordinary probabilistic inference handles the resulting model
  └─ log-joint: bind coordinates, consume observations, accumulate smooth score
       └─ evaluate / forward / value-and-grad interprets the arithmetic
            └─ HMC or MALA uses numeric scores and gradients
```

`log-joint` must interpret the model sites so that the objective passed to
`value-and-grad` has only `smooth<a>`. Handler order is meaningful: these
interpreters are not claimed to commute, and the result does not differentiate
the ordinary probabilistic interpreter or a sampler.

For example, [the adapter test](../tests/differentiable_model.kk#L20) uses
`θ ~ Normal(0,1)` with two observations `1` and `2` from `Normal(θ,1)`.
Its joint score and derivative are

```text
ℓ(θ) = −3/2 log(2π) − 1/2 [θ² + (1−θ)² + (2−θ)²]
ℓ′(θ) = 3 − 3θ.
```

At `θ=0.25`, the score is `−1.5 log(2π)−1.84375`, the reverse derivative is
`2.25`, and a forward seed of `2` produces tangent `4.5`. Under
`probabilistic`, the same model instead supplies draws and weights to
likelihood weighting. Its analytic posterior is `Normal(1, sqrt(1/3))`.
These are two interpretations of a shared model body.

HMC/MALA call [evaluate-target](../lib/alg/gradient.kk#L24), which invokes
`value-and-grad` and caches the position, score and gradient together. The
samplers require nonempty finite coordinates and finite scores/partials; an
invalid initial state throws, and invalid proposals are rejected. Rejection
retains the previous state and its cached score/gradient. Details of the
gradient proposals and their Metropolis corrections are in
[gradient inference](GRADIENT_INFERENCE.md) and the
[HMC](../lib/alg/hmc.kk)/[MALA](../lib/alg/mala.kk) sources.

## Domains, unsupported combinations and evidence

The primitive handlers do not validate domains or throw explicit domain
exceptions. Invalid logarithms, zero divisors and overflowing arithmetic can
produce IEEE NaNs or infinities. The Normal adapter does not add a separate
standard-deviation check. Stay in the stated domains and require finite
results; the gradient samplers reject nonfinite target states, but direct AD
callers must inspect their own results.

The implemented differentiation boundary has these limits:

- Scalar `float64` first derivatives; no Hessians, nested AD, tensors, GPU
  kernels, AD checkpointing or custom derivative registration.
- Generic AD values have no comparison operation. Structural control flow is
  usable; value-dependent branching on `a` is not supplied by this interface.
- The continuous adapter has only scalar Normal sites. It does not translate
  arbitrary `core/model` programs, discrete sites or general factors.
- Gradient sampling requires a fixed number and interpretation of coordinates.
  The adapter checks count, but has no latent-address schema that can detect a
  same-length reordering of sites. Keep site count and order fixed yourself.
- Constrained targets need manually written transformations and log-Jacobians.
  Sampling, resampling, finite enumeration weights and inferred expectations
  have no AD rules here.
- The public reverse wrapper exposes no residual effect row. Arbitrary handler
  composition and differentiating other inference algorithms are outside its
  implemented contract.

| Evidence | What it checks |
| --- | --- |
| [autodiff_checks.kk](../tests/autodiff_checks.kk) | Analytic primitives and polynomial gradients, sharing, Normal derivatives, extreme division scales, directional derivatives, independent finite differences, identity/constants and per-call isolation |
| [differentiable_model.kk](../tests/differentiable_model.kk) | Normalized log joints, all four hierarchical temperature derivatives, data/coordinate mismatch behavior, and identical seeded draws/weights against ordinary model implementations |
| [gradient_samplers.kk](../tests/gradient_samplers.kk) | Target validation, deterministic HMC/MALA equations, proposal correction, rejection retention, reproducibility and fixed-budget Gaussian posterior comparisons |
| [gradient_examples.kk](../tests/gradient_examples.kk) | Separate thermometer, regression and logistic-intercept posterior examples, with benchmark-specific tolerances |

The main AD analytic tolerance is `1e-10 * max(1,abs(expected))`; its independent
central-difference check uses `1e-8`. Finite examples and tolerances provide
implementation evidence, not a proof over all programs, numerical inputs or
posterior geometries.

```sh
make test-autodiff          # Arithmetic interpreters
./bayes differentiable-model # Continuous-model adapter
make test-hmc              # HMC equations, validation and Gaussian runs
make test-mala             # MALA equations, validation and Gaussian runs
```

`make check` includes these checks and the broader examples. On Windows,
replace `./bayes` with `.\bayes.cmd`. For a smaller introduction, return to
[differentiate a Koka program](AUTODIFF.md).
