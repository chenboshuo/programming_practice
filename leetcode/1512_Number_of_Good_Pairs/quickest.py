class Solution:
    def numIdenticalPairs(self, nums: List[int]) -> int:
        num_to_count = {}
        for n in nums:
            if n not in num_to_count:
                num_to_count[n] = 0
            num_to_count[n] += 1

        num_good_pairs = 0
        for k,v in num_to_count.items():
            if v >= 2:
                num_good_pairs += v*(v-1) // 2
        return num_good_pairs
