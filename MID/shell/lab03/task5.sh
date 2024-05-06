#!/bin/bash

# Function to add a new user
add_user() {
    read -p "Enter username: " username
    read -p "Enter home directory: " home_dir
    sudo useradd -m -d "$home_dir" "$username"
    echo "User $username added successfully."
}

# Function to delete a user
delete_user() {
    read -p "Enter username to delete: " username
    sudo userdel -r "$username"
    echo "User $username deleted successfully."
}

# Function to list all user accounts
list_users() {
    echo "List of user accounts:"
    awk -F: '{ print $1 }' /etc/passwd
}


    while true; do
        echo "User Account Management"
        echo "1. Add User"
        echo "2. Delete User"
        echo "3. List Users"
        echo "4. Exit"
        read -p "Enter your choice: " choice

        case $choice in
            1) add_user ;;
            2) delete_user ;;
            3) list_users ;;
            4) exit ;;
            *) echo "Invalid choice. Please try again." ;;
        esac
    done
}


