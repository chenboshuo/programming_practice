class Solution:
    def restoreString(self, s: str, indices: List[int]) -> str:
      l = list(s)
      for i in range(len(s)):
        j = indices[i]
        l[j] = s[i]
      return ''.join(l)



# 399 / 399 test cases passed.
# Status: Accepted
# Runtime: 72 ms(35.39%)
# Memory Usage: 13.8 MB (77.68%)
# Submitted: 4 weeks ago
