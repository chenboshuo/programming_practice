import sys
import logging
from itertools import accumulate
from bisect import bisect_left

logging.root.setLevel(logging.INFO)

num = int(sys.stdin.readline())
if num == 1:
    print(1,0)
    exit(0)
times = list(map(int,sys.stdin.readline().strip().split()))
# left = 0
# right = num-1
series = list(accumulate(times))
logging.info(f"series={series}")
total = series[-1]
alice = bisect_left(series,total/2+1)
print(alice,num-alice)

# Test: #7, time: 310 ms., memory: 5940 KB, exit code: 0, checker exit code: 1, verdict: WRONG_ANSWER
# Input
# 2
# 8 2
# Output
# 0 2
# Answer
# 1 1
# Checker Log
# wrong answer 1st numbers differ - expected: '1', found: '0'