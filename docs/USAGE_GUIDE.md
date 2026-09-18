[Docs](README.md)

<a id="write-and-run-one-model-file"></a>

# Write a model

Edit [model.kk](../model.kk), then run:

```sh
make inference
```

Keep the model, data, inference method and output in that file.
[Install the tools](INSTALLATION.md) first if needed. Without Make, use `./bayes`
on Linux/macOS or `.\bayes.cmd` on Windows.

## Model

The starter learns a coin's probability of heads:

```koka
import bayes

val flip = obs-bool("flip")

fun coin-model(count : int) : model<e,float64>
  fn(){
    val p = beta'(2.0, 3.0)
    for(count) fn(_){ val _ = bernoulli(flip, p); () }
    p
  }
```

`beta'` draws an unknown value. `bernoulli(flip, p)` names a site that can read
observed data. The model returns the quantity you want to infer.

<a id="data-assumptions"></a>

## Data

```koka
val flips = [True, True, True, False]
val observations = singleton(flip, flips)
```

Each occurrence of `flip` consumes the next value. If the list runs out, the
model samples a value; unused data is ignored. This model assumes one fixed
coin probability and independent flips given that probability.

## Inference

Inside `main`, choose a method:

```koka
val posterior = likelihood-weighting(2000, observations, coin-model(flips.length), seed=2027)
```

The seed makes the run reproducible. Budgets and tuning depend on the model.

<details>
<summary>Other inference methods</summary>

For this coin model, replace that line with Metropolis–Hastings:

```koka
val posterior = metropolis-hastings(3000, 500, observations, coin-model(flips.length), seed=2027)
```

This takes 3,000 transitions and discards the first 500. These settings are
checked on small examples, rather than chosen automatically for any model.

For finite latent choices, `enumerate(observations, model)` explores all supported
paths. Query its result with `probability`, `expectation` or `marginal`.
Bernoulli, categorical, Binomial and degenerate Poisson draws are supported;
continuous observations are allowed. The starter's continuous Beta latent needs
a sampling method. See the [exact inference guide](EXACT_INFERENCE.md).

For HMC and MALA, see [gradient inference](GRADIENT_INFERENCE.md). The
[AD guide](AUTODIFF.md) covers differentiating a deterministic objective.
Finding a posterior mode does not produce posterior samples.

</details>

## Results

```koka
println("Estimated probability of heads: " ++ posterior-mean(posterior).show)
```

`posterior-mean` uses likelihood weights for LW and averages retained draws for
MH. The starter's exact answer is `5/9`, for its `Beta(2,3)` prior and three
heads plus one tail. Your edited model has no fixed coin-answer assertion.

## Examples

Run an example in place:

```sh
make inference MODEL=examples/temperature.kk
```

| Try | Learn |
| --- | --- |
| [Room temperature](TEMPERATURE.md) | Infer a continuous value from three noisy readings |
| `make demo-enumerate` | Exact probabilities for finite choices |
| `make demo-hmc` or `make demo-mala` | Inference using AD gradients |
| `make demo-handlers` | Run one checkpointed model with SMC or LW |
| `make examples` | Run every inference demonstration |

The [example guide](INFERENCE_EXAMPLES.md) explains the models and reference
answers. Individual sampler demos are `demo-lw`, `demo-lwis`, `demo-mh`,
`demo-smc`, `demo-rmsmc`, `demo-pmmh` and `demo-smc2`.

<details>
<summary>Example files</summary>

Each file contains its model and inference code. You can copy the Gaussian
starter into `model.kk`; run larger examples in place because their module names
match their paths. Use `./bayes run examples/gaussian.kk` or
`.\bayes.cmd run examples/gaussian.kk` without Make.

| File | Example |
| --- | --- |
| [temperature.kk](../examples/temperature.kk) | Room temperature, with an analytic answer |
| [gaussian.kk](../examples/gaussian.kk) | One unknown Gaussian mean |
| [exact_inference.kk](../examples/exact_inference.kk) | An alarm, two coins and a heater setting |
| [inference.kk](../examples/inference.kk) | One thermometer model with seven samplers |
| [gradient_inference.kk](../examples/gradient_inference.kk) | One Normal-site program with LW, HMC and MALA |
| [compositional_inference.kk](../examples/compositional_inference.kk) | One checkpointed program with SMC or LW |
| [autodiff.kk](../examples/autodiff.kk) | Differentiation and temperature mode optimization |
| [hmm.kk](../examples/hmm.kk) | A sequential hidden-state model |
| [linear_regression.kk](../examples/linear_regression.kk) | Simulation and inference from the same model |
| [sir.kk](../examples/sir.kk) | A larger epidemic model |

The coin and temperature models are starting points. Larger examples demonstrate
composition; the [benchmarks](BENCHMARKS.md) use models with independent reference
answers.

</details>

<a id="project-checks-and-layout"></a>

## Checks

```sh
make check          # Compile, test and run the small examples
make tests          # Tests only; make test is equivalent
make test-examples  # Sampling methods on three models and three seeds
```

Tests have their own models, so editing `model.kk` does not change their targets.
Use `make help` for all commands.

<details>
<summary>Individual checks and project layout</summary>

| Command | Checks |
| --- | --- |
| `make test-enumerate` | Finite supports, exact posteriors, branch isolation, nesting and budgets |
| `make test-lw` | Likelihood weighting |
| `make test-lwis` | Likelihood weighting with resampling |
| `make test-mh` | Metropolis–Hastings |
| `make test-smc` | Sequential Monte Carlo |
| `make test-rmsmc` | Resample-move SMC |
| `make test-pmmh` | Particle marginal Metropolis–Hastings |
| `make test-smc2` | SMC² |
| `make test-hmc` | Leapfrog, rejection and three correlated Gaussian runs |
| `make test-mala` | Proposal correction, rejection and three correlated Gaussian runs |
| `make test-inference` | All 36 baseline analytic inference runs |
| `make test-inference-audit` | Joint posteriors, asymmetric kernels and particle evidence |
| `make test-handlers` | Repeated resumptions, scoring, observation streams and retained state |
| `make test-autodiff` | Forward and reverse AD |

Sampling benchmarks use three fixed seeds. See [benchmark details](BENCHMARKS.md)
and [multi-model validation](MULTI_MODEL_VALIDATION.md) for targets and tolerances.

```text
model.kk       Your model, data, inference and output
examples/      Complete example programs
lib/           Public API and inference implementation
tests/         Independent library checks
scripts/       Installation and command runner
Makefile       Command shortcuts
docs/          Guides and reference
archive/       Unsupported historical code
```

</details>

<a id="optional-lower-level-apis"></a>

## Reference

Start with `import bayes`. For custom inference, use the modules in `lib/alg/`.

<details>
<summary>Lower-level inference APIs</summary>

| API | Result |
| --- | --- |
| `simulate(env, model)` | Value, trace and output environment |
| `enumerate(env, model, max-nodes=100000)` | Finite path probabilities, joint weights, traces and log evidence |
| `lw(iterations, env, model)` | Weighted samples |
| `lwis(iterations, env, model)` | Resampled values |
| `mh(iterations, burnin, env, model)` | Samples, acceptance count and posterior environment |
| `smc(particles, steps, env, sequential-model)` | Particles, log evidence and posterior environment |
| `smc-model(particles, env, checkpointed-model)` | SMC over checkpointed model code |
| `rmsmc(particles, steps, mh-steps, env, sequential-model)` | SMC with rejuvenation |
| `pmmh(particles, steps, config, env, sequential-model)` | Parameter samples with particle likelihood estimates |
| `smc2(outer, inner, steps, rejuvenation-steps, env, sequential-model)` | Parameter particles with retained inner filters |

These APIs retain their algorithm-specific result types.

</details>

<a id="sequential-models-and-custom-kernels"></a>

<details>
<summary>Sequential models and custom kernels</summary>

[Sequential models](../lib/core/sequential.kk) define a prior, initial state and
step function. `as-model(steps, spec)` turns one into a regular model.

**Observations.** Each name has a stream consumed once in execution order, across
prior, initial and step stages. A step may read a name several times. A singleton
is observed once; later occurrences are sampled. To observe a value three times,
provide three entries. Filtering and prefix replay use this same rule.
`focus-step` and `take-prefix` only slice streams; inference does not infer
observation roles from list length or use these helpers internally.

**Retained filters.** `alg/smc` provides `start-smc-given`, `advance-smc-state`,
`extend-smc-state` and `finish-smc`. Each particle retains its own remaining
observations through resampling and rejected rejuvenation. `smc-given` and
`start-smc-given` take the stream left after the parameter prior has run.
The older `advance-smc` and `extend-smc` signatures remain available, but their
environment argument no longer resets that stream.

Supply available data at initialization. When more arrives, call
`append-smc-observations(new-data, state)` before `advance-smc-state(spec, state)`.
Append only new occurrences. This preserves pending observations, leaves the old
filter unchanged, and scores new data only when the model reads it.

An all-zero-weight population returns no particles and log evidence `-inf`.
This can mean impossible data or finite-particle depletion; it is not a posterior.
Invalid distribution parameters are rejected.

**Custom parameter proposals.** For `pmmh-with` and `smc2-with`:

- `parameter-score` includes every parameter-level target factor, including
  observations and explicit factors. It must be deterministic for a fixed
  parameter. An arbitrary noisy log score or changing external state is invalid,
  even though the effect row permits it.
- The kernel separately returns `log-correction = log q(current | proposed) -
  log q(proposed | current)`. Do not put this correction in the target score.
- The prior must consume a fixed observation prefix across parameters. For
  parameter-dependent consumption, use `pmmh-with-state` or `smc2-with-state`.
  Return an `alg/parameter.Parameter-proposal` containing the proposed parameter,
  output environment, remaining observations and correction. That stream must
  match the proposed parameter and its score.
- Both `smc2-with` and `smc2-with-state` require the returned parameter to expose
  the prior's sampled latent coordinates: initialization uses their trace density
  as the proposal density. Transformed or marginalized parameters and hidden
  prior randomness need additional density handling.

Default `pmmh` and `smc2` cancel sampled prior factors and retain observed prior
factors automatically.

**Composition.** Replay MH must trace every random choice affecting likelihood
or control flow. Untraced randomness or changing external state can invalidate
replay. Nested inference and repeated continuation resumptions have separate
reader, trace and weight state. Caller-provided I/O and mutable references still
need suitable semantics; effect rows do not prove arbitrary compositions.
See the [handler guide](HANDLER_COMPOSITION.md).

</details>

<a id="factors-and-checkpoints"></a>

<details>
<summary>Factors and checkpoints</summary>

`score(weight)` multiplies the unnormalized density by a finite nonnegative
weight; zero is allowed. `log-score(log-weight)` accepts finite log weights or
`-inf` for zero mass. The operation itself does not validate the log argument;
NaN and positive infinity are outside its supported domain. Both create factor
trace entries without adding a latent sampling site.

Import `handlers/sequential` for `checkpoint()` and `run-sequential`, and
`alg/handler_smc` for `smc-model`. Checkpoints mark resampling boundaries.
`smc-model` runs suspended particles; `run-sequential(model)` completes those
same checkpoints for another method. See the [example](../examples/compositional_inference.kk)
and [handler guide](HANDLER_COMPOSITION.md) for operation routing and evidence.

</details>

<a id="sir-diagnostics"></a>

<details>
<summary>SIR diagnostics and recorded limitations</summary>

Run `make inference MODEL=examples/sir_report.kk` for synthetic SIR recovery
checks. It creates `results/` if needed and writes:

- `results/sir-diagnostics-dashboard.svg`
- `results/sir-diagnostics-summary.csv`
- `results/sir-diagnostics-samples.csv`

The [report](../examples/sir_report.kk) defines its synthetic truth and tolerances.
Each parameter is labelled **recovery within tolerance** or **recovery outside
tolerance**, based on distance from the generating parameter. These labels do
not establish inference correctness or convergence.

The dashboard and summary CSV also show retained draw counts, exact distinct-value
counts and empirical 90% intervals (the 5th and 95th percentiles of those draws).
Repeated rejected states and resampled duplicates remain in the summaries.
These intervals describe the draws; they do not measure Monte Carlo error or
prove convergence. Empty or nonfinite samples are rejected. CSV numeric values
retain full precision; display labels are rounded.

The generated summary CSV now has separate `beta_recovery_within_tolerance` and
`report_recovery_within_tolerance` columns in place of the old combined `success`
column. The historical audit CSV keeps its original schema and results.

The 17 September audit rerun, after repairing the transformed proposal, passed
SMC and RMSMC recovery thresholds. PMMH and SMC² missed the report-rate threshold:
absolute errors about `0.148` and `0.151`, against a `0.12` limit.
[Recorded results](sir-audit-results.csv) preserve those failures.

This compares estimates with generating parameters, not an exact posterior.
It alone establishes neither an inference-equation bug nor adequate mixing.
The original budgets remain unchanged: 90 PMMH iterations with 30 burn-in and
48 inner particles; SMC² uses 32 outer and 32 inner particles with two moves.
The SIR custom parameter kernel holds gamma fixed; supply the known gamma in
the observation environment when using this kernel.

Run `make test-sir` for a separate small SIR posterior check against exhaustive
arithmetic, plus regression tests for the report summaries. These tests are
included in `make check`. See the [inference audit](INFERENCE_AUDIT.md#small-sir-posterior-check)
for the reference model and budgets. Passing them does not resolve the larger
SIR report's recovery failures.

</details>

[Architecture](development/ARCHITECTURE_MAPPING.md) ·
[Handler design](development/DESIGN_NOTES.md) ·
[Correctness assessment](ASSESSMENT.md)
