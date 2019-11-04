#!/bin/sh

for x in `who | cut -d" " -f1`
do
	echo Szevasz $x
done
