"""Record verified runtime evidence and the completed contour-only installation."""
from pathlib import Path
from datetime import datetime, timezone, timedelta
import json
from PIL import Image, ImageDraw, ImageFont

ROOT = Path(__file__).resolve().parents[3]
OUT = Path(__file__).parent
read = lambda name: json.loads((OUT / name).read_text(encoding='utf8'))
art = read('art_verify.json')
build = read('build_verify.json')
runtime = read('runtime_verify.json')
install = read('install.json')
assert runtime['runtime_verified'] and install['all_patch_junction_sd_zip_files_match']

# Both sides come from native Azahar screenshots. Only crop, magnification and
# labels are applied; there is no retouching of the captured game pixels.
font = ImageFont.truetype('C:/Windows/Fonts/malgun.ttf', 18)
detail = Image.new('RGB', (760, 358), (25, 25, 25))
draw = ImageDraw.Draw(detail)
for i, (name, label) in enumerate([
    ('runtime_before.png', '수정 전 · Azahar 실제 화면'),
    ('runtime_after.png', '수정 후 · Azahar 실제 화면'),
]):
    im = Image.open(OUT / name).convert('RGB')
    assert im.size == (400, 480)
    crop = im.crop((265, 3, 360, 85)).resize((380, 328), Image.Resampling.NEAREST)
    detail.paste(crop, (i * 380, 30))
    draw.text((i * 380 + 10, 3), label, font=font, fill='white')
detail.save(OUT / 'runtime_detail_before_after.png')

report = f'''# 모드 선택 RPG·3 외곽선 수정 — 2026-10-08

모드 선택 화면의 G와 숫자 3 사이에 남은 흰색 각, 작은 흰 점과 하단의 절단 흔적을 제거했다. Codex 내장 Computer Use로 Azahar 2126.1.2 / 일본판 v1.2의 해당 화면에 직접 진입해 수정된 윤곽을 확인했다. patch·Azahar 정션·SD 폴더·배포 ZIP 설치를 완료했다.

## 원인과 수정

- 기존 레시피는 RPG 면을 사각 영역으로 추출할 때 숫자 3 쪽의 작은 광택 조각까지 포함했고, 숫자 3을 보존할 때 x=301 경계에서 원본을 통째로 덮어썼다. 새 G 외곽과 원본 숫자 외곽 사이의 사각 틈과 잔점이 생긴 원인이다.
- 실제 R/P/G 면의 연결 성분만 추출한다. 숫자 3의 면과 RPG 면까지의 거리로 원본을 보존할 영역을 정하고, 고정된 사각 덮어쓰기를 제거했다.
- G와 왼쪽 불꽃의 접합부에서 두 외곽의 피복률을 합쳐 곡선으로 연결했다. 작은 흰 구멍을 메우고 실제 반투명 경계까지 반영해 흰색 테두리 잔재를 제거했다.
- RGB565 양자화 후 변경은 203픽셀, 범위는 x=289..309 / y=24..83이다. RPG 글자 면·광택, 숫자 3의 색이 있는 전면, 한글·&와 캐릭터 그림은 그대로다. 접합부의 외곽선은 의도적으로 수정했다.
- 공통 재제작 레시피는 `work/img/fileload_logo_20261008/build_fileload.py`를 갱신했다. `logo2/run_all.py`의 기존 연결로 다시 만들어도 이 수정이 적용된다. 이전 레시피는 이 폴더의 `before_build_fileload.py`에 보관했다.

## 검사와 실제 화면

- `audit_art.py`: 변경 범위 제한, 한글·& 및 일러스트 보존, 접합부의 고립된 흰 점 제거 확인.
- `build_archive.py`: MLyt의 `MENU_FILE_LOAD_JP_ja/timg/LOAD_GAME_IMG_ML_R_00_JP_ja.bflim` 한 장만 교체했다. 다른 모든 SARC 파일·BG4 항목·레이아웃·애니메이션·쿠파주니어 로고는 바이트가 같다. 디코드한 RGB565는 양자화 입력과 정확히 일치한다.
- 메인 에이전트가 Codex 내장 `@oai/sky`로 게임 시작 → 슬롯 1 → 시작하기 → 모드 선택 화면을 조작했다. G·3 사이의 흰색 각과 점이 사라지고 둥근 테두리가 이어지는 것을 확인했다.
- Azahar Ctrl+P의 실제 캡처: `{runtime['native_screenshot']}`. 수정 전 화면은 직전 설치본을 실제로 캡처한 `fileload_logo_20261008/runtime_after.png`와 동일하다. 아래 비교는 원본 캡처를 자르고 4배 최근접 확대했으며 게임 픽셀을 보정하지 않았다.
- 이번 실행에서는 입력 프로필·설정을 바꾸지 않았다. 검증 후 F5로 에뮬레이션을 정상 중지했다. 서브에이전트·Orca·별도 Windows 입력 스크립트는 사용하지 않았다.

![실제 화면의 외곽선 수정 전후](C:/AI-Projects/mario-luigi-rpg-3dx-korean-patch/work/img/fileload_outline_fix_20261008/runtime_detail_before_after.png)

전체 화면 비교: `runtime_before_after.png`. 상세 증거: `art_verify.json`, `build_verify.json`, `runtime_verify.json`, `install.json`.

## 설치 결과

- 패치 변경 파일: `Lyt/JP/MLyt.dat` 하나. 기본 `work/build/lyt_stage/romfs/`에도 동기화했다.
- patch·Azahar 정션·SD 폴더·ZIP 36파일 모두 바이트 일치, ZIP CRC PASS.
- MLyt SHA-256: `{install['MLyt_sha256']}`.
- ZIP SHA-256: `{install['zip_sha256']}`.
- 메인 타이틀·인트로 FMdl은 `{runtime['FMdl_unchanged_sha256']}`로 그대로다.
- 직전 MLyt·PNG 입력·배포 ZIP: `work/build/prev_fileload_outline_fix_20261008/`.
- 원본 게임 파일은 수정하지 않았다.
'''
(OUT / 'REPORT.md').write_text(report, encoding='utf8')

state_path = ROOT / 'work/lead_state.json'
state = json.loads(state_path.read_text(encoding='utf8'))
state['updated'] = '2026-10-08'
state['phase'] = '2026-10-08: 모드 선택 로고 G·3 접합부의 흰색 각·잔점 수정. Codex 내장 computer-use로 Azahar v1.2 실제 화면 검증 완료, patch·정션·SD·ZIP 36파일 일치.'
state['build']['latest'] = ('2026-10-08: Removed angular white cuts, isolated white speck and lower seam at the file/mode-selection G/3 outline. '
    'Only 203 RGB565 pixels changed in the right MLyt texture; RPG/numeral front colors and gloss, Hangul/amp and character art preserved. '
    'Verified actual Azahar v1.2 mode-selection screen via Codex built-in Computer Use without changing input settings. '
    'Main-title/intro FMdl unchanged. All 36 patch/junction/SD/ZIP files equal; ZIP CRC PASS. See work/img/fileload_outline_fix_20261008/REPORT.md.')
state['fileload_logo_20261008']['contour_followup'] = 'fileload_outline_fix_20261008'
state['fileload_outline_fix_20261008'] = {
    'status': 'complete; installed; verified in actual Azahar game via Codex built-in Computer Use',
    'timestamp': datetime.now(timezone(timedelta(hours=9))).isoformat(),
    'report': 'work/img/fileload_outline_fix_20261008/REPORT.md',
    'recipe': 'work/img/fileload_logo_20261008/build_fileload.py',
    'runtime_comparison': 'work/img/fileload_outline_fix_20261008/runtime_detail_before_after.png',
    'art': art, 'build': build, 'runtime': runtime, 'install': install,
    'subagents_used': False,
}
state_path.write_text(json.dumps(state, ensure_ascii=False, indent=1) + '\n', encoding='utf8')

def append_once(path, marker, paragraph):
    content = path.read_text(encoding='utf8')
    if marker not in content:
        path.write_text(content.rstrip() + '\n\n' + paragraph.strip() + '\n', encoding='utf8')

append_once(ROOT / 'work/img/I4.md', '## 20. 모드 선택 RPG·3 접합부 흰색 각 제거', '''
## 20. 모드 선택 RPG·3 접합부 흰색 각 제거 (2026-10-08)
- §19의 RPG 면 추출에 작은 숫자 광택 성분이 포함되고 x=301 사각 보존 경계가 남아 G·3 사이에 흰색 각·잔점·하단 절단 흔적이 생겼다. 실제 글자 성분과 면까지의 거리로 보존 영역을 나누고 두 외곽의 피복률을 합쳐 곡선 접합으로 수정했다.
- 양자화 후 203픽셀만 변경(x289..309/y24..83). RPG·3의 색이 있는 전면과 광택, 한글·&, 캐릭터 그림 동일. MLyt의 ML_R BFLIM 한 장만 교체, 다른 SARC/BG4 바이트 및 메인 타이틀·인트로 FMdl 동일.
- Codex 내장 Computer Use로 Azahar v1.2의 모드 선택 화면에 직접 진입해 흰색 각·점 제거 확인, Ctrl+P 실제 캡처 저장. 입력 설정 변경 없음. F5 정상 중지. 서브에이전트·Orca·별도 입력 스크립트 사용 없음.
- patch/정션/SD/ZIP 36파일 일치, CRC PASS, 기본 lyt_stage 동기화. 백업 work/build/prev_fileload_outline_fix_20261008/.
- 기존 최신 레시피 work/img/fileload_logo_20261008/build_fileload.py를 수정했으며 logo2/run_all.py 연결은 그대로 사용한다. 보고서·실제 확대 비교: work/img/fileload_outline_fix_20261008/REPORT.md, runtime_detail_before_after.png.
''')
append_once(ROOT / 'work/img/fileload_logo_20261008/REPORT.md', '## 후속 외곽선 수정', '''
## 후속 외곽선 수정 (2026-10-08)

사용자가 추가 지적한 G·3 접합부의 흰색 각·점과 하단 절단 흔적을 수정했다. 이 문서의 설치 해시는 당시 기록이며 최신 설치 결과·실제 검증은 `work/img/fileload_outline_fix_20261008/REPORT.md`에 있다. 같은 `build_fileload.py`를 갱신했다. 숫자 3의 색이 있는 전면은 보존하고 접합부 외곽만 곡선으로 연결했다.
''')

agents = ROOT / 'AGENTS.md'
content = agents.read_text(encoding='utf8')
addition = ('   - 2026-10-08: 모드 선택 로고의 G·3 접합부 흰색 각·잔점·절단 흔적을 곡선으로 수정했다. '
    'MLyt 오른쪽 텍스처 203픽셀만 변경, 글자 면·광택·일러스트와 메인 타이틀·인트로 FMdl 동일. '
    'Codex 내장 computer-use로 Azahar v1.2 실제 화면 검증 완료, patch/정션/SD/ZIP 36파일 일치. '
    '최신 외곽선 보고서·실제 확대 비교: `work/img/fileload_outline_fix_20261008/REPORT.md`, `runtime_detail_before_after.png`.\n')
if addition not in content:
    marker = '3. 2026-10-07: 후리가나 설정'
    assert marker in content
    agents.write_text(content.replace(marker, addition + marker, 1), encoding='utf8')
print('Runtime detail comparison, REPORT, lead_state, I4, prior report and AGENTS updated.')
