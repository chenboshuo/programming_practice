# reference: https://leetcode.com/problems/longest-increasing-subsequence/discuss/1326308/C%2B%2BPython-DP-Binary-Search-BIT-Solutions-Picture-explain-O(NlogN)

class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        dp = [1] * len(nums)
        for i in range(1, len(nums)):
            for j in range(i):
                if nums[j] < nums[i]:
                    dp[i] = max(dp[i], dp[j]+1)
        return max(dp)

# https://leetcode.com/submissions/detail/768261405/
# Runtime: 5032 ms, faster than 46.52% of Python3 online submissions for Longest Increasing Subsequence.
# Memory Usage: 14.3 MB, less than 47.45% of Python3 online submissions for Longest Increasing Subsequence.
