.DEFAULT_GOAL := help

# GNU Make 3.81+; use native commands on Windows, including from PowerShell.
ifeq ($(OS),Windows_NT)
SHELL := cmd.exe
.SHELLFLAGS := /d /c
BAYES := .\bayes.cmd
SETUP := powershell -NoProfile -ExecutionPolicy Bypass -File scripts/setup.ps1
else
SHELL := /bin/sh
BAYES := ./bayes
SETUP := sh scripts/setup.sh
endif

MODEL ?= model.kk
# Pass paths as data, without interpolating their contents into a shell command.
export KOKA_BAYES_MODEL = $(MODEL)

# Compiler invocations share a build cache. Even `make -j` runs these sequentially.
.NOTPARALLEL:
.PHONY: help setup inference test tests check test-inference test-autodiff test-handlers test-examples \
        test-inference-audit test-lw test-lwis test-mh test-smc test-rmsmc test-pmmh test-smc2 \
        test-hmc test-mala examples demo-lw demo-lwis demo-mh demo-smc demo-rmsmc \
        demo-pmmh demo-smc2 demo-hmc demo-mala demo-handlers test-enumerate demo-enumerate test-sir

help:
	@echo make setup       - Install the tools and check the project
	@echo make inference   - Run model.kk with its chosen inference algorithm
	@echo make inference MODEL=examples/temperature.kk
	@echo make test        - Run all tests
	@echo make check       - Compile, test, and run the starter examples
	@echo make examples    - Demonstrate sampling methods and finite enumeration
	@echo make test-examples - Check sampling methods on three models and three seeds
	@echo make test-enumerate - Check finite supports, exact posteriors and composition
	@echo make demo-enumerate - Run three finite enumeration examples
	@echo make demo-hmc    - Run one algorithm example, also demo-mala, demo-lw, etc.
	@echo make demo-handlers - Run a model with checkpoint SMC and likelihood weighting
	@echo make test-inference - Run all 36 simple inference benchmark cases
	@echo make test-inference-audit - Check joint posteriors, custom kernels, and particle evidence
	@echo make test-sir - Check a small exact SIR posterior and report summaries
	@echo make test-handlers - Check particle inference nesting, weights and retained state
	@echo Algorithm targets: test-enumerate test-lw test-lwis test-mh test-smc test-rmsmc test-pmmh test-smc2 test-hmc test-mala
	@echo Example: make test-mh
	@echo make test-autodiff - Check automatic differentiation

setup:
	@$(SETUP)

inference:
	@$(BAYES) inference

test tests:
	@$(BAYES) test

check:
	@$(BAYES) check

test-inference:
	@$(BAYES) inference-tests

test-inference-audit:
	@$(BAYES) inference-audit

test-sir:
	@$(BAYES) test-sir

test-handlers:
	@$(BAYES) handler-composition

test-examples:
	@$(BAYES) example-matrix

test-autodiff:
	@$(BAYES) autodiff-test

test-enumerate test-lw test-lwis test-mh test-smc test-rmsmc test-pmmh test-smc2 test-hmc test-mala:
	@$(BAYES) $@

examples:
	@$(BAYES) examples

demo-enumerate demo-lw demo-lwis demo-mh demo-smc demo-rmsmc demo-pmmh demo-smc2 demo-hmc demo-mala demo-handlers:
	@$(BAYES) $@
