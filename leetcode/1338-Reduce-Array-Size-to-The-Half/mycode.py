from collections import Counter
class Solution:
    def minSetSize(self, arr: List[int]) -> int:
      a = Counter(arr)
      half = len(arr)/2
      # return range(1,len(a)+1)

      # for i in range(1,len(a)+1):
      #   if sum(i[1] for i in a.most_common(i)) >= half:
      #     return i
      count = 0
      total = 0
      for i in sorted(a.values())[::-1]:
        total += i
        count += 1
        if total >= half:
          return count;

# https://leetcode.com/submissions/detail/299439534/
# 31 / 31 test cases passed.
# Status: Accepted
# Runtime: 1204 ms
# Memory Usage: 29 MB
