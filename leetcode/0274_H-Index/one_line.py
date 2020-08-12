# reference https://leetcode.com/problems/h-index/discuss/71055/1-line-Python-solution
class Solution:
    def hIndex(self, citations: List[int]) -> int:
      return sum(i < j for i, j in enumerate(sorted(citations, reverse=True)))
