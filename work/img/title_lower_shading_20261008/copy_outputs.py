from pathlib import Path
import shutil,sys
import numpy as np
ROOT=Path(__file__).resolve().parents[3];OUT=Path(__file__).parent
SOURCE=ROOT/'work/img/title_layout_20261008'
for name in ['title_logo_JP_bottom.png','title_logo_JP_top.png','layout_metrics.json','title_masks.npz']:
    target=OUT/name;temporary=target.with_suffix('.review.tmp')
    temporary.write_bytes((SOURCE/name).read_bytes());temporary.replace(target)
sys.path.insert(0,str(ROOT/'work/img/logo2'))
import l2
before=l2.comp_on(l2.load(OUT/'title_logo_JP_bottom_before.png'))
after=l2.comp_on(l2.load(OUT/'title_logo_JP_bottom.png'))
jp=l2.comp_on(l2.load(l2.JP_DIR/'title_logo_JP_bottom.png'))
donor=l2.comp_on(l2.load(l2.KR1DX))
l2.sheet([
    [('BEFORE underside',l2.zoom_img(before[115:162,10:328],4))],
    [('AFTER underside',l2.zoom_img(after[115:162,10:328],4))],
    [('Japanese 3DX reference',l2.zoom_img(jp[107:145,50:278],4))],
    [('1DX silhouette / shading pattern',l2.zoom_img(donor[65:104,1:338],3))],
    [('BEFORE ji',l2.zoom_img(before[85:155,269:327],6)),('AFTER ji',l2.zoom_img(after[85:155,269:327],6))],
],OUT/'detail_before_after.png')
l2.sheet([[('BEFORE ji stem',l2.zoom_img(before[85:155,269:327],6)),
           ('AFTER ji stem',l2.zoom_img(after[85:155,269:327],6))]],OUT/'stem_before_after.png')
l2.sheet([[('BEFORE underside',l2.zoom_img(before[115:162,10:328],4))],
          [('AFTER underside',l2.zoom_img(after[115:162,10:328],4))]],OUT/'underside_before_after.png')
print('Copied review outputs and prepared detail comparison')
