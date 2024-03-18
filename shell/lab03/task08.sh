#!/bin/bash

# Accept the directory path as an argument
directory=$1

# Create subdirectories if they don't exist
mkdir -p $directory/shelldir
mkdir -p $directory/cdir
mkdir -p $directory/jpgdir

# Move shell script files to shelldir
mv $directory/*.sh $directory/shelldir/

# Move C source files to cdir
mv $directory/*.c $directory/cdir/

# Move JPEG image files to jpgdir
mv $directory/*.jpg $directory/jpgdir/

# Count the number of files moved to each subdirectory
shelldir_count=$(ls $directory/shelldir | wc -l)
cdir_count=$(ls $directory/cdir | wc -l)
jpgdir_count=$(ls $directory/jpgdir | wc -l)

# Provide feedback to the user
echo "Files organized successfully!"
echo "Number of shell script files moved: $shelldir_count"
echo "Number of C source files moved: $cdir_count"
echo "Number of JPEG image files moved: $jpgdir_count"

