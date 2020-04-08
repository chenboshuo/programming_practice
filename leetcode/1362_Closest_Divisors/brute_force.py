class Solution:
    def closestDivisors(self, num: int) -> List[int]:
        closet = float('inf')
        limit = int((num+2) ** (1/2)) + 1
        for i in range(1, limit):
            for delta in (1, 2):
                if (num+delta) % i == 0:
                    j = (num+delta)//i
                    if j-i < closet:
                        ans_i = i
                        ans_j = j
                        closet = j-i

        return [ans_i, ans_j]

# https://leetcode.com/submissions/detail/305961255/


# Runtime: 392 ms, faster than 17.55 % of Python3 online submissions for Closest Divisors.
# Memory Usage: 13.9 MB, less than 100.00 % of Python3 online submissions for Closest Divisors.
