#!/bin/sh

sum=0
while read -r line
do
	if [ $line -gt $2 ]
	then
		sum=`expr $sum + $line`
	fi
done < $1
echo $sum
echo $sum >> $1