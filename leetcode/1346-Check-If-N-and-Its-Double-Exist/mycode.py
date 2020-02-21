class Solution:
    def checkIfExist(self, arr: List[int]) -> bool:
      a = set(arr)
      double_a = set([i*2 for i in arr])
      if double_a & a:
        return True
      else:
        return False
# Input:
# [-2,0,10,-19,4,6,-8]
# Output:
# true
# Expected:
# false
