"""Lead: compose a test build tag from an existing code-patch tag plus romfs overlays.

    python scripts/fps60/lead_compose.py <new_tag> --code <tag> [--overlay <dir_with_romfs_tree> ...]

Writes work/fps60/build/<new_tag>/{code.bps, code.ips, romfs/..., manifest.json}. Each overlay directory must
contain files laid out as romfs paths (e.g. work/fps60/build/bai/romfs -> BAI/BAI.dat). Refuses to overwrite an
existing tag. Copies only; never touches patch/.
"""
import argparse, hashlib, json, pathlib, shutil, sys, time

ROOT = pathlib.Path(__file__).resolve().parents[2]
BUILD = ROOT / 'work' / 'fps60' / 'build'


def sha(p: pathlib.Path) -> str:
    return hashlib.sha256(p.read_bytes()).hexdigest()


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('tag')
    ap.add_argument('--code', required=True)
    ap.add_argument('--overlay', action='append', default=[])
    a = ap.parse_args()

    out = BUILD / a.tag
    if out.exists():
        sys.exit(f'refusing: {out} exists')
    src = BUILD / a.code
    for name in ('code.bps', 'code.ips', 'manifest.json'):
        if not (src / name).is_file():
            sys.exit(f'missing {src / name}')
    out.mkdir(parents=True)
    man = {'tag': a.tag, 'created': time.strftime('%Y-%m-%dT%H:%M:%S%z'), 'code_from': a.code,
           'code_manifest_sha256': sha(src / 'manifest.json'), 'files': {}}
    for name in ('code.bps', 'code.ips'):
        shutil.copy2(src / name, out / name)
        man['files'][name] = sha(out / name)
    for ov in a.overlay:
        ovp = (ROOT / ov).resolve() if not pathlib.Path(ov).is_absolute() else pathlib.Path(ov)
        if not ovp.is_dir():
            sys.exit(f'overlay not a directory: {ovp}')
        for f in sorted(p for p in ovp.rglob('*') if p.is_file()):
            rel = f.relative_to(ovp)
            dst = out / 'romfs' / rel
            if dst.exists():
                sys.exit(f'overlay conflict: {rel}')
            dst.parent.mkdir(parents=True, exist_ok=True)
            shutil.copy2(f, dst)
            assert sha(dst) == sha(f)
            man['files']['romfs/' + rel.as_posix()] = sha(dst)
            man.setdefault('overlays', {}).setdefault(str(ovp.relative_to(ROOT)), []).append(rel.as_posix())
    (out / 'manifest.json').write_text(json.dumps(man, indent=2, ensure_ascii=False), encoding='utf-8')
    print(json.dumps(man, indent=2, ensure_ascii=False))


if __name__ == '__main__':
    main()
