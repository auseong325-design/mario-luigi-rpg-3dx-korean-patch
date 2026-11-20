from pathlib import Path
from datetime import datetime, timezone, timedelta
import json

ROOT = Path(__file__).resolve().parents[3]
OUT = Path(__file__).parent
path = ROOT / 'work/lead_state.json'
state = json.loads(path.read_text(encoding='utf8'))
runtime = json.loads((OUT / 'runtime_verify.json').read_text(encoding='utf8'))
install = json.loads((OUT / 'install.json').read_text(encoding='utf8'))
assert runtime['runtime_verified'] and install['all_patch_junction_sd_zip_files_match']
state['updated'] = '2026-10-08'
state['phase'] = '2026-10-08: 인트로 & 실제 검증에 이어 모드 선택 로고를 최신 1DX 골조·3DX 재질로 갱신. Codex 내장 computer-use로 Azahar v1.2 화면 확인 완료, patch·SD·ZIP 36파일 일치.'
state['build']['latest'] = '2026-10-08: File/mode-selection Mario & Luigi RPG3 logo updated to the latest 1DX word/amp shapes, rounded ji cap, approved underside contours and 3DX material. RPG uniformly resized to match; numeral 3 and character art preserved. Only two MLyt textures changed. Verified actual Azahar v1.2 mode-selection screen using Codex built-in Computer Use. Original Default gamepad profile restored after QA. Main-title/intro FMdl unchanged. All 36 patch/junction/SD/ZIP files equal; ZIP CRC PASS. See work/img/fileload_logo_20261008/REPORT.md; preceding intro fix remains verified.'
state['fileload_logo_20261008'] = {
    'status': 'complete; installed; verified in actual Azahar game via Codex built-in Computer Use',
    'report': 'work/img/fileload_logo_20261008/REPORT.md',
    'recipe': 'work/img/fileload_logo_20261008/build_fileload.py',
    'runtime_comparison': 'work/img/fileload_logo_20261008/runtime_before_after.png',
    'runtime': runtime, 'install': install, 'subagents_used': False,
    'timestamp': datetime.now(timezone(timedelta(hours=9))).isoformat()
}
for i, entry in enumerate(state.get('review_items', [])):
    if entry.startswith('File-select logos v2:'):
        state['review_items'][i] = 'File-select logo: Mario & Luigi RPG3 updated and verified in actual Azahar v1.2 on 2026-10-08 via Codex built-in Computer Use (fileload_logo_20261008). Remaining check: unchanged 쿠파주니어 RPG illustration. Main-title/intro verified earlier the same day (logo_runtime_fix_20261008).'
path.write_text(json.dumps(state, ensure_ascii=False, indent=1) + '\n', encoding='utf8')
print('Recorded fileload completion; retained unrelated review items and prior intro verification.')
