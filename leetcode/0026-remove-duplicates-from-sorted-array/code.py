class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if not nums:
          return 0
        i = 0
        for _ in nums:
          if nums[i] == _:
            continue
          else:
            i += 1
            nums[i] = _

        return i + 1

# Runtime: 56 ms,
# faster than 96.19% of Python3 online submissions for Remove Duplicates from Sorted Array.
# Memory Usage: 14.8 MB,
# less than 5.43% of Python3 online submissions for Remove Duplicates from Sorted Array.
