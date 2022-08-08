from collections import defaultdict

class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        next_nodes = defaultdict(list)
        for i,num in enumerate(nums):
            for pre in nums[:i]:
                if pre < num:
                    next_nodes[pre].append(num)

        def dps(cur, length):
            if cur not in next_nodes:
                return length
            return max(dps(next,length+1)
                for next in next_nodes[cur]
            )

        return max(dps(num,1) for num in nums)

# https://leetcode.com/submissions/detail/768043647/
# 21 / 54 test cases passed.
# Status: Wrong Answer
# Submitted: 10 minutes ago
# Input:
# [1,3,6,7,9,4,10,5,6]
# Output:
# 8
# Expected:
# 6
