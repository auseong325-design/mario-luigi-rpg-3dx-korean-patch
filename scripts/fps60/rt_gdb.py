"""RT: minimal GDB Remote Serial Protocol client for Azahar's GDB stub (test instance, port 24689).

Azahar 2126.1.2 stub facts (src/core/gdbstub/gdbstub.cpp): the listener is polled from the core
loop (non-blocking accept, the game keeps running while nobody is connected); '?' in
non-extended mode attaches the launched application and HALTS all its threads until 'c';
'D' detaches (the game resumes, the stub listens again); 0x03 interrupts a running target;
's' (single step) is NOT supported; Z0/Z1 = software breakpoint (writes BKPT 0xE1200070),
Z2/Z3/Z4 = write/read/access watchpoints; 'm' replies E0E for unmapped addresses (no log spam,
used by `map`).  Memory writes via 'M' work everywhere the page table maps (including the
0x30000000 linear heap that the RPC server refuses to write).

CLI (one-shot commands attach, act, and by default resume the game with 'D'):
  rt_gdb.py regs                      halt, print r0-r15/cpsr of the main thread, resume
  rt_gdb.py read ADDR LEN             hexdump (game halted while reading)
  rt_gdb.py write ADDR HEX            write bytes (works on 0x30000000+)
  rt_gdb.py threads                   list threads + their PC/LR
  rt_gdb.py map [--out FILE]          probe mapped memory (64 KiB coarse, page-exact edges)
  rt_gdb.py bp ADDR [--count N] [--timeout S] [--thumb]
                                      break at ADDR, report N hits (regs + LR), then resume
  rt_gdb.py watchw ADDR LEN [--count N] [--timeout S]
                                      write watchpoint (JIT: approximate, see stub warning)
  rt_gdb.py wait [--timeout S]        attach, continue, wait for a stop (crash / exception)
Add --keep to stay halted (the next client's '?' re-attaches).
"""
from __future__ import annotations

import argparse
import json
import socket
import struct
import sys
import time
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
PORT = 24689
REG_NAMES = [f"r{i}" for i in range(13)] + ["sp", "lr", "pc"]
SIGNALS = {0: "none", 2: "SIGINT", 5: "SIGTRAP", 11: "SIGSEGV", 15: "SIGTERM"}


def parse_int(s: str) -> int:
    return int(s, 0)


class GdbError(RuntimeError):
    pass


class Gdb:
    def __init__(self, host: str = "127.0.0.1", port: int = PORT, timeout: float = 5.0):
        self.sock = socket.create_connection((host, port), timeout=timeout)
        self.sock.setsockopt(socket.IPPROTO_TCP, socket.TCP_NODELAY, 1)
        self.buf = b""
        self.attached = False
        self.stop: dict | None = None

    # -- framing -----------------------------------------------------------------
    @staticmethod
    def _frame(payload: str) -> bytes:
        b = payload.encode("latin-1")
        return b"$" + b + b"#" + f"{sum(b) & 0xFF:02x}".encode()

    def _recv_more(self, timeout: float | None) -> None:
        self.sock.settimeout(timeout)
        chunk = self.sock.recv(65536)
        if not chunk:
            raise GdbError("stub closed the connection")
        self.buf += chunk

    def _read_packet(self, timeout: float | None = 5.0) -> str:
        deadline = None if timeout is None else time.monotonic() + timeout
        while True:
            while self.buf[:1] in (b"+", b"-"):
                self.buf = self.buf[1:]
            start = self.buf.find(b"$")
            if start >= 0:
                end = self.buf.find(b"#", start)
                if end >= 0 and len(self.buf) >= end + 3:
                    body = self.buf[start + 1:end]
                    cs = int(self.buf[end + 1:end + 3], 16)
                    self.buf = self.buf[end + 3:]
                    if sum(body) & 0xFF != cs:
                        self.sock.sendall(b"-")
                        continue
                    self.sock.sendall(b"+")
                    return body.decode("latin-1")
            left = None if deadline is None else max(0.0, deadline - time.monotonic())
            if left == 0.0:
                raise socket.timeout("no packet from stub")
            self._recv_more(left)

    def cmd(self, payload: str, timeout: float | None = 5.0) -> str:
        self.sock.sendall(self._frame(payload))
        return self._read_packet(timeout)

    def send_nowait(self, payload: str) -> None:
        self.sock.sendall(self._frame(payload))

    # -- session ---------------------------------------------------------------------
    def attach(self) -> dict:
        """'?' (non-extended mode): selects the launched title and halts it."""
        self.stop = self.parse_stop(self.cmd("?"))
        self.attached = True
        return self.stop

    def detach(self) -> None:
        """Resume the game and drop the connection.  In 2126.1.2 'D' runs ToggleServer(false)
        (which resets current_process) BEFORE Continue(), so the game can stay halted; instead
        send 'c' and close the socket: the stub sees recv()==0 and re-listens."""
        try:
            self.send_nowait("c")
            time.sleep(0.05)
        except OSError:
            pass
        self.attached = False

    def close(self) -> None:
        try:
            self.sock.close()
        except OSError:
            pass

    def cont(self) -> None:
        self.send_nowait("c")

    def interrupt(self, timeout: float = 5.0) -> dict:
        self.sock.sendall(b"\x03")
        self.stop = self.parse_stop(self._read_packet(timeout))
        return self.stop

    def wait_stop(self, timeout: float | None) -> dict:
        self.stop = self.parse_stop(self._read_packet(timeout))
        return self.stop

    @staticmethod
    def parse_stop(pkt: str) -> dict:
        d: dict = {"raw": pkt}
        if pkt.startswith("T") and len(pkt) >= 3:
            sig = int(pkt[1:3], 16)
            d["signal"] = sig
            d["signame"] = SIGNALS.get(sig, f"sig{sig}")
            for kv in pkt[3:].split(";"):
                if ":" not in kv:
                    continue
                k, v = kv.split(":", 1)
                if k == "thread":
                    d["thread"] = int(v, 16)
                elif all(c in "0123456789abcdefABCDEF" for c in k) and len(v) == 8:
                    reg = int(k, 16)
                    val = struct.unpack("<I", bytes.fromhex(v))[0]
                    d[{13: "sp", 14: "lr", 15: "pc"}.get(reg, f"r{reg}")] = val
                else:
                    d[k] = v
        elif pkt.startswith(("W", "X")):
            d["exited"] = pkt
        elif pkt.startswith("S"):
            d["signal"] = int(pkt[1:3], 16)
        return d

    # -- memory / registers --------------------------------------------------------
    def read(self, addr: int, size: int, chunk: int = 2048) -> bytes:
        out = bytearray()
        while size > 0:
            n = min(size, chunk)
            r = self.cmd(f"m{addr:x},{n:x}")
            if r.startswith("E") or len(r) != 2 * n:
                raise GdbError(f"read {addr:#x}+{n:#x}: {r[:16]!r} (unmapped?)")
            out += bytes.fromhex(r)
            addr += n
            size -= n
        return bytes(out)

    def is_mapped(self, addr: int) -> bool:
        # RT2: 2126.1.2 answers 'm' on an unmapped page with an EMPTY packet (not E0E).
        r = self.cmd(f"m{addr:x},1")
        return len(r) == 2 and not r.startswith("E")

    def write(self, addr: int, data: bytes, chunk: int = 2048) -> None:
        for off in range(0, len(data), chunk):
            c = data[off:off + chunk]
            r = self.cmd(f"M{addr + off:x},{len(c):x}:{c.hex()}")
            if r != "OK":
                raise GdbError(f"write {addr + off:#x}: {r}")

    def regs(self) -> dict[str, int]:
        r = self.cmd("g")
        if r.startswith("E"):
            raise GdbError(f"g: {r}")
        vals = [struct.unpack("<I", bytes.fromhex(r[i * 8:i * 8 + 8]))[0] for i in range(17)]
        d = dict(zip(REG_NAMES, vals[:16]))
        d["cpsr"] = vals[16]
        return d

    def set_reg(self, n: int, val: int) -> None:
        r = self.cmd(f"P{n:x}={struct.pack('<I', val).hex()}")
        if r != "OK":
            raise GdbError(f"P{n}: {r}")

    def threads(self) -> list[int]:
        r = self.cmd("qfThreadInfo")
        if not r.startswith("m"):
            return []
        return [int(x, 16) for x in r[1:].split(",") if x]

    def select_thread(self, tid: int) -> None:
        r = self.cmd(f"Hg{tid:x}")
        if r != "OK":
            raise GdbError(f"Hg{tid:x}: {r}")

    def add_bp(self, addr: int, kind: int = 0, length: int = 4) -> None:
        r = self.cmd(f"Z{kind},{addr:x},{length:x}")
        if r != "OK":
            raise GdbError(f"Z{kind} {addr:#x}: {r!r}")

    def del_bp(self, addr: int, kind: int = 0, length: int = 4) -> None:
        self.cmd(f"z{kind},{addr:x},{length:x}")


# ------------------------------------------------------------------------------------
PROBE_REGIONS = [  # (name, start, end) searched for mapped pages
    ("image", 0x00100000, 0x04000000),
    ("heap", 0x08000000, 0x10000000),
    ("shared", 0x10000000, 0x14000000),
    ("linear_old", 0x14000000, 0x1C000000),
    ("n3ds_extra", 0x1E800000, 0x1EC00000),
    ("cfg_shared_tls", 0x1FF80000, 0x1FFC0000),
    ("linear", 0x30000000, 0x40000000),
]


def probe_map(g: Gdb, coarse: int = 0x100000) -> list[dict]:
    """Return mapped [start, end) runs (page-exact edges).

    RT2: one GDB round trip costs ~10-15 ms in 2126.1.2 (the stub is polled from the core loop),
    so the old 64 KiB sweep (~10k probes) took > 120 s.  Now: probe every `coarse` bytes (small
    regions page by page) and binary-search each mapped/unmapped edge to the 4 KiB page.  A hole or
    an island smaller than `coarse` between two probes with the same state is not seen."""
    runs = []
    for name, lo, hi in PROBE_REGIONS:
        step = 0x1000 if hi - lo <= 0x100000 else coarse

        def edge(a: int, b: int, a_mapped: bool) -> int:
            """First page in (a, b] whose state differs from a's (a, b page aligned)."""
            while b - a > 0x1000:
                mid = ((a + b) // 2) & ~0xFFF
                if mid <= a:
                    mid = a + 0x1000
                if g.is_mapped(mid) == a_mapped:
                    a = mid
                else:
                    b = mid
            return b

        a = lo
        prev = g.is_mapped(lo)
        run_start = lo if prev else None
        while a + step < hi:
            b = a + step
            m = g.is_mapped(b)
            if m != prev:
                e = edge(a, b, prev)
                if m:
                    run_start = e
                else:
                    runs.append({"region": name, "start": run_start, "end": e})
                    run_start = None
            prev = m
            a = b
        if prev and run_start is not None:
            last = hi - 0x1000
            if a < last and not g.is_mapped(last):
                runs.append({"region": name, "start": run_start, "end": edge(a, last, True)})
            else:
                runs.append({"region": name, "start": run_start, "end": hi})
    return runs


def hexdump(addr: int, data: bytes) -> str:
    out = []
    for i in range(0, len(data), 16):
        row = data[i:i + 16]
        out.append(f"{addr + i:08x}  " + " ".join(f"{b:02x}" for b in row).ljust(48)
                   + "  " + "".join(chr(b) if 32 <= b < 127 else "." for b in row))
    return "\n".join(out)


def fmt_regs(r: dict[str, int]) -> str:
    keys = REG_NAMES + ["cpsr"]
    return "  ".join(f"{k}={r[k]:08x}" for k in keys if k in r)


def main(argv=None) -> None:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--host", default="127.0.0.1")
    ap.add_argument("--port", type=int, default=PORT)
    ap.add_argument("--keep", action="store_true", help="leave the game halted (no detach)")
    sub = ap.add_subparsers(dest="cmd", required=True)
    sub.add_parser("regs")
    sub.add_parser("threads")
    p = sub.add_parser("read"); p.add_argument("addr", type=parse_int); p.add_argument("len", type=parse_int)
    p = sub.add_parser("write"); p.add_argument("addr", type=parse_int); p.add_argument("hex")
    p = sub.add_parser("map"); p.add_argument("--out"); p.add_argument("--coarse", type=parse_int, default=0x100000)
    p = sub.add_parser("bp"); p.add_argument("addr", type=parse_int); p.add_argument("--count", type=int, default=1)
    p.add_argument("--timeout", type=float, default=30.0); p.add_argument("--thumb", action="store_true")
    p.add_argument("--mem", action="append", default=[], help="ADDR:LEN or rN:LEN to dump at each hit")
    p = sub.add_parser("watchw"); p.add_argument("addr", type=parse_int); p.add_argument("len", type=parse_int)
    p.add_argument("--count", type=int, default=1); p.add_argument("--timeout", type=float, default=30.0)
    p = sub.add_parser("wait"); p.add_argument("--timeout", type=float, default=600.0)
    a = ap.parse_args(argv)

    g = Gdb(a.host, a.port)
    try:
        st = g.attach()
        if a.cmd == "regs":
            print("stop:", st.get("raw"))
            print(fmt_regs(g.regs()))
        elif a.cmd == "threads":
            for t in g.threads():
                g.select_thread(t)
                r = g.regs()
                print(f"thread {t:#x}: pc={r['pc']:08x} lr={r['lr']:08x} sp={r['sp']:08x} cpsr={r['cpsr']:08x}")
        elif a.cmd == "read":
            print(hexdump(a.addr, g.read(a.addr, a.len)))
        elif a.cmd == "write":
            data = bytes.fromhex(a.hex)
            g.write(a.addr, data)
            print(hexdump(a.addr, g.read(a.addr, len(data))))
        elif a.cmd == "map":
            t0 = time.perf_counter()
            runs = probe_map(g, a.coarse)
            for r in runs:
                print(f"{r['region']:15s} {r['start']:#010x}-{r['end']:#010x} ({(r['end'] - r['start']) >> 10} KiB)")
            print(f"probed in {time.perf_counter() - t0:.1f}s")
            if a.out:
                Path(a.out).write_text(json.dumps({
                    "probed_at": time.strftime("%Y-%m-%d %H:%M:%S"),
                    "runs": [{**r, "start": f"{r['start']:#010x}", "end": f"{r['end']:#010x}"} for r in runs],
                    "data_ranges": [{"start": f"{r['start']:#010x}", "size": f"{r['end'] - r['start']:#x}"}
                                    for r in runs if r["region"] in ("heap", "linear", "linear_old")],
                }, indent=1), encoding="utf-8")
                print("wrote", a.out)
        elif a.cmd in ("bp", "watchw"):
            kind = 0 if a.cmd == "bp" else 2
            ln = (2 if a.thumb else 4) if a.cmd == "bp" else a.len
            g.add_bp(a.addr, kind, ln)
            try:
                for i in range(a.count):
                    g.cont()
                    st = g.wait_stop(a.timeout)
                    r = g.regs()
                    print(f"hit {i + 1}: {st.get('signame')} thread={st.get('thread')} {fmt_regs(r)}"
                          + (f" watch={st.get('watch')}" if "watch" in st else ""))
                    for spec in a.mem:
                        where, ln2 = spec.split(":")
                        base = r[where] if where in r else parse_int(where)
                        print(hexdump(base, g.read(base, parse_int(ln2))))
                    if kind == 0 and i + 1 < a.count:
                        # The stub has no single-step: hop over the BKPT with a temporary
                        # breakpoint on the next instruction (ADDR must not be a branch).
                        g.del_bp(a.addr, 0, ln)
                        g.add_bp(a.addr + ln, 0, ln)
                        g.cont()
                        g.wait_stop(a.timeout)
                        g.del_bp(a.addr + ln, 0, ln)
                        g.add_bp(a.addr, 0, ln)
            except socket.timeout:
                print(f"no hit within {a.timeout}s; interrupting")
                g.interrupt()
            finally:
                g.del_bp(a.addr, kind, ln)
        elif a.cmd == "wait":
            g.cont()
            try:
                st = g.wait_stop(a.timeout)
                print("STOP:", st)
                if st.get("signal") not in (None, 0):
                    print(fmt_regs(g.regs()))
            except socket.timeout:
                print(f"no stop within {a.timeout}s")
                g.interrupt()
    finally:
        if not a.keep:
            g.detach()
        g.close()


if __name__ == "__main__":
    main()
