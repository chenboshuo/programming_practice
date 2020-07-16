from collections import Counter

class Solution:
    def numIdenticalPairs(self, nums: List[int]) -> int:
        c = Counter(nums)
        c = c.most_common()
        i = 0
        ans = 0
        for _, t in c:
          ans += t * (t-1) / 2
        return int(ans)


# 48 / 48 test cases passed.
# Status: Accepted
# Runtime: 72 ms
# Memory Usage: 13.7 MB
# Submitted: 3 days, 23 hours ago
