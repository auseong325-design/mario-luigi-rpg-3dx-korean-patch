"""Ghidra headless runner for the fps60 workstream TG.

    python scripts/fps60/ghidra/ghidra_run.py import 3dx_v12        # prepare.py + import + analysis + PostAnalysis
    python scripts/fps60/ghidra/ghidra_run.py dump 3dx_v12 [--threads 6] [--modules static,Battle] [--out DIR]
    python scripts/fps60/ghidra/ghidra_run.py status

Project: work/fps60/ghidra/<game>/<game>.gpr (+ .rep), program '<game>.code.bin'.
Dumps:   work/fps60/decomp/<game>/<module>.c, functions.tsv, summary.txt.
Logs:    work/fps60/ghidra/<game>/logs/.
Every Ghidra run has a hard timeout; on timeout the whole process tree is killed.
"""
from __future__ import annotations

import argparse
import os
import subprocess
import sys
import time

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(os.path.dirname(os.path.dirname(HERE)))
GHIDRA = os.path.join(ROOT, "tools", "ghidra", "ghidra_12.2_PUBLIC")
HEADLESS = os.path.join(GHIDRA, "support", "analyzeHeadless.bat")
LANG, CSPEC = "ARM:LE:32:v6", "hardfp"
GAMES = ("3dx_v12", "1dx_kr")


def proj_dir(game: str) -> str:
    return os.path.join(ROOT, "work", "fps60", "ghidra", game)


def program_name(game: str) -> str:
    return f"{game}.code.bin"


def kill_tree(pid: int) -> None:
    subprocess.run(["taskkill", "/T", "/F", "/PID", str(pid)], stdout=subprocess.DEVNULL,
                   stderr=subprocess.DEVNULL, timeout=60)


# ------------------------------------------------------------------ snapshot slots
# Ghidra locks a project while a process has it open, so every read-only consumer (dumps, decomp.py)
# works on a private copy of the master project: a pool of slot directories, one user per slot
# (exclusive lock file holding the owner PID), re-copied whenever the master project changes.
MAX_SLOTS = 8


def pid_alive(pid: int) -> bool:
    import ctypes
    k32 = ctypes.windll.kernel32
    h = k32.OpenProcess(0x1000, False, pid)  # PROCESS_QUERY_LIMITED_INFORMATION
    if not h:
        return ctypes.GetLastError() == 5  # access denied -> exists
    code = ctypes.c_ulong()
    ok = k32.GetExitCodeProcess(h, ctypes.byref(code))
    k32.CloseHandle(h)
    return bool(ok) and code.value == 259  # STILL_ACTIVE


def snap_base() -> str:
    import tempfile
    for cand in (os.path.join(tempfile.gettempdir(), "fps60_ghidra_snap"),
                 os.path.join(ROOT, "work", "fps60", "ghidra", "_snap")):
        parts = os.path.normpath(cand).split(os.sep)
        if not any(p.startswith(".") for p in parts[1:]):  # Ghidra refuses '.'-prefixed path elements
            return cand
    raise SystemExit("no usable snapshot directory")


def project_stamp(game: str) -> str:
    rep = os.path.join(proj_dir(game), f"{game}.rep")
    latest, n = 0.0, 0
    for dp, _dn, fns in os.walk(rep):
        for fn in fns:
            st = os.stat(os.path.join(dp, fn))
            latest = max(latest, st.st_mtime)
            n += 1
    return f"{latest:.3f}:{n}"


def master_locked(game: str) -> bool:
    return os.path.exists(os.path.join(proj_dir(game), f"{game}.lock"))


class Slot:
    """with Slot(game) as s: run analyzeHeadless on s.dir (project name = game)."""

    def __init__(self, game: str, wait_s: int = 900):
        self.game, self.wait_s = game, wait_s
        self.dir: str | None = None
        self.lock: str | None = None

    def __enter__(self) -> "Slot":
        import shutil  # noqa: F401
        base = os.path.join(snap_base(), self.game)
        os.makedirs(base, exist_ok=True)
        deadline = time.time() + self.wait_s
        while self.dir is None:
            for k in range(MAX_SLOTS):
                lock = os.path.join(base, f"slot{k}.lock")
                try:
                    fd = os.open(lock, os.O_CREAT | os.O_EXCL | os.O_WRONLY)
                except FileExistsError:
                    try:
                        pid = int(open(lock).read().split()[0])
                    except (OSError, ValueError, IndexError):
                        pid = -1
                    if pid > 0 and not pid_alive(pid):
                        try:
                            os.remove(lock)  # stale (owner died)
                        except OSError:
                            pass
                    continue
                os.write(fd, f"{os.getpid()} {time.time():.0f}\n".encode())
                os.close(fd)
                self.lock, self.dir = lock, os.path.join(base, f"slot{k}")
                break
            if self.dir is None:
                if time.time() > deadline:
                    raise SystemExit(f"all {MAX_SLOTS} snapshot slots busy for {self.wait_s}s")
                time.sleep(3)
        try:
            self.refresh()
        except BaseException:
            self.__exit__()
            raise
        return self

    def refresh(self) -> None:
        import shutil
        stamp_file = os.path.join(self.dir, "stamp.txt")
        src = proj_dir(self.game)
        if not os.path.exists(os.path.join(src, f"{self.game}.gpr")):
            raise SystemExit(f"no Ghidra project for {self.game} yet (see work/fps60/TOOLS_STATUS.md)")
        if master_locked(self.game):
            if os.path.exists(stamp_file):
                sys.stderr.write("[ghidra] master project is being updated; using the existing snapshot\n")
                return
            raise SystemExit("master project is locked by a running import; retry later or use --cached")
        stamp = project_stamp(self.game)
        if os.path.exists(stamp_file) and open(stamp_file).read().strip() == stamp:
            return
        sys.stderr.write(f"[ghidra] refreshing snapshot {self.dir}\n")
        if os.path.exists(self.dir):
            shutil.rmtree(self.dir)
        os.makedirs(self.dir)
        shutil.copy2(os.path.join(src, f"{self.game}.gpr"), self.dir)
        shutil.copytree(os.path.join(src, f"{self.game}.rep"), os.path.join(self.dir, f"{self.game}.rep"))
        with open(stamp_file, "w") as f:
            f.write(stamp)

    def __exit__(self, *exc) -> None:
        if self.dir and os.path.isdir(self.dir):
            for fn in os.listdir(self.dir):
                if fn.endswith((".lock", ".lock~")):
                    try:
                        os.remove(os.path.join(self.dir, fn))  # leftover Ghidra project lock after a kill
                    except OSError:
                        pass
        if self.lock:
            try:
                os.remove(self.lock)
            except OSError:
                pass
            self.lock = None


def bat_cmdline(args: list[str]) -> str:
    """Command line for a .bat: quote EVERY argument, because cmd.exe also splits unquoted %1..%9 on
    '=', ',' and ';' (e.g. 'a=b,c' would reach analyzeHeadless as three arguments)."""
    out = []
    for a in args:
        if '"' in a or a.endswith("\\"):
            a = a.replace('"', "'").rstrip("\\")
        out.append(f'"{a}"')
    return " ".join(out)


def run_headless(argv: list[str], log_base: str, timeout_s: int, maxmem: str = "4G",
                 quiet: bool = False) -> int:
    """Run analyzeHeadless with stdout/stderr to <log_base>.out/.err; kill the tree after timeout_s."""
    os.makedirs(os.path.dirname(log_base), exist_ok=True)
    env = dict(os.environ)
    env["GHIDRA_HEADLESS_MAXMEM"] = maxmem
    env.setdefault("JAVA_HOME", r"C:\Program Files\Eclipse Adoptium\jdk-25.0.5.8-hotspot")
    with open(log_base + ".out", "w", encoding="utf-8", errors="replace") as fo, \
            open(log_base + ".err", "w", encoding="utf-8", errors="replace") as fe:
        t0 = time.time()
        p = subprocess.Popen('cmd.exe /d /s /c "' + bat_cmdline([HEADLESS] + argv) + '"', stdout=fo, stderr=fe,
                             stdin=subprocess.DEVNULL, env=env, cwd=ROOT,
                             creationflags=getattr(subprocess, "CREATE_NO_WINDOW", 0))
        try:
            rc = p.wait(timeout=timeout_s)
        except subprocess.TimeoutExpired:
            kill_tree(p.pid)
            p.wait(timeout=60)
            rc = -9
            fe.write(f"\n[ghidra_run] TIMEOUT after {timeout_s}s; process tree {p.pid} killed\n")
        if not quiet:
            print(f"[ghidra_run] rc={rc} in {time.time() - t0:.0f}s; log {log_base}.out")
    return rc


def layout_load_len(game: str) -> int:
    with open(os.path.join(proj_dir(game), "layout.tsv"), encoding="utf-8") as f:
        for line in f:
            if line.startswith("STATIC\t"):
                return int(line.rstrip("\n").split("\t")[2], 16)
    raise SystemExit("layout.tsv has no STATIC row; run prepare.py first")


def cmd_import(game: str, timeout_s: int, test: bool = False) -> int:
    py = sys.executable
    r = subprocess.run([py, os.path.join(HERE, "prepare.py"), game], cwd=ROOT, timeout=900)
    if r.returncode:
        return r.returncode
    d = proj_dir(game)
    logs = os.path.join(d, "logs")
    code_bin = os.path.join(ROOT, "work", "fps60", "bin", f"{game}.code.bin")
    pd = os.path.join(ROOT, "work", "fps60", "ghidra", "_test") if test else d
    os.makedirs(pd, exist_ok=True)
    argv = [pd, game, "-import", code_bin, "-overwrite",
            "-loader", "BinaryLoader", "-loader-baseAddr", "0x100000",
            "-loader-length", hex(layout_load_len(game)), "-loader-blockName", "static.text",
            "-processor", LANG, "-cspec", CSPEC,
            "-scriptPath", HERE,
            "-preScript", "ImportLayout.java", os.path.join(d, "layout.tsv"),
            "-postScript", "PostAnalysis.java", os.path.join(d, "layout.tsv"),
            os.path.join(d, "stats_test.tsv" if test else "stats.tsv"),
            "-analysisTimeoutPerFile", str(max(600, timeout_s - 1200)), "-max-cpu", "8",
            "-log", os.path.join(logs, "test.log" if test else "import.log"),
            "-scriptlog", os.path.join(logs, "test_script.log" if test else "import_script.log")]
    if test:
        argv += ["-noanalysis", "-readOnly"]
    return run_headless(argv, os.path.join(logs, "test" if test else "import"), timeout_s, maxmem="6G")


def cro_modules(game: str) -> list[str]:
    import json
    link = json.load(open(os.path.join(ROOT, "work", "fps60", "link", game, "link.json"), encoding="utf-8"))
    return sorted(link["modules"])


def dump_group(game: str, modules: str, out: str, threads: int, timeout_s: int, func_timeout: int,
               split_mb: int) -> int:
    logs = os.path.join(proj_dir(game), "logs")
    tag = "dump_" + ("all" if modules == "all" else modules.replace(",", "_")[:60])
    with Slot(game) as slot:
        argv = [slot.dir, game, "-process", program_name(game), "-noanalysis", "-readOnly",
                "-scriptPath", HERE,
                "-postScript", "DumpDecomp.java", out, str(threads), str(func_timeout), str(split_mb), modules,
                "-log", os.path.join(logs, f"{tag}.log"), "-scriptlog", os.path.join(logs, f"{tag}_script.log")]
        return run_headless(argv, os.path.join(logs, tag), timeout_s, maxmem="5G")


def cmd_dump(game: str, threads: int, modules: str, out: str | None, timeout_s: int, func_timeout: int,
             split_mb: int, jobs: int) -> int:
    """Dump into <out>.tmp, then move every file into <out> (per-file replace, readers never see halves)."""
    import concurrent.futures
    import glob
    import shutil
    final = out or os.path.join(ROOT, "work", "fps60", "decomp", game)
    stage = final.rstrip("\\/") + ".tmp"
    if os.path.exists(stage):
        shutil.rmtree(stage)
    os.makedirs(stage)
    if modules == "all" and jobs > 1:
        cros = cro_modules(game)
        groups = [["static"]] + [cros[i::jobs - 1] for i in range(jobs - 1)]
        groups = [",".join(g) for g in groups if g]
    else:
        groups = [modules]
    with concurrent.futures.ThreadPoolExecutor(len(groups)) as ex:
        futs = {ex.submit(dump_group, game, g, stage, threads, timeout_s, func_timeout, split_mb): g for g in groups}
        rcs = {futs[f]: f.result() for f in concurrent.futures.as_completed(futs)}
    print("[ghidra_run] dump groups:", rcs)
    # merge per-group index/summary files
    rows, header = [], None
    for p in sorted(glob.glob(os.path.join(stage, "functions*.tsv"))):
        with open(p, encoding="utf-8") as f:
            header = f.readline()
            rows += [ln for ln in f if ln.strip()]
        os.remove(p)
    rows.sort(key=lambda ln: int(ln.split("\t", 1)[0], 16))
    summ = []
    for p in sorted(glob.glob(os.path.join(stage, "summary*.txt"))):
        summ += open(p, encoding="utf-8").read().splitlines()
        os.remove(p)
    os.makedirs(final, exist_ok=True)
    if modules != "all":  # partial re-dump: keep other modules' index rows
        old = os.path.join(final, "functions.tsv")
        done = set(modules.split(","))
        if os.path.exists(old):
            with open(old, encoding="utf-8") as f:
                old_header = f.readline()
                header = header or old_header
                for ln in f:
                    if ln.strip() and ln.split("\t")[3] not in done:
                        rows.append(ln)
            rows.sort(key=lambda ln: int(ln.split("\t", 1)[0], 16))
        olds = os.path.join(final, "summary.txt")
        if os.path.exists(olds):
            summ = [s for s in open(olds, encoding="utf-8").read().splitlines()
                    if s.split("\t")[0] not in done] + summ
    with open(os.path.join(stage, "functions.tsv"), "w", encoding="utf-8", newline="\n") as f:
        f.write(header or "addr\tend\tsize\tmodule\tname\tsymbol\tfile\tline\tstatus\tcallers\n")
        f.writelines(rows)
    with open(os.path.join(stage, "summary.txt"), "w", encoding="utf-8", newline="\n") as f:
        f.write("\n".join(summ) + "\n")
    for fn in sorted(os.listdir(stage)):
        for attempt in range(20):
            try:
                os.replace(os.path.join(stage, fn), os.path.join(final, fn))
                break
            except PermissionError:
                time.sleep(3)  # a reader has the old file open
        else:
            print(f"[ghidra_run] could not replace {fn}; left in {stage}")
    if not os.listdir(stage):
        os.rmdir(stage)
    bad = {g: rc for g, rc in rcs.items() if rc}
    return 1 if bad else 0


def cmd_status() -> None:
    for g in GAMES:
        d = proj_dir(g)
        gpr = os.path.join(d, f"{g}.gpr")
        print(f"{g}: project {'yes' if os.path.exists(gpr) else 'no'}  ({d})")
        st = os.path.join(d, "stats.tsv")
        if os.path.exists(st):
            print(open(st, encoding="utf-8").read().rstrip())
        dd = os.path.join(ROOT, "work", "fps60", "decomp", g)
        sm = os.path.join(dd, "summary.txt")
        if os.path.exists(sm):
            print(open(sm, encoding="utf-8").read().rstrip())


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("cmd", choices=["import", "dump", "status"])
    ap.add_argument("game", nargs="?", choices=GAMES)
    ap.add_argument("--threads", type=int, default=6)
    ap.add_argument("--modules", default="all", help="comma list (static,Battle,...) or all")
    ap.add_argument("--out", default=None)
    ap.add_argument("--timeout", type=int, default=4 * 3600, help="hard timeout of the Ghidra run (s)")
    ap.add_argument("--func-timeout", type=int, default=90, help="per-function decompiler timeout (s)")
    ap.add_argument("--split-mb", type=int, default=30)
    ap.add_argument("--test", action="store_true", help="import: no analysis, throwaway read-only project")
    ap.add_argument("--jobs", type=int, default=2, help="dump: parallel Ghidra processes (static + CRO groups)")
    a = ap.parse_args()
    if a.cmd == "status":
        cmd_status()
        return
    if not a.game:
        ap.error("game required")
    if a.cmd == "import":
        sys.exit(cmd_import(a.game, a.timeout, a.test))
    sys.exit(cmd_dump(a.game, a.threads, a.modules, a.out, a.timeout, a.func_timeout, a.split_mb, a.jobs))


if __name__ == "__main__":
    main()
