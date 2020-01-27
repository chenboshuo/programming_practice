class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        ans = ""
        c = 0
        for i,j in zip(num1[::-1], num2[::-1]):
          ans += str((ord(i) + ord(j) + c - ord('0')*2) % 10)
          c = (ord(i)+ord(j)) // 10
        return ans[::-1]

# Input
# "1"
# "9"
# Output
# "0"
# Expected
# "10"
# https://leetcode.com/submissions/detail/297808272/
