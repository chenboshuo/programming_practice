# reference https://leetcode.com/problems/largest-divisible-subset/discuss/84002/4-lines-in-Python
class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        s = {-1:set()} # s[x] is the largest subset
                      # with x as the largest elemennt
        for x in sorted(nums):
            s[x] = max((s[d] for d in s if x % d == 0),key=len) | {x}
        return list(max(s.values(),key=len))
