"""STAR2: classify star2_bp.py logs of the ?ㅽ?&?ㅽ? demonstration (atk_pc_sp_ml_star.bai).

  star2_ana.py FILE.jsonl [--timeline]

Events (script offsets = next instruction after the op, from atk_pc_sp_ml_star.dis.txt):
  se 0x1301a2 throw (0x7192, in 0x70D5)      se 0x1301a6 catch (0x6982/0x6d8d)   se 0x1301a7 miss (0x6a49/0x6e54)
  se 0x13019c stock hop lands (0x2d92/0x2e3f) se 0x13019d/e hand reload start/end (0x31c7/0x321b)
  jmp next 0x2d77/0x2e24 pile->stock hops    jmp next 0x31b3 stock->hand          jmp next 0x88bc drop-group fall
  jmp next 0x865e bounce                      dmg = group hit (op0b9)              est = EXCELLENT (op1d8)
Clock = btl::Main+0x8A40 ($7013, 60-Hz units) so 30 and 60fps runs compare directly.
"""
from __future__ import annotations

import json
import sys
from collections import Counter, defaultdict

SE = {0x1301A2: "throw", 0x1301A6: "catch", 0x1301A7: "miss", 0x13019C: "hop_land", 0x13019D: "reload_go",
      0x13019E: "reload_done", 0x1301A9: "drop_big", 0x1301AB: "drop_grp", 0x1301AD: "drop_one"}
JMP = {0x2D77: "hop1", 0x2E24: "hop2", 0x31B3: "to_hand", 0x319D: "to_hand", 0x88BC: "fall", 0x865E: "bounce", 0x6795: "miss_bounce",
       0x7673: "bro_jump1", 0x782B: "bro_jump2"}


def load(path):
    rows = [json.loads(l) for l in open(path, encoding="utf-8") if l.strip()]
    hits = [r for r in rows if "bp" in r and "pc" in r and "clk" in r]
    base = None
    for r in hits:
        if r["bp"] == "dmg":
            base = r["pc"] - 0x8119
            break
    if base is None:  # fall back to a drop fall (op12f at 0x88A9, next 0x88BC)
        for r in hits:
            if r["bp"] == "jmp" and r.get("op") == "0x12f" and r.get("fl", [0, 0, 0])[2] == -526.0:
                base = r["pc"] - 0x88BC
                break
    ev = []
    for r in hits:
        off = r["pc"] - base if base is not None else None
        kind = r["bp"]
        if kind == "se":
            sid = int(r["ints"][0], 16)
            kind = SE.get(sid, f"se_{sid:x}")
        elif kind == "jmp":
            kind = JMP.get(off, f"jmp_{off:x}" if off is not None else "jmp")
        ev.append({"clk": r["clk"], "ctr": r["ctr"], "kind": kind, "off": off, "obj": r["ints"][0],
                   "p3": r.get("p3"), "n": r.get("v7085"), "t": r["t"]})
    return base, ev


def main():
    path = sys.argv[1]
    base, ev = load(path)
    print(f"{path}: {len(ev)} events, script base {hex(base) if base else None}")
    # split into cycles at each EXCELLENT
    cyc, cur = [], []
    for e in ev:
        cur.append(e)
        if e["kind"] == "est":
            cyc.append(cur)
            cur = []
    if cur:
        cyc.append(cur)
    for i, c in enumerate(cyc):
        cnt = Counter(e["kind"] for e in c)
        throws = [e for e in c if e["kind"] == "throw"]
        catches = [e for e in c if e["kind"] == "catch"]
        dmg = [e for e in c if e["kind"] == "dmg"]
        est = [e for e in c if e["kind"] == "est"]
        print(f"\n== part {i}: clk {c[0]['clk']:.0f}..{c[-1]['clk']:.0f}  counts {dict(cnt)}")
        if throws:
            t0, t1 = throws[0]["clk"], throws[-1]["clk"]
            gaps = [round(b["clk"] - a["clk"], 1) for a, b in zip(throws, throws[1:])]
            print(f"  throws {len(throws)}: first {t0:.0f} last {t1:.0f} span {t1 - t0:.0f} units; gaps {Counter(gaps).most_common(8)}")
            byobj = defaultdict(list)
            for e in throws:
                byobj[e["obj"]].append(e["clk"])
            for o, ts in sorted(byobj.items()):
                g = [round(b - a, 1) for a, b in zip(ts, ts[1:])]
                print(f"    thrower {o}: {len(ts)} throws, gaps {Counter(g).most_common(6)}")
        if catches:
            print(f"  catches {len(catches)}: n at last catch {catches[-1]['n']}")
        if dmg:
            hs = [e["clk"] for e in dmg]
            print(f"  hits {len(hs)}: first {hs[0]:.0f} last {hs[-1]:.0f} -> {hs[-1] - hs[0]:.0f} units; gaps "
                  f"{[round(b - a) for a, b in zip(hs, hs[1:])]}; n={dmg[0]['n']}")
        if est and dmg:
            print(f"  EXCELLENT at {est[0]['clk']:.0f} = first hit + {est[0]['clk'] - dmg[0]['clk']:.0f} units")
        falls = [e for e in c if e["kind"] == "fall"]
        if falls and dmg:
            print(f"  fall starts {[round(e['clk'] - falls[0]['clk']) for e in falls]} (rel.), first hit - first fall "
                  f"= {dmg[0]['clk'] - falls[0]['clk']:.0f}")
    if "--timeline" in sys.argv:
        for e in ev:
            print(f"{e['clk']:9.1f} {e['ctr']:7d} {e['kind']:12s} obj={e['obj']} p3={e['p3']} n={e['n']} off={hex(e['off']) if e['off'] is not None else None}")


if __name__ == "__main__":
    main()
