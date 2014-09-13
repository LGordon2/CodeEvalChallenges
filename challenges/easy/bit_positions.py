__author__ = 'lew'

import sys

if len(sys.argv) < 2:
    print 'Not enough arguments!'
    exit(1)

with open(sys.argv[1]) as f:
    for line in f:
        number, pos_1, pos_2 = [int(num) for num in line.split(',')]
        comp_num = 2 ** (pos_1 - 1) + 2 ** (pos_2 - 1)
        bitwise_and_num = number & comp_num
        both_ones = bitwise_and_num == comp_num
        both_zeroes = bitwise_and_num == 0
        print repr(both_ones or both_zeroes).lower()