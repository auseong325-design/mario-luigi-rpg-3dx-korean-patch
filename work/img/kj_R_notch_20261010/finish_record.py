from pathlib import Path
import hashlib,json,zipfile
import numpy as np
from PIL import Image

HERE=Path(__file__).resolve().parent
ROOT=HERE.parents[2]
OUT=HERE/'out'
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()


def main():
    art=json.loads((OUT/'R_only_verify.json').read_text(encoding='utf8'))
    build=json.loads((OUT/'build_verify.json').read_text(encoding='utf8'))
    install=json.loads((OUT/'install.json').read_text(encoding='utf8'))
    old=np.asarray(Image.open(ROOT/'work/img/kj_R_touchup_20261010/R_clean.png').convert('RGBA'))
    new=np.asarray(Image.open(HERE/'R_clean.png').convert('RGBA'))
    assert np.array_equal(old[...,3],new[...,3])
    assert np.array_equal(new,np.asarray(Image.open(HERE/'R_clean_aligned.png').convert('RGBA'))[140:203,201:261])
    yy,xx=np.nonzero(np.any(old!=new,2))
    rcheck=dict(changed_pixels=len(xx),changed_bbox=[int(xx.min()+201),int(yy.min()+140),int(xx.max()+201),int(yy.max()+140)],alpha_and_aligned_export_identical=True)
    (HERE/'R_verify.json').write_text(json.dumps(rcheck,indent=2),encoding='utf8')
    assert sha(ROOT/'patch/00040000001CA900/romfs/FMdl/JP/FMdl.dat')=='2d7819214886f6e973810940ff69f4096c254cd8da30381983e52ac519cefcad'
    assert sha(Path('C:/Users/woose/Desktop/ml3dx_kj_affinity/OA_kupajunior_logo.af'))=='164315b9f50245a83c5e7b80d4e98de8583179cbc9ac088717df68d5a280d98e'
    shot=Image.open(OUT/'runtime_after.png').convert('RGB')
    assert shot.size==(400,480)
    expected=np.asarray(Image.open(OUT/'fileload_KJ_assembled.png').convert('RGB')).astype(int)
    delta=np.abs(np.asarray(shot)[:208].astype(int)-expected)
    assert delta.max()<=2
    shot.crop((0,0,400,240)).save(OUT/'runtime_top.png')
    runtime=dict(method='Codex built-in @oai/sky computer-use',emulator='Azahar 2126.1.2',capture=(OUT/'runtime_source.txt').read_text(encoding='utf-8-sig').strip(),max_channel_difference=int(delta.max()),mean_channel_difference=float(delta.mean()),input_profile_unchanged=True,normal_stop='F5',subagents_used=False,Orca_used=False)
    (OUT/'runtime_verify.json').write_text(json.dumps(runtime,ensure_ascii=False,indent=2),encoding='utf8')
    record=dict(date='2026-10-10',status='R inner notch edge polished, assembled, installed and runtime verified',R=rcheck,assembly=art,archive=build,install=install,runtime=runtime,recipe='work/img/kj_R_notch_20261010/build_notch_assembly.py',R_affinity='R_notch_20261010.af',assembly_affinity='KJ_assembled_R_notch_20261010.af')
    (HERE/'manifest.json').write_text(json.dumps(record,ensure_ascii=False,indent=2),encoding='utf8')
    report=f'''# R 다리 사이 꼭짓점 및 사선 경계 정리 — 2026-10-10

사용자 확대 이미지의 두 다리 사이 꼭짓점과 아래 사선에서 밝은 테/적갈색 경계가 불규칙하게 섞여 보이는 부분을 추가 정리했다.

- 안쪽 꼭짓점을 작게 둥글려 튀어나온 밝은 점을 정리했다.
- 세로와 사선 경계를 하나의 연속된 경로로 만들고, 얇은 밝은 테의 두께를 맞췄다.
- 적갈 경계 내부의 잡색을 주변의 깊은 적갈색으로 맞췄다. 녹색 면은 직전 원본 재질 필드를 이용해 색과 사선 결을 연결했다.
- Affinity native RGBA 픽셀 편집으로 독립 R {rcheck['changed_pixels']}픽셀 수정. 알파/외곽과 좌표 보존 PNG 동일.
- 기존 18% 문구의 자형·크기·위치·재질, 바람 두 장의 픽셀/배치는 해시 동일. 합성본은 R 위치 {art['final_changed_pixels']}픽셀만 변경.
- Affinity 확대 비교 `R_notch_detail.png`: 왼쪽 직전 / 오른쪽 수정, 12배 nearest 확대. `R_before_after.png`: 직전 / 수정 / 파란 배경.
- 실제 변경 MLyt 텍스처는 KJ_R 한 장. 다른 SARC 파일과 BG4 항목 바이트 동일, RGB565 재디코드 일치.
- Codex 내장 computer-use로 Azahar 모드 선택을 직접 확인하고 Ctrl+P 캡처 후 F5 정상 중지. 입력 프로필 변경 없음.
- 실제 캡처 `{runtime['capture']}`의 상단 정적 그림과 설치 PNG 채널 차이 최대 {runtime['max_channel_difference']}, 평균 {runtime['mean_channel_difference']:.6f}.
- patch/정션/SD/ZIP {install['checked_files']}파일 일치 및 ZIP CRC PASS. lyt_stage 동기화.
- MLyt SHA256 `{install['MLyt_sha256']}`.
- 배포 ZIP SHA256 `{install['zip_sha256']}`.
- 원래 OA Affinity 파일 및 타이틀/인트로 FMdl 동일. 서브에이전트·Orca·별도 입력 스크립트 사용 없음.
- 직전 MLyt/ZIP 백업: `work/build/prev_kj_R_notch_20261010/`.
- 최신 레시피: `build_notch_assembly.py`, `affinity_notch_R.js`. `logo2/run_all.py` 연결 갱신.
- 소재: `R_clean.png`, `R_clean_aligned.png`, `R_notch_20261010.af`, `KJ_assembled_R_notch_20261010.af`.
'''
    (HERE/'REPORT.md').write_text(report,encoding='utf8')
    sp=ROOT/'work/lead_state.json'
    state=json.loads(sp.read_text(encoding='utf8'));state['updated']='2026-10-10';state['kj_R_notch_20261010']=record
    sp.write_text(json.dumps(state,ensure_ascii=False,indent=1)+'\n',encoding='utf8')
    marker='## 쿠파주니어 R 다리 사이 꼭짓점/사선 추가 정리 (2026-10-10)'
    p=ROOT/'work/img/I4.md';s=p.read_text(encoding='utf8')
    if marker not in s:p.write_text(s+'\n\n'+marker+'\n- 꼭짓점의 밝은 돌기와 안쪽 경계 잡색 정리, 연속된 세로/사선 테. 독립 R 100픽셀·합성 84픽셀만 변경. 문구/바람/외곽 알파 동일.\n- KJ_R 한 장만 교체, Azahar 직접 확인, 36파일 동기화·CRC PASS. 최신 work/img/kj_R_notch_20261010/, logo2/run_all.py 갱신.\n',encoding='utf8')
    ap=ROOT/'AGENTS.md';s=ap.read_text(encoding='utf8')
    entry='   - 2026-10-10 (R 안쪽 꼭짓점): 두 다리 사이 밝은 돌기와 세로/사선 경계의 잡색을 정리했다. Affinity native R 100픽셀·합성 84픽셀만 변경, 외곽 알파·문구·바람 동일. MLyt KJ_R 한 장만 교체, Codex 내장 computer-use로 Azahar 모드 선택 직접 확인, patch/정션/SD/ZIP 36파일 일치. 최신 소재·Affinity·레시피·기록: `work/img/kj_R_notch_20261010/REPORT.md`. logo2/run_all.py 갱신.\n'
    if entry not in s:
        anchor='3. 2026-10-07: 후리가나 설정';assert anchor in s;ap.write_text(s.replace(anchor,entry+anchor),encoding='utf8')
    package=HERE/'KJ_R_notch_editable_20261010.zip'
    names=['R_clean.png','R_clean_aligned.png','R_before_after.png','R_notch_detail.png','R_notch_20261010.af','KJ_assembled_R_notch_20261010.af','REPORT.md','manifest.json','affinity_notch_R.js','affinity_assembly.js','colour_field.json','build_notch_assembly.py','out/fileload_KJ_assembled.png','out/runtime_after.png']
    with zipfile.ZipFile(package,'w',zipfile.ZIP_DEFLATED) as z:
        for name in names:z.write(HERE/name,name)
        for p in (HERE/'affinity').iterdir():
            if p.is_file():z.write(p,p.relative_to(HERE).as_posix())
    with zipfile.ZipFile(package) as z:assert z.testzip() is None
    print(json.dumps(runtime,ensure_ascii=False,indent=2))


if __name__=='__main__':main()
