from pathlib import Path
import shutil
ROOT=Path(__file__).resolve().parents[3];OUT=Path(__file__).parent
BACKUP=ROOT/'work/build/prev_title_lower_shading_20261008'
assert not BACKUP.exists(),'Preserve previous inputs'
(BACKUP/'fmdl_ko').mkdir(parents=True)
for name in ['title_logo_JP_bottom.png','title_logo_JP_top.png']:
    data=(OUT/name).read_bytes()
    for directory in [ROOT/'work/img/fmdl_ko/fmd_title_JP_ja',ROOT/'work/img/logo2/out']:
        target=directory/name
        if target.read_bytes()==data:continue
        if 'fmdl_ko' in directory.parts:shutil.copy2(target,BACKUP/'fmdl_ko'/name)
        temporary=target.with_suffix('.lower_shading.tmp')
        temporary.write_bytes(data);temporary.replace(target)
print('Staged restored ji cap and 1DX underside with Japanese 3DX shading')
