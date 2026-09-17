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
.PHONY: help setup inference test tests check test-inference \
        test-inference-audit test-lw test-lwis test-mh test-smc test-rmsmc test-pmmh test-smc2

help:
	@echo make setup       - Install the tools and check the project
	@echo make inference   - Run model.kk with its chosen inference algorithm
	@echo make inference MODEL=examples/gaussian.kk
	@echo make test        - Run all tests
	@echo make check       - Compile, test, and run the starter examples
	@echo make test-inference - Run all 30 simple inference benchmark cases
	@echo make test-inference-audit - Check joint posteriors, custom kernels, and particle evidence
	@echo Algorithm targets: test-lw test-lwis test-mh test-smc test-rmsmc test-pmmh test-smc2
	@echo Example: make test-mh

setup:
	@$(SETUP)

inference:
	@$(BAYES) inference

test tests:
	@$(BAYES) test

check:
	@$(BAYES) check

test-inference:
	@$(BAYES) benchmark

test-inference-audit:
	@$(BAYES) inference-audit

test-lw test-lwis test-mh test-smc test-rmsmc test-pmmh test-smc2:
	@$(BAYES) $@
