import json
from pathlib import Path

root = Path.cwd()
lead = json.loads((root / 'work/lead_state.json').read_text(encoding='utf8'))
print('LEAD', json.dumps({k:lead[k] for k in lead if k in ['review_items','font_phase']}, ensure_ascii=False, indent=1))
for rel in ['work/img/lyt_plan.json','work/img/obj_plan.json','work/img/hb_plan.json',
            'work/build/font_report.json','work/build/patch_report.json','text/staffroll.json',
            'work/img/fmdl_manifest.json','work/img/I5_build.json']:
    p = root / rel
    if not p.exists():
        print(rel, 'MISSING'); continue
    d = json.loads(p.read_text(encoding='utf8'))
    print(rel, type(d).__name__, list(d)[:16] if isinstance(d,dict) else len(d))
    if isinstance(d,dict):
        for k,v in d.items():
            if isinstance(v,list) and v:
                print(k,len(v),str(v[0])[:1100])
            elif k == 'fonts':
                print(json.dumps(v,ensure_ascii=False,indent=1)[:1700])
