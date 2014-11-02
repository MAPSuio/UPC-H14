#!/bin/bash
num=$(($(cat rename.num)))

for i in $@; do
    new="$(printf "draw-%03d.in" $num)"
    cp -v "$i" "$new"
    num=$((num+1))
done

echo $num > rename.num
