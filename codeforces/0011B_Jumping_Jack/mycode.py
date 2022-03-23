from sys import stdin
from math import ceil,floor
from bisect import bisect_right

input = stdin.readline
target = abs(int(input()))
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

Time: 124 ms, memory: 16 KB
Verdict: WRONG_ANSWER
Input
-1000000000
Participant's output
51002
Jury's answer
44723
Checker comment
wrong answer 1st numbers differ - expected: '44723', found: '51002'
"""
