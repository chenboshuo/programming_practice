from collections import defaultdict

class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        dp = [0,1]
        for i in range(1,len(nums)):
            new_ans = max(
                dp[-j] + int(nums[i] > nums[i-j])
                for j in range(1,i+1)
            )
            dp.append(new_ans)
        return dp[len(nums)]
