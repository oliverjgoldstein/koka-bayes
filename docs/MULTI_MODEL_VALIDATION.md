[Docs](README.md) · [Get started](USAGE_GUIDE.md)

# Testing multiple models

Each sampling method runs on three models with three fixed seeds.

```sh
make test-examples
```

The matrix contains **90 posterior runs and nine simulation checks**. Finite enumeration has separate deterministic checks: `make test-enumerate`. Both are included in `make check`.

<details>
<summary>Coverage, tolerances and recorded results</summary>

## Testing every inference method on multiple models
Run `make test-examples` or `./bayes example-matrix`. Every posterior sampling method,
including checkpoint SMC, runs on three models with three fixed seeds per model:
**90 posterior runs**, plus **nine prior-simulation checks**. All 99 runs are
also included in `make test`, `make check` and CI.

Finite enumeration has deterministic checks rather than seeded runs. Run
`make test-enumerate` for independent exact models, branch and nesting checks,
numerical edge cases and support/budget errors; see
[finite enumeration](EXACT_INFERENCE.md). These checks also run in the full suite.

All **99/99 final matrix runs passed** locally on 17 September 2026 using
Koka 3.2.3, Node 24.21.0 and `jsnode` on macOS arm64. The
[recorded results](multi-model-results.csv) contain every model/method/seed cell.
The smaller-budget failure described below is retained as a limitation of that
initial configuration. These results do not establish correctness for arbitrary
models or report a hosted CI run for the current changes.

Before finite enumeration was added, the full `./bayes check` also passed: 46 library/model files compiled, all
36 baseline inference runs and 27 joint-posterior comparisons passed, all
regression/handler/AD checks passed, and all runnable examples completed.
Its 99 matrix rows reproduce the separately run suites exactly.

## Coverage

| Method | Models | Runs |
| --- | --- | ---: |
| LW | Beta–Binomial, Gamma–Poisson, finite Gaussian mixture | 9 |
| LWIS | Beta–Binomial, Gamma–Poisson, finite Gaussian mixture | 9 |
| Trace MH | Beta–Binomial, Gamma–Poisson, finite Gaussian mixture | 9 |
| SMC | Three-class classification, hidden binary process, noisy sensor calibration | 9 |
| RMSMC | Three-class classification, hidden binary process, noisy sensor calibration | 9 |
| PMMH | Three-class classification, hidden binary process, noisy sensor calibration | 9 |
| SMC² | Three-class classification, hidden binary process, noisy sensor calibration | 9 |
| Checkpoint SMC | Three-class classification, hidden binary process, noisy sensor calibration | 9 |
| HMC | Thermometer, Bayesian linear regression, logistic intercept | 9 |
| MALA | Thermometer, Bayesian linear regression, logistic intercept | 9 |
| Simulation | Beta–Binomial, Gamma–Poisson, finite Gaussian mixture; prior checks | 9 |

Models match each method's interface. Gradient methods use continuous
differentiable targets. Particle methods include latent state; PMMH and SMC²
exercise noisy inner filters in the hidden-process and sensor examples. The
generic MH chain is exercised through PMMH and the existing asymmetric-proposal
and rejection audit.

## Independent reference answers

[Trace examples](../tests/trace_examples.kk) check means, variances and several
CDF points, plus LW evidence:

- **Beta–Binomial:** a Beta(2,3) prior and two Binomial(5) counts, 4 and 2,
  give Beta(8,7). Evidence is `25/1001`, including both binomial coefficients.
  CDF references at 0.25, 0.5 and 0.75 come from finite binomial sums.
- **Gamma–Poisson:** a Gamma(shape 2, scale 1.5) prior and counts 1, 4 and 2
  give Gamma(shape 9, rate 11/3). Moments, evidence and CDF values at 1, 2,
  3 and 4 follow analytically.
- **Finite mixture:** three possible Gaussian means have prior probabilities
  0.2, 0.5 and 0.3. Two readings give three directly calculated posterior
  masses and their evidence. Two CDF checks identify all three masses.

Simulation uses the same models and clamped observations, but checks latent
draws against the prior. Simulation alone does not condition the prior on data.

[Particle examples](../tests/particle_examples.kk) use:

- **Classification:** all three posterior category probabilities and evidence
  are calculated by multiplying prior and Bernoulli likelihoods.
- **Hidden process:** exhaustive enumeration of 32 parameter/latent-path
  combinations supplies the parameter/final-state joint, initial-state marginal
  and evidence. The tests check these quantities, not every full-trajectory cell.
- **Sensor calibration:** a Gaussian parameter with latent Gaussian fluctuations
  and measurement noise has an analytically Gaussian posterior. Tests check
  parameter and final latent-state means, centered second moments, covariance
  and evidence after marginalizing the nuisance variables.

SMC, RMSMC, SMC² and checkpoint SMC report valid evidence estimates. PMMH's
retained likelihood estimates are conditional quantities sampled under its
extended posterior, so their average is not compared to marginal evidence.

[Gradient examples](../tests/gradient_examples.kk) check posterior means and
centered second moments; regression also checks covariance, and logistic
inference checks predictive success probability:

- **Thermometer:** three Normal observations under a Normal prior give an
  analytic Gaussian posterior.
- **Regression:** independent Normal priors for intercept and slope give a
  posterior whose moments follow from a separately calculated 2×2 precision inverse.
- **Logistic intercept:** nine successes and one failure under a Normal(0,2)
  prior give a non-Gaussian posterior. Independent Simpson quadrature is checked
  by doubling grid resolution and expanding the integration domain. Mean,
  variance and predictive references agree to `1e-8` under those checks.

Gradients also agree with independent analytic derivatives before sampling.
The logistic reference mean is approximately 1.9789304, variance 0.7759141 and
predictive probability 0.8505267.

## Budgets and tolerances

| Method | Budget per run |
| --- | --- |
| Simulation, LW, LWIS | 6,000 draws |
| Trace MH | 14,000 transitions, 2,000 burn-in |
| SMC, checkpoint SMC | 4,000 particles, three observations |
| RMSMC | 700 particles, two moves per step |
| PMMH | 2,000 transitions, 400 burn-in, two inner particles |
| SMC² | 600 outer particles, four inner particles, one move per step |
| HMC | 8,000 transitions, 1,000 burn-in, four leapfrog steps |
| MALA | 14,000 transitions, 2,000 burn-in |

Seeds: `1301,1303,1307` for trace/simulation, `3011,3023,3037` for particle
methods and `1201,1213,1217` for gradient methods. HMC step sizes are 0.20,
0.16 and 0.30 for thermometer, regression and logistic respectively; MALA uses
0.70, 0.55 and 1.0.

The source files declare every tolerance. Principal bounds are:

- Trace posterior mean errors: 0.02, 0.09 and 0.065 respectively; variance
  errors: 0.0025, 0.12 and 0.055; maximum CDF errors: 0.045, 0.045 and 0.035.
  LW evidence must be within 10% of its exact value.
- Particle finite probabilities: 0.075 absolute error. Classification also caps
  each cell's tolerance at 65% of its true probability, so losing its rare
  positive-probability category fails. Gaussian statistic bounds are
  `[0.12,0.12,0.12,0.15,0.12]` in the source's stated order. Evidence tolerance
  is 15% relative.
- Gradient means: 0.10 posterior standard deviations; centered second moments:
  12% of posterior variance; regression cross moment: 0.10 times the product of
  posterior standard deviations; logistic predictive probability: 0.012.

These are regression bounds, not confidence intervals or convergence proofs.
Moments and selected probabilities cannot detect every posterior defect.
Existing support, rejection, observation-stream, handler-composition,
gradient-math and asymmetric-proposal checks remain in the full suite.

## Result format and practical limits

Each run emits a CSV row with these fields:

```text
example,family,model,algorithm,seed,max_error_ratio,status
```

The ratio is the largest error divided by its declared tolerance; passing
requires a finite value at most one. This is a test diagnostic, not an accuracy
ranking across models or methods. The runner verifies every expected cell and
rejects missing rows, duplicates and invalid or failing values, even if a
completion marker was printed.

An initial classification run with 1,400 checkpoint-SMC particles and seed 3023
estimated category probabilities `[0.05357,0.70143,0.24500]`, against exact
`[0.03870,0.63235,0.32895]`. Its largest error, about 0.08395, exceeded the
0.075 bound. The SMC and checkpoint-SMC budgets were increased to 4,000 for all
three models and seeds; the posterior and evidence tolerances were unchanged.
The final matrix therefore assesses the larger budget, not a claim that every
smaller population will meet these bounds.

The PMMH budget uses two inner particles because retained observation-output
aggregation currently grows quadratically with the number of saved observations.
An initial larger budget exposed this runtime cost; posterior tolerances stayed
unchanged. These examples test statistical behavior at the listed budgets,
not performance on large data sets or arbitrary posterior geometry.

</details>
