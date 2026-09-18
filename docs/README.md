[Koka Bayes](../readme.md)

# Documentation

Write a model. Supply observations. Choose how to infer the unknowns.

## What works today

**Gradients can drive HMC and MALA. Automatic gradients of inference results
are not implemented.** Finite enumeration and the sampling algorithms work
within their supported model interfaces; enumeration's weights are not connected
to AD. Arbitrary handler composition has no correctness proof here.

**Known empirical limitation:** recorded SIR runs miss parameter-recovery
thresholds for PMMH and SMC². This does not by itself establish an algorithm bug
or support a claim of reliable performance on every model.

Read the [support table and limits](STATUS.md) before choosing an approach,
and the [recorded SIR limitation](INFERENCE_AUDIT.md#known-empirical-limitation).

## Start here

1. [Install](INSTALLATION.md) — set up the tools and run the starter.
2. [Write your model](USAGE_GUIDE.md) — keep model, data and results in one file.
3. [Try a thermometer](TEMPERATURE.md) — infer a temperature from noisy readings.

## Choose an approach

[See the models, illustrated](MODELS.md) — what each model asks and which
inference algorithms are tested on it.

| I want to… | Read |
| --- | --- |
| Compute a posterior over finite choices | [Exact inference](EXACT_INFERENCE.md) |
| Try the sampling algorithms | [Inference examples](INFERENCE_EXAMPLES.md) |
| See which model each algorithm uses | [Visual model guide](MODELS.md#which-algorithm-uses-which-model) |
| Sample using gradients | [HMC and MALA](GRADIENT_INFERENCE.md) |
| Differentiate a function | [Automatic differentiation](AUTODIFF.md) |
| Compose inference with handlers | [Handler composition](HANDLER_COMPOSITION.md) |

## Run the examples

```sh
make examples
make check
```

`examples` runs the demonstrations. `check` compiles the project, checks the
algorithms and runs the examples. Use `make help` for individual commands.

## Understand the implementation

Start with the [effects and handlers reference](EFFECTS_AND_HANDLERS.md).
It lists every library effect and explains how the model's requests become
observations, samples, traces and weights.

| Reference | Details |
| --- | --- |
| [Relationship to the original thesis](PAPER_COMPARISON.md) | Corresponding handlers, implementation changes, later additions and proof boundaries |
| [Effects, tracing and weighting](EFFECTS_AND_HANDLERS.md) | Operation types, handler clauses, model measure, replay rules and failure behavior |
| [Sequential handlers](SEQUENTIAL_HANDLERS.md) | Continuations, populations, evidence equations and RMSMC/PMMH/SMC² contracts |
| [Enumeration handlers](ENUMERATION_HANDLERS.md) | Finite branching, path masses, normalization, pruning and work budgets |
| [Differentiation handlers](AD_HANDLERS.md) | Every primitive rule, forward/reverse propagation and probabilistic model interpretation |

Each reference links its claims to implementation and tests, and distinguishes
mathematical targets from properties actually checked or proved.

<details>
<summary>Tests, design and reference</summary>

### Verification

- [Multiple models](MULTI_MODEL_VALIDATION.md) — models, budgets and tolerances.
- [Baseline benchmarks](BENCHMARKS.md) — independent posterior reference answers.
- [Inference audit](INFERENCE_AUDIT.md) — algorithm invariants and regressions.
- [Correctness history](ASSESSMENT.md) — repaired issues and remaining limits.

These checks cover specific models and budgets; they do not establish correctness
or convergence for every program. Finite enumeration explores supported execution
trees exactly up to floating-point rounding.

### Design

- [Comparison with monad-bayes](MONAD_BAYES_COMPARISON.md)
- [Algorithm reference](development/ALGORITHM_COVERAGE.md)
- [Source map](development/ARCHITECTURE_MAPPING.md)
- [Design notes](development/DESIGN_NOTES.md)
- [Migration history](development/MIGRATION_PLAN.md)

</details>
