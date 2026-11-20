from pathlib import Path
import subprocess
import sys
name, seconds, script, *args = sys.argv[1:]
path = Path(__file__).resolve().parent / (name + '.log')
try:
    result = subprocess.run([sys.executable, '-X', 'utf8', script, *args], capture_output=True, timeout=int(seconds))
except subprocess.TimeoutExpired as exc:
    path.write_bytes((exc.stdout or b'') + (exc.stderr or b'') + b'\nTIMEOUT\n')
    raise SystemExit(124)
path.write_bytes(result.stdout + result.stderr)
print(name, 'exit', result.returncode, str(path))
print((result.stdout + result.stderr).decode('utf-8', errors='replace')[-1400:])
raise SystemExit(result.returncode)
