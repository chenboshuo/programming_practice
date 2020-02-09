from collections import Counter
class Solution:
    def minSetSize(self, arr: List[int]) -> int:
      a = Counter(arr)
      half = len(arr)//2
      total = 0
      for index,i in enumerate(sorted(Counter(arr).values(), reverse=True)):
        total += i
        if total >= half:
          return index+1;
        
# https://leetcode.com/submissions/detail/301640520/
# Runtime: 832 ms, faster than 26.18% of Python3 online submissions
# Memory Usage: 33.2 MB, less than 100.00% of Python3 online submissions.
# reference https://leetcode.com/problems/reduce-array-size-to-the-half/discuss/496703/Python-Simple-Greedy-Solution-using-Counter-and-Sorting
