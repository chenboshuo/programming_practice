class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs:
          return ''
        n = min([len(i) for i in strs]) + 1
        if n == 1:
          return ""
        prefix = ''
        for i in range(0,n):
          _ = strs[0][i]
          for str in strs:
            if str[i] != _:
              return prefix
          else:
            prefix += _
'''
https://leetcode.com/submissions/detail/247220843/
Runtime: 48 ms, faster than 21.67% of Python3 online submissions for Longest Common Prefix.
Memory Usage: 13.9 MB, less than 5.11% of Python3 online submissions for Longest Common Prefix.
'''
