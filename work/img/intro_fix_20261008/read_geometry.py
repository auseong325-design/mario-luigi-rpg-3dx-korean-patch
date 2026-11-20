from pathlib import Path
import json
OUT=Path(__file__).resolve().parent
d=json.loads((OUT/'model_geometry.json').read_text(encoding='utf-8-sig'))
for model in d['models']:
    print('\nMODEL',model['name'],'WORLD',model['world'])
    for bone in model['bones']:print('bone',bone['name'],'inverse',bone['inverse'])
    for mesh in model['meshes']:
        print('mesh',mesh['texture0'],'stride',mesh['stride'],'attributes',mesh['attributes'],'offset',mesh['position_offset'])
        print('texcoords',mesh['texcoords'])
        for v in mesh['vertices']:print(' vertex',v)
print('animations',d['skeletal_animations'],d['visibility_animations'])
