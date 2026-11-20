"""Inverse-project all glyph masks to the original 1DX pixel grid to check shape fidelity."""
from pathlib import Path
import json,sys
import numpy as np
from scipy import ndimage as ndi
ROOT=Path(__file__).resolve().parents[3];OUT=Path(__file__).parent
sys.path.insert(0,str(ROOT/'work/img/logo2'))
import l2,seg_1dx
donor=seg_1dx.syllables(fix_stem=False)[0]
metrics=json.loads((OUT/'layout_metrics.json').read_text(encoding='utf8'))
map_info=metrics['donor_layout']
masks=np.load(OUT/'title_masks.npz')
scale=map_info['scale_x'];left=map_info['left'];base=map_info['baseline']+metrics['config']['title_down']
assert scale==map_info['scale_y'] and map_info['stroke_growth']==0 and not map_info['stem_redesign']
assert map_info['preserve_donor_letter_positions']
scores={}
for name,cov in donor.items():
    Y,X=np.mgrid[:cov.shape[0],:cov.shape[1]]
    px=(left+(X+.5-map_info['donor_left'])*scale)*4-.5
    py=(base+(Y+.5-map_info['source_baseline'])*scale)*4-.5
    back=ndi.map_coordinates(masks[name].astype(float),[py,px],order=1,mode='constant')>.5
    source=cov>.5
    scores[name]=float(np.logical_and(back,source).sum()/np.logical_or(back,source).sum())
assert min(scores.values())>.97,scores
intro=json.loads((OUT/'intro_amp_metrics.json').read_text(encoding='utf8'))
F=np.load(OUT/'intro_amp_mask.npz')['amp']
cov=donor['amp'];Y,X=np.mgrid[:cov.shape[0],:cov.shape[1]]
px=(intro['face_left']+(X+.5-intro['donor_box'][0])*intro['uniform_scale'])*4-.5
py=(intro['face_top']+(Y+.5-intro['donor_box'][1])*intro['uniform_scale'])*4-.5
back=ndi.map_coordinates(F.astype(float),[py,px],order=1,mode='constant')>.5
intro_iou=float((back&(cov>.5)).sum()/(back|(cov>.5)).sum())
assert intro_iou>.96,intro_iou
result={'title_donor_mask_iou':scores,'intro_amp_donor_mask_iou':intro_iou,
        'single_uniform_affine_for_entire_title_word':True,'no_glyph_growth_or_stem_redesign':True,
        'shared_1dx_amp_shape_in_title_and_intro':True}
(OUT/'shape_verify.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf8')
print(json.dumps(result,indent=2))
