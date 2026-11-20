import json, re, collections, sys
sys.path.insert(0, str(__import__('pathlib').Path(__file__).resolve().parents[4] / 'scripts'))
from lib3dx import encode_text
from corpus import *
jp = jp_msgs(); ko = ko_final()
# encoded UTF-16 length (bytes) per message, per file
def enc_len(t):
    try: return len(encode_text(t))
    except Exception as e: return -1
per_file_max = collections.defaultdict(lambda: [0, 0, '', ''])
ratio = []
for mid, k in ko.items():
    j = jp[mid]['jp']
    f = mid.split('#')[0] if mid.startswith('FMsg') else mid.split('/')[0].split('#')[0]
    fam = mid.split('/')[0].split('#')[0]
    lj, lk = enc_len(j), enc_len(k)
    pm = per_file_max[fam]
    if lj > pm[0]: pm[0] = lj; pm[2] = mid
    if lk > pm[1]: pm[1] = lk; pm[3] = mid
    if lk > lj: ratio.append((lk - lj, lk, lj, mid))
print('per file: max encoded bytes JP vs KO')
for f, (a, b, ma, mb) in per_file_max.items(): print(f'  {f:12} JP {a:6} ({ma})  KO {b:6} ({mb})')
ratio.sort(reverse=True)
print('messages where KO encodes longer than JP:', len(ratio), 'of', len(ko))
for d, lk, lj, mid in ratio[:12]: print(f'  +{d} bytes  KO {lk} JP {lj}  {mid}')
