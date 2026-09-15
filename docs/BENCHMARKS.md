# Simple correctness checks by inference method

Run `make test-inference`. The suite gives each inference method a small problem
suited to what it does, with an analytic or exhaustively enumerated answer.
It contains **30 runs: ten method/model pairs, each with three fixed seeds**.

| Methods | Elementary problem | Unknown quantities |
| --- | --- | --- |
| LW, LWIS, MH | Beta–Bernoulli coin | One coin probability |
| LW, LWIS, MH | Conjugate Gaussian mean | One real mean |
| SMC, resample-move SMC | Two-step HMM with known parameters | Two binary states |
| PMMH, SMC² | Two noisy readings of one persistent binary latent variable | One binary parameter and one binary latent variable |

This is a correctness regression suite. It does not rank systems by speed or
claim general inference correctness from success on elementary examples.

The fixed test models live in [tests/correctness.kk](../tests/correctness.kk),
independently of the editable starter `model.kk`.

Run only one method with `make test-lw`, `make test-lwis`, `make test-mh`,
`make test-smc`, `make test-rmsmc`, `make test-pmmh`, or `make test-smc2`.
Each target runs that method's applicable models with all three seeds. The
models, particle counts, and tolerances are the same as in the full suite.
LW, LWIS, and MH each run six checks; SMC, RMSMC, PMMH, and SMC² each run three.
Use `make tests` to include the separate boundary-condition and runner regressions.

Make commands work on all supported platforms with GNU Make installed. Without
Make, use `./bayes benchmark` on Linux/macOS or `.\bayes.cmd benchmark` on Windows.

The launcher checks each test suite's exact completion marker and rejects
uncaught exceptions as well as nonzero exits. Koka 3.2.3's JavaScript main handler
can otherwise print an uncaught exception while exiting zero.

## Why these problems

Beta–Bernoulli learning is a standard introductory probabilistic program; see
the [ProbMods learning exercises](https://probmods.org/exercises/learning-as-conditional-inference.html).
The Gaussian mean is another conjugate model with an independent closed-form
answer: [Murphy's Gaussian conjugacy notes](https://www.cs.ubc.ca/~murphyk/Papers/bayesGauss.pdf).

Hidden Markov models are a prototypical PPL inference benchmark. The Anglican
paper compares inferred HMM marginals with exact answers and describes analytic
and enumerated correctness references: [Wood, van de Meent and Mansinghka,
AISTATS 2014, sections 4–5](https://probprog.github.io/anglican/assets/pdf/wood-aistats-2014.pdf).
Our filtering example reduces that benchmark family to two binary states and
known parameters. It is not a reproduction of the paper's performance experiment.

PMMH and SMC² need a parameter and a particle likelihood estimate. Their example
has just four joint possibilities and no state transition. This retains a noisy
particle likelihood while making the inference problem transparent.

## Independent answers

### Coin — LW, LWIS, MH

- Prior: `p ~ Beta(2, 3)`.
- Ordered observations: `true, true, true, false`, independently Bernoulli(p).
- Posterior: `Beta(5, 4)`.
- Mean: `5/9 = 0.5555555556`.
- Variance: `5*4 / (9²*10) = 0.0246913580`.
- `P(p <= 0.5 | y) = 93/256 = 0.36328125`.
- Evidence: `B(5,4)/B(2,3) = 3/70 = 0.0428571429`.

The observations are ordered, so the evidence has **no binomial coefficient**.
The informative prior detects accidentally counting a prior twice in MH.

### Gaussian mean — LW, LWIS, MH

- Prior: `mu ~ Normal(0, 1)`; the second argument is standard deviation.
- Observations: `1, 2`, independently `Normal(mu, 1)`.
- Posterior: `Normal(1, sqrt(1/3))`.
- Mean: `1`; variance: `1/3`.
- `P(mu <= 0.5 | y) = Phi(-sqrt(3)/2) = 0.19323811538561636`.
- Evidence density: `exp(-1)/(2*pi*sqrt(3)) = 0.03380376099`.

The observation covariance after integrating out the mean is `[[2,1],[1,2]]`.
The test computes evidence from its determinant and quadratic form. Gaussian
evidence here is a density, not the probability of an exact real observation.

### Fixed-parameter two-step HMM — SMC, resample-move SMC

- `P(x0 = 1) = 0.5`.
- `P(x1 = x0) = 0.8`.
- `P(yt = true | xt = 1) = 0.8`; for state zero it is `0.2`.
- Observe `true, true`: the first observation measures `x0`, then one transition
  occurs and the second observation measures `x1`.
- All transition and observation parameters are known.

The test enumerates four state paths. Their joint probabilities including the
observations, in order `00, 01, 10, 11`, are `0.016, 0.016, 0.016, 0.256`.

| Quantity | Exact answer |
| --- | ---: |
| Evidence | `38/125 = 0.304` |
| Posterior mean of x1 = probability x1 is one | `17/19 = 0.8947368421` |
| Posterior variance of x1 | `34/361 = 0.0941828255` |
| Posterior CDF of x1 at 0.5 | `2/19 = 0.1052631579` |

The returned quantity is the final-state indicator, so the CSV mean and
final-state probability columns are identical. Its variance and CDF are also
determined by that one Bernoulli probability; they are not independent checks.

### Persistent binary latent variable — PMMH, SMC²

- `q` is `0.25` or `0.75`, with equal prior probability.
- Sample one persistent `z ~ Bernoulli(q)`.
- Observe `true, true`, conditionally independently given that same `z`.
- Each observation has success probability `0.8` when `z=1`, and `0.2` otherwise.
- There are no state transitions and no additional latent draws between readings.

The four joint masses `(q,z) = (.25,0), (.25,1), (.75,0), (.75,1)` are
`0.015, 0.08, 0.005, 0.24`. The likelihood after integrating out `z` is
`L(q) = 0.04 + 0.60*q`: `0.19` or `0.49`.

| Quantity | Exact answer |
| --- | ---: |
| Evidence | `17/50 = 0.34` |
| Posterior mean of q | `83/136 = 0.6102941176` |
| Posterior variance of q | `931/18496 = 0.0503352076` |
| Posterior CDF of q at 0.5 | `19/68 = 0.2794117647` |
| Posterior probability z is one | `16/17 = 0.9411764706` |

Both discrete references multiply probabilities directly. They do not call the
inference algorithms or the distribution library's scoring functions. The suite
also checks both enumerations against the independent rational answers above
to `1e-12`, guarding errors in the shared summary helper and the oracle.

## Work, estimators and fixed tolerances

The seeds are `2027`, `4093`, and `8191`. Every seed must pass separately. The
suite prints every result, including failures; it does not pool seeds to hide
opposing errors.

| Algorithm | Work per applicable model and seed |
| --- | --- |
| LW | 2,000 weighted prior draws |
| LWIS | 1,000 weighted draws and 1,000 resampled outputs |
| MH | 3,000 transitions, first 500 discarded |
| SMC | 800 particles |
| Resample-move SMC | 600 particles, one MH move per observation |
| PMMH | 4 inner particles; 1,500 transitions, first 300 discarded |
| SMC² | 600 outer particles, 4 inner particles, one rejuvenation move |

LW moments and CDFs use normalized importance weights. Resampled particles have
equal weight. MH and PMMH retain repeated states after rejection. Population
variance is computed around the estimated mean. The latent-variable estimate
for PMMH/SMC² averages each retained inner particle cloud and then averages over
parameter samples. Those particles and MCMC states are correlated; their count
is not an effective independent sample size.

| Metric | Maximum absolute error, per seed |
| --- | ---: |
| Mean, except Gaussian | 0.05 |
| Mean, Gaussian | 0.10 |
| Variance, coin and persistent-latent parameter | 0.015 |
| Variance, binary HMM | Derived from marginal bound; see below |
| Variance, Gaussian | 0.075 |
| CDF at 0.5, binary HMM | 0.05 |
| CDF at 0.5, other models | 0.075 |
| Final-state or persistent-latent probability | 0.085 |
| Evidence | 15% of the analytic evidence |

The binary HMM's variance is `v(p) = p(1-p)`. For a permitted probability error
`delta = 0.05`, its variance error is bounded by
`abs(1 - 2*p)*delta + delta²`, or approximately `0.041974` here. The test uses
that derived bound rather than an unrelated continuous-parameter variance
threshold. Its mean and CDF checks each require the full two-state marginal to
be within `0.05` of the exact answer.

Initially applying the old `0.015` continuous-parameter variance threshold to
this binary HMM gave two RMSMC failures (variance errors `0.0150273` and
`0.0177939`) even though their state probabilities met the prescribed marginal
bound. This revealed a redundant-metric threshold mismatch. The final binary
variance bound follows algebraically from the marginal bound; the observations,
seeds and particle counts are unchanged. Other model thresholds retain the
previous bounds, and the HMM CDF bound is tightened from `0.075` to `0.05`.

These are regression tolerances, not calibrated confidence intervals or a
false-failure guarantee. A failure requires investigation, not automatic
widening of a threshold.

Evidence checks use the mean unnormalized LW weight or `exp(log_evidence)` from
SMC/RMSMC/SMC². LWIS and MH do not expose evidence. PMMH's likelihood estimates
are sampled under a posterior extended target, so their average is not a model
evidence estimator. Those three methods print `NA` in the evidence column.

## Recorded results

The [current CSV](benchmark-results.csv) contains the 30 method/model/seed runs
recorded on 2026-09-15: **30 passed, zero failed**.
Environment: Koka `3.2.3`, `jsnode` in its default debug configuration, Node.js
`v24.21.0`, macOS (`Darwin`) on `arm64`. The pinned local toolchain reproduces all
30 saved rows exactly. An earlier run on Node 24.18.1 took approximately 2.9
seconds for the already compiled program; compilation is excluded. This is a local
reproducibility detail, not a performance comparison.

These are the largest errors over the applicable methods and all three seeds,
without pooling samples across runs:

| Model | Mean error | Variance error | CDF error | Relative evidence error | Latent-state probability error |
| --- | ---: | ---: | ---: | ---: | ---: |
| Coin | 0.015628 | 0.001005 | 0.049681 | 1.98% | — |
| Gaussian | 0.038374 | 0.044453 | 0.033238 | 2.21% | — |
| Fixed HMM | 0.021930 | 0.017794 | 0.021930 | 7.73% | 0.021930 |
| Persistent latent variable | 0.018039 | 0.004305 | 0.036078 | 1.64% | 0.010907 |

Mean estimates ranged from `0.548336` to `0.571183` for the coin (truth
`0.555556`), `0.986332` to `1.038374` for the Gaussian (truth `1`),
`0.876250` to `0.916667` for the HMM's final-state probability (truth
`0.894737`), and `0.603750` to `0.628333` for the persistent-latent model's
parameter (truth `0.610294`). These describe the observed runs, not confidence
bounds.

The previous 63-run all-method/all-model experiment is kept separately as an
[exploratory archive](extended-benchmark-results.md). It is not the current
method-specific correctness suite.

## Limits

These tests can reveal elementary inference mistakes. They do not establish
correctness for arbitrary programs, high-dimensional mixing, tail accuracy,
multimodal exploration, long-sequence particle degeneracy, performance rankings,
parallel safety or differentiable-inference estimators. Hard support, impossible
observations and dynamic traces have separate regression tests. Differentiation
checks are also separate from posterior inference checks.
