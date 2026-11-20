from pathlib import Path
import csv,json,collections,re
root=Path(__file__).resolve().parents[3]
out=Path(__file__).resolve().parent
d=json.loads((out/'technical.json').read_text(encoding='utf8'))
for scope,plan in d['plans'].items():
    print(scope,plan['actions'])
    for row in plan['kept_japanese']:
        print(row.get('id'),row.get('jp'),row.get('notes'))
g=list(csv.DictReader((root/'text/glossary.tsv').open(encoding='utf8'),delimiter='\t'))
print('GLOSSARY',len(g),collections.Counter(r['basis'] for r in g))
for r in g:
    if r['basis']=='coined' or re.search(r'확인|불확실|검토',r.get('note','')):
        print('TERM',json.dumps(r,ensure_ascii=False))
from PIL import Image
for p in sorted((root/'work/img/review').glob('*.png')):
    if p.name.startswith(('A_','B_','C_','D_','I3_','I6_','lead_','I4v2_')):
        im=Image.open(p)
        print('IMG',p.name,im.size)
