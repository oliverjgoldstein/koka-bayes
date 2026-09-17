# Correctness assessment and development priorities

The [17 September algorithm audit](INFERENCE_AUDIT.md) reviews every inference
method, adds an exact joint-posterior oracle and asymmetric-kernel checks, and
records two further shared-sampler repairs.

Assessment date: 2026-09-15. Current test environment: Koka 3.2.3, Node.js
24.21.0, `jsnode`, macOS arm64. The repository pins the [current official Koka
release](https://github.com/koka-lang/koka/releases/tag/v3.2.3) in `.koka-version`.
The installed compiler was already 3.2.3; the build checks, installer URL, and
documented baseline have been updated to match it. The subsequent dependency
update installs both tools locally from checksum-locked official archives.

## What the tests establish

The original smoke suite passed before this work. It primarily checked execution,
output sizes, observation order, and finite weights. Those checks did not establish
that inference targeted the right posterior.

The [benchmark suite](BENCHMARKS.md) assigns simple problems to the methods they
exercise directly. It does not run every method on every model:

| Methods | Problem | Why it is useful |
| --- | --- | --- |
| LW, LWIS, MH | Beta–Bernoulli coin: Beta(5,4) posterior | One unknown probability, four observations, exact conjugate answer |
| LW, LWIS, MH | Gaussian mean: N(1,1/3) posterior | One continuous latent variable and two observations |
| SMC, RMSMC | Fixed-parameter two-state, two-step HMM | Four possible state paths; tests filtering without parameter inference |
| PMMH, SMC² | One binary parameter and one persistent binary state, two noisy observations | Four parameter/state combinations; a minimal nontrivial noisy inner filter |

These ten model/algorithm pairs run with three fixed seeds each, for 30 runs.
Tests include posterior CDF values as well as moments;
available importance/particle evidence estimates are compared on the probability
scale. Posterior PMMH likelihood estimates are not evidence estimates. See the
protocol for sample budgets, tolerances, results, and statistical limitations.

Additional regression tests target defects that these small positive-density
benchmarks do not necessarily reveal.

The complete [CSV results](benchmark-results.csv) record every current benchmark
run; the [protocol](BENCHMARKS.md) gives budgets, tolerances, and maximum errors.
All **30/30** cases pass on the pinned tools. The fixed test models live under
`tests/`, independently of the editable starter `model.kk`. `./bayes check`
compiles the active modules, runs the runner, inference, regression, and
differentiation tests, and runs the starter and small examples. On Windows use `.\bayes.cmd check`.

The test wrapper requires each suite's exact completion marker as well as a zero
command exit status. This matters because Koka's Node exception handler can print
an uncaught assertion failure and still exit zero. An intentional failing Koka
program was used to verify that the wrapper returns failure.

### Comparison with the starting revision

Before narrowing the default suite to method-specific examples, an initial broader
matrix ran all seven algorithms on the coin, Gaussian, and a three-step HMM with
an unknown parameter. All 63 corrected runs passed, and their
[CSV results](extended-benchmark-results.csv) are preserved separately. These
earlier results use different model assignments and budgets from the current suite.

For that earlier matrix, the source at `aa32580b7ab3db5adcb74b5bd1a0ac8a9c0fbf60` was compiled with the
same Koka 3.2.3/Node 24.18.1 toolchain as the earlier matrix in an isolated
temporary directory. The same models,
seeds, tolerances, and earlier MH/SMC² budgets were run; other algorithms were omitted
from this historical comparison. All **9 original MH runs failed**, while all
**9 original SMC² runs passed** these positive-likelihood benchmarks. The final
implementation passed all 18 corresponding runs in the earlier matrix. The [historical CSV](baseline-benchmark-results.csv)
preserves the results, including failures.

For example, original Gaussian MH means ranged from **0.697336 to 0.713452** when
the exact mean is **1**. This is direct evidence of a material inference error
that the original smoke suite did not detect. The SMC² result also demonstrates
the limits of these three benchmarks: they do not exercise its zero-support
problem, which needs the separate retained-state regression below.

## Findings and repairs

### MH counted the prior twice

The proposal keeps a trace prefix and regenerates its suffix from the model prior.
The old acceptance ratio used the full joint density without cancelling the
regenerated prior against the proposal density. For an unobserved Bernoulli(0.8),
this changes the stationary success probability to
`0.8² / (0.8² + 0.2²) = 0.941176…`, although the answer must remain 0.8.

Acceptance now uses observed likelihoods and the ratio of selectable latent-site
counts. Regression tests cover an unobserved biased coin, a program whose trace
length depends on a sampled branch, and dependent suffix regeneration.

### SMC² must retain appropriate auxiliary state and support

SMC² now retains and extends each inner filter. Resampling copies the whole filter;
rejuvenation proposes a fresh prefix filter and preserves the old one on rejection.
This follows the propagation and PMCMC structure of the [original SMC²
paper](https://arxiv.org/abs/1101.1528).

The old implementation independently recomputed full-prefix filters and divided
their likelihood estimates. Such ratios can form a valid extended-space SMC sampler
when all estimates are strictly positive, so independence alone does not prove
bias. Zero likelihood estimates can violate the support of the implicit backward
kernel, however. Small positive substitutes can hide that problem behind very
large importance-weight variance.

The regression uses `p ∈ {0.2,0.8}` with equal prior probability and one persistent
state `z ~ Bernoulli(p)`. Observing `z=true` twice has likelihood `p`, because the
same state is observed twice. The exact posterior mean of `p` is **0.68**. With one
inner particle, discarding zero-weight prefixes and independently restarting them
can instead introduce another survival factor `p`, giving **0.76470588**. The new
retained-filter test checks both the mean and evidence **0.5** across three seeds.

The same finite-budget probe was also executed against the original and corrected
sources (seeds 211, 419, 839; 2,000 outer particles, one inner particle, two steps,
no rejuvenation). Original means were **0.7676, 0.7589, 0.7712**, with evidence
**0.3376, 0.3434, 0.3265**. Corrected means were **0.6515, 0.6929, 0.6932**, with
evidence **0.4990, 0.5085, 0.4965**. The old code clipped impossible probabilities
to `1e-9`, so this comparison demonstrates severe finite-population error, not
universal asymptotic bias. [Probe results](probe-comparison.csv) also record the
unobserved Bernoulli MH comparison: original means **0.9439–0.9510** versus
corrected **0.7905–0.8017**, for an exact mean of **0.8**.

A separate deterministic replay check verifies that filtering all steps together
and extending a retained filter consume the same randomness and produce identical
trajectories, evidence, and output observations.

### Boundary probabilities, initial weights, and execution isolation

- Bernoulli and Binomial probabilities 0 and 1 now represent exact impossible or
  certain outcomes. Poisson rate 0 samples zero. Distribution parameters are
  validated instead of silently clipped, reversed, or substituted.
- Negative categorical indices have zero mass. Categorical normalization scales
  large finite weights before summing. Poisson sampling uses bounded independent
  chunks to avoid truncation from `exp(-rate)` underflow.
- A population with no finite positive mass returns no resampled posterior.
  Impossible data no longer cause an arbitrary uniform fallback. NaN and positive
  infinite log weights are rejected; negative infinity is valid zero mass.
- Observations executed in parameter-prior and initial-state stages contribute to
  the relevant targets and particle evidence. Tests include parameter-dependent
  observations inside the prior.
- LW, simulation, and MH allocate trace state for each invocation. Nested execution
  no longer overwrites another invocation's counters or weights.

These changes deliberately alter edge-case behavior. An empty result can indicate
impossible observations or particle depletion; it is not a posterior sample.

## Differentiable programming

The new `smooth<a>` effect supports evaluation, forward AD, and reverse AD over
scalar arithmetic. The reverse handler resumes the rest of the program, then
accumulates derivative contributions while returning through the handlers. The
implementation uses Koka's continuation handlers and has no global AD state.

Analytic tests cover the paper's polynomial, shared expressions, every supported
primitive, Gaussian densities, and Gaussian posterior gradients. The Gaussian
MAP example recovers the known optimum within `9.4e-10`. Full API details and
limits are in the [AD guide](AUTODIFF.md). MAP estimates a mode; it does not sample
posterior uncertainty.

## What remains before claiming broad leadership

This remains a research library embedded in Koka. Passing these checks does not
prove general inference correctness or make it the best PPL or differentiable
language. The next priorities have explicit acceptance criteria:

1. **Connect model densities to AD.** Introduce continuous latent coordinates,
   parameter transforms and log-Jacobians, and differentiable log-joint evaluation.
   Require agreement with existing model log probabilities and analytic gradients
   before adding gradient-based samplers.
2. **Add HMC, then NUTS.** Test leapfrog reversibility and energy error, Gaussian
   posterior moments, constrained parameters, and a difficult geometry such as
   a funnel. Report divergences, effective sample size, and multiple-chain
   convergence diagnostics.
3. **Broaden calibration.** Add simulation-based calibration, longer state-space
   models, multimodal posteriors, more seeds, and comparisons with independently
   implemented reference systems. Fixed-seed tolerances are regression checks,
   not confidence intervals or a universal convergence guarantee.
4. **Improve composition.** Replace remaining `unsafe-total` inference state,
   introduce explicit sequential observation roles and structured trace addresses,
   and test nested/mixed inference beyond the covered cases. Supported sequential
   environments use distinct names per stage, singleton prior/initial observations,
   and one occurrence per step with per-step observation lists. Singleton reuse
   across multiple steps is unsupported.
5. **Measure and optimize.** Benchmark runtime and memory at matched statistical
   accuracy. Add efficient resampling, ESS-triggered resampling, and adaptive
   particle counts before claiming speed. Current list-based traces, population
   accumulation, and multinomial resampling have scaling costs.
6. **Extend AD deliberately.** Add vector/tensor operations, differentiable
   branching semantics, custom derivative rules, higher derivatives, and
   checkpointing with separate correctness and memory tests. Existing sample,
   discrete-choice, and resampling operations are not automatically differentiable.

Extreme floating-point parameter ranges, native C performance, large reverse
continuations, distributed execution, and arbitrary custom proposal kernels have
not been validated by this assessment. Custom kernel score/proposal contracts are
documented in the source and [usage guide](USAGE_GUIDE.md).
