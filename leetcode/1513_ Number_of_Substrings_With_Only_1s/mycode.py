# reference https://leetcode.com/problems/number-of-substrings-with-only-1s/discuss/731580/JavaC%2B%2BPython-Count
class Solution:
    def numSub(self, s: str) -> int:
        return sum((len(a) * (len(a)+1) // 2) for a in s.split('0')) % (10**9 + 7)

# Runtime: 52 ms, faster than 94.96% of Python3 online submissions for Number of Substrings With Only 1s.
# Memory Usage: 14.8 MB, less than 100.00% of Python3 online submissions for Number of Substrings With Only 1s.
