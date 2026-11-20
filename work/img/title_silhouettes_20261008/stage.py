from pathlib import Path
import shutil
ROOT=Path(__file__).resolve().parents[3];OUT=Path(__file__).parent
SOURCE=ROOT/'work/img/title_layout_20261008'
BACKUP=ROOT/'work/build/prev_title_silhouettes_20261008'
assert not BACKUP.exists(),'Preserve existing backup'
(BACKUP/'fmdl_ko').mkdir(parents=True)
for name in ['title_logo_JP_bottom','title_logo_JP_top']:
    desired=(SOURCE/(name+'.png')).read_bytes()
    (OUT/(name+'.png')).write_bytes(desired)
    for directory in [ROOT/'work/img/fmdl_ko/fmd_title_JP_ja',ROOT/'work/img/logo2/out']:
        target=directory/(name+'.png')
        if target.read_bytes()==desired:continue
        if 'fmdl_ko' in directory.parts:shutil.copy2(target,BACKUP/'fmdl_ko'/target.name)
        temporary=target.with_suffix('.silhouettes.tmp')
        temporary.write_bytes(desired);temporary.replace(target)
for name in ['title_masks.npz','layout_metrics.json','screen_mapping.json','preview_title.py']:
    shutil.copy2(SOURCE/name,OUT/name)
print('Staged Luigi over 오; preserved current title/DX layout')
