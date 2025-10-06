#!/bin/bash

PROGRAM=./converter
INPUT_DIR="inputs"
EXPECTED_DIR="expected"
OUTPUT_DIR="output"

mkdir -p "$OUTPUT_DIR"

if [[ ! -x "$PROGRAM" ]]; then
    echo "Compiling..."
    make
fi

echo "Running tests..."

for infile in "$INPUT_DIR"/*; do
    base=$(basename "$infile")
    outfile="$OUTPUT_DIR/$base.out"
    expected="$EXPECTED_DIR/$base.out"

    echo -n "Test $base ... "

    # Read the input file into a variable
    input=$(<"$infile")

    # Run program with input as argument
    if ! "$PROGRAM" "$input" > "$outfile" 2>&1; then
        echo "X Runtime error"
        continue
    fi

    # Compare to expected output if it exists
    if [[ -f "$expected" ]]; then
        if diff -q "$outfile" "$expected" >/dev/null; then
            echo "✅ Passed"
        else
            echo "❌ Failed (output differs)"
            diff -u "$expected" "$outfile" || true
        fi
    else
        echo "⚠️ No expected output to compare"
    fi
done
