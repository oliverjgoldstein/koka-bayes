# koka-bayes

**Open [model.kk](model.kk). Your model, data, inference method, and results live in that one file.**

## Model

The starter model learns a coin's probability of heads, with a `Beta(2, 3)` prior.
Replace `coin-model` with your model.

## Data assumptions

Edit `flips` in the same file. The starter data is three heads and one tail;
flips are independent given one fixed probability.

## Inference

Choose the method in `model.kk`:

```koka
val posterior = likelihood-weighting(2000, observations, coin-model(flips.length), seed=2027)
```

With GNU Make installed, run setup once, then run your model:

```sh
make setup
make inference
```

The Makefile selects the Linux/macOS or Windows setup script, installs the pinned
tools locally, and checks the project. [Installation](docs/INSTALLATION.md)
also covers running without Make.

## Results

The starter prints the estimated probability of heads: approximately **0.553**.
For the supplied prior and data, the exact posterior mean is **5/9 ≈ 0.556**.
Changing the model or data changes that answer.

Try another complete model:

```sh
make inference MODEL=examples/gaussian.kk
```

Check one inference method with `make test-mh`, or run all tests with `make tests`.
The method targets are `test-lw`, `test-lwis`, `test-mh`, `test-smc`,
`test-rmsmc`, `test-pmmh`, and `test-smc2`. Run `make help` for all commands.

[Writing your model](docs/USAGE_GUIDE.md) · [Installation](docs/INSTALLATION.md) ·
[Inference checks](docs/BENCHMARKS.md)
