"""RT: build (or refresh) the portable Azahar test instance in tools/azahar-test.

Only READS C:\\Program Files\\Azahar and %APPDATA%\\Azahar; every write goes under
tools/azahar-test (asserted).  Idempotent: files already copied with the same size are
skipped unless --force.

  .venv\\Scripts\\python.exe scripts\\fps60\\rt_setup.py            # build/refresh
  .venv\\Scripts\\python.exe scripts\\fps60\\rt_setup.py --config   # only regenerate qt-config.ini

What is copied (and why):
  * emulator binaries            C:\\Program Files\\Azahar\\*          -> tools/azahar-test/
  * base game + v1.2 update      sdmc title/00040000/001ca900, title/0004000e/001ca900 (content)
  * save data (copy, not move)   sdmc title/00040000/001ca900/data
  * system save data + tickets   nand/data, nand/dbs (CFG language/region, Mii DB)
  * shader cache for the title   shaders/opengl/*/00040000001CA900.bin
NOT copied: encrypted NAND system titles, nand/private (movable.sed), nand/rw/sys
(SecureInfo_A, LocalFriendCodeSeed_B) and sysdata (otp.bin): console-unique files the game
does not need.  Because of that the test config uses HLE applets (lle_applets=false).
The Korean patch: user/load/mods/00040000001CA900 is a junction to patch/00040000001CA900.
"""
from __future__ import annotations

import argparse
import os
import re
import shutil
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
TEST = ROOT / "tools" / "azahar-test"
USER = TEST / "user"
SRC_EXE = Path(r"C:\Program Files\Azahar")
SRC_USER = Path(os.environ["APPDATA"]) / "Azahar"
ZID = "0" * 32
TITLE_REL = Path("Nintendo 3DS") / ZID / ZID / "title"
PATCH = ROOT / "patch" / "00040000001CA900"
TID = "00040000001CA900"
GDB_PORT = 24689

_TEST_RESOLVED = TEST.resolve()


def _guard(dst: Path) -> None:
    """Refuse any write that does not land inside tools/azahar-test (junctions resolved)."""
    r = dst.resolve()
    if r != _TEST_RESOLVED and _TEST_RESOLVED not in r.parents:
        raise SystemExit(f"refusing to write outside the test instance: {dst} -> {r}")


def copy_file(src: Path, dst: Path, force: bool) -> bool:
    _guard(dst.parent if not dst.exists() else dst)
    if dst.exists() and not force and dst.stat().st_size == src.stat().st_size:
        return False
    dst.parent.mkdir(parents=True, exist_ok=True)
    _guard(dst.parent)
    shutil.copy2(src, dst)
    return True


def copy_tree(src: Path, dst: Path, force: bool, skip=lambda rel: False) -> tuple[int, int]:
    n_copied = n_total = 0
    for p in sorted(src.rglob("*")):
        if not p.is_file():
            continue
        rel = p.relative_to(src)
        if skip(rel):
            continue
        n_total += 1
        if copy_file(p, dst / rel, force):
            n_copied += 1
    return n_copied, n_total


# ---------------------------------------------------------------- config ---------------
def _parse_ini(text: str):
    sections: list[tuple[str, list[str]]] = [("", [])]
    for line in text.splitlines():
        m = re.match(r"^\[(.+)\]\s*$", line)
        if m:
            sections.append((m.group(1), []))
        else:
            sections[-1][1].append(line)
    return sections


def _set(lines: list[str], key: str, value: str, has_default: bool = True) -> None:
    pref = (key + "=", key + "\\default=")
    lines[:] = [l for l in lines if not l.startswith(pref)]
    if has_default:
        lines.append(f"{key}\\default=false")
    lines.append(f"{key}={value}")


def gen_config() -> str:
    src = (SRC_USER / "config" / "qt-config.ini").read_text(encoding="utf-8")
    secs = _parse_ini(src)
    names = [s for s, _ in secs]
    def sec(name: str) -> list[str]:
        if name not in names:
            secs.append((name, []))
            names.append(name)
        return secs[names.index(name)][1]

    u = USER.as_posix()
    # Controls: profile 0 = stock Azahar keyboard mapping (taken from the user's second
    # profile, which is the untouched default keyboard map). A=A B=S X=Z Y=X, D-pad T/G/F/H,
    # L=Q R=W ZL=1 ZR=2 Start=M Select=N Home=B, circle pad = arrow keys, C-stick IJKL.
    c = sec("Controls")
    default_prof = [l for l in c if l.startswith("profiles\\2\\")]
    c[:] = [l for l in c if not l.startswith("profiles\\")]
    for l in default_prof:
        l = "profiles\\1\\" + l[len("profiles\\2\\"):]
        if l.startswith("profiles\\1\\name="):
            l = "profiles\\1\\name=RT keyboard"
        c.append(l)
    c.append("profiles\\size=1")
    _set(c, "profile", "0", has_default=False)

    ds = sec("Data%20Storage")
    _set(ds, "use_custom_storage", "false")
    _set(ds, "nand_directory", f"{u}/nand/")
    _set(ds, "sdmc_directory", f"{u}/sdmc/")

    dbg = sec("Debugging")
    _set(dbg, "use_gdbstub", "true")
    _set(dbg, "gdbstub_port", str(GDB_PORT))
    _set(dbg, "enable_rpc_server", "true")

    misc = sec("Miscellaneous")
    _set(misc, "check_for_update_on_start", "false")
    # RT2: the RPC server logs two Info lines per request; a memory scan made the log 3+ MB and
    # slowed `rt_rpc.py cros`. Keep everything else at Info (CRO loads, LayeredFS lines).
    _set(misc, "log_filter", "*:Info RPC_Server:Warning")

    ws = sec("WebService")
    ws[:] = [re.sub(r"^([^=\\]*(?:token|username|password)[^=\\]*)=.*$", r"\1=", l, flags=re.I)
             for l in ws]

    sysc = sec("System")
    _set(sysc, "is_new_3ds", "true")
    _set(sysc, "lle_applets", "false")

    aud = sec("Audio")
    _set(aud, "volume", "0")

    ui = sec("UI")
    ui[:] = [l for l in ui if not re.match(r"^Paths\\gamedirs\\[3-9]\\", l)]
    _set(ui, "Paths\\gamedirs\\size", "2", has_default=False)
    _set(ui, "Paths\\screenshotPath", f"{u}/screenshots/")
    _set(ui, "Paths\\romsPath", "", has_default=False)
    _set(ui, "Paths\\recentFiles", "", has_default=False)
    _set(ui, "Paths\\last_artic_base_addr", "")
    _set(ui, "Paths\\language", "en")
    for k, v in (("enable_discord_presence", "false"), ("confirmClose", "false"),
                 ("saveStateWarning", "false"), ("pauseWhenInBackground", "false"),
                 ("muteWhenInBackground", "false"), ("firstStart", "false"),
                 ("showStatusBar", "true")):
        _set(ui, k, v)

    out = []
    for name, lines in secs:
        if name:
            out.append(f"[{name}]")
        out.extend(lines)
    text = "\n".join(out).rstrip("\n") + "\n"
    # Final safety net: the test config must not reference the user's Azahar dir.
    bad = [l for l in text.splitlines()
           if re.search(r"AppData[\\/]+Roaming[\\/]+Azahar", l, re.I)]
    if bad:
        raise SystemExit("generated config still points at the user's Azahar dir:\n" + "\n".join(bad))
    return text


def write_config() -> Path:
    cfg = USER / "config" / "qt-config.ini"
    cfg.parent.mkdir(parents=True, exist_ok=True)
    _guard(cfg.parent)
    cfg.write_text(gen_config(), encoding="utf-8", newline="\n")
    return cfg


# ---------------------------------------------------------------- main -----------------
def main() -> None:
    ap = argparse.ArgumentParser()
    ap.add_argument("--force", action="store_true", help="recopy files even if sizes match")
    ap.add_argument("--config", action="store_true", help="only regenerate qt-config.ini")
    a = ap.parse_args()

    TEST.mkdir(parents=True, exist_ok=True)
    gi = TEST / ".gitignore"
    if not gi.exists():
        gi.write_text("# RT test instance: emulator binaries, game content, saves, system data.\n"
                      "# Never commit any of it.\n*\n!.gitignore\n", encoding="utf-8")
    if a.config:
        print("config:", write_config())
        return

    print("binaries: %d copied / %d" % copy_tree(SRC_EXE, TEST, a.force))
    (USER / "screenshots").mkdir(parents=True, exist_ok=True)
    (USER / "cheats").mkdir(parents=True, exist_ok=True)
    (USER / "sysdata").mkdir(parents=True, exist_ok=True)

    sd_src = SRC_USER / "sdmc" / TITLE_REL
    sd_dst = USER / "sdmc" / TITLE_REL
    for rel in ("00040000/001ca900/content", "00040000/001ca900/data", "0004000e/001ca900/content"):
        print(f"sdmc {rel}: %d copied / %d" % copy_tree(sd_src / rel, sd_dst / rel, a.force))
    # the save's 00000001.metadata sits next to data/00000001 and is inside the data tree

    nand_src, nand_dst = SRC_USER / "nand", USER / "nand"
    for rel in ("data", "dbs"):
        print(f"nand {rel}: %d copied / %d" % copy_tree(nand_src / rel, nand_dst / rel, a.force))

    for kind in ("precompiled/separable", "transferable"):
        s = SRC_USER / "shaders" / "opengl" / Path(kind) / f"{TID}.bin"
        if s.exists():
            copy_file(s, USER / "shaders" / "opengl" / Path(kind) / f"{TID}.bin", a.force)

    mods = USER / "load" / "mods"
    mods.mkdir(parents=True, exist_ok=True)
    link = mods / TID
    if not link.exists():
        import _winapi
        _winapi.CreateJunction(str(PATCH), str(link))
    print("mods junction:", link, "->", os.path.realpath(link))

    print("config:", write_config())


if __name__ == "__main__":
    main()
