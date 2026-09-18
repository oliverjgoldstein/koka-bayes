[Docs](README.md) · [Get started](USAGE_GUIDE.md)

<a id="inference-using-automatic-differentiation"></a>

# Sample with gradients

**HMC** follows a gradient-driven trajectory. **MALA** takes a noisy gradient
step. Both use reverse AD and a Metropolis correction, retaining the current
sample when a proposal is rejected.

See the [AD handler reference](AD_HANDLERS.md) for the exact primitive rules,
Normal-model translation, coordinate contract and handling of invalid targets.

**Works today:** use the gradient of a smooth, fixed-dimensional log density
to sample its posterior. Sampler settings are manual.

**Not implemented:** differentiate the sampler's output, posterior estimates
or evidence. Sampling and resampling have no gradient rules, and arbitrary
mixed discrete/continuous models are not converted automatically. See
[what works today](STATUS.md) for implementation and proof limits.

```sh
make demo-hmc
make demo-mala
```

These examples sample the [thermometer posterior](INFERENCE_EXAMPLES.md).
The older `examples/autodiff.kk` instead optimizes a posterior mode.

## One model, probabilistic and differentiable interpretations

The [example](../examples/gradient_inference.kk) uses a Normal-site model with
`ad-*` arithmetic. Its adapter requires a fixed number and order of scalar Normal
latent sites. It does not convert arbitrary `core/model` programs.

```koka
fun temperature-program() : <continuous<a>,smooth<a>> a
  val average = normal-latent(ad-constant(20.0), ad-constant(2.0))
  for(3) fn(_){
    val actual = normal-latent(average, ad-constant(0.5))
    val observed = normal-observed("temperature/readings", actual, ad-constant(1.0))
    ()
  }
  average
```

Run it with `probabilistic(temperature-program)` for ordinary sample/observe
handlers, or call `log-joint(temperature-program, coordinates, observations)`
to build the score that AD differentiates. The executable example shares its
constants with the sequential thermometer model.

<details>
<summary>Coordinates and observations</summary>

This model has four coordinates: `[average, actual1, actual2, actual3]`.
`log-joint` binds each latent site in order and adds every prior and observed
Normal log density. Each observed site consumes the next float from its named list.

Missing or wrongly typed observations, or the wrong coordinate count, give
`-infinity`. Extra observations are ignored, matching the existing model API;
make the executed site count match your intended data. `probabilistic` samples
missing observations, while `log-joint` requires them to be supplied.

This adapter supports scalar Normal sites. It does not convert arbitrary
existing `core/model` programs. Use `ad-*` for arithmetic involving latent values
and keep their number and order fixed. Sampling and resampling themselves are
not differentiated.

</details>

## Sampler API

Given your differentiable `target` and starting coordinates `initial`:

```koka
import alg/mcmc
import alg/hmc
import alg/mala

// target: forall<a> list<a> -> smooth<a> a
val chain = hmc(default-config(4500, 500), target,
                initial, step-size=0.15, leapfrog-steps=10, seed=8108)
val chain2 = mala(default-config(10000, 2000), target,
                  initial, step-size=0.35, seed=8109)
```

Both return `mcmc-result<list<float64>>`. `samples` includes repetitions from
rejected proposals. Iterations include burn-in, so these calls retain 4,000
and 8,000 draws. `accepted` counts transitions across the whole run, including burn-in.

Targets must have a fixed number of continuous coordinates and a differentiable
log density. Settings are manual: burn-in discards draws without adapting them.
High acceptance alone does not establish mixing or convergence.

<details>
<summary>Proposal formulas and limits</summary>

HMC draws fresh standard-normal momentum, uses unit mass and a fixed number of
reversible leapfrog steps, then corrects for the change in log density and
kinetic energy.

MALA proposes `x + eps²/2 * gradient(log p(x)) + eps * noise` and corrects with
`log q(x|y) - log q(y|x)`. Its `step-size` is noise standard deviation;
proposal covariance is `eps² I`.

Initial coordinates, scores and gradients must be finite. Invalid starts or
configurations throw; nonfinite or out-of-support proposals are rejected.
Constrained coordinates need an explicit transform and its log-Jacobian.
There are no automatic transforms, discrete-latent marginalization, mass-matrix
adaptation, NUTS or variational inference. Finite budgets offer no convergence guarantee.

</details>

<a id="verification"></a>
<details>
<summary>Tests and references</summary>

Run `make test-hmc`, `make test-mala` or `make test-inference`. The last includes
six gradient posterior runs plus 30 existing benchmark runs. `make check` also
checks the model adapter and runs the examples.

The gradient suite uses a Gaussian with mean `[1,-2]` and covariance
`[[1,0.5],[0.5,1]]`, seeds `719,727,733`, and 4,500 iterations / 500 burn-in.
HMC uses step 0.2 and seven leapfrog steps; MALA uses step 0.9. Predetermined
absolute bounds are 0.16 for means, 0.20 for second moments and 0.15 for the
cross moment, centered at the exact mean.

Deterministic checks cover leapfrog equations, reversibility and energy
convergence; MALA detailed balance and correction signs; support rejection,
retained states, reproducibility, invalid settings and large finite energies.
Adapter checks cover normalized joint densities, all thermometer derivatives,
coordinate/data mismatches and seeded equivalence with the existing API.
See also [multiple-model validation](MULTI_MODEL_VALIDATION.md).

The algorithms follow [Neal's HMC treatment](https://arxiv.org/abs/1206.1901)
and [Roberts and Tweedie's Langevin analysis](https://www2.stat.duke.edu/~scs/Courses/Stat376/Papers/ConvergeRates/GeneralState/RobertsTweedie1996.pdf).

</details>

Without Make, replace `make` with `./bayes`, or `.\bayes.cmd` on Windows.
`make examples` runs the sampling, enumeration and handler demonstrations.
