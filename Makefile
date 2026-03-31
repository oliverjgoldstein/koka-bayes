KOKA ?= koka
KOKA_FLAGS := --target=jsnode --include=src
KOKA_TEST_FLAGS := --target=jsnode --include=src --include=test
KOKA_CHECK_FLAGS := --target=jsnode --library --include=src

.PHONY: compile smoke run linear-regression hmm sir-simulate sir-infer sir-bootstrap sir-report

compile:
	$(KOKA) $(KOKA_CHECK_FLAGS) -c src/core/obsvalue.kk
	$(KOKA) $(KOKA_CHECK_FLAGS) -c src/core/obsvar.kk
	$(KOKA) $(KOKA_CHECK_FLAGS) -c src/core/env.kk
	$(KOKA) $(KOKA_CHECK_FLAGS) -c src/core/dist.kk
	$(KOKA) $(KOKA_CHECK_FLAGS) -c src/core/model.kk
	$(KOKA) $(KOKA_CHECK_FLAGS) -c src/core/trace.kk
	$(KOKA) $(KOKA_CHECK_FLAGS) -c src/core/sequential.kk
	$(KOKA) $(KOKA_CHECK_FLAGS) -c src/handlers/read.kk
	$(KOKA) $(KOKA_CHECK_FLAGS) -c src/handlers/dist.kk
	$(KOKA) $(KOKA_CHECK_FLAGS) -c src/handlers/core.kk
	$(KOKA) $(KOKA_CHECK_FLAGS) -c src/alg/mcmc.kk
	$(KOKA) $(KOKA_CHECK_FLAGS) -c src/alg/simulate.kk
	$(KOKA) $(KOKA_CHECK_FLAGS) -c src/alg/lw.kk
	$(KOKA) $(KOKA_CHECK_FLAGS) -c src/alg/lwis.kk
	$(KOKA) $(KOKA_CHECK_FLAGS) -c src/alg/mh.kk
	$(KOKA) $(KOKA_CHECK_FLAGS) -c src/alg/smc.kk
	$(KOKA) $(KOKA_CHECK_FLAGS) -c src/alg/pmmh.kk
	$(KOKA) $(KOKA_CHECK_FLAGS) -c src/alg/rmsmc.kk
	$(KOKA) $(KOKA_CHECK_FLAGS) -c src/alg/smc2.kk
	$(KOKA) $(KOKA_CHECK_FLAGS) -c src/examples/linear_regression.kk
	$(KOKA) $(KOKA_CHECK_FLAGS) -c src/examples/hmm.kk
	$(KOKA) $(KOKA_CHECK_FLAGS) -c src/examples/sir.kk
	$(KOKA) $(KOKA_CHECK_FLAGS) -c src/diagnostics/sir_report.kk
	$(KOKA) $(KOKA_CHECK_FLAGS) -c src/run/linear_regression.kk
	$(KOKA) $(KOKA_CHECK_FLAGS) -c src/run/hmm.kk
	$(KOKA) $(KOKA_CHECK_FLAGS) -c src/run/sir_simulate.kk
	$(KOKA) $(KOKA_CHECK_FLAGS) -c src/run/sir_infer.kk
	$(KOKA) $(KOKA_CHECK_FLAGS) -c src/run/sir_bootstrap.kk
	$(KOKA) $(KOKA_CHECK_FLAGS) -c src/run/sir_report.kk
	$(KOKA) --target=jsnode --include=src -c src/main.kk

smoke:
	$(KOKA) -e $(KOKA_TEST_FLAGS) test/smoke.kk

run:
	$(KOKA) -e $(KOKA_FLAGS) src/main.kk

linear-regression:
	$(KOKA) -e $(KOKA_FLAGS) src/run/linear_regression.kk

hmm:
	$(KOKA) -e $(KOKA_FLAGS) src/run/hmm.kk

sir-simulate:
	$(KOKA) -e $(KOKA_FLAGS) src/run/sir_simulate.kk

sir-infer:
	$(KOKA) -e $(KOKA_FLAGS) src/run/sir_infer.kk

sir-bootstrap:
	$(KOKA) -e $(KOKA_FLAGS) src/run/sir_bootstrap.kk

sir-report:
	$(KOKA) -e $(KOKA_FLAGS) src/run/sir_report.kk
