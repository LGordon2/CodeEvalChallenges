__author__ = 'lew'

import sys

if len(sys.argv) < 2:
    print 'Not enough arguments!'
    exit(1)

with open(sys.argv[1]) as f:
    for line in f:
        curr_num = None
        nums = []
        for num in line.rstrip().split(','):
            if curr_num != num:
                curr_num = num
                nums.append(num)
        print ','.join(nums)