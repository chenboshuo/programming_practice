class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        prefix = ''
        n = min([len(i) for i in strs]) + 1
        if n == 1:
          return prefix;
        for i in range(0,n):
          _ = strs[0][i]
          for str in strs:
            if str[i] != _:
              return prefix
          else:
            prefix += _

'''
https://leetcode.com/submissions/detail/247215594/
Runtime Error Message:
Line 4: ValueError: min() arg is an empty sequence
Last executed input: []
'''
