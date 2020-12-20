class Solution:
    def maxOperations(self, nums: List[int], k: int) -> int:
        times = 0
        sum_map = defaultdict(int)
        for num in nums:
            if num not in sum_map:
                sum_map[k-num] += 1
            elif sum_map[num] > 0:
                times += 1
                sum_map[num] -= 1

        return times
# Input:
# [4,4,1,3,1,3,2,2,5,5,1,5,2,1,2,3,5,4]
# 2
# Output:
# 1
# Expected:
# 2
