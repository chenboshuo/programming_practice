# source https://leetcode.com/problems/find-numbers-with-even-number-of-digits/discuss/457571/Python-C%2B%2B-and-Haskell-Solutions
class Solution:
    def findNumbers(self, nums: List[int]) -> int:
      return len([i for i in nums if len(str(i)) % 2 == 0])

# Runtime: 48 ms, faster than 90.98% of Python3 online submissions
# for Find Numbers with Even Number of Digits.
# Memory Usage: 12.9 MB, less than 100.00% of Python3 online submissions
# for Find Numbers with Even Number of Digits.
