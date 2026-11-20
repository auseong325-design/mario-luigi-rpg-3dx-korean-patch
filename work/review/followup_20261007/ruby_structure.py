import hashlib
import json
import re
import struct
import sys
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3]; OUT=Path(__file__).resolve().parent
sys.path[:0]=[str(ROOT/'scripts'),str(OUT/'deps')]
import lib3dx,lytimg

data=lib3dx.romfs_path('RO/MainMenu.cro').read_bytes()
f=struct.unpack_from('<46I',data,0x80)
segs=[struct.unpack_from('<3I',data,f[18]+n*12) for n in range(f[19])]
import_sites={}
for n in range(f[33]):
    off,batch=struct.unpack_from('<II',data,f[32]+n*8)
    text=data[off:data.index(b'\0',off)].decode('ascii')
    index=0
    while True:
        tag,typ,last,resolved,addend=struct.unpack_from('<IBBBxI',data,batch+index*12)
        site=segs[tag&15][0]+(tag>>4)
        import_sites[site]=text
        if last:break
        index+=1
print('IMPORTS',[(hex(site),text) for site,text in import_sites.items() if site==0xb54 or any(w in text for w in ('Ruby','Language','Lang','Animation','Frame','Visible','Hit'))])
(OUT/'MainMenu_import_sites.json').write_text(json.dumps(import_sites,indent=2),encoding='utf-8')

crr=lib3dx.romfs_path('.crr/static.crr').read_bytes()
hashoff,count=struct.unpack_from('<II',crr,0x350)
hashes=[crr[hashoff+n*32:hashoff+(n+1)*32] for n in range(count)]
print('CRR fields',crr[:32].hex(),hex(hashoff),count,'sorted',hashes==sorted(hashes))
debugoff,debugsize=struct.unpack_from('<II',crr,0x10)
print('CRR DEBUG',hex(debugoff),hex(debugsize),crr[debugoff:debugoff+32].hex())
for name in ('MainMenu','Battle','LoadMenu'):
    blob=lib3dx.romfs_path('RO/'+name+'.cro').read_bytes()
    fields=struct.unpack_from('<46I',blob,0x80)
    ranges=[(0x80,fields[12]),(fields[12],fields[16]),(fields[16],fields[14]),(fields[14],fields[14]+fields[15])]
    checks=[hashlib.sha256(blob[a:b]).digest()==blob[n*32:(n+1)*32] for n,(a,b) in enumerate(ranges)]
    digest=hashlib.sha256(blob[:0x80]).digest()
    print('CRO HASH',name,checks,digest.hex(),'CRRindex',hashes.index(digest) if digest in hashes else None)

# BFLAN runtime's existing visibility/placement animation for hasRuby=false.
path=OUT/'MENU_SET_JP_ja_MENU_SET_L_SET_PNL_hurigana.bflan'
blob=path.read_bytes()
print('ANIM hex')
for p in range(0,len(blob),16):
    if p<0xb0 or p>=0x430:
        print(f'{p:04x}',blob[p:p+16].hex(' '))
for dat,entry,sarc in lytimg.iter_sarcs('1DX'):
    if 'SET' in entry:
        names=[n for n,_,_ in lytimg.sarc_list(sarc) if n.endswith('.bflyt')]
        print('1DX SET',dat,entry,names)
        if any('MENU_SET' in n for n in names):
            for name,a,b in lytimg.sarc_list(sarc):
                if name.endswith(('.bflyt','.bflan')):
                    (OUT/('1DX_'+entry+'_'+Path(name).name)).write_bytes(sarc[a:b])

# Whole installed text: ruby is encoded as group 0, type 0, with base/ruby lengths.
patch=ROOT/'patch/00040000001CA900/romfs'
messages=[]
for rel in lib3dx.MSG_MSBT_FILES:
    blob=(patch/rel).read_bytes()
    messages.extend((rel,m.index,m.text) for m in lib3dx.read_msbt(blob).messages)
for rel in lib3dx.MSG_BG4_FILES:
    _, entries=lib3dx.read_bg4((patch/rel).read_bytes())
    for entry in entries:
        if not entry.size_flag and entry.data:
            messages.extend((rel+'/'+entry.name,m.index,m.text) for m in lib3dx.read_msbt(lib3dx.bg4_plain(entry)).messages)
ruby=[(rel,index,text) for rel,index,text in messages if '[Ruby ' in text or '[0000:0000:' in text]
print('INSTALLED RUBY',len(messages),'messages;',len(ruby),'ruby tags')
(OUT/'ruby_structure.json').write_text(json.dumps(dict(language_import=import_sites.get(0xb54),crr_hash_offset=hashoff,crr_hash_count=count,crr_sorted=hashes==sorted(hashes),installed_messages=len(messages),installed_ruby=ruby),ensure_ascii=False,indent=2),encoding='utf-8')
