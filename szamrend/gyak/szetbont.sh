#!/bin/sh

counter=1

while read -r line
do
	if [ `expr $counter % 2` -eq 0 ]
	then
		echo $line >> file_even.txt
	else
		echo $line >> odd_file.txt
	fi
	counter=`expr $counter + 1`
done < $1
