import json
from pathlib import Path
OUT=Path(__file__).resolve().parent
ROOT=OUT.parents[2]
script=json.loads((OUT/'chika_ds_script.json').read_text(encoding='utf-8'))[0]
ds=next(r for r in json.loads((ROOT/'text/ref_ds_ko/FEvent.json').read_text(encoding='utf-8')) if r['room']=='0DA')
messages={m['i']:m['ko'] for m in ds['messages']}
lines=[]
rows=[]
print('Parsed commands',sum(len(s['commands']) for s in script['subroutines']), 'subroutine footer bytes',sum(len(s['footer'])//2 for s in script['subroutines']))
for subid,sub in enumerate(script['subroutines']):
    for cmdid,c in enumerate(sub['commands']):
        if c.get('command_id') in (0x1BA,0x1BC,0x1C8,0x1CA):
            args=c['arguments']
            row={'subroutine':subid,'command':cmdid,'op':c['command_id'],'arguments':args}
            if len(args)>11 and isinstance(args[11],int):
                row.update(actor=args[0],ds_message=args[11],text=messages.get(args[11],''))
            rows.append(row)
            lines.append(json.dumps(row,ensure_ascii=False))
        elif c.get('command_id') in (0x1B9,0x1BB,0x1C7,0x1C9):
            rows.append({'subroutine':subid,'command':cmdid,'op':c['command_id'],'arguments':c['arguments']})
(OUT/'chika_textboxes.json').write_text(json.dumps(rows,ensure_ascii=False,indent=1),encoding='utf-8')
(OUT/'chika_textboxes.txt').write_text('\n'.join(lines),encoding='utf-8')
print('Textbox records',len(rows))
for row in rows:
    if row.get('ds_message') in (0,1,3,4,5,7,8,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41):print(json.dumps(row,ensure_ascii=False))
