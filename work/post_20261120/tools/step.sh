#!/usr/bin/env bash
# step.sh NAME [wait_ms] KEY...   press keys on the test Azahar, wait, then grab NAME (top/bottom split).
# NAME '-' = no capture.
set -e
cd /c/AI-Projects/mario-luigi-rpg-3dx-korean-patch
name="$1"; shift
wait_ms="${1:-1500}"; shift || true
if [ "$#" -gt 0 ]; then timeout 120 python -X utf8 scripts/fps60/rt_input.py keys "$@" > /dev/null; fi
python -c "import time; time.sleep($wait_ms/1000)"
if [ "$name" != "-" ]; then timeout 60 python -X utf8 work/post_20261120/tools/grab.py "work/post_20261120/raw/${name}.png" --split; fi
