from pathlib import Path
from PIL import Image
import numpy as np,json
p=Path('C:/Users/woose/AppData/Local/Temp/codex-clipboard-14c3a77c-0986-4db7-8980-151b55eef1a4.png')
a=Image.open(p)
print('reference',a.mode,a.size,a.getextrema())
g=json.loads((Path(__file__).parent/'cutout_geometry.json').read_text())
print('ref face points',g['reference_face_points'])
