#!/bin/sh

a=1

for n in `seq $1`
do
	a=`expr $a \* $n`
done
echo $a
