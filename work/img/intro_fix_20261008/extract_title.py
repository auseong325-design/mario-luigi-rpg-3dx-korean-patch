from pathlib import Path
import sys,json,struct
ROOT=Path(__file__).resolve().parents[3]
OUT=Path(__file__).resolve().parent
sys.path.insert(0,str(ROOT/'scripts'))
import build_fmdl as BF
import libbch
for kind,path in [('original',BF.GAMES['3DX']()),('before',ROOT/'patch/00040000001CA900/romfs/FMdl/JP/FMdl.dat')]:
    raw,models=BF.load(path)
    slot,plain,bch=models['fmd_title_JP_ja']
    (OUT/f'{kind}_title.bch').write_bytes(plain)
    print(kind,'BCH',len(plain),'slot',slot,'main',hex(bch.main),'data',hex(bch.dat))
    for n in range(15):
        ptr,count,tree=struct.unpack_from('<III',plain,bch.main+n*12)
        if count:
            print('dict',n,hex(ptr),count,hex(tree))
    strings=plain[bch.strings:bch.strings+bch.str_len].split(b'\0')
    print('strings:',[s.decode('ascii','replace') for s in strings if s])
    for tex in bch.textures:
        print('texture',tex)
