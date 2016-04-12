#!/bin/bash

echo "Enter the first string"
read str1
echo "Enter the second string"
read str2
echo "Concatenated string and its length"
res=$str1$str2
size=${#res}
echo "$res"
echo "$size"
