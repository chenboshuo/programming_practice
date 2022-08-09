class Solution:
    def numFactoredBinaryTrees(self, arr: List[int]) -> int:
        arr.sort()
        tree_num = {}
        for num in arr:
            subtree = 1
            for pre in tree_num:
                if num % pre == 0 and num // pre in tree_num:
                    subtree += tree_num[pre]
            tree_num[num] = subtree
        return sum(tree_num.values())


# https://leetcode.com/submissions/detail/768863847/
# Submission Detail
# 32 / 48 test cases passed.
# Status: Wrong Answer
# Submitted: 13 minutes ago
# Input:
# [18, 3, 6, 2]
# Output:
# 10
# Expected:
# 12
