@echo off
setlocal
if exist "%~dp0.tools\node\node.exe" goto local
where node >nul 2>&1
if errorlevel 1 goto missing
node "%~dp0scripts\project.mjs" %*
exit /b %errorlevel%
:local
"%~dp0.tools\node\node.exe" "%~dp0scripts\project.mjs" %*
exit /b %errorlevel%
:missing
echo Run: powershell -NoProfile -ExecutionPolicy Bypass -File scripts\setup.ps1
exit /b 1
