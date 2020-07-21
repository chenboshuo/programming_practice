class Solution:
    def numSub(self, s: str) -> int:
        memo = [i for i in range(len(s)+1)]
        for i in range(1,len(memo)):
          memo[i] += memo[i-1]

        result = 0
        i = 0
        while i< len(s):
          k = 1
          if s[i] == '1':
            while i+k < len(s) and s[i+k] == '1':
              k += 1
            result += memo[k]
          i += k

        return result % (10**9 + 7)

# 56 / 56 test cases passed.
# Status: Accepted
# Runtime: 352 ms
# Memory Usage: 19.1 MB
# Submitted: 1 week, 1 day ago
