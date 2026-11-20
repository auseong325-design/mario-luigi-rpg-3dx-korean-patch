import re, collections
from corpus import *
jp = jp_msgs(); ko = ko_final()
def is_kj(mid):
    if mid.startswith('FMsg/k_') or mid.startswith('MenuKJ'): return True
    lab = jp[mid].get('label') or ''
    return lab.startswith(('KJ', 'Kj', 'kj', 'Menu_KJ'))
gl = {r['jp'] for r in glossary()}
KATA = re.compile(r'[ァ-ヺー]{2,}(?:Jr\.)?')
kj_tok, main_tok = collections.Counter(), collections.Counter()
for mid in ko:
    t = vis(jp[mid]['jp'])
    toks = KATA.findall(t)
    (kj_tok if is_kj(mid) else main_tok).update(set(toks))
both = [t for t in kj_tok if main_tok[t] and t not in gl]
print('KJ katakana tokens', len(kj_tok), 'shared with main', sum(1 for t in kj_tok if main_tok[t]), 'shared & not in glossary', len(both))
print(sorted(both, key=lambda t: -kj_tok[t])[:150])
