[Documentation](README.md) · [Effects and handlers](EFFECTS_AND_HANDLERS.md) · [Exact inference tutorial](EXACT_INFERENCE.md)

# Finite enumeration: effects, handlers and semantics

`enumerate` interprets the supported finite execution tree of a model. It resumes
the continuation at each latent choice once for every positive-mass alternative,
records each surviving complete path, and normalizes their weights. This page
specifies that implementation; it does not establish a formal correctness theorem
for Koka handlers or arbitrary effect combinations.

The implementation is in [handlers/enumerate.kk](../lib/handlers/enumerate.kk),
[core/finite.kk](../lib/core/finite.kk) and
[alg/enumerate.kk](../lib/alg/enumerate.kk). For runnable models, start with the
[alarm, coins and heater examples](../examples/exact_inference.kk).

## Public interface and result contract

The public signature is:

```koka
pub fun enumerate(environment : env, action : model<<random,exn|e>,a>,
                  max-nodes : int = 100000)
  : <div,exn|e> enumeration-result<a>
```

Here `model<e,a>` abbreviates `() -> <obs-reader,model-dist,div|e> a`.
The effect row includes `random` so that enumeration can install an interpretation
that rejects raw randomness. Enumeration itself does not sample. Other effects
in `e` remain the caller's responsibility; the type does not certify that the
model is finite, terminates, or uses external effects safely.

| Field | Meaning |
| --- | --- |
| `outcomes : list<enumeration-outcome<a>>` | One entry per surviving complete execution path, including distinct paths returning the same value. |
| `log-evidence : float64` | Logarithm of the sum of unnormalized joint path weights. |
| `executions : int` | `outcomes.length`; pruned branches do not count. |
| `nodes : int` | Work charged across the whole execution tree. |
| `outcome.value : a` | The return value on that path. |
| `outcome.log-weight : float64` | Latent log masses plus observed log likelihoods and explicit log factors. |
| `outcome.log-probability : float64` | Normalized log mass of that path. |
| `outcome.probability : float64` | `exp(outcome.log-probability)`, which can underflow to zero. |
| `outcome.trace : run-trace` | Sampled, observed and factor entries for that execution. |
| `outcome.output-env : env` | Named sampled and observed values reconstructed from the trace. |

`output-env` is not the unused remainder of the supplied observation environment.
The lower-level `enumerate-paths` returns `enumeration-path<a>` records containing
`value`, `trace`, `remaining-env` and `log-weight`; `enumerate` uses the trace to
construct the public output environment instead. Unconsumed observations do not
automatically contribute likelihood, and their presence does not cause an error.

## The private control effect

The ordinary [model operations](../lib/core/model.kk) are declared with `fun`;
they do not expose a continuation for arbitrary repeated resumption. Enumeration
introduces branching behind their interpretation using this private effect:

```koka
effect enumeration-control
  ctl choose-finite(distribution : dist) : observable
  ctl discard-branch() : ()
  fun count-operation() : ()
```

| Operation | Interpreter | Operational meaning |
| --- | --- | --- |
| `choose-finite(d)` | `explore` | Charge for the draw, enumerate the positive support of `d`, then resume once per alternative and add that alternative's log mass to each returned suffix. |
| `discard-branch()` | `explore` | Return an empty list without resuming the continuation. No later operation on that branch runs. |
| `count-operation()` | `explore` | Increment the shared work counter or throw if the budget is exhausted. |

`explore` returns `(list<(a,float64)>,int)`: each pair contains a completed action
result and the sum of latent log masses accumulated through choices; the integer
is the shared work count. Its return clause maps a completed value to
`[(value, 0.0)]`. Its choice clause concatenates all resumed result lists. The
alternative's log probability is added once to each completed suffix, so latent
mass is not also accumulated by the observation-weight handler.

## Handler nesting and ownership of state

The following is the nesting in `enumerate-paths`, from outside to inside. It is
a diagram of scope, not an additional API:

```text
reject raw random-int32 calls
  explore                         shared nodes counter
    exact-weight                  branch-local observation/factor log weight
      finite-sampling             sample-value becomes choose-finite
        handle-trace              branch-local entries and next address
          mask internal sampling, weight and enumeration effects
            exact-core
              handle-read-state   branch-local observation environment
                model-dist handler
                  mask model hooks
                    model action
```

The `nodes` variable is outside the handler whose continuation is resumed for
each finite alternative. It therefore charges all alternatives to one budget.
The reader cursor, trace and accumulated observation weight are inside that
branching handler: resuming a continuation restores the state at the choice
point, then each branch advances its own copy. For example, consuming two extra
observations on one branch must not remove them from its sibling's environment.

The masks distinguish effects raised by the supplied action from operations
introduced by the interpreters. They hide this runner's implementation handlers
from direct use by model code while allowing the surrounding interpreter clauses
to invoke them. They do not prove that arbitrary combinations of other handlers
commute. See [effect scopes and composition](EFFECTS_AND_HANDLERS.md) and
[handler composition](HANDLER_COMPOSITION.md).

### `exact-core`: specialize the model using observations

`exact-core` interprets `model-dist` inside `handle-read-state` and returns
`(value, remaining-env)`. It validates distribution parameters before interpreting
either a latent or an observed site:

| Model operation | Exact interpretation |
| --- | --- |
| `draw(d)` | Validate `d`, then call `sample-hook(Nothing, d)`. |
| `draw-observable(name, d)` | Validate `d`, consume the next observation for `name`, then call `observe-hook(name, d, value)` if one exists; otherwise call `sample-hook(Just(name), d)`. |
| `factor(log-weight)` | Call `factor-hook(log-weight)`. |

Observations are consumed once, in occurrence order for each name. Exhaustion
changes a named site into a latent draw. Thus an observed Normal is supported,
but a missing Normal observation reaches finite-support selection and fails.
Calling `read-observation` directly only reads data; scoring comes from the
model-distribution interpretation and its hooks.

Unlike the general core handler, this specialization checks `is-valid(d)` for
observed distributions as well as latent ones. Support restrictions apply only
when the site actually requires enumeration.

### `handle-trace`: record the selected execution

The shared [trace handler](../lib/handlers/trace.kk) gives every encountered
sample, observation and factor the next integer address, beginning at zero.

- A sample hook calls `sample-value(address, d)`, records the returned value and
  its distribution log probability as `TraceSampled`, then increments the address.
- An observation hook records the supplied value as `TraceObserved`, increments
  the address, and sends its log likelihood to `accumulate-weight`.
- A factor hook records `TraceFactor`, increments the address, and sends the log
  factor to `accumulate-weight`.

Only observations and factors use `accumulate-weight`. Latent masses enter the
joint weight through `explore`; adding sampled trace densities again would count
the prior twice. The trace's total log density and the enumerated joint weight
describe the same product, up to numerical differences between support
construction and the distribution's log-density evaluator.

### `finite-sampling`: replace sampling with branching

`finite-sampling` interprets the shared `sample-value` effect by calling
`choose-finite(distribution)`. It ignores the address argument: addresses identify
trace entries but do not select or cache alternatives. The continuation captures
the rest of the trace, reader and model computation after this choice.

### `exact-weight`: validate, accumulate and prune scores

`exact-weight` interprets `accumulate-weight` and returns `(value, weight)`, where
`weight` is the accumulated observation/factor log weight. Each increment first
charges one work unit. A finite increment is added; a nonfinite accumulated sum
raises an error. Negative infinity calls `discard-branch` immediately. NaN and
positive infinity raise errors rather than representing posterior mass.

This is stricter than the general [weight handler](../lib/handlers/weight.kk),
which simply adds increments. `score(w)` also validates ordinary weights before
converting to log space: `w` must be finite and nonnegative; `score(0.0)` becomes
`log-score(neginf)`.

### `enumerate-paths`: assemble joint path weights

`enumerate-paths` installs the raw-randomness rejection handler and the complete
stack above. For each surviving result, it adds the latent log mass returned by
`explore` to the observation/factor log weight returned by `exact-weight`, checks
that the sum is finite, and constructs an `enumeration-path`.

It throws if an otherwise unhandled `random-int32()` reaches its random handler.
The purpose is to reject random behavior absent from the enumerated trace. This
does not inspect caller-provided state, I/O, or a separately installed inner
random handler; such behavior still needs an appropriate model interpretation.

## Path measure and normalization

Let a complete path `t` return `r(t)`, choose latent values `x_i` with conditional
masses `p_i(x_i | prefix(t))`, consume observations `y_j` with likelihoods
`q_j(y_j | prefix(t))`, and execute log factors `s_k`. The intended unnormalized
path mass is

$$
w_t = \prod_i p_i(x_i\mid\operatorname{prefix}(t))
      \prod_j q_j(y_j\mid\operatorname{prefix}(t))
      \exp\!\left(\sum_k s_k\right),
\qquad
\ell_t = \log w_t.
$$

The finite measure on returned values and its normalizer are

$$
\mu(A)=\sum_{t:r(t)\in A} w_t,
\qquad Z=\sum_t w_t,
\qquad \Pr(r\in A\mid\text{scores})=\mu(A)/Z.
$$

These equations describe the intended finite-tree interpretation. At each finite
draw, `explore` forms the weighted sum of continuation results; an observed site
returns its supplied value and multiplies its likelihood; a factor multiplies
by `exp(s)`; returning a value contributes a unit terminal weight. This provides
an explicit compositional description for those operations under this stack.
The repository has tests of that interpretation, not a mechanized equivalence
proof between the Koka implementation and the equations.

If a likelihood is continuous, `Z` is an observation density under the model's
likelihood conventions. Arbitrary factors make `Z` an unnormalized measure's
normalizer; it need not be an event probability or at most one.

For nonempty path lists, the public wrapper computes

$$
m=\max_t\ell_t,\quad
c=\log\sum_t\exp(\ell_t-m),\quad
\log Z=m+c,\quad
\log\pi_t=(\ell_t-m)-c.
$$

Centering before normalization avoids losing the normalization correction when
all paths have a large common log score. The calculations use `float64`: small
differences can still be lost, log sums can overflow, and ordinary probabilities
can underflow. “Exact” means complete finite enumeration without Monte Carlo
sampling error, subject to these arithmetic limits. It does not mean symbolic
integration, rational arithmetic, or differentiable enumeration.

`probability` sums normalized log masses selected by a predicate. `marginal`
combines returned values using the caller's equality function, which should be
a deterministic equivalence relation. `expectation` sums positive and negative
contributions separately in log space before taking their difference; projected
values must be finite. These queries require at least one positive-mass outcome.

## Supported finite support

`finite-support(d, max-size)` returns `finite-choice` records containing an
`observable` value and its log probability. It validates the distribution and
checks support size before allocating the outcome population.

| Latent distribution | Enumerated alternatives |
| --- | --- |
| Bernoulli with `0 < p < 1` | `False`, `True`, with log masses `ln1p(-p)`, `ln(p)`. |
| Bernoulli at `p = 0` or `p = 1` | The single certain value. |
| Categorical (`discrete`) | Original indices with strictly positive weights; zero-weight entries are omitted. Log weights are normalized using a maximum shift. |
| Binomial with `n > 0`, `0 < p < 1` | All counts `0` through `n`, built by the log-space probability-ratio recurrence and normalized. |
| Binomial at `n = 0`, `p = 0` or `p = 1` | Its single certain count. |
| Poisson with rate zero | The single value `0`. |
| Positive-rate Poisson, Normal, Uniform, Gamma, Beta | Rejected as unsupported latent support. |

A positive categorical or Binomial mass is retained in log form even when its
ordinary probability would underflow. A later finite factor can make that path
important. All existing distribution families may supply observed likelihoods
without enumerating their support, subject to parameter and log-score validation.

## Alarm walkthrough

For the [machine example](../examples/exact_inference.kk), the observation
environment contains `machine/alarm = [True]`:

```koka
val faulty = bernoulli'(0.3)
val sounded = bernoulli(alarm, if faulty then 0.8 else 0.2)
faulty
```

The first operation becomes `sample-value(0, ...)`, then `choose-finite(...)`.
`explore` resumes first with `False`, then with `True`. Each continuation records
its own sampled entry at address zero, consumes its own copy of the `True`
observation, and records an observed entry at address one.

| Path | Latent mass from `explore` | Likelihood from `exact-weight` | Joint mass | Posterior mass |
| --- | --- | --- | --- | --- |
| `faulty = False` | `0.7` | `0.2` | `0.14` | `7/19` |
| `faulty = True` | `0.3` | `0.8` | `0.24` | `12/19` |

The evidence is `0.38`; there are two surviving executions and five charged
nodes: one latent operation, two resumed alternatives, and one observed
operation in each alternative. Both output environments contain the consumed
alarm value. The unnamed `faulty` sample appears in the trace, not the output
environment; it is available as `outcome.value`.

## Budget, pruning and failure contract

The positive `max-nodes` limit is shared across the tree. A latent draw costs one
unit, each resumed positive alternative costs another, and each observed
likelihood or factor costs one. At a choice, the remaining budget is also passed
to `finite-support`, preventing a support population larger than that budget
from being allocated. Descendants still consume the same remaining global
budget. Two fair coins therefore use nine units: three draw operations and six
resumptions for four completed paths. A pure return uses zero units, although
the supplied limit must still be positive.

- Exceeding the limit throws; enumeration never returns a budget-truncated
  posterior as an exact result.
- A zero likelihood or negative-infinite factor discards the continuation.
  Unsupported operations after that point are not reached. Zero-mass alternatives
  omitted by `finite-support` are not resumed.
- If every branch is pruned, `outcomes` is empty, `executions` is zero, and
  `log-evidence` is negative infinity. There is no posterior; the query helpers
  throw instead of returning a uniform distribution.
- Invalid parameters, unsupported reached latent support, raw random operations,
  invalid log contributions and checked numerical overflow also throw. An error
  on one reached branch aborts enumeration instead of dropping just that branch.

The budget counts probabilistic work, not elapsed time or arbitrary instructions.
It cannot interrupt a pure infinite loop between counted operations, and it is
not a bound on all memory used by model values, traces or external effects.

## Nested inference and other effects

Each nested `enumerate` has separate observations, traces, normalization and
budget. Merely computing an inner result does not add its evidence to an outer
model. To perform that particular composition, use
`log-score(inner.log-evidence)` explicitly; the outer trace then contains one
factor, not the inner trace. Inner and outer budgets are independent.

The tests also exercise enumeration inside an enclosing multi-shot handler and
verify restored observation cursors, traces and probabilities. That is evidence
for the tested scope arrangement. External I/O or mutable references may behave
differently under repeated continuation resumption; their semantics must be
specified separately. Neither the generic residual effect row nor the tests
justify treating every handler rearrangement as semantics-preserving.

Enumeration weights and query results use `float64` and do not invoke the AD
effect. There is currently no automatic differentiation of enumerated evidence,
probabilities or expectations. See [supported combinations](STATUS.md).

## Verification map

Run `make test-enumerate` for the dedicated checks and `make demo-enumerate` for
the runnable examples. The following names are functions in the linked suites;
they identify checks rather than a general proof claim.

| Contract | Existing check |
| --- | --- |
| Positive support, normalization, degenerate cases, tiny probabilities and allocation limits | [finite_support.kk](../tests/finite_support.kk): `test-bernoulli`, `test-categorical`, `test-binomial`, `test-rejections`. |
| Complete paths, prior mass, posterior mass, evidence and aggregation | [enumeration_checks.kk](../tests/enumeration_checks.kk): `test-two-coins`, `test-informative-bayes`, `test-categorical-binomial`. |
| Branch-local observation cursors and traces; exhausted streams | [enumeration_checks.kk](../tests/enumeration_checks.kk): `test-observation-branches`. |
| Continuous and infinite-support observed likelihoods | [enumeration_checks.kk](../tests/enumeration_checks.kk): `test-observed-continuous`. |
| Nested evidence isolation and explicit propagation | [enumeration_checks.kk](../tests/enumeration_checks.kk): `test-nested-enumeration`. |
| State restoration under an enclosing multi-shot handler | [enumeration_checks.kk](../tests/enumeration_checks.kk): `test-outer-resumptions`. |
| Log normalization, zero mass and immediate pruning | [enumeration_checks.kk](../tests/enumeration_checks.kk): `test-factors-and-empty`. |
| Global budget, raw randomness, unsupported support and invalid input | [enumeration_checks.kk](../tests/enumeration_checks.kk): `test-errors-and-budget`. |

The finite-support and posterior checks use independent arithmetic, moments and
density formulas for their models. Coverage is limited to those cases and the
tested handler arrangements; it does not remove the termination, numerical or
external-effect qualifications above.
