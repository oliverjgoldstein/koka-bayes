SHELL := /bin/sh

.DEFAULT_GOAL := help

KOKA_INSTALL_URL ?= https://github.com/koka-lang/koka/releases/latest/download/install.sh
KOKA_INSTALL_PREFIX ?=
KOKA ?= $(if $(strip $(KOKA_INSTALL_PREFIX)),$(KOKA_INSTALL_PREFIX)/bin/koka,koka)

KOKA_FLAGS := --target=jsnode --include=src
KOKA_TEST_FLAGS := --target=jsnode --include=src --include=test
KOKA_CHECK_FLAGS := --target=jsnode --library --include=src
KOKA_LIBRARY_MODULES := $(filter-out src/main.kk,$(shell find src -type f -name '*.kk' | LC_ALL=C sort))

.PHONY: help setup ensure-koka ensure-node koka-install koka-install-local compile smoke test run linear-regression hmm sir-simulate sir-infer sir-bootstrap sir-report

help:
	@printf '%s\n' \
	  'Targets:' \
	  '  make setup               Verify the runtime toolchain and ensure Koka v3 is available.' \
	  '  make compile             Typecheck/compile all source modules.' \
	  '  make smoke               Run the smoke checks.' \
	  '  make run                 Run src/main.kk.' \
	  '  make linear-regression   Run the linear regression demo.' \
	  '  make hmm                 Run the HMM demo.' \
	  '  make sir-simulate        Run the SIR simulation demo.' \
	  '  make sir-infer           Run the SIR inference demo.' \
	  '  make sir-bootstrap       Run the SIR bootstrap demo.' \
	  '  make sir-report          Run the SIR diagnostics report.' \
	  '  make koka-install        Install the official Koka 3 release if needed.' \
	  '  make koka-install-local  Install Koka 3 into $$HOME/.local/bin.' \
	  '' \
	  'Variables:' \
	  '  KOKA=<path>                    Use a specific koka binary.' \
	  '  KOKA_INSTALL_PREFIX=<prefix>   Pass --prefix=<prefix> to the official installer.'

setup: ensure-koka ensure-node

ensure-koka:
	@version=`"$(KOKA)" --version 2>/dev/null | sed -n -e 's/^version:[[:space:]]*//p' -e 's/^Koka[[:space:]]\([0-9][^,[:space:]]*\).*/\1/p' | head -n 1`; \
	if [ -n "$$version" ]; then \
	  case "$$version" in \
	    3.*) printf 'Using Koka %s via %s\n' "$$version" "$(KOKA)" ;; \
	    *) printf '%s\n' "Found Koka $$version at $(KOKA), but this repository requires Koka 3."; \
	       printf '%s\n' "Run 'make koka-install' to install the official Koka 3 release."; \
	       exit 1 ;; \
	  esac; \
	else \
	  $(MAKE) --no-print-directory koka-install KOKA="$(KOKA)" KOKA_INSTALL_PREFIX="$(KOKA_INSTALL_PREFIX)"; \
	fi

ensure-node:
	@if ! command -v node >/dev/null 2>&1; then \
	  printf '%s\n' 'Node.js is required for the jsnode backend.'; \
	  exit 1; \
	fi
	@if node -e 'const probe = { ok: 1 }; process.stdout.write(String(probe?.ok ?? 0));' >/dev/null 2>&1; then \
	  printf 'Using Node.js %s\n' "$$(node --version)"; \
	else \
	  printf '%s\n' "Node.js $$(node --version) is too old for the jsnode backend in this repository."; \
	  printf '%s\n' 'Install a newer Node.js release and re-run the target.'; \
	  exit 1; \
	fi

koka-install:
	@if [ "$$(uname -s)" = "Darwin" ] && command -v brew >/dev/null 2>&1 && brew list --versions koka >/dev/null 2>&1; then \
	  printf '%s\n' 'Koka appears to be installed through Homebrew.'; \
	  printf '%s\n' 'The official Koka docs say to run `brew uninstall koka` before using the manual installer.'; \
	  exit 1; \
	fi
	@if ! command -v curl >/dev/null 2>&1; then \
	  printf '%s\n' 'curl is required to download the official Koka installer.'; \
	  exit 1; \
	fi
	@tmp=$$(mktemp "$${TMPDIR:-/tmp}/koka-install.XXXXXX"); \
	trap 'rm -f "$$tmp"' EXIT HUP INT TERM; \
	printf 'Downloading Koka installer from %s\n' "$(KOKA_INSTALL_URL)"; \
	curl -fsSL "$(KOKA_INSTALL_URL)" -o "$$tmp"; \
	if [ -n "$(KOKA_INSTALL_PREFIX)" ]; then \
	  printf 'Installing Koka 3 into %s\n' "$(KOKA_INSTALL_PREFIX)"; \
	  sh "$$tmp" --prefix="$(KOKA_INSTALL_PREFIX)"; \
	else \
	  printf '%s\n' 'Installing Koka 3 with the official default prefix.'; \
	  sh "$$tmp"; \
	fi; \
	rm -f "$$tmp"; \
	"$(KOKA)" --version

koka-install-local:
	@$(MAKE) --no-print-directory koka-install KOKA="$(HOME)/.local/bin/koka" KOKA_INSTALL_PREFIX="$(HOME)/.local"

compile: ensure-koka
	@for module in $(KOKA_LIBRARY_MODULES); do \
	  printf 'Checking %s\n' "$$module"; \
	  "$(KOKA)" $(KOKA_CHECK_FLAGS) -c "$$module" || exit $$?; \
	done
	@"$(KOKA)" $(KOKA_FLAGS) -c src/main.kk

smoke: setup
	@"$(KOKA)" $(KOKA_TEST_FLAGS) -e test/smoke.kk

test: smoke

run: setup
	@"$(KOKA)" $(KOKA_FLAGS) -e src/main.kk

linear-regression: setup
	@"$(KOKA)" $(KOKA_FLAGS) -e src/run/linear_regression.kk

hmm: setup
	@"$(KOKA)" $(KOKA_FLAGS) -e src/run/hmm.kk

sir-simulate: setup
	@"$(KOKA)" $(KOKA_FLAGS) -e src/run/sir_simulate.kk

sir-infer: setup
	@"$(KOKA)" $(KOKA_FLAGS) -e src/run/sir_infer.kk

sir-bootstrap: setup
	@"$(KOKA)" $(KOKA_FLAGS) -e src/run/sir_bootstrap.kk

sir-report: setup
	@"$(KOKA)" $(KOKA_FLAGS) -e src/run/sir_report.kk
