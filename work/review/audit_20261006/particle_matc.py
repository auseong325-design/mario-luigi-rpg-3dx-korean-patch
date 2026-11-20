from pathlib import Path
import struct,re,sys,collections,json
ROOT=Path(__file__).resolve().parents[3]; sys.path.insert(0,str(ROOT/'scripts'))
from libbch import pica_commands
d=(Path(__file__).parent/'particle.ptcl').read_bytes()
offs=[m.start() for m in re.finditer(b'MATC',d)]
groups=collections.defaultdict(set)
for i,p in enumerate(offs):
 end=offs[i+1] if i+1<len(offs) else len(d)
 regs=pica_commands(d,p+12,(end-p-12)//4)
 if i<2: print('MATC',hex(p),'size',end-p,'header',struct.unpack_from('<3I',d,p),'REGS', {hex(k):list(map(hex,v)) for k,v in regs.items()})
 if 0x82 in regs and 0x85 in regs and 0x8e in regs:
  groups[regs[0x85][-1]].add((regs[0x82][-1]>>16,regs[0x82][-1]&65535,regs[0x8e][-1]&15))
print('groups',len(groups))
for k,v in sorted(groups.items()): print(k,list(v))
(Path(__file__).parent/'particle_matc_groups.json').write_text(json.dumps({k:list(v) for k,v in groups.items()},indent=2),encoding='utf-8')
