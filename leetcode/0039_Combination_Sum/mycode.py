from copy import copy
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        ans = []
        memo = defaultdict(list)
        for i in candidates:
            items = []
            s = i
            while s <= target:
                items.append(i)
                memo[s].append(copy(items))
                s += i

        memo[0] = []
        matched = set()
        # match the target
        for s in memo.keys():
            if s in matched:
                continue
            match = target - s
            if match == 0:
                for i in memo[s]:
                    ans.append(i)

            if (match != s) and (match in memo):
                for i,j in product(memo[s],memo[match]):
                    valid = copy(i)
                    valid.extend(j)
                    ans.append(valid)
                matched.add(match)



        return list(ans)


# Input:
# [2,3,5]
# 8
# Output:
# [[2,2,2,2],[2,3,3],[2,2,2,2],[3,5]]
# Expected:
# [[2,2,2,2],[2,3,3],[3,5]]
