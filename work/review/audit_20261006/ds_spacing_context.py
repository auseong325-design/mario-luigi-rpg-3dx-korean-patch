import json
from ds_spacing_scan import ROOT, OUT, clean, anchors, display

rooms = json.loads((ROOT/'text/ref_ds_ko/FEvent.json').read_text(encoding='utf-8-sig'))
for room in rooms:
    if room['room'] not in ['0F9', '0D1', '20F']:
        continue
    for m in room['messages']:
        if room['room']=='0D1' and not 48 <= m['i'] <= 55:
            continue
        if room['room']=='20F' and not 0 <= m['i'] <= 10:
            continue
        print('DS'+room['room']+'#'+str(m['i']),display(m['ko']))
print('spacing variants within same room')
for r in json.loads((OUT/'ds_spacing_candidates.json').read_text(encoding='utf-8')):
    rid = r['ds_key'].split('#')[0][2:]
    chars = anchors(r['ds'])[0]
    variants = [(m['i'], m['ko']) for rr in rooms if rr['room']==rid for m in rr['messages'] if anchors(m['ko'])[0]==chars]
    if len(variants)>1:
        print(r['id'],[(i,display(s)) for i,s in variants])
for path in [ROOT/'work/batches/FMsg__o_zutsuda_01__and9.json']:
    b = json.loads(path.read_text(encoding='utf-8'))
    for m in b['messages']:
        if m['id'].split('#')[0] in ['FMsg/o_zutsuda_04_before','FMsg/o_zutsuda_04_after']:
            print(m['id'],display(m['src']))
