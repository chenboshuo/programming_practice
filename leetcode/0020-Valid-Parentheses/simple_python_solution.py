# source : https://leetcode.com/problems/valid-parentheses/discuss/9271/My-python-solution
class Solution:
    # @param {string} s
    # @return {boolean}
    def isValid(self, s):
        stack=[]
        for i in s:
            if i in ['(','[','{']:
                stack.append(i)
            else:
                if not stack or {')':'(',']':'[','}':'{'}[i]!=stack[-1]:
                    return False
                stack.pop()
        return not stack
