import csv, json, re, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
OUT = Path(__file__).resolve().parent

def natural(v):
    return [int(t) if t.isdigit() else t for t in re.split(r'(\d+)',v)]

def clean(v):
    return re.sub(r'\[[^\]]+\]', '', v).replace('\\n',' / ')

def ownrows():
    rows=[]
    for p in sorted((ROOT/'work/batches').glob('*.json')):
        if not (p.stem.startswith('FMsg__k') or p.stem.startswith('BMsg__b_sys')):
            continue
        batch=json.loads(p.read_text(encoding='utf-8'))
        ko=json.loads((ROOT/'text/ko'/p.name).read_text(encoding='utf-8'))
        for msg in batch['messages']:
            rows.append({'batch':p.stem, 'id':msg['id'], 'label':msg['label'], 'src':msg['src'], 'ko':ko['translations'][msg['id']], 'note':ko.get('notes',{}).get(msg['id'],''), 'dups':msg.get('dups',[])})
    return sorted(rows,key=lambda r:natural(r['id']))

def main():
    mode=sys.argv[1]
    pattern=sys.argv[2] if len(sys.argv)>2 else '.*'
    if mode=='ref':
        ref=list(csv.DictReader((ROOT/'work/ref_1dx_ko.tsv').open(encoding='utf-8'),delimiter='\t'))
        selected=[r for r in ref if re.search(pattern,r['key']+' '+r['label']+' '+r['text'])]
        selected.sort(key=lambda r:(r['key'],natural(r['label'])))
        start=int(sys.argv[3]) if len(sys.argv)>3 else 0
        count=int(sys.argv[4]) if len(sys.argv)>4 else len(selected)
        for r in selected[start:start+count]:
            print(r['key'],r['index'],r['label'],clean(r['text']),sep=' | ')
        print('SELECTED',len(selected))
    elif mode in ('own','compact'):
        selected=[r for r in ownrows() if re.search(pattern,r['id']+' '+r['label']+' '+r['src']+' '+r['ko'])]
        start=int(sys.argv[3]) if len(sys.argv)>3 else 0
        count=int(sys.argv[4]) if len(sys.argv)>4 else len(selected)
        for r in selected[start:start+count]:
            if mode=='compact':
                jp=re.sub(r'\{\d+:\w+\}','',r['src']).replace('\n',' / ').replace('[Next]',' || ')
                ko=re.sub(r'\{\d+:\w+\}','',r['ko']).replace('\n',' / ').replace('[Next]',' || ')
                print(r['id'],r['label'],jp,'=>',ko,sep=' | ')
            else:
                print(r['id'],r['label'],r['src'].replace('\n',' / '),'=>',r['ko'].replace('\n',' / '),'NOTE',r['note'],sep=' | ')
        print('SELECTED',len(selected))
    elif mode=='export':
        rows=ownrows()
        with (OUT/'kj_speech_pairs.tsv').open('w',encoding='utf-8',newline='') as f:
            w=csv.DictWriter(f,fieldnames=rows[0].keys(),delimiter='\t');w.writeheader();w.writerows(rows)
        print('EXPORTED',len(rows))

if __name__=='__main__':
    main()
