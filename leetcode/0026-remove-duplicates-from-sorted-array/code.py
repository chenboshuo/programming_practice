class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        i = 0
        j = 0
        for _ in nums:
          if nums[i] == nums[j]:
            j += 1
          else:
            i += 1
            nums[i] = nums[j]
            j += 1

        return j-i-1

# Wrong Answer
# Details
# Playground Debug
# Input
# [1,1,2]
# Output
# [1]
# Expected
# [1,2]
