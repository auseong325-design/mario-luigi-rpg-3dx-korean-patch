"""Locate user detail crops against the previous native proof, without editing artwork."""
from pathlib import Path
import json
import numpy as np
from PIL import Image
from scipy.signal import correlate2d

HERE=Path(__file__).resolve().parent
ROOT=HERE.parents[2]
NAMES=['d30a54bc-0364-4df5-9126-a74631d03d23','81c1edf3-5564-4361-90e0-2e862fdb0c39','b864b1bd-cad0-4f57-9a43-d38003fc092d']


def main():
    proof=np.asarray(Image.open(ROOT/'work/img/kj_R_polish_20261010/R_before_after.png').convert('RGB')).astype(float)
    # Search the middle corrected R and the blue-background corrected R only.
    result=[]
    for name in NAMES:
        p=Path('C:/Users/woose/AppData/Local/Temp')/('codex-clipboard-'+name+'.png')
        a=np.asarray(Image.open(p).convert('RGB')).astype(float)
        best=None
        for origin in [300,600]:
            b=proof[:,origin:origin+300]
            h,w=a.shape[:2]
            cross=sum(correlate2d(b[...,i],a[...,i],mode='valid') for i in range(3))
            bs=sum(correlate2d(b[...,i]**2,np.ones((h,w)),mode='valid') for i in range(3))
            mse=(bs+np.sum(a*a)-2*cross)/(h*w*3)
            y,x=np.unravel_index(np.argmin(mse),mse.shape)
            record=dict(file=name,size=[w,h],proof_crop=[origin+int(x),int(y),origin+int(x+w),int(y+h)],
                        original_R_region=[201+(int(x)-30)/4,140+(int(y)-24)/4,201+(int(x+w)-30)/4,140+(int(y+h)-24)/4],
                        RGB_rmse=float(np.sqrt(max(mse[y,x],0))))
            if best is None or record['RGB_rmse']<best['RGB_rmse']:best=record
        result.append(best)
    (HERE/'located_details.json').write_text(json.dumps(result,indent=2),encoding='utf8')
    print(json.dumps(result,indent=2))


if __name__=='__main__':main()
