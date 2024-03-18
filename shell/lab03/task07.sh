#!/bin/bash

# Function to calculate and display directory sizes
calculate_directory_sizes() {
    # Accept directory path as an argument
    path=$1
    limit_1=$1
    


    # Calculate and display size of each subdirectory within the specified path
    for dir in $(find $path -type d); do
        size=$(du -sh $dir | awk '{print $1}')
        echo "Directory: $dir, Size: $size"

        # Highlight directories that exceed a user-defined size limit
        if [[ $size > $limit_1 ]]; then
            echo "This directory exceeds the size limit!"
        fi
    done
}

# Provide an option to sort and display directories based on their sizes
sort_directories_by_size() {
    # Accept directory path as an argument
    path=$1

    # Sort directories based on their sizes
    sorted_dirs=$(du -sh $path/* | sort -hr)

    # Display sorted directories
    echo "Sorted Directories:"
    echo "$sorted_dirs"
}

# Main script

# Accept directory path as an argument
directory_path=$1

# Accept user-defined size limit
echo "Enter the size limit (in kilobytes):"
read limit

# Call the function to calculate and display directory sizes
calculate_directory_sizes $directory_path $limit

# Ask user if they want to sort and display directories
echo "Do you want to sort and display directories based on their sizes? (y/n)"
read choice

if [[ $choice == "y" ]]; then
    # Call the function to sort and display directories
    sort_directories_by_size $directory_path
fi

