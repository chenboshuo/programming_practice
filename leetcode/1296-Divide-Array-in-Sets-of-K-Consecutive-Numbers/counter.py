# cource: https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/discuss/457625/Python-Counter-Solution
import collections
class Solution:
    def isPossibleDivide(self, nums: List[int], k: int) -> bool:
        count=collections.Counter(nums)
        keys=sorted(count.keys())
        for n in keys:
            if count[n]>0:
                minus=count[n]
                for i in range(n,n+k):
                    if count[i]<minus:
                        return False
                    count[i]-=minus
        return True
# https://leetcode.com/submissions/detail/299529634/
# Runtime: 456 ms, faster than 68.81% of Python3 online submissions for Divide Array in Sets of K Consecutive Numbers.
# Memory Usage: 27.2 MB, less than 100.00% of Python3 online submissions for Divide Array in Sets of K Consecutive Numbers.
