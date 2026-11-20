from pathlib import Path
import sys
import numpy as np
from PIL import Image
ROOT=Path(__file__).resolve().parents[3];OUT=Path(__file__).parent
sys.path.insert(0,str(ROOT/'work/img/logo2'))
import l2
im=Image.open(OUT/'intro_assembly_before_after.png').convert('RGB')
assert im.size==(848,1152)
preview=Image.new('RGB',(848,768),(32,32,32))
preview.paste(im.crop((0,0,848,384)),(0,0))
preview.paste(im.crop((0,768,848,1152)),(0,384))
preview.save(OUT/'intro_fix_preview.png')
before=l2.comp_on(l2.load(OUT/'title_logo_JP_bottom_before.png'))
after=l2.comp_on(l2.load(OUT/'title_logo_JP_bottom.png'))
l2.sheet([
    [('RU BEFORE',l2.zoom_img(before[120:162,189:239],6)),('RU AFTER',l2.zoom_img(after[120:162,189:239],6))],
    [('JI BEFORE',l2.zoom_img(before[125:163,266:329],6)),('JI AFTER',l2.zoom_img(after[125:163,266:329],6))],
],OUT/'title_details_before_after.png')
print('Saved intro_fix_preview.png and title_details_before_after.png')
