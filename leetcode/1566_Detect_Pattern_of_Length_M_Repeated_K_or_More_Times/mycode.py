class Solution:
    def containsPattern(self, arr: List[int], m: int, k: int) -> bool:
        d = defaultdict(int)
        for i in range(len(arr)-m):
            d[tuple(arr[i:i+m])] += 1
            if d[tuple(arr[i:i+m])] >= k:
                return True

        return False


# Input:
# [2,2]
# 1
# 2
# Output:
# false
# Expected:
# true
