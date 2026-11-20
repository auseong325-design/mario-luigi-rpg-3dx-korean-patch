"""Read-only follow-up material; run via run_checked.py."""
import json,re
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3]
OUT=Path(__file__).resolve().parent
rows=json.loads((OUT/'ds_field_rows.json').read_text(encoding='utf-8'))
def plain(s): return re.sub(r'\{[^}]*\}','',s).replace('[Next]',' / ').replace('\n',' / ').strip()
diffs=[r for r in rows if not r['exact']]
for part in range((len(diffs)+59)//60):
    lines=[]
    for ix,r in enumerate(diffs[part*60:(part+1)*60],part*60):
        lines.extend([f"[{ix}] {r['id']}",f"JP {plain(r['src'])}",f"KO {plain(r['ko'])}",f"DS {r['ds_key']} {plain(r['ds'])}"])
    (OUT/f'speech_part_{part:02d}.txt').write_text('\n'.join(lines),encoding='utf-8')
ds=json.loads((ROOT/'text/ref_ds_ko/FEvent.json').read_text(encoding='utf-8'))
room=next(r for r in ds if r['room']=='0DA')
(OUT/'chika_ds_context.txt').write_text('\n'.join(f"DS0DA#{m['i']} {m['ko']}" for m in room['messages']),encoding='utf-8')
print(f'{len(diffs)} differences in {(len(diffs)+59)//60} parts')
