from pathlib import Path
import shutil
ROOT=Path(__file__).resolve().parents[3];OUT=Path(__file__).parent
SOURCE=ROOT/'work/img/title_layout_20261008'
BACKUP=ROOT/'work/build/prev_title_1dx_shapes_20261008'
assert not BACKUP.exists(),'Preserve existing backup'
(BACKUP/'fmdl_ko').mkdir(parents=True)
for name in ['title_logo_JP_bottom','title_logo_JP_top']:
    shutil.copy2(SOURCE/(name+'.png'),OUT/(name+'.png'))
for name in ['title_logo_JP_bottom','title_logo_JP_top','title_logo_and_JP']:
    desired=(OUT/(name+'.png')).read_bytes()
    for directory in [ROOT/'work/img/fmdl_ko/fmd_title_JP_ja',ROOT/'work/img/logo2/out']:
        target=directory/(name+'.png')
        if target.exists() and target.read_bytes()==desired:continue
        if 'fmdl_ko' in directory.parts and target.exists():shutil.copy2(target,BACKUP/'fmdl_ko'/target.name)
        temporary=target.with_suffix('.1dx_shapes.tmp')
        temporary.write_bytes(desired);temporary.replace(target)
for name in ['title_masks.npz','layout_metrics.json','preview_title.py']:
    shutil.copy2(SOURCE/name,OUT/name)
print('Staged 1DX title word shapes and intro &')
