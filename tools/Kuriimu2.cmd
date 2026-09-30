@echo off
rem Kuriimu2 1.2.1 targets .NET Core 3.1; roll forward to the installed .NET 6/8 runtime.
set DOTNET_ROLL_FORWARD=Major
start "" "%~dp0Kuriimu2\Kuriimu2.exe" %*
