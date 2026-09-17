[Docs](README.md) · [Get started](USAGE_GUIDE.md)

<a id="local-installation"></a>

# Install

Run from the project folder. Setup installs **Koka 3.2.3** and
**Node.js 24.21.0** into `.tools/` and checks the project. It leaves your system
tools and settings alone. No C compiler, Windows SDK or npm packages are needed.

## First run

With GNU Make, the commands are the same on Linux, macOS and Windows:

```sh
make setup
make inference
```

The starter is [model.kk](../model.kk). To run another model:

```sh
make inference MODEL=examples/temperature.kk
```

Use `make tests` for all tests, `make test-mh` for one method, or `make help`
for the command list. Next: [write your model](USAGE_GUIDE.md).

<a id="without-make"></a>

<details>
<summary>Without Make</summary>

Linux or macOS:

```sh
sh scripts/setup.sh
./bayes
```

Windows PowerShell:

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File scripts/setup.ps1
.\bayes.cmd
```

To select another model, use `./bayes run examples/gaussian.kk` or
`.\bayes.cmd run examples/gaussian.kk`. The launcher supplies the library paths;
paths containing spaces work too.

Setup ends with the full project check: compilation, inference and
differentiation tests, the starter and small examples. A failed check makes
setup fail.

To install or verify only the tools:

```sh
sh scripts/setup.sh --tools-only
```

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File scripts/setup.ps1 -ToolsOnly
```

Then run `make check`, `./bayes check` or `.\bayes.cmd check`.

</details>

<a id="getting-make"></a>

<details>
<summary>Get GNU Make</summary>

Check `make --version`; GNU Make 3.81 or later is supported. Install your
operating system's GNU Make package, or use the direct commands above.

On Windows with WinGet:

```powershell
winget install --id ezwinports.make --exact --version 4.4.1
```

This uses the [Microsoft WinGet package catalogue](https://github.com/microsoft/winget-pkgs/blob/master/manifests/e/ezwinports/make/4.4.1/ezwinports.make.installer.yaml).
Reopen the terminal, check `make --version`, and run `make setup`. The Windows
Makefile uses native Command Prompt and PowerShell.

</details>

<a id="platform-requirements"></a>

<details>
<summary>Supported platforms and prerequisites</summary>

| Platform | Architecture | Requirements |
| --- | --- | --- |
| macOS | Apple Silicon or Intel | macOS 13.5+; shell, `tar`, `curl`, `shasum` |
| Linux | x64 or ARM64 | glibc 2.34+, kernel 4.18+, libstdc++ 6.0.25+, zlib, GMP; shell, `tar`, `getconf`, `curl` or `wget`, `sha256sum` or `shasum` |
| Windows | x64 | Windows 10 / Server 2016+; PowerShell 5.1+, `tar.exe` |
| Windows | ARM64 | Windows 11+ with x64 emulation; PowerShell 5.1+, `tar.exe` |

The [Node 24 support table](https://github.com/nodejs/node/blob/v24.21.0/BUILDING.md#platform-list)
provides Node's requirements. The pinned Koka Linux archives also require
glibc 2.34 symbols, `libz.so.1` and `libgmp.so.10`.

Ubuntu 22.04+ and Debian 12+ meet the glibc requirement; Ubuntu 20.04 does not.
On Debian/Ubuntu, the runtime packages are `zlib1g` and `libgmp10`. Minimal
images may also need the download and archive utilities above. Setup reports
missing tools; it does not run a package manager or `sudo`. Alpine/musl and
32-bit systems are unsupported by this bootstrap.

[Koka 3.2.3](https://github.com/koka-lang/koka/releases/tag/v3.2.3) has native
Linux and macOS binaries for both architectures. Windows ARM64 runs its x64
compiler through emulation and runs Node natively. The runner gives the emulated
compiler one GHC runtime capability to avoid its parallel-runtime crash.
Apple Silicon uses native binaries even when setup starts in a Rosetta shell.
A warning about a missing C compiler is harmless for this JavaScript backend.

</details>

<a id="reproducibility-and-recovery"></a>

<details>
<summary>Reinstall, recover or update the tools</summary>

- Exact versions are pinned in `.node-version` and `.koka-version`. Archive
  hashes are locked in `scripts/toolchain-sha256.txt`: Koka hashes come from
  GitHub release digests; Node hashes come from its official checksum file.
- Downloads are verified and unpacked in a temporary directory under `.tools/`.
  A replacement is checked before installation, so interrupted downloads cannot
  become installed tools.
- Rerunning setup reuses working tools of the pinned versions, preserves their
  binary timestamps, and checks the project again.
- Setup changes PATH only for its own process. It does not edit shell profiles,
  registry settings, user or machine PATH, or system installations.
- `.tools/setup.lock` prevents simultaneous setup. Before removing a stale lock,
  confirm that no setup process is still running.
- To repair a damaged tool, remove only its managed `.tools/node` or
  `.tools/koka` directory and rerun setup. Build output is separate, in `.koka/`.

To update a tool, change its version file and matching checksum entries together,
then rerun setup and the platform checks. A version without a locked checksum
will not be installed.

</details>

<a id="verification"></a>

<details>
<summary>Recorded platform verification</summary>

<a id="verification-limits"></a>

On 17 September 2026, clean installation, repeat-install idempotence, every
then-current algorithm target, and the full check with only managed tools on
PATH passed on six GitHub Actions platforms: Linux, macOS and Windows, each on
x64 and ARM64. These [master](https://github.com/oliverjgoldstein/koka-bayes/actions/runs/35221024509)
and [handler autodiff](https://github.com/oliverjgoldstein/koka-bayes/actions/runs/35221024682)
runs cover the CI repairs **before the additional inference audit**.

The Windows workflow downloads GNU Make with curl, a direct mirror and a
fallback, checking its locked SHA-256 before extraction. Only the x64 compiler
is emulated on Windows ARM64; Node runs the generated JavaScript natively.

Local macOS ARM64 checks also covered a clean installation in a path with spaces,
all then-current algorithm targets and the full test suite. Runner tests cover
models outside the project, changed data and inference methods, compile errors
and runtime exceptions. Make serializes compiler invocations even with `-j`.

These results establish the tested toolchain combinations, not correctness of
arbitrary models. The [inference audit](INFERENCE_AUDIT.md) records mathematical
targets, regression coverage and limitations.

</details>
