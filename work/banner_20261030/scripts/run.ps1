param([int]$Timeout = 120, [Parameter(ValueFromRemainingArguments = $true)][string[]]$Rest)
# Run a project-venv python script with a hard timeout; stdout/stderr go to logs\<name>.out/.err
[Console]::OutputEncoding = [Text.UTF8Encoding]::new($false)
$root = "C:\AI-Projects\mario-luigi-rpg-3dx-korean-patch"
$work = "$root\work\banner_20261030"
New-Item -ItemType Directory -Force "$work\logs" | Out-Null
$name = [IO.Path]::GetFileNameWithoutExtension($Rest[0]) + "_" + ($Rest[1] -replace '[^A-Za-z0-9_-]', '')
$out = "$work\logs\$name.out"; $err = "$work\logs\$name.err"
$argList = @("-X", "utf8") + ($Rest | ForEach-Object { if ($_ -match '\s') { '"' + $_ + '"' } else { $_ } })
$p = Start-Process -FilePath "$root\.venv\Scripts\python.exe" -ArgumentList $argList -WorkingDirectory $root -NoNewWindow -PassThru -RedirectStandardOutput $out -RedirectStandardError $err
$null = $p.Handle
if (-not $p.WaitForExit($Timeout * 1000)) { Stop-Process -Id $p.Id -Force; Write-Output "TIMEOUT after $Timeout s" }
else { Write-Output "exit $($p.ExitCode)" }
Get-Content $out -Encoding UTF8 -TotalCount 400
Get-Content $err -Encoding UTF8 -TotalCount 60
