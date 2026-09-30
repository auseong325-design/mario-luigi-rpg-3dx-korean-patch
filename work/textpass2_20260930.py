"""TEXT PASS 2 (2026-09-30, cloud): switch Bowser Jr. RPG terms to the 1DX KR official wording.

Source of every switch: work/review/kj_1dx_terms.md (groups A and G). Same safety rules as
work/textpass_20260930.py: the raw JSON of each batch file is edited in place (layout kept), every edit
names its exact old text and nothing is written if one is missing, and the re-parsed result must differ
only in the intended values. Glossary rows are changed in text/glossary.tsv AND text/glossary_overrides.tsv
(overrides win in scripts/build_glossary.py, so a rebuild keeps them).

  python work/textpass2_20260930.py                      dry run: writes the diff to work/textpass2_diff.txt
  python work/textpass2_20260930.py --apply              writes the files
  ... --groups terms,challenge,spacing,amiibo            only these groups (default: all four)
Groups: terms = 1DX skill/attack names, 3상성, 군단의 혼; challenge = the Bowser Jr. RPG チャレンジ feature
(도전); spacing = 쿠파7인조, 로켓 박치기, bean/chicken item names; amiibo = the standard amiibo error messages.
Then: python scripts/merge_ko.py --check-all && python scripts/merge_ko.py --merge
"""
import difflib
import json
import pathlib
import sys
from json.decoder import scanstring

ROOT = pathlib.Path(__file__).resolve().parent.parent
KO = ROOT / "text" / "ko"
GLOSS = ROOT / "text" / "glossary.tsv"
OVERRIDES = ROOT / "text" / "glossary_overrides.tsv"
STYLE = ROOT / "text" / "style_guide.md"
DIFF = ROOT / "work" / "textpass2_diff.txt"
APPLY = "--apply" in sys.argv
GROUPS_ALL = ("terms", "challenge", "spacing", "amiibo")
GROUPS = set(sys.argv[sys.argv.index("--groups") + 1].split(",")) if "--groups" in sys.argv else set(GROUPS_ALL)
if not GROUPS <= set(GROUPS_ALL):
    raise SystemExit(f"unknown group(s): {sorted(GROUPS - set(GROUPS_ALL))}")
R = "review(클라우드 2026-09-30): "

N_SUKE = R + "すけっと = 「도우미」(1DX 한국판 공식, k_sys#587 KMsg_la_name_10·#881 KGGuide_BA33·KMsgBtl_la_suketto_01 '도우미 컴온!!')."
N_YAMI = R + "やみうち = 「허 찌르기」(1DX 한국판 공식, k_sys#601 KMsg_la_name_11·#890 KGGuide_BA34, 설명 같음)."
N_MIKI = R + "みきり = 「회피」(1DX 한국판 공식 리더 액션, k_sys#106 KMsg_la_name_05·#358 KGGuide_BA28, 라벨 la_mikiri)."
N_NOUT = R + "脳天かちわり = 「정수리 깨기」(1DX 한국판 공식, k_sys#355 KMsg_cw_04·#172 KGGuide_BA04, 설명 같음)."
N_BUNN = R + "ブン投げ = 「내던지기」(1DX 한국판 공식, k_sys#371 KMsg_cw_06·#191 KGGuide_BA06 '큰 무기를 내던져')."
N_BKAM = R + "ぶちかまし = 「튕겨내기」(1DX 한국판 공식, k_sys#379 KMsg_cw_07·KGGuide_BA07, 설명 같음)."
N_TATA = R + "たたきつけ = 「내동댕이」(1DX 한국판 공식, k_sys#928 KMsg_cw_15·#724 KGGuide_BA14 '내동댕이쳐서')."
N_BNUK = R + "ぶちぬき = 「관통 공격」(1DX 한국판 공식, k_sys#4 KMsg_cw_18·#744 KGGuide_BA17, 설명 같음)."
N_ROCK = R + "ロケットずつき = 「로켓 박치기」(1DX 한국판 띄어쓰기, k_sys#346 KMsg_cw_03)."
N_SUKU = R + "３すくみ = 「3상성」(1DX 한국판 공식, k_sys#631 KGGuide_BB07·#940·#815 '이게 3상성이라는 거야')."
N_GUND = R + "軍団魂 = 「군단의 혼」(1DX 한국판 k_sys#76 'GDH는 군단의 혼…'·#443; '군단혼'은 1DX 본문에 없는 나무위키 표기)."
N_CHAL = (R + "쿠파주니어 RPG의 チャレンジ 기능 = 「도전」(1DX 한국판 k_sys#181 KGGuide_BB10 '도전에 대해'·#156 '기록과 도전'"
          "·#731 '도전 달성!'). 본편 챌린지 홀은 그대로.")
N_SEVN = R + "クッパ７人衆 = 「쿠파7인조」(1DX 한국판은 43회 모두 붙여 씀, k_sys#409 등)."
N_BEAN = R + "콩 아이템 이름은 1DX 한국판의 같은 라벨대로 띄어 씀(k_sys#30 'HP 콩', #406 '슈퍼 EXP 콩 S')."
N_CHIK = R + "치킨 아이템 이름도 같은 목록의 콩 아이템(1DX 'HP 콩', '슈퍼 EXP 콩 S')처럼 띄어 씀."
N_AMII = (R + "닌텐도 표준 amiibo 오류 문구를 1DX 한국판 ComErr.msbt에 맞춤(오류, 꺼져/켜, 떼 주십시오, 업데이트, "
          "사용설명서, 한국닌텐도 고객지원센터, 적외선 포트).")

# (id, old substring, new substring, note); dups follow their primary in merge_ko
EDITS = [
    ("BMsg/b_sys#409", "지원군", "도우미", N_SUKE),
    ("BMsg/b_sys#1726", "지원군 컴온!", "도우미 컴온!", N_SUKE),
    ("BMsg/b_sys#1745", "{2:var}, 지원군으로 와 주었다!", "{2:var}, 도우미로 와 주었다!", N_SUKE),
    ("BMsg/b_sys#1769", "적 군단에 지원군이 왔다!", "적 군단에 도우미가 왔다!", N_SUKE),
    ("BMsg/b_sys#973", "적의 지원군이 더 왔다!", "적의 도우미가 더 왔다!", N_SUKE),

    ("BMsg/b_sys#683", "기습", "허 찌르기", N_YAMI),
    ("BMsg/b_sys#1193", "간파", "회피", N_MIKI),

    ("BMsg/b_sys#490", "정수리 찍기", "정수리 깨기", N_NOUT),
    ("BMsg/b_sys#377", "주특기는 정수리 찍기", "주특기는 정수리 깨기", N_NOUT),
    ("BMsg/b_sys#1750", "빙글 돌아서 정수리 찍기.", "빙글 돌아서 정수리 깨기.", N_NOUT),

    ("BMsg/b_sys#539", "힘껏 던지기", "내던지기", N_BUNN),
    ("BMsg/b_sys#1566", "커다란 무기를 던져서", "커다란 무기를 내던져서", N_BUNN),

    ("BMsg/b_sys#1341", "들이받기", "튕겨내기", N_BKAM),

    ("BMsg/b_sys#1422", "내리치기", "내동댕이", N_TATA),
    ("BMsg/b_sys#1297", "「내리치기」다!", "「내동댕이」다!", N_TATA),
    ("BMsg/b_sys#172", "온몸으로 퍼붓는 내리치기는", "온몸으로 펼치는 내동댕이는", N_TATA),
    ("BMsg/b_sys#1583", "힘차게 내리쳐서", "힘차게 내동댕이쳐서", N_TATA),
    ("BMsg/b_sys#1612", "일제히 내리쳐요.", "일제히 내동댕이쳐요.", N_TATA),

    ("BMsg/b_sys#591", "꿰뚫기", "관통 공격", N_BNUK),
    ("BMsg/b_sys#1061", "꿰뚫기가 강력하지만", "관통 공격이 강력하지만", N_BNUK),

    ("BMsg/b_sys#1361", "로켓박치기", "로켓 박치기", N_ROCK),
    ("BMsg/b_sys#31", "로켓박치기가 특기이고", "로켓 박치기가 특기이고", N_ROCK),

    ("BMsg/b_sys#384", "삼각 상성에 대해", "3상성에 대해", N_SUKU),
    ("BMsg/b_sys#1526", "이 삼각 상성이", "이 3상성이", N_SUKU),
    ("BMsg/b_sys#839", "{6:color}삼각 상성{7:color}", "{6:color}3상성{7:color}", N_SUKU),
    ("FMsg/k_o_koopa_r_80#27", "삼각 상성을 이루고", "3상성을 이루고", N_SUKU),

    ("BMsg/b_sys#711", "GDH는 군단혼{2:color}", "GDH는 군단의 혼{2:color}", N_GUND),
    ("BMsg/b_sys#1141", "쿠파 군단혼이다!", "쿠파 군단의 혼이다!", N_GUND),
    ("FMsg/k_o_koopa_80#36", "쿠파 군단혼{1:pause}", "쿠파 군단의 혼{1:pause}", N_GUND),
    ("FMsg/k_o_koopa_r_80#262", "{5:color}군단혼{6:color}", "{5:color}군단의 혼{6:color}", N_GUND),
    ("FMsg/k_o_koopa_r_80#50", "쿠파주니어님의 군단혼!", "쿠파주니어님의 군단의 혼!", N_GUND),

    ("MenuKJ#17", "챌린지 달성!", "도전 달성!", N_CHAL),
    ("MenuKJ#19", "{4:color}챌린지{5:color}에서", "{4:color}도전{5:color}에서", N_CHAL),
    ("BMsg/b_sys#17", "{1:color}챌린지{2:color}에서", "{1:color}도전{2:color}에서", N_CHAL),
    ("BMsg/b_sys#316", "챌린지 조건을 클리어하면", "도전 조건을 클리어하면", N_CHAL),
    ("BMsg/b_sys#337", "챌린지의 내용이나\n어떤 챌린지를 달성했는지 등은\n기록의 챌린지에서",
     "도전 내용이나\n어떤 도전을 달성했는지 등은\n기록의 도전에서", N_CHAL),
    ("BMsg/b_sys#1407", "챌린지에 대해", "도전에 대해", N_CHAL),
    ("BMsg/b_sys#1599", "기록과 챌린지", "기록과 도전", N_CHAL),
]
EDITS += [(mid, "쿠파 7인조", "쿠파7인조", N_SEVN) for mid in [
    "BMsg/b_sys#193", "BMsg/b_sys#375", "BMsg/b_sys#485", "BMsg/b_sys#581", "BMsg/b_sys#817", "BMsg/b_sys#1624",
    "BMsg/b_sys#1650", "BMsg/b_sys#1669", "FMsg/k_o_ekubon_80#9", "FMsg/k_o_gepu_13#24", "FMsg/k_o_koopa_39#0",
    "FMsg/k_o_zutsuda_80#7"]]
# item names (whole value); the N_/Ns_ twin of each is a dup of the one listed
ITEMS = {
    "BMsg/b_sys#72": ("HP콩", "HP 콩"), "BMsg/b_sys#959": ("POW콩", "POW 콩"), "BMsg/b_sys#395": ("DEF콩", "DEF 콩"),
    "BMsg/b_sys#565": ("SPEED콩", "SPEED 콩"), "BMsg/b_sys#1314": ("GDH콩", "GDH 콩"),
    "BMsg/b_sys#807": ("슈퍼EXP콩S", "슈퍼 EXP 콩 S"), "BMsg/b_sys#723": ("슈퍼EXP콩M", "슈퍼 EXP 콩 M"),
    "BMsg/b_sys#704": ("슈퍼EXP콩L", "슈퍼 EXP 콩 L"), "BMsg/b_sys#960": ("슈퍼EXP콩DX", "슈퍼 EXP 콩 DX"),
    "BMsg/b_sys#517": ("돌격EXP콩S", "돌격 EXP 콩 S"), "BMsg/b_sys#418": ("돌격EXP콩M", "돌격 EXP 콩 M"),
    "BMsg/b_sys#396": ("돌격EXP콩L", "돌격 EXP 콩 L"), "BMsg/b_sys#1537": ("돌격EXP콩DX", "돌격 EXP 콩 DX"),
    "BMsg/b_sys#734": ("원거리EXP콩S", "원거리 EXP 콩 S"), "BMsg/b_sys#622": ("원거리EXP콩M", "원거리 EXP 콩 M"),
    "BMsg/b_sys#602": ("원거리EXP콩L", "원거리 EXP 콩 L"), "BMsg/b_sys#257": ("원거리EXP콩DX", "원거리 EXP 콩 DX"),
    "BMsg/b_sys#1107": ("비행EXP콩S", "비행 EXP 콩 S"), "BMsg/b_sys#1017": ("비행EXP콩M", "비행 EXP 콩 M"),
    "BMsg/b_sys#997": ("비행EXP콩L", "비행 EXP 콩 L"), "BMsg/b_sys#1416": ("비행EXP콩DX", "비행 EXP 콩 DX"),
    "BMsg/b_sys#789": ("HP치킨", "HP 치킨"), "BMsg/b_sys#73": ("POW치킨", "POW 치킨"), "BMsg/b_sys#71": ("DEF치킨", "DEF 치킨"),
    "BMsg/b_sys#760": ("SPEED치킨", "SPEED 치킨"), "BMsg/b_sys#759": ("GDH치킨", "GDH 치킨"),
    "BMsg/b_sys#397": ("EXP치킨S", "EXP 치킨 S"), "BMsg/b_sys#256": ("EXP치킨M", "EXP 치킨 M"),
    "BMsg/b_sys#244": ("EXP치킨L", "EXP 치킨 L"), "BMsg/b_sys#115": ("EXP치킨DX", "EXP 치킨 DX"),
}
EDITS += [(mid, old, new, N_CHIK if "치킨" in old else N_BEAN) for mid, (old, new) in ITEMS.items()]
EDITS += [
    ("Menu#113", "{3:color}OFF{4:color}로 되어 있어서\namiibo를 사용할 수 없습니다.\n무선 통신을 {5:color}ON{6:color}으로 해 주십시오.",
     "{3:color}꺼져{4:color} 있어\namiibo를 사용할 수 없습니다.\n무선 통신을 {5:color}켜{6:color} 주십시오.", N_AMII),
    ("Menu#120", "\n에러가 발생했습니다.", "\n오류가 발생했습니다.", N_AMII),
    ("Menu#131", "본체의 적외선 송수신부와", "본체의 적외선 포트와", N_AMII),
    ("Menu#143", "{5:choice}업데이트하기{6:pause}", "{5:choice}업데이트{6:pause}", N_AMII),
    ("Menu#144", "{4:color}에서 떼어 주십시오.", "{4:color}에서 떼 주십시오.", N_AMII),
    ("Menu#160", "{4:color}에서 떼어 주십시오.", "{4:color}에서 떼 주십시오.", N_AMII),
    ("Menu#159", "적외선 통신 에러가 발생했습니다.\n본체의 전원을 끈 다음\n다시 시도해 주십시오.{3:wait}[Next]{4:mode}{5:align}"
                 "증상이 해결되지 않을 때는\n본체 취급설명서에 기재된\n닌텐도 서비스 센터로 문의해 주십시오.",
     "적외선 통신 오류가 발생했습니다.\n본체 전원을 껐다가\n다시 시도해 주십시오.{3:wait}[Next]{4:mode}{5:align}"
     "이 증상이 계속될 경우\n본체 사용설명서에 기재되어 있는\n한국닌텐도 고객지원센터로 문의해 주십시오.", N_AMII),
    ("Menu#177", "전원을 끈 다음 다시 시도해 주십시오.{8:wait}[Next]{9:mode}{10:align}증상이 해결되지 않을 때는\n"
                 "본체 취급설명서에 기재된\n닌텐도 서비스 센터로 문의해 주십시오.",
     "전원을 껐다가 다시 시도해 주십시오.{8:wait}[Next]{9:mode}{10:align}이 증상이 계속될 경우\n"
     "본체 사용설명서에 기재되어 있는\n한국닌텐도 고객지원센터로 문의해 주십시오.", N_AMII),
]

C = "클라우드 2026-09-30"
GLOSS_ROWS = {
    "すけっと": ["すけっと", "도우미", "ability", "official", "1DX-KR:BMsg.dat:k_sys#587",
                f"RPG1 DX 한국판 헤이호 대장 스킬명(k_sys#587 KMsg_la_name_10, #881 KGGuide_BA33, 전투 KMsgBtl_la_suketto_01 "
                f"'도우미 컴온!!'). 「がすけっとに来てくれた！」→'가 도우미로 와 주었다!' [gl_kj; {C}, 예전 신조어 '지원군']"],
    "やみうち": ["やみうち", "허 찌르기", "ability", "official", "1DX-KR:BMsg.dat:k_sys#601",
                f"RPG1 DX 한국판 부끄부끄 대장 스킬명(k_sys#601 KMsg_la_name_11, #890 KGGuide_BA34, 라벨 la_yamiiuchi) "
                f"[gl_kj; {C}, 예전 신조어 '기습']"],
    "みきり": ["みきり", "회피", "ability", "official", "1DX-KR:BMsg.dat:k_sys#106",
              f"RPG1 DX 한국판 리더 액션명(k_sys#106 KMsg_la_name_05, #358 KGGuide_BA28, 라벨 la_mikiri). "
              f"장신구 みきりグラス는 '간파안경'(따로 행) [gl_kj; {C}, 예전 신조어 '간파']"],
    "脳天かちわり": ["脳天かちわり", "정수리 깨기", "attack", "official", "1DX-KR:BMsg.dat:k_sys#355",
                  f"RPG1 DX 한국판 공격명(k_sys#355 KMsg_cw_04, #172 KGGuide_BA04, 설명 같음) [gl_kj; {C}, 예전 신조어 '정수리 찍기']"],
    "ブン投げ": ["ブン投げ", "내던지기", "attack", "official", "1DX-KR:BMsg.dat:k_sys#371",
                f"RPG1 DX 한국판 공격명(k_sys#371 KMsg_cw_06, #191 KGGuide_BA06 '큰 무기를 내던져') [gl_kj; {C}, 예전 신조어 '힘껏 던지기']"],
    "ぶちかまし": ["ぶちかまし", "튕겨내기", "attack", "official", "1DX-KR:BMsg.dat:k_sys#379",
                 f"RPG1 DX 한국판 공격명(k_sys#379 KMsg_cw_07, KGGuide_BA07, 설명 같음) [gl_kj; {C}, 예전 신조어 '들이받기']"],
    "たたきつけ": ["たたきつけ", "내동댕이", "attack", "official", "1DX-KR:BMsg.dat:k_sys#928",
                 f"RPG1 DX 한국판 공격명(k_sys#928 KMsg_cw_15, #724 KGGuide_BA14 '내동댕이쳐서'). 동사 叩きつける는 '내동댕이치다' "
                 f"[gl_kj; {C}, 예전 신조어 '내리치기']"],
    "ぶちぬき": ["ぶちぬき", "관통 공격", "attack", "official", "1DX-KR:BMsg.dat:k_sys#4",
                f"RPG1 DX 한국판 공격명(k_sys#4 KMsg_cw_18, #744 KGGuide_BA17, 설명 같음) [gl_kj; {C}, 예전 신조어 '꿰뚫기']"],
    "ロケットずつき": ["ロケットずつき", "로켓 박치기", "attack", "official", "1DX-KR:BMsg.dat:k_sys#346",
                   f"RPG1 DX 한국판 공격명(k_sys#346 KMsg_cw_03, #163 KGGuide_BA03) [gl_kj; {C}, 예전 '로켓박치기']"],
    "３すくみ": ["３すくみ", "3상성", "term", "official", "1DX-KR:BMsg.dat:k_sys#631",
               f"RPG1 DX 한국판(k_sys#631 KGGuide_BB07 '3상성에 대해', #940, #815 '이게 3상성이라는 거야'). 가위바위보식 상성 "
               f"[gl_kj; {C}, 예전 신조어 '삼각 상성']"],
    "軍団魂": ["軍団魂", "군단의 혼", "term", "official", "1DX-KR:BMsg.dat:k_sys#76",
             f"RPG1 DX 한국판(k_sys#76 KGGuide_BB05_6 'GDH는 군단의 혼…', #443 '군단의 혼을 보여주겠어!!'). GDD=GDH는 이 말의 머리글자 "
             f"[gl_kj; {C}, 예전 '군단혼'(나무위키 표기, 1DX 본문에 없음)]"],
    "クッパ軍団魂": ["クッパ軍団魂", "쿠파 군단의 혼", "term", "official", "1DX-KR:BMsg.dat:k_sys#76",
                 f"軍団魂=군단의 혼(1DX) + クッパ軍団=쿠파 군단(DS) [gl_kj; {C}, 예전 '쿠파 군단혼']"],
    "クッパ７人衆": ["クッパ７人衆", "쿠파7인조", "character", "official", "1DX-KR:BMsg.dat:k_sys#409",
                  f"RPG1 DX 한국판은 43회 모두 붙여 씀(KMsgChr_exp_lemmy 등 7인 설명, KMsg_quest_65 '쿠파군단 VS 쿠파7인조', "
                  f"KMsg_b_skill_38 '우리는 쿠파7인조!'). 3DX 원문에 'コクッパ'는 나오지 않음 [gl_kj; {C}, 예전 '쿠파 7인조'(나무위키)]"],
    "チャレンジ": ["チャレンジ", "챌린지", "term", "DS", "FEvent#28A.60",
                 "챌린지 홀 등 이름은 '챌린지'. 일반 '도전하다' 뜻(もう１度 チャレンジ)은 DS대로 '도전'. 쿠파주니어 RPG의 チャレンジ 기능"
                 f"(기록·달성 알림·가이드)은 1DX 한국판 공식 '도전'(k_sys#181 KGGuide_BB10 '도전에 대해', #731 '도전 달성!') [{C}]"],
    "取扱説明書": ["取扱説明書", "사용설명서", "ui", "official", "1DX-KR:ComErr.msbt#25",
                f"닌텐도 표준 문구 '본체 사용설명서에 기재되어 있는'(1DX ComErr#25·#26) [gl_kj; {C}, 예전 추정 '취급설명서']"],
    "任天堂サービスセンター": ["任天堂サービスセンター", "한국닌텐도 고객지원센터", "ui", "official", "1DX-KR:ComErr.msbt#25",
                      f"닌텐도 표준 문구 '한국닌텐도 고객지원센터로 문의해 주십시오'(1DX ComErr#25·#26) [gl_kj; {C}, 예전 추정 '닌텐도 서비스 센터']"],
    "赤外線受発光部": ["赤外線受発光部", "적외선 포트", "ui", "official", "1DX-KR:ComErr.msbt#9",
                  f"닌텐도 표준 문구 '본체의 적외선 포트에'(1DX ComErr#9) [gl_kj; {C}, 예전 신조어 '적외선 송수신부']"],
}
BEANS = {"HPマメ": ("HP 콩", 30), "POWマメ": ("POW 콩", 751), "DEFマメ": ("DEF 콩", 197), "SPEEDマメ": ("SPEED 콩", 538),
         "GDDマメ": ("GDH 콩", 947)}
for size, idx in {"S": (406, 257, 366, 546), "M": (356, 206, 315, 495), "L": (347, 198, 305, 483),
                  "DX": (465, 786, 139, 720)}.items():
    for (jp, ko), i in zip([("スーパー", "슈퍼"), ("トツゲキ", "돌격"), ("エンキョリ", "원거리"), ("ヒコウ", "비행")], idx):
        BEANS[f"{jp}EXPマメ{size}"] = (f"{ko} EXP 콩 {size}", i)
for jp, (ko, i) in BEANS.items():
    GLOSS_ROWS[jp] = [jp, ko, "item", "official", f"1DX-KR:BMsg.dat:k_sys#{i}",
                      f"RPG1 DX 한국판 같은 라벨(N_/Ns_Item*)의 표기, 띄어 씀 [gl_kj; {C}, 예전 DS식 붙여 쓰기]"]
CHICKENS = {"HPチキン": "HP 치킨", "POWチキン": "POW 치킨", "DEFチキン": "DEF 치킨", "SPEEDチキン": "SPEED 치킨",
            "GDDチキン": "GDH 치킨", "EXPチキンS": "EXP 치킨 S", "EXPチキンM": "EXP 치킨 M", "EXPチキンL": "EXP 치킨 L",
            "EXPチキンDX": "EXP 치킨 DX"}
for jp, ko in CHICKENS.items():
    GLOSS_ROWS[jp] = [jp, ko, "item", "coined", "BMsg/b_sys (3DX 신규)",
                      f"1DX에 없는 아이템. 같은 목록의 콩 아이템(1DX 'HP 콩', '슈퍼 EXP 콩 S')처럼 띄어 씀 [gl_kj; {C}]"]

STYLE_EDITS = [("terms", "軍団魂은 `군단혼`, GDD는 `GDH`.", "軍団魂은 `군단의 혼`(1DX 한국판), GDD는 `GDH`.")]

NOTE_GROUP = {N_SUKE: "terms", N_YAMI: "terms", N_MIKI: "terms", N_NOUT: "terms", N_BUNN: "terms", N_BKAM: "terms",
              N_TATA: "terms", N_BNUK: "terms", N_SUKU: "terms", N_GUND: "terms", N_CHAL: "challenge",
              N_ROCK: "spacing", N_SEVN: "spacing", N_BEAN: "spacing", N_CHIK: "spacing", N_AMII: "amiibo"}
GLOSS_GROUP = {**{jp: "terms" for jp in ["すけっと", "やみうち", "みきり", "脳天かちわり", "ブン投げ", "ぶちかまし", "たたきつけ",
                                          "ぶちぬき", "３すくみ", "軍団魂", "クッパ軍団魂"]},
               "チャレンジ": "challenge", "ロケットずつき": "spacing", "クッパ７人衆": "spacing",
               **{jp: "spacing" for jp in list(BEANS) + list(CHICKENS)},
               **{jp: "amiibo" for jp in ["取扱説明書", "任天堂サービスセンター", "赤外線受発光部"]}}


def enc(s: str) -> str:
    return json.dumps(s, ensure_ascii=False)[1:-1]


def region(text: str, key: str) -> tuple[int, int]:
    """Span of the top-level object `key` ("translations" / "notes"): from its '{' to the matching '}'."""
    i = text.find(f'"{key}":')
    if i < 0:
        return -1, -1
    j = text.index("{", i)
    depth, k, in_str = 0, j, False
    while k < len(text):
        c = text[k]
        if in_str:
            if c == "\\":
                k += 2
                continue
            if c == '"':
                in_str = False
        elif c == '"':
            in_str = True
        elif c == "{":
            depth += 1
        elif c == "}":
            depth -= 1
            if depth == 0:
                return j, k
        k += 1
    raise ValueError(f"unbalanced object {key}")


def value_span(text: str, key: str, lo: int, hi: int) -> tuple[int, int] | None:
    """(start of the opening quote, index after the closing quote) of the string value of `key` in [lo, hi)."""
    pat = json.dumps(key, ensure_ascii=False) + ":"
    i = text.find(pat, lo, hi)
    if i < 0:
        return None
    q = text.index('"', i + len(pat))
    _, end = scanstring(text, q + 1)
    return q, end


def edit_file(text: str, edits: list[tuple]) -> str:
    for mid, old, new, note in edits:
        t0, t1 = region(text, "translations")
        span = value_span(text, mid, t0, t1)
        raw = text[span[0]:span[1]]
        if raw.count(enc(old)) != 1:
            raise SystemExit(f"{mid}: old text found {raw.count(enc(old))} times in the raw value: {old!r}")
        text = text[:span[0]] + raw.replace(enc(old), enc(new)) + text[span[1]:]

        n0, n1 = region(text, "notes")
        if n0 < 0:
            raise SystemExit(f"{mid}: file has no notes object")
        nspan = value_span(text, mid, n0, n1)
        if nspan:  # append to the existing note, just before its closing quote
            text = text[:nspan[1] - 1] + enc(" " + note) + text[nspan[1] - 1:]
        else:      # new first entry of notes, indented like the entry that follows (or the object's own indent + 1)
            after = text[n0 + 1:n1]
            if after.strip():
                line = after.split("\n")[1] if after.startswith("\n") else after
                indent = line[:len(line) - len(line.lstrip())]
                text = text[:n0 + 1] + f"\n{indent}\"{enc(mid)}\": \"{enc(note)}\"," + text[n0 + 1:]
            else:
                text = text[:n0 + 1] + f"\"{enc(mid)}\": \"{enc(note)}\"" + text[n0 + 1:]
    return text


def tsv_rows(text: str, rows: dict[str, list[str]], append_missing: bool) -> tuple[str, set[str]]:
    """Replace the lines of `rows` (keyed by jp) in a TSV text; append the missing ones if asked."""
    lines = text.split("\n")
    seen = set()
    for i, line in enumerate(lines):
        jp = line.split("\t", 1)[0]
        if jp in rows:
            if jp in seen:
                raise SystemExit(f"two rows for {jp}")
            seen.add(jp)
            lines[i] = "\t".join(rows[jp])
    if append_missing:
        tail = [] if lines[-1] else [lines.pop()]
        lines += ["\t".join(rows[jp]) for jp in rows if jp not in seen] + tail
    return "\n".join(lines), seen


def main():
    ids = [e[0] for e in EDITS]
    if len(ids) != len(set(ids)):
        raise SystemExit("an id is listed twice")
    if set(GLOSS_ROWS) != set(GLOSS_GROUP) or any(e[3] not in NOTE_GROUP for e in EDITS):
        raise SystemExit("every edit and glossary row needs a group")
    edits = [e for e in EDITS if NOTE_GROUP[e[3]] in GROUPS]
    rows = {jp: r for jp, r in GLOSS_ROWS.items() if GLOSS_GROUP[jp] in GROUPS}
    style = [(old, new) for g, old, new in STYLE_EDITS if g in GROUPS]
    by_id = {e[0]: e for e in edits}
    changed = {}
    for p in sorted(KO.glob("*.json")):
        if p.name.startswith("_"):
            continue
        text = p.read_text(encoding="utf-8")
        d = json.loads(text)
        tr = d.get("translations") or {}
        mine = [by_id.pop(mid) for mid in list(by_id) if mid in tr]
        if not mine:
            continue
        new_text = edit_file(text, mine)
        d2 = json.loads(new_text)
        for mid, old, new, note in mine:
            if d2["translations"][mid] != tr[mid].replace(old, new):
                raise SystemExit(f"{p.name} {mid}: result differs from the intended value")
            if note not in d2["notes"][mid]:
                raise SystemExit(f"{p.name} {mid}: note missing")
        done = {m[0] for m in mine}
        if {k: v for k, v in d2["translations"].items() if k not in done} != {k: v for k, v in tr.items() if k not in done}:
            raise SystemExit(f"{p.name}: unintended translation change")
        changed[p] = (text, new_text)
    if by_id:
        raise SystemExit(f"ids not found in any batch file: {sorted(by_id)}")

    g_text = GLOSS.read_text(encoding="utf-8")
    g_new, seen = tsv_rows(g_text, rows, append_missing=False)
    if seen != set(rows):
        raise SystemExit(f"glossary rows missing: {sorted(set(rows) - seen)}")
    changed[GLOSS] = (g_text, g_new)
    o_text = OVERRIDES.read_text(encoding="utf-8")
    changed[OVERRIDES] = (o_text, tsv_rows(o_text, rows, append_missing=True)[0])

    s_text = STYLE.read_text(encoding="utf-8")
    s_new = s_text
    for old, new in style:
        if s_new.count(old) != 1:
            raise SystemExit(f"style guide: {old!r} found {s_new.count(old)} times")
        s_new = s_new.replace(old, new)
    changed[STYLE] = (s_text, s_new)

    diff_lines = []
    for p, (old, new) in changed.items():
        diff_lines += list(difflib.unified_diff(old.splitlines(), new.splitlines(), str(p.relative_to(ROOT)),
                                                str(p.relative_to(ROOT)), n=0, lineterm=""))
        if APPLY:
            p.write_text(new, encoding="utf-8")
    DIFF.write_text("\n".join(diff_lines) + "\n", encoding="utf-8")
    print(f"diff: {len(diff_lines)} lines -> {DIFF.relative_to(ROOT)}")
    print(f"{'APPLIED' if APPLY else 'DRY RUN'} groups {','.join(g for g in GROUPS_ALL if g in GROUPS)}: "
          f"{len(edits)} message edits in {len(changed) - 3} batch files, "
          f"{len(rows)} glossary rows (glossary.tsv + overrides), {len(style)} style-guide line(s)")


if __name__ == "__main__":
    main()
