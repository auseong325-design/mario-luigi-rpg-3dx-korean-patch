"""Full inventory of 3DX layout textures (I1): work/img/lyt_plan.json, lyt_families.json, family sheets.

    python scripts/make_lyt_plan.py           # reads work/img/lyt_plan_src.tsv (hand classification of every
                                              #   texture with text) + lyt_manifest.json + the Lyt dats
                                              # -> work/img/lyt_plan.json, work/img/lyt_families.json,
                                              #    work/img/sheets/family_<id>.png

Every one of the 1,158 unique 3DX layout textures gets one item. Textures not listed in the TSV were
checked visually on the contact sheets work/img/sheets/I1_scan_NN.png (no text) and are `keep`.
"""

from __future__ import annotations

import collections
import json
import re
import sys
from pathlib import Path

import numpy as np
from PIL import Image, ImageDraw, ImageFont

sys.path.insert(0, str(Path(__file__).resolve().parent))
from lib3dx import ROOT  # noqa: E402
import lytimg as L  # noqa: E402

IMG = ROOT / "work" / "img"
SRC = IMG / "lyt_plan_src.tsv"
FONT = ROOT / "fonts" / "NotoSansKR-Medium.otf"

# ------------------------------------------------------------------ families
# id: (description, decoration summary, difficulty 1-3)
FAMILIES = {
    "battle_btn": ("전투 화면 버튼 글자(つかう·やめる·けってい·れんしゅう·おてほん)",
                   "흰 채움 + 검은 굵은 테두리(1겹), 가운데 정렬. btn_USE만 ETC1A4", 1),
    "list_title": ("목록 제목·라벨(LTIT_*, KJ_LTIT_*, LIST_ATCMINIGAME_*) 128x16 등",
                   "흰 채움 + 얇은 검은 테두리, 왼쪽 정렬(일부 가운데), 작은 글자(약 12px)", 1),
    "list_title_faint": ("기록 화면 오른쪽 정렬 흐린 제목(ベストスコア·ベストターン)",
                         "반투명 흰 채움, 테두리 없음, 오른쪽 정렬", 1),
    "panel_label": ("미니게임 패널 라벨(もくひょうスコア·クリアじょうけん)",
                    "흰 채움 + 어두운 테두리, 가운데 정렬, 128x16", 1),
    "rank_name": ("랭크 이름 11종(RANK_NAME_*) 128x42 ETC1A4",
                  "흰 채움 + 남색 굵은 테두리 + 옅은 바깥 번짐, 기울임 없음. 원문보다 긴 것이 많아 장평 조절", 2),
    "stat_en": ("능력치 영문 라벨(STbr_*, ST_*, KJ_ST_*, EXP/LV/NEXT). BP→SP, HIGE→SUYEOM, TSUNO→PPUL만 교체",
                "흰 채움 + 검은 테두리 + 아래 그림자(픽셀 영문 글꼴). 영문 글자는 같은 판 원본 글자를 재조합", 1),
    "en_keep": ("영어 그대로 두는 글자(RANK UP!!, LEVEL UP!, PAUSE, MARIO 등)", "변경 없음", 1),
    "kj_skill": ("쿠파주니어 RPG 리더 커맨드 이름(btn_KJ_LA_*) 116x22",
                 "흰 채움 + 검은 굵은 테두리, 가운데 정렬, 약 18px. 긴 이름은 장평", 1),
    "kj_battle_btn": ("쿠파주니어 RPG 전투 버튼(やめる·ガイド) 128x26", "흰 채움 + 검은 테두리, 왼쪽/가운데", 1),
    "kj_menu_btn": ("쿠파주니어 RPG 퀘스트/메뉴 버튼(KJ_QUEST)", "흰 채움 + 검은 굵은 테두리, 가운데 정렬", 1),
    "kj_small_btn": ("쿠파주니어 RPG 편성·파티 작은 버튼 글자(78x12~108x16)",
                     "흰 채움 + 얇은 검은 테두리, 매우 작음(8~12px) → 1DX 폰트 글리프", 1),
    "kj_faint_label": ("쿠파주니어 RPG 흐린 흰 라벨(ならびかえ·てきのじょうほう)", "반투명 흰 채움, 테두리 없음", 1),
    "kj_dark_label": ("쿠파주니어 RPG 진회색 라벨(プロフィール·とじる)", "진회색 채움, 테두리 없음", 1),
    "kj_sort_btn": ("쿠파주니어 RPG 정렬 버튼(しゅぞく·レベル) 128x24", "흰 채움 + 검은 굵은 테두리", 1),
    "kj_type": ("쿠파주니어 RPG 타입 이름(とつげき·ひこう·えんきょり) 64x22", "흰 채움 + 검은 굵은 테두리. 1DX 같은 그림 있음", 1),
    "kj_label": ("쿠파주니어 RPG 결과 화면 '군단 LV' 52x28", "흰 채움 + 검은 테두리, 두 줄. 1DX 같은 그림 있음", 1),
    "guide_pnl": ("가이드 패널 두 줄 글자(MENU_GUIDE·KJ_GUIDE btn_text_*_pnl_*) 96x32",
                  "흰 채움 + 검은 굵은 테두리, 두 줄 가운데 정렬", 1),
    "record_btn": ("기록 화면 버튼(btn_p_*) 88x24/88x32", "흰 채움 + 검은 굵은 테두리, 한두 줄", 1),
    "menu_top": ("스타 메뉴 윗 항목(TOP_MENU_TEXT_1~6) 80x24", "흰 채움 + 검은 굵은 테두리. 1DX 같은 역할 그림 있음(96x24)", 1),
    "set_tab": ("설정 탭 あり/なし 96x24", "흰 채움 + 검은 굵은 테두리", 1),
    "shop_btn": ("상점 버튼(かう·うる·そうび·あとで·はい) 108x24", "흰 채움 + 검은 굵은 테두리", 1),
    "shop_top": ("상점 첫 화면 항목(shop_top_*_text) 96x22", "흰 채움 + 검은 굵은 테두리", 1),
    "shop_title": ("상점 이름(SHOP_TIT_*) 180x16", "흰 채움 + 어두운 그림자, 왼쪽 정렬, 작은 글자", 1),
    "status_label": ("능력 화면 라벨(そうびひん·ランクアップボーナス) 150x24", "흰 채움 + 검은 테두리", 1),
    "file_btn": ("파일 선택·저장 화면 버튼", "흰 채움 + 검은 굵은 테두리, 가운데 정렬", 1),
    "file_label": ("파일 선택 화면 작은 라벨(게임 이름·スロット)", "흰 채움 + 어두운 그림자, 왼쪽 정렬, 작은 글자", 1),
    "field_btn": ("필드 미니맵 열기/닫기 64x16", "흰 채움 + 검은 테두리, 오른쪽 정렬", 1),
    "minigame_btn": ("미니게임·콜로세움 버튼 글자(スタート·もういちど·ボス/きょだいか バトル·おすすめLV)",
                     "흰 채움 + 검은 굵은 테두리(일부 ETC1A4)", 1),
    "result_banner": ("결과 배너(ベストターンこうしん·ベストスコア·しょうひんGET!)",
                      "흰 채움 + 남색/검은 테두리, ETC1A4·LA4", 2),
    "logo": ("게임 로고가 든 파일 선택 그림(LOAD_GAME_IMG_*) → I4", "로고(입체·그라데이션). I4 담당", 3),
    "equip_marker": ("장착 표시 'E'(1DX도 E 유지)", "변경 없음", 1),
    "dummy": ("지역 더미 텍스처", "변경 없음", 1),
}

# second-wave distribution (families are never split); logo goes to I4
GROUPS = [
    {"id": "A", "title": "쿠파주니어 RPG 화면", "families": [
        "kj_skill", "kj_battle_btn", "kj_menu_btn", "kj_small_btn", "kj_faint_label", "kj_dark_label",
        "kj_sort_btn", "kj_type", "kj_label"]},
    {"id": "B", "title": "메뉴·상점·파일", "families": [
        "menu_top", "set_tab", "shop_btn", "shop_top", "shop_title", "status_label", "file_btn", "file_label"]},
    {"id": "C", "title": "전투·결과·미니게임", "families": [
        "battle_btn", "rank_name", "stat_en", "panel_label", "field_btn", "minigame_btn", "result_banner"]},
    {"id": "D", "title": "목록 제목·가이드·기록", "families": [
        "list_title", "list_title_faint", "guide_pnl", "record_btn"]},
]
I4_FAMILIES = ["logo"]


def base_of(r: dict) -> str:
    return r["file"].rsplit("/", 1)[-1][:-6]


def read_src() -> dict[str, dict]:
    rows = {}
    for ln in SRC.read_text("utf-8").splitlines():
        if not ln.strip() or ln.startswith("#"):
            continue
        f = ln.split("\t")
        f += [""] * (9 - len(f))
        base, action, jp, ko, basis, family, kind, ref, notes = f[:9]
        if base in rows:
            raise SystemExit(f"duplicate row {base}")
        if family not in FAMILIES:
            raise SystemExit(f"{base}: unknown family {family!r}")
        rows[base] = {"action": action, "jp": jp.replace("\\n", "\n"), "ko": ko.replace("\\n", "\n"),
                      "basis": basis, "family": family, "kind": kind, "ref_1dx": ref, "notes": notes}
    return rows


def usage() -> dict[tuple, list[str]]:
    """(dat, entry, texture base) -> layouts / animations naming it."""
    used = collections.defaultdict(list)
    for dat, entry, sarc in L.iter_sarcs("3DX"):
        files = L.sarc_list(sarc)
        texnames = [f.rsplit("/", 1)[-1][:-6] for f, _, _ in files if f.endswith(".bflim")]
        for fn, s, e in files:
            if fn.endswith((".bflyt", ".bflan")):
                blob = sarc[s:e]
                for t in texnames:
                    if (t + ".bflim").encode() in blob or (t + "\0").encode() in blob:
                        used[(dat, entry, t)].append(fn.rsplit("/", 1)[-1])
    return used


def text_box(png: Path) -> dict:
    a = np.asarray(Image.open(png).convert("RGBA"))[..., 3]
    h, w = a.shape
    ys, xs = np.nonzero(a > 40)
    if not len(xs):
        return {"x": 0, "y": 0, "w": 0, "h": 0, "align": "none"}
    x0, x1, y0, y1 = int(xs.min()), int(xs.max()) + 1, int(ys.min()), int(ys.max()) + 1
    lm, rm = x0, w - x1
    align = "center" if abs(lm - rm) <= max(2, w // 10) else ("left" if lm < rm else "right")
    return {"x": x0, "y": y0, "w": x1 - x0, "h": y1 - y0, "align": align}


def scan_index() -> dict[str, str]:
    out = {}
    p = IMG / "sheets" / "I1_scan_index.txt"
    if p.exists():
        for ln in p.read_text("utf-8").splitlines():
            i, tid = ln.split("\t")[:2]
            out[tid] = f"work/img/sheets/I1_scan_{int(i) // 48 + 1:02d}.png #{i}"
    return out


def family_sheet(fid: str, members: list[dict], man1: dict, font) -> Path:
    """Originals (with Korean target) + 1DX references, max 1600x1600 per sheet."""
    cell_w, cell_h, lab = 250, 76, 30
    refs = []
    for m in members:
        rid = m.get("ref_1dx", "")
        if rid.startswith("1DX:") and rid in man1 and rid not in refs:
            refs.append(rid)
    items = [(m["id"], ROOT / m["png"], f"{m['base']}", (m["jp"] + " → " + m["ko"]).replace("\n", "/"))
             for m in members[:36]]
    items += [(r, ROOT / man1[r]["png"], "1DX " + r.rsplit("/", 1)[-1][:-6], "(1DX 참고)") for r in refs[:6]]
    cols = 5
    rows = (len(items) + cols - 1) // cols
    sheet = Image.new("RGB", (cols * cell_w, max(1, rows) * (cell_h + lab) + 24), (40, 40, 40))
    d = ImageDraw.Draw(sheet)
    d.text((4, 2), f"family {fid}: {FAMILIES[fid][0]}"[:120], font=font, fill=(255, 255, 255))
    for k, (_id, png, l1, l2) in enumerate(items):
        im = Image.open(png).convert("RGBA")
        sc = min((cell_w - 8) / im.width, (cell_h - 8) / im.height, 3.0)
        im = im.resize((max(1, round(im.width * sc)), max(1, round(im.height * sc))),
                       Image.NEAREST if sc >= 1 else Image.LANCZOS)
        bg = Image.new("RGBA", im.size, (90, 90, 90, 255))
        for y in range(0, im.height, 6):
            for x in range((y // 6) % 2 * 6, im.width, 12):
                bg.paste((120, 120, 120, 255), (x, y, x + 6, y + 6))
        bg.alpha_composite(im)
        x, y = (k % cols) * cell_w, 24 + (k // cols) * (cell_h + lab)
        col = (140, 220, 255) if l2 == "(1DX 참고)" else (255, 230, 90)
        d.text((x + 3, y), l1[:40], font=font, fill=col)
        d.text((x + 3, y + 13), l2[:30], font=font, fill=(255, 255, 255))
        sheet.paste(bg.convert("RGB"), (x + 4, y + lab))
    assert sheet.width <= 1600 and sheet.height <= 1600, sheet.size
    out = IMG / "sheets" / f"family_{fid}.png"
    sheet.save(out)
    return out


def main() -> None:
    man = json.loads((IMG / "lyt_manifest.json").read_text("utf-8"))
    rows3 = man["3DX"]
    man1 = {r["id"]: r for r in man["1DX"]}
    sha1dx = collections.defaultdict(list)
    for r in man["1DX"]:
        sha1dx[r["sha1"]].append(r["id"])
    copies = collections.defaultdict(list)
    for r in rows3:
        copies[r["sha1"]].append(r)
    src = read_src()
    used = usage()
    scans = scan_index()
    items = []
    seen_src = set()
    for r in rows3:
        if "dup_of" in r:
            continue
        b = base_of(r)
        cp = copies[r["sha1"]]
        use = sorted({f for c in cp for f in used.get((c["dat"], c["entry"], base_of(c)), [])})
        it = {"id": r["id"], "base": b, "dat": r["dat"], "entry": r["entry"], "w": r["w"], "h": r["h"],
              "fmt": r["fmt"], "copies": len(cp), "copy_ids": [c["id"] for c in cp[1:]], "png": r["png"],
              "ko_png": f"work/img/ko/lyt/{r['dat']}/{r['entry']}/{b}.png",
              "used_by": use[:6], "identical_1dx": sha1dx.get(r["sha1"], [])[:2]}
        s = src.get(b)
        if s:
            seen_src.add(b)
            it.update(s)
            it["box"] = text_box(ROOT / r["png"])
            it["box"]["lines"] = max(1, (s["ko"] or s["jp"]).count("\n") + 1)
        else:
            it.update({"action": "keep", "jp": "", "ko": "", "basis": "", "family": None, "kind": "",
                       "ref_1dx": "", "notes": "글자 없음(육안 확인: " + scans.get(r["id"], "?") + ")"})
        items.append(it)
    missing = set(src) - seen_src
    if missing:
        raise SystemExit(f"TSV rows without a unique texture: {sorted(missing)}")

    fam = {}
    for fid, (desc, deco, diff) in FAMILIES.items():
        mem = [i for i in items if i["family"] == fid]
        rep = [i for i in mem if i["action"] == "replace"]
        rev = [i for i in mem if i["action"] == "review"]
        work = len(rep) * diff
        refs = sorted({i["ref_1dx"] for i in mem if i["ref_1dx"]})
        fam[fid] = {"id": fid, "description": desc, "decoration": deco, "difficulty": diff,
                    "textures": len(mem), "to_make": len(rep), "review": [i["id"] for i in rev],
                    "workload": work,
                    "formats": dict(collections.Counter(i["fmt"] for i in mem)),
                    "dats": sorted({i["dat"] for i in mem}), "ref_1dx": refs[:8],
                    "representative": (rep or mem or [{"id": None}])[0]["id"],
                    "members": [i["id"] for i in mem], "sheet": f"work/img/sheets/family_{fid}.png"}
    for g in GROUPS:
        g["textures_to_make"] = sum(fam[f]["to_make"] for f in g["families"])
        g["workload"] = sum(fam[f]["workload"] for f in g["families"])
    grouped = {f for g in GROUPS for f in g["families"]} | set(I4_FAMILIES)
    loose = [f for f in fam if f not in grouped and fam[f]["to_make"]]
    if loose:
        raise SystemExit(f"families with work but no group: {loose}")

    font = ImageFont.truetype(str(FONT), 11)
    for fid in fam:
        mem = [i for i in items if i["family"] == fid]
        if mem:
            family_sheet(fid, mem, man1, font)

    summary = {
        "unique_textures": len(items),
        "all_copies": len(rows3),
        "with_text": sum(1 for i in items if i["family"]),
        "replace": sum(1 for i in items if i["action"] == "replace"),
        "review": sum(1 for i in items if i["action"] == "review"),
        "keep_text": sum(1 for i in items if i["family"] and i["action"] == "keep"),
        "keep_no_text": sum(1 for i in items if not i["family"]),
        "kind": dict(collections.Counter(i["kind"] for i in items if i["action"] != "keep")),
        "copies_to_replace": sum(i["copies"] for i in items if i["action"] in ("replace", "review")),
    }
    plan = {"version": 1, "made_by": "I1 scripts/make_lyt_plan.py (source: work/img/lyt_plan_src.tsv)",
            "summary": summary,
            "groups": GROUPS + [{"id": "I4", "title": "로고(I4 담당)", "families": I4_FAMILIES,
                                  "textures_to_make": sum(fam[f]["to_make"] for f in I4_FAMILIES),
                                  "workload": sum(fam[f]["workload"] for f in I4_FAMILIES)}],
            "items": items}
    (IMG / "lyt_plan.json").write_text(json.dumps(plan, ensure_ascii=False, indent=1), "utf-8")
    (IMG / "lyt_families.json").write_text(json.dumps(fam, ensure_ascii=False, indent=1), "utf-8")
    print(json.dumps(summary, ensure_ascii=False))
    for g in plan["groups"]:
        print(g["id"], g["title"], "to make", g["textures_to_make"], "workload", g["workload"])


if __name__ == "__main__":
    main()
