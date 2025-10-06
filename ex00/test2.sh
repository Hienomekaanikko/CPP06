#!/bin/bash

PROGRAM="./converter"
OUTPUT_DIR="output"
INPUT_DIR="input"
EXPECTED_DIR="expected"

if [ ! -x "$PROGRAM" ]; then
	echo "Compiling!"
	make
fi

echo "Running the tests!"

for infile in "$INPUT_DIR"/*; do
	base=$(basename "$infile")
	outfile="$OUTPUT_DIR/base.out"
	expected="$EXPECTED_DIR/base.out"

	echo -n "Test $base ..."

	input=$(<"$infile")

	if ! "$PROGRAM" "$input" > "$outfile" 2>&; then
		echo "X runtime error"
		continue
	fi

	if [[ -f "$expected" ]]; then
		if diff -q "$outfile" "$expected" >/dev/null; then
			echo "Passed"
		else
			echo "Failed"
			diff -u "$expected" "$outfile" || true
		fi
	else
		echo "No expectedo output to compaer"
	fi
done
