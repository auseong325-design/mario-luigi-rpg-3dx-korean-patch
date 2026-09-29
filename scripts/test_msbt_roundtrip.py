"""Round-trip every 3DX MSBT (v1.2 view): decode -> encode must reproduce the original bytes.

Run: .venv\\Scripts\\python scripts\\test_msbt_roundtrip.py
A faulthandler watchdog aborts after 120 s so a parser bug can never hang the session.
"""

import collections
import faulthandler
import sys
import time

from lib3dx import iter_all_msbt, read_msbt, write_msbt

faulthandler.dump_traceback_later(120, exit=True)


def main() -> int:
    stats: collections.Counter[str] = collections.Counter()
    problems: list[str] = []
    messages = 0
    t0 = time.time()
    for key, data in iter_all_msbt():
        try:
            doc = read_msbt(data)
        except Exception as exc:  # noqa: BLE001 - report every failure
            stats["decode_error"] += 1
            problems.append(f"{key}: decode {type(exc).__name__}: {exc}")
            continue
        messages += len(doc.messages)
        out = write_msbt(doc)
        if out == data:
            stats["exact"] += 1
        else:
            stats["differs"] += 1
            first = next((i for i in range(min(len(out), len(data))) if out[i] != data[i]), min(len(out), len(data)))
            problems.append(f"{key}: bytes differ (len {len(data)} -> {len(out)}, first diff @0x{first:X})")
    print(dict(stats), f"messages={messages}", f"{time.time() - t0:.1f}s")
    for p in problems[:15]:
        print("  ", p)
    return 0 if not problems else 1


if __name__ == "__main__":
    sys.exit(main())
