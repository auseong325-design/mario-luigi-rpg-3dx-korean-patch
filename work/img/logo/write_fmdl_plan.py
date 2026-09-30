"""Write work/img/fmdl_plan.json: every FMdl texture with letters (from the 13-sheet visual scan)."""
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
man = json.loads((ROOT / "work/img/fmdl_manifest.json").read_text("utf-8"))["3DX"]
by = {r["id"]: r for r in man}
T = "fmd_title_JP_ja/"
S = "fmd_title_start_JP_ja/"
items = [
    dict(id=T + "title_logo_JP_bottom", action="replace", jp="マリオ&ルイージRPG", ko="마리오&루이지RPG (RPG·&·실루엣은 원본)",
         family="logo", kind="나", ref_1dx="MGMap/KR mg_map_title_logo_KR_ko/ttl_c02_str_KR(+_a)",
         notes="글자 뼈대 1DX 로고, 꾸밈은 이 텍스처에서 측정(logo_lib). work/img/logo/make_bottom.py"),
    dict(id=T + "title_logo_JP_top", action="replace", jp="DX デラックス 3 ™", ko="DX 디럭스 3 ™ (DX·3·™ 원본)",
         family="logo", kind="나", ref_1dx="MGMap/KR ttl_c02_str_KR 의 「디럭스」", notes="make_top.py"),
    dict(id=T + "title_logo_M_JP", action="replace", jp="マリオ", ko="마리오", family="logo", kind="나",
         ref_1dx="ttl_c02_str_KR 「마리오」", notes="make_pieces.py"),
    dict(id=T + "title_logo_L_JP", action="replace", jp="ルイージ", ko="루이지", family="logo", kind="나",
         ref_1dx="ttl_c02_str_KR 「루이지」 (1DX 새싹 장식 제외)", notes="make_pieces.py"),
    dict(id=T + "title_logo_and_JP", action="keep", jp="&", ko="&", family="logo", notes="기호 — 원본 그대로"),
    dict(id=T + "logo_heat_01", action="keep", jp="", family="logo", notes="아지랑이 효과 텍스처(글자 없음)"),
    dict(id=T + "logo_heat_02", action="keep", jp="", family="logo", notes="아지랑이 효과 텍스처(글자 없음)"),
    dict(id=S + "st", action="replace", jp="ゲームスタート", ko="게임 시작", family="title_start", kind="나",
         ref_1dx="SLyt GAMESTART_KR_ko/btn_GAMESTART_12_KR_ko (같은 낱말)", notes="make_start.py"),
    dict(id=S + "ken", action="keep", jp="©2009-2018 Nintendo Developed by ALPHADREAM", family="title_start",
         notes="영문 저작권 표기 — 1DX도 영문"),
    dict(id=S + "title_ver", action="keep", jp="Ver. 1.2", family="title_start", notes="영문·숫자"),
    dict(id=S + "st_shadow", action="keep", jp="", family="title_start", notes="줄무늬 그림자(글자 없음)"),
    dict(id="fmd_ev_tfp_JP_ja/tfp", action="keep", jp="Thank you for playing!", family="ending",
         ref_1dx="FMdl/KR fmd_ev_tfp_KR_ko/tfp", notes="1DX 한국판과 픽셀까지 같음(1DX도 영문) — 그대로"),
    dict(id="fmd_ev_tfp_JP_ja/tfp_a", action="keep", jp="", family="ending", notes="알파 그라데이션"),
]
kari = ["fmd_o_dv_pch_catapult/cpdm", "fmd_o_dv_kpa_gera_bronze/gera_bronze_01_dm", "fmd_o_dv_kpa_gera_bronze/gera_bronze_02_dm",
        "fmd_o_dv_kpa_seesaw/seesaw_dm", "fmd_o_dv_kpa_k_chair/k_chair", "fmd_o_dv_kpa_floordoor/floordoor_dm",
        "fmd_o_dv_kpa_floordoor/floordoor_open_dm", "fmd_kks_bronze_kpa/bronze_kpa_dm"]
for k in kari:
    items.append(dict(id=k, action="keep", jp="仮", family="placeholder",
                      notes="개발용 임시(仮) 텍스처 — 어느 재질도 이 이름을 참조하지 않음(화면에 안 나옴)"))
for k in ["fmd_o_dv_ztd_board/ztd_board", "fmd_o_dv_otpk_board/otpk_boar", "fmd_o_dv_gepu_board/gepu_board",
          "fmd_o_dv_msb_board/msb_board", "fmd_o_dv_ekb_board/ekb_board", "fmd_o_dv_gepu_irongate/irongate"]:
    items.append(dict(id=k, action="keep", jp="(가상 문자)", family="sign",
                      notes="마리오&루이지 세계의 가상 문자 간판 — 일본어 아님"))
# resolve ids against the manifest (texture names may carry suffixes)
for it in items:
    hits = [r for r in man if r["id"] == it["id"] or r["id"].startswith(it["id"])]
    if hits:
        r = hits[0]
        it["id"] = r["id"]
        it.update(w=r["w"], h=r["h"], fmt=r["fmt"], copies=sum(1 for q in man if q["sha1"] == r["sha1"]))
    else:
        it["notes"] += " (manifest id not found)"
plan = dict(scanned=dict(models=len({r["model"] for r in man}), textures=len(man),
                         unique=sum(1 for r in man if "dup_of" not in r),
                         sheets="work/img/fmdl/sheets/3DX_01..13.png"),
            items=items,
            also_logo_lyt=["3DX:MLyt/MENU_FILE_LOAD_JP_ja/timg/LOAD_GAME_IMG_ML_L_00_JP_ja.bflim",
                           "3DX:MLyt/MENU_FILE_LOAD_JP_ja/timg/LOAD_GAME_IMG_ML_R_00_JP_ja.bflim",
                           "3DX:MLyt/MENU_FILE_LOAD_JP_ja/timg/LOAD_GAME_IMG_KJ_L_00_JP_ja.bflim",
                           "3DX:MLyt/MENU_FILE_LOAD_JP_ja/timg/LOAD_GAME_IMG_KJ_R_00_JP_ja.bflim"])
(ROOT / "work/img/fmdl_plan.json").write_text(json.dumps(plan, ensure_ascii=False, indent=1), "utf-8")
print(len(items), "items;", sum(1 for i in items if i["action"] == "replace"), "replace;",
      [i["id"] for i in items if "not found" in i["notes"]])
