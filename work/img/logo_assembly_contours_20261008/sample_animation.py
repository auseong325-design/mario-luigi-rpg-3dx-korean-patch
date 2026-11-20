from pathlib import Path
import subprocess,json
ROOT=Path(__file__).resolve().parents[3];OUT=Path(__file__).parent
subprocess.run(['powershell','-NoProfile','-File',str(OUT/'sample_animation.ps1'),
                '-InputBch',str(OUT/'before_title.bch'),'-OutputJson',str(OUT/'animation_frames.json')],
               capture_output=True,check=True,cwd=ROOT,timeout=45)
data=json.loads((OUT/'animation_frames.json').read_text(encoding='utf-8-sig'))
print('SPICA sampled',len(data),'frames; assembled period 0..159')
for i in [0,100,159,160,209]:print(data[i])
