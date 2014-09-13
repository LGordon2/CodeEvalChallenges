__author__ = 'lew'

import sys

if len(sys.argv) < 2:
    print 'Not enough arguments!'
    exit(1)

def fib(n):
    if n == 0:
        return 0
    if n == 1:
        return 1

    return fib(n-1) + fib(n-2)

with open(sys.argv[1]) as f:
    for line in f:
        n = int(line)
        print fib(n)