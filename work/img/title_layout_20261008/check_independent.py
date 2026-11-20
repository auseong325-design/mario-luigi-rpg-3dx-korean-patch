from pathlib import Path
import json
OUT=Path(__file__).parent
a=json.loads((OUT/'before_geometry.json').read_text(encoding='utf-8-sig'))
b=json.loads((OUT/'after_geometry.json').read_text(encoding='utf-8-sig'))
assert a==b,'SPICA geometry or animation changed'
layout=json.loads((OUT/'layout_metrics.json').read_text(encoding='utf8'))
assert layout['center_difference_texture_px']<=1
result={'spica_geometry_and_animation_equal':True,'main_and_dx_center_difference_texture_px':layout['center_difference_texture_px']}
(OUT/'independent_verify.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf8')
print(json.dumps(result,indent=2))
