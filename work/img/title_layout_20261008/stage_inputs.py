from pathlib import Path
import hashlib,json,shutil,sys
ROOT=Path(__file__).resolve().parents[3];OUT=Path(__file__).parent
BACKUP=ROOT/'work/build/prev_title_layout_20261008'
sys.path.insert(0,str(ROOT/'scripts'))
import libbch
from PIL import Image
import numpy as np
before=libbch.Bch((OUT/'before_title.bch').read_bytes())
dst_dir=ROOT/'work/img/fmdl_ko/fmd_title_JP_ja'
(BACKUP/'fmdl_ko').mkdir(parents=True,exist_ok=True)
files=[]
for name in ['title_logo_JP_bottom','title_logo_JP_top']:
    src=OUT/(name+'.png');dst=dst_dir/(name+'.png')
    with Image.open(dst) as opened:
        original=np.array(opened.convert('RGBA'))
    assert np.array_equal(before.decode(before.texture(name)),original),'Installed title differs from the stored builder input'
    backup=BACKUP/'fmdl_ko'/dst.name
    if backup.exists():assert backup.read_bytes()==dst.read_bytes(),'Preserve differing backup'
    else:shutil.copy2(dst,backup)
    # Atomic replacement also avoids CopyFile2 failing on a mapped image preview.
    temporary=dst.with_name(dst.name+'.title_layout.tmp')
    temporary.write_bytes(src.read_bytes())
    temporary.replace(dst)
    files.append({'name':name,'sha256':hashlib.sha256(dst.read_bytes()).hexdigest()})
(OUT/'inputs_staged.json').write_text(json.dumps(files,indent=2)+'\n',encoding='utf8')
print('Staged two title PNGs; previous input PNGs backed up')
