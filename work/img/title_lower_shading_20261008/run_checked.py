"""Run a Python audit with a hard timeout and UTF-8 output."""
from pathlib import Path
import subprocess
import sys

name, seconds, script, *args = sys.argv[1:]
out = Path(__file__).resolve().parent / (name + '.log')
try:
    result = subprocess.run([sys.executable, '-X', 'utf8', script, *args],
                            capture_output=True, timeout=int(seconds))
except subprocess.TimeoutExpired as exc:
    out.write_bytes((exc.stdout or b'') + (exc.stderr or b'') + b'\nTIMEOUT\n')
    print(f'{name}: TIMEOUT ({seconds}s), {out}')
    sys.exit(124)
out.write_bytes(result.stdout + result.stderr)
print(f'{name}: exit={result.returncode}, log={out}')
print((result.stdout + result.stderr).decode('utf8', errors='replace')[-1600:])
sys.exit(result.returncode)
