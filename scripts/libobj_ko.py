"""Korean Obj/JP sprites: job list + generator.

    python scripts/libobj_ko.py            # write work/img/obj_ko/<dat>/<object>/<region>.png + plan status
    python scripts/libobj_ko.py --review   # also write before/after sheets work/img/review/I3_*.png

A job fills some parts of one 3DX frame with a target image:
  donor : render a 1DX Korean frame (optionally only some of its parts), align it on the frame
          origin (the sprite anchor; optional dx/dy), and use it as the target
  png   : a finished RGBA target in 3DX frame coordinates (made by imgtext etc.)
  mode "frame" = the target is the whole frame -> every part of the frame is re-derived;
  mode "text"  = only the listed 3DX parts (region keys) are re-derived, the rest are untouched.
The target is cut into a non-overlapping cover of the chosen parts; chosen parts outside the
cover become transparent. The result is re-rendered and compared with the target.
"""

from __future__ import annotations

import argparse
import json
import sys
from pathlib import Path

import numpy as np
from PIL import Image

sys.path.insert(0, str(Path(__file__).resolve().parent))
import libobj  # noqa: E402

ROOT = libobj.ROOT
OUT = ROOT / "work" / "img" / "obj_ko"
REVIEW = ROOT / "work" / "img" / "review"
PLAN = ROOT / "work" / "img" / "obj_plan.json"
REVIEW_PREFIX = "I3_"

_dats: dict = {}


def dat(game: str, name: str) -> libobj.ObjDat:
    if (game, name) not in _dats:
        _dats[game, name] = libobj.ObjDat(game, name)
    return _dats[game, name]


def obj_frame(game, d, obj, fi):
    od = dat(game, d)
    o = od.objs[obj]
    af = od.anim(o.anim)
    return od, o, af, af.frames[fi]


def render_layer(af, graph, fr, keys=None) -> tuple[np.ndarray, tuple[int, int]]:
    """Composite of the frame's parts (all, or only those whose region key is in `keys`)."""
    lay, (w, h), origin = libobj.frame_layout(af, fr)
    out = np.zeros((h, w, 4), np.float32)
    for p, x0, y0 in reversed(lay):
        if keys is not None and libobj.region_key(p) not in keys:
            continue
        t = libobj.part_rgba(af, graph, p).astype(np.float32)
        pw, ph = p.size
        dst = out[y0:y0 + ph, x0:x0 + pw]
        sa, da = t[..., 3:4] / 255, dst[..., 3:4] / 255
        a = sa + da * (1 - sa)
        rgb = (t[..., :3] * sa + dst[..., :3] * da * (1 - sa)) / np.maximum(a, 1e-3)
        dst[..., :3] = np.where(a < 1e-3, t[..., :3], rgb)
        dst[..., 3:4] = a * 255
    return np.clip(out + 0.5, 0, 255).astype(np.uint8), origin


def place(src, src_origin, size, origin, dx=0, dy=0) -> np.ndarray:
    w, h = size
    out = np.zeros((h, w, 4), np.uint8)
    ox, oy = origin[0] - src_origin[0] + dx, origin[1] - src_origin[1] + dy
    sh, sw = src.shape[:2]
    x0, y0, x1, y1 = max(0, ox), max(0, oy), min(w, ox + sw), min(h, oy + sh)
    if x1 > x0 and y1 > y0:
        out[y0:y1, x0:x1] = src[y0 - oy:y1 - oy, x0 - ox:x1 - ox]
    lost = src[..., 3].sum() - out[..., 3].sum()
    if lost > 255 * 2:
        raise ValueError(f"donor does not fit the frame ({lost / 255:.0f} alpha px lost)")
    return out


def decompose(af, fr, target, keys=None) -> dict[str, np.ndarray]:
    """target (frame coords) -> {region key: storage-orientation RGBA} for the chosen parts."""
    lay, (w, h), _o = libobj.frame_layout(af, fr)
    chosen = [(p, x, y) for p, x, y in lay if keys is None or libobj.region_key(p) in keys]
    inst: dict[str, int] = {}
    for p, _x, _y in chosen:
        inst[libobj.region_key(p)] = inst.get(libobj.region_key(p), 0) + 1
    # greedy cover: big parts first, single-instance regions first, no overlap
    order = sorted(chosen, key=lambda t: (inst[libobj.region_key(t[0])] > 1, -t[0].size[0] * t[0].size[1], t[2], t[1]))
    cover, taken = [], np.zeros((h, w), bool)
    for p, x, y in order:
        pw, ph = p.size
        if taken[y:y + ph, x:x + pw].any():
            continue
        cover.append((p, x, y))
        taken[y:y + ph, x:x + pw] = True
    ckeys = {libobj.region_key(p) for p, _x, _y in cover}
    if len(ckeys) != len(cover):
        raise ValueError("cover uses one region twice")
    out = {}
    for p, x, y in chosen:
        k = libobj.region_key(p)
        pw, ph = p.size
        if k in ckeys and (p, x, y) in cover:
            img = target[y:y + ph, x:x + pw].copy()
            hf, vf = p.flip
            if hf:
                img = img[:, ::-1]
            if vf:
                img = img[::-1]
            out[k] = np.ascontiguousarray(img)
        elif k not in ckeys:
            out[k] = np.zeros((ph, pw, 4), np.uint8)
    uncovered = (target[..., 3] > 0) & ~taken
    if uncovered.any():
        raise ValueError(f"{uncovered.sum()} target pixels are outside the chosen parts")
    return out


def quantize(img, fmt):
    return libobj.libtex3ds.decode(libobj.libtex3ds.encode(img, fmt, flip=False), fmt,
                                   img.shape[1], img.shape[0], flip=False)


def apply_regions(od, o, regions: dict[str, np.ndarray]) -> bytes:
    """Graph buffer of object o with the regions replaced (for previews)."""
    af = od.anim(o.anim)
    buf = bytearray(od.plain(o.graph))
    seen = {}
    for p in af.parts:
        seen.setdefault(libobj.region_key(p), p)
    for k, img in regions.items():
        p = seen[k]
        enc = libobj.part_encode(af, p, img, undo_flip=False)
        buf[128 * p.buf:128 * p.buf + len(enc)] = enc
    return bytes(buf)


# ------------------------------------------------------------------ jobs
def J(d, obj, frames, donor=None, mode="frame", keys=None, dkeys=None, dx=0, dy=0, png=None, note=""):
    return dict(dat=d, obj=obj, frames=frames, donor=donor, mode=mode, keys=keys, dkeys=dkeys,
                dx=dx, dy=dy, png=png, note=note)


def text_keys(game, d, obj, fi, sizes=((64, 32),), ys=None):
    _od, _o, af, fr = obj_frame(game, d, obj, fi)
    lay, _s, _org = libobj.frame_layout(af, fr)
    return {libobj.region_key(p) for p, x, y in lay if p.size in sizes and (ys is None or y in ys)}


# ------------------------------------------------------------------ pixel-built targets (fn jobs)
def FJ(d, obj, frames, fn, keys=None, note=""):
    """Job whose target is computed by fn(od, o, af, fr, fi) -> RGBA in 3DX frame coordinates."""
    return dict(dat=d, obj=obj, frames=frames, donor=None, mode="text" if keys else "frame", keys=keys,
                dkeys=None, dx=0, dy=0, png=None, note=note, fn=fn)


OUTLINE_1DX = (51, 34, 17)          # dark-brown outline of the 1DX Korean UI sprites
OUTLINE_3DX = (17, 17, 17)          # near-black outline of the 3DX sprites
TUTO_TINT = 68 / 255                # 3DX bui_tuto f0 -> f1: face (v, v, v) -> (v, v, v * 68/255)
# Lead 2026-09-30: a region copied from a 1DX sprite keeps the 1DX letter shapes but takes the
# colours of the 3DX original. Both games shade the face with the same greys; only the outline
# brown and its two dark blends with the face differ, and each maps to the 3DX colour of the same
# role (68,51,51 = brown + grey 85 half and half -> 51; 85,85,68 = brown + grey 119 -> 68).
PALETTE_1DX_3DX = {OUTLINE_1DX: OUTLINE_3DX, (68, 51, 51): (51, 51, 51), (85, 85, 68): (68, 68, 68)}
LUMA = np.array([0.299, 0.587, 0.114])


def to_3dx_colours(img: np.ndarray, jp: np.ndarray | None = None) -> np.ndarray:
    """1DX donor copy (RGBA, frame coordinates) -> the colours of the 3DX original `jp`.
    RGB: PALETTE_1DX_3DX; every other colour must be one of the shared greys (at most one 4-bit
    step off neutral). Alpha: where the original draws its outline half transparent (bui_tuto
    おてほん: outline alpha 170, face/outline blends 187-238, one alpha per colour) its colour ->
    alpha rule is applied (interpolated over luminance for greys it does not use, the outline's
    anti-aliased fringe scaled by the same factor); elsewhere the 1DX alpha stays."""
    from collections import Counter, defaultdict
    out = img.copy()
    vis = out[..., 3] > 0
    for src, dst in PALETTE_1DX_3DX.items():
        out[vis & np.all(out[..., :3] == np.array(src, np.uint8), axis=-1), :3] = dst
    rest = out[vis, :3].astype(int)
    off = rest.max(1) - rest.min(1) > 17
    if off.any():
        raise ValueError(f"1DX colours outside the shared greys: {sorted({tuple(c) for c in rest[off].tolist()})[:6]}")
    if jp is None:
        return out
    jv = jp[..., 3] > 0
    jo = jv & np.all(jp[..., :3] == np.array(OUTLINE_3DX, np.uint8), axis=-1)
    a_out = int(jp[jo, 3].max()) if jo.any() else 255
    if a_out == 255:
        return out
    votes = defaultdict(Counter)
    for (r, g, b, a) in jp[jv & ~jo].tolist():
        votes[(r, g, b)][a] += 1
    pts: dict[float, list] = {float(np.array(OUTLINE_3DX) @ LUMA): [a_out]}
    for c, v in votes.items():
        pts.setdefault(float(np.array(c) @ LUMA), []).append(v.most_common(1)[0][0])
    xs = np.array(sorted(pts))
    ys = np.array([np.mean(pts[x]) for x in xs])
    lum = out[..., :3].astype(np.float64) @ LUMA
    a = out[..., 3].astype(np.float64) * np.interp(lum, xs, ys) / 255
    out[..., 3] = np.where(vis, np.clip(17 * np.rint(a / 17), 17, 255), 0).astype(np.uint8)
    return out


def donor_copy(j, od, o, af, fr, size, origin) -> np.ndarray:
    """Target of a 1DX donor job: the 1DX frame (or its listed parts) placed on the 3DX frame
    origin, in the colours of the 3DX original (to_3dx_colours)."""
    gd, gobj, gf = j["donor"]
    dod, do, daf, dfr = obj_frame("1DX", gd, gobj, gf)
    src, sorg = render_layer(daf, dod.plain(do.graph), dfr, j["dkeys"])
    jp, _org = render_layer(af, od.plain(o.graph), fr, set(j["keys"]) if j["mode"] == "text" else None)
    return to_3dx_colours(place(src, sorg, size, origin, j["dx"], j["dy"]), jp)


def _tint_yellow(img: np.ndarray, outline=OUTLINE_1DX) -> np.ndarray:
    out = img.copy()
    face = (out[..., 3] > 0) & ~np.all(out[..., :3] == np.array(outline, np.uint8), axis=-1)
    out[face, 2] = np.clip(17 * np.rint(out[face, 2] * TUTO_TINT / 17), 0, 255).astype(np.uint8)
    return out


def _check_tuto_tint() -> float:
    """Share of 3DX f1 face pixels the tint rule reproduces from 3DX f0 (must stay high)."""
    od, o, af, fr0 = obj_frame("3DX", "BUI", "bui_tuto_JP_ja", 0)
    fr1 = af.frames[1]
    g = od.plain(o.graph)
    a0, a1 = libobj.render_frame(af, g, fr0), libobj.render_frame(af, g, fr1)
    t = _tint_yellow(a0, outline=(17, 17, 17))
    face = (a0[..., 3] > 0) & ~np.all(a0[..., :3] == 17, axis=-1)
    return float((np.abs(t[face, :3].astype(int) - a1[face, :3].astype(int)).max(-1) <= 17).mean())


def tuto_highlight(od, o, af, fr, fi):
    """bui_tuto f1 (highlighted おてほん): the same 1DX 「시범」 as the f0 copy, same size, place
    and 3DX colours, face tinted yellow the way 3DX turns f0 into f1; outline unchanged."""
    ok = _check_tuto_tint()
    if ok < 0.9:
        raise ValueError(f"tint rule reproduces only {ok:.0%} of the 3DX f1 face")
    lay, size, origin = libobj.frame_layout(af, fr)
    dod, do, daf, dfr = obj_frame("1DX", "BUI", "bui_tuto_KR_ko", 0)
    src, sorg = render_layer(daf, dod.plain(do.graph), dfr)
    jp0 = libobj.render_frame(af, od.plain(o.graph), af.frames[0])
    return _tint_yellow(to_3dx_colours(place(src, sorg, size, origin), jp0), outline=OUTLINE_3DX)


GDH_KEY3, GDH_KEY1 = "b00276_64x32", "b00244_64x32"      # the GDD / GDH text parts


def gdh_text(od, o, af, fr, fi):
    """ko_ui_statname GDD -> GDH. Left of the first column where the 3DX GDD and the 1DX GDH text
    parts differ (G, D and most of the outline) the 3DX pixels stay; from there on the 1DX H is
    used, recoloured with the 1DX -> 3DX colour map learned on the G and D both sprites share
    (1DX draws the outline dark brown, 3DX near-black; the face greys are the same)."""
    from collections import Counter, defaultdict
    t3, org3 = render_layer(af, od.plain(o.graph), fr, {GDH_KEY3})
    od1, o1, af1, fr1 = obj_frame("1DX", "KUI", "ko_ui_statname_KR_ko", fi)
    t1, org1 = render_layer(af1, od1.plain(o1.graph), fr1, {GDH_KEY1})
    t1 = place(t1, org1, (t3.shape[1], t3.shape[0]), org3)
    diff = (t3[..., 3] != t1[..., 3]).any(0)
    split = int(np.nonzero(diff)[0].min())
    votes = defaultdict(Counter)
    both = (t3[:, :split, 3] > 0) & (t1[:, :split, 3] > 0)
    for a, b in zip(t1[:, :split][both], t3[:, :split][both]):
        votes[tuple(int(v) for v in a[:3])][tuple(int(v) for v in b[:3])] += 1
    cmap = {k: v.most_common(1)[0][0] for k, v in votes.items()}
    keys = np.array(list(cmap), float)
    out = t3.copy()
    out[:, split:] = 0
    right = t1[:, split:].copy()
    vis = right[..., 3] > 0
    for y, x in zip(*np.nonzero(vis)):
        c = tuple(int(v) for v in right[y, x, :3])
        if c not in cmap:        # nearest colour of the shared letters
            c = tuple(int(v) for v in keys[np.argmin(((keys - np.array(c)) ** 2).sum(1))])
        right[y, x, :3] = cmap[c]
    out[:, split:] = right
    return out


def jobs() -> list[dict]:
    B, K = "BUI", "KUI"
    js = []
    # bui_sys_badstatname: text parts are the 64x32 ones (icons untouched).
    # f0 ころび -> 1DX 「꽈당」 (lead 2026-09-30: the official 1DX word wins over our coined 넘어짐)
    for f3, f1 in ((0, 0), (1, 1), (2, 2), (10, 10)):
        js.append(J(B, "bui_sys_badstatname_JP_ja", [f3], ("BUI", "bui_sys_badstatname_KR_ko", f1), "text",
                    text_keys("3DX", B, "bui_sys_badstatname_JP_ja", f3),
                    text_keys("1DX", B, "bui_sys_badstatname_KR_ko", f1)))
    # bui_sys_block_name: whole frame is the word
    for f3, f1 in ((0, 0), (1, 1), (3, 4), (4, 5)):
        js.append(J(B, "bui_sys_block_name_JP_ja", [f3], ("BUI", "bui_sys_block_name_KR_ko", f1)))
    js.append(J(B, "bui_tuto_JP_ja", [0], ("BUI", "bui_tuto_KR_ko", 0)))
    # f1 = highlighted 「おてほん」 (yellow): the f0 copy with the 3DX f0 -> f1 face tint
    js.append(FJ(B, "bui_tuto_JP_ja", [1], tuto_highlight, None, "1DX 시범 (f0 copy) + 3DX f1 yellow face"))
    js.append(J(K, "ko_ui_jump_JP_ja", [0], ("KUI", "ko_ui_jump_KR_ko", 0)))
    # ko_ui_statname: めいちゅう/かいひ
    for f3 in (8, 9, 10, 11):
        js.append(J(K, "ko_ui_statname_JP_ja", [f3], ("KUI", "ko_ui_statname_KR_ko", f3), "text",
                    text_keys("3DX", K, "ko_ui_statname_JP_ja", f3),
                    text_keys("1DX", K, "ko_ui_statname_KR_ko", f3)))
    # ko_ui_statname: GDD -> GDH (lead 22:05; dialogue and KJ_ST_GDD say GDH): 3DX G, D + the H of
    # the 1DX GDH sprite (same pixel font) recoloured to the 3DX palette
    for f3 in (6, 7):
        js.append(FJ(K, "ko_ui_statname_JP_ja", [f3], gdh_text, {GDH_KEY3}, "3DX G·D + 1DX H"))
    # ko_ui_fukubikiblock: labels under the icons (two 64x32 parts at the bottom)
    for f3, f1 in ((13, 10), (14, 11), (15, 12), (16, 13), (23, 20), (24, 21), (25, 22), (26, 19)):
        ys3 = {48}
        js.append(J(K, "ko_ui_fukubikiblock_JP_ja", [f3], ("KUI", "ko_ui_fukubikiblock_KR_ko", f1), "text",
                    text_keys("3DX", K, "ko_ui_fukubikiblock_JP_ja", f3, ys=ys3),
                    text_keys("1DX", K, "ko_ui_fukubikiblock_KR_ko", f1, ys=ys3)))
    if DRAW:
        js += draw_jobs()
    return js


READY = ROOT / "work" / "img" / "toolkit" / "READY"
DRAW = READY.exists() or "--try-draw" in sys.argv


def draw_jobs() -> list[dict]:
    """Sprites with no 1DX twin of the same look: imgtext (I2) draws them. See obj_plan.json."""
    B, F, K, M = "BUI", "FUI", "KUI", "Menu"
    js = []
    # battle: score gauge title
    js.append(DJ(B, "bui_score_JP_ja", [11], "콜레미터", {"b00224_32x16", "b00232_32x16", "b00240_32x16"}))
    # bad-status names (text = the 64x32 part right of the icon); f0 ころび = 1DX 「꽈당」 copy (jobs()).
    # weight = stroke to reach (px), set where the default overshot the Japanese stroke by > 10 %;
    # 필살: source pinned to the 1DX font like 감기·분노 (1.3 auto would switch it to the vector font)
    for f, t, kw in ((3, "감기", {}), (11, "분노", {"weight": 1.62}), (12, "필살", {"weight": 1.55, "source": "font"})):
        js.append(DJ(B, "bui_sys_badstatname_JP_ja", [f], t,
                     text_keys("3DX", B, "bui_sys_badstatname_JP_ja", f), **kw))
    # command block names (whole frame is the word): face height, stroke and decoration of the 1DX
    # names copied into the same family (점프·해머·아이템·도망가기), see block_family()
    for f, t in ((2, "스페셜 어택"), (5, "펀치"), (6, "파이어"), (7, "스페셜 어택"), (9, "배큐엄"), (10, "가이드"),
                 (11, "힌트")):
        js.append(DJ(B, "bui_sys_block_name_JP_ja", [f], t, None, family="block"))
    # battle-guide buttons: letters of the same 1DX button, decoration of the 3DX one
    btn = "bui_sys_button_JP_ja"

    def bdon(fi, w, thr=None):
        return [("1DX", "BUI", "bui_sys_button_KR_ko", fi,
                 [k for k in text_keys("1DX", "BUI", "bui_sys_button_KR_ko", fi, sizes=((32, 16), (64, 32)))],
                 None, w, thr)]
    js.append(DJ(B, btn, [0, 1], "뒤로", {"b00000_64x32", "b00032_64x32"}, donors=bdon(0, "뒤로")))
    # 1DX 「이지 모드」 is yellow on a dark arc; imgtext cuts it into the wrong pieces -> font letters
    js.append(DJ(B, btn, [2], "이지 모드", {"b00452_64x32", "b00484_64x32"}))
    js.append(DJ(B, btn, [3, 4], "긴급 가드", {"b00160_64x32", "b00192_64x32"}, donors=bdon(3, "긴급 가드")))
    js.append(DJ(B, btn, [5], "난이도", {"b00260_64x32", "b00292_64x32"}, donors=bdon(5, "난이도", 150)))
    # 1DX 보통/쉬움 sprites (flat letters, like the 3DX ones). The 1DX 보통 is spaced wide: -3 px brings
    # the gap between its syllables to 쉬움's (no empty column between the two syllables)
    js.append(DJ(B, btn, [6], "보통", None, donors=bdon(6, "보통", 0), tracking=-3.0))
    js.append(DJ(B, btn, [7], "보통", None, donors=bdon(7, "보통", 0), tracking=-3.0))
    js.append(DJ(B, btn, [8], "쉬움", None, donors=bdon(8, "쉬움", 0), tracking=-1.0))
    js.append(DJ(B, btn, [9], "쉬움", None, donors=bdon(9, "쉬움", 0), tracking=-1.0))
    k10 = {"b00096_32x16", "b00104_32x16", "b00112_32x16", "b00120_32x16"}
    k12 = {"b00224_32x16", "b00232_32x16", "b00240_32x16", "b00248_32x16"}
    js.append(DJ(B, btn, [10, 11], "연습 모드", k10, donors=bdon(10, "연습 모드")))
    js.append(DJ(B, btn, [12, 13], "시범 모드", k12, donors=bdon(12, "시범 모드")))
    k14 = {"b00548_32x16", "b00556_32x16", "b00564_32x16", "b00572_32x16"}
    k16 = {"b00708_32x16", "b00716_32x16", "b00724_32x16", "b00732_32x16"}
    js.append(DJ(B, btn, [14, 15, 18, 19], "시범", k14, donors=bdon(12, "시범 모드")))
    js.append(DJ(B, btn, [16, 17, 20], "연습", k16, donors=bdon(10, "연습 모드")))
    # "take out the stylus" under the START button (same picture in three dats)
    kt = {"b01024_64x32", "b01088_64x32", "b01152_64x32"}
    for d, o in ((B, "bui_touch_start_JP_ja"), (F, "fui_touch_start_JP_ja"), (M, "m_touch_start_JP_ja")):
        js.append(DJ(d, o, [0, 1, 2, 3, 4], "터치펜을\n꺼내 주세요", kt))
    # "hold the system upright"
    for d, o in ((F, "fui_bodyrot_JP_ja"), (M, "m_bodyrot_JP_ja")):
        js.append(DJ(d, o, [0], "본체를 세로로\n바꿔 들어 주세요", None, weight=1.78))
    # Bowser Jr. RPG small labels
    js.append(DJ(K, "ko_ui_change_JP_ja", [0], "전환", None))
    js.append(DJ(K, "ko_ui_return_JP_ja", [0], "되돌리기", None))
    js.append(DJ(K, "ko_ui_onemore_JP_ja", [0], "결정", None))
    js.append(DJ(K, "ko_ui_onemore_JP_ja", [1], "다시 한번", None))
    # 「あと」 is a crisp white label (40 % of its ink opaque); the plain redraw came out soft (22 %):
    # alpha contrast + pixel phase like lyt_D.py (57 %, stroke 1.01x of the kana, lead 2026-09-30)
    js.append(DJ(K, "ko_ui_special_JP_ja", [11], "앞으로", None, source="font", sharp=1.5))
    return js


# ------------------------------------------------------------------ imgtext (I2 toolkit) jobs
_DRAW_CACHE: dict = {}
DRAW_REPORT: dict = {}


def DJ(d, obj, frames, text, keys=None, area=None, donors=None, note="", family=None, **kw):
    """Redraw the Japanese text of a frame in Korean with imgtext.
    keys   = region keys of the text parts (None = every part of the frame is text)
    area   = (x0, y0, x1, y1) frame crop handed to imgtext (default: union of the text parts)
    donors = [("1DX", dat, obj, frame, dkeys|None, crop|None, "word shown"), ...] letter shapes
    family = "block": size, stroke, decoration and width limit shared with the 1DX copies of the
             same family (block_family())
    kw     = extra arguments for imgtext.redraw()"""
    return dict(dat=d, obj=obj, frames=frames, donor=None, mode="text" if keys else "frame", keys=keys,
                dkeys=None, dx=0, dy=0, png=None, note=note,
                draw=dict(text=text, area=area, donors=donors or [], kw=kw, family=family))


_BLOCK_FAMILY: dict = {}
BLOCK_COPIES = (0, 1, 4, 5)          # 1DX bui_sys_block_name_KR_ko 점프, 해머, 아이템, 도망가기 (copied as is)
BLOCK_TEXT_FRAMES = (0, 1, 2, 3, 4, 5, 6, 7, 9, 10, 11)     # 3DX frames with a name (f8 = empty bar)


def block_family() -> dict:
    """Target of the redrawn command-block names (lead 2026-09-30: same size and weight as the
    1DX copies): median face height and stroke of the 1DX copies, the decoration of 점프 (white
    face, 2 px outline, the look all 1DX block names share) in the 3DX colours the copies take
    (to_3dx_colours: near-black outline), and the widest Japanese face box of the family as the
    width a name may take (wider -> horizontal scale >= 80 %). Size and stroke are measured on
    the 1DX pixels as approved (the recoloured outline shifts the stroke measure by 2 %)."""
    import imgtext as T
    if not _BLOCK_FAMILY:
        sts, deco = [], None
        for fi in BLOCK_COPIES:
            od, o, af, fr = obj_frame("1DX", "BUI", "bui_sys_block_name_KR_ko", fi)
            img = libobj.render_frame(af, od.plain(o.graph), fr)
            sts.append(T.measure_style(img.astype(np.float64) / 255))
            if deco is None:
                deco = T.measure_style(to_3dx_colours(img).astype(np.float64) / 255)
        od, o, af, _fr = obj_frame("3DX", "BUI", "bui_sys_block_name_JP_ja", 0)
        g = od.plain(o.graph)
        bx = [T.measure_style(libobj.render_frame(af, g, af.frames[fi]).astype(np.float64) / 255).box
              for fi in BLOCK_TEXT_FRAMES]
        _BLOCK_FAMILY.update(em=float(np.median([s.em for s in sts])),
                             stroke=float(np.median([s.stroke for s in sts])), deco=deco,
                             x=(min(b[0] for b in bx), max(b[2] for b in bx)),
                             copies={fi: (s.em, round(s.stroke, 3)) for fi, s in zip(BLOCK_COPIES, sts)})
    return _BLOCK_FAMILY


def _part_union(af, fr, keys):
    lay, (w, h), _o = libobj.frame_layout(af, fr)
    xs0, ys0, xs1, ys1 = [], [], [], []
    for p, x, y in lay:
        if keys is None or libobj.region_key(p) in keys:
            xs0.append(x), ys0.append(y), xs1.append(x + p.size[0]), ys1.append(y + p.size[1])
    return min(xs0), min(ys0), max(xs1), max(ys1)


def donor_rgba(spec) -> np.ndarray:
    """spec = (game, dat, obj, frame, keys|None, crop|None, word[, luminance threshold]).
    With a threshold only pixels brighter than it stay opaque: lifts light letters off the dark
    bar / wooden plank the 1DX button draws behind them."""
    game, d, obj, fi, keys, crop = spec[:6]
    od, o, af, fr = obj_frame(game, d, obj, fi)
    img, _org = render_layer(af, od.plain(o.graph), fr, set(keys) if keys else None)
    if crop:
        x0, y0, x1, y1 = crop
        img = img[y0:y1, x0:x1]
    img = img.astype(np.float64) / 255
    if len(spec) > 7 and spec[7]:
        lum = img[..., :3] @ np.array([0.299, 0.587, 0.114])
        img = img.copy()
        img[..., 3] *= np.clip((lum * 255 - spec[7]) / 24 + 0.5, 0, 1)
    return img


PHASE_DY = (-0.5, -0.25, 0.0, 0.25, 0.5)
PHASE_DX = (0.0, 0.25, 0.5, 0.75)


def crisp_redraw(jp: np.ndarray, text: str, fmt: str, gain: float, **kw):
    """White label without outline drawn crisp (lyt_D.py's method, work/img/D.md): imgtext render
    at quarter-pixel phases, alpha contrast x gain around 0.5, the phase with the least
    half-transparent ink kept."""
    import copy
    import imgtext as T
    st = T.measure_style(jp)
    if st.layers or st.shadow or min(min(c) for _t, c in st.face_stops) < 0.9:
        raise ValueError("crisp_redraw is for white labels without outline or shadow")
    best = None
    for dy in PHASE_DY:
        for dx in PHASE_DX:
            st2 = copy.deepcopy(st)
            st2.box = (st.box[0] + dx, st.box[1] + dy, st.box[2] + dx, st.box[3] + dy)
            st2.lines = [(a + dy, b + dy) for a, b in st.lines]
            rep = {"style": st.to_json(), "fmt": fmt}
            k = T.bleed(T.render(text, st2, report=rep, **kw))
            k[..., :3] = 1.0
            k[..., 3] = np.clip((k[..., 3] - 0.5) * gain + 0.5, 0, 1)
            k = T.finalize(k, fmt)
            a = k[..., 3]
            m = float((a * (1 - a))[a > 0.02].mean())
            if best is None or m < best[0] - 1e-9:
                best = (m, k, rep, dx, dy)
    m, k, rep, dx, dy = best
    rep.update(sharp=gain, phase=(dx, dy, round(m, 4)))
    rep["compare"] = T.compare(jp, k, st)
    rep["problems"] = T.verdict(rep["compare"])
    return k, rep


def draw_target(od, o, af, fr, j) -> np.ndarray:
    import imgtext as T
    d = j["draw"]
    keys = set(j["keys"]) if j["keys"] else None
    layer, _org = render_layer(af, od.plain(o.graph), fr, keys)
    h, w = layer.shape[:2]
    x0, y0, x1, y1 = d["area"] or _part_union(af, fr, keys)
    jp8 = layer[y0:y1, x0:x1]
    ck = (j["obj"], d["text"], (x0, y0, x1, y1), jp8.tobytes(), repr(sorted(d["kw"].items())), repr(d["donors"]),
          d.get("family"))
    if ck not in _DRAW_CACHE:
        kw = dict(d["kw"])
        # IMAGE_TASK.md 1: one letter source per word -> a donor image is used only when it
        # holds every syllable of the word
        need = set(d["text"]) - set(" \n")
        dons = [s for s in d["donors"] if need <= set(s[6])]
        if dons:
            kw["donors"] = [(donor_rgba(s), s[6]) for s in dons]
        if d.get("family") == "block":
            import dataclasses
            fam = block_family()
            sj = T.measure_style(jp8.astype(np.float64) / 255)
            kw["style"] = dataclasses.replace(sj, face_stops=fam["deco"].face_stops, layers=fam["deco"].layers,
                                              shadow=fam["deco"].shadow)
            kw.setdefault("em", fam["em"])
            kw.setdefault("weight", fam["stroke"])
            kw.setdefault("box", (fam["x"][0] - x0, 0, fam["x"][1] - x0, y1 - y0))
        gain = kw.pop("sharp", None)
        if gain:
            ko, rep = crisp_redraw(jp8.astype(np.float64) / 255, d["text"], af.fmt, gain, **kw)
        else:
            ko, rep = T.redraw(jp8.astype(np.float64) / 255, d["text"], fmt=af.fmt, **kw)
        _DRAW_CACHE[ck] = T.to_u8(ko)
        DRAW_REPORT[f"{j['dat']}/{j['obj']}/{d['text']}"] = rep
    target = np.zeros((h, w, 4), np.uint8)
    target[y0:y1, x0:x1] = _DRAW_CACHE[ck]
    return target


def run_job(j) -> dict:
    """-> {region key: img} for this job, plus preview info."""
    od, o, af, _ = obj_frame("3DX", j["dat"], j["obj"], j["frames"][0])
    res: dict[str, np.ndarray] = {}
    for fi in j["frames"]:
        fr = af.frames[fi]
        lay, size, origin = libobj.frame_layout(af, fr)
        if j.get("fn"):
            target = j["fn"](od, o, af, fr, fi)
        elif j.get("draw"):
            target = draw_target(od, o, af, fr, j)
        elif j["png"]:
            target = np.array(Image.open(ROOT / j["png"]).convert("RGBA"))
        else:
            target = donor_copy(j, od, o, af, fr, size, origin)
        keys = j["keys"] if j["mode"] == "text" else None
        regs = decompose(af, fr, target, keys)
        for k, img in regs.items():
            if k in res and not np.array_equal(res[k], img):
                raise ValueError(f"{j['obj']} {k}: two frames of one job disagree")
            res[k] = img
    return res


def main() -> None:
    global OUT, REVIEW_PREFIX
    ap = argparse.ArgumentParser()
    ap.add_argument("--review", action="store_true")
    ap.add_argument("--try-draw", action="store_true",
                    help="run the imgtext jobs before toolkit/READY exists: output goes to "
                         "$KIROCREW_SCRATCH/obj_ko_try and review sheets to I3_try_*, never to obj_ko")
    a = ap.parse_args()
    if a.try_draw and not READY.exists():
        import os
        OUT = Path(os.environ.get("KIROCREW_SCRATCH", ROOT / "work" / "tmp")) / "obj_ko_try"
        REVIEW_PREFIX = "I3_try_"
    per_obj: dict[tuple, dict] = {}
    log = []
    for j in jobs():
        regs = run_job(j)
        cur = per_obj.setdefault((j["dat"], j["obj"]), {})
        for k, img in regs.items():
            if k in cur and not np.array_equal(cur[k], img):
                raise ValueError(f"{j['obj']} {k}: jobs disagree (frames {j['frames']})")
            cur[k] = img
        log.append({"dat": j["dat"], "obj": j["obj"], "frames": j["frames"], "regions": sorted(regs),
                    "donor": j["donor"], "png": j["png"], "mode": j["mode"],
                    "text": (j.get("draw") or {}).get("text"),
                    "fn": j["fn"].__name__ if j.get("fn") else None, "note": j.get("note") or None})
    for (d, obj), regs in per_obj.items():
        base = OUT / d / obj
        base.mkdir(parents=True, exist_ok=True)
        for old in base.glob("*.png"):
            old.unlink()
        for k, img in regs.items():
            Image.fromarray(img, "RGBA").save(base / f"{k}.png")
    (OUT / "_jobs.json").write_text(json.dumps(log, ensure_ascii=False, indent=1), "utf-8")
    if DRAW_REPORT:
        if _BLOCK_FAMILY:
            DRAW_REPORT["_block_family"] = {k: v for k, v in _BLOCK_FAMILY.items() if k != "deco"}
        (OUT / "_imgtext_report.json").write_text(json.dumps(DRAW_REPORT, ensure_ascii=False, indent=1,
                                                             default=str), "utf-8")
    print(len(log), "jobs,", sum(len(r) for r in per_obj.values()), "regions,", len(per_obj), "objects")
    if a.review:
        review(per_obj, log)


# ------------------------------------------------------------------ review sheets
def review(per_obj, log) -> None:
    """orig | Korean sheets. The Korean side is read back from the staged build
    (work/build/obj_stage/romfs/Obj/JP/<dat>.dat) when it exists and holds these regions,
    otherwise it is previewed from the regions in memory."""
    stage = ROOT / "work" / "build" / "obj_stage" / "romfs" / "Obj" / "JP"
    rows = {}
    for (d, obj), regs in per_obj.items():
        od = dat("3DX", d)
        o = od.objs[obj]
        af = od.anim(o.anim)
        g0 = od.plain(o.graph)
        g1 = apply_regions(od, o, {k: quantize(v, af.fmt) for k, v in regs.items()})
        sp = stage / f"{d}.dat"
        src = "preview"
        if sp.exists() and OUT == ROOT / "work" / "img" / "obj_ko":
            gs = libobj.ObjDat("3DX", d, sp.read_bytes()).plain(o.graph)
            if gs == g1:
                g1, src = gs, "stage"
        frames = sorted({f for e in log if e["obj"] == obj for f in e["frames"]})
        for fi in frames:
            fr = af.frames[fi]
            a0 = libobj.render_frame(af, g0, fr)
            a1 = libobj.render_frame(af, g1, fr)
            rows.setdefault(d, []).append((f"{obj}/f{fi:03d} [{src}]", a0, a1))
    for d, rs in rows.items():
        sheet(rs, REVIEW / f"{REVIEW_PREFIX}{d}.png")


def _checker(h, w, s=4):
    y, x = np.mgrid[0:h, 0:w]
    c = np.where(((x // s) + (y // s)) % 2, 150, 110).astype(np.uint8)
    return np.dstack([c, c, c, np.full_like(c, 255)])


def _over(img, bg):
    a = img[..., 3:4].astype(np.float32) / 255
    out = bg.copy()
    out[..., :3] = (img[..., :3] * a + bg[..., :3] * (1 - a)).astype(np.uint8)
    return out


MAX_SIDE = 1600   # IMAGE_TASK.md 3장: every image that is opened for viewing stays <= 1600 px per side


def _on_bg(img, bg=(60, 110, 170)):
    h, w = img.shape[:2]
    b = np.dstack([np.full((h, w), c, np.uint8) for c in bg] + [np.full((h, w), 255, np.uint8)])
    return _over(img, b)[..., :3]


def _zoom(img, z):
    return np.kron(img, np.ones((z, z, 1), np.uint8)) if z > 1 else img


def paged_sheet(cells, prefix: Path, max_side=MAX_SIDE) -> list[Path]:
    """cells = [(label, [[RGB img, ...] one list per line])] -> shelf-packed pages
    prefix_00.png, prefix_01.png ... each at most max_side x max_side."""
    from PIL import ImageDraw
    pad = 6
    boxes = []
    for label, lines in cells:
        w = max(sum(im.shape[1] for im in ln) + pad * (len(ln) - 1) for ln in lines)
        h = 12 + sum(max(im.shape[0] for im in ln) + pad for ln in lines)
        w = max(w, min(6 * len(label), max_side - 2 * pad))
        if w > max_side - 2 * pad or h > max_side - 2 * pad:
            raise ValueError(f"cell {label} is {w}x{h}, larger than a page")
        boxes.append((label, lines, w, h))
    pages, cur, x, y, rowh = [], [], pad, pad, 0
    for b in boxes:
        _l, _ln, w, h = b
        if x + w > max_side - pad:
            x, y, rowh = pad, y + rowh + pad, 0
        if y + h > max_side - pad:
            pages.append(cur)
            cur, x, y, rowh = [], pad, pad, 0
        cur.append((b, x, y))
        x += w + pad * 2
        rowh = max(rowh, h)
    if cur:
        pages.append(cur)
    prefix.parent.mkdir(parents=True, exist_ok=True)
    for old in prefix.parent.glob(prefix.name + "_[0-9][0-9].png"):
        old.unlink()
    paths = []
    for pi, pg in enumerate(pages):
        W = max(x + b[2] for b, x, _y in pg) + pad
        H = max(y + b[3] for b, _x, y in pg) + pad
        out = Image.new("RGB", (W, H), (35, 35, 35))
        dr = ImageDraw.Draw(out)
        for (label, lines, _w, _h), x, y in pg:
            dr.text((x, y), label, fill=(255, 230, 90))
            yy = y + 12
            for ln in lines:
                xx = x
                for im in ln:
                    out.paste(Image.fromarray(np.ascontiguousarray(im)), (xx, yy))
                    xx += im.shape[1] + pad
                yy += max(im.shape[0] for im in ln) + pad
        assert out.size[0] <= max_side and out.size[1] <= max_side
        p = prefix.parent / f"{prefix.name}_{pi:02d}.png"
        out.save(p)
        paths.append(p)
    return paths


def compare_cell(label, a0, a1, zoom=3):
    """orig | ko at 1x on one line, then orig xN and ko xN (side by side when they fit)."""
    w = a0.shape[1]
    z = max(1, min(zoom, (MAX_SIDE - 20) // max(1, w)))
    o, k = _on_bg(a0), _on_bg(a1)
    lines = [[o, k]]
    bo, bk = _zoom(o, z), _zoom(k, z)
    if 2 * bo.shape[1] + 6 <= MAX_SIDE - 20:
        lines.append([bo, bk])
    else:
        lines += [[bo], [bk]]
    return (f"{label}  orig|ko, x{z}", lines)


def sheet(rows, path: Path, zoom=3) -> None:
    cells = [compare_cell(label, a0, a1, zoom) for label, a0, a1 in rows]
    stem = path.with_suffix("")
    for p in paged_sheet(cells, stem):
        print("review", p)


def survey(game: str, dats=None, limit=12, only=None) -> None:
    """Unique frames of every object (checking for text), paged <= 1600 px:
    work/img/review/I3_survey_<game>_<dat>_NN.png"""
    dl = dats or (libobj.DATS_3DX if game == "3DX" else list(libobj.DATS_1DX))
    for d in dl:
        od = dat(game, d)
        cells = []
        for name in sorted(od.objs):
            if only and not any(s in name for s in only):
                continue
            o = od.objs[name]
            af = od.anim(o.anim)
            g = od.plain(o.graph)
            seen, n = set(), 0
            for fi, fr in enumerate(af.frames):
                img = libobj.render_frame(af, g, fr)
                if img is None or img[..., 3].max() == 0:
                    continue
                key = img.tobytes()
                if key in seen:
                    continue
                seen.add(key)
                n += 1
                if n > limit:
                    break
                z = 2 if max(img.shape[:2]) <= 96 else 1
                cells.append((f"{name}/f{fi:03d}", [[_zoom(_on_bg(img), z)]]))
        for p in paged_sheet(cells, REVIEW / f"I3_survey_{game}_{d}"):
            print("survey", p)


if __name__ == "__main__":
    if len(sys.argv) > 1 and sys.argv[1] == "--survey":
        g = sys.argv[2]
        ds = sys.argv[3].split(",") if len(sys.argv) > 3 and sys.argv[3] != "-" else None
        lim = int(sys.argv[4]) if len(sys.argv) > 4 else 12
        only = sys.argv[5].split(",") if len(sys.argv) > 5 else None
        survey(g, ds, lim, only)
    else:
        main()
