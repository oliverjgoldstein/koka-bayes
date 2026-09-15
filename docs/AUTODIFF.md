# Automatic differentiation with handlers

This is a scalar, first-order AD foundation for Koka 3.2.3. A single program
using `smooth<a>` operations can be evaluated, differentiated in forward mode,
or differentiated in reverse mode. The implementation uses `float64` arithmetic.

## Implementation

Arithmetic operations are effects, polymorphic over their value representation.
The evaluation, forward, and reverse handlers interpret the same objective.

| Component | Behavior |
| --- | --- |
| `smooth<a>` | Represents constants, unary operations, and binary operations |
| `evaluate` | Computes ordinary `float64` values |
| `dual` and `forward` | Carry a value and a directional derivative through the chain rule |
| `reverse-value<h>` | Pairs a value with a scoped derivative cell |
| Reverse `ctl` clauses | Resume the remaining computation, then accumulate derivatives into parent cells |
| `value-and-grad` | Creates input cells, seeds the output derivative with one, and returns input partials |

Koka's deep handlers handle subsequent operations when `resume` continues the
program. Reverse derivative contributions accumulate as those continuations
return. Both parent contributions are added for `x*x` and shared intermediate
values. References are local to each `run`; differentiation calls share no
global mutable state.

## API

| Module | Purpose |
| --- | --- |
| [`autodiff/smooth`](../lib/autodiff/smooth.kk) | Arithmetic effect, `evaluate`, and normal log density |
| [`autodiff/forward`](../lib/autodiff/forward.kk) | `dual`, `forward`, and `value-and-derivative` |
| [`autodiff/reverse`](../lib/autodiff/reverse.kk) | `value-and-grad`, returning value and input partials |

Supported operations are constants, addition, subtraction, multiplication,
division, negation, exponential, logarithm, sine, and cosine. `ad-square` and
`ad-normal-log-density` compose those operations.

```koka
import autodiff/smooth
import autodiff/reverse

fun objective(xs : list<a>) : smooth<a> a
  match xs
    Cons(x, Cons(y, _)) ->
      ad-add(ad-constant(1.0), ad-sub(ad-mul(ad-square(x), x), ad-square(y)))
    _ -> ad-constant(0.0)

// value = -7; partials = [12, -8]
val result = value-and-grad(objective, [2.0, 4.0])
```

The list API preserves input order, including zero gradients for unused inputs.
The objective must be polymorphic in `a`: use the `ad-*` arithmetic operations
to keep its arithmetic visible to the handlers. Forward mode accepts `Dual`
inputs with user-specified tangents, so a single run computes a directional
derivative. `value-and-derivative` seeds a unary function with tangent one.

## Verification and probabilistic example

Run:

```sh
make test-autodiff
make inference MODEL=examples/differentiation.kk
make inference MODEL=examples/autodiff.kk
```

These commands are the same on Linux, macOS, and Windows with GNU Make installed.
Without Make, use `./bayes autodiff-test` and `./bayes run examples/autodiff.kk`;
on Windows use `.\bayes.cmd` in place of `./bayes`.

The deterministic tests compare values and gradients with analytic answers for:

- The polynomial `1 + x^3 - y^2`.
- Shared intermediate values and repeated operands.
- All supported unary and binary primitive operations.
- Division gradients at scales `1e200` and `1e-200`, using dimensionless checks
  that detect a wrong zero as well as overflow.
- A normalized normal log density, including observation, mean, and scale
  derivatives.
- A conjugate normal model's log joint and exact posterior mode.
- Constants, unused inputs, identity, empty inputs, and separate AD calls.

They also compare one derivative with a central finite difference. Analytic
checks use a scaled tolerance of `1e-10`; the finite-difference tolerance is
`1e-8`.

The [polynomial example](../examples/differentiation.kk) evaluates `1 + x^3 - y^2` at `(2,4)`
using all three handlers. It prints value `-7`, forward derivative `12` in the
`x` direction, and reverse gradient `[12,-8]`.

The [single-file example](../examples/autodiff.kk) contains the objective,
optimization settings, and result printing. It uses a `N(0,1)` prior and one observation of 2 with noise
variance 1. The posterior is exactly `N(1,0.5)`. Thirty-two gradient-ascent steps
using the reverse handler, starting at -3 with rate 0.25, recover the mode 1 to
within `1e-8`. This validates a connection between AD and a probabilistic
objective. MAP is optimization, not posterior sampling.

## Scope and limits

- Only scalar first derivatives are implemented. There are no tensors, GPU
  kernels, Hessians, nested differentiation, checkpointing, or custom derivative
  registration.
- Reverse mode retains the executed computation through continuations and
  derivative cells. Its time and storage grow with the executed operations;
  large-program performance and stack limits have not been benchmarked.
- Operands must be in each operation's differentiable domain: normal standard
  deviations and logarithm arguments must be positive; divisors must be nonzero.
  IEEE floating-point overflow, infinities, and NaNs are not repaired.
- Objectives passed to `value-and-grad` have only the `smooth<a>` effect.
  Ordinary scalar arithmetic, effectful randomness, and existing `core/model`
  sample/observe operations are not differentiated automatically. Fixed
  observed data can be lifted with `ad-constant`.
- The generic representation currently provides no primal-value comparison
  operation. Smooth objectives can use ordinary structural control flow, but
  data-dependent branching on AD values is not part of this API.
- There is no HMC, NUTS, variational inference, differentiation through discrete
  sampling or resampling, or claim of whole-language differentiation.

These checks establish a small executable base for further work. They do not
establish performance leadership, inference correctness outside the separate
inference benchmark suite.
