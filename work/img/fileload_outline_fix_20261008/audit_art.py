from pathlib import Path
import sys,json
import numpy as np
from PIL import Image,ImageDraw,ImageFont
from scipy import ndimage as ndi
ROOT=Path(__file__).resolve().parents[3];OUT=Path(__file__).parent
sys.path.insert(0,str(ROOT/'scripts'))
import build_lyt
before=np.asarray(Image.open(OUT/'before_fileload.png').convert('RGBA'))
after=np.asarray(Image.open(ROOT/'work/img/fileload_logo_20261008/fileload.png').convert('RGBA'))
q=build_lyt.expected('RGB565',after)
changed=np.any(before!=q,axis=2)
ys,xs=np.nonzero(changed)
bounds=[int(xs.min()),int(ys.min()),int(xs.max()+1),int(ys.max()+1)]
assert np.array_equal(before[:,:144],q[:,:144])
assert np.array_equal(before[:,:288],q[:,:288]),bounds
assert np.array_equal(before[:,310:],q[:,310:]),bounds
assert np.array_equal(before[91:],q[91:]),bounds
white=q[...,:3].min(2)>180
labs,n=ndi.label(white)
holes=[]
for i,sl in enumerate(ndi.find_objects(labs)):
    if sl and 295<=sl[1].start<305 and 30<=sl[0].start<85:
        holes.append([sl[1].start,sl[0].start,int((labs==i+1).sum())])
assert not holes,holes
font=ImageFont.truetype('C:/Windows/Fonts/malgun.ttf',18)
comparison=Image.new('RGB',(760,356),(25,25,25));draw=ImageDraw.Draw(comparison)
for i,(a,label) in enumerate([(before,'수정 전 · 패치 텍스처'),(q,'수정 후 · 패치 텍스처')]):
    crop=Image.fromarray(a).crop((265,3,360,85)).resize((380,328),Image.Resampling.NEAREST)
    comparison.paste(crop,(380*i,28));draw.text((12+380*i,2),label,font=font,fill='white')
comparison.save(OUT/'outline_before_after.png')
result={'change_bounds':bounds,'changed_RGB565_pixels':int(changed.sum()),
        'left_texture_and_hangul_amp_art_unchanged':True,
        'characters_and_right_number_face_art_unchanged':True,
        'no_isolated_white_specks_at_join':True}
(OUT/'art_verify.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf8')
print(json.dumps(result,indent=2))
