#!/bin/bash
while true; do
    echo 1. add 2. sub 3. mul 4. div 5.to exit
    echo -n "Enter your choice: "
    read ch
    echo -n "Enter first number: "
    read n1
    echo -n "Enter second number: "
    read n2
    case $ch in
        1) let sum=n1+n2
            echo "Sum = $sum";;
        2) let sub=n1-n2
            echo "Subtraction = $sub";;
        3) let mul=n1*n2
            echo "Multiplication = $mul";;
        4) if [ $n2 -eq 0 ]; then
                echo "Division by zero is not allowed."
            else
                let div=n1/n2
                echo "Division = $div"
            fi;;
        5)echo "Exiting the program."
            exit;;
        *)
            echo "Invalid choice. Please try again.";;
    esac
    
done
