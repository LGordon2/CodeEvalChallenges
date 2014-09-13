__author__ = 'lew'

import sys

if len(sys.argv) < 2:
    print 'Not enough arguments!'
    exit(1)

with open(sys.argv[1]) as f:
    for line in f:
        print " ".join([word.rstrip() for word in line.split(' ')][::-1])