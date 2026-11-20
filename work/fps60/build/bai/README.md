# BAI fix for 60fps (BTL2, 2026-10-30)

Staged LayeredFS file: `romfs/BAI/BAI.dat` (battle AI scripts). Details and evidence: `work/fps60/analysis/battle.md`
sections 2.4, 2.5 and 7.

## Build

```
.venv\Scripts\python.exe scripts\fps60\btl_baifix.py identity     # zero-change rebuild == source (byte-identical)
.venv\Scripts\python.exe scripts\fps60\btl_baifix.py build        # writes this folder (groups hold,step2,orbit)
.venv\Scripts\python.exe scripts\fps60\btl_baifix.py verify work\fps60\build\bai\romfs\BAI\BAI.dat
```
Run each with a timeout (Start-Process + WaitForExit); each takes about 2 s. `--groups hold,step2` builds without
the orbit `wait(2)` changes.

- Source: `romfs/BAI/BAI.dat` (v1.0; the v1.2 update and the Korean patch have no BAI/), 2,862,248 bytes,
  sha256 `12be16cd099b69aee84b9f5fa6cd07342eccb112f1ddc21d440187061de0c2f2`.
- Output: `romfs/BAI/BAI.dat`, 2,862,076 bytes, sha256 `c681a963b8428128a2d9133c39911f9f2acf5a53e83dff0a097de8fbe750fbb6`.
- `diff.tsv`: the 15 changed instructions (script, offset, old/new bytes, old/new instruction, reason).
- `manifest.json`: hashes, groups, changed scripts.
- `scan_*.tsv`: the scans the site list came from (`btl_timing.py`, `btl_cscan.py`, `btl_asmscan.py`).

## What changes

All edits are same-length, so no script offset moves; only 9 of 543 entries are recompressed (BLZ, ndspy), every
other entry keeps its original bytes.

| transform | sites | 30fps | 60fps |
|---|---|---|---|
| `$v = op025(2f)` -> `$v = op016($v, $7012)` | 10 (5 hold-grace loops, 5 other timers) | `v + 2.0` (step = 2.0): identical | `v + 1.0` per frame: same ms as 30fps |
| `wait(1)` -> `wait(2)` | 5 orbit loops (enemy circles 6.8-8 deg per frame) | resumes next frame: identical | loop runs every 2nd frame: same ms as 30fps |

Identical at 30fps holds while the battle step is exactly 2.0, i.e. in every phase except the victory slow-motion
(`btl::TaskBtlResultPcWin`), where none of these enemy-attack scripts run.

## Install (lead)

Copy `romfs/BAI/BAI.dat` into the mod folder: Luma `/luma/titles/00040000001CA900/romfs/BAI/BAI.dat`,
Azahar `load/mods/00040000001CA900/romfs/BAI/BAI.dat`. No code, CRO or CRR change goes with it.
