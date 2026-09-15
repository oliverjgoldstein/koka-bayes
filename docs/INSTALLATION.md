# Local installation

The bootstrap installs **Koka 3.2.3** and **Node.js 24.21.0 LTS** into `.tools/`
inside this checkout. Existing system installations are left alone. The
JavaScript backend needs no C compiler, Windows SDK, npm packages, or global
package installation.

## First run

With GNU Make installed, use the same commands on Linux, macOS, and Windows:

```sh
make setup
make inference
```

`make setup` selects the platform's installation script and checks the whole
project. `make inference` runs [model.kk](../model.kk), which contains your model,
data, inference method, and result printing. Select another complete model with:

```sh
make inference MODEL=examples/gaussian.kk
```

`make tests` runs all tests; `make test-mh` checks just Metropolis–Hastings.
Run `make help` for the other commands.

### Getting Make

Check `make --version`. The Makefile uses GNU Make 3.81 or later. If it is
missing, install your operating system's GNU Make package, or use the direct
commands below.

On Windows with WinGet, install GNU Make from the
[Microsoft WinGet package catalogue](https://github.com/microsoft/winget-pkgs/blob/master/manifests/e/ezwinports/make/4.4.1/ezwinports.make.installer.yaml):

```powershell
winget install --id ezwinports.make --exact --version 4.4.1
```

Reopen the terminal, check `make --version`, and run `make setup`.
The Windows Makefile uses native Command Prompt and PowerShell.

### Without Make

GNU Make is only a command shortcut. If it is unavailable, run the same workflow
directly. On Linux or macOS:

```sh
sh scripts/setup.sh
./bayes
```

Windows PowerShell:

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File scripts/setup.ps1
.\bayes.cmd
```

Both setup scripts finish by running `scripts/project.mjs check` with the local
Node executable. This compiles the source, runs the inference and differentiation
checks, and runs `model.kk` and the small examples. A failed check makes
setup fail. Paths containing spaces are supported.

To install or verify just the tools, use `sh scripts/setup.sh --tools-only` or
`powershell -NoProfile -ExecutionPolicy Bypass -File scripts/setup.ps1 -ToolsOnly`.
Then run `make check`, `./bayes check`, or `.\bayes.cmd check` when ready.

`./bayes` runs `model.kk`; `./bayes run examples/gaussian.kk` selects another.
The launcher supplies library paths automatically.

## Platform requirements

| Platform | Architecture | Requirements |
| --- | --- | --- |
| macOS | Apple Silicon or Intel | macOS 13.5+; stock shell, `tar`, `curl`, and `shasum` |
| Linux | x64 or ARM64 | glibc 2.34+, kernel 4.18+, libstdc++ 6.0.25+, zlib and GMP runtime libraries; shell, `tar`, `getconf`, `curl` or `wget`, and `sha256sum` or `shasum` |
| Windows | x64 | Windows 10 / Server 2016 or later; PowerShell 5.1+ and `tar.exe` |
| Windows | ARM64 | Windows 11 or later with x64 application emulation; PowerShell 5.1+ and `tar.exe` |

The [Node 24 platform support
table](https://github.com/nodejs/node/blob/v24.21.0/BUILDING.md#platform-list)
documents Node's requirements. Koka's official Linux x64 and ARM64 binaries additionally
require glibc 2.34 symbols, `libz.so.1` and `libgmp.so.10`, as verified by
inspection of the pinned release archive. Ubuntu 22.04+ and Debian 12+ meet the
glibc minimum; Ubuntu 20.04 does not. On Debian/Ubuntu, the corresponding runtime
packages are `zlib1g` and `libgmp10`.
Minimal Linux images may need their normal system download/archive utilities
installed first. The scripts report missing prerequisites and do not run a
package manager or `sudo`. Alpine/musl and 32-bit architectures are unsupported
by this bootstrap.

[Koka's 3.2.3 release](https://github.com/koka-lang/koka/releases/tag/v3.2.3)
provides native Linux and macOS archives for both architectures. Its Windows
compiler is x64; Windows ARM64 runs that compiler through emulation while Node
runs natively. An Apple Silicon Mac uses native binaries even if setup starts
from a Rosetta shell. The compiler may warn that no native C compiler was found;
this project uses its JavaScript backend.

## Reproducibility and recovery

- `.node-version` and `.koka-version` pin exact tool versions.
- `scripts/toolchain-sha256.txt` locks the official archive SHA-256 hashes. The
  Koka hashes come from GitHub release asset digests; the Node hashes come from
  its official release checksum file. Downloaded archives must match before
  extraction or execution.
- Downloads and unpacking occur in a temporary directory under `.tools/`. Each
  replacement is checked before it replaces the previous managed installation.
  Interrupted downloads cannot become an installed tool.
- Rerunning setup keeps a working installation of the exact pinned version and
  checks the project again. Existing binary timestamps stay unchanged.
- The scripts set PATH for their own execution. They do not edit shell profiles,
  registry settings, user or machine PATH, or system installations.
- `.tools/setup.lock` prevents concurrent setup. If a process was forcibly
  terminated, confirm that no setup is running before removing its stale lock.
- To reinstall a damaged tool, remove its managed `.tools/node` or `.tools/koka`
  directory and rerun setup. Build output lives in the separate `.koka/` folder.

Updating a tool requires updating its version file and matching checksum entries
together, then rerunning setup and the platform checks. An unknown version is
never installed without a matching locked checksum.

## Verification limits

Verified here on macOS ARM64: archive downloads and checksums, installation into
an empty `.tools`, repeat-install idempotence, checksum-failure recovery, the full
project check, and the full check with only managed tools on PATH. The 30 inference
benchmark rows reproduce exactly on Node 24.21.0. Default setup also passed in a
fresh copy with spaces in its path, no Git metadata, and an empty build cache,
using copies of the verified managed tools. This was repeated after the
single-file restructuring: all 31 library/model files compiled, all six Koka
suites and eight Node checks passed, and the starter, Gaussian, and AD examples
ran successfully. The workflow checks include a renamed model file, a change
of observations and inference method, and reported model failures.
The Make commands were then verified with GNU Make 3.81 on macOS:
`make setup`, `make inference`, an alternative `MODEL` path, and all seven
algorithm targets. The full test run now includes nine Node checks. Make
propagates model failures, accepts paths containing spaces, and serializes
compiler invocations even when given `-j`.
Linux/Windows binaries were
inspected for runtime dependencies; their installation scripts have not been
executed on those operating systems in this session.

The repository's CI matrix is configured to run clean setup and repeat setup on Linux, Windows,
and macOS, including a checkout path containing spaces. A workflow definition
does not establish that its remote jobs have passed; consult the actual CI run
for platform results. Local testing on one operating system cannot establish
that a different operating system or architecture works.
