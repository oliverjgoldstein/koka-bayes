# Write and run one model file

Start with [model.kk](../model.kk). It contains everything you edit: the model,
observations, inference method, and result printing. Library code lives in `lib/`.

## Model

Import the public API once:

```koka
import bayes
```

A model is a function that requests random values and returns the quantity you
want to infer. The starter returns the coin's probability of heads.

```koka
val flip = obs-bool("flip")

fun coin-model(count : int) : model<e,float64>
  fn(){
    val p = beta'(2.0, 3.0)
    for(count) fn(_){ val _ = bernoulli(flip, p); () }
    p
  }
```

`beta'` samples an unobserved value. `bernoulli(flip, p)` names a site that can
read observed data. The same model can also generate missing observations.

## Data assumptions

The data belongs beside the model:

```koka
val flips = [True, True, True, False]
val observations = singleton(flip, flips)
```

Repeated occurrences of `flip` read this list in order. The starter calls it once
per supplied flip, so every supplied value is used. Its assumptions are a fixed
coin probability and independent flips given that probability.

In general, a site samples when its observation list runs out; extra data is
ignored when execution never reaches another site. Match the model's observation
sites to the data you intend to condition on.

## Inference

Inside `main`, select the method with one line:

```koka
val posterior = likelihood-weighting(2000, observations, coin-model(flips.length), seed=2027)
```

For this small coin model, change that line to use Metropolis–Hastings:

```koka
val posterior = metropolis-hastings(3000, 500, observations, coin-model(flips.length), seed=2027)
```

The MH example takes 3,000 transitions and discards the first 500. The seed makes
a run reproducible. The appropriate method and budget depend on your model;
these settings are checked on small, simple examples.

With GNU Make installed, run setup once and then run your model:

```sh
make setup
make inference
```

`make inference` runs `model.kk`. To run another file:

```sh
make inference MODEL=examples/temperature.kk
```

The Make commands are the same on Linux, macOS, and Windows. The
[installation guide](INSTALLATION.md) includes commands without Make:
`./bayes` on Linux/macOS or `.\bayes.cmd` on Windows runs the starter directly.
Each example contains its model and inference code together. You can copy the
Gaussian starter into `model.kk`. Run the larger examples in place; their module
names match their paths.

| Example | What it shows |
| --- | --- |
| [temperature.kk](../examples/temperature.kk) | A room temperature from three noisy readings, with an exact answer |
| [gaussian.kk](../examples/gaussian.kk) | One unknown Gaussian mean |
| [hmm.kk](../examples/hmm.kk) | A sequential hidden-state model |
| [linear_regression.kk](../examples/linear_regression.kk) | Simulation and inference with the same model |
| [sir.kk](../examples/sir.kk) | A larger epidemic model |

The [temperature walkthrough](TEMPERATURE.md) is the main continuous worked
example. The coin is a smaller discrete starting point. The larger examples are
composition demonstrations; the [benchmark suite](BENCHMARKS.md) uses simpler
problems matched to each inference method.

## Results

Print a posterior mean:

```koka
println("Estimated probability of heads: " ++ posterior-mean(posterior).show)
```

`posterior-mean` uses the importance weights for likelihood weighting and
averages the retained samples for Metropolis–Hastings. The starter's exact answer,
`5/9`, applies only to its `Beta(2,3)` prior and three-heads/one-tail data.
Your edited model runs without a hard-coded coin-answer assertion.

## Project checks and layout

```sh
make check
```

This compiles the active Koka modules, runs the tests, and runs the starter and
small examples. `make tests` (or `make test`) runs just the tests. Choose an
individual inference algorithm when that is all you need to check:

| Command | Checks |
| --- | --- |
| `make test-lw` | Likelihood weighting |
| `make test-lwis` | Likelihood weighting with importance resampling |
| `make test-mh` | Metropolis–Hastings |
| `make test-smc` | Sequential Monte Carlo |
| `make test-rmsmc` | Resample-move SMC |
| `make test-pmmh` | Particle marginal Metropolis–Hastings |
| `make test-smc2` | SMC² |
| `make test-inference-audit` | Joint posteriors, asymmetric kernels and particle evidence |
| `make test-inference` | All 30 analytic inference runs |

The inference checks use small problems with exact answers and three fixed
seeds. They have their own models under `tests/`, so editing your starter does
not change their mathematical targets. [Benchmark details](BENCHMARKS.md)
explain the models and tolerances. Run `make help` for the command summary.

```text
model.kk       Your model, data, inference, and results
Makefile       Setup, inference, and test commands
examples/      Other complete model files
lib/           Public API and inference implementation
tests/         Independent library checks
scripts/       Installation and command runner
docs/          Optional explanations and development notes
archive/       Unsupported historical code
```

## Optional: lower-level APIs

Most models start with `import bayes`. The implementation modules remain
available for custom algorithms and sequential models:

| API | Result |
| --- | --- |
| `simulate(env, model)` | Model value, trace, and output environment |
| `lw(iterations, env, model)` | Weighted samples |
| `lwis(iterations, env, model)` | Resampled values |
| `mh(iterations, burnin, env, model)` | Samples, acceptance count, and posterior environment |
| `smc(particles, steps, env, sequential-model)` | Particles, log evidence, and posterior environment |
| `rmsmc(particles, steps, mh-steps, env, sequential-model)` | SMC with rejuvenation |
| `pmmh(particles, steps, config, env, sequential-model)` | Parameter samples using a particle likelihood estimate |
| `smc2(outer, inner, steps, rejuvenation-steps, env, sequential-model)` | Parameter particles with retained inner filters |

The lower-level APIs retain their algorithm-specific outputs. Use their modules
under `lib/alg/` when you need more than the starter's public helpers.

### Sequential models and custom kernels

[Sequential models](../lib/core/sequential.kk) define a prior, initial state, and
step function. `as-model(steps, spec)` turns one into a regular model.
`focus-step` projects observations onto one step; `take-prefix` projects onto a
prefix while preserving singleton global bindings.

`alg/smc` exposes retained filters: `start-smc-given`, `advance-smc`, `extend-smc`,
and `finish-smc`. Each advance consumes the next step from the original
environment. SMC² retains these populations on rejected rejuvenation proposals.

Supported sequential environments use distinct names for prior, initial, and
step sites. Observed prior/initial sites occur once and use singleton lists.
Each repeated step observable occurs once per step and has a per-step observation
list. Reusing a singleton across several steps is unsupported: filtering would
repeat it while prefix replay would consume it once.

An all-zero-weight population produces an empty result and log evidence `-inf`.
This can indicate impossible data or finite-particle depletion; it is not a
posterior. Invalid distribution parameters are rejected.

Custom `pmmh-with` and `smc2-with` kernels must include the reverse-minus-forward
proposal log density and every parameter-level target factor in their score.
`smc2-with` also requires the returned parameters to expose the prior's sampled
latent coordinates: initialization uses the sampled trace density as its proposal
density. Transformed or marginalized parameters, or hidden prior randomness,
need matching density handling beyond this API. Default `pmmh` and `smc2` cancel
sampled prior factors and automatically retain observed prior factors.

Replay MH requires every random choice affecting likelihood or control flow to
use the traced model distribution operations. Untraced randomness or changing
external state can invalidate replay.

### SIR diagnostics

Run `make inference MODEL=examples/sir_report.kk` for synthetic SIR recovery diagnostics.
It writes `results/sir-diagnostics-dashboard.svg`,
`results/sir-diagnostics-summary.csv`, and `results/sir-diagnostics-samples.csv`.
The report creates `results/` if needed and uses the synthetic truth and tolerances
in [the report implementation](../examples/sir_report.kk). It is separate
from the elementary analytic correctness suite.

The 17 September audit rerun, after repairing the transformed proposal,
passed the SMC and RMSMC recovery thresholds. PMMH and SMC² missed the
report-rate threshold (absolute errors about 0.148 and 0.151; limit 0.12).
[Recorded results](sir-audit-results.csv) preserve those failures. This diagnostic
compares estimates with generating parameters, not an exact posterior oracle;
it does not by itself establish an inference-equation bug or adequate mixing.
Use the analytic benchmarks and [inference audit](INFERENCE_AUDIT.md) for the
supported elementary correctness cases.

[Architecture](development/ARCHITECTURE_MAPPING.md) ·
[Handler design](development/DESIGN_NOTES.md) ·
[Correctness assessment](ASSESSMENT.md)
