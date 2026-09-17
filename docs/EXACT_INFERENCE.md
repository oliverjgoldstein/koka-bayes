[Docs](README.md) · [Get started](USAGE_GUIDE.md)

<a id="exact-inference-over-finite-choices"></a>

# Exact inference

For a small model with finite choices, `enumerate` checks every possible path.
There is no seed or sampling error; results are exact up to floating-point rounding.

```sh
make demo-enumerate
```

## A noisy alarm

A machine is faulty 30% of the time. Its alarm sounds with probability 0.8
when faulty and 0.2 otherwise. After hearing the alarm, how likely is a fault?

```koka
import bayes

val alarm = obs-bool("machine/alarm")

fun machine() : model<e,bool>
  fn(){
    val faulty = bernoulli'(0.3)
    val sounded = bernoulli(alarm, if faulty then 0.8 else 0.2)
    faulty
  }

pub fun main() : <console,div,exn> ()
  val result = enumerate(singleton(alarm, [True]), machine())
  println(probability(result, fn(faulty){ faulty }).show)
```

The answer is **12/19 ≈ 0.631579**: the two path weights are `0.3 × 0.8 = 0.24`
and `0.7 × 0.2 = 0.14`, giving evidence `0.38` and posterior `0.24 / 0.38`.
The same model also works with likelihood weighting or Metropolis–Hastings.

The [runnable example](../examples/exact_inference.kk) also covers two coins
and a heater setting inferred from a real thermometer reading.

## Results and queries

```koka
val result = enumerate(singleton(alarm, [True]), machine())
val chance = probability(result, fn(faulty){ faulty })
val average = expectation(result, fn(faulty){ if faulty then 1.0 else 0.0 })
val grouped = marginal(result, fn(left, right){ left == right })
```

`probability` answers a question; `expectation` averages a finite numeric value;
`marginal` groups equal results. These queries reuse the completed enumeration.
For two fair coins, four paths group into head counts **0: ¼, 1: ½, 2: ¼**.
Use a deterministic equivalence relation for `marginal`.

<details>
<summary>Result fields</summary>

| Field | Meaning |
| --- | --- |
| `result.outcomes` | One entry per completed positive-mass path; returned values may repeat. |
| `result.log-evidence` | Log sum of joint path weights. With continuous observations, evidence is a density. |
| `result.executions` | Number of positive completed paths. |
| `result.nodes` | Work charged to the enumeration budget. |
| `outcome.value` | The model's returned value. |
| `outcome.probability`, `outcome.log-probability` | Normalized path mass, in ordinary and log form. |
| `outcome.log-weight` | Joint log weight: latent probabilities, likelihoods and factors. |
| `outcome.trace`, `outcome.output-env` | This path's trace and named generated/observed values. |

Grouped values have `value`, `probability` and `log-probability` fields.
Log fields retain information when a tiny probability underflows to zero.
Arithmetic remains `float64`, not symbolic or arbitrary precision.

</details>

## Supported model operations

Latent choices may be **Bernoulli, categorical, Binomial or Poisson(0)**.
Positive-rate Poisson and continuous latent distributions are unsupported.
All existing distribution families can be **observed**, including Normal,
with valid parameters and supported log likelihoods.

Each named observation is consumed once. An exhausted observation stream
becomes a latent draw, so a missing Normal observation raises an unsupported-draw error.
`score` and `log-score` multiply path weights; zero mass prunes a path.

<details>
<summary>Invalid inputs and impossible data</summary>

Invalid distribution parameters, negative or nonfinite ordinary scores, and
NaN or positive-infinite log contributions raise errors. Negative infinity
means zero mass.

If every path has zero mass, the result has no outcomes and `log-evidence = -inf`.
There is no posterior, so `probability`, `expectation` and `marginal` raise errors.
Only positive-mass latent alternatives are explored: categorical indices retain
their original positions; Binomial counts range from `0` to `n`.

</details>

## A budget for the execution tree

Trees can grow exponentially. `enumerate(..., max-nodes=100000)` sets the
default work limit; exceeding it raises an error without returning a truncated posterior.
The limit must be positive.

<details>
<summary>What the budget counts</summary>

Every distribution or factor operation costs one node, and every positive
latent alternative resumed costs another. The budget covers the whole tree.
Two fair coins use nine nodes: three draws and six resumed alternatives,
producing four paths.

The limit cannot interrupt pure infinite loops between probabilistic operations.
Models must terminate on explored paths; ordinary computation and external
effects remain the caller's responsibility. Each nested `enumerate` has its
own budget. To weight an outer model by inner evidence, call
`log-score(inner.log-evidence)` explicitly.

</details>

<a id="how-the-handlers-compose"></a>
<details>
<summary>How the handlers compose</summary>

Finite choices resume the model continuation once per positive alternative.
Each branch keeps its own observation cursor, trace, addresses and log weight.
Latent probabilities, observed likelihoods and factors form its joint weight;
normalizing all path weights gives the posterior.

This interprets a finite execution tree; it does not symbolically integrate
arbitrary programs. Randomness must use traced model operations: untraced
random calls raise errors. Caller-supplied I/O and external mutable references
still need appropriate semantics. See [handler composition](HANDLER_COMPOSITION.md).

</details>

<a id="verification"></a>
<details>
<summary>Checks and recorded validation</summary>

Run `make test-enumerate`. [Support checks](../tests/finite_support.kk) cover
masses, moments, degenerate inputs, tiny probabilities and allocation limits.
[Enumeration checks](../tests/enumeration_checks.kk) use independent arithmetic
and density oracles, plus observation branching, nested inference, enclosing
multi-shot handlers, zero mass, unsupported draws and whole-tree limits.

Local validation on 17 September 2026 passed `make test-enumerate`,
`make demo-enumerate` and `./bayes check` with Koka 3.2.3 / Node 24.21.0 on
macOS arm64: 50 compiled library/model files, all new checks, 36 baseline runs,
99 multi-model runs, 27 joint-posterior comparisons and existing handler/AD
checks and examples. CI includes these checks; this records local validation,
not a hosted run of these changes.

Without Make, use `./bayes demo-enumerate` or `./bayes test-enumerate`;
on Windows, replace `./bayes` with `.\bayes.cmd`.

</details>
