#!/bin/bash

echo "Enter a number"
read num
echo "Factorial is"
fact=1
until [ $num -eq 0 ]
do
    fact=$[fact*num]
    num=$[num-1]
done
echo $fact
