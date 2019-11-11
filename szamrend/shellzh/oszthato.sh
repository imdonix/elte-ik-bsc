#!/bin/sh

kul=`expr $2 - $3`
rem=`expr $kul % $1`

if [ $rem -eq 0 ]
then
	echo oszthato
else
	echo nem oszthato
fi