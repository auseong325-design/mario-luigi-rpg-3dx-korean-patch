# fps60 tools status (workstream TG: Ghidra + decompiled dumps)

Updated: 2026-10-30 13:50 KST by the lead (TG hit its tool-call budget after the 1dx_kr dump finished;
verified: `work/fps60/decomp/1dx_kr/summary.txt` = static 12,082 functions / 0 failed, EtcSys 1,311 / 0 failed,
MiniGame/Staffroll/Title complete; `decomp.py 1dx_kr <addr> --cached` works).

| game | status | what exists |
|---|---|---|
| `3dx_v12` | **READY** | full decompiled C dump of static + all 15 CROs, function index, Ghidra project, `decomp.py` |
| `1dx_kr` | **READY** | full decompiled C dump of static + EtcSys/MiniGame/Staffroll/Title, `functions.tsv`, Ghidra project `work/fps60/ghidra/1dx_kr/1dx_kr.gpr` |

Note: `scripts/fps60/ghidra/ImportLayout.java` was edited by TG at 13:46, after the last import; it has not
been re-run. Do not re-import unless a dump is wrong.

## Where things are

- Dumps: `work/fps60/decomp/3dx_v12/<module>.c` (one file per module: `static.c` 16 MB, `HugeBattle.c`,
  `Battle.c`, `KJRPG.c`, `KJMenu.c`, `MainMenu.c`, ...). Every function starts with
  `// FUNC 0x<addr> <name> (<module>)` and one info line
  `//   sym <mangled> | size 0x.. | file <Module>+0x<file offset> | callers(N): 0x.. 0x.. | datarefs N`.
- Index: `work/fps60/decomp/3dx_v12/functions.tsv` (addr, end, size, module, name, mangled symbol, file, line,
  status, callers). `summary.txt` = per-module counts.
- Ghidra project (master, do not open in a GUI while others work): `work/fps60/ghidra/3dx_v12/3dx_v12.gpr`,
  program `3dx_v12.code.bin`. Layout/labels input: `work/fps60/ghidra/3dx_v12/layout.tsv`; coverage `stats.tsv`.
- Ghidra 12.2 (JDK 25 Temurin): `tools/ghidra/ghidra_12.2_PUBLIC/`. Scripts: `scripts/fps60/ghidra/`.

## Usage

Grep the dumps first (fast), e.g. grep `isFps30` in `work/fps60/decomp/3dx_v12/` or look a function up:

```
python scripts/fps60/ghidra/decomp.py 3dx_v12 --find TaskBase          # list matches from the index (instant)
python scripts/fps60/ghidra/decomp.py 3dx_v12 0x25edd0 --cached        # print from the dump (instant)
python scripts/fps60/ghidra/decomp.py 3dx_v12 0x25edd0 0x13e8b8        # fresh decompile, read-only (~6-30 s)
python scripts/fps60/ghidra/decomp.py 3dx_v12 ad::fw::TaskBase::funcInit --xrefs --asm
python scripts/fps60/ghidra/decomp.py 3dx_v12 Battle::EntryTask        # CRO non-mangled exports are Module::name
```

Targets: any address inside a function, an exact or mangled name, `a::b::c`, or a substring (more than 8 hits
are listed instead of decompiled; `--max-match N`). `--xrefs` lists callers including calls that reach the
function through CRO veneers. Batch several targets in one call. Run it like every other Python command:
`Start-Process .venv\Scripts\python.exe ... -RedirectStandardOutput <file>` + `WaitForExit(timeout)`.
Fresh mode works on a private snapshot copy of the project (`work/fps60/ghidra/_snap/<game>/slot<k>`, up to
8 concurrent callers, re-copied automatically when the master project changes), so it never conflicts with
other agents or with the dumps.

## What the program contains (3dx_v12)

- One program, language `ARM:LE:32:v6` (ARMv6K + VFPv2) with compiler spec `hardfp` (stock `ARM.cspec`,
  AAPCS-VFP: floats in s0-s15). The game passes/returns floats in VFP registers (e.g. `calcUpdateSpd` returns
  in s0); the stock v6 spec has no float registers, so `hardfp` was added to
  `tools/ghidra/.../ARM/data/languages/ARM.ldefs` (backup `ARM.ldefs.orig`). Another Ghidra install needs the
  same line to open the project.
- Memory: static `code.bin` at 0x100000 (text RX 0x100000-0x388FFF, rodata R 0x389000, data RW 0x3EF000-0x3F816F,
  bss 0x3F8170 +0x3CBD0) and every CRO image from `work/fps60/link/3dx_v12/*.bin` at its analysis base
  (`<Module>.hdr/.text/.rodata/.tables/.data/.bss` blocks). Config memory 0x1FF80000 and shared page 0x1FF81000
  are empty RW blocks with labels (`SHAREDPAGE_3D_SLIDERSTATE` = 0x1FF81080, `CFGMEM_APPMEMTYPE` = 0x1FF80030 ...).
- Symbols: all 2,766 names of `symbols.tsv` (2,561 functions, demangled by Ghidra into namespaces/classes with
  signatures). CRO non-mangled exports live in a namespace per module (`Battle::EntryTask`).
- Veneers: 3,905 `ldr pc,[pc,#-4]; .word` veneers are thunk functions of their targets (3,676 in CROs, 229 in
  static), so calls from CROs into static (and back) show the real callee name. In the dumps a veneer prints as
  `// FUNC 0x.. ->target (Module)` with a one-line body.
- Static import slots: the 222 named imports of `static.crs` were bound to the CRO analysis addresses
  (written into the program copy only), so static -> CRO calls resolve too (e.g. static veneers -> `kj::TaskBtlAtk`).
- RTTI: 2,028 `type_info` objects recovered (only 47 were exported) and 2,051 vtables (1,838 primary).
  Vtable address points are labelled `<Class>::vtable` (secondary vtables `vtable_sec0x<off>`), so constructors
  read `*(...)this = &btl::ObjBase::vtable`.
- Virtual functions without an export name are named `<Class>::vfunc_0x<slot offset>` (8,365 functions;
  owner = the most-base class whose vtable uses the pointer). The suffix is the byte offset of the slot from the
  vtable address point, NOT the real method name. Example: `btl::Main::vfunc_0x18`, `fld::System::vfunc_0x18`.
- Coverage: 25,929 functions (static 11,643; HugeBattle 6,189; Battle 2,019; KJRPG 1,618; KJMenu 1,245 ...),
  94.1 % of text bytes are instructions (`work/fps60/ghidra/3dx_v12/stats.tsv`). Dump: 21,588 functions
  decompiled, 0 failures, 0 timeouts; 4,341 thunks.

## Known gaps / how to read the output

- No structure types: fields appear as `this[0x45]` (byte offset on an empty class placeholder) or
  `*(float *)(this + 0x20)`. Read the number as the byte offset (e.g. `this[0x45]` = TaskBase+0x45 fps byte).
- `/* WARNING: Could not recover jumptable ... */` (about 1,300 sites) is almost always an indirect tail call
  `pop {..,lr}; bx rN` (virtual/function-pointer tail call); Ghidra treats it as a call. Real switch tables are
  recovered normally.
- Unnamed non-virtual functions keep Ghidra names `FUN_<addr>`; global data is untyped (`DAT_<addr>`).
- 4 functions contain `halt_baddata()` (undecodable instruction); 1 function each in `KJGuide`/`MenuGuide`
  (those CROs have only 0xAC bytes of code).
- CRO addresses are analysis addresses (bases in `work/fps60/link/3dx_v12/link.json`); the info line gives
  `Module+fileoffset` for patching. Runtime CRO addresses must be measured (RT).
- Fresh decompilation of the same function always matches the dump (same program, same options).

## Rebuild (TG only)

```
python scripts/fps60/ghidra/ghidra_run.py import 3dx_v12      # prepare.py + import + auto-analysis + PostAnalysis (~2 min)
python scripts/fps60/ghidra/ghidra_run.py dump 3dx_v12 --jobs 3 --threads 4   # ~1 min, staged then moved in place
python scripts/fps60/ghidra/ghidra_run.py status
```
