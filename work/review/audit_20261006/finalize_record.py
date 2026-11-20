"""Preserve prior lead state and record verified audit/install results."""
from pathlib import Path
import json, re, csv
from datetime import datetime
ROOT=Path(__file__).resolve().parents[3]
OUT=Path(__file__).resolve().parent
def read(p):return json.loads(p.read_text(encoding='utf-8-sig'))
def save(p,d):p.write_text(json.dumps(d,ensure_ascii=False,indent=1)+'\n',encoding='utf8',newline='')
technical=read(OUT/'technical.json');summary=read(OUT/'integration_summary.json');installed=read(OUT/'install.json')
particle=read(OUT/'particle_manifest.json')
assert not technical['issues']
assert not technical['text']['japanese_residue'] and not technical['text']['absolute_dialogue_width_errors']
assert summary['batches']==130 and summary['changed_representatives']==54 and summary['changed_merged_ids']==56
assert particle['decoded_bytes']==particle['texture_size'] and not particle['gaps']
for name in ['REPORT.md','GAME_CHECKS.md']:
    doc=(OUT/name).read_text(encoding='utf8')
    for target in re.findall(r'\]\((C:/[^)]+)\)',doc):
        path=re.sub(r':\d+$','',target)
        assert Path(path).exists(),(name,target)
leadfile=ROOT/'work/lead_state.json'
backup=OUT/'before_merge/lead_state.json'
assert not backup.exists(),'Run once only'
backup.write_bytes(leadfile.read_bytes())
lead=read(leadfile)
lead['updated']='2026-10-06'
lead['phase']='2026-10-06 한글화 파일 감사와 확정 수정 반영 완료. 대표54개/복사본포함56개, 메시지4파일 최신 설치·SD ZIP 동기화. 일반 메시지 미번역/일본어잔존0, 메시지·폰트·이미지 재읽기 기술문제0. 일본어 임시 아이템 그림6종 실제 노출과 기존 화면 확인 항목은 사용자 Azahar 테스트 대기.'
lead['build']['before_audit_20261006']=lead['build'].get('latest')
lead['build']['latest']='2026-10-06: whole-file localization audit -> 54 representative translations in17files corrected (51 DS text/punctuation/spacing restorations,1 DS typo,1 action-switch terminology,1 ※ restoration) -> merge_ko --check-all130/130 errors0 -> --merge9617 IDs,5 overrides0 errors (56 changed IDs incl. copies) -> build_patch --fonts --out work/build/msg_stage/romfs:9623 messages re-parsed0 problems,1254 characters/1161 Hangul covered. Azahar/Citra not running -> installed FMsg.dat/BMsg.dat/Menu.msbt/HugeBattle.msbt. All10 message/font stage/patch/Azahar-junction SHA256 match. SD folder and ZIP all patch files match, CRC PASS. Installed-data independent technical audit0 issues. Previous files/ZIP in work/build/prev_msg_before_audit_20261006/. No game launched.'
new_items=[
 '2026-10-06 NEW: Obj/JP/Menu.dat m_item_ev_all f022/f024/f026/f028/f030/f034 and odd paired frames:6 unique Japanese temporary icons remain (ビリリンパ,バキューム,スター赤/青/黄,マグナムキラー). MainMenu v1.2 resource use and corresponding event-item text/table references exist; exact frame-selection path not confirmed. Check important-item menu/acquisition scenes for 찌릿찌릿 림프,배큐엄블록,스타백신3색,매그넘킬러. Numeric1-5 pictures are separate5 types. Do not label all11 unused based on appearance. See work/review/audit_20261006/particle_item_icons.md.',
 '2026-10-06 NEW: BMsg/b_sys#746 restored DS question 스페셜 어택의 사용 방법을 설명해 줄까?;292px,source one question row+choice row preserved,check0errors but relative-length warning. Confirm actual balloon fit. See work/review/audit_20261006/GAME_CHECKS.md.'
]
for item in new_items:
    if item not in lead.setdefault('review_items',[]):lead['review_items'].append(item)
lead.setdefault('font_phase',[]).append('DONE2026-10-06: Menu#731 ※New 닌텐도3DS전용 marker restored; all3 installed message fonts rebuilt byte-identically and all1254usedchars covered. Direct1DX copies remain pixel/Hangul-width identical;5 last-resort Hangul 몫쬔췄핥휩 remain documented. Staffroll6newHangul direct1DX verified.')
lead['audit_20261006']={
 'status':'file_audit_complete; in_game_checks_pending',
 'report':'work/review/audit_20261006/REPORT.md',
 'game_checks':'work/review/audit_20261006/GAME_CHECKS.md',
 'batches':summary['batches'],'representatives':summary['representative_messages'],
 'duplicate_links':summary['duplicate_links'],'merged_ids':summary['final_messages'],
 'original_messages':technical['text']['jp_messages'],'tag_only_originals':technical['text']['unmerged'],
 'changed_representatives':54,'changed_final_ids':56,'changed_batch_files':summary['changed_files'],
 'automatic_errors':0,'technical_issues':0,'japanese_message_residue':0,
 'manual_scope':'5220 representative JP/KO texts directly compared (4757 KJ/BMsg/menus +463 field DS differences);2870 DS-identical field texts automatically aligned with direct samples and complete interior-spacing audit. All8090 batch representatives+1527copies covered. Known text-bearing replacement art and localized kept art directly viewed; do not claim every non-text texture or every scene replayed.',
 'fonts':{'used_chars':1254,'used_hangul':1161,'all_three_cover_required':True,'donor_pixels_and_hangul_widths_match':True,'fallback_hangul':'몫쬔췄핥휩'},
 'images':{'lyt_unique_replacements':178,'lyt_replacement_copies':258,'lyt_kept_directly_reviewed':48,'obj_replacement_regions':125,'fmdl_inputs':5,'hb_input_images':20,'hb_replacement_copies':25,'particle_base_textures':87,'particle_extra_mips':7,'particle_full_texture_region_accounted':True,'particle_text_found':False},
 'remaining_japanese_art':{'resource':'Obj/JP/Menu.dat:m_item_ev_all','unique_japanese_images':6,'representative_frames':[22,24,26,28,30,34],'paired_odd_frames_share_pixels':True,'actual_exposure':'not_confirmed; resource code and corresponding item texts exist','numeric_only_images':5},
 'unconfirmed_wording':[{'id':'FMsg/i_metaboru_06#43','issue':'ボケーッとしてきた as 멍청해졌다; quiz distractor/function versus literal meaning'},{'id':'FMsg/i_energy_32#19','issue':'失笑 as 코웃음; surrounding sarcasm versus involuntary laugh. DS110#8 correspondence verified.'}],
 'glossary_evidence':'トゲダメージ=가시 대미지 basis official,1DX BMsg:k_sys#223 (+#32/#766), persisted in overrides; Korean term unchanged',
 'reference_gap':'HugeBattle SOURCE_DS misses BAI__BMes_yo table2; field MAX_REF_LINES400 truncates refs. Audit used complete originals and documented fixes; generator code unchanged.',
 'install':installed,
 'source_files_modified':False,'azahar_launched':False,
 'timestamp':datetime.now().astimezone().isoformat(timespec='seconds')}
save(leadfile,lead)
print('Lead state preserved and audit/install results recorded; local report links valid.')
