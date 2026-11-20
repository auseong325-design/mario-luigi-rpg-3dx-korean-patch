import hashlib
import json
import re
import struct
import sys
from pathlib import Path
ROOT = Path(__file__).resolve().parents[3]
OUT = Path(__file__).resolve().parent
sys.path[:0] = [str(ROOT / 'scripts'), str(OUT / 'deps')]
import capstone
import lib3dx
import lytimg

def word(data, offset):
    return struct.unpack_from('<I', data, offset)[0]

for name in ('MainMenu', 'LoadMenu', 'KJMenu', 'SaveMenu'):
    path = lib3dx.romfs_path('RO/' + name + '.cro')
    data = path.read_bytes()
    fields = struct.unpack_from('<46I', data, 0x80)
    segments = [struct.unpack_from('<3I', data, fields[18] + n*12) for n in range(fields[19])]
    strings = {m.start(): m.group().decode('ascii') for m in re.finditer(rb'[A-Za-z_][A-Za-z0-9_/. :+-]{3,}', data)}
    wanted = {off:s for off,s in strings.items() if any(t in s.lower() for t in ('ruby', 'setting', 'menu_set', 'set_tab', 'furigana'))}
    refs = []
    for pos in range(fields[12], fields[12] + fields[13], 4):
        ins = word(data, pos)
        if (ins & 0x0e0f0000) == 0x020f0000 and ((ins >> 21) & 15) in (2,4):
            value=ins&255; rot=((ins>>8)&15)*2
            value=((value>>rot)|(value<<(32-rot)))&0xffffffff if rot else value
            target=pos+8+value*(1 if ((ins>>21)&15)==4 else -1)
            if target in wanted:
                refs.append(dict(site=pos, target=target, text=wanted[target], type='ADR'))
        if (ins & 0x0f7f0000) != 0x051f0000:
            continue
        rd=(ins>>12)&15; literal=pos+8+(ins&4095)*(1 if ins&0x00800000 else -1)
        if not 0<=literal<len(data)-4:
            continue
        value=word(data,literal)
        if value>=0x80000000:
            value-=0x100000000
        for q in range(pos+4,min(pos+40,fields[12]+fields[13]),4):
            add=word(data,q)
            if (add&0x0fe000f0)==0x00800000 and ((add>>16)&15)==15 and (add&15)==rd:
                target=q+8+value
                if target in wanted:
                    refs.append(dict(site=pos, add=q, literal=literal,target=target,text=wanted[target],type='PCREL'))
                break
    for n in range(fields[43]):
        tag,typ,sym,addend=struct.unpack_from('<IBB2xI', data, fields[42]+n*12)
        target=segments[sym][0]+addend
        if target in wanted:
            site=segments[tag&15][0]+(tag>>4)
            refs.append(dict(site=site,target=target,text=wanted[target],type='REL'+str(typ)))
    md=capstone.Cs(capstone.CS_ARCH_ARM, capstone.CS_MODE_ARM | capstone.CS_MODE_LITTLE_ENDIAN)
    md.skipdata=True
    assembly=[]
    for ins in md.disasm(data[fields[12]:fields[12]+fields[13]], fields[12]):
        assembly.append(f'{ins.address:08x} {ins.bytes.hex()} {ins.mnemonic:8s} {ins.op_str}')
    (OUT/(name+'_arm.txt')).write_text('\n'.join(assembly),encoding='utf-8')
    (OUT/(name+'_strings.txt')).write_text('\n'.join(f'{off:08x} {s}' for off,s in strings.items()),encoding='utf-8')
    (OUT/(name+'_ruby_refs.json')).write_text(json.dumps(dict(path=str(path),sha256=hashlib.sha256(data).hexdigest(), fields=fields,segments=segments,strings=wanted,refs=refs),indent=2),encoding='utf-8')
    print(name, 'fields', [hex(x) for x in fields[:20]], 'segments', segments)
    print('STRINGS', wanted)
    print('REFS', refs)

for dat, entry, sarc in lytimg.iter_sarcs('3DX'):
    if any(s in entry for s in ('MENU_SET', 'SETTING')):
        print('LAYOUT',dat,entry,len(sarc))
        for name,start,end in lytimg.sarc_list(sarc):
            if name.endswith(('.bflyt','.bflan')):
                path=OUT/(entry+'_'+Path(name).name)
                path.write_bytes(sarc[start:end])
                parts=[]
                blob=sarc[start:end]
                for m in re.finditer(rb'[A-Za-z_][A-Za-z0-9_/]{2,}',blob):
                    parts.append(f'{m.start():08x} {m.group().decode("ascii")}')
                path.with_suffix(path.suffix+'.strings.txt').write_text('\n'.join(parts),encoding='utf-8')
                print(name,len(blob),'strings',parts)
