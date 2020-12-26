class Solution:
    def numberOfMatches(self, n: int) -> int:
        pass_ = 0
        if n == 1:
            return 0
        count = 0
        if n & 1:
            pass_ = 1
        n //= 2
        count += n
        return count + self.numberOfMatches(n+pass_)
