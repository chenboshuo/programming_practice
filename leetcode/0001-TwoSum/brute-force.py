'''
Brute Force
Time Complexity: O(n^2)
Space Complexity: O(1)
'''
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for i in range(0,len(nums)):
            if i < len(nums):
                for j in range(i+1,len(nums)):
                    if nums[i] + nums[j] == target:
                        return [i,j]
# Runtime: 5808 ms, faster than 11.40% of Python3 online submissions for Two Sum.
# Memory Usage: 13.9 MB, less than 21.36% of Python3 online submissions for Two Sum.
