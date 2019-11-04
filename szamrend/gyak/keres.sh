#!/bin/sh

getent passwd | grep ^$1 | wc -l
