# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
closest = 0;

def total_weight(node : TreeNode):
    if not node :
        return 0
    part_sum = node.val + total_weight(node.left) + total_weight(node.right)
    return part_sum

class Solution:
    def maxProduct(self, root: TreeNode) -> int:
      symmetr_axis = total_weight(root)/2

# 0 / 54 test cases passed.
# Status: Wrong Answer
# Submitted: 1 week, 2 days ago
# Input:
# [1,2,3,4,5,6]
# Output:
# None
# Expected:
# 110
