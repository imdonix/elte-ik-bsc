#!/bin/sh

a=$1

while [ `expr $a % 17` -ne 0 ]
do
	echo $a
	a=`expr $a + 1`
done
