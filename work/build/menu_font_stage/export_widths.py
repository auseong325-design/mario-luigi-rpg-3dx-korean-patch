"""Advance table for scripts/merge_ko.py after the staged font is installed (FONT, wave 5).

merge_ko.charset() takes ASCII advances from the ORIGINAL 3DX font.bffnt (lib3dx.bffnt_advances reads romfs)
plus EXTRA_ASCII_WIDTH. With the staged font, letters/digits/'+'/'/' have the 1DX advances, so the model must
take these values (adv.update(...) after EXTRA_ASCII_WIDTH). Writes merge_ko_ascii_widths.json:
{"font": {char: advance, ...}, "font_btl": {...}} for every character whose advance differs from the model.
"""
import json
import sys
from pathlib import Path

STAGE = Path(__file__).resolve().parent
ROOT = STAGE.parents[2]
sys.path.insert(0, str(ROOT / "scripts"))
import libbffnt as L  # noqa: E402
import merge_ko as M  # noqa: E402


def advances(path: Path) -> dict[str, int]:
    f = L.parse(path.read_bytes())
    w = f.widths()
    return {chr(c): w[g].char for c, g in f.char_map().items() if c < 0x80}


def main():
    model, _ = M.charset()
    out = {"note": __doc__.strip().splitlines()[0], "font": {}, "font_btl_for_reference": {}}
    new = advances(STAGE / "romfs/Msg/JP_ja/font.bffnt")
    for ch, a in sorted(new.items()):
        if model.get(ch) != a:
            out["font"][ch] = a
    old_btl = advances(ROOT / "patch/00040000001CA900/romfs/Msg/JP_ja/font_btl.bffnt")
    for ch, a in sorted(advances(STAGE / "romfs/Msg/JP_ja/font_btl.bffnt").items()):
        if old_btl.get(ch) != a:
            out["font_btl_for_reference"][ch] = [old_btl.get(ch), a]
    (STAGE / "merge_ko_ascii_widths.json").write_text(json.dumps(out, ensure_ascii=False, indent=1), "utf-8")
    print(f"font: {len(out['font'])} model advances to update; font_btl: {len(out['font_btl_for_reference'])} changed")


if __name__ == "__main__":
    main()
