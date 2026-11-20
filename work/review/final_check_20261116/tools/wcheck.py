import json, collections
from corpus import *
rows = json.load(open('widths.json'))
def grp(r): return (r['id'].split('/')[0].split('#')[0], r['style'])
gmax = collections.defaultdict(int); gl = collections.defaultdict(list)
for r in rows:
    for p in r['jlines']:
        for x in p: gmax[grp(r)] = max(gmax[grp(r)], x)
print('group max JP widths:', dict(sorted(gmax.items())))
over = []
for r in rows:
    g = grp(r)
    for pi, p in enumerate(r['klines']):
        for li, x in enumerate(p):
            if x > gmax[g]: over.append((x - gmax[g], r['id'], pi, li, x, gmax[g]))
over.sort(reverse=True)
print('KO lines wider than group max JP:', len(over))
ko = ko_final(); jp = jp_msgs()
for d, mid, pi, li, x, gm in over[:60]:
    print(f'  +{d:.0f}px {mid} p{pi+1} l{li+1} {x:.0f}/{gm:.0f} style {jp[mid]["style"]} |', vis(ko[mid]).split('[Next]')[pi].split('\n')[li][:80])
