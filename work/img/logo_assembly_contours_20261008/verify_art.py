from pathlib import Path
import json,sys
import numpy as np
from PIL import Image
ROOT=Path(__file__).resolve().parents[3];OUT=Path(__file__).parent
sys.path.insert(0,str(ROOT/'work/img/logo2'))
import l2,model as M
before=np.load(OUT/'before_title_masks.npz');after=np.load(OUT/'title_masks.npz')
assert set(before.files)==set(after.files)
for key in before.files:assert np.array_equal(before[key],after[key]),'Changed main-title mask: '+key
old=l2.load(OUT/'title_logo_JP_bottom_before.png');new=l2.load(OUT/'title_logo_JP_bottom.png')
face_pixels=0
for key in ['ma','ri','o','amp','ru','i','ji','F4','F5','F6']:
    core=l2.down(before[key].astype(float))>.999
    assert np.array_equal(old[core],new[core]),'Changed accepted face pixels: '+key
    face_pixels+=int(core.sum())
assert np.array_equal(l2.load(OUT/'title_logo_JP_top_before.png'),l2.load(OUT/'title_logo_JP_top.png'))
underside=np.load(ROOT/'work/img/title_lower_shading_20261008/underside.npz')
faces={g:l2.shift_hr(after[f'F{g}'],0,-40) for g in range(1,7)}
sil=l2.shift_hr(after['sil'],0,-40)
approved=M.geometry(faces,M.Params(),sil)
repair=underside['contour_repair']
assert repair.any()
assert np.array_equal(underside['approved_outline'],approved['O'])
assert np.array_equal(underside['approved_extrusion'],approved['E'])
assert np.array_equal(underside['body'][repair],approved['B'][repair])
other=underside['lower']&~repair&~sil
assert np.array_equal(underside['body'][other],underside['donor_body'][other])
rgb=underside['rgb'][underside['shade_mask']]
assert np.isfinite(rgb).all() and rgb.min()>=-1e-4 and rgb.max()<=255
# The old raw Japanese strip is replaced by clean body/glow, preserving accepted RPG faces.
rpg_surrounding_changes=np.any(old[75:165,333:450]!=new[75:165,333:450],axis=2)
assert rpg_surrounding_changes.any()
layout_meta=json.loads((OUT/'layout_metrics.json').read_text())
assert layout_meta['rpg_composition']=='accepted RPG face pixels on regenerated body; no Japanese DX strip'
intro=json.loads((OUT/'intro_layout.json').read_text())
for key in ['title_logo_M_JP','title_logo_L_JP','title_logo_and_JP']:
    assert intro[key]['scale_x']==intro[key]['scale_y']==.6
    assert intro[key]['world_donor_baseline']==111.375
    with Image.open(OUT/(key+'.png')) as im:img=np.array(im.convert('RGBA'))
    edge=np.concatenate([img[0,:,3],img[-1,:,3],img[:,0,3],img[:,-1,3]])
    assert edge.max()<=34
anim=json.loads((OUT/'animation_verify.json').read_text())
assert anim['assembled_frames_checked']==160 and anim['full_animation_frames_checked']==371
assert anim['assembly_face_overlap_mario_amp']==0 and anim['assembly_face_overlap_luigi_amp']==0
assert anim['max_assembly_baseline_difference_world']<.15
assert anim['attached_and_assembled_relative_positions_match']
preview=json.loads((OUT/'preview_metrics.json').read_text())
assert preview['all_silhouettes_inside_screen']
result={'all_main_title_face_masks_and_silhouettes_equal':True,
        'accepted_face_color_and_gloss_pixels_equal':face_pixels,
        'dx_deluxe_number_texture_equal':True,'approved_ru_ji_lower_contours_restored':True,
        'other_1dx_underside_contours_preserved':True,'rpg_surrounding_pixels_rebuilt':int(rpg_surrounding_changes.sum()),
        'raw_japanese_right_strip_composition_removed':True,
        'intro_common_scale_and_baseline':True,'intro_no_hard_edge_clipping':True,
        'animation_checks':anim,'runtime_verified':False}
(OUT/'art_verify.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf8')
print(json.dumps(result,indent=2))
