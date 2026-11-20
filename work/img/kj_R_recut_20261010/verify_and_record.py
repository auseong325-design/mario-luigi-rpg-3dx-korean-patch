"""Verify the fresh Affinity export against the actual ROM, and package materials."""
from pathlib import Path
import json,hashlib,zipfile
import numpy as np
from PIL import Image

HERE=Path(__file__).resolve().parent
ROOT=HERE.parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()


def main():
    g=json.loads((HERE/'cutout_geometry.json').read_text(encoding='utf8'))
    source=np.asarray(Image.open(HERE/'source_R_region.png').convert('RGB'))
    top=np.asarray(Image.open(HERE/'R_original_cutout.png').convert('RGBA'))
    below=np.asarray(Image.open(HERE/'R_restore_underlay.png').convert('RGBA'))
    final=np.asarray(Image.open(HERE/'R_clean.png').convert('RGBA'))
    aligned=np.asarray(Image.open(HERE/'R_clean_aligned.png').convert('RGBA'))
    original=np.asarray(g['original_inner'],bool)
    assert np.array_equal(top[original,:3],source[original])
    assert np.all(top[original,3]==255)
    assert np.array_equal(final[original,:3],source[original])
    assert np.all(final[original,3]==255)
    assert np.array_equal(final,aligned[140:203,201:261])
    covered=np.asarray(g['covered'],bool)
    assert not np.any((below[...,3]>0)&~covered),'Restoration escaped its occlusion mask'
    ta,ba=top[...,3:]/255,below[...,3:]/255
    alpha=ta+ba*(1-ta)
    comp=(top[...,:3]*ta+below[...,:3]*ba*(1-ta))/np.maximum(alpha,1e-9)
    expected=np.concatenate([comp,alpha*255],2)
    error=np.abs(final.astype(float)-expected)
    assert error[final[...,3]>0].max()<=2,error.max()
    assert sha(Path(g['source_ROM']))==g['source_ROM_sha256']
    patch=ROOT/'patch/00040000001CA900/romfs/Lyt/JP/MLyt.dat'
    distro=ROOT/'work/sd_package/ml3dx_ko_luma.zip'
    assert sha(patch)=='cb172fbe843269aa75a675752cdf94a9a6e30d611bc7f4a26931f38330d41664'
    assert sha(distro)=='beff425ef955f1d3148daf600e971e7647f7d2f17e198da154fdf9b76340c7be'
    verify=dict(date='2026-10-10',status='fresh R material extracted/restored in Affinity; existing installed composition retained',
                source_ROM=g['source_ROM'],source_ROM_sha256=g['source_ROM_sha256'],
                fresh_source_not_previous_repaired_R=True,
                unchanged_original_face_rim_counter_and_legs_pixels=int(original.sum()),
                original_cutout_nontransparent_pixels=int((top[...,3]>0).sum()),
                restoration_underlay_pixels=int((below[...,3]>0).sum()),
                restoration_only_in_covered_regions=True,
                reference='user-supplied Korean 1DX 쿠파군단 RPG R; silhouette only',
                reference_fit=g['reference_fit'],
                layered_composite_max_difference=float(error[final[...,3]>0].max()),
                aligned_export_exact=True,R_sha256=sha(HERE/'R_clean.png'),
                installed_patch_sha256=sha(patch),distribution_zip_sha256=sha(distro),
                installed_patch_and_distribution_unchanged=True,subagents_used=False,
                Affinity_documents=['R_recut_20261010.af','R_recut_aligned_20261010.af'])
    (HERE/'manifest.json').write_text(json.dumps(verify,ensure_ascii=False,indent=2),encoding='utf8')
    report=f'''# 일본판 ROM에서 R 새 누끼 및 가려진 외곽 복원 — 2026-10-10

## 출처와 범위

- 최신 사용자 요청: 기존 수리본을 다시 다듬는 대신, Affinity에서 일본판 ROM의 R을 새로 분리하고 쿠파군단 RPG R의 획을 참고해 가려진 부분을 겹쳐 채운다.
- `lib3dx.romfs_path('Lyt/JP/MLyt.dat')`로 원본 ROM을 직접 읽고 `MENU_FILE_LOAD_JP_ja`의 KJ 좌우 BFLIM을 다시 디코드했다. 이전 R 수리본을 입력으로 쓰지 않았다.
- 원본 ROM SHA256 `{g['source_ROM_sha256']}`. 읽기 전용으로 유지되었음을 확인했다.
- 작업 결과는 독립 R 소재다. 현재 설치된 직전 faithful/corner 조립본과 배포 ZIP은 그대로이며, 이번 요청에서 게임 조립본 교체는 수행하지 않았다.

## Affinity의 겹침 구성

1. **위: 원본 누끼** — 원본 면·밝은 테·R 구멍·두 다리 {int(original.sum())}픽셀을 그대로 보존했다. 어두운 원본 외곽도 보이는 곳은 원본에서 추출했다. 흰 바탕에 합성되어 있던 반투명 가장자리는 흰색 성분을 풀어 투명화했다.
2. **아래: 가려진 외곽 보완** — 일본어 Jr. 문구·바람·별/클라운·옆 P와 겹친 외곽만 채웠다. 보완 색은 원본 R의 깨끗한 적갈색 외곽에서 가져왔다.
3. 쿠파군단 R의 면 실루엣을 현 R 좌표에 맞춘 뒤, 가려진 왼쪽 획/발의 곧은 외곽을 잇는 데 참고했다. 참고 로고의 금색 재질을 이식하지 않았다. 같은 서체여도 조형이 약간 달라 면 전체를 바꾸지 않았다(면 실루엣 대응 IoU {g['reference_fit']['face_iou']:.3f}).
4. 별·P·Jr.의 색이 누끼에 섞이지 않도록 가림 마스크를 분리했다. 두 다리 사이의 원본 적갈 외곽도 유지했다.

## 확인

- Affinity native Bitmap/PixelReader/PixelWriter로 원본 누끼와 외곽 보완을 각각 만든 후 원본을 위에 겹쳤다. 두 레이어가 별도로 편집 가능한 Affinity 문서를 저장했다.
- 흰색/파란색 배경을 Affinity에서 렌더링해 확인했다.
- 원본 면/테/구멍/두 다리 {int(original.sum())}픽셀의 RGB와 불투명도가 ROM 디코드와 정확히 일치한다.
- 보완 레이어는 가림 마스크 안에만 있다. 레이어 합성과 최종 export 차이는 최대 {verify['layered_composite_max_difference']:.3f}/255로 내보내기 반올림 범위다.
- 60×63 투명 R과 400×208 좌표 보존 export가 정확히 일치한다. 원점 (201,140).
- 설치 MLyt/배포 ZIP 해시 동일. 원본 게임 파일 수정 및 서브에이전트 사용 없음.

## 파일

- `R_clean.png`: 겹쳐 채운 최종 투명 R.
- `R_original_cutout.png`: 원본에서 새로 분리한 위 레이어.
- `R_restore_underlay.png`: 가려진 외곽만 채운 아래 레이어.
- `R_clean_aligned.png`: 원래 400×208 좌표에 놓인 R.
- `R_recut_20261010.af`: 60×63, 원본/보완 독립 레이어 및 숨긴 ROM 참고.
- `R_recut_aligned_20261010.af`: 400×208, 같은 독립 레이어.
- `R_preview.png`: 최종 R 흰색/파란색 배경.
- `R_source_and_recut.png`: 실제 ROM 원본 영역 / 새 R 흰색 / 새 R 파란색.
- `reference_R_crop.png`, `reference_1dx.png`: 사용자 참고 자료.
- `prepare_source.py`, `cutout_geometry.json`, `affinity_recut_R.js`: 원본 추출/마스크 측정/실제 Affinity 작업.
- `R_recut_materials_20261010.zip`: 최신 독립 R 소재 및 편집본 묶음.
'''
    (HERE/'REPORT.md').write_text(report,encoding='utf8')
    state_path=ROOT/'work/lead_state.json'
    state=json.loads(state_path.read_text(encoding='utf8'))
    state['updated']='2026-10-10';state['kj_R_recut_20261010']=dict(verify,report='work/img/kj_R_recut_20261010/REPORT.md')
    state_path.write_text(json.dumps(state,ensure_ascii=False,indent=1)+'\n',encoding='utf8')
    entry=('   - 2026-10-10 (R 새 누끼 소재): 사용자 요청으로 Affinity에서 일본판 ROM을 직접 재추출해 R 원본 누끼를 새로 만들었다. '
           '원본 면·테·구멍·두 다리 1,482픽셀 그대로, 가려진 외곽은 사용자 쿠파군단 R의 획을 맞춰 원본 적갈색으로 아래 레이어에 보완하고 원본을 위에 겹쳤다. '
           '원본/보완 PNG·독립 레이어 Affinity·좌표 보존본 저장 및 검증. 이번 결과는 소재 작업이며 설치 조립본/배포 ZIP은 직전 faithful/corner판 동일. '
           '최신 소재·편집본·기록: `work/img/kj_R_recut_20261010/REPORT.md`, `R_recut_20261010.af`.\n')
    ap=ROOT/'AGENTS.md';s=ap.read_text(encoding='utf8');anchor='3. 2026-10-07: 후리가나 설정'
    if entry not in s:assert anchor in s;ap.write_text(s.replace(anchor,entry+anchor),encoding='utf8')
    i4=ROOT/'work/img/I4.md';s=i4.read_text(encoding='utf8');marker='## R 일본판 원본 새 누끼 소재 (2026-10-10)'
    if marker not in s:i4.write_text(s+'\n\n'+marker+'\n- 이전 R 수리본 대신 ROM 직접 재디코드, Affinity 원본/보완 독립 레이어. 1,482 원본 면 픽셀 그대로, 가림 외곽만 참고 R 획에 맞춰 아래에 겹침.\n- 최신 work/img/kj_R_recut_20261010/. 소재 완료, 설치 faithful/corner 조립본/배포 ZIP 동일.\n',encoding='utf8')
    package=HERE/'R_recut_materials_20261010.zip'
    names=['R_clean.png','R_original_cutout.png','R_restore_underlay.png','R_clean_aligned.png','R_recut_20261010.af','R_recut_aligned_20261010.af','R_preview.png','R_source_and_recut.png','source_original_JP.png','source_R_region.png','reference_1dx.png','reference_R_crop.png','REPORT.md','manifest.json','prepare_source.py','cutout_geometry.json','affinity_recut_R.js']
    with zipfile.ZipFile(package,'w',zipfile.ZIP_DEFLATED) as z:
        for name in names:z.write(HERE/name,name)
    with zipfile.ZipFile(package) as z:assert z.testzip() is None
    print(json.dumps(verify,ensure_ascii=False,indent=2))


if __name__=='__main__':main()
