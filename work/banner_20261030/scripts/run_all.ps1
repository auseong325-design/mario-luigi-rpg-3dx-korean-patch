# Rebuild everything of the BANNER work in order (read-only on originals; writes only work/banner_20261030).
# Run from anywhere:  powershell -File work\banner_20261030\scripts\run_all.ps1
$ErrorActionPreference = 'Stop'
$root = "C:\AI-Projects\mario-luigi-rpg-3dx-korean-patch"
$s = "$root\work\banner_20261030\scripts"
Set-Location $root
$cia = (Get-ChildItem "$root\00040000001CA900*.cia").FullName
$out = "work/banner_20261030/out"
& "$s\run.ps1" 300 work/banner_20261030/scripts/extract.py            # banners -> extract/
& "$s\run.ps1" 300 work/banner_20261030/scripts/title_src.py          # title textures (JP v1.2, installed KR)
& "$s\run.ps1" 600 work/banner_20261030/scripts/fit_jp.py             # how the JP banner was made
& "$s\run.ps1" 120 work/banner_20261030/scripts/make_logo.py          # Korean COMMON texture
& "$s\run.ps1" 900 work/banner_20261030/scripts/build_banner.py       # banner: identity + Korean
& "$s\run.ps1" 900 work/banner_20261030/scripts/cia.py build "$cia" exefs/banner - "$out/cia/identity_build.json"
& "$s\run.ps1" 1200 work/banner_20261030/scripts/cia.py build "$cia" "$out/banner/banner_ko.bin" "$out/00040000001CA900_ML3DX_KoreanBanner.cia" "$out/cia/korean_build.json"
& "$s\run.ps1" 900 work/banner_20261030/scripts/cia.py info "$out/00040000001CA900_ML3DX_KoreanBanner.cia" "$out/cia/korean_cia_info.json"
& "$s\run.ps1" 120 work/banner_20261030/scripts/sigcheck.py "$out/00040000001CA900_ML3DX_KoreanBanner.cia" "$out/cia/korean_sigcheck.json"
& "$s\run.ps1" 900 work/banner_20261030/scripts/verify_final.py       # read-back from the CIA
$j = Start-Job -ScriptBlock { param($r, $w) Set-Location $r
    & "$w/scripts/spica_dump.ps1" -InputCgfx "$w/extract/3dx_banner.cgfx" -OutputJson "$w/extract/3dx_spica.json" | Out-Null
    & "$w/scripts/spica_dump.ps1" -InputCgfx "$w/extract/ko_banner.cgfx" -OutputJson "$w/extract/ko_spica.json" | Out-Null } -ArgumentList $root, "work/banner_20261030"
if (-not (Wait-Job $j -Timeout 150)) { Stop-Job $j; throw "SPICA timeout" }
Remove-Job $j -Force
& "$s\run.ps1" 300 work/banner_20261030/scripts/mockup.py
# 2026-11-20: Korean HOME title (SMDH icon) + base CIA with banner and icon + v1.2 update CIA with icon
$upd = (Get-ChildItem "$root\0004000E001CA900*.cia").FullName
& "$s\run.ps1" 120 work/banner_20261030/scripts/make_icon.py
& "$s\run.ps1" 1500 work/banner_20261030/scripts/cia.py replace "$cia" "$out/00040000001CA900_ML3DX_KoreanBanner_Name.cia" "$out/cia_name/base_build.json" "banner=$out/banner/banner_ko.bin" "icon=$out/icon/icon_ko.bin"
& "$s\run.ps1" 900 work/banner_20261030/scripts/cia.py replace "$upd" "$out/0004000E001CA900_ML3DX_v1.2_KoreanName.cia" "$out/cia_name/update_build.json" "icon=$out/icon/icon_ko.bin"
& "$s\run.ps1" 600 work/banner_20261030/scripts/preview_home.py
