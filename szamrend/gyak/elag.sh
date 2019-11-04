#!/bin/sh

if [ $1 -ge 5 ]
then
	if [ $1 -lt 10 ]
	then
		echo Nagyobb
	else
		echo tul kicsi
	fi
else
	echo Kisebb
fi
