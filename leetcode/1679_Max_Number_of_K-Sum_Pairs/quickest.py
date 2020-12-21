class Solution:
    def maxOperations(self, nums: List[int], k: int) -> int:
        memo = Counter(nums)
        ans = 0
        for num in memo.keys():
            if num <= k//2:
                if k - num in memo:
                    if k - num == num:
                        ans += memo[num] // 2
                    else:
                        ans += min(memo[num],memo[k-num])
        return ans
# Runtime: 628 ms, faster than 96.15% of Python3 online submissions for Max Number of K-Sum Pairs.
# Memory Usage: 27.5 MB, less than 40.76% of Python3 online submissions for Max Number of K-Sum Pairs.
