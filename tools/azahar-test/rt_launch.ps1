# RT launcher for the portable Azahar test instance (never touches %APPDATA%\Azahar).
#   powershell -ExecutionPolicy Bypass -File tools\azahar-test\rt_launch.ps1            # boot the game
#   powershell -ExecutionPolicy Bypass -File tools\azahar-test\rt_launch.ps1 -Stop      # stop it
#   ... -Game <path-to-.app/.3ds/.cxi>   boot something else;  -NoGame  open the emulator only
# The emulator is started with Start-Process (stdout/stderr -> user\log\rt_stdout.txt / rt_stderr.txt)
# and returns immediately; its PID is written to rt_azahar.pid. -Stop only kills that PID, and only if
# the process image is this folder's azahar.exe.
param([switch]$Stop, [switch]$NoGame, [string]$Game = "")
[Console]::OutputEncoding = [Text.UTF8Encoding]::new($false)
$here = Split-Path -Parent $MyInvocation.MyCommand.Path
$exe = Join-Path $here 'azahar.exe'
$pidFile = Join-Path $here 'rt_azahar.pid'

if ($Stop) {
    if (-not (Test-Path $pidFile)) { "no pid file"; exit 0 }
    $id = [int](Get-Content $pidFile -TotalCount 1)
    $p = Get-Process -Id $id -ErrorAction SilentlyContinue
    if (-not $p) { "pid $id not running"; Remove-Item $pidFile; exit 0 }
    if ($p.Path -ne $exe) { "pid $id is $($p.Path), not the test instance: refusing"; exit 1 }
    [void]$p.CloseMainWindow()
    if (-not $p.WaitForExit(8000)) { Stop-Process -Id $id -Force; "killed pid $id" } else { "closed pid $id" }
    Remove-Item $pidFile
    exit 0
}

if (Test-Path $pidFile) {
    $id = [int](Get-Content $pidFile -TotalCount 1)
    $p = Get-Process -Id $id -ErrorAction SilentlyContinue
    if ($p -and $p.Path -eq $exe) { "already running: pid $id"; exit 0 }
}
if (-not $NoGame -and -not $Game) {
    $z = '00000000000000000000000000000000'
    $Game = Join-Path $here "user\sdmc\Nintendo 3DS\$z\$z\title\00040000\001ca900\content\00000000.app"
}
$logDir = Join-Path $here 'user\log'
New-Item -ItemType Directory -Force $logDir | Out-Null
# IMPORTANT (lead fix 2026-10-30): no -RedirectStandardOutput/-Error here. Redirection makes Start-Process use
# CreateProcess with handle inheritance, so the long-lived emulator inherits the agent shell's stdout pipe and the
# calling tool never returns until Azahar exits (stalled RT for 45 min). Without redirection Start-Process uses
# ShellExecute (no inherited handles). Azahar writes its own log to user\log\azahar_log.txt.
$argList = @()
if (-not $NoGame) { $argList += ('"' + $Game + '"') }
if ($argList.Count -gt 0) {
    $p = Start-Process -FilePath $exe -ArgumentList $argList -WorkingDirectory $here -PassThru
} else {
    $p = Start-Process -FilePath $exe -WorkingDirectory $here -PassThru
}
$p.Id | Set-Content $pidFile
"started pid=$($p.Id) game=$Game (detached; log: user\log\azahar_log.txt)"
