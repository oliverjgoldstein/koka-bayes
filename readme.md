<p align="center">
  <img src="docs/assets/koka-bayes-logo.png" width="112" alt="Koka Bayes logo">
</p>

<a id="koka-bayes"></a>
<h1 align="center">Koka Bayes</h1>

<p align="center">Probabilistic programming with effect handlers.</p>

<p align="center">
  <a href="docs/USAGE_GUIDE.md">Get started</a> ·
  <a href="docs/README.md">Documentation</a> ·
  <a href="docs/INFERENCE_EXAMPLES.md">Examples</a>
</p>

Write a model in Koka, add observations, and choose an inference method.

## What works today

**You can use gradients to perform inference. Automatic differentiation of
inference results is not implemented.**

| Available | Not implemented |
| --- | --- |
| LW, LWIS, MH, SMC, RMSMC, PMMH and SMC², tested on multiple examples | Automatic gradients through these inference algorithms |
| Finite enumeration of supported choices, up to floating-point rounding | Differentiating enumerated posterior probabilities or evidence |
| Forward/reverse first derivatives and HMC/MALA for smooth, fixed-dimensional log densities | Automatic conversion of arbitrary probabilistic models to differentiable models |
| A Normal-site model interface with probabilistic and differentiable interpretations | General mixed discrete/continuous gradient inference |

Specific handler combinations are tested. **There is no general denotational
correctness proof for this implementation, and it does not inherit CHAD's guarantees.**

**Known empirical limitation:** recorded SIR runs miss parameter-recovery
thresholds for PMMH and SMC². This alone does not establish an algorithm bug;
reliable performance on every model is not established.

[Full support table and limits →](docs/STATUS.md) ·
[Recorded SIR results →](docs/INFERENCE_AUDIT.md#known-empirical-limitation)

## Start

```sh
make setup
make inference
```

Open [model.kk](model.kk). Your model, data, inference method and results live
in that one file. Setup installs the pinned tools and runs the checks; it can
take several minutes. [Installation without Make →](docs/INSTALLATION.md#without-make)

<a id="model"></a>

## A small model

The starter learns a coin's probability of heads:

```koka
fun coin-model(count : int) : model<e,float64>
  fn(){
    val p = beta'(2.0, 3.0)
    for(count) fn(_){ val _ = bernoulli(flip, p); () }
    p
  }
```

<a id="data-assumptions"></a>
<a id="results"></a>

Given three heads and one tail, its posterior mean is **5/9 ≈ 0.556**.
The starter estimates that value with likelihood weighting. Edit the data or
swap the inference method in the same file.

<a id="inference"></a>

## Explore

| Try | Guide |
| --- | --- |
| See the models and their inference algorithms | [Visual model guide](docs/MODELS.md) |
| Infer a room's temperature | [A first example](docs/TEMPERATURE.md) |
| Explore every finite choice | [Exact inference](docs/EXACT_INFERENCE.md) |
| Use HMC or MALA | [Gradient inference](docs/GRADIENT_INFERENCE.md) |
| Differentiate a Koka program | [Automatic differentiation](docs/AUTODIFF.md) |
| Combine inference handlers | [Composition](docs/HANDLER_COMPOSITION.md) |
| Understand each effect and handler | [Implementation reference](docs/EFFECTS_AND_HANDLERS.md) |
| Compare with the original Koka-Bayes thesis | [What carries over and what changed](docs/PAPER_COMPARISON.md) |

Run `make examples` for the demonstrations, `make check` for all checks,
or `make help` for commands. [What the tests cover →](docs/MULTI_MODEL_VALIDATION.md)
