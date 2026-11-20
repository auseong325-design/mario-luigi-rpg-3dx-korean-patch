"""RT: memory client for Azahar's UDP RPC server (port 45987), for the M&L RPG3 DX test instance.

Protocol (Azahar 2126.1.2, src/core/rpc): header <IIII> = version(1), request id, type, data size;
types 1=ReadMemory(addr,size<=1024) 2=WriteMemory(addr,size,data) 3=ProcessList(start,max)
4=SetGetProcess(op 0=get/1=set, pid).  Reads/writes go through the SELECTED process's page table.

LIMITS of the 2126.1.2 server (read src/core/rpc/rpc_server.cpp):
  * WriteMemory is silently ignored outside 0x00100000-0x04000000 (image), 0x08000000-0x10000000
    (heap), 0x14000000-0x1C000000 (old linear heap), 0x1E800000-0x1EC00000 (N3DS extra RAM).
    This game uses the NEW linear heap at 0x30000000 (kernel 2.52), so writes there need
    rt_gdb.py (GDB 'M' packet) -- `write` below refuses them instead of pretending.
  * Reading an unmapped page returns zeros AND logs one error line per page in the emulator log.
    Only read known-mapped ranges (see `regions` / rt_gdb.py `map`).
  * Reads are asynchronous to emulation (no pause): fine for scans, racy for fast-changing data.

CLI (run with the project venv):
  rt_rpc.py ps                          list processes, select the game (title 00040000001CA900)
  rt_rpc.py read ADDR LEN               hexdump
  rt_rpc.py dump ADDR LEN FILE          raw dump
  rt_rpc.py write ADDR HEX              write bytes (image/heap/old-linear only, see above)
  rt_rpc.py find HEX [--range A:L ...]  search a byte pattern
  rt_rpc.py watch ADDR [--fmt I] [--secs 2] [--hz 50]   sample a value, report rate per second
  rt_rpc.py cros [--log FILE]           CRO runtime bases from the emulator log
  rt_rpc.py tasks [--range A:L ...] [--json OUT]   find live ad::fw::TaskBase objects via RTTI
Addresses accept 0x-hex or decimal.  Default ranges come from rt_rpc.DEFAULT_RANGES or --range.
"""
from __future__ import annotations

import argparse
import json
import os
import random
import re
import socket
import struct
import sys
import time
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
TEST_USER = ROOT / "tools" / "azahar-test" / "user"
LOG_FILE = TEST_USER / "log" / "azahar_log.txt"
SYMBOLS = ROOT / "work" / "fps60" / "link" / "3dx_v12" / "symbols.tsv"
GAME_TID = 0x00040000001CA900

PORT = 45987
VERSION = 1
MAX_DATA = 1024
T_READ, T_WRITE, T_PLIST, T_PROC = 1, 2, 3, 4

# Static image of 3DX v1.2 (text/rodata/data/bss), see work/fps60/BRIEF.md section 3.
STATIC_LO, STATIC_HI = 0x00100000, 0x00434D40
RPC_WRITABLE = ((0x00100000, 0x04000000), (0x08000000, 0x10000000),
                (0x14000000, 0x1C000000), (0x1E800000, 0x1EC00000))
# Mapped data ranges measured at runtime (rt_gdb.py map); override with --range.
DEFAULT_RANGES: list[tuple[int, int]] = []
RANGES_FILE = ROOT / "work" / "fps60" / "runtime" / "memmap.json"


def parse_int(s: str) -> int:
    return int(s, 0)


class Rpc:
    def __init__(self, host: str = "127.0.0.1", port: int = PORT, timeout: float = 1.0,
                 retries: int = 3):
        self.addr = (host, port)
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        self.sock.settimeout(timeout)
        self.retries = retries

    # -- transport -------------------------------------------------------------------
    def _req(self, rtype: int, payload: bytes) -> bytes:
        last = None
        for _ in range(self.retries):
            rid = random.getrandbits(32)
            pkt = struct.pack("<IIII", VERSION, rid, rtype, len(payload)) + payload
            self.sock.sendto(pkt, self.addr)
            deadline = time.monotonic() + self.sock.gettimeout()
            while time.monotonic() < deadline:
                try:
                    raw = self.sock.recv(MAX_DATA + 0x10)
                except socket.timeout as e:
                    last = e
                    break
                except ConnectionResetError as e:  # Windows: ICMP port unreachable
                    raise ConnectionError("RPC server not reachable (is the emulator running "
                                          "with enable_rpc_server=true?)") from e
                ver, rrid, rrtype, size = struct.unpack_from("<IIII", raw)
                if rrid != rid:
                    continue  # stale reply of an earlier timed-out request
                if ver != VERSION or rrtype != rtype or size != len(raw) - 16:
                    raise ConnectionError("malformed RPC reply")
                return raw[16:]
        raise ConnectionError(f"RPC request type {rtype} timed out ({last})")

    # -- process selection -----------------------------------------------------------
    def process_list(self) -> dict[int, tuple[int, str]]:
        procs: dict[int, tuple[int, str]] = {}
        start = 0
        while True:
            data = self._req(T_PLIST, struct.pack("<II", start, 0x7FFFFFFF))
            if len(data) < 4:
                break
            n = struct.unpack_from("<I", data)[0]
            if n == 0:
                break
            for i in range(n):
                pid, tid, name = struct.unpack_from("<IQ8s", data, 4 + i * 0x14)
                procs[pid] = (tid, name.rstrip(b"\0").decode("ascii", "replace"))
            start += n
        return procs

    def get_process(self) -> int:
        return struct.unpack("<I", self._req(T_PROC, struct.pack("<II", 0, 0)))[0]

    def set_process(self, pid: int) -> None:
        self._req(T_PROC, struct.pack("<II", 1, pid))

    def select_game(self, tid: int = GAME_TID) -> int:
        for pid, (t, _name) in self.process_list().items():
            if t == tid:
                if self.get_process() != pid:
                    self.set_process(pid)
                return pid
        raise LookupError(f"title {tid:016X} is not running")

    # -- memory ----------------------------------------------------------------------
    def read(self, addr: int, size: int) -> bytes:
        out = bytearray()
        while size > 0:
            n = min(size, MAX_DATA)
            data = self._req(T_READ, struct.pack("<II", addr, n))
            if len(data) != n:
                raise IOError(f"short read at {addr:#x}: {len(data)}/{n}")
            out += data
            addr += n
            size -= n
        return bytes(out)

    def u32(self, addr: int) -> int:
        return struct.unpack("<I", self.read(addr, 4))[0]

    def write(self, addr: int, data: bytes) -> None:
        end = addr + len(data)
        if not any(lo <= addr and end <= hi for lo, hi in RPC_WRITABLE):
            raise PermissionError(f"Azahar's RPC server ignores writes to {addr:#010x}; "
                                  "use rt_gdb.py write for the 0x30000000 linear heap")
        step = MAX_DATA - 8
        for off in range(0, len(data), step):
            chunk = data[off:off + step]
            self._req(T_WRITE, struct.pack("<II", addr + off, len(chunk)) + chunk)


# ------------------------------------------------------------------------------------
def load_ranges(args_ranges) -> list[tuple[int, int]]:
    if args_ranges:
        out = []
        for r in args_ranges:
            a, l = r.split(":")
            out.append((parse_int(a), parse_int(l)))
        return out
    if RANGES_FILE.exists():
        j = json.loads(RANGES_FILE.read_text(encoding="utf-8"))
        return [(parse_int(r["start"]), parse_int(r["size"])) for r in j["data_ranges"]]
    if DEFAULT_RANGES:
        return DEFAULT_RANGES
    raise SystemExit("no ranges known: run rt_gdb.py map first or pass --range ADDR:LEN")


def flush_log(rpc: "Rpc", settle: float = 0.3) -> None:
    """RT2: Azahar's file log backend flushes only on Error-level lines (or when its buffer fills),
    so fresh 'CRO ... loaded' lines can be missing for minutes.  Reading one unmapped word through
    RPC logs one Memory <Error> line, which flushes the file; harmless (the read returns zeros)."""
    try:
        rpc.read(0x05000000, 4)
    except Exception:
        pass
    time.sleep(settle)


def parse_cro_log(path: Path = LOG_FILE) -> dict[str, dict]:
    """CRO name -> {'base': runtime base, 'end': fixed_end, 'loaded': bool, 'events': n}."""
    cur: dict[str, dict] = {}
    if not path.exists():
        return cur
    load_re = re.compile(r'CRO "([^"]+)" loaded at 0x([0-9A-Fa-f]+), fixed_end=0x([0-9A-Fa-f]+)')
    unload_re = re.compile(r'Unloading CRO "([^"]+)"')
    for line in path.read_text(encoding="utf-8", errors="replace").splitlines():
        m = load_re.search(line)
        if m:
            d = cur.setdefault(m.group(1), {"events": 0})
            d.update(base=int(m.group(2), 16), end=int(m.group(3), 16), loaded=True)
            d["events"] += 1
            continue
        m = unload_re.search(line)
        if m and m.group(1) in cur:
            cur[m.group(1)]["loaded"] = False
    return cur


def load_symbols() -> dict[int, str]:
    syms: dict[int, str] = {}
    if SYMBOLS.exists():
        for line in SYMBOLS.read_text(encoding="utf-8").splitlines():
            parts = line.split("\t")
            if len(parts) >= 3:
                syms[int(parts[0], 16)] = parts[2]
    return syms


def hexdump(addr: int, data: bytes) -> str:
    lines = []
    for i in range(0, len(data), 16):
        row = data[i:i + 16]
        lines.append(f"{addr + i:08x}  " + " ".join(f"{b:02x}" for b in row).ljust(48)
                     + "  " + "".join(chr(b) if 32 <= b < 127 else "." for b in row))
    return "\n".join(lines)


class Image:
    """Local snapshot of code/rodata/data (static + loaded CROs) to resolve vtables/RTTI fast."""

    SEG_NAMES = {0: "text", 1: "rodata", 2: "data", 3: "bss"}

    def __init__(self, rpc: Rpc, cros: dict[str, dict], with_bss: bool = False):
        self.blocks: list[tuple[int, bytes, str]] = []
        self.segments: dict[str, list[tuple[str, int, int]]] = {}
        self.blocks.append((STATIC_LO, rpc.read(STATIC_LO, STATIC_HI - STATIC_LO), "static"))
        for name, d in cros.items():
            if not d.get("loaded"):
                continue
            try:
                segs = self.cro_segments(rpc, d["base"])
            except IOError:
                # RT2: the emulator log is flushed lazily, so a CRO unloaded a moment ago can still
                # look loaded; its header is gone -> skip it instead of failing the whole scan.
                d["loaded"] = False
                continue
            self.segments[name] = segs
            for kind, addr, size in segs:
                if size and (kind != "bss" or with_bss):
                    self.blocks.append((addr, rpc.read(addr, size), f"{name}.{kind}"))

    @classmethod
    def cro_segments(cls, rpc: Rpc, base: int) -> list[tuple[str, int, int]]:
        """Runtime segments of a loaded CRO. Azahar's LDR:RO rebases the header and the segment
        table in place: text/rodata -> base + offset, data/bss -> the buffers the game passed."""
        hdr = rpc.read(base, 0x138)
        if hdr[0x80:0x84] != b"CRO0":
            raise IOError(f"no CRO0 magic at {base:#x}")
        tab, cnt = struct.unpack_from("<II", hdr, 0xC8)
        if tab < base:  # not rebased (should not happen for a loaded CRO)
            tab += base
        out = []
        raw = rpc.read(tab, 12 * cnt)
        for i in range(cnt):
            off, size, kind = struct.unpack_from("<III", raw, 12 * i)
            out.append((cls.SEG_NAMES.get(kind, str(kind)), off, size))
        return out

    def module_of(self, addr: int) -> str | None:
        for lo, data, name in self.blocks:
            if lo <= addr < lo + len(data):
                return name
        return None

    def u32(self, addr: int) -> int | None:
        for lo, data, _ in self.blocks:
            if lo <= addr and addr + 4 <= lo + len(data):
                return struct.unpack_from("<I", data, addr - lo)[0]
        return None

    def cstr(self, addr: int, limit: int = 200) -> str | None:
        for lo, data, _ in self.blocks:
            if lo <= addr < lo + len(data):
                off = addr - lo
                end = data.find(b"\0", off, off + limit)
                if end < 0:
                    return None
                s = data[off:end]
                return s.decode("ascii") if all(32 < c < 127 for c in s) and s else None
        return None


class Rtti:
    """Itanium C++ ABI RTTI walker over an Image (vptr-4 -> typeinfo -> name/bases)."""

    def __init__(self, img: Image, syms: dict[int, str]):
        self.img = img
        inv = {v: k for k, v in syms.items()}
        self.ti_vt = {}
        for kind, sym in (("class", "_ZTVN10__cxxabiv117__class_type_infoE"),
                          ("si", "_ZTVN10__cxxabiv120__si_class_type_infoE"),
                          ("vmi", "_ZTVN10__cxxabiv121__vmi_class_type_infoE")):
            if sym in inv:
                self.ti_vt[inv[sym] + 8] = kind
        self.cache: dict[int, tuple[str, list[int]] | None] = {}

    def typeinfo(self, ti: int):
        if ti in self.cache:
            return self.cache[ti]
        res = None
        vt = self.img.u32(ti)
        kind = self.ti_vt.get(vt)
        if kind:
            name = self.img.cstr(self.img.u32(ti + 4) or 0)
            if name:
                bases: list[int] = []
                if kind == "si":
                    bases = [self.img.u32(ti + 8) or 0]
                elif kind == "vmi":
                    n = self.img.u32(ti + 12) or 0
                    if n < 16:
                        bases = [self.img.u32(ti + 16 + 8 * i) or 0 for i in range(n)]
                res = (name, bases)
        self.cache[ti] = res
        return res

    def chain(self, ti: int, depth: int = 0) -> list[str]:
        t = self.typeinfo(ti)
        if not t or depth > 12:
            return []
        out = [t[0]]
        for b in t[1]:
            out += self.chain(b, depth + 1)
        return out

    def class_of_vptr(self, vptr: int):
        if self.img.module_of(vptr) is None or vptr & 3:
            return None
        ti = self.img.u32(vptr - 4)
        if ti is None or self.typeinfo(ti) is None:
            return None
        return self.chain(ti)


def demangle_simple(n: str) -> str:
    """'N2ad2fw8TaskBaseE' -> 'ad::fw::TaskBase' (nested names only; enough for class names)."""
    s = n
    if s.startswith("N") and s.endswith("E"):
        s = s[1:-1]
    parts, i = [], 0
    while i < len(s) and s[i].isdigit():
        j = i
        while j < len(s) and s[j].isdigit():
            j += 1
        ln = int(s[i:j])
        parts.append(s[j:j + ln])
        i = j + ln
    return "::".join(parts) if parts and i == len(s) else n


def find_tasks(rpc: Rpc, ranges, cros, syms, base_name: str = "N2ad2fw8TaskBaseE",
               all_classes: bool = False):
    """Scan word-aligned memory for objects whose vptr resolves (via RTTI) to a class that
    derives from ad::fw::TaskBase.  all_classes=True returns every RTTI-resolvable object."""
    import numpy as np

    img = Image(rpc, cros)
    rt = Rtti(img, syms)
    blk = sorted((lo, lo + len(d)) for lo, d, _ in img.blocks)
    los = np.array([b[0] for b in blk], dtype=np.uint64)
    his = np.array([b[1] for b in blk], dtype=np.uint64)
    verdict: dict[int, list[str] | None] = {}
    found = []
    for start, size in ranges:
        data = rpc.read(start, size)
        words = np.frombuffer(data[: len(data) // 4 * 4], dtype="<u4").astype(np.uint64)
        idx = np.searchsorted(los, words, side="right") - 1
        ok = (idx >= 0) & ((words & 3) == 0)
        ok &= words < his[np.clip(idx, 0, len(his) - 1)]
        for wi in np.nonzero(ok)[0]:
            vptr = int(words[wi])
            if vptr not in verdict:
                verdict[vptr] = rt.class_of_vptr(vptr)
            ch = verdict[vptr]
            if not ch or (not all_classes and base_name not in ch):
                continue
            off = int(wi) * 4
            obj = data[off:off + 0x50].ljust(0x50, b"\0")
            found.append({
                "addr": f"{start + off:#010x}",
                "vptr": f"{vptr:#010x}",
                "module": img.module_of(vptr),
                "class": demangle_simple(ch[0]),
                "bases": [demangle_simple(c) for c in ch[1:]],
                "b3c_48": obj[0x3C:0x49].hex(" "),
                "fps_mode": obj[0x45],
                "pattern_44": obj[0x44:0x48].hex(),
            })
    return found


# ------------------------------------------------------------------------------------
def main(argv=None) -> None:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--host", default="127.0.0.1")
    sub = ap.add_subparsers(dest="cmd", required=True)
    sub.add_parser("ps")
    p = sub.add_parser("read"); p.add_argument("addr", type=parse_int); p.add_argument("len", type=parse_int)
    p = sub.add_parser("dump"); p.add_argument("addr", type=parse_int); p.add_argument("len", type=parse_int); p.add_argument("file")
    p = sub.add_parser("write"); p.add_argument("addr", type=parse_int); p.add_argument("hex")
    p = sub.add_parser("find"); p.add_argument("hex"); p.add_argument("--range", action="append"); p.add_argument("--align", type=int, default=1); p.add_argument("--max", type=int, default=200)
    p = sub.add_parser("watch"); p.add_argument("addr", type=parse_int); p.add_argument("--fmt", default="I"); p.add_argument("--secs", type=float, default=2.0); p.add_argument("--hz", type=float, default=50.0)
    p = sub.add_parser("cros"); p.add_argument("--log", default=str(LOG_FILE))
    p = sub.add_parser("tasks"); p.add_argument("--range", action="append"); p.add_argument("--json")
    a = ap.parse_args(argv)

    rpc = Rpc(a.host)
    if a.cmd == "cros":
        for name, d in sorted(parse_cro_log(Path(a.log)).items(), key=lambda kv: kv[1]["base"]):
            print(f"{name:16s} base={d['base']:#010x} fixed_end={d['end']:#010x} "
                  f"loaded={d['loaded']} loads={d['events']}")
        return
    pid = rpc.select_game()
    if a.cmd == "ps":
        for p_, (tid, name) in sorted(rpc.process_list().items()):
            mark = "*" if p_ == pid else " "
            print(f"{mark} pid={p_:3d} tid={tid:016X} {name}")
    elif a.cmd == "read":
        print(hexdump(a.addr, rpc.read(a.addr, a.len)))
    elif a.cmd == "dump":
        Path(a.file).write_bytes(rpc.read(a.addr, a.len))
        print(f"wrote {a.len:#x} bytes from {a.addr:#010x} to {a.file}")
    elif a.cmd == "write":
        rpc.write(a.addr, bytes.fromhex(a.hex))
        print(hexdump(a.addr, rpc.read(a.addr, len(bytes.fromhex(a.hex)))))
    elif a.cmd == "find":
        pat = bytes.fromhex(a.hex)
        hits = 0
        for start, size in load_ranges(a.range):
            data = rpc.read(start, size)
            i = data.find(pat)
            while i >= 0 and hits < a.max:
                if (start + i) % a.align == 0:
                    print(f"{start + i:#010x}")
                    hits += 1
                i = data.find(pat, i + 1)
        print(f"{hits} hit(s)")
    elif a.cmd == "watch":
        sz = struct.calcsize("<" + a.fmt)
        t0 = time.perf_counter()
        v0 = struct.unpack("<" + a.fmt, rpc.read(a.addr, sz))[0]
        samples = [(0.0, v0)]
        while time.perf_counter() - t0 < a.secs:
            time.sleep(1.0 / a.hz)
            samples.append((time.perf_counter() - t0,
                            struct.unpack("<" + a.fmt, rpc.read(a.addr, sz))[0]))
        dt = samples[-1][0]
        dv = samples[-1][1] - v0
        changes = sum(1 for i in range(1, len(samples)) if samples[i][1] != samples[i - 1][1])
        print(f"{a.addr:#010x}: {v0} -> {samples[-1][1]} in {dt:.3f}s = {dv / dt:.2f}/s; "
              f"{changes} changes in {len(samples)} samples")
    elif a.cmd == "tasks":
        tasks = find_tasks(rpc, load_ranges(a.range), parse_cro_log(), load_symbols())
        for t in tasks:
            print(f"{t['addr']} vptr={t['vptr']} [{t['module']}] {t['class']}  "
                  f"+3C..+48={t['b3c_48']}  fps={t['fps_mode']}")
        print(f"{len(tasks)} TaskBase-derived object(s)")
        if a.json:
            Path(a.json).write_text(json.dumps(tasks, indent=1), encoding="utf-8")


if __name__ == "__main__":
    main()
