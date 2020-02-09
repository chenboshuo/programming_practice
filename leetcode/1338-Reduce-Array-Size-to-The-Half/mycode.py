from collections import Counter
class Solution:
    def minSetSize(self, arr: List[int]) -> int:
      a = Counter(arr)
      half = len(arr)//2
      total = 0
      for index,i in enumerate(a.most_common()):
        total += i[1]
        if total >= half:
          return index+1;
          
# https://leetcode.com/submissions/detail/301649219/
# Runtime: 604 ms, faster than 92.22% of Python3 online submissions for Reduce Array Size to The Half.
# Memory Usage: 34.4 MB, less than 100.00% of Python3 online submissions for Reduce Array Size to The Half.
