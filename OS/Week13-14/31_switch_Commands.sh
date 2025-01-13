#!/bin/bash
ch=0
while [ $ch -ne 4 ]; do
    echo "1) Current path"
    echo "2) List directories"
    echo "3) Date"
    echo "4) Exit"
    echo "Enter your choice:"
    read ch
    case $ch in
        1) pwd ;;
        2) ls ;;
        3) date ;;
        4) echo "Exiting..." ;;
        *) echo "Invalid choice" ;;
    esac
done
