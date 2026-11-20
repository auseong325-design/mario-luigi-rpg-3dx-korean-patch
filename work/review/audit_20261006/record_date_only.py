from pathlib import Path
import json
p=Path(__file__).resolve().parents[3]/'work/lead_state.json'
d=json.loads(p.read_text(encoding='utf8'))
d['build']['latest']=d['build']['latest'].replace('2026-10-06T16:37+09:00:','2026-10-06:',1)
p.write_text(json.dumps(d,ensure_ascii=False,indent=1)+'\n',encoding='utf8',newline='')
print('Audit build label records the verified date without an estimated clock time.')
