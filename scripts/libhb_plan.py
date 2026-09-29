"""Measure the style of every Japanese-text texture of the giant-battle UI and write the plan.

    python scripts/libhb_plan.py      -> work/img/hb_plan.json, work/img/hb_erase/<name>.png

Every HB text texture is a free-standing word: light fill + dark outline on a transparent
texture (no plate behind it), so erasing the Japanese = clearing the whole texture to
transparent while keeping the RGB of the original (ETC1A4 encodes colour under alpha 0 too).
"""
from __future__ import annotations

import json
import sys
from pathlib import Path

import numpy as np
from PIL import Image
from scipy import ndimage

sys.path.insert(0, str(Path(__file__).resolve().parent))
from lib3dx import ROOT  # noqa: E402

IMG = ROOT / "work" / "img"

# texture -> (Japanese, Korean, source of the Korean word, lines)
WORDS = {
    "s_ui_cyorometer_distance": ("チョロメートル", "쪼르미터", "HugeBattle#69 「약 100쪼르미터!」"),
    "s_ui_cyorometer_station": ("駅まで", "역까지", "HugeBattle#69 「다리 앞 역까지의 거리는…」"),
    "i_ui_demoskip01a": ("スキップ", "건너뛰기", "HugeBattle#108 「배틀을 건너뛰고」"),
    "ja_sentaku_yes": ("はい", "예", "선택지 표준 (Menu#157 등 「아니요/예」)"),
    "ja_sentaku_no": ("いいえ", "아니요", "선택지 표준 (Menu#157 등 「아니요/예」)"),
    "ja_mukaeute_text": ("むかえうて！", "맞받아쳐!", "HugeBattle#6 「액션으로 맞받아쳐요」 (명령형)"),
    "ja_slide_text": ("スライド！", "슬라이드!", "glossary スライド=슬라이드"),
    "ja_renzoku_slide_text": ("れんぞくスライド！", "연속 슬라이드!", "連続=연속 (b_sys#523 연속 밟기) + 슬라이드"),
    "ja_touch_text": ("タッチ！", "터치!", "glossary タッチ=터치"),
    "hayaku_slide_text": ("はやくスライド！", "빠르게 슬라이드!", "HugeBattle#112 「빠르게 슬라이드할수록 강력!」"),
    "ja_renda_touch_text": ("れんだタッチ！", "연타 터치!", "HugeBattle#45 「연타 터치와」"),
    "ja_kaiten_slide_text": ("かいてんスライド！", "회전 슬라이드!", "HugeBattle#45 「회전 슬라이드 조작으로」"),
    "ja_battleskip_text": ("バトルをスキップする", "배틀 건너뛰기", "HugeBattle#108 「배틀을 건너뛰고」 (메뉴 항목형)"),
    "ja_easymode_text": ("イージーモードでやりなおす", "이지 모드로 다시 시작", "b_sys#116 / glossary"),
    "ja_kettei_text": ("けってい", "결정", "b_sys#151 Retry_easymode_enter"),
    "ja_modoru_text": ("もどる", "돌아가기", "b_sys#1821 Retry_easymode_back"),
    "ja_title_text": ("タイトルにもどる", "타이틀로 돌아가기", "b_sys#1694 Retry_item_back_to_title"),
    "ja_yarinaosu_text": ("やりなおす", "다시 시작", "b_sys#1398 Retry_item_retry"),
    "ja_e_ui_boss_rotation_text": ("本体をヨコに\nもちかえてください", "본체를 가로로\n바꿔 들어 주세요", "신규(대사 번역에 없음)"),
    "ja_e_ui_boss_button_text": ("タッチペンを\nとりだしてください", "터치펜을\n꺼내 주세요", "glossary タッチペン=터치펜 + 신규"),
}
ENGLISH = {"text_comment_get01a": "GET!", "text_comment_win01a": "WIN!", "s_ui_boss_button_start02a": "START",
           "text_comment_excellent_01a": "EXCELLENT!", "text_comment_great_01a": "GREAT!",
           "text_comment_good_01a": "GOOD!", "text_comment_ok_01a": "OK", "text_comment_miss_01a": "MISS..."}


def measure(rgba: np.ndarray) -> dict:
    a = rgba[..., 3].astype(float)
    lum = rgba[..., :3].astype(float) @ [0.299, 0.587, 0.114]
    ink = a > 96
    fill = ink & (lum > 150)
    outline = ink & ~fill
    ys, xs = np.nonzero(a > 8)
    fy, fx = np.nonzero(fill)
    d = ndimage.distance_transform_edt(~fill)
    thick = float(np.percentile(d[outline], 90)) if outline.any() else 0.0
    # stroke width of the fill: 2 * max inner distance along the medial axis (median of local maxima)
    din = ndimage.distance_transform_edt(fill)
    loc = (din == ndimage.maximum_filter(din, 3)) & (din > 0)
    stroke = float(2 * np.median(din[loc])) if loc.any() else 0.0
    # fill colour by row (gradient check)
    rows = []
    for y in range(fy.min(), fy.max() + 1):
        m = fill[y] & (din[y] >= 1.0)
        if m.sum() >= 2:
            rows.append([int(v) for v in rgba[y][m][:, :3].mean(0)])
    oc = rgba[outline & (d >= 1.5)][:, :3].mean(0) if (outline & (d >= 1.5)).any() else rgba[outline][:, :3].mean(0)
    # lines: horizontal gaps in the fill projection
    proj = fill.any(1)
    runs, y = [], 0
    while y < len(proj):
        if proj[y]:
            y0 = y
            while y < len(proj) and proj[y]:
                y += 1
            if y - y0 >= 3:
                runs.append([y0, y - 1])
        y += 1
    cx = (xs.min() + xs.max()) / 2
    return {
        "ink_box": [int(xs.min()), int(ys.min()), int(xs.max()), int(ys.max())],
        "fill_box": [int(fx.min()), int(fy.min()), int(fx.max()), int(fy.max())],
        "lines": len(runs), "line_rows": runs,
        "fill_height": int(fy.max() - fy.min() + 1),
        "align": "center" if abs(cx - (rgba.shape[1] - 1) / 2) <= 3 else ("left" if cx < rgba.shape[1] / 2 else "right"),
        "outline_px": round(thick, 2), "stroke_px": round(stroke, 2),
        "fill_top": rows[0] if rows else None, "fill_mid": rows[len(rows) // 2] if rows else None,
        "fill_bottom": rows[-1] if rows else None,
        "outline_rgb": [int(v) for v in oc],
        "soft_edge": bool(((a > 8) & (a < 200)).sum() > 0.1 * (a > 8).sum()),
    }


def main():
    man = json.loads((IMG / "hb" / "_manifest.json").read_text("utf-8"))
    items = []
    (IMG / "hb_erase").mkdir(parents=True, exist_ok=True)
    done = set()
    for r in man:
        name = r["name"]
        it = {"id": r["id"], "arc": r["arc"], "name": name, "fmt": r["fmt"], "w": r["w"], "h": r["h"],
              "png": r["png"], "hash": r["hash"]}
        if "dup_of" in r:
            it["dup_of"] = r["dup_of"]
        if name in WORDS:
            jp, ko, basis = WORDS[name]
            rgba = np.array(Image.open(ROOT / r["png"]).convert("RGBA"))
            it.update({"action": "replace", "jp": jp, "ko": ko, "ko_basis": basis, "family": "hb_white_outline",
                       "kind": "다", "ref_1dx": None, "box": measure(rgba)})
            if name not in done:
                er = rgba.copy()
                er[..., 3] = 0
                Image.fromarray(er, "RGBA").save(IMG / "hb_erase" / f"{name}.png")
                it["erased_png"] = f"work/img/hb_erase/{name}.png"
                done.add(name)
        elif name in ENGLISH:
            it.update({"action": "keep", "jp": ENGLISH[name], "ko": ENGLISH[name],
                       "notes": "영어 원문 — 0장 규칙: 1DX에 대응 없음 → 영어 유지, 리드 확인"})
        else:
            it.update({"action": "keep", "notes": "글자 없음(아이콘·숫자·판·효과)"})
        items.append(it)
    fam = {"hb_white_outline": {"desc": "흰~연회색 채움 + 검은 테두리(1.5~4px), 투명 배경의 낱말 텍스처(ETC1A4)",
                                "count": len(done), "difficulty": 1}}
    out = {"items": items, "families": fam,
           "summary": {"textures": len(items), "replace": sum(i["action"] == "replace" for i in items),
                       "replace_unique": len(done), "keep_english": sum(i.get("name") in ENGLISH for i in items),
                       "bch_textures_checked": "work/img/hb_bch/_manifest.json (431 unique, no text)"}}
    (IMG / "hb_plan.json").write_text(json.dumps(out, ensure_ascii=False, indent=1), "utf-8")
    print(json.dumps(out["summary"], ensure_ascii=False))


if __name__ == "__main__":
    main()
