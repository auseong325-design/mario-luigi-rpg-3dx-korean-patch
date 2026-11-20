"""BTL2: find frame-rate-dependent timing in the battle AI scripts (romfs BAI/BAI.dat).

    python scripts/fps60/btl_timing.py counters [--out file.tsv] [name-substr ...]
    python scripts/fps60/btl_timing.py waits    [--out file.tsv]

Timing model (battle.md 1.4 + BTL2 section 2.4, confirmed in code):
  * the AI VM runs once per presented frame; `wait(n)` stores n (float) and every exec subtracts
    AISys+0x14 = whole 60 Hz ticks of this frame (2 at 30fps, 1 at 60fps); the remainder is dropped.
    => wait(1) yields exactly one frame at both rates (33.3 ms at 30fps, 16.7 ms at 60fps);
       wait(2k) is k*33.3 ms at both rates; wait(2k+1) is (k+1)*33.3 ms at 30fps, (2k+1)*16.7 ms at 60fps.
  * `$7012` = this frame's step in 60 Hz units (2.0 at 30fps, 1.0 at 60fps, x battle time scale).

`counters`: every loop (backward branch) whose *direct* body (not counting nested loops) contains a
`wait(1)` and updates a variable by a constant (op023 ++, op024 --, op025/op026 +=/-= imm,
op016/op017 v = v +/- imm). Such a counter advances once per frame, i.e. twice as fast in ms at 60fps,
unless the increment is scaled by $7012 (reported as step). For each counter: the constants it is
compared with (op003) anywhere in the script, whether the loop reads buttons, and the loop range.

`waits`: histogram of wait immediates per script family (odd waits are 16.7 ms shorter at 60fps).
Read-only.
"""
from __future__ import annotations

import os
import struct
import sys
from collections import Counter, defaultdict

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import btl_bai  # noqa: E402

INPUT = {0x7005: "hold", 0x7006: "trg", 0x7007: "rls", 0x7008: "rep", 0x7009: "rawhold", 0x700A: "rawtrg"}
STEP = 0x7012


def var_params(ins):
    return [v for t, v in ins[4] if t == "var"]


def counter_update(ins):
    """(var, delta) if ins advances a variable by a constant, else None."""
    pos, op, mask, res, params = ins
    if res is None:
        return None
    if op == 0x23:
        return res, 1.0
    if op == 0x24:
        return res, -1.0
    if op in (0x25, 0x26) and params and params[0][0] != "var":
        d = float(params[0][1])
        return res, d if op == 0x25 else -d
    if op in (0x16, 0x17) and len(params) == 2:
        (t0, v0), (t1, v1) = params
        if op == 0x16:
            if t0 == "var" and v0 == res and t1 != "var":
                return res, float(v1)
            if t1 == "var" and v1 == res and t0 != "var":
                return res, float(v0)
        if op == 0x17 and t0 == "var" and v0 == res and t1 != "var":
            return res, -float(v1)
    return None


def step_update(ins, stepvars):
    """var if ins advances a variable by a step-derived amount."""
    pos, op, mask, res, params = ins
    if res is None:
        return None
    vs = var_params(ins)
    if op in (0x25, 0x26) and vs and vs[0] in stepvars:
        return res
    if op in (0x16, 0x17) and res in vs and any(v in stepvars for v in vs if v != res):
        return res
    return None


def loops_of(ins):
    out = []
    for i in ins:
        op, params = i[1], i[4]
        t = None
        if op == 0x04 and btl_bai.imm(params, 0) in (0, 2):
            t = btl_bai.imm(params, 1)
        elif op == 0x03:
            t = btl_bai.imm(params, 4)
        if t is not None and t < i[0]:
            out.append((t, i[0]))
    return sorted(set(out), key=lambda r: r[1] - r[0])


def scan_counters(name, buf, dt):
    ins, _ = btl_bai.decode_all(buf, dt)
    order = [i[0] for i in ins]
    by = {i[0]: i for i in ins}
    lps = loops_of(ins)
    # compares: var -> set of constants
    cmps = defaultdict(set)
    for i in ins:
        if i[1] == 0x03 and len(i[4]) >= 3:
            (ta, a), (tb, b) = i[4][1], i[4][2]
            if ta == "var" and tb != "var":
                cmps[a].add(b)
            if tb == "var" and ta != "var":
                cmps[b].add(a)
    # step-derived vars: assigned from an expression that reads $7012 (or another step var)
    stepvars = {STEP}
    changed = True
    while changed:
        changed = False
        for i in ins:
            if i[3] is not None and i[3] not in stepvars and any(v in stepvars for v in var_params(i)) \
                    and i[1] in (0x15, 0x16, 0x17, 0x18, 0x19):
                stepvars.add(i[3])
                changed = True
    rows = []
    for (t, e) in lps:
        inner = [(a, b) for (a, b) in lps if t <= a and b <= e and (a, b) != (t, e)]
        body = [by[p] for p in order if t <= p <= e and not any(a <= p <= b for a, b in inner)]
        waits = [btl_bai.imm(b[4], 0) for b in body if b[1] == 0x05]
        if 1 not in waits:
            continue
        inputs = sorted({INPUT[v] for b in body for v in var_params(b) if v in INPUT})
        stepped = {step_update(b, stepvars) for b in body} - {None}
        # forward branches inside the loop (p -> q with t <= p < q <= e) make the code between conditional
        fwd = []
        for b in body:
            q = None
            if b[1] == 0x03:
                q = btl_bai.imm(b[4], 4)
            elif b[1] == 0x04 and btl_bai.imm(b[4], 0) in (0, 2):
                q = btl_bai.imm(b[4], 1)
            if q is not None and b[0] < q <= e:
                fwd.append((b[0], q))
        for b in body:
            cu = counter_update(b)
            if cu is None:
                continue
            v, d = cu
            if v in stepvars:
                continue
            cond = any(p < b[0] < q for p, q in fwd)
            incmp = sorted({(x[4][1][1] if x[4][2][0] == "var" and x[4][2][1] == v else x[4][2][1])
                            for x in body if x[1] == 0x03 and len(x[4]) >= 3 and
                            any(tt == "var" and vv == v for tt, vv in x[4][1:3])},
                           key=lambda z: (isinstance(z, str), z))
            kind = "angle" if 360 in cmps.get(v, ()) and abs(d) not in (1.0, 2.0) else \
                   ("step2" if abs(d) == 2.0 else ("count" if abs(d) == 1.0 else "rate"))
            rows.append({
                "script": name, "loop": f"{t:05x}-{e:05x}", "at": f"{b[0]:05x}",
                "var": f"${v:04x}", "delta": f"{d:g}", "waits": ",".join(str(w) for w in waits),
                "input": ",".join(inputs), "cmp": ",".join(f"{c:g}" for c in sorted(cmps.get(v, ()))),
                "step_in_loop": "yes" if stepped else "", "uncond": "" if cond else "yes",
                "cmp_in_loop": ",".join(str(z) if not isinstance(z, float) else f"{z:g}" for z in incmp),
                "kind": kind, "ins": btl_bai.fmt(b).split(": ", 1)[1],
            })
    return rows


def main(argv):
    if not argv:
        print(__doc__)
        return
    out = None
    if "--out" in argv:
        k = argv.index("--out")
        out = argv[k + 1]
        argv = argv[:k] + argv[k + 2:]
    dt = btl_bai.descs()
    files = btl_bai.load()
    cmd, only = argv[0], argv[1:]
    lines = []
    if cmd == "counters":
        cols = ["script", "loop", "at", "var", "delta", "kind", "uncond", "cmp_in_loop", "waits", "input",
                "cmp", "step_in_loop", "ins"]
        lines.append("\t".join(cols))
        for k in sorted(files):
            if only and not any(o in k for o in only):
                continue
            for r in scan_counters(k, files[k], dt):
                lines.append("\t".join(r[c] for c in cols))
    elif cmd == "waits":
        fam = defaultdict(Counter)
        for k in sorted(files):
            f = k.split("_")[0] if not k.startswith("atk_pc") else "atk_pc"
            ins, _ = btl_bai.decode_all(files[k], dt)
            for i in ins:
                if i[1] == 0x05:
                    w = btl_bai.imm(i[4], 0)
                    fam[f]["var" if w is None else ("odd" if w % 2 else "even")] += 1
                    if w is not None and w % 2:
                        fam[f][f"w{w}"] += 1
        lines.append("family\teven\todd\tvar\todd_values")
        for f, c in sorted(fam.items()):
            odd = ",".join(f"{k[1:]}x{v}" for k, v in sorted(c.items(), key=lambda kv: -kv[1]) if k.startswith("w"))
            lines.append(f"{f}\t{c['even']}\t{c['odd']}\t{c['var']}\t{odd}")
    else:
        print(__doc__)
        return
    text = "\n".join(lines) + "\n"
    if out:
        with open(out, "w", encoding="utf-8", newline="\n") as fh:
            fh.write(text)
        print(f"wrote {out}: {len(lines) - 1} rows")
    else:
        sys.stdout.write(text)


if __name__ == "__main__":
    main(sys.argv[1:])
