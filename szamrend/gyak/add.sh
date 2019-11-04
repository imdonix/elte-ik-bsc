#!/bin/sh

expr $1 + `echo $* | cut -d " " -f$#`
