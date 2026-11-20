from pathlib import Path
import datetime,json
ROOT=Path(__file__).resolve().parents[3];OUT=Path(__file__).parent
state_path=ROOT/'work/lead_state.json'
state=json.loads(state_path.read_text(encoding='utf8'))
install=json.loads((OUT/'install.json').read_text(encoding='utf8'))
state['phase']='2026-10-08 인트로 & 수정과 타이틀 1DX 비율·화면 배치 완료. 두 실루엣 모두 마리오 위(리/오)로 배치·설치. patch/SD ZIP 동기화, 실제 게임 화면 확인 대기.'
state['build']['latest']='2026-10-08: Luigi silhouette moved above 오 beside Mario above 리, matching 1DX. Only old/new Luigi silhouette pixel regions in title bottom texture differ; all other texture/geometry/animation and intro & bytes identical. FMdl installed; all patch/Azahar-junction/SD/ZIP files match, ZIP CRC PASS. Backup work/build/prev_title_silhouettes_20261008/. No game launched.'
state['title_silhouettes_20261008']={'report':'work/img/title_silhouettes_20261008/REPORT.md',
    'preview':'work/img/title_silhouettes_20261008/title_before_after.png',
    'positions':{'mario':'리','luigi':'오'},'install':install,'runtime_verified':False,'subagents_used':False,
    'timestamp':datetime.datetime.now(datetime.timezone(datetime.timedelta(hours=9))).isoformat()}
state_path.write_text(json.dumps(state,ensure_ascii=False,indent=1)+'\n',encoding='utf8')
note='''\n\n## 13. 두 실루엣 모두 마리오 위로 배치 (2026-10-08, 사용자 추가 지침)\n- 1DX처럼 마리오 「리」 위, 루이지 「오」 위로 확정. `title_layout_20261008/build_title.py`의 대상 음절을 ri/o로 변경했다.\n- 글자 비율·전체 제목 크기/배치와 DX·디럭스 중앙 정렬 동일. FMdl 재읽기에서 아래 타이틀 텍스처의 루이지 이전/새 위치 주변만 변경. 다른 텍스처·모델·애니메이션·인트로 & 바이트 모두 동일.\n- patch/정션/SD/ZIP 일치, ZIP CRC PASS. 이전 파일: `work/build/prev_title_silhouettes_20261008/`. 보고서/비교: `work/img/title_silhouettes_20261008/REPORT.md`, `title_before_after.png`. 실제 게임은 사용자 확인 대기.\n'''
i4=ROOT/'work/img/I4.md';i4.write_text(i4.read_text(encoding='utf8')+note,encoding='utf8')
report=ROOT/'work/img/title_layout_20261008/REPORT.md'
report.write_text(report.read_text(encoding='utf8')+'\n\n후속 사용자 지침: 루이지는 「이」 대신 「오」 위로 옮겨 두 실루엣을 모두 「마리오」 위에 배치했다. 최종 기록은 `work/img/title_silhouettes_20261008/REPORT.md`.\n',encoding='utf8')
print('Recorded final 1DX silhouette placement')
