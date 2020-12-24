class Solution:
    def concatenatedBinary(self, n: int) -> int:
        s = ""
        for i in range(1,n+1):
            s += str(bin(i))[2:]
        return int(s,2) % 1_000_000_007


# Runtime: 1756 ms, faster than 49.74% of Python3 online submissions for Concatenation of Consecutive Binary Numbers.
# Memory Usage: 16.2 MB, less than 30.58% of Python3 online submissions for Concatenation of Consecutive Binary Numbers.
