from itertools import combinations
class CombinationIterator:

    def __init__(self, characters: str, combination_length: int):
        self.iter = combinations(characters, combination_length)
        l = len(characters)
        ans = 1
        for i in range(1,combination_length+1):
            ans *= l
            ans //= i
            l -= 1
        self.t = ans

    def next(self) -> str:
        self.t -= 1
        return "".join(next(self.iter))



    def hasNext(self) -> bool:
        return self.t


# Your CombinationIterator object will be instantiated and called as such:
# obj = CombinationIterator(characters, combinationLength)
# param_1 = obj.next()
# param_2 = obj.hasNext()



# 16 / 16 test cases passed.
# Status: Accepted
# Runtime: 36 ms
# Memory Usage: 15.7 MB
# Submitted: 0 minutes ago
