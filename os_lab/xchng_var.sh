#!/bin/bash

echo "Enter the value of var1"
read var1
echo "Enter the value of var2"
read var2
echo "\n"
echo "Value of var1 : $var1"
echo "Value of var2 : $var2"
echo "Exchanging values"
tmp=$var1
var1=$var2
var2=$tmp
echo "Value of var1 : $var1"
echo "Value of var2 : $var2"

