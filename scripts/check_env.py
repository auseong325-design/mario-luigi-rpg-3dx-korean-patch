"""Environment self-check for the M&L RPG3 DX Korean patch project.

Run:  .venv\\Scripts\\python scripts\\check_env.py
Every check is read-only: nothing under romfs/, exefs/, unpacked/ or the .nds is modified.
"""

from __future__ import annotations

import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
TITLE_ID = "00040000001CA900"  # Mario & Luigi RPG3 DX (JPN, CTR-P-A3RJ)

results: list[tuple[bool, str]] = []


def check(ok: bool, label: str) -> bool:
    results.append((ok, label))
    print(f"[{'OK' if ok else 'NG'}] {label}")
    return ok


# ---------------------------------------------------------------- BG4 helpers
def bg4_entries(data: bytes):
    """Yield (name, raw_bytes, is_compressed) for each valid BG4 entry."""
    if data[:4] != b"BG4\0":
        raise ValueError("not a BG4 archive")
    _ver, count, _meta = struct.unpack_from("<HHI", data, 4)
    names_base = 16 + count * 14
    for n in range(count):
        off, size, _hash, name_off = struct.unpack_from("<IIIH", data, 16 + n * 14)
        end = data.find(b"\0", names_base + name_off)
        name = data[names_base + name_off:end].decode("ascii", "replace") if end >= 0 else f"#{n}"
        if name.lower() == "(invalid)":
            continue
        start = off & 0x7FFFFFFF
        yield name, data[start:start + (size & 0x7FFFFFFF)], bool(off >> 31)


def main() -> int:
    print(f"Project: {ROOT}\nPython : {sys.version.split()[0]} ({sys.executable})\n")

    # 1. Python libraries -------------------------------------------------
    try:
        import mnllib, mnlscript, mnltools, pymsbmnl, ndspy, PIL, numpy, fontTools  # noqa: F401
        check(True, "Python libraries import (mnllib, mnlscript, mnltools, pymsbmnl, ndspy, Pillow, numpy, fontTools)")
    except ImportError as exc:
        check(False, f"Python libraries import: {exc}")
        return 1

    # 2. Original game data present ------------------------------------------
    for rel in ["romfs/Msg/JP_ja/FMsg.dat", "romfs/Msg/JP_ja/font.bffnt", "exefs/.code",
                "mario&luigi rpg 3.nds", "unpacked/data/FEvent/FEvent.dat"]:
        check((ROOT / rel).is_file(), f"source file present: {rel}")

    # 3. 3DX text: BG4 -> MSBT -> readable Japanese ---------------------------
    from mnllib.dt.text import DTLMSAdapter
    fmsg = (ROOT / "romfs/Msg/JP_ja/FMsg.dat").read_bytes()
    entries = list(bg4_entries(fmsg))
    msbt_count = sum(1 for _, raw, _ in entries if raw[:8] == b"MsgStdBn")
    check(msbt_count > 0, f"FMsg.dat BG4 archive: {len(entries)} entries, {msbt_count} MSBT")
    name, raw, _ = next(e for e in entries if e[1][:8] == b"MsgStdBn")
    try:
        doc = pymsbmnl.msbt_from_buffer(lambda: DTLMSAdapter("JP_ja"), raw)
        sample = next((m.text for m in doc.messages if m.text.strip()), "")
        check(True, f"MSBT decode '{name}': {len(doc.messages)} msgs, sample={sample[:30]!r}")
    except Exception as exc:  # adapter tags may differ from Dream Team; report, don't crash
        check(False, f"MSBT decode '{name}' with DT adapter: {type(exc).__name__}: {exc}")

    # 4. Korean NDS (CLJK) -----------------------------------------------------
    nds = (ROOT / "mario&luigi rpg 3.nds").read_bytes()
    check(nds[0x0C:0x10] == b"CLJK", f"NDS game code = {nds[0x0C:0x10].decode()} (expect CLJK, Korean BIS)")
    std = ROOT / "work/nds_kr/data"
    check((std / "arm9.dec.bin").is_file() and (std / "overlay.dec").is_dir(),
          "mnllib-standard NDS unpack exists (work/nds_kr/data)")

    # 5. Fonts: KS X 1001 Hangul coverage --------------------------------------
    from fontTools.ttLib import TTFont
    ksx_hangul = [chr(c) for c in range(0xAC00, 0xD7A4)
                  if len(chr(c).encode("euc-kr", errors="ignore")) == 2]
    for font_path in sorted((ROOT / "fonts").glob("*.[to]tf")):
        cmap = TTFont(font_path, lazy=True).getBestCmap()
        missing = sum(1 for ch in ksx_hangul if ord(ch) not in cmap)
        check(missing == 0, f"font {font_path.name}: KS X 1001 Hangul {len(ksx_hangul) - missing}/{len(ksx_hangul)}")

    # 6. External tools + emulator hook ----------------------------------------
    for rel in ["tools/Kuriimu2/Kuriimu2.exe", "tools/SwitchToolbox/Toolbox.exe",
                "tools/Spritoglobin-DX/spritoglobin_dx.exe"]:
        check((ROOT / rel).is_file(), f"tool present: {rel}")
    mods = Path.home() / "AppData/Roaming/Azahar/load/mods" / TITLE_ID
    check(mods.is_dir() and (mods / "romfs").is_dir(), f"Azahar LayeredFS hook: {mods} -> patch/{TITLE_ID}")

    bad = [label for ok, label in results if not ok]
    print(f"\n{len(results) - len(bad)}/{len(results)} checks passed.")
    return 1 if bad else 0


if __name__ == "__main__":
    sys.exit(main())
