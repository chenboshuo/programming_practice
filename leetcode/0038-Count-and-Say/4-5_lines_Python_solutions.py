# reference https://leetcode.com/problems/count-and-say/discuss/15999/4-5-lines-Python-solutions
class Solution:
    def countAndSay(self, n: int) -> str:
      s = '1'
      for _ in range(n - 1):
          s = re.sub(r'(.)\1*',
                     lambda m: str(len(m.group(0)))
                     + m.group(1), s)
      return s

# Runtime: 36 ms, faster than 93.28% of Python3 online submissions for Count and Say.
# Memory Usage: 13.7 MB, less than 6.38% of Python3 online submissions for Count and Say.
