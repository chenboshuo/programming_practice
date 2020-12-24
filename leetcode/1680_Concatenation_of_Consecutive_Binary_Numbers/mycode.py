class Solution:
    def concatenatedBinary(self, n: int) -> int:
        s = ""
        for i in range(1,n+1):
            s += str(bin(i))[2:]
        return int(s,2) % (10**9+7)


# 403 / 403 test cases passed.
# Status: Accepted
# Runtime: 2936 ms
# Memory Usage: 16.3 MB
# Submitted: 2 weeks, 4 days ago
