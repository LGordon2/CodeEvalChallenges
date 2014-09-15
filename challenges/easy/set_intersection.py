__author__ = 'lew'

import sys

if len(sys.argv) < 2:
    print 'Not enough arguments!'
    exit(1)

with open(sys.argv[1]) as f:
    for line in f:
        set1_str, set2_str = line.split(';')
        set1 = [int(num) for num in set1_str.split(',')]
        set2 = [int(num) for num in set2_str.split(',')]
        intersect_set = []
        for num in set1:
            if num in set2:
                intersect_set.append(str(num))
        print ','.join(intersect_set)
