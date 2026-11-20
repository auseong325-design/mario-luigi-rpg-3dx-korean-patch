import json, re, csv
from pathlib import Path
ROOT = Path(__file__).resolve().parents[4]
def ds_strings():
    out = []
    def walk(x, src):
        if isinstance(x, dict):
            for k, v in x.items():
                if k == 'ko' and isinstance(v, str): out.append((src, v))
                else: walk(v, src)
        elif isinstance(x, list):
            for v in x: walk(v, src)
    for f in sorted((ROOT/'text/ref_ds_ko').glob('*.json')):
        walk(json.load(open(f)), f.stem)
    return out
def glossary():
    with open(ROOT/'text/glossary.tsv', encoding='utf-8') as f:
        return list(csv.DictReader(f, delimiter='\t'))
def jp_msgs():
    out = {}
    for f in (ROOT/'text/jp').glob('*.json'):
        for m in json.load(open(f))['messages']:
            out[m['id']] = m
    return out
def ko_final():
    return json.load(open(ROOT/'work/ko_final.json'))
TAG = re.compile(r'\[[0-9A-F]{4}:[0-9A-F]{4}:[^\]]*\]')
RUBY = re.compile(r'\[Ruby ([^;\]]*);[^\]]*\]')
def vis(raw):
    """visible text with [Next] kept"""
    t = RUBY.sub(r'\1', raw)
    t = TAG.sub('', t)
    return t
def sq(s): return re.sub(r'[\s\n]', '', s)
