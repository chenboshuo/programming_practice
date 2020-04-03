NULL = -1
INIT = -2


class Solution:
    def validateBinaryTreeNodes(self, n: int, leftChild: List[int], rightChild: List[int]) -> bool:
        parents = [INIT]*n  # INIT 代表还没有确定parent, 否则为对应索引
        parents[0] = NULL  # 根节点无parent,被赋值说明被替换
        for i, children in enumerate(zip(leftChild, rightChild)):
            for child in children:
                if child != NULL:
                    if parents[child] != INIT:  # parent 被替换
                        return False
                    # 标记parent
                    parents[child] = i
        if INIT in parents:
            return False

        return True


# Wrong Answer
# Details
# Playground Debug
# Input
# 2
# [-1, 0]
# [-1, -1]
# Output
# false
# Expected
# true
