"""Record the second R repair, native emulator proof, and current editing bundle."""
from pathlib import Path
import hashlib,json,zipfile
import numpy as np
from PIL import Image,ImageDraw

HERE=Path(__file__).resolve().parent
ROOT=HERE.parents[2]
OUT=HERE/'out'
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()


def main():
    rcheck=json.loads((HERE/'R_verify.json').read_text(encoding='utf8'))
    art=json.loads((OUT/'R_only_verify.json').read_text(encoding='utf8'))
    build=json.loads((OUT/'build_verify.json').read_text(encoding='utf8'))
    install=json.loads((OUT/'install.json').read_text(encoding='utf8'))
    assert sha(Path('C:/Users/woose/Desktop/ml3dx_kj_affinity/OA_kupajunior_logo.af'))=='164315b9f50245a83c5e7b80d4e98de8583179cbc9ac088717df68d5a280d98e'
    assert sha(ROOT/'patch/00040000001CA900/romfs/FMdl/JP/FMdl.dat')=='2d7819214886f6e973810940ff69f4096c254cd8da30381983e52ac519cefcad'
    shot=Image.open(OUT/'runtime_after.png').convert('RGB')
    assert shot.size==(400,480)
    expected=np.asarray(Image.open(OUT/'fileload_KJ_assembled.png').convert('RGB')).astype(int)
    actual=np.asarray(shot)[:208].astype(int)
    diff=np.abs(actual-expected)
    assert diff.max()<=2,(diff.max(),diff.mean())
    shot.crop((0,0,400,240)).save(OUT/'runtime_top.png')
    previous=Image.open(ROOT/'work/img/kj_R_polish_20261010/out/runtime_after.png').convert('RGB')
    compare=Image.new('RGB',(732,394),'white')
    d=ImageDraw.Draw(compare)
    d.text((8,8),'PREVIOUS',fill='black');d.text((374,8),'TOUCH-UP',fill='black')
    for i,image in enumerate([previous,shot]):
        compare.paste(image.crop((200,143,261,204)).resize((366,366),Image.Resampling.NEAREST),(i*366,28))
    compare.save(OUT/'runtime_R_before_after.png')
    runtime=dict(method='Codex built-in @oai/sky computer-use',emulator='Azahar 2126.1.2',
                 capture=(OUT/'runtime_source.txt').read_text(encoding='utf-8-sig').strip(),
                 observed_mode='slot 1, 쿠파주니어 RPG mode selection',
                 native_capture_max_channel_difference=int(diff.max()),
                 native_capture_mean_channel_difference=float(diff.mean()),
                 input_profile_unchanged=True,normal_stop='F5',subagents_used=False,Orca_used=False)
    (OUT/'runtime_verify.json').write_text(json.dumps(runtime,ensure_ascii=False,indent=2),encoding='utf8')
    record=dict(date='2026-10-10',status='second R stem/bottom touch-up installed and runtime verified',
                standalone_R_check=rcheck,assembly_check=art,archive=build,install=install,runtime=runtime,
                change='left face widened to cover residual gaps and maroon intrusions; artificial bottom rim removed; surface/hatch continued smoothly',
                R_png='R_clean.png',R_aligned_png='R_clean_aligned.png',R_affinity='R_touchup_20261010.af',
                assembly_affinity='KJ_assembled_R_touchup_20261010.af',R_sha256=sha(HERE/'R_clean.png'),
                original_OA_document_and_title_intro_FMdl_identical=True,
                recipe='work/img/kj_R_touchup_20261010/build_touchup_assembly.py')
    (HERE/'manifest.json').write_text(json.dumps(record,ensure_ascii=False,indent=2),encoding='utf8')
    report=f'''# R 왼쪽 경계·빈 부분·덧칠 이음선 추가 정리 — 2026-10-10

사용자가 올린 세 확대 이미지는 직전 `kj_R_polish_20261010/R_before_after.png`의 수정 열과 정확히 일치했다(RGB RMSE 0).
해당 위치를 원래 R 좌표로 환산해 추가 수정했다. 이전 작업과 기록은 보존한다.

## 수정한 부분

- 왼쪽 줄기의 녹색 면 경계를 약 1픽셀 바깥으로 옮겨, 남은 적갈색 침범과 경계의 빈칸을 정리했다.
- 아래 모서리는 기존 외곽 안에서 녹색 면을 이어 채웠다. 외곽 알파·구멍·위 몸통·오른쪽 다리는 동일하다.
- 지난 작업에서 추가한 밝은 하단 가장자리 효과를 제거했다. 이 효과와 불연속적인 면 색이 합쳐져 덧칠 이음선처럼 보였다.
- 원본 R의 노랑→초록 색과 사선 결을 측정하고, 행별 색을 부드럽게 연결한 뒤 원본 색 잔차를 주변 면에서 이어 받았다. Affinity native RGBA writer로 실제 픽셀을 적용했다.
- 사선 결 각도/주기는 기존 원본 측정값 59도/3.7픽셀. 새로운 서체나 다른 팔레트를 쓰지 않았다.
- 독립 R **{rcheck['R_changed_pixels']}픽셀** 변경. R 알파 및 좌표 보존 PNG 일치 확인.
- 새로 넓힌 줄기 면 내부의 어두운 적갈 픽셀 {rcheck['dark_pixels_inside_widened_stem_before']}→{rcheck['dark_pixels_inside_widened_stem_after']}. 색상 경사 내부의 최대 행간 RGB 변화 {rcheck['bottom_interior_max_row_colour_step_before']:.2f}→{rcheck['bottom_interior_max_row_colour_step_after']:.2f}. 이는 그림의 연속성 확인 수치이며 모든 시각적 취향을 판정하는 수치는 아니다.
- 이전처럼 18% 확대된 쿠파주니어 문구의 자형·위치·기울기·재질 및 두 바람은 파일 해시 동일. 실제 합성본은 R 위치의 **{art['final_changed_pixels']}픽셀**만 바뀌었다.

## 실제 화면 및 설치

- Affinity의 R 확대 비교와 조립본을 직접 렌더링해 확인했다.
- Codex 내장 computer-use로 Azahar 2126.1.2 실행 → 쿠파주니어 RPG 모드 선택 → Ctrl+P 원해상도 캡처 → F5 정상 중지.
- 원해상도 캡처 `{runtime['capture']}`. 상단 정적 그림 400×208과 빌드 입력의 채널 차이 최대 {runtime['native_capture_max_channel_difference']}, 평균 {runtime['native_capture_mean_channel_difference']:.6f}.
- 실제 바뀐 MLyt 텍스처는 `MENU_FILE_LOAD_JP_ja/timg/LOAD_GAME_IMG_KJ_R_00_JP_ja.bflim` 한 장. 나머지 SARC 파일과 BG4 항목은 바이트 동일, 재디코드 RGB565 일치.
- patch/Azahar 정션/SD 폴더/배포 ZIP **{install['checked_files']}파일** 일치, ZIP CRC PASS, lyt_stage 동기화.
- MLyt SHA256 `{install['MLyt_sha256']}`.
- 배포 ZIP SHA256 `{install['zip_sha256']}`.
- 직전 패치와 ZIP 백업: `work/build/prev_kj_R_touchup_20261010/`.
- 원래 OA Affinity 문서와 타이틀/인트로 FMdl은 해시 동일. 서브에이전트·Orca·Windows 별도 입력 스크립트 없음.
- `logo2/run_all.py`는 최신 `build_touchup_assembly.py`로 연결했다.

## 소재 및 편집 파일

- `R_clean.png`: 투명 R 60×63.
- `R_clean_aligned.png`: 400×208의 기존 좌표.
- `R_before_after.png`: 왼쪽 직전 / 가운데 추가 수정 / 오른쪽 배경 확인.
- `R_detail_before_after.png`: 침범·빈칸·이음선 부분(위 직전, 아래 수정).
- `R_touchup_20261010.af`: R 단독 편집본.
- `KJ_assembled_R_touchup_20261010.af`: 문구·R·바람 독립 레이어를 유지한 전체 편집본.
- `out/runtime_top.png`, `out/runtime_R_before_after.png`: 실제 게임 화면 및 확대 비교.
- `affinity_touchup_R.js`, `prepare_colours.py`, `colour_field.json`: native 수정 및 수치 자료.
- `KJ_R_touchup_editable_20261010.zip`: 최신 소재·문구 벡터·바람·Affinity 편집본·레시피·기록 묶음.
'''
    (HERE/'REPORT.md').write_text(report,encoding='utf8')
    state_path=ROOT/'work/lead_state.json'
    state=json.loads(state_path.read_text(encoding='utf8'))
    state['updated']='2026-10-10'
    state['kj_R_touchup_20261010']=dict(record,report='work/img/kj_R_touchup_20261010/REPORT.md')
    state_path.write_text(json.dumps(state,ensure_ascii=False,indent=1)+'\n',encoding='utf8')
    marker='## 쿠파주니어 R 잔여 침범·빈칸·이음선 추가 정리 (2026-10-10)'
    i4=ROOT/'work/img/I4.md'
    text=i4.read_text(encoding='utf8')
    if marker not in text:
        i4.write_text(text+'\n\n'+marker+f'\n- 왼쪽 면 경계 추가 확장과 빈칸 채움, 지난 밝은 하단선 제거 및 원본 색/결 연결. 독립 R {rcheck["R_changed_pixels"]}픽셀, 합성 R {art["final_changed_pixels"]}픽셀만 수정.\n- 문구/바람 동일, 외곽 알파 동일, KJ_R 텍스처만 변경. 실제 Azahar 모드 선택 확인 및 36파일 동기화·CRC PASS.\n- 최신 소재·Affinity·레시피·실제 캡처·기록: work/img/kj_R_touchup_20261010/. logo2/run_all.py 경로 갱신.\n',encoding='utf8')
    agents_path=ROOT/'AGENTS.md'
    agents=agents_path.read_text(encoding='utf8')
    entry=('   - 2026-10-10 (R 추가 정리): 사용자 지적 잔여 적갈 침범과 빈칸을 녹색 면 경계 확장으로 채우고, 지난 수정의 밝은 하단선을 제거해 이음선과 색/사선 결을 연결했다. '
           f'Affinity native 독립 R {rcheck["R_changed_pixels"]}픽셀·합성 R {art["final_changed_pixels"]}픽셀만 변경, 외곽 알파·문구·바람 동일. '
           'MLyt KJ_R 한 장만 수정, Codex 내장 computer-use로 Azahar 실제 모드 선택 확인, patch/정션/SD/ZIP 36파일 일치. '
           '최신 소재·Affinity·레시피·보고서: `work/img/kj_R_touchup_20261010/REPORT.md`, `R_clean.png`, `KJ_assembled_R_touchup_20261010.af`. logo2/run_all.py 갱신.\n')
    if entry not in agents:
        anchor='3. 2026-10-07: 후리가나 설정'
        assert anchor in agents
        agents_path.write_text(agents.replace(anchor,entry+anchor),encoding='utf8')
    package=HERE/'KJ_R_touchup_editable_20261010.zip'
    names=['R_clean.png','R_clean_aligned.png','R_before_after.png','R_detail_before_after.png',
           'R_touchup_20261010.af','KJ_assembled_R_touchup_20261010.af','REPORT.md','manifest.json',
           'affinity_touchup_R.js','affinity_assembly.js','prepare_colours.py','colour_field.json',
           'build_touchup_assembly.py','audit_R.py','out/fileload_KJ_assembled.png','out/runtime_after.png','out/runtime_R_before_after.png']
    with zipfile.ZipFile(package,'w',zipfile.ZIP_DEFLATED) as z:
        for name in names:z.write(HERE/name,name)
        for name in ['wind_top.png','wind_bottom.png']:z.write(ROOT/'work/img/kj_parts_20261009'/name,name)
        for p in (HERE/'affinity').iterdir():
            if p.is_file():z.write(p,p.relative_to(HERE).as_posix())
    with zipfile.ZipFile(package) as z:assert z.testzip() is None
    print(json.dumps(runtime,ensure_ascii=False,indent=2))
    print('Updated assets, runtime proof, install history, and editing bundle recorded.')


if __name__=='__main__':main()
