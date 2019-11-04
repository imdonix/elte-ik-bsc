#!/bin/sh

getent passwd | cut -d":" -f5 | cut -d" " -f2 | grep $1 | wc -l
