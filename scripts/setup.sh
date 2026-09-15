#!/bin/sh
# Install pinned, checksum-verified tools inside this checkout; then check it.
set -eu

fail() { printf 'setup: %s\n' "$*" >&2; exit 1; }
repo=$(CDPATH= cd -P "$(dirname "$0")/.." && pwd)
tools="$repo/.tools"
tools_only=false
case "${1:-}" in
  '') ;;
  --tools-only) tools_only=true; shift ;;
  *) fail 'Usage: sh scripts/setup.sh [--tools-only]' ;;
esac
[ "$#" -eq 0 ] || fail 'Usage: sh scripts/setup.sh [--tools-only]'

node_version=$(tr -d '\r\n' < "$repo/.node-version")
koka_version=$(tr -d '\r\n' < "$repo/.koka-version")
for version in "$node_version" "$koka_version"; do
  printf '%s\n' "$version" | grep -Eq '^[0-9]+\.[0-9]+\.[0-9]+$' || fail 'Invalid toolchain version file.'
done

case "$(uname -s)" in
  Darwin)
    node_os=darwin; koka_os=macos
    mac_version=$(sw_vers -productVersion)
    printf '%s\n' "$mac_version" | awk -F. '{ exit !($1 > 13 || ($1 == 13 && $2 >= 5)) }' ||
      fail 'Node 24 requires macOS 13.5 or later.'
    ;;
  Linux)
    node_os=linux; koka_os=linux
    libc_version=$(getconf GNU_LIBC_VERSION 2>/dev/null) ||
      fail 'Official Linux binaries require glibc 2.34+; musl/Alpine is unsupported. Use a supported glibc distribution.'
    printf '%s\n' "$libc_version" | awk '{ split($2,v,"."); exit !(v[1] > 2 || (v[1] == 2 && v[2] >= 34)) }' ||
      fail 'The official Koka 3.2.3 Linux binary requires glibc 2.34 or later (for example Ubuntu 22.04+ or Debian 12+).'
    ;;
  *) fail 'Supported platforms: macOS, glibc Linux, and Windows through scripts/setup.ps1.' ;;
esac
case "$(uname -m)" in
  x86_64|amd64) arch=x64 ;;
  arm64|aarch64) arch=arm64 ;;
  *) fail 'Official tool binaries support only x64 and arm64 processors.' ;;
esac
# Prefer native Apple Silicon binaries even when this shell uses Rosetta.
if [ "$node_os" = darwin ] && [ "$(sysctl -n hw.optional.arm64 2>/dev/null || true)" = 1 ]; then arch=arm64; fi

command -v tar >/dev/null 2>&1 || fail 'tar is required to extract the official archives.'
if command -v curl >/dev/null 2>&1; then downloader=curl
elif command -v wget >/dev/null 2>&1; then downloader=wget
else fail 'Install curl or wget using your operating system package manager, then rerun setup.'
fi
if command -v sha256sum >/dev/null 2>&1; then hash_tool=sha256sum
elif command -v shasum >/dev/null 2>&1; then hash_tool=shasum
else fail 'A SHA-256 utility is required: sha256sum (Linux) or shasum (macOS).'
fi

[ ! -L "$tools" ] || fail '.tools must be a directory inside this checkout, not a symbolic link.'
mkdir -p "$tools"
lock="$tools/setup.lock"
mkdir "$lock" 2>/dev/null || fail 'Another setup owns .tools/setup.lock. If it was interrupted, remove that lock after confirming no setup is running.'
stage=''
cleanup() {
  if [ -n "$stage" ] && [ -d "$stage" ]; then rm -rf "$stage"; fi
  rmdir "$lock" 2>/dev/null || true
}
trap cleanup EXIT
trap 'exit 130' INT
trap 'exit 143' TERM HUP
stage=$(mktemp -d "$tools/.setup.XXXXXX")

download() {
  printf 'Downloading %s\n' "$1"
  if [ "$downloader" = curl ]; then
    curl --proto '=https' --tlsv1.2 --fail --location --silent --show-error --retry 3 --connect-timeout 30 "$1" -o "$2"
  else
    wget --https-only --tries=3 --timeout=30 --no-verbose "$1" -O "$2"
  fi
}

verify_archive() {
  expected=$(awk -v file="$1" '$2 == file { print $1 }' "$repo/scripts/toolchain-sha256.txt")
  [ "${#expected}" -eq 64 ] || fail "No unique locked SHA-256 checksum for $1. Update the version files and checksum manifest together."
  if [ "$hash_tool" = sha256sum ]; then actual=$(sha256sum "$2" | awk '{print $1}')
  else actual=$(shasum -a 256 "$2" | awk '{print $1}')
  fi
  [ "$actual" = "$expected" ] || fail "SHA-256 mismatch for $1; the downloaded archive will not be installed."
}

node_matches() { [ -x "$1/bin/node" ] && [ "$("$1/bin/node" --version 2>/dev/null)" = "v$node_version" ]; }
koka_matches() {
  [ -x "$1/bin/koka" ] && [ -f "$1/share/koka/v$koka_version/lib/std/core.kk" ] || return 1
  koka_reported_version=$("$1/bin/koka" --version 2>/dev/null) || return 1
  printf '%s\n' "$koka_reported_version" | awk -v expected="$koka_version" '$1 == "version:" && $2 == expected { found=1 } END { exit !found }'
}

install_directory() {
  # Both moves stay on the same filesystem. Keep the previous tool until ready.
  if [ -e "$tools/$1" ] || [ -L "$tools/$1" ]; then mv "$tools/$1" "$stage/$1.previous"; fi
  if ! mv "$stage/$1" "$tools/$1"; then
    if [ -e "$stage/$1.previous" ] || [ -L "$stage/$1.previous" ]; then mv "$stage/$1.previous" "$tools/$1"; fi
    fail "Could not activate the new $1 installation."
  fi
}

if node_matches "$tools/node"; then
  printf 'Using local Node.js %s\n' "$node_version"
else
  node_archive="node-v$node_version-$node_os-$arch.tar.gz"
  download "https://nodejs.org/dist/v$node_version/$node_archive" "$stage/$node_archive"
  verify_archive "$node_archive" "$stage/$node_archive"
  mkdir "$stage/node"
  tar -xzf "$stage/$node_archive" --strip-components=1 -C "$stage/node"
  node_matches "$stage/node" || fail 'The downloaded Node binary could not run. Check the platform requirements in docs/INSTALLATION.md.'
  install_directory node
  printf 'Installed local Node.js %s\n' "$node_version"
fi

if koka_matches "$tools/koka"; then
  printf 'Using local Koka %s\n' "$koka_version"
else
  koka_archive="koka-v$koka_version-$koka_os-$arch.tar.gz"
  download "https://github.com/koka-lang/koka/releases/download/v$koka_version/$koka_archive" "$stage/$koka_archive"
  verify_archive "$koka_archive" "$stage/$koka_archive"
  mkdir "$stage/koka"
  tar -xzf "$stage/$koka_archive" -C "$stage/koka"
  if ! koka_matches "$stage/koka"; then
    "$stage/koka/bin/koka" --version >&2 || true
    fail 'The downloaded Koka binary or source library could not run. Linux also requires zlib and GMP runtime libraries; see docs/INSTALLATION.md.'
  fi
  install_directory koka
  printf 'Installed local Koka %s\n' "$koka_version"
fi

PATH="$tools/node/bin:$tools/koka/bin:$PATH"
export PATH
if [ "$tools_only" = false ]; then
  cd "$repo"
  "$tools/node/bin/node" scripts/project.mjs check
fi
