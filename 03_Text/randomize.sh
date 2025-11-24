#!/bin/bash

tmp=$(mktemp)

row=0
while IFS= read -r line; do
    col=0
    echo "$line" | fold -w 1 | while IFS= read c; do
        echo $row $col $c >> $tmp
        ((col++))
    done
    ((row++))
done

tput clean
shuf "$tmp" | while read row col c ; do
    tput cup "$row" "$col"
    echo -n $c
    sleep $1
done

tput cup $((row+1)) 0

trap 'rm -f "$TMP"' EXIT
