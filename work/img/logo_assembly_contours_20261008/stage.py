from pathlib import Path
import json,shutil
ROOT=Path(__file__).resolve().parents[3];OUT=Path(__file__).parent
BACKUP=ROOT/'work/build/prev_logo_assembly_contours_20261008'
result=json.loads((OUT/'art_verify.json').read_text())
assert result['approved_ru_ji_lower_contours_restored'] and result['intro_common_scale_and_baseline']
names=['title_logo_JP_bottom','title_logo_JP_top','title_logo_M_JP','title_logo_L_JP','title_logo_and_JP']
for folder in [ROOT/'work/img/fmdl_ko/fmd_title_JP_ja',ROOT/'work/img/logo2/out']:
    backup=BACKUP/('fmdl_inputs' if 'fmdl_ko' in folder.parts else 'logo2_inputs')
    backup.mkdir(parents=True,exist_ok=True)
    for name in names:
        target=folder/(name+'.png');saved=backup/target.name
        assert not saved.exists(),'Preserve prior input snapshot: '+str(saved)
        shutil.copy2(target,saved)
    for name in names:
        target=folder/(name+'.png');tmp=target.with_suffix('.assembly_contours.tmp')
        assert not tmp.exists()
        tmp.write_bytes((OUT/target.name).read_bytes());tmp.replace(target)
print('Staged all five title PNGs; previous inputs saved to',BACKUP)
