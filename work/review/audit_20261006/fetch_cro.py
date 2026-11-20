from pathlib import Path
import urllib.request
P=Path(__file__).parent
for name in ['cro_helper.h','cro_helper.cpp']:
 url='https://raw.githubusercontent.com/azahar-emu/azahar/master/src/core/hle/service/ldr_ro/'+name
 b=urllib.request.urlopen(url,timeout=20).read();(P/('upstream_'+name)).write_bytes(b);print(name,len(b))
