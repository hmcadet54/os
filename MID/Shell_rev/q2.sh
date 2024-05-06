#!/bin/bash

input_file="sample.txt"

cat "$input_file" | tr '[:upper:]' '[:lower:]' | tr -sc '[:alnum:]' '\n' | sort | uniq -c | sort -nr
