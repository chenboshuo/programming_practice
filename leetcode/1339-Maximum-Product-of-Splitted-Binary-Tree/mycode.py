# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def __init__(self):
      self.memo = []

    def total(self,node:TreeNode) -> int:
      if not node:
        return 0
      subtree_sum = self.total(node.left) + self.total(node.right) + node.val
      self.memo.append(subtree_sum)
      return subtree_sum

    def maxProduct(self, root: TreeNode) -> int:
      total = self.total(root)
      mid = min(self.memo,key=lambda x: abs(x-total/2))
      return mid*(total-mid) % (10**9+7)

# Runtime: 304 ms, faster than 99.25% of Python3 online submissions.
# Memory Usage: 62.3 MB, less than 100.00% of Python3 online submissions.
