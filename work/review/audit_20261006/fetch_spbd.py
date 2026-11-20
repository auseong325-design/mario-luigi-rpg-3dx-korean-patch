from pathlib import Path
import json,urllib.request
p=Path(__file__).parent
url='https://api.github.com/repos/KillzXGaming/Switch-Toolbox/git/trees/master?recursive=1'
r=json.loads(urllib.request.urlopen(url,timeout=20).read())
paths=[x['path'] for x in r.get('tree',[]) if 'spb' in x['path'].lower() or 'ptcl' in x['path'].lower()]
print(paths)
for path in paths:
 if path.endswith('.cs'):
  b=urllib.request.urlopen('https://raw.githubusercontent.com/KillzXGaming/Switch-Toolbox/master/'+path,timeout=20).read()
  dest=p/('upstream_'+path.replace('/','_'))
  dest.write_bytes(b);print(dest)
