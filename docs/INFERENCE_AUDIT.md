[Docs](README.md) · [Get started](USAGE_GUIDE.md)

# Inference audit

This audit checks posterior targets, proposal corrections and retained particle state.

```sh
make test-inference-audit
```

The tests include 27 joint-posterior comparisons and targeted regressions. The record below gives the assumptions, equations and limits of the review.

## Known empirical limitation

**Recorded SIR runs miss parameter-recovery thresholds for PMMH and SMC²:**
report-rate errors are about **0.148 and 0.151**, respectively, against a limit
of **0.12**. The [recorded results](sir-audit-results.csv) preserve these failures.

These compare estimates with generating parameters, not exact posterior means.
They do not distinguish Monte Carlo error from posterior uncertainty or prior
influence, so they do not by themselves establish an algorithm bug. They also
prevent claiming reliable performance on every model. Passing other benchmark
checks does not resolve these failures.

See [what works today](STATUS.md) for implemented features, missing gradient
capabilities and the limits of the correctness evidence.

The report now labels recovery separately for each parameter, preserves full
numeric precision in its CSV files, and shows draw counts, distinct values and
empirical 90% intervals. Empty or nonfinite samples are rejected. These repairs
make the diagnostics more informative; they do not fix the recovery failures.
The original seeds, budgets and tolerances are unchanged.

## Small SIR posterior check

`make test-sir` checks the real SIR transition and observation code against an
independent exhaustive calculation for five people: four susceptible and one
infected initially, fixed gamma `0.3`, equal prior probabilities for beta in
`{0.4, 1.0}` and report rate in `{0.2, 0.7}`, and observations `[0, 1, 1]`.

The reference sums all infection and recovery counts and Poisson observation
weights. Evidence is `0.026548262947988184`; posterior probabilities are
`0.5597371636713165` for beta `1.0`, `0.5197103355157454` for report rate `0.7`,
and `0.2583800924418703` for both. This checks the posterior, rather than recovery
of a generating parameter.

[The test](../tests/sir_inference.kk) compares all four parameter cells and both
marginals for SMC, custom PMMH and custom SMC² at seeds `3011`, `3023`, `3037`.
Budgets and tolerances were set before running: SMC has 4,000 particles; PMMH
has 3,000 iterations, 600 burn-in and eight inner particles; SMC² has 800 outer
and eight inner particles with one move per observation. Absolute posterior
tolerance is `0.075`; relative evidence tolerance for SMC and SMC² is `15%`.
Asymmetric proposals exercise the Hastings correction. The test also checks
population conservation, retained output counts and observation consumption.

A local run on 18 September 2026 passed all nine algorithm/seed combinations.
The largest posterior error was about `0.0393`; the largest relative evidence
error was about `3.34%`. This records local validation, not a hosted CI result.

These checks and the [report-summary regressions](../tests/sir_report_checks.kk)
run in `make check` and CI. This small finite-parameter model does not establish
adequate mixing for the larger continuous-parameter SIR example.

<details>
<summary>Read the audit and its assumptions</summary>

## Inference correctness audit — 17 September 2026
The review covers the algorithms at its original baseline, shared distribution
sampling, observation handling, trace replay and weight normalization. Later
[gradient](GRADIENT_INFERENCE.md), [checkpoint](HANDLER_COMPOSITION.md) and
[enumeration](EXACT_INFERENCE.md) extensions have separate coverage. The inference
at the original audit baseline was shared by `master` and
`feat/handler-autodiff`. The subsequent gradient and handler extensions are
developed on `feat/handler-autodiff`. Historical code under `archive/` is not
supported.

The reviewed update equations agree with the intended algorithms under the
contracts below. Tests give regression evidence on finite models and budgets;
they do not prove correctness or convergence for arbitrary programs.

The later [handler-composition review](HANDLER_COMPOSITION.md) checks RMSMC,
PMMH and SMC² more directly. It confirms supported nested-call isolation and
retained-state behavior. Its subsequent implementation repairs the reproduced
multi-shot trace-state leak and singleton observation mismatch, and adds reusable
scoring, tracing, checkpoint and population components. The tests do not establish
arbitrary handler compositionality.

## Algorithm review

| Algorithm | Reviewed invariant | Evidence |
| --- | --- | --- |
| Simulation | Draw latent choices from the model and clamp supplied observations; this alone does not condition the prior | Observation-order, trace/isolation and prior-frequency checks |
| LW | Prior proposal factors cancel; the weight is the product of observed likelihoods | Conjugate coin/Gaussian benchmarks and enumerated joint posterior/evidence |
| LWIS | Multinomial resampling uses normalized LW weights; zero mass is never selected | The same posterior oracles, weight-collapse and support checks |
| Trace MH | Retain the prefix and regenerate the suffix; acceptance uses likelihood ratio times old/new latent-site counts | Prior cancellation, dependent suffixes, variable-length branches with observations and enumerated posterior |
| Generic MH | Use target log ratio plus reverse-minus-forward proposal log density; rejection retains the state and its multiplicity | Deterministic rejection/zero-likelihood recovery checks and asymmetric kernels exercised through PMMH/SMC² |
| SMC | Bootstrap propagation, incremental likelihood weights and multinomial resampling; evidence multiplies mean incremental weights, including initialization | Exact HMM and joint posterior; independent low-particle evidence checks and retained-filter replay |
| RMSMC | Resample, then move the complete prefix using an independent prior proposal; its prior cancels in acceptance | Exact HMM and joint posterior with informative prior and initial observations |
| PMMH | Store the particle likelihood estimate with the state; regenerate it only for proposals and retain it on rejection | Exact latent/joint posterior, impossible data and asymmetric custom proposals |
| SMC² | Retain and advance each inner filter, resample complete filters and preserve them on rejected PMMH moves | Exact latent/joint posterior/evidence, zero-support persistent-state regression and asymmetric custom proposals |

For trace MH, the cancellation applies to this implementation's **suffix
regeneration** proposal. It must not be copied unchanged to a proposal that
reuses dependent suffix values. The [lightweight MH paper](https://proceedings.mlr.press/v15/wingate11a.html)
describes the broader trace/proposal-density accounting.

The stored-estimator and extended-state requirements were checked against
[Andrieu, Doucet and Holenstein's PMCMC paper](https://www.stats.ox.ac.uk/~doucet/andrieu_doucet_holenstein_PMCMC.pdf)
and [Chopin, Jacob and Papaspiliopoulos's SMC² paper](https://arxiv.org/abs/1101.1528).
An average of PMMH's retained likelihood estimates is **not** a model-evidence
estimator. Finite LWIS/SMC populations approximate their targets; MH/PMMH also
need adequate mixing and burn-in.

## Additional oracle and checks

`tests/inference_audit.kk` enumerates all 32 paths of a binary parameter,
initial state and three subsequent states. The prior is nonuniform, with
informative observations in the prior, initialization and every step.
Independent rational enumeration gives:

- Evidence: `69018819 / 2000000000 = 0.0345094095`.
- Parameter marginal: `13483998 / 23006273 ≈ 0.58610093`.
- Final-state marginal: `20109776 / 23006273 ≈ 0.87409969`.
- Joint parameter/final-state marginal: `12636576 / 23006273 ≈ 0.54926654`.

All seven inference methods and custom PMMH/SMC² are compared with all three
marginals at seeds 719, 727 and 733: **27 comparisons**. Custom proposals draw
`Bernoulli(0.85)` independently, so omitting their reverse/forward correction
would multiply the target odds by `0.85/0.15`.

| Method | Budget per seed |
| --- | --- |
| LW / LWIS | 6,000 / 4,000 draws |
| MH | 12,000 iterations, including 2,000 burn-in |
| SMC / RMSMC | 3,000 / 1,600 particles; RMSMC uses two moves per step |
| PMMH | Three inner particles; 6,000 iterations including 1,000 burn-in |
| SMC² | 1,200 outer and three inner particles; two moves per step |
| Custom PMMH | Three inner particles; 8,000 iterations including 1,000 burn-in |
| Custom SMC² | 1,600 outer and three inner particles; two moves per step |

Marginal tolerance is 0.065 absolute; evidence tolerance is 15% relative.
The first complete run passed all comparisons; its largest marginal error was
0.05141, for trace MH. These are fixed regression thresholds, not confidence
intervals or a convergence diagnostic.

Independent SMC evidence checks run 4,000 filters for each particle count 1, 2
and 4. They average likelihood estimates on the probability scale, and also
check evidence-weighted parameter marginals against the unnormalized joint.
Their tolerances are 8% relative evidence error and 0.045 normalized joint-mass
error. Additional checks cover simulation, observed variable-length MH,
rejection multiplicity, escape from zero likelihood, and impossible data in
all seven algorithms. The earlier 30 conjugate/enumerated benchmark runs remain
separate and unchanged in scope.

## Bugs reproduced and repaired

- **Categorical rounding could select zero mass.** At the largest representable
  random draw, seven equally weighted categories followed by a zero-weight
  category returned the zero-weight index. A deterministic random handler
  reproduces this. The rounding fallback now remembers the last positive-weight
  category instead of choosing the final category unconditionally.
- **Tiny positive Poisson rates returned -1.** At rate `1e-20`, `exp(-rate)`
  rounds to one. The old loop stopped before its first draw and returned
  `count - 1`. The sampler now executes the required first draw before testing
  termination. This preserves the ordinary-rate random-number sequence.
- **Small-shape Beta sampling returned NaN.** Both underlying Gamma samples
  could underflow to zero, giving `0/0`; 231 of 1,000 draws at
  `Beta(0.001, 0.001)` were non-finite in the reproduction. Gamma log samples
  and a stable logistic ratio avoid that underflow. Regressions check support,
  mean and second moment of `Beta(0.001, 0.002)` over three seeds.

These bugs are in shared sampling code and therefore affect every inference
method using those distributions, even when its inference equations are right.

The supplied **SIR custom proposal** also clamped current parameters to `1e-6`
before a log/logit random walk, although its density correction assumed no
clamping. It now preserves every valid current coordinate, validates transform
domains, uses an unclipped Box-Muller draw and a stable logistic transform.
A deterministic zero-increment test covers a small positive parameter and
rates near both boundaries; the old kernel fails it. This repairs the example's
proposal contract, independently of PMMH/SMC²'s generic acceptance equations.

## Contracts and remaining limits

- Replay must be deterministic conditional on traced choices. Untraced random
  calls or changing external state can invalidate MH and prefix rejuvenation.
- Sequential observations are consumed once in execution order. Each particle
  retains its remaining stream through propagation, resampling and rejuvenation;
  direct execution and prefix replay use the same semantics. Repeated equal
  observations must be supplied explicitly instead of relying on singleton reuse.
- Custom kernels must supply the complete parameter target and correct proposal
  ratio. Custom SMC² initialization also requires exposed prior latent coordinates;
  hidden or transformed coordinates need additional density accounting.
- Empty particles can mean finite-particle depletion or impossible data. They
  are not a valid posterior. NaN and positive-infinite importance weights are
  rejected; finite scores are required for usable MCMC output.
- Extreme floating-point ranges beyond the tested cases, arbitrary effect
  composition, long-run mixing and large-scale calibration remain unverified.
  The [recorded SIR failures](#known-empirical-limitation) remain unresolved;
  see the [usage guide](USAGE_GUIDE.md#sir-diagnostics) for diagnostic commands.

Run `make test-inference-audit` (or `./bayes inference-audit`). The audit is also
included in `make tests`, `make check`, and clean-install CI.

</details>
