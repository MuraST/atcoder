#!/bin/bash

ACL_PATH="/mnt/c/Users/takoy/vscode/ac-library"
LIBRARY_PATH="/mnt/c/Users/takoy/vscode/atcoder/library"
CODE_FILE="main.cpp"
OUTPUT_FILE="submit.cpp"

oj-bundle "$CODE_FILE" -I "$LIBRARY_PATH" | \
grep -v '^#line ' | \
grep -v '^#pragma once' | \
cat -s > "$OUTPUT_FILE"

g++ "$OUTPUT_FILE" -Wall -std=c++23 -I "$ACL_PATH"
oj t -c ./a.out -d ./test

read -p "Do you really want to submit? [y/N]: " input
if [ -z "$input" ]; then
    input="n"
fi
input=$(echo "$input" | tr '[:upper:]' '[:lower:]')
if [ "$input" = "y" ]; then
    acc submit "$OUTPUT_FILE" -- -y -w 0
fi