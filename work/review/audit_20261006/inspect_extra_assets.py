from pathlib import Path
import sys,json,re,struct
root=Path(__file__).resolve().parents[3]
sys.path.insert(0,str(root/'scripts'))
import lib3dx as L
import libhb as H
d=json.loads((root/'work/scan_text_outside_msbt.json').read_text(encoding='utf8'))
for rel,row in d.items():
    if rel.endswith('.csv') or rel.startswith('RO/'):
        print(rel,row['strings'],row['by_entry'])
for p in (root/'romfs/HB').rglob('*.ptcl.z'):
    rel=p.relative_to(root/'romfs').as_posix()
    data=L.romfs_path(rel).read_bytes()
    raw=H.unpack(data)
    out=root/'work/review/audit_20261006'/p.stem
    out.write_bytes(raw)
    print('PARTICLE',rel,'compressed',len(data),'plain',len(raw),'header',raw[:80].hex(' '))
    print('MAGICS',[(m,raw.find(m.encode())) for m in ['SPBD','CGFX','CTPK','FLIM','BCH','SARC','TEXR']])
    print('STRINGS',re.findall(rb'[A-Za-z0-9_/ .-]{5,}',raw)[:25])
print('FILES',len(list((root/'romfs').rglob('*'))))
