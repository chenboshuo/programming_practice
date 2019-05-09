# source: https://leetcode.com/problems/house-robber/discuss/272983/Python-O(1)-DP
'''
Simple DP problem.
dp[i] stands for largest value can be robbed from houses[:i+1]. It's max(dp[i-1], dp[i-2]+houses[i]) since robber can't rob house[i] if it robbed houses[i-1].
We only use dp[i-1] and dp[i-2] to update dp[i] , so we can replace dp array by rolling two variables prev and curr.
'''
def rob(nums):
	prev = curr = 0
	for x in nums:
		curr, prev = max(curr, prev+x), curr
	return curr
