# Migration record

## Current layout

The supported Koka 3.2.3 workflow starts with [model.kk](../../model.kk). Its
model, data, inference method, and result printing are in one file. Run
`make setup` once, then `make inference` to run that file.
`make inference MODEL=examples/gaussian.kk` selects another complete example.

| Location | Purpose |
| --- | --- |
| `model.kk` | Editable starter |
| `Makefile` | Portable setup, inference, and test commands |
| `examples/` | Complete runnable model files, including their inference |
| `lib/bayes.kk` | Public import and beginner inference helpers |
| `lib/core/`, `lib/handlers/`, `lib/alg/` | Modeling and inference implementation |
| `tests/` | Independent inference and runner checks |
| `scripts/` | Local tool installation and portable runner |
| `results/` | Generated reports, excluded from version control |
| `docs/` | Usage, evidence, and optional development notes |
| `archive/2019/` | Unsupported thesis-era code and artifacts |

The separate model run-wrapper layer was removed. Models and their inference
selection stay together. The Makefile delegates setup and execution to the
platform scripts and portable runner; the launchers supply compiler settings
and library paths. `make test-lw` through `make test-smc2` select individual
algorithm checks. The [README](../../readme.md) is the starting guide.

## Completed implementation work

- Koka v3 native model effects and specialization handlers.
- Typed observation identifiers with ordered environments.
- Simulation, LW, LWIS, replay MH, SMC, RMSMC, PMMH, and SMC².
- Retained inner particle filters and inference boundary-condition repairs.
- First-order scalar forward and reverse AD.
- Method-specific exact-answer benchmarks and separate regression tests.
- Pinned local tool installation for the JavaScript backend.

The [assessment](../ASSESSMENT.md) gives measured results, remaining limitations,
and criteria for future work. The CI configuration does not establish that every
operating system has passed; see [installation verification](../INSTALLATION.md#verification-limits).

## Historical migration

The original 2019 prototype used explicit `sample` and `score` effects,
pre-v3 syntax such as `public module`, and deprecated modules such as
`std/num/double`. It did not compile on Koka 3.2.2. Those sources, climate examples,
datasets, generated output, and bug notes are preserved under `archive/2019/`.

The current implementation uses native Koka effects and effect rows. Observable
identifiers carry codecs into a closed runtime value representation; handlers
consume the environment and specialize distribution requests into sampling or
observation. Algorithms interpret those operations. The archive supplies
historical context, not the supported API.

[Archive notes](../../archive/README.md) · [Design notes](DESIGN_NOTES.md) ·
[Architecture map](ARCHITECTURE_MAPPING.md)
