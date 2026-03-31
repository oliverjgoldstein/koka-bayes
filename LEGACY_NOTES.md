# Legacy Notes

## Archived Material

The thesis-era implementation was moved to `legacy/2019/`. That archive includes:

- the old root-level Koka modules built around explicit `sample` and `score`
- legacy inference algorithms such as SMC, TMCMC, RMSMC, and PMMH
- climate-change examples and plotting scripts
- historical datasets and generated climate output
- bug notes and scratch experiments from the original project

The archive is preserved for archaeological reference only. It is not part of the supported Koka v3 API.

## What Was Preserved Conceptually

Very little code was carried over directly. The main things preserved were:

- general probabilistic modeling intent
- some distribution and numerical intuition from the old utilities
- repository history and example context
- replay-style MH intuition, now reintroduced only as an internal proposal refinement in `src/alg/mh.kk`

## What Was Replaced

The following thesis-era assumptions were intentionally dropped:

- explicit `sample`/`score` as the main user-facing model API
- flat root-level module layout
- pre-v3 Koka syntax
- older algorithm lineup as the primary execution surface
- climate demo as the main example story

They were replaced by the current Koka v3 multimodal architecture under `src/`.

## How To Read The Archive

- Read `legacy/2019/*.kk` only for historical comparison.
- Do not treat archived modules as examples of current Koka syntax.
- Use `README.md`, `DESIGN_NOTES.md`, and `ARCHITECTURE_MAPPING.md` for the current implementation.

## Current Boundary

If a module is under `src/`, it is part of the current implementation.

If a file is under `legacy/2019/`, it is archived and unsupported unless explicitly revived in a future migration.
