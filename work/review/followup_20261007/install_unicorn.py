import subprocess
import sys
from pathlib import Path

target = Path(__file__).resolve().parent / 'deps'
result = subprocess.run([sys.executable, '-X', 'utf8', '-m', 'pip', 'install', '--target', str(target), 'unicorn==2.1.4'], capture_output=True, timeout=90)
print((result.stdout + result.stderr).decode('utf-8', errors='replace'))
raise SystemExit(result.returncode)
