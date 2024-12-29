#!/bin/bash

ACL_PATH="/mnt/c/Users/takoy/vscode/ac-library"
LIBRARY_PATH="/mnt/c/Users/takoy/vscode/atcoder/library"
SUBMIT_PATH="/mnt/c/Users/takoy/vscode/atcoder/config/acs.sh"
CODE_FILE="main.cpp"

g++ "$CODE_FILE" -Wall -std=c++23 -I "$ACL_PATH" -I "$LIBRARY_PATH"
oj t -c ./a.out -d ./test

read -p "Do you want to submit? [y/N]: " input
if [ -z "$input" ]; then
    input="n"
fi
input=$(echo "$input" | tr '[:upper:]' '[:lower:]')
if [ "$input" = "y" ]; then
    "$SUBMIT_PATH"
fi