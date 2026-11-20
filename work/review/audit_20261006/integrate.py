"""Snapshot, compare, and install only independently validated message assets."""
from pathlib import Path
import json, sys, shutil, subprocess, hashlib, zipfile, csv, io
ROOT=Path(__file__).resolve().parents[3]
OUT=Path(__file__).resolve().parent
PATCH=ROOT/'patch/00040000001CA900/romfs'
STAGE=ROOT/'work/build/msg_stage/romfs'
REL=Path('Msg/JP_ja')
NAMES=['FMsg.dat','BMsg.dat','Item.msbt','Menu.msbt','MenuKJ.msbt','HugeBattle.msbt','InitLoad.msbt','font.bffnt','font_l.bffnt','font_btl.bffnt']
def read(p):return json.loads(p.read_text(encoding='utf-8-sig'))
def digest(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def save(name,obj):(OUT/name).write_text(json.dumps(obj,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
mode=sys.argv[1]
if mode=='snapshot':
    folder=OUT/'before_merge';folder.mkdir(exist_ok=True)
    for name in ['ko_final.json','merge_report.json']:
        dst=folder/name
        assert not dst.exists(),f'Already snapshotted: {dst}'
        shutil.copy2(ROOT/'work'/name,dst)
    print('Saved previous merged text and merge report')
elif mode=='diff':
    before=read(OUT/'before_merge/ko_final.json');after=read(ROOT/'work/ko_final.json')
    changes=[{'id':mid,'before':before.get(mid),'after':text} for mid,text in after.items() if before.get(mid)!=text]
    save('merged_changes.json',changes)
    representatives=[]
    batches=0;total=0;all_ids=set();dups=0
    for p in sorted((ROOT/'text/ko').glob('*.json')):
        if p.name.startswith('_'):continue
        new=read(p)
        proc=subprocess.run(['git','show',f'HEAD:text/ko/{p.name}'],cwd=ROOT,capture_output=True,check=True,timeout=15)
        old=json.loads(proc.stdout.decode('utf8'))
        for mid,text in new['translations'].items():
            if old['translations'].get(mid)!=text:representatives.append({'batch':p.stem,'id':mid,'before':old['translations'].get(mid),'after':text,'note':new.get('notes',{}).get(mid,'')})
        batch=read(ROOT/'work/batches'/p.name)
        batches+=1;total+=len(batch['messages'])
        for m in batch['messages']:
            all_ids.add(m['id']);all_ids.update(m.get('dups',[]));dups+=len(m.get('dups',[]))
    save('representative_changes.json',representatives)
    s=io.StringIO(newline='');w=csv.DictWriter(s,fieldnames=['batch','id','before','after','note'],delimiter='\t',lineterminator='\n');w.writeheader();w.writerows(representatives)
    (OUT/'changes.tsv').write_text(s.getvalue(),encoding='utf8',newline='')
    mr=read(ROOT/'work/merge_report.json')
    assert not mr['failed'] and not mr['missing'] and not mr['dup_overrides']['errors'], mr
    assert all_ids==set(after),(len(all_ids),len(after),set(after)-all_ids)
    summary={'batches':batches,'representative_messages':total,'duplicate_links':dups,'covered_ids':len(all_ids),'final_messages':len(after),'changed_representatives':len(representatives),'changed_merged_ids':len(changes),'changed_files':sorted(set(r['batch'] for r in representatives)),'overrides_applied':len(mr['dup_overrides']['applied']),'override_errors':mr['dup_overrides']['errors'],'added_ids':sorted(set(after)-set(before)),'removed_ids':sorted(set(before)-set(after))}
    save('integration_summary.json',summary);print(json.dumps(summary,ensure_ascii=False,indent=2))
elif mode=='install':
    # Runtime testing belongs to the user; avoid replacing loaded game files.
    ps=subprocess.run(['powershell','-NoProfile','-Command',"@(Get-Process -Name azahar,citra -ErrorAction SilentlyContinue).Count"],capture_output=True,timeout=15)
    assert ps.stdout.decode('utf8',errors='replace').strip()=='0','Azahar/Citra is running'
    summary=read(OUT/'integration_summary.json')
    assert summary['changed_merged_ids']>0
    backup=ROOT/'work/build/prev_msg_before_audit_20261006'
    changed=[];hashes={}
    for name in NAMES:
        src=STAGE/REL/name;dst=PATCH/REL/name
        assert src.is_file() and dst.is_file(),name
        if src.read_bytes()!=dst.read_bytes():
            bk=backup/REL/name;bk.parent.mkdir(parents=True,exist_ok=True)
            assert not bk.exists(),f'Backup already exists: {bk}'
            shutil.copy2(dst,bk);shutil.copy2(src,dst);changed.append(name)
        assert digest(src)==digest(dst)
        hashes[name]=digest(dst)
    # Confirm Azahar's existing mod junction sees the same bytes.
    import os
    junction=Path(os.environ['APPDATA'])/'Azahar/load/mods/00040000001CA900/romfs'
    assert junction.is_dir(),junction
    for name in NAMES:assert digest(junction/REL/name)==hashes[name],name
    package=ROOT/'work/sd_package'
    distro=package/'luma/titles/00040000001CA900/romfs'
    distribution_changed=[]
    for p in PATCH.rglob('*'):
        if not p.is_file():continue
        rel=p.relative_to(PATCH);dst=distro/rel
        if not dst.exists() or digest(p)!=digest(dst):
            dst.parent.mkdir(parents=True,exist_ok=True);shutil.copy2(p,dst);distribution_changed.append(rel.as_posix())
    zpath=package/'ml3dx_ko_luma.zip'
    zipbackup=backup/'ml3dx_ko_luma.zip'
    assert not zipbackup.exists(),zipbackup
    shutil.copy2(zpath,zipbackup)
    temp=package/'ml3dx_ko_luma.audit_20261006.tmp.zip'
    updated=[]
    with zipfile.ZipFile(zpath,'r') as old,zipfile.ZipFile(temp,'w') as new:
        for info in old.infolist():
            data=old.read(info.filename)
            candidate=package/info.filename
            if not info.is_dir() and candidate.is_file() and info.filename.startswith('luma/'):
                fresh=candidate.read_bytes()
                if fresh!=data:updated.append(info.filename)
                data=fresh
            new.writestr(info,data)
    with zipfile.ZipFile(temp,'r') as z:
        assert z.testzip() is None
        for p in PATCH.rglob('*'):
            if p.is_file():
                arc='luma/titles/00040000001CA900/romfs/'+p.relative_to(PATCH).as_posix()
                assert z.read(arc)==p.read_bytes(),arc
    temp.replace(zpath)
    save('install.json',{'changed_patch_files':changed,'all_message_hashes':hashes,'azahar_junction_matches':True,'distribution_changed':distribution_changed,'zip_members_updated':updated,'zip_crc_check':'PASS','all_package_patch_bytes_match':True,'previous_files':str(backup)})
    print(f'Installed {len(changed)} changed files; all 10 stage/patch/junction hashes match. SD folder and ZIP verified against patch.')
    print('Changed: '+', '.join(changed))
else:raise ValueError(mode)
