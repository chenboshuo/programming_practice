class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        c = Counter(nums)
        ans = []
        for num,times in c.most_common():
          if times == 2:
            ans.append(num)
        return ans
