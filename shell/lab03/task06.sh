#!/bin/bash

# Accept a list of package names as command-line arguments
packages=("$@")

# Check if each package is already installed
for package in "${packages[@]}"
do
    if ! dpkg -s "$package" >/dev/null 2>&1; then
        echo "Package $package is not installed. Installing..."
        sudo apt-get install -y "$package"
    else
        echo "Package $package is already installed."
    fi
done

# Display a summary of installed and updated packages
echo "Summary of installed and updated packages:"
sudo apt-get upgrade -s | grep -E "^Inst" | awk '{print $2, $3, $4, $5}'

