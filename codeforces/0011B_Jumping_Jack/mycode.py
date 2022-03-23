from sys import stdin
from math import ceil,floor
from bisect import bisect_right

input = stdin.readline
target = int(input())
lower = floor((2*target)**(1/2) - 1)
upper = ceil((2*target) **(1/2))
points = [(n*(n+1))//2 for n in range(lower,upper+1)]
# print(points)
base = bisect_right(points,target)
# print(base)
if target == points[base-1]:
    print(lower+base-1)
else:
    print(lower+base+points[base]-target)

"""

Time: 154 ms, memory: 2652 KB
Verdict: RUNTIME_ERROR
Input
-1000000000
Participant's output
Jury's answer
Checker comment
Exit code is 1
"""
