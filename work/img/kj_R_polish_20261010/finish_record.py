"""Record the localized R fix and verified installation; preserve older work history."""
from pathlib import Path
import hashlib
import json
import zipfile
import numpy as np
from PIL import Image

HERE=Path(__file__).resolve().parent
ROOT=HERE.parents[2]
OUT=HERE/'out'
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()


def main():
    rcheck=json.loads((HERE/'R_verify.json').read_text(encoding='utf8'))
    art=json.loads((OUT/'R_only_verify.json').read_text(encoding='utf8'))
    build=json.loads((OUT/'build_verify.json').read_text(encoding='utf8'))
    install=json.loads((OUT/'install.json').read_text(encoding='utf8'))
    source_af=Path('C:/Users/woose/Desktop/ml3dx_kj_affinity/OA_kupajunior_logo.af')
    assert sha(source_af)=='164315b9f50245a83c5e7b80d4e98de8583179cbc9ac088717df68d5a280d98e'
    assert sha(ROOT/'patch/00040000001CA900/romfs/FMdl/JP/FMdl.dat')=='2d7819214886f6e973810940ff69f4096c254cd8da30381983e52ac519cefcad'
    screenshot=Image.open(OUT/'runtime_after.png').convert('RGB')
    assert screenshot.size==(400,480)
    expected=np.asarray(Image.open(OUT/'fileload_KJ_assembled.png').convert('RGB')).astype(int)
    actual=np.asarray(screenshot)[:208].astype(int)
    diff=np.abs(actual-expected)
    assert diff.max()<=2,(diff.max(),diff.mean())
    screenshot.crop((0,0,400,240)).save(OUT/'runtime_top.png')
    screenshot.crop((200,143,261,204)).resize((366,366),Image.Resampling.NEAREST).save(OUT/'runtime_R_detail.png')
    previous=Image.open(ROOT/'work/img/kj_assembly_20261010/out/runtime_after.png').convert('RGB')
    comparison=Image.new('RGB',(732,366),'white')
    comparison.paste(previous.crop((200,143,261,204)).resize((366,366),Image.Resampling.NEAREST),(0,0))
    comparison.paste(screenshot.crop((200,143,261,204)).resize((366,366),Image.Resampling.NEAREST),(366,0))
    comparison.save(OUT/'runtime_R_before_after.png')
    runtime=dict(method='Codex built-in @oai/sky computer-use',emulator='Azahar 2126.1.2',
                 capture=(OUT/'runtime_source.txt').read_text(encoding='utf8'),
                 observed_mode='slot 1, 쿠파주니어 RPG mode selection',
                 R_fix_applied_without_assembly_shift_or_seam=True,
                 native_capture_max_channel_difference=int(diff.max()),
                 native_capture_mean_channel_difference=float(diff.mean()),
                 input_profile_unchanged=True,normal_stop='F5',subagents_used=False,Orca_used=False)
    (OUT/'runtime_verify.json').write_text(json.dumps(runtime,ensure_ascii=False,indent=2),encoding='utf8')
    record=dict(date='2026-10-10',status='R inner face repaired, reassembled, installed and runtime verified',
                standalone_R_check=rcheck,assembly_check=art,archive=build,install=install,runtime=runtime,
                reference='user-supplied Korean 1DX 쿠파군단 RPG R: straight stem and clean face/bevel boundary',
                colours='original 3DX yellow-green gradient/hatch; only damaged edge pixels reconstructed',
                R_png='R_clean.png',R_aligned_png='R_clean_aligned.png',
                R_affinity='R_refined_20261010.af',assembly_affinity='KJ_assembled_R_refined_20261010.af',
                R_sha256=sha(HERE/'R_clean.png'),
                original_OA_document_and_title_intro_FMdl_identical=True,
                recipe='work/img/kj_R_polish_20261010/build_refined_assembly.py')
    (HERE/'manifest.json').write_text(json.dumps(record,ensure_ascii=False,indent=2),encoding='utf8')
    report=f'''# 쿠파주니어 RPG의 R 녹색 면 경계 정리 — 2026-10-10

사용자가 지적한 왼쪽 줄기/아래 모서리에서 적갈 테가 녹색 면을 침범하는 부분을 수정했다.
제공된 한국판 1DX 「쿠파군단 RPG」 R의 곧은 줄기와 깔끔한 면/테 경계를 형태 참고로 삼았다.

## 수정

- 이전 R 분리 작업의 테두리 복원 픽셀이 면 쪽으로 들어가 있었다. 왼쪽 면 경계를 직선으로 잇고 줄기 아래를 평평한 모서리로 정리했다.
- 새 서체로 바꾸거나 R 전체를 늘리지 않았다. 알파/외곽 실루엣, 구멍, 위쪽 몸통, 오른쪽 다리는 동일하다.
- Affinity MCP의 native RGBA8 PixelReader/Writer로 x206..224/y164..196 내부만 수정했다. **독립 R {rcheck['R_changed_pixels']}픽셀** 변경.
- 기존 3DX 색/질감을 유지했다. 손상되지 않은 녹색 면 픽셀을 그대로 쓰고, 비어 있던 면만 원본 R에서 측정한 행별 그라데이션과 사선 결로 보완했다.
- 곧은 경계를 따라 얇은 연녹색 밝은 테를 연결해 적갈 외곽과 녹색 면이 구분되도록 했다.
- 의도한 녹색 면 내부의 적갈색 픽셀 **{rcheck['maroon_pixels_inside_intended_green_face_before']} → {rcheck['maroon_pixels_inside_intended_green_face_after']}**. 알파/외곽 및 crop/aligned RGBA 일치 확인.
- 18% 커진 쿠파주니어 문구, 기울기/위치/재질, 위아래 바람은 SHA256/픽셀 동일하다. 합성본은 R 부분의 **{art['final_changed_pixels']}픽셀**만 바뀌었다(나머지 수정 부위는 문구/바람 뒤에 있다).

## 검증 및 설치

- MLyt에서 실제 바뀐 파일은 `MENU_FILE_LOAD_JP_ja/timg/LOAD_GAME_IMG_KJ_R_00_JP_ja.bflim` **한 장**. 왼쪽 그림을 포함한 다른 SARC 파일/BG4 항목은 바이트 동일하다.
- 바뀐 BFLIM을 디코드한 RGB565와 입력 PNG가 정확히 일치한다.
- Codex 내장 `@oai/sky`로 Azahar 2126.1.2를 실행해 실제 KJ 모드 선택 화면에서 확인했다. 문구/바람 조립 유지, 잘림/이음새 없음.
- Ctrl+P 캡처: `{runtime['capture']}`. 정적 상단 그림 400×208과 설치 PNG의 채널 차이 최대 {runtime['native_capture_max_channel_difference']}, 평균 {runtime['native_capture_mean_channel_difference']:.6f}.
- 입력 프로필 변경 없이 F5 정상 중지. 서브에이전트·Orca·별도 Windows 입력 스크립트 없음.
- patch·Azahar 정션·SD 폴더·ZIP **{install['checked_files']}파일** 일치, ZIP CRC PASS, lyt_stage 동기화.
- MLyt SHA256 `{install['MLyt_sha256']}`.
- 배포 ZIP SHA256 `{install['zip_sha256']}`.
- 메인 타이틀/인트로 FMdl, 원래 클로드 OA Affinity 파일은 동일하다.
- 직전 MLyt/ZIP 백업: `work/build/prev_kj_R_polish_20261010/`.
- `work/img/logo2/run_all.py`는 이 폴더의 `build_refined_assembly.py`를 호출한다. 이전 조립 레시피는 기본 R 파일을 유지해 이전 결과도 재현할 수 있다.

## 파일

- `R_clean.png`: 최신 투명 R 소재(60×63).
- `R_clean_aligned.png`: 기존 400×208 좌표의 R.
- `R_before_after.png`: 왼쪽 이전 / 가운데 수정 / 오른쪽 파란 배경 확인.
- `R_refined_20261010.af`: R 단독 Affinity 파일.
- `KJ_assembled_R_refined_20261010.af`: 수정 R을 반영한 전체 조립 Affinity 파일.
- `out/runtime_after.png`, `out/runtime_top.png`, `out/runtime_R_before_after.png`: 실제 게임 화면.
- `affinity_refine_R.js`, `fit_material.py`, `build_refined_assembly.py`: 재현 코드.
- `manifest.json`, `R_verify.json`, `out/R_only_verify.json`, `out/build_verify.json`, `out/install.json`, `out/runtime_verify.json`: 확인 기록.
'''
    (HERE/'REPORT.md').write_text(report,encoding='utf8')
    state_path=ROOT/'work/lead_state.json'
    state=json.loads(state_path.read_text(encoding='utf8'))
    state['updated']='2026-10-10'
    state['kj_R_polish_20261010']=dict(record,report='work/img/kj_R_polish_20261010/REPORT.md')
    state_path.write_text(json.dumps(state,ensure_ascii=False,indent=1)+'\n',encoding='utf8')
    marker='## 쿠파주니어 R 녹색 면 침범 정리 (2026-10-10)'
    i4=ROOT/'work/img/I4.md'
    text=i4.read_text(encoding='utf8')
    if marker not in text:
        text+='\n\n'+marker+'\n- 참고 1DX R처럼 왼쪽 줄기/아래 모서리 면 경계를 곧게 정리. 독립 R 110픽셀, 녹색 면의 적갈 침범 10→0, 알파/외곽 동일. 기존 3DX 색·사선 결 유지.\n- 문구·바람은 동일, 합성 R 25픽셀만 변경. MLyt KJ_R 한 장만 변경·그 외 바이트 동일. Affinity 편집본/최신 투명 R 저장.\n- Codex 내장 computer-use로 실제 모드 선택 확인. patch/정션/SD/ZIP 36파일 일치·CRC PASS, 입력 프로필 그대로 F5 종료.\n- 최신 레시피·검증·실제 화면: work/img/kj_R_polish_20261010/. logo2/run_all.py 경로 갱신, 서브에이전트·Orca 사용 없음.\n'
        i4.write_text(text,encoding='utf8')
    agents_path=ROOT/'AGENTS.md'
    agents=agents_path.read_text(encoding='utf8')
    entry=('   - 2026-10-10 (R 정리): 사용자 참고 1DX 쿠파군단 RPG의 R처럼 왼쪽 줄기/아래 모서리의 면·테두리 경계를 정리했다. '
           'Affinity native 픽셀 편집으로 독립 R 110픽셀을 수정, 녹색 면 안의 적갈 침범 10→0. 외곽 알파/나머지 면과 기존 3DX 그라데이션·사선 결 보존. '
           '문구/바람 조립은 동일하며 실제 합성 R 25픽셀·MLyt KJ_R 한 장만 변경했다. '
           'Codex 내장 computer-use로 Azahar 모드 선택 직접 확인, patch/정션/SD/ZIP 36파일 일치. '
           '최신 R 소재·Affinity·레시피·보고서: `work/img/kj_R_polish_20261010/REPORT.md`, `R_clean.png`, `KJ_assembled_R_refined_20261010.af`. '
           'logo2/run_all.py 연결 갱신.\n')
    if entry not in agents:
        anchor='3. 2026-10-07: 후리가나 설정'
        assert anchor in agents
        agents_path.write_text(agents.replace(anchor,entry+anchor),encoding='utf8')
    package=HERE/'KJ_R_refined_editable_20261010.zip'
    names=['R_clean.png','R_clean_aligned.png','R_before_after.png','R_refined_20261010.af',
           'KJ_assembled_R_refined_20261010.af','REPORT.md','manifest.json','affinity_refine_R.js',
           'material_fit.json','fit_material.py','build_refined_assembly.py','out/fileload_KJ_assembled.png',
           'out/runtime_after.png','out/runtime_R_before_after.png']
    with zipfile.ZipFile(package,'w',zipfile.ZIP_DEFLATED) as z:
        for name in names:z.write(HERE/name,name)
        for name in ['wind_top.png','wind_bottom.png']:
            z.write(ROOT/'work/img/kj_parts_20261009'/name,name)
        for p in (HERE/'affinity').iterdir():
            if p.is_file():z.write(p,p.relative_to(HERE).as_posix())
    with zipfile.ZipFile(package) as z:assert z.testzip() is None
    print(json.dumps(runtime,ensure_ascii=False,indent=2))
    print('Latest R assets, assembly, reports and editable ZIP recorded.')


if __name__=='__main__':
    main()
