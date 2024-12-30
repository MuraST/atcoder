#!/bin/bash

LIBRARY_PATH="/mnt/c/Users/takoy/vscode/atcoder/library"
TMP_FILE="main.bundle.cpp"
if [ -z "$1" ]; then
  CODE_FILE="main.cpp"
else
  CODE_FILE="$1"
fi

oj-bundle "$CODE_FILE" -I "$LIBRARY_PATH" | \
grep -v '^#line ' | \
grep -v '^#pragma once' | \
cat -s > "$TMP_FILE"
cat -s "$TMP_FILE" > "$CODE_FILE"
rm "$TMP_FILE"