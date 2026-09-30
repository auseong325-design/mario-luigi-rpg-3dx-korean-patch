"""lyt_B -- 2차 B조(메뉴·상점·파일 화면) 레이아웃 한글 그림.

    python scripts/lyt_B.py measure      -> work/img/B_styles.json (원본 꾸밈 측정)
    python scripts/lyt_B.py make [ids..] -> work/img/ko/lyt/<dat>/<entry>/<name>.png (임시 이름 -> 이름 바꾸기)
    python scripts/lyt_B.py review       -> work/img/review/B_*.png (1600px 이하 조각)

imgtext*.py 는 I2 소유라 여기서는 가져다 쓰기만 한다.
"""
from __future__ import annotations

import json
import os
import sys
from pathlib import Path

import numpy as np
from PIL import Image

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "scripts"))

FAMS = ["menu_top", "set_tab", "shop_btn", "shop_top", "shop_title", "status_label", "file_btn", "file_label"]
OUT_STYLES = ROOT / "work/img/B_styles.json"


def items():
    plan = json.loads((ROOT / "work/img/lyt_plan.json").read_text(encoding="utf-8"))
    return [it for it in plan["items"] if it.get("family") in FAMS and it.get("action") == "replace"]


_MAN = None


def png_of(tex_id: str) -> Path | None:
    """manifest id ('1DX:MLyt/.../x.bflim') -> PNG path (복사본은 고유 위치의 PNG)."""
    global _MAN
    if not tex_id:
        return None
    if _MAN is None:
        m = json.loads((ROOT / "work/img/lyt_manifest.json").read_text(encoding="utf-8"))
        _MAN = {t["id"]: t for g in m for t in m[g]}
    t = _MAN.get(tex_id)
    if not t:
        return None
    p = ROOT / t["png"]
    return p if p.exists() else None


png_1dx = png_of


def load(p) -> np.ndarray:
    return np.asarray(Image.open(p).convert("RGBA"), dtype=np.float64) / 255.0


def cmd_measure():
    import imgtext as T
    res = {}
    for it in items():
        jp = load(ROOT / it["png"])
        st = T.measure_style(jp)
        d = {"fam": it["family"], "fmt": it["fmt"], "size": [it["w"], it["h"]], "jp": it["jp"], "ko": it["ko"],
             "kind": it["kind"], "style": st.to_json()}
        r = png_1dx(it.get("ref_1dx", ""))
        if r:
            s1 = T.measure_style(load(r))
            d["ref_1dx"] = {"png": str(r.relative_to(ROOT)), "size": list(Image.open(r).size),
                            "em": s1.em, "stroke": s1.stroke, "layers": [(l.width, l.color) for l in s1.layers],
                            "shadow": s1.shadow.__dict__ if s1.shadow else None, "box": s1.box}
        res[it["base"]] = d
    OUT_STYLES.write_text(json.dumps(res, ensure_ascii=False, indent=1, default=float), encoding="utf-8")
    # compact summary
    lines = []
    for k, d in res.items():
        s = d["style"]
        lay = " ".join("%.2f@%.2f" % (l["width"], l["color"][0]) for l in s["layers"])
        sh = s["shadow"]
        shs = "sh(%.1f,%.1f w%.2f c%.2f a%.2f)" % (sh["dx"], sh["dy"], sh["width"], sh["color"][0], sh["alpha"]) if sh else "-"
        face = "%.2f..%.2f" % (s["face_stops"][0][1][0], s["face_stops"][-1][1][0])
        r = d.get("ref_1dx")
        rs = ""
        if r:
            rs = " | 1DX em%.1f st%.2f lay %s box%s" % (r["em"], r["stroke"],
                                                      " ".join("%.2f" % l[0] for l in r["layers"]), r["box"])
        lines.append("%-14s %-30s %s em%.1f st%.2f face %s lay[%s] %s box%s %s%s" % (
            d["fam"], k, d["size"], s["em"], s["stroke"], face, lay, shs, s["box"], s["align"], rs))
    (ROOT / "work/img/B_styles.txt").write_text("\n".join(lines) + "\n", encoding="utf-8")


def cmd_zoom(extra_ids=()):
    """원본(3DX)과 1DX 참고를 묶음별로 확대해 본다: work/img/review/B_src_<fam>.png"""
    import imgtext as T
    by = {}
    for it in items():
        by.setdefault(it["family"], []).append(it)
    for fam, its in by.items():
        rows = []
        for it in its:
            imgs = [load(ROOT / it["png"])]
            r = png_of(it.get("ref_1dx", ""))
            if r:
                imgs.append(load(r))
            rows.append(("%s  %s -> %s" % (it["base"], it["jp"], it["ko"]), imgs))
        T.make_sheet(rows, ROOT / ("work/img/review/B_src_%s.png" % fam), zoom=3)
    for x in extra_ids:
        p = png_of(x)
        if p:
            T.make_sheet([(x, [load(p)])], ROOT / ("work/img/review/B_ref_%s.png" % Path(p).stem), zoom=4)


# ----------------------------------------------------------------------------- own drawing (kind 가, fallbacks)

SS = 4
WD_MAX = float(os.environ.get("B_WDMAX", "1.5"))   # 굵히기 상한 px (틈 보호 thicken 을 쓰므로 넉넉히)
GAP_MIN = float(os.environ.get("B_GAPMIN", "1.0"))  # 굵힐 때 지킬 획 사이 최소 틈 px


def face_cov(rgba: np.ndarray) -> np.ndarray:
    """흰 채움 + 검은 테두리 LA4 그림의 채움 덮임(0..1) = 밝기 × 알파."""
    L = rgba[..., 0] * 0.299 + rgba[..., 1] * 0.587 + rgba[..., 2] * 0.114
    c = L * rgba[..., 3]
    c[c < 0.04] = 0
    return c


def bbox(m, thr=0.3):
    ys, xs = np.nonzero(m > thr)
    return (int(xs.min()), int(ys.min()), int(xs.max()) + 1, int(ys.max()) + 1)


def hires(cov: np.ndarray, scale: float) -> np.ndarray:
    """native 덮임 -> (scale*SS)배 부드러운 마스크."""
    import imgtext as T
    return T.upsample(cov, scale * SS)


def paste(canvas, m, x, y):
    import imgtext as T
    T._paste_max(canvas, m.astype(np.float32), int(round(x)), int(round(y)))


def decorate(face_hr: np.ndarray, size, outline=1.85, weight=0.0, face=1.0, edge=0.0) -> np.ndarray:
    """SS배 채움 마스크 -> 원본 크기 RGBA. outline = 채움 윤곽 밖 테두리 반지름(px),
    weight = 채움을 한쪽으로 굵게(+)/가늘게(-) 할 px."""
    import imgtext as T
    w, h = size
    d = T.sdf(face_hr) - weight * SS
    fc = T.cov_from_sdf(d, 0.0)
    oc = T.cov_from_sdf(d, outline * SS) if outline > 0 else np.zeros_like(fc)
    a_hr = np.maximum(fc, oc)
    prem_hr = fc * face + (oc * (1 - fc)) * edge
    a = T.downsample(a_hr, SS)
    p = T.downsample(prem_hr, SS)
    out = np.zeros((h, w, 4))
    col = np.where(a > 1e-6, p / np.maximum(a, 1e-6), 0)
    out[..., 0] = out[..., 1] = out[..., 2] = col
    out[..., 3] = a
    return out


def stroke_px(cov: np.ndarray) -> float:
    import imgtext as T
    return float(T.stroke_width(cov))


def finish(rgba, fmt="LA4"):
    import imgtext as T
    return T.finalize(T.bleed(rgba), fmt)


def write_ko(it, rgba):
    """임시 이름으로 쓴 뒤 이름 바꾸기(다른 조와 동시 빌드)."""
    import imgtext as T
    dst = ROOT / it["ko_png"]
    dst.parent.mkdir(parents=True, exist_ok=True)
    tmp = dst.with_name(dst.stem + ".tmpB.png")
    T.save_png(rgba, tmp)
    os.replace(tmp, dst)
    return dst


def by_base():
    return {it["base"]: it for it in items()}


def make_from_1dx_word(it, src_id, crop=None, em=None, outline=1.85, stroke_target=None, cx=None, cy=None,
                       max_w=None):
    """1DX 같은 낱말 그림의 글자 모양(채움만) -> 3DX 원본 크기·꾸밈."""
    jp = load(ROOT / it["png"])
    st = json.loads(OUT_STYLES.read_text(encoding="utf-8"))[it["base"]]["style"]
    src = load(png_of(src_id))
    fc = face_cov(src)
    if crop:
        x0, y0, x1, y1 = crop
        z = np.zeros_like(fc)
        z[y0:y1, x0:x1] = fc[y0:y1, x0:x1]
        fc = z
    b = bbox(fc)
    fc = fc[max(0, b[1] - 1):b[3] + 1, max(0, b[0] - 1):b[2] + 1]
    src_h = b[3] - b[1]
    em = em or st["em"]
    s = em / src_h
    hs = 1.0
    if max_w and (b[2] - b[0]) * s > max_w:
        hs = max(0.8, max_w / ((b[2] - b[0]) * s))
    m = hires(fc, s)
    if hs != 1.0:
        import cv2
        m = cv2.resize(m, (int(round(m.shape[1] * hs)), m.shape[0]), interpolation=cv2.INTER_AREA)
    w, h = it["w"], it["h"]
    bx = st["box"]
    if cx is None:
        cx = (bx[0] + bx[2]) / 2.0
        if abs(cx - w / 2) <= 1.5:
            cx = w / 2
    if cy is None:
        cy = (bx[1] + bx[3]) / 2.0
    canvas = np.zeros((h * SS, w * SS), np.float32)
    paste(canvas, m, cx * SS - m.shape[1] / 2, cy * SS - m.shape[0] / 2)
    cur = stroke_px(fc) * s
    tgt = stroke_target if stroke_target is not None else st["stroke"]
    wd = float(np.clip((tgt - cur) / 2, -0.25 * cur, WD_MAX))
    r = _thicken(canvas, wd)
    if isinstance(r, tuple):
        m2, pad = r
        canvas = m2[pad:pad + canvas.shape[0], pad:pad + canvas.shape[1]]
    ko = decorate(canvas, (w, h), outline=outline, weight=0.0)
    return finish(ko, it["fmt"]), {"src": src_id, "scale": round(s, 3), "hscale": hs, "stroke_src": round(cur, 2),
                                   "stroke_tgt": tgt, "weight_delta": round(wd, 3)}


def cmd_ga():
    import imgtext as T
    B = by_base()
    rows = []
    rep = {}
    it = B["TOP_MENU_TEXT_2_00_JP_ja"]
    for ol in (1.75, 2.0):
        ko, r = make_from_1dx_word(it, "1DX:GLyt/G_BG_12_KR_ko/timg/TOP_MENU_TEXT_2_12_KR_ko.bflim", outline=ol)
        jp = load(ROOT / it["png"])
        c = T.compare(jp, ko)
        r["cmp"] = c["summary"]
        rep["%s ol%.2f" % (it["base"], ol)] = r
        rows.append(("%s 장비 outline %.2f" % (it["base"], ol), [jp, ko]))
    T.make_sheet(rows, ROOT / "work/img/review/B_ga_test.png", zoom=4)
    (ROOT / "work/img/B_ga_test.json").write_text(json.dumps(rep, ensure_ascii=False, indent=1, default=str), encoding="utf-8")


OFL_LATIN = ["GothicA1-Black.ttf", "GothicA1-ExtraBold.ttf", "GothicA1-Bold.ttf", "NotoSansKR-Bold.otf",
             "NanumGothic-ExtraBold.ttf", "NanumSquareRoundEB.ttf", "NanumSquareRoundB.ttf", "BlackHanSans-Regular.ttf",
             "DoHyeon-Regular.ttf", "Jua-Regular.ttf", "Sunflower-Bold.ttf"]


def seg_columns(cov, thr=0.15):
    prof = (cov > thr).any(axis=0)
    segs, x = [], 0
    while x < len(prof):
        if prof[x]:
            x0 = x
            while x < len(prof) and prof[x]:
                x += 1
            segs.append((x0, x))
        else:
            x += 1
    return segs


def ofl_letter(font_file, ch, cap_px_hr):
    """OFL 글꼴 글자 -> 대문자 높이가 cap_px_hr 인 부드러운 마스크(+ 글자 위쪽 기준 y)."""
    from PIL import ImageFont, ImageDraw
    big = 200
    f = ImageFont.truetype(str(ROOT / "fonts" / font_file), big)
    im = Image.new("L", (big * 2, big * 2), 0)
    ImageDraw.Draw(im).text((big // 2, big // 2), ch, font=f, fill=255)
    a = np.asarray(im, np.float64) / 255
    # 대문자 높이 기준: 'H' 높이
    imH = Image.new("L", (big * 2, big * 2), 0)
    ImageDraw.Draw(imH).text((big // 2, big // 2), "H", font=f, fill=255)
    bh = bbox(np.asarray(imH, np.float64) / 255, 0.5)
    b = bbox(a, 0.5)
    s = cap_px_hr / (bh[3] - bh[1])
    import cv2
    crop = a[b[1]:b[3], b[0]:b[2]]
    m = cv2.resize(crop.astype(np.float32), (max(1, int(round(crop.shape[1] * s))), max(1, int(round(crop.shape[0] * s)))),
                   interpolation=cv2.INTER_AREA)
    return m, (b[1] - bh[1]) * s


def iou(a, b):
    return float(np.minimum(a, b).sum() / max(np.maximum(a, b).sum(), 1e-6))


def cmd_newgame(font_pick=None):
    """NEW DATA -> NEW GAME. N·E·W·A 는 3DX 원본 글자, G·M 은 가장 비슷한 OFL 글꼴."""
    import cv2
    import imgtext as T
    it = by_base()["NEW_DATA_text_00_JP_ja"]
    jp = load(ROOT / it["png"])
    cov = jp[..., 3] * (jp[..., 0] > 0.5)
    segs = seg_columns(cov, 0.75)
    letters = "NEWDATA"
    assert len(segs) == 7, segs
    yb = bbox(cov)
    cap = yb[3] - yb[1]
    L = {}
    for ch, (x0, x1) in zip(letters, segs):
        L.setdefault(ch, (x0, x1))
    # 글꼴 고르기: N E W D A T 겹침
    rep = {"segs": segs, "cap": cap}
    scores = {}
    for ff in OFL_LATIN:
        if not (ROOT / "fonts" / ff).exists():
            continue
        sc = []
        for ch in "NEWDAT":
            x0, x1 = L[ch]
            ref = cov[yb[1]:yb[3], x0:x1]
            m, _ = ofl_letter(ff, ch, cap * SS)
            m = cv2.resize(m, (ref.shape[1], ref.shape[0]), interpolation=cv2.INTER_AREA)
            sc.append(iou(ref, m))
        # 글자 폭 비율도 본다
        wr = []
        for ch in "NEWDAT":
            x0, x1 = L[ch]
            m, _ = ofl_letter(ff, ch, cap * SS)
            wr.append((m.shape[1] / SS) / (x1 - x0))
        scores[ff] = {"iou": round(float(np.mean(sc)), 3), "w_ratio": round(float(np.mean(wr)), 3)}
    rep["fonts"] = scores
    best = font_pick or max(scores, key=lambda k: scores[k]["iou"] - abs(1 - scores[k]["w_ratio"]) * 0.5)
    rep["pick"] = best
    # 원본 글자 폭·간격
    gaps = [segs[i + 1][0] - segs[i][1] for i in range(len(segs) - 1)]
    gap_in = int(round(np.median([gaps[0], gaps[1], gaps[4], gaps[5]])))   # 낱말 안 간격
    space = segs[3][0] - segs[2][1]                                            # W 와 D 사이
    ref_stroke = stroke_px(cov[:, L["N"][0]:L["N"][1]])
    parts = []
    for ch in "NEW GAME":
        if ch == " ":
            parts.append(None)
            continue
        if ch in L and ch != "M":
            x0, x1 = L[ch]
            src = cov[:, x0 - 1:x1 + 1]
            m = T.upsample(src, SS)
            parts.append((m, 0.0, "3dx", 1))
        else:
            m, _ = ofl_letter(best, ch, cap * SS)
            # 굵기 맞춤: 원본 N 획 두께
            cur = T.stroke_width(cv2.resize(m, (max(1, m.shape[1] // SS), cap), interpolation=cv2.INTER_AREA))
            wd = (ref_stroke - cur) / 2
            d = T.sdf(m) - wd * SS
            m = T.cov_from_sdf(d, 0.0)
            # 위아래 여백 없이 대문자 높이로
            full = np.zeros((jp.shape[0] * SS, m.shape[1]), np.float32)
            y0 = yb[1] * SS
            full[y0:y0 + m.shape[0], :] = m[:full.shape[0] - y0]
            parts.append((full, wd, best, 0))
    widths = [((p[0].shape[1] - 2 * p[3] * SS) if p else space * SS) for p in parts]
    gsum = (segs[1][0] - segs[0][1]) * 2 + (segs[2][0] - segs[1][1]) + (segs[4][0] - segs[3][1]) + (segs[5][0] - segs[4][1])
    total = sum(widths) + gsum * SS
    w, h = it["w"], it["h"]
    cx = (yb[0] + yb[2]) / 2.0
    x = cx * SS - total / 2
    canvas = np.zeros((h * SS, w * SS), np.float32)
    prev_letter = False
    # 글자 사이 간격(원본 코어 간격): N-E, E-W 는 원본값, G-A·A-M 은 원본 D-A·A-T 값, M-E 는 N-E(곧은 획끼리)와 같게
    gl = [segs[1][0] - segs[0][1], segs[2][0] - segs[1][1], segs[4][0] - segs[3][1], segs[5][0] - segs[4][1],
          segs[1][0] - segs[0][1]]
    gi = 0
    for p, wd_ in zip(parts, widths):
        if p is None:
            x += wd_
            prev_letter = False
            continue
        if prev_letter:
            x += gl[gi] * SS
            gi += 1
        paste(canvas, p[0], x - p[3] * SS, 0)
        x += wd_
        prev_letter = True
    rgba = decorate(canvas, (w, h), outline=0.0)
    ko = finish(rgba, it["fmt"])
    rep["gap_in"] = gap_in
    rep["space"] = space
    rep["ref_stroke"] = ref_stroke
    rep["compare"] = T.compare(jp, ko)["summary"]
    return it, jp, ko, rep


def cmd_ga_final():
    import imgtext as T
    B = by_base()
    rows, rep = [], {}
    it = B["TOP_MENU_TEXT_2_00_JP_ja"]
    ko, r = make_from_1dx_word(it, "1DX:GLyt/G_BG_12_KR_ko/timg/TOP_MENU_TEXT_2_12_KR_ko.bflim", outline=1.85)
    write_ko(it, ko)
    rep[it["base"]] = r
    rows.append((it["base"] + " 장비 (가)", [load(ROOT / it["png"]), ko]))
    it2, jp2, ko2, r2 = cmd_newgame(os.environ.get("B_NEWGAME_FONT"))
    write_ko(it2, ko2)
    rep[it2["base"]] = r2
    rows.append((it2["base"] + " 원본 NEW DATA", [jp2]))
    rows.append((it2["base"] + " NEW GAME (가) G·M=" + r2["pick"], [ko2]))
    T.make_sheet(rows, ROOT / "work/img/review/B_ga.png", zoom=4)
    (ROOT / "work/img/B_ga.json").write_text(json.dumps(rep, ensure_ascii=False, indent=1, default=str), encoding="utf-8")


# 묶음(·텍스처 크기)별 통일 값: 한글 글자 높이 em, 검은 테두리 반지름, 목표 획 두께(원본 가나에서 잰 값의 중앙)
FAMP = {
    "menu_top": dict(em=13, outline=1.85, stroke=2.4),
    "set_tab": dict(em=16, outline=1.85, stroke=3.5),
    "shop_btn": dict(em=16, outline=1.85, stroke=3.2),
    "shop_top": dict(em=13, outline=1.85, stroke=2.4),
    "shop_title": dict(em=13, outline=0.0, stroke=2.2),
    "status_label": dict(em=12, outline=1.85, stroke=2.1),
    "file_btn:108x22": dict(em=12, outline=1.85, stroke=2.8),
    "file_btn:172x22": dict(em=14, outline=1.85, stroke=3.0),
    "file_btn:128x24": dict(em=16, outline=1.85, stroke=3.4),
    "file_btn:232x62": dict(em=16, outline=1.85, stroke=3.1),
    "file_label": dict(em=12, outline=0.0, stroke=2.3),
}


def famp(it):
    k = "%s:%dx%d" % (it["family"], it["w"], it["h"])
    return dict(FAMP.get(k) or FAMP[it["family"]])


K = "1DX:MLyt/MLYT_SHOP_KR_ko/timg/"
F = "1DX:MLyt/MLYT_FILE_LOAD_KR_ko/timg/"
G = "1DX:GLyt/G_BG_12_KR_ko/timg/"
SAME_WORD = {
    "TOP_MENU_TEXT_1_00_JP_ja": G + "TOP_MENU_TEXT_1_12_KR_ko.bflim",
    "TOP_MENU_TEXT_2_00_JP_ja": G + "TOP_MENU_TEXT_2_12_KR_ko.bflim",
    "TOP_MENU_TEXT_6_00_JP_ja": G + "TOP_MENU_TEXT_4_12_KR_ko.bflim",
    "TOP_MENU_TEXT_4_00_JP_ja": "1DX:MLyt/MLYT_MAIN_KR_ko/timg/TOP_MENU_TEXT_5_12_KR_ko.bflim",
    "TOP_MENU_TEXT_5_00_JP_ja": K + "shop_top_badge_text_12_KR_ko.bflim",
    "btn_buy_00_JP_ja": K + "btn_buy_12_KR_ko.bflim",
    "btn_sell_00_JP_ja": K + "btn_sell_12_KR_ko.bflim",
    "btn_later_00_JP_ja": K + "btn_later_12_KR_ko.bflim",
    "btn_scratch_00_JP_ja": F + "btn_load_YES_text_12_KR_ko.bflim",
    "shop_top_item_text_00_JP_ja": G + "TOP_MENU_TEXT_1_12_KR_ko.bflim",   # shop_top_item 은 13px에서 '템'이 뭉침
    "shop_top_sell_text_00_JP_ja": K + "shop_top_sell_text_12_KR_ko.bflim",
    "shop_top_badge_text_00_JP_ja": K + "shop_top_badge_text_12_KR_ko.bflim",
    "shop_top_wear_text_00_JP_ja": K + "shop_top_wear_01_text_12_KR_ko.bflim",
    "shop_top_equip_text_00_JP_ja": G + "TOP_MENU_TEXT_2_12_KR_ko.bflim",
    "STATUS_EQUIP_00_JP_ja": G + "TOP_MENU_TEXT_2_12_KR_ko.bflim",
    "btn_SAVE_text_00_JP_ja": "1DX:MLyt/MLYT_FILE_SAVE_KR_ko/timg/btn_SAVE_text_12_KR_ko.bflim",
    "btn_DERACE_00_JP_ja": F + "btn_load_DERACE_text_12_KR_ko.bflim",
    "btn_COPY_00_JP_ja": F + "btn_load_COPY_text_12_KR_ko.bflim",
    "btn_CANCEL2_00_JP_ja": F + "btn_load_DONOT_text_12_KR_ko.bflim",
    "btn_FERASE_00_JP_ja": F + "btn_load_FERACE_text_12_KR_ko.bflim",
    "btn_DELETE1_00_JP_ja": F + "btn_load_DELETE_text_12_KR_ko.bflim",
    "btn_OWRITE_00_JP_ja": F + "btn_load_OWRITE_text_12_KR_ko.bflim",
    "btn_START_00_JP_ja": F + "btn_load_START_text_12_KR_ko.bflim",
}


def make_same_word(it):
    p = famp(it)
    return make_from_1dx_word(it, SAME_WORD[it["base"]], em=p["em"], outline=p["outline"], stroke_target=p["stroke"],
                              max_w=it["w"] - 2 * (p["outline"] + 1))


def cmd_same(outdir=None):
    """1DX 같은 낱말 그림이 있는 텍스처를 내 방식으로 그린다(outdir 에만, 시험)."""
    import imgtext as T
    B = by_base()
    outdir = Path(outdir)
    outdir.mkdir(parents=True, exist_ok=True)
    rows, rep = [], {}
    for base in SAME_WORD:
        it = B[base]
        ko, r = make_same_word(it)
        T.save_png(ko, outdir / (base + ".png"))
        jp = load(ROOT / it["png"])
        r["problems"] = T.verdict(T.compare(jp, ko))
        rep[base] = r
        rows.append(("%s %s  %s" % (base, it["ko"], " ".join(r["problems"])), [jp, ko]))
    T.make_sheet(rows, outdir / "same.png", zoom=3)
    (outdir / "same.json").write_text(json.dumps(rep, ensure_ascii=False, indent=1, default=str), encoding="utf-8")


# ----------------------------------------------------------------------------- compositor (font / 1DX word / original pieces)


def _thicken(m_hr: np.ndarray, wd_px: float):
    """채움을 wd_px 만큼 굵게(+)/가늘게(-). 굵힐 때는 imgtext.thicken(획 사이 틈 1px 보호)."""
    import imgtext as T
    if abs(wd_px) < 1e-3:
        return m_hr
    pad = int(np.ceil(abs(wd_px) * SS)) + 2
    mp = np.pad(m_hr, pad)
    if wd_px > 0:
        return T.thicken(mp, wd_px * SS, GAP_MIN * SS).astype(np.float32), pad
    return T.cov_from_sdf(T.sdf(mp) - wd_px * SS, 0.0).astype(np.float32), pad


def compose(it, pieces, em, outline, stroke, align=None, cx=None, cy=None, left=None, min_hs=0.8,
            gap_px=None, space_em=0.33):
    """pieces: [("font", text, fontname) | ("img", 1dx_id) | ("orig", x0, x1) | ("space", em_frac)]
    한글은 em 상자 위를 공유하고(가운데 cy), 원본 조각은 원래 자리 높이 그대로 둔다."""
    import cv2
    import imgtext as T
    import imgtext_bank as BK
    st = json.loads(OUT_STYLES.read_text(encoding="utf-8"))[it["base"]]["style"]
    jp = load(ROOT / it["png"])
    w, h = it["w"], it["h"]
    bx = st["box"]
    align = align or st["align"]
    if cy is None:
        cy = (bx[1] + bx[3]) / 2.0
    emtop = cy - em / 2.0
    face_jp = face_cov(jp) if st["layers"] else jp[..., 3] * (luma(jp) > 0.5)
    glyphs = []     # dict(m=hr mask, w=advance px, y=top px (abs), gap=px after, ko=bool)
    info = {"sources": []}
    for p in pieces:
        if p[0] == "space":
            if glyphs:
                glyphs[-1]["gap"] += p[1] * em
            continue
        if p[0] == "orig":
            x0, x1 = p[1], p[2]
            sub = face_jp[:, x0:x1]
            glyphs.append(dict(m=T.upsample(sub, SS), w=float(x1 - x0), y=0.0, gap=gap_px if gap_px is not None else 1.0,
                               ko=False, pad=0))
            info["sources"].append(("orig", x0, x1))
            continue
        if p[0] == "img":
            src = load(png_of(p[1]))
            fc = face_cov(src)
            b = bbox(fc)
            fc = fc[b[1]:b[3], b[0]:b[2]]
            s = em / (b[3] - b[1])
            cur = stroke_px(fc) * s
            wd = float(np.clip((stroke - cur) / 2, -0.25 * cur, WD_MAX))
            m = hires(fc, s)
            r = _thicken(m, wd)
            m, pad = (r if isinstance(r, tuple) else (r, 0))
            glyphs.append(dict(m=m, w=fc.shape[1] * s, y=emtop, gap=gap_px if gap_px is not None else 1.0, ko=True, pad=pad))
            info["sources"].append(("img", p[1], round(s, 3), round(cur, 2), round(wd, 2)))
            continue
        # font word (한 낱말은 한 글꼴: 없는 음절이 있으면 낱말 전체를 다른 글꼴로)
        text, fname = p[1], os.environ.get("B_FONT") or p[2]

        def _word(fn):
            f_ = BK.bitmap_font(fn)
            res = []
            for ch in text:
                g_ = f_.glyph(ch)
                tg = "font"
                if g_ is None:
                    g_ = f_.composed(ch)
                    tg = "compose"
                if g_ is None:
                    return None
                res.append((ch, g_, tg))
            return f_, res
        got = _word(fname)
        if got is None:
            fname = "font" if fname == "font_l" else "font_l"
            got = _word(fname)
        if got is None:
            raise ValueError("no glyphs for %r" % text)
        f, gl = got
        srcs = []
        for ch, g, tag in gl:
            s = em / f.em
            cur = g.stroke * s
            wd = 0.0 if stroke is None else float(np.clip((stroke - cur) / 2, -0.25 * cur, WD_MAX))
            m = hires(g.cov, s)
            r = _thicken(m, wd)
            m, pad = (r if isinstance(r, tuple) else (r, 0))
            gp = g.gap * s if gap_px is None else gap_px
            glyphs.append(dict(m=m, w=g.cov.shape[1] * s, y=emtop + g.y * s, gap=gp, ko=True, pad=pad))
            srcs.append("%s%s" % (ch, "" if tag == "font" else "*"))
        info["sources"].append(("%s:%s" % (tag if all("*" not in x for x in srcs) else "font+compose", fname),
                                "".join(srcs), round(em / f.em, 3)))
    if glyphs:
        glyphs[-1]["gap"] = 0.0
    # --- fit width
    ext = outline + 0.5
    avail = (w - 2 * ext) if align == "center" else (w - ext - (left if left is not None else bx[0]))
    nat = sum(g["w"] + g["gap"] for g in glyphs)
    kow = sum(g["w"] for g in glyphs if g["ko"])
    hs, tr = 1.0, 0.0
    if nat > avail and kow > 0:
        hs = max(min_hs, 1 - (nat - avail) / kow)
        nat2 = nat - kow * (1 - hs)
        if nat2 > avail and len(glyphs) > 1:
            tr = -(nat2 - avail) / (len(glyphs) - 1)
    total = sum(g["w"] * (hs if g["ko"] else 1) + g["gap"] + tr for g in glyphs) - tr
    if align == "center":
        if cx is None:
            cx = (bx[0] + bx[2]) / 2.0
            if abs(cx - w / 2) <= 1.5:
                cx = w / 2
        x = cx - total / 2
        x = min(max(x, ext), w - ext - total)
    else:
        x = left if left is not None else bx[0]
    canvas = np.zeros((h * SS, w * SS), np.float32)
    for g in glyphs:
        m = g["m"]
        if g["ko"] and hs != 1.0:
            m = cv2.resize(m, (max(1, int(round(m.shape[1] * hs))), m.shape[0]), interpolation=cv2.INTER_AREA)
        pad = g["pad"]
        paste(canvas, m, x * SS - pad * hs, g["y"] * SS - pad)
        x += g["w"] * (hs if g["ko"] else 1) + g["gap"] + tr
    ko = decorate(canvas, (w, h), outline=outline, weight=0.0)
    info.update({"hscale": round(hs, 3), "tracking": round(tr, 3), "width": round(total, 2), "avail": round(avail, 2)})
    return finish(ko, it["fmt"]), info


def luma(rgba):
    return rgba[..., 0] * 0.299 + rgba[..., 1] * 0.587 + rgba[..., 2] * 0.114


def cmd_segs():
    B = by_base()
    out = []
    for base in ["btn_MLRPG3_00_JP_ja", "LABEL_MLRPG_00_JP_ja", "btn_KJRPG_00_JP_ja", "LABEL_KJRPG_00_JP_ja"]:
        it = B[base]
        jp = load(ROOT / it["png"])
        st = json.loads(OUT_STYLES.read_text(encoding="utf-8"))[base]["style"]
        fc = face_cov(jp) if st["layers"] else jp[..., 3] * (luma(jp) > 0.5)
        for thr in (0.15, 0.5, 0.75):
            out.append("%s thr%.2f %s" % (base, thr, seg_columns(fc, thr)))
        out.append("%s alpha-cols %s" % (base, seg_columns(jp[..., 3], 0.1)))
    (ROOT / "work/img/B_segs.txt").write_text("\n".join(out) + "\n", encoding="utf-8")


def words(text, fname):
    out = []
    for i, wd in enumerate(text.split(" ")):
        if i:
            out.append(("space", 0.33))
        out.append(("font", wd, fname))
    return out


PIECES = {
    # 1DX 그림 쪽은 em 10~11 이라 13~16px로 키우면 뭉개짐(규칙: 확대 1.25배 이하) -> 폰트
    "TOP_MENU_TEXT_5_00_JP_ja": [("font", "배지", "font")],
    "shop_top_badge_text_00_JP_ja": [("font", "배지", "font")],
    "btn_scratch_00_JP_ja": [("font", "예", "font_l")],
    "TOP_MENU_TEXT_3_00_JP_ja": [("font", "능력", "font")],
    "tab_SET_ON2_00_JP_ja": [("font", "있음", "font_l")],
    "tab_SET_OFF2_00_JP_ja": [("font", "없음", "font_l")],
    "btn_equip_00_JP_ja": [("font", "착용하기", "font_l")],
    "shop_top_acce_text_00_JP_ja": [("font", "액세서리", "font")],
    "shop_top_koura_text_00_JP_ja": [("font", "등껍질", "font")],
    "STATUS_RANKBONUS_00_JP_ja": words("랭크 업 보너스", "font"),
    "btn_RETURN_TITLE_00_JP_ja": words("타이틀로 돌아가기", "font"),
    "btn_CONTINUE_00_JP_ja": words("모험 계속하기", "font"),
    "btn_KJRPG_00_JP_ja": [("font", "쿠파주니어", "font_l"), ("space", 0.33), ("orig", 132, 173)],
    "btn_MLRPG3_00_JP_ja": [("font", "마리오", "font_l"), ("orig", 77, 89), ("font", "루이지", "font_l"),
                            ("space", 0.33), ("orig", 153, 203)],
    "LABEL_MLRPG_00_JP_ja": [("font", "마리오", "font"), ("orig", 36, 45), ("font", "루이지", "font"),
                             ("space", 0.33), ("orig", 93, 131)],
    "LABEL_KJRPG_00_JP_ja": [("font", "쿠파주니어", "font"), ("space", 0.33), ("orig", 53, 84)],
    "btn_SLOT_00_JP_ja": [("font", "슬롯", "font_l")],
}


STROKE_OVERRIDE = {
    # 슬·롯은 ㅅㅡㄹ·ㄹㅗㅅ 세로 세 겹이라 12px에서 가나 두께(2.3)로 굵히면 막힌다 -> 1DX 폰트 두께 그대로
    "btn_SLOT_00_JP_ja": {"thick": 2.3, "none": None}.get(os.environ.get("B_SLOT", ""), 2.0),
}


def plan_for(it):
    b = it["base"]
    if b == "NEW_DATA_text_00_JP_ja":
        return "newgame"
    if b in GRID_BASES and not os.environ.get("B_NO_GRID"):
        return "grid"
    if b in PIECES:
        return "pieces"
    if b in SAME_WORD:
        return "same"
    if it["family"] == "shop_title":
        return "pieces"
    raise KeyError(b)


def make_one(it):
    kind = plan_for(it)
    p = famp(it)
    if kind == "newgame":
        _, _, ko, r = cmd_newgame(os.environ.get("B_NEWGAME_FONT"))
        return ko, dict(method="newgame", **r)
    if kind == "grid":
        return make_grid(it)
    if kind == "same":
        ko, r = make_same_word(it)
        return ko, dict(method="1dx_same_word", **r)
    pcs = PIECES.get(it["base"]) or words(it["ko"], "font")
    if it["base"] in STROKE_OVERRIDE:
        p["stroke"] = STROKE_OVERRIDE[it["base"]]
    st = json.loads(OUT_STYLES.read_text(encoding="utf-8"))[it["base"]]["style"]
    left = st["box"][0] if st["align"] == "left" else None
    ko, r = compose(it, pcs, em=p["em"], outline=p["outline"], stroke=p["stroke"], left=left)
    return ko, dict(method="compose", **r)


def cmd_make(outdir=None, only=()):
    """전부(또는 only) 만들기. outdir 없으면 work/img/ko/ 에 임시 이름 -> 이름 바꾸기."""
    import imgtext as T
    rep = {}
    for it in items():
        if only and it["base"] not in only:
            continue
        ko, r = make_one(it)
        jp = load(ROOT / it["png"])
        r["problems"] = T.verdict(T.compare(jp, ko))
        if outdir:
            Path(outdir).mkdir(parents=True, exist_ok=True)
            T.save_png(ko, Path(outdir) / (it["base"] + ".png"))
        else:
            r["out"] = str(write_ko(it, ko).relative_to(ROOT))
        r["ko"] = it["ko"]
        rep[it["base"]] = r
    dst = (Path(outdir) / "make.json") if outdir else (ROOT / "work/img/B_make.json")
    old = {}
    if dst.exists() and only:
        old = json.loads(dst.read_text(encoding="utf-8"))
    old.update(rep)
    dst.write_text(json.dumps(old, ensure_ascii=False, indent=1, default=str), encoding="utf-8")


def cmd_review(src_dir=None, tag="B"):
    """묶음별 대조표: 원본 | 한국어 (실제 크기 + 3배). 1600px 이하 조각."""
    import imgtext as T
    by = {}
    for it in items():
        by.setdefault(it["family"], []).append(it)
    written = []
    for fam in FAMS:
        rows = []
        for it in by.get(fam, []):
            kp = (Path(src_dir) / (it["base"] + ".png")) if src_dir else (ROOT / it["ko_png"])
            if not kp.exists():
                continue
            rows.append(("%s  %s -> %s" % (it["base"], it["jp"], it["ko"]), [load(ROOT / it["png"]), load(kp)]))
        if rows:
            written += T.make_sheet(rows, (Path(src_dir) if src_dir else ROOT / "work/img/review") /
                                    ("%s_%s.png" % (tag, fam)), zoom=3)
    return written


def cmd_summary(path):
    d = json.loads(Path(path).read_text(encoding="utf-8"))
    lines = []
    for k, v in d.items():
        lines.append("%-30s %-14s %s hs=%s tr=%s w=%s/%s wd=%s %s" % (
            k, v.get("method"), v.get("sources") or v.get("src") or v.get("pick"), v.get("hscale"), v.get("tracking"),
            v.get("width"), v.get("avail"), v.get("weight_delta"), " ".join(v.get("problems", []))))
    (Path(path).with_suffix(".txt")).write_text("\n".join(lines) + "\n", encoding="utf-8")


def cmd_tk(outdir, only=()):
    """imgtext 1.1 redraw 기본값(jp_text 포함)으로 그려 outdir 에."""
    import imgtext as T
    outdir = Path(outdir)
    outdir.mkdir(parents=True, exist_ok=True)
    rep = {}
    for it in items():
        if only and it["base"] not in only:
            continue
        try:
            ko, r = T.redraw(str(ROOT / it["png"]), it["ko"], fmt=it["fmt"], jp_text=it["jp"])
        except Exception as e:  # noqa
            rep[it["base"]] = {"error": repr(e)}
            continue
        T.save_png(ko, outdir / (it["base"] + ".png"))
        rep[it["base"]] = {"sources": r.get("sources"), "levels": r.get("levels"), "weight": r.get("weight"),
                           "fit": r.get("fit"), "problems": r.get("problems")}
    (outdir / "tk.json").write_text(json.dumps(rep, ensure_ascii=False, indent=1, default=str), encoding="utf-8")


def cmd_cmp3(mine, tk, dst):
    """원본 | 내 방식 | imgtext 1.1 을 묶음별로."""
    import imgtext as T
    by = {}
    for it in items():
        by.setdefault(it["family"], []).append(it)
    for fam in FAMS:
        rows = []
        for it in by.get(fam, []):
            ims = [load(ROOT / it["png"])]
            for d in (mine, tk):
                p = Path(d) / (it["base"] + ".png")
                if p.exists():
                    ims.append(load(p))
            rows.append(("%s %s  [원본 | B | imgtext]" % (it["base"], it["ko"]), ims))
        T.make_sheet(rows, Path(dst) / ("C3_%s.png" % fam), zoom=2)


# ----------------------------------------------------------------------------- grid-fit (작은 흰 글상자: shop_title · file_label)
#
# 4배로 그려 줄이는 길(compose)은 비트맵 글자를 0.57~0.87배로 줄이면서 획이 픽셀 사이에 걸려
# 회색으로 흐려진다(숍·슬롯·마리오&루이지 — 리드 확인 2026-09-30). 작은 글상자는 1DX 비트맵 글자를
# 픽셀 격자 그대로 쓰고, 크기·굵기는 행/열을 통째로 빼거나 더하고(격자 맞춤) 1px 단위로 굵힌다.


GRID_THR = 0.70      # 1DX 비트맵 덮임: B/15(0.73) 이상 = 획, A/15(0.67) 이하 = 틈(반투명 가장자리)
# 수정 2라운드(리드: 격자 맞춤이 너무 가늘다, 획 비 0.55~0.92): 1DX 폰트의 가로획은 진한 1px 줄 + 반투명 줄이라
# 0.70에서 자르면 1px만 남는다. 음절마다 아래 문턱값을 낮은 것부터 시험해, 격자 맞춤 결과의 먹 조각 수와
# 속공간 수가 원래 크기 글자(0.70)와 같은 가장 낮은 값을 쓴다(획은 굵어지고 ㅁ·ㅂ·ㅇ 속은 막히지 않음).
# 모양을 손으로 정한 글자(GLYPH_OVERRIDE의 thr·splice·row_groups)는 그 값 그대로.
GRID_THRS = (0.45, 0.50, 0.55, 0.60, 0.65, 0.70)


def _topology(B: np.ndarray) -> tuple[int, int]:
    """(먹 조각 수(8방향), 속공간 수(4방향)) of a 0/1 glyph."""
    import cv2
    X = np.pad((np.asarray(B) >= 0.5).astype(np.uint8), 1)
    n_ink, _ = cv2.connectedComponents(X, connectivity=8)
    n_bg, _ = cv2.connectedComponents(1 - X, connectivity=4)
    return n_ink - 1, n_bg - 1


def _partition(A: np.ndarray, n: int, eps: float = 1e-3, eps_ink: float = 1e-2) -> list:
    """A(h×w)의 행을 n개의 이어진 묶음으로 나눈다(동적 계획법). 비용 = 묶음 안 제곱 편차
    (서로 다른 행을 합치면 비쌈 → 1px 틈·1px 획이 사라지지 않음) + eps·(k-1)² (같은 행이 길게 이어진 곳을
    고르게 줄임) + eps_ink·(잃는 먹 픽셀 수) (획보다 틈·속공간을 먼저 줄여 굵기 유지)."""
    h, w = A.shape
    n = max(1, min(n, h))
    P = np.vstack([np.zeros(w), np.cumsum(A, axis=0)])
    Q = np.vstack([np.zeros(w), np.cumsum(A * A, axis=0)])
    INF = float("inf")
    best = np.full((n + 1, h + 1), INF)
    arg = np.zeros((n + 1, h + 1), int)
    best[0, 0] = 0.0
    for t in range(1, n + 1):
        for i in range(t, h - (n - t) + 1):
            for j in range(t - 1, i):
                b0 = best[t - 1, j]
                if b0 == INF:
                    continue
                k = i - j
                s = P[i] - P[j]
                var = float((Q[i] - Q[j] - s * s / k).sum())
                c = b0 + var + eps * (k - 1) ** 2 + eps_ink * (k - 1) * float(s.sum()) / k
                if c < best[t, i] - 1e-12:
                    best[t, i] = c
                    arg[t, i] = j
    out, i = [], h
    for t in range(n, 0, -1):
        j = int(arg[t, i])
        out.append((j, i))
        i = j
    return out[::-1]


def grid_fit(B: np.ndarray, n_rows: int, n_cols: int) -> np.ndarray:
    """0/1 글자를 n_rows×n_cols 로: 행·열을 통째로 합쳐(OR) 줄이고, 늘릴 때는 먹이 가장 많은 행·열을
    복제한다. 모든 획과 틈이 온 픽셀에 남는다."""
    B = B.astype(np.float64)
    if n_rows < B.shape[0]:
        B = np.stack([B[a:b].max(axis=0) for a, b in _partition(B, n_rows)])
    while B.shape[0] < n_rows:
        i = int(np.argmax(B.sum(axis=1)))
        B = np.insert(B, i, B[i], axis=0)
    if n_cols < B.shape[1]:
        B = np.stack([B[:, a:b].max(axis=1) for a, b in _partition(B.T, n_cols)], axis=1)
    while B.shape[1] < n_cols:
        i = int(np.argmax(B.sum(axis=0)))
        B = np.insert(B, i, B[:, i], axis=1)
    return B


def widen_runs(B: np.ndarray, axis: int = 1, target: int = 2) -> np.ndarray:
    """1px 먹 줄을 target px로 굵힌다. axis=1: 행 안의 가로 줄(=세로획), axis=0: 열 안의 세로 줄(=가로획).
    오른쪽(아래)을 먼저, 막히면 왼쪽(위). 채울 칸 너머가 먹이면(=1px 틈) 채우지 않으므로 틈이 막히지 않는다.
    B는 가장자리에 1px 여백이 있어야 한다(밖으로 굵어질 자리)."""
    X = (B if axis == 1 else B.T).astype(bool)
    orig = X.copy()
    out = X.copy()
    H, W = X.shape

    def empty(y, c):
        return c < 0 or c >= W or (not orig[y, c] and not out[y, c])

    for y in range(H):
        x = 0
        while x < W:
            if not orig[y, x]:
                x += 1
                continue
            x0 = x
            while x < W and orig[y, x]:
                x += 1
            x1 = x
            need = target - (x1 - x0)
            while need > 0:
                if 0 <= x1 < W and empty(y, x1) and empty(y, x1 + 1):
                    out[y, x1] = True
                    x1 += 1
                elif 0 <= x0 - 1 < W and empty(y, x0 - 1) and empty(y, x0 - 2):
                    out[y, x0 - 1] = True
                    x0 -= 1
                else:
                    break
                need -= 1
    out = out.astype(np.float64)
    return out if axis == 1 else out.T


def _source_binary(ch: str, fname: str, thr: float):
    """(0/1 글자, 먹 위 y(em 위 기준, 원본 px), 폰트, 조합 여부). 1DX 폰트에 없는 음절은 GLYPH_OVERRIDE 의
    splice(다른 1DX 음절의 행을 이어 붙임 = 조합 A+B−B′를 행 단위로 한 것)로 만든다."""
    import imgtext_bank as BK
    f = BK.bitmap_font(fname)
    ov = GLYPH_OVERRIDE.get((ch, fname), {})
    if "splice" in ov:
        parts = []
        y0 = None
        for donor, r0, r1, n in ov["splice"]:
            gd = f.glyph(donor)
            P = np.asarray(gd.cov)[r0:r1] >= thr
            if y0 is None:
                y0 = gd.y + r0
            if n:
                ys = np.nonzero(P.any(axis=1))[0]
                P = P[ys.min():ys.max() + 1]
                P = grid_fit(P, n, P.shape[1]) >= 0.5
            parts.append(P)
        B0 = np.vstack(parts)
        comp = True
        y = y0
    else:
        g = f.glyph(ch)
        comp = False
        if g is None:
            g = f.composed(ch)
            comp = True
        if g is None:
            return None
        B0 = np.asarray(g.cov) >= thr
        y = g.y
    ys, xs = np.nonzero(B0)
    return B0[ys.min():ys.max() + 1, xs.min():xs.max() + 1], y + ys.min(), f, comp


def widen_bars(B: np.ndarray, min_len: int = 5) -> np.ndarray:
    """1px 두께 가로획을 획 전체가 한꺼번에 2px가 되게 굵힌다(아래 먼저, 막히면 위).
    - 획 가운데만 굵어져 혹이 생기지 않게 획 전체 폭을 채운다.
    - 채울 칸 너머가 먹이면(=1px 틈) 그 방향은 포기한다.
    - 양옆이 먹인 칸(속공간)을 채울 때는 그 너머 행도 양옆이 막혀 있어야 한다(속공간이 한 행 남음).
      그렇지 않으면 ㅂ 윗부분·ㅅ 가지 사이 같은 한 행짜리 홈이 메워지므로 포기한다.
    - min_len(5px)보다 짧은 줄(ㅅ 다리 끝, ㅏ·ㅓ 곁줄기)은 가로획으로 보지 않는다. 이미 2px 이상이면 건드리지 않는다."""
    X = B.astype(bool)
    out = X.copy()
    H, W = X.shape

    def ink(yy, c, arr):
        return 0 <= yy < H and 0 <= c < W and arr[yy, c]

    for y in range(H):
        x = 0
        while x < W:
            if not X[y, x]:
                x += 1
                continue
            x0 = x
            while x < W and X[y, x]:
                x += 1
            x1 = x
            if x1 - x0 < min_len:
                continue
            thin = [c for c in range(x0, x1) if not ink(y - 1, c, X) and not ink(y + 1, c, X)]
            if len(thin) < 2:
                continue                # 가로획이 아니거나 이미 두꺼움
            for d in (1, -1):
                yn, yb = y + d, y + 2 * d
                if not (0 <= yn < H):
                    continue
                cells = [c for c in range(x0, x1) if not out[yn, c]]
                if not cells:
                    break
                ok = all(not ink(yb, c, out) for c in cells)
                if ok:
                    # 채울 칸을 이어진 토막으로 나눠 속공간(양옆이 먹) 검사
                    segs, c = [], None
                    for cc in cells:
                        if c is None or cc != c[1]:
                            if c is not None:
                                segs.append(c)
                            c = [cc, cc + 1]
                        else:
                            c[1] = cc + 1
                    if c is not None:
                        segs.append(c)
                    for c0, c1 in segs:
                        if ink(yn, c0 - 1, out) and ink(yn, c1, out):
                            if not (ink(yb, c0 - 1, out) and ink(yb, c1, out)):
                                ok = False
                                break
                if ok:
                    for c in cells:
                        out[yn, c] = True
                    break
    return out.astype(np.float64)


def grid_glyph(ch: str, fname: str, em_t: float | None = None, widen=(True, False), thr: float | None = None,
               extra_cols: int = 0):
    """1DX 비트맵 글자 한 자 -> 격자 맞춤 0/1 글자.
    em_t: 목표 한글 높이(px, 없으면 폰트 원래 크기). 글자의 먹 위·아래를 em 기준으로 정수 행에 맞춘다.
    열 수는 올림(세로획 2px + 틈 1px 가 들어갈 자리). widen=(세로획 2px, 가로획 2px).
    돌려줌: (0/1 덮임, 먹 위 y(em 위 기준), 폰트, 조합 여부).
    thr 없음 = GRID_THRS 중 모양(조각·속공간 수)을 지키는 가장 낮은 문턱값."""
    ov = GLYPH_OVERRIDE.get((ch, fname), {})
    if thr is None and not ({"thr", "splice", "row_groups"} & set(ov)):
        ref = _source_binary(ch, fname, GRID_THR)
        if ref is None:
            return None
        want = _topology(ref[0])
        for t in GRID_THRS:
            r = grid_glyph(ch, fname, em_t, widen, t, extra_cols)
            if t == GRID_THR or _topology(r[0]) == want:
                GRID_THR_USED[ch, fname, em_t] = t
                return r
    thr = GRID_THR if thr is None else thr
    thr = ov.get("thr", thr)
    extra_cols = ov.get("extra_cols", extra_cols)
    r = _source_binary(ch, fname, thr)
    if r is None:
        return None
    B0, top_src, f, comp = r
    s = (em_t / f.em) if em_t else 1.0
    bot_src = top_src + B0.shape[0]
    t_top = int(np.floor(top_src * s + 0.5))
    if "row_groups" in ov:
        B0 = np.stack([B0[g].max(axis=0) for g in ov["row_groups"]])
        n_rows = B0.shape[0]
    else:
        t_bot = int(np.floor(bot_src * s + 0.5)) + ov.get("extra_rows", 0)
        n_rows = max(1, t_bot - t_top)
    n_cols = max(1, int(np.ceil(B0.shape[1] * s - 1e-6)) + extra_cols)
    B = grid_fit(B0, n_rows, n_cols)
    PAD = 2
    B = np.pad(B, PAD)
    if widen[0]:
        B = widen_runs(B, 1)
    if widen[1]:
        B = widen_bars(B)
    yy, xx = np.nonzero(B)
    dy = int(yy.min()) - PAD
    B = B[yy.min():yy.max() + 1, xx.min():xx.max() + 1]
    return B, t_top + dy + ov.get("dy", 0), f, comp


GRID_THR_USED: dict = {}     # (음절, 폰트, em) -> 고른 문턱값 (make_grid 보고용)


# 음절별 조정(격자 맞춤이 모양을 깨는 글자만): (음절, 폰트) -> {thr, extra_cols, extra_rows, row_groups, splice, dy}
GLYPH_OVERRIDE = {
    # 롯: 1DX 폰트에 없음(imgtext 조합은 ㄹ 속공간이 회색으로 차 뭉개짐). 로의 ㄹ(0~7행 → 5행) + 못의 ㅗ·ㅅ받침(5~14행)
    ("롯", "font"): {"splice": [("로", 0, 8, 5), ("못", 5, 15, None)]},
    # 숍: 자동 맞춤은 ㅛ 두 행(5·6)을 따로 남겨 ㅅ이 두 겹처럼 보인다 -> ㅛ 한 행, 꼭지 3px 두 행을 한 행으로(11행)
    ("숍", "font"): {"row_groups": [[0], [1, 2], [3], [4], [5, 6], [7], [8], [9], [10, 11], [12], [13]]},
}


def compose_grid(it, pieces, fname="font", em_t=12, widen=(True, False), gap=1, align=None, left=None,
                 cy=None, dy=0):
    """pieces: [("font", text) | ("orig", x0, x1) | ("space", px)] -> 원본 크기 RGBA(흰색, 알파 0/1).
    한글: 1DX 비트맵 글자를 격자 맞춤(grid_glyph). 원본 조각(영문·&): 원래 행·열 그대로."""
    st = json.loads(OUT_STYLES.read_text(encoding="utf-8"))[it["base"]]["style"]
    jp = load(ROOT / it["png"])
    w, h = it["w"], it["h"]
    bx = st["box"]
    align = align or st["align"]
    face_jp = jp[..., 3] * (luma(jp) > 0.5)
    parts = []     # [cov, y(한글: em 위 기준 / 원본: 0), 다음 글자까지 간격, 한글?]
    info = {"sources": [], "font": fname, "em": em_t, "widen": list(widen)}
    for p in pieces:
        if p[0] == "space":
            if parts:
                parts[-1][2] += p[1]
            continue
        if p[0] == "orig":
            x0, x1 = p[1], p[2]
            parts.append([face_jp[:, x0:x1], 0, gap, False])
            info["sources"].append(("orig", x0, x1))
            continue
        srcs = []
        word_font = fname
        rs = [grid_glyph(ch, word_font, em_t, widen) for ch in p[1]]
        if any(r is None for r in rs):          # 한 낱말은 한 글꼴: 없는 음절이 있으면 낱말 전체를 다른 폰트로
            word_font = "font" if fname != "font" else "font_l"
            rs = [grid_glyph(ch, word_font, em_t, widen) for ch in p[1]]
        for ch, r in zip(p[1], rs):
            if r is None:
                raise ValueError("no glyph %s in %s" % (ch, word_font))
            cov, y, f, comp = r
            parts.append([cov, y, gap, True])
            srcs.append(ch + ("*" if comp else ""))
            info.setdefault("thr", {})[ch] = GRID_THR_USED.get(
                (ch, word_font, em_t), GLYPH_OVERRIDE.get((ch, word_font), {}).get("thr", GRID_THR))
        info["sources"].append(("grid:%s" % word_font, "".join(srcs)))
    if parts:
        parts[-1][2] = 0
    # --- vertical: 한글 먹 가운데 = 일본어 글상자 가운데 (정수 행)
    ko = [q for q in parts if q[3]]
    tops = [q[1] for q in ko]
    bots = [q[1] + q[0].shape[0] for q in ko]
    ink_h = max(bots) - min(tops)
    if cy is None:
        cy = (bx[1] + bx[3]) / 2.0
    top = int(np.floor(cy - ink_h / 2.0 + 0.5)) - min(tops) + dy
    # --- horizontal
    total = sum(q[0].shape[1] + q[2] for q in parts)
    if align == "left":
        x = left if left is not None else bx[0]
    else:
        cx = (bx[0] + bx[2]) / 2.0
        if abs(cx - w / 2) <= 1.5:
            cx = w / 2
        x = int(np.floor(cx - total / 2.0 + 0.5))
    canvas = np.zeros((h, w))
    spans = []
    for cov, y, g, isko in parts:
        yy = top + y if isko else 0
        hh, ww = cov.shape
        ya, yb = max(0, yy), min(h, yy + hh)
        xa, xb = max(0, x), min(w, x + ww)
        if yb > ya and xb > xa:
            canvas[ya:yb, xa:xb] = np.maximum(canvas[ya:yb, xa:xb], cov[ya - yy:yb - yy, xa - x:xb - x])
        spans.append((int(x), int(x + ww), bool(isko)))
        x += ww + g
    out = np.zeros((h, w, 4))
    out[..., :3] = 1.0
    out[..., 3] = np.clip(canvas, 0, 1)
    info.update({"top": top, "ink_rows": [top + min(tops), top + max(bots)], "width": total, "x_end": x,
                 "spans": spans})
    return out, info


def _words_grid(text, space):
    out = []
    for i, wd in enumerate(text.split(" ")):
        if i:
            out.append(("space", space))
        out.append(("font", wd))
    return out


PIECES_GRID = {
    "LABEL_MLRPG_00_JP_ja": [("font", "마리오"), ("orig", 36, 45), ("font", "루이지"), ("space", 4), ("orig", 93, 131)],
    "LABEL_KJRPG_00_JP_ja": [("font", "쿠파주니어"), ("space", 4), ("orig", 53, 84)],
    "btn_SLOT_00_JP_ja": [("font", "슬롯")],
}

# 격자 맞춤 설정(묶음 → 텍스처 순으로 덮어씀). em = 목표 한글 높이(1DX font em 15 기준으로 줄임)
GRID_CFG = {
    "shop_title": dict(font="font", em=13, widen=(True, True), space=4),
    "file_label": dict(font="font", em=12, widen=(True, True), space=4),
    # 슬롯은 ㅅ·ㅡ·ㄹ 세 겹이라 12px에서는 ㅅ이 막대가 된다 -> 13px, 가로획은 1px 그대로(틈 보호)
    "btn_SLOT_00_JP_ja": dict(em=13, widen=(True, False)),
}
GRID_BASES = {"SHOP_TIT_EQUIP3_00_JP_ja", "SHOP_TIT_BLODOG_00_JP_ja", "SHOP_TIT_EQUIP1_00_JP_ja",
              "SHOP_TIT_BADGE_00_JP_ja", "SHOP_TIT_BLOCK_00_JP_ja", "SHOP_TIT_BLILOCK_00_JP_ja",
              "SHOP_TIT_EQUIP2_00_JP_ja", "SHOP_TIT_ITEM_00_JP_ja",
              "LABEL_MLRPG_00_JP_ja", "LABEL_KJRPG_00_JP_ja", "btn_SLOT_00_JP_ja"}


def make_grid(it, fname=None, em_t=None, widen=None, space=None):
    cfg = dict(GRID_CFG.get(it["family"], {}))
    cfg.update(GRID_CFG.get(it["base"], {}))
    fname = fname or cfg.get("font", "font")
    em_t = em_t if em_t is not None else cfg.get("em")
    widen = tuple(widen if widen is not None else cfg.get("widen", (True, False)))
    space = space if space is not None else cfg.get("space", 4)
    pcs = PIECES_GRID.get(it["base"]) or _words_grid(it["ko"], space)
    st = json.loads(OUT_STYLES.read_text(encoding="utf-8"))[it["base"]]["style"]
    left = st["box"][0] if st["align"] == "left" else None
    rgba, info = compose_grid(it, pcs, fname=fname, em_t=em_t, widen=widen, left=left, dy=cfg.get("dy", 0))
    ko = finish(rgba, it["fmt"])
    info["stroke_px"] = round(stroke_px(ko[..., 3]), 3)
    return ko, dict(method="grid", **info)


def cmd_gridtest(outdir, variants):
    """variants: 'name:font:em:v,h' (v,h = 세로획·가로획 2px 굵히기 0/1) -> outdir/<name>/<base>.png"""
    import imgtext as T
    outdir = Path(outdir)
    B = by_base()
    rep = {}
    for v in variants:
        name, fn, em, wv = v.split(":")
        em = float(em) if em not in ("", "0", "None") else None
        wd = tuple(bool(int(x)) for x in wv.split(","))
        for base in sorted(GRID_BASES):
            it = B[base]
            ko, info = make_grid(it, fname=fn, em_t=em, widen=wd)
            jp = load(ROOT / it["png"])
            info["problems"] = T.verdict(T.compare(jp, ko))
            info["jp_stroke_px"] = round(stroke_px(jp[..., 3]), 3)
            T.save_png(ko, outdir / name / (base + ".png"))
            rep["%s/%s" % (name, base)] = info
    (outdir / "gridtest.json").write_text(json.dumps(rep, ensure_ascii=False, indent=1, default=str), encoding="utf-8")


def cmd_fixcheck(ko_dir=None, out_json=None):
    """격자 맞춤 텍스처 검사: 굵기(획 두께 비, 일본어 원본 대비·같은 그림의 원본 영문 대비), 선명함(반투명 픽셀 비율),
    흰색(먹 픽셀 밝기), 음절별 값. -> work/img/B_fixcheck.json / .txt"""
    import imgtext as T
    B = by_base()
    res, lines = {}, []
    for base in sorted(GRID_BASES):
        it = B[base]
        jp = load(ROOT / it["png"])
        kp = (Path(ko_dir) / (base + ".png")) if ko_dir else (ROOT / it["ko_png"])
        ko = load(kp)
        fj = jp[..., 3] * (luma(jp) > 0.5)
        A = ko[..., 3]
        _, info = make_grid(it)
        ink = A > 0.02
        r = {"jp_stroke": round(T.stroke_width(fj), 3), "ko_stroke": round(T.stroke_width(A), 3),
             "ink_px": int(ink.sum()), "partial_px": int((ink & (A < 0.97)).sum()),
             "ink_min_luma": round(float(luma(ko)[ink].min()), 3) if ink.any() else None}
        r["ratio"] = round(r["ko_stroke"] / max(r["jp_stroke"], 1e-6), 3)
        syl = []
        ko_mask = np.zeros_like(A, bool)
        lat_mask = np.zeros_like(A, bool)
        for x0, x1, isko in info["spans"]:
            m = np.zeros_like(A, bool)
            m[:, max(0, x0):x1] = True
            (ko_mask if isko else lat_mask)[:, max(0, x0):x1] = True
            if isko:
                sub = A * m
                e = sub > 0.02
                syl.append({"x": [x0, x1], "partial": int((e & (sub < 0.97)).sum()), "ink": int(e.sum())})
        r["hangul_partial_px"] = int(sum(s["partial"] for s in syl))
        r["hangul_stroke"] = round(T.stroke_width(A * ko_mask), 3)
        if lat_mask.any():
            r["latin_stroke_ko"] = round(T.stroke_width(A * lat_mask), 3)
            r["hangul_vs_latin"] = round(r["hangul_stroke"] / max(r["latin_stroke_ko"], 1e-6), 3)
        r["syllables"] = syl
        r["sources"] = info["sources"]
        res[base] = r
        lines.append("%-26s jp %.2f ko %.2f ratio %.2f | hangul %.2f%s | ink %d partial %d (hangul %d) minL %s" % (
            base, r["jp_stroke"], r["ko_stroke"], r["ratio"], r["hangul_stroke"],
            (" latin %.2f h/l %.2f" % (r["latin_stroke_ko"], r["hangul_vs_latin"])) if "latin_stroke_ko" in r else "",
            r["ink_px"], r["partial_px"], r["hangul_partial_px"], r["ink_min_luma"]))
    dst = Path(out_json) if out_json else ROOT / "work/img/B_fixcheck.json"
    dst.write_text(json.dumps(res, ensure_ascii=False, indent=1, default=str), encoding="utf-8")
    dst.with_suffix(".txt").write_text("\n".join(lines) + "\n", encoding="utf-8")


def cmd_trial(outdir):
    """toolkit 기본값으로 전부 그려 보기(시험, work/img/ko 에는 쓰지 않음)."""
    import imgtext as T
    outdir = Path(outdir)
    outdir.mkdir(parents=True, exist_ok=True)
    rows, rep_all = [], {}
    for it in items():
        jp = load(ROOT / it["png"])
        try:
            ko, rep = T.redraw(jp, it["ko"], fmt=it["fmt"])
        except Exception as e:  # noqa
            rep_all[it["base"]] = {"error": repr(e)}
            continue
        T.save_png(ko, outdir / (it["base"] + ".png"))
        rep_all[it["base"]] = {"sources": rep.get("sources"), "fit": rep.get("fit"), "problems": rep["problems"],
                               "wd": rep.get("weight_delta_px")}
        rows.append(("%s %s" % (it["base"], it["ko"]), [jp, ko]))
    (outdir / "trial.json").write_text(json.dumps(rep_all, ensure_ascii=False, indent=1, default=str), encoding="utf-8")
    T.make_sheet(rows, outdir / "trial.png", zoom=3)


if __name__ == "__main__":
    a = sys.argv[1:]
    if not a:
        print(__doc__)
    elif a[0] == "ga":
        cmd_ga()
    elif a[0] == "make":
        # make [--out DIR] [base ...]
        out = None
        rest = a[1:]
        if rest[:1] == ["--out"]:
            out, rest = rest[1], rest[2:]
        cmd_make(out, tuple(rest))
    elif a[0] == "review":
        cmd_review(a[1] if len(a) > 1 else None)
    elif a[0] == "fixcheck":
        cmd_fixcheck(a[1] if len(a) > 1 and a[1] != "-" else None, a[2] if len(a) > 2 else None)
    elif a[0] == "gridtest":
        cmd_gridtest(a[1], a[2:])
    elif a[0] == "tk":
        cmd_tk(a[1], tuple(a[2:]))
    elif a[0] == "cmp3":
        cmd_cmp3(a[1], a[2], a[3])
    elif a[0] == "summary":
        cmd_summary(a[1])
    elif a[0] == "segs":
        cmd_segs()
    elif a[0] == "same":
        cmd_same(a[1])
    elif a[0] == "ga_final":
        cmd_ga_final()
    elif a[0] == "trial":
        cmd_trial(a[1])
    elif a[0] == "measure":
        cmd_measure()
    elif a[0] == "zoom":
        cmd_zoom(a[1:])
