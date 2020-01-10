#!/bin/sh

o=`expr $1 + $2`
s=`expr $1 \* $2`

if [ $o -ge $s ]
then
	echo szorzat angyobb
fi
