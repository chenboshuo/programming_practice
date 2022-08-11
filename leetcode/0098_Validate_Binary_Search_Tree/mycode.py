# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        if root is None:
            return True
        val = root.val
        if root.left is not None:
            left = root.left.val
            if left >= val:
                return False

        if root.right is not None:
            right = root.right.val
            if right <= val:
                return False

        return self.isValidBST(root.left) and self.isValidBST(root.right)
# https://leetcode.com/submissions/detail/770639244/
# Submission Detail
# 72 / 80 test cases passed.
# Status: Wrong Answer
# Submitted: 3 minutes ago
# Input:
# [5,4,6,null,null,3,7]
# Output:
# true
# Expected:
# false