class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        ans = ""
        c = 0
        for i,j in zip(num1[::-1], num2[::-1]):
          s = ord(i) + ord(j) - 2*ord('0')
          ans += str(s % 10)
          c = s // 10
        if c:
          ans += str(c)
        return ans[::-1]


# Input
# "9"
# "99"
# Output
# "18"
# Expected
# "108"
# https://leetcode.com/submissions/detail/297809278/
