from pathlib import Path
import hashlib,json,os,shutil,sys
ROOT=Path(__file__).resolve().parents[3];OUT=Path(__file__).parent
sys.path.insert(0,str(ROOT/'scripts'))
import build_fmdl,lib3dx
assert not (OUT/'before_fmdl.dat').exists()
raw,models=build_fmdl.load(ROOT/'patch/00040000001CA900/romfs/FMdl/JP/FMdl.dat')
(OUT/'before_fmdl.dat').write_bytes(raw)
(OUT/'before_title.bch').write_bytes(models['fmd_title_JP_ja'][1])
source=ROOT/'work/img/logo_assembly_contours_20261008'
for name in ['build_intro.py','intro_layout.json','intro_masks.npz','original_geometry.json','animation_frames.json']:
    shutil.copy2(source/name,OUT/('before_'+name))
shutil.copy2(ROOT/'work/img/fmdl_geometry_patches.json',OUT/'before_geometry_plan.json')
shutil.copy2(Path('C:/Users/woose/OneDrive - 남창고등학교/사진/그림/스크린샷/스크린샷 2026-10-08 154346.png'),OUT/'user_issue.png')
(OUT/'before.json').write_text(json.dumps({'before_fmdl_sha256':hashlib.sha256(raw).hexdigest(),
       'codex_computer_use_error':'Windows Computer Use Sky runtime is unavailable',
       'orca_computer_use_error':'runtime_open_timeout; orca-runtime.json unavailable',
       'gui_fallback':'native Windows window capture and keyboard input',
       'user_authorized_azahar':True},indent=2)+'\n',encoding='utf8')
print('Snapshot saved')
