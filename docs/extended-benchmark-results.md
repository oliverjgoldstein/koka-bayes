[Docs](README.md) · [Get started](USAGE_GUIDE.md)

# Archived exploratory benchmark results

The [63-row CSV](extended-benchmark-results.csv) is an earlier 2026-09-15
exploratory snapshot. The active [correctness suite](BENCHMARKS.md) now gives
each method a simpler problem suited to its inference task. The archive is not
run by `./bayes benchmark`, and its model names and budgets differ from the
current 30-run CSV.

The old experiment applied LW, LWIS, MH, SMC, RMSMC, PMMH and SMC² to each of
three models, using seeds `2027`, `4093`, `8191`:

- `coin`: Beta(2,3) prior, ordered TTTF observations; posterior Beta(5,4).
- `gaussian`: N(0,1) mean prior, observations 1 and 2 with noise standard
  deviation one; posterior mean 1 and variance 1/3.
- `hmm`: unknown q in {.2,.8}, P(q=.8)=.35; P(x0=1)=.3; stay probability .8;
  emission success q in state one and 1-q in state zero; observations TFT.
  Exact evidence .092096, q mean .3616226546, q variance .0708517103,
  CDF at .5 equal to .7306289090, final-state probability .3553683113.

Budgets per seed were LW 4000, LWIS 1500, MH 4000 with 500 burnin, SMC 2400,
RMSMC 600 with one move, PMMH 1500 with 300 burnin and 4 inner particles, and
SMC² 600 outer/4 inner particles with one move. The archived variance bound for the HMM
parameter was 0.015, and its CDF bound was 0.075; other metric bounds are
listed in the current suite. All 63 final archived rows passed.

An earlier 1000-particle SMC run failed for HMM seed 8191: q mean .4142 versus
.3616226546 and CDF .643 versus .7306289090. Raising the old SMC budget to 2400
produced the archived passing snapshot without changing tolerances. That
parameter-learning HMM was subsequently removed from the active elementary
suite; its increased particle budget is not used in the current filtering test.

Environment: Koka 3.2.3, default-debug jsnode, Node v24.18.1, Darwin arm64. The
already-compiled old program took about 14.8 seconds locally. This is a historical
reproducibility detail, not a speed ranking or an independent validation result.
