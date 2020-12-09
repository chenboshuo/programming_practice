from itertools import compress
class Solution:
    def mostCompetitive(self, nums: List[int], k: int) -> List[int]:
        # most_competitive = nums[:k]
        # reverse = set()
        # for i,x in enumerate(zip(nums,nums[1:])):
        #     pre,cur = x
        #     if pre > cur:
        #         reverse.add(i)
        has_chosen = [0 for _ in range(len(nums))]
        right = len(nums)-k
        chose_index = -1
        while k :
            minium = float('inf')
            for i,num in enumerate(nums):
                if i > chose_index and i <= right:
                    if num < minium:
                        chose_index = i
                        minium = num
            has_chosen[chose_index] = 1
            k -= 1
            right += 1

        ans = []
        for element,has_chose in zip(nums,has_chosen):
            if has_chose:
                ans.append(element)
        return ans
