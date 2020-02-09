# https://leetcode.com/problems/the-k-wyyeakest-rows-in-a-matrix/discuss/496713/Python-One-Liner-using-Sorting
class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        return sorted(range(len(mat)), key=lambda x: sum(mat[x]))[:k]


# Runtime: 108 ms, faster than 92.17% of Python3 online submissions for The K Weakest Rows in a Matrix.
# Memory Usage: 13.1 MB, less than 100.00% of Python3 online submissions for The K Weakest Rows in a Matrix.
