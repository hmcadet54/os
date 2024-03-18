#!/bin/bash

input_file="q3.txt"

content=$(sed -n '10p' "$input_file")
echo "$content"