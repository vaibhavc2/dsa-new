#!/bin/bash

# Use the DSA_REPO_PATH environment variable
ROOT_DIR="$DSA_REPO_PATH"

# Navigate to the folder containing the source file
cd "$(dirname "$1")"

# Compile and execute
/usr/bin/g++ -fdiagnostics-color=always -g -pedantic -std=c++17 -DDEBUG -DLOCAL_PROJECT -O0 -fno-omit-frame-pointer -Wall -Wvla -Wextra -Wshadow -Wduplicated-cond -Wfloat-equal -Wconversion -Wformat=2 -Wlogical-op -Wduplicated-cond -Wshift-overflow=2 -Wcast-qual -Wcast-align -Wformat-signedness -fstack-protector-all -fsanitize=undefined,address,float-divide-by-zero,float-cast-overflow -fno-sanitize-recover=all "$1" -o a && ./a < "$ROOT_DIR/input.txt" > "$ROOT_DIR/output.txt"
