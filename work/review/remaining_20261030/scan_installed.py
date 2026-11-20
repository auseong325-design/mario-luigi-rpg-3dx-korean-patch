"""Independent scan of the INSTALLED patch (patch/00040000001CA900/romfs) for leftover Japanese.

2026-10-30 review ("남은 미작업·미한글화 잔재 검토"). Reads the installed files themselves, not the
plans, and compares them with the v1.2 originals (lib3dx.romfs_path). Read-only: writes only
scan_installed.json / scan_installed.txt next to this script.

  text      every message of the 7 installed message files: Japanese characters left, messages
            identical to the Japanese original, ruby tags, characters outside KS X 1001 / the fonts
  lyt       every texture of the 6 Lyt dats: changed vs original, cross-checked with lyt_plan.json
  obj/hb/fmdl  changed BG4 entries / archives vs the plans
  staffroll Japanese left in the installed Staffroll.bin
  smdh      HOME-menu titles in exefs2/icon (outside RomFS; LayeredFS cannot replace it)
"""

from __future__ import annotations

import collections
import hashlib
import json
import re
import struct
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
sys.path.insert(0, str(ROOT / "scripts"))

import lib3dx as L  # noqa: E402
import libbffnt  # noqa: E402
import libstaffroll  # noqa: E402
import lytimg  # noqa: E402

PATCH = ROOT / "patch" / "00040000001CA900" / "romfs"
JP_RE = re.compile("[\u3040-\u309f\u30a0-\u30fa\u30fc-\u30ff\u3400-\u4dbf\u4e00-\u9fff"
                   "\uff01-\uff5e\uff65-\uff9f\u3001\u3002\u3005\u301c]")
RUBY_RE = re.compile(r"\[Ruby ([^;\]]*);([^\]]*)\]")
TAG_RE = re.compile(r"\[[^\[\]]*\]")
HANGUL = re.compile("[\uac00-\ud7a3]")


def plain(text: str) -> tuple[str, int]:
    n = len(RUBY_RE.findall(text))
    t = RUBY_RE.sub(lambda m: m.group(1) + m.group(2), text)
    return TAG_RE.sub("", t), n


def ksx1001(ch: str) -> bool:
    b = ch.encode("cp949", errors="ignore")
    return len(b) == 2 and 0xB0 <= b[0] <= 0xC8 and b[1] >= 0xA1


def msbt_sources(base_of):
    """(key, msbt bytes) for the 7 message files, read through base_of(rel) -> bytes."""
    for rel in L.MSG_BG4_FILES:
        _, ents = L.read_bg4(base_of(rel))
        for e in ents:
            if e.data[:8] == b"MsgStdBn":
                yield f"{rel}:{e.name}", e.data
    for rel in L.MSG_MSBT_FILES:
        yield rel, base_of(rel)


def scan_text() -> dict:
    orig = {k: L.read_msbt(b) for k, b in msbt_sources(lambda r: L.romfs_path(r).read_bytes())}
    inst = {k: L.read_msbt(b) for k, b in msbt_sources(lambda r: (PATCH / r).read_bytes())}
    out = {"files_missing": sorted(set(orig) - set(inst)), "files_extra": sorted(set(inst) - set(orig)),
           "count_mismatch": [], "japanese_left": [], "identical_to_jp": [], "no_hangul_but_jp_had_kana": [],
           "ruby_tags": 0, "messages": 0, "translated_differs": 0}
    chars = collections.Counter()
    for key, mo in orig.items():
        mi = inst.get(key)
        if mi is None:
            continue
        if len(mo.messages) != len(mi.messages):
            out["count_mismatch"].append([key, len(mo.messages), len(mi.messages)])
            continue
        for a, b in zip(mo.messages, mi.messages):
            out["messages"] += 1
            pa, _ = plain(a.text)
            pb, nr = plain(b.text)
            out["ruby_tags"] += nr
            mid = f"{key}#{b.index}"
            jp = JP_RE.findall(pb)
            if jp:
                out["japanese_left"].append([mid, "".join(sorted(set(jp))), pb[:80]])
            if a.text != b.text:
                out["translated_differs"] += 1
            if pa.strip() and pa == pb and re.search(r"[A-Za-z\u3040-\u30ff\u4e00-\u9fff]", pa):
                out["identical_to_jp"].append([mid, pa[:80]])
            if not HANGUL.search(pb) and re.search("[\u3040-\u30ff]", pa):
                out["no_hangul_but_jp_had_kana"].append([mid, pa[:60], pb[:60]])
            chars.update(c for c in pb if c != "\n")
    fonts = {}
    for f in ("font", "font_l", "font_btl"):
        cm = libbffnt.parse((PATCH / f"Msg/JP_ja/{f}.bffnt").read_bytes()).char_map()
        fonts[f] = sorted(c for c in chars if ord(c) not in cm)
    out["distinct_chars"] = len(chars)
    out["hangul_used"] = sum(1 for c in chars if HANGUL.match(c))
    out["hangul_outside_ksx1001"] = sorted(c for c in chars if HANGUL.match(c) and not ksx1001(c))
    out["missing_in_font"] = fonts
    out["other_symbols"] = {c: n for c, n in sorted(chars.items(), key=lambda x: -x[1])
                            if not (HANGUL.match(c) or 0x20 <= ord(c) < 0x7F)}
    return out


def _entries(data: bytes) -> dict:
    _, ents = L.read_bg4(data)
    return {e.name: e for e in ents}


def scan_lyt() -> dict:
    plan = json.loads((ROOT / "work/img/lyt_plan.json").read_text(encoding="utf-8"))
    changed, changed_other, per_dat = set(), [], {}
    for dat in lytimg.LYT_DATS["3DX"]:
        p = PATCH / f"Lyt/JP/{dat}.dat"
        if not p.exists():
            per_dat[dat] = "not installed (original used)"
            continue
        eo, en = _entries(L.romfs_path(f"Lyt/JP/{dat}.dat").read_bytes()), _entries(p.read_bytes())
        assert list(eo) == list(en), dat
        n = 0
        for name, a in eo.items():
            b = en[name]
            if a.data == b.data:
                continue
            n += 1
            ra, rb = L.bg4_plain(a), L.bg4_plain(b)
            if ra[:4] != b"SARC":
                changed_other.append(f"{dat}/{name} (not SARC)")
                continue
            la = {k: (s, e) for k, s, e in lytimg.sarc_list(ra)}
            lb = {k: (s, e) for k, s, e in lytimg.sarc_list(rb)}
            for k, (s, e) in la.items():
                s2, e2 = lb[k]
                if ra[s:e] != rb[s2:e2]:
                    (changed.add(f"3DX:{dat}/{name}/{k}") if k.endswith(".bflim")
                     else changed_other.append(f"{dat}/{name}/{k}"))
        per_dat[dat] = f"{n} entries changed"
    rep_missing, keep_changed, keep_text, glyt = [], [], [], []
    for it in plan["items"]:
        ids = [it["id"]] + list(it.get("copy_ids") or [])
        hit = [i for i in ids if i in changed]
        if it["dat"] == "GLyt":
            glyt.append([it["id"], it["action"], it.get("jp", ""), it.get("notes", "")[:60]])
        if it["action"] == "replace" and len(hit) != len(ids):
            rep_missing.append([it["id"], f"{len(hit)}/{len(ids)} copies changed", it.get("jp", "")])
        if it["action"] != "replace":
            if hit:
                keep_changed.append([it["id"], len(hit)])
            if (it.get("jp") or "").strip():
                keep_text.append([it["id"], it["jp"], it.get("notes", "")[:80]])
    planned = {i for it in plan["items"] for i in [it["id"]] + list(it.get("copy_ids") or [])}
    return {"per_dat": per_dat, "changed_textures": len(changed),
            "changed_not_in_plan": sorted(changed - planned), "changed_non_texture_files": changed_other,
            "replace_not_fully_installed": rep_missing, "keep_items_changed": keep_changed,
            "keep_items_with_text": keep_text, "glyt_items": glyt}


def scan_bg4_dir(rel_dir: str, names: list[str]) -> dict:
    res = {}
    for n in names:
        rel = f"{rel_dir}/{n}"
        p = PATCH / rel
        if not p.exists():
            res[n] = "not installed"
            continue
        eo, en = _entries(L.romfs_path(rel).read_bytes()), _entries(p.read_bytes())
        res[n] = sorted(k for k in eo if k not in en or eo[k].data != en[k].data)
    return res


def scan_hb() -> dict:
    plan = json.loads((ROOT / "work/img/hb_plan.json").read_text(encoding="utf-8"))
    arcs = sorted({i["arc"] for i in plan["items"]})
    want = sorted({i["arc"] for i in plan["items"] if i["action"] == "replace"})
    res = {}
    for a in arcs:
        p = PATCH / a
        o = L.romfs_path(a)
        res[a] = ("installed, differs" if p.exists() and p.read_bytes() != o.read_bytes()
                  else "installed, same" if p.exists() else "not installed")
    return {"arcs": res, "replace_arcs_not_installed": [a for a in want if not res[a].startswith("installed, differs")]}


def scan_staffroll() -> dict:
    lo = libstaffroll.read(L.romfs_path("Staffroll/JP/Staffroll.bin").read_bytes())
    li = libstaffroll.read((PATCH / "Staffroll/JP/Staffroll.bin").read_bytes())
    jp = [[i, l.text] for i, l in enumerate(li) if JP_RE.search(l.text)]
    diff = [[i, a.text, b.text] for i, (a, b) in enumerate(zip(lo, li)) if a.text != b.text]
    jp_orig = [[i, l.text] for i, l in enumerate(lo) if JP_RE.search(l.text)]
    return {"lines": [len(lo), len(li)], "japanese_left": jp, "changed_lines": diff, "japanese_in_original": jp_orig}


def scan_smdh() -> dict:
    langs = ["Japanese", "English", "French", "German", "Italian", "Spanish", "SimpChinese", "Korean",
             "Dutch", "Portuguese", "Russian", "TradChinese", "?12", "?13", "?14", "?15"]
    out = {}
    for name in ("exefs/icon", "exefs2/icon"):
        d = (ROOT / name).read_bytes()
        assert d[:4] == b"SMDH"
        t = {}
        for k, lang in enumerate(langs):
            base = 8 + k * 0x200
            s = d[base:base + 0x80].decode("utf-16le").split("\0")[0]
            lo = d[base + 0x80:base + 0x180].decode("utf-16le").split("\0")[0]
            pub = d[base + 0x180:base + 0x200].decode("utf-16le").split("\0")[0]
            t[lang] = [s, lo, pub]
        region = struct.unpack_from("<I", d, 0x2018)[0]
        out[name] = {"titles": t, "region_lockout": hex(region), "sha1": hashlib.sha1(d).hexdigest()}
    return out


def main() -> int:
    rep = {"text": scan_text(), "lyt": scan_lyt(),
           "obj": scan_bg4_dir("Obj/JP", ["BUI.dat", "FUI.dat", "KUI.dat", "Menu.dat"]),
           "fmdl": scan_bg4_dir("FMdl/JP", ["FMdl.dat"]), "hb": scan_hb(), "staffroll": scan_staffroll(),
           "smdh": scan_smdh()}
    (HERE / "scan_installed.json").write_text(json.dumps(rep, ensure_ascii=False, indent=1), encoding="utf-8")
    t = rep["text"]
    lines = [f"text: {t['messages']} messages, differs from JP {t['translated_differs']}, "
             f"japanese_left {len(t['japanese_left'])}, identical_to_jp {len(t['identical_to_jp'])}, "
             f"ruby {t['ruby_tags']}, hangul {t['hangul_used']}, outside KS X 1001 {t['hangul_outside_ksx1001']}, "
             f"missing in fonts { {k: len(v) for k, v in t['missing_in_font'].items()} }",
             f"lyt: {rep['lyt']['per_dat']} changed textures {rep['lyt']['changed_textures']}, "
             f"replace not installed {len(rep['lyt']['replace_not_fully_installed'])}, "
             f"keep changed {len(rep['lyt']['keep_items_changed'])}, keep with text {len(rep['lyt']['keep_items_with_text'])}",
             f"hb: not installed replace arcs {rep['hb']['replace_arcs_not_installed']}",
             f"staffroll: japanese_left {len(rep['staffroll']['japanese_left'])}, changed {len(rep['staffroll']['changed_lines'])}"]
    (HERE / "scan_installed.txt").write_text("\n".join(lines) + "\n", encoding="utf-8")
    print("\n".join(lines))
    return 0


if __name__ == "__main__":
    sys.exit(main())
