"""Korean giant-battle UI textures with imgtext 1.3 (work/img/toolkit/README.md).

Letters come from imgtext's source ladder (1DX image > 1DX bitmap font > A+B-B' > GothicA1
vector, README 2); decoration and stroke weight are measured on the 3DX Japanese original
(README 3: target = Japanese face stroke, +-10 %, counters kept open). No per-texture weight
or source overrides of the v1.0 era: those made round 1 thin and soft (README 6).

One letter source per GROUP: textures shown on the same screen / in the same family must not
mix bitmap and vector letters (README 2, lead 2026-09-30). The group source was chosen by
--explore (imgtext defaults for every candidate, next to the original): the one closer in weight
and crispness wins. A group may add render() spacing arguments ("kw": tracking / gap_min, found on
the zoomed review sheets); they apply to every member alike.

    python scripts/libhb_ko.py                draw all 20 -> work/img/hb_ko/<name>.png + _report.json
    python scripts/libhb_ko.py NAME ...       only these textures
    python scripts/libhb_ko.py --explore [G]  every candidate source for every group (or group G)
                                              -> work/img/review/I6_src_<group>[_NN].png
                                              + work/img/hb_ko/_explore.json
The PNGs are already quantised through the ETC1A4 encoder (libtex3ds, what the game shows);
build_hb.py encodes them again into every copy of the texture.
"""
from __future__ import annotations

import json
import sys
import time
import traceback
from pathlib import Path

import numpy as np
from PIL import Image, ImageDraw, ImageFont

sys.path.insert(0, str(Path(__file__).resolve().parent))
from lib3dx import ROOT  # noqa: E402
import imgtext as T  # noqa: E402

OUT = ROOT / "work" / "img" / "hb_ko"
REVIEW = ROOT / "work" / "img" / "review"
CANDIDATES = ["auto", "font", "compose", "ofl"]

GROUPS = {
    # action prompts over the battle (dpunch / punch / fireball / touchpen / ui_fa): 256x32, face 19 px.
    # auto mixes compose / font / ofl here; 빠르게 and 맞받아쳐 exist only as vector letters, so the
    # group is GothicA1 (imgtext picks the weight). compose also gave a cramped 슬. Weight 0.96-1.00.
    "prompt": {"source": "ofl",
               # review round 2: faces 1 px apart made 드! / 치! run together and left the counters of
               # 슬 / 빠 as grey lines; 2 px tracking + 2 px minimum gap while thickening keeps every
               # letter and the ! apart like the kana (weight still 0.95-0.99)
               "kw": {"tracking": 2.0, "gap_min": 2.0},
               "members": ["ja_slide_text", "ja_renzoku_slide_text", "hayaku_slide_text", "ja_kaiten_slide_text",
                           "ja_mukaeute_text", "ja_touch_text", "ja_renda_touch_text"]},
    # rescue menu after a lost giant battle + its own confirm buttons (kyusai.arc; its layouts use no
    # other text texture): 256x32, face 14-15 px. 1DX font at its own size: weight 0.96-0.99, face
    # height 1.06, no verdict problem; ofl came out 19 % taller and relatively thin (0.80 per em);
    # auto took a broken 다 from the bank for 다시 시작.
    "rescue": {"source": "font",
               # review round 2: the ㅗ / ㅡ bars of 모드로 touched; 2 whole pixels of tracking keep the
               # bitmap on its pixel grid and the syllables apart (gap_min 2 deformed 이)
               "kw": {"tracking": 2.0},
               "members": ["ja_yarinaosu_text", "ja_easymode_text", "ja_battleskip_text", "ja_title_text",
                           "ja_kettei_text", "ja_modoru_text"]},
    # yes / no choice (yesno.arc, parts.arc) + the event-skip button (demoskip.arc): 128x64, face 12-14 px.
    # font 예 cannot be thickened past 0.65 of the Japanese stroke (1-px gaps of ㅖ); ofl 0.97.
    "yesno": {"source": "ofl", "members": ["i_ui_demoskip01a", "ja_sentaku_yes", "ja_sentaku_no"]},
    # distance meter (cyorometer.arc, shown together): 64x16 and 64x32, face 8 and 11 px.
    # font_btl looked thinner than the bold originals (white area 0.74 / 0.81 of the original);
    # ofl 0.83 / 1.10 with edge softness closer to the original. Weight: 0.98 / 0.98.
    "meter": {"source": "ofl", "members": ["s_ui_cyorometer_distance", "s_ui_cyorometer_station"]},
    # boss-battle notices, two lines in 128x32 (rotation.arc, start.arc), face 12 px.
    # font_btl 본체를…들어 stopped at 0.86 (counters kept open); ofl 0.94 / 0.90, whiter.
    "boss": {"source": "ofl", "members": ["ja_e_ui_boss_rotation_text", "ja_e_ui_boss_button_text"]},
}
# per-texture render() arguments on top of the group source (documented in work/img/I6.md)
EXTRA: dict[str, dict] = {}


def items() -> dict:
    plan = json.loads((ROOT / "work" / "img" / "hb_plan.json").read_text("utf-8"))
    return {i["name"]: i for i in plan["items"] if i["action"] == "replace" and "dup_of" not in i}


def group_of(name: str) -> str:
    return next(g for g, v in GROUPS.items() if name in v["members"])


def psnr(a: np.ndarray, b: np.ndarray) -> float:
    """PSNR of premultiplied colour + alpha (0..1 floats); transparent pixels do not count."""
    pa = np.concatenate([a[..., :3] * a[..., 3:], a[..., 3:]], -1)
    pb = np.concatenate([b[..., :3] * b[..., 3:], b[..., 3:]], -1)
    mse = float(np.mean((pa - pb) ** 2))
    return 99.0 if mse == 0 else round(10 * np.log10(1.0 / mse), 2)


def edge_stats(rgba: np.ndarray) -> dict:
    """soft = half-transparent pixels per ink pixel (blur of the outer edge);
    grey = mid-grey pixels between the white face and the dark outline per face pixel
    (grey fringes on the white letters). Compared with the same numbers of the original."""
    a = rgba[..., 3]
    v = T.luminance(rgba[..., :3]) * a
    ink = (a >= 0.5).sum()
    face = (v > 0.6).sum()
    ys = np.nonzero((v > 0.55).any(axis=1))[0]
    return {"soft": round(float(((a > 0.1) & (a < 0.9)).sum()) / max(1, ink), 3),
            "grey": round(float(((v > 0.3) & (v <= 0.6)).sum()) / max(1, face), 3),
            "face_rows": int(ys.max() - ys.min() + 1) if len(ys) else 0}


def draw(it: dict, source: str, extra: dict | None = None) -> tuple[np.ndarray, dict]:
    jp = T.load_png(ROOT / it["png"])
    kw = dict(extra or {})
    if source != "auto":
        kw["source"] = source
    t0 = time.time()
    raw, rep = T.redraw(jp, it["ko"], fmt=None, jp_text=it["jp"], **kw)
    ko = T.finalize(raw, it["fmt"])
    st = T.Style.from_json(rep["style"])
    cmp = T.compare(jp, ko, st)
    b = T.measure_style(ko, plate=st.plate or None, lines=len(st.lines) or None)
    info = {
        "ko": it["ko"], "source": source, "kw": kw, "levels": rep.get("levels"), "sources": rep.get("sources"),
        "em": round(float(rep.get("em", 0)), 2), "em_ratio": cmp["summary"]["em_ratio"],
        "weight": rep.get("weight"),
        "final_stroke_px": round(float(b.stroke), 3), "jp_stroke_px": round(float(st.stroke), 3),
        "final_stroke_ratio": round(float(b.stroke) / max(float(st.stroke), 1e-6), 3),
        "psnr_etc": psnr(raw, ko),
        "edges_jp": edge_stats(jp), "edges_ko": edge_stats(ko),
        "fit": rep.get("fit"), "problems": T.verdict(cmp), "summary": cmp["summary"],
        "seconds": round(time.time() - t0, 1),
    }
    return ko, info


# ------------------------------------------------------------------ explore sheets
_FONT = None


def _font():
    global _FONT
    if _FONT is None:
        for cand in (ROOT / "fonts/NotoSansKR-Medium.otf", ROOT / "fonts/NanumSquareRoundB.ttf"):
            if cand.exists():
                _FONT = ImageFont.truetype(str(cand), 12)
                break
    return _FONT


def _on(rgba: np.ndarray, bg, zoom: int) -> Image.Image:
    im = Image.fromarray(T.to_u8(rgba), "RGBA")
    base = Image.new("RGBA", im.size, bg)
    base.alpha_composite(im)
    return base.resize((im.width * zoom, im.height * zoom), Image.NEAREST).convert("RGB")


def row_image(label: str, rgba: np.ndarray, zoom: int = 3) -> Image.Image:
    """label line, then the texture at 1x on blue and at zoom x on grey, side by side."""
    h, w = rgba.shape[:2]
    one = _on(rgba, (58, 110, 170, 255), 1)
    big = _on(rgba, (110, 110, 110, 255), zoom)
    img = Image.new("RGB", (max(w + 8 + w * zoom, 640), 16 + h * zoom), (31, 31, 31))
    ImageDraw.Draw(img).text((2, 1), label, fill=(255, 230, 120), font=_font())
    img.paste(one, (0, 16))
    img.paste(big, (w + 8, 16))
    return img


def _label(src: str, info: dict) -> str:
    w = info.get("weight") or {}
    srcs = " ".join(f"{t}={s}" for line in (info.get("sources") or []) for t, s in line)
    return (f"{src}: {'/'.join(info.get('levels') or [])} | w {w.get('ratio')} fin {info['final_stroke_ratio']}"
            f" em {info['em']} ({info['em_ratio']}) | soft {info['edges_ko']['soft']}/{info['edges_jp']['soft']}"
            f" grey {info['edges_ko']['grey']}/{info['edges_jp']['grey']} | {srcs}")


def explore(groups: list[str]) -> None:
    its = items()
    xp = OUT / "_explore.json"
    data = json.loads(xp.read_text("utf-8")) if xp.exists() else {}
    for g in groups:
        blocks = []
        for name in GROUPS[g]["members"]:
            it = its[name]
            jp = T.load_png(ROOT / it["png"])
            rows = [row_image(f"{name}  original {it['jp']!r}  stroke {T.measure_style(jp).stroke:.2f}px", jp)]
            for src in CANDIDATES:
                try:
                    ko, info = draw(it, src, EXTRA.get(name))
                    data.setdefault(name, {})[src] = info
                    rows.append(row_image(_label(src, info), ko))
                    print(g, name, src, info["levels"], info["weight"] and info["weight"].get("ratio"),
                          info["final_stroke_ratio"], info["psnr_etc"], flush=True)
                except Exception as e:  # record and continue
                    data.setdefault(name, {})[src] = {"error": repr(e), "trace": traceback.format_exc()[-1200:]}
                    print(g, name, src, "ERR", repr(e), flush=True)
            W = max(r.width for r in rows)
            H = sum(r.height + 4 for r in rows)
            blk = Image.new("RGB", (W, H + 6), (31, 31, 31))
            y = 0
            for r in rows:
                blk.paste(r, (0, y))
                y += r.height + 4
            blocks.append(blk)
            xp.write_text(json.dumps(data, ensure_ascii=False, indent=1, default=str), "utf-8")
        for p in T.save_tiled(blocks, REVIEW / f"I6_src_{g}.png"):
            print(p)


# ------------------------------------------------------------------ final drawing
def main(names: list[str]) -> None:
    its = items()
    todo = [n for n in its if not names or n in names]
    OUT.mkdir(parents=True, exist_ok=True)
    rp = OUT / "_report.json"
    report = json.loads(rp.read_text("utf-8")) if rp.exists() and names else {}
    for name in todo:
        g = group_of(name)
        src = GROUPS[g]["source"]
        kw = {**GROUPS[g].get("kw", {}), **EXTRA.get(name, {})}
        try:
            ko, info = draw(its[name], src, kw)
            T.save_png(ko, OUT / f"{name}.png")
            info["group"] = g
            report[name] = info
            print(name, g, src, info["levels"], info["weight"] and info["weight"].get("ratio"),
                  info["final_stroke_ratio"], info["psnr_etc"], info["problems"], flush=True)
        except Exception as e:  # keep going, record the failure
            report[name] = {"ko": its[name]["ko"], "group": g, "error": repr(e), "trace": traceback.format_exc()[-1500:]}
            print(name, "ERR", repr(e), flush=True)
        rp.write_text(json.dumps(report, ensure_ascii=False, indent=1, default=str), "utf-8")


if __name__ == "__main__":
    args = sys.argv[1:]
    if args and args[0] == "--explore":
        explore(args[1:] or list(GROUPS))
    else:
        main(args)
