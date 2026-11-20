"""Record completed assembly, native Azahar capture and protected-file checks."""
from pathlib import Path
import hashlib
import json
import zipfile
import numpy as np
from PIL import Image

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
OUT = HERE / 'out'


def sha(p):
    return hashlib.sha256(p.read_bytes()).hexdigest()


def main():
    assembly = json.loads((OUT / 'assembly.json').read_text(encoding='utf8'))
    archive = json.loads((OUT / 'build_verify.json').read_text(encoding='utf8'))
    install = json.loads((OUT / 'install.json').read_text(encoding='utf8'))
    fmdl = ROOT / 'patch/00040000001CA900/romfs/FMdl/JP/FMdl.dat'
    source_af = Path('C:/Users/woose/Desktop/ml3dx_kj_affinity/OA_kupajunior_logo.af')
    assert sha(fmdl) == '2d7819214886f6e973810940ff69f4096c254cd8da30381983e52ac519cefcad'
    assert sha(source_af) == '164315b9f50245a83c5e7b80d4e98de8583179cbc9ac088717df68d5a280d98e'
    shot = Image.open(OUT / 'runtime_after.png').convert('RGB')
    assert shot.size == (400, 480)
    expected = np.asarray(Image.open(OUT / 'fileload_KJ_assembled.png').convert('RGB')).astype(int)
    actual = np.asarray(shot)[:208].astype(int)
    difference = np.abs(actual - expected)
    # Shader RGB565 conversion can differ by one channel unit. A different
    # picture/position would fail this native capture comparison.
    assert difference.max() <= 2, (difference.max(), difference.mean())
    shot.crop((0, 0, 400, 240)).save(OUT / 'runtime_top.png')
    shot.crop((190, 142, 265, 208)).resize((450, 396), Image.Resampling.NEAREST).save(OUT / 'runtime_R_detail.png')
    runtime = dict(method='Codex built-in computer-use, @oai/sky',
                   emulator='Azahar 2126.1.2', screenshot='runtime_after.png',
                   screenshot_source="Mario & Luigi Bowser's Inside…_10.10.26_00.20.00.511.png",
                   mode='쿠파주니어 RPG, file slot 1, mode selection',
                   observed_R_repairs_hidden_by_Hangul=True,
                   observed_no_clipping_or_L_R_seam=True,
                   native_capture_max_channel_difference=int(difference.max()),
                   native_capture_mean_channel_difference=float(difference.mean()),
                   input_profile_changed=False, normal_emulation_stop='F5',
                   subagents_used=False, Orca_used=False)
    (OUT / 'runtime_verify.json').write_text(json.dumps(runtime, ensure_ascii=False, indent=2), encoding='utf8')
    record = dict(date='2026-10-10',status='assembled, installed and directly verified in Azahar',
                  assembly=assembly,archive=archive,install=install,runtime=runtime,
                  original_OA_Affinity_unchanged=True,main_title_and_intro_FMdl_unchanged=True,
                  editable_affinity='KJ_assembled_20261010.af',
                  affinity_sha256=sha(HERE / 'KJ_assembled_20261010.af'),
                  recipe='work/img/kj_assembly_20261010/build_assembly.py',
                  canonical_pipeline='work/img/logo2/run_all.py')
    (HERE / 'manifest.json').write_text(json.dumps(record, ensure_ascii=False, indent=2),encoding='utf8')
    state_path = ROOT / 'work/lead_state.json'
    state = json.loads(state_path.read_text(encoding='utf8'))
    state['updated'] = '2026-10-10'
    state['kj_assembly_20261010'] = dict(record,report='work/img/kj_assembly_20261010/REPORT.md')
    state_path.write_text(json.dumps(state, ensure_ascii=False, indent=1) + '\n',encoding='utf8')
    agent_entry = ('   - 2026-10-10: 사용자 요청으로 승인된 쿠파주니어 OA 자형을 18% 균등 확대하고 R 앞에 조립했다. '
                   '문구 전체 기울기를 4도 조정해 마지막 「어」의 테두리로 R 왼쪽의 위·아래 복원 부분을 가렸다. '
                   '분리한 위·아래 바람을 독립 배치했으며 RPG보다 작은 높이를 유지했다. '
                   'Affinity 편집본 저장, Codex 내장 computer-use로 Azahar 모드 선택 화면 직접 확인, '
                   'MLyt KJ 좌우 두 텍스처만 변경·그 외 바이트 동일, patch/정션/SD/ZIP 36파일 일치. '
                   '최신 레시피는 logo2/run_all.py에 연결했다. 기록: `work/img/kj_assembly_20261010/REPORT.md`, '
                   '`KJ_assembled_20261010.af`, `out/runtime_after.png`.\n')
    agents_path = ROOT / 'AGENTS.md'
    agents = agents_path.read_text(encoding='utf8')
    if agent_entry not in agents:
        marker = '3. 2026-10-07: 후리가나 설정'
        assert marker in agents
        agents_path.write_text(agents.replace(marker,agent_entry + marker),encoding='utf8')
    i4 = ROOT / 'work/img/I4.md'
    marker = '## 쿠파주니어 문구·R·바람 최종 조립 (2026-10-10)'
    history = i4.read_text(encoding='utf8')
    if marker not in history:
        history += ('\n\n' + marker + '\n'
            '- 승인 OA 자형을 균등 1.18배로 키우고 전체 각도를 기존 대비 4도 조정했다. '
            '문구를 R 앞으로 보내 마지막 어 테두리로 왼쪽 위·아래 복원 부위를 덮었다.\n'
            '- 분리 소재 R_clean/wind_top/wind_bottom 사용. 위 바람 꼬리는 문구 뒤, 아래 바람은 R 밑. '
            '기존 주황 그라데이션·사선 결·흰/노란/적갈 외곽 재질 유지.\n'
            '- MLyt의 KJ 좌우 두 텍스처만 변경, 그 외 SARC·BG4 바이트 동일. '
            'FMdl과 원래 OA Affinity 동일. patch/정션/SD/ZIP 36파일 일치·CRC PASS.\n'
            '- Codex 내장 computer-use로 Azahar의 실제 KJ 모드 선택을 직접 확인하고 Ctrl+P로 기록했다. '
            '게임 캡처와 설치 텍스처의 채널 오차 최대 2 이내, 입력 프로필 변경 없이 F5 종료.\n'
            '- 레시피·Affinity 편집본·실제 화면·보고서: work/img/kj_assembly_20261010/. '
            'logo2/run_all.py에 재생성 경로 연결. 서브에이전트·Orca 사용 없음.\n')
        i4.write_text(history,encoding='utf8')
    text = f'''# 쿠파주니어 RPG 로고 조립 — 2026-10-10

사용자 요청: 기존에 제작된 쿠파주니어 자형과 복원한 R·바람을 조립한다.
R 왼쪽 위·아래의 지적된 부분은 문구 앞뒤 겹침으로 가리고, 한글 문구는 조금 키워 RPG보다 작게 한다.

## 결과

- 공식 자형 OA 벡터를 한 번에 **1.18배** 균등 확대했다. 획·음절별 비율은 바꾸지 않았다.
- 문구 전체를 기존 대비 4도 돌려 상승 기울기를 거의 수평으로 맞추었다. 마지막 「어」의 흰/노란/적갈 테두리가 R 왼쪽 줄기·아래 모서리를 덮는다.
- 가림 순서: 배경 → 복원 R → 위 바람 → 쿠파주니어 문구 → 아래 바람.
- 위 바람 원점 (36,139), 아래 바람 (214,187). R은 원래 (201,140)에 둔다.
- 한글 면 전체 범위 x=53.45..211.00, y=165.20..197.00. 외곽 포함 높이도 RPG보다 작고 하단 208행 안에 있다.
- 기존 주황 그라데이션·사선 결·붉은 가장자리와 흰/노란/적갈 외곽 재질을 유지했다. 크기에 맞춰 세로 그라데이션 범위만 맞췄다.
- `KJ_assembled_20261010.af`: 배경, R, 위 바람, 문구, 아래 바람 독립 레이어. 문구 그룹에는 실제 재질 래스터와 수정용 공식 자형/외곽 벡터가 함께 있다. 벡터는 숨김 참고 레이어다.

## 검증과 설치

- 대표 가림 좌표 (206,165), (207,175), (209,193), (210,196)의 문구 피복률 100%.
- 변경 {assembly['changed_pixels']:,}픽셀, 범위 {assembly['changed_bbox']}. 별·일러스트와 P/G 면은 유지했다.
- MLyt 재읽기: KJ 좌우 BFLIM 두 장만 변경, 그 외 SARC 파일·BG4 항목은 바이트 동일. 디코드 RGB565와 입력이 정확히 같다.
- Codex 내장 `@oai/sky`로 Azahar 2126.1.2에서 슬롯1 → KJ 모드 선택을 직접 확인했다. R 두 복원 부위가 문구 뒤에 가려지고, 이음새·잘림이 없다.
- Ctrl+P 원본 캡처 `out/runtime_after.png` (400×480). 상단 정적 400×208 화면과 설치 PNG의 채널 차이 최대 {runtime['native_capture_max_channel_difference']}, 평균 {runtime['native_capture_mean_channel_difference']:.6f}이다.
- 입력 프로필 변경 없이 F5로 정상 중지. 서브에이전트·Orca·별도 Windows 입력 스크립트 없음.
- patch·Azahar 정션·SD 폴더·ZIP **{install['checked_files']}파일** 일치, ZIP CRC PASS, lyt_stage 동기화.
- MLyt SHA256: `{install['MLyt_sha256']}`.
- ZIP SHA256: `{install['zip_sha256']}`.
- 메인 타이틀·인트로 FMdl 및 클로드의 원래 OA Affinity 파일은 SHA256 동일.
- 백업: `work/build/prev_kj_assembly_20261010/` (직전 MLyt와 배포 ZIP).
- 최신 레시피 `build_assembly.py`를 `work/img/logo2/run_all.py`에 연결해 전체 그림을 재생성해도 유지한다.

## 산출물

- `out/runtime_top.png`: 실제 Azahar 상단 화면.
- `out/runtime_R_detail.png`: 실제 R 접합부 최근접 확대.
- `out/before_after.png`: 기존 문구 크기와 조립 후 비교.
- `out/fileload_KJ_assembled.png`: 조립된 400×208 텍스처.
- `KJ_assembled_20261010.af`: 편집 가능한 Affinity 파일.
- `build_assembly.py`, `build_archive.py`, `install.py`, `affinity_assembly.js`: 재현 레시피.
- `manifest.json`, `out/assembly.json`, `out/build_verify.json`, `out/install.json`, `out/runtime_verify.json`: 확인 기록.
'''
    (HERE / 'REPORT.md').write_text(text,encoding='utf8')
    archive_path = HERE / 'KJ_assembled_editable_20261010.zip'
    names = ['KJ_assembled_20261010.af','REPORT.md','manifest.json','build_assembly.py','affinity_assembly.js',
             'out/fileload_KJ_assembled.png','out/before_after.png','out/runtime_after.png']
    with zipfile.ZipFile(archive_path,'w',zipfile.ZIP_DEFLATED) as z:
        for name in names:
            z.write(HERE / name,name)
        for p in (HERE / 'affinity').iterdir():
            if p.is_file():
                z.write(p,p.relative_to(HERE).as_posix())
    with zipfile.ZipFile(archive_path) as z:
        assert z.testzip() is None
    print(json.dumps(runtime,ensure_ascii=False,indent=2))
    print('Report/state/history recorded; editable assets ZIP saved.')


if __name__ == '__main__':
    main()
