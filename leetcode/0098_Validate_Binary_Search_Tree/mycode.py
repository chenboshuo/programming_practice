# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, 
        node: Optional[TreeNode],
        inferior=-float('inf'),
        superior=float('inf')) -> bool:
        val = node.val
        if node.left is not None:
            left = node.left.val
            if left >= val or left <= inferior:
                return False
            # inferior = left 
            left_correct = self.isValidBST(
                node=node.left,
                inferior=inferior,
                superior=val
            )
        else:
            left_correct = True
        
        if node.right is not None:
            right = node.right.val
            if val >= right or right >= superior:
                return False
            # superior = right
            right_correct = self.isValidBST(
                node=node.right,
                inferior=val,
                superior=superior
            )
        else:
            right_correct = True
        return left_correct and right_correct
            
# https://leetcode.com/submissions/detail/770647733/# Submission Detail
# Runtime: 55 ms, faster than 78.59% of Python3 online submissions for Validate Binary Search Tree.
# Memory Usage: 16.6 MB, less than 46.02% of Python3 online submissions for Validate Binary Search Tree.