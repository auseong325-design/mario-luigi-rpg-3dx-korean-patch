from pathlib import Path
import json, sys
ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0,str(ROOT/'scripts'))
import make_batches as M
ds=json.loads((ROOT/'text/ref_ds_ko/FEvent.json').read_text(encoding='utf8'))
for room in ds:
    if room['room']=='110':
        print('DS ROOM 110')
        for m in room['messages']:
            if 0<=m['i']<=12: print('DS110#'+str(m['i']),m['ko'])
for rel in ['FMsg__i_energy_32','FMsg__i_metaboru_06','FMsg__o_koopa_13_2']:
    jp=json.loads((ROOT/'text/jp'/f'{rel}.json').read_text(encoding='utf8'))
    arr=jp['messages']
    for m in arr:
        n=int(m['id'].rsplit('#',1)[1])
        if rel.endswith('i_metaboru_06') and not 37<=n<=48: continue
        if rel.endswith('o_koopa_13_2') and not 37<=n<=41: continue
        ko=None
        for path in (ROOT/'text/ko').glob('*.json'):
            d=json.loads(path.read_text(encoding='utf8'))
            if m['id'] in d.get('translations',{}): ko=d['translations'][m['id']]; break
        print(m['id'], M.to_view(m['jp'])[1], '\nKO:',ko)
