#!/bin/sh

max=0
for i in `cat $1`
do
    num=`cat $1 | grep "$i" -o | wc -w`
    
    if [ $max -lt $num ]
    then
        max=$num
        str=$i
    fi
done

echo A legtobbszor elofordul: $str