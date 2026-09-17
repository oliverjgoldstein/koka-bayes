[Koka Bayes](../readme.md)

# Documentation

Write a model. Supply observations. Choose how to infer the unknowns.

## Start here

1. [Install](INSTALLATION.md) — set up the tools and run the starter.
2. [Write your model](USAGE_GUIDE.md) — keep model, data and results in one file.
3. [Try a thermometer](TEMPERATURE.md) — infer a temperature from noisy readings.

## Choose an approach

| I want to… | Read |
| --- | --- |
| Compute a posterior over finite choices | [Exact inference](EXACT_INFERENCE.md) |
| Try the sampling algorithms | [Inference examples](INFERENCE_EXAMPLES.md) |
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
