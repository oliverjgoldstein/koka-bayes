[Docs](README.md) · [Effects and handlers](EFFECTS_AND_HANDLERS.md) · [Supported scope](STATUS.md)

# Relationship to the original Koka-Bayes thesis

**The current library is a reimplementation and extension of the original
effect-handler design. It is not a verbatim port or a proved equivalent
implementation.**

The original work is Oliver Goldstein's 2019 MSc thesis, supervised by Ohad
Kammar, *Modular probabilistic programming with algebraic effects*, released on
arXiv in 2024. It develops inference from modular effects and handlers, drawing
on Monad Bayes. [Read the thesis](https://arxiv.org/html/2412.19826v1).

The original source is preserved in [archive/2019](../archive/2019/).
The supported implementation is in `lib/`; use its current APIs and tests.
The archive is excluded from the supported build.

## Effects and handlers that correspond

Both designs separate model requests from their interpretation. The following
are corresponding responsibilities, not interchangeable APIs:

| Original implementation | Current implementation | What changed |
| --- | --- | --- |
| `sample()` and `random_sampler` | `draw`, `sample-value`, `handle-sampling` | Requests carry a distribution; the selected value is an `observable`, decoded by typed model wrappers. |
| `score(exp)` and `weighted` | `score`, `log-score`, `accumulate-weight`, `handle-weight` | Scoring is routed through model factors and the trace. The accumulator returns a `float64` log weight. |
| `replay` and lists of random choices | `handle-replay`, `handle-trace`, `run-trace` | Entries record addresses, distribution summaries, values and sampled/observed/factor modes. |
| `yield`, `advance`, `finalize` | `checkpoint`, `suspend`, `advance`, `run-sequential` | Suspensions explicitly store the remaining computation; advancing resumes to the next boundary. |
| Weighted populations and resampling | `resample-population`, `sample-population` | Population results expose a log normalizer and explicit evidence transfer. |

Compare the [archived declarations](../archive/2019/effects-and-types.kk) and
[handlers](../archive/2019/handlers.kk) with the current
[model interface](../lib/core/model.kk), [trace handlers](../lib/handlers/trace.kk),
[weights](../lib/handlers/weight.kk), [suspensions](../lib/handlers/sequential.kk)
and [populations](../lib/handlers/population.kk).

Log-domain weighting is not new: the archived
[`Exp` representation](../archive/2019/exponents.kk) already multiplies weights
by adding their logarithms. The representation and surrounding interfaces changed.

## Model and trace differences

The archived model alias is `model<a,e> = () -> <sample,score|e> a`.
The current alias is `model<e,a> = () -> <obs-reader,model-dist,div|e> a`.
The type-parameter order also differs.

The current observation reader consumes named data streams once per occurrence.
A named distribution request becomes an observation when matching data is
available and a latent draw otherwise; an unnamed draw is always latent.
Sample, observation and factor hooks then separate
tracing from value selection and weight accumulation. See the
[operation-by-operation reference](EFFECTS_AND_HANDLERS.md).

Archived sampling operates on uniform random numbers; for example, its
[Normal sampler](../archive/2019/model-resources.kk) consumes two `sample()`
calls. Current traces record distribution-level draws. This changes the
granularity of replay proposals. A similar trace/MH architecture does not mean
the two implementations have identical traces or transition kernels.

## How the inference compositions differ

The thesis's SMC inserts a yield after each score and advances through a chosen
number of those boundaries before resampling. [Thesis §4.2.1](https://arxiv.org/html/2412.19826v1#S4.SS2.SSS1).

Current [`smc-model`](../lib/alg/handler_smc.kk) is the closest continuation-based
counterpart: it weights and resamples suspended model executions. Its checkpoints
are explicit. Several scores can occur between checkpoints; a score alone does
not suspend the model. The separate [`smc`](../lib/alg/smc.kk) implementation
uses staged `prior`, `initial`, `step` and `finish` functions.

Current RMSMC, PMMH and SMC² share handlers and inference components while
retaining dedicated loops. PMMH retains its parameter and noisy likelihood
estimate on rejection; SMC² retains and extends inner filters and transfers
incremental evidence once. They are not obtained by copying the original
handler stack. The [sequential reference](SEQUENTIAL_HANDLERS.md) specifies
these transitions and the custom proposal contracts.

## Later additions

The thesis discusses SMC² as a further compound algorithm in
[§4.6.2](https://arxiv.org/html/2412.19826v1#S4.SS6.SSS2), and backpropagation
and exact inference through disintegration as future work in
[§6.2](https://arxiv.org/html/2412.19826v1#S6.SS2).

The current implementation adds:

- [SMC²](SEQUENTIAL_HANDLERS.md#smc²-an-outer-population-carrying-inner-filters)
  with retained inner filter state.
- [Finite enumeration](ENUMERATION_HANDLERS.md) over supported execution trees.
  It does not implement symbolic disintegration or continuous latent integration.
- [Forward and reverse AD](AD_HANDLERS.md), plus a Normal-site interface with
  probabilistic and differentiable interpretations.
- [HMC and MALA](GRADIENT_INFERENCE.md), which use deterministic log-density
  gradients. They do not differentiate sampling or posterior estimates.

These are additions relative to the archived implementation, not claims of
new inference algorithms or features already delivered by the thesis.

## What this relationship establishes

The source correspondence establishes continuity of design. It does not
establish semantic equivalence, correctness for arbitrary handler orders, or
automatic inheritance of Monad Bayes's semantic results or CHAD's guarantees.

Such claims would require connecting the current operations and state scopes
to a mathematical interpretation, then justifying each inference transformation
under its assumptions. The documentation states targets and contracts;
the tests check particular laws, state-isolation properties and independent
posterior reference answers. Neither substitutes for that proof.

See [supported capabilities and limits](STATUS.md), the
[Monad Bayes comparison](MONAD_BAYES_COMPARISON.md), and the
[inference audit](INFERENCE_AUDIT.md). The recorded SIR recovery limitations
remain applicable to this implementation.
