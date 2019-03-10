# source
# https://leetcode.com/problems/roman-to-integer/discuss/6542/4-lines-in-Python
d = {'M':1000, 'D':500, 'C':100, 'L':50, 'X':10, 'V':5, 'I':1}

def romanToInt(self, s):
    res, p = 0, 'I'
    for c in s[::-1]:
        res, p = res - d[c] if d[c] < d[p] else res + d[c], c
    return res
