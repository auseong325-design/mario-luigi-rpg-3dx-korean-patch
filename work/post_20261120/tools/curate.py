"""Cut the 3DS screens out of chosen raw captures and file them under images/ with readable names.

Raw captures are 1613x760 window grabs (top 633x380 above a centred bottom 506x380). Each pick is saved as the
two screens stacked (633x760, the usual 3DS layout); dialogue picks also get a top-screen-only copy.
"""
import sys
from pathlib import Path
from PIL import Image

POST = Path(__file__).resolve().parents[1]
RAW, IMG = POST / 'raw', POST / 'images'
PICKS = {
    '01_3dx_main': [
        ('3dx/010_title', '01_타이틀', False), ('3dx/intro_04', '02_인트로_로고', True),
        ('3dx/020_after_A', '03_파일선택', False), ('3dx/040_mode', '04_모드선택_본편', False),
        ('3dx/041_mode_kj', '05_모드선택_쿠파주니어', False),
        ('3dx/story_5', '10_대사_엄마저왔어요', True), ('3dx/story_7', '11_대사_어왔니', True),
        ('3dx/story_8', '12_대사_느타리선생님', True), ('3dx/story_11', '13_대사_훌륭한키노피오', True),
        ('3dx/story_27', '14_대사_까악여보', True), ('3dx/story_31', '15_내레이션_퉁퉁데굴병', False),
        ('3dx/story_47', '16_대사_끔찍합니다', True), ('3dx/story_54', '17_대사_고민할시간', True),
        ('3dx/story_61', '18_대사_스타의정령', True), ('3dx/story_64', '19_대사_엘로스타', True),
        ('3dx/story_69', '20_대사_퉁퉁데굴병문제', True), ('3dx/story_79', '21_대사_우리도마찬가지', True),
        ('3dx/story_82', '22_대사_닥터오키노', True),
        ('3dx/080_field', '30_필드_쿠파', False), ('3dx/060_star_menu', '31_스타메뉴', False),
        ('3dx/062_menu_item', '32_아이템', False), ('3dx/064_menu_gear', '33_장비', False),
        ('3dx/065_menu_status', '34_스테이터스', False), ('3dx/066_menu_badge', '35_배지', False),
        ('3dx/068_menu_guide_open', '36_가이드', False), ('3dx/081_saveblock', '37_저장', False),
    ],
    '02_3dx_bowser_jr': [
        ('3dx/kj_1', '01_대사_큰일입니다쿠파님', True), ('3dx/kj_16', '02_대사_주니어의장난', True),
        ('3dx/kj_38', '03_대사_데굴데굴', True), ('3dx/kj_50', '04_쿠파_불꽃', True),
        ('3dx/kj_52', '05_대사_피치성으로', True), ('3dx/kj_64', '06_대사_깜지롱', True),
        ('3dx/kj_66', '07_대사_슬림마초큐티', True), ('3dx/kj_75', '08_대사_SS컴퍼니', True),
        ('3dx/kj_82', '09_대사_앞으로6번', True), ('3dx/kj_100', '10_전투_START', True),
        ('3dx/kj_102', '11_전투_체력을0으로', True), ('3dx/kj_111', '12_전투_내동댕이', True),
        ('3dx/kj_112', '13_전투_가이드추가', True), ('3dx/kj_122', '14_전투_CLEAR', True),
        ('3dx/kj_125', '15_대사_10번이길때까지', True),
    ],
    '03_1dx_korean_reference': [
        ('1dx/010_title', '01_1DX_타이틀', False), ('1dx/story_1', '02_1DX_대사_콩글리아', True),
        ('1dx/story_5', '03_1DX_대사_선물', True), ('1dx/story_17', '04_1DX_대사_카하하', True),
        ('1dx/story_27', '05_1DX_대사_임시뉴스', True), ('1dx/story_30', '06_1DX_대사_마리오님', True),
    ],
}


def screens(path):
    img = Image.open(path).convert('RGB')
    w, h = img.size
    scale = min(w / 400, h / 480)
    sh = round(240 * scale); oy = round((h - 2 * sh) / 2)
    tw = round(400 * scale); tx = round((w - tw) / 2)
    bw = round(320 * scale); bx = round((w - bw) / 2)
    top = img.crop((tx, oy, tx + tw, oy + sh))
    bottom = img.crop((bx, oy + sh, bx + bw, oy + 2 * sh))
    both = Image.new('RGB', (tw, 2 * sh), (0, 0, 0))
    both.paste(top, (0, 0)); both.paste(bottom, ((tw - bw) // 2, sh))
    return both, top


def main():
    sheet = []
    for folder, picks in PICKS.items():
        out = IMG / folder; out.mkdir(parents=True, exist_ok=True)
        for f in out.glob('*.png'): f.unlink()
        for raw, name, dialogue in picks:
            src = RAW / f'{raw}.png'
            if not src.exists():
                head, _, num = raw.rpartition('_'); src = RAW / f'{head}_{int(num):02d}.png'
            both, top = screens(src)
            both.save(out / f'{name}.png', optimize=True)
            if dialogue:
                top.save(out / f'{name}_위화면.png', optimize=True)
            sheet.append((folder, name, both))
    if '--sheet' in sys.argv:
        cols, tw, th = 8, 210, 252
        s = Image.new('RGB', (cols * tw, ((len(sheet) + cols - 1) // cols) * th), 'white')
        for k, (_, _, im) in enumerate(sheet):
            s.paste(im.resize((tw - 6, th - 6)), ((k % cols) * tw, (k // cols) * th))
        s.save(POST / '_peek.png')
    print(len(sheet), 'picks')


if __name__ == '__main__':
    main()
