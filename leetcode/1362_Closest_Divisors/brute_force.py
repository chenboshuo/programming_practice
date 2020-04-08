class Solution:
    def closestDivisors(self, num: int) -> List[int]:
        closet = float('inf')
        limit = int((num+2) ** (1/2)) + 1
        for i in range(1, limit):
            if (num+1) % i == 0:
                j = (num+1)//i
                if j-i < closet:
                    ans_i = i
                    ans_j = j
                    closet = j-i
            if (num+2) % i == 0:
                j = (num+2)//i
                if j-i < closet:
                    ans_i = i
                    ans_j = j
                    closet = j-i

        return [ans_i, ans_j]

# https://leetcode.com/submissions/detail/305961255/


# 113 / 113 test cases passed.
# Status: Accepted
# Runtime: 324 ms
# Memory Usage: 12.7 MB
# Submitted: 1 month, 2 weeks ago
