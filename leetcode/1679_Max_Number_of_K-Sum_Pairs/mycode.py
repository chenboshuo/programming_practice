class Solution:
    def maxOperations(self, nums: List[int], k: int) -> int:
        times = 0
        sum_map = defaultdict(int)
        for num in nums:
            if sum_map[num] == 0:
                sum_map[k-num] += 1
            else:
                times += 1
                sum_map[num] -= 1

        return times
