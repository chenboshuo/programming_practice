# source
# https://leetcode.com/problems/fibonacci-number/discuss/225696/Python-1-liner-recursive-and-iterative-solutions-O(N)-time-O(1)-space
class Solution:
    def fib(self, N, l = -1, r = 1):
        return self.fib(N - 1, r, l + r) if N else l + r
