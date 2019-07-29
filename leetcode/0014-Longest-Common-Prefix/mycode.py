class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs:
          return ''
        prefix = ''
        n = min([len(i) for i in strs]) + 1
        for i in range(0,n):
          _ = strs[0][i]
          for str in strs:
            if str[i] != _:
              return prefix
          else:
            prefix += _


'''
https://leetcode.com/submissions/detail/247216397/
Runtime Error Message:
Line 8: IndexError: string index out of range
Last executed input:
[""]
'''
