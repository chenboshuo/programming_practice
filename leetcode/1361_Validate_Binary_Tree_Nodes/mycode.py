class Solution:
    def validateBinaryTreeNodes(self, n: int, leftChild: List[int], rightChild: List[int]) -> bool:
        parents = [-2]*n
        parents[0] = -1  # 根节点无parent,被赋值说明被替换
        for i, c in enumerate(zip(leftChild, rightChild)):
            l, r = c
            if l > -1:
                if parents[l] != -2:  # parent 被替换
                    return False
                parents[l] = i
            if r > -1:
                if parents[r] != -2:  # parent 被替换
                    return False
                parents[r] = i
        if -2 in parents:
            return False

        return True


# 30 / 30 test cases passed.
# Status: Accepted
# Runtime: 296 ms
# Memory Usage: 14.3 MB
# Submitted: 1 month, 1 week ago
