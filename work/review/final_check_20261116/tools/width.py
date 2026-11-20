import re, json, collections, sys
from corpus import *
from fontw import adv
P = ROOT/'patch/00040000001CA900/romfs/Msg/JP_ja'
O = ROOT/'romfs/Msg/JP_ja'
FJ = {n: {c: v[2] for c, v in adv(O/f'{n}.bffnt').items()} for n in ['font','font_btl','font_l']}
FK = {n: {c: v[2] for c, v in adv(P/f'{n}.bffnt').items()} for n in ['font','font_btl','font_l']}
GAIZI = {c: v[2] for c, v in adv(ROOT/'romfs/Msg/gaizi.bffnt').items()}
STYLE_FONT = {11: 'font_btl', 3: 'font_btl', 5: 'font_btl', 10: 'font_l'}
def default_font(mid, style):
    src = mid.split('/')[0].split('#')[0]
    if src == 'FMsg' and style == 5: return 'font'
    return STYLE_FONT.get(style, 'font')
SW = {'02 00': 'font_l', '00 00': 'font_btl', '01 00': 'font', '04 00': 'font', '06 00': 'font'}
TOK = re.compile(r'\[Ruby ([^;\]]*);[^\]]*\]|\[U\+([0-9A-F]{4})\]|\[0000:0001:([0-9A-F ]+)\]|\[0003:[^\]]*\]|\[[^\]]*\]|(\n)|(.)', re.S)
def measure(raw, mid, style, korean):
    F = FK if korean else FJ
    base = default_font(mid, style); cur = base
    pages = [[0]]; nvar = 0; missing = set(); bigline = set()
    def addw(w): pages[-1][-1] += w
    i = 0
    for m in TOK.finditer(raw):
        ruby, icon, sw, nl, ch = m.group(1), m.group(2), m.group(3), m.group(4), m.group(5)
        whole = m.group(0)
        if whole == '[Next]': pages.append([0]); continue
        if ruby is not None:
            for c in ruby: addw(F[cur].get(c, 16 * (1.5 if cur=='font_l' else 0.75 if cur=='font_btl' else 1)))
            continue
        if icon: addw(GAIZI.get(chr(int(icon, 16)), 16)); continue
        if sw: cur = base if sw == 'FF FF' else SW.get(sw, base); 
        if sw:
            if cur == 'font_l': bigline.add((len(pages)-1, len(pages[-1])-1))
            continue
        if whole.startswith('[0003:'): nvar += 1; continue
        if whole.startswith('['): continue
        if nl: pages[-1].append(0); continue
        c = ch
        w = F[cur].get(c)
        if w is None:
            missing.add(c); w = {'font_l': 24, 'font_btl': 12}.get(cur, 16)
        addw(w)
    return pages, nvar, missing
if __name__ == '__main__':
    jp = jp_msgs(); ko = ko_final()
    rows = []
    for mid, k in ko.items():
        m = jp[mid]
        jpages, jv, jmiss = measure(m['jp'], mid, m['style'], False)
        kpages, kv, kmiss = measure(k, mid, m['style'], True)
        rows.append({'id': mid, 'style': m['style'], 'label': m.get('label'),
                     'jw': [max(p) for p in jpages], 'kw': [max(p) for p in kpages],
                     'jl': [sum(1 for x in p if x > 0) for p in jpages], 'kl': [sum(1 for x in p if x > 0) for p in kpages],
                     'jlines': jpages, 'klines': kpages, 'kmiss': ''.join(sorted(kmiss)), 'nvar': kv})
    json.dump(rows, open('widths.json', 'w'), ensure_ascii=False)
    miss = [r for r in rows if r['kmiss']]
    print('messages', len(rows), 'with chars missing from patched font:', len(miss), collections.Counter(c for r in miss for c in r['kmiss']).most_common(20))
