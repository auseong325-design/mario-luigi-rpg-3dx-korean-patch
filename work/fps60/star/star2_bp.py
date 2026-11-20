"""STAR2: multi-breakpoint logger for Battle.cro AI op handlers (Azahar test instance, GDB stub 24689).

Every hit halts the game, records the battle frame counter and the AI context, hops over the BKPT
(temporary breakpoint on ADDR+4) and resumes.  Game logic is frame-based, so the halts do not change it.

  star2_bp.py run --secs S --out FILE.jsonl [--bp NAME=0x1105xxxx ...] [--max N]
      default breakpoints (analysis addresses, Battle.cro base 0x11000000):
        dmg  0x11058EC0  op0b9  btl::ChrPc::DoDamageML  (one per star group hit)
        est  0x1104C9D4  op1d8  btl::Main::entryEstimate (EXCELLENT / rank text)
        jmp  0x11029AE4  op12d..op135 MoveVBase::jump*  (fall start, bounce, ...)
  star2_bp.py summary FILE.jsonl [--base-from dmg]

Per hit (handler entry: r0 = AISys (GlobalEvent), r1 = LocalEvent-4, r2 = decoded command):
  ctr  = btl::Main+0x578 (frames)          clk = btl::Main+0x8A40 ($7013, 60-Hz units, float)
  pc   = [LocalEvent+0] (next instruction)  p3  = $3000..$3003 ([LocalEvent+0x30])
  v7085 = AISys+0x184 ($7085, stars caught)  op = cmd+0, ints = cmd+8.., floats = cmd+0x68..
Only reads memory and writes/removes BKPTs through the stub; never writes game data.
"""
from __future__ import annotations

import argparse
import json
import socket
import struct
import sys
import time
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT / "scripts" / "fps60"))
import rt_gdb  # noqa: E402
import rt_rpc  # noqa: E402

CRO_ANALYSIS_BASE = 0x11000000
DEFAULT_BPS = {"dmg": 0x11058EC0, "est": 0x1104C9D4, "jmp": 0x11029AE4}


def f32(b: bytes, off: int = 0) -> float:
    return struct.unpack_from("<f", b, off)[0]


def u32(b: bytes, off: int = 0) -> int:
    return struct.unpack_from("<I", b, off)[0]


def battle_base() -> int:
    rpc = rt_rpc.Rpc()
    rpc.select_game()
    rt_rpc.flush_log(rpc)
    cros = rt_rpc.parse_cro_log()
    d = cros.get("Battle")
    if not d or not d.get("loaded"):
        raise SystemExit(f"Battle.cro not loaded (log: {sorted(cros)})")
    return d["base"]


def run(a) -> None:
    base = a.base if a.base is not None else battle_base()
    bps = dict(DEFAULT_BPS)
    if a.only:
        bps = {k: v for k, v in bps.items() if k in a.only.split(",")}
    for spec in a.bp or []:
        n, v = spec.split("=")
        bps[n] = int(v, 0)
    rt = {n: base + (v - CRO_ANALYSIS_BASE) for n, v in bps.items()}
    by_addr = {v: n for n, v in rt.items()}
    out = open(a.out, "a", encoding="utf-8")
    out.write(json.dumps({"start": time.time(), "battle_base": base, "bps": {n: hex(v) for n, v in rt.items()}}) + "\n")
    out.flush()
    g = rt_gdb.Gdb(timeout=5.0)
    temp: dict[int, int] = {}          # temp addr -> parent addr
    n_hits = 0
    t0 = time.time()
    try:
        g.attach()
        for addr in rt.values():
            g.add_bp(addr)
        main_ptr = None
        g.cont()
        while time.time() - t0 < a.secs and n_hits < a.max:
            try:
                st = g.wait_stop(1.0)
            except socket.timeout:
                continue
            r = g.regs()
            pc = r["pc"]
            if pc in temp:
                parent = temp.pop(pc)
                g.del_bp(pc)
                g.add_bp(parent)
                g.cont()
                continue
            name = by_addr.get(pc)
            if name is None:
                out.write(json.dumps({"t": round(time.time() - t0, 3), "unexpected_stop": st.get("raw"),
                                      "pc": hex(pc)}) + "\n")
                out.flush()
                g.cont()
                continue
            n_hits += 1
            rec = {"t": round(time.time() - t0, 3), "bp": name}
            try:
                aisys, e = r["r0"], r["r1"] + 4
                if main_ptr is None:
                    main_ptr = u32(g.read(aisys + 0x18, 4))
                rec["ctr"] = u32(g.read(main_ptr + 0x578, 4))
                rec["clk"] = round(f32(g.read(main_ptr + 0x8A40, 4)), 2)
                le = g.read(e, 0x34)
                rec["pc"] = u32(le, 0)
                rec["wait"] = round(f32(le, 0x28), 2)
                p3 = u32(le, 0x30)
                if p3:
                    pv = g.read(p3, 16)
                    rec["p3"] = [round(f32(pv, 4 * i), 3) for i in range(4)]
                rec["v7085"] = round(f32(g.read(aisys + 0x184, 4)), 2)
                if a.work:   # AISys work variables $706c..$70ab (AISys+0x120 + 4*(id-0x706c))
                    wv = g.read(aisys + 0x120, 0x100)
                    rec["w"] = {f"{0x706c + i:04x}": round(f32(wv, 4 * i), 3) for i in range(0x40)
                                if f32(wv, 4 * i) != 0.0}
                cmd = g.read(r["r2"], 0x20)
                rec["op"] = hex(struct.unpack_from("<H", cmd, 0)[0])
                rec["ints"] = [hex(u32(cmd, 8 + 4 * i)) for i in range(6)]
                fl = g.read(r["r2"] + 0x68, 0x18)
                rec["fl"] = [round(f32(fl, 4 * i), 3) for i in range(6)]
            except Exception as ex:  # keep logging even if one read fails
                rec["err"] = repr(ex)
            out.write(json.dumps(rec) + "\n")
            out.flush()
            # hop over the BKPT: remove it, break on the next instruction, resume
            g.del_bp(pc)
            g.add_bp(pc + 4)
            temp[pc + 4] = pc
            g.cont()
    finally:
        try:
            g.interrupt(3.0)
        except Exception:
            pass
        for addr in list(rt.values()) + list(temp.keys()):
            try:
                g.del_bp(addr)
            except Exception:
                pass
        g.detach()
        g.close()
        out.write(json.dumps({"end": time.time(), "hits": n_hits}) + "\n")
        out.close()
    print(f"{a.out}: {n_hits} hits in {time.time() - t0:.1f} s")


def summary(a) -> None:
    rows = [json.loads(l) for l in open(a.file, encoding="utf-8") if l.strip()]
    hits = [r for r in rows if "bp" in r and "pc" in r]
    base = None
    for r in hits:
        if r["bp"] == "dmg":
            base = r["pc"] - 0x8119      # op0b9 at 0x810B, next instruction 0x8119
            break
    print(f"hits {len(hits)}, script base {hex(base) if base else None}")
    prev_clk = None
    for r in hits:
        off = r["pc"] - base if base is not None else r["pc"]
        d = "" if prev_clk is None else f" d={r['clk'] - prev_clk:7.1f}"
        print(f"t={r['t']:7.2f} ctr={r['ctr']:6d} clk={r['clk']:9.1f}{d} {r['bp']:4s} op={r['op']:6s} "
              f"next=0x{off:05x} p3={r.get('p3')} n={r.get('v7085')} ints={r['ints'][:3]} fl={r['fl'][:4]}")
        prev_clk = r["clk"]


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    p = sub.add_parser("run")
    p.add_argument("--secs", type=float, default=100.0)
    p.add_argument("--out", required=True)
    p.add_argument("--bp", action="append")
    p.add_argument("--max", type=int, default=100000)
    p.add_argument("--base", type=lambda s: int(s, 0), default=None)
    p.add_argument("--only", default=None, help="comma list of default breakpoints to keep (dmg,est,jmp)")
    p.add_argument("--work", action="store_true", help="also record the AISys work variables $706c..$70ab")
    p = sub.add_parser("summary")
    p.add_argument("file")
    a = ap.parse_args()
    {"run": run, "summary": summary}[a.cmd](a)


if __name__ == "__main__":
    main()
