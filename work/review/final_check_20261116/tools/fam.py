import json, re, collections
from corpus import *
rows = json.load(open('widths.json'))
jp = jp_msgs(); ko = ko_final()
def family(r):
    mid = r['id']; src = mid.split('/')[0].split('#')[0]; lab = r['label'] or ''; st = r['style']
    if src == 'FMsg': return (src, st, 'dialog')
    toks = lab.split('_')
    if lab.startswith('Menu_KJ_Chr_exp'): f = 'Menu_KJ_Chr_exp'
    elif lab.startswith('Menu_KJ_'): f = '_'.join(toks[:3])
    elif lab.startswith('MES_'): f = '_'.join(toks[:2])
    elif src == 'BMsg' and st == 13 and len(toks) <= 2 and not lab.startswith(('KJ', 'Kj', 'kj', 'Menu')): f = 'enemyname'
    else: f = re.sub(r'\d+$', '', toks[0])
    return (src, st, f)
fmax = collections.defaultdict(float); fn = collections.Counter(); fmaxid = {}
for r in rows:
    f = family(r); fn[f] += 1
    m = max(r['jw'])
    if m > fmax[f]: fmax[f] = m; fmaxid[f] = r['id']
out = []
for r in rows:
    f = family(r)
    if f[2] == 'dialog': continue
    kw = max(r['kw'])
    if kw > fmax[f] and fn[f] >= 3:
        out.append((kw - fmax[f], r['id'], f, max(r['jw']), kw, fmax[f]))
out.sort(reverse=True)
print('non-dialogue texts wider than the widest JP of their family (families with >=3 members):', len(out))
for d, mid, f, jw, kw, fm in out:
    print(f'+{d:4.0f} {mid:18} {f[0]}:{f[1]}:{f[2][:22]:22} n={fn[f]:3} JP {jw:4.0f} KO {kw:4.0f} famJPmax {fm:4.0f} ({fmaxid[f]}) | {vis(ko[mid]).replace(chr(10)," / ")[:60]}')
json.dump({'fmax': {str(k): v for k, v in fmax.items()}}, open('fam.json', 'w'))
