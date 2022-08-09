class Solution:
    def numFactoredBinaryTrees(self, arr: List[int]) -> int:
        arr.sort()
        tree_num = {}
        for num in arr:
            subtree = 1
            for pre in tree_num:
                right = num // pre
                if num % pre == 0 and right in tree_num and pre <= right:
                    new_term = tree_num[pre] * tree_num[right] % (10**9 + 7)
                    if pre != right:
                        new_term *= 2
                    subtree += new_term % (10**9 + 7)
            tree_num[num] = subtree
        return sum(tree_num.values()) % (10**9 + 7)

# https://leetcode.com/submissions/detail/768874738/

# Runtime: 368 ms, faster than 90.91% of Python3 online submissions for Binary Trees With Factors.
# Memory Usage: 14.2 MB, less than 57.07% of Python3 online submissions for Binary Trees With Factors.