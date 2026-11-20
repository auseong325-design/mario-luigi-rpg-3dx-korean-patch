"""Run the existing checker read-only with hard timeout; no merge/build."""
import json,subprocess,sys
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3]
OUT=Path(__file__).resolve().parent
rows=json.loads((OUT/'ds_field_rows.json').read_text(encoding='utf-8'))
batches=sorted({r['batch'] for r in rows})
result=subprocess.run([sys.executable,'-X','utf8',str(ROOT/'scripts/merge_ko.py'),'--check',*batches],cwd=ROOT,capture_output=True,timeout=120)
(OUT/'main_speech_check.log').write_bytes(result.stdout+result.stderr)
summary={'batches':len(batches),'exit_code':result.returncode,'last_line':result.stdout.decode('utf-8',errors='replace').strip().splitlines()[-1]}
(OUT/'main_speech_check.json').write_text(json.dumps(summary,ensure_ascii=False,indent=2),encoding='utf-8')
print(json.dumps(summary,ensure_ascii=False))
sys.exit(result.returncode)
