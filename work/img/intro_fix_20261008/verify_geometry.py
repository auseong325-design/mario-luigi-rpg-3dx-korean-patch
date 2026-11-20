from pathlib import Path
import copy,json
import numpy as np
ROOT=Path(__file__).resolve().parents[3];OUT=Path(__file__).parent
old=json.loads((OUT/'model_geometry.json').read_text(encoding='utf-8-sig'))
new=json.loads((OUT/'after_geometry.json').read_text(encoding='utf-8-sig'))
plan=json.loads((ROOT/'work/img/fmdl_geometry_patches.json').read_text(encoding='utf8'))
normalized=copy.deepcopy(new);diffs=[]
for om,nm,cm in zip(old['models'],new['models'],normalized['models']):
    for mesh_index,(oa,na,ca) in enumerate(zip(om['meshes'],nm['meshes'],cm['meshes'])):
        if oa['position_offset']==na['position_offset']:continue
        assert om['name'] in ['logo_L','logo_pch']
        assert oa['texture0']=='title_logo_and_JP'
        delta=np.array(na['position_offset'])-oa['position_offset']
        np.testing.assert_allclose(delta,[plan['derivation']['local_dx'],0,plan['derivation']['local_dz'],0],atol=2e-6)
        for ov,nv,cv in zip(oa['vertices'],na['vertices'],ca['vertices']):
            np.testing.assert_allclose(np.array(nv['position'])-ov['position'],delta,atol=5e-6)
            cv['position']=ov['position']
        ca['position_offset']=oa['position_offset']
        diffs.append({'model':om['name'],'mesh':mesh_index,'texture':oa['texture0'],'local_delta':delta.tolist()})
assert normalized==old,'Unexpected SPICA model or animation differences'
assert len(diffs)==2
result={'independent_spica_readback':True,'changed_meshes':diffs,'all_other_geometry_and_animation_equal':True}
(OUT/'geometry_verify.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf8')
print(json.dumps(result,indent=2))
