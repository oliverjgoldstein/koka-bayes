[Docs](README.md) · [Get started](USAGE_GUIDE.md)

<a id="automatic-differentiation-with-handlers"></a>

# Differentiate a Koka program

Write arithmetic with `ad-*` operations, then choose an evaluation, forward or
reverse handler. This library computes scalar first derivatives using `float64`
on Koka 3.2.3.

For `f(x,y) = 1 + x³ − y²`:

```koka
import std/num/float64
import autodiff/smooth
import autodiff/reverse

fun objective(xs : list<a>) : smooth<a> a
  match xs
    Cons(x, Cons(y, _)) ->
      ad-add(ad-constant(1.0), ad-sub(ad-mul(ad-square(x), x), ad-square(y)))
    _ -> ad-constant(0.0)

pub fun main()
  val result = value-and-grad(objective, [2.0, 4.0])
  println(result.value.show)     // -7
  println(result.partials.show)  // [12, -8]
```

Run the [example showing all three handlers](../examples/differentiation.kk):

```sh
make inference MODEL=examples/differentiation.kk
```

## API

| Module | Use |
| --- | --- |
| [smooth](../lib/autodiff/smooth.kk) | `ad-*` arithmetic and `evaluate` for ordinary values. |
| [forward](../lib/autodiff/forward.kk) | `forward` with `Dual(value,tangent)` for a directional derivative; `value-and-derivative` seeds tangent one. |
| [reverse](../lib/autodiff/reverse.kk) | `value-and-grad` returns the value and input partials in order, including zeros for unused inputs. |
| [model](../lib/autodiff/model.kk) | Interpret Normal-site programs as probabilistic models or differentiable joint densities. |

Primitives cover constants, `+`, `−`, `×`, division, negation, `exp`, `log`,
`sin` and `cos`. `ad-square` and `ad-normal-log-density` combine those primitives.
Keep the objective polymorphic in `a` so handlers can see its arithmetic.

For a probabilistic example, [differentiate the temperature model](TEMPERATURE.md).
For posterior sampling with gradients, use [HMC or MALA](GRADIENT_INFERENCE.md).

<a id="implementation"></a>
<details>
<summary>How the handlers work</summary>

The effect boundary has three operations:

```koka
pub effect smooth<a>
  fun constant(value : float64) : a
  ctl apply-unary(op : unary-op, x : a) : a
  ctl apply-binary(op : binary-op, x : a, y : a) : a
```

Each operation supplies its value and local derivative rule. `evaluate` computes
values; forward mode carries values and tangents through the chain rule.
Reverse mode pairs each value with a scoped derivative cell (`reverse-value<h>`).
Its `ctl` clauses resume the rest of the computation, then add derivative
contributions as continuations return. `value-and-grad` seeds the output with one.

Koka's deep handlers handle subsequent operations after `resume`. Contributions
from both operands accumulate, including `x*x` and shared intermediates. Every
reverse call owns its references through `run`; there is no global AD state.

</details>

<a id="compositionality"></a>
<details>
<summary>Composing functions and probabilistic models</summary>

Functions using `smooth<a>` can call each other, capture values in closures and
traverse structural data. Their derivatives combine by the chain rule. In the
temperature example, a fold sums separate reading scores and the prior; all
contributions to the shared temperature accumulate. Normal log density itself
uses ordinary AD arithmetic and logarithms, with no special handler clause.

One objective works under evaluation, forward and reverse handlers. This allows
higher-order code organization, while the gradient API still accepts scalar
inputs and a scalar output, not function-valued inputs. The Normal-model adapter
interprets its model operations into `smooth<a>` before AD. This is a supported
composition, not arbitrary-effect or nested differentiation.

</details>

<a id="scope-and-limits"></a>
<details>
<summary>Current limits</summary>

- Scalar first derivatives only: no tensors, GPU kernels, Hessians, nested AD,
  AD checkpointing or custom derivative registration.
- Reverse mode retains continuations and derivative cells. Time and storage
  grow with executed operations; large-program performance and stack limits
  have not been benchmarked.
- Inputs must be in each operation's differentiable domain: positive log
  arguments and Normal standard deviations, and nonzero divisors. IEEE overflow,
  infinities and NaNs are not repaired.
- `value-and-grad` objectives have only `smooth<a>` effects. Ordinary arithmetic,
  randomness and existing `core/model` operations are not differentiated
  automatically. Lift fixed data with `ad-constant`; new `continuous<a>`
  Normal-site models can first use `log-joint`.
- There is no comparison operation on generic AD values. Structural control
  flow is supported; branching on AD values is outside this API.
- HMC/MALA need smooth continuous targets and manual settings. There is no NUTS,
  variational inference, differentiation through discrete sampling/resampling,
  or claim of whole-language differentiation.

Tests cover these implemented behaviors, not a formal whole-language theorem,
performance leadership or inference correctness beyond the separate inference checks.

</details>

<a id="verification-and-probabilistic-example"></a>
<details>
<summary>Tests and the temperature example</summary>

```sh
make test-autodiff
make inference MODEL=examples/autodiff.kk
```

Analytic checks cover the polynomial; shared/repeated operands; every primitive;
large/small division scales (`1e200`, `1e-200`); normalized Normal density
(including observation, mean and scale derivatives); the conjugate Normal model;
temperature folds; constants, unused/empty inputs, identity and separate calls.
Dimensionless division checks detect incorrect zeros as well as overflow.
Analytic tolerance is scaled `1e-10`; one central finite-difference check uses `1e-8`.

The polynomial example prints value `-7`, forward derivative `12` in the
`x` direction and reverse gradient `[12,-8]` at `(2,4)`.
The temperature example shares a Normal(20,2) prior and readings 19,21,22
with noise SD 1 with the [ordinary model](../examples/temperature.kk).
Its posterior mean/mode is `268/13`, variance `4/13`. Sixteen gradient-ascent
steps from 16°C at rate 0.25 recover the mode within `1e-8`. This is optimization,
not posterior sampling; the sampler itself is not differentiated.

Without Make, use `./bayes autodiff-test` or
`./bayes run examples/autodiff.kk`; on Windows replace `./bayes` with `.\bayes.cmd`.

</details>

<a id="research-basis"></a>
<details>
<summary>Research basis</summary>

The arithmetic-effect and handler architecture adapts Jesse Sigal's
[Automatic Differentiation via Effects and Handlers: An Implementation in Frank](https://arxiv.org/abs/2101.08095).
Reverse propagation uses the same central idea: resume the computation, then
accumulate derivatives as the continuation returns. This is a restricted Koka implementation.

Matthijs Vákár and Tom Smeding's [CHAD](https://arxiv.org/abs/2103.15776)
presents a compositional, type-respecting source transformation and correctness
argument. [Efficient CHAD](https://arxiv.org/abs/2307.05738) develops efficiency
results, including a formalized complexity proof. This library does not implement
those transformations or inherit their guarantees.

Ohad Kammar contributes to research on effects and
[differentiable probabilistic programming semantics](https://denotational.co.uk/).
Sigal acknowledges discussions with him. This is not one joint algorithm by all
four researchers or a dependency on their software.

</details>
