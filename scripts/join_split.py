"""Reassemble files split into _split/ (GitHub 100MB limit) back to their original paths."""
import pathlib, collections
root = pathlib.Path(__file__).resolve().parent.parent
groups = collections.defaultdict(list)
for p in (root / "_split").rglob("*.part*"):
    groups[p.parent / p.name.split(".part")[0]].append(p)
for base, parts in groups.items():
    out = root / base.relative_to(root / "_split")
    out.parent.mkdir(parents=True, exist_ok=True)
    with open(out, "wb") as f:
        for part in sorted(parts):
            f.write(part.read_bytes())
    print(out, out.stat().st_size)
