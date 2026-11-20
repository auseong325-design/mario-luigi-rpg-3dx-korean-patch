import csv, json, subprocess
from kj_speech_helper import ROOT, OUT, ownrows

rows=ownrows()
changes=json.loads((OUT/'kj_speech_changes.json').read_text(encoding='utf-8'))
stats={
    'all_representatives':len(rows),
    'kj_field_representatives':sum(r['id'].startswith('FMsg/') for r in rows),
    'battle_representatives':sum(r['id'].startswith('BMsg/') for r in rows),
    'kj_battle_dialogue_and_command_representatives':sum(r['label'].startswith('Kj_Btl_') and not r['label'].startswith('Kj_Btl_lose_') for r in rows),
    'changed_representatives':len(changes),
    'changed_expanded_ids':sum(1+len(r['dups']) for r in changes),
    'changed_batches':len({r['batch'] for r in changes}),
    'iggy_first_person':7,
    'lemmy_laugh':1,
}
ref=list(csv.DictReader((ROOT/'work/ref_1dx_ko.tsv').open(encoding='utf-8'),delimiter='\t'))
evidence_labels={
    'krpg_gera_qst7_7','krpg_gera_qst7_8','krpg_gera_qst7_13','krpg_gera_qst7_17','krpg_gera_qst1_30','krpg_gera_qst1_32','krpg_gera_qst6_10',
    'krpg_dehe_qst5_4','krpg_dehe_qst5_7','krpg_joke_qst5_8','krpg_joke_qst5_12','krpg_mame_qst_fort_end_5','krpg_mame_qst_fort_end_11',
    'krpg_koopa_qst2_6','krpg_koopa_qst2_7','krpg_koopa_qst3_9','krpg_hera_qst1_26','krpg_hera_qst5_7','krpg_hera_qst5_8',
}
evidence=[r for r in ref if r['label'] in evidence_labels]
with (OUT/'kj_speech_1dx_evidence.tsv').open('w',encoding='utf-8',newline='') as f:
    writer=csv.DictWriter(f,fieldnames=['key','index','label','text'],delimiter='\t');writer.writeheader();writer.writerows(evidence)
with (OUT/'kj_speech_all_check.log').open('w',encoding='utf-8') as logfile:
    for batch in sorted({r['batch'] for r in rows}):
        result=subprocess.run([str(ROOT/'.venv/Scripts/python.exe'),'-X','utf8',str(ROOT/'scripts/merge_ko.py'),'--check',batch],cwd=ROOT,timeout=120,stdout=subprocess.PIPE,stderr=subprocess.STDOUT,encoding='utf-8',check=True)
        logfile.write('== '+batch+' ==\n'+result.stdout+'\n')
        assert '0 with errors' in result.stdout,(batch,result.stdout)
stats['checked_batches']=len({r['batch'] for r in rows})
stats['batches_with_errors']=0
stats['1dx_evidence_rows']=len(evidence)
(OUT/'kj_speech_summary.json').write_text(json.dumps(stats,ensure_ascii=False,indent=2)+'\n',encoding='utf-8')
print(json.dumps(stats,ensure_ascii=False))
for r in changes:
    print(r['id'],r['dups'])
