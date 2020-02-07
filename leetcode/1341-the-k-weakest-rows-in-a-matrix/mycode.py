class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        score = [(sum(mat[i]),i) for i in range(len(mat))]
        score.sort()
        # return score
        return [i[1] for i in score[0:k]]

# 52 / 52 test cases passed.
# Status: Accepted
# Runtime: 108 ms
# Memory Usage: 12.8 MB
# Submitted: 5 days, 5 hours ago
