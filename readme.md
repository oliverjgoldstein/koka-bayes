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
Use finite enumeration, sampling, or gradients to answer questions about it.

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
| Infer a room's temperature | [A first example](docs/TEMPERATURE.md) |
| Explore every finite choice | [Exact inference](docs/EXACT_INFERENCE.md) |
| Use HMC or MALA | [Gradient inference](docs/GRADIENT_INFERENCE.md) |
| Differentiate a Koka program | [Automatic differentiation](docs/AUTODIFF.md) |
| Combine inference handlers | [Composition](docs/HANDLER_COMPOSITION.md) |

Run `make examples` for the demonstrations, `make check` for all checks,
or `make help` for commands. [What the tests cover →](docs/MULTI_MODEL_VALIDATION.md)
