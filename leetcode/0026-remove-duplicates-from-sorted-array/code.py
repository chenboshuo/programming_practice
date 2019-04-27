class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if not nums:
          return 0
        i = 0
        j = 0
        for _ in nums:
          if nums[i] == nums[j]:
            j += 1
          else:
            i += 1
            nums[i] = nums[j]
            j += 1

        return i + 1

# Runtime: 60 ms, 
# faster than 80.85% of Python3 online submissions for Remove Duplicates from Sorted Array.
# Memory Usage: 14.9 MB,
# less than 5.43% of Python3 online submissions for Remove Duplicates from Sorted Array.
