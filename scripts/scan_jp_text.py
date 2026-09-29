"""Scan the whole v1.2 RomFS + ExeFS for Japanese text that lives outside Msg/*.msbt.

Looks for runs of >= 3 kana/kanji in UTF-16LE and UTF-8, inside plain files and
inside (BLZ-decompressed) BG4 entries. Writes work/scan_text_outside_msbt.json.
"""

from __future__ import annotations

import json
import re
import sys
from collections import defaultdict

from lib3dx import ROMFS_BASE, ROMFS_UPDATE, ROOT, blz_decompress, read_bg4

JP = "\u3041-\u3096\u30a1-\u30fa\u30fc\u4e00-\u9fff\uff01-\uff5e\u3001\u3002\u300c\u300d\u2026"
RUN = re.compile("[" + JP + "]{3,}")


def _kana(s: str) -> bool:
    return any("\u3041" <= c <= "\u30fa" for c in s)


def _plausible(s: str) -> bool:
    """Reject binary noise: ASCII byte pairs read as UTF-16 ('Mat_' -> '慍彴') and kana-poor runs."""
    ascii_pair = sum(1 for c in s if 0x20 <= (ord(c) & 0xFF) <= 0x7E and 0x20 <= (ord(c) >> 8) <= 0x7E)
    kana = sum(1 for c in s if "\u3041" <= c <= "\u30fc")
    return ascii_pair <= 0.2 * len(s) and kana >= 2 and kana >= 0.3 * len(s)


def scan_bytes(data: bytes) -> list[str]:
    """Kana-containing runs in 2-aligned UTF-16LE and in UTF-8."""
    hits = [m.group(0) for m in RUN.finditer(data[: len(data) & ~1].decode("utf-16-le", errors="replace"))
            if _plausible(m.group(0))]
    hits += [m.group(0) for m in RUN.finditer(data.decode("utf-8", errors="replace")) if _plausible(m.group(0))]
    return hits


def files() -> dict[str, "Path"]:
    out = {}
    for base in (ROMFS_BASE, ROMFS_UPDATE):
        for p in base.rglob("*"):
            if p.is_file():
                out[p.relative_to(base).as_posix()] = p
    for exe in ("exefs2/.code",):
        out[exe] = ROOT / exe
    return out


def main() -> int:
    report: dict[str, dict] = {}
    for rel, path in sorted(files().items()):
        if rel.startswith("Msg/") and (rel.endswith(".msbt") or rel.endswith("Msg.dat")):
            continue
        if rel.startswith("Snd/"):
            continue
        data = path.read_bytes()
        found: dict[str, list[str]] = defaultdict(list)
        if data[:4] == b"BG4\0":
            _, entries = read_bg4(data)
            for e in entries:
                if e.name == "(invalid)":
                    continue
                raw = e.data
                if e.compressed:
                    try:
                        raw = blz_decompress(raw)
                    except Exception:
                        continue
                h = scan_bytes(raw)
                if h:
                    found[e.name] = h
        else:
            h = scan_bytes(data)
            if h:
                found["-"] = h
        if found:
            n = sum(len(v) for v in found.values())
            report[rel] = {"strings": n, "entries": len(found),
                           "sample": [s for v in list(found.values())[:6] for s in v[:2]][:8],
                           "by_entry": {k: v for k, v in found.items()}}
            print(f"{rel:40s} strings={n:5d} entries={len(found):4d} e.g. {report[rel]['sample'][:3]}")
    (ROOT / "work" / "scan_text_outside_msbt.json").write_text(
        json.dumps(report, ensure_ascii=False, indent=1), encoding="utf-8")
    return 0


if __name__ == "__main__":
    sys.exit(main())
