"""Inventory of every 3DX Obj/JP sprite with text (IMAGE_TASK.md 5장 I3-3) -> work/img/obj_plan.json

    python scripts/libobj_plan.py      # writes the plan, with status taken from work/img/obj_ko/

Every object of BUI/FUI/KUI/Menu was looked at frame by frame (survey sheets
work/img/review/I3_survey_*.png). Objects not listed here have no text (icons, characters, digits,
button glyphs A/B/X/Y/L/R/START, gauges, cursors).

action : replace = make Korean pixels / keep = text that stays (English kept like 1DX, or digits) /
         review = unclear whether the game shows it; left as is, listed for the lead
method : donor = 1DX Korean frame copied (libobj_ko.py job) / imgtext = drawn with I2's toolkit /
         pixel = rebuilt from original sprite pixels (libobj_ko.py fn job) / none
kind   : 가 (1DX same sprite) / 나 (1DX same role, other look: 1DX letters, 3DX decoration) / 다 (3DX only)
"""

from __future__ import annotations

import json
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import libobj  # noqa: E402

ROOT = libobj.ROOT
PLAN = ROOT / "work" / "img" / "obj_plan.json"
KO = ROOT / "work" / "img" / "obj_ko"


def E(dat, obj, frames, action, jp, ko="", basis="", kind="", method="none", ref_1dx="", notes=""):
    return dict(dat=dat, obj=obj, frames=frames, action=action, jp=jp, ko=ko, basis=basis, kind=kind,
                method=method, ref_1dx=ref_1dx, notes=notes)


B, F, K, M = "BUI", "FUI", "KUI", "Menu"
R_BAD = "BUI/bui_sys_badstatname_KR_ko"
R_BLK = "BUI/bui_sys_block_name_KR_ko"
R_BTN = "BUI/bui_sys_button_KR_ko"
BLK_NOTE = ("글자 높이·획 = 같은 묶음 1DX 복사본(점프·해머·아이템·도망가기) 중앙값(em 13px, 획 2.2px), "
            "채움·테두리 = 복사본(흰 채움, 갈색 2px), 너비 한도 = 묶음에서 가장 넓은 일본어 상자(x 18~109)")
TOUCH = "タッチペンを\nとりだしてください"
BODY = "本体をタテに\nもちかえてください"

ITEMS = [
    # ---------------------------------------------------------------- BUI
    E(B, "bui_challenge_JP_ja", [0], "keep", "CHALLENGE START!", basis="영어 원문, 1DX 대응 없음",
      notes="리드 확인: 영어 유지"),
    E(B, "bui_gameover_JP_ja", [0], "keep", "GAME OVER", basis="1DX bui_gameover_KR_ko도 영어", kind="가",
      ref_1dx="BUI/bui_gameover_KR_ko f0"),
    E(B, "bui_score_JP_ja", [11], "replace", "コレメーター", "콜레미터", "glossary:コレメーター(coined)", "다",
      "imgtext", notes="점프점프헬멧 미니게임 거리 게이지 제목. 숫자 f0-9·빈 막대 f10은 그대로"),
    E(B, "bui_sys_badstatname_JP_ja", [0], "replace", "ころび", "꽈당",
      "1DX bui_sys_badstatname_KR_ko f0(공식 표기) — 리드 결정 2026-09-30, 용어집 coined 「넘어짐」 대신", "가",
      "donor", R_BAD + " f0", "대사의 「넘어짐」 2줄은 리드가 고침"),
    E(B, "bui_sys_badstatname_JP_ja", [1], "replace", "めまわし", "어질어질", "glossary:めまわし(DS)", "가",
      "donor", R_BAD + " f1"),
    E(B, "bui_sys_badstatname_JP_ja", [2], "replace", "やけど", "화상", "glossary:やけど(DS)", "가", "donor",
      R_BAD + " f2"),
    E(B, "bui_sys_badstatname_JP_ja", [3], "replace", "かぜ", "감기", "glossary:かぜ(DS)", "나", "imgtext", R_BAD),
    E(B, "bui_sys_badstatname_JP_ja", [4, 5, 6, 7, 8, 9], "keep", "POW / DEF / SPEED", basis="1DX도 영어",
      kind="가", ref_1dx=R_BAD + " f4-9"),
    E(B, "bui_sys_badstatname_JP_ja", [10], "replace", "どく", "독", "glossary:どく", "가", "donor", R_BAD + " f10"),
    E(B, "bui_sys_badstatname_JP_ja", [11], "replace", "いかり", "분노", "glossary:いかり(DS); ko_final Item#79", "나",
      "imgtext", R_BAD),
    E(B, "bui_sys_badstatname_JP_ja", [12], "replace", "ひっさつ", "필살", "glossary:ひっさつ(DS); ko_final Item#463",
      "나", "imgtext", R_BAD),
    E(B, "bui_sys_block_name_JP_ja", [0], "replace", "ジャンプ", "점프", "ko_final Menu#408; glossary", "가", "donor",
      R_BLK + " f0"),
    E(B, "bui_sys_block_name_JP_ja", [1], "replace", "ハンマー", "해머", "ko_final Menu#69; glossary", "가", "donor",
      R_BLK + " f1"),
    E(B, "bui_sys_block_name_JP_ja", [2], "replace", "ブラザーアタック", "스페셜 어택", "glossary:ブラザーアタック(DS)", "나",
      "imgtext", R_BLK + " f3(브라더 어택)",
      "리드 확인: 1DX 그림은 '브라더 어택'이지만 용어집·게임 번역은 '스페셜 어택'. " + BLK_NOTE),
    E(B, "bui_sys_block_name_JP_ja", [3], "replace", "アイテム", "아이템", "ko_final Menu#541", "가", "donor",
      R_BLK + " f4"),
    E(B, "bui_sys_block_name_JP_ja", [4], "replace", "にげる", "도망가기", "glossary:にげる(DS)", "가", "donor",
      R_BLK + " f5"),
    E(B, "bui_sys_block_name_JP_ja", [5], "replace", "パンチ", "펀치", "ko_final Menu#424; glossary", "나", "imgtext",
      R_BLK, BLK_NOTE),
    E(B, "bui_sys_block_name_JP_ja", [6], "replace", "ファイア", "파이어", "ko_final Menu#764; glossary", "나",
      "imgtext", R_BLK, BLK_NOTE),
    E(B, "bui_sys_block_name_JP_ja", [7], "replace", "ボコスカアタック", "스페셜 어택", "glossary:ボコスカアタック(확정)", "나",
      "imgtext", R_BLK, BLK_NOTE),
    E(B, "bui_sys_block_name_JP_ja", [9], "replace", "バキューム", "배큐엄", "glossary:バキューム(DS)", "나", "imgtext",
      R_BLK, BLK_NOTE),
    E(B, "bui_sys_block_name_JP_ja", [10], "replace", "ガイド", "가이드", "glossary:ガイド; lyt btn_KJ_GUIDE", "나",
      "imgtext", R_BLK, BLK_NOTE),
    E(B, "bui_sys_block_name_JP_ja", [11], "replace", "ヒント", "힌트", "ko_final BMsg/b_sys#1180", "나", "imgtext",
      R_BLK, BLK_NOTE),
    E(B, "bui_sys_button_JP_ja", [0, 1], "replace", "もどる", "뒤로", "1DX 같은 버튼(뒤로); 선택지 번역 もどる→뒤로", "나",
      "imgtext", R_BTN + " f0/f1",
      "1DX는 글자 뒤에 어두운 막대가 있어 디자인이 달라 글자만 1DX에서. 리드 확인: b_sys#1821은 '돌아가기'"),
    E(B, "bui_sys_button_JP_ja", [2], "replace", "イージーモード", "이지 모드", "ko_final BMsg/b_sys#603", "나", "imgtext",
      R_BTN + " f2"),
    E(B, "bui_sys_button_JP_ja", [3, 4], "replace", "きんきゅうガード", "긴급 가드", "ko_final BMsg/b_sys#1129", "나",
      "imgtext", R_BTN + " f3/f4"),
    E(B, "bui_sys_button_JP_ja", [5], "replace", "なんいど", "난이도", "1DX bui_sys_button_KR_ko f5", "나", "imgtext",
      R_BTN + " f5", "1DX는 나무판 디자인. 글자만 1DX"),
    E(B, "bui_sys_button_JP_ja", [6, 7], "replace", "ふつう", "보통", "1DX bui_sys_button_KR_ko f6/f7", "나", "imgtext",
      R_BTN + " f6/f7", "1DX 글자(넓게 띄어 있음)를 자간 -3px로 좁혀 「쉬움」과 같은 간격(두 음절 사이 빈 열 0)"),
    E(B, "bui_sys_button_JP_ja", [8, 9], "replace", "かんたん", "쉬움", "1DX bui_sys_button_KR_ko f8/f9", "나",
      "imgtext", R_BTN + " f8/f9"),
    E(B, "bui_sys_button_JP_ja", [10, 11], "replace", "れんしゅうモードへ", "연습 모드", "1DX f10/f11; glossary:れんしゅう", "나",
      "imgtext", R_BTN + " f10/f11"),
    E(B, "bui_sys_button_JP_ja", [12, 13], "replace", "おてほんモードへ", "시범 모드", "1DX f12/f13; glossary:おてほん", "나",
      "imgtext", R_BTN + " f12/f13"),
    E(B, "bui_sys_button_JP_ja", [14, 15, 18, 19], "replace", "おてほん", "시범", "glossary:おてほん(DS)", "다",
      "imgtext", R_BTN + " f12(시범)"),
    E(B, "bui_sys_button_JP_ja", [16, 17, 20], "replace", "れんしゅう", "연습", "glossary:れんしゅう(DS)", "다",
      "imgtext", R_BTN + " f10(연습)"),
    E(B, "bui_sys_dam_JP_ja", [34, 36, 38], "keep", "TOTAL / LUCKY / CRITICAL", basis="1DX도 영어", kind="가",
      ref_1dx="BUI/bui_sys_dam_KR_ko f34/36/38"),
    E(B, "bui_sys_font_JP_ja", [0, 1, 2, 3, 4], "keep", "MISS... / OK / GOOD! / GREAT! / EXCELLENT!",
      basis="1DX도 영어", kind="가", ref_1dx="BUI/bui_sys_font_KR_ko"),
    E(B, "bui_touch_start_JP_ja", [0, 1, 2, 3], "replace", TOUCH, "터치펜을\n꺼내 주세요",
      "coined(터치펜: ko_final FMsg/i_areanone_puzzle_02_L#14)", "다", "imgtext",
      notes="START는 영어 유지. 같은 그림이 FUI·Menu에도 있음"),
    E(B, "bui_tuto_JP_ja", [0], "replace", "おてほん", "시범", "glossary:おてほん", "가", "donor",
      "BUI/bui_tuto_KR_ko f0"),
    E(B, "bui_tuto_JP_ja", [1], "replace", "おてほん(강조)", "시범", "glossary:おてほん", "나", "pixel",
      "BUI/bui_tuto_KR_ko f0",
      "f0과 같은 1DX 글자·크기·위치, 채움만 3DX f0→f1처럼 노랑(파랑 채널 ×68/255, 3DX f1 채움 100% 재현), 테두리 그대로"),
    # ---------------------------------------------------------------- FUI
    E(F, "fui_bodyrot_JP_ja", [0], "replace", BODY, "본체를 세로로\n바꿔 들어 주세요", "coined", "다", "imgtext",
      notes="Menu/m_bodyrot_JP_ja와 같은 그림"),
    E(F, "fui_end_JP_ja", list(range(12)), "keep", "THE END", basis="영어 원문, 1DX 대응 없음",
      notes="리드 확인: 영어 유지"),
    E(F, "fui_touch_start_JP_ja", [0, 1, 2, 3], "replace", TOUCH, "터치펜을\n꺼내 주세요", "coined", "다", "imgtext",
      notes="BUI와 같은 그림"),
    E(F, "fui_button", [16, 17], "keep", "START", basis="본체 버튼 이름(1DX fu_button_push도 START)", kind="가"),
    # ---------------------------------------------------------------- KUI
    E(K, "ko_ui_bonusskill_JP_ja", [0], "review", "(ボーナス スキル 모양의 회색 덩어리)", "보너스 스킬",
      basis="1DX ko_ui_bonusskill_KR_ko", ref_1dx="KUI/ko_ui_bonusskill_KR_ko f0",
      notes="3DX 그림에는 글자 없이 단색 실루엣만 있음(RGB 136 한 값). 화면에 쓰이지 않는 것으로 보고 그대로 둠. 리드 확인"),
    E(K, "ko_ui_fall_JP_ja", [0], "review", "(おとす 모양 실루엣)", "떨어트리기", ref_1dx="KUI/ko_ui_fall_KR_ko f0",
      notes="단색 실루엣만. 그대로 둠. 리드 확인"),
    E(K, "ko_ui_wakeup_JP_ja", [0], "review", "(おこす 모양 실루엣)", "일어나기", ref_1dx="KUI/ko_ui_wakeup_KR_ko f0",
      notes="단색 실루엣만. 그대로 둠. 리드 확인"),
    E(K, "ko_ui_miss_JP_ja", [0], "review", "(MISS... 모양 실루엣)", notes="단색 실루엣만(영어). 그대로 둠"),
    E(K, "ko_ui_change_JP_ja", [0], "replace", "きりかえ", "전환", "ko_final Menu#396(きりかえる→전환)", "나",
      "imgtext", "KUI/ko_ui_fall_KR_ko(같은 흰 글자 모양)"),
    E(K, "ko_ui_return_JP_ja", [0], "replace", "もどす", "되돌리기", "coined(もどす)", "나", "imgtext",
      "KUI/ko_ui_fall_KR_ko"),
    E(K, "ko_ui_onemore_JP_ja", [0], "replace", "けってい", "결정", "ko_final BMsg/b_sys#151; glossary", "나",
      "imgtext", "KUI/ko_ui_fall_KR_ko"),
    E(K, "ko_ui_onemore_JP_ja", [1], "replace", "もういちど", "다시 한번", "ko_final Menu#433; lyt btn_restart", "나",
      "imgtext", "KUI/ko_ui_fall_KR_ko"),
    E(K, "ko_ui_special_JP_ja", [11], "replace", "あと", "앞으로", "ko_final FMsg/k_o_koopa_14#132(あと７回→앞으로 7번)",
      "다", "imgtext", notes="남은 횟수/시간 앞에 붙는 말. 리드 확인: '남은'도 후보"),
    E(K, "ko_ui_special_JP_ja", [10], "keep", "TIME", basis="영어 원문"),
    E(K, "ko_ui_jump_JP_ja", [0], "replace", "ジャンプ", "점프", "ko_final Menu#408", "가", "donor",
      "KUI/ko_ui_jump_KR_ko f0"),
    E(K, "ko_ui_statname_JP_ja", [8, 9], "replace", "めいちゅう", "명중", "glossary:めいちゅう", "가", "donor",
      "KUI/ko_ui_statname_KR_ko f8/f9"),
    E(K, "ko_ui_statname_JP_ja", [10, 11], "replace", "かいひ", "회피", "glossary:かいひ", "가", "donor",
      "KUI/ko_ui_statname_KR_ko f10/f11"),
    E(K, "ko_ui_statname_JP_ja", [0, 1, 2, 3, 4, 5], "keep", "POW / DEF / SPEED", basis="영어(1DX도 같음)",
      kind="가", ref_1dx="KUI/ko_ui_statname_KR_ko f0-5"),
    E(K, "ko_ui_statname_JP_ja", [6, 7], "replace", "GDD", "GDH",
      "리드 결정(22:05); 대사·레이아웃 KJ_ST_GDD도 GDH; 1DX ko_ui_statname_KR_ko f6/f7", "나", "pixel",
      "KUI/ko_ui_statname_KR_ko f6/f7",
      "G·D는 3DX 픽셀 그대로, H는 같은 픽셀 글꼴의 1DX GDH에서(1DX 갈색 테두리 → 3DX 검정, 공통 G·D에서 배운 색 대응)"),
    E(K, "ko_ui_fukubikiblock_JP_ja", [13, 14], "replace", "めいちゅう", "명중", "glossary", "가", "donor",
      "KUI/ko_ui_fukubikiblock_KR_ko f10/f11"),
    E(K, "ko_ui_fukubikiblock_JP_ja", [15, 16], "replace", "かいひ", "회피", "glossary", "가", "donor",
      "KUI/ko_ui_fukubikiblock_KR_ko f12/f13"),
    E(K, "ko_ui_fukubikiblock_JP_ja", [23], "replace", "とつげき\nダメージ", "돌격\n대미지", "glossary:とつげき; 1DX 같은 그림",
      "가", "donor", "KUI/ko_ui_fukubikiblock_KR_ko f20",
      "리드 확인: 용어집 ダメージ=타격(숫자 문맥 대미지 허용). 1DX 같은 스프라이트는 '대미지'"),
    E(K, "ko_ui_fukubikiblock_JP_ja", [24], "replace", "ひこう\nダメージ", "비행\n대미지", "glossary:ひこう; 1DX", "가",
      "donor", "KUI/ko_ui_fukubikiblock_KR_ko f21"),
    E(K, "ko_ui_fukubikiblock_JP_ja", [25], "replace", "えんきょり\nダメージ", "원거리\n대미지", "glossary:えんきょり; 1DX",
      "가", "donor", "KUI/ko_ui_fukubikiblock_KR_ko f22"),
    E(K, "ko_ui_fukubikiblock_JP_ja", [26], "replace", "ぜんたい\nダメージ", "전체\n대미지", "1DX 같은 그림", "가", "donor",
      "KUI/ko_ui_fukubikiblock_KR_ko f19", "리드 확인: 용어집 ぜんたい=전부(대상 선택 UI)"),
    E(K, "ko_ui_fukubikiblock_JP_ja", [5, 6, 7, 8, 22], "keep", "POW / DEF / EXP", basis="1DX도 영어", kind="가"),
    E(K, "ko_ui_clear_JP_ja", [0, 1, 2], "keep", "CLEAR!! / QUEST COMPLETE!! / YOU ARE A SUPER PLAYER!!",
      basis="1DX ko_ui_clear_KR_ko(CLEAR!!)도 영어", kind="가", notes="리드 확인: 나머지 둘은 1DX 대응 없음, 영어 유지"),
    E(K, "ko_ui_entry_JP_ja", [0], "keep", "E", basis="1DX도 같음", kind="가"),
    E(K, "ko_ui_font_JP_ja", [0, 1, 2, 3, 4], "keep", "MISS... / OK / GOOD! / GREAT! / EXCELLENT!", basis="1DX도 영어",
      kind="가"),
    E(K, "ko_ui_luckyouch_JP_ja", [0, 1, 2, 3], "keep", "LUCKY! / OUCH! / CRITICAL", basis="1DX도 영어", kind="가"),
    E(K, "ko_ui_okexcellent_JP_ja", [0, 1], "keep", "OK / EXCELLENT!", basis="1DX도 영어", kind="가"),
    E(K, "ko_ui_start_JP_ja", [10, 11, 12], "keep", "BATTLE / FINAL BATTLE / START!", basis="1DX도 영어", kind="가"),
    E(K, "ko_ui_winlose_JP_ja", [0, 1, 2], "keep", "WIN! / LOSE... / PERFECT!", basis="1DX도 영어", kind="가"),
    E(K, "ko_ui_lvup_JP_ja", [10], "review", "(빈 판)", notes="1DX는 LEVEL UP! 3DX는 글자 없는 판. 그대로"),
    E(K, "ko_ui_number_JP_ja", [10], "review", "(빈 칸)", notes="1DX는 LV. 3DX는 글자 없음. 그대로"),
    # ---------------------------------------------------------------- Menu
    E(M, "m_bodyrot_JP_ja", [0], "replace", BODY, "본체를 세로로\n바꿔 들어 주세요", "coined", "다", "imgtext",
      notes="FUI/fui_bodyrot_JP_ja와 같은 그림"),
    E(M, "m_touch_start_JP_ja", [0, 1, 2, 3], "replace", TOUCH, "터치펜을\n꺼내 주세요", "coined", "다", "imgtext"),
    E(M, "m_item_ev_all", [22, 24, 26, 28, 30, 34, 36, 38, 40, 42, 44], "review",
      "ビリリンパ / バキューム / スター赤·青·黄 / マグナムキラー / 1~5 (손글씨 빨간 칸)",
      notes="개발용 임시 그림으로 보임(빨간 테두리 손글씨). 그대로 둠. 리드 확인"),
]


def status(it) -> str:
    """made = every frame of the entry is covered by a job in work/img/obj_ko/_jobs.json."""
    if it["method"] == "none":
        return "-"
    jf = KO / "_jobs.json"
    done = set()
    if jf.exists():
        for j in json.loads(jf.read_text("utf-8")):
            if j["dat"] == it["dat"] and j["obj"] == it["obj"]:
                done |= set(j["frames"])
    return "made" if set(it["frames"]) <= done else "todo"


def main() -> None:
    items = []
    for it in ITEMS:
        it = dict(it)
        it["id"] = f"{it['dat']}/{it['obj']}/" + ",".join(f"f{f:03d}" for f in it["frames"])
        it["status"] = status(it)
        items.append(it)
    summ = {}
    for it in items:
        summ.setdefault(it["action"], 0)
        summ[it["action"]] += 1
    rep = [i for i in items if i["action"] == "replace"]
    out = {"version": 1, "made_by": "I3 scripts/libobj_plan.py",
           "note": __doc__.strip(),
           "summary": {"entries": len(items), **summ,
                       "replace_frames": sum(len(i["frames"]) for i in rep),
                       "replace_by_method": {m: sum(1 for i in rep if i["method"] == m)
                                             for m in ("donor", "imgtext", "pixel")},
                       "replace_objects": len({(i["dat"], i["obj"]) for i in rep})},
           "items": items}
    PLAN.write_text(json.dumps(out, ensure_ascii=False, indent=1), "utf-8")
    print(json.dumps(out["summary"], ensure_ascii=False))


if __name__ == "__main__":
    main()
