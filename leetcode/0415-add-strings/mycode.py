class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        ans = ""
        c = 0
        delta = len(num1) - len(num2)
        num1 = num1[::-1]
        num2 = num2[::-1]
        if delta < 0:
          num1 += "0"*(-delta)
        elif delta > 0:
          num2 += "0"*delta
        for i,j in zip(num1, num2):
          s = ord(i) + ord(j) +c - 2*ord('0')
          ans += str(s % 10)
          c = s // 10
        if c:
          ans += str(c)
        return ans[::-1]
        # return num1, num2

# Runtime: 56 ms, faster than 22.76%
# of Python3 online submissions for Add Strings.
# Memory Usage: 12.8 MB, less than 100.00%
# of Python3 online submissions for Add Strings.
# https://leetcode.com/submissions/detail/297815193/
