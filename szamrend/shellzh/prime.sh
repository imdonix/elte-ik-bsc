#!/bin/sh

osztok()
{
db=0

for x in `seq $1`
do
	rem=`expr $1 % $x`
	if [ $rem -eq 0 ]
	then
		db=`expr $db + 1`
	fi
done
echo `expr $db - 2`
}

for x in `seq $1`
do
	if [ `osztok $x` -eq 0 ]
	then
		echo $x
	fi
done