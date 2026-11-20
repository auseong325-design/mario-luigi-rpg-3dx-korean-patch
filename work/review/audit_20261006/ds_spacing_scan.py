import collections, csv, json, re, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
OUT = Path(__file__).parent
TAG = re.compile(r'\{[^}]*\}')

def clean(s):
    return TAG.sub('', s).replace('[Next]', '\n').strip()

def anchors(s):
    s = clean(s)
    chars = []
    gaps = ['']
    for ch in s:
        if ch.isspace():
            gaps[-1] += ch
        else:
            chars.append(ch)
            gaps.append('')
    return ''.join(chars), gaps

def display(s):
    return clean(s).replace('\n', ' / ')

before = json.loads((OUT/'ds_field_before_rows.json').read_text(encoding='utf-8'))
groups = [r for r in before if r['exact']]
cache = {}
differences = []
summary = collections.Counter()
output_prefix = sys.argv[3] if len(sys.argv)>3 else 'ds_spacing'
for r in groups:
    if r['batch'] not in cache:
        cache[r['batch']] = json.loads((ROOT/'text/ko'/f"{r['batch']}.json").read_text(encoding='utf-8'))
    ko = cache[r['batch']]['translations'][r['id']]
    chars, kgaps = anchors(ko)
    dchars, dgaps = anchors(r['ds'])
    if chars != dchars:
        summary['characters_now_differ'] += 1
        continue
    found = []
    excluded = []
    for pos in range(1, len(chars)):
        k, d = kgaps[pos], dgaps[pos]
        if k == d:
            continue
        if any(ch in k+d for ch in '\r\n'):
            excluded.append(pos)
            continue
        found.append(dict(position=pos, left=chars[max(0,pos-15):pos], right=chars[pos:pos+15],
                          ko_gap=k, ds_gap=d))
    summary['alignable'] += 1
    summary['linebreak_gaps_excluded'] += len(excluded)
    if found:
        summary['candidate_messages'] += 1
        summary['candidate_boundaries'] += len(found)
        out = dict(r)
        out['ko_current'] = ko
        out['note_current'] = cache[r['batch']].get('notes', {}).get(r['id'], '')
        out['gaps'] = found
        differences.append(out)
    else:
        summary['no_internal_spacing_difference'] += 1
summary['exact_groups_before'] = len(groups)
(OUT/f'{output_prefix}_candidates.json').write_text(json.dumps(differences, ensure_ascii=False, indent=2), encoding='utf-8')
(OUT/f'{output_prefix}_summary.json').write_text(json.dumps(dict(summary), ensure_ascii=False, indent=2), encoding='utf-8')
with (OUT/f'{output_prefix}_candidates.tsv').open('w',encoding='utf-8',newline='') as f:
    w = csv.writer(f,delimiter='\t')
    w.writerow(['batch','id','ds_key','boundaries','src','ko_current','ds','note_current'])
    for r in differences:
        w.writerow([r['batch'],r['id'],r['ds_key'],json.dumps(r['gaps'],ensure_ascii=False),r['src'],r['ko_current'],r['ds'],r['note_current']])
print(json.dumps(dict(summary),ensure_ascii=False))
for r in differences[int(sys.argv[1]):int(sys.argv[2])]:
    print(r['id'],r['batch'],r['ds_key'])
    print('JP',display(r['src']))
    print('KO',display(r['ko_current']))
    print('DS',display(r['ds']))
    print('GAPS',json.dumps(r['gaps'],ensure_ascii=False))
    if r['note_current']:
        print('NOTE',r['note_current'])
