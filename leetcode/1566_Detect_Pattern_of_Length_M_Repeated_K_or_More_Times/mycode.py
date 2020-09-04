class Solution:
    def containsPattern(self, arr: List[int], m: int, k: int) -> bool:
        times = 1
        for i in range(len(arr)-m):
            j = i
            while(arr[j:j+m] == arr[j+m:j+2*m]):
                times += 1
                j += m
            if times >= k:
                return True
            times = 1

        return False


# 91 / 91 test cases passed.
# Status: Accepted
# Runtime: 56 ms
# Memory Usage: 13.8 MB
# Submitted: 4 days, 23 hours ago
