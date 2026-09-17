[Docs](README.md) · [Get started](USAGE_GUIDE.md)

<a id="inference-from-thermometer-readings"></a>

# Try the inference algorithms

Estimate a room's average temperature from readings of **19, 21 and 22°C**.
The room fluctuates between readings, and the thermometer adds measurement noise.

```sh
make examples        # Run every example
make demo-smc        # Run one sampler
```

The nine samplers below use the same statistical assumptions. Each prints its
estimate beside the exact posterior mean **20.604°C** and standard deviation
**0.614°C**.

## One demonstration per algorithm

| Command | Method | How it samples |
| --- | --- | --- |
| `make demo-lw` | Likelihood weighting | Draw from the prior; weight by the data. |
| `make demo-lwis` | Resampled likelihood weighting | Resample those weighted draws. |
| `make demo-mh` | Trace MH | Change a latent choice, regenerate its suffix, then accept or retain the old trace. |
| `make demo-smc` | SMC | Update and resample particles with each reading. |
| `make demo-rmsmc` | Resample-move SMC | Add MH moves after resampling. |
| `make demo-pmmh` | Particle marginal MH | Use an inner particle filter to estimate a proposed temperature's likelihood. |
| `make demo-smc2` | SMC² | Keep a population of temperatures, each with an inner filter. |
| `make demo-hmc` | HMC | Follow gradients along a corrected leapfrog trajectory. |
| `make demo-mala` | MALA | Take a noisy gradient step with a proposal correction. |

Without Make, replace `make` with `./bayes`, or `.\bayes.cmd` on Windows.
`make examples` also runs [finite enumeration](EXACT_INFERENCE.md) and the
[checkpoint-handler example](HANDLER_COMPOSITION.md).

## The exact answer

<details>
<summary>The model and calculation</summary>

Here `Normal(mean, sd)` uses **standard deviation**:

```text
average temperature θ ~ Normal(20, 2)
actual temperature i  ~ Normal(θ, 0.5)
reading i             ~ Normal(actual temperature i, 1)
```

Integrating out each local fluctuation gives reading variance `0.5² + 1² = 1.25`.
The posterior for the average temperature is Normal:

```text
variance = 1 / (1/4 + 3/1.25) = 0.3773584906
mean     = variance × (20/4 + (19+21+22)/1.25) = 20.6037735849°C
sd       = sqrt(variance) = 0.6142951168°C
```

Posterior standard deviation describes uncertainty about the temperature,
not Monte Carlo error. The [simpler temperature model](TEMPERATURE.md) has
no local fluctuations, so its exact mean is slightly different: 20.615°C.
The checkpoint-handler example uses that simpler model.

</details>

<details>
<summary>How the examples share a model</summary>

[examples/inference.kk](../examples/inference.kk) defines the sequential model
used by LW, LWIS, MH, SMC, RMSMC, PMMH and SMC²:

```koka
pub fun temperature-model() : sequential-model<e,float64,float64,float64,float64>
  Sequential-model(
    fn(){ normal'(prior-mean, prior-stddev) },
    fn(average){ average },
    fn(average, _index, _previous){
      val actual = normal'(average, fluctuation-stddev)
      Step-output(actual, normal(thermometer, actual, reading-stddev))
    },
    fn(result){ result.parameter })
```

LW, LWIS and MH run the whole sequence through `as-model`; particle methods
advance it one reading at a time. Local temperatures give them a latent state.

[examples/gradient_inference.kk](../examples/gradient_inference.kk) expresses
the same assumptions through scalar-polymorphic Normal sites. That program
supports ordinary probabilistic execution and a differentiable density for
HMC/MALA. It shares data and constants with the sequential example; the two
model bodies use different interfaces. See [gradient inference](GRADIENT_INFERENCE.md).

Run either file with `make inference MODEL=examples/inference.kk` or
`make inference MODEL=examples/gradient_inference.kk`.

</details>

<details>
<summary>Example budgets and one recorded run</summary>

Each function has a fixed seed. These are approximate results from small
budgets, not an accuracy ranking. Compare independent seeds and larger budgets
when assessing Monte Carlo error.

| Function | Budget | Mean, °C | Posterior SD, °C |
| --- | --- | ---: | ---: |
| Exact | Analytic | 20.604 | 0.614 |
| `run-lw()` | 4,000 draws | 20.614 | 0.621 |
| `run-lwis()` | 4,000 draws | 20.608 | 0.611 |
| `run-mh()` | 6,000 iterations; 1,000 burn-in | 20.650 | 0.612 |
| `run-smc()` | 1,600 particles | 20.560 | 0.601 |
| `run-rmsmc()` | 800 particles; 1 move | 20.693 | 0.645 |
| `run-pmmh()` | 2,500 iterations; 500 burn-in; 6 inner particles | 20.602 | 0.640 |
| `run-smc2()` | 300 outer / 6 inner particles; 1 move | 20.574 | 0.597 |
| `run-hmc()` | 4,500 iterations; 500 burn-in; step 0.15; 10 leapfrog steps | 20.532 | 0.599 |
| `run-mala()` | 10,000 iterations; 2,000 burn-in; step 0.35 | 20.575 | 0.600 |

HMC uses reverse AD, reversible leapfrog and a Hamiltonian acceptance correction.
MALA includes the reverse/forward proposal correction. The separate
[inference audit](INFERENCE_AUDIT.md) checks analytic and enumerated references;
[multiple-model validation](MULTI_MODEL_VALIDATION.md) checks each method on
three models and three seeds.

</details>
