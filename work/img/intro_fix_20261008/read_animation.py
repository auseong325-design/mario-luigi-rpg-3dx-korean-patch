from pathlib import Path
import json
d=json.loads((Path(__file__).resolve().parent/'model_geometry.json').read_text(encoding='utf-8-sig'))
for anim in d['skeletal_animations']:
    print('ANIM',anim['name'],anim['frames'])
    for el in anim['elements']:
        print('BONE',el['Name'],'target',el.get('TargetType'),'primitive',el.get('PrimitiveType'))
        content=el['Content']
        for key,v in content.items():
            if isinstance(v,dict):
                frames=v.get('KeyFrames',[])
                print(' ',key,'constant',v.get('Value'), 'exists',v.get('Exists'),'keys',len(frames),'first',frames[:1],'last',frames[-1:])
            else: print(' ',key,v)
