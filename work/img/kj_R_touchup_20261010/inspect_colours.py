from pathlib import Path
import numpy as np
from PIL import Image
root=Path(__file__).resolve().parent.parents[2]
paths=['work/img/kj_R_polish_20261010/R_clean.png','work/img/kj_R_touchup_20261010/R_clean.png']
for path in paths:
    a=np.asarray(Image.open(root/path).convert('RGBA'))
    print(path)
    for y in range(187,195):
        print(y,a[y-140,214-201:223-201,:3].tolist())
    b=a[187-140:194-140,215-201:222-201,:3].astype(float)
    print('row mean',b.mean(1).round(2).tolist())
    print('row steps',np.linalg.norm(np.diff(b.mean(1),axis=0),axis=1).round(2).tolist())
