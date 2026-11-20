const fs=require('fs'),path=require('path'),crypto=require('crypto');
const root=path.resolve(__dirname,'../../..'),out=__dirname;
const sha=p=>crypto.createHash('sha256').update(fs.readFileSync(p)).digest('hex');
const mlyt=path.join(root,'patch/00040000001CA900/romfs/Lyt/JP/MLyt.dat');
const pkg=path.join(root,'work/sd_package/ml3dx_ko_luma.zip');
const sourceAf='C:/Users/woose/Desktop/ml3dx_kj_affinity/OA_kupajunior_logo.af';
if(sha(mlyt)!=='b4838b8b204d922611a9adc5e01b0ca9c42c5008deb78899855f4ab7d03aa0c6')throw Error('patch changed');
if(sha(pkg)!=='6a220553d39549534dd5acc83392698e556835f9c6c360f86eff60df9cc28a70')throw Error('distribution changed');
if(sha(sourceAf)!=='164315b9f50245a83c5e7b80d4e98de8583179cbc9ac088717df68d5a280d98e')throw Error('source Affinity document changed');
const extract=JSON.parse(fs.readFileSync(path.join(out,'extraction.json'),'utf8'));
const verify=JSON.parse(fs.readFileSync(path.join(out,'verify.json'),'utf8'));
const names=['R_clean','wind_top','wind_bottom'];
const manifest={started_date:'2026-10-09',completed_date:'2026-10-10',coordinate_space:[400,208],
  assets:verify.checks.map(a=>({...a,png:a.name+'.png',aligned:a.name+'_aligned.png',sha256:sha(path.join(out,a.name+'.png'))})),
  method:'Affinity MCP native raster extraction and localized restoration',affinity_file:'KJ_parts_20261009.af',
  layered_affinity_sha256:sha(path.join(out,'KJ_parts_20261009.af')),source_affinity_unchanged:true,
  installed_patch_unchanged:true,distribution_zip_unchanged:true,subagents_used:false};
fs.writeFileSync(path.join(out,'manifest.json'),JSON.stringify(manifest,null,2)+'\n');
const statePath=path.join(root,'work/lead_state.json'),state=JSON.parse(fs.readFileSync(statePath,'utf8'));
state.updated='2026-10-10';
state.kj_parts_20261009={status:'completed independent asset extraction; final logo composition is the next step',
  report:'work/img/kj_parts_20261009/README.md',manifest:'work/img/kj_parts_20261009/manifest.json',
  extraction:extract,verify,patch_installed:false,source_OA_document_untouched:true,subagents_used:false};
fs.writeFileSync(statePath,JSON.stringify(state,null,1)+'\n');
const append=(file,marker,body)=>{let s=fs.readFileSync(file,'utf8');if(!s.includes(marker))fs.writeFileSync(file,s.trimEnd()+'\n\n'+body.trim()+'\n');};
append(path.join(root,'work/img/I4.md'),'## 쿠파주니어 R·바람 분리 소재 (2026-10-10)',`
## 쿠파주니어 R·바람 분리 소재 (2026-10-10)
- 사용자 지시로 클로드의 한글 자형을 유지하고 최종 합성 전 독립 소재부터 만들었다. Affinity MCP로 원본 픽셀을 추출해 R 왼쪽/하단의 가린 적갈 테와 바람의 가린 꼬리를 복원했다.
- R_clean 60×63, wind_top 40×30, wind_bottom 21×21 투명 PNG와 원래 위치의 400×208 aligned PNG. 세 이미지가 독립 레이어인 KJ_parts_20261009.af도 저장했다.
- 흰/어두운/파란 배경 검수, R 면·사선 결 원본 보존, 불투명 흰색 내부·부분 알파 존재, crop/aligned RGBA 일치 확인. 원래 OA 문서와 patch/ZIP은 그대로다. 서브에이전트 사용 없음.
- 보고서·소재·재현 스크립트: work/img/kj_parts_20261009/README.md, manifest.json, affinity_extract.js, affinity_proof.js.
`);
const agents=path.join(root,'AGENTS.md');let ag=fs.readFileSync(agents,'utf8');
const entry='   - 2026-10-10: 사용자 요청으로 쿠파주니어 로고의 R과 위·아래 바람 이펙트를 Affinity MCP에서 독립 투명 소재로 분리했다. R의 문구·이펙트에 가린 테두리와 바람 꼬리만 복원했고 글자 면·사선 결은 보존했다. 개별 PNG·400×208 좌표 보존 PNG·독립 레이어 Affinity 파일을 저장했다. 최종 합성 전 소재 작업이며 기존 OA 문서·패치·배포 ZIP은 동일하다. 기록: `work/img/kj_parts_20261009/README.md`, `manifest.json`.\n';
if(!ag.includes(entry)){const marker='3. 2026-10-07: 후리가나 설정';if(!ag.includes(marker))throw Error('AGENTS insertion anchor missing');fs.writeFileSync(agents,ag.replace(marker,entry+marker));}
console.log(JSON.stringify({assets:manifest.assets.map(x=>({name:x.name,size:x.size,origin:x.origin})),patch_unchanged:true,zip_unchanged:true,source_affinity_unchanged:true,records_updated:true},null,2));
