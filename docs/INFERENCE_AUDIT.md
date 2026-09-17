# Inference correctness audit — 17 September 2026

The review covers every active module in `lib/alg`, shared distribution sampling,
observation handling, trace replay and weight normalization. The inference
implementation is shared by `master` and `feat/handler-autodiff`. Historical code
under `archive/` is not supported.

The reviewed update equations agree with the intended algorithms under the
contracts below. Tests give regression evidence on finite models and budgets;
they do not prove correctness or convergence for arbitrary programs.

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

- **Tiny positive Poisson rates returned -1.** At rate `1e-20`, `exp(-rate)`
  rounds to one. The old loop stopped before its first draw and returned
  `count - 1`. The sampler now executes the required first draw before testing
  termination. This preserves the ordinary-rate random-number sequence.
- **Small-shape Beta sampling returned NaN.** Both underlying Gamma samples
  could underflow to zero, giving `0/0`; 231 of 1,000 draws at
  `Beta(0.001, 0.001)` were non-finite in the reproduction. Gamma log samples
  and a stable logistic ratio avoid that underflow. Regressions check support,
  mean and second moment of `Beta(0.001, 0.002)` over three seeds.

Both bugs are in shared sampling code and therefore affect every inference
method using those distributions, even when its inference equations are right.

## Contracts and remaining limits

- Replay must be deterministic conditional on traced choices. Untraced random
  calls or changing external state can invalidate MH and prefix rejuvenation.
- Sequential observations require distinct prior/initial/step names, singleton
  prior/initial observations and one occurrence of each step site per step.
  Reusing a singleton at multiple steps is unsupported: filtering repeats it
  while replay consumes it once. This restriction is documented, not enforced
  by the type system.
- Custom kernels must supply the complete parameter target and correct proposal
  ratio. Custom SMC² initialization also requires exposed prior latent coordinates;
  hidden or transformed coordinates need additional density accounting.
- Empty particles can mean finite-particle depletion or impossible data. They
  are not a valid posterior. NaN and positive-infinite importance weights are
  rejected; finite scores are required for usable MCMC output.
- Extreme floating-point ranges beyond the tested cases, arbitrary effect
  composition, long-run mixing and large-scale calibration remain unverified.
  The separately recorded SIR diagnostic tolerance miss is not erased by these
  elementary checks; see the [usage guide](USAGE_GUIDE.md#sir-diagnostics).

Run `make test-inference-audit` (or `./bayes inference-audit`). The audit is also
included in `make tests`, `make check`, and clean-install CI.
