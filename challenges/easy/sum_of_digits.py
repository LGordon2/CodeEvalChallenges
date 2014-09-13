__author__ = 'lew'

import sys

if len(sys.argv) < 2:
    print 'Not enough arguments!'
    exit(1)

with open(sys.argv[1]) as f:
    for line in f:
        number = int(line)
        digit_sum = 0
        while number >= 1:
            digit_sum += number % 10
            number /= 10
        print digit_sum