#!/bin/sh

count=`cat counter.dat`
count=`expr $count + 1`
echo $count > counter.dat
echo Latogatok $count
