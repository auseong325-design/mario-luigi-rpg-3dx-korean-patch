import collections, json, subprocess, sys
from kj_battle_audit import ROOT, OUT, rows

rr = rows()
bids = sorted({r['batch'] for r in rr})
cmd = [str(ROOT/'.venv/Scripts/python.exe'), '-X', 'utf8', str(ROOT/'scripts/merge_ko.py'), '--check', *bids]
res = subprocess.run(cmd, cwd=ROOT, capture_output=True, text=True, encoding='utf-8', timeout=120)
(OUT/'kj_battle_check.log').write_text(res.stdout+res.stderr, encoding='utf-8')
triage = json.loads((ROOT/'work/review/triage.json').read_text(encoding='utf-8'))['batches']
counts = collections.Counter()
scoped = set()
dup_count = 0
for r in rr:
    counts[triage[r['batch']]['msgs'][r['id']][0]] += 1
    for mid in [r['id'], *r['dups']]:
        if mid.startswith(('FMsg/k', 'BMsg/')):
            scoped.add(mid)
    dup_count += len(r['dups'])
summary = dict(batches=len(bids), representatives=len(rr), kj=sum(r['id'].startswith('FMsg/') for r in rr),
               battle=sum(r['id'].startswith('BMsg/') for r in rr), same_source_dups=dup_count,
               scope_instances=len(scoped), triage_original_counts=dict(counts), exit_code=res.returncode)
(OUT/'kj_battle_summary.json').write_text(json.dumps(summary, ensure_ascii=False, indent=2), encoding='utf-8')
print(json.dumps(summary, ensure_ascii=False, indent=2))
print(res.stdout.splitlines()[-1] if res.stdout else res.stderr)
sys.exit(res.returncode)
