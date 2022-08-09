class Solution:
    def numFactoredBinaryTrees(self, arr: List[int]) -> int:
        arr.sort()
        tree_num = {}
        for num in arr:
            subtree = 1
            for pre in tree_num:
                right = num // pre
                if num % pre == 0 and right in tree_num and pre <= right:
                    new_term = tree_num[pre] * tree_num[right]
                    if pre != right:
                        new_term *= 2
                    subtree += new_term
            tree_num[num] = subtree
        return sum(tree_num.values())

# https://leetcode.com/submissions/detail/768871730/

# 42 / 48 test cases passed.
# Status: Wrong Answer
# Submitted: 0 minutes ago
# Input:
# [46,144,5040,4488,544,380,4410,34,11,5,3063808,5550,34496,12,540,28,18,13,2,1056,32710656,31,91872,23,26,240,18720,33,49,4,38,37,1457,3,799,557568,32,1400,47,10,20774,1296,9,21,92928,8704,29,2162,22,1883700,49588,1078,36,44,352,546,19,523370496,476,24,6000,42,30,8,16262400,61600,41,24150,1968,7056,7,35,16,87,20,2730,11616,10912,690,150,25,6,14,1689120,43,3128,27,197472,45,15,585,21645,39,40,2205,17,48,136]
# Output:
# 1509730804
# Expected:
# 509730797