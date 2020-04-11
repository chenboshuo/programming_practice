class Solution:
    def closestDivisors(self, num: int) -> List[int]:
        limit = int((num+2) ** (1/2))
        for i in range(limit, 0, -1):
            if (num+1) % i == 0:
                return [i, (num+1) // i]
            if (num+2) % i == 0:
                return [i, (num+2) // i]

# Runtime: 168 ms, faster than 91.88% of Python3 online submissions for Closest Divisors.
# Memory Usage: 13.8 MB, less than 100.00% of Python3 online submissions for Closest Divisors.
