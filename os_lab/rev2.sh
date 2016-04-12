#!/bin/bash

echo "Enter an integer"
read x
y=0
until [[ $x -eq 0 ]]
do
    y=$[y*10+x%10]
    x=$[x/10]
done
echo $y
