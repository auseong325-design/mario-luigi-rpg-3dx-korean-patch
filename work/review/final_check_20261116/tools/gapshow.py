import json, sys
from corpus import *
gap = json.load(open('gap.json'))
jp = jp_msgs(); ko = ko_final()
lo, hi = float(sys.argv[1]), float(sys.argv[2])
skip = sys.argv[3] if len(sys.argv) > 3 else None
rows = [g for g in gap if lo <= g[2] < hi and (skip is None or g[0] != skip)]
rows.sort(key=lambda g: -g[2])
print(len(rows))
for bid, key, cov, mid, text in rows:
    print(f'## {key} cov={cov} -> {mid}')
    print('  DS:', text.replace('\n', ' ').replace('[Next]', ' / '))
    print('  KO:', vis(ko.get(mid, '')).replace('\n', ' ').replace('[Next]', ' / '))
    print('  JP:', vis(jp[mid]['jp']).replace('\n', '').replace('[Next]', ' / '))
