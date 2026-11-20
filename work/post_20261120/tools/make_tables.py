"""Comparison sheets for the post: Japanese original / DS Korean release / this patch, and 1DX Korean terms.

Reads only project data (text/jp, text/ref_ds_ko/FEvent.json, work/ko_final.json, work/review/triage.json,
text/glossary.tsv, work/review/kj_1dx_pairs.tsv). Writes work/post_20261120/images/04_translation/*.png.
"""
import csv
import json
import re
from collections import Counter
from pathlib import Path

from PIL import Image, ImageDraw, ImageFont

ROOT = Path(__file__).resolve().parents[3]
OUT = ROOT / 'work' / 'post_20261120' / 'images' / '04_translation'
FONTS = Path(r'C:\Windows\Fonts')
KO = lambda size, bold=False: ImageFont.truetype(str(FONTS / ('malgunbd.ttf' if bold else 'malgun.ttf')), size)
JP = lambda size: ImageFont.truetype(str(FONTS / 'YuGothM.ttc'), size)
INK, SUB, LINE, HEAD, BG, CARD = '#1A1D23', '#5B6472', '#E3E6EC', '#3B5BDB', '#F3F4F7', '#FFFFFF'
TAG = {'ds': ('DS 그대로', '#178A54', '#E4F6EC'), 'edited': ('DS를 고침', '#A86200', '#FFF3DC'),
       'new': ('새로 번역', '#3B5BDB', '#EEF2FF'), '1dx': ('1DX 공식', '#7A3BDB', '#F3ECFF')}


def clean(text, jp=False):
    text = re.sub(r'\[Ruby ([^;\]]*);[^\]]*\]', r'\1', text)
    text = re.sub(r'\[Next\]', ' / ', text)
    text = re.sub(r'\[[^\]]*\]|\{[^}]*\}', '', text)
    text = text.replace('\n', ' ' if not jp else '')
    return re.sub(r'\s+', ' ', text).strip(' /')


def load():
    jp = {}
    for path in (ROOT / 'text' / 'jp').glob('*.json'):
        for m in json.loads(path.read_text(encoding='utf-8'))['messages']:
            jp[m['id']] = m['jp']
    ds = {}
    for room in json.loads((ROOT / 'text' / 'ref_ds_ko' / 'FEvent.json').read_text(encoding='utf-8')):
        for m in room['messages']:
            ds[f"DS{room['room']}#{m['i']}"] = m['ko']
    ko = json.loads((ROOT / 'work' / 'ko_final.json').read_text(encoding='utf-8'))
    triage = {}
    for batch in json.loads((ROOT / 'work' / 'review' / 'triage.json').read_text(encoding='utf-8'))['batches'].values():
        triage.update(batch['msgs'])
    return jp, ds, ko, triage


def wrap(draw, text, font, width):
    lines, line = [], ''
    for ch in text:
        if draw.textlength(line + ch, font=font) > width and line:
            cut = line.rfind(' ')
            if cut > len(line) * 0.6:
                lines.append(line[:cut]); line = line[cut + 1:] + ch
            else:
                lines.append(line); line = ch
        else:
            line += ch
    return lines + ([line] if line else [])


def sheet(title, subtitle, headers, widths, rows, out, note=''):
    """rows: list of (cells, tag) where tag is a TAG key or None."""
    pad, gap, W = 48, 22, 48 * 2 + sum(widths) + 22 * (len(widths) - 1)
    probe = ImageDraw.Draw(Image.new('RGB', (10, 10)))
    fonts = [JP(22) if h.startswith('일본') else KO(22) for h in headers]
    laid = []
    for cells, tag in rows:
        wrapped = [wrap(probe, c, f, w - (150 if i == len(cells) - 1 and tag else 0)) for i, (c, f, w) in enumerate(zip(cells, fonts, widths))]
        laid.append((wrapped, tag, max(len(x) for x in wrapped) * 34 + 26))
    H = 150 + 56 + sum(h for *_, h in laid) + (70 if note else 40)
    img = Image.new('RGB', (W, H), BG)
    d = ImageDraw.Draw(img)
    d.text((pad, 34), title, font=KO(38, True), fill=INK)
    d.text((pad, 92), subtitle, font=KO(22), fill=SUB)
    y = 150
    d.rounded_rectangle((pad - 14, y - 6, W - pad + 14, H - (56 if note else 26)), 18, fill=CARD, outline=LINE, width=2)
    x = pad
    for h, w in zip(headers, widths):
        d.text((x, y + 12), h, font=KO(21, True), fill=HEAD); x += w + gap
    y += 56
    d.line((pad, y - 6, W - pad, y - 6), fill=LINE, width=2)
    for wrapped, tag, h in laid:
        x = pad
        for i, (lines, font, w) in enumerate(zip(wrapped, fonts, widths)):
            for k, line in enumerate(lines):
                d.text((x, y + 12 + k * 34), line, font=font, fill=INK if i else SUB)
            x += w + gap
        if tag:
            label, ink, soft = TAG[tag]
            tw = d.textlength(label, font=KO(18, True)) + 28
            d.rounded_rectangle((W - pad - tw, y + 12, W - pad, y + 46), 17, fill=soft)
            d.text((W - pad - tw / 2, y + 29), label, font=KO(18, True), fill=ink, anchor='mm')
        y += h
        d.line((pad, y - 4, W - pad, y - 4), fill=LINE, width=1)
    if note:
        d.text((pad, H - 46), note, font=KO(18), fill=SUB)
    OUT.mkdir(parents=True, exist_ok=True)
    img.save(OUT / out, optimize=True)
    print(out, img.size)


def main():
    jp, ds, ko, triage = load()

    def row(mid, force=None):
        kind, _, ref = triage.get(mid, ['new', 0, ''])
        kind = force or ('new' if kind == 'short' and not ref else kind)
        return ([clean(jp[mid], True), clean(ds[ref]) if ref in ds else '—', clean(ko[mid])], kind)

    picks = [f'FMsg/o_town_25_before#{i}' for i in (3, 4, 6, 7, 8)] + \
            [f'FMsg/o_peach_op_04#{i}' for i in (31, 32, 34, 29)]
    rows = [row(m) for m in picks]
    # one line that exists only in the remake (Bowser Jr.'s Journey)
    rows.append(([clean(jp['BMsg/b_sys#1297'], True), '— (리메이크에 새로 생긴 쿠파주니어 RPG)', clean(ko['BMsg/b_sys#1297'])], 'new'))
    sheet('원작 DS 한국어판 번역을 그대로 이어받았습니다',
          '오프닝 장면의 실제 대사. 원작과 같은 대사는 DS 한국어판 문장을 띄어쓰기까지 그대로 쓰고, 달라진 부분만 고쳤습니다.',
          ['일본판 원문 (3DS 리메이크)', 'DS 한국어판 (2010, 공식)', '이번 한글패치'], [520, 500, 560], rows,
          '01_ds_vs_patch_opening.png', '자료: 일본판 대사 파일, DS 한국어판 롬에서 추출한 대사, 한글패치 최종본. 「DS를 고침」은 리메이크에서 바뀐 표현을 반영한 줄입니다.')

    counts = Counter(v[0] for v in triage.values())
    gl = list(csv.DictReader(open(ROOT / 'text' / 'glossary.tsv', encoding='utf-8'), delimiter='\t'))
    basis = Counter('DS' if g['basis'].startswith('DS') else 'official' if g['basis'].startswith('official') else
                    'coined' if g['basis'].startswith('coined') else 'other' for g in gl)
    total = sum(counts.values())
    stats = [(['DS 한국어판 문장을 그대로 사용', f"{counts['ds']:,}줄", f"{counts['ds'] / total:.0%}"], 'ds'),
             (['DS 문장을 바탕으로 리메이크에 맞게 고침', f"{counts['edited']:,}줄", f"{counts['edited'] / total:.0%}"], 'edited'),
             (['리메이크에서 새로 생긴 대사 (쿠파주니어 RPG 등) 새 번역', f"{counts['new']:,}줄", f"{counts['new'] / total:.0%}"], 'new'),
             (['짧은 문구 (이름·메뉴·선택지 등, DS·1DX 용어 우선)', f"{counts['short']:,}줄", f"{counts['short'] / total:.0%}"], None),
             (['용어집: DS 한국어판 표기', f"{basis['DS']:,}개", ''], 'ds'),
             (['용어집: 한국닌텐도 공식 표기 (1DX 한국어판 등)', f"{basis['official']:,}개", ''], '1dx'),
             (['용어집: 새로 지은 이름', f"{basis['coined']:,}개", ''], 'new')]
    sheet('번역은 어디에서 왔나',
          f'대사 {total:,}줄을 DS 한국어판과 문장 단위로 대조해 분류했습니다. 고유명사는 용어집으로 관리했습니다.',
          ['구분', '분량', '비율'], [760, 200, 320], stats, '02_translation_sources.png',
          f'용어집 {len(gl):,}개 · 우선순위: 확정 용어집 → DS 한국어판 → 한국닌텐도 공식 표기 → 신조어(검토 대상)')

    order = ['ability', 'attack', 'term', 'character', 'ui']
    picked = [g for g in gl if 'official' in g['basis'] and '1DX' in g['source'] and g['type'] in order]
    picked.sort(key=lambda g: order.index(g['type']))
    names = {'ability': '스킬', 'attack': '공격', 'term': '용어', 'character': '이름', 'ui': '화면'}
    rows = [([g['jp'], names[g['type']], g['ko']], '1dx') for g in picked][:16]
    sheet('쿠파주니어 RPG 용어는 1DX 한국어판과 맞췄습니다',
          'DS판에 없던 「쿠파주니어 RPG」의 용어는 『마리오&루이지 RPG1 DX』 한국어판 「쿠파군단 RPG」의 공식 표기를 따랐습니다.',
          ['일본판 원문', '종류', '한글패치 = 1DX 한국어판 표기'], [420, 160, 700], rows, '03_1dx_terms.png',
          '1DX 한국어판 대사 7,867줄을 추출해 같은 기능·같은 라벨의 문장을 짝지어 대조했습니다(일치 115줄).')

    pairs = list(csv.DictReader(open(ROOT / 'work' / 'review' / 'kj_1dx_pairs.tsv', encoding='utf-8'), delimiter='\t'))
    good, seen = [], set()
    for p in sorted(pairs, key=lambda p: -len(clean(p['ko']))):
        text = clean(p['ko'])
        if p['sim'] == '1.00' and 14 <= len(text) <= 70 and text not in seen and '/  ' not in p['ko']:
            seen.add(text); good.append(p)
    good = good[:8]
    rows = [([clean(p['jp'], True), clean(p['ko_1dx']), clean(p['ko'])], '1dx') for p in good]
    sheet('같은 설명은 1DX 한국어판 문장 그대로',
          '두 게임에 공통으로 있는 쿠파 군단 관련 설명·가이드·아이템 문장은 1DX 한국어판 문장을 그대로 썼습니다.',
          ['일본판 원문 (3DX)', '1DX 한국어판 (공식)', '이번 한글패치'], [480, 520, 520], rows, '04_1dx_guide_lines.png')


if __name__ == '__main__':
    main()
