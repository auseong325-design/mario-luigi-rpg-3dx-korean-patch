"""Dump every Korean 1DX message (ml 1dx/3romfs/Msg/KR_ko) to work/ref_1dx_ko.tsv: key<TAB>index<TAB>label<TAB>text.

Read-only on the 1DX dump. Used to look up Nintendo Korea's official wording for things 1DX and 3DX share
(the Bowser's Minions / Bowser Jr.'s Journey battle system, badge names, ...).
"""
import pathlib
import sys

sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent))
from lib3dx import read_bg4, read_msbt  # noqa: E402

ROOT = pathlib.Path(__file__).resolve().parent.parent
SRC = ROOT / "ml 1dx" / "3romfs" / "Msg" / "KR_ko"
OUT = ROOT / "work" / "ref_1dx_ko.tsv"


def rows():
    for p in sorted(SRC.iterdir()):
        data = p.read_bytes()
        if p.suffix == ".dat":
            _, entries = read_bg4(data)
            for e in entries:
                if e.data[:8] == b"MsgStdBn":
                    yield f"{p.name}:{e.name}", read_msbt(e.data)
        elif p.suffix == ".msbt":
            yield p.name, read_msbt(data)


def main():
    n = 0
    with OUT.open("w", encoding="utf-8", newline="\n") as f:
        f.write("key\tindex\tlabel\ttext\n")
        for key, doc in rows():
            for m in doc.messages:
                t = m.text.replace("\\", "\\\\").replace("\t", "\\t").replace("\n", "\\n")
                f.write(f"{key}\t{m.index}\t{m.label or ''}\t{t}\n")
                n += 1
    print(f"{n} messages -> {OUT}")


if __name__ == "__main__":
    main()
