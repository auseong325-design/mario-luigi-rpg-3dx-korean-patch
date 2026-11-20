from pathlib import Path
import json
import numpy as np
from PIL import Image
OUT=Path(__file__).parent
old=np.array(Image.open(OUT/'title_logo_JP_bottom_before.png'))
new=np.array(Image.open(OUT/'title_logo_JP_bottom.png'))
removed=(old[...,3]>64)&(new[...,3]<=64)
ys,xs=np.nonzero(removed)
print('All removed alpha64 pixels:',len(ys),'box',xs.min(),ys.min(),xs.max()+1,ys.max()+1)
for y in range(120,200,10):
    print(y, int(removed[y:y+10,330:].sum()))
print(json.loads((OUT/'animation_verify.json').read_text()))
