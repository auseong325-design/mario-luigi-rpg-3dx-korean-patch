"""Install validated follow-up assets and refresh the existing distribution."""
from pathlib import Path
import hashlib, json, os, shutil, subprocess, zipfile

ROOT = Path(__file__).resolve().parents[3]
OUT = Path(__file__).resolve().parent
PATCH = ROOT / 'patch/00040000001CA900/romfs'
BACKUP = ROOT / 'work/build/prev_followup_20261007'
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()

def main():
    merge = json.loads((ROOT/'work/merge_report.json').read_text(encoding='utf8'))
    assert not merge['failed'] and not merge['missing'] and not merge['dup_overrides']['errors']
    manifest = json.loads((OUT/'furigana_build.json').read_text(encoding='utf8'))
    verified = json.loads((OUT/'furigana_verify.json').read_text(encoding='utf8'))
    assert all(manifest['patched_cro_hash_checks']) and verified['stage_hash_checks']
    assert verified['no_game_execution'] and manifest['crr_patched_hash_table_sorted']
    assert sha(ROOT/'work/build/furigana_stage/romfs/RO/MainMenu.cro') == manifest['patched_main_sha256']
    assert sha(ROOT/'work/build/furigana_stage/romfs/.crr/static.crr') == manifest['patched_crr_sha256']
    proc = subprocess.run(['powershell','-NoProfile','-Command',
        '@(Get-Process -Name azahar,citra -ErrorAction SilentlyContinue).Count'],
        capture_output=True, check=True, timeout=15)
    assert proc.stdout.decode().strip() == '0', 'Azahar/Citra is running'
    stages = [ROOT/'work/build/msg_stage/romfs']
    extra = ROOT/'work/build/furigana_stage/romfs'
    if extra.exists(): stages.append(extra)
    changed = []
    for stage in stages:
        for src in sorted(stage.rglob('*')):
            if not src.is_file(): continue
            rel = src.relative_to(stage)
            dst = PATCH/rel
            if dst.exists() and sha(src) == sha(dst): continue
            old = BACKUP/rel
            assert not old.exists(), f'Existing backup: {old}'
            old.parent.mkdir(parents=True, exist_ok=True)
            if dst.exists(): shutil.copy2(dst, old)
            dst.parent.mkdir(parents=True, exist_ok=True)
            shutil.copy2(src, dst)
            assert sha(src) == sha(dst)
            changed.append(rel.as_posix())
    junction = Path(os.environ['APPDATA'])/'Azahar/load/mods/00040000001CA900/romfs'
    package = ROOT/'work/sd_package'
    distro = package/'luma/titles/00040000001CA900/romfs'
    for p in PATCH.rglob('*'):
        if not p.is_file(): continue
        rel = p.relative_to(PATCH)
        assert sha(p) == sha(junction/rel)
        dst = distro/rel
        if not dst.exists() or sha(dst) != sha(p):
            dst.parent.mkdir(parents=True, exist_ok=True)
            shutil.copy2(p, dst)
    zpath = package/'ml3dx_ko_luma.zip'
    BACKUP.mkdir(parents=True, exist_ok=True)
    assert not (BACKUP/zpath.name).exists()
    shutil.copy2(zpath, BACKUP/zpath.name)
    temp = package/'ml3dx_ko_luma.followup_20261007.tmp.zip'
    members = set()
    with zipfile.ZipFile(zpath) as old, zipfile.ZipFile(temp,'w',compression=zipfile.ZIP_DEFLATED) as new:
        for info in old.infolist():
            candidate = package/info.filename
            data = candidate.read_bytes() if not info.is_dir() and candidate.is_file() and info.filename.startswith('luma/') else old.read(info.filename)
            new.writestr(info, data)
            members.add(info.filename)
        for p in distro.rglob('*'):
            if p.is_file():
                arc = p.relative_to(package).as_posix()
                if arc not in members: new.write(p,arc)
    with zipfile.ZipFile(temp) as z:
        assert z.testzip() is None
        for p in PATCH.rglob('*'):
            if p.is_file(): assert z.read('luma/titles/00040000001CA900/romfs/'+p.relative_to(PATCH).as_posix()) == p.read_bytes()
    temp.replace(zpath)
    result = {'changed_patch_files':changed,'stage_patch_junction_match':True,'sd_and_zip_match':True,'backup':str(BACKUP)}
    (OUT/'install.json').write_text(json.dumps(result,ensure_ascii=False,indent=2),encoding='utf8')
    print(json.dumps(result,ensure_ascii=False,indent=2))

if __name__ == '__main__': main()
