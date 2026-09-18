[Docs](README.md) · [Get started](USAGE_GUIDE.md)

<a id="a-room-and-three-thermometer-readings"></a>

# Three thermometer readings

The readings are **19, 21 and 22°C**. What is the room's temperature?

```sh
make inference MODEL=examples/temperature.kk
```

Our model starts with a guess of 20°C, with standard deviation 2°C.
Each reading has independent Normal noise with standard deviation 1°C.
The room stays at one temperature; this model has no shared thermometer bias.

The [program](../examples/temperature.kk) uses 6,000 likelihood-weighted draws.
It prints its estimate beside the exact answer: **20.615°C**, with posterior
standard deviation **0.555°C**. Sampling estimates will vary.

## The exact answer

<details>
<summary>Why the answer is 20.615°C</summary>

Using variance as the second argument, `T ~ N(20,4)` and each
`reading | T ~ N(T,1)`. Koka's `normal` takes **standard deviation**, so
its prior argument is `2.0` and its reading-noise argument is `1.0`.

The posterior is Normal. Independent precisions—reciprocals of variance—add:

```text
precision = 1/4 + 3 = 13/4
variance  = 4/13
mean      = (20/4 + 19 + 21 + 22) / (13/4) = 268/13
```

The posterior mean and most probable value coincide.

</details>

## Differentiating the same model

On the `feat/handler-autodiff` branch:

```sh
make inference MODEL=examples/autodiff.kk
```

This [example](../examples/autodiff.kk) uses reverse AD to find the most probable
temperature by gradient ascent. It imports the same data and parameters.
Each reading contributes a differentiable score; a fold adds them to the prior.

The sampling example estimates a posterior expectation. Gradient ascent finds
the mode of a deterministic log density; it does not differentiate through the
sampler. [HMC and MALA](GRADIENT_INFERENCE.md) use gradients for posterior sampling.

<details>
<summary>Derivative and optimization check</summary>

Dropping terms that do not depend on temperature:

```text
L(T)  = -(T-20)^2/8 - ((19-T)^2 + (21-T)^2 + (22-T)^2)/2
L'(T) = 67 - 13*T/4
```

The derivative vanishes at `268/13`; the second derivative is `-13/4`, so
this is the unique maximum. The program obtains the derivative from its handler.
Sixteen steps from 16°C, with learning rate 0.25, reach absolute error below
`1e-8`°C; the example checks this bound. Broader checks are in the
[inference audit](INFERENCE_AUDIT.md).

</details>

Without Make, run `./bayes run examples/temperature.kk` or
`./bayes run examples/autodiff.kk`. On Windows, use `.\bayes.cmd`.
