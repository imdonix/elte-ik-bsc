#!/bin/sh
while read line
do
    nev=`echo $line | cut -f1 -d' '`
    cim=`echo $line | cut -f2 -d' '`
    ido=`echo $line | cut -f3 -d' '`
    echo `cat $1 | sed -e "s/<nev>/$nev/g" | sed -e "s/<cim>/$cim/g" | sed -e "s/<időpont>/$ido/g"`
done < $2
