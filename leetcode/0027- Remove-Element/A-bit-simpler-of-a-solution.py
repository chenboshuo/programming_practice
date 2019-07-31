class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        while val in nums:
          nums.remove(val)

'''
https://leetcode.com/problems/remove-element/discuss/12306/Simple-Python-O(n)-two-pointer-in-place-solution
https://leetcode.com/submissions/detail/247773945/
Runtime: 36 ms, faster than 91.71% of Python3 online submissions for Remove Element.
Memory Usage: 13.8 MB, less than 5.03% of Python3 online submissions for Remove Element.
'''
