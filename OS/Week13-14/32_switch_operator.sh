#!/bin/bash
ch=0
while [ $ch -ne 4 ]; do
    echo "1) Add"
    echo "2) Multiply"
    echo "3) Divide"
    echo "4) Exit"
    echo "Enter your choice:"
    read ch
    case $ch in
        1) 
            echo "Enter two numbers:"
            read a
            read b
            c=$((a + b))
            echo "Addition is $c"
            ;;
        2) 
            echo "Enter two numbers:"
            read a
            read b
            c=$((a * b))
            echo "Multiplication is $c"
            ;;
        3) 
            echo "Enter two numbers:"
            read a
            read b
            if [ $b -ne 0 ]; then
                c=$((a / b))
                echo "Division is $c"
            else
                echo "Division by zero is not allowed"
            fi
            ;;
        4) 
            echo "Exiting..."
            ;;
        *) 
            echo "Invalid choice"
            ;;
    esac
done
