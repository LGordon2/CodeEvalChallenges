__author__ = 'lew'

import sys

if len(sys.argv) < 2:
    print 'Not enough arguments!'
    exit(1)

with open(sys.argv[1]) as f:
    for line in f:
        x, init_n = [int(num.rstrip()) for num in line.split(',')]
        n = init_n
        while n < x:
            n += init_n

        print n