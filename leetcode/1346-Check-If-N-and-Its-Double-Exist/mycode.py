class Solution:
    def checkIfExist(self, arr: List[int]) -> bool:
      a = set(arr)
      double_a = set([i*2 for i in arr])
      if (double_a & a) - set([0]):
        return True
      else:
        return False
# Input:
# [0,0]
# Output:
# false
# Expected:
# true
