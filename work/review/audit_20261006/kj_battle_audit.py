import argparse, csv, json, re
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
OUT = Path(__file__).parent
TAG = re.compile(r'\{\d+:\w+\}')

def plain(s):
    return TAG.sub('', s).replace('\n', ' / ').replace('[Next]', ' | ')

def rows():
    ans=[]
    for p in sorted((ROOT/'work/batches').glob('*.json')):
        if not (p.name.startswith('FMsg__k') or p.name.startswith('BMsg__b_sys__')):
            continue
        b=json.loads(p.read_text(encoding='utf-8'))
        k=json.loads((ROOT/'text/ko'/p.name).read_text(encoding='utf-8'))
        for m in b['messages']:
            ans.append(dict(batch=b['batch'],id=m['id'],label=m['label'],src=m['src'],ko=k['translations'].get(m['id'],''),note=k.get('notes',{}).get(m['id'],''),dups=m.get('dups',[])))
    return ans

if __name__=='__main__':
    a=argparse.ArgumentParser()
    a.add_argument('scope', choices=['k','b','stats','search'])
    a.add_argument('start',nargs='?',default='0')
    a.add_argument('end',nargs='?',default='120')
    args=a.parse_args()
    rr=rows()
    if args.scope=='stats':
        from collections import Counter
        print(json.dumps(Counter(r['batch'] for r in rr),ensure_ascii=False,indent=2))
        with (OUT/'kj_battle_pairs.tsv').open('w',encoding='utf-8',newline='') as f:
            w=csv.DictWriter(f,fieldnames=['batch','id','label','src','ko','note','dups'],delimiter='\t'); w.writeheader();w.writerows(rr)
    else:
        if args.scope=='search':
            rr=[r for r in rr if re.search(args.start,r['src']+' '+r['ko']+' '+r['label'])]
        else:
            rr=[r for r in rr if r['id'].startswith('FMsg/' if args.scope=='k' else 'BMsg/')]
            rr.sort(key=lambda r:(r['id'].split('#')[0],int(r['id'].split('#')[1])))
            rr=rr[int(args.start):int(args.end)]
        prev=''
        for r in rr:
            room,idx=r['id'].split('#')
            if room!=prev:
                print(room)
                prev=room
            print('#'+idx+' '+plain(r['src'])+' ⇒ '+plain(r['ko']))
