"""Restore main-title diagnostic caches and confirm the accepted PNGs are unchanged."""
from pathlib import Path
import subprocess,sys,hashlib
ROOT=Path(__file__).resolve().parents[3]
recipe=ROOT/'work/img/title_layout_20261008/build_title.py'
paths=[recipe.parent/(n+'.png') for n in ['title_logo_JP_bottom','title_logo_JP_top']]
before={p:p.read_bytes() for p in paths}
subprocess.run([sys.executable,str(recipe)],cwd=ROOT,check=True,timeout=60,capture_output=True)
for p in paths:assert p.read_bytes()==before[p],'Accepted title changed: '+str(p)
recipe=Path(__file__).parent/'build_fileload.py'
before={p:p.read_bytes() for p in recipe.parent.glob('LOAD_GAME_IMG_ML_*.png')}
subprocess.run([sys.executable,str(recipe)],cwd=ROOT,check=True,timeout=60,capture_output=True)
for p in before:assert p.read_bytes()==before[p],'File-load output changed'
print('PASS: main-title diagnostic caches restored; accepted main-title and file-load PNGs identical')
