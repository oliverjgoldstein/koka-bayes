# A room and three thermometer readings

What is the temperature of a room when its thermometer readings disagree?

- Before measuring, our best guess is 20°C, with standard deviation 2°C.
- The readings are 19, 21, and 22°C.
- Each reading has independent normal noise with standard deviation 1°C.
- The room's temperature stays fixed during these readings; there is no shared
  thermometer bias in this model.

The unknown temperature is `T`. In notation where the second argument of `N`
is **variance**, the model is:

```text
T ~ N(20, 4)
reading_i | T ~ N(T, 1)
```

Koka's `normal` functions take **standard deviation**, so the prior uses `2.0`
and each reading uses `1.0`. The complete model, data, and inference call are in
[examples/temperature.kk](../examples/temperature.kk).

```sh
make inference MODEL=examples/temperature.kk
```

Without Make, use `./bayes run examples/temperature.kk`, or
`.\bayes.cmd run examples/temperature.kk` on Windows.

## The exact answer

Normal observations and a normal prior give a normal posterior. Precision is
the reciprocal of variance, so independent information adds:

```text
posterior precision = 1/4 + 3 = 13/4
posterior variance  = 4/13
posterior mean      = (20/4 + 19 + 21 + 22) / (13/4) = 268/13
```

The answer is centered at **20.615°C**, with posterior standard deviation about
**0.555°C**. Its mean and most probable value (mode) coincide. The inference
example uses 6,000 likelihood-weighted prior draws and prints its estimated mean
beside this exact answer. Finite sampling error is expected.

## Differentiating the same model

On `feat/handler-autodiff`, run:

```sh
make inference MODEL=examples/autodiff.kk
```

The AD example imports the same data and parameters, then writes the smooth log
joint with `ad-*` operations. Dropping constants independent of `T`:

```text
L(T)  = -(T-20)^2/8 - ((19-T)^2 + (21-T)^2 + (22-T)^2)/2
L'(T) = 67 - 13*T/4
```

The derivative is zero at `T = 268/13`. The second derivative is `-13/4`, so
this is the unique maximum. The program obtains the derivative from the reverse
handler, rather than coding this derivative formula, and uses it in gradient
ascent. Sixteen steps from 16°C with learning rate 0.25 give absolute error less
than `1e-8`°C; the example checks that bound.

Each reading is a separate differentiable function. A fold combines these
functions with the prior, and reverse mode adds their contributions to `T`'s
gradient. This is a small example of compositional differentiable programming.

The probabilistic version estimates a posterior expectation from weighted
samples. The AD version finds its mode by optimizing a deterministic log joint.
The AD handler does not differentiate through the sampler. This model is small
enough to check both against exact mathematics; broader algorithm coverage
remains in the [inference audit](INFERENCE_AUDIT.md).
