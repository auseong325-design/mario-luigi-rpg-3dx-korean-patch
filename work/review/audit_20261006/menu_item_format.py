import json
from pathlib import Path
ROOT = Path(__file__).resolve().parents[3]
OUT = Path(__file__).resolve().parent
changes = json.loads((OUT / 'menu_item_changes.json').read_text(encoding='utf-8'))
for batch in sorted({c['batch'] for c in changes}):
    path = ROOT / 'text/ko' / (batch + '.json')
    original = (OUT / 'menu_item_backup' / path.name).read_text(encoding='utf-8')
    text = path.read_text(encoding='utf-8')
    old = json.loads(original)
    current = json.loads(text)
    assert old['new_terms'] == current['new_terms']
    a = original.index(' "new_terms":')
    b = original.index(' "notes":', a)
    x = text.index(' "new_terms":')
    y = text.index(' "notes":', x)
    text = text[:x] + original[a:b] + text[y:]
    if original.startswith('{"batch":'):
        text = text.replace('{\n "batch":', '{"batch":', 1)
    assert json.loads(text) == current
    path.write_text(text, encoding='utf-8')
print('Restored unchanged new_terms and opening formatting for 5 batches')
