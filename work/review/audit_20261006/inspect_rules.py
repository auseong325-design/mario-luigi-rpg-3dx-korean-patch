import json
from pathlib import Path
from collections import Counter
r=Path(__file__).resolve().parent
d=json.loads((r/'rule_candidates.json').read_text(encoding='utf8'))
print(Counter((x['kind'],'choice' if ':choice}' in x['ko'] else 'prose') for x in d))
for x in d:
    if ':choice}' not in x['ko']:
        print(json.dumps(x,ensure_ascii=False))
