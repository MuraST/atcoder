#!/bin/bash

LIBRARY_PATH="/mnt/c/Users/takoy/vscode/atcoder/library"
CODE_FILE="main.cpp"
OUTPUT_FILE="main.bundle.cpp"

oj-bundle "$CODE_FILE" -I "$LIBRARY_PATH" | \
grep -v '^#line ' | \
grep -v '^#pragma once' | \
cat -s > "$OUTPUT_FILE"
cat -s "$OUTPUT_FILE" > "$CODE_FILE"
rm "$OUTPUT_FILE"