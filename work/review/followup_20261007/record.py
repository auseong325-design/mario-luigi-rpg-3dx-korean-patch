"""Record changes relative to the preceding completed audit."""
from pathlib import Path
import json, datetime
ROOT = Path(__file__).resolve().parents[3]
OUT = Path(__file__).resolve().parent
def read(p): return json.loads(p.read_text(encoding='utf-8-sig'))
def save(p,obj): p.write_text(json.dumps(obj,ensure_ascii=False,indent=1)+'\n',encoding='utf8')
before = read(OUT/'before_merge/ko_final.json')
after = read(ROOT/'work/ko_final.json')
changes = [{'id':mid,'before':before[mid],'after':text} for mid,text in after.items() if before.get(mid)!=text]
save(OUT/'merged_changes.json',changes)
assert set(before) == set(after)
for mid in ['FMsg/i_metaboru_06#43','FMsg/i_energy_32#19']:
    assert before[mid] == after[mid],mid
merge = read(ROOT/'work/merge_report.json')
assert not merge['failed'] and not merge['missing'] and not merge['dup_overrides']['errors']
state = read(ROOT/'work/lead_state.json')
record = {
 'date':'2026-10-07',
 'user_decisions':{
   'execution':'main agent directly completed resumed work; no subagents used after the latest instruction',
   'ss_company_names':{'スーリム':'슬림','キュット':'큐티','ムチオ':'마초','スーさん':'슬림씨'},
   'wording_candidates':'retain current translation; no further expression change requested',
   'six_temporary_item_images':'retain previous handling; actual exposure not claimed verified',
   'furigana':'remove unnecessary Korean-output furigana and its settings entry',
   'speech':'recurring characters use official Korean examples; original characters follow established character traits; identical DS lines remain DS'
 },
 'changed_merged_messages':len(changes),
 'merged_messages':len(after),
 'batches':len(merge['ok']),
 'merge_errors':0,
 'ss_name_changes':read(OUT/'ss_name_changes.json')['representatives'],
 'furigana':{'build':'work/review/followup_20261007/furigana_build.json','verification':'work/review/followup_20261007/furigana_verify.json','report':'work/review/followup_20261007/furigana.md','runtime_verified':False},
 'report':'work/review/followup_20261007/REPORT.md',
 'speech_reports':['work/review/followup_20261007/main_speech.md','work/review/followup_20261007/kj_speech.md'],
 'install':read(OUT/'install.json'),
 'technical':{'issues':read(OUT/'technical.json')['issues']},
 'azahar_launched':False,
 'timestamp':datetime.datetime.now(datetime.timezone(datetime.timedelta(hours=9))).isoformat()
}
assert not record['technical']['issues']
state['followup_20261007'] = record
state['font_phase']=[
 'DONE 2026-10-07: Korean messages have no ruby. The furigana settings row, buttons and cursor entry use the native hasRuby=0 path; CRO/CRR installed and statically verified. Actual game screen confirmation remains with the user.'
 if s.startswith("Menu#361 'メッセージにふりがなを表示'") else s
 for s in state.get('font_phase',[])
]
state['next']=[s.replace('the 「후리가나 표시」 setting label (font_phase), ', '') for s in state.get('next',[])]
state['review_items']=[
 '2026-10-07 USER DECISION: Six temporary event-item images retain their previous handling; no additional translation requested. Actual exposure remains unverified.'
 if s.startswith('2026-10-06 NEW: Obj/JP/Menu.dat m_item_ev_all') else s
 for s in state.get('review_items',[])
]
settings_check='2026-10-07 CHECK: Open settings after loading the patched MainMenu CRO; confirm the furigana row is absent, remaining rows align and D-pad/touch selection plus confirm/return work. Verify the patch loads on Azahar and Luma with v1.2.'
if settings_check not in state['review_items']:state['review_items'].append(settings_check)
if 'audit_20261006' in state:
    state['audit_20261006']['unconfirmed_wording_disposition'] = '2026-10-07 user decided to retain both current expressions'
    state['audit_20261006']['temporary_item_image_disposition'] = '2026-10-07 user decided to retain previous handling'
save(ROOT/'work/lead_state.json',state)
save(OUT/'summary.json',record)
print(json.dumps(record,ensure_ascii=False,indent=2))
