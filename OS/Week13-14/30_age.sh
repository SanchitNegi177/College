#!/bin/bash
echo "Please enter your age"
read age
if [ $age -ge 18 ]; then
    echo "Yes you are eligible to vote"
else
    echo "NO you are not eligible to vote"
fi 