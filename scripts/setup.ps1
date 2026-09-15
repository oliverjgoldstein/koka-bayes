param([switch]$ToolsOnly)

# PowerShell 5.1+; install only inside this checkout, then run its checks.
$ErrorActionPreference = 'Stop'
$ProgressPreference = 'SilentlyContinue'
$repo = Split-Path -Parent $PSScriptRoot
$tools = Join-Path $repo '.tools'
$stage = $null
$lockOwned = $false
$lock = Join-Path $tools 'setup.lock'

function Get-LockedVersion([string]$name) {
    $version = (Get-Content -LiteralPath (Join-Path $repo $name) -Raw).Trim()
    if ($version -notmatch '^\d+\.\d+\.\d+$') { throw "Invalid version file: $name" }
    return $version
}

function Get-Download([string]$url, [string]$destination) {
    Write-Host "Downloading $url"
    for ($attempt = 1; $attempt -le 3; $attempt++) {
        try {
            Invoke-WebRequest -UseBasicParsing -Uri $url -OutFile $destination
            return
        } catch {
            if ($attempt -eq 3) { throw }
            Start-Sleep -Seconds 2
        }
    }
}

function Assert-Archive([string]$name, [string]$path) {
    $pattern = '^([a-f0-9]{64})\s+' + [regex]::Escape($name) + '$'
    $found = @(Get-Content -LiteralPath (Join-Path $repo 'scripts/toolchain-sha256.txt') | Where-Object { $_ -match $pattern })
    if ($found.Count -ne 1) { throw "No unique locked SHA-256 checksum for $name. Update version files and checksum manifest together." }
    $expected = ($found[0] -split '\s+')[0]
    $actual = (Get-FileHash -LiteralPath $path -Algorithm SHA256).Hash.ToLowerInvariant()
    if ($actual -ne $expected) { throw "SHA-256 mismatch for $name; the downloaded archive will not be installed." }
}

function Test-Node([string]$prefix) {
    $exe = Join-Path $prefix 'node.exe'
    if (-not (Test-Path -LiteralPath $exe -PathType Leaf)) { return $false }
    try {
        # Windows PowerShell 5.1 treats redirected native stderr as error records.
        # Exit status, rather than harmless compiler warnings, decides success.
        $ErrorActionPreference = 'Continue'
        $version = & $exe --version 2>$null
        return ($LASTEXITCODE -eq 0 -and $version -eq "v$nodeVersion")
    } catch { return $false }
}

function Test-Koka([string]$prefix) {
    $exe = Join-Path $prefix 'bin/koka.exe'
    $library = Join-Path $prefix "share/koka/v$kokaVersion/lib/std/core.kk"
    if (-not (Test-Path -LiteralPath $exe -PathType Leaf) -or -not (Test-Path -LiteralPath $library -PathType Leaf)) { return $false }
    try {
        $ErrorActionPreference = 'Continue'
        $version = & $exe --version 2>$null
        $pattern = '^version:\s+' + [regex]::Escape($kokaVersion) + '$'
        return ($LASTEXITCODE -eq 0 -and @($version | Where-Object { $_ -match $pattern }).Count -eq 1)
    } catch { return $false }
}

function Install-Directory([string]$name) {
    $destination = Join-Path $tools $name
    $source = Join-Path $stage $name
    $previous = Join-Path $stage "$name.previous"
    if (Test-Path -LiteralPath $destination) {
        if ((Get-Item -LiteralPath $destination).Attributes -band [IO.FileAttributes]::ReparsePoint) {
            throw "$destination must be a managed directory, not a junction or symbolic link."
        }
        Move-Item -LiteralPath $destination -Destination $previous
    }
    try { Move-Item -LiteralPath $source -Destination $destination }
    catch {
        if (Test-Path -LiteralPath $previous) { Move-Item -LiteralPath $previous -Destination $destination }
        throw
    }
}

try {
    if ($PSVersionTable.PSVersion -lt [version]'5.1') { throw 'PowerShell 5.1 or later is required.' }
    if ([Environment]::OSVersion.Platform -ne [PlatformID]::Win32NT) { throw 'Use sh scripts/setup.sh on macOS and Linux.' }
    if ([Environment]::OSVersion.Version.Major -lt 10) { throw 'Node 24 requires Windows 10 / Server 2016 or later.' }
    $nodeVersion = Get-LockedVersion '.node-version'
    $kokaVersion = Get-LockedVersion '.koka-version'
    $architecture = $env:PROCESSOR_ARCHITEW6432
    if (-not $architecture) { $architecture = $env:PROCESSOR_ARCHITECTURE }
    switch ($architecture.ToUpperInvariant()) {
        'AMD64' { $arch = 'x64' }
        'ARM64' {
            $arch = 'arm64'
            if ([Environment]::OSVersion.Version.Build -lt 22000) { throw 'Koka uses x64 emulation on ARM64 Windows; Windows 11 or later is required.' }
            Write-Host 'Using native ARM64 Node and the official x64 Koka compiler through Windows emulation.'
        }
        default { throw 'Official tool binaries support only x64 and ARM64 Windows.' }
    }
    if (-not (Get-Command tar.exe -ErrorAction SilentlyContinue)) { throw 'tar.exe is required (included in current Windows 10/11). Install it or update Windows, then rerun setup.' }
    [Net.ServicePointManager]::SecurityProtocol = [Net.SecurityProtocolType]::Tls12
    if (Test-Path -LiteralPath $tools) {
        if ((Get-Item -LiteralPath $tools).Attributes -band [IO.FileAttributes]::ReparsePoint) { throw '.tools must be inside this checkout, not a junction or symbolic link.' }
    } else { New-Item -ItemType Directory -Path $tools | Out-Null }
    try { New-Item -ItemType Directory -Path $lock | Out-Null; $lockOwned = $true }
    catch { throw 'Another setup owns .tools/setup.lock. If it was interrupted, remove that lock after confirming no setup is running.' }
    $stage = Join-Path $tools ('.setup.' + [guid]::NewGuid().ToString('N'))
    New-Item -ItemType Directory -Path $stage | Out-Null

    $nodePrefix = Join-Path $tools 'node'
    if (Test-Node $nodePrefix) { Write-Host "Using local Node.js $nodeVersion" }
    else {
        $archiveName = "node-v$nodeVersion-win-$arch.zip"
        $archivePath = Join-Path $stage $archiveName
        Get-Download "https://nodejs.org/dist/v$nodeVersion/$archiveName" $archivePath
        Assert-Archive $archiveName $archivePath
        Expand-Archive -LiteralPath $archivePath -DestinationPath (Join-Path $stage 'node-unpacked')
        Move-Item -LiteralPath (Join-Path $stage "node-unpacked/node-v$nodeVersion-win-$arch") -Destination (Join-Path $stage 'node')
        if (-not (Test-Node (Join-Path $stage 'node'))) { throw 'The downloaded Node binary could not run. See docs/INSTALLATION.md.' }
        Install-Directory 'node'
        Write-Host "Installed local Node.js $nodeVersion"
    }

    $kokaPrefix = Join-Path $tools 'koka'
    if (Test-Koka $kokaPrefix) { Write-Host "Using local Koka $kokaVersion" }
    else {
        $archiveName = "koka-v$kokaVersion-windows-x64.tar.gz"
        $archivePath = Join-Path $stage $archiveName
        Get-Download "https://github.com/koka-lang/koka/releases/download/v$kokaVersion/$archiveName" $archivePath
        Assert-Archive $archiveName $archivePath
        New-Item -ItemType Directory -Path (Join-Path $stage 'koka') | Out-Null
        & tar.exe -xzf $archivePath -C (Join-Path $stage 'koka')
        if ($LASTEXITCODE -ne 0) { throw 'Koka archive extraction failed.' }
        if (-not (Test-Koka (Join-Path $stage 'koka'))) { throw 'The downloaded Koka binary or source library could not run. See docs/INSTALLATION.md.' }
        Install-Directory 'koka'
        Write-Host "Installed local Koka $kokaVersion"
    }

    $env:PATH = "$nodePrefix;$kokaPrefix\bin;$env:PATH"
    if (-not $ToolsOnly) {
        Push-Location -LiteralPath $repo
        try {
            & (Join-Path $nodePrefix 'node.exe') 'scripts/project.mjs' 'check'
            if ($LASTEXITCODE -ne 0) { throw 'Project checks failed; see the output above.' }
        } finally { Pop-Location }
    }
} catch {
    [Console]::Error.WriteLine('setup: ' + $_.Exception.Message)
    exit 1
} finally {
    if ($stage -and (Test-Path -LiteralPath $stage)) { Remove-Item -LiteralPath $stage -Recurse -Force }
    if ($lockOwned) { Remove-Item -LiteralPath $lock -Force }
}
