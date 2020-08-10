class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs:
          return ''
        n = min([len(i) for i in strs])
        if n == 0:
          return ""
        prefix = ''
        for i in range(0,n):
          _ = strs[0][i]
          for s in strs:
            if s[i] != _:
              return prefix
          prefix += _
        return prefix

# Runtime: 36 ms, faster than 69.33% of Python3 online submissions for Longest Common Prefix.
# Memory Usage: 14 MB, less than 27.73% of Python3 online submissions for Longest Common Prefix.
