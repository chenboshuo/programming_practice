from collections import defaultdict

class Solution:
    def numIdenticalPairs(self, nums: List[int]) -> int:
        counts = defaultdict(int)
        result = 0
        for i in nums:
          result += counts[i]
          counts[i] += 1
        return result


# Runtime: 56 ms, faster than 35.52% of Python3 online submissions for Number of Good Pairs.
# Memory Usage: 13.8 MB, less than 100.00% of Python3 online submissions for Number of Good Pairs.
