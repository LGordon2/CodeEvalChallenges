__author__ = 'lew'

import sys

if len(sys.argv) < 2:
    print 'Not enough arguments!'
    exit(1)

with open(sys.argv[1]) as f:
    for line in f:
        A, B, N = [int(arg) for arg in line.split(' ')]
        for i in range(1, N+1):
            if i % B == 0 and i % A == 0:
                print 'FB',
            elif i % B == 0:
                print 'B',
            elif i % A == 0:
                print 'F',
            else:
                print i,
        print
