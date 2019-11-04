#!/bin/sh

MAJORS="polgarmesterek.txt"
IDKS="kepviselok.txt"


major_max=0
while read line
do
    db=`cat $1 | cut -f1 -d',' | grep "$line" | wc -l`
    if [ $major_max -lt $db ]
    then
        major_max=$db
        major=$line
    fi
done < $MAJORS
echo "A Polgarmester: $major ($major_max szavazattal)"

idk_max=0
while read line
do
    db=`cat $1 | cut -f2 -d',' | grep "$line" | wc -l`
    if [ $idk_max -lt $db ]
    then
        idk_max=$db
        idk=$line
    fi
done < $IDKS
echo "A képvislő: $idk ($idk_max szavazattal)"