from pathlib import Path
import sys
import numpy as np
ROOT=Path(__file__).resolve().parents[3];OUT=Path(__file__).parent
sys.path.insert(0,str(ROOT/'work/img/logo2'))
import l2
SOURCE=ROOT/'work/img/title_layout_20261008'
for name in ['title_logo_JP_bottom.png','title_logo_JP_top.png','title_masks.npz','layout_metrics.json']:
    target=OUT/name;temp=target.with_suffix('.review.tmp')
    temp.write_bytes((SOURCE/name).read_bytes());temp.replace(target)
before=l2.comp_on(l2.load(OUT/'title_logo_JP_bottom_before.png'))
after=l2.comp_on(l2.load(OUT/'title_logo_JP_bottom.png'))
normal=l2.comp_on(l2.load(ROOT/'work/img/title_lower_shading_20261008/title_logo_JP_bottom_before.png'))
l2.sheet([
    [('RU expected prior contour',l2.zoom_img(normal[120:162,189:239],6)),('RU BEFORE',l2.zoom_img(before[120:162,189:239],6)),('RU AFTER',l2.zoom_img(after[120:162,189:239],6))],
    [('JI expected prior contour',l2.zoom_img(normal[125:163,266:329],6)),('JI BEFORE',l2.zoom_img(before[125:163,266:329],6)),('JI AFTER',l2.zoom_img(after[125:163,266:329],6))],
],OUT/'contours_before_after.png')
print('Prepared title and local contour previews')
