from pathlib import Path
import hashlib
import json
import os
import shutil
import subprocess
import zipfile

ROOT = Path(__file__).resolve().parents[3]
OUT = Path(__file__).parent
REL = Path('FMdl/JP/FMdl.dat')
PATCH = ROOT / 'patch/00040000001CA900/romfs'
STAGE = ROOT / 'work/build/fmdl_stage/romfs'
PACKAGE = ROOT / 'work/sd_package'
DISTRO = PACKAGE / 'luma/titles/00040000001CA900/romfs'
BACKUP = ROOT / 'work/build/prev_title_1dx_shapes_20261008'


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def read_result(name):
    return json.loads((OUT / name).read_text(encoding='utf8'))


def atomic_bytes(path, data):
    temp = path.with_name(path.name + '.1dx_shapes_20261008.tmp')
    assert not temp.exists(), f'Existing temporary file: {temp}'
    temp.write_bytes(data)
    temp.replace(path)


build = read_result('build_verify.json')
shape = read_result('shape_verify.json')
preview = read_result('preview_metrics.json')
intro = read_result('intro_preview_verify.json')
assert build['only_three_title_textures_changed']
assert build['geometry_and_animation_bytes_equal']
assert build['dx_deluxe_pixels_preserved']
assert build['both_silhouettes_remain_over_mario']
assert build['decoded_pixels_match_inputs']
assert shape['single_uniform_affine_for_entire_title_word']
assert shape['no_glyph_growth_or_stem_redesign']
assert min(shape['title_donor_mask_iou'].values()) > .99
assert shape['intro_amp_donor_mask_iou'] > .99
assert preview['all_silhouettes_inside_screen']
assert all(value == 0 for value in intro['AFTER'].values())
assert sha(STAGE / REL) == build['stage_sha256']
assert sha(PATCH / REL) == build['before_fmdl_sha256']

proc = subprocess.run(
    ['powershell', '-NoProfile', '-Command',
     '@(Get-Process -Name azahar,citra -ErrorAction SilentlyContinue).Count'],
    capture_output=True, check=True, timeout=15)
assert proc.stdout.decode().strip() == '0', 'Game is running'

zpath = PACKAGE / 'ml3dx_ko_luma.zip'
prefix = 'luma/titles/00040000001CA900/romfs/'
arc = prefix + REL.as_posix()
patch_files = [p for p in PATCH.rglob('*') if p.is_file()]
with zipfile.ZipFile(zpath) as z:
    for path in patch_files:
        rel = path.relative_to(PATCH)
        assert z.read(prefix + rel.as_posix()) == path.read_bytes()
        assert sha(DISTRO / rel) == sha(path)

assert not (BACKUP / REL).exists(), 'Preserve existing FMdl backup'
assert not (BACKUP / zpath.name).exists(), 'Preserve existing ZIP backup'
(BACKUP / REL.parent).mkdir(parents=True, exist_ok=True)
shutil.copy2(PATCH / REL, BACKUP / REL)
shutil.copy2(zpath, BACKUP / zpath.name)

data = (STAGE / REL).read_bytes()
temp_zip = PACKAGE / 'ml3dx_ko_luma.1dx_shapes_20261008.tmp.zip'
assert not temp_zip.exists(), 'Preserve existing temporary ZIP'
with zipfile.ZipFile(zpath) as old, zipfile.ZipFile(temp_zip, 'w') as new:
    new.comment = old.comment
    for info in old.infolist():
        new.writestr(info, data if info.filename == arc else old.read(info.filename))
with zipfile.ZipFile(temp_zip) as z:
    assert z.testzip() is None
    assert z.read(arc) == data

# Same-directory replacement also works when an image preview has mapped a file.
atomic_bytes(PATCH / REL, data)
atomic_bytes(DISTRO / REL, data)
temp_zip.replace(zpath)

junction = Path(os.environ['APPDATA']) / 'Azahar/load/mods/00040000001CA900/romfs'
with zipfile.ZipFile(zpath) as z:
    for path in patch_files:
        rel = path.relative_to(PATCH)
        assert sha(path) == sha(junction / rel) == sha(DISTRO / rel)
        assert z.read(prefix + rel.as_posix()) == path.read_bytes()
    assert z.testzip() is None

result = {
    'changed_patch_files': [REL.as_posix()],
    'changed_title_textures': build['changed_models'][0]['textures'],
    'stage_patch_junction_match': sha(STAGE / REL) == sha(PATCH / REL),
    'all_sd_and_zip_files_match': True,
    'checked_patch_files': len(patch_files),
    'zip_crc_check': 'PASS',
    'backup': str(BACKUP),
    'fmdl_sha256': sha(PATCH / REL),
    'zip_sha256': sha(zpath),
    'source_files_modified': False,
    'azahar_launched': False,
    'runtime_verified': False,
}
(OUT / 'install.json').write_text(
    json.dumps(result, ensure_ascii=False, indent=2) + '\n', encoding='utf8')
print(json.dumps(result, ensure_ascii=False, indent=2))
