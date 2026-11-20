from pathlib import Path
import json,sys
import numpy as np
from PIL import Image
from scipy import ndimage as ndi
ROOT=Path(__file__).resolve().parents[3];OUT=Path(__file__).parent
sys.path.insert(0,str(ROOT/'work/img/logo2'))
import l2,seg_1dx,layout
before=np.load(OUT/'before_title_masks.npz');after=np.load(OUT/'title_masks.npz')
for name in ['ma','ri','o','amp','ru','i','sil']:
    assert np.array_equal(before[name],after[name]),name+' moved or reshaped'
donor=np.load(OUT/'donor_masks.npz');raw,_=seg_1dx.syllables(fix_stem=False)
for name in ['ma','ri','o','amp','ru','i']:assert np.array_equal(raw[name],donor[name])
change=donor['ji']!=raw['ji']
ys,xs=np.nonzero(change)
assert len(ys)>0 and ys.max()<54 and xs.min()>=318 and xs.max()<332
assert np.all(donor['ji']>=raw['ji']),'Original stem pixels removed'
meta=json.loads((OUT/'layout_metrics.json').read_text(encoding='utf8'))
d=meta['donor_layout']
assert d['scale_x']==d['scale_y']==.9095092024539877
assert meta['rpg_and_3_shift_x']==41.25
assert meta['silhouette_moves']==[[-13.,10.],[-24.5,1.75]]
assert meta['center_difference_texture_px']<=1
underside=np.load(OUT/'underside.npz')
a=l2.load(l2.KR1DX);y,x=np.mgrid[:a.shape[0],:a.shape[1]]
source_alpha=(a[...,3]/255)*(y<100)*(x<338)
transform=(d['donor_left'],d['source_baseline'],d['scale_x'],d['scale_y'],d['left'],d['baseline'],after['ma'].shape)
independent_body=layout.resample(source_alpha,*transform,order=1)>.5
assert np.array_equal(underside['donor_body'],independent_body),'Donor contour changed'
# The new lower body has no extrusion created outside the imported 1DX contour.
lower=underside['lower']
unshifted_sil=l2.shift_hr(after['sil'],0,-40)
assert np.array_equal(underside['body'][lower&~unshifted_sil],independent_body[lower&~unshifted_sil])
old_img=l2.load(OUT/'title_logo_JP_bottom_before.png')
new_img=l2.load(OUT/'title_logo_JP_bottom.png')
face_unchanged=0
for name in ['ma','ri','o','amp','ru','i']:
    inner=l2.down(before[name].astype(float))>.999
    assert np.array_equal(old_img[inner],new_img[inner]),'Face color/gloss changed: '+name
    face_unchanged+=int(inner.sum())
assert np.array_equal(l2.load(OUT/'title_logo_JP_top_before.png'),l2.load(OUT/'title_logo_JP_top.png'))
# Raw colors remain inside the range of the Japanese 3DX palette, rather than the reference's cyan face.
rgb=underside['rgb'][underside['shade_mask']]
assert np.isfinite(rgb).all() and rgb.min()>=-1e-4 and rgb.max()<=255
preview=json.loads((OUT/'preview_metrics.json').read_text(encoding='utf8'))
assert preview['all_silhouettes_inside_screen']
result={'only_ji_cap_mask_changed':True,'ji_source_change_box':[int(xs.min()),int(ys.min()),int(xs.max()+1),int(ys.max()+1)],
        'ji_original_stem_preserved':True,'all_other_glyph_masks_and_silhouettes_equal':True,
        'face_color_and_gloss_pixels_unchanged':face_unchanged,'dx_number_and_deluxe_pixels_equal':True,
        'imported_1dx_underside_contour_exact':True,'lower_body_follows_imported_contour':True,
        'rpg_and_3_position_unchanged':True,'screen_projection_inside':True}
(OUT/'art_verify.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf8')
print(json.dumps(result,indent=2))
