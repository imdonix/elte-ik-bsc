#!/usr/bin/python

import sys

filename = sys.argv[1]

with open(filename) as file:
    lines = file.readlines()
    hosts = lines[0:10] + lines[-10:]
    print(hosts)