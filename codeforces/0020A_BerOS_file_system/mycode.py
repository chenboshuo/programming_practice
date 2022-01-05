import sys
# from heapq import heapify,heappop,heappush
from re import findall

# import logging
# logging.setLogge

addstr = sys.stdin.readline()
file_names = findall("\w+",addstr)
print("/"+"/".join(file_names))

# https://codeforces.com/contest/20/submission/141292145
# 186 ms,2048 KB
